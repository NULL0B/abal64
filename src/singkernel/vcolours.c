
#ifndef _vcolours_c
#define _vcolours_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vcolours.xml  */
/* Target         : vcolours.c  */
/* Identification : 0.0-1100085393-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto1524   "Sing : Version 1.0a"
#define fr_Auto1524   "Sing : Version 1.0a"
#define en_Auto1525   ""
#define en_Auto1526   "Widget Colour Selection"
#define fr_Auto1526   "S‚lection du couleur d'un Widget"
#define it_Auto1526   "Widget Colour Selection"
#define es_Auto1526   "Widget Colour Selection"
#define de_Auto1526   "Widget Colour Selection"
#define nl_Auto1526   "Widget Colour Selection"
#define pt_Auto1526   "Widget Colour Selection"
#define xx_Auto1526   "Widget Colour Selection"
#define en_Accept   "Accept"
#define fr_Accept   "&Valider"
#define en_Auto1527   "Foreground"
#define fr_Auto1527   "Caractere"
#define en_fgcolour   ""
#define en_bgcolour   ""
#define en_Auto1528   "Background"
#define fr_Auto1528   "Fond"
#define en_Cancel   "Cancel"
#define fr_Cancel   "&Annuler"
#define en_Auto1529   ""
#define en_Auto1530   ""
#define en_target   ""
static int	vfh[10];

private struct accept_visual_colour_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto1524[8];
	int	x_Auto1524;
	int	y_Auto1524;
	int	w_Auto1524;
	int	h_Auto1524;
	char * msg_Auto1526[8];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Auto1527[8];
	char	buffer_fgcolour[5];
	char	buffer_bgcolour[5];
	char * msg_Auto1528[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char	buffer_target[1251];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};

public	int	accept_visual_colour_create(
	struct accept_visual_colour_context ** cptr,
	char * pfgcolour,
	char * pbgcolour)
{

	int i;
	struct accept_visual_colour_context * _Context=(struct accept_visual_colour_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_visual_colour_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_fgcolour, 4, pfgcolour);
		visual_transferin(_Context->buffer_bgcolour, 4, pbgcolour);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto1524[i]=" ";
	_Context->msg_Auto1524[0]=en_Auto1524;
	_Context->msg_Auto1524[1]=fr_Auto1524;
	_Context->x_Auto1524=165;
	_Context->y_Auto1524=30;
	_Context->w_Auto1524=470;
	_Context->h_Auto1524=540;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1526[i]=" ";
	_Context->msg_Auto1526[0]=en_Auto1526;
	_Context->msg_Auto1526[1]=fr_Auto1526;
	_Context->msg_Auto1526[2]=it_Auto1526;
	_Context->msg_Auto1526[3]=es_Auto1526;
	_Context->msg_Auto1526[4]=de_Auto1526;
	_Context->msg_Auto1526[5]=nl_Auto1526;
	_Context->msg_Auto1526[6]=pt_Auto1526;
	_Context->msg_Auto1526[7]=xx_Auto1526;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Auto1527[i]=" ";
	_Context->msg_Auto1527[0]=en_Auto1527;
	_Context->msg_Auto1527[1]=fr_Auto1527;
	for (i=0; i < 8; i++)_Context->msg_Auto1528[i]=" ";
	_Context->msg_Auto1528[0]=en_Auto1528;
	_Context->msg_Auto1528[1]=fr_Auto1528;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto1524,_Context->y_Auto1524,470+10,540+10);
	return(0);
}

public 	int	accept_visual_colour_hide(struct accept_visual_colour_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto1524,_Context->y_Auto1524);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_visual_colour_remove(
	struct accept_visual_colour_context * _Context,
	char * pfgcolour,
	char * pbgcolour)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_fgcolour, 4, pfgcolour);
		visual_transferout(_Context->buffer_bgcolour, 4, pbgcolour);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_fgcolour_show(struct accept_visual_colour_context * _Context) {
	int i;
	int j;
	int v;
	char*sptr;
	int slen;
	for(v=0,sptr=_Context->buffer_fgcolour,slen=4,i=0;
	i<slen;i++){
	if((*(sptr+i)>='0')&&(*(sptr+i)<='9'))
	v=((v*10)+(*(sptr+i)-'0'));
	}
	if(((i=(v/16))<16)
	&&((j=(v%16))<16)){
	visual_filzone(
	_Context->x_Auto1524+30+((400/16)*j),
	_Context->y_Auto1524+60+((400/16)*i),
	(400/16),(400/16),v,9);
	}
	visual_frame(_Context->x_Auto1524+230,_Context->y_Auto1524+488,32+2,16+2,5);
visual_text(_Context->x_Auto1524+230+1,_Context->y_Auto1524+488+1,32,16,vfh[1],16,0,_Context->buffer_fgcolour,4,0);

	filzone(_Context->x_Auto1524+230+32+8,_Context->y_Auto1524+488,32*2,16,v);
	return(-1);
}
private int on_bgcolour_show(struct accept_visual_colour_context * _Context) {
	int i;
	int j;
	int v;
	char*sptr;
	int slen;
	for(v=0,sptr=_Context->buffer_bgcolour,slen=4,i=0;
	i<slen;i++){
	if((*(sptr+i)>='0')&&(*(sptr+i)<='9'))
	v=((v*10)+(*(sptr+i)-'0'));
	}
	if(((i=(v/16))<16)
	&&((j=(v%16))<16)){
	visual_filzone(
	_Context->x_Auto1524+30+((400/16)*j),
	_Context->y_Auto1524+60+((400/16)*i),
	(400/16),(400/16),v|0x0F00,9);
	}
	visual_frame(_Context->x_Auto1524+230,_Context->y_Auto1524+508,32+2,16+2,5);
visual_text(_Context->x_Auto1524+230+1,_Context->y_Auto1524+508+1,32,16,vfh[1],16,0,_Context->buffer_bgcolour,4,0);

	filzone(_Context->x_Auto1524+230+32+8,_Context->y_Auto1524+508,32*2,16,v);
	return(-1);
}
private int on_target_show(struct accept_visual_colour_context * _Context) {
	int i;
	int j;
	visual_freeze();
	visual_frame(_Context->x_Auto1524+30,_Context->y_Auto1524+60,400+2,400+2,5);
visual_text(_Context->x_Auto1524+30+1,_Context->y_Auto1524+60+1,400,400,vfh[1],27,0,_Context->buffer_target,1250,0);
;
	for(i=0;i<16;i++){
	for(j=0;j<16;j++){
	filzone(
	_Context->x_Auto1524+30+((400/16)*j),
	_Context->y_Auto1524+60+((400/16)*i),
	(400/16),(400/16),((i*16)+j));
	}
	}
	visual_thaw(_Context->x_Auto1524+30,_Context->y_Auto1524+60,400,400);
	on_fgcolour_show(_Context);
	on_bgcolour_show(_Context);
	return(-1);
}

public	int	accept_visual_colour_show(struct accept_visual_colour_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto1524,_Context->y_Auto1524);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto1524,_Context->y_Auto1524,470,540,vfh[2],_Context->msg_Auto1524[_Context->language],strlen(_Context->msg_Auto1524[_Context->language]),0x407);
	visual_frame(_Context->x_Auto1524+20,_Context->y_Auto1524+480,420,50,2);
	visual_text(_Context->x_Auto1524+10,_Context->y_Auto1524+30,450,20,vfh[3],16,0,_Context->msg_Auto1526[_Context->language],strlen(_Context->msg_Auto1526[_Context->language]),1283);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto1524+30,_Context->y_Auto1524+490,90,32,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	visual_text(_Context->x_Auto1524+150,_Context->y_Auto1524+490,70,16,vfh[2],16,0,_Context->msg_Auto1527[_Context->language],strlen(_Context->msg_Auto1527[_Context->language]),1282);
	visual_text(_Context->x_Auto1524+150,_Context->y_Auto1524+510,70,16,vfh[2],16,0,_Context->msg_Auto1528[_Context->language],strlen(_Context->msg_Auto1528[_Context->language]),1282);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto1524+340,_Context->y_Auto1524+490,88,32,vfh[2],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_filzone(_Context->x_Auto1524+30,_Context->y_Auto1524+60,420,420,19,12);
	visual_filzone(_Context->x_Auto1524+20,_Context->y_Auto1524+50,420,420,27,11);
	(void) on_target_show(_Context);
	visual_thaw(_Context->x_Auto1524,_Context->y_Auto1524,470,540);
	visual_thaw(_Context->x_Auto1524,_Context->y_Auto1524,470,540);

	return(0);
}

private int Auto1524action(struct accept_visual_colour_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_visual_colour_hide(_Context);

		_Context->x_Auto1524 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto1524 < 0) { _Context->x_Auto1524=0; }
		_Context->y_Auto1524 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto1524 < 0) { _Context->y_Auto1524=0; }
			accept_visual_colour_show(_Context);

		visual_thaw(_Context->x_Auto1524,_Context->y_Auto1524,470,540);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_visual_colour_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_visual_colour_context * _Context) {
	return(27);
	return(-1);
}
private int on_target_event(struct accept_visual_colour_context * _Context) {
	int r,c,b;
	int v=0;
	char*sptr=(char*)0;
	int slen;
	switch(visual_event(1)){
	case 32:/*mimo up*/
	switch(visual_event(2)){
	case 1:
	sptr=_Context->buffer_fgcolour;
	slen=4;
	break;
	case 2:
	sptr=_Context->buffer_bgcolour;
	slen=4;
	break;
	}
		r=visual_event(6);
	c=visual_event(7);
	r-=_Context->y_Auto1524+60;
	c-=_Context->x_Auto1524+30;
	c/=(400/16);
	r/=(400/16);
	v=((r*16)+c);
	if(sptr){
	sprintf(sptr,"%u",v);
	on_target_show(_Context);
	}
	}
	return(-1);
}


