/** @pkg Staff.Fred.zGuiCtrl */ 
// ****************************************************************************
// * zTexFont.c
// * Included in TEX module
// * Font management x
// ****************************************************************************


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - Internal Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// ****************************************************************************
/** TexSetFont :  

 * @parameter hFont   IN      
 * @return: Old font
 * @author FRC
*/
// * VarGlob:
// *  pApp->hCurrentFont   IN/OUT      
// ****************************************************************************
WORD TexSetFont( WORD hFont )
{
WORD        ret;
ret = g_pApp->hCurrentFont;
if (g_pTabFont->Font[hFont].IsDefined)
  g_pApp->hCurrentFont = hFont;
return ret;
}

// ****************************************************************************
/** TexGetFont :  

 * @return: current font
 * @author FRC
*/
// * VarGlob:
// *  pApp->hCurrentFont   IN
// ****************************************************************************
WORD TexGetFont( VOID )
{
return g_pApp->hCurrentFont;
}

// ****************************************************************************
/** TexSetFontRef :  

 * @parameter hFont   IN      
 * @return: Old font
 * @author FRC
*/
// * VarGlob:
// *  pApp->hCurrentFont   IN/OUT      
// ****************************************************************************
WORD TexSetFontRef( WORD hFont )
{
use_base_font(hFont);
return TexSetFont(hFont);
}

// ****************************************************************************
/** zLoadFontRescue:
    Loads a base font for rescue. This font is loaded and selected.

 * @param nptr        IN : name of font file
 * @param EnvPath     IN : Environment path name
 * @param Handle      IN : handle of the font
 * @param pFOntDescr  OUT: font descriptor

 * @return: CE_OK
            CE_ERR  
               
 * @author FCH

 */
// * VarGlob: nothing
// ****************************************************************************
WORD zLoadFontRescue( char * nptr, const char * EnvPath, WORD Handle, PTI_FONT_DESCR pFontDescr )
{
MI_TRACE_DCL_TFN("zLdFontRescue");
FILE  * handle;
int status = CE_OK;
CHAR  PathFont[CI_MAXPATH];

  // --- Default initialisation ----------------------------
  if (pFontDescr->IsDefined)
    ToolsReinitMemory(&pFontDescr->Storage);
  else
    ToolsInitMemory(&pFontDescr->Storage);

  pFontDescr->IsDefined    = FALSE;

  // --- Load font -----------------------------------------
  strcpy( PathFont, g_pApp->PathFont );
  strcat( PathFont, nptr);

  if ((handle = fopen( PathFont, "rb")) != (FILE *) 0) 
    {
    if ( fread(g_FontRescueBuffer,sizeof(g_FontRescueBuffer),1,handle) == 1 ) 
      {
      pFontDescr->IsDefined    = TRUE;
      pFontDescr->Storage.Ptr  = g_FontRescueBuffer;
      pFontDescr->Storage.Size = sizeof(g_FontRescueBuffer); 
      pFontDescr->GrSize.cx    = 10; // VOIR IJM !!!!
      pFontDescr->GrSize.cy    = 24; // VOIR IJM !!!!
      pFontDescr->GrOffset.x   = 0;
      pFontDescr->GrOffset.y   = 0;

      cicofont( pFontDescr->Storage.Ptr );
      TexSetFontRef(Handle);
      }
    else
      status = CE_ERR_BADFONTSYSTEM;

    fclose( handle );
    }     
  else
    status = CE_ERR_BADFONTSYSTEM;

  return( status );
}

// ****************************************************************************
/** zLoadFont:
    Loads a font. This font is loaded, but not selected.

 * @param nptr        IN : name of font file
 * @param EnvPath     IN : Environment path name
 * @param Handle      IN : handle of the font
 * @param pFOntDescr  OUT: font descriptor

 * @return: CE_OK
            CE_ERR  
               
 * @author FCH
           ANF - modified for usage of font manager

 */
