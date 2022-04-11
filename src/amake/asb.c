#include <stdio.h>

int	failure(char * aptr, int status)
{
	printf("\n** error : %u : %s **\n",status,aptr);
	asb_terminate();
	return(1);
}

static	int	integer(char *nptr)
{
	int	v=0;
	while (( *nptr >='0') && ( *nptr <= '9' ))
		v = ((v*10)+ (*(nptr++) -'0'));
	return(v);
}

static int	how(char *nptr)
{
	while (*nptr) {
		switch ( *(nptr++) ) {
			case	'g'	:
			case	'G'	:
				asb_option_g(0);
				return(0);

			case	'S'	:
			case	's'	:
				asb_option_s(1);
				return(0);
			case	'I'	:
			case	'i'	:
				asb_option_i( integer(nptr) );
				return(0);

			case	'M'	:
			case	'm'	:
				asb_option_m( integer(nptr) );
				return(0);

			case	'V'	:
			case	'v'	:
				asb_option_v( 1 );
				return(0);

			case	'E'	:
			case	'e'	:
				asb_option_e( 1 );
				return(0);

			default		:
				return(30);
			}
		}
	return(0);

}

static int	operation(int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	int	status;
	asb_initialise();
	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr != '-' ) {
			if (!(status = asb_operation(aptr)))
				continue;
			else	return( failure(aptr,status) );
			}
		else if (!(status = how((aptr+1)) ))
			continue;
		else	return( failure(aptr,status) );
		}
	return(0);
}
		
int	main(int argc, char * argv[] )
{
	if ( argc == 1 ) {
		printf("\n   Abal Source Beautifier : Version 3.2a.0.01 ");
		printf("\n   Provisoire du 07/07/2007 ");
		printf("\n   Copyright (c) 2007 Amenesik / Sologic \n");
		printf("\n   Usage : \n");
		printf("\n       ab    [ ");
		printf("\n             -m<size>       : margin size ");
		printf("\n             -i<size>       : indentation size ");
		printf("\n             -g             : inhibit result file ");
		printf("\n             -e             : echo input file ");
		printf("\n             -s             : remove all comments ");
		printf("\n             -v             : activate messages ");
		printf("\n             ] <filelist> \n");
		printf("\n   Example : \n");
		printf("\n       ab -i4 -v *.as\n\n");
		return(0);
		}
	else	return(operation(argc,argv));
}


