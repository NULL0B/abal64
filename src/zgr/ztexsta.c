/** @pkg Staff.Fred.zGuiCtrl */ 
// ****************************************************************************
// * zTexSta.c
// * Included in TEX module
// * Status line management
// ****************************************************************************


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Internal Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// ****************************************************************************
/** TexStatusFrame:

 * @param atcol  IN : 
 * @param atlin  IN : 
 * @param nbcol  IN: 
 * @param nblin  IN: 
 * @return: nothing
 * @author FCH

 */
// * VarGlob: nothing
// ****************************************************************************
VOID TexStatusFrame(int atcol,int atlin,int nbcol,int nblin) 
{
PTI_COMP_STATUS_DESCR pStatus = &g_pLook->Status;
int gratcol,gratlin;
int grnbcol,grnblin;

  gratcol = ((atcol-1)*cellwidth);
  gratlin = ((atlin-1)*cellheight);
  grnbcol = (nbcol*cellwidth);
  grnblin = (nblin*cellheight);

  if ( pStatus->SkinLine.Ptr == NULL)
    LookRelief( gratcol, gratlin, grnbcol, grnblin, pStatus->ColorReliefUp, pStatus->ColorBG, pStatus->ColorReliefDown );
  else  
    LookApplySkin( gratcol, gratlin, grnbcol, grnblin, pStatus->SkinLine.Ptr, CI_SKNF_3ZONES );
  return;
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - BDA APIs
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


// ****************************************************************************
/** BdaTxt_zStatusXY: (THO name) zstatus_xy - ABAL API - 
    Just memorize coordinates

 * @parameter x       IN
 * @parameter y       IN

 * @return: CE_OK

 * @author CCDoc Administrator
 
*/
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaTxt_zStatusXY(WORD x,WORD y)
{
MI_TRACE_DCL_TFN("StatusXY");

MI_TRACE_BEGIN();

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaTxt_zStatusDraw: (THO name) zstatus_draw - ABAL API - 
    Display a status line without text

 * @return: CE_OK

 * @author VAP
 
*/
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaTxt_zStatusDraw(void)
{
MI_TRACE_DCL_TFN("StatusDraw");

MI_TRACE_BEGIN();

  SysHide();
  SetChangeFlag();
  TexStatusFrame( 1, screenlins-1, screencols, 1);

  SysShow();

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaTxt_zStatus: (THO name) zstatus - ABAL API
    Display a status line and text
    
 * @parameter text      IN
 * @parameter lg        IN

 * @return: CE_OK

 * @author VAP
 
*/
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaTxt_zStatus(char FAR * text,WORD lg)
{
MI_TRACE_DCL_TFN("Status");
WORD        OldColors;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d",lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"text='%s'",MI_TRA_TRUNCLG(text,lg)));

  SysHide();
  SetChangeFlag();
  TexStatusFrame( 1, screenlins-1, screencols, 1);

  OldColors = TexSetFGBG(g_pLook->Status.ColorFG,CI_COL_TRANSPARENT);
  TexPrintXY(g_pLook->Status.hFont, 1, screenlins-1, text, lg, CI_ESC_PROCESS|CI_ESC_F_FG|CI_ESC_F_BG);
  TexSetFGBG(HIBYTE(OldColors),LOBYTE(OldColors));

  SysShow();

MI_TRACE_RETURN(CE_OK);
}

