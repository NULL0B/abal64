#ifndef	_TRDIAG_C
#define _TRDIAG_C

#ifdef	USE_ALM
#define	ALM_DIAGNOSTICS
#endif

#include "trdiag.h"
#include "tralm.c"

ALM_ERROR	terminate_diagnostics()
{
#ifdef	ALM_DIAGNOSTICS
	if ( Alm.phase & 4 ) {
		Alm.status += ALM_drop(Alm.handle);
		Alm.phase  &= ~4;
		}
	if ( Alm.phase & 2 ) {
		Alm.status += ALM_forget(Alm.handle);
		Alm.phase &= ~2;
		}
	if ( Alm.phase & 1 ) {
		Alm.status += ALM_terminate( (ALM_IDENTITYPTR) & Alm.identity );
		Alm.phase &= ~1;
		}
#endif
	return( Alm.status );
}

ALM_ERROR	initialise_diagnostics()
{

	Alm.phase 	  = 0;
	Alm.status	  = 0;

#ifdef	ALM_DIAGNOSTICS

	if ( strlen( _DCMD_SERVER ) == 0 )
		return( 0 );

	Alm.identity.pid  = ALM_getpid();
	Alm.identity.ppid = ALM_getppid();

	if ((Alm.status = ALM_initiate( (ALM_IDENTITYPTR) & Alm.identity)) != 0)
		return( terminate_diagnostics() );
	else	Alm.phase |= 1;

	if ((Alm.handle = ALM_sharename((BPTR) _DCMD_SERVER,(ALM_ERRORPTR) & Alm.status)) == 0)
		return( terminate_diagnostics() );
	else	Alm.phase |= 2;


 	if ((Alm.status = ALM_load(Alm.handle,(ALM_INIT XPTR) & Alm.init,sizeof(ALM_INIT))) != 0)
 		return( terminate_diagnostics() );
 	else	Alm.phase |= 4;

#endif
	return( 0 );
}



#endif	/* _TRDIAG_C */
	/* --------- */



