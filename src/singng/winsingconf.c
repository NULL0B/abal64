/*
 *	Fichier : winsingconf.c
 */

#include <Shlwapi.h>

void * allocate(unsigned int size);

#define REG_VAL_identity     		"RT_visualIdentity"    
#define REG_VAL_exa_program 		"RT_runtimeToolName"   
#define REG_VAL_exadb_program		"RT_debugToolName"     
#define REG_VAL_recordscript 		"RT_eventRecord"       
#define REG_VAL_replayscript 		"RT_eventReplay"       
#define REG_VAL_printer			"RT_printerAt"         

#define REG_VAL_amake_program		"AMAKE_abalToolName"   
#define REG_VAL_amake_options 		"AMAKE_abalOptions"    
#define REG_VAL_amake_define		"AMAKE_abalDefineList" 
#define REG_VAL_amake_path    		"AMAKE_abalIncludeList"

#define REG_VAL_stylepath 		"VIS_visualStylePath"  
#define REG_VAL_componentpath 		"VIS_visualComponentPath"  
#define REG_VAL_imagepath 		"VIS_visualImagePath"  
#define REG_VAL_iconpath  		"VIS_visualIconPath"   
#define REG_VAL_palette  		"VIS_visualPalette"    
#define REG_VAL_skin     		"VIS_visualSkin"       
#define REG_VAL_triggerstyle 		"VIS_visualTrigger"    
#define REG_VAL_triggercolour		"VIS_abalTextColour"   

#define REG_VAL_fontpath 		"VIS_visualFontPath"   
#define REG_VAL_fontname0 		"VIS_visualFont1"      
#define REG_VAL_fontname1 		"VIS_visualFont2"      
#define REG_VAL_fontname2 		"VIS_visualFont3"      
#define REG_VAL_fontname3 		"VIS_visualFont4"      
#define REG_VAL_fontname4 		"VIS_visualFont5"      
#define REG_VAL_fontname5 		"VIS_visualFont6"      
#define REG_VAL_fontname6 		"VIS_visualFont7"      
#define REG_VAL_fontname7 		"VIS_visualFont8"      
#define REG_VAL_fontname8 		"VIS_visualFont9"      
#define REG_VAL_fontname9 		"VIS_visualFont10"     

#define REG_VAL_density  		"VIS_printDensity"     
#define REG_VAL_papersize   		"VIS_paperSize"        
#define REG_VAL_layout      		"VIS_pageLayout"       
#define REG_VAL_pagefeed    		"VIS_pageFeed"         

#define REG_VAL_atr_program 		"ATR_abalToolName"     
#define REG_VAL_atr_path 		"ATR_abalIncludeList"  
#define REG_VAL_atr_define		"ATR_abalDefineList"   
#define REG_VAL_atr_options 		"ATR_abalOptions"      
#define REG_VAL_ald_program		"ALD_abalToolName"     
#define REG_VAL_ald_path 		"ALD_abalIncludeList"  
#define REG_VAL_ald_options		"ALD_abalOptions"      

#define REG_VAL_otr_program 		"OTR_abalToolName"     
#define REG_VAL_otr_path 		"OTR_abalIncludeList"  
#define REG_VAL_otr_define		"OTR_abalDefineList"   
#define REG_VAL_otr_options 		"OTR_abalOptions"      
#define REG_VAL_old_program		"OLD_abalToolName"     
#define REG_VAL_old_path 		"OLD_abalIncludeList"  
#define REG_VAL_old_options		"OLD_abalOptions"      

#ifdef ABALCPP	/* GWB le 16/11/2007 */
#define REG_VAL_cpp_program 		"CPP_cppToolName"     
#define REG_VAL_cpp_path 		"CPP_cppIncludeList"  
#define REG_VAL_cpp_define		"CPP_cppDefineList"   
#define REG_VAL_cpp_options 		"CPP_cppOptions"      
#define REG_VAL_lpp_program		"LPP_cppToolName"     
#define REG_VAL_lpp_path 		"LPP_cppIncludeList"  
#define REG_VAL_lpp_options		"LPP_cppOptions" 
#define REG_VAL_lpp_define		"LPP_cppDefineList" 

#define REG_VAL_dll_cpp_program 	"CPP_DLL_cppToolName"     
#define REG_VAL_dll_cpp_path 		"CPP_DLL_cppIncludeList"  
#define REG_VAL_dll_cpp_define		"CPP_DLL_cppDefineList"   
#define REG_VAL_dll_cpp_options 	"CPP_DLL_cppOptions"      
#define REG_VAL_dll_lpp_program		"LPP_DLL_cppToolName"     
#define REG_VAL_dll_lpp_path 		"LPP_DLL_cppIncludeList"  
#define REG_VAL_dll_lpp_options		"LPP_DLL_cppOptions" 
#define REG_VAL_dll_lpp_define		"CPP_DLL_lppDefineList" 
#endif

