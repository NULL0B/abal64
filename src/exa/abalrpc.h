#ifndef	_ABALRPC_H
#define	_ABALRPC_H

struct	abal_remote_procedure_context
{
	int	socket;			/* socket handle			*/
	int	calls;			/* nmuber of calls			*/
	int	errors;			/* number of errors			*/
	int	creation;		/* connection creation time stamp 	*/
	int	operation;		/* last operation time stamp		*/
};


#endif 	/* _ABALRPC_H */
	/* ---------- */

