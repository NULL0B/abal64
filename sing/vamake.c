
#ifndef _vamake_c
#define _vamake_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vamake.sng  */
/* Target         : vamake.c  */
/* Identification : 0.0-1065575122-3897.3896 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
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
#define fr_Auto5671   "Mise … Jour du Projet"
#define it_Auto5671   ""
#define es_Auto5671   ""
#define de_Auto5671   ""
#define nl_Auto5671   ""
#define pt_Auto5671   ""
#define xx_Auto5671   ""
#define en_Auto5672   "Program Tool Name"
#define fr_Auto5672   "Nom d'outil AMAKE"
#define it_Auto5672   ""
#define es_Auto5672   ""
#define de_Auto5672   ""
#define nl_Auto5672   ""
#define pt_Auto5672   ""
#define xx_Auto5672   ""
#define en_Auto5680   "Make Filename"
#define fr_Auto5680   "Nom de fichier projet"
#define it_Auto5680   ""
#define es_Auto5680   ""
#define de_Auto5680   ""
#define nl_Auto5680   ""
#define pt_Auto5680   ""
#define xx_Auto5680   ""
#define en_Auto5673   "Output Name"
#define fr_Auto5673   "Fichier de sortie"
#define it_Auto5673   ""
#define es_Auto5673   ""
#define de_Auto5673   ""
#define nl_Auto5673   ""
#define pt_Auto5673   ""
#define xx_Auto5673   ""
#define en_Auto5674   "Definitions"
#define fr_Auto5674   "Definitions"
#define it_Auto5674   "Definitions"
#define es_Auto5674   "Definitions"
#define de_Auto5674   "Definitions"
#define nl_Auto5674   "Definitions"
#define pt_Auto5674   "Definitions"
#define xx_Auto5674   "Definitions"
#define en_ForceBuild   "&Force Build"
#define fr_ForceBuild   "Mise … jour &Forc‚"
#define it_ForceBuild   ""
#define es_ForceBuild   ""
#define de_ForceBuild   ""
#define nl_ForceBuild   ""
#define pt_ForceBuild   ""
#define xx_ForceBuild   ""
#define en_ShowDates   "&Show Dependance Dates"
#define fr_ShowDates   "&Affichage des dates"
#define it_ShowDates   ""
#define es_ShowDates   ""
#define de_ShowDates   ""
#define nl_ShowDates   ""
#define pt_ShowDates   ""
#define xx_ShowDates   ""
#define en_Touch_Only   "&Touch Only"
#define fr_Touch_Only   "&Touche"
#define it_Touch_Only   ""
#define es_Touch_Only   ""
#define de_Touch_Only   ""
#define nl_Touch_Only   ""
#define pt_Touch_Only   ""
#define xx_Touch_Only   ""
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define it_Accept   ""
#define es_Accept   ""
#define de_Accept   ""
#define nl_Accept   ""
#define pt_Accept   ""
#define xx_Accept   ""
#define en_Edit   "&Edit"
#define fr_Edit   "&Editer"
#define it_Edit   ""
#define es_Edit   ""
#define de_Edit   ""
#define nl_Edit   ""
#define pt_Edit   ""
#define xx_Edit   ""
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"

private struct accept_amake_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto5669[8];
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
	} * _Context;

private	int	accept_amake_create(
	char * pToolName,
	char * pFileName,
	char * pOutput,
	char * pDefine,
	char * pForceBuild,
	char * pShowDates,
	char * pTouch_Only)
{

	int i;
	if (!(_Context = allocate( sizeof( struct accept_amake_context ) ) ))
		return(27);
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
	_Context->msg_Auto5671[2]=it_Auto5671;
	_Context->msg_Auto5671[3]=es_Auto5671;
	_Context->msg_Auto5671[4]=de_Auto5671;
	_Context->msg_Auto5671[5]=nl_Auto5671;
	_Context->msg_Auto5671[6]=pt_Auto5671;
	_Context->msg_Auto5671[7]=xx_Auto5671;
	for (i=0; i < 8; i++)_Context->msg_Auto5672[i]=" ";
	_Context->msg_Auto5672[0]=en_Auto5672;
	_Context->msg_Auto5672[1]=fr_Auto5672;
	_Context->msg_Auto5672[2]=it_Auto5672;
	_Context->msg_Auto5672[3]=es_Auto5672;
	_Context->msg_Auto5672[4]=de_Auto5672;
	_Context->msg_Auto5672[5]=nl_Auto5672;
	_Context->msg_Auto5672[6]=pt_Auto5672;
	_Context->msg_Auto5672[7]=xx_Auto5672;
	for (i=0; i < 8; i++)_Context->msg_Auto5680[i]=" ";
	_Context->msg_Auto5680[0]=en_Auto5680;
	_Context->msg_Auto5680[1]=fr_Auto5680;
	_Context->msg_Auto5680[2]=it_Auto5680;
	_Context->msg_Auto5680[3]=es_Auto5680;
	_Context->msg_Auto5680[4]=de_Auto5680;
	_Context->msg_Auto5680[5]=nl_Auto5680;
	_Context->msg_Auto5680[6]=pt_Auto5680;
	_Context->msg_Auto5680[7]=xx_Auto5680;
	for (i=0; i < 8; i++)_Context->msg_Auto5673[i]=" ";
	_Context->msg_Auto5673[0]=en_Auto5673;
	_Context->msg_Auto5673[1]=fr_Auto5673;
	_Context->msg_Auto5673[2]=it_Auto5673;
	_Context->msg_Auto5673[3]=es_Auto5673;
	_Context->msg_Auto5673[4]=de_Auto5673;
	_Context->msg_Auto5673[5]=nl_Auto5673;
	_Context->msg_Auto5673[6]=pt_Auto5673;
	_Context->msg_Auto5673[7]=xx_Auto5673;
	for (i=0; i < 8; i++)_Context->msg_Auto5674[i]=" ";
	_Context->msg_Auto5674[0]=en_Auto5674;
	_Context->msg_Auto5674[1]=fr_Auto5674;
	_Context->msg_Auto5674[2]=it_Auto5674;
	_Context->msg_Auto5674[3]=es_Auto5674;
	_Context->msg_Auto5674[4]=de_Auto5674;
	_Context->msg_Auto5674[5]=nl_Auto5674;
	_Context->msg_Auto5674[6]=pt_Auto5674;
	_Context->msg_Auto5674[7]=xx_Auto5674;
	for (i=0; i < 8; i++)_Context->msg_ForceBuild[i]=" ";
	_Context->msg_ForceBuild[0]=en_ForceBuild;
	_Context->msg_ForceBuild[1]=fr_ForceBuild;
	_Context->msg_ForceBuild[2]=it_ForceBuild;
	_Context->msg_ForceBuild[3]=es_ForceBuild;
	_Context->msg_ForceBuild[4]=de_ForceBuild;
	_Context->msg_ForceBuild[5]=nl_ForceBuild;
	_Context->msg_ForceBuild[6]=pt_ForceBuild;
	_Context->msg_ForceBuild[7]=xx_ForceBuild;
	for (i=0; i < 8; i++)_Context->msg_ShowDates[i]=" ";
	_Context->msg_ShowDates[0]=en_ShowDates;
	_Context->msg_ShowDates[1]=fr_ShowDates;
	_Context->msg_ShowDates[2]=it_ShowDates;
	_Context->msg_ShowDates[3]=es_ShowDates;
	_Context->msg_ShowDates[4]=de_ShowDates;
	_Context->msg_ShowDates[5]=nl_ShowDates;
	_Context->msg_ShowDates[6]=pt_ShowDates;
	_Context->msg_ShowDates[7]=xx_ShowDates;
	for (i=0; i < 8; i++)_Context->msg_Touch_Only[i]=" ";
	_Context->msg_Touch_Only[0]=en_Touch_Only;
	_Context->msg_Touch_Only[1]=fr_Touch_Only;
	_Context->msg_Touch_Only[2]=it_Touch_Only;
	_Context->msg_Touch_Only[3]=es_Touch_Only;
	_Context->msg_Touch_Only[4]=de_Touch_Only;
	_Context->msg_Touch_Only[5]=nl_Touch_Only;
	_Context->msg_Touch_Only[6]=pt_Touch_Only;
	_Context->msg_Touch_Only[7]=xx_Touch_Only;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	for (i=0; i < 8; i++)_Context->msg_Edit[i]=" ";
	_Context->msg_Edit[0]=en_Edit;
	_Context->msg_Edit[1]=fr_Edit;
	_Context->msg_Edit[2]=it_Edit;
	_Context->msg_Edit[3]=es_Edit;
	_Context->msg_Edit[4]=de_Edit;
	_Context->msg_Edit[5]=nl_Edit;
	_Context->msg_Edit[6]=pt_Edit;
	_Context->msg_Edit[7]=xx_Edit;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(110,100,580,400);
	return(0);
}

private	int	accept_amake_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,110,100);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_amake_remove(
	char * pToolName,
	char * pFileName,
	char * pOutput,
	char * pDefine,
	char * pForceBuild,
	char * pShowDates,
	char * pTouch_Only)
{

	int	result=_Context->keycode;
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

private	int	accept_amake_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,110,100);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(110,100,580,400,2,_Context->msg_Auto5669[_Context->language],strlen(_Context->msg_Auto5669[_Context->language]),0x7);
	visual_image(113,122,574,374,_Context->msg_Auto5670[_Context->language],4);
	visual_text(140,130,510,30,4,16,0,_Context->msg_Auto5671[_Context->language],strlen(_Context->msg_Auto5671[_Context->language]),1283);
	visual_text(130,180,154,16,2,16,0,_Context->msg_Auto5672[_Context->language],strlen(_Context->msg_Auto5672[_Context->language]),258);
	visual_text(130,220,154,16,2,16,0,_Context->msg_Auto5680[_Context->language],strlen(_Context->msg_Auto5680[_Context->language]),258);
	visual_text(130,260,154,16,2,16,0,_Context->msg_Auto5673[_Context->language],strlen(_Context->msg_Auto5673[_Context->language]),258);
	visual_text(130,300,154,16,2,16,0,_Context->msg_Auto5674[_Context->language],strlen(_Context->msg_Auto5674[_Context->language]),258);
	visual_frame(290,180,368+2,16+2,5);
	visual_text(290+1,180+1,368,16,1,16,0,_Context->buffer_ToolName,46,0);
	visual_frame(290,220,368+2,16+2,5);
	visual_text(290+1,220+1,368,16,1,16,0,_Context->buffer_FileName,46,0);
	visual_frame(290,260,368+2,16+2,5);
	visual_text(290+1,260+1,368,16,1,16,0,_Context->buffer_Output,46,0);
	visual_frame(290,300,368+2,80+2,5);
	visual_text(290+1,300+1,368,80,1,16,0,_Context->buffer_Define,230,0);
	_Context->trigger_ForceBuild=visual_trigger_code(_Context->msg_ForceBuild[_Context->language],strlen(_Context->msg_ForceBuild[_Context->language]));
	visual_check(130,390,154,32,2,16,0,_Context->msg_ForceBuild[_Context->language],strlen(_Context->msg_ForceBuild[_Context->language]),_Context->value_ForceBuild|0);
	_Context->trigger_ShowDates=visual_trigger_code(_Context->msg_ShowDates[_Context->language],strlen(_Context->msg_ShowDates[_Context->language]));
	visual_check(290,390,210,32,2,16,0,_Context->msg_ShowDates[_Context->language],strlen(_Context->msg_ShowDates[_Context->language]),_Context->value_ShowDates|0);
	_Context->trigger_Touch_Only=visual_trigger_code(_Context->msg_Touch_Only[_Context->language],strlen(_Context->msg_Touch_Only[_Context->language]));
	visual_check(530,390,126,32,2,16,0,_Context->msg_Touch_Only[_Context->language],strlen(_Context->msg_Touch_Only[_Context->language]),_Context->value_Touch_Only|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(140,440,126,32,2,16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(340,440,126,32,2,26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(530,440,126,32,2,16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_thaw(110,100,580,400);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Edit_event() {
	accept_amake_hide();
	use_editor(_Context->buffer_FileName);
	accept_amake_show();
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	accept_amake_event()
{
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
	if (mt & _MIMO_UP) {
	if ((mx >= 669 )  
	&&  (my >= 104 )  
	&&  (mx <= 685 )  
	&&  (my <= 120 )) {
		return(1);	/* Auto5669 */

		}
	if ((mx >= 653 )  
	&&  (my >= 104 )  
	&&  (mx <= 669 )  
	&&  (my <= 120 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vamake.htm");
			};
		return(-1);	/* Auto5669 */

		}
	if ((mx >= 637 )  
	&&  (my >= 104 )  
	&&  (mx <= 653 )  
	&&  (my <= 120 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		_Context->language--; _Context->language %=8;
			}
		(void) visual_national_language(_Context->language);
		accept_amake_show();
		return(-1);	/* Auto5669 */

		}
		}
	if (( mx >= 290 ) 
	&&  ( my >= 180 ) 
	&&  ( mx <= 658 ) 
	&&  ( my <= 196 )) {
		return(2); /* ToolName */
		}
	if (( mx >= 290 ) 
	&&  ( my >= 220 ) 
	&&  ( mx <= 658 ) 
	&&  ( my <= 236 )) {
		return(3); /* FileName */
		}
	if (( mx >= 290 ) 
	&&  ( my >= 260 ) 
	&&  ( mx <= 658 ) 
	&&  ( my <= 276 )) {
		return(4); /* Output */
		}
	if (( mx >= 290 ) 
	&&  ( my >= 300 ) 
	&&  ( mx <= 658 ) 
	&&  ( my <= 380 )) {
		return(5); /* Define */
		}
	if (( mx >= 130 ) 
	&&  ( my >= 390 ) 
	&&  ( mx <= 284 ) 
	&&  ( my <= 422 )) {
		return(6); /* ForceBuild */
		}
	if (( mx >= 290 ) 
	&&  ( my >= 390 ) 
	&&  ( mx <= 500 ) 
	&&  ( my <= 422 )) {
		return(7); /* ShowDates */
		}
	if (( mx >= 530 ) 
	&&  ( my >= 390 ) 
	&&  ( mx <= 656 ) 
	&&  ( my <= 422 )) {
		return(8); /* Touch_Only */
		}
	if (( mx >= 140 ) 
	&&  ( my >= 440 ) 
	&&  ( mx <= 266 ) 
	&&  ( my <= 472 )) {
		return(9); /* Accept */
		}
	if (( mx >= 340 ) 
	&&  ( my >= 440 ) 
	&&  ( mx <= 466 ) 
	&&  ( my <= 472 )) {
		return(10); /* Edit */
		}
	if (( mx >= 530 ) 
	&&  ( my >= 440 ) 
	&&  ( mx <= 656 ) 
	&&  ( my <= 472 )) {
		return(11); /* Cancel */
		}

	return(-1);
}


