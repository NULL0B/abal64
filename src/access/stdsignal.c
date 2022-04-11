#ifndef	_stdsignal_c
#define	_stdsignal_c

/*		-------------------------------------------		*/
/*			   S T D S I G N A L . C 			*/
/*		-------------------------------------------		*/
/*		Signal failure management and log subsystem		*/
/*		-------------------------------------------		*/


#include <signal.h>			/* Include Signal Definitions	*/
#include <syslog.h>			/* system loging definitions	*/

static	int	SignalFlags=-1;		/* signal configuration mask	*/
static	char	msgbuffer[320];		/* signal log message buffer	*/
static	char	idbuffer[256];		/* signal module name buffer	*/

/*	--------------------------------------------------------	*/
/*	s t a n d a r d _     l o g     _ s i g n a l ( signal )	*/
/*	--------------------------------------------------------	*/
/*	This function is used to log  signal trapping events    	*/
/*	--------------------------------------------------------	*/
void		standard_log_signal( int sigid, char * message )
{
	int	level;
	char *	mptr;

	if (!( message )) message = "\0";

	switch ( sigid ) {
		case	SIGTERM	:
			level = LOG_WARNING;	mptr  = "termination";
			break;

		case	0	:
			level = LOG_WARNING;	mptr  = "message";
			break;
		case	SIGILL	:
		case	SIGSEGV	:
		case	SIGFPE	:
		case	SIGBUS	:
			level = LOG_CRIT; 	mptr  = "critical failure";
			break;
		default		:
			level = LOG_WARNING;	mptr  = "failure";

		}

	sprintf(msgbuffer,"stdsignal: %s: pid=%u signal=%u %s %s ",idbuffer,getpid(),sigid,message,mptr);
	syslog( level, msgbuffer );
	return;
}

/*	--------------------------------------------------------	*/
/*	s t a n d a r d _ s i g n a l _ c a t c h e r ( signal )	*/
/*	--------------------------------------------------------	*/
/*	This function is used to log   unwanted signals	and exit	*/
/*	--------------------------------------------------------	*/
static void	standard_signal_catcher(int sigid)
{

	standard_log_signal( sigid, "unexpected" );
	exit(0);
}

/*	--------------------------------------------------------	*/
/*	s t a n d a r d _ c a t c h   _ s i g n a l   ( signal )	*/
/*	--------------------------------------------------------	*/
static void	standard_trap_signal(int sigid)
{
	(void) signal(sigid, standard_signal_catcher );
}

/*	--------------------------------------------------------	*/
/*	s t a n d a r d _ i g n o r e _ s i g n a l   ( signal )	*/
/*	--------------------------------------------------------	*/
static void	standard_ignore_signal(int sigid)
{
	(void) signal(sigid, SIG_IGN );
	return;
}

/*	--------------------------------------------------------	*/
/*	s t a n d a r d _ d e f a u l t _ s i g n a l ( signal )	*/
/*	--------------------------------------------------------	*/
static void	standard_default_signal(int sigid)
{
	(void) signal(sigid, SIG_DFL );
	return;
}

