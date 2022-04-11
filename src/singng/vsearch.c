
#ifndef _vsearch_c
#define _vsearch_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vsearch.xml                                              */
/* Target         : vsearch.c                                                */
/* Identification : 0.0-1177511936-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto2759   ""
#define fr__Auto2759   ""
#define it__Auto2759   ""
#define es__Auto2759   ""
#define de__Auto2759   ""
#define nl__Auto2759   ""
#define pt__Auto2759   ""
#define xx__Auto2759   ""
#define en_Auto2760   "Locate Text"
#define fr_Auto2760   "Rechercher"
#define it_Auto2760   "Locate Text"
#define es_Auto2760   "Locate Text"
#define de_Auto2760   "Locate Text"
#define nl_Auto2760   "Locate Text"
#define pt_Auto2760   "Locate Text"
#define xx_Auto2760   "Locate Text"
#define en_Criteria   ""
#define en_IgnoreCase   "&Ignore Case"
#define fr_IgnoreCase   "&Ignore la casse"
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
#define en_DoFind   "&Find"
#define fr_DoFind   "&Rechercher"
#define it_DoFind   "&Find"
#define es_DoFind   "&Find"
#define de_DoFind   "&Find"
#define nl_DoFind   "&Find"
#define pt_DoFind   "&Find"
#define xx_DoFind   "&Find"
#define en_Quit   "&Quit"
#define fr_Quit   "&Quitter"
#define it_Quit   "&Quit"
#define es_Quit   "&Abandonar"
#define de_Quit   "&Ausgang"
#define nl_Quit   "&Quit"
#define pt_Quit   "&Quit"
#define xx_Quit   "&Quit"

private struct accept_search_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2759[8];
	char * hint_Auto2759[8];
	int	x_Auto2759;
	int	y_Auto2759;
	int	w_Auto2759;
	int	h_Auto2759;
	char * msg_Auto2760[8];
	char * hint_Auto2760[8];
	char * hint_Criteria[8];
	char	buffer_Criteria[256];
	char * msg_IgnoreCase[8];
	int	trigger_IgnoreCase;
	char * hint_IgnoreCase[8];
	int	value_IgnoreCase;
	char * msg_ReverseSearch[8];
	int	trigger_ReverseSearch;
	char * hint_ReverseSearch[8];
	int	value_ReverseSearch;
	char * msg_DoFind[8];
	int	trigger_DoFind;
	char * hint_DoFind[8];
	char * msg_Quit[8];
	int	trigger_Quit;
	char * hint_Quit[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[4];
	};
static int	vfh[16];

public	int	accept_search_create(
	struct accept_search_context ** cptr,
	char * pCriteria,
	char * pIgnoreCase,
	char * pReverseSearch)
{

	int i;
	struct accept_search_context * _Context=(struct accept_search_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_search_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Criteria, 255, pCriteria);
		visual_transferin((void *) 0, 0, pIgnoreCase);
		if (!( pIgnoreCase )) _Context->value_IgnoreCase=0;
		else	_Context->value_IgnoreCase = *((int *)pIgnoreCase);
		visual_transferin((void *) 0, 0, pReverseSearch);
		if (!( pReverseSearch )) _Context->value_ReverseSearch=0;
		else	_Context->value_ReverseSearch = *((int *)pReverseSearch);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto2759[i]=" ";
	_Context->hint_Auto2759[0]=en__Auto2759;
	_Context->hint_Auto2759[1]=fr__Auto2759;
	_Context->hint_Auto2759[2]=it__Auto2759;
	_Context->hint_Auto2759[3]=es__Auto2759;
	_Context->hint_Auto2759[4]=de__Auto2759;
	_Context->hint_Auto2759[5]=nl__Auto2759;
	_Context->hint_Auto2759[6]=pt__Auto2759;
	_Context->hint_Auto2759[7]=xx__Auto2759;
	_Context->x_Auto2759=95;
	_Context->y_Auto2759=260;
	_Context->w_Auto2759=610;
	_Context->h_Auto2759=80;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2760[i]=" ";
	_Context->msg_Auto2760[0]=en_Auto2760;
	_Context->msg_Auto2760[1]=fr_Auto2760;
	_Context->msg_Auto2760[2]=it_Auto2760;
	_Context->msg_Auto2760[3]=es_Auto2760;
	_Context->msg_Auto2760[4]=de_Auto2760;
	_Context->msg_Auto2760[5]=nl_Auto2760;
	_Context->msg_Auto2760[6]=pt_Auto2760;
	_Context->msg_Auto2760[7]=xx_Auto2760;
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
	for (i=0; i < 8; i++)_Context->msg_DoFind[i]=" ";
	_Context->msg_DoFind[0]=en_DoFind;
	_Context->msg_DoFind[1]=fr_DoFind;
	_Context->msg_DoFind[2]=it_DoFind;
	_Context->msg_DoFind[3]=es_DoFind;
	_Context->msg_DoFind[4]=de_DoFind;
	_Context->msg_DoFind[5]=nl_DoFind;
	_Context->msg_DoFind[6]=pt_DoFind;
	_Context->msg_DoFind[7]=xx_DoFind;
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
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2759,_Context->y_Auto2759,610+10,80+10);
	return(0);
}

public 	int	accept_search_hide(struct accept_search_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2759,_Context->y_Auto2759);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_search_remove(
	struct accept_search_context * _Context,
	char * pCriteria,
	char * pIgnoreCase,
	char * pReverseSearch)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Criteria, 255, pCriteria);
		visual_transferout((void *) 0, 0, pIgnoreCase);
		if ( pIgnoreCase != (char *) 0)
			*((int*)pIgnoreCase) = _Context->value_IgnoreCase;
		visual_transferout((void *) 0, 0, pReverseSearch);
		if ( pReverseSearch != (char *) 0)
			*((int*)pReverseSearch) = _Context->value_ReverseSearch;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_search_show(struct accept_search_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2759,_Context->y_Auto2759);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto2759,_Context->y_Auto2759,610,80,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto2759,_Context->y_Auto2759,610,80,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto2759+20,_Context->y_Auto2759+30,570,20,vfh[2],27,0,_Context->msg_Auto2760[_Context->language],strlen(_Context->msg_Auto2760[_Context->language]),1282);
	visual_frame(_Context->x_Auto2759+100,_Context->y_Auto2759+30,424+2,16+2,5);
	visual_text(_Context->x_Auto2759+100+1,_Context->y_Auto2759+30+1,424,16,vfh[1],16,22,_Context->buffer_Criteria,255,0);
	_Context->trigger_IgnoreCase=visual_trigger_code(_Context->msg_IgnoreCase[_Context->language],strlen(_Context->msg_IgnoreCase[_Context->language]));
	visual_check(_Context->x_Auto2759+90,_Context->y_Auto2759+50,154,16,vfh[2],16,22,_Context->msg_IgnoreCase[_Context->language],strlen(_Context->msg_IgnoreCase[_Context->language]),_Context->value_IgnoreCase|0);
	_Context->trigger_ReverseSearch=visual_trigger_code(_Context->msg_ReverseSearch[_Context->language],strlen(_Context->msg_ReverseSearch[_Context->language]));
	visual_check(_Context->x_Auto2759+250,_Context->y_Auto2759+50,168,16,vfh[2],16,22,_Context->msg_ReverseSearch[_Context->language],strlen(_Context->msg_ReverseSearch[_Context->language]),_Context->value_ReverseSearch|0);
	_Context->trigger_DoFind=visual_trigger_code(_Context->msg_DoFind[_Context->language],strlen(_Context->msg_DoFind[_Context->language]));
	visual_button(_Context->x_Auto2759+530,_Context->y_Auto2759+30,68,16,vfh[8],16,22,_Context->msg_DoFind[_Context->language],strlen(_Context->msg_DoFind[_Context->language]),0);
	_Context->trigger_Quit=visual_trigger_code(_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]));
	visual_button(_Context->x_Auto2759+530,_Context->y_Auto2759+50,68,16,vfh[8],16,22,_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]),0);
	visual_thaw(_Context->x_Auto2759,_Context->y_Auto2759,610,80);

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

private int IgnoreCase_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this control is active the search will not be case sensitive, ";
			mptr[1]="other wise the exact case of the search expression will be respected. ";
			mptr[2]="  ";
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
			mptr[0] = "When this control is active the search will occur towards the start ";
			mptr[1]="of the file otherwise it will proceed towards the end of the file. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DoFind_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The editior search operation will be launched or repeated by clicking ";
			mptr[1]="on this button.   ";
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
			mptr[0] = "This button allows the current search operation to be abandoned.  ";
			mptr[1]=" ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2759action(struct accept_search_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_search_hide(_Context);

		_Context->x_Auto2759 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2759 < 0) { _Context->x_Auto2759=0; }
		_Context->y_Auto2759 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2759 < 0) { _Context->y_Auto2759=0; }
			accept_search_show(_Context);

		visual_thaw(_Context->x_Auto2759,_Context->y_Auto2759,610,80);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_DoFind_event(struct accept_search_context * _Context) {
		accept_search_hide(_Context);
;
	EditorTextFinder(_Context->buffer_Criteria,255,_Context->value_IgnoreCase,_Context->value_ReverseSearch);
		accept_search_show(_Context);
;
	return(-1);
}
private int on_Quit_event(struct accept_search_context * _Context) {
	return(13);
	return(-1);
}


public	int	accept_search_event(
struct accept_search_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IgnoreCase == mb ) return(3);
		if (_Context->trigger_ReverseSearch == mb ) return(4);
		if (_Context->trigger_DoFind == mb ) return(5);
		if (_Context->trigger_Quit == mb ) return(6);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2759+589) )  
	&&  (my >= (_Context->y_Auto2759+4) )  
	&&  (mx <= (_Context->x_Auto2759+606) )  
	&&  (my <= (_Context->y_Auto2759+20) )) {
		return(1);	/* Auto2759 */

		}
	if ((mx >= (_Context->x_Auto2759+573) )  
	&&  (my >= (_Context->y_Auto2759+4) )  
	&&  (mx <= (_Context->x_Auto2759+590) )  
	&&  (my <= (_Context->y_Auto2759+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vsearch.htm");
			};
		return(-1);	/* Auto2759 */

		}
	if ((mx >= (_Context->x_Auto2759+557) )  
	&&  (my >= (_Context->y_Auto2759+4) )  
	&&  (mx <= (_Context->x_Auto2759+574) )  
	&&  (my <= (_Context->y_Auto2759+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_search_show(_Context);
		return(-1);	/* Auto2759 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2759+4) )  
		&&  (my >= (_Context->y_Auto2759+4) )  
		&&  (mx <= (_Context->x_Auto2759+542) )  
		&&  (my <= (_Context->y_Auto2759+20) )) {
			return( Auto2759action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto2759+100) ) 
	&&  ( my >= (_Context->y_Auto2759+30) ) 
	&&  ( mx <= (_Context->x_Auto2759+100+424) ) 
	&&  ( my <= (_Context->y_Auto2759+30+16))) {
		return(2); /* Criteria */
		}
	if (( mx >= (_Context->x_Auto2759+90) ) 
	&&  ( my >= (_Context->y_Auto2759+50) ) 
	&&  ( mx <= (_Context->x_Auto2759+90+154) ) 
	&&  ( my <= (_Context->y_Auto2759+50+16))) {
		return(3); /* IgnoreCase */
		}
	if (( mx >= (_Context->x_Auto2759+250) ) 
	&&  ( my >= (_Context->y_Auto2759+50) ) 
	&&  ( mx <= (_Context->x_Auto2759+250+168) ) 
	&&  ( my <= (_Context->y_Auto2759+50+16))) {
		return(4); /* ReverseSearch */
		}
	if (( mx >= (_Context->x_Auto2759+530) ) 
	&&  ( my >= (_Context->y_Auto2759+30) ) 
	&&  ( mx <= (_Context->x_Auto2759+530+68) ) 
	&&  ( my <= (_Context->y_Auto2759+30+16))) {
		return(5); /* DoFind */
		}
	if (( mx >= (_Context->x_Auto2759+530) ) 
	&&  ( my >= (_Context->y_Auto2759+50) ) 
	&&  ( mx <= (_Context->x_Auto2759+530+68) ) 
	&&  ( my <= (_Context->y_Auto2759+50+16))) {
		return(6); /* Quit */
		}

	return(-1);
}


public	int	accept_search_focus(struct accept_search_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Criteria */
				_Context->keycode = visual_edit(_Context->x_Auto2759+100+1,_Context->y_Auto2759+30+1,424,16,vfh[1],_Context->buffer_Criteria,255);
				if(_Context->keycode==13){
				on_DoFind_event(_Context);
				_Context->keycode=0;
				}
			break;
			case	0x3 :
				/* IgnoreCase */
				visual_check(_Context->x_Auto2759+90,_Context->y_Auto2759+50,154,16,vfh[2],16,22,_Context->msg_IgnoreCase[_Context->language],strlen(_Context->msg_IgnoreCase[_Context->language]),(_Context->value_IgnoreCase |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IgnoreCase=visual_trigger_code(_Context->msg_IgnoreCase[_Context->language],strlen(_Context->msg_IgnoreCase[_Context->language]));
	visual_check(_Context->x_Auto2759+90,_Context->y_Auto2759+50,154,16,vfh[2],16,22,_Context->msg_IgnoreCase[_Context->language],strlen(_Context->msg_IgnoreCase[_Context->language]),_Context->value_IgnoreCase|0);
				break;
			case	0x4 :
				/* ReverseSearch */
				visual_check(_Context->x_Auto2759+250,_Context->y_Auto2759+50,168,16,vfh[2],16,22,_Context->msg_ReverseSearch[_Context->language],strlen(_Context->msg_ReverseSearch[_Context->language]),(_Context->value_ReverseSearch |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ReverseSearch=visual_trigger_code(_Context->msg_ReverseSearch[_Context->language],strlen(_Context->msg_ReverseSearch[_Context->language]));
	visual_check(_Context->x_Auto2759+250,_Context->y_Auto2759+50,168,16,vfh[2],16,22,_Context->msg_ReverseSearch[_Context->language],strlen(_Context->msg_ReverseSearch[_Context->language]),_Context->value_ReverseSearch|0);
				break;
			case	0x5 :
				/* DoFind */
				_Context->trigger_DoFind=visual_trigger_code(_Context->msg_DoFind[_Context->language],strlen(_Context->msg_DoFind[_Context->language]));
				visual_button(_Context->x_Auto2759+530,_Context->y_Auto2759+30,68,16,vfh[8],16,22,_Context->msg_DoFind[_Context->language],strlen(_Context->msg_DoFind[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_DoFind=visual_trigger_code(_Context->msg_DoFind[_Context->language],strlen(_Context->msg_DoFind[_Context->language]));
	visual_button(_Context->x_Auto2759+530,_Context->y_Auto2759+30,68,16,vfh[8],16,22,_Context->msg_DoFind[_Context->language],strlen(_Context->msg_DoFind[_Context->language]),0);
				break;
			case	0x6 :
				/* Quit */
				_Context->trigger_Quit=visual_trigger_code(_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]));
				visual_button(_Context->x_Auto2759+530,_Context->y_Auto2759+50,68,16,vfh[8],16,22,_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Quit=visual_trigger_code(_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]));
	visual_button(_Context->x_Auto2759+530,_Context->y_Auto2759+50,68,16,vfh[8],16,22,_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_search_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=6;
			accept_search_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_search_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (Criteria_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (IgnoreCase_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (ReverseSearch_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (DoFind_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Quit_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2759 */
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
					/* IgnoreCase */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IgnoreCase += 1;
						_Context->value_IgnoreCase &= 1;
						}
					continue;
				case	0x4 :
					/* ReverseSearch */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ReverseSearch += 1;
						_Context->value_ReverseSearch &= 1;
						}
					continue;
				case	0x5 :
					/* DoFind */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_DoFind=visual_trigger_code(_Context->msg_DoFind[_Context->language],strlen(_Context->msg_DoFind[_Context->language]));
						visual_button(_Context->x_Auto2759+530,_Context->y_Auto2759+30,68,16,vfh[8],16,22,_Context->msg_DoFind[_Context->language],strlen(_Context->msg_DoFind[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_DoFind=visual_trigger_code(_Context->msg_DoFind[_Context->language],strlen(_Context->msg_DoFind[_Context->language]));
	visual_button(_Context->x_Auto2759+530,_Context->y_Auto2759+30,68,16,vfh[8],16,22,_Context->msg_DoFind[_Context->language],strlen(_Context->msg_DoFind[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_DoFind_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Quit */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Quit=visual_trigger_code(_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]));
						visual_button(_Context->x_Auto2759+530,_Context->y_Auto2759+50,68,16,vfh[8],16,22,_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Quit=visual_trigger_code(_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]));
	visual_button(_Context->x_Auto2759+530,_Context->y_Auto2759+50,68,16,vfh[8],16,22,_Context->msg_Quit[_Context->language],strlen(_Context->msg_Quit[_Context->language]),0);
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

public	int	accept_search(
	char * pCriteria,
	char * pIgnoreCase,
	char * pReverseSearch)
{
	int	status=0;
	struct accept_search_context * _Context=(struct accept_search_context*) 0;
	status = accept_search_create(
	&_Context,
	 pCriteria,
	 pIgnoreCase,
	 pReverseSearch);
	if ( status != 0) return(status);
	status = accept_search_show(_Context);
		enter_modal();
	status = accept_search_focus(_Context);
		leave_modal();
	status = accept_search_hide(_Context);
	status = accept_search_remove(
	_Context,
	 pCriteria,
	 pIgnoreCase,
	 pReverseSearch);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vsearch_c */
