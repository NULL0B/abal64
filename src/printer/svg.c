#ifndef	_SVG12_C
#define	_SVG12_C

#include "lodriver.h"
#include "vimage.h"
#include "svg.h"

#define	_SVG_LINESIZE	64000
#define	__QUOTE	0x0022
#define	putlo(v) *(result+(rlen++))=v
#define	escapeT( v ) rlen = packethead(result,rlen,v)
#define	private	static

private	int	StartXml=0;
private	int	Density=0;
private	int	PageCount=0;
private	int	PageOptions=0;
private	int	HighQuality=0;
private	int	Landscaping=0;
private	int	escapeTbugfix=0;
private	int	LeftMarginBytes=0;
private	int	PrinterReady=0;
private	int	RasterReady=0;
private	int	RowLength=0;
private	int	RowNumber=0;
private	int	RowCount=0;
private	char *	RasterByte=(char *) 0;
private	char *	RasterWork=(char *) 0;
private	int	PixelMask=0;
private	int	BitsPerPixel=0;
private	char *	PaletteBuffer=(char *) 0;
private	char	Number[32];
private	int	ScaleFactor=2;

/* ------------------------------ */
/* SVG pre-buffering file control */
/* ------------------------------ */
private	char * 	StoragePath=(char *) 0;
private	FILE *	Storage=(FILE*) 0;
private	char 	StorageName[256];
private	int	StorageMode=0;

int	_fltused=0;
void	_cfltcvt()	{ 	return; 	}
void	_cropzeros()	{ 	return; 	}
long	_aFftol()	{	return(0L);	}
int	luminence( char * bptr, int offset );


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

private	void	flush_storage(char * wptr)
{
	if ( Storage ) { fprintf(Storage,"%s",wptr); }
	return;
}

int	DriverInitialise(char * palette, int dpi, int grnbcol, int grnbrow, int options)
{
	int	t;
	PaletteBuffer = palette;
	Storage=(FILE*) 0;
	StorageMode=0;
	if ( options & _PAGE_QUALITY   )
		HighQuality=1;
	else	HighQuality=0;
	if ( options & _PAGE_LANDSCAPE ) {
		t = grnbcol;
		grnbcol = grnbrow;
		grnbrow = t;
		Landscaping = 1; 
		}
	else	Landscaping = 0; 

	Density = dpi;	PageCount=0;
	RasterReady   = PrinterReady = 0;
	PaletteBuffer = palette;
	PageOptions   = options;

	set_paper_dimensions( dpi, ((PageOptions & _PAPER_TYPE) >> 8));

	RowLength = grnbcol;
	RowCount  = grnbrow;
	RowNumber = 0;
	textfiltering=1;
	return(_SVG_LINESIZE);
}


int	DriverConnect( char * bptr, char * wptr, char * result )
{
	RasterByte = bptr;
	RasterWork = wptr;
	PrinterReady=1;
	return( 0 );
}

int	DriverStartRaster(char * result)
{
	int	rlen=0;
	if (!( RasterReady )) {
		RasterReady = 1;
		}
	if (!( StartXml )) {
		sprintf(result,"<?xml version=%c1.0%c?>\n",__QUOTE,__QUOTE);
		rlen   += strlen( result );
		result += strlen( result );
		sprintf(result,"<svg xmlns=%chttp://www.w3.org/2000/svg%c\n\txmlns:xlink=%chttp://www.w3.org/1999/xlink%c\n\tversion=%c1.2%c\n\tbaseProfile=%ctiny%c\n\tviewBox=%c0 0 %u %u%c>\n",
			__QUOTE,__QUOTE,
			__QUOTE,__QUOTE,
			__QUOTE,__QUOTE,
			__QUOTE,__QUOTE,
			__QUOTE,RowLength,RowCount,__QUOTE);
		rlen   += strlen( result );
		result += strlen( result );
		rlen   += strlen( result );
		result += strlen( result );
		if ( Landscaping ) {
			sprintf(result,"<g transform=%crotate(-90)%c>",__QUOTE,__QUOTE);
			rlen   += strlen( result );
			result += strlen( result );
			sprintf(result,"<g transform=%ctranslate(0,%u)%c>",__QUOTE,RowLength,__QUOTE);
			rlen   += strlen( result );
			result += strlen( result );
			}
		if ( ScaleFactor > 1 ) {
			sprintf(result,"<g transform=%cscale(%u)%c>",__QUOTE,ScaleFactor,__QUOTE);
			rlen   += strlen( result );
			result += strlen( result );
			}
		StartXml=1;
		}	
	return(rlen);
}


