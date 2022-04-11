/** @pkg Staff.Fred.zGuiCtrl */ 
// ****************************************************************************
// * zTexPrin.c
// * Included in TEX module
// * Print management
// ****************************************************************************


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Internal Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// ****************************************************************************
/** PrintEsc :  
    Display a text with Escape sequence analysis
    This algorithm is adapted from zdll THO brain-storming

 * @parameter str      
 * @parameter nbchar      

 * @return: 0
 
 * @author FRC
 
*/
// * VarGlob:
// ****************************************************************************
WORD PrintEsc(WORD hFont, char FAR * str, WORD nbchar, WORD Mode)
{
MI_TRACE_DCL_TFN("PrintEsc");
WORD  ini=0;  // index in 'str' on the 1st character to display
WORD  cpt=0;  // number of character to display since 'ini'
WORD  i  =0;  // current index in 'str'
CHAR  c;     // a character from 'str'
WORD  Color; // color identified by an escape sequence
WORD  grx,gry;
SWORD fontID;

  grx = (cicogetcolumn()-1) * cellwidth;
  gry = (cicogetline()  -1) * cellheight;
  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"at gr(%d,%d)",grx,gry));

  while (i < nbchar)
    {
    if ((str[i]=='\x1B') && (i+1 < nbchar))
      {
      // ----------------------------
      // - Escape sequence found
      // ----------------------------
      
      // Flush the text on the screen
      if (cpt != 0)
        {
        grx = PixelFontLat(grx,gry,hFont,&str[ini],cpt);
        MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"'%s'",MI_TRA_TRUNC(&str[ini])));
        }
      cpt=0;
      
      // Esc sequence analysis
        switch (str[i+1])
          {
          case 'r' :
              if ( (Mode & CI_ESC_F_FG) && (i+2 < nbchar))
                {
                // Foreground color
                // Use in lists and during inputing
                c = str[i+2];
                switch (c)
                  {
                  case '0': Color = CI_COL_BLACK;                         break; // don't use transparent color
                  case 'T': Color = CI_COL_TRANSPARENT;                   break; // new feature to accept transparence
                  case 'G': Color = g_pLook->Window.ColorFGTitleActive;   break; 
                  case 'H': Color = g_pLook->Menu.ColorFGNormal;          break;
                  case 'I': Color = g_pLook->Input.ColorFGSelected;       break; // used during inputing
                  case 'J': Color = g_pLook->Window.ColorFGTitleInactive; break;
                  case 'K': Color = g_pLook->Input.ColorFGNormal;         break; // used during inputing
                  case 'L': Color = g_pLook->Window.ColorFGNormal;        break;
                  default : Color = (c<= '9') ? c-48 : c-55;              break; // Assume 0 to 15
                  }
                TexSetFG(Color);
                }
              i+=3;
              break;
  
          case 's' :
              if ((Mode & CI_ESC_F_BG) && (i+2 < nbchar))
                {
                // Background color
                // Use in lists and during inputing
                c = str[i+2];
                switch (c)
                  {
                  case '0': Color = CI_COL_BLACK;                         break; // don't use transparent color
                  case 'T': Color = CI_COL_TRANSPARENT;                   break; // new feature to accept transparence
                  case 'G': Color = g_pLook->Window.ColorBGTitleActive;   break; 
                  case 'H': Color = g_pLook->Menu.ColorBGNormal;          break;
                  case 'I': Color = g_pLook->Input.ColorBGSelected;       break; // used during inputing
                  case 'J': Color = g_pLook->Window.ColorBGTitleInactive; break;
                  case 'K': Color = g_pLook->Input.ColorBGNormal;         break; // used during inputing
                  case 'L': Color = g_pLook->Window.ColorBGNormal;        break;
                  default : Color = (c<= '9') ? c-48 : c-55;              break; // Assume 0 to 15
                  }
                TexSetBG(Color);
                }
              i+=3;
              break;
  
          case 'f' :
              if ((Mode & CI_ESC_F_POSIT) && (i+3 < nbchar))
                {
                // Change curser position, used by ZRC files
                grx = ((str[i+2]-0x1F/*+dx*/)-1) * cellwidth;
                gry = ((str[i+3]-0x1F/*+dy*/)-1) * cellheight;
                cicocurser(str[i+2]-0x1F/*+dx*/,str[i+3]-0x1F/*+dy*/);
                //MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"%f at (%02X,%02X)",str[i+2]-0x1F,str[i+3]-0x1F));
                }
              i+=4;
              break;
  
          case 'P' :
              if ((Mode & CI_ESC_F_FONT) && (i+2 < nbchar))
                {
                // Change font (THO functionnality instead of CICO), used by ZRC files
                c = str[i+2];
                fontID = (c<= '9') ? c-48 : c-55;
                TexSetFont(TexFontIDToHandle(fontID));
                //MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"%P %02X",fontID));
                }
              i+=3;
              break;
  
          case 'a' :
          case 'h' :
          case 'b' :
              // used, but not implemented 
              i+=2;
              break;
  
          default :
              // THO algorithm, assumes all other sequences are 2...
              // see with Warnings if it is true !
              MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"Unknown Esc %02X",str[i+1]));
              i+=2;
              break;
          }
        ini=i;
      }

    else
      {      
      // ----------------------------
      // - Printable character
      // ----------------------------
      i++;
      cpt++;
      }
    }// end while (i < lg)

  // Flush the text on the screen
  if (cpt != 0) 
    {
    grx = PixelFontLat(grx,gry,hFont,&str[ini],cpt);
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"'%s'",MI_TRA_TRUNC(&str[ini])));
    }

  SetCicoPixelColumn(grx);
  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"PixCol at %d",grx));
  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"GetCol at %d",cicogetcolumn()));

  return(0);
}

