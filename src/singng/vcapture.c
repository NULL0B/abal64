#ifndef	_vcapture_c
#define	_vcapture_c

#include <stdio.h>
#include <string.h>

#ifndef WIN32
#include "singprot.h"
#endif
 
#include "allocate.h"
#define	_SYSTEM_IMAGES
#include "sysimage.h"
#include "stdimage.h"

#include "genimage.c"

public	int	visual_screen_capture(char * nptr, int mode)
{
	char *	get_vga_palette();
	char *	tempname=(char *) 0;
	int	r=0;
	char *	bptr;
	struct standard_image * iptr;
	int	gwidth=x_conf(69);
	int	gheight=x_conf(68);
	int	pixelsize=x_conf(67);
	int	mapping=x_conf(70);
	char *	pptr;
	int	transparence=0;

	image_configuration(mapping, pixelsize, get_vga_palette() );

	if (!(iptr = local_allocate_image(gwidth,gheight,0,1) ))
		return(27);

	else	{
		for (	r=0; r < gheight; r++ ) {
			if (!( bptr = connect_pixel_row(iptr->storage,r) ))
				break;
			else	getzone(0,r,gwidth,1,bptr);
			}
		if ( *nptr == '!' ) {
			nptr++;
			transparence=1;
			}
		image_write(nptr, iptr ,mode, transparence);
		local_drop_image( iptr );
		return(0);
		}

}

#endif	/* _vcapture_c */
	/* ----------- */



