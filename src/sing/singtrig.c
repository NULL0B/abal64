#ifndef	_singtrig_c
#define	_singtrig_c

private	int		TriggerMap[256];
private	int		Triggers=0;
private	int		TriggerBase=0;

public	int	widget_can_trigger( struct window_control * dptr )
{
	char	*	sptr;

	switch ( (dptr->style & _FRAME_TYPE) ) {
		case	_TAB_FRAME	:
			return( 1 );
		case	_BUTTON_FRAME	:
			if ( dptr->align & 1 )
				return(0); /* images !!! */
			else	return(2); /* textes !!! */
		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
			return(2);

		case	_EDIT_FRAME	:
			if ( (!( sptr = dptr->payload )) || (!( *sptr )))
				return(0);
			else	return(2);
		default			:
			return(0);
		}
}				

public	int	compare_hotkeys( int a, int b )
{
	if ( a == b )	return(1);
	a &= 0x00FF; b &= 0x00FF;
	if ( a == b )	return(1);
	if ((a >= 'a') && ( a <= 'z'))
		a -= ('a' - 'A');
	if ((b >= 'a') && ( b <= 'z'))
		b -= ('a' - 'A');
	if ( a == b )	return(1);
	else		return(0);
}

public	int	detect_hotkey_trigger( char * nptr )
{
	if (!( nptr ))	return(0);

	while ( *nptr ) {
		if ( *nptr == _HOTKEY_TRIGGER )
			return( *(nptr+1) );
		else	nptr++;
		}
	return(0);
}

public	void	check_Widget_trigger( struct  window_control * dptr )
{
	char	*	nptr;
	int		result;
	if (!( widget_can_trigger( dptr ) ))
		return;
	if (!( nptr = dptr->payload ))
		return;

	dptr->trigger = detect_hotkey_trigger( nptr );

	return;

}

public	int	set_Widget_trigger(struct form_item * iptr, int uc )
{
	char *	rptr;
	char *	nptr;
	char *	sptr;
	int	t,i;

	if ((iptr->Contents.style & _FRAME_TYPE) == _LINE_FRAME)
		return;
	if (!( sptr = iptr->Contents.payload ))
		return(0);
	else if (!( rptr = allocate( strlen(sptr) + 2 )))
		return(0);

	for (	t=uc,nptr=rptr; *sptr != 0; sptr++ ) {
		if ( *sptr == t ) {
			*(nptr++) =_HOTKEY_TRIGGER;
			t = 0;
			}
		*(nptr++) = *sptr;
		}

	*nptr = 0;
	liberate( iptr->Contents.payload );
	iptr->Contents.payload = rptr;
	iptr->Contents.size = strlen( rptr );
	return((iptr->Contents.trigger = uc));
}


private	int	add_Widget_trigger(struct form_item * iptr, int c )
{
	int	i;
	int	t;
	int	uc=c;

	if ((c >= 'a') && ( c <= 'z'))
		c -= ('a'-'A');

	else if ( c <= ' ' )
		return(0);

	for (i=0; i < Triggers; i++ )
		if ( c == TriggerMap[i] )
			return(0);


	if (!( set_Widget_trigger( iptr, uc )))
		return(0);
	else	{
		TriggerMap[Triggers++] = c;
		return(uc);
		}
}

private	int	choose_Widget_trigger( struct form_item * iptr )
{
	char	*	nptr;
	int	c;
	if (!( nptr = iptr->Contents.payload ))
		return(0);
	while ( *nptr ) {
		if ((c = *(nptr++)) <= ' ')
			continue;
		else if (!(iptr->Contents.trigger = add_Widget_trigger(iptr,c)))
			continue;
		else	break;
		}
	return( iptr->Contents.trigger );
}

