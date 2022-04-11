
#ifndef _vdebug_c
#define _vdebug_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vdebug.xml  */
/* Target         : vdebug.c  */
/* Identification : 0.0-1100085240-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
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
#define en_Auto607   "Abal++ Debug Utility"
#define fr_Auto607   "Debuggeur ABAL"
#define en_Auto629   "Abal++ Runtime"
#define fr_Auto629   "Executeur ABAL"
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
#define en_Auto586   "Command Line Parameters"
#define fr_Auto586   "ParamŠtres de la ligne de commande"
#define en_Auto588   "Debug Root Path"
#define fr_Auto588   "Chemin racine d'acces aux sources"
#define en_Select   "&Select"
#define fr_Select   "&Choisir"
#define en_IsDebug   "&Debug"
#define fr_IsDebug   "&Debug"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
static int	vfh[10];

private struct accept_debug_parameters_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto580[8];
	int	x_Auto580;
	int	y_Auto580;
	int	w_Auto580;
	int	h_Auto580;
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
	};

public	int	accept_debug_parameters_create(
	struct accept_debug_parameters_context ** cptr,
	char * pFileName,
	char * pCommandLine,
	char * pIsDebug,
	char * pDebugger,
	char * pDebugRoot,
	char * pRuntime)
{

	int i;
	struct accept_debug_parameters_context * _Context=(struct accept_debug_parameters_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_debug_parameters_context ) ) ))
		return(27);
	else	*cptr=_Context;
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
	_Context->x_Auto580=135;
	_Context->y_Auto580=75;
	_Context->w_Auto580=530;
	_Context->h_Auto580=450;
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
	for (i=0; i < 8; i++)_Context->msg_Auto607[i]=" ";
	_Context->msg_Auto607[0]=en_Auto607;
	_Context->msg_Auto607[1]=fr_Auto607;
	for (i=0; i < 8; i++)_Context->msg_Auto629[i]=" ";
	_Context->msg_Auto629[0]=en_Auto629;
	_Context->msg_Auto629[1]=fr_Auto629;
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
	for (i=0; i < 8; i++)_Context->msg_Auto586[i]=" ";
	_Context->msg_Auto586[0]=en_Auto586;
	_Context->msg_Auto586[1]=fr_Auto586;
	for (i=0; i < 8; i++)_Context->msg_Auto588[i]=" ";
	_Context->msg_Auto588[0]=en_Auto588;
	_Context->msg_Auto588[1]=fr_Auto588;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	for (i=0; i < 8; i++)_Context->msg_IsDebug[i]=" ";
	_Context->msg_IsDebug[0]=en_IsDebug;
	_Context->msg_IsDebug[1]=fr_IsDebug;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto580,_Context->y_Auto580,530+10,450+10);
	return(0);
}

public 	int	accept_debug_parameters_hide(struct accept_debug_parameters_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto580,_Context->y_Auto580);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_debug_parameters_remove(
	struct accept_debug_parameters_context * _Context,
	char * pFileName,
	char * pCommandLine,
	char * pIsDebug,
	char * pDebugger,
	char * pDebugRoot,
	char * pRuntime)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
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

public	int	accept_debug_parameters_show(struct accept_debug_parameters_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto580,_Context->y_Auto580);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto580,_Context->y_Auto580,530,450,vfh[2],_Context->msg_Auto580[_Context->language],strlen(_Context->msg_Auto580[_Context->language]),0x407);
	visual_image(_Context->x_Auto580+5,_Context->y_Auto580+21,520,424,_Context->msg_Auto581[_Context->language],4);
	visual_frame(_Context->x_Auto580+198,_Context->y_Auto580+394,136,25,2);
	visual_text(_Context->x_Auto580+30,_Context->y_Auto580+30,370,30,vfh[3],27,0,_Context->msg_Auto669[_Context->language],strlen(_Context->msg_Auto669[_Context->language]),1282);
	visual_text(_Context->x_Auto580+30,_Context->y_Auto580+220,470,20,vfh[2],27,0,_Context->msg_Auto607[_Context->language],strlen(_Context->msg_Auto607[_Context->language]),2);
	visual_text(_Context->x_Auto580+30,_Context->y_Auto580+320,470,20,vfh[2],27,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),2);
	visual_image(_Context->x_Auto580+410,_Context->y_Auto580+20,40,60,_Context->msg_Auto592[_Context->language],3);
	visual_image(_Context->x_Auto580+450,_Context->y_Auto580+20,50,60,_Context->msg_Auto591[_Context->language],3);
	visual_text(_Context->x_Auto580+30,_Context->y_Auto580+80,470,20,vfh[2],27,0,_Context->msg_Auto585[_Context->language],strlen(_Context->msg_Auto585[_Context->language]),2);
	visual_text(_Context->x_Auto580+30,_Context->y_Auto580+130,470,20,vfh[2],27,0,_Context->msg_Auto586[_Context->language],strlen(_Context->msg_Auto586[_Context->language]),2);
	visual_text(_Context->x_Auto580+30,_Context->y_Auto580+270,470,20,vfh[2],27,0,_Context->msg_Auto588[_Context->language],strlen(_Context->msg_Auto588[_Context->language]),2);
	visual_frame(_Context->x_Auto580+30,_Context->y_Auto580+100,380+2,20+2,5);
	visual_text(_Context->x_Auto580+30+1,_Context->y_Auto580+100+1,380,20,vfh[1],16,0,_Context->buffer_FileName,47,0);
	visual_frame(_Context->x_Auto580+30,_Context->y_Auto580+150,470+2,40+2,5);
	visual_text(_Context->x_Auto580+30+1,_Context->y_Auto580+150+1,470,40,vfh[1],16,28,_Context->buffer_CommandLine,116,0);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_Auto580+420,_Context->y_Auto580+90,84,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	_Context->trigger_IsDebug=visual_trigger_code(_Context->msg_IsDebug[_Context->language],strlen(_Context->msg_IsDebug[_Context->language]));
	visual_check(_Context->x_Auto580+210,_Context->y_Auto580+400,116,17,vfh[2],16,0,_Context->msg_IsDebug[_Context->language],strlen(_Context->msg_IsDebug[_Context->language]),_Context->value_IsDebug|0);
	visual_frame(_Context->x_Auto580+30,_Context->y_Auto580+240,470+2,20+2,5);
	visual_text(_Context->x_Auto580+30+1,_Context->y_Auto580+240+1,470,20,vfh[1],16,28,_Context->buffer_Debugger,58,0);
	visual_frame(_Context->x_Auto580+30,_Context->y_Auto580+290,470+2,20+2,5);
	visual_text(_Context->x_Auto580+30+1,_Context->y_Auto580+290+1,470,20,vfh[1],16,28,_Context->buffer_DebugRoot,58,0);
	visual_frame(_Context->x_Auto580+30,_Context->y_Auto580+340,470+2,20+2,5);
	visual_text(_Context->x_Auto580+30+1,_Context->y_Auto580+340+1,470,20,vfh[1],16,28,_Context->buffer_Runtime,58,0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto580+30,_Context->y_Auto580+390,140,30,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto580+360,_Context->y_Auto580+390,140,30,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_thaw(_Context->x_Auto580,_Context->y_Auto580,530,450);
	visual_thaw(_Context->x_Auto580,_Context->y_Auto580,530,450);

	return(0);
}

private int Auto580action(struct accept_debug_parameters_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_debug_parameters_hide(_Context);

		_Context->x_Auto580 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto580 < 0) { _Context->x_Auto580=0; }
		_Context->y_Auto580 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto580 < 0) { _Context->y_Auto580=0; }
			accept_debug_parameters_show(_Context);

		visual_thaw(_Context->x_Auto580,_Context->y_Auto580,530,450);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Select_event(struct accept_debug_parameters_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_AT);
		accept_debug_parameters_show(_Context);
;
	return(-1);
}
private int on_Accept_event(struct accept_debug_parameters_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_debug_parameters_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_debug_parameters_event(
struct accept_debug_parameters_context * _Context){
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
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto580+509) )  
	&&  (my >= (_Context->y_Auto580+4) )  
	&&  (mx <= (_Context->x_Auto580+526) )  
	&&  (my <= (_Context->y_Auto580+20) )) {
		return(1);	/* Auto580 */

		}
	if ((mx >= (_Context->x_Auto580+493) )  
	&&  (my >= (_Context->y_Auto580+4) )  
	&&  (mx <= (_Context->x_Auto580+510) )  
	&&  (my <= (_Context->y_Auto580+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vdebug.htm");
			};
		return(-1);	/* Auto580 */

		}
	if ((mx >= (_Context->x_Auto580+477) )  
	&&  (my >= (_Context->y_Auto580+4) )  
	&&  (mx <= (_Context->x_Auto580+494) )  
	&&  (my <= (_Context->y_Auto580+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_debug_parameters_show(_Context);
		return(-1);	/* Auto580 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto580+4) )  
		&&  (my >= (_Context->y_Auto580+4) )  
		&&  (mx <= (_Context->x_Auto580+462) )  
		&&  (my <= (_Context->y_Auto580+20) )) {
			return( Auto580action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto580+30) ) 
	&&  ( my >= (_Context->y_Auto580+100) ) 
	&&  ( mx <= (_Context->x_Auto580+30+380) ) 
	&&  ( my <= (_Context->y_Auto580+100+20))) {
		return(2); /* FileName */
		}
	if (( mx >= (_Context->x_Auto580+30) ) 
	&&  ( my >= (_Context->y_Auto580+150) ) 
	&&  ( mx <= (_Context->x_Auto580+30+470) ) 
	&&  ( my <= (_Context->y_Auto580+150+40))) {
		return(3); /* CommandLine */
		}
	if (( mx >= (_Context->x_Auto580+420) ) 
	&&  ( my >= (_Context->y_Auto580+90) ) 
	&&  ( mx <= (_Context->x_Auto580+420+84) ) 
	&&  ( my <= (_Context->y_Auto580+90+32))) {
		return(4); /* Select */
		}
	if (( mx >= (_Context->x_Auto580+210) ) 
	&&  ( my >= (_Context->y_Auto580+400) ) 
	&&  ( mx <= (_Context->x_Auto580+210+116) ) 
	&&  ( my <= (_Context->y_Auto580+400+17))) {
		return(5); /* IsDebug */
		}
	if (( mx >= (_Context->x_Auto580+30) ) 
	&&  ( my >= (_Context->y_Auto580+240) ) 
	&&  ( mx <= (_Context->x_Auto580+30+470) ) 
	&&  ( my <= (_Context->y_Auto580+240+20))) {
		return(6); /* Debugger */
		}
	if (( mx >= (_Context->x_Auto580+30) ) 
	&&  ( my >= (_Context->y_Auto580+290) ) 
	&&  ( mx <= (_Context->x_Auto580+30+470) ) 
	&&  ( my <= (_Context->y_Auto580+290+20))) {
		return(7); /* DebugRoot */
		}
	if (( mx >= (_Context->x_Auto580+30) ) 
	&&  ( my >= (_Context->y_Auto580+340) ) 
	&&  ( mx <= (_Context->x_Auto580+30+470) ) 
	&&  ( my <= (_Context->y_Auto580+340+20))) {
		return(8); /* Runtime */
		}
	if (( mx >= (_Context->x_Auto580+30) ) 
	&&  ( my >= (_Context->y_Auto580+390) ) 
	&&  ( mx <= (_Context->x_Auto580+30+140) ) 
	&&  ( my <= (_Context->y_Auto580+390+30))) {
		return(9); /* Accept */
		}
	if (( mx >= (_Context->x_Auto580+360) ) 
	&&  ( my >= (_Context->y_Auto580+390) ) 
	&&  ( mx <= (_Context->x_Auto580+360+140) ) 
	&&  ( my <= (_Context->y_Auto580+390+30))) {
		return(10); /* Cancel */
		}

	return(-1);
}


public	int	accept_debug_parameters_focus(struct accept_debug_parameters_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_Auto580+30+1,_Context->y_Auto580+100+1,380,20,vfh[1],_Context->buffer_FileName,47);
			break;
			case	0x3 :
				/* CommandLine */
				_Context->keycode = visual_edit(_Context->x_Auto580+30+1,_Context->y_Auto580+150+1,470,40,vfh[1],_Context->buffer_CommandLine,116);
			break;
			case	0x4 :
				/* Select */
				visual_button(_Context->x_Auto580+420,_Context->y_Auto580+90,84,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto580+420,_Context->y_Auto580+90,84,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0x5 :
				/* IsDebug */
				visual_check(_Context->x_Auto580+210,_Context->y_Auto580+400,116,17,vfh[2],16,0,_Context->msg_IsDebug[_Context->language],strlen(_Context->msg_IsDebug[_Context->language]),(_Context->value_IsDebug |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto580+210,_Context->y_Auto580+400,116,17,vfh[2],16,0,_Context->msg_IsDebug[_Context->language],strlen(_Context->msg_IsDebug[_Context->language]),(_Context->value_IsDebug |0));
				break;
			case	0x6 :
				/* Debugger */
				_Context->keycode = visual_edit(_Context->x_Auto580+30+1,_Context->y_Auto580+240+1,470,20,vfh[1],_Context->buffer_Debugger,58);
			break;
			case	0x7 :
				/* DebugRoot */
				_Context->keycode = visual_edit(_Context->x_Auto580+30+1,_Context->y_Auto580+290+1,470,20,vfh[1],_Context->buffer_DebugRoot,58);
			break;
			case	0x8 :
				/* Runtime */
				_Context->keycode = visual_edit(_Context->x_Auto580+30+1,_Context->y_Auto580+340+1,470,20,vfh[1],_Context->buffer_Runtime,58);
			break;
			case	0x9 :
				/* Accept */
				visual_button(_Context->x_Auto580+30,_Context->y_Auto580+390,140,30,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto580+30,_Context->y_Auto580+390,140,30,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0xa :
				/* Cancel */
				visual_button(_Context->x_Auto580+360,_Context->y_Auto580+390,140,30,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto580+360,_Context->y_Auto580+390,140,30,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_debug_parameters_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=10;
			accept_debug_parameters_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_debug_parameters_event(_Context)) == -1)
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
							visual_button(_Context->x_Auto580+420,_Context->y_Auto580+90,84,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto580+420,_Context->y_Auto580+90,84,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

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
							visual_button(_Context->x_Auto580+30,_Context->y_Auto580+390,140,30,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto580+30,_Context->y_Auto580+390,140,30,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0xa :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto580+360,_Context->y_Auto580+390,140,30,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto580+360,_Context->y_Auto580+390,140,30,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
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
	struct accept_debug_parameters_context * _Context=(struct accept_debug_parameters_context*) 0;
	status = accept_debug_parameters_create(
	&_Context,
	 pFileName,
	 pCommandLine,
	 pIsDebug,
	 pDebugger,
	 pDebugRoot,
	 pRuntime);
	if ( status != 0) return(status);
	status = accept_debug_parameters_show(_Context);
		enter_modal();
	status = accept_debug_parameters_focus(_Context);
		leave_modal();
	status = accept_debug_parameters_hide(_Context);
	status = accept_debug_parameters_remove(
	_Context,
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
