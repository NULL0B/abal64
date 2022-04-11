#include <stdio.h>

#define	indexsize 48
#define	recordsize 4
char	buffer[indexsize+recordsize+indexsize+4];

void	setlong( int offset, long value )
{ 
	char	* bptr;
	int	i;
	if (( buffer )
	&&  ( (offset+3) < recordsize )) {
		for ( 	bptr = (buffer + offset + indexsize+6), i=0;
			i < 4;
			i++, bptr--, value >>= 8 )
			*bptr = (value & 0x000000FFL);
		}
	return;
}

long	getlong( int offset )
{
	char *  bptr;
	long	value=0L;
	int	i;
	if (( buffer )
	&&  ( (offset+3) < recordsize )) {
		for ( 	bptr = (buffer + offset + indexsize+3), i=0;
			i < 4;
			i++, bptr++ )
			value = ((value << 8) | ((long) ( *( bptr ) & 0x00FF )));
		}
	return( value );
}


