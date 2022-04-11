#ifndef	_wave_c
#define	_wave_c

#include <stdio.h>
#ifdef UNIX
#include <sys/ioctl.h>
#include <unistd.h>
#endif
#include <fcntl.h>
#include <errno.h>
#ifdef	ABALAUDIO
#ifdef UNIX
#include <sys/soundcard.h>
#else
#include "soundcard.h"
#endif
#endif
#ifdef UNIX
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#endif
#include "wave.h"

#include "sound.c"

#ifdef ABALMP3
#include "mp3.c"
#endif

static	struct	wave_handle * WaveHeap=(struct wave_handle *) 0;

void	show_wave_header( struct wave_handle * wptr )

{
	if (!( wptr )) 
		return;
	else if (!( wptr->name ))
		return;
	else	{
		printf("Wave File Name : %s \r\n",wptr->name );
		printf("Wave File Type : ");
		switch ( wptr->nature ) {
			case	_FORMAT_NULL	:	printf(" NULL \r\n"); break;
			case	_FORMAT_WAVE	:	printf(" WAVE \r\n"); break;
			case	_FORMAT_AIFF 	:	printf(" AIFF \r\n"); break;
#ifdef	_mp3_c
			case	_FORMAT_MP3	:	printf(" MP3 \r\n" ); break;
#endif
#ifdef	_ogg_c
			case	_FORMAT_OGG	:	printf(" OGG \r\n" ); break;
#endif
			default			:	printf(" ???? \r\n"); break;
			}
		printf("File Size      : %lu\r\n",wptr->filesize);
		printf("Data Size      : %lu\r\n",wptr->datasize);
		printf("w Format       : %lu\r\n",wptr->formattag);
		printf("Channel Count  : %lu\r\n",wptr->channels );
		printf("Sample Rate    : %lu\r\n",wptr->samplerate);
		printf("Byte Rate      : %lu\r\n",wptr->byterate);
		printf("Block Align    : %lu\r\n",wptr->blockalign);
		printf("BitsPerSample  : %lu\r\n\n",wptr->bitspersample);
		return;
		}
}

unsigned 	int	getbeword(FILE * h)
{
	int	c;
	unsigned	int	value=0;
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (c & 0x00FF);
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (c  | ((value & 0x00FF) << 8));
	return( value );
}

unsigned 	int	getword(FILE * h)
{
	int	c;
	unsigned	int	value=0;
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (c & 0x00FF);
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (value  | ((c & 0x00FF) << 8));
	return( value );
}

short 	int	getbeshort(FILE * h)
{
	int	c;
	short 	int	value=0;
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (c & 0x00FF);
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (c  | ((value & 0x00FF) << 8));
	return( value );
}

short 	int	getshort(FILE * h)
{
	int	c;
	short int	value=0;
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (c & 0x00FF);
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (value  | ((c & 0x00FF) << 8));
	return( value );
}

unsigned 	long	getbelong(FILE * h)
{
	int	c;
	unsigned	long	value=0L;
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = ((c & 0x00FF) << 24);
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (value  | ((c & 0x00FF) << 16));
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (value | ((c & 0x00FF) << 8));
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (value | ((c & 0x00FF) ));
	return( value );
}

unsigned 	long	getlong(FILE * h)
{
	int	c;
	unsigned	long	value=0L;
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (c & 0x00FF);
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (value  | ((c & 0x00FF) << 8));
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (value | ((c & 0x00FF) << 16));
	if ((c = fgetc(h)) == -1)
		return( value );
	else 	value = (value | ((c & 0x00FF) << 24));
	return( value );
}

void	putlong(FILE * h, unsigned long v)
{
	int	c;
	c = (v & 0x00FF);
	fputc(c,h);
	c = ((v >> 8) & 0x00FF);
	fputc(c,h);
	c = ((v >> 16) & 0x00FF);
	fputc(c ,h);
	c = ((v >> 24) & 0x00FF);
	fputc(c,h);
	return;
}

void	bputlong(int h, unsigned long v)
{
	char	buffer[4];
	int	c;
	c = (v & 0x00FF);
	buffer[0] = c;
	c = ((v >> 8) & 0x00FF);
	buffer[1] = c;
	c = ((v >> 16) & 0x00FF);
	buffer[2] = c;
	c = ((v >> 24) & 0x00FF);
	buffer[3] = c;
	write(h,buffer,4);
	return;
}

