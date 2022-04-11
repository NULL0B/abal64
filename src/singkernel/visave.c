
#ifndef _visave_c
#define _visave_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : visave.xml  */
/* Target         : visave.c  */
/* Identification : 0.0-1100085303-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_auto6   "Sing : Version 1.0a"
#define fr_auto6   "Sing : Version 1.0a"
#define en_Auto1179   "skin.gif"
#define fr_Auto1179   "skin.gif"
#define en_auto707   "imgicon.gif"
#define fr_auto707   "imgicon.gif"
#define en_auto8   "Name of Image to Save"
#define fr_auto8   "Nom de fichier d'Image … Sauver"
#define it_auto8   ""
#define es_auto8   ""
#define de_auto8   ""
#define nl_auto8   ""
#define pt_auto8   ""
#define xx_auto8   ""
#define en_auto235   "File Format"
#define fr_auto235   "Format d'Image"
#define it_auto235   ""
#define es_auto235   ""
#define de_auto235   ""
#define nl_auto235   ""
#define pt_auto235   ""
#define xx_auto235   ""
#define fr_ImageFormat   "Bmp|Gif|Jpeg"
#define it_ImageFormat   "Bmp|Gif|Jpeg"
#define es_ImageFormat   "Bmp|Gif|Jpeg"
#define de_ImageFormat   "Bmp|Gif|Jpeg"
#define nl_ImageFormat   "Bmp|Gif|Jpeg"
#define pt_ImageFormat   "Bmp|Gif|Jpeg"
#define xx_ImageFormat   "Bmp|Gif|Jpeg"
#define en_IsTransparent   "&Transparent"
#define fr_IsTransparent   "&Transparent"
#define it_IsTransparent   "&Transparent"
#define es_IsTransparent   "&Transparent"
#define de_IsTransparent   "&Transparent"
#define nl_IsTransparent   "&Transparent"
#define pt_IsTransparent   "&Transparent"
#define xx_IsTransparent   "&Transparent"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Select   "&Select"
#define fr_Select   "&S‚lection"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
static int	vfh[10];

private struct accept_imagesave_context {
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
	char * msg_Auto1179[8];
	char * msg_auto707[8];
	char * msg_auto8[8];
	char * msg_auto235[8];
	char	buffer_FileName[71];
	char * msg_PathSelection[8];
	int	value_PathSelection;
	char * msg_ImageFormat[8];
	int	value_ImageFormat;
	char * msg_IsTransparent[8];
	int	trigger_IsTransparent;
	int	value_IsTransparent;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Select[8];
	int	trigger_Select;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[5];
	};

public	int	accept_imagesave_create(
	struct accept_imagesave_context ** cptr,
	char * pFileName,
	char * pPathSelection,
	char * pImageFormat,
	char * pIsTransparent)
{

	int i;
	struct accept_imagesave_context * _Context=(struct accept_imagesave_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_imagesave_context ) ) ))
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
		visual_transferin((void *) 0, 0, pPathSelection);
		if (!( pPathSelection )) _Context->value_PathSelection=0;
		else	_Context->value_PathSelection = *((int *)pPathSelection);
		visual_transferin((void *) 0, 0, pImageFormat);
		if (!( pImageFormat )) _Context->value_ImageFormat=0;
		else	_Context->value_ImageFormat = *((int *)pImageFormat);
		visual_transferin((void *) 0, 0, pIsTransparent);
		if (!( pIsTransparent )) _Context->value_IsTransparent=0;
		else	_Context->value_IsTransparent = *((int *)pIsTransparent);
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
	for (i=0; i < 8; i++)_Context->msg_Auto1179[i]=" ";
	_Context->msg_Auto1179[0]=en_Auto1179;
	_Context->msg_Auto1179[1]=fr_Auto1179;
	for (i=0; i < 8; i++)_Context->msg_auto707[i]=" ";
	_Context->msg_auto707[0]=en_auto707;
	_Context->msg_auto707[1]=fr_auto707;
	for (i=0; i < 8; i++)_Context->msg_auto8[i]=" ";
	_Context->msg_auto8[0]=en_auto8;
	_Context->msg_auto8[1]=fr_auto8;
	_Context->msg_auto8[2]=it_auto8;
	_Context->msg_auto8[3]=es_auto8;
	_Context->msg_auto8[4]=de_auto8;
	_Context->msg_auto8[5]=nl_auto8;
	_Context->msg_auto8[6]=pt_auto8;
	_Context->msg_auto8[7]=xx_auto8;
	for (i=0; i < 8; i++)_Context->msg_auto235[i]=" ";
	_Context->msg_auto235[0]=en_auto235;
	_Context->msg_auto235[1]=fr_auto235;
	_Context->msg_auto235[2]=it_auto235;
	_Context->msg_auto235[3]=es_auto235;
	_Context->msg_auto235[4]=de_auto235;
	_Context->msg_auto235[5]=nl_auto235;
	_Context->msg_auto235[6]=pt_auto235;
	_Context->msg_auto235[7]=xx_auto235;
	for (i=0; i < 8; i++)_Context->msg_PathSelection[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_ImageFormat[i]=" ";
	_Context->msg_ImageFormat[1]=fr_ImageFormat;
	_Context->msg_ImageFormat[2]=it_ImageFormat;
	_Context->msg_ImageFormat[3]=es_ImageFormat;
	_Context->msg_ImageFormat[4]=de_ImageFormat;
	_Context->msg_ImageFormat[5]=nl_ImageFormat;
	_Context->msg_ImageFormat[6]=pt_ImageFormat;
	_Context->msg_ImageFormat[7]=xx_ImageFormat;
	for (i=0; i < 8; i++)_Context->msg_IsTransparent[i]=" ";
	_Context->msg_IsTransparent[0]=en_IsTransparent;
	_Context->msg_IsTransparent[1]=fr_IsTransparent;
	_Context->msg_IsTransparent[2]=it_IsTransparent;
	_Context->msg_IsTransparent[3]=es_IsTransparent;
	_Context->msg_IsTransparent[4]=de_IsTransparent;
	_Context->msg_IsTransparent[5]=nl_IsTransparent;
	_Context->msg_IsTransparent[6]=pt_IsTransparent;
	_Context->msg_IsTransparent[7]=xx_IsTransparent;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto6,_Context->y_auto6,600+10,210+10);
	return(0);
}

public 	int	accept_imagesave_hide(struct accept_imagesave_context * _Context)
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

public	int	accept_imagesave_remove(
	struct accept_imagesave_context * _Context,
	char * pFileName,
	char * pPathSelection,
	char * pImageFormat,
	char * pIsTransparent)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 70, pFileName);
		visual_transferout((void *) 0, 0, pPathSelection);
		if ( pPathSelection != (char *) 0)
			*((int*)pPathSelection) = _Context->value_PathSelection;
		visual_transferout((void *) 0, 0, pImageFormat);
		if ( pImageFormat != (char *) 0)
			*((int*)pImageFormat) = _Context->value_ImageFormat;
		visual_transferout((void *) 0, 0, pIsTransparent);
		if ( pIsTransparent != (char *) 0)
			*((int*)pIsTransparent) = _Context->value_IsTransparent;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_imagesave_show(struct accept_imagesave_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto6,_Context->y_auto6);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_auto6,_Context->y_auto6,600,210,vfh[2],_Context->msg_auto6[_Context->language],strlen(_Context->msg_auto6[_Context->language]),0x407);
	visual_image(_Context->x_auto6+3,_Context->y_auto6+21,594,184,_Context->msg_Auto1179[_Context->language],4);
	visual_image(_Context->x_auto6+230,_Context->y_auto6+140,50,50,_Context->msg_auto707[_Context->language],0);
	visual_text(_Context->x_auto6+20,_Context->y_auto6+30,560,16,vfh[2],27,0,_Context->msg_auto8[_Context->language],strlen(_Context->msg_auto8[_Context->language]),258);
	visual_text(_Context->x_auto6+20,_Context->y_auto6+110,100,20,vfh[2],27,0,_Context->msg_auto235[_Context->language],strlen(_Context->msg_auto235[_Context->language]),258);
	visual_frame(_Context->x_auto6+20,_Context->y_auto6+50,560+2,16+2,5);
	visual_text(_Context->x_auto6+20+1,_Context->y_auto6+50+1,560,16,vfh[1],16,24,_Context->buffer_FileName,70,0);
	visual_select(_Context->x_auto6+20,_Context->y_auto6+70,560,80,vfh[1],0,0,parse_selection(GetPathSelection(),&_Context->value_PathSelection),768);
	visual_select(_Context->x_auto6+170,_Context->y_auto6+110,108,58,vfh[1],0,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),0);
	_Context->trigger_IsTransparent=visual_trigger_code(_Context->msg_IsTransparent[_Context->language],strlen(_Context->msg_IsTransparent[_Context->language]));
	visual_check(_Context->x_auto6+360,_Context->y_auto6+110,140,16,vfh[2],27,0,_Context->msg_IsTransparent[_Context->language],strlen(_Context->msg_IsTransparent[_Context->language]),_Context->value_IsTransparent|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto6+20,_Context->y_auto6+150,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto6+360,_Context->y_auto6+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto6+470,_Context->y_auto6+150,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_thaw(_Context->x_auto6,_Context->y_auto6,600,210);
	visual_thaw(_Context->x_auto6,_Context->y_auto6,600,210);

	return(0);
}

private int auto6action(struct accept_imagesave_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_imagesave_hide(_Context);

		_Context->x_auto6 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto6 < 0) { _Context->x_auto6=0; }
		_Context->y_auto6 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto6 < 0) { _Context->y_auto6=0; }
			accept_imagesave_show(_Context);

		visual_thaw(_Context->x_auto6,_Context->y_auto6,600,210);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_imagesave_context * _Context) {
	return(13);
	return(-1);
}
private int on_Select_event(struct accept_imagesave_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_GIF);
		accept_imagesave_show(_Context);
;
	return(-1);
}
private int on_Cancel_event(struct accept_imagesave_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_imagesave_event(
struct accept_imagesave_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsTransparent == mb ) return(5);
		if (_Context->trigger_Accept == mb ) return(6);
		if (_Context->trigger_Select == mb ) return(7);
		if (_Context->trigger_Cancel == mb ) return(8);
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
			visual_help("visave.htm");
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
		accept_imagesave_show(_Context);
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
	if (( mx >= (_Context->x_auto6+20) ) 
	&&  ( my >= (_Context->y_auto6+50) ) 
	&&  ( mx <= (_Context->x_auto6+20+560) ) 
	&&  ( my <= (_Context->y_auto6+50+16))) {
		return(2); /* FileName */
		}
	if (( mx >= (_Context->x_auto6+20+0) ) 
	&&  ( my >= (_Context->y_auto6+70) ) 
	&&  ( mx <= (_Context->x_auto6+20+560) ) 
	&&  ( my <= (_Context->y_auto6+70+16))) {
		return(3); /* PathSelection */
		}
	if (( mx >= (_Context->x_auto6+170+0) ) 
	&&  ( my >= (_Context->y_auto6+110) ) 
	&&  ( mx <= (_Context->x_auto6+170+108) ) 
	&&  ( my <= (_Context->y_auto6+110+16))) {
		return(4); /* ImageFormat */
		}
	if (( mx >= (_Context->x_auto6+360) ) 
	&&  ( my >= (_Context->y_auto6+110) ) 
	&&  ( mx <= (_Context->x_auto6+360+140) ) 
	&&  ( my <= (_Context->y_auto6+110+16))) {
		return(5); /* IsTransparent */
		}
	if (( mx >= (_Context->x_auto6+20) ) 
	&&  ( my >= (_Context->y_auto6+150) ) 
	&&  ( mx <= (_Context->x_auto6+20+120) ) 
	&&  ( my <= (_Context->y_auto6+150+30))) {
		return(6); /* Accept */
		}
	if (( mx >= (_Context->x_auto6+360) ) 
	&&  ( my >= (_Context->y_auto6+150) ) 
	&&  ( mx <= (_Context->x_auto6+360+100) ) 
	&&  ( my <= (_Context->y_auto6+150+30))) {
		return(7); /* Select */
		}
	if (( mx >= (_Context->x_auto6+470) ) 
	&&  ( my >= (_Context->y_auto6+150) ) 
	&&  ( mx <= (_Context->x_auto6+470+110) ) 
	&&  ( my <= (_Context->y_auto6+150+30))) {
		return(8); /* Cancel */
		}

	return(-1);
}


