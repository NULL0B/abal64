/** @pkg Staff.Fred.zac */ 

// ****************************************************************************
/** zac.c: Text file access functionnalities */
// ****************************************************************************

#define  CI_MODULE_ID   0x0010

#if defined(__linux__) || defined(UNIX)
#include "wdef.h"
#else
#if defined(BDA_ABAL2)
#include "wdef.h"
#else
#include "bda.h"
#endif
#endif

#include "zext.h"
#include "zint.h"

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------
#include "string.h"
#include "ztrace.h"
#include "zglobal.h"
#include "zasmutil.h"
#include "ztools.h"
#include "zac.h"


// ----------------------------------------------------------------------------
// - Global variables of this module
// ----------------------------------------------------------------------------
#define C_MAXLOG  64

typedef struct
  {
  WORD    s;    // Numero secteur 
  SWORD   o;    // Numero octet 
  WORD    l;    // Numero ligne 
  SWORD   e;    // Derniere erreur 
  SWORD   m;    // Mode 0=READ, 1=WRITE 
  char FAR *    b;
  } ASC_F, FAR PTR PASC_F;

// Pour AZAC venant de z_pc.c 
SWORD   N_OCTS;     // nombre d'octets d'un buffer 
SWORD   N_SECTS;    // Nombre de secteurs d'un buffer 
SWORD   fh[C_MAXLOG];     // 64 numeros logiques 

// Pour fichiers Ascii (516 bytes) 
SWORD   f_mode[C_MAXLOG];   // Mode de lecture sur open 
SWORD   R_MODE;     // Mode de gestion EOF 
PASC_F  file[C_MAXLOG];   // Pointeurs sur structures fichiers 


// ----------------------------------------------------------------------------
// - Functions
// ----------------------------------------------------------------------------


