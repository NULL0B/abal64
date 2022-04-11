#ifndef _stdevent_c
#define _stdevent_c

#include "pixel.h"
#include "guimouse.h"
#include "stdctrl.h"
#include "stdevent.h"

#define	VISUAL_CLIPBOARD	1
#define	MAX_PENDING_EVENTS	1024

private	int	pending_events[MAX_PENDING_EVENTS];
private	int	next_read_event=0;
private	int	next_write_event=0;
private	int	UnGotKeyCode=-1;
private	int	ecounter=0;

#define	GIGOXTRACE
#ifdef	GIGOXTRACE
int	GigoXtrace=0;
#endif

/*	-------------------	*/
/*	Required Prototypes	*/
/*	-------------------	*/
extern	int	panic(int);
extern	Window	parentWindow;
private	int	request_clipboard();
private	int	toggle_keyboard_grab();

#include "stdkbf.c"
#include "xkeysym.c"

public	int	on_system( int state )
{
	if ( state )
		GigoKstate |= _GIGO_SUSPEND_FOCUS;	/*   256 */
	else	GigoKstate &= ~_GIGO_SUSPEND_FOCUS;	/* ! 256 */
	return(GigoKstate);
}
		

/*	----------------------------------------------	*/
/*		o n _ r e f r e s h ()			*/
/*		----------------------			*/
/*	This function is called in response to the	*/
/*	reception of an Expose or GraphicsExpose	*/
/*	event requiring a section of the application	*/
/*	screen to be redrawn to the output window.	*/
/*	----------------------------------------------	*/

private	void	on_refresh( int x, int y, int w , int h )
{
	int	nesting = XGC.outputfrozen;
	outzone(x,y,w,h);
	flush();
	XGC.outputfrozen = nesting;
	return;
}

private	int	resize_request_handler( XResizeRequestEvent * rat ) 
{
	if ( rat->width > XGC.width )
		rat->width = XGC.width;
	if ( rat->height > XGC.height )
		rat->height = XGC.height;
	if (!( reconfiguration() )) {
#ifdef	GIGOXTRACE
		if ( GigoXtrace & 512 ) { 
			printf("stdevent::XResizeWindow(%u,%u)\r\n",rat->width,rat->height);
			}
#endif
		XResizeWindow( XGC.displayptr, XGC.desktopwindow, rat->width, rat->height );
		}
	return(1);

}

private	int	client_message_handler( XClientMessageEvent * rat ) 
{
	if ( rat->message_type == XGC.WmProtocols ) {
		if (!( XGC.windowflags & 1 )) {
			if (!( XGC.windowflags & 2 )) {
				return(panic(SIGTERM));
				}
			else	{
				return(0);
				}
			}
		else	{
			return(1);
			}
		}
	else	return(1);
}

/* -------------------------------------------------------------------- */
/*									*/
/*		r e l e a s e _ s e l e c t i o n (         )		*/
/*		---------------------------------------------		*/
/*									*/
/*	This function is called whenever a published selection is	*/
/*	to be deleted, either prior to redefining another public	*/
/*	selection or due to its definition be another external		*/
/*	application on reception of a SelectionClear event.		*/
/*									*/
/* -------------------------------------------------------------------- */

public	void	release_public_selection()
{
	if ( XGC.PublicSelection ) {
		liberate( XGC.PublicSelection );
		XGC.PublicSelection = (char *) 0;
		}
	return;
}

/* -------------------------------------------------------------------- */
/*									*/
/*		p u b l i s h _ s e l e c t i o n ( message )		*/
/*		---------------------------------------------		*/
/*									*/
/*	This function will be called by applications requiring a	*/
/*	text selection to be made available to other applications	*/
/*	via the standard clipboard or selection mechansisms of X11.	*/
/*									*/
/* -------------------------------------------------------------------- */

public	void	publish_selection( char * mptr, int mlen )
{
	int	status;
	int	i;
	release_public_selection();

	if (!( mptr ))
		return;
	else if (!( XGC.PublicSelection = allocate( (mlen + 1) )))
		return;
	else	{

		for (i=0; i < mlen; i++ )
			*(XGC.PublicSelection+i) = *(mptr+i);

		*(XGC.PublicSelection+mlen) = 0;

		status = XSetSelectionOwner( XGC.displayptr, XA_PRIMARY, XGC.desktopwindow, CurrentTime );

		/* ensure that we are the actual owner */
		/* ----------------------------------- */
		if ( XGetSelectionOwner( XGC.displayptr, XA_PRIMARY ) != XGC.desktopwindow )
			release_public_selection();

		return;
		}
}

/* -------------------------------------------------------------------- */
/*									*/
/*		h a n d l e _ s e l e c t i o n _ r e q u e s t ()	*/
/*		--------------------------------------------------	*/
/*									*/
/*	This function is called upon receipt of a SelectionRequest	*/
/*	event from a client application requiring a copy of the 	*/
/*	selection data.							*/
/*									*/
/* -------------------------------------------------------------------- */

