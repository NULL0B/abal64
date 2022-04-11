#ifndef	_exdbword_h
#define	_exdbword_h

#include "exwords.h"

#ifdef	ABAL64
	#define	WORDSIZE	ExaWordSize
	#define	PTRSIZE		ExaPtrSize
	extern	EXAWORD		WORDSIZE;
	extern	EXAWORD		PTRSIZE;
	#define	EXDB_FFFF 	ExadbMinusOne
	#define	BINAIRE	signed long long int

	#ifdef	_EXDBSYMB_C
		EXAWORD	EXDB_FFFF = MOINS_UN64;  
	#else
		extern	EXAWORD	EXDB_FFFF;
	#endif
#else

	#ifdef	VERSION666
		#define	WORDSIZE	ExaWordSize
		#define	PTRSIZE		ExaPtrSize
		extern	EXAWORD		WORDSIZE;
		extern	EXAWORD		PTRSIZE;
		#define	BINAIRE	signed long int
		#define	EXDB_FFFF ExadbMinusOne
		#ifdef	_EXDBSYMB_C
			EXAWORD	EXDB_FFFF = MOINS_UN16;  
		#else
			extern	EXAWORD	EXDB_FFFF;
		#endif
	#else
		#define	BINAIRE	signed short int
		#define	EXDB_FFFF MOINS_UN
	#endif
#endif

#endif	/* _exdbword_h */

