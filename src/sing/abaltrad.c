#ifndef	_abaltrad_c
#define	_abaltrad_c

static	struct	translator_configuration * otr=(struct translator_configuration*) 0;
static	struct	translator_configuration * atr=(struct translator_configuration*) 0;
static	struct	translator_configuration * ctr=(struct translator_configuration*) 0;

char	*	CobolTranslator=(char *) 0;

#ifndef	__QUOTE
#define	__QUOTE	0x0022
#endif

public	void	initialise_abal_translators()
{
	otr=(struct translator_configuration*) 0;
	atr=(struct translator_configuration*) 0;
	ctr=(struct translator_configuration*) 0;
	return;
}

public	void	liberate_abal_translators()
{
	if ( otr ) {
		otr = liberate( otr );
		}
	if ( atr ) {
		atr = liberate( atr );
		}
	if ( ctr ) {
		ctr = liberate( ctr );
		}
	return;
}

private	void	use_translation_options( struct	translator_configuration * tptr, char * sptr )
{
	if (!( tptr )) return;
	while ( *sptr ) {
		switch ( *(sptr++) ) {
			case	'v'	:
			case	'V'	:
				tptr->verbose=1; 
				continue;
			case	'o'	:
			case	'O'	:
				tptr->optimise=1; 
				continue;
			case	't'	:
			case	'T'	:
				tptr->trace=1; 
				continue;
			case	'm'	:
			case	'M'	:
				tptr->debug=1; 
				continue;
			case	'A'	:
			case	'a'	:
				tptr->compact=1;
				continue;
			case	'l'	:
			case	'L'	:
				tptr->liste=1; 
				continue;
			}

		}
	return;
}

private	void	raz_translation_options( struct	translator_configuration * tptr, char * sptr )
{
	if (!( tptr )) return;
	while ( *sptr ) {
		switch ( *(sptr++) ) {
			case	'v'	:
			case	'V'	:
				tptr->verbose=0; 
				continue;
			case	'o'	:
			case	'O'	:
				tptr->optimise=0; 
				continue;
			case	't'	:
			case	'T'	:
				tptr->trace=0; 
				continue;
			case	'm'	:
			case	'M'	:
				tptr->debug=0; 
				continue;
			case	'A'	:
			case	'a'	:
				tptr->compact=0;
				continue;
			case	'l'	:
			case	'L'	:
				tptr->liste=0; 
				continue;
			}

		}
	return;
}

private	void	set_translation_options( struct	translator_configuration * tptr, char * sptr )
{
	if (!( tptr )) return;
	tptr->verbose=0;
	tptr->debug=0;
	tptr->liste=0;
	tptr->trace=0;
	tptr->optimise=0;
	tptr->compact=0;
	if (!( sptr )) return;
	use_translation_options( tptr, sptr );
	return;
}

public	void	configure_translation(char * cptr, char * dptr )
{
	if (!(otr = allocate( sizeof(struct translator_configuration) )))
		return(0);
	else	{
		set_translation_options( otr, SingConf->otr.options );
		}		
	use_translation_options( otr, cptr );
	raz_translation_options( otr, dptr );
	if (!(atr = allocate( sizeof(struct translator_configuration) )))
		return(0);
	else	{
		set_translation_options( atr, SingConf->atr.options );
		}		
	use_translation_options( atr, cptr );
	raz_translation_options( atr, dptr );
	if (!(ctr = allocate( sizeof(struct translator_configuration) )))
		return(0);
	else	{
		set_translation_options( ctr, SingConf->atr.options );
		}		
	use_translation_options( ctr, cptr );
	raz_translation_options( ctr, dptr );
	return;
}


#include "singtrac.c"

