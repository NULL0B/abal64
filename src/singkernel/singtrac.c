#ifndef	_singtrace_c
#define	_singtrace_c

#include "singtrac.h"

struct	abal_trace *	allocate_tracenode()
{
	struct	abal_trace * tptr;
	if (!( tptr = allocate( sizeof( struct	abal_trace ) ) ))
		return( tptr );
	else	{
		tptr->fileline   =
		tptr->column	 =
		tptr ->type 	 = 0;
		tptr->filename 	 =
		tptr->message	 =
		tptr->expression = (char *) 0;
		tptr->member 	 = (struct form_item *) 0;
		tptr->next	 = tptr->previous = (struct abal_trace *) 0;
		return( tptr );
		}
}

struct	abal_trace *	drop_tracenode( struct	abal_trace * tptr )
{
	if ( tptr ) {
		if ( tptr->filename )
			tptr->filename = liberate( tptr->filename );
		if ( tptr->message  )
			tptr->message = liberate( tptr->message );
		if ( tptr->expression )
			tptr->expression = liberate( tptr->expression );
		tptr = liberate( tptr );
		}
	return((struct	abal_trace *) 0);
}

private	void	drop_traceinfo( struct abal_trace * root )
{
	struct	abal_trace *	tptr;
	while	(( tptr = root) != (struct abal_trace *) 0) {
		root = tptr->next;
		drop_tracenode( tptr );
		}
	return;
}


private	int	loadtraceline( FILE * h, char * bptr, int blen )
{
	int	i=0;
	int	c;
	while ( i < blen ) {
		if (!( c = fgetc(h)))
			break;
		else if (c == -1)
			break;
		else if (c =='\n') {
			if (!( i ))
				continue;
			else	break;
			}
		else if ( c == '\r' )
			continue;
		else if ( c == '\t' )
			c = ' ';
		if (( c == ' ' ) &&  (!( i )))
			continue;
		else	{
			*(bptr+i) = c;
			i++;
			}
		}
	*(bptr+i) = 0;
	return(i);
}

private	char *	parsetracetoken( char * bptr, char ** rptr )
{
	char *	wptr;

	/* reset result */
	/* ------------ */
	*rptr = (char *) 0;

	/* copy pointer and step over space */
	/* -------------------------------- */
	if (!( wptr = bptr ))	return( wptr );
	while ( *wptr == ' ' ) wptr++;

	/* copy pointer and step to space */
	/* ------------------------------ */
	bptr = wptr;
	while ( *wptr ) {
		if ( *wptr  == ' ' )
			break;
		else	wptr++;
		}

	/* terminate token and step over space */
	/* ----------------------------------- */
	if ( *wptr == ' ' ) {
		*(wptr++) = 0;
		while ( *wptr == ' ' ) wptr++;
		}

	/* check, allocate and return results */
	/* ---------------------------------- */
	if ( *bptr ) { *rptr = allocate_string( bptr );	}
	return( wptr );
}

private	char *	parsetraceword( char * bptr, int * rptr )
{
	char *	wptr;
	*rptr = 0;
	bptr = parsetracetoken( bptr, & wptr );
	if ( wptr != (char *) 0 ) {
		while (( *wptr >= '0' ) && ( *wptr <= '9' ))
			*rptr = (( *rptr * 10 ) + ( *(wptr++) - '0' ));
		}
	return( bptr );
}


private	struct	abal_trace *	parsetraceline( char * bptr )
{
	struct	abal_trace *	tptr;
	char		   *	wptr;

	if (!( tptr = allocate_tracenode() ))
		return( tptr );

	/* Get filename */
	if (!( bptr = parsetracetoken(bptr, & tptr->filename ) ))
		return( tptr );
	/* Get fileline	*/
	if (!( bptr = parsetraceword(bptr, & tptr->fileline ) ))
		return( tptr );
	/* Get column 	*/
	if (!( bptr = parsetraceword(bptr, & tptr->column   ) ))
		return( tptr );

	/* Get member.method expression */
	if ( *bptr == '!' ) {
		if (!( bptr = parsetracetoken((bptr+1), & tptr->expression ) ))
			return( tptr );
		}

	/* Get Error Message and Details */
	tptr->message = allocate_string( bptr );
	return( tptr );
}

private	struct	abal_trace *	parse_tracefile( char * filename )
{
	struct	abal_trace *	root =(struct abal_trace *) 0;
	struct	abal_trace *	foot =(struct abal_trace *) 0;
	struct	abal_trace *	tptr;
	char		 *	buffer=(char *) 0;
	FILE 		 *	h=(FILE*)0;

