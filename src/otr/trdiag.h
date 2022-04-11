#ifndef	_TRDIAG_H
#define	_TRDIAG_H

#include "alm.h"

#ifdef	PROLOGUE
#define	_DCMD_SERVER	"\0b4.dcmd-xp"
#else
#define	_DCMD_SERVER	"dcmd.dll"
#endif

#ifdef	_TRDIAG_C

struct	_otr_alm_diag	{
	WORD		phase;
	ALM_ERROR	status;
	ALM_IDENTITY 	identity;
	ALM_HANDLE 	handle;
	ALM_INIT 	init;
	} Alm;
#endif

#endif	/* _TRDIAG_H */
	/* --------- */








