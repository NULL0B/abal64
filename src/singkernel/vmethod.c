
#ifndef _vmethod_c
#define _vmethod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vmethod.xml  */
/* Target         : vmethod.c  */
/* Identification : 0.0-1100519197-5231.5230 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto440   "Sing : Version 1.0a"
#define fr_Auto440   "Sing : Version 1.0a"
#define it_Auto440   "Sing : Version 1.0a"
#define es_Auto440   "Sing : Version 1.0a"
#define de_Auto440   "Sing : Version 1.0a"
#define nl_Auto440   "Sing : Version 1.0a"
#define pt_Auto440   "Sing : Version 1.0a"
#define xx_Auto440   "Sing : Version 1.0a"
#define en_Auto638   "skin.gif"
#define fr_Auto638   "skin.gif"
#define en_Ok   "&Accept"
#define fr_Ok   "&Valider"
#define it_Ok   "&Accept"
#define es_Ok   "&Accept"
#define de_Ok   "&Accept"
#define nl_Ok   "&Accept"
#define pt_Ok   "&Accept"
#define xx_Ok   "&Tha gu math"
#define en_FullScreen   "&Full Screen"
#define fr_FullScreen   "&Plein Ecran"
#define it_FullScreen   "&Full Screen"
#define es_FullScreen   "&Full Screen"
#define de_FullScreen   "&Full Screen"
#define nl_FullScreen   "&Full Screen"
#define pt_FullScreen   "&Full Screen"
#define xx_FullScreen   "&Sg…il mor"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
#define it_Cancel   "&Cancel"
#define es_Cancel   "&Cancel"
#define de_Cancel   "&Cancel"
#define nl_Cancel   "&Cancel"
#define pt_Cancel   "&Cancel"
#define xx_Cancel   "&Chan Eil"
#define en_MethodPage   "Method"
#define fr_MethodPage   "Methode"
#define it_MethodPage   ""
#define es_MethodPage   ""
#define de_MethodPage   ""
#define nl_MethodPage   ""
#define pt_MethodPage   ""
#define xx_MethodPage   ""
#define en_Auto444   "Visual Forms Method"
#define fr_Auto444   "Methode de Formulaire Visuelle"
#define it_Auto444   ""
#define es_Auto444   ""
#define de_Auto444   ""
#define nl_Auto444   ""
#define pt_Auto444   ""
#define xx_Auto444   ""
#define en_Auto445   "Nature"
#define fr_Auto445   "Nature"
#define it_Auto445   ""
#define es_Auto445   ""
#define de_Auto445   ""
#define nl_Auto445   ""
#define pt_Auto445   ""
#define xx_Auto445   ""
#define en_Auto446   "Name"
#define fr_Auto446   "Nom"
#define it_Auto446   ""
#define es_Auto446   ""
#define de_Auto446   ""
#define nl_Auto446   ""
#define pt_Auto446   ""
#define xx_Auto446   ""
#define en_Auto447   "Parameters"
#define fr_Auto447   "ParamŠtres"
#define it_Auto447   ""
#define es_Auto447   ""
#define de_Auto447   ""
#define nl_Auto447   ""
#define pt_Auto447   ""
#define xx_Auto447   ""
#define en_IsPublic   "Public"
#define fr_IsPublic   "Public"
#define en_IsPointer   "Pointer"
#define fr_IsPointer   "Pointeur"
#define it_IsPointer   ""
#define es_IsPointer   ""
#define de_IsPointer   ""
#define nl_IsPointer   ""
#define pt_IsPointer   ""
#define xx_IsPointer   ""
#define en_MethodType   "void|byte|word|bcd|string|long|class"
#define fr_MethodType   "void|byte|word|bcd|string|long|class"
#define it_MethodType   "void|byte|word|bcd|string|long|class"
#define es_MethodType   "void|byte|word|bcd|string|long|class"
#define de_MethodType   "void|byte|word|bcd|string|long|class"
#define nl_MethodType   "void|byte|word|bcd|string|long|class"
#define pt_MethodType   "void|byte|word|bcd|string|long|class"
#define xx_MethodType   "void|byte|word|bcd|string|long|class"
#define en_MethodClass   ""
#define fr_MethodClass   ""
#define en1_MethodNature "Inline"
#define fr1_MethodNature "Inline"
#define it1_MethodNature "Inline"
#define es1_MethodNature "Inline"
#define de1_MethodNature "Inline"
#define nl1_MethodNature "Inline"
#define pt1_MethodNature "Inline"
#define xx1_MethodNature "Inline"
#define en2_MethodNature "Function"
#define fr2_MethodNature "Function"
#define it2_MethodNature "Function"
#define es2_MethodNature "Function"
#define de2_MethodNature "Function"
#define nl2_MethodNature "Function"
#define pt2_MethodNature "Function"
#define xx2_MethodNature "Function"
#define en3_MethodNature "Virtual"
#define fr3_MethodNature "Virtual"
#define it3_MethodNature "Virtual"
#define es3_MethodNature "Virtual"
#define de3_MethodNature "Virtual"
#define nl3_MethodNature "Virtual"
#define pt3_MethodNature "Virtual"
#define xx3_MethodNature "Virtual"
#define en4_MethodNature "Overload"
#define fr4_MethodNature "Overload"
#define it4_MethodNature "Overload"
#define es4_MethodNature "Overload"
#define de4_MethodNature "Overload"
#define nl4_MethodNature "Overload"
#define pt4_MethodNature "Overload"
#define xx4_MethodNature "Overload"
#define en_MethodName   ""
#define fr_MethodName   ""
#define en_Signature   ""
#define fr_Signature   ""
#define en_BodyPage   "Body"
#define fr_BodyPage   "Corps"
#define it_BodyPage   ""
#define es_BodyPage   ""
#define de_BodyPage   ""
#define nl_BodyPage   ""
#define pt_BodyPage   ""
#define xx_BodyPage   ""
#define en_MethodText   ""
#define fr_MethodText   ""
static int	vfh[10];

private struct accept_forms_method_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[2+1];
	char * msg_Auto440[8];
	int	x_Auto440;
	int	y_Auto440;
	int	w_Auto440;
	int	h_Auto440;
	char * msg_Auto638[8];
	char * msg_Ok[8];
	int	trigger_Ok;
	char * msg_FullScreen[8];
	int	trigger_FullScreen;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_MethodPage[8];
	int	trigger_MethodPage;
	int	page_number;
	char * msg_Auto444[8];
	char * msg_Auto445[8];
	char * msg_Auto446[8];
	char * msg_Auto447[8];
	char * msg_IsPublic[8];
	int	trigger_IsPublic;
	int	value_IsPublic;
	char * msg_IsPointer[8];
	int	trigger_IsPointer;
	int	value_IsPointer;
	char * msg_MethodType[8];
	int	value_MethodType;
	char	buffer_MethodClass[60];
	char * msg1_MethodNature[8];
	int 	trigger1_MethodNature;	int	value_MethodNature;
	char * msg2_MethodNature[8];
	int 	trigger2_MethodNature;	char * msg3_MethodNature[8];
	int 	trigger3_MethodNature;	char * msg4_MethodNature[8];
	int 	trigger4_MethodNature;	char	buffer_MethodName[60];
	char	buffer_Signature[709];
	char * msg_BodyPage[8];
	int	trigger_BodyPage;
	char * buffer_MethodText;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[9];
	};

public	int	accept_forms_method_create(
	struct accept_forms_method_context ** cptr,
	char * pIsPublic,
	char * pIsPointer,
	char * pMethodType,
	char * pMethodClass,
	char * pMethodNature,
	char * pMethodName,
	char * pSignature,
	char * pMethodText)
{

	int i;
	struct accept_forms_method_context * _Context=(struct accept_forms_method_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_forms_method_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=17;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWSWSST");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pIsPublic);
		if (!( pIsPublic )) _Context->value_IsPublic=0;
		else	_Context->value_IsPublic = *((int *)pIsPublic);
		visual_transferin((void *) 0, 0, pIsPointer);
		if (!( pIsPointer )) _Context->value_IsPointer=0;
		else	_Context->value_IsPointer = *((int *)pIsPointer);
		visual_transferin((void *) 0, 0, pMethodType);
		if (!( pMethodType )) _Context->value_MethodType=0;
		else	_Context->value_MethodType = *((int *)pMethodType);
		visual_transferin(_Context->buffer_MethodClass, 59, pMethodClass);
		visual_transferin((void *) 0, 0, pMethodNature);
		if (!( pMethodNature )) _Context->value_MethodNature=0;
		else	_Context->value_MethodNature = *((int *)pMethodNature);
		visual_transferin(_Context->buffer_MethodName, 59, pMethodName);
		visual_transferin(_Context->buffer_Signature, 708, pSignature);
				_Context->buffer_MethodText=(char *) 0;
		visual_transferin(&_Context->buffer_MethodText, 1562, pMethodText);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto440[i]=" ";
	_Context->msg_Auto440[0]=en_Auto440;
	_Context->msg_Auto440[1]=fr_Auto440;
	_Context->msg_Auto440[2]=it_Auto440;
	_Context->msg_Auto440[3]=es_Auto440;
	_Context->msg_Auto440[4]=de_Auto440;
	_Context->msg_Auto440[5]=nl_Auto440;
	_Context->msg_Auto440[6]=pt_Auto440;
	_Context->msg_Auto440[7]=xx_Auto440;
	_Context->x_Auto440=75;
	_Context->y_Auto440=50;
	_Context->w_Auto440=650;
	_Context->h_Auto440=500;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto638[i]=" ";
	_Context->msg_Auto638[0]=en_Auto638;
	_Context->msg_Auto638[1]=fr_Auto638;
	for (i=0; i < 8; i++)_Context->msg_Ok[i]=" ";
	_Context->msg_Ok[0]=en_Ok;
	_Context->msg_Ok[1]=fr_Ok;
	_Context->msg_Ok[2]=it_Ok;
	_Context->msg_Ok[3]=es_Ok;
	_Context->msg_Ok[4]=de_Ok;
	_Context->msg_Ok[5]=nl_Ok;
	_Context->msg_Ok[6]=pt_Ok;
	_Context->msg_Ok[7]=xx_Ok;
	for (i=0; i < 8; i++)_Context->msg_FullScreen[i]=" ";
	_Context->msg_FullScreen[0]=en_FullScreen;
	_Context->msg_FullScreen[1]=fr_FullScreen;
	_Context->msg_FullScreen[2]=it_FullScreen;
	_Context->msg_FullScreen[3]=es_FullScreen;
	_Context->msg_FullScreen[4]=de_FullScreen;
	_Context->msg_FullScreen[5]=nl_FullScreen;
	_Context->msg_FullScreen[6]=pt_FullScreen;
	_Context->msg_FullScreen[7]=xx_FullScreen;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	for (i=0; i < 8; i++)_Context->msg_MethodPage[i]=" ";
	_Context->msg_MethodPage[0]=en_MethodPage;
	_Context->msg_MethodPage[1]=fr_MethodPage;
	_Context->msg_MethodPage[2]=it_MethodPage;
	_Context->msg_MethodPage[3]=es_MethodPage;
	_Context->msg_MethodPage[4]=de_MethodPage;
	_Context->msg_MethodPage[5]=nl_MethodPage;
	_Context->msg_MethodPage[6]=pt_MethodPage;
	_Context->msg_MethodPage[7]=xx_MethodPage;
	_Context->focus_pages[1]=5;
	for (i=0; i < 8; i++)_Context->msg_Auto444[i]=" ";
	_Context->msg_Auto444[0]=en_Auto444;
	_Context->msg_Auto444[1]=fr_Auto444;
	_Context->msg_Auto444[2]=it_Auto444;
	_Context->msg_Auto444[3]=es_Auto444;
	_Context->msg_Auto444[4]=de_Auto444;
	_Context->msg_Auto444[5]=nl_Auto444;
	_Context->msg_Auto444[6]=pt_Auto444;
	_Context->msg_Auto444[7]=xx_Auto444;
	for (i=0; i < 8; i++)_Context->msg_Auto445[i]=" ";
	_Context->msg_Auto445[0]=en_Auto445;
	_Context->msg_Auto445[1]=fr_Auto445;
	_Context->msg_Auto445[2]=it_Auto445;
	_Context->msg_Auto445[3]=es_Auto445;
	_Context->msg_Auto445[4]=de_Auto445;
	_Context->msg_Auto445[5]=nl_Auto445;
	_Context->msg_Auto445[6]=pt_Auto445;
	_Context->msg_Auto445[7]=xx_Auto445;
	for (i=0; i < 8; i++)_Context->msg_Auto446[i]=" ";
	_Context->msg_Auto446[0]=en_Auto446;
	_Context->msg_Auto446[1]=fr_Auto446;
	_Context->msg_Auto446[2]=it_Auto446;
	_Context->msg_Auto446[3]=es_Auto446;
	_Context->msg_Auto446[4]=de_Auto446;
	_Context->msg_Auto446[5]=nl_Auto446;
	_Context->msg_Auto446[6]=pt_Auto446;
	_Context->msg_Auto446[7]=xx_Auto446;
	for (i=0; i < 8; i++)_Context->msg_Auto447[i]=" ";
	_Context->msg_Auto447[0]=en_Auto447;
	_Context->msg_Auto447[1]=fr_Auto447;
	_Context->msg_Auto447[2]=it_Auto447;
	_Context->msg_Auto447[3]=es_Auto447;
	_Context->msg_Auto447[4]=de_Auto447;
	_Context->msg_Auto447[5]=nl_Auto447;
	_Context->msg_Auto447[6]=pt_Auto447;
	_Context->msg_Auto447[7]=xx_Auto447;
	for (i=0; i < 8; i++)_Context->msg_IsPublic[i]=" ";
	_Context->msg_IsPublic[0]=en_IsPublic;
	_Context->msg_IsPublic[1]=fr_IsPublic;
	for (i=0; i < 8; i++)_Context->msg_IsPointer[i]=" ";
	_Context->msg_IsPointer[0]=en_IsPointer;
	_Context->msg_IsPointer[1]=fr_IsPointer;
	_Context->msg_IsPointer[2]=it_IsPointer;
	_Context->msg_IsPointer[3]=es_IsPointer;
	_Context->msg_IsPointer[4]=de_IsPointer;
	_Context->msg_IsPointer[5]=nl_IsPointer;
	_Context->msg_IsPointer[6]=pt_IsPointer;
	_Context->msg_IsPointer[7]=xx_IsPointer;
	for (i=0; i < 8; i++)_Context->msg_MethodType[i]=" ";
	_Context->msg_MethodType[0]=en_MethodType;
	_Context->msg_MethodType[1]=fr_MethodType;
	_Context->msg_MethodType[2]=it_MethodType;
	_Context->msg_MethodType[3]=es_MethodType;
	_Context->msg_MethodType[4]=de_MethodType;
	_Context->msg_MethodType[5]=nl_MethodType;
	_Context->msg_MethodType[6]=pt_MethodType;
	_Context->msg_MethodType[7]=xx_MethodType;
	for (i=0; i < 8; i++)_Context->msg1_MethodNature[i]=" ";
	_Context->msg1_MethodNature[0]=en1_MethodNature;
	_Context->msg1_MethodNature[1]=fr1_MethodNature;
	_Context->msg1_MethodNature[2]=it1_MethodNature;
	_Context->msg1_MethodNature[3]=es1_MethodNature;
	_Context->msg1_MethodNature[4]=de1_MethodNature;
	_Context->msg1_MethodNature[5]=nl1_MethodNature;
	_Context->msg1_MethodNature[6]=pt1_MethodNature;
	_Context->msg1_MethodNature[7]=xx1_MethodNature;
	for (i=0; i < 8; i++)_Context->msg2_MethodNature[i]=" ";
	_Context->msg2_MethodNature[0]=en2_MethodNature;
	_Context->msg2_MethodNature[1]=fr2_MethodNature;
	_Context->msg2_MethodNature[2]=it2_MethodNature;
	_Context->msg2_MethodNature[3]=es2_MethodNature;
	_Context->msg2_MethodNature[4]=de2_MethodNature;
	_Context->msg2_MethodNature[5]=nl2_MethodNature;
	_Context->msg2_MethodNature[6]=pt2_MethodNature;
	_Context->msg2_MethodNature[7]=xx2_MethodNature;
	for (i=0; i < 8; i++)_Context->msg3_MethodNature[i]=" ";
	_Context->msg3_MethodNature[0]=en3_MethodNature;
	_Context->msg3_MethodNature[1]=fr3_MethodNature;
	_Context->msg3_MethodNature[2]=it3_MethodNature;
	_Context->msg3_MethodNature[3]=es3_MethodNature;
	_Context->msg3_MethodNature[4]=de3_MethodNature;
	_Context->msg3_MethodNature[5]=nl3_MethodNature;
	_Context->msg3_MethodNature[6]=pt3_MethodNature;
	_Context->msg3_MethodNature[7]=xx3_MethodNature;
	for (i=0; i < 8; i++)_Context->msg4_MethodNature[i]=" ";
	_Context->msg4_MethodNature[0]=en4_MethodNature;
	_Context->msg4_MethodNature[1]=fr4_MethodNature;
	_Context->msg4_MethodNature[2]=it4_MethodNature;
	_Context->msg4_MethodNature[3]=es4_MethodNature;
	_Context->msg4_MethodNature[4]=de4_MethodNature;
	_Context->msg4_MethodNature[5]=nl4_MethodNature;
	_Context->msg4_MethodNature[6]=pt4_MethodNature;
	_Context->msg4_MethodNature[7]=xx4_MethodNature;
	for (i=0; i < 8; i++)_Context->msg_BodyPage[i]=" ";
	_Context->msg_BodyPage[0]=en_BodyPage;
	_Context->msg_BodyPage[1]=fr_BodyPage;
	_Context->msg_BodyPage[2]=it_BodyPage;
	_Context->msg_BodyPage[3]=es_BodyPage;
	_Context->msg_BodyPage[4]=de_BodyPage;
	_Context->msg_BodyPage[5]=nl_BodyPage;
	_Context->msg_BodyPage[6]=pt_BodyPage;
	_Context->msg_BodyPage[7]=xx_BodyPage;
	_Context->focus_pages[2]=16;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto440,_Context->y_Auto440,650+10,500+10);
	return(0);
}

public 	int	accept_forms_method_hide(struct accept_forms_method_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	close_window_editor();
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto440,_Context->y_Auto440);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_forms_method_remove(
	struct accept_forms_method_context * _Context,
	char * pIsPublic,
	char * pIsPointer,
	char * pMethodType,
	char * pMethodClass,
	char * pMethodNature,
	char * pMethodName,
	char * pSignature,
	char * pMethodText)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWSWSST");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pIsPublic);
		if ( pIsPublic != (char *) 0)
			*((int*)pIsPublic) = _Context->value_IsPublic;
		visual_transferout((void *) 0, 0, pIsPointer);
		if ( pIsPointer != (char *) 0)
			*((int*)pIsPointer) = _Context->value_IsPointer;
		visual_transferout((void *) 0, 0, pMethodType);
		if ( pMethodType != (char *) 0)
			*((int*)pMethodType) = _Context->value_MethodType;
		visual_transferout(_Context->buffer_MethodClass, 59, pMethodClass);
		visual_transferout((void *) 0, 0, pMethodNature);
		if ( pMethodNature != (char *) 0)
			*((int*)pMethodNature) = _Context->value_MethodNature;
		visual_transferout(_Context->buffer_MethodName, 59, pMethodName);
		visual_transferout(_Context->buffer_Signature, 708, pSignature);
		visual_transferout(&_Context->buffer_MethodText, 1562, pMethodText);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_BodyPage_show(struct accept_forms_method_context * _Context) {
	open_window_editor(_Context->x_Auto440+40,_Context->y_Auto440+70,
	570,360,_Context->buffer_MethodText);
	return(-1);
}
private int on_MethodText_show(struct accept_forms_method_context * _Context) {
	visual_frame(_Context->x_Auto440+40,_Context->y_Auto440+70,570+2,360+2,5);
;
	show_window_editor();
	return(-1);
}

public	int	accept_forms_method_show(struct accept_forms_method_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto440,_Context->y_Auto440);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto440,_Context->y_Auto440,650,500,vfh[2],_Context->msg_Auto440[_Context->language],strlen(_Context->msg_Auto440[_Context->language]),0x407);
	visual_image(_Context->x_Auto440+3,_Context->y_Auto440+22,644,473,_Context->msg_Auto638[_Context->language],4);
	visual_filzone(_Context->x_Auto440+50,_Context->y_Auto440+460,110,30,18,12);
	visual_filzone(_Context->x_Auto440+270,_Context->y_Auto440+460,110,30,18,12);
	visual_filzone(_Context->x_Auto440+510,_Context->y_Auto440+460,110,30,18,12);
	_Context->trigger_Ok=visual_trigger_code(_Context->msg_Ok[_Context->language],strlen(_Context->msg_Ok[_Context->language]));
	visual_button(_Context->x_Auto440+40,_Context->y_Auto440+450,110,30,vfh[2],34,0,_Context->msg_Ok[_Context->language],strlen(_Context->msg_Ok[_Context->language]),0);
	_Context->trigger_FullScreen=visual_trigger_code(_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]));
	visual_button(_Context->x_Auto440+260,_Context->y_Auto440+450,112,32,vfh[2],28,28,_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto440+500,_Context->y_Auto440+450,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	if (_Context->page_number == 1 ) {
	_Context->trigger_MethodPage=visual_trigger_code(_Context->msg_MethodPage[_Context->language],strlen(_Context->msg_MethodPage[_Context->language]));
	visual_tabpage(_Context->x_Auto440+20,_Context->y_Auto440+30,610,410,vfh[2],_Context->msg_MethodPage[_Context->language],strlen(_Context->msg_MethodPage[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto440+20,_Context->y_Auto440+30,610,410,vfh[2],_Context->msg_MethodPage[_Context->language],strlen(_Context->msg_MethodPage[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto440+30,_Context->y_Auto440+60,590,30,vfh[3],16,0,_Context->msg_Auto444[_Context->language],strlen(_Context->msg_Auto444[_Context->language]),1283);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto440+40,_Context->y_Auto440+170,88,16,vfh[2],16,0,_Context->msg_Auto445[_Context->language],strlen(_Context->msg_Auto445[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto440+40,_Context->y_Auto440+200,100,20,vfh[2],16,0,_Context->msg_Auto446[_Context->language],strlen(_Context->msg_Auto446[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto440+40,_Context->y_Auto440+230,88,16,vfh[2],16,0,_Context->msg_Auto447[_Context->language],strlen(_Context->msg_Auto447[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsPublic=visual_trigger_code(_Context->msg_IsPublic[_Context->language],strlen(_Context->msg_IsPublic[_Context->language]));
	visual_check(_Context->x_Auto440+40,_Context->y_Auto440+100,98,16,vfh[2],27,28,_Context->msg_IsPublic[_Context->language],strlen(_Context->msg_IsPublic[_Context->language]),_Context->value_IsPublic|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsPointer=visual_trigger_code(_Context->msg_IsPointer[_Context->language],strlen(_Context->msg_IsPointer[_Context->language]));
	visual_check(_Context->x_Auto440+300,_Context->y_Auto440+100,104,16,vfh[2],27,28,_Context->msg_IsPointer[_Context->language],strlen(_Context->msg_IsPointer[_Context->language]),_Context->value_IsPointer|0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_Auto440+140,_Context->y_Auto440+100,140,160,vfh[1],27,28,parse_selection(_Context->msg_MethodType[_Context->language],&_Context->value_MethodType),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto440+140,_Context->y_Auto440+130,472+2,16+2,5);
	visual_text(_Context->x_Auto440+140+1,_Context->y_Auto440+130+1,472,16,vfh[1],27,28,_Context->buffer_MethodClass,59,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger1_MethodNature=visual_trigger_code(_Context->msg1_MethodNature[_Context->language],strlen(_Context->msg1_MethodNature[_Context->language]));
	visual_radio(_Context->x_Auto440+140,_Context->y_Auto440+170,84,16,vfh[2],27,28,_Context->msg1_MethodNature[_Context->language],strlen(_Context->msg1_MethodNature[_Context->language]),_Context->value_MethodNature,1);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger2_MethodNature=visual_trigger_code(_Context->msg2_MethodNature[_Context->language],strlen(_Context->msg2_MethodNature[_Context->language]));
	visual_radio(_Context->x_Auto440+240,_Context->y_Auto440+170,112,16,vfh[2],27,28,_Context->msg2_MethodNature[_Context->language],strlen(_Context->msg2_MethodNature[_Context->language]),_Context->value_MethodNature,2);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger3_MethodNature=visual_trigger_code(_Context->msg3_MethodNature[_Context->language],strlen(_Context->msg3_MethodNature[_Context->language]));
	visual_radio(_Context->x_Auto440+360,_Context->y_Auto440+170,126,16,vfh[2],27,28,_Context->msg3_MethodNature[_Context->language],strlen(_Context->msg3_MethodNature[_Context->language]),_Context->value_MethodNature,3);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger4_MethodNature=visual_trigger_code(_Context->msg4_MethodNature[_Context->language],strlen(_Context->msg4_MethodNature[_Context->language]));
	visual_radio(_Context->x_Auto440+500,_Context->y_Auto440+170,98,16,vfh[2],27,28,_Context->msg4_MethodNature[_Context->language],strlen(_Context->msg4_MethodNature[_Context->language]),_Context->value_MethodNature,4);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto440+140,_Context->y_Auto440+200,472+2,16+2,5);
	visual_text(_Context->x_Auto440+140+1,_Context->y_Auto440+200+1,472,16,vfh[1],0,0,_Context->buffer_MethodName,59,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto440+140,_Context->y_Auto440+230,472+2,192+2,5);
	visual_text(_Context->x_Auto440+140+1,_Context->y_Auto440+230+1,472,192,vfh[1],0,0,_Context->buffer_Signature,708,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_BodyPage=visual_trigger_code(_Context->msg_BodyPage[_Context->language],strlen(_Context->msg_BodyPage[_Context->language]));
	visual_tabpage(_Context->x_Auto440+20,_Context->y_Auto440+30,610,410,vfh[2],_Context->msg_BodyPage[_Context->language],strlen(_Context->msg_BodyPage[_Context->language]),80,2);
		(void) on_BodyPage_show(_Context);
	} else {
		visual_tabpage(_Context->x_Auto440+20,_Context->y_Auto440+30,610,410,vfh[2],_Context->msg_BodyPage[_Context->language],strlen(_Context->msg_BodyPage[_Context->language]),80,0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_MethodText_show(_Context);
		}
	visual_thaw(_Context->x_Auto440,_Context->y_Auto440,650,500);
	visual_thaw(_Context->x_Auto440,_Context->y_Auto440,650,500);

	return(0);
}

private int Auto440action(struct accept_forms_method_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_forms_method_hide(_Context);

		_Context->x_Auto440 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto440 < 0) { _Context->x_Auto440=0; }
		_Context->y_Auto440 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto440 < 0) { _Context->y_Auto440=0; }
			accept_forms_method_show(_Context);

		visual_thaw(_Context->x_Auto440,_Context->y_Auto440,650,500);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Ok_event(struct accept_forms_method_context * _Context) {
	return(13);
	return(-1);
}
private int on_FullScreen_event(struct accept_forms_method_context * _Context) {
		accept_forms_method_hide(_Context);
;
	use_editor(_Context->buffer_MethodText,0);
		accept_forms_method_show(_Context);
;
	visual_frame(_Context->x_Auto440+40,_Context->y_Auto440+70,570+2,360+2,5);
;
		/* MethodText */
	/* BodyPage */
	accept_forms_method_losefocus(_Context);
	_Context->page_number = 2;
	accept_forms_method_show(_Context);
	_Context->focus_item=16;
	accept_forms_method_show(_Context);
	_Context->focus_item=17;
