#ifndef	_SING_GIF_C
#define	_SING_GIF_C

#ifdef WIN32
FILE * open_production_target( char * nptr, int type );
void	close_production_target( FILE * h, char * nptr );
#else
#include "singprod.h"
#endif

#define	LZW_BITS	12

#define	HASH_SIZE	9973
#define	HASH_STEP	2039

#ifndef	WORD
#define	WORD	unsigned short int
#endif

#ifndef	DWORD
#define	DWORD	unsigned long
#endif

#undef 	_TRACE_GIF

#ifdef	_TRACE_GIF
static	char *	TraceGif="\0=TraceGif";
#endif

struct	gif_control	{
	int		started;

	WORD	*	prefixcode;
	BYTE	*	secondbyte;
	int *		code_value;
	BYTE		buffer[256];
	
	int		code_size;
	int		code;
	int		buff_offset;
	int		bit_count;
	DWORD		bit_buffer;
	int		clear_code;
	int		end_of_info;
	int		first_code;
	int		next_code;
	int		max_code;
	int		num_bits;
	int		bytesperline;
	int		line_number;
	
	} Gif;

public	void	reset_gif_control( int mode )
{
#ifdef	_TRACE_GIF
	if ( *TraceGif )
		printf("reset_gif_control(%u)\n",mode);
#endif
	if ( mode ) {
		if ( Gif.prefixcode )
			Gif.prefixcode = liberate( Gif.prefixcode );
		if ( Gif.secondbyte )
			Gif.secondbyte = liberate( Gif.secondbyte );
		if ( Gif.code_value )
			Gif.code_value = liberate( Gif.code_value );
		}
	else	{
		Gif.prefixcode = (WORD *) 0;
		Gif.secondbyte = (BYTE *) 0;
		Gif.code_value = (int  *) 0;
		}

	/* Reset all other member fields */
	/* ----------------------------- */
	Gif.code_size	=	Gif.code	=0;
	Gif.buff_offset	=	Gif.bit_count	=0;

	memset(Gif.buffer,0,256);

	Gif.bit_buffer=0L;

	Gif.clear_code	=	Gif.end_of_info	=0;
	Gif.first_code	=	Gif.next_code	=0;
	Gif.max_code	=	Gif.num_bits	=0;
	Gif.bytesperline=	Gif.line_number	=0;

	Gif.started = 0;
	return;
}


public 	int	gif_create(char * nptr, unsigned int w, unsigned int h, int d, int t )
{
	char	*	pptr;
	int		i;

	if (!( get_pixel_format() ))
		return(0);

#ifdef	_TRACE_GIF
	if ( *TraceGif )
		printf("gif_create(%s,%u,%u,%u,%u)\n",nptr,w,h,d,t);
#endif
	reset_gif_control(0);

	GenImage.transparent = t;

	if (!( GenImage.handle = open_production_target( nptr, 1 ) ))
		return(0);
	else if ((GenImage.name = allocate( strlen( nptr ) + 1 )) != (char *) 0)
		strcpy(GenImage.name,nptr);
 
	/* file signature */
	/* -------------- */
	put_byte(GenImage.handle,'G'); 
	put_byte(GenImage.handle,'I');
	put_byte(GenImage.handle,'F');
	put_byte(GenImage.handle,'8');
	put_byte(GenImage.handle,'7');
	put_byte(GenImage.handle,'a');

	/* logical screen descriptor and Global Palette */
	/* -------------------------------------------- */
	put_word(GenImage.handle,(GenImage.width=w));	/* image width			*/
	put_word(GenImage.handle,(GenImage.height=h));	/* image height 		*/

	if ((pptr = thispalette) != (char *) 0) {

		put_byte(GenImage.handle,0x00F7);	/* flags:Global Colour Map 256	*/
		put_byte(GenImage.handle,0);	/* background colour index 	*/
		put_byte(GenImage.handle,0);	/* aspect ration		*/

		for (i=0; i < 256; i++ ) {
			put_byte(GenImage.handle, *(pptr++) );
			put_byte(GenImage.handle, *(pptr++) );
			put_byte(GenImage.handle, *(pptr++) );
			pptr++;
			}

		}
	else	{
		put_byte(GenImage.handle,0);		/* flags: no colour map 	*/
		put_byte(GenImage.handle,0);		/* background colour index 	*/
		put_byte(GenImage.handle,0);		/* aspect ration		*/
		}
	return(1);

}

