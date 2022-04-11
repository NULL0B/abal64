#ifndef	_inipixel_c
#define	_inipixel_c

#include <stdio.h>
#include "xpixel.h"
#include "palet.h"
#include "apush.h"
#include "stdevent.h"
#include "stdbuffer.h"

public struct graphical_context	XGC;

private	int			graphical_mode=-1;
private	int			graphical_width=-1;
private	int			graphical_height=-1;
private	char		*	displayname="Pixel Library";
private	char		*	displayicon="GuiPixel";

private	int			console_graphics=-1;
private	int			GrabInputFocus=1;

extern	int			GigoXtrace;	/* public GIGO tracing control  */
extern	int			GigoKstate;	/* public GIGO keyboard control */

public				unsigned char  bRgbTable[256];
public				unsigned short wRgbTable[256];
public				unsigned long  lRgbTable[256];

private	XClassHint	ClassHints;

#include "getbpp.c"

public	Window	parentWindow=(Window) 0;

public	void	use_parent_window( Window w )
{
	parentWindow = w;
	return;
}

public	Window	x_window()
{
	return( XGC.desktopwindow );
}


private 	void	GigoCatcher(Widget w,XEvent *ev,XtPointer ptr,Boolean *cont);

private	void	thaw()
{
	if ( GigoXtrace & 256 ) {
		printf("thaw : frozen=%u\r\n",XGC.outputfrozen);
		}
	XGC.topx = XGC.width;
	XGC.topy = XGC.height;
	XGC.outputfrozen = 0;
	XGC.endx = XGC.endy = 0;
	return;
}

private	void	integrate(int x, int y, int width, int height )
{
	if ( x < XGC.topx ) XGC.topx = x;
	if ( y < XGC.topy ) XGC.topy = y;
	if (( x+width  ) > XGC.endx)
		XGC.endx = (x+width);
	if (( y+height ) > XGC.endy )
		XGC.endy = (y+height);
	if ( GigoXtrace & 512 ) {
		printf("integrate(%u,%u,%u,%u) -> (%u,%u,%u,%u)\r\n",x,y,width,height,XGC.topx,XGC.topy,XGC.endx,XGC.endy);
		}
	return;
}

/*
 *	s e t _ d i s p l a y _ n a m e ( string name )
 *	
 *	sets a string value to be used by the initialisation routines
 *	as the desktop title.
 *
 */

public	void	set_desktop_name( char * nptr )
{
	displayname = nptr;
	return;
}

public	int	windowtitle( char * sptr )
{
	/* Ensure that the display has been opened */
	/* --------------------------------------- */
	XStringListToTextProperty( &sptr, 1, &XGC.windowName );
	if (( XGC.displayptr != (Display *) NULL ) 
	&&  ( XGC.desktopwindow != (Window) NULL ))  {
		if (!( parentWindow ))
			XSetWMName(XGC.displayptr,XGC.desktopwindow, &XGC.windowName );
		}
	return(0);

}

/*
 *	s e t _ d i s p l a y _ i c o n ( string icon )
 *	
 *	sets a string value to be used by the initialisation routines
 *	as the desktop icon.
 *
 */

public	void	set_desktop_icon( char * nptr )
{
	displayicon = nptr;
	return;
}

public	int	windowicon( char * sptr )
{
	/* Ensure that the display has been opened */
	/* --------------------------------------- */
	XStringListToTextProperty( &sptr, 1, &XGC.iconName   );
	if (( XGC.displayptr != (Display *) NULL ) 
	&&  ( XGC.desktopwindow != (Window) NULL ))  {
		if (!( parentWindow ))
			XSetWMIconName(XGC.displayptr,XGC.desktopwindow, &XGC.iconName );
		}
	return(0);
}

public	int	standard_system_process( int value, char * sptr, int slen )
{
	char	buffer[513];
	int	i;
	int	nlen;
	for (nlen=0,i=0; i < slen; i++ ) {
		if ( i >= 512 )
	break;
		else if (( buffer[i] = *(sptr+i)) != ' ')
			nlen = (i+1);
		}
	buffer[nlen] = 0;	
	switch ( value ) {
		case	1 :	/* set window name */
			windowtitle( buffer );
			break;
		case	2 :	/* set icon name */
			windowicon( buffer );
			break;
		}
	return(0);
}

private	void	signal_handler(int sid)
{
	switch ( sid ) {
		case	SIGINT	:
		case	SIGHUP	:
		case	SIGTERM	:
			/* Protection against Evil !*/
			(void) signal(sid,SIG_DFL);
			liberatepixel();
			exit(1);
		}
	/* Lets ignore the others for now */
	/* ------------------------------ */
	return;
}

public	void	initialisesignals()
{
	(void) signal(SIGHUP,signal_handler);
	(void) signal(SIGINT,signal_handler);
	(void) signal(SIGTERM,signal_handler);
	return;
}

public	void	liberatesignals()
{
	(void) signal(SIGHUP,SIG_DFL);
	(void) signal(SIGINT,SIG_DFL);
	(void) signal(SIGTERM,SIG_DFL);
	return;
}

int	hardware()	
{
	if ( GigoXtrace & 256 ) {
		printf("hardware : frozen=%u\r\n",XGC.outputfrozen);
		}
	if (( XGC.softwidth  != 0)
	&&  ( XGC.softheight != 0)
	&&  ( XGC.softoutput != (char*) 0)) {
		XGC.width = XGC.softwidth;
		XGC.height = XGC.softheight;
		XGC.shadow = XGC.softoutput;
		}
	XGC.softwidth = XGC.softheight = 0;
	XGC.softoutput = (char *) 0;
	XGC.targetx= 0;
	XGC.targety= 0;
	thaw();
	return(0);		
}


public	void	restore_input_focus()
{
	if (!( XGC.displayptr))
		return;
	else if (!( GigoKstate & _GIGO_INITIAL_WINDOW_FOCUS )) {
		PixelSetInputFocus(XGC.displayptr,PointerRoot, RevertToPointerRoot,CurrentTime );
		}
	else	{
		/* ------------------------------------------------------------------ */
		/* this is not recomended by the specifications but for alliance .... */
		/* ------------------------------------------------------------------ */
		PixelSetInputFocus(XGC.displayptr,XGC.desktopwindow, RevertToPointerRoot,CurrentTime );
		}
	return;
}

