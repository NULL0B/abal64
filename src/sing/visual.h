#ifndef	_VISUAL_H
#define	_VISUAL_H

#include "allocate.h"

#define	_VISUAL_CHECK	1
#define	_VISUAL_FOCUS	2
#define	_VISUAL_PRESS	4
#define	_VISUAL_EVENT	8
#define	_VISUAL_IMAGE	16
#define	_INHIBIT_FRAME	32
#define	_TRANSPARENT  	64

#ifdef	UNIX_HAS_NO_SELECT
#define	select(a,b,c,d, e,f,g, p, x ) selection(a,b,c,d, e,f,g, p, x )
#endif

#ifndef	private
#define	private	static
#endif

#define	_VISUAL_DLL_ZONE	 0
#define	_VISUAL_DLL_LINE	 1
#define	_VISUAL_DLL_FONT	 2
#define	_VISUAL_DLL_TEXT	 3
#define	_VISUAL_DLL_EDIT 	 4
#define	_VISUAL_DLL_WINDOW	 5
#define	_VISUAL_DLL_BUTTON	 6
#define	_VISUAL_DLL_CHECK	 7
#define	_VISUAL_DLL_RADIO	 8
#define	_VISUAL_DLL_IMAGE	 9
#define	_VISUAL_DLL_TABPAGE	10
#define	_VISUAL_DLL_SELECT 	11
#define	_VISUAL_DLL_SCROLL 	12
#define	_VISUAL_DLL_PALETTE	13
#define	_VISUAL_DLL_INITIALISE	14
#define	_VISUAL_DLL_LIBERATE	15
#define	_VISUAL_DLL_FREEZE	16
#define	_VISUAL_DLL_THAW    	17
#define	_VISUAL_DLL_EVENT   	18
#define	_VISUAL_DLL_FILL    	19
#define	_VISUAL_DLL_KEY     	20
#define	_VISUAL_DLL_CONTROL    	21
#define	_VISUAL_DLL_PROGRESS   	22
#define	_VISUAL_DLL_TABLE   	23

/*	Interface Functions added for Paper Production		*/ 
/*	----------------------------------------------		*/
#define	_VISUAL_DLL_COLOUR	24
#define	_VISUAL_DLL_BUFFER	25
#define	_VISUAL_DLL_PAGE   	26
#define	_VISUAL_DLL_GET   	27
#define	_VISUAL_DLL_GETROW   	28
#define	_VISUAL_DLL_PUTROW   	29
#define	_VISUAL_DLL_PUT   	30
#define	_VISUAL_DLL_DROP   	31
#define	_VISUAL_DLL_TRANSFORM	32
#define	_VISUAL_DLL_PUTZONE	33
#define	_VISUAL_DLL_SWITCH	34
#define	_VISUAL_DLL_GRAPH 	35
#define	_VISUAL_DLL_ACTIVATE	36
#define	_VISUAL_DLL_VIEWPORT	37
#ifdef	_VISUAL_STYLE_MANAGER
#define	_VISUAL_DLL_STYLE 	38
#define	_VISUAL_DLL_FUNCTION	39
#else
#define	_VISUAL_DLL_FUNCTION	38
#endif

#define	public	
#define	private	static

#define	_TRANSFORM_ROTATE	0
#define	_TRANSFORM_REFLECT	1
#define	_TRANSFORM_RESIZE	2
#define	_TRANSFORM_MAKEFIT	3
#define	_TRANSFORM_COLOUR	4

#include "guimouse.h"
#include "vframe.h"
#include "vwidget.h"

#ifdef	_SINGREL_C
#else
#ifdef	_VOBJECT_C
#else
#define	mimo_getch		visual_getch
#define	mimo_kbhit		visual_kbhit
#define	get_mimo_type() 	visual_event(1)
#define	get_mimo_par()  	visual_event(2)
#define	get_mimo_row()  	visual_event(6)
#define	get_mimo_column()	visual_event(7)
#endif
#endif

#ifdef __cplusplus	/* GWB le 05/06/207 */
extern "C" {
#endif

void *	visual_buffer(int,int,int,int);
void *	drop_visual_buffer(void *);

#ifdef __cplusplus	/* GWB le 05/06/207 */
}
#endif

#endif	/* _VISUAL_H */
	/* --------- */









