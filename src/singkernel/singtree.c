#ifndef	_singtree_c
#define	_singtree_c

#include "singtree.h"

struct	tree_manager TreeMan = { 
		0,0,0,0,
		"....", "[-].","[+].","   .",
		(char * ) 0 ,
		(char * ) 0
		};

public	struct	tree_configuration TreeConf = { 1,1,4,1,1,1,0,0 };

public	struct treeview * allocate_for_treeview()
{
	struct	treeview * tptr;
	if ((tptr = allocate( sizeof( struct treeview ) )) != (struct treeview *)0) {
		tptr->previous = tptr->next =
		tptr->first    = tptr->last =
		tptr->parent   = tptr->current  = (struct treeview *) 0;
		tptr->atcol    = tptr->atrow = 0;
		tptr->state    = tptr->nature   = 0;
		tptr->payload  = (void *) 0;
		}
	return( tptr );
}

/*	
 *	Liberation of a TreeView node structure as a result of the 
 *	removal of the item from its parent and its host lists.
 *
 *	This function does not perform content call through but does
 *	reset the host reference to its tree node.
 *
 */

public	struct treeview * liberate_for_treeview(struct treeview * tptr) 
{
	struct	treeview * lptr;
	if ( tptr != (struct treeview *) 0 ) {

		/* drop all treeview members */
		while ((lptr = tptr->first) != (struct treeview *) 0) {
			tptr->first = lptr->next;
			lptr = liberate_for_treeview( lptr );
			}
		/* reset host reference 		*/
		disconnect_treeview( tptr );
		/* release memory */
		liberate( tptr );
		}
	return( (struct treeview *) 0);
}
 
public	void connect_treenode( struct treeview * tptr, int n, void * p)
{
	if (!( tptr ))
		return;
	else	{
		tptr->nature = n;
		tptr->payload= p;
		return;
		}
}

public	int add_treenode( struct treeview * tptr, struct treeview * lptr )
{
	if (!(lptr->previous = tptr->last))
		tptr->first = lptr;
	else	tptr->last->next = lptr;
	tptr->last = lptr;
	lptr->parent = tptr;
	tptr->current= lptr;
	return( 1 );
}

public	int append_treenode( 
		struct treeview * tptr,
		struct treeview * nptr,
		struct treeview * lptr 
		)
{
	if (!( lptr->previous = nptr ))
		tptr->first = lptr;
	else	{
		if (!(lptr->next = nptr->next))
			tptr->last = lptr;
		else	lptr->next->previous = lptr;
		nptr->next = lptr;
		}
	lptr->parent = tptr;
	return( 1 );
}

public	int add_treeleaf( struct treeview * tptr, struct treeview * lptr )
{
	struct treeview * mptr;

	if ( tptr->state & _TREE_CLOSED )
		return(0);

	for (  	mptr=tptr->first;
		mptr != (struct treeview *) 0;
		mptr = mptr->next ) 
		if ( add_treeleaf( mptr, lptr ) )
			return(1);

	return( add_treenode( tptr, lptr ) );
}

public	 int close_treeview( struct treeview * tptr )
{
	struct treeview * mptr;

	if ( tptr->state & _TREE_CLOSED )
		return(0);

	for (  	mptr=tptr->first;
		mptr != (struct treeview *) 0;
		mptr = mptr->next ) 
		if ( close_treeview( mptr ) )
			return(1);

	tptr->state |= _TREE_CLOSED;
	return(1);
}

char	*	event_message( void * vptr )
{
	return("[event]");
}

char	*	class_message( void * vptr );
char	*	file_message( void * vptr );
char	*	menu_message( void * vptr );
char	*	font_message( void * vptr )
{
	return("[font]");
}

char	*	widget_message( struct treeview * tptr ,void * vptr );
char	*	form_message( void * vptr );
char	*	project_message( void * vptr );
char	*	image_message( void * vptr );
char	*	text_message( void * vptr );