void	putword(FILE * h, unsigned int  v)
{
	int	c;
	c = (v & 0x00FF);
	fputc(c,h);
	c = ((v >> 8) & 0x00FF);
	fputc(c,h);
	return;
}

void	putbyte(FILE * h, unsigned int  v)
{
	int	c;
	c = (v & 0x00FF);
	fputc(c,h);
	return;
}

int	get_wave_sample( struct wave_handle * wptr, int * lv, int * rv )
{
	int	v;

	/* end of data */
#ifdef	_mp3_c
	if ( wptr->nature == _FORMAT_MP3 )
		return( get_mp3_sample( wptr, lv, rv ) );
	else 
#endif	
	     if ( wptr->fileoffset++ >= wptr->samples )
		return(0);

	switch ( wptr->format ) {
#ifdef	AFMT_U8
		case	AFMT_U8		:	v = (fgetc(wptr->handle) & 0x00FF); 	break;
#endif
#ifdef	AFMT_S8
		case	AFMT_S8		: 	v = fgetc(wptr->handle);		break;
#endif
#ifdef	AFMT_U16_LE
		case	AFMT_U16_LE	:	v = getword(wptr->handle); 		break;
#endif
#ifdef	AFMT_S16_LE
		case	AFMT_S16_LE	:	v = getshort(wptr->handle); 		break;
#endif
#ifdef	AFMT_U32_LE
		case	AFMT_U32_LE	:
#endif
#ifdef	AFMT_S32_LE
		case	AFMT_S32_LE	:	v = getlong(wptr->handle);		break;
#endif
#ifdef	AFMT_U16_BE
		case	AFMT_U16_BE	:	v = getbeword(wptr->handle); 		break;
#endif
#ifdef	AFMT_S16_BE
		case	AFMT_S16_BE	:	v = getbeshort(wptr->handle); 		break;
#endif
#ifdef	AFMT_U32_BE
		case	AFMT_U32_BE	:
#endif
#ifdef	AFMT_S32_BE
		case	AFMT_S32_BE	:	v = getbelong(wptr->handle);		break;
#endif
		default			:	v = 0;
		}
	* lv = v;
	if ( wptr->channels > 1 ) {
		switch ( wptr->format ) {
#ifdef	AFMT_U8
			case	AFMT_U8		:	v = (fgetc(wptr->handle) & 0x00FF); 	break;
#endif
#ifdef	AFMT_S8
			case	AFMT_S8		: 	v = fgetc(wptr->handle);		break;
#endif
#ifdef	AFMT_U16_LE
			case	AFMT_U16_LE	:	v = getword(wptr->handle); 		break;
#endif
#ifdef	AFMT_S16_LE
			case	AFMT_S16_LE	:	v = getshort(wptr->handle); 		break;
#endif
#ifdef	AFMT_U32_LE
			case	AFMT_U32_LE	:
#endif
#ifdef	AFMT_S32_LE
			case	AFMT_S32_LE	:	v = getlong(wptr->handle);		break;
#endif
#ifdef	AFMT_U16_BE
			case	AFMT_U16_BE	:	v = getbeword(wptr->handle); 		break;
#endif
#ifdef	AFMT_S16_BE
			case	AFMT_S16_BE	:	v = getbeshort(wptr->handle); 		break;
#endif
#ifdef	AFMT_U32_BE
			case	AFMT_U32_BE	:
#endif
#ifdef	AFMT_S32_BE
			case	AFMT_S32_BE	:	v = getbelong(wptr->handle);		break;
#endif
			default			:	v = 0;
			}
		}
	*rv = v;
	return(1);
}

