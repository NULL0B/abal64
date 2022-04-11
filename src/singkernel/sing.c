
#include <stdio.h>
#include "sing.h"
#include "palet.h"
#include "stdpsu.h"
#include "rtbda.c"

#ifndef WIN32
#include "zalloc.c"
#endif

#include "singpix.h"
#include "singprot.h"
#include "singrel.c"
#include "vconf.h"
#include "genimage.h"
#include "singedit.h"
#define	_SYSTEM_IMAGES
#include "sysimage.h"
#include "stdimage.h"

#ifdef	UNIX
#define	_NO_PANIC
#include "cico.c"

public  int	verbose=0;
#else
#include "console.c"
#include "fnparser.c" 
#endif
#include "singfind.c"

public	char	workbuffer[1024];

#ifdef	WIN32
#include "vmouse.c"
#else
#include "mouse.c"
#endif

public	int	texting=0;
public 	char	namebuffer[1024];
public	int	SystemD=0;
private	char *	singconfigname="sing";

extern	char *	font_name[];
extern	char *	_default_font_name[];

public	struct	screen_control	Context;

public	unsigned long MinusOne=-1;

#include "singlang.h"

#include "singpal.h"
#include "singbar.h"
#include "singedit.h"
#include "singmenu.h"
#include "singtool.h"
#include "singtext.h"
#include "singimg.h"
#include "singdesk.h"
#include "singprod.h"

#include "singconf.c"

public 	void	show_form_cursor(int o);
public 	void	hide_form_cursor(int o);
public 	void	show_mouse_position(int x,int y);
public 	void	calculate_cursor( struct window_control * wptr );

private	char *	xworkbuffer=(char *) 0;
public	char *	classbuffer=(char *) 0;

public	char *	check_payload( char * sptr )
{
	if (!( sptr ))
		return(" ");
	else	return(sptr);
}

int	check_class_buffer()
{
	if ((!( classbuffer ))
	&&  (!( classbuffer = allocate( 8192 ))))
		return(0);
	else	{
		*classbuffer = 0;
		return(1);
		}
}

void	output_string(char * sptr)
{
	if ( sptr )
		strcat( classbuffer, sptr);
	return;
}

void	output_int( int v )
{
	char	buffer[16];
	sprintf(buffer,"%u",v);
	output_string( buffer );
	return;
}

public	int	is_blank( char * sptr )
{
	if (!( sptr  ))
		return(1);
	else if (!( *sptr ))
		return(1);
	else	return(0);
}

public	int	not_blank( char * sptr )
{
	if ( is_blank(sptr) )
		return(0);
	else	return(1);
}

public	char * 	enforce_extension( char * nptr, char * xptr )
{
	if (!( xworkbuffer ))
		if (!(xworkbuffer = allocate( 513 )))
			return(xworkbuffer);

	(void) fn_parser( nptr, xworkbuffer, 0x000F );
	liberate( nptr );
	strcat( xworkbuffer, xptr );
	return( allocate_string( xworkbuffer ) );
}

public	char * 	verify_extension( char * nptr, char * xptr )
{
	if (!( xworkbuffer ))
		if (!(xworkbuffer = allocate( 513 )))
			return(xworkbuffer);

	if ( fn_parser( nptr, xworkbuffer, 0x0010 ) != 0)
		return( nptr );
	else	return( enforce_extension( nptr, xptr ) );
}

public	int	detect_extension( char * nptr, char * xptr )
{
	if (!( xworkbuffer ))
		if (!(xworkbuffer = allocate( 513 )))
			return(xworkbuffer);

	if (!( fn_parser( nptr, xworkbuffer, 0x0010 ) ))
		return( 0 );
	else if ( string_compare( xworkbuffer, xptr ) )
		return( 1 );
	else	return( 0 );

}

public	char *	path_prefix( char * filename, char * filepath )
{
	char *	result;
	if (!( filename ))
		return( filename );
	else if (!( filepath ))
		return( filename );
	else if (!( result = allocate( strlen(filename) + strlen( filepath ) + 8 ) ))
		return( filename );
	else	{
#ifdef	UNIX
		sprintf( result, "%s/%s",filepath,filename);		
#endif
#ifdef	WIN32
		sprintf( result, "%s\\%s",filepath,filename);		
#endif
#ifdef	PROLOGUE
		sprintf( result, "%s\\%s",filepath,filename);		
#endif
		liberate( filename );
		return( result );
		}
}

public	char *	relative_filename( char * filename, char * filepath )
{
	int	nlen;
	char *	tempname=(char *) 0;
	if (!( xworkbuffer ))
		if (!(xworkbuffer = allocate( 513 )))
			return(xworkbuffer);

	if (!( filename ))
		return((char *) 0);
	else if ( fn_parser( filename, xworkbuffer, 0x0007 ) != 0 )
		return( allocate_string( filename ) );
	else if (!( filepath ))
		return( allocate_string( filename ) );
	nlen = strlen(filepath);
	nlen += strlen( filename );
	if (!( tempname = allocate( nlen + 16 ) ))
		return(tempname);
	else	{
		sprintf(tempname,"%s%s",filepath,filename);
		return( tempname );
		}
}



