#include <stdio.h>
#include "sing.h"
#include "palet.h"
#include "stdpsu.h"
#include "guimouse.h"
#include "singrel.h"
#include "singpix.h"
#include "allocate.h"
#define	_SYSTEM_IMAGES
#include "genimage.h"
#include "sysimage.h"
#include "stdimage.h"
#include "singlang.h"

#include "singpal.h"
#include "singbar.h"
#include "singmenu.h"
#include "singtool.h"
#include "singtext.h"
#include "singimg.h"
#include "singdesk.h"
#include "singtree.h"
#include "valign.h"
#include "varrow.h"
#include "visual.h"

extern	char	namebuffer[];
extern	struct	screen_control	Context;
extern	char *	font_name[];
extern	char 	LaPaterne[];
extern	char *	ProjectIcon;
extern	char *	LockIcon;
extern	char *	TextIcon;
extern	char *	ImageIcon;
extern	char *	TreeIcon;
extern	char *	RootIcon;
extern	char *	DownIcon;
extern	char *	UpIcon;
extern	char *	WidgetIcon;
extern	char * 	system_imagepath;
extern	char *	thispalette;
extern	char	workbuffer[1024];

extern	char *	WidgetClass[32];


public	int	get_leftmargin() { return( Context.DeskTop.x ); }
public	int	get_rightmargin() { return( (Context.DeskTop.x+Context.DeskTop.w) ); }
public	int	get_topmargin() { return( Context.DeskTop.y ); }
public	void	reactivate_DeskTop(int mode);

#include "singtool.c"
#include "singmenu.c"

public 	void	reset_scroll( struct scroll_control * sptr )
{
	sptr->vpo = sptr->vps = sptr->vpl =
	sptr->rps = sptr->rpl = 0;
	sptr->rpo = (int *) 0;
	return;
}

public	void	reactivate_DeskTop(int mode)	
{
	if ((Context.DeskTop.style = mode)!=0) {
		if ( Context.DeskTop.style != _SCROLL_FRAME ) {
			Context.ScrollBar.x = 
			Context.ScrollBar.y = 
			Context.ScrollBar.w = 
			Context.ScrollBar.h = 0;
			if ( Context.TreeView.style != 0 ) 
				Context.DeskTop.x = ((Context.TreeView.x+Context.TreeView.w)+1);
			else	Context.DeskTop.x = ((Context.ToolBar.x+Context.ToolBar.w)+1);
			Context.DeskTop.w = inner_width(0)+2;
			Context.DeskTop.y = ((Context.MenuBar.y+Context.MenuBar.h)+1);
			Context.DeskTop.h = inner_height()+2;
			if ( Context.StatusBar.style )
				Context.DeskTop.h--;
			}
		else	{
			Context.ScrollBar.x = 
			Context.ScrollBar.y = 
			Context.ScrollBar.w = 
			Context.ScrollBar.h = 1;
			Context.DeskTop.x = ((Context.ToolBar.x+Context.ToolBar.w)+1);
			Context.DeskTop.w = (inner_width(0) - (Context.fontwidth * 3));
			Context.DeskTop.y = ((Context.MenuBar.y+Context.MenuBar.h));
			Context.DeskTop.h = inner_height();
			if ( Context.StatusBar.style )
				Context.DeskTop.h--;
			}
		}
	else	{
		Context.ScrollBar.x = 
		Context.ScrollBar.y = 
		Context.ScrollBar.w = 
		Context.ScrollBar.h = 
		Context.DeskTop.x = Context.DeskTop.y = 
		Context.DeskTop.w = Context.DeskTop.h = 0;
		}

	reset_scroll( &Context.VSB );
	reset_scroll( &Context.HSB );
 
	return; 
}
public 	void	activate_DeskTop(int mode)	
{
	if (Context.DeskTop.style != mode)
		reactivate_DeskTop(mode);
	return;
}


private	void	draw_Vscroll()
{
	visual_scrollbar(
			(Context.DeskTop.x+Context.DeskTop.w),
			Context.DeskTop.y,
			(Context.fontwidth*3),
			Context.DeskTop.h,
			Context.basefont,0,0, 
			Context.VSB.vpo, /* current scroll item */
			Context.VSB.vps,
			Context.VSB.vpl,  /* total scroll items */
			(Context.VSB.focus | _A_CENTER)
			);
	return;

}

