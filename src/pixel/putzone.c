#ifndef	_putzone_c
#define	_putzone_c

#include "pixel.h"

void	putzone(unsigned int atx, unsigned int aty, unsigned int nbx, unsigned int nby, char * sptr )
{
	register unsigned int y;
	register unsigned int x;
	register int w;
	unsigned int xtx=0;
	register unsigned short s;
	register unsigned short v;
	register unsigned long  l;
	register unsigned char * pptr;
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

	ClipColumn( atx,nbx,xtx, "putzone" );
	ClipRow( aty,nby, "putzone" );

	ww  = (XGC.width*pixelsize);

	if (!( softout ))
		w   = XGC.imageptr->bytes_per_line; 
	else	w   = ww;

	if (!( XGC.mapping )) {
		/* Source buffer contains true colour pixels */
		for (y=0; y < nby; y++ ) {
			if (!( softout ))
				pptr = (XGC.storage + ((aty+y+ty)*w) + ((atx+tx)*pixelsize));
			qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*pixelsize));
			for (x=0; x < nbx; x++ ) {
				for ( s=0; s < pixelsize; s++ ) {
					v = *(sptr+((x*pixelsize)+s));
					if (!( softout )) 
						*(pptr++) = (char ) v;
					*(qptr++) = (char ) v;
					}
				}
			sptr += ((nbx+xtx)*pixelsize);
			}
		}
	else	{
		/* Source buffer contains colourmap pixels */
		/* --------------------------------------- */		
	switch ( XGC.visbpp ) {

		case	8 :
			for (y=0; y < nby; y++ ) {
				if (!( softout ))
					pptr = (XGC.storage + ((aty+y+ty)*w) + (atx+tx));
				qptr = (XGC.shadow  + ((aty+y)*ww) + atx);
				for (x=0; x < nbx; x++ ) {
					v = *(sptr+x);
					if (!( softout )) {
						*(pptr++) = bRgbTable[(v & 0x00FF)];
						}
					if ( colourmaped )
						*(qptr++) = (char)v;
					else	*(qptr++) = bRgbTable[(v & 0x00FF)];
					}
				sptr += (nbx+xtx);
				}
			break;

		case	16 :
			for (y=0; y < nby; y++ ) {
				if (!( softout ))
					pptr = (XGC.storage + ((aty+y+ty)*w) + ((atx+tx)*2));
				qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*pixelsize));
				for (x=0; x < nbx; x++ ) {
					v = *(sptr+(x*pixelsize));
					if (!( softout )) {
						s = wRgbTable[(v & 0x00FF)];
						*(pptr++) = (s & 0x00FF);
						*(pptr++) = ((s & 0xFF00)>>8);
						}
					if ( colourmaped )
						*(qptr++) = (char)v;
					else	{
						s = wRgbTable[(v & 0x00FF)];
						*(qptr++) = (s & 0x00FF);
						*(qptr++) = ((s & 0xFF00)>>8);
						}
					}
				sptr += ((nbx+xtx)*pixelsize);
				}
			break;

		case	32 :
			for (y=0; y < nby; y++ ) {
				if (!( softout ))
					pptr = (XGC.storage + ((aty+y+ty)*w) + ((atx+tx)*4));
				qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*pixelsize));
				for (x=0; x < nbx; x++ ) {
					v = *(sptr+(x*pixelsize));
					if (!( softout )) {
						 l = lRgbTable[(v & 0x00FF)];
						*(pptr++) = (char)(l & 0x00FF);
						*(pptr++) = (char)((l & 0xFF00)>>8);
						*(pptr++) = (char)((l & 0xFF0000)>>16);
						*(pptr++) = 0;
						}
					if ( colourmaped )
						*(qptr++) = (char)v;
					else	{
						l = lRgbTable[(v & 0x00FF)];
						*(qptr++) = (char)(l & 0x00FF);
						*(qptr++) = (char)((l & 0xFF00)>>8);
						*(qptr++) = (char)((l & 0xFF0000)>>16);
						*(qptr++) = 0;
						}
					}
				sptr += ((nbx+xtx)*pixelsize);
				}
			break;
		}
		}

	if (!( softout )) { 	
		outzone(atx+tx,aty+ty,nbx,nby);
		}
	return;
}

void	putzone8(unsigned int atx, unsigned int aty, unsigned int nbx, unsigned int nby, char * sptr )
{
	register unsigned int y;
	register unsigned int x;
	register int w;
	unsigned int xtx=0;
	register unsigned short s;
	register unsigned short v;
	register unsigned long  l;
	register unsigned char * pptr;
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

	ClipColumn( atx,nbx,xtx, "putzone" );
	ClipRow( aty,nby, "putzone" );

	ww  = (XGC.width*pixelsize);

	if (!( softout ))
		w   = XGC.imageptr->bytes_per_line; 
	else	w   = ww;

	switch ( XGC.visbpp ) {

		case	8 :
			for (y=0; y < nby; y++ ) {
				if (!( softout ))
					pptr = (XGC.storage + ((aty+y+ty)*w) + (atx+tx));
				qptr = (XGC.shadow  + ((aty+y)*ww) + atx);
				for (x=0; x < nbx; x++ ) {
					v = *(sptr+x);
					if (!( softout )) {
						*(pptr++) = bRgbTable[(v & 0x00FF)];
						}
					if ( colourmaped )
						*(qptr++) = (char)v;
					else	*(qptr++) = bRgbTable[(v & 0x00FF)];
					}
				sptr += (nbx+xtx);
				}
			break;

		case	16 :
			for (y=0; y < nby; y++ ) {
				if (!( softout ))
					pptr = (XGC.storage + ((aty+y+ty)*w) + ((atx+tx)*2));
				qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*pixelsize));
				for (x=0; x < nbx; x++ ) {
					v = *(sptr+x);
					if (!( softout )) {
						s = wRgbTable[(v & 0x00FF)];
						*(pptr++) = (s & 0x00FF);
						*(pptr++) = ((s & 0xFF00)>>8);
						}
					if ( colourmaped )
						*(qptr++) = (char)v;
					else	{
						s = wRgbTable[(v & 0x00FF)];
						*(qptr++) = (s & 0x00FF);
						*(qptr++) = ((s & 0xFF00)>>8);
						}
					}
				sptr += (nbx+xtx);
				}
			break;

		case	32 :
			for (y=0; y < nby; y++ ) {
				if (!( softout ))
					pptr = (XGC.storage + ((aty+y+ty)*w) + ((atx+tx)*4));
				qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*pixelsize));
				for (x=0; x < nbx; x++ ) {
					v = *(sptr+x);
					if (!( softout )) {
						 l = lRgbTable[(v & 0x00FF)];
						*(pptr++) = (char)(l & 0x00FF);
						*(pptr++) = (char)((l & 0xFF00)>>8);
						*(pptr++) = (char)((l & 0xFF0000)>>16);
						*(pptr++) = 0;
						}
					if ( colourmaped )
						*(qptr++) = (char)v;
					else	{
						l = lRgbTable[(v & 0x00FF)];
						*(qptr++) = (char)(l & 0x00FF);
						*(qptr++) = (char)((l & 0xFF00)>>8);
						*(qptr++) = (char)((l & 0xFF0000)>>16);
						*(qptr++) = 0;
						}
					}
				sptr += (nbx+xtx);
				}
			break;
		}
	if (!( softout )) { 	
		outzone(atx+tx,aty+ty,nbx,nby);
		}
	return;
}

#endif	/* _putzone */