public	void	transfer( char * rptr, int rlen, char * sptr, int slen )
{
	int	i;
	for ( i=0; i < slen; i++ ) {
		if ( i < rlen ) 
			*(rptr+i) = *(sptr+i);
		else	break;
		}
	for ( ; i < rlen; i++ )
		*(rptr+i) = ' ';
	return;
}

public	void	fntransfer( char * rptr, int rlen, char * pptr, int plen , char * sptr, int slen )
{
	int	i;
	int	j;
	for ( i=0; i < plen; i++ ) {
		if ( i >= rlen )
			break;
		else if ( *(pptr+i) == ' ')
			break;
		else if (!( *(pptr+i) ))
			break;
		else	*(rptr+i) = *(pptr+i);
		}
	for ( j=0; j < slen; i++,j++ ) {
		if ( i < rlen ) 
			*(rptr+i) = *(sptr+j);
		else	break;
		}
	for ( ; i < rlen; i++ )
		*(rptr+i) = ' ';
	return;
}

public	void	fnaddfile( char * rptr, int rlen, char * pptr, int plen , char * sptr, int slen )
{
	fntransfer(rptr,rlen,pptr,plen,sptr,slen );
}

public	void	perform_toggle(int keycode)
{
	switch ( keycode ) {
		case	_TOGGLE_IDENTITY	:
			break;

		case	_TOGGLE_PALETTE		:
			swap_Palette();
			break;

		case	_TOGGLE_STATUSBAR	:
			swap_StatusBar();
			break;

		case	_TOGGLE_TOOLBAR		:
			swap_ToolBar();
			break;

		case	_TOGGLE_MENUBAR		:
			swap_MenuBar();
			break;

		case	_TOGGLE_TOOL		:
			if ( Context.usingtool )
				Context.usingtool = 0;
			else	Context.usingtool = (Context.style+1);
			draw_ToolBar();
			break;

		case	_TOGGLE_IMAGE		:
			if ( Context.Image.state )
				Context.Image.state = 0;
			else	Context.Image.state = 1;
			break;

		case	_TOGGLE_GRID		:
			if ( Context.gridlockw ) {
				Context.gridlockw = 0;
				Context.gridlockh = 0;
				}
			else 	{
				Context.gridlockw = Context.gridwidth;
				Context.gridlockh = Context.gridheight;
				}
			break;

		case	_TOGGLE_LOCK		:
			if ( Context.lockon   )
				Context.lockon = 0;
			else 	Context.lockon = 1;
			break;

		}

	return;
}

public	void	local_drop_font( int number )
{
#ifndef	UNIX
	drop_font( number );
#endif
}

public	int	local_load_font( int number, char * filename )
{
	int		fid=0;
	char *		tempname;
	if (!( system_fontpath ))
		return( load_font(number, filename ) );
	else if ( *filename == '{' )
		return( load_font(number, filename ) );
	else if (!( tempname = allocate( 1024 ) ))
		return( load_font(number, filename ) );
	else if ( fn_parser( filename, tempname, 0x0007) != 0 ) {
		liberate( tempname );
		return( load_font(number, filename ) );
		}
	else	{
		sprintf(tempname,"%s%s",system_fontpath,filename);
		fid = load_font(number, tempname );
		tempname = liberate( tempname );
		return( fid );
		}
}

/*
 *	Calculates the inner width for :
 *	
 *	0 : Desktop	: remainder after toolbar/treeview and palette
 *	1 : Menu Bar    : between toolbat and palette buttons
 *	2 : Status Bar  : remainder after toolbar/palette, under treeview
 */

public	int	inner_left()
{
	int	i;
	if ( Context.ToolBar.style ) {
		if (!( Context.ToolBar.align ))
			i = (Context.ToolBar.w+1);
		else	i = 0;
		}
	return( i );
}

public 	int	inner_width(int mode)
{
	int	i=0;
	if ( mode == 2 ) {
		/* scroll bar */
		if ( Context.ToolBar.style ) {
			if (!( Context.ToolBar.align ))
				i = (Context.ToolBar.w+1);
			else	i = 0;
			}
		}
	else if ( mode == 1 ) {
		/* menu bar */
		return( ((Context.Palette.x - Context.MenuBar.x)) );
		}

	else if ( Context.TreeView.style )
		i = (Context.TreeView.x+Context.TreeView.w);
	else if ( Context.ToolBar.style ) {
		if (!( Context.ToolBar.align ))
			i = (Context.ToolBar.w+1);
		}
	if ( Context.Palette.x ) {
		if (!( Context.Palette.align ))
			return( ((Context.Palette.x - i)-2) );
		else if ( mode == 1 ) /* Status/Menu bars */
			return( ((Context.Palette.x - i)-2) );
		else	return( ((Context.width - i)-2) );
		}
	else	return( ((Context.width - i)-2) );
}

public 	int	inner_height()
{
	if ( Context.StatusBar.y )
		return((Context.StatusBar.y-Context.DeskTop.y));
	else	return((Context.height-Context.DeskTop.y));
}

public 	void	draw_console()	
{ 
	draw_StatusBar();
	draw_MenuBar();
	draw_ToolBar();
	draw_Palette();
	draw_TreeView();
	draw_DeskTop();
	return; 
}

#include "singpal.c"
#include "singbar.c"
#include "singpv.c"


