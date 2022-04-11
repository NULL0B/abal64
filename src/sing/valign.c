
#ifndef _valign_c
#define _valign_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : valign.xml                                               */
/* Target         : valign.c                                                 */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto3533   "Sing : Version 1.0a"
#define fr_Auto3533   "Sing : Version 1.0a"
#define it_Auto3533   "Sing : Version 1.0a"
#define es_Auto3533   "Sing : Version 1.0a"
#define de_Auto3533   "Sing : Version 1.0a"
#define nl_Auto3533   "Sing : Version 1.0a"
#define pt_Auto3533   "Sing : Version 1.0a"
#define xx_Auto3533   "Sing : Version 1.0a"
#define en__Auto3533   ""
#define en_Auto3534   "Spacial Alignment of 3D Camera Items"
#define fr_Auto3534   "Alignement 3D des composants"
#define it_Auto3534   "Spacial Alignment of 3D Camera Items"
#define es_Auto3534   "Spacial Alignment of 3D Camera Items"
#define de_Auto3534   "Spacial Alignment of 3D Camera Items"
#define nl_Auto3534   "Spacial Alignment of 3D Camera Items"
#define pt_Auto3534   "Spacial Alignment of 3D Camera Items"
#define xx_Auto3534   "Spacial Alignment of 3D Camera Items"
#define en__Auto3534   ""
#define fr__Auto3534   ""
#define it__Auto3534   ""
#define es__Auto3534   ""
#define de__Auto3534   ""
#define nl__Auto3534   ""
#define pt__Auto3534   ""
#define xx__Auto3534   ""
#define en_Auto3536   "Accept"
#define fr_Auto3536   "&Valider"
#define it_Auto3536   "Accept"
#define es_Auto3536   "Accept"
#define de_Auto3536   "Accept"
#define nl_Auto3536   "Accept"
#define pt_Auto3536   "Accept"
#define xx_Auto3536   "Accept"
#define en1_Primary "Primary X"
#define fr1_Primary "X Primaire"
#define it1_Primary "Primary X"
#define es1_Primary "Primary X"
#define de1_Primary "Primary X"
#define nl1_Primary "Primary X"
#define pt1_Primary "Primary X"
#define xx1_Primary "Primary X"
#define en1__Primary ""
#define fr1__Primary ""
#define it1__Primary ""
#define es1__Primary ""
#define de1__Primary ""
#define nl1__Primary ""
#define pt1__Primary ""
#define xx1__Primary ""
#define en_Auto3537   "Cancel"
#define fr_Auto3537   "&Annuler"
#define it_Auto3537   "Cancel"
#define es_Auto3537   "Cancel"
#define de_Auto3537   "Cancel"
#define nl_Auto3537   "Cancel"
#define pt_Auto3537   "Cancel"
#define xx_Auto3537   "Cancel"
#define en2_Primary "Primary Y"
#define fr2_Primary "Y Primaire"
#define it2_Primary "Primary Y"
#define es2_Primary "Primary Y"
#define de2_Primary "Primary Y"
#define nl2_Primary "Primary Y"
#define pt2_Primary "Primary Y"
#define xx2_Primary "Primary Y"
#define en2__Primary ""
#define fr2__Primary ""
#define it2__Primary ""
#define es2__Primary ""
#define de2__Primary ""
#define nl2__Primary ""
#define pt2__Primary ""
#define xx2__Primary ""
#define en3_Primary "Primary Z"
#define fr3_Primary "Z Primaire"
#define it3_Primary "Primary Z"
#define es3_Primary "Primary Z"
#define de3_Primary "Primary Z"
#define nl3_Primary "Primary Z"
#define pt3_Primary "Primary Z"
#define xx3_Primary "Primary Z"
#define en3__Primary ""
#define fr3__Primary ""
#define it3__Primary ""
#define es3__Primary ""
#define de3__Primary ""
#define nl3__Primary ""
#define pt3__Primary ""
#define xx3__Primary ""

