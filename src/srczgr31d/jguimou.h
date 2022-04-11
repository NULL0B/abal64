//VAP HEADER
#ifndef	JGUIMOUSE_H
#define	JGUIMOUSE_H

#ifdef	BDA_TWIN16 //fucking_v0_Linux
extern int	SpriteIsVisible;
extern int	SpriteColumn;
extern int	SpriteRow;
extern int	SpriteMask;
extern int	SpriteWidth;
extern int	SpriteHeight;
extern int	SpriteBufferWidth;
extern int	SpriteBufferHeight;
int		hidemouse();
int		mouseover( int tx, int ty, int nx , int ny );
void	mousecurser( unsigned char * iptr );
void	showmouse();
void	movemouse(int c, int l);
#endif // fucking_v0_Linux

void	calibrate_mouse( int fbw, int fbh );
void	initialise_mouse();
void	terminate_mouse();
void  disable_mouse_move();
void  enable_mouse_move();


#define	_MIMO_LEFT 	1
#define	_MIMO_RIGHT	2

#define _MIMO_KEYBOARD	  0x0002

#define _MIMO_DOWN		    0x0010
#define _MIMO_UP		      0x0020

#define _MIMO_CLICK		    0x0040
#define _MIMO_DOUBLE		  0x0080

#define _MIMO_MOVE		    0x0100
#define _MIMO_WHILE_DOWN	0x0200

#define _MIMO_SEND_LEFT 	0x1000
#define _MIMO_SEND_RIGHT	0x2000
#define _MIMO_IS_DOWN		  0x4000

int		init_mimo();
int		flush_mimo();
int		activate_mimo();
int		set_mimo_mask(int);
int		get_mimo_mask();
void	mimo_move();
void	mimo_nomove();
int		mimo_kbhit();
int		mimo_getch();
int		get_mimo_lin();
int		get_mimo_col();
int		get_mimo_type();
int		get_mimo_par();
void	inhibit_mimo();
void	fin_mimo();

void  use_new_mimo();
void  use_old_mimo();

#endif	

