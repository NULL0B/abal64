#ifndef	_zimage_c
#define	_z_image_c

#include <stdio.h>

#if defined(WIN32)
#include "bda.h"
#ifndef	BPTR
#define	BPTR PIXIBYTE FAR PTR
#endif
#ifndef	WPTR
#define	WPTR WORD FAR PTR
#endif
#ifndef	LPTR
#define	LPTR LONG FAR PTR
#endif
#include "stdimage.h"
#include "rgraphapi.h"
#endif

#include "zalloc.h"
#include "sysimage.h"
#include "stdfont.h"

#include "stdimage.c"
#include "sysimage.c"

#endif	/* _zimage_c */

