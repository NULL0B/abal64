#include <stdio.h>

#include "zalloc.h"

#include "stdfont.h"
#include "ztrace.c"

static	char	*		BiosMode0="\4=BIOSMODE";
static	char	*		BiosModeN="\3=BIOSMODE";
static  char    *		FontName0="IS\\FONTS\\FONT0.FMF\0                               ";
static  char    *		FontNameN="IS\\FONTS\\FONTN.FMF\0                               ";

static	char	*		PaletteName="IS\\IMAGES\\STANDARD.RGB\0                         ";
static	struct standard_font * 	TextFont=(struct standard_font *) 0;
static	int			FontNumber=-1;

	int			gready=-1;

static	struct graphical {
	int	mode;
	int	width;
	int	height;
	int	foreground;
	int	background;
	int	hidden;
	int	stcs_lines;
	int	stcs_columns;
	int	stcs_colour;
	int	stcs_console;
	int	stcs_pixel_x;
	int	stcs_pixel_y;

	} Device = {
	-1,0,0,0,0,0,
	0,0,0,0,
	800,600
	};

//	-----------------------------------------
//	Amenesik / Sologic Console Input / Output Functions
//	-----------------------------------------

int	consoletype()
{
	char	buffer[16];
	int	bufbytes=0;
	_asm	{
		push	ds
		push	bx
		push	cx
		lea	bx,buffer
		mov	ax,ss
		mov	ds,ax
		mov	cx,16
		mov	ax,01C01H
		int	110
		xor	ch,ch
		mov	bufbytes,cx
		pop	cx
		pop	bx
		pop	ds
		}
	Device.stcs_lines   = (buffer[0] & 0x00FF);
	Device.stcs_columns = (buffer[1] & 0x00FF);
	Device.stcs_colour  = (buffer[6] & 0x00FF);
	Device.stcs_console = (buffer[7] & 0x00FF);
	if ( bufbytes < 13 ) {
		if (Device.stcs_console != 0)
			return(0);
		else	return(1);
		}
	else 	{
		Device.stcs_pixel_x = ((buffer[9] & 0x00FF) | ((buffer[10] & 0x00FF) << 8));
		Device.stcs_pixel_y = ((buffer[11] & 0x00FF) | ((buffer[12] & 0x00FF) << 8));
		if ((Device.stcs_pixel_x != 0)
		&&  (Device.stcs_pixel_y != 0))
			return(1);
		else	return(0);
		}
}

int	console_number()
{
	return( Device.stcs_console );
}

char *	rt_init=(char *) 0;
void	rt_error()	{ return; }

void	setscreenmode( int mode )
{
	switch ((Device.mode=mode)) {
		case	0 : Device.width = 320; Device.height=200; break;
		case	1 : Device.width = 640; Device.height=400; break;
		case	2 : Device.width = 640; Device.height=480; break;
		case	3 : Device.width = 800; Device.height=600; break;
		case	4 : Device.width =1024; Device.height=768; break;
		case	5 : Device.width =1280; Device.height=1024; break;
		case	6 : Device.width =1280; Device.height=1280; break;
		default	  : setscreenmode(3);
		}
	return;
}

void	set_bios_mode( char * mptr )
{
	int	gmode=0;
	while ( *mptr ) {
		if ((*mptr >= '0') && ( *mptr <= '9'))
			gmode = ((gmode * 10) + ( *(mptr++) - '0'));
		else	break;
		}
	if (( gmode >= 0 ) && ( gmode <=6 ))
		setscreenmode( gmode );
	return;
}
	
char *	allocate_string( char * sptr )
{
	char *	rptr;
	if ((rptr = allocate( strlen(sptr) + 1 )) != (char *) 0)
		strcpy(rptr,sptr);
	return(rptr);
}


#include "zvga.c"
#include "stdfont.c"

int	get_mouse_column()
{
	if ( gready != -1 )
		return( ((aed_mimo_column() / TextFont->width )+1));
	else	return( get_mimo_col() );
}

int	get_mouse_line()
{
	if ( gready != -1 )
		return( ((aed_mimo_row() / TextFont->height )+1));
	else	return( get_mimo_lin() );
}

int	get_mouse_event()
{
	return( get_mimo_type() );
}

int	get_mouse_button()
{
	return( get_mimo_par() );
}


void	x_putch(int c)
{
	if ( gready != -1 )
		PixelPutC((c&0x00FF));
	else	{
		_asm	{
			push	cx
			push	ax
			mov	ah,011H
			mov	cx,c
			int	110
			pop	ax
			pop	cx
			}
		}
	return;
}

void	editor_bell()
{
	x_putch(7);
	return;
}

void	x_cprintf( char * cptr )
{
	while ( *cptr )
		x_putch( *(cptr++) );
	return;
}

int	conf( int v )
{
	switch (v) {
		case	 2 : 
			if ( gready != -1 )
				return( Device.width  / TextFont->width  );
			else	return( Device.stcs_columns );

		case	 1 : 
			if ( gready != -1 )
				return((Device.height / TextFont->height)-2);
			else	return( Device.stcs_lines );
	
		case     9 : return( 0 );
		case	11 : return( 0 );

		case	14 : return( Device.stcs_colour );

		/* CONF de 66 : should the application use graphics */
		/*              0 means NO			    */
		/*            ! 0 means YES			    */
		/* ------------------------------------------------ */
		case	66 :  return(1); /* workval1 = conf_sixty_six(); */

		case	67 :  return(1); /* workval1 = conf_sixty_seven(); */

			/* Graphical Dimensions or Screen Resolution */
			/* ----------------------------------------- */

		case	68 :	/* Screen Height : Row Count */
			return(Device.height);
			/* workval1 = conf_sixty_eight(); */

		case	69 :	/* Screen Width : Column Count */
			return(Device.width);
			/* workval1 = conf_sixty_nine(); */

		}	
	return(0);
}

