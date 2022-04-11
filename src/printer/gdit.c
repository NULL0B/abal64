#ifndef	_PSIII_C
#define	_PSIII_C

#include "lodriver.h"
#include "gdit.h"
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

#define	_GDI_LINESIZE	64000
private	char * 	PaletteBuffer=(char *) 0;
private	char * 	RasterByte=(char *) 0;
private	char * 	RasterWork=(char *) 0;
private	int	RasterReady=0;
private	int	PrinterReady=0;
private	int	RowNumber=0;
private	int	RowCount=0;
private	int	TopMargin=0;
private	int	LeftMargin=0;
private	int	BottomMargin=0;
private	int	RightMargin=0;
private	int	TopBorder=13;
private	int	LeftBorder=14;
private	int	ColCount=0;
private	int	PageOptions=0;
private	int	Density=0;
private	int	PageCount=0;
private	int	ShowFontSize=16;
private	int	Landscaping=0;
private	int	HighQuality=0;
private	int	CalculateMargins=0;

char*	get_paper_name();
private	char *	decimal(char * wptr, int v );

int	_fltused=0;
void	_cfltcvt()	{ 	return; 	}
void	_cropzeros()	{ 	return; 	}
long	_aFftol()	{	return(0L);	}

private	int	max_red  =_RED_MASK32;
private	int	max_green=_GREEN_MASK32;
private	int	max_blue =_BLUE_MASK32;
private	int	IsoLatin=0;
private	char *	IsoLatinGdi=(char *) 0;

private	char * 	StoragePath=(char *) 0;
private	FILE *	Storage=(FILE*) 0;
private	char 	StorageName[256];
private	int	StorageMode=0;

