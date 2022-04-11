/** @pkg Staff.Fred.zGuiInMe */ 
// ****************************************************************************
// * zInpMenu.c
// * Included in GUI module
// * Input fields and items of menu Controls functionnalities
// ****************************************************************************

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Basic internal Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


VOID GuiVerticalMenuFrame(int atcol,int atlin,int nbcol,int nblin) 
{
PTI_COMP_MENU_DESCR pMenu = &g_pLook->Menu;
int gratcol,gratlin;
int grnbcol,grnblin;

  gratcol = ((atcol-1)*cellwidth);
  gratlin = ((atlin-1)*cellheight);
  grnbcol = (nbcol*cellwidth);
  grnblin = (nblin*cellheight);

  if ( pMenu->SkinFrameV.Ptr == NULL)
    LookRelief( gratcol, gratlin, grnbcol, grnblin, pMenu->ColorReliefUp, pMenu->ColorBGNormal, pMenu->ColorReliefDown );
  else  
    LookApplySkin( gratcol, gratlin, grnbcol, grnblin, pMenu->SkinFrameV.Ptr, CI_SKNF_9ZONES );
  return;
}

VOID GuiHorizontalMenuFrame(int atcol,int atlin,int nbcol,int nblin) 
{
PTI_COMP_MENU_DESCR pMenu = &g_pLook->Menu;
int gratcol,gratlin;
int grnbcol,grnblin;

  gratcol = ((atcol-1)*cellwidth);
  gratlin = ((atlin-1)*cellheight);
  grnbcol = (nbcol*cellwidth);
  grnblin = (nblin*cellheight);

  if ( pMenu->SkinFrameH.Ptr == NULL)
    LookRelief( gratcol, gratlin, grnbcol, grnblin, pMenu->ColorReliefUp, pMenu->ColorBGNormal, pMenu->ColorReliefDown );
  else
    LookApplySkin( gratcol, gratlin, grnbcol, grnblin, pMenu->SkinFrameH.Ptr, CI_SKNF_3ZONES );
  return;
}

VOID GuiMenuLine(int atcol,int atlin,int nbcol) 
{
PTI_COMP_MENU_DESCR pMenu = &g_pLook->Menu;
int gratcol,gratlin;
int grnbcol,grnblin;

  gratcol = ((atcol-1)*cellwidth);
  gratlin = ((atlin-1)*cellheight);
  grnbcol = (nbcol*cellwidth);
  grnblin = cellheight;
  LookApplySkin( gratcol, gratlin, grnbcol, grnblin, pMenu->SkinLine.Ptr, CI_SKNF_3ZONES );
  return;
}

VOID GuiMenuChild(int atcol,int atlin, WORD SkinFlag ) 
{
PTI_COMP_MENU_DESCR pMenu = &g_pLook->Menu;
int gratcol,gratlin;
int grnbcol,grnblin;

  gratcol = ((atcol-1)*cellwidth);
  gratlin = ((atlin-1)*cellheight);
  grnbcol = cellwidth;
  grnblin = cellheight;
  LookApplySkinButton( gratcol, gratlin, grnbcol, grnblin, pMenu->SkinChild.Ptr, SkinFlag );
  return;
}

