#ifndef	_SINGCONF_C
#define	_SINGCONF_C

#include "singconf.h"

#ifdef WIN32
#include "pubregkey.h"
#include "winsingconf.c"
#endif

#define	_CONF_EDIT	'Ce'
#define	_CONF_SAVE	'Cs'
#define	_CONF_LOAD	'Cl'
#define	_CONF_SAVE_LDAP	'SL'
#define	_CONF_LOAD_LDAP	'LL'
#define	_CONF_WIPE_LDAP	'ZL'
#define	_CONF_QUIT	27
#define	_CONF_EXIT	13

#define	confAdmin "confAdmin"
#define	confStandard "languageAbal"


#define	_SING_LDAP_ROOT " ou=languageAbal, ou=confAdmin"

static	char *	ConfigHost=(char *) 0;
static	char *	ComponentPath=(char *) 0;
static	char	ConfigurationRoot[256];

char *	GetFontVector( char * filename, int	number );
char *	UseFontVector( char * filename );

char *	configuration_rootname()	{ return( ConfigurationRoot ); }

private	void	configuration_init(char * fnptr)
{
	ConfigHost = (char *) 0;
	return;
}

public	char *	get_component_path()
{
	char *	eptr;
	if ( system_components )
		return( system_components );
	else	return( confgetenv("COMPONENTPATH") );
}

public	char *	get_system_editor()
{
	if ( SingConf )
		return( SingConf->aed.program );
	else	return( (char *) 0 );
}

public	char *	get_translator_inclusion()
{
	if ( SingConf )
		return( SingConf->atr.path );
	else	return( (char *) 0 );
}

public	void	editorConfiguration(int language )
{
	editorOnColour( 
		( SingConf->aed.usecolour ? -1 : 0 ),
		SingConf->aed.normal, 
		SingConf->aed.string, 
		SingConf->aed.keyword,
		SingConf->aed.comment, 
		SingConf->aed.punctuation );

	if ( SingConf->aed.usecolour ) {
		switch ( language ) {
			case	_GENERATE_C	:
			case	_GENERATE_CPP	:
				toggle_colour_control('C');
				break;
			case	_GENERATE_BAL	:
			case	_GENERATE_ABAL	:
				toggle_colour_control('A');
				break;
			case	_GENERATE_HTML	:
				toggle_colour_control('H');
				break;
			}
		}
	return;
}

public	void	configuration_fonts()
{
	load_FontTable();
	return;
}


private	char *	duplicate_string(char * rptr, char * sptr )
{
	if (!( sptr ))
		return( rptr );
	else 	{
		if ( rptr )
			liberate( rptr );
		return( allocate_string( sptr ) );
		}
}


public	void	check_configuration()
{
	if (!( SingConf )) {
		system_xml 	=
		system_skin     = 
		system_fontpath = 
		system_stylepath= 
		system_components= 
		system_palette  =
		system_imagepath= (char *) 0;
		}
	else	{
		system_xml	= confgetenv("SINGXML");
		system_skin     = SingConf->skin;
		system_fontpath = duplicate_string( system_fontpath, SingConf->fontpath );
		system_stylepath= duplicate_string( system_stylepath,SingConf->stylepath);
		system_components= duplicate_string( system_components,SingConf->componentpath);
		system_imagepath= duplicate_string( system_imagepath,SingConf->imagepath);
		system_imagepaths=0;
		system_navigator= duplicate_string( system_navigator,SingConf->navigator);
		system_docpath  = duplicate_string( system_docpath,  SingConf->docpath);
		system_palette  = duplicate_string( system_palette,  SingConf->palette);
		editorConfiguration(-1);
		trigger_conf( SingConf->triggerstyle, SingConf->triggercolour );
		configure_makefile();
		configuration_fonts();
		}
	return;
}

public	void	drop_configuration()
{
	if ( SingConf != (struct sing_configuration *) 0) {
		liberate(SingConf->filename);
		liberate(SingConf->identity);
		liberate(SingConf->replayscript);
		liberate(SingConf->recordscript);
		liberate(SingConf->atr.program);
		liberate(SingConf->atr.path);
		liberate(SingConf->atr.define);
		liberate(SingConf->atr.options);
		liberate(SingConf->ald.program);
		liberate(SingConf->ald.path);
		liberate(SingConf->ald.options);
		liberate(SingConf->otr.program);
		liberate(SingConf->otr.path);
		liberate(SingConf->otr.define);
		liberate(SingConf->otr.options);
		liberate(SingConf->old.program);
		liberate(SingConf->old.path);
		liberate(SingConf->old.options);

		liberate(SingConf->cpp.program);
		liberate(SingConf->cpp.path);
		liberate(SingConf->cpp.define);
		liberate(SingConf->cpp.options);

		liberate(SingConf->lpp.program);
		liberate(SingConf->lpp.path);
		liberate(SingConf->lpp.options);
		liberate(SingConf->lpp.define);

		liberate(SingConf->dll_cpp.program);
		liberate(SingConf->dll_cpp.path);
		liberate(SingConf->dll_cpp.define);
		liberate(SingConf->dll_cpp.options);

		liberate(SingConf->dll_lpp.program);
		liberate(SingConf->dll_lpp.path);
		liberate(SingConf->dll_lpp.options);
		liberate(SingConf->dll_lpp.define);

		liberate(SingConf->exa.program);
		liberate(SingConf->exadb.program);
		liberate(SingConf->amake.program);
		liberate(SingConf->amake.path);
		liberate(SingConf->amake.define);
		liberate(SingConf->amake.options);
		liberate(SingConf->aed.program);
		liberate(SingConf->imagepath);
		liberate(SingConf->iconpath);
		liberate(SingConf->palette);
		liberate(SingConf->skin);
		liberate(SingConf->fontpath);
		liberate(SingConf->stylepath);
		liberate(SingConf->componentpath);
		liberate(SingConf->fontname[0]);
		liberate(SingConf->fontname[1]);
		liberate(SingConf->fontname[2]);
		liberate(SingConf->fontname[3]);
		liberate(SingConf->fontname[4]);
		liberate(SingConf->fontname[5]);
 		liberate(SingConf->fontname[6]);
		liberate(SingConf->fontname[7]);
		liberate(SingConf->fontname[8]);
		liberate(SingConf->fontname[9]);
		liberate(SingConf->title);
		liberate(SingConf->logo);
		liberate(SingConf->copyright);
		liberate(SingConf->screenstyle);
		liberate(SingConf->printstyle);
		liberate(SingConf->navigator);
		liberate(SingConf->docpath);
		liberate(SingConf->printer);
		liberate(SingConf);
		SingConf = (struct sing_configuration *) 0;
		check_configuration();
		}
	configuration_drop();
	return;
}
 
private	int	allocate_configuration()
{
	int	i;
	if (!(SingConf = allocate( sizeof( struct sing_configuration ) )))
		return(27);
	else	{
		SingConf->filename		=
		SingConf->identity		=
		SingConf->replayscript		=
		SingConf->recordscript		=
		SingConf->atr.program		=
		SingConf->atr.path		=
		SingConf->atr.define		=
		SingConf->atr.options		=
		SingConf->ald.program		=
		SingConf->ald.path		=
		SingConf->ald.options		=
		SingConf->otr.program		=
		SingConf->otr.path		=
		SingConf->otr.define		=
		SingConf->otr.options		=

		SingConf->cpp.program		=
		SingConf->cpp.path		=
		SingConf->cpp.define		=
		SingConf->cpp.options		=

		SingConf->lpp.program		=
		SingConf->lpp.path		=
		SingConf->lpp.options		=
		SingConf->lpp.define		=

		SingConf->dll_cpp.program	=
		SingConf->dll_cpp.path		=
		SingConf->dll_cpp.define	=
		SingConf->dll_cpp.options	=

		SingConf->dll_lpp.program	=
		SingConf->dll_lpp.path		=
		SingConf->dll_lpp.options	=
		SingConf->dll_lpp.define	=

		SingConf->amake.program		=
		SingConf->amake.path		=
		SingConf->amake.define		=
		SingConf->amake.options		=
		SingConf->old.program		=
		SingConf->old.path		=
		SingConf->old.options		=
		SingConf->exa.program		=
		SingConf->exadb.program		=
		SingConf->aed.program		= (char *) 0;
		SingConf->aed.state  		= 1;
		SingConf->aed.font   		= 1;
		SingConf->aed.usecolour		= 1;
#ifdef WIN32
		SingConf->aed.normal		= 0;
#else
		SingConf->aed.normal		= 10;
#endif
		SingConf->aed.string		= 12;
		SingConf->aed.keyword		=  9;
#ifdef WIN32
		SingConf->aed.comment		= 10;
		SingConf->aed.punctuation	=  8; 
#else
		SingConf->aed.comment		= 11;
		SingConf->aed.punctuation	=  0;
#endif
		SingConf->imagepath		=
		SingConf->iconpath		=
		SingConf->palette		=
		SingConf->skin			=
		SingConf->componentpath		= 
		SingConf->stylepath		= 
		SingConf->fontpath		= (char *) 0;
		SingConf->triggerstyle		= 2;
		SingConf->triggercolour		= 31;

		for (i=0; i < 10; i++ ) SingConf->fontname[i] = (char *) 0;
		SingConf->title 	= 
		SingConf->logo  	= 
		SingConf->copyright 	= 
		SingConf->screenstyle 	= 
		SingConf->printstyle 	= 
		SingConf->navigator  	= 
		SingConf->docpath  	= 
		SingConf->printer 	= (char *) 0;
#ifdef	ABAL32A
		SingConf->expert_user	= 0;
#else
		SingConf->expert_user	= 0;
#endif
		check_configuration();
		return(0);
		}
}

