#ifndef	_xsystem_c
#define	_xsystem_c

#include "xsignal.h"
#include <sys/types.h>
#include <sys/wait.h>

#include "exasyslog.h"


#define	BIN_SHELL	"/bin/sh"

char*	binshell=BIN_SHELL;

//#BG 09/05/17
static int	childpid=0;

static	int	waithit=0;
static	int	working=0;
static	int	stupid=0;
static	void	(*worker) ()=(void *) 0;

#ifdef	SCREAM
/* Actually not defined */
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

/* 	------------------------	*/
/*	   x _ w a i t p i d 		*/
/* 	------------------------	*/
/* 	Await child completion.		*/
/* 	------------------------	*/

int	x_waitpid(int jobid )
{
	
	int	status=0;
	void *	sigholder;
	void *	vptr;
	if (IsExaSysLog() & SYSLOG_CHILD) 
	{
		sprintf(SysLogBuffer, "Waiting for child process (%u) ending ...", jobid);
		ExaSysLog(EXA_SYSLOG_INFO, SysLogBuffer);
	}
	while(1) 
	{
		if ( working ) 
		{
			/* Interception du signal SIGALRM par le handler waitpidjob() qui ne fait rien */
			sigholder = signal(SIGALRM, waitpidjob);
			/* Envoi d'un SIGALRM dans 1 sec:
			 * A pour effet d'interrompre waitpid() avec errno=EINTR et donc de boucler chaque seconde.
			 * Si pas de alarm(1), on ne boucle pas et on sort de waitpid() seulement quand le processus fils
			 * se termine par WIFEXITED() ou WIFSIGNALED().
			 * Quelle utilité, quelle influence sur les perfs?
			 */
			alarm(1);
		}

		if ( waitpid( jobid, & status, 0 ) == -1 ) 
		{
			if ( working )
			{
				sigholder = signal(SIGALRM, sigholder);
			}

			if ( errno == ECHILD ) 
			{
				/* waitpid() s'est termine car le process fils est inconnu */
				sprintf(SysLogBuffer, "waitpid(%u) failure ECHILD", jobid);
				ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
				return(errno);
			} 
			else if ( errno == EAGAIN ) 
			{
				/* waitpid() s'est termine car ressource indisponible ??? */
				sprintf(SysLogBuffer, "waitpid(%u) failure EAGAIN", jobid);
				ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
				continue;
			}
			else if ( errno == EINTR ) 
			{
				/* waitpid() a ete interrompu par un signal intercepte: SIGALRM du a alarm(1),
				 * donc on boucle chaque seconde car on reactive l'alarme!
				 */
				if ((IsExaSysLog() & SYSLOG_CHILD) && (stupid))
				{
					sprintf(SysLogBuffer, "waitpid(%u) failure EINTR (SIGALARM normal interruption)", jobid);
					ExaSysLog(EXA_SYSLOG_INFO, SysLogBuffer);
				}
				if (!( working )) {
					ExaSysLog(EXA_SYSLOG_ERROR, "EINTR not working");
				}
				else	
				{
					(worker)();
				}
				continue;
				}
			else if ( errno != EINTR ) 
			{
				/* waitpid() s'est termine anormalement pour une autre raison */
				sprintf(SysLogBuffer, "waitpid(%u) unknown failure", jobid);
				ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
				return(errno);
			}
		}
		else	
		{
			/* Le processus fils est termine (normalement ou non)*/

			if ( working ) 
			{
				sigholder = signal(SIGALRM, sigholder);
			}

			if ( WIFEXITED(status) ) 
			{
				/* normalement */
				status = WEXITSTATUS(status);
				if (IsExaSysLog() & SYSLOG_CHILD) 
				{
					sprintf(SysLogBuffer, "Child process (%u) normaly ended (%d)", jobid, status);
					ExaSysLog(EXA_SYSLOG_INFO, SysLogBuffer);
				}
			}
			else if ( WIFSIGNALED(status) ) 
			{
				/* a cause d'un signal non intercepte */
				status = WTERMSIG(status);	
				sprintf(SysLogBuffer, "Child process (%u) ended with not intercepted signal(%d)", jobid, status);
				ExaSysLog(EXA_SYSLOG_INFO, SysLogBuffer);
			}
			else	
			{
				/* pour une autre raison */
				sprintf(SysLogBuffer, "Child process (%u) ended for unknown reason", jobid);
				ExaSysLog(EXA_SYSLOG_INFO, SysLogBuffer);
			}	

			childpid = 0;	//#BG 09/05/17

			return(status);
		}
	}	
}

#ifdef	ABAL32A
static	int	is_background_task=0;
#endif

int	system( char * command )
{
//	char	cream[256];
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

	if ((jobid = fork()) < 0) 
	{
		/* Error */
 		(void) signal(SIGCHLD,SIG_IGN);
		return(24);
	}

	/* If its the Child Process */
	/* ------------------------ */
	else if (!(jobid)) 
	{

		argv[0] = binshell;
		argv[1] = "-c";
		argv[2] = command;
		argv[3] = (char *) 0;
		execv(argv[0],argv );

		/* This is the FailSafe */
		return( 38 );
	}

	else 
	{
		/* Otherwise its the Parent */
		/* ------------------------ */
#ifdef	ABAL32A
		if ( is_background_task ) 
		{
			/* Back groundworker job */
			/* --------------------- */
			(void) signal(SIGCHLD,SIG_IGN);
			return(0);
		}
		else	
		{
#endif
			on_system(1);	/* inhibit keyboard grab */

			if (IsExaSysLog() & SYSLOG_CHILD) 
			{
				sprintf(SysLogBuffer, "Child process (%u) running: %s", jobid, command);
				ExaSysLog(EXA_SYSLOG_INFO, SysLogBuffer);
			}

			childpid = jobid;

			status = x_waitpid(jobid);

			on_system(0);	/* permit keyboard grab */
			(void) signal(SIGCHLD,SIG_IGN);
			return( status );
#ifdef	ABAL32A
		}
#endif
	}
}

//#BG 09/05/17
int get_child_pid()
{
	return(childpid);
}

int reset_child_pid()
{
	childpid = 0;
}

#ifdef	ABAL32A
int multitask_system( char * command )
{
	int	h=is_background_task;
	int	status;
	is_background_task=1;
	status = system( command );
	is_background_task=h;
	return( status );
}

int is_loadgo_task()
{
	return(is_background_task);
}

void set_loadgo_task(int v)
{
	is_background_task=v;
}
#endif

	
#endif	/* _xsysteme_c */

