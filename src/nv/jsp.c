#include <stdio.h>

int	debug=0;
int	echo=0;
int	verbose=0;
int	dom=1;

int	include(char *);

#include "jsptype.h"
#include "jspnat.h"

#include "jspmem.c"

#include "jspin.c"
#include "jspnum.c"
#include "jspstr.c"
#include "jspval.c"
#include "jspvar.c"
#include "jspfunc.c"
#include "jspeval.c"
#include "jsplang.c"


int	parse_js( FILE * h )
{
	int	status;
	struct function * fptr;
	fh = h;

	if (!(fptr = new_function( "_javascript_main" ) ))
		return( 27 );
	else	add_function( fptr );

	while( remove_white_space() ) {
		if ( get_token() ) {
			if ((status = translate_token( token_buffer )) != 0 ) {
				jserror(status);
				break;
				}
			}
		else 	{
			switch ( not_white() ) {
				case	';'	:
				case	'{'	:
				case	'}'	:
					continue;
				default		:
					break;
				}
			break;
			}
		}

	fclose( fh );
	fh = (FILE *) 0;
	return(status);
}



int	include( char * aptr )
{
	FILE	*	handle;
	if ((handle = fopen( aptr, "rb" )) != (FILE *) 0)
		return( parse_js( handle ) );
	else	return( 40 );
}

int	is_option( char * aptr )
{
	if ( *(aptr++) != '-' )
		return(0);
	else if ( *aptr == 'e' )
		echo++;
	else if ( *aptr == 'v' )
		verbose++;
	else if ( *aptr == 'd' )
		debug++;
	else if ( *aptr == 'm' )
		dom=0;
	return(1);
}
		
int	operation( int argc, char * argv[] )
{
	int	argi;
	int	status=0;
	char *	aptr;

	for (argi=1; argi < argc; argi++ ) {
		if (!(aptr = argv[argi]))
			break;
		else if (!( is_option( aptr ) )) {

			if ( dom )
				(void) include( "dom.js" );

			if ((status = include( aptr )) != 0)
				printf("\nerror : %u \n",status);

			release_variables();
			release_functions();
			release_operands();
			}
	}
	return(0);
}

int	banner()
{
	printf("\n   Java Script Engine Tester : Version 1.0a ");
	printf("\n   Provisoire du 11/12/2000 ");
	printf("\n   Copyright (c) Amenesik / Sologic \n");
	return(0);
}

int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return(banner());
	else	return(operation(argc,argv));
}