private	int	lock_font_width( int v, int adjust, int fid )
{
	int	x;
	int	fw;
	if (!( fid ))
		return( v );
	fw  = (guifontsize(fid) & 0x00FF);
	if ((x = (v % fw)) > 0) {
		if ( v > (fw/2))
			v = (((v / fw)+adjust)*fw);
		else	v -= x;
		}
	else if (!( v ))
		v = ( fw * adjust);

	return(v);
}

private	int	lock_font_height( int v, int adjust, int fid )
{
	int	x;
	int	fh;

	if (!( fid ))
		return( v );

	fh  = ((guifontsize(fid) >> 8) & 0x00FF);

	if ((x = (v % fh)) > 0) {
		if ( v > (fh/2))
			v = (((v / fh)+adjust)*fh);
		else	v -= x;
		}
	else if (!( v ))
		v = (fh * adjust);
	return(v);
}

public 	void	apply_gridlock( struct window_control * wptr, int mode )
	/* Mode : 1	:	apply to position coordinates	*/
	/* Mode : 2	:	apply to dimension coordinates	*/
	/* Mode : 4	:	force round up			*/
{
	int	dflag;
	if ( mode & 4 )	
		dflag=0;
	else	dflag=1;
	if ( Context.gridlockw ) {
	
		if ( mode & 1 ) {
			wptr->x = use_grid_lock( wptr->x,0,Context.gridlockw );
			wptr->y = use_grid_lock( wptr->y,0,Context.gridlockh  );
			}
		if ( mode & 2 ) {
			if (( wptr->style == _TEXT_FRAME  ) 
			||  ( wptr->style == _SELECT_FRAME)
			||  ( wptr->style == _SWITCH_FRAME)
			||  ( wptr->style == _GRAPH_FRAME)
			||  ( wptr->style == _CHECK_FRAME )
			||  ( wptr->style == _RADIO_FRAME )
			||  ( wptr->style == _EDIT_FRAME  )) {
	
				wptr->w = lock_font_width( wptr->w,dflag, wptr->font );
				wptr->h = lock_font_height( wptr->h,dflag,wptr->font );

				}
			else if ( wptr->style == _BUTTON_FRAME  ) {
				if (!( wptr->align & 2 )) {
					wptr->w = lock_font_width( wptr->w,dflag, wptr->font );
					wptr->h = lock_font_height( wptr->h,dflag,wptr->font );
					}
				else	{
					wptr->w = use_grid_lock( wptr->w,dflag,Context.gridwidth );
					wptr->h = use_grid_lock( wptr->h,dflag,Context.gridheight);
					}

				}
			else	{
				wptr->w = use_grid_lock( wptr->w,dflag,Context.gridwidth );
				wptr->h = use_grid_lock( wptr->h,dflag,Context.gridheight);
				}
			}

		}
	return;
}

public 	void	calculate_cursor( struct window_control * wptr )
{
	int	i;
	int	adx=0;
	int	ady=0;
	struct form_item *  aptr;
	int	fid;

	wptr->style = wptr->font = wptr->x = wptr->y = wptr->h = wptr->w = 0;

	if (( aptr = Context.Form->active )) {

		wptr->font = aptr->Contents.font;
		wptr->style= _CURSOR_FRAME;

		adx = (Context.Item.w - Context.Item.x);
		ady = (Context.Item.h - Context.Item.y);
		
		if ( aptr->Contents.style == _LINE_FRAME ) {
			if ( Context.Item.style == _MOVE_FRAME ) {
				wptr->x = (aptr->Contents.x + adx);
				wptr->y = (aptr->Contents.y + ady);
				wptr->w = aptr->Contents.w;
				wptr->h = aptr->Contents.h;
				}
			else	{
				wptr->x = aptr->Contents.x;
				wptr->y = aptr->Contents.y;
				wptr->w = (aptr->Contents.w + adx);
				wptr->h = (aptr->Contents.h + ady);
				}
			}

		else if ( Context.Item.style == _SIZE_FRAME ) {
			if ((wptr->w = (aptr->Contents.w + adx)) < 0)
				wptr->w = 0;
			if ((wptr->h = (aptr->Contents.h + ady)) < 0)
				wptr->h = 0;
			wptr->x = aptr->Contents.x;
			wptr->y = aptr->Contents.y;

			}
		else	{
			if ((wptr->x = (aptr->Contents.x + adx)) < 0)
				wptr->x = 0;
			if ((wptr->y = (aptr->Contents.y + ady)) < 0)
				wptr->y = 0;
			wptr->w = aptr->Contents.w;
			wptr->h = aptr->Contents.h;

			}

		}
	else if ( Context.Item.style == _LINE_FRAME ) {
		wptr->x = Context.Item.x;
		wptr->y = Context.Item.y;
		wptr->w = Context.Item.w;
		wptr->h = Context.Item.h;
		wptr->font = Context.Item.font;
		wptr->style= _LINE_FRAME;
		}
	else	{
		wptr->font = Context.Item.font;
		wptr->style= _CURSOR_FRAME;
		if ( Context.Item.x > Context.Item.w ) {
			wptr->x = Context.Item.w;
			if (!(wptr->w = (Context.Item.x - wptr->x)))
				wptr->w = 1;
			}
		else	{
			wptr->x = Context.Item.x;
			if (!(wptr->w = (Context.Item.w - wptr->x)))
				wptr->w = 1;
			}
		if ( Context.Item.y > Context.Item.h ) {
			wptr->y = Context.Item.h;
			if (!(wptr->h = (Context.Item.y - wptr->y)))
				wptr->h = 1;
			}
		else	{
			wptr->y = Context.Item.y;	
			if (!(wptr->h = (Context.Item.h - wptr->y)))
				wptr->h = 1;
			}
	
		}

	if ( Context.lockon )
		apply_gridlock( wptr, 3 );

	return;
}

