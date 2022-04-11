
#ifndef _vtrad_c
#define _vtrad_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vtrad.sng  */
/* Target         : vtrad.c  */
/* Identification : 0.0-1065572946-3578.3577 */
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
#define en_Auto1154   "skin.gif"
#define fr_Auto1154   "skin.gif"
#define it_Auto1154   "skin.gif"
#define es_Auto1154   "skin.gif"
#define de_Auto1154   "skin.gif"
#define nl_Auto1154   "skin.gif"
#define pt_Auto1154   "skin.gif"
#define xx_Auto1154   "skin.gif"
#define en_Auto557   "otricon.gif"
#define fr_Auto557   "otricon.gif"
#define it_Auto557   "otricon.gif"
#define es_Auto557   "otricon.gif"
#define de_Auto557   "otricon.gif"
#define nl_Auto557   "otricon.gif"
#define pt_Auto557   "otricon.gif"
#define xx_Auto557   "otricon.gif"
#define en_auto726   "abalicon.gif"
#define fr_auto726   "abalicon.gif"
#define it_auto726   "abalicon.gif"
#define es_auto726   "abalicon.gif"
#define de_auto726   "abalicon.gif"
#define nl_auto726   "abalicon.gif"
#define pt_auto726   "abalicon.gif"
#define xx_auto726   "abalicon.gif"
#define en_Auto1159   "ABAL++ Translator Options"
#define fr_Auto1159   "Options du Traducteur d'ABAL"
#define it_Auto1159   ""
#define es_Auto1159   ""
#define de_Auto1159   ""
#define nl_Auto1159   ""
#define pt_Auto1159   ""
#define xx_Auto1159   ""
#define en_auto281   "Source Filename"
#define fr_auto281   "Nom de Source"
#define it_auto281   ""
#define es_auto281   ""
#define de_auto281   ""
#define nl_auto281   ""
#define pt_auto281   ""
#define xx_auto281   ""
#define en_auto282   "Translator"
#define fr_auto282   "Traducteur"
#define it_auto282   ""
#define es_auto282   ""
#define de_auto282   ""
#define nl_auto282   ""
#define pt_auto282   ""
#define xx_auto282   ""
#define en_Debug   "&Debug"
#define fr_Debug   "&Debug"
#define it_Debug   ""
#define es_Debug   ""
#define de_Debug   ""
#define nl_Debug   ""
#define pt_Debug   ""
#define xx_Debug   ""
#define en_Trace   "&Trace"
#define fr_Trace   "&Trace"
#define it_Trace   "&Trace"
#define es_Trace   "&Trace"
#define de_Trace   "&Trace"
#define nl_Trace   "&Trace"
#define pt_Trace   "&Trace"
#define xx_Trace   "&Trace"
#define en_Verbose   "&Verbose"
#define fr_Verbose   "&Verbose"
#define it_Verbose   "&Verbose"
#define es_Verbose   "&Verbose"
#define de_Verbose   "&Verbose"
#define nl_Verbose   "&Verbose"
#define pt_Verbose   "&Verbose"
#define xx_Verbose   "&Verbose"
#define en_Optimise   "&Optimisation"
#define fr_Optimise   "&Optimisation"
#define it_Optimise   "&Optimisation"
#define es_Optimise   "&Optimisation"
#define de_Optimise   "&Optimisation"
#define nl_Optimise   "&Optimisation"
#define pt_Optimise   "&Optimisation"
#define xx_Optimise   "&Optimisation"
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
#define en_auto351   "Include Paths"
#define fr_auto351   "Chemins d'inclusion"
#define it_auto351   ""
#define es_auto351   ""
#define de_auto351   ""
#define nl_auto351   ""
#define pt_auto351   ""
#define xx_auto351   ""
#define en_Edit   "&Edit"
#define fr_Edit   "&Editer"
#define it_Edit   ""
#define es_Edit   ""
#define de_Edit   ""
#define nl_Edit   ""
#define pt_Edit   ""
#define xx_Edit   ""
#define en_Select   "&Select"
#define fr_Select   "&Choisir"
#define it_Select   ""
#define es_Select   ""
#define de_Select   ""
#define nl_Select   ""
#define pt_Select   ""
#define xx_Select   ""