private	char *	build_abal_command_blank_allowed( char * sptr, char * prefix, char * encaps )
{
	int	elements=0;
	char *	rptr=(char *) 0;
	char *	hptr=(char *) 0;
	int	i;
	if (!( sptr ))
		return( sptr );
	else if (!(sptr = allocate_string( sptr ) ))
		return( sptr );
	for (i=0; *(sptr+i) != 0; i++ ) {
		if ( *(sptr+i) == ',' )
			*(sptr+i) = ',';
	/* FCH_SING ajout de ';'*/
	if ( *(sptr+i) == ';' )
		*(sptr+i) = ',';
#ifndef	WIN32
		if ( *(sptr+i) == ':' )
			*(sptr+i) = ',';
#endif
		else if ( *(sptr+i) == '|' )
			*(sptr+i) = ',';
		if ( *(sptr+i) == ',');
			elements++;
		}
	hptr = sptr;
	if (( rptr = allocate( strlen(sptr) + (elements * (strlen(prefix)+5)) + 256 ) ) != (char *) 0) {
		rptr[0]=0;
		i = 0;
		while ( *(sptr+i) != 0 ) {
			if ( *(sptr+i) == ',' ) {
				if (!( i )) {
					sptr++;
					continue;
					}
				else	{
					*(sptr+i) = 0;
					strcat(rptr," ");
					if (strchr(sptr,' ')) strcat(rptr,encaps);
					strcat(rptr,prefix);
					strcat(rptr,sptr);
#ifdef WIN32
					if (sptr[i-1]!="\\") strcat(rptr,"\\");
#else
					if (sptr[i-1]!="/") strcat(rptr,"/");
#endif
					if (strchr(sptr,' ')) strcat(rptr,encaps);
					sptr += (i+1); i= 0;
					}
				}
			else	i++;
			}
		if (i)	{
			*(sptr+i) = 0;
			strcat(rptr," ");
			if (strchr(sptr,' ')) strcat(rptr,encaps);
			strcat(rptr,prefix);
			strcat(rptr,sptr);
#ifdef WIN32
			if (sptr[i-1]!="\\") strcat(rptr,"\\");
#else
			if (sptr[i-1]!="/") strcat(rptr,"/");
#endif
			if (strchr(sptr,' ')) strcat(rptr,encaps);
			}
		}
	liberate( hptr );
	return( rptr );

}

private	char *	build_abal_command( char * sptr, char * prefix )
{
	int	elements=0;
	char *	rptr=(char *) 0;
	char *	hptr=(char *) 0;
	int	i;
	if (!( sptr ))
		return( sptr );
	else if (!(sptr = allocate_string( sptr ) ))
		return( sptr );
	for (i=0; *(sptr+i) != 0; i++ ) {
		if ( *(sptr+i) == ',' )
			*(sptr+i) = ' ';
		/* FCH_SING ajout de ';'*/
		if ( *(sptr+i) == ';' )
			*(sptr+i) = ' ';
#ifndef	WIN32
		if ( *(sptr+i) == ':' )
			*(sptr+i) = ' ';
#endif
		else if ( *(sptr+i) == '|' )
			*(sptr+i) = ' ';
		if ( *(sptr+i) == ' ');
			elements++;
		}
	hptr = sptr;
	if (( rptr = allocate( strlen(sptr) + (elements * (strlen(prefix)+2)) + 256 ) ) != (char *) 0) {
		i = 0;
		while ( *(sptr+i) != 0 ) {
			if ( *(sptr+i) == ' ' ) {
				if (!( i )) {
					sptr++;
					continue;
					}
				else	{
					*(sptr+i) = 0;
					strcat(rptr,prefix);
					strcat(rptr,sptr);
					sptr += (i+1); i= 0;
					}
				}
			else	i++;
			}
		if (i)	{
			*(sptr+i) = 0;
			strcat(rptr,prefix);
			strcat(rptr,sptr);
			}
		}
	liberate( hptr );
	return( rptr );

}

private	char *	prepare_abal_inclusion( char * sptr )
{
#ifdef WIN32
	return( build_abal_command_blank_allowed( sptr, "-i", "\"") );
#else
	return( build_abal_command( sptr, " -i") );
#endif
}

private	char *	prepare_abal_jinclusion( char * sptr )
{
#ifdef WIN32
	return( build_abal_command_blank_allowed( sptr, "-j", "\"") );
#else
	return( build_abal_command( sptr, " -j") );
#endif
}

private	char *	prepare_abal_defines( char * sptr )
{
	return( build_abal_command( sptr, " -n") );
}


