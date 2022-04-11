
#ifndef _vreplace_c
#define _vreplace_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.01  */
/* Production     : C  */
/* Project        : vreplace.sng  */
/* Target         : vreplace.c  */
/* Identification : 0.0-1057622498-2176.2175 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_replace_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_Criteria[54];
	char	buffer_Replace[54];
	int	value_IgnoreCase;
	int	value_ReverseSearch;
	int	value_ReplaceAll;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[6];
	} * _Context;

private	int	accept_replace_create( char * pCriteria,char * pReplace,char * pIgnoreCase,char * pReverseSearch,char * pReplaceAll)
{

	if (!(_Context = allocate( sizeof( struct accept_replace_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=8;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Criteria, 53, pCriteria);
		visual_transferin(_Context->buffer_Replace, 53, pReplace);
		visual_transferin((void *) 0, 0, pIgnoreCase);
		if (!( pIgnoreCase )) _Context->value_IgnoreCase=0;
		else	_Context->value_IgnoreCase = *((int *)pIgnoreCase);
		visual_transferin((void *) 0, 0, pReverseSearch);
		if (!( pReverseSearch )) _Context->value_ReverseSearch=0;
		else	_Context->value_ReverseSearch = *((int *)pReverseSearch);
		visual_transferin((void *) 0, 0, pReplaceAll);
		if (!( pReplaceAll )) _Context->value_ReplaceAll=0;
		else	_Context->value_ReplaceAll = *((int *)pReplaceAll);
		}
	_Context->window_col=60;
	_Context->window_row=30;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(60,30,610+10,100+10);
	return(0);
}

private	int	accept_replace_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,60,30);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_replace_remove( char * pCriteria,char * pReplace,char * pIgnoreCase,char * pReverseSearch,char * pReplaceAll)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Criteria, 53, pCriteria);
		visual_transferout(_Context->buffer_Replace, 53, pReplace);
		visual_transferout((void *) 0, 0, pIgnoreCase);
		if ( pIgnoreCase != (char *) 0)
			*((int*)pIgnoreCase) = _Context->value_IgnoreCase;
		visual_transferout((void *) 0, 0, pReverseSearch);
		if ( pReverseSearch != (char *) 0)
			*((int*)pReverseSearch) = _Context->value_ReverseSearch;
		visual_transferout((void *) 0, 0, pReplaceAll);
		if ( pReplaceAll != (char *) 0)
			*((int*)pReplaceAll) = _Context->value_ReplaceAll;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_replace_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,60,30);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(60,30,610,100,2,"Sing : Version 1.0a",19,0x403);
	visual_image(63,52,603,74,VisualSkin,4);
	visual_text(70,60,84,16,2,27,0,"Locate Text",11,771);
	visual_text(70,80,84,16,2,27,0,"Replace With",12,771);
	visual_frame(160,60,424+2,16+2,5);
	visual_text(160+1,60+1,424,16,1,16,22,_Context->buffer_Criteria,53,0);
	visual_frame(160,80,424+2,16+2,5);
	visual_text(160+1,80+1,424,16,1,27,0,_Context->buffer_Replace,53,0);
	visual_check(160,100,140,16,2,16,22,"&Ignore Case",12,_Context->value_IgnoreCase|0);
	visual_check(300,100,154,16,2,16,22,"&Reverse Search",15,_Context->value_ReverseSearch|0);
	visual_check(460,100,126,16,2,27,0,"Replace &All",12,_Context->value_ReplaceAll|0);
	visual_button(590,60,68,16,8,16,22,"Re&place",8,0);
	visual_button(590,80,70,20,8,16,22,"&Quit",5,0);
	visual_thaw(60,30,610,100);

	return(0);
}
private int on_DoReplace_event() {
	accept_replace_hide();
	EditorTextReplace(_Context->buffer_Criteria,53,
	_Context->buffer_Replace,53,
	_Context->value_IgnoreCase,
	_Context->value_ReverseSearch,
	_Context->value_ReplaceAll);
	accept_replace_show();
	return(-1);
}
private int on_Quit_event() {
	return(13);
	return(-1);
}


private	int	accept_replace_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 649 )  
	&&  (my >= 34 )  
	&&  (mx <= 665 )  
	&&  (my <= 50 )) {
		return(1);	/* Auto241 */

		}
	if ((mx >= 633 )  
	&&  (my >= 34 )  
	&&  (mx <= 649 )  
	&&  (my <= 50 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vreplace.htm");
			};
		return(-1);	/* Auto241 */

		}
	if (( mx >= 160 ) 
	&&  ( my >= 60 ) 
	&&  ( mx <= 584 ) 
	&&  ( my <= 76 )) {
		return(2); /* Criteria */
		}
	if (( mx >= 160 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 584 ) 
	&&  ( my <= 96 )) {
		return(3); /* Replace */
		}
	if (( mx >= 160 ) 
	&&  ( my >= 100 ) 
	&&  ( mx <= 300 ) 
	&&  ( my <= 116 )) {
		return(4); /* IgnoreCase */
		}
	if (( mx >= 300 ) 
	&&  ( my >= 100 ) 
	&&  ( mx <= 454 ) 
	&&  ( my <= 116 )) {
		return(5); /* ReverseSearch */
		}
	if (( mx >= 460 ) 
	&&  ( my >= 100 ) 
	&&  ( mx <= 586 ) 
	&&  ( my <= 116 )) {
		return(6); /* ReplaceAll */
		}
	if (( mx >= 590 ) 
	&&  ( my >= 60 ) 
	&&  ( mx <= 658 ) 
	&&  ( my <= 76 )) {
		return(7); /* DoReplace */
		}
	if (( mx >= 590 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 660 ) 
	&&  ( my <= 100 )) {
		return(8); /* Quit */
		}

	return(-1);
}