private struct accept_traduction_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3390[8];
	char * msg_Auto1154[8];
	char * msg_Auto557[8];
	char * msg_auto726[8];
	char * msg_Auto1159[8];
	char * msg_auto281[8];
	char * msg_auto282[8];
	char	buffer_FileName[53];
	char	buffer_Translator[53];
	char * msg_Debug[8];
	int	trigger_Debug;
	int	value_Debug;
	char * msg_Trace[8];
	int	trigger_Trace;
	int	value_Trace;
	char * msg_Verbose[8];
	int	trigger_Verbose;
	int	value_Verbose;
	char * msg_Optimise[8];
	int	trigger_Optimise;
	int	value_Optimise;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_auto351[8];
	char	buffer_Inclusion[105];
	char * msg_Edit[8];
	int	trigger_Edit;
	char * msg_Select[8];
	int	trigger_Select;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[8];
	} * _Context;

private	int	accept_traduction_create(
	char * pFileName,
	char * pTranslator,
	char * pDebug,
	char * pTrace,
	char * pVerbose,
	char * pOptimise,
	char * pInclusion)
{

	int i;
	if (!(_Context = allocate( sizeof( struct accept_traduction_context ) ) ))
		return(27);
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=12;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 52, pFileName);
		visual_transferin(_Context->buffer_Translator, 52, pTranslator);
		visual_transferin((void *) 0, 0, pDebug);
		if (!( pDebug )) _Context->value_Debug=0;
		else	_Context->value_Debug = *((int *)pDebug);
		visual_transferin((void *) 0, 0, pTrace);
		if (!( pTrace )) _Context->value_Trace=0;
		else	_Context->value_Trace = *((int *)pTrace);
		visual_transferin((void *) 0, 0, pVerbose);
		if (!( pVerbose )) _Context->value_Verbose=0;
		else	_Context->value_Verbose = *((int *)pVerbose);
		visual_transferin((void *) 0, 0, pOptimise);
		if (!( pOptimise )) _Context->value_Optimise=0;
		else	_Context->value_Optimise = *((int *)pOptimise);
		visual_transferin(_Context->buffer_Inclusion, 104, pInclusion);
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
	for (i=0; i < 8; i++)_Context->msg_Auto1154[i]=" ";
	_Context->msg_Auto1154[0]=en_Auto1154;
	_Context->msg_Auto1154[1]=fr_Auto1154;
	_Context->msg_Auto1154[2]=it_Auto1154;
	_Context->msg_Auto1154[3]=es_Auto1154;
	_Context->msg_Auto1154[4]=de_Auto1154;
	_Context->msg_Auto1154[5]=nl_Auto1154;
	_Context->msg_Auto1154[6]=pt_Auto1154;
	_Context->msg_Auto1154[7]=xx_Auto1154;
	for (i=0; i < 8; i++)_Context->msg_Auto557[i]=" ";
	_Context->msg_Auto557[0]=en_Auto557;
	_Context->msg_Auto557[1]=fr_Auto557;
	_Context->msg_Auto557[2]=it_Auto557;
	_Context->msg_Auto557[3]=es_Auto557;
	_Context->msg_Auto557[4]=de_Auto557;
	_Context->msg_Auto557[5]=nl_Auto557;
	_Context->msg_Auto557[6]=pt_Auto557;
	_Context->msg_Auto557[7]=xx_Auto557;
	for (i=0; i < 8; i++)_Context->msg_auto726[i]=" ";
	_Context->msg_auto726[0]=en_auto726;
	_Context->msg_auto726[1]=fr_auto726;
	_Context->msg_auto726[2]=it_auto726;
	_Context->msg_auto726[3]=es_auto726;
	_Context->msg_auto726[4]=de_auto726;
	_Context->msg_auto726[5]=nl_auto726;
	_Context->msg_auto726[6]=pt_auto726;
	_Context->msg_auto726[7]=xx_auto726;
	for (i=0; i < 8; i++)_Context->msg_Auto1159[i]=" ";
	_Context->msg_Auto1159[0]=en_Auto1159;
	_Context->msg_Auto1159[1]=fr_Auto1159;
	_Context->msg_Auto1159[2]=it_Auto1159;
	_Context->msg_Auto1159[3]=es_Auto1159;
	_Context->msg_Auto1159[4]=de_Auto1159;
	_Context->msg_Auto1159[5]=nl_Auto1159;
	_Context->msg_Auto1159[6]=pt_Auto1159;
	_Context->msg_Auto1159[7]=xx_Auto1159;
	for (i=0; i < 8; i++)_Context->msg_auto281[i]=" ";
	_Context->msg_auto281[0]=en_auto281;
	_Context->msg_auto281[1]=fr_auto281;
	_Context->msg_auto281[2]=it_auto281;
	_Context->msg_auto281[3]=es_auto281;
	_Context->msg_auto281[4]=de_auto281;
	_Context->msg_auto281[5]=nl_auto281;
	_Context->msg_auto281[6]=pt_auto281;
	_Context->msg_auto281[7]=xx_auto281;
	for (i=0; i < 8; i++)_Context->msg_auto282[i]=" ";
	_Context->msg_auto282[0]=en_auto282;
	_Context->msg_auto282[1]=fr_auto282;
	_Context->msg_auto282[2]=it_auto282;
	_Context->msg_auto282[3]=es_auto282;
	_Context->msg_auto282[4]=de_auto282;
	_Context->msg_auto282[5]=nl_auto282;
	_Context->msg_auto282[6]=pt_auto282;
	_Context->msg_auto282[7]=xx_auto282;
	for (i=0; i < 8; i++)_Context->msg_Debug[i]=" ";
	_Context->msg_Debug[0]=en_Debug;
	_Context->msg_Debug[1]=fr_Debug;
	_Context->msg_Debug[2]=it_Debug;
	_Context->msg_Debug[3]=es_Debug;
	_Context->msg_Debug[4]=de_Debug;
	_Context->msg_Debug[5]=nl_Debug;
	_Context->msg_Debug[6]=pt_Debug;
	_Context->msg_Debug[7]=xx_Debug;
	for (i=0; i < 8; i++)_Context->msg_Trace[i]=" ";
	_Context->msg_Trace[0]=en_Trace;
	_Context->msg_Trace[1]=fr_Trace;
	_Context->msg_Trace[2]=it_Trace;
	_Context->msg_Trace[3]=es_Trace;
	_Context->msg_Trace[4]=de_Trace;
	_Context->msg_Trace[5]=nl_Trace;
	_Context->msg_Trace[6]=pt_Trace;
	_Context->msg_Trace[7]=xx_Trace;
	for (i=0; i < 8; i++)_Context->msg_Verbose[i]=" ";
	_Context->msg_Verbose[0]=en_Verbose;
	_Context->msg_Verbose[1]=fr_Verbose;
	_Context->msg_Verbose[2]=it_Verbose;
	_Context->msg_Verbose[3]=es_Verbose;
	_Context->msg_Verbose[4]=de_Verbose;
	_Context->msg_Verbose[5]=nl_Verbose;
	_Context->msg_Verbose[6]=pt_Verbose;
	_Context->msg_Verbose[7]=xx_Verbose;
	for (i=0; i < 8; i++)_Context->msg_Optimise[i]=" ";
	_Context->msg_Optimise[0]=en_Optimise;
	_Context->msg_Optimise[1]=fr_Optimise;
	_Context->msg_Optimise[2]=it_Optimise;
	_Context->msg_Optimise[3]=es_Optimise;
	_Context->msg_Optimise[4]=de_Optimise;
	_Context->msg_Optimise[5]=nl_Optimise;
	_Context->msg_Optimise[6]=pt_Optimise;
	_Context->msg_Optimise[7]=xx_Optimise;
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
	for (i=0; i < 8; i++)_Context->msg_auto351[i]=" ";
	_Context->msg_auto351[0]=en_auto351;
	_Context->msg_auto351[1]=fr_auto351;
	_Context->msg_auto351[2]=it_auto351;
	_Context->msg_auto351[3]=es_auto351;
	_Context->msg_auto351[4]=de_auto351;
	_Context->msg_auto351[5]=nl_auto351;
	_Context->msg_auto351[6]=pt_auto351;
	_Context->msg_auto351[7]=xx_auto351;
	for (i=0; i < 8; i++)_Context->msg_Edit[i]=" ";
	_Context->msg_Edit[0]=en_Edit;
	_Context->msg_Edit[1]=fr_Edit;
	_Context->msg_Edit[2]=it_Edit;
	_Context->msg_Edit[3]=es_Edit;
	_Context->msg_Edit[4]=de_Edit;
	_Context->msg_Edit[5]=nl_Edit;
	_Context->msg_Edit[6]=pt_Edit;
	_Context->msg_Edit[7]=xx_Edit;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	_Context->msg_Select[2]=it_Select;
	_Context->msg_Select[3]=es_Select;
	_Context->msg_Select[4]=de_Select;
	_Context->msg_Select[5]=nl_Select;
	_Context->msg_Select[6]=pt_Select;
	_Context->msg_Select[7]=xx_Select;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(170,125,460+10,350+10);
	return(0);
}