private	void	draw_TreeScroll()
{
	int	options;
	int	i;
	if ((!( Context.TSB.vpl ))  
	||   ( Context.TSB.vps >= Context.TSB.vpl )) {
		i=0;
		}
	else	{
		Context.TSB.rpl = ((Context.TreeView.h-4)-((Context.TreeView.adjust-4)*2));

		if ( Context.TSB.rpl != 0 )
			Context.TSB.rps = ((((unsigned long)Context.TSB.vps)*Context.TSB.rpl)/Context.TSB.vpl);

		if ( (Context.TSB.rpl-Context.TSB.rps) != 0 )
			Context.TSB.sbp = ((((unsigned long)Context.TSB.vpo)*(Context.TSB.rpl-Context.TSB.rps))/(Context.TSB.vpl-Context.TSB.vps));

		visual_scrollbar(
			(Context.TreeView.x+(Context.TreeView.w-Context.TreeView.adjust)+2),
			Context.TreeView.y+2,
			(Context.TreeView.adjust-8),
			(Context.TreeView.h-4),
			Context.basefont,0,0, 
			(Context.TSB.vpo-1), /* current top item    */
			Context.TSB.vps, /* current page items  */
			Context.TSB.vpl, /* total scroll items 	*/
			(Context.TSB.focus | _A_CENTER)
			);
		}

	if ((options = treeview_options()) & 16) {
		visual_element(
			(Context.TreeView.x+(Context.TreeView.w-Context.TreeView.adjust)+2)+(Context.TreeView.adjust-8)-1,
			Context.TreeView.y+1,
			8,
			(Context.TreeView.h-3),
			_STYLE_TREE_BAR," ",0);
		}
	else	{
		visual_frame (
			(Context.TreeView.x+(Context.TreeView.w-Context.TreeView.adjust)+2)+(Context.TreeView.adjust-8)-1,
			Context.TreeView.y+1,
			6,
			(Context.TreeView.h-3),
			_RIDGE_FRAME );
		}
	return;

}

/*
 *	-----------------------------------------------------------------
 *			D E S K T O P   S C R O L L I N G
 *	-----------------------------------------------------------------
 *
 *	The desktop offers a comprehensive but complicated scrolling 
 *	mechanism comprising many functions with the following relationships.
 *
 *	-----------------------------------------------------------------
 *
 *  1->	singdesk.IS_DESKTOP_EVENT
 *		 |
 *		\|/
 *		 |
 *	singdesk.X_SCROLL(loop)
 *		 |
 *		\|/
 *		 |
 *	singform.SHOW_FORM   ---->---->		singdesk.DESKTOP_X_SCROLL
 *		 |		 |			 |	
 *	       	/|\		\|/			\|/
 *		 |		 |			 |
 *  2->	singform.DRAW_FORM	 |		singdesk.CALCULATE_XSCROLL
 *				 |			 |	
 *			singdesk.DRAW_SCROLLBARS	\|/
 *				 |			 |
 *				\|/			 |
 *		 draw_Hscroll <-----> draw_Vscroll	calculate_virtual_scroll
 *
 *	-----------------------------------------------------------------
 *
 *	The respective scroll bars will be activated when their need is
 *	detected by the form drawing/showing mechanims ( entry 2 above).
 *
 *	-----------------------------------------------------------------
 *
 *	When a bar is active mouse down events occuring over the scroll
 *	bar will activate the corresponding scroll bar driver responsible
 *	for repositioning and redisplay ( entry 1 above ).
 *	
 *	-----------------------------------------------------------------
 */



private	void	draw_Hscroll()
{
		visual_scrollbar( 
			Context.DeskTop.x,
			(Context.DeskTop.y+Context.DeskTop.h),
			Context.DeskTop.w,
			Context.fontheight+(Context.fontheight/2),
			Context.basefont,0,0, 
			Context.HSB.vpo, /* current scroll item */
			Context.HSB.vps,
			Context.HSB.vpl,  /* total scroll items */
			(Context.HSB.focus | _A_CENTER)
			);
	return;
}

public	void	draw_desktop_scroll()
{
	if ( Context.VSB.rpl != 0 )
		draw_Vscroll();
	if ( Context.HSB.rpl != 0 )
		draw_Hscroll();
	return;
}

private	void	calculate_virtual_scroll( struct scroll_control * sptr )
{
	/* 
	 * virtual page size 	/ virtual page limit 
	 *			= 
	 * real page size	/ real page limit 	
	 */

	sptr->vps = ((((unsigned long)sptr->rps)*sptr->vpl)/sptr->rpl);

	/*
 	 * virtual page offset 	/ virtual page limit 
	 *			=
	 *  real page offset	/ real page limit		
	 */
	
	if (!( sptr->rpo ))
		sptr->vpo = 0;
	else if (!( *sptr->rpo ))
		sptr->vpo = 0;
	else 	sptr->vpo = ((((unsigned long)*sptr->rpo) * sptr->vpl)/sptr->rpl);

	/* limit to reasonable available value */

	if (( sptr->vpo +  sptr->vps) > sptr->vpl )
		sptr->vpo = (sptr->vpl - sptr->vps);

	return;
}

