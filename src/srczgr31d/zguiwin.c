/** @pkg Staff.Fred.zGuiWin */ 
// ****************************************************************************
// * zWin.c
// * Included in GUI module
// * Display window functionnality
// ****************************************************************************


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Basic internal Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// direct from Jamis, never tested
VOID    color_frame(int atcol,int atlin,int nbcol,int nblin) 
{
  int gratcol,gratlin;
  int grnbcol,grnblin;

  gratcol = ((atcol-1)*cellwidth)+(cellwidth/2);
  gratlin = ((atlin-1)*cellwidth)+(cellheight/2);
  grnbcol = (nbcol*cellwidth);
  grnblin = (nblin*cellheight);
  LookRelief( gratcol, gratlin, grnbcol, grnblin, CI_COL_BLACK, CI_COL_TRANSPARENT, CI_COL_BLACK );
  return;
}

// direct from Jamis, never tested
VOID    help_frame(int atcol,int atlin,int nbcol,int nblin,char * titre,int lg_titre) 
{
  int gratcol,gratlin;
  int grnbcol,grnblin;

  gratcol = ((atcol-1)*cellwidth);
  gratlin = ((atlin-1)*cellheight);
  grnbcol = (nbcol*cellwidth);
  grnblin = (nblin*cellheight);
  if (!( helpskin ))
    LookRelief( (gratcol+(cellwidth/2)), (gratlin+(cellheight/2)), grnbcol, grnblin,
      CI_COL_DARK, CI_COL_NEUTRAL, CI_COL_LIGHT);
  else  LookApplySkin( gratcol, gratlin, grnbcol+cellwidth, grnblin+cellheight, helpskin, 0x01EF );
  return;
}



// ****************************************************************************
/** GuiWindowFrame: 
    Displays a window. If title bar is allowed, it is always in active look.

 * @param x         IN : Coordinate
 * @param y         IN : Coordinate
 * @param cx        IN : size
 * @param cy        IN : size
 * @param state     IN : CI_WINSTA_xxx values

 * @return nothing
 * @author FRC
 */
// * VarGlob:
// *   g_Look->Window IN
// *   cellwidth      IN
// *   cellheight     IN
// ****************************************************************************
VOID GuiWindowFrame(int atcol,int atlin,int nbcol,int nblin, WORD State) 
{
PTI_COMP_WINDOW_DESCR pWin = &g_pLook->Window;
int gratcol,gratlin;
int grnbcol,grnblin;
char *  sptr;

  gratcol = (atcol-1)*cellwidth;
  gratlin = (atlin-1)*cellheight;
  grnbcol = nbcol*cellwidth;
  grnblin = nblin*cellheight;

  // In all cases, clears the zone
  filzone( gratcol,gratlin,grnbcol,grnblin,pWin->ColorBGNormal);

  // Displays a frame if required, but not the center because of filzone
  if (State==CI_WINSTA_NOFRAME)
    return;

  sptr = (State==CI_WINSTA_FRAME_NOTITLE) ? pWin->SkinWithoutTitle.Ptr : pWin->SkinWithTitleActive.Ptr;

  if (sptr==NULL) 
    {
    // Draws the frame, then the title bar if any
    LookRelief(gratcol,gratlin,grnbcol,grnblin,pWin->ColorReliefUp,CI_COL_TRANSPARENT,pWin->ColorReliefDown);
    if (State==CI_WINSTA_FRAME_TITLE)
      filzone( gratcol+1,gratlin+1,grnbcol-2,cellheight-2,pWin->ColorBGTitleActive);
    }
  else
    {  
    // Fills the center, then apply the skin just for the frame
    LookApplySkin( gratcol, gratlin, grnbcol, grnblin, sptr, CI_SKNF_9ZONES_NOCENTER );
    }
}

