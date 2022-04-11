#ifndef	_putch_c
#define	_putch_c

#include "pixel.h"
#include "stdgigo.h"

void	putcharacter(unsigned int atx, unsigned int aty, unsigned int nbx, unsigned int nby, char * sptr, int fg, int bg, int atribut )
{
	char 	*	optr=sptr;
	int	     adjust=0;
	register unsigned int y;
	register unsigned int x;
		 int w;
	register unsigned short s;
	register unsigned short v;
	register unsigned long  l;
	register unsigned char * pptr;

	unsigned char	 bgfg[2];

	register char * qptr;
	register int ww;
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

	if ( atribut & _GIGO_SHADOW ) {
		/* La totale ! */
		putcharacter(atx+SHADOWX, aty+SHADOWY, nbx, nby,sptr,SHADOWFG,bg,0);

		if ( atribut & _GIGO_HIGHLIGHT )
			mixcharacter(atx+SHADOWX+1, aty+SHADOWY, nbx, nby,sptr,SHADOWFG,0);

		mixcharacter(atx, aty, nbx, nby,sptr,fg,0);
		if ( atribut & _GIGO_HIGHLIGHT )
			mixcharacter(atx+1, aty, nbx, nby,sptr,fg,0);
		if ( atribut & _GIGO_UNDERLINE ) { 
			if ( nby > 8 )
				filzone(atx,aty+(nby-4),nbx,1,fg);
			else	filzone(atx,aty+(nby-1),nbx,1,fg);
			}
		if ( atribut & _GIGO_OVERLINE )
			filzone(atx,aty,nbx,1,fg);
		if ( atribut & _GIGO_STRIKE )
			filzone(atx,(aty+((nby/2)-1)),nbx,1,fg);
		return;
		}

	bgfg[0] = bg; bgfg[1] = fg;

	ww = 	(XGC.width*XGC.pixelsize);

	ClipColumn( atx, nbx, adjust, "putch" );
	ClipRow(aty,nby, "putch" );	

	if (!( softout ))
		w   = XGC.imageptr->bytes_per_line; 
	else	w   = ww;

	if ( XGC.mapping ) {

		/* Colour Mapped Version */
		/* --------------------- */
		switch ( XGC.visbpp ) {
			case	8 :
				for (y=0; y < nby; y++ ) {
					if (!( softout ))
						pptr = (XGC.storage + ((aty+(y+ty))*w) + (atx+tx));
					qptr = (XGC.shadow  + ((aty+y)*ww) + atx);
					for (x=0; x < nbx; x++ ){
						*(qptr++) = bgfg[(v = *(sptr+x))];
						if (!( softout )) {
							 *(pptr++) = bRgbTable[bgfg[v]];
							}
						}
					sptr += (nbx+adjust);
					}
				break;
			case	16 :
				for (y=0; y < nby; y++ ) {
					if (!( softout ))
						pptr = (XGC.storage + ((aty+(y+ty))*w) + ((atx+tx)*2));
					qptr = (XGC.shadow  + ((aty+y)*ww) + atx);
					for (x=0; x < nbx; x++ ) {
						*(qptr++) = bgfg[(v = *(sptr+x))];
						if (!( softout )) {
							 v = bgfg[(v & 0x00FF)];
							 v = wRgbTable[(v & 0x00FF)];
							*(pptr++) = (v & 0x00FF);
							*(pptr++) = ((v & 0xFF00)>>8);
							}
						}
						sptr += (nbx+adjust);
					}
				break;
			case	32 :
				for (y=0; y < nby; y++ ) {
					if (!( softout ))
						pptr = (XGC.storage + ((aty+(y+ty))*w) + ((atx+tx)*4));
					qptr = (XGC.shadow  + ((aty+y)*ww) + atx);
					for (x=0; x < nbx; x++ ) {
						*(qptr++) = bgfg[(v = *(sptr+x))];
						if (!( softout )) {
							 v = bgfg[(v & 0x00FF)];
							 l = lRgbTable[(v & 0x00FF)];
							*(pptr++) = (char)(l & 0x00FF);
							*(pptr++) = (char)((l & 0xFF00)>>8);
							*(pptr++) = (char)((l & 0xFF0000)>>16);
							*(pptr++) = 0;
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
		/* Or will be */
		switch ( XGC.visbpp ) {
			case	8 :
				for (y=0; y < nby; y++ ) {
					if (!( softout ))
						pptr = (XGC.storage + ((aty+y+ty)*w) + (atx+tx));
					qptr = (XGC.shadow  + ((aty+y)*ww) + atx);
					for (x=0; x < nbx; x++ ){
						v = bRgbTable[bgfg[*(sptr+x)]];
						if (!( softout ))
							 *(pptr++) = v;
						*(qptr++) = v; 
						}
					sptr += (nbx+adjust);
					}
				break;
			case	16 :
				for (y=0; y < nby; y++ ) {
					if (!( softout ))
						pptr = (XGC.storage + ((aty+y+ty)*w) + ((atx+tx)*2));
					qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*2));
					for (x=0; x < nbx; x++ ) {
						s = wRgbTable[bgfg[*(sptr+x)]];
						if (!( softout )) {
							*(pptr++) = (s & 0x00FF);
							*(pptr++) = ((s & 0xFF00)>>8);
							}
						*(qptr++) = (s & 0x00FF);
						*(qptr++) = ((s & 0xFF00)>>8);
						}
					sptr += (nbx+adjust);
					}
				break;
			case	32 :
				for (y=0; y < nby; y++ ) {
					if (!( softout ))
						pptr = (XGC.storage + ((aty+y+ty)*w) + ((atx+tx)*4));
					qptr = (XGC.shadow  + ((aty+y)*ww) + (atx*4));
					for (x=0; x < nbx; x++ ) {
						l = lRgbTable[bgfg[*(sptr+x)]];
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
					sptr += (nbx+adjust);
					}
				break;
			}
		}

	if ( atribut & _GIGO_HIGHLIGHT )
		mixcharacter(atx+1,aty, nbx, nby,optr,fg,0 );

	if ( atribut & _GIGO_UNDERLINE ) {
 		if ( nby > 8 )
			filzone(atx,aty+(nby-4),nbx,1,fg);
		else	filzone(atx,aty+(nby-1),nbx,1,fg);
		}

	if ( atribut & _GIGO_OVERLINE )
		filzone(atx,aty,nbx,1,fg);

	if ( atribut & _GIGO_STRIKE )
		filzone(atx,(aty+((nby/2)-1)),nbx,1,fg);

	if (!( softout )) {
		outzone(atx+tx,aty+ty,nbx,nby);
		}

	return;
}

#endif	/* _putch */


