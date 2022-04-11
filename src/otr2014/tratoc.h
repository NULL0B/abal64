#ifndef	_TRATOC_H
#define	_TRATOC_H

#ifdef	PRIVATE_SCOPE
#define	PRIVATE PRIVATE_SCOPE
#else	
#define	PRIVATE static
#endif

#ifdef	PUBLIC_SCOPE
#define	PUBLIC PUBLIC_SCOPE
#else	
#define	PUBLIC
#endif

#ifdef	_TRATOC_C
#define	_ATOC_REGISTERS 77
PRIVATE WORD	AtocRegisters=0;
PRIVATE	BPTR	AtocRegister [_ATOC_REGISTERS];
PRIVATE	BPTR	AtocPrimary  [_ATOC_REGISTERS];
PRIVATE	BPTR	AtocSecondary[_ATOC_REGISTERS];
#endif

PUBLIC 	BPTR	atoc_integer( WORD, WORD );
PUBLIC	WORD	atoc_newline( WORD );

EXTERN	TCTYPPTR	resolve_method_type( VPTR );
EXTERN	TCVARPTR	resolve_method_parameters( VPTR );

#endif	/* _TRATOC_H */
	/* --------- */






