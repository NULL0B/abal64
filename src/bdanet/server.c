#ifndef	_SERVER_C
#define	_SERVER_C

#include "basic.h"
#include "address.h"
#include "global.h"
#include "trace.h"
#include "url.h"
#include "server.h"


PUBLIC	VOID	show_server_usage()
{
	printf("         [ -s<socket_number>  ] : Activated by INETD (silence)  \n");
	printf("         [ -n<host_url>       ] : Administrative Host           \n");
#ifdef	_TRACE_H
	printf("         [ -t<trace_filename> ] : Activate Tracing to file      \n");
#endif
	printf("         [ -x<host_url>       ] : Request Server Shutdown       \n");
	return;
}

PUBLIC	VOID	set_server_silence( aptr )
	BPTR	aptr;
{
	silence = 1;
	return;
}

PUBLIC	VOID	set_server_verbose( aptr )
	BPTR	aptr;
{
	if (!( silence ))
		set_global_verbose( aptr );
	return;
}

PUBLIC	VOID	set_server_debug( aptr )
	BPTR	aptr;
{
	if (!( silence ))
		set_global_debug( aptr );
	return;
}

PUBLIC	VOID	set_server_master( administrator )
	BPTR	administrator;
{
	AdminName = administrator;
	return;
}

#ifdef	_TRACE_H
PUBLIC	VOID	set_server_trace( trace_file )
	BPTR	trace_file;
{
	TraceName = trace_file;
	return;
}
#endif


PRIVATE	INT	compare_address( aptr, bptr )
	BPTR  aptr;
	BPTR  bptr;
{
	while (( *aptr ) && ( *bptr )) {
		if (( *aptr == ':' ) && ( *bptr == ':' ))
			return(1);
		else if ( *(aptr++) != *(bptr++) )
			return(0);
		}
	if ( *(aptr++) != *(bptr++) )
		return(0);
	else	return(1);
}

PUBLIC	INT	is_authorised( aptr )
	ADDRPTR	aptr;
{
	if ((AdminName != (BPTR) 0)
	&&  (Administrator != (URLPTR) 0))
		return( verify_url( Administrator, aptr ) );
	else	return( 1 );
}


PRIVATE	INT	privatise()
{
	if ((AdminName != (BPTR) 0)
	&&  ((Administrator = allocate_for_url( AdminName,0L )) == (URLPTR) 0))
		return( 27 );
	else	return( 0  );
}

PUBLIC	INT	start_server()
{
	INT	status=0;
	if ( ! ( ServerStarted ) ) {

		if ((status = privatise()) == 0) {
			ServerStarted=1;

#ifdef	_TRACE_H
			if ( TraceName != (BPTR) 0 )
				activate_trace( TraceName );
#endif
			}
		}
	return(status);
}

PUBLIC	INT	close_server()
{
	if ( ServerStarted ) {

#ifdef	_TRACE_H
		if ( trace_active )
			terminate_trace();
#endif
		if ((AdminName != (BPTR) 0)
		&&  (Administrator != (URLPTR) 0))
			Administrator = liberate_for_url( Administrator );

		ServerStarted = 0;
		}

	return(0);
}


#endif	/* _SERVER_C */
	/* --------- */