private	void	calculate_Hscroll(int * offset, int limit )
{
	Context.HSB.rpo = offset;
	Context.HSB.rps = Context.DeskTop.w;
	Context.HSB.rpl = limit;
	Context.HSB.vpl = Context.DeskTop.w-4;
	calculate_virtual_scroll( &Context.HSB );
	return;
}

private	void	calculate_Vscroll(int * offset, int limit )
{
	Context.VSB.rpo = offset;
	Context.VSB.rpl = limit;
	Context.VSB.rps = Context.DeskTop.h;
	Context.VSB.vpl = (Context.DeskTop.h-4);
	calculate_virtual_scroll( &Context.VSB );
	return;
}


public	int	desktop_Hscroll(int * offset, int limit )
{
	if (!( Context.HSB.rpl )) {
		/* activate horizontal scroll bar */
		if ( limit != 0 ) {
			calculate_Hscroll( offset, limit );
			Context.DeskTop.h -= (Context.fontheight+(Context.fontheight/2));
			}
		}
	else if (!( limit )) {
		/* Disactivate existing horizontal scroll bar */
		reset_scroll(&Context.HSB);
		Context.DeskTop.h += (Context.fontheight+(Context.fontheight/2));
		}
	else	{
		calculate_Hscroll( offset, limit );
		}
	if (Context.VSB.rpl)
		calculate_Vscroll(Context.VSB.rpo,Context.VSB.rpl);
	return(0);
}

public	int	desktop_Vscroll(int * offset, int limit )
{
	if (!( Context.VSB.rpl )) {
		/* activate vertical scroll bar */
		if ( limit != 0 ) {
			calculate_Vscroll( offset, limit );
			Context.DeskTop.w -= (Context.fontwidth*3);
			}
		}
	else if (!( offset )) {
		/* Disactivate existing vertical scroll bar */
		reset_scroll(&Context.VSB);
		Context.DeskTop.w += (Context.fontwidth*3);
		}
	else	{
		calculate_Vscroll( offset, limit );
		}
	if (Context.HSB.rpl)
		calculate_Hscroll(Context.HSB.rpo,Context.HSB.rpl);
	return(0);
}

public	void	use_background_colour( int v )
{

	Context.background=v;
	get_rgb_values(Context.background,&Context.bgrgb[0],&Context.bgrgb[1],&Context.bgrgb[2]); 

	if ((!( Context.Form 		))
	&&  (!( Context.Menu 		))
	&&  (!( Context.Class  		))
	&&  (!( Context.Zoom 		))
	&&  (!( Context.FontContext 	)))	
		background_Camera(Context.Camera, v );

	return;

}

public	void	use_foreground_colour( int v )
{
	Context.foreground=v;
	get_rgb_values(Context.foreground,&Context.fgrgb[0],&Context.fgrgb[1],&Context.fgrgb[2]); 
	return;
}

#include "singmod.c"

public	void	show_DeskTop()
{
	/* Draw Desktop WorkArea Frame */
	/* --------------------------- */
	if ((!(Context.usestyle))
	||  ( visual_element(
			Context.DeskTop.x,Context.DeskTop.y,
			Context.DeskTop.w-1,Context.DeskTop.h,
			_STYLE_DESKTOP_FRAME, " ",0) )) {
		filzone	(Context.DeskTop.x,Context.DeskTop.y,
			Context.DeskTop.w+1,Context.DeskTop.h+1,_DEFAULT_GUI_NEUTRAL);
		}
	if ( Context.DeskTop.style == _SCROLL_FRAME ) {
		visual_scrollbar(
			(Context.DeskTop.x+Context.DeskTop.w),
			Context.DeskTop.y,
			(Context.fontwidth*3),
			Context.DeskTop.h,
			Context.basefont,0,0, 
			Context.ScrollBar.y, /* current scroll item */
			(Context.DeskTop.h / Context.fontheight), 
			Context.ScrollBar.h,  /* total scroll items */
			0
			);
		}
	else 	{
		draw_desktop_scroll();
		}
	return;
}

public 	void	draw_DeskTop()	
{ 
	struct form_item * iptr;
	int	pas;

	hide();

	show_DeskTop();

	/* The New Way of doing it */
	/* ----------------------- */
	if ( Context.ModelHeap )
		Context.ModelHeap->onshow(Context.ModelHeap,0);

	else if (( Context.DataView ) && ( Context.DataView < 4)) {
		switch ( Context.DataView ) {
			case	1 : databaseEditorShow(); break;
			case	2 : flowchartEditorShow(); break;
			case	3 : dependanceEditorShow(); break;
			}
		}
	else if ( Context.EditView )
		editorOnShow();

	/* All the old dudes */
	/* ----------------- */
	else if ( Context.Zoom )
		refresh_ZoomWindow();

	else if ( Context.FontContext )	
		refresh_FontContext();

	else if ( Context.Form )
		draw_Form(Context.Form,1);

#ifdef	_PROTOTYPE_CLASS
	else if ( Context.Class )
		draw_Class(Context.Class);
#endif

#ifdef	_PROTOTYPE_MENUS
	else if ( Context.Menu )
		draw_Menu(Context.Menu);
#endif

	else if ( Context.Camera )
		draw_Camera(Context.Camera);


	/* Commit Image to output */
	/* ---------------------- */
	show (	Context.DeskTop.x,Context.DeskTop.y,
		Context.DeskTop.w,Context.DeskTop.h );

	return;
}

