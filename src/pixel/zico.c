#ifndef	_standard_ico_c
#define	_standard_ico_c

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
#include "vimage.h"

/*		--------------------------		*/
/*		Window ICon File Structure		*/
/*		--------------------------		*/
/*							*/
/*		Just for the record			*/
/*							*/
/*	struct	ico_file	{			*/
/*							*/
/*		char	signature[6];			*/
/*		char	columns;			*/
/*		char	rows;				*/
/*		int	colours;			*/
/*		char	rgb[16][3];			*/
/*		char	nowt$=68			*/
/*		char	pixels[32][16];			*/
/*							*/
/*		};					*/
/*							*/
/*		--------------------------		*/


struct	standard_image * ico_loader( char * nptr )
{
	FILE * h;
	char *	bptr;
	char *	dptr;
	char *	buffer;
	struct	standard_image * iptr=(struct	standard_image *)0;
	int	c;
	int	r;
	int	v;
	int	nbp;
	int	nbc;
	int	nbr;
	int	palette[16];

	if ((buffer = allocate( 768 )) != (char *) 0) {
		if ((h = fopen( nptr, "rb" )) != (FILE*) 0) {
			fread(buffer,768,1,h);
			fclose(h);
			if (!(nbc = *(buffer + 6))) nbc = 32;
			if (!(nbr = *(buffer + 7))) nbr = 32;
			nbp = (*(buffer + 8) | (*(buffer + 9) << 8));
			if (!( nbp )) nbp = 16;

			if ((iptr = local_allocate_image( nbc,nbr,0,0)) != (struct standard_image *) 0) {

				iptr->storage->descriptor[6] = 1;

				for ( r=0; r < nbp; r++ )
					palette[r] = r;
				palette[1]  = 4; palette[4]  =  1;
				palette[3]  = 6; palette[6]  =  3;
				palette[9]  =12; palette[12] =  9;
				palette[11] =14; palette[14] = 11;

				for ( r=0; r < nbr; r++ ) {
					dptr = (buffer + (10+(nbp*3)+68) + (r*(nbc/2))); 
					if (!( bptr = connect_pixel_row( iptr->storage,(nbr-(r+1)) ) ))
						break;
					for ( c=0; c < nbc; c += 2 ) {
						v = ((*dptr++) & 0x00FF);
						*(bptr+c)   = palette[((v & 0x00F0) >> 4)];
						*(bptr+c+1) = palette[(v & 0x000F)];
						}
					}
				}
			}
		liberate( buffer );
		}
	return( iptr );
}

#endif	/* _standard_ico_c */
	/* --------------- */