	if (( h = fopen( filename , "r" )) != (FILE *) 0) {
		if (( buffer = allocate(1024) ) != (char *) 0) {
			while ( loadtraceline( h, buffer, 1024 ) != 0 ) {
				if (!( tptr = parsetraceline( buffer ) ))
					break;
				else if (!( tptr->previous = foot ))
					root = tptr;
				else 	foot->next = tptr;
				foot = tptr;
				}
			liberate( buffer );
			}
		fclose(h);
		}
	return(root);
}

private	int	edit_widget_method( char ** sptr, int fileline )
{
	int	event=0;
	char *	nptr=(char *) 0;
	filetransferin( &nptr, sptr );
	if (!( nptr ))
		return( 0 );
	else if (!( open_window_editor( 
			Context.DeskTop.x, Context.DeskTop.y,
			Context.DeskTop.w, Context.DeskTop.h, 
			nptr ) )) {
		filetransferdrop( nptr );
		return( 0 );
		}
	else	{
		editorOnSeek(0,fileline);

		show_window_editor();

		event = use_window_editor();

		close_window_editor();

		if ( event != _LEAVE_SING )
			filetransferout( &nptr, sptr );
		else	filetransferdrop( nptr );
		return(event);
		}
}

private	int	zoom_trace_method( struct abal_trace * tptr )
{
	struct	form_control * fptr;
	struct	form_item * iptr;
	int	fileline=0;
	char		  * sptr;
	char		  * mptr;
	int			i;
	int			event=0;
	if (!( tptr->expression ))
		return( 0 );
	else if (!( fptr = Context.Form ))
		return(0);
	else if (!( sptr = allocate_string( tptr->expression )))
		return(0);
	for (	i=0; *(sptr +i) != 0; i++ )
		if ( *(sptr+i) == '.' )
			break;

	if ( *(sptr+i) == '.' ) {
		*(sptr+i) = 0;
		i++;
		}
	mptr = (sptr+i);

	if ( upper_compare("this", sptr ) ) {
		close_window_editor();
		fileline=0; sptr=mptr;
		while ( *sptr ) {
			if ( *sptr == '(' )
				break;
			else	sptr++;
			}
		if ( *sptr == '(' ) {
			*(sptr++) = 0;
			while (( *sptr >= '0' ) && ( *sptr <= '9' ))
				fileline = (( fileline * 10 ) + ( *(sptr++) - '0' ));
			}		
		if ( forms_method_editor( fptr,mptr, fileline ) != 27 ) {
			get_context_defaults(fptr);
			save_Form(fptr,QUICK);
			}
		}
	else	{
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next ) {
			if (!( iptr->Contents.name ))
				continue;
			else if ( upper_compare( sptr, iptr->Contents.name ) )
				break;
			}
		if ( iptr ) {
			/* we have found the form member */
			close_window_editor();
			fileline=0; sptr=mptr;
			while ( *sptr ) {
				if ( *sptr == '(' )
					break;
				else	sptr++;
				}
			if ( *sptr == '(' ) {
				*(sptr++) = 0;
				while (( *sptr >= '0' ) && ( *sptr <= '9' ))
					fileline = (( fileline * 10 ) + ( *(sptr++) - '0' ));
				}		
			if ( upper_compare( mptr, 	__abal_method_create	))
				event = edit_widget_method( &iptr->Contents.events.on_create , fileline );
			else if ( upper_compare( mptr, 	__abal_method_show	))
				event = edit_widget_method( &iptr->Contents.events.on_show   , fileline );
			else if ( upper_compare( mptr, 	__abal_method_get_focus	))
				event = edit_widget_method( &iptr->Contents.events.on_get_focus , fileline );
			else if ( upper_compare( mptr, 	__abal_method_lose_focus))
				event = edit_widget_method( &iptr->Contents.events.on_lose_focus, fileline );
			else if ( upper_compare( mptr, 	__abal_method_event	))
				event = edit_widget_method( &iptr->Contents.events.on_event , fileline );
			else if ( upper_compare( mptr, 	__abal_method_hide	))
				event = edit_widget_method( &iptr->Contents.events.on_hide , fileline );
			else if ( upper_compare( mptr, 	__abal_method_remove	))
				event = edit_widget_method( &iptr->Contents.events.on_remove , fileline );
			else	event = 0;
			if (( event ) && ( event != _LEAVE_SING )) {
				get_context_defaults(fptr);
				save_Form(fptr,QUICK);
				}
			}
		}
	return( event );
}