public 	void	select_current(int x, int y)
{
	struct form_item * iptr;

	if (!( Context.Form ))
		return;

	for (iptr=Context.Form->first; iptr != (struct form_item *) 0; iptr = iptr->next ) {
		if ( iptr->Contents.style == _LINE_FRAME ) {
			if ((x == iptr->Contents.x )
			&&  (y == iptr->Contents.y )) {
				Context.Form->current = iptr;
				break;
				}
			else if ((x == iptr->Contents.w )
			     &&  (y == iptr->Contents.h )) {
				Context.Form->current = iptr;
				break;
				}
			}
		else	{
			if ((x >= iptr->Contents.x )
			&&  (y >= iptr->Contents.y )
			&&  (x < (iptr->Contents.x+Context.fontwidth))
			&&  (y < (iptr->Contents.y+Context.fontheight))) {
				Context.Form->current = iptr;
				break;
				}
			if ((x <= iptr->Contents.w 		    )
			&&  (y <= iptr->Contents.h 		    )
			&&  ( iptr->Contents.w > Context.fontwidth  )
			&&  ( iptr->Contents.h > Context.fontheight )
			&&  (x > (iptr->Contents.w-Context.fontwidth))
			&&  (y > (iptr->Contents.h-Context.fontheight))) {
				Context.Form->current = iptr;
				break;
				}
			}
		}	
	return;
}

public	int	is_ConsoleEvent(int x, int y )
{
	int	t;
	int	b;

	return(  ((y / Context.fontheight)+1) );
}

