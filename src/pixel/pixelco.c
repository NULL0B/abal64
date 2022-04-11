#ifndef	_pixelco_c
#define	_pixelco_c

/*	-----------------------------------	*/
/*		P I X E L C O 			*/
/*	-----------------------------------	*/
/*						*/
/*	This file is included by STDGIGO.C	*/
/*						*/
/*	and defines the following functions	*/
/*						*/
/*		textsizelen,	textsize	*/
/*						*/
/*		PixelFontCat,	PixelFontC	*/
/*		PixelFontLat,	PixelFontL	*/
/*		PixelFontSat,	PixelFontS	*/
/*						*/
/*		PixelPutCat,	PixelPutC	*/
/*		PixelPutLat,	PixelPutL	*/
/*		PixelPutSat,	PixelPutS	*/
/*	-----------------------------------	*/

#if defined(WIN32)
#include "pixel.h"
#include "stdgigo.h"
#include "fontapi.h"
#include "gigoapi.h"
#include "stdgigoapi.h"
#include "pixelcoapi.h"

extern struct	gigo_manager	Gigo; 
#endif

/*	--------------------------------------	*/
/*	T E X T S I Z E L E N ( fid, sptr, l )	*/
/*	--------------------------------------	*/
/*	Returns the length in pixels of the 	*/
/*	string sptr of l characters		*/
/*	--------------------------------------	*/

public	struct standard_font * load_dynamic_system_font( char * fnptr, int height );
public	struct	standard_font * load_system_font( char * symbolic );

public 	int	textsizelen(int fid, char * sptr, int l)
{
	char 			* nptr;
	struct	standard_font *	fptr;
	struct	standard_font *	ffptr;
	struct	standard_cell * cptr;
	int	w=0;
	int	i=0;
	int	c;
	if ( fid >= MAX_FONTS)
		return(0);

	else if (!( fptr = Gigo.graphicfonts[fid] ))
		return(0);
	else if ( Gigo.hqfontid ) {
		if (!( ffptr = fptr->hqfont[Gigo.hqfontid-1] )) {
			if (!( nptr = fptr->hqname[Gigo.hqfontid-1] )) {
				if (!( nptr = fptr->hqname[0] ))
					return(0);
				}
			if (!( ffptr = load_dynamic_system_font( nptr, xgr_rescale(fptr->height) ) ))
				return(0);
			else	fptr->hqfont[Gigo.hqfontid-1] = ffptr;
			}	
		fptr = ffptr;
		}

	for (i=0; i < l; i++ ) {
		if (!( c = *(sptr+i) ))
			break;
#ifdef	_ABAL_DTI
		if ( Gigo.direction & _GIGO_R2L )
			c = Gigo.reflection[(c & 0x00FF)];
#endif
		if (!(cptr = fptr->cell[(c & 0x00FF)]))
			break;
		else	w += (cptr->width+Gigo.letter_spacing);
		}

	return(w);	
	
}

/*	--------------------------------------	*/
/*		T E X T S I Z E ( fid, sptr )	*/
/*	--------------------------------------	*/
/*	Returns the length in pixels of the 	*/
/*	string sptr up to the null byte
/*	--------------------------------------	*/

public 	int	textsize(int fid, char * sptr)
{
	return( textsizelen( fid, sptr, strlen(sptr) )  );
}

/*	--------------------------------------	*/
/*	P I X E L F O N T C A T ( x,y , f, c )	*/
/*	--------------------------------------	*/
/*	Displays the character c of the font f	*/
/*	at the x,y screen position		*/
/*	--------------------------------------	*/

