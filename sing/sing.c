
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sing.h"
#include "palet.h"
#include "stdpsu.h"
#include "rtbda.c"

#ifndef WIN32
#include "zalloc.c"
#ifdef	GWBTRACE
#define TRACEON
#define CE_TRA_MASTERKEY "[sing]"
#define CI_PRG_ID "sing"
#include "trace.h"
#include "trace.c"
#endif
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
#include "singappl.h"
extern	struct	application_parameters Application;
extern char * system_imagepath;

#ifdef	UNIX
char *confgetenv( const char *varname )
{
	return( getenv( varname ) );
}

#define	_NO_PANIC
#include "cico.c"

public  int	verbose=0;

#else	/* ! UNIX */
#include "console.c"
#include "fnparser.c"
#endif	/* UNIX   */


#include "singfind.c"

public	char	workbuffer[1024];

#ifndef	WIN32
#include "mouse.c"
#endif

public	int	texting=0;
public 	char	namebuffer[1024];
public	int	SystemD=1;
private	char *	singconfigname="sing";
private	char *	projecter=(char *) 0;	/* project for compilation */
extern	char *	font_name[];
extern	char *	_default_font_name[];

public	struct	screen_control	Context;
private	int	OperationStatus=0;

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

int	test_initialise_hardware()	{	return(1);	}

#ifdef	UNIX
/* #BGI 01/08/06 Définitions inutiles si choixrepfic.c dans le projet. */

public	int	ChoixRep(char * a, char * b )
{
	return(0);
}
public	int	ChoixRepPlus(char * a, char * b )
{
	return(0);
}
#endif

public 	void	show_form_cursor(int o);
public 	void	hide_form_cursor(int o);
public 	void	show_mouse_position(int x,int y);
public 	void	calculate_cursor( struct window_control * wptr );

private	char *	xworkbuffer=(char *) 0;
public	char *	classbuffer=(char *) 0;

public	int	use_system_d()		{ 	return( SystemD );			}

public	int	is_expert_user()	
{	
	return( SingConf->expert_user );	
}

/*	--------------------------------------------------------------------	*/
/*	Allows display of old widget properties sialog box for total control 	*/
/*	--------------------------------------------------------------------	*/

private	int	SingUseAllWidget=-1;

public	int	set_all_widget(int v)
{
	return((SingUseAllWidget=v));	
}

public	int	use_all_widget()
{
	char *	eptr;
	if ( SingUseAllWidget != -1 )
		return( SingUseAllWidget );
	else	
	if (!(eptr = confgetenv("VWIDGET")))
		return((SingUseAllWidget = 0));
	else if ( *eptr == '1' )
		return((SingUseAllWidget = 1));
	else	return((SingUseAllWidget = 0));
}

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
#ifdef WIN32
	/* Case of long path names converted by GetShortPathName() */
	else if ( upper_compare( xworkbuffer, xptr ) )
#else
	else if ( string_compare( xworkbuffer, xptr ) )
#endif
		return( 1 );
	else	return( 0 );

}

public	int	detect_language_extension(char * nptr)
{
	if (!( xworkbuffer ))
		if (!(xworkbuffer = allocate( 513 )))
			return(0);

	if (!( fn_parser( nptr, xworkbuffer, 0x0010 ) ))
		return( 0 );

	if (( string_compare( xworkbuffer, CLASS_EXTENSION ))
	||  ( string_compare( xworkbuffer, AS_EXTENSION    ))
	||  ( string_compare( xworkbuffer, EXT_EXTENSION   ))
	||  ( string_compare( xworkbuffer, S_EXTENSION 	   )))
		return( _GENERATE_BAL );
	if (( string_compare( xworkbuffer, XML_EXTENSION ))
	||  ( string_compare( xworkbuffer, HTM_EXTENSION ))
	||  ( string_compare( xworkbuffer, CSS_EXTENSION )))
		return( _GENERATE_HTML );

	if (( string_compare( xworkbuffer, CPP_EXTENSION ))
	||  ( string_compare( xworkbuffer, C_EXTENSION   ))
	||  ( string_compare( xworkbuffer, JAV_EXTENSION ))
	||  ( string_compare( xworkbuffer, H_EXTENSION   )))
		return( _GENERATE_C );
	else	return( 0 );
}

