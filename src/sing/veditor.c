
#ifndef _veditor_c
#define _veditor_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : veditor.sng  */
/* Target         : veditor.c  */
/* Identification : 0.0-1065019113-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct visual_text_editor_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	value_B;
	int	value_I;
	int	value_U;
	int	value_HREF;
	int	value_HR;
	int	value_BR;
	int	value_OL;
	int	value_UL;
	int	value_LI;
	int	value_DL;
	int	value_DT;
	int	value_DD;
	int	value_P;
	int	value_IMG;
	int	value_DIV;
	int	value_TABLE;
	int	value_TR;
	int	value_TH;
	int	value_TD;
	int	value_H1;
	int	value_H2;
	int	value_H3;
	int	value_H4;
	int	value_H5;
	int	value_H6;
	char * buffer_Body;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[27];
	} * _Context;

private	int	visual_text_editor_create(
	char * pB,
	char * pI,
	char * pU,
	char * pHREF,
	char * pHR,
	char * pBR,
	char * pOL,
	char * pUL,
	char * pLI,
	char * pDL,
	char * pDT,
	char * pDD,
	char * pP,
	char * pIMG,
	char * pDIV,
	char * pTABLE,
	char * pTR,
	char * pTH,
	char * pTD,
	char * pH1,
	char * pH2,
	char * pH3,
	char * pH4,
	char * pH5,
	char * pH6,
	char * pBody)
{

	if (!(_Context = allocate( sizeof( struct visual_text_editor_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=29;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWWWWWWWWWWWWWWWWT");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pB);
		if (!( pB )) _Context->value_B=0;
		else	_Context->value_B = *((int *)pB);
		visual_transferin((void *) 0, 0, pI);
		if (!( pI )) _Context->value_I=0;
		else	_Context->value_I = *((int *)pI);
		visual_transferin((void *) 0, 0, pU);
		if (!( pU )) _Context->value_U=0;
		else	_Context->value_U = *((int *)pU);
		visual_transferin((void *) 0, 0, pHREF);
		if (!( pHREF )) _Context->value_HREF=0;
		else	_Context->value_HREF = *((int *)pHREF);
		visual_transferin((void *) 0, 0, pHR);
		if (!( pHR )) _Context->value_HR=0;
		else	_Context->value_HR = *((int *)pHR);
		visual_transferin((void *) 0, 0, pBR);
		if (!( pBR )) _Context->value_BR=0;
		else	_Context->value_BR = *((int *)pBR);
		visual_transferin((void *) 0, 0, pOL);
		if (!( pOL )) _Context->value_OL=0;
		else	_Context->value_OL = *((int *)pOL);
		visual_transferin((void *) 0, 0, pUL);
		if (!( pUL )) _Context->value_UL=0;
		else	_Context->value_UL = *((int *)pUL);
		visual_transferin((void *) 0, 0, pLI);
		if (!( pLI )) _Context->value_LI=0;
		else	_Context->value_LI = *((int *)pLI);
		visual_transferin((void *) 0, 0, pDL);
		if (!( pDL )) _Context->value_DL=0;
		else	_Context->value_DL = *((int *)pDL);
		visual_transferin((void *) 0, 0, pDT);
		if (!( pDT )) _Context->value_DT=0;
		else	_Context->value_DT = *((int *)pDT);
		visual_transferin((void *) 0, 0, pDD);
		if (!( pDD )) _Context->value_DD=0;
		else	_Context->value_DD = *((int *)pDD);
		visual_transferin((void *) 0, 0, pP);
		if (!( pP )) _Context->value_P=0;
		else	_Context->value_P = *((int *)pP);
		visual_transferin((void *) 0, 0, pIMG);
		if (!( pIMG )) _Context->value_IMG=0;
		else	_Context->value_IMG = *((int *)pIMG);
		visual_transferin((void *) 0, 0, pDIV);
		if (!( pDIV )) _Context->value_DIV=0;
		else	_Context->value_DIV = *((int *)pDIV);
		visual_transferin((void *) 0, 0, pTABLE);
		if (!( pTABLE )) _Context->value_TABLE=0;
		else	_Context->value_TABLE = *((int *)pTABLE);
		visual_transferin((void *) 0, 0, pTR);
		if (!( pTR )) _Context->value_TR=0;
		else	_Context->value_TR = *((int *)pTR);
		visual_transferin((void *) 0, 0, pTH);
		if (!( pTH )) _Context->value_TH=0;
		else	_Context->value_TH = *((int *)pTH);
		visual_transferin((void *) 0, 0, pTD);
		if (!( pTD )) _Context->value_TD=0;
		else	_Context->value_TD = *((int *)pTD);
		visual_transferin((void *) 0, 0, pH1);
		if (!( pH1 )) _Context->value_H1=0;
		else	_Context->value_H1 = *((int *)pH1);
		visual_transferin((void *) 0, 0, pH2);
		if (!( pH2 )) _Context->value_H2=0;
		else	_Context->value_H2 = *((int *)pH2);
		visual_transferin((void *) 0, 0, pH3);
		if (!( pH3 )) _Context->value_H3=0;
		else	_Context->value_H3 = *((int *)pH3);
		visual_transferin((void *) 0, 0, pH4);
		if (!( pH4 )) _Context->value_H4=0;
		else	_Context->value_H4 = *((int *)pH4);
		visual_transferin((void *) 0, 0, pH5);
		if (!( pH5 )) _Context->value_H5=0;
		else	_Context->value_H5 = *((int *)pH5);
		visual_transferin((void *) 0, 0, pH6);
		if (!( pH6 )) _Context->value_H6=0;
		else	_Context->value_H6 = *((int *)pH6);
				_Context->buffer_Body=(char *) 0;
		visual_transferin(&_Context->buffer_Body, 1768, pBody);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	open_window_editor(86,112,546,418,_Context->buffer_Body);
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(70,44,660+10,512+10);
	return(0);
}
private int on_Body_hide() {
	close_window_editor(86,112,546,418,_Context->buffer_Body);
	return(-1);
}

private	int	visual_text_editor_hide()
{
	(void) on_Body_hide();
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,70,44);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	visual_text_editor_remove(
	char * pB,
	char * pI,
	char * pU,
	char * pHREF,
	char * pHR,
	char * pBR,
	char * pOL,
	char * pUL,
	char * pLI,
	char * pDL,
	char * pDT,
	char * pDD,
	char * pP,
	char * pIMG,
	char * pDIV,
	char * pTABLE,
	char * pTR,
	char * pTH,
	char * pTD,
	char * pH1,
	char * pH2,
	char * pH3,
	char * pH4,
	char * pH5,
	char * pH6,
	char * pBody)
{

	int	result=_Context->keycode;
	if (_Context->keycode == 27 ) {
		filetransferdrop(_Context->buffer_Body);
		
	} else {
		strcpy(_Context->signature,"WWWWWWWWWWWWWWWWWWWWWWWWWT");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pB);
		if ( pB != (char *) 0)
			*((int*)pB) = _Context->value_B;
		visual_transferout((void *) 0, 0, pI);
		if ( pI != (char *) 0)
			*((int*)pI) = _Context->value_I;
		visual_transferout((void *) 0, 0, pU);
		if ( pU != (char *) 0)
			*((int*)pU) = _Context->value_U;
		visual_transferout((void *) 0, 0, pHREF);
		if ( pHREF != (char *) 0)
			*((int*)pHREF) = _Context->value_HREF;
		visual_transferout((void *) 0, 0, pHR);
		if ( pHR != (char *) 0)
			*((int*)pHR) = _Context->value_HR;
		visual_transferout((void *) 0, 0, pBR);
		if ( pBR != (char *) 0)
			*((int*)pBR) = _Context->value_BR;
		visual_transferout((void *) 0, 0, pOL);
		if ( pOL != (char *) 0)
			*((int*)pOL) = _Context->value_OL;
		visual_transferout((void *) 0, 0, pUL);
		if ( pUL != (char *) 0)
			*((int*)pUL) = _Context->value_UL;
		visual_transferout((void *) 0, 0, pLI);
		if ( pLI != (char *) 0)
			*((int*)pLI) = _Context->value_LI;
		visual_transferout((void *) 0, 0, pDL);
		if ( pDL != (char *) 0)
			*((int*)pDL) = _Context->value_DL;
		visual_transferout((void *) 0, 0, pDT);
		if ( pDT != (char *) 0)
			*((int*)pDT) = _Context->value_DT;
		visual_transferout((void *) 0, 0, pDD);
		if ( pDD != (char *) 0)
			*((int*)pDD) = _Context->value_DD;
		visual_transferout((void *) 0, 0, pP);
		if ( pP != (char *) 0)
			*((int*)pP) = _Context->value_P;
		visual_transferout((void *) 0, 0, pIMG);
		if ( pIMG != (char *) 0)
			*((int*)pIMG) = _Context->value_IMG;
		visual_transferout((void *) 0, 0, pDIV);
		if ( pDIV != (char *) 0)
			*((int*)pDIV) = _Context->value_DIV;
		visual_transferout((void *) 0, 0, pTABLE);
		if ( pTABLE != (char *) 0)
			*((int*)pTABLE) = _Context->value_TABLE;
		visual_transferout((void *) 0, 0, pTR);
		if ( pTR != (char *) 0)
			*((int*)pTR) = _Context->value_TR;
		visual_transferout((void *) 0, 0, pTH);
		if ( pTH != (char *) 0)
			*((int*)pTH) = _Context->value_TH;
		visual_transferout((void *) 0, 0, pTD);
		if ( pTD != (char *) 0)
			*((int*)pTD) = _Context->value_TD;
		visual_transferout((void *) 0, 0, pH1);
		if ( pH1 != (char *) 0)
			*((int*)pH1) = _Context->value_H1;
		visual_transferout((void *) 0, 0, pH2);
		if ( pH2 != (char *) 0)
			*((int*)pH2) = _Context->value_H2;
		visual_transferout((void *) 0, 0, pH3);
		if ( pH3 != (char *) 0)
			*((int*)pH3) = _Context->value_H3;
		visual_transferout((void *) 0, 0, pH4);
		if ( pH4 != (char *) 0)
			*((int*)pH4) = _Context->value_H4;
		visual_transferout((void *) 0, 0, pH5);
		if ( pH5 != (char *) 0)
			*((int*)pH5) = _Context->value_H5;
		visual_transferout((void *) 0, 0, pH6);
		if ( pH6 != (char *) 0)
			*((int*)pH6) = _Context->value_H6;
		visual_transferout(&_Context->buffer_Body, 1768, pBody);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Body_show() {
	show_window_editor();
	return(-1);
}

private	int	visual_text_editor_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,70,44);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(70,44,660,512,2,"Sing : Version 1.1a",19,0x400);
	visual_image(74,66,652,484,"skin.gif",4);
	visual_text(82,92,556,16,2,27,0,"Documentation Text Editor",25,258);
	visual_frame(82,108,556,428,258);
	visual_switch(82,68,24,16,1,12,15,"B",1,_Context->value_B);
	visual_switch(102,68,24,16,1,12,15,"I",1,_Context->value_I);
	visual_switch(122,68,24,16,1,12,15,"U",1,_Context->value_U);
	visual_switch(142,68,40,16,1,12,15,"HREF",4,_Context->value_HREF);
	visual_switch(178,68,24,16,1,12,15,"HR",2,_Context->value_HR);
	visual_switch(198,68,24,16,1,12,15,"BR",2,_Context->value_BR);
	visual_switch(238,68,24,16,1,12,15,"OL",2,_Context->value_OL);
	visual_switch(258,68,24,16,1,12,15,"UL",2,_Context->value_UL);
	visual_switch(278,68,24,16,1,12,15,"LI",2,_Context->value_LI);
	visual_switch(298,68,24,16,1,12,15,"DL",2,_Context->value_DL);
	visual_switch(318,68,24,16,1,12,15,"DT",2,_Context->value_DT);
	visual_switch(338,68,24,16,1,12,15,"DD",2,_Context->value_DD);
	visual_switch(218,68,24,16,1,12,15,"P",1,_Context->value_P);
	visual_switch(358,68,32,16,1,12,15,"IMG",3,_Context->value_IMG);
	visual_switch(386,68,32,16,1,12,15,"DIV",3,_Context->value_DIV);
	visual_switch(414,68,48,16,1,12,15,"TABLE",5,_Context->value_TABLE);
	visual_switch(458,68,24,16,1,12,15,"TR",2,_Context->value_TR);
	visual_switch(478,68,24,16,1,12,15,"TH",2,_Context->value_TH);
	visual_switch(498,68,24,16,1,12,15,"TD",2,_Context->value_TD);
	visual_switch(518,68,24,16,1,12,15,"H1",2,_Context->value_H1);
	visual_switch(538,68,24,16,1,12,15,"H2",2,_Context->value_H2);
	visual_switch(558,68,24,16,1,12,15,"H3",2,_Context->value_H3);
	visual_switch(578,68,24,16,1,12,15,"H4",2,_Context->value_H4);
	visual_switch(598,68,24,16,1,12,15,"H5",2,_Context->value_H5);
	visual_switch(618,68,24,16,1,12,15,"H6",2,_Context->value_H6);
	visual_button(646,460,70,32,2,26,0,"&Accept",7,0);
	visual_button(646,498,70,32,2,26,0,"&Cancel",7,0);
	visual_frame(86,112,546+2,418+2,5);
	(void) on_Body_show();
	visual_thaw(70,44,660,512);

	return(0);
}
private int on_B_event() {
	if(_Context->value_B)
	editorOnUseString("<B>");
	else editorOnUseString("</B>");
	return(-1);
}
private int on_I_event() {
	if(_Context->value_I)
	editorOnUseString("<I>");
	else editorOnUseString("</I>");
	return(-1);
}
private int on_U_event() {
	if(_Context->value_U)
	editorOnUseString("<U>");
	else editorOnUseString("</U>");
	return(-1);
}
private int on_HREF_event() {
	if(_Context->value_HREF)
	editorOnUseString("<A HREF=");
	else editorOnUseString("</A>");
	return(-1);
}
private int on_HR_event() {
	if(_Context->value_HR){
	editorOnUseString("<HR>");
	_Context->value_HR=0;
		visual_switch(178,68,24,16,1,12,15,"HR",2,_Context->value_HR);
;
	}
	return(-1);
}
private int on_BR_event() {
	if(_Context->value_BR){
	editorOnUseString("<BR>");
	_Context->value_BR=0;
		visual_switch(198,68,24,16,1,12,15,"BR",2,_Context->value_BR);
;
	}
	return(-1);
}
private int on_OL_event() {
	if(_Context->value_OL)
	editorOnUseString("<OL>");
	else editorOnUseString("</OL>");
	return(-1);
}
private int on_UL_event() {
	if(_Context->value_UL)
	editorOnUseString("<UL>");
	else editorOnUseString("</UL>");
	return(-1);
}
private int on_LI_event() {
	if(_Context->value_LI){
	editorOnUseString("<LI>");
	_Context->value_LI=0;
		visual_switch(278,68,24,16,1,12,15,"LI",2,_Context->value_LI);
;
	}
	return(-1);
}
private int on_DL_event() {
	if(_Context->value_DL)
	editorOnUseString("<DL>");
	else editorOnUseString("</DL>");
	return(-1);
}
private int on_DT_event() {
	if(_Context->value_DT){
	editorOnUseString("<DT>");
	_Context->value_DT=0;
		visual_switch(318,68,24,16,1,12,15,"DT",2,_Context->value_DT);
;
	}
	return(-1);
}
private int on_DD_event() {
	if(_Context->value_DD){
	editorOnUseString("<DD>");
	_Context->value_DD=0;
		visual_switch(338,68,24,16,1,12,15,"DD",2,_Context->value_DD);
;
	}
	return(-1);
}
private int on_P_event() {
	if(_Context->value_P){
	editorOnUseString("<P>");
	_Context->value_P=0;
		visual_switch(218,68,24,16,1,12,15,"P",1,_Context->value_P);
;
	}
	return(-1);
}
private int on_IMG_event() {
	if(_Context->value_IMG){
	editorOnUseString("<IMG SRC=>");
	_Context->value_IMG=0;
		visual_switch(358,68,32,16,1,12,15,"IMG",3,_Context->value_IMG);
;
	}
	return(-1);
}
private int on_DIV_event() {
	if(_Context->value_DIV)
	editorOnUseString("<DIV ALIGN=CENTER>");
	else editorOnUseString("</DIV>");
	return(-1);
}
private int on_TABLE_event() {
	if(_Context->value_TABLE)
	editorOnUseString("<TABLE>");
	else editorOnUseString("</TABLE>");
	return(-1);
}
private int on_TR_event() {
	if(_Context->value_TR){
	editorOnUseString("<TR>");
	_Context->value_TR=0;
		visual_switch(458,68,24,16,1,12,15,"TR",2,_Context->value_TR);
;
	}
	return(-1);
}
private int on_TH_event() {
	if(_Context->value_TH){
	editorOnUseString("<TH>");
	_Context->value_TH=0;
		visual_switch(478,68,24,16,1,12,15,"TH",2,_Context->value_TH);
;
	}
	return(-1);
}
private int on_TD_event() {
	if(_Context->value_TD){
	editorOnUseString("<TD>");
	_Context->value_TD=0;
		visual_switch(498,68,24,16,1,12,15,"TD",2,_Context->value_TD);
;
	}
	return(-1);
}
private int on_H1_event() {
	if(_Context->value_H1)
	editorOnUseString("<H1>");
	else editorOnUseString("</H1>");
	return(-1);
}
private int on_H2_event() {
	if(_Context->value_H2)
	editorOnUseString("<H2>");
	else editorOnUseString("</H2>");
	return(-1);
}
private int on_H3_event() {
	if(_Context->value_H3)
	editorOnUseString("<H3>");
	else editorOnUseString("</H3>");
	return(-1);
}
private int on_H4_event() {
	if(_Context->value_H4)
	editorOnUseString("<H4>");
	else editorOnUseString("</H4>");
	return(-1);
}
private int on_H5_event() {
	if(_Context->value_H5)
	editorOnUseString("<H5>");
	else editorOnUseString("</H5>");
	return(-1);
}
private int on_H6_event() {
	if(_Context->value_H6)
	editorOnUseString("<H6>");
	else editorOnUseString("</H6>");
	return(-1);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	visual_text_editor_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 82 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 106 ) 
	&&  ( my <= 84 )) {
		return(2); /* B */
		}
	if (( mx >= 102 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 126 ) 
	&&  ( my <= 84 )) {
		return(3); /* I */
		}
	if (( mx >= 122 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 146 ) 
	&&  ( my <= 84 )) {
		return(4); /* U */
		}
	if (( mx >= 142 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 182 ) 
	&&  ( my <= 84 )) {
		return(5); /* HREF */
		}
	if (( mx >= 178 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 202 ) 
	&&  ( my <= 84 )) {
		return(6); /* HR */
		}
	if (( mx >= 198 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 222 ) 
	&&  ( my <= 84 )) {
		return(7); /* BR */
		}
	if (( mx >= 238 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 262 ) 
	&&  ( my <= 84 )) {
		return(8); /* OL */
		}
	if (( mx >= 258 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 282 ) 
	&&  ( my <= 84 )) {
		return(9); /* UL */
		}
	if (( mx >= 278 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 302 ) 
	&&  ( my <= 84 )) {
		return(10); /* LI */
		}
	if (( mx >= 298 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 322 ) 
	&&  ( my <= 84 )) {
		return(11); /* DL */
		}
	if (( mx >= 318 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 342 ) 
	&&  ( my <= 84 )) {
		return(12); /* DT */
		}
	if (( mx >= 338 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 362 ) 
	&&  ( my <= 84 )) {
		return(13); /* DD */
		}
	if (( mx >= 218 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 242 ) 
	&&  ( my <= 84 )) {
		return(14); /* P */
		}
	if (( mx >= 358 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 390 ) 
	&&  ( my <= 84 )) {
		return(15); /* IMG */
		}
	if (( mx >= 386 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 418 ) 
	&&  ( my <= 84 )) {
		return(16); /* DIV */
		}
	if (( mx >= 414 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 462 ) 
	&&  ( my <= 84 )) {
		return(17); /* TABLE */
		}
	if (( mx >= 458 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 482 ) 
	&&  ( my <= 84 )) {
		return(18); /* TR */
		}
	if (( mx >= 478 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 502 ) 
	&&  ( my <= 84 )) {
		return(19); /* TH */
		}
	if (( mx >= 498 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 522 ) 
	&&  ( my <= 84 )) {
		return(20); /* TD */
		}
	if (( mx >= 518 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 542 ) 
	&&  ( my <= 84 )) {
		return(21); /* H1 */
		}
	if (( mx >= 538 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 562 ) 
	&&  ( my <= 84 )) {
		return(22); /* H2 */
		}
	if (( mx >= 558 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 582 ) 
	&&  ( my <= 84 )) {
		return(23); /* H3 */
		}
	if (( mx >= 578 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 602 ) 
	&&  ( my <= 84 )) {
		return(24); /* H4 */
		}
	if (( mx >= 598 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 622 ) 
	&&  ( my <= 84 )) {
		return(25); /* H5 */
		}
	if (( mx >= 618 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 642 ) 
	&&  ( my <= 84 )) {
		return(26); /* H6 */
		}
	if (( mx >= 646 ) 
	&&  ( my >= 460 ) 
	&&  ( mx <= 716 ) 
	&&  ( my <= 492 )) {
		return(27); /* Accept */
		}
	if (( mx >= 646 ) 
	&&  ( my >= 498 ) 
	&&  ( mx <= 716 ) 
	&&  ( my <= 530 )) {
		return(28); /* Cancel */
		}
	if (( mx >= 86 ) 
	&&  ( my >= 112 ) 
	&&  ( mx <= 632 ) 
	&&  ( my <= 530 )) {
		return(29); /* Body */
		}

	return(-1);
}
private int on_Body_getfocus() {
	return(focus_window_editor());
	return(-1);
}


