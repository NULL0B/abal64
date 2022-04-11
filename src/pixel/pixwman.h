#ifndef	_pixwman_h
#define	_pixwman_h

#include "pixwind.h"

struct	pixel_window_manager	{
	struct	pixel_window *	first;
	struct	pixel_window *	current;
	struct	pixel_window *	last;
	int			count;
	};

struct pixel_window * pwm_detach( struct pixel_window * wptr );
struct pixel_window * pwm_first( struct pixel_window * wptr );
struct pixel_window * pwm_insert( struct pixel_window * xptr, struct pixel_window * wptr );
struct pixel_window * pwm_last( struct pixel_window * wptr );
struct pixel_window * pwm_append( struct pixel_window * xptr, struct pixel_window * wptr );
struct pixel_window * pwm_resolve( int number );

int	pwm_liberate();
int	pwm_initialise();

#endif	/* _pixwman_h */
	/* ---------- */


