#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/soundcard.h>

#define	MAX_BUFFER_SIZE 0x8000

char	buffer[MAX_BUFFER_SIZE];
char	cuffer[MAX_BUFFER_SIZE];
int	verbose=0;

char *	target="/dev/dsp0";

struct	wave_handle * Recording=(struct	wave_handle *) 0;
int			ChildReadHandle=-1;

void	*	malloc(int);
void		free( void *);


#include "wave.c"

void	failure(char * message)
{
	printf("failure : %s : %u\n",message,errno);
	return;
}

void	recordcatcher(int n)
{
	printf("record catcher : signal %u\r\n",n);
	if ( ChildReadHandle != -1) {
		ioctl(ChildReadHandle,SNDCTL_DSP_SYNC,0);
		close(ChildReadHandle);
		if ( Recording ) {
			Recording = terminate_wave_file( Recording );
			}
		ChildReadHandle=-1;
		}
	exit(0);
}
void	expand_buffer(int o, struct wave_handle * wptr,int channels, char * bptr, int blen )
{
	int	i;
	int	c;
	for ( c=0, i=0; i < blen; i++ ) {
		cuffer[c++] = *(bptr+i);
		cuffer[c++] = *(bptr+i);
		if ((c+2) < MAX_BUFFER_SIZE)
			continue;
		else 	{
			write(o,cuffer,c);
			c = 0;
			}
		}
	if ( c )
		write(o,cuffer,c);
}


int	operate(char * nptr )
{
	char *	rptr;
	int	rlen;
	int	speed=44100;
	int	channels=2;
	int	format=1;
	int	status;
	int	o;
	int	c,n;
	long	total=0L;
	struct	wave_handle * wptr;

	if (!( wptr = create_wave_file(  nptr, 44100,2,2 )))
		return( 40 );
	else	show_wave_header( wptr );

	if (( o = open( target, O_RDONLY, 0)) == -1) {
		close_wave_file(wptr);		
		failure("open");
		}
	else 	{
		speed  	= wptr->samplerate;
		format  = wptr->format;
		channels= wptr->channels;

		/* Change sample rate */
		/* ------------------ */
		if ((status = ioctl(o,SNDCTL_DSP_RESET, 0 )) == -1) {
			close_wave_file(wptr);		
			failure("reset");
			}
		else if ((status = ioctl(o,SNDCTL_DSP_SETFMT, &format )) == -1) {
			close_wave_file(wptr);		
			failure("setfmt");
			}
		else if ((status = ioctl(o,SNDCTL_DSP_CHANNELS, &channels )) == -1) {
			close_wave_file(wptr);		
			failure("channels");
			}
		else if ((status = ioctl(o,SNDCTL_DSP_SPEED, &speed )) == -1) {
			close_wave_file(wptr);		
			failure("speed");
			}
		else	{
			ChildReadHandle=o;
			Recording = wptr;
			signal(SIGHUP,recordcatcher);
			signal(SIGINT,recordcatcher);
			signal(SIGQUIT,recordcatcher);
			while ((status = read(o,buffer,MAX_BUFFER_SIZE)) > 0) {
				if ((n = fwrite(buffer,1,n,wptr->handle)) <= 0  )
					break;
				else	wptr->datasize += n;
				}
			}
		close(o);
		}
	terminate_wave_file(wptr);		
	return(0);
}

int	option( char * aptr )
{
	if ( *aptr == 'a' )
		target = "/dev/audio0";
	else if ( *aptr == 'v' )
		verbose = 1;
	return(0);
}

int	doit( int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' )
			option((aptr+1));
		else	operate(aptr);
		}
	return(0);
	
}

int	banner()
{
	printf("\nrecord wave : version 1.0a.0.01");
	printf("\nprovisoire 21/09/2004\n");
	return(0);
}

int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( doit(argc,argv) );

}



