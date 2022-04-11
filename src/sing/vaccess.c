
#ifndef _vaccess_c
#define _vaccess_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vaccess.sng  */
/* Target         : vaccess.c  */
/* Identification : 0.0-1065019114-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct visual_access_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	value_Auto482;
	int	value_Auto483;
	int	value_Auto484;
	int	value_Auto485;
	int	value_Auto486;
	int	value_Auto487;
	int	value_Auto488;
	int	value_Auto489;
	int	value_Auto490;
	char	signature[10];
	} * _Context;

private	int	visual_access_create(
	char * pAuto482,
	char * pAuto483,
	char * pAuto484,
	char * pAuto485,
	char * pAuto486,
	char * pAuto487,
	char * pAuto488,
	char * pAuto489,
	char * pAuto490)
{

	if (!(_Context = allocate( sizeof( struct visual_access_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=10;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pAuto482);
		if (!( pAuto482 )) _Context->value_Auto482=0;
		else	_Context->value_Auto482 = *((int *)pAuto482);
		visual_transferin((void *) 0, 0, pAuto483);
		if (!( pAuto483 )) _Context->value_Auto483=0;
		else	_Context->value_Auto483 = *((int *)pAuto483);
		visual_transferin((void *) 0, 0, pAuto484);
		if (!( pAuto484 )) _Context->value_Auto484=0;
		else	_Context->value_Auto484 = *((int *)pAuto484);
		visual_transferin((void *) 0, 0, pAuto485);
		if (!( pAuto485 )) _Context->value_Auto485=0;
		else	_Context->value_Auto485 = *((int *)pAuto485);
		visual_transferin((void *) 0, 0, pAuto486);
		if (!( pAuto486 )) _Context->value_Auto486=0;
		else	_Context->value_Auto486 = *((int *)pAuto486);
		visual_transferin((void *) 0, 0, pAuto487);
		if (!( pAuto487 )) _Context->value_Auto487=0;
		else	_Context->value_Auto487 = *((int *)pAuto487);
		visual_transferin((void *) 0, 0, pAuto488);
		if (!( pAuto488 )) _Context->value_Auto488=0;
		else	_Context->value_Auto488 = *((int *)pAuto488);
		visual_transferin((void *) 0, 0, pAuto489);
		if (!( pAuto489 )) _Context->value_Auto489=0;
		else	_Context->value_Auto489 = *((int *)pAuto489);
		visual_transferin((void *) 0, 0, pAuto490);
		if (!( pAuto490 )) _Context->value_Auto490=0;
		else	_Context->value_Auto490 = *((int *)pAuto490);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	return(0);
}

private	int	visual_access_hide()
{

	return(0);
}

private	int	visual_access_remove(
	char * pAuto482,
	char * pAuto483,
	char * pAuto484,
	char * pAuto485,
	char * pAuto486,
	char * pAuto487,
	char * pAuto488,
	char * pAuto489,
	char * pAuto490)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pAuto482);
		if ( pAuto482 != (char *) 0)
			*((int*)pAuto482) = _Context->value_Auto482;
		visual_transferout((void *) 0, 0, pAuto483);
		if ( pAuto483 != (char *) 0)
			*((int*)pAuto483) = _Context->value_Auto483;
		visual_transferout((void *) 0, 0, pAuto484);
		if ( pAuto484 != (char *) 0)
			*((int*)pAuto484) = _Context->value_Auto484;
		visual_transferout((void *) 0, 0, pAuto485);
		if ( pAuto485 != (char *) 0)
			*((int*)pAuto485) = _Context->value_Auto485;
		visual_transferout((void *) 0, 0, pAuto486);
		if ( pAuto486 != (char *) 0)
			*((int*)pAuto486) = _Context->value_Auto486;
		visual_transferout((void *) 0, 0, pAuto487);
		if ( pAuto487 != (char *) 0)
			*((int*)pAuto487) = _Context->value_Auto487;
		visual_transferout((void *) 0, 0, pAuto488);
		if ( pAuto488 != (char *) 0)
			*((int*)pAuto488) = _Context->value_Auto488;
		visual_transferout((void *) 0, 0, pAuto489);
		if ( pAuto489 != (char *) 0)
			*((int*)pAuto489) = _Context->value_Auto489;
		visual_transferout((void *) 0, 0, pAuto490);
		if ( pAuto490 != (char *) 0)
			*((int*)pAuto490) = _Context->value_Auto490;
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	visual_access_show()
{
	visual_freeze();
	visual_window(238,126,324,348,2,"Sing : Version 1.0a",19,0x0);
	visual_text(250,150,300,20,2,27,0,"File Method Types",17,259);
	visual_frame(250,170,300,288,4);
	visual_select(442,190,88,28,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto482),768);
	visual_select(442,218,88,32,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto483),768);
	visual_text(266,190,172,20,2,27,0,"OnCreate",8,2);
	visual_text(266,218,172,20,2,27,0,"OnLocate",8,2);
	visual_text(266,246,172,24,2,27,0,"OnUpdate",8,2);
	visual_select(442,246,88,28,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto484),768);
	visual_select(442,274,88,28,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto485),768);
	visual_select(442,302,88,28,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto486),768);
	visual_select(442,330,88,28,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto487),768);
	visual_select(442,358,88,28,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto488),768);
	visual_select(442,386,88,28,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto489),768);
	visual_select(442,414,88,36,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto490),768);
	visual_text(266,274,172,24,2,27,0,"OnDelete",8,2);
	visual_text(266,302,172,24,2,27,0,"OnFirst",7,2);
	visual_text(266,330,172,24,2,27,0,"OnNext",6,2);
	visual_text(266,358,172,24,2,27,0,"OnPrevious",10,2);
	visual_text(266,386,172,24,2,27,0,"OnLast",6,2);
	visual_text(266,414,172,24,2,27,0,"OnRemove",8,2);
	visual_thaw(238,126,324,348);

	return(0);
}


private	int	visual_access_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 442 ) 
	&&  (my >= 190 ) 
	&&  (mx <= 530 ) 
	&&  (my <= 206 )) {
		return(2); /* Auto482 */
		}
	if ((mx >= 442 ) 
	&&  (my >= 218 ) 
	&&  (mx <= 530 ) 
	&&  (my <= 234 )) {
		return(3); /* Auto483 */
		}
	if ((mx >= 442 ) 
	&&  (my >= 246 ) 
	&&  (mx <= 530 ) 
	&&  (my <= 262 )) {
		return(4); /* Auto484 */
		}
	if ((mx >= 442 ) 
	&&  (my >= 274 ) 
	&&  (mx <= 530 ) 
	&&  (my <= 290 )) {
		return(5); /* Auto485 */
		}
	if ((mx >= 442 ) 
	&&  (my >= 302 ) 
	&&  (mx <= 530 ) 
	&&  (my <= 318 )) {
		return(6); /* Auto486 */
		}
	if ((mx >= 442 ) 
	&&  (my >= 330 ) 
	&&  (mx <= 530 ) 
	&&  (my <= 346 )) {
		return(7); /* Auto487 */
		}
	if ((mx >= 442 ) 
	&&  (my >= 358 ) 
	&&  (mx <= 530 ) 
	&&  (my <= 374 )) {
		return(8); /* Auto488 */
		}
	if ((mx >= 442 ) 
	&&  (my >= 386 ) 
	&&  (mx <= 530 ) 
	&&  (my <= 402 )) {
		return(9); /* Auto489 */
		}
	if ((mx >= 442 ) 
	&&  (my >= 414 ) 
	&&  (mx <= 530 ) 
	&&  (my <= 430 )) {
		return(10); /* Auto490 */
		}

	return(-1);
}


