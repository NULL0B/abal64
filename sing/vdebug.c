
#ifndef _vdebug_c
#define _vdebug_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vdebug.sng  */
/* Target         : vdebug.c  */
/* Identification : 0.0-1065572400-3578.3577 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto580   "Sing : Version 1.0a"
#define fr_Auto580   "Sing : Version 1.0a"
#define it_Auto580   "Sing : Version 1.0a"
#define es_Auto580   "Sing : Version 1.0a"
#define de_Auto580   "Sing : Version 1.0a"
#define nl_Auto580   "Sing : Version 1.0a"
#define pt_Auto580   "Sing : Version 1.0a"
#define xx_Auto580   "Sing : Version 1.0a"
#define en_Auto581   "skin.gif"
#define fr_Auto581   "skin.gif"
#define it_Auto581   "skin.gif"
#define es_Auto581   "skin.gif"
#define de_Auto581   "skin.gif"
#define nl_Auto581   "skin.gif"
#define pt_Auto581   "skin.gif"
#define xx_Auto581   "skin.gif"
#define en_Auto669   "ABAL++ Runtime Options"
#define fr_Auto669   "ABAL++ Options d'Execution"
#define it_Auto669   ""
#define es_Auto669   ""
#define de_Auto669   ""
#define nl_Auto669   ""
#define pt_Auto669   ""
#define xx_Auto669   ""
#define en_Auto607   "Abal++ Debug Utility"
#define fr_Auto607   "Debuggeur ABAL"
#define it_Auto607   ""
#define es_Auto607   ""
#define de_Auto607   ""
#define nl_Auto607   ""
#define pt_Auto607   ""
#define xx_Auto607   ""
#define en_Auto629   "Abal++ Runtime"
#define fr_Auto629   "Executeur ABAL"
#define it_Auto629   ""
#define es_Auto629   ""
#define de_Auto629   ""
#define nl_Auto629   ""
#define pt_Auto629   ""
#define xx_Auto629   ""
#define en_Auto592   "exaicon.gif"
#define fr_Auto592   "exaicon.gif"
#define it_Auto592   "exaicon.gif"
#define es_Auto592   "exaicon.gif"
#define de_Auto592   "exaicon.gif"
#define nl_Auto592   "exaicon.gif"
#define pt_Auto592   "exaicon.gif"
#define xx_Auto592   "exaicon.gif"
#define en_Auto591   "abal.gif"
#define fr_Auto591   "abal.gif"
#define it_Auto591   "abal.gif"
#define es_Auto591   "abal.gif"
#define de_Auto591   "abal.gif"
#define nl_Auto591   "abal.gif"
#define pt_Auto591   "abal.gif"
#define xx_Auto591   "abal.gif"
#define en_Auto585   "Abal Program Name"
#define fr_Auto585   "Nom de programme ABAL"
#define it_Auto585   ""
#define es_Auto585   ""
#define de_Auto585   ""
#define nl_Auto585   ""
#define pt_Auto585   ""
#define xx_Auto585   ""
#define en_Auto586   "Command Line Parameters"
#define fr_Auto586   "ParamŠtres de la ligne de commande"
#define it_Auto586   ""
#define es_Auto586   ""
#define de_Auto586   ""
#define nl_Auto586   ""
#define pt_Auto586   ""
#define xx_Auto586   ""
#define en_Auto588   "Debug Root Path"
#define fr_Auto588   "Chemin racine d'acces aux sources"
#define it_Auto588   ""
#define es_Auto588   ""
#define de_Auto588   ""
#define nl_Auto588   ""
#define pt_Auto588   ""
#define xx_Auto588   ""
#define en_Select   "&Select"
#define fr_Select   "&Choisir"
#define it_Select   ""
#define es_Select   ""
#define de_Select   ""
#define nl_Select   ""
#define pt_Select   ""
#define xx_Select   ""
#define en_IsDebug   "&Debug"
#define fr_IsDebug   "&Debug"
#define it_IsDebug   ""
#define es_IsDebug   ""
#define de_IsDebug   ""
#define nl_IsDebug   ""
#define pt_IsDebug   ""
#define xx_IsDebug   ""
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

private struct accept_debug_parameters_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto580[8];
	char * msg_Auto581[8];
	char * msg_Auto669[8];
	char * msg_Auto607[8];
	char * msg_Auto629[8];
	char * msg_Auto592[8];
	char * msg_Auto591[8];
	char * msg_Auto585[8];
	char * msg_Auto586[8];
	char * msg_Auto588[8];
	char	buffer_FileName[48];
	char	buffer_CommandLine[117];
	char * msg_Select[8];
	int	trigger_Select;
	char * msg_IsDebug[8];
	int	trigger_IsDebug;
	int	value_IsDebug;
	char	buffer_Debugger[59];
	char	buffer_DebugRoot[59];
	char	buffer_Runtime[59];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[7];
	} * _Context;

private	int	accept_debug_parameters_create(
	char * pFileName,
	char * pCommandLine,
	char * pIsDebug,
	char * pDebugger,
	char * pDebugRoot,
	char * pRuntime)
{

	int i;
	if (!(_Context = allocate( sizeof( struct accept_debug_parameters_context ) ) ))
		return(27);
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=10;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 47, pFileName);
		visual_transferin(_Context->buffer_CommandLine, 116, pCommandLine);
		visual_transferin((void *) 0, 0, pIsDebug);
		if (!( pIsDebug )) _Context->value_IsDebug=0;
		else	_Context->value_IsDebug = *((int *)pIsDebug);
		visual_transferin(_Context->buffer_Debugger, 58, pDebugger);
		visual_transferin(_Context->buffer_DebugRoot, 58, pDebugRoot);
		visual_transferin(_Context->buffer_Runtime, 58, pRuntime);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto580[i]=" ";
	_Context->msg_Auto580[0]=en_Auto580;
	_Context->msg_Auto580[1]=fr_Auto580;
	_Context->msg_Auto580[2]=it_Auto580;
	_Context->msg_Auto580[3]=es_Auto580;
	_Context->msg_Auto580[4]=de_Auto580;
	_Context->msg_Auto580[5]=nl_Auto580;
	_Context->msg_Auto580[6]=pt_Auto580;
	_Context->msg_Auto580[7]=xx_Auto580;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto581[i]=" ";
	_Context->msg_Auto581[0]=en_Auto581;
	_Context->msg_Auto581[1]=fr_Auto581;
	_Context->msg_Auto581[2]=it_Auto581;
	_Context->msg_Auto581[3]=es_Auto581;
	_Context->msg_Auto581[4]=de_Auto581;
	_Context->msg_Auto581[5]=nl_Auto581;
	_Context->msg_Auto581[6]=pt_Auto581;
	_Context->msg_Auto581[7]=xx_Auto581;
	for (i=0; i < 8; i++)_Context->msg_Auto669[i]=" ";
	_Context->msg_Auto669[0]=en_Auto669;
	_Context->msg_Auto669[1]=fr_Auto669;
	_Context->msg_Auto669[2]=it_Auto669;
	_Context->msg_Auto669[3]=es_Auto669;
	_Context->msg_Auto669[4]=de_Auto669;
	_Context->msg_Auto669[5]=nl_Auto669;
	_Context->msg_Auto669[6]=pt_Auto669;
	_Context->msg_Auto669[7]=xx_Auto669;
	for (i=0; i < 8; i++)_Context->msg_Auto607[i]=" ";
	_Context->msg_Auto607[0]=en_Auto607;
	_Context->msg_Auto607[1]=fr_Auto607;
	_Context->msg_Auto607[2]=it_Auto607;
	_Context->msg_Auto607[3]=es_Auto607;
	_Context->msg_Auto607[4]=de_Auto607;
	_Context->msg_Auto607[5]=nl_Auto607;
	_Context->msg_Auto607[6]=pt_Auto607;
	_Context->msg_Auto607[7]=xx_Auto607;
	for (i=0; i < 8; i++)_Context->msg_Auto629[i]=" ";
	_Context->msg_Auto629[0]=en_Auto629;
	_Context->msg_Auto629[1]=fr_Auto629;
	_Context->msg_Auto629[2]=it_Auto629;
	_Context->msg_Auto629[3]=es_Auto629;
	_Context->msg_Auto629[4]=de_Auto629;
	_Context->msg_Auto629[5]=nl_Auto629;
	_Context->msg_Auto629[6]=pt_Auto629;
	_Context->msg_Auto629[7]=xx_Auto629;
	for (i=0; i < 8; i++)_Context->msg_Auto592[i]=" ";
	_Context->msg_Auto592[0]=en_Auto592;
	_Context->msg_Auto592[1]=fr_Auto592;
	_Context->msg_Auto592[2]=it_Auto592;
	_Context->msg_Auto592[3]=es_Auto592;
	_Context->msg_Auto592[4]=de_Auto592;
	_Context->msg_Auto592[5]=nl_Auto592;
	_Context->msg_Auto592[6]=pt_Auto592;
	_Context->msg_Auto592[7]=xx_Auto592;
	for (i=0; i < 8; i++)_Context->msg_Auto591[i]=" ";
	_Context->msg_Auto591[0]=en_Auto591;
	_Context->msg_Auto591[1]=fr_Auto591;
	_Context->msg_Auto591[2]=it_Auto591;
	_Context->msg_Auto591[3]=es_Auto591;
	_Context->msg_Auto591[4]=de_Auto591;
	_Context->msg_Auto591[5]=nl_Auto591;
	_Context->msg_Auto591[6]=pt_Auto591;
	_Context->msg_Auto591[7]=xx_Auto591;
	for (i=0; i < 8; i++)_Context->msg_Auto585[i]=" ";
	_Context->msg_Auto585[0]=en_Auto585;
	_Context->msg_Auto585[1]=fr_Auto585;
	_Context->msg_Auto585[2]=it_Auto585;
	_Context->msg_Auto585[3]=es_Auto585;
	_Context->msg_Auto585[4]=de_Auto585;
	_Context->msg_Auto585[5]=nl_Auto585;
	_Context->msg_Auto585[6]=pt_Auto585;
	_Context->msg_Auto585[7]=xx_Auto585;
	for (i=0; i < 8; i++)_Context->msg_Auto586[i]=" ";
	_Context->msg_Auto586[0]=en_Auto586;
	_Context->msg_Auto586[1]=fr_Auto586;
	_Context->msg_Auto586[2]=it_Auto586;
	_Context->msg_Auto586[3]=es_Auto586;
	_Context->msg_Auto586[4]=de_Auto586;
	_Context->msg_Auto586[5]=nl_Auto586;
	_Context->msg_Auto586[6]=pt_Auto586;
	_Context->msg_Auto586[7]=xx_Auto586;
	for (i=0; i < 8; i++)_Context->msg_Auto588[i]=" ";
	_Context->msg_Auto588[0]=en_Auto588;
	_Context->msg_Auto588[1]=fr_Auto588;
	_Context->msg_Auto588[2]=it_Auto588;
	_Context->msg_Auto588[3]=es_Auto588;
	_Context->msg_Auto588[4]=de_Auto588;
	_Context->msg_Auto588[5]=nl_Auto588;
	_Context->msg_Auto588[6]=pt_Auto588;
	_Context->msg_Auto588[7]=xx_Auto588;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	_Context->msg_Select[2]=it_Select;
	_Context->msg_Select[3]=es_Select;
	_Context->msg_Select[4]=de_Select;
	_Context->msg_Select[5]=nl_Select;
	_Context->msg_Select[6]=pt_Select;
	_Context->msg_Select[7]=xx_Select;
	for (i=0; i < 8; i++)_Context->msg_IsDebug[i]=" ";
	_Context->msg_IsDebug[0]=en_IsDebug;
	_Context->msg_IsDebug[1]=fr_IsDebug;
	_Context->msg_IsDebug[2]=it_IsDebug;
	_Context->msg_IsDebug[3]=es_IsDebug;
	_Context->msg_IsDebug[4]=de_IsDebug;
	_Context->msg_IsDebug[5]=nl_IsDebug;
	_Context->msg_IsDebug[6]=pt_IsDebug;
	_Context->msg_IsDebug[7]=xx_IsDebug;
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
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(135,75,530+10,450+10);
	return(0);
}

private	int	accept_debug_parameters_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,135,75);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_debug_parameters_remove(
	char * pFileName,
	char * pCommandLine,
	char * pIsDebug,
	char * pDebugger,
	char * pDebugRoot,
	char * pRuntime)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 47, pFileName);
		visual_transferout(_Context->buffer_CommandLine, 116, pCommandLine);
		visual_transferout((void *) 0, 0, pIsDebug);
		if ( pIsDebug != (char *) 0)
			*((int*)pIsDebug) = _Context->value_IsDebug;
		visual_transferout(_Context->buffer_Debugger, 58, pDebugger);
		visual_transferout(_Context->buffer_DebugRoot, 58, pDebugRoot);
		visual_transferout(_Context->buffer_Runtime, 58, pRuntime);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_debug_parameters_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,135,75);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(135,75,530,450,2,_Context->msg_Auto580[_Context->language],strlen(_Context->msg_Auto580[_Context->language]),0x407);
	visual_image(140,96,520,424,_Context->msg_Auto581[_Context->language],4);
	visual_frame(333,469,136,25,2);
	visual_text(165,105,370,30,3,27,0,_Context->msg_Auto669[_Context->language],strlen(_Context->msg_Auto669[_Context->language]),1538);
	visual_text(165,295,470,20,2,27,0,_Context->msg_Auto607[_Context->language],strlen(_Context->msg_Auto607[_Context->language]),2);
	visual_text(165,395,470,20,2,27,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),2);
	visual_image(545,95,40,60,_Context->msg_Auto592[_Context->language],3);
	visual_image(585,95,50,60,_Context->msg_Auto591[_Context->language],3);
	visual_text(165,155,470,20,2,27,0,_Context->msg_Auto585[_Context->language],strlen(_Context->msg_Auto585[_Context->language]),2);
	visual_text(165,205,470,20,2,27,0,_Context->msg_Auto586[_Context->language],strlen(_Context->msg_Auto586[_Context->language]),2);
	visual_text(165,345,470,20,2,27,0,_Context->msg_Auto588[_Context->language],strlen(_Context->msg_Auto588[_Context->language]),2);
	visual_frame(165,175,380+2,20+2,5);
	visual_text(165+1,175+1,380,20,1,16,0,_Context->buffer_FileName,47,0);
	visual_frame(165,225,470+2,40+2,5);
	visual_text(165+1,225+1,470,40,1,16,28,_Context->buffer_CommandLine,116,0);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(555,165,84,32,2,27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	_Context->trigger_IsDebug=visual_trigger_code(_Context->msg_IsDebug[_Context->language],strlen(_Context->msg_IsDebug[_Context->language]));
	visual_check(345,475,116,17,2,16,0,_Context->msg_IsDebug[_Context->language],strlen(_Context->msg_IsDebug[_Context->language]),_Context->value_IsDebug|0);
	visual_frame(165,315,470+2,20+2,5);
	visual_text(165+1,315+1,470,20,1,16,28,_Context->buffer_Debugger,58,0);
	visual_frame(165,365,470+2,20+2,5);
	visual_text(165+1,365+1,470,20,1,16,28,_Context->buffer_DebugRoot,58,0);
	visual_frame(165,415,470+2,20+2,5);
	visual_text(165+1,415+1,470,20,1,16,28,_Context->buffer_Runtime,58,0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(165,465,140,30,2,16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(495,465,140,30,2,16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_thaw(135,75,530,450);

	return(0);
}
private int on_Select_event() {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_AT);
	accept_debug_parameters_show();
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


private	int	accept_debug_parameters_event()
{
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Select == mb ) return(4);
		if (_Context->trigger_IsDebug == mb ) return(5);
		if (_Context->trigger_Accept == mb ) return(9);
		if (_Context->trigger_Cancel == mb ) return(10);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (mt & _MIMO_UP) {
	if ((mx >= 644 )  
	&&  (my >= 79 )  
	&&  (mx <= 660 )  
	&&  (my <= 95 )) {
		return(1);	/* Auto580 */

		}
	if ((mx >= 628 )  
	&&  (my >= 79 )  
	&&  (mx <= 644 )  
	&&  (my <= 95 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vdebug.htm");
			};
		return(-1);	/* Auto580 */

		}
	if ((mx >= 612 )  
	&&  (my >= 79 )  
	&&  (mx <= 628 )  
	&&  (my <= 95 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		_Context->language--; _Context->language %=8;
			}
		(void) visual_national_language(_Context->language);
		accept_debug_parameters_show();
		return(-1);	/* Auto580 */

		}
		}
	if (( mx >= 165 ) 
	&&  ( my >= 175 ) 
	&&  ( mx <= 545 ) 
	&&  ( my <= 195 )) {
		return(2); /* FileName */
		}
	if (( mx >= 165 ) 
	&&  ( my >= 225 ) 
	&&  ( mx <= 635 ) 
	&&  ( my <= 265 )) {
		return(3); /* CommandLine */
		}
	if (( mx >= 555 ) 
	&&  ( my >= 165 ) 
	&&  ( mx <= 639 ) 
	&&  ( my <= 197 )) {
		return(4); /* Select */
		}
	if (( mx >= 345 ) 
	&&  ( my >= 475 ) 
	&&  ( mx <= 461 ) 
	&&  ( my <= 492 )) {
		return(5); /* IsDebug */
		}
	if (( mx >= 165 ) 
	&&  ( my >= 315 ) 
	&&  ( mx <= 635 ) 
	&&  ( my <= 335 )) {
		return(6); /* Debugger */
		}
	if (( mx >= 165 ) 
	&&  ( my >= 365 ) 
	&&  ( mx <= 635 ) 
	&&  ( my <= 385 )) {
		return(7); /* DebugRoot */
		}
	if (( mx >= 165 ) 
	&&  ( my >= 415 ) 
	&&  ( mx <= 635 ) 
	&&  ( my <= 435 )) {
		return(8); /* Runtime */
		}
	if (( mx >= 165 ) 
	&&  ( my >= 465 ) 
	&&  ( mx <= 305 ) 
	&&  ( my <= 495 )) {
		return(9); /* Accept */
		}
	if (( mx >= 495 ) 
	&&  ( my >= 465 ) 
	&&  ( mx <= 635 ) 
	&&  ( my <= 495 )) {
		return(10); /* Cancel */
		}

	return(-1);
}


