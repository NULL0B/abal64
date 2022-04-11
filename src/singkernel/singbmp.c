#ifndef	_SING_BMP_C
#define	_SING_BMP_C

extern	char * thispalette;

#include "singprod.h"

struct	image_generator_control	{
	char *	name;	
	FILE * 	handle;
	int	height;
	int	width;
	int	transparent;
	} GenImage = { (char *) 0, (FILE*)0, 0,0 };

static	unsigned char ImagePalette[256][4];


public	void	reset_image_control()
{
	GenImage.name =(char *) 0;
	GenImage.handle = (FILE *) 0;
	GenImage.width  = GenImage.height = 0;
	return;
}

public 	int	bmp_create(char * nptr, unsigned int w, unsigned int h, int d )
{
	unsigned 	char *	pptr;
	unsigned 	int	i;
	unsigned	int	x;
	unsigned long headersize=0x0028;
	unsigned long pixeloffset=0x0436;
	unsigned long filesize=0L;
	unsigned long compsize=0L;
	compsize = w;
	for (x=w; x%4 != 0; x++ )
		compsize++;
	compsize = (compsize * h); 
	filesize = compsize;
	filesize += pixeloffset;

	/* End of File @ (256*4)+54+(w*h) */
	if (!( GenImage.handle = open_production_target( nptr, 1 ) ))
		return(40);
	else if ((GenImage.name = allocate( strlen( nptr ) + 1 )) != (char *) 0)
		strcpy( GenImage.name,nptr);

	/* 0: signature */
	put_byte(GenImage.handle,'B');
	put_byte(GenImage.handle,'M');

	/* 2: filesize */	
		put_long(GenImage.handle,filesize);

	/* 6: resolution 1 and 2 */
		put_word(GenImage.handle,0);
		put_word(GenImage.handle,0);

	/* 10: pixel offset */
		put_long(GenImage.handle,pixeloffset);

	/* 14: header size */
		put_long(GenImage.handle,headersize);

	/* 18: columns / rows / planes / bits */
		put_long(GenImage.handle,(unsigned long) w);
		put_long(GenImage.handle,(unsigned long) h);
		put_word(GenImage.handle, 1);
		put_word(GenImage.handle, d);

	/* 30 : compression /  compsize : filesize-pixeloffset */
		put_long(GenImage.handle, 0L);
		put_long(GenImage.handle, compsize );

	/* 38 : X and Y scale */
		put_long(GenImage.handle, 0L);
		put_long(GenImage.handle, 0L);

	/* 46 : Colour Count / Important Colour Count */
		put_long(GenImage.handle, 256L);
		put_long(GenImage.handle, 256L);

	/* 54 : Palette : 256 * 4 bytes		*/
	if ((pptr = thispalette) != (char *) 0) {
		for (i=0; i < 256; i++ ) {
			ImagePalette[i][3] = 0;
			ImagePalette[i][2]=*(pptr++);
			ImagePalette[i][1]=*(pptr++);
			ImagePalette[i][0]=*(pptr++);
			pptr++;
			}
		put_block(GenImage.handle,ImagePalette,256*4);
		}

	/* 256*4+54 : Pixels will start here */

	/* End of File @ (256*4)+54+(w*h) */

	return(1);
}


public	void	bmp_row(int r, char * bptr,int rl )
{
	int	i;
	if ( GenImage.handle )
		put_block(GenImage.handle,bptr,rl);
	for (i=rl; i%4 != 0; i++ )
		put_byte(GenImage.handle,0);
	return;
}

public 	void	bmp_close()
{
	if ( GenImage.handle ) {
		close_production_target(GenImage.handle,GenImage.name);
		if ( GenImage.name ) {
			liberate( GenImage.name );
			GenImage.name = (char *) 0;
			}
		GenImage.handle = (FILE *) 0;
		}
	return;
}


#endif	/* _SING_BMP_C */