public	char *	extract_path( char * sptr )
{
	char *	rptr;
	if (!( sptr ))
		return( (char *) 0 );
	else if (!(rptr = allocate_string( sptr ) ))
		return( (char *) 0 );
	else	{
		fn_parser( sptr, rptr, 0x0007 );
		return( rptr );
		}
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
	else if (!( filepath ))
		return( allocate_string( filename ) );
#ifdef WIN32
	if (filename[0]=='\\') return( allocate_string( filename ) );
	if (filename[1]==':') return( allocate_string( filename ) );
#else
	if (filename[0]=='/') return( allocate_string( filename ) );
#endif
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
#ifdef	PROLOGUE
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
				i = Context.ToolBar.w;
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
	if (!( Context.compiling )) {
#ifdef	_TRACE_POSITION
		printf("SB : x=%u, y=%u, w=%u, h=%u \r\n",
			Context.StatusBar.x,	Context.StatusBar.y,
			Context.StatusBar.w,	Context.StatusBar.h);
#endif
		draw_StatusBar();
#ifdef	_TRACE_POSITION
		printf("MB : x=%u, y=%u, w=%u, h=%u \r\n",
			Context.MenuBar.x,	Context.MenuBar.y,
			Context.MenuBar.w,	Context.MenuBar.h);
#endif
		draw_MenuBar();
#ifdef	_TRACE_POSITION
		printf("TB : x=%u, y=%u, w=%u, h=%u \r\n",
			Context.ToolBar.x,	Context.ToolBar.y,
			Context.ToolBar.w,	Context.ToolBar.h);
#endif
		draw_ToolBar();
#ifdef	_TRACE_POSITION
		printf("PL : x=%u, y=%u, w=%u, h=%u \r\n",
			Context.Palette.x,	Context.Palette.y,
			Context.Palette.w,	Context.Palette.h);
#endif
		draw_Palette();
#ifdef	_TRACE_POSITION
		printf("TV : x=%u, y=%u, w=%u, h=%u \r\n",
			Context.TreeView.x,	Context.TreeView.y,
			Context.TreeView.w,	Context.TreeView.h);
#endif
		draw_TreeView();
#ifdef	_TRACE_POSITION
		printf("DT : x=%u, y=%u, w=%u, h=%u \r\n",
			Context.DeskTop.x,	Context.DeskTop.y,
			Context.DeskTop.w,	Context.DeskTop.h);
#endif
		draw_DeskTop();
		}
	return; 
}

#include "singpal.c"
#include "singbar.c"
#include "singpv.c"
#include "singlock.c"


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

	/* Is the Font Editor Active */
	/* ------------------------- */
	else if ( Context.FontContext )
		return( is_FontEvent(Context.FontContext,x,y) );
		
	/* Resolve other ALT Key Combinations now */
	/* -------------------------------------- */ 
	else if ((t = visual_event(1)) & _MIMO_ALT )
		return( visual_event(2) );
 
	/* Is the Zoom Editor Active */
	/* ------------------------- */
	else if ( Context.Zoom ) 
		return( is_ZoomEvent(Context.Zoom,x,y) );
		
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

	if ( Context.TestData )
		Context.TestData = liberate( Context.TestData );

	if ( Context.WidgetCursor )
		visual_drop( Context.WidgetCursor );

	Context.TestDataSize = 0;
	Context.UseTestData  = 0;

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

	if ( Context.CopiedMethod ) {
		liberate_Method( Context.CopiedMethod );
		Context.CopiedMethod = (void*)0;
		}

	if ( Context.CopiedMember ) {
		liberate_Member( Context.CopiedMember );
		Context.CopiedMember = (void*)0;
		}

	Context.TemplateWidget = (struct form_item *) 0;

	if ( Context.form_message_buffer ) {
		liberate( Context.form_message_buffer );
		Context.form_message_buffer = (char *) 0;
		}
	if ( Context.FontList ) {
		liberate( Context.FontList);
		Context.FontList=(char *) 0;
		}
	if ( Context.FontLabelList ) {
		liberate( Context.FontLabelList);
		Context.FontLabelList=(char *) 0;
		}
	liberate_font_labels();

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

