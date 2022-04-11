#ifndef	_xorzone_c
#define	_xorzone_c

#include "pixel.h"

void	xorzone(unsigned int atx, unsigned int aty, unsigned int nbx, unsigned int nby, unsigned int pixel )
{
	register int y;
	register int x;
	register int w;
	register unsigned short v;
	register unsigned long l;
	register char * pptr;
	register char * qptr;
	register int ww;
	register int colourmaped;
	register int pixelsize;
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
	pixelsize   = XGC.pixelsize;

	ww  = (XGC.width*pixelsize);

	ClipCoordinates(atx,aty,nbx,nby,"xorzone");

	if (!( softout ))
		w   = XGC.imageptr->bytes_per_line; 
	else	w   = ww;

	switch ( XGC.visbpp ) {

		case	8 	:
			v =  bRgbTable[(pixel & 0x00FF)];
			for (y=0; y < nby; y++ ) {
				if (!( softout ))
					pptr = (XGC.storage + ((aty+y+ty)*w) + (tx+atx));
				qptr = (XGC.shadow  + ((aty+y)*ww) + atx);
				for (x=0; x < nbx; x++ ) {
					if (!( softout ))
						*(pptr++) ^= v;
					if ( colourmaped )
						*(qptr++) ^= pixel;
					else	*(qptr++) ^= v;
					}
				}
			break;

		case	16	:
			v = wRgbTable[(pixel & 0x00FF)];
			for (y=0; y < nby; y++ ) {
				if (!( softout ))
					pptr = (XGC.storage + ((aty+y+ty)*w) + ((tx+atx)*2));
				qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*pixelsize));
				for (x=0; x < nbx; x++ ) {
					if (!( softout )) {
						*(pptr++) ^= (v & 0x00FF);
						*(pptr++) ^= ((v & 0xFF00) >> 8);
						}
					if ( colourmaped )
						*(qptr++) ^= pixel;
					else	{
						*(qptr++) ^= (v & 0x00FF);
						*(qptr++) ^= ((v & 0xFF00) >> 8);
						}
					}
				}
			break;

		case	32	:
			l = lRgbTable[(pixel & 0x00FF)];
			for (y=0; y < nby; y++ ) {
				if (!( softout ))
					pptr = (XGC.storage + ((aty+y+ty)*w) + ((atx+tx)*4));
				qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*pixelsize));
				for (x=0; x < nbx; x++ ) {
					if (!( softout )) {
						*(pptr++) ^= (l & 0x00FF);
						*(pptr++) ^= ((l & 0xFF00)>>8);
						*(pptr++) ^= ((l & 0xFF0000)>>16);
						*(pptr++) = 0;
						}
					if ( colourmaped )
						*(qptr++) ^= pixel;
					else	{
						*(qptr++) ^= (l & 0x00FF);
						*(qptr++) ^= ((l & 0xFF00)>>8);
						*(qptr++) ^= ((l & 0xFF0000)>>16);
						*(qptr++) = 0;
						}
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

#endif	/* _xorzone_c */


