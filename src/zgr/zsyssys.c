/** @pkg Staff.Fred.zSysSys */

// ****************************************************************************
// * zSysSys.c
// * Included in System module
// * System functionnalities
// ****************************************************************************

WORD    hd=4;//no used anywhere
SWORD   hide_show_counter=0;   

SWORD init_counter=0;
SWORD end_counter =0;


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Internal Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


// ****************************************************************************
/** zzend:
    end of Zadapt
 * @param nothing
 * @return: nothing
 * @author FRC
 */
// * VarGlob:
// ****************************************************************************
VOID  zzend()
{
MI_TRACE_DCL_TFN("zzend");

  if ( g_VesaMode != -1 ) 
    {
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"LookEndAllComponents"));
    LookEndAllComponents();
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"LookEndPalette"));
    LookEndPalette();
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"zzendmouse"));
    zzendmouse();

    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"DestroyWindowSystem"));
    DestroyWindowSystem();//new vap
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"DestroyStandardBitmaps"));
    DestroyStandardBitmaps();
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"DestroyStandardIcons"));
    DestroyStandardIcons();
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"GuiDestroyMBoxSystem"));
    GuiDestroyMBoxSystem();
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"GuiDestroyScrollHolder"));
    GuiDestroyScrollHolder();
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"TexEndFont"));
    TexEndFont();

    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"flush_mimo"));
    flush_mimo(); // FRC22062001: To clear the mouse stack

    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"liberate_images"));
    liberate_images();

#if defined (BDA_UNIX) || defined(BDA_WIN32)

	 if (g_VesaMode!=-2)
		{
		MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"liberatepixel"));
		if ( liberatepixel() <= 1 ) 
			{
			cicopalette(0,16);
			}
		}

	x_putch(27); x_putch('v');
	g_VesaMode = -1;

#else

    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"liberatepixel"));
    liberatepixel();
    g_VesaMode = -1;

#endif

	}

  return;
}

#if defined(BDA_TWIN16)
// ****************************************************************************
/** llwait: internal function, used to wait some amount of time

 * @return: void
 * @author ANF
 
 */
// * VarGlob: 
// ****************************************************************************
void  llwait( char * descriptor )
{
_asm  {
  push  ds      ;** DS ==> Pile
  push  bx
  push  ax
  lds bx,descriptor
  mov ah,42h  
  int 110
  lds bx,descriptor
  mov ah,31h  
  int 110
  pop ax
  pop bx
  pop ds      
  };
  return;
}
#endif

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Exported Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// ****************************************************************************
/** SysWait
    function, used to wait some amount of time

 * @return: void
 * @author ANF
 
 */
// * VarGlob: 
// ****************************************************************************
#if defined(BDA_TWIN16)
static  char waitbuffer[16];
#endif

VOID  SysWait( SWORD dixsec )
{
#if defined(BDA_TWIN16)
  waitbuffer[0] = '\x80';
  waitbuffer[1] = (dixsec & 0x00FF);
  waitbuffer[2] = ((dixsec >> 8) & 0x00FF);
  waitbuffer[3] = waitbuffer[4] = 
  waitbuffer[5] = waitbuffer[6] = waitbuffer[7] = 0;
  llwait( waitbuffer );
#elif defined(BDA_WIN32)
  Sleep(dixsec*100);
#else
  usleep(100000 * dixsec);
#endif   
}

// ****************************************************************************
/** SysInitShow:
    Initialisation of rectangle to show
 * @param nothing
 * @return: nothing
 * @author FRC
 */
// * VarGlob:
//    g_pApp->rectToShow  OUT 
// ****************************************************************************
VOID  SysInitShow(VOID)
{
ToolsVoidRectangle(&g_pApp->rectToShow);
}

// ****************************************************************************
/** SysIncreaseShow:
    Increase the show rectangle with a new zone
 * @param nothing
 * @return: nothing
 * @author FRC
 */
// * VarGlob:
//    g_pApp->rectToShow  IN/OUT 
// ****************************************************************************
VOID  SysIncreaseShow(PTI_RECTANGLE p)
{
ToolsIncreaseRectangle(&g_pApp->rectToShow,p);
}