#define REG_VAL_docpath  		"HTML_documentPath"        
#define REG_VAL_title 			"HTML_documentPageTitle"   
#define REG_VAL_logo  			"HTML_documentPageLogo"    
#define REG_VAL_copyright 		"HTML_documentCopyright"   
#define REG_VAL_screenstyle 		"HTML_documentScreenStyle" 
#define REG_VAL_printstyle 		"HTML_documentPrintStyle"  
#define REG_VAL_navigator  		"HTML_documentNavigator"   

#define REG_VAL_aed_program 		"AED_abalToolName"         
#define REG_VAL_aed_font    		"AED_abalFontNumber"       
#define REG_VAL_aed_normal   		"AED_abalTextColour"       
#define REG_VAL_aed_string   		"AED_abalStringColour"     
#define REG_VAL_aed_keyword  		"AED_abalKeywordColour"    
#define REG_VAL_aed_comment  		"AED_abalCommentColour"    
#define REG_VAL_aed_punctuation		"AED_abalPunctuationColour"
#define REG_VAL_aed_abalOptions  	"AED_abalOptions"

#define REG_VAL_expert_user		"GEN_expertUser"

public	void	drop_configuration();
public	void	check_configuration();
private	int	allocate_configuration();

// **************************************************************************************************
// FCT ExtractPathToken
// **************************************************************************************************
int ExtractPathToken( char* MonoPath, const char* MultiPath, int iToken )
{
	char  seps[]   = ";,";
	int   i = 0;
	int   Size = 0;
	char* ptr;
	char* token;

	ptr = allocate_string((char*)MultiPath);

   token = strtok( ptr, seps );
   while(token != NULL)
   {
		if (i==iToken)
			break;
      token = strtok( NULL, seps );
		i++;
   }

	if (token)
	{
		strcpy(MonoPath,token);
		Size = strlen(MonoPath);
		if ((Size) && (MonoPath[Size-1]!='\\'))
		{
			strcat(MonoPath,"\\");
			Size++;
		}
	}
	else
		strcpy(MonoPath,"");

	liberate(ptr);
	return Size;
}

// **************************************************************************************************
// FCT ShortNameAllTokens
// **************************************************************************************************
int ShortNameAllTokens( char* MultiShortPath, const char* MultiLongPath)
{
	char  seps[]   = ";,";
	int   Size = 0;
	char* ptr;
	char* token;

	ptr = allocate_string((char*)MultiLongPath);
	MultiShortPath[0]='\0';

   token = strtok( ptr, seps );
   while(token != NULL)
   {
		GetShortPathName( token, token, strlen(token) );
		strcat(MultiShortPath,token);

		Size = strlen(MultiShortPath);
		if ((Size) && (MultiShortPath[Size-1]!='\\'))
			strcat(MultiShortPath,"\\");

		strcat(MultiShortPath,";");

      token = strtok( NULL, seps );
   }

	Size = strlen(MultiShortPath);

	if ((Size) && (MultiShortPath[Size-1]==';'))
	{
		MultiShortPath[Size-1]='\0';
		Size--;
	}

	liberate(ptr);
	return Size;
}

// **************************************************************************************************
// * Win_load_configuration_item
// **************************************************************************************************
static	char * 	Win_load_configuration_item( char* Value, char* DefaultValue)
{
	static char buf[1024];
	LONG	 Size;
	char*	 ptr;

	if (DefaultValue)
		Size = GetRegistryString(REG_SING_CONTEXT_KEY, Value, DefaultValue, buf, sizeof(buf));
	else
		Size = GetRegistryString(REG_SING_CONTEXT_KEY, Value, "", buf, sizeof(buf));

	if (Size)
	{
		ptr = allocate(Size+1);
		strcpy(ptr,buf);
		return ptr;
	}
	else
		return NULL;
}

// **************************************************************************************************
// * Win_load_configuration_word
// **************************************************************************************************
static int 	Win_load_configuration_word( char* Value, int DefaultValue)
{
	return GetRegistryInt(REG_SING_CONTEXT_KEY, Value, DefaultValue);
}


// **************************************************************************************************
// * WinInitSingConf
// * Si la clé n'existe pas, création et remplissage
// **************************************************************************************************
int WinIsSingConfFile( const char* rootname)
{
	FILE*  h;
	char* nptr;

	if (!(  nptr = allocate( strlen( rootname ) + 16 ) ))
		return( 27 );
	
	sprintf(nptr,"%s.cfg",rootname);

	h = fopen( nptr, "r");
	if (h)
		fclose(h);
	liberate(nptr);

	return (h) ?  0 : 40;
}