#define	save_configuration_item( h, v, n ) fprintf(h,"%s=%s\n",n,v)
#define	save_configuration_word( h, v, n ) fprintf(h,"%s=%u\n",n,v)

private	char * 	load_configuration_item( char * nptr )
{
	char * vptr;
	if (!( nptr ))
		return( nptr );
	if (!( vptr = configuration_item(nptr))) 
		return( vptr );
	else	return( allocate_string( vptr ) );
}

#define	load_configuration_word( n ) configuration_integer(n)

public	void	save_configuration( char * rootname )
{
	FILE *	h;
	char *	nptr;

	if (!(  nptr = allocate_string( rootname ) ))
		return;
	else if (!( nptr = enforce_extension( nptr, ".cfg" ) ))
		return;
	else if (!( h = fopen(nptr,"w"))) {
		liberate( nptr );
		return;
		}

	save_configuration_item( h, SingConf->identity     ,"IDENTITY"  );
	save_configuration_item( h, SingConf->recordscript ,"RECORD"  );
	save_configuration_item( h, SingConf->replayscript ,"REPLAY"  );
	save_configuration_item( h, SingConf->atr.program ,"ATR"       );
	save_configuration_item( h, SingConf->atr.options ,"ATR.OPTIONS");
	save_configuration_item( h, SingConf->atr.define ,"ATR.DEFINE");
	save_configuration_item( h, SingConf->atr.path ,"ATR.INCLUDE");
	save_configuration_item( h, SingConf->ald.program  ,"ALD"       );
	save_configuration_item( h, SingConf->ald.path ,"ALD.INCLUDE");
	save_configuration_item( h, SingConf->ald.options  ,"ALD.OPTIONS");
	save_configuration_item( h, SingConf->otr.program  ,"OTR"       );
	save_configuration_item( h, SingConf->otr.options  ,"OTR.OPTIONS");
	save_configuration_item( h, SingConf->otr.path  ,"OTR.INCLUDE");
	save_configuration_item( h, SingConf->otr.define ,"OTR.DEFINE");

	save_configuration_item( h, SingConf->cpp.program ,"CPP"       );
	save_configuration_item( h, SingConf->cpp.options ,"CPP.OPTIONS");
	save_configuration_item( h, SingConf->cpp.define ,"CPP.DEFINE");
	save_configuration_item( h, SingConf->cpp.path ,"CPP.INCLUDE");

	save_configuration_item( h, SingConf->lpp.program ,"LPP"       );
	save_configuration_item( h, SingConf->lpp.options ,"LPP.OPTIONS");
	save_configuration_item( h, SingConf->lpp.path ,"LPP.INCLUDE");
	save_configuration_item( h, SingConf->lpp.define ,"LPP.DEFINE");

	save_configuration_item( h, SingConf->dll_cpp.program ,"DLL_CPP"       );
	save_configuration_item( h, SingConf->dll_cpp.options ,"DLL_CPP.OPTIONS");
	save_configuration_item( h, SingConf->dll_cpp.define ,"DLL_CPP.DEFINE");
	save_configuration_item( h, SingConf->dll_cpp.path ,"DLL_CPP.INCLUDE");

	save_configuration_item( h, SingConf->dll_lpp.program ,"DLL_LPP"       );
	save_configuration_item( h, SingConf->dll_lpp.options ,"DLL_LPP.OPTIONS");
	save_configuration_item( h, SingConf->dll_lpp.path ,"DLL_LPP.INCLUDE");
	save_configuration_item( h, SingConf->dll_lpp.define ,"DLL_LPP.DEFINE");

	save_configuration_item( h, SingConf->amake.program  ,"AMAKE"       );
	save_configuration_item( h, SingConf->amake.options  ,"AMAKE.OPTIONS");
	save_configuration_item( h, SingConf->amake.define ,"AMAKE.DEFINE");
	save_configuration_item( h, SingConf->amake.path   ,"AMAKE.LIST");
	save_configuration_item( h, SingConf->old.program  ,"OLD"       );
	save_configuration_item( h, SingConf->old.path ,"OLD.INCLUDE");
	save_configuration_item( h, SingConf->old.options  ,"OLD.OPTIONS");
	save_configuration_item( h, SingConf->exa.program ,"EXA"       );
	save_configuration_item( h, SingConf->exadb.program,"EXADB"     );
	save_configuration_item( h, SingConf->imagepath ,"IMAGEPATH" );
	save_configuration_item( h, SingConf->iconpath  ,"ICONPATH"  );
	save_configuration_item( h, SingConf->palette  ,"PALETTE"   );
	save_configuration_item( h, SingConf->skin     ,"SKIN"      );
	save_configuration_word( h, SingConf->triggerstyle ,"TRIGGER.STYLE" );
	save_configuration_word( h, SingConf->triggercolour,"TRIGGER.COLOUR" );
	save_configuration_item( h, SingConf->fontpath ,"FONTPATH"  );
	save_configuration_item( h, SingConf->stylepath ,"STYLEPATH"  );
	save_configuration_item( h, SingConf->componentpath ,"COMPONENTPATH"  );
	save_configuration_item( h, GetFontVector(SingConf->fontname[0],1)  ,"FONT1"  );
	save_configuration_item( h, GetFontVector(SingConf->fontname[1],2)  ,"FONT2"  );
	save_configuration_item( h, GetFontVector(SingConf->fontname[2],3)  ,"FONT3"  );
	save_configuration_item( h, GetFontVector(SingConf->fontname[3],4)  ,"FONT4"  );
	save_configuration_item( h, GetFontVector(SingConf->fontname[4],5)  ,"FONT5"  );
	save_configuration_item( h, GetFontVector(SingConf->fontname[5],6)  ,"FONT6"  );
	save_configuration_item( h, GetFontVector(SingConf->fontname[6],7)  ,"FONT7"  );
	save_configuration_item( h, GetFontVector(SingConf->fontname[7],8)  ,"FONT8"  );
	save_configuration_item( h, GetFontVector(SingConf->fontname[8],9)  ,"FONT9"  );
	save_configuration_item( h, GetFontVector(SingConf->fontname[9],10) ,"FONT10"  );
	save_configuration_item( h, SingConf->docpath ,"DOCPATH");
	save_configuration_item( h, SingConf->title ,"HTML.TITLE");
	save_configuration_item( h, SingConf->logo  ,"HTML.LOGO");
	save_configuration_item( h, SingConf->copyright ,"HTML.COPYRIGHT");
	save_configuration_item( h, SingConf->screenstyle ,"SCREEN.CSS");
	save_configuration_item( h, SingConf->printstyle ,"PRINT.CSS");
	save_configuration_item( h, SingConf->navigator  ,"NAVIGATOR");
	save_configuration_item( h, SingConf->printer ,"PRINTER"   );
	save_configuration_word( h, SingConf->density ,"DENSITY"   );
	save_configuration_word( h, SingConf->papersize  ,"PAPERSIZE"   );
	save_configuration_word( h, SingConf->layout ,"LAYOUT"   );
	save_configuration_word( h, SingConf->pagefeed ,"PAGEFEED"   );

	save_configuration_item( h, SingConf->aed.program ,"AED"       );
	save_configuration_word( h, SingConf->aed.state   ,"AED.STATE" );
	save_configuration_word( h, SingConf->aed.font    ,"AED.FONT"  );
	save_configuration_word( h, SingConf->aed.usecolour,"AED.COLOUR"  );
	save_configuration_word( h, SingConf->aed.normal   ,"AED.NORMAL"  );
	save_configuration_word( h, SingConf->aed.string   ,"AED.STRING"  );
	save_configuration_word( h, SingConf->aed.keyword  ,"AED.KEYWORD"  );
	save_configuration_word( h, SingConf->aed.comment  ,"AED.COMMENT"  );
	save_configuration_word( h, SingConf->aed.punctuation,"AED.PUNCTUATE"  );

	if ( SingConf->expert_user ) {
		save_configuration_word( h, SingConf->expert_user ,"EXPERT"  );
		}
	liberate( nptr );
	fclose(h);
	return;
}


