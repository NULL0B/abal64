#ifndef	_PV_HEADER_C
#define	_PV_HEADER_C

/*
 *	This file provides a standardised 'PV' compatible 'C' program
 *	startup procedure 'int main(argc,argv)' which displays a 
 *	standardised banner by calling the function 'int banner(argv[0])'
 *	 when called with no parameters.
 *
 *	The function "main()" will pass control to 'operation(argc,argv)'
 *	if command line parameters are detected. 
 *
 *	The following symbols must have been defined in the including
 *	source :
 *
 *		_MODULE_V_STATE
 *
 *		_MODULE_V_MAJOR
 *		_MODULE_V_MINOR
 *		_MODULE_INDICE
 *		_MODULE_I_MAJOR
 *		_MODULE_I_EXTRA
 *		_MODULE_I_MINOR
 *
 *		_MODULE_DATE and _MODULE_TITLE
 *
 *	If module usage information is to be displayed in the banner
 *	then the symbol _MODULE_USAGE must be defined as the name
 *	of the function to be called.
 *
 */

static  char	VersionStatus[16]= { 
	'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':',
	_MODULE_V_STATE
	};

static	char 	LaPaterne[32] = { 
	'*','P','R','L','@','I','N','F','O','*','#',6,
	_MODULE_V_MAJOR,
	_MODULE_V_MINOR,
	_MODULE_INDICE,
	_MODULE_I_MAJOR,
	_MODULE_I_EXTRA,
	_MODULE_I_MINOR,
	0
	};

static	char *	LaPointeur=(char*)0;
static	char 	LaVersion[16];

char *	getpatternversion()
{
	if (!( LaPointeur )) {
		LaVersion[0] = LaPaterne[12];
		LaVersion[1] = '.';
		LaVersion[2] = LaPaterne[13];
		LaVersion[3] = LaPaterne[14];
		if ( VersionStatus[15] != '0' ) {
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = '.';
			LaVersion[7] = LaPaterne[16];
			LaVersion[8] = LaPaterne[17];
			LaVersion[9] = 0;
			}
		else if ( LaPaterne[15] != '0' ) {
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = 0;
			}
		else	LaVersion[4] = 0;

		LaPointeur = LaVersion;
		}
	return( LaPointeur );

}

int	banner(char * cptr)
{
	printf("\n   %s : Version %s ",_MODULE_TITLE,getpatternversion());
	if ( VersionStatus[15] == '2' )
		printf("\n   Provisoire du %s ",_MODULE_DATE );
	printf("\n   Copyright (c) 1987,2006 Amenesik / Sologic \n");
#ifdef	_MODULE_USAGE
		_MODULE_USAGE (cptr);
#endif
	return(0);
}

int	operation(int,char * []);

int	main(int argc,char * argv[])
{
	if ( argc == 1 )
		return(banner(argv[0]));
	else	return(operation(argc,argv));
}

#endif	/* _PV_HEADER_C */


