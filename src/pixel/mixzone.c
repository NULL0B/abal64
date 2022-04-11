#ifndef	_mixzone_c
#define	_mixzone_c

#include "pixel.h"

void	mixzone(unsigned int atx, unsigned int aty, unsigned int nbx, unsigned int nby, char * sptr )
{
	register unsigned int y;
	register unsigned int x;
		 int w;
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

	ww  = (XGC.width*pixelsize);

	ClipColumn( atx,nbx,xtx, "mixzone" );
	ClipRow( aty,nby, "mixzone" );

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
					if (!(v = *(sptr+x) )) {
						if (!( softout ))
							pptr++;	
						qptr++;
						}
					else	{
						if (!( softout )) {
							*(pptr++) = bRgbTable[(v & 0x00FF)];
							}
						if ( colourmaped )
						*(qptr++) = (char)v;
						else	*(qptr++) = v; /* bRgbTable[(v & 0x00FF)]; */
						}
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

					/* test source pixel value for transparence */
					/* ---------------------------------------- */
					if ( colourmaped ) {
						if (!( v = *(sptr+x) )) {
						if (!( softout ))
							pptr += 2;
						qptr++;
						}
					else	{	
							/* transfer the pixel value */
							/* ------------------------ */
						if (!( softout )) {
							s = wRgbTable[(v & 0x00FF)];
							*(pptr++) = (s & 0x00FF);
							*(pptr++) = ((s & 0xFF00)>>8);
							}
						*(qptr++) = (char)v;
							}
						}
						else	{
						if (!(v = ( (*(sptr+(x*pixelsize)) & 0x00FF)
							  | ( (*(sptr+(x*pixelsize)+1) & 0x00FF) << 8))
							)) {
							if (!( softout ))
								pptr += 2;
							qptr += 2;
							}
						else	{
							if (!( softout )) {
								*(pptr++) = (v & 0x00FF);
								*(pptr++) = ((v & 0xFF00)>>8);
								}
							*(qptr++) = (v & 0x00FF);
							*(qptr++) = ((v & 0xFF00)>>8);
							}
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

					/* test source pixel value for transparence */
					/* ---------------------------------------- */
					if ( colourmaped ) {
						if (!( v = *(sptr+x) )) {
						if (!( softout ))
							pptr += 4;
						qptr++;
						}
						else	{
								/* transfer the pixel value */
								/* ------------------------ */
							if (!( softout )) {
									l = lRgbTable[(v & 0x00FF)];
									*(pptr++) =  (l & 0x00FF);
									*(pptr++) = ((l & 0xFF00)>>8);
									*(pptr++) = ((l & 0xFF0000)>>16);
								*(pptr++) = 0;
								}
							*(qptr++) = (char)v;
							}
						}
					else	{
						if (!(l = ( (*(sptr+(x*pixelsize)) & 0x00FF)
							  | ( (*(sptr+(x*pixelsize)+1) & 0x00FF) << 8)
							  | ( (*(sptr+(x*pixelsize)+2) & 0x00FF) << 16))
							)) {
							if (!( softout ))
								pptr += 4;
							qptr += 4;
							}
						else	{
							if (!( softout )) {
								*(pptr++) = ( l & 0x00FF);
								*(pptr++) = ((l & 0xFF00)>>8);
								*(pptr++) = ((l & 0xFF0000)>>16);
								*(pptr++) = 0;
								}
							*(qptr++) = ( l & 0x00FF);
							*(qptr++) = ((l & 0xFF00)>>8);
							*(qptr++) = ((l & 0xFF0000)>>16);
							*(qptr++) = 0;
							}
						}
					}
				sptr += ((nbx+xtx)*pixelsize);
				}
			break;

		}

	if (!( softout )) {
		outzone(atx+tx,aty+ty,nbx,nby);
		}
	return;
}

void	mixzone8(unsigned int atx, unsigned int aty, unsigned int nbx, unsigned int nby, char * sptr )
{
	register unsigned int y;
	register unsigned int x;
		 int w;
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

	ww  = (XGC.width*pixelsize);

	ClipColumn( atx,nbx,xtx, "mixzone" );
	ClipRow( aty,nby, "mixzone" );

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
					if (!(v = *(sptr+x) )) {
						if (!( softout ))
							pptr++;	
						qptr++;
						}
					else	{
						if (!( softout )) {
							*(pptr++) = bRgbTable[(v & 0x00FF)];
							}
						if ( colourmaped )
							*(qptr++) = (char)v;
						else	*(qptr++) = bRgbTable[(v & 0x00FF)];
						}
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
					if (!(v = *(sptr+x) )) {
						if (!( softout ))
							pptr += 2;
						if ( colourmaped )
							qptr++;
						else	qptr += 2;
						}
					else	{	
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
					if (!(v = *(sptr+x) )) {
						if (!( softout ))
							pptr += 4;
						if ( colourmaped )
							qptr++;
						else	qptr += 4;
						}
					else	{
						l = lRgbTable[(v & 0x00FF)];
						if (!( softout )) {
							*(pptr++) = (char)(l & 0x00FF);
							*(pptr++) = (char)((l & 0xFF00)>>8);
							*(pptr++) = (char)((l & 0xFF0000)>>16);
							*(pptr++) = 0;
							}
						if ( colourmaped )
							*(qptr++) = (char)v;
						else	{
							*(qptr++) = (char)(l & 0x00FF);
							*(qptr++) = (char)((l & 0xFF00)>>8);
							*(qptr++) = (char)((l & 0xFF0000)>>16);
							*(qptr++) = 0;
							}
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

#endif	/* _mixzone */









