
#ifndef _vcompose_c
#define _vcompose_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vcompose.sng  */
/* Target         : vcompose.c  */
/* Identification : 0.0-1065019002-2581.2580 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_form_syntax_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_Result[435];
	int	value_ClassList;
	int	value_WidgetList;
	int	value_MethodList;
	int	value_Concatenate;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[6];
	} * _Context;

private	int	accept_form_syntax_create(
	char * pResult,
	char * pClassList,
	char * pWidgetList,
	char * pMethodList,
	char * pConcatenate)
{

	if (!(_Context = allocate( sizeof( struct accept_form_syntax_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=9;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Result, 434, pResult);
		visual_transferin((void *) 0, 0, pClassList);
		if (!( pClassList )) _Context->value_ClassList=0;
		else	_Context->value_ClassList = *((int *)pClassList);
		visual_transferin((void *) 0, 0, pWidgetList);
		if (!( pWidgetList )) _Context->value_WidgetList=0;
		else	_Context->value_WidgetList = *((int *)pWidgetList);
		visual_transferin((void *) 0, 0, pMethodList);
		if (!( pMethodList )) _Context->value_MethodList=0;
		else	_Context->value_MethodList = *((int *)pMethodList);
		visual_transferin((void *) 0, 0, pConcatenate);
		if (!( pConcatenate )) _Context->value_Concatenate=0;
		else	_Context->value_Concatenate = *((int *)pConcatenate);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->value_ClassList=5;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(130,140,540+10,320+10);
	return(0);
}

private	int	accept_form_syntax_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,130,140);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_form_syntax_remove(
	char * pResult,
	char * pClassList,
	char * pWidgetList,
	char * pMethodList,
	char * pConcatenate)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Result, 434, pResult);
		visual_transferout((void *) 0, 0, pClassList);
		if ( pClassList != (char *) 0)
			*((int*)pClassList) = _Context->value_ClassList;
		visual_transferout((void *) 0, 0, pWidgetList);
		if ( pWidgetList != (char *) 0)
			*((int*)pWidgetList) = _Context->value_WidgetList;
		visual_transferout((void *) 0, 0, pMethodList);
		if ( pMethodList != (char *) 0)
			*((int*)pMethodList) = _Context->value_MethodList;
		visual_transferout((void *) 0, 0, pConcatenate);
		if ( pConcatenate != (char *) 0)
			*((int*)pConcatenate) = _Context->value_Concatenate;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_form_syntax_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,130,140);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(130,140,540,320,1,"Sing : Version 1.0a",19,0x403);
	visual_image(133,161,532,294,"skin.gif",4);
	visual_text(140,170,520,20,3,16,0,"Widget Syntax Composer",22,1283);
	visual_frame(140,190,520,260,3);
	visual_text(150,240,500,40,2,16,0,"Result Syntax",13,1283);
	visual_frame(150,280,500+2,120+2,5);
	visual_text(150+1,280+1,500,120,1,16,0,_Context->buffer_Result,434,0);
	visual_select(150,200,160,208,1,27,28,parse_selection(WidgetClassList,&_Context->value_ClassList),768);
	visual_select(320,200,160,208,1,27,28,parse_selection(FormWidgetList(_Context->value_ClassList),&_Context->value_WidgetList),768);
	visual_select(490,200,160,200,1,27,28,parse_selection(FormMethodList(_Context->value_WidgetList),&_Context->value_MethodList),768);
	visual_check(400,410,140,32,2,28,28,"Concatentate",12,_Context->value_Concatenate|0);
	visual_button(150,410,84,32,2,16,0,"&Accept",7,0);
	visual_button(290,410,84,32,2,16,0,"Co&mpose",8,0);
	visual_button(570,410,84,32,2,16,0,"&Cancel",7,0);
	visual_thaw(130,140,540,320);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Compose_event() {
	FormWidgetCompose(_Context->value_ClassList,_Context->value_WidgetList,_Context->value_MethodList,
	_Context->buffer_Result,434,_Context->value_Concatenate);
	visual_frame(150,280,500+2,120+2,5);
visual_text(150+1,280+1,500,120,1,16,0,_Context->buffer_Result,434,0);
;
	_Context->value_Concatenate=1;
		visual_check(400,410,140,32,2,28,28,"Concatentate",12,_Context->value_Concatenate|0);
;
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	accept_form_syntax_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 649 )  
	&&  (my >= 144 )  
	&&  (mx <= 665 )  
	&&  (my <= 160 )) {
		return(1);	/* Auto5287 */

		}
	if ((mx >= 633 )  
	&&  (my >= 144 )  
	&&  (mx <= 649 )  
	&&  (my <= 160 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcompose.htm");
			};
		return(-1);	/* Auto5287 */

		}
	if (( mx >= 150 ) 
	&&  ( my >= 280 ) 
	&&  ( mx <= 650 ) 
	&&  ( my <= 400 )) {
		return(2); /* Result */
		}
	if ((mx >= 150 ) 
	&&  (my >= 200 ) 
	&&  (mx <= 310 ) 
	&&  (my <= 216 )) {
		return(3); /* ClassList */
		}
	if ((mx >= 320 ) 
	&&  (my >= 200 ) 
	&&  (mx <= 480 ) 
	&&  (my <= 216 )) {
		return(4); /* WidgetList */
		}
	if ((mx >= 490 ) 
	&&  (my >= 200 ) 
	&&  (mx <= 650 ) 
	&&  (my <= 216 )) {
		return(5); /* MethodList */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 410 ) 
	&&  ( mx <= 540 ) 
	&&  ( my <= 442 )) {
		return(6); /* Concatenate */
		}
	if (( mx >= 150 ) 
	&&  ( my >= 410 ) 
	&&  ( mx <= 234 ) 
	&&  ( my <= 442 )) {
		return(7); /* Accept */
		}
	if (( mx >= 290 ) 
	&&  ( my >= 410 ) 
	&&  ( mx <= 374 ) 
	&&  ( my <= 442 )) {
		return(8); /* Compose */
		}
	if (( mx >= 570 ) 
	&&  ( my >= 410 ) 
	&&  ( mx <= 654 ) 
	&&  ( my <= 442 )) {
		return(9); /* Cancel */
		}

	return(-1);
}