public	int	console_Message( int atx, int aty, int state, char * message, int mlen, int indent )
{
	int	fg;
	int	bg;
	int	zw;
	int	ff;
	if (( atx < 0 )
	||  ( aty < 0 )
	||  ( atx > Context.DeskTop.w )
	||  ( aty > Context.DeskTop.h ))
		return(0);
	else if (!( message ))
		return(0);

	if ( Context.fontheight )
		ff = ((aty/Context.fontheight)&1);

	if ( state & 2 ) {
		fg = standard_text;
		bg = standard_title;
		}
	else if (!( state & 1 )) {
		fg = standard_title;
		if ( ff )
			bg = standard_backwash;
		else	bg = standard_himid;
		}
	else	{ /* state & 1 */
		fg = standard_black;
		if ( ff )
			bg = standard_backwash;
		else	bg = standard_himid;
		}

	filzone( Context.DeskTop.x+atx, Context.DeskTop.y+aty,
		(zw = (Context.DeskTop.w-atx)),Context.fontheight, bg);

	if (!( message ))
		return(0);
	else if (!( mlen    ))
		return(0);

	if ((mlen * Context.fontwidth) > zw)
		mlen = (zw / Context.fontwidth);

	cicocolour(fg,bg);

	PixelFontLat(	Context.DeskTop.x+atx, Context.DeskTop.y+aty,1,
			message,mlen );

	return(Context.fontheight);
}
		
		
public	int	treeview_Message( int atx, int aty,char * message, int mlen, int iconid , int state, int indent )
{
	int	treefont=0;
	int	padding;
	int	gmlen;
	int	a=0;
	int	adjust=0;
	int	fg;
	int	bg;
	int	zw;
	int	ff;
	int	nby;
	int	mmlen=0;
	int	options=0;
	int	backwash=standard_backwash;
	if (!( Context.TreeView.style ))
		return(Context.treefontheight);
	if (!( nby = Context.TreeView.w ))
		return(Context.treefontheight);
	if ( nby < Context.TreeView.adjust)
		return(Context.treefontheight);
	else	nby -= Context.TreeView.adjust;

	if (( atx < 0 )
	||  ( aty < 0 )
	||  ( atx > nby )
	||  ( aty > Context.TreeView.h ))
		return(0);
	else if (!( message ))
		return(0);

	atx += 2; aty += 2;

	options = treeview_options();

	if ( options & 16 ) {
		/* activetool style */
		backwash = 0;
		ff = 1;
		}
	else if (!( options & 1)) {
		ff = 1;
		backwash=standard_white;
		}
	else if ( Context.treefontheight )
		ff = ((aty/Context.treefontheight)&1);
	else	ff =0;

	if ( state & 2 ) {
		fg = standard_white;
		if ( options & 16 ) {
			bg = 0;
			}
		else	{
			bg = standard_title;
			}
		}
	else if (!( state & 1 )) {
		fg = standard_text;
		if ( ff )
			bg = backwash;
		else	bg = standard_himid;
		}
	else	{ /* state & 1 */
		fg = standard_black;
		if ( ff )
			bg = backwash;
		else	bg = standard_himid;
		}

	hide();
	zw = (nby-atx);
	if ( bg ) {
		filzone( Context.TreeView.x+atx, Context.TreeView.y+aty,
			zw,Context.treefontheight, bg);
		}

	if ((padding = treeview_padding()) != 0)
		padding /= 2;

	switch ( iconid ) {

		case	TREE_ROOT	:
			if ( RootIcon ) {
				if ( bg ) {
					filzone( Context.TreeView.x+atx, Context.TreeView.y+aty+padding,
						20,Context.fontheight, bg /* standard_backwash */);
					}
				mixzone(Context.TreeView.x+atx,Context.TreeView.y+aty+padding,Context.Tool.w,Context.fontheight,RootIcon);
				adjust = 20;
				}
			break;
		case	TREE_PROJECT	:
			if (!( state & _TREE_QUOI )) {
				if ( LockIcon ) {
					if ( bg ) {
						filzone( Context.TreeView.x+atx, Context.TreeView.y+aty+padding,
							20,Context.fontheight,  bg /* standard_backwash */);
						}
					mixzone(Context.TreeView.x+atx,Context.TreeView.y+aty+padding,Context.Tool.w,Context.fontheight,LockIcon);
					adjust = 20;
					}
				}
			else	adjust=0;
			if ( ProjectIcon ) {
				if ( bg ) {
					filzone( Context.TreeView.x+atx+adjust, Context.TreeView.y+aty+padding,
						20,Context.fontheight,  bg /* standard_backwash */);
					}
				mixzone(Context.TreeView.x+atx+adjust,Context.TreeView.y+aty+padding,Context.Tool.w,Context.fontheight,ProjectIcon);
				adjust += 20;
				}
			break;

		case	TREE_TEXT	:
			if (!( state & _TREE_QUOI )) {
				if ( LockIcon ) {
					if ( bg ) {
						filzone( Context.TreeView.x+atx, Context.TreeView.y+aty+padding,
							20,Context.fontheight,  bg /* standard_backwash */);
						}
					mixzone(Context.TreeView.x+atx,Context.TreeView.y+aty+padding,Context.Tool.w,Context.fontheight,LockIcon);
					adjust = 20;
					}
				}
			else	adjust=0;
			if ( TextIcon ) {
				if ( bg ) {
					filzone( Context.TreeView.x+atx+adjust, Context.TreeView.y+aty+padding,
						20,Context.fontheight,  bg /* standard_backwash */);
					}
				mixzone(Context.TreeView.x+atx+adjust,Context.TreeView.y+aty+padding,Context.Tool.w,Context.fontheight,TextIcon);
				adjust += 20;
				}
			break;

		case	TREE_IMAGE	:
			if (!( state & _TREE_QUOI )) {
				if ( LockIcon ) {
					if ( bg ) {
						filzone( Context.TreeView.x+atx, Context.TreeView.y+aty+padding,
							20,Context.fontheight,  bg /* standard_backwash */);
						}
					mixzone(Context.TreeView.x+atx,Context.TreeView.y+aty+padding,Context.Tool.w,Context.fontheight,LockIcon);
					adjust = 20;
					}
				}
			else	adjust=0;
			if ( ImageIcon ) {
				if ( bg ) {
					filzone( Context.TreeView.x+atx+adjust, Context.TreeView.y+aty+padding,
						20,Context.fontheight,  bg /* standard_backwash */);
					}
				mixzone(Context.TreeView.x+atx+adjust,Context.TreeView.y+aty+padding,Context.Tool.w,Context.fontheight,ImageIcon);
				adjust += 20;
				}
			break;

		case	TREE_FORM   	:
			if (!( state & _TREE_QUOI )) {
				if ( LockIcon ) { 
					if ( bg ) {
						filzone( Context.TreeView.x+atx, Context.TreeView.y+aty+padding,
							20,Context.fontheight,  bg /* standard_backwash */);
						}
					mixzone(Context.TreeView.x+atx,Context.TreeView.y+aty+padding,Context.Tool.w,Context.fontheight,LockIcon);
					adjust = 20;
					}
				}
			else	adjust=0;
			if ( TreeIcon ) {
				if ( bg ) {
					filzone( Context.TreeView.x+atx+adjust, Context.TreeView.y+aty+padding,
						20,Context.fontheight,  bg /* standard_backwash */);
					}
				mixzone(Context.TreeView.x+atx+adjust,Context.TreeView.y+aty+padding,Context.Tool.w,Context.fontheight,TreeIcon);
				adjust += 20;
				}
			break;

		case	TREE_WIDGET 	:
			if ( bg ) {
				filzone( Context.TreeView.x+atx, Context.TreeView.y+aty+padding,
					20,Context.fontheight,  bg /* standard_backwash */);
				}
			if ( state & _TREE_WHAT )
				filzone( Context.TreeView.x+atx+5, Context.TreeView.y+aty,
					1,Context.treefontheight+(padding*2)+4,  standard_black );
			else	filzone( Context.TreeView.x+atx+5, Context.TreeView.y+aty,
					1,(Context.treefontheight/2)+padding,  standard_black );
			filzone( Context.TreeView.x+atx+5, Context.TreeView.y+aty+(Context.treefontheight/2)+padding,
				15,1,  standard_black );
				
			adjust = 20;
			break;

		}

	if ((!( message ))
	||  (!( mlen    ))) {
		show( Context.TreeView.x+atx, Context.TreeView.y+aty,zw,Context.fontheight);
		return(0);
		}

	else if (!( zw - adjust )) {
		show( Context.TreeView.x+atx, Context.TreeView.y+aty,zw,Context.fontheight);
		return(0);
		}

	if ( options & 16 ) {
		if ( state & 2 ) {
			if (!( treefont = resolve_style_font( "treeview_focus" )))
				treefont = Context.treefont;
			}
		else if (!( treefont = resolve_style_font( "treeview_label" )))
			treefont = Context.treefont;
		}
	else	treefont = Context.treefont;

	while (( gmlen = textsizelen( treefont, message, mlen )) > (zw - adjust )) {
		mmlen = ( mlen-1 );
		if ( iconid != TREE_WIDGET )
			message += (mlen - mmlen);
		if (!(mlen = mmlen)) {
			show( Context.TreeView.x+atx, Context.TreeView.y+aty,zw,Context.fontheight);
			return(0);
			}
		}

	if ( options & 16 ) {

		if ( state & 2 ) {
			visual_element(
				Context.TreeView.x+atx+adjust-4, 
				Context.TreeView.y+aty,
				(zw-adjust),Context.treefontheight,
				_STYLE_TREE_FOCUS,message,mlen);
			}
		else	{
			visual_element(
				Context.TreeView.x+atx+adjust-4, 
				Context.TreeView.y+aty,
				(zw-adjust),Context.treefontheight,
				_STYLE_TREE_LABEL,message,mlen);
			}

		}
	else	{

		cicocolour(fg,bg);

		if ( adjust > 4 ) {
			if ( bg ) {
				filzone( Context.TreeView.x+atx+adjust-4, Context.TreeView.y+aty,(zw-adjust),Context.treefontheight,bg);
				}
			}
		if ( state & _A_BOLD ) { a = cicoatribut(_PIXELCO_BOLD); }


		PixelFontLat(	Context.TreeView.x+atx+adjust, Context.TreeView.y+aty+padding,Context.treefont,
				message,mlen );

		if ( state & _A_BOLD ) { a = cicoatribut( a ); }

		}
	show( Context.TreeView.x+atx, Context.TreeView.y+aty,zw,Context.treefontheight);

	return(Context.treefontheight);
}
		
