#ifndef	_xsystem_c
#define	_xsystem_c

#include "xsignal.h"
#include <sys/types.h>
#include <sys/wait.h>


#define	BIN_SHELL	"/bin/sh"

char	*	binshell=BIN_SHELL;

#ifdef	SCREAM
void	scream(char * message)
{
	char 	xsbuffer[512];
	sprintf(xsbuffer,"echo %s pid %u errno = %d >> xs.out",message,getpid(),errno );
	system( xsbuffer );
	return;
}
void	iscream(char * message,int v)
{
	char 	xsbuffer[512];
	sprintf(xsbuffer,"%s %d",message,v);
	scream(xsbuffer);
	return;
}
#else	
#define	scream(a)
#define	iscream(a,b)
#endif
#define	system(c) x_system(c)

static	int	waithit=0;
static	int	working=0;
static	void	(*worker) ()=(void *) 0;

void	set_worker( void * vptr)
{
	if (!(worker = vptr))
		working=0;
	else	working=1;
	return;
}

static	void	waitpidjob(int sid )
{
	waithit=1;
	return;
}
	
int	x_waitpid(int jobid )
{
	int	status=0;
	void *	sigholder;
	void *	vptr;
	while(1) {

		/* Await child completion */
		/* ---------------------- */
		if ( working ) {
			sigholder = signal(SIGALRM,waitpidjob);
			alarm(1);
			}
		if ( waitpid( jobid, & status, 0 ) == -1 ) {
			if ( working ) { sigholder = signal(SIGALRM,sigholder); }
			if ( errno == ECHILD ) {
				scream("unknown child process");
				return(errno);
				} 
			else if ( errno == EAGAIN ) {
				scream("EAGAIN");
				continue;
				}
			else if ( errno == EINTR ) {
				if (!( working )) {
					scream("EINTR");
					}
				else	{
					(worker)();
					}
				continue;
				}
			else if ( errno != EINTR ) {
				scream("not EINTR");
				return(errno);
				}
			}
		else	{
			if ( working ) { sigholder = signal(SIGALRM,sigholder); }
			if ( WIFEXITED(status) ) {
				status = WEXITSTATUS(status);
				iscream("exited",status);
				}
			else if ( WIFSIGNALED(status) ) {
				status = WTERMSIG(status);	
				iscream("signaled",status);
				}
			else	{
				iscream("failure",status);
				}	
			return(status);
			}
		}

}

int	system( char * command )
{
	char	cream[256];
	int	jobid;
	int	status;
	char *	argv[4];

	/* Ensure Legal Command */
	/* -------------------- */
	if (!( command ))
		return(30);

	/* Protection against premature cot death */
	/* -------------------------------------- */
	(void) signal(SIGCHLD,SIG_DFL);

	/* Ensure Task Created */
	/* ------------------- */

	if ((jobid = fork()) < 0) {
 		(void) signal(SIGCHLD,SIG_IGN);
		return(24);
		}

	/* If its the Child Process */
	/* ------------------------ */
	else if (!(jobid)) {

		argv[0] = binshell;
		argv[1] = "-c";
		argv[2] = command;
		argv[3] = (char *) 0;
		execv(argv[0],argv );

		/* This is the FailSafe */
		/* -------------------- */
		return( 38 );
		}

	/* Otherwise its the Parent */
	/* ------------------------ */
	else	{

		status = x_waitpid(jobid );
		(void) signal(SIGCHLD,SIG_IGN);
		return( status );

		}

}


#endif	/* _xsysteme_c */

