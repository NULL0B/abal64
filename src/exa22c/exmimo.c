/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMIMO.C  				*/
/*		Date 	:	11/08/1993				*/
/*		Version :	2.1a					*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXMIMO_C
#define	_EXMIMO_C

#include "exos.h"
#include "stdtypes.h"
#include "exmimo.h"

void	*	malloc(int n); 
void		free(void * vptr);

void	*	allocate(int n)		{	return( malloc(n) ); 	} 
void	*	liberate(void * vptr)	{	if ( vptr ) free(vptr); return((void *) 0); }



/*	------------------------------------------------------		*/
/*	LOW LEVEL MOUSE INPUT MOUSE OUTPUT INTERFACE FUNCTIONS 		*/
/*      ------------------------------------------------------		*/
EXAWORD	activate_mimo()		{ 	return(0); 	}
EXAWORD	get_mimo_status()	{ 	return(0); 	}
EXAWORD	get_mimo()		{ 	return(0); 	}
EXAWORD	get_mimo_col()		{ 	return(0); 	}
EXAWORD	get_mimo_lin()		{ 	return(0);	}
EXAWORD	get_mimo_par()		{ 	return(0);	}
EXAWORD	get_mimo_mask()		{ 	return(0);	}
EXAWORD	get_mimo_type()		{ 	return(0);	}
EXAWORD	flush_mimo()		{ 	return(0);	}
EXAWORD	inhibit_mimo()		{ 	return(0);	}
EXAWORD	verify_wakeup_status(a) { 	return(a); 	}
EXAWORD	clear_wakeup_status()	{ 	return(0);	}

VOID	set_mimo_mask(v)
EXAWORD	v;
{
	return;
}

VOID	save_mimo_context( buffer )
BPTR	buffer;
{
	return;
}

VOID	restore_mimo_context( buffer )	
BPTR	buffer;
{ 
	return;	
}

EXAWORD	mimo_kbhit() 		{ 	return( x_kbhit() ); 	}
EXAWORD	mimo_getch() 		{ 	return( x_getch() ); 	}
EXAWORD	init_mimo()  		{ 	return(0); 		}
EXAWORD    fin_mimo()   		{ 	return(0); 		}
EXAWORD	start_mimo_alarm() 	{ 	return(0); 		}
EXAWORD	cancel_mimo_alarm() 	{ 	return(0); 		}
EXAWORD	simulate_mimo() 	{	return(0); 		}
BPTR	Mgetenv(char * nptr)
{
	char * getenv(char *);
 	return( getenv(nptr) ); 
}
EXAWORD	set_mimo_curser() 	{ 	return(0); 		}

#endif 	/* _EXMIMO_C */
	/* --------- */

