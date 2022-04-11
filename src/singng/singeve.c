#ifndef	_SING_EVENT_C
#define	_SING_EVENT_C

#include "singeve.h"

private	void 	drop_event_control(struct event_control * eptr)
{
	if (( eptr->control & _IS_ON_CREATE )
	&&  ( eptr->on_create   ))
		eptr->on_create = liberate( eptr->on_create );

	if (( eptr->control & _IS_ON_REMOVE )
	&&  ( eptr->on_remove   ))
		eptr->on_remove = liberate( eptr->on_remove );

	if (( eptr->control & _IS_ON_SHOW )
	&&  ( eptr->on_show   ))
		eptr->on_show = liberate( eptr->on_show );

	if (( eptr->control & _IS_ON_HIDE )
	&&  ( eptr->on_hide   ))
		eptr->on_hide = liberate( eptr->on_hide );

	if (( eptr->control & _IS_ON_FOCUS)
	&&  ( eptr->on_get_focus   ))
		eptr->on_get_focus = liberate( eptr->on_get_focus );

	if (( eptr->control & _IS_ON_LOSE)
	&&  ( eptr->on_lose_focus   ))
		eptr->on_lose_focus = liberate( eptr->on_lose_focus );

	if (( eptr->control & _IS_ON_EVENT)
	&&  ( eptr->on_event   ))
		eptr->on_event = liberate( eptr->on_event );
	return;
}

public 	void 	reset_extended_events(struct event_control * eptr,int widget_class)
{
	eptr->control 		|= (_ALL_XO_EVENTS | _IS_ON_MOUSE);
	eptr->mimo		=  _MIMO_UP;
	eptr->xo_create 	= eptr->xo_remove 	=
	eptr->xo_show 		= eptr->xo_hide 	=
	eptr->xo_get_focus 	= eptr->xo_lose_focus 	= 
	eptr->xo_event		= _INLINE_NOT_FOCUS;

	switch ( (widget_class & _FRAME_TYPE ) ) {
		case	_FILL_FRAME	:	
		case	_OUTSET_FRAME	:	
		case	_INSET_FRAME	:	
		case	_RIDGE_FRAME	:	
		case	_GROOVE_FRAME	:	
		case	_LINE_FRAME	:

			/* Default Decoration only */
			/* ----------------------- */
			break;

		case	_TEXT_FRAME	:	
		case	_IMAGE_FRAME	:	

			/* May need calling so : Function */
			/* ------------------------------ */
			eptr->xo_show 		= 
			eptr->xo_get_focus 	= 
			eptr->xo_event		= _FUNCTION_NOT_FOCUS;
			break;

		case	_WINDOW_FRAME	:	

			/* May need calling so : Function */
			/* ------------------------------ */
			eptr->xo_show 		= 
			eptr->xo_get_focus 	= _FUNCTION_NOT_FOCUS;
			eptr->xo_event		= _FUNCTION_AND_FOCUS;
			break;

		case	_EDIT_FRAME	:	
		case	_BUTTON_FRAME	:	
		case	_TAB_FRAME	:	
		case	_SWITCH_FRAME	:	
		case	_GRAPH_FRAME	:	
		case	_CHECK_FRAME	:	
		case	_RADIO_FRAME	:	
		case	_SELECT_FRAME	:	
#ifdef	ABAL32A			
			eptr->xo_lose_focus	= 
#endif
			eptr->xo_show 		= _FUNCTION_NOT_FOCUS;
			eptr->xo_event		= 
			eptr->xo_get_focus	= _FUNCTION_AND_FOCUS;
			break;

		case	_FORM_FRAME	:	
			
			eptr->mimo		= _MIMO_DOWN;
#ifdef	ABAL32A			
			eptr->xo_lose_focus	= 
#endif
			eptr->xo_show 		= _FUNCTION_NOT_FOCUS;
			eptr->xo_event		= 
			eptr->xo_get_focus	= _FUNCTION_AND_FOCUS;
			break;

		case	_PROGRESS_FRAME	:
		case	_SCROLL_FRAME	:
			eptr->mimo		= (_MIMO_DOWN | _MIMO_UP | _MIMO_WHILE_DOWN);
#ifdef	ABAL32A			
			eptr->xo_lose_focus	= 
#endif
			eptr->xo_show 		= _FUNCTION_NOT_FOCUS;
			eptr->xo_event		= 
			eptr->xo_get_focus	= _FUNCTION_AND_FOCUS;
			break;


		}
	return;
}

