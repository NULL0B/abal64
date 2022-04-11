#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#include <X11/Shell.h>
#include <X11/Xmd.h>
#include <X11/keysym.h>
#include <X11/cursorfont.h>
#include <X11/Xatom.h>

static	int	verbose=0;
static	int	alliance=0;

#define	_X11_MOUSE    ButtonPressMask | ButtonReleaseMask  | PointerMotionMask | ButtonMotionMask
#define	_X11_KEYBOARD KeyPressMask    | KeyReleaseMask     | KeymapStateMask
#define _X11_REFRESH  ExposureMask    | VisibilityChangeMask // |  StructureNotifyMask |  ResizeRedirectMask | SubstructureRedirectMask 
#define _X11_FOCUS    EnterWindowMask | LeaveWindowMask | FocusChangeMask 

#define	_X11_MOUSE_EVENTS _X11_MOUSE | _X11_KEYBOARD | _X11_REFRESH | _X11_FOCUS

#define	_X11_SPECIAL_EVENTS ButtonPressMask | ButtonReleaseMask | _X11_KEYBOARD | _X11_REFRESH | _X11_FOCUS

#define	_X11_STANDARD_EVENTS _X11_KEYBOARD | _X11_REFRESH | _X11_FOCUS

struct	Qxcontext {
	char	*	name;
	Display *  	display;
	Window	   	window;
	int		width;
	int		height;
	int		screen;
	int		flags;
	int		x_position;
	int		y_position;
	int		border;
	int		currentevents;
	XEvent		event;
	char		exa[1024];
	char 		command[4096];
	} QxC = {
	(char *) 0,
	(Display *) 0,
	(Window) 0,
	0,0,0,0,0,0,0,0
	};


static	void	setexa()
{

	sprintf(QxC.exa,"%s \'-x%u:%u:%u:%u:%u:f%u:w%lu\' ", /* quote avant et apres -x */
		"/home/Dev/abal32/bin/exa32.37",
		24,80,0,0,7,getpid(),QxC.window);
	return;
}

static	int	failure(int ecode, char * mptr)
{
	if (ecode != 0 ) {
		printf("error::pid(%u).value(%u,%s)\n",getpid(),ecode,mptr);
		}
	return( ecode );
}

static	int	qx_error()	{	return( failure( 888, "qx_failure" ) );		}
static	int	qx_io_error()	{	return( failure( 777, "qx_io_failure" ) );	}
static	int	qx_after()	{	return( failure( verbose, "qx_after" ) );	}