public	int	reset_Widget_trigger( struct form_item * iptr )
{
	char *	rptr;
	char *	nptr;
	char *	sptr;

	if ( iptr->Contents.events->control & _IS_XO_LOCK )
		return(0);

	iptr->Contents.trigger = 0;

	if (!( widget_can_trigger( &iptr->Contents )))
		return(0);
	else if (!( sptr = iptr->Contents.payload ))
		return(0);
	else if (!( rptr = allocate_string( sptr )))
		return(0);
	for (	nptr=rptr; *sptr != 0; sptr++ )
		if ( *sptr != _HOTKEY_TRIGGER )
			*(nptr++) = *sptr;
	*nptr = 0;
	liberate( iptr->Contents.payload );
	iptr->Contents.payload = rptr;
	return(1);
}

public 	int 	calculate_payload_triggers( struct form_control * fptr )
{
	int			p;
	int			i;
	int			c;
	int			uc;
	struct form_item * 	iptr;
	char		 *	nptr;

	if (!( fptr->mimoflags & _MIMO_INTERRUPT ))
		return(0);

	if (!( fptr->pages )) {
		/* Now distribute Page unique trigger values */
		/* ----------------------------------------- */
		TriggerBase=Triggers=0;
		for ( 	Triggers=TriggerBase,
			iptr = fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next ) {
			if ((!( iptr->Contents.w ))
			||  (!( iptr->Contents.w )))
				continue;
			else if ( iptr->Contents.events->control & _IS_XO_LOCK )
				continue;
			else if (!( nptr = iptr->Contents.payload ))
				continue;
			else if ( *nptr == _UNQUOTED_STRING )
				continue;
			else if (!( reset_Widget_trigger( iptr ) ))
				continue;
			else if ( widget_can_trigger( &iptr->Contents ) < 2 )
				continue;
			else if (!( choose_Widget_trigger( iptr ) ))
				return( no_free_triggers( iptr->Contents.name,iptr->Contents.payload ) );
			}
		}
	else	{
		/* Detect and Affect Form Page Components */
		/* -------------------------------------- */
		for ( 	Triggers=0,
			iptr = fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next ) {

			if ((!( iptr->Contents.w ))
			||  (!( iptr->Contents.w )))
				continue;

			else if ( iptr->Contents.events->control & _IS_XO_LOCK )
				continue;

			else if (!( nptr = iptr->Contents.payload ))
				continue;

			else if ( *nptr == _UNQUOTED_STRING )
				continue;

			else if (!( reset_Widget_trigger( iptr ) ))
				continue;

			else if ((iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME ) {
				if (!( choose_Widget_trigger( iptr ) ))
					return( no_free_triggers( iptr->Contents.name,iptr->Contents.payload ) );
				else	continue;
				}
			else if ( iptr->Contents.page )
				continue;
			else if (!( widget_can_trigger( &iptr->Contents )))
				continue;
			else if (!( choose_Widget_trigger( iptr ) ))
				return( no_free_triggers( iptr->Contents.name, iptr->Contents.payload ) );
			}

		/* Now distribute Page unique trigger values */
		/* ----------------------------------------- */
		for (	TriggerBase=Triggers,
			p=1;	p < fptr->pages; p++ ) {
			for ( 	Triggers=TriggerBase,
				iptr = fptr->first;
				iptr != (struct form_item *) 0;
				iptr = iptr->next ) {
				if ((!( iptr->Contents.w ))
				||  (!( iptr->Contents.w )))
					continue;
				else if ( iptr->Contents.events->control & _IS_XO_LOCK )
					continue;
				else if ( iptr->Contents.page != p )
					continue;
				else if (!( nptr = iptr->Contents.payload ))
					continue;
				else if ( *nptr == _UNQUOTED_STRING )
					continue;

				else if ( widget_can_trigger( &iptr->Contents ) < 2 )
					continue;
				else if (!( choose_Widget_trigger( iptr ) ))
					return( no_free_triggers( iptr->Contents.name,iptr->Contents.payload ) );
				}
			}
		}
	return(0);
}

#endif	/* _singtrig_c */

