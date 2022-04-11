#ifndef	_pixwind_c
#define	_pixwind_c

#include <string.h>

#include "pixwind.h"
#include "pixwman.c"

#include "allocate.h"


/*	-------------------------------		*/
/*	pixel window descriptor storage		*/
/*	-------------------------------		*/

struct	pixel_window *	allocate_pixel_window()
{
	struct	pixel_window	* wptr;
	
	if (!( wptr = allocate( sizeof( struct pixel_window ) )))
		return( wptr );
	else	{
		wptr->previous 	=
		wptr->next	= (struct pixel_window *) 0;
#ifdef	UNIX
		wptr->parent 	= (Window) 0;
		wptr->handle	= (Window) 0;
		wptr->image	= (XImage*) 0;
#endif
		wptr->number	=0;
		wptr->state	=0;
		wptr->x_position=0;
		wptr->y_position=0;
		wptr->width	=0;
		wptr->height	=0;
		wptr->viewsize  =0;
		wptr->border	=0;
		wptr->foreground=0;
		wptr->background=0;
		wptr->title	=(char *)0;
		wptr->options	=0;
		wptr->storage	=(char*) 0;
		return( wptr );
		}
}

int	liberate_pixel_window(struct pixel_window * wptr )
{
	if ( wptr ) {

#ifdef	UNIX
		if ( wptr->handle != (Window) -1 ) {
			XDestroyWindow(XGC.displayptr,wptr->handle);
			}

		if ( wptr->image ) {
			if ( wptr->image->data )
				wptr->image->data = liberate( wptr->image->data );
			XDestroyImage( wptr->image );
			}
#endif
		if ( wptr->title )
			liberate( wptr->title );

		if ( wptr->storage )
			liberate( wptr->storage );

		liberate( wptr );

		if (PWM.count) {
			PWM.count--;
			}

		}
	return(0);
}
			
/*	------------------------------------------	*/
/*	pixel window interface function prototypes 	*/
/*	------------------------------------------	*/

int	create_pixel_window( int x, int y, int w, int h, int fg, int bg, char *title, int options )
{
	struct	pixel_window	* wptr;
	if (!( wptr = allocate_pixel_window()))
		return(0);
	else if (!( wptr->title = allocate( strlen(title)+1 ) ))
		return( liberate_pixel_window(wptr) );
	else	{
		strcpy( wptr->title, title );
		wptr->x_position = x;
		wptr->y_position = y;
		wptr->width	 = w;
		wptr->height	 = h;
		wptr->foreground = fg;
		wptr->background = bg;
		wptr->options    = options;

#ifdef	UNIX
		/* -------------------------------- */
		/* Create system window and storage */
		/* -------------------------------- */
		wptr->handle = XCreateSimpleWindow(
			XGC.displayptr, RootWindow(XGC.displayptr,XGC.screen),
			wptr->x_position,wptr->y_position, wptr->width, wptr->height,
			wptr->border,
			BlackPixel(XGC.displayptr,XGC.screen),
			WhitePixel(XGC.displayptr,XGC.screen)  );

		wptr->image = XCreateImage(XGC.displayptr, XGC.vis, XGC.visdepth, ZPixmap, 0, NULL,
				 wptr->width, wptr->height,
				 BitmapPad(XGC.displayptr), 0);

		wptr->image->byte_order = LSBFirst;

		/* Allocate Desktop Image Data Storage Zone */
		/* ---------------------------------------- */
		if (!(wptr->image->data = allocate((wptr->viewsize = (wptr->image->bytes_per_line * wptr->image->height))))) {
			liberate_pixel_window( wptr );
			return(0);
			}
	
#endif

		/* ------------------------------------------------- */
		/* ad to list of windows, atribute number and return */
		/* ------------------------------------------------- */
		wptr->number = ++PWM.count;

		pwm_last( wptr );
		return( wptr->number );
		}
}

		
int	show_pixel_window( int handle )
{
	struct	pixel_window	* wptr;
	if (!( wptr = pwm_resolve( handle )))
		return( _UNKNOWN_WINDOW );
	else if ( wptr->handle != (Window) -1 ) {
#ifdef	UNIX
		XMapWindow(XGC.displayptr,wptr->handle);
		XPutImage(
			XGC.displayptr, wptr->handle,
			XGC.gc, 	wptr->image,
			wptr->x_position, 	wptr->y_position, 
			wptr->x_position, 	wptr->y_position, 
			wptr->width, wptr->height );
#endif
		return(0);
		}
	else	{
		return(_INCORRECT_WINDOW);
		}
}

int	enter_pixel_window( int handle )
{
	struct	pixel_window	* wptr;
	if (!( wptr = pwm_resolve( handle )))
		return( _UNKNOWN_WINDOW );
	else if ( wptr->handle != (Window) -1 ) {
		return(0);
		}
	else	{
		return(_INCORRECT_WINDOW);
		}
}

int	leave_pixel_window( int handle )
{
	struct	pixel_window	* wptr;
	if (!( wptr = pwm_resolve( handle )))
		return( _UNKNOWN_WINDOW );
	else if ( wptr->handle != (Window) -1 ) {
		return(0);
		}
	else	{
		return(_INCORRECT_WINDOW);
		}
}

int	move_pixel_window( int handle, int tox, int toy );
int	resize_pixel_window( int handle, int width, int height );
int	hide_pixel_window( int handle )
{
	struct	pixel_window	* wptr;
	if (!( wptr = pwm_resolve( handle )))
		return( _UNKNOWN_WINDOW );
	else if ( wptr->handle != (Window) -1 ) {
#ifdef	UNIX
		XUnmapWindow(XGC.displayptr,wptr->handle);
#endif
		return(0);
		}
	else	{
		return(_INCORRECT_WINDOW);
		}
}

int	remove_pixel_window( int number )
{
	struct	pixel_window	* wptr;
	if (!( wptr = pwm_resolve( number )))
		return( _UNKNOWN_WINDOW );
	else	{
		pwm_detach( wptr );
		liberate_pixel_window( wptr );
		return(0);
		}
}


void	test_new_window()
{
	int	wh;
	int	status;
	sleep(10);
	pwm_initialise();
	if ((wh = create_pixel_window( 50,50, 300,200, 16, 0, "test X11 window", 0 )) != 0) {
		if (!(status = show_pixel_window(wh) )) {
			sleep(10);
			if (( status = hide_pixel_window( wh )) != 0)
				printf("\r\nhide pixel window failure : %u \r\n",status);

			}
		else	printf("\r\nshow pixel window failure : %u \r\n",status);

		if ((status = remove_pixel_window( wh )) != 0)
			printf("\r\nremove pixel window failure : %u \r\n",status);

		}
	else	printf("\r\ncreate pixel window failure\r\n");
	pwm_liberate();
	return;

}


#endif	/* _pixwind_c */
	/* ---------- */



