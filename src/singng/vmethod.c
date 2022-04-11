
#ifndef _vmethod_c
#define _vmethod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : vmethod.xml                                              */
/* Target         : vmethod.c                                                */
/* Identification : 0.0-1197059933-2760.2759                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3336   ""
#define fr__Auto3336   ""
#define it__Auto3336   ""
#define es__Auto3336   ""
#define de__Auto3336   ""
#define nl__Auto3336   ""
#define pt__Auto3336   ""
#define xx__Auto3336   ""
#define en_MethodPage   "&Method"
#define fr_MethodPage   "&M‚thodes"
#define it_MethodPage   "&Method"
#define es_MethodPage   "&Method"
#define de_MethodPage   "&Method"
#define nl_MethodPage   "&Method"
#define pt_MethodPage   "&Method"
#define xx_MethodPage   "&Method"
#define en__MethodPage   ""
#define fr__MethodPage   ""
#define it__MethodPage   ""
#define es__MethodPage   ""
#define de__MethodPage   ""
#define nl__MethodPage   ""
#define pt__MethodPage   ""
#define xx__MethodPage   ""
#define en_Auto3337   "Visual Forms Method"
#define fr_Auto3337   "M‚thodes du formulaire"
#define it_Auto3337   "Visual Forms Method"
#define es_Auto3337   "Visual Forms Method"
#define de_Auto3337   "Visual Forms Method"
#define nl_Auto3337   "Visual Forms Method"
#define pt_Auto3337   "Visual Forms Method"
#define xx_Auto3337   "Visual Forms Method"
#define en_Auto3338   "Nature"
#define fr_Auto3338   "Nature"
#define it_Auto3338   "Nature"
#define es_Auto3338   "Nature"
#define de_Auto3338   "Nature"
#define nl_Auto3338   "Nature"
#define pt_Auto3338   "Nature"
#define xx_Auto3338   "Nature"
#define en_Auto3339   "Name"
#define fr_Auto3339   "Nom"
#define it_Auto3339   "Name"
#define es_Auto3339   "Name"
#define de_Auto3339   "Name"
#define nl_Auto3339   "Name"
#define pt_Auto3339   "Name"
#define xx_Auto3339   "Name"
#define en_Auto3340   "Parameters"
#define fr_Auto3340   "ParamŠtres"
#define it_Auto3340   "Parameters"
#define es_Auto3340   "Parameters"
#define de_Auto3340   "Parameters"
#define nl_Auto3340   "Parameters"
#define pt_Auto3340   "Parameters"
#define xx_Auto3340   "Parameters"
#define en_IsPublic   "&Public"
#define fr_IsPublic   "&Publique"
#define it_IsPublic   "&Public"
#define es_IsPublic   "&Public"
#define de_IsPublic   "&Public"
#define nl_IsPublic   "&Public"
#define pt_IsPublic   "&Public"
#define xx_IsPublic   "&Public"
#define en__IsPublic   ""
#define fr__IsPublic   ""
#define it__IsPublic   ""
#define es__IsPublic   ""
#define de__IsPublic   ""
#define nl__IsPublic   ""
#define pt__IsPublic   ""
#define xx__IsPublic   ""
#define en_IsExtern   "&Extern"
#define fr_IsExtern   "&Extern"
#define it_IsExtern   "&Extern"
#define es_IsExtern   "&Extern"
#define de_IsExtern   "&Extern"
#define nl_IsExtern   "&Extern"
#define pt_IsExtern   "&Extern"
#define xx_IsExtern   "&Extern"
#define en__IsExtern   ""
#define fr__IsExtern   ""
#define it__IsExtern   ""
#define es__IsExtern   ""
#define de__IsExtern   ""
#define nl__IsExtern   ""
#define pt__IsExtern   ""
#define xx__IsExtern   ""
#define en_IsPointer   "Poin&ter"
#define fr_IsPointer   "Poin&teur"
#define it_IsPointer   "Poin&ter"
#define es_IsPointer   "Poin&ter"
#define de_IsPointer   "Poin&ter"
#define nl_IsPointer   "Poin&ter"
#define pt_IsPointer   "Poin&ter"
#define xx_IsPointer   "Poin&ter"
#define en__IsPointer   ""
#define fr__IsPointer   ""
#define it__IsPointer   ""
#define es__IsPointer   ""
#define de__IsPointer   ""
#define nl__IsPointer   ""
#define pt__IsPointer   ""
#define xx__IsPointer   ""
#define en_MethodType   "void|int8|int16|int32|bcd|string|class"
#define fr_MethodType   "void|int8|int16|int32|bcd|string|class"
#define it_MethodType   "void|int8|int16|int32|bcd|string|class"
#define es_MethodType   "void|int8|int16|int32|bcd|string|class"
#define de_MethodType   "void|int8|int16|int32|bcd|string|class"
#define nl_MethodType   "void|int8|int16|int32|bcd|string|class"
#define pt_MethodType   "void|int8|int16|int32|bcd|string|class"
#define xx_MethodType   "void|int8|int16|int32|bcd|string|class"
#define en__MethodType   ""
#define fr__MethodType   ""
#define it__MethodType   ""
#define es__MethodType   ""
#define de__MethodType   ""
#define nl__MethodType   ""
#define pt__MethodType   ""
#define xx__MethodType   ""
#define en_MethodClass   ""
#define fr_MethodClass   ""
#define en1_MethodNature "&Inline"
#define fr1_MethodNature "&Inline"
#define it1_MethodNature "&Inline"
#define es1_MethodNature "&Inline"
#define de1_MethodNature "&Inline"
#define nl1_MethodNature "&Inline"
#define pt1_MethodNature "&Inline"
#define xx1_MethodNature "&Inline"
#define en1__MethodNature ""
#define fr1__MethodNature ""
#define it1__MethodNature ""
#define es1__MethodNature ""
#define de1__MethodNature ""
#define nl1__MethodNature ""
#define pt1__MethodNature ""
#define xx1__MethodNature ""
#define en2_MethodNature "&Function"
#define fr2_MethodNature "&Function"
#define it2_MethodNature "&Function"
#define es2_MethodNature "&Function"
#define de2_MethodNature "&Function"
#define nl2_MethodNature "&Function"
#define pt2_MethodNature "&Function"
#define xx2_MethodNature "&Function"
#define en2__MethodNature ""
#define fr2__MethodNature ""
#define it2__MethodNature ""
#define es2__MethodNature ""
#define de2__MethodNature ""
#define nl2__MethodNature ""
#define pt2__MethodNature ""
#define xx2__MethodNature ""
#define en3_MethodNature "&Virtual"
#define fr3_MethodNature "&Virtual"
#define it3_MethodNature "&Virtual"
#define es3_MethodNature "&Virtual"
#define de3_MethodNature "&Virtual"
#define nl3_MethodNature "&Virtual"
#define pt3_MethodNature "&Virtual"
#define xx3_MethodNature "&Virtual"
#define en3__MethodNature ""
#define fr3__MethodNature ""
#define it3__MethodNature ""
#define es3__MethodNature ""
#define de3__MethodNature ""
#define nl3__MethodNature ""
#define pt3__MethodNature ""
#define xx3__MethodNature ""
#define en4_MethodNature "&Overload"
#define fr4_MethodNature "&Overload"
#define it4_MethodNature "&Overload"
#define es4_MethodNature "&Overload"
#define de4_MethodNature "&Overload"
#define nl4_MethodNature "&Overload"
#define pt4_MethodNature "&Overload"
#define xx4_MethodNature "&Overload"
#define en4__MethodNature ""
#define fr4__MethodNature ""
#define it4__MethodNature ""
#define es4__MethodNature ""
#define de4__MethodNature ""
#define nl4__MethodNature ""
#define pt4__MethodNature ""
#define xx4__MethodNature ""
#define en_MethodName   ""
#define fr_MethodName   ""
#define en_Signature   ""
#define fr_Signature   ""
#define en_BodyPage   "&Body"
#define fr_BodyPage   "&Corps"
#define it_BodyPage   "&Body"
#define es_BodyPage   "&Body"
#define de_BodyPage   "&Korper"
#define nl_BodyPage   "&Body"
#define pt_BodyPage   "&Body"
#define xx_BodyPage   "&Body"
#define en__BodyPage   ""
#define fr__BodyPage   ""
#define it__BodyPage   ""
#define es__BodyPage   ""
#define de__BodyPage   ""
#define nl__BodyPage   ""
#define pt__BodyPage   ""
#define xx__BodyPage   ""
#define en_MethodText   ""
#define fr_MethodText   ""
#define en_Auto3341   "ok.gif"
#define fr_Auto3341   "ok.gif"
#define it_Auto3341   "ok.gif"
#define es_Auto3341   "ok.gif"
#define de_Auto3341   "ok.gif"
#define nl_Auto3341   "ok.gif"
#define pt_Auto3341   "ok.gif"
#define xx_Auto3341   "ok.gif"
#define en__Auto3341   ""
#define fr__Auto3341   ""
#define it__Auto3341   ""
#define es__Auto3341   ""
#define de__Auto3341   ""
#define nl__Auto3341   ""
#define pt__Auto3341   ""
#define xx__Auto3341   ""
#define en_Auto3342   "screen.gif"
#define fr_Auto3342   "screen.gif"
#define it_Auto3342   "screen.gif"
#define es_Auto3342   "screen.gif"
#define de_Auto3342   "screen.gif"
#define nl_Auto3342   "screen.gif"
#define pt_Auto3342   "screen.gif"
#define xx_Auto3342   "screen.gif"
#define en__Auto3342   ""
#define en_Auto3343   "cancel.gif"
#define fr_Auto3343   "cancel.gif"
#define it_Auto3343   "cancel.gif"
#define es_Auto3343   "cancel.gif"
#define de_Auto3343   "cancel.gif"
#define nl_Auto3343   "cancel.gif"
#define pt_Auto3343   "cancel.gif"
#define xx_Auto3343   "cancel.gif"

private struct accept_forms_method_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[2+1];
	char * msg_Auto3336[8];
	char * hint_Auto3336[8];
	int	x_Auto3336;
	int	y_Auto3336;
	int	w_Auto3336;
	int	h_Auto3336;
	char * msg_MethodPage[8];
	int	trigger_MethodPage;
	char * hint_MethodPage[8];
	int	page_number;
	char * msg_Auto3337[8];
	char * hint_Auto3337[8];
	char * msg_Auto3338[8];
	char * hint_Auto3338[8];
	char * msg_Auto3339[8];
	char * hint_Auto3339[8];
	char * msg_Auto3340[8];
	char * hint_Auto3340[8];
	char * msg_IsPublic[8];
	int	trigger_IsPublic;
	char * hint_IsPublic[8];
	int	value_IsPublic;
	char * msg_IsExtern[8];
	int	trigger_IsExtern;
	char * hint_IsExtern[8];
	int	value_IsExtern;
	char * msg_IsPointer[8];
	int	trigger_IsPointer;
	char * hint_IsPointer[8];
	int	value_IsPointer;
	char * msg_MethodType[8];
	char * hint_MethodType[8];
	int	value_MethodType;
	char * hint_MethodClass[8];
	char	buffer_MethodClass[256];
	char * msg1_MethodNature[8];
	int 	trigger1_MethodNature;	char * hint1_MethodNature[8];
	int	value_MethodNature;
	char * msg2_MethodNature[8];
	int 	trigger2_MethodNature;	char * hint2_MethodNature[8];
	char * msg3_MethodNature[8];
	int 	trigger3_MethodNature;	char * hint3_MethodNature[8];
	char * msg4_MethodNature[8];
	int 	trigger4_MethodNature;	char * hint4_MethodNature[8];
	char * hint_MethodName[8];
	char	buffer_MethodName[256];
	char * hint_Signature[8];
	char	buffer_Signature[709];
	char * msg_BodyPage[8];
	int	trigger_BodyPage;
	char * hint_BodyPage[8];
	char * hint_MethodText[8];
	char * buffer_MethodText;
	char * msg_Auto3341[8];
	int	trigger_Auto3341;
	char * hint_Auto3341[8];
	char * msg_Auto3342[8];
	int	trigger_Auto3342;
	char * hint_Auto3342[8];
	char * msg_Auto3343[8];
	int	trigger_Auto3343;
	char * hint_Auto3343[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[10];
	};
static int	vfh[16];

public	int	accept_forms_method_create(
	struct accept_forms_method_context ** cptr,
	char * pIsPublic,
	char * pIsExtern,
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
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_forms_method_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=18;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWSWSST");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pIsPublic);
		if (!( pIsPublic )) _Context->value_IsPublic=0;
		else	_Context->value_IsPublic = *((int *)pIsPublic);
		visual_transferin((void *) 0, 0, pIsExtern);
		if (!( pIsExtern )) _Context->value_IsExtern=0;
		else	_Context->value_IsExtern = *((int *)pIsExtern);
		visual_transferin((void *) 0, 0, pIsPointer);
		if (!( pIsPointer )) _Context->value_IsPointer=0;
		else	_Context->value_IsPointer = *((int *)pIsPointer);
		visual_transferin((void *) 0, 0, pMethodType);
		if (!( pMethodType )) _Context->value_MethodType=0;
		else	_Context->value_MethodType = *((int *)pMethodType);
		visual_transferin(_Context->buffer_MethodClass, 255, pMethodClass);
		visual_transferin((void *) 0, 0, pMethodNature);
		if (!( pMethodNature )) _Context->value_MethodNature=0;
		else	_Context->value_MethodNature = *((int *)pMethodNature);
		visual_transferin(_Context->buffer_MethodName, 255, pMethodName);
		visual_transferin(_Context->buffer_Signature, 708, pSignature);
				_Context->buffer_MethodText=(char *) 0;
		visual_transferin(&_Context->buffer_MethodText, 1562, pMethodText);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3336[i]=" ";
	_Context->hint_Auto3336[0]=en__Auto3336;
	_Context->hint_Auto3336[1]=fr__Auto3336;
	_Context->hint_Auto3336[2]=it__Auto3336;
	_Context->hint_Auto3336[3]=es__Auto3336;
	_Context->hint_Auto3336[4]=de__Auto3336;
	_Context->hint_Auto3336[5]=nl__Auto3336;
	_Context->hint_Auto3336[6]=pt__Auto3336;
	_Context->hint_Auto3336[7]=xx__Auto3336;
	_Context->x_Auto3336=75;
	_Context->y_Auto3336=45;
	_Context->w_Auto3336=650;
	_Context->h_Auto3336=510;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_MethodPage[i]=" ";
	_Context->msg_MethodPage[0]=en_MethodPage;
	_Context->msg_MethodPage[1]=fr_MethodPage;
	_Context->msg_MethodPage[2]=it_MethodPage;
	_Context->msg_MethodPage[3]=es_MethodPage;
	_Context->msg_MethodPage[4]=de_MethodPage;
	_Context->msg_MethodPage[5]=nl_MethodPage;
	_Context->msg_MethodPage[6]=pt_MethodPage;
	_Context->msg_MethodPage[7]=xx_MethodPage;
	_Context->hint_MethodPage[0]=en__MethodPage;
	_Context->hint_MethodPage[1]=fr__MethodPage;
	_Context->hint_MethodPage[2]=it__MethodPage;
	_Context->hint_MethodPage[3]=es__MethodPage;
	_Context->hint_MethodPage[4]=de__MethodPage;
	_Context->hint_MethodPage[5]=nl__MethodPage;
	_Context->hint_MethodPage[6]=pt__MethodPage;
	_Context->hint_MethodPage[7]=xx__MethodPage;
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_Auto3337[i]=" ";
	_Context->msg_Auto3337[0]=en_Auto3337;
	_Context->msg_Auto3337[1]=fr_Auto3337;
	_Context->msg_Auto3337[2]=it_Auto3337;
	_Context->msg_Auto3337[3]=es_Auto3337;
	_Context->msg_Auto3337[4]=de_Auto3337;
	_Context->msg_Auto3337[5]=nl_Auto3337;
	_Context->msg_Auto3337[6]=pt_Auto3337;
	_Context->msg_Auto3337[7]=xx_Auto3337;
	for (i=0; i < 8; i++)_Context->msg_Auto3338[i]=" ";
	_Context->msg_Auto3338[0]=en_Auto3338;
	_Context->msg_Auto3338[1]=fr_Auto3338;
	_Context->msg_Auto3338[2]=it_Auto3338;
	_Context->msg_Auto3338[3]=es_Auto3338;
	_Context->msg_Auto3338[4]=de_Auto3338;
	_Context->msg_Auto3338[5]=nl_Auto3338;
	_Context->msg_Auto3338[6]=pt_Auto3338;
	_Context->msg_Auto3338[7]=xx_Auto3338;
	for (i=0; i < 8; i++)_Context->msg_Auto3339[i]=" ";
	_Context->msg_Auto3339[0]=en_Auto3339;
	_Context->msg_Auto3339[1]=fr_Auto3339;
	_Context->msg_Auto3339[2]=it_Auto3339;
	_Context->msg_Auto3339[3]=es_Auto3339;
	_Context->msg_Auto3339[4]=de_Auto3339;
	_Context->msg_Auto3339[5]=nl_Auto3339;
	_Context->msg_Auto3339[6]=pt_Auto3339;
	_Context->msg_Auto3339[7]=xx_Auto3339;
	for (i=0; i < 8; i++)_Context->msg_Auto3340[i]=" ";
	_Context->msg_Auto3340[0]=en_Auto3340;
	_Context->msg_Auto3340[1]=fr_Auto3340;
	_Context->msg_Auto3340[2]=it_Auto3340;
	_Context->msg_Auto3340[3]=es_Auto3340;
	_Context->msg_Auto3340[4]=de_Auto3340;
	_Context->msg_Auto3340[5]=nl_Auto3340;
	_Context->msg_Auto3340[6]=pt_Auto3340;
	_Context->msg_Auto3340[7]=xx_Auto3340;
	for (i=0; i < 8; i++)_Context->msg_IsPublic[i]=" ";
	_Context->msg_IsPublic[0]=en_IsPublic;
	_Context->msg_IsPublic[1]=fr_IsPublic;
	_Context->msg_IsPublic[2]=it_IsPublic;
	_Context->msg_IsPublic[3]=es_IsPublic;
	_Context->msg_IsPublic[4]=de_IsPublic;
	_Context->msg_IsPublic[5]=nl_IsPublic;
	_Context->msg_IsPublic[6]=pt_IsPublic;
	_Context->msg_IsPublic[7]=xx_IsPublic;
	_Context->hint_IsPublic[0]=en__IsPublic;
	_Context->hint_IsPublic[1]=fr__IsPublic;
	_Context->hint_IsPublic[2]=it__IsPublic;
	_Context->hint_IsPublic[3]=es__IsPublic;
	_Context->hint_IsPublic[4]=de__IsPublic;
	_Context->hint_IsPublic[5]=nl__IsPublic;
	_Context->hint_IsPublic[6]=pt__IsPublic;
	_Context->hint_IsPublic[7]=xx__IsPublic;
	for (i=0; i < 8; i++)_Context->msg_IsExtern[i]=" ";
	_Context->msg_IsExtern[0]=en_IsExtern;
	_Context->msg_IsExtern[1]=fr_IsExtern;
	_Context->msg_IsExtern[2]=it_IsExtern;
	_Context->msg_IsExtern[3]=es_IsExtern;
	_Context->msg_IsExtern[4]=de_IsExtern;
	_Context->msg_IsExtern[5]=nl_IsExtern;
	_Context->msg_IsExtern[6]=pt_IsExtern;
	_Context->msg_IsExtern[7]=xx_IsExtern;
	_Context->hint_IsExtern[0]=en__IsExtern;
	_Context->hint_IsExtern[1]=fr__IsExtern;
	_Context->hint_IsExtern[2]=it__IsExtern;
	_Context->hint_IsExtern[3]=es__IsExtern;
	_Context->hint_IsExtern[4]=de__IsExtern;
	_Context->hint_IsExtern[5]=nl__IsExtern;
	_Context->hint_IsExtern[6]=pt__IsExtern;
	_Context->hint_IsExtern[7]=xx__IsExtern;
	for (i=0; i < 8; i++)_Context->msg_IsPointer[i]=" ";
	_Context->msg_IsPointer[0]=en_IsPointer;
	_Context->msg_IsPointer[1]=fr_IsPointer;
	_Context->msg_IsPointer[2]=it_IsPointer;
	_Context->msg_IsPointer[3]=es_IsPointer;
	_Context->msg_IsPointer[4]=de_IsPointer;
	_Context->msg_IsPointer[5]=nl_IsPointer;
	_Context->msg_IsPointer[6]=pt_IsPointer;
	_Context->msg_IsPointer[7]=xx_IsPointer;
	_Context->hint_IsPointer[0]=en__IsPointer;
	_Context->hint_IsPointer[1]=fr__IsPointer;
	_Context->hint_IsPointer[2]=it__IsPointer;
	_Context->hint_IsPointer[3]=es__IsPointer;
	_Context->hint_IsPointer[4]=de__IsPointer;
	_Context->hint_IsPointer[5]=nl__IsPointer;
	_Context->hint_IsPointer[6]=pt__IsPointer;
	_Context->hint_IsPointer[7]=xx__IsPointer;
	for (i=0; i < 8; i++)_Context->msg_MethodType[i]=" ";
	_Context->msg_MethodType[0]=en_MethodType;
	_Context->msg_MethodType[1]=fr_MethodType;
	_Context->msg_MethodType[2]=it_MethodType;
	_Context->msg_MethodType[3]=es_MethodType;
	_Context->msg_MethodType[4]=de_MethodType;
	_Context->msg_MethodType[5]=nl_MethodType;
	_Context->msg_MethodType[6]=pt_MethodType;
	_Context->msg_MethodType[7]=xx_MethodType;
	_Context->hint_MethodType[0]=en__MethodType;
	_Context->hint_MethodType[1]=fr__MethodType;
	_Context->hint_MethodType[2]=it__MethodType;
	_Context->hint_MethodType[3]=es__MethodType;
	_Context->hint_MethodType[4]=de__MethodType;
	_Context->hint_MethodType[5]=nl__MethodType;
	_Context->hint_MethodType[6]=pt__MethodType;
	_Context->hint_MethodType[7]=xx__MethodType;
	for (i=0; i < 8; i++)_Context->msg1_MethodNature[i]=" ";
	_Context->msg1_MethodNature[0]=en1_MethodNature;
	_Context->msg1_MethodNature[1]=fr1_MethodNature;
	_Context->msg1_MethodNature[2]=it1_MethodNature;
	_Context->msg1_MethodNature[3]=es1_MethodNature;
	_Context->msg1_MethodNature[4]=de1_MethodNature;
	_Context->msg1_MethodNature[5]=nl1_MethodNature;
	_Context->msg1_MethodNature[6]=pt1_MethodNature;
	_Context->msg1_MethodNature[7]=xx1_MethodNature;
	_Context->hint1_MethodNature[0]=en1__MethodNature;
	_Context->hint1_MethodNature[1]=fr1__MethodNature;
	_Context->hint1_MethodNature[2]=it1__MethodNature;
	_Context->hint1_MethodNature[3]=es1__MethodNature;
	_Context->hint1_MethodNature[4]=de1__MethodNature;
	_Context->hint1_MethodNature[5]=nl1__MethodNature;
	_Context->hint1_MethodNature[6]=pt1__MethodNature;
	_Context->hint1_MethodNature[7]=xx1__MethodNature;
	for (i=0; i < 8; i++)_Context->msg2_MethodNature[i]=" ";
	_Context->msg2_MethodNature[0]=en2_MethodNature;
	_Context->msg2_MethodNature[1]=fr2_MethodNature;
	_Context->msg2_MethodNature[2]=it2_MethodNature;
	_Context->msg2_MethodNature[3]=es2_MethodNature;
	_Context->msg2_MethodNature[4]=de2_MethodNature;
	_Context->msg2_MethodNature[5]=nl2_MethodNature;
	_Context->msg2_MethodNature[6]=pt2_MethodNature;
	_Context->msg2_MethodNature[7]=xx2_MethodNature;
	_Context->hint2_MethodNature[0]=en2__MethodNature;
	_Context->hint2_MethodNature[1]=fr2__MethodNature;
	_Context->hint2_MethodNature[2]=it2__MethodNature;
	_Context->hint2_MethodNature[3]=es2__MethodNature;
	_Context->hint2_MethodNature[4]=de2__MethodNature;
	_Context->hint2_MethodNature[5]=nl2__MethodNature;
	_Context->hint2_MethodNature[6]=pt2__MethodNature;
	_Context->hint2_MethodNature[7]=xx2__MethodNature;
	for (i=0; i < 8; i++)_Context->msg3_MethodNature[i]=" ";
	_Context->msg3_MethodNature[0]=en3_MethodNature;
	_Context->msg3_MethodNature[1]=fr3_MethodNature;
	_Context->msg3_MethodNature[2]=it3_MethodNature;
	_Context->msg3_MethodNature[3]=es3_MethodNature;
	_Context->msg3_MethodNature[4]=de3_MethodNature;
	_Context->msg3_MethodNature[5]=nl3_MethodNature;
	_Context->msg3_MethodNature[6]=pt3_MethodNature;
	_Context->msg3_MethodNature[7]=xx3_MethodNature;
	_Context->hint3_MethodNature[0]=en3__MethodNature;
	_Context->hint3_MethodNature[1]=fr3__MethodNature;
	_Context->hint3_MethodNature[2]=it3__MethodNature;
	_Context->hint3_MethodNature[3]=es3__MethodNature;
	_Context->hint3_MethodNature[4]=de3__MethodNature;
	_Context->hint3_MethodNature[5]=nl3__MethodNature;
	_Context->hint3_MethodNature[6]=pt3__MethodNature;
	_Context->hint3_MethodNature[7]=xx3__MethodNature;
	for (i=0; i < 8; i++)_Context->msg4_MethodNature[i]=" ";
	_Context->msg4_MethodNature[0]=en4_MethodNature;
	_Context->msg4_MethodNature[1]=fr4_MethodNature;
	_Context->msg4_MethodNature[2]=it4_MethodNature;
	_Context->msg4_MethodNature[3]=es4_MethodNature;
	_Context->msg4_MethodNature[4]=de4_MethodNature;
	_Context->msg4_MethodNature[5]=nl4_MethodNature;
	_Context->msg4_MethodNature[6]=pt4_MethodNature;
	_Context->msg4_MethodNature[7]=xx4_MethodNature;
	_Context->hint4_MethodNature[0]=en4__MethodNature;
	_Context->hint4_MethodNature[1]=fr4__MethodNature;
	_Context->hint4_MethodNature[2]=it4__MethodNature;
	_Context->hint4_MethodNature[3]=es4__MethodNature;
	_Context->hint4_MethodNature[4]=de4__MethodNature;
	_Context->hint4_MethodNature[5]=nl4__MethodNature;
	_Context->hint4_MethodNature[6]=pt4__MethodNature;
	_Context->hint4_MethodNature[7]=xx4__MethodNature;
	for (i=0; i < 8; i++)_Context->msg_BodyPage[i]=" ";
	_Context->msg_BodyPage[0]=en_BodyPage;
	_Context->msg_BodyPage[1]=fr_BodyPage;
	_Context->msg_BodyPage[2]=it_BodyPage;
	_Context->msg_BodyPage[3]=es_BodyPage;
	_Context->msg_BodyPage[4]=de_BodyPage;
	_Context->msg_BodyPage[5]=nl_BodyPage;
	_Context->msg_BodyPage[6]=pt_BodyPage;
	_Context->msg_BodyPage[7]=xx_BodyPage;
	_Context->hint_BodyPage[0]=en__BodyPage;
	_Context->hint_BodyPage[1]=fr__BodyPage;
	_Context->hint_BodyPage[2]=it__BodyPage;
	_Context->hint_BodyPage[3]=es__BodyPage;
	_Context->hint_BodyPage[4]=de__BodyPage;
	_Context->hint_BodyPage[5]=nl__BodyPage;
	_Context->hint_BodyPage[6]=pt__BodyPage;
	_Context->hint_BodyPage[7]=xx__BodyPage;
	_Context->focus_pages[2]=14;
	for (i=0; i < 8; i++)_Context->msg_Auto3341[i]=" ";
	_Context->msg_Auto3341[0]=en_Auto3341;
	_Context->msg_Auto3341[1]=fr_Auto3341;
	_Context->msg_Auto3341[2]=it_Auto3341;
	_Context->msg_Auto3341[3]=es_Auto3341;
	_Context->msg_Auto3341[4]=de_Auto3341;
	_Context->msg_Auto3341[5]=nl_Auto3341;
	_Context->msg_Auto3341[6]=pt_Auto3341;
	_Context->msg_Auto3341[7]=xx_Auto3341;
	_Context->hint_Auto3341[0]=en__Auto3341;
	_Context->hint_Auto3341[1]=fr__Auto3341;
	_Context->hint_Auto3341[2]=it__Auto3341;
	_Context->hint_Auto3341[3]=es__Auto3341;
	_Context->hint_Auto3341[4]=de__Auto3341;
	_Context->hint_Auto3341[5]=nl__Auto3341;
	_Context->hint_Auto3341[6]=pt__Auto3341;
	_Context->hint_Auto3341[7]=xx__Auto3341;
	for (i=0; i < 8; i++)_Context->msg_Auto3342[i]=" ";
	_Context->msg_Auto3342[0]=en_Auto3342;
	_Context->msg_Auto3342[1]=fr_Auto3342;
	_Context->msg_Auto3342[2]=it_Auto3342;
	_Context->msg_Auto3342[3]=es_Auto3342;
	_Context->msg_Auto3342[4]=de_Auto3342;
	_Context->msg_Auto3342[5]=nl_Auto3342;
	_Context->msg_Auto3342[6]=pt_Auto3342;
	_Context->msg_Auto3342[7]=xx_Auto3342;
	_Context->hint_Auto3342[0]=en__Auto3342;
	for (i=0; i < 8; i++)_Context->msg_Auto3343[i]=" ";
	_Context->msg_Auto3343[0]=en_Auto3343;
	_Context->msg_Auto3343[1]=fr_Auto3343;
	_Context->msg_Auto3343[2]=it_Auto3343;
	_Context->msg_Auto3343[3]=es_Auto3343;
	_Context->msg_Auto3343[4]=de_Auto3343;
	_Context->msg_Auto3343[5]=nl_Auto3343;
	_Context->msg_Auto3343[6]=pt_Auto3343;
	_Context->msg_Auto3343[7]=xx_Auto3343;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3336,_Context->y_Auto3336,650+10,510+10);
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
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3336,_Context->y_Auto3336);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_forms_method_remove(
	struct accept_forms_method_context * _Context,
	char * pIsPublic,
	char * pIsExtern,
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
	if (_Context->keycode == 27 ) {
		filetransferdrop(_Context->buffer_MethodText);
		
	} else {
		strcpy(_Context->signature,"WWWWSWSST");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pIsPublic);
		if ( pIsPublic != (char *) 0)
			*((int*)pIsPublic) = _Context->value_IsPublic;
		visual_transferout((void *) 0, 0, pIsExtern);
		if ( pIsExtern != (char *) 0)
			*((int*)pIsExtern) = _Context->value_IsExtern;
		visual_transferout((void *) 0, 0, pIsPointer);
		if ( pIsPointer != (char *) 0)
			*((int*)pIsPointer) = _Context->value_IsPointer;
		visual_transferout((void *) 0, 0, pMethodType);
		if ( pMethodType != (char *) 0)
			*((int*)pMethodType) = _Context->value_MethodType;
		visual_transferout(_Context->buffer_MethodClass, 255, pMethodClass);
		visual_transferout((void *) 0, 0, pMethodNature);
		if ( pMethodNature != (char *) 0)
			*((int*)pMethodNature) = _Context->value_MethodNature;
		visual_transferout(_Context->buffer_MethodName, 255, pMethodName);
		visual_transferout(_Context->buffer_Signature, 708, pSignature);
		visual_transferout(&_Context->buffer_MethodText, 1562, pMethodText);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_BodyPage_show(struct accept_forms_method_context * _Context) {
	open_window_editor(_Context->x_Auto3336+40,_Context->y_Auto3336+70,
	570,360,_Context->buffer_MethodText);
	return(-1);
}
private int on_MethodText_show(struct accept_forms_method_context * _Context) {
	visual_frame(_Context->x_Auto3336+40,_Context->y_Auto3336+70,570+2,360+2,5);
;
	show_window_editor();
	return(-1);
}

public	int	accept_forms_method_show(struct accept_forms_method_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3336,_Context->y_Auto3336);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3336,_Context->y_Auto3336,650,510,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3336,_Context->y_Auto3336,650,510,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_MethodPage=visual_trigger_code(_Context->msg_MethodPage[_Context->language],strlen(_Context->msg_MethodPage[_Context->language]));
	visual_tabpage(_Context->x_Auto3336+20,_Context->y_Auto3336+30,610,410,vfh[2],_Context->msg_MethodPage[_Context->language],strlen(_Context->msg_MethodPage[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto3336+20,_Context->y_Auto3336+30,610,410,vfh[2],_Context->msg_MethodPage[_Context->language],strlen(_Context->msg_MethodPage[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3336+30,_Context->y_Auto3336+60,590,30,vfh[3],16,0,_Context->msg_Auto3337[_Context->language],strlen(_Context->msg_Auto3337[_Context->language]),1283);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3336+40,_Context->y_Auto3336+170,88,16,vfh[2],16,0,_Context->msg_Auto3338[_Context->language],strlen(_Context->msg_Auto3338[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3336+40,_Context->y_Auto3336+200,100,20,vfh[2],16,0,_Context->msg_Auto3339[_Context->language],strlen(_Context->msg_Auto3339[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3336+40,_Context->y_Auto3336+230,88,16,vfh[2],16,0,_Context->msg_Auto3340[_Context->language],strlen(_Context->msg_Auto3340[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsPublic=visual_trigger_code(_Context->msg_IsPublic[_Context->language],strlen(_Context->msg_IsPublic[_Context->language]));
	visual_check(_Context->x_Auto3336+40,_Context->y_Auto3336+100,98,16,vfh[2],27,28,_Context->msg_IsPublic[_Context->language],strlen(_Context->msg_IsPublic[_Context->language]),_Context->value_IsPublic|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsExtern=visual_trigger_code(_Context->msg_IsExtern[_Context->language],strlen(_Context->msg_IsExtern[_Context->language]));
	visual_check(_Context->x_Auto3336+40,_Context->y_Auto3336+130,98,16,vfh[2],27,28,_Context->msg_IsExtern[_Context->language],strlen(_Context->msg_IsExtern[_Context->language]),_Context->value_IsExtern|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsPointer=visual_trigger_code(_Context->msg_IsPointer[_Context->language],strlen(_Context->msg_IsPointer[_Context->language]));
	visual_check(_Context->x_Auto3336+300,_Context->y_Auto3336+100,104,16,vfh[2],27,28,_Context->msg_IsPointer[_Context->language],strlen(_Context->msg_IsPointer[_Context->language]),_Context->value_IsPointer|0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_Auto3336+140,_Context->y_Auto3336+100,140,160,vfh[2],27,28,parse_selection(_Context->msg_MethodType[_Context->language],&_Context->value_MethodType),768);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3336+140,_Context->y_Auto3336+130,472+2,16+2,5);
	visual_text(_Context->x_Auto3336+140+1,_Context->y_Auto3336+130+1,472,16,vfh[1],27,28,_Context->buffer_MethodClass,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger1_MethodNature=visual_trigger_code(_Context->msg1_MethodNature[_Context->language],strlen(_Context->msg1_MethodNature[_Context->language]));
	visual_radio(_Context->x_Auto3336+140,_Context->y_Auto3336+170,84,16,vfh[2],27,28,_Context->msg1_MethodNature[_Context->language],strlen(_Context->msg1_MethodNature[_Context->language]),_Context->value_MethodNature,1);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger2_MethodNature=visual_trigger_code(_Context->msg2_MethodNature[_Context->language],strlen(_Context->msg2_MethodNature[_Context->language]));
	visual_radio(_Context->x_Auto3336+240,_Context->y_Auto3336+170,112,16,vfh[2],27,28,_Context->msg2_MethodNature[_Context->language],strlen(_Context->msg2_MethodNature[_Context->language]),_Context->value_MethodNature,2);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger3_MethodNature=visual_trigger_code(_Context->msg3_MethodNature[_Context->language],strlen(_Context->msg3_MethodNature[_Context->language]));
	visual_radio(_Context->x_Auto3336+360,_Context->y_Auto3336+170,126,16,vfh[2],27,28,_Context->msg3_MethodNature[_Context->language],strlen(_Context->msg3_MethodNature[_Context->language]),_Context->value_MethodNature,3);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger4_MethodNature=visual_trigger_code(_Context->msg4_MethodNature[_Context->language],strlen(_Context->msg4_MethodNature[_Context->language]));
	visual_radio(_Context->x_Auto3336+500,_Context->y_Auto3336+170,98,16,vfh[2],27,28,_Context->msg4_MethodNature[_Context->language],strlen(_Context->msg4_MethodNature[_Context->language]),_Context->value_MethodNature,4);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3336+140,_Context->y_Auto3336+200,472+2,16+2,5);
	visual_text(_Context->x_Auto3336+140+1,_Context->y_Auto3336+200+1,472,16,vfh[1],0,0,_Context->buffer_MethodName,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3336+140,_Context->y_Auto3336+230,472+2,192+2,5);
	visual_text(_Context->x_Auto3336+140+1,_Context->y_Auto3336+230+1,472,192,vfh[1],0,0,_Context->buffer_Signature,708,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_BodyPage=visual_trigger_code(_Context->msg_BodyPage[_Context->language],strlen(_Context->msg_BodyPage[_Context->language]));
	visual_tabpage(_Context->x_Auto3336+20,_Context->y_Auto3336+30,610,410,vfh[2],_Context->msg_BodyPage[_Context->language],strlen(_Context->msg_BodyPage[_Context->language]),96,2);
		(void) on_BodyPage_show(_Context);
	} else {
		visual_tabpage(_Context->x_Auto3336+20,_Context->y_Auto3336+30,610,410,vfh[2],_Context->msg_BodyPage[_Context->language],strlen(_Context->msg_BodyPage[_Context->language]),96,0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_MethodText_show(_Context);
		}
	_Context->trigger_Auto3341=visual_trigger_code(_Context->msg_Auto3341[_Context->language],strlen(_Context->msg_Auto3341[_Context->language]));
	visual_button(_Context->x_Auto3336+30,_Context->y_Auto3336+450,56,48,vfh[2],34,0,_Context->msg_Auto3341[_Context->language],strlen(_Context->msg_Auto3341[_Context->language]),1040);
	_Context->trigger_Auto3342=visual_trigger_code(_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]));
	visual_button(_Context->x_Auto3336+310,_Context->y_Auto3336+450,56,48,vfh[2],28,28,_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]),1040);
	_Context->trigger_Auto3343=visual_trigger_code(_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]));
	visual_button(_Context->x_Auto3336+560,_Context->y_Auto3336+450,56,48,vfh[2],34,0,_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3336,_Context->y_Auto3336,650,510);

	return(0);
}

private int MethodPage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This tab page presents the collection of forms method parameters for ";
			mptr[1]=" inspection and eventual modification.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsPublic_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This check control applies to object source generation only, and when ";
			mptr[1]=" active indicates that the forms method may be acccessed from outside ";
			mptr[2]="of the forms class. Otherwise the method will be private.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsExtern_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This check control applies to object source generation only, and when ";
			mptr[1]=" active indicates that the forms method may be acccessed from outside ";
			mptr[2]="of the forms class. Otherwise the method will be private.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsPointer_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This check control when activate indicates that the associated return ";
			mptr[1]="value will be a pointer to the type indicated by the select control ";
			mptr[2]="ReturnType.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MethodType_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[14];
			mptr[0] = "This select control allows definition of the return type of the forms ";
			mptr[1]="method taken from the table presented below :  ";
			mptr[2]=" ";
			mptr[3]="   ";
			mptr[4]=" Type Description  ";
			mptr[5]=" Void Methods of this type will not return values.  ";
			mptr[6]=" Byte 8 bit integer return type.  ";
			mptr[7]=" Word 16 bit integer return type.  ";
			mptr[8]=" Long 32 bit integer return type.  ";
			mptr[9]=" Numeric Bcd Numeric return type  ";
			mptr[10]=" String String return type  ";
			mptr[11]=" Class Class return type.   ";
			mptr[12]=" ";
			mptr[13]="  ";
			return(visual_online_help(mptr,14));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MethodClass_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the name of the class to bespecified for class ";
			mptr[1]="return types    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MethodNature1_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "This collection of radio controls applies to object source generation ";
			mptr[1]="only.  ";
			mptr[2]=" ";
			mptr[3]="The inline option implies that the application method source will ";
			mptr[4]="be inlined where invoked rather than packaged in a procedural function ";
			mptr[5]="body.    ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MethodNature2_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This radio option indicates procedural function packaging of the forms ";
			mptr[1]="method application code.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MethodNature3_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "When this radio option is selected the function method will contribute ";
			mptr[1]="to the virtual interface of its parent form.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MethodNature4_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this radio option is selected the forms method function will ";
			mptr[1]="overload a virtual function of the parent class or one of its baseclass ";
			mptr[2]="components.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MethodName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This edit field defines the formal name of the forms method.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Signature_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows definition of the parameter variables for the ";
			mptr[1]="reception of any eventual parameters values required to be passed ";
			mptr[2]="to the forms method.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "  ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 2 : 
			{
			char * mptr[1];
			mptr[0] = "  ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 3 : 
			{
			char * mptr[1];
			mptr[0] = "  ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 4 : 
			{
			char * mptr[1];
			mptr[0] = "  ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 5 : 
			{
			char * mptr[1];
			mptr[0] = "  ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 6 : 
			{
			char * mptr[1];
			mptr[0] = "  ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 7 : 
			{
			char * mptr[1];
			mptr[0] = "  ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int BodyPage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This tab page presents the application source code associated with ";
			mptr[1]="and  defined for the method.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MethodText_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the application source code to be edited activetool ";
			mptr[1]="the  internal source editor.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3341_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the ACCEPT button any changes made to the various    parameters ";
			mptr[1]="will take effect.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3342_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By clicking on this button, the full screen source editor will be ";
			mptr[1]="activated for the edition of the forms method source.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3343_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the CANCEL button any modifications performed will be ";
			mptr[1]="   discarded.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3336action(struct accept_forms_method_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_forms_method_hide(_Context);

		_Context->x_Auto3336 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3336 < 0) { _Context->x_Auto3336=0; }
		_Context->y_Auto3336 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3336 < 0) { _Context->y_Auto3336=0; }
			accept_forms_method_show(_Context);

		visual_thaw(_Context->x_Auto3336,_Context->y_Auto3336,650,510);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3341_event(struct accept_forms_method_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3342_event(struct accept_forms_method_context * _Context) {
		accept_forms_method_hide(_Context);
;
	use_editor(_Context->buffer_MethodText,-1);
		accept_forms_method_show(_Context);
;
	visual_frame(_Context->x_Auto3336+40,_Context->y_Auto3336+70,570+2,360+2,5);
;
		/* MethodText */
	/* BodyPage */
	accept_forms_method_losefocus(_Context);
	_Context->page_number = 2;
	accept_forms_method_show(_Context);
	_Context->focus_item=14;
	accept_forms_method_show(_Context);
	_Context->focus_item=15;
