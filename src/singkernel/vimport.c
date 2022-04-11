
#ifndef _vimport_c 
#define _vimport_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vimport.xml  */
/* Target         : vimport.c  */
/* Identification : 0.0-1100085182-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_auto2   "Sing : Version 1.0a"
#define fr_auto2   "Sing : Version 1.0a"
#define en_Auto4867   "skin.gif"
#define fr_Auto4867   "skin.gif"
#define en_auto27   "Import Font from Image"
#define fr_auto27   "Import d'Image de Fonte"
#define it_auto27   ""
#define es_auto27   ""
#define de_auto27   ""
#define nl_auto27   ""
#define pt_auto27   ""
#define xx_auto27   ""
#define en_auto28   "Cell Wdith"
#define fr_auto28   "Largeur"
#define it_auto28   ""
#define es_auto28   ""
#define de_auto28   ""
#define nl_auto28   ""
#define pt_auto28   ""
#define xx_auto28   ""
#define en_auto31   "Cell Height"
#define fr_auto31   "Hauteur"
#define it_auto31   ""
#define es_auto31   ""
#define de_auto31   ""
#define nl_auto31   ""
#define pt_auto31   ""
#define xx_auto31   ""
#define en_Auto4868   "Automatic"
#define fr_Auto4868   "&Automatique"
#define en_Prompted   "&Prompted"
#define fr_Prompted   "&Prompt‚"
#define it_Prompted   ""
#define es_Prompted   ""
#define de_Prompted   ""
#define nl_Prompted   ""
#define pt_Prompted   ""
#define xx_Prompted   ""
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
static int	vfh[10];

private struct accept_font_import_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto2[8];
	int	x_auto2;
	int	y_auto2;
	int	w_auto2;
	int	h_auto2;
	char * msg_Auto4867[8];
	char * msg_auto27[8];
	char * msg_auto28[8];
	char * msg_auto31[8];
	char	buffer_CellWidth[8];
	char	buffer_CellHeight[8];
	char * msg_Auto4868[8];
	int	trigger_Auto4868;
	char * msg_Prompted[8];
	int	trigger_Prompted;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};

public	int	accept_font_import_create(
	struct accept_font_import_context ** cptr,
	char * pCellWidth,
	char * pCellHeight)
{

	int i;
	struct accept_font_import_context * _Context=(struct accept_font_import_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_font_import_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_CellWidth, 7, pCellWidth);
		visual_transferin(_Context->buffer_CellHeight, 7, pCellHeight);
		}
	for (i=0; i < 8; i++)_Context->msg_auto2[i]=" ";
	_Context->msg_auto2[0]=en_auto2;
	_Context->msg_auto2[1]=fr_auto2;
	_Context->x_auto2=235;
	_Context->y_auto2=200;
	_Context->w_auto2=330;
	_Context->h_auto2=200;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto4867[i]=" ";
	_Context->msg_Auto4867[0]=en_Auto4867;
	_Context->msg_Auto4867[1]=fr_Auto4867;
	for (i=0; i < 8; i++)_Context->msg_auto27[i]=" ";
	_Context->msg_auto27[0]=en_auto27;
	_Context->msg_auto27[1]=fr_auto27;
	_Context->msg_auto27[2]=it_auto27;
	_Context->msg_auto27[3]=es_auto27;
	_Context->msg_auto27[4]=de_auto27;
	_Context->msg_auto27[5]=nl_auto27;
	_Context->msg_auto27[6]=pt_auto27;
	_Context->msg_auto27[7]=xx_auto27;
	for (i=0; i < 8; i++)_Context->msg_auto28[i]=" ";
	_Context->msg_auto28[0]=en_auto28;
	_Context->msg_auto28[1]=fr_auto28;
	_Context->msg_auto28[2]=it_auto28;
	_Context->msg_auto28[3]=es_auto28;
	_Context->msg_auto28[4]=de_auto28;
	_Context->msg_auto28[5]=nl_auto28;
	_Context->msg_auto28[6]=pt_auto28;
	_Context->msg_auto28[7]=xx_auto28;
	for (i=0; i < 8; i++)_Context->msg_auto31[i]=" ";
	_Context->msg_auto31[0]=en_auto31;
	_Context->msg_auto31[1]=fr_auto31;
	_Context->msg_auto31[2]=it_auto31;
	_Context->msg_auto31[3]=es_auto31;
	_Context->msg_auto31[4]=de_auto31;
	_Context->msg_auto31[5]=nl_auto31;
	_Context->msg_auto31[6]=pt_auto31;
	_Context->msg_auto31[7]=xx_auto31;
	for (i=0; i < 8; i++)_Context->msg_Auto4868[i]=" ";
	_Context->msg_Auto4868[0]=en_Auto4868;
	_Context->msg_Auto4868[1]=fr_Auto4868;
	for (i=0; i < 8; i++)_Context->msg_Prompted[i]=" ";
	_Context->msg_Prompted[0]=en_Prompted;
	_Context->msg_Prompted[1]=fr_Prompted;
	_Context->msg_Prompted[2]=it_Prompted;
	_Context->msg_Prompted[3]=es_Prompted;
	_Context->msg_Prompted[4]=de_Prompted;
	_Context->msg_Prompted[5]=nl_Prompted;
	_Context->msg_Prompted[6]=pt_Prompted;
	_Context->msg_Prompted[7]=xx_Prompted;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto2,_Context->y_auto2,330+10,200+10);
	return(0);
}

public 	int	accept_font_import_hide(struct accept_font_import_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_font_import_remove(
	struct accept_font_import_context * _Context,
	char * pCellWidth,
	char * pCellHeight)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_CellWidth, 7, pCellWidth);
		visual_transferout(_Context->buffer_CellHeight, 7, pCellHeight);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_font_import_show(struct accept_font_import_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_auto2,_Context->y_auto2,330,200,vfh[2],_Context->msg_auto2[_Context->language],strlen(_Context->msg_auto2[_Context->language]),0x407);
	visual_image(_Context->x_auto2+3,_Context->y_auto2+22,323,175,_Context->msg_Auto4867[_Context->language],4);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+30,276,20,vfh[3],27,0,_Context->msg_auto27[_Context->language],strlen(_Context->msg_auto27[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+80,72,20,vfh[2],27,0,_Context->msg_auto28[_Context->language],strlen(_Context->msg_auto28[_Context->language]),258);
	visual_text(_Context->x_auto2+170,_Context->y_auto2+80,72,20,vfh[2],27,0,_Context->msg_auto31[_Context->language],strlen(_Context->msg_auto31[_Context->language]),258);
	visual_frame(_Context->x_auto2+90,_Context->y_auto2+80,60+2,20+2,5);
	visual_text(_Context->x_auto2+90+1,_Context->y_auto2+80+1,60,20,vfh[1],26,0,_Context->buffer_CellWidth,7,0);
	visual_frame(_Context->x_auto2+240,_Context->y_auto2+80,60+2,20+2,5);
	visual_text(_Context->x_auto2+240+1,_Context->y_auto2+80+1,60,20,vfh[1],26,0,_Context->buffer_CellHeight,7,0);
	_Context->trigger_Auto4868=visual_trigger_code(_Context->msg_Auto4868[_Context->language],strlen(_Context->msg_Auto4868[_Context->language]));
	visual_button(_Context->x_auto2+10,_Context->y_auto2+150,98,32,vfh[2],26,0,_Context->msg_Auto4868[_Context->language],strlen(_Context->msg_Auto4868[_Context->language]),0);
	_Context->trigger_Prompted=visual_trigger_code(_Context->msg_Prompted[_Context->language],strlen(_Context->msg_Prompted[_Context->language]));
	visual_button(_Context->x_auto2+110,_Context->y_auto2+150,98,32,vfh[2],26,0,_Context->msg_Prompted[_Context->language],strlen(_Context->msg_Prompted[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto2+210,_Context->y_auto2+150,112,32,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_thaw(_Context->x_auto2,_Context->y_auto2,330,200);
	visual_thaw(_Context->x_auto2,_Context->y_auto2,330,200);

	return(0);
}

private int auto2action(struct accept_font_import_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_font_import_hide(_Context);

		_Context->x_auto2 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto2 < 0) { _Context->x_auto2=0; }
		_Context->y_auto2 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto2 < 0) { _Context->y_auto2=0; }
			accept_font_import_show(_Context);

		visual_thaw(_Context->x_auto2,_Context->y_auto2,330,200);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Auto4868_event(struct accept_font_import_context * _Context) {
	return(13);
	return(-1);
}
private int on_Prompted_event(struct accept_font_import_context * _Context) {
	return(26);
	return(-1);
}
private int on_Cancel_event(struct accept_font_import_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_font_import_event(
struct accept_font_import_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto4868 == mb ) return(4);
		if (_Context->trigger_Prompted == mb ) return(5);
		if (_Context->trigger_Cancel == mb ) return(6);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto2+309) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+326) )  
	&&  (my <= (_Context->y_auto2+20) )) {
		return(1);	/* auto2 */

		}
	if ((mx >= (_Context->x_auto2+293) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+310) )  
	&&  (my <= (_Context->y_auto2+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vimport.htm");
			};
		return(-1);	/* auto2 */

		}
	if ((mx >= (_Context->x_auto2+277) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+294) )  
	&&  (my <= (_Context->y_auto2+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_font_import_show(_Context);
		return(-1);	/* auto2 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto2+4) )  
		&&  (my >= (_Context->y_auto2+4) )  
		&&  (mx <= (_Context->x_auto2+262) )  
		&&  (my <= (_Context->y_auto2+20) )) {
			return( auto2action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto2+90) ) 
	&&  ( my >= (_Context->y_auto2+80) ) 
	&&  ( mx <= (_Context->x_auto2+90+60) ) 
	&&  ( my <= (_Context->y_auto2+80+20))) {
		return(2); /* CellWidth */
		}
	if (( mx >= (_Context->x_auto2+240) ) 
	&&  ( my >= (_Context->y_auto2+80) ) 
	&&  ( mx <= (_Context->x_auto2+240+60) ) 
	&&  ( my <= (_Context->y_auto2+80+20))) {
		return(3); /* CellHeight */
		}
	if (( mx >= (_Context->x_auto2+10) ) 
	&&  ( my >= (_Context->y_auto2+150) ) 
	&&  ( mx <= (_Context->x_auto2+10+98) ) 
	&&  ( my <= (_Context->y_auto2+150+32))) {
		return(4); /* Auto4868 */
		}
	if (( mx >= (_Context->x_auto2+110) ) 
	&&  ( my >= (_Context->y_auto2+150) ) 
	&&  ( mx <= (_Context->x_auto2+110+98) ) 
	&&  ( my <= (_Context->y_auto2+150+32))) {
		return(5); /* Prompted */
		}
	if (( mx >= (_Context->x_auto2+210) ) 
	&&  ( my >= (_Context->y_auto2+150) ) 
	&&  ( mx <= (_Context->x_auto2+210+112) ) 
	&&  ( my <= (_Context->y_auto2+150+32))) {
		return(6); /* Cancel */
		}

	return(-1);
}


