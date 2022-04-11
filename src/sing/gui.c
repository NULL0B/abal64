#ifndef	_gui_c
#define _gui_c

#include "pixelgui.h"

int	gigo=-1;	// 	System is not Graphic System Does CICO

int 	initialise_for_gui( int mode )
{
	return((gigo = initialisepixel(mode) ));
}

void	liberate_for_gui( )
{
	if ( gigo != -1 ) {
		gigo = -1;
		liberatepixel();
		}
	return;
}

#endif





