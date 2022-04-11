
#ifndef _vpragma_c
#define _vpragma_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vpragma.sng  */
/* Target         : vpragma.c  */
/* Identification : 0.0-1065019114-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_pragmas_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_Auto1244[4];
	int	value_IgnoreCase;
	int	value_EnhancedIndirect;
	int	value_OptimiseTables;
	char	signature[5];
	} * _Context;

private	int	accept_pragmas_create(
	char * pAuto1244,
	char * pIgnoreCase,
	char * pEnhancedIndirect,
	char * pOptimiseTables)
{

	if (!(_Context = allocate( sizeof( struct accept_pragmas_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=5;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Auto1244, 3, pAuto1244);
		visual_transferin((void *) 0, 0, pIgnoreCase);
		if (!( pIgnoreCase )) _Context->value_IgnoreCase=0;
		else	_Context->value_IgnoreCase = *((int *)pIgnoreCase);
		visual_transferin((void *) 0, 0, pEnhancedIndirect);
		if (!( pEnhancedIndirect )) _Context->value_EnhancedIndirect=0;
		else	_Context->value_EnhancedIndirect = *((int *)pEnhancedIndirect);
		visual_transferin((void *) 0, 0, pOptimiseTables);
		if (!( pOptimiseTables )) _Context->value_OptimiseTables=0;
		else	_Context->value_OptimiseTables = *((int *)pOptimiseTables);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	return(0);
}

private	int	accept_pragmas_hide()
{

	return(0);
}

private	int	accept_pragmas_remove(
	char * pAuto1244,
	char * pIgnoreCase,
	char * pEnhancedIndirect,
	char * pOptimiseTables)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Auto1244, 3, pAuto1244);
		visual_transferout((void *) 0, 0, pIgnoreCase);
		if ( pIgnoreCase != (char *) 0)
			*((int*)pIgnoreCase) = _Context->value_IgnoreCase;
		visual_transferout((void *) 0, 0, pEnhancedIndirect);
		if ( pEnhancedIndirect != (char *) 0)
			*((int*)pEnhancedIndirect) = _Context->value_EnhancedIndirect;
		visual_transferout((void *) 0, 0, pOptimiseTables);
		if ( pOptimiseTables != (char *) 0)
			*((int*)pOptimiseTables) = _Context->value_OptimiseTables;
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_pragmas_show()
{
	visual_freeze();
	visual_window(180,210,440,180,2,"Sing : Version 1.0a",19,0x0);
	visual_image(186,234,431,153,VisualSkin,4);
	visual_text(197,243,403,16,2,16,0,"Object Translator Pragmas",25,2);
	visual_frame(197,259,403,114,4);
	visual_text(260,280,88,20,2,27,0,"Token Size",10,3);
	visual_frame(220,280,42+2,16+2,5);
	visual_text(220+1,280+1,42,16,2,27,28,_Context->buffer_Auto1244,3,0);
	visual_check(390,280,140,16,2,27,28,"&Ignore Case",12,_Context->value_IgnoreCase|0);
	visual_check(230,330,154,16,2,27,28,"&Enhanced Indirect",18,_Context->value_EnhancedIndirect|0);
	visual_check(390,330,154,16,2,16,28,"&Optimise Tables",16,_Context->value_OptimiseTables|0);
	visual_thaw(180,210,440,180);

	return(0);
}


private	int	accept_pragmas_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 220 ) 
	&&  ( my >= 280 ) 
	&&  ( mx <= 262 ) 
	&&  ( my <= 296 )) {
		return(2); /* Auto1244 */
		}
	if (( mx >= 390 ) 
	&&  ( my >= 280 ) 
	&&  ( mx <= 530 ) 
	&&  ( my <= 296 )) {
		return(3); /* IgnoreCase */
		}
	if (( mx >= 230 ) 
	&&  ( my >= 330 ) 
	&&  ( mx <= 384 ) 
	&&  ( my <= 346 )) {
		return(4); /* EnhancedIndirect */
		}
	if (( mx >= 390 ) 
	&&  ( my >= 330 ) 
	&&  ( mx <= 544 ) 
	&&  ( my <= 346 )) {
		return(5); /* OptimiseTables */
		}

	return(-1);
}


private	int	accept_pragmas_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto1244 */
				_Context->keycode = visual_edit(220+1,280+1,42,16,2,_Context->buffer_Auto1244,3);
				break;
			case	0x3 :
				/* IgnoreCase */
				visual_check(390,280,140,16,2,27,28,"&Ignore Case",12,(_Context->value_IgnoreCase |2));
				_Context->keycode = visual_getch();
				visual_check(390,280,140,16,2,27,28,"&Ignore Case",12,(_Context->value_IgnoreCase |0));
				break;
			case	0x4 :
				/* EnhancedIndirect */
				visual_check(230,330,154,16,2,27,28,"&Enhanced Indirect",18,(_Context->value_EnhancedIndirect |2));
				_Context->keycode = visual_getch();
				visual_check(230,330,154,16,2,27,28,"&Enhanced Indirect",18,(_Context->value_EnhancedIndirect |0));
				break;
			case	0x5 :
				/* OptimiseTables */
				visual_check(390,330,154,16,2,16,28,"&Optimise Tables",16,(_Context->value_OptimiseTables |2));
				_Context->keycode = visual_getch();
				visual_check(390,330,154,16,2,16,28,"&Optimise Tables",16,(_Context->value_OptimiseTables |0));
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_pragmas_show();
			continue;
		case	0x2 :
			_Context->focus_item=5;
			accept_pragmas_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_pragmas_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1240 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Auto1244 */
						continue;
					case	0x3 :
						/* IgnoreCase */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IgnoreCase += 1;
							_Context->value_IgnoreCase &= 1;
							}
						continue;
					case	0x4 :
						/* EnhancedIndirect */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_EnhancedIndirect += 1;
							_Context->value_EnhancedIndirect &= 1;
							}
						continue;
					case	0x5 :
						/* OptimiseTables */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_OptimiseTables += 1;
							_Context->value_OptimiseTables &= 1;
							}
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
				_Context->focus_item=5;
			}
			continue;
		case 0x849 : 
		case 0x869 : 
		/* IgnoreCase */
		_Context->value_IgnoreCase += 1;
		_Context->value_IgnoreCase &= 1;
		_Context->focus_item=3;
		continue;
		case 0x845 : 
		case 0x865 : 
		/* EnhancedIndirect */
		_Context->value_EnhancedIndirect += 1;
		_Context->value_EnhancedIndirect &= 1;
		_Context->focus_item=4;
		continue;
		case 0x84f : 
		case 0x86f : 
		/* OptimiseTables */
		_Context->value_OptimiseTables += 1;
		_Context->value_OptimiseTables &= 1;
		_Context->focus_item=5;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_pragmas(
	char * pAuto1244,
	char * pIgnoreCase,
	char * pEnhancedIndirect,
	char * pOptimiseTables)
{
	int	status=0;
	status = accept_pragmas_create(
	 pAuto1244,
	 pIgnoreCase,
	 pEnhancedIndirect,
	 pOptimiseTables);
	if ( status != 0) return(status);
	status = accept_pragmas_show();
		enter_modal();
	status = accept_pragmas_focus();
		leave_modal();
	status = accept_pragmas_hide();
	status = accept_pragmas_remove(
	 pAuto1244,
	 pIgnoreCase,
	 pEnhancedIndirect,
	 pOptimiseTables);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vpragma_c */