public	void	release_input_focus()
{
	if (!( XGC.displayptr))
		return;
	else	{
		PixelSetInputFocus(XGC.displayptr,PointerRoot, RevertToPointerRoot,CurrentTime );
		}
	return;
}

public	void	cancel_input_focus()
{
	if (!( XGC.displayptr))
		return;
	else	{
		PixelSetInputFocus(XGC.displayptr,None, RevertToPointerRoot,CurrentTime );
		}
	return;
}

/*
 *	l i b e r a t e _ p i x e l ()
 *	
 *	performs all the necessary operations to restore a clean state
 *	and disactivation of the activated graphics.
 *
 */

public	int	liberatepixel()
{
	if ( graphical_mode != -1) {

		if ( XGC.softoutput )
			hardware();

		if ( XGC.users > 1 ) {
			XGC.users--;
			return(XGC.users);
			}

		/* Ensure that the display has been opened */
		/* --------------------------------------- */
		if ( XGC.displayptr != (Display *) NULL) {

			/* Destroy the Graphic Context */
			/* --------------------------- */
			if ( XGC.gc != (GC) NULL) {
				XFreeGC(XGC.displayptr,XGC.gc);
				XGC.gc = (GC) NULL;
				}

			/* Check for and Delete Both image and Storage */
			/* ------------------------------------------- */	
			if ( XGC.imageptr != (XImage *) NULL ) {
				if ( XGC.imageptr->data )
					XGC.imageptr->data = liberate( XGC.imageptr->data );
				XDestroyImage( XGC.imageptr );
				XGC.imageptr = (XImage *) NULL;
				XGC.storage  = (char *) 0;
				}

			/* Unmap and Destroy the eventual Window */
			/* ------------------------------------- */
			if ( XGC.desktopwindow != (Window) NULL ) {
				if (!( parentWindow )) {
					XUnmapWindow(XGC.displayptr,XGC.desktopwindow);
					XDestroyWindow(XGC.displayptr,XGC.desktopwindow);
					XGC.desktopwindow = (Window) NULL;
					}
				else 	XGC.desktopwindow = (Window) NULL;
				}	

			/* Finally Close the Display */
			/* ------------------------- */
			XCloseDisplay( XGC.displayptr );
			XGC.displayptr = (Display *) 0;

			}

		/* Check for and release Shadow Memory */
		/* ----------------------------------- */
		if ( XGC.principal != (char *) 0 ) {
			XGC.principal = liberate( XGC.principal );
			}
		if ( XGC.alternative != (char *) 0 ) {
			XGC.alternative = liberate( XGC.alternative );
			}

		/* Reset the Graphicalmode */
		/* ----------------------- */
		graphical_mode   = -1; 
		graphical_width  = -1; 
		graphical_height = -1; 
		fingigo();

		}
	return(0);
}


private	int	shift_count( unsigned int bitmask )
{
	int result=0;
	while (( (bitmask >> result) << result) == bitmask)
		result++;
	if ( result )
		result--;
	return( result );
}

static	int	inhibit_reconfig=0;
static	int	override_redirect=0;

static	void	use_overide()
{
	XSetWindowAttributes	XSWA;
	if (!( parentWindow )) {
		XSWA.override_redirect = override_redirect;
		XChangeWindowAttributes(XGC.displayptr,XGC.desktopwindow,CWOverrideRedirect,&XSWA );
		}
	return;
}

static	int	start_overide()
{
	char *	eptr;
	if (!( eptr = getenv("XFULLSCREEN") ))
		override_redirect=0;
	else if ( *eptr == '1' )
		override_redirect=1;
	else	override_redirect=0;
	return( override_redirect );
}


static	void	set_window_hints()
{
	XSizeHints XSH;
	XSH.max_width = XGC.width;
	XSH.max_height= XGC.height;
	XSH.flags = PMinSize | PMaxSize;
	if ( inhibit_reconfig ) {
		XSH.min_width = XSH.max_width;
		XSH.min_height = XSH.max_height;
		}
	else	{
		XSH.min_width = 0;
		XSH.min_height= 0;
		}
	XSetNormalHints( XGC.displayptr,XGC.desktopwindow,&XSH);
	return;
}

int	get_override() 		{	return( override_redirect);		}

void	set_override(int v)
{
	override_redirect = v;
	use_overide();
}
	
int	get_reconfiguration() 		{	return( inhibit_reconfig );		}

void	set_reconfiguration(int v)	
{	
	inhibit_reconfig=v;	
	set_window_hints();
	return;		
}

int	reconfiguration(XConfigureEvent * eptr)
{
	return( inhibit_reconfig );
}

static	int	start_reconfigure()
{
	char *	eptr;
	if (!( eptr = getenv("XINHIBITRESIZE") ))
		set_reconfiguration(0);
	else if ( *eptr == '1' )
		set_reconfiguration(1);
	else	set_reconfiguration(0);
	return( inhibit_reconfig );
}

/*
 *	c o n s o l e t y p e ()
 *	------------------------
 *
 *	Returns 1,TRUE if X11 graphics are available on this console
 *	otherwise returns 0,FALSE.
 *
 */

public	int	consoletype()
{
	char	*	gptr;

	if (console_graphics == -1) {

		/* Test for inhibition by either of the following */
		/* ---------------------------------------------- */
		if (((gptr = getenv("GRAPHOFF"))!=(char*)0)
		&&  ( *gptr == '1' )) {
			if (((gptr = getenv("PIXELTRACE")) != (char*) 0)
			&&  (*gptr == '1'))	
				printf("GraphOff=True\r\n");
			console_graphics=0;
			}

		else if (((gptr = getenv("GRAPHON"))!=(char*)0)
		     &&  ( *gptr == '0' )) {
			if (((gptr = getenv("PIXELTRACE")) != (char*) 0)
			&&  (*gptr == '1'))	
				printf("GraphOn=False\r\n");
			console_graphics=0;
			}


		/* If we cannot connect to the display then Error */
		/* ---------------------------------------------- */
		else if (!(XGC.displayptr = XOpenDisplay(XGC.display_name))) {
			if (((gptr = getenv("PIXELTRACE")) != (char*) 0)
			&&  (*gptr == '1'))	
				printf("Cannot Open X11 display\r\n");
			console_graphics=0;
			}
		else	{
			XCloseDisplay( XGC.displayptr );
			console_graphics=1;
			XGC.displayptr =(Display*)NULL;
			}
		}
	return( console_graphics );
}

