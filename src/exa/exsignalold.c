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

#include <signal.h>		/* Signal function definitions header	*/

#ifdef RT_AIX
EXTERN EX_FILE_HANDLE TcodeFileHandle;	/* Numero logique du fichier		*/
#endif


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
#ifdef	UNIX
EX_FILE_HANDLE	CloseTcodeFile();
#endif
					/* -------------------- */
	(void) x_newlyne();		/* Newline Feed		*/
#ifdef SPARC
        (void) modterm(1);		/* forcer le reset ecran*/
#endif
	(void) finterm(0);		/* stty sane please	*/
#ifdef	UNIX
     TcodeFileHandle = CloseTcodeFile( TcodeFileHandle );
#endif
#ifdef ABAL_CRITERIA
	(void) si_fin();		/* IsamEnd		*/
#endif

#ifdef	COEXA
	(void) PurgeLox();		/* liberate all files	*/
#endif
	exit(0);			/* and die gracefully	*/
					/* -------------------- */
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
	switch ( sigid ) {
		case 0  :	/* Initialisation of SIGNAL TRAP */
				/* ----------------------------- */
#if !defined(SPARC) && !defined(AIX) && !defined(LINUX)
				(void) signal(SIGBUS ,exsignal);
				(void) signal(SIGSEGV,exsignal);
#endif
				(void) signal(SIGTERM,ExaSortie);
				(void) signal(SIGHUP,ExaSortie);
#if defined(RT_AIX) || defined(LINUX)
				(void) signal(SIGTSTP,ExaSortie);
				(void) signal(SIGALRM,SIG_IGN);
				(void) signal(SIGUSR2,ExaSortie);
#endif
				break;

		case 99 :	/* Liberation of Trapped Signals */
				/* ----------------------------- */
#if !defined(SPARC) && !defined(AIX) && !defined(LINUX)
				(void) signal(SIGBUS , SIG_DFL );
				(void) signal(SIGSEGV, SIG_DFL );
#endif
				(void) signal(SIGTERM, SIG_DFL );
				(void) signal(SIGHUP,  SIG_DFL );
#if defined(RT_AIX) || defined(LINUX)
				(void) signal(SIGTSTP, SIG_DFL );
				(void) signal(SIGALRM,SIG_IGN  );
				(void) signal(SIGUSR2,SIG_DFL  );
#endif
				break;

		default :	/* Handling of Recieved signals  */
				/* ----------------------------- */
				(void) x_newlyne();
				(void) x_cprintf((BPTR)TalkPtr[12]);
				(void) x_putch(' ');
				(void) intvisi( sigid );
				(void) eder(err_val);
				(void) exsignal( 99 );
				exit(0);
		}
	return;
}	

	/* ------------ */
#endif	/* ! DOS 	*/
#endif	/* ! PROLOGUE	*/
#endif	/* ! EXSIGNALC	*/
	/* ------------ */
