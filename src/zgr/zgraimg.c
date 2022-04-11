/** @pkg Staff.Fred.zImage */ 
// ****************************************************************************
// * zImage.c
// * Included in Graphic module
// * Image functionnalities
// ****************************************************************************


// ****************************************************************************
/** BdaImg_zBmpLoad: (THO name) zbmp_load - ABAL API
    Load a new bmp from a file 

 * @param bmp_no      IN  : bmp ID 
 * @param bmp_nom     IN  : name of file

 * @returns
      CE_OK                 
      CE_ERR_MEMORY         
      CE_ERR_FILEACCESS     
      CE_ERR_FILETYPE       

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaImg_zBmpLoad(WORD bmp_no,char FAR * bmp_nom,WORD bmp_mode)
{
MI_TRACE_DCL_TFN("BmpLoad");

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"NoBmp=%d"  ,bmp_no));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"name='%s'" ,bmp_nom));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"mode=%d"   ,bmp_mode));
  bmp_error_code=0;
  zbmp_load(bmp_no,bmp_nom,bmp_mode);
MI_TRACE_RETURN(bmp_error_code);
}

// ****************************************************************************
/** BdaImg_zBmpFree: (THO name) zbmp_free - ABAL API
    release a bmp

 * @param bmp_no      IN  : bmp ID 

 * @returns
      CE_OK                 

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaImg_zBmpFree(WORD bmp_no)
{
MI_TRACE_DCL_TFN("BmpFree");

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"NoBmp=%d",bmp_no));
  zbmp_free(bmp_no);
MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaImg_zDllBitmapLoad: (THO name) zdll_load - ABAL API (Windows only)
    Load a resource file 

 * @param dll_nom     IN  : name of file

 * @returns
      CE_OK                 
      CE_ERR_FILEACCESS     

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaImg_zDllBitmapLoad(char FAR * dll_nom)
{
MI_TRACE_DCL_TFN("DllBitmapLoad");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaImg_zDllBitmapFree : (THO name) zdll_free - ABAL API - 
    release a resource file

 * @param Nothing

 * @returns
      CE_OK                 
      
 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaImg_zDllBitmapFree()
{
MI_TRACE_DCL_TFN("DllBitmapFree");
MI_TRACE_VOID(CE_OK);
return CE_OK;
}

// ****************************************************************************
/** BdaImg_zButtonBitmap : (THO name) zwin_bbitmap - ABAL API (Windows only)
    Associate a bitmap included in a ressource file already loaded by zdll_load
    to a button type/label

 * @param bout_type  IN : type of button (small, big,...)
 * @param bout_lib   IN : label of button ("O.K", "ESC",...)
 * @param bit_nom    IN : name of resource
 * @param larg       IN

 * @returns
      CE_OK
      CE_ERR_FULL   (too much association)
      CE_ERR_NOKEY  (bmp not found in the ressource file)

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaImg_zButtonBitmap(WORD bout_type,char FAR * bout_lib,char FAR * bit_nom,WORD larg)
{
MI_TRACE_DCL_TFN("ButtonBitmap");

MI_TRACE_BEGIN();
MI_TRACE_RETURN(CE_ERR_NOKEY);
}

// ****************************************************************************
/** BdaImg_zButtonBmp: (THO name) zwin_bbmp - ABAL API
    Associate a bitmap already loaded by zbmp_load to a button type/label

 * @param bout_type  IN : type of button (small, big,...)
 * @param bout_lib   IN : label of button ("O.K", "ESC",...)
 * @param bit_no     IN : bmp ID
 * @param larg       IN

 * @returns
      CE_OK
      CE_ERR_FULL    (too much association)
      CE_ERR_MEMORY
      CE_ERR_NOLOGID (bmp file not found)

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaImg_zButtonBmp(WORD bout_type,char FAR * bout_lib,WORD bmp_no,WORD larg)
{
MI_TRACE_DCL_TFN("ButtonBmp");

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"type =%d"  ,bout_type));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"NoBmp=%d"  ,bmp_no));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lg=%d"     ,larg));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"text='%s'" ,MI_TRA_TRUNC(bout_lib)));

  AssociateImage(bmp_no,bout_lib,larg,bout_type);

//MI_TRACE_RETURN(CE_ERR_NOLOGID);
MI_TRACE_RETURN(CE_OK);
}

// ****************************************************************************
/** BdaImg_zBitmap: (THO name) zwin_bitmap - ABAL API -(Windows only)
     Display a bitmap included in a ressource file already loaded by zdll_load

 * @param bit_nom    IN : name of resource
 * @param x          IN
 * @param y          IN
 * @param larg       IN
 * @param haut       IN

 * @returns
      CE_OK
      CE_ERR_NOKEY  (bmp not found in the ressource file)

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaImg_zBitmap(char FAR * bit_nom,WORD x,WORD y,WORD larg,WORD haut)
{
MI_TRACE_DCL_TFN("Bitmap");

MI_TRACE_BEGIN();
//  zwin_bmp(bmp_nom,0,0,x,y,larg,haut);
MI_TRACE_RETURN(CE_ERR_NOKEY);
}

// ****************************************************************************
/** BdaImg_zBmp: (THO name) zwin_bmp - ABAL API
     Display a bitmap already loaded by zbmp_load

 * @param bmp_no     IN : bmp ID
 * @param x          IN
 * @param y          IN
 * @param larg       IN
 * @param haut       IN

 * @returns
      CE_OK<p>
      CE_ERR_FULL    (too much association)<p>
      CE_ERR_MEMORY<p>
      CE_ERR_BADNOLOG<p>
      CE_ERR_NOLOGID (bmp file not found)<p>

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaImg_zBmp(WORD bmp_no,WORD x,WORD y,WORD larg,WORD haut)
{
MI_TRACE_DCL_TFN("Bmp");
WORD  ret = CE_ERR;

MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"NoBmp=%d"  ,bmp_no));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d) on (%d,%d)",x,y,larg,haut));
  SysHide();
  SetChangeFlag();
  ret = zwin_bmp(bmp_no,x,y,larg,haut);
  SysShow();
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
/** BdaImg_zBmp2: (THO name)zwin_bmp2 - ABAL API -
    Display a bitmap already loaded by zbmp_load

 * @param bmp_no     IN : bmp ID
 * @param olarg      IN
 * @param ohaut      IN
 * @param x          IN
 * @param y          IN
 * @param larg       IN
 * @param haut       IN

 * @returns
      CE_OK
      CE_ERR_FULL    (too much association)
      CE_ERR_MEMORY
      CE_ERR_BADNOLOG
      CE_ERR_NOLOGID (bmp file not found)

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
EXAWORD BDA_API BdaImg_zBmp2(WORD bmp_no,WORD olarg,WORD ohaut,WORD x,WORD y,WORD larg,WORD haut)
{
MI_TRACE_DCL_TFN("Bmp2");
WORD  ret = CE_ERR;

//FCh: For V0, function redirected
//     just diplay without stretch
MI_TRACE_BEGIN();
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"NoBmp=%d"  ,bmp_no));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"at (%d,%d) on (%d,%d)",x,y,larg,haut));
  MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"lgori (%d,%d)",olarg,ohaut));
  SysHide();
  SetChangeFlag();
  ret = zwin_xbmp( bmp_no, olarg, ohaut, x, y, larg, haut );
  SysShow();
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
/** BdaImg_ScreenSaver: - ABAL API -
    Display a screen saver

 * @param bmp_no     nothing

 * @returns
      CE_OK

 * @author CCDoc Administrator
 
 */
