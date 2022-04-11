#ifndef	_abaledit_c
#define	_abaledit_c

#include <setjmp.h>

#include "stdbuffer.h"

extern	jmp_buf	Ed_Exit;

#define	USE_SYSTEM_V 1

static	struct	aed_control { 
	int	zapping;
	int	window;
	int	x;
	int	y;
	int	w;
	int	h;
	int	trace;
	char *	criteria;
	char *	replacement;
	char *	command;
	int	respect;
	int	direction;
	int	replaceall;
	int	fontwidth;
	int	fontheight;
	} aed = { 
		0,
		0,	0,0,0,0,	0, 
		(char *) 0,
		(char *) 0, 
		(char *) 0, 
		0,1,0,
		0,0
		};

private	int	text_editor_change();
private	int	resolve_editor_token();
private	void	reset_window_editor()
{
	aed.window=0;
	aed.x = aed.y = aed.w = aed.h = 0;
	return;
}

public	void	method_editor_window(int x,int y, int w, int h )
{
	aed.x = x;
	aed.y = y;
	aed.w = w;
	aed.h = h;
	return;
}

public	void	delete_system_file( char * nptr, int nlen )
{
	int	i;
	int	c;
	int	l=0;
	if ((!( nptr )) || (!( nlen ))) return;
	for (i=0; i < nlen; i++ )
		if ( *(nptr+i) != ' ')
			l = (i+1);
	c = (*nptr+l); 	*(nptr+l) = 0;

	unlink( nptr );

	*(nptr+l) = c;
	return;
}

public	void	get_widget_filename( char * rptr, int rlen, int v, char * pptr, int plen )
{
	char * sptr = WidgetFileNames;
	int	i;
	for ( i=0; i < v; i++ ) {
		while ( *sptr )
			if ( *(sptr++) == '|' ) 
				break;
		if (!( *sptr ))
			break;
		}
	if ( pptr != (char *) 0 ) {
		for ( i=0; i < rlen; i++ ) {
			if ( i < plen ) {
				switch ( *(rptr+i) = *(pptr+i) ) {
					/* FCH_SING Attention, ceci interdit l'utilisation de blanc dans les noms */
					case	' '	:
						*(rptr+i) = 0;
					case	0	:
						break;
					default		:
						continue;
					}
				}
			else	*(rptr+i)=0;
			break;
			}
		rptr += i;
		rlen -= i;
		}
	if (!( *sptr )) 
		strcpy( rptr,"*.*" );
	else	{ 
		for ( i=0; i < rlen; i++ ) {
			switch ( *(rptr+i) = *(sptr+i) ) {
				case	'|'	:
					*(rptr+i) = 0;
				case	0	:
					break;
				default		:
					continue;
				}
			break;
			}
		}
	return;
}

