#ifndef	_PSIII_C
#define	_PSIII_C

#include "lodriver.h"

#include "psiii.h"
#include "vimage.h"
#include "isolatin.h"

#ifdef UNIX

#define Portable_getenv	getenv

#else

#include "allocate.h"
#include "rgraphapi.h"
char* Getenv_from_exa(const char* env);
#define Portable_getenv	Getenv_from_exa

#define private static

#endif

#define	_POSTSCRIPT_LINESIZE	64000
static	char * 	PaletteBuffer=(char *) 0;
static	char * 	RasterByte=(char *) 0;
static	char * 	RasterWork=(char *) 0;
static	int	RasterReady=0;
static	int	PrinterReady=0;
static	int	RowNumber=0;
static	int	RowCount=0;
static	int	TopMargin=0;
static	int	LeftMargin=0;
static	int	BottomMargin=0;
static	int	RightMargin=0;
static	int	TopBorder=13;
static	int	LeftBorder=14;
static	int	ColCount=0;
static	int	PageOptions=0;
static	int	Density=0;
static	int	PageCount=0;
static	int	ShowFontSize=16;
static	int	Landscaping=0;
static	int	HighQuality=0;
static	int	CalculateMargins=0;

char*	get_paper_name();
static	char *	decimal(char * wptr, int v );

int	_fltused=0;
void	_cfltcvt()	{ 	return; 	}
void	_cropzeros()	{ 	return; 	}
long	_aFftol()	{	return(0L);	}

static	int	max_red  =_RED_MASK32;
static	int	max_green=_GREEN_MASK32;
static	int	max_blue =_BLUE_MASK32;
static	int	IsoLatin=0;
static	char *	IsoLatinPs=(char *) 0;
static	char *	EnvPageControl=(char *) 0;

static	char * 	StoragePath=(char *) 0;
static	FILE *	Storage=(FILE*) 0;
static	char 	StorageName[256];
static	int	StorageMode=0;

static struct	postscript_font	{
	char *	name;
	char *	bold;
	char *	italic;
	char * 	both;
	int	size;
	int	width;
	char *	info;
	} PsFont[256] = {

	/* 0 */		"f8","f9","f11","f10",12,0,"\0",	/* fixed */
	/* 1 */		"f8","f9","f11","f10",12,0,"\0",	/* fixed */
	/* 2 */		"f0","f1","f3","f2",12,0,"\0",
	/* 3 */		"f0","f1","f3","f2",14,0,"\0",
	/* 4 */		"f0","f1","f3","f2",18,0,"\0",
	/* 5 */		"f0","f1","f3","f2",21,0,"\0",
	/* 6 */		"f0","f1","f3","f2",24,0,"\0",
	/* 7 */		"f4","f5","f7","f6",14,0,"\0",
	/* 8 */		"f8","f9","f11","f10",8,0,"\0",
	/* 9 */		"f4","f5","f7","f6",16,0,"\0"

	};

#define	_MAX_PS_FONTS 13

static	char *	ps_font_name[64] = {
	"Times-Roman",		"Times-Bold",	"Times-BoldItalic",		"Times-Italic",
	"Helvetica",		"Helvetica-Bold","Helvetica-BoldOblique",	"Helvetica-Oblique",
	"Courier",		"Courier-Bold",	"Courier-BoldOblique",		"Courier-Oblique",
	"Symbol",
	(char *) 0
	};

static	int	MaxPsFonts=_MAX_PS_FONTS;

int	debug_font_number( int f )
{
	printf("font : %u : %s, %s, %s, %s, : %u %u \n",f,
		PsFont[f].name,
		PsFont[f].bold,
		PsFont[f].italic,
		PsFont[f].both,
		PsFont[f].size,
		PsFont[f].width );
	return;
}
 
static	void	reset_global_context()
{
	max_red  =_RED_MASK32;
	max_green=_GREEN_MASK32;
	max_blue =_BLUE_MASK32;
	IsoLatin=0;
	IsoLatinPs=(char *) 0;
	Storage=(FILE*) 0;
	StorageMode=0;
 	PaletteBuffer=(char *) 0;
	RasterByte=(char *) 0;
 	RasterWork=(char *) 0;
	RasterReady=0;
	PrinterReady=0;
	RowNumber=0;
	RowCount=0;
	TopMargin=0;
	LeftMargin=0;
	BottomMargin=0;
	RightMargin=0;
	TopBorder=13;
	LeftBorder=14;
	ColCount=0;
	PageOptions=0;
	Density=0;
	PageCount=0;
	ShowFontSize=16;
	Landscaping=0;
	HighQuality=0;
	return;
}

/*	---------------------------------------------------		*/
/*	colour manager	S E T _ W H I T E _ L I M I T ( x )		*/
/*	---------------------------------------------------		*/

void	set_white_limit(int pixeltype )
{
	switch ( pixeltype ) {
		case	1 :
			max_red  =_RED_MASK8;
			max_green=_GREEN_MASK8;
			max_blue =_BLUE_MASK8;
			break;
		case	2  :
			max_red  =_RED_MASK16;
			max_green=_GREEN_MASK16;
			max_blue =_BLUE_MASK16;
			break;
		case	4  :
			max_red  =_RED_MASK32;
			max_green=_GREEN_MASK32;
			max_blue =_BLUE_MASK32;
			break;
		}
	return;
}

/*	---------------------------------------		*/
/*	colour manager	N O T _ W H I T E ( x )		*/
/*	---------------------------------------		*/

int	not_white( int x )
{
	int	r;
	int	g;
	int	b;
	if ( colourmapping ) {
		if (( x == 15 ) || ( x == 31 ))
			return(0);
		else	return(1);
		}
	else	{
		extract_colour(x,&r,&g,&b);
		if (( r >= max_red ) && ( g >= max_green ) && ( b >= max_blue ))
			return(0);
		else	return(1);
		}
}

/*	-----------------------------------	*/
/*	PostScript Operator	M O V E T O	*/
/*	-----------------------------------	*/
static	char *	movexyto(char * bptr, int x,int y)
{
	sprintf(bptr,"%u %u m ",x,y); 
	return( (bptr + strlen(bptr)) );
}
static	char *	moveto(char * bptr, int x)
{
	sprintf(bptr,"%u %u m ",LeftBorder+LeftMargin+x,TopBorder+BottomMargin+(RowCount-RowNumber));
	return( (bptr + strlen(bptr)) );
}

/*	-----------------------------------	*/
/*	PostScript Operator	L I N E T O	*/
/*	-----------------------------------	*/
static	char *	lineto(char * bptr, int x)
{
	sprintf(bptr,"%u %u l ",x,0);
	return( (bptr + strlen(bptr)));
}

/*	-----------------------------------	*/
/*	PostScript Operator	L I N E T O	*/
/*	-----------------------------------	*/
static	char *	linexyto(char * bptr, int x ,int y)
{
	sprintf(bptr,"%u %u l ",x,y);
	return( (bptr + strlen(bptr)));
}

/*	-----------------------------------	*/
/*	PostScript Operator	S T R O K E	*/
/*	-----------------------------------	*/
static	char *	stroke(char * bptr, int x)
{
	int	a;
	int	n;
	char	buffer[16];
	if ( PageOptions & _FORCE_GRAYSCALE ) {
		a = colour_map_luminence(( x & 0x00FF));
		a = ((a*10)/256);
		sprintf(bptr,"0.%u p ",a);	 			
		}
	else	{
		sprintf(bptr,"y%x p ",(x & 0x00FF));
		}
	return( (bptr + strlen(bptr)) );
}
		
/*	-----------------------------------	*/
/*	PostScript Operand 	Z.Z3       	*/
/*	-----------------------------------	*/
static	char * zazzzx( char * rptr, int v )
{
	char 	buffer[16];
	if ( v >= 100 )
		sprintf(rptr,"0.%03.1u ",v);
	else if ( v >= 10 )
		sprintf(rptr,"0.0%02.1u ",v);
	else	sprintf(rptr,"0.00%u ",v);
	rptr += strlen( rptr );
	return( rptr );
}

/*	-----------------------------------	*/
/*	PostScript Operand 	Z.Z3       	*/
/*	-----------------------------------	*/
static	void	pzazzzx( char * rptr, int v )
{
	if ( v >= 100 )
		printf(" 0.%03.1u",v);
	else if ( v >= 10 )
		printf(" 0.0%02.1u",v);
	else	printf(" 0.00%u",v);
}

/*	-----------------------------------	*/
/*	PostScript Operator	 P A I N T 	*/
/*	-----------------------------------	*/
static	char *	paint(char * bptr, int x)
{
	int	r=0;
	int	b=0;
	int	g=0;
	int	a;
	int	n;
	if ( PageOptions & _FORCE_GRAYSCALE ) {
		a = colour_map_luminence(( x & 0x00FF));
		a = ((a*10)/256);
		sprintf(bptr,"0.%u srgb ",a);	 			
		}
	else	{
		extract_colour(x,&r,&g,&b);	

/*		printf("extracted colour (r=%u, g=%u, b=%u) from 0x0%x ",r,g,b,x);	*/

		r = ((r*1000)/(redmask+1));	bptr = zazzzx(bptr,r);
		g = ((g*1000)/(greenmask+1));	bptr = zazzzx(bptr,g);
		b = ((b*1000)/(bluemask+1));	bptr = zazzzx(bptr,b);

		sprintf(bptr,"p\n");
		}
	return( (bptr + strlen(bptr)) );
}

private	void	flush_storage(char * wptr)
{
	if ( Storage ) { fprintf(Storage,"%s",wptr); }
	return;
}

