#ifndef	_stdevent_h
#define	_stdevent_h

/*	---------------------------------------------------------------------	*/
/*	These constants control crucial keyboard and event handling decisions 	*/
/*	---------------------------------------------------------------------	*/
/*	Their default value may be changed by the ENV( GIGOKBD )		*/
/*	---------------------------------------------------------------------	*/

#define	_GIGO_SUSPEND_FOCUS		256

#define	_GIGO_INHIBIT_UNMAP_FOCUS	8
#define	_GIGO_INITIAL_WINDOW_FOCUS	4
#define	_GIGO_RESELECT_ON_FOCUS_IN 	2
#define	_GIGO_SOFT_KEYBOARD_GRAB	1

#ifdef	_stdevent_c

		/* ---------------------------------------------------------------- */
		/* the default value of 1 ... caused keyboard to be kept by windows */
		/* even when the pointer has left the window, unless the new window */
		/* grabs the keyboard for itself on receiving the EventEvent	    */
		/* This may be set to zero by the environment variable GIGOKBD to   */
		/* revert to the previous PointerRoot and RevertToPointerRoot state.*/
		/* ---------------------------------------------------------------- */
		/* The new default value of 3 causes the keyboard to be kept by     */
		/* windows unles an active grab has been performed by others. This  */
		/* window will only reselect its input on receipt of a FocusIn 	    */
		/* Event instead of the EnterNotification  Event		    */
		/* ---------------------------------------------------------------- */
		/* 06/01/2006 : For Alliance IceWM Exa Startup by Keyboard Bug	    */
		/* ---------------------------------------------------------------- */
		/* The new bit field of 4 causes the XSetInputFocus to the newly    */
		/* created window instead of leaving this to PointerRoot as before  */
		/* ---------------------------------------------------------------- */
		/* The bit 8 inhibits the XSetInputFocus call on receipt of Unmap   */
		/* events in order to avoid grabing the keyboard whilst unmapped    */
		/* This looks like a KDE bug since the XSetInputFocus call allowed  */
		/* and even Requested Revert to Pointer and Pointer Root !!!!	    */
		/* ---------------------------------------------------------------- */

int	GigoKstate = 	( _GIGO_INHIBIT_UNMAP_FOCUS 
  			| _GIGO_INITIAL_WINDOW_FOCUS
  			| _GIGO_RESELECT_ON_FOCUS_IN
  			| _GIGO_SOFT_KEYBOARD_GRAB	);
#else
extern int GigoKstate;
#endif


#endif	/* _stdevent_h */
	/* ----------- */

