#ifndef	_TRAPPING_H
#define	_TRAPPING_H

#ifdef	_TRAPPING_C
	EXAWORD	ExceptionCounter;
#else
EXTERN	EXAWORD	ExceptionCounter;
#endif

struct	exception_context	{
	MEMBERPTR	member;
	MEMBERPTR	father;
	OBJECTPTR	object;
	EXAWORD		adjust;
	EXAWORD		ladjust;
	EXAWORD		field;
	EXAWORD		common;	
	EXAWORD		identity;
	};

#define	TRAPPTR	struct exception_context XPTR

#ifdef	CHECK_PROTO_ARGS
TRAPPTR initiate_exception_handler(MEMBERPTR,OBJECTPTR,EXAWORD,MEMBERPTR,EXAWORD,EXAWORD,EXAWORD);
EXAWORD    initiate_invariant_handler(MEMBERPTR,OBJECTPTR,EXAWORD,MEMBERPTR,EXAWORD,EXAWORD,EXAWORD);
#else
TRAPPTR initiate_exception_handler();
EXAWORD    initiate_invariant_handler();
#endif

#endif	/* _TRAPPING_H */
	/* ----------- */