private	void	ps_hq_circle(char * wptr, struct text_item * tptr )
{
	int	cx;
	int	cy;
	int	d;

	cx = (LeftBorder+LeftMargin+(((tptr->atx+(tptr->w/2))*Density)/75));
	cy = (TopBorder+BottomMargin+(RowCount-(((tptr->aty+(tptr->h/2))*Density)/75)));
	d  = (((( tptr->w > tptr->h ? tptr->h : tptr->w ) / 2)*Density)/75);

	switch ( tptr->align & 15 ) {

		case	4	:	/* top left */
			sprintf(wptr,"%u setlinewidth newpath %u %u %u 90 180 arc stroke\n",
				(Density/75),cx,cy,d);
			break;
		case	8	:	/* top left */
			sprintf(wptr,"newpath %u %u m %u %u %u 90 180 arc %u %u lineto fill\n",
				cx,cy,cx,cy,d,cx,cy);
			break;

		case	5	:	/* top right */
			sprintf(wptr,"%u setlinewidth newpath %u %u %u 360 90 arc stroke\n",
				(Density/75),cx,cy,d);
			break;

		case	9	:	/* top right */
			sprintf(wptr,"newpath %u %u m %u %u %u 360 90 arc %u %u lineto fill\n",
				cx,cy,cx,cy,d,cx,cy);
			break;


		case	6	:	/* bottom left */
			sprintf(wptr,"%u setlinewidth newpath %u %u %u 180 270 arc stroke\n",
				(Density/75),cx,cy,d);
			break;


		case	10	:	/* bottom left */
			sprintf(wptr,"newpath %u %u m %u %u %u 180 270 arc %u %u lineto fill\n",
				cx,cy,cx,cy,d,cx,cy);
			break;


		case	7	:	/* bottom right */
			sprintf(wptr,"%u setlinewidth newpath %u %u %u 270 360 arc stroke\n",
				(Density/75),cx,cy,d);
			break;

		case	11	:	/* bottom right */

			sprintf(wptr,"newpath %u %u m %u %u %u 270 360 arc %u %u lineto fill\n",
				cx,cy,cx,cy,d,cx,cy);
			break;


		case	 0	:	/* standard outline */

			sprintf(wptr,"%u setlinewidth newpath %u %u %u 360 0 arcn stroke\n",
				(Density/75),cx,cy,d);
			break;

		case	 1	:	/* standard filled */

			sprintf(wptr,"newpath %u %u %u 360 0 arcn fill\n",cx,cy,d);
			break;

		default		:	*wptr = 0;
		}
	flush_storage(wptr);
	return;
}

private	void	ps_circle(char * wptr, struct text_item * tptr )
{
	int	cx;
	int	cy;
	int	d;
	cx = (LeftBorder+LeftMargin+(((tptr->atx+(tptr->w/2)))));
	cy = (TopBorder+BottomMargin+(RowCount-(((tptr->aty+(tptr->h/2))))));
	d  = (((( tptr->w > tptr->h ? tptr->w : tptr->h ) / 2)));
	switch ( tptr->align & 15 ) {

		case	4	:	/* top left */
			sprintf(wptr,"1 setlinewidth newpath %u %u %u 90 180 arc stroke\n",
				cx,cy,d);
			break;
		case	8	:	/* top left */
			sprintf(wptr,"newpath %u %u moveto %u %u %u 90 180 arc %u %u lineto fill\n",
				cx,cy,cx,cy,d,cx,cy);
			break;

		case	5	:	/* top right */
			sprintf(wptr,"1 setlinewidth newpath %u %u %u 360 90 arc stroke\n",
				cx,cy,d);
			break;

		case	9	:	/* top right */
			sprintf(wptr,"newpath %u %u moveto %u %u %u 360 90 arc %u %u lineto fill\n",
				cx,cy,cx,cy,d,cx,cy);
			break;


		case	6	:	/* bottom left */
			sprintf(wptr,"1 setlinewidth newpath %u %u %u 180 270 arc stroke\n",
				cx,cy,d);
			break;


		case	10	:	/* bottom left */
			sprintf(wptr,"newpath %u %u m %u %u %u 180 270 arc %u %u lineto fill\n",
				cx,cy,cx,cy,d,cx,cy);
			break;


		case	7	:	/* bottom right */
			sprintf(wptr,"1 setlinewidth newpath %u %u %u 270 360 arc stroke\n",
				cx,cy,d);
			break;


		case	11	:	/* bottom right */
			sprintf(wptr,"newpath %u %u m %u %u %u 270 360 arc %u %u lineto fill\n",
				cx,cy,cx,cy,d,cx,cy);
			break;

		case	 0	:	/* standard outline */

			sprintf(wptr,"newpath 1 setlinewidth %u %u %u 360 0 arcn stroke\n",
				cx,cy,d);
			break;

		case	 1	:	/* standard filled  */

			sprintf(wptr,"newpath %u %u %u 360 0 arcn fill\n",cx,cy,d);
			break;

		default		:	*wptr = 0;
		}

	flush_storage(wptr);
	return;
}

private	void	ps_hq_line(char * wptr, struct text_item * tptr )
{
	sprintf(wptr,"%u setlinewidth %u %u m %u %u lineto stroke\n",
			((tptr->align*Density)/75),
			(LeftBorder+LeftMargin+((tptr->atx*Density)/75)),
			(TopBorder+BottomMargin+(RowCount-((tptr->aty*Density)/75))),
			(LeftBorder+LeftMargin+((tptr->w*Density)/75)),
			(TopBorder+BottomMargin+(RowCount-((tptr->h*Density)/75)))
			);
	flush_storage(wptr);
	return;
}

private	void	ps_line(char * wptr, struct text_item * tptr )
{
	sprintf(wptr,"%u setlinewidth %u %u m %u %u lineto stroke\n",
			tptr->align,
			(LeftBorder+LeftMargin+tptr->atx),
			(TopBorder+BottomMargin+(RowCount-tptr->aty)),
			(LeftBorder+LeftMargin+tptr->w),
			(TopBorder+BottomMargin+(RowCount-tptr->h))
			);
	flush_storage(wptr);
	return;
}

private	void	ps_hq_fill(char * wptr, struct text_item * tptr )
{
	sprintf(wptr,"%u %u m %u %u lineto %u %u lineto %u %u lineto closepath fill\n",
		(LeftBorder+LeftMargin+((tptr->atx*Density)/75)),
		(TopBorder+BottomMargin+(RowCount-((tptr->aty*Density)/75))),
		(LeftBorder+LeftMargin+(((tptr->atx+tptr->w)*Density)/75)),
		(TopBorder+BottomMargin+(RowCount-((tptr->aty*Density)/75))),
		(LeftBorder+LeftMargin+(((tptr->atx+tptr->w)*Density)/75)),
		(TopBorder+BottomMargin+(RowCount-(((tptr->aty+tptr->h)*Density)/75))),
		(LeftBorder+LeftMargin+(((tptr->atx)*Density)/75)),
		(TopBorder+BottomMargin+(RowCount-(((tptr->aty+tptr->h)*Density)/75)))
		);
	flush_storage(wptr);
	return;
}

private	void	ps_fill(char * wptr, struct text_item * tptr )
{
	sprintf(wptr,"%u %u m %u %u lineto %u %u lineto %u %u lineto closepath fill\n",
		(LeftBorder+LeftMargin+((tptr->atx))),
		(TopBorder+BottomMargin+(RowCount-((tptr->aty)))),
		(LeftBorder+LeftMargin+(((tptr->atx+tptr->w)))),
		(TopBorder+BottomMargin+(RowCount-((tptr->aty)))),
		(LeftBorder+LeftMargin+(((tptr->atx+tptr->w)))),
		(TopBorder+BottomMargin+(RowCount-(((tptr->aty+tptr->h))))),
		(LeftBorder+LeftMargin+((tptr->atx))),
		(TopBorder+BottomMargin+(RowCount-(((tptr->aty+tptr->h)))))
		);
	flush_storage(wptr);
	return;
}

/*FCH24022006 begin */
private	void	ps_roundfill(char * wptr, struct text_item * tptr )
{
	int	x = tptr->atx;
	int	y = tptr->aty;
	int	w = tptr->w;
	int	h = tptr->h;
	int	v;
	v = ( w > h ? h : w );
	v /= 8;
	if (!( v )) {
		ps_fill(wptr,tptr); 
		}
	else	{
		tptr->atx = x+(v/2); tptr->aty = y      ; tptr->w = w-v; tptr->h=h  ; ps_fill(wptr,tptr);
		tptr->atx = x      ; tptr->aty = y+(v/2); tptr->w = w  ; tptr->h=h-v; ps_fill(wptr,tptr);
		tptr->atx = x      ; tptr->aty = y      ; tptr->w = v  ; tptr->h=v  ; tptr->align =  8; ps_circle(wptr,tptr);
		tptr->atx = x+(w-v); tptr->aty = y      ; tptr->w = v  ; tptr->h=v  ; tptr->align =  9; ps_circle(wptr,tptr);
		tptr->atx = x      ; tptr->aty = y+(h-v); tptr->w = v  ; tptr->h=v  ; tptr->align = 10; ps_circle(wptr,tptr);
		tptr->atx = x+(w-v); tptr->aty = y+(h-v); tptr->w = v  ; tptr->h=v  ; tptr->align = 11; ps_circle(wptr,tptr);
		}
}

private	void	ps_hq_roundfill(char * wptr, struct text_item * tptr )
{
	tptr->atx = tptr->atx * Density / 75;
	tptr->aty = tptr->aty * Density / 75;
	tptr->w   = tptr->w   * Density / 75;
	tptr->h   = tptr->h   * Density / 75;
	ps_roundfill(wptr,tptr);
}