// **************************************************************************************************
// * WinLoadSingconf
// **************************************************************************************************
int WinLoadSingconf( char* rootname, int verbose)
{
	char* nptr;
	char* buf;
	char* ptr;
	static char RuntimePath[256];
	static char WabalPath[256];
	static char DevBinPath[256];
	static char IncludePath[256];
	static char HelpPath[256];
	static char TmpPath[256];
	LONG        Size;
	char* tmp;

	/* Valeurs par défaut des chemins */
	/* ------------------------------ */

	GetRegistryStringEx(REG_LOCAL_MACHINE, REG_RUNTIME_ROOT_KEY, NULL, REG_PATH_VAL, "", RuntimePath, 256);
	GetRegistryStringEx(REG_LOCAL_MACHINE, REG_WABAL_ROOT_KEY, NULL, REG_PATH_VAL, "", WabalPath, 256);
	strcpy(DevBinPath,WabalPath);
	strcat(DevBinPath,"dev\\bin\\");

	/* Répertoires d'inclusion pour Traduction et Liens */

	strcpy(IncludePath, WabalPath);
	strcat(IncludePath, "dev\\include\\");
	ShortNameAllTokens( IncludePath, IncludePath);

	/* Ajoute le chemin de Criteria (pour Modext)
	   Recherche par priorité en l'absence d'une clé unique indépendante de la nature et de la version de Criteria
	   (on suppose qu'il n'y a qu'un seul Criteria installé).
	*/
	if (!GetRegistryStringEx(REG_LOCAL_MACHINE, REG_CRI_PERS_OPEN_CRITERIA_KEY, NULL, REG_PATH_VAL, "", TmpPath, 256))
		if (!GetRegistryStringEx(REG_LOCAL_MACHINE, REG_CRI_OPEN_CRITERIA_CS_KEY, NULL, REG_PATH_VAL, "", TmpPath, 256))
			GetRegistryStringEx(REG_LOCAL_MACHINE, REG_CRI_OPEN_CRITERIA_CS_FOR_TS_KEY, NULL, REG_PATH_VAL, "", TmpPath, 256);

	if (strlen(TmpPath)) {
		ShortNameAllTokens(TmpPath, TmpPath);
		strcat(IncludePath, ";");
		strcat(IncludePath, TmpPath);
		}

	/* Ajoute le chemin des classes */
	strcpy(TmpPath, WabalPath);
	strcat(TmpPath, "dev\\class\\");
	ShortNameAllTokens(TmpPath, TmpPath);
	if (strlen(TmpPath)) {
		ShortNameAllTokens(TmpPath, TmpPath);
		strcat(IncludePath, ";");
		strcat(IncludePath, TmpPath);
		}

	strcpy(HelpPath, WabalPath);
	strcat(HelpPath, "help\\abal3\\");

	/*
	 * Essai en lisant dans la clé de Wabal
	 *
	GetRegistryStringEx(REG_CURRENT_USER, REG_WABAL_ROOT_KEY, "Directories", "Bin Dirs", "", DevBinPath, 256);
	ExtractPathToken( DevBinPath, DevBinPath, 0 );

	GetRegistryStringEx(REG_CURRENT_USER, REG_WABAL_ROOT_KEY,"Directories", "Include Dirs", "", IncludePath, 256);
	ShortNameAllTokens( IncludePath, IncludePath);

	Size = GetRegistryStringEx(REG_CURRENT_USER, REG_WABAL_ROOT_KEY,"Directories", "Help Dirs", "", HelpPath, 256);
	if (Size)
	{
		ExtractPathToken( HelpPath, HelpPath, 0 );
		strcat(HelpPath,"Abal3\\");
	}
	*/

	nptr = allocate_string( rootname );
	drop_configuration();	
	allocate_configuration();
	SingConf->filename 	= nptr;

	/* runtime configuration parameters */
	/* -------------------------------- */
	SingConf->identity     		= Win_load_configuration_item( REG_VAL_identity      , "Sing default" );

	strcpy(TmpPath,RuntimePath);
	strcat(TmpPath,"wexa\\wexa.exe");
	SingConf->exa.program 		= Win_load_configuration_item( REG_VAL_exa_program   , TmpPath );

	//strcpy(TmpPath,RuntimePath);
	//strcat(TmpPath,"wexa\\wabaldb.exe");
	strcpy(TmpPath,DevBinPath);
	strcat(TmpPath,"wabaldb.exe");
	SingConf->exadb.program		= Win_load_configuration_item( REG_VAL_exadb_program , TmpPath );

	SingConf->recordscript 		= Win_load_configuration_item( REG_VAL_recordscript  , NULL );
	SingConf->replayscript 		= Win_load_configuration_item( REG_VAL_replayscript  , NULL );
	SingConf->printer				= Win_load_configuration_item( REG_VAL_printer       , "printer.at");

	/* runtime configuration parameters */
	/* -------------------------------- */
	strcpy(TmpPath,DevBinPath);
	strcat(TmpPath,"wamake.exe");
	SingConf->amake.program		= Win_load_configuration_item( REG_VAL_amake_program  , TmpPath );
	SingConf->amake.options 	= Win_load_configuration_item( REG_VAL_amake_options  , "-b -d" );
	SingConf->amake.define		= Win_load_configuration_item( REG_VAL_amake_define   , NULL );
	SingConf->amake.path    	= Win_load_configuration_item( REG_VAL_amake_path     , "amake.tmp" );

	/* visual  configuration parameters */
	/* -------------------------------- */

	SingConf->imagepath 		= Win_load_configuration_item( REG_VAL_imagepath     , NULL );
	SingConf->iconpath  		= Win_load_configuration_item( REG_VAL_iconpath      , NULL );
	SingConf->stylepath 		= Win_load_configuration_item( REG_VAL_stylepath     , NULL );
	SingConf->componentpath		= Win_load_configuration_item( REG_VAL_componentpath , NULL );

	/*FCH_SING "standard.rgb" obligatoire, sinon plantage lors d'une production */
	/*FCH21032006 si on met " " ça produit un source qui utilise la palette GIGOPALETTE à l'exécution */
	SingConf->palette  		= Win_load_configuration_item( REG_VAL_palette       , " " /*"standard.rgb"*/ ); 
	SingConf->skin     		= Win_load_configuration_item( REG_VAL_skin          , NULL );
	SingConf->triggerstyle 		= Win_load_configuration_word( REG_VAL_triggerstyle  , SingConf->triggerstyle  );
	SingConf->triggercolour		= Win_load_configuration_word( REG_VAL_triggercolour , SingConf->triggercolour );

	strcpy(TmpPath,RuntimePath);
	strcat(TmpPath,"fonts\\");
	GetShortPathName( TmpPath, TmpPath, strlen(TmpPath) );
	SingConf->fontpath 		= Win_load_configuration_item( REG_VAL_fontpath      , TmpPath );
	SingConf->fontname[0] 		= Win_load_configuration_item( REG_VAL_fontname0     , "standard.fmf"  );
	SingConf->fontname[1] 		= Win_load_configuration_item( REG_VAL_fontname1     , "arial2.fmf"  );
	SingConf->fontname[2] 		= Win_load_configuration_item( REG_VAL_fontname2     , "arial3.fmf"  );
	SingConf->fontname[3] 		= Win_load_configuration_item( REG_VAL_fontname3     , "arial4.fmf"  );
	SingConf->fontname[4] 		= Win_load_configuration_item( REG_VAL_fontname4     , "arial5.fmf"  );
	SingConf->fontname[5] 		= Win_load_configuration_item( REG_VAL_fontname5     , "arial6.fmf"  );
	SingConf->fontname[6] 		= Win_load_configuration_item( REG_VAL_fontname6     , "book1.fmf"  );
	SingConf->fontname[7] 		= Win_load_configuration_item( REG_VAL_fontname7     , "font8.fmf"  );
	SingConf->fontname[8] 		= Win_load_configuration_item( REG_VAL_fontname8     , "font9.fmf"  );
	SingConf->fontname[9] 		= Win_load_configuration_item( REG_VAL_fontname9     , "font10.fmf" );

	SingConf->density  		= Win_load_configuration_word( REG_VAL_density       , SingConf->density   );
	SingConf->papersize   		= Win_load_configuration_word( REG_VAL_papersize     , SingConf->papersize );
	SingConf->layout      		= Win_load_configuration_word( REG_VAL_layout        , SingConf->layout    );
	SingConf->pagefeed    		= Win_load_configuration_word( REG_VAL_pagefeed      , SingConf->pagefeed  );

	/* abal    configuration parameters */
	/* -------------------------------- */
	strcpy(TmpPath,DevBinPath);
	strcat(TmpPath,"wotr32.exe");
	SingConf->atr.program 		= Win_load_configuration_item( REG_VAL_atr_program  , TmpPath );
	SingConf->atr.path 		= Win_load_configuration_item( REG_VAL_atr_path     , IncludePath );
	SingConf->atr.define		= Win_load_configuration_item( REG_VAL_atr_define   , NULL );
	SingConf->atr.options 		= Win_load_configuration_item( REG_VAL_atr_options  , "OMT" );

	strcpy(TmpPath,DevBinPath);
	strcat(TmpPath,"wold.exe");
	SingConf->ald.program		= Win_load_configuration_item( REG_VAL_ald_program  , TmpPath );
	SingConf->ald.path 		= Win_load_configuration_item( REG_VAL_ald_path     , IncludePath );
	SingConf->ald.options		= Win_load_configuration_item( REG_VAL_ald_options  , "M" );

	strcpy(TmpPath,DevBinPath);
	strcat(TmpPath,"wotr32.exe");
	SingConf->otr.program 		= Win_load_configuration_item( REG_VAL_otr_program  , TmpPath );
	SingConf->otr.path 		= Win_load_configuration_item( REG_VAL_otr_path     , IncludePath );
	SingConf->otr.define		= Win_load_configuration_item( REG_VAL_otr_define   , NULL );
	SingConf->otr.options 		= Win_load_configuration_item( REG_VAL_otr_options  , "OMT" );

	strcpy(TmpPath,DevBinPath);
	strcat(TmpPath,"wold.exe");
	SingConf->old.program		= Win_load_configuration_item( REG_VAL_old_program  , TmpPath );
	SingConf->old.path 		= Win_load_configuration_item( REG_VAL_old_path     , IncludePath );
	SingConf->old.options		= Win_load_configuration_item( REG_VAL_old_options  , "M" );

#ifdef ABALCPP	/* GWB le 16/11/2007 */
	/* C++    configuration parameters */
	/* ------------------------------- */
	strcpy(TmpPath,"c:\\program files\\Microsoft Visual Studio\\vc98\\Bin\\");
	strcat(TmpPath,"Cl.exe");
	SingConf->cpp.program 		= Win_load_configuration_item( REG_VAL_cpp_program  , TmpPath );
	SingConf->cpp.path 		= Win_load_configuration_item( REG_VAL_cpp_path     , IncludePath );
	SingConf->cpp.define		= Win_load_configuration_item( REG_VAL_cpp_define   , NULL );
	SingConf->cpp.options 		= Win_load_configuration_item( REG_VAL_cpp_options  , "/nologo /ML /W3 /GX /O2 /D WIN32 /D NDEBUG /D _WINDOWS /D _MBCS /YX /FD /c" );

	strcpy(TmpPath,"c:\\program files\\Microsoft Visual Studio\\vc98\\Bin\\");
	strcat(TmpPath,"link.exe");
	SingConf->lpp.program		= Win_load_configuration_item( REG_VAL_lpp_program  , TmpPath );
	SingConf->lpp.path 		= Win_load_configuration_item( REG_VAL_lpp_path     , IncludePath );
	SingConf->lpp.options		= Win_load_configuration_item( REG_VAL_lpp_options  , "/nologo /subsystem:windows /incremental:no /machine:I386 /pdbtype:sept /NODEFAULTLIB:libcd /NODEFAULTLIB:libcmtd" );
	SingConf->lpp.define		= Win_load_configuration_item( REG_VAL_lpp_define   , "kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib libsing.lib winmm.lib ddraw.lib wsing.res" );

	/* DLL C++    configuration parameters */
	/* ----------------------------------- */
	strcpy(TmpPath,"c:\\program files\\Microsoft Visual Studio\\vc98\\Bin\\");
	strcat(TmpPath,"Cl.exe");
	SingConf->dll_cpp.program 	= Win_load_configuration_item( REG_VAL_dll_cpp_program  , TmpPath );
	SingConf->dll_cpp.path 		= Win_load_configuration_item( REG_VAL_dll_cpp_path     , IncludePath );
	SingConf->dll_cpp.define	= Win_load_configuration_item( REG_VAL_dll_cpp_define   , NULL );
	SingConf->dll_cpp.options 	= Win_load_configuration_item( REG_VAL_dll_cpp_options  , "/nologo /MTd /W3 /Gm /GX /ZI /Od /D WIN32 /D _DEBUG /D _WINDOWS /D _MBCS /D _USRDLL /D TESTC_EXPORTS /D TRACEON /D VERSION666 /D ABAL32A /D ABAL33A /D ABALCPP /D EXPORT_LIBRARY /YX /FD /GZ /c" );

	strcpy(TmpPath,"c:\\program files\\Microsoft Visual Studio\\vc98\\Bin\\");
	strcat(TmpPath,"link.exe");
	SingConf->dll_lpp.program	= Win_load_configuration_item( REG_VAL_dll_lpp_program  , TmpPath );
	SingConf->dll_lpp.path 		= Win_load_configuration_item( REG_VAL_dll_lpp_path     , IncludePath );
	SingConf->dll_lpp.options	= Win_load_configuration_item( REG_VAL_dll_lpp_options  , "/nologo /D _DEBUG /mktyplib203 /win32 /dll /incremental:yes /debug /machine:I386 /pdbtype:sept" );
	SingConf->dll_lpp.define	= Win_load_configuration_item( REG_VAL_dll_lpp_define   , "kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib vclass.obj singrelais.obj" );
#endif
	/* html    configuration parameters */
	/* -------------------------------- */
	SingConf->docpath  		= Win_load_configuration_item( REG_VAL_docpath     , HelpPath );
	SingConf->title 		= Win_load_configuration_item( REG_VAL_title       , NULL );
	SingConf->logo  		= Win_load_configuration_item( REG_VAL_logo        , NULL );
	SingConf->copyright 		= Win_load_configuration_item( REG_VAL_copyright   , NULL );
	SingConf->screenstyle 		= Win_load_configuration_item( REG_VAL_screenstyle , NULL );
	SingConf->printstyle 		= Win_load_configuration_item( REG_VAL_printstyle  , NULL );
	SingConf->navigator  		= Win_load_configuration_item( REG_VAL_navigator   , NULL );

	/* aed     configuration parameters */
	/* -------------------------------- */
	SingConf->aed.program 		= Win_load_configuration_item( REG_VAL_aed_program     , "!aed32" );
	SingConf->aed.font    		= Win_load_configuration_word( REG_VAL_aed_font        , SingConf->aed.font   );
	SingConf->aed.normal   		= Win_load_configuration_word( REG_VAL_aed_normal      , SingConf->aed.normal );
	SingConf->aed.string   		= Win_load_configuration_word( REG_VAL_aed_string      , SingConf->aed.string );
	SingConf->aed.keyword  		= Win_load_configuration_word( REG_VAL_aed_keyword     , SingConf->aed.keyword);
	SingConf->aed.comment  		= Win_load_configuration_word( REG_VAL_aed_comment     , SingConf->aed.comment);
	SingConf->aed.punctuation	= Win_load_configuration_word( REG_VAL_aed_punctuation , SingConf->aed.punctuation);

	if ((buf = Win_load_configuration_item(REG_VAL_aed_abalOptions,NULL)) != (char *) 0) 
	{
		ptr = buf;
		if ( *(ptr++) == 'T' )
			SingConf->aed.usecolour	= 1;
		else	SingConf->aed.usecolour	= 0;
		if ( *(ptr++) == 'T' )
			SingConf->aed.state	= 1;
		else	SingConf->aed.state	= 0;
		liberate(buf);
	}

	/* other   configuration parameters */
	/* -------------------------------- */
	SingConf->expert_user = Win_load_configuration_word( REG_VAL_expert_user, SingConf->expert_user );

	check_configuration();

return 0;
}

