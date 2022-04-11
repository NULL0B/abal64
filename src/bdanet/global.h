#ifndef	_GLOBAL_H
#define	_GLOBAL_H

#ifdef	_GLOBAL_C
PUBLIC	INT	verbose=0;
PUBLIC	INT	debug=0;
#else
EXTERN	INT	debug;
EXTERN	INT	verbose;
#endif

PUBLIC	BPTR 	HostSystemName();
PUBLIC	BPTR 	GetUserAgent();
PUBLIC	VOID 	SetUserAgent(BPTR);

PUBLIC	INT	integer_option( BPTR );
PUBLIC	INT	compare_tokens( BPTR, BPTR );
PUBLIC	VOID	set_global_verbose( BPTR );
PUBLIC	VOID	set_global_debug( BPTR );
PUBLIC	VPTR	allocate_zone( INT );
PUBLIC	VPTR	liberate_zone( VPTR );
PUBLIC	BPTR	socketname( ADDRPTR );
PUBLIC	BPTR	allocate_for_string( BPTR );
PUBLIC	VOID	show_global_usage( VOID );

PUBLIC	INT	wildcomp( BPTR , BPTR );

#endif	/* _GLOBAL_H */
	/* --------- */

