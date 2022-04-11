#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define	allocate	malloc
#define	liberate	free

char *	allocate_string( char * sptr )
{
	char *	rptr;
	if (!( sptr ))	return( sptr );
	if (!( rptr = allocate( strlen( sptr ) + 1 ) ))
		return( rptr );
	else	return( strcpy( rptr, sptr ) );
}

int	compare( char * aptr, char * bptr )
{
	while (( *aptr ) && (*bptr ))
		if ( *(aptr++) != *(bptr++) )	
			return(0);
	if ( *aptr != *bptr )	
		return(0);
	else	return(1);
}

#include "xmlparse.c"
#include "xsd.c"

int	banner()
{
	printf("\n   XML/XSD Parser : Version 1.0a.0.01 ");
	printf("\n   Provisoire du 04/11/2003 ");
	printf("\n   Copyright (c) 2003 Amenesik / Sologic \n\n");
	return(0);
}

	
int	main( int argc, char * argv[] )
{
	int	argi;
	int	status;
	char *	aptr;
	if ( argc == 1 )
		return( banner() );
	for ( 	argi=1;
		argi < argc;
		argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			if ( *(aptr+1) == 'e' )
				xml_echo_state = 1;
			}
		else if ((status = xml_parse( argv[argi], &xsdrelay )) != 0) {
			printf("\r\n*** %s: error xml:%u ***\r\n",argv[argi],status);
			}
		}
	xsd_show();
	return(0);

}

