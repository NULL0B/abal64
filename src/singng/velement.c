#ifndef	_velement_c
#define	_velement_c
#ifdef WIN32
#include "singprot.h"
#else
#include <stdio.h>
#include "allocate.h"
#define	private	static
#define	public	
#endif
#include "vimage.h"
#include "vstyle.h"
private	 int	ImageQuality=0;	
#include "vstylist.c"
#endif	/* _velement_c */