private	char * treeview_message( struct treeview * tptr )
{
	char	*	mptr;
	switch ( tptr->nature ) {
		case	0 : return("[null]");
		case	TREE_EVENT	:
			return( event_message( tptr->payload ) );
		case	TREE_WIDGET	:
			return( widget_message(tptr, tptr->payload ) );
		case	TREE_FORM	:
			return( form_message( tptr->payload ) );
		case	TREE_PROJECT	:
			return( project_message( tptr->payload ) );
#ifdef	_PROTOTYPE_CLASS
		case	TREE_CLASS	:
			return( class_message( tptr->payload ) );
#endif
		case	TREE_IMAGE	:
			return( image_message( tptr->payload ) );
		case	TREE_TEXT	:
			return( text_message( tptr->payload ) );
		case	TREE_FONT	:
			return( font_message( tptr->payload ) );
		case	TREE_MENU	:
#ifdef	_PROTOTYPE_MENUS
			return( menu_message( tptr->payload ) );
#endif
		case	TREE_ROOT	:
			if (!( mptr = configuration_item( "IDENTITY" )))
				return("[sing]");
			else	return( mptr );

		default			:
			return("[what]");
		}
}

public		int	is_treeview_visible(struct treeview * tptr )
{
	if (!( tptr ))
		return(1);
	if (!( tptr->state & _TREE_OPEN ))
		return(0);
	else if (!( tptr->parent ))
		return( 1 );
	else	return( is_treeview_visible( tptr->parent ) );
}

public		int	draw_treenode(struct treeview * tptr )
{
	char *	mptr;
	if (!( Context.TreeTop ))
		return(1);
	if (!( check_class_buffer() ))
		return(0);
	if (!( mptr = treeview_message( tptr ) ))
		return(1); 
	else if (!( is_treeview_visible( tptr->parent ) ))
		return(1);
	if ( tptr->identity < Context.TreeTop->identity)
		return(1);
	else if (tptr->identity > (Context.TSB.vps+Context.TreeTop->identity))
		return(1);
	else	{
		output_string( mptr );
		treeview_Message(
			tptr->atcol,tptr->atrow,
			mptr,strlen(mptr),
			tptr->nature,
			(
			(tptr->state & _TREE_FOCUS) |
			(tptr->next  ? 0x1000 : 0 ) |
			((tptr->state & _TREE_BOLD) ? _A_BOLD : 0) |
			1),1
			);
		tptr->state &= ~_TREE_BUILD;
		return(1);
		}
}

public		int	draw_treeleaf(struct treeview * tptr, int atcol, int * atrow  )
{
	int	r;
	if ((r = *atrow) >= Context.TreeView.h )
		return(0);
	else if ((r + Context.treefontheight) > Context.TreeView.h )
		return(0);
	else	{
		tptr->atrow = r;
		tptr->atcol = atcol; 
		*atrow += Context.treefontheight;
		tptr->state |= _TREE_BUILD;
		return( draw_treenode( tptr ) );
		}
}

public		int	draw_tree_view(struct treeview * tptr, int atcol, int * atrow )
{
	struct treeview * lptr;
	int	level;
	int	status=1;
	char * mptr;

	while (tptr != (struct treeview *) 0) {


		/* count it and draw it ( if we still can ) */
		/* ---------------------------------------- */
		if (( mptr = treeview_message( tptr )) != (char *) 0) {
			if (!( draw_treeleaf( tptr,atcol, atrow ) ))
				return(0);
			}
		/* if an open collection : step into first */
		/* --------------------------------------- */
		if ( tptr->first ) {
			if ( tptr->state & _TREE_OPEN ) {
				atcol += _TREE_INDENT;
				tptr = tptr->first;
				continue;
				}
			}

		/* is there a next at this level */
		/* ----------------------------- */
		if ( tptr->next ) {
			tptr = tptr->next;
			continue;
			}
		while (1) {
			if (!( tptr->parent ))
				return(0);
			else if (!( tptr->parent->next )) {
				tptr = tptr->parent;
				if ( atcol > _TREE_INDENT ) 
					atcol -= _TREE_INDENT;
				else	atcol = 0;
				}
			else	{
				tptr = tptr->parent->next;
				if ( atcol > _TREE_INDENT ) 
					atcol -= _TREE_INDENT;
				else	atcol = 0;
				break;
				}
			}
		}
	return(status);
}

public		void	initialise_tree_manager()
{
	TreeMan.height = Context.TreeView.h;
	TreeMan.width  = Context.TreeView.w;
	TreeMan.fontheight = guifontsize(1);	
	TreeMan.fontwidth = (TreeMan.fontheight & 0x00FF);
	TreeMan.fontheight >>= 8;	
	TreeMan.fontheight &= 0x00FF;
	TreeMan.pattern = (char *) 0;
	return;
}

