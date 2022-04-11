#ifndef	_ymain_c
#define	_ymain_c

int	option( char * aptr )
{
	switch ( *(aptr++) ) {
		case	'h'	:
		case	'H'	:
			homepath = aptr;
			return(0);
		case	'l'	:
		case	'L'	:
			listfile = aptr;
			return(0);
		case	'i'	:
		case	'I'	:
			including = aptr;
			return(0);
		case	'v'	:
		case	'V'	:
			verbose = 1;
			return(0);
		case	's'	:
		case	'S'	:
			substitution( aptr );
			return( 0 );
		case	'd'	:
		case	'D'	:
			sourcedir=aptr;
			return(0);
		case	'r'	:
		case	'R'	:
			redirection( aptr );
			return( 0 );
		case	'e'	:
		case	'E'	:
			echo = 1;
			return(0);
		default		:
			return( report_error( 30 ) );
		}
}


int	loader(int argc, char * argv[] )
{
	int	status;
	int	argi;
	char *	aptr;

	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr != '-') {
			if (!(status = loadfile( aptr ) ))
				continue;
			else	return( status );
			}
		else if (!( status = option( (aptr+1) )))
			continue;
		else	return( status );
		}
	return(conversion());
}

int	banner()
{
	printf("\n   Wabal Project File Convertor : version 1.0a.0.05");
	printf("\n   Provisoire du 03/12/2003 ");
	printf("\n   Copyright (c) 2003 Amenesik / Sologic \n");
	printf("\n   Usage   : ");
	printf("\n        yabal [ options ] file.jrp  ");
	printf("\n        yabal [ options ] file.jmp \n");
	printf("\n   Options :");
	printf("\n        -v           : activate messages ");
	printf("\n        -d<pathname> : default source path name ");
	printf("\n        -e           : echo source stream to stdio ");
	printf("\n        -h<pathname> : set root or home path ");
	printf("\n        -l<filename> : list structure report to filename ");
	printf("\n        -s<a=b>      : substitute b for a in  filenames ");
	printf("\n        -r<a=b>      : redirect filename a with path b");
	printf("\n        -i<filename> : include tool definitions from file\n");
	printf("\n   Example :");
	printf("\n        yabal -iabal3.def -sc:=/home example.jmp \n");
#ifdef	UNIX
	printf("\n");
#endif
	return(0);
}


int	main(int argc, char * argv[] )
{
	if ( argc==1) 
		return( banner() );
	else	return( loader(argc, argv ) );
}

#endif	// _ymain_c

