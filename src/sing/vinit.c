private	char *	configuration_name=(char *) 0;

public 	int 	initialise_configuration(char * nptr)
{
#ifdef	SYSTEM_LDAP
	char *	hptr;
	if (((hptr = getenv("ABALHOST")) != (char *) 0)
	&&  (*hptr != '0')) {
		if ( load_visual_ldap( hptr, nptr, "VIS") != 40 ) {
			system_fontpath  = configuration_item( "VIS.visualFontPath" );
			system_imagepath = configuration_item( "VIS.visualImagePath" );
			system_palette   = configuration_item( "VIS.visualPalette" );
			system_stylepath = configuration_item( "VIS.visualStylePath" );
			}
		if ( load_document_ldap( hptr, nptr, "HTML") != 40 ) {
			system_docpath = configuration_item( "HTML.documentPath" );
			system_navigator = configuration_item( "HTML.documentNavigator" );
			}
		x_event(31);
		return( 0 );
		}
	else
#endif
	if ( configuration_load( nptr ) != 40 ) {
		system_fontpath  = configuration_item( "FONTPATH" );
		system_imagepath = configuration_item( "IMAGEPATH" );
		system_docpath   = configuration_item( "DOCPATH" );
		system_navigator = configuration_item( "NAVIGATOR" );
		system_palette   = configuration_item( "PALETTE" );
		system_stylepath = configuration_item( "STYLEPATH" );
		x_event(31);
		return(0);
		}
	else	{
		x_event(31);
		return(40);
		}
}

public 	int 	terminate_configuration()
{
	system_fontpath = 
	system_imagepath = (char *) 0;
	x_event(32);
	configuration_drop();
	return(0);
}

public	int	set_configuration_name(char * rptr)
{
	if (!( rptr )) 
		return(0);
	else if (!(configuration_name = allocate( strlen( rptr ) + 16 ) ))
		return(27);
	else	{
		strcpy(configuration_name,rptr);
		return(0);
		}
}

private	int	activate_visuals(int mode)
{
char* p;

	initialise_mouse();
	if (!( configuration_name ))
		(void) initialise_configuration("visual");
	else	(void) initialise_configuration(configuration_name );

	/*FCH03042006 couleurs des titres*/
#if defined(WIN32)
	p = confgetenv("GIGOTITLECOLORON");
#else
	p = getenv("GIGOTITLECOLORON");
#endif
	if ( p && *p=='1')
		{
		standard_text		=_DEFAULT_GUI_FG_TITLE_ORI;
		standard_title		=_DEFAULT_GUI_BG_TITLE_ORI;
		}

	cicopalette(0,0);
#ifndef	UNIX
 	initialise_mouse();
#endif
	return( mode );
}

public	int  visual_initialise(WORD mode )
{
	int		imode;
	reset_replay_record();

	if ((imode = initialisepixel((mode | 256))) == -1)
		return(-1);
	else if ( imode == 56 )
		return(-1);
	else	return( activate_visuals( imode ) );
}

public	int  visual_activate(WORD width, WORD height, WORD style )
{
	int		imode;
	reset_replay_record();
#if defined(UNIX) || defined(WIN32)
	if ((imode = activatepixel(width,height,style)) == -1)
		return(-1);
	else if ( imode == 56 )
		return(-1);
	else	return( activate_visuals(imode) );
#else
	return(-1);
#endif
}



