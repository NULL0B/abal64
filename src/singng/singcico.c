#ifndef	_singcico_c
#define	_singcico_c

#include "singcico.h"

public	unsigned short prndest=1;

private	struct	gigo_manager	Gigo;

public	int	set_gigo_cursor(int v)
{
	int	previous=Gigo.cursorstyle;
	if (( v > 0 ) && ( v <= _GIGO_CURSOR_OUTLINE ))
		Gigo.cursorstyle=v;
	return( previous );
}

/*	Set Mouse Mask to lb,hb		*/
/*	-----------------------		*/
private	void	esc_Z(int l, int h )
{
	set_mimo_mask(((l&0x00FF) | ((h & 0x00FF)<<8)));
	return;
}

/*	Convert Uppercase	*/
/*	-----------------	*/
private	void	esc_i()
{
	return;
}

/*	Convert	LowerCase	*/
/*	-----------------	*/	
private	void	esc_j()
{
	return;
}

/*	Set Cursor position to C,L	*/
/*	--------------------------	*/
private	void	esc_f(int c, int l)
{
	Gigo.column = (c-0x001F);
	Gigo.line   = (l-0x001F);
	return;
}

/*	switch text cursor off		*/
/* 	----------------------		*/
private	void	esc_w()
{
	Gigo.cursing &= ~1;
	return;
}

/*	switch  text cursor on		*/
/* 	----------------------		*/
private	void	esc_v()
{
	Gigo.cursing |= 1;
	return;
}

/*	switch  OP  cursor off		*/
/* 	----------------------		*/
public 	int 	esc_op_w()
{
	Gigo.cursing &= ~2;
	return(1);
}

/*	switch   OP  cursor on		*/
/* 	----------------------		*/
public 	int 	esc_op_v()
{
	Gigo.cursing |= 2;
	return(1);
}

/*	Reset atributs and colours	*/
/*	--------------------------	*/
private	void	esc_a()
{
	Gigo.atribut    = 0;
	Gigo.foreground = Gigo.fg;
	Gigo.background = Gigo.washground;
	return;
}

/*	Activate Inverse Video		*/
/*	----------------------		*/
private	void	esc_b()
{
	Gigo.atribut    = 0;
	Gigo.foreground = Gigo.bg;
	Gigo.background = Gigo.fg;	
	return;
}

/*	Activate Blinking		*/
/*	-----------------		*/
private	void	esc_c()
{
	Gigo.atribut    |= _GIGO_BLINK;
	return;
}

/*	Activate Underline	*/
/*	------------------	*/
private	void	esc_d()
{
	Gigo.atribut    |= _GIGO_UNDERLINE;
	return;
}

/*	Activate Halflight	*/
/*	------------------	*/
private	void	esc_e()
{
	Gigo.atribut    |= _GIGO_LOWLIGHT;
	return;
}

/*	Activate HighLight	*/
/*	------------------	*/
private	void	esc_h()
{
	Gigo.atribut    |= _GIGO_HIGHLIGHT;
	return;
}

/*	Activate Compressed	*/
/*	-------------------	*/
private	void	esc_x()
{
	Gigo.atribut    |= _GIGO_COMPRESSED;
	return;
}

/*	Activate Preferred 	*/
/*	------------------ 	*/
private	void	esc_p()
{
	Gigo.atribut    |= _GIGO_PREFERRED;
	return;
}

/*	Activate Italic		*/
/*	---------------		*/
private	void	esc_y()
{
	Gigo.atribut    |= _GIGO_ITALIC;
	return;
}

private	void	set_background_colour(int c )
{
	if ( c > 15 ) {
		Gigo.bg = Gigo.background = c;
		}
	else	{
		Gigo.bg = Gigo.background = Gigo.painter[c];
		}
	return;
}

private	void	set_washground_colour(int c )
{
	if ( c > 15 ) {
		Gigo.bg = Gigo.washground = c;
		}
	else	{
		Gigo.bg = Gigo.washground = Gigo.painter[c];
		}
	return;
}

private	void	set_foreground_colour(int c )
{
	if ( c > 15 ) {
		Gigo.fg = Gigo.foreground = c;
		}
	else	{
		Gigo.fg = Gigo.foreground = Gigo.painter[c];
		}
	return;
}