public		void	terminate_tree_manager()
{
	if ( TreeMan.pattern )
		liberate( TreeMan.pattern );
	initialise_tree_manager();
	return;
}

public	void	reactivate_TreeView(int state)
{
	Context.DeskTop.style = 0;
	if (!(Context.TreeView.style = state)) {
		Context.TreeView.w = TreeConf.width;
		Context.TreeView.x = 
		Context.TreeView.y = 
		Context.TreeView.h = 0;
		reset_scroll( &Context.TSB );
		}
	else	{
		Context.TreeView.adjust = (Context.fontwidth*3);
		Context.TreeView.x = (Context.ToolBar.x+Context.ToolBar.w+1);
		Context.TreeView.y = (Context.MenuBar.y+Context.MenuBar.h);
		if (!( Context.TreeView.w = TreeConf.width ))
			Context.TreeView.w = ((Context.MenuBar.w/4)+Context.TreeView.adjust);
		Context.TreeView.h = inner_height();
		}
	return;
}

public	void	activate_TreeView(int state)
{
	if (( state == _RIDGE_FRAME )
	&& (!( TreeConf.zonage  & 1)))
		state = _EDIT_FRAME;

	if ( Context.TreeView.style == state )
		return;
	else	{
		reactivate_TreeView(state);
		return;
		}
}

public	void	calculate_treescroll( struct treeview * tptr )
{
	struct	treeview * lptr;

	if ( tptr != (struct treeview *) 0 ) {
		tptr->identity = ++Context.TSB.vpl;
		if ( tptr->state & _TREE_OPEN ) {
			for ( 	lptr=tptr->first;
				lptr != (struct treeview *) 0;
				lptr = lptr->next ) {
				calculate_treescroll( lptr );
				}
			}
		}
	return;
}


public	void	draw_TreeView()
{
	int	atcol=0;
	int	atrow=0;
	int	totvis=0;
	struct	treeview * tptr;
	char *	mptr;
	if ( Context.TreeView.style != 0 ) {
		hide();

		visual_frame(	Context.TreeView.x,Context.TreeView.y,
			Context.TreeView.w+1,Context.TreeView.h,Context.TreeView.style);

		if (!( Context.TreeTop ))
			Context.TreeTop = Context.Tree;

		reset_scroll( &Context.TSB );

		Context.TSB.vps = (Context.TreeView.h/Context.treefontheight);

		calculate_treescroll( Context.Tree );

		/* back calculate indentation of the current trre top */
		/* -------------------------------------------------- */
		if ((tptr = Context.TreeTop) != (struct treeview*) 0) {
			while ( tptr->parent ) {
				atcol+=_TREE_INDENT;
				tptr = tptr->parent;
				}
			}

		draw_tree_view( Context.TreeTop, atcol, & atrow );

		if ( Context.TreeTop )
			Context.TSB.vpo = Context.TreeTop->identity;

		draw_TreeScroll();

		show(	Context.TreeView.x,Context.TreeView.y,
			Context.TreeView.w,Context.TreeView.h );

		}
	return;

}

public	void	focus_treenode( struct treeview * tptr, int state )
{
	if ( tptr ) {
		if (!( state  & _TREE_FOCUS ))
			tptr->state &= ~_TREE_FOCUS;
		else	tptr->state |= _TREE_FOCUS;

		if  ( Context.TreeFocus ) {
			if (!( state  & _TREE_FOCUS ))
				Context.Tree->state &= ~_TREE_FOCUS;
			else	Context.Tree->state |= _TREE_FOCUS;
			}

		draw_treenode((Context.TreeFocus = tptr));
		}
	return;
}

public	int	select_TreeEvent( void * vptr )
{
	return(0);
}

public	int	select_TreeFont( void * vptr )
{
	return(0);
}

