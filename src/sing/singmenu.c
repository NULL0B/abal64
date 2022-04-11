#ifndef	_singmenu_c
#define	_singmenu_c

#include "singfont.h"
#include "singclas.h"
#include "vconf.h"
#include "singpage.h"
#include "singconf.h"
#include "singprod.h"
#include "singalig.h"

struct	menu_item;

private	int	menu_counter=0;
private	int	menu_character=65;
private	char * 	UsingNewMenu="ok";
extern	char * OtrIcon;
extern	char * OldIcon;
extern	char * AedIcon;
extern	char * ExaIcon;
extern	char * ExadbIcon;

struct	menu_manager	{
	struct menu_item * first;
	struct menu_item * last;
	struct menu_item * current;
	struct menu_manager * parent;
	struct standard_image * shadow;
	long	loadstamp;
	long	savestamp;
	int			visible;
	int 	(*service)();
	int	identity;
	int	storage;
	int	type;
	int	x;
	int	y;
	int	w;
	int	h;
	int	length;
	int	members;
	};

struct	menu_item	{
	char *	message;
	int	length;
	char *	hint;
	struct menu_item * next;
	struct menu_item * previous;
	struct menu_manager * parent;
	int	x;
	int	y;
	int	h;
	int	w;
	int	hotkey;
	int	active;
	int	nature;
	int *	shadow;
	struct	menu_manager * linkage;
	int	result;
	};

private	struct	menu_manager * drop_menu( struct menu_manager * mptr );
public	int	syntax_composer();

private	struct menu_manager * MenuBar=(struct menu_manager *) 0;
private	struct menu_manager * EditMenu=(struct menu_manager *) 0;
private	struct menu_manager * FileMenu=(struct menu_manager *) 0;
private	struct menu_manager * OptionMenu=(struct menu_manager *) 0;
private	struct menu_manager * EventMenu=(struct menu_manager *) 0;
private	struct menu_manager * TraceMenu=(struct menu_manager *) 0;
private	struct menu_manager * FormMenu=(struct menu_manager *) 0;
private	struct menu_manager * WidgetMenu=(struct menu_manager *) 0;
private	struct menu_manager * FontMenu=(struct menu_manager *) 0;
private	struct menu_manager * ZoomMenu=(struct menu_manager *) 0;
private	struct menu_manager * ThreedMenu=(struct menu_manager *) 0;
private	struct menu_manager * EditorMenu=(struct menu_manager *) 0;
private	struct menu_manager * MenuMenu=(struct menu_manager *) 0;
private	struct menu_manager * ClassMenu=(struct menu_manager *) 0;

private	struct visual_language_message ProjectMessage 	= { "&Project", "&Projet", "&Project", "&Project", "&Project", "&Project", "&Project", "&Project" };
private	struct visual_language_message FormsMessage 	= { "For&m",      "For&mulaire", "For&m", "For&m", "For&m", "For&m", "For&m", "For&m" };
private	struct visual_language_message FontMessage 	= { "Fo&,nt",      "For&mulaire", "For&m", "For&m", "For&m", "For&m", "For&m", "For&m" };
private	struct visual_language_message WidgetMsg 	= { "&Widget",   "&Widget", "&Widget", "&Widget", "&Widget", "&Widget", "&Widget", "&Widget" };
private	struct visual_language_message ImageMessage 	= { "&Image",     "&Image", "&Image", "&Image", "&Image", "&Image", "&Image", "&Image" };
private	struct visual_language_message TraceMessage 	= { "&Trace",     "&Trace", "&Trace", "&Trace", "&Trace", "&Trace", "&Trace", "&Trace" };
private	struct visual_language_message EditorMessage 	= { "&Editor",   "&Editeur", "&Editor", "&Editor", "&Editor", "&Editor", "&Editor", "&Editor" };
private	struct visual_language_message EmptyMessage 	= { " ",   " ", " ", " ", " ", " ", " ", " " };

private	int	PageResolution[]= { 0,75,100,150,300,600,1200,2400,4800 };

public	struct visual_language_message * visual_empty_message()
{
	return( &EmptyMessage );
}

public	struct menu_manager * allocatemenu(int t, int x, int y,int w, int h, void * sptr)
{
	struct	menu_manager * mptr;
	if (!(mptr = allocate( sizeof( struct menu_manager ) ) ))
		return(mptr);
	mptr->first = mptr->last = mptr->current = (struct menu_item *) 0;
	mptr->type = t; mptr->x= x; mptr->y= y; mptr->members=0;
	mptr->storage = mptr->w = w; mptr->h = h; mptr->length = 0;
	mptr->parent = (struct menu_manager *) 0;
	mptr->service = sptr;
	mptr->identity = ++menu_counter;
	mptr->shadow   = (struct standard_image *) 0;
	mptr->visible  = 0;
	return(mptr);
}

public	void	mouse_move_on()
{
	set_mimo_mask((
		_MIMO_ALT	 |
		_MIMO_WHILE_DOWN |
		_MIMO_MOVE 	 |
		_MIMO_DOWN 	 |
		_MIMO_UP 	 |
		_MIMO_SEND_WHEEL |
		_MIMO_SEND_RIGHT |
		_MIMO_SEND_LEFT   	   ));
	return;
}

public	void	mouse_move_off()
{
	set_mimo_mask((
		_MIMO_ALT	 |
		_MIMO_WHILE_DOWN |
		_MIMO_DOWN 	 |
		_MIMO_UP 	 |
		_MIMO_SEND_WHEEL |
		_MIMO_SEND_RIGHT |
		_MIMO_SEND_LEFT   	   ));
	return;
}

public	void	compare_Files(char * lptr, char * rptr )
{
	char *	lfile;
	char * 	rfile;
	if (!( lptr ))
		lfile = (char * ) 0;
	else 	lfile = allocate_string(lptr);
	if (!( rptr ))
		rfile = (char * ) 0;
	else 	rfile = allocate_string(rptr);
	visual_file_compare( &lfile, &rfile );
	if ( lfile )
		liberate( lfile );
	if ( rfile )
		liberate( rfile );

	return;
}

public	struct	menu_item * drop_menu_item( struct menu_item * optr )
{
	if (!( optr )) 
		return(optr);
	if ( optr->message ) {
		optr->message = liberate( optr->message );
		}
	if ( optr->hint )
		optr->hint = liberate( optr->hint );

	optr = liberate( optr );		
	return((struct menu_item *) 0);
}

public	struct	menu_manager * drop_linkage( 
		struct menu_manager * pptr,
		struct menu_manager * mptr )
{
	struct 	menu_manager * lptr;
	struct	menu_item * optr;
	for (	optr=pptr->first;
		optr != (struct menu_item *) 0;
		optr = optr->next ) {

		if ( optr->result )
			continue;
		else if (!(lptr = optr->linkage))
			continue;
		else if ( lptr->identity != mptr->identity ) 
			continue;
		else	{
			/* remove this item */
			if (!( optr->previous ))
				pptr->first = optr->next;
			else	optr->previous->next = optr->next;
			if (!( optr->next ))
				pptr->last = optr->previous;
			else	optr->next->previous = optr->previous;
			pptr->current = pptr->first;
			optr = drop_menu_item( optr );
			break;
			}
		}
	return((struct menu_manager *) 0);
}

public	struct	menu_manager * drop_menu( struct menu_manager * mptr )
{
	struct	menu_item * optr;
	if (!( mptr ))
		return( mptr );

	if ( mptr->parent )
		mptr->parent = drop_linkage( mptr->parent, mptr );

	while ((optr=mptr->first) != (struct menu_item *) 0) {
		mptr->first = optr->next;
		optr = drop_menu_item(optr);
		}
	if ( mptr->shadow )
		mptr->shadow = local_drop_image(mptr->shadow );

	mptr = liberate( mptr );		
	return((struct menu_manager *) 0);
}