private	void	handle_selection_request()
{
	int			 status;
	XSelectionRequestEvent * request = (XSelectionRequestEvent*) &XGC.event;
	XSelectionEvent		 response;

	/* Determine the appropriate response */
	/* ---------------------------------- */ 
	if (!( XGC.PublicSelection ))
		response.property = None;
	else if ( request->selection != XA_PRIMARY )
		response.property = None;
	else	{
		switch ( request->target ) {
			case	XA_STRING	:
	
				if ((status = XChangeProperty( 
					XGC.displayptr, 
					request->requestor, 
					request->property, 
					XA_STRING, 8, PropModeReplace,
					XGC.PublicSelection, strlen( XGC.PublicSelection ))) != Success ) {
#ifdef	GIGOXTRACE
					if ( GigoXtrace & 32 ) { printf("XChangeProperty(NotSuccess)\r\n"); }
#endif
					response.property = request->property;
					}
				else	{
					response.property = request->property;
					}
				break;

			default			:
				response.property = None;
				break;
			}
		}

	/* Duplicate the relevant Request Fields */
	/* ------------------------------------- */
	response.type	= SelectionNotify;
	response.serial	= request->serial;
	response.time 	= time((long *) 0); /* request->time; */
	response.selection= request->selection;
	response.target	= request->target;
	response.requestor= request->requestor;
	response.display  = XGC.displayptr;
	
	/* Inform Client of Response */
	/* ------------------------- */
	status = XSendEvent( request->display, request->requestor, True, 0, & response );
	return;
}


/*		------------------------------------			*/
/*		r e q u e s t _ c l i p b o a r d ()			*/
/*		------------------------------------			*/
/*		Called whenever the current clipboard			*/
/*		contents are to be released.				*/
/*		------------------------------------			*/

private	void	drop_clipboard( ) 
{
	if ( XGC.ClipBoardValue ) {
		if ( XGC.ClipBoardOwner != XGC.desktopwindow ) {
			XFree( XGC.ClipBoardValue );
			}
		XGC.ClipBoardValue = (unsigned char *) 0;
		XGC.ClipBoardIndex = XGC.ClipBoardLength = 0;
		XGC.ClipBoardOwner = 0;
		}
	return;
}

/*		------------------------------------			*/
/*		c o n s u m e _ c l i p b o a r d ()			*/
/*		------------------------------------			*/
/*									*/
/*	This function  removes and returns 1 byte from the clipboard	*/

private	int	consume_clipboard()
{
	int	KeyCode=0;
	if ((KeyCode = *(XGC.ClipBoardValue+(XGC.ClipBoardIndex++))) == '\n')
		KeyCode = '\r';
	if ( XGC.ClipBoardIndex == XGC.ClipBoardLength ) {
		drop_clipboard();
		}
	return( KeyCode );
}


/*		------------------------------------			*/
/*		r e q u e s t _ c l i p b o a r d ()			*/
/*		------------------------------------			*/
/*									*/
/*	This function is activated in response to a paste event 	*/
/*	being detected in either the keyboard or pointer stream		*/
/*	and will attempt to recover a published selection from		*/
/*	another process aznd make it available as the standard		*/
/*	input. Unix NL will be converted to CR				*/
/*									*/
/*		------------------------------------			*/
private	int	request_clipboard()
{
	Window	W;
	int	status;

	XKeyEvent * k = (XKeyEvent *)&XGC.event;

	if ((W = XGetSelectionOwner( XGC.displayptr, XA_PRIMARY )) == None ) {
		return( -1 );
		}
	else if (( W == XGC.desktopwindow ) && (!( parentWindow ))) 
	{
		/* request for one's own published selection */
		drop_clipboard();
		if ((XGC.ClipBoardValue = XGC.PublicSelection) != (char *) 0) 
		{
			XGC.ClipBoardOwner = XGC.desktopwindow;
			XGC.ClipBoardIndex = 0;
			XGC.ClipBoardLength= strlen(XGC.ClipBoardValue);
			return( consume_clipboard() );
		}
		else
		{
			return(-1);
		}
	}
	else	
	{
		status = XConvertSelection(  
			XGC.displayptr, 
			XA_PRIMARY, XA_STRING, 
		 	XGC.ClipBoard,
			XGC.desktopwindow, k->time );
		return(-1);
		}
}

public	int	paste_selection( char * mptr, int mlen )
{
	int	c;
	int	rlen=0;
	if (!( mlen ))
		return(0);

	if ( GigoXtrace & 32 ) { 
		printf("stdevent::pasteSelection(%u) : entry \r\n",mlen);
		}
	if ((c = request_clipboard()) != -1) {
		*mptr = c;
		rlen++;
		}
	while ( rlen < mlen ) {
		if (!(  test_event() ))
			break;
		else	{
			*(mptr+rlen) = wait_event();
			rlen++;
			}
		}
	if ( GigoXtrace & 32 ) { 
		printf("stdevent::pasteSelection(%u) : exit  \r\n",rlen);
		}
	return(rlen);
}

/*		    -----------------------------			*/
/*		    u s e  _ c l i p b o a r d ()			*/
/*		    ------------------------------			*/
/*									*/
/*	This function is activated in response to the reception 	*/
/*	of a SelectionNotify message being received from the   		*/
/*	current selection owner process and provides us with the	*/
/*	current text selection value.					*/
/*	The value will be type check and then submited as the		*/
/*	current standard input.						*/
/*									*/
/*		------------------------------------			*/

private	int	use_clipboard( XSelectionEvent * sptr )
{
	Atom		actual_type;
	int		actual_format_return;
	int	status;
	unsigned long	nitems_return;
	unsigned long	bytes_after_return;
	unsigned char *	property_value=(char *) 0;
	if ((status = XGetWindowProperty(
		XGC.displayptr, XGC.desktopwindow, 
		sptr->property, 0L, (long) 1000,/* delete = */  True,
		XA_STRING, 
		&actual_type, &actual_format_return,
		&nitems_return, &bytes_after_return,
		&property_value )) != Success ) {
		return( -1 );
		}
	else	{
		drop_clipboard();
		XGC.ClipBoardOwner = 0;
		XGC.ClipBoardValue = property_value;
		XGC.ClipBoardIndex = 0;
		XGC.ClipBoardLength= nitems_return;
		return(-1);
		}
}

