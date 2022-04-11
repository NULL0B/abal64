#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <termio.h>

int	pipetype=0;
int	debug=0;
int	prndest=1;
int	err_val=0;
int	prnleng=0;
int	prnfid=0;
char *	prnptr=(char *) 0;


#include "special.h"

static	void * Where=(void*)0;

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
	struct	timeval recordtime;
	long	timing;
	} Context;

static	char *	tracename=(char *) 0;

static struct termio confterm;
static struct termio proterm;

#define	MICROSECONDS 1000000


static	void	copytimeofday( struct timeval * a, struct timeval * b)
{
	a->tv_sec = b->tv_sec;
	a->tv_usec = b->tv_usec;
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

static	void	reset_timeval( struct timeval * tptr)
{
	tptr->tv_sec = 0;
	tptr->tv_usec= 0;
	return;
}

static	int	initerm()
{
	reset_timeval( &Context.now );
	reset_timeval( &Context.then );
	reset_timeval( &Context.recordtime );
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

static	void	debug_message_ww(char * mptr, int a, int b )
{
	if ( debug ) 
		 fprintf(Context.tracehandle,"# %s ( %u, %u ) \n",mptr,a,b);
	return;
}

static	void	debug_message_sw(char * mptr, char * pptr, int v )
{
	if ( debug ) 
		 fprintf(Context.tracehandle,"# %s ( %s:%u ) \n",mptr,pptr,v);
	return;
}

static	void	debug_message_s(char * mptr, char * pptr )
{
	if ( debug ) 
		 fprintf(Context.tracehandle,"# %s ( %s ) \n",mptr,pptr);
	return;
}

static	void	debug_message(char * mptr)
{
	if ( debug ) 
		 fprintf(Context.tracehandle,"# %s \n",mptr);
	return;
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
	reset_timeval( &Context.recordtime );
	Context.timing = 0L;
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
		debug_message_sw( "context closure", message, status );
		fclose(Context.tracehandle);
		}

	if ( status )
		printf("\n** error : %s : %u **\n",message,status);

	reset_context();

	return( status );
}


static	void	child_catcher(int sigid)
{
	debug_message_ww( "child death event", sigid,Context.child);
	Context.terminate=1;
	return;
}

static	void	alarm_catcher(int sigid)
{
	Context.timing++;
	debug_message_ww( "alarm event",sigid,Context.timing);
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
			debug_message("standard pipe");
			return( pipe( Context.pipehandles ) );
		case	1	:
			debug_message("named pipe");
			sprintf(Context.pipename,"/tmp/capturing.%u",getpid());
			debug_message(Context.pipename);
			sprintf(sbuffer,"mkfifo %s",Context.pipename);
			if ( system( sbuffer ) < 0 ) 
				return( close_context( "creating named pipe", errno ) );
			else if (!( Context.pipehandles[0] = open( Context.pipename, O_RDONLY | O_NDELAY  ) ))
				return( close_context( "opening named pipe for reading", errno ) );
			else if (!( Context.pipehandles[1] = open( Context.pipename, O_WRONLY ) ))
				return( close_context( "opening named pipe for writing", errno ) );
			else	return( 0 );
		case	2	:
			debug_message("pseudo device");
			if (( Context.pipehandles[1] = open( PSEUDO_DEVICE_MASTER, O_RDWR | O_NOCTTY )) < 0 )
				return( close_context( "opening master pseudo device", errno ) );
			else if ( grantpt( Context.pipehandles[1] ) < 0 )
				return( close_context( "creating pseudo device slave", errno ) );
			else if ( unlockpt( Context.pipehandles[1] ) < 0 )
				return( close_context( "unlocking pseudo device slave", errno ) );
			else if (!( Context.slavename = (char *) ptsname( Context.pipehandles[1] )))
				return( close_context( "resolving pseudo device slave name", errno ) );
			debug_message( Context.slavename );
			if (( Context.pipehandles[0] = open( Context.slavename, O_RDONLY )) < 0 )
				return( close_context( "opening slave pseudo device", errno ) );
			else	return( 0 );
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
	if (!( tracename )) {
		printf("scenario filename required\n");
		return(40);
		}
	else	strcpy(Context.tracename,tracename);

	/* create capture file */
	/* ------------------- */
	if (!( Context.tracehandle = fopen(Context.tracename,"w"))) {
		printf("creating trace file : %s \n",Context.tracename);
		return(46);
		}
	else 	{
		fprintf(Context.tracehandle,"# ------------------------------------------------------- \n");
		fprintf(Context.tracehandle,"# cico standard input capture : %s \n",Context.tracename);
		fprintf(Context.tracehandle,"# ------------------------------------------------------- \n");
		fprintf(Context.tracehandle,"# export CICO=%s \n",getenv("CICO"));
		fprintf(Context.tracehandle,"# ------------------------------------------------------- \n");
		}

	/* Create Communication Pipe */
	/* ------------------------- */
	if ( make_pipe() < 0 ) 
		return( close_context("creating pipe",errno) );
	else 	debug_message("communication pipe created");
		
	/* initialise CICO manager */
	/* ----------------------- */
	if ( initerm() != 0)
		return( close_context("changing line protocol",errno) );
	else 	debug_message("terminal initialisation ok"); 
		
	/* Setup Stdin for Exa */
	/* ------------------- */
	if ((Context.duplicate = dup(STDIN)) == -1)
		return( close_context("duplicating stdin",errno) );

	else if ( close(STDIN) == -1 ) 
		return( close_context("closing stdin",errno) );

	else if ( dup( Context.pipehandles[STDIN] ) == -1 ) 
		return( close_context("duplicating pipe handle",errno) );
	else 	debug_message("redirection of stdin for child ok"); 

	/* catch child death signal */
	/* ------------------------ */
	if ((Context.sigchld = (long) signal(SIGCHLD,child_catcher)) == -1) 
		return( close_context("catching child signal",errno) );
	else 	debug_message("catching child death signal");
		
	if ( debug ) { 
		debug_message("launching child process"); 
		for ( i=argi; i < argc; i++ ) 
			debug_message_sw("argv[]",argv[i],i);
		} 

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
				debug_message("recovery of stdin by parent ok ");
				}
				
			/* Operational Loop Waiting for Child Death */
			/* ---------------------------------------- */
			gettimeofday(&Context.then,Where);

			while (!( Context.terminate )) {

				if ( read_stdin( wbuf,1 ) != 1)
					continue;
				else	{
					/* Send the byte to exa */
					/* -------------------- */
					write(Context.pipehandles[STDOUT],wbuf,1);
	
					/* and record to the capture log */
					/* ----------------------------- */	
					gettimeofday(&Context.now,Where);
					copytimeofday(&Context.recordtime,&Context.now);
					subtimeofday(&Context.recordtime,&Context.then);
					fprintf(Context.tracehandle,"%lu %lu K %u\n",Context.recordtime.tv_sec,Context.recordtime.tv_usec,(wbuf[0] & 0x00FF));
					copytimeofday(&Context.then,&Context.now);
					}
				}
		}


	return( close_context( "ok", 0 ) );

}

int	option( char * aptr)
{
	switch ( *(aptr++) ) {
		case	'x'	:
			pipetype=2;
			return(0);
		case	'n'	:
			pipetype=1;
			return(0);
		case	'd'	:
			debug = 1;
			return(0);
		case	'o'	:
			tracename = aptr;
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
	printf("\n   Abal Key Stroke Capture : Version 1.0.1 ");
//	printf("\n   Provisoire du 30/03/2009 ");
	printf("\n   Copyright (c) 2019 A.P.I. \n");
	printf("\n   Usage    : capture [ options ] command \n");
	printf("\n   Options  : ");
	printf("\n            -n          : use named pipe ");
	printf("\n            -d          : activate debug messages ");
	printf("\n            -ofilename  : specify name of trace file ");
	printf("\n            -x          : use pseudo device\n\n ");

	return(0);
}


int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return(banner());
	else	return(operation(argc,argv));
}


