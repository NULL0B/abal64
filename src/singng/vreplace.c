
#ifndef _vreplace_c
#define _vreplace_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vreplace.xml                                             */
/* Target         : vreplace.c                                               */
/* Identification : 0.0-1177511936-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto2756   ""
#define fr__Auto2756   ""
#define it__Auto2756   ""
#define es__Auto2756   ""
#define de__Auto2756   ""
#define nl__Auto2756   ""
#define pt__Auto2756   ""
#define xx__Auto2756   ""
#define en_Auto2757   "Locate Text"
#define fr_Auto2757   "Rechercher"
#define it_Auto2757   "Locate Text"
#define es_Auto2757   "Locate Text"
#define de_Auto2757   "Sucher Text"
#define nl_Auto2757   "Locate Text"
#define pt_Auto2757   "Locate Text"
#define xx_Auto2757   "Locate Text"
#define en_Auto2758   "Replace With"
#define fr_Auto2758   "Remplacer"
#define it_Auto2758   "Replace With"
#define es_Auto2758   "Replace With"
#define de_Auto2758   "Replace With"
#define nl_Auto2758   "Replace With"
#define pt_Auto2758   "Replace With"
#define xx_Auto2758   "Replace With"
#define en_Criteria   ""
#define en_Replace   ""
#define en_IgnoreCase   "&Ignore Case"
#define fr_IgnoreCase   "&Ignorer la casse"
#define it_IgnoreCase   "&Ignore Case"
#define es_IgnoreCase   "&Ignore Case"
#define de_IgnoreCase   "&Ignore Case"
#define nl_IgnoreCase   "&Ignore Case"
#define pt_IgnoreCase   "&Ignore Case"
#define xx_IgnoreCase   "&Ignore Case"
#define en_ReverseSearch   "&Reverse Search"
#define fr_ReverseSearch   "&Rechercher en arriŠre"
#define it_ReverseSearch   "&Reverse Search"
#define es_ReverseSearch   "&Reverse Search"
#define de_ReverseSearch   "&Reverse Search"
#define nl_ReverseSearch   "&Reverse Search"
#define pt_ReverseSearch   "&Reverse Search"
#define xx_ReverseSearch   "&Reverse Search"
#define en_ReplaceAll   "Replace &All"
#define fr_ReplaceAll   "&Remplacer tout"
#define it_ReplaceAll   "Replace &All"
#define es_ReplaceAll   "Replace &All"
#define de_ReplaceAll   "Replace &All"
#define nl_ReplaceAll   "Replace &All"
#define pt_ReplaceAll   "Replace &All"
#define xx_ReplaceAll   "Replace &All"
#define en_DoReplace   "Re&place"
#define fr_DoReplace   "&Remplacer"
#define it_DoReplace   "Re&place"
#define es_DoReplace   "Re&place"
#define de_DoReplace   "Re&place"
#define nl_DoReplace   "Re&place"
#define pt_DoReplace   "Re&place"
#define xx_DoReplace   "Re&place"
#define en_Quit   "&Quit"
#define fr_Quit   "&Quitter"
#define it_Quit   "&Quit"
#define es_Quit   "&Abandonar"
#define de_Quit   "&Ausgang"
#define nl_Quit   "&Quit"
#define pt_Quit   "&Quit"
#define xx_Quit   "&Quit"

private struct accept_replace_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2756[8];
	char * hint_Auto2756[8];
	int	x_Auto2756;
	int	y_Auto2756;
	int	w_Auto2756;
	int	h_Auto2756;
	char * msg_Auto2757[8];
	char * hint_Auto2757[8];
	char * msg_Auto2758[8];
	char * hint_Auto2758[8];
	char * hint_Criteria[8];
	char	buffer_Criteria[256];
	char * hint_Replace[8];
	char	buffer_Replace[256];
	char * msg_IgnoreCase[8];
	int	trigger_IgnoreCase;
	char * hint_IgnoreCase[8];
	int	value_IgnoreCase;
	char * msg_ReverseSearch[8];
	int	trigger_ReverseSearch;
	char * hint_ReverseSearch[8];
	int	value_ReverseSearch;
	char * msg_ReplaceAll[8];
	int	trigger_ReplaceAll;
	char * hint_ReplaceAll[8];
	int	value_ReplaceAll;
	char * msg_DoReplace[8];
	int	trigger_DoReplace;
	char * hint_DoReplace[8];
	char * msg_Quit[8];
	int	trigger_Quit;
	char * hint_Quit[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[6];
	};
static int	vfh[16];

public	int	accept_replace_create(
	struct accept_replace_context ** cptr,
	char * pCriteria,
	char * pReplace,
	char * pIgnoreCase,
	char * pReverseSearch,
	char * pReplaceAll)
{

	int i;
	struct accept_replace_context * _Context=(struct accept_replace_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_replace_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=8;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Criteria, 255, pCriteria);
		visual_transferin(_Context->buffer_Replace, 255, pReplace);
		visual_transferin((void *) 0, 0, pIgnoreCase);
		if (!( pIgnoreCase )) _Context->value_IgnoreCase=0;
		else	_Context->value_IgnoreCase = *((int *)pIgnoreCase);
		visual_transferin((void *) 0, 0, pReverseSearch);
		if (!( pReverseSearch )) _Context->value_ReverseSearch=0;
		else	_Context->value_ReverseSearch = *((int *)pReverseSearch);
		visual_transferin((void *) 0, 0, pReplaceAll);
		if (!( pReplaceAll )) _Context->value_ReplaceAll=0;
		else	_Context->value_ReplaceAll = *((int *)pReplaceAll);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto2756[i]=" ";
	_Context->hint_Auto2756[0]=en__Auto2756;
	_Context->hint_Auto2756[1]=fr__Auto2756;
	_Context->hint_Auto2756[2]=it__Auto2756;
	_Context->hint_Auto2756[3]=es__Auto2756;
	_Context->hint_Auto2756[4]=de__Auto2756;
	_Context->hint_Auto2756[5]=nl__Auto2756;
	_Context->hint_Auto2756[6]=pt__Auto2756;
	_Context->hint_Auto2756[7]=xx__Auto2756;
	_Context->x_Auto2756=95;
	_Context->y_Auto2756=250;
	_Context->w_Auto2756=610;
	_Context->h_Auto2756=100;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2757[i]=" ";
	_Context->msg_Auto2757[0]=en_Auto2757;
	_Context->msg_Auto2757[1]=fr_Auto2757;
	_Context->msg_Auto2757[2]=it_Auto2757;
	_Context->msg_Auto2757[3]=es_Auto2757;
	_Context->msg_Auto2757[4]=de_Auto2757;
	_Context->msg_Auto2757[5]=nl_Auto2757;
	_Context->msg_Auto2757[6]=pt_Auto2757;
	_Context->msg_Auto2757[7]=xx_Auto2757;
	for (i=0; i < 8; i++)_Context->msg_Auto2758[i]=" ";
	_Context->msg_Auto2758[0]=en_Auto2758;
	_Context->msg_Auto2758[1]=fr_Auto2758;
	_Context->msg_Auto2758[2]=it_Auto2758;
	_Context->msg_Auto2758[3]=es_Auto2758;
	_Context->msg_Auto2758[4]=de_Auto2758;
	_Context->msg_Auto2758[5]=nl_Auto2758;
	_Context->msg_Auto2758[6]=pt_Auto2758;
	_Context->msg_Auto2758[7]=xx_Auto2758;
	for (i=0; i < 8; i++)_Context->msg_IgnoreCase[i]=" ";
	_Context->msg_IgnoreCase[0]=en_IgnoreCase;
	_Context->msg_IgnoreCase[1]=fr_IgnoreCase;
	_Context->msg_IgnoreCase[2]=it_IgnoreCase;
	_Context->msg_IgnoreCase[3]=es_IgnoreCase;
	_Context->msg_IgnoreCase[4]=de_IgnoreCase;
	_Context->msg_IgnoreCase[5]=nl_IgnoreCase;
	_Context->msg_IgnoreCase[6]=pt_IgnoreCase;
	_Context->msg_IgnoreCase[7]=xx_IgnoreCase;
	for (i=0; i < 8; i++)_Context->msg_ReverseSearch[i]=" ";
	_Context->msg_ReverseSearch[0]=en_ReverseSearch;
	_Context->msg_ReverseSearch[1]=fr_ReverseSearch;
	_Context->msg_ReverseSearch[2]=it_ReverseSearch;
	_Context->msg_ReverseSearch[3]=es_ReverseSearch;
	_Context->msg_ReverseSearch[4]=de_ReverseSearch;
	_Context->msg_ReverseSearch[5]=nl_ReverseSearch;
	_Context->msg_ReverseSearch[6]=pt_ReverseSearch;
	_Context->msg_ReverseSearch[7]=xx_ReverseSearch;
	for (i=0; i < 8; i++)_Context->msg_ReplaceAll[i]=" ";
	_Context->msg_ReplaceAll[0]=en_ReplaceAll;
	_Context->msg_ReplaceAll[1]=fr_ReplaceAll;
	_Context->msg_ReplaceAll[2]=it_ReplaceAll;
	_Context->msg_ReplaceAll[3]=es_ReplaceAll;
	_Context->msg_ReplaceAll[4]=de_ReplaceAll;
	_Context->msg_ReplaceAll[5]=nl_ReplaceAll;
	_Context->msg_ReplaceAll[6]=pt_ReplaceAll;
	_Context->msg_ReplaceAll[7]=xx_ReplaceAll;
	for (i=0; i < 8; i++)_Context->msg_DoReplace[i]=" ";
	_Context->msg_DoReplace[0]=en_DoReplace;
	_Context->msg_DoReplace[1]=fr_DoReplace;
	_Context->msg_DoReplace[2]=it_DoReplace;
	_Context->msg_DoReplace[3]=es_DoReplace;
	_Context->msg_DoReplace[4]=de_DoReplace;
	_Context->msg_DoReplace[5]=nl_DoReplace;
	_Context->msg_DoReplace[6]=pt_DoReplace;
	_Context->msg_DoReplace[7]=xx_DoReplace;
	for (i=0; i < 8; i++)_Context->msg_Quit[i]=" ";
	_Context->msg_Quit[0]=en_Quit;
	_Context->msg_Quit[1]=fr_Quit;
	_Context->msg_Quit[2]=it_Quit;
	_Context->msg_Quit[3]=es_Quit;
	_Context->msg_Quit[4]=de_Quit;
	_Context->msg_Quit[5]=nl_Quit;
	_Context->msg_Quit[6]=pt_Quit;
	_Context->msg_Quit[7]=xx_Quit;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2756,_Context->y_Auto2756,610+10,100+10);
	return(0);
}

public 	int	accept_replace_hide(struct accept_replace_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2756,_Context->y_Auto2756);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_replace_remove(
	struct accept_replace_context * _Context,
	char * pCriteria,
	char * pReplace,
	char * pIgnoreCase,
	char * pReverseSearch,
	char * pReplaceAll)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Criteria, 255, pCriteria);
		visual_transferout(_Context->buffer_Replace, 255, pReplace);
		visual_transferout((void *) 0, 0, pIgnoreCase);
		if ( pIgnoreCase != (char *) 0)
			*((int*)pIgnoreCase) = _Context->value_IgnoreCase;
		visual_transferout((void *) 0, 0, pReverseSearch);
		if ( pReverseSearch != (char *) 0)
			*((int*)pReverseSearch) = _Context->value_ReverseSearch;
		visual_transferout((void *) 0, 0, pReplaceAll);
		if ( pReplaceAll != (char *) 0)
			*((int*)pReplaceAll) = _Context->value_ReplaceAll;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_replace_show(struct accept_replace_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2756,_Context->y_Auto2756);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto2756,_Context->y_Auto2756,610,100,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto2756,_Context->y_Auto2756,610,100,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto2756+10,_Context->y_Auto2756+30,84,16,vfh[2],27,0,_Context->msg_Auto2757[_Context->language],strlen(_Context->msg_Auto2757[_Context->language]),771);
	visual_text(_Context->x_Auto2756+10,_Context->y_Auto2756+50,84,16,vfh[2],27,0,_Context->msg_Auto2758[_Context->language],strlen(_Context->msg_Auto2758[_Context->language]),771);
	visual_frame(_Context->x_Auto2756+100,_Context->y_Auto2756+30,424+2,16+2,5);
	visual_text(_Context->x_Auto2756+100+1,_Context->y_Auto2756+30+1,424,16,vfh[1],16,22,_Context->buffer_Criteria,255,0);
	visual_frame(_Context->x_Auto2756+100,_Context->y_Auto2756+50,424+2,16+2,5);
	visual_text(_Context->x_Auto2756+100+1,_Context->y_Auto2756+50+1,424,16,vfh[1],27,0,_Context->buffer_Replace,255,0);
	_Context->trigger_IgnoreCase=visual_trigger_code(_Context->msg_IgnoreCase[_Context->language],strlen(_Context->msg_IgnoreCase[_Context->language]));
	visual_check(_Context->x_Auto2756+100,_Context->y_Auto2756+70,140,16,vfh[2],16,22,_Context->msg_IgnoreCase[_Context->language],strlen(_Context->msg_IgnoreCase[_Context->language]),_Context->value_IgnoreCase|0);
	_Context->trigger_ReverseSearch=visual_trigger_code(_Context->msg_ReverseSearch[_Context->language],strlen(_Context->msg_ReverseSearch[_Context->language]));
	visual_check(_Context->x_Auto2756+240,_Context->y_Auto2756+70,168,16,vfh[2],16,22,_Context->msg_ReverseSearch[_Context->language],strlen(_Context->msg_ReverseSearch[_Context->language]),_Context->value_ReverseSearch|0);
	_Context->trigger_ReplaceAll=visual_trigger_code(_Context->msg_ReplaceAll[_Context->language],strlen(_Context->msg_ReplaceAll[_Context->language]));
	visual_check(_Context->x_Auto2756+420,_Context->y_Auto2756+70,154,16,vfh[2],27,0,_Context->msg_ReplaceAll[_Context->language],strlen(_Context->msg_ReplaceAll[_Context->language]),_Context->value_ReplaceAll|0);
	_Context->trigger_DoReplace=visual_trigger_code(_Context->msg_DoReplace[_Context->language],strlen(_Context->msg_DoReplace[_Context->language]));
	visual_button(_Context->x_Auto2756+530,_Context->y_Auto2756+30,68,16,vfh[8],16,22,_Context->msg_DoReplace[_Context->language],strlen(_Context->msg_DoReplace[_Context->language]),0);
	_Context->trigger_Quit=visual_trigger_code(_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]));
	visual_button(_Context->x_Auto2756+530,_Context->y_Auto2756+50,70,20,vfh[8],16,22,_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]),0);
	visual_thaw(_Context->x_Auto2756,_Context->y_Auto2756,610,100);

	return(0);
}

private int Criteria_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This edit field allows the search pattern to be specified.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Replace_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This edit field allows the search pattern to be specified.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IgnoreCase_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this control is active the search and replace operation will ";
			mptr[1]="ignore the case of the search expression, otherwise the exact case ";
			mptr[2]="of the search expression will be respected.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ReverseSearch_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this control is active the search and replace operations  will ";
			mptr[1]="occur towards the start of the file otherwise it will proceed towards ";
			mptr[2]="the end of the file.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ReplaceAll_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this control is active the search and replace operation will ";
			mptr[1]="be performed in the required direction for all occurance encountered ";
			mptr[2]="up to the end or start  of the file.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DoReplace_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The editior search and replace operation will be launched or repeated ";
			mptr[1]="by  clicking on this button.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Quit_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This button allows the current search and replace operation to be ";
			mptr[1]="abandoned.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2756action(struct accept_replace_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_replace_hide(_Context);

		_Context->x_Auto2756 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2756 < 0) { _Context->x_Auto2756=0; }
		_Context->y_Auto2756 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2756 < 0) { _Context->y_Auto2756=0; }
			accept_replace_show(_Context);

		visual_thaw(_Context->x_Auto2756,_Context->y_Auto2756,610,100);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_DoReplace_event(struct accept_replace_context * _Context) {
		accept_replace_hide(_Context);
;
	EditorTextReplace(_Context->buffer_Criteria,255,
	_Context->buffer_Replace,255,
	_Context->value_IgnoreCase,
	_Context->value_ReverseSearch,
	_Context->value_ReplaceAll);
		accept_replace_show(_Context);
;
	return(-1);
}
private int on_Quit_event(struct accept_replace_context * _Context) {
	return(13);
	return(-1);
}


public	int	accept_replace_event(
struct accept_replace_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IgnoreCase == mb ) return(4);
		if (_Context->trigger_ReverseSearch == mb ) return(5);
		if (_Context->trigger_ReplaceAll == mb ) return(6);
		if (_Context->trigger_DoReplace == mb ) return(7);
		if (_Context->trigger_Quit == mb ) return(8);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2756+589) )  
	&&  (my >= (_Context->y_Auto2756+4) )  
	&&  (mx <= (_Context->x_Auto2756+606) )  
	&&  (my <= (_Context->y_Auto2756+20) )) {
		return(1);	/* Auto2756 */

		}
	if ((mx >= (_Context->x_Auto2756+573) )  
	&&  (my >= (_Context->y_Auto2756+4) )  
	&&  (mx <= (_Context->x_Auto2756+590) )  
	&&  (my <= (_Context->y_Auto2756+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vreplace.htm");
			};
		return(-1);	/* Auto2756 */

		}
	if ((mx >= (_Context->x_Auto2756+557) )  
	&&  (my >= (_Context->y_Auto2756+4) )  
	&&  (mx <= (_Context->x_Auto2756+574) )  
	&&  (my <= (_Context->y_Auto2756+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_replace_show(_Context);
		return(-1);	/* Auto2756 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2756+4) )  
		&&  (my >= (_Context->y_Auto2756+4) )  
		&&  (mx <= (_Context->x_Auto2756+542) )  
		&&  (my <= (_Context->y_Auto2756+20) )) {
			return( Auto2756action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto2756+100) ) 
	&&  ( my >= (_Context->y_Auto2756+30) ) 
	&&  ( mx <= (_Context->x_Auto2756+100+424) ) 
	&&  ( my <= (_Context->y_Auto2756+30+16))) {
		return(2); /* Criteria */
		}
	if (( mx >= (_Context->x_Auto2756+100) ) 
	&&  ( my >= (_Context->y_Auto2756+50) ) 
	&&  ( mx <= (_Context->x_Auto2756+100+424) ) 
	&&  ( my <= (_Context->y_Auto2756+50+16))) {
		return(3); /* Replace */
		}
	if (( mx >= (_Context->x_Auto2756+100) ) 
	&&  ( my >= (_Context->y_Auto2756+70) ) 
	&&  ( mx <= (_Context->x_Auto2756+100+140) ) 
	&&  ( my <= (_Context->y_Auto2756+70+16))) {
		return(4); /* IgnoreCase */
		}
	if (( mx >= (_Context->x_Auto2756+240) ) 
	&&  ( my >= (_Context->y_Auto2756+70) ) 
	&&  ( mx <= (_Context->x_Auto2756+240+168) ) 
	&&  ( my <= (_Context->y_Auto2756+70+16))) {
		return(5); /* ReverseSearch */
		}
	if (( mx >= (_Context->x_Auto2756+420) ) 
	&&  ( my >= (_Context->y_Auto2756+70) ) 
	&&  ( mx <= (_Context->x_Auto2756+420+154) ) 
	&&  ( my <= (_Context->y_Auto2756+70+16))) {
		return(6); /* ReplaceAll */
		}
	if (( mx >= (_Context->x_Auto2756+530) ) 
	&&  ( my >= (_Context->y_Auto2756+30) ) 
	&&  ( mx <= (_Context->x_Auto2756+530+68) ) 
	&&  ( my <= (_Context->y_Auto2756+30+16))) {
		return(7); /* DoReplace */
		}
	if (( mx >= (_Context->x_Auto2756+530) ) 
	&&  ( my >= (_Context->y_Auto2756+50) ) 
	&&  ( mx <= (_Context->x_Auto2756+530+70) ) 
	&&  ( my <= (_Context->y_Auto2756+50+20))) {
		return(8); /* Quit */
		}

	return(-1);
}


public	int	accept_replace_focus(struct accept_replace_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Criteria */
				_Context->keycode = visual_edit(_Context->x_Auto2756+100+1,_Context->y_Auto2756+30+1,424,16,vfh[1],_Context->buffer_Criteria,255);
				if(_Context->keycode==13){
				on_DoReplace_event(_Context);
				_Context->keycode=0;
				}
			break;
			case	0x3 :
				/* Replace */
				_Context->keycode = visual_edit(_Context->x_Auto2756+100+1,_Context->y_Auto2756+50+1,424,16,vfh[1],_Context->buffer_Replace,255);
				if(_Context->keycode==13){
				on_DoReplace_event(_Context);
				_Context->keycode=0;
				}
			break;
			case	0x4 :
				/* IgnoreCase */
				visual_check(_Context->x_Auto2756+100,_Context->y_Auto2756+70,140,16,vfh[2],16,22,_Context->msg_IgnoreCase[_Context->language],strlen(_Context->msg_IgnoreCase[_Context->language]),(_Context->value_IgnoreCase |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IgnoreCase=visual_trigger_code(_Context->msg_IgnoreCase[_Context->language],strlen(_Context->msg_IgnoreCase[_Context->language]));
	visual_check(_Context->x_Auto2756+100,_Context->y_Auto2756+70,140,16,vfh[2],16,22,_Context->msg_IgnoreCase[_Context->language],strlen(_Context->msg_IgnoreCase[_Context->language]),_Context->value_IgnoreCase|0);
				break;
			case	0x5 :
				/* ReverseSearch */
				visual_check(_Context->x_Auto2756+240,_Context->y_Auto2756+70,168,16,vfh[2],16,22,_Context->msg_ReverseSearch[_Context->language],strlen(_Context->msg_ReverseSearch[_Context->language]),(_Context->value_ReverseSearch |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ReverseSearch=visual_trigger_code(_Context->msg_ReverseSearch[_Context->language],strlen(_Context->msg_ReverseSearch[_Context->language]));
	visual_check(_Context->x_Auto2756+240,_Context->y_Auto2756+70,168,16,vfh[2],16,22,_Context->msg_ReverseSearch[_Context->language],strlen(_Context->msg_ReverseSearch[_Context->language]),_Context->value_ReverseSearch|0);
				break;
			case	0x6 :
				/* ReplaceAll */
				visual_check(_Context->x_Auto2756+420,_Context->y_Auto2756+70,154,16,vfh[2],27,0,_Context->msg_ReplaceAll[_Context->language],strlen(_Context->msg_ReplaceAll[_Context->language]),(_Context->value_ReplaceAll |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ReplaceAll=visual_trigger_code(_Context->msg_ReplaceAll[_Context->language],strlen(_Context->msg_ReplaceAll[_Context->language]));
	visual_check(_Context->x_Auto2756+420,_Context->y_Auto2756+70,154,16,vfh[2],27,0,_Context->msg_ReplaceAll[_Context->language],strlen(_Context->msg_ReplaceAll[_Context->language]),_Context->value_ReplaceAll|0);
				break;
			case	0x7 :
				/* DoReplace */
				_Context->trigger_DoReplace=visual_trigger_code(_Context->msg_DoReplace[_Context->language],strlen(_Context->msg_DoReplace[_Context->language]));
				visual_button(_Context->x_Auto2756+530,_Context->y_Auto2756+30,68,16,vfh[8],16,22,_Context->msg_DoReplace[_Context->language],strlen(_Context->msg_DoReplace[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_DoReplace=visual_trigger_code(_Context->msg_DoReplace[_Context->language],strlen(_Context->msg_DoReplace[_Context->language]));
	visual_button(_Context->x_Auto2756+530,_Context->y_Auto2756+30,68,16,vfh[8],16,22,_Context->msg_DoReplace[_Context->language],strlen(_Context->msg_DoReplace[_Context->language]),0);
				break;
			case	0x8 :
				/* Quit */
				_Context->trigger_Quit=visual_trigger_code(_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]));
				visual_button(_Context->x_Auto2756+530,_Context->y_Auto2756+50,70,20,vfh[8],16,22,_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Quit=visual_trigger_code(_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]));
	visual_button(_Context->x_Auto2756+530,_Context->y_Auto2756+50,70,20,vfh[8],16,22,_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_replace_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=8;
			accept_replace_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_replace_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (Criteria_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Replace_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (IgnoreCase_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (ReverseSearch_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (ReplaceAll_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (DoReplace_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (Quit_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2756 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Criteria */
					continue;
				case	0x3 :
					/* Replace */
					continue;
				case	0x4 :
					/* IgnoreCase */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IgnoreCase += 1;
						_Context->value_IgnoreCase &= 1;
						}
					continue;
				case	0x5 :
					/* ReverseSearch */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ReverseSearch += 1;
						_Context->value_ReverseSearch &= 1;
						}
					continue;
				case	0x6 :
					/* ReplaceAll */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ReplaceAll += 1;
						_Context->value_ReplaceAll &= 1;
						}
					continue;
				case	0x7 :
					/* DoReplace */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_DoReplace=visual_trigger_code(_Context->msg_DoReplace[_Context->language],strlen(_Context->msg_DoReplace[_Context->language]));
						visual_button(_Context->x_Auto2756+530,_Context->y_Auto2756+30,68,16,vfh[8],16,22,_Context->msg_DoReplace[_Context->language],strlen(_Context->msg_DoReplace[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_DoReplace=visual_trigger_code(_Context->msg_DoReplace[_Context->language],strlen(_Context->msg_DoReplace[_Context->language]));
	visual_button(_Context->x_Auto2756+530,_Context->y_Auto2756+30,68,16,vfh[8],16,22,_Context->msg_DoReplace[_Context->language],strlen(_Context->msg_DoReplace[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_DoReplace_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Quit */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Quit=visual_trigger_code(_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]));
						visual_button(_Context->x_Auto2756+530,_Context->y_Auto2756+50,70,20,vfh[8],16,22,_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Quit=visual_trigger_code(_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]));
	visual_button(_Context->x_Auto2756+530,_Context->y_Auto2756+50,70,20,vfh[8],16,22,_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Quit_event(_Context)) != -1) break;

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

public	int	accept_replace(
	char * pCriteria,
	char * pReplace,
	char * pIgnoreCase,
	char * pReverseSearch,
	char * pReplaceAll)
{
	int	status=0;
	struct accept_replace_context * _Context=(struct accept_replace_context*) 0;
	status = accept_replace_create(
	&_Context,
	 pCriteria,
	 pReplace,
	 pIgnoreCase,
	 pReverseSearch,
	 pReplaceAll);
	if ( status != 0) return(status);
	status = accept_replace_show(_Context);
		enter_modal();
	status = accept_replace_focus(_Context);
		leave_modal();
	status = accept_replace_hide(_Context);
	status = accept_replace_remove(
	_Context,
	 pCriteria,
	 pReplace,
	 pIgnoreCase,
	 pReverseSearch,
	 pReplaceAll);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vreplace_c */