public	void	PixelSetInputFocus(display,window,revert,when)
	Display * display;
	Window	  window;
	int	  revert;
	Time	  when;
{
	if ( GigoXtrace & 32 ) { 
		printf("XSetInputFocus(pid=%u,w=%u,r=%u,t=%lu)\r\n",getpid(),window,revert,when); 
		}
	switch ( XSetInputFocus(display,window,revert,when) ) {
		case	BadMatch 	:
			if ( GigoXtrace & 32 ) { printf("XSetInputFocus : BadMatch \r\n"); }
			break;
		case	BadValue	:
			if ( GigoXtrace & 32 ) { printf("XSetInputFocus : BadValue \r\n"); }
			break;
		case	BadWindow	:
			if ( GigoXtrace & 32 ) { printf("XSetInputFocus : BadWindow \r\n"); }
			break;
		}
	return;
}	

public	void	StdEventEnterNotify()
{
	if (!( GigoKstate & _GIGO_RESELECT_ON_FOCUS_IN /* 2 */ )) {
		if ( GigoKstate & XGC.ismapped ) {
			if ( GigoXtrace & 32 ) { printf("PixelSetInputFocus(pid=%u,ThisWindow)\r\n",getpid()); }
			PixelSetInputFocus(XGC.displayptr, XGC.desktopwindow, RevertToPointerRoot,CurrentTime );
			}
		else	{
			if ( GigoXtrace & 32 ) { printf("PixelSetInputFocus(pid=%u,PointerRoot)\r\n",getpid()); }
			PixelSetInputFocus(XGC.displayptr, PointerRoot , RevertToPointerRoot,CurrentTime );
			}
		}
	XSelectInput( XGC.displayptr, XGC.desktopwindow, XGC.currentevents );
	XSync(XGC.displayptr,FALSE);
	return;
}

/*		-------------------------------------			*/
/*		c o n s u m e _ e v e n t ( testing )			*/
/*		-------------------------------------			*/
/*									*/
/*	This function will be called upon reception of an event		*/
/*	by either the wait_event loop or the test_event loop to		*/
/*	see if the event is to be decoded and returned to the		*/
/*	client application, exa,aed,sing etc or is it to be 		*/
/*	consumed by the event management system for its own needs	*/
/*	screen refresh, selection control, etc etc			*/
/*									*/
/*	The function returns true if the event has been consumed	*/
/*	otherwise it returns false to indicate decoding is required	*/
/*									*/
/*		-------------------------------------			*/

