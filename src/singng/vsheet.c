
#ifndef _vsheet_c
#define _vsheet_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : vsheet.xml                                               */
/* Target         : vsheet.c                                                 */
/* Identification : 0.0-1196372989-3302.3301                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto3325   ""
#define en_Auto3326   "Style Class Characteristics"
#define fr_Auto3326   "File Model Characteristics"
#define it_Auto3326   "File Model Characteristics"
#define es_Auto3326   "File Model Characteristics"
#define de_Auto3326   "File Model Characteristics"
#define nl_Auto3326   "File Model Characteristics"
#define pt_Auto3326   "File Model Characteristics"
#define xx_Auto3326   "File Model Characteristics"
#define en__Auto3326   ""
#define fr__Auto3326   ""
#define it__Auto3326   ""
#define es__Auto3326   ""
#define de__Auto3326   ""
#define nl__Auto3326   ""
#define pt__Auto3326   ""
#define xx__Auto3326   ""
#define en_Auto3327   "Style Class Characteristics"
#define fr_Auto3327   "File Model Characteristics"
#define it_Auto3327   "File Model Characteristics"
#define es_Auto3327   "File Model Characteristics"
#define de_Auto3327   "File Model Characteristics"
#define nl_Auto3327   "File Model Characteristics"
#define pt_Auto3327   "File Model Characteristics"
#define xx_Auto3327   "File Model Characteristics"
#define en__Auto3327   ""
#define fr__Auto3327   ""
#define it__Auto3327   ""
#define es__Auto3327   ""
#define de__Auto3327   ""
#define nl__Auto3327   ""
#define pt__Auto3327   ""
#define xx__Auto3327   ""
#define en_Editor   ""
#define en__Editor   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en__Accept   ""
#define fr__Accept   ""
#define it__Accept   ""
#define es__Accept   ""
#define de__Accept   ""
#define nl__Accept   ""
#define pt__Accept   ""
#define xx__Accept   ""
#define en_Example   ""
#define en__Example   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""
#define fr__Cancel   ""
#define it__Cancel   ""
#define es__Cancel   ""
#define de__Cancel   ""
#define nl__Cancel   ""
#define pt__Cancel   ""
#define xx__Cancel   ""

private struct accept_style_inspection_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3325[8];
	char * hint_Auto3325[8];
	int	x_Auto3325;
	int	y_Auto3325;
	int	w_Auto3325;
	int	h_Auto3325;
	char * msg_Auto3326[8];
	char * hint_Auto3326[8];
	char * msg_Auto3327[8];
	char * hint_Auto3327[8];
	char * hint_Editor[8];
	char * buffer_Editor;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * hint_Example[8];
	char	buffer_Example[97];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];

public	int	accept_style_inspection_create(
	struct accept_style_inspection_context ** cptr,
	char * pEditor,
	char * pExample)
{

	int i;
	struct accept_style_inspection_context * _Context=(struct accept_style_inspection_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_style_inspection_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"TS");
		visual_signature(_Context->signature,_Context->signature);
				_Context->buffer_Editor=(char *) 0;
		visual_transferin(&_Context->buffer_Editor, 624, pEditor);
		visual_transferin(_Context->buffer_Example, 96, pExample);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3325[i]=" ";
	_Context->hint_Auto3325[0]=en__Auto3325;
	_Context->x_Auto3325=180;
	_Context->y_Auto3325=130;
	_Context->w_Auto3325=440;
	_Context->h_Auto3325=340;
	_Context->window_col=0;
	_Context->window_row=0;
	if(((_Context->y_Auto3325=visual_event(6))+340)>hardrows())
	_Context->y_Auto3325=(hardrows()-340);
	if(((_Context->x_Auto3325=visual_event(7))+440)>hardcolumns())
	_Context->x_Auto3325=(hardcolumns()-440);
	for (i=0; i < 8; i++)_Context->msg_Auto3326[i]=" ";
	_Context->msg_Auto3326[0]=en_Auto3326;
	_Context->msg_Auto3326[1]=fr_Auto3326;
	_Context->msg_Auto3326[2]=it_Auto3326;
	_Context->msg_Auto3326[3]=es_Auto3326;
	_Context->msg_Auto3326[4]=de_Auto3326;
	_Context->msg_Auto3326[5]=nl_Auto3326;
	_Context->msg_Auto3326[6]=pt_Auto3326;
	_Context->msg_Auto3326[7]=xx_Auto3326;
	_Context->hint_Auto3326[0]=en__Auto3326;
	_Context->hint_Auto3326[1]=fr__Auto3326;
	_Context->hint_Auto3326[2]=it__Auto3326;
	_Context->hint_Auto3326[3]=es__Auto3326;
	_Context->hint_Auto3326[4]=de__Auto3326;
	_Context->hint_Auto3326[5]=nl__Auto3326;
	_Context->hint_Auto3326[6]=pt__Auto3326;
	_Context->hint_Auto3326[7]=xx__Auto3326;
	for (i=0; i < 8; i++)_Context->msg_Auto3327[i]=" ";
	_Context->msg_Auto3327[0]=en_Auto3327;
	_Context->msg_Auto3327[1]=fr_Auto3327;
	_Context->msg_Auto3327[2]=it_Auto3327;
	_Context->msg_Auto3327[3]=es_Auto3327;
	_Context->msg_Auto3327[4]=de_Auto3327;
	_Context->msg_Auto3327[5]=nl_Auto3327;
	_Context->msg_Auto3327[6]=pt_Auto3327;
	_Context->msg_Auto3327[7]=xx_Auto3327;
	_Context->hint_Auto3327[0]=en__Auto3327;
	_Context->hint_Auto3327[1]=fr__Auto3327;
	_Context->hint_Auto3327[2]=it__Auto3327;
	_Context->hint_Auto3327[3]=es__Auto3327;
	_Context->hint_Auto3327[4]=de__Auto3327;
	_Context->hint_Auto3327[5]=nl__Auto3327;
	_Context->hint_Auto3327[6]=pt__Auto3327;
	_Context->hint_Auto3327[7]=xx__Auto3327;
	_Context->hint_Editor[0]=en__Editor;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	_Context->hint_Accept[0]=en__Accept;
	_Context->hint_Accept[1]=fr__Accept;
	_Context->hint_Accept[2]=it__Accept;
	_Context->hint_Accept[3]=es__Accept;
	_Context->hint_Accept[4]=de__Accept;
	_Context->hint_Accept[5]=nl__Accept;
	_Context->hint_Accept[6]=pt__Accept;
	_Context->hint_Accept[7]=xx__Accept;
	_Context->hint_Example[0]=en__Example;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	_Context->hint_Cancel[0]=en__Cancel;
	_Context->hint_Cancel[1]=fr__Cancel;
	_Context->hint_Cancel[2]=it__Cancel;
	_Context->hint_Cancel[3]=es__Cancel;
	_Context->hint_Cancel[4]=de__Cancel;
	_Context->hint_Cancel[5]=nl__Cancel;
	_Context->hint_Cancel[6]=pt__Cancel;
	_Context->hint_Cancel[7]=xx__Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3325,_Context->y_Auto3325,440+10,340+10);
	return(0);
}

public 	int	accept_style_inspection_hide(struct accept_style_inspection_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	close_window_editor();
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3325,_Context->y_Auto3325);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_style_inspection_remove(
	struct accept_style_inspection_context * _Context,
	char * pEditor,
	char * pExample)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode == 27 ) {
		filetransferdrop(_Context->buffer_Editor);
		
	} else {
		strcpy(_Context->signature,"TS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(&_Context->buffer_Editor, 624, pEditor);
		visual_transferout(_Context->buffer_Example, 96, pExample);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Auto3325_show(struct accept_style_inspection_context * _Context) {
		if (((_Context->status = visual_styled_element(_Context->x_Auto3325,_Context->y_Auto3325,440,340,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3325,_Context->y_Auto3325,440,340,vfh[1],GetWindowVersion(),strlen(GetWindowVersion()),0x405);
	}

	open_window_editor(_Context->x_Auto3325+10,_Context->y_Auto3325+60,
	416,192,_Context->buffer_Editor);
	return(-1);
}
private int on_Editor_show(struct accept_style_inspection_context * _Context) {
	visual_frame(_Context->x_Auto3325+10,_Context->y_Auto3325+60,416+2,192+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_Example_show(struct accept_style_inspection_context * _Context) {
	int i;
	int l;
	for(i=0,l=0;i<96;i++){
	if(_Context->buffer_Example[i]!=' ')
	l=i+1;
	}
	_Context->buffer_Example[l]=0;
	visual_styled_element(_Context->x_Auto3325+90,_Context->y_Auto3325+280,256,48,_Context->buffer_Example,_Context->buffer_Example,l);
	_Context->buffer_Example[l]=' ';
	return(-1);
}

public	int	accept_style_inspection_show(struct accept_style_inspection_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3325,_Context->y_Auto3325);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	(void) on_Auto3325_show(_Context);
	visual_text(_Context->x_Auto3325+10,_Context->y_Auto3325+30,414,20,vfh[3],16,0,_Context->msg_Auto3326[_Context->language],strlen(_Context->msg_Auto3326[_Context->language]),259);
	visual_text(_Context->x_Auto3325+10,_Context->y_Auto3325+260,414,20,vfh[3],16,0,_Context->msg_Auto3327[_Context->language],strlen(_Context->msg_Auto3327[_Context->language]),259);
	(void) on_Editor_show(_Context);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3325+10,_Context->y_Auto3325+280,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	(void) on_Example_show(_Context);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3325+370,_Context->y_Auto3325+280,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3325,_Context->y_Auto3325,440,340);

	return(0);
}

private int Auto3325action(struct accept_style_inspection_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_style_inspection_hide(_Context);

		_Context->x_Auto3325 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3325 < 0) { _Context->x_Auto3325=0; }
		_Context->y_Auto3325 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3325 < 0) { _Context->y_Auto3325=0; }
			accept_style_inspection_show(_Context);

		visual_thaw(_Context->x_Auto3325,_Context->y_Auto3325,440,340);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_style_inspection_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_style_inspection_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_style_inspection_event(
struct accept_style_inspection_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(3);
		if (_Context->trigger_Cancel == mb ) return(4);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3325+419) )  
	&&  (my >= (_Context->y_Auto3325+4) )  
	&&  (mx <= (_Context->x_Auto3325+436) )  
	&&  (my <= (_Context->y_Auto3325+20) )) {
		return(1);	/* Auto3325 */

		}
	if ((mx >= (_Context->x_Auto3325+387) )  
	&&  (my >= (_Context->y_Auto3325+4) )  
	&&  (mx <= (_Context->x_Auto3325+404) )  
	&&  (my <= (_Context->y_Auto3325+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_style_inspection_show(_Context);
		return(-1);	/* Auto3325 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3325+4) )  
		&&  (my >= (_Context->y_Auto3325+4) )  
		&&  (mx <= (_Context->x_Auto3325+372) )  
		&&  (my <= (_Context->y_Auto3325+20) )) {
			return( Auto3325action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3325+10) ) 
	&&  ( my >= (_Context->y_Auto3325+60) ) 
	&&  ( mx <= (_Context->x_Auto3325+10+416) ) 
	&&  ( my <= (_Context->y_Auto3325+60+192))) {
		return(2); /* Editor */
		}
	if (( mx >= (_Context->x_Auto3325+10) ) 
	&&  ( my >= (_Context->y_Auto3325+280) ) 
	&&  ( mx <= (_Context->x_Auto3325+10+56) ) 
	&&  ( my <= (_Context->y_Auto3325+280+48))) {
		return(3); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3325+370) ) 
	&&  ( my >= (_Context->y_Auto3325+280) ) 
	&&  ( mx <= (_Context->x_Auto3325+370+56) ) 
	&&  ( my <= (_Context->y_Auto3325+280+48))) {
		return(4); /* Cancel */
		}

	return(-1);
}
private int on_Editor_getfocus(struct accept_style_inspection_context * _Context) {
	return(focus_window_editor());
	return(-1);
}


