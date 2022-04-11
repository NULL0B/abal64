/** @pkg Staff.Fred.zGuiCtrl */ 

// ****************************************************************************
// * zTexFgBg.c
// * Included in TEX module
// * Foreground / background management
// ****************************************************************************

// ****************************************************************************
/** TexSetFGBG :  

 * @parameter ColFG   IN      
 * @parameter ColBG   IN   
 * @return: Old colors HIBYTE=FG, LOBYTE=BG
 * @author FRC
*/
// * VarGlob:
// *  pApp->CurrentFG   IN/OUT      
// *  pApp->CurrentBG   IN/OUT   
// ****************************************************************************
WORD TexSetFGBG( WORD ColFG, WORD ColBG)
{
MI_TRACE_DCL_TFN("TexSetFGBG");
WORD        ret;
ret = (g_pApp->CurrentFG<<8) | (g_pApp->CurrentBG);
g_pApp->CurrentFG = ColFG;
g_pApp->CurrentBG = ColBG;
MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"(%d,%d)",ColFG,ColBG));
zcicocolour(ColFG,ColBG);
return ret;
}

// ****************************************************************************
/** TexSetFG :  

 * @parameter ColFG   IN      
 * @return: Old colorFG
 * @author FRC
*/
// * VarGlob:
// *  pApp->CurrentFG   IN/OUT   
// ****************************************************************************
WORD TexSetFG( WORD ColFG)
{
MI_TRACE_DCL_TFN("TexSetFG");
WORD        ret;
ret = g_pApp->CurrentFG;
g_pApp->CurrentFG = ColFG;
MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"(%d,%d)",ColFG,g_pApp->CurrentBG));
zcicocolour(ColFG,g_pApp->CurrentBG);
return ret;
}

// ****************************************************************************
/** TexSetBG :  

 * @parameter ColBG   IN      
 * @return: Old colorBG
 * @author FRC
*/
// * VarGlob:
// *  pApp->CurrentBG   IN/OUT   
// ****************************************************************************
WORD TexSetBG( WORD ColBG)
{
MI_TRACE_DCL_TFN("TexSetBG");
WORD        ret;
ret = g_pApp->CurrentBG;
g_pApp->CurrentBG = ColBG;
MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"(%d,%d)",g_pApp->CurrentFG,ColBG));
zcicocolour(g_pApp->CurrentFG,ColBG);
return ret;
}

// ****************************************************************************
/** TexGetFG :  

 * @parameter nothing
 * @return: colorFG
 * @author FRC
*/
// * VarGlob:
// *  pApp->CurrentFG   IN
// ****************************************************************************
WORD TexGetFG(VOID)
{
return g_pApp->CurrentFG;
}

// ****************************************************************************
/** TexGetBG :  

 * @parameter nothing
 * @return: colorBG
 * @author FRC
*/
// * VarGlob:
// *  pApp->CurrentBG   IN
// ****************************************************************************
WORD TexGetBG(VOID)
{
return g_pApp->CurrentBG;
}

// ****************************************************************************
/*  TexFillBackground
    
 * @parameter hFont   IN  font used to fill the zone
 * @parameter x       IN  coordinate
 * @parameter y       IN  coordinate
 * @parameter ColorBG IN  Color used to fill the zone
 * @parameter lg      IN  coordinate
 * @return: nothing
 * @author FRC
*/
// * VarGlob: 
// *  g_pLook->ColorCicoToPalette   IN
// ****************************************************************************
VOID TexFillBackground( WORD hFont, WORD x, WORD y, WORD ColorBG, WORD lg)
{
MI_TRACE_DCL_TFN("TexFillBg");
WORD  grx, gry;
WORD  grcx, grcy;

if (lg==0)
  return;

grx  = (x-1)*cellwidth  + g_pTabFont->Font[hFont].GrOffset.x;
gry  = (y-1)*cellheight + g_pTabFont->Font[hFont].GrOffset.y;
grcx = lg*cellwidth - 2*g_pTabFont->Font[hFont].GrOffset.x; // computed from reference font
grcy = g_pTabFont->Font[hFont].GrSize.cy    - 2*g_pTabFont->Font[hFont].GrOffset.y;

// FCH 17052001: 
// Sometimes, a print can be out of the screen, 
if ((grx+grcx)>=g_pApp->GrScreenWidth)
  grcx = g_pApp->GrScreenWidth - grx;
  
if ((gry+grcy)>=g_pApp->GrScreenHeight)
  grcy = g_pApp->GrScreenHeight - gry;  

if (ColorBG<=CI_COL_CICO_WHITE)
  ColorBG = g_pLook->ColorCicoToPalette[ColorBG];

MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"at (%d,%d) on (%d,%d) col %02X",grx,gry,grcx,grcy,ColorBG));

filzone( grx,gry,grcx,grcy,ColorBG);
}