private	int	accept_traduction_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,170,125);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_traduction_remove(
	char * pFileName,
	char * pTranslator,
	char * pDebug,
	char * pTrace,
	char * pVerbose,
	char * pOptimise,
	char * pInclusion)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 52, pFileName);
		visual_transferout(_Context->buffer_Translator, 52, pTranslator);
		visual_transferout((void *) 0, 0, pDebug);
		if ( pDebug != (char *) 0)
			*((int*)pDebug) = _Context->value_Debug;
		visual_transferout((void *) 0, 0, pTrace);
		if ( pTrace != (char *) 0)
			*((int*)pTrace) = _Context->value_Trace;
		visual_transferout((void *) 0, 0, pVerbose);
		if ( pVerbose != (char *) 0)
			*((int*)pVerbose) = _Context->value_Verbose;
		visual_transferout((void *) 0, 0, pOptimise);
		if ( pOptimise != (char *) 0)
			*((int*)pOptimise) = _Context->value_Optimise;
		visual_transferout(_Context->buffer_Inclusion, 104, pInclusion);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_traduction_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,170,125);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(170,125,460,350,2,_Context->msg_Auto3390[_Context->language],strlen(_Context->msg_Auto3390[_Context->language]),0x407);
	visual_image(174,148,452,324,_Context->msg_Auto1154[_Context->language],4);
	visual_frame(191,293,412,32,2);
	visual_image(520,155,30,20,_Context->msg_Auto557[_Context->language],3);
	visual_image(560,155,51,50,_Context->msg_auto726[_Context->language],0);
	visual_text(190,155,392,32,3,34,0,_Context->msg_Auto1159[_Context->language],strlen(_Context->msg_Auto1159[_Context->language]),770);
	visual_text(190,195,414,16,2,34,0,_Context->msg_auto281[_Context->language],strlen(_Context->msg_auto281[_Context->language]),0);
	visual_text(190,245,415,16,2,34,0,_Context->msg_auto282[_Context->language],strlen(_Context->msg_auto282[_Context->language]),0);
	visual_frame(190,215,416+2,16+2,5);
	visual_text(190+1,215+1,416,16,1,16,28,_Context->buffer_FileName,52,0);
	visual_frame(190,265,416+2,16+2,5);
	visual_text(190+1,265+1,416,16,1,16,28,_Context->buffer_Translator,52,0);
	_Context->trigger_Debug=visual_trigger_code(_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]));
	visual_check(200,305,84,16,2,34,0,_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]),_Context->value_Debug|0);
	_Context->trigger_Trace=visual_trigger_code(_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]));
	visual_check(290,305,84,16,2,34,0,_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]),_Context->value_Trace|0);
	_Context->trigger_Verbose=visual_trigger_code(_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]));
	visual_check(380,305,98,16,2,27,0,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),_Context->value_Verbose|0);
	_Context->trigger_Optimise=visual_trigger_code(_Context->msg_Optimise[_Context->language],strlen(_Context->msg_Optimise[_Context->language]));
	visual_check(480,305,126,16,2,34,0,_Context->msg_Optimise[_Context->language],strlen(_Context->msg_Optimise[_Context->language]),_Context->value_Optimise|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(190,415,98,32,2,34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(510,415,98,32,2,34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_text(190,335,419,20,2,34,0,_Context->msg_auto351[_Context->language],strlen(_Context->msg_auto351[_Context->language]),0);
	visual_frame(190,355,420+2,40+2,5);
	visual_text(190+1,355+1,420,40,1,16,28,_Context->buffer_Inclusion,104,0);
	_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(290,415,98,32,2,26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(410,415,98,32,2,27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	visual_thaw(170,125,460,350);

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
private int on_Edit_event() {
	accept_traduction_hide();
	use_editor(_Context->buffer_FileName);
	accept_traduction_show();
	return(-1);
}
private int on_Select_event() {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_AS);
	accept_traduction_show();
	return(-1);
}


private	int	accept_traduction_event()
{
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Debug == mb ) return(4);
		if (_Context->trigger_Trace == mb ) return(5);
		if (_Context->trigger_Verbose == mb ) return(6);
		if (_Context->trigger_Optimise == mb ) return(7);
		if (_Context->trigger_Accept == mb ) return(8);
		if (_Context->trigger_Cancel == mb ) return(9);
		if (_Context->trigger_Edit == mb ) return(11);
		if (_Context->trigger_Select == mb ) return(12);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (mt & _MIMO_UP) {
	if ((mx >= 609 )  
	&&  (my >= 129 )  
	&&  (mx <= 625 )  
	&&  (my <= 145 )) {
		return(1);	/* Auto3390 */

		}
	if ((mx >= 593 )  
	&&  (my >= 129 )  
	&&  (mx <= 609 )  
	&&  (my <= 145 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vtrad.htm");
			};
		return(-1);	/* Auto3390 */

		}
	if ((mx >= 577 )  
	&&  (my >= 129 )  
	&&  (mx <= 593 )  
	&&  (my <= 145 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		_Context->language--; _Context->language %=8;
			}
		(void) visual_national_language(_Context->language);
		accept_traduction_show();
		return(-1);	/* Auto3390 */

		}
		}
	if (( mx >= 190 ) 
	&&  ( my >= 215 ) 
	&&  ( mx <= 606 ) 
	&&  ( my <= 231 )) {
		return(2); /* FileName */
		}
	if (( mx >= 190 ) 
	&&  ( my >= 265 ) 
	&&  ( mx <= 606 ) 
	&&  ( my <= 281 )) {
		return(3); /* Translator */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 305 ) 
	&&  ( mx <= 284 ) 
	&&  ( my <= 321 )) {
		return(4); /* Debug */
		}
	if (( mx >= 290 ) 
	&&  ( my >= 305 ) 
	&&  ( mx <= 374 ) 
	&&  ( my <= 321 )) {
		return(5); /* Trace */
		}
	if (( mx >= 380 ) 
	&&  ( my >= 305 ) 
	&&  ( mx <= 478 ) 
	&&  ( my <= 321 )) {
		return(6); /* Verbose */
		}
	if (( mx >= 480 ) 
	&&  ( my >= 305 ) 
	&&  ( mx <= 606 ) 
	&&  ( my <= 321 )) {
		return(7); /* Optimise */
		}
	if (( mx >= 190 ) 
	&&  ( my >= 415 ) 
	&&  ( mx <= 288 ) 
	&&  ( my <= 447 )) {
		return(8); /* Accept */
		}
	if (( mx >= 510 ) 
	&&  ( my >= 415 ) 
	&&  ( mx <= 608 ) 
	&&  ( my <= 447 )) {
		return(9); /* Cancel */
		}
	if (( mx >= 190 ) 
	&&  ( my >= 355 ) 
	&&  ( mx <= 610 ) 
	&&  ( my <= 395 )) {
		return(10); /* Inclusion */
		}
	if (( mx >= 290 ) 
	&&  ( my >= 415 ) 
	&&  ( mx <= 388 ) 
	&&  ( my <= 447 )) {
		return(11); /* Edit */
		}
	if (( mx >= 410 ) 
	&&  ( my >= 415 ) 
	&&  ( mx <= 508 ) 
	&&  ( my <= 447 )) {
		return(12); /* Select */
		}

	return(-1);
}


private	int	accept_traduction_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(190+1,215+1,416,16,1,_Context->buffer_FileName,52);
				break;
			case	0x3 :
				/* Translator */
				_Context->keycode = visual_edit(190+1,265+1,416,16,1,_Context->buffer_Translator,52);
				break;
			case	0x4 :
				/* Debug */
				visual_check(200,305,84,16,2,34,0,_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]),(_Context->value_Debug |2));
				_Context->keycode = visual_getch();
				visual_check(200,305,84,16,2,34,0,_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]),(_Context->value_Debug |0));
				break;
			case	0x5 :
				/* Trace */
				visual_check(290,305,84,16,2,34,0,_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]),(_Context->value_Trace |2));
				_Context->keycode = visual_getch();
				visual_check(290,305,84,16,2,34,0,_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]),(_Context->value_Trace |0));
				break;
			case	0x6 :
				/* Verbose */
				visual_check(380,305,98,16,2,27,0,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),(_Context->value_Verbose |2));
				_Context->keycode = visual_getch();
				visual_check(380,305,98,16,2,27,0,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),(_Context->value_Verbose |0));
				break;
			case	0x7 :
				/* Optimise */
				visual_check(480,305,126,16,2,34,0,_Context->msg_Optimise[_Context->language],strlen(_Context->msg_Optimise[_Context->language]),(_Context->value_Optimise |2));
				_Context->keycode = visual_getch();
				visual_check(480,305,126,16,2,34,0,_Context->msg_Optimise[_Context->language],strlen(_Context->msg_Optimise[_Context->language]),(_Context->value_Optimise |0));
				break;
			case	0x8 :
				/* Accept */
				visual_button(190,415,98,32,2,34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(190,415,98,32,2,34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x9 :
				/* Cancel */
				visual_button(510,415,98,32,2,34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(510,415,98,32,2,34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0xa :
				/* Inclusion */
				_Context->keycode = visual_edit(190+1,355+1,420,40,1,_Context->buffer_Inclusion,104);
				break;
			case	0xb :
				/* Edit */
				visual_button(290,415,98,32,2,26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(290,415,98,32,2,26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
				break;
			case	0xc :
				/* Select */
				visual_button(410,415,98,32,2,27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(410,415,98,32,2,27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_traduction_show();
			continue;
		case	0x2 :
			_Context->focus_item=12;
			accept_traduction_show();
			continue;
			case	0x100 :
				if ((retcode=accept_traduction_event()) == -1)
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
						/* FileName */
						continue;
					case	0x3 :
						/* Translator */
						continue;
					case	0x4 :
						/* Debug */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Debug += 1;
							_Context->value_Debug &= 1;
							}
						continue;
					case	0x5 :
						/* Trace */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Trace += 1;
							_Context->value_Trace &= 1;
							}
						continue;
					case	0x6 :
						/* Verbose */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Verbose += 1;
							_Context->value_Verbose &= 1;
							}
						continue;
					case	0x7 :
						/* Optimise */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Optimise += 1;
							_Context->value_Optimise &= 1;
							}
						continue;
					case	0x8 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(190,415,98,32,2,34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(190,415,98,32,2,34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x9 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(510,415,98,32,2,34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(510,415,98,32,2,34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0xa :
						/* Inclusion */
						continue;
					case	0xb :
						/* Edit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(290,415,98,32,2,26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(290,415,98,32,2,26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Edit_event()) != -1) break;

							}
						continue;
					case	0xc :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(410,415,98,32,2,27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(410,415,98,32,2,27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Select_event()) != -1) break;

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
				_Context->focus_item=12;
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

public	int	accept_traduction(
	char * pFileName,
	char * pTranslator,
	char * pDebug,
	char * pTrace,
	char * pVerbose,
	char * pOptimise,
	char * pInclusion)
{
	int	status=0;
	status = accept_traduction_create(
	 pFileName,
	 pTranslator,
	 pDebug,
	 pTrace,
	 pVerbose,
	 pOptimise,
	 pInclusion);
	if ( status != 0) return(status);
	status = accept_traduction_show();
		enter_modal();
	status = accept_traduction_focus();
		leave_modal();
	status = accept_traduction_hide();
	status = accept_traduction_remove(
	 pFileName,
	 pTranslator,
	 pDebug,
	 pTrace,
	 pVerbose,
	 pOptimise,
	 pInclusion);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vtrad_c */
