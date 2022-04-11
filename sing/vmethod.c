
#ifndef _vmethod_c
#define _vmethod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vmethod.sng  */
/* Target         : vmethod.c  */
/* Identification : 0.0-1065019114-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_method_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	focus_pages[3+1];
	int	page_number;
	char	buffer_Identity[54];
	char	buffer_ReturnType[54];
	int	value_Nature;
	char	buffer_Parameters[738];
	char	buffer_Order[1073];
	char	buffer_Body[1207];
	int	value_IsPublic;
	int	value_IsPointer;
	int	value_IsVirtual;
	int	value_IsOverload;
	char	signature[11];
	} * _Context;

private	int	accept_method_create(
	char * pIdentity,
	char * pReturnType,
	char * pNature,
	char * pParameters,
	char * pOrder,
	char * pBody,
	char * pIsPublic,
	char * pIsPointer,
	char * pIsVirtual,
	char * pIsOverload)
{

	if (!(_Context = allocate( sizeof( struct accept_method_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=17;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWSSSWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Identity, 53, pIdentity);
		visual_transferin(_Context->buffer_ReturnType, 53, pReturnType);
		visual_transferin((void *) 0, 0, pNature);
		if (!( pNature )) _Context->value_Nature=0;
		else	_Context->value_Nature = *((int *)pNature);
		visual_transferin(_Context->buffer_Parameters, 737, pParameters);
		visual_transferin(_Context->buffer_Order, 1072, pOrder);
		visual_transferin(_Context->buffer_Body, 1206, pBody);
		visual_transferin((void *) 0, 0, pIsPublic);
		if (!( pIsPublic )) _Context->value_IsPublic=0;
		else	_Context->value_IsPublic = *((int *)pIsPublic);
		visual_transferin((void *) 0, 0, pIsPointer);
		if (!( pIsPointer )) _Context->value_IsPointer=0;
		else	_Context->value_IsPointer = *((int *)pIsPointer);
		visual_transferin((void *) 0, 0, pIsVirtual);
		if (!( pIsVirtual )) _Context->value_IsVirtual=0;
		else	_Context->value_IsVirtual = *((int *)pIsVirtual);
		visual_transferin((void *) 0, 0, pIsOverload);
		if (!( pIsOverload )) _Context->value_IsOverload=0;
		else	_Context->value_IsOverload = *((int *)pIsOverload);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->focus_pages[1]=2;
	_Context->focus_pages[2]=7;
	_Context->focus_pages[3]=9;
	return(0);
}

private	int	accept_method_hide()
{

	return(0);
}

private	int	accept_method_remove(
	char * pIdentity,
	char * pReturnType,
	char * pNature,
	char * pParameters,
	char * pOrder,
	char * pBody,
	char * pIsPublic,
	char * pIsPointer,
	char * pIsVirtual,
	char * pIsOverload)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWSSSWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Identity, 53, pIdentity);
		visual_transferout(_Context->buffer_ReturnType, 53, pReturnType);
		visual_transferout((void *) 0, 0, pNature);
		if ( pNature != (char *) 0)
			*((int*)pNature) = _Context->value_Nature;
		visual_transferout(_Context->buffer_Parameters, 737, pParameters);
		visual_transferout(_Context->buffer_Order, 1072, pOrder);
		visual_transferout(_Context->buffer_Body, 1206, pBody);
		visual_transferout((void *) 0, 0, pIsPublic);
		if ( pIsPublic != (char *) 0)
			*((int*)pIsPublic) = _Context->value_IsPublic;
		visual_transferout((void *) 0, 0, pIsPointer);
		if ( pIsPointer != (char *) 0)
			*((int*)pIsPointer) = _Context->value_IsPointer;
		visual_transferout((void *) 0, 0, pIsVirtual);
		if ( pIsVirtual != (char *) 0)
			*((int*)pIsVirtual) = _Context->value_IsVirtual;
		visual_transferout((void *) 0, 0, pIsOverload);
		if ( pIsOverload != (char *) 0)
			*((int*)pIsOverload) = _Context->value_IsOverload;
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_method_show()
{
	visual_freeze();
	visual_window(110,75,580,450,2,"Sing : Version 1.0a",19,0x0);
	if (_Context->page_number == 1 ) {
	visual_tabpage(120,105,560,370,1,"Head",4,0,2);
	} else {
		visual_tabpage(120,105,560,370,1,"Head",4,0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(130,145,210,16,2,26,0,"Class Method",12,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(130,175,154,16,2,26,0,"Identity",8,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(130,205,154,16,2,26,0,"Return Type",11,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(130,235,154,16,2,26,0,"Nature",6,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(130,265,154,16,2,26,0,"Parameters",10,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(240,175,430+2,16+2,5);
	visual_text(240+1,175+1,430,16,1,26,0,_Context->buffer_Identity,53,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(240,205,430+2,16+2,5);
	visual_text(240+1,205+1,430,16,1,26,0,_Context->buffer_ReturnType,53,0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(240,235,430,50,1,26,0,parse_selection(WidgetMethodNature,&_Context->value_Nature),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(130,285,540+2,180+2,5);
	visual_text(130+1,285+1,540,180,1,26,0,_Context->buffer_Parameters,737,0);
		}
	if (_Context->page_number == 2 ) {
	visual_tabpage(120,105,560,370,1,"Base",4,49,2);
	} else {
		visual_tabpage(120,105,560,370,1,"Base",4,49,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(130,165,518,16,2,27,0,"Base Construction",17,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(130,195,540+2,270+2,5);
	visual_text(130+1,195+1,540,270,1,27,0,_Context->buffer_Order,1072,0);
		}
	if (_Context->page_number == 3 ) {
	visual_tabpage(120,105,560,370,1,"Body",4,98,2);
	} else {
		visual_tabpage(120,105,560,370,1,"Body",4,98,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(130,175,540+2,290+2,5);
	visual_text(130+1,175+1,540,290,1,26,0,_Context->buffer_Body,1206,0);
		}
	visual_button(120,485,100,30,2,26,0,"Accept",6,0);
	visual_button(580,485,100,30,2,26,0,"Cancel",6,0);
	if (_Context->page_number == 3 ) {
	visual_check(130,145,100,32,2,26,0,"Public",6,_Context->value_IsPublic|0);
		}
	if (_Context->page_number == 3 ) {
	visual_check(270,145,100,32,2,26,0,"Pointer",7,_Context->value_IsPointer|0);
		}
	if (_Context->page_number == 3 ) {
	visual_check(410,145,100,32,2,26,0,"Virtual",7,_Context->value_IsVirtual|0);
		}
	if (_Context->page_number == 3 ) {
	visual_check(540,145,100,40,2,26,0,"Overload",8,_Context->value_IsOverload|0);
		}
	visual_button(230,485,100,30,2,26,0,"Editor",6,0);
	visual_thaw(110,75,580,450);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}
private int on_Editer_event() {
	perform_editor(_Context->buffer_Body);
	accept_method_show();
	return(-1);
}


private	int	accept_method_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 120 ) 
		&&  (my >= 105 ) 
		&&  (mx <= 168 ) 
		&&  (my <= 129 )) {
			return(2); /* Head */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 240 ) 
		&&  ( my >= 175 ) 
		&&  ( mx <= 670 ) 
		&&  ( my <= 191 )) {
			return(3); /* Identity */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 240 ) 
		&&  ( my >= 205 ) 
		&&  ( mx <= 670 ) 
		&&  ( my <= 221 )) {
			return(4); /* ReturnType */
		}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 240 ) 
		&&  (my >= 235 ) 
		&&  (mx <= 670 ) 
		&&  (my <= 251 )) {
			return(5); /* Nature */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 130 ) 
		&&  ( my >= 285 ) 
		&&  ( mx <= 670 ) 
		&&  ( my <= 465 )) {
			return(6); /* Parameters */
		}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 169 ) 
		&&  (my >= 105 ) 
		&&  (mx <= 217 ) 
		&&  (my <= 129 )) {
			return(7); /* Base */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 130 ) 
		&&  ( my >= 195 ) 
		&&  ( mx <= 670 ) 
		&&  ( my <= 465 )) {
			return(8); /* Order */
		}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if ((mx >= 218 ) 
		&&  (my >= 105 ) 
		&&  (mx <= 266 ) 
		&&  (my <= 129 )) {
			return(9); /* BodyPage */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 130 ) 
		&&  ( my >= 175 ) 
		&&  ( mx <= 670 ) 
		&&  ( my <= 465 )) {
			return(10); /* Body */
		}
		}
	if (( mx >= 120 ) 
	&&  ( my >= 485 ) 
	&&  ( mx <= 220 ) 
	&&  ( my <= 515 )) {
		return(11); /* Accept */
		}
	if (( mx >= 580 ) 
	&&  ( my >= 485 ) 
	&&  ( mx <= 680 ) 
	&&  ( my <= 515 )) {
		return(12); /* Cancel */
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 130 ) 
		&&  ( my >= 145 ) 
		&&  ( mx <= 230 ) 
		&&  ( my <= 177 )) {
			return(13); /* IsPublic */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 270 ) 
		&&  ( my >= 145 ) 
		&&  ( mx <= 370 ) 
		&&  ( my <= 177 )) {
			return(14); /* IsPointer */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 410 ) 
		&&  ( my >= 145 ) 
		&&  ( mx <= 510 ) 
		&&  ( my <= 177 )) {
			return(15); /* IsVirtual */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 540 ) 
		&&  ( my >= 145 ) 
		&&  ( mx <= 640 ) 
		&&  ( my <= 185 )) {
			return(16); /* IsOverload */
		}
		}
	if (( mx >= 230 ) 
	&&  ( my >= 485 ) 
	&&  ( mx <= 330 ) 
	&&  ( my <= 515 )) {
		return(17); /* Editer */
		}

	return(-1);
}