;
	return(-1);
}
private int on_Cancel_event(struct accept_forms_method_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_forms_method_event(
struct accept_forms_method_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Ok == mb ) return(2);
		if (_Context->trigger_FullScreen == mb ) return(3);
		if (_Context->trigger_Cancel == mb ) return(4);
		if (_Context->trigger_MethodPage == mb ) return(5);
		if (_Context->trigger_IsPublic == mb ) return(6);
		if (_Context->trigger_IsPointer == mb ) return(7);
		if (_Context->trigger1_MethodNature == mb ) return(10);
		if (_Context->trigger2_MethodNature == mb ) return(11);
		if (_Context->trigger3_MethodNature == mb ) return(12);
		if (_Context->trigger4_MethodNature == mb ) return(13);
		if (_Context->trigger_BodyPage == mb ) return(16);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto440+629) )  
	&&  (my >= (_Context->y_Auto440+4) )  
	&&  (mx <= (_Context->x_Auto440+646) )  
	&&  (my <= (_Context->y_Auto440+20) )) {
		return(1);	/* Auto440 */

		}
	if ((mx >= (_Context->x_Auto440+613) )  
	&&  (my >= (_Context->y_Auto440+4) )  
	&&  (mx <= (_Context->x_Auto440+630) )  
	&&  (my <= (_Context->y_Auto440+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vmethod.htm");
			};
		return(-1);	/* Auto440 */

		}
	if ((mx >= (_Context->x_Auto440+597) )  
	&&  (my >= (_Context->y_Auto440+4) )  
	&&  (mx <= (_Context->x_Auto440+614) )  
	&&  (my <= (_Context->y_Auto440+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_forms_method_show(_Context);
		return(-1);	/* Auto440 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto440+4) )  
		&&  (my >= (_Context->y_Auto440+4) )  
		&&  (mx <= (_Context->x_Auto440+582) )  
		&&  (my <= (_Context->y_Auto440+20) )) {
			return( Auto440action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto440+40) ) 
	&&  ( my >= (_Context->y_Auto440+450) ) 
	&&  ( mx <= (_Context->x_Auto440+40+110) ) 
	&&  ( my <= (_Context->y_Auto440+450+30))) {
		return(2); /* Ok */
		}
	if (( mx >= (_Context->x_Auto440+260) ) 
	&&  ( my >= (_Context->y_Auto440+450) ) 
	&&  ( mx <= (_Context->x_Auto440+260+112) ) 
	&&  ( my <= (_Context->y_Auto440+450+32))) {
		return(3); /* FullScreen */
		}
	if (( mx >= (_Context->x_Auto440+500) ) 
	&&  ( my >= (_Context->y_Auto440+450) ) 
	&&  ( mx <= (_Context->x_Auto440+500+110) ) 
	&&  ( my <= (_Context->y_Auto440+450+30))) {
		return(4); /* Cancel */
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto440+20+0) ) 
		&&  ( my >= (_Context->y_Auto440+30) ) 
		&&  ( mx <= (_Context->x_Auto440+20+79) ) 
		&&  ( my <= (_Context->y_Auto440+30+24))) {
			return(5); /* MethodPage */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto440+40) ) 
		&&  ( my >= (_Context->y_Auto440+100) ) 
		&&  ( mx <= (_Context->x_Auto440+40+98) ) 
		&&  ( my <= (_Context->y_Auto440+100+16))) {
			return(6); /* IsPublic */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto440+300) ) 
		&&  ( my >= (_Context->y_Auto440+100) ) 
		&&  ( mx <= (_Context->x_Auto440+300+104) ) 
		&&  ( my <= (_Context->y_Auto440+100+16))) {
			return(7); /* IsPointer */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto440+140+0) ) 
		&&  ( my >= (_Context->y_Auto440+100) ) 
		&&  ( mx <= (_Context->x_Auto440+140+140) ) 
		&&  ( my <= (_Context->y_Auto440+100+16))) {
			return(8); /* MethodType */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto440+140) ) 
		&&  ( my >= (_Context->y_Auto440+130) ) 
		&&  ( mx <= (_Context->x_Auto440+140+472) ) 
		&&  ( my <= (_Context->y_Auto440+130+16))) {
			return(9); /* MethodClass */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto440+140) ) 
		&&  ( my >= (_Context->y_Auto440+170) ) 
		&&  ( mx <= (_Context->x_Auto440+140+84) ) 
		&&  ( my <= (_Context->y_Auto440+170+16))) {
			return(10); /* MethodNature */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto440+240) ) 
		&&  ( my >= (_Context->y_Auto440+170) ) 
		&&  ( mx <= (_Context->x_Auto440+240+112) ) 
		&&  ( my <= (_Context->y_Auto440+170+16))) {
			return(11); /* MethodNature */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto440+360) ) 
		&&  ( my >= (_Context->y_Auto440+170) ) 
		&&  ( mx <= (_Context->x_Auto440+360+126) ) 
		&&  ( my <= (_Context->y_Auto440+170+16))) {
			return(12); /* MethodNature */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto440+500) ) 
		&&  ( my >= (_Context->y_Auto440+170) ) 
		&&  ( mx <= (_Context->x_Auto440+500+98) ) 
		&&  ( my <= (_Context->y_Auto440+170+16))) {
			return(13); /* MethodNature */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto440+140) ) 
		&&  ( my >= (_Context->y_Auto440+200) ) 
		&&  ( mx <= (_Context->x_Auto440+140+472) ) 
		&&  ( my <= (_Context->y_Auto440+200+16))) {
			return(14); /* MethodName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto440+140) ) 
		&&  ( my >= (_Context->y_Auto440+230) ) 
		&&  ( mx <= (_Context->x_Auto440+140+472) ) 
		&&  ( my <= (_Context->y_Auto440+230+192))) {
			return(15); /* Signature */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto440+20+80) ) 
		&&  ( my >= (_Context->y_Auto440+30) ) 
		&&  ( mx <= (_Context->x_Auto440+20+143) ) 
		&&  ( my <= (_Context->y_Auto440+30+24))) {
			return(16); /* BodyPage */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto440+40) ) 
		&&  ( my >= (_Context->y_Auto440+70) ) 
		&&  ( mx <= (_Context->x_Auto440+40+570) ) 
		&&  ( my <= (_Context->y_Auto440+70+360))) {
			return(17); /* MethodText */
			}
		}

	return(-1);
}