int	put_wave_sample( struct wave_handle * optr, int ohandle, int lsample, int rsample )
{
	if ( ohandle == -1 ) {
		optr->fileoffset++;
		optr->samples++;
		switch ( optr->format ) {
#ifdef	AFMT_U8
			case	AFMT_U8		:
#endif
#ifdef	AFMT_S8
			case	AFMT_S8		: putbyte(optr->handle,lsample); 		break;
#endif
#ifdef	AFMT_U16_LE
			case	AFMT_U16_LE	:
#endif
#ifdef	AFMT_S16_LE
			case	AFMT_S16_LE	: putword(optr->handle,lsample);		break;
#endif
#ifdef	AFMT_U32_LE
			case	AFMT_U32_LE	:
#endif
#ifdef	AFMT_S32_LE
			case	AFMT_S32_LE	: putlong(optr->handle,lsample );		break;
#endif
			default			: break;
			}
		if ( optr->channels > 1 ) {
			switch ( optr->format ) {
#ifdef	AFMT_U8
				case	AFMT_U8		:
#endif
#ifdef	AFMT_S8
				case	AFMT_S8		: putbyte(optr->handle,rsample); 	break;
#endif
#ifdef	AFMT_U16_LE
				case	AFMT_U16_LE	:
#endif
#ifdef	AFMT_S16_LE
				case	AFMT_S16_LE	: putword(optr->handle,rsample);	break;
#endif
#ifdef	AFMT_U32_LE
				case	AFMT_U32_LE	:
#endif
#ifdef	AFMT_S32_LE
				case	AFMT_S32_LE	: putlong(optr->handle,rsample );	break;
#endif
				default			: break;
				}
			}
		return(0);
		}
	else	{
		switch ( optr->format ) {
#ifdef	AFMT_U8
			case	AFMT_U8		:
#endif
#ifdef	AFMT_S8
			case	AFMT_S8		: outputbyte(ohandle,lsample); 		break;
#endif
#ifdef	AFMT_U16_LE
			case	AFMT_U16_LE	:
#endif
#ifdef	AFMT_S16_LE
			case	AFMT_S16_LE	: outputword(ohandle,lsample);		break;
#endif
#ifdef	AFMT_U32_LE
			case	AFMT_U32_LE	:
#endif
#ifdef	AFMT_S32_LE
			case	AFMT_S32_LE	: outputlong(ohandle,lsample );		break;
#endif
			default			: break;
			}
		if ( optr->channels > 1 ) {
			switch ( optr->format ) {
#ifdef	AFMT_U8
				case	AFMT_U8		:
#endif
#ifdef	AFMT_S8
				case	AFMT_S8		: outputbyte(ohandle,rsample); 		break;
#endif
#ifdef	AFMT_U16_LE
				case	AFMT_U16_LE	:
#endif
#ifdef	AFMT_S16_LE
				case	AFMT_S16_LE	: outputword(ohandle,rsample);		break;
#endif
#ifdef	AFMT_U32_LE
				case	AFMT_U32_LE	:
#endif
#ifdef	AFMT_S32_LE
				case	AFMT_S32_LE	: outputlong(ohandle,rsample );		break;
#endif
				default			: break;
				}
			}
		return(0);
		}
}

void	reset_wave_handle( struct wave_handle * wptr )
{
	wptr->handle 		= (FILE *) 0;
	wptr->nature		= _FORMAT_NULL;
	wptr->filesize   	= 0L;
	wptr->fileoffset	= 0L;
	wptr->datasize   	= 0L;
	wptr->formattag		= 0;
	wptr->channels		= 0;
	wptr->samplerate	= 0;
	wptr->samples		= 0L;
	wptr->byterate  	= 0;
	wptr->blockalign	= 0;
	wptr->bitspersample	= 0;
	wptr->format		= 0;
	wptr->name		= (char *) 0;
	wptr->next		= (struct wave_handle *) 0;
	wptr->complex		= (void *) 0;
	return;
}

void	write_wave_header( struct wave_handle * wptr )
{
	fseek(wptr->handle,0L,SEEK_SET);
	fprintf(wptr->handle,"RIFF");
	putlong(wptr->handle,wptr->filesize);
	fprintf(wptr->handle,"WAVE");
	fprintf(wptr->handle,"fmt ");
	putlong(wptr->handle,16);
	putword(wptr->handle,wptr->formattag);
	putword(wptr->handle,wptr->channels);
	putlong(wptr->handle,wptr->samplerate);
	putlong(wptr->handle,wptr->byterate);
	putword(wptr->handle,wptr->blockalign);
	putword(wptr->handle,wptr->bitspersample);
	fprintf(wptr->handle,"data");
	putlong(wptr->handle,wptr->datasize);
}
		
