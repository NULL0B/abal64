#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/soundcard.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <signal.h>

#define	MAX_BUFFER_SIZE 0x8000

int	sbecho=0;
int	sbinfo=0;
int	verbose=0;
int	gapsize=0;

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

	if (!( output )) {

		if ( verbose )
			printf("creating audio file : %s \n",nptr);

		if (!( output = create_wave_file( targetname, wptr->samplerate, (wptr->bitspersample/8), wptr->channels ) )) {
			if ( verbose )
				printf("error creating wave output file : %s \r\n",targetname);
			close_wave_file( wptr );
			return(27);
			}
		}
	if ( verbose )
		show_wave_header( wptr );

	if ( gapsize ) {
		for (i=0; i < gapsize; i++ )
			put_wave_sample( output, -1, 0, 0 );
		}

	while ( get_wave_sample( wptr, &lsample, &rsample ) != 0 )
		put_wave_sample( output, -1, lsample, rsample );

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
	printf("\n   Audio File Convertor/Concatenator : Version 1.0a");
	printf("\n   Provisoire du 28/03/2008 ");
	printf("\n   Copyright (c) 2008 Amenesik / Sologic \n\n");
	printf("\n   usage   : waveconv [ options ] [ wavefilename  [+]mp3name ] \n");
	printf("\n   options : \n");
	printf("\n          -rresultname  : determine result file name");
	printf("\n          -v            : activate information messages");
	printf("\n          -i            : show file header information only ");
	printf("\n          -gvalue       : set interfile gap time \n\n");
	return(0);
}

int	failure(int e)
{
	if ( e ) 
		printf("\nerror: %u\n");
	return(e);
}

int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( failure(doit(argc,argv)) );
}

