#ifndef	_singjpeg_c
#define	_singjpeg_c

/*	----------------------		*/
/*	j p e g _ c l o s e ()		*/
/*	----------------------		*/

int	jpg_close()
{
	return( JpegCloseOutput() );
}

/*	------------------------	*/
/*	j p e g _ c r e a t e ()	*/
/*	------------------------	*/

int	jpg_create( char * filename, unsigned int w, unsigned int h, int d, int t )
{
	return( JpegCreate(filename, w, h, truecolour, pixelsize, genpalette ) );
}


/*	------------------	*/
/*	j p e g _ r o w ()	*/
/*	------------------	*/

int	jpg_row(int r, char * rowbuffer, int rl )
{
	return( JpegPutRow( r, rowbuffer, rl ) );
}



#endif 	/* _singjpeg_c */
	/* ----------- */