public	int	get_pixel_size()	{	return( XGC.pixelsize );	}
public	int	get_pixel_format()	{	return( XGC.mapping   );	}

public	int	set_pixel_size(int v) 
{
	int	holder = XGC.pixelsize;
	XGC.pixelsize = v;
	return( holder );
}

public	int	set_pixel_format(int v)
{
	int	holder=XGC.mapping;
	XGC.mapping=v;
	return(holder);	
}


public	void	use_pixel_alternative(int refresh)
{
	char * mptr;

	while (!( mptr = XGC.alternative )) {

		/* Allocate Pixel Shadow Buffer */
		/* ---------------------------- */
		if (!( XGC.alternative = allocate( (XGC.width * XGC.height * XGC.pixelsize ) )))
			return;
		else	memset( XGC.alternative,0, (XGC.width * XGC.height * XGC.pixelsize));
		}

	XGC.shadow = mptr;

	if ( refresh )
		putzone(0,0,XGC.width,XGC.height,XGC.shadow);

	return;
}

public	void	use_pixel_primary(int refresh)
{
	char * mptr;

	while (!( mptr = XGC.principal )) {

		/* Allocate Pixel Shadow Buffer */
		/* ---------------------------- */
		if (!( XGC.principal = allocate( (XGC.width * XGC.height * XGC.pixelsize ) )))
			return;
		else	memset( XGC.principal,0, (XGC.width * XGC.height * XGC.pixelsize));
		}
	XGC.shadow = mptr;

	if ( refresh )
		putzone(0,0,XGC.width,XGC.height,XGC.shadow);

	return;
}


/*	--------------------------------------------------------------------	*/
/*		i n i t i a l i s e p i x e l ( int mode )			*/
/*	--------------------------------------------------------------------	*/
/* 	performs initialisation and activation of the X window system for	*/
/*	use by the cooperating graphical library functions.			*/
/*	the mode parameter is a vesa mode from 0 to 5 as for twin server 2.4.	*/
/*										*/
/*	--------------------------------------------------------------------	*/

public	int	initialisepixel( int mode )
{
	int	iwidth;
	int	iheight;

	switch (mode & 0x00FF) {
		case	0 :	iwidth =  320; iheight =  200; break;
		case	1 :	iwidth =  640; iheight =  400; break;
		case	2 :	iwidth =  640; iheight =  480; break;
		case	3 :	iwidth =  800; iheight =  600; break;
		case	4 :	iwidth = 1024; iheight =  768; break;
		case	5 :	iwidth = 1280; iheight = 1024; break;
		default	  :	return(-1);
		}

	if ( activatepixel( iwidth, iheight, (mode & 0xFF00) ) != -1) {
		XGC.mode = graphical_mode = (mode & 0x00FF);
		return( XGC.mode );
		}
	else	return( -1 );
}

public	void	PixelMapWindow()
{
	if (!( XGC.inhibitMap ))
	{
		XMapWindow(XGC.displayptr,XGC.desktopwindow);
	}
}

