/*
 *	Copyright (C) 1999 AT&T Laboratories Cambridge.	All Rights Reserved.
 *
 *	This is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	This software is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this software; if not, write to the Free Software
 *	Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA	02111-1307,
 *	USA.
 */

/*
 * sockets.c - functions to deal with sockets.
 */

#ifndef	_rfbsock_c
#define	_rfbsock_c

#ifdef	UNIX
#include <unistd.h>
#include <sys\socket.h>
#include <errno.h>
#include <netinet\in.h>
#include <netinet\tcp.h>
#include <arpa\inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <assert.h>
#include <vncview.h>
#else
#include <errno.h>
#include ".\include\sys\types.h"
#include ".\include\netdb.h"
#include ".\include\sys\socket.h"
#include ".\include\netinet\in.h"
unsigned long inet_addr( char * );
#include "vncview.h"
#include "boolean.h"
#define	EWOULDBLOCK 2047
#include "rfberror.h"
#endif

#include "ipx.h"

extern	int	VncTransport;

Bool errorMessageOnReadFailure = True;

#ifdef	_DEBUG
void PrintInHex(char *buf, int len);
#endif

#define BUF_SIZE 8192

static char buf[BUF_SIZE];
static char *bufoutptr = buf;
static int buffered = 0;

static	unsigned long TotalTransfered=0L;

static	int	connection_counter=0;

/*
 * ReadFromRFBServer is called whenever we want to read some data from the RFB
 * server.	It is non-trivial for two reasons:
 *
 * 1. For efficiency it performs some intelligent buffering, avoiding invoking
 *	the read() system call too often.	For small chunks of data, it simply
 *	copies the data out of an internal buffer.	For large amounts of data it
 *	reads directly into the buffer provided by the caller.
 *
 * 2. Whenever read() would block, it invokes the Xt event dispatching
 *	mechanism to process X events.	In fact, this is the only place these
 *	events are processed, as there is no XtAppMainLoop in the program.
 */

static	void	server_closed_error()
{
	printf("%s: VNC server closed connection\n",programName);
	return;
}


void	error_message(char * mptr)
{
	printf("error:%u:%s:%s\n",errno,programName,mptr);
	return;
}


#ifdef	UNIX

static Bool rfbsockReady = False;

static void rfbsockReadyCallback(XtPointer clientData, int *fd, XtInputId *id)
{
	rfbsockReady = True;
	XtRemoveInput(*id);
}

static void ProcessXtEvents()
{
	rfbsockReady = False;

	XtAppAddInput(
		appContext, 
		rfbsock, 
		(XtPointer)XtInputReadMask,
		rfbsockReadyCallback, 
		NULL);

	while (!rfbsockReady) {
		XtAppProcessEvent(appContext, XtIMAll);
		}
}

#else	

extern	int 	rfbsock;
extern	void 	ProcessXtEvents();

#endif

int	socketread(int sock, char * bptr, int blen )
{
	int	i;
	int	n;
	if ( debug )
		printf("socketread(%u,%u) { ",sock,blen);
#ifdef	UNIX
	i = read(sock,bptr,blen);
#else
#ifdef	_ipx_h
	if ( VncTransport == IPX_TRANSPORT )
		i = read_ipx(sock,bptr,blen);
	else
#endif
		i = sread(sock,bptr,blen);
#endif
	if (( i > 0 )
	&&  ( debug ))	
		for (n=0; n < i; n++)
			printf("%02.1X ",*(bptr +n));
	if ( debug )
		printf(" } \n");

	return(i);		
}

int	socketwrite(int sock, char * bptr, int blen )
{
	int	i;
	int	n;
	if ( debug )
		printf("socketwrite(%u,%u) { ",sock,blen);
#ifdef	UNIX
	i = write(sock,bptr,blen);
#else
#ifdef	_ipx_h
	if ( VncTransport == IPX_TRANSPORT ) {
		if ((i = write_ipx(sock,bptr,blen)) != 0)
			return(0);
		else	i = blen;
		}
	else
#endif
		i = swrite(sock,bptr,blen);
#endif
	if (( i > 0 )
	&&  ( debug ))	
		for (n=0; n < i; n++)
			printf("%02.1X ",*(bptr +n));
	if ( debug )
		printf(" } \n");
	return(i);		
}