private struct	gdiscript_font	{
	char *	name;
	char *	bold;
	char *	italic;
	char * 	both;
	int	size;
	int	width;
	char *	info;
	} GdiFont[256] = {

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

private	char *	gdi_font_name[64] = {
	"Times-Roman",		"Times-Bold",	"Times-BoldItalic",		"Times-Italic",
	"Helvetica",		"Helvetica-Bold","Helvetica-BoldOblique",	"Helvetica-Oblique",
	"Courier",		"Courier-Bold",	"Courier-BoldOblique",		"Courier-Oblique",
	"Symbol",
	(char *) 0
	};

private	int	MaxGdiFonts=_MAX_PS_FONTS;

int	debug_font_number( int f )
{
	printf("font : %u : %s, %s, %s, %s, : %u %u \n",f,
		GdiFont[f].name,
		GdiFont[f].bold,
		GdiFont[f].italic,
		GdiFont[f].both,
		GdiFont[f].size,
		GdiFont[f].width );
	return;
}
 
private	void	reset_global_context()
{
	max_red  =_RED_MASK32;
	max_green=_GREEN_MASK32;
	max_blue =_BLUE_MASK32;
	IsoLatin=0;
	IsoLatinGdi=(char *) 0;
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
private	char *	movexyto(char * bptr, int x,int y)
{
	sprintf(bptr,"%u %u m ",x,y); 
	return( (bptr + strlen(bptr)) );
}
private	char *	moveto(char * bptr, int x)
{
	sprintf(bptr,"%u %u m ",LeftBorder+LeftMargin+x,TopBorder+BottomMargin+(RowCount-RowNumber));
	return( (bptr + strlen(bptr)) );
}

/*	-----------------------------------	*/
/*	PostScript Operator	L I N E T O	*/
/*	-----------------------------------	*/
private	char *	lineto(char * bptr, int x)
{
	sprintf(bptr,"%u %u l ",x,0);
	return( (bptr + strlen(bptr)));
}

/*	-----------------------------------	*/
/*	PostScript Operator	L I N E T O	*/
/*	-----------------------------------	*/
private	char *	linexyto(char * bptr, int x ,int y)
{
	sprintf(bptr,"%u %u l ",x,y);
	return( (bptr + strlen(bptr)));
}

/*	-----------------------------------	*/
/*	PostScript Operator	S T R O K E	*/
/*	-----------------------------------	*/
private	char *	stroke(char * bptr, int x)
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
private	char * zazzzx( char * rptr, int v )
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
private	void	pzazzzx( char * rptr, int v )
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
private	char *	paint(char * bptr, int x)
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

private	void	gdi_hq_circle(char * wptr, struct text_item * tptr )
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

private	void	gdi_circle(char * wptr, struct text_item * tptr )
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

private	void	gdi_hq_line(char * wptr, struct text_item * tptr )
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

private	void	gdi_line(char * wptr, struct text_item * tptr )
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

private	void	gdi_hq_fill(char * wptr, struct text_item * tptr )
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

private	void	gdi_fill(char * wptr, struct text_item * tptr )
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

private	void	gdi_roundfill(char * wptr, struct text_item * tptr )
{
	int	x = tptr->atx;
	int	y = tptr->aty;
	int	w = tptr->w;
	int	h = tptr->h;
	int	v;
	v = ( w > h ? h : w );
	v /= 8;
	if (!( v )) {
		gdi_fill(wptr,tptr); 
		}
	else	{
		tptr->atx = x+(v/2); tptr->aty = y      ; tptr->w = w-v; tptr->h=h  ; gdi_fill(wptr,tptr);
		tptr->atx = x      ; tptr->aty = y+(v/2); tptr->w = w  ; tptr->h=h-v; gdi_fill(wptr,tptr);
		tptr->atx = x      ; tptr->aty = y      ; tptr->w = v  ; tptr->h=v  ; tptr->align =  8; gdi_circle(wptr,tptr);
		tptr->atx = x+(w-v); tptr->aty = y      ; tptr->w = v  ; tptr->h=v  ; tptr->align =  9; gdi_circle(wptr,tptr);
		tptr->atx = x      ; tptr->aty = y+(h-v); tptr->w = v  ; tptr->h=v  ; tptr->align = 10; gdi_circle(wptr,tptr);
		tptr->atx = x+(w-v); tptr->aty = y+(h-v); tptr->w = v  ; tptr->h=v  ; tptr->align = 11; gdi_circle(wptr,tptr);
		}
}

private	void	gdi_hq_roundfill(char * wptr, struct text_item * tptr )
{
	tptr->atx = tptr->atx * Density / 75;
	tptr->aty = tptr->aty * Density / 75;
	tptr->w   = tptr->w   * Density / 75;
	tptr->h   = tptr->h   * Density / 75;
	gdi_roundfill(wptr,tptr);
}

private	void	gdi_roundframe(char * wptr, struct text_item * tptr )
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
		gdi_fill(wptr,tptr); 
		}
	else	{
		tptr->atx = x+(v/2); tptr->aty = y      ; tptr->w = (w-v)+1; tptr->h=cpt    ; gdi_fill(wptr,tptr);
		tptr->atx = x      ; tptr->aty = y+(v/2); tptr->w = cpt    ; tptr->h=(h-v)+1; gdi_fill(wptr,tptr);
		tptr->atx = x+w-cpt; tptr->aty = y+(v/2); tptr->w = cpt    ; tptr->h=(h-v)+1; gdi_fill(wptr,tptr);
		tptr->atx = x+(v/2); tptr->aty = y+h-cpt; tptr->w = (w-v)+1; tptr->h=cpt    ; gdi_fill(wptr,tptr);
		tptr->atx = x      ; tptr->aty = y      ; tptr->w = v      ; tptr->h=v      ; tptr->align = 4; gdi_circle(wptr,tptr);
		tptr->atx = x+(w-v); tptr->aty = y      ; tptr->w = v      ; tptr->h=v      ; tptr->align = 5; gdi_circle(wptr,tptr);
		tptr->atx = x      ; tptr->aty = y+(h-v); tptr->w = v      ; tptr->h=v      ; tptr->align = 6; gdi_circle(wptr,tptr);
		tptr->atx = x+(w-v); tptr->aty = y+(h-v); tptr->w = v      ; tptr->h=v      ; tptr->align = 7; gdi_circle(wptr,tptr);
		}
}

private	void	gdi_hq_roundframe(char * wptr, struct text_item * tptr )
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
		gdi_roundframe(wptr,tptr);
		x++;
		y++;
		w-=2;
		h-=2;
		cpt--;
		}
	while(cpt);
}

private	void	gdi_xfill(char * wptr, struct text_item * tptr )
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

private	int	gdi_bestfit( int iw, int ih, int * zw, int * zh)
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

