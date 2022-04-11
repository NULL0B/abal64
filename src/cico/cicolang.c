#ifndef	_cicolang_c
#define	_cicolang_c

#include <stdio.h>

static int	current_message_language=-1;

int	cico_message_language()
{
	char *	eptr;
	char *	getenv(char *);
	int	atoi(char *);
	if ( current_message_language != -1 )
		return( current_message_language );
	else if (!( eptr = getenv("CICOLANG") ))
		return( (current_message_language=0) );
	else	return( (current_message_language=atoi(eptr)) );
}

	/* ----------- */
#endif 	/* _cicolang_c */
	/* ----------- */

