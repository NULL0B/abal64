#ifndef	_shadzone_c
#define	_shadzone_c

#include "pixel.h"

/*	X S H A D Z O N E ( atx, aty, nbx, nby , colours ) 	*/
/*	--------------------------------------------------	*/
/*	     FILZONE will alter the rectangle defined by	*/
/*	atx,aty nbx,nby using the colour value parameter.	*/
/*	For all pixels in the zone the colour values of the 	*/
/*	shading colour will be added to the pixel colours	*/
/*	and then averaged to create the new pixel		*/
/*	The target bit map may be 8,16 or 24 bit true colour.	*/
/*	The source pixel values are, as usual 8 bit colour	*/
/*	map entries.						*/


void	shadzone(unsigned int atx, unsigned int aty, unsigned int nbx, unsigned int nby, unsigned int pixel )
{
	int	r;
	int	g;
	int	b;
	int	rv;
	int	gv;
	int	bv;
	register unsigned int y;
	register unsigned int x;
	register int w;
	register unsigned short v;
	register unsigned long l;
	register char * pptr;
	register char * qptr;
	register int ww;
	register int colourmaped;
	register int pixelsize=XGC.pixelsize;
	register unsigned int ty=0;
	register unsigned int tx=0;
	register int softout=0;

	if (!( XGC.displayptr ))
		softout = 1;
	else if ( XGC.softoutput != (char *) 0) {
		if (!(tx = XGC.targetx ))
			softout = 1;
		else 	{
			tx--;
			ty = XGC.targety-1;
			}
		}

	colourmaped = XGC.mapping;
	ww  = (XGC.width*pixelsize);

	ClipCoordinates( atx,aty,nbx,nby, "shadzone" );

	if (!( softout ))
		w   = XGC.imageptr->bytes_per_line; 
	else	w   = ww;

	if (!( pixel & 0x80000000)) {
		get_rgb_values((pixel & 0x00FF),&rv,&gv,&bv);
		}
	else 	{
		v = pixel & 0x7FFFFFFF; //FCH
		rv = ((pixel & 0x00FF0000) >> 16);
		gv = ((pixel & 0x0000FF00) >> 8 );
		bv = ((pixel & 0x000000FF)      );
		}

	for (y=0; y < nby; y++ ) {
		if (!( softout ))
			pptr = (XGC.storage + ((aty+y+ty)*w) + ((atx+tx)*pixelsize));
		qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*pixelsize));
		for (x=0; x < nbx; x++ ) {
			if (!( softout )) {
				get_logical_pixel( pptr, &r, &g, &b );
				r = ((r+rv)/2);
				g = ((g+gv)/2);
				b = ((b+bv)/2);
				put_logical_pixel( pptr, r, g ,b );
				pptr += pixelsize;
				}
			if (!( colourmaped )) {
				get_logical_pixel( qptr, &r, &g, &b );
				r = ((r+rv)/2);
				g = ((g+gv)/2);
				b = ((b+bv)/2);
				put_logical_pixel( qptr, r, g ,b );
				qptr += pixelsize;
				}
			}
		}

	if (!( softout )) {
		outzone(atx+tx,aty+ty,nbx,nby);
		}
	return;
}

#endif	/* _shadzone_c */



