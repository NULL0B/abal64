#ifndef	_stdgigo_c
#define	_stdgigo_c

#include "stdgigo.h"
#include "redirect.h"
#include "stdfont.c"
#include "stdmimo.c"
#include "abalcico.h"


extern  char * GigoColours;

static	int	exatba=0;

/*	Set current Graphical Cursor Shape 	*/
/*	----------------------------------	*/
public	int	set_gigo_cursor(int v)
{
	int	previous=Gigo.cursorstyle;
	if (( v > 0 ) && ( v <= _GIGO_CURSOR_OUTLINE ))
		Gigo.cursorstyle=v;
	return( previous );
}

public	int	set_gigo_cursor_colour(int v)
{
	int	previous=Gigo.cursorcolour;
	Gigo.cursorcolour=(v & 0x00FF);
	return( previous );
}

public	int	get_gigo_cursor()
{
	return( Gigo.cursorstyle );
}

/*	Set current Graphical Cursor Shape 	*/
/*	----------------------------------	*/
public	int	set_gigo_colour(int dath, int v)
{
	int	previous=-1;
	if (( dath >= 0 ) && ( dath < 16 )) {
		previous = Gigo.painter[dath];
		Gigo.painter[dath] = v;
		}
	return( previous );
}

public	int	get_gigo_colour(int dath)
{
	if (( dath >= 0 ) && ( dath < 16 ))
		return( Gigo.painter[dath] );
	else	return( dath );
}

/*	Set Mouse Mask to lb,hb		*/
/*	-----------------------		*/
private	void	esc_Z(int l, int h )
{
	set_mimo_mask(((l&0x00FF) | ((h & 0x00FF)<<8)));
	return;
}