// ****************************************************************************
/** TexCopyRemoveEsc :  
    Removes Esc sequences from a string. Assumes the destination buffer 
    has the same size of source buffer + 1 for '\0'.
    (see 'PrintEsc' to get explanations on Esc analyse)

 * @parameter Dst OUT string destination (assume, has the same length as Src)
 * @parameter Src IN  string source
 * @parameter lg  IN  length of source and Dst buffer    

 * @return: strlen of Dst
 
 * @author FRC
*/
// * VarGlob: nothing
// ****************************************************************************
WORD TexCopyRemoveEsc(char FAR * Dst, char FAR * Src, WORD lg )
{
MI_TRACE_DCL_TFN("TexCopyRemoveEsc");
WORD ini =0;  // index in 'str' on the 1st character to display
WORD cpt =0;  // number of character to display since 'ini'
WORD i   =0;  // current index in 'str'
WORD iDst=0;

  while (i < lg)
    {
    if (Src[i]=='\x1B')
      {
      // ----------------------------
      // - Escape sequence found
      // ----------------------------
      
      // Flush the text
      if (cpt != 0) 
        {
        memcpy(&Dst[iDst],&Src[ini],cpt);
        iDst+=cpt;
        }
      cpt=0;
      
      // Esc sequence analysis
      switch (Src[i+1])
        {
        case 'r' :
        case 's' :
        case 'P' :
            i+=3;
            break;
        case 'f' :
            i+=4;
            break;
        default :
            i+=2;
            break;
        }
      ini=i;
      }

    else
      {      
      // ----------------------------
      // - Printable character
      // ----------------------------
      i++;
      cpt++;
      }
    }// end while (i < lg)

  // Flush the text
  if (cpt != 0) 
    {
    memcpy(&Dst[iDst],&Src[ini],cpt);
    iDst+=cpt;
    }

  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%d",iDst));
  return iDst;
}


// ****************************************************************************
/** TexPrint :  
    Display a text according to Mode (no Esc control, remove Esc, analyse Esc)

 * @parameter str       IN text to display     
 * @parameter nbchar    IN length to display
 * @parameter Mode      IN mode (see CI_ESC_xxx)

 * @return: 0
 
 * @author FRC
 
*/
// * VarGlob:
// ****************************************************************************
WORD TexPrint(WORD hFont, char FAR * str, WORD nbchar, WORD Mode)
{
MI_TRACE_DCL_TFN("TexPrint");
WORD  grx,gry;
WORD  OldMargin,NewMargin;

grx = (cicogetcolumn()-1) * cellwidth;
gry = (cicogetline()  -1) * cellheight;

if (Mode & CI_CLIP_ON)
  {
  NewMargin = grx+nbchar*cellwidth;
  OldMargin = CicoFontMargin(NewMargin);
  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"Margin Old=%d New=%d",OldMargin,NewMargin));
  }