private	int	consume_event(int testing)
{
	int		nesting=0;
	int		KeyCode;
	int		masking=0;
	XCrossingEvent *kross=(XCrossingEvent*)&XGC.event;
	XButtonEvent * 	rat= (XButtonEvent *)&XGC.event;
	XMotionEvent * 	mat= (XButtonEvent *)&XGC.event;
	XMappingEvent*  pat= (XMappingEvent*)&XGC.event;

#ifdef	GIGOXTRACE
	if ( GigoXtrace & 1 )  { printf("consume_event(%u)\r\n",XGC.event.type); }
#endif

	switch ( XGC.event.type ) {

		case	MappingNotify	:

			XRefreshKeyboardMapping(pat);
			return(1);

		case	SelectionClear	:
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 64 )  { printf("XEvent(pid=%u,SelectionClear)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
			release_public_selection();
			return(1);		/* Always Consumed */

		case	SelectionRequest :
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 64 )  { printf("XEvent(pid=%u,SelectionRequest)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
			handle_selection_request();
			return(1);		/* Always consumed */


		case	SelectionNotify	:	/* Return from Selection Request */
			/* will be traced in the decode event section later */
			// printf("do not consume SelectionNotify because it must be decoded\r\n");
			return( 0 );		/* Do not consume, needs decode	 */

		case	ButtonPress	:
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 64 )  { 
				printf("XEvent(pid=%u,ButtonPress)(%u,(%u,%u),%u)\r\n",getpid(),++ecounter,rat->x,rat->y,rat->button);
				}
#endif
			if (!( masking = get_mimo_status()))
				break;
			else	return(0);

		case	ButtonRelease	:
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 64 )  {
				printf("XEvent(pid=%u,ButtonRelease)(%u,(%u,%u),%u)\r\n",getpid(),++ecounter,rat->x,rat->y,rat->button);
				}
#endif
			if (!( masking = get_mimo_status()))
				break;
			else	return(0);

		case	MotionNotify	:
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 128 ) { 
				printf("XEvent(pid=%u,MotionNotify)(%u,(%u,%u))\r\n",getpid(),++ecounter,mat->x,mat->y );
				}
#endif
			if (!( masking = get_mimo_status()))
				break;
			else if ((masking & _MIMO_MOVE ))
				return(0);
			else if (!(masking = get_mimo_buttons()))
				break;
			else	return(0);


		case	KeyPress	:

#ifdef	GIGOXTRACE
			if ( GigoXtrace & 64 ) { printf("XEvent(pid=%u,KeyPress)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
			/* these events are never consumed */
			/* ------------------------------- */
			return(0);	

		}


	switch ( XGC.event.type ) {

		case	KeyRelease	:
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 64 ) { printf("XEvent(pid=%u,KeyRelease)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
			switch ( TranscodeXkeysymbol(&XGC.event,0)) {
				case XK_Shift_L			:
					XGC.shift &= ~1;
					break;

				case XK_Shift_R			:
					XGC.shift &= ~2;
					break;

				case	XK_ISO_Level3_Shift	:
					/* Alt Gr	 */
					XGC.alt = 0;
					break;

				case XK_Alt_L			: 
				case XK_Alt_R			: 
					if ( XGC.altcompose ) {
						return( 0 );
						}
					else	{
						XGC.alt = 0;
						break;
						}
				case XK_Control_L		: // FFE3	/* Left control */
				case XK_Control_R		: // FFE4	/* Right control */
					XGC.control = 0;
				}
			return(1);

		case	UnmapNotify	:
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 32 ) { printf("XEvent(pid=%u,UnmapNotify)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
			XGC.ismapped=0;
			if (!( GigoKstate & _GIGO_INHIBIT_UNMAP_FOCUS )) {
				if ( GigoXtrace & 32 ) { printf("PixelSetInputFocus(pid=%u,PointerRoot)\r\n",getpid()); }
				PixelSetInputFocus(XGC.displayptr, PointerRoot , RevertToPointerRoot,CurrentTime );
				}
			XSync(XGC.displayptr,TRUE);
			return(1);

		case	MapNotify	:
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 32 ) { printf("XEvent(pid=%u,MapNotify)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
			XGC.ismapped= _GIGO_SOFT_KEYBOARD_GRAB /* 1 */;
			return(1);

		case	ConfigureNotify	:
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 512 ) { printf("XEvent(pid=%u,ConfigureNotify)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
			if (!(reconfiguration()))
				return(1);
		case	Expose		:
		case	GraphicsExpose	:
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 512 ) { printf("XEvent(pid=%u,Expose/GraphicsExpose)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
			on_refresh(
				XGC.event.xexpose.x,
				XGC.event.xexpose.y,
				XGC.event.xexpose.width,
				XGC.event.xexpose.height);
			return(1);

		case	VisibilityNotify:
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 512 ) { printf("XEvent(pid=%u,VisibilityNotify)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
			return(1);

		case	EnterNotify	:
			if (!( GigoKstate & _GIGO_SUSPEND_FOCUS /*256 */ ))  {
#ifdef	GIGOXTRACE
				if ( GigoXtrace & 32 ) { printf("XEvent(pid=%u,EnterNotify)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
				StdEventEnterNotify();

				XGC.control = (kross->state & ControlMask);
				XGC.alt = 0;
				}
			return( 1 );

		case	LeaveNotify	:
			if (!( GigoKstate & _GIGO_SUSPEND_FOCUS /* 256 */))  {
#ifdef	GIGOXTRACE
				if ( GigoXtrace & 32 ) { printf("XEvent(pid=%u,LeaveNotify)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
				if (!( GigoKstate & _GIGO_RESELECT_ON_FOCUS_IN /* 2 */)) {
					if (!( GigoKstate & _GIGO_SOFT_KEYBOARD_GRAB /* 1 */)) {
						if ( GigoXtrace & 32 ) { printf("PixelSetInputFocus(pid=%u,PointerRoot)\r\n",getpid()); }
						PixelSetInputFocus(XGC.displayptr,PointerRoot, RevertToPointerRoot,CurrentTime );
						}
					}
				XGC.control = (kross->state & ControlMask);
				XGC.alt = 0;
				}
			return(1);

		case 	FocusIn    :
			if (!( GigoKstate & _GIGO_SUSPEND_FOCUS /* 256 */))  {
#ifdef	GIGOXTRACE
				if ( GigoXtrace & 32 ) { printf("XEvent(pid=%u,FocusIn)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
				if ( GigoKstate & _GIGO_RESELECT_ON_FOCUS_IN /* 2 */ ) {
					if ( GigoKstate & XGC.ismapped ) {
						if ( GigoXtrace & 32 ) { printf("PixelSetInputFocus(pid=%u,ThisWindow)\r\n",getpid()); }
						PixelSetInputFocus(XGC.displayptr, XGC.desktopwindow, RevertToPointerRoot,CurrentTime );
						}
					else	{
						if ( GigoXtrace & 32 ) { printf("PixelSetInputFocus(pid=%u,PointerRoot)\r\n",getpid()); }
						PixelSetInputFocus(XGC.displayptr, PointerRoot , RevertToPointerRoot,CurrentTime );
						}
					}
				else if (!( GigoKstate & _GIGO_SOFT_KEYBOARD_GRAB /* 1 */ )) {
					if ( GigoXtrace & 32 ) { printf("PixelSetInputFocus(pid=%u,PointerRoot)\r\n",getpid()); }
					PixelSetInputFocus(XGC.displayptr, PointerRoot , RevertToPointerRoot,CurrentTime );
					}
				XSelectInput( XGC.displayptr, XGC.desktopwindow, XGC.currentevents );
				}
			return( 1 );

		case	FocusOut	:
			if (!( GigoKstate & _GIGO_SUSPEND_FOCUS /* 256 */ ))  {
#ifdef	GIGOXTRACE
				if ( GigoXtrace & 32 )  { printf("XEvent(pid=%u,FocusOut)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
				if (!( GigoKstate & _GIGO_RESELECT_ON_FOCUS_IN /* 2 */ )) {
					if (!( GigoKstate & _GIGO_SOFT_KEYBOARD_GRAB /* 1 */ )) {
						if ( GigoXtrace & 32 ) { printf("PixelSetInputFocus(pid=%u,PointerRoot)\r\n",getpid()); }
						PixelSetInputFocus(XGC.displayptr,PointerRoot, RevertToPointerRoot,CurrentTime );
						}
					}
				}
			return( 1 );

		case	DestroyNotify	:
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 512 ) { printf("XEvent(pid=%u,DestroyNotify)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
			return(1);

		case	ResizeRequest	:
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 512 ) { printf("XEvent(pid=%u,ResizeRequest)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
			return( resize_request_handler(&XGC.event ) );

		case	ClientMessage	:
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 32 ) { printf("XEvent(pid=%u,ClientMessage)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
			return( client_message_handler(&XGC.event) );


		default			:
			return( 1 );
		}
}

/*			--------------------------			*/
/*			d e c o d e _ e v e n t ()			*/
/*			--------------------------			*/
/*									*/
/*	This function will be called upon reception of an event		*/
/*	by either the wait_event loop or the test_event loop as		*/
/*	a result of the  previous functions indicating false in		*/
/*	that the event may be decoded prior to return to the 		*/
/*	client application exa,sing,etc					*/
/*									*/
/*	The function returns -1 if event decoding has failed to 	*/
/*	provide a useable value, either a mouse event filtered		*/
/*	out by the mouse mask, of an invalid or unknow key		*/
/*	sequence. Otherwise the decoded and converted keycode		*/
/*	will be returned.
/*									*/
/*		-------------------------------------			*/

private	int	decode_event()
{
	int	KeyCode=0;

	XButtonEvent * 	rat= (XButtonEvent *)&XGC.event;
	XMotionEvent * 	mat= (XButtonEvent *)&XGC.event;
	XSelectionEvent	* paste=(XSelectionEvent *)&XGC.event;

	switch ( XGC.event.type ) {

		case	SelectionNotify	:	/* Return from Selection Request */
			// printf("decode_event(SelectionNotify)\n");
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 64 )  { printf("XEvent(pid=%u,SelectionNotify)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
			if ( paste->property == None ) {
				/* selection conversion to text */
				/* was not possible or refused	*/
				return( -1 );
				}
			else 	return( use_clipboard( paste ) );

		case	KeyPress	:

			switch ((KeyCode = TranscodeXkeysymbol(&XGC.event,1))) {
				case XK_KP_End		: // FF9C
				case XK_End		: // 0xFF57	 EOL : CTRL B */
					if ( XGC.alt ) {
						toggle_keyboard_grab();
						return(-1);
						}
					else	return( mimo_key_event(KeyCode));

				case XK_Alt_L			: 
					XGC.alt = 1;
					XGC.altcompose=0;
					return(-1);

				case XK_Alt_R			: 
					XGC.alt = 2;
					XGC.altcompose=0;
					return(-1);

				case	XK_ISO_Level3_Shift	:
					XGC.alt = 4;
					XGC.altcompose=0;
					return(-1);

				case XK_Control_L		: // FFE3	/* Left control */
				case XK_Control_R		: // FFE4	/* Right control */
					XGC.control = 1;
					return(-1);
				case XK_Shift_L			: // FFE1	/* Left shift */
					XGC.shift |= 1;
					return(-1);
				case XK_Shift_R			: // FFE2	/* Right shift */
					XGC.shift |= 2;
					return(-1);

				case XK_Caps_Lock		: // FFE5	/* Caps lock */
				case XK_Shift_Lock		: // FFE6	/* Shift lock */
				case	-1	:
					return(-1);
				default		:
					if ( XGC.alt ) {
						switch ( XGC.alt ) {
							case	1	: /* Left Alt */
							case	2	: /* Right Alt */
								if ( XGC.keyconfig & _MIMO_INTERRUPT )
									return( mimo_key_event((KeyCode & 0x00FF) | _MIMO_ALT ) );
								else	return( gigo_alt_event((KeyCode & 0x00FF)) );
							case	4	: /* Alt Gr */
								return( gigo_alt_event((KeyCode & 0x00FF)) );
							}							
						}
					else if (!( XGC.control ))
						return( mimo_key_event( KeyCode ));
					else if ((KeyCode >= 'A') && (KeyCode <= 'Z'))
						return( mimo_key_event((KeyCode-'A')+1));
					else if ((KeyCode >= 'a') && (KeyCode <= 'z'))
						return( mimo_key_event((KeyCode-'a')+1));
					else	return( mimo_key_event(KeyCode));
				}

		case	KeyRelease	:
			switch ( TranscodeXkeysymbol(&XGC.event,0) ) {
				case XK_Shift_L			: // FFE1	/* Left shift */
					XGC.shift &= ~1;
					return(-1);
				case XK_Shift_R			: // FFE2	/* Rightshift */
					XGC.shift &= ~2;
					return(-1);
	
				case XK_Alt_L			: 
				case XK_Alt_R			: 
					XGC.alt = 0;
					if ((KeyCode = XGC.altcompose) !=0 ) {
						XGC.altcompose=0;
						return( mimo_key_event(KeyCode));
						}
					return(-1);
				case XK_Control_L		: // FFE3	/* Left control */
				case XK_Control_R		: // FFE4	/* Right control */
					XGC.control = 0;
				default		:
					return(-1);					
				}

		case	MotionNotify	:
			/* consume all pending motion events */
			while ( XCheckTypedEvent(XGC.displayptr,MotionNotify,&XGC.event) );
			if ((KeyCode = mimo_use_event( 
				_MIMO_MOVE,
				mat->x,mat->y, 0,
				mat->time
				)) != -1)
				return(KeyCode);
			else	return(-1);


		case	ButtonPress	:
			if ((KeyCode = mimo_use_event( 
				_MIMO_DOWN,
				rat->x,rat->y,
				rat->button,
				rat->time
				)) != -1)
				return(KeyCode);
			else	return(-1);

		case	ButtonRelease	:
			if ((KeyCode = mimo_use_event( 
				_MIMO_UP,
				rat->x,rat->y,
				rat->button,rat->time
				)) != -1)
				return(KeyCode);
			else	return(-1);


		case	ClientMessage	:
			/* arrival here means we have a client window message : exit to signal */
			/* ------------------------------------------------------------------- */
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 32 ) { printf("XEvent(pid=%u,ClientMessage)(%u,%u)\r\n",getpid(),mat->serial,++ecounter); }
#endif
			return( mimo_key_event( (0 | _MIMO_ALT ) ));


		default		:
			return(-1);

		}

}


/*			----------------------			*/
/*			w a i t _ e v e n t ()			*/
/*			----------------------			*/
/*								*/
/*	This function waits for the arrival of a key or mouse	*/
/*	event and returns the corresponding code to the caller.	*/
/*	This is the GIGO equivalent of the CICO x_getch call.	*/
/*								*/
/*		----------------------------------------	*/

public	int	unget_event( int v )
{
	if ((UnGotKeyCode = v) != -1)
		XGC.pending=1;
	else	XGC.pending=0;
	return(UnGotKeyCode);
}

public	void	std_signal_event( int v )
{
	if ( mimo_signal_event( v ) ) {
		unget_event( 256 );
		}
}

public	int 	std_thread_event( int v )
{
	if ( mimo_task_event( v ) ) {
		unget_event( 256 );
		}
	return(0);
}

public	int	wait_event()
{
	int	KeyCode=0;

	XButtonEvent * rat= (XButtonEvent *)&XGC.event;

#ifdef	GIGOXTRACE
	if ( GigoXtrace & 2 )  {
		printf("wait_event(UgKc=%d)\r\n",UnGotKeyCode);
		}
#endif
	while(1) {

		/* Test for UnGot OP Key Value */
		/* --------------------------- */
		if ((KeyCode = UnGotKeyCode) != -1 ) {
			XGC.pending  = 0;
			UnGotKeyCode = -1;
			return( KeyCode );
			}

		/* Test for currently importing from clipboard selection */
		/* ----------------------------------------------------- */
		else if ( XGC.ClipBoardIndex < XGC.ClipBoardLength ) {
			return( consume_clipboard() );
			}

		/* Test for Function Key Value */
		/* --------------------------- */
		else if ( FunctionKeyIndex < FunctionKeyLength ) {
			KeyCode = (FunctionKeyValue[FunctionKeyIndex++] & 0x00FF);
			if ( FunctionKeyIndex == FunctionKeyLength )
				FunctionKeyIndex = FunctionKeyLength = 0;
			return( KeyCode );
			}

		/* Otherwise try and get an event */
		/* ------------------------------ */

		do	{

			if ( XGC.pending )
				XGC.pending = 0;
			else	{
#ifdef	SAFE_X_EVENTS
				(void) SafeXWindowEvent(1);
#else
#ifdef	VISUAL_CLIPBOARD
				/* ----------------------------------------------------------	*/
				/* This is necessary to allow reception of unmaskable events 	*/
				/* Such as ClientMessage events and Selection events		*/
				/* ----------------------------------------------------------	*/
				XNextEvent	(
						XGC.displayptr,
						&XGC.event
						);
#else
				XWindowEvent	(
						XGC.displayptr,
						XGC.desktopwindow,
						XGC.currentevents,
						&XGC.event
						);
#endif
#endif
				}
			}
		while ( consume_event(0) == 1 );

		if ((KeyCode = decode_event()) != -1 )
			return( KeyCode );
		else	continue;

		}
}

/*	------------------------------------------------------------	*/
/*		p i x e l _ s c r e e n _ m a n a g e r ()		*/
/*	------------------------------------------------------------	*/
/*	called from iof_screen_manager during loadgo child wait		*/ 
/*	------------------------------------------------------------	*/
public	void	pixel_screen_manager()
{
	while  ( test_event() )
		wait_event();
	return;
}

/*			----------------------			*/
/*			t e s t _ e v e n t ()			*/
/*			----------------------			*/
/*								*/
/*	This function tests for the presence of an uncomsumed	*/
/*	event on the event queue. Events received will be	*/
/*	processed for consumtion in order to allow bread and	*/
/*	butter low level events to go about their business.	*/
/*	This function will return zero if no unconsumed event	*/
/*	is pending, other wise it will return true.		*/
/*
/*	This is the GIGO equivalent of the CICO x_kbhit call.	*/
/*								*/
/*		----------------------------------------	*/

public	int	peek_event()
{
	if ( UnGotKeyCode == -1 )
		return(0);
	else if ( UnGotKeyCode != 256 )
		return(2);
	else	return(1);
}

public	int	test_event()
{
#ifdef	GIGOXTRACE
	if ( GigoXtrace & 2 )  {
 		if ( UnGotKeyCode != -1 )
 			printf("test_event(UgKc=%d)\r\n",UnGotKeyCode);
		else	printf("*");
 		}
#endif
	
	/* Test for UnGot Op key value present */
	/* ----------------------------------- */
	if ( UnGotKeyCode != -1 )
		return(peek_event());
	
	/* Test for currently importing from clipboard selection */
	/* ----------------------------------------------------- */
	else if ( XGC.ClipBoardIndex < XGC.ClipBoardLength ) {
		return(2);
		}

	/* Test for function key value present */
	/* ----------------------------------- */
	else if ( FunctionKeyIndex < FunctionKeyLength )
		return(2);

	while (!(XGC.pending)) {

#ifdef	SAFE_X_EVENTS
		if (!( SafeXWindowEvent(0) ))
			break;
#else
#ifdef	VISUAL_CLIPBOARD
		/* ----------------------------------------------------------	*/
		/* This is necessary to allow reception of unmaskable events 	*/
		/* Such as ClientMessage events and Selection events		*/
		/* ----------------------------------------------------------	*/
		if (!( XPending( XGC.displayptr ) ))
			break;

		else 	XNextEvent( XGC.displayptr, &XGC.event );
#else
		if (!( XCheckWindowEvent(
				XGC.displayptr,
				XGC.desktopwindow,
				XGC.currentevents,
				&XGC.event
				)))
			break;
#endif
#endif
		if ( consume_event(1) )
			continue;

		else if ((UnGotKeyCode = decode_event()) != -1)
			XGC.pending=peek_event();
			
		}

	return( XGC.pending );
}

/*	--------------------------------------------	*/
/*	General Event Context Manipulation Functions	*/
/*	and Mouse Cursor positioning routines		*/
/*	--------------------------------------------	*/

public	void	set_enhanced_events()
{
	XGC.currentevents = _X11_MOUSE_EVENTS;
	if ( XGC.displayptr )
		XSelectInput( XGC.displayptr, XGC.desktopwindow, XGC.currentevents );
	return;
}

public	void	set_standard_events()
{
	XGC.currentevents = _X11_MOUSE_EVENTS;
	if ( XGC.displayptr )
		XSelectInput( XGC.displayptr, XGC.desktopwindow, XGC.currentevents );
	return;
}


/*	-----------------------------------------------------------------------		*/
/*	called from Exa Cute Mechanisms of LOAD.GO prior to X/11 Window Sharing		*/
/*	-----------------------------------------------------------------------		*/
public	void	suspend_standard_events()
{
	if ( XGC.displayptr ) {
		cancel_input_focus();
#ifdef	GIGOXTRACE
		if ( GigoXtrace & 32 )  { printf("XSelectInput(pid=%u,window=%u,flags=0)\r\n",getpid(),XGC.desktopwindow); }
#endif
		XSelectInput( XGC.displayptr, XGC.desktopwindow, _X11_SUSPENDED_EVENTS );
		XFlush( XGC.displayptr );
		}
	return;
}

/*	-----------------------------------------------------------------------------		*/
/*	called from Exa Cute Mechanisms of LOAD.GO on return from X/11 Window Sharing		*/
/*	-----------------------------------------------------------------------------		*/
public	void	resume_standard_events()
{
	if ( XGC.displayptr ) {
#ifdef	GIGOXTRACE
		if ( GigoXtrace & 32 )  { printf("XSelectInput(pid=%u,window=%u,flags=%x)\r\n",getpid(),XGC.desktopwindow,XGC.currentevents); }
#endif
		XSelectInput( XGC.displayptr, XGC.desktopwindow, XGC.currentevents );
		restore_input_focus();
		XFlush( XGC.displayptr );
		}
	return;
}

private	int	SetAlternativeMouseCursor() 
{
	if (!( parentWindow )) {
		XDefineCursor(XGC.displayptr,XGC.desktopwindow,XGC.alternatecursor);
		}
	return(0);
}

private	int	SetStandardMouseCursor()
{
	if (!( parentWindow )) {
		XDefineCursor(XGC.displayptr,XGC.desktopwindow,XGC.standardcursor);
		}
	return(0);
}

private	int	SetWaitingMouseCursor()
{
	if (!( parentWindow )) {
		XDefineCursor(XGC.displayptr,XGC.desktopwindow,XGC.waitingcursor);
		}
	return(0);
}

private	int	SetProblemMouseCursor()
{
	if (!( parentWindow )) {
		XDefineCursor(XGC.displayptr,XGC.desktopwindow,XGC.problemcursor);
		}
	return(0);
}

private	int	keyboard_grab_status()
{
	return( XGC.keyboardgrab );
}

private	int	ungrab_keyboard()
{
	int	status = 0;
	if ( GigoXtrace & 32 ) { printf("XGrabKeyboard(pid=%u,1)\r\n",getpid()); }
	status = XGrabKeyboard(XGC.displayptr,XGC.desktopwindow,True,GrabModeAsync,GrabModeAsync,CurrentTime);
	if ( GigoXtrace & 32 ) { printf("XUnGrabKeyboard(pid=%u)\r\n",getpid()); }
	XUngrabKeyboard(XGC.displayptr,CurrentTime);
	XGC.keyboardgrab = 0;
	return( status );
}

private	int	grab_keyboard()
{
	int	status = 0;
	if ( GigoXtrace & 32 ) { printf("XGrabKeyboard(pid=%u,0)\r\n",getpid()); }
	if (!( status = XGrabKeyboard(XGC.displayptr,XGC.desktopwindow,False,GrabModeAsync,GrabModeAsync,CurrentTime))) {
		if (!( XGC.keyboardgrab ))
			XGC.keyboardgrab=1;
		else	XGC.keyboardgrab=0;
		}
	return( status );
}

private	int	toggle_keyboard_grab()
{
	if ( XGC.keyboardgrab )
		return( ungrab_keyboard() );
	else	return(   grab_keyboard() );
}

private	int	WindowExitButton(int state)
{
	int	current;
	current = (XGC.windowflags & 3);
	switch ( state ) {
		case	1 : XGC.windowflags |= 1;  break;
		case	0 : XGC.windowflags &= ~3; break;
		case	2 : XGC.windowflags |= 2;  break;
		}
	return( current );
}

private	int	xgr_after_handler(Display * dptr)
{
	if ( GigoXtrace & 512 ) { 
		printf("XAfter(pid=%u)\r\n",getpid());
		}
	return(0);
}

private	int	xgr_error_handler(Display * dptr, XErrorEvent * eptr)
{
	char	message[121];
	if ( GigoXtrace & 32 ) { 
		XGetErrorText(XGC.displayptr, eptr->error_code, message, 120);
		printf("XEvent(pid=%u,ErrorNotify)(%u,%u,major=%u,minor=%u) : %s \r\n",getpid(),eptr->serial,++ecounter,eptr->request_code,eptr->minor_code,message); 
		}
	return(0);
}

private	int	xgr_io_error_handler(Display * dptr, XErrorEvent * eptr)
{
	if ( GigoXtrace & 32 ) { printf("XEvent(pid=%u,IOErrorNotify)(%u,%u)\r\n",getpid(),eptr->serial,++ecounter); }
	return(panic(SIGKILL));
}

public	xgr_error_handlers()
{
	XSetAfterFunction( XGC.displayptr, xgr_after_handler );
	XSetErrorHandler(xgr_error_handler);
	XSetIOErrorHandler(xgr_io_error_handler);
	return;
}



/*		---------------------------------		*/
/*		x g r _ e v e n t ( int eventid )		*/
/*		---------------------------------		*/
/*								*/
/*	This is the low level event fetch function called	*/
/*	through the CICO/GIGO relay for mouse and other		*/
/*	event level information by the ABAL instruction		*/
/*								*/
/*			V = EVENT( eventid )			*/
/*								*/
/*	or by other clients for similar reasons			*/
/*								*/
/*		---------------------------------		*/

public	long	pixel_application_window(long v)
{
	long	holder;
	holder = XGC.desktopwindow;
	if ( v ) { XGC.desktopwindow = v; }
	return( holder );
}


public	int	xgr_event(int eventid)
{
	if (!(XGC.displayptr ))
		return(0);

#ifdef	GIGOXTRACE
	if ( GigoXtrace & 4 )  {
		printf("x_event(%u)\r\n",eventid);
		}
#endif

	switch( eventid ) {
		case	0 : return( activate_mimo() );
		case	1 : return( get_mimo_type() );
		case	2 : return( get_mimo_par()  );
		case	3 : return( get_mimo_lin()  );
		case	4 : return( get_mimo_col()  );
		case	5 : return( get_mimo_mask() );
		case	6 : return( flush_mimo()    );
		case	8 : return( get_mimo_row() );
		case	9 : return( get_mimo_column() );

		case	22: 
			//printf("event 22 : test event : %u \r\n",gigo_test_replaying() );
			if ( gigo_test_replaying() )
				return( xgr_kbhit() );
			else	return( test_event() );
		case	23: 
			//printf("event 23 : wait event : %u\r\n",gigo_test_replaying() );
			if ( gigo_test_replaying() )
				return( xgr_getch() );
			else	return( wait_event() );
			
		case	29: return( esc_op_v() );
		case	30: return( esc_op_w() );
		case	31: return((XGC.keyconfig |= _MIMO_INTERRUPT));
		case	32: return((XGC.keyconfig &= ~_MIMO_INTERRUPT));
		case	33: return( SetAlternativeMouseCursor() );
		case	34: return( SetStandardMouseCursor() );
		case	35: return( SetWaitingMouseCursor() );
		case	36: return( SetProblemMouseCursor() );
		case	82: return( 1 );
		case	81: return( esc_F() );
		case	80: return( esc_E() );
		case	88: return( get_cyrillic_base() );
		case	40: 
		case	41: 
		case	42: return( WindowExitButton(eventid-40) );
		case	66: return( get_biosmode() );
		case	75: return( set_gigo_cursor(-1) );
		case	90: return( hide() );
		case    91: return( show(0,0,0,0) );
		case    92: return( hidecount() );
		case    96: return( (XGC.trace_error_count=0) );
		case    97: return( XGC.trace_error_count );
		case    98: return( keyboard_grab_status() );
		case    99: return( toggle_keyboard_grab() );
		case   200: return( cico_top_margin() );
		case   201: return( cico_right_margin() );
		case   202: return( cico_bottom_margin() );
		case   203: return( cico_left_margin() );
		case   204: return( cico_cell_height() );
		case   205: return( cico_cell_width() );
		case   206: return( cico_cell_ymargin() );
		case   207: return( cico_cell_xmargin() );
		case   208: return( cico_page_height() );
		case   209: return( cico_page_width() );
		case   210: return( cico_font_number() );
		case   300: return( push_freeze() );
		case   301: return( pop_freeze() );
		default	  : return(0);
		}
}

/*	-------------------------------------------	*/
/*	The name of this function speaks for itself	*/
/*	-------------------------------------------	*/
void	initialise_event_manager()
{
	char * eptr;
#ifdef	GIGOXTRACE
	GigoXtrace = 0;
	if ((eptr = getenv("GIGOXTRACE")) != (char *) 0) {
		while ( *eptr ) {
			if ((*eptr < '0' ) || ( *eptr > '9'))
				break;
			else 	GigoXtrace = ((GigoXtrace * 10) + ( *(eptr++) - '0' ));
			}
		if ( GigoXtrace  ) {
			printf("Event Trace Active : %d ( %x )\n",GigoXtrace );
			}
		}
	if ((eptr = getenv("GIGOKBD")) != (char *) 0) {
		GigoKstate=0;
		while ( *eptr ) {
			if ((*eptr < '0' ) || ( *eptr > '9'))
				break;
			else 	GigoKstate = ((GigoKstate * 10) + ( *(eptr++) - '0' ));
			}
		if ( GigoXtrace  ) {
			printf("Keyboard Options : %d ( %x )\n",GigoKstate );
			}
		}
#endif
	return;
}

#endif	/* _stdevent_c */


