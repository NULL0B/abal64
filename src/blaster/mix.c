#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/soundcard.h>

#define	MAX_BUFFER_SIZE 0x80000
#define	MAX_TRACKS	32

char	buffer[MAX_BUFFER_SIZE];

int	verbose=0;
int	level=100;
char *	target="/dev/dsp0";
char *	outputname="output.wav";
int	directout=1;
int	outputhandle=-1;

void	*	malloc(int);
void		free( void *);

struct	track_control	{
	char		    *	name;
	struct	wave_handle * 	sample;
	int			active;
	int			solo;
	int			mute;
	int			level;
	} Track[MAX_TRACKS];

struct	wave_handle *	Output=(struct wave_handle *) 0;

int			Tracks=0;
unsigned long		MaxSamples=0L;

#include "wave.c"
#include "sound.c"

void	failure(char * message)
{
	printf("failure : %s : %u\n",message,errno);
	return;
}


void	initialise()
{
	int	i;
	for ( i=0; i < Tracks; i++ ) {
		Track[i].name   = (char *) 0;
		Track[i].sample = (struct wave_handle *) 0;
		Track[i].solo=0;
		Track[i].mute=0;
		Track[i].level=level;
		Track[i].active=1;
		}
	Output=(struct wave_handle *) 0;
	Tracks=0;
	return;
}

void	terminate()
{
	int	i;
	for ( i=0; i < Tracks; i++ ) {
		if (!( Track[i].sample ))
			continue;
		else	Track[i].sample = close_wave_file( Track[i].sample );
		}
	if ( directout )
		outputhandle = closeoutput( outputhandle );
	if ( Output )
		Output = terminate_wave_file( Output );
	Tracks=0;
	return;
}

int	operate( char * nptr )
{
	struct	wave_handle * wptr;
	if ( Tracks >= MAX_TRACKS )
		return( 56 );
	else if (!( wptr = open_wave_file( nptr )))
		return(40);
	else	{
		if ( verbose )
			printf("track : %02.1u : %s \n",Tracks,wptr->name);
		Track[Tracks].mute = Track[Tracks].solo = 0;
		Track[Tracks].active=1;
		Track[Tracks].level=level;
		Track[Tracks++].sample = wptr;
		if ( wptr->samples > MaxSamples )
			MaxSamples = wptr->samples;
		return(0);
		}
}




int	use_sample( struct wave_handle * wptr, int l, int r, int nsample )
{
	if ( verbose )
		printf("( %d,%d ->",l,r);
	l /= nsample;
	r /= nsample;
	if ( verbose )
		printf(" %d,%d )\r\n",l,r);
	switch ( wptr->format ) {
		case	AFMT_U8		:
		case	AFMT_S8		: fputc((l&0x00FF),wptr->handle); 	break;
		case	AFMT_U16_LE	:
		case	AFMT_S16_LE	: putword(wptr->handle,(l & 0x0FFFF));	break;
		case	AFMT_U32_LE	:
		case	AFMT_S32_LE	: putlong(wptr->handle,l );		break;
		}
	if ( wptr->channels > 1 ) {
		switch ( wptr->format ) {
			case	AFMT_U8		:
			case	AFMT_S8		: fputc(( r & 0x00FF),wptr->handle); 	break;
			case	AFMT_U16_LE	:
			case	AFMT_S16_LE	: putword(wptr->handle,(r & 0x0FFFF));	break;
			case	AFMT_U32_LE	:
			case	AFMT_S32_LE	: putlong(wptr->handle,r );		break;
			}
		}
	wptr->datasize += wptr->blockalign;
	return(0);
}
	
