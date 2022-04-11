
#ifndef _template_c
#define _template_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : template.xml                                             */
/* Target         : template.c                                               */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct template_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	value_WidgetClass;
	int	value_NationalLanguage;
	int	value_TextFont;
	int	value_Align;
	int	value_ImageFormat;
	char	signature[3];
	};
static int	vfh[16];
private int on_WidgetClass_losefocus(struct template_context * _Context);
private int on_Accept_event(struct template_context * _Context);
private int on_Cancel_event(struct template_context * _Context);
private int on_FullScreen_event(struct template_context * _Context);
static short	CheckClass(struct template_context * _Context);
static void	ChangeClass(struct template_context * _Context);

/*	----------------------	*/
/*	C h e c k C l a s s ()	*/
/*	----------------------	*/
static short	CheckClass(struct template_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	if(!(pSpecificWidgetProperties->pWidgetClass))
	return(0);
	else if(_Context->value_WidgetClass!=*((int*)pSpecificWidgetProperties->pWidgetClass))
	return(1);
	else return(0);

}

/*	------------------------	*/
/*	C h a n g e C l a s s ()	*/
/*	------------------------	*/
static void	ChangeClass(struct template_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	if(!(pSpecificWidgetProperties->pWidgetClass))
	return;
	else{
	*((int*)pSpecificWidgetProperties->pWidgetClass)=_Context->value_WidgetClass;
	return;
	}

}

public	int	template_create(
	struct template_context ** cptr,
	char * pNationalLanguage,
	char * pImageFormat)
{

	int i;
	struct template_context * _Context=(struct template_context*)0;
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
	if (!(_Context = allocate( sizeof( struct template_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=8;
		_Context->value_WidgetClass=0;
		_Context->value_TextFont=0;
		_Context->value_Align=0;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pNationalLanguage);
		if (!( pNationalLanguage )) _Context->value_NationalLanguage=0;
		else	_Context->value_NationalLanguage = *((int *)pNationalLanguage);
		visual_transferin((void *) 0, 0, pImageFormat);
		if (!( pImageFormat )) _Context->value_ImageFormat=0;
		else	_Context->value_ImageFormat = *((int *)pImageFormat);
		}
	return(0);
}

public 	int	template_hide(struct template_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	template_remove(
	struct template_context * _Context,
	char * pNationalLanguage,
	char * pImageFormat)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pNationalLanguage);
		if ( pNationalLanguage != (char *) 0)
			*((int*)pNationalLanguage) = _Context->value_NationalLanguage;
		visual_transferout((void *) 0, 0, pImageFormat);
		if ( pImageFormat != (char *) 0)
			*((int*)pImageFormat) = _Context->value_ImageFormat;
		}
	_Context=liberate(_Context);

	return(result);
}

public	int	template_show(struct template_context * _Context)
{
	visual_freeze();
	visual_button(70,0,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1040);
	visual_button(130,0,56,48,vfh[2],34,0,"cancel.gif",strlen("cancel.gif"),1040);
	visual_button(190,0,56,48,vfh[2],28,28,"screen.gif",strlen("screen.gif"),1040);
	visual_select(90,60,126,144,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_select(80,90,140,144,vfh[2],27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),768);
	visual_select(90,120,126,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),768);
	visual_select(90,150,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),768);
	visual_select(100,180,108,58,vfh[1],0,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),0);
	visual_thaw(0,0,176,250);

	return(0);
}
private int on_Accept_event(struct template_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct template_context * _Context) {
	return(27);
	return(-1);
}
private int on_FullScreen_event(struct template_context * _Context) {
		template_hide(_Context);
;
	use_editor(MethodText.buffer,0);
		template_show(_Context);
;
	MethodText.	template_show(_Context);
;
	MethodText.Trigger();
	return(-1);
}


