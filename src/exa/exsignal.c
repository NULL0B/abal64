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

/* Mises a jour :
 * ------------
 * 12/12/12: Traitement asynchrone de la sortie d'exa sur reception de signal (SIGTERM, ...)
 * 24/02/16: Suppression modification du 12/12/12 suite correction dans Criteria (coshm.c)
 */

#ifndef  EXSIGNALC
#define  EXSIGNALC

#ifndef  PROLOGUE
#ifndef  DOS

#ifdef RT_AIX
EXTERN EX_FILE_HANDLE TcodeFileHandle;	/* Numero logique du fichier		*/
#endif

#include "xsignal.c"		/* Signal function definition		*/

#ifdef	UNIX 
#include "exasyslog.h"
#include <setjmp.h>
jmp_buf	signalfailure;
#define	preparesignalfailure(v) if ((v = setjmp(signalfailure))!=0) return(v)
#else
#define	preparesignalfailure(v) 
#endif

int 	SignalFlags = 0xFFFFFFFF;	/* all signals on and syslog active */
static	int 	ExaPanic = 0;

int get_child_pid();

/*	----------------	*/
/*	critical_message	*/
/*	----------------	*/
void	critical_message( message )
BPTR	message;
{
#ifdef	LINUX
	ExaSysLog(EXA_SYSLOG_CRITICAL, message);
#else
#ifdef	AIX
	ExaSysLog(EXA_SYSLOG_CRITICAL, message);
#else
	printf("%s",message);
#endif
#endif
	return;
}

/*	-----------------	*/
/*	 warning_message	*/
/*	-----------------	*/
static	void	warning_message( message )
BPTR	message;
{
#ifdef	LINUX
	ExaSysLog(EXA_SYSLOG_WARNING, message);
#else
#ifdef	AIX
	ExaSysLog(EXA_SYSLOG_WARNING, message);
#else
	printf("%s",message);
#endif
#endif
	return;
}

/*	--------------------	*/
/*	build_syslog_message	*/
/*	--------------------	*/
static	void	build_syslog_message( sigid, mptr, eptr) 
	int	sigid;
	BPTR 	mptr;
	BPTR	eptr;
	
{
	if ( sicico & ONSEM_PRC )
		sprintf(SysLogBuffer,"%s %s : %s : signal %u : ( procedure /%lx:%lx ) ", Exa, eptr, mptr, sigid ,procid*(WORDSIZE*8), fdex-TcodeSegment);
	else	sprintf(SysLogBuffer,"%s %s : %s : signal %u : ( segment    %lx:%lx ) ", Exa, eptr, mptr, sigid, cur_seg, fdex-TcodeSegment);
	return;
}

/*	-------------------	*/
/*	exa_failure_message	*/
/*	-------------------	*/
static	void	exa_failure_message(sigid)
	int	sigid;
{
	BPTR	eptr;
	BPTR	trace_tcode_filename();

	if (!(eptr = trace_tcode_filename()))
		eptr = "\0";

	build_syslog_message( sigid, "critical failure", eptr );	

	if ( SignalFlags & 0x8000 )
		critical_message(SysLogBuffer);
	else
		printf(SysLogBuffer);
	return;
}

/*	-----------------	*/
/*	exa_crash_message	*/
/*	-----------------	*/
static	void	exa_crash_message(char * mptr)
{
	BPTR	eptr;
	BPTR	trace_tcode_filename();

	if (!(eptr = trace_tcode_filename()))
		eptr = "\0";

	build_syslog_message( 0, mptr, eptr );	

	if ( SignalFlags & 0x8000 )
		critical_message(SysLogBuffer);
	else	printf(SysLogBuffer);
}

/*	---------------------	*/
/*	exa_application_error	*/
/*	---------------------	*/
void	exa_application_error(e)
WORD 	e;
{
	char	apperr[128];
	BPTR	eptr;
	BPTR	trace_tcode_filename();

	if (!(eptr = trace_tcode_filename()))
		eptr = "\0";

	sprintf(apperr,"application failure %u",e);
	build_syslog_message( 0, apperr, eptr );	

	if ( SignalFlags & 0x8000 )
		warning_message(SysLogBuffer);
	else	printf(SysLogBuffer);
	return;
}

/*	-----------------	*/
/*	exa_event_failure	*/
/*	-----------------	*/
void	exa_event_failure(e)
WORD 	e;
{
	char	apperr[128];
	BPTR	eptr;
	BPTR	trace_tcode_filename();

	if (!(eptr = trace_tcode_filename()))
		eptr = "\0";

	sprintf(apperr,"event failure %u",e);
	build_syslog_message( 0, apperr, eptr );	

	if ( SignalFlags & 0x8000 )
		warning_message(SysLogBuffer);
	else	printf(SysLogBuffer);
	return;
}

/*	-------------------	*/
/*	exa_warning_message	*/
/*	-------------------	*/
static	void	exa_warning_message(sigid)
	int	sigid;
{
	BPTR	eptr;
	BPTR	trace_tcode_filename();

	if (!(eptr = trace_tcode_filename()))
		eptr = "\0";

	build_syslog_message( sigid, "failure", eptr );	

	if ( SignalFlags & 0x8000 )
		warning_message(SysLogBuffer);
	else
		printf(SysLogBuffer);
	return;

}


