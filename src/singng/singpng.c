
#ifndef	_SING_PNG_C
#define _SING_PNG_C

#include <stdio.h>

#ifdef	WIN32
/* #define	NOPNG */	/* a virer lorsqu'on a du png pour windows */
#endif

#ifndef	NOPNG
#include <png.h>
#include "zpng.h"
#endif

#include "zalloc.h"
#include "vimage.h"

 
private	struct	png_control	{

	FILE		       * handle;
	struct	standard_image * image;
#ifndef	NOPNG
	png_structp		 p;
	png_infop		 info;
	png_infop		 extra;
#endif
	char *			 outbuffer;
	char *			 palette;
	int			 truecolour;
	int			 pixelsize;
	int			outpixels;
	int			inpixels;
	int			width;
	int			height;
	int			failure;

	} PngMan = { (FILE*)0,(struct standard_image *) 0
#ifndef	NOPNG
		,(png_structp) 0,(png_infop) 0,(png_infop) 0 
#endif
	};


private	void	png_error_trap(char * mptr)
{
	return;
}

private	void	png_warning_trap(char * mptr)
{
	return;
}


private	void	reset_png_manager()
{
	PngMan.handle=(FILE*) 0;
	PngMan.image=(struct standard_image *) 0;
#ifndef	NOPNG
	PngMan.p=(png_structp)0;
	PngMan.info=(png_infop)0;
	PngMan.extra=(png_infop) 0;
#endif
	PngMan.palette   = (char*) 0;
	PngMan.outbuffer = (char *) 0;
	PngMan.outpixels = 0;
	PngMan.inpixels  = 0;
	PngMan.width     = 0;
	PngMan.height    = 0;
	PngMan.failure	 = 0;
	return;

}

public	void	png_close()
{
#ifndef	NOPNG
	if ( PngMan.p ) {

		/* Install error handler and do it ! */
		/* --------------------------------- */
		if (!( setjmp( PngMan.p->jmpbuf ))) {

			if (!( PngMan.failure )) {
				/* Flush pending output data */
				/* ------------------------- */
				if ( PngMan.info ) { png_write_end(PngMan.p, PngMan.info); }

				/* Clean up all allocations */
				/* ------------------------ */
				png_destroy_write_struct(&PngMan.p,&PngMan.info);
				}

			}

		if ( PngMan.handle )
			fclose( PngMan.handle );
		}
#endif
	reset_png_manager();
	return;

}


public 	int	png_create(
			char * nptr, 
			unsigned int w, unsigned int h, 
			int tc, int ps, char * pptr
			)
{
	int	r;
	int	imode=0;
	int	pmode=0;

	reset_png_manager();	

#ifndef	NOPNG
	PngMan.truecolour = tc;
	PngMan.pixelsize  = ps;

	if (!( tc )) 
		PngMan.inpixels = 0;
	else	PngMan.inpixels = ps;

	PngMan.outpixels = 3;
	imode=PNG_COLOR_TYPE_RGB;
	pmode=8;

	PngMan.palette=pptr;
	PngMan.failure=0;

	/* Attempt to open the file */
	/* ------------------------ */
	if (!( PngMan.handle = fopen( nptr, "wb" )))
		return(0);

	/* Attempt to allocate a control structure for reading */
	/* --------------------------------------------------- */
	else if (!(PngMan.p = png_create_write_struct(
			PNG_LIBPNG_VER_STRING,
			&PngMan,		/* (png_voidp)0	*/
			png_error_trap,  	/* (png_voidp)0 */
			png_warning_trap 	/*(png_voidp)0  */ 
			))) {
		png_close();
		return(0);
		}

	/* Attempt to allocate a start info control structure */
	/* -------------------------------------------------- */
	else if (!(PngMan.info = png_create_info_struct(PngMan.p))) {
		png_close();
		return(0);
		}

	/* Allocate Output storage */
	/* ----------------------- */
	else if (!( PngMan.outbuffer = allocate( w * PngMan.outpixels ))) {
		png_close();
		return(0);
		}

	/* Install error handler and do it ! */
	/* --------------------------------- */
	if (!( setjmp( PngMan.p->jmpbuf ))) {

		/* initialise IO */
		/* ------------- */
		png_init_io( PngMan.p, PngMan.handle );

		/* Use Best Compression Level */
		/* -------------------------- */ 
	        png_set_compression_level(PngMan.p, Z_BEST_COMPRESSION);

		/* Set up the file format fields */
		/* ----------------------------- */
		png_set_IHDR(PngMan.p, PngMan.info, w, h,
			pmode,
			imode,
			PNG_INTERLACE_NONE,
			PNG_COMPRESSION_TYPE_DEFAULT,
			PNG_FILTER_TYPE_DEFAULT);

		/* And write it out to disk */
		/* ------------------------ */
		png_write_info(PngMan.p, PngMan.info );

		PngMan.width = w;
		PngMan.height= h;

		return(1);

		}
	else	{
		PngMan.failure=1;
		png_close();
		return(0);
		}
#else
	return(0);
#endif

}

public	int	png_row(int r, unsigned char * rowbuffer,int rl )
{
#ifndef	NOPNG
	/* Install error handler and do it ! */
	/* --------------------------------- */
	if (!( setjmp( PngMan.p->jmpbuf ))) {
		if (!( PngMan.outbuffer	))
			return(0);
		else	{
			expand_pixels(
				PngMan.inpixels,
				rowbuffer, PngMan.width,
				PngMan.outbuffer,
				PngMan.palette );
			png_write_row(PngMan.p,PngMan.outbuffer);
			}
		return(1);
		}
	else	{
		PngMan.failure=1;
		return(0);
		}
#else
	return(0);
#endif
}

	/* ----------- */
#endif	/* _SING_PNG_C */
	/* ----------- */


