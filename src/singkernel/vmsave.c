
#ifndef _vmsave_c
#define _vmsave_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vmsave.xml  */
/* Target         : vmsave.c  */
/* Identification : 0.0-1100085267-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_auto6   "Sing : Version 1.0a"
#define fr_auto6   "Sing : Version 1.0a"
#define en_Auto1149   "skin.gif"
#define fr_Auto1149   "skin.gif"
#define en_auto8   "Name of Application to Save"
#define fr_auto8   "Nom du Projet a Sauver"
#define it_auto8   ""
#define es_auto8   ""
#define de_auto8   ""
#define nl_auto8   ""
#define pt_auto8   ""
#define xx_auto8   ""
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Select   "&Select"
#define fr_Select   "&S‚lection"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
#define en_SaveImages   "Sa&ve Images"
#define fr_SaveImages   "Sa&uve Images"
#define it_SaveImages   ""
#define es_SaveImages   ""
#define de_SaveImages   ""
#define nl_SaveImages   ""
#define pt_SaveImages   ""
#define xx_SaveImages   ""
#define en_SaveForms   "Sav&e Forms"
#define fr_SaveForms   "Sauve &Formulaires"
#define it_SaveForms   ""
#define es_SaveForms   ""
#define de_SaveForms   ""
#define nl_SaveForms   ""
#define pt_SaveForms   ""
#define xx_SaveForms   ""
#define en_SaveAll   "Save A&ll"
#define fr_SaveAll   "Sauver &Tout"
#define en_auto702   "fileicon.gif"
#define fr_auto702   "fileicon.gif"
#define it_auto702   ""
#define es_auto702   ""
#define de_auto702   ""
#define nl_auto702   ""
#define pt_auto702   ""
#define xx_auto702   ""
static int	vfh[10];

private struct accept_modelsave_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto6[8];
	int	x_auto6;
	int	y_auto6;
	int	w_auto6;
	int	h_auto6;
	char * msg_Auto1149[8];
	char * msg_auto8[8];
	char	buffer_FileName[71];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Select[8];
	int	trigger_Select;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_SaveImages[8];
	int	trigger_SaveImages;
	int	value_SaveImages;
	char * msg_SaveForms[8];
	int	trigger_SaveForms;
	int	value_SaveForms;
	char * msg_SaveAll[8];
	int	trigger_SaveAll;
	int	value_SaveAll;
	char * msg_auto702[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[5];
	};

public	int	accept_modelsave_create(
	struct accept_modelsave_context ** cptr,
	char * pFileName,
	char * pSaveImages,
	char * pSaveForms,
	char * pSaveAll)
{

	int i;
	struct accept_modelsave_context * _Context=(struct accept_modelsave_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_modelsave_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=8;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 70, pFileName);
		visual_transferin((void *) 0, 0, pSaveImages);
		if (!( pSaveImages )) _Context->value_SaveImages=0;
		else	_Context->value_SaveImages = *((int *)pSaveImages);
		visual_transferin((void *) 0, 0, pSaveForms);
		if (!( pSaveForms )) _Context->value_SaveForms=0;
		else	_Context->value_SaveForms = *((int *)pSaveForms);
		visual_transferin((void *) 0, 0, pSaveAll);
		if (!( pSaveAll )) _Context->value_SaveAll=0;
		else	_Context->value_SaveAll = *((int *)pSaveAll);
		}
	for (i=0; i < 8; i++)_Context->msg_auto6[i]=" ";
	_Context->msg_auto6[0]=en_auto6;
	_Context->msg_auto6[1]=fr_auto6;
	_Context->x_auto6=100;
	_Context->y_auto6=195;
	_Context->w_auto6=600;
	_Context->h_auto6=210;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1149[i]=" ";
	_Context->msg_Auto1149[0]=en_Auto1149;
	_Context->msg_Auto1149[1]=fr_Auto1149;
	for (i=0; i < 8; i++)_Context->msg_auto8[i]=" ";
	_Context->msg_auto8[0]=en_auto8;
	_Context->msg_auto8[1]=fr_auto8;
	_Context->msg_auto8[2]=it_auto8;
	_Context->msg_auto8[3]=es_auto8;
	_Context->msg_auto8[4]=de_auto8;
	_Context->msg_auto8[5]=nl_auto8;
	_Context->msg_auto8[6]=pt_auto8;
	_Context->msg_auto8[7]=xx_auto8;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	for (i=0; i < 8; i++)_Context->msg_SaveImages[i]=" ";
	_Context->msg_SaveImages[0]=en_SaveImages;
	_Context->msg_SaveImages[1]=fr_SaveImages;
	_Context->msg_SaveImages[2]=it_SaveImages;
	_Context->msg_SaveImages[3]=es_SaveImages;
	_Context->msg_SaveImages[4]=de_SaveImages;
	_Context->msg_SaveImages[5]=nl_SaveImages;
	_Context->msg_SaveImages[6]=pt_SaveImages;
	_Context->msg_SaveImages[7]=xx_SaveImages;
	for (i=0; i < 8; i++)_Context->msg_SaveForms[i]=" ";
	_Context->msg_SaveForms[0]=en_SaveForms;
	_Context->msg_SaveForms[1]=fr_SaveForms;
	_Context->msg_SaveForms[2]=it_SaveForms;
	_Context->msg_SaveForms[3]=es_SaveForms;
	_Context->msg_SaveForms[4]=de_SaveForms;
	_Context->msg_SaveForms[5]=nl_SaveForms;
	_Context->msg_SaveForms[6]=pt_SaveForms;
	_Context->msg_SaveForms[7]=xx_SaveForms;
	for (i=0; i < 8; i++)_Context->msg_SaveAll[i]=" ";
	_Context->msg_SaveAll[0]=en_SaveAll;
	_Context->msg_SaveAll[1]=fr_SaveAll;
	for (i=0; i < 8; i++)_Context->msg_auto702[i]=" ";
	_Context->msg_auto702[0]=en_auto702;
	_Context->msg_auto702[1]=fr_auto702;
	_Context->msg_auto702[2]=it_auto702;
	_Context->msg_auto702[3]=es_auto702;
	_Context->msg_auto702[4]=de_auto702;
	_Context->msg_auto702[5]=nl_auto702;
	_Context->msg_auto702[6]=pt_auto702;
	_Context->msg_auto702[7]=xx_auto702;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto6,_Context->y_auto6,600+10,210+10);
	return(0);
}

public 	int	accept_modelsave_hide(struct accept_modelsave_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto6,_Context->y_auto6);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_modelsave_remove(
	struct accept_modelsave_context * _Context,
	char * pFileName,
	char * pSaveImages,
	char * pSaveForms,
	char * pSaveAll)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 70, pFileName);
		visual_transferout((void *) 0, 0, pSaveImages);
		if ( pSaveImages != (char *) 0)
			*((int*)pSaveImages) = _Context->value_SaveImages;
		visual_transferout((void *) 0, 0, pSaveForms);
		if ( pSaveForms != (char *) 0)
			*((int*)pSaveForms) = _Context->value_SaveForms;
		visual_transferout((void *) 0, 0, pSaveAll);
		if ( pSaveAll != (char *) 0)
			*((int*)pSaveAll) = _Context->value_SaveAll;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_modelsave_show(struct accept_modelsave_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto6,_Context->y_auto6);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_auto6,_Context->y_auto6,600,210,vfh[2],_Context->msg_auto6[_Context->language],strlen(_Context->msg_auto6[_Context->language]),0x407);
	visual_image(_Context->x_auto6+3,_Context->y_auto6+23,594,184,_Context->msg_Auto1149[_Context->language],4);
	visual_text(_Context->x_auto6+20,_Context->y_auto6+40,560,16,vfh[2],38,0,_Context->msg_auto8[_Context->language],strlen(_Context->msg_auto8[_Context->language]),258);
	visual_frame(_Context->x_auto6+21,_Context->y_auto6+60,560+2,16+2,5);
	visual_text(_Context->x_auto6+21+1,_Context->y_auto6+60+1,560,16,vfh[1],16,24,_Context->buffer_FileName,70,0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto6+20,_Context->y_auto6+150,110,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto6+360,_Context->y_auto6+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto6+470,_Context->y_auto6+150,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	_Context->trigger_SaveImages=visual_trigger_code(_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]));
	visual_check(_Context->x_auto6+20,_Context->y_auto6+90,154,16,vfh[2],34,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),_Context->value_SaveImages|0);
	_Context->trigger_SaveForms=visual_trigger_code(_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]));
	visual_check(_Context->x_auto6+181,_Context->y_auto6+88,168,16,vfh[2],34,0,_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]),_Context->value_SaveForms|0);
	_Context->trigger_SaveAll=visual_trigger_code(_Context->msg_SaveAll[_Context->language],strlen(_Context->msg_SaveAll[_Context->language]));
	visual_check(_Context->x_auto6+357,_Context->y_auto6+89,196,16,vfh[2],34,0,_Context->msg_SaveAll[_Context->language],strlen(_Context->msg_SaveAll[_Context->language]),_Context->value_SaveAll|0);
	visual_image(_Context->x_auto6+226,_Context->y_auto6+136,50,50,_Context->msg_auto702[_Context->language],0);
	visual_thaw(_Context->x_auto6,_Context->y_auto6,600,210);
	visual_thaw(_Context->x_auto6,_Context->y_auto6,600,210);

	return(0);
}

private int auto6action(struct accept_modelsave_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_modelsave_hide(_Context);

		_Context->x_auto6 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto6 < 0) { _Context->x_auto6=0; }
		_Context->y_auto6 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto6 < 0) { _Context->y_auto6=0; }
			accept_modelsave_show(_Context);

		visual_thaw(_Context->x_auto6,_Context->y_auto6,600,210);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_modelsave_context * _Context) {
	return(13);
	return(-1);
}
private int on_Select_event(struct accept_modelsave_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_XML);
		accept_modelsave_show(_Context);
;
	return(-1);
}
private int on_Cancel_event(struct accept_modelsave_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_modelsave_event(
struct accept_modelsave_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(3);
		if (_Context->trigger_Select == mb ) return(4);
		if (_Context->trigger_Cancel == mb ) return(5);
		if (_Context->trigger_SaveImages == mb ) return(6);
		if (_Context->trigger_SaveForms == mb ) return(7);
		if (_Context->trigger_SaveAll == mb ) return(8);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto6+579) )  
	&&  (my >= (_Context->y_auto6+4) )  
	&&  (mx <= (_Context->x_auto6+596) )  
	&&  (my <= (_Context->y_auto6+20) )) {
		return(1);	/* auto6 */

		}
	if ((mx >= (_Context->x_auto6+563) )  
	&&  (my >= (_Context->y_auto6+4) )  
	&&  (mx <= (_Context->x_auto6+580) )  
	&&  (my <= (_Context->y_auto6+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vmsave.htm");
			};
		return(-1);	/* auto6 */

		}
	if ((mx >= (_Context->x_auto6+547) )  
	&&  (my >= (_Context->y_auto6+4) )  
	&&  (mx <= (_Context->x_auto6+564) )  
	&&  (my <= (_Context->y_auto6+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_modelsave_show(_Context);
		return(-1);	/* auto6 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto6+4) )  
		&&  (my >= (_Context->y_auto6+4) )  
		&&  (mx <= (_Context->x_auto6+532) )  
		&&  (my <= (_Context->y_auto6+20) )) {
			return( auto6action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto6+21) ) 
	&&  ( my >= (_Context->y_auto6+60) ) 
	&&  ( mx <= (_Context->x_auto6+21+560) ) 
	&&  ( my <= (_Context->y_auto6+60+16))) {
		return(2); /* FileName */
		}
	if (( mx >= (_Context->x_auto6+20) ) 
	&&  ( my >= (_Context->y_auto6+150) ) 
	&&  ( mx <= (_Context->x_auto6+20+110) ) 
	&&  ( my <= (_Context->y_auto6+150+30))) {
		return(3); /* Accept */
		}
	if (( mx >= (_Context->x_auto6+360) ) 
	&&  ( my >= (_Context->y_auto6+150) ) 
	&&  ( mx <= (_Context->x_auto6+360+100) ) 
	&&  ( my <= (_Context->y_auto6+150+30))) {
		return(4); /* Select */
		}
	if (( mx >= (_Context->x_auto6+470) ) 
	&&  ( my >= (_Context->y_auto6+150) ) 
	&&  ( mx <= (_Context->x_auto6+470+110) ) 
	&&  ( my <= (_Context->y_auto6+150+30))) {
		return(5); /* Cancel */
		}
	if (( mx >= (_Context->x_auto6+20) ) 
	&&  ( my >= (_Context->y_auto6+90) ) 
	&&  ( mx <= (_Context->x_auto6+20+154) ) 
	&&  ( my <= (_Context->y_auto6+90+16))) {
		return(6); /* SaveImages */
		}
	if (( mx >= (_Context->x_auto6+181) ) 
	&&  ( my >= (_Context->y_auto6+88) ) 
	&&  ( mx <= (_Context->x_auto6+181+168) ) 
	&&  ( my <= (_Context->y_auto6+88+16))) {
		return(7); /* SaveForms */
		}
	if (( mx >= (_Context->x_auto6+357) ) 
	&&  ( my >= (_Context->y_auto6+89) ) 
	&&  ( mx <= (_Context->x_auto6+357+196) ) 
	&&  ( my <= (_Context->y_auto6+89+16))) {
		return(8); /* SaveAll */
		}

	return(-1);
}


public	int	accept_modelsave_focus(struct accept_modelsave_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_auto6+21+1,_Context->y_auto6+60+1,560,16,vfh[1],_Context->buffer_FileName,70);
			break;
			case	0x3 :
				/* Accept */
				visual_button(_Context->x_auto6+20,_Context->y_auto6+150,110,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto6+20,_Context->y_auto6+150,110,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x4 :
				/* Select */
				visual_button(_Context->x_auto6+360,_Context->y_auto6+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto6+360,_Context->y_auto6+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0x5 :
				/* Cancel */
				visual_button(_Context->x_auto6+470,_Context->y_auto6+150,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto6+470,_Context->y_auto6+150,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0x6 :
				/* SaveImages */
				visual_check(_Context->x_auto6+20,_Context->y_auto6+90,154,16,vfh[2],34,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),(_Context->value_SaveImages |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto6+20,_Context->y_auto6+90,154,16,vfh[2],34,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),(_Context->value_SaveImages |0));
				break;
			case	0x7 :
				/* SaveForms */
				visual_check(_Context->x_auto6+181,_Context->y_auto6+88,168,16,vfh[2],34,0,_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]),(_Context->value_SaveForms |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto6+181,_Context->y_auto6+88,168,16,vfh[2],34,0,_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]),(_Context->value_SaveForms |0));
				break;
			case	0x8 :
				/* SaveAll */
				visual_check(_Context->x_auto6+357,_Context->y_auto6+89,196,16,vfh[2],34,0,_Context->msg_SaveAll[_Context->language],strlen(_Context->msg_SaveAll[_Context->language]),(_Context->value_SaveAll |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto6+357,_Context->y_auto6+89,196,16,vfh[2],34,0,_Context->msg_SaveAll[_Context->language],strlen(_Context->msg_SaveAll[_Context->language]),(_Context->value_SaveAll |0));
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_modelsave_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=8;
			accept_modelsave_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_modelsave_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto6 */
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
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto6+20,_Context->y_auto6+150,110,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto6+20,_Context->y_auto6+150,110,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto6+360,_Context->y_auto6+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto6+360,_Context->y_auto6+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto6+470,_Context->y_auto6+150,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto6+470,_Context->y_auto6+150,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* SaveImages */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SaveImages += 1;
							_Context->value_SaveImages &= 1;
							}
						continue;
					case	0x7 :
						/* SaveForms */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SaveForms += 1;
							_Context->value_SaveForms &= 1;
							}
						continue;
					case	0x8 :
						/* SaveAll */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SaveAll += 1;
							_Context->value_SaveAll &= 1;
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
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_modelsave(
	char * pFileName,
	char * pSaveImages,
	char * pSaveForms,
	char * pSaveAll)
{
	int	status=0;
	struct accept_modelsave_context * _Context=(struct accept_modelsave_context*) 0;
	status = accept_modelsave_create(
	&_Context,
	 pFileName,
	 pSaveImages,
	 pSaveForms,
	 pSaveAll);
	if ( status != 0) return(status);
	status = accept_modelsave_show(_Context);
		enter_modal();
	status = accept_modelsave_focus(_Context);
		leave_modal();
	status = accept_modelsave_hide(_Context);
	status = accept_modelsave_remove(
	_Context,
	 pFileName,
	 pSaveImages,
	 pSaveForms,
	 pSaveAll);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vmsave_c */
