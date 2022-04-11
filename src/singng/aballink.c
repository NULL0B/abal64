#ifndef	_aballink_c
#define	_aballink_c

#include "singappl.h"

extern	struct	application_parameters Application;
public	char *	forms_modules(struct form_control * fptr,char * sptr);
private	char *	build_abal_command_blank_allowed( char * sptr, char * prefix, char * encaps );

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

public	void	configure_linker( char * cptr )
{
	set_linker_options( cptr );
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

		if ( *target != ' ' ) {
			fn_parser(target,old.targetname,0x000F);
			strcat(old.targetname,AT_EXTENSION);
			}
		else	*old.targetname = 0;

		if ( modules ) {

			if (!( old.modules = allocate( strlen( modules ) + strlen( old.targetname ) + 32 ) )) {
				allocate_failure();
				return(27);
				}

			if ( *target != ' ' ) {
				fn_parser(target,old.modules,0x000F);
				strcat(old.modules,O_EXTENSION);
				strcat(old.modules," ");
				}
			else	*old.modules = 0;

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


/*	-------------------------------------------------------------	*/
/*		a b a l _ m o d u l e s ( result, source )		*/
/*	-------------------------------------------------------------	*/
/*									*/
/*	Performs analysis of the forms construction string to detect	*/
/*	eventual module names to be used for the link phase.		*/
/*	The modules themselves will be analysed, when xml ressources	*/
/*	are found to exist, and eventual subordinate modules will be	*/
/*	appended to the list.						*/
/*	-------------------------------------------------------------	*/


struct	module_control	{
	char 			* oname;	/* tcode object name			*/
	char 			* xname;	/* tcode object name			*/
	char 			* iname;	/* identifier   name			*/
	struct module_control 	* next;		/* next module in the list		*/
	struct form_control 	* form;		/* parent ressource form		*/
	};

private	struct	module_control * GlobalModuleControl=(struct module_control *) 0;

struct	string_control	{
	char 			* construction;
	int			  waiting;
	struct string_control 	* next;
	};

public	int	add_module_control( char * nptr )
{
	struct	module_control * mptr;
	if (!( nptr )) return(0);
	for (	mptr=GlobalModuleControl;
		mptr != (struct	module_control *) 0;
		mptr = mptr->next)
		if (!( strcmp( nptr, mptr->iname ) ))
			return(0);

	if (!( mptr = allocate( sizeof( struct module_control ) )))
		return(0);
	else if (!(mptr->iname = allocate_string( nptr ))) {
		liberate( mptr );
		return(0);
		}
	else	{
		mptr->oname = mptr->xname = (char *) 0;
		mptr->form  = (struct form_control *) 0;
		mptr->next  = GlobalModuleControl;
		GlobalModuleControl = mptr;
		return(1);
		}
}

public	void	drop_module_control()
{
	struct	module_control * mptr;
	while ((mptr=GlobalModuleControl)!= (struct module_control *) 0) {
		GlobalModuleControl = mptr->next;
		if ( mptr->iname )
			liberate( mptr->iname );
		liberate( mptr );
		}
	GlobalModuleControl=(struct module_control *) 0;
	return;
}

public	char *		abal_modules(char * rptr, char * sptr)
{
	char	*	tptr;
	int		c;
	int		modules=0;
	char 	*	xptr;
	char	*	nptr;
	char	*	smptr;
	int		i;
	char	*	modulelist=(char *) 0;
	char	*	moduletemp=(char *) 0;

	struct form_control 	* locate_form_control( char * nptr );
	struct module_control 	* root=(struct module_control *) 0;
	struct module_control 	* work=(struct module_control *) 0;
	struct module_control 	* foot=(struct module_control *) 0;
	struct module_control 	* temp=(struct module_control *) 0;

	struct string_control 	* sroot=(struct string_control *) 0;
	struct string_control 	* swork=(struct string_control *) 0;
	struct string_control 	* sheap=(struct string_control *) 0;
	struct string_control 	* sfoot=(struct string_control *) 0;

	if (!(xptr = sptr))	return(xptr);


	while (1) {

	/* ---------------------------------------------------- */
	/* analyse construction string to separate module names */
	/* ---------------------------------------------------- */
	while ( *sptr != 0 ) {

		/* --------------------- */
		/* step over white space */
		/* --------------------- */
		while ( *sptr ) {
			if (( *sptr == ' ' )
			||  ( *sptr == '\t')
			||  ( *sptr == '\r')
			||  ( *sptr == '\n'))
				sptr++;
			else	break;
			}
		if (!( *sptr ))	break;

		/* ------------------------------- */
		/* step to next white space or end */
		/* ------------------------------- */
		tptr = sptr;
		while ( *tptr != 0 ) {
			if (( *tptr == ' ' )
			||  ( *tptr == '\t')
			||  ( *tptr == '\r')
			||  ( *tptr == '\n'))
				break;
			else	tptr++;
			}

		/* ------------------------------ */
		/* Allocate a Module Control Node */
		/* ------------------------------ */
		c = *tptr; *tptr = 0;

		if (!( work = allocate( sizeof( struct module_control ) )))
			break;
		if (!( work->oname = allocate_string( sptr ) )) {
			liberate( work );
			break;
			}
		else if (!( work->oname = enforce_extension( work->oname, O_EXTENSION ) )) {
			liberate( work );
			break;
			}
		else if (!( work->xname = allocate_string( sptr ) )) {
			liberate( work->oname );
			liberate( work );
			break;
			}
		else if (!( work->xname = enforce_extension( work->xname, XML_EXTENSION ) )) {
			liberate( work );
			break;
			}
		else if (!( work->iname = allocate_string( sptr ) )) {
			liberate( work->oname );
			liberate( work->xname );
			liberate( work );
			break;
			}
		else	{
			/* --------------------------- */
			/* remove identifier extension */
			/* --------------------------- */
			for ( i=0, nptr = work->iname; *(nptr+i) != 0; i++ ) {
				if ( *(nptr+i) == '.' ) {
					*(nptr+i) = 0;
					break;
					}
				}
 				
			work->form = (struct form_control *) 0;
			work->next = (struct module_control *) 0;

			/* ----------------- */
			/* Detect duplicates */
			/* ----------------- */
			for (	temp=root;
				temp != (struct module_control *) 0;
				temp = temp->next ) {
				if (!( temp->iname ))
					continue;
				if (!( work->iname ))
					continue;
				if (!( string_compare( temp->iname, work->iname ) ))
					continue;
				else	{
					/* ------------------- */					
					/* eliminate duplicate */
					/* ------------------- */					
					if ( work->oname )
						liberate( work->oname );
					if ( work->xname )
						liberate( work->xname );
					if ( work->iname )
						liberate( work->iname );
					liberate( work );
					work = (struct module_control *) 0;
					break;
					}
				}

			/* --------------------------------- */
			/* if module has not been eliminated */
			/* --------------------------------- */
			if ( work != (struct module_control *) 0) {				

				/* --------------------- */
				/* resolve eventual form */
				/* --------------------- */
				if ((work->form = locate_form_control( work->iname )) != (struct form_control *) 0) {

					/* ----------------------------------------- */
					/* allocate construction string control node */	
					/* ----------------------------------------- */
					if ((swork = allocate( sizeof ( struct string_control ) )) != (struct string_control *) 0) {
						swork->waiting = 1;
						/* ------------------------------------ */
						/* detect eventual modular construction */
						/* ------------------------------------ */
						if ( work->form->construction )
							smptr = allocate_string( work->form->construction );
						else 	smptr = (char *) 0;
						if (!( swork->construction = forms_modules( work->form, smptr )))
							liberate( swork );
						else 	{
							if (!( sroot )) {
								sroot = swork;
								}
							else	sfoot->next = swork;
							sfoot = swork;
							}	
						}
					}

				if (!( foot ))
					root = work;
				else 	foot->next = work;
				foot = work;

				modules++;
				}

			}

		if ( work ) {
			/* --------------------------------- */
			/* transfer to callers result buffer */
			/* --------------------------------- */
			if ( rptr ) {
				strcat( rptr, " ");
				strcat( rptr, sptr );
				}
			}

		*tptr = c;
		sptr = tptr;
		}

		/* -------------------------------- */
		/* Detect other forms to be scanned */
		/* -------------------------------- */
		sptr= (char *) 0;

		for (	sheap=sroot;
			sheap!=(struct string_control *) 0;
			sheap = sheap->next ) {
			if (!( sheap->waiting ))
				continue;
			else if (!( sptr = sheap->construction ))
				continue;
			else	{
				sheap->waiting = 0;
				break;
				}
			}
		if (!( sptr ))
			break;
		}


	modules=0;

	/* --------------------------------------------------- */
	/* count modules in control list and build module list */
	/* --------------------------------------------------- */
	for ( 	work=root;
		work != (struct module_control *) 0;
		work = work->next ) {
		if (!( modulelist ))
			modulelist = allocate_string( work->oname );
		else if (!( moduletemp = allocate( strlen( modulelist ) + strlen( work->oname ) + 16)))
			break;
		else	{
			sprintf(moduletemp,"%s %s",modulelist,work->oname);
			liberate( modulelist );
			modulelist = moduletemp;
			}
		modules++;
		}

	/* ------------------------ */
	/* drop module control list */
	/* ------------------------ */
	while ((work = root ) != (struct module_control *) 0) {
		if ( work->oname )
			liberate( work->oname );
		if ( work->xname )
			liberate( work->xname );
		if ( work->iname )
			liberate( work->iname );
		root = work->next;
		liberate( work );
		}

	/* ------------------------ */
	/* drop string control list */
	/* ------------------------ */
	while ((swork = sroot ) != (struct string_control *) 0) {
		if ( swork->construction )
			liberate( swork->construction );
		sroot = swork->next;
		liberate( swork );
		}

	/* ------------------------------------------------------- */
	/* determine if any modules have been provided or detected */
	/* ------------------------------------------------------- */
	liberate( xptr ); return( modulelist );	

#ifdef	oldways
	if (!( modules )) {
		liberate( xptr );
		return( (char *) 0 );
		}
	else	{
		return(xptr);
		}
#endif
}






public	void	link_abal(char * rootname, char * modules, int automatic, int mode)
{
	char	quote[2];
	char *	dptr=(char *) 0;
	int	status=0;
	char *	cptr;
	int	l;
	char *	iptr=(char *) 0,*iobj_product=(char *)0,*obj_name,*app_objects;

	if (!( SingConf ))
		return;
	
	if ( method_is_valid((app_objects = application_object_production())) ) {
		add_path_terminator(&app_objects);
		obj_name=relative_filename(rootname, app_objects );
		app_objects=liberate(app_objects);
		}
	else	obj_name=allocate_string(rootname);

	if ( prepare_abal_linker( obj_name, modules )  != 0)
		return;

	liberate(obj_name);

	if (!( automatic & _INHIBIT_PROPERTIES )) {
		if ( accept_linker_parameters( 
			&SingConf->old.program,
			&old.target, 		&old.targetname,
			&old.report, 		&old.reportname,
			&old.debug,
			&old.sourcetrace,	&old.targettrace,
			&old.verbose,
			&old.modules,		&SingConf->old.path
			) == 27 ) {
			release_linker_context();
			return;
			}
		}
	/* build quote string */
	quote[0] = 0x0022; quote[1] = 0;

	if (( SingConf->old.program != (char *) 0 )
	&&  ( old.modules    != (char *) 0)) {
		l = strlen( SingConf->old.program ) + strlen( old.modules );
		if (( SingConf->old.path )
		&&  ((iptr = prepare_abal_inclusion( SingConf->old.path )) != (char *) 0)) {
			l += strlen( iptr ); 
			}
		if ( method_is_valid((dptr = application_object_production()))) {
			if (iobj_product=build_abal_command_blank_allowed( dptr, "-i", quote)) {
				l += strlen( iobj_product ); 
				}
			dptr=liberate( dptr );
			}
		if (( old.report )
		&&  ( old.reportname ))
			l += (strlen(old.reportname)+4);
		if (( old.target )
		&&  ( old.targetname ))
			l += (strlen(old.targetname)+4);
		l += ((old.debug + old.verbose + old.sourcetrace + old.targettrace)*4);
		if ((cptr = allocate( (l+256) )) != (char *) 0) {
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
			if ( SingConf->old.path   ) {
				strcat(cptr,iptr);
				}
			if ( iobj_product   ) {
				strcat(cptr,iobj_product);
				}
			if ((old.modules = abal_modules(cptr,old.modules)) != (char *) 0 ) {
				status_message(cptr,3);
#ifdef WIN32
				windows_create_process( cptr, TRUE );
#else
				if ( use_system_d() != 0 )
					status = SystemV(cptr);
				else	{
					if ( Context.compiling & 2 )
						printf("%s\r\n",cptr);
					else if ( old.verbose ) 
						printf("%s\r\n",cptr);
					status = system( cptr);
					}
				if ( status != 0 ) {
					linker_failure( rootname );
					}
				if (!( use_system_d() )) {
					if ( old.verbose ) printf("\r\ncompleted\r\n");
					}
#endif
				status_message("completed",3);
				}
			liberate( cptr );
			}
		}
	if ( iobj_product ) {  	liberate( iobj_product );	}
	if ( iptr ) {  	liberate( iptr );	}
	release_linker_context();
	return;

}

public	void	use_abal_linker(char * nptr,int automatic)
{
	link_abal(nptr,application_modules(),automatic,1);	
	return;
}
#endif	/* aballink_c */
	/* ---------- */