public 	int	PixelFontCat(int atx, int aty, int fontid, int c )
{
	int	i;
	char	*		nptr;
	struct	standard_font *	fptr;
	struct	standard_font *	ffptr;
	struct	standard_cell * cptr;
	int	w=0;
#ifdef	TRACE_GIGO_CAT
	printf("PixelFontCat(x=%u,y=%u,f=%u,c=%x)\r\n",atx,aty,fontid,c);
#endif
	if ( fontid >= MAX_FONTS)
		return(atx);

	else if (!( fptr = Gigo.graphicfonts[fontid] ))
		return(atx);
	else if ( Gigo.hqfontid ) {
		if (!( ffptr = fptr->hqfont[Gigo.hqfontid-1] )) {
			if (!( nptr = fptr->hqname[Gigo.hqfontid-1] )) {
				if (!( nptr = fptr->hqname[0] ))
					return(0);
				}
			if (!( ffptr = load_dynamic_system_font( nptr, xgr_rescale(fptr->height) ) ))
				return(0);
			else	fptr->hqfont[Gigo.hqfontid-1] = ffptr;
/*
			if (!( fptr->hqname[Gigo.hqfontid-1] ))
				return(atx);
			else if (!( ffptr = load_system_font( fptr->hqname[Gigo.hqfontid-1] )))
				return(atx);
			else	fptr->hqfont[Gigo.hqfontid-1] = ffptr;
*/
			}	
		fptr = ffptr;
		}
#ifdef	_ABAL_DTI
	if (( c > 180 ) && ( c < 220 ))
		i = 1;
	else	i=  0;			
	if ( Gigo.direction & _GIGO_R2L )
		c = Gigo.reflection[(c & 0x00FF)];
#endif
	if (!(cptr = fptr->cell[(c & 0x00FF)]))
		return(atx);

	if ( Gigo.background ) {
		/* Overwrite the background with colour */
		/* ------------------------------------ */
		putcharacter(
			atx,aty,(w=cptr->width),cptr->height,
			cptr->matrix,
			Gigo.foreground, Gigo.background, 
			Gigo.atribut 
			);

		}
	else	{
		/* The background transparent */
		/* -------------------------- */
		mixcharacter(
			atx,aty,(w=cptr->width),cptr->height,
			cptr->matrix,
			Gigo.foreground,
			Gigo.atribut 
			);
		}
	return(atx+w+Gigo.letter_spacing);	
	
}

/*	--------------------------------------	*/
/*	P I X E L F O N T C     (  f, c )	*/
/*	--------------------------------------	*/
/*	Displays the character c of the font f	*/
/*	at the current screen cursor position	*/
/*	--------------------------------------	*/

public	int	PixelFontC(int fontid,int c )
{
#ifdef	_ABAL_DTI
	int	atx=(	(!(Gigo.direction & _GIGO_R2L)) ?
			((Gigo.column-1)*Gigo.fontwidth) :
			((Gigo.columns-Gigo.column)*Gigo.fontwidth) );
	int	aty=(	(!(Gigo.direction & _GIGO_B2T)) ?
			((Gigo.line-1)*Gigo.fontheight) :
			((Gigo.lines-Gigo.line)*Gigo.fontheight) );
#else
	int	atx=((Gigo.column-1)*Gigo.fontwidth);
	int	aty=((Gigo.line-1)*Gigo.fontheight);
#endif
#ifdef	TRACE_GIGO_C
	printf("PixelFontC(f=%u,c=%x)\r\n",fontid,c);
#endif
	return(PixelFontCat(atx,aty,fontid,c));
}

/*	--------------------------------------	*/
/*	P I X E L F O N T L A T ( x,y , f,s,l)	*/
/*	--------------------------------------	*/
/*	Displays the string of characters s up	*/
/*	to length l at the x,y screen position	*/
/*	using font number f			*/
/*	--------------------------------------	*/

public	int	PixelFontLat(int atx, int aty, int fontid,unsigned  char * sptr, int l )
{
	unsigned int	c;
#ifdef	TRACE_GIGO_LAT
	printf("PixelFontLat(x=%u,y=%u,f=%u,l=%u)\r\n",atx,aty,fontid,l);
#endif
	for (	; l > 0; l-- ) {
		if (!(c = *(sptr++)))
			break;
		else	atx = PixelFontCat(atx,aty,fontid,(c&0x00FF) );
		}
	return( atx );
}


/*	--------------------------------------	*/
/*	P I X E L F O N T S A T ( x,y , f,s )	*/
/*	--------------------------------------	*/
/*	Displays the string of characters s up	*/
/*	to null byte at   x,y screen position	*/
/*	using font number f			*/
/*	--------------------------------------	*/