public	void	use_file_selector( char * fnptr, int pft)
{
	char *	rptr=(char*) 0;
	char *	sptr=(char*) 0;
	int	ft=pft;
	int	infos=0;
	if ( ft > WIDGET_FILE_LIMIT )
		ft = WIDGET_FILE_ANY;
	else if ( ft < 0 )
		ft = WIDGET_FILE_ANY;

	if (!( fnptr ))
		return;
	else if (!( sptr = allocate_string( fnptr )))
		return;

#ifdef WIN32
	else if ( ChoixFic(&rptr,ft,sptr) == 27) {
#else
	else if (!( rptr = allocate_string( fnptr ))) {
		sptr = liberate( sptr );
		return;
		}
	else if ( file_selector(&rptr,&infos,&Context.file_path[ft],&sptr) == 27) {
#endif
		sptr = liberate( sptr );
		rptr = liberate( rptr );
		return;
		}
	else	{
		if ( rptr != (char *) 0 ) {
			strcpy(fnptr, rptr );
			rptr = liberate( rptr );
			}
		if ( sptr != (char *) 0 )
			sptr = liberate( sptr );
		return;
		}
}

int	editorOnStatus( int option, int value )
{
	if (!( option ))
		editor_wipe_icons();
	else 	{
		if ( option & 1 ) editor_insert_icon((value & 1 ? 1 : 0));
		if ( option & 2 ) editor_line_counter( value  );
		if ( option & 4 ) editor_basket_icon((value & 4 ? 1 : 0));
		}
	return(0);
}

public	int	editorOnError( int g, char * mptr, char * eptr )
{
	return( editor_failure( mptr, eptr ) );
}

public	int	editorOnCommand( char * cptr, int clen )
{
	char	*	sptr;
	int	i;
	if ( accept_editor_command(&aed.command) == 27 )
		return(27);
	else if (!( cptr ))
		return(27);
	else if (!(sptr = aed.command ))
		return(27);
	else	{
		for (i=0; i < (clen-1); i++ ) {
			if (!( *(sptr+i) ))
				break;
			else	*(cptr+i) = *(sptr+i);
			}
		*(cptr+i) = 0;
		return(13);
		}
}

public	int	editor_await_event()
{
	int	status;
	int	event;
	while (1) {
		editorOnGetFocus();
		event = visual_getch();
		editorOnLoseFocus();
		if (event != 256)
			return(event);
		else if ((status= handle_event()) == 256)
			continue;
		else if ( status == -1 )
			return( event );
		else	return( status );
		}
}

public	void	html_operation( char * tptr )
{
	char	tagbuffer[32];
	sprintf(tagbuffer,"<%s>",tptr);
	editorOnUseString(tagbuffer);
	return;
}

public	void	css_operation( char * tptr )
{
	char	tagbuffer[32];
	sprintf(tagbuffer,"%s",tptr);
	editorOnUseString(tagbuffer);
	return;
}

private	void	configure_editor_window()
{
	if (!( SingConf ))
		return;
	if ((!( aed.w ))
	||  (!( aed.h ))) {
		use_base_font(SingConf->aed.font);
		aed.fontwidth  = guifontsize(SingConf->aed.font);
		aed.fontheight = (aed.fontwidth >> 8);
		aed.fontwidth  &= 0x00FF;
		cicowindow(	Context.DeskTop.x,Context.DeskTop.y,
				Context.DeskTop.w-(aed.fontwidth*2),Context.DeskTop.h);
		sprintf(workbuffer,"%u:%u:%u:%u:0:%u:0:%u:%u", 
				Context.DeskTop.x,Context.DeskTop.y,
				Context.DeskTop.w,Context.DeskTop.h,
				SingConf->aed.font,(aed.fontwidth*2),1);

		}
	else	{
		use_base_font(SingConf->aed.font);
		aed.fontwidth  = guifontsize(SingConf->aed.font);
		aed.fontheight = (aed.fontwidth >> 8);
		aed.fontwidth  &= 0x00FF;
		cicowindow(aed.x,aed.y,aed.w-(aed.fontwidth*2),aed.h);
		sprintf(workbuffer,"%u:%u:%u:%u:1:%u:0:%u:%u",aed.x,aed.y,aed.w,aed.h,SingConf->aed.font,(aed.fontwidth*2),1);
		}

	editor_window_connection( workbuffer );	
	
	return;
}

public	void	reconfigure_editor_window( int atx, int aty, int nbx, int nby )
{
	char *	argv[16];
	int	argc=0;

	aed.x = atx; aed.y = aty;
	aed.w = nbx; aed.h = nby;

	configure_editor_window();
	editorInitEcran();
	return;

}


private	void	AbalEditorOnUpdate(char * nfic)
{
	char	*	nptr=(char *) 0;
	unsigned long	nbl=0L;
	unsigned long	topline=0L;
	unsigned long	endline=0L;
	editorGetPosition(&nptr,&nbl,&topline,&endline);
	editorOnUpdate(( nfic ? nfic : "\0"));
	editorOnSeek(0,nbl);
	return;
}


public	int	internal( char * cptr, int ismodal, int language )
{
	char *	thisnomfic=(char *) 0;
	int	event=0;
	int	status;
	char *	argv[16];
	int	argc=0;
	do	{
		/* store this parameter */
		argv[argc++]=cptr;
		while ( *cptr ) {
			if ( *cptr != ' ' ) {
				cptr++;
				continue;
				}
			else	break;
			}
		while ( *cptr ) {
			if ( *cptr == ' ' ) {
				cptr++;
				continue;
				}
			else	break;
			}
		
		}
	while ( *cptr );

	desktop_Hscroll(0,0);
	desktop_Vscroll(0,0);

	configure_editor_window();

	if ( setjmp( Ed_Exit ) != 0 ) {
		editorOnRemove(0);
		}
	else if ( editorOnCreate(argc,argv) ) {
		add_editor_menu();
		if ( language != -1 ) {
			editorConfiguration(language);
			if ( language == _GENERATE_HTML )
				use_html_tools();
			else if ( language == _GENERATE_CSS )
				use_css_tools();
			}

		editorOnShow();
		without_mouse_move();
		Context.EditView=1;
		editorOnStatus(7,1);
		while (1) {
			if ((event = editor_await_event()) == _LEAVE_SING) {
				event = 0;
				break;
				}
			else if ( event == _EDIT_RESOLVE ) {
				if ((event = resolve_editor_token()) != 0 )
					break;
				}
			else if ( event == _FILE_PRODUCE ) {
				AbalEditorOnUpdate((char *) 0);
				break;
				}
			else if ( event == _FILE_DROP ) {
				AbalEditorOnUpdate((char *) 0);
				event=0;
				break;
				}
			else if ( event == _FILE_SAVE ) {
				if ( accept_textsave(&thisnomfic) != 27 ) {
					if ( thisnomfic ) {
						AbalEditorOnUpdate(thisnomfic);
						liberate( thisnomfic );
						thisnomfic = (char *) 0;
						}
					}
				}
			else if ( event == _FILE_LOAD )
				text_editor_change();
			else if ( event == _FILE_QSAVE )
				AbalEditorOnUpdate((char *) 0);
			else if (( event == _EDIT_FORM )
			 ||      ( event == _EDIT_GRAPH)
			 ||      ( event == _EDIT_FONT )
#ifdef	ABAL32A
			 ||      ( event == _EDIT_STYLE)
			 ||      ( event == _EDIT_DEPEND)
#endif
			 || 	 ( event == _EDIT_IMAGE))
				break;
			else if (( event == _VIEW_TEXT )
			     &&  ( treeview_is_active()))
				break;
			else if (( event == _VIEW_IMAGE )
			     &&  ( treeview_is_active()))
				break;
			else if ( event & 0xFF00 )
				continue;
			else if ( event == 27 )
				editorCommandWindow();
			else if ( editorOnUseEvent(event) )
				break;
			}
		if ( ismodal )
			editorOnUpdate("\0");
		editorOnStatus(0,0);
		Context.EditView=0;
		without_mouse_move();
		editorOnHide();
		editorOnQuit();
		editorOnRemove(0);
		if ( language == _GENERATE_HTML )
			drop_tool_manager();
		else if ( language == _GENERATE_CSS )
			drop_tool_manager();
		drop_editor_menu();
		inhibit_text_cursor();
		}
	use_base_font(1);
	switch ( event ) {
		case	_VIEW_TEXT	:
		case	_VIEW_IMAGE	:
		case	_EDIT_FORM 	:
		case	_EDIT_GRAPH	:
		case	_EDIT_FONT 	:
#ifdef	ABAL32A
		case	_EDIT_STYLE 	:
		case	_EDIT_DEPEND 	:
#endif
		case	_EDIT_TEXT	:	
		case	_EDIT_IMAGE	:
			break;
		default		:
			draw_console();
		}
	return(event);
}

public	void	reconfigure_editor()
{
	editorOnLoseFocus();
	editorOnHide();
	reconfigure_editor_window(0,0,0,0);
	editorOnShow();
	editorOnGetFocus();
	return;
}


public void show_window_editor()
{
	if ( aed.window )
		editorOnShow();
	return;
}

public	int	use_window_editor()
{
	int	mx,my;
	int	event;
	int	status;
	without_mouse_move();
	Context.EditView=2;
	editorOnStatus(7,1);
	while (1) {
		if ((event = editor_await_event()) == 256 ) {
			mx = visual_event(7);
			my = visual_event(6);
			if (( mx < aed.x )
			||  ( my < aed.y )
			||  ( mx > (aed.x + aed.w))
			||  ( my > (aed.y + aed.h))) {
				/* editorOnUpdate("\0"); */
				break;
				}
			else if ( editorOnUseEvent(event) )
				break;
			}

		else if ( event == _EDIT_RESOLVE ) {
			if ((event = resolve_editor_token()) != 0 ) {
				event=27;
				break;
				}
			else	continue;
			}
		else if ( event == 27 ) 
			editorCommandWindow();
		else if ( event & 0xFF00 )
			break; 
		else if ( aed.zapping ) {
			switch ( event ) {
				case	CTRL_V		 :
				case	CTRL_Z		 :
				case	CTRL_T		 :
				case	__TRACE_FIRST 	 :
				case	__TRACE_WIDGET	 :
				case	__TRACE_PREVIOUS :
				case	__TRACE_METHOD   :
				case	__TRACE_NEXT 	 :
				case	__TRACE_LAST 	 :
					break;
				default			 :
					if ( editorOnUseEvent(event) )
						break;
					else	continue;
				}
			break;
			}
		else if ( editorOnUseEvent(event) )
			break;

		}
	editorOnStatus(0,0);
	Context.EditView=0;
	without_mouse_move();
	return(event);
}

public int focus_window_editor()
{
	int	status=-1;
	if ( aed.window ) {
		if (!( setjmp( Ed_Exit ))) {
			activate_text_cursor();
			status = use_window_editor();		
			inhibit_text_cursor();
			}
		}
	return(status);
}

public	void	close_window_editor()
{
	if ( aed.window ) {
		if ( setjmp( Ed_Exit ) != 0 ) {
			editorOnRemove(0);
			drop_editor_menu();
			use_base_font(1);
			}
		else	{
			editorOnUpdate("\0");
			reset_window_editor();
			editorOnHide();
			editorOnQuit();
			editorOnRemove(0);
			drop_editor_menu();
			use_base_font(1);
			inhibit_text_cursor();
			}
		aed.window = 0;
		}
	return;
}
	
public	void	drop_window_editor()
{
	if ( aed.window ) {
		if ( setjmp( Ed_Exit ) != 0 ) {
			editorOnRemove(0);
			drop_editor_menu();
			use_base_font(1);
			}
		else	{
			reset_window_editor();
			editorOnHide();
			editorOnQuit();
			editorOnRemove(0);
			drop_editor_menu();
			use_base_font(1);
			inhibit_text_cursor();
			}
		aed.window = 0;
		}
	return;
}
	
public	int	open_window_editor( int atx, int aty, int nbx, int nby, char * nomfic )
{
	char *	argv[16];
	int	argc=0;
	if (!( SingConf ))
		return(0);
	if ( aed.window )
		close_window_editor();
	argv[argc++]="!ned";
	argv[argc++]=nomfic;
	argv[argc] = (char *) 0;
	aed.x = atx; aed.y = aty;
	aed.w = nbx; aed.h = nby;
	use_base_font(SingConf->aed.font);
	aed.fontwidth = guifontsize(SingConf->aed.font);
	aed.fontheight = (aed.fontwidth >> 8);
	aed.fontwidth  &= 0x00FF;

	if ( setjmp( Ed_Exit ) != 0 ) {
		editorOnRemove(0);
		use_base_font(1);
		return((aed.window=0));
		}
	else	{
		cicowindow(aed.x+1,aed.y+1,aed.w-((aed.fontwidth*2)+2),aed.h-2);
		sprintf(workbuffer,"%u:%u:%u:%u:1:%u:0:%u:%u",atx+1,aty+1,nbx-2,nby-2,SingConf->aed.font,(aed.fontwidth*2),1);
		editor_window_connection( workbuffer );
		if ( editorOnCreate(argc,argv) ) { 
			add_editor_menu();
			return((aed.window=1));
			}
		else	return(0);
		}
}

public	int	accept_editor_options(char * filename)
{
	int	status;
	if (!( SingConf ))
		return(27);
	SingConf->aed.font--;
	status = accept_editor( 
		filename, 
		&SingConf->aed.program, 
		&SingConf->aed.normal,
		&SingConf->aed.string,
		&SingConf->aed.keyword,
		&SingConf->aed.comment,
		&SingConf->aed.state, 
		&SingConf->aed.font );
	SingConf->aed.font++;
	check_configuration();
	return(status);
}

public	int	use_editor( char * fnptr, int language)
{
	int	event=0;
	int	holder;
	int	status;
	char *	sptr;
	char *	command;
	char *	filename;
	int	i;
	if (!( SingConf ))
		return(0);
	if ( Context.EditView == 1 )
		return( event );
	if ( *fnptr == '"' )
		fnptr++;

	for ( i=0; *(fnptr+i) != ' '; i++ ) {
		if ( *(fnptr+i) == '"' )
			break;
		else if (!( *(fnptr+i)  ))
			break;
		}


	if (!( filename = allocate( (i+16) )))
		return(event);

	for ( i=0; *(fnptr+i) != ' '; i++ ) {
		if (!( *(filename + i ) = *(fnptr+i) ))
			break;
		else if ( *(filename +i) == '"' )
			break;
		}
	*(filename+i) = 0;
	
	if (!( SingConf->aed.state )) {
		status = accept_editor_options(filename);
		if ( status == 27 ) {
			filename = liberate( filename );
			return(event);
			}
		}

	if (!( command = allocate( strlen( SingConf->aed.program ) + strlen( filename ) + 128 ) )) {
		filename = liberate( filename );
		return(event);
		}
	else	{
		if (!( aed.trace ))
			sprintf(command,"%s %s",SingConf->aed.program, filename );
		else	{
			sprintf(command,"%s -t%s",SingConf->aed.program,filename);
			for ( 	i=0,sptr=command;
				*sptr != 0;
				sptr++ ) {
				if (!( i )) {
					if (( *sptr     == '-' )
					&&  ( *(sptr+1) == 't' ))
						i = 1;
					continue;
					}
				else if ( *sptr == '.' ) {
					*sptr = 0;
					break;
					}
				}
			}					
		status_message(command,3);
		if ( *command == '!' ) {
			holder = Context.ismodal;
			Context.ismodal = 0;
			event = internal( (command+1),holder, language );
			Context.ismodal = holder;
			}
		else	{
			activate_background_job( command );
			}
		command  = liberate( command );
		filename = liberate( filename );
		return(event);
		}
}

public	void	trace_editor( char * filename )
{
	if ( consoletype() ) {
		if (!( aed.trace )) {
			aed.trace = 1;
			(void) use_editor( filename, _GENERATE_BAL );
			aed.trace = 0;
			}
		}
	return;
}

public	void	protect_trace_editor(char * nomfic )
{
	struct	standard_buffer	holder;
	int	pushed=0;

	/* Detect if working in visual buffer */
	/* ---------------------------------- */
	if ((pushed = pushware( &holder )) != 0 ) {
		hardware();
		}
	trace_editor( nomfic );
	/* Restore if working in visual buffer */
	/* ----------------------------------- */
	if ( pushed != 0 ) {
		userware( holder.columns, holder.rows, holder.storage );
		}
	return;
}

public	int	perform_editor( char * filename, int language )
{
	int	event=0;

	while (( *filename == ' ' )
	&&     ( *filename != 0 )) 	filename++;

	if (!( *filename ))
		return(event);

	else if (!( filename = compare( filename, "#include" ))) 
		return(event);

	else	{

		while (( *filename == ' ' )
		&&     ( *filename != 0 )) 	filename++;

		if ( *filename != 0 )
			event = use_editor( filename, language );

		return(event);
		}

}

public	void	method_editor( char * filename, int language )
{

	while (( *filename == ' ' )
	&&     ( *filename != 0 )) 	filename++;

	if (!( *filename ))
		return;

	else if (!( filename = compare( filename, "#include" ))) 
		return;

	else	{

		while (( *filename == ' ' )
		&&     ( *filename != 0 )) 	filename++;

		if ( *filename != 0 )
			(void)use_editor( filename, language );

		return;
		}

}

public	void	use_abal_editor()
{
	accept_editor_options(" ");
	return;
}

public	void	EditorTextFinder( char * cptr, int clen, int respect, int direct )
{
	int	i,l;
	for ( i=0,l=0; i < clen; i++ )
		if ( *(cptr+i) != ' ' )
			l = (i+1);
	i = *(cptr+l);
	*(cptr+l) = 0;
	editorOnSearch( cptr, respect, direct );
	*(cptr+l) = i;
	return;
}

public	void	EditorTextReplace(
			char * sptr, int slen, 
			char * rptr, int rlen, 
			int respect, int direct, int  replaceall )
{
	int	i,sc,sl,rl,rc;
	for ( i=0,sl=0; i < slen; i++ )
		if ( *(sptr+i) != ' ' )
			sl = (i+1);
	sc = *(sptr+sl); *(sptr+sl) = 0;
	for ( i=0,rl=0; i < rlen; i++ )
		if ( *(rptr+i) != ' ' )
			rl = (i+1);
	rc = *(rptr+rl); *(rptr+rl) = 0;	
	editorOnReplace( sptr, rptr, respect, direct, replaceall );
	*(sptr+sl) = sc; *(rptr+rl) = sc;
	return;
}

public	int	text_editor_search()
{
	editorOnLoseFocus();
	HyperText();
	draw_console();
	editorOnGetFocus();
	return(-1);
}

public	int	text_editor_change()
{
	char *	wptr;
	char *	argv[3];
	int	argc=2;
	argv[0] = "aed";
	editorOnLoseFocus();
	editorGetToken((wptr = workbuffer), 1 );
	if ( *wptr != 0 ) {
		if ( *wptr == '"' )
			wptr++;
		argv[1] = wptr;
		argv[2] = (char *) 0;
		editorOnHide();
		editorOnRemove(1);
		editorOnCreate(argc,argv);
		editorOnShow();
		}
	editorOnGetFocus();
	return(-1);
}


private	int	resolve_editor_token()
{
	char *	wptr;
	editorGetToken((wptr = workbuffer), 1 );
	if (!( *wptr )) 
		return(0);
	else 	return( select_form_member( wptr )  );
}

public	int	text_editor_find()
{
	int	status;
	editorOnLoseFocus();
	status = accept_search(&aed.criteria,&aed.respect,&aed.direction);
	editorOnGetFocus();
	return(-1);
}

public	int	text_editor_replace()
{
	int	status;
	editorOnLoseFocus();
	status = accept_replace(&aed.criteria,&aed.replacement,&aed.respect,&aed.direction,&aed.replaceall);
	editorOnGetFocus();
	return(-1);
}

#include "abaldbug.c"
#include "aballink.c"
#include "abaltrad.c"

public	void	initialise_abal_production()
{
	reset_window_editor();
	aed.respect =
	aed.direction = 
	aed.replaceall = 
	aed.trace = 0;
	aed.criteria = (char *) 0;
	aed.command  = (char *) 0;
	aed.replacement = (char *) 0;
	initialise_abal_translators();
	initialise_abal_linker();
	return;
}

public	void	release_abal_production()
{
	if ( aed.criteria ) aed.criteria = liberate( aed.criteria );
	if ( aed.command ) aed.command = liberate( aed.command );
	if ( aed.replacement ) aed.replacement = liberate( aed.replacement );
	liberate_abal_translators();
	liberate_abal_linker();
	return;
}

public	int	use_visual_text_editor( char ** nptr, int language )
{
	char	*	tempfilename=(char *) 0;
	int		status;
	visual_signature("T","T");
	visual_transferin(&tempfilename,1000,nptr);
	use_editor( tempfilename, language );
	visual_signature("T","T");
	visual_transferout(&tempfilename,1000,nptr);
	return( 13 );
}

public	void	standard_text_editor(char * nptr, int nlen )
{
	char	*	nomfic;
	int		i;
	int		l;
	if (!( nlen ))
		return;
	else if (!( nomfic = allocate( (nlen+1) )))
		return;
	else	{
		memcpy(nomfic,nptr,nlen);
		for ( l=0,i=0; i < nlen; i++ ) 
			if ( *(nomfic+i) != ' ' )
				l = (i+1);
		*(nomfic+l) = 0;
		use_editor( nomfic, _GENERATE_BAL );
		liberate( nomfic );
		return;
		}
}

public	void	edit_style_file( char * nptr, int nlen )
{
	int i;
	char* tptr = allocate( nlen+1 );
	memcpy( tptr, nptr, nlen);

	for (i=nlen ; i>0 ; i-- )
		{
		if (tptr[i-1] != ' ')
			{
			tptr[i] = 0; 
			break;
			}
		}
	tptr[nlen] = 0;

	tptr = resolve_stylepath( tptr, get_system_stylepath() );
	
	standard_text_editor( tptr, strlen(tptr) ) ;
	liberate( tptr );

	return;
}


#endif	/* _abaledit_c */



