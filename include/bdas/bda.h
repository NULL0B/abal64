/*
 *	BDA.H	:	06/09/2001
 *
 *	This file is an amalgamation by inclusion of the BDA inclusions
 *	recovered from the windows versions, qualified for use for Twin
 *	Server 16 bit modules and completed for Twin Server 32 bit Linux
 *	modules.
 *
 */

#ifndef	_BDA_H
#define	_BDA_H

// include the 'system' definitions

#ifdef	__OLD_BDA__
#include "oldbda.h"
#else
#include "wdef.h"
#include "pubsbda.h"
#include "pubwbda.h"
#endif

// define the ABAL type

#ifndef	EXABYTE
#define	EXABYTE	BYTE
#endif

#ifndef	EXAWORD
#ifdef	VERSION666
#ifdef	ABAL64
#define	EXAWORD	HUGE
#else
#define	EXAWORD	LONG
#endif
#else
#define	EXAWORD	WORD
#endif
#endif

#ifndef	EXALONG
#define	EXALONG	LONG
#endif

#ifndef	EXAHUGE
#define	EXAHUGE HUGE
#endif

#ifndef	BDA_API
#define	BDA_API
#endif


#endif	/* BDA_H */
	/* ----- */