/*	Set Foreground Colour to C	*/
/*	--------------------------	*/
private	void	esc_r(int c)
{
	int	dath = (c > 0x003A ? ((c - 7) & 0x000F) : (c & 0x000F));
	set_foreground_colour( dath );
	return;
}

/*	Set BackGround Colour to C	*/
/*	--------------------------	*/
private	void	esc_s(int c)
{
	int	dath = (c > 0x003A ? ((c - 7) & 0x000F) : (c & 0x000F));
	set_background_colour( dath );
	return;
}

/*	Set Screen     Colour to C	*/
/*	--------------------------	*/
private	void	esc_n(int c)
{
	int	dath = (c > 0x003A ? ((c - 7) & 0x000F) : (c & 0x000F));
	set_washground_colour(dath);
	return;
}

/*	cico mode scroll	*/
/*	----------------	*/
private	void	esc_t()
{
	Gigo.scrolling = 1;
	return;
}

/*	cico mode page 		*/
/*	--------------		*/
private	void	esc_u()
{
	Gigo.scrolling = 0;
	return;
}

/*	Clear to End of Line	*/
/*	--------------------	*/
private	void	esc_K()
{
	if ((!( Gigo.line ))
	|| (!( Gigo.column )))
		return;
	if (( Gigo.line   <= Gigo.lines )
	&&  ( Gigo.column <= Gigo.columns ))
		filzone(((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
			((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin,
			(Gigo.width - ((Gigo.column-1)*Gigo.fontwidth)),
			/*((Gigo.columns-Gigo.column)+1)*Gigo.fontwidth,*/
			Gigo.fontheight,
			Gigo.washground);
	return;
}

private	void	xgr_cursor(int mode)
{
	switch ( mode ) {

		case	1 :	/* Block XOR */

			switch ( Gigo.cursorstyle ) {
				case	_GIGO_CURSOR_BLOCK	:
					xorzone(((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
						((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin,
						Gigo.fontwidth,Gigo.fontheight,
						0x00FF );
					break;

				case	_GIGO_CURSOR_VLINE	:
					xorzone(((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
						((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin,
						2,Gigo.fontheight,
						0x00FF );
					break;

				case	_GIGO_CURSOR_HLINE	:
					xorzone(((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
						((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin+(Gigo.fontheight-2),
						Gigo.fontwidth,2,0x00FF );
					break;

				case	_GIGO_CURSOR_OUTLINE	:
					xorzone(((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
						((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin,
						Gigo.fontwidth,1,0x00FF );
					xorzone(((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
						((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin+(Gigo.fontheight-1),
						Gigo.fontwidth,1,0x00FF );
					xorzone(((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
						((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin,
						1,Gigo.fontheight,0x00FF );
					xorzone(((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin+(Gigo.fontwidth-1),
						((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin,
						1,Gigo.fontheight,0x00FF );
					break;

				}	
			}
	return;
}

/*	Clear to End of Page	*/
/*	--------------------	*/
private	void	esc_J()
{
	esc_K();	
	if ( Gigo.line < Gigo.lines )
		filzone( Gigo.leftmargin, 
			(Gigo.line*Gigo.fontheight)+Gigo.topmargin,
			Gigo.width, 
			(Gigo.height - (Gigo.line*Gigo.fontheight)),
			Gigo.washground);
	return;
}

private	void	movezone(int tox, int toy, int fromx, int fromy, int nbx, int nby )
{
	int y;
	if  ((!( Gigo.rbuffer ))
	&&   (!( Gigo.rbuffer = allocate( Gigo.width+16 ) )))
		return;
	if ( toy < fromy ) {
		for (y=0; y < nby; y++ ) {
			getzone(fromx,fromy+y,nbx,1,Gigo.rbuffer);
			putzone(tox,toy+y,nbx,1,Gigo.rbuffer);
			}
		}
	else	{

		for (y=nby; y > 0 ; y-- ) {
			getzone(fromx,fromy+y,nbx,1,Gigo.rbuffer);
			putzone(tox,toy+y,nbx,1,Gigo.rbuffer);
			}
		}
	return;
}

/*	Insert Line  		*/
/*	-----------		*/
private	void	esc_L()
{
	if ( Gigo.line < Gigo.lines )
		movezone(	Gigo.leftmargin,  (Gigo.line*Gigo.fontheight)+Gigo.topmargin,
				Gigo.leftmargin,  ((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin,
				Gigo.width,
				(Gigo.height - (Gigo.line*Gigo.fontheight)));

	filzone(Gigo.leftmargin,Gigo.topmargin+((Gigo.line-1)*Gigo.fontheight),Gigo.width,Gigo.fontheight,Gigo.washground);
	return;
}

/*	Delete Line  		*/
/*	-----------		*/
private	void	esc_M()
{
	if ( Gigo.line < Gigo.lines )
		movezone(	Gigo.leftmargin,Gigo.topmargin+ ((Gigo.line-1)*Gigo.fontheight),
				Gigo.leftmargin,Gigo.topmargin+ (Gigo.line*Gigo.fontheight),
				Gigo.width,
				(Gigo.height - (Gigo.line*Gigo.fontheight)));

	filzone(Gigo.leftmargin,Gigo.topmargin+((Gigo.lines-1)*Gigo.fontheight),Gigo.width,
		(Gigo.height-((Gigo.lines-1)*Gigo.fontheight)),Gigo.washground);
	return;
}


private	void	scroll_up(int n)
{
	movezone(Gigo.leftmargin,Gigo.topmargin,Gigo.leftmargin,Gigo.topmargin+(n*Gigo.fontheight),Gigo.width,((Gigo.lines-n)*Gigo.fontheight));
	filzone(Gigo.leftmargin,Gigo.topmargin+((Gigo.lines-n)*Gigo.fontheight),Gigo.width,(n*Gigo.fontheight),Gigo.washground);
	return;
}

public	int	x_col(int i)
{
	return( Gigo.column );
}

public	int	x_lin(int i)
{
	return( Gigo.line );
}

public	void	x_bstart()
{
	visual_freeze();
	return;
}

public	void	x_bflush()
{
	visual_thaw(0,0,0,0);
	return;
}

public	int	conf(int n)
{
	switch ( n ) {
		case	1 : return( Gigo.lines );
		case	2 : return( Gigo.columns );
		case	14: return( 255 );
		case	11: return( 1+2+4+8 );
		case	12: return( 1+4 );
		case	9 : return( 0 );
		case	66: return( consoletype() );
		case	67: return( consoletype() );
		case	68: return( hardrows()    );
		case	69: return( hardcolumns() );
		default	  : return(0);
		}
}


public	void	x_clear()
{
	esc_f(0x0020,0x0020);
	esc_J();
	return;
}


public	int	initgigo(int width, int height )
{
	int	i;
	char *	eptr;

	prndest = 1;

	Gigo.leftmargin  = Gigo.topmargin    = 0;
	Gigo.rightmargin = Gigo.bottommargin = 0;
	Gigo.rbuffer     = (char *) 0;
	Gigo.cursorstyle = _GIGO_CURSOR_BLOCK;
	Gigo.tracing     = 0;
	Gigo.columns 	 = 80;
	Gigo.lines   	 = 24;
	Gigo.fontwidth 	 = Gigo.fontheight = 1;
	Gigo.currentfont = 0;
	Gigo.width 	 = width;
	Gigo.height 	 = height;
	Gigo.escapestate = _ESC_normal;

	for (i=0; i < 32; i++ ) Gigo.painter[i] = i;

	Gigo.painter[0] = 0;
	Gigo.painter[1] = 4; Gigo.painter[4] = 1;
	Gigo.painter[3] = 6; Gigo.painter[6] = 3;
	Gigo.painter[9] =12; Gigo.painter[12]= 9;
	Gigo.painter[11]=14; Gigo.painter[14]=11;
	esc_r(0x030);	esc_s(0x03F); 	esc_n(0x03F);
	
	esc_v();	esc_t(); 	esc_a();

	esc_f(0x20,0x20);

	Gigo.fontwidth = Gigo.fontheight = 0;
	Gigo.currentfont = 0;
	return(0);
}

public	int	fingigo()
{
	int	i;
	if ( Gigo.rbuffer ) {
		liberate( Gigo.rbuffer );
		Gigo.rbuffer = (char *) 0;
		}
	return(0);
}


public	void	x_curser(int nbx )
{
	int	temp=(((Gigo.column-1)*Gigo.fontwidth)+nbx);
	for (	Gigo.column = (((((Gigo.column-1)*Gigo.fontwidth)+nbx)/Gigo.fontwidth)+1);
		Gigo.column > Gigo.columns;
		Gigo.column -= Gigo.columns ) {
		if ( Gigo.line < Gigo.lines )
			Gigo.line++;
		else	scroll_up(1);
		}
	return;
}

public	void	cicocolour(int fg, int bg )
{
	set_foreground_colour((fg & 0x00FF));
	set_background_colour((bg & 0x00FF));
	if ( bg )
		set_washground_colour((bg & 0x00FF));
	return;
}

public	void	gigocolour(int f, int b)
{
	cicocolour(f,b);
	return;
}

public	int	cicopalette(int colour, int value )
{	
	int	result;
	if ( colour < 16 ) {
		result = Gigo.painter[colour];
		Gigo.painter[colour] = value;
		}
	else	result = colour;
	return(result);
}

public	void	cicocursor(int atc, int atl )
{
	Gigo.column = atc;
	Gigo.line   = atl;
	return;
}

public	int 	x_getch()
{
	int	result;
	if ( Gigo.cursing & 1)
		xgr_cursor(1);
	result = visual_getch();
	if ( Gigo.cursing & 1)
		xgr_cursor(1);
	return(result);
}

public	int 	x_kbhit()
{
	int	result;

	if (( Gigo.cursing & 3)==3)
		xgr_cursor(1);
	result = visual_kbhit();
	if (( Gigo.cursing & 3)==3)
		xgr_cursor(1);
	return( result );
}

public	void	x_putch(int c)
{	
	switch (Gigo.escapestate) {
		case	_ESC_normal	:	/* awaiting  escape character */
			if ( c == 27 ) {
				Gigo.escapestate = _ESC_active;
				return;
				}
			break;

		case	_ESC_active	:	/* awaiting escaped character */
			switch ((Gigo.escapecharacter = c)) {
				case	'T'	:
				case	'f'	:
				case	'Z'	:
				case	'n'	:
				case	's'	:
				case	'r'	:
					Gigo.escapestate = _ESC_parameter;
					return;
				case	'u'	:
					esc_u();
					Gigo.escapestate = _ESC_normal;
					return;
				case	't'	:
					esc_t();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'J'	:
					esc_J();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'K'	:
					esc_K();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'L'	:
					esc_L();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'M'	:
					esc_M();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'v'	:
					esc_v();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'w'	:
					esc_w();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'a'	:
					esc_a();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'b'	:
					esc_b();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'c'	:
					esc_c();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'd'	:
					esc_d();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'e'	:
					esc_e();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'h'	:
					esc_h();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'x'	:
					esc_x();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'p'	:
					esc_p();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'y'	:
					esc_y();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'>'	:
					Gigo.escapestate = _ESC_normal;
					return;
				case	'<'	:
					Gigo.escapestate = _ESC_normal;
					return;
				default		:
					Gigo.escapestate = _ESC_normal;
					return;
				}
		case	_ESC_parameter 	:	/* awaiting 1st parameter     */
			switch (Gigo.escapecharacter) {
				case	'T'	:
				case	'f'	:
				case	'Z'	:
					Gigo.escapeparameter = c;
					Gigo.escapestate = _ESC_special;
					return;
				case	's'	:
					esc_s(c);
					Gigo.escapestate = _ESC_normal;
					return;
				case	'n'	:
					esc_n(c);
					Gigo.escapestate = _ESC_normal;
					return;
				case	'r'	:
					esc_r(c);
					Gigo.escapestate = _ESC_normal;
					return;
				default		:
					Gigo.escapestate = _ESC_normal;
					return;
				}
		case	_ESC_special   	:	/* awaiting 2nd parameter     */
			switch (Gigo.escapecharacter) {
				case	'T'	:
					Gigo.escapetransfer = (Gigo.escapeparameter + ((c & 0x00FF) * 256));
					Gigo.escapestate    = _ESC_transfer;
					return;
					
				case	'f'	:
					Gigo.escapestate = _ESC_normal;
					esc_f(Gigo.escapeparameter,c);
					Gigo.escapestate = _ESC_normal;
					return;
				case	'Z'	:
					Gigo.escapestate = _ESC_normal;
					esc_Z(Gigo.escapeparameter,c);
					Gigo.escapestate = _ESC_normal;
					return;
				}
		case	_ESC_transfer  	:	/* performing transparent T   */
			if ( Gigo.escapetransfer ) {
				Gigo.escapetransfer--;
				return;
				}
			else	{
				Gigo.escapestate = _ESC_normal;
				break;
				}
		}
	
	/* None-escaped characters arrive here */
	/* ----------------------------------- */
	switch ( c ) {
		case	'\r'	:
			Gigo.column = 1;
			break;

		case	'\t'	:
			do	{
				Gigo.column++;
				}
			while ((Gigo.column %8) !=0);
			if ( Gigo.column > Gigo.columns )
				Gigo.column = Gigo.columns;
			break;

		case	0x000C	:
			x_clear();

		case	0x001C	:
			Gigo.column = Gigo.line = 1;
			break;

		case	7	:
			break;

		case	 8	:
			if ( Gigo.column > 1 ) {
				 Gigo.column--;
				break;
				}
			Gigo.column = Gigo.columns;

		case	11	:
			if ( Gigo.line > 1 ) Gigo.line--;
			break;

		case	 6	:
			if ( Gigo.column < Gigo.columns ) {
				Gigo.column++;
				break;
				}
			Gigo.column = 1;

		case	 5	:
		case	'\n'	:
			if ( Gigo.line < Gigo.lines )
				Gigo.line++;
			else if ( Gigo.scrolling )
				scroll_up(1);
			else	Gigo.line = 1;
			break;

		default		:
			if ( c >= ' ' ) {
				PixelFontCat(
					((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
					((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin,
					Gigo.currentfont,c);
				x_putch(6);
			}
		}
	return;
}

public	void	x_bell()	{	return;			  }
public	int	x_event(int n)	{	return( visual_event(n) );  }
public	void	x_cprintf( char * sptr )
{
	while ( *sptr )
		x_putch( *(sptr++) );
	return;
}

public	void	x_foregr(int v)
{
	Gigo.foreground = v;
	return;
}

public	void	x_backgr(int v)
{
	Gigo.background = Gigo.washground = v;
	return;
}

public	void	x_pos(int l, int c)
{
	Gigo.column = c;
	Gigo.line   = l;
	return;
}
public	void	x_atb( int atbid )
{
	switch ( atbid ) {
		case 0 : atbid = 'a'; break;
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
	x_putch(27); x_putch( atbid );
	return;
}

public	int	x_lcfo()	{	return(56);	}
public	int	x_prfo()	{	return(56);	}

public	int	get_mouse_event()  {	return( visual_event(1) );	}
public	int	get_mouse_button() {	return( visual_event(2) );	}
public	int	get_mouse_line()   {	return( visual_event(3) );	}
public	int	get_mouse_col()    {	return( visual_event(4) );	}
public	int	get_mouse_row()    {	return( visual_event(6) );	}
public	int	get_mouse_column() {	return( visual_event(7) );	}
public	void	inifont(char * fzero, char * fother )
{
	return;
}

public	int	cicopagemargins(int lm, int rm, int tm, int bm )
{
	if ((lm+rm) > Gigo.width )
		return(103);
	if ((tm+bm) > Gigo.height )
		return(103);
	else	{
		Gigo.currentfont = use_base_font(1);
		Gigo.fontwidth   = guifontsize(	Gigo.currentfont );
		Gigo.fontheight  = ((Gigo.fontwidth >> 8) & 0x00FF);
		Gigo.fontwidth  &= 0x00FF;
		Gigo.leftmargin = lm;
		Gigo.rightmargin = rm;
		Gigo.topmargin = tm;
		Gigo.bottommargin = bm;
		Gigo.width = (Gigo.width - (lm+rm));
		Gigo.height = (Gigo.height - (tm+bm));
		return( use_base_font( Gigo.currentfont ) );
		}
}

public	int	cicowindow(int atx, int aty, int nbx, int nby )
{
	if (( atx > Gigo.width )
	||  ( aty > Gigo.height)
	||  ( (atx+nbx) > Gigo.width )
	||  ( (aty+nby) > Gigo.height ))
		return(103);
	else	return( cicopagemargins( atx,(nbx ? (Gigo.width - (atx+nbx)) : nbx ), 
					 aty,(nby ? (Gigo.height- (aty+nby)) : nby ) ) );
}


#endif	/* _singcico_c */

