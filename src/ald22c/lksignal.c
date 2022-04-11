/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 2002
 *	Module  : T-CODE
 *	Fichier : LKSIGNAL.C
 *	Version : 2.2b
 *	Date    : 09/10/95
 *	Systeme : Tous
 *
 *	Linker                               
 *
 *	[Noyau ALD - Linker]
 *
 */

 /* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	------------ 2.2b -------------------------------------------------
 */

#ifdef UNIX

#ifndef  PROLOGUE
#ifndef  DOS

#include <signal.h>		/* Signal function definitions header	*/

#include "aldtype.h"


/*
 *	E X A S O R T I E ( sigid )
 *	---------------------------
 *	Allows reception of the signal SIGTERM : SOFTWARE TERMINATION
 *	and performs a graceful exit to the operating system after
 *	terminal liberation and Purge of Co-Executeur Locking Infos
 */
extern	int init_term;
static	void LibSortie( sigid )
int	sigid;
{
					/* -------------------- */
	if (init_term) 
		(void) finterm(0);	/* stty sane please	*/
	
	#ifndef __WALD__
	lkprintf("\r\n");
	#endif
	(void) PurgeLox();		/* liberate all files	*/

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

void	libsignal( sigid )
int	sigid;
{
	char	buffer[64];

	switch ( sigid ) {
		case 0  :	/* Initialisation of SIGNAL TRAP */
				/* ----------------------------- */
/* #IJM 06/11/02
				(void) signal(SIGBUS ,libsignal);
				(void) signal(SIGSEGV,libsignal);
*/
				(void) signal(SIGTERM,LibSortie);
				break;

		case 99 :	/* Liberation of Trapped Signals */
				/* ----------------------------- */
/* #IJM 06/11/02
				(void) signal(SIGBUS , SIG_DFL );
				(void) signal(SIGSEGV, SIG_DFL );
*/
				(void) signal(SIGTERM, SIG_DFL );
				break;

		default :	/* Handling of Recieved signals  */
				/* ----------------------------- */

				if ( init_term ) {
					(void) x_cprintf("\r\n");
					(void) x_cprintf("   Erreur Signal : ");
					(void) x_putch(' ');
					(void) sprintf(buffer,"%u",sigid);
					(void) x_cprintf(buffer);
					}
				else 	{
					#ifndef __WALD__
					lkprintf("\r\n   Erreur Signal : %d", sigid);
					#endif
					}
				(void) libsignal( 99 );
				LibSortie( 99 );				
		}
	return;
}	
	/* ------------ */
#endif	/* ! DOS 	*/
#endif	/* ! PROLOGUE	*/
	/* ------------ */
#endif	/* unix 	*/