// ****************************************************************************
/** GuiTitleFrame: 
    Displays a title bar.

 * @param x         IN : Coordinate
 * @param y         IN : Coordinate
 * @param cx        IN : size
 * @param cy        IN : size
 * @param IsActive  IN : Active or not inactive window

 * @return nothing
 * @author FRC
 */
// * VarGlob:
// *   g_Look->Window IN
// *   cellwidth      IN
// *   cellheight     IN
// ****************************************************************************
VOID GuiTitleFrame(int atcol,int atlin,int nbcol,int nblin, WORD IsActive) 
{
PTI_COMP_WINDOW_DESCR pWin = &g_pLook->Window;
int gratcol,gratlin;
int grnbcol,grnblin;
char *  sptr;

  gratcol = (atcol-1)*cellwidth;
  gratlin = (atlin-1)*cellheight;
  grnbcol = nbcol*cellwidth;
  grnblin = nblin*cellheight;

  sptr = (IsActive) ? pWin->SkinWithTitleActive.Ptr : pWin->SkinWithTitleInactive.Ptr;
  
  if (sptr==NULL) 
      {
      if (IsActive)
        filzone( gratcol+1,gratlin+1,grnbcol-2,cellheight-2,pWin->ColorBGTitleActive);
      else
        filzone( gratcol+1,gratlin+1,grnbcol-2,cellheight-2,pWin->ColorBGTitleInactive);
      }
    else
      LookApplySkin( gratcol, gratlin, grnbcol, grnblin, sptr, CI_SKNF_3ZONES );
}

// ****************************************************************************
/** GuiTitleButtons: 
    Displays a buttons in title bar.

 * @param x         IN : Coordinate
 * @param y         IN : Coordinate
 * @param cx        IN : size
 * @param cy        IN : size
 * @param ButState  IN : State of buttons CE_TIT_xxx values
 * @param IsActive  IN : Active or not (today, is not used)

 * @return nothing
 * @author FRC
 */
// * VarGlob:
// *   g_Look->Window IN
// *   cellwidth      IN
// *   cellheight     IN
// ****************************************************************************
VOID GuiTitleButtons(int x,int y,int cx, WORD ButState, WORD IsActive) 
{
PTI_COMP_WINDOW_DESCR pWin = &g_pLook->Window;
int xHelp, xClose;
int grxHelp, grxClose, gry;
int grcx,grcy;
PTI_MEMORY  pSkinHelp = &pWin->SkinHelp;
PTI_MEMORY  pSkinClose= &pWin->SkinClose;

  xHelp  = x + cx - 7; 
  xClose = x + cx - 4;

  grxHelp  = (xHelp -1)*cellwidth;
  grxClose = (xClose-1)*cellwidth;
  gry      = (y-1)*cellheight;
  grcx     = 3*cellwidth;
  grcy     = cellheight;

  // Displays Close button
  switch(ButState)
    {
    case CE_TIT_X:
    case CE_TIT_H_X:
    case CE_TIT_HPUSH_X:
      // Normal state
      if (pSkinClose->Ptr==NULL)
        TexPrintXY( g_pApp->hFontFixeSmall, xClose, y, " X ", 3, CI_ESC_NOCONTROL);
      else
        if (IsActive)
          LookApplySkinButton( grxClose, gry, grcx, grcy, pSkinClose->Ptr, CI_SKNF_3ZONES );
        else
          LookApplySkinButton( grxClose, gry, grcx, grcy, pSkinClose->Ptr, CI_SKNF_3ZONES_BOTTOM );
      break;

    case CE_TIT_XPUSH:
    case CE_TIT_H_XPUSH:
      // Pushed state
      if (pSkinClose->Ptr==NULL)
        TexPrintXY( g_pApp->hFontFixeSmall, xClose, y, " x ", 3, CI_ESC_NOCONTROL);
      else
        if (IsActive)
          LookApplySkinButton( grxClose, gry, grcx, grcy, pSkinClose->Ptr, CI_SKNF_3ZONES_MIDDLE );
        else
          LookApplySkinButton( grxClose, gry, grcx, grcy, pSkinClose->Ptr, CI_SKNF_3ZONES_BOTTOM );
      break;
    }

  // Displays Help button
  switch(ButState)
    {
    case CE_TIT_H_X:
    case CE_TIT_HPUSH_X:
    case CE_TIT_H_XPUSH:
      // In the current version there is no pushed state, like in zdll
      if (pSkinHelp->Ptr==NULL)
        TexPrintXY( g_pApp->hFontFixeSmall, xHelp, y, " ? ", 3, CI_ESC_NOCONTROL);
      else
        if (IsActive)
          LookApplySkinButton( grxHelp, gry, grcx, grcy, pSkinHelp->Ptr, CI_SKNF_3ZONES );
        else
          LookApplySkinButton( grxHelp, gry, grcx, grcy, pSkinHelp->Ptr, CI_SKNF_3ZONES_BOTTOM );
      break;
    }
}

