#ifndef	_HTTPCNX_H
#define	_HTTPCNX_H

#define	tcp_server_connection( u, s ) open_connection( SOCK_STREAM, s , u )
#define udp_server_connection( u, s ) open_connection( SOCK_DGRAM,  s , u )
#define	tcp_client_connection( u )    open_connection( SOCK_STREAM, 0, u )
#define udp_client_connection( u )    open_connection( SOCK_DGRAM,  0, u )

PUBLIC	CONNECTIONPTR	open_connection ( INT, INT, URLPTR );
PUBLIC	CONNECTIONPTR	close_connection( CONNECTIONPTR );
PUBLIC	CONNECTIONPTR	drop_connection( CONNECTIONPTR );
PUBLIC	VOID		show_connection ( CONNECTIONPTR );
PUBLIC	CONNECTIONPTR	copy_connection ( CONNECTIONPTR );
PUBLIC	CONNECTIONPTR	establish_connection ( CONNECTIONPTR, URLPTR );
PUBLIC	INT		resolve_internet_host( URLPTR );

#endif	/* _HTTPCNX_H */
	/* ---------- */