Bool	ReadFromRFBServer(char *out, unsigned int n)
{
	int	i;
	if (n <= buffered) {
		memcpy(out, bufoutptr, n);
		bufoutptr += n;
		buffered -= n;
		return True;
		}

	memcpy(out, bufoutptr, buffered);

	out += buffered;
	n -= buffered;

	bufoutptr = buf;
	buffered = 0;

	if (n <= BUF_SIZE) {

		while (buffered < n) {

			i = socketread(rfbsock, buf + buffered, BUF_SIZE - buffered);

			if (i <= 0) {
				if (i < 0) {
					if (errno == EWOULDBLOCK || errno == EAGAIN) {
						ProcessXtEvents();
						i = 0;
						} 
					else 	{
						read_error();
						return False;
						}
					} 
				else 	{
					if (errorMessageOnReadFailure) {
						server_closed_error();
						}
					return False;
					}
				}
			buffered += i;
			}

		memcpy(out, bufoutptr, n);
		bufoutptr += n;
		buffered -= n;
		return True;

		} 

	else 	{

		while (n > 0) {
			i = socketread(rfbsock, out, n);
			if (i <= 0) {
				if (i < 0) {
					if (errno == EWOULDBLOCK || errno == EAGAIN) {
						ProcessXtEvents();
						i = 0;
						} 
					else 	{
						read_error();
						return False;
						}
					} 
				else 	{
					if (errorMessageOnReadFailure) {
						server_closed_error();
						}
					return False;
					}
				}
			out += i;
			n -= i;
			}
		return True;
		}
}

Bool	ReadFromRFBClient(int newsock, char *out, unsigned int n)
{
	int	status=0;
	int	holdsock=rfbsock;
	int	holdflag = errorMessageOnReadFailure;
	errorMessageOnReadFailure=0;
	rfbsock = newsock;
	status = ReadFromRFBServer( out, n );
	rfbsock = holdsock;
	errorMessageOnReadFailure=holdflag;
	return( status );
}


/*
 * Write an exact number of bytes, and don't return until you've sent them.
 */

Bool	WriteExact(int sock, char *buf, int n)
{
	fd_set fds;
	int i = 0;
	int j;

	while (i < n) {
		j = socketwrite(sock, buf + i, (n - i));
		if (j <= 0) {
			if (j < 0) {
				if (errno == EWOULDBLOCK || errno == EAGAIN) {
					FD_ZERO(&fds);
					FD_SET(rfbsock,&fds);
					if (select(rfbsock+1, NULL, &fds, NULL, NULL) <= 0) {
						select_error();
						return False;
						}
					j = 0;
					} 
				else 	{
					write_error();
					return False;
					}
				} 
			else 	{
				write_error();
				return False;
				}
			}
		i += j;
		}

	TotalTransfered += n;
	return True;
}

#ifdef	_ipx_h
int	ConnectToIpxHost(char * host)
{
	if (VncTransport == IPX_TRANSPORT)
		return( open_client_ipx( host ) );
	else	return(-1);
}

int	StartIpxServer()
{
	if (VncTransport == IPX_TRANSPORT)
		return( open_server_ipx() );
	else	return(-1);
}
#endif

/*
 * ConnectToTcpAddr connects to the given TCP port.
 */

#ifdef	UNIX
int	ConnectToTcpAddr(unsigned int host, int port)
#else
int	ConnectToTcpAddr(unsigned long host, int port)
#endif
{
	int sock;
	struct sockaddr_in addr;
	int one = 1;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = host;

	if ( debug )
		printf("client socket()\n");

	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock < 0) {
		socket_error();
		return -1;
		}

	if ( debug )
		printf("connect(%u,%lu:%u)\n",sock,host,port);

	if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		connect_error();
#ifdef	UNIX
		close(sock);
#else
		sclose(sock);
#endif
		return -1;
		}

#ifdef	TCP_NODELAY
	if ( debug )
		printf("setsockopt(%u,NODELAY)\n",sock);
	if (setsockopt(sock, IPPROTO_TCP, TCP_NODELAY,
		 (char *)&one, sizeof(one)) < 0) {
		option_error();
#ifdef	UNIX
		close(sock);
#else
		sclose(sock);
#endif
		return -1;
		}
#endif

	if ( debug )
		printf("client socket OK = %u\n",sock);
	return sock;

}



/*
 * ListenAtTcpPort starts listening at the given TCP port.
 */

int	ListenAtTcpPort(int port)
{
	int sock;
	struct sockaddr_in addr;
	int one = 1;

#ifdef	_ipx_h
	if (VncTransport == IPX_TRANSPORT)
		return( StartIpxServer() );
#endif

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;

	if ( debug )
		printf("server socket()\n");

	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock < 0) {
		socket_error();
		return -1;
		}

	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR,
		 (const char *)&one, sizeof(one)) < 0) {
		option_error();
#ifdef	UNIX
		close(sock);
#else
		sclose(sock);
#endif
		return -1;
		}

	if ( debug )
		printf("bind(%u,%u)\n",sock,port);
	if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		bind_error();
#ifdef	UNIX
		close(sock);
#else
		sclose(sock);
#endif
		return -1;
		}

	if ( debug )
		printf("listen(%u)\n",sock);
	if (listen(sock, 5) < 0) {
		listen_error();
#ifdef	UNIX
		close(sock);
#else
		sclose(sock);
#endif
		return -1;
		}

	if ( debug )
		printf("server socket OK = %u\n",sock);
	return sock;
}