private struct accept_camera_alignment_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3533[8];
	char * hint_Auto3533[8];
	int	x_Auto3533;
	int	y_Auto3533;
	int	w_Auto3533;
	int	h_Auto3533;
	char * msg_Auto3534[8];
	char * hint_Auto3534[8];
	char * hint_Auto3535[8];
	char * msg_Auto3536[8];
	int	trigger_Auto3536;
	char * hint_Auto3536[8];
	char * msg1_Primary[8];
	int 	trigger1_Primary;	char * hint1_Primary[8];
	int	value_Primary;
	char * msg_Auto3537[8];
	int	trigger_Auto3537;
	char * hint_Auto3537[8];
	char * msg2_Primary[8];
	int 	trigger2_Primary;	char * hint2_Primary[8];
	char * msg3_Primary[8];
	int 	trigger3_Primary;	char * hint3_Primary[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];
private int on_Auto3536_event(struct accept_camera_alignment_context * _Context);
private int on_Auto3537_event(struct accept_camera_alignment_context * _Context);

public	int	accept_camera_alignment_create(
	struct accept_camera_alignment_context ** cptr,
	char * pPrimary)
{

	int i;
	struct accept_camera_alignment_context * _Context=(struct accept_camera_alignment_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("bmap0414.fmf",12);
	if (!(_Context = allocate( sizeof( struct accept_camera_alignment_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
		_Context->value_Primary=0;
		_Context->value_Primary=0;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"W");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pPrimary);
		if (!( pPrimary )) _Context->value_Primary=0;
		else	_Context->value_Primary = *((int *)pPrimary);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3533[i]=" ";
	_Context->msg_Auto3533[0]=en_Auto3533;
	_Context->msg_Auto3533[1]=fr_Auto3533;
	_Context->msg_Auto3533[2]=it_Auto3533;
	_Context->msg_Auto3533[3]=es_Auto3533;
	_Context->msg_Auto3533[4]=de_Auto3533;
	_Context->msg_Auto3533[5]=nl_Auto3533;
	_Context->msg_Auto3533[6]=pt_Auto3533;
	_Context->msg_Auto3533[7]=xx_Auto3533;
	_Context->hint_Auto3533[0]=en__Auto3533;
	_Context->x_Auto3533=130;
	_Context->y_Auto3533=175;
	_Context->w_Auto3533=540;
	_Context->h_Auto3533=250;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3534[i]=" ";
	_Context->msg_Auto3534[0]=en_Auto3534;
	_Context->msg_Auto3534[1]=fr_Auto3534;
	_Context->msg_Auto3534[2]=it_Auto3534;
	_Context->msg_Auto3534[3]=es_Auto3534;
	_Context->msg_Auto3534[4]=de_Auto3534;
	_Context->msg_Auto3534[5]=nl_Auto3534;
	_Context->msg_Auto3534[6]=pt_Auto3534;
	_Context->msg_Auto3534[7]=xx_Auto3534;
	_Context->hint_Auto3534[0]=en__Auto3534;
	_Context->hint_Auto3534[1]=fr__Auto3534;
	_Context->hint_Auto3534[2]=it__Auto3534;
	_Context->hint_Auto3534[3]=es__Auto3534;
	_Context->hint_Auto3534[4]=de__Auto3534;
	_Context->hint_Auto3534[5]=nl__Auto3534;
	_Context->hint_Auto3534[6]=pt__Auto3534;
	_Context->hint_Auto3534[7]=xx__Auto3534;
	for (i=0; i < 8; i++)_Context->msg_Auto3536[i]=" ";
	_Context->msg_Auto3536[0]=en_Auto3536;
	_Context->msg_Auto3536[1]=fr_Auto3536;
	_Context->msg_Auto3536[2]=it_Auto3536;
	_Context->msg_Auto3536[3]=es_Auto3536;
	_Context->msg_Auto3536[4]=de_Auto3536;
	_Context->msg_Auto3536[5]=nl_Auto3536;
	_Context->msg_Auto3536[6]=pt_Auto3536;
	_Context->msg_Auto3536[7]=xx_Auto3536;
	for (i=0; i < 8; i++)_Context->msg1_Primary[i]=" ";
	_Context->msg1_Primary[0]=en1_Primary;
	_Context->msg1_Primary[1]=fr1_Primary;
	_Context->msg1_Primary[2]=it1_Primary;
	_Context->msg1_Primary[3]=es1_Primary;
	_Context->msg1_Primary[4]=de1_Primary;
	_Context->msg1_Primary[5]=nl1_Primary;
	_Context->msg1_Primary[6]=pt1_Primary;
	_Context->msg1_Primary[7]=xx1_Primary;
	_Context->hint1_Primary[0]=en1__Primary;
	_Context->hint1_Primary[1]=fr1__Primary;
	_Context->hint1_Primary[2]=it1__Primary;
	_Context->hint1_Primary[3]=es1__Primary;
	_Context->hint1_Primary[4]=de1__Primary;
	_Context->hint1_Primary[5]=nl1__Primary;
	_Context->hint1_Primary[6]=pt1__Primary;
	_Context->hint1_Primary[7]=xx1__Primary;
	for (i=0; i < 8; i++)_Context->msg_Auto3537[i]=" ";
	_Context->msg_Auto3537[0]=en_Auto3537;
	_Context->msg_Auto3537[1]=fr_Auto3537;
	_Context->msg_Auto3537[2]=it_Auto3537;
	_Context->msg_Auto3537[3]=es_Auto3537;
	_Context->msg_Auto3537[4]=de_Auto3537;
	_Context->msg_Auto3537[5]=nl_Auto3537;
	_Context->msg_Auto3537[6]=pt_Auto3537;
	_Context->msg_Auto3537[7]=xx_Auto3537;
	for (i=0; i < 8; i++)_Context->msg2_Primary[i]=" ";
	_Context->msg2_Primary[0]=en2_Primary;
	_Context->msg2_Primary[1]=fr2_Primary;
	_Context->msg2_Primary[2]=it2_Primary;
	_Context->msg2_Primary[3]=es2_Primary;
	_Context->msg2_Primary[4]=de2_Primary;
	_Context->msg2_Primary[5]=nl2_Primary;
	_Context->msg2_Primary[6]=pt2_Primary;
	_Context->msg2_Primary[7]=xx2_Primary;
	_Context->hint2_Primary[0]=en2__Primary;
	_Context->hint2_Primary[1]=fr2__Primary;
	_Context->hint2_Primary[2]=it2__Primary;
	_Context->hint2_Primary[3]=es2__Primary;
	_Context->hint2_Primary[4]=de2__Primary;
	_Context->hint2_Primary[5]=nl2__Primary;
	_Context->hint2_Primary[6]=pt2__Primary;
	_Context->hint2_Primary[7]=xx2__Primary;
	for (i=0; i < 8; i++)_Context->msg3_Primary[i]=" ";
	_Context->msg3_Primary[0]=en3_Primary;
	_Context->msg3_Primary[1]=fr3_Primary;
	_Context->msg3_Primary[2]=it3_Primary;
	_Context->msg3_Primary[3]=es3_Primary;
	_Context->msg3_Primary[4]=de3_Primary;
	_Context->msg3_Primary[5]=nl3_Primary;
	_Context->msg3_Primary[6]=pt3_Primary;
	_Context->msg3_Primary[7]=xx3_Primary;
	_Context->hint3_Primary[0]=en3__Primary;
	_Context->hint3_Primary[1]=fr3__Primary;
	_Context->hint3_Primary[2]=it3__Primary;
	_Context->hint3_Primary[3]=es3__Primary;
	_Context->hint3_Primary[4]=de3__Primary;
	_Context->hint3_Primary[5]=nl3__Primary;
	_Context->hint3_Primary[6]=pt3__Primary;
	_Context->hint3_Primary[7]=xx3__Primary;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(130,175,540+10,250+10);
	return(0);
}

public 	int	accept_camera_alignment_hide(struct accept_camera_alignment_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,130,175);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_camera_alignment_remove(
	struct accept_camera_alignment_context * _Context,
	char * pPrimary)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"W");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pPrimary);
		if ( pPrimary != (char *) 0)
			*((int*)pPrimary) = _Context->value_Primary;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_camera_alignment_show(struct accept_camera_alignment_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,130,175);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(130,175,540,250,vfh[2],_Context->msg_Auto3533[_Context->language],strlen(_Context->msg_Auto3533[_Context->language]),0x407);
	visual_text(150,205,500,30,vfh[3],16,0,_Context->msg_Auto3534[_Context->language],strlen(_Context->msg_Auto3534[_Context->language]),1283);
	visual_frame(140,255,510,100,3);
	_Context->trigger_Auto3536=visual_trigger_code(_Context->msg_Auto3536[_Context->language],strlen(_Context->msg_Auto3536[_Context->language]));
	visual_button(150,365,126,32,vfh[2],27,28,_Context->msg_Auto3536[_Context->language],strlen(_Context->msg_Auto3536[_Context->language]),0);
	_Context->trigger1_Primary=visual_trigger_code(_Context->msg1_Primary[_Context->language],strlen(_Context->msg1_Primary[_Context->language]));
	visual_radio(150,265,208,16,vfh[2],27,28,_Context->msg1_Primary[_Context->language],strlen(_Context->msg1_Primary[_Context->language]),_Context->value_Primary,1);
	_Context->trigger_Auto3537=visual_trigger_code(_Context->msg_Auto3537[_Context->language],strlen(_Context->msg_Auto3537[_Context->language]));
	visual_button(520,365,128,32,vfh[2],27,28,_Context->msg_Auto3537[_Context->language],strlen(_Context->msg_Auto3537[_Context->language]),0);
	_Context->trigger2_Primary=visual_trigger_code(_Context->msg2_Primary[_Context->language],strlen(_Context->msg2_Primary[_Context->language]));
	visual_radio(150,295,208,16,vfh[2],27,28,_Context->msg2_Primary[_Context->language],strlen(_Context->msg2_Primary[_Context->language]),_Context->value_Primary,2);
	_Context->trigger3_Primary=visual_trigger_code(_Context->msg3_Primary[_Context->language],strlen(_Context->msg3_Primary[_Context->language]));
	visual_radio(150,325,208,16,vfh[2],27,28,_Context->msg3_Primary[_Context->language],strlen(_Context->msg3_Primary[_Context->language]),_Context->value_Primary,3);
	visual_thaw(130,175,540,250);

	return(0);
}
private int on_Auto3536_event(struct accept_camera_alignment_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3537_event(struct accept_camera_alignment_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_camera_alignment_event(
struct accept_camera_alignment_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3536 == mb ) return(2);
		if (_Context->trigger1_Primary == mb ) return(3);
		if (_Context->trigger_Auto3537 == mb ) return(4);
		if (_Context->trigger2_Primary == mb ) return(5);
		if (_Context->trigger3_Primary == mb ) return(6);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= 649 )  
	&&  (my >= 179 )  
	&&  (mx <= 665 )  
	&&  (my <= 195 )) {
		return(1);	/* Auto3533 */

		}
	if ((mx >= 633 )  
	&&  (my >= 179 )  
	&&  (mx <= 649 )  
	&&  (my <= 195 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("valign.htm");
			};
		return(-1);	/* Auto3533 */

		}
	if ((mx >= 617 )  
	&&  (my >= 179 )  
	&&  (mx <= 633 )  
	&&  (my <= 195 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_camera_alignment_show(_Context);
		return(-1);	/* Auto3533 */

		}
		}
	if (( mx >= 150 ) 
	&&  ( my >= 365 ) 
	&&  ( mx <= 276 ) 
	&&  ( my <= 397 )) {
		return(2); /* Auto3536 */
		}
	if (( mx >= 150 ) 
	&&  ( my >= 265 ) 
	&&  ( mx <= 358 ) 
	&&  ( my <= 281 )) {
		return(3); /* Primary */
		}
	if (( mx >= 520 ) 
	&&  ( my >= 365 ) 
	&&  ( mx <= 648 ) 
	&&  ( my <= 397 )) {
		return(4); /* Auto3537 */
		}
	if (( mx >= 150 ) 
	&&  ( my >= 295 ) 
	&&  ( mx <= 358 ) 
	&&  ( my <= 311 )) {
		return(5); /* Primary */
		}
	if (( mx >= 150 ) 
	&&  ( my >= 325 ) 
	&&  ( mx <= 358 ) 
	&&  ( my <= 341 )) {
		return(6); /* Primary */
		}

	return(-1);
}


