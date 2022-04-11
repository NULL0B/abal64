
#ifndef _vaed_c
#define _vaed_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vaed.sng  */
/* Target         : vaed.c  */
/* Identification : 0.0-1065572693-3578.3577 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
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
#define fr_Auto4714   "Normale"
#define it_Auto4714   ""
#define es_Auto4714   ""
#define de_Auto4714   ""
#define nl_Auto4714   ""
#define pt_Auto4714   ""
#define xx_Auto4714   ""
#define en_Auto4715   "Strings"
#define fr_Auto4715   "Chaines"
#define it_Auto4715   ""
#define es_Auto4715   ""
#define de_Auto4715   ""
#define nl_Auto4715   ""
#define pt_Auto4715   ""
#define xx_Auto4715   ""
#define en_Auto4716   "Keywords"
#define fr_Auto4716   "Motcl‚fs"
#define it_Auto4716   ""
#define es_Auto4716   ""
#define de_Auto4716   ""
#define nl_Auto4716   ""
#define pt_Auto4716   ""
#define xx_Auto4716   ""
#define en_Auto4717   "Comments"
#define fr_Auto4717   "Commentaire"
#define it_Auto4717   ""
#define es_Auto4717   ""
#define de_Auto4717   ""
#define nl_Auto4717   ""
#define pt_Auto4717   ""
#define xx_Auto4717   ""
#define en_Auto4707   "Abal Editor Configuration"
#define fr_Auto4707   "Configuration de l'editeur d'ABAL"
#define it_Auto4707   ""
#define es_Auto4707   ""
#define de_Auto4707   ""
#define nl_Auto4707   ""
#define pt_Auto4707   ""
#define xx_Auto4707   ""
#define en_auto777   "Name of file to Edit"
#define fr_auto777   "Nom de fichier … editer"
#define it_auto777   ""
#define es_auto777   ""
#define de_auto777   ""
#define nl_auto777   ""
#define pt_auto777   ""
#define xx_auto777   ""
#define en_auto599   "Path and Filename of Editor"
#define fr_auto599   "Nom et chemin de l'editeur"
#define it_auto599   ""
#define es_auto599   ""
#define de_auto599   ""
#define nl_auto599   ""
#define pt_auto599   ""
#define xx_auto599   ""
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define it_Accept   ""
#define es_Accept   ""
#define de_Accept   ""
#define nl_Accept   ""
#define pt_Accept   ""
#define xx_Accept   ""
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
#define it_Cancel   ""
#define es_Cancel   ""
#define de_Cancel   ""
#define nl_Cancel   ""
#define pt_Cancel   ""
#define xx_Cancel   ""
#define en_FrameInhibit   "&Inhibit this Frame"
#define fr_FrameInhibit   "&Inhiber ces choix"
#define it_FrameInhibit   ""
#define es_FrameInhibit   ""
#define de_FrameInhibit   ""
#define nl_FrameInhibit   ""
#define pt_FrameInhibit   ""
#define xx_FrameInhibit   ""

private struct accept_editor_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3390[8];
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
	} * _Context;

private	int	accept_editor_create(
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
	if (!(_Context = allocate( sizeof( struct accept_editor_context ) ) ))
		return(27);
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
	_Context->msg_Auto4714[2]=it_Auto4714;
	_Context->msg_Auto4714[3]=es_Auto4714;
	_Context->msg_Auto4714[4]=de_Auto4714;
	_Context->msg_Auto4714[5]=nl_Auto4714;
	_Context->msg_Auto4714[6]=pt_Auto4714;
	_Context->msg_Auto4714[7]=xx_Auto4714;
	for (i=0; i < 8; i++)_Context->msg_Auto4715[i]=" ";
	_Context->msg_Auto4715[0]=en_Auto4715;
	_Context->msg_Auto4715[1]=fr_Auto4715;
	_Context->msg_Auto4715[2]=it_Auto4715;
	_Context->msg_Auto4715[3]=es_Auto4715;
	_Context->msg_Auto4715[4]=de_Auto4715;
	_Context->msg_Auto4715[5]=nl_Auto4715;
	_Context->msg_Auto4715[6]=pt_Auto4715;
	_Context->msg_Auto4715[7]=xx_Auto4715;
	for (i=0; i < 8; i++)_Context->msg_Auto4716[i]=" ";
	_Context->msg_Auto4716[0]=en_Auto4716;
	_Context->msg_Auto4716[1]=fr_Auto4716;
	_Context->msg_Auto4716[2]=it_Auto4716;
	_Context->msg_Auto4716[3]=es_Auto4716;
	_Context->msg_Auto4716[4]=de_Auto4716;
	_Context->msg_Auto4716[5]=nl_Auto4716;
	_Context->msg_Auto4716[6]=pt_Auto4716;
	_Context->msg_Auto4716[7]=xx_Auto4716;
	for (i=0; i < 8; i++)_Context->msg_Auto4717[i]=" ";
	_Context->msg_Auto4717[0]=en_Auto4717;
	_Context->msg_Auto4717[1]=fr_Auto4717;
	_Context->msg_Auto4717[2]=it_Auto4717;
	_Context->msg_Auto4717[3]=es_Auto4717;
	_Context->msg_Auto4717[4]=de_Auto4717;
	_Context->msg_Auto4717[5]=nl_Auto4717;
	_Context->msg_Auto4717[6]=pt_Auto4717;
	_Context->msg_Auto4717[7]=xx_Auto4717;
	for (i=0; i < 8; i++)_Context->msg_Auto4707[i]=" ";
	_Context->msg_Auto4707[0]=en_Auto4707;
	_Context->msg_Auto4707[1]=fr_Auto4707;
	_Context->msg_Auto4707[2]=it_Auto4707;
	_Context->msg_Auto4707[3]=es_Auto4707;
	_Context->msg_Auto4707[4]=de_Auto4707;
	_Context->msg_Auto4707[5]=nl_Auto4707;
	_Context->msg_Auto4707[6]=pt_Auto4707;
	_Context->msg_Auto4707[7]=xx_Auto4707;
	for (i=0; i < 8; i++)_Context->msg_auto777[i]=" ";
	_Context->msg_auto777[0]=en_auto777;
	_Context->msg_auto777[1]=fr_auto777;
	_Context->msg_auto777[2]=it_auto777;
	_Context->msg_auto777[3]=es_auto777;
	_Context->msg_auto777[4]=de_auto777;
	_Context->msg_auto777[5]=nl_auto777;
	_Context->msg_auto777[6]=pt_auto777;
	_Context->msg_auto777[7]=xx_auto777;
	for (i=0; i < 8; i++)_Context->msg_auto599[i]=" ";
	_Context->msg_auto599[0]=en_auto599;
	_Context->msg_auto599[1]=fr_auto599;
	_Context->msg_auto599[2]=it_auto599;
	_Context->msg_auto599[3]=es_auto599;
	_Context->msg_auto599[4]=de_auto599;
	_Context->msg_auto599[5]=nl_auto599;
	_Context->msg_auto599[6]=pt_auto599;
	_Context->msg_auto599[7]=xx_auto599;
	for (i=0; i < 8; i++)_Context->msg_RazColour[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_QuoteColour[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_KeyWordColour[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_CommentColour[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	for (i=0; i < 8; i++)_Context->msg_FrameInhibit[i]=" ";
	_Context->msg_FrameInhibit[0]=en_FrameInhibit;
	_Context->msg_FrameInhibit[1]=fr_FrameInhibit;
	_Context->msg_FrameInhibit[2]=it_FrameInhibit;
	_Context->msg_FrameInhibit[3]=es_FrameInhibit;
	_Context->msg_FrameInhibit[4]=de_FrameInhibit;
	_Context->msg_FrameInhibit[5]=nl_FrameInhibit;
	_Context->msg_FrameInhibit[6]=pt_FrameInhibit;
	_Context->msg_FrameInhibit[7]=xx_FrameInhibit;
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(145,140,510+10,320+10);
	return(0);
}

private	int	accept_editor_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,145,140);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_editor_remove(
	char * pFileName,
	char * pEditorName,
	char * pRazColour,
	char * pQuoteColour,
	char * pKeyWordColour,
	char * pCommentColour,
	char * pFrameInhibit,
	char * pTextFont)
{

	int	result=_Context->keycode;
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

private	int	accept_editor_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,145,140);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(145,140,510,320,2,_Context->msg_Auto3390[_Context->language],strlen(_Context->msg_Auto3390[_Context->language]),0x407);
	visual_image(149,162,502,294,_Context->msg_Auto1155[_Context->language],4);
	visual_text(165,310,110,20,1,27,0,_Context->msg_Auto4714[_Context->language],strlen(_Context->msg_Auto4714[_Context->language]),3);
	visual_text(285,310,110,20,1,27,0,_Context->msg_Auto4715[_Context->language],strlen(_Context->msg_Auto4715[_Context->language]),3);
	visual_text(405,310,110,20,1,27,0,_Context->msg_Auto4716[_Context->language],strlen(_Context->msg_Auto4716[_Context->language]),3);
	visual_text(525,310,110,20,1,27,0,_Context->msg_Auto4717[_Context->language],strlen(_Context->msg_Auto4717[_Context->language]),3);
	visual_text(165,170,460,20,3,27,0,_Context->msg_Auto4707[_Context->language],strlen(_Context->msg_Auto4707[_Context->language]),2);
	visual_text(165,200,470,20,2,27,0,_Context->msg_auto777[_Context->language],strlen(_Context->msg_auto777[_Context->language]),0);
	visual_frame(165,220,470+2,20+2,5);
	visual_text(165+1,220+1,470,20,1,26,0,_Context->buffer_FileName,58,0);
	visual_text(165,260,470,20,2,27,0,_Context->msg_auto599[_Context->language],strlen(_Context->msg_auto599[_Context->language]),0);
	visual_frame(165,280,470+2,20+2,5);
	visual_text(165+1,280+1,470,20,1,26,0,_Context->buffer_EditorName,58,0);
	visual_select(165,330,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_RazColour),768);
	visual_select(285,330,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_QuoteColour),768);
	visual_select(405,330,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_KeyWordColour),768);
	visual_select(525,330,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_CommentColour),768);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(165,410,110,30,2,26,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(525,410,110,30,2,26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	_Context->trigger_FrameInhibit=visual_trigger_code(_Context->msg_FrameInhibit[_Context->language],strlen(_Context->msg_FrameInhibit[_Context->language]));
	visual_check(335,420,154,16,2,26,0,_Context->msg_FrameInhibit[_Context->language],strlen(_Context->msg_FrameInhibit[_Context->language]),_Context->value_FrameInhibit|0);
	visual_select(335,380,150,70,1,0,0,parse_selection(TextFontList,&_Context->value_TextFont),0);
	visual_thaw(145,140,510,320);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	accept_editor_event()
{
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
	if (mt & _MIMO_UP) {
	if ((mx >= 634 )  
	&&  (my >= 144 )  
	&&  (mx <= 650 )  
	&&  (my <= 160 )) {
		return(1);	/* Auto3390 */

		}
	if ((mx >= 618 )  
	&&  (my >= 144 )  
	&&  (mx <= 634 )  
	&&  (my <= 160 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vaed.htm");
			};
		return(-1);	/* Auto3390 */

		}
	if ((mx >= 602 )  
	&&  (my >= 144 )  
	&&  (mx <= 618 )  
	&&  (my <= 160 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		_Context->language--; _Context->language %=8;
			}
		(void) visual_national_language(_Context->language);
		accept_editor_show();
		return(-1);	/* Auto3390 */

		}
		}
	if (( mx >= 165 ) 
	&&  ( my >= 280 ) 
	&&  ( mx <= 635 ) 
	&&  ( my <= 300 )) {
		return(2); /* EditorName */
		}
	if ((mx >= 165 ) 
	&&  (my >= 330 ) 
	&&  (mx <= 277 ) 
	&&  (my <= 346 )) {
		return(3); /* RazColour */
		}
	if ((mx >= 285 ) 
	&&  (my >= 330 ) 
	&&  (mx <= 397 ) 
	&&  (my <= 346 )) {
		return(4); /* QuoteColour */
		}
	if ((mx >= 405 ) 
	&&  (my >= 330 ) 
	&&  (mx <= 517 ) 
	&&  (my <= 346 )) {
		return(5); /* KeyWordColour */
		}
	if ((mx >= 525 ) 
	&&  (my >= 330 ) 
	&&  (mx <= 637 ) 
	&&  (my <= 346 )) {
		return(6); /* CommentColour */
		}
	if (( mx >= 165 ) 
	&&  ( my >= 410 ) 
	&&  ( mx <= 275 ) 
	&&  ( my <= 440 )) {
		return(7); /* Accept */
		}
	if (( mx >= 525 ) 
	&&  ( my >= 410 ) 
	&&  ( mx <= 635 ) 
	&&  ( my <= 440 )) {
		return(8); /* Cancel */
		}
	if (( mx >= 335 ) 
	&&  ( my >= 420 ) 
	&&  ( mx <= 489 ) 
	&&  ( my <= 436 )) {
		return(9); /* FrameInhibit */
		}
	if ((mx >= 335 ) 
	&&  (my >= 380 ) 
	&&  (mx <= 485 ) 
	&&  (my <= 396 )) {
		return(10); /* TextFont */
		}

	return(-1);
}


