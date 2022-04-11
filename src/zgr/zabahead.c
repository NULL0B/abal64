// ****************************************************************************
// * zAbaHead.c
// * Included in ABAL module
// * Header of the BDA
// ****************************************************************************

#if defined(BDA_UNIX) || defined(BDA_TWIN)
void  _cfltcvt()  {   return;   }
void  _cropzeros()  {   return;   }
long  _aFftol() { return(0L); }
#endif

// This defines the total number of functions in the Z library
// -----------------------------------------------------------
#define _Z_FUNCTION_COUNT 	122


/* ---------------------- */
/* Test */
/* ---------------------- */
WORD BdaAba_Test1(WORD toto)
{
MI_TRACE_DCL_TFN("Tst1");

if (toto)
  MI_TRACE_RETURN(1);
else
  MI_TRACE_RETURN(0);
}

/* ---------------------- */
/* Library identification */
/* ---------------------- */
VOID  banniere(VOID)
{
MI_TRACE_DCL_TFN("banniere");

  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"'%s'",Banner_GetVersionID(MI_TRA_LINE,'2') ));
  Banner_DisplayBanner();
}

/* ------------------ */
/* DLL initialisation */
/* ------------------ */
VOID FAR PTR InitRelais()
{ 
MI_TRACE_DCL_TFN("InitRelais");

  MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"'%s'",Banner_GetVersionID(MI_TRA_LINE,Banner_GetVersionStatus())));

#ifdef	BDA_TWIN16
  cico_redirection(rt_init);
#endif

#ifdef BDA_UNIX
	rt_init->ordinaire.signature = BDA_ZGR;
#else
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_ORDINAIRE;
#endif

#ifdef BDA_WIN32
  g_hwnd    = (HWND)rt_init->ordinaire.hWnd;
#endif

  s_desrt.banniere = (VOID (FAR PTR)()) banniere;
  s_desrt.fin = (VOID (FAR PTR)()) 0L;

  s_desrt.nombre = _Z_FUNCTION_COUNT;
  s_desrt.reserve = (VOID FAR PTR) 0L;

#ifdef	BDA_UNIX
	initialise_access_controller();
