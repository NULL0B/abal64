#include "genimage.h"

#ifdef	UNIX
#define	_WRITE_JPG
#define	_WRITE_PNG
#endif
#ifdef	WIN32
#define	_WRITE_JPG
#define	_WRITE_PNG
#endif

static	int	pixelsize=1;
static  int 	truecolour=0;
static	char *	genpalette=(char*) 0;

#include "pexpand.c"
#include "singbmp.c"
#include "singgif.c"
#ifdef	_WRITE_PNG
#include "singpng.c"
#endif

public	void	image_configuration(int ismap, int psize, char * pptr )
{
	if ( pptr )
		genpalette= pptr;
	else	genpalette= thispalette;
	truecolour= ismap;
	pixelsize = psize;
	return;
}

public 	int	image_create(char * nptr, unsigned int w, unsigned int h, int d, int format, int t )
{
	switch ( format ) {
		case	_GENERATE_BMP	:
			return( bmp_create( nptr, w,h,d ) );
		case	_GENERATE_GIF	:
			return( gif_create( nptr, w,h,d, t ) );
#ifdef	_WRITE_JPG
		case	_GENERATE_JPG	:
			return( jpg_create( nptr, w,h,truecolour,pixelsize,genpalette ) );	
#endif
#ifdef	_WRITE_PNG
		case	_GENERATE_PNG	:
			return( png_create( nptr, w,h,truecolour,pixelsize,genpalette ) );
#endif
		default			:
			return(0);
		}
}


public	int	image_row(int r, char * bptr,int rl, int format )
{
	switch ( format ) {
		case	_GENERATE_BMP	:
			bmp_row(r,bptr,rl ); return(1);
		case	_GENERATE_GIF	:
			gif_row(r,bptr,rl ); return(1);
#ifdef	_WRITE_JPG
		case	_GENERATE_JPG	:
			return(jpg_row(r,bptr,rl ));
#endif
#ifdef	_WRITE_PNG
		case	_GENERATE_PNG	:
			return(png_row(r,bptr,rl ));
#endif
		default			:
			return(0);
		}
}

public 	void	image_close(int format)
{
	switch ( format ) {
		case	_GENERATE_BMP	:
			bmp_close(); return;
		case	_GENERATE_GIF	:
			gif_close(); return;
#ifdef	_WRITE_JPG
		case	_GENERATE_JPG	:
			jpg_close(); return;
#endif
#ifdef	_WRITE_PNG
		case	_GENERATE_PNG	:
			png_close(); return;	
#endif
		default			:
			return;
		}
}



public 	int	image_write( char * nptr, struct standard_image * iptr, int mode, int transparence )
{
	int	r;
	char *	rptr;

	if ((!( nptr ))
	||  (!( iptr )))
		return(0);

	if ((!( iptr->columns ))
	||  (!( iptr->rows    )))
		return(0);

	if (!( image_create(nptr,iptr->columns,iptr->rows,8,mode,transparence)))
			return(0);
	else	{
		if ( mode == _GENERATE_BMP ) {
			for (	r=iptr->rows; r != 0; r-- ) {
				if (!( rptr = connect_pixel_row(iptr->storage,(r-1)) ))
					break;
				else if (!( image_row((r-1),rptr, iptr->columns,mode) ))
					break;
				}
			}
		else if ( mode == _GENERATE_GIF ) {
			for (	r=0; r < iptr->rows;  r++ ) {
				if (!( rptr = connect_pixel_row(iptr->storage,r) ))
					break;
				else if (!( image_row(r,rptr, iptr->columns,mode) )) 
					break;
				}
			}
		else if ( mode == _GENERATE_PNG ) {
			for (	r=0; r < iptr->rows;  r++ ) {
				if (!( rptr = connect_pixel_row(iptr->storage,r) ))
					break;
				else if (!( image_row(r,rptr, iptr->columns,mode) )) 
					break;
				}
			}
		else if ( mode == _GENERATE_JPG ) {
			for (	r=0; r < iptr->rows;  r++ ) {
				if (!( rptr = connect_pixel_row(iptr->storage,r) ))
					break;
				else if (!( image_row(r,rptr, iptr->columns,mode) )) 
					break;
				}
			}
		image_close(mode);
		return(1);
		}

}

