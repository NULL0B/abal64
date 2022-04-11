#ifndef	_guimouse_h
#define	_guimouse_h

#define	_MIMO_LEFT 	 1
#define	_MIMO_RIGHT	 2
#define	_MIMO_MIDDLE	 4
#define	_MIMO_WHEELUP	 8
#define	_MIMO_WHEELDOWN	16

#define	_MIMO_MASK	_MIMO_WHILE_DOWN | _MIMO_DOWN |_MIMO_UP  | _MIMO_CLICK | _MIMO_SEND_RIGHT | _MIMO_SEND_LEFT 

#define _MIMO_INTERRUPT		0x0001
#define _MIMO_KEYBOARD		0x0002
#define _MIMO_SIGNAL		0x0004

#define _MIMO_DOWN		0x0010
#define _MIMO_UP		0x0020
#define _MIMO_CLICK		0x0040
#define _MIMO_DOUBLE		0x0080

#define _MIMO_MOVE		0x0100
#define _MIMO_WHILE_DOWN	0x0200
#define _MIMO_IS_DOWN		0x0400
#define _MIMO_ALT		0x0800

#define _MIMO_SEND_LEFT 	0x1000
#define _MIMO_SEND_RIGHT	0x2000
#define _MIMO_SEND_MIDDLE	0x4000
#define _MIMO_SEND_WHEEL 	0x8000

#define	_MIMO_BUTTONS	_MIMO_SEND_LEFT | _MIMO_SEND_RIGHT | _MIMO_SEND_MIDDLE

#define	_MOUSE_EVENTS		0x0FFF

#ifndef	_stdmimo_c
int	init_mimo();
int	activate_mimo();
int	set_mimo_mask(int);
int	get_mimo_mask();
void	mimo_move();
void	mimo_nomove();
int	mimo_kbhit();
int	mimo_getch();
int	get_mimo_lin();
int	get_mimo_col();
int	get_mimo_type();
int	get_mimo_par();
int	inhibit_mimo();
int	fin_mimo();
#endif
#endif	/* _guimouse_h */

