#ifndef	_edwindow_c
#define	_edwindow_c

#include "edrelief.c"
#include "edmouse.h"

static	char * 	integer_parameter( char * sptr, int * vptr )
{
	*vptr = 0;
	while ( *sptr != 0 ) {
		if (( *sptr >= '0') && ( *sptr <= '9' ))
			*vptr = ((*vptr * 10) + ( *(sptr++) - '0'));
		else	break;
		}
	return( sptr );
}


struct	editor_window_manager {
	int	x;	/* x position of top left corner */
	int	y;	/* y position of top left corner */
	int	w;	/* width of window in pixels	 */
	int	h;	/* height of window in pixels	 */
	int	frame;	/* frame to use			 */
	int	font;	/* font to uses			 */
	int	fontwidth;
	int	fontheight;
	int	state;	/* state of window usage	 */
	int	topline;/* display top frame		 */
	int	scrollbar; /* width of scroll bar	 */
	int	isfocus;
	int	scrollbox;
	} EditorWindow = { 
		0,0,0,0,
		1,1,0,0,0,3,0,0,0 };

int	is_window_editor()
{
	if (( EditorWindow.w > 0 )
	||  ( EditorWindow.h > 0 ))
		return((EditorWindow.topline ? 3 : 1));
	else	return(0);
}

int	get_status_line()
{
	int	status;
	if (!( status = is_window_editor()))
		return(1);
	else if ( status > 1 )
		return(1);
	else	return(0);
}

public	void	window_messages()
{
	if (!( is_window_editor() ))
		show_messages();
	else if ( EditorWindow.topline )
		show_messages();
	return;
}

public	void	window_characteristics()
{
	if ( is_window_editor() )
		screen_characteristics(EditorWindow.topline);
	else	screen_characteristics(1);
}

static	void	graphical_rule(int atlin, int atcol, int nbcol )
{
	int	fh;
	int	fw;
	int	atx;
	int	aty;
	int	nbx;
	pos(atlin,atcol);
	Xatb(21);
	fw = guifontsize(EditorWindow.font); fh = (fw >> 8 ); fw &= 0x00FF;
	atx = ((atcol-1) * fw)+EditorWindow.x;
	aty = ((atlin-1) * fh)+EditorWindow.y+(fh/2);
	nbx = ((nbcol+1) * fw);
	relief_line( atx,aty,nbx,EditorWindow.frame);
	return;
}

void	draw_editor_scrollbar()
{
	if ( EditorWindow.scrollbar ) {
		if ( EditorWindow.scrollbox ) {
			relief_frame( 
				EditorWindow.x+(EditorWindow.w-EditorWindow.scrollbar),
				EditorWindow.y-1, EditorWindow.scrollbar+4,EditorWindow.h+4,
				EditorWindow.scrollbox);
			}
		visual_scrollbar(
			EditorWindow.x+(EditorWindow.w-EditorWindow.scrollbar)+2,
			EditorWindow.y+2, EditorWindow.scrollbar,EditorWindow.h-1,
			EditorWindow.font,16,15,
			numlgn,(EditorWindow.h/EditorWindow.fontheight),
			maxnumlgn,(EditorWindow.isfocus | 3 ) );
		show_line_numbering();
		}
	return;
}



void	draw_window_frame()
{
	int	fh;
	int	fw;
	int	atx;
	int	aty;
	int	nbx;
	int	nby;
	fw = guifontsize(EditorWindow.font); fh = (fw >> 8 ); fw &= 0x00FF;
	if ( EditorWindow.x > fw )
		atx =(EditorWindow.x-fw);
	else if (!( EditorWindow.x ))
		return;
	else	atx = 0;

	if ( EditorWindow.y > (fh/2) )
		aty =(EditorWindow.y-(fh/2));
	else if (!( EditorWindow.y ))
		return;
	else	aty = 0;
	nbx = (EditorWindow.w + (2*fw));
	nby = (EditorWindow.h + fh);
	relief_frame( atx,aty,nbx,nby, EditorWindow.frame);
}


static	void	refresh_file_window()
{
	BYTE 	autrefic[LGMXNOM];
	ULONG go_ligne=1L;
	BPTR	pcom="O";
	window_characteristics();
	(void) WizzardOfOz( pcom, &go_ligne,autrefic);
	if ( EditorWindow.topline ) {
		draw_editor_screen();
		}
	return;
}


int	aed_mimo_row()
{
	int	r;
	r = get_mimo_row();

	if (r > EditorWindow.y )
		return( r - EditorWindow.y );
	else	return( 0 );
}


int	aed_mimo_column()
{
	int	c;

	c = get_mimo_column();

	if (c > EditorWindow.x )
		return( c - EditorWindow.x );
	else	return( 0 );
}