public	int	add_menu_item(struct menu_manager * mptr,char * tptr, char * hptr, int h,int r, void * vptr )
{
	struct	menu_item * optr;
	if (!(optr = allocate(sizeof( struct menu_item ) ) ))
		return(0);

	optr->previous= optr->next = (struct menu_item *) 0;
	optr->message = optr->hint = (char *) 0;
	optr->linkage = (struct menu_manager *) 0;
	optr->shadow  = (int * ) 0;
	optr->parent  = mptr;
	optr->x=optr->y=optr->w=optr->h;
	optr->hotkey  = (h | _MIMO_ALT); 
	optr->nature = optr->active  = 0; 
	if (!( optr->result  = r )) {
		if ((optr->linkage = vptr) != (struct menu_manager *) 0)
			optr->linkage->parent = mptr;

		}
	else	optr->shadow  = vptr;

	if (!(optr->message = allocate((optr->length = strlen(tptr))+1 ))) {
		optr = drop_menu_item(optr);
		return(0);
		}
	strcpy(optr->message,tptr);

	if ((optr->hotkey = detect_hotkey_trigger( optr->message )) !=0)
		optr->hotkey |= _MIMO_ALT;

	if (!(optr->hint = allocate( strlen(hptr)+1 ))) {
		optr = drop_menu_item(optr);
		return(0);
		}
	else	{
		strcpy(optr->hint,hptr);
		if (!(optr->previous = mptr->last )) {
			mptr->current = mptr->first = optr;
			}
		else 	mptr->last->next = optr;
		mptr->last = optr;
		mptr->members++;
		if ( mptr->length < optr->length ) {
			mptr->length = optr->length;
			}
		if ( mptr->type == 1 ) {
			mptr->w = ((mptr->length+4)*Context.fontwidth);
			mptr->h = ((mptr->members+1)*Context.fontheight);
			}

		return(1);
		}		
}

public	int	font_selector(int v)
{
	if ( Context.FontContext ) {
		Context.FontContext->x_cursor = Context.FontContext->y_cursor = 0;	
		save_Character(Context.FontContext,Context.fontitem);
		}

	if ( Context.FontContext ) {
		draw_DeskTop();
		(void) font_window( Context.FontContext );
		}

	return(0);
}

public	int	add_check_item(struct menu_manager * mptr,char * tptr, char * hptr, int h,int r, void * vptr )
{
	if (!( add_menu_item(mptr,tptr,hptr, h, r,vptr ) ))
		return(0);
	else	return((mptr->last->nature = 1 ));
}

public	int	syntax_composer()
{
	if (!( Context.Form ))
		return(0);
	else	return(FormSyntaxComposer(Context.Form));
}

public 	int	page_resolution()
{
	if (!( Context.Form ))
		return(0);
	else	return( PageResolution[ (Context.Form->printout.PrintResolution-1) ] );
}

#include "singprag.c"

public	int	page_parameters()
{
	int	status;
	if ( Context.Form->printout.PrintResolution ) 
		Context.Form->printout.PrintResolution--;
	if ( Context.Form->printout.PaperType ) 
		Context.Form->printout.PaperType--;
	if ( Context.Form->printout.Layout )
		Context.Form->printout.Layout--;
	if ( Context.Form->printout.FeedOpt ) 
		Context.Form->printout.FeedOpt--;

	status = accept_visual_page( 	
			&Context.Form->printout.DeviceName,	
			&Context.Form->printout.DriverName,	
			&Context.Form->printout.PageHead,
			&Context.Form->printout.PaperType,
			&Context.Form->printout.PrintResolution,
			&Context.Form->printout.Layout,
			&Context.Form->printout.FeedOpt,
			&Context.Form->printout.Alignment,
			&Context.Form->printout.Preview,	
			&Context.Form->printout.LeftMargin,	
			&Context.Form->printout.RightMargin,
			&Context.Form->printout.TopMargin,
			&Context.Form->printout.BottomMargin );

	Context.Form->printout.PrintResolution++;
	Context.Form->printout.PaperType++;
	Context.Form->printout.Layout++;
	Context.Form->printout.FeedOpt++;
	if ( status != 27 ) {
		draw_Form( Context.Form, 1 );
		form_is_outofdate(Context.Form);
		save_for_rollback(Context.Form,0,"page_parameters");
		draw_Form( Context.Form, 1 );
		}
	return(256);
}

int	toggle_treeview()
{
	if ( Context.EditView != 2 )
		swap_TreeView();
	return(256);
}

int	toggle_palette()
{
	swap_Palette();
	return(256);
}

public	void	configure_gridlock(int v)
{
	if ( v & 1 ) {
		Context.gridlockw = Context.gridwidth;
		Context.gridlockh = Context.gridheight;
		}
	else	{
		Context.gridlockw = 0;
		Context.gridlockh = 0;
		}
	return;
}

public	int	treeview_parameters()
{
	if ( configure_treeview() == 27 )
		return( 27 );
	else	return(256);

}

public	int	general_parameters()
{
	int	isgrid;
	int	fontid;
	int	langid=_GENERATE_ABAL;
	int	isb;
	int	isu;
	int	isa;
	int	issh;
	int	userstate=SingConf->expert_user;

	if ( Context.alignment & _A_BOLD )
		isb = 1;
	else	isb = 0;

	if ( Context.alignment & _A_LINE )
		isu = 1;
	else	isu = 0;

	if ( Context.alignment & _A_SHADOW )
		issh = 1;
	else	issh = 0;

	isa = (Context.alignment & 0x00FF);


	if ((fontid = Context.Item.font) > 0)
		fontid--;
	if ( Context.gridlockw )
		isgrid = 1;
	else	isgrid = 0;

	/* new default language id */
	langid = Context.language;

	if (!( SingConf->expert_user )) {
		if ( langid < _GENERATE_BAL )
			SingConf->expert_user++;
		else	langid -= _GENERATE_BAL;
		}

	if ( accept_general_options(
		& langid,
		& Context.imageformat,
		& fontid,
		& isa, &isb, &isu, &issh,
		& Context.gridtype,
		& Context.lockon,
		& Context.UseTestData,
		& Context.AutoSave,
		& Context.dropon,

		& Context.gridwidth,
		& Context.gridheight,
		& Context.thickness,
		& Context.ResizeBy
		 ) != 27 ) {

		if (!(SingConf->expert_user ))
			langid += _GENERATE_BAL;

		/* new default language id */
		Context.language = langid;

		configure_gridlock(Context.gridtype);
		Context.Item.font = (fontid+1);
		
		if (( Context.FontContext )) {
			Context.FontContext->font = (fontid+1);
			font_window(Context.FontContext);
			}
		Context.alignment = isa;

		if ( isb  ) Context.alignment |= _A_BOLD;
		if ( isu  ) Context.alignment |= _A_LINE;
		if ( issh ) Context.alignment |= _A_SHADOW;

		}
	SingConf->expert_user = userstate;
	draw_console();
	return(256);

}

#ifdef	PROTOTYPE
public	int	about_sing()
{
	inform_about();
	return(256);
}
#endif

public	int	menu_refresh()
{
	draw_console();
	return(256);
}

public struct	sing_animator	{
	char	*	script;
	int		replay;
	} Animator = { (char *) 0, 0 };

public	int	perform_animation()
{
	(void) 	cancel_replay_record();
	if ( accept_animation_parameters( & Animator.script, &Animator.replay ) != 27 ) {
		if ( Animator.replay ) {
			if (activate_replay( Animator.script ) !=0)
				file_not_found( Animator.script );
			}
		else if (activate_record( Animator.script ) !=0) 
			creation_failure( Animator.script );

		}
	return( menu_refresh() );
}

public	int	screen_capture();
public	int	inspect_configuration();
public	int	use_font_editor()
{
	int	fontid;
	if ((fontid = Context.Item.font) > 0)
		fontid--;
	if ( standard_font_editor(&menu_character,&fontid) != 27 )
		Context.Item.font = (fontid+1);
	
	return(256);
}

