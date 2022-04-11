#ifndef	_std_event_c
#define	_std_event_c

#include "vncmem.h"
#include "guimouse.h"
#include "stdevent.h"

struct	standard_event	{

	unsigned short	type;
	unsigned short	parameter;
	unsigned short	line;
	unsigned short	column;

	struct standard_event * next;
	struct standard_event * previous;

	};

static	struct standard_event * free_event_queue=(struct standard_event *) 0;
static	struct standard_event * first_event=(struct standard_event *) 0;
static	struct standard_event * last_event=(struct standard_event *) 0;

static	unsigned short		event_mask=ALL_EXCEPT_MOVE;
static	unsigned short		event_mode=False;
static	unsigned short		Buttons=0;

static	int			keyflag=0;
static	unsigned char		keystate[256];
			
struct standard_event * release_event(struct standard_event * eptr)
{
	eptr->next = free_event_queue;
	free_event_queue = eptr;
	return( (struct standard_event *) 0 );
}

struct standard_event * allocate_event()
{
	struct standard_event * eptr;

	if ((eptr = free_event_queue) != (struct standard_event *) 0)
		free_event_queue = eptr->next;
	else if (!(eptr = allocate( sizeof( struct standard_event ))))
		return((struct standard_event *) 0);
	eptr->type = eptr->parameter = eptr->line = eptr->column = 0;
	eptr->next = eptr->previous  = (struct standard_event *) 0;
	return( eptr );
}

void	add_event(struct standard_event * eptr)
{
	if ( verbose )
		printf("adding event\n");
	if (!(eptr->previous = last_event))
		first_event = eptr;
	else	last_event->next = eptr;
	last_event = eptr;
	return;
}

Bool	keyboard_event( int keycode )
{
	struct standard_event * eptr;
	if ( verbose )
		printf("keyboard event  %u \n",keycode);
	if ((eptr = allocate_event()) != (struct standard_event *) 0) {
		eptr->parameter = keycode;
		eptr->line      = eptr->column    = 0;
		eptr->type      = _MIMO_KEYBOARD;
		add_event( eptr );
		return( True );
		}
	else	return( False );
}


Bool	 StandardKeyEvent(int keycode, int state)
{
	int	i;
	if (!( keyflag )) {
		for (i=0; i < 256; i++ ) keystate[i]=0;
		keyflag = 1;
		}

	if (( keycode & 0xFF00 ) == 0xFF00) {
		switch ( keycode ) {
			case	_RFB_INSERT : keycode =_CICO_INSERT; break;
			case	_RFB_DELETE : keycode =_CICO_DELETE; break;
			case	_RFB_DOWN   : keycode =_CICO_DOWN; break;
			case	_RFB_UP     : keycode =_CICO_UP; break;
			case	_RFB_LEFT   : keycode =_CICO_LEFT; break;
			case	_RFB_RIGHT  : keycode =_CICO_RIGHT; break;
			case	_RFB_PUP    : keycode =_CICO_PUP; break;
			case	_RFB_PDOWN  : keycode =_CICO_PDOWN; break;
			case	_RFB_HOME   : keycode =_CICO_HOME; break;
			case	_RFB_END    : keycode =_CICO_END; break;
			case	_RFB_ESC    : keycode =_CICO_ESC; break;
			case	_RFB_TAB    : keycode =_CICO_TAB; break;
			case	_RFB_CR     : keycode =_CICO_CR; break;
			case	_RFB_ALT    :
			case	_RFB_CTRL   :
			case	_RFB_SHIFT  :
				if ( state )
					keyflag |=  (keycode & 0x00FF);
				else	keyflag &= ~(keycode & 0x00FF);
				return( True );
			}
		}

	if ( verbose )
		printf("testing keycode : %u for state %u : %u \n",keycode,state,keystate[(keycode&0x00FF)]);

	if ( keystate[(keycode & 0x00FF)] != state ) {

		keystate[(keycode & 0x00FF)] = state;

		if (!( state )) {
			// Key goes back up
			// ----------------
			if ( keyflag & _RFB_ALT )
				return( True );
			else if (!( keyflag & _RFB_CTRL ))
				return( keyboard_event( keycode ) );
			else if ((keycode >= 'a') &&  (keycode <= 'z'))
				return( keyboard_event( (keycode - 'a') +1 ) );
			else if ((keycode >= 'A') &&  (keycode <= 'Z'))
				return( keyboard_event( (keycode - 'A') +1 ) );
			else	return( keyboard_event( keycode ) );
			}
		}
	return(True);
}