/*
 *	L O A D _ C O N F I G U R A T I O N ( name )
 *	--------------------------------------------
 *	Load the configuration file intot the configuration parameter controller.
 *
 */

public	void	load_configuration( char * rootname )
{
	char	*	vptr;
	char 	*	nptr;
	char 	*	filename;

	/* detect existance prior to destruction */
	/* ------------------------------------- */
	if (!( configuration_test( rootname ) )) {
		file_not_found( rootname );
		return;
		}

	rootname = allocate_string( rootname );

	drop_configuration();
	allocate_configuration();

	if ( configuration_load(rootname) != 0 ) configuration_init(rootname);

	SingConf->filename 	= rootname;

	SingConf->identity     	= load_configuration_item( "IDENTITY"  );
	SingConf->recordscript 	= load_configuration_item( "RECORD"  );
	SingConf->replayscript 	= load_configuration_item( "REPLAY"  );

	SingConf->atr.program 	= load_configuration_item( "ATR"       );
	SingConf->atr.options 	= load_configuration_item( "ATR.OPTIONS");
	SingConf->atr.path 	= load_configuration_item( "ATR.INCLUDE");
	SingConf->atr.define	= load_configuration_item( "ATR.DEFINE");
	SingConf->ald.program   = load_configuration_item( "ALD"       );
	SingConf->ald.path 	= load_configuration_item( "ALD.INCLUDE");
	SingConf->ald.options   = load_configuration_item( "ALD.OPTIONS");

	SingConf->otr.program   = load_configuration_item( "OTR"       );
	SingConf->otr.options   = load_configuration_item( "OTR.OPTIONS");
	SingConf->otr.path      = load_configuration_item( "OTR.INCLUDE");
	SingConf->otr.define	= load_configuration_item( "OTR.DEFINE");
	SingConf->old.program   = load_configuration_item( "OLD"       );
	SingConf->old.path 	= load_configuration_item( "OLD.INCLUDE");
	SingConf->old.options   = load_configuration_item( "OLD.OPTIONS");

	SingConf->cpp.program 	= load_configuration_item( "CPP"       );
	SingConf->cpp.options 	= load_configuration_item( "CPP.OPTIONS");
	SingConf->cpp.path 	= load_configuration_item( "CPP.INCLUDE");
	SingConf->cpp.define	= load_configuration_item( "CPP.DEFINE");

	SingConf->lpp.program   = load_configuration_item( "LPP"       );
	SingConf->lpp.path 	= load_configuration_item( "LPP.INCLUDE");
	SingConf->lpp.options   = load_configuration_item( "LPP.OPTIONS");
	SingConf->lpp.define	= load_configuration_item( "LPP.DEFINE");

	SingConf->dll_cpp.program 	= load_configuration_item( "DLL_CPP"       );
	SingConf->dll_cpp.options 	= load_configuration_item( "DLL_CPP.OPTIONS");
	SingConf->dll_cpp.path		= load_configuration_item( "DLL_CPP.INCLUDE");
	SingConf->dll_cpp.define	= load_configuration_item( "DLL_CPP.DEFINE");

	SingConf->dll_lpp.program	= load_configuration_item( "DLL_LPP"       );
	SingConf->dll_lpp.path		= load_configuration_item( "DLL_LPP.INCLUDE");
	SingConf->dll_lpp.options	= load_configuration_item( "DLL_LPP.OPTIONS");
	SingConf->dll_lpp.define	= load_configuration_item( "DLL_LPP.DEFINE");

	SingConf->exa.program 	= load_configuration_item( "EXA"       );
	SingConf->exadb.program = load_configuration_item( "EXADB"     );
	SingConf->amake.program   = load_configuration_item( "AMAKE"       );
	SingConf->amake.options   = load_configuration_item( "AMAKE.OPTIONS");
	SingConf->amake.define	= load_configuration_item( "AMAKE.DEFINE");
	SingConf->amake.path  	= load_configuration_item( "AMAKE.LIST");
	SingConf->imagepath 	= load_configuration_item( "IMAGEPATH" );
	SingConf->iconpath  	= load_configuration_item( "ICONPATH"  );
	SingConf->palette  	= load_configuration_item( "PALETTE"   );
	SingConf->skin     	= load_configuration_item( "SKIN"      );
	SingConf->triggerstyle 	= load_configuration_word( "TRIGGER.STYLE"  );
	SingConf->triggercolour	= load_configuration_word( "TRIGGER.COLOUR"  );

	SingConf->fontpath 	= load_configuration_item( "FONTPATH"  );

	if (!( SingConf->fontname[0] 	= UseFontVector(load_configuration_item( "FONT1"  )) ))
		SingConf->fontname[0] = allocate_string("font1.fmf");
	if (!( SingConf->fontname[1] 	= UseFontVector(load_configuration_item( "FONT2"  )) ))
		SingConf->fontname[1] = allocate_string("font2.fmf");
	if (!( SingConf->fontname[2] 	= UseFontVector(load_configuration_item( "FONT3"  )) ))
		SingConf->fontname[2] = allocate_string("font3.fmf");
	if (!( SingConf->fontname[3] 	= UseFontVector(load_configuration_item( "FONT4"  )) ))
		SingConf->fontname[3] = allocate_string("font4.fmf");
	if (!( SingConf->fontname[4] 	= UseFontVector(load_configuration_item( "FONT5"  )) ))
		SingConf->fontname[4] = allocate_string("font5.fmf");
	if (!( SingConf->fontname[5] 	= UseFontVector(load_configuration_item( "FONT6"  )) ))
		SingConf->fontname[5] = allocate_string("font6.fmf");
	if (!( SingConf->fontname[6] 	= UseFontVector(load_configuration_item( "FONT7"  )) ))
		SingConf->fontname[6] = allocate_string("font7.fmf");
	if (!( SingConf->fontname[7] 	= UseFontVector(load_configuration_item( "FONT8"  )) ))
		SingConf->fontname[7] = allocate_string("font8.fmf");
	if (!( SingConf->fontname[8] 	= UseFontVector(load_configuration_item( "FONT9"  )) ))
		SingConf->fontname[8] = allocate_string("font9.fmf");
	if (!( SingConf->fontname[9] 	= UseFontVector(load_configuration_item( "FONT10" )) ))
		SingConf->fontname[9] = allocate_string("font10.fmf");

	SingConf->stylepath 	= load_configuration_item( "STYLEPATH"  );
	SingConf->componentpath = load_configuration_item( "COMPONENTPATH"  );

	SingConf->docpath  	= load_configuration_item("DOCPATH");
	SingConf->title 	= load_configuration_item("HTML.TITLE");
	SingConf->logo  	= load_configuration_item("HTML.LOGO");
	SingConf->copyright 	= load_configuration_item("HTML.COPYRIGHT");
	SingConf->screenstyle 	= load_configuration_item("SCREEN.CSS");
	SingConf->printstyle 	= load_configuration_item("PRINT.CSS");
	SingConf->navigator  	= load_configuration_item("NAVIGATOR");
	if (!( SingConf->printer = load_configuration_item( "PRINTER"   )))
		SingConf->printer = allocate_string("printer.at");
	SingConf->density     	= load_configuration_word( "DENSITY" );
	SingConf->papersize   	= load_configuration_word( "PAPERSIZE" );
	SingConf->layout      	= load_configuration_word( "LAYOUT" );
	SingConf->pagefeed    	= load_configuration_word( "PAGEFEED" );

	SingConf->aed.program 	= load_configuration_item( "AED"       );
	SingConf->aed.state   	= load_configuration_word( "AED.STATE" );
	SingConf->aed.font    	= load_configuration_word( "AED.FONT"  );
	SingConf->aed.usecolour	= load_configuration_word( "AED.COLOUR"  );
	SingConf->aed.normal   	= load_configuration_word( "AED.NORMAL"  );
	SingConf->aed.string   	= load_configuration_word( "AED.STRING"  );
	SingConf->aed.keyword  	= load_configuration_word( "AED.KEYWORD"  );
	SingConf->aed.comment  	= load_configuration_word( "AED.COMMENT"  );
	SingConf->aed.punctuation= load_configuration_word( "AED.PUNCTUATE"  );
#ifdef	ABAL32A
	SingConf->expert_user	= 1;
#else
	SingConf->expert_user	= load_configuration_word( "EXPERT" );
#endif
	check_configuration();
	SingConf->expert_user	= 1;

	return;
}