static	int	doit( char * aptr )
{
	int	abandon=0;
	int	state=0;
	if ( verbose )	printf("verbose::doit(%s)\n",aptr );
	if ( verbose )	printf("verbose::XOpenDisplay(%s)\n",(QxC.name ? QxC.name : "Null" ));

	if (!(QxC.display = XOpenDisplay(QxC.name)))
		return( failure( 999, "XOpenDisplay" ) );

	if ( QxC.flags & 1 ) {
		if ( verbose )
			printf("verbose::XSetAfterFunction(qx_after)\n");
		XSetAfterFunction( QxC.display, qx_after );
		}

	if ( QxC.flags & 2 ) {
		if ( verbose )	printf("verbose::XSetErrorHandler(qx_error)\n");
		XSetErrorHandler( qx_error );
		if ( verbose )	printf("verbose::XSetIOErrorHandler(qx_io_error)\n");
		XSetIOErrorHandler( qx_io_error );
		}

	QxC.screen  	= DefaultScreen(QxC.display);
	QxC.width	= DisplayWidth(QxC.display,QxC.screen);
	QxC.height	= DisplayHeight(QxC.display,QxC.screen);
	QxC.x_position 	= QxC.y_position = 0;
	QxC.border	= 1;

	if ( verbose )	printf("verbose::XCreateWindow(%u,%u,%u,%u)\n",QxC.x_position,QxC.y_position, QxC.width, QxC.height);

	QxC.window = XCreateSimpleWindow(
		QxC.display, RootWindow(QxC.display,QxC.screen),
		QxC.x_position,QxC.y_position, QxC.width, QxC.height,
		QxC.border,
		BlackPixel(QxC.display,QxC.screen),
		WhitePixel(QxC.display,QxC.screen)  );

	setexa();

	if ( verbose )	printf("exa=%s\n",QxC.exa);

	QxC.currentevents = _X11_MOUSE_EVENTS;

	if ( verbose )	printf("verbose::XSelectInput(%08.8X)\n",QxC.currentevents);
	XSelectInput( QxC.display, QxC.window, QxC.currentevents );

	if ( verbose )	printf("verbose::XMapWindow(%u)\n",QxC.window);
	XMapWindow(QxC.display,QxC.window);

	if ( alliance ) {
		if ( verbose )	printf("verbose::XSetInputFocus(w=%u)\n",QxC.window);
		XSetInputFocus(QxC.display,QxC.window,RevertToPointerRoot,CurrentTime );
		}
	else	{
		if ( verbose )	printf("verbose::XSetInputFocus(PointerRoot)\n",QxC.window);
		XSetInputFocus(QxC.display, PointerRoot,RevertToPointerRoot,CurrentTime );
		}

	while(!(abandon)) {
		if ( verbose )	printf("verbose::XNextEvent()\n");
		XNextEvent(QxC.display, &QxC.event );
		switch ( QxC.event.type ) {
			case	MappingNotify		:
				printf("MappingNotifyEvent()\n");
				break;
			case	SelectionClear		:
				printf("SelectionClearEvent()\n");
				break;
			case	SelectionRequest 	:
				printf("SelectionRequestEvent()\n");
				break;
			case	SelectionNotify		:
				printf("SelectionNotifyEvent()\n");
				break;
			case	ButtonPress		:
				printf("ButtonPressEvent()\n");
				break;
			case	ButtonRelease		:
				XSetInputFocus(QxC.display, None, None,CurrentTime );
				QxC.currentevents = _X11_STANDARD_EVENTS;
				XSelectInput( QxC.display, QxC.window, QxC.currentevents );
				XFlush( QxC.display );
				printf("ButtonReleaseEvent()\n");
				printf("load.go,exa=%s,tcode=%s\n",QxC.exa,aptr);
				sprintf(QxC.command,"%s %s",QxC.exa,aptr); 
				printf("command=%s\n",QxC.command);
				sleep(2);
				system( QxC.command );
				QxC.currentevents = _X11_MOUSE_EVENTS;
				XSelectInput( QxC.display, QxC.window, QxC.currentevents );
				XSetInputFocus(QxC.display, PointerRoot,RevertToPointerRoot,CurrentTime );
				XFlush( QxC.display );
				break;
			case	MotionNotify		:
				printf("MotionNotifyEvent()\n");
				break;
			case	KeyPress		:	
				printf("KeyPressEvent()\n");
				break;
			case	KeyRelease		:
				printf("KeyReleaseEvent()\n");
				break;
			case	UnmapNotify		:
				printf("UnmapNotifyEvent()\n");
				break;
			case	MapNotify		:
				printf("MapNotifyEvent()\n");
				break;
			case	ConfigureNotify		:
				printf("ConfigureNotifyEvent()\n");
				break;
			case	Expose			:
				printf("ExposeEvent()\n");
				break;
			case	GraphicsExpose		:
				printf("GraphicsExposeEvent()\n");
				break;
			case	VisibilityNotify	:
				printf("VisibilityNotifyEvent()\n");
				break;
			case	EnterNotify		:
				printf("EnterNotifyEvent()\n");
				break;
			case	LeaveNotify		:
				printf("LeaveNotifyEvent()\n");
				break;
			case	FocusIn			:
				printf("FocusInEvent()\n");
				break;
			case	FocusOut		:
				printf("FocusOutEvent()\n");
				break;
			case	DestroyNotify		:
				printf("DestroyNotifyEvent()\n");
				break;
			case	ResizeRequest		:
				printf("ResizeRequestEvent()\n");
				break;
			case	ClientMessage		:
				printf("ClientMessageEvent()\n");
				break;
			default				:
				printf("OtherEvent()\n");
				break;
			}
		}

	XSelectInput( QxC.display, QxC.window, 0 );

	if ( verbose )	printf("verbose::XUnmapWindow()\n");
	XUnmapWindow(QxC.display,QxC.window);

	if ( verbose )	printf("verbose::XDestroyWindow()\n");
	XDestroyWindow(QxC.display,QxC.window);

	if ( verbose )	printf("verbose::XCloseDisplay()\n");
	XCloseDisplay( QxC.display );

	return(0);
}

static	int	option( char * aptr )
{
	char *	bptr=aptr;

	if ( verbose )
		printf("verbose::option(%s)\n",aptr);

	switch( *(aptr++) ) {
		case	'e'	:	QxC.flags |= 2;
					return(0);
		case	'a'	:	QxC.flags |= 1;
					return(0);
		case	'v'	:	verbose=1; 
					return(0);
		case	'n'	:	QxC.name = aptr;
					return(0);
		case	'w'	:	QxC.width = atoi( aptr );
					return(0);
		case	'h'	:	QxC.height = atoi( aptr );
					return(0);
		default		:	return(failure(30,bptr));
		}
}


static	int	operation(int argc, char * argv[] )
{
	int	status;
	int	argi;
	char *	aptr;
	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( verbose )
			printf("verbose::argv[%u]=%s\n",argi,aptr);

		if ( *aptr == '-' ) {
			if ((status = option( (aptr+1) )) != 0)
				return( status );
			else	continue;
			}
		else if (( status = doit( aptr )) != 0 )
			return( status );
		else	continue;	
		}
	return(0);
}

static	int	banner()
{
	printf("\n   X/11 Event Qualifier : Version 1.0a ");
	printf("\n   Provisoire du 23/10/2008 ");
	printf("\n   Copyright (me) Now \n\n");
	return(0);
}


int	main(int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( operation(argc,argv) );
}