// ****************************************************************************
/** GuiReliefFrame: 
    Displays an outset frame with or without a title

 * @param x         IN : Coordinate
 * @param y         IN : Coordinate
 * @param cx        IN : size
 * @param cy        IN : size
 * @param ButState  IN : State of buttons CE_TIT_xxx values
 * @param IsActive  IN : Active or not (today, is not used)

 * @return nothing
 * @author FRC
 */
// * VarGlob:
// *   g_Look->Window IN
// *   cellwidth      IN
// *   cellheight     IN
// ****************************************************************************
VOID GuiReliefFrame(int x,int y,int cx,int cy, char * titre,int lg_titre, WORD IsInset)
{
PTI_COMP_FRAME_DESCR pFrame = &g_pLook->Frame;
PTI_MEMORY           pSkin;
WORD ColUp, ColDown; 
int  grx,gry;
int  grcx,grcy;
WORD OldColors;

  grx  = (x-1)*cellwidth;
  gry  = (y-1)*cellheight;
  grcx = cx*cellwidth;
  grcy = cy*cellheight;

  pSkin = (IsInset) ? &pFrame->SkinInset : &pFrame->SkinOutset;

  if (pSkin->Ptr==NULL)
    {
    // Display draw center on a character
    grx  += cellwidth/2;
    gry  += cellheight/2;
    grcx -= cellwidth;
    grcy -= cellheight;
    ColUp   = (IsInset) ? pFrame->ColorReliefInsetUp   : pFrame->ColorReliefOutsetUp;
    ColDown = (IsInset) ? pFrame->ColorReliefInsetDown : pFrame->ColorReliefOutsetDown;
    LookRelief( grx, gry, grcx, grcy, ColUp, CI_COL_TRANSPARENT, ColDown);
    }
  else  
    LookApplySkin( grx, gry, grcx, grcy, pSkin->Ptr, CI_SKNF_9ZONES_NOCENTER );

  if (lg_titre!=0)
    {
    OldColors = TexSetFGBG( pFrame->ColorFG,pFrame->ColorBG);
    TexPrintXY(pFrame->hFont, x+(cx-lg_titre)/2, y, titre, lg_titre, CI_ESC_NOCONTROL);
    TexSetFGBG(HIBYTE(OldColors),LOBYTE(OldColors));
    }
}

