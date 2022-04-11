#ifndef	_getzone_c
#define	_getzone_c

#include "pixel.h"

void	getzone(unsigned int atx, unsigned int aty, unsigned int nbx, unsigned int nby, char * rptr )
{
	int	xtx=0;
	register unsigned int y;
	ClipColumn( atx,nbx,xtx, "getzone" );
	ClipRow( aty,nby, "getzone" );

	for (y=0; y < nby; y++ ) {
		memcpy(rptr, (XGC.shadow  + ((aty+y)*(XGC.width*XGC.pixelsize)) + (atx*XGC.pixelsize)), (nbx*XGC.pixelsize));
		rptr += ((nbx+xtx) * XGC.pixelsize);
		}
	return;
}

#endif	/* _getzone */


