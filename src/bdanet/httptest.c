#include "basic.h"
#include "address.h"


PUBLIC	int	main( argc, argv )
	int	argc;
	BPTR	argv[];
{
	if ( argc > 1 )
		if ( HttpInitialise(argv[1],strlen(argv[1])) == 0 ) {
			if ( HttpOpenServer(80,1) == 0 ) {
				if ( HttpAccept(0,10) != 0 )
					printf("Accepted Message\n");
				else	printf("HttpAccept * * Failure \n");
				HttpClose(0);
				}
			else	printf("HttpOpenServer * * Failure \n");
			(void) HttpLiberate();
			}
		else	printf("HttpInitialise * * Failure \n");
	return(0);
}