private	void	gdi_image(char * wptr, struct text_item * tptr )
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
			gdi_bestfit(iptr->columns,iptr->rows,&zc,&zr);
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

private	void	gdi_tile(char * wptr, struct text_item * tptr )
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

private	char * gdi_text_colour(char * wptr, struct prn_colour * cptr )
{
	int	a=0;
	int	r=0;
	int	g=0;
	int	b=0;
	r = ((cptr->red * 100)/255);	
	g = ((cptr->green * 100)/255);	
	b = ((cptr->blue * 100)/255);
	sprintf(wptr,"GdiScript.SetTextColour: ");
	wptr += strlen( wptr );	
	wptr = decimal(wptr,r);
	wptr = decimal(wptr,g);
	wptr = decimal(wptr,b);
	return( wptr );
}

private	char * gdi_background_colour(char * wptr, struct prn_colour * cptr )
{
	int	a=0;
	int	r=0;
	int	g=0;
	int	b=0;
	r = ((cptr->red * 100)/255);	
	g = ((cptr->green * 100)/255);	
	b = ((cptr->blue * 100)/255);
	sprintf(wptr,"GdiScript.SetBackgroundColour: ");
	wptr += strlen( wptr );	
	wptr = decimal(wptr,r);
	wptr = decimal(wptr,g);
	wptr = decimal(wptr,b);
	return( wptr );
}

private	void	gdi_text(char * wptr, struct text_item * tptr )
{
	int	spacecount=0;
	wptr = gdi_text_colour( wptr, &tptr->foreground);
	wptr = gdi_background_colour( wptr, &tptr->background);
	ShowFontSize = (GdiFont[tptr->font].size/4);
	switch ( tptr->align ) {
		case	 0	:
		case	-1	: /* no alignment */
			sprintf(wptr,"GdiScript.TextOut: %u %u %c%s%c %u\n",
				(LeftBorder+LeftMargin+tptr->atx),
				(TopBorder+BottomMargin+(RowCount-tptr->aty)-(ShowFontSize*3)),
				0x0022,tptr->message,0x0022,strlen(tptr->message));
			break;
		case	1	: /* right aligned */
			sprintf(wptr,"GdiScript.RightTextOut: %u %u %c%s%c %u\n",
				(LeftBorder+LeftMargin+tptr->atx),
				(TopBorder+BottomMargin+(RowCount-tptr->aty)-(ShowFontSize*3)),
				0x0022,tptr->message,0x0022,strlen(tptr->message));
			break;
		case	4	: /* justified */
			if ((spacecount = count_space(tptr->message)) != 0) {
				sprintf(wptr,"GdiScript.JustfiedTextOut: %u %u %c%s%c %u\n",
					(LeftBorder+LeftMargin+tptr->atx),
					(TopBorder+BottomMargin+(RowCount-tptr->aty)-(ShowFontSize*3)),
					0x0022,tptr->message,0x0022,strlen(tptr->message));
				break;
				}
		case	2	: /* left aligned */
			sprintf(wptr,"GdiScript.TextOut: %u %u %c%s%c %u\n",
				(LeftBorder+LeftMargin+tptr->atx),
				(TopBorder+BottomMargin+(RowCount-tptr->aty)-(ShowFontSize*3)),
				0x0022,tptr->message,0x0022,strlen(tptr->message));
			break;
		case	3	: /* centered */
			sprintf(wptr,"GdiScript.CenterTextOut: %u %u %c%s%c %u\n",
				(LeftBorder+LeftMargin+tptr->atx),
				(TopBorder+BottomMargin+(RowCount-tptr->aty)-(ShowFontSize*3)),
				0x0022,tptr->message,0x0022,strlen(tptr->message));
			break;

		default		:
			*wptr = 0;
		}
	flush_storage(wptr);
	return;
}

private	void	gdi_hq_text(char * wptr, struct text_item * tptr )
{
	gdi_text( wptr, tptr );
}

private	void	gdi_hq_image(char * wptr, struct text_item * tptr )
{
	gdi_image( wptr, tptr );
	return;
}