private	int	resize_TreeView(int x,int y)
{
	int	event;
	int	tx;
	int	ty;
	if (visual_event(1) != _MIMO_DOWN) 
		return(0);

	while (1) {
		show_tree_sprite( x,y );
		if ((event = visual_getch()) == 256) {
			hide_sprite();
			tx = visual_event(7); 
			ty = visual_event(6); 
			if (( tx > Context.TreeView.x ) 
			&&  ( tx < Context.Palette.x  )) {
				x = tx; y = ty;
				TreeConf.width = Context.TreeView.w = (tx - Context.TreeView.x);
				activate_DeskTop(0);
				activate_DeskTop(_OUTSET_FRAME );
				resize_console();
				}	
			if ((event = visual_event(1)) == _MIMO_UP)
				break;
			}
		else if ( event == 27 ) {
			hide_sprite();
			break;
			}
		}

	return(0);
}
	
private	int	compare_treeview_item( struct treeview * tptr , char * nptr )
{
	switch ( tptr->nature ) {
		case	TREE_FORM	:
			return( compare_treeview_form( tptr->payload, nptr ) );
		case	TREE_IMAGE	:
			return( compare_treeview_image( tptr->payload, nptr ) );
		case	TREE_TEXT	:
			return( compare_treeview_text ( tptr->payload, nptr ) );
		default			:
			return( 0 );
		}
}

private	int	detect_treeview_item(struct treeview * tptr,char * nptr)
{
	if (!( tptr ))
		return(0);
	for (	;
		tptr != (struct treeview *) 0;
		tptr = tptr->next ) {
		if (compare_treeview_item(tptr,TreeMan.pattern)) {
			tptr->state |= _TREE_FOCUS;
			Context.TreeTop = tptr;
			return(1);
			}
		else if (!( tptr->first ))
			continue;
		else if ( detect_treeview_item( tptr->first, nptr ) )
			return(1);
		}
	return(0);
}

private	int	select_TreeViewItem( struct treeview * tptr )
{
	if ( tptr->nature != TREE_ROOT ) {
		if ( tptr->first ) {
			if ( tptr->state & _TREE_OPEN )
				tptr->state &= ~_TREE_OPEN;
			else	tptr->state |=  _TREE_OPEN;
			draw_TreeView();
			}
		}
	return(0);
}

private	int	locate_treeview_item()
{
	struct treeview * tptr;
	if ( accept_treeviewitem(&TreeMan.pattern) != 27 )
		if ( detect_treeview_item( Context.Tree, TreeMan.pattern ) )
			select_TreeViewItem( Context.TreeTop );
	return(0);
}

private	int	select_TreeView( struct treeview * tptr )
{
	int	event;

	/* Perform Event Filtering */
	/* ----------------------- */
	switch ( tptr->nature ) {
		case	TREE_ROOT	:
			if ((event = visual_event(1)) != _MIMO_UP) 
				return(0);
			else	break;
		default			:
			if ((event = visual_event(1)) != _MIMO_DOWN) 
				return(0);
			else	break;
		}

	select_TreeViewItem( tptr );

	switch ( tptr->nature ) {
		case	TREE_ROOT	:
			if ( visual_event(2) == _MIMO_LEFT )
				event = toggle_treeview(); 
			else	event = locate_treeview_item();
			break;
		case	TREE_EVENT	:
			event = select_TreeEvent( tptr->payload ); break;
		case	TREE_WIDGET	:
			event = select_TreeWidget( tptr->payload ); break;
		case	TREE_FORM	:
			event = select_TreeForm( tptr->payload ); 
			break;
		case	TREE_PROJECT	:
			event = select_TreeProject( tptr->payload ); 
			break;
#ifdef	_PROTOTYPE_CLASS
		case	TREE_CLASS	:
			event = select_TreeClass( tptr->payload ); break;
#endif
		case	TREE_IMAGE	:
			event = select_TreeImage( tptr->payload ); break;

		case	TREE_TEXT 	:
			event = select_TreeText( tptr->payload ); break;

		case	TREE_FONT	:
			event = select_TreeFont( tptr->payload ); break;
		case	TREE_MENU	:
#ifdef	_PROTOTYPE_MENUS
			event = select_TreeMenu( tptr->payload ); break;
#endif
		default			:
			event = 0;
			focus_treenode( tptr, _TREE_FOCUS ); break;
		}
	return(event);
}