/*	
 *	V E R T I C A L _ S C R O L L 
 *	-----------------------------
 *	event driven operation of the desk top vertical scroll bar
 *	currently deicated to the forms editor.
 *
 */

private	int	vertical_scroll( struct scroll_control * sptr)
{
	int	aty;
	int	toy;
	if ( visual_event(1) == _MIMO_DOWN ) {
		aty = visual_event(6);
		sptr->focus = 0x0100;
		draw_Vscroll();
		do	{
			while ( visual_getch() != 256 );
			if ((toy = visual_event(6)) > aty ) {
				*sptr->rpo += (toy - aty);
				if ( *sptr->rpo > (sptr->rpl - sptr->rps))
					*sptr->rpo = (sptr->rpl - sptr->rps);

				}
			else if ( (aty - toy) <= *sptr->rpo )
				*sptr->rpo -= (aty-toy);
			else	*sptr->rpo = 0;
			show_Form(Context.Form,1);
			aty = toy;
			}
		while ( visual_event(1) != _MIMO_UP );
		sptr->focus = 0;
		draw_Vscroll();
		}
	return(256);
}

/*	
 *	H O R I Z O N T A L _ S C R O L L 
 *	---------------------------------
 *	event driven operation of the desk top horizontal scroll bar
 *	currently deicated to the forms editor.
 *
 */