public	int	accept_imagesave_focus(struct accept_imagesave_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_auto6+20+1,_Context->y_auto6+50+1,560,16,vfh[1],_Context->buffer_FileName,70);
			break;
			case	0x3 :
				/* PathSelection */
				_Context->keycode = visual_select(_Context->x_auto6+20,_Context->y_auto6+70,560,80,vfh[1],0,0,parse_selection(GetPathSelection(),&_Context->value_PathSelection),770);
				break;
			case	0x4 :
				/* ImageFormat */
				_Context->keycode = visual_select(_Context->x_auto6+170,_Context->y_auto6+110,108,58,vfh[1],0,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),2);
				break;
			case	0x5 :
				/* IsTransparent */
				visual_check(_Context->x_auto6+360,_Context->y_auto6+110,140,16,vfh[2],27,0,_Context->msg_IsTransparent[_Context->language],strlen(_Context->msg_IsTransparent[_Context->language]),(_Context->value_IsTransparent |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto6+360,_Context->y_auto6+110,140,16,vfh[2],27,0,_Context->msg_IsTransparent[_Context->language],strlen(_Context->msg_IsTransparent[_Context->language]),(_Context->value_IsTransparent |0));
				break;
			case	0x6 :
				/* Accept */
				visual_button(_Context->x_auto6+20,_Context->y_auto6+150,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto6+20,_Context->y_auto6+150,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x7 :
				/* Select */
				visual_button(_Context->x_auto6+360,_Context->y_auto6+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto6+360,_Context->y_auto6+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0x8 :
				/* Cancel */
				visual_button(_Context->x_auto6+470,_Context->y_auto6+150,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto6+470,_Context->y_auto6+150,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_imagesave_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=8;
			accept_imagesave_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_imagesave_event(_Context)) == -1)
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
						/* PathSelection */
						continue;
					case	0x4 :
						/* ImageFormat */
						continue;
					case	0x5 :
						/* IsTransparent */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsTransparent += 1;
							_Context->value_IsTransparent &= 1;
							}
						continue;
					case	0x6 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto6+20,_Context->y_auto6+150,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto6+20,_Context->y_auto6+150,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x7 :
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
					case	0x8 :
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

public	int	accept_imagesave(
	char * pFileName,
	char * pPathSelection,
	char * pImageFormat,
	char * pIsTransparent)
{
	int	status=0;
	struct accept_imagesave_context * _Context=(struct accept_imagesave_context*) 0;
	status = accept_imagesave_create(
	&_Context,
	 pFileName,
	 pPathSelection,
	 pImageFormat,
	 pIsTransparent);
	if ( status != 0) return(status);
	status = accept_imagesave_show(_Context);
		enter_modal();
	status = accept_imagesave_focus(_Context);
		leave_modal();
	status = accept_imagesave_hide(_Context);
	status = accept_imagesave_remove(
	_Context,
	 pFileName,
	 pPathSelection,
	 pImageFormat,
	 pIsTransparent);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _visave_c */