public	void	cursor_frame( int atx, int aty, int nbx, int nby, int style )
{
	atx -= Context.Form->Buffer.x; aty -= Context.Form->Buffer.y;

	if ( atx > (Context.DeskTop.x+Context.DeskTop.w))
		return;
	else if ( atx < Context.DeskTop.x ) {
		if ((atx +nbx) < Context.DeskTop.x )
			return;
		else  if ( atx > 0 )
			nbx -= (Context.DeskTop.x - atx);
		else	{
			nbx -= 	Context.DeskTop.x;
			nbx +=  atx;			
			}
		atx = Context.DeskTop.x;
 		}

	if ( aty > (Context.DeskTop.y+Context.DeskTop.h))	
		return;
	else if ( aty < Context.DeskTop.y ) {
		if ((aty +nby) < Context.DeskTop.y )
			return;
		else  if ( aty > 0 )
			nby -= (Context.DeskTop.y - aty);
		else	{
			nby -= 	Context.DeskTop.y;
			nby +=  aty;			
			}
		aty = Context.DeskTop.y;
		}

	if ( (atx+nbx) > (Context.DeskTop.x+Context.DeskTop.w))	
		nbx = ((Context.DeskTop.x+Context.DeskTop.w) - atx);

	if ( (aty+nby) > (Context.DeskTop.y+Context.DeskTop.h))	
		nby = ((Context.DeskTop.y+Context.DeskTop.h) - aty);

	visual_frame( atx,aty,nbx,nby,style );
	return;
}

private	void	cursor_frame_show( int atx, int aty, int nbx, int nby )
{
	atx -= Context.Form->Buffer.x; aty -= Context.Form->Buffer.y;

	if ( atx > (Context.DeskTop.x+Context.DeskTop.w))
		return;
	else if ( atx < Context.DeskTop.x ) {
		if ((atx +nbx) < Context.DeskTop.x )
			return;
		else  if ( atx > 0 )
			nbx -= (Context.DeskTop.x - atx);
		else	{
			nbx -= 	Context.DeskTop.x;
			nbx +=  atx;			
			}
		atx = Context.DeskTop.x;
 		}

	if ( aty > (Context.DeskTop.y+Context.DeskTop.h))	
		return;
	else if ( aty < Context.DeskTop.y ) {
		if ((aty +nby) < Context.DeskTop.y )
			return;
		else  if ( aty > 0 )
			nby -= (Context.DeskTop.y - aty);
		else	{
			nby -= 	Context.DeskTop.y;
			nby +=  aty;			
			}
		aty = Context.DeskTop.y;
		}

	if ( (atx+nbx) > (Context.DeskTop.x+Context.DeskTop.w))	
		nbx = ((Context.DeskTop.x+Context.DeskTop.w) - atx);

	if ( (aty+nby) > (Context.DeskTop.y+Context.DeskTop.h))	
		nby = ((Context.DeskTop.y+Context.DeskTop.h) - aty);

	show( atx,aty,nbx,nby );
	return;
}

private	void	cursor_line( int atx, int aty, int tox , int toy, int size, int colour, void * fptr )
{
	atx -= Context.Form->Buffer.x; aty -= Context.Form->Buffer.y;
	tox -= Context.Form->Buffer.x; toy -= Context.Form->Buffer.y;

	if ( atx > (Context.DeskTop.x+Context.DeskTop.w))
		return;
	else if (( atx < Context.DeskTop.x )
	     &&  ( tox < Context.DeskTop.x ))
		return;

	if ( aty > (Context.DeskTop.y+Context.DeskTop.h))
		return;
	else if (( aty < Context.DeskTop.y )
	     &&  ( toy < Context.DeskTop.y ))
		return;

	drawline( atx,aty,tox,toy,size,colour,fptr);
	return;
}