public	int	activatepixel( int iwidth, int iheight, int istyle )
{
	unsigned char buttons[16];
	int		buttcount;
	int	status=0;
	int	argc=0;
	char *	argv=(char *)0;
	int	i=0;
	int	users=0;
	int	change_state=0;
	char	*	eptr;

	if ((eptr = getenv("EXATBA")) != (char *) 0)
		set_atba( *eptr );
	else	set_atba( 0 );

	/* liberate if already activated */
	if ( graphical_mode != -1) {

		if (( istyle & 0x0700 ) > 0x0100) {
			if ( XGC.mapping )
				change_state=1;
			else	change_state=0;
			}
		else	change_state=0;

		if (!( change_state )) {
			if (( iwidth  <= graphical_width  )
			&&  ( iheight <= graphical_height )) {
				XGC.users++;
				return( XGC.mode );
				}
			}
		lock_access_controller();
		users = XGC.users;
		while ( liberatepixel() != 0);
		}

	/* establish correct mode value and set dimensions */
	/* ----------------------------------------------- */
	XGC.mode = 6; XGC.width = iwidth; XGC.height = iheight; XGC.scale = 0;

	/* Cancel Share ware offset */
	/* ------------------------ */
	XGC.targetx = XGC.targety = 0;

	/* Start Graphical Text Emulation */
	/* ------------------------------ */
	initgigo(XGC.width,XGC.height);

	unlock_access_controller();

	/* Reset Important Variables */
	/* ------------------------- */
	XGC.softwidth = XGC.softheight = 0;
	XGC.softoutput = (char *) 0;

	XGC.inhibitMap = cico_screen_inhibit();
	XGC.rightmargin   = XGC.width;
	XGC.heap	  = (struct push_control *) 0;
	XGC.viewsize      = 0;
	XGC.displayptr 	  = (Display *) 0;
	XGC.desktopwindow = (Window) 0;
	XGC.imageptr   	  = (XImage *) 0;
	XGC.gc		  = (GC) 0;
	XGC.shadow        = (char *) 0;
	XGC.principal     = (char *) 0;
	XGC.alternative   = (char *) 0;
	XGC.users 	  = 0;
	XGC.keyboardgrab  = 0;
	XGC.textcursor	  = 1;
	XGC.pixelsize 	  = 1;
	XGC.lastpalette	  = get_vga_palette();

	switch (( istyle & 0x0700 )) {
		case	0x00200	:	/* 8 bit : true colour */
		case	0x00300	:	/* 16 bit : true colour */
		case	0x00400	:	/* 32 bit : true colour */
			XGC.mapping   = 0;
			break;
		default		:
			XGC.mapping       = 1;
		}

	XGC.border=0; XGC.display_name = (char *) 0;
	XGC.display_width = XGC.display_height = 0;
	XGC.x_position = XGC.y_position = 0;
	XGC.pending    = XGC.control    = XGC.alt = XGC.altcompose = XGC.shift = 0;
	XGC.keyconfig  = 0;
	XGC.ismapped   = 0;
	XGC.trace_error_count = 0;
	

	/* Variables for the management of the new selection paste mechanisms */
	/* ------------------------------------------------------------------ */
 	XGC.pastekey	    = 666;
	XGC.ClipBoard	    = None;
	XGC.ClipBoardValue  = (unsigned char *) 0;
	XGC.PublicSelection = (unsigned char *) 0;
	XGC.ClipBoardIndex  = 0;
	XGC.ClipBoardOwner  = 0;
	XGC.ClipBoardLength = 0;
	XGC.windowflags	    = 0;

	/* Ensure output is unfrozen */
	/* ------------------------- */
	thaw();	raz_freeze();

	/* set pixel characteristics */
	/* ------------------------- */
	XGC.depth = 255; XGC.bpp = 8; 
	XGC.desktopname = displayname;
	XGC.desktopicon = displayicon;

	/* We've connected to the Screen and must protect ourselves now */
	/* ------------------------------------------------------------ */
	graphical_mode = XGC.mode;
	graphical_width = XGC.width;
	graphical_height = XGC.height;

	/* Reset Pressed Key controller */
	/* ---------------------------- */
	for (i = 0; i < 256; i++) XGC.modifierPressed[i] = False;

	XGC.leftbutton = XGC.rightbutton = XGC.middlebutton = XGC.upwheel = XGC.downwheel = 0;

	/* Allocate Pixel Shadow Buffer */
	/* ---------------------------- */
/*	if ( XGC.mapping ) { use_pixel_primary(0); }	*/

	/* Test for Graphical Screen Available */
	/* ----------------------------------- */
	if ( consoletype() > 0 ) {

		/* If we cannot connect to the display then Error */
		/* ---------------------------------------------- */
		if (!(XGC.displayptr = XOpenDisplay(XGC.display_name))) {
			fingigo();
			return(-1);
			}

		/* Install these Now */
		/* ----------------- */
		xgr_error_handlers();

		/* Collect Display Pointer Mapping Information */
		/* ------------------------------------------- */
		if ((buttcount = XGetPointerMapping( XGC.displayptr, buttons, 8 )) > 0) {
			XGC.leftbutton = buttons[0];
			if ( buttcount > 1 ) {
				if ( buttcount > 2 ) {
					XGC.rightbutton= buttons[2];
					XGC.middlebutton= buttons[1];
					if( buttcount > 3 ) {
						XGC.upwheel = buttons[3];
						if ( buttcount > 4 )
							XGC.downwheel = buttons[4];
						}
					}
				else	XGC.rightbutton = buttons[1];

				}
			}

		/* Otherwise collect the default Display Information */
		/* ------------------------------------------------- */
		XGC.screen  		= DefaultScreen(XGC.displayptr);
		XGC.display_width	= DisplayWidth(XGC.displayptr,XGC.screen);
		XGC.display_height	= DisplayHeight(XGC.displayptr,XGC.screen);

		if (( XGC.display_width  > XGC.width )
		||  ( XGC.display_height > XGC.height )) {
			XGC.x_position = ((XGC.display_width-XGC.width)/2);
			XGC.y_position = ((XGC.display_height-XGC.height)/2);
			}
		else	{
			XGC.x_position = XGC.y_position = 0;
			}

		/* Interogate and Calculate Colour Depth and Pixel Formats */
		/* ------------------------------------------------------- */
		XGC.vis 	= DefaultVisual(XGC.displayptr,XGC.screen);
		XGC.visdepth 	= DefaultDepth(XGC.displayptr,XGC.screen);
		XGC.visbpp 	= GetBPPForDepth(XGC.visdepth);
		XGC.cmap 	= DefaultColormap(XGC.displayptr,XGC.screen);

		XGC.redshift   = shift_count(XGC.vis->red_mask   );
		XGC.greenshift = shift_count(XGC.vis->green_mask );
		XGC.blueshift  = shift_count(XGC.vis->blue_mask  );

		/* Allocate Pixel Shadow Buffer */
		/* ---------------------------- */
		if (!( XGC.mapping )) {
			switch ( XGC.visbpp ) {
				case	8  :	XGC.pixelsize = 1; break;
				case	16 :	XGC.pixelsize = 2; break;
				case	32 :	XGC.pixelsize = 4; break;
				default	   :	XGC.pixelsize = 1; break;
				}
			/* use_pixel_primary(0); */
			}

		if ( start_overide() ) {

			XGC.x_position = XGC.y_position = 0;
			XGC.width = XGC.display_width;
			XGC.height = XGC.display_height;
			graphical_width = XGC.width;
			graphical_height = XGC.height;
			initgigosize(XGC.width,XGC.height);

			}

		use_pixel_primary(0);

		/* Create our Desk Top Window */
		/* -------------------------- */
		if (!( parentWindow )) {
			if ( GigoXtrace ) {
				printf("Creating Simple Window ( pid=%u, w=%u, h=%u )\r\n",getpid(),XGC.width,XGC.height);
				}
			XGC.desktopwindow = XCreateSimpleWindow(
				XGC.displayptr, RootWindow(XGC.displayptr,XGC.screen),
				XGC.x_position,XGC.y_position, XGC.width, XGC.height,
				XGC.border,
				BlackPixel(XGC.displayptr,XGC.screen),
				WhitePixel(XGC.displayptr,XGC.screen)  );
			}
		else	{
			if ( GigoXtrace ) {
				printf("Reusing Parent Window ( pid=%u, window=%u )\r\n",getpid(),parentWindow);
				}
			XGC.desktopwindow = XCreateSimpleWindow(
				XGC.displayptr, parentWindow,
				(XGC.x_position=0),(XGC.y_position=0), XGC.width, XGC.height,
				XGC.border,
				BlackPixel(XGC.displayptr,XGC.screen),
				WhitePixel(XGC.displayptr,XGC.screen)  );
			parentWindow = 0;
			}
		XGC.standardcursor  = XCreateFontCursor(XGC.displayptr,XC_top_left_arrow);
		XGC.waitingcursor   = XCreateFontCursor(XGC.displayptr,XC_watch);
		XGC.problemcursor   = XCreateFontCursor(XGC.displayptr,XC_spider);
		XGC.alternatecursor = XCreateFontCursor(XGC.displayptr,XC_hand2);

		use_overide();

		if (!( parentWindow )) {
			XDefineCursor(XGC.displayptr,XGC.desktopwindow,XGC.standardcursor);
			}

		/* Establish Window Manager Protocol to Avoid X button delete */
		/* ---------------------------------------------------------- */
		XGC.WmProtocols = XInternAtom(XGC.displayptr,(_Xconst char *) "WM_PROTOCOLS",0 );
		XGC.WmDelete 	= XInternAtom(XGC.displayptr,(_Xconst char *) "WM_DELETE_WINDOW",0 );
		XGC.ClipBoard 	= XInternAtom(XGC.displayptr,(_Xconst char *) "GIGO_CLIPBOARD",0 );

		if (!( parentWindow )) {
			XSetWMProtocols( XGC.displayptr,
					 XGC.desktopwindow,
					 &XGC.WmDelete,
					 1);
			start_reconfigure();
			XStringListToTextProperty( &XGC.desktopname, 1, &XGC.windowName );
			XStringListToTextProperty( &XGC.desktopicon, 1, &XGC.iconName   );
			ClassHints.res_name  = XGC.desktopicon;
			ClassHints.res_class = XGC.desktopicon;
			XSetWMProperties(
				XGC.displayptr,XGC.desktopwindow,
				&XGC.windowName, &XGC.iconName,
				(void *) 0, 0, (void *) 0, (void *) 0, &ClassHints );


			}

		XGC.imageptr = XCreateImage(XGC.displayptr, XGC.vis, XGC.visdepth, ZPixmap, 0, NULL,
				 XGC.width, XGC.height,
				 BitmapPad(XGC.displayptr), 0);

		XGC.imageptr->byte_order = LSBFirst;

		/* Allocate Desktop Image Data Storage Zone */
		/* ---------------------------------------- */
		if (!(XGC.imageptr->data = allocate((XGC.viewsize = (XGC.imageptr->bytes_per_line * XGC.imageptr->height))))) {
			liberatepixel();
			return(-1);
			}
	
		else	XGC.storage = XGC.imageptr->data;

		/* Allow Event Reception for this Window */
		/* ------------------------------------- */
		set_standard_events();

		XGC.gc = XCreateGC(XGC.displayptr,XGC.desktopwindow,0,NULL);

		if (!( parentWindow )) {
			PixelMapWindow();
			}

		if (!( GigoKstate & _GIGO_INITIAL_WINDOW_FOCUS )) {
			PixelSetInputFocus(XGC.displayptr,PointerRoot, RevertToPointerRoot,CurrentTime );
			}
		else	{
			/* ------------------------------------------------------------------ */
			/* this is not recomended by the specifications but for alliance .... */
			/* ------------------------------------------------------------------ */
			PixelSetInputFocus(XGC.displayptr,XGC.desktopwindow, RevertToPointerRoot,CurrentTime );
			}

		/* Allow Event Manager to Work Now */
		/* ------------------------------- */
		(void) test_event();

		/* Check for screen image to be preserved */
		/* -------------------------------------- */
		check_autopop();

		}
	else	{

		/* ---------------------------- */
		/* No graphics possible		*/
		/* ---------------------------- */
		/* Allocate Pixel Shadow Buffer */
		/* ---------------------------- */
		use_pixel_primary(0);
		}


	standard_image_quality( get_pixel_size(), get_pixel_format() );

	/* indicate success by returning the current mode */
	/* ---------------------------------------------- */
	XGC.users++;	XGC.users += users;
	return(  XGC.mode );
}

