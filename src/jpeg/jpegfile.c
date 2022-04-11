#ifndef	_jpegfile_c
#define	_jpegfile_c

#include <stdio.h>

#include "zjpeg.h"
#include "zalloc.h"
#include "vimage.h"

#include "jpegtype.h"
#include "jpegdef.h"
#include "jinclude.h"
#include "jpeglib.h"
#define	private static
#define	public	

private	struct	jpeg_manager	{
	FILE  * 	outfile;
	char  *		outbuffer;
	int 		row_stride;
	int		quality;
	int		pixelsize;
	int		default_quality;
	char	*	palette;
	struct 		jpeg_compress_struct cinfo;
	struct 		jpeg_error_mgr jerr;
	JSAMPROW 	row_pointer[1];
	} JpegMan = { (FILE*) 0, (char *) 0, 0, 75, 2, -1, (char *) 0 };


/*	--------------------------------------		*/
/*	s e t _ j p e g _ q u a l i t y  ( v )		*/
/*	--------------------------------------		*/
/*	sets the jpeg compression quality to v		*/
/*	the value passed as the parameter.		*/
/*	best quality : 100; worst quality 1,		*/
/*	default value in JPEG code is 75		*/
/*	--------------------------------------		*/
public	int	set_jpeg_quality( int v )
{
	if (( v <= 100 ) && ( v >= 0 )) {
		JpegMan.default_quality = v;
		return(0);
		}
	else	return(30);
}

public	int	get_jpeg_quality( int v )
{
	return( JpegMan.default_quality );
}

/*	--------------------------------------		*/
/*	r e s e t _ j p e g _ m a n a g e r ()		*/
/*	--------------------------------------		*/
private	void	reset_jpeg_manager()
{
	char	*	eptr;
	JpegMan.outfile  	= (FILE*) 0;
	JpegMan.outbuffer	= (char *) 0;
	JpegMan.row_stride	= 0;

	if ( JpegMan.default_quality == -1 ) {
#ifdef	WIN32
		if (!(eptr = confgetenv("JPEGQ"))) {
#else
		if (!( eptr = getenv("JPEGQ"))) {
#endif
			JpegMan.default_quality	= 0;
			}
		else	{
			JpegMan.default_quality = atoi( eptr );
			}
		}
	JpegMan.quality		= JpegMan.default_quality;
	JpegMan.pixelsize	= 2;
	JpegMan.palette		= (char *) 0;
	return;
}


/*	----------------------		*/
/*	j p e g _ c l o s e ()		*/
/*	----------------------		*/

public	int	jpg_close()
{
	if ( JpegMan.outfile ) {
		jpeg_finish_compress(&JpegMan.cinfo);
		fclose(JpegMan.outfile);
		jpeg_destroy_compress(&JpegMan.cinfo);
		}
	if ( JpegMan.outbuffer )
		liberate( JpegMan.outbuffer );
	reset_jpeg_manager();
}

/*	------------------------	*/
/*	j p e g _ c r e a t e ()	*/
/*	------------------------	*/

public	int	jpg_create( char * filename, unsigned int w, unsigned int h, int tc, int ps, unsigned char * palette )
{
	reset_jpeg_manager();

	if (!(JpegMan.outfile = fopen(filename, "wb")))
		return(0);
 
	JpegMan.cinfo.err = jpeg_std_error(&JpegMan.jerr);

	jpeg_create_compress(&JpegMan.cinfo);

	jpeg_stdio_dest(&JpegMan.cinfo, JpegMan.outfile);


	JpegMan.cinfo.image_width = w;
	JpegMan.cinfo.image_height = h;
	JpegMan.cinfo.input_components = 3;		
	JpegMan.cinfo.in_color_space = JCS_RGB;

	jpeg_set_defaults(&JpegMan.cinfo);
	if ( JpegMan.quality ) {
		jpeg_set_quality(&JpegMan.cinfo, JpegMan.quality, 0);
		}
	jpeg_start_compress(&JpegMan.cinfo, TRUE);
	JpegMan.row_stride = (w * 3);	
	if ( tc )
		JpegMan.pixelsize  = ps;
	else	JpegMan.pixelsize  = 0;
	JpegMan.palette = palette;
	if (!( JpegMan.outbuffer = allocate( JpegMan.row_stride )))
		return(0);
	else	return(1);

}


#include "pexpand.c"

/*	---------------------------------------------------------	*/
/*			j p e g _ r o w ()				*/
/*	---------------------------------------------------------	*/
/*	It is the callers responsibility to expand the pixels to 	*/
/*	full RGB byte triads						*/
/*	--------------------------------------------------------- 	*/

public	int	jpg_row(int r, unsigned char * rowbuffer, int rl )
{
 	if (JpegMan.cinfo.next_scanline < JpegMan.cinfo.image_height) {
		expand_pixels(JpegMan.pixelsize,rowbuffer,JpegMan.cinfo.image_width,JpegMan.outbuffer,JpegMan.palette);
		/* memcpy( JpegMan.outbuffer, rowbuffer, JpegMan.row_stride ); */
		JpegMan.row_pointer[0] = JpegMan.outbuffer;
		(void) jpeg_write_scanlines(&JpegMan.cinfo, JpegMan.row_pointer, 1);
		return(1);
		}
	else	return(0);

}



#endif 	/* _jpegfile_c */
	/* ----------- */


