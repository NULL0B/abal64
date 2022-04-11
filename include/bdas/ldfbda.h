#ifndef	_LDFBDA_H
#define	_LDFBDA_H

#include "bda.h"

/* function scope definitions */

#ifndef public
#define public
#endif

#ifndef private
#define private static
#endif

/* dynamic library interface functions */

public EXAWORD	LdfBdaInitialise(BDA_INIT FAR PTR, EXAWORD);
public EXAWORD	LdfBdaExecute(EXAWORD, EXAWORD, BYTE FAR [], VOID FAR PTR FAR [], EXAWORD FAR [],int *);
public EXAWORD	LdfBdaTerminate();
public EXAWORD	LdfBdaInformation(void *);

/* collect a logical C value from an ABAL variable */

public EXAWORD  GetAbalInt8(char FAR * vptr);
public EXAWORD  GetAbalInt16(BYTE FAR * vptr);
public EXAWORD  GetAbalInt32(BYTE FAR * vptr);
public EXAWORD  GetAbalInt64(BYTE FAR * vptr);

/* store a logical C value from an ABAL variable */

public void PutAbalInt8(char FAR * vptr, EXAWORD v);
public void PutAbalInt16(BYTE FAR * vptr, EXAWORD v);
public void PutAbalInt32(BYTE FAR * vptr, EXAWORD v);
public void PutAbalInt64(BYTE FAR * vptr, EXAWORD v);

#endif	/* _LDFBDA_H */
	/* --------- */



