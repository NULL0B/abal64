#include <stdio.h>

#define	_MODULE_DATE	"08/09/2001"
#define _MODULE_TITLE	"Directory Management Utility"
#define _MODULE_V_MAJOR	'1'
#define _MODULE_V_MINOR	'1'
#define _MODULE_INDICE	'a'
#define _MODULE_I_MAJOR	'0'
#define _MODULE_I_EXTRA '1'
#define _MODULE_I_MINOR	'1'
#define	_MODULE_V_STATE '2'

#define	_MODULE_USAGE	rep_syntax
void	rep_syntax()
{
	printf("\n   Syntax : \n\trep cr <directory>\n\trep sr <directory>\n\n");
	return;
}

#include "pvheader.c"

static	char	cmd_buffer[512];


void	mkdir(char * nptr)
{
	sprintf(cmd_buffer,"mkdir %s",nptr);
#ifndef	UNIX
	system( cmd_buffer );
#else
	printf("%s\n",cmd_buffer);
#endif
}

void	rmdir(char * nptr)
{
	sprintf(cmd_buffer,"rmdir %s",nptr);
#ifndef	UNIX
	system( cmd_buffer );
#else
	printf("%s\n",cmd_buffer);
#endif
}

int	compare(char * sptr, char * mptr )
{
	while (( *sptr != 0 ) && ( *mptr != 0 )) {
		if (( *sptr & 0x005F ) != *mptr )
			return(0);
		else	{
			sptr++;
			mptr++;
			}
		}
	if ( *sptr == *mptr )
		return(1);
	else	return(0);
}

int	operation( int argc, char * argv[] )
{
	int	argi;
	char *	cmdptr;
	char *	nomptr;

	if ( argc == 3 ) {
		if ( compare(argv[1],"CR") )
			mkdir( argv[2] );
		else if ( compare(argv[1],"SR") )
			rmdir( argv[2] );
		else	banner(argv[0]);
		} 
	else	banner(argv[0]);
	return(0);
}


