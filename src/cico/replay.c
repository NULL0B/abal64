#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <termio.h>

#include "special.h"

static	void * Where=(void*)0;
int	zap=0;
int	pipetype=0;
int	prndest=1;
int	err_val=0;
int	prnleng=0;
int	prnfid=0;
char *	prnptr=(char *) 0;

struct	capture_context	{
	int	ungotch;
	FILE * 	tracehandle;
	long	sigchld;
	long	sigalrm;
	int	terminate;
	int	child;
	int	pipehandles[2];
	char	tracename[512];
	char	pipename[512];
	int	pipetype;
	int	cico;
	int	duplicate;
	char *	slavename;
	struct	timeval now;
	struct	timeval then;
	struct	timeval replaydelay;
	long	timing;
	int	zap;
	} Context;

static	char *	capturedname=(char *) 0;

static struct termio confterm;
static struct termio proterm;

#define	MICROSECONDS 1000000

static	void	copytimeofday( struct timeval * a, struct timeval * b)
{
	a->tv_sec = b->tv_sec;
	a->tv_usec = b->tv_usec;
	return;
}


static	void	reset_timeval( struct timeval * tptr)
{
	tptr->tv_sec = 0;
	tptr->tv_usec= 0;
	return;
}

static	void	addtimeofday( struct timeval * a, struct timeval * b)
{
	a->tv_sec += b->tv_sec;
	a->tv_usec += b->tv_usec;
	while ( a->tv_usec >= MICROSECONDS ) {
		a->tv_sec++;
		a->tv_usec -= MICROSECONDS;
		}
	return;
}

static	void	subtimeofday( struct timeval * a, struct timeval * b)
{
	if ( b->tv_usec > a->tv_usec ) {
		a->tv_usec += MICROSECONDS;
		a->tv_sec--;
		}
	a->tv_usec -= b->tv_usec;
	a->tv_sec -= b->tv_sec;
	return;
}

static	int	cmptimeofday( struct timeval * a, struct timeval * b)
{
	if ( a->tv_sec > b->tv_sec )
		return( 1 );
	else if ( a->tv_sec < b->tv_sec )
		return( -1 );
	else if ( a->tv_usec > b->tv_usec )
		return(1);
	else if ( a->tv_usec < b->tv_usec )
		return(-1);
	else	return( 0 );
}

static	int	finterm()
{
	if ( Context.cico ) {
		ioctl(STDIN, TCSETA, &confterm);	/* pour sauvegarde */
		Context.cico = 0;
		}
	return(0);
}

static	int	initerm()
{
	reset_timeval( &Context.now );
	reset_timeval( &Context.then );
	reset_timeval( &Context.replaydelay );
	ioctl(STDIN, TCGETA, &confterm);	/* pour sauvegarde */
	ioctl(STDIN, TCGETA, &proterm); 	/* pour programmer */
	proterm.c_iflag &= ~ICRNL;
	proterm.c_iflag &= ~ISTRIP;
	proterm.c_oflag &= ~OPOST;
	proterm.c_lflag = 0;
	proterm.c_cc[VTIME] = 0;
	proterm.c_cc[VMIN] = 1;
	proterm.c_cc[VINTR] = 0xFF;
	proterm.c_cc[VQUIT] = 0x7F;
	ioctl(STDIN, TCSETA, &proterm);
	Context.cico = 1;
	return(0);
}

static	void	reset_context()
{
	Context.tracehandle = (FILE *) 0;
	Context.ungotch = 0;
	Context.sigchld     = -1L;
	Context.sigalrm     = -1L;
	Context.slavename   = (char *) 0;
	Context.terminate   = 0;
	Context.child       = 0;
	Context.pipehandles[0] = -1;
	Context.pipehandles[1] = -1;
	Context.duplicate      = -1;
	Context.cico 	       = 0;
	Context.pipetype       = pipetype;
	memset(Context.pipename,0,512);
	reset_timeval( &Context.now );
	reset_timeval( &Context.then );
	reset_timeval( &Context.replaydelay );
	Context.timing 		= 0L;
	Context.zap 		= zap;
	return;
}

static	int	close_context(char * message, int status )
{
	if ( Context.cico )
		 finterm();

	if ( Context.sigchld != -1 )
		signal(SIGCHLD,(void *) Context.sigchld );

	if ( Context.duplicate != -1 )
		close( Context.duplicate );

	if ( Context.pipehandles[1] != -1 )
		close( Context.pipehandles[1] );

	if ( Context.pipehandles[0] != -1 )
		close( Context.pipehandles[0] );

	switch ( Context.pipetype ) {
		case	1 :
			if ( Context.pipename[0] != 0 )
				unlink( Context.pipename );
			break;
		}

	if ( Context.tracehandle ) {
		fclose(Context.tracehandle);
		}

	if ( status )
		printf("\n** error : %s : %u **\n",message,status);

	reset_context();

	return( status );
}