public 	void 	reset_event_control(struct event_control * eptr,int widget_class)
{
	eptr->control 		= 0;
	eptr->mimo              = 0;

	reset_extended_events( eptr,widget_class );

	eptr->on_create 	=
	eptr->on_remove 	=
	eptr->on_show 		=
	eptr->on_hide 		=
	eptr->on_get_focus 	= 
	eptr->on_lose_focus 	= 
	eptr->on_event    	= (void *) 0;
	return;
}

private	void	copy_event_control(
		struct event_control * rptr,
		struct event_control * sptr)
{
	rptr->control   = sptr->control;
	rptr->mimo      = sptr->mimo;

	if (( sptr->control & _IS_ON_CREATE )
	&&  ( sptr->on_create   ))
		rptr->on_create = allocate_string(  sptr->on_create );
	else	rptr->on_create = (char *) 0;

	if (( sptr->control & _IS_ON_REMOVE )
	&&  ( sptr->on_remove   ))
		rptr->on_remove = allocate_string(  sptr->on_remove );
	else	rptr->on_remove = (char *) 0;

	if (( sptr->control & _IS_ON_SHOW )
	&&  ( sptr->on_show   ))
		rptr->on_show = allocate_string(  sptr->on_show );
	else	rptr->on_show = (char *) 0;

	if (( sptr->control & _IS_ON_HIDE )
	&&  ( sptr->on_hide   ))
		rptr->on_hide = allocate_string(  sptr->on_hide );
	else	rptr->on_hide = (char *) 0;

	if (( sptr->control & _IS_ON_FOCUS)
	&&  ( sptr->on_get_focus   ))
		rptr->on_get_focus = allocate_string(  sptr->on_get_focus );
	else	rptr->on_get_focus = (char *) 0;

	if (( sptr->control & _IS_ON_LOSE)
	&&  ( sptr->on_lose_focus   ))
		rptr->on_lose_focus = allocate_string(  sptr->on_lose_focus );
	else	rptr->on_lose_focus= (char *) 0;

	if (( sptr->control & _IS_ON_EVENT)
	&&  ( sptr->on_event   ))
		rptr->on_event = allocate_string(  sptr->on_event );
	else	rptr->on_event = (char *) 0;

	rptr->xo_create = sptr->xo_create;
	rptr->xo_show = sptr->xo_show;
	rptr->xo_get_focus = sptr->xo_get_focus;
	rptr->xo_event = sptr->xo_event;
	rptr->xo_lose_focus = sptr->xo_lose_focus;
	rptr->xo_hide = sptr->xo_hide;
	rptr->xo_remove = sptr->xo_remove;

	return;
	
}

private	void	check_event_control(struct event_control * eptr)
{
	if (( eptr->control & _IS_ON_CREATE )
	&&  (!( eptr->on_create   )))
		eptr->control &= ~_IS_ON_CREATE;

	if (( eptr->control & _IS_ON_REMOVE )
	&&  (!( eptr->on_remove   )))
		eptr->control &= ~_IS_ON_REMOVE;

	if (( eptr->control & _IS_ON_SHOW )
	&&  (!( eptr->on_show   )))
		eptr->control &= ~_IS_ON_SHOW;

	if (( eptr->control & _IS_ON_HIDE )
	&&  (!( eptr->on_hide   )))
		eptr->control &= ~_IS_ON_HIDE;

	if (( eptr->control & _IS_ON_FOCUS )
	&&  (!( eptr->on_get_focus   )))
		eptr->control &= ~_IS_ON_FOCUS;

	if (( eptr->control & _IS_ON_LOSE )
	&&  (!( eptr->on_lose_focus   )))
		eptr->control &= ~_IS_ON_LOSE;

	if (( eptr->control & _IS_ON_EVENT )
	&&  (!( eptr->on_event   )))
		eptr->control &= ~_IS_ON_EVENT;
	return;
}		