private	void	gdi_hq_font(char * wptr, struct text_item * tptr )
{
	switch ( tptr->atribut & 0x000E ) {
		case	0x0000	:
			sprintf(wptr,"%u %s ",((GdiFont[tptr->font].size*Density)/75),GdiFont[tptr->font].name);
			break;
		case	0x0002	:
			sprintf(wptr,"%u %s ",((GdiFont[tptr->font].size*Density)/75),GdiFont[tptr->font].bold);
			break;
		case	0x000C	:
		case	0x0008	:
		case	0x0004	:
			sprintf(wptr,"%u %s ",((GdiFont[tptr->font].size*Density)/75),GdiFont[tptr->font].italic);
			break;	
		case	0x000E	:
		case	0x000A	:
		case	0x0006	:
			sprintf(wptr,"%u %s ",((GdiFont[tptr->font].size*Density)/75),GdiFont[tptr->font].both);
			break;
		default		:
			*wptr = 0;
		}
	flush_storage(wptr);
	return;
}

private	void	gdi_font(char * wptr, struct text_item * tptr )
{
	switch ( tptr->atribut & 0x000E ) {
		case	0x0000	:
			sprintf(wptr,"%u %s ",GdiFont[tptr->font].size,GdiFont[tptr->font].name);
			break;
		case	0x0002	:
			sprintf(wptr,"%u %s ",GdiFont[tptr->font].size,GdiFont[tptr->font].bold);
			break;
		case	0x000C	:
		case	0x0008	:
		case	0x0004	:
			sprintf(wptr,"%u %s ",GdiFont[tptr->font].size,GdiFont[tptr->font].italic);
			break;
		case	0x000E	:
		case	0x000A	:
		case	0x0006	:
			sprintf(wptr,"%u %s ",GdiFont[tptr->font].size,GdiFont[tptr->font].both);
			break;
		default		:
			*wptr = 0;
		}
	flush_storage(wptr);
	return;
}

