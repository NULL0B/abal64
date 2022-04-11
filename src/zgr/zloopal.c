/** @pkg Staff.Fred.zLooPal */ 
// ****************************************************************************
// * zLooPal.c
// * Included in zLook module
// * Palette management
// ****************************************************************************


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// - External Functions
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// ****************************************************************************
/** zInitPalette: 

 * @param nothing
 * @return: CE_OK  CE_ERR
 * @author FRC
 */
// * VarGlob: 
// *  g_pLook->ColorCicoToPalette OUT
// *  g_pApp->PathLook            IN
// ****************************************************************************
WORD LookInitPalette(VOID)
{
MI_TRACE_DCL_TFN("InitPal");
WORD i;
WORD Colors;
CHAR  NamePalette[CI_MAXPATH];

#if !defined(BDA_WIN32)
CHAR  PathPalette[CI_MAXPATH];
#endif

  // ------------------------------------------------------------------------------
  // Palette initialisation 
  // From a file or internal default palette
  // ------------------------------------------------------------------------------

  ToolsGetZiniKey(NamePalette, CI_ZINI_PALETTE_NAME, CI_MAXPATH, FALSE);

  if(*NamePalette=='\0')
	 strcpy(NamePalette,CI_ZPALETTE_FILENAME);

#if defined(BDA_WIN32)
  if (load_palette_byexa(NamePalette))
    {
    MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"Assumes default palette"));
    put_palette_byexa();
    }

#else

  if (ToolsFindFile(PathPalette,NamePalette, CI_SYSTEMIMAGE_PATH)==CE_OK)
	 {
    load_palette(PathPalette);
	 }
  else
    {
    MI_TRACE((CI_TRA_F_WARNING,CI_MODULE_ID,TFN,"Assumes default palette"));
    put_palette();
    }

#endif

  // ------------------------------------------------------------------------------
  // ABAL / Palette adaptation
  // To have a correct look using ABAL colors, 
  // we change the classical black and white colors by the relief colors
  // ------------------------------------------------------------------------------
  #if defined (BDA_UNIX) || defined(BDA_WIN32) /* Portage: à vérifier... */
  cicopalette(0,0); // gestion de la transparence
  #endif
  cicopalette(CI_COL_CICO_HIGRAY,CI_COL_NEUTRAL);
  cicopalette(CI_COL_CICO_LOGRAY,CI_COL_GRAYED);
  cicopalette(CI_COL_CICO_WHITE,CI_COL_WHITE);

  // ------------------------------------------------------------------------------
  // ABAL / Palette adaptation
  // Palette colors are not sorted in the same order as ABAL colors.
  // --> CICO functions use ABAL color convention, we use directly these colors 
  //     (see CI_COL_CICO_xxx constants), for example in 'cicocolour'.
  // --> Graphic functions use GIF Palette convention, we must convert it to get 
  //     the same color as ABAL, for example in 'filzone'.
  // ------------------------------------------------------------------------------
  for( i=0 ; i<16 ; i++)
    {
    Colors = cicopalette(i,i);
//    Colors = cicocolour(i,i); // this function returns the actual index in the palette
    g_pLook->ColorCicoToPalette[i] = (BYTE)Colors; /* i ;*/  /* LOBYTE(Colors); */ 
    Colors = cicopalette(i,Colors);
    }    

  cicocolour(CI_COL_CICO_WHITE,CI_COL_CICO_BLACK);

  return CE_OK;
}

VOID	zcicocolour(WORD f, WORD b)
{
#if defined (BDA_UNIX) || defined(BDA_WIN32)
	if ( f < 16 )
		f = g_pLook->ColorCicoToPalette[f];
	if ( b < 16 )
		b = g_pLook->ColorCicoToPalette[b];
#endif
	cicocolour(f,b);
	return;
}

VOID LookEndPalette(VOID)
{
}


