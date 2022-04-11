#ifndef	_EXMPEG_C
#define	_EXMPEG_C

#include "exmpegs.h"

int	read_command( int h, char * b, int blen )
{
	unsigned char c[4];
	int		o=0;
	while (o < blen) {
		if ( recv( h, c, 1, MSG_WAITALL ) <= 0 )
			break;
		else if ( c[0] == '\r' )
			continue;
		else if ( c[0] == '\n' )
			break;
		else if ( c[0] == '\t' )
			c[0] = ' ';
		else	{
			*(b+o) = c[0];
			o++;
			}
		}
	*(b+o) = 0;
	return(o);
}

int	extract_portion( char * rptr, char ** sptr, char * terminator )
{
	char * wptr;
	int	i=0;
	if (!( sptr ))
		return( 0 );
	else if (!( wptr = *sptr ))
		return( 0 );

	while (*wptr != 0)
	{
		if ( *wptr == *terminator )
		{
			*(rptr+i) = 0;
			*sptr = wptr;
			return( i );	
		}
		else
		{
		 	*(rptr+i) = *(wptr++);
			i++;
		}
	}
	return(0);
}

	/* --------- */
#endif	/* _EXMPEG_C */
	/* --------- */

