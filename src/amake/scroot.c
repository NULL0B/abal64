#include <stdio.h>


int	doit(int argc, char * argv[] )
{
	int	argi;
	char *	aptr;

	return(0);
}

int	banner()
{
	printf("\n   scroot for pattern in file : version 1.0a.0.01\n");
	return(0);
}


int	main(int argc, char * argv[])
{
	if ( argc == 0 )
		return( banner());
	else	return( doit() );
}

