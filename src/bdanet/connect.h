#ifndef	_CONNECT_H
#define	_CONNECT_H

/*	---------------------------------------------------------	*/
/*	Definition of types and structures for connection control	*/
/*	---------------------------------------------------------	*/
#ifdef WIN32 
#define	SocketRead(a,b,c) 	recv(a,b,c,0)
#define	SocketWrite(a,b,c) 	send(a,b,c,0)
#define	SocketClose(a) 		closesocket(a)
#endif

#ifdef	UNIX
#define	SocketRead(a,b,c) 	socketreader(a,b,c)
#define	SocketWrite(a,b,c) 	socketwriter(a,b,c)

#define	SocketClose(a) 		close(a)
#else
#ifdef	PROLOGUE
#define	SocketRead(a,b,c) 	sread(a,b,c)
#define	SocketWrite(a,b,c) 	swrite(a,b,c)
#define	SocketClose(a) 		sclose(a)
#endif
#endif

#define	MAX_CLIENTS	16

#define	PERSISTANCE	struct persistant_connection
#define	CONNECTION	struct internet_connection
#define	CONNECTIONPTR	CONNECTION PTR

#include "cryptage.h"

CONNECTION	{
	INT		service;		/* Server Service Port	*/
	INT		flags;			/* Initial Options	*/
	INT		duplicate;		/* Indicates Duplicate	*/
	INT		status;			/* Connection status	*/
	LONG		alive;			/* Keep Alive Address	*/
	LONG		connected;		/* Address connected	*/
	URLPTR		remote;			/* Remote URL infos	*/
	INT		socket;			/* Connect   socket	*/
	INT		newsocket;		/* Accept    socket	*/
	ADDRESS		address;		/* Local  IP Address	*/
	INT		timeout;		/* Possible Time Out	*/
	INT		length;			/* Possible Size	*/
	INT		worker;			/* Do not close yet (UNIX=0/1 , WIN32=0/hThread)	*/
	CONNECTIONPTR	next;			/* These two pointers 	*/
	CONNECTIONPTR	previous;		/* Use by Keep Alive	*/
	INT		cryptage;		/* Indicates encrypt	*/
	CRYPTAGE  	coding;			/* Used to store the	*/	
	VOID	PTR	context;		/* SSL Context		*/
	VOID	PTR	object;			/* SSL Object		*/
	VOID	PTR	newobject;		/* SSL Object		*/
						/* Encryption state	*/
						/* variables		*/
	INT		is_ssl;			/* SSL connection	*/
	INT		certify;		/* enforce ceritfy	*/
	BPTR		hostname;		/* for certification	*/

	};

/*	--------------------------	*/
/*	Public Function Prototypes 	*/
/*	--------------------------	*/

PUBLIC	INT		resolve_internet_host( URLPTR );
PUBLIC	CONNECTIONPTR	open_connection ( INT, INT, URLPTR );
PUBLIC	CONNECTIONPTR	make_connection ( INT, INT, URLPTR, INT );
PUBLIC	CONNECTIONPTR	copy_connection ( CONNECTIONPTR);
PUBLIC	CONNECTIONPTR	accept_connection ( CONNECTIONPTR,INT );
PUBLIC	CONNECTIONPTR	establish_connection ( CONNECTIONPTR, URLPTR );
PUBLIC	VOID		show_connection ( CONNECTIONPTR );
PUBLIC	CONNECTIONPTR	close_connection( CONNECTIONPTR );
PUBLIC	CONNECTIONPTR	persist_connection( CONNECTIONPTR );
PUBLIC	VOID		clear_persistance();
PUBLIC	VOID		drop_connection( CONNECTIONPTR );
PUBLIC 	INT	select_connection( INT, INT );
PUBLIC  CONNECTIONPTR   liberate_for_connection( CONNECTIONPTR );

#ifdef	_BEFORE_20041999
#else
PUBLIC	INT		await_connection( CONNECTIONPTR, INT );
#endif

/*	----------------------------	*/
/*	Connection Macro Definitions 	*/
/*	----------------------------	*/

#define	connect_tcp_server( u, s ) open_connection( SOCK_STREAM, s , u )
#define connect_udp_server( u, s ) open_connection( SOCK_DGRAM,  s , u )
#define	connect_tcp_client( u )    open_connection( SOCK_STREAM, 0, u )
#define connect_udp_client( u )    open_connection( SOCK_DGRAM,  0, u )
#define	client_connection( u )	   open_connection( u->transport,0, u )

PUBLIC	INT	tcp_readb( INT );
PUBLIC	INT	tcp_readw( INT );
PUBLIC	INT	tcp_read( INT, BPTR, INT );
PUBLIC	INT	tcp_write( INT, BPTR, INT );

PUBLIC	INT	udp_peek( INT, URLPTR );
PUBLIC	INT	udp_read( INT, BPTR, INT, URLPTR );
PUBLIC	INT	udp_write( INT, BPTR, INT, URLPTR );
PUBLIC	VOID	drop_live_connections();
PUBLIC	VOID	keep_connection_alive( CONNECTIONPTR );
PUBLIC	VOID	connection_not_alive( CONNECTIONPTR );


	/* ---------- */
#endif	/* _CONNECT_H */
	/* ---------- */

