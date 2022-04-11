#ifndef	_filzone_c
#define	_filzone_c

#include "pixel.h"

/*	X F I L Z O N E ( atx, aty, nbx, nby , colours ) 	*/
/*	------------------------------------------------	*/
/*	     FILZONE will fill the rectangle defined by		*/
/*	atx,aty nbx,nby with the colour value parameter.	*/
/*	This is a real workhorse function performing		*/
/*	most of the pixel output for more evolved functions.	*/
/*	The target bit map may be 8,16 or 24 bit true colour.	*/
/*	The source pixel values are, as usual 8 bit colour	*/
/*	map entries.						*/


void	filzone(unsigned int atx, unsigned int aty, unsigned int nbx, unsigned int nby, unsigned int pixel )
{
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

	ClipCoordinates( atx,aty,nbx,nby, "filzone" );

	if (!( softout ))
		w   = XGC.imageptr->bytes_per_line; 
	else	w   = ww;

	switch ( XGC.visbpp ) {

		case	8 	:
			if (!( pixel & 0x80000000)) 
				v =  bRgbTable[(pixel & 0x00FF)];
			else 	v = pixel & 0x7FFFFFFF; //FCH

			for (y=0; y < nby; y++ ) {
				if (!( softout ))
					pptr = (XGC.storage + ((aty+y+ty)*w) + (atx+tx));
				qptr = (XGC.shadow  + ((aty+y)*ww) + atx);
				for (x=0; x < nbx; x++ ) {
					if (!( softout )) 
						*(pptr++) = (char)v;
					if (!( colourmaped ))
						*(qptr++) = (char) v;
					else	*(qptr++) = pixel;
					}
				}
			break;

		case	16	:
			if (!( pixel & 0x80000000)) 
				v = wRgbTable[(pixel & 0x00FF)];
			else 	v = pixel & 0x7FFFFFFF; //FCH

			for (y=0; y < nby; y++ ) {
				if (!( softout ))
					pptr = (XGC.storage + ((aty+y+ty)*w) + ((tx+atx)*2));
				qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*pixelsize));
				for (x=0; x < nbx; x++ ) {
					if (!( softout )) {
						*(pptr++) = (v & 0x00FF);
						*(pptr++) = ((v & 0xFF00) >> 8);
						}
					if (!( colourmaped )) {
						*(qptr++) = (v & 0x00FF);
						*(qptr++) = ((v & 0xFF00) >> 8);
						}
					else	*(qptr++) = pixel;
					}
				}
			break;

		case	32	:
			if (!( pixel & 0x80000000)) 
				l = lRgbTable[(pixel & 0x00FF)];
			else 	l = pixel & 0x7FFFFFFF; //FCH

			for (y=0; y < nby; y++ ) {
				if (!( softout ))
					pptr = (XGC.storage + ((aty+y+ty)*w) + ((tx+atx)*4));
				qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*pixelsize));
				for (x=0; x < nbx; x++ ) {
					if (!( softout )) {
						*(pptr++) = (char)(l & 0x00FF);
						*(pptr++) = (char)((l & 0xFF00)>>8);
						*(pptr++) = (char)((l & 0xFF0000)>>16);
						*(pptr++) = 0;
						}
					if (!( colourmaped )) {
						*(qptr++) = (char)(l & 0x00FF);
						*(qptr++) = (char)((l & 0xFF00)>>8);
						*(qptr++) = (char)((l & 0xFF0000)>>16);
						*(qptr++) = 0;
						}
					else	*(qptr++) = pixel;
					}
				}
			break;

		default		:
			return;
		}

	if (!( softout )) {
		outzone(atx+tx,aty+ty,nbx,nby);
		}
	return;
}

/*	X F I L Z O N E ( atx, aty, nbx, nby , colours ) 	*/
/*	------------------------------------------------	*/
/*	Like FILZONE, XFILZONE will fill a rectangle with	*/
/*	colour values taken alternatly from the low byte	*/
/*	then high byte of the word value parameter.		*/

