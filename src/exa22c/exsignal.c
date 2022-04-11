/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXSIGNAL - C				*/
/*		Version :	1.4c / 2.1a				*/
/*		Date 	:	28/01/1993				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef  EXSIGNALC
#define  EXSIGNALC

#ifndef  PROLOGUE
#ifndef  DOS

#ifdef RT_AIX
EXTERN EX_FILE_HANDLE TcodeFileHandle;	/* Numero logique du fichier		*/
#endif

#include "xsignal.c"		/* Signal function definition		*/

#ifdef	LINUX
#include <syslog.h>
#include <setjmp.h>
jmp_buf	signalfailure;
#define	preparesignalfailure(v) if ((v = setjmp(signalfailure))!=0) return(v)
#else
#define	preparesignalfailure(v) 
#endif

int	SignalFlags=0xFFFF;	/* all signals on and syslog active */

/*
 *	E X A S O R T I E ( sigid )
 *	---------------------------
 *	Allows reception of the signal SIGTERM : SOFTWARE TERMINATION
 *	and performs a graceful exit to the operating system after
 *	terminal liberation and Purge of Co-Executeur Locking Infos
 */
static	int  ExaPanic=0;
static	void ExaSortie( sigid )
int	sigid;
{
	char 	xbuffer[256];

#if defined(RT_AIX) || defined(LINUX)
EX_FILE_HANDLE	CloseTcodeFile();
#endif

#ifdef	LINUX
	switch ( sigid ) {
		case	SIGILL	:
		case	SIGSEGV	:
		case	SIGFPE	:
		case	SIGBUS	:
			sprintf(xbuffer,"\nexa critical failure : signal %u, pid %u \n",sigid,getpid());
			if ( SignalFlags & 0x8000 )
				syslog(LOG_CRIT,xbuffer);
			longjmp( signalfailure, sigid );
		default		:
			sprintf(xbuffer,"\nexa failure : signal %u, pid %u \n",sigid,getpid());
			if ( SignalFlags & 0x8000 )
				syslog(LOG_WARNING,xbuffer);
		}
#endif
	if (!( ExaPanic )) {
		ExaPanic++;
	if (( sigid != SIGHUP ) 
	&&  ( sigid != SIGPIPE )) {
						/* -------------------- */
		(void) x_newlyne();		/* Newline Feed		*/
#ifdef SPARC
	        (void) modterm(1);		/* forcer le reset ecran*/
#endif
		if (!( close_console()))
			(void) finterm(0);	/* stty sane please	*/

		}
	else	(void) finterm(0);

#if defined(RT_AIX) || defined(LINUX)
	/* ----------------------------------------- */
	/* un con avait mis ceci apres le si_fin() ! */
	/* ----------------------------------------- */
	TcodeFileHandle = CloseTcodeFile( TcodeFileHandle );
#endif

#ifdef ABAL_CRITERIA
	(void) si_fin();		/* IsamEnd		*/
#endif

#ifdef	COEXA
	(void) PurgeLox();		/* liberate all files	*/
#endif
	}

	exit(sigid);			/* and die gracefully	*/
					/* -------------------- */
}

void	catch_sigterm()
{
	(void) signal(SIGTERM,ExaSortie);
	return;
}

void	ignore_sigterm()
{
	(void) signal(SIGTERM,SIG_IGN);
	return;
}

void	default_sigterm()
{
	(void) signal(SIGTERM,SIG_DFL);
	return;
}

/*
 *	E X S I G N A L ( sigid )
 *	-------------------------
 *	Performs system exception signal management for Executeur under 
 *	UNIX like operating systems that offer the SIGNAL() function
 *		sigid = Signal number
 *	Note : 
 *		Sigid = 0	==>	Initialise signal trapping
 *		Sigid = 99	==>	Liberate signal trapping
 *
 */	

#define	signalmessage(a)