public	void	set_abal_path_selection(int mode)
{
	char *	pptr=(char *) 0;
	char *	sptr=(char *) 0;
	char *	rptr=(char *) 0;
	char *	getcwd();

	switch (mode) {
		case	0	:	/* ctr */
			sptr = SingConf->atr.path;
			break;
		case	1	:	/* atr */
			sptr = SingConf->atr.path;
			break;
		case	2	:	/* otr */
			sptr = SingConf->otr.path;
			break;
		default		:
			return;

		}

	if (!( pptr = getcwd(Context.string_buffer,Context.string_buffer_length)))
		return;

	if (!(sptr))
		rptr = allocate( strlen( pptr ) );
	else 	rptr = allocate( strlen( pptr ) + strlen( sptr ) + 16 );

	if ( rptr ) {
#ifdef	WIN32
		sprintf(rptr,"%s\\|%s",pptr,sptr);
#else
		sprintf(rptr,"%s/:%s",pptr,sptr);
#endif
		SetPathSelection( rptr );
		liberate( rptr );
		}
	return;
}


#ifdef ABALCPP
public	int	translate_abal(int translator,char * filename, int automatic,void *this_param)
#else
public	int	translate_abal(int translator,char * filename, int automatic)
#endif
{
	char *	gptr=(char *) 0;
	char *	iptr=(char *) 0;
	char *	jptr=(char *) 0;
	char *	nptr=(char *) 0;
	char *	mptr=(char *) 0;
	char *	pptr;
	char * 	sptr;
	char *	tptr=(char *) 0;
	char *	dptr;
	char *	vptr;
	char *	optr;
	char *	aptr;
	struct	translator_configuration * xptr;
	char *	fnptr;
	int	ilen=0;
	int	jlen=0;
	int	nlen=0;
	int	status=0;
	char *app_object=(char *)0;
	char xworkbuffer[512];

	if (!( SingConf ))
		return( 0 );

	if ((!( Abal_Config.generate_program ))
	&&  (!( Abal_Config.generate_overlay )))
		return(0);

	switch ( translator ) {
		case	2	: /* CTR */
			if (!(xptr = ctr)) {
	 			if (!(ctr = allocate( sizeof(struct translator_configuration) )))
					return(0);
				else	{
					xptr = ctr;
					ctr->verbose=0;	ctr->debug=0;
					ctr->liste=0;	ctr->trace=0;
					ctr->optimise=0;
					set_translation_options( ctr, SingConf->atr.options );
					}		
				}
			break;

		case	0	: /* ATR */
			if (!(xptr = atr)) {
	 			if (!(atr = allocate( sizeof(struct translator_configuration) )))
					return(0);
				else	{
					xptr = atr;
					atr->verbose=0;	atr->debug=0;
					atr->liste=0;	atr->trace=0;
					atr->optimise=0;
					set_translation_options( atr, SingConf->atr.options );
					}		
				}
			break;
		case	1	: /* OTR */
			if (!(xptr = otr)) {
	 			if (!(otr = allocate( sizeof(struct translator_configuration) )))
					return(0);
				else	{
					xptr = otr;
					set_translation_options( otr, SingConf->otr.options );
					}		
				}
			break;
		default		:
			return(0);
		}

	if (!( filename ))
		fnptr = (char *) 0;

	else if (!( fnptr = allocate_string( filename )))
		return(0);

	switch ( translator ) {
		case	2	: /* CTR */
			if (!( automatic & _INHIBIT_PROPERTIES )) {
				if (!( CobolTranslator ))
					CobolTranslator = allocate_string( "/opt/prologue/bin/ctr32" );
#ifdef ABALCPP
				if ( accept_traductionpp( &fnptr, 
						&CobolTranslator,
						&xptr->debug, 	&xptr->trace, 
						&xptr->verbose, &xptr->liste,
						&xptr->optimise,&xptr->compact, 
						&SingConf->atr.path,this_param ) == 27 ) {
#else
				if ( accept_traduction( &fnptr, 
						&CobolTranslator,
						&xptr->debug, 	&xptr->trace, 
						&xptr->verbose, &xptr->liste,
						&xptr->optimise,&xptr->compact, 
						&SingConf->atr.path ) == 27 ) {
#endif
					fnptr = liberate( fnptr );
					return(0);
					}
				}
			iptr = SingConf->atr.path;
			nptr = SingConf->atr.define;
			pptr = CobolTranslator;
			break;
		case	0	: /* ATR */
			if (!( automatic & _INHIBIT_PROPERTIES )) {
#ifdef ABALCPP
				if ( accept_traductionpp( &fnptr, 
						&SingConf->atr.program,
						&xptr->debug, 	&xptr->trace, 
						&xptr->verbose, &xptr->liste,
						&xptr->optimise,&xptr->compact, 
						&SingConf->atr.path,this_param ) == 27 ) {
#else
				if ( accept_traduction( &fnptr, 
						&SingConf->atr.program,
						&xptr->debug, 	&xptr->trace, 
						&xptr->verbose, &xptr->liste,
						&xptr->optimise,&xptr->compact, 
						&SingConf->atr.path ) == 27 ) {
#endif
					fnptr = liberate( fnptr );
					return(0);
					}
				}
			iptr = SingConf->atr.path;
			nptr = SingConf->atr.define;
			pptr = SingConf->atr.program;
			break;
		case	1	: /* OTR */
			if (!( automatic & _INHIBIT_PROPERTIES )) {
#ifdef ABALCPP
				if ( accept_traductionpp( &fnptr, 
						&SingConf->otr.program,
						&xptr->debug, 	&xptr->trace, 
						&xptr->verbose, &xptr->liste,
						&xptr->optimise,&xptr->compact,
						&SingConf->otr.path,this_param ) == 27) {
#else
				if ( accept_traduction( &fnptr, 
						&SingConf->otr.program,
						&xptr->debug, 	&xptr->trace, 
						&xptr->verbose, &xptr->liste,
						&xptr->optimise,&xptr->compact,
						&SingConf->otr.path ) == 27) {
#endif
					fnptr = liberate( fnptr );
					return(0);
					}
				}
			iptr = SingConf->otr.path;
			nptr = SingConf->otr.define;
			pptr = SingConf->otr.program;
			break;
		}

	if (( not_blank( nptr ) )
	&&  (( nptr = prepare_abal_defines( nptr )) != (char *) 0)) 
		nlen = (strlen( nptr ) + 16 );
	else 	{
		nptr = (char *) 0;
		nlen = 0;
		}

	if (( not_blank( jptr=iptr ) )
	&&  (( jptr = prepare_abal_jinclusion( jptr )) != (char *) 0)) 
		jlen = (strlen( jptr ) + 16 );
	else	{
		jlen = 0;
		jptr = (char *) 0;
		}

	if (( not_blank( iptr ) )
	&&  (( iptr = prepare_abal_inclusion( iptr )) != (char *) 0)) 
		ilen = (strlen( iptr ) + 16 );
	else	{
		ilen = 0;
		iptr = (char *) 0;
		}

	if (!( pptr )) {
		fnptr = liberate( fnptr );
		if (iptr) liberate(iptr);
		return(0);
		}
	else if (!( sptr = allocate( strlen( pptr ) + (strlen( fnptr )*2) + 256 + ilen + jlen + nlen ))) {
		fnptr = liberate( fnptr );
		if (iptr) liberate(iptr);
		return(0);
		}
	else	{

		if ( xptr->compact )
			aptr = " -a";
		else	aptr = "\0";

		if ( xptr->debug ) {
			if ( xptr->liste )
				dptr = " -ml";
			else	dptr = " -m";
			}

		else if ( xptr->liste )
			dptr = " -l";
		else	dptr = "\0";

		if ( xptr->trace )
			{
			xworkbuffer[0]=0;
			fn_parser( filename, xworkbuffer, 0x000F );
			if (!( tptr = allocate(strlen(filename) + 16) )) {
				fnptr = liberate( fnptr );
				sptr = liberate( sptr );
				if (iptr) liberate(iptr);
				return(0);
				}
			sprintf(tptr," -e%s",xworkbuffer);
			}
		else if (!( tptr = allocate_string("\0") )) {
			fnptr = liberate( fnptr );
			sptr = liberate( sptr );
			if (iptr) liberate(iptr);
			return(0);
			}

		if ( xptr->verbose )
			vptr = " -v";
		else	vptr = "\0";

		if ( xptr->optimise )
			optr = " -o";
		else	optr = "\0";

		if (!( mptr = nptr ))
			mptr = "\0";

		if ( method_is_valid((gptr = application_object_production())) ) {

			if (!( app_object=allocate(strlen(gptr)+strlen(filename)+32) )) {
				fnptr = liberate( fnptr );
				sptr = liberate( sptr );
				tptr = liberate( tptr );
				if (iptr) liberate(iptr);
				return(0);
				}				
			sprintf(app_object,"%c-d%s",__QUOTE,gptr);
			add_path_terminator(&app_object);
			fn_parser( filename, xworkbuffer, 0x0008 );
			strcat(app_object,xworkbuffer);
			sprintf((app_object+strlen(app_object)),"%c",__QUOTE);
			gptr = liberate( gptr );
			}
		else if (!( app_object=allocate_string("\0") )) {
			fnptr = liberate( fnptr );
			sptr = liberate( sptr );
			tptr = liberate( tptr );
			if (iptr) liberate(iptr);
			return(0);
			}				

		if ( not_blank( iptr ) ) {
			if ( not_blank( jptr ) ) {
				sprintf(sptr,"%s -sas %s %s %s %s %s%s%s%s %s \"%s\"",
					pptr,iptr,jptr,aptr,mptr,
					dptr,tptr,vptr,optr,app_object,fnptr);
				}
			else	{
				sprintf(sptr,"%s -sas %s %s %s %s%s%s%s %s \"%s\"",
					pptr,iptr,aptr,mptr,
					dptr,tptr,vptr,optr,app_object,fnptr);
				}
			}
		else if ( not_blank( jptr ) ) {
			sprintf(sptr,"%s -sas %s %s %s %s%s%s%s %s \"%s\"",
				pptr,jptr,aptr,mptr,
				dptr,tptr,vptr,optr,app_object,fnptr);

			}
		else	{
			sprintf(sptr,"%s -sas %s %s %s%s%s%s %s \"%s\"",
				pptr,aptr,mptr,
				dptr,tptr,vptr,optr,app_object,fnptr);
			}
		status_message(sptr,3);

#ifdef WIN32
		if ( windows_create_process( sptr, TRUE ) != 0 ) {
#else
		if ( use_system_d() != 0 )
			status = SystemV(sptr);
		else	{
			if ( Context.compiling & 2 )
				printf("%s\r\n",sptr);
			else if ( xptr->verbose )
				printf("%s\r\n",sptr);
			if ((status = system( sptr)) == -1)
				system_failure( sptr );
			}
		if ( status != 0 ) {
#endif
			if ( Context.compiling ) {
				cancel_automatic_production();
				status=0;
				}
			else	{
				status = 0;
				x_event(36); /* problem cursor */
				switch ( xptr->trace ) {
					case	0	:	/* OFF 		*/
						break;
					case	1	:	/* Enhanced	*/
						if (!( trace_model(fnptr)))			
							trace_editor(fnptr);
						break;
					case	2	:	/* STD : AED 	*/
						trace_editor(fnptr);
						break;
					}
				x_event(33); /* normal cursor */
				}
			}
		else	status = 1;
		status_message("completed",3);

		sptr  = liberate( sptr );
		fnptr = liberate( fnptr );
		if ( iptr ) 
			iptr = liberate( iptr );
		if ( nptr ) 
			nptr = liberate( nptr );
		if (app_object) liberate(app_object);
		if (tptr) liberate(tptr);
		}
	return(status);
}

public	void	use_abal_translator(char * sptr, int automatic)
{
#ifdef ABALCPP
	if (!( translate_abal(1,sptr,automatic,NULL) ))
#else
	if (!( translate_abal(1,sptr,automatic) ))
#endif
		draw_console();
	return;
}

#endif	/* _abaltrad_c */
	/* ----------- */