private	int	horizontal_scroll( struct scroll_control * sptr)
{
	int	atx;
	int	tox;
	if ( visual_event(1) == _MIMO_DOWN ) {
		atx = visual_event(7);
		sptr->focus = 0x0100;
		draw_Hscroll();
		do	{
			while ( visual_getch() != 256 );
			if ((tox = visual_event(7)) > atx ) {
				*sptr->rpo += (tox - atx);
				if ( *sptr->rpo > (sptr->rpl - sptr->rps))
					*sptr->rpo = (sptr->rpl - sptr->rps);
				}
			else if ( (atx - tox) <= *sptr->rpo )
				*sptr->rpo -= (atx-tox);
			else	*sptr->rpo = 0;
			show_Form(Context.Form,1);
			atx = tox;
			}
		while ( visual_event(1) != _MIMO_UP );
		sptr->focus = 0;
		draw_Hscroll();
		}
	return(256);
}

/*
 *	I S _ D E S K T O P _ E V E N T 
 *	-------------------------------
 *	Desktop event manager
 *
 */

public 	int	is_DeskTopEvent(int x, int y )
{
	int	t;
	int	b;

	if (( x > Context.DeskTop.x ) 
	&&  ( y > Context.DeskTop.y )
	&&  ( x < (Context.DeskTop.x+Context.DeskTop.w)) 
	&&  ( y < (Context.DeskTop.y+Context.DeskTop.h))) {

		if ( Context.EditView == 1 ) {
			editorOnLoseFocus();
			editorOnUseEvent(256);
			editorOnGetFocus();
			return(256);
			}
		else if ( Context.EditView == 2 ) {
			/* return(257); */
			editorOnLoseFocus();
			editorOnUseEvent(256);
			editorOnGetFocus();
			return(256);
			}
		else if ( Context.Form ) {
			x -= Context.DeskTop.x;
			y -= Context.DeskTop.y;
			return( is_FormEvent( Context.Form, x, y ) );
			}
#ifdef	_PROTOTYPE_CLASS
		else if ( Context.Class ) {
			x -= Context.DeskTop.x; 
			y -= Context.DeskTop.y;
			return( is_ClassEvent( Context.Class, x, y ) );
			}
#endif
		else if ( Context.Camera )
			return( is_CameraEvent(Context.Camera, x,y ) );

		}
	else	{
		if ( Context.VSB.rpl != 0 ) {
			if  (( x >= (Context.DeskTop.x+Context.DeskTop.w)) 
			&&   ( x <  (Context.DeskTop.x+Context.DeskTop.w+(Context.fontwidth*2))) 
			&&   ( y >= Context.DeskTop.y )
			&&   ( y <  (Context.DeskTop.y+Context.DeskTop.h))) {
				return( vertical_scroll(&Context.VSB) );
				}
			}
		if ( Context.HSB.rpl != 0 ) {
			if  (( y >= (Context.DeskTop.y+Context.DeskTop.h)) 
			&&   ( y <  (Context.DeskTop.y+Context.DeskTop.h+Context.fontheight)) 
			&&   ( x >= Context.DeskTop.x )
			&&   ( x <  (Context.DeskTop.x+Context.DeskTop.w))) {
				return( horizontal_scroll(&Context.HSB) );
				}
			}
		}
	return(-1);
}

public 	void	drop_DeskTop()
{
	if ( Context.Form )
		Context.Form = liberate_Form( Context.Form );
	if ( Context.Widgets )
		drop_form_clipboard();
	if ( Context.gridbuffer != (char *) 0 )
		Context.gridbuffer = liberate( Context.gridbuffer );
	drop_MenuBar();
	return;
}

/* #include "genimage.c" */

private	char *	PathSelection=(char *) 0;

public	char *	GetPathSelection()
{
	if (!( PathSelection ))
		return( "\0");
	else	return( PathSelection );
}

public	void	SetPathSelection( char * sptr )
{
	if ( PathSelection )
		PathSelection = liberate( PathSelection );
	if (!( sptr ))
		return;
	if (!( PathSelection = allocate( strlen(sptr) + 16 ) ))
		return;
	else	{
		sprintf(PathSelection,"|%s",sptr);
#ifndef	WIN32
		for ( sptr=PathSelection; *sptr != 0; sptr++ )
			if ( *sptr == ':' )
				*sptr = '|';
#endif
		return;
		}
}

public	char * UsePathSelection( char * sptr, int item )
{
	int	i;
	int	n;
	int	c;
	char *	pptr;
	char *	rptr;
	if (!( pptr = PathSelection ))
		return( sptr );
	if ( item > 0 ) {
		n=0; i=0;
		while ( *(pptr+i) != 0 ) {
			if ( n >= item )
				break;
			else if (( *(pptr+i) == '|' ) 
#ifdef WIN32
				) {
#else
			     ||  ( *(pptr+i) == ':' )){
#endif
				pptr += (i+1);
				i=0;
				n++;
				}
			else	i++;
			}
		}
	for (i=0; *(pptr+i) != 0; i++ ) {
		if ( *(pptr+i) == '|' )
			break;
#ifndef	WIN32
		else if ( *(pptr+i) == ':' )
			break;
#endif
		}
	if (!( i ))
		return( sptr );
	
	c = *(pptr+i);
	*(pptr+i) = 0;
	rptr = relative_filename( sptr, pptr );
	*(pptr+i) = c;
	return( rptr );
}


