// ****************************************************************************
// * zIntCtx.h
// * Constants, types,... for internal context
// ****************************************************************************
#ifndef ZINTCTX_H
#define ZINTCTX_H

// *******************************************************
// * CONSTANTS
// *******************************************************

#define CI_MAXFONT              32
#define CI_MAXPATH              512

#define CI_ZINI_FILENAME        "z.ini"
#define CI_ZINI_MAXLINE         512
#define CI_ZINI_ZLIBPATH_NAME   "ZLIBPATH"
#define CI_ZINI_LOOKPATH_NAME   "ZLOOKPATH"
#define CI_ZINI_SCRSV_TIME      "ZTIMESCRSV"
#define CI_ZINI_GRMODE          "ZGRMODE"

#define CI_ZSKIN_FILENAME       "zskin.skn\0------PRLSKIN"
#define CI_ZPALETTE_FILENAME    "standard.rgb\0---PRLPAL"
#define CI_ZFIXREF_FILENAME     "zfixref.fmf\0----PRLFIXREF"
#define CI_ZFIXSMALL_FILENAME   "zfixsml.fmf\0----PRLFIXSML"
#define CI_ZPROREF_FILENAME     "zproref.fmf\0----PRLPROREF"
#define CI_ZPROSMALL_FILENAME   "zprosml.fmf\0----PRLPROSML"
#define CI_ZRESCUE_FILENAME     "font8025.bmf\0---PRLRESC"

#if defined (BDA_TWIN16)
#define CI_DEFAULT_RUNTIME_PATH "is\\zlibrary\\\0-------------------------------------PRLZLIB"
#define CI_SYSTEMFONT_PATH      "is\\fonts\\\0----------------------------------------PRLFONT"
#define CI_SYSTEMIMAGE_PATH     "is\\images\\\0---------------------------------------PRLIMG"
#else
#define CI_DEFAULT_RUNTIME_PATH "/opt/prologue/zlibrary/\0----------------------------PRLZLIB"
#define CI_SYSTEMFONT_PATH      "/opt/prologue/fonts/\0-------------------------------PRLFONT"
#define CI_SYSTEMIMAGE_PATH     "/opt/prologue/images/\0------------------------------PRLIMG"
#endif

#define CI_ZSCRSV_FILENAME      "prlimg\0----PRLSCRSV"

// ---------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------
// Component Descriptors
// ---------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------

// ----------------------------------------
// Descriptor of component Menu
// ----------------------------------------
typedef struct
  {
  // Skins (Ptr==NULL if no skin)
  TI_MEMORY     SkinFrameH;       // Frame for horizontal menu
  TI_MEMORY     SkinFrameV;       // Frame for vertical   menu
  TI_MEMORY     SkinChild;        // Arrow for child menu
  TI_MEMORY     SkinLine;         // Separator line
  // Font for items
  WORD          hFont;
  // Background colors
  WORD          ColorBGNormal;
  WORD          ColorBGSelected;
  // Foreground colors
  WORD          ColorFGNormal;
  WORD          ColorFGSelected;
  WORD          ColorFGDisabled;
  WORD          ColorFGHotKey;       
  // Relief colors
  WORD          ColorReliefUp;
  WORD          ColorReliefDown;
  } TI_COMP_MENU_DESCR, FAR PTR PTI_COMP_MENU_DESCR;

// ----------------------------------------
// Descriptor of component Input
// ----------------------------------------
typedef struct
  {
  // Skins (Ptr==NULL if no skin)
  TI_MEMORY     SkinFrameH;
  TI_MEMORY     SkinFrameBigNormal; // seems to be required by zFrame ???
  // Font
  WORD          hFont;
  // Background colors
  WORD          ColorBGNormal;
  WORD          ColorBGSelected;
  WORD          ColorBGDisabled;
  WORD          ColorBGHidden;
  // Foreground colors
  WORD          ColorFGNormal;
  WORD          ColorFGSelected;
  WORD          ColorFGDisabled;
  WORD          ColorFGHidden;       
  // Relief colors
  WORD          ColorReliefUp;
  WORD          ColorReliefDown;
  } TI_COMP_INPUT_DESCR, FAR PTR PTI_COMP_INPUT_DESCR;

