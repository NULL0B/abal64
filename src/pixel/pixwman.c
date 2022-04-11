#ifndef	_pixwman_c
#define	_pixwman_c

#include "pixwman.h"

struct	pixel_window_manager PWM = {
		(struct pixel_window *) 0,
		(struct pixel_window *) 0,
		(struct pixel_window *) 0,
		0
		};

/*	---------------------------------------------------------	*/
/*	p i x e l   w i n d o w   m a n g e r   f u n c t i o n s 	*/
/*	---------------------------------------------------------	*/

struct pixel_window * pwm_detach( struct pixel_window * wptr )
{
	if ( wptr->previous )
		wptr->previous->next = wptr->next;
	else	PWM.first = wptr->next;

	if ( wptr->next )
		wptr->next->previous = wptr->previous;
	else	PWM.last = wptr->previous;

	return( wptr );
}

struct pixel_window * pwm_first( struct pixel_window * wptr )
{
	if (!( wptr->next = PWM.first ))
		PWM.last = wptr;
	else 	wptr->next->previous = wptr;
	PWM.first = wptr;
	return( wptr );
}

struct pixel_window * pwm_insert( struct pixel_window * xptr, struct pixel_window * wptr )
{
	if (!( wptr->previous = xptr->previous ))
		PWM.first = wptr;
	else	wptr->previous->next = wptr;
	wptr->next = xptr;
	xptr->previous = wptr;
	return( wptr );
}

struct pixel_window * pwm_last( struct pixel_window * wptr )
{
	if (!( wptr->previous = PWM.last ))
		PWM.first = wptr;
	else	wptr->previous->next = wptr;
	PWM.last = wptr;
	return( wptr );
}

struct pixel_window * pwm_append( struct pixel_window * xptr, struct pixel_window * wptr )
{
	if (!( wptr->next = xptr->next ))
		PWM.last = wptr;
	else	wptr->next->previous = wptr;
	xptr->next = wptr;
	wptr->previous = xptr;
	return( wptr );
}

struct pixel_window * pwm_resolve( int number )
{
	struct	pixel_window *	wptr;
	for (	wptr=PWM.first;
		wptr != (struct pixel_window *) 0;
		wptr = wptr->next )
		if ( wptr->number == number )
			break;
	return( wptr );
}

int	pwm_liberate()
{
	struct	pixel_window *	wptr;
	while ((wptr = PWM.first) != (struct pixel_window *) 0) {
		pwm_detach( wptr );
		liberate_pixel_window( wptr );
		}
	return(0);
}

int	pwm_initialise()
{
	PWM.first = PWM.last = PWM.current = (struct pixel_window *) 0;
	PWM.count = 0;
	return(0);
}


#endif	/* _pixwman_c */
	/* ---------- */

