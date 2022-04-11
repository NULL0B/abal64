#include <stdio.h>

#define	_MODULE_DATE	"08/09/2001"
#define _MODULE_TITLE	"File Delete Utility"
#define _MODULE_V_MAJOR	'1'
#define _MODULE_V_MINOR	'1'
#define _MODULE_INDICE	'a'
#define _MODULE_I_MAJOR	'0'
#define _MODULE_I_EXTRA '1'
#define _MODULE_I_MINOR	'1'
#define	_MODULE_V_STATE '2'

#define	_MODULE_USAGE	del_syntax
void	del_syntax()
{
	printf("\n   Syntax : \n\tdel [ -s -r -f ] <files> ");
	printf("\n   Options: ");
	printf("\n\t-s\tinhibit messages ");
	printf("\n\t-r\trecursive delete ");
	printf("\n\t-f\tno confirmation  \n");
	return;
}

#include "pvheader.c"

static	int	doit=0;
static	int	recursive=0;
static	int	verbose=1;
static	char	cmd_buffer[512];

int	set_option(char * aptr)
{
	while ( *aptr ) {
		switch ( *(aptr++) ) {
			case	'f'	:
			case	'F'	:
				doit=1;
				continue;
			case	'r'	:
			case	'R'	:
				recursive=1;
				continue;
			case	's'	:
			case	'S'	:
				verbose=0;
				continue;
			}
		}
	return(1);
}

int	validation()
{
	if (doit)
		return(1);
	else	return(0);
}

void	rm( char *sptr )
{
	if ( verbose )
		printf("delete files %s \n",sptr);

	if  (!( validation() ))
		return;

	sprintf(cmd_buffer,"rm %s",sptr);
#ifdef	UNIX
	system( cmd_buffer );
#else
	printf("%s\n",cmd_buffer);
#endif
	return;

}

int	operation( int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	for (argi=1; argi < argc; argi++) {

		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			if (!( set_option((aptr+1)) ))
				break;
			else	continue;
			}
		}

	for (argi=1; argi < argc; argi++) {

		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr != '-' )
			rm( argv[argi] );
		}

	return(0);
}




