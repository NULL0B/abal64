#ifndef	_relief_c
#define _relief_c

#include "pixel.h"
#include "palet.h"

void	relief_box( int atx, int aty, int nbx, int nby, int size )
{


	hide();
	filzone(atx,aty,nbx,size,_DEFAULT_GUI_LIGHT_HIGH );
	filzone(atx,aty,size,nby,_DEFAULT_GUI_LIGHT_HIGH );
	filzone(atx+size,aty+size,nbx-(size*2),nby-(size*2),_DEFAULT_GUI_NEUTRAL);
	filzone(atx+nbx-size,aty,size,nby,_DEFAULT_GUI_DARK_LOW );
	filzone(atx,aty+nby-size,nbx,size,_DEFAULT_GUI_DARK_LOW );
	show(atx,aty,nbx,nby);
	return;
}

#endif /* _relief_c */