// ****************************************************************************
/** SysShow:
    Displays the rectangle to show
 * @param nothing
 * @return: nothing
 * @author FRC
 */
// * VarGlob:
//    g_pApp->rectToShow  IN/OUT
// ****************************************************************************
VOID  SysShow(VOID)
{
++hide_show_counter;

// IJM03102002 add hide/show
show(0,0,0,0);

zzshowmouse();
}

// ****************************************************************************
/** SysShow:
    Force Display of modified areas of the screen.
    Screen gets lost so this is necessary for Message Box display
 * @param nothing
 * @return: nothing
 * @author IJM
 */
// * VarGlob:
//    g_pApp->rectToShow  IN/OUT
// ****************************************************************************
VOID  SysFlush(VOID)
{
++hide_show_counter;
/* ---------------- */
/* IJM : 19/11/2004 */
/* ---------------- */
while ( show(0,0,0,0) );
zzshowmouse();
}

// ****************************************************************************
/** SysHide:
    Hides display
 * @param nothing
 * @return: nothing
 * @author FRC
 */
// * VarGlob:
// ****************************************************************************
VOID  SysHide(VOID)
{
--hide_show_counter;
zzhidemouse();
GuiSetActiveCursor(0);

// IJM03102002 add hide/show
hide();
}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - API Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


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
EXAWORD BDA_API BdaSys_zInit(char FAR * version)
{
MI_TRACE_DCL_TFN("zInit");

char * eptr;
char   GrMode[5];
SWORD  RequestedMode;
int	 res;

MI_TRACE_BEGIN();

#if defined(BDA_WIN23)
	if (!IsUtilActivated())
      MI_TRACE_RETURN_MSG(CE_ERR_UNSUPPORTED,"No Util API");
	
	if (!x_event(82))	
      MI_TRACE_RETURN_MSG(CE_ERR_UNSUPPORTED,"graphoff");
#endif

  // -------------------------------------------------------------------------
  // - Test version Z-Library 
  // -------------------------------------------------------------------------
  if (memcmp(version,"LCLH",4) == 0) {
    version[4]=(char)cellwidth;
    version[5]=(char)cellheight;
    MI_TRACE_RETURN_MSG(31,"VER");
    }
  else if (g_VesaMode==-1) 
    {
    // ------------------------------------------------------------------
    // Init context 
    // ------------------------------------------------------------------
    init_counter++;
    MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"NbInit=%d",init_counter));

    g_pTabFont= &g_App.TabFont;
    g_pApp    = &g_App.App;
    g_pClip   = &g_App.Clip;
    g_pPrint  = &g_App.Print;
    g_pCaret  = &g_App.Caret;
    g_pLook   = &g_App.Look;
    g_pPuPo   = &g_App.PuPo;
    g_pBmp    = &g_App.Bmp; 

    memset( (VOID FAR PTR)g_pTabFont, 0, sizeof(TI_TABFONT));
    memset( (VOID FAR PTR)g_pApp    , 0, sizeof(TI_MEMO_APPLI));
    memset( (VOID FAR PTR)g_pClip   , 0, sizeof(TI_RECTANGLE));
    memset( (VOID FAR PTR)g_pPrint  , 0, sizeof(TI_MEMO_PRINT));
    memset( (VOID FAR PTR)g_pCaret  , 0, sizeof(TI_MEMO_CARET));
    memset( (VOID FAR PTR)g_pLook   , 0, sizeof(TI_MEMO_LOOK));
    memset( (VOID FAR PTR)g_pPuPo   , 0, sizeof(TI_PUPO));
    memset( (VOID FAR PTR)g_pBmp   , 0, sizeof(TI_BMP));
    
    SysInitShow();
    ToolsGetZiniKey(g_pApp->PathLook, CI_ZINI_LOOKPATH_NAME, CI_MAXPATH, TRUE);
    ToolsGetZiniKey(g_pApp->PathZlib, CI_ZINI_ZLIBPATH_NAME, CI_MAXPATH, TRUE);