private	void	ps_roundframe(char * wptr, struct text_item * tptr )
{
	int	x = tptr->atx;
	int	y = tptr->aty;
	int	w = tptr->w;
	int	h = tptr->h;
	int	cpt = 1;
	int	v;
	v = ( w > h ? h : w );
	v /= 8;
	if (!( v )) {
		ps_fill(wptr,tptr); 
		}
	else	{
		tptr->atx = x+(v/2); tptr->aty = y      ; tptr->w = (w-v)+1; tptr->h=cpt    ; ps_fill(wptr,tptr);
		tptr->atx = x      ; tptr->aty = y+(v/2); tptr->w = cpt    ; tptr->h=(h-v)+1; ps_fill(wptr,tptr);
		tptr->atx = x+w-cpt; tptr->aty = y+(v/2); tptr->w = cpt    ; tptr->h=(h-v)+1; ps_fill(wptr,tptr);
		tptr->atx = x+(v/2); tptr->aty = y+h-cpt; tptr->w = (w-v)+1; tptr->h=cpt    ; ps_fill(wptr,tptr);
		tptr->atx = x      ; tptr->aty = y      ; tptr->w = v      ; tptr->h=v      ; tptr->align = 4; ps_circle(wptr,tptr);
		tptr->atx = x+(w-v); tptr->aty = y      ; tptr->w = v      ; tptr->h=v      ; tptr->align = 5; ps_circle(wptr,tptr);
		tptr->atx = x      ; tptr->aty = y+(h-v); tptr->w = v      ; tptr->h=v      ; tptr->align = 6; ps_circle(wptr,tptr);
		tptr->atx = x+(w-v); tptr->aty = y+(h-v); tptr->w = v      ; tptr->h=v      ; tptr->align = 7; ps_circle(wptr,tptr);
		}
}

private	void	ps_hq_roundframe(char * wptr, struct text_item * tptr )
{
	int	x = tptr->atx * Density / 75;
	int	y = tptr->aty * Density / 75;
	int	w = tptr->w   * Density / 75;
	int	h = tptr->h   * Density / 75;
	int	cpt = get_xgr_scale() ? get_xgr_scale() : 1;

	do {
		tptr->atx = x;
		tptr->aty = y;
		tptr->w   = w;
		tptr->h   = h;
		ps_roundframe(wptr,tptr);
		x++;
		y++;
		w-=2;
		h-=2;
		cpt--;
		}
	while(cpt);
}
/*FCH24022006 end */

private	void	ps_xfill(char * wptr, struct text_item * tptr )
{
	sprintf(wptr,"%u %u %u %u xfill \n",
		(LeftBorder+LeftMargin+((tptr->atx*Density)/75)),
		(LeftBorder+LeftMargin+(((tptr->atx+tptr->w)*Density)/75)),
		(TopBorder+BottomMargin+(RowCount-(((tptr->aty+tptr->h)*Density)/75))),
		(TopBorder+BottomMargin+(RowCount-((tptr->aty*Density)/75)))
		);
	flush_storage(wptr);
	return;
}

private	int	ps_bestfit( int iw, int ih, int * zw, int * zh)
{
	int	bw=*zw;
	int	bh=*zh;
	if ( iw < ih ) {
		if ( bw < bh )
			bw = ((bh * iw) / ih);
		else	bh = ((ih * bw) / iw);
		}
	else if ( bw < bh )
		bh = ((ih*bw)/iw);
	else	bw = ((iw*bh)/ih);		
	*zw = bw;
	*zh = bh;
	return;
}

private	void	ps_hq_image(char * wptr, struct text_item * tptr )
{
	int	xx=0;
	int	yy=0;
	int	zc=0;
	int	zr=0;
	int	nbc;
	int	nbr;
	char *	xptr;
	struct	standard_image * iptr;
	char *	bptr;
	int	r;
	int	g;
	int	b;
	int	bytes=3;
	int	c;
	int	n;
	char *	shadow=(char *) 0;
	if (!( tptr ))
		return;
	if (!( iptr = tptr->image ))
		return;

	if ( tptr->align & 1024 ) {
		if (!( shadow = allocate(((((iptr->columns*Density)/75)*Density)/75)*4) ))
			return;
		}

	nbc = tptr->w;
	nbr = tptr->h;

	switch ( tptr->align  & 7 ) {
		case	0 :
		case	2 : /* left */

			if ( iptr->columns < nbc )
				nbc = iptr->columns;

			if ( iptr->rows < nbr )
				nbr = iptr->rows;

			zc = ((nbc*Density)/75); zr = ((nbr*Density)/75);
			break;

		case	1 : /* right */
			if ( iptr->columns < nbc ) {
				xx  = (nbc-iptr->columns);
				nbc = iptr->columns;
				}
			if ( iptr->rows < nbr ) {
				yy  = (nbr-iptr->rows);
				nbr = iptr->rows;
				}
			zc = ((nbc*Density)/75); zr = ((nbr*Density)/75);
			break;

		case	3 : /* center */

			if ( iptr->columns < nbc ) {
				xx  = ((nbc-iptr->columns)/2);
				nbc = iptr->columns;
				}
			if ( iptr->rows < nbr ) {
				yy  = ((nbr-iptr->rows)/2);
				nbr = iptr->rows;
				}
			zc = ((nbc*Density)/75); zr = ((nbr*Density)/75);
			break;

		case	6 : /* bestfit */
			zc = nbc; zr = nbr;
			ps_bestfit(iptr->columns,iptr->rows,&zc,&zr);
			xx  = ((nbc - zc)/2);
			yy  = ((nbr - zr)/2);
			nbr = iptr->rows;
			nbc = iptr->columns;
			zc = ((zc*Density)/75); zr = ((zr*Density)/75);
			if ( tptr->align & 1024 )
				tptr->align = 4096;
			break;

		case	5 : /* makefit */
			if ( tptr->align & 1024 )
				tptr->align = 4096;
		case	4 : /* tiling */
			zc = ((nbc*Density)/75); zr = ((nbr*Density)/75);
			nbr = iptr->rows;
			nbc = iptr->columns;
			break;
		}

	sprintf(wptr,"/rowdata %u string def\n",nbc*bytes);
	flush_storage(wptr);

	sprintf(wptr,"gsave\n%u %u translate %u %u scale\n",
		(LeftBorder+LeftMargin+(((tptr->atx+xx)*Density)/75)),
		(TopBorder+BottomMargin+(RowCount-(((tptr->aty+yy)*Density)/75))),
		zc, zr
		);
	flush_storage(wptr);

	sprintf(wptr,"%u %u 8 [%u 0 0 -%u 0 0] { currentfile rowdata readhexstring pop } false 3 colorimage\n",
		nbc,nbr,nbc,nbr );
	flush_storage(wptr);

	for (n=0; n < nbr; n++ ) {
		if (!( bptr = connect_pixel_row( iptr->storage, n ) ))
			break;
		xptr = wptr;
		if ( tptr->align & 4096 ) {
			for (c=0; c < nbc; c++) {
				bptr += get_logical_pixel( bptr, &r,&g,&b);
				if ((!(r)) && (!(g)) && (!(b))) {
					r = g = b = 0x00FF;
					}
				sprintf(xptr,"%02.2X%02.2X%02.2X",r,g,b);
				xptr += 6;
				}
			}
		else if ( tptr->align & 1024 ) {
			getzone(((tptr->atx*Density)/75),(((tptr->aty+n)*Density)/75),iptr->columns,1,shadow);
			for (c=0; c < nbc; c++) {
				bptr += get_logical_pixel( bptr, &r,&g,&b);
				if ((!(r)) && (!(g)) && (!(b))) {
					get_logical_pixel((shadow + ((c*Density)/75)), &r,&g,&b);
					}
				sprintf(xptr,"%02.2X%02.2X%02.2X",r,g,b);
				xptr += 6;
				}
			}
		else	{
			for (c=0; c < nbc; c++) {
				bptr += get_logical_pixel( bptr, &r,&g,&b);
				sprintf(xptr,"%02.2X%02.2X%02.2X",r,g,b);
				xptr += 6;
				}
			}
		sprintf(xptr,"\n");
		flush_storage(wptr);
		}

	sprintf(wptr,"grestore\n");
	flush_storage(wptr);
	sprintf(wptr,"/rowdata where { /rowdata undef } if\n");
	flush_storage(wptr);
	if ( shadow  ) { liberate( shadow ); }
	return;
}

private	void	ps_image(char * wptr, struct text_item * tptr )
{
	int	zc=0;
	int	zr=0;
	int	xx=0;
	int	yy=0;
	int	nbc;
	int	nbr;
	char *	xptr;
	struct	standard_image * iptr;
	char *	bptr;
	int	r;
	int	g;
	int	b;
	int	bytes=3;
	int	c;
	int	n;
	char *	shadow=(char *) 0;
	if (!( tptr ))
		return;
	if (!( iptr = tptr->image ))
		return;
	if ( tptr->align & 1024 ) {
		if (!( shadow = allocate(((((iptr->columns*Density)/75)*Density)/75)*2) ))
			return;
		}
	nbc = tptr->w;
	nbr = tptr->h;

	switch ( tptr->align  & 7 ) {
		case	0 :
		case	2 : /* left */
			if ( iptr->columns < nbc )
				nbc = iptr->columns;

			if ( iptr->rows < nbr )
				nbr = iptr->rows;
			zc = nbc; zr = nbr;
			break;

		case	1 : /* right */
			if ( iptr->columns < nbc ) {
				xx  = (nbc-iptr->columns);
				nbc = iptr->columns;
				}
			if ( iptr->rows < nbr ) {
				yy  = (nbr-iptr->rows);
				nbr = iptr->rows;
				}
			zc = nbc; zr = nbr;
			break;
		case	3 : /* center */

			if ( iptr->columns < nbc ) {
				xx  = ((nbc-iptr->columns)/2);
				nbc = iptr->columns;
				}
			if ( iptr->rows < nbr ) {
				yy  = ((nbr-iptr->rows)/2);
				nbr = iptr->rows;
				}
			zc = nbc; zr = nbr;
			break;

		case	6 : /* bestfit */
			zc = nbc; zr = nbr;
			ps_bestfit(iptr->columns,iptr->rows,&zc,&zr);
			xx  = ((nbc - zc)/2);
			yy  = ((nbr - zr)/2);
			nbr = iptr->rows;
			nbc = iptr->columns;
			if ( tptr->align & 1024 )
				tptr->align = 4096;
			break;
		case	5 : /* makefit */
			if ( tptr->align & 1024 )
				tptr->align = 4096;
		case	4 : /* tiling */
			zc = nbc; zr = nbr;
			nbr = iptr->rows;
			nbc = iptr->columns;
			break;
		}

	sprintf(wptr,"/rowdata %u string def\n",nbc*bytes);
	flush_storage(wptr);
	/* printf("%s",wptr); */

	sprintf(wptr,"gsave\n%u %u translate %u %u scale\n",
		(LeftBorder+LeftMargin+tptr->atx+xx),
		(TopBorder+BottomMargin+(RowCount-(tptr->aty+yy))),
		zc,zr
		);
	flush_storage(wptr);

	sprintf(wptr,"%u %u 8 [%u 0 0 -%u 0 0] { currentfile rowdata readhexstring pop } false 3 colorimage\n",
		nbc,nbr,nbc,nbr);
	flush_storage(wptr);

	for (n=0; n < nbr; n++ ) {
		if (!( bptr = connect_pixel_row( iptr->storage, n ) ))
			break;
		xptr = wptr;
		if ( tptr->align & 4096 ) {
			for (c=0; c < nbc; c++) {
				bptr += get_logical_pixel( bptr, &r,&g,&b);
				if ((!(r)) && (!(g)) && (!(b))) {
					r = g = b = 0x00FF;
					}
				sprintf(xptr,"%02.2X%02.2X%02.2X",r,g,b);
				xptr += 6;
				}
			}
		else if ( tptr->align & 1024 ) {
			getzone(tptr->atx,tptr->aty+n,iptr->columns,1,shadow);
			for (c=0; c < nbc; c++) {
				bptr += get_logical_pixel( bptr, &r,&g,&b);
				if ((!(r)) && (!(g)) && (!(b))) {
					get_logical_pixel((shadow + ((c*Density)/75)), &r,&g,&b);
					}
				sprintf(xptr,"%02.2X%02.2X%02.2X",r,g,b);
				xptr += 6;
				}
			}
		else	{
			for (c=0; c < nbc; c++) {
				bptr += get_logical_pixel( bptr, &r,&g,&b);
				sprintf(xptr,"%02.2X%02.2X%02.2X",r,g,b);
				xptr += 6;
				}
			}
		sprintf(xptr,"\n");
		flush_storage(wptr);
		}

	sprintf(wptr,"grestore\n");
	flush_storage(wptr);

	sprintf(wptr,"/rowdata where { /rowdata undef } if\n");
	flush_storage(wptr);
	if ( shadow  ) { liberate( shadow ); }
	return;
}