private	void 	gif_putcode(WORD code) 
{
#ifdef	_TRACE_GIF
	if ( *TraceGif )
		printf("gif_putcode(0x0%x)\n",code);
#endif
	Gif.bit_buffer |= (((DWORD) code) << Gif.bit_count);
	Gif.bit_count += Gif.num_bits;

	while (Gif.bit_count >= 8) {
		Gif.buffer[Gif.buff_offset] = (Gif.bit_buffer & 0x00FF);
		Gif.buff_offset++;
		if ( Gif.buff_offset == 255) {
#ifdef	_gif_tester
			printf("gif_putcode::flush_block(%u)\n",255);
#endif
			put_byte(GenImage.handle,255);
			put_block(GenImage.handle,Gif.buffer,255);
			Gif.buff_offset = 0;
			}
		Gif.bit_buffer >>= 8;
		Gif.bit_count -= 8;
		}
	return;
}

public 	void	gif_close()
{
	int	i;
	if ( GenImage.handle ) {
		if (Gif.started) {

	 	  	/* We must handle the case of bit increment when EOF */
			/* ------------------------------------------------- */
			if (Gif.next_code == Gif.max_code)
				++Gif.num_bits;  

			gif_putcode(Gif.code); 
			gif_putcode(Gif.end_of_info); 
			gif_putcode(0);

			/* flush all unwritten code */
			/* ------------------------ */
			if (Gif.buff_offset != 0) {
#ifdef	_gif_tester
			printf("gif_putcode::flush_block(%u)\n",Gif.buff_offset);
#endif
				put_byte(GenImage.handle,Gif.buff_offset);
				put_block(GenImage.handle,Gif.buffer,Gif.buff_offset);
				}

			/* end of image record */
			/* ------------------- */
			put_byte(GenImage.handle,0x0000);
			put_byte(GenImage.handle,0x003B);
			put_byte(GenImage.handle,0x0000);

			}

		close_production_target(GenImage.handle,GenImage.name);
		if ( GenImage.name ) {
			liberate( GenImage.name );
			GenImage.name = (char *) 0;
			}
		reset_gif_control(1);
		reset_image_control();

		}
	return;
}

public 	int gif_find_match(
		int 	hash_prefix,
		WORD 	hash_symbol	
		) 
{
	int index,offset;

#ifdef	_TRACE_GIF
	if ( *TraceGif )
		printf("gif_find_match(%d,%u)\n",hash_prefix,hash_symbol);
#endif
	index = ((hash_symbol << LZW_BITS - 8) | hash_prefix);

	if (!(index))
		offset = 1;
	else 	offset = (HASH_SIZE - index);

#ifdef	_TRACE_GIF
	if ( *TraceGif )
		printf("\tindex = %d offset = %d \n",index,offset);
#endif
	while (1) {
		if (Gif.code_value[index] == -1) {
#ifdef	_TRACE_GIF
			if ( *TraceGif )
				printf("\tGif.code_value[%u] == -1 : return(%u)\n",index,index);
#endif
			return(index);
			}
		else if (( Gif.prefixcode[index] == hash_prefix )
		     &&  ( Gif.secondbyte[index] == hash_symbol )) {
#ifdef	_TRACE_GIF
			if ( *TraceGif )
				printf("\tGif.prefix and secondbyte check on %u : return(%u)\n",index,index);
#endif
			return(index);
			}
		else	{

#ifdef	_TRACE_GIF
			if ( *TraceGif )
				printf("\tadjust index(%d) by(-=) offset(%u) ",index,offset);
#endif
			index -= offset;
			}

#ifdef	_TRACE_GIF
			if ( *TraceGif )
				printf(" : gives index(%d)\n",index);
#endif
		if (index < 0) {

			index += HASH_SIZE;

#ifdef	_TRACE_GIF
			if ( *TraceGif )
				printf(" : += HASH_SIZE(%u) gives index(%d)\n",HASH_SIZE,index);
#endif
			}

		}
	
}