public	void	allow_rollback()	{	Context.lockroll=0;	}
public	void	inhibit_rollback()	{	Context.lockroll=1;	}

/*	-------------------------------------------------	*/
/*	s e t _ c o n t e x t _ d a t a v i e w ( state )	*/
/*	-------------------------------------------------	*/
/*	used to set the model editor to called to redisplay	*/
/*	the current workbench contents.				*/
/*	-------------------------------------------------	*/
public	int	set_context_dataview(int state)
{
	int	result = Context.DataView;
	Context.DataView = state;
	return(result);
}

private	int	_default_i_hide=_I_HIDE;
public	int	default_i_hide()
{
	return( _default_i_hide );
}

private	void	reset_context()
{
	char *	eptr;
	int	i;
	Context.FontList=(char *) 0;
	Context.FontLabelList=(char *) 0;
	Context.hideimage = default_i_hide();
	Context.showall = 1;
#ifdef	ABAL32A
	Context.usestyle=1;
#else
	Context.usestyle=0;
#endif
	if ( get_pixel_format() )
		Context.defaultimagetype = 1;
	else	Context.defaultimagetype = 3;
	if (!( eptr = confgetenv("WIDGETRESIZE")))
		Context.ResizeBy=0;
	else if ( *eptr == '1' )
		Context.ResizeBy=1;
	else	Context.ResizeBy=0;
	
	Context.radioshowall=0;
	Context.natlang=0;
	Context.rollback=0;
	allow_rollback();
	Context.MakeFormFit = 0;
	Context.TemplateWidget = (struct form_item *) 0;
	Context.CopiedMethod=(void*)0;
	Context.CopiedMember=(void*)0;
	Context.Introduction=(void*)0;
	Context.StatusObject=(void*)0;
	Context.MainMenuContext = (void*)0;
	Context.ThreedCursor = (void*)0;
	Context.VisualShell  = (void*)0;
	Context.form_message_buffer = (char *) 0;
	Context.imagepathitem = 0;
	Context.sourcepathitem = 0;
	Context.OutOfDate=0;
	Context.AutoSave = 1;
	Context.UndoList = (struct form_item *) 0;
	Context.EditView = 0;
	Context.DataView = 0;
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
	Context.MenuActive=1;
	Context.BarActive=1;
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
	Context.gridtype	= 1;
	Context.BalOrAbal	= 0;
	Context.lockon		= 1;
	Context.dropon		= 1;
	Context.widgetstyle 	= 0;
	Context.nested 		= 0;
	Context.Item.font	=FONT_MIN;
	Context.Cursor.style = Context.Cursor.x = Context.Cursor.y = Context.Cursor.w = Context.Cursor.h = 0;
	Context.foreground	= _DEFAULT_GUI_BLACK;
	get_rgb_values( Context.foreground, &Context.fgrgb[0],&Context.fgrgb[1],&Context.fgrgb[2]);
	Context.background	= _DEFAULT_GUI_WHITE;
	get_rgb_values( Context.background, &Context.bgrgb[0],&Context.bgrgb[1],&Context.bgrgb[2]);
	Context.Image.x = Context.Image.y = Context.Image.width = Context.Image.height = 0;
	Context.Image.type	= 0; /* BMP=0, GIF=1,JPG=2 */
	Context.Image.depth     = 8; /* 8 bits per pixel   */
	Context.Image.state     = 0; /* Not active */
	Context.TestData	= (char *) 0;
	Context.TestDataSize	= 0;
	Context.UseTestData	= 0;
	connect_3dscroll((struct coordinate3d *)0,0,0);
	reset_scroll( &Context.TSB );
	reset_scroll( &Context.VSB );
	reset_scroll( &Context.HSB );
	Context.string_buffer = (char *) 0;
	Context.string_buffer_length  =  0;

	Context.WidgetCursor = (void *) 0;
	Context.WidgetCursorX= 
	Context.WidgetCursorY=0;

	for (i=0; i < WIDGET_FILE_LIMIT; i++ )
		Context.file_path[i] = (char *) 0;
	initialise_file_manager((void*)0);
	initialise_style();
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
char* p;

	if ( open_console() == 2 ) {

#if defined(WIN32)
#ifndef CPP_PRODUCT	/* GWB le 22/10/2007 */
		windows_show_window();
#endif
#else
		visual_palette(_BASE_PALETTE,strlen(_BASE_PALETTE));
#endif

		p = confgetenv("GIGOTITLECOLORON");
		if ( p && *p=='1')
			{
			standard_text		=_DEFAULT_GUI_FG_TITLE_ORI;
			standard_title		=_DEFAULT_GUI_BG_TITLE_ORI;
			}

		initialise_mouse();
#if defined(WIN32)
		//FCH_SING (essai temporaire) mouse_move_off();
#else
		mouse_move_off();
#endif
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
	else if (!( cptr = confgetenv("SINGCFG") ))
		fn_parser(argptr,(cptr = namebuffer),0x000F);
#else
	else	cptr = "sing";
#endif
	printf("configuration : %s\r\n",cptr);
	return( cptr );
}

#ifdef	UNIX
public	void	use_visual_shell()
{
	signal_system_d((void *) 0);
	visual_command_shell_show(Context.VisualShell);
	visual_command_shell_focus(Context.VisualShell);
	visual_command_shell_hide(Context.VisualShell);
	return;
}

static	int	svs=0;
public	void	start_visual_shell()
{
	visual_command_shell_show(Context.VisualShell);
	svs = 1;
	return;
}

public	int	SystemV( char * cptr )
{
	int	status=0;
	svs = 0;

	/* indicate startup function */
	/* ------------------------- */
	signal_system_d(start_visual_shell);

	/* Perform controlled system operation */
	/* ----------------------------------- */
	if ((status = visual_system_d(Context.VisualShell,cptr)) != 0 ) {

		/* allow user intervention if visible error occured */
		/* ------------------------------------------------ */
		if ( svs ) { visual_command_shell_focus(Context.VisualShell); }
		}
	else if ( svs ) {
		/* allow user intervention if output occured */
		/* ----------------------------------------- */
		visual_command_shell_focus(Context.VisualShell);
		}

	/* hide eventual shell screen display */
	/* ---------------------------------- */
	if ( svs ) { visual_command_shell_hide(Context.VisualShell); }

	signal_system_d((void *) 0);
	return(status);
}
#endif

int	og=0;

private	int	operation(int argi, int argc, char * argv[] )
{
	char *	stylename;
	char *	cptr;
	int	c;
	char	kbf[2];
	char * aptr=(char *) 0;
	
#ifndef CPP_PRODUCT	/* GWB le 22/10/2007 */
	for (	; argi < argc; argi++ ) {
		if (!( aptr = argv[argi]))
			break;
		else if ( *aptr != '-' )
			break;
		}

	if (!( aptr ))
		return(argi);
	else 
#endif

	if (!( cptr = operation_configuration(argv[0])))
		return(argi);
	else	LoadConfiguration( cptr );

#ifdef CPP_PRODUCT
	sprintf(workbuffer,"Sing %s",argv[0]);
#else
	sprintf(workbuffer,"Sing %s",aptr);
#endif
	set_desktop_name( workbuffer  );
	set_desktop_icon( "Sing" );
	databaseEditorDefault();
	flowchartEditorDefault();
	dependanceEditorDefault();
	initialise_sing_other();

	if ((og = open_graphics()) != 0) {

		Context.width    = hardcolumns();
		Context.height   = hardrows();
#ifdef	SING_MODEL_EDITOR
		kbf[0] = _SING_HELP; kbf[1] = 0; prfo(128,kbf,1);		
		kbf[0] = _SING_PROD; kbf[1] = 0; prfo(129,kbf,1);		
		kbf[0] = _SING_BASE; kbf[1] = 0; prfo(130,kbf,1);		
		kbf[0] = _SING_FLOW; kbf[1] = 0; prfo(131,kbf,1);		
#endif
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

#ifndef CPP_PRODUCT	/* GWB le 23/10/2007 */
		treeview_configuration();

		Context.menufont = 2;
		Context.tinyfont = 8;

		reset_context();
		allocate_tree_managers();
		allocate_tool_managers();
		initialise_production();
#endif
		/* --------------------------------------------- */
		/* Code added to allow default style information */
		/* to be loaded for use by the new forms editor	 */
		/* active widget cursor display mechanisms.	 */
		/* IJM 12/9/2006				 */
		/* --------------------------------------------- */
		if (!( stylename = confgetenv("SINGSTYLE") ))		
			stylename = _SING_STYLESHEET;
		(void) load_visual_style(stylename,strlen(stylename));
		use_widget_cursor();

#ifdef CPP_PRODUCT
		cpp_main();
#else
		configure_console(1,1,1,1,0);
		draw_console();
#ifdef	UNIX
		visual_command_shell_create(&Context.VisualShell);
#endif
		CameraWorkOut(aptr);
#ifdef	UNIX
		visual_command_shell_remove(Context.VisualShell);
#endif
		drop_DeskTop();
#endif	/* CPP_PRODUCT */
#ifndef CPP_PRODUCT	/* GWB le 23/10/2007 */
		release_production();
		liberate_tool_managers();
		liberate_tree_managers();
		release_widget_types();
#endif
		drop_FontTable();
		release_images();
		terminate_style();
		release_style_trace();
		(void) close_graphics(og);
		drop_context();
		}
	else	{
		close_graphics(og);
		printf("\nerror opening graphics\n");
		}
	liberate_sing_other();
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
				xml_put_Form( Context.Form->loadname, Context.Form, "sing.dtd" );
				drop_DeskTop();
				}			
			continue;
			}
		}
	return(argc);
}