if (Mode & CI_ESC_PROCESS)
  {
  // Display with a string analysis
  PrintEsc(hFont,str,nbchar,Mode);
  }
else
  {
  // Display without control
  grx = PixelFontLat(grx,gry,hFont,str,nbchar);
  SetCicoPixelColumn(grx);
  }

if (Mode & CI_CLIP_ON)
  CicoFontMargin(OldMargin);

return 0;
}

// ****************************************************************************
/** TexPrintXY :  
    Display a text according to Mode (no Esc control, remove Esc, analyse Esc)
    at position (x,y)
    
 * @parameter x       IN  text coordinate
 * @parameter y       IN  text coordinate
 * @parameter text    IN  text
 * @parameter lg      IN  text length
 * @parameter Mode    IN mode (see CI_ESC_xxx)

 * @return: 0
 
 * @author VAP
 
*/
// * VarGlob:
// ****************************************************************************
WORD TexPrintXY(WORD hFont, WORD x,WORD y,char FAR * text, WORD lg, WORD Mode)
{
WORD ret = 0;
  // When coordinates are (0,0) or empty text, don't change the curser position
  cicocurser(x,y);

  if (lg!=0)
    ret = TexPrint(hFont, text, lg, Mode);

  return ret;
}

// ****************************************************************************
/** TexPrintGrXY :  
    Display a text according to Mode (no Esc control, remove Esc, analyse Esc)
    at graphical position (grx,gry)
    
 * @parameter x       IN  graphical coordinate
 * @parameter y       IN  graphical coordinate
 * @parameter text    IN  text
 * @parameter lg      IN  text length
 * @parameter Mode    IN mode (see CI_ESC_xxx)

 * @return: 0
 
 * @author VAP
 
*/
// * VarGlob:
// ****************************************************************************
WORD TexPrintGrXY(WORD hFont, WORD grx,WORD gry,char FAR * text, WORD lg, WORD Mode)
{
char FAR *  pNoEsc;
WORD  lgNoEsc;

if (Mode & CI_ESC_PROCESS)
  {
  // remove Escape sequence before display
  pNoEsc = allocate(lg);
  if (pNoEsc!=NULL)
    {
    lgNoEsc = TexCopyRemoveEsc(pNoEsc, text, lg);
    grx = PixelFontLat( grx, gry, hFont, text, lg);
    liberate(pNoEsc);
    }
  }
else
  {
  // Display without control
  grx = PixelFontLat( grx, gry, hFont, text, lg);
  }

SetCicoPixelColumn(grx);
return 0;
}

// ****************************************************************************
/*  TexPrintXY_FillBG
    Display a text with our own management of the background. 
    Mode is automatically filtered to authorize only FG escape analysis and
    clipping management.

 * @parameter hFont   IN  
 * @parameter x       IN  
 * @parameter y       IN  
 * @parameter lg      IN  
 * @parameter text    IN  
 * @parameter Mode    IN  
 * @return: nothing
 * @author FRC
*/
// * VarGlob: nothing
// ****************************************************************************
VOID TexPrintXY_FillBG( WORD hFont, WORD x, WORD y, char FAR * text, WORD lg, WORD Mode)
{
MI_TRACE_DCL_TFN("TexPrintXY_FillBG");
char FAR *  pNoEsc;
WORD  lgNoEsc;
WORD  OldBG;

  OldBG = TexGetBG();
  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"OldBG=%04X",OldBG));

  // Set background on size without Esc
  pNoEsc = allocate(lg);
  if (pNoEsc!=NULL)
    {
    lgNoEsc = TexCopyRemoveEsc(pNoEsc, text, lg);
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"avant TFBg"));
    TexFillBackground(hFont, x, y, OldBG, lgNoEsc);
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"apres TFBg"));
    liberate(pNoEsc);
    }

  // Print text in transparent background with Escape sequences if any
  TexSetBG(CI_COL_TRANSPARENT);
  Mode &= (CI_CLIP_ON | CI_ESC_PROCESS | CI_ESC_F_FG);
  TexPrintXY(hFont, x,y,text,lg,Mode);
  TexSetBG(OldBG);
  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"the end"));
}