public	int	template_event(
struct template_context * _Context){
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 70 ) 
	&&  ( my >= 0 ) 
	&&  ( mx <= 126 ) 
	&&  ( my <= 48 )) {
		return(1); /* Accept */
		}
	if (( mx >= 130 ) 
	&&  ( my >= 0 ) 
	&&  ( mx <= 186 ) 
	&&  ( my <= 48 )) {
		return(2); /* Cancel */
		}
	if (( mx >= 190 ) 
	&&  ( my >= 0 ) 
	&&  ( mx <= 246 ) 
	&&  ( my <= 48 )) {
		return(3); /* FullScreen */
		}
	if ((mx >= 90 ) 
	&&  (my >= 60 ) 
	&&  (mx <= 216 ) 
	&&  (my <= 76 )) {
		return(4); /* WidgetClass */
		}
	if ((mx >= 80 ) 
	&&  (my >= 90 ) 
	&&  (mx <= 220 ) 
	&&  (my <= 106 )) {
		return(5); /* NationalLanguage */
		}
	if ((mx >= 90 ) 
	&&  (my >= 120 ) 
	&&  (mx <= 216 ) 
	&&  (my <= 136 )) {
		return(6); /* TextFont */
		}
	if ((mx >= 90 ) 
	&&  (my >= 150 ) 
	&&  (mx <= 220 ) 
	&&  (my <= 166 )) {
		return(7); /* Align */
		}
	if ((mx >= 100 ) 
	&&  (my >= 180 ) 
	&&  (mx <= 208 ) 
	&&  (my <= 196 )) {
		return(8); /* ImageFormat */
		}

	return(-1);
}
private int on_WidgetClass_losefocus(struct template_context * _Context) {
	if(CheckClass(_Context)!=0){
	switch(check_widget_change()){
	case 13:
	vwedit_GetVars(_Context);
	return(26);
	case 26:
	ChangeClass(_Context);
	return(26);
	}
	}
	return(-1);
}


public	int	template_focus(struct template_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Accept */
				visual_button(70,0,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1042);
				_Context->keycode = visual_getch();
	visual_button(70,0,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1040);
				break;
			case	0x2 :
				/* Cancel */
				visual_button(130,0,56,48,vfh[2],34,0,"cancel.gif",strlen("cancel.gif"),1042);
				_Context->keycode = visual_getch();
	visual_button(130,0,56,48,vfh[2],34,0,"cancel.gif",strlen("cancel.gif"),1040);
				break;
			case	0x4 :
				/* WidgetClass */
				_Context->keycode = visual_select(90,60,126,144,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				(void) on_WidgetClass_losefocus(_Context);
				break;
			case	0x5 :
				/* NationalLanguage */
				_Context->keycode = visual_select(80,90,140,144,vfh[2],27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),770);
				break;
			case	0x6 :
				/* TextFont */
				_Context->keycode = visual_select(90,120,126,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),770);
				break;
			case	0x7 :
				/* Align */
				_Context->keycode = visual_select(90,150,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),774);
				break;
			case	0x8 :
				/* ImageFormat */
				_Context->keycode = visual_select(100,180,108,58,vfh[1],0,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),2);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			template_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=8;
			template_show(_Context);
			continue;
		case	0x100 :
			if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
			if ((retcode=template_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(70,0,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(70,0,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(130,0,56,48,vfh[2],34,0,"cancel.gif",strlen("cancel.gif"),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(130,0,56,48,vfh[2],34,0,"cancel.gif",strlen("cancel.gif"),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* FullScreen */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(190,0,56,48,vfh[2],28,28,"screen.gif",strlen("screen.gif"),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(190,0,56,48,vfh[2],28,28,"screen.gif",strlen("screen.gif"),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FullScreen_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* WidgetClass */
					continue;
				case	0x5 :
					/* NationalLanguage */
					continue;
				case	0x6 :
					/* TextFont */
					continue;
				case	0x7 :
					/* Align */
					continue;
				case	0x8 :
					/* ImageFormat */
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

public	int	template(
	char * pNationalLanguage,
	char * pImageFormat)
{
	int	status=0;
	struct template_context * _Context=(struct template_context*) 0;
	status = template_create(
	&_Context,
	 pNationalLanguage,
	 pImageFormat);
	if ( status != 0) return(status);
	status = template_show(_Context);
		enter_modal();
	status = template_focus(_Context);
		leave_modal();
	status = template_hide(_Context);
	status = template_remove(
	_Context,
	 pNationalLanguage,
	 pImageFormat);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _template_c */