static	void	child_catcher(int sigid)
{
	Context.terminate=1;
	return;
}

static	void	alarm_catcher(int sigid)
{
	Context.timing++;
	signal(SIGALRM,alarm_catcher);
	return;
}	

static	int	child_worker( int argi, int argc, char * argv[] )
{
	execv( argv[argi], & argv[argi] );
	return(errno);
}


static	int	read_stdin(char * buffer, int nb )
{
	int	status=0;
	struct	sigaction new;
	struct	sigaction old;
	memset( &new, 0, sizeof( struct sigaction ));
	new.sa_handler = alarm_catcher;
	new.sa_flags= SA_ONESHOT;
	sigaction(SIGALRM,&new,&old);
	alarm(1);
	status = read( STDIN, buffer, nb );
	sigaction(SIGALRM,&old,(void*) 0);
	return( status );
}

static	int	make_pipe()
{
	int	master;
	char	sbuffer[512];
	switch ( Context.pipetype ) {
		case	0	:
			return( pipe( Context.pipehandles ) );
		case	1	:
			sprintf(Context.pipename,"/tmp/capturing.%u",getpid());
			sprintf(sbuffer,"mkfifo %s",Context.pipename);
			if ( system( sbuffer ) < 0 ) 
				return( close_context( "creating named pipe", errno ) );
			else if (!( Context.pipehandles[0] = open( Context.pipename, O_RDONLY | O_NDELAY  ) ))
				return( close_context( "opening named pipe for reading", errno ) );
			else if (!( Context.pipehandles[1] = open( Context.pipename, O_WRONLY ) ))
				return( close_context( "opening named pipe for writing", errno ) );
			else	return( 0 );
		case	2	:
			if (( Context.pipehandles[1] = open( PSEUDO_DEVICE_MASTER, O_RDWR | O_NOCTTY )) < 0 )
				return( close_context( "opening master pseudo device", errno ) );
			else if ( grantpt( Context.pipehandles[1] ) < 0 )
				return( close_context( "creating pseudo device slave", errno ) );
			else if ( unlockpt( Context.pipehandles[1] ) < 0 )
				return( close_context( "unlocking pseudo device slave", errno ) );
			else if (!( Context.slavename = (char *) ptsname( Context.pipehandles[1] )))
				return( close_context( "resolving pseudo device slave name", errno ) );
			if (( Context.pipehandles[0] = open( Context.slavename, O_RDONLY )) < 0 )
				return( close_context( "opening slave pseudo device", errno ) );
			else	return( 0 );
		}
}

static	int	trace_byte()
{
	int	c;
	if ((c = Context.ungotch) != 0) {
		Context.ungotch = 0;
		return( c );
		}
	else if (!( Context.tracehandle ))
		return( -1 );
	else if ((c = fgetc(Context.tracehandle)) == -1) {
		fclose( Context.tracehandle );
		Context.tracehandle = (FILE *) 0;
		return(-1);
		}
	else	return( c );
}

static	int	trace_line()
{
	int	c;
	while ((c = trace_byte()) != -1 )
		if ( c == '\n' )
			return(1);
	return(-1);
}

static	int	trace_not_space()
{
	int	c;
	while (1) {
		switch ((c = trace_byte())) {
			case	'#'	:
				if ( trace_line() != -1 )
					continue;
				else	return(-1);
			case	-1	:
			case	 0	:
				return( -1 );
			case	' '	:
			case	'\t'	:
			case	'\r'	:
				continue;
			default		:
				return( c );
			}
		}
}

static	int	trace_integer()
{
	int	value=0;
	int	c;
	
	if ((c = trace_not_space()) == -1)
		return(-1);
	else 	{
		while (( c >= '0') && ( c <= '9' )) {
			value = ((value * 10) + ( c - '0' ));
			if ((c = trace_byte()) == -1)
				return( c );
			}
		if ( c == '\n' )
			Context.ungotch = c;
		return( value );
		}
}
	

static	int	read_trace( char * buffer, int length )
{
	struct	timeval remainder;
	int	w;
	int	c;
	while (1) {
		if (( Context.replaydelay.tv_sec = trace_integer()) == -1)
			return(0);
		else if (( Context.replaydelay.tv_usec = trace_integer()) == -1)
			return(0);
		else 	{
			addtimeofday(&Context.replaydelay,&Context.then);
			while (1) {
				gettimeofday(&Context.now,Where);
				if ( cmptimeofday( &Context.now, &Context.replaydelay ) >= 0 )
					break;
				else	{
					copytimeofday(&remainder,&Context.replaydelay);
					subtimeofday(&remainder,&Context.now);
					if ( remainder.tv_sec > 0 ) {
						sleep( remainder.tv_sec );
						}
					}
				}
			copytimeofday(&Context.then,&Context.now);
			if ((c = trace_not_space()) == -1)
				return(0);
			else if ( c != 'K' ) {
				if ( c == '\n' )
					continue;
				else if ( trace_line() == -1) 
					return(0);
				else	continue;
				}
			else if (( c = trace_integer()) == -1)
				return(0);
			else if ( trace_line() == -1) 
				return(0);
			else 	{
				*buffer = (c & 0x00FF);
				/* fprintf(stderr,"%u K %u\n",w,c); */
				return(1);
				}
			}
		}
}