private	void	ps_tile(char * wptr, struct text_item * tptr )
{
	int	xh;
	int	xw;
	char *	xptr;
	struct	standard_image * iptr;
	char *	bptr;
	int	r;
	int	g;
	int	b;
	int	bytes=3;
	int	c;
	int	n;
	int	w;
	int	h;

	if (!( tptr ))
		return;
	if (!( iptr = tptr->image ))
		return;

	/* ----------------------------------------------------------------- */
	/* Define Image Array and Load Hex Data from stream to Array Strings */
	/* ----------------------------------------------------------------- */
	sprintf(wptr,"/tiledata %u array  def\n",iptr->rows);
	flush_storage(wptr);

	sprintf(wptr,"0 1 %u { tiledata exch currentfile %u string readhexstring pop put } for\n",
		iptr->rows-1,
		iptr->columns*bytes);

	flush_storage(wptr);


	for (n=0; n < iptr->rows; n++ ) {
		if (!( bptr = connect_pixel_row( iptr->storage, n ) ))
			break;
		xptr = wptr;
		for (c=0; c < iptr->columns; c++) {
			bptr += get_logical_pixel( bptr, &r,&g,&b);
			sprintf(xptr,"%02.2X%02.2X%02.2X",r,g,b);
			xptr += 6;
			}
		sprintf(xptr,"\n");
		flush_storage(wptr);
		}

	/* -------------------------------- */
	/* Define the Tile Display Function */
	/* -------------------------------- */
	sprintf(wptr,"/showtile { gsave /tileitem 0 def translate %u %u scale %u %u 8 [ %u 0 0 -%u 0 0 ] {",
		(iptr->columns*Density)/75,(iptr->rows*Density)/75,
		iptr->columns,iptr->rows,
		iptr->columns,iptr->rows);
	flush_storage(wptr);

	sprintf(wptr,"tiledata tileitem dup 1 add /tileitem exch def get } false 3 colorimage grestore } def\n");
	flush_storage(wptr);

	/* -------------------------------------------- */
	/* Display the tiles to cover the required area */
	/* -------------------------------------------- */
	sprintf(wptr,"gsave newpath %u %u m %u %u lineto %u %u lineto %u %u lineto %u %u lineto closepath clip newpath\n",
		(LeftBorder+LeftMargin+((tptr->atx*Density)/75)),
		(TopBorder+BottomMargin+(RowCount-((tptr->aty*Density)/75))),
		(LeftBorder+LeftMargin+(((tptr->atx+tptr->w)*Density)/75)),
		(TopBorder+BottomMargin+(RowCount-((tptr->aty*Density)/75))),
		(LeftBorder+LeftMargin+(((tptr->atx+tptr->w)*Density)/75)),
		(TopBorder+BottomMargin+(RowCount-(((tptr->aty+tptr->h)*Density)/75))),
		(LeftBorder+LeftMargin+((tptr->atx*Density)/75)),
		(TopBorder+BottomMargin+(RowCount-(((tptr->aty+tptr->h)*Density)/75))),
		(LeftBorder+LeftMargin+((tptr->atx*Density)/75)),
		(TopBorder+BottomMargin+(RowCount-((tptr->aty*Density)/75)))
		);						
	flush_storage(wptr);
	n = 0;
	while (1) {
		if ( n >= tptr->h )
			break;
		else	c = 0;
		while (1) {
			if ( c >= tptr->w )
				break;
			else	{
				sprintf(wptr,"%u %u showtile\n",
					(LeftBorder+LeftMargin+(((tptr->atx+c)*Density)/75)),
					(TopBorder+BottomMargin+(RowCount-(((tptr->aty+n)*Density)/75))));
				flush_storage(wptr);
				c += iptr->columns;
				}
			}
		n += iptr->rows;
		}

	/* ------------------------------------------ */
	/* Undefine the define items ( they are big ) */
	/* ------------------------------------------ */
	sprintf(wptr,"%s","grestore initclip\n");
	flush_storage(wptr);
	sprintf(wptr,"/tileitem where { /tileitem undef } if\n");
	flush_storage(wptr);
	sprintf(wptr,"/tiledata where { /tiledata undef } if\n");
	flush_storage(wptr);

	return;
}

private	int	count_space(char * tptr)
{
	int	c;
	int	result=0;
	while ((c = *(tptr++)) != 0)
		if ( c == ' ' )
			result++;
	return(result);
}

private	void	ps_text(char * wptr, struct text_item * tptr )
{
	int	spacecount=0;
	ShowFontSize = (PsFont[tptr->font].size/4);
	switch ( tptr->align ) {
		case	 0	:
		case	-1	: /* no alignment */
			sprintf(wptr,"%u %u (%s) nm\n",
				(LeftBorder+LeftMargin+tptr->atx),
				(TopBorder+BottomMargin+(RowCount-tptr->aty)-(ShowFontSize*3)),
				tptr->message);
			break;
		case	1	: /* right aligned */
			sprintf(wptr,"%u %u %u %u %u (%s) amr\n",
				PsFont[tptr->font].size,
				(LeftBorder+LeftMargin+tptr->atx),
				(TopBorder+BottomMargin+(RowCount-tptr->aty)-ShowFontSize)/*+4*/,
				tptr->w, tptr->h,
				tptr->message);
			break;
		case	4	: /* justified */
			if ((spacecount = count_space(tptr->message)) != 0) {
				sprintf(wptr,"%u %u %u %u %u (%s) amj\n",
					PsFont[tptr->font].size,
					(LeftBorder+LeftMargin+tptr->atx),
					(TopBorder+BottomMargin+(RowCount-tptr->aty)-ShowFontSize)/*+4*/,
					tptr->w, tptr->h,
					tptr->message);
				break;
				}
		case	2	: /* left aligned */
			sprintf(wptr,"%u %u %u %u %u (%s) aml\n",
				PsFont[tptr->font].size,
				(LeftBorder+LeftMargin+tptr->atx),
				(TopBorder+BottomMargin+(RowCount-tptr->aty)-ShowFontSize)/*+4*/,
				tptr->w, tptr->h,
				tptr->message);
			break;
		case	3	: /* centered */
			sprintf(wptr,"%u %u %u %u %u (%s) amc\n",
				PsFont[tptr->font].size,
				(LeftBorder+LeftMargin+tptr->atx),
				(TopBorder+BottomMargin+(RowCount-tptr->aty)-ShowFontSize)/*+4*/,
				tptr->w, tptr->h,
				tptr->message);
			break;

		default		:
			*wptr = 0;
		}
	flush_storage(wptr);
	return;
}

