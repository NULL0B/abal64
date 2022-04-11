#ifndef	_ldfbda_h
#define	_ldfbda_h

#include "bda.h"

WORD LdfBdaTerminate();
WORD LdfBdaExecute(WORD,WORD,BYTE FAR [],VOID FAR PTR FAR [],WORD FAR []);
WORD LdfBdaInitialise(BDA_INIT FAR PTR,	WORD);

#endif  /* _ldfbda_h */