int	DriverEndRaster(char * result)
{
	if ( RasterReady ) {
		RasterReady=0;
		}
	return(0);
}

private	char	ColourNameBuf[256];
private	char *	svg_colour_name( int colour )
{
	int	r;
	int	g;
	int	b;
	switch ( colour ) {
		case	 0 :	return("black");
		case 	 1 :	return(	"navy");
		case	 2 :	return(	"green");
		case	 3 :	return(	"cyan");
		case	 4 :	return(	"red");
		case	 5 :	return(	"magenta");
		case	 6 :	return(	"brown");
		case	 7 :	return(	"grey");
		case	 8 :	return(	"silver");
		case	 9 :	return(	"blue");
		case	10 :	return(	"lime");
		case	11 :	return(	"sky");
		case	12 :	return(	"pink");
		case	13 :	return(	"purple");
		case	14 :	return(	"yellow");
		case	15 :	return(	"white");
		case	16 :	return(	"black");
		default	   :
			r = ( *(PaletteBuffer + ((colour & 0x00FF) * 4))   & 0x00FF);
			g = ( *(PaletteBuffer + ((colour & 0x00FF) * 4)+1) & 0x00FF);
			b = ( *(PaletteBuffer + ((colour & 0x00FF) * 4)+2) & 0x00FF);
			sprintf(ColourNameBuf,"#%02.2X%02.2X%02.2X",r,g,b);
			return( ColourNameBuf );
		}
}

private	void	svg_circle(char * wptr, struct text_item * tptr )
{
	char *	rptr=wptr;
	int	cx;
	int	cy;
	int	r;
	
	if ( tptr->w < tptr->h )
		r = tptr->w;
	else	r = tptr->h;
	cx = tptr->atx+(tptr->w/2);
	cy = tptr->aty+(tptr->h/2);
	sprintf(rptr,"<circle cx=%c%u%c cy=%c%u%c r=%c%u%c",
		__QUOTE,cx,__QUOTE,
		__QUOTE,cy,__QUOTE,
		__QUOTE,r,__QUOTE);
	rptr += strlen(rptr);
	sprintf(rptr," fill=%c%s%c stroke=%c%s%c stroke-width=%c%u%c/>\n",
		__QUOTE,svg_colour_name(tptr->foreground.value),__QUOTE,
		__QUOTE,"none",__QUOTE,
		__QUOTE,0,__QUOTE );
	flush_storage(wptr);
	return;	
}

private	void	svg_hq_circle(char * wptr, struct text_item * tptr )
{
	svg_circle(wptr,tptr);
	return;	
}

private	void	svg_text(char * wptr, struct text_item * tptr )
{
	char *	rptr=wptr;
	int	fw;
	int	fh;
	if (!( tptr ))
		return;
	else if (!( tptr->message ))
		 return;
	else if (!( fw = guifontsize(tptr->font) ))
		return;
	fh = ((fw >> 8) & 0x00FF);
	fw &= 0x00FF;
	sprintf(rptr,"<text x=%c%u%c y=%c%u%c font-size=%c%u%c fill=%c%s%c",
		__QUOTE,tptr->atx,__QUOTE,
		__QUOTE,tptr->aty+fh,__QUOTE,
		__QUOTE,((fh*3)/4),__QUOTE,
		__QUOTE,svg_colour_name(tptr->foreground.value),__QUOTE);
	rptr += strlen(rptr);
	switch ( tptr->align ) {
		case	1 :	/* right */
			sprintf(rptr," text-anchor=%cend%c",__QUOTE,__QUOTE);
			break;

		case	2 :	/* left */
			sprintf(rptr," text-anchor=%cstart%c",__QUOTE,__QUOTE);
			break;

		case	4 :	/* justify */
		case	3 :	/* center  */
			sprintf(rptr," text-anchor=%cmiddle%c",__QUOTE,__QUOTE);
			break;
		}
	rptr += strlen(rptr);
	sprintf(rptr,">%s</text>\n",tptr->message);
	rptr += strlen(rptr);
	flush_storage(wptr);
	return;	
}