// ----------------------------------------
// Descriptor of component Window
// ----------------------------------------
typedef struct
  {
  // Skins (Ptr==NULL if no skin)
  TI_MEMORY     SkinWithTitleActive;
  TI_MEMORY     SkinWithTitleInactive;
  TI_MEMORY     SkinWithoutTitle;
  TI_MEMORY     SkinClose;
  TI_MEMORY     SkinHelp;
  // Font
  WORD          hFontWindow;
  WORD          hFontTitle;
  // Background colors
  WORD          ColorBGNormal;
  WORD          ColorBGTitleActive;
  WORD          ColorBGTitleInactive;
  // Foreground colors
  WORD          ColorFGNormal;
  WORD          ColorFGTitleActive;
  WORD          ColorFGTitleInactive;
  // Relief colors
  WORD          ColorReliefUp;
  WORD          ColorReliefDown;
  } TI_COMP_WINDOW_DESCR, FAR PTR PTI_COMP_WINDOW_DESCR;

// ----------------------------------------
// Descriptor of component Window
// ----------------------------------------
typedef struct
  {
  // Skins (Ptr==NULL if no skin)
  TI_MEMORY     SkinOutset;
  TI_MEMORY     SkinInset;
  TI_MEMORY     SkinRidgeLineV;
  TI_MEMORY     SkinGrooveLineV;
  TI_MEMORY     SkinRidgeLineH;
  TI_MEMORY     SkinGrooveLineH;
  // Font
  WORD          hFont;
  // Background colors
  WORD          ColorBG;
  WORD          ColorFG;
  // Relief colors
  WORD          ColorReliefOutsetUp;
  WORD          ColorReliefOutsetDown;
  WORD          ColorReliefInsetUp;
  WORD          ColorReliefInsetDown;
  } TI_COMP_FRAME_DESCR, FAR PTR PTI_COMP_FRAME_DESCR;

// ----------------------------------------
// Descriptor of component Radio
// ----------------------------------------
typedef struct
  {
  // Skins (Ptr==NULL if no skin)
  TI_MEMORY     SkinOff;
  TI_MEMORY     SkinOn;
  // Background colors
  WORD          ColorBGNormal;
  WORD          ColorBGSelected;
  WORD          ColorBGDisabled;
  WORD          ColorBGHidden;
  // Foreground colors
  WORD          ColorFGNormal;
  WORD          ColorFGSelected;
  WORD          ColorFGDisabled;
  WORD          ColorFGHidden;       
  // Relief colors
  WORD          ColorReliefUp;
  WORD          ColorReliefDown;
  } TI_COMP_RADIO_DESCR, FAR PTR PTI_COMP_RADIO_DESCR;

// ----------------------------------------
// Descriptor of component Check
// ----------------------------------------
typedef struct
  {
  // Skins (Ptr==NULL if no skin)
  TI_MEMORY     SkinOff;
  TI_MEMORY     SkinOn;
  TI_MEMORY     SkinOn2;
  // Background colors
  WORD          ColorBGNormal;
  WORD          ColorBGSelected;
  WORD          ColorBGDisabled;
  WORD          ColorBGHidden;
  // Foreground colors
  WORD          ColorFGNormal;
  WORD          ColorFGSelected;
  WORD          ColorFGDisabled;
  WORD          ColorFGHidden;       
  // Relief colors
  WORD          ColorReliefUp;
  WORD          ColorReliefDown;
  } TI_COMP_CHECK_DESCR, FAR PTR PTI_COMP_CHECK_DESCR;

// ----------------------------------------
// Descriptor of component ComboBox button
// ----------------------------------------
typedef struct
  {
  // Skins (Ptr==NULL if no skin)
  TI_MEMORY     SkinButton;
  // Background colors
  WORD          ColorBGButtonNormal;
  WORD          ColorBGButtonDisabled;
  WORD          ColorBGButtonHidden;
  // Foreground colors
  WORD          ColorFGButtonNormal;
  WORD          ColorFGButtonDisabled;
  // Relief colors
  WORD          ColorReliefButtonUp;
  WORD          ColorReliefButtonDown;
  } TI_COMP_COMBO_DESCR, FAR PTR PTI_COMP_COMBO_DESCR;

