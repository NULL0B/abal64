#ifndef	_xpixel_h
#define	_xpixel_h

#include <stdio.h>

#ifdef	unix
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#endif

#define	_USE_X
#ifdef	_USE_X
#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#include <X11/Shell.h>
#include <X11/Xmd.h>
#include <X11/keysym.h>
#include <X11/cursorfont.h>
#include <X11/Xatom.h>
#ifdef	USING_X_TOOLSKET
#include <X11/Xmu/StdSel.h>
#include <X11/Xaw/Form.h>
#include <X11/Xaw/Command.h>
#include <X11/Xaw/Toggle.h>
#include <X11/Xaw/Viewport.h>
#endif
#else
#include "xeleven.h"
#endif
#define	_X11_MOUSE    ButtonPressMask | ButtonReleaseMask  | PointerMotionMask | ButtonMotionMask
#define	_X11_KEYBOARD KeyPressMask    | KeyReleaseMask     | KeymapStateMask
#define _X11_REFRESH  ExposureMask    | VisibilityChangeMask 
#define	_X11_PRIVATE  StructureNotifyMask |  ResizeRedirectMask | SubstructureRedirectMask 
#define _X11_FOCUS    EnterWindowMask | LeaveWindowMask | FocusChangeMask 
#define	_X11_MOUSE_EVENTS _X11_MOUSE | _X11_KEYBOARD | _X11_REFRESH | _X11_FOCUS | _X11_PRIVATE
#define	_X11_STANDARD_EVENTS _X11_KEYBOARD | _X11_REFRESH | _X11_FOCUS
#define	_X11_SUSPENDED_EVENTS _X11_REFRESH | _X11_FOCUS

#define	public
#define	private static

#define	byte	unsigned char
#define word	unsigned int

struct	push_control	{
	struct push_control * next;
	char	buffer[1];
	};

struct	graphical_context	{
	int	pixelsize;		/* bytes / pixel 1,2,3,4	*/
	int	mapping;		/* colour mapping active 0/1	*/
	int	mode;			/* graphical mode value		*/
	int	x_position;		/* X Position of window 	*/
	int	y_position;		/* Y Position of window 	*/

	int	targetx;		/* x coordinate for share ware	*/
	int	targety;		/* y coordinate for share ware	*/

	int	width;			/* width in pixels		*/
	int	height;			/* height in rows		*/
	int	rightmargin;		/* Edge coltroller 		*/
	int	border;			/* width of border in pixels	*/
	int	depth;			/* colour depth (colour count)	*/
	int	bpp;			/* bits per pixel		*/

	char	*	display_name;	/* Name of physical device	*/
	int		display_width;	/* Width of physical device	*/
	int		display_height;	/* Height of physical device	*/
	int		screen;		/* Default display screen id	*/

	char	*	titleformat;	/* points to title format	*/
	char	*	title;		/* allocated formated title	*/
	char	*	desktopname;	/* configuration name		*/
	char	*	desktopicon;	/* configuration icon		*/

	int			viewsize;
	struct push_control *	heap;	/* Push Pop Screen Control	*/

	Display * 	displayptr;	/* display  handle of X terminal*/
	Atom		WmProtocols;	/* Identifies WM PROTOCOLS Atom	*/
	Atom		WmDelete;   	/* Identifies WM DELETE    Atom	*/

	int		textcursor;	/* Defines the GIGO getch/op cursir shape */

	Cursor		standardcursor;	/* Defines the standard cursor	*/
	Cursor		waitingcursor;	/* Defines the standard cursor	*/
	Cursor		alternatecursor;/* Defines the standard cursor	*/
	Cursor		problemcursor;	/* Defines the standard cursor	*/

	/* Variables required for the control of the output image */
	/* ------------------------------------------------------ */	
	int		softwidth;	/* Width of software output	*/
	int		softheight;	/* Height of software output	*/
	char	*	softoutput;	/* output catcher for background*/	

	char	*	shadow;		/* buffer for screen gets	*/
	char	*	principal;	/* buffer for screen gets	*/
	char	*	alternative;	/* buffer for screen gets	*/
	char	*	storage;	/* alias to image->data   	*/
	int		outputfrozen;	/* output state			*/
	int		topx;
	int		topy;
	int		endx;
	int		endy;
	char		modifierPressed[256];	/* Stores key events	*/

	XTextProperty windowName;
	XTextProperty iconName;

	XImage 	*	imageptr;	/* data image / pixel storage	*/

	Visual	*	vis;
	unsigned int	visdepth;
	unsigned int	visbpp; 
	unsigned int	redshift;
	unsigned int	greenshift;
	unsigned int	blueshift;

	int		control;	/* Control Key state		*/
	int		shift;		/* Shift Key State		*/
	int		alt;		/* Alt  Key state		*/
	int		altcompose;	/* Alt  Key state		*/
	int		keyconfig;	/* options for alt, Ctrl etc	*/

	GC 		gc;		/* graphical curser		*/
	Window 		desktopwindow;	/* the actual output target	*/
	Colormap 	cmap;		/* Our Colour map		*/
	int		currentevents;	/* Current event mask		*/
	int		pending;	/* Event received and pending	*/
	char		paddingbefore[512];
	XEvent		event;
	char		paddingafter[1024];
	int		users;		/* controls nested activation	*/
	int		leftbutton;
	int		rightbutton;
	int		middlebutton;
	int		upwheel;
	int		downwheel;
	int		keyboardgrab;
	int		windowflags;
	int		pastekey;
	int		ismapped;

	Atom		ClipBoard;
	unsigned char *	PublicSelection;
	unsigned char *	ClipBoardValue;
	unsigned long	ClipBoardIndex;
	unsigned long	ClipBoardLength;
	Window 		ClipBoardOwner;

	int		trace_error_count;
	char*		lastpalette;
	int		scale;
	
	/* ---------------------------------------------------------- */
	/* these variables are used to save the Freeze/Thaw State for */
	/* Alliance who do some crazy things ........................ */
	/* ---------------------------------------------------------- */
	int		pushed;

	int		hold_of;
	int		hold_tx;
	int		hold_ty;
	int		hold_ex;
	int		hold_ey;

	/* ---------------------------------------------------------- */
	/* this sections provides extensions to allow background mode */
	/* ---------------------------------------------------------- */
	int		inhibitMap;	/* inhibits mapping of window */

	};

void	outzone(int,int,int,int);

#define	scaled_dimension( v ) ( XGC.scale ? (v*XGC.scale) : v )
#define	scaled_coordinate(v ) ( XGC.scale ? (v*XGC.scale) : v )
#define	scaled_reduction( v ) ( XGC.scale ? (v/XGC.scale) : v )

#define ALSMID "pixel"

#include "allocate.h"


#include "pixtrace.h"

#endif	/* _xpixel_h */

