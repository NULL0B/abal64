#ifndef	_TRACE_C
#define	_TRACE_C

#include "basic.h"
#include "address.h"
#include "global.h"
#include "files.h"
#include "trace.h"

PUBLIC	VOID	activate_trace( nptr )
	BPTR 	nptr;
{
	if ((TraceHandle = FileCreate( nptr )) > 0)
		trace_active = 1;
	else	{
		TraceHandle = 0;
		trace_active = 0;
		}
	return;
}

PUBLIC	VOID	terminate_trace()
{
	if ( trace_active ) {
		FileFlush( TraceHandle );
		TraceHandle  = 0;
		trace_active = 0;
		}
	return;
}

PUBLIC	VOID	trace_puts( sptr )
	BPTR	sptr;
{
	INT	l=strlen(sptr);
	if ( trace_active )
		if ( FileWrite( TraceHandle, sptr, l ) != l)
			terminate_trace();
	return;
}

PUBLIC	VOID	trace_line()
{
	if ( trace_active )
		trace_puts("\r\n");
	return;
}

PUBLIC	VOID	trace_putw( v )
	INT	v;
{
	BYTE	buffer[16];
	if ( trace_active ) {
		sprintf(buffer,"%u",v);
		trace_puts( buffer );
		}
	return;
}

PUBLIC	VOID	trace_putl( v )
	LONG	v;
{
	BYTE	buffer[32];
	if ( trace_active ) {
		sprintf(buffer,"%lu",v);
		trace_puts( buffer );
		}
	return;
}


#endif	/* _TRACE_C */
	/* -------- */