Bool	 StandardPointerEvent(int atx, int aty, int buttons)
{
	int	thisevent=0;
	struct standard_event * eptr;

	if ((( buttons & _MIMO_LEFT  ) &&  (!( Buttons & _MIMO_LEFT  ))) 
	||  (( buttons & _MIMO_RIGHT ) &&  (!( Buttons & _MIMO_RIGHT ))))
		thisevent = _MIMO_DOWN;

	else if (((!( buttons & _MIMO_LEFT  )) &&  ( Buttons & _MIMO_LEFT  )) 
	     ||  ((!( buttons & _MIMO_RIGHT )) &&  ( Buttons & _MIMO_RIGHT )))
		thisevent = _MIMO_UP;

	else if (( buttons & _MIMO_LEFT  ) ||  ( buttons & _MIMO_RIGHT ))
		thisevent = _MIMO_WHILE_DOWN;

	else 	thisevent = _MIMO_MOVE;

	Buttons = buttons;

	if ( event_mask & thisevent ) {

		if ((eptr = allocate_event()) != (struct standard_event *) 0) {
			eptr->parameter = 0;
			eptr->line      = aty;
			eptr->column    = atx;
			switch ((eptr->type = thisevent)) {
				case	_MIMO_MOVE	:
				case	_MIMO_WHILE_DOWN:
				case	_MIMO_DOWN	:
					if ( buttons & _MIMO_LEFT )
						eptr->parameter |= _MIMO_LEFT;
					if ( buttons & _MIMO_RIGHT )
						eptr->parameter |= _MIMO_RIGHT;
					break;

				case	_MIMO_UP	:
					if (!( buttons & _MIMO_LEFT ))
						eptr->parameter |= _MIMO_LEFT;
					if (!( buttons & _MIMO_RIGHT ))
						eptr->parameter |= _MIMO_RIGHT;
					break;

				}
			add_event( eptr );
			}
		}
	return(True);
}

int	MfTestEvent()
{
	if (!( first_event ))
		return(0);
	else	return(1);
}

void	MfWaitEvent( struct standard_event * eptr )
{
	struct standard_event * xptr;

	while (!(xptr = first_event))
		abqt();

	if (!(first_event = first_event->next))
		last_event = first_event;
	else	first_event->previous = (struct standard_event*) 0;

	eptr->type      = xptr->type;
	eptr->parameter = xptr->parameter;
	eptr->line      = xptr->line;
	eptr->column    = xptr->column;

	xptr = release_event( xptr );

	return;

}

int	MfGetMask()
{
	return( event_mask );
}

void	MfSetMask(int v)
{
	event_mask = v;
	return;
}

void	MfShowEvents()
{
	struct standard_event * eptr;
	printf("\nPending Events : \n");
	for (eptr=first_event; eptr != (struct standard_event *) 0; eptr=eptr->next)
		printf("%x : %x : %u,%u \n",
			eptr->type,eptr->parameter,eptr->line,eptr->column);
	return;
}

void	MfFlushEvents()
{
	struct standard_event * eptr;
	while ((eptr=first_event) != (struct standard_event *) 0) {
		first_event = eptr->next;
		release_event( eptr );
		}
	last_event = first_event;
	return;
}


#endif	// _std_event_c
	// ------------