#if defined(BDA_WIN32)
    ToolsGetZiniKey(g_pApp->PathFont, CI_FONTPATH_NAME, CI_MAXPATH, TRUE);
#else
    strcpy(g_pApp->PathFont,CI_SYSTEMFONT_PATH);
#endif 

    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"PathFont='%s'",g_pApp->PathFont));
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"PathLook='%s'",g_pApp->PathLook));
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"PathZlib='%s'",g_pApp->PathZlib));
    
	// ------------------------------------------------------------------
	// Init graphic mode
	// ------------------------------------------------------------------

	// --- Lecture des variables d'environnement
	ToolsGetZiniKey(GrMode, CI_ZINI_GRMODE, 2, FALSE);
	MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"'%s'",GrMode));
	if      (strcmp(GrMode,"0")==0) RequestedMode = CI_GR_320X200; 
	else if (strcmp(GrMode,"1")==0) RequestedMode = CI_GR_640X400; 
	else if (strcmp(GrMode,"2")==0) RequestedMode = CI_GR_640X480; 
	else if (strcmp(GrMode,"3")==0) RequestedMode = CI_GR_800X600; 
	else if (strcmp(GrMode,"4")==0) RequestedMode = CI_GR_1024X768; 
	else if (strcmp(GrMode,"5")==0) RequestedMode = CI_GR_1280X1024; 

	else if ((eptr = Portable_getenv("ZGRMODE")) != (char *) 0) 
		{
		if      (strcmp(eptr,"0")==0) RequestedMode = CI_GR_320X200; 
		else if (strcmp(eptr,"1")==0) RequestedMode = CI_GR_640X400; 
		else if (strcmp(eptr,"2")==0) RequestedMode = CI_GR_640X480; 
		else if (strcmp(eptr,"3")==0) RequestedMode = CI_GR_800X600; 
		else if (strcmp(eptr,"4")==0) RequestedMode = CI_GR_1024X768; 
		else if (strcmp(eptr,"5")==0) RequestedMode = CI_GR_1280X1024; 
		else	RequestedMode = CI_GR_UNKNOWN; 
		}

	else RequestedMode = CI_GR_UNKNOWN; 

	// --- Initialisation
	if (RequestedMode == CI_GR_UNKNOWN)
		{
#if defined(BDA_WIN32) || defined(BDA_UNIX)
		// zgr se comporte comme un "esclave"
		// il utilise le mode graphique courant, 
		// sans le réinitialiser
		g_VesaMode = -2;
		g_pApp->GrScreenWidth  = x_conf(69);
		g_pApp->GrScreenHeight = x_conf(68);
#else
		// zgr est forcé
		RequestedMode = CI_GR_800X600;
#endif
		}

	if (RequestedMode != CI_GR_UNKNOWN)
		{
		// On change la taille de l'affichage
		// mais on doit conserver le mode palette ou TrueColor
		int FullRequestedMode;

		if (get_pixel_format())
			FullRequestedMode = RequestedMode | 0x0100;
		else
			{
			switch(get_pixel_size())
				{
				case 1 : FullRequestedMode = RequestedMode | 0x0200;; break;
				case 2 : FullRequestedMode = RequestedMode | 0x0300;; break;
				case 4 : FullRequestedMode = RequestedMode | 0x0400;; break;
				default: FullRequestedMode = RequestedMode | 0x0400;; break;
				}
			} 

		MI_TRACE((CI_TRA_F_ERROR,CI_MODULE_ID,TFN,"initialisepixel reqmode=%04X",FullRequestedMode));
		g_VesaMode = initialisepixel(FullRequestedMode);

		if (g_VesaMode == -1)
			{
			MI_TRACE((CI_TRA_F_ERROR,CI_MODULE_ID,TFN,"initialisepixel %d",g_VesaMode));
			MI_TRACE_RETURN_MSG(CE_ERR_INCOHERENT,"initialisepixel");
			}

		switch ( g_VesaMode & 0x00FF ) 
			{
			case CI_GR_320X200 :
				g_pApp->GrScreenWidth  = 320;
				g_pApp->GrScreenHeight = 200;
				break;
			case  CI_GR_640X400 :
				g_pApp->GrScreenWidth  = 640;
				g_pApp->GrScreenHeight = 400;
				break;
			case CI_GR_640X480 :
				g_pApp->GrScreenWidth  = 640;
				g_pApp->GrScreenHeight = 480;
				break;
			case CI_GR_800X600 :
				g_pApp->GrScreenWidth  = 800;
				g_pApp->GrScreenHeight = 600;
				break;
			case CI_GR_1024X768 :
				g_pApp->GrScreenWidth  = 1024;
				g_pApp->GrScreenHeight = 768;
				break;
			case CI_GR_1280X1024 :
				g_pApp->GrScreenWidth  = 1280;
				g_pApp->GrScreenHeight = 1024;
				break;
			default :
				liberatepixel();
				MI_TRACE((CI_TRA_F_ERROR,CI_MODULE_ID,TFN,"Unknown GrMode %d",g_VesaMode));
				MI_TRACE_RETURN_MSG(CE_ERR_INCOHERENT,"Unknown GrMode");
				break;
			}

			// Le viewport doit être porté à la taille de la fenêtre sinon
			// il y a des cafouillages dans les affichages 
			cicowindow(0,0,g_pApp->GrScreenWidth,g_pApp->GrScreenHeight);

	}

	MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"GrMode=%d",g_VesaMode));

    // ------------------------------------------------------------------
    // Look initialisation
    // ------------------------------------------------------------------
    initialise_images();

    res = TexInitFont();  
    if (res != CE_OK)
      {
      zzend();
      // La zlib confond le n°poste 27 avec l'erreur mémoire
      if (res==CE_ERR_MEMORY) res += CE_ERR_USER;
      MI_TRACE_RETURN_MSG(res,"Font");
      }

    
    if (LookInitAllComponents() == CE_ERR)
      {
      zzend();
      MI_TRACE_RETURN_MSG(CE_ERR,"Component");
      }
  
    if (LookInitPalette() == CE_ERR)
      {
      zzend();
      MI_TRACE_RETURN_MSG(CE_ERR,"Palette");
      }

    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"Look1 OK"));

    initialise_letter_size(cellwidth,cellheight);
    InitialiseWindowSystem();

    res = GuiInitialiseScrollSystem();
    if (res != CE_OK)
      {
      zzend();
      // La zlib confond le n°poste 27 avec l'erreur mémoire
      if (res==CE_ERR_MEMORY) res += CE_ERR_USER;
      MI_TRACE_RETURN_MSG(res,"ListScroll");
      }

    res = GuiInitialiseMBoxSystem(1,screenlins/2 - 4,screencols,screenlins/2 +4);
    if (res != CE_OK)
      {
      zzend();
      // La zlib confond le n°poste 27 avec l'erreur mémoire
      if (res==CE_ERR_MEMORY) res += CE_ERR_USER;
      MI_TRACE_RETURN_MSG(res,"MsgBox");
      }

    LoadAndAssociateStandardBitmaps(g_pApp->PathLook);
    LoadStandardIcons(g_pApp->PathLook);

    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"Look2 OK"));

    zzinitmouse("");
    calibrate_mouse( g_pApp->GrScreenWidth, g_pApp->GrScreenHeight );

    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"mouse OK"));
    }

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaSys_zEnd: (THO name) zend - ABAL API
    End

 * @param version    IN/OUT

 * @return: CE_OK

 * @author VAP 9.12.00 11.20
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_zEnd()
{
MI_TRACE_DCL_TFN("zEnd");
#ifdef TRACEON
int TmpCptAlloc  = gCptAlloc;
int Tmphide_show = hide_show_counter;
int TmpBitmap    = g_pApp->BitmapCounter;
int Flag;
#endif

MI_TRACE_BEGIN();

  end_counter++;
  zzend();

#ifdef TRACEON
  // Statistics, may be warnings if something is wrong
  Flag = CI_TRA_F_INFO_HIGH;
  MI_TRACE((Flag,CI_MODULE_ID,TFN,"Stat %s (%d,%d)","Init/End",init_counter,end_counter));

  Flag = (gCptAlloc!=0) ? CI_TRA_F_WARNING : CI_TRA_F_INFO_HIGH;
  MI_TRACE((Flag,CI_MODULE_ID,TFN,"Stat %s (%d,%d)","Alloc", TmpCptAlloc,gCptAlloc));

  Flag = (hide_show_counter!=0) ? CI_TRA_F_WARNING : CI_TRA_F_INFO_HIGH;
  MI_TRACE((Flag,CI_MODULE_ID,TFN,"Stat%s (%d,%d)","HideShow",Tmphide_show,hide_show_counter));

  Flag = (TmpBitmap-g_pApp->BitmapCounter!=0) ? CI_TRA_F_WARNING : CI_TRA_F_INFO_HIGH;
  MI_TRACE((Flag,CI_MODULE_ID,TFN,"Stat %s (%d,%d)","Image",TmpBitmap,g_pApp->BitmapCounter));

  Flag = (g_pPuPo->FrameCreated-g_pPuPo->FrameDeleted!=0) ? CI_TRA_F_WARNING : CI_TRA_F_INFO_HIGH;
  MI_TRACE((Flag,CI_MODULE_ID,TFN,"Stat %s (%d,%d)","Frame",g_pPuPo->FrameCreated,g_pPuPo->FrameDeleted));

  Flag = (g_pPuPo->NumBGAllocated-g_pPuPo->NumBGLiberated!=0) ? CI_TRA_F_WARNING : CI_TRA_F_INFO_HIGH;
  MI_TRACE((Flag,CI_MODULE_ID,TFN,"Stat %s (%d,%d)","FrameBG",g_pPuPo->NumBGAllocated,g_pPuPo->NumBGLiberated));

  Flag = (g_pPuPo->NumWDAllocated-g_pPuPo->NumWDLiberated!=0) ? CI_TRA_F_WARNING : CI_TRA_F_INFO_HIGH;
  MI_TRACE((Flag,CI_MODULE_ID,TFN,"Stat %s (%d,%d)","Window",g_pPuPo->NumWDAllocated,g_pPuPo->NumWDLiberated));

  Flag = CI_TRA_F_INFO_HIGH;
  MI_TRACE((Flag,CI_MODULE_ID,TFN,"Stat %s (%d,%d)","Frames Killed in Zadapt",g_pPuPo->FramesKilledByZadapt,0));
#endif

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaSys_ManageLoadgo: zzManageLoadgo _ ABAL API

 * @param version    IN/OUT

 * @return: CE_OK  
               
 * @author VAP 9.12.00

 */
// * VarGlob:
// *   g_ScreenMode 
// ****************************************************************************
EXAWORD BDA_API BdaSys_ManageLoadgo(WORD IsBeforeLoadgo)
{
MI_TRACE_DCL_TFN("Loadgo");
SWORD NewMode;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"%d",IsBeforeLoadgo));

	if (g_VesaMode!=-2)
		{
		if (IsBeforeLoadgo)
			{
			liberatepixel();
			}
		else
			{
			NewMode = initialisepixel( g_VesaMode | 256 );
			if ((NewMode==-1) || (NewMode!=g_VesaMode))
				{
				MI_TRACE((CI_TRA_F_ERROR,CI_MODULE_ID,TFN,"initialisepixel %d",NewMode));
				zzend();
				MI_TRACE_RETURN_MSG(CE_ERR_INCOHERENT,"initialisepixel");
				}
			else
				LookInitPalette();
			}
		}

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaSys_zHide: (THO name) zbhide - ABAL API
    Hide modifications of display

 * @param flag    IN

 * @return: CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_zHide(WORD flag)
{
MI_TRACE_DCL_TFN("Hide");

MI_TRACE_BEGIN();
SysHide();
MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaSys_zShow: (THO name) zbshow - ABAL API
    ???? Hide modifications of display

 * @param flag    IN
 * @param x1      IN
 * @param y1      IN
 * @param x2      IN
 * @param y2      IN

 * @return: CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_zShow(WORD flag,WORD x1,WORD y1,WORD x2,WORD y2)
{
MI_TRACE_DCL_TFN("Show");

MI_TRACE_BEGIN();
SysShow();
MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaSys_zWait: (THO name) zw_wait - ABAL API - 
    Give hand to the system

 * @return: CE_OK
 * @author ANF
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_zWait()
{
MI_TRACE_DCL_TFN("Wait");

//MI_TRACE_BEGIN();

SysWait(2);    // Waiting 0.2 seconds


//MI_TRACE_RETURN(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaSys_zAppliAlone; (THO name) zwin_alone - ABAL API - (Windows 16 only)
    Only 1 instance of the application

 * @param nomappli    IN

 * @returns 
    CE_OK  
    CE_ERR  : appli already loaded (Win16 only)
    
 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_zAppliAlone(char FAR * nomappli)
{
MI_TRACE_DCL_TFN("AppliAlone");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaSys_zWinVersion: (THO name) zzwin_version - ABAL API
    Version of User interface Win3.11 or Win95

 * @param nomappli    IN

 * @returns
    31
    95
 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// *   Nothing
// ****************************************************************************
EXAWORD BDA_API BdaSys_zWinVersion()
{
MI_TRACE_DCL_TFN("WinVersion");
MI_TRACE_VOID(95);
return 95;
}

// ****************************************************************************
/** BdaSys_zWinNbBits: (THO name) zzwin_nbbits - ABAL API (Windows only?)
    Return number of bits by pixel

 * @return: 8 (1 byte per pixel in 256 colors)

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// *   Nothing
// ****************************************************************************
EXAWORD BDA_API BdaSys_zWinNbBits()
{
MI_TRACE_DCL_TFN("WinNbBits");
MI_TRACE_VOID(8);
return 8;
}

// ****************************************************************************
/** BdaSys_zGetMaxy: (THO name) zgetmaxy - ABAL API
    Return the size of the screen in text mode

 * @param x       OUT
 * @param y       OUT

 * @return: ?

 * @author ANF
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_zGetMaxy(WORD FAR PTR x,WORD FAR PTR y)
{
MI_TRACE_DCL_TFN("GetMaxy");

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"(%d,%d)",screencols,screenlins));
  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"(%lX,%lX)",(unsigned long)x,(unsigned long)y));
  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"x=%04X",*x));
  //MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"y=%04X",*y));
  
  ToolsAbalPutWord( x, screencols );
  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"apres x=%04X",(WORD)*x));
  ToolsAbalPutWord( y, screenlins );
  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"apres y=%04X",(WORD)*y));
MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaSys_zWinHelp: (THO name) zwinhelp - ABAL API - (Windows only)
    Starts Windows Help (Winhelp.exe) 

 * @param ch1       IN
 * @param type      IN
 * @param ch2       IN

 * @return: non zero value if OK (see MSDN)

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_zWinHelp(char FAR * ch1,SWORD type,char FAR * ch2)
{
MI_TRACE_DCL_TFN("WinHelp");
MI_TRACE_VOID(1);
return 1;
}

// ****************************************************************************
/** BdaSys_zSystemMenu: (THO name) zsystem_menu - ABAL API - (Windows only)
    Calls system menu

 * @return: 0

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_zSystemMenu() 
{
MI_TRACE_DCL_TFN("SystemMenu");
MI_TRACE_VOID(0);
return 0;
}

// ****************************************************************************
/** BdaSys_zRGBColor: (THO name) zzRGBcolo - ABAL API -
    Memorizes a color

 * @param set       IN
 * @param cprol     IN
 * @param r         IN
 * @param g         IN
 * @param b         IN

 * @return: CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_zRGBColor(WORD set,WORD cprol,WORD r,WORD g,WORD b) 
{
MI_TRACE_DCL_TFN("RGBColor");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/* BdaSys_zDefaultColor: (THO name) zdefault_color - ABAL API
   Defines a default color for the elements of a window

 * @param item      IN
 * @param r         IN
 * @param g         IN
 * @param b         IN

 * @return: CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaSys_zDefaultColor(WORD item,WORD r,WORD g,WORD b) 
{
MI_TRACE_DCL_TFN("DefaultColor");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

