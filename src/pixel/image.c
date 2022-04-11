#ifndef	_image_c
#define	_image_c

#ifdef WIN32
#include "pixel.h"
#endif

#include "zjpeg.h"
#include "vimage.h"
#include "valign.h"
#include "vmakefit.c"

private	void	llimage(	int atx, int aty, int tw, int th,
			struct standard_image * iptr, int options )
{
	int			r;
	int			p;
	int			sw;
	int			sh;
	int			nc,np;
	int			nl,nr;
	char	*		rptr;

	if ((!( tw  ))
	||  (!( th  ))) {
		return;
		}

	if ((!( iptr ))
	||  (!( iptr->storage ))) {
		if (!( options & _I_HIDE )) {
		 for (	p=1,r=0; r < th; r++,p++ ) filzone(atx,aty+r,tw,1,p);
		}
		}
	else	{
		if ( iptr->palette ) {
			vgapalette(iptr->palette,0,256);
			}
		/* calculate alignments and repetitions */
		/* ------------------------------------ */
		if (( options & 7 ) == _I_TILE ) {
			sh=(th>iptr->rows?iptr->rows:th);
			sw=(tw>iptr->columns?iptr->columns:tw);
			}
		else if (( options & 7 ) == _I_MAKEFIT ) {
			imakefit(atx,  aty,  tw,  th,iptr,( _I_MAKEFIT | (options & _I_SPRITE )) );
			if ( iptr->palette )
				put_palette();
			return;
			}
		else if (( options & 7 ) == _I_BESTFIT ) {
			ibestfit(atx,  aty,  tw,  th,iptr,( _I_BESTFIT  | (options & _I_SPRITE )));
			if ( iptr->palette )
				put_palette();
			return;
			}
		else	{
			/* horizontaltical alignment */
			/* ------------------------- */
			switch ( options & 3 ) {
				case	_A_NONE    : 
				case	_A_LEFT    : 
					sw=(tw>iptr->columns?iptr->columns:tw);
					break;
	
				case	_A_RIGHT   : 
					if ((sw = iptr->columns ) < tw) 
						atx += 	(tw-sw);
					else	sw = tw;
					break;					
	
				case	_A_CENTER  :
					if ((sw = iptr->columns ) < tw) 
						atx += 	((tw-sw)/2);
					else	sw = tw;
					break;
				}

			/* vertical alignment */
			/* ------------------ */
			if ( options & _A_TOP )
				sh=(th>iptr->rows?iptr->rows:th);

			else if ( options & _A_BOTTOM ) {
				if ((sh = iptr->rows ) < th) 
					aty += 	(th - sh);
				else	sh = th;
				}
			else 	{
				if ((sh = iptr->rows ) < th) 
					aty += 	((th - sh)/2);
				else	sh = th;
				}
			tw = sw; th = sh;
			}
		nl = 0;
		while ( nl < th ) {
			nr = ( sh < (th - nl) ? sh : (th - nl));
			for (	r=0; r < nr; r++ ) {
				if (!(rptr = connect_pixel_row(iptr->storage,r)))
					break;
				else	{
					nc=0;
					if (!( iptr->format )) {
						while ( nc < tw ) {
							if (!( np = (sw < (tw - nc) ? sw : (tw - nc) ) ))
								break;
							else if ( options & _I_SPRITE )
								mixzone8(atx+nc,aty+nl+r,np,1,rptr);
							else	putzone8(atx+nc,aty+nl+r,np,1,rptr);
							nc += np;
							}
						}
					else	{
						while ( nc < tw ) {
							if (!( np = (sw < (tw - nc) ? sw : (tw - nc) ) ))
								break;
							else if ( options & _I_SPRITE )
								mixzone(atx+nc,aty+nl+r,np,1,rptr);
							else	putzone(atx+nc,aty+nl+r,np,1,rptr);
							nc += np;
							}

						}
					}
				}
			nl += r;
			}
		}
	if ( iptr )
		if ( iptr->palette )
			put_palette();
	return;
}

public	void	drawimage(
	int atx, int aty, int tw, int th,
	struct standard_image * iptr, int options )
{
	hide();
	llimage(atx,aty,tw,th,iptr,options);
	show(atx,aty,tw,th);
	return;
}

#endif	/* _image_c */
	/* -------- */