public	void	gif_row(int r, unsigned char * rowbuffer,int rl )
{
	WORD i=0,index;
	unsigned char pixelvalue;

	if (!( Gif.started )) {

		/* Image Extension */
		/* --------------- */
		put_byte( GenImage.handle, 0x021 ); /* Extension block 	  */
		put_byte( GenImage.handle, 0x0F9 ); /* Graphics extension */
		put_byte( GenImage.handle, 0x004 ); /* block length	  */
		put_byte( GenImage.handle, GenImage.transparent ); /* bitval 1 transpar  */
		put_byte( GenImage.handle, 0x000 ); /* unknown byte 	  */
		put_byte( GenImage.handle, 0x000 ); /* Transparence code  */
		put_byte( GenImage.handle, 0x000 ); /* unknown byte	  */
		put_byte( GenImage.handle, 0x000 ); /* NULL block length  */
		
		/* Image Descriptor */
		/* ---------------- */
		put_byte( GenImage.handle, 0x02C );	/* Image Descriptor 	*/
		put_word( GenImage.handle, 0 );	/* X offset		*/
		put_word( GenImage.handle, 0 );	/* Y offset		*/
		put_word( GenImage.handle, GenImage.width );	
		put_word( GenImage.handle, GenImage.height );
		put_byte( GenImage.handle, 0 );	/* options : 0		*/

		/* Allocation of GIF compression structures */
		/* ---------------------------------------- */
		if ((!( Gif.prefixcode = (WORD*) allocate((HASH_SIZE*sizeof(WORD))) ))
		||  (!( Gif.code_value = (int*)  allocate((HASH_SIZE*sizeof(int)))  )) 
		||  (!( Gif.secondbyte = (BYTE*) allocate((HASH_SIZE*sizeof(BYTE))) ))) {
			gif_close();
			return;
			}

		memset(Gif.code_value,0xFF,HASH_SIZE*2);
		Gif.started=1;
		put_byte( GenImage.handle, (Gif.code_size= 8));
		Gif.code_size++;
		Gif.buff_offset = Gif.bit_count = Gif.bit_buffer = 0;
		Gif.clear_code  = (1 << (Gif.code_size-1));
		Gif.end_of_info = (Gif.clear_code + 1);
		Gif.next_code   = Gif.first_code  = (Gif.clear_code + 2);
		Gif.max_code    = ((1 << Gif.code_size) - 1);
		Gif.num_bits    = Gif.code_size;
		Gif.bytesperline= GenImage.width;
		Gif.line_number = 0;
		Gif.code        = *rowbuffer;
		gif_putcode(Gif.clear_code);
		i=1;
		}

	else if ( Gif.line_number >= GenImage.height )
		return;

	else	i= 0;

	for(	;
		i < GenImage.width;
		i++ )	{

		pixelvalue = (*(rowbuffer+i) & 0x00FF);           // get next pixel

		index = gif_find_match(Gif.code,(WORD)pixelvalue);

		if(Gif.code_value[index] != -1) 
			Gif.code=Gif.code_value[index];

		else 	{

			Gif.code_value[index] = Gif.next_code;
			Gif.prefixcode[index] = Gif.code;
			Gif.secondbyte[index] = pixelvalue;

			/* output the current code */
			/* ----------------------- */

			gif_putcode(Gif.code); 
			Gif.code = pixelvalue;

			/* check for code table full condition */
			/* ----------------------------------- */
			if (Gif.next_code++ > Gif.max_code) {
				if ( Gif.num_bits < LZW_BITS)
					Gif.max_code = (1 << ++Gif.num_bits) - 1; // increment code size
				else 	{
					gif_putcode(Gif.clear_code);
					Gif.num_bits = Gif.code_size;
					Gif.next_code = Gif.first_code;
					Gif.max_code = (1 << Gif.num_bits) - 1;
					/* reset the code table */
					/* -------------------- */
					memset(Gif.code_value,0xFF,HASH_SIZE*2);
					}
				}
			}
		}

	Gif.line_number++;


	return;
}


#endif	/* _SING_GIF_C */

