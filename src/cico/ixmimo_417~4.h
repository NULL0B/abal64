#define	_X_BUTTON_1		1
#define	_X_BUTTON_2		2
#define	_X_BUTTON_3		3
#define	_X_BUTTON_OFF		4
#define	_X_MOVING		5

#define	_MIMO_NO_EVENT		0x0000

#define	_MIMO_INTERRUPT		0x0001

#define	_MIMO_KEYBOARD		0x0002

#define	_MIMO_DOWN		0x0010
#define	_MIMO_UP		0x0020
#define	_MIMO_CLICK		0x0040
#define	_MIMO_DOUBLE		0x0080
#define	_MIMO_MOVE		0x0100
#define	_MIMO_WHILE_DOWN	0x0200
#define	_MIMO_IS_DOWN		0x0400
#define	_MIMO_SEND_LEFT		0x1000
#define	_MIMO_SEND_RIGHT	0x2000
#define	_MIMO_SEND_MIDDLE	0x4000

/* #BG 18/03/13 Non conforme a la doc EVENT(2) mais ne pas changer pour compatibilite existant! */
#define	_MIMO_LEFT 		0x0001
#define	_MIMO_RIGHT		0x0002
#define	_MIMO_MIDDLE		0x0004

#define	_MIMO_BUTTONS	_MIMO_SEND_LEFT | _MIMO_SEND_RIGHT | _MIMO_SEND_MIDDLE