private	void	release_menus()
{
	if ( UsingNewMenu ) {
		standard_main_menu_remove(Context.MainMenuContext);
		}
	if ( EditMenu )		EditMenu = drop_menu( EditMenu );
	if ( FileMenu )		FileMenu = drop_menu( FileMenu );
	if ( OptionMenu )	OptionMenu = drop_menu( OptionMenu );
	if ( EventMenu )	EventMenu = drop_menu( EventMenu );
	if ( MenuBar )		MenuBar = drop_menu( MenuBar );
	return;
}

public	void	build_menu()
{
	if ((!(MenuBar = allocatemenu(0,
			Context.MenuBar.x,
			Context.MenuBar.y,
			Context.MenuBar.w,
			Context.MenuBar.h,(void *) 0)))

	||  (!(EditMenu    = allocatemenu(1,0,0,0,0,(void *) 0)))
	||  (!(FileMenu    = allocatemenu(1,0,0,0,0,(void *) 0)))
	||  (!(OptionMenu    = allocatemenu(1,0,0,0,0,(void *) 0)))
	||  (!(EventMenu    = allocatemenu(1,0,0,0,0,(void *) 0)))

	||  (!( add_menu_item(MenuBar,"&File","File operations",'F',0,FileMenu)))
		||  (!( add_menu_item(FileMenu,"&New","Reset editor",'N',_FILE_NEW,(void*)0)))
		||  (!( add_menu_item(FileMenu,"&Save","Quick Save to File",'S',_FILE_QSAVE,(void*)0)))
		||  (!( add_menu_item(FileMenu,"Sa&ve As","Save to File",'S',_FILE_SAVE,(void*)0)))
		||  (!( add_menu_item(FileMenu,"&Open","Open a File",'L',_FILE_LOAD,(void*)0)))
		||  (!( add_menu_item(FileMenu,"&Production","Production of Target",'P',_FILE_PRODUCE,(void*)0)))
		||  (!( add_menu_item(FileMenu,"&Compare","Compare Files",'P',_FILE_COMPARE,(void*)0)))
#ifdef	PROTOTYPE
		||  (!( add_menu_item(FileMenu,"&Import","Import Model",'I',_FILE_IMPORT,(void*)0)))
		||  (!( add_menu_item(FileMenu,"E&xport","Export Model",'G',_FILE_IMAGE,(void*)0)))
		||  (!( add_menu_item(FileMenu,"Mer&ge","Merge Models",'M',_FILE_MERGE,(void*)0)))
#endif
		||  (!( add_menu_item(FileMenu,"&Drop","Drop a File",'D',_FILE_DROP,(void*)0)))
		||  (!( add_menu_item(FileMenu,"&Quit","Leave this Editor",'Q',_LEAVE_SING,(void*)0)))

	||  (!( add_menu_item(MenuBar,"&View","Activate Editor",'F',0,EditMenu)))
		||  (!( add_menu_item(EditMenu,"&Run","Execution",'X',_EXEC_PROG,&EditMenu->storage)))
		||  (!( add_menu_item(EditMenu,"Te&xt","Text editor",'I',_EDIT_TEXT,&EditMenu->storage)))
		||  (!( add_menu_item(EditMenu,"&Image","Image editor",'I',_EDIT_IMAGE,&EditMenu->storage)))
		||  (!( add_menu_item(EditMenu,"Fo&nt","Font editor",'F',-1,use_font_editor)))
	/* _EDIT_FONT, &EditMenu->storage))) */
		||  (!( add_menu_item(EditMenu,"&Properites","Property Editor",'P',_EDIT_PROPERTIES,&EditMenu->storage)))
		||  (!( add_menu_item(EditMenu,"&Visual","Visual Forms Editor",'M',_EDIT_FORM,&EditMenu->storage)))
		||  (!( add_menu_item(EditMenu,"&DataBase" ,"Access File Manager",'H',_EDIT_DATABASE,(void*)0)))
		||  (!( add_menu_item(EditMenu,"Tr&eeView","Tree Viewer",'C',-1,toggle_treeview)))
		||  (!( add_menu_item(EditMenu,"&Application","Application Editor",'A',_EDIT_GRAPH,&EditMenu->storage)))

	||  (!( add_menu_item(MenuBar,"&Event","Event Methods",'E',0,EventMenu)))
		||  (!( add_menu_item(EventMenu,"On&Create","Construction"	,'C',_EVENT_CREATE,(void*) 0)))
		||  (!( add_menu_item(EventMenu,"On&Remove","Destruction"	,'R',_EVENT_REMOVE,(void*) 0)))
		||  (!( add_menu_item(EventMenu,"On&Show"  ,"Prior to Display",'S',_EVENT_SHOW  ,(void*) 0)))
		||  (!( add_menu_item(EventMenu,"On&Hide"  ,"Before Disappear",'H',_EVENT_HIDE  ,(void*) 0)))
		||  (!( add_menu_item(EventMenu,"On&Focus" ,"Gets Focus"	,'F',_EVENT_FOCUS ,(void*) 0)))
		||  (!( add_menu_item(EventMenu,"On&Lose"  ,"Lose Focus"	,'L',_EVENT_LOSE  ,(void*) 0)))
		||  (!( add_menu_item(EventMenu,"On&Event" ,"Mouse Event"	,'E',_EVENT_EVENT ,(void*) 0)))
		||  (!( add_menu_item(EventMenu,"&Item Document","Item Documentation"	,'I',_EVENT_ITEMDOC ,(void*) 0)))
		||  (!( add_menu_item(EventMenu,"Form &Document","Form Documentation"	,'D',_EVENT_FORMDOC ,(void*) 0)))


	||  (!( add_menu_item(MenuBar,"&Options","General Options",'O',0,OptionMenu)))
		||  (!( add_menu_item(OptionMenu,"&Parameters","Modify Editor Parameters",'O',-1,general_parameters )))
#ifdef	_PROTOTYPE_CLASS
		||  (!( add_menu_item(OptionMenu,"Pra&gmas","Modify Object Pragmas",'G',-1,object_pragmas )))
#endif
		||  (!( add_menu_item(OptionMenu,"&Refresh","Redraw Desktop",'R',-1,menu_refresh)))
		||  (!( add_menu_item(OptionMenu,"&Configure","Inspect Configuration",'O',-1,inspect_configuration )))
		||  (!( add_menu_item(OptionMenu,"&Screen Capture","Capture Screen",'O',-1,screen_capture )))
#ifdef	PROTOTYPE
		||  (!( add_menu_item(OptionMenu,"&File Compare","Compare Files",'C',-1,file_compare )))
#endif
#ifdef	PROTOTYPE
		||  (!( add_menu_item(OptionMenu,"A&bout","Information and Sing",'A',-1,about_sing)))
#endif
		||  (!( add_menu_item(OptionMenu,"&Animate","Record/Replay Animation",'N',-1,perform_animation )))) {
		release_menus();
		}
	if ((UsingNewMenu )
	||  (( UsingNewMenu = confgetenv("VMENUS")) != (char *) 0))
		standard_main_menu_create(&Context.MainMenuContext);
	return;
}

public	int	get_menubar_height()
{
	return( Context.MenuBar.h );
}

public	void	activate_MenuBar(int mode)
{
	if ((Context.MenuBar.style = mode)!=0) {
		Context.MenuBar.x = ((Context.ToolBar.x+Context.ToolBar.w)+1);
		Context.MenuBar.h = ((Context.fontheight*2)-1); 
		Context.MenuBar.y = 1;
		Context.MenuBar.w = inner_width(1);
		if (!( MenuBar )) 
			build_menu();
		MenuBar->x = Context.MenuBar.x;
		MenuBar->y = Context.MenuBar.y;
		MenuBar->w = Context.MenuBar.w;
		MenuBar->h = Context.MenuBar.h;
		}
	else	{
		Context.MenuBar.x = Context.MenuBar.y = 
		Context.MenuBar.w = Context.MenuBar.h = 0;
		}
	return; 
}