private	int	accept_editor_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* EditorName */
				_Context->keycode = visual_edit(165+1,280+1,470,20,1,_Context->buffer_EditorName,58);
				break;
			case	0x3 :
				/* RazColour */
				_Context->keycode = visual_select(165,330,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_RazColour),770);
				break;
			case	0x4 :
				/* QuoteColour */
				_Context->keycode = visual_select(285,330,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_QuoteColour),770);
				break;
			case	0x5 :
				/* KeyWordColour */
				_Context->keycode = visual_select(405,330,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_KeyWordColour),770);
				break;
			case	0x6 :
				/* CommentColour */
				_Context->keycode = visual_select(525,330,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_CommentColour),770);
				break;
			case	0x7 :
				/* Accept */
				visual_button(165,410,110,30,2,26,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(165,410,110,30,2,26,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x8 :
				/* Cancel */
				visual_button(525,410,110,30,2,26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(525,410,110,30,2,26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0x9 :
				/* FrameInhibit */
				visual_check(335,420,154,16,2,26,0,_Context->msg_FrameInhibit[_Context->language],strlen(_Context->msg_FrameInhibit[_Context->language]),(_Context->value_FrameInhibit |2));
				_Context->keycode = visual_getch();
				visual_check(335,420,154,16,2,26,0,_Context->msg_FrameInhibit[_Context->language],strlen(_Context->msg_FrameInhibit[_Context->language]),(_Context->value_FrameInhibit |0));
				break;
			case	0xa :
				/* TextFont */
				_Context->keycode = visual_select(335,380,150,70,1,0,0,parse_selection(TextFontList,&_Context->value_TextFont),2);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_editor_show();
			continue;
		case	0x2 :
			_Context->focus_item=10;
			accept_editor_show();
			continue;
			case	0x100 :
				if ((retcode=accept_editor_event()) == -1)
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
							visual_button(165,410,110,30,2,26,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(165,410,110,30,2,26,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x8 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(525,410,110,30,2,26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(525,410,110,30,2,26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

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
	status = accept_editor_create(
	 pFileName,
	 pEditorName,
	 pRazColour,
	 pQuoteColour,
	 pKeyWordColour,
	 pCommentColour,
	 pFrameInhibit,
	 pTextFont);
	if ( status != 0) return(status);
	status = accept_editor_show();
		enter_modal();
	status = accept_editor_focus();
		leave_modal();
	status = accept_editor_hide();
	status = accept_editor_remove(
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
