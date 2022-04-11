#ifndef	_PPPC_C
#define	_PPPC_C

#define	____FAR_DATA

#include "http.h"
#include "ppp.h"
#include "lcp.h"

PRIVATE	VOID	banner()
{
	printf("   Point to Point Protocol Client Version %s \n",__HTTP_VERSION);
	printf("   Provisoire du %s \n",__HTTP_DATE);
	printf("   Copyright (C) 1997 Amenesik / Sologic \n");
	return;
}

PRIVATE	VOID	usage( mptr )
	BPTR	mptr;
{
	return;
}

PRIVATE	INT 	operation( cptr )
	BPTR	cptr;
{
	return(0);	/* OK : Success */
}

PRIVATE	INT 	initialisation()
{
	return(1);	/* OK : Success */
}

PRIVATE	VOID	liberation()
{
	return;		/* OK : Success */
}


PRIVATE	INT	analyse_option( aptr )
	BPTR	aptr;
{
	INT	status=0;
	switch ( *(aptr++) ) {
		case	'a' :
		case	'b' :
		default	    : 	status = 30;
		}
	return(status);
}

PUBLIC	INT	main( argc, argv )
	INT	argc;
	BPTR	argv[];
{
	INT	status=0;
	INT	argi=1;
	BPTR	aptr;

	if ( argc == argi ) {
		banner();
		usage(argv[0]);
		}
	else if ( initialisation() ) {
		while ( argi < argc ) {
			aptr = argv[argi++];
			if ( *aptr == '-' ) {
				aptr++;
				if ( analyse_option( aptr ) == 0 )
					continue;
				else	{
					banner();
					printf("\n * * Syntax Error * *\n");
					usage(argv[0]);
					break;
					}
				}
			else	{
				status = operation( aptr );
				break;
				}
			}
		liberation();
		}					
	return(status);
}



#endif	/* _PPPC_C */
	/* ------- */

