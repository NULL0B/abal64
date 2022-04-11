
#include <stdio.h>
#include <errno.h>
#include "stdtypes.h"
#include "traceman.h"

main()
{
	TRACEPTR	tptr;
	if ( initialise_trace_controller( "testsf.err" ) != 0 ) {
		sysprintf("ITC SUCCESS\n");
		if (( tptr = position_to_first( ANYTYPE )) != (TRACEPTR) 0 ) {
			sysprintf("%s: %d %d %s\n",tptr->filename,tptr->ligne,tptr->colonne,tptr->message );
			while (( tptr = position_to_next( ANYTYPE )) != (TRACEPTR) 0 )
				sysprintf("%s: %d %d %s\n",tptr->filename,tptr->ligne,tptr->colonne,tptr->message );
			sysprintf("** END OF TRACE FILE **\n");
			if ((tptr = position_to_current()) != (TRACEPTR) 0) {
				sysprintf("%s: %d %d %s\n",tptr->filename,tptr->ligne,tptr->colonne,tptr->message );
				while (( tptr = position_to_previous( ANYTYPE )) != (TRACEPTR) 0 )
					sysprintf("%s: %d %d %s\n",tptr->filename,tptr->ligne,tptr->colonne,tptr->message );
				sysprintf("** TOP OF TRACE FILE **\n");
				}
			}
		terminate_trace_controller();
		}
	return(0);
}



