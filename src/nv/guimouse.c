#ifndef	_guimouse_c
#define	_guimouse_c

#include "guimouse.h"

static		int	SpriteIsVisible=0;
static		int	SpriteColumn=-1;
static		int	SpriteRow=-1;
static		int	SpriteMask=-1;
static		int	SpriteWidth=10;
static		int	SpriteHeight=10;
static		int	SpriteBufferWidth=0;
static		int	SpriteBufferHeight=0;

static	unsigned char 	SpriteZone[10][10];

static	unsigned char 	SpriteForm[10][10] = {
	16,16,16,16,16,16,16,16, 0, 0,
	16,15,15,15,15,15,16, 0, 0, 0,
	16,15,15,15,15,16, 0, 0, 0, 0,
	16,15,15,15,15,15,16, 0, 0, 0,
	16,15,15,15,15,15,15,16, 0, 0,
	16,15,16,15,15,15,15,15,16, 0,
	16,16, 0,16,15,15,15,15,15,16,
	16, 0, 0, 0,16,15,15,15,16, 0,
	 0, 0, 0, 0, 0,16,15,16, 0, 0,
	 0, 0, 0, 0, 0, 0,16, 0, 0, 0
	};

static	unsigned char *	SpritePointer=SpriteForm;

int	hidemouse() 
{
	if ( SpriteIsVisible ) {
		putzone(SpriteColumn, SpriteRow, SpriteWidth,SpriteHeight,SpriteZone);
		SpriteIsVisible = 0;
		return(1);
		}
	else	return(0);
}

int	mouseover( int tx, int ty, int nx , int ny )
{
	if (!( SpriteIsVisible ))
		return(0);
	else if ( SpriteColumn > (tx + nx))
		return(0);
	else if (( SpriteColumn + SpriteWidth) < tx)
		return(0);
	else if ( SpriteRow > (ty + ny))
		return(0);
	else if (( SpriteRow + SpriteHeight) < ty)
		return(0);
	else	return(1);
}

void	mousecurser( unsigned char * iptr )
{
	if (!(SpritePointer = iptr ))
		SpritePointer = SpriteForm;
	return;
}


void	showmouse()
{
	if (!( SpriteIsVisible )) {
		getzone(SpriteColumn, SpriteRow, SpriteWidth,SpriteHeight,SpriteZone);
		mixzone(SpriteColumn, SpriteRow, SpriteWidth,SpriteHeight,SpritePointer);
		SpriteIsVisible = 1;
		}
	return;
}

void	calibrate_mouse( int fbw, int fbh )
{
	SpriteBufferWidth = fbw;
	SpriteBufferHeight= fbh;
	return;
}

void	movemouse(int c, int l)
{
	int mode;
	mode = hidemouse();
	c--; l--;
	SpriteColumn  = (int) (( ((long) c) * SpriteBufferWidth) / 140);
	SpriteRow     = (int) (( ((long) l) * SpriteBufferHeight) / 140);
	if ( mode )
		showmouse();
	return;
}

void	initialise_mouse()
{
	init_mimo();
	activate_mimo();
	SpriteMask = get_mimo_mask();
	set_mimo_mask((
		_MIMO_WHILE_DOWN |
		_MIMO_MOVE 	 |
		_MIMO_DOWN 	 |
		_MIMO_UP 	 |
		_MIMO_SEND_RIGHT |
		_MIMO_SEND_LEFT   	   ));
	mimo_move();
	SpriteColumn = SpriteRow = -1;	
	SpriteIsVisible = 0;
	return;
}

void	terminate_mouse()
{
	(void) hidemouse();
	mimo_nomove();
	set_mimo_mask(SpriteMask);
	inhibit_mimo();
	fin_mimo();
	return;
}


#endif	/* _guimouse_c */

