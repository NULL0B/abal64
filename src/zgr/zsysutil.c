/** @pkg Staff.Fred.zSysUtil */

// ****************************************************************************
// * zSysUtil.c
// * Included in System module
// * Utility routines functionnalities
// ****************************************************************************



// ----------------------------------------------------------------------------
// - Internal Functions
// ----------------------------------------------------------------------------
#if defined(BDA_TWIN16) || defined(BDA_WIN32)
#define Portable_chdir _chdir
#else
#define Portable_chdir chdir
#endif

// ----------------------------------------------------------------------------
// - External Functions
// ----------------------------------------------------------------------------


// ****************************************************************************
/** BdaSys_zRleCompress: (THO name) zrlecpt - ABAL API - 
    Compacts a string with a very simple RLE algo

 * @param txtIn      IN
 * @param txtOut     OUT
 * @param lgIn       IN

 * @return: ?

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_zRleCompress(BYTE FAR* txtIn,BYTE FAR* txtOut,WORD lgIn)
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
EXAWORD BDA_API BdaSys_zRleDecompress(BYTE FAR* txtIn,BYTE FAR* txtOut,WORD lgIn)
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

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_zFind(char FAR * chaine,char FAR * achercher,WORD debut,WORD fin)
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
EXAWORD BDA_API BdaSys_zIndex(char FAR * chaine,CHAR car,WORD debut,WORD fin)
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
EXAWORD BDA_API BdaSys_zOem2Ansi(char FAR * chaine,WORD lg)
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
EXAWORD BDA_API BdaSys_zAnsi2Oem(char FAR * chaine,WORD lg)
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

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_zTab2Seq(WORD min,WORD max,char FAR * car,char FAR * sty,char FAR * s,WORD x_min,WORD y, char FAR * pseq,char FAR * osty,WORD mode)
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

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_EmptyFunction()
{
MI_TRACE_DCL_TFN("EmptyFunction");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaSys_zChDir: (THO name) zchdir - ABAL API
    Changes directory. This function is implemented only in ZDLL. Why ? bug ?

 * @param dir_nom   IN

 * @returns
   CE_OK
   CE_ERR

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_zChDir(char FAR * dir_nom)
{  
MI_TRACE_DCL_TFN("ChDir");
CHAR  nom_dir[64];
WORD i,j;

MI_TRACE_BEGIN();

  i=0;
  j=0;

  if (dir_nom[0]==' ' || dir_nom[0]==0) 
    MI_TRACE_RETURN(CE_OK);

  while (1) 
    {
    if (dir_nom[i]==' ') break;
    if (dir_nom[i]==0)   break;
    nom_dir[j]=dir_nom[i];
    i++;
    j++;
    }
  j--;
  while (1) 
    {       // Vire dernier '\'
    if (nom_dir[j]!=CI_CHAR_SLASH) break;
    j--;
    }
  nom_dir[j+1]=0;

  i=Portable_chdir(nom_dir); // this function returns 0 or -1 
  MI_TRACE_RETURN(i);
}
