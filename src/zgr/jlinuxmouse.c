#if defined(__linux__) || defined(UNIX)
#include "wdef.h"
#else
#if defined(BDA_ABAL2)
#include "wdef.h"
#else
#include "bda.h"
#endif
#endif

#include "zglobal.h"
#include "mouse.h"

VOID	disable_mouse_move()	{	return; 	}
VOID	enable_mouse_move()	{	return;		}
VOID	calibrate_mouse()	{	return;		}
VOID	zzshowmouse()		{	return;		}
VOID	zzhidemouse()		{	return;		}

SWORD zzinitmouse(char FAR * string)
{
	init_mimo();
   return(0);
}

VOID  zzendmouse()
{
	fin_mimo();
}