VOID GuiReliefLine(int x,int y,int cx,int cy, WORD IsInset)
{
PTI_COMP_FRAME_DESCR pFrame = &g_pLook->Frame;
PTI_MEMORY           pSkin;
WORD ColUp, ColDown;
WORD SkinFlag;
int  grx,gry;
int  grcx,grcy;

  grx  = (x-1)*cellwidth;
  gry  = (y-1)*cellheight;
  grcx = cx*cellwidth;
  grcy = cy*cellheight;

  if (cx==1)
    {
    pSkin = (IsInset) ? &pFrame->SkinGrooveLineV : &pFrame->SkinRidgeLineV;
    SkinFlag = CI_SKNF_3ZONES_V;
    }
  else
    {
    pSkin = (IsInset) ? &pFrame->SkinGrooveLineH : &pFrame->SkinRidgeLineH;
    SkinFlag = CI_SKNF_3ZONES;
    }

  if (pSkin->Ptr==NULL)
    {
    // Display draw center on a character
    grx  += cellwidth/3;
    gry  += cellheight/3;
    grcx -= cellwidth*2/3;
    grcy -= cellheight*2/3;
    ColUp   = (IsInset) ? pFrame->ColorReliefInsetUp   : pFrame->ColorReliefOutsetUp;
    ColDown = (IsInset) ? pFrame->ColorReliefInsetDown : pFrame->ColorReliefOutsetDown;
    LookRelief( grx, gry, grcx, grcy, ColUp, CI_COL_TRANSPARENT, ColDown);
    }
  else  
    LookApplySkin( grx, gry, grcx, grcy, pSkin->Ptr, SkinFlag );
    
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Internal Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// ****************************************************************************
/** zWindow_Internal: internal function, used by BdaGui_zWindow
    to avoid direct API function call

 * @param State     IN : CI_WINSTA_xxx values
 * @param x         IN : Coordinate
 * @param y         IN : Coordinate
 * @param larg      IN : size
 * @param haut      IN : size
 * @param coul      IN : FG color
 * @param fond      IN : BG color
 * @param title     IN 
 * @param lg        IN 
 * @param bouts     IN

 * @author FRC
 */
// * VarGlob:
// ****************************************************************************
VOID GuiWindowInternal(WORD State, WORD x,WORD y,WORD larg,WORD haut,WORD coul,WORD fond,PTRC title,SWORD lg,WORD bouts)
{
PTI_COMP_WINDOW_DESCR pWin = &g_pLook->Window;

  // -------------------------------------------------------------------
  // - Init
  // - Look is defined by 'state' parameter
  // -------------------------------------------------------------------

  GuiWindowFrame(x,y,larg,haut,State);
  GuiWinTitleInternal(State, x,y,larg,title,lg,bouts,1);

  // -------------------------------------------------------------------
  // - Restore
  // -------------------------------------------------------------------
  TexSetFGBG( pWin->ColorFGNormal,pWin->ColorBGNormal);
  TexSetFont(pWin->hFontWindow);
}

// ****************************************************************************
/** GuiWinTitleInternal: 
    Used by BdaGui_zWinTitle to avoid trace calls. See BdaGui_zWinTitle.

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
VOID GuiWinTitleInternal(WORD State, WORD x,WORD y,WORD larg,PTRC title,WORD lg,WORD appel,WORD IsActive)
{   
PTI_COMP_WINDOW_DESCR pWin = &g_pLook->Window;
WORD        ColFG;
WORD        ColBG;
WORD        OldColors;

  // -------------------------------------------------------------------
  // - Init
  // - Look is defined by 'state' parameter
  // -------------------------------------------------------------------
  if (State!=CI_WINSTA_FRAME_TITLE)
    return;

  // --- Look
  GuiTitleFrame(x,y,larg,1,IsActive);
  
  if (IsActive)
    {
    ColFG = pWin->ColorFGTitleActive;
    ColBG = pWin->ColorBGTitleActive;
    }
  else
    {
    ColFG = pWin->ColorFGTitleInactive;
    ColBG = pWin->ColorBGTitleInactive;
    }

  OldColors = TexSetFGBG( ColFG,CI_COL_TRANSPARENT);
  GuiTitleButtons(x, y, larg, appel, IsActive);

  // -------------------------------------------------------------------
  // - Display title
  // -------------------------------------------------------------------
  TexPrintXY( pWin->hFontTitle, x+1, y, title, lg, CI_ESC_NOCONTROL );
 
  // -------------------------------------------------------------------
  // - Restore
  // -------------------------------------------------------------------
  TexSetFGBG(HIBYTE(OldColors),LOBYTE(OldColors));
}

// ****************************************************************************
/** zFrame_Internal
    Internal function, used to avoid trace calls. See BdaGui_zFrame

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
WORD zFrame_Internal( SWORD style,WORD atcol,WORD atlin,WORD nbcol,WORD nblin, WORD coul,WORD fond,WORD lg_titre,PTRC titre)
{
  switch (style) 
    {
    case CE_FRAME_LIST :
      GuiListFrame(atcol,atlin,nbcol,nblin);
      break;

    case CE_FRAME_INPUTFIELD :
      GuiInputFrame(atcol,atlin,nbcol,nblin);
      break;

    case CE_FRAME_VMENU :
      GuiVerticalMenuFrame(atcol,atlin,nbcol,nblin);
      break;

    case -4 :
      color_frame(atcol,atlin,nbcol,nblin);
      break;

    case CE_FRAME_HMENU :
      // to remove -1, it is necessary to change ABAL level
      GuiHorizontalMenuFrame(atcol,atlin,nbcol-1,nblin);
      break;

    case CE_FRAME_THIN  :    
    case CE_FRAME_BOLD  :    
    case CE_FRAME_THINBOLD  :
    case CE_FRAME_BOLDTHIN  :
      // With the trace, we see that these frames are not called, but they are
      // drawn by zPrintXY, with semi-graphical characters...
      // To avoid surprises, inset frame is assumed 
      GuiReliefFrame(atcol,atlin,nbcol,nblin,titre,lg_titre,TRUE);
      break;

    case CE_FRAME_OUTSET :
      GuiReliefFrame(atcol,atlin,nbcol,nblin,titre,lg_titre,FALSE);
      break;

    case CE_FRAME_INSET  :
      GuiReliefFrame(atcol,atlin,nbcol,nblin,titre,lg_titre,TRUE);
      break;

    case CE_FRAME_BUTTON  :
      GuiButtonFrame(atcol,atlin,nbcol,nblin);
      break;

    case CE_FRAME_TABVIEW  : 
      GuiTabviewFrame(atcol,atlin,nbcol,nblin);
      break;

    case CE_FRAME_RIDGE :
      GuiReliefLine(atcol,atlin,nbcol,nblin,FALSE);
      break;

    case CE_FRAME_GROOVE :
      GuiReliefLine(atcol,atlin,nbcol,nblin,TRUE);
      break;

    case 11 :
      help_frame(atcol,atlin,nbcol,nblin,titre,lg_titre);
      break;
}

return CE_OK;
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - BDA APIs
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------



// ****************************************************************************
/** BdaGui_zWindow: (THO name) zwindow - ABAL API - 
    Display a window with its title

 *  @param style     IN
 *  @param x         IN
 *  @param y         IN
 *  @param larg      IN
 *  @param haut      IN
 *  @param coul      IN
 *  @param fond      IN
 *  @param title     IN
 *  @param lg        IN
 *  @param bouts     IN

 * @return CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
// ANF
WORD BDA_WINAPI BdaGui_zWindow(SWORD style,WORD x,WORD y,WORD larg,WORD haut,WORD coul,WORD fond,PTRC title,SWORD lg,WORD bouts)
{
MI_TRACE_DCL_TFN("Window");
WORD  State;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d) on (%d,%d)",x,y,larg,haut));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"colors (%d,%d)",coul,fond));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"style=%d bouts=%d",style,bouts));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d",lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"title='%s'",MI_TRA_TRUNCLG(title,lg)));

  // -------------------------------------------------------------------
  // - Coherence and parameter adaptation
  // -------------------------------------------------------------------

  // This one is not available with screener 2
  if ( style < 0 ) 
    MI_TRACE_RETURN(CE_OK);
  style = (style>0 ) ? 1 : 0; 

  if (x+larg-1 > (WORD)screencols)
    larg = screencols-x;
  if (y+haut-1 > (WORD)screenlins)
    haut = screenlins-y;

  if ((haut<=0) || (larg<=0))
    MI_TRACE_RETURN(CE_OK);

  // -------------------------------------------------------------------
  // - 3 styles of window (oulesian conception heritage):
  // - style==0, lg==? --> No frame, no title bar
  // - style==1, lg==0 --> Frame, no title bar
  // - style==1, lg!=0 --> Frame, title bar
  // -------------------------------------------------------------------
  if (style==0)
    State = CI_WINSTA_NOFRAME;
  else
    State = (lg==0) ? CI_WINSTA_FRAME_NOTITLE : CI_WINSTA_FRAME_TITLE;
  MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"State=%d",State));

  SysHide();
  GuiWindowInternal(State, x, y, larg, haut, coul, fond, title, lg, bouts);
  SysShow();

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaGui_zWinTitle: (THO name) zwin_title - ABAL API - 
    Display a title in the title bar

 *  @param x         IN
 *  @param y         IN
 *  @param larg      IN
 *  @param title     IN
 *  @param lg        IN
 *  @param appel     IN
 *  @param actif     IN

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zWinTitle(WORD x,WORD y,WORD larg,PTRC title,WORD lg,WORD appel,WORD actif)
{
MI_TRACE_DCL_TFN("WinTitle");
WORD  State;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d) on %d",x,y,larg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"actif=%d bouts=%d",actif,appel));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d",lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"title='%s'",MI_TRA_TRUNCLG(title,lg)));

  // -------------------------------------------------------------------
  // - 3 styles of window (oulesian conception heritage):
  // - lg==0 --> no title bar
  // - lg!=0 --> title bar
  // -------------------------------------------------------------------
  State = (lg==0) ? CI_WINSTA_FRAME_NOTITLE : CI_WINSTA_FRAME_TITLE;
      
  SysHide();
  GuiWinTitleInternal(State, x, y, larg, title, lg, appel, actif);          
  SysShow();

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaGui_zFrame: (THO name) zframe - ABAL API
    Display a frame with a title

 *  @param style     IN
 *  @param xx1       IN
 *  @param yy1       IN
 *  @param xx2       IN
 *  @param yy2       IN
 *  @param coul      IN
 *  @param fond      IN
 *  @param lg_titre  IN
 *  @param titre     IN

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zFrame( SWORD style,WORD xx1,WORD yy1,WORD xx2,WORD yy2, WORD coul,WORD fond,WORD lg_titre,PTRC titre)
{
MI_TRACE_DCL_TFN("Frame");
int x,y;
int cx,cy;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d) to (%d,%d)",xx1,yy1,xx2,yy2));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"style=%d",style));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"colors (%d,%d)",coul,fond));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d",lg_titre));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"text='%s'",MI_TRA_TRUNCLG(titre,lg_titre)));

  xx1 = (xx1>(WORD)screencols) ? screencols : xx1;
  xx2 = (xx2>(WORD)screencols) ? screencols : xx2;
  yy1 = (yy1>(WORD)screenlins) ? screenlins : yy1;
  yy2 = (yy2>(WORD)screenlins) ? screenlins : yy2;
  
  x  = (xx2>xx1) ? xx1 : xx2;
  cx = (xx2>xx1) ? xx2-xx1+1 : xx1-xx2+1;
  y  = (yy2>yy1) ? yy1 : yy2;
  cy = (yy2>yy1) ? yy2-yy1+1 : yy1-yy2+1;

  MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"at (%d,%d) on (%d,%d)",x,y,cx,cy));

  SysHide();
  zFrame_Internal(style, x, y, cx, cy, coul, fond, lg_titre, titre);
  SysShow();

MI_TRACE_RETURN(CE_OK);
}



// ****************************************************************************
/** BdaGui_zWinClear: (THO name) zzwin_clear - ABAL API - 
    Clear a window (current window?)

 *  @param car       IN
 *  @param x         IN
 *  @param y         IN
 *  @param la        IN
 *  @param ha        IN

 * @return CE_OK

 * @author ANF
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zWinClear(PTRC car,WORD x,WORD y,WORD la,WORD ha)
{
MI_TRACE_DCL_TFN("WinClear");
int gratcol;
int gratlin;
int grnbcol;
int grnblin;

MI_TRACE_BEGIN();
  gratcol = ((x-1) * cellwidth);
  gratlin = ((y-1) * cellheight);
  grnbcol = (la * cellwidth);
  grnblin = (ha * cellheight);

  SysHide();
  filzone( gratcol, gratlin, grnbcol, grnblin, CI_COL_NEUTRAL );
  SysShow();

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaGui_zWinMove: (THO name) zzwinmove - ABAL API
    move the current window

 *  @param x         IN  : old coordinate
 *  @param y         IN  : old coordinate
 *  @param ll        IN  : size
 *  @param hh        IN  : size
 *  @param nx        IN  : new coordinate
 *  @param ny        IN  : new coordinate

 * @return CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zWinMove(SWORD x,SWORD y,SWORD ll,SWORD hh,SWORD nx,SWORD ny)
{
MI_TRACE_DCL_TFN("WinMove");
MI_TRACE_VOID(CE_OK);
SysHide();
  move_it(x,y,ll,hh,nx,ny);
SysShow();  
return CE_OK;
}

// ****************************************************************************
/** BdaGui_zWinMoveable: (THO name) zzwinmoveable - ABAL API - 
    Initiate a moving of a window, when there is a click on the title bar

 *  @param x         IN  : old coordinate
 *  @param y         IN  : old coordinate
 *  @param ll        IN  : size
 *  @param hh        IN  : size

 * @return CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
WORD BDA_WINAPI BdaGui_zWinMoveable(WORD x,WORD y,WORD ll,WORD hh)
{
MI_TRACE_DCL_TFN("WinMoveable");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaGui_zWinScroll: (THO name) zwin_scroll - ABAL API - 
    Scroll a zone

 *  @param x         IN  : old coordinate
 *  @param y         IN  : old coordinate   lie!!!
 *  @param larg      IN  : size
 *  @param haut      IN  : size       lie!!!
 *  @param dx        IN  : 
 *  @param dy        IN  : 
// *
 * @return CE_OK
// *
 * @author CCDoc Administrator
 
 */
// * VarGlob:
// ****************************************************************************
PTI_SCREENHOLDER scroll_holder=0;
PTI_SCREENHOLDER alarm_scroll_holder=0;

int GuiInitialiseScrollSystem(){
  TI_RECTANGLE screen_string;
  screen_string.x1=1;
  screen_string.x2=screencols;
  screen_string.y1=1;
  screen_string.y2=1;
  alarm_scroll_holder=allocate_screenholder(&screen_string);
  if(!alarm_scroll_holder) return CE_ERR_MEMORY;
  return CE_OK;
}
void GuiDestroyScrollHolder(){
  free_screenholder(scroll_holder);
  free_screenholder(alarm_scroll_holder);
}

WORD BDA_WINAPI BdaGui_zWinScroll(WORD x,WORD y,WORD larg,WORD haut,SWORD dx,SWORD dy)
{
 TI_RECTANGLE     r1;
 TI_POINT         co;
 TI_POINT         a;
 WORD             i;
 //FILE* out;
MI_TRACE_DCL_TFN("WinScroll");

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d) on (%d,%d)",x,y,larg,haut));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"delta (%d,%d)",dx,dy));

  SysHide();
  if(dy<0){
    r1.y1=y+dy;
  } else{
    r1.y1=y-1;
  } 
  haut=haut+dy;
  larg=larg-1;
  r1.x1=x;
  r1.x2=r1.x1+larg;
  r1.y2=r1.y1+haut;
  co.x=r1.x1;
  if(dy<0){
    co.y=r1.y1;
    r1.y1-=dy;
  }else{
    co.y=r1.y1+dy;
    r1.y2-=dy;
  }

  if(scroll_holder){//optimisation:  users like press scrollbars buttons many times
    if(is_holder_compatible(scroll_holder,&r1)){
      TI_POINT a;
      a.x=r1.x1;
      a.y=r1.y1;
      capture_screen_at(&a,scroll_holder);
    }else{
  free_screenholder(scroll_holder);
      scroll_holder=0;
    }
    }
  if(!scroll_holder){
    scroll_holder=capture_screen(&r1);
  }
  refresh_screen_at(&co,scroll_holder);;
  if(!scroll_holder){
  //on_screenholder_visual();
    if(dy<0){
    a.x=r1.x1;
    a.y=r1.y1;
      for(i=0;i<r1.y2-r1.y1;i++){
        capture_limit_screen_at(&a,alarm_scroll_holder,r1.x2-r1.x1+1);
        refresh_limit_screen_at(&co,alarm_scroll_holder,r1.x2-r1.x1+1);
        ++a.y;
        ++co.y;
      }
    }else{
      a.x=r1.x1;
    a.y=r1.y2;
    co.y+=r1.y2-r1.y1;
      for(i=0;i<r1.y2-r1.y1+1;i++){
        capture_limit_screen_at(&a,alarm_scroll_holder,r1.x2-r1.x1+1);
        refresh_limit_screen_at(&co,alarm_scroll_holder,r1.x2-r1.x1+1);
        --a.y;
        --co.y;
      }
    }
    //off_screenholder_visual();
  }
  SysShow();
MI_TRACE_RETURN(CE_OK);
    }