// * VarGlob: 
// ****************************************************************************
WORD zLoadFont( char * nptr, const char * EnvPath, WORD Handle, PTI_FONT_DESCR pFontDescr )
{
MI_TRACE_DCL_TFN("zLdFont");
CHAR  PathFont[CI_MAXPATH];
int status;

  // --- Default initialisation ----------------------------
  if (pFontDescr->IsDefined)
    ToolsReinitMemory(&pFontDescr->Storage);
  else
    ToolsInitMemory(&pFontDescr->Storage);

  pFontDescr->IsDefined    = FALSE;

#if defined(BDA_WIN32)
/////////////////////////
// Windows

// --- Load font -----------------------------------------
	if (*nptr=='/')
		{
		// Descripteur de police conforme à zdll
		// La suite est la structure windows
		MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"logfont"));
		status = loadguifont_os_dependant(Handle, &nptr[1], sizeof(LOGFONT));
		}
	else 
		{
		if (*nptr=='{')
			{
			// Descripteur de police conforme à GIGO
			strcpy(PathFont,nptr);
			}
		else
			{
			// Descripteur de police fmf
			if (ToolsFindFile(PathFont,nptr,EnvPath)==CE_ERR)
				return CE_ERR_FONTACCESS;
			}

		MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"PathFont='%s'",PathFont));
		status = standard_load_font_with_fid( Handle, PathFont );
		}

	MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"LoadFont=%d",status));
	if (status)
		return CE_ERR_BADFONTFILE;

	pFontDescr->IsDefined    = TRUE;

	status = guifontsize_without_linespacing(Handle);
	pFontDescr->GrSize.cx    = LOBYTE(status);
	pFontDescr->GrSize.cy    = HIBYTE(status);

	status = guifontoffset(Handle);
	pFontDescr->GrOffset.x   = LOBYTE(status);
	pFontDescr->GrOffset.y   = HIBYTE(status);

	// FCH15062001: coherence test with old fashion file format
	if ( (pFontDescr->GrOffset.x >= pFontDescr->GrSize.cx) || (pFontDescr->GrOffset.x >= 0x20)
		||(pFontDescr->GrOffset.y >= pFontDescr->GrSize.cy) || (pFontDescr->GrOffset.y >= 0x20)
		)
		{
		MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"Old fmf header"));
		pFontDescr->GrOffset.x = 0;
		pFontDescr->GrOffset.y = 0;
		}

#else
/////////////////////////
// Twin Useit

  // FCH26082005
  // Ici, on n'accepte pas de police système pour l'instant
  if (ToolsFindFile(PathFont,nptr,EnvPath)==CE_ERR)
    return CE_ERR_FONTACCESS;

  status = LoadFontM( PathFont, (char) FALSE, (void *) &pFontDescr->Storage.Ptr);
  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"PathFont='%s'",PathFont));
  MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"LoadFontM=%d",status));
  
  if (status == CE_ERR_FILETYPE)
    status = CE_ERR_BADFONTFILE;

  if (status != CE_OK)
    return status;

  if (!pFontDescr->Storage.Ptr)
    return CE_ERR_BADFONTFILE;

  pFontDescr->Storage.Size = ToolsExtractInt( (pFontDescr->Storage.Ptr+0x10) );
     
  pFontDescr->IsDefined    = TRUE;
  pFontDescr->GrSize.cx    = ToolsExtractInt( (pFontDescr->Storage.Ptr+0x14) );
  pFontDescr->GrSize.cy    = ToolsExtractInt( (pFontDescr->Storage.Ptr+0x12) );

  // FCH17052001: new feature, margins are coded in the header
  pFontDescr->GrOffset.x   = *(pFontDescr->Storage.Ptr+0x1E);
  pFontDescr->GrOffset.y   = *(pFontDescr->Storage.Ptr+0x1F);

  // FCH15062001: coherence test with old fashion file format
  if ( (pFontDescr->GrOffset.x >= pFontDescr->GrSize.cx) || (pFontDescr->GrOffset.x >= 0x20)
     ||(pFontDescr->GrOffset.y >= pFontDescr->GrSize.cy) || (pFontDescr->GrOffset.y >= 0x20)
     )
    {
    MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"Old fmf header"));
    pFontDescr->GrOffset.x = 0;
    pFontDescr->GrOffset.y = 0;
    }
  
  loadguifont( Handle, pFontDescr->Storage.Ptr, pFontDescr->Storage.Size );

