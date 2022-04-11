#ifndef	_varrow_c
#define	_varrow_c

#include "varrow.h"

public	int	visual_focus( int atx, int aty, int nbx, int nby )
{
	int	y;
	for (	y=0; y < (nby/2); y += 2) {
		filzone(atx+(nbx/4),aty+(nby/4)+y,nbx/2,1,standard_himid);
		filzone(atx+(nbx/4),aty+(nby/4)+y+1,nbx/2,1,standard_lomid);
		}
	return(0);
}

public	int	visual_arrow( int atx, int aty, int nbx, int nby, int dath, int style )
{
	int	h;
	int	w;
	int	n;
	int	y;
	int	x;

	if (!(w = (nbx - (nbx/4)))) return(0);
	if (!(h = (nby - (nby/4)))) return(0);

	if ( h > w ) 
		h = w;
	else	w = h;

	switch ( style ) {
		case	_ARROW_FOCUS	:
			visual_focus(atx,aty,nbx,nby);
			break;

		case	_ARROW_TOP	:
			if (!( w & 1 )) w++;
			y=((nby-(w/2))/2)-1;
			filzone(atx+1,aty+y,w,1,dath);
			for (	n=1,x=((nbx/2)-1);
				n <= w;
				n += 2,y++,x-- )
				filzone(atx+x,aty+y,n,1,dath);
				
			break;

		case	_ARROW_UP	:
			if (!( w & 1 )) w++;
			for (	y=((nby-(w/2))/2)-1,n=1,x=((nbx/2)-1);
				n <= w;
				n += 2,y++,x-- )
				filzone(atx+x,aty+y,n,1,dath);
			break;

		case	_ARROW_DOWN	:
			if (!( w & 1 )) w++;
			for (	y=((nby-(w/2))/2),n=w,x=((nbx-w)/2);
				n >=1;
				n -= 2,y++,x++ )
				filzone(atx+x,aty+y,n,1,dath);
			break;

		case	_ARROW_BOTTOM	:
			if (!( w & 1 )) w++;
			for (	y=((nby-(w/2))/2),n=w,x=((nbx-w)/2);
				n >=1;
				n -= 2,y++,x++ )
				filzone(atx+x,aty+y,n,1,dath);
			filzone(atx+1,aty+(y-1),w,1,dath);
			break;

		case	_ARROW_RIGHT	:
			if (!( h & 1 )) h++;
			for (	y=((nby-h)/2),n=h,x=((nbx-(h/2))/2);
				n >= 1;
				n -= 2,y++,x++ )
				filzone(atx+x,aty+y,1,n,dath);
			break;


		case	_ARROW_LEFT	:
			if (!( h & 1 )) h++;
			for (	y=((nby/2)-1),n=1,x=((nbx-(h/2))/2)-1;
				n <= h;
				n += 2,y--,x++ )
				filzone(atx+x,aty+y,1,n,dath);
			break;

		case	_ARROW_HSLIDE	:
		case	_ARROW_VSLIDE	:
			break;

		}
	return(0);

}



#endif 	_varrow_c