#ifdef	__SING_LDAP

/*	------------------------------------------------	*/
/*		L O A D  _  L D A P  _ 	R T			*/
/*					V I S U A L		*/ 
/*					A B A L    		*/ 
/*					A P L U S  		*/ 
/*					H T M L    		*/ 
/*					A E D      		*/ 
/*								*/
/*	------------------------------------------------	*/
							
private	void	load_ldap_rt()
{
	/* runtime configuration parameters */
	/* -------------------------------- */
	SingConf->identity     	  = load_configuration_item( "RT.visualIdentity"  );
	SingConf->exa.program 	  = load_configuration_item( "RT.runtimeToolName" );
	SingConf->exadb.program   = load_configuration_item( "RT.debugToolName"   );
	SingConf->recordscript 	  = load_configuration_item( "RT.eventRecord"     );
	SingConf->replayscript 	  = load_configuration_item( "RT.eventReplay"     );

	if (!( SingConf->printer  = load_configuration_item( "RT.printerAt"      )))
		SingConf->printer = allocate_string("printer.at");

	return;
}


private	void	load_ldap_amake()
{
	/* runtime configuration parameters */
	/* -------------------------------- */
	SingConf->amake.program 	= load_configuration_item( "AMAKE.abalToolName"   );
	SingConf->amake.options 	= load_configuration_item( "AMAKE.abalOptions"    );
	SingConf->amake.define		= load_configuration_item( "AMAKE.abalDefineList" );
	SingConf->amake.path    	= load_configuration_item( "AMAKE.abalIncludeList");
	return;
}

private	void	load_ldap_visual()
{
	/* visual  configuration parameters */
	/* -------------------------------- */
	SingConf->imagepath 	= load_configuration_item( "VIS.visualImagePath" );
	SingConf->iconpath  	= load_configuration_item( "VIS.visualIconPath"  );
	SingConf->palette  	= load_configuration_item( "VIS.visualPalette"   );
	SingConf->skin     	= load_configuration_item( "VIS.visualSkin"      );
	SingConf->triggerstyle 	= load_configuration_word( "VIS.visualTrigger"   );
	SingConf->triggercolour	= load_configuration_word( "VIS.abalTextColour"  );

	SingConf->fontpath 	= load_configuration_item( "VIS.visualFontPath"  );

	if (!( SingConf->fontname[0] 	= UseFontVector(load_configuration_item( "VIS.visualFont1"  )) ))
		SingConf->fontname[0] = allocate_string("font1.fmf");
	if (!( SingConf->fontname[1] 	= UseFontVector(load_configuration_item( "VIS.visualFont2"  )) ))
		SingConf->fontname[1] = allocate_string("font2.fmf");
	if (!( SingConf->fontname[2] 	= UseFontVector(load_configuration_item( "VIS.visualFont3"  )) ))
		SingConf->fontname[2] = allocate_string("font3.fmf");
	if (!( SingConf->fontname[3] 	= UseFontVector(load_configuration_item( "VIS.visualFont4"  )) ))
		SingConf->fontname[3] = allocate_string("font4.fmf");
	if (!( SingConf->fontname[4] 	= UseFontVector(load_configuration_item( "VIS.visualFont5"  )) ))
		SingConf->fontname[4] = allocate_string("font5.fmf");
	if (!( SingConf->fontname[5] 	= UseFontVector(load_configuration_item( "VIS.visualFont6"  )) ))
		SingConf->fontname[5] = allocate_string("font6.fmf");
	if (!( SingConf->fontname[6] 	= UseFontVector(load_configuration_item( "VIS.visualFont7"  )) ))
		SingConf->fontname[6] = allocate_string("font7.fmf");
	if (!( SingConf->fontname[7] 	= UseFontVector(load_configuration_item( "VIS.visualFont8"  )) ))
		SingConf->fontname[7] = allocate_string("font8.fmf");
	if (!( SingConf->fontname[8] 	= UseFontVector(load_configuration_item( "VIS.visualFont9"  )) ))
		SingConf->fontname[8] = allocate_string("font9.fmf");
	if (!( SingConf->fontname[9] 	= UseFontVector(load_configuration_item( "VIS.visualFont10"  )) ))
		SingConf->fontname[9] = allocate_string("font10.fmf");

	SingConf->stylepath 	= load_configuration_item( "VIS.visualStylePath"  );
	SingConf->componentpath = load_configuration_item( "VIS.visualComponentPath"  );
	SingConf->density  	= load_configuration_word( "VIS.printDensity" );
	SingConf->papersize   	= load_configuration_word( "VIS.paperSize" );
	SingConf->layout      	= load_configuration_word( "VIS.pageLayout" );
	SingConf->pagefeed    	= load_configuration_word( "VIS.pageFeed" );

	return;
}

private	void	load_ldap_abal()
{
	SingConf->atr.program 	= load_configuration_item( "ATR.abalToolName"   );
	SingConf->atr.path 	= load_configuration_item( "ATR.abalIncludeList");
	SingConf->atr.define	= load_configuration_item( "ATR.abalDefineList" );
	SingConf->atr.options 	= load_configuration_item( "ATR.abalOptions"    );
	SingConf->ald.program   = load_configuration_item( "ALD.abalToolName"   );
	SingConf->ald.path 	= load_configuration_item( "ALD.abalIncludeList");
	SingConf->ald.options   = load_configuration_item( "ALD.abalOptions"    );
	return;
}

private	void	load_ldap_aplus()
{
	SingConf->otr.program 	= load_configuration_item( "OTR.abalToolName"   );
	SingConf->otr.path 	= load_configuration_item( "OTR.abalIncludeList");
	SingConf->otr.define	= load_configuration_item( "OTR.abalDefineList" );
	SingConf->otr.options 	= load_configuration_item( "OTR.abalOptions"    );
	SingConf->old.program   = load_configuration_item( "OLD.abalToolName"   );
	SingConf->old.path 	= load_configuration_item( "OLD.abalIncludeList");
	SingConf->old.options   = load_configuration_item( "OLD.abalOptions"    );
	return;
}

private	void	load_ldap_cpp()
{
	SingConf->cpp.program 	= load_configuration_item( "CPP.cppToolName"   );
	SingConf->cpp.path 	= load_configuration_item( "CPP.cppIncludeList");
	SingConf->cpp.define	= load_configuration_item( "CPP.cppDefineList" );
	SingConf->cpp.options 	= load_configuration_item( "CPP.cppOptions"    );
}

private	void	load_ldap_cso()
{
	SingConf->dll_cpp.program 	= load_configuration_item( "CSO.cppToolName"   );
	SingConf->dll_cpp.path 		= load_configuration_item( "CSO.cppIncludeList");
	SingConf->dll_cpp.define	= load_configuration_item( "CSO.cppDefineList" );
	SingConf->dll_cpp.options 	= load_configuration_item( "CSO.cppOptions"    );
}

private	void	load_ldap_lpp()
{
	SingConf->lpp.program   = load_configuration_item( "LPP.cppToolName"   );
	SingConf->lpp.path 	= load_configuration_item( "LPP.cppIncludeList");
	SingConf->lpp.options   = load_configuration_item( "LPP.cppOptions"    );
	SingConf->lpp.define	= load_configuration_item( "LPP.cppDefineList" );
}

private	void	load_ldap_lso()
{
	SingConf->dll_lpp.program   	= load_configuration_item( "LSO.cppToolName"   );
	SingConf->dll_lpp.path		= load_configuration_item( "LSO.cppIncludeList");
	SingConf->dll_lpp.options   	= load_configuration_item( "LSO.cppOptions"    );
	SingConf->dll_lpp.define	= load_configuration_item( "LSO.cppDefineList" );
	return;
}

private	void	load_ldap_html()
{
	char *	sptr;
	SingConf->docpath  	= load_configuration_item("HTML.documentPath");
	SingConf->title 	= load_configuration_item("HTML.documentPageTitle");
	SingConf->logo  	= load_configuration_item("HTML.documentPageLogo");
	SingConf->copyright 	= load_configuration_item("HTML.documentCopyright");
	SingConf->screenstyle 	= load_configuration_item("HTML.documentScreenStyle");
	SingConf->printstyle 	= load_configuration_item("HTML.documentPrintStyle");
	SingConf->navigator  	= load_configuration_item("HTML.documentNavigator");

	return;
}