public	int	accept_visual_colour_event(
struct accept_visual_colour_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(2);
		if (_Context->trigger_Cancel == mb ) return(5);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto1524+449) )  
	&&  (my >= (_Context->y_Auto1524+4) )  
	&&  (mx <= (_Context->x_Auto1524+466) )  
	&&  (my <= (_Context->y_Auto1524+20) )) {
		return(1);	/* Auto1524 */

		}
	if ((mx >= (_Context->x_Auto1524+433) )  
	&&  (my >= (_Context->y_Auto1524+4) )  
	&&  (mx <= (_Context->x_Auto1524+450) )  
	&&  (my <= (_Context->y_Auto1524+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcolours.htm");
			};
		return(-1);	/* Auto1524 */

		}
	if ((mx >= (_Context->x_Auto1524+417) )  
	&&  (my >= (_Context->y_Auto1524+4) )  
	&&  (mx <= (_Context->x_Auto1524+434) )  
	&&  (my <= (_Context->y_Auto1524+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_visual_colour_show(_Context);
		return(-1);	/* Auto1524 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto1524+4) )  
		&&  (my >= (_Context->y_Auto1524+4) )  
		&&  (mx <= (_Context->x_Auto1524+402) )  
		&&  (my <= (_Context->y_Auto1524+20) )) {
			return( Auto1524action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto1524+30) ) 
	&&  ( my >= (_Context->y_Auto1524+490) ) 
	&&  ( mx <= (_Context->x_Auto1524+30+90) ) 
	&&  ( my <= (_Context->y_Auto1524+490+32))) {
		return(2); /* Accept */
		}
	if (( mx >= (_Context->x_Auto1524+230) ) 
	&&  ( my >= (_Context->y_Auto1524+488) ) 
	&&  ( mx <= (_Context->x_Auto1524+230+32) ) 
	&&  ( my <= (_Context->y_Auto1524+488+16))) {
		return(3); /* fgcolour */
		}
	if (( mx >= (_Context->x_Auto1524+230) ) 
	&&  ( my >= (_Context->y_Auto1524+508) ) 
	&&  ( mx <= (_Context->x_Auto1524+230+32) ) 
	&&  ( my <= (_Context->y_Auto1524+508+16))) {
		return(4); /* bgcolour */
		}
	if (( mx >= (_Context->x_Auto1524+340) ) 
	&&  ( my >= (_Context->y_Auto1524+490) ) 
	&&  ( mx <= (_Context->x_Auto1524+340+88) ) 
	&&  ( my <= (_Context->y_Auto1524+490+32))) {
		return(5); /* Cancel */
		}
	if (( mx >= (_Context->x_Auto1524+30) ) 
	&&  ( my >= (_Context->y_Auto1524+60) ) 
	&&  ( mx <= (_Context->x_Auto1524+30+400) ) 
	&&  ( my <= (_Context->y_Auto1524+60+400))) {
		return(6); /* target */
		}

	return(-1);
}
private int on_target_getfocus(struct accept_visual_colour_context * _Context) {
	return(visual_getch());
	return(-1);
}


public	int	accept_visual_colour_focus(struct accept_visual_colour_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Accept */
				visual_button(_Context->x_Auto1524+30,_Context->y_Auto1524+490,90,32,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1524+30,_Context->y_Auto1524+490,90,32,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x5 :
				/* Cancel */
				visual_button(_Context->x_Auto1524+340,_Context->y_Auto1524+490,88,32,vfh[2],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1524+340,_Context->y_Auto1524+490,88,32,vfh[2],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0x6 :
				/* target */
				if ((_Context->keycode = on_target_getfocus(_Context)) != -1) break;
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_visual_colour_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=6;
			accept_visual_colour_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_visual_colour_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1524 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1524+30,_Context->y_Auto1524+490,90,32,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1524+30,_Context->y_Auto1524+490,90,32,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* fgcolour */
						continue;
					case	0x4 :
						/* bgcolour */
						continue;
					case	0x5 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1524+340,_Context->y_Auto1524+490,88,32,vfh[2],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1524+340,_Context->y_Auto1524+490,88,32,vfh[2],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* target */
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_target_event(_Context)) != -1) break;

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

public	int	accept_visual_colour(
	char * pfgcolour,
	char * pbgcolour)
{
	int	status=0;
	struct accept_visual_colour_context * _Context=(struct accept_visual_colour_context*) 0;
	status = accept_visual_colour_create(
	&_Context,
	 pfgcolour,
	 pbgcolour);
	if ( status != 0) return(status);
	status = accept_visual_colour_show(_Context);
		enter_modal();
	status = accept_visual_colour_focus(_Context);
		leave_modal();
	status = accept_visual_colour_hide(_Context);
	status = accept_visual_colour_remove(
	_Context,
	 pfgcolour,
	 pbgcolour);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcolours_c */
