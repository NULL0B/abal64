
#ifndef _vaed_c
#define _vaed_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vaed.xml  */
/* Target         : vaed.c  */
/* Identification : 0.0-1100085067-2936.2935 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto3390   "Sing : Version 1.0a"
#define fr_Auto3390   "Sing : Version 1.0a"
#define it_Auto3390   "Sing : Version 1.0a"
#define es_Auto3390   "Sing : Version 1.0a"
#define de_Auto3390   "Sing : Version 1.0a"
#define nl_Auto3390   "Sing : Version 1.0a"
#define pt_Auto3390   "Sing : Version 1.0a"
#define xx_Auto3390   "Sing : Version 1.0a"
#define en_Auto1155   "skin.gif"
#define fr_Auto1155   "skin.gif"
#define it_Auto1155   "skin.gif"
#define es_Auto1155   "skin.gif"
#define de_Auto1155   "skin.gif"
#define nl_Auto1155   "skin.gif"
#define pt_Auto1155   "skin.gif"
#define xx_Auto1155   "skin.gif"
#define en_Auto4714   "Normal"
#define fr_Auto4714   "Normal"
#define en_Auto4715   "Strings"
#define fr_Auto4715   "ChaŒnes"
#define en_Auto4716   "Keywords"
#define fr_Auto4716   "Mots cl‚s"
#define en_Auto4717   "Comments"
#define fr_Auto4717   "Commentaires"
#define en_Auto4707   "Abal Editor Configuration"
#define fr_Auto4707   "Configuration de l'Editeur ABAL"
#define en_auto777   "Name of file to Edit"
#define fr_auto777   "Nom du fichier … Editer"
#define en_auto599   "Path and Filename of Editor"
#define fr_auto599   "Chemin et Nom de l'Editeur"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
#define en_FrameInhibit   "&Inhibit this Frame"
#define fr_FrameInhibit   "&Inhiber cette BoŒte"
static int	vfh[10];

private struct accept_editor_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3390[8];
	int	x_Auto3390;
	int	y_Auto3390;
	int	w_Auto3390;
	int	h_Auto3390;
	char * msg_Auto1155[8];
	char * msg_Auto4714[8];
	char * msg_Auto4715[8];
	char * msg_Auto4716[8];
	char * msg_Auto4717[8];
	char * msg_Auto4707[8];
	char * msg_auto777[8];
	char	buffer_FileName[59];
	char * msg_auto599[8];
	char	buffer_EditorName[59];
	char * msg_RazColour[8];
	int	value_RazColour;
	char * msg_QuoteColour[8];
	int	value_QuoteColour;
	char * msg_KeyWordColour[8];
	int	value_KeyWordColour;
	char * msg_CommentColour[8];
	int	value_CommentColour;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_FrameInhibit[8];
	int	trigger_FrameInhibit;
	int	value_FrameInhibit;
	char * msg_TextFont[8];
	int	value_TextFont;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[9];
	};

public	int	accept_editor_create(
	struct accept_editor_context ** cptr,
	char * pFileName,
	char * pEditorName,
	char * pRazColour,
	char * pQuoteColour,
	char * pKeyWordColour,
	char * pCommentColour,
	char * pFrameInhibit,
	char * pTextFont)
{

	int i;
	struct accept_editor_context * _Context=(struct accept_editor_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_editor_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=10;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KSWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 58, pFileName);
		visual_transferin(_Context->buffer_EditorName, 58, pEditorName);
		visual_transferin((void *) 0, 0, pRazColour);
		if (!( pRazColour )) _Context->value_RazColour=0;
		else	_Context->value_RazColour = *((int *)pRazColour);
		visual_transferin((void *) 0, 0, pQuoteColour);
		if (!( pQuoteColour )) _Context->value_QuoteColour=0;
		else	_Context->value_QuoteColour = *((int *)pQuoteColour);
		visual_transferin((void *) 0, 0, pKeyWordColour);
		if (!( pKeyWordColour )) _Context->value_KeyWordColour=0;
		else	_Context->value_KeyWordColour = *((int *)pKeyWordColour);
		visual_transferin((void *) 0, 0, pCommentColour);
		if (!( pCommentColour )) _Context->value_CommentColour=0;
		else	_Context->value_CommentColour = *((int *)pCommentColour);
		visual_transferin((void *) 0, 0, pFrameInhibit);
		if (!( pFrameInhibit )) _Context->value_FrameInhibit=0;
		else	_Context->value_FrameInhibit = *((int *)pFrameInhibit);
		visual_transferin((void *) 0, 0, pTextFont);
		if (!( pTextFont )) _Context->value_TextFont=0;
		else	_Context->value_TextFont = *((int *)pTextFont);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3390[i]=" ";
	_Context->msg_Auto3390[0]=en_Auto3390;
	_Context->msg_Auto3390[1]=fr_Auto3390;
	_Context->msg_Auto3390[2]=it_Auto3390;
	_Context->msg_Auto3390[3]=es_Auto3390;
	_Context->msg_Auto3390[4]=de_Auto3390;
	_Context->msg_Auto3390[5]=nl_Auto3390;
	_Context->msg_Auto3390[6]=pt_Auto3390;
	_Context->msg_Auto3390[7]=xx_Auto3390;
	_Context->x_Auto3390=145;
	_Context->y_Auto3390=140;
	_Context->w_Auto3390=510;
	_Context->h_Auto3390=320;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1155[i]=" ";
	_Context->msg_Auto1155[0]=en_Auto1155;
	_Context->msg_Auto1155[1]=fr_Auto1155;
	_Context->msg_Auto1155[2]=it_Auto1155;
	_Context->msg_Auto1155[3]=es_Auto1155;
	_Context->msg_Auto1155[4]=de_Auto1155;
	_Context->msg_Auto1155[5]=nl_Auto1155;
	_Context->msg_Auto1155[6]=pt_Auto1155;
	_Context->msg_Auto1155[7]=xx_Auto1155;
	for (i=0; i < 8; i++)_Context->msg_Auto4714[i]=" ";
	_Context->msg_Auto4714[0]=en_Auto4714;
	_Context->msg_Auto4714[1]=fr_Auto4714;
	for (i=0; i < 8; i++)_Context->msg_Auto4715[i]=" ";
	_Context->msg_Auto4715[0]=en_Auto4715;
	_Context->msg_Auto4715[1]=fr_Auto4715;
	for (i=0; i < 8; i++)_Context->msg_Auto4716[i]=" ";
	_Context->msg_Auto4716[0]=en_Auto4716;
	_Context->msg_Auto4716[1]=fr_Auto4716;
	for (i=0; i < 8; i++)_Context->msg_Auto4717[i]=" ";
	_Context->msg_Auto4717[0]=en_Auto4717;
	_Context->msg_Auto4717[1]=fr_Auto4717;
	for (i=0; i < 8; i++)_Context->msg_Auto4707[i]=" ";
	_Context->msg_Auto4707[0]=en_Auto4707;
	_Context->msg_Auto4707[1]=fr_Auto4707;
	for (i=0; i < 8; i++)_Context->msg_auto777[i]=" ";
	_Context->msg_auto777[0]=en_auto777;
	_Context->msg_auto777[1]=fr_auto777;
	for (i=0; i < 8; i++)_Context->msg_auto599[i]=" ";
	_Context->msg_auto599[0]=en_auto599;
	_Context->msg_auto599[1]=fr_auto599;
	for (i=0; i < 8; i++)_Context->msg_RazColour[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_QuoteColour[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_KeyWordColour[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_CommentColour[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	for (i=0; i < 8; i++)_Context->msg_FrameInhibit[i]=" ";
	_Context->msg_FrameInhibit[0]=en_FrameInhibit;
	_Context->msg_FrameInhibit[1]=fr_FrameInhibit;
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3390,_Context->y_Auto3390,510+10,320+10);
	return(0);
}

public 	int	accept_editor_hide(struct accept_editor_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3390,_Context->y_Auto3390);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_editor_remove(
	struct accept_editor_context * _Context,
	char * pFileName,
	char * pEditorName,
	char * pRazColour,
	char * pQuoteColour,
	char * pKeyWordColour,
	char * pCommentColour,
	char * pFrameInhibit,
	char * pTextFont)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KSWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 58, pFileName);
		visual_transferout(_Context->buffer_EditorName, 58, pEditorName);
		visual_transferout((void *) 0, 0, pRazColour);
		if ( pRazColour != (char *) 0)
			*((int*)pRazColour) = _Context->value_RazColour;
		visual_transferout((void *) 0, 0, pQuoteColour);
		if ( pQuoteColour != (char *) 0)
			*((int*)pQuoteColour) = _Context->value_QuoteColour;
		visual_transferout((void *) 0, 0, pKeyWordColour);
		if ( pKeyWordColour != (char *) 0)
			*((int*)pKeyWordColour) = _Context->value_KeyWordColour;
		visual_transferout((void *) 0, 0, pCommentColour);
		if ( pCommentColour != (char *) 0)
			*((int*)pCommentColour) = _Context->value_CommentColour;
		visual_transferout((void *) 0, 0, pFrameInhibit);
		if ( pFrameInhibit != (char *) 0)
			*((int*)pFrameInhibit) = _Context->value_FrameInhibit;
		visual_transferout((void *) 0, 0, pTextFont);
		if ( pTextFont != (char *) 0)
			*((int*)pTextFont) = _Context->value_TextFont;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_editor_show(struct accept_editor_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3390,_Context->y_Auto3390);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto3390,_Context->y_Auto3390,510,320,vfh[2],_Context->msg_Auto3390[_Context->language],strlen(_Context->msg_Auto3390[_Context->language]),0x407);
	visual_image(_Context->x_Auto3390+4,_Context->y_Auto3390+22,502,294,_Context->msg_Auto1155[_Context->language],4);
	visual_text(_Context->x_Auto3390+20,_Context->y_Auto3390+170,110,20,vfh[2],27,0,_Context->msg_Auto4714[_Context->language],strlen(_Context->msg_Auto4714[_Context->language]),3);
	visual_text(_Context->x_Auto3390+140,_Context->y_Auto3390+170,110,20,vfh[2],27,0,_Context->msg_Auto4715[_Context->language],strlen(_Context->msg_Auto4715[_Context->language]),3);
	visual_text(_Context->x_Auto3390+260,_Context->y_Auto3390+170,110,20,vfh[2],27,0,_Context->msg_Auto4716[_Context->language],strlen(_Context->msg_Auto4716[_Context->language]),3);
	visual_text(_Context->x_Auto3390+380,_Context->y_Auto3390+170,110,20,vfh[2],27,0,_Context->msg_Auto4717[_Context->language],strlen(_Context->msg_Auto4717[_Context->language]),3);
	visual_text(_Context->x_Auto3390+20,_Context->y_Auto3390+30,460,20,vfh[3],27,0,_Context->msg_Auto4707[_Context->language],strlen(_Context->msg_Auto4707[_Context->language]),1282);
	visual_text(_Context->x_Auto3390+20,_Context->y_Auto3390+60,470,20,vfh[2],27,0,_Context->msg_auto777[_Context->language],strlen(_Context->msg_auto777[_Context->language]),0);
	visual_frame(_Context->x_Auto3390+20,_Context->y_Auto3390+80,470+2,20+2,5);
	visual_text(_Context->x_Auto3390+20+1,_Context->y_Auto3390+80+1,470,20,vfh[1],26,0,_Context->buffer_FileName,58,0);
	visual_text(_Context->x_Auto3390+20,_Context->y_Auto3390+120,470,20,vfh[2],27,0,_Context->msg_auto599[_Context->language],strlen(_Context->msg_auto599[_Context->language]),0);
	visual_frame(_Context->x_Auto3390+20,_Context->y_Auto3390+140,470+2,20+2,5);
	visual_text(_Context->x_Auto3390+20+1,_Context->y_Auto3390+140+1,470,20,vfh[1],26,0,_Context->buffer_EditorName,58,0);
	visual_select(_Context->x_Auto3390+20,_Context->y_Auto3390+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_RazColour),768);
	visual_select(_Context->x_Auto3390+140,_Context->y_Auto3390+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_QuoteColour),768);
	visual_select(_Context->x_Auto3390+260,_Context->y_Auto3390+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_KeyWordColour),768);
	visual_select(_Context->x_Auto3390+380,_Context->y_Auto3390+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_CommentColour),768);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3390+20,_Context->y_Auto3390+270,110,30,vfh[2],26,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3390+380,_Context->y_Auto3390+270,110,30,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	_Context->trigger_FrameInhibit=visual_trigger_code(_Context->msg_FrameInhibit[_Context->language],strlen(_Context->msg_FrameInhibit[_Context->language]));
	visual_check(_Context->x_Auto3390+190,_Context->y_Auto3390+280,168,16,vfh[2],26,0,_Context->msg_FrameInhibit[_Context->language],strlen(_Context->msg_FrameInhibit[_Context->language]),_Context->value_FrameInhibit|0);
	visual_select(_Context->x_Auto3390+190,_Context->y_Auto3390+240,150,70,vfh[1],0,0,parse_selection(TextFontList,&_Context->value_TextFont),0);
	visual_thaw(_Context->x_Auto3390,_Context->y_Auto3390,510,320);
	visual_thaw(_Context->x_Auto3390,_Context->y_Auto3390,510,320);

	return(0);
}

private int Auto3390action(struct accept_editor_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_editor_hide(_Context);

		_Context->x_Auto3390 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3390 < 0) { _Context->x_Auto3390=0; }
		_Context->y_Auto3390 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3390 < 0) { _Context->y_Auto3390=0; }
			accept_editor_show(_Context);

		visual_thaw(_Context->x_Auto3390,_Context->y_Auto3390,510,320);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_editor_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_editor_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_editor_event(
struct accept_editor_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(7);
		if (_Context->trigger_Cancel == mb ) return(8);
		if (_Context->trigger_FrameInhibit == mb ) return(9);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3390+489) )  
	&&  (my >= (_Context->y_Auto3390+4) )  
	&&  (mx <= (_Context->x_Auto3390+506) )  
	&&  (my <= (_Context->y_Auto3390+20) )) {
		return(1);	/* Auto3390 */

		}
	if ((mx >= (_Context->x_Auto3390+473) )  
	&&  (my >= (_Context->y_Auto3390+4) )  
	&&  (mx <= (_Context->x_Auto3390+490) )  
	&&  (my <= (_Context->y_Auto3390+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vaed.htm");
			};
		return(-1);	/* Auto3390 */

		}
	if ((mx >= (_Context->x_Auto3390+457) )  
	&&  (my >= (_Context->y_Auto3390+4) )  
	&&  (mx <= (_Context->x_Auto3390+474) )  
	&&  (my <= (_Context->y_Auto3390+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_editor_show(_Context);
		return(-1);	/* Auto3390 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3390+4) )  
		&&  (my >= (_Context->y_Auto3390+4) )  
		&&  (mx <= (_Context->x_Auto3390+442) )  
		&&  (my <= (_Context->y_Auto3390+20) )) {
			return( Auto3390action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3390+20) ) 
	&&  ( my >= (_Context->y_Auto3390+140) ) 
	&&  ( mx <= (_Context->x_Auto3390+20+470) ) 
	&&  ( my <= (_Context->y_Auto3390+140+20))) {
		return(2); /* EditorName */
		}
	if (( mx >= (_Context->x_Auto3390+20+0) ) 
	&&  ( my >= (_Context->y_Auto3390+190) ) 
	&&  ( mx <= (_Context->x_Auto3390+20+112) ) 
	&&  ( my <= (_Context->y_Auto3390+190+16))) {
		return(3); /* RazColour */
		}
	if (( mx >= (_Context->x_Auto3390+140+0) ) 
	&&  ( my >= (_Context->y_Auto3390+190) ) 
	&&  ( mx <= (_Context->x_Auto3390+140+112) ) 
	&&  ( my <= (_Context->y_Auto3390+190+16))) {
		return(4); /* QuoteColour */
		}
	if (( mx >= (_Context->x_Auto3390+260+0) ) 
	&&  ( my >= (_Context->y_Auto3390+190) ) 
	&&  ( mx <= (_Context->x_Auto3390+260+112) ) 
	&&  ( my <= (_Context->y_Auto3390+190+16))) {
		return(5); /* KeyWordColour */
		}
	if (( mx >= (_Context->x_Auto3390+380+0) ) 
	&&  ( my >= (_Context->y_Auto3390+190) ) 
	&&  ( mx <= (_Context->x_Auto3390+380+112) ) 
	&&  ( my <= (_Context->y_Auto3390+190+16))) {
		return(6); /* CommentColour */
		}
	if (( mx >= (_Context->x_Auto3390+20) ) 
	&&  ( my >= (_Context->y_Auto3390+270) ) 
	&&  ( mx <= (_Context->x_Auto3390+20+110) ) 
	&&  ( my <= (_Context->y_Auto3390+270+30))) {
		return(7); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3390+380) ) 
	&&  ( my >= (_Context->y_Auto3390+270) ) 
	&&  ( mx <= (_Context->x_Auto3390+380+110) ) 
	&&  ( my <= (_Context->y_Auto3390+270+30))) {
		return(8); /* Cancel */
		}
	if (( mx >= (_Context->x_Auto3390+190) ) 
	&&  ( my >= (_Context->y_Auto3390+280) ) 
	&&  ( mx <= (_Context->x_Auto3390+190+168) ) 
	&&  ( my <= (_Context->y_Auto3390+280+16))) {
		return(9); /* FrameInhibit */
		}
	if (( mx >= (_Context->x_Auto3390+190+0) ) 
	&&  ( my >= (_Context->y_Auto3390+240) ) 
	&&  ( mx <= (_Context->x_Auto3390+190+150) ) 
	&&  ( my <= (_Context->y_Auto3390+240+16))) {
		return(10); /* TextFont */
		}

	return(-1);
}