private	void	ps_hq_text(char * wptr, struct text_item * tptr )
{
	int	spacecount=0;
	ShowFontSize = (((PsFont[tptr->font].size*Density)/75)/4);
	switch ( tptr->align ) {
		case	 0	:
		case	-1	:
			sprintf(wptr,"%u %u (%s) nm\n",
				(LeftBorder+LeftMargin+((tptr->atx*Density)/75)),
				(TopBorder+BottomMargin+(RowCount-((tptr->aty*Density)/75))-(ShowFontSize*3)),
				tptr->message);
			break;
		case	1	: /* right */
			sprintf(wptr,"%u %u %u %u %u (%s) amr\n",
				((PsFont[tptr->font].size*Density)/75),
				(LeftBorder+LeftMargin+((tptr->atx*Density)/75)),
				(TopBorder+BottomMargin+(RowCount-((tptr->aty*Density)/75))-ShowFontSize)/*+4*/,
				((tptr->w*Density)/75), 
				((tptr->h*Density)/75), 
				tptr->message);
			break;
		case	4	: /* justified */
			if ((spacecount = count_space(tptr->message)) != 0) {
				sprintf(wptr,"%u %u %u %u %u (%s) amj\n",
					((PsFont[tptr->font].size*Density)/75),
					(LeftBorder+LeftMargin+((tptr->atx*Density)/75)),
					(TopBorder+BottomMargin+(RowCount-((tptr->aty*Density)/75))-ShowFontSize)/*+4*/,
					((tptr->w*Density)/75), 
					((tptr->h*Density)/75), 
					tptr->message);
				break;
				}				
		case	2	: /* left*/
			sprintf(wptr,"%u %u %u %u %u (%s) aml\n",
				((PsFont[tptr->font].size*Density)/75),
				(LeftBorder+LeftMargin+((tptr->atx*Density)/75)),
				(TopBorder+BottomMargin+(RowCount-((tptr->aty*Density)/75))-ShowFontSize)/*+4*/,
				((tptr->w*Density)/75), 
				((tptr->h*Density)/75), 
				tptr->message);
			break;
		case	3	: /* center */
			sprintf(wptr,"%u %u %u %u %u (%s) amc\n",
				((PsFont[tptr->font].size*Density)/75),
				(LeftBorder+LeftMargin+((tptr->atx*Density)/75)),
				(TopBorder+BottomMargin+(RowCount-((tptr->aty*Density)/75))-ShowFontSize)/*+4*/,
				((tptr->w*Density)/75), 
				((tptr->h*Density)/75), 
				tptr->message);
			break;

		default		:
			*wptr = 0;
		}				
	flush_storage(wptr);
	return;
}


private	void	ps_hq_font(char * wptr, struct text_item * tptr )
{
	switch ( tptr->atribut & 0x000E ) {
		case	0x0000	:
			sprintf(wptr,"%u %s ",((PsFont[tptr->font].size*Density)/75),PsFont[tptr->font].name);
			break;
		case	0x0002	:
			sprintf(wptr,"%u %s ",((PsFont[tptr->font].size*Density)/75),PsFont[tptr->font].bold);
			break;
		case	0x000C	:
		case	0x0008	:
		case	0x0004	:
			sprintf(wptr,"%u %s ",((PsFont[tptr->font].size*Density)/75),PsFont[tptr->font].italic);
			break;	
		case	0x000E	:
		case	0x000A	:
		case	0x0006	:
			sprintf(wptr,"%u %s ",((PsFont[tptr->font].size*Density)/75),PsFont[tptr->font].both);
			break;
		default		:
			*wptr = 0;
		}
	flush_storage(wptr);
	return;
}

private	void	ps_font(char * wptr, struct text_item * tptr )
{
	switch ( tptr->atribut & 0x000E ) {
		case	0x0000	:
			sprintf(wptr,"%u %s ",PsFont[tptr->font].size,PsFont[tptr->font].name);
			break;
		case	0x0002	:
			sprintf(wptr,"%u %s ",PsFont[tptr->font].size,PsFont[tptr->font].bold);
			break;
		case	0x000C	:
		case	0x0008	:
		case	0x0004	:
			sprintf(wptr,"%u %s ",PsFont[tptr->font].size,PsFont[tptr->font].italic);
			break;
		case	0x000E	:
		case	0x000A	:
		case	0x0006	:
			sprintf(wptr,"%u %s ",PsFont[tptr->font].size,PsFont[tptr->font].both);
			break;
		default		:
			*wptr = 0;
		}
	flush_storage(wptr);
	return;
}

static	void	ps_colour(char * wptr, struct prn_colour * cptr )
{
	int	a=0;
	int	r=0;
	int	g=0;
	int	b=0;
	if ( PageOptions & _FORCE_GRAYSCALE ) {
		a = colour_map_luminence(( cptr->value & 0x00FF));
		a *=100;
		a /= 256;
		sprintf(wptr,"0.%02.2u setgray ",a);
		flush_storage((wptr=RasterWork));
		}
	else	{
		r = ((cptr->red * 100)/255);	
		g = ((cptr->green * 100)/255);	
		b = ((cptr->blue * 100)/255);
		wptr = decimal(wptr,r);
		wptr = decimal(wptr,g);
		wptr = decimal(wptr,b);
		sprintf(wptr,"setrgbcolor ");
		flush_storage((wptr=RasterWork));
		}
	return;
}

/*	-----------------------------		*/
/*	PostScript Palette Definition		*/
/*	-----------------------------		*/
static	char *	setrgbcolors( char * rptr )
{
	int	i;
	int	r;
	int	g;
	int	b;
	char *	pptr;

	if ( colourmapping ) {

		pptr = PaletteBuffer;

		for ( i=0; i < 256; i++ ) {
			sprintf(rptr,"/y%x {",(i & 0x00FF));
			rptr += strlen( rptr );	
			r = (*pptr & 0x00FF);
			r = ((r*1000)/256);
			rptr = zazzzx(rptr,r);
			g = (*(pptr+1) & 0x00FF);
			g = ((g*1000)/256);
			rptr = zazzzx(rptr,g);
			b = (*(pptr+2) & 0x00FF);
			b = ((b*1000)/256);
			rptr = zazzzx(rptr,b);
			sprintf(rptr," srgb } bind def\n");
			rptr += strlen( rptr );	
			pptr += 4;
			}
		}

	return( rptr );
}

/*	-----------------------------------	*/
/*	Encapsulation of PostScript in EscT	*/
/*	-----------------------------------	*/
static	int	encapsulate( char * rptr, char * sptr )
{
	int	l=strlen( sptr );

	if (!( l ))
		return( l );
	
	*(rptr++) = 27;
	*(rptr++) = 'T';
	*(rptr++) = (l & 0x00FF);
	*(rptr++) = ((l >> 8) & 0x00FF);
	strcpy( rptr, sptr);
	return( l+4 );
}

#define	_calculate_driver_margins
int	calculate_driver_margins()
{
	if ( CalculateMargins ) {
		LeftMargin = calculate_paper_left_margin(Density);
		if ( (LeftMargin+ColCount) < PaperWidth)
			RightMargin = (PaperWidth - (LeftMargin+ColCount));
		TopMargin = calculate_paper_top_margin(Density);
		if ( (TopMargin+RowCount) < PaperHeight )
			BottomMargin = (PaperHeight - (TopMargin+RowCount));
		}
	return(0);
}

/*	---------------------------------------------------------------------------	*/
/*	D r i v e r I n i t i a l i s e ( palette, dpi, grnbcol, grnbrow, options )	*/
/*	---------------------------------------------------------------------------	*/
int	DriverInitialise(char * palette, int dpi, int grnbcol, int grnbrow, int options )
{
	int	fwh;
	int	t;
	int	i;
	char *	eptr;

	reset_global_context();

	if (!( StoragePath )) {
		if (!( eptr = Portable_getenv("PSPATHTEMP"))) {
#ifdef	WIN32
			eptr = ".\\";
#else
			eptr = "/tmp/";
#endif
			}
		if ((StoragePath = allocate(strlen(eptr)+1)) != (char *) 0)
			strcpy(StoragePath,eptr);
		}
	if ( options & _PAGE_QUALITY   )
		HighQuality=1;
	else	HighQuality=0;
	if ( options & _PAGE_LANDSCAPE ) {
		t = grnbcol;
		grnbcol = grnbrow;
		grnbrow = t;
		Landscaping = 1; 
		}
	else	{
		Landscaping = 0; 
		}

	set_iso_latin((IsoLatin=1));

	/* ----------------------------- */
	/* initialise font table entries */
	/* ----------------------------- */
	for (i=10; i < 256; i++ ) {
		PsFont[i].name	=
		PsFont[i].bold	=
		PsFont[i].italic= 
		PsFont[i].both 	= (char *) 0;
		fwh = guifontsize(i);
		PsFont[i].size	= (((fwh >> 8) & 0x00FF)-2);
		PsFont[i].width = (fwh & 0x00FF);
		PsFont[i].info  = guifontinfo(i);
#ifdef	PSIIIT_TRACE
		if ( PsFont[i].info) {
			printf("guifontinfo(%u) = %s : %s \r\n",i,PsFont[i].info,guifontname(i));
			}
#endif
		}

/*	printf("psiiit::initialise(nbcol=%u,nbrow=%u,mode=%u)\n",grnbcol,grnbrow,Landscaping);	*/

	set_colour_options( options );

	if (!( colourmapping )) { set_white_limit( pixelsize ); }

	Density = dpi;	PageCount=0;
	RasterReady   = PrinterReady = 0;
	PaletteBuffer = palette;
	PageOptions   = options;

	set_paper_dimensions( dpi, ((PageOptions & _PAPER_TYPE) >> 8));

	RowCount 	= grnbrow;	ColCount 	= grnbcol;
	BottomMargin  	= 0;		TopMargin     	= 0;
	LeftMargin    	= 0;		RightMargin   	= 0;
	LeftBorder    	= 0;		TopBorder     	= 0;
	CalculateMargins= 0;

	if (!( Landscaping )) {
		/* --------------------------------------- */
		/* Portrait alignment can be performed now */
		/* --------------------------------------- */
		LeftBorder = 14;
		TopBorder = 13;
		PaperWidth -= (2*LeftBorder);
		PaperHeight-= (2*TopBorder);
		switch ( PageOptions & _PAGE_ALIGNMENT ) {
			case	_ALIGN_RIGHT : /* Bottom Right Align */
				if ( ColCount < PaperWidth )
					LeftMargin = (PaperWidth - ColCount);
				if ( RowCount < PaperHeight )
					TopMargin = (PaperHeight - RowCount);
				break;

			case	_ALIGN_LEFT : /* Top Left Align */
				if ( ColCount < PaperWidth )
					RightMargin = (PaperWidth - ColCount);
				if ( RowCount < PaperHeight )
					BottomMargin = (PaperHeight - RowCount);
				break;

			case	_ALIGN_NONE    :
			case	_ALIGN_CENTER  : /* Center */
				if ( ColCount < PaperWidth ) {
					RightMargin = LeftMargin = ((PaperWidth - ColCount)/2);
					}
				if ( RowCount < PaperHeight ) {
					BottomMargin = TopMargin = ((PaperHeight - RowCount)/2);
					}
				break;
			case	_ALIGN_MARGIN    :
				CalculateMargins=1;
				calculate_driver_margins();
				break;

			}
		}

	textfiltering=1;
	
	return(_POSTSCRIPT_LINESIZE);
}

