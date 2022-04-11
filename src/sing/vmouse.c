
#include "guimouse.h"
#ifndef	public
#define	public
#endif
public 	void	initialise_mouse()
{
	use_new_mimo();
	init_mimo();
	activate_mimo();
	set_mimo_mask((
		_MIMO_ALT	 |
		_MIMO_WHILE_DOWN |
		_MIMO_DOWN 	 |
		_MIMO_UP 	 |
		_MIMO_SEND_RIGHT |
		_MIMO_SEND_LEFT  | 
		_MIMO_SEND_WHEEL 	   ));
	return;
}

public 	void	terminate_mouse()
{
	inhibit_mimo();
	fin_mimo();
	return;
}

#ifdef	WIN32
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
#endif

