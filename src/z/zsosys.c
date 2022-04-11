// ****************************************************************************
// * zsoSys.c
// * System module
// ****************************************************************************

#define  CI_MODULE_ID   0x0001

#include "wdef.h"

// ----------------------------------------------------------------------------
// - Headers of modules
// ----------------------------------------------------------------------------
#include "ztrace.h"
#include "zsoext.h"
#include "zsosys.h"

// ----------------------------------------------------------------------------
// - Constants
// ----------------------------------------------------------------------------
#define C_RLE 0xFE

// ****************************************************************************
// * BdaSys_zPush: (THO name) zzpush - ABAL API - 
// *   jamais appelé en mode ASFUN dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaSys_zPush(WORD x1,WORD y1,WORD x2,WORD y2,WORD sha)
{
MI_TRACE_DCL_TFN("Push");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
// * BdaSys_zPop: (THO name) zzpop - ABAL API - 
// *   jamais appelé en mode ASFUN dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaSys_zPop()
{
MI_TRACE_DCL_TFN("Pop");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaSys_zInit: (THO name) zzinit _ ABAL API
    Initialisation

 * @param version    IN/OUT

 * @return: CE_OK, CE_ERR, CE_ERR_MEMORY, CE_ERR_BADFONTFILE, 
            CE_ERR_BADFONTSYSTEM, CE_ERR_FILEACCESS
               
 * @author VAP 9.12.00

 */
// * VarGlob: 
// ****************************************************************************
WORD BdaSys_zInit(PTRC version)
{
MI_TRACE_DCL_TFN("zInit");

MI_TRACE_BEGIN();

	/* Test version Z-Library: */
	if (memcmp(version,"5.00",4) > 0)
	    return(CE_ERR);

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaSys_zEnd: (THO name) zend - ABAL API
    End

 * @param version    IN/OUT

 * @return: CE_OK
 */
// * VarGlob: 
// ****************************************************************************
WORD BdaSys_zEnd()
{
MI_TRACE_DCL_TFN("zEnd");
MI_TRACE_BEGIN();
MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
// * BdaSys_zHide: (THO name) zbhide - ABAL API
// *   jamais appelé dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaSys_zHide(WORD flag)
{
MI_TRACE_DCL_TFN("Hide");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
// * BdaSys_zShow: (THO name) zbshow - ABAL API
// *   jamais appelé dans la couche ABAL
// *   ==> non implémentée
// ****************************************************************************
WORD BdaSys_zShow(WORD flag,WORD x1,WORD y1,WORD x2,WORD y2)
{
MI_TRACE_DCL_TFN("Show");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
// * BdaSys_zWait: (THO name) zw_wait - ABAL API - 
// *    Give hand to the system during 100ms
// ****************************************************************************
WORD BdaSys_zWait()
{
//Pas de trace car très fréquent
//MI_TRACE_DCL_TFN("Wait");
//MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,""));
usleep( 100000L );
return CE_OK;
}

// ****************************************************************************
/** BdaSys_zRleCompress: (THO name) zrlecpt - ABAL API - 
    Compacts a string with a very simple RLE algo

 * @param txtIn      IN
 * @param txtOut     OUT
 * @param lgIn       IN

 * @return: ?

 */
// * VarGlob: 
// ****************************************************************************
WORD BdaSys_zRleCompress(BYTE FAR* txtIn,BYTE FAR* txtOut,WORD lgIn)
{
MI_TRACE_DCL_TFN("zRleCompress");
SWORD rep;
WORD  i,j;

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN txtIn='%s'",txtIn));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN lgIn =%d"  ,lgIn));

  i=0;
  j=0;

  // Mets le car. de compactage RLE:
  txtOut[j++]=C_RLE;

  while (i < lgIn)
  {
      // Caractère de contrôle:
      if (txtIn[i] == C_RLE)
      {
      txtOut[j++]=C_RLE;
      txtOut[j++]=C_RLE;
      i++;
      }
      else
      {
      if (txtOut[j-1] == txtIn[i])  // Répétition
      {
        rep=1;      // répet = 1
        i++;      // suivant...
        while (rep < 127)
        {
          if (i >= lgIn) 
            break;   // dépassement maximum autorisé
          if (txtOut[j-1] != txtIn[i]) 
            break; // si différent, abandonne
          i++;
          rep++;
        }
        txtOut[j++]=C_RLE;
        txtOut[j++]=(char)rep;
      }       // Pas répétition
      else
        txtOut[j++]=txtIn[i++];
      }
  }
  txtOut[j++]=C_RLE;
  txtOut[j++]=0;

  
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT txtOut='%s'",txtOut));
  MI_TRACE_RETURN(j);
}

// ****************************************************************************
/** BdaSys_zRleDecompress: (THO name) zrledcpt - ABAL API - 
    Expands a string with a very simple RLE algo

 * @param txtIn       IN
 * @param txtOut      OUT
 * @param lgIn        unused

 * @return: ?

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
WORD BdaSys_zRleDecompress(BYTE FAR* txtIn,BYTE FAR* txtOut,WORD lgIn)
{
MI_TRACE_DCL_TFN("RleDecompress");
WORD k;
WORD rep;
WORD  i,j;

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN txtIn='%s'",MI_TRA_TRUNC(txtIn)));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN lgIn =%04X",lgIn));

  i=1;
  j=0;

  // Pas caractère de contrôle :
  while (1)
    {
      if (txtIn[i]==C_RLE)
        {
        i++;
        switch (txtIn[i])
          {
          case 0 :    // Fin
              MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"i=%04Xh",i));
              MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"Dump txtIn",txtIn,i));

              MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"j=%04Xh",j));
              MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"Dump txtOut",txtOut,j));

              MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT txtOut='%s'",MI_TRA_TRUNC(txtOut)));
              MI_TRACE_RETURN(j);
              
          case C_RLE :    // Car de contrôle
              //MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"C_RLE i=%04Xh",i));
              txtOut[j++]=C_RLE;
              i++;
              break;
              
          default :   // Répétition
              rep=txtIn[i];
              //MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"rep=%04Xh",rep));
              for (k=0;k<rep;k++)
                txtOut[j++]=txtIn[i-2];
              i++;
              break;
          }
        }
      else      // Pas FEh
        txtOut[j++]=txtIn[i++];
    }
}

// ****************************************************************************
/** BdaSys_zFind: (THO name) zzfind - ABAL API - 
    Finds a string in a string

 * @param chaine      IN
 * @param achercher   IN
 * @param debut       IN
 * @param fin         IN

 * @returns
     0     = not found
     other = index in string

 */
// * VarGlob: 
// ****************************************************************************
WORD BdaSys_zFind(PTRC chaine,PTRC achercher,WORD debut,WORD fin)
{
MI_TRACE_DCL_TFN("Find");
WORD i,j=0;

MI_TRACE_BEGIN();

  while (achercher[j] != ' ') 
    j++;
    
  for (i=debut-1;i<fin;i++) 
    {
    if (memcmp(chaine+i,achercher,j) == 0) 
      break;
    }
    
  if (i >= fin)
    MI_TRACE_RETURN(0);
  else
    MI_TRACE_RETURN(i+1);
}

// ****************************************************************************
/** BdaSys_zIndex: (THO name) zindex - ABAL API - 
    Finds a char in a string

 * @param chaine      IN
 * @param car         IN
 * @param debut       IN
 * @param fin         IN

 * @returns 
   0     = not found
   other = index in string

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
WORD BdaSys_zIndex(PTRC chaine,CHAR car,WORD debut,WORD fin)
{
MI_TRACE_DCL_TFN("Index");
WORD  i;

MI_TRACE_BEGIN();

  i=(debut-1);
  while (1) 
    {
    if (i >= fin) 
      MI_TRACE_RETURN(0);
    if (chaine[i] == car) 
      MI_TRACE_RETURN(i+1);
    i++;
    }
}

// ****************************************************************************
/** BdaSys_zOem2Ansi: (THO name) zoem2ansi - ABAL API - (Windows only)
    Converts OEM charset string to ANSI charset string

 * @param chaine      IN
 * @param lg          IN

 * @return: CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
WORD BdaSys_zOem2Ansi(PTRC chaine,WORD lg)
{
MI_TRACE_DCL_TFN("Oem2Ansi");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaSys_zAnsi2Oem : (THO name) zansi2oem - ABAL API - (Windows only)
    Converts ANSI charset string to OEM charset string

 * @param chaine      IN
 * @param lg          IN

 * @return: CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
WORD BdaSys_zAnsi2Oem(PTRC chaine,WORD lg)
{
MI_TRACE_DCL_TFN("Ansi2Oem");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaSys_zTab2Seq: (THO name) ztab_2_seq - ABAL API - 
    Converts a Z-SCREEN table to Escape sequence
    This function is called by the Painter (see ZEDI_UNX.S)
    
 * @param min       IN
 * @param max       IN
 * @param car       ?
 * @param sty       ?
 * @param s         ?
 * @param x_min     IN
 * @param y         IN
 * @param pseq      ?
 * @param osty      ?
 * @param mode      IN

 * @return: ?

 */
// * VarGlob: 
// ****************************************************************************
WORD BdaSys_zTab2Seq(WORD min,WORD max,PTRC car,PTRC sty,PTRC s,WORD x_min,WORD y, PTRC pseq,PTRC osty,WORD mode)
{
MI_TRACE_DCL_TFN("Tab2Seq");
WORD  x,i,lg=0;
CHAR  c[1];
WORD  s_l=0;
WORD  oxm;
CHAR  ch[1024];

MI_TRACE_BEGIN();

  min--;
  y--;
  oxm=min;

  switch (mode) 
    {
  
    case 0 :    // Affic générateur d'écrans
        for (x=min ; x<max ; x++) 
          {
          if (lg == 0) 
            oxm=x;
          if (sty[x] != osty[0]) 
            {
            osty[0]=sty[x];
            for (i=2;i<16;i++) 
              {
              if (pseq[((osty[0]-1)*16)+i] == '/') 
                break;
              }
            memcpy(ch+lg,pseq+((osty[0]-1)*16),i);
            lg+=i;
            }
          ch[lg++]=car[x];
          }
        break;
  
    case 1 :    // Affic prototypeur
        for (x=min ; x<max ; x++) 
          {
          if (car[x] == ' ') 
            {
            if (lg > 0) 
              {
              s[s_l++]=27;
              s[s_l++]='f';
              s[s_l++]=(CHAR)(oxm+x_min-1+32);
              s[s_l++]=(CHAR)(y+32);
              memcpy(s+s_l,ch,lg);
              s_l=s_l+lg;
              lg=0;
              }
            }
          else 
            {
            if (lg == 0) 
              oxm=x;
            if (sty[x] != osty[0]) 
              {
              osty[0]=sty[x];
              for (i=2;i<16;i++) 
                {
                if (pseq[((osty[0]-1)*16)+i] == '/') 
                  break;
                }
              memcpy(ch+lg,pseq+((osty[0]-1)*16),i);
              lg+=i;
              }
            c[0]=car[x];
            if (c[0] == 'ú')
              ch[lg++]=' ';
            else
              ch[lg++]=car[x];
            }
          }
        break;
  
    case 2 :    // Affic vecteurs
        for (x=min ; x<max ; x++) 
          {
          if (sty[x] == 0) 
            {
            if (lg > 0) 
              {
              s[s_l++]=27;
              s[s_l++]='f';
              s[s_l++]=(CHAR)(oxm+x_min+31);
              s[s_l++]=(CHAR)(y+32);
              memcpy(s+s_l,ch,lg);
              s_l=s_l+lg;
              lg=0;
              }
            }
          else 
            {
            if (lg == 0) 
              oxm=x;
            if (sty[x] != osty[0]) 
              {
              osty[0]=sty[x];
              for (i=2;i<16;i++) 
                {
                if (pseq[((osty[0]-1)*16)+i] == '/') 
                  break;
                }
              memcpy(ch+lg,pseq+((osty[0]-1)*16),i);
              lg+=i;
              }
            ch[lg++]=car[x];
            }
          }
        break;
    }

  // Fin commune:
  if (lg > 0) 
    {
    s[s_l++]=27;
    s[s_l++]='f';
    s[s_l++]=(CHAR)(oxm+x_min-1+32);
    s[s_l++]=(CHAR)(y+32);
    memcpy(s+s_l,ch,lg);
    s_l=s_l+lg;
    }
    
MI_TRACE_RETURN(s_l);
}

// ****************************************************************************
/* BdaSys_EmptyFunction: ABAL API
    Does nothing, except trace message. For unused entry points

 * @return: CE_OK

 */
// * VarGlob: 
// ****************************************************************************
WORD BdaSys_EmptyFunction()
{
MI_TRACE_DCL_TFN("EmptyFunction");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
// BdaSys_AnalAsfun: ABAL API
// Reproduction en C du code assembleur de Oulès, avec les conneries originelles
// 
// ****************************************************************************
WORD BdaSys_AnalAsfun(PTRC String,WORD iDeb, WORD iFin, WORD* pLg, WORD* pLgTot, WORD* pZa, WORD* pZc, WORD* pZf)
{
MI_TRACE_DCL_TFN("AnalAsfun");
WORD  i;
WORD  Etat;
WORD  Cpt;
WORD  x;
BOOL  IsEsc;

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN string='%s'",MI_TRA_TRUNC(String) ));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN debut=%d, fin=%d"  ,iDeb,iFin));

// --- Initialisations
iDeb--;
iFin--;
Cpt=0;

// --- Test des indices
if (iDeb>iFin)
  MI_TRACE_RETURN(0);

// --- Boucle de recherche d'un Escape
for (i=iDeb, IsEsc=FALSE ; ((i<=iFin) && (!IsEsc)) ; i++)
  {
  //MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"IsEsc String[%d]='%c'",i,String[i]));
  IsEsc = (String[i]==0x1B);
  }

if (!IsEsc)
  {
  *pLg    = iFin-iDeb+1;
  *pLgTot = iFin-iDeb+1;
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Lg=%d, LgTot=%d"  ,*pLg,*pLgTot));
  MI_TRACE_RETURN(3);
  }  

// --- Boucle d'analyse de la séquence et passage à la suivante
*pLg = i-iDeb-1;

do
  { 
  //MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"Anal String[%d]='%c'",i,String[i]));
  switch( String[i] )
    {
    case 'a':
      *pZa = 0x0000;
      Cpt += 2;
      Etat = 2;
      break;
      
    case 'p':
    case 'h':
      *pZa = 0x0008;
      Cpt += 2;
      Etat = 2;
      break;
      
    case 'b':
      *pZa = 0x0001;
      Cpt += 2;
      Etat = 2;
      break;
      
    case 'c':
      *pZa = 0x0080;
      Cpt += 2;
      Etat = 2;
      break;
      
    case 'd':
      *pZa = 0x0002;
      Cpt += 2;
      Etat = 2;
      break;
          
    case 'r': // couleur
      x = String[++i]-'0';
      *pZc = (x>9) ? x-7 : x;
      Cpt += 3;
      Etat = 2;
      break;
          
    case 's': // couleur
      x = String[++i]-'0';
      *pZf = (x>9) ? x-7 : x;
      Cpt += 3;
      Etat = 2;
      break;
          
    case 'f': // position curseur
      *pZf = String[++i]-0x1F;
      *pZc = String[++i]-0x1F;
      Cpt += 4;
      Etat = 4;
      // SORTIE      
      break;
          
    default:
      Cpt += 3;
      Etat = 5;
      // SORTIE
      break;
    } 
     
  i++;
  //MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"Anal String[%d]='%c'-'%c'",i,String[i],String[i+1]));
  }
while(  (Etat == 2)         /*ce test permet de sortir du 'f' et default sans goto */ 
     && (i+1<iFin)          /*ce test n'existe pas chez Oulès*/ 
     && (String[i]==0x1B) 
     && (String[++i]!='f') 
     );

MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"Anal String[%d]='%c'",i,String[i]));

*pLgTot = *pLg + Cpt;
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT za=%d, zc=%d zf=%d" ,*pZa,*pZc,*pZf));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Lg=%d, LgTot=%d" ,*pLg, *pLgTot));
MI_TRACE_RETURN(Etat);
}