private	void	save_event_control(FILE * h, struct event_control * eptr)
{
	check_event_control( eptr );

	put_word(h, eptr->control );

	if ((eptr->control & _IS_ON_MOUSE))
		put_word(h,eptr->mimo);

	/* Primary : Event Methods */
	/* ----------------------- */
	if (( eptr->control & _IS_ON_CREATE )
	&&  ( eptr->on_create   ))
		put_string(h, eptr->on_create );

	if (( eptr->control & _IS_ON_REMOVE )
	&&  ( eptr->on_remove   ))
		put_string(h, eptr->on_remove );

	if (( eptr->control & _IS_ON_SHOW )
	&&  ( eptr->on_show   ))
		put_string(h, eptr->on_show );

	if (( eptr->control & _IS_ON_HIDE )
	&&  ( eptr->on_hide   ))
		put_string(h, eptr->on_hide );

	if (( eptr->control & _IS_ON_FOCUS)
	&&  ( eptr->on_get_focus   ))
		put_string(h, eptr->on_get_focus );

	if (( eptr->control & _IS_ON_LOSE)
	&&  ( eptr->on_lose_focus   ))
		put_string(h, eptr->on_lose_focus );

	if (( eptr->control & _IS_ON_EVENT)
	&&  ( eptr->on_event   ))
		put_string(h, eptr->on_event );

	/* Secondary Event Extensions */
	/* -------------------------- */

	if ( eptr->control & _IS_XO_CREATE )
		put_word(h, eptr->xo_create );

	if ( eptr->control & _IS_XO_REMOVE )
		put_word(h, eptr->xo_remove );

	if ( eptr->control & _IS_XO_SHOW )
		put_word(h, eptr->xo_show );

	if ( eptr->control & _IS_XO_HIDE )
		put_word(h, eptr->xo_hide );

	if ( eptr->control & _IS_XO_FOCUS)
		put_word(h, eptr->xo_get_focus );

	if ( eptr->control & _IS_XO_LOSE)
		put_word(h, eptr->xo_lose_focus );

	if ( eptr->control & _IS_XO_EVENT)
		put_word(h, eptr->xo_event );

	return;
}

private	void load_event_control(FILE * h, struct event_control * eptr)
{
	eptr->control = get_word(h);

	if ((eptr->control & _IS_ON_MOUSE))
		eptr->mimo = get_word(h);
	else	{
		eptr->mimo = _MIMO_UP;
		eptr->control |= _IS_ON_MOUSE;
		}

	if ((eptr->control & _IS_ON_CREATE )
	&& (!( eptr->on_create = get_string(h) )))
		eptr->control &= ~_IS_ON_CREATE;

	if ((eptr->control & _IS_ON_REMOVE )
	&& (!( eptr->on_remove = get_string(h) )))
		eptr->control &= ~_IS_ON_REMOVE;

	if ((eptr->control & _IS_ON_SHOW )
	&& (!( eptr->on_show   = get_string(h) )))
		eptr->control &= ~_IS_ON_SHOW;

	if ((eptr->control & _IS_ON_HIDE )
	&& (!( eptr->on_hide   = get_string(h) )))
		eptr->control &= ~_IS_ON_HIDE;

	if ((eptr->control & _IS_ON_FOCUS )
	&& (!( eptr->on_get_focus = get_string(h) )))
		eptr->control &= ~_IS_ON_FOCUS;

	if ((eptr->control & _IS_ON_LOSE)
	&& (!( eptr->on_lose_focus = get_string(h) )))
		eptr->control &= ~_IS_ON_LOSE;

	if ((eptr->control & _IS_ON_EVENT)
	&& (!( eptr->on_event	 = get_string(h) )))
		eptr->control &= ~_IS_ON_EVENT;


	/* Eliminate all null length strings 	*/
	/* and reset all controllers		*/
	/* ------------------------------------ */
	perform_event_control(eptr);

	/* Secondary Event Extensions */
	/* -------------------------- */

	if ( eptr->control & _IS_XO_CREATE )
		macro_get_word(h, eptr->xo_create );

	if ( eptr->control & _IS_XO_REMOVE )
		macro_get_word(h, eptr->xo_remove );

	if ( eptr->control & _IS_XO_SHOW )
		macro_get_word(h, eptr->xo_show );

	if ( eptr->control & _IS_XO_HIDE )
		macro_get_word(h, eptr->xo_hide );

	if ( eptr->control & _IS_XO_FOCUS)
		macro_get_word(h, eptr->xo_get_focus );

	if ( eptr->control & _IS_XO_LOSE)
		macro_get_word(h, eptr->xo_lose_focus );

	if ( eptr->control & _IS_XO_EVENT)
		macro_get_word(h, eptr->xo_event );
	
	return;
}