/*	--------------------------------------------------------	*/
/*	s t a n d a r d _   i n i t   _ s i g n a l s (        )	*/
/*	--------------------------------------------------------	*/
int	standard_init_signals(char * modulename, char * varname)
{
	char * 	eptr;
	char *	getenv(char *);

	/* ---------------------- */
	/* Set Signal Module Name */
	/* ---------------------- */
	if (!( modulename ))
		strcpy( idbuffer,"stdsignal");
	else	strcpy( idbuffer,modulename);

	/* ---------------------------- */
	/* Collect environment variable */
	/* ---------------------------- */
	if (!( varname )) { varname = "STDSIGNAL"; }

	if (!( eptr = getenv(varname)))
		SignalFlags = -1;
	else	{
		/* ------------------------ */
		/* Determine HEX mask value */
		/* ------------------------ */
		SignalFlags = 0;

		if (( *eptr == '/' ) || ( *eptr == 'x' ) || ( *eptr == 'X' )) {
			eptr++;
			}
		while ( *eptr ) {
			if (( *eptr >= '0' ) && ( *eptr <= '9' ))
				SignalFlags = ((SignalFlags * 16) + (*(eptr++) - '0'));
			if (( *eptr >= 'A' ) && ( *eptr <= 'F' ))
				SignalFlags = ((SignalFlags * 16) + ((*(eptr++) - 'A')+10));
			if (( *eptr >= 'a' ) && ( *eptr <= 'f' ))
				SignalFlags = ((SignalFlags * 16) + ((*(eptr++) - 'a')+10));
			else	break;
			}
		}

	if ( SignalFlags ) {

		/* ---------------------------------------- */
		/* Signals that may be trapped : or default */
		/* ---------------------------------------- */
#ifdef	SIGBUS
		if ( SignalFlags & 1 )
			standard_trap_signal(SIGBUS);
		else	standard_default_signal(SIGBUS);
#endif
#ifdef	SIGSEGV
		if ( SignalFlags & 2 )
			standard_trap_signal(SIGSEGV);
		else	standard_default_signal(SIGSEGV);
#endif
#ifdef	SIGILL

		if ( SignalFlags & 4 )
			standard_trap_signal(SIGILL);
		else	standard_default_signal(SIGILL);
#endif
#ifdef	SIGFPE

		if ( SignalFlags & 8 )
			standard_trap_signal(SIGFPE);
		else	standard_default_signal(SIGFPE);
#endif
#ifdef	SIGINT
		if ( SignalFlags & 0x0010)
			standard_trap_signal(SIGINT);
		else	standard_default_signal(SIGINT);
#endif
#ifdef	SIGTERM
		if ( SignalFlags & 0X0020)
			standard_trap_signal(SIGTERM);
		else	standard_default_signal(SIGTERM);
#endif
#ifdef	SIGHUP
		if ( SignalFlags & 0X0040)
			standard_trap_signal(SIGHUP);
		else	standard_default_signal(SIGHUP);
#endif
#ifdef	SIGPIPE
		if ( SignalFlags & 0X0080)
			standard_trap_signal(SIGPIPE);
		else	standard_default_signal(SIGPIPE);
#endif
		/* ---------------------------------------- */
		/* Signals that may be ignored : or default */
		/* ---------------------------------------- */
#ifdef	SIGALRM
		if ( SignalFlags & 0x0100 )
			standard_ignore_signal(SIGALRM);
		else	standard_default_signal(SIGALRM);

#endif
#ifdef	SIGUSR2
		if ( SignalFlags & 0x0200 )
			standard_ignore_signal(SIGUSR2);
		else	standard_default_signal(SIGUSR2);
#endif
#ifdef	SIGUSR1

		if ( SignalFlags & 0x0400 )
			standard_ignore_signal(SIGUSR1);
		else	standard_default_signal(SIGUSR1);
#endif
#ifdef	SIGCHLD

		if ( SignalFlags & 0x0800 )
			standard_ignore_signal(SIGCHLD);
		else	standard_default_signal(SIGCHLD);
#endif
#ifdef	SIGTSTP
		if ( SignalFlags & 0x1000 )
			standard_ignore_signal(SIGTSTP);
		else	standard_default_signal(SIGTSTP);
#endif
#ifdef	SIGPWR
		if ( SignalFlags & 0x2000 )
			standard_ignore_signal(SIGPWR);
		else	standard_default_signal(SIGPWR);
#endif
#ifdef	SIGSYS
		if ( SignalFlags & 0x4000 )
			standard_ignore_signal(SIGSYS);
		else	standard_default_signal(SIGSYS);
#endif
		}
	return( SignalFlags );
}


#endif	/* _stdsignal_c */
	/* ------------ */