private	int	accept_replace_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Criteria */
				_Context->keycode = visual_edit(160+1,60+1,424,16,1,_Context->buffer_Criteria,53);
				if(_Context->keycode==13){
				on_DoReplace_event();
				_Context->keycode=0;
				}
				break;
			case	0x3 :
				/* Replace */
				_Context->keycode = visual_edit(160+1,80+1,424,16,1,_Context->buffer_Replace,53);
				if(_Context->keycode==13){
				on_DoReplace_event();
				_Context->keycode=0;
				}
				break;
			case	0x4 :
				/* IgnoreCase */
				visual_check(160,100,140,16,2,16,22,"&Ignore Case",12,(_Context->value_IgnoreCase |2));
				_Context->keycode = visual_getch();
				visual_check(160,100,140,16,2,16,22,"&Ignore Case",12,(_Context->value_IgnoreCase |0));
				break;
			case	0x5 :
				/* ReverseSearch */
				visual_check(300,100,154,16,2,16,22,"&Reverse Search",15,(_Context->value_ReverseSearch |2));
				_Context->keycode = visual_getch();
				visual_check(300,100,154,16,2,16,22,"&Reverse Search",15,(_Context->value_ReverseSearch |0));
				break;
			case	0x6 :
				/* ReplaceAll */
				visual_check(460,100,126,16,2,27,0,"Replace &All",12,(_Context->value_ReplaceAll |2));
				_Context->keycode = visual_getch();
				visual_check(460,100,126,16,2,27,0,"Replace &All",12,(_Context->value_ReplaceAll |0));
				break;
			case	0x7 :
				/* DoReplace */
				visual_button(590,60,68,16,8,16,22,"Re&place",8,2);
				_Context->keycode = visual_getch();
				visual_button(590,60,68,16,8,16,22,"Re&place",8,0);
				break;
			case	0x8 :
				/* Quit */
				visual_button(590,80,70,20,8,16,22,"&Quit",5,2);
				_Context->keycode = visual_getch();
				visual_button(590,80,70,20,8,16,22,"&Quit",5,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_replace_show();
			continue;
		case	0x2 :
			_Context->focus_item=8;
			accept_replace_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_replace_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto241 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Criteria */
						continue;
					case	0x3 :
						/* Replace */
						continue;
					case	0x4 :
						/* IgnoreCase */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IgnoreCase += 1;
							_Context->value_IgnoreCase &= 1;
							}
						continue;
					case	0x5 :
						/* ReverseSearch */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_ReverseSearch += 1;
							_Context->value_ReverseSearch &= 1;
							}
						continue;
					case	0x6 :
						/* ReplaceAll */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_ReplaceAll += 1;
							_Context->value_ReplaceAll &= 1;
							}
						continue;
					case	0x7 :
						/* DoReplace */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(590,60,68,16,8,16,22,"Re&place",8,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(590,60,68,16,8,16,22,"Re&place",8,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_DoReplace_event()) != -1) break;

							}
						continue;
					case	0x8 :
						/* Quit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(590,80,70,20,8,16,22,"&Quit",5,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(590,80,70,20,8,16,22,"&Quit",5,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Quit_event()) != -1) break;

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
				_Context->focus_item=8;
			}
			continue;
		case 0x849 : 
		case 0x869 : 
		/* IgnoreCase */
		_Context->value_IgnoreCase += 1;
		_Context->value_IgnoreCase &= 1;
		_Context->focus_item=4;
		continue;
		case 0x852 : 
		case 0x872 : 
		/* ReverseSearch */
		_Context->value_ReverseSearch += 1;
		_Context->value_ReverseSearch &= 1;
		_Context->focus_item=5;
		continue;
		case 0x841 : 
		case 0x861 : 
		/* ReplaceAll */
		_Context->value_ReplaceAll += 1;
		_Context->value_ReplaceAll &= 1;
		_Context->focus_item=6;
		continue;
		case 0x870 : 
		case 0x890 : 
		/* DoReplace */
		visual_button(590,60,68,16,8,16,22,"Re&place",8,8);
		visual_button(590,60,68,16,8,16,22,"Re&place",8,0);
		_Context->focus_item=7;
		if ((_Context->keycode = on_DoReplace_event()) != -1) break;
		continue;
		case 0x851 : 
		case 0x871 : 
		/* Quit */
		visual_button(590,80,70,20,8,16,22,"&Quit",5,8);
		visual_button(590,80,70,20,8,16,22,"&Quit",5,0);
		_Context->focus_item=8;
		if ((_Context->keycode = on_Quit_event()) != -1) break;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_replace( char * pCriteria,char * pReplace,char * pIgnoreCase,char * pReverseSearch,char * pReplaceAll)
{
	int	status=0;
	status = accept_replace_create(  pCriteria, pReplace, pIgnoreCase, pReverseSearch, pReplaceAll);
	if ( status != 0) return(status);
	status = accept_replace_show();
		enter_modal();
	status = accept_replace_focus();
		leave_modal();
	status = accept_replace_hide();
	status = accept_replace_remove(  pCriteria, pReplace, pIgnoreCase, pReverseSearch, pReplaceAll);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vreplace_c */
