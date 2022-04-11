/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXUSER - H				*/
/*		Date 	:	09.02.1988				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef ExUserIpc		/* To avoid recursive inclusions */

#define	ExUserIpc		/* Inhibit further includes	 */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

/*
 *	Parameter definition structure
 *	------------------------------
 */

struct	ipc_param {
	key_t	key;		/* Message file Key value	*/
	long	max;		/* Maximum communication length	*/
	long	id;		/* Automate recieve ID value	*/
	int	perm;		/* Automate recieve permissions	*/
	int	opt;		/* Automate child semaphore	*/
};

#endif