int	directaction()
{
	struct 	wave_handle * wptr;
	int	i;
	int	v;
	int	nsample,lsample,rsample,xsample=0;
	if (!( outputname ))
		outputname = "output.wav";
	if (!( Output = create_wave_file( outputname, 44100,2,2 ) ))
		return(27);
	else if (!(xsample = Tracks ))
		return(0);
	else if ( directout ) {
		if ((outputhandle = openoutput(target,Output->samplerate,Output->channels,Output->format)) == -1)
			return(56);
		}
	while (xsample) {
		nsample=lsample=rsample=0;
		for (i=0; i < Tracks; i++ ) {
			if (!( Track[i].active ))
				continue;
			else if ( Track[i].mute )
				continue;
			else if (!( wptr = Track[i].sample ))
				continue;
			else if ( wptr->fileoffset++ >= wptr->samples ) {
				Track[i].active=0;
				xsample--;
				}
			else	{
				switch ( wptr->format ) {
					case	AFMT_U8		:	v = (fgetc(wptr->handle) & 0x00FF); 	break;
					case	AFMT_S8		: 	v = fgetc(wptr->handle);		break;
					case	AFMT_U16_LE	:	v = getword(wptr->handle); 		break;
					case	AFMT_S16_LE	:	v = getshort(wptr->handle); 		break;
					case	AFMT_U32_LE	:
					case	AFMT_S32_LE	:	v = getlong(wptr->handle);		break;
					}
				lsample += ((v * level)/100);
				if ( wptr->channels > 1 ) {
					switch ( wptr->format ) {
						case	AFMT_U8		:	v = (fgetc(wptr->handle) & 0x00FF); 	break;
						case	AFMT_S8		: 	v = fgetc(wptr->handle);		break;
						case	AFMT_U16_LE	:	v = getword(wptr->handle); 		break;
						case	AFMT_S16_LE	:	v = getshort(wptr->handle); 		break;
						case	AFMT_U32_LE	:
						case	AFMT_S32_LE	:	v = getlong(wptr->handle);		break;
						}
					}
				rsample += ((v * level)/100);
				nsample++;
				}
			}
		if (!( nsample ))
			break;
		lsample /= nsample;
		rsample /= nsample;
		switch ( wptr->format ) {
			case	AFMT_U8		:
			case	AFMT_S8		: outputbyte(outputhandle,lsample); 		break;
			case	AFMT_U16_LE	:
			case	AFMT_S16_LE	: outputword(outputhandle,lsample);		break;
			case	AFMT_U32_LE	:
			case	AFMT_S32_LE	: outputlong(outputhandle,lsample );		break;
			}
		if ( wptr->channels > 1 ) {
			switch ( wptr->format ) {
				case	AFMT_U8		:
				case	AFMT_S8		: outputbyte(outputhandle,rsample); 		break;
				case	AFMT_U16_LE	:
				case	AFMT_S16_LE	: outputword(outputhandle,rsample);		break;
				case	AFMT_U32_LE	:
				case	AFMT_S32_LE	: outputlong(outputhandle,rsample );		break;
				}
			}

		}
	return(0);

}

int	fileaction()
{
	struct 	wave_handle * wptr;
	int	i;
	int	v;
	int	nsample,lsample,rsample,xsample=0;
	if (!( outputname ))
		outputname = "output.wav";
	if (!( Output = create_wave_file( outputname, 44100,2,2 ) ))
		return(27);
	else if (!(xsample = Tracks ))
		return(0);
	if ( verbose )
		printf("mixing down to %s\r\n",outputname);
	while (xsample) {
		nsample=lsample=rsample=0;
		for (i=0; i < Tracks; i++ ) {
			if (!( Track[i].active ))
				continue;
			else if ( Track[i].mute )
				continue;
			else if (!( wptr = Track[i].sample ))
				continue;
			else if ( wptr->fileoffset++ >= wptr->samples ) {
				Track[i].active=0;
				xsample--;
				}
			else	{
				switch ( wptr->format ) {
					case	AFMT_U8		:	v = (fgetc(wptr->handle) & 0x00FF); 	break;
					case	AFMT_S8		: 	v = fgetc(wptr->handle);		break;
					case	AFMT_U16_LE	:	v = getword(wptr->handle); 		break;
					case	AFMT_S16_LE	:	v = getshort(wptr->handle); 		break;
					case	AFMT_U32_LE	:
					case	AFMT_S32_LE	:	v = getlong(wptr->handle);		break;
					}
				lsample += ((v * level)/100);
				if ( wptr->channels > 1 ) {
					switch ( wptr->format ) {
						case	AFMT_U8		:	v = (fgetc(wptr->handle) & 0x00FF); 	break;
						case	AFMT_S8		: 	v = fgetc(wptr->handle);		break;
						case	AFMT_U16_LE	:	v = getword(wptr->handle); 		break;
						case	AFMT_S16_LE	:	v = getshort(wptr->handle); 		break;
						case	AFMT_U32_LE	:
						case	AFMT_S32_LE	:	v = getlong(wptr->handle);		break;
						}
					}
				rsample += ((v * level)/100);
				nsample++;
				}
			}
		if (!( nsample ))
			break;
		else 	use_sample( Output, lsample, rsample, nsample );
		}
	return(0);

}


int	option( char * aptr )
{
	if ( *aptr == 'a' )
		target = "/dev/audio0";
	else if ( *aptr == 'v' )
		verbose = 1;
	else if ( *aptr == 'o' ) {
		directout=0;
		outputname = (aptr+1);
		}
	else if ( *aptr == 'l' )
		level = atoi((aptr+1));
	return(0);
}

int	doit( int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	int	status=0;
	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' )
			option((aptr+1));
		else if (!( status = operate(aptr)))
			continue;
		else	break;
		}
	if (!( status )) {
		if ( directout )
			directaction();	
		else	fileaction();
		}
	terminate();
	return(0);
	
}

int	banner()
{
	printf("\nmix wave files : version 1.0a.0.01");
	printf("\nprovisoire 21/09/2004\n");
	return(0);
}

int	main( int argc, char * argv[] )
{
	initialise();
	if ( argc == 1 )
		return( banner() );
	else	return( doit(argc,argv) );

}