#endif
/////////////////////////

  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"Font %02X : %dx%d - %d,%d",
            Handle, pFontDescr->GrSize.cx ,pFontDescr->GrSize.cy ,
                    pFontDescr->GrOffset.x,pFontDescr->GrOffset.y));

  if ((pFontDescr->GrSize.cx == 0) || (pFontDescr->GrSize.cy == 0))
    return CE_ERR_INCOHERENT;
  else
    return CE_OK;
}

// ****************************************************************************
/** TexInitFont
    Initialisation of fonts

 * @param nothing

 * @return: CE_OK, CE_ERR, CE_ERR_MEMORY, CE_ERR_BADFONTFILE, CE_ERR_FILEACCESS

 * @author FCH
           Modified by ANF (return codes)
 */
// * VarGlob:
//      g_pTabFont              OUT
//      g_App->hFontFixeRef     OUT
//      g_pApp->hFontFixeSmall  OUT
//      g_App->hFontPropRef     OUT
//      g_pApp->hFontPropSmall  OUT
//      cellwidth               OUT
//      cellheight              OUT
//      screencols              OUT
//      screenlins              OUT
//      g_pApp->GrScreenWidth   IN
//      g_pApp->GrScreenHeight  IN
//      g_pApp->PathLook        IN
// ****************************************************************************
WORD TexInitFont(VOID)
{
MI_TRACE_DCL_TFN("TexInitFont");
WORD  hFont;
WORD  status;

  // ---------------------------------------------------
  // Load Rescue font (Used if all other fonts are HS)
  // ---------------------------------------------------

#if defined (BDA_TWIN16)
  status = zLoadFontRescue( CI_ZRESCUE_FILENAME, g_pApp->PathFont, 0, &g_pTabFont->Font[0] );
  if ( status == CE_OK)
    {
    g_pApp->hFontFixeRef   = 0; 
    g_pApp->hFontFixeSmall = 0; 
    }
  else
    { 
    MI_TRACE((CI_TRA_F_ERROR,CI_MODULE_ID,TFN,"'%s' FAILED - %d",CI_ZRESCUE_FILENAME, status));
    return status;
   }
#endif
      
  // ---------------------------------------------------
  // Load fonts
  // ---------------------------------------------------
    
  // Reference fixe font (used to calculate text-screen dimension)
  hFont = 1+CI_OFFSETFONT;
  if ( (status = zLoadFont( CI_ZFIXREF_FILENAME, g_pApp->PathLook, hFont, &g_pTabFont->Font[hFont])) == CE_OK)
    g_pApp->hFontFixeRef = hFont; 
  else 
    { 
    MI_TRACE((CI_TRA_F_ERROR,CI_MODULE_ID,TFN,"'%s' FAILED - %d",CI_ZFIXREF_FILENAME, status));
    return status;
    }

#if !defined (BDA_TWIN16)
   // To initialise like under Twin16
   g_pTabFont->Font[0] = g_pTabFont->Font[hFont];
#endif

  // Small fixe font
  hFont = 2+CI_OFFSETFONT;
  if ( (status = zLoadFont( CI_ZFIXSMALL_FILENAME, g_pApp->PathLook, hFont, &g_pTabFont->Font[hFont])) == CE_OK)
    g_pApp->hFontFixeSmall = hFont; 
  else 
    { 
    MI_TRACE((CI_TRA_F_ERROR,CI_MODULE_ID,TFN,"'%s' FAILED - %d",CI_ZFIXSMALL_FILENAME, status));
    return status;
    }

  // Optional Proportional font
  hFont = 3+CI_OFFSETFONT;
  if ((status = zLoadFont( CI_ZPROREF_FILENAME, g_pApp->PathLook, hFont, &g_pTabFont->Font[hFont])) == CE_OK)
    g_pApp->hFontPropRef = hFont; 
  else
    {
    MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"'%s' FAILED - %d",CI_ZPROREF_FILENAME, status));
    g_pApp->hFontPropRef = g_pApp->hFontFixeRef;
    }

  // Optional Proportional small font
  hFont = 4+CI_OFFSETFONT;
  if ((status = zLoadFont( CI_ZPROSMALL_FILENAME, g_pApp->PathLook, hFont, &g_pTabFont->Font[hFont])) == CE_OK)
    g_pApp->hFontPropSmall = hFont;
  else
    {
    MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"'%s' FAILED - %d",CI_ZPROSMALL_FILENAME, status));
    g_pApp->hFontPropSmall = g_pApp->hFontFixeSmall;
    }

  g_pTabFont->FirstItemForUserFont = hFont+1;

  // ---------------------------------------------------
  // Font Initialisations
  // ---------------------------------------------------
  cellwidth  = g_pTabFont->Font[g_pApp->hFontFixeRef].GrSize.cx;
  cellheight = g_pTabFont->Font[g_pApp->hFontFixeRef].GrSize.cy;

  screencols = (g_pApp->GrScreenWidth / cellwidth);
  screenlins = (g_pApp->GrScreenHeight / cellheight);
  TexSetFontRef(g_pApp->hFontFixeRef);
  return CE_OK; 
}