private	void	svg_hq_text(char * wptr, struct text_item * tptr )
{
	svg_text(wptr,tptr);
	return;	
}

private	void	svg_line(char * wptr, struct text_item * tptr )
{
	char *	rptr=wptr;
	sprintf(rptr,"<g stroke=%c%s%c>",__QUOTE,svg_colour_name(tptr->foreground.value),__QUOTE);
	rptr += strlen(rptr);
	sprintf(rptr,"<line x1=%c%u%c y1=%c%u%c x2=%c%u%c y2=%c%u%c stroke-width=%c%u%c/>",
		__QUOTE,tptr->atx,__QUOTE,
		__QUOTE,tptr->aty,__QUOTE,
		__QUOTE,tptr->w,__QUOTE,
		__QUOTE,tptr->h,__QUOTE,
		__QUOTE,1,__QUOTE );
	rptr += strlen(rptr);
	sprintf(rptr,"</g>\n");
	rptr += strlen(rptr);
	flush_storage(wptr);
	return;
}

private	void	svg_hq_line(char * wptr, struct text_item * tptr )
{
	svg_line(wptr,tptr);
	return;	
}

private	void	svg_fill(char * wptr, struct text_item * tptr )
{
	char *	rptr=wptr;
	sprintf(rptr,"<rect x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c",
		__QUOTE,tptr->atx,__QUOTE,
		__QUOTE,tptr->aty,__QUOTE,
		__QUOTE,tptr->w,__QUOTE,
		__QUOTE,tptr->h,__QUOTE);
	rptr += strlen(rptr);
	sprintf(rptr," fill=%c%s%c stroke=%c%s%c stroke-width=%c%u%c/>\n",
		__QUOTE,svg_colour_name(tptr->foreground.value),__QUOTE,
		__QUOTE,"none",__QUOTE,
		__QUOTE,0,__QUOTE );
	flush_storage(wptr);
	return;	
}

private	void	svg_frame(char * wptr, struct text_item * tptr )
{
	char *	rptr=wptr;
	sprintf(rptr,"<rect x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c",
		__QUOTE,tptr->atx,__QUOTE,
		__QUOTE,tptr->aty,__QUOTE,
		__QUOTE,tptr->w,__QUOTE,
		__QUOTE,tptr->h,__QUOTE);
	rptr += strlen(rptr);
	sprintf(rptr," fill=%c%s%c stroke=%c%s%c stroke-width=%c%u%c/>\n",
		__QUOTE,"none",__QUOTE,
		__QUOTE,svg_colour_name(tptr->foreground.value),__QUOTE,
		__QUOTE,1,__QUOTE );
	flush_storage(wptr);
	return;	
}

private	void	svg_hq_fill(char * wptr, struct text_item * tptr )
{
	svg_fill( wptr, tptr );
	return;	
}

private	void	svg_xfill(char * wptr, struct text_item * tptr )
{
	svg_fill( wptr, tptr );
	return;	
}

private	void	svg_hq_xfill(char * wptr, struct text_item * tptr )
{
	svg_fill( wptr, tptr );
	return;	
}

