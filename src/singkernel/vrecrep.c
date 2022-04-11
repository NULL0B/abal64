
#ifndef _vrecrep_c
#define _vrecrep_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vrecrep.xml  */
/* Target         : vrecrep.c  */
/* Identification : 0.0-1100085296-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto529   "Sing : Version 1.0a"
#define fr_Auto529   "Sing : Version 1.0a"
#define en_Auto722   "skin.gif"
#define fr_Auto722   "skin.gif"
#define en_Filename   "Animation Filename"
#define fr_Filename   "Nom de Fichier d'animation"
#define it_Filename   "Animation Filename"
#define es_Filename   "Animation Filename"
#define de_Filename   "Animation Filename"
#define nl_Filename   "Animation Filename"
#define pt_Filename   "Animation Filename"
#define xx_Filename   "Animation Filename"
#define en_Mode   "Record Script|Replay Animation"
#define fr_Mode   "Enregistrer|Re-enacter"
#define it_Mode   "Record Script|Replay Animation"
#define es_Mode   "Record Script|Replay Animation"
#define de_Mode   "Record Script|Replay Animation"
#define nl_Mode   "Record Script|Replay Animation"
#define pt_Mode   "Record Script|Replay Animation"
#define xx_Mode   "Record Script|Replay Animation"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
static int	vfh[10];

private struct accept_animation_parameters_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto529[8];
	int	x_Auto529;
	int	y_Auto529;
	int	w_Auto529;
	int	h_Auto529;
	char * msg_Auto722[8];
	char * msg_Filename[8];
	char	buffer_FileName[60];
	char * msg_Mode[8];
	int	value_Mode;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};

public	int	accept_animation_parameters_create(
	struct accept_animation_parameters_context ** cptr,
	char * pFileName,
	char * pMode)
{

	int i;
	struct accept_animation_parameters_context * _Context=(struct accept_animation_parameters_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_animation_parameters_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=5;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 59, pFileName);
		visual_transferin((void *) 0, 0, pMode);
		if (!( pMode )) _Context->value_Mode=0;
		else	_Context->value_Mode = *((int *)pMode);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto529[i]=" ";
	_Context->msg_Auto529[0]=en_Auto529;
	_Context->msg_Auto529[1]=fr_Auto529;
	_Context->x_Auto529=140;
	_Context->y_Auto529=220;
	_Context->w_Auto529=520;
	_Context->h_Auto529=160;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto722[i]=" ";
	_Context->msg_Auto722[0]=en_Auto722;
	_Context->msg_Auto722[1]=fr_Auto722;
	for (i=0; i < 8; i++)_Context->msg_Filename[i]=" ";
	_Context->msg_Filename[0]=en_Filename;
	_Context->msg_Filename[1]=fr_Filename;
	_Context->msg_Filename[2]=it_Filename;
	_Context->msg_Filename[3]=es_Filename;
	_Context->msg_Filename[4]=de_Filename;
	_Context->msg_Filename[5]=nl_Filename;
	_Context->msg_Filename[6]=pt_Filename;
	_Context->msg_Filename[7]=xx_Filename;
	for (i=0; i < 8; i++)_Context->msg_Mode[i]=" ";
	_Context->msg_Mode[0]=en_Mode;
	_Context->msg_Mode[1]=fr_Mode;
	_Context->msg_Mode[2]=it_Mode;
	_Context->msg_Mode[3]=es_Mode;
	_Context->msg_Mode[4]=de_Mode;
	_Context->msg_Mode[5]=nl_Mode;
	_Context->msg_Mode[6]=pt_Mode;
	_Context->msg_Mode[7]=xx_Mode;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto529,_Context->y_Auto529,520+10,160+10);
	return(0);
}

public 	int	accept_animation_parameters_hide(struct accept_animation_parameters_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto529,_Context->y_Auto529);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_animation_parameters_remove(
	struct accept_animation_parameters_context * _Context,
	char * pFileName,
	char * pMode)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 59, pFileName);
		visual_transferout((void *) 0, 0, pMode);
		if ( pMode != (char *) 0)
			*((int*)pMode) = _Context->value_Mode;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_animation_parameters_show(struct accept_animation_parameters_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto529,_Context->y_Auto529);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto529,_Context->y_Auto529,520,160,vfh[2],_Context->msg_Auto529[_Context->language],strlen(_Context->msg_Auto529[_Context->language]),0x407);
	visual_image(_Context->x_Auto529+2,_Context->y_Auto529+22,514,134,_Context->msg_Auto722[_Context->language],4);
	visual_text(_Context->x_Auto529+20,_Context->y_Auto529+40,476,16,vfh[2],27,0,_Context->msg_Filename[_Context->language],strlen(_Context->msg_Filename[_Context->language]),258);
	visual_frame(_Context->x_Auto529+20,_Context->y_Auto529+60,472+2,16+2,5);
	visual_text(_Context->x_Auto529+20+1,_Context->y_Auto529+60+1,472,16,vfh[1],27,0,_Context->buffer_FileName,59,0);
	visual_select(_Context->x_Auto529+130,_Context->y_Auto529+100,250,46,vfh[1],27,0,parse_selection(_Context->msg_Mode[_Context->language],&_Context->value_Mode),0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto529+20,_Context->y_Auto529+100,100,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto529+390,_Context->y_Auto529+100,100,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_thaw(_Context->x_Auto529,_Context->y_Auto529,520,160);
	visual_thaw(_Context->x_Auto529,_Context->y_Auto529,520,160);

	return(0);
}

private int Auto529action(struct accept_animation_parameters_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_animation_parameters_hide(_Context);

		_Context->x_Auto529 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto529 < 0) { _Context->x_Auto529=0; }
		_Context->y_Auto529 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto529 < 0) { _Context->y_Auto529=0; }
			accept_animation_parameters_show(_Context);

		visual_thaw(_Context->x_Auto529,_Context->y_Auto529,520,160);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_animation_parameters_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_animation_parameters_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_animation_parameters_event(
struct accept_animation_parameters_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(4);
		if (_Context->trigger_Cancel == mb ) return(5);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto529+499) )  
	&&  (my >= (_Context->y_Auto529+4) )  
	&&  (mx <= (_Context->x_Auto529+516) )  
	&&  (my <= (_Context->y_Auto529+20) )) {
		return(1);	/* Auto529 */

		}
	if ((mx >= (_Context->x_Auto529+483) )  
	&&  (my >= (_Context->y_Auto529+4) )  
	&&  (mx <= (_Context->x_Auto529+500) )  
	&&  (my <= (_Context->y_Auto529+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vrecrep.htm");
			};
		return(-1);	/* Auto529 */

		}
	if ((mx >= (_Context->x_Auto529+467) )  
	&&  (my >= (_Context->y_Auto529+4) )  
	&&  (mx <= (_Context->x_Auto529+484) )  
	&&  (my <= (_Context->y_Auto529+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_animation_parameters_show(_Context);
		return(-1);	/* Auto529 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto529+4) )  
		&&  (my >= (_Context->y_Auto529+4) )  
		&&  (mx <= (_Context->x_Auto529+452) )  
		&&  (my <= (_Context->y_Auto529+20) )) {
			return( Auto529action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto529+20) ) 
	&&  ( my >= (_Context->y_Auto529+60) ) 
	&&  ( mx <= (_Context->x_Auto529+20+472) ) 
	&&  ( my <= (_Context->y_Auto529+60+16))) {
		return(2); /* FileName */
		}
	if (( mx >= (_Context->x_Auto529+130+0) ) 
	&&  ( my >= (_Context->y_Auto529+100) ) 
	&&  ( mx <= (_Context->x_Auto529+130+250) ) 
	&&  ( my <= (_Context->y_Auto529+100+16))) {
		return(3); /* Mode */
		}
	if (( mx >= (_Context->x_Auto529+20) ) 
	&&  ( my >= (_Context->y_Auto529+100) ) 
	&&  ( mx <= (_Context->x_Auto529+20+100) ) 
	&&  ( my <= (_Context->y_Auto529+100+30))) {
		return(4); /* Accept */
		}
	if (( mx >= (_Context->x_Auto529+390) ) 
	&&  ( my >= (_Context->y_Auto529+100) ) 
	&&  ( mx <= (_Context->x_Auto529+390+100) ) 
	&&  ( my <= (_Context->y_Auto529+100+30))) {
		return(5); /* Cancel */
		}

	return(-1);
}


public	int	accept_animation_parameters_focus(struct accept_animation_parameters_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_Auto529+20+1,_Context->y_Auto529+60+1,472,16,vfh[1],_Context->buffer_FileName,59);
			break;
			case	0x3 :
				/* Mode */
				_Context->keycode = visual_select(_Context->x_Auto529+130,_Context->y_Auto529+100,250,46,vfh[1],27,0,parse_selection(_Context->msg_Mode[_Context->language],&_Context->value_Mode),2);
				break;
			case	0x4 :
				/* Accept */
				visual_button(_Context->x_Auto529+20,_Context->y_Auto529+100,100,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto529+20,_Context->y_Auto529+100,100,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x5 :
				/* Cancel */
				visual_button(_Context->x_Auto529+390,_Context->y_Auto529+100,100,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto529+390,_Context->y_Auto529+100,100,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_animation_parameters_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=5;
			accept_animation_parameters_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_animation_parameters_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto529 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* FileName */
						continue;
					case	0x3 :
						/* Mode */
						continue;
					case	0x4 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto529+20,_Context->y_Auto529+100,100,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto529+20,_Context->y_Auto529+100,100,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto529+390,_Context->y_Auto529+100,100,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto529+390,_Context->y_Auto529+100,100,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
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
				_Context->focus_item=5;
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

public	int	accept_animation_parameters(
	char * pFileName,
	char * pMode)
{
	int	status=0;
	struct accept_animation_parameters_context * _Context=(struct accept_animation_parameters_context*) 0;
	status = accept_animation_parameters_create(
	&_Context,
	 pFileName,
	 pMode);
	if ( status != 0) return(status);
	status = accept_animation_parameters_show(_Context);
		enter_modal();
	status = accept_animation_parameters_focus(_Context);
		leave_modal();
	status = accept_animation_parameters_hide(_Context);
	status = accept_animation_parameters_remove(
	_Context,
	 pFileName,
	 pMode);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vrecrep_c */