public 	void	show_form_cursor(int optimised)
{
	struct window_control Window;
	struct window_control Worker;
	struct form_item *  aptr;

	if (!( Context.Cursor.style )) {

		calculate_cursor( & Window );

		if ((aptr = Context.Form->active )) {
			if ( aptr->Contents.style != _LINE_FRAME ) {
				cursor_frame(	Context.DeskTop.x+Window.x,
					Context.DeskTop.y+Window.y,
					Window.w,Window.h,(Context.Cursor.style = _CURSOR_FRAME));
				}
			else	{
				optimised = 0;
				cursor_line(
					Context.DeskTop.x+Window.x,
					Context.DeskTop.y+Window.y,
					Context.DeskTop.x+Window.w,
					Context.DeskTop.y+Window.h,
					aptr->Contents.size,
					aptr->Contents.colour,
					xorzone);
				Context.Cursor.style = _CURSOR_FRAME;
				}
			}
		else if ( Context.Item.style == _LINE_FRAME ) {
			optimised = 0;
			cursor_line(	Context.DeskTop.x+Window.x,
				Context.DeskTop.y+Window.y,
				Context.DeskTop.x+Window.w,
				Context.DeskTop.y+Window.h,
				Context.thickness,Context.foreground,xorzone);
			Context.Cursor.style = _CURSOR_FRAME;
			}
		else	{
			cursor_frame(	
				Context.DeskTop.x+Window.x,
				Context.DeskTop.y+Window.y,
				Window.w,Window.h,
				(Context.Cursor.style = _CURSOR_FRAME) );
			}

		if ( optimised ) {

			if ( Window.x > Context.Cursor.x )
				Worker.x = Context.Cursor.x;
			else	Worker.x = Window.x;
				if ( Window.y > Context.Cursor.y )
				Worker.y = Context.Cursor.y;
			else	Worker.y = Window.y;
				if (( Context.Cursor.x + Context.Cursor.w )  > ( Window.x + Window.w ))
				Worker.w = (( Context.Cursor.x + Context.Cursor.w ) - Worker.x);
			else	Worker.w = (( Window.x + Window.w ) - Worker.x);
				if (( Context.Cursor.y + Context.Cursor.h )  > ( Window.y + Window.h ))
				Worker.h = (( Context.Cursor.y + Context.Cursor.h ) - Worker.y);
			else	Worker.h = (( Window.y + Window.h ) - Worker.y);

			cursor_frame_show(Context.DeskTop.x+Worker.x,Context.DeskTop.y+Worker.y,Worker.w,Worker.h);

			}

		show_zone_position(Window.x,Window.y,Window.w,Window.h);


		}
	return;
}

public 	void	hide_form_cursor(int optimised)
{
	struct form_item *  aptr;

	if ( Context.Cursor.style != 0 ) {

		if ( Context.Item.style == _LINE_FRAME )
			optimised = 0;
		else if (((aptr = Context.Form->active ))
		     &&  ( aptr->Contents.style == _LINE_FRAME ))
			optimised = 0;

		if ( optimised )
			hide();

		calculate_cursor( &Context.Cursor );

		if (((aptr = Context.Form->active ))
		&&  ( aptr->Contents.style == _LINE_FRAME )) {
			cursor_line(	Context.DeskTop.x+Context.Cursor.x,
				Context.DeskTop.y+Context.Cursor.y,
				Context.DeskTop.x+Context.Cursor.w,
				Context.DeskTop.y+Context.Cursor.h,
				aptr->Contents.size,aptr->Contents.colour,xorzone);
			}
		else if ( Context.Item.style == _LINE_FRAME ) {
			cursor_line(	Context.DeskTop.x+Context.Cursor.x,
				Context.DeskTop.y+Context.Cursor.y,
				Context.DeskTop.x+Context.Cursor.w,
				Context.DeskTop.y+Context.Cursor.h,
				Context.thickness,Context.foreground,xorzone);
			}
		else	{
			cursor_frame(	Context.DeskTop.x+Context.Cursor.x,Context.DeskTop.y+Context.Cursor.y,Context.Cursor.w,Context.Cursor.h,Context.Cursor.style );
			}
		Context.Cursor.style = 0;
		}
	return;
}

public	void	enter_modal()	{ Context.ismodal++; }
public	void	leave_modal()	{ if ( Context.ismodal ) Context.ismodal--; }

public 	int	handle_event()
{
	int	x;
	int	y;
	int	t;
	int	b;
	int	e;

	x = visual_event(7);
	y = visual_event(6);

	/* Is it a click on the Palette */
	/* ---------------------------- */
	if ((e = is_PaletteEvent(x,y)) != -1 )
		return(e);

	/* Is it a click on the menu bar */
	/* ----------------------------- */
	else if ((e = is_MenuBarEvent(x,y)) != -1)
		return(e);

	/* Is it a click on the tool bar */
	/* ----------------------------- */
	else if ((e = is_ToolBarEvent(x,y)) != -1 )
		return(e);

	/* Is it a click on the menu bar */
	/* ----------------------------- */
	else if ((e = is_TreeViewEvent(x,y)) != -1)
		return(e);

	/* Is the Zoom Editor Active */
	/* ------------------------- */
	else if ( Context.Zoom ) 
		return( is_ZoomEvent(Context.Zoom,x,y) );
		
	/* Is the Font Editor Active */
	/* ------------------------- */
	else if ( Context.FontContext )
		return( is_FontEvent(Context.FontContext,x,y) );
		
	else if ( Context.ismodal )
		return(-1);

	else if ((e = is_DeskTopEvent(x,y)) != -1)
		return(e);

	else	return(256);
}

public	void	configure_console(
	int	toolbar_status, 	int	palette_status,
	int	statusbar_status,	int	menubar_status,
	int	treeview_status					 )
{
	if ( toolbar_status )
		activate_ToolBar(_MENU_FRAME);
	else	activate_ToolBar(0);
	if ( palette_status )
		activate_Palette(_MENU_FRAME);
	else	activate_Palette(0);
	if ( statusbar_status )
		activate_StatusBar(_OUTSET_FRAME);
	else	activate_StatusBar(0);
	if ( menubar_status )
		activate_MenuBar(_OUTSET_FRAME);
	else	activate_MenuBar(0);
	if ( treeview_status )
		activate_TreeView(_RIDGE_FRAME);
	else	activate_TreeView(0);
	activate_DeskTop(_OUTSET_FRAME );
	return;
}