// **************************************************************************************************
// * WinSaveSingconf 
// **************************************************************************************************
int WinSaveSingconf( char* rootname, int verbose)
{
	char* KeyName;
	char	obuffer[16];

	KeyName = REG_SING_CONTEXT_KEY;

	/* runtime configuration parameters */
	/* -------------------------------- */
	SetRegistryString(KeyName, REG_VAL_identity     , SingConf->identity      , strlen(SingConf->identity));
	SetRegistryString(KeyName, REG_VAL_exa_program  , SingConf->exa.program   , strlen(SingConf->exa.program));
	SetRegistryString(KeyName, REG_VAL_exadb_program, SingConf->exadb.program , strlen(SingConf->exadb.program));
	SetRegistryString(KeyName, REG_VAL_recordscript , SingConf->recordscript  , strlen(SingConf->recordscript));
	SetRegistryString(KeyName, REG_VAL_replayscript , SingConf->replayscript  , strlen(SingConf->replayscript));
	SetRegistryString(KeyName, REG_VAL_printer      , SingConf->printer       , strlen(SingConf->printer));

	/* runtime configuration parameters */
	/* -------------------------------- */
	SetRegistryString(KeyName, REG_VAL_amake_program, SingConf->amake.program , strlen(SingConf->amake.program));
	SetRegistryString(KeyName, REG_VAL_amake_options, SingConf->amake.options , strlen(SingConf->amake.options));
	SetRegistryString(KeyName, REG_VAL_amake_define , SingConf->amake.define  , strlen(SingConf->amake.define));
	SetRegistryString(KeyName, REG_VAL_amake_path   , SingConf->amake.path    , strlen(SingConf->amake.path));

	/* visual  configuration parameters */
	/* -------------------------------- */
	SetRegistryString(KeyName, REG_VAL_componentpath, SingConf->componentpath , strlen(SingConf->componentpath));
	SetRegistryString(KeyName, REG_VAL_stylepath    , SingConf->stylepath     , strlen(SingConf->stylepath));
	SetRegistryString(KeyName, REG_VAL_imagepath    , SingConf->imagepath     , strlen(SingConf->imagepath));
	SetRegistryString(KeyName, REG_VAL_iconpath     , SingConf->iconpath      , strlen(SingConf->iconpath));
	SetRegistryString(KeyName, REG_VAL_palette      , SingConf->palette       , strlen(SingConf->palette));
	SetRegistryString(KeyName, REG_VAL_skin         , SingConf->skin          , strlen(SingConf->skin));
	SetRegistryInt   (KeyName, REG_VAL_triggerstyle , SingConf->triggerstyle  );
	SetRegistryInt   (KeyName, REG_VAL_triggercolour, SingConf->triggercolour );

	SetRegistryString(KeyName, REG_VAL_fontpath     , SingConf->fontpath      , strlen(SingConf->fontpath));
	SetRegistryString(KeyName, REG_VAL_fontname0    , SingConf->fontname[0]   , strlen(SingConf->fontname[0]));
	SetRegistryString(KeyName, REG_VAL_fontname1    , SingConf->fontname[1]   , strlen(SingConf->fontname[1]));
	SetRegistryString(KeyName, REG_VAL_fontname2    , SingConf->fontname[2]   , strlen(SingConf->fontname[2]));
	SetRegistryString(KeyName, REG_VAL_fontname3    , SingConf->fontname[3]   , strlen(SingConf->fontname[3]));
	SetRegistryString(KeyName, REG_VAL_fontname4    , SingConf->fontname[4]   , strlen(SingConf->fontname[4]));
	SetRegistryString(KeyName, REG_VAL_fontname5    , SingConf->fontname[5]   , strlen(SingConf->fontname[5]));
	SetRegistryString(KeyName, REG_VAL_fontname6    , SingConf->fontname[6]   , strlen(SingConf->fontname[6]));
	SetRegistryString(KeyName, REG_VAL_fontname7    , SingConf->fontname[7]   , strlen(SingConf->fontname[7]));
	SetRegistryString(KeyName, REG_VAL_fontname8    , SingConf->fontname[8]   , strlen(SingConf->fontname[8]));
	SetRegistryString(KeyName, REG_VAL_fontname9    , SingConf->fontname[9]   , strlen(SingConf->fontname[9]));

	SetRegistryInt   (KeyName, REG_VAL_density      , SingConf->density  );
	SetRegistryInt   (KeyName, REG_VAL_papersize    , SingConf->papersize  );
	SetRegistryInt   (KeyName, REG_VAL_layout       , SingConf->layout  );
	SetRegistryInt   (KeyName, REG_VAL_pagefeed     , SingConf->pagefeed  );

	/* abal    configuration parameters */
	/* -------------------------------- */
	SetRegistryString(KeyName, REG_VAL_atr_program  , SingConf->atr.program   , strlen(SingConf->atr.program));
	SetRegistryString(KeyName, REG_VAL_atr_path     , SingConf->atr.path      , strlen(SingConf->atr.path));
	SetRegistryString(KeyName, REG_VAL_atr_define   , SingConf->atr.define    , strlen(SingConf->atr.define));
	SetRegistryString(KeyName, REG_VAL_atr_options  , SingConf->atr.options   , strlen(SingConf->atr.options));
	SetRegistryString(KeyName, REG_VAL_ald_program  , SingConf->ald.program   , strlen(SingConf->ald.program));
	SetRegistryString(KeyName, REG_VAL_ald_path     , SingConf->ald.path      , strlen(SingConf->ald.path));
	SetRegistryString(KeyName, REG_VAL_ald_options  , SingConf->ald.options   , strlen(SingConf->ald.options));

	SetRegistryString(KeyName, REG_VAL_otr_program  , SingConf->otr.program   , strlen(SingConf->otr.program));
	SetRegistryString(KeyName, REG_VAL_otr_path     , SingConf->otr.path      , strlen(SingConf->otr.path));
	SetRegistryString(KeyName, REG_VAL_otr_define   , SingConf->otr.define    , strlen(SingConf->otr.define));
	SetRegistryString(KeyName, REG_VAL_otr_options  , SingConf->otr.options   , strlen(SingConf->otr.options));
	SetRegistryString(KeyName, REG_VAL_old_program  , SingConf->old.program   , strlen(SingConf->old.program));
	SetRegistryString(KeyName, REG_VAL_old_path     , SingConf->old.path      , strlen(SingConf->old.path));
	SetRegistryString(KeyName, REG_VAL_old_options  , SingConf->old.options   , strlen(SingConf->old.options));

	/* html    configuration parameters */
	/* -------------------------------- */
	SetRegistryString(KeyName, REG_VAL_docpath      , SingConf->docpath       , strlen(SingConf->docpath));
	SetRegistryString(KeyName, REG_VAL_title        , SingConf->title         , strlen(SingConf->title));
	SetRegistryString(KeyName, REG_VAL_logo         , SingConf->logo          , strlen(SingConf->logo));
	SetRegistryString(KeyName, REG_VAL_copyright    , SingConf->copyright     , strlen(SingConf->copyright));
	SetRegistryString(KeyName, REG_VAL_screenstyle  , SingConf->screenstyle   , strlen(SingConf->screenstyle));
	SetRegistryString(KeyName, REG_VAL_printstyle   , SingConf->printstyle    , strlen(SingConf->printstyle));
	SetRegistryString(KeyName, REG_VAL_navigator    , SingConf->navigator     , strlen(SingConf->navigator));

#ifdef ABALCPP	/* GWB le 16/11/2007 */
	/* c++    configuration parameters */
	/* ------------------------------- */
	SetRegistryString(KeyName, REG_VAL_cpp_program  , SingConf->cpp.program   , strlen(SingConf->cpp.program));
	SetRegistryString(KeyName, REG_VAL_cpp_path     , SingConf->cpp.path      , strlen(SingConf->cpp.path));
	SetRegistryString(KeyName, REG_VAL_cpp_define   , SingConf->cpp.define    , strlen(SingConf->cpp.define));
	SetRegistryString(KeyName, REG_VAL_cpp_options  , SingConf->cpp.options   , strlen(SingConf->cpp.options));
	SetRegistryString(KeyName, REG_VAL_lpp_program  , SingConf->lpp.program   , strlen(SingConf->lpp.program));
	SetRegistryString(KeyName, REG_VAL_lpp_path     , SingConf->lpp.path      , strlen(SingConf->lpp.path));
	SetRegistryString(KeyName, REG_VAL_lpp_options  , SingConf->lpp.options   , strlen(SingConf->lpp.options));
	SetRegistryString(KeyName, REG_VAL_lpp_define   , SingConf->lpp.define    , strlen(SingConf->lpp.define));

	/* dll C++  configuration parameters */
	/* --------------------------------- */
	SetRegistryString(KeyName, REG_VAL_dll_cpp_program  , SingConf->dll_cpp.program   , strlen(SingConf->dll_cpp.program));
	SetRegistryString(KeyName, REG_VAL_dll_cpp_path     , SingConf->dll_cpp.path      , strlen(SingConf->dll_cpp.path));
	SetRegistryString(KeyName, REG_VAL_dll_cpp_define   , SingConf->dll_cpp.define    , strlen(SingConf->dll_cpp.define));
	SetRegistryString(KeyName, REG_VAL_dll_cpp_options  , SingConf->dll_cpp.options   , strlen(SingConf->dll_cpp.options));
	SetRegistryString(KeyName, REG_VAL_dll_lpp_program  , SingConf->dll_lpp.program   , strlen(SingConf->dll_lpp.program));
	SetRegistryString(KeyName, REG_VAL_dll_lpp_path     , SingConf->dll_lpp.path      , strlen(SingConf->dll_lpp.path));
	SetRegistryString(KeyName, REG_VAL_dll_lpp_options  , SingConf->dll_lpp.options   , strlen(SingConf->dll_lpp.options));
	SetRegistryString(KeyName, REG_VAL_dll_lpp_define   , SingConf->dll_lpp.define    , strlen(SingConf->dll_lpp.define));
#endif

	/* aed     configuration parameters */
	/* -------------------------------- */
	SetRegistryString(KeyName, REG_VAL_aed_program    , SingConf->aed.program   , strlen(SingConf->aed.program));
	SetRegistryInt   (KeyName, REG_VAL_aed_font       , SingConf->aed.font  );
	SetRegistryInt   (KeyName, REG_VAL_aed_normal     , SingConf->aed.normal  );
	SetRegistryInt   (KeyName, REG_VAL_aed_string     , SingConf->aed.string  );
	SetRegistryInt   (KeyName, REG_VAL_aed_keyword    , SingConf->aed.keyword  );
	SetRegistryInt   (KeyName, REG_VAL_aed_comment    , SingConf->aed.comment  );
	SetRegistryInt   (KeyName, REG_VAL_aed_punctuation, SingConf->aed.punctuation  );

	if ( SingConf->aed.usecolour )
		obuffer[0] = 'T';
	else	obuffer[0] = 'F';
		if ( SingConf->aed.usecolour )
			obuffer[1] = 'T';
		else	obuffer[1] = 'F';
			obuffer[2] = 0;
	SetRegistryString(KeyName, REG_VAL_aed_abalOptions, obuffer, strlen(obuffer));

	/* other   configuration parameters */
	/* -------------------------------- */
	SetRegistryInt   (KeyName, REG_VAL_expert_user, SingConf->expert_user  );

return 0;
}

// **************************************************************************************************
// * WinRazSingconf
// **************************************************************************************************
int WinRazSingconf( char* rootname, int verbose)
{
char	SubKey[REG_MAX_KEY]; 

strcpy( SubKey, REG_CONFIG_SING_ROOT_KEY);
strcat( SubKey, REG_SING_CONTEXT_KEY);

SHDeleteKey( HKEY_CURRENT_USER, SubKey );

return 0;
}

