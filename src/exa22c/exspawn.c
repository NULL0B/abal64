#ifndef	_EXSPAWN_C
#define	_EXSPAWN_C

#ifdef	DOS

/*	---------------------------------------------------------	*/
/*	Dummy low level routines for semaphore management for DOS	*/
/*	---------------------------------------------------------	*/
/*	These functions are present in EXSPAWN.ASM for PROLOGUE 3	*/
/*	---------------------------------------------------------	*/

VOID	low_level_synch() 	{ return; 	}
VOID	low_level_drop() 	{ return; 	}
VOID	low_level_raise() 	{ return; 	}
VOID	low_level_kill() 	{ return; 	}
VOID	reset_parent_identity() { return; 	}
EXAWORD	get_parent_identity() 	{ return(0); 	}

#endif

#ifdef	UNIX

VOID	low_level_synch() 	{ return; 	}
VOID	low_level_drop() 	{ return; 	}
VOID	low_level_raise() 	{ return; 	}
VOID	low_level_kill() 	{ return; 	}
VOID	reset_parent_identity() { return; 	}
EXAWORD	get_parent_identity() 	{ return(0); 	}

#endif

#endif	/* _EXSPAWN_C */
	/* ---------- */