private	int	accept_debug_parameters_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(165+1,175+1,380,20,1,_Context->buffer_FileName,47);
				break;
			case	0x3 :
				/* CommandLine */
				_Context->keycode = visual_edit(165+1,225+1,470,40,1,_Context->buffer_CommandLine,116);
				break;
			case	0x4 :
				/* Select */
				visual_button(555,165,84,32,2,27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(555,165,84,32,2,27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0x5 :
				/* IsDebug */
				visual_check(345,475,116,17,2,16,0,_Context->msg_IsDebug[_Context->language],strlen(_Context->msg_IsDebug[_Context->language]),(_Context->value_IsDebug |2));
				_Context->keycode = visual_getch();
				visual_check(345,475,116,17,2,16,0,_Context->msg_IsDebug[_Context->language],strlen(_Context->msg_IsDebug[_Context->language]),(_Context->value_IsDebug |0));
				break;
			case	0x6 :
				/* Debugger */
				_Context->keycode = visual_edit(165+1,315+1,470,20,1,_Context->buffer_Debugger,58);
				break;
			case	0x7 :
				/* DebugRoot */
				_Context->keycode = visual_edit(165+1,365+1,470,20,1,_Context->buffer_DebugRoot,58);
				break;
			case	0x8 :
				/* Runtime */
				_Context->keycode = visual_edit(165+1,415+1,470,20,1,_Context->buffer_Runtime,58);
				break;
			case	0x9 :
				/* Accept */
				visual_button(165,465,140,30,2,16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(165,465,140,30,2,16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0xa :
				/* Cancel */
				visual_button(495,465,140,30,2,16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(495,465,140,30,2,16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_debug_parameters_show();
			continue;
		case	0x2 :
			_Context->focus_item=10;
			accept_debug_parameters_show();
			continue;
			case	0x100 :
				if ((retcode=accept_debug_parameters_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto580 */
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
						/* CommandLine */
						continue;
					case	0x4 :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(555,165,84,32,2,27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(555,165,84,32,2,27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Select_event()) != -1) break;

							}
						continue;
					case	0x5 :
						/* IsDebug */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsDebug += 1;
							_Context->value_IsDebug &= 1;
							}
						continue;
					case	0x6 :
						/* Debugger */
						continue;
					case	0x7 :
						/* DebugRoot */
						continue;
					case	0x8 :
						/* Runtime */
						continue;
					case	0x9 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(165,465,140,30,2,16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(165,465,140,30,2,16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0xa :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(495,465,140,30,2,16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(495,465,140,30,2,16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

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

public	int	accept_debug_parameters(
	char * pFileName,
	char * pCommandLine,
	char * pIsDebug,
	char * pDebugger,
	char * pDebugRoot,
	char * pRuntime)
{
	int	status=0;
	status = accept_debug_parameters_create(
	 pFileName,
	 pCommandLine,
	 pIsDebug,
	 pDebugger,
	 pDebugRoot,
	 pRuntime);
	if ( status != 0) return(status);
	status = accept_debug_parameters_show();
		enter_modal();
	status = accept_debug_parameters_focus();
		leave_modal();
	status = accept_debug_parameters_hide();
	status = accept_debug_parameters_remove(
	 pFileName,
	 pCommandLine,
	 pIsDebug,
	 pDebugger,
	 pDebugRoot,
	 pRuntime);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vdebug_c */
