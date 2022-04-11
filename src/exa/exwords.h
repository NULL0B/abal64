#ifndef	_exwords_h
#define	_exwords_h

#ifdef	VERSION_XX
#include "exvtype.h"
EXTERN	EXAWORD	ISLOCAL;
EXTERN	EXAWORD	TOGLOBAL;
#endif

#ifdef	VERSION666
EXTERN EXAWORD	ExaWordMask;
EXTERN EXAWORD  ExaWordSize;
EXTERN EXAWORD  ExaPtrSize;
EXTERN EXAWORD  MinusOne;
#ifndef	PTRSIZE
#define PTRSIZE ExaPtrSize
#endif
#else
#define	ExaWordMask 0xFFFF
#define	ExaWordSize 2
#define	ExaPtrSize 5
#endif

#define	TCPREFIX	(9*WORD16SIZE)
#define	BYTESIZE	sizeof( BYTE )
#define	MAXBCDSIZE	12
#define	ABALWORDSIZE	WORD16SIZE

#endif	/* _exwords_h */







