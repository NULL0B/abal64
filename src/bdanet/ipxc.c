#include <stdio.h>
#include "ipx.h"

#define	_DEBUG

#include "sf.c"
#include "ipx.c"

static	char * message="**( Hello IPX World )**";

static	char mbuffer[1024];
int	echo=0;
int	debug=0;

int	length( char * mptr )
{
	int	l;
	for (l=0; *(mptr+l) != 0; l++);
	return(l);
}

int	compare( char * aptr, char * bptr )
{
	while (( *aptr ) && ( *bptr ))
		if ( *(aptr++) != *(bptr++) )
			return(0);
	return(1);
}

int	verbose=0;
char *	hostname=(char*)0;
int	banner()
{
	printf("\n   IPX Test Client : Version 1.1a.0.01 ");
	printf("\n   Provisoire du 06/12/2000 ");
  	printf("\n   Copyright (c) 2000 Amenesik / Sologic \n ");
    	return(0);
}

int	doit( char * fptr )
{
	int	i;
	int	handle;
	int	status;
	long	sector=0L;
	long	received=0L;
	
 	if (!( hostname )) 
		return(error(30,"host name required: use -hname option"));
	else if ((handle = open_client_ipx( hostname )) == -1)
		return(error(40,hostname));
	else	{
		if ((i = read_ipx( handle, mbuffer, length(message)+1 )) > 0 ) {
			mbuffer[i] = 0;
	 		if ( compare( mbuffer, message ) ) {
				if ( verbose ) printf("\n%s\n",mbuffer );
				sprintf(mbuffer,"GET %s",fptr);
				if ( verbose ) printf("send : %s \n",mbuffer);
				if ((status = write_ipx(handle,mbuffer,length(mbuffer)+1)) != 0)
					error( status, "sending command");
				else	{
					if ( verbose ) printf("recv : \n");
 					while ((i= read_ipx(handle,mbuffer,256))  > 0 ) {
						mbuffer[i] = 0;
						if ( debug )
							printf("block %lu length %u total %lu \n",sector++,i,received);
						for (i=0; i < 256; i++ ) {
							if (!( mbuffer[i] ))
				 				break;
							else if ( mbuffer[i] == 0x001A )
								break;
							else if ( echo )
								printf("%c",(mbuffer[i]&0x00FF));
							}
						mbuffer[0] = 0;
	 		  			}
					}
				}
			else	error(999,"whoops wrong planet");
			}
		else	error(999,"whoops no life forms");
		return( close_client_ipx( handle ) );
		}      
}
 

int	error(int value,char * mptr)
{
	printf("\nerror: %u : %s \n",value,mptr);
 	return(value); 
}

int	ipx_option( char * aptr )
{
	switch ( *(aptr++) ) {
 		case	'e'	:
		case	'E'	: echo=1; return(0);
 		case	'd'	:
		case	'D'	: debug=1; return(0);
 		case	'v'	:
		case	'V'	: verbose=1; return(0);
		case	'h'	:
		case	'H'	: hostname = aptr;
				  return(0);
		default		: return( error(30,"incorrect option") );
		}
}
 
int	operation(int argc, char * argv[] ) 
{
	int	status;
	int	argi;
	char *	aptr;
	for (	argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			return( error(30,"null option") );
		else if ( *aptr == '-' ) {
			if ((status = ipx_option( (aptr+1) )) != 0)
				return(status); 
			else	continue;
			}
		else if ((status = doit( aptr )) != 0)
			return( error(status,"error whilst doing it") );
		}
       	return(0);
}
 
   
int	main(int argc, char * argv[] ) 
{

	if ( argc == 1 )
		return( banner() );
	else	return( operation( argc, argv ) );
}

