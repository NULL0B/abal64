//VAP HEADER
#ifndef JMOUSE_H
#define JMOUSE_H

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

//
VOID zzshowmouse();
VOID zzhidemouse();
SWORD zzinitmouse(char FAR * string);
VOID	zzendmouse();
VOID zzstatusmouse(char FAR * string);

#endif
