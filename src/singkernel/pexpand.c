#ifndef	_expand_pixels_c
#define	_expand_pixels_c


/*	-----------------------------------------	*/
/*		e x p a n d _ p i x e l s ()		*/
/*	-----------------------------------------	*/

private	void	expand_pixels( 
			int  pixel, 					/* source pixel size		*/
			unsigned char * sptr, unsigned int width, 	/* source buffer and width 	*/
			unsigned char * rptr, 				/* target colour traid buffer 	*/
			unsigned char * pptr 				/* eventual colourmap		*/
			)
{
	int	w;
	int	x;
	int	v;
	int	rvalue,bvalue,gvalue;
	unsigned char *	wptr;	
	for ( 	x=0;
		x < width; x++ ) {
		switch ( pixel ) {
			case	0	: /* colour mapped */
				v = (*(sptr+x) & 0x00FF);
				rvalue = *(pptr+(v*4));
				gvalue = *(pptr+(v*4)+1);
				bvalue = *(pptr+(v*4)+2);
				break;
			case	1	:
				rvalue = ((*(sptr+x) & 0x00D0));
				gvalue = ((*(sptr+x) & 0x001C) << 3);
				bvalue = ((*(sptr+x) & 0x0003) << 6);
				break;
			case	2	:
				v = ((*(sptr+(x*2)+1) << 8) | *(sptr+(x*2)));
				rvalue = ((v & 0xF800) >> 8);
				gvalue = ((v & 0x07D0) >> 3);
				bvalue = ((v & 0x001F) << 3);
				break;
			case	3	:
				rvalue = *(sptr+(x*3)+0);
				gvalue = *(sptr+(x*3)+1);
				bvalue = *(sptr+(x*3)+2);
				break;
			case	4	:
				rvalue = *(sptr+(x*4)+0);
				gvalue = *(sptr+(x*4)+1);
				bvalue = *(sptr+(x*4)+2);
				break;
			}
		*(rptr++) =rvalue;
		*(rptr++) =gvalue;
		*(rptr++) =bvalue;
		}
	return;
}

#endif	/* _expand_pixels_c */
	/* ---------------- */