public	void	use_event_control( 
		struct event_control * eptr,
		int event_code
		)
{
	char	*	sptr;
	switch ( event_code ) {

		case	_EVENT_CREATE	:
			if (!( sptr = eptr->on_create ))
				eptr->control &= ~ _IS_ON_CREATE;
			else if (!( is_valid_method( sptr ) )) {
				eptr->on_create = liberate( eptr->on_create );
				eptr->control &= ~ _IS_ON_CREATE;
				}
			else	eptr->control |=   _IS_ON_CREATE;
			break;

		case	_EVENT_REMOVE	:
			if (!( sptr = eptr->on_remove ))
				eptr->control &= ~ _IS_ON_REMOVE;
			else if (!( is_valid_method( sptr ) )) {
				eptr->on_remove = liberate( eptr->on_remove );
				eptr->control &= ~ _IS_ON_REMOVE;
				}
			else	eptr->control |=   _IS_ON_REMOVE;
			break;

		case	_EVENT_SHOW  	:
			if (!( sptr = eptr->on_show ))
				eptr->control &= ~ _IS_ON_SHOW;
			else if (!( is_valid_method( sptr ) )) {
				eptr->on_show = liberate( eptr->on_show );
				eptr->control &= ~ _IS_ON_SHOW;
				}
			else	eptr->control |=   _IS_ON_SHOW;
			break;

		case	_EVENT_HIDE  	:
			if (!( sptr = eptr->on_hide ))
				eptr->control &= ~ _IS_ON_HIDE;
			else if (!( is_valid_method( sptr ) )) {
				eptr->on_hide = liberate( eptr->on_hide );
				eptr->control &= ~ _IS_ON_HIDE;
				}
			else	eptr->control |=   _IS_ON_HIDE;
			break;

		case	_EVENT_FOCUS 	:
			if (!( sptr = eptr->on_get_focus ))
				eptr->control &= ~ _IS_ON_FOCUS;
			else if (!( is_valid_method( sptr ) )) {
				eptr->on_get_focus = liberate( eptr->on_get_focus );
				eptr->control &= ~ _IS_ON_FOCUS;
				}
			else	eptr->control |=   _IS_ON_FOCUS;
			break;

		case	_EVENT_LOSE  	:
			if (!( sptr = eptr->on_lose_focus ))
				eptr->control &= ~ _IS_ON_LOSE;
			else if (!( is_valid_method( sptr ) )) {
				eptr->on_lose_focus = liberate( eptr->on_lose_focus );
				eptr->control &= ~ _IS_ON_LOSE;
				}
			else	eptr->control |=   _IS_ON_LOSE;
			break;

		case	_EVENT_EVENT 	:
			if (!( sptr = eptr->on_event ))
				eptr->control &= ~ _IS_ON_EVENT;
			else if (!( is_valid_method( sptr ) )) {
				eptr->on_event = liberate( eptr->on_event );
				eptr->control &= ~ _IS_ON_EVENT;
				}
			else	eptr->control |=   _IS_ON_EVENT;
			break;
		}
	return;
}

public	void	perform_event_control( struct event_control * eptr )
{
	use_event_control( eptr, _EVENT_CREATE );
	use_event_control( eptr, _EVENT_REMOVE );
	use_event_control( eptr, _EVENT_SHOW   );
	use_event_control( eptr, _EVENT_HIDE   );
	use_event_control( eptr, _EVENT_FOCUS  );
	use_event_control( eptr, _EVENT_LOSE   );
	use_event_control( eptr, _EVENT_EVENT  );
	return;
}