public	void 	outzone(int x, int y, int width, int height )
{
	if (!( XGC.outputfrozen )) {

		if (!( XGC.targetx )) {
			ClipCoordinates( x,y,width,height,"outzone" );
			}
		else	{
			ClipTargetCoordinates( x,y,width,height,"outzone" );
			}

		if ( XGC.displayptr ) {
			if ( GigoXtrace & 256 ) {
				printf("XPutImage(%u,%u,%u,%u)\r\n",x,y,width,height);
				}
			XPutImage(	XGC.displayptr, 
					XGC.desktopwindow, 
					XGC.gc, 
					XGC.imageptr, 
					x, y, 
					x, y, width, height );
			}

		thaw();
		}
	else	integrate(x,y,width,height);
	return;
}

public	int	hardrows()
{
	if ( graphical_mode != -1) 
		return( XGC.height );
	else	return(0);
}

public	int	hardcolumns()
{
	if ( graphical_mode != -1) 
		return( XGC.width );
	else	return(0);
}

int	vgapalette(char * pptr, int start, int finish )
{
	int	i;

	int	r,g,b;
	int	rs=0,gs=0,bs=0;
	char *	gptr;
	rs = XGC.redshift;
	gs = XGC.greenshift;
	bs = XGC.blueshift;

	XGC.lastpalette = pptr;

	if (((gptr = getenv("PIXELTRACE")) != (char*) 0) &&  (*gptr == '1')) {
		printf("X11 : XGC.visbpp %u \r\n",XGC.visbpp );
		printf("X11 : XGC.red    %u, XGC.green %u, XGC.blue %u\r\n",rs,gs,bs);
		}

	for (	i=start;
		i<finish;
		i++ ) {
		r = (*(pptr + (i*4)+0)&0x00FF);
		g = (*(pptr + (i*4)+1)&0x00FF);
		b = (*(pptr + (i*4)+2)&0x00FF);
		switch ( XGC.visbpp ) {
			case	8 	:
			bRgbTable[i] = (
				(((r&0xE0)>>5)<<rs) |
				(((g&0xE0)>>5)<<gs) | 
				(((b & 0xC0)>>6)<<bs)	);
				continue;
			case	16	:
				wRgbTable[i] =  (((((r&0x0F8)>>3)<<rs) | (((g&0x0FC)>>2)<<gs)| (((b & 0x0F8)>>3)<<bs)) & 0xFFFF);
				continue;
			case	32	:
				lRgbTable[i] =  (((r&0x0FF)<<rs) | ((g&0x0FF)<<gs)| ((b & 0x0FF)<<bs));
				continue;
			}
		}
	return(0);

}