public	void	reconfigure_console(	treeview_status	 )
{
	if ( treeview_status )
		activate_TreeView(_RIDGE_FRAME);
	else	activate_TreeView(0);
	activate_DeskTop(_OUTSET_FRAME );
	if ( Context.EditView == 1 ) {
		reconfigure_editor(); 
		}
	return;
}

private	void	drop_context()
{
	int	i;
	struct	form_item * iptr;

	Context.TreeView.style=0;

	if ( Context.string_buffer )
		Context.string_buffer = liberate( Context.string_buffer );

	if ( Context.paper_types )
		Context.paper_types = liberate( Context.paper_types );

	Context.string_buffer_length  = 0;

	for (i=0; i < WIDGET_FILE_LIMIT; i++ ) {
		if ( Context.file_path[i] )
			Context.file_path[i] = liberate( Context.file_path[i] );
		}

	if ( xworkbuffer != (char *) 0)
		xworkbuffer = liberate( xworkbuffer );

	while ((iptr = Context.UndoList ) != (struct form_item *) 0) {
		Context.UndoList = iptr->next;
		liberate_Widget( iptr );
		}

	liberate_file_finder();
	liberate_file_manager((void*)0);

	if ( Context.form_message_buffer ) {
		liberate( Context.form_message_buffer );
		Context.form_message_buffer = (char *) 0;
		}
	return;
}

public	void	connect_3dscroll(struct coordinate3d * cptr, int l, int m)
{
	Context.Scroll3d.value = cptr;
	Context.Scroll3d.limit = l;
	Context.Scroll3d.focus = 0;
	Context.Scroll3d.max   = m;
	return;
}

private	void	reset_context()
{
	int	i;
	Context.Introduction=(void*)0;
	Context.StatusObject=(void*)0;
	Context.MainMenuContext = (void*)0;
	Context.ThreedCursor = (void*)0;
	Context.form_message_buffer = (char *) 0;
	Context.imagepathitem = 0;
	Context.OutOfDate=0;
	Context.AutoSave = 1;
	Context.UndoList = (struct form_item *) 0;
	Context.EditView = 0;
	Context.RelativeFonts=1;
	Context.compiling   = 0;
	Context.paper_types = (char *) 0;
	Context.ismodal	    = 0;
	Context.Tree        = (struct treeview *) 0;
	Context.TreeTop     = (struct treeview *) 0;
	Context.TreeFocus   = (struct treeview *) 0;
	Context.ToolManager = (struct tool_node *) 0;
	Context.ModelHeap   = (struct model_node *) 0;
	Context.Class= (struct standard_class*) 0;
	Context.Form = (struct form_control *) 0;
	Context.File = (struct file_control *) 0;
	Context.Widgets= (struct form_item *) 0;
	Context.Menu = (struct menu_control *) 0;
	Context.Zoom = (struct zoom_control *) 0;
	Context.Camera=(struct camera3d*) 0;
	Context.FontContext     = (struct font_context *) 0;
	Context.alignment	=_A_NONE;
	Context.language	=_GENERATE_ABAL;
	Context.imageformat     = 0;
	Context.transparent	= 0;
	Context.thickness	= 1;
	Context.gridbuffer	= (char *) 0;
	Context.gridlockw       = 0;
	Context.gridlockh       = 0;
	Context.gridwidth       = 10;
	Context.gridheight      = 24;
	Context.usingtool	= 0;
	Context.usage 		= 0;
	Context.style           = _FILL_FRAME;
	Context.fontitem	= 0x0041;
	Context.Item.style	= -1;
	Context.lockon		= 1;
	Context.dropon		= 1;
	Context.Item.font	=FONT_MIN;
	Context.Cursor.style = Context.Cursor.x = Context.Cursor.y = Context.Cursor.w = Context.Cursor.h = 0;
	Context.foreground	= _DEFAULT_GUI_BLACK;
	Context.background	= _DEFAULT_GUI_WHITE;
	Context.Image.x = Context.Image.y = Context.Image.width = Context.Image.height = 0;
	Context.Image.type	= 0; /* BMP=0, GIF=1,JPG=2 */
	Context.Image.depth     = 8; /* 8 bits per pixel   */
	Context.Image.state     = 0; /* Not active */
	connect_3dscroll((struct coordinate3d *)0,0,0);
	reset_scroll( &Context.TSB );
	reset_scroll( &Context.VSB );
	reset_scroll( &Context.HSB );
	Context.string_buffer = (char *) 0;
	Context.string_buffer_length  =  0;
	for (i=0; i < WIDGET_FILE_LIMIT; i++ )
		Context.file_path[i] = (char *) 0;
	initilise_file_manager((void*)0);
	return;
}

public	void	inhibit_text_cursor()
{
	x_putch(27); x_putch('w');
	return;
}

public	void	activate_text_cursor()
{
	x_putch(27); x_putch('v');
	return;
}

