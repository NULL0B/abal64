#ifndef	_TRAPPING_H
#define	_TRAPPING_H

#ifdef	_TRAPPING_C
	WORD	ExceptionCounter;
#else
EXTERN	WORD	ExceptionCounter;
#endif

struct	exception_context	{
	MEMBERPTR	member;
	MEMBERPTR	father;
	OBJECTPTR	object;
	WORD		adjust;
	WORD		ladjust;
	WORD		field;
	WORD		common;	
	WORD		identity;
	};

#define	TRAPPTR	struct exception_context XPTR

#ifdef	CHECK_PROTO_ARGS
TRAPPTR initiate_exception_handler(MEMBERPTR,OBJECTPTR,WORD,MEMBERPTR,WORD,WORD,WORD);
WORD    initiate_invariant_handler(MEMBERPTR,OBJECTPTR,WORD,MEMBERPTR,WORD,WORD,WORD);
#else
TRAPPTR initiate_exception_handler();
WORD    initiate_invariant_handler();
#endif

#endif	/* _TRAPPING_H */
	/* ----------- */
