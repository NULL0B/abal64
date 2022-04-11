/** @pkg Staff.Fred.zLooComp */ 
// ****************************************************************************
// * zLooComp.c
// * Included in zLook module
// * Component management
// ****************************************************************************


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Internal Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// ****************************************************************************
/** zInitComponentMenu: 
    Initialisation of the look for menus

 * @param nothing
 * @return: CE_OK  
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->Menu OUT
// ****************************************************************************
WORD zInitComponentMenu(VOID)
{
PTI_COMP_MENU_DESCR p = &g_pLook->Menu;

  ToolsInitMemory(&p->SkinFrameH);
  ToolsInitMemory(&p->SkinFrameV);
  ToolsInitMemory(&p->SkinChild);
  ToolsInitMemory(&p->SkinLine);

  p->hFont = g_pApp->hFontFixeSmall;

  p->ColorBGNormal    = CI_COL_NEUTRAL;
  p->ColorBGSelected  = CI_COL_DARK;

  p->ColorFGNormal    = CI_COL_WHITE;
  p->ColorFGSelected  = CI_COL_WHITE;
  p->ColorFGDisabled  = CI_COL_GRAYED;
  p->ColorFGHotKey    = CI_COL_FOCUS;       

  p->ColorReliefUp    = CI_COL_LIGHT;
  p->ColorReliefDown  = CI_COL_DARK;

  return CE_OK;
}

VOID zEndComponentMenu(VOID)
{
PTI_COMP_MENU_DESCR p = &g_pLook->Menu;
  ToolsReinitMemory(&p->SkinFrameH);
  ToolsReinitMemory(&p->SkinFrameV);
  ToolsReinitMemory(&p->SkinChild);
  ToolsReinitMemory(&p->SkinLine);
}

// ****************************************************************************
/** zInitComponentInput: 
    Initialisation of the look for Inputs

 * @param nothing
 * @return: CE_OK  
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->Input OUT
// ****************************************************************************
WORD zInitComponentInput(VOID)
{
PTI_COMP_INPUT_DESCR p = &g_pLook->Input;

  ToolsInitMemory(&p->SkinFrameH);
  ToolsInitMemory(&p->SkinFrameBigNormal);

  p->hFont = g_pApp->hFontFixeSmall;

  p->ColorBGNormal    = CI_COL_WHITE;
  p->ColorBGSelected  = CI_COL_DARK;
  p->ColorBGDisabled  = CI_COL_NEUTRAL;
  p->ColorBGHidden    = CI_COL_NEUTRAL;

  p->ColorFGNormal    = CI_COL_BLACK;
  p->ColorFGSelected  = CI_COL_WHITE;
  p->ColorFGDisabled  = CI_COL_GRAYED;
  p->ColorFGHidden    = CI_COL_NEUTRAL;

  p->ColorReliefUp    = CI_COL_DARK;
  p->ColorReliefDown  = CI_COL_LIGHT;

  return CE_OK;
}

VOID zEndComponentInput(VOID)
{
PTI_COMP_INPUT_DESCR p = &g_pLook->Input;
  ToolsReinitMemory(&p->SkinFrameH);
  ToolsReinitMemory(&p->SkinFrameBigNormal);
}

// ****************************************************************************
/** zInitComponentWindow: 
    Initialisation of the look for Windows

 * @param nothing
 * @return: CE_OK  
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->Input OUT
// ****************************************************************************
WORD zInitComponentWindow(VOID)
{
PTI_COMP_WINDOW_DESCR p = &g_pLook->Window;

  ToolsInitMemory(&p->SkinWithTitleActive);
  ToolsInitMemory(&p->SkinWithTitleInactive);
  ToolsInitMemory(&p->SkinWithoutTitle);
  ToolsInitMemory(&p->SkinClose);
  ToolsInitMemory(&p->SkinHelp);

  p->hFontWindow = g_pApp->hFontFixeRef; // Will be the Default font
  p->hFontTitle  = g_pApp->hFontPropSmall;

  p->ColorBGNormal        = CI_COL_NEUTRAL;
  p->ColorBGTitleActive   = CI_COL_TITLE_BK_ACTIVE;
  p->ColorBGTitleInactive = CI_COL_NEUTRAL_LOW;

  p->ColorFGNormal        = CI_COL_BLACK;
  p->ColorFGTitleActive   = CI_COL_TITLE_FG_ACTIVE;
  p->ColorFGTitleInactive = CI_COL_GRAYED;

  p->ColorReliefUp    = CI_COL_LIGHT;
  p->ColorReliefDown  = CI_COL_DARK;

  return CE_OK;
}

VOID zEndComponentWindow(VOID)
{
PTI_COMP_WINDOW_DESCR p = &g_pLook->Window;

  ToolsReinitMemory(&p->SkinWithTitleActive);
  ToolsReinitMemory(&p->SkinWithTitleInactive);
  ToolsReinitMemory(&p->SkinWithoutTitle);
  ToolsReinitMemory(&p->SkinClose);
  ToolsReinitMemory(&p->SkinHelp);
}

// ****************************************************************************
/** zInitComponentFrame: 
    Initialisation of the look for Windows

 * @param nothing
 * @return: CE_OK  
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->Input OUT
// ****************************************************************************
WORD zInitComponentFrame(VOID)
{
PTI_COMP_FRAME_DESCR p = &g_pLook->Frame;

  ToolsReinitMemory(&p->SkinOutset);
  ToolsReinitMemory(&p->SkinInset);
  ToolsReinitMemory(&p->SkinRidgeLineV);
  ToolsReinitMemory(&p->SkinGrooveLineV);
  ToolsReinitMemory(&p->SkinRidgeLineH);
  ToolsReinitMemory(&p->SkinGrooveLineH);

  p->hFont = g_pApp->hFontPropRef;

  p->ColorBG = CI_COL_NEUTRAL;
  p->ColorFG = CI_COL_BLACK;

  p->ColorReliefOutsetUp    = CI_COL_LIGHT;
  p->ColorReliefOutsetDown  = CI_COL_DARK;
  p->ColorReliefInsetUp     = CI_COL_DARK;
  p->ColorReliefInsetDown   = CI_COL_LIGHT;

  return CE_OK;
}

VOID zEndComponentFrame(VOID)
{
PTI_COMP_FRAME_DESCR p = &g_pLook->Frame;

  ToolsReinitMemory(&p->SkinOutset);
  ToolsReinitMemory(&p->SkinInset);
  ToolsReinitMemory(&p->SkinRidgeLineV);
  ToolsReinitMemory(&p->SkinGrooveLineV);
  ToolsReinitMemory(&p->SkinRidgeLineH);
  ToolsReinitMemory(&p->SkinGrooveLineH);
}

// ****************************************************************************
/** zInitComponentCheck: 
    Initialisation of the look for Inputs

 * @param nothing
 * @return: CE_OK  
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->Input OUT
// ****************************************************************************
WORD zInitComponentCheck(VOID)
{
PTI_COMP_CHECK_DESCR p = &g_pLook->Check;

  ToolsInitMemory(&p->SkinOff);
  ToolsInitMemory(&p->SkinOn);
  ToolsInitMemory(&p->SkinOn2);

  p->ColorBGNormal    = CI_COL_WHITE;
  p->ColorBGSelected  = CI_COL_WHITE;
  p->ColorBGDisabled  = CI_COL_NEUTRAL;
  p->ColorBGHidden    = CI_COL_NEUTRAL;

  p->ColorFGNormal    = CI_COL_BLACK;
  p->ColorFGSelected  = CI_COL_FOCUS;
  p->ColorFGDisabled  = CI_COL_GRAYED;
  p->ColorFGHidden    = CI_COL_NEUTRAL;

  p->ColorReliefUp    = CI_COL_LIGHT;
  p->ColorReliefDown  = CI_COL_DARK;

  return CE_OK;
}

VOID zEndComponentCheck(VOID)
{
PTI_COMP_CHECK_DESCR p = &g_pLook->Check;
  ToolsReinitMemory(&p->SkinOff);
  ToolsReinitMemory(&p->SkinOn);
  ToolsReinitMemory(&p->SkinOn2);
}

// ****************************************************************************
/** zInitComponentRadio: 
    Initialisation of the look for Inputs

 * @param nothing
 * @return: CE_OK  
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->Input OUT
// ****************************************************************************
WORD zInitComponentRadio(VOID)
{
PTI_COMP_RADIO_DESCR p = &g_pLook->Radio;

  ToolsInitMemory(&p->SkinOff);
  ToolsInitMemory(&p->SkinOn);

  p->ColorBGNormal    = CI_COL_WHITE;
  p->ColorBGSelected  = CI_COL_WHITE;
  p->ColorBGDisabled  = CI_COL_NEUTRAL;
  p->ColorBGHidden    = CI_COL_NEUTRAL;

  p->ColorFGNormal    = CI_COL_BLACK;
  p->ColorFGSelected  = CI_COL_FOCUS;
  p->ColorFGDisabled  = CI_COL_GRAYED;
  p->ColorFGHidden    = CI_COL_NEUTRAL;

  p->ColorReliefUp    = CI_COL_DARK;
  p->ColorReliefDown  = CI_COL_LIGHT;

  return CE_OK;
}

VOID zEndComponentRadio(VOID)
{
PTI_COMP_RADIO_DESCR p = &g_pLook->Radio;
  ToolsReinitMemory(&p->SkinOff);
  ToolsReinitMemory(&p->SkinOn);
}

// ****************************************************************************
/** zInitComponentCombo: 

 * @param nothing
 * @return: CE_OK  
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->Input OUT
// ****************************************************************************
WORD zInitComponentCombo(VOID)
{
PTI_COMP_COMBO_DESCR p = &g_pLook->Combo;

  ToolsInitMemory(&p->SkinButton);

  p->ColorBGButtonNormal    = CI_COL_NEUTRAL;
  p->ColorBGButtonDisabled  = CI_COL_NEUTRAL;
  p->ColorBGButtonHidden    = CI_COL_NEUTRAL;

  p->ColorFGButtonNormal    = CI_COL_DARK;
  p->ColorFGButtonDisabled  = CI_COL_GRAYED;

  p->ColorReliefButtonUp    = CI_COL_LIGHT;
  p->ColorReliefButtonDown  = CI_COL_DARK;

  return CE_OK;
}

VOID zEndComponentCombo(VOID)
{
PTI_COMP_COMBO_DESCR p = &g_pLook->Combo;
  ToolsReinitMemory(&p->SkinButton);
}

// ****************************************************************************
/** zInitComponentList: 

 * @param nothing
 * @return: CE_OK  
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->Input OUT
// ****************************************************************************
WORD zInitComponentList(VOID)
{
PTI_COMP_LIST_DESCR p = &g_pLook->List;

  ToolsInitMemory(&p->SkinFrame);
  ToolsInitMemory(&p->SkinTitle);

  p->hFontTitle       = g_pApp->hFontFixeSmall;

  p->ColorBGNormal    = CI_COL_WHITE;
  p->ColorFGLine      = CI_COL_DARK;

  p->ColorReliefFrameUp    = CI_COL_DARK;
  p->ColorReliefFrameDown  = CI_COL_LIGHT;

  p->ColorBGTitle          = CI_COL_NEUTRAL;
  p->ColorFGTitle          = CI_COL_WHITE;
  p->ColorReliefTitleUp    = CI_COL_LIGHT;
  p->ColorReliefTitleDown  = CI_COL_DARK;

  return CE_OK;
}

VOID zEndComponentList(VOID)
{
PTI_COMP_LIST_DESCR p = &g_pLook->List;
  ToolsReinitMemory(&p->SkinFrame);
  ToolsReinitMemory(&p->SkinTitle);
}

// ****************************************************************************
/** zInitComponentScroll: 

 * @param nothing
 * @return: CE_OK  
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->Input OUT
// ****************************************************************************
WORD zInitComponentScroll(VOID)
{
PTI_COMP_SCROLL_DESCR p = &g_pLook->Scroll;

  ToolsInitMemory(&p->SkinLeftBut);
  ToolsInitMemory(&p->SkinRightBut);
  ToolsInitMemory(&p->SkinUpBut);
  ToolsInitMemory(&p->SkinDownBut);
  ToolsInitMemory(&p->SkinPgUpBut);
  ToolsInitMemory(&p->SkinPgDownBut);
  ToolsInitMemory(&p->SkinTopBut);
  ToolsInitMemory(&p->SkinBottomBut);
  ToolsInitMemory(&p->SkinHSliderNormal);
  ToolsInitMemory(&p->SkinVSliderNormal);
  ToolsInitMemory(&p->SkinHSliderDisabled);
  ToolsInitMemory(&p->SkinVSliderDisabled);

  // common
  p->ColorBGHidden        = CI_COL_NEUTRAL;

  // buttons
  p->ColorBGButNormal     = CI_COL_NEUTRAL;
  p->ColorBGButDisabled   = CI_COL_NEUTRAL;

  p->ColorFGButNormal     = CI_COL_DARK;
  p->ColorFGButDisabled   = CI_COL_GRAYED;

  // bar and slider
  p->ColorBGSliderNormal  = CI_COL_NEUTRAL_LOW;
  p->ColorBGSliderDisabled= CI_COL_NEUTRAL;

  p->ColorFGSliderNormal  = CI_COL_NEUTRAL;
  p->ColorFGSliderDisabled= CI_COL_NEUTRAL;

  // Relief colors
  p->ColorReliefUp        = CI_COL_DARK;
  p->ColorReliefDown      = CI_COL_LIGHT;
  p->ColorReliefButUp     = CI_COL_LIGHT;
  p->ColorReliefButDown   = CI_COL_DARK;
  p->ColorReliefSliderUp  = CI_COL_LIGHT;
  p->ColorReliefSliderDown= CI_COL_DARK;

  return CE_OK;
}

VOID zEndComponentScroll(VOID)
{
PTI_COMP_SCROLL_DESCR p = &g_pLook->Scroll;

  ToolsReinitMemory(&p->SkinLeftBut);
  ToolsReinitMemory(&p->SkinRightBut);
  ToolsReinitMemory(&p->SkinUpBut);
  ToolsReinitMemory(&p->SkinDownBut);
  ToolsReinitMemory(&p->SkinPgUpBut);
  ToolsReinitMemory(&p->SkinPgDownBut);
  ToolsReinitMemory(&p->SkinTopBut);
  ToolsReinitMemory(&p->SkinBottomBut);
  ToolsReinitMemory(&p->SkinHSliderNormal);
  ToolsReinitMemory(&p->SkinVSliderNormal);
  ToolsReinitMemory(&p->SkinHSliderDisabled);
  ToolsReinitMemory(&p->SkinVSliderDisabled);
}

// ****************************************************************************
/** zInitComponentStatus: 

 * @param nothing
 * @return: CE_OK  
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->Input OUT
// ****************************************************************************
WORD zInitComponentStatus(VOID)
{
PTI_COMP_STATUS_DESCR p = &g_pLook->Status;

  ToolsInitMemory(&p->SkinLine);

  p->hFont = g_pApp->hFontPropSmall;

  p->ColorBG          = CI_COL_NEUTRAL;
  p->ColorFG          = CI_COL_WHITE;

  p->ColorReliefUp    = CI_COL_LIGHT;
  p->ColorReliefDown  = CI_COL_DARK;

  return CE_OK;
}

VOID zEndComponentStatus(VOID)
{
PTI_COMP_STATUS_DESCR p = &g_pLook->Status;
  ToolsReinitMemory(&p->SkinLine);
}

// ****************************************************************************
/** zInitComponentButton: 

 * @param nothing
 * @return: CE_OK  
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->Button OUT
// ****************************************************************************
WORD zInitComponentButton(VOID)
{
PTI_COMP_BUTTON_DESCR p = &g_pLook->Button;

  ToolsInitMemory(&p->SkinSmall);
  ToolsInitMemory(&p->SkinButNormal);
  ToolsInitMemory(&p->SkinButSelected);
  ToolsInitMemory(&p->SkinButDisabled);
  ToolsInitMemory(&p->SkinButPushed);
  ToolsInitMemory(&p->SkinBut2Normal);
  ToolsInitMemory(&p->SkinBut2Selected);
  ToolsInitMemory(&p->SkinBut2Disabled);
  ToolsInitMemory(&p->SkinBut2Pushed);
  ToolsInitMemory(&p->SkinTabviewFrame);
  ToolsInitMemory(&p->SkinHTabview);
  ToolsInitMemory(&p->SkinVTabview);

  p->hFont      = g_pApp->hFontFixeRef;
  p->hFontSmall = g_pApp->hFontFixeSmall;

  p->ColorBGButNormal   = CI_COL_NEUTRAL;
  p->ColorBGButDisabled = CI_COL_NEUTRAL;
  p->ColorBGButSelected = CI_COL_NEUTRAL_LOW;

  p->ColorFGButNormal   = CI_COL_BLACK;
  p->ColorFGButSelected = CI_COL_BLACK;
  p->ColorFGButDisabled = CI_COL_GRAYED;

  p->ColorBGTabFront    = CI_COL_NEUTRAL;
  p->ColorBGTabBack     = CI_COL_NEUTRAL;
  p->ColorBGTabDisabled = CI_COL_NEUTRAL;
  p->ColorBGTabSelected = CI_COL_NEUTRAL_LOW;

  p->ColorFGTabFront    = CI_COL_BLACK;
  p->ColorFGTabBack     = CI_COL_DARK_LOW;
  p->ColorFGTabSelected = CI_COL_BLACK;
  p->ColorFGTabDisabled = CI_COL_GRAYED;

  p->ColorBGHidden      = CI_COL_NEUTRAL;

  p->ColorReliefUp      = CI_COL_LIGHT;
  p->ColorReliefDown    = CI_COL_DARK;

  return CE_OK;
}

VOID zEndComponentButton(VOID)
{
PTI_COMP_BUTTON_DESCR p = &g_pLook->Button;
  ToolsReinitMemory(&p->SkinSmall);
  ToolsReinitMemory(&p->SkinButNormal);
  ToolsReinitMemory(&p->SkinButSelected);
  ToolsReinitMemory(&p->SkinButDisabled);
  ToolsReinitMemory(&p->SkinButPushed);
  ToolsReinitMemory(&p->SkinBut2Normal);
  ToolsReinitMemory(&p->SkinBut2Selected);
  ToolsReinitMemory(&p->SkinBut2Disabled);
  ToolsReinitMemory(&p->SkinBut2Pushed);
  ToolsReinitMemory(&p->SkinTabviewFrame);
  ToolsReinitMemory(&p->SkinHTabview);
  ToolsReinitMemory(&p->SkinVTabview);
}

// ****************************************************************************
/** zInitComponentVariator: 

 * @param nothing
 * @return: CE_OK  
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->Variator OUT
// ****************************************************************************
WORD zInitComponentVariator(VOID)
{
PTI_COMP_VAR_DESCR p = &g_pLook->Variator;

  ToolsInitMemory(&p->SkinVar);

  p->ColorBGNormal   = CI_COL_NEUTRAL;
  p->ColorBGDisabled = CI_COL_NEUTRAL;
  p->ColorBGHidden   = CI_COL_NEUTRAL;

  p->ColorFGNormal   = CI_COL_DARK;
  p->ColorFGDisabled = CI_COL_GRAYED;
  p->ColorFGHidden   = CI_COL_NEUTRAL;

  p->ColorReliefUp   = CI_COL_LIGHT;
  p->ColorReliefDown = CI_COL_DARK;

  return CE_OK;
}

VOID zEndComponentVariator(VOID)
{
PTI_COMP_VAR_DESCR p = &g_pLook->Variator;
  ToolsReinitMemory(&p->SkinVar);
}

// ****************************************************************************
/** zInitComponentCaret: 

 * @param nothing
 * @return: CE_OK  
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->Caret OUT
// ****************************************************************************
WORD zInitComponentCaret(VOID)
{
PTI_COMP_CARET_DESCR p = &g_pLook->Caret;
WORD x,y;
WORD xOffset, yOffset;
WORD yBottom; 


#if defined (BDA_UNIX) || defined(BDA_WIN32)
// FCH27032006 Prise en compte mode palette/truecolor
int  pixelformat = get_pixel_format();
int  pixelsize   = get_pixel_size();
#else
int  pixelformat = 1;
int  pixelsize   = sizeof(char);
#endif

  ToolsInitMemory(&p->FgCaret);
  ToolsInitMemory(&p->BgCaret);

  p->IsInitialised = FALSE;
  p->IsVisible     = FALSE;
  p->GrPos.x   = 0;
  p->GrPos.y   = 0;

  xOffset = g_pTabFont->Font[g_pApp->hFontFixeSmall].GrOffset.x;
  yOffset = g_pTabFont->Font[g_pApp->hFontFixeSmall].GrOffset.y;
  yBottom = g_pTabFont->Font[g_pApp->hFontFixeSmall].GrSize.cy - yOffset ;

  p->GrSize.cx = xOffset+2;
  p->GrSize.cy = cellheight;

  if (  (ToolsAllocMemory(&p->FgCaret, p->GrSize.cx * p->GrSize.cy * pixelsize ))
     && (ToolsAllocMemory(&p->BgCaret, p->GrSize.cx * p->GrSize.cy * pixelsize ))
     )
    {
    // Empty carets 
 	 if (pixelformat)
		{
		for ( x=0 ; x<p->FgCaret.Size ; x++)
	 		{
			p->BgCaret.Ptr[x]=CI_COL_TRANSPARENT;
			p->FgCaret.Ptr[x]=CI_COL_TRANSPARENT;
			}
		}
    else
		{
		for ( x=0 ; x<p->FgCaret.Size ; x++)
			{
			p->BgCaret.Ptr[x] = 0;
			p->FgCaret.Ptr[x] = 0;
			}
      }

    // Draw caret
 	 if (pixelformat)
		{
      for ( y=yOffset ; y<yBottom ; y++)
        p->FgCaret.Ptr[y*p->GrSize.cx+xOffset+(y%2)] = CI_COL_BLACK;
		}
    else
		{
#if defined (BDA_UNIX) || defined(BDA_WIN32)
      for ( y=yOffset ; y<yBottom ; y++)
		  put_palette_pixel( &p->FgCaret.Ptr[ (y*p->GrSize.cx+xOffset+(y%2)) * pixelsize ], CI_COL_BLACK);
#endif
		}

    p->IsInitialised = TRUE;
    }

  return CE_OK;
}

VOID zEndComponentCaret(VOID)
{
PTI_COMP_CARET_DESCR p = &g_pLook->Caret;
  ToolsReinitMemory(&p->FgCaret);
  ToolsReinitMemory(&p->BgCaret);
}

// ****************************************************************************
/** zInitComponentDraw: 

 * @param nothing
 * @return: CE_OK  
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->Draw OUT
// ****************************************************************************
WORD zInitComponentDraw(VOID)
{
PTI_COMP_DRAW_DESCR p = &g_pLook->Draw;

  p->PointColor = CI_COL_BLACK;
  p->PenType    = CI_PEN_SOLID;
  p->PenColor   = CI_COL_BLACK;
  p->PenSize    = 1;
  p->BrushType  = CI_BRUSH_SOLID;
  p->BrushColor = CI_COL_NEUTRAL_LOW;
  
  p->IsInitialised = TRUE;
  return CE_OK;
}

VOID zEndComponentDraw(VOID)
{
//PTI_COMP_DRAW_DESCR p = &g_pLook->Draw;
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - External Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// ****************************************************************************
/** zInitAllComponents: 

 * @param nothing
 * @return: CE_OK  CE_ERR
 * @author FRC
 */