private	void	load_ldap_aed()
{
	char *	sptr;
	SingConf->aed.program 	= load_configuration_item( "AED.abalToolName"       );
	SingConf->aed.font    	= load_configuration_word( "AED.abalFontNumber"  );
	SingConf->aed.normal   	= load_configuration_word( "AED.abalTextColour");
	SingConf->aed.string   	= load_configuration_word( "AED.abalStringColour");
	SingConf->aed.keyword  	= load_configuration_word( "AED.abalKeywordColour");
	SingConf->aed.comment  	= load_configuration_word( "AED.abalCommentColour"  );
	SingConf->aed.punctuation= load_configuration_word( "AED.abalPunctuationColour" );
	if ((sptr = load_configuration_item("AED.abalOptions")) != (char *) 0) {
		if ( *(sptr++) == 'T' )
			SingConf->aed.usecolour	= 1;
		else	SingConf->aed.usecolour	= 0;
		if ( *(sptr++) == 'T' )
			SingConf->aed.state	= 1;
		else	SingConf->aed.state	= 0;
		}
	return;
}

#endif


public	int	production_language()
{
	char *	vptr;
	int	r=0;
	if (!( vptr = configuration_item( "PRODUCTION.LANGUAGE" )))
		return( _GENERATE_BAL );
	else if ( string_compare( vptr, "C" ) )
		return( _GENERATE_C );
	else if ( string_compare( vptr, "C++" ) )
		return( _GENERATE_CPP );
	else if ( string_compare( vptr, "ABAL" ) )
		return( _GENERATE_BAL );
	else if ( string_compare( vptr, "ABAL++" ) )
		return( _GENERATE_ABAL );
	else if ( string_compare( vptr, "HTML" ) )
		return( _GENERATE_HTML );
	else if ( string_compare( vptr, "JAVA" ) )
		return( _GENERATE_JAVA );
	else	return( _GENERATE_BAL );

}

public	int	inspect_configuration()
{
	char *	nptr;
	int	status;

	while (1) {
		
		if ( SingConf->aed.font  )	SingConf->aed.font--;
		if ( SingConf->density   )	SingConf->density--;
		if ( SingConf->papersize )	SingConf->papersize--;
		if ( SingConf->layout    )	SingConf->layout--;
		if ( SingConf->pagefeed  )	SingConf->pagefeed--;

		status = accept_configuration(

			/* General Parameters */
			/* ------------------ */
			&SingConf->filename,

			&ConfigHost,

			&SingConf->identity,
			&SingConf->replayscript,
			&SingConf->recordscript,
			
			/* Abal Parameters */
			/* --------------- */
			&SingConf->atr.program,
			&SingConf->atr.define,
			&SingConf->atr.path,
			&SingConf->atr.options,
		
			&SingConf->ald.program,
			&SingConf->ald.path,
			&SingConf->ald.options,

			&SingConf->otr.program,
			&SingConf->otr.define,
			&SingConf->otr.path,
			&SingConf->otr.options,
		
			&SingConf->old.program,
			&SingConf->old.path,
			&SingConf->old.options,

			&SingConf->exa.program,
			&SingConf->exadb.program,

#ifdef	ABAL32C
			/* CPP Parameters */
			/* -------------- */
			&SingConf->cpp.program,
			&SingConf->cpp.define,
			&SingConf->cpp.path,
			&SingConf->cpp.options,
		
			&SingConf->lpp.program,
			&SingConf->lpp.path,
			&SingConf->lpp.options,
			&SingConf->lpp.define,

			&SingConf->dll_cpp.program,
			&SingConf->dll_cpp.define,
			&SingConf->dll_cpp.path,
			&SingConf->dll_cpp.options,
		
			&SingConf->dll_lpp.program,
			&SingConf->dll_lpp.path,
			&SingConf->dll_lpp.options,
			&SingConf->dll_lpp.define,
#endif
			/* Image Manager */
			/* ------------- */
			&SingConf->imagepath,
			&SingConf->iconpath,
			&SingConf->palette,
			&SingConf->skin,

			&SingConf->triggerstyle,
			&SingConf->triggercolour,
			&SingConf->stylepath,
			&SingConf->componentpath,

			/* Font Manager */
			/* ------------ */
			&SingConf->fontpath,
			&SingConf->fontname[0],
			&SingConf->fontname[1],
			&SingConf->fontname[2],
			&SingConf->fontname[3],
			&SingConf->fontname[4],
			&SingConf->fontname[5],
 			&SingConf->fontname[6],
			&SingConf->fontname[7],
			&SingConf->fontname[8],
			&SingConf->fontname[9],

			/* Html Documents */
			/* -------------- */
			&SingConf->title,
			&SingConf->logo,
			&SingConf->copyright,
			&SingConf->screenstyle,
			&SingConf->printstyle,
			&SingConf->navigator,
			&SingConf->docpath,

			/* Document Production */
			/* ------------------- */
			&SingConf->printer,
			&SingConf->papersize,
			&SingConf->layout,
			&SingConf->pagefeed,
			&SingConf->density,

			/* Editor Configuration */
			/* -------------------- */
			&SingConf->aed.program,
			&SingConf->aed.font,
			&SingConf->aed.state,

			&SingConf->aed.usecolour,

			&SingConf->aed.normal,
			&SingConf->aed.string,
			&SingConf->aed.keyword,
			&SingConf->aed.comment,
			&SingConf->aed.punctuation,

			/* AMAKE Project Options */
			/* --------------------- */
			&SingConf->amake.program,
			&SingConf->amake.options,
			&SingConf->amake.define ,
			&SingConf->amake.path   

			);

		SingConf->aed.font++;
		SingConf->density++;
		SingConf->papersize++;
		SingConf->layout++;
		SingConf->pagefeed++;

		switch ( status ) {
		case	_CONF_EXIT	:
		case	_CONF_QUIT	:
			check_configuration();
			break;

		case	_CONF_EDIT	:
			check_configuration();
			if ( SingConf->filename ) {
				sprintf(namebuffer,"%s.cfg",SingConf->filename);
				if ((nptr = allocate_string( namebuffer )) != (char *) 0) {
					(void) use_editor( nptr , -1 );
					liberate( nptr );
					}
				}
			continue;

		case	_CONF_LOAD_LDAP	:
			if ( SingConf->filename ) {
				if (!( load_from_slapd(SingConf->filename,0) )) {
					liberate(SingConf->filename);
					SingConf->filename = allocate_string("sing");
					load_from_slapd(SingConf->filename,0);
					}
				}
			continue;

		case	_CONF_SAVE_LDAP	:
			if ( SingConf->filename )
				save_to_slapd(SingConf->filename,0);
			continue;

		case	_CONF_WIPE_LDAP	:
			if ( SingConf->filename )
				raz_from_slapd(SingConf->filename);
			continue;

		case	_CONF_SAVE	:
			check_configuration();
			if ( SingConf->filename )
				save_configuration(SingConf->filename);
			continue;
		case	_CONF_LOAD	:
			check_configuration();
			if ( SingConf->filename ) {
				load_configuration((nptr =allocate_string(SingConf->filename)));
				liberate( nptr );
				}
			continue;
		}
		break;
		}
	return(0);
		
}


#ifdef	__SING_LDAP
private	char	*	build_ldap_name( char * confName )
{
	char	*	buffer;
	

	/* allocate buffer for fn parser */
	/* ----------------------------- */
	if (!( buffer = allocate_string( confName ) )) {
		liberate( confName );
		return(27);
		}

	/* extract file root */
	/* ----------------- */
	if (fn_parser(confName,buffer,8) != 0) {
		liberate( confName );
		confName = buffer;
		}
	else	liberate( buffer );

	if (!( buffer = allocate( strlen( confName ) + 32 ) )) {
		liberate( confName );
		return( 27 );
		}

	if (( *confName >= 'a' ) && ( *confName <= 'z' ))
		*confName = ( *confName - ('a' - 'A') );

	sprintf(buffer,"conf%s",confName);
	liberate( confName );
	return( buffer );
}
#endif