public	int	pixel_to_rgb( int pixel, int *r, int *g, int *b )
{
	unsigned long	v=0L;

	switch ( XGC.visbpp ) {

		case	8	:
			if ((v = (pixel & 0x00FF)) == 0x00FF)
				*r = *g = *b = 0x00FF;
			else	{
				*r = 	(((v >> XGC.redshift) << 5) & 0x0E0);
				*g = 	(((v >> XGC.greenshift) << 5) & 0x0E0);
				*b = 	(((v >> XGC.blueshift) << 6) & 0x0C0);
				}
			break;

		case	16	:
			if ((v = (pixel & 0xFFFF)) == 0xFFFF)
				*r = *g = *b = 0x00FF;
			else	{
				*r = 	(((v >> XGC.redshift) << 3) & 0x0F8);
				*g = 	(((v >> XGC.greenshift) << 2) & 0x0FC);
				*b = 	(((v >> XGC.blueshift) << 3) & 0x0F8);
				}
			break;

		case	24	:
		case	32	:
			v = (pixel & 0x00FFFFFF);
			*r = 	((v >> XGC.redshift) & 0x0FF);
			*g = 	((v >> XGC.greenshift) & 0x0FF);
			*b = 	((v >> XGC.blueshift)  & 0x0FF);
			break;

		}

	return( XGC.pixelsize );
}



public	int	get_logical_pixel( void * vptr, int *r, int *g, int *b )
{
	unsigned short 	* wptr;
	unsigned char 	* bptr;
	unsigned long 	* lptr;
	unsigned long	v=0L;

	switch ( XGC.visbpp ) {

		case	8	:
			bptr = (unsigned char *) vptr;
			if ((v = (*bptr & 0x00FF)) == 0x00FF)
				*r = *g = *b = 0x00FF;
			else	{
				*r = 	(((v >> XGC.redshift) << 5) & 0x0E0);
				*g = 	(((v >> XGC.greenshift) << 5) & 0x0E0);
				*b = 	(((v >> XGC.blueshift) << 6) & 0x0C0);
				}
			break;

		case	16	:
#ifdef	AIX
			bptr = (unsigned char *) vptr;
			v = (*(bptr++) & 0X00FF);
			v |= ((*(bptr++) & 0X00FF) << 8);
			*r = 	(((v >> XGC.redshift) << 3) & 0x0F8);
			*g = 	(((v >> XGC.greenshift) << 2) & 0x0FC);
			*b = 	(((v >> XGC.blueshift) << 3) & 0x0F8);

#else
			wptr = (unsigned short *) vptr;
			if ((v = (*wptr & 0xFFFF)) == 0xFFFF)
				*r = *g = *b = 0x00FF;
			else	{
				*r = 	(((v >> XGC.redshift) << 3) & 0x0F8);
				*g = 	(((v >> XGC.greenshift) << 2) & 0x0FC);
				*b = 	(((v >> XGC.blueshift) << 3) & 0x0F8);
				}
#endif
			break;

		case	32	:
#ifdef	AIX
			bptr = (unsigned char *) vptr;
			v = (*(bptr++) & 0X00FF);
			v |= ((*(bptr++) & 0X00FF) << 8);
			v |= ((*(bptr++) & 0X00FF) << 16);
			v |= ((*(bptr++) & 0X00FF) << 24);
#else
			lptr = (unsigned long *) vptr;
			v = (*lptr & 0x00FFFFFF);
#endif
			*r = 	((v >> XGC.redshift) & 0x0FF);
			*g = 	((v >> XGC.greenshift) & 0x0FF);
			*b = 	((v >> XGC.blueshift)  & 0x0FF);
			break;

		case	24	:
			bptr = (unsigned char *) vptr;
			*r	= (*bptr & 0x00FF);
			*g	= (*(bptr+1) & 0x00FF);
			*b	= (*(bptr+2) & 0x00FF);
			break;
		}

	return( XGC.pixelsize );
}

public	unsigned long	get_rgb_pixel( int r, int g, int b )
{
	unsigned char	c=0;
	unsigned short	s=0;	
	unsigned long	l=0;

	switch ( XGC.visbpp ) {
		case	8	:
			c =    (((r&0xE0)>>5)<<XGC.redshift) | 
				(((g&0xE0)>>5)<<XGC.greenshift) | 
				(((b & 0xC0)>>6)<<XGC.blueshift);
			return((unsigned long) (0x80000000 | (c & 0x0000FF)) );

		case	16	:
			s  = (((((r&0x0F8)>>3)<<XGC.redshift) |
				(((g&0x0FC)>>2)<<XGC.greenshift) |
				(((b & 0x0F8)>>3)<<XGC.blueshift)) & 0xFFFF);
			return((unsigned long)  (0x80000000 | (s & 0x00FFFF)) );

		case	32	:
			l = (((r&0x0FF)<<XGC.redshift) | ((g&0x0FF)<<XGC.greenshift)| ((b & 0x0FF)<<XGC.blueshift));
			return((unsigned long)  (0x80000000 | (l & 0x00FFFFFF)) );

		case	24	:
			l = (((r&0x0FF)<<XGC.redshift) | ((g&0x0FF)<<XGC.greenshift)| ((b & 0x0FF)<<XGC.blueshift));
			return((unsigned long)  (0x80000000 | (l & 0x00FFFFFF)) );

		default		:
			return((unsigned long)  0 );
		}
}

public	int	make_rgb_pixel( int r, int g, int b )
{
	char * pptr;
	int	p=255;
	if (( pptr = XGC.lastpalette ) != (char *) 0) {
		*( pptr + (255 *4)) = r;
		*( pptr + (255 *4)+1) = g;
		*( pptr + (255 *4)+2) = b;
		}
	switch ( XGC.visbpp ) {
		case	8	: 
			bRgbTable[(p & 0x00FF)] = get_rgb_pixel(r,g,b); break;
		case	16	:
			wRgbTable[(p & 0x00FF)] = get_rgb_pixel(r,g,b); break;
		case	24	:
		case	32	:
			lRgbTable[(p & 0x00FF)] = get_rgb_pixel(r,g,b); break;
		}
	return(p);
}