// * VarGlob: 
// *  g_pApp->PathLook            IN
// ****************************************************************************
WORD LookInitAllComponents(VOID)
{
CHAR  PathSkin[CI_MAXPATH];

  zInitComponentMenu();
  zInitComponentInput();
  zInitComponentWindow();
  zInitComponentFrame();
  zInitComponentRadio();
  zInitComponentCheck();
  zInitComponentCombo();  
  zInitComponentList();  
  zInitComponentScroll();  
  zInitComponentButton();  
  zInitComponentStatus();  
  zInitComponentVariator();  
  zInitComponentCaret();  
  zInitComponentDraw();  

  if (ToolsFindFile(PathSkin,CI_ZSKIN_FILENAME, g_pApp->PathLook)==CE_ERR)
	 LookLoadSkinByImages();
  else
	 LookLoadSkin( PathSkin );

  return CE_OK;
}

VOID LookEndAllComponents(VOID)
{
  zEndComponentMenu();    
  zEndComponentInput();    
  zEndComponentWindow();    
  zEndComponentFrame();    
  zEndComponentRadio();    
  zEndComponentCheck();    
  zEndComponentCombo();    
  zEndComponentList();    
  zEndComponentScroll();    
  zEndComponentStatus();    
  zEndComponentButton();    
  zEndComponentVariator();    
  zEndComponentCaret();    
  zEndComponentDraw();    
}