// * VarGlob: 
// ****************************************************************************
WORD FindNextScrSv( char * NextFile, WORD Index, const char * EnvPathname)
{
MI_TRACE_DCL_TFN("NextSV");
char  FileName[CI_MAXPATH];

NextFile[0] = '\0';
Index++;

sprintf( FileName, "%s%02u.gif", CI_ZSCRSV_FILENAME, Index);
MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"'%s'",FileName));
if (ToolsFindFile( NextFile, FileName, EnvPathname)==CE_OK)
  {
  return Index;
  }

sprintf( FileName, "%s%02u.jpg", CI_ZSCRSV_FILENAME, Index);
MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"'%s'",FileName));
if (ToolsFindFile( NextFile, FileName, EnvPathname)==CE_OK)
  {
  return Index;
  }

sprintf( FileName, "%s%02u.bmp", CI_ZSCRSV_FILENAME, Index);
MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"'%s'",FileName));
if (ToolsFindFile( NextFile, FileName, EnvPathname)==CE_OK)
  {
  return Index;
  }

return 0;
}


EXAWORD BDA_API BdaImg_ScreenSaver()
{
#if defined(BDA_WIN32)
//Sans intérêt sous Windows

return CE_OK;

#else

MI_TRACE_DCL_TFN("ScrSv");
char  FileName[CI_MAXPATH];
char  Path[CI_MAXPATH];
char  Buf[3];
WORD  Index;
WORD  GotoNextScreen = FALSE;
WORD  NoBmp;
WORD  Cpt;
unsigned int  TimeSwap = 2;

MI_TRACE_BEGIN();

  // --------------------------------------------------------------
  // - Initialisation
  // --------------------------------------------------------------

  // --- Find space in bmp table ----------------------------------
  NoBmp = zbmp_findfreeindex();  
  if (NoBmp==0)
    MI_TRACE_RETURN(CE_OK);

  // --- Find file ------------------------------------------------
  strcpy(Path,CI_SYSTEMIMAGE_PATH);
  Index = FindNextScrSv( FileName, 0, Path);
  if ((Index==0) && (g_pApp->PathLook!=NULL))
    {
    strcpy(Path,g_pApp->PathLook);
    Index = FindNextScrSv( FileName, 0, Path);
    }

  if (Index==0)
    MI_TRACE_RETURN(CE_OK);

  // --- Find timing in zini file ---------------------------------
  ToolsGetZiniKey(Buf, CI_ZINI_SCRSV_TIME, 3, FALSE);
  if (Buf[0]!='\0')
    {
    sscanf(Buf,"%u",&TimeSwap);
    if (TimeSwap < 2)
      TimeSwap = 2;
    }

  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"%u"  ,TimeSwap));
  MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"'%s'",FileName));

  // --------------------------------------------------------------
  // - Process
  // --------------------------------------------------------------

  zSysPush_Internal( 1, 1, screencols, screenlins, 0 );

  flush_mimo();

  while (mimo_kbhit())
    mimo_getch();

  disable_mouse_move();

  do
    {
    // --- Display ------------------------------------------------
    if (zbmp_load(NoBmp,FileName,FALSE))
      {
      SysHide();
      SetChangeFlag();
      zwin_bmp( NoBmp, 1, 1, screencols, screenlins );
      SysShow();

      Cpt = TimeSwap * 2;
      do
        {
        MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"%u",Cpt));
        Cpt--;
        SysWait(5);

        if (Cpt==0)
          GotoNextScreen = TRUE;
          
        if (mimo_kbhit())
          {
          MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"avant mimo_getch"));
          mimo_getch();
          MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"apres mimo_getch"));
          GotoNextScreen = FALSE;
          Cpt=0;
          }
        }
      while (Cpt!=0);

      zbmp_free(NoBmp);
      }
    
    // --- Find next image ----------------------------------------
    if (GotoNextScreen)
      {
      Index = FindNextScrSv( FileName, Index, Path);
      MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"'%s'",FileName));
      if (Index==0)
        {
        Index = FindNextScrSv( FileName, 0, Path);
        GotoNextScreen = (Index!=0);
        }
      }
    }
  while (GotoNextScreen);

  enable_mouse_move();
  zSysPop_Internal();

MI_TRACE_RETURN(CE_OK);

#endif
}

