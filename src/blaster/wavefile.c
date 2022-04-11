int	verbose=0;

#include "wave.c"


int	showfile( char * nptr )
{
	struct	wave_handle * wptr;

	if ( verbose )
		printf("%s:\n",nptr);

	if (!( wptr = open_wave_file( nptr ) ))
		return( 40 );
	else	{
		show_wave_header( wptr );
		close_wave_file( wptr );
		return( 0 );
		}
}


int	doit( int argc, char * argv[] )
{
	int	argi;
	char *	aptr;

	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr != '-' ) {
			if (showfile( aptr ) != 0)
				break;
			else	continue;
			}
		else if ( *(aptr+1) == 'v' ) {
			verbose=1;
			continue;
			}
		}
	return(0);
}

int	banner()
{
	printf("\n   Wive File Header Display : Version 1.0a.0.01 ");
	printf("\n   Provisoire du 28/09/2004 ");
	printf("\n   Copyright (c) Iain James Marshall \n\n ");
	return(0);
}

int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( doit( argc, argv ) );
}















