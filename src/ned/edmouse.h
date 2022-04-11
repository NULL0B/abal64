#ifndef	_edmouse_h
#define	_edmouse_h

#include "guimouse.h"

#ifdef	UNIX
#ifdef	LINUX
#define get_mouse_line() 	x_event(3)
#define get_mouse_column() 	x_event(4)
#define get_mouse_button() 	x_event(2)
#define get_mouse_event()	x_event(1)
#else
#define get_mouse_line 		get_mimo_lin
#define get_mouse_column 	get_mimo_col
#define get_mouse_button  	get_mimo_par
#define get_mouse_event   	get_mimo_type
#endif
#endif

#endif /* _edmouse_h */