public	int	compiler(int argi, int argc, char * argv[] )
{
	void *	kptr;
	int	language=_GENERATE_ABAL;
	int	verboser=0;
	int	success=0;
	int	projectstate=0;
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
						case	'v'	:
						case	'V'	:
							verboser = 1;
							continue;
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

						case	'p'	:
						case	'P'	:
							language = _GENERATE_PHP;
							continue;
						case	'b'	:
						case	'B'	:
							language = _GENERATE_BIFS;
							continue;
						case	'l'	:
						case	'L'	:
							language = _GENERATE_LASER;
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

			Context.compiling = (verboser+1);
			SystemD = 0;

			if ( verboser ) {
				printf("loading project : %s\r\n",argv[argi]);
				}

			allocate_tree_managers();
			initialise_production();

			if (!( kptr = load_Project( argv[argi],_INHIBIT_REFRESH | _INHIBIT_PROPERTIES) ))
				return( error_message(argc,"error: loading" , argv[argi] ) );
			else	Context.Camera = kptr;

			if ( consult_style_trace() )
				printf("warning: style errors : \r\n",argv[argi]);

			if ( verboser )
				printf("compiling project : %s\r\n",argv[argi]);

			Context.language = language;
			configure_translation("E","E");
			if (!( build_Camera(kptr) ))
				OperationStatus = 1;
			else	OperationStatus = 0;

			if ( OperationStatus )
				printf("error: production failure : %s\r\n",argv[argi]);
			else if ( verboser )
				printf("production completed : %s\r\n",argv[argi]);

			terminate_Camera( Context.Camera );
			Context.Camera = (void *) 0;

			release_production();
			liberate_tree_managers();
			drop_DeskTop();

			}
		}
	drop_FontTable();
	drop_configuration();
	release_style_trace();
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
#ifdef	ABAL32A
				use_animation_script(aptr);
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
	int   ret;

	texting = *textchoose;
	initialise_file_manager();