private	int	accept_method_losefocus()
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;
		case 3 : 
			break;

		}
	return(0);

}


private	int	accept_method_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Head */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* Identity */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(240+1,175+1,430,16,1,_Context->buffer_Identity,53);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* ReturnType */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(240+1,205+1,430,16,1,_Context->buffer_ReturnType,53);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* Nature */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(240,235,430,50,1,26,0,parse_selection(WidgetMethodNature,&_Context->value_Nature),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* Parameters */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(130+1,285+1,540,180,1,_Context->buffer_Parameters,737);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* Base */
				if (_Context->page_number == 2 ) {
					if(_Context->value_Nature==0){
					_Context->keycode=0x0003;
					}
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x8 :
				/* Order */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(130+1,195+1,540,270,1,_Context->buffer_Order,1072);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* BodyPage */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xa :
				/* Body */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(130+1,175+1,540,290,1,_Context->buffer_Body,1206);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* Accept */
				visual_button(120,485,100,30,2,26,0,"Accept",6,2);
				_Context->keycode = visual_getch();
				visual_button(120,485,100,30,2,26,0,"Accept",6,0);
				break;
			case	0xc :
				/* Cancel */
				visual_button(580,485,100,30,2,26,0,"Cancel",6,2);
				_Context->keycode = visual_getch();
				visual_button(580,485,100,30,2,26,0,"Cancel",6,0);
				break;
			case	0xd :
				/* IsPublic */
				if (_Context->page_number == 3 ) {
				visual_check(130,145,100,32,2,26,0,"Public",6,(_Context->value_IsPublic |2));
					_Context->keycode = visual_getch();
				visual_check(130,145,100,32,2,26,0,"Public",6,(_Context->value_IsPublic |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* IsPointer */
				if (_Context->page_number == 3 ) {
				visual_check(270,145,100,32,2,26,0,"Pointer",7,(_Context->value_IsPointer |2));
					_Context->keycode = visual_getch();
				visual_check(270,145,100,32,2,26,0,"Pointer",7,(_Context->value_IsPointer |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* IsVirtual */
				if (_Context->page_number == 3 ) {
				visual_check(410,145,100,32,2,26,0,"Virtual",7,(_Context->value_IsVirtual |2));
					_Context->keycode = visual_getch();
				visual_check(410,145,100,32,2,26,0,"Virtual",7,(_Context->value_IsVirtual |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* IsOverload */
				if (_Context->page_number == 3 ) {
				visual_check(540,145,100,40,2,26,0,"Overload",8,(_Context->value_IsOverload |2));
					_Context->keycode = visual_getch();
				visual_check(540,145,100,40,2,26,0,"Overload",8,(_Context->value_IsOverload |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* Editer */
				visual_button(230,485,100,30,2,26,0,"Editor",6,2);
				_Context->keycode = visual_getch();
				visual_button(230,485,100,30,2,26,0,"Editor",6,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			accept_method_losefocus();
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_method_show();
			continue;
		case	0x2 :
			accept_method_losefocus();
			_Context->page_number=3;
			_Context->focus_item=17;
			accept_method_show();
			continue;
		case	0x3 :
			accept_method_losefocus();
			if ( _Context->page_number < 3 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_method_show();
			continue;
		case	0x12 :
			accept_method_losefocus();
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_method_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_method_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Window */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Head */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_method_losefocus();
							_Context->page_number = 1;
							accept_method_show();
							}
						continue;
					case	0x3 :
						/* Identity */
						continue;
					case	0x4 :
						/* ReturnType */
						continue;
					case	0x5 :
						/* Nature */
						continue;
					case	0x6 :
						/* Parameters */
						continue;
					case	0x7 :
						/* Base */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_method_losefocus();
							_Context->page_number = 2;
							accept_method_show();
							}
						continue;
					case	0x8 :
						/* Order */
						continue;
					case	0x9 :
						/* BodyPage */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_method_losefocus();
							_Context->page_number = 3;
							accept_method_show();
							}
						continue;
					case	0xa :
						/* Body */
						continue;
					case	0xb :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(120,485,100,30,2,26,0,"Accept",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(120,485,100,30,2,26,0,"Accept",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0xc :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(580,485,100,30,2,26,0,"Cancel",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(580,485,100,30,2,26,0,"Cancel",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0xd :
						/* IsPublic */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsPublic += 1;
							_Context->value_IsPublic &= 1;
							}
						continue;
					case	0xe :
						/* IsPointer */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsPointer += 1;
							_Context->value_IsPointer &= 1;
							}
						continue;
					case	0xf :
						/* IsVirtual */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsVirtual += 1;
							_Context->value_IsVirtual &= 1;
							}
						continue;
					case	0x10 :
						/* IsOverload */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsOverload += 1;
							_Context->value_IsOverload &= 1;
							}
						continue;
					case	0x11 :
						/* Editer */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(230,485,100,30,2,26,0,"Editor",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(230,485,100,30,2,26,0,"Editor",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Editer_event()) != -1) break;

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
				_Context->focus_item=17;
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

public	int	accept_method(
	char * pIdentity,
	char * pReturnType,
	char * pNature,
	char * pParameters,
	char * pOrder,
	char * pBody,
	char * pIsPublic,
	char * pIsPointer,
	char * pIsVirtual,
	char * pIsOverload)
{
	int	status=0;
	status = accept_method_create(
	 pIdentity,
	 pReturnType,
	 pNature,
	 pParameters,
	 pOrder,
	 pBody,
	 pIsPublic,
	 pIsPointer,
	 pIsVirtual,
	 pIsOverload);
	if ( status != 0) return(status);
	status = accept_method_show();
		enter_modal();
	status = accept_method_focus();
		leave_modal();
	status = accept_method_hide();
	status = accept_method_remove(
	 pIdentity,
	 pReturnType,
	 pNature,
	 pParameters,
	 pOrder,
	 pBody,
	 pIsPublic,
	 pIsPointer,
	 pIsVirtual,
	 pIsOverload);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vmethod_c */
