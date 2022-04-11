#ifndef	_z_image_h
#define	_z_image_h

#include "stdpsu.h"

struct	standard_image {
	int		rows;
	int		columns;
	STDPSUPTR	storage;
	int 		users;
	};

struct standard_image * image_loader( char * );
struct standard_image * resolve_image(char *,int);
struct standard_image * drop_image( struct standard_image * );
			
#endif	/* _z_image */