public 	void	image_save( char * nptr, struct standard_image * iptr, int mode )
{
	int	r;
	char *	rptr;
	char *	tempname;
	char *	get_vga_palette();
	if ((!( nptr ))
	||  (!( iptr )))
		return;

	if ((!( iptr->columns ))
	||  (!( iptr->rows    )))
		return;

	if (!(tempname = allocate_string( nptr ) ))
		return;

	SetPathSelection( system_imagepath );

	if ( mode != QUICK ) {
		if ( accept_imagesave( &tempname, &Context.imagepathitem, &Context.imageformat, &Context.transparent ) == 27 ) {
			tempname = liberate( tempname );
			return;
			}
		else if (!( tempname = UsePathSelection( tempname, Context.imagepathitem ) ))
			return;
		}

	status_message(tempname,3);
	image_configuration(x_conf(70),x_conf(67),get_vga_palette());
	x_event(35);
	if (!( image_write( tempname, iptr,Context.imageformat, Context.transparent ) )) 
		image_creation_failure( tempname );

	x_event(34);
	tempname = liberate( tempname );
	return;

}


public 	int	load_DeskTop( char * nptr,int reset, int automatic )
{
	if (!( Context.Form = load_Form((struct form_control *) 0, nptr, reset, automatic) ))
		return(0);
	else	return(1);
}

public 	int 	export_DeskTop( char * nptr,int mode )
{
	check_Form(Context.Form);
	return( export_Form(Context.Form,mode) );
}

public 	void	image_DeskTop( char * nptr, int automatic )
{
	struct form_item * iptr;
	char	*	buffer;
	int		r;
	int		holder;
	char    *	tempname;

	if ((!( Context.Image.width  ))
	||  (!( Context.Image.height )))
		return;

	if (!( nptr ))
		nptr = "new";

	if (!( nptr = allocate_string( nptr )))
		return;

	switch ( Context.imageformat ) {
		case	_GENERATE_BMP 	:
			if (!( nptr = enforce_extension( nptr, BMP_EXTENSION )))
				return;
			else	break;
		case	_GENERATE_GIF 	:
			if (!( nptr = enforce_extension( nptr, GIF_EXTENSION )))
				return;
			else	break;
		case	_GENERATE_JPG 	:
			if (!( nptr = enforce_extension( nptr, JPG_EXTENSION )))
				return;
			else	break;
		}

	if (!( tempname = nptr ))
		return;

	if (!( Context.Image.state )) {
		strcpy(namebuffer,"specify image zone");
		status_message(namebuffer,3);
		liberate( tempname );
		return;
		}


	if (!( automatic & _INHIBIT_PROPERTIES )) {
		if ( accept_imageload( & tempname ) == 27 ) {
			tempname = liberate( tempname );
			return;
			}
		else	status_message(tempname,3);
		}

	if ((buffer = allocate(Context.Image.width)) != (char *) 0) {
		if ( image_create(tempname,Context.Image.width,Context.Image.height,Context.Image.depth,Context.imageformat,Context.transparent ) != 0 ) {
			if ((holder = Context.gridlockw) != 0) {
				Context.gridlockw = 0;
				Context.gridlockh = 0;
				draw_DeskTop();
				}
			if ( Context.imageformat == _GENERATE_BMP ) {
				for (	r=Context.Image.height; r != 0; r-- ) {
					getzone(Context.DeskTop.x+Context.Image.x,
						(Context.DeskTop.y+Context.Image.y+(r-1)),
						Context.Image.width,1,buffer);
					image_row((r-1),buffer, Context.Image.width,Context.imageformat );
					}
				}
			else	{
				for (	r=0; r < Context.Image.height; r++ ) {
					getzone(Context.DeskTop.x+Context.Image.x,
						(Context.DeskTop.y+Context.Image.y+r),
						Context.Image.width,1,buffer);
					image_row(r,buffer, Context.Image.width,Context.imageformat );
					}


				}
			image_close(Context.imageformat);
			if ((Context.gridlockw = holder) != 0) {
				Context.gridlockh = Context.gridheight;
				draw_DeskTop();
				}
			}
		buffer = liberate(buffer);
		}

	tempname = liberate( tempname );
	status_message(" ",3);
	return;

}

#include "singdbed.c"

#include "singtree.c"