/*
 * AcceptTcpConnection accepts a TCP connection.
 */

int	AcceptTcpConnection(int listenSock)
{
	int sock;
	struct sockaddr_in addr;
	int addrlen = sizeof(addr);
	int one = 1;

	if ( verbose )
		printf("awaiting client connection\n");

	if ( debug )
		printf("accept(%u)\n",listenSock);

#ifdef	_ipx_h
	if (VncTransport == IPX_TRANSPORT) {

		if (!( accept_client_ipx( listenSock ) ))
			sock = listenSock;

		else	{
			accept_error();
			return -1;
			}
		}
	else	{
#endif

		if ((sock = accept(listenSock, (struct sockaddr *) &addr, &addrlen)) < 0 ) {
			accept_error();
			return -1;
			}

#ifdef	TCP_NODELAY
		if (setsockopt(sock, IPPROTO_TCP, TCP_NODELAY,
			 (char *)&one, sizeof(one)) < 0) {
			option_error();
#ifdef	UNIX
			close(sock);
#else
			sclose(sock);
#endif
			return -1;
			}
#endif
#ifdef	_ipx_h
		}
#endif
	connection_counter++;
	if ( verbose )
		printf("client connection #%u : %u \n",connection_counter,sock);

	return sock;
}


/*
 * ReleaseTcpConnection release an accepted client TCP connection.
 */

int	ReleaseTcpConnection(int sock)
{
	if ( debug )
		printf("close socket %u \n",sock);

#ifdef	_ipx_h
	if (VncTransport == IPX_TRANSPORT)
		sock = release_client_ipx( sock );

	else	
#endif

	if ( sock > 0 ) {
#ifdef	UNIX
		close(sock);
#else
		sclose(sock);
#endif
		}

	if ( verbose ) {
		printf("\nTotal Transfered : %lu \n",TotalTransfered);
		MfShowEvents();
		}
	MfFlushEvents();
	TotalTransfered = 0L;
	return(0);
}

/*
 * SetNonBlocking sets a socket into non-blocking mode.
 */

Bool	SetNonBlocking(int sock)
{
#ifdef	F_SETFL
	if (fcntl(sock, F_SETFL, O_NONBLOCK) < 0) {
		fcntl_error();
		return False;
		}
#endif
	return True;
}


/*
 * StringToIPAddr - convert a host string to an IP address.
 */

#ifdef	UNIX
Bool	StringToIPAddr(const char *str, unsigned int *addr)
#else
Bool	StringToIPAddr(const char *str, unsigned long *addr)
#endif
{
	struct hostent *hp;

	if ( debug )
		printf("String (%s) to IP Address \n",str);

	if (strcmp(str,"") == 0) {
		*addr = 0; /* local */
		return True;
		}

	*addr = inet_addr(str);

	if (*addr != -1)
		return True;

	hp = gethostbyname(str);

	if (hp) {
#ifdef	UNIX
		*addr = *(unsigned int *)hp->h_addr;
#else
		*addr = *(unsigned int *)hp->h_addr;
#endif
		return True;
		}

	if ( debug )
		printf("IP OK = %lu\n",*addr);
	return False;
}


/*
 * Test if the other end of a socket is on the same machine.
 */

Bool	SameMachine(int sock)
{
	struct sockaddr_in peeraddr, myaddr;
	int addrlen = sizeof(struct sockaddr_in);

	getpeername(sock, (struct sockaddr *)&peeraddr, &addrlen);
	getsockname(sock, (struct sockaddr *)&myaddr, &addrlen);

	return (peeraddr.sin_addr.s_addr == myaddr.sin_addr.s_addr);
}


#ifdef	_DEBUG

/*
 * Print out the contents of a packet for debugging.
 */


void	PrintInHex(char *buf, int len)
{
	int i, j;
	char c, str[17];

	str[16] = 0;

	fprintf(stderr,"ReadExact: ");

	for (i = 0; i < len; i++) {
		if ((i % 16 == 0) && (i != 0)) {
			fprintf(stderr,"					 ");
			}
		c = buf[i];
		str[i % 16] = (((c > 31) && (c < 127)) ? c : '.');
		fprintf(stderr,"%02x ",(unsigned char)c);
		if ((i % 4) == 3)
			fprintf(stderr," ");
		if ((i % 16) == 15) {
			fprintf(stderr,"%s\n",str);
			}
		}
	if ((i % 16) != 0) {
		for (j = i % 16; j < 16; j++) {
			fprintf(stderr,"	 ");
			if ((j % 4) == 3) 
				fprintf(stderr," ");
			}
		str[i % 16] = 0;
		fprintf(stderr,"%s\n",str);
		}

	fflush(stderr);
}

#endif

#endif	/* _rfbsock_c */

