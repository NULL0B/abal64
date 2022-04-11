//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_argvzero_c
#define _html_argvzero_c

#include "argvzero.h"
#include "string.h"

static	char *	argvzero=(char *) 0;

#define	BACKSLASH 0x005C

void	setargvzero( char * sptr )
{
	int	i;
	int	backslash;
	if ( argvzero )
		delargvzero();

	if( sptr ) {

		argvzero = html_string::allocate( 
			html_string::length( _FILE_SERVICE ) +
			html_string::length( sptr ) +
			16 );

		// Check for Network Loaded Version
		// --------------------------------
		if (( *sptr     == BACKSLASH )
		&&  ( *(sptr+1) == BACKSLASH ))
			sprintf(argvzero,"%s%s",_FILE_SERVICE,sptr );
		else	sprintf(argvzero,"%s///%s",_FILE_SERVICE,sptr );

		for ( backslash=i=0; *(argvzero + i) != 0; i++ ) {
			if ( *(argvzero +i) == BACKSLASH )
				backslash = i;
			else if ((!( backslash ))
			     &&  ( *(argvzero +i) == '.' ))
				backslash = i;
			}

		if ( backslash )
			*( argvzero + backslash + 1 ) = 0;

		for ( i=0; *(argvzero + i) != 0; i++ )
			if ( *(argvzero +i) == BACKSLASH )
				*( argvzero + i) = '/';

		}
	return;	
}

char *	useargvzero( char * sptr )
{
	if ((!( argvzero ))
	||  (!( sptr     )))
		return( sptr );

	if (( html_string::compare( ':', sptr, _HTTP_SERVICE  ))
	||  ( html_string::compare( ':', sptr, _FILE_SERVICE  ))
	||  ( html_string::compare( ':', sptr, _HTTPS_SERVICE ))
	||  ( html_string::compare( ':', sptr, _FTP_SERVICE   )))
		return( sptr );

	return( html_string::concatenate( argvzero, sptr ) );
}

void	delargvzero()
{
	if ( argvzero != (char *) 0 )
		html_string::liberate( argvzero );
	argvzero = (char *) 0;
	return;
}
	

#endif	// _html_argvzero_c