/*	Set Cursor position to C,L	*/
/*	--------------------------	*/
private	void	esc_f(int c, int l)
{
	if ((Gigo.column = (c-0x001F)) > Gigo.columns)
		Gigo.column = ((Gigo.column % Gigo.columns) + 1);
	if ((Gigo.line   = (l-0x001F)) > Gigo.lines)
		Gigo.line = ((Gigo.line % Gigo.lines) + 1);
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
public	void	set_atba( int v )
{
	switch ( v ) {
		case	'0'	:
			exatba = 0;
			break;
		case	'1'	:
			exatba = 1;
			break;
		default		:
			exatba = v;
		}
	return;
}

private	void	esc_a()
{
	Gigo.atribut    = 0;
	if ( exatba & 1 ) {
		/* ------------------------------------------------------- */
		/* required for GFI / MAGELLAN otherwise transparence lost */
		/* because of ATB(0)					   */
		/* ------------------------------------------------------- */
		Gigo.foreground = Gigo.fg = Gigo.painter[Gigo.C_FORE];
		Gigo.background = Gigo.bg = Gigo.painter[Gigo.C_BACK];
		}
	else	{
		Gigo.foreground = Gigo.fg = Gigo.C_FORE; /* Gigo.painter[Gigo.C_FORE]; */
		Gigo.background = Gigo.bg = Gigo.C_BACK; /* Gigo.painter[Gigo.C_BACK]; */
		}
	return;
}

/*	Activate Inverse Video		*/
/*	----------------------		*/
private	void	esc_b()
{
	Gigo.atribut    = 0;
	if ((( Gigo.bg == 16 ) && ( Gigo.fg ==  0))
	||  (( Gigo.bg ==  0 ) && ( Gigo.fg == 16))
	||  (( Gigo.bg == 15 ) && ( Gigo.fg == 31))
	||  (( Gigo.bg == 31 ) && ( Gigo.fg == 15))) {
		Gigo.foreground = 15; Gigo.background=16;
		}
	else if ((Gigo.foreground = Gigo.bg) == (Gigo.background = Gigo.fg)) {
		if ( Gigo.foreground == 7 )
			Gigo.foreground=8;
		}
	else if (!( Gigo.background ))
		Gigo.background = 16;
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

/*	Activate Double Width : Shadow 	*/
/*	------------------------------	*/
private	void	esc_z()
{
	Gigo.atribut    |= _GIGO_SHADOW;
	return;
}

/*	Activate Upper Case Conversion 	*/
/*	------------------------------	*/
private	void	esc_i()
{
	Gigo.atribut    |= _GIGO_UPPER;
	return;
}

/*	Activate Lower Case Conversion 	*/
/*	------------------------------	*/
private	void	esc_j()
{
	Gigo.atribut    |= _GIGO_LOWER;
	return;
}

/*	Set Foreground Colour to C	*/
/*	--------------------------	*/

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


public	void	get_gigo_colours( int * f, int * b )
{
	*f = Gigo.foreground;
	*b = Gigo.background;
	return;
}

public	void	set_gigo_colours( int f, int b )
{
	Gigo.fg = Gigo.foreground = f;
	Gigo.bg = Gigo.background = b;
	return;
}

public	void	get_gigo_tab( int * f, int * b )
{
	*f = Gigo.column;
	*b = Gigo.line;
	return;
}

public	void	set_gigo_tab( int f, int b )
{
	Gigo.column = f;
	Gigo.line   = b;
	return;
}

private	int	esc_r(int c)
{
	int	dath = (c > '9' ? ((c - 'A') + 10 ) : (c - '0'));
	set_foreground_colour( dath );
	return( Gigo.fg );
}

/*	Set BackGround Colour to C	*/
/*	--------------------------	*/

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

private	int	esc_s(int c)
{
	int	dath = (c > '9' ? ((c - 'A') + 10 ) : (c - '0'));
	set_background_colour( dath );
	return( Gigo.bg );
}

/*	Set Screen Wash or Erase Colour to C	*/
/*	------------------------------------	*/
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

/*	Force initial delete colour for esc a	*/
/*	-------------------------------------	*/

private	int	esc_q(int c)
{
	int	dath = (c > '9' ? ((c - 'A') + 10 ) : (c - '0'));
	set_washground_colour(dath);
	return((Gigo.C_BACK=Gigo.bg));
}

private	int	esc_n(int c)
{
	int	dath = (c > '9' ? ((c - 'A') + 10 ) : (c - '0'));
	set_washground_colour(dath);
	return(Gigo.bg);
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

/*	cico mode block 	*/
/*	---------------		*/
private	void	esc_k()
{
	Gigo.scrolling = 2;
	return;
}

/*	Draws the Graphical Text Cursor 	*/
/*	-------------------------------		*/
private	void	xgr_cursor(int mode)
{
	int	atx;
	int	aty;
	switch ( mode ) {

		case	1 :	/* Block XOR */

#ifdef	_ABAL_DTI
			atx= (	(!(Gigo.direction & _GIGO_R2L)) ?
				((Gigo.column-1)*Gigo.fontwidth):
				((Gigo.columns-Gigo.column)*Gigo.fontwidth) )+Gigo.leftmargin;
			aty= ((!(Gigo.direction & _GIGO_B2T)) ?
				((Gigo.line-1)*Gigo.fontheight):
				((Gigo.lines-Gigo.line)*Gigo.fontheight) )+Gigo.topmargin;
#else
			atx = ((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin;
			aty = ((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin;
#endif
			switch ( Gigo.cursorstyle ) {
				case	_GIGO_CURSOR_BLOCK	: 
					xorzone( atx+Gigo.xmargin,aty+Gigo.ymargin,
						Gigo.xfontwidth,Gigo.yfontheight,
						Gigo.cursorcolour );
					break;

				case	_GIGO_CURSOR_VLINE	:
					xorzone( atx+Gigo.xmargin,aty+Gigo.ymargin,
						((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin+Gigo.ymargin,
						2,Gigo.yfontheight,
						Gigo.cursorcolour );
					break;

				case	_GIGO_CURSOR_HLINE	:
					xorzone( atx+Gigo.xmargin,
						 aty+Gigo.ymargin+(Gigo.yfontheight-2),
						Gigo.xfontwidth,2,Gigo.cursorcolour );
					break;

				case	_GIGO_CURSOR_OUTLINE	:
					xorzone( atx+Gigo.xmargin,aty+Gigo.ymargin,
						Gigo.xfontwidth,1,Gigo.cursorcolour );
					xorzone( atx+Gigo.xmargin,aty+Gigo.ymargin+(Gigo.yfontheight-1),
						Gigo.xfontwidth,1,Gigo.cursorcolour );
					xorzone( atx+Gigo.xmargin,aty+Gigo.ymargin,
						1,Gigo.yfontheight,Gigo.cursorcolour );
					xorzone( atx+Gigo.xmargin+(Gigo.xfontwidth-1),aty+Gigo.ymargin,
						1,Gigo.yfontheight,Gigo.cursorcolour );
					break;

				}	
			}
	return;
}

public	int	is_gigo_flushall()
{
	return( Gigo.flushall );
}

public	int	esc_E()
{
	Gigo.flushall=0;
	return( Gigo.flushall );
}

public	int	esc_F()
{
	Gigo.flushall=1;
	flush();
	return( Gigo.flushall );
}


/*	Clear to End of Line	*/
/*	--------------------	*/
private	void	esc_K()
{
	if (!( Gigo.acontrol & _GIGO_CLEAR_EOL ))
		return;
	else	{
		if ((!( Gigo.line ))
		|| (!( Gigo.column )))
			return;
		if (( Gigo.line   <= Gigo.lines )
		&&  ( Gigo.column <= Gigo.columns )) {
			switch ( Gigo.direction ) {
				case	_GIGO_L2RT2B	:
					filzone(((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
						((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin,
						(Gigo.width - ((Gigo.column-1)*Gigo.fontwidth)),
						Gigo.fontheight,
						Gigo.washground);
					break;
				case	_GIGO_L2RB2T	:
					filzone(((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
						((Gigo.lines-Gigo.line)*Gigo.fontheight)+Gigo.topmargin,
						(Gigo.width - ((Gigo.column-1)*Gigo.fontwidth)),
						Gigo.fontheight,
						Gigo.washground);
					break;
				case	_GIGO_R2LT2B	:
					filzone(Gigo.leftmargin,
						((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin,
						((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
						Gigo.fontheight,
						Gigo.washground);
					break;
				case	_GIGO_R2LB2T	:
					filzone(Gigo.leftmargin,
						((Gigo.lines-Gigo.line)*Gigo.fontheight)+Gigo.topmargin,
						((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
						Gigo.fontheight,
						Gigo.washground);
					break;
				}
			}
		}
	return;
}

/*	Clear to End of Page	*/
/*	--------------------	*/
private	void	esc_J()
{
	if (!( Gigo.acontrol & _GIGO_CLEAR_EOP ))
		return;
	else	{
		esc_K();	
		if ( Gigo.line < Gigo.lines ) {
			switch ( Gigo.direction ) {
				case	_GIGO_L2RT2B	:
				case	_GIGO_R2LT2B	:
					filzone( Gigo.leftmargin,
						(Gigo.line*Gigo.fontheight)+Gigo.topmargin,
						Gigo.width, 
						(Gigo.height - (Gigo.line*Gigo.fontheight)),
						Gigo.washground);
					break;

				case	_GIGO_L2RB2T	:
				case	_GIGO_R2LB2T	:
					filzone( Gigo.leftmargin,
						 Gigo.topmargin,
						 Gigo.width, 
						 (Gigo.line*Gigo.fontheight)+Gigo.topmargin,
						 Gigo.washground);
					break;
				}
			}
		}
	return;
}

/*	Insert Line  		*/
/*	-----------		*/
private	void	esc_L()
{
	if (!( Gigo.acontrol & _GIGO_INSERT_LINE ))
		return;
	else	{
		if ( Gigo.line < Gigo.lines )
			movezone(
				Gigo.leftmargin,  (Gigo.line*Gigo.fontheight)+Gigo.topmargin,
				Gigo.leftmargin,  ((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin,
				Gigo.width,
				((Gigo.lines-Gigo.line)*Gigo.fontheight));

		filzone(Gigo.leftmargin,Gigo.topmargin+((Gigo.line-1)*Gigo.fontheight),Gigo.width,Gigo.fontheight,Gigo.washground);
		}
	return;
}

/*	Delete Line  		*/
/*	-----------		*/
private	void	esc_M()
{
	if (!( Gigo.acontrol & _GIGO_DELETE_LINE ))
		return;
	else	{
		if ( Gigo.line < Gigo.lines )
			movezone(	Gigo.leftmargin,Gigo.topmargin+ ((Gigo.line-1)*Gigo.fontheight),
					Gigo.leftmargin,Gigo.topmargin+ (Gigo.line*Gigo.fontheight),
					Gigo.width,
					((Gigo.lines-Gigo.line)*Gigo.fontheight));

		filzone(Gigo.leftmargin,Gigo.topmargin+((Gigo.lines-1)*Gigo.fontheight),Gigo.width,
			(Gigo.height-((Gigo.lines-1)*Gigo.fontheight)),Gigo.washground);
		}
	return;
}

/*	Insert Character	*/
/*	----------------	*/
private	void	esc_P()
{
	if (!( Gigo.acontrol & _GIGO_INSERT_CHAR ))
		return;
	else if ((!( Gigo.line ))
	     || (!( Gigo.column )))
		return;
	else if (( Gigo.line   <= Gigo.lines )
	     &&  ( Gigo.column <= Gigo.columns )) {/* IJM */
		/* move all to end of line - 1 forward 1 character */
		if (( Gigo.column*Gigo.fontwidth ) < Gigo.width ) {
			movezone(
		/* tox */	(Gigo.column*Gigo.fontwidth)+Gigo.leftmargin	,
		/* toy */	((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin  ,
		/* frx */	((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
		/* fry */	((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin  ,
		/* nbx */	(Gigo.width - (Gigo.column*Gigo.fontwidth)) ,
		/* nby */	 Gigo.fontheight
				);
			}
		/* erase current character */
		filzone(((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
			((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin,
			Gigo.fontwidth,Gigo.fontheight,Gigo.washground);
		}
	return;
}

/*	Delete Character	*/
/*	----------------	*/
private	void	esc_AT()
{
	if (!( Gigo.acontrol & _GIGO_DELETE_CHAR ))
		return;
	else if ((!( Gigo.line   ))
	     ||  (!( Gigo.column )))
		return;
	else if (( Gigo.line   <= Gigo.lines   )
	     &&  ( Gigo.column <= Gigo.columns )) {/* IJM */
		/* move from next character to end of line backward 1 character */
		if (( Gigo.column*Gigo.fontwidth ) < Gigo.width ) {
			movezone(
		/* tox */	((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin,
		/* toy */	((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin  ,
		/* frx */	(Gigo.column*Gigo.fontwidth)+Gigo.leftmargin	,
		/* fry */	((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin  ,
		/* nbx */	(Gigo.width - ((Gigo.column-1)*Gigo.fontwidth)) ,
		/* nby */	 Gigo.fontheight
				);
			}
		/* erase last character */
		filzone((Gigo.leftmargin+(Gigo.width - Gigo.fontwidth)),
			((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin  ,
			Gigo.fontwidth,	Gigo.fontheight, Gigo.washground);
		}
	return;
}



/*	Scroll N Lines Up	*/
/*	-----------------	*/
private	void	scroll_up(int n)
{
	switch ( Gigo.direction ) {
		case	_GIGO_L2RT2B	:
		case	_GIGO_R2LT2B	:
			movezone(Gigo.leftmargin,Gigo.topmargin,Gigo.leftmargin,Gigo.topmargin+(n*Gigo.fontheight),Gigo.width,((Gigo.lines-n)*Gigo.fontheight));
			filzone(Gigo.leftmargin,Gigo.topmargin+((Gigo.lines-n)*Gigo.fontheight),Gigo.width,(n*Gigo.fontheight),Gigo.washground);
			break;
		case	_GIGO_L2RB2T	:
		case	_GIGO_R2LB2T	:
			movezone(Gigo.leftmargin,Gigo.topmargin+(n*Gigo.fontheight),
				Gigo.leftmargin,Gigo.topmargin,
				Gigo.width,((Gigo.lines-n)*Gigo.fontheight));
			filzone (Gigo.leftmargin,Gigo.topmargin,Gigo.width,(n*Gigo.fontheight),Gigo.washground);
			break;
		}
	return;
}

/*	Returns the current text column position	*/
/*	----------------------------------------	*/
private	int 	xgr_prfo(int numero,PIXIBYTE *chaine,int longueur )
{
#define	prfo
#ifndef	prfo
	return(prfo(numero,chaine,longueur));
#else
	return(0);
#endif
}

private	int	xgr_lcfo(int numero,PIXIBYTE *chaine,int longueur )
{
#define	lcfo
#ifndef	lcfo
	return(lcfo(numero,chaine,longueur));
#else
	return(0);
#endif
}

private	int	xgr_col()
{
	if ( prndest != 1 )
		return( local_x_col() );
	else	return( Gigo.column );
}

/*	Returns the current text line   position	*/
/*	----------------------------------------	*/
private	int	xgr_lin()
{
	if ( prndest != 1 )
		return( local_x_lin() );
	else	return( Gigo.line );
}

/*	Activates Text Output buffering mechanisms	*/
/*	------------------------------------------	*/
private	int	xgr_bstart()
{
	if ( prndest != 1 )
		local_x_bstart();
	else	{
		if ( GigoXtrace & 256 ) {
			printf("xgr_bstart(1)\r\n");
			}
		hide();
		}
	return( 0 );
}

/*	Releases  Text Output buffering mechanisms	*/
/*	------------------------------------------	*/
private	int	xgr_bflush()
{
	if ( prndest != 1 )
		local_x_bflush();
	else	{
		if ( GigoXtrace & 256 ) {
			printf("xgr_bflush(1)\r\n");
			}
		if ( Gigo.flushall )
			while ( flush() );
		else	flush();
		}
	return(0);
}

/*	Returns Configuration Values or Information	*/
/*	-------------------------------------------	*/
private	int	AbalConf10=-1;
private	int	host_system_identity()
{
	char	*	eptr;
	if (AbalConf10 != -1 )
		return( AbalConf10 );
	else if (!( eptr = getenv("ABALCONF10") ))
		return((AbalConf10=3));
	else	{
		for (AbalConf10=0; *eptr != 0; eptr++ ) {
			if ((*eptr >= '0') && ( *eptr <= '9'))
				AbalConf10 = ((AbalConf10*10) + ( *eptr -'0'));
			else	break;
			}
		return(AbalConf10);
		}
}

/*	conf	*/
/*	-----	*/
private	int	xgr_conf(int n)
{
	if ( prndest != 1 )
		return( local_x_conf(n) );

	else	{
		switch ( n ) {
			case	1 : return( Gigo.lines );
			case	2 : return( Gigo.columns );
			case	14: return( 1 );
			case	11: return( (Gigo.acontrol & 0x007F) );
			case	12: return( 1+4 );
			case	9 : return( xgr_nbfo() );
			case	16: return( Gigo.atribut );
			case	17: 
				if ( Gigo.foreground < 32 )
					return( Gigo.painter[ Gigo.foreground ] );
				else	return( Gigo.foreground );
			case    18: 
				if ( Gigo.background < 32 )
					return( Gigo.painter[ Gigo.background ] );
				else	return( Gigo.background );
			case	28: 
				if ( Gigo.C_FORE < 32 )
					return( Gigo.painter[ Gigo.C_FORE ] );
				else	return( Gigo.C_FORE );
			case	29: 
				if ( Gigo.C_BACK < 32 )
					return( Gigo.painter[ Gigo.C_BACK ] );
				else	return( Gigo.C_BACK );
			case	66: return( consoletype() );
			case	68: return( hardrows()    );
			case	69: return( hardcolumns() );
			case	70: if ( XGC.mapping ) return(0);
			case	67: return( get_pixel_size() );
			case	10: return( host_system_identity() );
			default	  : return(local_x_conf(n));
			}
		}
}

public	void	x_configure(int n)	{	Gigo.acontrol = n; return;	}
public	int	x_conf(int n)		{	return( xgr_conf(n) );		}


/*	----------------------		*/
/*	 x g r _ c l e a r ()		*/
/*	----------------------		*/
/*	Clears the text screen		*/
/*	----------------------		*/

private	void	xgr_clear()
{
	esc_f(0x0020,0x0020);
	esc_J();
	return;
}

/*	---------------------------------------------------------------		*/
/*	Function prototypes for the remaining Redirected functions		*/
/*	These will be declared and activated during init gigo below		*/
/*	---------------------------------------------------------------		*/

public 	int	xgr_lcfo(int numero,PIXIBYTE *chaine,int longueur );
public	int 	xgr_prfo(int numero,PIXIBYTE *chaine,int longueur );
public	void	xgr_push_view();
public	void	xgr_pop_view();
public	void	xgr_bell();
public	int	xgr_event(int n);
private	void	xgr_putch(int c);
/* public	int	xgr_getch(); */
/* public	int	xgr_kbhit(); */
private	int	xgr_detect();

extern	int	xgr_graph(int, void *);

#include "stdgetch.c"

extern	void *	redirect_access_controller(int, void *);

public	int	set_letter_spacing(int v)
{
	int	r=Gigo.letter_spacing;
	Gigo.letter_spacing = v;
	return(r);
}

public	int	set_line_spacing(int v)
{
	int	r=Gigo.line_spacing;
	Gigo.line_spacing = v;
	return(r);
}

public	int	set_shadow_colour(int v)
{
	int	r=Gigo.ShadowFg;
	Gigo.ShadowFg = v;
	return(r);
}

public	int	set_shadow_width(int v)
{
	int	r=Gigo.ShadowX;
	Gigo.ShadowX = v;
	return(r);
}

public	int	set_shadow_height(int v)
{
	int	r=Gigo.ShadowY;
	Gigo.ShadowY = v;
	return(r);
}

/*	---------------------------------------------------------------		*/
/*			l o a d _ g i g o _ a l t m a p ()			*/
/*	---------------------------------------------------------------		*/
/*	Loads the gigo alt key conversion table from the file defined		*/
/*	by the GIGOALTMAP variable.						*/
/*	---------------------------------------------------------------		*/
int	load_gigo_altmap()
{
	char *	eptr;
	FILE *	hptr;
	if (( eptr = getenv("GIGOALTMAP" )) != (char *) 0) {
		if ((hptr = fopen(eptr,"rb"))!=(FILE*) 0) {
			fread(Gigo.altmap,256,1,hptr);
			close(hptr);
			return(1);
			}
		else	{
			memset(Gigo.altmap,0,256);
			return(0);
			}
		}
	else	{
		memset(Gigo.altmap,0,256);
		return(0);
		}
}

#ifdef	_ABAL_DTI
int	get_gigo_direction()
{
	return( Gigo.direction );
}
void	set_gigo_direction( int v )
{
	switch ( v & 3 ) {
		case	0 : Gigo.direction = _GIGO_L2RT2B; break;
		case	1 : Gigo.direction = _GIGO_R2LT2B; break;
		case	2 : Gigo.direction = _GIGO_L2RB2T; break;
		case	3 : Gigo.direction = _GIGO_R2LB2T; break;
		}
	return;
}
#endif

int	gigo_alt_event(int keycode)
{
	if (!( Gigo.use_altmap ))
		return( mimo_key_event(keycode) );
	else if (!( Gigo.altmap[(keycode & 0x00FF)] ))
		return( mimo_key_event(keycode) );
	else	return( mimo_key_event(Gigo.altmap[(keycode & 0x00FF)] ) );

}


/*	---------------------------------------------------------------		*/
/*				i n i t g i g o ()				*/
/*	---------------------------------------------------------------		*/
/*	Initialisation of the Graphical Console Input Output Controller		*/
/*	---------------------------------------------------------------		*/
public	void	default_access_controller()
{
	redirect_access_controller(CICO_CO,	xgr_putch);
	redirect_access_controller(CICO_CI,	xgr_getch);
	redirect_access_controller(CICO_TPCI, 	xgr_kbhit);
	redirect_access_controller(CICO_CONF,	xgr_conf);
	redirect_access_controller(CICO_COLONNE,xgr_col);
	redirect_access_controller(CICO_LIGNE,	xgr_lin);
	redirect_access_controller(CICO_LCFO,	xgr_lcfo);
	redirect_access_controller(CICO_PRFO,	xgr_prfo);
	redirect_access_controller(CICO_START,	xgr_bstart);
	redirect_access_controller(CICO_FLUSH,	xgr_bflush);
	redirect_access_controller(CICO_EVENT,	xgr_event);
	redirect_access_controller(CICO_GRAPH,	xgr_graph);
	return;
}


public	void	initgigosize(int width, int height )
{
	set_bioswidth((Gigo.width = width ));
	set_biosheight((Gigo.height = height));
	return;
}

public	int	initgigo(int width, int height )
{
	int	i;
	char *	eptr;
	char *	cptr;

	if (!( islocked_access_controller() )) {	
		initialise_access_controller();
		initialise_event_manager();
		printf("\n");
		}


	initerm();
	select_cico_ecran();
	if (!( islocked_access_controller() )) {	

		Gigo.acontrol    = ((	_GIGO_CLEAR_EOP 	| _GIGO_CLEAR_EOL 	) | 
				    (	_GIGO_INSERT_LINE 	| _GIGO_DELETE_LINE 	) | 
				    (	_GIGO_INSERT_CHAR 	| _GIGO_DELETE_CHAR	) | _GIGO_HARD_COPY );

		if (!( eptr = getenv("GIGOREPLAY")))
			Gigo.replaying = 0;
		else	{
			Gigo.replaying = ( *eptr -'0');
			}

		// printf(" Gigo.replaying = %u \r\n",Gigo.replaying);

		if (( Gigo.replaying & 2 ) != 0) {
			if (!(eptr = getenv("GIGOREPLAYFILE")))
				Gigo.replaying &= ~2;
			else	{
				activate_xgr_replay( eptr );
				printf(" replaying from file %s \r\n",eptr);
				}
			}

		if (( Gigo.replaying & 4 ) != 0) {
			if (!(eptr = getenv("GIGORECORDFILE")))
				Gigo.replaying &= ~4;
			else	{
				activate_xgr_record( eptr );
				printf(" recording to file %s \r\n",eptr);
				}
			}

		Gigo.leftmargin  = Gigo.topmargin    = 0;
		Gigo.rightmargin = Gigo.bottommargin = 0;
		x_clear();
		xgr_ikeys();

		default_access_controller();

		Gigo.cursorstyle = _GIGO_CURSOR_BLOCK;
		Gigo.cursorcolour= _GIGO_CURSOR_COLOUR;

		if (( eptr = getenv( "GIGOCURSOR" )) != (char *) 0) 
			set_gigo_cursor((*eptr - '0'));
		if (( eptr = getenv( "GIGOCURSORCOLOUR" )) != (char *) 0) 
			set_gigo_cursor_colour((*eptr - '0'));

#ifdef	_ABAL_DTI
		if (( eptr = getenv( "GIGODIRECTION" )) != (char *) 0)
			set_gigo_direction( (*eptr - '0') );
		else	set_gigo_direction( 0 );
		for (i=0; i<256; i++) { Gigo.reflection[i] = i; }
		/* symbol reflections for right to left display */
		/* -------------------------------------------- */
		Gigo.reflection['('] = ')'; Gigo.reflection[')'] = '(';
		Gigo.reflection['['] = ']'; Gigo.reflection[']'] = '[';
		Gigo.reflection['{'] = '}'; Gigo.reflection['}'] = '{';
		Gigo.reflection['<'] = '>'; Gigo.reflection['>'] = '<';
		/* semi graphical reflections for R2L display */
		/* ------------------------------------------ */
		Gigo.reflection['´' & 0x00FF] = 'Ã'; Gigo.reflection['Ã' & 0x00FF] = '´';
		Gigo.reflection['µ' & 0x00FF] = 'Æ'; Gigo.reflection['Ã' & 0x00FF] = 'µ';
		Gigo.reflection['¶' & 0x00FF] = '¶'; Gigo.reflection['Ã' & 0x00FF] = '¶';
		Gigo.reflection['·' & 0x00FF] = 'Ö'; Gigo.reflection['Ö' & 0x00FF] = '·';
		Gigo.reflection['¸' & 0x00FF] = 'Õ'; Gigo.reflection['Õ' & 0x00FF] = '¸';
		Gigo.reflection['¹' & 0x00FF] = 'Ì'; Gigo.reflection['Ì' & 0x00FF] = '¹';
		Gigo.reflection['»' & 0x00FF] = 'É'; Gigo.reflection['É' & 0x00FF] = '»';
		Gigo.reflection['¼' & 0x00FF] = 'È'; Gigo.reflection['È' & 0x00FF] = '¼';
		Gigo.reflection['½' & 0x00FF] = 'Ó'; Gigo.reflection['Ó' & 0x00FF] = '½';
		Gigo.reflection['¾' & 0x00FF] = 'Ô'; Gigo.reflection['Ô' & 0x00FF] = '¾';
		Gigo.reflection['¿' & 0x00FF] = 'Ú'; Gigo.reflection['Ú' & 0x00FF] = '¿';
		Gigo.reflection['À' & 0x00FF] = 'Ù'; Gigo.reflection['Ù' & 0x00FF] = 'À';
#endif
		Gigo.cursing        = 0;
		Gigo.letter_spacing = 0;
		Gigo.line_spacing = 0;
		Gigo.tracing     = 0;
		Gigo.columns 	 = 80;
		Gigo.lines   	 = 24;
		Gigo.fontwidth 	 = Gigo.fontheight = 1;	
		Gigo.workingfont = 0;
		Gigo.currentfont = 0;
		sethqfont(75);
		}

	Gigo.width 	 = width;
	Gigo.height 	 = height;
	Gigo.thisevent	 = 0;

	if (!( islocked_access_controller() )) {
		
		Gigo.escapestate = _ESC_normal;
		
		Gigo.C_FORE	 = 0;
		Gigo.C_BACK	 = 7;

		/* Set Shadow Step and Colours */
		/* --------------------------- */
		if (!( eptr = getenv("GIGOSHADOWX")))
			Gigo.ShadowX = 2;
		else	{ Gigo.ShadowX = atoi(eptr); }

		if (!( eptr = getenv("GIGOSHADOWY")))
			Gigo.ShadowY = 2;
		else	{ Gigo.ShadowY = atoi(eptr); }

		if (!( eptr = getenv("GIGOSHADOWFG")))
			Gigo.ShadowFg = 19;
		else	{ Gigo.ShadowFg = atoi(eptr); }

		for (i=0; i < 32; i++ ) Gigo.painter[i] = i;

		Gigo.painter[0] = 16;
		Gigo.painter[1] =  4; Gigo.painter[4] =  1;
		Gigo.painter[3] =  6; Gigo.painter[6] =  3;
		Gigo.painter[7] =  8; Gigo.painter[8] =  7;
		Gigo.painter[9] = 12; Gigo.painter[12]=  9;
		Gigo.painter[11]= 14; Gigo.painter[14]= 11;

		esc_r(0x030);	esc_s(0x03F); 	esc_n(0x03F);

		if ((cptr = GigoColours )) {
			if ( *cptr )
				Gigo.C_FORE = esc_r(*(cptr++));
			if ( *cptr )
				Gigo.C_BACK = esc_s(*(cptr++));
			if ( *cptr )
				Gigo.C_BACK = esc_n(*(cptr++));
			}
	
		esc_v();	
		esc_t(); 	
		esc_a(); 
		esc_op_w();

		esc_f(0x20,0x20);	

		if (!(eptr = getenv("ABALESCE")))
			esc_F();
		else if ( *eptr == '1' )
			esc_E();
		else	esc_F();

		for (i=0; i < MAX_FONTS; i++ ) {
			Gigo.graphicfonts[i] = (struct standard_font *) 0;
			Gigo.fontnames   [i] = (char *) 0;
			}
		Gigo.fontwidth   = Gigo.fontheight  = 0;
		Gigo.workingfont = Gigo.currentfont = 0;
		Gigo.xmargin     = Gigo.ymargin     = 0;
		Gigo.xfontwidth  = Gigo.yfontheight = 0;

		/* reset alt key conversion table */
		/* ------------------------------ */
		Gigo.use_altmap = load_gigo_altmap();

		}
	return(0);
}

public	int	gigo_is_replaying()
{
	return( Gigo.replaying & 1 );
}

public	int	gigo_test_replaying()
{
	return( Gigo.replaying & 6 );
}

/*	---------------------------------------------------------------		*/
/*				f i n g i g o ()				*/
/*	---------------------------------------------------------------		*/
/*	Termination of the Graphical Console IO Management Mechanisms		*/
/*	---------------------------------------------------------------		*/
public	int	fingigo()
{
	int	i;

	if (!( islocked_access_controller() )) {	

		for (i=0; i < MAX_FONTS; i++ ) {
			if ((Gigo.graphicfonts[i]) != (struct standard_font *) 0)
				Gigo.graphicfonts[i] = drop_font( Gigo.graphicfonts[i] );
			if ( Gigo.fontnames[i] != (char *) 0 )
				liberate( Gigo.fontnames[i] );
			}
		initialise_access_controller();

		if ( Gigo.replaying )
			cancel_xgr_replay_record();

		}
	finterm(0);
	return(0);
}

/*	--------------------------	*/
/*	Character Output Functions	*/
/*	--------------------------	*/
#include "pixelco.c"


/*	--------------------------------------------------------------------------------------		*/
/*					x _ c u r s e r ( nbx )						*/
/*	--------------------------------------------------------------------------------------		*/
/*	Repositioning of the graphical screen text coordinates after character / string output		*/
/*	--------------------------------------------------------------------------------------		*/
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

/*	-------------------------------------	*/
/*	   c i c o c o l o u r ( fg, bg )	*/
/*	-------------------------------------	*/
/*	Sets the current text output colours	*/
/*	------------------------------------	*/
int	cicocolour(int fg, int bg )
{
	Gigo.bg = Gigo.background = bg;
	Gigo.foreground = fg;

/*	set_foreground_colour((fg & 0x00FF));		*/
/*	set_background_colour((bg & 0x00FF));		*/
/*	if ( bg ) set_washground_colour((bg & 0x00FF));	*/

	return 0;
}

/*	------------------------------------------	*/
/*	      c i c o c o l o u r s ( fg, bg )	 	*/
/*	------------------------------------------	*/
/*	Sets all three current text output colours	*/
/*	------------------------------------------	*/
int	cicocolours(int fg, int bg, int wg )
{
	set_foreground_colour((fg & 0x00FF));
	set_background_colour((bg & 0x00FF));
	set_washground_colour((wg & 0x00FF));
	return 0;
}


/*	-------------------------------------	*/
/*	   c i c o p a l e t t e ( c, v )	*/
/*	-------------------------------------	*/
/*	Redirection of colour map values	*/
/*	-------------------------------------	*/
int	cicopalette(int colour, int value )
{	
	int	result;
	if ( colour < 16 ) {
		result = Gigo.painter[colour];
		Gigo.painter[colour] = value;
		}
	else	result = colour;
	return(result);
}

int	set_paint_translation( char * bptr, int blen )
{
	int	i;
	for (	i=0; i < blen; i++ ) {
		if ( i < 16 )
			Gigo.painter[i] = (*(bptr+i) & 0x00FF);
		}
	return;
}

int	get_paint_translation( char * bptr, int blen )
{
	int	i;
	for (	i=0; i < blen; i++ ) {
		if ( i < 16 )
			*(bptr+i) = (Gigo.painter[i] & 0x00FF);
		}
	return;
}



/*	-------------------------------------	*/
/*	    c i c o c u r s o r ( c, l )	*/
/*	-------------------------------------	*/
/*	Sets the current text curser position	*/
/*	-------------------------------------	*/
int	cicocursor(int atc, int atl )
{
	if ((Gigo.column = atc) > Gigo.columns)
		Gigo.column = ((Gigo.column % Gigo.columns) + 1);
	if ((Gigo.line   = atl) > Gigo.lines)
		Gigo.line = ((Gigo.line % Gigo.lines) + 1);
	return 0;
}

/*	-----------------------------------	*/
/*	x g r _ p r i n t _ s c r e e n ()	*/
/*	-----------------------------------	*/
/*	Prints the current graphical screen	*/
/*	to a graphical file			*/
/*	-----------------------------------	*/
static	int	hardcopycounter=0;
static	int	hardcopymode=1; /* BMP=0, GIF=1, JPG=2, PNG=3 */
public	int	esc_Q()
{
	char	nomfic[256];
	char *	pptr;
	char *	nptr;
	char *	xptr;
	char *	sptr;
	char *	mptr;
	if (!( Gigo.acontrol & _GIGO_HARD_COPY ))
		return(0);
	if (!( mptr = getenv("ESCQMODE") )) {
		if ( XGC.mapping )
			mptr = "1";
		else	mptr = "2";
		}
	if (!( nptr = getenv("ESCQNAME") ))
		nptr = "escQ";
	if (!( pptr = getenv("ESCQPATH") ))
		pptr = "\0";
	switch ((hardcopymode = atoi(mptr))) {
		case	0 :
			sprintf(nomfic,"%s%s%lx%u.bmp",pptr,nptr,getpid(),++hardcopycounter);
			break;
		case	1 :
			sprintf(nomfic,"%s%s%lx%u.gif",pptr,nptr,getpid(),++hardcopycounter);
			break;
		case	2 :
			sprintf(nomfic,"%s%s%lx%u.jpg",pptr,nptr,getpid(),++hardcopycounter);
			break;
		case	3 :
			sprintf(nomfic,"%s%s%lx%u.png",pptr,nptr,getpid(),++hardcopycounter);
			break;
		default	  :
			return(1);
		}
	if ( visual_screen_capture( nomfic, hardcopymode ) != 0)
		return(0);
	else if (!(xptr = getenv("ESCQEXEC")))
		return(30);
	else if (!( sptr = allocate( strlen( nomfic ) + strlen( xptr ) + 64 ) ))
	 	return(27);
	else	{
		sprintf(sptr,"%s %s",xptr,nomfic);
		system(sptr);
		liberate(sptr);
		return(1);
		}
}

/*	----------------------------------	*/
/*	      x g r _ d e t e c t ( )		*/
/*	----------------------------------	*/
/*	Character Input Test	: CO?		*/
/*	----------------------------------	*/
private	int 	xgr_detect()
{
	int	result;
	if ( Gigo.cursing & 1)
		xgr_cursor(1);
	result = wait_event();
	if ( Gigo.cursing & 1)
		xgr_cursor(1);
	if ( result == 256 )
		Gigo.thisevent = get_mimo_type();
	else	Gigo.thisevent = 0;
	return( unget_event(result) );
}

public	int	x_detect()	{	return( xgr_detect() );		}


/*	----------------------------------	*/
/*	      x g r _ p u t c h ( c )		*/
/*	----------------------------------	*/
/*	Character Output	:	CO	*/
/*	----------------------------------	*/

private	void	xgr_putch(int c)
{	
	if ( prndest != 1 ) {
		local_x_putch(c);
		return;
		}

	switch (Gigo.escapestate) {
		case	_ESC_normal	:	/* awaiting  escape character */
			if ( c == 27 ) {
				Gigo.escapestate = _ESC_active;
				return;
				}
			break;

		case	_ESC_active	:	/* awaiting escaped character */
			switch ((Gigo.escapecharacter = c)) {
				case	'T'	: /* transparent packet */
				case	'f'	: /* cursor positioning */
				case	'Z'	: /* mouse mask		*/
				case	'n'	: /* erase colour	*/
				case	'q'	: /* erase colour	*/
				case	's'	: /* wash colour	*/
				case	'r'	: /* Text colour	*/
				case	'('	: /* new visual atributs */
					Gigo.escapestate = _ESC_parameter;
					return;
				case	'E'	:
					esc_E();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'F'	:
					esc_F();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'u'	:
					esc_u();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'k'	:
					esc_k();
					Gigo.escapestate = _ESC_normal;
					return;
				case	't'	:
					esc_t();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'Q'	:
					esc_Q();
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
				case	'P'	:
					esc_P();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'@'	:
					esc_AT();
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
				case	'i'	:
					esc_i();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'j'	:
					esc_j();
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
				case	'z'	:
					esc_z();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'>'	:
					xgr_push_view();
					Gigo.escapestate = _ESC_normal;
					return;
				case	'<'	:
					xgr_pop_view();
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

				case	'('	:
					/* these are simply filtered out */
					/* ----------------------------- */
					Gigo.escapestate = _ESC_normal;
					return;

				case	's'	:
					esc_s(c);
					Gigo.escapestate = _ESC_normal;
					return;
				case	'n'	:
					esc_n(c);
					Gigo.escapestate = _ESC_normal;
					return;
				case	'q'	:
					esc_q(c);
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
				PixelFontCat(/* IJM */
					scaled_coordinate( (((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin+Gigo.xmargin)),
					scaled_coordinate( (((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin+Gigo.ymargin)),
					Gigo.workingfont,c);
				c = 6;
				break;
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
			xgr_clear();

		case	0x001C	:
			Gigo.column = Gigo.line = 1;
			break;

		case	7	:
			xgr_bell();
			break;

		case	 8	:
			if ( Gigo.column > 1 ) {
				 Gigo.column--;
				break;
				}
			else if ( Gigo.scrolling != 2 )
				Gigo.column = Gigo.columns;
			else if ( Gigo.line > 1 )
				Gigo.column = Gigo.columns;
			else	break;

		case	11	:
			if ( Gigo.line > 1 ) Gigo.line--;
			break;

		case	 6	:
			if ( Gigo.column < Gigo.columns ) {
				Gigo.column++;
				break;
				}
			else if ( Gigo.scrolling != 2 )
				Gigo.column = 1;
			else if ( Gigo.line != Gigo.lines )
				Gigo.column = 1;
			else	break;

		case	 5	:
		case	'\n'	:
			if ( Gigo.line < Gigo.lines )
				Gigo.line++;
			else 	{ 
				switch ( Gigo.scrolling ) {
					case	0 :	Gigo.line= 1; break;
					case	1 :	scroll_up(1); break;
					case	2 :	break;				
					}
				}
			break;

		default		:
			if ( c >= ' ' ) {
				if ( Gigo.atribut & _GIGO_UPPER ) {
					c = mima(c,0);
					}
				else if ( Gigo.atribut & _GIGO_LOWER ) {
					c = mima(c,1);
					}
#ifdef	_ABAL_DTI
				PixelFontCat(/* IJM */
					( (!(Gigo.direction & _GIGO_R2L)) ?
						((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin+Gigo.xmargin : 
						((Gigo.columns-Gigo.column)*Gigo.fontwidth)+Gigo.leftmargin+Gigo.xmargin 
						),
					( (!(Gigo.direction & _GIGO_B2T)) ?
						((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin+Gigo.ymargin : 
						((Gigo.lines-Gigo.line)*Gigo.fontheight)+Gigo.topmargin+Gigo.ymargin 
						),
					Gigo.workingfont,c);
#else
				PixelFontCat(/* IJM */
					((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin+Gigo.xmargin,
					((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin+Gigo.ymargin,
					Gigo.workingfont,c);
#endif
				xgr_putch(6);
			}
		}
	return;
}


public	int	get_transparence_status()
{
	if (!( Gigo.painter[0] ))
		return(1);
	else	return(0);
}

public	void	set_transparence_status(int v)
{
	if ( v )
		Gigo.painter[0] = 0;
	else	Gigo.painter[0] = 16;
}


#endif	/* _stdgigo_c */