int	x_getch()
{
	return(mimo_getch());
}

int	x_kbhit()
{
	return(mimo_kbhit());
}

void	x_foregr(int c)
{
	Device.foreground = c;
	if ( gready != -1 )
		cicocolour(Device.foreground,Device.background);
	else	{
		x_putch(27);
		x_putch('r');
		c = ((c & 0x000F) | 0x0030);
		if ( c > 0x003A )
			c += 7;
		x_putch( c );
		}
	return;
}

void	x_backgr(int c)
{
	Device.background = c;
	if ( gready != -1 ) 
		cicocolour(Device.foreground,Device.background);
	else	{
		x_putch(27);
		x_putch('s');
		c = ((c & 0x0007) | 0x0030);
		x_putch( c );
		}
	return;
}

void	x_atb( int atbid )
{
	switch ( atbid ) {
		case 0 : 
			 atbid = 'a'; break;
		case 1 : atbid = 'p'; break;
		case 2 : atbid = 'b'; break;
		case 3 : atbid = 'c'; break;
		case 4 : atbid = 'd'; break;
		case 5 : atbid = 'e'; break;
		case 6 : atbid = 'h'; break;
		case 7 : atbid = 'i'; break;
		case 8 : atbid = 'j'; break;
		case 9 : atbid = 'O'; break;
		case 10: atbid = 'y'; break;
		case 11: atbid = 'z'; break;
		case 12: atbid = 'k'; break;
		case 13: atbid = 'l'; break;
		case 14: atbid = 'm'; break;
		case 15: atbid = 'n'; break;
		case 16: atbid = 'q'; break;
		case 17: atbid = 'r'; break;
		case 18: atbid = 's'; break;
		case 19: atbid = 't'; break;
		case 20: atbid = 'Q'; break;
		case 21: atbid = 'K'; break;
		case 22: atbid = 'J'; break;
		case 23: atbid = 'L'; break;
		case 24: atbid = 'M'; break;
		case 25: atbid = 'w'; break;
		case 26: atbid = 'v'; break;
		case 27: atbid = '*'; break;
		case 28: atbid = '#'; break;
		case 29: atbid = 'x'; break;
		case 30: atbid = '>'; break;
		case 31: atbid = '<'; break;
		default: return;
		}

	if ( gready == -1 ) {
		x_putch(27);
		x_putch( atbid );
		}
	else if (  atbid == 'a' ) {
		cicocolour(_DEFAULT_GUI_BLACK,_DEFAULT_GUI_NEUTRAL);
		}
	else if (atbid == 'b' ) {
		cicocolour(_DEFAULT_GUI_LIGHT_HIGH,_DEFAULT_GUI_DARK);
		}
	else	{
		x_putch(27);
		x_putch( atbid );
		}
	return;
}

void	x_clear()
{
	if ( gready != -1 ) 
		filzone(0,0,Device.width,Device.height,_DEFAULT_GUI_NEUTRAL);
	else	x_putch(0x000C);
	return;

}

void	close_console()
{
	terminate_editor_mouse();
	if ( gready != -1 ) {
		if ( gready == 1 )
			liberatepixel();
		else	disconnectpixel(0);
		gready = -1;
		}
	x_clear();
	return;
}



void	inifont(char * fontzero, char * fontn)
{
	if ( fontzero )
		FontName0=fontzero;

	if ( fontn )
		FontNameN=fontn;
	return;
}

int	change_font( char * fname )
{
	struct standard_font * fptr;

	if (!( fname ))
		return(0);
	else if (!( *fname ))
		return(0);
	else if (!(fptr = load_font( fname )))
		return(0);
	else 	{
		TextFont = drop_font( TextFont );
		FontNumber = use_font((TextFont = fptr ));
		return(1);
		}
}

int	open_console()
{


	initialise_font_manager();

	/* Test if graphics is allowed */
	/* --------------------------- */
	if ( consoletype() != 0) {

		/* Attempt to start the graphics */
		/* ----------------------------- */
		if ( Device.mode == -1 ) {
			if (!( console_number() ))
				setscreenmode( *BiosMode0 );
			else	setscreenmode( *BiosModeN );
			}

		if ( initialisepixel( (Device.mode|256) ) != -1 )
			gready = 1;

		else if ((Device.mode = connectpixel(256,(void *) 0, (void *) 0)) != -1) {
			setscreenmode( Device.mode );
			gready = 2;
			}

		if ( gready != -1 )
			load_palette(PaletteName);

		}

	initialise_editor_mouse();

	if ( gready != -1 ) {
		if (!( console_number() )) {
			if ((TextFont = load_font( FontName0 )) != (struct standard_font *) 0)
				FontNumber = use_font( TextFont );
			}
		else if ((TextFont = load_font( FontNameN )) != (struct standard_font *) 0)
			FontNumber = use_font( TextFont );

		}

	x_foregr(7); x_backgr(4);

	return(2);
}

void	x_bstart()
{
	if (!( Device.hidden )) {
		Device.hidden = 1;
		hide();
		}
	return;
}

void	x_bflush()
{
	if ( Device.hidden ) {
		Device.hidden = 0;
		show( 0,0, Device.width, Device.height );
		}
	return;
}


void	x_pos( int l, int c)
{ 
	if ( gready != -1 )
		cicocurser(c,l);
	else	{
		x_putch(0x001B);
		x_putch('f');
		_asm		{
			mov	ax,l
			xor	ah,ah
			add	ax,01FH
			mov	l,ax
			mov	ax,c
			xor	ah,ah
			add	ax,01FH
			mov	c,ax
			}
		x_putch(c);
		x_putch(l);
		}
	return; 
}