private	int	visual_access_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto482 */
				_Context->keycode = visual_select(442,190,88,28,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto482),770);
				break;
			case	0x3 :
				/* Auto483 */
				_Context->keycode = visual_select(442,218,88,32,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto483),770);
				break;
			case	0x4 :
				/* Auto484 */
				_Context->keycode = visual_select(442,246,88,28,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto484),770);
				break;
			case	0x5 :
				/* Auto485 */
				_Context->keycode = visual_select(442,274,88,28,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto485),770);
				break;
			case	0x6 :
				/* Auto486 */
				_Context->keycode = visual_select(442,302,88,28,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto486),770);
				break;
			case	0x7 :
				/* Auto487 */
				_Context->keycode = visual_select(442,330,88,28,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto487),770);
				break;
			case	0x8 :
				/* Auto488 */
				_Context->keycode = visual_select(442,358,88,28,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto488),770);
				break;
			case	0x9 :
				/* Auto489 */
				_Context->keycode = visual_select(442,386,88,28,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto489),770);
				break;
			case	0xa :
				/* Auto490 */
				_Context->keycode = visual_select(442,414,88,36,1,27,19,parse_selection("Function|Inline",&_Context->value_Auto490),770);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			visual_access_show();
			continue;
		case	0x2 :
			_Context->focus_item=10;
			visual_access_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=visual_access_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto468 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Auto482 */
						continue;
					case	0x3 :
						/* Auto483 */
						continue;
					case	0x4 :
						/* Auto484 */
						continue;
					case	0x5 :
						/* Auto485 */
						continue;
					case	0x6 :
						/* Auto486 */
						continue;
					case	0x7 :
						/* Auto487 */
						continue;
					case	0x8 :
						/* Auto488 */
						continue;
					case	0x9 :
						/* Auto489 */
						continue;
					case	0xa :
						/* Auto490 */
						continue;
					case	0xffffffff :
					default :
						_Context->focus_item=1;
					continue;
					}
				break;
			case	0x1b :
			case	0xd :
				break;
			case	0x9 :
			case	0x5 :
			if ( _Context->focus_item < _Context->focus_items ) {
				_Context->focus_item++;			} else {
				_Context->focus_item=1;
			}
			continue;
			case	0xb :
			if ( _Context->focus_item > 1 ) {
				_Context->focus_item--;
			} else {
				_Context->focus_item=10;
			}
			continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	visual_access(
	char * pAuto482,
	char * pAuto483,
	char * pAuto484,
	char * pAuto485,
	char * pAuto486,
	char * pAuto487,
	char * pAuto488,
	char * pAuto489,
	char * pAuto490)
{
	int	status=0;
	status = visual_access_create(
	 pAuto482,
	 pAuto483,
	 pAuto484,
	 pAuto485,
	 pAuto486,
	 pAuto487,
	 pAuto488,
	 pAuto489,
	 pAuto490);
	if ( status != 0) return(status);
	status = visual_access_show();
		enter_modal();
	status = visual_access_focus();
		leave_modal();
	status = visual_access_hide();
	status = visual_access_remove(
	 pAuto482,
	 pAuto483,
	 pAuto484,
	 pAuto485,
	 pAuto486,
	 pAuto487,
	 pAuto488,
	 pAuto489,
	 pAuto490);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vaccess_c */