#ifdef CPP_PRODUCT	/* GWB le 22/10/2007 */
	return(operation(0,argc,argv));
#else
#ifdef WIN32
	initerm_graphic();
#endif
	if ( argc == 1 )
		ret = ( banner() );
	else if ((argi = commandline(argc,argv)) < argc )
		ret = ( operation(argi,argc,argv) );
	else	ret = (OperationStatus);

#ifdef WIN32
	finterm(0);
#endif
	return ret;
#endif
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

public void charger_context_file_path()
{
	char *	dptr;
	char *	pptr;
	char *	getcwd();
	int r_pptr=0,i;

	if (!( pptr = getcwd(Context.string_buffer,Context.string_buffer_length))) {
#ifdef WIN32
		/* FUCK what about the other drives */
		/* -------------------------------- */
		if (!(pptr=allocate_string("c:\\"))) 
			return;
#else
		if (!(pptr=allocate_string("/"))) 
			return;
#endif
		r_pptr=1;
		}

	for (i=0; i < WIDGET_FILE_LIMIT; i++ ) {
		if ( Context.file_path[i] )
			Context.file_path[i] = liberate( Context.file_path[i] );
		}

	Context.file_path[WIDGET_FILE_ANY]=allocate_string(pptr);
	if ( method_is_valid((dptr = application_source_production())) )
		Context.file_path[WIDGET_FILE_AS]=dptr;
	else	Context.file_path[WIDGET_FILE_AS]=allocate_string(pptr);

	if ( method_is_valid((dptr = application_object_production())) )
		Context.file_path[WIDGET_FILE_AT]=dptr;
	else	Context.file_path[WIDGET_FILE_AT]=allocate_string(pptr);

	if ( method_is_valid((dptr = application_forms_folder())) )
		Context.file_path[WIDGET_FILE_XML]=dptr;
	else 	Context.file_path[WIDGET_FILE_XML]=allocate_string(pptr);

	Context.file_path[WIDGET_FILE_HTM]=allocate_string(pptr);
	Context.file_path[WIDGET_FILE_CSS]=allocate_string(pptr);

	if ( method_is_valid(SingConf->imagepath) )	{
		Context.file_path[WIDGET_FILE_JPG]=allocate_string(SingConf->imagepath);
		Context.file_path[WIDGET_FILE_GIF]=allocate_string(SingConf->imagepath);
		Context.file_path[WIDGET_FILE_PNG]=allocate_string(SingConf->imagepath);
		Context.file_path[WIDGET_FILE_BMP]=allocate_string(SingConf->imagepath);
		Context.file_path[WIDGET_FILE_RGB]=allocate_string(SingConf->imagepath);
		}
	else	{
		Context.file_path[WIDGET_FILE_JPG]=allocate_string(pptr);
		Context.file_path[WIDGET_FILE_GIF]=allocate_string(pptr);
		Context.file_path[WIDGET_FILE_PNG]=allocate_string(pptr);
		Context.file_path[WIDGET_FILE_BMP]=allocate_string(pptr);
		Context.file_path[WIDGET_FILE_RGB]=allocate_string(pptr);
		}

	if ( method_is_valid(SingConf->iconpath) ) {
		Context.file_path[WIDGET_FILE_ICO]=allocate_string(SingConf->iconpath);
		}
	else	{
		Context.file_path[WIDGET_FILE_ICO]=allocate_string(pptr);
		}
	
	if ( method_is_valid(SingConf->fontpath) )  {
		Context.file_path[WIDGET_FILE_FMF]=allocate_string(SingConf->fontpath);
		}
	else	{
		Context.file_path[WIDGET_FILE_FMF]=allocate_string(pptr);
		}
	
	Context.file_path[WIDGET_FILE_C]=allocate_string(pptr);
	Context.file_path[WIDGET_FILE_H]=allocate_string(pptr);
	Context.file_path[WIDGET_FILE_3D]=allocate_string(pptr);
	Context.file_path[WIDGET_FILE_SNG]=allocate_string(pptr);	
	Context.file_path[WIDGET_FILE_ANI]=allocate_string(pptr);
	Context.file_path[WIDGET_FILE_CFG]=allocate_string(pptr);

	if ( method_is_valid((dptr = application_object_production())) )
		Context.file_path[WIDGET_FILE_OBJ]=dptr;
	else	Context.file_path[WIDGET_FILE_OBJ]=allocate_string(pptr);

	Context.file_path[WIDGET_FILE_TXT]=allocate_string(pptr);

	if (r_pptr) liberate(pptr);

	return;

}

#ifdef CPP_PRODUCT
void visual_set_size(int w,int h)
{
#ifdef WIN32
windows_resize(w+8,h+33);
#else
activatepixel(w,h,0);	// BiosMode=0
#endif
}

void visual_show_window()
{
#ifdef WIN32
windows_show_window();
#endif
}
#endif



