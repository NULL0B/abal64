#ifndef	_SERVER_H
#define	_SERVER_H

#ifdef	_SERVER_C
PRIVATE	INT	ServerStarted=0;
PRIVATE	BPTR	AdminName=(BPTR) 0;
PRIVATE	URLPTR	Administrator=(URLPTR) 0;
PUBLIC 	INT 	silence=0;
#else
EXTERN	INT	silence;
#endif

PUBLIC	VOID	set_server_silence( BPTR );
PUBLIC	VOID	set_server_verbose( BPTR );
PUBLIC	VOID	set_server_debug( BPTR );
PUBLIC	VOID	set_server_master( BPTR );
PUBLIC	VOID	show_server_usage();
PUBLIC	INT 	is_authorised( ADDRPTR );

#ifdef	_TRACE_H
PUBLIC	VOID	set_server_trace( BPTR );
#endif

PUBLIC	INT	start_server();
PUBLIC	INT	close_server();

#endif	/* _SERVER_H */
	/* --------- */