public	int	put_logical_pixel( void * vptr, int r, int g, int b )
{
	unsigned short 	* wptr;
	unsigned char 	* bptr;
	unsigned long 	* lptr;
#ifdef	AIX
	unsigned short	s=0;	
	unsigned long	l=0;
#endif
	switch ( XGC.visbpp ) {

		case	8	:
			bptr = (unsigned char *) vptr;
			*bptr = (((r&0xE0)>>5)<<XGC.redshift) | 
				(((g&0xE0)>>5)<<XGC.greenshift) | 
				(((b & 0xC0)>>6)<<XGC.blueshift);
			break;

		case	16	:
#ifdef	AIX
			s  = (((((r&0x0F8)>>3)<<XGC.redshift) |
				(((g&0x0FC)>>2)<<XGC.greenshift) |
				(((b & 0x0F8)>>3)<<XGC.blueshift)) & 0xFFFF);
			bptr = (unsigned char *) vptr;
			*(bptr++) = (s & 0x00FF);
			*(bptr++) = ((s>>8) & 0x00FF);
#else
			wptr = (unsigned short *) vptr;
			*wptr = (((((r&0x0F8)>>3)<<XGC.redshift) |
				(((g&0x0FC)>>2)<<XGC.greenshift) |
				(((b & 0x0F8)>>3)<<XGC.blueshift)) & 0xFFFF);
#endif
			break;

		case	32	:
#ifdef	AIX
			l = (((r&0x0FF)<<XGC.redshift) | ((g&0x0FF)<<XGC.greenshift)| ((b & 0x0FF)<<XGC.blueshift));
			bptr = (unsigned char *) vptr;
			*(bptr++) = (l       & 0x00FF);
			*(bptr++) = ((l>>8 ) & 0x00FF);
			*(bptr++) = ((l>>16) & 0x00FF);
			*(bptr++) = ((l>>24) & 0x00FF);
#else		
			lptr = (unsigned long *) vptr;
			*lptr = (((r&0x0FF)<<XGC.redshift) | ((g&0x0FF)<<XGC.greenshift)| ((b & 0x0FF)<<XGC.blueshift));
#endif
			break;

		case	24	:
			bptr = (unsigned char *) vptr;
			*bptr     = (r & 0x00FF);
			*(bptr+1) = (g & 0x00FF);
			*(bptr+2) = (b & 0x00FF);

		}

	return( XGC.pixelsize );
}

public	void	put_palette_pixel( void * vptr, int v )
{
	char * pptr;
	if (!( pptr = XGC.lastpalette ))
		return;
	else	{
		pptr += ((v & 0x00FF) * 4);
		put_logical_pixel(vptr,(*pptr & 0x00FF),(*(pptr+1) & 0x00FF),(*(pptr+2) & 0x00FF));
		return;
		}
}

public	int	get_palette_pixel( int v )
{
	int	r=0;
	char * pptr;

	if (!( XGC.mapping )) {
		switch ( XGC.pixelsize ) {
			case	1 : r = bRgbTable[(v & 0x00FF)]; break;
			case	2 : r = wRgbTable[(v & 0x00FF)]; break;
			case	3 :
			case	4 : r = lRgbTable[(v & 0x00FF)]; break;
			}
		}
	else	r = (v & 0x00FF);
	return( r );
}

public	int	get_physical_pixel(char * sptr,int x)
{
	int	v;
	
	if (!( XGC.mapping )) {
		sptr += (x * XGC.pixelsize);
		switch ( XGC.pixelsize ) {
			case	1	:
				v = (*sptr & 0x00FF);
				break;
			case	2	:
				v = ( (*sptr & 0x00FF)
				  | ( (*(sptr+1) & 0x00FF) << 8));
				break;
			case	3	:
			case	4	:
				v = ( (*sptr & 0x00FF)
				  | ( (*(sptr+1) & 0x00FF) << 8)
				  | ( (*(sptr+2) & 0x00FF) << 16));
				break;
			}
		}
	else	v = (*(sptr+x) & 0x00FF);
	return( v );
}

public	void	put_physical_pixel( unsigned char * vptr, int p )
{
	int	v;
	
	if (!( XGC.mapping )) {
		switch ( XGC.pixelsize ) {
			case	3	:
			case	4	: *(vptr+2) = ((p & 0x00FF0000) >> 16);
			case	2	: *(vptr+1) = ((p & 0x00FF00) >> 8);
			case	1	: *vptr = (p & 0x00FF);
			}
		}
	else	*vptr = ( p & 0x00FF);
	return;
}

int	hide()
{
	XGC.outputfrozen++;
	if ( GigoXtrace & 256 ) {
		printf("hide : frozen=%u\r\n",XGC.outputfrozen);
		}
	return(XGC.outputfrozen);
}

int	hidecount()	{	return( XGC.outputfrozen ); 	}

int	push_freeze()
{
	if (!( XGC.pushed )) {
		XGC.pushed++;
		XGC.hold_of = XGC.outputfrozen;
		XGC.hold_tx = XGC.topx;
		XGC.hold_ty = XGC.topy;
		XGC.hold_ex = XGC.endx;
		XGC.hold_ey = XGC.endy;
		thaw();
		return(1);
		}
	else	return(0);
}

int	raz_freeze()
{
	XGC.pushed  = 0;
	XGC.hold_of = 0;
	XGC.hold_tx = 0;
	XGC.hold_ty = 0;
	XGC.hold_ex = 0;
	XGC.hold_ey = 0;
	return;
}

int	pop_freeze()
{
	if ( XGC.pushed ) {
		XGC.outputfrozen = XGC.hold_of;
		XGC.topx = XGC.hold_tx;
		XGC.topy = XGC.hold_ty;
		XGC.endx = XGC.hold_ex;
		XGC.endy = XGC.hold_ey;
		raz_freeze();
		return(1);
		}
	else	return(0);
}


int	show(int x,int y, int nbx, int nby)
{
	if ( GigoXtrace & 256 ) {
		printf("show(%u,%u,%u,%u) frozen=%u\r\n",x,y,nbx,nby,XGC.outputfrozen);
		}
	if (!( XGC.outputfrozen )) {
		if ((nbx!=0)&& (nby!= 0))
			outzone(x,y,nbx,nby);
		else	outzone(XGC.topx,XGC.topy,(XGC.endx-XGC.topx),(XGC.endy-XGC.topy));
		}
	else	{
		XGC.outputfrozen--;
		if (!( XGC.outputfrozen ))
			outzone(XGC.topx,XGC.topy,(XGC.endx-XGC.topx),(XGC.endy-XGC.topy));
		}
	return(XGC.outputfrozen);
}