// ****************************************************************************
/*  TexPrintButtonCaption
    (Only for FIXE FONT)
    Button caption displaying. 
    Display a text with an underlined character, 
    and a graphic offset (1,1) if IsPushed is set.

 * @parameter x             IN  text coordinate
 * @parameter y             IN  text coordinate
 * @parameter mptr          IN  text
 * @parameter lg            IN  text length
 * @parameter kptr          IN  The first occurence of this character will be underlined
 * @parameter ColHotKey     IN  color for underlined character
 * @parameter IsEvenHeigth  IN  TRUE if the text must be vertically centered between 2 lines
 * @parameter IsPushed      IN  TRUE if the text must be shift to simulate push effect

 * @return: NOTHING
 
 * @author Jamie
 
*/
// * VarGlob: nothing
// ****************************************************************************
VOID  TexPrintButtonCaption(  WORD hFont, WORD x, WORD y, char FAR * mptr, WORD lg, char FAR * kptr, WORD ColHotKey, WORD IsEvenHeigth, WORD IsPushed )
{
WORD  status=0;
WORD  i;
WORD  grx,gry;
WORD  grxHot,gryHot;
WORD  grcxHot,grcyHot;

  grx = (x-1)*cellwidth;
  gry = (y-1)*cellheight;

  if (IsPushed)
    {
    grx++;
    gry++;
    }

  if (IsEvenHeigth)
    gry -= (cellheight/2);

  // The key will be a space character if no key is to be shown
  if ( *kptr != ' ' ) status = 0; else status = 1;

  for ( i=0; i < lg; i++ ) 
    {
    if (!( *(mptr+i) ))
      break;

    PixelFontCat(grx, gry, hFont, mptr[i]);

    if ((!( status )) && (*(mptr+i)==*kptr)) 
      {
      grxHot  = grx + g_pTabFont->Font[hFont].GrOffset.x;
      gryHot  = gry + cellheight - g_pTabFont->Font[hFont].GrOffset.y - 1;
      grcxHot = cellwidth - 2*g_pTabFont->Font[hFont].GrOffset.x;
      grcyHot = 1;
      
      if (ColHotKey<=CI_COL_CICO_WHITE)
        ColHotKey = g_pLook->ColorCicoToPalette[ColHotKey];
      filzone( grxHot, gryHot, grcxHot, grcyHot, ColHotKey);

      status = 1;
      }

    grx +=cellwidth; 
    }

}

