
#ifndef	_standard_png_c
#define _standard_png_c

#include <stdio.h>


#ifndef	NOPNG
#include <png.h>
#include "zpng.h"
static	png_color	ditherer[256];
#endif

#include "zalloc.h"
#include "vimage.h"

static	int		dithering=0;

extern	char * thispalette;
extern	int	colourmapping;
extern	int	pixelsize;

int	png_tester( char * bptr, int a, int b )
{
#ifdef	NOPNG
	return(0);
#else
	return(!png_sig_cmp( bptr, a, b ) );
#endif
}

struct standard_image * png_loader(char * nptr)
{
	FILE		       * h=(FILE*)0;
	struct	standard_image * iptr=(struct standard_image *) 0;
#ifdef	NOPNG
	return( iptr );
#else
	png_structp		 p=(png_structp) 0;
	png_infop		 i=(png_infop) 0;
	png_infop		 e=(png_infop) 0;
	int			 nbc,nbr;
	char		*	 pptr;
	char 		*	*rptr;
	int			 r,c;
	int			channels;
	int			rowbytes;
	int			colortype; 
	int			bitdepth;
	int			hiq;
	int			v,rv,gv,bv;
	char 		*	xbuffer=(char *) 0;

	hiq = get_image_quality();

	/* Attempt to open the file */
	/* ------------------------ */
	if (!( h = fopen( nptr, "rb" )))
		return(iptr);

	/* Attempt to allocate a control structure for reading */
	/* --------------------------------------------------- */
	else if (!(p = png_create_read_struct(
			PNG_LIBPNG_VER_STRING,
			(png_voidp)0,(png_voidp)0,
			(png_voidp)0 ))) {
		fclose(h);
		return(iptr);
		}

	/* Attempt to allocate a start info control structure */
	/* -------------------------------------------------- */
	else if (!(i = png_create_info_struct(p))) {
		png_destroy_read_struct(&p,(png_infopp)0,(png_infopp)0);
		fclose(h);
		return( iptr );
		}

	/* Attempt to allocate a final info control structure */
	/* -------------------------------------------------- */
	else if (!(e = png_create_info_struct(p))) {
		png_destroy_read_struct(&p,&i,(png_infopp)0);
		fclose(h);
		return( iptr );
		}

	/* Install error handler and do it ! */
	/* --------------------------------- */
	if (!( png_jmpbuf( p ))) {

		/* initialise IO */
		/* ------------- */
		png_init_io( p, h );

		/* Read information up to data */
		/* --------------------------- */
		png_read_info(p, i );

		/* Collect dimensions and Allocate our image controller */
		/* ---------------------------------------------------- */
		if (((nbc = png_get_image_width ( p, i )) != 0)
		&&  ((nbr = png_get_image_height( p, i )) != 0)
		&&  ((iptr= local_allocate_image(nbc,nbr,0,0)) != (struct standard_image *) 0)) {

			/* Determine the source image type and establish transformations to our 8 bit colour space */
			/* --------------------------------------------------------------------------------------- */
			if (!( hiq ))
				iptr->storage->descriptor[6] = 1;
			else if ( colourmapping )
				iptr->storage->descriptor[6] = 1;

			channels = png_get_channels( p, i );
			rowbytes = png_get_rowbytes( p, i );
			colortype= png_get_color_type( p, i );
			bitdepth = png_get_bit_depth(p,i);

			/* One byte per pixel when would have been packed */
			/* ---------------------------------------------- */
			if ( bitdepth < 8 ) {
				png_set_packing(p);
				/* png_read_update_info( p, i ); */
				}

			if (!( colortype & PNG_COLOR_MASK_COLOR)) {

				/* Its got to be Grey */
				/* ------------------ */
				if ( bitdepth < 8 ) {
					png_set_expand_gray_1_2_4_to_8(p);
					}
				if ( hiq != 0 )
					if (!( xbuffer = allocate( rowbytes ) ))
						hiq = 0;
				}
			else 	{
				if ( colortype & PNG_COLOR_MASK_PALETTE ) {

					/* Expand it to RGB first */
					/* ---------------------- */
					png_set_palette_to_rgb( p );
	
					}

				if ( hiq != 0 ) {

					if (!( xbuffer = allocate( rowbytes ) ))
						hiq = 0;


					}
 				else if (png_get_valid(p, i,PNG_INFO_PLTE)) {
					png_uint_16p histogram = NULL;
					png_get_hIST(p, i,&histogram);
					png_set_quantize(p, &ditherer, 256, 256, histogram, 1);
      					}
				else	{

					/* build the dithering mechanism */
					/* ----------------------------- */
					if (!( dithering )) {
						pptr = thispalette;
						for (r=0; r < 256; r++) {
							ditherer[r].red   = *(pptr++);
							ditherer[r].green = *(pptr++);
							ditherer[r].blue  = *(pptr++);
							pptr++;
							}
						dithering = 1;
						}
					/* and request dithering to our 256 colours */
					/* ---------------------------------------- */
					if ( dithering ) { 
						png_set_quantize( p, &ditherer, 256, 256, NULL, 1 ); 
						}
					}
				}

			png_read_update_info( p, i );


			if (!( hiq )) {

				/* Build and connect the row matrix */
				/* -------------------------------- */
				if ((rptr = allocate((nbr * sizeof(char *)))) != (char **) 0) {
					for (r=0; r < nbr; r++ )
						if (!( *(rptr+r) = connect_pixel_row( iptr->storage,r )))
							break;

					/* Read in the image ( interlacing is also handled) */
					/* ------------------------------------------------ */
					png_read_image( p, rptr ); 	
					liberate( rptr );
					}
				}
			else if (!( colortype & PNG_COLOR_MASK_COLOR)) {
				/* High quality Grey Scale Work */
				/* high quality requires extra work */
				/* -------------------------------- */
				if (!( colourmapping ))
					iptr->format = iptr->storage->descriptor[6];
				for (r=0; r < nbr; r++ ) {
					if (!( pptr = connect_pixel_row( iptr->storage,r )))
						break;
					else	{
						png_read_row(p, xbuffer, NULL);
						for ( c=0; c < nbc; c++ ) {
							rv = *(xbuffer +  (c*channels));
							pptr += put_logical_pixel( pptr, rv, rv, rv );
							}
						}
					}
				}
			else	{
				/* high quality requires extra work */
				/* -------------------------------- */
				if (!( colourmapping ))
					iptr->format = iptr->storage->descriptor[6];
				for (r=0; r < nbr; r++ ) {
					if (!( pptr = connect_pixel_row( iptr->storage,r )))
						break;
					else	{
						png_read_row(p, xbuffer, NULL);
						for ( c=0; c < nbc; c++ ) {
							rv = *(xbuffer +  (c*channels));
							gv = *(xbuffer +  (c*channels)+1);
							bv = *(xbuffer +  (c*channels)+2);
							pptr += put_logical_pixel( pptr, rv, gv, bv );
							}
						}
					}
				}
			}
		}

	/* Clean up all allocations */
	/* ------------------------ */
	png_destroy_read_struct(&p,&i,&e);
	fclose(h);
	return( iptr );
#endif
}
	


#endif	// _standard_png_c