VOID GuiInputFrame(int x,int y,int cx,int cy)
{
PTI_COMP_INPUT_DESCR pInput = &g_pLook->Input;
PTI_MEMORY  pSkin;
WORD        SkinFlag;
int grx,gry;
int grcx,grcy;

  grx = (x-1)*cellwidth;
  gry = (y-1)*cellheight;
  grcx= cx*cellwidth;
  grcy= cy*cellheight;

  pSkin    = (cy==1) ? &pInput->SkinFrameH : &pInput->SkinFrameBigNormal;
  SkinFlag = (cy==1) ? CI_SKNF_3ZONES : CI_SKNF_9ZONES;

  if ( pSkin->Ptr == NULL)
    LookRelief( grx,gry, grcx,grcy, pInput->ColorReliefUp, pInput->ColorBGNormal, pInput->ColorReliefDown );
  else
    LookApplySkin( grx, gry, grcx, grcy, pSkin->Ptr, SkinFlag );
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - BDA APIs
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


// ****************************************************************************
/** BdaGui_zPrintVar: (THO name) zbprintvar - ABAL API
    Displays an input zone field

 * @param state     IN : CE_FIELDLOOK_xxx values
 * @param x         IN : Coordinate
 * @param y         IN : Coordinate
 * @param var       IN : Value terminated by '/FE'

 * @return CE_OK
 * @author CCDoc Administrator
 
 */

// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaGui_zPrintVar(WORD state,WORD x,WORD y,char FAR * var)
{
MI_TRACE_DCL_TFN("zPrintVar");
  
WORD lg;
PTI_COMP_INPUT_DESCR pInput = &g_pLook->Input;
WORD        ColFG;
WORD        ColBG;
PTI_MEMORY  pSkin;
WORD        SkinFlag;
WORD        OldColors;
WORD  grx,gry;
WORD  grcx,grcy;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"state=%d at (%d,%d)",state,x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"var='%s'",MI_TRA_TRUNC(var)));

  // -------------------------------------------------------------------
  // - Init
  // - Look is defined by 'state' parameter
  // -------------------------------------------------------------------

  // --- Find length of the value
  for (lg=0; *(var+lg) != '\xFE'; lg++);
  MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"l=%d",lg));

  // --- Look identification
  pSkin = &pInput->SkinFrameH;

  switch(state)
    {
    case CE_FIELDLOOK_NORMAL:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Normal"));
      ColFG    = pInput->ColorFGNormal;
      ColBG    = pInput->ColorBGNormal;
      SkinFlag = CI_SKNF_3ZONES;
      break;

    case CE_FIELDLOOK_FOCUSED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Selected"));
      ColFG    = pInput->ColorFGSelected;
      //ColBG   = pInput->ColorBGSelected;
      ColBG    = pInput->ColorBGNormal;
      SkinFlag = CI_SKNF_3ZONES_MIDDLE;
      break;

    case CE_FIELDLOOK_GRAYED:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Disabled"));
      // FRC: 'var' is always void in grayed...
      // we must grayed the existing zone, instead of display a new value
      // or best solution, change ABAL level to send the text in 'var' parameter
      ColFG    = pInput->ColorFGDisabled;
      ColBG    = pInput->ColorBGDisabled;
      SkinFlag = CI_SKNF_3ZONES_BOTTOM;
      break;

    case CE_FIELDLOOK_HIDDEN:
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Hidden"));
      ColFG = pInput->ColorFGHidden;
      ColBG = pInput->ColorBGHidden;
      break;

    default:
      MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"state unknown"));
      break;
    }
    

  // -------------------------------------------------------------------
  // - Compute
  // -------------------------------------------------------------------
  SysHide();

  OldColors = TexSetFGBG( ColFG,CI_COL_TRANSPARENT);

  // --- Set the background
  grx  = (x-1)*cellwidth;
  gry  = (y-1)*cellheight;
  grcx = lg*cellwidth;
  grcy = cellheight;

  if ( state == CE_FIELDLOOK_HIDDEN )
    filzone( grx, gry, grcx, grcy, ColBG);
  else
    {
    if ( pSkin->Ptr == NULL)
      LookRelief( grx,gry, grcx,grcy, pInput->ColorReliefUp, ColBG, pInput->ColorReliefDown );
    else  
      LookApplySkin( grx, gry, grcx, grcy, pSkin->Ptr, SkinFlag );

    if (state==CE_FIELDLOOK_FOCUSED)
      TexFillBackground(pInput->hFont,x,y,pInput->ColorBGSelected,lg);

    TexPrintXY(pInput->hFont,x,y,var,lg,CI_ESC_NOCONTROL);
    }

  SysShow();

  // -------------------------------------------------------------------
  // - Restore
  // -------------------------------------------------------------------
  TexSetFGBG(HIBYTE(OldColors),LOBYTE(OldColors));

MI_TRACE_RETURN(CE_OK);
}