struct	wave_handle * 	close_wave_file( struct wave_handle * wptr )
{
	if ( wptr ) {
		if ( wptr->complex ) {
			switch ( wptr->nature ) {
#ifdef	_mp3_c
				case	_FORMAT_MP3	:
					close_mp3_file( wptr );
					break;
#endif
#ifdef	_ogg_c
				case	_FORMAT_OGG	:
					close_ogg_file( wptr );
					break;
#endif
				default			:
					wptr->complex = (void *) 0;
				}
			}
		if ( wptr->name ) {
			free( wptr->name );
			}
		if ( wptr->handle )
			fclose( wptr->handle );
		reset_wave_handle( wptr );			
		wptr->next = WaveHeap;
		WaveHeap = wptr;
		}
	return((struct wave_handle*) 0);
}

struct	wave_handle * 	terminate_wave_file( struct wave_handle * wptr )
{
	wptr->datasize = (wptr->samples * wptr->channels * (wptr->bitspersample/8));
	wptr->filesize = (wptr->datasize + 38);
	write_wave_header(wptr);
	wptr = close_wave_file( wptr );
	return( wptr );
}


struct	wave_handle * 	consume_aiff_header( struct wave_handle * wptr )
{
	int	c;
	int	i;
	char	chunk[4];
	unsigned char	extended[10];
	unsigned long	size;

	wptr->nature = _FORMAT_AIFF;

	if ( sbecho )
		printf("consume aiff header\r\n");

	while (1) {

		/* read chunk type and size or error */
		/* --------------------------------- */
		if ( fread(chunk,4,1,wptr->handle) != 1)
			return( close_wave_file( wptr ) );
		if (!( size = getbelong( wptr->handle )))
			return( close_wave_file( wptr ) );

		/* detect and handle format chunks */
		/* ------------------------------- */
		if (( chunk[0] == 'C' )
		&&  ( chunk[1] == 'O' )
		&&  ( chunk[2] == 'M' )
		&&  ( chunk[3] == 'M' )) {

			if ( sbecho )
				printf("aiff COMM header chunk \r\n");
			wptr->channels = getbeword( wptr->handle );
			wptr->samples  = getbelong( wptr->handle );

			if (( wptr->bitspersample = getbeword( wptr->handle )) <= 8) {
#ifdef	AFMT_U8
				wptr->format = AFMT_U8;
#else
				wptr->format = 0;
#endif
				}
			else if ( wptr->bitspersample <= 16 ) {
#ifdef	AFMT_S16_BE
				wptr->format = AFMT_S16_BE;
#else
				wptr->format = 0;
#endif
				}
			else if ( wptr->bitspersample <= 24 ) {
#ifdef	AFMT_S24_BE
				wptr->format = AFMT_S24_BE;
#else
				wptr->format = 0;
#endif
				}
			else if ( wptr->bitspersample <= 32 ) {
#ifdef	AFMT_S32_BE
				wptr->format = AFMT_S32_BE; 
#else
				wptr->format = 0;
#endif
				}

			if ( fread( extended,10,1,wptr->handle ) != 1 )
				return( close_wave_file( wptr ) );

			if (( extended[0] == 0x040 )
			&&  ( extended[1] == 0x00C )
			&&  ( extended[2] == 0x0AC )
			&&  ( extended[3] == 0x044 )) 
					wptr->samplerate = 11025;

			else if (( extended[0] == 0x040 )
			     &&  ( extended[1] == 0x00D )
			     &&  ( extended[2] == 0x0AC )
		   	     &&  ( extended[3] == 0x044 )) 

					wptr->samplerate = 22050;

			else if (( extended[0] == 0x040 )
			     &&  ( extended[1] == 0x00E )
			     &&  ( extended[2] == 0x0AC )
		   	     &&  ( extended[3] == 0x044 )) 
				wptr->samplerate = 44100;
			else	wptr->samplerate = 44100;

			if ( sbecho )
				show_wave_header( wptr );
		
			continue;
			}

		/* detect and handle data chunk */
		/* ---------------------------- */
		else if (( chunk[0] == 'S' )
		     &&  ( chunk[1] == 'S' )
		     &&  ( chunk[2] == 'N' )
		     &&  ( chunk[3] == 'D' )) {
			if ( sbecho )
				printf("aiff SSND data chunk\r\n");

			wptr->datasize = size;
			return( wptr );

			}
		else	{
			if ( sbecho )
				printf("unsupported chunk\r\n");
			/* Step over unsupported chunk */
			/* --------------------------- */
			for (i=0; i < size; i++ )
				if ((c = fgetc(wptr->handle)) == -1)
					return( close_wave_file( wptr ) );
			continue;
			}
		}
}