private	int	accept_form_syntax_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Result */
				_Context->keycode = visual_edit(150+1,280+1,500,120,1,_Context->buffer_Result,434);
				break;
			case	0x3 :
				/* ClassList */
				_Context->keycode = visual_select(150,200,160,208,1,27,28,parse_selection(WidgetClassList,&_Context->value_ClassList),770);
				break;
			case	0x4 :
				/* WidgetList */
				_Context->keycode = visual_select(320,200,160,208,1,27,28,parse_selection(FormWidgetList(_Context->value_ClassList),&_Context->value_WidgetList),770);
				break;
			case	0x5 :
				/* MethodList */
				_Context->keycode = visual_select(490,200,160,200,1,27,28,parse_selection(FormMethodList(_Context->value_WidgetList),&_Context->value_MethodList),770);
				break;
			case	0x6 :
				/* Concatenate */
				visual_check(400,410,140,32,2,28,28,"Concatentate",12,(_Context->value_Concatenate |2));
				_Context->keycode = visual_getch();
				visual_check(400,410,140,32,2,28,28,"Concatentate",12,(_Context->value_Concatenate |0));
				break;
			case	0x7 :
				/* Accept */
				visual_button(150,410,84,32,2,16,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(150,410,84,32,2,16,0,"&Accept",7,0);
				break;
			case	0x8 :
				/* Compose */
				visual_button(290,410,84,32,2,16,0,"Co&mpose",8,2);
				_Context->keycode = visual_getch();
				visual_button(290,410,84,32,2,16,0,"Co&mpose",8,0);
				break;
			case	0x9 :
				/* Cancel */
				visual_button(570,410,84,32,2,16,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(570,410,84,32,2,16,0,"&Cancel",7,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_form_syntax_show();
			continue;
		case	0x2 :
			_Context->focus_item=9;
			accept_form_syntax_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_form_syntax_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto5287 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Result */
						continue;
					case	0x3 :
						/* ClassList */
						continue;
					case	0x4 :
						/* WidgetList */
						continue;
					case	0x5 :
						/* MethodList */
						continue;
					case	0x6 :
						/* Concatenate */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Concatenate += 1;
							_Context->value_Concatenate &= 1;
							}
						continue;
					case	0x7 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(150,410,84,32,2,16,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(150,410,84,32,2,16,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x8 :
						/* Compose */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(290,410,84,32,2,16,0,"Co&mpose",8,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(290,410,84,32,2,16,0,"Co&mpose",8,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Compose_event()) != -1) break;

							}
						continue;
					case	0x9 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(570,410,84,32,2,16,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(570,410,84,32,2,16,0,"&Cancel",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

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
				_Context->focus_item=9;
			}
			continue;
		case 0x841 : 
		case 0x861 : 
		/* Accept */
		visual_button(150,410,84,32,2,16,0,"&Accept",7,8);
		visual_button(150,410,84,32,2,16,0,"&Accept",7,0);
		_Context->focus_item=7;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x86d : 
		case 0x88d : 
		/* Compose */
		visual_button(290,410,84,32,2,16,0,"Co&mpose",8,8);
		visual_button(290,410,84,32,2,16,0,"Co&mpose",8,0);
		_Context->focus_item=8;
		if ((_Context->keycode = on_Compose_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(570,410,84,32,2,16,0,"&Cancel",7,8);
		visual_button(570,410,84,32,2,16,0,"&Cancel",7,0);
		_Context->focus_item=9;
		if ((_Context->keycode = on_Cancel_event()) != -1) break;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_form_syntax(
	char * pResult,
	char * pClassList,
	char * pWidgetList,
	char * pMethodList,
	char * pConcatenate)
{
	int	status=0;
	status = accept_form_syntax_create(
	 pResult,
	 pClassList,
	 pWidgetList,
	 pMethodList,
	 pConcatenate);
	if ( status != 0) return(status);
	status = accept_form_syntax_show();
		enter_modal();
	status = accept_form_syntax_focus();
		leave_modal();
	status = accept_form_syntax_hide();
	status = accept_form_syntax_remove(
	 pResult,
	 pClassList,
	 pWidgetList,
	 pMethodList,
	 pConcatenate);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcompose_c */