/*	-----------------------------		*/
/*	PostScript Palette Definition		*/
/*	-----------------------------		*/
private	char *	setrgbcolors( char * rptr )
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
private	int	encapsulate( char * rptr, char * sptr )
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
		if (!( eptr = Portable_getenv("GDIPATHTEMP"))) {
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
		GdiFont[i].name	=
		GdiFont[i].bold	=
		GdiFont[i].italic= 
		GdiFont[i].both 	= (char *) 0;
		fwh = guifontsize(i);
		GdiFont[i].size	= (((fwh >> 8) & 0x00FF)-2);
		GdiFont[i].width = (fwh & 0x00FF);
		GdiFont[i].info  = guifontinfo(i);
#ifdef	GDIT_TRACE
		if ( GdiFont[i].info) {
			printf("guifontinfo(%u) = %s : %s \r\n",i,GdiFont[i].info,guifontname(i));
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
	
	return(_GDI_LINESIZE);
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
	RasterByte = bptr;
	Storage = (FILE *) 0;

	if (!( RasterWork = wptr )) { 
		return(0);
		}	
	
	rptr = wptr;
	*rptr = 0;

	sprintf(rptr,"GdiScript.Name: %c%s%c\nGdiScript.Version: %c%c.%c%c%c\nGdiScript.Date: %c%s%c\n",
			0x0022,__DRIVER_NAME,0x0022,
			0x0022,__DRIVER_MAJOR,__DRIVER_MINOR,__DRIVER_INDEX,0x0022,
			0x0022,__DRIVER_DATE,0x0022 );
	rptr += strlen( rptr );

	sprintf(rptr,"GdiScript.Box: %u %u %u %u \n",LeftMargin,BottomMargin,LeftMargin+PaperWidth,BottomMargin+PaperHeight);
	rptr += strlen( rptr );
	sprintf(rptr,"GdiScript.PaperSize: %s \n",get_paper_name());
	rptr += strlen(rptr);

	if ( Landscaping )
		sprintf(rptr,"GdiScript.Orientation: Landscape \n");
	else	sprintf(rptr,"GdiScript.Orientation: Portrait  \n");
	rptr += strlen(rptr);

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
 			printf("psiiit: RasterWorkNull in DriverStartRaster \n"); 
			return(0);
			}
		else	{
			sprintf(wptr,"GdiScript.Page: %u \n",PageCount);
			wptr += strlen( wptr );
			switch ( Density ) {
				case	75	:
					sprintf(wptr,"GdiScript.Scale: 1 1\n");
					wptr += strlen( wptr );
					break;
				case	100	:
					sprintf(wptr,"GdiScript.Scale: 0.75 0.75 \n");
					wptr += strlen( wptr );
					break;
				case	150	:
					sprintf(wptr,"GdiScript.Scale: 0.5 0.5 \n");
					wptr += strlen( wptr );
					break;
				case	300	:
					sprintf(wptr,"GdiScript.Scale: 0.25 0.25 \n");
					wptr += strlen( wptr );
					break;
				case	600 	:
					sprintf(wptr,"GdiScript.Scale: 0.125 0.125 \n");
					wptr += strlen( wptr );
					break;
				case	1200 	:
					sprintf(wptr,"GdiScript.Scale: 0.0625 0.0625 \n");
					wptr += strlen( wptr );
					break;
				}
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

private	char *	decimal(char * wptr, int v )
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
			sprintf(wptr,"GdiScript.EndPage: %u \n",PageCount);
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
			if (!( GdiFont[tptr->font].name )) {
				GdiFont[tptr->font].name   = GdiFont[2].name;
				GdiFont[tptr->font].bold   = GdiFont[2].bold;
				GdiFont[tptr->font].italic = GdiFont[2].italic;
				GdiFont[tptr->font].both	  = GdiFont[2].both;
				}
			fwh = guifontsize(tptr->font);
			GdiFont[tptr->font].size	= (((fwh >> 8) & 0x00FF)-2);
			GdiFont[tptr->font].width = (fwh & 0x00FF);
			if (!( GdiFont[tptr->font].info ))
				GdiFont[tptr->font].info   = guifontinfo(tptr->font);
			if ( HighQuality )
				gdi_hq_font(wptr,tptr);
			else	gdi_font(wptr,tptr);
			}
		}

	if ( tptr->type != _PRINT_IMAGE ) {
//		gdi_colour(wptr,&tptr->foreground );
		}

	switch ( tptr->type ) {
		case	_PRINT_TEXT	:
			if ( HighQuality )
				gdi_hq_text(wptr,tptr);
			else	gdi_text(wptr,tptr);
			break;

		case	_PRINT_CIRCLE	:
			if ( HighQuality )
				gdi_hq_circle(wptr,tptr);
			else	gdi_circle(wptr,tptr);
			break;

		case	_PRINT_LINE	:
			if ( HighQuality )
				gdi_hq_line(wptr,tptr);
			else	gdi_line(wptr,tptr);
			break;

		case	_PRINT_XFILL	:
			if (( tptr->foreground.value & 0x00FF ) != 0 ) {
				if (( tptr->background.value & 0x00FF ) != 0 ) {
					if ( HighQuality )
						gdi_hq_fill(wptr,tptr);
					else	gdi_fill(wptr,tptr);
					//gdi_colour(wptr,&tptr->background );
					}
				gdi_xfill(wptr,tptr);
				}
			else if (( tptr->background.value & 0x00FF ) != 0 ) {
				//gdi_colour(wptr,&tptr->background );
				gdi_xfill(wptr,tptr);
				}
			break;

		case	_PRINT_FILL	:
			if ( HighQuality )
				gdi_hq_fill(wptr,tptr);
			else	gdi_fill(wptr,tptr);
			break;

		case	_PRINT_IMAGE	:
			if (( tptr->align  & 7 ) == 4)
				gdi_tile( wptr, tptr );
			else if ( HighQuality )
				gdi_hq_image(wptr,tptr);
			else	gdi_image(wptr,tptr);
			break;

		case	_PRINT_ROUNDFILL:
			if ( HighQuality )
				gdi_hq_roundfill(wptr,tptr);
			else	gdi_roundfill(wptr,tptr);
			break;

		case	_PRINT_ROUNDFRAME:
			if ( HighQuality )
				gdi_hq_roundframe(wptr,tptr);
			else	gdi_roundframe(wptr,tptr);
			break;

		}
	return(1);
}
#endif

#ifdef	PSIII_ULINE
private	void	gdi_underline( char * wptr, struct text_item * tptr )
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
	else if (!( RasterByte )) 
		return(0);

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
			if (( rlen + rl) < _GDI_LINESIZE ) {
				strcat(RasterByte,RasterWork);
				rlen += rl;
				*RasterWork=0;
				}
			else	break;
			}
		if ( Storage ) {
			i = 0;
			while ( i < _GDI_LINESIZE ) {
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




