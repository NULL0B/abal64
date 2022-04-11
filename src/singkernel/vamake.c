
#ifndef _vamake_c
#define _vamake_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vamake.xml  */
/* Target         : vamake.c  */
/* Identification : 0.0-1100519154-5231.5230 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto5669   "Sing : Version 1.0a"
#define fr_Auto5669   "Sing : Version 1.0a"
#define it_Auto5669   "Sing : Version 1.0a"
#define es_Auto5669   "Sing : Version 1.0a"
#define de_Auto5669   "Sing : Version 1.0a"
#define nl_Auto5669   "Sing : Version 1.0a"
#define pt_Auto5669   "Sing : Version 1.0a"
#define xx_Auto5669   "Sing : Version 1.0a"
#define en_Auto5670   "skin.gif"
#define fr_Auto5670   "skin.gif"
#define it_Auto5670   "skin.gif"
#define es_Auto5670   "skin.gif"
#define de_Auto5670   "skin.gif"
#define nl_Auto5670   "skin.gif"
#define pt_Auto5670   "skin.gif"
#define xx_Auto5670   "skin.gif"
#define en_Auto5671   "Project Builder : Amake"
#define fr_Auto5671   "Construction de Projet : Amake"
#define en_Auto5672   "Program Tool Name"
#define fr_Auto5672   "Nom d'outil Programme"
#define en_Auto5680   "Make Filename"
#define fr_Auto5680   "Nom du fichier de construction"
#define en_Auto5673   "Output Name"
#define fr_Auto5673   "Fichier de sortie"
#define en_Auto5674   "Definitions"
#define fr_Auto5674   "D‚finitions"
#define xx_Auto5674   "Definitions"
#define en_ForceBuild   "&Force Build"
#define fr_ForceBuild   "&Forc‚e"
#define en_ShowDates   "&Show Dependance Dates"
#define fr_ShowDates   "&Dates de D‚pendance"
#define en_Touch_Only   "&Touch Only"
#define fr_Touch_Only   "&Touche"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Edit   "&Edit"
#define fr_Edit   "&Editer"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
static int	vfh[10];

private struct accept_amake_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto5669[8];
	int	x_Auto5669;
	int	y_Auto5669;
	int	w_Auto5669;
	int	h_Auto5669;
	char * msg_Auto5670[8];
	char * msg_Auto5671[8];
	char * msg_Auto5672[8];
	char * msg_Auto5680[8];
	char * msg_Auto5673[8];
	char * msg_Auto5674[8];
	char	buffer_ToolName[47];
	char	buffer_FileName[47];
	char	buffer_Output[47];
	char	buffer_Define[231];
	char * msg_ForceBuild[8];
	int	trigger_ForceBuild;
	int	value_ForceBuild;
	char * msg_ShowDates[8];
	int	trigger_ShowDates;
	int	value_ShowDates;
	char * msg_Touch_Only[8];
	int	trigger_Touch_Only;
	int	value_Touch_Only;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Edit[8];
	int	trigger_Edit;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[8];
	};

public	int	accept_amake_create(
	struct accept_amake_context ** cptr,
	char * pToolName,
	char * pFileName,
	char * pOutput,
	char * pDefine,
	char * pForceBuild,
	char * pShowDates,
	char * pTouch_Only)
{

	int i;
	struct accept_amake_context * _Context=(struct accept_amake_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_amake_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=11;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_ToolName, 46, pToolName);
		visual_transferin(_Context->buffer_FileName, 46, pFileName);
		visual_transferin(_Context->buffer_Output, 46, pOutput);
		visual_transferin(_Context->buffer_Define, 230, pDefine);
		visual_transferin((void *) 0, 0, pForceBuild);
		if (!( pForceBuild )) _Context->value_ForceBuild=0;
		else	_Context->value_ForceBuild = *((int *)pForceBuild);
		visual_transferin((void *) 0, 0, pShowDates);
		if (!( pShowDates )) _Context->value_ShowDates=0;
		else	_Context->value_ShowDates = *((int *)pShowDates);
		visual_transferin((void *) 0, 0, pTouch_Only);
		if (!( pTouch_Only )) _Context->value_Touch_Only=0;
		else	_Context->value_Touch_Only = *((int *)pTouch_Only);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto5669[i]=" ";
	_Context->msg_Auto5669[0]=en_Auto5669;
	_Context->msg_Auto5669[1]=fr_Auto5669;
	_Context->msg_Auto5669[2]=it_Auto5669;
	_Context->msg_Auto5669[3]=es_Auto5669;
	_Context->msg_Auto5669[4]=de_Auto5669;
	_Context->msg_Auto5669[5]=nl_Auto5669;
	_Context->msg_Auto5669[6]=pt_Auto5669;
	_Context->msg_Auto5669[7]=xx_Auto5669;
	_Context->x_Auto5669=110;
	_Context->y_Auto5669=100;
	_Context->w_Auto5669=580;
	_Context->h_Auto5669=400;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto5670[i]=" ";
	_Context->msg_Auto5670[0]=en_Auto5670;
	_Context->msg_Auto5670[1]=fr_Auto5670;
	_Context->msg_Auto5670[2]=it_Auto5670;
	_Context->msg_Auto5670[3]=es_Auto5670;
	_Context->msg_Auto5670[4]=de_Auto5670;
	_Context->msg_Auto5670[5]=nl_Auto5670;
	_Context->msg_Auto5670[6]=pt_Auto5670;
	_Context->msg_Auto5670[7]=xx_Auto5670;
	for (i=0; i < 8; i++)_Context->msg_Auto5671[i]=" ";
	_Context->msg_Auto5671[0]=en_Auto5671;
	_Context->msg_Auto5671[1]=fr_Auto5671;
	for (i=0; i < 8; i++)_Context->msg_Auto5672[i]=" ";
	_Context->msg_Auto5672[0]=en_Auto5672;
	_Context->msg_Auto5672[1]=fr_Auto5672;
	for (i=0; i < 8; i++)_Context->msg_Auto5680[i]=" ";
	_Context->msg_Auto5680[0]=en_Auto5680;
	_Context->msg_Auto5680[1]=fr_Auto5680;
	for (i=0; i < 8; i++)_Context->msg_Auto5673[i]=" ";
	_Context->msg_Auto5673[0]=en_Auto5673;
	_Context->msg_Auto5673[1]=fr_Auto5673;
	for (i=0; i < 8; i++)_Context->msg_Auto5674[i]=" ";
	_Context->msg_Auto5674[0]=en_Auto5674;
	_Context->msg_Auto5674[1]=fr_Auto5674;
	_Context->msg_Auto5674[7]=xx_Auto5674;
	for (i=0; i < 8; i++)_Context->msg_ForceBuild[i]=" ";
	_Context->msg_ForceBuild[0]=en_ForceBuild;
	_Context->msg_ForceBuild[1]=fr_ForceBuild;
	for (i=0; i < 8; i++)_Context->msg_ShowDates[i]=" ";
	_Context->msg_ShowDates[0]=en_ShowDates;
	_Context->msg_ShowDates[1]=fr_ShowDates;
	for (i=0; i < 8; i++)_Context->msg_Touch_Only[i]=" ";
	_Context->msg_Touch_Only[0]=en_Touch_Only;
	_Context->msg_Touch_Only[1]=fr_Touch_Only;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Edit[i]=" ";
	_Context->msg_Edit[0]=en_Edit;
	_Context->msg_Edit[1]=fr_Edit;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto5669,_Context->y_Auto5669,580,400);
	return(0);
}

public 	int	accept_amake_hide(struct accept_amake_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto5669,_Context->y_Auto5669);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_amake_remove(
	struct accept_amake_context * _Context,
	char * pToolName,
	char * pFileName,
	char * pOutput,
	char * pDefine,
	char * pForceBuild,
	char * pShowDates,
	char * pTouch_Only)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_ToolName, 46, pToolName);
		visual_transferout(_Context->buffer_FileName, 46, pFileName);
		visual_transferout(_Context->buffer_Output, 46, pOutput);
		visual_transferout(_Context->buffer_Define, 230, pDefine);
		visual_transferout((void *) 0, 0, pForceBuild);
		if ( pForceBuild != (char *) 0)
			*((int*)pForceBuild) = _Context->value_ForceBuild;
		visual_transferout((void *) 0, 0, pShowDates);
		if ( pShowDates != (char *) 0)
			*((int*)pShowDates) = _Context->value_ShowDates;
		visual_transferout((void *) 0, 0, pTouch_Only);
		if ( pTouch_Only != (char *) 0)
			*((int*)pTouch_Only) = _Context->value_Touch_Only;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_amake_show(struct accept_amake_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto5669,_Context->y_Auto5669);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto5669,_Context->y_Auto5669,580,400,vfh[2],_Context->msg_Auto5669[_Context->language],strlen(_Context->msg_Auto5669[_Context->language]),0x7);
	visual_image(_Context->x_Auto5669+3,_Context->y_Auto5669+22,574,374,_Context->msg_Auto5670[_Context->language],4);
	visual_text(_Context->x_Auto5669+30,_Context->y_Auto5669+30,510,30,vfh[4],16,0,_Context->msg_Auto5671[_Context->language],strlen(_Context->msg_Auto5671[_Context->language]),1283);
	visual_text(_Context->x_Auto5669+20,_Context->y_Auto5669+80,154,16,vfh[2],16,0,_Context->msg_Auto5672[_Context->language],strlen(_Context->msg_Auto5672[_Context->language]),258);
	visual_text(_Context->x_Auto5669+20,_Context->y_Auto5669+120,154,16,vfh[2],16,0,_Context->msg_Auto5680[_Context->language],strlen(_Context->msg_Auto5680[_Context->language]),258);
	visual_text(_Context->x_Auto5669+20,_Context->y_Auto5669+160,154,16,vfh[2],16,0,_Context->msg_Auto5673[_Context->language],strlen(_Context->msg_Auto5673[_Context->language]),258);
	visual_text(_Context->x_Auto5669+20,_Context->y_Auto5669+200,154,16,vfh[2],16,0,_Context->msg_Auto5674[_Context->language],strlen(_Context->msg_Auto5674[_Context->language]),258);
	visual_frame(_Context->x_Auto5669+180,_Context->y_Auto5669+80,368+2,16+2,5);
	visual_text(_Context->x_Auto5669+180+1,_Context->y_Auto5669+80+1,368,16,vfh[1],16,0,_Context->buffer_ToolName,46,0);
	visual_frame(_Context->x_Auto5669+180,_Context->y_Auto5669+120,368+2,16+2,5);
	visual_text(_Context->x_Auto5669+180+1,_Context->y_Auto5669+120+1,368,16,vfh[1],16,0,_Context->buffer_FileName,46,0);
	visual_frame(_Context->x_Auto5669+180,_Context->y_Auto5669+160,368+2,16+2,5);
	visual_text(_Context->x_Auto5669+180+1,_Context->y_Auto5669+160+1,368,16,vfh[1],16,0,_Context->buffer_Output,46,0);
	visual_frame(_Context->x_Auto5669+180,_Context->y_Auto5669+200,368+2,80+2,5);
	visual_text(_Context->x_Auto5669+180+1,_Context->y_Auto5669+200+1,368,80,vfh[1],16,0,_Context->buffer_Define,230,0);
	_Context->trigger_ForceBuild=visual_trigger_code(_Context->msg_ForceBuild[_Context->language],strlen(_Context->msg_ForceBuild[_Context->language]));
	visual_check(_Context->x_Auto5669+20,_Context->y_Auto5669+290,154,32,vfh[2],16,0,_Context->msg_ForceBuild[_Context->language],strlen(_Context->msg_ForceBuild[_Context->language]),_Context->value_ForceBuild|0);
	_Context->trigger_ShowDates=visual_trigger_code(_Context->msg_ShowDates[_Context->language],strlen(_Context->msg_ShowDates[_Context->language]));
	visual_check(_Context->x_Auto5669+180,_Context->y_Auto5669+290,238,32,vfh[2],16,0,_Context->msg_ShowDates[_Context->language],strlen(_Context->msg_ShowDates[_Context->language]),_Context->value_ShowDates|0);
	_Context->trigger_Touch_Only=visual_trigger_code(_Context->msg_Touch_Only[_Context->language],strlen(_Context->msg_Touch_Only[_Context->language]));
	visual_check(_Context->x_Auto5669+420,_Context->y_Auto5669+290,126,32,vfh[2],16,0,_Context->msg_Touch_Only[_Context->language],strlen(_Context->msg_Touch_Only[_Context->language]),_Context->value_Touch_Only|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto5669+30,_Context->y_Auto5669+340,126,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(_Context->x_Auto5669+230,_Context->y_Auto5669+340,126,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto5669+420,_Context->y_Auto5669+340,126,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_thaw(_Context->x_Auto5669,_Context->y_Auto5669,580,400);
	visual_thaw(_Context->x_Auto5669,_Context->y_Auto5669,580,400);

	return(0);
}

private int Auto5669action(struct accept_amake_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_amake_hide(_Context);

		_Context->x_Auto5669 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto5669 < 0) { _Context->x_Auto5669=0; }
		_Context->y_Auto5669 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto5669 < 0) { _Context->y_Auto5669=0; }
			accept_amake_show(_Context);

		visual_thaw(_Context->x_Auto5669,_Context->y_Auto5669,580,400);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_amake_context * _Context) {
	return(13);
	return(-1);
}
private int on_Edit_event(struct accept_amake_context * _Context) {
		accept_amake_hide(_Context);
;
	use_editor(_Context->buffer_FileName,0);
		accept_amake_show(_Context);
;
	return(-1);
}
private int on_Cancel_event(struct accept_amake_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_amake_event(
struct accept_amake_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_ForceBuild == mb ) return(6);
		if (_Context->trigger_ShowDates == mb ) return(7);
		if (_Context->trigger_Touch_Only == mb ) return(8);
		if (_Context->trigger_Accept == mb ) return(9);
		if (_Context->trigger_Edit == mb ) return(10);
		if (_Context->trigger_Cancel == mb ) return(11);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto5669+559) )  
	&&  (my >= (_Context->y_Auto5669+4) )  
	&&  (mx <= (_Context->x_Auto5669+576) )  
	&&  (my <= (_Context->y_Auto5669+20) )) {
		return(1);	/* Auto5669 */

		}
	if ((mx >= (_Context->x_Auto5669+543) )  
	&&  (my >= (_Context->y_Auto5669+4) )  
	&&  (mx <= (_Context->x_Auto5669+560) )  
	&&  (my <= (_Context->y_Auto5669+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vamake.htm");
			};
		return(-1);	/* Auto5669 */

		}
	if ((mx >= (_Context->x_Auto5669+527) )  
	&&  (my >= (_Context->y_Auto5669+4) )  
	&&  (mx <= (_Context->x_Auto5669+544) )  
	&&  (my <= (_Context->y_Auto5669+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_amake_show(_Context);
		return(-1);	/* Auto5669 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto5669+4) )  
		&&  (my >= (_Context->y_Auto5669+4) )  
		&&  (mx <= (_Context->x_Auto5669+512) )  
		&&  (my <= (_Context->y_Auto5669+20) )) {
			return( Auto5669action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto5669+180) ) 
	&&  ( my >= (_Context->y_Auto5669+80) ) 
	&&  ( mx <= (_Context->x_Auto5669+180+368) ) 
	&&  ( my <= (_Context->y_Auto5669+80+16))) {
		return(2); /* ToolName */
		}
	if (( mx >= (_Context->x_Auto5669+180) ) 
	&&  ( my >= (_Context->y_Auto5669+120) ) 
	&&  ( mx <= (_Context->x_Auto5669+180+368) ) 
	&&  ( my <= (_Context->y_Auto5669+120+16))) {
		return(3); /* FileName */
		}
	if (( mx >= (_Context->x_Auto5669+180) ) 
	&&  ( my >= (_Context->y_Auto5669+160) ) 
	&&  ( mx <= (_Context->x_Auto5669+180+368) ) 
	&&  ( my <= (_Context->y_Auto5669+160+16))) {
		return(4); /* Output */
		}
	if (( mx >= (_Context->x_Auto5669+180) ) 
	&&  ( my >= (_Context->y_Auto5669+200) ) 
	&&  ( mx <= (_Context->x_Auto5669+180+368) ) 
	&&  ( my <= (_Context->y_Auto5669+200+80))) {
		return(5); /* Define */
		}
	if (( mx >= (_Context->x_Auto5669+20) ) 
	&&  ( my >= (_Context->y_Auto5669+290) ) 
	&&  ( mx <= (_Context->x_Auto5669+20+154) ) 
	&&  ( my <= (_Context->y_Auto5669+290+32))) {
		return(6); /* ForceBuild */
		}
	if (( mx >= (_Context->x_Auto5669+180) ) 
	&&  ( my >= (_Context->y_Auto5669+290) ) 
	&&  ( mx <= (_Context->x_Auto5669+180+238) ) 
	&&  ( my <= (_Context->y_Auto5669+290+32))) {
		return(7); /* ShowDates */
		}
	if (( mx >= (_Context->x_Auto5669+420) ) 
	&&  ( my >= (_Context->y_Auto5669+290) ) 
	&&  ( mx <= (_Context->x_Auto5669+420+126) ) 
	&&  ( my <= (_Context->y_Auto5669+290+32))) {
		return(8); /* Touch_Only */
		}
	if (( mx >= (_Context->x_Auto5669+30) ) 
	&&  ( my >= (_Context->y_Auto5669+340) ) 
	&&  ( mx <= (_Context->x_Auto5669+30+126) ) 
	&&  ( my <= (_Context->y_Auto5669+340+32))) {
		return(9); /* Accept */
		}
	if (( mx >= (_Context->x_Auto5669+230) ) 
	&&  ( my >= (_Context->y_Auto5669+340) ) 
	&&  ( mx <= (_Context->x_Auto5669+230+126) ) 
	&&  ( my <= (_Context->y_Auto5669+340+32))) {
		return(10); /* Edit */
		}
	if (( mx >= (_Context->x_Auto5669+420) ) 
	&&  ( my >= (_Context->y_Auto5669+340) ) 
	&&  ( mx <= (_Context->x_Auto5669+420+126) ) 
	&&  ( my <= (_Context->y_Auto5669+340+32))) {
		return(11); /* Cancel */
		}

	return(-1);
}


public	int	accept_amake_focus(struct accept_amake_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* ToolName */
				_Context->keycode = visual_edit(_Context->x_Auto5669+180+1,_Context->y_Auto5669+80+1,368,16,vfh[1],_Context->buffer_ToolName,46);
			break;
			case	0x3 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_Auto5669+180+1,_Context->y_Auto5669+120+1,368,16,vfh[1],_Context->buffer_FileName,46);
			break;
			case	0x4 :
				/* Output */
				_Context->keycode = visual_edit(_Context->x_Auto5669+180+1,_Context->y_Auto5669+160+1,368,16,vfh[1],_Context->buffer_Output,46);
			break;
			case	0x5 :
				/* Define */
				_Context->keycode = visual_edit(_Context->x_Auto5669+180+1,_Context->y_Auto5669+200+1,368,80,vfh[1],_Context->buffer_Define,230);
			break;
			case	0x6 :
				/* ForceBuild */
				visual_check(_Context->x_Auto5669+20,_Context->y_Auto5669+290,154,32,vfh[2],16,0,_Context->msg_ForceBuild[_Context->language],strlen(_Context->msg_ForceBuild[_Context->language]),(_Context->value_ForceBuild |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto5669+20,_Context->y_Auto5669+290,154,32,vfh[2],16,0,_Context->msg_ForceBuild[_Context->language],strlen(_Context->msg_ForceBuild[_Context->language]),(_Context->value_ForceBuild |0));
				break;
			case	0x7 :
				/* ShowDates */
				visual_check(_Context->x_Auto5669+180,_Context->y_Auto5669+290,238,32,vfh[2],16,0,_Context->msg_ShowDates[_Context->language],strlen(_Context->msg_ShowDates[_Context->language]),(_Context->value_ShowDates |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto5669+180,_Context->y_Auto5669+290,238,32,vfh[2],16,0,_Context->msg_ShowDates[_Context->language],strlen(_Context->msg_ShowDates[_Context->language]),(_Context->value_ShowDates |0));
				break;
			case	0x8 :
				/* Touch_Only */
				visual_check(_Context->x_Auto5669+420,_Context->y_Auto5669+290,126,32,vfh[2],16,0,_Context->msg_Touch_Only[_Context->language],strlen(_Context->msg_Touch_Only[_Context->language]),(_Context->value_Touch_Only |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto5669+420,_Context->y_Auto5669+290,126,32,vfh[2],16,0,_Context->msg_Touch_Only[_Context->language],strlen(_Context->msg_Touch_Only[_Context->language]),(_Context->value_Touch_Only |0));
				break;
			case	0x9 :
				/* Accept */
				visual_button(_Context->x_Auto5669+30,_Context->y_Auto5669+340,126,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto5669+30,_Context->y_Auto5669+340,126,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0xa :
				/* Edit */
				visual_button(_Context->x_Auto5669+230,_Context->y_Auto5669+340,126,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto5669+230,_Context->y_Auto5669+340,126,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
				break;
			case	0xb :
				/* Cancel */
				visual_button(_Context->x_Auto5669+420,_Context->y_Auto5669+340,126,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto5669+420,_Context->y_Auto5669+340,126,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_amake_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=11;
			accept_amake_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_amake_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto5669 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* ToolName */
						continue;
					case	0x3 :
						/* FileName */
						continue;
					case	0x4 :
						/* Output */
						continue;
					case	0x5 :
						/* Define */
						continue;
					case	0x6 :
						/* ForceBuild */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_ForceBuild += 1;
							_Context->value_ForceBuild &= 1;
							}
						continue;
					case	0x7 :
						/* ShowDates */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_ShowDates += 1;
							_Context->value_ShowDates &= 1;
							}
						continue;
					case	0x8 :
						/* Touch_Only */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Touch_Only += 1;
							_Context->value_Touch_Only &= 1;
							}
						continue;
					case	0x9 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto5669+30,_Context->y_Auto5669+340,126,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto5669+30,_Context->y_Auto5669+340,126,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0xa :
						/* Edit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto5669+230,_Context->y_Auto5669+340,126,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto5669+230,_Context->y_Auto5669+340,126,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Edit_event(_Context)) != -1) break;

							}
						continue;
					case	0xb :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto5669+420,_Context->y_Auto5669+340,126,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto5669+420,_Context->y_Auto5669+340,126,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
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
				_Context->focus_item=11;
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

public	int	accept_amake(
	char * pToolName,
	char * pFileName,
	char * pOutput,
	char * pDefine,
	char * pForceBuild,
	char * pShowDates,
	char * pTouch_Only)
{
	int	status=0;
	struct accept_amake_context * _Context=(struct accept_amake_context*) 0;
	status = accept_amake_create(
	&_Context,
	 pToolName,
	 pFileName,
	 pOutput,
	 pDefine,
	 pForceBuild,
	 pShowDates,
	 pTouch_Only);
	if ( status != 0) return(status);
	status = accept_amake_show(_Context);
		enter_modal();
	status = accept_amake_focus(_Context);
		leave_modal();
	status = accept_amake_hide(_Context);
	status = accept_amake_remove(
	_Context,
	 pToolName,
	 pFileName,
	 pOutput,
	 pDefine,
	 pForceBuild,
	 pShowDates,
	 pTouch_Only);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vamake_c */
