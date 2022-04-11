
#include <stdio.h>
#include "ipx.h"

#define	_DEBUG

int	verbose=0;
int	debug=0;

#include "sf.c"
#include "ipx.c"

static	char * message="**( Hello IPX World )**";
static	char * cmderror="**( IPX syntax error )**";
static	char * filerror="**( file not found  )**";

static	char mbuffer[256];

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


int	kbhit()
{
	int	result=0;
	_asm	{
		mov	ah,012H
		int	110
		sahf
		jz	nowt
		mov	result,1
nowt:		
		}
	return( result );
  
}

int	getch()
{
	char	result=0;
	_asm	{
		mov	ah,010H
		int	110		
		mov	result,al
		}
	return(( result  & 0x00FF));
}


int	banner()
{
	printf("\n   IPX Test Server : Version 1.1a.0.01 ");
	printf("\n   Provisoire du 06/12/2000 ");
	printf("\n   Copyright (c) 2000 Amenesik / Sologic \n ");
    	return(0);
}
   
int	doit()
{
	long	sector=0L;
	int	handle;
	int	status;
	FILE *	fhandle;
	int	i;
	char *	mptr;

	if ((handle = open_server_ipx()) == -1)
		return(error(44,"starting server"));
	else	{
		while (1) {    
			if (( kbhit() )
			&&  ( getch() == 27 ))
				break;
			else if ((status = accept_client_ipx( handle )) != 0)
				error(status,"accepting client");
			else if ((status = write_ipx( handle, message, length(message)+1 )) != 0)
				error(status,"sending message");
			else if ((i = read_ipx( handle, mbuffer, 256 )) > 0 ) {
				mptr = mbuffer;
				mbuffer[i] = 0;
				if (( mbuffer[0] = 'G' )
 				&&  ( mbuffer[1] = 'E' )
				&&  ( mbuffer[2] = 'T' )
				&&  ( mbuffer[3] = ' ' )) {
					if ( verbose )
						printf("recv: GET %s\n",(mptr + 4));
 						if (!( fhandle = fopen( (mptr+4), "rb") )) {
						error(40,"cannot get");
						status = write_ipx( handle, filerror, length(filerror)+1 );
						}
					else	{
						if ( verbose )
 							printf("send:  %s\n",(mptr + 4));
 						while ( fread( mbuffer, 256, 1, fhandle ) == 1 ) {
	 						if ( debug )
								printf("sector %lu\n",sector++);
							write_ipx( handle, mbuffer, 256 );
							}
						fclose( fhandle );
						}
					  }
  				else	{
					error(55,"incorrect remote command");
					write_ipx( handle, cmderror,length(cmderror)+1); 
					}
				}
   			if ((status = release_client_ipx( handle )) != 0)
				error(status,"releasing client");
			}
		return( close_server_ipx( handle ) );
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
 		case	'd'	:
		case	'D'	: debug=1; return(0);
 		case	'v'	:
		case	'V'	: verbose=1; return(0);
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
		else	return( error(30,"unknown option") );
		}
       	return(doit());
}
 
   
int	main(int argc, char * argv[] ) 
{

	if ( argc == 1 )
		return( banner() );
	else	return( operation( argc, argv ) );
}
  