// ----------------------------------------
// Descriptor of component List
// ----------------------------------------
typedef struct
  {
  // Skins (Ptr==NULL if no skin)
  TI_MEMORY     SkinFrame;
  TI_MEMORY     SkinTitle;
  // Font
  WORD          hFontTitle;
  // Background colors
  WORD          ColorBGNormal;
  WORD          ColorBGTitle;
  // Foreground colors
  WORD          ColorFGTitle;
  WORD          ColorFGLine;
  // Relief colors
  WORD          ColorReliefFrameUp;
  WORD          ColorReliefFrameDown;
  WORD          ColorReliefTitleUp;
  WORD          ColorReliefTitleDown;
  } TI_COMP_LIST_DESCR, FAR PTR PTI_COMP_LIST_DESCR;

// ----------------------------------------
// Descriptor of component ScrollBar
// ----------------------------------------
typedef struct
  {
  // Skins (Ptr==NULL if no skin)
  TI_MEMORY     SkinLeftBut;
  TI_MEMORY     SkinRightBut;
  TI_MEMORY     SkinUpBut;
  TI_MEMORY     SkinDownBut;
  TI_MEMORY     SkinPgUpBut;
  TI_MEMORY     SkinPgDownBut;
  TI_MEMORY     SkinTopBut;
  TI_MEMORY     SkinBottomBut;
  TI_MEMORY     SkinHSliderNormal;
  TI_MEMORY     SkinVSliderNormal;
  TI_MEMORY     SkinHSliderDisabled;
  TI_MEMORY     SkinVSliderDisabled;
  // Background colors
  WORD          ColorBGHidden;
  WORD          ColorBGButNormal;
  WORD          ColorBGButDisabled;
  WORD          ColorBGSliderNormal;
  WORD          ColorBGSliderDisabled;
  // Foreground colors
  WORD          ColorFGButNormal;
  WORD          ColorFGButDisabled;
  WORD          ColorFGSliderNormal;
  WORD          ColorFGSliderDisabled;
  // Relief colors
  WORD          ColorReliefSliderUp;
  WORD          ColorReliefSliderDown;
  WORD          ColorReliefButUp;
  WORD          ColorReliefButDown;
  WORD          ColorReliefUp;
  WORD          ColorReliefDown;
  } TI_COMP_SCROLL_DESCR, FAR PTR PTI_COMP_SCROLL_DESCR;

// ----------------------------------------
// Descriptor of component Status line
// ----------------------------------------
typedef struct
  {
  // Skins (Ptr==NULL if no skin)
  TI_MEMORY     SkinLine;
  // Font
  WORD          hFont;
  // Background colors
  WORD          ColorBG;
  // Foreground colors
  WORD          ColorFG;
  // Relief colors
  WORD          ColorReliefUp;
  WORD          ColorReliefDown;
  } TI_COMP_STATUS_DESCR, FAR PTR PTI_COMP_STATUS_DESCR;

// ----------------------------------------
// Descriptor of component Button
// ----------------------------------------
typedef struct
  {
  // Skins (Ptr==NULL if no skin)
  TI_MEMORY     SkinSmall;
  TI_MEMORY     SkinButNormal;
  TI_MEMORY     SkinButSelected;
  TI_MEMORY     SkinButDisabled;
  TI_MEMORY     SkinButPushed;
  TI_MEMORY     SkinBut2Normal;
  TI_MEMORY     SkinBut2Selected;
  TI_MEMORY     SkinBut2Disabled;
  TI_MEMORY     SkinBut2Pushed;
  TI_MEMORY     SkinTabviewFrame;
  TI_MEMORY     SkinHTabview;
  TI_MEMORY     SkinVTabview;
  // Font
  WORD          hFontSmall;
  WORD          hFont;
  // Background colors
  WORD          ColorBGButNormal;
  WORD          ColorBGButDisabled;
  WORD          ColorBGButSelected;
  WORD          ColorBGTabFront;
  WORD          ColorBGTabBack;
  WORD          ColorBGTabDisabled;
  WORD          ColorBGTabSelected;
  WORD          ColorBGHidden;
  // Foreground colors
  WORD          ColorFGButNormal;
  WORD          ColorFGButSelected;
  WORD          ColorFGButDisabled;
  WORD          ColorFGTabFront;
  WORD          ColorFGTabBack;       
  WORD          ColorFGTabSelected;
  WORD          ColorFGTabDisabled;       
  // Relief colors
  WORD          ColorReliefUp;
  WORD          ColorReliefDown;
  } TI_COMP_BUTTON_DESCR, FAR PTR PTI_COMP_BUTTON_DESCR;

