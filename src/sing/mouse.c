#ifndef	_MOUSE_C
#define	_MOUSE_C

#include "guimouse.h"

void	with_mouse_move()
{
	set_mimo_mask((
		_MIMO_ALT        |
		_MIMO_WHILE_DOWN |
		_MIMO_MOVE	 |
		_MIMO_DOWN 	 |
		_MIMO_UP 	 |
		_MIMO_CLICK	 |
		_MIMO_SEND_RIGHT |
		_MIMO_SEND_LEFT  |
		_MIMO_SEND_WHEEL 	   ));
	return;
}

void	without_mouse_move()
{
	set_mimo_mask((
		_MIMO_ALT        |
		_MIMO_WHILE_DOWN |
		_MIMO_DOWN 	 |
		_MIMO_UP 	 |
		_MIMO_CLICK	 |
		_MIMO_SEND_RIGHT |
		_MIMO_SEND_LEFT  |
		_MIMO_SEND_WHEEL 	   ));
	return;
}

void	initialise_mouse()
{
	use_new_mimo();
	init_mimo();
	activate_mimo();
	with_mouse_move();
	return;
}

void	terminate_mouse()
{
	inhibit_mimo();
	fin_mimo();
	return;
}

#endif	/* _MOUSE_C */