static	int	launch( int argi, int argc, char * argv[] )
{
	int	i;
	int	c;
	char	wbuf[2];

	/* Ensure clean context */
	/* -------------------- */
	reset_context();

	/* Build Trace File Name if necessary */
	/* ---------------------------------- */
	if (!( capturedname )) {
		printf("scenario filename required\n");
		return(40);
		}
	else	strcpy(Context.tracename,capturedname);

	/* create capture file */
	/* ------------------- */
	if (!( Context.tracehandle = fopen(Context.tracename,"r"))) {
		printf("opening scenario file : %s \n",Context.tracename);
		return(46);
		}

	/* Create Communication Pipe */
	/* ------------------------- */
	if ( make_pipe() < 0 ) 
		return( close_context("creating pipe",errno) );
		
	/* initialise CICO manager */
	/* ----------------------- */
	if ( initerm() != 0)
		return( close_context("changing line protocol",errno) );
		
	/* Setup Stdin for Exa */
	/* ------------------- */
	if ((Context.duplicate = dup(STDIN)) == -1)
		return( close_context("duplicating stdin",errno) );

	else if ( close(STDIN) == -1 ) 
		return( close_context("closing stdin",errno) );

	else if ( dup( Context.pipehandles[STDIN] ) == -1 ) 
		return( close_context("duplicating pipe handle",errno) );

	/* catch child death signal */
	/* ------------------------ */
	if ((Context.sigchld = (long) signal(SIGCHLD,child_catcher)) == -1) 
		return( close_context("catching child signal",errno) );
		
	/* Launch Abal Application */
	/* ----------------------- */
	switch ((Context.child = fork())) {

		case	-1 :	
			return( close_context( "creating child process",errno) );

		case	0  :
			exit( child_worker(argi,argc,argv) );

		default	   :
			/* Restore Original Standard Input */
			/* ------------------------------- */
			if ( close(STDIN) == -1 ) 
				return( close_context("closing pipe stdin",errno) );

			else if ( dup( Context.duplicate ) == -1 ) 
				return( close_context("duplicating stdin",errno) );

			else if ( close(Context.duplicate) == -1 ) 
				return( close_context("closing duplicate",errno) );

			else	{
				Context.duplicate = -1;
				}
				
			/* Operational Loop Waiting for Child Death */
			/* ---------------------------------------- */
			gettimeofday(&Context.now,Where);
			copytimeofday(&Context.then,&Context.now);

			while (!( Context.terminate )) {
				if ( Context.tracehandle ) {
					if ( read_trace( wbuf, 1 ) != 1)
						continue;
					}
				else if ( Context.zap ) {
					sleep((Context.zap/2+1) );
					kill( Context.child , SIGTERM );
					while (!( Context.terminate )) {
						sleep(1);
						}
					break;
					}
				else if ( read_stdin( wbuf,1 ) != 1)
					continue;
				/* Send the byte to exa */
				/* -------------------- */
				write(Context.pipehandles[STDOUT],wbuf,1);
				}
		}


	return( close_context( "ok", 0 ) );

}

int	option( char * aptr)
{
	switch ( *(aptr++) ) {
		case	'z'	:
			zap = atoi(aptr);
			return(0);
		case	'x'	:
			pipetype=2;
			return(0);
		case	'n'	:
			pipetype=1;
			return(0);
		case	'i'	:
			capturedname = aptr;
			return(0);
		default		:
			return(30);
		}
}

static	int	operation( int argc, char * argv[] )
{
	int	status;
	int	argi;
	char *	aptr;
	for (argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			if ((status = option((aptr+1))) != 0)
				return(status);
			else	continue;
			}
		else	return( launch( argi, argc, argv ) );
		}
	return(0);
}

static	int	banner()
{
	printf("\n   Abal Key Stroke Replay  : Version 1.0.1 ");
//	printf("\n   Provisoire du 30/03/2009 ");
	printf("\n   Copyright (c) 2019 A.P.I. \n");
	printf("\n   Usage    : replay [ options ] command \n");
	printf("\n   Options  : ");
	printf("\n            -n          : use named pipe ");
	printf("\n            -ifilename  : specify filename to be replayed ");
	printf("\n            -z          : abandon on end of file "); 
	printf("\n            -x          : use pseudo device\n\n ");

	return(0);
}


int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return(banner());
	else	return(operation(argc,argv));
}