public	int	PixelFontSat(int atx, int aty,int fontid, char * sptr )
{
#ifdef	TRACE_GIGO_SAT
	printf("PixelFontSat(x=%u,y=%u,f=%u,s=%s)\r\n",atx,aty,fontid,sptr);
#endif
	while ( *sptr )
		atx = PixelFontCat(atx,aty,fontid,*(sptr++) );
	return( atx );
}

/*	--------------------------------------	*/
/*	P I X E L  P U T  L A T ( x,y , s,l ) 	*/
/*	--------------------------------------	*/
/*	Displays the string of characters s up	*/
/*	to length l at the x,y screen position	*/
/*	using the current font value		*/
/*	--------------------------------------	*/

public	int	PixelPutLat(int atx, int aty, char * sptr, int l)
{
	return(PixelFontLat(atx,aty,Gigo.currentfont,sptr,l));
}

/*	--------------------------------------	*/
/*	P I X E L  P U T  L     (  s , l )    	*/
/*	--------------------------------------	*/
/*	Displays the string of characters s up	*/
/*	to length l at the current cursor     	*/
/*	using the current font value		*/
/*	--------------------------------------	*/

public	int	PixelPutL( char * sptr, int l )
{
#ifdef	_ABAL_DTI
	int	atx=(	(!(Gigo.direction & _GIGO_R2L)) ?
			((Gigo.column-1)*Gigo.fontwidth):
			((Gigo.columns-Gigo.column)*Gigo.fontwidth) )+Gigo.leftmargin;
	int	aty=(	(!(Gigo.direction & _GIGO_B2T)) ?
			((Gigo.line-1)*Gigo.fontheight):
			((Gigo.lines-Gigo.line)*Gigo.fontheight) )+Gigo.topmargin;
#else
	int	atx=((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin;
	int	aty=((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin;
#endif
	return(PixelFontLat(atx,aty,Gigo.currentfont,sptr,l));
}

/*	--------------------------------------	*/
/*	P I X E L F O N T L    ( f,s,l)		*/
/*	--------------------------------------	*/
/*	Displays the string of characters s up	*/
/*	to length l at the textcursor position	*/
/*	using font number f			*/
/*	--------------------------------------	*/

public	int	PixelFontL(int fontid, char * sptr, int l )
{
#ifdef	_ABAL_DTI
	int	atx=(	(!(Gigo.direction & _GIGO_R2L)) ?
			((Gigo.column-1)*Gigo.fontwidth):
			((Gigo.columns-Gigo.column)*Gigo.fontwidth) )+Gigo.leftmargin;
	int	aty=(	(!(Gigo.direction & _GIGO_B2T)) ?
			((Gigo.line-1)*Gigo.fontheight):
			((Gigo.lines-Gigo.line)*Gigo.fontheight) )+Gigo.topmargin;
#else
	int	atx=((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin;
	int	aty=((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin;
#endif
	return(PixelFontLat(atx,aty,fontid,sptr,l));
}

/*	--------------------------------------	*/
/*	P i x e l F o n t S    ( f,s )		*/
/*	--------------------------------------	*/
/*	Displays the string of characters s up	*/
/*	to nullbyte at the textcursor position	*/
/*	using font number f			*/
/*	--------------------------------------	*/

public	int	PixelFontS(int fontid, char * sptr )
{
#ifdef	_ABAL_DTI
	int	atx=(	(!(Gigo.direction & _GIGO_R2L)) ?
			((Gigo.column-1)*Gigo.fontwidth):
			((Gigo.columns-Gigo.column)*Gigo.fontwidth) )+Gigo.leftmargin;
	int	aty=(	(!(Gigo.direction & _GIGO_B2T)) ?
			((Gigo.line-1)*Gigo.fontheight):
			((Gigo.lines-Gigo.line)*Gigo.fontheight) )+Gigo.topmargin;
#else
	int	atx=((Gigo.column-1)*Gigo.fontwidth);
	int	aty=((Gigo.line-1)*Gigo.fontheight);
#endif
	return(PixelFontSat(atx,aty,fontid,sptr));
}

/*	--------------------------------------	*/
/*	P i x e l  P u t  S a t( x,y, s )	*/
/*	--------------------------------------	*/
/*	Displays the string of characters s up	*/
/*	to nullbyte at the x,y screen position	*/
/*	using font number f			*/
/*	--------------------------------------	*/

public	int	PixelPutSat( int atx, int aty, char * sptr)
{
	return(PixelFontSat(atx,aty,Gigo.currentfont,sptr));
}

/*	--------------------------------------	*/
/*	P i x e l  P u t  S    ( s )		*/
/*	--------------------------------------	*/
/*	Displays the string of characters s up	*/
/*	to nullbyte at the textcursor position	*/
/*	using the current default font		*/
/*	--------------------------------------	*/

public	int	PixelPutS( char * sptr )
{
#ifdef	_ABAL_DTI
	int	atx=(	(!(Gigo.direction & _GIGO_R2L)) ?
			((Gigo.column-1)*Gigo.fontwidth):
			((Gigo.columns-Gigo.column)*Gigo.fontwidth) )+Gigo.leftmargin;
	int	aty=(	(!(Gigo.direction & _GIGO_B2T)) ?
			((Gigo.line-1)*Gigo.fontheight):
			((Gigo.lines-Gigo.line)*Gigo.fontheight) )+Gigo.topmargin;
#else
	int	atx=((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin;
	int	aty=((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin;
#endif
	return(PixelFontSat(atx,aty,Gigo.currentfont,sptr));
}

/*	--------------------------------------	*/
/*	P i x e l  P u t  C a t( x,y, c )	*/
/*	--------------------------------------	*/
/*	Displays the character c at the x,y 	*/
/*	screen position using the current font	*/
/*	--------------------------------------	*/

public	int	PixelPutCat(int atx, int aty, int c )
{
	return(PixelFontCat(atx,aty,Gigo.currentfont,c));
}

/*	--------------------------------------	*/
/*	P i x e l  P u t  C    ( c )		*/
/*	--------------------------------------	*/
/*	Displays the character c at the text	*/
/*	cursor position using the current font	*/
/*	--------------------------------------	*/

public	int	PixelPutC( int c )
{
#ifdef	_ABAL_DTI
	int	atx=(	(!(Gigo.direction & _GIGO_R2L)) ?
			((Gigo.column-1)*Gigo.fontwidth):
			((Gigo.columns-Gigo.column)*Gigo.fontwidth) )+Gigo.leftmargin;
	int	aty=(	(!(Gigo.direction & _GIGO_B2T)) ?
			((Gigo.line-1)*Gigo.fontheight):
			((Gigo.lines-Gigo.line)*Gigo.fontheight) )+Gigo.topmargin;
#else
	int	atx=((Gigo.column-1)*Gigo.fontwidth)+Gigo.leftmargin;
	int	aty=((Gigo.line-1)*Gigo.fontheight)+Gigo.topmargin;
#endif
	return(PixelFontCat(atx,aty,Gigo.currentfont,c));
}


/*	-----------------------------------------	*/
/*	S e t C i c o P i x e l C o l u m n ( x )	*/
/*	-----------------------------------------	*/
/*	Sets the current text column from the x		*/
/*	graphical pixel column value using the		*/
/*	current base font grid width value		*/
/*	-----------------------------------------	*/

public	int	SetCicoPixelColumn( int x )
{
	return((Gigo.column = ((x / Gigo.fontwidth) + 1)));
}

/*	--------------------------------------	*/
/*	c i c o a t r i b u t  ( v )		*/
/*	--------------------------------------	*/
/*	Sets the current value of the GIGO   	*/
/*	text atributs to the value v returning	*/
/*	the previous value to the caller.	*/
/*	--------------------------------------	*/

public	int	cicoatribut(int v)
{
	int r=Gigo.atribut;
	Gigo.atribut =v;
	return(r);
}

/*	--------------------------------------	*/
/*	C i c o F o n t M a r g i n ( x ) 	*/
/*	--------------------------------------	*/
/*	Sets the right edge limit to use as the	*/
/*	absolut right margin. Returns previous	*/
/*	value to caller.			*/
/*	--------------------------------------	*/

public	int	CicoFontMargin(int x)
{
	int	holder=XGC.rightmargin;
	XGC.rightmargin = x;
	return( holder );
}

/*	------------------------------------------------	*/
/*	c i c o p a g e m a r g i n s ( lm, rm, tm, bm )	*/
/*	------------------------------------------------	*/
/*	Checks for legal values and then sets the GIGO		*/
/*	margin values to be used for text clipping with		*/
/*	in the defined zone. The text zone size will be 	*/
/*	recalculated using the current font dimensions		*/
/*	to be made avalable to the application via the		*/
/*	standard instructions CONF to this effect.		*/ 
/*	------------------------------------------------	*/

public	int	cicopagemargins(int lm, int rm, int tm, int bm )
{
/*
 *	IJM 7/7/2005
 *	------------
 *	This clipping has been removed as it is no longer necessary
 *	since the low level routines perform thesame role but better.
 *	if ((lm+rm) > XGC.width )
 *		return(103);
 *	if ((tm+bm) > XGC.height )
 *		return(103);
 *	else	{
 */
		Gigo.leftmargin = lm;
		Gigo.rightmargin = rm;
		Gigo.topmargin = tm;
		Gigo.bottommargin = bm;
		Gigo.width = (XGC.width - (lm+rm));
		Gigo.height = (XGC.height - (tm+bm));
		return( use_base_font( Gigo.currentfont ) );
/*		}	*/
}

public	int	sethqfont(int v)
{
	switch ( v ) {
		case	  75	:	Gigo.hqfontid = 0; xgr_set_scale( 0); break;
		case	 150	:	Gigo.hqfontid = 1; xgr_set_scale( 2); break;
		case	 300	:	Gigo.hqfontid = 2; xgr_set_scale( 4); break;
		case	 600	:	Gigo.hqfontid = 3; xgr_set_scale( 8); break;
		case	1200	:	Gigo.hqfontid = 4; xgr_set_scale(16); break;
		case	2400	:	Gigo.hqfontid = 5; xgr_set_scale(32); break;
		case	4800	:	Gigo.hqfontid = 6; xgr_set_scale(64); break;
		default		:	Gigo.hqfontid = 7; xgr_set_scale(v);  break;
		}
	return(0);
}	

public	int	gethqfont()
{
	switch ( Gigo.hqfontid ) {
		case	0 : return(  75);
		case	1 : return( 150);
		case	2 : return( 300);
		case	3 : return( 600);
		case	4 : return(1200);
		case	5 : return(2400);
		case	6 : return(4800);
		case	7 : return(xgr_get_scale());
		}
	return( 0 );
}

/*	----------------------------------	*/
/*	c i c o w i n d o w ( x, y, w, h )	*/
/*	----------------------------------	*/
/*	Sets the cico text margins to create	*/
/*	the required text clipping window.	*/
/*	----------------------------------	*/

public	int	cicowindow(int atx, int aty, int nbx, int nby )
{
/*
 *	IJM 7/7/2005
 *	------------
 *	This clipping has been removed as it is no longer necessary
 *	since the low level routines perform thesame role but better.
 *	if (( atx > XGC.width )
 *	||  ( aty > XGC.height)
 *	||  ( (atx+nbx) > XGC.width )
 *	||  ( (aty+nby) > XGC.height ))
 *		return(103);
 *	else	
 */
	return( cicopagemargins( 
		atx,(nbx ? (XGC.width - (atx+nbx)) : nbx ), 
		aty,(nby ? (XGC.height- (aty+nby)) : nby ) ) );
}

/*	---------------------------------------------	*/
/*	V i e w		P o r t 	C o n t r o l	*/
/*	---------------------------------------------	*/
struct	viewport_control {
	int	lm;
	int	rm;
	int	tm;
	int	bm;
	int	w;
	int	h;
	int	gridfont;
	int	textfont;
	int	atcolumn;
	int	atline;
	int	nbcolumns;
	int	nblines;
	int	alignment;
	int	scrolling;
	} VPK;


/*	-------------------------------------------------------------------------------------------------------	*/
/*	GET and SET CICO VIEWPORT are used by EXADB to manage program and debug viewporting and print ask FONTS */
/*	-------------------------------------------------------------------------------------------------------	*/
public	int	get_cico_viewport( struct viewport_control * vptr )
{
	if (!( vptr ))
		return(0);
	else 	{
		vptr->lm = Gigo.leftmargin;
		vptr->rm = Gigo.rightmargin;
		vptr->tm = Gigo.topmargin;
		vptr->bm = Gigo.bottommargin;
		vptr->gridfont = Gigo.currentfont;
		vptr->textfont = Gigo.workingfont;
		return(1);
		}
}

public	int	set_cico_viewport( struct viewport_control * vptr )
{
	if (!( vptr ))
		return(118);
	else 	{
		Gigo.workingfont=Gigo.currentfont=vptr->gridfont;
		(void) cicopagemargins( vptr->lm , vptr->rm, vptr->tm , vptr->bm );
		if( vptr->gridfont != vptr->textfont )
			apply_font_margin( vptr->textfont );
		else	cancel_font_margin();
		return(0);
		}
}

/*	These functions return the values required by x_event(200->207)	*/
/*	They are in order 200 -> 207 ! */

public	int	 cico_top_margin() 	{ return( Gigo.topmargin );	}
public	int	 cico_right_margin()	{ return( Gigo.rightmargin ); 	}
public	int	 cico_bottom_margin()	{ return( Gigo.bottommargin ); 	}
public	int	 cico_left_margin() 	{ return( Gigo.leftmargin ); 	}

public	int	 cico_cell_height()
{ 
	int	gfw,gfh;
	if (!( VPK.gridfont )) 
		return( Gigo.fontheight );
	else	{
		gfw = guifontsize(VPK.gridfont);
		gfh = ((gfw >> 8) & 0x00FF);	
		gfw = (gfw & 0x00FF);
		}
	return( gfh );
}

public	int	 cico_cell_width() 	
{ 
	if (!( VPK.gridfont ))
		return( Gigo.fontwidth );
	else	return(( guifontsize(VPK.gridfont) & 0x00FF));
}

public	int	 cico_page_width() 	{ 	return( Gigo.width );		}
public	int	 cico_page_height() 	{ 	return( Gigo.height );		}
public	int	 cico_cell_ymargin() 	{ 	return( Gigo.ymargin );		}
public	int	 cico_cell_xmargin() 	{ 	return( Gigo.xmargin );		}
public	int	 cico_font_number()	{	return( Gigo.currentfont );	}
	
/*	-------------------------------------------------	*/
/*	n e s t e d _ v i e w p o r t ( f, a, c, l, nbl )	*/
/*	-------------------------------------------------	*/
/*	Creates a nested viewport, saving the current		*/
/*	text window clipping and view port conditions		*/
/*	prior to establishing the new requirements		*/
/*	-------------------------------------------------	*/

public	int	nested_viewport( int f, int a, int * c, int * l, int nbl )
{
	int	gratx,graty,grnbx,grnby;
	int	gfh,gfw;
	int	tfh,tfw;
	int	xfh,xfw;

	VPK.scrolling = Gigo.scrolling;
	VPK.lm = Gigo.leftmargin;	VPK.tm = Gigo.topmargin;
	VPK.rm = Gigo.rightmargin;	VPK.bm = Gigo.bottommargin;
	VPK.w  = Gigo.width;		VPK.h  = Gigo.height;
	VPK.gridfont = Gigo.currentfont;
	VPK.textfont = f;		VPK.alignment= a;
	VPK.atcolumn = *c;		VPK.atline   = *l;
	VPK.nblines  = 1;		VPK.nbcolumns= nbl;
	gfw = guifontsize(VPK.gridfont);
	gfh = ((gfw >> 8) & 0x00FF);	gfw = (gfw & 0x00FF);
	tfw = guifontsize(VPK.textfont);
	tfh = ((tfw >> 8) & 0x00FF);	tfw = (tfw & 0x00FF);
	Gigo.scrolling = 0;

	if ( VPK.atcolumn )
		gratx = ((VPK.atcolumn-1)*gfw);
	else	gratx =0;
	if ( VPK.atline )
		graty = ((VPK.atline-1)*gfh);
	else	graty = 0;

	if ( VPK.nbcolumns )
		grnbx = (VPK.nbcolumns*tfw);
	else	return(0);

	if ( VPK.nblines )
		grnby = (VPK.nblines*tfh);
	else	return(0);

	Gigo.currentfont = VPK.textfont;

	switch ( VPK.alignment ) {
		case	1	:	
			xfh=( gfh > tfh ? (gfh - tfh) : 0);
			xfw=( gfw > tfw ? (gfw - tfw) : 0);
			break;
		case	3	:	
			xfh=( gfh > tfh ? ((gfh - tfh)/2) : 0);
			xfw=( gfw > tfw ? ((gfw - tfw)/2) : 0);
			break;
		default		:
			xfh = xfw = 0;
			break;
		}

	if ( cicowindow(gratx+xfw,graty+xfh,grnbx,grnby) != 0 )
		return( 0 );
	else	{
		*c = 1; *l = 1;
		esc_f(0x20,0x20);
		return(1);
		}
}

/*	--------------------------------------------	*/
/*	    p o p  _ v i e w p o r t ( n, c, l )	*/
/*	--------------------------------------------	*/
/*	Restores a previously stored view port		*/
/*	--------------------------------------------	*/

public	void	pop_viewport( int n, int * c, int * l )
{
	*c = VPK.atcolumn; *l = VPK.atline;
	Gigo.leftmargin   = VPK.lm;
	Gigo.rightmargin  = VPK.rm;
	Gigo.topmargin    = VPK.tm;
	Gigo.bottommargin = VPK.bm;
	Gigo.width        = VPK.w;
	Gigo.height       = VPK.h;
	Gigo.scrolling    = VPK.scrolling;
	use_base_font((Gigo.currentfont = VPK.gridfont));
	return;
}

/*	-------------------------------------		*/
/*	a p p l y  _ f o n t _ m a r g i n(f)		*/
/*	-------------------------------------		*/
/*	Sets the font f to be used as the current	*/
/*	working font for all subsequent CO text.	*/
/*	The font is intended to be smaller than		*/
/*	The base or grid font giving rise to the	*/
/*	calculation of the font margin values		*/
/*	to be used to position the characters		*/
/*	within the standard base or grid font		*/
/*	character cells.				*/
/*	-------------------------------------		*/

public	int	apply_font_margin( int fontid )
{
	int	f=Gigo.currentfont;
	int	ofw;
	int	ofh;
	int	nfw;
	int	nfh;
	int	xfw;
	int	xfh;
	ofw = guifontsize(f);
	ofh = (ofw >> 8); ofw &= 0x00FF;
	nfw = guifontsize(fontid);
	nfh = (nfw >> 8); nfw &= 0x00FF;
	xfw = (nfw < ofw ? (ofw - nfw)/2 : 0 );
	xfh = (nfh < ofh ? (ofh - nfh)/2 : 0 );
	Gigo.xfontwidth  = nfw;
	Gigo.yfontheight = nfh;
	Gigo.xmargin= xfw;
	Gigo.ymargin= xfh;
	Gigo.workingfont = fontid;
	return(f);
}

/*	-------------------------------------		*/
/*	c a n c e l _ f o n t _ m a r g i n()		*/
/*	-------------------------------------		*/
/*	Cancels any font margin behaviour.		*/
/*	-------------------------------------		*/

public	int	cancel_font_margin()
{
	Gigo.xmargin= 0;
	Gigo.ymargin= 0;
	Gigo.xfontwidth = Gigo.fontwidth;
	Gigo.yfontheight = Gigo.fontheight;
	Gigo.workingfont=Gigo.currentfont;
	return(0);
}

#endif	/* _pixelco_c */

