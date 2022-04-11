#include <stdio.h>
#include "sing.h"
#include "palet.h"
#include "stdpsu.h"
#include "guimouse.h"
#include "singrel.h"
#include "singpix.h"
#include "allocate.h"
#define	_SYSTEM_IMAGES
#include "sysimage.h"
#include "stdimage.h"
#include "singlang.h"
#include "singedit.h"
#include "singprod.h"
#include "singpars.h"

#include "singpal.h"
#include "singbar.h"
#include "singmenu.h"
#include "singtool.h"
#include "singtext.h"
#include "singimg.h"
#include "singdesk.h"

#include "vconf.h"
#include "visual.h"
#include "singconf.h"

extern	char	namebuffer[];
extern	char	workbuffer[];
extern	struct	screen_control	Context;
extern	char *	font_name[];
extern	int	TargetBiosMode;
extern	int	WindowCol;
extern	int	WindowRow;
extern	int	ZeroWindow;	


#define	_STANDARD_RGB	system_palette

#define	_NATURE_PROGRAM	0
#define	_NATURE_OVERLAY	1
#define	_NATURE_MODULE 	2
#define	_NATURE_INCLUDE 3


#include "singc.c"

