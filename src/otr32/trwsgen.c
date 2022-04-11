#ifndef	_trwsgen_c
#define	_trwsgen_c

#include <stdio.h>


static	int	wsgen(char * nptr)
{
	printf("wsgen : %s\n",nptr);
	return(0);
}

static	int	option( char * optr )
{
	return(30);
}


static	int	operation(int argc, char * argv[] )
{
	char *	aptr;
	int	argi;
	int	status=0;
	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			if (!(status = option((aptr+1)) ))
				continue;
			else	break;
			}
		else if (!(status = wsgen( aptr ) ))
			continue;
		else	break;
		}
	return(status);			
}

static	int	banner()
{
	printf("\n   Web Service Overlay Translator : Version 1.1a.0.01");
	printf("\n   Provisoire du 21/03/2006");
	printf("\n   Copyright (c) 2006 Amenesik / Sologic  \n\n");
	return(0);
}

int	main(int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( operation(argc,argv) );
}



#endif	/* _trwsgen_c */
	/* ---------- */

