#ifndef	_GWB_MOUSE_C
#define	_GWB_MOUSE_C

#include "guimouse.h"

void	editor_mouse_mask(int v)
{
#ifdef	LINUX
	x_putch(27); x_putch('Z');
	x_putch((v & 0x00FF));
	x_putch(((v >> 8) & 0x00FF));
#else
	set_mimo_mask(v);
#endif
	return;
}

void	initialise_editor_mouse()
{
	int	v;
#ifndef	NOGIGO
	use_new_mimo();
	init_mimo();
#endif
#ifdef	LINUX
	if ( x_event(0) == 0 ) 
		editor_mouse_mask(
			_MIMO_WHILE_DOWN |
			_MIMO_DOWN 	 |
			_MIMO_UP 	 |
			_MIMO_CLICK	 |
			_MIMO_SEND_RIGHT |
			_MIMO_SEND_LEFT  |
			_MIMO_SEND_WHEEL );   
#else
	activate_mimo();
	set_mimo_mask((
		_MIMO_WHILE_DOWN |
		_MIMO_DOWN 	 |
		_MIMO_UP 	 |
		_MIMO_CLICK	 |
		_MIMO_SEND_RIGHT |
		_MIMO_SEND_LEFT   	   ));
#endif
	return;
}

void	terminate_editor_mouse()
{
#ifndef	NOGIGO
	inhibit_mimo();
	fin_mimo();
#endif
	return;
}

#endif	/* _GWB_MOUSE_C */

