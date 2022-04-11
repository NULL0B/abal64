#ifndef	_pixwind_h
#define	_pixwind_h

#define	_UNKNOWN_WINDOW		78
#define	_INCORRECT_WINDOW	50

/*	-------------------------------		*/
/*	pixel window descriptor storage		*/
/*	-------------------------------		*/

struct	pixel_window	{

	struct	pixel_window	*	previous;
	struct	pixel_window	*	next;

#ifdef	UNIX
	/* Unix System specific X11 Window Handling */
	/* ---------------------------------------- */
	XImage 			*	image;	
	Window	parent;
	Window	handle;
#endif

#ifdef	WINDOWS
	/* Windows System specific GDI Window Handling */
	/* ------------------------------------------- */
#endif

	/* Logical Window Handling */
	/* ----------------------- */
	int	number;
	int	x_position;
	int	y_position;
	int	width;
	int	height;
	int	viewsize;
	int	border;
	int	foreground;
	int	background;
	char *	title;
	int	options;
	int	state;
	void *	storage;

	};

/*	------------------------------------------	*/
/*	pixel window interface function prototypes 	*/
/*	------------------------------------------	*/

int	create_pixel_window( int x, int y, int w, int h, int fg, int bg, char *title, int options );
int	show_pixel_window( int handle );
int	enter_pixel_window( int handle );
int	leave_pixel_window( int handle );
int	move_pixel_window( int handle, int tox, int toy );
int	resize_pixel_window( int handle, int width, int height );
int	hide_pixel_window( int handle );
int	remove_pixel_window( int number );

#endif	/* _pixwind_h */
	/* ---------- */


