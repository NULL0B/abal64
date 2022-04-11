#include "wdef.h"
#include "zglobal.h"
#include "mouse.h"

VOID	disable_mouse_move()	{	return; 	}
VOID	enable_mouse_move()	{	return;		}
VOID	calibrate_mouse()	{	return;		}
VOID	zzshowmouse()		{	return;		}
VOID	zzhidemouse()		{	return;		}

SWORD zzinitmouse(PTRC string)
{
	init_mimo();
   return(0);
}

VOID  zzendmouse()
{
	fin_mimo();
}

