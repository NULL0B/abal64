
#ifndef _vedcmd_c
#define _vedcmd_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vedcmd.xml  */
/* Target         : vedcmd.c  */
/* Identification : 0.0-1100085366-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto4724   "Sing : Version 1.0a"
#define fr_Auto4724   "Sing : Version 1.0a"
#define en_Auto6248   "skin.gif"
#define fr_Auto6248   "skin.gif"
#define en_Auto4869   "Editor Command"
#define fr_Auto4869   "Commande de l'Editeur"
#define it_Auto4869   "Editor Command"
#define es_Auto4869   "Editor Command"
#define de_Auto4869   "Editor Command"
#define nl_Auto4869   "Editor Command"
#define pt_Auto4869   "Editor Command"
#define xx_Auto4869   "Editor Command"
#define en_EditorCommand   ""
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
static int	vfh[10];

private struct accept_editor_command_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto4724[8];
	int	x_Auto4724;
	int	y_Auto4724;
	int	w_Auto4724;
	int	h_Auto4724;
	char * msg_Auto6248[8];
	char * msg_Auto4869[8];
	char	buffer_EditorCommand[65];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};

public	int	accept_editor_command_create(
	struct accept_editor_command_context ** cptr,
	char * pEditorCommand)
{

	int i;
	struct accept_editor_command_context * _Context=(struct accept_editor_command_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_editor_command_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_EditorCommand, 64, pEditorCommand);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto4724[i]=" ";
	_Context->msg_Auto4724[0]=en_Auto4724;
	_Context->msg_Auto4724[1]=fr_Auto4724;
	_Context->x_Auto4724=125;
	_Context->y_Auto4724=230;
	_Context->w_Auto4724=550;
	_Context->h_Auto4724=140;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto6248[i]=" ";
	_Context->msg_Auto6248[0]=en_Auto6248;
	_Context->msg_Auto6248[1]=fr_Auto6248;
	for (i=0; i < 8; i++)_Context->msg_Auto4869[i]=" ";
	_Context->msg_Auto4869[0]=en_Auto4869;
	_Context->msg_Auto4869[1]=fr_Auto4869;
	_Context->msg_Auto4869[2]=it_Auto4869;
	_Context->msg_Auto4869[3]=es_Auto4869;
	_Context->msg_Auto4869[4]=de_Auto4869;
	_Context->msg_Auto4869[5]=nl_Auto4869;
	_Context->msg_Auto4869[6]=pt_Auto4869;
	_Context->msg_Auto4869[7]=xx_Auto4869;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto4724,_Context->y_Auto4724,550+10,140+10);
	return(0);
}

public 	int	accept_editor_command_hide(struct accept_editor_command_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto4724,_Context->y_Auto4724);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_editor_command_remove(
	struct accept_editor_command_context * _Context,
	char * pEditorCommand)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_EditorCommand, 64, pEditorCommand);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_editor_command_show(struct accept_editor_command_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto4724,_Context->y_Auto4724);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto4724,_Context->y_Auto4724,550,140,vfh[2],_Context->msg_Auto4724[_Context->language],strlen(_Context->msg_Auto4724[_Context->language]),0x407);
	visual_image(_Context->x_Auto4724+3,_Context->y_Auto4724+21,542,114,_Context->msg_Auto6248[_Context->language],4);
	visual_text(_Context->x_Auto4724+10,_Context->y_Auto4724+30,530,20,vfh[3],27,0,_Context->msg_Auto4869[_Context->language],strlen(_Context->msg_Auto4869[_Context->language]),1026);
	visual_frame(_Context->x_Auto4724+10,_Context->y_Auto4724+50,530,40,4);
	visual_frame(_Context->x_Auto4724+20,_Context->y_Auto4724+60,512+2,16+2,5);
	visual_text(_Context->x_Auto4724+20+1,_Context->y_Auto4724+60+1,512,16,vfh[1],27,0,_Context->buffer_EditorCommand,64,0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto4724+10,_Context->y_Auto4724+100,100,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto4724+440,_Context->y_Auto4724+100,100,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_thaw(_Context->x_Auto4724,_Context->y_Auto4724,550,140);
	visual_thaw(_Context->x_Auto4724,_Context->y_Auto4724,550,140);

	return(0);
}

private int Auto4724action(struct accept_editor_command_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_editor_command_hide(_Context);

		_Context->x_Auto4724 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto4724 < 0) { _Context->x_Auto4724=0; }
		_Context->y_Auto4724 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto4724 < 0) { _Context->y_Auto4724=0; }
			accept_editor_command_show(_Context);

		visual_thaw(_Context->x_Auto4724,_Context->y_Auto4724,550,140);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_editor_command_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_editor_command_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_editor_command_event(
struct accept_editor_command_context * _Context){
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
	if ((mx >= (_Context->x_Auto4724+529) )  
	&&  (my >= (_Context->y_Auto4724+4) )  
	&&  (mx <= (_Context->x_Auto4724+546) )  
	&&  (my <= (_Context->y_Auto4724+20) )) {
		return(1);	/* Auto4724 */

		}
	if ((mx >= (_Context->x_Auto4724+513) )  
	&&  (my >= (_Context->y_Auto4724+4) )  
	&&  (mx <= (_Context->x_Auto4724+530) )  
	&&  (my <= (_Context->y_Auto4724+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vedcmd.htm");
			};
		return(-1);	/* Auto4724 */

		}
	if ((mx >= (_Context->x_Auto4724+497) )  
	&&  (my >= (_Context->y_Auto4724+4) )  
	&&  (mx <= (_Context->x_Auto4724+514) )  
	&&  (my <= (_Context->y_Auto4724+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_editor_command_show(_Context);
		return(-1);	/* Auto4724 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto4724+4) )  
		&&  (my >= (_Context->y_Auto4724+4) )  
		&&  (mx <= (_Context->x_Auto4724+482) )  
		&&  (my <= (_Context->y_Auto4724+20) )) {
			return( Auto4724action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto4724+20) ) 
	&&  ( my >= (_Context->y_Auto4724+60) ) 
	&&  ( mx <= (_Context->x_Auto4724+20+512) ) 
	&&  ( my <= (_Context->y_Auto4724+60+16))) {
		return(2); /* EditorCommand */
		}
	if (( mx >= (_Context->x_Auto4724+10) ) 
	&&  ( my >= (_Context->y_Auto4724+100) ) 
	&&  ( mx <= (_Context->x_Auto4724+10+100) ) 
	&&  ( my <= (_Context->y_Auto4724+100+32))) {
		return(3); /* Accept */
		}
	if (( mx >= (_Context->x_Auto4724+440) ) 
	&&  ( my >= (_Context->y_Auto4724+100) ) 
	&&  ( mx <= (_Context->x_Auto4724+440+100) ) 
	&&  ( my <= (_Context->y_Auto4724+100+32))) {
		return(4); /* Cancel */
		}

	return(-1);
}


public	int	accept_editor_command_focus(struct accept_editor_command_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* EditorCommand */
				_Context->keycode = visual_edit(_Context->x_Auto4724+20+1,_Context->y_Auto4724+60+1,512,16,vfh[1],_Context->buffer_EditorCommand,64);
			break;
			case	0x3 :
				/* Accept */
				visual_button(_Context->x_Auto4724+10,_Context->y_Auto4724+100,100,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto4724+10,_Context->y_Auto4724+100,100,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x4 :
				/* Cancel */
				visual_button(_Context->x_Auto4724+440,_Context->y_Auto4724+100,100,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto4724+440,_Context->y_Auto4724+100,100,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_editor_command_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=4;
			accept_editor_command_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_editor_command_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto4724 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* EditorCommand */
						continue;
					case	0x3 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto4724+10,_Context->y_Auto4724+100,100,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto4724+10,_Context->y_Auto4724+100,100,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto4724+440,_Context->y_Auto4724+100,100,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto4724+440,_Context->y_Auto4724+100,100,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
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
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_editor_command(
	char * pEditorCommand)
{
	int	status=0;
	struct accept_editor_command_context * _Context=(struct accept_editor_command_context*) 0;
	status = accept_editor_command_create(
	&_Context,
	 pEditorCommand);
	if ( status != 0) return(status);
	status = accept_editor_command_show(_Context);
		enter_modal();
	status = accept_editor_command_focus(_Context);
		leave_modal();
	status = accept_editor_command_hide(_Context);
	status = accept_editor_command_remove(
	_Context,
	 pEditorCommand);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vedcmd_c */