private	void	svg_roundfill(char * wptr, struct text_item * tptr )
{
	char *	rptr=wptr;
	sprintf(rptr,"<rect x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c rx=%c%u%c",
		__QUOTE,tptr->atx,__QUOTE,
		__QUOTE,tptr->aty,__QUOTE,
		__QUOTE,tptr->w,__QUOTE,
		__QUOTE,tptr->h,__QUOTE,
		__QUOTE,10,__QUOTE );
	rptr += strlen(rptr);
	sprintf(rptr," fill=%c%s%c stroke=%c%s%c stroke-width=%c%u%c/>\n",
		__QUOTE,svg_colour_name(tptr->foreground.value),__QUOTE,
		__QUOTE,"none",__QUOTE,
		__QUOTE,0,__QUOTE );
	flush_storage(wptr);
	return;	
}

private	void	svg_hq_roundfill(char * wptr, struct text_item * tptr )
{
	svg_roundfill( wptr, tptr );
	return;	
}

private	void	svg_roundframe(char * wptr, struct text_item * tptr )
{
	char *	rptr=wptr;
	sprintf(rptr,"<rect x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c rx=%c%u%c",
		__QUOTE,tptr->atx,__QUOTE,
		__QUOTE,tptr->aty,__QUOTE,
		__QUOTE,tptr->w,__QUOTE,
		__QUOTE,tptr->h,__QUOTE,
		__QUOTE,10,__QUOTE );
	rptr += strlen(rptr);
	sprintf(rptr," fill=%c%s%c stroke=%c%s%c stroke-width=%c%u%c/>\n",
		__QUOTE,"none",__QUOTE,
		__QUOTE,svg_colour_name(tptr->foreground.value),__QUOTE,
		__QUOTE,1,__QUOTE );
	flush_storage(wptr);
	return;	
}

private	void	svg_hq_roundframe(char * wptr, struct text_item * tptr )
{
	svg_frame( wptr, tptr );
	return;	
}

private	void	svg_colour(char * wptr, struct text_item * tptr )
{
	return;	
}

private	void	svg_tile(char * wptr, struct text_item * tptr )
{
	int	x;
	int	y;
	struct	standard_image * iptr;
	char *	rptr=wptr;
	char *	nptr;
	if (!( tptr ))
		return;
	else if (!( iptr = tptr->image ))
		 return;
	else if (!( nptr = iptr->name ))
		return;
	else	{
		for (	y=tptr->aty;
			y < tptr->aty+tptr->h;
			y += iptr->rows) {
			for (	x=tptr->atx;
				x < tptr->atx+tptr->w;
				x += iptr->columns ) {
				sprintf(rptr,"<image x=%c%u%c",__QUOTE,x,__QUOTE);
				rptr += strlen(rptr);
				sprintf(rptr," y=%c%u%c",__QUOTE,y,__QUOTE);
				rptr += strlen(rptr);
				sprintf(rptr," width=%c%u%c",__QUOTE,((x + iptr->columns) > (tptr->atx+tptr->w) ? ((tptr->atx+tptr->w) - x) : iptr->columns) ,__QUOTE);
				rptr += strlen(rptr);
				sprintf(rptr," height=%c%u%c",__QUOTE,((y + iptr->rows) > (tptr->aty+tptr->h) ? ((tptr->aty+tptr->h) - y) : iptr->rows) ,__QUOTE);
				rptr += strlen(rptr);
				sprintf(rptr," xlink:href=%c%s%c/>\n",__QUOTE,nptr,__QUOTE);
				rptr += strlen(rptr);
				}
			}
		flush_storage(wptr);
		return;	
		}
	return;	
}

private	void	svg_image(char * wptr, struct text_item * tptr )
{
	struct	standard_image * iptr;
	char *	rptr=wptr;
	char *	nptr;
	if (!( tptr ))
		return;
	else if (!( iptr = tptr->image ))
		 return;
	else if (!( nptr = iptr->name ))
		return;
	else	{
		sprintf(rptr,"<image x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c xlink:href=%c%s%c/>\n",
			__QUOTE,tptr->atx,__QUOTE,
			__QUOTE,tptr->aty,__QUOTE,
			__QUOTE,tptr->w,__QUOTE,
			__QUOTE,tptr->h,__QUOTE,
			__QUOTE,nptr,__QUOTE);
		rptr += strlen(rptr);
		flush_storage(wptr);
		return;	
		}
}