struct	wave_handle * 	consume_wave_header( struct wave_handle * wptr )
{
	int	c;
	int	i;
	char	chunk[4];
	unsigned long	size;

	wptr->nature = _FORMAT_WAVE;

	while (1) {

		/* read chunk type and size or error */
		/* --------------------------------- */
		if ( fread(chunk,4,1,wptr->handle) != 1)
			return( close_wave_file( wptr ) );
		if (!( size = getlong( wptr->handle )))
			return( close_wave_file( wptr ) );

		/* detect and handle format chunks */
		/* ------------------------------- */
		if (( chunk[0] == 'f' )
		&&  ( chunk[1] == 'm' )
		&&  ( chunk[2] == 't' )
		&&  ( chunk[3] == ' ' )) {

			/* collect format information */
			/* -------------------------- */
			if ( sbecho )
				printf("fmt chunk\r\n");
			wptr->formattag 	= getword( wptr->handle );
			wptr->channels  	= getword( wptr->handle );
			wptr->samplerate  	= getlong( wptr->handle );
			wptr->byterate  	= getlong( wptr->handle );
			wptr->blockalign	= getword( wptr->handle );

			if (( wptr->bitspersample = getword( wptr->handle )) <= 8) {
#ifdef	AFMT_U8
				wptr->format = AFMT_U8;
#else
				wptr->format = 0;
#endif
				}

			else if ( wptr->bitspersample <= 16 ) {
#ifdef	AFMT_S16_LE
				wptr->format = AFMT_S16_LE;
#else
				wptr->format = 0;
#endif
				}
			else if ( wptr->bitspersample <= 24 ) {
#ifdef	AFMT_S32_LE
				wptr->format = AFMT_S24_LE;
#else
				wptr->format = 0;
#endif
				}
			else if ( wptr->bitspersample <= 32 ) {
#ifdef	AFMT_S32_LE
				wptr->format = AFMT_S32_LE;
#else
				wptr->format = 0;
#endif
				}

			/* detect and handle compression */
			/* ----------------------------- */
			if ( wptr->formattag != 1 ) {
				if ( sbecho )
					printf("incorrect compression\r\n");
				size = getword( wptr->handle );
				for ( i=0; i < size; i++ )
				if ((c = fgetc(wptr->handle)) == -1)
					return( close_wave_file( wptr ) );

				}

			continue;
			}

		/* detect and handle data chunk */
		/* ---------------------------- */
		else if (( chunk[0] == 'd' )
		     &&  ( chunk[1] == 'a' )
		     &&  ( chunk[2] == 't' )
		     &&  ( chunk[3] == 'a' )) {
			if ( sbecho )
				printf("data chunk\r\n");
			wptr->datasize = size;
			wptr->samples = (wptr->datasize / wptr->blockalign);
			return( wptr );
			}
		else	{
			if ( sbecho )
				printf("unsupported chunk\r\n");
			/* Step over unsupported chunk */
			/* --------------------------- */
			for (i=0; i < size; i++ )
				if ((c = fgetc(wptr->handle)) == -1)
					return( close_wave_file( wptr ) );
			continue;
			}
		}
}


struct	wave_handle *	allocate_wave_handle( )
{
	struct	wave_handle * wptr;
	
	if (( wptr = WaveHeap ) != (struct wave_handle *) 0)
		WaveHeap = wptr->next;
	else if (!( wptr = malloc( sizeof( struct wave_handle ) ) ))
		return( wptr );
	
	reset_wave_handle( wptr );
	return( wptr );
}