private	int	use_TreeViewEvent(int x, int y, struct treeview * lptr )
{
	int	status=-1;
	struct	treeview * tptr;
	for (	tptr=lptr;
		tptr != (struct treeview *) 0;
		tptr = tptr->next ) {
		if (( y >= tptr->atrow )
		&&  ( y <= (tptr->atrow + Context.treefontheight)))
			return( select_TreeView( tptr ) );
		else if (!( tptr->state & _TREE_OPEN ))
			continue;
		else if ((status = use_TreeViewEvent(x,y,tptr->first)) != -1)
			break;
		else	continue;
		}
	return(status);

}

public	struct treeview * newlocate_TreeViewWidget(int x, int y, struct treeview * lptr )
{
	if (!( lptr )) return( lptr );

	if  ( y < lptr->atrow ) {
		/* move back up towards the node */
		/* ----------------------------- */
		while (( lptr = lptr->previous) != (struct treeview*) 0) 
			if ( y > lptr->atrow )
				break;
		return( lptr );
		}
	else if (y <= (lptr->atrow + Context.fontheight))
		return( lptr );
	else	{
		while ((lptr = lptr->next) != (struct treeview *) 0)
			if (y <= (lptr->atrow + Context.treefontheight))
				break;
		return( lptr );
		}
}

public	struct treeview * locate_TreeViewWidget(int x, int y, struct treeview * lptr )
{
	int	status=-1;
	struct	treeview * tptr;
	struct	treeview * rptr;
	for (	tptr=lptr;
		tptr != (struct treeview *) 0;
		tptr = tptr->next ) {
		if (( y >= tptr->atrow )
		&&  ( y <= (tptr->atrow + Context.treefontheight)))
			return( tptr );
		else if (!( tptr->state & _TREE_OPEN ))
			continue;
		else if (!(rptr = locate_TreeViewWidget(x,y,tptr->first)))
			continue;
		else	return( rptr );
		}
	return(tptr);

}

private	int	try_TreeViewEvent(int x, int y, struct treeview * lptr )
{
	int	status=-1;
	while ( lptr != (struct treeview *) 0 ) {
		if ((status = use_TreeViewEvent(x,y,lptr)) != -1)
			break;
		else if (!( lptr->parent ))
			break;
		else 	lptr = lptr->parent->next;
		}
	return( status );
}

public	int	TreeViewScrollDown(int n)
{
	struct	treeview * tptr;

	while ( n != 0 ) {

		if (!( tptr = Context.TreeTop ))
			break;
		if ( tptr->first ) {
			if ( tptr->state & _TREE_OPEN ) {
				Context.TreeTop = tptr->first;
				n--;
				continue;
				}
			}
		if ( tptr->next ) {
			Context.TreeTop = tptr->next;
			n--;
			continue;
			}
		while (1) {
			if (!( tptr->parent )) {
				Context.TreeTop =tptr;
				return(n);
				}
			else if (!( tptr->parent->next )) {
				tptr = tptr->parent;
				continue;
				}
			else	{
				Context.TreeTop = tptr->parent->next;
				break;
				}
			}

		}
	draw_TreeView();
	return(n);

}

public	int	TreeViewScrollUp(int n)
{
	struct	treeview * tptr;

	while ( n != 0 ) {

		if (!( tptr = Context.TreeTop ))
			break;

		if ( tptr->previous ) {
			if (( tptr->previous->state & _TREE_OPEN )
		     	&&  ( tptr->previous->last               )) {
				Context.TreeTop = tptr->previous->last;
				n--;
				continue;
				}
			else	{
				Context.TreeTop = tptr->previous;
				n--;
				continue;
				}
			}
		if (!( tptr->parent ))
			break;
		else	{
			Context.TreeTop = tptr->parent;
			n--;
			}
		}

	draw_TreeView();
	return(n);

}

public	int	TreeViewScrollTo(int y, int dy)
{
	if ( y < dy ) 
		return(TreeViewScrollDown((((dy-y)/Context.treefontheight)+1)));
	else	return(TreeViewScrollUp((((y-dy)/Context.treefontheight)+1)));
}