public	void	show_menu_item(
	struct	menu_item * optr,
	int	atx,
	int	aty	)
{
	int	dy=2;
	int	bg;
	int	fh;
	int	menufont=2;
	if ( optr->message ) {
		if ( optr->active ) {
			if ( optr->hint )
				status_message(optr->hint,3);
			cicocolour(standard_black,transparent );
			bg = standard_title;
			}
		else	{
			cicocolour(standard_black,transparent);
			bg = standard_backwash;
			}

		if ( optr->message != (char *) 0 ) {
			fh = guifontsize(menufont);
			fh >>= 8;
			fh &= 0x00FF;
			optr->w  = textsizelen( menufont, optr->message, strlen(optr->message) );
			optr->w += Context.fontwidth;
			if (!( optr->w & 1 )) optr->w++;
			if ( bg != standard_backwash ) {
				visual_frame(
					(atx+optr->x-(Context.fontwidth+1)),
					(aty+optr->y),
					(optr->w+Context.fontwidth),
					fh,_GROOVE_FRAME);
				}
			else	{
				filzone(
					(atx+optr->x-(Context.fontwidth+1)),
					(aty+optr->y),
					(optr->w+Context.fontwidth),
					fh,bg);
				}
			}


		if (( optr->shadow != (int *) 0 )
		&&  ( optr->result != -1        )) {
			if ( optr->nature ) {
				if ( *optr->shadow != 0 )
					(void) PixelFontCat( (atx+optr->x-Context.fontwidth),
						(aty+optr->y+dy),Context.basefont,'x' );
				else	(void) PixelFontCat( (atx+optr->x-Context.fontwidth),
					(aty+optr->y+dy),Context.basefont,' ' );

				}
			else if ( *optr->shadow == optr->result) 
				(void) PixelFontCat( (atx+optr->x-Context.fontwidth),
					(aty+optr->y+dy),Context.basefont,'*' );
			else	(void) PixelFontCat( (atx+optr->x-Context.fontwidth),
					(aty+optr->y+dy),Context.basefont,' ' );
			}

		if ( optr->hotkey ) {

			visual_trigger(
				(atx+optr->x),(aty+optr->y+dy),
				(optr->w+Context.fontwidth),Context.fontheight,
				Context.menufont,standard_black,transparent,
				optr->message, optr->length,_A_LEFT);
			}
		else	{
			(void) PixelFontSat( 	
				(atx+optr->x),(aty+optr->y+dy),
				Context.menufont,
				optr->message
				);
			}
		optr->w = (optr->length * Context.fontwidth);
		optr->h = Context.fontheight;
		}
	return;
}


public	void	draw_hmenu( struct menu_manager * mptr )
{
	struct	menu_item * optr;
	int	gratcol;
	int	gratlin;
	if (( mptr->w > 0 ) && ( mptr->h > 0 )) {

		hide();
		visual_frame(	mptr->x,mptr->y,mptr->w,mptr->h+1,_HMENU_FRAME );
	
		for (	gratcol=(Context.fontwidth*2),
			gratlin=(Context.fontheight/2),
			optr=MenuBar->first; 
			optr != (struct	menu_item *) 0;
			optr = optr->next ) {
			optr->x=gratcol; optr->y=gratlin;
			show_menu_item(optr,mptr->x,mptr->y);
			if ((!( optr->result )) 
			&&  (  optr->linkage )) {
				optr->linkage->x = (mptr->x+optr->x-Context.fontwidth);
				optr->linkage->y = (mptr->y+mptr->h+1);
				}
			gratcol += (Context.fontwidth*(optr->length+2));
			}
		show( mptr->x,mptr->y,mptr->w,mptr->h+1 );
		}
	return;
}

public	void	shadow_vmenu( struct menu_manager * mptr )
{
	int	nbr;
	int	nbc;
	int	r;
	char *	bptr;
	if (!( mptr ))
		return;
	else	{
		nbc=(mptr->w+10);
		nbr=(mptr->h+10);
		}
	if ((!( mptr->shadow ))
	&&  (!( mptr->shadow = local_allocate_image( nbc,nbr,0, 0 ) )))
		return;

	for (r=0; r < nbr; r++ ) {
		if (!(bptr = connect_pixel_row( mptr->shadow->storage, r )))
			break;
		else	getzone( mptr->x,mptr->y+r,nbc,1,bptr);
		}
	/* this may be added to addow underlying shadow */
	/* I don't like it much
	xfilzone(mptr->x+5,mptr->y+5,mptr->w,mptr->h,18);
	*/
	return;
}

public	void	draw_vmenu( struct menu_manager * mptr )
{
	struct	menu_item * optr;
	int	gratcol;
	int	gratlin;
	if ( mptr->visible )
		return;
	if (( mptr->w > 0 ) && ( mptr->h > 0 )) {
		mptr->visible = 1;
		shadow_vmenu( mptr );
		hide();
		visual_frame(	mptr->x,mptr->y,mptr->w,mptr->h,_MENU_FRAME );

		for (	gratcol=(Context.fontwidth*2),
			gratlin=(Context.fontheight/2),
			optr=mptr->first; 
			optr != (struct	menu_item *) 0;
			optr = optr->next ) {
			optr->x=gratcol; optr->y=gratlin;
			show_menu_item(optr,mptr->x,mptr->y);
			gratlin += Context.fontheight;
			}
		show(	mptr->x,mptr->y,mptr->w,mptr->h );
		mouse_move_on();
		}
	return;
}

public	void	hide_vmenu( struct menu_manager * mptr )
{
	int	nbc;
	int	nbr;
	int	r;
	char *	bptr;
	mouse_move_off();
	while ( visual_kbhit() ) (void) visual_getch();
	if (!( mptr ))
		return;
	else if (!( mptr->visible ))
		return;
	else if (!( mptr->shadow ))
		draw_DeskTop();
	else	{
		hide();
		for (nbc=mptr->w+10,nbr=mptr->h+10,r=0; r < nbr; r++ ) {
			if (!(bptr = connect_pixel_row( mptr->shadow->storage, r )))
				break;
			else	putzone( mptr->x,mptr->y+r,nbc,1,bptr);
			}
		show(mptr->x,mptr->y,nbc,nbr);
		}
	mptr->visible = 0;
	return;
}

public	void	draw_abal_tools()
{
	int	aty=(Context.MenuBar.y + 4);
	int	nbx=(Context.fontheight+3);
	int	atx=((Context.MenuBar.x+Context.MenuBar.w)-(5*nbx));
	if ( ExadbIcon )  SingDrawIcon(atx,aty,ExadbIcon,_INSET_FRAME);
	atx += nbx;
	if ( ExaIcon )  SingDrawIcon(atx,aty,ExaIcon,_INSET_FRAME);
	atx += nbx;
	if ( AedIcon )  SingDrawIcon(atx,aty,AedIcon,_INSET_FRAME);
	atx += nbx;
	if ( OtrIcon )  SingDrawIcon(atx,aty,OtrIcon,_INSET_FRAME);
	atx += nbx;
	if ( OldIcon )  SingDrawIcon(atx,aty,OldIcon,_INSET_FRAME);
	return;
}

public	void	editor_wipe_icons()
{
	int	aty=(Context.MenuBar.y + 4);
	int	atx=((Context.MenuBar.x+Context.MenuBar.w)-(5*(Context.fontheight+3))-(16*Context.fontwidth));
	filzone(atx,aty,Context.fontwidth*14,Context.fontheight,standard_backwash);
	return;
}

public	void	editor_insert_icon(int value)
{
	int	aty=(Context.MenuBar.y + 6);
	int	atx=((Context.MenuBar.x+Context.MenuBar.w)-(5*(Context.fontheight+3))-(16*Context.fontwidth));
	visual_switch(atx,aty,Context.fontwidth*4,Context.fontheight,1,25,26,"INS",3,(value | 0x0030));
	return;
}