static	int	check_pattern( char * sptr, char * pptr )
{
	while ( *pptr ) 
		if ( *(sptr++)  != *(pptr++) )
			return(0);
		
	return(1);
}

struct	wave_handle *	open_wave_file( char * nptr )
{
	struct	wave_handle * wptr;
	char	signature[4];

	if (!( wptr = allocate_wave_handle() )) {
		return( wptr );
		}

	if (!( wptr->handle = fopen( nptr, "rb" )))
		return( close_wave_file( wptr ) );
	else if (!( wptr->name = malloc( strlen( nptr ) + 1 ) ))
		return( close_wave_file( wptr ) );
	else if ( fread(signature,4,1,wptr->handle) != 1)
		return( close_wave_file( wptr ) );
	else	{
		strcpy( wptr->name, nptr );
		if ( check_pattern(signature, "RIFF" ) ) {
			if (!( wptr->filesize = getlong( wptr->handle ) ))
				return( close_wave_file( wptr ) );
			else if ( fread(signature,4,1,wptr->handle) != 1)
				return( close_wave_file( wptr ) );
			else if ( check_pattern(signature, "WAVE" ) ) {
				return( consume_wave_header( wptr ) );
				}
			else	return( close_wave_file( wptr ) );
			}
		else if ( check_pattern(signature, "FORM" ) ) {
			if (!( wptr->filesize = getbelong( wptr->handle ) ))
				return( close_wave_file( wptr ) );
			else if ( fread(signature,4,1,wptr->handle) != 1)
				return( close_wave_file( wptr ) );
			else if ( check_pattern(signature, "AIFF" ) ) {
				return( consume_aiff_header( wptr ) );
				}
			else	return( close_wave_file( wptr ) );
			}
#ifdef	_mp3_c
		else 	return( consume_mp3_header( wptr ) );
#else
		else	return( close_wave_file( wptr ) );
#endif
		}
}
	
int	read_wave_block(struct wave_handle * wptr, unsigned char * bptr, int blen ) 
{
	if (!( wptr ))
		return(0);
	else	{
		switch ( wptr->nature ) {
			case	_FORMAT_WAVE	:
			case	_FORMAT_AIFF	:
				return(  fread( bptr, 1, blen , wptr->handle) );
#ifdef	_mp3_c
			case	_FORMAT_MP3	:
				return(  read_mp3_block( wptr, bptr, blen ) );
#endif
#ifdef	_ogg_c
			case	_FORMAT_OGG	:
				return( read_off_block( wptr, bptr, blen ) );
#endif
			case	_FORMAT_NULL	:
			default			:
				return(0);
			}
		}
}




struct	wave_handle *	create_wave_file( char * nptr, int speed, int format, int channels )
{
	struct	wave_handle * wptr;


	if (!( wptr = allocate_wave_handle() ))
		return( wptr );

	if (!( wptr->handle = fopen( nptr, "wb" )))
		return( close_wave_file( wptr ) );
	else if (!( wptr->name = malloc( strlen( nptr ) + 1 ) ))
		return( close_wave_file( wptr ) );
	else	{
		wptr->formattag=1;
		wptr->channels=channels;
		wptr->samplerate=speed;
		wptr->byterate=(speed*channels*format);
		wptr->blockalign=(channels*format);
		wptr->bitspersample=(format*8);
		strcpy( wptr->name, nptr );
		write_wave_header( wptr );
		if (  wptr->bitspersample  <= 8) {
#ifdef	AFMT_S8
			wptr->format = AFMT_U8;
#else
			wptr->format = 0;
#endif
			}
		else if ( wptr->bitspersample <= 16 ) {
#ifdef	AFMT_S16_LE
			wptr->format = AFMT_S16_LE;
#else
			wptr->format = 0;
#endif
			}
		else if ( wptr->bitspersample <= 24 ) {
#ifdef	AFMT_S24_LE
			wptr->format = AFMT_S24_LE;
#else
			wptr->format = 0;
#endif
			}
		else if ( wptr->bitspersample <= 32 ) {
#ifdef	AFMT_S32_LE
			wptr->format = AFMT_S32_LE;
#else
			wptr->format = 0;
#endif
			}
		return( wptr );
		}
}
	
#endif	/* _wave_c */
	/* ------- */