private	int	accept_amake_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* ToolName */
				_Context->keycode = visual_edit(290+1,180+1,368,16,1,_Context->buffer_ToolName,46);
				break;
			case	0x3 :
				/* FileName */
				_Context->keycode = visual_edit(290+1,220+1,368,16,1,_Context->buffer_FileName,46);
				break;
			case	0x4 :
				/* Output */
				_Context->keycode = visual_edit(290+1,260+1,368,16,1,_Context->buffer_Output,46);
				break;
			case	0x5 :
				/* Define */
				_Context->keycode = visual_edit(290+1,300+1,368,80,1,_Context->buffer_Define,230);
				break;
			case	0x6 :
				/* ForceBuild */
				visual_check(130,390,154,32,2,16,0,_Context->msg_ForceBuild[_Context->language],strlen(_Context->msg_ForceBuild[_Context->language]),(_Context->value_ForceBuild |2));
				_Context->keycode = visual_getch();
				visual_check(130,390,154,32,2,16,0,_Context->msg_ForceBuild[_Context->language],strlen(_Context->msg_ForceBuild[_Context->language]),(_Context->value_ForceBuild |0));
				break;
			case	0x7 :
				/* ShowDates */
				visual_check(290,390,210,32,2,16,0,_Context->msg_ShowDates[_Context->language],strlen(_Context->msg_ShowDates[_Context->language]),(_Context->value_ShowDates |2));
				_Context->keycode = visual_getch();
				visual_check(290,390,210,32,2,16,0,_Context->msg_ShowDates[_Context->language],strlen(_Context->msg_ShowDates[_Context->language]),(_Context->value_ShowDates |0));
				break;
			case	0x8 :
				/* Touch_Only */
				visual_check(530,390,126,32,2,16,0,_Context->msg_Touch_Only[_Context->language],strlen(_Context->msg_Touch_Only[_Context->language]),(_Context->value_Touch_Only |2));
				_Context->keycode = visual_getch();
				visual_check(530,390,126,32,2,16,0,_Context->msg_Touch_Only[_Context->language],strlen(_Context->msg_Touch_Only[_Context->language]),(_Context->value_Touch_Only |0));
				break;
			case	0x9 :
				/* Accept */
				visual_button(140,440,126,32,2,16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(140,440,126,32,2,16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0xa :
				/* Edit */
				visual_button(340,440,126,32,2,26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(340,440,126,32,2,26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
				break;
			case	0xb :
				/* Cancel */
				visual_button(530,440,126,32,2,16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(530,440,126,32,2,16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_amake_show();
			continue;
		case	0x2 :
			_Context->focus_item=11;
			accept_amake_show();
			continue;
			case	0x100 :
				if ((retcode=accept_amake_event()) == -1)
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
							visual_button(140,440,126,32,2,16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(140,440,126,32,2,16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0xa :
						/* Edit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(340,440,126,32,2,26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(340,440,126,32,2,26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Edit_event()) != -1) break;

							}
						continue;
					case	0xb :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(530,440,126,32,2,16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(530,440,126,32,2,16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
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
	status = accept_amake_create(
	 pToolName,
	 pFileName,
	 pOutput,
	 pDefine,
	 pForceBuild,
	 pShowDates,
	 pTouch_Only);
	if ( status != 0) return(status);
	status = accept_amake_show();
		enter_modal();
	status = accept_amake_focus();
		leave_modal();
	status = accept_amake_hide();
	status = accept_amake_remove(
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