public	int	load_from_slapd(char * eptr,int verbose)
{
	char	*	sptr;
#ifdef WIN32

	return WinLoadSingconf(eptr, verbose);

#else

	int	status=0;
#ifdef	__SING_LDAP
	int	i=0;
	struct	ldap_controller * lptr;
	char	* dbuffer;
	char 	* nptr;
	char	* confName=(char *) 0;
	char	* confRoot=(char *) 0;

	if (!( confRoot = allocate_string( _SING_LDAP_ROOT ) ))
		return(27);

	if (!( confName = allocate_string( eptr ))) {
		liberate( confRoot );
		return( 27 );
		}
	else if (!( confName = build_ldap_name( confName ))) {
		liberate( confRoot );
		return( 27 );
		}
	if (!( ConfigHost ))
		if ((sptr = confgetenv("ABALHOST")) != (char *) 0)
			ConfigHost = allocate_string( sptr );

	if (!( dbuffer = allocate( 1024 ) )) {
		liberate( confRoot );
		liberate( confName );
		return(27);
		}

	else if ((lptr = OpenLdap(ConfigHost, (char *)0,(char *) 0)) != (struct ldap_controller*) 0) {

		nptr = allocate_string( eptr );
		drop_configuration();	allocate_configuration();
		SingConf->filename 	= nptr;

		/* Runtime Configuration */
		/* --------------------- */
		sprintf(dbuffer,"ou=confRuntime, ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );

		if ((status = load_from_ldap( lptr,  dbuffer, "RT" )) != 0) {

			load_ldap_rt();

			/* Amake   Configuration */
			/* --------------------- */
			sprintf(dbuffer,"ou=confAmake, ou=%s, %s",confName,confRoot);
			status_message( dbuffer , 2 );

			if ((status = load_from_ldap( lptr,  dbuffer, "AMAKE" )) != 0) {

				load_ldap_amake();

				/* Visual Configuration */
				/* -------------------- */
				sprintf(dbuffer,"ou=confVisual, ou=%s, %s",confName,confRoot);
				status_message( dbuffer , 2 );

				if ((status = load_from_ldap( lptr,  dbuffer, "VIS" )) != 0) {

					load_ldap_visual();


					/* Abal   Configuration */
					/* -------------------- */
					sprintf(dbuffer,"ou=confAtr, ou=%s, %s",confName,confRoot);
					status_message( dbuffer , 2 );
	
					if ((status = load_from_ldap( lptr,  dbuffer, "ATR" )) != 0) {

						sprintf(dbuffer,"ou=confAld, ou=%s, %s",confName,confRoot);
						status_message( dbuffer , 2 );

						if ((status = load_from_ldap( lptr,  dbuffer, "ALD" )) != 0) {
							load_ldap_abal();

							/* Aplus  Configuration */
							/* -------------------- */
							sprintf(dbuffer,"ou=confOtr, ou=%s, %s",confName,confRoot);
							status_message( dbuffer , 2 );
							if ((status = load_from_ldap( lptr,  dbuffer, "OTR" )) != 0) {
								sprintf(dbuffer,"ou=confOld, ou=%s, %s",confName,confRoot);
								status_message( dbuffer , 2 );
								if ((status = load_from_ldap( lptr,  dbuffer, "OLD" )) != 0) {
									load_ldap_aplus();

									/* Html  Configuration */
									/* ------------------- */
									sprintf(dbuffer,"ou=confHtml, ou=%s, %s",confName,confRoot);
									status_message( dbuffer , 2 );
									if ((status = load_from_ldap( lptr,  dbuffer, "HTML" )) != 0) {
										load_ldap_html();
	
										/* Editor Configuration */
										/* -------------------- */
										sprintf(dbuffer,"ou=confAed, ou=%s, %s",confName,confRoot);
										status_message( dbuffer , 2 );
										if ((status = load_from_ldap( lptr,  dbuffer, "AED" )) != 0) {
											load_ldap_aed();
#ifdef	ABAL32C

										/* Cpp Configuration */
										/* ----------------- */
										sprintf(dbuffer,"ou=confCpp, ou=%s, %s",confName,confRoot);
										status_message( dbuffer , 2 );
										if ((status = load_from_ldap( lptr,  dbuffer, "CPP" )) != 0)
											load_ldap_cpp();

										/* Lpp Configuration */
										/* ----------------- */
										sprintf(dbuffer,"ou=confLpp, ou=%s, %s",confName,confRoot);
										status_message( dbuffer , 2 );
										if ((status = load_from_ldap( lptr,  dbuffer, "LPP" )) != 0)
											load_ldap_lpp();

										/* Cpp Configuration */
										/* ----------------- */
										sprintf(dbuffer,"ou=confCso, ou=%s, %s",confName,confRoot);
										status_message( dbuffer , 2 );
										if ((status = load_from_ldap( lptr,  dbuffer, "CSO" )) != 0)
											load_ldap_cso();

										/* Lpp Configuration */
										/* ----------------- */
										sprintf(dbuffer,"ou=confLso, ou=%s, %s",confName,confRoot);
										status_message( dbuffer , 2 );
										if ((status = load_from_ldap( lptr,  dbuffer, "LSO" )) != 0)
											load_ldap_lso();
#endif
										status=1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		CloseLdap(lptr);

		/* SingConf->expert_user	= load_configuration_word( "EXPERT" );	*/
	
		if ( status )
			check_configuration();

		}
	else if ( verbose ) {
		printf("error opening ldap connection %s for %s \n",ConfigHost,confName);
		}
	liberate( dbuffer  );
	liberate( confRoot );
	liberate( confName );

#endif
	return(status);
#endif
}



public	void	LoadConfiguration( char * rootname )
{
	char * eptr;

	strcpy( ConfigurationRoot, rootname );

#ifdef WIN32

	if (WinIsSingConfFile(rootname)==0)
		load_configuration( rootname );
	else
		load_from_slapd( rootname,0 );

#else

#ifdef	__SING_LDAP
	if ((( eptr = confgetenv("ABALHOST"))!=(char *) 0)
	&&   ( *eptr != '0' )) {
		ConfigHost = allocate_string( eptr );
		load_from_slapd( rootname,0 );
		}
	else

#endif
		load_configuration( rootname );
#endif
}


public	int	save_to_slapd(char * eptr,int verbose)
{
#ifdef WIN32

	return WinSaveSingconf(eptr, verbose);

#else

#ifdef	__SING_LDAP
	struct	ldap_controller * lptr;
	char		obuffer[16];
	char *		sptr;
	char *		dbuffer;
	char *		confName=(char *) 0;
	char *		confRoot=(char *) 0;

	if (!( confRoot = allocate_string( _SING_LDAP_ROOT )))
		return( 27 );

	if (!( confName = allocate_string( eptr ))) {
		liberate( confRoot );
		return( 27 );
		}

	else if (!( confName = build_ldap_name( confName ))) {
		liberate( confRoot );
		return( 27 );
		}

	if (!( ConfigHost ))
		if ((sptr = confgetenv("ABALHOST")) != (char *) 0)
			ConfigHost = allocate_string( sptr );

	if (!( dbuffer = allocate( 1024 ) )) {
		liberate( confRoot );
		liberate( confName );
		return(27);
		}

	else if ((lptr = OpenLdap(ConfigHost, (char *)0,(char *) 0)) != (struct ldap_controller*) 0) {

		lptr->synchronise = 0;

		/* Configuration Collector : Top Level */
		/* ----------------------------------- */
		sprintf(dbuffer,"ou=%s, ou=%s",confStandard,confAdmin);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, confStandard			     ,"ou" );
		AddLdapStringAtb( lptr, "organizationalUnit|top","objectClass" );
		FlushLdapUpdate ( lptr );

		/* Configuration Collector */
		/* ----------------------- */
		sprintf(dbuffer,"ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, confName	 		,"ou" );
		AddLdapStringAtb( lptr, "organizationalUnit|top","objectClass" );
		FlushLdapUpdate ( lptr );

		/* Visual Configuration */
		/* -------------------- */
		sprintf(dbuffer,"ou=confVisual, ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, "confVisual"		,"ou" );
		AddLdapStringAtb( lptr, "visualConf|organizationalUnit|top","objectClass" );
		AddLdapStringAtb( lptr, SingConf->identity	 ,"visualIdentity");
		AddLdapStringAtb( lptr, SingConf->imagepath  	 ,"visualImagePath");
		AddLdapStringAtb( lptr, SingConf->iconpath   	 ,"visualIconPath");
		AddLdapStringAtb( lptr, SingConf->fontpath   	 ,"visualFontPath");
		AddLdapStringAtb( lptr, SingConf->stylepath   	 ,"visualStylePath");
		AddLdapStringAtb( lptr, SingConf->componentpath  ,"visualComponentPath");
		AddLdapStringAtb( lptr, SingConf->palette    	 ,"visualPalette");
		AddLdapStringAtb( lptr, SingConf->skin       	 ,"visualSkin");
		AddLdapStringAtb( lptr, GetFontVector(SingConf->fontname[0], 1)	 ,"visualFont1");
		AddLdapStringAtb( lptr, GetFontVector(SingConf->fontname[1], 2)	 ,"visualFont2");
		AddLdapStringAtb( lptr, GetFontVector(SingConf->fontname[2], 3)	 ,"visualFont3");
		AddLdapStringAtb( lptr, GetFontVector(SingConf->fontname[3], 4)	 ,"visualFont4");
		AddLdapStringAtb( lptr, GetFontVector(SingConf->fontname[4], 5)	 ,"visualFont5");
		AddLdapStringAtb( lptr, GetFontVector(SingConf->fontname[5], 6)	 ,"visualFont6");
		AddLdapStringAtb( lptr, GetFontVector(SingConf->fontname[6], 7)	 ,"visualFont7");
		AddLdapStringAtb( lptr, GetFontVector(SingConf->fontname[7], 8)	 ,"visualFont8");
		AddLdapStringAtb( lptr, GetFontVector(SingConf->fontname[8], 9)	 ,"visualFont9");
		AddLdapStringAtb( lptr, GetFontVector(SingConf->fontname[9],10)	 ,"visualFont10");
		AddLdapWordAtb( lptr, SingConf->triggerstyle	 ,"visualTrigger");
		AddLdapWordAtb( lptr, SingConf->triggercolour	 ,"abalTextColour");
		AddLdapWordAtb  ( lptr, SingConf->density  	 ,"printDensity");
		AddLdapWordAtb  ( lptr, SingConf->papersize   	 ,"paperSize"	);
		AddLdapWordAtb  ( lptr, SingConf->layout      	 ,"pageLayout"	);
		AddLdapWordAtb  ( lptr, SingConf->pagefeed    	 ,"pageFeed"	);
		FlushLdapUpdate ( lptr );

		/* Object Translator Configuration */
		/* ------------------------------- */
		sprintf(dbuffer,"ou=confOtr, ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, "confOtr" 		,"ou" );
		AddLdapStringAtb( lptr, "translatorConf|organizationalUnit|top","objectClass" );
		AddLdapStringAtb( lptr, SingConf->identity	 ,"visualIdentity");
		AddLdapStringAtb( lptr, SingConf->otr.program	 ,"abalToolName" );
		AddLdapStringAtb( lptr, SingConf->otr.path	 ,"abalIncludeList");
		AddLdapStringAtb( lptr, SingConf->otr.define     ,"abalDefineList");
		AddLdapStringAtb( lptr, SingConf->otr.options	 ,"abalOptions"	);
		FlushLdapUpdate ( lptr );

		/* Object Linker Configuration */
		/* --------------------------- */
		sprintf(dbuffer,"ou=confOld, ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, "confOld" 		,"ou" );
		AddLdapStringAtb( lptr, "linkerConf|organizationalUnit|top","objectClass" );
		AddLdapStringAtb( lptr, SingConf->identity	 ,"visualIdentity" 	);
		AddLdapStringAtb( lptr, SingConf->old.path	 ,"abalIncludeList");
		AddLdapStringAtb( lptr, SingConf->old.program	 ,"abalToolName" );
		AddLdapStringAtb( lptr, SingConf->old.options	 ,"abalOptions"	);
		FlushLdapUpdate ( lptr );

		/* Abal Translator Configuration */
		/* ----------------------------- */
		sprintf(dbuffer,"ou=confAtr, ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, "confAtr" 		,"ou" );
		AddLdapStringAtb( lptr, "translatorConf|organizationalUnit|top","objectClass" );
		AddLdapStringAtb( lptr, SingConf->identity	 ,"visualIdentity" 	);
		AddLdapStringAtb( lptr, SingConf->atr.program	 ,"abalToolName" );
		AddLdapStringAtb( lptr, SingConf->atr.path	 ,"abalIncludeList");
		AddLdapStringAtb( lptr,	SingConf->atr.define 	 ,"abalDefineList");
		AddLdapStringAtb( lptr, SingConf->atr.options	 ,"abalOptions"	);
		FlushLdapUpdate ( lptr );

		/* Abal Linker Configuration */
		/* ------------------------- */
		sprintf(dbuffer,"ou=confAld, ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, "confAld" 		,"ou" );
		AddLdapStringAtb( lptr, "linkerConf|organizationalUnit|top","objectClass" );
		AddLdapStringAtb( lptr, SingConf->identity	 ,"visualIdentity" 	);
		AddLdapStringAtb( lptr, SingConf->ald.program	 ,"abalToolName" );
		AddLdapStringAtb( lptr, SingConf->ald.path	 ,"abalIncludeList");
		AddLdapStringAtb( lptr, SingConf->ald.options	 ,"abalOptions"	);
		FlushLdapUpdate ( lptr );

#ifdef	ABAL32C
		/* CPP Translator Configuration */
		/* ---------------------------- */
		sprintf(dbuffer,"ou=confCpp, ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, "confCpp" 		,"ou" );
		AddLdapStringAtb( lptr, "pCompilerConf|organizationalUnit|top","objectClass" );
		AddLdapStringAtb( lptr, SingConf->identity	 ,"visualIdentity" 	);
		AddLdapStringAtb( lptr, SingConf->cpp.program	 ,"cppToolName" );
		AddLdapStringAtb( lptr, SingConf->cpp.path	 ,"cppIncludeList");
		AddLdapStringAtb( lptr,	SingConf->cpp.define 	 ,"cppDefineList");
		AddLdapStringAtb( lptr, SingConf->cpp.options	 ,"cppOptions"	);
		FlushLdapUpdate ( lptr );

		/* CPP Linker Configuration */
		/* ------------------------ */
		sprintf(dbuffer,"ou=confLpp, ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, "confLpp" 		,"ou" );
		AddLdapStringAtb( lptr, "pLinkerConf|organizationalUnit|top","objectClass" );
		AddLdapStringAtb( lptr, SingConf->identity	 ,"visualIdentity" 	);
		AddLdapStringAtb( lptr, SingConf->lpp.program	 ,"cppToolName" );
		AddLdapStringAtb( lptr, SingConf->lpp.path	 ,"cppIncludeList");
		AddLdapStringAtb( lptr, SingConf->lpp.options	 ,"cppOptions"	);
		AddLdapStringAtb( lptr, SingConf->lpp.define	 ,"cppDefineList"	);
		FlushLdapUpdate ( lptr );

		/* DLL CPP Translator Configuration */
		/* -------------------------------- */
		sprintf(dbuffer,"ou=confCso, ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, "confCso" 		,"ou" );
		AddLdapStringAtb( lptr, "lCompilerConf|organizationalUnit|top","objectClass" );
		AddLdapStringAtb( lptr, SingConf->identity	 ,"visualIdentity" 	);
		AddLdapStringAtb( lptr, SingConf->dll_cpp.program,"cppToolName" );
		AddLdapStringAtb( lptr, SingConf->dll_cpp.path	 ,"cppIncludeList");
		AddLdapStringAtb( lptr,	SingConf->dll_cpp.define ,"cppDefineList");
		AddLdapStringAtb( lptr, SingConf->dll_cpp.options,"cppOptions"	);
		FlushLdapUpdate ( lptr );

		/* DLL CPP Linker Configuration */
		/* ---------------------------- */
		sprintf(dbuffer,"ou=confLso, ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, "confLso" 		,"ou" );
		AddLdapStringAtb( lptr, "lLinkerConf|organizationalUnit|top","objectClass" );
		AddLdapStringAtb( lptr, SingConf->identity	 ,"visualIdentity" 	);
		AddLdapStringAtb( lptr, SingConf->dll_lpp.program,"cppToolName" );
		AddLdapStringAtb( lptr, SingConf->dll_lpp.path	 ,"cppIncludeList");
		AddLdapStringAtb( lptr, SingConf->dll_lpp.options,"cppOptions"	);
		AddLdapStringAtb( lptr, SingConf->dll_lpp.define ,"cppDefineList"	);
		FlushLdapUpdate ( lptr );
#endif
		/* Abal Documentation Configuration */
		/* -------------------------------- */
		sprintf(dbuffer,"ou=confHtml, ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, "confHtml" 		,"ou" );
		AddLdapStringAtb( lptr, "documentConf|organizationalUnit|top","objectClass" );
		AddLdapStringAtb( lptr, SingConf->identity	 ,"visualIdentity" 	);
		AddLdapStringAtb( lptr, SingConf->screenstyle	 ,"documentScreenStyle");
		AddLdapStringAtb( lptr, SingConf->printstyle	 ,"documentPrintStyle");	
		AddLdapStringAtb( lptr, SingConf->title		 ,"documentPageTitle");	
		AddLdapStringAtb( lptr, SingConf->logo		 ,"documentPageLogo");	
		AddLdapStringAtb( lptr, SingConf->copyright	 ,"documentCopyright");	
		AddLdapStringAtb( lptr, SingConf->navigator	 ,"documentNavigator");	
		AddLdapStringAtb( lptr, SingConf->docpath	 ,"documentPath");		
		FlushLdapUpdate ( lptr );

		/* Abal Editor Configuration */
		/* ------------------------- */
		sprintf(dbuffer,"ou=confAed, ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, "confAed" 		 ,"ou" );
		AddLdapStringAtb( lptr, "editorConf|organizationalUnit|top","objectClass" );
		AddLdapStringAtb( lptr, SingConf->identity	 ,"visualIdentity" 	);
		AddLdapStringAtb( lptr, SingConf->aed.program 	 ,"abalToolName" 	);
		AddLdapWordAtb  ( lptr, SingConf->aed.font    	 ,"abalFontNumber" 	);
		AddLdapWordAtb  ( lptr, SingConf->aed.normal     ,"abalTextColour"  	);
		AddLdapWordAtb  ( lptr, SingConf->aed.string     ,"abalStringColour"  );
		AddLdapWordAtb  ( lptr, SingConf->aed.keyword    ,"abalKeywordColour" 	);
		AddLdapWordAtb  ( lptr, SingConf->aed.comment    ,"abalCommentColour"	);
		AddLdapWordAtb  ( lptr, SingConf->aed.punctuation,"abalPunctuationColour"  );
		if ( SingConf->aed.usecolour )
			obuffer[0] = 'T';
		else	obuffer[0] = 'F';
		if ( SingConf->aed.usecolour )
			obuffer[1] = 'T';
		else	obuffer[1] = 'F';
		obuffer[2] = 0;
		AddLdapStringAtb  ( lptr,  obuffer              ,  "abalOptions" 	);
		FlushLdapUpdate ( lptr );

		/* Abal Runtime Configuration */
		/* -------------------------- */
		sprintf(dbuffer,"ou=confRuntime, ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, "confRuntime" 		,"ou" );
		AddLdapStringAtb( lptr, "runtimeConf|organizationalUnit|top","objectClass" );
		AddLdapStringAtb( lptr, SingConf->identity	 ,"visualIdentity" 	);
		AddLdapStringAtb( lptr, SingConf->exa.program	 ,"runtimeToolName");
		AddLdapStringAtb( lptr, SingConf->exadb.program	 ,"debugToolName");
		AddLdapStringAtb( lptr, SingConf->printer	 ,"printerAt");
		AddLdapStringAtb( lptr, SingConf->replayscript	 ,"eventReplay");
		AddLdapStringAtb( lptr, SingConf->recordscript	 ,"eventRecord");
		FlushLdapUpdate ( lptr );

		/* Abal Runtime Configuration */
		/* -------------------------- */
		sprintf(dbuffer,"ou=confAmake, ou=%s, %s",confName,confRoot);
		status_message( dbuffer , 2 );
		StartLdapUpdate( lptr, dbuffer );
		AddLdapStringAtb( lptr, "confAmake" 		,"ou" );
		AddLdapStringAtb( lptr, "projectbuilderConf|organizationalUnit|top","objectClass" );
		AddLdapStringAtb( lptr, SingConf->identity	 ,"visualIdentity" );
		AddLdapStringAtb( lptr, SingConf->amake.program	 ,"abalToolName"   );
		AddLdapStringAtb( lptr, SingConf->amake.options	 ,"abalOptions"	   );
		AddLdapStringAtb( lptr,	SingConf->amake.define 	 ,"abalDefineList" );
		AddLdapStringAtb( lptr, SingConf->amake.path   	 ,"abalIncludeList");
		FlushLdapUpdate ( lptr );


		CloseLdap(lptr);
		liberate( confName );
		liberate( dbuffer );
		return(1);		
		}
	else if ( verbose ) {
		printf("error opening ldap connection %s for %s \n",ConfigHost,confName);
		}
	liberate( confName );
	liberate( dbuffer );
#endif
	return(0);
#endif
}


/*	-------------------------------		*/
/*	l d a p _ i n j e c t ( entry )		*/
/*	-------------------------------		*/
/*	Called from sing main for the		*/
/*	injection of ldap information		*/
/*	-------------------------------		*/


public	int	ldap_inject( char * entry )
{
	int	i;
	int	c;
	int	status;
	for (i=0; *(entry+i) != 0; i++ )
		if ( *(entry+i) == '@' )
			break;
	if ((c = *(entry+i)) == '@' ) {
		ConfigHost =(entry+i+1);
		*(entry+i) = 0;
		}

	status = save_to_slapd( entry, 1 );
	if ((*(entry+i) = c) == '@')
		ConfigHost = (char *) 0;
	if ( status )
		return( 0 );
	else	return( 56);
}

public	int	raz_from_slapd(char * sptr)
{
#ifdef WIN32

	return WinRazSingconf(sptr, 0);

#else

#ifdef	__SING_LDAP
	struct	ldap_controller * lptr;
	char		obuffer[16];
	char *		eptr;
	char *		dbuffer;
	char *		confName=(char *) 0;
	char *		confRoot=(char *) 0;
	char *		configRoot=(char *) 0;

	if (!( configRoot = confgetenv("LDAPROOT") )) {
		if (!( confRoot = allocate_string( _SING_LDAP_ROOT )))
			return( 27 );
		}
	else if (!( confRoot = allocate_string( configRoot ) ))
		return(27);

	if (!( confName = allocate_string( sptr ))) {
		liberate( confRoot );
		return( 27 );
		}

	else if (!( confName = build_ldap_name( confName ))) {
		liberate( confRoot );
		return( 27 );
		}

	if (!( ConfigHost ))
		if ((eptr = confgetenv("ABALHOST")) != (char *) 0)
			ConfigHost = allocate_string( eptr );

	if (!( dbuffer = allocate( 1024 ) )) {
		liberate( confRoot );
		liberate( confName );
		return(27);
		}

	else if ((lptr = OpenLdap(ConfigHost, (char *)0,(char *) 0)) != (struct ldap_controller*) 0) {

		sprintf(dbuffer,"ou=confAed, ou=%s, %s",confName,confRoot);
		DeleteLdap(lptr,dbuffer);
		sprintf(dbuffer,"ou=confOtr, ou=%s, %s",confName,confRoot);
		DeleteLdap(lptr,dbuffer);
		sprintf(dbuffer,"ou=confOld, ou=%s, %s",confName,confRoot);
		DeleteLdap(lptr,dbuffer);
		sprintf(dbuffer,"ou=confAtr, ou=%s, %s",confName,confRoot);
		DeleteLdap(lptr,dbuffer);
		sprintf(dbuffer,"ou=confAld, ou=%s, %s",confName,confRoot);
		DeleteLdap(lptr,dbuffer);
		sprintf(dbuffer,"ou=confCpp, ou=%s, %s",confName,confRoot);
		DeleteLdap(lptr,dbuffer);
		sprintf(dbuffer,"ou=confLpp, ou=%s, %s",confName,confRoot);
		DeleteLdap(lptr,dbuffer);
		sprintf(dbuffer,"ou=confCso, ou=%s, %s",confName,confRoot);
		DeleteLdap(lptr,dbuffer);
		sprintf(dbuffer,"ou=confLso, ou=%s, %s",confName,confRoot);
		DeleteLdap(lptr,dbuffer);
		sprintf(dbuffer,"ou=confRuntime, ou=%s, %s",confName,confRoot);
		DeleteLdap(lptr,dbuffer);
		sprintf(dbuffer,"ou=confVisual, ou=%s, %s",confName,confRoot);
		DeleteLdap(lptr,dbuffer);
		sprintf(dbuffer,"ou=confHtml, ou=%s, %s",confName,confRoot);
		DeleteLdap(lptr,dbuffer);
		sprintf(dbuffer,"ou=confAmake, ou=%s, %s",confName,confRoot);
		DeleteLdap(lptr,dbuffer);
		sprintf(dbuffer,"ou=%s, %s",confName,confRoot);
		DeleteLdap(lptr,dbuffer);
		CloseLdap(lptr);
		liberate( confName );
		liberate( dbuffer );
		}
	
#endif
	return(0);
#endif
}

#endif	/* _SINGCONF_C */