// ----------------------------------------
// Descriptor of component Variator
// ----------------------------------------
typedef struct
  {
  // Skins (Ptr==NULL if no skin)
  TI_MEMORY     SkinVar;
  // Background colors
  WORD          ColorBGNormal;
  WORD          ColorBGDisabled;
  WORD          ColorBGHidden;
  // Foreground colors
  WORD          ColorFGNormal;
  WORD          ColorFGDisabled;
  WORD          ColorFGHidden;
  // Relief colors
  WORD          ColorReliefUp;
  WORD          ColorReliefDown;
  } TI_COMP_VAR_DESCR, FAR PTR PTI_COMP_VAR_DESCR;

// ----------------------------------------
// Descriptor of component Caret
// ----------------------------------------
typedef struct
  {
  // Not a skin, just a memzone to store the caret
  WORD          IsInitialised;
  TI_MEMORY     FgCaret;
  TI_MEMORY     BgCaret;
  TI_POINT      GrPos;
  TI_SIZE       GrSize;
  WORD          IsVisible;
  } TI_COMP_CARET_DESCR, FAR PTR PTI_COMP_CARET_DESCR;

// ----------------------------------------
// Descriptor of component Draw
// ----------------------------------------
typedef struct
  {
  // Not a skin, just a memo of drawing parameters
  WORD          IsInitialised;
  WORD          PointColor;
  WORD          PenType;
  WORD          PenColor;
  WORD          PenSize;
  WORD          BrushType;
  WORD          BrushColor;
  } TI_COMP_DRAW_DESCR, FAR PTR PTI_COMP_DRAW_DESCR;


// ---------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------
// Others Descriptors
// ---------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------

// ----------------------------------------
// Descriptor of fonts
// ----------------------------------------
typedef struct
  {
  WORD          IsDefined;
  TI_MEMORY     Storage;
  TI_SIZE       GrSize;
  TI_POINT      GrOffset;
  } TI_FONT_DESCR, FAR PTR PTI_FONT_DESCR;


// ---------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------
// Tables of descriptors
// ---------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------

// ----------------------------------------
// Fonts management
// ----------------------------------------
typedef struct
  {
  WORD           FirstItemForUserFont;
  TI_FONT_DESCR  Font[CI_MAXFONT];      // (THO ufont)  loaded fonts 
  } TI_TABFONT, FAR PTR PTI_TABFONT;

// ---------------------------------------------------------------------------------------
// Memo current context
// ---------------------------------------------------------------------------------------

// ----------------------------------------
// Print management
// ----------------------------------------
typedef struct
  {
  TI_POINT TxPrintPos;                    // (THO X,Y)    Current coordinate for prints
  TI_POINT TxStatusPos;                   // (THO nothing for x,YSTA) Status line position
  WORD  ColorFG;                          // (THO COUL)   Foreground color
  WORD  ColorBG;                          // (THO FOND)   Background color
  } TI_MEMO_PRINT, FAR PTR PTI_MEMO_PRINT;

// ----------------------------------------
// State of the caret
// ----------------------------------------
typedef struct 
  {
  TI_POINT TxCaretPos;                    // (THO CARET_X, CARET_Y) Current coodinate of the caret
  WORD  IsShow;                           // (THO SHOWCARET)Visible caret or not
  } TI_MEMO_CARET, FAR PTR PTI_MEMO_CARET;