int	perform_low_level_flush()
{
	if ( XGC.outputfrozen )
		return(XGC.outputfrozen);
	if (( XGC.endx > XGC.topx )
	||  ( XGC.endy > XGC.topy )) {
		outzone(XGC.topx,XGC.topy,(XGC.endx-XGC.topx),(XGC.endy-XGC.topy));
		if ( XGC.displayptr ) {
			XFlush(XGC.displayptr);
			}
		}
	return(0);
}

int	flush()
{
	if ( GigoXtrace & 256 ) {
		printf("flush : frozen=%u\r\n",XGC.outputfrozen);
		}
	if ( XGC.outputfrozen )
		XGC.outputfrozen--;
	return( perform_low_level_flush() );
}

int	userware(int w, int h,char * buffer )	
{
	if (( w != 0)
	&&  ( h != 0)
	&&  ( buffer != (char *) 0)) {
		hardware();
		XGC.softwidth  = XGC.width;
		XGC.softheight = XGC.height;
		XGC.softoutput = XGC.shadow;
		XGC.width  = w;
		XGC.height = h;
		XGC.targetx= 0;
		XGC.targety= 0;
		XGC.shadow = buffer;
		}
	return(0);		
}

int	moveware(int x, int y)
{
	if (( XGC.softoutput != (char *) 0) && ( XGC.targetx != 0 )) {
		XGC.targetx = (x+1);
		XGC.targety = (y+1);
		}
	return(0);
}

int	pushware(struct	standard_buffer * iptr )
{
	if (!( iptr ))
		return(0);
	else	{
		iptr->columns = iptr->rows = 0;
		iptr->storage = (void *) 0;
		if (!(iptr->storage = XGC.softoutput)) {
			iptr->columns = iptr->rows = 0;
			return(0);
			}
		else	{
			iptr->columns = XGC.softwidth;
			iptr->rows = XGC.softheight;
			return(1);
			}
		}
}

int	shareware(int w, int h, int x, int y, char * buffer )	
{
	if (( w != 0)
	&&  ( h != 0)
	&&  ( buffer != (char *) 0)) {
		hardware();
		XGC.softwidth  = XGC.width;
		XGC.softheight = XGC.height;
		XGC.softoutput = XGC.shadow;
		XGC.width  = w;
		XGC.height = h;
		XGC.targetx= (x+1);
		XGC.targety= (y+1);
		XGC.shadow = buffer;
		}
	return(0);		
}

int	calcbuff()		{	return(0);		}
int	calczone()		{	return(0);		}
void *	share_psu(int process,void * aptr,void * bptr, void * cptr)	{	return((void *) 0); 	}
void *	check_psu(void * p)	{	return(p );		}


public	void	xgr_push_view()
{
	struct	push_control * pptr;
	char *	buffers[10];
	int	buflens[10];
	int	items=0;
	int	fg=0;
	int	bg=0;
	int	atc=1;
	int	atl=1;
	int	poptions = get_pushpoptions();

	get_gigo_tab(&atc,&atl);
	get_gigo_colours(&fg,&bg);

	buffers[items]  = XGC.shadow;			/* was imageptr->data 	*/
	buflens[items++]= (XGC.width*XGC.height*XGC.pixelsize);	/* XGC.viewsize		*/
	if (!( poptions & _INHIBIT_PUSH_POSITION )) {
		buffers[items] = &atl;
		buflens[items++] = sizeof( atl );
		buffers[items] = &atc;
		buflens[items++] = sizeof( atc );
		}
	if (!( poptions & _INHIBIT_PUSH_COLOUR )) {
		buffers[items] = &fg;
		buflens[items++] = sizeof( fg );
		buffers[items] = &bg;
		buflens[items++] = sizeof( bg );
		}
	buffers[items] = XGC.lastpalette;
	buflens[items++] = 4*256;

	if (!( co_push_to_file( items, buffers, buflens ) )) {
		if ((pptr = (struct push_control *) allocate( sizeof( struct push_control ) + XGC.viewsize )) != (struct push_control *) 0) {
			pptr->next = XGC.heap;
			XGC.heap  = pptr;
			if ( XGC.shadow ) {
				memcpy(pptr->buffer,XGC.shadow,(XGC.width*XGC.height));
				}
			}

		}
	return;
}

public	void	xgr_pop_view()
{
	struct	push_control * pptr;

	char *	buffers[10];
	int	buflens[10];
	int	items=0;
	int	fg=0;
	int	bg=0;
	int	atc=1;
	int	atl=1;
	int	poptions = get_pushpoptions();
	get_gigo_tab(&atc,&atl);
	get_gigo_colours(&fg,&bg);
	buffers[items] = XGC.lastpalette;
	buflens[items++] = 4*256;
	if (!( poptions & _INHIBIT_PUSH_COLOUR )) {
		buffers[items] = &bg;
		buflens[items++] = sizeof( bg );
		buffers[items] = &fg;
		buflens[items++] = sizeof( bg );
		}
	if (!( poptions & _INHIBIT_PUSH_POSITION )) {
		buffers[items] = &atc;
		buflens[items++] = sizeof( atc );
		buffers[items] = &atl;
		buflens[items++] = sizeof( atl );
		}
	buffers[items]  = XGC.shadow;			/* was imageptr->data 	*/
	buflens[items++]= (XGC.width*XGC.height*XGC.pixelsize);	/* XGC.viewsize		*/

	if ( co_pop_from_file( items, buffers, buflens ) ) {
		vgapalette(XGC.lastpalette,0,256);
		set_gigo_colours(fg,bg);
		set_gigo_tab(atc,atl);
		putzone(0,0,XGC.width,XGC.height,XGC.shadow);
		}
	else	{
		if ((pptr = XGC.heap) != (struct push_control *) 0) {
			XGC.heap = pptr->next;
			if ( XGC.shadow ){
				memcpy(XGC.shadow,pptr->buffer,(XGC.width*XGC.height));
				}
			pptr = liberate( pptr );
			putzone(0,0,XGC.width,XGC.height,XGC.shadow);
			}
		}

	return;
}

public	void	xgr_bell()
{
	if ( XGC.displayptr ) {
		XBell( XGC.displayptr, 100 );
		}
	return;
}


#endif	/* _inipixel_c */