#define	_BASE_PALETTE "/home/abal3/images/grisstd.rgb"

public	int	open_graphics()
{
	if ( open_console() == 2 ) {

		visual_palette(_BASE_PALETTE,strlen(_BASE_PALETTE));

		initialise_mouse();
		mouse_move_off();
		cicopalette(0,0);
		x_event(31);	/* activate alt key operation */
		/* hide the text cursor for now */
		inhibit_text_cursor();
		return(1);
		}
	else	return(0);
}

public	int	close_graphics(int og)
{
	if ( og ) {
		x_event(32);	/* inhibit alt key operation */
		/* show the text cursor for now */
		activate_text_cursor();
		terminate_mouse();
		}
	close_console();
	return(1);
}


private	char *	operation_configuration(char * argptr)
{
	char *	cptr;
	if ((cptr = singconfigname ) != (char *) 0)
		return( cptr );

#ifndef	PROLOGUE
	else if (!( cptr = getenv("SINGCFG") ))
		fn_parser(argptr,(cptr = namebuffer),0x000F);
#else
	else	cptr = "sing";
#endif
	printf("configuration : %s\r\n",cptr);
	return( cptr );
}

int	og=0;

private	int	operation(int argi, int argc, char * argv[] )
{
	char *	cptr;
	int	c;
	char * aptr=(char *) 0;
	char * getenv(char *);
	
	for (	; argi < argc; argi++ ) {
		if (!( aptr = argv[argi]))
			break;
		else if ( *aptr != '-' )
			break;
		}

	if (!( aptr ))
		return(argi);


	else if (!( cptr = operation_configuration(argv[0])))
		return(argi);
	else	LoadConfiguration( cptr );

	sprintf(workbuffer,"Sing %s",aptr);
	set_desktop_name( workbuffer  );
	set_desktop_icon( "Sing" );

	if ((og = open_graphics()) != 0) {

		Context.width    = hardcolumns();
		Context.height   = hardrows();

		load_FontTable();

		visual_limits(Context.width,Context.height);

		if ((c = guifontsize((Context.basefont=1))) == 0 ) {
			Context.fontwidth	= 
			Context.fontheight	= 10;
			}
		else	{
			Context.fontwidth	= (c & 0x00FF);
			Context.fontheight	= ((c >> 8) & 0x00FF);
			}

		treeview_configuration();

		Context.menufont = 2;
		Context.tinyfont = 8;

		reset_context();
		allocate_tree_managers();
		allocate_tool_managers();
		initialise_production();
		configure_console(1,1,1,1,0);
		draw_console();
		CameraWorkOut(aptr);
		drop_DeskTop();
		release_production();
		liberate_tool_managers();
		liberate_tree_managers();
		release_widget_types();
		drop_FontTable();
		release_images();
		(void) close_graphics(og);
		drop_context();
		}
	else	{
		close_graphics(og);
		printf("\nerror opening graphics\n");
		}
	drop_configuration();
#ifdef	PROLOGUE
	flush_zalloc();
#endif
	return(0);
}

private	int	error_message( int result,char * mptr, char * vptr )
{
	drop_configuration();
	printf("\r\n* * * %s : %s * * * \r\n",mptr,vptr);
	return( result );
}

public	int	injection(int argi, int argc, char * argv[] )
{
	int	status;
	int	verboser=0;
	char *	aptr;
	char *	cptr;

	font_load(1, _default_font_name[1], 0 );
	if (!( cptr = operation_configuration(argv[0])))
		return(argi);
	else	LoadConfiguration( cptr );
	load_FontTable();
	for (	; argi < argc; argi++ )  {
		if (!( aptr = argv[argi] ))
			return( argc );
		else if ( *aptr == '-' ) {
			switch ( *(aptr+1) ) {
				case	'v'	:
				case	'V'	:
					verboser = 1;
					continue;
				default		:
					return( error_message(argc,"syntax error", argv[argi] ) );
				}
			}
		else 	{
			if ( verboser )
				printf("injecting ldap  %s\n",aptr);
				
			if (( status = ldap_inject( aptr )) != 0) {
				if (!( verboser ))
					return( error_message(argc,"ldap injection failure", argv[argi] ) );
				else	return( argc );
				}
			continue;
			}
		}
	return(argc);
}

public	int	convertor(int argi, int argc, char * argv[] )
{
	int	status;
	int	verboser=0;
	char *	aptr;
	char *	cptr;
	char *	mptr;
	char *	xptr;

	font_load(1, _default_font_name[1], 0 );
	if (!( cptr = operation_configuration(argv[0])))
		return(argi);
	else	LoadConfiguration( cptr );
	load_FontTable();
	for (	; argi < argc; argi++ )  {
		if (!( aptr = argv[argi] ))
			return( argc );
		else if ( *aptr == '-' ) {
			switch ( *(aptr+1) ) {
				case	'v'	:
				case	'V'	:
					verboser = 1;
					continue;
				default		:
					return( error_message(argc,"syntax error", argv[argi] ) );
				}
			}
		else if (!(  mptr = allocate_string( argv[argi] )))
			return( error_message(argc,"allocation failure", argv[argi] ) );
		else if (!( mptr = enforce_extension(mptr,MODEL_EXTENSION) ))
			return( error_message(argc,"allocation failure", argv[argi] ) );
		else	{ 
			if ( verboser )
				printf("converting %s\n",aptr);
			if (!( status = load_DeskTop(mptr,1,_INHIBIT_REFRESH | _INHIBIT_PROPERTIES )))
				return( error_message(argc,"error loading" , mptr ) );
			else if (!( Context.Form->loadname = enforce_extension(Context.Form->loadname,XML_EXTENSION) )) {
				return( error_message(argc,"allocation failure", argv[argi] ) );
				}
			else	{
				xml_put_Form( Context.Form, "sing.dtd" );
				drop_DeskTop();
				}			
			continue;
			}
		}
	return(argc);
}


