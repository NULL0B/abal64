#ifndef	_PSIII_C
#define	_PSIII_C

#include "lodriver.h"

#include "psiii.h"

#define	_POSTSCRIPT_LINESIZE	64000

static	char * 	PaletteBuffer=(char *) 0;
static	char * 	RasterByte=(char *) 0;
static	char * 	RasterWork=(char *) 0;
static	int	RasterReady=0;
static	int	PrinterReady=0;
static	int	RowNumber=0;
static	int	RowCount=0;
static	int	RightMargin=0;
static	int	TopBorder=13;
static	int	LeftBorder=14;
static	int	BottomMargin=0;
static	int	TopMargin=0;
static	int	LeftMargin=0;
static	int	ColCount=0;
static	int	PageOptions=0;
static	int	Density=0;
static	int	PageCount=0;
static	int	ShowFontSize=16;
static	int	Landscaping=0;
static	int	HighQuality=0;



int	_fltused=0;
void	_cfltcvt()	{ 	return; 	}
void	_cropzeros()	{ 	return; 	}
long	_aFftol()	{	return(0L);	}

static	int	max_red  =_RED_MASK32;
static	int	max_green=_GREEN_MASK32;
static	int	max_blue =_BLUE_MASK32;

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
	return(1);
}

/*	-----------------------------------	*/
/*	PostScript Operator	M O V E T O	*/
/*	-----------------------------------	*/
static	char *	moveto(char * bptr, int x)
{
	sprintf(bptr,"%u %u m ",LeftBorder+LeftMargin+x,TopBorder+TopMargin+(RowCount-RowNumber));
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

/*		pzazzzx(bptr,r);	*/
/*		pzazzzx(bptr,g);	*/
/*		pzazzzx(bptr,b);	*/
/*		printf("\r\n");		*/

		sprintf(bptr,"p\n");
		}
	return( (bptr + strlen(bptr)) );
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

/*	---------------------------------------------------------------------------	*/
/*	D r i v e r I n i t i a l i s e ( palette, dpi, grnbcol, grnbrow, options )	*/
/*	---------------------------------------------------------------------------	*/
int	DriverInitialise(char * palette, int dpi, int grnbcol, int grnbrow, int options )
{
	if ( options & _PAGE_QUALITY   )
		HighQuality=1;
	else	HighQuality=0;
	set_colour_options( options );
	if (!( colourmapping )) { set_white_limit( pixelsize ); }
	Density = dpi;	PageCount=0;
	RasterReady   = PrinterReady = 0;
	PaletteBuffer = palette;
	PageOptions   = options;
	set_paper_dimensions( dpi, ((PageOptions & _PAPER_TYPE) >> 8));
	RowCount      = grnbrow;
	ColCount      = grnbcol;
	TopMargin     = 0;
	LeftMargin    = 0;
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
		}
	return(_POSTSCRIPT_LINESIZE);
}

/*	---------------------------------------------------------------------------	*/
/*		    D r i v e r C o n n e c t ( bptr, wptr, result )			*/
/*	---------------------------------------------------------------------------	*/
int	DriverConnect( char * bptr, char * wptr, char * result )
{
	char	*	rptr;
	RasterByte = bptr;
	RasterWork = wptr;
	
	rptr = wptr;
	*rptr = 0;

	sprintf(rptr,"%c!PS-Adobe 3.0\n%c!%s version : %c.%c%c : date %s \n",
			0x0025,
			0x0025,
			__DRIVER_NAME,
			__DRIVER_MAJOR,__DRIVER_MINOR,__DRIVER_INDEX,
			__DRIVER_DATE );
	rptr += strlen( rptr );
	sprintf(rptr,"/m { newpath moveto } bind def \n");
	rptr += strlen( rptr );
	sprintf(rptr,"/l { rlineto } bind def \n");
	rptr += strlen( rptr );
	if ( PageOptions & _FORCE_GRAYSCALE ) {
		sprintf(rptr,"/p { setgray stroke } bind def \n");
		rptr += strlen( rptr );
		}
	else if ( colourmapping ) {
		sprintf(rptr,"/p { stroke } bind def \n");
		rptr += strlen( rptr );
		sprintf(rptr,"/srgb { setrgbcolor } bind def \n");
		rptr += strlen( rptr );
		rptr = setrgbcolors(rptr);
		}
	else	{
		sprintf(rptr,"/p { setrgbcolor stroke } bind def \n");
		rptr += strlen( rptr );
		}

	PrinterReady=1;
	return(encapsulate(result,RasterWork));
}

/*	---------------------------------------------------------------------------	*/
/*			D r i v e r S t a r t R a s t e r ( result )			*/
/*	---------------------------------------------------------------------------	*/
int	DriverStartRaster(char * result)
{
	char	*	wptr;
	if (!( PrinterReady ))
		return(0);
	else if (!( RasterReady )) {
		RasterReady=1;
		RowNumber = 0;
		PageCount++;		
		if (!(wptr=RasterWork)) {
/* 			printf("psiiit: RasterWorkNull in DriverStartRaster \r\n"); */
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
			return(encapsulate(result,RasterWork));
			}
		}
	return(0);
}


/*	---------------------------------------------------------------------------	*/
/*		 	D r i v e r E n d R a s t e r ( result )			*/
/*	---------------------------------------------------------------------------	*/
int	DriverEndRaster(char * result)
{
	char *	wptr;
	if (!( PrinterReady ))
		return(0);
	else if (!( RasterReady ))
		return(0);
	else	{
		RasterReady=0;
		RowNumber = 0;
		wptr=RasterWork;
		sprintf(wptr,"showpage\ngrestore\n");
		return(encapsulate(result,RasterWork));
		}
}

/*	---------------------------------------------------------------------------	*/
/*			D r i v e r L i b e r a t e ( result )				*/
/*	---------------------------------------------------------------------------	*/
int	DriverLiberate(char * result)
{
	return(0);
}

/*	---------------------------------------------------------------------------	*/
/*		D r i v e r P r i n t R o w ( result, rowbuffer )			*/
/*	---------------------------------------------------------------------------	*/
int	DriverPrintRow(char * result, char * rowbuffer)
{
	int	rlen=0;
	int	o;
	int	i;
	int	n;
	int	d;
	int	dd;
	char *	wptr;

	if (!( PrinterReady )) 
		return(0);
	else if (!( wptr=RasterWork )) 
		return(0);


	*wptr = 0;

/*	printf("DriverRow %u of %u\r\n",RowNumber,RowCount);		*/
	for (	o=0,d=-1,n=0,i=0; i < ColCount; i++ ) {
/*		printf("\tDriverCol %u of %u : 0x0%x \r\n",i,ColCount,logicalpixel(rowbuffer,i));	*/
		if ( d == -1 ) {
			o = i;
			d = logicalpixel(rowbuffer,i);
			n = 1;
			}
		else if ((dd = logicalpixel(rowbuffer,i)) == d ) {
			n++;
			}
		else	{
/*			printf("m %u l %u s %u\r\n",o,n,d);		*/
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
/*		printf("m %u l %u s %u\r\n",o,n,d);		*/
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
	rlen = encapsulate(result,RasterWork);
/*	if ( rlen > 33000 ) { printf("\r\nDriverPrintRow(length=%u)\r\n",rlen); }	*/
	return( rlen );

}

/*	---------------------------------------------------------------------------	*/
/*				D r i v e r C o l o u r s () 				*/
/*	---------------------------------------------------------------------------	*/
int	DriverColours()	
{	
	return(0); 	
}


#include "lodriver.c"

	/* ------------- */
#endif	/* _DRIVERABAL_C */
	/* ------------- */




