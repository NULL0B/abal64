#ifndef	_xsignal_c
#define	_xsignal_c

#include "xsignal.h"

#ifdef	LINUX

/*
 *	03/03/2002 : IJM 
 *	----------------
 *
 *	This file has been created with the function :
 *
 *		X_SIGNAL( signal, action )
 *	
 *	to ensure multiple shot signal action behaviour as was
 *	the case for UNIX BSD and friends.
 *
 */


void	*	signal( int sig, __sighandler_t handler )
{

	struct	sigaction	new_sa;
	struct	sigaction	old_sa;

	int			ret;

	new_sa.sa_handler = handler;

	/* ---------------------------------------------- */ 
	/* The LINUX signal() function sets this field as */
	/* ---------------------------------------------- */ 
	/* new_sa.sa_flags = (SA_ONESHOT | SA_NOMASK); 	  */
	/* ---------------------------------------------- */ 
	/* The flags are cleared : MULTIPLE SHOT	  */	
	/* ---------------------------------------------- */
	new_sa.sa_flags    = 0;

	ret = sigaction( sig, &new_sa, &old_sa );

	return((void *) ( ret ? ret : old_sa.sa_handler ) );

}

#endif	/* LINUX */

#endif	/* _xsignal_c */

