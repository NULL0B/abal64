#ifndef	_standard_image
#define	_standard_image

#include "stdpsu.h"

struct	standard_image {
	int		rows;
	int		columns;
	STDPSUPTR	storage;
	int 		users;
	};

#endif	/* _standard_image */