public	int	TreeViewScrollPage(int y, int dy)
{
	unsigned long	lvpo;
	int	vpo;

	if ( y < dy ) 
		return(TreeViewScrollDown((((dy-y)/Context.treefontheight)+1)));
	else	return(TreeViewScrollUp((((y-dy)/Context.treefontheight)+1)));
#ifdef	NOSHIT
	if ( y < dy ) {
		/* scroll down */
		y = (dy - y);
		Context.TSB.sbp += y;
		if ( Context.TSB.sbp > (Context.TSB.rpl-Context.TSB.rps))
			Context.TSB.sbp = (Context.TSB.rpl-Context.TSB.rps);
		}
	else	{
		/* scroll up */
		y = (y - dy);
		if ( Context.TSB.sbp > y )
			Context.TSB.sbp -= y;
		else	Context.TSB.sbp = 0;
		}
	vpo = ((((unsigned long)Context.TSB.sbp)*(Context.TSB.vpl-Context.TSB.vps))/(Context.TSB.rpl-Context.TSB.rps));
	if ( vpo > Context.TreeTop->identity )
		TreeViewScrollDown((vpo - Context.TreeTop->identity));
	else	TreeViewScrollUp((Context.TreeTop->identity-vpo));
#endif
}


public	int	TreeViewScrollEvent(int x,int y)
{
	int	b;
	int	dx;
	int	dy;
	/* nothing to scroll */
	if ((!( Context.TSB.vpl ))  
	||   ( Context.TSB.vps >= Context.TSB.vpl ))
		return(256);

	/* use scroll bar */
	/* -------------- */
	if (visual_event(1) != _MIMO_DOWN) 
		return(0);
	
	Context.TSB.focus=0x0100;
	draw_TreeScroll();
	while (1) {
		if ( visual_getch() == 256) {

			/* ensure within scroll bar zone */
			if ((dy = visual_event(6)) < Context.TreeView.y )
				continue;
			else if (dy > (Context.TreeView.y+Context.TreeView.h))
				continue;

			switch ((b = visual_event(2))) {

				case	_MIMO_RIGHT	:
					switch ( visual_event(1) ) {
						case	_MIMO_DOWN		:
						case	_MIMO_WHILE_DOWN	:
							TreeViewScrollTo(y,dy);
							y = dy;
							continue;
						case	_MIMO_UP		:
							if ( dy < (Context.TreeView.y+Context.TreeView.adjust))
								TreeViewScrollUp(1);
							else if ( dy > (Context.TreeView.y+(Context.TreeView.h-Context.TreeView.adjust)))
								TreeViewScrollDown(1);
							Context.TSB.focus=0;
							draw_TreeScroll();
							return(256);
						default				:
							continue;
						}

				case	_MIMO_WHEELUP	:
					if  ( visual_event(1) == _MIMO_UP ) {
						TreeViewScrollUp(10);
						Context.TSB.focus=0;
						draw_TreeScroll();
						}
					return(256);

				case	_MIMO_WHEELDOWN	:
					if  ( visual_event(1) == _MIMO_UP ) {
						TreeViewScrollDown(10);
						Context.TSB.focus=0;
						draw_TreeScroll();
						}
					return(256);

				case	_MIMO_LEFT	:
					switch ( visual_event(1) ) {
						case	_MIMO_DOWN		:
						case	_MIMO_WHILE_DOWN	:
							TreeViewScrollPage(y,dy);
							y = dy;
							continue;
						case	_MIMO_UP		:
							if ( dy < (Context.TreeView.y+Context.TreeView.adjust))
								TreeViewScrollUp(1);
							else if ( dy > (Context.TreeView.y+(Context.TreeView.h-Context.TreeView.adjust)))
								TreeViewScrollDown(1);
							Context.TSB.focus=0;
							draw_TreeScroll();
							return(256);
						}
				}
			}

		}	

}

public	int	treeview_is_active()
{
	if (!( Context.TreeView.style ))
		return(0);
	else if ( Context.EditView == 2 )
		return(0);
	else	return(1);
}