// ----------------------------------------
// State of the mouse
// ----------------------------------------
typedef struct 
  {
  TI_POINT TxPos;                         // (THO MOUSE_X, MOUSE_Y)
  TI_POINT GrPos;                         // (THO MOUSE_GRX, MOUSE_GRY)
  WORD  lBut;                             // (THO MOUSE_B)  State of the button
  WORD  mBut;                             // (THO ?)        State of the button
  WORD  rBut;                             // (THO ?)        State of the button
  } TI_MEMO_MOUSE, FAR PTR PTI_MEMO_MOUSE;
// Notes : This structure must be changed if necessary. The mouse management is strange
// in the THO code...

// ----------------------------------------
// Descriptor of the application
// ----------------------------------------
typedef struct
  {
  WORD      hConsole; 
  WORD      hFontRescue;
  WORD      hFontFixeRef;
  WORD      hFontFixeSmall;
  WORD      hFontPropRef;
  WORD      hFontPropSmall;
  WORD      hCurrentFont;
  WORD      CurrentFG;
  WORD      CurrentBG;
  WORD      GrScreenWidth;
  WORD      GrScreenHeight;
  SWORD     CptAlloc;
  SWORD     BitmapCounter;
  CHAR      PathLook[CI_MAXPATH];
  CHAR      PathZlib[CI_MAXPATH];
  CHAR      PathFont[CI_MAXPATH];
  TI_RECTANGLE  rectToShow;
  // add Jamie's variables (palette, font,...) To do later
  } TI_MEMO_APPLI, FAR PTR PTI_MEMO_APPLI;

// ----------------------------------------
// Table of components
// ----------------------------------------
typedef struct
  {
  BYTE                 ColorCicoToPalette[15];
  TI_COMP_MENU_DESCR   Menu;
  TI_COMP_INPUT_DESCR  Input;
  TI_COMP_WINDOW_DESCR Window;
  TI_COMP_FRAME_DESCR  Frame;
  TI_COMP_RADIO_DESCR  Radio;
  TI_COMP_CHECK_DESCR  Check;
  TI_COMP_COMBO_DESCR  Combo;
  TI_COMP_LIST_DESCR   List;
  TI_COMP_SCROLL_DESCR Scroll;
  TI_COMP_STATUS_DESCR Status;
  TI_COMP_BUTTON_DESCR Button;
  TI_COMP_VAR_DESCR    Variator;
  TI_COMP_CARET_DESCR  Caret;
  TI_COMP_DRAW_DESCR   Draw;
  } TI_MEMO_LOOK, FAR PTR PTI_MEMO_LOOK;
  
// ---------------------------------------------------------------------------------------
// Application context
// ---------------------------------------------------------------------------------------

typedef struct{
	SWORD FrameCreated;			//Any Frame..windows+controlbars+menu(?) not MsgBoxes!!!
	SWORD FrameDeleted;			//the same
	SWORD NumBGAllocated;		// pure statistic: NumBGAllocated=FrameCreated-1(for zero window)?
	SWORD NumBGLiberated;		// NumBGAllocated==NumBGLiberated
	SWORD NumWDAllocated;		// NumWDAllocated<=NumBGAllocated
	SWORD NumWDLiberated;
	SWORD FramesKilledByZadapt;	// if 1 then OK else something wrong in Abal prog or in Zlibrary ? :)
}TI_PUPO,FAR PTR PTI_PUPO;


typedef struct{
	SWORD BmpLoaded;
	SWORD BmpKilled;	//BmpKilled=BmpLoaded+BmpExported
	SWORD BmpExported;
	SWORD BmpKilledByZadapt;
}TI_BMP,FAR PTR PTI_BMP;
// All members associated to one application
typedef struct
  {
  TI_TABFONT      TabFont;
  TI_MEMO_APPLI   App;
  TI_RECTANGLE    Clip;
  TI_MEMO_PRINT   Print;
  TI_MEMO_CARET   Caret;
  TI_MEMO_LOOK    Look;
  TI_PUPO		  	PuPo;
  TI_BMP		  		Bmp;	
  } TI_APP_CONTEXT, FAR PTR PTI_APP_CONTEXT;

#endif

