#ifndef	_aballink_c
#define	_aballink_c

static	struct	linker_configuration {
	int	configured;
	int	target;
	int	report;
	int	debug;
	int	verbose;
	int	targettrace;
	int	sourcetrace;
	char *	reportname;
	char *	targetname;
	char *	modules;
	char *	inclusion;
	} old = { 0,0,0,0,0,0,(char *) 0,(char *) 0,(char *) 0, (char *) 0 };

public	void	initialise_abal_linker()
{
	old.target = old.report = old.debug = old.verbose =
	old.sourcetrace = old.targettrace = 0;
	old.reportname = old.targetname = (char *) 0;
	old.configured = 0;
	return;
}

private	void	release_linker_context()
{
	if ( old.targetname ) 	old.targetname 	= liberate( old.targetname );
	if ( old.reportname ) 	old.reportname 	= liberate( old.reportname );
	if ( old.modules    ) 	old.modules 	= liberate( old.modules    );
	if ( old.inclusion  ) 	old.inclusion 	= liberate( old.inclusion  );
	return;
}

public	void	liberate_abal_linker()
{
	release_linker_context();
	return;
}

private	void	set_linker_options( char * sptr )
{
	if (!( sptr ))	return;

	while ( *sptr ) {
		switch ( *(sptr++) ) {
			case	'v'	:
			case	'V'	:
				old.verbose=1; 
				continue;
			case	'm'	:
			case	'M'	:
				old.debug=1; 
				continue;
			case	'r'	:
			case	'R'	:
				old.report=1;
				continue;
			case	'd'	:
			case	'D'	:
				old.target=1; 
				continue;
			case	's'	:
			case	'S'	:
				old.sourcetrace=1;
				continue;
			case	't'	:
			case	'T'	:
				old.targettrace=1;
				continue;
			}

		}
	return;
}


private	int	prepare_abal_linker( char * target, char * modules )
{
	char	*	sptr;

	if (!( SingConf ))
		return(56);

	release_linker_context();

	if (!( old.configured ))
		set_linker_options( SingConf->old.options );

	if ( target ) {

		if (!( old.targetname = allocate(( strlen( target ) + 32) ) )) {
			allocate_failure();
			return(27);
			}

		fn_parser(target,old.targetname,0x000F);
		strcat(old.targetname,AT_EXTENSION);

		if ( modules ) {
			if (!( old.modules = allocate( strlen( modules ) + strlen( target ) + 32 ) )) {
				allocate_failure();
				return(27);
				}

			fn_parser(target,old.modules,0x000F);
			strcat(old.modules,O_EXTENSION);
			strcat(old.modules," ");
			strcat(old.modules,modules);
			
			for ( sptr=old.modules; *sptr != 0; sptr++ ) {
				switch ( *sptr ) {
					case	'\t'	:
					case	'\n'	:
					case	'\r'	:
						*sptr = ' ';
					}
				}
			}
		}
	return(0);	
}

public	int	abal_modules(char * rptr, char * sptr)
{
	char	*	tptr;
	int		c;
	int		modules=0;

	if (!( sptr ))	return(modules);

	while ( *sptr != 0 ) {

		/* step over white space */
		while ( *sptr ) {
			if (( *sptr == ' ' )
			||  ( *sptr == '\t')
			||  ( *sptr == '\r')
			||  ( *sptr == '\n'))
				sptr++;
			else	break;
			}
		if (!( *sptr ))	break;

		/* step to next white space or end */
		tptr = sptr;
		while ( *tptr != 0 ) {
			if (( *tptr == ' ' )
			||  ( *tptr == '\t')
			||  ( *tptr == '\r')
			||  ( *tptr == '\n'))
				break;
			else	tptr++;
			}
		if ( rptr ) {
			c = *tptr;
			*tptr = 0;
			strcat( rptr, " ");
			strcat( rptr, sptr );
			*tptr = c;
			}
		sptr = tptr;
		modules++;
		}
	return(modules);
}






public	void	link_abal(char * rootname, char * modules, int automatic)
{
	char *	cptr;
	int	l;
	char *	iptr=(char *) 0;

	if (!( SingConf ))
		return;
	if ( prepare_abal_linker( rootname, modules )  != 0)
		return;

	if (!( automatic & _INHIBIT_PROPERTIES )) {
		if ( accept_linker_parameters( 
			&SingConf->old.program,
			&old.target, 		&old.targetname,
			&old.report, 		&old.reportname,
			&old.debug,
			&old.sourcetrace,	&old.targettrace,
			&old.verbose,
			&old.modules,		&old.inclusion
			) == 27 ) {
			release_linker_context();
			return;
			}
		}

	if (( SingConf->old.program != (char *) 0 )
	&&  ( old.modules    != (char *) 0)) {
		l = strlen( SingConf->old.program ) + strlen( old.modules );
		if (( old.inclusion )
		&&  ((iptr = prepare_abal_inclusion( old.inclusion )) != (char *) 0)) {
			l += strlen( iptr ); 
			}
		if (( old.report )
		&&  ( old.reportname ))
			l += (strlen(old.reportname)+4);
		if (( old.target )
		&&  ( old.targetname ))
			l += (strlen(old.targetname)+4);
		l += ((old.debug + old.verbose + old.sourcetrace + old.targettrace)*4);
		if ((cptr = allocate( (l+16) )) != (char *) 0) {
			strcpy(cptr,SingConf->old.program);
			if (( old.report )
			&&  ( old.reportname )) {
				strcat(cptr," -r");
				strcat(cptr,old.reportname);
				}
			if (( old.target )
			&&  ( old.targetname )) {
				strcat(cptr," -d");
				strcat(cptr,old.targetname);
				}
			if ( old.verbose     ) strcat(cptr," -v");
			if ( old.debug       ) strcat(cptr," -m");
			if ( old.targettrace ) strcat(cptr," -zt");
			if ( old.sourcetrace ) strcat(cptr," -zs");
			if ( old.inclusion   ) {
				strcat(cptr,iptr);
				}
			if ( abal_modules(cptr,old.modules) ) {
				status_message(cptr,3);
				if ( old.verbose ) printf("%s\r\n",cptr);
				system( cptr );
				status_message("completed",3);
				if ( old.verbose ) printf("\r\ncompleted\r\n");
				}
			liberate( cptr );
			}
		}
	if ( iptr ) {  	liberate( iptr );	}
	release_linker_context();
	return;

}

public	void	use_abal_linker(char * nptr,int automatic)
{
	link_abal(nptr," ",automatic);	
	return;
}
#endif	/* aballink_c */
	/* ---------- */