public	int	is_TreeViewEvent(int x,int y)
{
	if (!( treeview_is_active() ))
		return(-1);

	/* is tree view active */
	/* ------------------- */
	/* is the event outside the tree view zone */
	/* --------------------------------------- */
	else if ((x <  Context.TreeView.x)
	     ||  (y <  Context.TreeView.y)
	     ||  (y >  (Context.TreeView.y+Context.TreeView.h)))
		return(-1);



	/* is the event within the treeview data zone */
	/* ------------------------------------------ */
	else if ( x < (Context.TreeView.x+(Context.TreeView.w-Context.TreeView.adjust))) {

		/* Detect mouse wheel events */
		/* ------------------------- */
		switch ( visual_event(2) ) {

			case	_MIMO_WHEELUP	:
				if  ( visual_event(1) == _MIMO_UP ) {
					TreeViewScrollUp(1);
					Context.TSB.focus=0;
					draw_TreeScroll();
					}
				return(256);

			case	_MIMO_WHEELDOWN	:
				if  ( visual_event(1) == _MIMO_UP ) {
					TreeViewScrollDown(1);
					Context.TSB.focus=0;
					draw_TreeScroll();
					}
				return(256);

			default			:

				return( try_TreeViewEvent( (x-Context.TreeView.x), (y-Context.TreeView.y),Context.TreeTop) );
			}
		}

	/* is the event beyond the drag bar */
	/* --------------------------------- */
	if ( x >= Context.DeskTop.x)
		return( -1 );

	/* is the event in the scroll bar */
	/* ------------------------------ */
	else if ( x < (Context.DeskTop.x - 8)) 
		return( TreeViewScrollEvent(x,y) );

	/* it must be the drag bar */
	/* ----------------------- */
	else	return( resize_TreeView(x,y) );

}

public	void	remove_treenode( struct treeview * tptr )
{
	struct	treeview * wptr;
	struct	treeview * pptr;
	if (!( tptr ))
		return;
	if (!( wptr = tptr->previous )) {
		if ((pptr = tptr->parent) != (struct treeview*) 0) {
			if (!(pptr->first = tptr->next)) {
				pptr->current = pptr->last = tptr->next;
				}
			else	tptr->next->previous = (struct treeview*) 0;
			}
		}		
	else if (!( wptr->next = tptr->next)) {
		if ((pptr = tptr->parent) != (struct treeview*) 0) 
			pptr->last = wptr;
		}
	else	tptr->next->previous = wptr;
	tptr->current = tptr->next = tptr->previous = tptr->parent = (struct treeview*) 0;
	draw_TreeView();
	return;	
}

public int allocate_tree_managers()
{
	struct treeview * tptr;
	if (!( tptr = allocate_for_treeview() )) {
		allocate_failure();
		return(27);
		}
	else	{
		Context.Tree = tptr;
		tptr->nature= TREE_ROOT;
		tptr->state = (_TREE_OPEN | _TREE_LOCK);
		initialise_tree_manager();
		return(0);
		}
}

public int liberate_tree_managers()
{
	terminate_tree_manager();

	if ( Context.Tree ) {
		liberate_for_treeview( Context.Tree );
		Context.Tree = (struct treeview *) 0;
		}
	return(0);

}


public	void	treeview_configuration()
{
	int	c;
	if ((c = guifontsize((Context.treefont=TreeConf.font))) == 0 ) {
		Context.treefont=2;
		Context.treefontwidth	= Context.fontwidth;
		Context.treefontheight  = (Context.fontheight + TreeConf.spacing);
		}
	else	{
		Context.treefontwidth	= (c & 0x00FF);
		Context.treefontheight	= (((c >> 8) & 0x00FF)+TreeConf.spacing);
		}
	Context.TreeView.w = TreeConf.width;
	return;
}


public	int	reconfigure_treeview()
{
	int	status;
	if ((status = treeview_is_active()))
		swap_TreeView();
	treeview_configuration();
	if ((status))
		swap_TreeView();
	return(status);
}

public	int	configure_treeview()
{
	int	c;
	int	status;
	if ( TreeConf.font )
		TreeConf.font--;
	if ( TreeConf.zonage )
		TreeConf.zonage--;

	status = accept_treeview_parameters(
			&TreeConf.font,
			&TreeConf.spacing,
			&TreeConf.zonage,
			&TreeConf.source,
			&TreeConf.target,
			&TreeConf.packaging,
			&TreeConf.identity );
	TreeConf.font++;
	TreeConf.zonage++;
	if ( status == 27 ) {
		return( 27 );
		}
	else	{
		reconfigure_treeview();
		return(13);
		}
}

public	int	treeview_options()
{
	return( (TreeConf.zonage | ( TreeConf.source << 8 ) | ( TreeConf.target << 9 ) | ( TreeConf.packaging << 10 ) | ( TreeConf.identity << 11 )) );
}

public	int	treeview_padding()
{
	return( TreeConf.spacing );
}

#endif /* _singtree_c */


