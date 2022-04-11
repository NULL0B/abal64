#ifndef	_pixel_h
#define	_pixel_h

#include "xpixel.h"


#define	MAX_FONTS	256	/* enough for now I think     */

extern	struct graphical_context XGC;
extern	int			 Verbose;
extern	unsigned char 		 bRgbTable[256];
extern	unsigned short 		 wRgbTable[256];
extern	unsigned long 		 lRgbTable[256];

#include "pixtrace.h"

#endif	/* _pixel_h */