// ****************************************************************************
/** TexEndFont
    Initialisation of fonts

 * @param nothing

 * @return: CE_OK
            CE_ERR

 * @author FCH
           ANF - modified for usage of font manager
 */
// * VarGlob:
//      g_pTabFont        IN/OUT
//      g_App->hFontFixe  OUT
//      g_pApp->hFontProp OUT
//      cellwidth         OUT
//      cellheight        OUT
//      screencols        OUT
//      screenlins        OUT
// ****************************************************************************
VOID TexEndFont(VOID)
{
WORD  i;

#if defined(BDA_WIN32)
/////////////////////////
// Windows

  for( i=1 ; i<CI_MAXFONT ; i++)
    {
    if (g_pTabFont->Font[i].IsDefined)
      {
      standard_drop_font(i);
      g_pTabFont->Font[i].IsDefined = FALSE;
      }
    }

#else
/////////////////////////
// Twin Useit

#ifdef	BDA_UNIX
  for( i=1 ; i<CI_MAXFONT ; i++)
#else
  for( i=0 ; i<CI_MAXFONT ; i++)
#endif
    {
    if (g_pTabFont->Font[i].IsDefined)
      {
      // If it's a BMF rescue font - just free the memory,
      // else unload it via font manager
      if (g_pTabFont->Font[i].Storage.Ptr == g_FontRescueBuffer)
        ToolsReinitMemory(&g_pTabFont->Font[i].Storage);
      else
        DropFont((void *) g_pTabFont->Font[i].Storage.Ptr);

      g_pTabFont->Font[i].IsDefined = FALSE;
      }
    }

#endif
/////////////////////////

  g_pApp->hFontFixeRef   = 0;
  g_pApp->hFontFixeSmall = 0;
  g_pApp->hFontPropRef   = 0;
  g_pApp->hFontPropSmall = 0;
           
  cellwidth = 10;
  cellheight= 23;
  screencols = 80; 
  screenlins = 25;
}

// ****************************************************************************
/** TexFontIDToHandle
    Converts the font ID to internal handle

 * @param FontID

 * @return: hFont

 * @author FCH

 */
