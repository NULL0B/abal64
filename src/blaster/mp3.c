#ifndef	_mp3_c
#define	_mp3_c

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#include "mp3dec.h"

static	int	aBitrate[2][16] = {
		{ 0,32,40,48,56,64,80,96,112,128,160,192,224,256,320,0 },
		{ 0, 8,16,24,32,64,80,56, 64,128,160,112,128,256,320,0 }
		};

static	int aFrequency[2][4] = {
		{ 44100,48000,32000,0 },
		{ 22050,24000,16000,0 }
		};

struct	mp3_handle	{
	MPEG_DECODE_INFO	MP3DI;
	MPEG_DECODE_PARAM	MP3DP;
	int			NowPos;
	int			Indent;
	int			Loaded;
	unsigned char *		Buffer;
	int			MpegSpec;
	int			BitRate;
	int			Frequency;
	int			Channel;
	int			FileSize;
	int			FrameSize;
	unsigned char *		FrameData;
	unsigned char *		FileData;
	};

void	close_mp3_handle( struct mp3_handle *	mptr )
{
	if ( mptr ) {
		if ( mptr->Buffer )
			free( mptr->Buffer );
		if ( mptr->FileData )
			free(mptr->FileData);
		free( mptr );
		}
	return;
}

struct	wave_handle *	consume_mp3_header( struct wave_handle * wptr )
{
	struct stat		S;
	FILE 		  * 	h;
	struct mp3_handle *	mptr;

	if (!( mptr = malloc( sizeof( struct mp3_handle ) )))
		return( close_wave_file( wptr ) );
	else	{
		mptr->NowPos   = 0;
		mptr->Loaded   = 0;
		mptr->Indent   = 0;
		mptr->Buffer   = (unsigned char *) 0;
		mptr->MpegSpec = 0;
		mptr->BitRate  = 0;
		mptr->Frequency= 0;
		mptr->Channel  = 0;
		mptr->FileSize = 0;
		mptr->FrameData= (unsigned char *) 0;
		mptr->FileData = (unsigned char *) 0;

		if ( stat( wptr->name, &S ) < 0) {
			close_mp3_handle( mptr );
			return(close_wave_file( wptr ));
			}
		else if (!( h = fopen( wptr->name, "r" ) )) {
			close_mp3_handle( mptr );
			return(close_wave_file( wptr ));
			}
		else if (!( mptr->FrameData = malloc((mptr->FileSize = S.st_size)) )) {
			close_mp3_handle( mptr );
			fclose(h);
			return(close_wave_file( wptr ));
			}

		else if ( fread((mptr->FileData = mptr->FrameData),S.st_size,1,h) < 1 ) {
			close_mp3_handle( mptr );
			fclose(h);
			return(close_wave_file(wptr));
			}
		else	{
			fclose(h);
			for ( ; mptr->FileSize != 0; mptr->FileSize-- ) {
				if ( ( *mptr->FrameData & 0x00FF ) == 0x00FF )
					break; 
				else	mptr->FrameData++;
				}
			mptr->MpegSpec	= (((mptr->FrameData[1] & 8) == 0) ? 1 : 0);
			mptr->BitRate	= aBitrate[ mptr->MpegSpec ][ mptr->FrameData[2] >> 4 ];
			mptr->Frequency	= aFrequency[ mptr->MpegSpec ][ (mptr->FrameData[2] >> 2) & 3 ];
			mptr->Channel	= ((mptr->FrameData[3] >> 6 == 3) ? 1 : 2);
			mptr->FrameSize	= 144000 * mptr->BitRate / mptr->Frequency;
			mp3DecodeInit();
			if (!(  mp3GetDecodeInfo(mptr->FrameData,mptr->FrameSize,&mptr->MP3DI,1) )) {
				close_mp3_handle( mptr );
				return(close_wave_file(wptr));
				}
			else if (!( mptr->Buffer = malloc(mptr->MP3DI.outputSize) )) {
				close_mp3_handle( mptr );
				return(close_wave_file(wptr));
				}
			else	{
				mp3DecodeStart(mptr->FrameData,mptr->FileSize);
				wptr->channels  	= mptr->Channel;
				wptr->samplerate  	= mptr->Frequency;
				wptr->byterate  	= ((mptr->Frequency * mptr->Channel) * 2);
				wptr->blockalign	= 0;
				wptr->bitspersample 	= 16;
				wptr->format 		= AFMT_S16_LE;
				wptr->complex 		= (void *) mptr;
				wptr->nature		= _FORMAT_MP3;
				return( wptr );
				}
			}
		}
}

int			read_mp3_block( struct wave_handle * wptr, char * bptr, int blen )
{
	int			total=0;
	int			xfer;
	struct mp3_handle *	mptr;
	if (!( wptr ))
		return(0);
	else if (!( mptr = wptr->complex ))
		return(0);

	while (blen != 0) {

		if ( mptr->Indent < mptr->Loaded ) {
			if ( blen <= (mptr->Loaded - mptr->Indent))
				xfer = blen;
			else	xfer = (mptr->Loaded - mptr->Indent);
			memcpy( bptr, (mptr->Buffer + mptr->Indent), xfer );
			bptr		+= xfer;
			blen 		-= xfer;
			mptr->Indent 	+= xfer;
			total		+= xfer;
			}
		else if (!( mp3GetDecodeInfo(mptr->FrameData + mptr->NowPos,mptr->FrameSize,&mptr->MP3DI,1) ))
			break;
		else	{
			mptr->MP3DP.header	=	mptr->MP3DI.header;
			mptr->MP3DP.bitRate	=	mptr->MP3DI.bitRate;
			mptr->MP3DP.inputBuf	=	mptr->FrameData + mptr->NowPos;
			mptr->MP3DP.inputSize	=	mptr->MP3DI.header.padding ? mptr->MP3DI.maxInputSize : mptr->MP3DI.minInputSize;
			mptr->MP3DP.outputBuf	=	mptr->Buffer;
			mptr->MP3DP.outputSize	=	mptr->MP3DI.outputSize;
			mp3DecodeFrame(&mptr->MP3DP);
			mptr->NowPos += ( mptr->MP3DI.header.padding ? mptr->MP3DI.maxInputSize : mptr->MP3DI.minInputSize);
			mptr->Loaded = mptr->MP3DI.outputSize;
			mptr->Indent = 0;
			}
		}
	return(total);
}

int	get_mp3_sample( struct wave_handle * wptr, int * lv, int * rv )
{
	unsigned int	v;
	int	l;
	unsigned char samples[8];
	l = (2 * wptr->channels);
	if (!( read_mp3_block( wptr, samples, l ) ))
		return(0);

	switch ( wptr->format ) {
		case	AFMT_S16_LE	:
			v = (samples[0] | ( samples[1] << 8 ));
			break;
		case	AFMT_S16_BE	:
			v = (samples[1] | ( samples[0] << 8 ));
			break;
		 }
	*lv = v;

	if ( wptr->channels > 1 ) {
		switch ( wptr->format ) {
			case	AFMT_S16_LE	:
				v = (samples[0] | ( samples[1] << 8 ));
				break;
			case	AFMT_S16_BE	:
				v = (samples[1] | ( samples[0] << 8 ));
				break;
			 }
		*rv = v;
		}
	return(1);
}

void			close_mp3_file( struct wave_handle * wptr )
{
	if ( wptr )
		close_mp3_handle( wptr->complex );
	return;
}

#endif	/* _mp3_c */
	/* ------ */

