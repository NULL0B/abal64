#ifndef	_SING_EVENT_H
#define	_SING_EVENT_H

/*	This value indicates SNG file contains extended events 	*/


struct	event_control	{
	int	control;
	int	mimo;			/* mimo control word */
	void *	on_create;
	int	xo_create;
	void *	on_remove;
	int	xo_remove;
	void *	on_show;
	int	xo_show;
	void *	on_hide;
	int	xo_hide;
	void *	on_get_focus;
	int	xo_get_focus;
	void *	on_lose_focus;
	int	xo_lose_focus;
	void *	on_event;
	int	xo_event;
	};

/*	Event Method Preseence flags	*/
#define	_IS_ON_CREATE	0x0001
#define	_IS_ON_REMOVE	0x0002
#define	_IS_ON_SHOW  	0x0004
#define	_IS_ON_HIDE  	0x0008
#define	_IS_ON_FOCUS  	0x0010
#define	_IS_ON_LOSE  	0x0020
#define	_IS_ON_EVENT 	0x0040
#define	_IS_ON_MOUSE 	0x0080	/* indicates specialised mouse events */

/*	Event Option Presence flags	*/
#define	_IS_XO_CREATE	0x0100
#define	_IS_XO_REMOVE	0x0200
#define	_IS_XO_SHOW  	0x0400
#define	_IS_XO_HIDE  	0x0800
#define	_IS_XO_FOCUS  	0x1000
#define	_IS_XO_LOSE  	0x2000
#define	_IS_XO_EVENT 	0x4000

#define	_IS_XO_LOCK   	0x8000

#define	_ALL_XO_EVENTS	(_IS_XO_CREATE | _IS_XO_REMOVE | _IS_XO_SHOW | _IS_XO_HIDE | _IS_XO_FOCUS | _IS_XO_LOSE | _IS_XO_EVENT )

/*	Event Extension Bit Fields	*/
#define	_EVENT_IS_FOCUS   	0x0001	/* for on focus methods 	*/
#define	_EVENT_IS_COND   	0x0001	/* for on show methods		*/
#define	_EVENT_IS_POP   	0x0001	/* for on hide methods		*/
#define	_EVENT_IS_FUNCTION	0x0002


/*	Predefined types compatible with the EventTypeList 	*/
/*	defined in VWIDGET.H					*/

#define	_INLINE_NOT_FOCUS	0
#define	_INLINE_AND_FOCUS	_EVENT_IS_FOCUS
#define	_FUNCTION_NOT_FOCUS	_EVENT_IS_FUNCTION
#define	_FUNCTION_AND_FOCUS	(_EVENT_IS_FOCUS | _EVENT_IS_FUNCTION)

public 	void 	reset_event_control(struct event_control * eptr,int type);
public 	void 	reset_extended_events(struct event_control * eptr,int type);
public	void	perform_event_control( struct event_control * eptr );

#endif	/* _SING_EVENT_H */