// ****************************************************************************
/*  TexPrintMenuItem
    (Only for FIXE FONT)
    Menu item displaying. 
    Display a text whith an underlined character (shortcut).
    The text is componed like this: "main-text\xx", 
      where 'main-text' is displayed from the left margin
      and 'xx' is the shortcut name (2 characters) displayed at the end
    Truncation of left text and right alignement depends on the presence 
    of a shortcut and child menu 

 * @parameter x       IN  text coordinate
 * @parameter y       IN  text coordinate
 * @parameter mptr    IN  text
 * @parameter lg      IN  text length
 * @parameter kptr    IN  The first occurence of the character underlined
 * @parameter ColHotKey     IN  color for underlined character
 * @parameter ColHotKey     IN  color for underlined character

 * @return: NOTHING
 
 * @author FRC, from zprintkeyed
 
*/
// * VarGlob: nothing
// ****************************************************************************
VOID  TexPrintMenuItem(  WORD hFont, WORD x, WORD y, char FAR * mptr, WORD lg, char FAR * kptr, WORD ColHotKey, WORD HasChild)
{
  MI_TRACE_DCL_TFN("TexPrintMenuItem");
  WORD  i;
  CHAR  CarKey=*kptr;
  WORD  IsSearchingUnderlined;
  WORD  IsShortcut;
  WORD  iShortcut;
  WORD  LgRight;
  WORD  OldFG;
  WORD  grx,gry;
  WORD  grxHot,gryHot;
  WORD  grcxHot,grcyHot;

  // --------------------------------------
  // - Identifies left part
  // --------------------------------------
  IsShortcut = FALSE;
  iShortcut  = 0;
  LgRight    = lg;
  
  // Look if there is a shortcut
  for ( i=0 ; (i<lg) && (mptr[i]!='\0') ; i++ ) 
    {
    if (mptr[i]=='\\')
      {
      IsShortcut = TRUE;
      iShortcut = i+1;
      break;      
      }
    }

  // --------------------------------------
  // Truncation and alignment
  // If shortcut, cut at lg-3 to get the same vertical alignement for all the shortcuts
  // Else       , I let the maximum of place for the left part
  // --------------------------------------
  if (IsShortcut)
    LgRight = lg-3;
  else
    LgRight = (HasChild) ? lg-1 : lg;

  // --------------------------------------
  // - Display left part
  // --------------------------------------
  IsSearchingUnderlined = (CarKey!=' ');

  //cicocurser(x,y);
  grx = (x-1) * cellwidth;
  gry = (y-1) * cellheight;
  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"gr (%d,%d)",grx,gry));
  
  
  for ( i=0 ; (i<LgRight) && (mptr[i]!='\0') && (mptr[i]!='\\'); i++ ) 
    {
    if (IsSearchingUnderlined  && (mptr[i]==CarKey)) 
      {
      grxHot  = grx + g_pTabFont->Font[hFont].GrOffset.x;
      gryHot  = gry + cellheight - g_pTabFont->Font[hFont].GrOffset.y - 1;
      grcxHot = cellwidth - 2*g_pTabFont->Font[hFont].GrOffset.x;
      grcyHot = 1;
      
      if (ColHotKey<=CI_COL_CICO_WHITE)
        ColHotKey = g_pLook->ColorCicoToPalette[ColHotKey];
      filzone( grxHot, gryHot, grcxHot, grcyHot, ColHotKey);

      OldFG = TexSetFG(ColHotKey);      
      grx = PixelFontCat( grx, gry, hFont, mptr[i] );
      TexSetFG(OldFG);      

      IsSearchingUnderlined = FALSE;
      }
    else  
      grx = PixelFontCat( grx, gry, hFont, mptr[i] );
  
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"grx=%d",grx));
    }

  // --------------------------------------
  // - Display shortcut
  // --------------------------------------
  if (IsShortcut)
    {
    for( ; i<LgRight ; i++)
      grx = PixelFontCat( grx, gry, hFont, ' ' );

    grx = PixelFontCat( grx, gry, hFont, mptr[iShortcut]  );
    grx = PixelFontCat( grx, gry, hFont, mptr[iShortcut+1]);
    }
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - BDA APIs
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