public	int	accept_font_import_focus(struct accept_font_import_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* CellWidth */
				_Context->keycode = visual_edit(_Context->x_auto2+90+1,_Context->y_auto2+80+1,60,20,vfh[1],_Context->buffer_CellWidth,7);
			break;
			case	0x3 :
				/* CellHeight */
				_Context->keycode = visual_edit(_Context->x_auto2+240+1,_Context->y_auto2+80+1,60,20,vfh[1],_Context->buffer_CellHeight,7);
			break;
			case	0x4 :
				/* Auto4868 */
				visual_button(_Context->x_auto2+10,_Context->y_auto2+150,98,32,vfh[2],26,0,_Context->msg_Auto4868[_Context->language],strlen(_Context->msg_Auto4868[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+10,_Context->y_auto2+150,98,32,vfh[2],26,0,_Context->msg_Auto4868[_Context->language],strlen(_Context->msg_Auto4868[_Context->language]),0);
				break;
			case	0x5 :
				/* Prompted */
				visual_button(_Context->x_auto2+110,_Context->y_auto2+150,98,32,vfh[2],26,0,_Context->msg_Prompted[_Context->language],strlen(_Context->msg_Prompted[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+110,_Context->y_auto2+150,98,32,vfh[2],26,0,_Context->msg_Prompted[_Context->language],strlen(_Context->msg_Prompted[_Context->language]),0);
				break;
			case	0x6 :
				/* Cancel */
				visual_button(_Context->x_auto2+210,_Context->y_auto2+150,112,32,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+210,_Context->y_auto2+150,112,32,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_font_import_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=6;
			accept_font_import_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_font_import_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto2 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* CellWidth */
						continue;
					case	0x3 :
						/* CellHeight */
						continue;
					case	0x4 :
						/* Auto4868 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+10,_Context->y_auto2+150,98,32,vfh[2],26,0,_Context->msg_Auto4868[_Context->language],strlen(_Context->msg_Auto4868[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+10,_Context->y_auto2+150,98,32,vfh[2],26,0,_Context->msg_Auto4868[_Context->language],strlen(_Context->msg_Auto4868[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto4868_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Prompted */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+110,_Context->y_auto2+150,98,32,vfh[2],26,0,_Context->msg_Prompted[_Context->language],strlen(_Context->msg_Prompted[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+110,_Context->y_auto2+150,98,32,vfh[2],26,0,_Context->msg_Prompted[_Context->language],strlen(_Context->msg_Prompted[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Prompted_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+210,_Context->y_auto2+150,112,32,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+210,_Context->y_auto2+150,112,32,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
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

public	int	accept_font_import(
	char * pCellWidth,
	char * pCellHeight)
{
	int	status=0;
	struct accept_font_import_context * _Context=(struct accept_font_import_context*) 0;
	status = accept_font_import_create(
	&_Context,
	 pCellWidth,
	 pCellHeight);
	if ( status != 0) return(status);
	status = accept_font_import_show(_Context);
		enter_modal();
	status = accept_font_import_focus(_Context);
		leave_modal();
	status = accept_font_import_hide(_Context);
	status = accept_font_import_remove(
	_Context,
	 pCellWidth,
	 pCellHeight);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vimport_c */
