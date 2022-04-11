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

MPEG_DECODE_INFO	MP3DI;
MPEG_DECODE_PARAM	MP3DP;
int			NowPos=0;
unsigned char *			Buffer=(unsigned char *) 0;
int			MpegSpec=0;
int			BitRate=0;
int			Frequency=0;
int			Channel=0;
int			FileSize=0;
int			FrameSize=0;
unsigned char *			FrameData=(unsigned char *) 0;
unsigned char *			FileData=(unsigned char *) 0;

int	mp3_player(unsigned char * aptr)
{
	FILE *	h;
	struct stat	S;
	if ( stat( aptr, &S ) < 0)
		return( errno );
	else if (!( h = fopen( aptr, "r" ) ))
		return( 40 );
	else if (!( FrameData = malloc((FileSize = S.st_size)) )) {
		fclose(h);
		return(27);
		}
	else if ( fread((FileData = FrameData),S.st_size,1,h) < 1 ) {
		free(FileData);
		fclose(h);
		return(48);
		}
	else	{
		fclose(h);

		for ( ; FileSize != 0; FileSize-- ) {
			if ( ( *FrameData & 0x00FF ) == 0x00FF )
				break; 
			else	FrameData++;
			}

		MpegSpec	= ((FrameData[1] & 8) == 0) ? 1 : 0;
		BitRate		= aBitrate[ MpegSpec ][ FrameData[2] >> 4 ];
		Frequency	= aFrequency[ MpegSpec ][ (FrameData[2] >> 2) & 3 ];
		Channel		= (FrameData[3] >> 6 == 3) ? 1 : 2;
		FrameSize	= 144000 * BitRate / Frequency;

		mp3DecodeInit();
		if ( mp3GetDecodeInfo(FrameData,FrameSize,&MP3DI,1) != 0 ) {
			if ((Buffer = malloc(MP3DI.outputSize)) != (unsigned char *) 0) {
				mp3DecodeStart(FrameData,FileSize);
				while( mp3GetDecodeInfo(FrameData + NowPos,FrameSize,&MP3DI,1) != 0) {
					MP3DP.header			=	MP3DI.header;
					MP3DP.bitRate			=	MP3DI.bitRate;
					MP3DP.inputBuf			=	FrameData + NowPos;
					MP3DP.inputSize			=	MP3DI.header.padding ? MP3DI.maxInputSize : MP3DI.minInputSize;
					MP3DP.outputBuf			=	Buffer;
					MP3DP.outputSize		=	MP3DI.outputSize;
					mp3DecodeFrame(&MP3DP);
					/* we over-write the same output buffer for the moment */
					NowPos += MP3DI.header.padding ? MP3DI.maxInputSize : MP3DI.minInputSize;
					}
				free(Buffer);
				}
			}
		free( FileData );
		return(0);
		}
}

int	option(unsigned char * aptr)
{
	return(0);
}

int	operation(int argc, unsigned char * argv[] )
{
	int	argi;
	unsigned char * 	aptr;
	int	status=0;
	for (	argi=1; argi < argc; argi++ ) {
		if (!( aptr =argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			if ((status = option(aptr+1)) != 0)
				return(status);
			else	continue;
			}
		else if ((status = mp3_player( aptr )) != 0)
			return(status);
		else	continue;
		}
	return(0);
}

int	banner()
{
	printf("\n   MP3 Player : Version 1.0a ");
	printf("\n   Provisoire du 26/03/2008  ");
	printf("\n   Copyright (c) 2008 IJM   \n\n");
	return(0);
}


int	main(int argc, unsigned char * argv[] )
{
	if ( argc == 1 )
		return(banner());
	else	return(operation(argc,argv));
}


