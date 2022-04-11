#ifndef	_mixch_c
#define	_mixch_c

#include "pixel.h"
#include "stdgigo.h"

void	mixcharacter(unsigned int atx, unsigned int aty, unsigned int nbx, unsigned int nby, char * sptr,int fg, int atribut )
{
	char *	optr=sptr;
	int	adjust=0;
	register unsigned int y;
	register unsigned int x;
	register unsigned int ty=0;
	register unsigned int tx=0;
		 int w;
	register unsigned short s;
	register unsigned short v;
	register unsigned long  l;
	register unsigned char * pptr;
	register char * qptr;
	register int ww;
	register int pixelsize=XGC.pixelsize;
	int cy = (XGC.scale) ? XGC.scale : 1;
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

	ww  = (XGC.width * pixelsize);

	if (!( softout ))
		w   = XGC.imageptr->bytes_per_line; 
	else	w   = ww;


	if ( atribut & _GIGO_SHADOW ) {
		mixcharacter(atx+SHADOWX, aty+SHADOWY, nbx, nby,sptr,SHADOWFG,0);
		if ( atribut & _GIGO_HIGHLIGHT )
			mixcharacter(atx+SHADOWX+1, aty+SHADOWY, nbx, nby,sptr,SHADOWFG,0);
		}

	ClipColumn(atx,nbx,adjust,"mixch");
	ClipRow(aty,nby,"mixch");

	if ( XGC.mapping ) {

		switch ( XGC.visbpp ) {
			case	8 :
				for (y=0; y < nby; y++ ) {
					if (!( softout ))
						pptr = (XGC.storage + ((aty+y+ty)*w) + (atx+tx));
					qptr = (XGC.shadow  + ((aty+y)*ww) + atx);
					for (x=0; x < nbx; x++ ) {
						if (!( *(sptr+x) )) {
							qptr++;
							pptr++;
							}	
						else	{
							if (!( softout )) {
								*(pptr++) = bRgbTable[(fg&0x00FF)];
								}
							*(qptr++) = fg;
							}	
						}	
					sptr += (nbx+adjust);
					}
				break;
			case	16 :
				for (y=0; y < nby; y++ ) {
					if (!( softout ))
						pptr = (XGC.storage + ((aty+y+ty)*w) + ((atx+tx)*2));
					qptr = (XGC.shadow  + ((aty+y)*ww) + atx);
					for (x=0; x < nbx; x++ ) {
						if (!( *(sptr+x) )) {
							qptr++; 
							pptr += 2;
							}
						else	{	
							*(qptr++) = fg;
							if (!( softout )) {
								v = wRgbTable[(fg & 0x00FF)];
								*(pptr++) = (v & 0x00FF);
								*(pptr++) = ((v & 0xFF00)>>8);
								}
							}
						}
					sptr += (nbx+adjust);
					}
				break;
			case	32 :
				for (y=0; y < nby; y++ ) {
					if (!( softout ))
						pptr = (XGC.storage + ((aty+y+ty)*w) + ((atx+tx)*4));
					qptr = (XGC.shadow  + ((aty+y)*ww) + atx);
					for (x=0; x < nbx; x++ ) {
						if (!( *(sptr+x) )) {
							qptr++;
							pptr += 4;
							}
						else	{
							*(qptr++) = fg;
							if (!( softout )) {
								 l = lRgbTable[(fg & 0x00FF)];
								*(pptr++) = (char)(l & 0x00FF);
								*(pptr++) = (char)((l & 0xFF00)>>8);
								*(pptr++) = (char)((l & 0xFF0000)>>16);
								*(pptr++) = 0;
								}
							}
						}
					sptr += (nbx+adjust);
					}
				break;
			}
		}
	else	{
		/* True Colour Version */
		/* ------------------- */
		switch ( XGC.visbpp ) {
			case	8 :
				for (y=0; y < nby; y++ ) {
					if (!( softout ))
						pptr = (XGC.storage + ((aty+y+ty)*w) + (atx+tx));
					qptr = (XGC.shadow  + ((aty+y)*ww) + atx);
					for (x=0; x < nbx; x++ ){
						if (!( *(sptr+x) )) {
							qptr++;
							pptr++;
							}
						else	{
							v = bRgbTable[fg & 0x00FF];
							if (!( softout ))
								 *(pptr++) = v;
							*(qptr++) = v; 
							}
						}
					sptr += (nbx+adjust);
					}
				break;
			case	16 :
				for (y=0; y < nby; y++ ) {
					if (!( softout ))
						pptr = (XGC.storage + ((aty+y+ty)*w) + ((atx+tx)*2));
					qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*pixelsize));
					for (x=0; x < nbx; x++ ) {
						if (!( *(sptr+x) )) {
							qptr+=2;
							pptr+=2;
							}
						else	{
							s = wRgbTable[fg & 0x00FF];
							if (!( softout )) {
								*(pptr++) = (s & 0x00FF);
								*(pptr++) = ((s & 0xFF00)>>8);
								}
							*(qptr++) = (s & 0x00FF);
							*(qptr++) = ((s & 0xFF00)>>8);
							}
						}
					sptr += (nbx+adjust);
					}
				break;
			case	32 :
				for (y=0; y < nby; y++ ) {
					if (!( softout ))
						pptr = (XGC.storage + ((aty+y+ty)*w) + ((atx+tx)*4));
					qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*pixelsize));
					for (x=0; x < nbx; x++ ) {
						if (!( *(sptr+x) )) {
							qptr += 4;
							pptr += 4;
							}
						else	{
							l = lRgbTable[fg & 0x00FF];
							if (!( softout )) {
								*(pptr++) = (char)(l & 0x00FF);
								*(pptr++) = (char)((l & 0xFF00)>>8);
								*(pptr++) = (char)((l & 0xFF0000)>>16);
								*(pptr++) = 0;
								}
								*(qptr++) = (char)(l & 0x00FF);
							*(qptr++) = (char)((l & 0xFF00)>>8);
							*(qptr++) = (char)((l & 0xFF0000)>>16);
							*(qptr++) = 0;
							}
						}
					sptr += (nbx+adjust);
					}
				break;
			}
		}

	/* FCH partie identique à putch */
	if ( atribut & _GIGO_HIGHLIGHT ) 
		mixcharacter(atx+1,aty, nbx, nby,optr,fg,0 );

	if ( atribut & _GIGO_UNDERLINE ) {
		if ( nby > 8 )
			filzone(atx, aty+(nby-4*cy), nbx, cy, fg);
		else	
			filzone(atx,aty+(nby-1),nbx,1,fg);
		}

	if ( atribut & _GIGO_OVERLINE )
		filzone(atx, aty, nbx, cy, fg);

	if ( atribut & _GIGO_STRIKE )
		filzone(atx, (aty+((nby/2*cy)-1)), nbx, cy, fg);

	if (!( softout )) {
		outzone(atx+tx,aty+ty,nbx,nby);
		}

	return;
}
#endif	/* _mixch */