/*	---------------------------------------------------------------------------	*/
/*		    D r i v e r C o n n e c t ( bptr, wptr, result )			*/
/*	---------------------------------------------------------------------------	*/
int	DriverConnect( char * bptr, char * wptr, char * result )
{
	int	fid;
	int	i;
	int	c;
	FILE	*	h;
	char	*	nptr;
	char	*	rptr;
	char	*	pcptr=(char *) 0;
	int		pclen=0;
	RasterByte = bptr;
	Storage = (FILE *) 0;

	if (!( RasterWork = wptr )) { 
		return(0);
		}	
	
	rptr = wptr;
	*rptr = 0;

	sprintf(rptr,"%c!PS-Adobe 3.0\n%c%c%s version : %c.%c%c : date %s \n",
			0x0025,
			0x0025,
			0x0025,
			__DRIVER_NAME,
			__DRIVER_MAJOR,__DRIVER_MINOR,__DRIVER_INDEX,
			__DRIVER_DATE );
	rptr += strlen( rptr );

	sprintf(rptr,"%c%cPages: (atend) \n",0x0025,0x0025);
	rptr += strlen( rptr );
	sprintf(rptr,"%c%cBoundingBox: %u %u %u %u \n",0x0025,0x0025,LeftMargin,BottomMargin,LeftMargin+PaperWidth,BottomMargin+PaperHeight);
	rptr += strlen( rptr );
	sprintf(rptr,"%c%cDocumentPaperSizes: %s \n",0x0025,0x0025,get_paper_name());
	rptr += strlen(rptr);

	if ( Landscaping )
		sprintf(rptr,"%c%cOrientation: Landscape \n",0x0025,0x0025);
	else	sprintf(rptr,"%c%cOrientation: Portrait  \n",0x0025,0x0025);
	rptr += strlen(rptr);

	sprintf(rptr,"%c%cEndComments\n",0x0025,0x0025);
	rptr += strlen(rptr);

	/* ----------------------------- */
	/* Collect Imlicite Page Control */
	/* ----------------------------- */
	if  (((EnvPageControl = Portable_getenv("PSPAGECONTROL")) != (char *) 0) 
	&&   ((h = fopen(EnvPageControl,"r")) != (FILE*)0)) {
		while ((c = fgetc(h)) != -1) {
			if (!( c )) 
				break;
			else	*(rptr++) = c;
			}
		*rptr= 0;
		fclose(h);
		}	

	/* ------------------------------ */
	/* Collect Explicite Page Control */
	/* ------------------------------ */
	if ( get_page_control( &pcptr, &pclen ) ) {
		for ( c=0; c < pclen; c++ )
			*(rptr++) = *(pcptr+c);
		*rptr= 0;
		}

/*	------------------------------------------------------ 		*/
/*	Postscript stack and code for right and center aligned		*/
/*	------------------------------------------------------ 		*/
/*
	h w x y s		dup stringwidth
	h w x y s tw th		
*				dup
*	h w x y s tw th th	8 -1 roll
*	w x y s tw th th h	dup
*	w x y s tw th th h h	9 1 roll
*	h w x y s tw th th h 	ge 			? th <= h
*				{ 
				7 -1 roll
*				pop 0
*				} 
*				{
	h w x y s tw th|0	7 -1 roll
	w x y s tw th h		xchg
	w x y s tw h  th	sub
				2 div 
				} ifelse
	w x y s tw ay		xchg
	w x y s ay tw		6 -1 roll
	x y s ay tw w		xchg
	x y s ay w tw		sub
				2 div 		---- not required for right aligned
	x y s ay ax		5 -1 roll
	y s ay ax x		add
	y s ay x		xchg
	y s x ay		4 -1 roll
	s x ay y		xchg				
	s x y ay		sub
	s x y			m
*/

/*	------------------------------------------ 		*/
/*	Postscript stack and code for left aligned		*/
/*	------------------------------------------ 		*/
/*
	h w x y s		dup stringwidth 	
	h w x y s tw th		
*				dup
*	h w x y s tw th th	8 -1 roll
*	w x y s tw th th h	dup
*	w x y s tw th th h h	9 1 roll
*	h w x y s tw th th h 	ge 			? th <= h
*				{ 
				7 -1 roll
*				pop 0
*				} 
*				{
	h w x y s tw th|0	7 -1 roll
	w x y s tw th h		xchg
	w x y s tw h  th	sub
				2 div 
				} ifelse
	w x y s tw ay		xchg
	w x y s ay tw		6 -1 roll
	x y s ay tw w		xchg
	x y s ay w tw		sub
	x y s ay ax		pop
	x y s ay 		0 5 -1 roll
	y s ay ax x		add
	y s ay x		xchg
	y s x ay		4 -1 roll
	s x ay y		xchg				
	s x y ay		sub
	s x y			m
*/
/*	------------------------------------------ 		*/
/*	Postscript stack and code for none aligned		*/
/*	------------------------------------------ 		*/
/*
	x y s			dup stringwidth
	x y s tw th		xchg
	x y s th tw		pop
	x y s th		4 -1 roll
	y s th x 		xchg
	y s x th		4 -1 roll
	s x th y		xchg
	s x y th		add 
	s x y 			m
*/


	sprintf(rptr,"\t/m { newpath moveto } bind def \n");
	rptr += strlen( rptr );

	sprintf(rptr,"\t/l { rlineto } bind def \n");
	rptr += strlen( rptr );

	sprintf(rptr,"\t/msh { m show } bind def \n");
	rptr += strlen( rptr );

	sprintf(rptr,"\t/wsh { widthshow } bind def \n");
	rptr += strlen( rptr );

	sprintf(rptr,"\t/sw { dup stringwidth } bind def \n");
	rptr += strlen( rptr );

	sprintf(rptr,"\t/diff { 1 index 1 index ge { pop pop 0 } { exch sub } ifelse } bind def \n");
	rptr += strlen( rptr );

	sprintf(rptr,"\t/nm { sw exch pop 4 -1 roll exch 4 -1 roll exch add m show } bind def \n");
	rptr += strlen( rptr );

	/* Text joining macro : see join.ps */
	/* -------------------------------- */
	sprintf(rptr,"\t/join { 1 index length dup 2 index length add string dup dup 0 7 -1 roll putinterval 4 1 roll exch 3 -1 roll putinterval } bind def \n");
	rptr += strlen( rptr );

	/* Space count macro : see spaces.ps */
	/* --------------------------------- */
	sprintf(rptr,"\t/spaces	{ 0 0 { 2 index dup length 2 index gt { 1 index	get 32 eq { 2 -1 roll 1 add 2 1 roll } if 1 add } { pop exit } ifelse } loop pop } bind def \n");
	rptr += strlen( rptr );
	
	/* Line cutting macro : see cutline.ps */
	/* ----------------------------------- */
	sprintf(rptr,"\t/cutline { () exch ( ) { search { sw pop 5 -1 roll dup length 0 gt { ( ) join } if sw pop 3 -1 roll add 5 index le { exch join } \n");
	rptr += strlen( rptr );
	sprintf(rptr,"\t{ 4 1 roll exch join exch join 	exch exit } ifelse 3 1 roll } \n");
	rptr += strlen( rptr );
	sprintf(rptr,"\t{ sw pop 3 -1 roll dup length 0 gt { ( ) join } if sw pop 3 -1 roll add 3 index le { exch join () exch } if exit } ifelse } loop } bind def \n");
	rptr += strlen( rptr );

	/* text left  align   macro : see lm.ps */
	/* ------------------------------------ */
	sprintf(rptr,"\t/lm { sw 4 -1 roll diff 2 div 5 -1 roll exch sub exch pop 4 -2 roll pop exch msh } bind def \n");
	rptr += strlen( rptr );

	/* text right align   macro : see rm.ps */
	/* ------------------------------------ */
	sprintf(rptr,"\t/rm { sw 4 -1 roll diff 2 div 5 -1 roll exch sub exch 4 -1 roll diff 4 -1 roll add exch msh } bind def \n");
	rptr += strlen( rptr );

	/* text centering     macro : see cm.ps */
	/* ------------------------------------ */
	sprintf(rptr,"\t/cm { sw 4 -1 roll diff 2 div 5 -1 roll exch sub exch 4 -1 roll diff 2 div 4 -1 roll add exch msh } bind def \n");
	rptr += strlen( rptr );

	/* text justification macro : see jm.ps */
	/* ------------------------------------ */
	sprintf(rptr,"\t/jm { spaces exch sw 5 -1 roll diff 2 div 6 -1 roll exch sub exch 5 -1 roll diff 4 -1 roll div exch 4 -1 roll exch m 0 32 4 -1 roll wsh } bind def \n");
	rptr += strlen( rptr );

	/* Multi line text alignment macros : see multiline.ps */
	/* --------------------------------------------------- */
	sprintf(rptr,"\t/mlc { { dup length 0 gt { cutline 5 index 5 index 4 index 6 index 5 -1 roll cm 2 index 5 -1 roll exch sub 4 1 roll } { pop pop pop pop pop exit } ifelse exit } loop } bind def \n");
	rptr += strlen( rptr );
	sprintf(rptr,"\t/mlr { { dup length 0 gt { cutline 5 index 5 index 4 index 6 index 5 -1 roll rm 2 index 5 -1 roll exch sub 4 1 roll } { pop pop pop pop pop exit } ifelse exit } loop } bind def \n");
	rptr += strlen( rptr );
	sprintf(rptr,"\t/mll { { dup length 0 gt { cutline 5 index 5 index 4 index 6 index 5 -1 roll lm 2 index 5 -1 roll exch sub 4 1 roll } { pop pop pop pop pop exit } ifelse exit } loop } bind def \n");
	rptr += strlen( rptr );
	sprintf(rptr,"\t/mlj { { dup length 0 gt { cutline 5 index 5 index 4 index 6 index 5 -1 roll jm 2 index 5 -1 roll exch sub 4 1 roll } { pop pop pop pop pop exit } ifelse exit } loop } bind def \n");
	rptr += strlen( rptr );

	/* Text Alignment Macros : Multi / Mono Line : see align.ps */
 	/* -------------------------------------------------------- */
	sprintf(rptr,"\t/reorg { exch pop 4 index 3 1 roll } bind def \n");
	rptr += strlen( rptr );
	sprintf(rptr,"\t/aml { sw pop 3 index ge { reorg mll } { lm } ifelse pop } bind def \n");
	rptr += strlen( rptr );
	sprintf(rptr,"\t/amr { sw pop 3 index ge { reorg mlr } { rm } ifelse pop } bind def \n");
	rptr += strlen( rptr );
	sprintf(rptr,"\t/amc { sw pop 3 index ge { reorg mlc } { cm } ifelse pop } bind def \n");
	rptr += strlen( rptr );
	sprintf(rptr,"\t/amj { sw pop 3 index ge { reorg mlj } { jm } ifelse pop } bind def \n");
	rptr += strlen( rptr );

	/* zone fill macro */
	/* --------------- */
	sprintf(rptr,"\t/xfill { 2  exch { 3 1 roll 2 copy 2 exch { ",((Density/75)*2),((Density/75)*2));
	rptr += strlen( rptr );
	sprintf(rptr,"4 -1 roll dup 5 1 roll  m 0 1  l 1  0 l 0 -1  ",(Density/75),(Density/75),(Density/75));
	rptr += strlen( rptr );
	sprintf(rptr,"rlineto closepath fill } for } for } def\n");
	rptr += strlen( rptr );

	if ( PageOptions & _FORCE_GRAYSCALE ) {
		sprintf(rptr,"\t/p { setgray stroke } bind def \n");
		rptr += strlen( rptr );
		}
	else if ( colourmapping ) {
		sprintf(rptr,"\t/p { stroke } bind def \n");
		rptr += strlen( rptr );
		sprintf(rptr,"\t/srgb { setrgbcolor } bind def \n");
		rptr += strlen( rptr );
		rptr = setrgbcolors(rptr);
		}
	else	{
		sprintf(rptr,"\t/p { setrgbcolor stroke } bind def \n");
		rptr += strlen( rptr );
		}

	/* Test for external file description of Fonts and Character Set */
	/* ------------------------------------------------------------- */
	sprintf(rptr,"%c Start of Font Definitions \n",0x0025); rptr+= strlen(rptr);
	if  (((IsoLatinPs = Portable_getenv("PSISOLATIN")) != (char *) 0) 
	&&   ((h = fopen(IsoLatinPs,"r")) != (FILE*)0)) {
		sprintf(rptr,"%c Included File %s \n",0x0025,IsoLatinPs); rptr+= strlen(rptr);
		while ((c = fgetc(h)) != -1) {
			if (!( c )) 
				break;
			else	*(rptr++) = c;
			}
		*rptr= 0;
		fclose(h);
		}	
	else	{
		/* ----------------------------------------------------- */
		/* Standard Mozilla compatible Iso Latin Accent Handling */
		/* ----------------------------------------------------- */
		/* Generate ISO LATIN 1 Character Set			 */
		/* ----------------------------------------------------- */
		sprintf(rptr,"%c Standard \n",0x0025); rptr+= strlen(rptr);
		sprintf(rptr,"[ \n"); rptr+= strlen(rptr);
		for (i=0; i < 256; i++ ) {
			sprintf(rptr,"/%s ",CharacterMnemonic[i]);
			rptr += strlen(rptr);
			if (( i ) && (!(i%16))) {
				sprintf(rptr,"\n");
				rptr+= strlen(rptr);
				}
			}
		sprintf(rptr," ] /Abal3IsoLatin exch def \n"); 
		rptr+= strlen(rptr);

		/* ----------------------------------------------------- */
		/* Font redefinition and selection functions		 */
		/* ----------------------------------------------------- */
		sprintf(rptr,"\t/A3FR { findfont dup length dict \n"); 
		rptr+= strlen(rptr);
		sprintf(rptr,"\t\tbegin {1 index /FID ne {def} {pop pop} ifelse} forall /Encoding Abal3IsoLatin def currentdict  end \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t\tdefinefont pop } bind def \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/A3SF /selectfont where { pop { exch selectfont } } { { findfont exch scalefont setfont } } ifelse bind def \n");
		rptr+= strlen(rptr);
		for ( fid=0; fid < MaxPsFonts; fid++) {
			sprintf(rptr,"\t/F%u /%s A3FR \n",fid,ps_font_name[fid]);
			rptr+= strlen(rptr);
			sprintf(rptr,"\t/f%u { dup /csize exch def /F%u A3SF } bind def \n",fid,fid);
			rptr+= strlen(rptr);
			}
#ifdef	OLD_PS_FONTS
		sprintf(rptr,"\t/F0 /Times-Roman A3FR \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/f0 { dup /csize exch def /F0 A3SF } bind def \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/F1 /Times-Bold A3FR \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/f1 { dup /csize exch def /F1 A3SF } bind def \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/F2 /Times-BoldItalic A3FR \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/f2 { dup /csize exch def /F2 A3SF } bind def \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/F3 /Times-Italic A3FR \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/f3 { dup /csize exch def /F3 A3SF } bind def \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/F4 /Helvetica A3FR \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/f4 { dup /csize exch def /F4 A3SF } bind def \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/F5 /Helvetica-Bold A3FR \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/f5 { dup /csize exch def /F5 A3SF } bind def \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/F6 /Helvetica-BoldOblique A3FR \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/f6 { dup /csize exch def /F6 A3SF } bind def \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/F7 /Helvetica-Oblique A3FR \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/f7 { dup /csize exch def /F7 A3SF } bind def \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/F8 /Courier A3FR \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/f8 { dup /csize exch def /F8 A3SF } bind def \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/F9 /Courier-Bold A3FR \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/f9 { dup /csize exch def /F9 A3SF } bind def \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/F10 /Courier-BoldOblique A3FR \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/f10 { dup /csize exch def /F10 A3SF } bind def \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/F11 /Courier-Oblique A3FR \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/f11 { dup /csize exch def /F11 A3SF } bind def \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/F12 /Symbol A3FR \n");
		rptr+= strlen(rptr);
		sprintf(rptr,"\t/f12 { dup /csize exch def /F12 A3SF } bind def \n");
		rptr+= strlen(rptr);
#endif
		}
	sprintf(rptr,"%c End of Font Definitions \n",0x0025); rptr+= strlen(rptr); 		
	sprintf(rptr,"%c%cEndProlog\n",0x0025,0x0025);
	rptr += strlen( rptr );
	PrinterReady=1;
	return(encapsulate(result,RasterWork));
}

