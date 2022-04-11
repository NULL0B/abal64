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

/*
 *	E X A S O R T I E ( sigid )
 *	---------------------------
 *	Allows reception of the signal SIGTERM : SOFTWARE TERMINATION
 *	and performs a graceful exit to the operating system after
 *	terminal liberation and Purge of Co-Executeur Locking Infos
 */

static	void ExaSortie( sigid )
int	sigid;
{
	char 	xbuffer[64];
#if defined(RT_AIX) || defined(LINUX)
EX_FILE_HANDLE	CloseTcodeFile();
#endif

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

#ifdef ABAL_CRITERIA
	(void) si_fin();		/* IsamEnd		*/
#endif

#ifdef	COEXA
	(void) PurgeLox();		/* liberate all files	*/
#endif
#if defined(RT_AIX) || defined(LINUX)
     TcodeFileHandle = CloseTcodeFile( TcodeFileHandle );
#endif
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

void	exsignal( sigid )
int	sigid;
{
	char	*	eptr;
	switch ( sigid ) {
		case 0  :	/* Initialisation of SIGNAL TRAP */
				/* ----------------------------- */
#if !defined(SPARC) && !defined(AIX) /* IJM Captain's Log Below && !defined(LINUX) */
				if (!(eptr = getenv("EXSIGNAL"))) {
					(void) signal(SIGBUS ,exsignal);
					(void) signal(SIGSEGV,exsignal);
					}
#endif
				catch_sigterm();
				(void) signal(SIGHUP,ExaSortie);
				(void) signal(SIGPIPE,ExaSortie);
#if defined(RT_AIX) || defined(LINUX)
				(void) signal(SIGTSTP,ExaSortie);
				(void) signal(SIGALRM,SIG_IGN);
				(void) signal(SIGINT ,ExaSortie);
				(void) signal(SIGUSR2,SIG_IGN);
				(void) signal(SIGUSR1,SIG_IGN);
				/* This is important to avoid zombies */
				/* ---------------------------------- */

				(void) signal(SIGCHLD,SIG_IGN);
	 
#endif
				break;

		case 99 :	/* Liberation of Trapped Signals */
				/* ----------------------------- */
#if !defined(SPARC) && !defined(AIX) /* see above && !defined(LINUX) */
				if (!(eptr = getenv("EXSIGNAL"))) {
					(void) signal(SIGBUS , SIG_DFL );
					(void) signal(SIGSEGV, SIG_DFL );
					}
#endif
				default_sigterm();
				(void) signal(SIGHUP,  SIG_DFL );
				(void) signal(SIGPIPE,  SIG_DFL );
#if defined(RT_AIX) || defined(LINUX)

				(void) signal( SIGCHLD,	SIG_DFL	);		
 
				(void) signal( SIGTSTP,	SIG_DFL	);
				(void) signal( SIGALRM,	SIG_DFL	);
				(void) signal( SIGINT,	SIG_DFL	);
				(void) signal( SIGUSR2,	SIG_DFL	);
				(void) signal( SIGUSR1,	SIG_DFL	);
#endif
				break;

#ifdef	LINUX
		/* --------------------------------------- */
		/* IJM : Captain's Log StarDate 29/03/2002 */
		/* --------------------------------------- */
		/* The signal handling has been restored   */
		/* and reworked to effectivly trap these   */
		/* two clingons ... We need to clean out   */
		/* Criteria/Access/Cico not to mention X11 */
		/* To boldly go where no man went before   */
		/* --------------------------------------- */
		case	SIGBUS	:
		case	SIGSEGV	:
				(void) signal(SIGBUS , SIG_DFL );
				(void) signal(SIGSEGV, SIG_DFL );
				exsignal(99);
				ExaSortie(sigid);
#endif
		default :	/* Handling of Received signals  */
				/* ----------------------------- */
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

void	panic(int sid )
{
	switch ( sid ) {
		case	SIGTERM	:
		case	SIGHUP	:
		case	SIGPIPE	:
			ExaSortie(sid);
			exit(1);
		}
	return;
}

	/* ------------ */
#endif	/* ! DOS 	*/
#endif	/* ! PROLOGUE	*/
#endif	/* ! EXSIGNALC	*/
	/* ------------ */

