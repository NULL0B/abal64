#ifndef	_rounded_c
#define	_rounded_c

#include "pixel.h"

void rounded_frame( unsigned int x, unsigned int y, unsigned int w, unsigned int h, int pixel)
{
	int	cpt = (XGC.scale) ? XGC.scale : 1;
	int	v;
	v = ( w > h ? h : w );
	v /= 8;
	if (!( v )) {
		filzone (x,y,w,h,pixel); 
		}
	else	{
		filzone   (x+(v/2), y       , (w-v)+1, cpt    , pixel);
		filzone   (x      , y+(v/2) , cpt    , (h-v)+1, pixel);
		filzone   (x+w-cpt, y+(v/2) , cpt    , (h-v)+1, pixel);
		filzone   (x+(v/2), y+h-cpt , (w-v)+1, cpt    , pixel);
		drawcircle(x      , y       , v      , v      , pixel, 4);
		drawcircle(x+(w-v), y       , v      , v      , pixel, 5);
		drawcircle(x,       y+(h-v) , v      , v      , pixel, 6);
		drawcircle(x+(w-v), y+(h-v) , v      , v      , pixel, 7);
		}
	return;
}

void rounded_filzone( unsigned int x, unsigned int y, unsigned int w, unsigned int h, int pixel)
{
	int	v;
	v = ( w > h ? h : w );
	v /= 8;
	if (!( v )) {
		filzone (x,y,w,h,pixel); 
		}
	else	{
		filzone   (x+(v/2), y      , (w-v),h    , pixel);
		filzone   (x      , y+(v/2), w    ,(h-v), pixel);
		drawcircle(x      , y      , v    ,v    , pixel,8);
		drawcircle(x+(w-v), y      , v    ,v    , pixel,9);
		drawcircle(x      , y+(h-v), v    ,v    , pixel,10);
		drawcircle(x+(w-v), y+(h-v), v    ,v    , pixel,11);
		}
	return;
}

#endif	/* _rounded_c */