/*	---------------------------------------------------------------------------	*/
/*			D r i v e r S t a r t R a s t e r ( result )			*/
/*	---------------------------------------------------------------------------	*/
int	DriverStartRaster(char * result)
{
	int	xx,yy;
	char *	wptr;
	if (!( PrinterReady ))
		return(0);
	else if (!( RasterReady )) {
		RasterReady=1;
		RowNumber = 0;
		PageCount++;		
		if (!(wptr=RasterWork)) {
/* 			printf("psiiit: RasterWorkNull in DriverStartRaster \n"); */
			return(0);
			}
		else	{
			sprintf(wptr,"%c%cPage: %u %u\ngsave\n",0x0025,0x0025,PageCount,PageCount);
			switch ( Density ) {
				case	75	:
					sprintf(wptr,"1 1 scale\n");
					wptr += strlen( wptr );
					break;
				case	100	:
					sprintf(wptr,"0.75 0.75 scale\n");
					wptr += strlen( wptr );
					break;
				case	150	:
					sprintf(wptr,"0.5 0.5 scale\n");
					wptr += strlen( wptr );
					break;
				case	300	:
					sprintf(wptr,"0.25 0.25 scale\n");
					wptr += strlen( wptr );
					break;
				case	600 	:
					sprintf(wptr,"0.125 0.125 scale\n");
					wptr += strlen( wptr );
					break;
				case	1200 	:
					sprintf(wptr,"0.0625 0.0625 scale\n");
					wptr += strlen( wptr );
					break;
				}
			wptr += strlen(wptr);
			if ( Landscaping ) {
				sprintf(wptr,"%c pw=%u cc=%u ph=%u rc=%u \n",0x0025,PaperWidth,ColCount,PaperHeight,RowCount);
				wptr += strlen( wptr );
				yy = -(PaperHeight/2); xx = -(PaperWidth/2);
				switch ( PageOptions & _PAGE_ALIGNMENT ) {
					case	_ALIGN_RIGHT : /* Bottom Right Align */
						if ( (PaperHeight-10) > ColCount )
							yy += ((PaperHeight-10)-ColCount);
						break;

					case	_ALIGN_LEFT : /* Top Left Align */
						if ( PaperWidth > RowCount )
							xx += (PaperWidth-RowCount);

						yy += 10; 
						xx -= 10;
						break;

					case	_ALIGN_NONE    :
					case	_ALIGN_CENTER  : /* Center */
						if ( PaperWidth > RowCount )
							xx += ((PaperWidth-RowCount)/2);
						if ( (PaperHeight-10) > ColCount )
							yy += (((PaperHeight-10)-ColCount)/2);
						xx -= 10;
						break;
					}
				sprintf(wptr,"%u %u translate 90 rotate %d %d translate \n",
					(PaperWidth/2),(PaperHeight/2),yy,xx);
				wptr += strlen( wptr );
				}
			return(encapsulate(result,RasterWork));
			}
		}
	return(0);
}

static	char *	decimal(char * wptr, int v )
{
	if ( v == 100 )
		sprintf(wptr,"1.00 ");
	else	sprintf(wptr,"0.%02.2u ",v);
	wptr += strlen( wptr );
	return(wptr);
}