// * VarGlob:
//      g_pTabFont        OUT
//      g_App->hFont...   OUT
// ****************************************************************************
WORD TexFontIDToHandle( SWORD fontID )
{
MI_TRACE_DCL_TFN("FontIDToH");
WORD  hFont;

  switch (fontID) 
    {
    case CE_FONTID_MENU :
      hFont = g_pApp->hFontFixeSmall;
      break;
    case CE_FONTID_INPUT :
      hFont = g_pApp->hFontFixeSmall;
      break;
    case CE_FONTID_FIXE :
      hFont = g_pApp->hFontFixeRef;
      break;
    case CE_FONTID_PROP :
      hFont = g_pApp->hFontPropRef;
      break;
    case CE_FONTID_SMALL :
      hFont = g_pApp->hFontPropSmall;
      break;
    default :
      // A user font is selected
      MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"User font"));

      hFont =  fontID - CE_FONTID_USER;
      hFont += g_pTabFont->FirstItemForUserFont;

      if ((hFont>=CI_MAXFONT) || (!g_pTabFont->Font[hFont].IsDefined))
        hFont = g_pApp->hFontPropRef;
      break;
  }

  MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"hFont=%d",hFont));
  return hFont;
}

// ****************************************************************************
/** TexFontHandleToID
    Converts the internal font handle to font ID

 * @param FontID

 * @return: hFont

 * @author FCH

 */
// * VarGlob:
//      g_pTabFont        OUT
//      g_App->hFont...   OUT
// ****************************************************************************
SWORD TexFontHandleToID( WORD hFont )
{
MI_TRACE_DCL_TFN("FontHToID");
SWORD  fontID;

  // --------------------------------------------------------------------------
  // Conversion Internal implementation --> ID
  // 1) comparison with internal known fonts
  // 2) comparison with array of all fonts (not implemented)
  // --------------------------------------------------------------------------
  if (hFont == g_pApp->hFontFixeRef)
    fontID = CE_FONTID_FIXE;    
  else if (hFont == g_pApp->hFontFixeSmall)
    fontID = CE_FONTID_INPUT;    
  else if (hFont == g_pApp->hFontPropRef)
    fontID = CE_FONTID_PROP;    
  else if (hFont == g_pApp->hFontPropSmall)
    fontID = CE_FONTID_SMALL;    
  else
    {
    // user font, the ID must be searched in loaded font
    MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"User font"));
    fontID = CE_FONTID_USER + hFont - g_pTabFont->FirstItemForUserFont;
    }           
    
  return fontID;  
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - BDA APIs
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


// ****************************************************************************
/** BdaTxt_zFont - (THO name) zfont - ABAL API
    Select a new font in already loaded fonts

 * @parameter no_font  IN  : new font ID

 * @return: old font ID 

 * @author CCDoc Administrator
 
*/
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaTxt_zFont(SWORD fontID)       
{
MI_TRACE_DCL_TFN("Font");
WORD  hOldFont;
WORD  hFont;
SWORD OldFontID;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"ID=%d",fontID));

  hFont     = TexFontIDToHandle( fontID);
  hOldFont  = TexSetFont(hFont);
  OldFontID = TexFontHandleToID(hOldFont);

MI_TRACE_RETURN(OldFontID);
}

// ****************************************************************************
/** BdaTxt_zDefaultFont: (THO name) zdefault_font - ABAL API - 
    Initialize the font (already loaded) which will be associated to  
    a type of controle

 * @parameter item    IN  : type of controle
 * @parameter font    IN  : font ID 

 * @return: CE_OK

 * @author CCDoc Administrator
 
*/
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaTxt_zDefaultFont(WORD item,WORD font)
{
MI_TRACE_DCL_TFN("DefaultFont");

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"not implemented"));
MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaTxt_zFontChoose: (THO name) zfont_choose - ABAL API (Windows only) - 
    Select a font with a system dialog box

 * @parameter fonte_desc    IN/OUT  : Windows font descriptor

 * @returns:
 *   CE_OK                 
 *   CE_ERR
 
 * @author CCDoc Administrator
 