static	int	use_editor_scrollbar()
{
	int maxlgn=(EditorWindow.h/EditorWindow.fontheight);
	int aty=aed_mimo_row();
	int toy=aed_mimo_row();

	if ((toy = aed_mimo_row()) < EditorWindow.scrollbar ) {
		do 	{
			while(x_getch() != 256);
			}
	 	while (get_mimo_type() != _MIMO_UP);
		editorPageUp();
		draw_editor_scrollbar();		
		return(1);
		}

	else if ( toy > (EditorWindow.h-EditorWindow.scrollbar)) {
		do 	{
			while(x_getch() != 256);
			}
	 	while (get_mimo_type() != _MIMO_UP);
		editorPageDown();
		draw_editor_scrollbar();		
		return(1);
		}

	EditorWindow.isfocus = 0x0100;
	draw_editor_scrollbar();		
	do 	{
		while(x_getch() != 256);
		if ((toy = aed_mimo_row()) < EditorWindow.scrollbar )
			continue;
		else if ( toy > (EditorWindow.h-EditorWindow.scrollbar))
			continue;
		else	toy -= EditorWindow.scrollbar;
		aty = numlgn;
		aty = ((toy * maxnumlgn) / (EditorWindow.h - (2*EditorWindow.scrollbar)));

		if (aty < 1) 
			aty = 1;

		else if ( aty > maxnumlgn )
			aty = maxnumlgn;

		if ( numlgn != aty ) {
			off_cursor();
			if (!( poslgn(0,aty) ))
				draw_editor_scrollbar();		
			on_cursor();
			}
		}
	while (get_mimo_type() != _MIMO_UP);
	EditorWindow.isfocus = 0;
	draw_editor_scrollbar();		
	return(1);
}

int	is_editor_scrollbar_event()
{
	int	atx;
	int	aty;
	if (!( EditorWindow.scrollbar ))
		return(0);
	else if ((atx = get_mimo_column()) < EditorWindow.x )
		return(0);
	else if ((atx = aed_mimo_column()) < (EditorWindow.w-EditorWindow.scrollbar) )
		return(0);
	else	return( use_editor_scrollbar() );
}

int	ned_mouse_line()
{
	int	fh;
	int	aty;
	if ( flg_cico < 2 )
		return( get_mouse_line() );
	else	{
		fh = ((guifontsize(EditorWindow.font) >> 8 ) & 0x00FF);
		aty = aed_mimo_row();
		return( (aty / fh)+1);
		}
}

int	ned_mouse_column()
{
	int	fw;
	int	atx;
	if ( flg_cico < 2 )
		return( get_mouse_column() );
	else	{
		fw = (guifontsize(EditorWindow.font)  & 0x00FF);
		atx = aed_mimo_column();
		return( (atx / fw)+1);
		}
}


int	use_editor_window( )
{
	if (!( EditorWindow.state & 1 )) {
		if ( EditorWindow.topline ) {
			draw_editor_screen();
			}
		EditorWindow.state = 3;
		return(0);
		}
	if ( EditorWindow.state & 2 )
		return(0);
	else	EditorWindow.state |= 2;

	if ( flg_cico < 2 ) {
		if ( EditorWindow.topline ) {
			draw_editor_screen();
			}
		EditorWindow.state = 3;
		return(0);
		}

	use_base_font(EditorWindow.font);
	cicopalette(15,22);

	if ((!( EditorWindow.w ))
	||  (!( EditorWindow.h ))) {
		if (!(
			cicopagemargins(
				EditorWindow.x,EditorWindow.w,
				EditorWindow.y,EditorWindow.h 
				)
			)) 
			refresh_file_window();
		return(0);
		}
	else 	{
		if (!(
			cicowindow( 	
				EditorWindow.x,EditorWindow.y,
				EditorWindow.w-EditorWindow.scrollbar,EditorWindow.h
				)
			 )) 
			refresh_file_window();
		return(0);
		}
}

int 	editor_window_connection( char * aptr )
{
	EditorWindow.state =
	EditorWindow.frame = 0;
	EditorWindow.x =
	EditorWindow.y =   
	EditorWindow.w =   
	EditorWindow.h = 0;

	if (!( aptr ))	
		return(0);
	else if (!( aptr = integer_parameter( aptr, &EditorWindow.x ) ))
		return( 30 );
	else if ( *(aptr++) != ':' )
		return( 30 );
	else if (!( aptr = integer_parameter( aptr, &EditorWindow.y ) ))
		return( 30 );
	else if ( *(aptr++) != ':' )
		return( 30 );
	else if (!( aptr = integer_parameter( aptr, &EditorWindow.w ) ))
		return( 30 );
	else if ( *(aptr++) != ':' )
		return( 30 );
	else if (!( aptr = integer_parameter( aptr, &EditorWindow.h ) ))
		return( 30 );
	else if ( *(aptr++) != ':' )
		return( 30 );
	else if (!( aptr = integer_parameter( aptr, &EditorWindow.frame ) ))
		return( 30 );
	else if ( *(aptr++) != ':' )
		return( 30 );
	else if (!( aptr = integer_parameter( aptr, &EditorWindow.font ) ))
		return( 30 );
	else if ( *(aptr++) != ':' )
		return( 30 );
	else if (!( aptr = integer_parameter( aptr, &EditorWindow.topline ) ))
		return( 30 );
	else if ( *(aptr++) != ':' )
		return( 30 );
	else if (!( aptr = integer_parameter( aptr, &EditorWindow.scrollbar ) ))
		return( 30 );
	else if ( *(aptr++) != ':' )
		EditorWindow.scrollbox = 0;
	else if (!( aptr = integer_parameter( aptr, &EditorWindow.scrollbox ) ))
		EditorWindow.scrollbox = 0;

	if (!( EditorWindow.font ))
		EditorWindow.font = 1;

	EditorWindow.fontwidth  = guifontsize(EditorWindow.font );
	EditorWindow.fontheight = (EditorWindow.fontwidth >> 8);
	EditorWindow.fontwidth  &= 0x00FF;
	EditorWindow.state=1;
	return(0);

}

#endif	/* _edwindow_c */
	/* ----------- */





























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