public	int	accept_forms_method_losefocus(struct accept_forms_method_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;

		}
	return(0);

}
private int on_MethodText_getfocus(struct accept_forms_method_context * _Context) {
	return(focus_window_editor());
	return(-1);
}


public	int	accept_forms_method_focus(struct accept_forms_method_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x5 :
				/* MethodPage */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x6 :
				/* IsPublic */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto440+40,_Context->y_Auto440+100,98,16,vfh[2],27,28,_Context->msg_IsPublic[_Context->language],strlen(_Context->msg_IsPublic[_Context->language]),(_Context->value_IsPublic |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto440+40,_Context->y_Auto440+100,98,16,vfh[2],27,28,_Context->msg_IsPublic[_Context->language],strlen(_Context->msg_IsPublic[_Context->language]),(_Context->value_IsPublic |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* IsPointer */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto440+300,_Context->y_Auto440+100,104,16,vfh[2],27,28,_Context->msg_IsPointer[_Context->language],strlen(_Context->msg_IsPointer[_Context->language]),(_Context->value_IsPointer |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto440+300,_Context->y_Auto440+100,104,16,vfh[2],27,28,_Context->msg_IsPointer[_Context->language],strlen(_Context->msg_IsPointer[_Context->language]),(_Context->value_IsPointer |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* MethodType */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto440+140,_Context->y_Auto440+100,140,160,vfh[1],27,28,parse_selection(_Context->msg_MethodType[_Context->language],&_Context->value_MethodType),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* MethodClass */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto440+140+1,_Context->y_Auto440+130+1,472,16,vfh[1],_Context->buffer_MethodClass,59);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* MethodNature */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_getch();
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* MethodNature */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_getch();
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* MethodNature */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_getch();
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* MethodNature */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_getch();
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* MethodName */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto440+140+1,_Context->y_Auto440+200+1,472,16,vfh[1],_Context->buffer_MethodName,59);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* Signature */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto440+140+1,_Context->y_Auto440+230+1,472,192,vfh[1],_Context->buffer_Signature,708);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* BodyPage */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x11 :
				/* MethodText */
				if (_Context->page_number == 2 ) {
					if ((_Context->keycode = on_MethodText_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			accept_forms_method_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_forms_method_show(_Context);
			continue;
		case	0x2 :
			accept_forms_method_losefocus(_Context);
			_Context->page_number=2;
			_Context->focus_item=17;
			accept_forms_method_show(_Context);
			continue;
		case	0x3 :
			accept_forms_method_losefocus(_Context);
			if ( _Context->page_number < 2 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_forms_method_show(_Context);
			continue;
		case	0x12 :
			accept_forms_method_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_forms_method_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_forms_method_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto440 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Ok */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto440+40,_Context->y_Auto440+450,110,30,vfh[2],34,0,_Context->msg_Ok[_Context->language],strlen(_Context->msg_Ok[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto440+40,_Context->y_Auto440+450,110,30,vfh[2],34,0,_Context->msg_Ok[_Context->language],strlen(_Context->msg_Ok[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Ok_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* FullScreen */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto440+260,_Context->y_Auto440+450,112,32,vfh[2],28,28,_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto440+260,_Context->y_Auto440+450,112,32,vfh[2],28,28,_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FullScreen_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto440+500,_Context->y_Auto440+450,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto440+500,_Context->y_Auto440+450,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* MethodPage */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_forms_method_losefocus(_Context);
							_Context->page_number = 1;
							accept_forms_method_show(_Context);
							}
						continue;
					case	0x6 :
						/* IsPublic */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsPublic += 1;
							_Context->value_IsPublic &= 1;
							}
						continue;
					case	0x7 :
						/* IsPointer */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsPointer += 1;
							_Context->value_IsPointer &= 1;
							}
						continue;
					case	0x8 :
						/* MethodType */
						continue;
					case	0x9 :
						/* MethodClass */
						continue;
					case	0xa :
						/* MethodNature */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MethodNature = 1;
							accept_forms_method_show(_Context);
							}
						continue;
					case	0xb :
						/* MethodNature */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MethodNature = 2;
							accept_forms_method_show(_Context);
							}
						continue;
					case	0xc :
						/* MethodNature */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MethodNature = 3;
							accept_forms_method_show(_Context);
							}
						continue;
					case	0xd :
						/* MethodNature */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MethodNature = 4;
							accept_forms_method_show(_Context);
							}
						continue;
					case	0xe :
						/* MethodName */
						continue;
					case	0xf :
						/* Signature */
						continue;
					case	0x10 :
						/* BodyPage */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_forms_method_losefocus(_Context);
							_Context->page_number = 2;
							accept_forms_method_show(_Context);
							}
						continue;
					case	0x11 :
						/* MethodText */
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
				_Context->focus_item=17;
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

public	int	accept_forms_method(
	char * pIsPublic,
	char * pIsPointer,
	char * pMethodType,
	char * pMethodClass,
	char * pMethodNature,
	char * pMethodName,
	char * pSignature,
	char * pMethodText)
{
	int	status=0;
	struct accept_forms_method_context * _Context=(struct accept_forms_method_context*) 0;
	status = accept_forms_method_create(
	&_Context,
	 pIsPublic,
	 pIsPointer,
	 pMethodType,
	 pMethodClass,
	 pMethodNature,
	 pMethodName,
	 pSignature,
	 pMethodText);
	if ( status != 0) return(status);
	status = accept_forms_method_show(_Context);
		enter_modal();
	status = accept_forms_method_focus(_Context);
		leave_modal();
	status = accept_forms_method_hide(_Context);
	status = accept_forms_method_remove(
	_Context,
	 pIsPublic,
	 pIsPointer,
	 pMethodType,
	 pMethodClass,
	 pMethodNature,
	 pMethodName,
	 pSignature,
	 pMethodText);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vmethod_c */