*/
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaTxt_zFontChoose(char FAR * pFontDesc)
{
MI_TRACE_DCL_TFN("FontChoose");

#if defined(BDA_WIN32)
/////////////////////////////////////
// Windows

LOGFONT		lf;
CHOOSEFONT  cf;
BOOL			res;

if (pFontDesc[0] == 47)
	memcpy(&lf,pFontDesc+1,sizeof(lf));
else
	memcpy(&lf,pFontDesc,sizeof(lf));

// Initialisation fonte:
if (pFontDesc[1] == 'I' && pFontDesc[2] == 'N') 
	{
	lf.lfHeight=13;
	lf.lfWidth=10;
	lf.lfEscapement=MM_TEXT;
	lf.lfWeight=FW_DONTCARE;
	lf.lfItalic=0;
	lf.lfUnderline=0;
	lf.lfStrikeOut=0;
	lf.lfCharSet=0;
	lf.lfOutPrecision=OUT_DEVICE_PRECIS;
	lf.lfClipPrecision=CLIP_DEFAULT_PRECIS;
	lf.lfQuality=DEFAULT_QUALITY;
	strcpy(lf.lfFaceName,"Arial");
	}

memset(&cf, 0, sizeof(CHOOSEFONT));
cf.lStructSize  = sizeof(CHOOSEFONT);

cf.hwndOwner  = g_hwnd;

cf.lpLogFont	=&lf;
cf.Flags			= CF_SCREENFONTS | CF_EFFECTS | CF_INITTOLOGFONTSTRUCT;
cf.rgbColors	= RGB(0, 0, 0);
cf.nFontType	= SCREEN_FONTTYPE;

res=ChooseFont(&cf);    // appelle common dialog box...
if (res != 0) 
	{
	pFontDesc[0]=47;   // Flag indiquant fonte WIN32
	memcpy(pFontDesc+1,&lf,sizeof(lf));  // rends fonte à l'application
	MI_TRACE((CI_TRA_F_DUMP,CI_MODULE_ID,TFN,"desc",pFontDesc,sizeof(LOGFONT)+1));
	MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"End 0"));
	return(0);
	}
else
	{
	MI_TRACE((CI_TRA_F_FUNCTION,CI_MODULE_ID,TFN,"End -1"));
	return(-1);
	}

#else
/////////////////////////////////////
// Twin , UseIt

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"not implemented"));
if (pFontDesc!=NULL)
  pFontDesc[0]='\0';
MI_TRACE_RETURN(CE_ERR);

#endif

}

// ****************************************************************************
/** BdaTxt_zFontCreate: (THO name) zfont_create - ABAL API (Windows only) - 
    Load a new font, defined by a Windows font descriptor

 * @parameter no_fonte      IN  : font ID 
 * @parameter fonte_desc    IN  : Windows font descriptor

 * @returns
 *   CE_OK                 
 *   CE_ERR
 * @author CCDoc Administrator
 
*/
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaTxt_zFontCreate(short fontID,char FAR * pFontDesc)
{
MI_TRACE_DCL_TFN("FontCreate");
WORD  hFont;
CHAR  PathFont[CI_MAXPATH];
WORD  i;
WORD  IsEnd;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"ID=%d",fontID));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"'%s'",MI_TRA_TRUNC(pFontDesc)));

// --- Coherence tests ------------------------------------
if (pFontDesc==NULL)
  MI_TRACE_RETURN_MSG(CE_ERR,"NULL");