public	void	editor_indent_icon(int value)
{
	int	aty=(Context.MenuBar.y + 6);
	int	atx=((Context.MenuBar.x+Context.MenuBar.w)-(8*(Context.fontheight+3))-(8*Context.fontwidth));
	visual_switch(atx,aty,Context.fontwidth*4,Context.fontheight,1,25,26,"IND",3,(value | 0x0030));
	return;
}

public	void	editor_line_counter(int value)
{
	int	aty=(Context.MenuBar.y + 6);
	int	atx=((Context.MenuBar.x+Context.MenuBar.w)-(5*(Context.fontheight+3))-(8*Context.fontwidth));
	char	buffer[16];
	sprintf(buffer,"%lu",value);
	atx -=4;
	visual_freeze();
	visual_frame(atx,aty,(Context.fontwidth*8),(Context.fontheight),_INSET_FRAME);
	visual_frame(atx+1,aty+1,(Context.fontwidth*8)-2,(Context.fontheight)-2,_EDIT_FRAME);
	visual_text (atx+2,aty+2,(Context.fontwidth*8)-4,Context.fontheight,1,16,0,buffer,strlen(buffer),3);
	visual_thaw(atx,aty,(Context.fontwidth*8),(Context.fontheight));
	return;
}

public	void	editor_basket_icon(int value)
{
	int	aty=(Context.MenuBar.y + 6);
	int	atx=((Context.MenuBar.x+Context.MenuBar.w)-(5*(Context.fontheight+3))-(12*Context.fontwidth));
	visual_switch(atx-2,aty,Context.fontwidth*4,Context.fontheight,1,25,26,"SEL",3,(value | 0x0030));
	return;
}


public 	void	draw_MenuBar()	
{ 
	if (( UsingNewMenu )) {
		if ( Context.MenuBar.h )
			standard_main_menu_show(Context.MainMenuContext);
		}
	else if ( Context.MenuBar.style ) {
		if ( MenuBar ) {
			draw_hmenu(MenuBar);
			draw_abal_tools();
			}
		}
	return;
}

public 	void swap_MenuBar()
{
#ifdef	ABAL32A
	int	tvs=Context.TreeView.style;
	if ( Context.MenuBar.style )
		activate_MenuBar(0);
	else	activate_MenuBar(_OUTSET_FRAME);
	if ( Context.StatusBar.style )
		activate_StatusBar(0);
	else	activate_StatusBar(_OUTSET_FRAME);
	activate_DeskTop(0);
	activate_DeskTop(_OUTSET_FRAME);
	reactivate_TreeView(0);
	reactivate_TreeView(tvs);
	resize_console();
#endif
	return;
}

private	void	disactivate_vmenu( 
	struct menu_manager * mptr,
	struct menu_item * optr )
{
	optr->active = 0;

	hide_vmenu(mptr);

	if (!( mptr = mptr->parent ))
		return;

	else if (!( optr = mptr->current ))
		return;
	else	{
		optr->active = 0;
		show_menu_item( optr, mptr->x,mptr->y);
		return;
		}
}

private	int	ActivateMenuOption(
		struct	menu_manager * mptr,
		struct	menu_item * optr )
{
	int 	(*service)(void);
	optr->active = 1;
	show_menu_item(optr,mptr->x,mptr->y);
	if ( optr->result ) {
		if  ( optr->shadow ) {
			disactivate_vmenu(mptr,optr);
			if ( optr->result != -1 ) {
				if (!( optr->nature ))
					*optr->shadow = optr->result;
				}
			else	{
				service = (int (*)(void))optr->shadow;
				return( (*service)() );
				}
			}
		if (( optr->parent )
		&&  ( optr->parent->service )) {
			disactivate_vmenu(mptr,optr);
			return( (*optr->parent->service)(optr->result) );
			}
		else	{
			disactivate_vmenu(mptr,optr);
			return( optr->result );
			}
		}
	return(256 );
}

private	void	DrawOptionLinkage( struct	menu_item * optr )
{
	if ((!( optr->result))
	&&  ( optr->linkage  )) {
		if (!( optr->active & 2)) {
			switch ( optr->linkage->type ) {
				case	0 :
					draw_hmenu( optr->linkage ); break;
				case	1 :
					draw_vmenu( optr->linkage ); break;
				}
			optr->active |= 2;
			}
		}
	return;
}

private	void	ThisMenuOption( 
	struct	menu_manager * mptr,
	struct	menu_item * optr,
	int	x,
	int	y )
{
	struct	menu_item * xptr;
	if (((xptr = mptr->current ))
	&&  ( xptr->active  )) {
		if ( xptr->linkage ) {
			if (( x >= xptr->x )
			&&  ( y >= xptr->y )
			&&  ( x < (xptr->x+xptr->w))
			&&  ( y < (xptr->y+xptr->h)))
				/* Its the same */
				return;
			else	{
				/* its different */
				/* ------------- */
				hide_vmenu(xptr->linkage );
				xptr->active = 0;
				show_menu_item(xptr,mptr->x,mptr->y);
				}
			}
		else	{
			xptr->active = 0;
			show_menu_item(xptr,mptr->x,mptr->y);
			}
		}
	mptr->current = optr;
	if (!( optr->active )) {
		mptr->current->active = 1;
		show_menu_item(mptr->current,mptr->x,mptr->y);
		}
	return;
}

public	int	is_MenuOptionEvent(int x,int y, struct menu_manager * mptr )
{
	int	aty=(Context.MenuBar.y + 4);
	int	nbx=(Context.fontheight+3);
	int	atx=((Context.MenuBar.x+Context.MenuBar.w)-(5*nbx));
	int	t;
	int	b;
	struct	menu_item * optr;
	struct	menu_item * xptr;
	int 	(*service)(void);

	y -= mptr->y;
	x -= mptr->x;


	for (	optr=mptr->first; 
		optr != (struct	menu_item *) 0;
		optr = optr->next ) {
		if (( x >= optr->x )
		&&  ( y >= optr->y )
		&&  ( x < (optr->x+optr->w))
		&&  ( y < (optr->y+optr->h))) {
			if (!( optr->active ))
				ThisMenuOption(mptr,optr,x,y);
			break;
			}
		}

	if (!( optr )) return(256);

	switch ((t = visual_event(1))) {
		case	_MIMO_MOVE	:
		case	_MIMO_WHILE_DOWN:
		case	_MIMO_DOWN	:
			DrawOptionLinkage(optr);
			return(256);

		case	_MIMO_UP	:
		case	_MIMO_CLICK	:
			while ( visual_kbhit() ) visual_getch();
			return( ActivateMenuOption(mptr,optr) );

		default			:
			return(256);
		}
}

public	int	insidePopUp( struct menu_manager * mptr, int x, int y )
{
	int	ltx=24;
	int	rtx=24;
	int	ty=24;

	if ( mptr->x < ltx )
		ltx = mptr->x;
	
	if (( y >= Context.MenuBar.y )
     	&&  ( y <= (mptr->y + mptr->h + ty))
	&&  ( x >= (mptr->x-ltx)       )
	&&  ( x <= (mptr->x + mptr->w + rtx))) {
		return(1);
		}
	else	return(0);
}

public	void	resolve_tool_parameters( int * automatic, char * * sptr, int * nature )
{
	int	button=visual_event(2);
	if ( Context.Form ) {
		*nature = Context.Form->language;
		*sptr = Context.Form->prodname ;
		}
	else	{
		camera_ItemFile( sptr );
		*nature = -1;
		}
	if ( button == _MIMO_LEFT )
		*automatic = _INHIBIT_PROPERTIES;
	else	*automatic=0;
	if (!( *sptr ))
		*sptr = "\0";
	return;
}

public	void	use_menu_editor()
{
	char *	sptr;
	int		button=visual_event(2);
	if ( Context.Form )
		sptr = Context.Form->prodname ;
	else	camera_ItemFile( &sptr );
	if( button == _MIMO_RIGHT )
		use_abal_editor();
	else	use_editor( sptr, 0 );
	return;
}


