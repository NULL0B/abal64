#ifndef	_movezone_c
#define	_movezone_c

#include "pixel.h"

private	void	moveright(int tox, int toy, int fromx, int fromy, int nbx, int nby )
{
	register int y;
	register int x;
		 int w;
		 int ww;
		 int p;
	register unsigned char * tptr;
	register unsigned char * sptr;
	register int pixelsize=XGC.pixelsize;
	register unsigned int ty=0;
	register unsigned int tx=0;

	w   = XGC.width;
	ww   = (XGC.width * pixelsize);
	for (y=0; y < nby; y++ ) {
		tptr = (XGC.shadow + ((toy+y)*ww) + (tox*pixelsize));
		sptr = (XGC.shadow + ((fromy+y)*ww)+(fromx*pixelsize));
		for ( x=1; x <= nbx; x++ ) {
			for ( p=0; p < pixelsize; p++ ) {
				*(tptr + ((nbx-x)*pixelsize)+p) = *(sptr+((nbx-x)*pixelsize)+p);
				}
			}
		}

	if (!( XGC.displayptr ))
		return;
	else if ( XGC.softoutput != (char *) 0) {
		if (!(tx = XGC.targetx ))
			return;
		else 	{
			tx--;
			ty = XGC.targety-1;
			}
		}

	w   = XGC.imageptr->bytes_per_line; 

	switch ( XGC.visbpp ) {
		case	8 :
			for (y=0; y < nby; y++ ) {
				tptr = (XGC.storage + ((toy+y+ty)*w) + (tox+tx));
				sptr = (XGC.storage + ((fromy+y+ty)*w)+(fromx+tx));
				for ( x=1; x <= nbx; x++ )
					*(tptr + (nbx-x)) = *(sptr+(nbx-x));
				}
			break;
		case	16 :
			for (y=0; y < nby; y++ ) {
				tptr = (XGC.storage + ((toy+y+ty)*w) + ((tox+tx)*2));
				sptr = (XGC.storage + ((fromy+y+ty)*w)+((fromx+tx)*2));
				for ( x=1; x <= nbx; x++ )
					memcpy((tptr + ((nbx-x)*2)) ,(sptr+((nbx-x)*2)), 2);
				}
			break;
		case	32 :
			for (y=0; y < nby; y++ ) {
				tptr = (XGC.storage + ((toy+y+ty)*w) + ((tox+tx)*4));
				sptr = (XGC.storage + ((fromy+y+ty)*w)+((fromx+tx)*4));
				for ( x=1; x <= nbx; x++ )
					memcpy((tptr + ((nbx-x)*4)) ,(sptr + ((nbx-x)*4)), 4);
				}
			break;
		}
	outzone(tox+tx,toy+ty,nbx,nby);
	return;
}

private	void	moveup(int tox, int toy, int fromx, int fromy, int nbx, int nby )
{
	register int y;
	int w;
		 int ww;
	register unsigned char * tptr;
	register unsigned char * sptr;
	register int pixelsize=XGC.pixelsize;
	register unsigned int ty=0;
	register unsigned int tx=0;

	w   = XGC.width;
	ww   = (XGC.width * pixelsize);

	for (y=0; y < nby; y++ ) {
		tptr = (XGC.shadow + ((toy+y)*ww) + (tox*pixelsize));
		sptr = (XGC.shadow + ((fromy+y)*ww)+(fromx*pixelsize));
		memcpy( tptr, sptr, (nbx*pixelsize) );
		}

	if (!( XGC.displayptr ))
		return;
	else if ( XGC.softoutput != (char *) 0) {
		if (!(tx = XGC.targetx ))
			return;
		else 	{
			tx--;
			ty = XGC.targety-1;
			}
		}

	w   = XGC.imageptr->bytes_per_line; 

	switch ( XGC.visbpp ) {
		case	8 :
			for (y=0; y < nby; y++ ) {
				tptr = (XGC.storage + ((toy+y+ty)*w) + (tox+tx));
				sptr = (XGC.storage + ((fromy+y+ty)*w)+(fromx+tx));
				memcpy( tptr, sptr, nbx );
				}
			break;
		case	16 :
			for (y=0; y < nby; y++ ) {
				tptr = (XGC.storage + ((toy+y+ty)*w) + ((tox+tx)*2));
				sptr = (XGC.storage + ((fromy+y+ty)*w)+((fromx+tx)*2));
				memcpy( tptr, sptr, (nbx*2) );
				}
			break;
		case	32 :
			for (y=0; y < nby; y++ ) {
				tptr = (XGC.storage + ((toy+y+ty)*w) + ((tox+tx)*4));
				sptr = (XGC.storage + ((fromy+y+ty)*w)+((fromx+tx)*4));
				memcpy( tptr, sptr, (nbx*4) );
				}
			break;
		}
	outzone(tox+tx,toy+ty,nbx,nby);
	return;
}