public	void	accept_event( int event_code, struct event_control * eptr )
{
	char	* mptr;
	void	*tptr;

	switch ( event_code ) {
		case	_EVENT_CREATE	:
			mptr = "Event : On Create";
			tptr = &eptr->on_create; break;
		case	_EVENT_REMOVE	:
			mptr = "Event : On Remove";
			tptr = &eptr->on_remove; break;
		case	_EVENT_SHOW  	:
			mptr = "Event : On Show";
			tptr = &eptr->on_show; break;
		case	_EVENT_HIDE  	:
			mptr = "Event : On Hide";
			tptr = &eptr->on_hide; break;
		case	_EVENT_FOCUS 	:
			mptr = "Event : On Get Focus";
			tptr = &eptr->on_get_focus; break;
		case	_EVENT_LOSE  	:
			mptr = "Event : On Lose Focus";
			tptr = &eptr->on_lose_focus; break;
		case	_EVENT_EVENT 	:
			mptr = "Event : On Event";
			tptr = &eptr->on_event; break;
		default			:
			return;
		}

	if ( use_visual_text_editor( tptr, 0 ) != 27 )
		use_event_control( eptr, event_code );

	draw_console();

	return;
}

private	void 	normalise_event_methods(struct event_control * eptr)
{
	if (( eptr->control & _IS_ON_CREATE )
	&&  ( eptr->on_create   ))
		eptr->on_create = normalise_method_text( eptr->on_create );

	if (( eptr->control & _IS_ON_REMOVE )
	&&  ( eptr->on_remove   ))
		eptr->on_remove = normalise_method_text( eptr->on_remove );

	if (( eptr->control & _IS_ON_SHOW )
	&&  ( eptr->on_show   ))
		eptr->on_show = normalise_method_text( eptr->on_show );

	if (( eptr->control & _IS_ON_HIDE )
	&&  ( eptr->on_hide   ))
		eptr->on_hide = normalise_method_text( eptr->on_hide );

	if (( eptr->control & _IS_ON_FOCUS)
	&&  ( eptr->on_get_focus   ))
		eptr->on_get_focus = normalise_method_text( eptr->on_get_focus );

	if (( eptr->control & _IS_ON_LOSE)
	&&  ( eptr->on_lose_focus   ))
		eptr->on_lose_focus = normalise_method_text( eptr->on_lose_focus );

	if (( eptr->control & _IS_ON_EVENT)
	&&  ( eptr->on_event   ))
		eptr->on_event = normalise_method_text( eptr->on_event );
	return;
}

public	void	SetEventProperty(struct event_control * eptr, int event )
{
	switch ( event ) {
		case	_CREATE_WITHOUT_SIZE	:
			eptr->xo_create &= ~_EVENT_IS_FOCUS;
			break;
		case	_CREATE_WITH_SIZE	:
			eptr->xo_create |= _EVENT_IS_FOCUS;
			break;
		case	_SHOW_AUTOMATIC		:
			eptr->xo_show &= ~_EVENT_IS_COND;
			break;
		case	_SHOW_CONDITIONAL	:
			eptr->xo_show |= _EVENT_IS_COND;
			break;
		case	_FOCUS_WITHOUT_FOCUS	:
			eptr->xo_get_focus &= ~_EVENT_IS_FOCUS;
			break;
		case	_FOCUS_WITH_FOCUS	:
			eptr->xo_get_focus |= _EVENT_IS_FOCUS;
			break;
		case	_EVENT_WITHOUT_EVENT	:
			eptr->xo_event &= ~_EVENT_IS_FOCUS;
			break;
		case	_EVENT_WITH_EVENT	:
			eptr->xo_event |= _EVENT_IS_FOCUS;
			break;
		case	_HIDE_NO_POPUP		:
			eptr->xo_hide &= ~_EVENT_IS_POP;
			break;
		case	_HIDE_WITH_POPUP	:
			eptr->xo_hide |= _EVENT_IS_POP;
			break;
		}
	return;
}

#endif	/* _SING_EVENT_C */












































































