#endif

  s_desrt.fonction[0]   = (WORD (FAR PTR)())BdaSys_zInit;  
  s_desrt.fonction[1]   = (WORD (FAR PTR)())BdaGui_zInitMouse; 
  s_desrt.fonction[2]   = (WORD (FAR PTR)())BdaGui_zShowMouse; 
  s_desrt.fonction[3]   = (WORD (FAR PTR)())BdaGui_zHideMouse; 
  s_desrt.fonction[4]   = (WORD (FAR PTR)())BdaSys_EmptyFunction; 
  s_desrt.fonction[5]   = (WORD (FAR PTR)())BdaGui_zStatusMouse; 
  s_desrt.fonction[6]   = (WORD (FAR PTR)())BdaSys_EmptyFunction; 
  s_desrt.fonction[7]   = (WORD (FAR PTR)())BdaSys_EmptyFunction; //zzzshadow, just in Z.XP, never called in ABAL files 
  s_desrt.fonction[8]   = (WORD (FAR PTR)())BdaSys_zRleCompress; 
  s_desrt.fonction[9]   = (WORD (FAR PTR)())BdaSys_zRleDecompress;  
  s_desrt.fonction[10]  = (WORD (FAR PTR)())BdaSys_EmptyFunction;  
  s_desrt.fonction[11]  = (WORD (FAR PTR)())BdaSys_EmptyFunction;  
  s_desrt.fonction[12]  = (WORD (FAR PTR)())BdaSys_EmptyFunction;  
  s_desrt.fonction[13]  = (WORD (FAR PTR)())BdaSys_EmptyFunction;  
  s_desrt.fonction[14]  = (WORD (FAR PTR)())BdaTxt_zPrint;  
  s_desrt.fonction[15]  = (WORD (FAR PTR)())BdaTxt_zPrintXYWithSeq;  
  s_desrt.fonction[16]  = (WORD (FAR PTR)())BdaSys_zHide;  
  s_desrt.fonction[17]  = (WORD (FAR PTR)())BdaSys_zShow;  
  s_desrt.fonction[18]  = (WORD (FAR PTR)())BdaSys_zWait;  
  s_desrt.fonction[19]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //dllzwanal, just in Z.XP, called in ABAL files for ASFUN
  s_desrt.fonction[20]  = (WORD (FAR PTR)())BdaSys_zEnd;  
  s_desrt.fonction[21]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //dllzz_adrs, just in Z.XP, never called in ABAL files
  s_desrt.fonction[22]  = (WORD (FAR PTR)())BdaSys_zPush; 
  s_desrt.fonction[23]  = (WORD (FAR PTR)())BdaSys_zPop;  
  s_desrt.fonction[24]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; // zzmove, just in Z.XP, never called in ABAL files
  s_desrt.fonction[25]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //zshadow, just in Z.XP, never called in ABAL files
  s_desrt.fonction[26]  = (WORD (FAR PTR)())BdaGui_zWinScroll;

  #ifdef OLD_FASHIONED_WITH_ZAC
  s_desrt.fonction[27]  = (WORD (FAR PTR)())BdaZac_init;  
  s_desrt.fonction[28]  = (WORD (FAR PTR)())BdaZac_open;  
  s_desrt.fonction[29]  = (WORD (FAR PTR)())BdaZac_nextline;  
  s_desrt.fonction[30]  = (WORD (FAR PTR)())BdaZac_prevline;  
  s_desrt.fonction[31]  = (WORD (FAR PTR)())BdaZac_firstline; 
  s_desrt.fonction[32]  = (WORD (FAR PTR)())BdaZac_lastline;  
  s_desrt.fonction[33]  = (WORD (FAR PTR)())BdaZac_close; 
  s_desrt.fonction[34]  = (WORD (FAR PTR)())BdaZac_create;  
  s_desrt.fonction[35]  = (WORD (FAR PTR)())BdaZac_write; 
  #else
  s_desrt.fonction[27]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //BdaZac_init;  
  s_desrt.fonction[28]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //BdaZac_open;  
  s_desrt.fonction[29]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //BdaZac_nextline;  
  s_desrt.fonction[30]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //BdaZac_prevline;  
  s_desrt.fonction[31]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //BdaZac_firstline; 
  s_desrt.fonction[32]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //BdaZac_lastline;  
  s_desrt.fonction[33]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //BdaZac_close; 
  s_desrt.fonction[34]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //BdaZac_create;  
  s_desrt.fonction[35]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //BdaZac_write;
  #endif
  
  s_desrt.fonction[36]  = (WORD (FAR PTR)())BdaGui_zPrintVar; 
  s_desrt.fonction[37]  = (WORD (FAR PTR)())BdaGui_zPrintItem; 
  s_desrt.fonction[38]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //zprintran, just in Z.XP, never called in ABAL files
  s_desrt.fonction[39]  = (WORD (FAR PTR)())BdaSys_zTab2Seq; 
  s_desrt.fonction[40]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //zstring_cpt, just in Z.XP, never called in ABAL files
  s_desrt.fonction[41]  = (WORD (FAR PTR)())BdaSys_zFind; 
  
  #ifdef OLD_FASHIONED_WITH_ZAC
  s_desrt.fonction[42]  = (WORD (FAR PTR)())BdaZac_read;  
  #else
  s_desrt.fonction[42]  = (WORD (FAR PTR)())BdaSys_EmptyFunction; //BdaZac_read;  
  #endif

  s_desrt.fonction[43]  = (WORD (FAR PTR)())BdaSys_zIndex;
  s_desrt.fonction[44]  = (WORD (FAR PTR)())BdaSys_zOem2Ansi; 
  s_desrt.fonction[45]  = (WORD (FAR PTR)())BdaSys_zAnsi2Oem; 
  s_desrt.fonction[46]  = (WORD (FAR PTR)())BdaSys_zWinHelp;  
  s_desrt.fonction[47]  = (WORD (FAR PTR)())BdaSys_EmptyFunction;  
  s_desrt.fonction[48]  = (WORD (FAR PTR)())BdaSys_EmptyFunction;  
  s_desrt.fonction[49]  = (WORD (FAR PTR)())BdaSys_EmptyFunction;  
  s_desrt.fonction[50]  = (WORD (FAR PTR)())BdaGui_zMesVal;  
  s_desrt.fonction[51]  = (WORD (FAR PTR)())BdaGui_zMesErr; 
  s_desrt.fonction[52]  = (WORD (FAR PTR)())BdaGui_zMesYesNo;  
  s_desrt.fonction[53]  = (WORD (FAR PTR)())BdaGui_zMesYesNoCancel;  
  s_desrt.fonction[54]  = (WORD (FAR PTR)())BdaGui_zButton;  
  s_desrt.fonction[55]  = (WORD (FAR PTR)())BdaGui_zSmallButton;  
  s_desrt.fonction[56]  = (WORD (FAR PTR)())BdaGui_zF1Button; 
  s_desrt.fonction[57]  = (WORD (FAR PTR)())BdaGui_zListVertScrollBar;  
  s_desrt.fonction[58]  = (WORD (FAR PTR)())BdaGui_zLisFicScrollBar; 
  s_desrt.fonction[59]  = (WORD (FAR PTR)())BdaGui_zFrame; 
  s_desrt.fonction[60]  = (WORD (FAR PTR)())BdaGui_zWindow;  
  s_desrt.fonction[61]  = (WORD (FAR PTR)())BdaTxt_zFont; 
  s_desrt.fonction[62]  = (WORD (FAR PTR)())BdaGui_zCheck; 
  s_desrt.fonction[63]  = (WORD (FAR PTR)())BdaGui_zRadio; 
  s_desrt.fonction[64]  = (WORD (FAR PTR)())BdaTxt_zStatusXY; 
  s_desrt.fonction[65]  = (WORD (FAR PTR)())BdaTxt_zStatusDraw; 
  s_desrt.fonction[66]  = (WORD (FAR PTR)())BdaTxt_zStatus;  
  s_desrt.fonction[67]  = (WORD (FAR PTR)())BdaGui_zMouseCursor;  
  s_desrt.fonction[68]  = (WORD (FAR PTR)())BdaGui_zAskCursor;  
  s_desrt.fonction[69]  = (WORD (FAR PTR)())BdaImg_zButtonBitmap;  
  s_desrt.fonction[70]  = (WORD (FAR PTR)())BdaImg_zBitmap; 
  s_desrt.fonction[71]  = (WORD (FAR PTR)())BdaSys_zWinImpl; 
  s_desrt.fonction[72]  = (WORD (FAR PTR)())BdaImg_zDllBitmapLoad;  
  s_desrt.fonction[73]  = (WORD (FAR PTR)())BdaImg_zDllBitmapFree;  
  s_desrt.fonction[74]  = (WORD (FAR PTR)())BdaGui_zListHoriScrollBar;  
  s_desrt.fonction[75]  = (WORD (FAR PTR)())BdaSys_zAppliAlone;  
  s_desrt.fonction[76]  = (WORD (FAR PTR)())BdaSys_zChDir;  
  s_desrt.fonction[77]  = (WORD (FAR PTR)())BdaImg_zBmpLoad;  
  s_desrt.fonction[78]  = (WORD (FAR PTR)())BdaImg_zBmpFree;  
  s_desrt.fonction[79]  = (WORD (FAR PTR)())BdaImg_zButtonBmp;  
  s_desrt.fonction[80]  = (WORD (FAR PTR)())BdaImg_zBmp; 
  s_desrt.fonction[81]  = (WORD (FAR PTR)())BdaSys_zWinVersion;  
  s_desrt.fonction[82]  = (WORD (FAR PTR)())BdaGui_zWinClear; 
  s_desrt.fonction[83]  = (WORD (FAR PTR)())BdaGui_zListTitle;  
  s_desrt.fonction[84]  = (WORD (FAR PTR)())BdaGui_zWinMove; 
  s_desrt.fonction[85]  = (WORD (FAR PTR)())BdaGui_zWinMoveable; 
  s_desrt.fonction[86]  = (WORD (FAR PTR)())BdaGui_zTabview; 
  s_desrt.fonction[87]  = (WORD (FAR PTR)())BdaSys_zGetMaxy; 
  s_desrt.fonction[88]  = (WORD (FAR PTR)())BdaTxt_zFontChoose; 
  s_desrt.fonction[89]  = (WORD (FAR PTR)())BdaTxt_zFontCreate; 
  s_desrt.fonction[90]  = (WORD (FAR PTR)())BdaTxt_zFontDelete; 
  s_desrt.fonction[91]  = (WORD (FAR PTR)())BdaGui_zWinTitle; 
  s_desrt.fonction[92]  = (WORD (FAR PTR)())BdaTxt_zPrintL;  
  s_desrt.fonction[93]  = (WORD (FAR PTR)())BdaImg_getcolor;  
  s_desrt.fonction[94]  = (WORD (FAR PTR)())BdaImg_color; 
  s_desrt.fonction[95]  = (WORD (FAR PTR)())BdaImg_brush; 
  s_desrt.fonction[96]  = (WORD (FAR PTR)())BdaImg_pen; 
  s_desrt.fonction[97]  = (WORD (FAR PTR)())BdaImg_point; 
  s_desrt.fonction[98]  = (WORD (FAR PTR)())BdaImg_line;  
  s_desrt.fonction[99]  = (WORD (FAR PTR)())BdaImg_rectangle; 
  s_desrt.fonction[100] = (WORD (FAR PTR)())BdaImg_roundrect;  
  s_desrt.fonction[101] = (WORD (FAR PTR)())BdaImg_ellipse;  
  s_desrt.fonction[102] = (WORD (FAR PTR)())BdaImg_arc;  
  s_desrt.fonction[103] = (WORD (FAR PTR)())BdaImg_trapez; 
  s_desrt.fonction[104] = (WORD (FAR PTR)())BdaTxt_zPrintXYWithoutSeq; 
  s_desrt.fonction[105] = (WORD (FAR PTR)())BdaImg_zBmp2; 
  s_desrt.fonction[106] = (WORD (FAR PTR)())BdaSys_zWinNbBits;
  s_desrt.fonction[107] = (WORD (FAR PTR)())BdaTxt_zDefaultFont;
  s_desrt.fonction[108] = (WORD (FAR PTR)())BdaSys_zRGBColor;
  s_desrt.fonction[109] = (WORD (FAR PTR)())BdaSys_zDefaultColor;
  s_desrt.fonction[110] = (WORD (FAR PTR)())BdaGui_zVaButton;
  s_desrt.fonction[111] = (WORD (FAR PTR)())BdaSys_zWinSetStack;
  s_desrt.fonction[112] = (WORD (FAR PTR)())BdaSys_zSystemMenu;
  s_desrt.fonction[113] = (WORD (FAR PTR)())BdaSys_EmptyFunction;
  s_desrt.fonction[114] = (WORD (FAR PTR)())BdaSys_EmptyFunction; //BdaTra_Msg;
  s_desrt.fonction[115] = (WORD (FAR PTR)())BdaSys_EmptyFunction; //BdaTra_MsgInt;

  s_desrt.fonction[116] = (WORD (FAR PTR)())BdaAba_Test1;
  s_desrt.fonction[117] = (WORD (FAR PTR)())BdaAba_Test1;
  s_desrt.fonction[118] = (WORD (FAR PTR)())BdaAba_Test1;

  s_desrt.fonction[119] = (WORD (FAR PTR)())BdaSys_ManageLoadgo;
  s_desrt.fonction[120] = (WORD (FAR PTR)())BdaImg_ScreenSaver;
  s_desrt.fonction[121] = (WORD (FAR PTR)())BdaSys_EmptyFunction; //BdaTra_Dump;

#ifdef	BDA_UNIX
	prepare_access_controller(&s_desrt,_Z_FUNCTION_COUNT);
#endif

  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"signature=%d",rt_init->ordinaire.signature));
  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"nombre   =%d",s_desrt.nombre));

  return((VOID FAR PTR) &s_desrt);

}