/*	---------------------------------------------------------------------------	*/
/*		 	D r i v e r E n d R a s t e r ( result )			*/
/*	---------------------------------------------------------------------------	*/
int	DriverEndRaster(char * result)
{
	int	textitem=0;
	int	r,g,b;
	int	a;
	int	f;
	int	lastatb=-1;
	int	lastfore=-1;
	int	lastfont=-1;
	struct	text_item * tptr;
	char *	wptr;
	if (!( PrinterReady ))
		return(0);
	else if (!( RasterReady ))
		return(0);
	else	{
		if ( Storage != (FILE *) 0) {
			fclose(Storage);
			Storage = (FILE *) 0;
			}
		unlink(StorageName);
		StorageMode = 0;
		RasterReady=0;
		RowNumber = 0;
		if (!( wptr=RasterWork )) {
			return(0);
			}
		else	{
			sprintf(wptr,"showpage\ngrestore\n");
			return(encapsulate(result,RasterWork));
			}
		}
}

#ifndef	_use_text_item
#define	_use_text_item
int	use_text_item( struct text_item * tptr )
{
	int	fwh;
	int	a;
	int	r;
	int	g;
	int	b;
	char *	wptr;

	if (!( wptr = RasterWork ))
		return(0);

	else if (!( Storage )) {
		sprintf(StorageName,"%sps3t%04.4x.tmp",StoragePath,getpid());
		if (!( Storage = fopen( StorageName,"w") ))
			return(46);
		else	StorageMode = 1;
		}

	if ( tptr->type == _PRINT_TEXT ) {
		if (( tptr->font > 0  )  &&  ( tptr->font < 256 )) {
			if (!( PsFont[tptr->font].name )) {
				PsFont[tptr->font].name   = PsFont[2].name;
				PsFont[tptr->font].bold   = PsFont[2].bold;
				PsFont[tptr->font].italic = PsFont[2].italic;
				PsFont[tptr->font].both	  = PsFont[2].both;
				}
			fwh = guifontsize(tptr->font);
			PsFont[tptr->font].size	= (((fwh >> 8) & 0x00FF)-2);
			PsFont[tptr->font].width = (fwh & 0x00FF);
			if (!( PsFont[tptr->font].info ))
				PsFont[tptr->font].info   = guifontinfo(tptr->font);
#ifdef	PSIIIT_TRACE
			if ( PsFont[tptr->font].info)
				printf("guifontinfo(%u) = %s : %s \r\n",tptr->font,PsFont[tptr->font].info,guifontname(tptr->font));
#endif
			if ( HighQuality )
				ps_hq_font(wptr,tptr);
			else	ps_font(wptr,tptr);
			}
		}

	if ( tptr->type != _PRINT_IMAGE ) {
		ps_colour(wptr,&tptr->foreground );
		}

	switch ( tptr->type ) {
		case	_PRINT_TEXT	:
			if ( HighQuality )
				ps_hq_text(wptr,tptr);
			else	ps_text(wptr,tptr);
			break;

		case	_PRINT_CIRCLE	:
			if ( HighQuality )
				ps_hq_circle(wptr,tptr);
			else	ps_circle(wptr,tptr);
			break;

		case	_PRINT_LINE	:
			if ( HighQuality )
				ps_hq_line(wptr,tptr);
			else	ps_line(wptr,tptr);
			break;

		case	_PRINT_XFILL	:
			if (( tptr->foreground.value & 0x00FF ) != 0 ) {
				if (( tptr->background.value & 0x00FF ) != 0 ) {
					if ( HighQuality )
						ps_hq_fill(wptr,tptr);
					else	ps_fill(wptr,tptr);
					ps_colour(wptr,&tptr->background );
					}
				ps_xfill(wptr,tptr);
				}
			else if (( tptr->background.value & 0x00FF ) != 0 ) {
				ps_colour(wptr,&tptr->background );
				ps_xfill(wptr,tptr);
				}
			break;

		case	_PRINT_FILL	:
			if ( HighQuality )
				ps_hq_fill(wptr,tptr);
			else	ps_fill(wptr,tptr);
			break;

		case	_PRINT_IMAGE	:
			if (( tptr->align  & 7 ) == 4)
				ps_tile( wptr, tptr );
			else if ( HighQuality )
				ps_hq_image(wptr,tptr);
			else	ps_image(wptr,tptr);
			break;

/*FCH24022006 begin */
		case	_PRINT_ROUNDFILL:
			if ( HighQuality )
				ps_hq_roundfill(wptr,tptr);
			else	ps_roundfill(wptr,tptr);
			break;

		case	_PRINT_ROUNDFRAME:
			if ( HighQuality )
				ps_hq_roundframe(wptr,tptr);
			else	ps_roundframe(wptr,tptr);
			break;
/*FCH24022006 end */
		}
	return(1);
}
#endif

#ifdef	PSIII_ULINE
static	void	ps_underline( char * wptr, struct text_item * tptr )
{
	if ( tptr->type == _PRINT_TEXT ) {
		if ( tptr->atribut & _GIGO_UNDERLINE ) {
			sprintf(wptr,"currentpoint ");
			wptr += strlen(wptr);
			wptr = movexyto(wptr,(LeftBorder+LeftMargin+tptr->atx),(TopBorder+BottomMargin+(RowCount-tptr->aty)-ShowFontSize)+2);
			sprintf(wptr,"pop 0 l ");
			wptr += strlen(wptr);
			a = palettepixel(( tptr->foreground.value & 0x00FF));
			if ( colourmapping )
				wptr = stroke(wptr,a);
			else	wptr = paint( wptr,a );
			}
		}
	return;
}
#endif

/*	---------------------------------------------------------------------------	*/
/*			D r i v e r L i b e r a t e ( result )				*/
/*	---------------------------------------------------------------------------	*/
int	DriverLiberate(char * result)
{
	char *	rptr;
	textfiltering=0;
	if (!( rptr=RasterWork )) {
		/* printf("psiiit: RasterWorkNull in DriverLiberate \n"); */
		return(0);
		}
	else	{
		sprintf(rptr,"%c%cTrailer\n",0x0025,0x0025);
		rptr += strlen( rptr );
		sprintf(rptr,"%c%cPages: %u\n",0x0025,0x0025,PageCount);
		rptr += strlen( rptr );
		return(encapsulate(result,RasterWork));
		}
}

/*	---------------------------------------------------------------------------	*/
/*		D r i v e r P r i n t R o w ( result, rowbuffer )			*/
/*	---------------------------------------------------------------------------	*/
int	DriverPrintRow(char * result, char * rowbuffer)
{
	int	rl;
	int	rlen=0;
	int	c;
	int	o;
	int	i;
	int	n;
	int	d;
	int	dd;
	char *	wptr;

	if (!( PrinterReady )) 
		return(0);
	else if (!( RasterByte )) {
/*		printf("psiiit: RasterWorkNull in DriverPrintRow \n");	*/
		return(0);
		}

	if ( StorageMode ) {
		*RasterWork=0;
		if ( Storage != (FILE *) 0) {
			fclose(Storage);
			Storage = (FILE *) 0;
			}
		StorageMode = 0;
		if (!( Storage = fopen( StorageName,"r")))
			return(0);
		}
	*RasterByte = 0;
	while (1) {
		if ((rl = strlen(RasterWork)) > 0) {	
			if (( rlen + rl) < _POSTSCRIPT_LINESIZE ) {
				strcat(RasterByte,RasterWork);
				rlen += rl;
				*RasterWork=0;
				}
			else	break;
			}
		if ( Storage ) {
			i = 0;
			while ( i < _POSTSCRIPT_LINESIZE ) {
				if ((c = fgetc(Storage)) <= 0 )
					break;
				else	{
					*(RasterWork+i) = c;
					i++;
					if ( c == '\n' )
						break;
					}
				}
			*(RasterWork+i) = 0;
			if ( c <= 0 )
				break;
			}
		else	break;
		}		
	if ( RowNumber < RowCount )
		RowNumber++;
	return( encapsulate(result,RasterByte) );
#ifdef	OLD_PS_PRINT_ROW
	*wptr = 0;

/*	printf("DriverRow %u of %u\n",RowNumber,RowCount);		*/
	sprintf(wptr,"%row %u of %u \n",RowNumber,RowCount);
	wptr += strlen(wptr);
	for (	o=0,d=-1,n=0,i=0; i < ColCount; i++ ) {
/*		printf("\tDriverCol %u of %u : 0x0%x \n",i,ColCount,logicalpixel(rowbuffer,i));	*/
		if ( d == -1 ) {
			o = i;
			d = logicalpixel(rowbuffer,i);
			n = 1;
			}
		else if ((dd = logicalpixel(rowbuffer,i)) == d ) {
			n++;
			}
		else	{
/*			printf("m %u l %u s %u\n",o,n,d);		*/
			if ( not_white(d) ) {
				wptr = moveto(wptr,o);
				wptr = lineto(wptr,n);
				if ( colourmapping )
					wptr = stroke(wptr,d);
				else	wptr = paint( wptr,d);
				}
			d = dd;
			o = i;
			n=1;
			}
		}

	if ( n != 0 ) {
/*		printf("m %u l %u s %u\n",o,n,d);		*/
		if ( not_white(d) ) {
			wptr = moveto(wptr,o);
			wptr = lineto(wptr,n);
			if ( colourmapping )
				wptr = stroke(wptr,d);
			else	wptr = paint( wptr,d);
			}
		}
	sprintf(wptr,"\n");
	if ( RowNumber < RowCount )
		RowNumber++;
	return(encapsulate(result,RasterWork));
#endif
}

/*	---------------------------------------------------------------------------	*/
/*				D r i v e r C o l o u r s () 				*/
/*	---------------------------------------------------------------------------	*/
int	DriverColours()	
{	
	if ( Landscaping )
		return(256); 	
	else	return(0);
}

#include "lodriver.c"

	/* ------------- */
#endif	/* _DRIVERABAL_C */
	/* ------------- */