private	void	svg_hq_image(char * wptr, struct text_item * tptr )
{
	svg_image( wptr, tptr );
	return;	
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
		sprintf(StorageName,"%ssvg%04.4x.tmp",StoragePath,getpid());
		if (!( Storage = fopen( StorageName,"w") ))
			return(46);
		else	StorageMode = 1;
		}
#ifdef	OHFUCK
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
			if ( HighQuality )
				svg_hq_font(wptr,tptr);
			else	svg_font(wptr,tptr);
			}
		}
#endif
	if ( tptr->type != _PRINT_IMAGE ) {
		svg_colour(wptr,tptr->foreground.value);
		}

	switch ( tptr->type ) {
		case	_PRINT_TEXT	:
			if ( HighQuality )
				svg_hq_text(wptr,tptr);
			else	svg_text(wptr,tptr);
			break;

		case	_PRINT_CIRCLE	:
			if ( HighQuality )
				svg_hq_circle(wptr,tptr);
			else	svg_circle(wptr,tptr);
			break;

		case	_PRINT_LINE	:
			if ( HighQuality )
				svg_hq_line(wptr,tptr);
			else	svg_line(wptr,tptr);
			break;

		case	_PRINT_XFILL	:
			if (( tptr->foreground.value & 0x00FF ) != 0 ) {
				if (( tptr->background.value & 0x00FF ) != 0 ) {
					if ( HighQuality )
						svg_hq_fill(wptr,tptr);
					else	svg_fill(wptr,tptr);
					svg_colour(wptr,tptr->background.value );
					}
				svg_xfill(wptr,tptr);
				}
			else if (( tptr->background.value & 0x00FF ) != 0 ) {
				svg_colour(wptr,tptr->background.value );
				svg_xfill(wptr,tptr);
				}
			break;

		case	_PRINT_FILL	:
			if ( HighQuality )
				svg_hq_fill(wptr,tptr);
			else	svg_fill(wptr,tptr);
			break;

		case	_PRINT_IMAGE	:
			if (( tptr->align  & 7 ) == 4)
				svg_tile( wptr, tptr );
			else if ( HighQuality )
				svg_hq_image(wptr,tptr);
			else	svg_image(wptr,tptr);
			break;

		case	_PRINT_ROUNDFILL:
			if ( HighQuality )
				svg_hq_roundfill(wptr,tptr);
			else	svg_roundfill(wptr,tptr);
			break;

		case	_PRINT_ROUNDFRAME:
			if ( HighQuality )
				svg_hq_roundframe(wptr,tptr);
			else	svg_roundframe(wptr,tptr);
			break;
		}
	return(1);
}
#endif

int	DriverLiberate(char * result)
{
	int	rlen=0;
	if ( RasterReady ) {
		rlen = DriverEndRaster(result);
		result += strlen( result );
		}
	if ( StartXml ) {
		if ( Landscaping ) {
			sprintf(result,"</g>\n");
			rlen += strlen( result );
			result += strlen( result );
			sprintf(result,"</g>\n");
			rlen += strlen( result );
			result += strlen( result );
			}
		if ( ScaleFactor > 1 ) {
			sprintf(result,"</g>\n");
			rlen += strlen( result );
			result += strlen( result );
			}

		sprintf(result,"</svg>\n");
		rlen += strlen( result );
		result += strlen( result );
		StartXml=0;
		}
	RasterWork = (char *) 0;
	RasterByte = (char *) 0;
	return(rlen);
}

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
	else if (!( RasterReady ))
		rlen = DriverStartRaster(result);

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
			if (( rlen + rl) < _SVG_LINESIZE ) {
				strcat(RasterByte,RasterWork);
				rlen += rl;
				*RasterWork=0;
				}
			else	break;
			}
		if ( Storage ) {
			i = 0;
			while ( i < _SVG_LINESIZE ) {
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

int	DriverColours()	
{	
	if ( Landscaping )
		return(256); 	/* inhibts the transformation */
	else	return(0);
}

#include "lodriver.c"

	/* -------- */
#endif	/* _SVG12_C */
	/* -------- */



