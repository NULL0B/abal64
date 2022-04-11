#ifndef	_sys_image_h
#define	_sys_image_h

#include "vimage.h"

#include "zgif.h"
#include "zpng.h"
#include "zico.h"
#include "zbmp.h"
#include "zjpeg.h"

#ifndef	_SYSTEM_IMAGES


#else

int	LoadImage(char *, char, void *);
int	CloneImage( void *);
int	DropImage(void *);
int	DropFont(void *);
int	LoadFont(char *, char, void *);

#endif


#endif

