#ifndef	_ipx_h
#define	_ipx_h

#define	IPX_TRANSPORT 7


#include "sf.h"

/*	IPX / SF Function codes 	*/
/*	-----------------------		*/

#define	_IPX_CONNECT		(_SF_ | 0x00B0)
#define	_IPX_DISCONNECT		(_SF_ | 0x00B8)

#define	_IPX_ACCEPT		(_SF_ | 0x0070)
#define	_IPX_ACK		(_SF_ | 0x00B4)

/*	IPX Specific Error Codes	*/
/*	------------------------	*/
#define	_IPX_DISCONNECTED	80
#define	_IPX_TIMEOUT		91


/*	IPX Public Interface Functions	*/
/*	------------------------------	*/

/*	For servers	*/
/*	-----------	*/
int	open_server_ipx();		/* void			*/
int	accept_client_ipx( int );	/* handle 		*/
int	release_client_ipx( int );	/* handle 		*/
int	close_server_ipx( int );	/* handle		*/

/*	For clients	*/
/*	-----------	*/
int	open_client_ipx( char * );	/* server name		*/
int	close_client_ipx( int );	/* handle		*/


/*	For both	*/
/*	-----------	*/
int	read_ipx(int, char *, int );	/* handle,buffer,length */
int	write_ipx(int, char *, int );	/* handle,buffer,length */


#endif	/* _ipx_h */