// ****************************************************************************
/** BdaZac_init: ABAL API

 * @param b_length    IN : buffer length

 @return: CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// *  R_MODE 
// *  N_OCTS
// *  N_SECTS
// *  fh
// ****************************************************************************
EXAWORD BDA_API BdaZac_init(SWORD b_length)
{
MI_TRACE_DCL_TFN("ZacInit");
SWORD i;

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN len=%d",b_length));

  switch (b_length) 
  {
    case 0 :
        R_MODE=0;
        MI_TRACE_RETURN(CE_OK);
    case 1 :
        R_MODE=1;
        MI_TRACE_RETURN(CE_OK);
  }

  for (i=0;i<C_MAXLOG;i++)
      fh[i]=0;

  N_OCTS=b_length;
  N_SECTS=b_length/256;

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaZac_open: ABAL API

 * @param no      IN : Logical numero
 * @param nom     IN : file name 
 * @param mode    IN : CE_ZAC_MODE_*

 * @returns: CE_OK
             CE_ERR_TOOMANYFILES
             CE_ERR_FILENAME
             other value
             
 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaZac_open(SWORD no,char FAR * nom,SWORD mode)
{
MI_TRACE_DCL_TFN("ZacOpen");
SWORD err;
SWORD i;
CHAR  tempo[82];
PASC_F f;

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no  =%d"  ,no));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN name='%s'",nom));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN mode=%d"  ,mode));

  if (no < 1 || no > C_MAXLOG) 
    MI_TRACE_RETURN(CE_ERR_TOOMANYFILES);

  no--;

  // ANFC 
  i=0;
  while (nom[i] != ' ') 
    {
    tempo[i]=nom[i];
    i++;
    }
    
MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"i=%d",i));

  tempo[i]=' ';
  err=sf_anfc(tempo,tempo+65);
  switch (err)
    {
    case  0 :
    case 32 :
        break;
    case 30 :
        MI_TRACE_RETURN(CE_ERR_FILENAME);
    default :
        MI_TRACE_RETURN(err);
    }

  // OPEN 
  err=sf_open(&fh[no],tempo+65);
  switch (err)
  {
  case  0 :
      break;
  case 40 :
  case 43 :
  case 44 :
  case 51 :
      fh[no]=0;
      MI_TRACE_RETURN(err);
  default :
      fh[no]=0;
      MI_TRACE_RETURN(err);
  }

  // ALLOUE BUFFERS 
  file[no]=allocate(14);
  f_mode[no]=mode;
  if (file[no]==0L)
    MI_TRACE_RETURN(CE_ERR_MEMORY);

  f=file[no];
  f->b=allocate(N_OCTS);
  if (f->b==0L) 
    MI_TRACE_RETURN(CE_ERR_MEMORY);

  // Lit 1er paquet 
  err=sf_read(fh[no],0,f->b,N_SECTS);
  switch (err)
    {
    case  0 :
    case 48 :
        break;
    default :
        liberate(f->b);
        liberate(file[no]);
        MI_TRACE_RETURN(err);
    }

  f->s=0;
  f->o=-1;
  f->l=0;   // Num‚ro de ligne 
  f->e=-1;  // Flag erreur 
  f->m=0;   // Mode ‚criture 0/1 

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaZac_nextline: ABAL API

 * @param no      IN  : Logical numero
 * @param ligne   OUT : read line
 * @param lg_l    OUT : size of read line

 * @returns: CE_OK
             CE_ERR
             ?

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaZac_nextline(SWORD no,char FAR * ligne,SWORD FAR PTR lg_l)
{
MI_TRACE_DCL_TFN("ZacNextline");
SWORD lg_read;
SWORD Eof;
PASC_F f;

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",no));
  
  if (no < 1 || no > C_MAXLOG) 
    MI_TRACE_RETURN(CE_ERR);

  no--;
  if (fh[no] == 0) 
    MI_TRACE_RETURN(CE_ERR);

  f=file[no];

  if (f->e==64) 
    {   // Un coup pour rien 
    f->e=0;
    MI_TRACE_RETURN(CE_ERR);
    }
    
  if (f->e==48)
    MI_TRACE_RETURN(CE_ERR);
    
  if (f->o >= 0) 
    {
    if (f->b[f->o]==26) 
      { // octet courant = EOF 
      f->e=48;
      MI_TRACE_RETURN(CE_ERR);
      }
  }

  f->e=0;
  Eof=0;
  lg_read=0;

  while (1) 
    {
    f->o++;
    if (f->o == N_OCTS) 
      {
      f->o=0;
      f->s=f->s+N_SECTS;
      if (sf_read(fh[no],f->s,f->b,N_SECTS) != 0) 
        MI_TRACE_RETURN(CE_ERR);
      }

    switch (f->b[f->o]) 
      {
      case 26 :   // 1A 
        f->e=48;            
        ToolsAbalPutWord(lg_l,lg_read);
        MI_TRACE_RETURN(CE_ERR);

      case 'þ' :    // "þ" 
        if (R_MODE == 1) 
          {
          if (Eof == 1) 
            {
            f->e=48;
            ToolsAbalPutWord(lg_l,lg_read-1);
            MI_TRACE_RETURN(CE_ERR);
            }
          else 
            {
            Eof=1;
            ligne[lg_read]=f->b[f->o];
            lg_read++;
            }
          }
        else 
          {
          if (lg_read < N_OCTS) 
            ligne[lg_read]=f->b[f->o];
          lg_read++;
          }
        break;
        
      case 10:    // 0A 
        ToolsAbalPutWord(lg_l,lg_read);
        f->l++;
        MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT text='%s'",ligne));
        MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT size=%d"  ,lg_read));
        MI_TRACE_RETURN(f->l);
        
      case 13 :   // 0D 
        break;
        
      case 9 :    // TAB 
        if (f_mode[no] == 2 || f_mode[no] == 4) 
          {
          ligne[lg_read]=f->b[f->o];
          lg_read++;
          }
        else 
          {
          if (lg_read % 8 == 0) 
            {
            memset(ligne+lg_read,32,8);
            lg_read=lg_read+8;
            }
          while (lg_read % 8 != 0) 
            {
            ligne[lg_read]=' ';
            lg_read++;
            }
          }
        break;
      default :
        ligne[lg_read]=f->b[f->o];
        lg_read++;
        break;
      }
  }

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaZac_prevline: ABAL API

 * @param no      IN  : Logical numero
 * @param ligne   OUT : read line
 * @param lg_l    OUT : size of read line

 * @return: CE_OK, ?

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaZac_prevline(SWORD no,char FAR * ligne,SWORD FAR PTR lg_l)
{
MI_TRACE_DCL_TFN("ZacPrevline");
PASC_F f;
SWORD un;
WORD ret;

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",no));

  if (no < 1 || no > C_MAXLOG) 
    MI_TRACE_RETURN(CE_ERR);
  
  no--;
  if (fh[no] == 0) 
    MI_TRACE_RETURN(CE_ERR);
  
  un=0;
  f=file[no];
  if (f->e==48) 
    {   
    // Un coup pour rien 
    // On etait sur /1A, retour sur /0A 
    while (1) 
      {
      f->o--;
      if (f->o == -1) 
        {
        f->o=N_OCTS-1;
        f->s=f->s-N_SECTS;
        if (sf_read(fh[no],f->s,f->b,N_SECTS) != 0) 
          MI_TRACE_RETURN(CE_OK);
        }
      if (f->b[f->o] == 10) 
        break;
      }
    f->e=0;
    un=1;
  }
  
  if (f->l <= 1) 
    {
    if (f->e==-1) 
      MI_TRACE_RETURN(CE_ERR);

    f->e=-1;
    f->l=0;
    f->o=-1;
    MI_TRACE_RETURN(CE_ERR);
    }
  f->e=0;

  // Retour debut de 2 lignes en arriere 
  while (1) 
    {
    f->o--;
    if (f->o == -1) 
      {
      if (f->s == 0) 
        {
        f->l=0;
        f->e=-1;
        no++;
        ret = BdaZac_nextline(no,ligne,lg_l);
        MI_TRACE_RETURN(ret);
        }
      
      f->o=N_OCTS-1;
      f->s=f->s-N_SECTS;
      if (sf_read(fh[no],f->s,f->b,N_SECTS) != 0) 
        MI_TRACE_RETURN(CE_ERR);
      }
      
    if (f->b[f->o] == 10) 
      {   // 0A 
      f->l--;
      if (un == 0)
        un=1;
      else
        break;
      }
    }
    
  no++;
  ret = BdaZac_nextline(no,ligne,lg_l);
  MI_TRACE_RETURN(ret);
}

// ****************************************************************************
/** BdaZac_firstline: ABAL API

 * @param no      IN  : Logical numero
 * @param ligne   OUT : read line
 * @param lg_l    OUT : size of read line

 * @return: CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaZac_firstline(SWORD no,char FAR * ligne,SWORD FAR PTR lg_l)
{
MI_TRACE_DCL_TFN("ZacFirstline");
PASC_F f;
WORD ret;

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",no));
  
  if (no < 1 || no > C_MAXLOG) 
    MI_TRACE_RETURN(CE_ERR);
  
  no--;
  if (fh[no] == 0) 
    MI_TRACE_RETURN(CE_ERR);

  f=file[no];

  // Lit 1er paquet 
  if (sf_read(fh[no],0,f->b,N_SECTS) != 0) 
    MI_TRACE_RETURN(CE_ERR);

  f->s=0;   // Secteur courant 
  f->o=-1;  // Octet courant -1 
  f->l=0;   // Num‚ro de ligne 
  f->e=-1;  // Flag erreur 
  f->m=0;   // Mode ‚criture 

  no++;
  ret = BdaZac_nextline(no,ligne,lg_l);

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
/** BdaZac_lastline: ABAL API

 * @param no      IN  : Logical numero
 * @param ligne   OUT : read line
 * @param lg_l    OUT : size of read line

 * @return: CE_OK
 
 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaZac_lastline(SWORD no,char FAR * ligne,SWORD FAR PTR lg_l)
{
MI_TRACE_DCL_TFN("ZacLastline");
SWORD err;

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",no));
  
  // Lit jusqu'… la fin 
  err=0;
  while (err != -1)
      err=BdaZac_nextline(no,ligne,lg_l);
      
  err = BdaZac_prevline(no,ligne,lg_l);


MI_TRACE_RETURN(err);
}

// ****************************************************************************
/** BdaZac_read: ABAL API

 * @param no      IN  : Logical numero
 * @param ligne   OUT : read line
 * @param lg_l    OUT : size of read line

 @return: CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaZac_read(SWORD no,char FAR * ligne,SWORD lg)
{
MI_TRACE_DCL_TFN("ZacRead");
SWORD  lg_read;
PASC_F f;

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",no));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN lg=%d",lg));
  
  if (no < 1 || no > C_MAXLOG) 
    MI_TRACE_RETURN(CE_ERR);
    
  no--;
  if (fh[no] == 0) 
    MI_TRACE_RETURN(CE_ERR);

  f=file[no];

  lg_read=0;
  while (1) 
    {
    f->o++;
    if (f->o == N_OCTS) 
      {
      f->o=0;
      f->s=f->s+N_SECTS;
      if (sf_read(fh[no],f->s,f->b,N_SECTS) != 0)
        {
        MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT text='%s'",ligne));
        MI_TRACE_RETURN(lg_read);
        }
      }
    ligne[lg_read]=f->b[f->o];
    lg_read++;
    if (lg_read == lg)
      {
      MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT text='%s'",ligne));
      MI_TRACE_RETURN(lg_read);
      }
    }

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaZac_close: ABAL API

 * @param no      IN  : Logical numero
// *

 * @return: CE_OK
 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaZac_close(SWORD no)
{
MI_TRACE_DCL_TFN("ZacClose");
PASC_F f;
SWORD last;
SWORD nboct;
WORD  ret;

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d",no));

  if (no < 1 || no > C_MAXLOG) 
    MI_TRACE_RETURN(CE_ERR);

  no--;

  if (fh[no] == 0) 
    MI_TRACE_RETURN(CE_ERR);

  f=file[no];
  if (f->m == 1)    // Mode ecriture 
    {
    if (f->o != 0)
      {
      f->s=f->s+N_SECTS;
      memset(f->b+f->o,'ÿ',N_OCTS-f->o);
      last=f->o;
      nboct=last % 256;
      
      if (nboct != 0)
        last=(last/256)+1;
      else
        last=last/256;
        
      ret = sf_write(fh[no],f->s,f->b,last);  
       if ( ret != 0) 
        MI_TRACE_RETURN(CE_OK);
      }
    }
  
  sf_close(fh[no]);
  liberate(f->b);
  liberate(file[no]);
  fh[no]=0;
  
  MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaZac_create: ABAL API

 * @param no      IN : Logical numero
 * @param nom     IN : file name 

 * @returns: CE_OK ?

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaZac_create(SWORD no,char FAR * nom)
{
MI_TRACE_DCL_TFN("ZacCreate");
SWORD err;
SWORD i;
CHAR  tempo[82];
PASC_F f;

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no=%d"    ,no));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN name='%s'",nom));

  if (no < 1 || no > C_MAXLOG) 
    MI_TRACE_RETURN(CE_ERR_TOOMANYFILES);

  no--;

  // ANFC 
  i=0;
  while (nom[i] != ' ') 
    {
    tempo[i]=nom[i];
    i++;
    }
  
  tempo[i]=' ';
  err=sf_anfc(tempo,tempo+65);
  if (err != 0 && err != 32) 
    MI_TRACE_RETURN(err);

  // DFILE 
  err=sf_dfile(tempo+65);
  switch (err) 
    {
    case 0 :
    case 40 :
        break;
    default :
        MI_TRACE_RETURN(err);
    }

  // CFILE 
  err=sf_cfile(&fh[no],tempo+65);
  if (err != 0) 
    MI_TRACE_RETURN(err);

  // ALLOUE BUFFERS 
  file[no]=allocate(14);
  if (file[no]==0L) 
    MI_TRACE_RETURN(CE_ERR_MEMORY);

  f=file[no];
  f->b=allocate(N_OCTS);
  if (f->b==0L) 
    MI_TRACE_RETURN(CE_ERR_MEMORY);

  f->s=-N_SECTS;
  f->o=0;
  f->l=0;
  f->m=1;

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaZac_write: ABAL API

 * @param no      IN  : Logical numero
 * @param chaine  IN  : line
 * @param lg_l    IN  : size of line

 * @returns: CE_OK ?
 
 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaZac_write(SWORD no,char FAR * chaine,SWORD lg)
{
MI_TRACE_DCL_TFN("ZacWrite");
PASC_F f;
SWORD var;
SWORD idx=0;
SWORD err;

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN no  =%d"  ,no));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN text='%s'",chaine));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN size=%d"  ,lg));

  if (lg==0) 
    MI_TRACE_RETURN(CE_OK);
  
  if (no < 1 || no > C_MAXLOG) 
    MI_TRACE_RETURN(CE_ERR);
  
  no--;
  
  if (fh[no] == 0) 
    MI_TRACE_RETURN(CE_ERR2);
    
  f=file[no];
  if (lg < 0 || lg > N_OCTS) 
    MI_TRACE_RETURN(CE_ERR3);
    
  while (1)
    {
    if (f->o+lg < N_OCTS)   // ca rentre dans le secteur 
      {
      memcpy(f->b+f->o,chaine+idx,lg);  // up to date 
      f->o=f->o+lg;     // maj compteur d' octets 
      MI_TRACE_RETURN(CE_OK);
      }
    else        // ‚criture sur disque 
      {
      var=N_OCTS-f->o;
      memcpy(f->b+f->o,chaine+idx,var); // on finit Zrecep(1).
      f->s=f->s+N_SECTS;    // Ecriture 
      err=sf_write(fh[no],f->s,f->b,N_SECTS);
      if (err != 0) 
        MI_TRACE_RETURN(err);

      f->l=f->l+N_SECTS;
      f->o=0;
      idx=idx+var;
      lg=lg-var;
      }
    }

MI_TRACE_RETURN(CE_OK);
}
