#ifndef	_safex_c
#endif 	_safex_c

#define	SAFE_X_EVENTS

#include <poll.h>
#include <errno.h>

static 	int	poll_connection( handle, delay )
	int	handle;
	int	delay;
{
	struct	pollfd context;
	while (1) {
		context.fd = handle;
		context.events = (POLLIN | POLLERR);
		context.revents = 0;
		switch ( poll(&context,1,delay) ) {
			case	-1	: /* Poll failed */
				if ( errno == EINTR ) 
					continue;
				else	return(0);
			case	 0	: /* Timeout	 */
				return(1);
			default		: 
				/* must be something!	*/
				/* could be error	*/
				if ( context.revents & POLLERR )
					return(0);
				else if ( context.revents & POLLHUP ) {
					panic( SIGHUP );
					return(0);
					}
				else	return(1);
			}
		}
}

private	int	SafeXWindowEvent(int mode) /* 0 : test, 1 : wait */
{
	int	c;
	while (1) {
		if ((c = XCheckWindowEvent(
				XGC.displayptr,
				XGC.desktopwindow,
				XGC.currentevents,
				&XGC.event
				))!=0) {
			return(1);
			}
		else if ((c = ConnectionNumber( XGC.displayptr )) >= 0) {
			if (!( poll_connection(c,( mode != 0 ? 50 : 0)) )) {
				panic(SIGTERM);
				}
			else if (!( mode ))
				return(0);
			else	continue;
			}
		else	panicpixel(SIGTERM);	
		}
}

#endif