;
	return(FormZoomCheck());
	return(-1);
}
private int on_Auto3343_event(struct accept_forms_method_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_forms_method_event(
struct accept_forms_method_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_MethodPage == mb ) return(2);
		if (_Context->trigger_IsPublic == mb ) return(3);
		if (_Context->trigger_IsExtern == mb ) return(4);
		if (_Context->trigger_IsPointer == mb ) return(5);
		if (_Context->trigger1_MethodNature == mb ) return(8);
		if (_Context->trigger2_MethodNature == mb ) return(9);
		if (_Context->trigger3_MethodNature == mb ) return(10);
		if (_Context->trigger4_MethodNature == mb ) return(11);
		if (_Context->trigger_BodyPage == mb ) return(14);
		if (_Context->trigger_Auto3341 == mb ) return(16);
		if (_Context->trigger_Auto3342 == mb ) return(17);
		if (_Context->trigger_Auto3343 == mb ) return(18);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3336+629) )  
	&&  (my >= (_Context->y_Auto3336+4) )  
	&&  (mx <= (_Context->x_Auto3336+646) )  
	&&  (my <= (_Context->y_Auto3336+20) )) {
		return(1);	/* Auto3336 */

		}
	if ((mx >= (_Context->x_Auto3336+613) )  
	&&  (my >= (_Context->y_Auto3336+4) )  
	&&  (mx <= (_Context->x_Auto3336+630) )  
	&&  (my <= (_Context->y_Auto3336+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vmethod.htm");
			};
		return(-1);	/* Auto3336 */

		}
	if ((mx >= (_Context->x_Auto3336+597) )  
	&&  (my >= (_Context->y_Auto3336+4) )  
	&&  (mx <= (_Context->x_Auto3336+614) )  
	&&  (my <= (_Context->y_Auto3336+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_forms_method_show(_Context);
		return(-1);	/* Auto3336 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3336+4) )  
		&&  (my >= (_Context->y_Auto3336+4) )  
		&&  (mx <= (_Context->x_Auto3336+582) )  
		&&  (my <= (_Context->y_Auto3336+20) )) {
			return( Auto3336action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto3336+20+0) ) 
		&&  ( my >= (_Context->y_Auto3336+30) ) 
		&&  ( mx <= (_Context->x_Auto3336+20+95) ) 
		&&  ( my <= (_Context->y_Auto3336+30+24))) {
			return(2); /* MethodPage */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3336+40) ) 
		&&  ( my >= (_Context->y_Auto3336+100) ) 
		&&  ( mx <= (_Context->x_Auto3336+40+98) ) 
		&&  ( my <= (_Context->y_Auto3336+100+16))) {
			return(3); /* IsPublic */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3336+40) ) 
		&&  ( my >= (_Context->y_Auto3336+130) ) 
		&&  ( mx <= (_Context->x_Auto3336+40+98) ) 
		&&  ( my <= (_Context->y_Auto3336+130+16))) {
			return(4); /* IsExtern */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3336+300) ) 
		&&  ( my >= (_Context->y_Auto3336+100) ) 
		&&  ( mx <= (_Context->x_Auto3336+300+104) ) 
		&&  ( my <= (_Context->y_Auto3336+100+16))) {
			return(5); /* IsPointer */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3336+140+0) ) 
		&&  ( my >= (_Context->y_Auto3336+100) ) 
		&&  ( mx <= (_Context->x_Auto3336+140+140) ) 
		&&  ( my <= (_Context->y_Auto3336+100+16))) {
			return(6); /* MethodType */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3336+140) ) 
		&&  ( my >= (_Context->y_Auto3336+130) ) 
		&&  ( mx <= (_Context->x_Auto3336+140+472) ) 
		&&  ( my <= (_Context->y_Auto3336+130+16))) {
			return(7); /* MethodClass */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3336+140) ) 
		&&  ( my >= (_Context->y_Auto3336+170) ) 
		&&  ( mx <= (_Context->x_Auto3336+140+84) ) 
		&&  ( my <= (_Context->y_Auto3336+170+16))) {
			return(8); /* MethodNature */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3336+240) ) 
		&&  ( my >= (_Context->y_Auto3336+170) ) 
		&&  ( mx <= (_Context->x_Auto3336+240+112) ) 
		&&  ( my <= (_Context->y_Auto3336+170+16))) {
			return(9); /* MethodNature */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3336+360) ) 
		&&  ( my >= (_Context->y_Auto3336+170) ) 
		&&  ( mx <= (_Context->x_Auto3336+360+126) ) 
		&&  ( my <= (_Context->y_Auto3336+170+16))) {
			return(10); /* MethodNature */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3336+500) ) 
		&&  ( my >= (_Context->y_Auto3336+170) ) 
		&&  ( mx <= (_Context->x_Auto3336+500+98) ) 
		&&  ( my <= (_Context->y_Auto3336+170+16))) {
			return(11); /* MethodNature */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3336+140) ) 
		&&  ( my >= (_Context->y_Auto3336+200) ) 
		&&  ( mx <= (_Context->x_Auto3336+140+472) ) 
		&&  ( my <= (_Context->y_Auto3336+200+16))) {
			return(12); /* MethodName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3336+140) ) 
		&&  ( my >= (_Context->y_Auto3336+230) ) 
		&&  ( mx <= (_Context->x_Auto3336+140+472) ) 
		&&  ( my <= (_Context->y_Auto3336+230+192))) {
			return(13); /* Signature */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto3336+20+96) ) 
		&&  ( my >= (_Context->y_Auto3336+30) ) 
		&&  ( mx <= (_Context->x_Auto3336+20+174) ) 
		&&  ( my <= (_Context->y_Auto3336+30+24))) {
			return(14); /* BodyPage */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3336+40) ) 
		&&  ( my >= (_Context->y_Auto3336+70) ) 
		&&  ( mx <= (_Context->x_Auto3336+40+570) ) 
		&&  ( my <= (_Context->y_Auto3336+70+360))) {
			return(15); /* MethodText */
			}
		}
	if (( mx >= (_Context->x_Auto3336+30) ) 
	&&  ( my >= (_Context->y_Auto3336+450) ) 
	&&  ( mx <= (_Context->x_Auto3336+30+56) ) 
	&&  ( my <= (_Context->y_Auto3336+450+48))) {
		return(16); /* Auto3341 */
		}
	if (( mx >= (_Context->x_Auto3336+310) ) 
	&&  ( my >= (_Context->y_Auto3336+450) ) 
	&&  ( mx <= (_Context->x_Auto3336+310+56) ) 
	&&  ( my <= (_Context->y_Auto3336+450+48))) {
		return(17); /* Auto3342 */
		}
	if (( mx >= (_Context->x_Auto3336+560) ) 
	&&  ( my >= (_Context->y_Auto3336+450) ) 
	&&  ( mx <= (_Context->x_Auto3336+560+56) ) 
	&&  ( my <= (_Context->y_Auto3336+450+48))) {
		return(18); /* Auto3343 */
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
			case	0x2 :
				/* MethodPage */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* IsPublic */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3336+40,_Context->y_Auto3336+100,98,16,vfh[2],27,28,_Context->msg_IsPublic[_Context->language],strlen(_Context->msg_IsPublic[_Context->language]),(_Context->value_IsPublic |2));
					_Context->keycode = visual_getch();
					_Context->trigger_IsPublic=visual_trigger_code(_Context->msg_IsPublic[_Context->language],strlen(_Context->msg_IsPublic[_Context->language]));
	visual_check(_Context->x_Auto3336+40,_Context->y_Auto3336+100,98,16,vfh[2],27,28,_Context->msg_IsPublic[_Context->language],strlen(_Context->msg_IsPublic[_Context->language]),_Context->value_IsPublic|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* IsExtern */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3336+40,_Context->y_Auto3336+130,98,16,vfh[2],27,28,_Context->msg_IsExtern[_Context->language],strlen(_Context->msg_IsExtern[_Context->language]),(_Context->value_IsExtern |2));
					_Context->keycode = visual_getch();
					_Context->trigger_IsExtern=visual_trigger_code(_Context->msg_IsExtern[_Context->language],strlen(_Context->msg_IsExtern[_Context->language]));
	visual_check(_Context->x_Auto3336+40,_Context->y_Auto3336+130,98,16,vfh[2],27,28,_Context->msg_IsExtern[_Context->language],strlen(_Context->msg_IsExtern[_Context->language]),_Context->value_IsExtern|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* IsPointer */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3336+300,_Context->y_Auto3336+100,104,16,vfh[2],27,28,_Context->msg_IsPointer[_Context->language],strlen(_Context->msg_IsPointer[_Context->language]),(_Context->value_IsPointer |2));
					_Context->keycode = visual_getch();
					_Context->trigger_IsPointer=visual_trigger_code(_Context->msg_IsPointer[_Context->language],strlen(_Context->msg_IsPointer[_Context->language]));
	visual_check(_Context->x_Auto3336+300,_Context->y_Auto3336+100,104,16,vfh[2],27,28,_Context->msg_IsPointer[_Context->language],strlen(_Context->msg_IsPointer[_Context->language]),_Context->value_IsPointer|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* MethodType */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto3336+140,_Context->y_Auto3336+100,140,160,vfh[2],27,28,parse_selection(_Context->msg_MethodType[_Context->language],&_Context->value_MethodType),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* MethodClass */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3336+140+1,_Context->y_Auto3336+130+1,472,16,vfh[1],_Context->buffer_MethodClass,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* MethodNature */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_getch();
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* MethodNature */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_getch();
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
				/* MethodName */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3336+140+1,_Context->y_Auto3336+200+1,472,16,vfh[1],_Context->buffer_MethodName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* Signature */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3336+140+1,_Context->y_Auto3336+230+1,472,192,vfh[1],_Context->buffer_Signature,708);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* BodyPage */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xf :
				/* MethodText */
				if (_Context->page_number == 2 ) {
					_Context->keycode = on_MethodText_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* Auto3341 */
				_Context->trigger_Auto3341=visual_trigger_code(_Context->msg_Auto3341[_Context->language],strlen(_Context->msg_Auto3341[_Context->language]));
				visual_button(_Context->x_Auto3336+30,_Context->y_Auto3336+450,56,48,vfh[2],34,0,_Context->msg_Auto3341[_Context->language],strlen(_Context->msg_Auto3341[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3341=visual_trigger_code(_Context->msg_Auto3341[_Context->language],strlen(_Context->msg_Auto3341[_Context->language]));
	visual_button(_Context->x_Auto3336+30,_Context->y_Auto3336+450,56,48,vfh[2],34,0,_Context->msg_Auto3341[_Context->language],strlen(_Context->msg_Auto3341[_Context->language]),1040);
				break;
			case	0x12 :
				/* Auto3343 */
				_Context->trigger_Auto3343=visual_trigger_code(_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]));
				visual_button(_Context->x_Auto3336+560,_Context->y_Auto3336+450,56,48,vfh[2],34,0,_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3343=visual_trigger_code(_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]));
	visual_button(_Context->x_Auto3336+560,_Context->y_Auto3336+450,56,48,vfh[2],34,0,_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]),1040);
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
			_Context->focus_item=18;
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
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (MethodPage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (IsPublic_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (IsExtern_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (IsPointer_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (MethodType_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (MethodClass_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (MethodNature1_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (MethodNature2_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (MethodNature3_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (MethodNature4_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (MethodName_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (Signature_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (BodyPage_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (MethodText_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (Auto3341_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (Auto3342_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (Auto3343_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3336 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* MethodPage */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_forms_method_losefocus(_Context);
						_Context->page_number = 1;
						accept_forms_method_show(_Context);
						}
					continue;
				case	0x3 :
					/* IsPublic */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsPublic += 1;
						_Context->value_IsPublic &= 1;
						}
					continue;
				case	0x4 :
					/* IsExtern */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsExtern += 1;
						_Context->value_IsExtern &= 1;
						}
					continue;
				case	0x5 :
					/* IsPointer */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsPointer += 1;
						_Context->value_IsPointer &= 1;
						}
					continue;
				case	0x6 :
					/* MethodType */
					continue;
				case	0x7 :
					/* MethodClass */
					continue;
				case	0x8 :
					/* MethodNature */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MethodNature = 1;
						accept_forms_method_show(_Context);
						}
					continue;
				case	0x9 :
					/* MethodNature */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MethodNature = 2;
						accept_forms_method_show(_Context);
						}
					continue;
				case	0xa :
					/* MethodNature */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MethodNature = 3;
						accept_forms_method_show(_Context);
						}
					continue;
				case	0xb :
					/* MethodNature */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MethodNature = 4;
						accept_forms_method_show(_Context);
						}
					continue;
				case	0xc :
					/* MethodName */
					continue;
				case	0xd :
					/* Signature */
					continue;
				case	0xe :
					/* BodyPage */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_forms_method_losefocus(_Context);
						_Context->page_number = 2;
						accept_forms_method_show(_Context);
						}
					continue;
				case	0xf :
					/* MethodText */
					continue;
				case	0x10 :
					/* Auto3341 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3341=visual_trigger_code(_Context->msg_Auto3341[_Context->language],strlen(_Context->msg_Auto3341[_Context->language]));
						visual_button(_Context->x_Auto3336+30,_Context->y_Auto3336+450,56,48,vfh[2],34,0,_Context->msg_Auto3341[_Context->language],strlen(_Context->msg_Auto3341[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3341=visual_trigger_code(_Context->msg_Auto3341[_Context->language],strlen(_Context->msg_Auto3341[_Context->language]));
	visual_button(_Context->x_Auto3336+30,_Context->y_Auto3336+450,56,48,vfh[2],34,0,_Context->msg_Auto3341[_Context->language],strlen(_Context->msg_Auto3341[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3341_event(_Context)) != -1) break;

						}
					continue;
				case	0x11 :
					/* Auto3342 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3342=visual_trigger_code(_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]));
						visual_button(_Context->x_Auto3336+310,_Context->y_Auto3336+450,56,48,vfh[2],28,28,_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3342=visual_trigger_code(_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]));
	visual_button(_Context->x_Auto3336+310,_Context->y_Auto3336+450,56,48,vfh[2],28,28,_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3342_event(_Context)) != -1) break;

						}
					continue;
				case	0x12 :
					/* Auto3343 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3343=visual_trigger_code(_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]));
						visual_button(_Context->x_Auto3336+560,_Context->y_Auto3336+450,56,48,vfh[2],34,0,_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3343=visual_trigger_code(_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]));
	visual_button(_Context->x_Auto3336+560,_Context->y_Auto3336+450,56,48,vfh[2],34,0,_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3343_event(_Context)) != -1) break;

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
				_Context->focus_item=18;
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
	char * pIsExtern,
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
	 pIsExtern,
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
	 pIsExtern,
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