void	exsignal( sigid )
int	sigid;
{
	char	*	eptr;
	switch ( sigid ) {
		case 0  :
			if (!( eptr = getenv( "EXSIGNAL") ))
				SignalFlags = 0xFFFF;
			else	{
				SignalFlags = 0;
				while ( *eptr ) {
					if (( *eptr >= 'A' )
					&&  ( *eptr <= 'F' ))
						SignalFlags = ((SignalFlags * 16) + ( *(eptr++) - 'A' ) + 10 );
					else if (( *eptr >= 'a' )
					     &&  ( *eptr <= 'f' ))
						SignalFlags = ((SignalFlags * 16) + ( *(eptr++) - 'a' ) + 10 );
					else if (( *eptr >= '0' )
					     &&  ( *eptr <= '9' ))
						SignalFlags = ((SignalFlags * 16) + ( *(eptr++) - '0' ) );
					else	break;
					}
				}
			/*	Initialisation of SIGNAL TRAP 			*/
			/* ----------------------------------------------- 	*/
			/* These are critical and will cause graceful exit 	*/
			/* ----------------------------------------------- 	*/ 
			if ( SignalFlags & 0x0001 ) {
				signalmessage("bus\r\n");
				(void) signal(	SIGBUS ,	ExaSortie);
				}
			if ( SignalFlags & 0x0002 ) {
				signalmessage("segv\r\n");
				(void) signal(	SIGSEGV,	ExaSortie);
				}
			if ( SignalFlags & 0x0004 ) {
				signalmessage("ill\r\n");
				(void) signal(	SIGILL,		ExaSortie);
				}
			if ( SignalFlags & 0x0008 ) { 
				signalmessage("fpe \r\n");
				(void) signal(	SIGFPE,		ExaSortie);
				}
			if ( SignalFlags & 0x0010 ) {
				signalmessage("int \r\n");
				(void) signal(	SIGINT ,	ExaSortie);
				}
			if ( SignalFlags & 0x0020 ) {
				signalmessage("term\r\n");
				(void) signal(	SIGTERM	,	ExaSortie);
				}
			if ( SignalFlags & 0x0040 ) {
				signalmessage("hup\r\n");
				(void) signal(	SIGHUP,		ExaSortie);
				}
			if ( SignalFlags & 0x0080 ) {
				signalmessage("pipe\r\n");
				(void) signal(	SIGPIPE,	ExaSortie);
				}
			/* These are simply ignored for now 		 	*/
			/* ----------------------------------------------- 	*/
			if ( SignalFlags & 0x0100 ) {
				(void) signal(	SIGALRM,	SIG_IGN);
				}
			if ( SignalFlags & 0x0200 ) {
				(void) signal(	SIGUSR2,	SIG_IGN);
				}
			if ( SignalFlags & 0x0400 ) {
				(void) signal(	SIGUSR1,	SIG_IGN);
				}
			if ( SignalFlags & 0x0800 ) {
				(void) signal(	SIGCHLD,	SIG_IGN);
				}
	 
#if defined(RT_AIX) || defined(LINUX)
			/* These are possbile and specific to LINUX and POSIX 	*/
			/* -------------------------------------------------- 	*/
			if ( SignalFlags & 0x1000 ) {
				(void) signal(SIGTSTP,ExaSortie);
				}
			if ( SignalFlags & 0x2000 ) {
				(void) signal(SIGPWR ,ExaSortie);
				}
			if ( SignalFlags & 0x4000 ) {
				(void) signal(SIGSYS ,ExaSortie);
				}
#endif
			break;

		case 99 :	/* Liberation of Trapped Signals */
				/* ----------------------------- */
				/* These are critical and will cause graceful exit 	*/
				/* ----------------------------------------------- 	*/
				if ( SignalFlags & 0x0001 )
					(void) signal(	SIGBUS ,	SIG_IGN);
				if ( SignalFlags & 0x0002 )
					(void) signal(	SIGSEGV,	SIG_IGN);
				if ( SignalFlags & 0x0004 )
					(void) signal(	SIGILL,		SIG_IGN);
				if ( SignalFlags & 0x0008 )
					(void) signal(	SIGFPE,		SIG_IGN);
				if ( SignalFlags & 0x0010 )
					(void) signal(	SIGINT ,	SIG_IGN);
				if ( SignalFlags & 0x0020 )
					(void) signal(	SIGTERM	,	SIG_IGN);
				if ( SignalFlags & 0x0040 )
					(void) signal(	SIGHUP,		SIG_IGN);
				if ( SignalFlags & 0x0080 )
					(void) signal(	SIGPIPE,	SIG_IGN);
				if ( SignalFlags & 0x0100 )

				/* These are simply ignored for now 		 	*/
				/* ----------------------------------------------- 	*/
				if ( SignalFlags & 0x0200 )
					(void) signal(	SIGALRM,	SIG_IGN);
				if ( SignalFlags & 0x0400 )
					(void) signal(	SIGUSR2,	SIG_IGN);
				if ( SignalFlags & 0x0800 )
					(void) signal(	SIGUSR1,	SIG_IGN);
				if ( SignalFlags & 0x1000 )
					(void) signal(	SIGCHLD,	SIG_IGN);
	 
#if defined(RT_AIX) || defined(LINUX)
				/* These are possbile and specific to LINUX and POSIX 	*/
				/* -------------------------------------------------- 	*/
				if ( SignalFlags & 0x2000 )
					(void) signal(SIGTSTP,SIG_IGN);
				if ( SignalFlags & 0x4000 )
					(void) signal(SIGPWR ,SIG_IGN);
				if ( SignalFlags & 0x8000 )	
					(void) signal(SIGSYS ,SIG_IGN);
#endif
				break;

		default :	/* Handling of Received signals : it can't happen here  */
				/* ---------------------------------------------------- */
				(void) x_newlyne();
				(void) x_cprintf((BPTR)TalkPtr[12]);
				(void) x_putch(' ');
				(void) intvisi( sigid );
				(void) eder(err_val);
				(void) exsignal( 99 );
				exit(1000+sigid);
		}
	return;
}	

int	panic(int sid )
{
	switch ( sid ) {
		case	SIGKILL	:
			sid = SIGTERM;
		case	SIGBUS	:
		case	SIGSEGV	:
		case	SIGILL 	:
		case	SIGFPE 	:
		case	SIGTERM	:
		case	SIGHUP	:
		case	SIGPIPE	:
			ExaSortie(sid);
			exit(1);
		}
	return(1);
}

	/* ------------ */
#endif	/* ! DOS 	*/
#endif	/* ! PROLOGUE	*/
#endif	/* ! EXSIGNALC	*/
	/* ------------ */


