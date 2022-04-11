#ifndef	_zjpeg_c
#define	_zjpeg_c

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
#else
#include "stdimage.h"
#endif

#include "zalloc.h"
#include "vimage.h"
#include "zjpeg.h"

struct  standard_image * local_allocate_image(int, int, int, int);

int JpegInitialise(int);
int JpegLiberate();
int JpegOpen(PIXIBYTE FAR PTR,int,int,PIXIBYTE FAR PTR);
int JpegClose(int);
int JpegGetRow(int,PIXIBYTE FAR PTR,int);
int JpegGetWidth(int);
int JpegGetHeight(int);
VOID JpegSetMemory(int);

extern	char * thispalette;
static	int	jpegmem=0;
static	char *	workpalette=(char *) 0;

int	JpegHandle=-1;

int	jpeg_option_value=0x007D;

/*	------------	*/
/*	jpeg_options	*/
/*	------------	*/
void	jpeg_options(int v )
{
	jpeg_option_value = (0x007D | v );
	return;
}

/*	-----------------	*/
/*	set_image_quality	*/
/*	-----------------	*/
void	set_image_quality(int v)
{
	if (v)
		jpeg_options( ((_JPEG_DEFAULT) | _JPEG_SOLO) );
	else	jpeg_options( ((_JPEG_DEFAULT)) );
	return;
}

/*	-----------------	*/
/*	get_image_quality	*/
/*	-----------------	*/
int	get_image_quality()
{
	if  (jpeg_option_value & _JPEG_SOLO) 
		return(1);
	else if (!( get_pixel_format() ))
		return(1);
	else	return(0);
}

/*	-----------------	*/
/*	 initialise_jpeg	*/
/*	-----------------	*/
int	initialise_jpeg( char * nptr )

{
	char *	pptr=thispalette;
	workpalette = (char *) 0;
	if (!( jpegmem )) 
	{
		if (( pptr = getenv("JPEGMEM") ) != (char *) 0) 
		{
			jpegmem =0;
			while (( *pptr >= '0' ) && ( *pptr <= '9' ))
				jpegmem = ((jpegmem * 10) + ( *(pptr++) - '0' ));
		}
		pptr = (char *) 0;
	}
	if (!( jpegmem ))
		jpegmem = 8000;

	JpegSetMemory( jpegmem );

	if (!( get_pixel_format() ))
		set_image_quality(1);

	if ( jpeg_option_value & _JPEG_SOLO ) 
	{
		/* ------------------------- */
		/* solo image : solo palette */
		/* ------------------------- */
		if (!( workpalette = allocate( 1024 ) ))
			return(27);
		else	
		{
			memset((pptr=workpalette),0,1024);
			jpeg_option_value &= 0x0FFE;
		}
	}
	if (( JpegHandle = JpegOpen( nptr, (WORD)strlen( nptr ), jpeg_option_value , pptr  )) != -1)
		return(0);
	else	return(40);
}

/*	----------	*/
/*	parse_jpeg	*/
/*	----------	*/
struct	standard_image * parse_jpeg(struct standard_image *  iptr )
{
	int	r;
	int	nby;
	int	nbx;
	char *	bptr;
	if ( JpegHandle == -1 )
		return((struct	standard_image * ) 0);
	else if (!( nby = JpegGetHeight(JpegHandle) ))
		return((struct	standard_image * ) 0);
	else if (!( nbx = JpegGetWidth(JpegHandle) ))
		return((struct	standard_image * ) 0);
	else if (!( iptr = local_allocate_image( nbx, nby, 0, 0 ) ))
		return((struct	standard_image * ) 0);
	else	
	{
		iptr->storage->descriptor[6] = 1;
		iptr->palette = workpalette; workpalette = (char *) 0;
		for ( r=0; r < iptr->rows; r++ ) 
		{
			if (!( bptr = connect_pixel_row( iptr->storage, r ) ))
				break;
			else if (!( JpegGetRow(JpegHandle,bptr, (WORD)nbx )))
				break;
		}
		return( iptr );
	}
}

/*	--------------	*/
/*	terminate_jpeg	*/
/*	--------------	*/
void	terminate_jpeg()
{
	if ( JpegHandle != -1 ) 
	{
		JpegClose( JpegHandle );
		JpegHandle = -1;
	}
	return;
}

/*	-----------	*/
/*	jpeg_loader	*/
/*	-----------	*/
struct standard_image * jpeg_loader( char * filename )
{
	struct standard_image * iptr=(struct standard_image *) 0;
	if (!( initialise_jpeg(filename) ))
		iptr = parse_jpeg(iptr);
	terminate_jpeg();
	return( iptr );
}

#endif	/* _zjpeg_c */