WORD SpaceKiller(char FAR * phrase,WORD lg){
  int i;
  //for(i=0;(i<lg) ;i++){
  for(i=lg;--i>=0;){
    //zbprintxy_deputy(2+i,(ddcounter)+2,1,phrase+i);
    if((phrase[i])!=' ') return i+1;
  }
  return 0;
}
// ****************************************************************************
/** BdaGui_zPrintItem: (THO name) zprintitem - ABAL API
    Displays an item of menu.

 * @param x         IN : Coordinate
 * @param y         IN : Coordinate
 * @param lg        IN : 
 * @param phrase    IN : Composed by name and shortcut separated by '\'
 * @param car       IN : Character to underline
 * @param coul1     IN : unused
 * @param coul2     IN : unused
 * @param fils      IN : Exist or not a child menu (to display an arrow)

 * @return CE_OK

 * @author CCDoc Administrator
 
 */

// * VarGlob:
// ****************************************************************************

EXAWORD BDA_API BdaGui_zPrintItem(WORD x,WORD y,WORD lg,char FAR * phrase,char FAR * car,WORD coul1,WORD coul2,WORD child)
{
MI_TRACE_DCL_TFN("PrintItem");
PTI_COMP_MENU_DESCR pMenu = &g_pLook->Menu;
WORD  SkinChildFlag;
WORD  ColFG;
WORD  ColBG;
WORD  OldColors;
TI_RECTANGLE menu_coo;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d)",x,y));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"colors (%d,%d)",coul1,coul2));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"key='%c' child=%d",car[0],child));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d",lg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"text='%s'",MI_TRA_TRUNCLG(phrase,lg)));

  // -------------------------------------------------------------------
  // - Init
  // - This is an Oulesianism: state is defined by color parameters
  // - to define the correct colors.
  // -------------------------------------------------------------------

  // --- Look
  if (coul2==16)
    {
    MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Selected"));
    ColFG = pMenu->ColorFGSelected;
    ColBG = pMenu->ColorBGSelected;
    SkinChildFlag = CI_SKNF_L2C1;
    }
  else 
    if (coul2==8)
      {
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Disabled"));
      ColFG = pMenu->ColorFGDisabled;
      ColBG = pMenu->ColorBGNormal;
      SkinChildFlag = CI_SKNF_L3C1;
      }
    else
      {
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Normal"));
      ColFG = pMenu->ColorFGNormal;
      ColBG = pMenu->ColorBGNormal;
      SkinChildFlag = CI_SKNF_L1C1;
      }

  // -------------------------------------------------------------------
  // - Compute
  // -------------------------------------------------------------------
  SysHide();

  // Background
  // lg-1 to avoid display out of horizontal menu
  TexFillBackground(pMenu->hFont,x,y,ColBG,lg-1); 
  OldColors = TexSetFGBG( ColFG,CI_COL_TRANSPARENT);

  // Content
  if ( (phrase[0]=='\xC4') && (pMenu->SkinLine.Ptr!=NULL))
    GuiMenuLine(x,y,lg);
  else
    TexPrintMenuItem( pMenu->hFont, x, y, phrase, lg, car, pMenu->ColorFGHotKey, child );

  // Arrow for child menu
  // aligned at lg-1
  if (child)
    {
    if (pMenu->SkinChild.Ptr == NULL)
      TexPrintXY(pMenu->hFont, x+lg-1, y, ">", 1, CI_ESC_NOCONTROL);
    else
      GuiMenuChild(x+lg-1,y,SkinChildFlag);
    }

  //VAP ADDONS
  GuiGetGrButtonRectangle(&menu_coo, x, y,2,CE_BUTTONTYPE_SMALL);
  DrawAssociatedImage( &menu_coo,phrase+1,1,SpaceKiller(phrase+1,lg));

  SysShow();


  // -------------------------------------------------------------------
  // - Restore
  // -------------------------------------------------------------------
  TexSetFGBG(HIBYTE(OldColors),LOBYTE(OldColors));

MI_TRACE_RETURN(CE_OK);
}