if (  (fontID==CE_FONTID_MENU)
   || (fontID==CE_FONTID_INPUT)
   || (fontID==CE_FONTID_FIXE)
   || (fontID==CE_FONTID_PROP)
   || (fontID==CE_FONTID_SMALL)
   || (fontID>=CI_MAXFONT)
   )
  MI_TRACE_RETURN_MSG(CE_ERR,"ID");

// Fucking system
#ifdef UNIX
  MI_TRACE_RETURN_MSG(CE_ERR,"SYSTEM");
#endif

  if (*pFontDesc=='/')
	 {
	 // Descripteur de police conforme à zdll (structure windows)
	 // Rien à faire
	 }
  else if (*pFontDesc=='{')
    {
	 // Descripteur de police système (format GIGO)
    for( i=0,IsEnd=FALSE ; (i<CI_MAXPATH-1) && (!IsEnd) ; i++ )
	   {
      PathFont[i] = pFontDesc[i];
		IsEnd = (pFontDesc[i]=='}') || (pFontDesc[i]=='\0');
		}
    PathFont[i] = '\0';
	 pFontDesc = PathFont;
	 }
  else if (*pFontDesc=='<')
    {
	 // Descripteur de police fmf (nom de fichier)
    for( i=1,IsEnd=FALSE ; (i<CI_MAXPATH-1) && (!IsEnd) ; i++ )
	   {
		IsEnd = (pFontDesc[i]=='>') || (pFontDesc[i]=='\0');
      PathFont[i-1] = (IsEnd) ? '\0' : pFontDesc[i];
		}
	 pFontDesc = PathFont;
	 }
  else
    {
    MI_TRACE_RETURN_MSG(CE_ERR,"DESC");
	 }

// --- Process ---------------------------------------------
hFont =  fontID - CE_FONTID_USER;
hFont += g_pTabFont->FirstItemForUserFont;
MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"hFont=%d",hFont));

if (zLoadFont( pFontDesc, g_pApp->PathFont, hFont, &g_pTabFont->Font[hFont]) != CE_OK)
  {
  MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"'%s' failed",MI_TRA_TRUNC(pFontDesc)));
  MI_TRACE_RETURN_MSG(CE_ERR,"LOAD");
  }

MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaTxt_zFontDelete : (THO name) zfont_delete - ABAL API (Windows only) - 
    Destroy a font

 * @parameter no_fonte      IN  : font ID 

 * @return: CE_OK
 
 * @author CCDoc Administrator
 
*/
// * VarGlob:
// ****************************************************************************
EXAWORD BDA_API BdaTxt_zFontDelete(short fontID)
{
MI_TRACE_DCL_TFN("FontDel");
WORD  hFont;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"ID=%d",fontID));

// --- Coherence tests ------------------------------------
if (  (fontID==CE_FONTID_MENU)
   || (fontID==CE_FONTID_INPUT)
   || (fontID==CE_FONTID_FIXE)
   || (fontID==CE_FONTID_PROP)
   || (fontID==CE_FONTID_SMALL)
   || (fontID>=CI_MAXFONT)
   )
  MI_TRACE_RETURN_MSG(CE_ERR,"ID");

// Fucking system
#ifdef UNIX
  MI_TRACE_RETURN_MSG(CE_ERR,"SYSTEM");
#endif

// --- Process ---------------------------------------------
hFont =  fontID - CE_FONTID_USER;
hFont += g_pTabFont->FirstItemForUserFont;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"hFont=%d",hFont));

if (hFont==TexGetFont())
  TexSetFont(g_pApp->hFontFixeRef);

if (g_pTabFont->Font[hFont].IsDefined)
  {
#if defined(BDA_WIN32)
  standard_drop_font(hFont);
#else
  DropFont((void *) g_pTabFont->Font[hFont].Storage.Ptr);
#endif
  g_pTabFont->Font[hFont].IsDefined = FALSE;
  }
else
  MI_TRACE_RETURN_MSG(CE_ERR,"UNDEF");

MI_TRACE_RETURN(CE_OK);
}


