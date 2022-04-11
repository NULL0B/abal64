#include <stdio.h>
#include <iconv.h>

int	gencode='h';	/* h = html, p = prologue, w = windows, u = unicode */
int	verbose=0;
int	echo=0;
int	mode=0;
int	yes=0;

iconv_t	truc;

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
		if ( mode > 0 ) {
			if ( gencode != 'w' ) 
				v = is_macro( c );
			else	v = c;
			}
		else	v = c;

		switch ( gencode ) {
			case	'h'	:
				if (( v >= 160 )
				&&  ( v < (160 + _HTML_MACRO_MAX)))
					sprintf(buffer,"&%s;",macrotoken[(v-160)]);
				else	sprintf(buffer,"&#%u;",v);
				for ( v=0; buffer[v] != 0; v++ )
					fputc( ( buffer[v] & 0x00FF), target);
				break;
			default		:
				fputc( c, target );

			}
		}
	return(0);
}

char *	target_code( char * cptr )
{
	switch ( *(cptr++) ) {
		case	'u'	:
		case	'U'	:	/* to unicode */
			gencode = 'u';
			break;
		case	'p'	:
		case	'P'	:	/* to prologue*/
			gencode = 'p';
			break;
		case	'w'	:
		case	'W'	:	/* to windows */
			gencode = 'w';
			break;
		case	'h'	:
		case	'H'	:
		case	' '	:
		case	0	:
			gencode = 'h';
			break;
		}
	return( cptr );
}


int	option( char * cptr )
{
	while ( *cptr ) {
		switch ( *(cptr++ ) ) {
			case	'u'	:
			case	'U'	:	/* utf8 source 		*/
				mode = 2;
				cptr = target_code( cptr );
				continue;

			case	'w'	:
			case	'W'	:	/* 8859-1 source	*/
				mode = 0;
				cptr = target_code( cptr );
				continue;
			case	'p'	:
			case	'P'	:	/* prologue source	*/
				mode = 1;
				cptr = target_code( cptr );
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

int	utf8conv( int c, FILE * h, int nb )
{
	char	sbytes[8];
	const char *	iptr=sbytes;
	int	sn=nb;
	char	tbytes[8];
	char *	optr=tbytes;
	int	tn=8;
	int	i=0;
	sbytes[i++] = (c & 0x00FF); tbytes[0] = 0;
	while ( i < nb ) {
		sbytes[i++] = (fgetc(h) & 0x00FF);
		}
	iconv( truc, &iptr, &sn, &optr, &tn );
	return( (tbytes[0] & 0x00FF) );
}

int	fgetcharacter( FILE * h )
{
	int	c;
	switch ( mode ) {
		case	0	:	/* windows  */
		case	1	:	/* prologue */
			return( fgetc( h ) );
		case	2	:	/* utf8	    */
			if ((c = fgetc(h)) == -1)
				return( c );
			else if (!( c & 0x0080)) {
				/* mono byte */
				return( c & 0x007F );
				}
			else if (!( c  & 0x0020)) {
				return( utf8conv( c, h, 2 ) );
				}
			else if (!( c & 0x0010)) {
				return( utf8conv( c, h, 3 ) );
				}
			else	{
				return( utf8conv( c, h, 4 ) );
				}
		}
}

int	conversion( char * filename )
{
	int	status;
	int	c;
	FILE	* handle;
	FILE	* target;
	if ((handle = fopen( filename, "r" )) != (FILE *) 0) {
		if ((target = fopen( "tempfile.out", "w" )) != (FILE *) 0) {
			if ( verbose )
				printf("conversion of : %s \n",filename);

			if ( mode == 2 )
				truc = iconv_open("ISO-8859-1","UTF-8" );

			while ((c = fgetcharacter(handle)) != -1) 
				if ((status = doit((c & 0x00FF),target)) != 0)
					break;
			if ( mode == 2 )
				iconv_close(truc);
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
	printf("\n   Abal HTML File Convertor : Windows Accents to Html Macros : Version 2.1a.0.02 ");
	printf("\n   Provisoire du 04/09/2007 ");
	printf("\n   Copyright (c) 2000, 2007 Amenesik / Sologic \n");
	printf("\n   Options : ");
	printf("\n        -w : convert windows character set to html macros ");
	printf("\n        -p : convert abal    character set to html macros ");
	printf("\n        -u : convert unicode character set to html macros ");
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



