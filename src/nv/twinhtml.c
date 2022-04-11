#include <stdio.h>

int	verbose=0;
int	echo=0;
int	mode=0;
int	yes=0;

#define	_MACROVALPRL
#include "macroval.h"

#define	_HTML_MACRO_MAX		96

char * macrotoken[ _HTML_MACRO_MAX ] = {
	(char *)	"nbsp",	
	(char *)	"iexcl",
	(char *)	"cent",
	(char *)	"pound",
	(char *)	"curren",
	(char *)	"yen",
	(char *)	"brvbar",
	(char *)	"sect",
	(char *)	"uml",
	(char *)	"copy",
	(char *)	"ordf",
	(char *)	"laquo",
	(char *)	"not",
	(char *)	"shy",
	(char *)	"reg",
	(char *)	"macr",
	(char *)	"deg",
	(char *)	"plusmn",
	(char *)	"sup2",
	(char *)	"sup3",
	(char *)	"acute",
	(char *)	"micro",
	(char *)	"para",
	(char *)	"middot",
	(char *)	"cedil",
	(char *)	"sup1",
	(char *)	"ordm",
	(char *)	"raquo",
	(char *)	"frac14",
	(char *)	"frac12",
	(char *)	"frac34",
	(char *)	"iquest",
	(char *)	"Agrave",
	(char *)	"Aacute",
	(char *)	"Acirc",
	(char *)	"Atilde",
	(char *)	"Auml",
	(char *)	"Aring",
	(char *)	"AElig",
	(char *)	"Ccedil",
	(char *)	"Egrave",
	(char *)	"Eacute",
	(char *)	"Ecirc",
	(char *)	"Euml",
	(char *)	"Igrave",
	(char *)	"Iacute",
	(char *)	"Icirc",
	(char *)	"Iuml",
	(char *)	"ETH",
	(char *)	"Ntilde",
	(char *)	"Ograve",
	(char *)	"Oacute",
	(char *)	"Ocirc",
	(char *)	"Otilde",
	(char *)	"Ouml",
	(char *)	"times",
	(char *)	"Oslash",
	(char *)	"Ugrave",
	(char *)	"Uacute",
	(char *)	"Ucirc",
	(char *)	"Uuml",
	(char *)	"Yacute",
	(char *)	"THORN",
	(char *)	"szlig",
	(char *)	"agrave",
	(char *)	"aacute",
	(char *)	"acirc",
	(char *)	"atilde",
	(char *)	"auml",
	(char *)	"aring",
	(char *)	"aelig",
	(char *)	"ccedil",
	(char *)	"egrave",
	(char *)	"eacute",
	(char *)	"ecirc",
	(char *)	"euml",
	(char *)	"igrave",
	(char *)	"iacute",
	(char *)	"icirc",
	(char *)	"iuml",
	(char *)	"eth",
	(char *)	"ntilde",
	(char *)	"ograve",
	(char *)	"oacute",
	(char *)	"ocirc",
	(char *)	"otilde",
	(char *)	"ouml",
	(char *)	"divide",
	(char *)	"oslash",
	(char *)	"ugrave",
	(char *)	"uacute",
	(char *)	"ucirc",
	(char *)	"uuml",
	(char *)	"yacute",
	(char *)	"thorn",
	(char *)	"yuml"

	};

int	is_macro( int c )
{
	int	i;
	c &= 0x00FF;
	if ( c <= 127 )
		return(c);
	else	{
		for ( i=128; i < 256; i++ )
			if (( macrovalue[i] & 0x00FF) == c )
				return(i);
		return(c);
		}
}

int	doit( int c, FILE * target )
{
	int	v;
	char	buffer[16];
	c &= 0x00FF;
	if ( c <= 127 )
		fputc( c, target );
	else	{
		// If source is CICO
		// -----------------
		if ( mode == 1 )
			v = is_macro( c );
		else	v = c;

		if (( v >= 160 )
		&&  ( v < (160 + _HTML_MACRO_MAX)))
			sprintf(buffer,"&%s;",macrotoken[(v-160)]);
		else	sprintf(buffer,"&#%u;",v);
		for ( v=0; buffer[v] != 0; v++ )
			fputc( ( buffer[v] & 0x00FF), target);
		}
	return(0);
}

int	option( char * cptr )
{
	while ( *cptr ) {
		switch ( *(cptr++ ) ) {
			case	'w'	:
			case	'W'	:
				mode = 0;
				continue;
			case	'p'	:
			case	'P'	:
				mode = 1;
				continue;
			case	'v'	:
			case	'V'	:
				verbose = 1; 
				continue;
			case	'e'	:
			case	'E'	:
				echo = 1; 
				continue;
			case	'y'	:
				yes = 1; 
				continue;
			default		:
				return(30);
			}
		}
	return(0);
}

int	conversion( char * filename )
{
	int	status;
	int	c;
	FILE	* handle;
	FILE	* target;
	if ((handle = fopen( filename, "r" )) != (FILE *) 0) {
		if ((target = fopen( "tempfile.out", "w" )) != (FILE *) 0) {

			while ((c = fgetc(handle)) != -1) 
				if ((status = doit((c & 0x00FF),target)) != 0)
					break;
			fputc(0x000D,target);
			fputc(0x000A,target);
			fputc(0x001A,target);
			fclose( target );
			fclose( handle );
			if ( yes ) {
				unlink( filename );
				rename( "tempfile.out", filename );
				}
			return(status);

			}
		else	{
			fclose( handle );
			return(41);
			}

		}
	else	return( 40 );

}


int	operation( int argc, char * argv[] )
{
	int	status;
	int	argi;
	char *	aptr;
	for ( 	argi=1; argi < argc; argi++ ) {
		if (( aptr = argv[argi] ) == (char *) 0)
			return(30);
		else if ( *aptr == '-' ) {
			if ((status = option( (aptr + 1) )) != 0)
				return(status );
			else	continue;
			}
		else if ((status = conversion( aptr )) != 0)
			return( status );
		else	continue;
		}
	return(0);
}

int	banner()
{
	printf("\n   HTML File Convertor : Windows Accents to Html Macros : Version 2.1a.0.01 ");
	printf("\n   Provisoire du 09/02/2007 ");
	printf("\n   Copyright (c) 2000, 2007 Amenesik / Sologic \n");
	printf("\n   Options : ");
	printf("\n        -w : convert windows characterset to html macros ");
	printf("\n        -p : convert abal    characterset to html macros ");
	printf("\n        -v : active verbose messages ");
	printf("\n        -e : activate source echo to standard output ");
	printf("\n        -y : save results to original filename \n\n");
	return(0);
}

int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return(banner());
	else	return(operation( argc, argv ) );
}


