#ifndef	_GWB_MOUSE_C
#define	_GWB_MOUSE_C

#include "guimouse.h"

void	initialise_mouse()
{
	use_new_mimo();
	init_mimo();
	activate_mimo();
	set_mimo_mask((
		_MIMO_WHILE_DOWN |
		_MIMO_MOVE	 |
		_MIMO_DOWN 	 |
		_MIMO_UP 	 |
		_MIMO_CLICK	 |
		_MIMO_SEND_RIGHT |
		_MIMO_SEND_LEFT   	   ));
	return;
}

void	terminate_mouse()
{
	inhibit_mimo();
	fin_mimo();
	return;
}

#endif	/* _GWB_MOUSE_C */