private	void	movedown(int tox, int toy, int fromx, int fromy, int nbx, int nby )
{
	register int y;
	int w;
		 int ww;
	register unsigned char * tptr;
	register unsigned char * sptr;
	register int pixelsize=XGC.pixelsize;
	register unsigned int ty=0;
	register unsigned int tx=0;

	w   = XGC.width;
	ww   = (XGC.width * pixelsize);

	for (y=nby-1; y >= 0 ; y-- ) {
		tptr = (XGC.shadow + ((toy+y)*ww) + (tox*pixelsize));
		sptr = (XGC.shadow + ((fromy+y)*ww)+(fromx*pixelsize));
		memcpy( tptr, sptr, (nbx*pixelsize) );
		}

	if (!( XGC.displayptr ))
		return;
	else if ( XGC.softoutput != (char *) 0) {
		if (!(tx = XGC.targetx ))
			return;
		else 	{
			tx--;
			ty = XGC.targety-1;
			}
		}

	w   = XGC.imageptr->bytes_per_line; 

	switch ( XGC.visbpp ) {
		case	8 :
			for (y=nby-1; y >= 0 ; y-- ) {
				tptr = (XGC.storage + ((toy+(y-1)+ty)*w) + (tox+tx));
				sptr = (XGC.storage + ((fromy+(y-1)+ty)*w)+(fromx+tx));
				memcpy( tptr, sptr, nbx );
				}
			break;
		case	16 :
			for (y=nby-1; y >= 0 ; y-- ) {
				tptr = (XGC.storage + ((toy+(y-1)+ty)*w) + ((tox+tx)*2));
				sptr = (XGC.storage + ((fromy+(y-1)+ty)*w)+((fromx+tx)*2));
				memcpy( tptr, sptr, (nbx*2) );
				}
			break;
		case	32 :
			for (y=nby-1; y >= 0 ; y-- ) {
				tptr = (XGC.storage + ((toy+(y-1)+ty)*w) + ((tox+tx)*4));
				sptr = (XGC.storage + ((fromy+(y-1)+ty)*w)+((fromx+tx)*4));
				memcpy( tptr, sptr, (nbx*4) );
				}
			break;
		}
	outzone(tox+tx,toy+ty,nbx,nby);
	return;
}

public	void	movezone(int tox, int toy, int fromx, int fromy, int nbx, int nby )
{
/*	printf("movezone to(%u,%u) from(%u,%u) size(%u,%u)\r\n",tox,toy,fromx,fromy,nbx,nby);	*/
	if ( toy < fromy )
		moveup(tox,toy,fromx,fromy,nbx,nby );
	else if ( toy > fromy )
		movedown(tox,toy,fromx,fromy,nbx,nby );
	else if ( tox > fromx )
		moveright(tox,toy,fromx,fromy,nbx,nby );
	else	moveup(tox,toy,fromx,fromy,nbx,nby );
	return;
}

#endif	/* _movezone_c */



