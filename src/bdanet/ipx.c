#ifndef	_sf_ipx_c
#define	_sf_ipx_c

#include "ipx.h"

static	char	cnxbuffer[256];
static	char	readbuffer[1504];
static	int	readindent=4;
static	int	byteswaiting=0;
static	int	ungotipx=-1;
static	int	selecting=0;

#ifdef	_DEBUG
extern	int	verbose;
extern	int	debug;
#endif
/*	Client Functions	*/
/*	----------------	*/
int	close_client_ipx(	int handle )
{
	if ( handle != -1 ) {
#ifdef	_DEBUG
		if ( verbose )
			printf("close_client_ipx(%u)\n",handle);
#endif
		(void)  write_sf( handle, _IPX_DISCONNECT, cnxbuffer, 1, 1L );
		close_sf( handle );
		}
	return(0);
}

int	open_client_ipx( char * server )
{
	int	handle;
	int	i;
	int	status=0;
#ifdef	_DEBUG
	if ( verbose )
		printf("open_client_ipx(%s)\n",server);
#endif
	if ((handle = open_sf( "TP0.NIPX_USE", _SF_OPEN_EXCLUSIVE )) != -1) {
		for (i=0; i < 256; i++ ) 
			if (!( cnxbuffer[(i+2)] = *(server+i) ))
				break;
		cnxbuffer[0] = (i >> 8);
		cnxbuffer[1] = (i & 0x00FF);
		i += 2;
		switch ((status = write_sf( handle, _IPX_CONNECT, cnxbuffer, i, 1L ) )) {
			case	_IPX_TIMEOUT		:
			case	0			:
				break;
			case	_IPX_DISCONNECTED	:
			case	_MEMORY_ERROR   	:
			case	_SF_NOT_FOUND		:
			case	_SF_LOCKED		:
			case	_SF_INCORRECT		:
			default				:
				return( close_client_ipx(handle) );

			}
		}
	return( handle );
}

/*	Server Functions	*/
/*	----------------	*/
int	close_server_ipx( int handle )
{
	if ( handle != -1 ) {
#ifdef	_DEBUG
		if ( verbose )
			printf("close_server_ipx(%u)\n",handle);
#endif
 		close_sf( handle );
		}
	return(0);
}

int	open_server_ipx()
{
#ifdef	_DEBUG
	if ( verbose )
		printf("open_server_ipx()\n");
#endif
	return( open_sf( "TP0.NIPX_USE", _SF_OPEN_EXCLUSIVE ) );
}

int	release_client_ipx( int handle )
{
	if ( handle != -1 ) {
#ifdef	_DEBUG
		if ( verbose )
			printf("release_client_ipx(%u)\n",handle);
#endif
 		(void) write_sf( handle, _IPX_DISCONNECT, cnxbuffer, 1, 1L );
		}
	return(-1);
}

int	accept_client_ipx( int handle )
{
	int	status=0;

#ifdef	_DEBUG
	if ( verbose )
		printf("accept_client_ipx(%u)\n",handle);
#endif
	while (1) {
		switch ((status = read_sf(handle, _IPX_ACCEPT, cnxbuffer, 256, 10L ))) {
			case	0		:
				return( write_sf( handle, _IPX_ACK, cnxbuffer, 0, 1L ) );

			case	_IPX_TIMEOUT	:
#ifdef	_DEBUG
				if (!( kbhit() ))
					continue;
				else if ( getch() == 27 )
					return(48);
#endif
				continue;
			default			:
				return(status);
			}
		}
  }
 



int	read_ipx( int handle, char * buffer, int length )
{
	int	transfer=0;
	int	status=0;
	int	transfered=0; 
	while ( transfered < length ) {
#ifdef	_DEBUG
		if ( debug )
			printf("readipx(h=%u,l=%u) : t=%u, w=%u, i=%u \n",handle,length,transfered,byteswaiting,readindent);
#endif
		if ( ungotipx != -1 ) {
			*(buffer + transfered) = (ungotipx & 0x00FF);
			ungotipx = -1;
			transfered += 1;
			continue;
			}

 		else if (!( byteswaiting )) {
			readindent = 4;
			if ((status = read_sf(handle,_SF_READ, readbuffer, 1504, 10L )) != 0) {
				if (( status == _IPX_TIMEOUT )
				&&  (!( transfered ))) {
					if (!( selecting ))
						continue;
					else	break;
					}
				else	break;
				}

			else	{
				if (!(byteswaiting = ((readbuffer[3] & 0x00FF) + ((readbuffer[2] << 8) & 0xFF00)))) {
					if ( transfered )
						break;
					else	continue;
					}
   				} 
			}
		else 	{
			if ( (length - transfered) <= byteswaiting )
 				transfer = (length - transfered);
  			else	transfer = byteswaiting;
			if ( transfer)
				memcpy((buffer+transfered),&readbuffer[readindent],transfer);
			transfered   += transfer;
			byteswaiting -= transfer;
			readindent   += transfer;
			}
		}
	return( transfered );
}
	
int	select_connection_ipx( int handle, int delay )
{
	char	c;
	int	status=0;
#ifdef	_DEBUG
	if ( debug )
		printf("select_ipx(%u,%u)\n",handle,delay);
#endif
	selecting = 1;
	status = read_ipx( handle, & c, 1 );
	selecting = 0;
	if (!( status ))
		return(0);
	else	{
		ungotipx = (c & 0x00FF);
		return(1);
		}
}


int	write_ipx( int handle, char * buffer, int length )
{
	return(write_sf(handle, _SF_WRITE, buffer, length, 0L ) );
}
	


#endif	/* _sf_ipx_c */



