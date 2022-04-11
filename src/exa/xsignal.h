#ifndef	_xsignal_h
#define	_xsignal_h
#include <signal.h>
#ifdef	LINUX
#define	signal(s,v) x_signal(s,v)
void	* signal( int sig, __sighandler_t handler );
#endif
#endif	/* _xsignal_h */

