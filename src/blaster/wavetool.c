#include <stdio.h>
#include <stdlib.h>
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
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <signal.h>
#endif

#define	MAX_BUFFER_SIZE 0x8000

int	sbecho=0;
int	sbinfo=0;
int	verbose=0;
int	gapsize=0;
int	splice=0;
int	samples=0;
int	maxsamples=0;
int	filenumber=0;
char	outname[1024];

char *	targetname="output.wav";

static	struct	wave_handle * output=(struct wave_handle *) 0;

#include "wave.h"
#include "wave.c"

static	void	terminate_output()
{
	if ( output ) {
		terminate_wave_file( output );
		output = (struct wave_handle *) 0;
		}
	return;
}

int	start_output( struct wave_handle * wptr )
{
	if (!( output )) 
	{

		if ( splice )
		{
			sprintf(outname,"%s%u.wav",targetname,++filenumber );
			maxsamples = wptr->samplerate * splice;
			samples = maxsamples;
		}
		else	strcpy( outname, targetname );

		if ( verbose )
			printf("creating audio file : %s \n",outname);

		if (!( output = create_wave_file( outname, wptr->samplerate, (wptr->bitspersample/8), wptr->channels ) )) 
		{
			if ( verbose )
				printf("error creating wave output file : %s \r\n",outname);
			close_wave_file( wptr );
			return(27);
		}
	}

	return(0);
}

int	operation(char * nptr)
{
	int	i;
	int	lsample;
	int	rsample;
	struct	wave_handle * wptr;
	if ( *nptr != '+' ) {
		if ( verbose )
			printf("source audio file : %s \n",nptr);
		terminate_output();
		}
	else 	{
		nptr++;
		if ( verbose )
			printf("adding audio file : %s \n",nptr);
		}

	if (!( wptr = open_wave_file( nptr )))
		return(40);

	else if ( sbinfo ) {
		show_wave_header( wptr );
		close_wave_file( wptr );
		return(0);
		}

	else if ( verbose )
		show_wave_header( wptr );

	(void) start_output(wptr);

	if ( verbose )
		show_wave_header( wptr );

	if ( gapsize ) 
	{
		for (i=0; i < gapsize; i++ )
			put_wave_sample( output, -1, 0, 0 );
	}

	while ( get_wave_sample( wptr, &lsample, &rsample ) != 0 )
	{
		put_wave_sample( output, -1, lsample, rsample );
		if ( splice )
		{
			samples--;
			if (!( samples ))
			{
				terminate_output();
				(void)start_output(wptr);
			}
		}		
	}
	close_wave_file( wptr );
	return(0);
}


int	justdoit( int argc, char * argv[] )
{
	int	status=0;
	int	argi;
	char *	aptr;
	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			switch ( *(aptr+1) ) {
				case	's'	:
					splice = atoi( (aptr+2) );
					continue;
				case	'r'	:
					terminate_output();
					targetname = (aptr+2); 
					continue;
				case	'v'	:	
					verbose=1; 
					continue;
				case	'i'	:	
					sbinfo=1; 
					continue;
				case	'g'	:	
					gapsize=atoi((aptr+2));
					continue;
				default		:
					return(30);
				}
			}
		else if ((status = operation( aptr )) != 0)
			return(status );

		}
	return(0);
}

int	doit( int argc, char * argv[] )
{
	int	status;
	status = justdoit(argc,argv);
	terminate_output();
	return(status);
}

int	banner()
{
	printf("\n   Audio File Convertor/Concatenator/Splicer : Version 1.0a");
	printf("\n   Happy Christmas 2009 \n\n");
	printf("\n   usage   : waveconv [ options ] [ wavefilename  [+]mp3name ] \n");
	printf("\n   options : \n");
	printf("\n          -rresultname  : determine result file name");
	printf("\n          -v            : activate information messages");
	printf("\n          -i            : show file header information only ");
	printf("\n          -sseconds     : set max splice length limit ");
	printf("\n          -gvalue       : set interfile gap time \n\n");
	return(0);
}

int	failure(int e)
{
	if ( e ) 
		printf("\nerror: %u\n",e);
	return(e);
}

int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( failure(doit(argc,argv)) );
}

