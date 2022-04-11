#ifndef	_abaltrad_c
#define	_abaltrad_c

static	struct	translator_configuration * otr=(struct translator_configuration*) 0;
static	struct	translator_configuration * atr=(struct translator_configuration*) 0;
static	struct	translator_configuration * ctr=(struct translator_configuration*) 0;

char	*	CobolTranslator=(char *) 0;

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

#include "singtrac.c"

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
	if (( rptr = allocate( strlen(sptr) + (elements * (strlen(prefix)+2)) + 16 ) ) != (char *) 0) {
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
	return( build_abal_command( sptr, " -i") );
}

private	char *	prepare_abal_jinclusion( char * sptr )
{
	return( build_abal_command( sptr, " -j") );
}

private	char *	prepare_abal_defines( char * sptr )
{
	return( build_abal_command( sptr, " -n") );
}


public	int	translate_abal(int translator,char * filename, int automatic)
{
	char *	iptr=(char *) 0;
	char *	jptr=(char *) 0;
	char *	nptr=(char *) 0;
	char *	mptr=(char *) 0;
	char *	pptr;
	char * 	sptr;
	char *	tptr;
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
				if ( accept_traduction( &fnptr, 
						&CobolTranslator,
						&xptr->debug, 	&xptr->trace, 
						&xptr->verbose, &xptr->liste,
						&xptr->optimise,&xptr->compact, 
						&SingConf->atr.path ) == 27 ) {
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
				if ( accept_traduction( &fnptr, 
						&SingConf->atr.program,
						&xptr->debug, 	&xptr->trace, 
						&xptr->verbose, &xptr->liste,
						&xptr->optimise,&xptr->compact, 
						&SingConf->atr.path ) == 27 ) {
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
				if ( accept_traduction( &fnptr, 
						&SingConf->otr.program,
						&xptr->debug, 	&xptr->trace, 
						&xptr->verbose, &xptr->liste,
						&xptr->optimise,&xptr->compact,
						&SingConf->otr.path ) == 27) {
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
		return(0);
		}
	else if (!( sptr = allocate( strlen( pptr ) + strlen( fnptr ) + 64 + ilen + nlen ))) {
		fnptr = liberate( fnptr );
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
			tptr = " -e";
		else	tptr = "\0";

		if ( xptr->verbose )
			vptr = " -v";
		else	vptr = "\0";

		if ( xptr->optimise )
			optr = " -o";
		else	optr = "\0";

		if (!( mptr = nptr ))
			mptr = "\0";

		if ( not_blank( iptr ) ) {
			if ( not_blank( jptr ) ) {
				sprintf(sptr,"%s -sas %s %s %s %s %s%s%s%s %s",
					pptr,iptr,jptr,aptr,mptr,
					dptr,tptr,vptr,optr,fnptr);
				}
			else	{
				sprintf(sptr,"%s -sas %s %s %s %s%s%s%s %s",
					pptr,iptr,aptr,mptr,
					dptr,tptr,vptr,optr,fnptr);
				}
			}
		else if ( not_blank( jptr ) ) {
			sprintf(sptr,"%s -sas %s %s %s %s%s%s%s %s",
				pptr,jptr,aptr,mptr,
				dptr,tptr,vptr,optr,fnptr);

			}
		else	{
			sprintf(sptr,"%s -sas %s %s %s%s%s%s %s",
				pptr,aptr,mptr,
				dptr,tptr,vptr,optr,fnptr);
			}
		status_message(sptr,3);
		if ( xptr->verbose )
			printf("%s\n",sptr);

		if ( system( sptr ) != 0 ) {
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
		else	status = 1;
		status_message("completed",3);

		if ( xptr->verbose )
			printf("\ncompleted\n");
		sptr  = liberate( sptr );
		fnptr = liberate( fnptr );
		if ( iptr ) 
			iptr = liberate( iptr );
		if ( nptr ) 
			nptr = liberate( nptr );
		}
	return(status);
}

public	void	use_abal_translator(char * sptr, int automatic)
{
	if (!( translate_abal(1,sptr,automatic) ))
		draw_console();
	return;
}

#endif	/* _abaltrad_c */
	/* ----------- */