/*

  out = fopen( "zwscr.dat", "wt" );
  fprintf( out,"x=%u\n",x);
  fprintf( out,"y=%u\n",y);
  fprintf( out,"larg=%u\n",larg);
  fprintf( out,"haut=%u\n",haut);
  fprintf( out,"dx=%d\n",dx);
  fprintf( out,"dy=%d\n",dy);
  fclose(out);  

  if(dy<0){
    r1.y1=y+dy;
  }else{
    r1.y1=y-1;
    }
  haut=haut+dy;
  larg=larg-1;
  r1.x1=x;
  r1.x2=r1.x1+larg;
  r1.y2=r1.y1+haut;
WORD BDA_WINAPI BdaGui_zWinScroll(WORD x,WORD y,WORD larg,WORD haut,SWORD dx,SWORD dy)
{
 TI_RECTANGLE     r1;
 TI_POINT         co;
 //FILE* out;
MI_TRACE_DCL_TFN("WinScroll");

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d) on (%d,%d)",x,y,larg,haut));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"delta (%d,%d)",dx,dy));

  SysHide();
  if(dy<0){
    r1.y1=y+dy;
  } else{
    r1.y1=y-1;
  } 
  haut=haut+dy;
  larg=larg-1;
  r1.x1=x;
  r1.x2=r1.x1+larg;
  r1.y2=r1.y1+haut;
  co.x=r1.x1;
  if(dy<0){
    co.y=r1.y1;
    r1.y1-=dy;
  }else{
    co.y=r1.y1+dy;
    r1.y2-=dy;
  }
  if(scroll_holder){//optimisation:  users like press scrollbars buttons many times
    if(is_holder_compatible(scroll_holder,&r1)){
      TI_POINT a;
      a.x=r1.x1;
      a.y=r1.y1;
      capture_screen_at(&a,scroll_holder);
    }else{
      free_screenholder(scroll_holder);
      scroll_holder=0;
    }
    }
  if(!scroll_holder)scroll_holder=capture_screen(&r1);
  if(!scroll_holder){
    MessageBox( "List Eroor", MB_OK|MB_ICONEXCLAMATION );
    MI_TRACE_RETURN(CE_ERR_MEMORY);
  }
  refresh_screen_at(&co,scroll_holder);
  SysShow();
MI_TRACE_RETURN(CE_OK);
    }




  
*/