void	xfilzone(unsigned int atx, unsigned int aty, unsigned int nbx, unsigned int nby, int pixel )
{
	register int p;
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
	ww  = (XGC.width*XGC.pixelsize);

	ClipCoordinates( atx,aty,nbx,nby, "xfilzone" );

	if (!( softout ))
		w   = XGC.imageptr->bytes_per_line; 
	else	w   = ww;

	switch ( XGC.visbpp ) {

		case	8 	:
			for (y=0; y < nby; y++ ) {
				pptr = (XGC.storage + ((aty+y+ty)*w) + (tx+atx));
				qptr = (XGC.shadow  + ((aty+y)*ww) + atx);
				for (p=pixel,x=0; x < nbx; x++ ) {
					if ( p & 0x00FF ) {
						v =  bRgbTable[(p & 0x00FF)];
						if (!( softout )) {
							*(pptr++) = (char)v;
							}
						if ( colourmaped )
						*(qptr++) = (p & 0x00FF);
						else	*(qptr++) = (char)v;
						}
					else	{
						if (!( softout )) pptr++;
							qptr ++;
						} 
					p = (((p & 0x00FF) << 8) | ((p & 0xFF00) >> 8));

					}
				pixel = (((pixel & 0x00FF) << 8) | ((pixel & 0xFF00) >> 8));
				}
			break;

		case	16	:
			for (y=0; y < nby; y++ ) {
				pptr = (XGC.storage + ((aty+y+ty)*w) + ((tx+atx)*2));
				qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*pixelsize));
				for (p=pixel,x=0; x < nbx; x++ ) {
					if ( p & 0x00FF ) {
						v = wRgbTable[(p & 0x00FF)];
						if (!( softout )) {
							*(pptr++) = (v & 0x00FF);
							*(pptr++) = ((v & 0xFF00) >> 8);
							}
						if ( colourmaped )
						*(qptr++) = p;
						else	{
							*(qptr++) = (v & 0x00FF);
							*(qptr++) = ((v & 0xFF00) >> 8);
							}
						}
					else	{
						if (!( softout )) pptr += 2;
						if ( colourmaped )
							qptr++;
						else	qptr += pixelsize;
						} 

					p = (((p & 0x00FF) << 8) | ((p & 0xFF00) >> 8));
					}
				pixel = (((pixel & 0x00FF) << 8) | ((pixel & 0xFF00) >> 8));
				}
			break;

		case	32	:
			for (y=0; y < nby; y++ ) {
				pptr = (XGC.storage + ((aty+y+ty)*w) + ((atx+tx)*4));
				qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*pixelsize));
				for (p=pixel,x=0; x < nbx; x++ ) {
					if ( p & 0x00FF ) {
						l = lRgbTable[(p & 0x00FF)];
						if (!( softout )) {
							*(pptr++) = (char)(l & 0x00FF);
							*(pptr++) = (char)((l & 0xFF00)>>8);
							*(pptr++) = (char)((l & 0xFF0000)>>16);
							*(pptr++) = 0;
							}
						if ( colourmaped )
						*(qptr++) = p;
						else	{
							*(qptr++) = (char)(l & 0x00FF);
							*(qptr++) = (char)((l & 0xFF00)>>8);
							*(qptr++) = (char)((l & 0xFF0000)>>16);
							*(qptr++) = 0;
							}
						}
					else	{
						if (!( softout )) pptr += 4;
						if ( colourmaped )
							qptr++;
						else	qptr += pixelsize;
						} 
					p = (((p & 0x00FF) << 8) | ((p & 0xFF00) >> 8));
					}
				pixel = (((pixel & 0x00FF) << 8) | ((pixel & 0xFF00) >> 8));
				}
			break;

		default		:
			return;
		}

	if (!( softout )) {
		outzone(atx+tx,aty+ty,nbx,nby);
		}
	return;
}

#endif	/* _filzone_c */


