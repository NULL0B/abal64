#ifndef	_JREAD_C
#define	_JREAD_C

#include <stdio.h>
#include "jpeglib.h"
#include "ijpeg.h"

/******************** JPEG DECOMPRESSION SAMPLE INTERFACE *******************/

/* 
 * This half of the example shows how to read data from the JPEG decompressor.
 * It's a bit more refined than the above, in that we show:
 *   (a) how to modify the JPEG library's standard error-reporting behavior;
 *   (b) how to allocate workspace using the library's memory manager.
 *
 * Just to make this example a little different from the first one, we'll
 * assume that we do not intend to put the whole image into an in-memory
 * buffer, but to send it line-by-line someplace else.  We need a one-
 * scanline-high JSAMPLE array as a work buffer, and we will let the JPEG
 * memory manager allocate it for us.  This approach is actually quite useful
 * because we don't need to remember to deallocate the buffer separately: it
 * will go away automatically when the JPEG object is cleaned up.
 */


/*
 * Sample routine for JPEG decompression.  We assume that the source file name
 * is passed in.  We want to return 1 on success, 0 on error.
 */


GLOBAL int read_JPEG_file (char * filename)
{
	struct jpeg_decompress_struct cinfo;	/* decompression controler */
	FILE * infile;				/* source file 		   */
  	JSAMPARRAY buffer;			/* Output row buffer 	   */
	int row_stride;				/* physical row width in   */
						/* output buffer 	   */

  /* In this example we want to open the input file before doing anything else,
   * so that the setjmp() error recovery below can assume the file is open.
   * VERY IMPORTANT: use "b" option to fopen() if you are on a machine that
   * requires it in order to read binary files.
   */

	if ((infile = fopen(filename, "rb")) == NULL)
		return(400);

#ifdef	_JPEG_NAVIGATOR_READ

  /* Step 1: allocate and initialize JPEG decompression object */

	jpeg_create_decompress(&cinfo);

  /* Step 2: specify data source (eg, a file) */

	jpeg_stdio_src(&cinfo, infile);

  /* Step 3: read file parameters with jpeg_read_header() */

	(void) jpeg_read_header(&cinfo, TRUE);

  /* We can ignore the return value from jpeg_read_header since
   *   (a) suspension is not possible with the stdio data source, and
   *   (b) we passed TRUE to reject a tables-only JPEG file as an error.
   * See libjpeg.doc for more info.
   */

  /* Step 4: set parameters for decompression */

  /* In this example, we don't need to change any of the defaults set by
   * jpeg_read_header(), so we do nothing here.
   */

  /* Step 5: Start decompressor */

	(void) jpeg_start_decompress(&cinfo);

  /* We can ignore the return value since suspension is not possible
   * with the stdio data source.
   */

  /* We may need to do some setup of our own at this point before reading
   * the data.  After jpeg_start_decompress() we have the correct scaled
   * output image dimensions available, as well as the output colormap
   * if we asked for color quantization.
   * In this example, we need to make an output work buffer of the right size.
   */ 

  /* JSAMPLEs per row in output buffer */

	row_stride = cinfo.output_width * cinfo.output_components;

  /* Make a one-row-high sample array that will go away when done with image */

	buffer = (*cinfo.mem->alloc_sarray)
		((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

  /* Step 6: while (scan lines remain to be read) */
  /*           jpeg_read_scanlines(...); */

  /* Here we use the library's state variable cinfo.output_scanline as the
   * loop counter, so that we don't have to keep track ourselves.
   */

	while (cinfo.output_scanline < cinfo.output_height) {

    /* jpeg_read_scanlines expects an array of pointers to scanlines.
     * Here the array is only one element long, but you could ask for
     * more than one scanline at a time if that's more convenient.
     */
		(void) jpeg_read_scanlines(&cinfo, buffer, 1);

    		use_scanline_someplace(buffer[0], row_stride);

  		}

  /* Step 7: Finish decompression */

	(void) jpeg_finish_decompress(&cinfo);

  /* Step 8: Release JPEG decompression object */

	jpeg_destroy_decompress(&cinfo);

#endif
	fclose(infile);
	return(0);
}


/*
 * SOME FINE POINTS:
 *
 * In the above code, we ignored the return value of jpeg_read_scanlines,
 * which is the number of scanlines actually read.  We could get away with
 * this because we asked for only one line at a time and we weren't using
 * a suspending data source.  See libjpeg.doc for more info.
 *
 * We cheated a bit by calling alloc_sarray() after jpeg_start_decompress();
 * we should have done it beforehand to ensure that the space would be
 * counted against the JPEG max_memory setting.  In some systems the above
 * code would risk an out-of-memory error.  However, in general we don't
 * know the output image dimensions before jpeg_start_decompress(), unless we
 * call jpeg_calc_output_dimensions().  See libjpeg.doc for more about this.
 *
 * Scanlines are returned in the same order as they appear in the JPEG file,
 * which is standardly top-to-bottom.  If you must emit data bottom-to-top,
 * you can use one of the virtual arrays provided by the JPEG memory manager
 * to invert the data.  See wrbmp.c for an example.
 *
 * As with compression, some operating modes may require temporary files.
 * On some systems you may need to set up a signal handler to ensure that
 * temporary files are deleted if the program is interrupted.  See libjpeg.doc.
 */


int	main(argc,argv)
int	argc;
char * argv[];
{
	int	status;
	int	argi;
	char * aptr;
	if ( argc > 1 ) {
		for (argi= 1; argi < argc; argi++ ) {
			aptr = argv[argi];	
			if ( *aptr != '-' ) {
				printf("fichier: %s \n",aptr);
				if ((status = read_JPEG_file( aptr )) != 0)
					printf("\terror %u\n",status);
				}
			}

		}
	else	{
		printf("\n   JPEG Image Loader Test Utility \n");
		printf("\n   Provisoire 05/01/1999 \n");
		printf("\n   * * Not for Distribution * *\n");
		}
	return(0);
}


#endif	/* _JREAD_C */
	/* -------- */