public 	int	is_AbalToolEvent(int x, int y )
{
	char	*	sptr=(char *) 0;
	int		slen;
	int		button=visual_event(2);
	int		automatic=0;
	if (visual_event(1) != _MIMO_UP)
		return(256);
	else if ( Context.Form )
		sptr = Context.Form->prodname ;
	else	camera_ItemFile( &sptr );
	if ( button == _MIMO_LEFT )
		automatic = _INHIBIT_PROPERTIES;
	else	automatic=0;
	if (!( sptr ))
		sptr = "\0";
	slen = strlen(	sptr );
	if ( x > ((Context.fontheight+3)*4))
		use_abal_linker(sptr,automatic);
	else if ( x > ((Context.fontheight+3)*3))
		use_abal_translator(sptr,automatic);
	else if ( x > ((Context.fontheight+3)*2)) 
		use_menu_editor();
	else if ( x > (Context.fontheight+3))
		abal_runtime(sptr,automatic);
	else if ( x > (Context.fontheight+3))
		abal_runtime(sptr,automatic);
	else	abal_debuger(sptr,automatic);
	return(256);
}


private	int	ChooseMenuOption(
	struct	menu_manager * mptr,
	struct	menu_item * optr,
	int e )
{
	hide_vmenu(mptr);
	optr->active = 0;
	show_menu_item(optr,MenuBar->x,MenuBar->y);
	if ( mptr->service )
		e = (*mptr->service)(e);
	return( e );
}


public	int	is_MenuBarAltEvent(int keycode)
{
	struct	menu_item * optr;
	struct	menu_manager * mptr;

	if (((optr = MenuBar->current ))
	&&  ((mptr = optr->linkage    ))
	&&  (( optr->active           ))) {
		for (	optr=mptr->first; 
			optr != (struct	menu_item *) 0;
			optr = optr->next ) {
			if (!( optr->hotkey ))
				continue;
			else if ( compare_hotkeys( optr->hotkey, keycode ) ) {
				ThisMenuOption(mptr,optr,0,0);
				DrawOptionLinkage(optr);
				/* ChooseMenuOption(mptr,optr, */
				return( ActivateMenuOption( mptr, optr ) );
				}
			}
		}

	for (	optr=MenuBar->first; 
		optr != (struct	menu_item *) 0;
		optr = optr->next ) {
		if (!( optr->hotkey ))
			continue;
		else if ( compare_hotkeys( optr->hotkey, keycode ) ) {
			ThisMenuOption(MenuBar,optr,0,0);
			DrawOptionLinkage(optr);
			return(256);
			}
		}
	return(-1);
}

public 	int	is_MenuBarEvent(int x, int y )
{
	int	aty=(Context.MenuBar.y + 4);
	int	nbx=(Context.fontheight+3);
	int	atx=((Context.MenuBar.x+Context.MenuBar.w)-(5*nbx));
	int	t;
	int	b;
	int	e;
	struct	menu_item * optr;
	struct	menu_manager * mptr;

	if (( UsingNewMenu )) {
		if ( Context.MenuBar.h ) {
			e =  standard_main_menu_event(Context.MainMenuContext);
			return(e);
			}
		}
	/* Is it a Menu Bar Alt HotKey Event */
	/* --------------------------------- */
	if ((t = visual_event(1)) & _MIMO_ALT)
		return( is_MenuBarAltEvent( visual_event(2) ) );

	/* Is it a click on the Menu Bar */
	/* ----------------------------- */
	if (( Context.MenuBar.style != 0)
	&&  ( MenuBar 			)) {

		if (( y > Context.MenuBar.y     		 )
		&&  ( y < (Context.MenuBar.y + Context.MenuBar.h))
		&&  ( x > Context.MenuBar.x      		 )
		&&  ( x < (Context.MenuBar.x + Context.MenuBar.w))) {
			if (( y >= aty ) 
			&&  ( y <= (aty+16))
			&&  ( x >= atx ) 
			&&  ( x <= (atx+(5*(Context.fontheight+1)))))
				return( is_AbalToolEvent(x-atx,y-aty) );
			else	return( is_MenuOptionEvent(x,y, MenuBar ) );
			}

		else if ((!(optr = MenuBar->current ))
		     ||  (!(mptr = optr->linkage    ))
		     ||  (!( optr->active           )))
			return(-1);

		else if ( insidePopUp( mptr, x, y ) ) {
			switch ((e = is_MenuOptionEvent(x,y, mptr ) )) {
				case	256	: break;
				case	-1	: 
				default		:
					e = ChooseMenuOption(mptr,optr,e);
				}
			return(e);
			}
		}
	if (((optr = MenuBar->current ))
	&&  ((mptr = optr->linkage    ))
	&&  (( optr->active           ))) {
		hide_vmenu(mptr);
		optr->active = 0;
		show_menu_item(optr,MenuBar->x,MenuBar->y);
		}
	return(-1);
}

public	void	drop_form_editor_menu()
{
	if ( UsingNewMenu ) {
		drop_menu_extension(Context.MainMenuContext,7);
		drop_menu_extension(Context.MainMenuContext,2);
		}
	else if (!( FormMenu ))
		return;
	else	{
		FormMenu = drop_menu( FormMenu );
		WidgetMenu = drop_menu( WidgetMenu );
		draw_MenuBar();
		}
	return;
}

public	int	new_menu_system()
{
	if ( UsingNewMenu )
		return(1);
	else	return(0);
}


