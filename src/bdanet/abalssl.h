#ifndef	_ABALSSL_H
#define	_ABALSSL_H

#ifdef SYSTEM_SSL
PUBLIC	INT	https_use_encryption(BPTR);
PUBLIC	INT	https_use_certificate(BPTR);
PUBLIC	INT	https_use_password(BPTR);

PUBLIC	INT	sslsocketwriter( SSL *, BPTR, INT );
PUBLIC	INT	ssl_tcp_read( SSL *, BPTR, INT );
PUBLIC	INT	ssl_tcp_readb( SSL * );
PUBLIC	INT	ssl_tcp_readw( SSL * );
#endif

#endif
