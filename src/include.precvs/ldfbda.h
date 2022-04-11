#ifndef	_LDFBDA_H
#define	_LDFBDA_H

#include "bda.h"

EXAWORD	LdfBdaInitialise(BDA_INIT FAR PTR, EXAWORD);
EXAWORD	LdfBdaExecute(EXAWORD, EXAWORD, BYTE FAR [], VOID FAR PTR FAR [], EXAWORD FAR [], EXAWORD FAR *);
EXAWORD	LdfBdaTerminate();

#endif	/* _LDFBDA_H */
	/* --------- */



