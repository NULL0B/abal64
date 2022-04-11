#ifndef	_EXRP_C
#define	_EXRP_C

#include "exrps.h"

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

char * 	rpc_parse_parameter( char * sptr )
{
	if (!( *sptr )) return((char *) 0);
	while (( *sptr != 0 ) && ( *sptr != ' ' )) sptr++;
	if( *sptr ) *(sptr++) = 0;
	return( sptr );
}

int	rpc_parse_hex_byte( char * sptr )
{
	int	v=0;
	int	c;
	if (!( c = *(sptr++) ))
		return(v);
	if ((c >= '0') && ( c <= '9'))
		v = (c - '0' );
	else if ((c >= 'a') && ( c <= 'f'))
		v = ((c - 'a') +10);
	else if ((c >= 'A') && ( c <= 'F'))
		v = ((c - 'A') + 10);
	v <<= 4;
	if (!( c = *(sptr++) ))
		return(v);
	if ((c >= '0') && ( c <= '9'))
		v |= (c - '0' );
	else if ((c >= 'a') && ( c <= 'f'))
		v |= ((c - 'a') +10);
	else if ((c >= 'A') && ( c <= 'F'))
		v |= ((c - 'A') + 10);
	return( v );
}

int	rpc_parse_hex_value( char ** sptr,int bytes )
{
	int	result=0;
	int	value=0;
	char	*	wptr=(char *) 0;
	if (!( sptr )) 
		return(0);
	else if (!( wptr = *sptr))
		return(0);
	else
	{
		while (( *wptr != 0 ) && ( *wptr == ' ' )) wptr++;
		while ( bytes-- )
		{
			value = rpc_parse_hex_byte( wptr ); wptr+= 2;
			result = (( result << 8 ) | ( value & 0x00FF ));
		}		
		while (( *wptr != 0 ) && ( *wptr == ' ' )) wptr++;
		*sptr = wptr;
		return( result );
	}
}

void	rpc_parse_hex_string(char * rptr, char ** sptr,int bytes )
{
	int	result=0;
	int	value=0;
	char	*	wptr=(char *) 0;
	if (!( sptr )) 
		return;
	else if (!( wptr = *sptr))
		return;
	else
	{
		while (( *wptr != 0 ) && ( *wptr == ' ' )) wptr++;
		while ( bytes-- )
		{
			value = rpc_parse_hex_byte( wptr ); wptr+= 2;
			*(rptr++) = (value & 0x00FF);
		}		
		while (( *wptr != 0 ) && ( *wptr == ' ' )) wptr++;
		*sptr = wptr;
		return;
	}
}

	/* ------- */
#endif	/* _EXRP_C */
	/* ------- */