// ****************************************************************************
/** 
  * BdaTxt_zPrint: (THO name) zprint - ABAL API -
    Display a text with Esc sequences

 * @parameter lg      IN
 * @parameter str     IN
 * @parameter dx      IN
 * @parameter dy      IN

 * @return CE_OK

 * @author CCDoc Administrator
 
*/
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaTxt_zPrint(WORD lg,char FAR * str,SWORD dx,SWORD dy)
{
MI_TRACE_DCL_TFN("Print");

MI_TRACE_BEGIN();
  // FRC Bug:
  // Sometimes (date displaying, for example) we are called with only 2 parameters
  // This makes a crash : I remove the trace. dx, dy are not used.
  // MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d)",dx,dy));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d",lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"var='%s'",MI_TRA_TRUNCLG(str,lg)));
  
  SysHide();
  SetChangeFlag();
  TexPrint(TexGetFont(),str,lg,CI_ESC_PROCESS|CI_ESC_F_ALL);
  SysShow();

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaTxt_zPrintXYWithSeq: (THO name) zprintxy - ABAL API -
    Display a text with Esc sequences

 * @parameter x       IN
 * @parameter y       IN
 * @parameter lg      IN
 * @parameter phrase  IN

 * @return: CE_OK

 * @author CCDoc Administrator
 
*/
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaTxt_zPrintXYWithSeq(WORD x,WORD y,WORD lg,char FAR * phrase)
{
MI_TRACE_DCL_TFN("PrintXY_Seq");
WORD  hFont;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d)",x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d",lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"var='%s'",MI_TRA_TRUNCLG(phrase,lg)));

  // Current Font 
  hFont = TexGetFont();
  MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"hFont=%d",hFont));

  SysHide();
  SetChangeFlag();

  if (  (lg!=0) 
     && ((g_pTabFont->Font[hFont].GrOffset.x) || (g_pTabFont->Font[hFont].GrOffset.y))
     )
    TexPrintXY_FillBG(hFont, x, y, phrase, lg, CI_ESC_PROCESS|CI_ESC_F_ALL);
  else
    TexPrintXY(hFont, x, y, phrase, lg, CI_ESC_PROCESS|CI_ESC_F_ALL);
  
  SysShow();

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/* BdaTxt_zPrintL : (THO name) zprintl - ABAL API - 
   Display a text underlined by a continue or not line 
   Seems used just for the content of a list.

 * @parameter lg      IN
 * @parameter phrase  IN
 * @parameter mode    IN

 * @return: CE_OK
 
 * @author CCDoc Administrator
 
*/
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaTxt_zPrintL(WORD lg,char FAR * phrase,WORD mode)
{
MI_TRACE_DCL_TFN("PrintL");
WORD  hFont;
WORD  x,y;
WORD  grx,gry;
WORD  grcx,grcy;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"state=%d",mode));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d"   ,lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"var='%s'",MI_TRA_TRUNCLG(phrase,lg)));

  // Current Font 
  hFont = TexGetFont();
  MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"hFont=%d",hFont));
  
  x = cicogetcolumn();
  y = cicogetline();
  MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"at (%d,%d)",x,y));

  SysHide();
  SetChangeFlag();

  if (  (lg!=0) 
     && ((g_pTabFont->Font[hFont].GrOffset.x) || (g_pTabFont->Font[hFont].GrOffset.y))
     )
    TexPrintXY_FillBG(hFont, x, y, phrase, lg, CI_ESC_NOCONTROL | CI_CLIP_ON );
  else
    TexPrintXY(hFont, x, y, phrase, lg, CI_ESC_NOCONTROL | CI_CLIP_ON );


if (  (lg!=0)
   && ((mode==1) || (mode==2))
   )
  {
  grx = (x-1)*cellwidth;
  gry = (y)*cellheight-1;
  grcx= lg*cellwidth;
  grcy= 1;
  filzone(grx,gry,grcx,grcy,g_pLook->List.ColorFGLine);
  }

  SysShow();

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaTxt_zPrintXYWithoutSeq: (THO name) zw_printxy - ABAL API - 
    Display a text without Esc sequence 

 * @parameter x       IN
 * @parameter y       IN
 * @parameter lg      IN
 * @parameter phrase  IN

 * @return: CE_OK

 * @author CCDoc Administrator
 
*/
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaTxt_zPrintXYWithoutSeq(WORD x,WORD y,WORD lg,char FAR * phrase)
{
MI_TRACE_DCL_TFN("PrintXY_No");
WORD  hFont;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d)",x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d"     ,lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"var='%s'"  ,MI_TRA_TRUNCLG(phrase,lg)));

// Current Font 
hFont = TexGetFont();
MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"hFont=%d",hFont));

  SysHide();
  SetChangeFlag();

  if (  (lg!=0) 
     && ((g_pTabFont->Font[hFont].GrOffset.x) || (g_pTabFont->Font[hFont].GrOffset.y))
     )
    TexPrintXY_FillBG(hFont, x, y, phrase, lg, CI_ESC_NOCONTROL);
  else
    TexPrintXY(hFont, x, y, phrase, lg, CI_ESC_NOCONTROL);
  
  SysShow();

MI_TRACE_RETURN(CE_OK);
}

