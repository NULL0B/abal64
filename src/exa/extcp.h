#ifndef	_EXTCP_H
#define	_EXTCP_H

#include "exnetwork.h"

int	connect_tcp( char * host, int port );
int	listen_tcp( int port, int clients );
int	getline_tcp(int handle, char * buffer, int length );
int	read_tcp(int handle, char * buffer, int length );
int	write_tcp(int handle, char * buffer, int length );
int	service2port_tcp( char * name );
int	close_tcp( int handle );
int  	putline_tcp(int handle, char * buffer, int length );

	/* -------- */
#endif	/* _EXTCP_H */
	/* -------- */

