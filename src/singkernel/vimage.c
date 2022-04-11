
#ifndef _vimage_c
#define _vimage_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vimage.xml  */
/* Target         : vimage.c  */
/* Identification : 0.0-1100085189-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_auto193   "Sing : Version 1.0a"
#define fr_auto193   "Sing : Version 1.0a"
#define en_Auto720   "skin.gif"
#define fr_Auto720   "skin.gif"
#define en_auto220   "Image"
#define fr_auto220   "Image"
#define en_auto196   "Dimension"
#define fr_auto196   "Dimension"
#define it_auto196   "Dimension"
#define es_auto196   "Dimension"
#define de_auto196   "Dimension"
#define nl_auto196   "Dimension"
#define pt_auto196   "Dimension"
#define xx_auto196   "Dimension"
#define en_auto198   "Width"
#define fr_auto198   "Largeur"
#define it_auto198   ""
#define es_auto198   ""
#define de_auto198   ""
#define nl_auto198   ""
#define pt_auto198   ""
#define xx_auto198   ""
#define en_auto199   "Height"
#define fr_auto199   "Hauteur"
#define it_auto199   "Height"
#define es_auto199   "Height"
#define de_auto199   "Height"
#define nl_auto199   "Height"
#define pt_auto199   "Height"
#define xx_auto199   "Height"
#define en_Accept   "Accept"
#define fr_Accept   "&Valider"
#define en_Cancel   "Cancel"
#define fr_Cancel   "&Annuler"
#define en_MakeFit   "Make Fit"
#define fr_MakeFit   "Redimensioner"
#define it_MakeFit   "Make Fit"
#define es_MakeFit   "Make Fit"
#define de_MakeFit   "Make Fit"
#define nl_MakeFit   "Make Fit"
#define pt_MakeFit   "Make Fit"
#define xx_MakeFit   "Make Fit"
static int	vfh[10];

private struct accept_image_dimensions_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto193[8];
	int	x_auto193;
	int	y_auto193;
	int	w_auto193;
	int	h_auto193;
	char * msg_Auto720[8];
	char * msg_auto220[8];
	char * msg_auto196[8];
	char * msg_auto198[8];
	char * msg_auto199[8];
	char	buffer_Width[9];
	char	buffer_Height[9];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_MakeFit[8];
	int	trigger_MakeFit;
	int	value_MakeFit;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[4];
	};

public	int	accept_image_dimensions_create(
	struct accept_image_dimensions_context ** cptr,
	char * pWidth,
	char * pHeight,
	char * pMakeFit)
{

	int i;
	struct accept_image_dimensions_context * _Context=(struct accept_image_dimensions_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_image_dimensions_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Width, 8, pWidth);
		visual_transferin(_Context->buffer_Height, 8, pHeight);
		visual_transferin((void *) 0, 0, pMakeFit);
		if (!( pMakeFit )) _Context->value_MakeFit=0;
		else	_Context->value_MakeFit = *((int *)pMakeFit);
		}
	for (i=0; i < 8; i++)_Context->msg_auto193[i]=" ";
	_Context->msg_auto193[0]=en_auto193;
	_Context->msg_auto193[1]=fr_auto193;
	_Context->x_auto193=300;
	_Context->y_auto193=175;
	_Context->w_auto193=200;
	_Context->h_auto193=250;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto720[i]=" ";
	_Context->msg_Auto720[0]=en_Auto720;
	_Context->msg_Auto720[1]=fr_Auto720;
	for (i=0; i < 8; i++)_Context->msg_auto220[i]=" ";
	_Context->msg_auto220[0]=en_auto220;
	_Context->msg_auto220[1]=fr_auto220;
	for (i=0; i < 8; i++)_Context->msg_auto196[i]=" ";
	_Context->msg_auto196[0]=en_auto196;
	_Context->msg_auto196[1]=fr_auto196;
	_Context->msg_auto196[2]=it_auto196;
	_Context->msg_auto196[3]=es_auto196;
	_Context->msg_auto196[4]=de_auto196;
	_Context->msg_auto196[5]=nl_auto196;
	_Context->msg_auto196[6]=pt_auto196;
	_Context->msg_auto196[7]=xx_auto196;
	for (i=0; i < 8; i++)_Context->msg_auto198[i]=" ";
	_Context->msg_auto198[0]=en_auto198;
	_Context->msg_auto198[1]=fr_auto198;
	_Context->msg_auto198[2]=it_auto198;
	_Context->msg_auto198[3]=es_auto198;
	_Context->msg_auto198[4]=de_auto198;
	_Context->msg_auto198[5]=nl_auto198;
	_Context->msg_auto198[6]=pt_auto198;
	_Context->msg_auto198[7]=xx_auto198;
	for (i=0; i < 8; i++)_Context->msg_auto199[i]=" ";
	_Context->msg_auto199[0]=en_auto199;
	_Context->msg_auto199[1]=fr_auto199;
	_Context->msg_auto199[2]=it_auto199;
	_Context->msg_auto199[3]=es_auto199;
	_Context->msg_auto199[4]=de_auto199;
	_Context->msg_auto199[5]=nl_auto199;
	_Context->msg_auto199[6]=pt_auto199;
	_Context->msg_auto199[7]=xx_auto199;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	for (i=0; i < 8; i++)_Context->msg_MakeFit[i]=" ";
	_Context->msg_MakeFit[0]=en_MakeFit;
	_Context->msg_MakeFit[1]=fr_MakeFit;
	_Context->msg_MakeFit[2]=it_MakeFit;
	_Context->msg_MakeFit[3]=es_MakeFit;
	_Context->msg_MakeFit[4]=de_MakeFit;
	_Context->msg_MakeFit[5]=nl_MakeFit;
	_Context->msg_MakeFit[6]=pt_MakeFit;
	_Context->msg_MakeFit[7]=xx_MakeFit;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto193,_Context->y_auto193,200+10,250+10);
	return(0);
}

public 	int	accept_image_dimensions_hide(struct accept_image_dimensions_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto193,_Context->y_auto193);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_image_dimensions_remove(
	struct accept_image_dimensions_context * _Context,
	char * pWidth,
	char * pHeight,
	char * pMakeFit)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Width, 8, pWidth);
		visual_transferout(_Context->buffer_Height, 8, pHeight);
		visual_transferout((void *) 0, 0, pMakeFit);
		if ( pMakeFit != (char *) 0)
			*((int*)pMakeFit) = _Context->value_MakeFit;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_image_dimensions_show(struct accept_image_dimensions_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto193,_Context->y_auto193);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_auto193,_Context->y_auto193,200,250,vfh[2],_Context->msg_auto193[_Context->language],strlen(_Context->msg_auto193[_Context->language]),0x407);
	visual_image(_Context->x_auto193+3,_Context->y_auto193+22,194,223,_Context->msg_Auto720[_Context->language],4);
	visual_text(_Context->x_auto193+10,_Context->y_auto193+40,160,20,vfh[3],27,0,_Context->msg_auto220[_Context->language],strlen(_Context->msg_auto220[_Context->language]),1027);
	visual_text(_Context->x_auto193+10,_Context->y_auto193+130,160,20,vfh[3],27,0,_Context->msg_auto196[_Context->language],strlen(_Context->msg_auto196[_Context->language]),1027);
	visual_text(_Context->x_auto193+20,_Context->y_auto193+70,68,20,vfh[2],27,0,_Context->msg_auto198[_Context->language],strlen(_Context->msg_auto198[_Context->language]),258);
	visual_text(_Context->x_auto193+20,_Context->y_auto193+100,68,20,vfh[2],27,0,_Context->msg_auto199[_Context->language],strlen(_Context->msg_auto199[_Context->language]),258);
	visual_frame(_Context->x_auto193+90,_Context->y_auto193+70,64+2,16+2,5);
	visual_text(_Context->x_auto193+90+1,_Context->y_auto193+70+1,64,16,vfh[1],27,0,_Context->buffer_Width,8,0);
	visual_frame(_Context->x_auto193+90,_Context->y_auto193+100,64+2,16+2,5);
	visual_text(_Context->x_auto193+90+1,_Context->y_auto193+100+1,64,16,vfh[1],27,0,_Context->buffer_Height,8,0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto193+10,_Context->y_auto193+200,84,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto193+100,_Context->y_auto193+200,84,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	_Context->trigger_MakeFit=visual_trigger_code(_Context->msg_MakeFit[_Context->language],strlen(_Context->msg_MakeFit[_Context->language]));
	visual_check(_Context->x_auto193+20,_Context->y_auto193+160,150,20,vfh[2],27,0,_Context->msg_MakeFit[_Context->language],strlen(_Context->msg_MakeFit[_Context->language]),_Context->value_MakeFit|0);
	visual_thaw(_Context->x_auto193,_Context->y_auto193,200,250);
	visual_thaw(_Context->x_auto193,_Context->y_auto193,200,250);

	return(0);
}

private int auto193action(struct accept_image_dimensions_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_image_dimensions_hide(_Context);

		_Context->x_auto193 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto193 < 0) { _Context->x_auto193=0; }
		_Context->y_auto193 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto193 < 0) { _Context->y_auto193=0; }
			accept_image_dimensions_show(_Context);

		visual_thaw(_Context->x_auto193,_Context->y_auto193,200,250);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_image_dimensions_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_image_dimensions_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_image_dimensions_event(
struct accept_image_dimensions_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(4);
		if (_Context->trigger_Cancel == mb ) return(5);
		if (_Context->trigger_MakeFit == mb ) return(6);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto193+179) )  
	&&  (my >= (_Context->y_auto193+4) )  
	&&  (mx <= (_Context->x_auto193+196) )  
	&&  (my <= (_Context->y_auto193+20) )) {
		return(1);	/* auto193 */

		}
	if ((mx >= (_Context->x_auto193+163) )  
	&&  (my >= (_Context->y_auto193+4) )  
	&&  (mx <= (_Context->x_auto193+180) )  
	&&  (my <= (_Context->y_auto193+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vimage.htm");
			};
		return(-1);	/* auto193 */

		}
	if ((mx >= (_Context->x_auto193+147) )  
	&&  (my >= (_Context->y_auto193+4) )  
	&&  (mx <= (_Context->x_auto193+164) )  
	&&  (my <= (_Context->y_auto193+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_image_dimensions_show(_Context);
		return(-1);	/* auto193 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto193+4) )  
		&&  (my >= (_Context->y_auto193+4) )  
		&&  (mx <= (_Context->x_auto193+132) )  
		&&  (my <= (_Context->y_auto193+20) )) {
			return( auto193action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto193+90) ) 
	&&  ( my >= (_Context->y_auto193+70) ) 
	&&  ( mx <= (_Context->x_auto193+90+64) ) 
	&&  ( my <= (_Context->y_auto193+70+16))) {
		return(2); /* Width */
		}
	if (( mx >= (_Context->x_auto193+90) ) 
	&&  ( my >= (_Context->y_auto193+100) ) 
	&&  ( mx <= (_Context->x_auto193+90+64) ) 
	&&  ( my <= (_Context->y_auto193+100+16))) {
		return(3); /* Height */
		}
	if (( mx >= (_Context->x_auto193+10) ) 
	&&  ( my >= (_Context->y_auto193+200) ) 
	&&  ( mx <= (_Context->x_auto193+10+84) ) 
	&&  ( my <= (_Context->y_auto193+200+32))) {
		return(4); /* Accept */
		}
	if (( mx >= (_Context->x_auto193+100) ) 
	&&  ( my >= (_Context->y_auto193+200) ) 
	&&  ( mx <= (_Context->x_auto193+100+84) ) 
	&&  ( my <= (_Context->y_auto193+200+32))) {
		return(5); /* Cancel */
		}
	if (( mx >= (_Context->x_auto193+20) ) 
	&&  ( my >= (_Context->y_auto193+160) ) 
	&&  ( mx <= (_Context->x_auto193+20+150) ) 
	&&  ( my <= (_Context->y_auto193+160+20))) {
		return(6); /* MakeFit */
		}

	return(-1);
}


public	int	accept_image_dimensions_focus(struct accept_image_dimensions_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_auto193+90+1,_Context->y_auto193+70+1,64,16,vfh[1],_Context->buffer_Width,8);
			break;
			case	0x3 :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_auto193+90+1,_Context->y_auto193+100+1,64,16,vfh[1],_Context->buffer_Height,8);
			break;
			case	0x4 :
				/* Accept */
				visual_button(_Context->x_auto193+10,_Context->y_auto193+200,84,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto193+10,_Context->y_auto193+200,84,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x5 :
				/* Cancel */
				visual_button(_Context->x_auto193+100,_Context->y_auto193+200,84,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto193+100,_Context->y_auto193+200,84,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0x6 :
				/* MakeFit */
				visual_check(_Context->x_auto193+20,_Context->y_auto193+160,150,20,vfh[2],27,0,_Context->msg_MakeFit[_Context->language],strlen(_Context->msg_MakeFit[_Context->language]),(_Context->value_MakeFit |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto193+20,_Context->y_auto193+160,150,20,vfh[2],27,0,_Context->msg_MakeFit[_Context->language],strlen(_Context->msg_MakeFit[_Context->language]),(_Context->value_MakeFit |0));
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_image_dimensions_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=6;
			accept_image_dimensions_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_image_dimensions_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto193 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Width */
						continue;
					case	0x3 :
						/* Height */
						continue;
					case	0x4 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto193+10,_Context->y_auto193+200,84,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto193+10,_Context->y_auto193+200,84,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto193+100,_Context->y_auto193+200,84,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto193+100,_Context->y_auto193+200,84,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* MakeFit */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MakeFit += 1;
							_Context->value_MakeFit &= 1;
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

public	int	accept_image_dimensions(
	char * pWidth,
	char * pHeight,
	char * pMakeFit)
{
	int	status=0;
	struct accept_image_dimensions_context * _Context=(struct accept_image_dimensions_context*) 0;
	status = accept_image_dimensions_create(
	&_Context,
	 pWidth,
	 pHeight,
	 pMakeFit);
	if ( status != 0) return(status);
	status = accept_image_dimensions_show(_Context);
		enter_modal();
	status = accept_image_dimensions_focus(_Context);
		leave_modal();
	status = accept_image_dimensions_hide(_Context);
	status = accept_image_dimensions_remove(
	_Context,
	 pWidth,
	 pHeight,
	 pMakeFit);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vimage_c */
