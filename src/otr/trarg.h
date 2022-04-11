#ifndef	_TRARG_H
#define	_TRARG_H

#define	ARGPTR	struct clf_operand XPTR

struct	clf_operand	{
#ifndef	_GEN_C_RTL
	RESULTPTR	operand;
#else
	BPTR		operand;
#endif
	WORD		nature;
	BPTR		format;
	ARGPTR		next;
	ARGPTR		prev;
	};

#ifdef	_TRCLF_C
	ARGPTR	ArgHeap;
#else	
EXTERN	ARGPTR	ArgHeap;
#endif

#ifndef	UNIX
VOID	initialise_operands( VOID );
VOID	liberate_operands( VOID );
VOID	release_operands( ARGPTR );
ARGPTR	allocate_for_operand( VOID );
#else
ARGPTR		allocate_for_operand();
#endif

#endif	/* _TRARG_H */
	/* -------- */