public	void	add_form_editor_menu()
{
	if ( UsingNewMenu ) {
		standard_menu_extension(Context.MainMenuContext,2,&FormsMessage);
		standard_menu_extension(Context.MainMenuContext,7,&WidgetMsg); 
		}
	else if (!( FormMenu )) {
		if (!(FormMenu = allocatemenu(1,0,0,0,0,(void *) 0) ))
			return;
		if ((!( add_menu_item(MenuBar,"&Form","Forms Operations",'O',0,FormMenu)))
		||  (!( add_menu_item(FormMenu,"&Properities","Form Parameters",'F',_FORM_PARA, 	(void*) 0)))
		||  (!( add_menu_item(FormMenu,"&Document","Page Parameters",'D',-1,page_parameters )))
		||  (!( add_menu_item(FormMenu,"&ReNumerate","Renumerate auto names",'N',_FORM_NUMBER, (void *) 0)))
		||  (!( add_menu_item(FormMenu,"&Triggers","Recalculate widget triggers",'T',_FORM_TRIGGER, (void *) 0)))
		||  (!( add_menu_item(FormMenu,"&Undo","Undo last deletion",'U',_FORM_UNDO, (void *) 0)))
		||  (!( add_menu_item(FormMenu,"&Interface","Activate Interface Items",'O',_FORM_FACE,	(void*) 0)))) 
			FormMenu = drop_menu( FormMenu );
		else if (!(WidgetMenu = allocatemenu(1,0,0,0,0,(void *) 0) )) {
			FormMenu = drop_menu( FormMenu );
			return;
			}
		else	{
			if ((!( add_menu_item(MenuBar,"&Widget","Widget Operations",'O',0,WidgetMenu)))
			||  (!( add_menu_item(WidgetMenu,"&Messages","International Messages",'M',_WIDGET_MSG, (void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"&ItemHelp","Widget Documentation",'H',_WIDGET_HELP, (void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"&FormHelp","Form Documentation",'R',_WIDGET_FORM, (void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"&Font","Set Widget Font",'F',_WIDGET_FONT, (void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"&Type","Set Widget Type",'T',_WIDGET_TYPE, (void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"&Align","Set Widget Align",'A',_WIDGET_ALIG, (void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"&Bold","Set Widget Bold",'D',_WIDGET_BOLD, (void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"&Shadow","Set Widget Shadow",'D',_WIDGET_SHADOW, (void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"&Underline","Set Widget Underline",'U',_WIDGET_ULINE, (void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"&Copy","Copy Widget or Selection",'C',_WIDGET_COPY, 	(void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"&Paste","Paste Copied Widgets into Form",'P',_WIDGET_PASTE,(void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"&Lock","Lock Widget or Selection",'L',_WIDGET_LOCK, 	(void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"Unloc&k","Unlock Widget or Selection",'K',_WIDGET_UNLOCK, 	(void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"Auto&matic","Automatic Show",'O',_WIDGET_AUTO, (void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"Co&nditional","Conditional Show",'C',_WIDGET_COND, (void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"&Locate","Locate references",'L',_WIDGET_FIND, (void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"Co&nditional","Conditional Show",'C',_WIDGET_COND, (void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"F&oreground","Set Widget Foreground",'T',_WIDGET_FORE, (void*) 0)))
			||  (!( add_menu_item(WidgetMenu,"Back&ground","Set Widget Background",'W',_WIDGET_BACK, (void*) 0)))) {
				FormMenu = drop_menu( FormMenu );
				WidgetMenu = drop_menu( WidgetMenu );
				return;
				}
			else	draw_MenuBar();
			}

		}
	return;
}

public	void	add_font_editor_menu()
{
	if ( UsingNewMenu ) {
		standard_menu_extension(Context.MainMenuContext,6,&FontMessage); 
		}
	else if (!( FontMenu )) {
		if (!(FontMenu = allocatemenu(1,0,0,0,0,(void *) 0) ))
			return;
		if ((!( add_menu_item(MenuBar,"&Font","Font Operations",'O',0,FontMenu)))
		||  (!( add_menu_item(FontMenu,"&Copy         ^S","Copy Current Cell",'C',__FONT_CUT_CHAR,		 (void*)0)))
		||  (!( add_menu_item(FontMenu,"Pas&te        ^T","Paste Copied Cell to Current",'P',__FONT_PASTE_CHAR,	 (void*)0)))
		||  (!( add_menu_item(FontMenu,"&Recalculate  ^A","Calculate Proportional Font",'R',__FONT_FIX_CHAR,	 (void*)0)))
		||  (!( add_menu_item(FontMenu,"&SemiGraphics ^Q","Generate SemiGraphic Characters",'G',__FONT_SEMI_GRAPH,(void*)0)))
		||  (!( add_menu_item(FontMenu,"C&lear        ^Z","Clear to End of Cell",'E',__FONT_CLEAR_END, (void*)0)))
		||  (!( add_menu_item(FontMenu,"&Fill         ^W","Fill to End of Cell",'F',__FONT_WIPE_END, (void*)0)))
		||  (!( add_menu_item(FontMenu,"I&mport         ","Import Font Image",'I',_FILE_IMPORT,	 (void*)0)))
		||  (!( add_menu_item(FontMenu,"E&xport         ","Export Font Image",'I',_FILE_PRODUCE, (void*)0)))
		||  (!( add_menu_item(FontMenu,"Ex&tract        ","Extract Character",'I',__FONT_EXTRACT, (void*)0)))
		||  (!( add_menu_item(FontMenu,"&Invert       ^I","Invert Cell Matrix",'I',__FONT_INVERT, (void*)0)))
		||  (!( add_menu_item(FontMenu,"&Paper        ^P","Change Page Page",'F',__FONT_PAPER_TYPE, (void*)0))))
			FontMenu = drop_menu( FontMenu );
		else	draw_MenuBar();
		}
	return;
}

public	void	drop_font_editor_menu()
{
	if ( UsingNewMenu ) {
		drop_menu_extension(Context.MainMenuContext,6);
		}
	else if (!( FontMenu ))
		return;
	else	{
		FontMenu = drop_menu( FontMenu );
		draw_MenuBar();
		}
	return;
}

public	void	add_zoom_editor_menu()
{
	if (!( ZoomMenu )) {
		if (!(ZoomMenu = allocatemenu(1,0,0,0,0,(void *) 0) ))
			return;
		if ( UsingNewMenu ) {
			standard_menu_extension(Context.MainMenuContext,3,&ImageMessage);	
			}
		if ((!( add_menu_item(MenuBar,"&Image","Image Operations",'O',0,ZoomMenu)))
		||  (!( add_menu_item(ZoomMenu,"&Copy","Copy Selection",'C',_ZOOM_COPY,	 (void*)0)))
		||  (!( add_menu_item(ZoomMenu,"&Paste","Insert Selection",'P',_ZOOM_PASTE,	 (void*)0)))
		||  (!( add_menu_item(ZoomMenu,"&Rotate  90","Rotation Right 1/4 turn",'1',_ZOOM_ROTATE1,	 (void*)0)))
		||  (!( add_menu_item(ZoomMenu,"R&otate 180","Rotation Right 1/2 turn",'2',_ZOOM_ROTATE2,	 (void*)0)))
		||  (!( add_menu_item(ZoomMenu,"Ro&tate 270","Rotation Right 3/4 turn",'3',_ZOOM_ROTATE3,	 (void*)0)))
		||  (!( add_menu_item(ZoomMenu,"&Change Colour","Change pixel colour values",'Z',_ZOOM_COLOUR,(void*)0)))
		||  (!( add_menu_item(ZoomMenu,"&Grey Scale","Convert to grey",'G',_ZOOM_GREY,(void*)0)))
		||  (!( add_menu_item(ZoomMenu,"&Vertical Mirror","Reflect along middle Y axis",'V',_ZOOM_REFLECTY,(void*)0)))
		||  (!( add_menu_item(ZoomMenu,"&Horizontal Mirror","Reflect along middle X axis",'H',_ZOOM_REFLECTX, (void*)0)))
		||  (!( add_menu_item(ZoomMenu,"&Dimensions","Change Image Dimensions",'D',_ZOOM_CHANGE, (void*)0))))
			ZoomMenu = drop_menu( ZoomMenu );
		else	draw_MenuBar();
		}
	return;
}

public	void	drop_zoom_editor_menu()
{
	if (!( ZoomMenu ))
		return;
	else	{
		if ( UsingNewMenu ) {
			drop_menu_extension(Context.MainMenuContext,3);
			ZoomMenu = drop_menu( ZoomMenu );
			}
		else	{
			ZoomMenu = drop_menu( ZoomMenu );
			draw_MenuBar();
			}
		}
	return;
}

public	void	add_menu_menu()
{
	if (!( MenuMenu )) {
		if (!(MenuMenu = allocatemenu(1,0,0,0,0,(void *) 0) ))
			return;
		if ((!( add_menu_item(MenuBar,"&Menu","Menu Model operations",'M',0,MenuMenu)))
		||  (!( add_menu_item(MenuMenu,"&Properties","Menu Properties",'P',__MENU_PROPERTIES,(void*)0)))
		||  (!( add_menu_item(MenuMenu,"&Option"	,"Add Option"	,'O',__MENU_OPTION,(void*)0)))
		||  (!( add_menu_item(MenuMenu,"&Line","Add Separator"	,'S',__MENU_SEPARATOR, (void*)0))))
			MenuMenu = drop_menu( MenuMenu );
		else	draw_MenuBar();
		}
	return;
}
public	void	drop_menu_menu()
{
	if (!( MenuMenu ))
		return;
	else	{
		MenuMenu = drop_menu( MenuMenu );
		draw_MenuBar();
		}
}


public	void	add_class_menu()
{
	if (!( ClassMenu )) {
		if (!(ClassMenu = allocatemenu(1,0,0,0,0,(void *) 0) ))
			return;
		if ((!( add_menu_item(MenuBar,"&Class"		,"Class Model Operations",'O',0,ClassMenu)))
		||  (!( add_menu_item(ClassMenu,"&Properties"	,"Class Properties"	,'C',__CLASS_PROPERTIES,	(void*)0)))
		||  (!( add_menu_item(ClassMenu,"&Constant"	,"Add constant"	,'C',__ADD_CONSTANT,	(void*)0)))
		||  (!( add_menu_item(ClassMenu,"&Data"		,"Add data"	,'D',__ADD_DATA,	(void*)0)))
		||  (!( add_menu_item(ClassMenu,"&Method"	,"Add method"	,'M',__ADD_METHOD,	(void*)0))))
			ClassMenu = drop_menu( ClassMenu );
		else	draw_MenuBar();
		}
	return;
}

public	void	drop_class_menu()
{
	if (!( ClassMenu ))
		return;
	else	{
		ClassMenu = drop_menu( ClassMenu );
		draw_MenuBar();
		}
}

public	void	add_trace_menu()
{
	if ( UsingNewMenu ) {
		standard_menu_extension(Context.MainMenuContext,5,&TraceMessage);	
		}
	else if (!( TraceMenu )) {
		if (!(TraceMenu = allocatemenu(1,0,0,0,0,(void *) 0) ))
			return;
		if ((!( add_menu_item(MenuBar,"&Trace"		,"Error Tracing Operations",'T',0,TraceMenu)))
		||  (!( add_menu_item(TraceMenu,"&First"	,"First"	,'F',__TRACE_FIRST,(void*)0)))
		||  (!( add_menu_item(TraceMenu,"&Previous"	,"Previous"	,'P',__TRACE_PREVIOUS,	(void*)0)))
		||  (!( add_menu_item(TraceMenu,"&Widget"	,"Widget"	,'W',__TRACE_WIDGET,	(void*)0)))
		||  (!( add_menu_item(TraceMenu,"&Method"	,"Method"	,'W',__TRACE_METHOD,	(void*)0)))
		||  (!( add_menu_item(TraceMenu,"&Next"		,"Next"	,	'N',__TRACE_NEXT,	(void*)0)))
		||  (!( add_menu_item(TraceMenu,"&Last"		,"Last"	,	'L',__TRACE_LAST,	(void*)0))))
			TraceMenu = drop_menu( TraceMenu );
		else	draw_MenuBar();
		}
	return;
}

public	void	drop_trace_menu()
{
	if ( UsingNewMenu ) {
		drop_menu_extension(Context.MainMenuContext,5);
		}
	else if (!( TraceMenu ))
		return;
	else	{
		TraceMenu = drop_menu( TraceMenu );
		draw_MenuBar();
		}
}

extern	int	standard_main_menu(void *);
extern	int	text_editor_find(void *);
extern	int	text_editor_replace(void *);
extern	int	text_editor_search(void *);

public	void	add_editor_menu()
{
	if ( UsingNewMenu ) {
		standard_menu_extension(Context.MainMenuContext,4,&EditorMessage);	
		}
	else if (!( EditorMenu )) {
		if (!(EditorMenu = allocatemenu(1,0,0,0,0,(void *) 0) ))
			return;
		if ((!( add_menu_item(MenuBar,"E&ditor"	,"Text Editor",'T',0,EditorMenu)))
		||  (!( add_menu_item(EditorMenu,"&Find"	,"Locate Text in this file",'F',-1,text_editor_find)))
		||  (!( add_menu_item(EditorMenu,"&Replace"	,"Locate and Replace Text in file",'R',-1,text_editor_replace)))
		||  (!( add_menu_item(EditorMenu,"&Syntax"	,"Widget Expression",'S',-1,syntax_composer)))
		||  (!( add_menu_item(EditorMenu,"&Search","Locate Text in files",'S',-1,text_editor_search))))
			EditorMenu = drop_menu( EditorMenu );
		else	draw_MenuBar();
		}
	return;
}
public	void	drop_editor_menu()
{
	if ( UsingNewMenu ) {
		drop_menu_extension(Context.MainMenuContext,4);
		}
	else if (!( EditorMenu ))
		return;
	else	{
		EditorMenu = drop_menu( EditorMenu );
		draw_MenuBar();
		}
	return;
}

#ifdef	_PROTOTYPE_ANALYSER
public	int	use_analyser()
{
	visual_analyser();
	return(256);

}
#endif

public	void	add_3d_editor_menu()
{
	char	*	nptr;
	if ( UsingNewMenu ) {
		standard_menu_extension(Context.MainMenuContext,1,&ProjectMessage);
		}
	else if (!( ThreedMenu )) {
		if (!(ThreedMenu = allocatemenu(1,0,0,0,0,(void *) 0) ))
			return;
		if ((!( add_menu_item(MenuBar,"&Project"	,"3d Operations",'P',0,ThreedMenu)))
		||  (!( add_menu_item(ThreedMenu,"&Camera"	,"Camera Properties",'C',__3D_CAMERA,	(void*)0)))
		||  (!( add_menu_item(ThreedMenu,"&Translate"	,"Translate national language",'T',__3D_TRANSLATE,(void*)0)))
		||  (!( add_menu_item(ThreedMenu,"&HelpText"	,"Form Help Text Editor",'H',__3D_HELP,(void*)0)))
/*		||  (!( add_menu_item(ThreedMenu,"&Align"	,"Align 3d Elements",'H',__3D_ALIGN,(void*)0)))	*/
#ifdef	_PROTOTYPE_ANALYSER
		||  (!( add_menu_item(ThreedMenu,"&Analyse"	,"Analyse Application",'A',2727,(void *) 0)))
#endif
#ifdef	_PROTOTYPE_MENUS
		||  (!( add_menu_item(ThreedMenu,"Add &Menu"		,"Add Menu",'M',__3D_MENU,	(void*)0)))
#endif
		||  (!( add_menu_item(ThreedMenu,"&Add Form"		,"Add Form",'A',__3D_FORM,		(void*)0)))
#ifdef	_PROTOTYPE_CLASS
		||  (!( add_menu_item(ThreedMenu,"Add Cla&ss"	,"Add Class",'A',__3D_CLASS,		(void*)0)))
#endif
		||  (!( add_menu_item(ThreedMenu,"Add &Source"	,"Add Source",'T',__3D_TEXT,		(void*)0)))
		||  (!( add_menu_item(ThreedMenu,"Add &Image"	,"Add Image",'X',__3D_IMAGE,		(void*)0)))
#ifdef	PROTOTYPE
		||  (!( add_menu_item(ThreedMenu,"&Library"	,"Add Library",'X',__3D_LIBRARY,	(void*)0)))
		||  (!( add_menu_item(ThreedMenu,"&Project"	,"Add Project",'X',__3D_PROJECT,	(void*)0)))
#endif

#ifdef	PROTOTYPE
		||  (!( add_menu_item(ThreedMenu,"&ReCalculate"	,"ReCalculate Items" ,'R',__3D_CALC,	(void*)0)))
		||  (!( add_menu_item(ThreedMenu,"For&ward"	,"Look Forward",'F',__3D_FORWARD,&ThreedMenu->storage)))
		||  (!( add_menu_item(ThreedMenu,"Bac&k"		,"Look Back",'B',__3D_BACK,	 &ThreedMenu->storage)))
		||  (!( add_menu_item(ThreedMenu,"Lef&t"		,"Look Left",'L',__3D_LEFT,	 &ThreedMenu->storage)))
		||  (!( add_menu_item(ThreedMenu,"Ri&ght"	,"Look Right",'R',__3D_RIGHT,	 &ThreedMenu->storage)))
		||  (!( add_menu_item(ThreedMenu,"&Up"		,"Look Up",'U',__3D_UP,	 	 &ThreedMenu->storage)))
		||  (!( add_menu_item(ThreedMenu,"Do&wn"		,"Look Down",'D',__3D_DOWN,	 &ThreedMenu->storage)))
#endif
		)
			ThreedMenu = drop_menu( ThreedMenu );
		else	draw_MenuBar();
		}
	return;
}

public	void	drop_3d_editor_menu()
{
	if ( UsingNewMenu ) {
		drop_menu_extension(Context.MainMenuContext,1);
		}
	else if (!( ThreedMenu ))
		return;
	else	{
		ThreedMenu = drop_menu( ThreedMenu );
		draw_MenuBar();
		}
	return;
}

public	void	drop_MenuBar()
{
	release_menus();
	return;
}

#ifdef	ABAL32A
public	int	style_editor()
{
	int	event;
	if ((event = cstyleman()) == 27)
		return(0);
	else	return( event );
}
#endif

#endif	/* _singmenu_c */
	/* ----------- */