/*
 *	ExaEndPanic( sigid )
 *	--------------------
 *	Performs a graceful exit to the operating system after
 *	terminal liberation and Purge of Co-Executeur Locking Infos
 */
static	void ExaEndPanic( sigid )
int	sigid;
{
	EX_FILE_HANDLE	CloseTcodeFile();
	
	switch ( sigid ) {
		case	SIGILL	:
		case	SIGSEGV	:
		case	SIGFPE	:
		case	SIGBUS	:
			exa_failure_message(sigid);
			longjmp( signalfailure, sigid );
		default		:
			exa_warning_message(sigid);
		}

#ifdef	ABAL32A
	if ( is_on_extern_event() ) {
		/* application requires notification of non-critical signals */
		/* --------------------------------------------------------- */
		
		/* #BG 19/07/16 Exclus SIGTERM
		   Sinon pb dans le cas ou la session du terminal est fermee sans quitter l'application
		*/
		if (sigid != SIGTERM) {
			std_signal_event(sigid);
			return;
			}
		}
#endif

	if (!ExaPanic) {
		/* 	Liberate Console Manager */
		/*	------------------------ */

		ExaPanic++;
		exa_crash_message("terminate console");	

		if (( sigid != SIGHUP )	&& ( sigid != SIGPIPE )) {
			(void) x_newlyne();		/* Newline Feed */
#ifdef SPARC
			(void) modterm(1);		/* Forcer le reset ecran */
#endif
/* #BG 25/02/16			if (!( close_console()))*/
			if ( close_console_panic() != 0 )
				(void) finterm(0);	/* stty sane please	*/
			}
		else
			(void) finterm(0);
		}
	else {
		exa_crash_message("double exception");	
		}
		
#ifdef	UNIX
	/* Close TCode file (before MA_fin()! */
	/* ---------------------------------- */
	exa_crash_message("terminate tcode");	
	TcodeFileHandle = CloseTcodeFile( TcodeFileHandle );
#endif

#ifdef ABAL_CRITERIA
	/* Liberate File Manager */
	/* --------------------- */
	exa_crash_message("terminate criteria");	
	MA_fin();		/* #BG 22/11/11 */
#endif

#ifdef	COEXA
	/* liberate all files */
	/* ----------------- */
	exa_crash_message("terminate access");	
	(void) PurgeLox();
#endif
	exa_crash_message("terminate exa");	
	
	/* And die gracefully */
	/* ------------------ */
	exit(sigid);			
}


/*
 *	OnSignalExaEnd( sigid )
 *	-----------------------
 *	Handler for reception of the signal SIGTERM and others: SOFTWARE TERMINATION
 */
static	void OnSignalExaEnd( sigid )
int	sigid;
{
	int	loadgopid;

	if (loadgopid = get_child_pid()) 
	{
		kill(loadgopid, SIGTERM);
	}

	ExaEndPanic(sigid);
}

/*	-------------	*/
/*	catch_sigterm	*/
/*	-------------	*/
void	catch_sigterm()
{
	(void) signal(SIGTERM, OnSignalExaEnd);
	return;
}

/*	--------------	*/
/*	ignore_sigterm	*/
/*	--------------	*/
void	ignore_sigterm()
{
	(void) signal(SIGTERM,SIG_IGN);
	return;
}

/*	---------------	*/
/*	default_sigterm	*/
/*	---------------	*/
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
				SignalFlags = 0xFFFFFFFF;
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
				(void) signal( SIGBUS, OnSignalExaEnd);
				}
			if ( SignalFlags & 0x0002 ) {
				signalmessage("segv\r\n");
				(void) signal( SIGSEGV, OnSignalExaEnd);
				}
			if ( SignalFlags & 0x0004 ) {
				signalmessage("ill\r\n");
				(void) signal( SIGILL, OnSignalExaEnd);
				}
			if ( SignalFlags & 0x0008 ) { 
				signalmessage("fpe \r\n");
				(void) signal( SIGFPE, OnSignalExaEnd);
				}
			if ( SignalFlags & 0x0010 ) {
				signalmessage("int \r\n");
				(void) signal( SIGINT, OnSignalExaEnd);
				}
			if ( SignalFlags & 0x0020 ) {
				signalmessage("term\r\n");
				(void) signal( SIGTERM, OnSignalExaEnd);
				}
			if ( SignalFlags & 0x0040 ) {
				signalmessage("hup\r\n");
				(void) signal( SIGHUP, OnSignalExaEnd);
				}
			if ( SignalFlags & 0x0080 ) {
				signalmessage("pipe\r\n");
				(void) signal( SIGPIPE, OnSignalExaEnd);
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
				(void) signal( SIGTSTP, OnSignalExaEnd);
				}
			if ( SignalFlags & 0x2000 ) {
				(void) signal( SIGPWR, OnSignalExaEnd);
				}
			if ( SignalFlags & 0x4000 ) {
				(void) signal( SIGSYS, OnSignalExaEnd);
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

/*	-----	*/
/*	panic	*/
/*	-----	*/
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
			ExaEndPanic(sid);
			exit(1);
		}
	return(1);
}

	/* ------------ */
#endif	/* ! DOS 	*/
#endif	/* ! PROLOGUE	*/
#endif	/* ! EXSIGNALC	*/
	/* ------------ */