private	int	visual_text_editor_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1b :
				/* Accept */
				visual_button(646,460,70,32,2,26,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(646,460,70,32,2,26,0,"&Accept",7,0);
				break;
			case	0x1c :
				/* Cancel */
				visual_button(646,498,70,32,2,26,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(646,498,70,32,2,26,0,"&Cancel",7,0);
				break;
			case	0x1d :
				/* Body */
				if ((_Context->keycode = on_Body_getfocus()) != -1) break;
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			visual_text_editor_show();
			continue;
		case	0x2 :
			_Context->focus_item=29;
			visual_text_editor_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=visual_text_editor_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto1 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* B */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_B += 1;
							_Context->value_B &= 1;
				visual_switch(82,68,24,16,1,12,15,"B",1,(_Context->value_B |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_B_event()) != -1) break;

							}
						continue;
					case	0x3 :
						/* I */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_I += 1;
							_Context->value_I &= 1;
				visual_switch(102,68,24,16,1,12,15,"I",1,(_Context->value_I |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_I_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* U */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_U += 1;
							_Context->value_U &= 1;
				visual_switch(122,68,24,16,1,12,15,"U",1,(_Context->value_U |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_U_event()) != -1) break;

							}
						continue;
					case	0x5 :
						/* HREF */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_HREF += 1;
							_Context->value_HREF &= 1;
				visual_switch(142,68,40,16,1,12,15,"HREF",4,(_Context->value_HREF |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_HREF_event()) != -1) break;

							}
						continue;
					case	0x6 :
						/* HR */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_HR += 1;
							_Context->value_HR &= 1;
				visual_switch(178,68,24,16,1,12,15,"HR",2,(_Context->value_HR |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_HR_event()) != -1) break;

							}
						continue;
					case	0x7 :
						/* BR */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_BR += 1;
							_Context->value_BR &= 1;
				visual_switch(198,68,24,16,1,12,15,"BR",2,(_Context->value_BR |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_BR_event()) != -1) break;

							}
						continue;
					case	0x8 :
						/* OL */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_OL += 1;
							_Context->value_OL &= 1;
				visual_switch(238,68,24,16,1,12,15,"OL",2,(_Context->value_OL |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_OL_event()) != -1) break;

							}
						continue;
					case	0x9 :
						/* UL */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UL += 1;
							_Context->value_UL &= 1;
				visual_switch(258,68,24,16,1,12,15,"UL",2,(_Context->value_UL |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_UL_event()) != -1) break;

							}
						continue;
					case	0xa :
						/* LI */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_LI += 1;
							_Context->value_LI &= 1;
				visual_switch(278,68,24,16,1,12,15,"LI",2,(_Context->value_LI |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_LI_event()) != -1) break;

							}
						continue;
					case	0xb :
						/* DL */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_DL += 1;
							_Context->value_DL &= 1;
				visual_switch(298,68,24,16,1,12,15,"DL",2,(_Context->value_DL |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_DL_event()) != -1) break;

							}
						continue;
					case	0xc :
						/* DT */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_DT += 1;
							_Context->value_DT &= 1;
				visual_switch(318,68,24,16,1,12,15,"DT",2,(_Context->value_DT |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_DT_event()) != -1) break;

							}
						continue;
					case	0xd :
						/* DD */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_DD += 1;
							_Context->value_DD &= 1;
				visual_switch(338,68,24,16,1,12,15,"DD",2,(_Context->value_DD |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_DD_event()) != -1) break;

							}
						continue;
					case	0xe :
						/* P */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_P += 1;
							_Context->value_P &= 1;
				visual_switch(218,68,24,16,1,12,15,"P",1,(_Context->value_P |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_P_event()) != -1) break;

							}
						continue;
					case	0xf :
						/* IMG */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IMG += 1;
							_Context->value_IMG &= 1;
				visual_switch(358,68,32,16,1,12,15,"IMG",3,(_Context->value_IMG |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_IMG_event()) != -1) break;

							}
						continue;
					case	0x10 :
						/* DIV */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_DIV += 1;
							_Context->value_DIV &= 1;
				visual_switch(386,68,32,16,1,12,15,"DIV",3,(_Context->value_DIV |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_DIV_event()) != -1) break;

							}
						continue;
					case	0x11 :
						/* TABLE */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_TABLE += 1;
							_Context->value_TABLE &= 1;
				visual_switch(414,68,48,16,1,12,15,"TABLE",5,(_Context->value_TABLE |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_TABLE_event()) != -1) break;

							}
						continue;
					case	0x12 :
						/* TR */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_TR += 1;
							_Context->value_TR &= 1;
				visual_switch(458,68,24,16,1,12,15,"TR",2,(_Context->value_TR |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_TR_event()) != -1) break;

							}
						continue;
					case	0x13 :
						/* TH */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_TH += 1;
							_Context->value_TH &= 1;
				visual_switch(478,68,24,16,1,12,15,"TH",2,(_Context->value_TH |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_TH_event()) != -1) break;

							}
						continue;
					case	0x14 :
						/* TD */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_TD += 1;
							_Context->value_TD &= 1;
				visual_switch(498,68,24,16,1,12,15,"TD",2,(_Context->value_TD |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_TD_event()) != -1) break;

							}
						continue;
					case	0x15 :
						/* H1 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_H1 += 1;
							_Context->value_H1 &= 1;
				visual_switch(518,68,24,16,1,12,15,"H1",2,(_Context->value_H1 |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_H1_event()) != -1) break;

							}
						continue;
					case	0x16 :
						/* H2 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_H2 += 1;
							_Context->value_H2 &= 1;
				visual_switch(538,68,24,16,1,12,15,"H2",2,(_Context->value_H2 |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_H2_event()) != -1) break;

							}
						continue;
					case	0x17 :
						/* H3 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_H3 += 1;
							_Context->value_H3 &= 1;
				visual_switch(558,68,24,16,1,12,15,"H3",2,(_Context->value_H3 |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_H3_event()) != -1) break;

							}
						continue;
					case	0x18 :
						/* H4 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_H4 += 1;
							_Context->value_H4 &= 1;
				visual_switch(578,68,24,16,1,12,15,"H4",2,(_Context->value_H4 |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_H4_event()) != -1) break;

							}
						continue;
					case	0x19 :
						/* H5 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_H5 += 1;
							_Context->value_H5 &= 1;
				visual_switch(598,68,24,16,1,12,15,"H5",2,(_Context->value_H5 |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_H5_event()) != -1) break;

							}
						continue;
					case	0x1a :
						/* H6 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_H6 += 1;
							_Context->value_H6 &= 1;
				visual_switch(618,68,24,16,1,12,15,"H6",2,(_Context->value_H6 |0));
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_H6_event()) != -1) break;

							}
						continue;
					case	0x1b :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(646,460,70,32,2,26,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(646,460,70,32,2,26,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x1c :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(646,498,70,32,2,26,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(646,498,70,32,2,26,0,"&Cancel",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0x1d :
						/* Body */
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
				_Context->focus_item=29;
			}
			continue;
		case 0x841 : 
		case 0x861 : 
		/* Accept */
		visual_button(646,460,70,32,2,26,0,"&Accept",7,8);
		visual_button(646,460,70,32,2,26,0,"&Accept",7,0);
		_Context->focus_item=27;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(646,498,70,32,2,26,0,"&Cancel",7,8);
		visual_button(646,498,70,32,2,26,0,"&Cancel",7,0);
		_Context->focus_item=28;
		if ((_Context->keycode = on_Cancel_event()) != -1) break;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	visual_text_editor(
	char * pB,
	char * pI,
	char * pU,
	char * pHREF,
	char * pHR,
	char * pBR,
	char * pOL,
	char * pUL,
	char * pLI,
	char * pDL,
	char * pDT,
	char * pDD,
	char * pP,
	char * pIMG,
	char * pDIV,
	char * pTABLE,
	char * pTR,
	char * pTH,
	char * pTD,
	char * pH1,
	char * pH2,
	char * pH3,
	char * pH4,
	char * pH5,
	char * pH6,
	char * pBody)
{
	int	status=0;
	status = visual_text_editor_create(
	 pB,
	 pI,
	 pU,
	 pHREF,
	 pHR,
	 pBR,
	 pOL,
	 pUL,
	 pLI,
	 pDL,
	 pDT,
	 pDD,
	 pP,
	 pIMG,
	 pDIV,
	 pTABLE,
	 pTR,
	 pTH,
	 pTD,
	 pH1,
	 pH2,
	 pH3,
	 pH4,
	 pH5,
	 pH6,
	 pBody);
	if ( status != 0) return(status);
	status = visual_text_editor_show();
		enter_modal();
	status = visual_text_editor_focus();
		leave_modal();
	status = visual_text_editor_hide();
	status = visual_text_editor_remove(
	 pB,
	 pI,
	 pU,
	 pHREF,
	 pHR,
	 pBR,
	 pOL,
	 pUL,
	 pLI,
	 pDL,
	 pDT,
	 pDD,
	 pP,
	 pIMG,
	 pDIV,
	 pTABLE,
	 pTR,
	 pTH,
	 pTD,
	 pH1,
	 pH2,
	 pH3,
	 pH4,
	 pH5,
	 pH6,
	 pBody);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _veditor_c */