private	int	zoom_trace_position( struct abal_trace * tptr )
{
	struct	form_control * fptr;
	struct	form_item * iptr;
	char		  * sptr;
	char		  * mptr;
	int			i;
	int			event=0;

	if (!( tptr->expression ))
		return( 0 );

	else if (!( fptr = Context.Form ))
		return(0);

	else if (!( sptr = allocate_string( tptr->expression )))
		return(0);

	for (	i=0; *(sptr +i) != 0; i++ )
		if ( *(sptr+i) == '.' )
			break;

	if ( *(sptr+i) == '.' ) {
		*(sptr+i) = 0;
		i++;
		}
	mptr = (sptr+i);

	/* We've got a forms method */
	/* ------------------------ */
	if ( upper_compare( sptr, "this" ) ) {

		close_window_editor();
		if ( form_parameters(fptr) != 27 ) {
			get_context_defaults(fptr);
			save_Form(fptr,QUICK);
			}
		}
	else	{
		/* Try and find a widget match */
		/* --------------------------- */
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next ) {
			if (!( iptr->Contents.name ))
				continue;
			else if ( upper_compare( sptr, iptr->Contents.name ) )
				break;
			}

		if ( iptr ) {
			/* we have found the form member */
			/* ----------------------------- */
			close_window_editor();
			if ( edit_Widget(  iptr, iptr->parent ) != 27 ) {
				get_context_defaults(fptr);
				save_Form(fptr,QUICK);
				}
			}
		}

	liberate( sptr );
	return( event );
}


private	int	edit_trace_position( struct abal_trace * tptr )
{
	if (!( tptr->filename )) {
		if (!( tptr->next ))
			return( _LEAVE_SING );
		else	return( __TRACE_NEXT );
		}
	else if (!( open_window_editor( 
			Context.DeskTop.x, Context.DeskTop.y,
			Context.DeskTop.w, Context.DeskTop.h,
			tptr->filename ) )) {
			return( _LEAVE_SING );
		}
	else	{
		status_message( tptr->filename, 1 );

		if ( tptr->expression )
			status_message( tptr->expression, 2 );
		else	status_message( " ", 2  );

		if ( tptr->message )
			status_message( tptr->message, 3  );
		else	status_message( "error", 3  );

		editorOnSeek(0,tptr->fileline);
		return( use_window_editor() );
		}
}

public	int	trace_model( char * filename )
{
	struct	abal_trace * root=(struct abal_trace *) 0;
	struct	abal_trace * tinfo=(struct abal_trace *) 0;
	int	event;
	char *	tracename;
	if (!( tracename = allocate_string( filename ) ))
		return(0);
	else if (!( tracename = enforce_extension( tracename, ERR_EXTENSION ) ))
		return(0);
	else if (!( tinfo = parse_tracefile( tracename ))) {
		liberate( tracename );
		return(0);
		}
	else	{ 
		root = tinfo;
		add_trace_menu();
		aed.zapping++;
		while ((event = edit_trace_position( tinfo )) != _LEAVE_SING) {
			if  ( event == __TRACE_WIDGET ) {
				if ((event = zoom_trace_position( tinfo )) == _LEAVE_SING)
					break;
				}
			else if  ( event == __TRACE_METHOD ) {
				if ((event = zoom_trace_method( tinfo )) == _LEAVE_SING)
					break;
				}
			switch ( event ) {
				case	_FILE_QSAVE	:
				case	_FILE_SAVE	:
				case	_FILE_LOAD	:
					continue;
				case	_VIEW_TEXT	:
				case	_VIEW_IMAGE	:
				case	_EDIT_TEXT	:
				case	_EDIT_FORM	:
					continue;

				case	__TRACE_FIRST	:
					tinfo = root;
					continue;

				case	__TRACE_PREVIOUS	:
					if ( tinfo ->previous )
						tinfo = tinfo->previous;
					continue;

				case	__TRACE_NEXT	:
					if ( tinfo ->next )
						tinfo = tinfo->next;
					continue;

				case	__TRACE_LAST	:
					while ( tinfo ->next )
						tinfo = tinfo->previous;
					continue;

				default			:
					continue;
				}
			}
		close_window_editor();
		aed.zapping--;
		drop_trace_menu();
		liberate( tracename );
		drop_traceinfo( root );
		return(1);
		}
}



#endif 	/* _singtrace_c */