public	int	accept_editor_focus(struct accept_editor_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* EditorName */
				_Context->keycode = visual_edit(_Context->x_Auto3390+20+1,_Context->y_Auto3390+140+1,470,20,vfh[1],_Context->buffer_EditorName,58);
			break;
			case	0x3 :
				/* RazColour */
				_Context->keycode = visual_select(_Context->x_Auto3390+20,_Context->y_Auto3390+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_RazColour),770);
				break;
			case	0x4 :
				/* QuoteColour */
				_Context->keycode = visual_select(_Context->x_Auto3390+140,_Context->y_Auto3390+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_QuoteColour),770);
				break;
			case	0x5 :
				/* KeyWordColour */
				_Context->keycode = visual_select(_Context->x_Auto3390+260,_Context->y_Auto3390+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_KeyWordColour),770);
				break;
			case	0x6 :
				/* CommentColour */
				_Context->keycode = visual_select(_Context->x_Auto3390+380,_Context->y_Auto3390+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_CommentColour),770);
				break;
			case	0x7 :
				/* Accept */
				visual_button(_Context->x_Auto3390+20,_Context->y_Auto3390+270,110,30,vfh[2],26,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto3390+20,_Context->y_Auto3390+270,110,30,vfh[2],26,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x8 :
				/* Cancel */
				visual_button(_Context->x_Auto3390+380,_Context->y_Auto3390+270,110,30,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto3390+380,_Context->y_Auto3390+270,110,30,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0x9 :
				/* FrameInhibit */
				visual_check(_Context->x_Auto3390+190,_Context->y_Auto3390+280,168,16,vfh[2],26,0,_Context->msg_FrameInhibit[_Context->language],strlen(_Context->msg_FrameInhibit[_Context->language]),(_Context->value_FrameInhibit |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto3390+190,_Context->y_Auto3390+280,168,16,vfh[2],26,0,_Context->msg_FrameInhibit[_Context->language],strlen(_Context->msg_FrameInhibit[_Context->language]),(_Context->value_FrameInhibit |0));
				break;
			case	0xa :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_Auto3390+190,_Context->y_Auto3390+240,150,70,vfh[1],0,0,parse_selection(TextFontList,&_Context->value_TextFont),2);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_editor_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=10;
			accept_editor_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_editor_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto3390 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* EditorName */
						continue;
					case	0x3 :
						/* RazColour */
						continue;
					case	0x4 :
						/* QuoteColour */
						continue;
					case	0x5 :
						/* KeyWordColour */
						continue;
					case	0x6 :
						/* CommentColour */
						continue;
					case	0x7 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto3390+20,_Context->y_Auto3390+270,110,30,vfh[2],26,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto3390+20,_Context->y_Auto3390+270,110,30,vfh[2],26,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x8 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto3390+380,_Context->y_Auto3390+270,110,30,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto3390+380,_Context->y_Auto3390+270,110,30,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0x9 :
						/* FrameInhibit */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_FrameInhibit += 1;
							_Context->value_FrameInhibit &= 1;
							}
						continue;
					case	0xa :
						/* TextFont */
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
				_Context->focus_item=10;
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

public	int	accept_editor(
	char * pFileName,
	char * pEditorName,
	char * pRazColour,
	char * pQuoteColour,
	char * pKeyWordColour,
	char * pCommentColour,
	char * pFrameInhibit,
	char * pTextFont)
{
	int	status=0;
	struct accept_editor_context * _Context=(struct accept_editor_context*) 0;
	status = accept_editor_create(
	&_Context,
	 pFileName,
	 pEditorName,
	 pRazColour,
	 pQuoteColour,
	 pKeyWordColour,
	 pCommentColour,
	 pFrameInhibit,
	 pTextFont);
	if ( status != 0) return(status);
	status = accept_editor_show(_Context);
		enter_modal();
	status = accept_editor_focus(_Context);
		leave_modal();
	status = accept_editor_hide(_Context);
	status = accept_editor_remove(
	_Context,
	 pFileName,
	 pEditorName,
	 pRazColour,
	 pQuoteColour,
	 pKeyWordColour,
	 pCommentColour,
	 pFrameInhibit,
	 pTextFont);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vaed_c */
