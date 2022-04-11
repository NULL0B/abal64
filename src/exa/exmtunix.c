#ifndef	_EXLLSPWN_C
#define	_EXLLSPWN_C

#define ABALMT

#include <signal.h>

int	unix_parent_identity;

VOID liberate_tcode_stacks(VOID PTR ss )	{ return;    }

/*
 *	Task oriented operations
 *
 */

VOID reset_parent_identity()    
{ 
	unix_parent_identity = 0;
	return;
}
int	get_parent_identity()
{
	return(unix_parent_identity);  
}


int	low_level_spawn()
{ 
	int	forkret;
	if ((forkret = fork()) == 0) {
		/* child process */
		unix_parent_identity = getpid();
#ifdef	ABAL32A
		/* connect to criteria */
		/* activate the screen */
		EntryMain();
#endif
		}
	return(forkret); 
}

EXAWORD 	low_level_kill(n)
int	n;
{
	if (!( n )) {
		/* Detect and Handle Suicide */
		/* ------------------------- */
		exlbsm(); 	exit(getpid());
		}
	else	{
		/* otherwise signal death request */
		/* ------------------------------ */
		return(kill(n,SIGTERM)); 
		}
}

EXAWORD low_level_interrupt(n)
EXAWORD n;
{ 
	return(0); 
}

/*
 *	Semaphore oriented operations
 *
 */



EXAWORD low_level_drop(sptr)
BPTR	sptr;
{ 
	return(0); 
}

EXAWORD low_level_raise(sptr)
BPTR	sptr;
{
	return(0);
}

EXAWORD low_level_synch(sptr)
BPTR	sptr;
{
	return(0); 
}

#endif	/* _EXLLSPWN_C */
	/* ----------- */