public	int	accept_camera_alignment_focus(struct accept_camera_alignment_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto3536 */
				_Context->trigger_Auto3536=visual_trigger_code(_Context->msg_Auto3536[_Context->language],strlen(_Context->msg_Auto3536[_Context->language]));
				visual_button(150,365,126,32,vfh[2],27,28,_Context->msg_Auto3536[_Context->language],strlen(_Context->msg_Auto3536[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3536=visual_trigger_code(_Context->msg_Auto3536[_Context->language],strlen(_Context->msg_Auto3536[_Context->language]));
	visual_button(150,365,126,32,vfh[2],27,28,_Context->msg_Auto3536[_Context->language],strlen(_Context->msg_Auto3536[_Context->language]),0);
				break;
			case	0x3 :
				/* Primary */
				_Context->keycode = visual_getch();
				break;
			case	0x4 :
				/* Auto3537 */
				_Context->trigger_Auto3537=visual_trigger_code(_Context->msg_Auto3537[_Context->language],strlen(_Context->msg_Auto3537[_Context->language]));
				visual_button(520,365,128,32,vfh[2],27,28,_Context->msg_Auto3537[_Context->language],strlen(_Context->msg_Auto3537[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3537=visual_trigger_code(_Context->msg_Auto3537[_Context->language],strlen(_Context->msg_Auto3537[_Context->language]));
	visual_button(520,365,128,32,vfh[2],27,28,_Context->msg_Auto3537[_Context->language],strlen(_Context->msg_Auto3537[_Context->language]),0);
				break;
			case	0x5 :
				/* Primary */
				_Context->keycode = visual_getch();
				break;
			case	0x6 :
				/* Primary */
				_Context->keycode = visual_getch();
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_camera_alignment_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=6;
			accept_camera_alignment_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_camera_alignment_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3533 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto3536 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3536=visual_trigger_code(_Context->msg_Auto3536[_Context->language],strlen(_Context->msg_Auto3536[_Context->language]));
						visual_button(150,365,126,32,vfh[2],27,28,_Context->msg_Auto3536[_Context->language],strlen(_Context->msg_Auto3536[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3536=visual_trigger_code(_Context->msg_Auto3536[_Context->language],strlen(_Context->msg_Auto3536[_Context->language]));
	visual_button(150,365,126,32,vfh[2],27,28,_Context->msg_Auto3536[_Context->language],strlen(_Context->msg_Auto3536[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3536_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Primary */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Primary = 1;
						accept_camera_alignment_show(_Context);
						}
					continue;
				case	0x4 :
					/* Auto3537 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3537=visual_trigger_code(_Context->msg_Auto3537[_Context->language],strlen(_Context->msg_Auto3537[_Context->language]));
						visual_button(520,365,128,32,vfh[2],27,28,_Context->msg_Auto3537[_Context->language],strlen(_Context->msg_Auto3537[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3537=visual_trigger_code(_Context->msg_Auto3537[_Context->language],strlen(_Context->msg_Auto3537[_Context->language]));
	visual_button(520,365,128,32,vfh[2],27,28,_Context->msg_Auto3537[_Context->language],strlen(_Context->msg_Auto3537[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3537_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Primary */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Primary = 2;
						accept_camera_alignment_show(_Context);
						}
					continue;
				case	0x6 :
					/* Primary */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Primary = 3;
						accept_camera_alignment_show(_Context);
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
				_Context->focus_item=6;
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

public	int	accept_camera_alignment(
	char * pPrimary)
{
	int	status=0;
	struct accept_camera_alignment_context * _Context=(struct accept_camera_alignment_context*) 0;
	status = accept_camera_alignment_create(
	&_Context,
	 pPrimary);
	if ( status != 0) return(status);
	status = accept_camera_alignment_show(_Context);
		enter_modal();
	status = accept_camera_alignment_focus(_Context);
		leave_modal();
	status = accept_camera_alignment_hide(_Context);
	status = accept_camera_alignment_remove(
	_Context,
	 pPrimary);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _valign_c */