public	int	accept_style_inspection_focus(struct accept_style_inspection_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Editor */
				_Context->keycode = on_Editor_getfocus(_Context);
			break;
			case	0x3 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_Auto3325+10,_Context->y_Auto3325+280,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3325+10,_Context->y_Auto3325+280,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x4 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Auto3325+370,_Context->y_Auto3325+280,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3325+370,_Context->y_Auto3325+280,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_style_inspection_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=4;
			accept_style_inspection_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_Auto3325 )
				|| ( visual_event(6) < _Context->y_Auto3325  )
				|| ( visual_event(7) > (_Context->x_Auto3325+_Context->w_Auto3325))
				|| ( visual_event(6) >  (_Context->y_Auto3325+_Context->h_Auto3325))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=accept_style_inspection_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3325 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Editor */
					continue;
				case	0x3 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3325+10,_Context->y_Auto3325+280,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3325+10,_Context->y_Auto3325+280,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3325+370,_Context->y_Auto3325+280,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3325+370,_Context->y_Auto3325+280,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

						}
					continue;
				case	0xffffffff :
				default :
					_Context->focus_item=1;
				continue;
				}
				break;
		case	0x1b :
			break;
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
				_Context->focus_item=4;
			}
			continue;
		case	0x0 :
			
			continue;
		case	0xffffffff :
			
			continue;

			}
		break;
		}

	return( _Context->keycode );
}

public	int	accept_style_inspection(
	char * pEditor,
	char * pExample)
{
	int	status=0;
	struct accept_style_inspection_context * _Context=(struct accept_style_inspection_context*) 0;
	status = accept_style_inspection_create(
	&_Context,
	 pEditor,
	 pExample);
	if ( status != 0) return(status);
	status = accept_style_inspection_show(_Context);
		enter_modal();
	status = accept_style_inspection_focus(_Context);
		leave_modal();
	status = accept_style_inspection_hide(_Context);
	status = accept_style_inspection_remove(
	_Context,
	 pEditor,
	 pExample);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vsheet_c */