/*****************************************************************************
* BdaSys_CptCharInString 
*	Compte le nbre de caractères d'une chaine (c'est du Oules pur jus)
*
*	Input:	chaine, longueur, car … compter
*
*	Output:	Nombre
*
*****************************************************************************/
WORD BdaSys_CptCharInString(PTRC ch, WORD lg, PTRC car)
{
MI_TRACE_DCL_TFN("AnalAsfun");
WORD	i,cpt=0;

MI_TRACE_BEGIN();
	for (i=0;i<lg;i++) 
	  {
	  if (ch[i] == car[0]) 
	    cpt++;
	  }
MI_TRACE_RETURN(cpt);
}

/*****************************************************************************
* BdaSys_TransformBadCar
*	Enlève les cars. < 32 (c'est du Oules pur jus)
*
*	Input:	string, longueur
*
*	Output:	Rien
*
*****************************************************************************/
WORD BdaSys_TransformBadCar(WORD lg,PTRC str)
{
MI_TRACE_DCL_TFN("TransformBadCar");
WORD	i;

MI_TRACE_BEGIN();
	for (i=0;i<lg;i++) 
	  {
	  if (str[i] >= 0 && str[i] < 32) 
	    str[i]='ù'; //0xF9
	  }
MI_TRACE_RETURN(CE_OK);
}

/******************************************************************************
* BdaSys_Zadrs 
*	Rends un pointeur sur les pointeurs sur les fonctions
* Cette fonction n'est jamais appelé par la couche ABAL
* ==> non implémentée...
*
******************************************************************************/
WORD BdaSys_Zadrs(PTRC adresse)
{
MI_TRACE_DCL_TFN("Zadrs");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}