public	int	compiler(int argi, int argc, char * argv[] )
{
	int	language=_GENERATE_ABAL;
	int	verboser=0;
	int	success=0;
	char *	aptr;
	char *	cptr;
	font_load(1, _default_font_name[1], 0 );
	if (!( cptr = operation_configuration(argv[0])))
		return(argi);
	else	LoadConfiguration( cptr );
	load_FontTable();
	for (	; argi < argc; argi++ )  {
		if (!( aptr = argv[argi] ))
			return( argc );
		else if ( *(aptr++) == '-' ) {
			switch ( *(aptr++) ) {
				case	'v'	:
				case	'V'	:
					verboser = 1;
					continue;
				case	'l'	:
				case	'L'	:
					switch ( *(aptr++) ) {
						case	'c'	:
						case	'C'	:
							if ( *aptr == '+' )
								language = _GENERATE_CPP;
							else	language = _GENERATE_C;
							continue;

						case	'a'	:
						case	'A'	:
							if ( *aptr == '+' )
								language = _GENERATE_ABAL;
							else	language = _GENERATE_BAL;
							continue;

						case	'h'	:
						case	'H'	:
							language = _GENERATE_HTML;
							continue;
						default		:
							return( error_message(argc,"syntax error", argv[argi] ) );
						}
				default		:
					return( error_message(argc,"syntax error", argv[argi] ) );
				}
			}
		else	{
			reset_context();

			Context.compiling = 1;

			if ( verboser )
				printf("loading %s\n",argv[argi]);

			if (!( success = load_DeskTop(argv[argi],1,_INHIBIT_REFRESH | _INHIBIT_PROPERTIES )))
				return( error_message(argc,"error loading" , argv[argi] ) );
			
			if ( verboser )
				printf("compiling %s\n",argv[argi]);
			Context.language = language;
			success = export_DeskTop(argv[argi],_INHIBIT_REFRESH | _INHIBIT_PROPERTIES | _INHIBIT_STATUS );
			drop_DeskTop();

			if (!( success ))
				return( error_message(argc,"error compiling", argv[argi] ) );
			}
		}
	drop_FontTable();
	drop_configuration();
	return( argc );
}

public	int	commandline( int argc, char * argv[] )
{
	int	c;
	int	argi;
	char *	aptr;
	for (argi=1; argi < argc; argi++ )  {
		if (!( aptr = argv[argi] ))
			return( argc );
		else if ( *(aptr++) != '-' )
			break;
		switch ( *(aptr++) ) {
			case	'a'	:
#ifdef	PROLOGUE
				AllocationTrace = 1;
#endif
				continue;
			case	'j'	:
				switch ((c = *(aptr++))) {
					case	0   :
						c = '0';
					case	'0' :
					case	'1' :
					case	'2' :
						set_image_quality(c-'0');
					}
				continue;
			case	'd'	:
				c=0;
				while ( *aptr ) {
					if (( *aptr >= '0' ) && ( *aptr <= '9' ))
						c = ((c*10) + ( *(aptr++) - '0' ));
					else	break;
					}
				SystemD = c;
				continue;
				
			case	'l'	:
			case	'L'	:
				if ( *aptr != 0 )
					singconfigname = aptr;
				continue;

			case	'i'	:
			case	'I'	:
				return( injection( argi+1, argc, argv ) );

			case	'c'	:
			case	'C'	:
				return( compiler( argi+1, argc, argv ) );

			case	'x'	:
			case	'X'	:
				return( convertor( argi+1, argc, argv ) );


			case	't'	:
			case	'T'	:
				texting = 1;
				continue;

			case	'm'	:
			case	'M'	:
				c = 0;
				while ( *aptr ) {
					if (( *aptr >= '0' ) && ( *aptr <= '9' ))
						c = ((c*10) + ( *(aptr++) - '0' ));
					else	break;
					}
				set_biosmode(c);
				continue;
			}
		}
	return( argi );
}

private	int	llmain( int argc, char * argv[] )
{
	int	argi;
	char *  textchoose="\1=TEXTING";
	texting = *textchoose;
	if ( argc == 1 )
		return( banner() );
	else if ((argi = commandline(argc,argv)) < argc )
		return( operation(argi,argc,argv) );
	else	return(0);
}

#ifdef	WIN32
public majn( int argc, char* argv[])
#else
public int main( int argc, char * argv[] )
#endif
{
	int	status=0;
#ifdef	UNIX
	start_allocation_trace();
#endif
	status = llmain(argc,argv);
#ifdef	UNIX
	close_allocation_trace();
#endif
	return( status );
}

