
#ifndef _vlink_c
#define _vlink_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vlink.sng  */
/* Target         : vlink.c  */
/* Identification : 0.0-1065574334-3811.3810 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto3389   "Sing : Version 1.0a"
#define fr_Auto3389   "Sing : Version 1.0a"
#define it_Auto3389   "Sing : Version 1.0a"
#define es_Auto3389   "Sing : Version 1.0a"
#define de_Auto3389   "Sing : Version 1.0a"
#define nl_Auto3389   "Sing : Version 1.0a"
#define pt_Auto3389   "Sing : Version 1.0a"
#define xx_Auto3389   "Sing : Version 1.0a"
#define en_Auto3390   "skin.gif"
#define fr_Auto3390   "skin.gif"
#define it_Auto3390   "skin.gif"
#define es_Auto3390   "skin.gif"
#define de_Auto3390   "skin.gif"
#define nl_Auto3390   "skin.gif"
#define pt_Auto3390   "skin.gif"
#define xx_Auto3390   "skin.gif"
#define en_Auto3391   "ABAL++ Object Linker"
#define fr_Auto3391   "Editeur de Liens d'objets ABAL"
#define en_Auto3392   "oldicon.gif"
#define fr_Auto3392   "oldicon.gif"
#define it_Auto3392   "oldicon.gif"
#define es_Auto3392   "oldicon.gif"
#define de_Auto3392   "oldicon.gif"
#define nl_Auto3392   "oldicon.gif"
#define pt_Auto3392   "oldicon.gif"
#define xx_Auto3392   "oldicon.gif"
#define en_General   "&General"
#define fr_General   "&Generaux"
#define en_Auto3394   "abal.gif"
#define fr_Auto3394   "abal.gif"
#define it_Auto3394   "abal.gif"
#define es_Auto3394   "abal.gif"
#define de_Auto3394   "abal.gif"
#define nl_Auto3394   "abal.gif"
#define pt_Auto3394   "abal.gif"
#define xx_Auto3394   "abal.gif"
#define en_Auto8289   "Linker Program Name"
#define fr_Auto8289   "Nom de l'editeur de liens"
#define en_TargetFile   "Targ&et File"
#define fr_TargetFile   "&Fichier cible"
#define en_Report   "&Html Report"
#define fr_Report   "&Raport Html"
#define en_Debug   "&Debug"
#define fr_Debug   "&Debug"
#define en_InputTrace   "&Trace Input"
#define fr_InputTrace   "&Trace Entr‚e"
#define en_OutputTrace   "T&race Output"
#define fr_OutputTrace   "Trace &Sortie"
#define en_Verbose   "&Verbose"
#define fr_Verbose   "&Verbose"
#define it_Verbose   "&Verbose"
#define es_Verbose   "&Verbose"
#define de_Verbose   "&Verbose"
#define nl_Verbose   "&Verbose"
#define pt_Verbose   "&Verbose"
#define xx_Verbose   "&Verbose"
#define en_Modules   "&Modules"
#define fr_Modules   "&Modules"
#define en_Inclusion   "&Inclusion"
#define fr_Inclusion   "&Inclusion"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"

private struct accept_linker_parameters_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[3+1];
	char * msg_Auto3389[8];
	char * msg_Auto3390[8];
	char * msg_Auto3391[8];
	char * msg_Auto3392[8];
	char * msg_General[8];
	int	trigger_General;
	int	page_number;
	char * msg_Auto3394[8];
	char * msg_Auto8289[8];
	char	buffer_Linker[59];
	char * msg_TargetFile[8];
	int	trigger_TargetFile;
	int	value_TargetFile;
	char	buffer_TargetName[44];
	char * msg_Report[8];
	int	trigger_Report;
	int	value_Report;
	char	buffer_ReportName[44];
	char * msg_Debug[8];
	int	trigger_Debug;
	int	value_Debug;
	char * msg_InputTrace[8];
	int	trigger_InputTrace;
	int	value_InputTrace;
	char * msg_OutputTrace[8];
	int	trigger_OutputTrace;
	int	value_OutputTrace;
	char * msg_Verbose[8];
	int	trigger_Verbose;
	int	value_Verbose;
	char * msg_Modules[8];
	int	trigger_Modules;
	char	buffer_Modules[721];
	char * msg_Inclusion[8];
	int	trigger_Inclusion;
	char	buffer_IncludePath[721];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[12];
	} * _Context;

private	int	accept_linker_parameters_create(
	char * pLinker,
	char * pTargetFile,
	char * pTargetName,
	char * pReport,
	char * pReportName,
	char * pDebug,
	char * pInputTrace,
	char * pOutputTrace,
	char * pVerbose,
	char * pModules,
	char * pIncludePath)
{

	int i;
	if (!(_Context = allocate( sizeof( struct accept_linker_parameters_context ) ) ))
		return(27);
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=17;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWSWSWWWWSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Linker, 58, pLinker);
		visual_transferin((void *) 0, 0, pTargetFile);
		if (!( pTargetFile )) _Context->value_TargetFile=0;
		else	_Context->value_TargetFile = *((int *)pTargetFile);
		visual_transferin(_Context->buffer_TargetName, 43, pTargetName);
		visual_transferin((void *) 0, 0, pReport);
		if (!( pReport )) _Context->value_Report=0;
		else	_Context->value_Report = *((int *)pReport);
		visual_transferin(_Context->buffer_ReportName, 43, pReportName);
		visual_transferin((void *) 0, 0, pDebug);
		if (!( pDebug )) _Context->value_Debug=0;
		else	_Context->value_Debug = *((int *)pDebug);
		visual_transferin((void *) 0, 0, pInputTrace);
		if (!( pInputTrace )) _Context->value_InputTrace=0;
		else	_Context->value_InputTrace = *((int *)pInputTrace);
		visual_transferin((void *) 0, 0, pOutputTrace);
		if (!( pOutputTrace )) _Context->value_OutputTrace=0;
		else	_Context->value_OutputTrace = *((int *)pOutputTrace);
		visual_transferin((void *) 0, 0, pVerbose);
		if (!( pVerbose )) _Context->value_Verbose=0;
		else	_Context->value_Verbose = *((int *)pVerbose);
		visual_transferin(_Context->buffer_Modules, 720, pModules);
		visual_transferin(_Context->buffer_IncludePath, 720, pIncludePath);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3389[i]=" ";
	_Context->msg_Auto3389[0]=en_Auto3389;
	_Context->msg_Auto3389[1]=fr_Auto3389;
	_Context->msg_Auto3389[2]=it_Auto3389;
	_Context->msg_Auto3389[3]=es_Auto3389;
	_Context->msg_Auto3389[4]=de_Auto3389;
	_Context->msg_Auto3389[5]=nl_Auto3389;
	_Context->msg_Auto3389[6]=pt_Auto3389;
	_Context->msg_Auto3389[7]=xx_Auto3389;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3390[i]=" ";
	_Context->msg_Auto3390[0]=en_Auto3390;
	_Context->msg_Auto3390[1]=fr_Auto3390;
	_Context->msg_Auto3390[2]=it_Auto3390;
	_Context->msg_Auto3390[3]=es_Auto3390;
	_Context->msg_Auto3390[4]=de_Auto3390;
	_Context->msg_Auto3390[5]=nl_Auto3390;
	_Context->msg_Auto3390[6]=pt_Auto3390;
	_Context->msg_Auto3390[7]=xx_Auto3390;
	for (i=0; i < 8; i++)_Context->msg_Auto3391[i]=" ";
	_Context->msg_Auto3391[0]=en_Auto3391;
	_Context->msg_Auto3391[1]=fr_Auto3391;
	for (i=0; i < 8; i++)_Context->msg_Auto3392[i]=" ";
	_Context->msg_Auto3392[0]=en_Auto3392;
	_Context->msg_Auto3392[1]=fr_Auto3392;
	_Context->msg_Auto3392[2]=it_Auto3392;
	_Context->msg_Auto3392[3]=es_Auto3392;
	_Context->msg_Auto3392[4]=de_Auto3392;
	_Context->msg_Auto3392[5]=nl_Auto3392;
	_Context->msg_Auto3392[6]=pt_Auto3392;
	_Context->msg_Auto3392[7]=xx_Auto3392;
	for (i=0; i < 8; i++)_Context->msg_General[i]=" ";
	_Context->msg_General[0]=en_General;
	_Context->msg_General[1]=fr_General;
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_Auto3394[i]=" ";
	_Context->msg_Auto3394[0]=en_Auto3394;
	_Context->msg_Auto3394[1]=fr_Auto3394;
	_Context->msg_Auto3394[2]=it_Auto3394;
	_Context->msg_Auto3394[3]=es_Auto3394;
	_Context->msg_Auto3394[4]=de_Auto3394;
	_Context->msg_Auto3394[5]=nl_Auto3394;
	_Context->msg_Auto3394[6]=pt_Auto3394;
	_Context->msg_Auto3394[7]=xx_Auto3394;
	for (i=0; i < 8; i++)_Context->msg_Auto8289[i]=" ";
	_Context->msg_Auto8289[0]=en_Auto8289;
	_Context->msg_Auto8289[1]=fr_Auto8289;
	for (i=0; i < 8; i++)_Context->msg_TargetFile[i]=" ";
	_Context->msg_TargetFile[0]=en_TargetFile;
	_Context->msg_TargetFile[1]=fr_TargetFile;
	for (i=0; i < 8; i++)_Context->msg_Report[i]=" ";
	_Context->msg_Report[0]=en_Report;
	_Context->msg_Report[1]=fr_Report;
	for (i=0; i < 8; i++)_Context->msg_Debug[i]=" ";
	_Context->msg_Debug[0]=en_Debug;
	_Context->msg_Debug[1]=fr_Debug;
	for (i=0; i < 8; i++)_Context->msg_InputTrace[i]=" ";
	_Context->msg_InputTrace[0]=en_InputTrace;
	_Context->msg_InputTrace[1]=fr_InputTrace;
	for (i=0; i < 8; i++)_Context->msg_OutputTrace[i]=" ";
	_Context->msg_OutputTrace[0]=en_OutputTrace;
	_Context->msg_OutputTrace[1]=fr_OutputTrace;
	for (i=0; i < 8; i++)_Context->msg_Verbose[i]=" ";
	_Context->msg_Verbose[0]=en_Verbose;
	_Context->msg_Verbose[1]=fr_Verbose;
	_Context->msg_Verbose[2]=it_Verbose;
	_Context->msg_Verbose[3]=es_Verbose;
	_Context->msg_Verbose[4]=de_Verbose;
	_Context->msg_Verbose[5]=nl_Verbose;
	_Context->msg_Verbose[6]=pt_Verbose;
	_Context->msg_Verbose[7]=xx_Verbose;
	for (i=0; i < 8; i++)_Context->msg_Modules[i]=" ";
	_Context->msg_Modules[0]=en_Modules;
	_Context->msg_Modules[1]=fr_Modules;
	_Context->focus_pages[2]=12;
	for (i=0; i < 8; i++)_Context->msg_Inclusion[i]=" ";
	_Context->msg_Inclusion[0]=en_Inclusion;
	_Context->msg_Inclusion[1]=fr_Inclusion;
	_Context->focus_pages[3]=14;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(135,115,530+10,370+10);
	return(0);
}

private	int	accept_linker_parameters_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,135,115);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_linker_parameters_remove(
	char * pLinker,
	char * pTargetFile,
	char * pTargetName,
	char * pReport,
	char * pReportName,
	char * pDebug,
	char * pInputTrace,
	char * pOutputTrace,
	char * pVerbose,
	char * pModules,
	char * pIncludePath)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWSWSWWWWSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Linker, 58, pLinker);
		visual_transferout((void *) 0, 0, pTargetFile);
		if ( pTargetFile != (char *) 0)
			*((int*)pTargetFile) = _Context->value_TargetFile;
		visual_transferout(_Context->buffer_TargetName, 43, pTargetName);
		visual_transferout((void *) 0, 0, pReport);
		if ( pReport != (char *) 0)
			*((int*)pReport) = _Context->value_Report;
		visual_transferout(_Context->buffer_ReportName, 43, pReportName);
		visual_transferout((void *) 0, 0, pDebug);
		if ( pDebug != (char *) 0)
			*((int*)pDebug) = _Context->value_Debug;
		visual_transferout((void *) 0, 0, pInputTrace);
		if ( pInputTrace != (char *) 0)
			*((int*)pInputTrace) = _Context->value_InputTrace;
		visual_transferout((void *) 0, 0, pOutputTrace);
		if ( pOutputTrace != (char *) 0)
			*((int*)pOutputTrace) = _Context->value_OutputTrace;
		visual_transferout((void *) 0, 0, pVerbose);
		if ( pVerbose != (char *) 0)
			*((int*)pVerbose) = _Context->value_Verbose;
		visual_transferout(_Context->buffer_Modules, 720, pModules);
		visual_transferout(_Context->buffer_IncludePath, 720, pIncludePath);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_linker_parameters_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,135,115);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(135,115,530,370,2,_Context->msg_Auto3389[_Context->language],strlen(_Context->msg_Auto3389[_Context->language]),0x407);
	visual_image(138,137,524,346,_Context->msg_Auto3390[_Context->language],4);
	visual_text(155,145,437,20,3,27,0,_Context->msg_Auto3391[_Context->language],strlen(_Context->msg_Auto3391[_Context->language]),1538);
	visual_image(555,155,30,30,_Context->msg_Auto3392[_Context->language],3);
	if (_Context->page_number == 1 ) {
	_Context->trigger_General=visual_trigger_code(_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]));
	visual_tabpage(145,175,500,250,2,_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]),0,2);
	} else {
		visual_tabpage(145,175,500,250,2,_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(165,345,460,40,2);
		}
	visual_image(595,145,50,50,_Context->msg_Auto3394[_Context->language],3);
	if (_Context->page_number == 1 ) {
	visual_text(165,215,462,24,2,16,0,_Context->msg_Auto8289[_Context->language],strlen(_Context->msg_Auto8289[_Context->language]),1283);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(165,235,464+2,16+2,5);
	visual_text(165+1,235+1,464,16,1,16,28,_Context->buffer_Linker,58,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_TargetFile=visual_trigger_code(_Context->msg_TargetFile[_Context->language],strlen(_Context->msg_TargetFile[_Context->language]));
	visual_check(165,265,112,16,2,16,28,_Context->msg_TargetFile[_Context->language],strlen(_Context->msg_TargetFile[_Context->language]),_Context->value_TargetFile|0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(285,265,344+2,16+2,5);
	visual_text(285+1,265+1,344,16,1,16,28,_Context->buffer_TargetName,43,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Report=visual_trigger_code(_Context->msg_Report[_Context->language],strlen(_Context->msg_Report[_Context->language]));
	visual_check(165,295,126,16,2,16,28,_Context->msg_Report[_Context->language],strlen(_Context->msg_Report[_Context->language]),_Context->value_Report|0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(285,295,344+2,16+2,5);
	visual_text(285+1,295+1,344,16,1,16,28,_Context->buffer_ReportName,43,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Debug=visual_trigger_code(_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]));
	visual_check(175,355,84,16,2,16,28,_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]),_Context->value_Debug|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_InputTrace=visual_trigger_code(_Context->msg_InputTrace[_Context->language],strlen(_Context->msg_InputTrace[_Context->language]));
	visual_check(365,355,126,16,2,16,28,_Context->msg_InputTrace[_Context->language],strlen(_Context->msg_InputTrace[_Context->language]),_Context->value_InputTrace|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_OutputTrace=visual_trigger_code(_Context->msg_OutputTrace[_Context->language],strlen(_Context->msg_OutputTrace[_Context->language]));
	visual_check(485,355,126,16,2,16,28,_Context->msg_OutputTrace[_Context->language],strlen(_Context->msg_OutputTrace[_Context->language]),_Context->value_OutputTrace|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Verbose=visual_trigger_code(_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]));
	visual_check(265,355,98,16,2,16,28,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),_Context->value_Verbose|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Modules=visual_trigger_code(_Context->msg_Modules[_Context->language],strlen(_Context->msg_Modules[_Context->language]));
	visual_tabpage(145,175,500,250,2,_Context->msg_Modules[_Context->language],strlen(_Context->msg_Modules[_Context->language]),95,2);
	} else {
		visual_tabpage(145,175,500,250,2,_Context->msg_Modules[_Context->language],strlen(_Context->msg_Modules[_Context->language]),95,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(155,215,480+2,192+2,5);
	visual_text(155+1,215+1,480,192,1,16,28,_Context->buffer_Modules,720,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_Inclusion=visual_trigger_code(_Context->msg_Inclusion[_Context->language],strlen(_Context->msg_Inclusion[_Context->language]));
	visual_tabpage(145,175,500,250,2,_Context->msg_Inclusion[_Context->language],strlen(_Context->msg_Inclusion[_Context->language]),182,2);
	} else {
		visual_tabpage(145,175,500,250,2,_Context->msg_Inclusion[_Context->language],strlen(_Context->msg_Inclusion[_Context->language]),182,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(155,215,480+2,192+2,5);
	visual_text(155+1,215+1,480,192,1,16,28,_Context->buffer_IncludePath,720,0);
		}
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(145,435,120,30,2,16,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(525,435,120,30,2,16,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_thaw(135,115,530,370);

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


private	int	accept_linker_parameters_event()
{
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_General == mb ) return(2);
		if (_Context->trigger_TargetFile == mb ) return(4);
		if (_Context->trigger_Report == mb ) return(6);
		if (_Context->trigger_Debug == mb ) return(8);
		if (_Context->trigger_InputTrace == mb ) return(9);
		if (_Context->trigger_OutputTrace == mb ) return(10);
		if (_Context->trigger_Verbose == mb ) return(11);
		if (_Context->trigger_Modules == mb ) return(12);
		if (_Context->trigger_Inclusion == mb ) return(14);
		if (_Context->trigger_Accept == mb ) return(16);
		if (_Context->trigger_Cancel == mb ) return(17);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (mt & _MIMO_UP) {
	if ((mx >= 644 )  
	&&  (my >= 119 )  
	&&  (mx <= 660 )  
	&&  (my <= 135 )) {
		return(1);	/* Auto3389 */

		}
	if ((mx >= 628 )  
	&&  (my >= 119 )  
	&&  (mx <= 644 )  
	&&  (my <= 135 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vlink.htm");
			};
		return(-1);	/* Auto3389 */

		}
	if ((mx >= 612 )  
	&&  (my >= 119 )  
	&&  (mx <= 628 )  
	&&  (my <= 135 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		_Context->language--; _Context->language %=8;
			}
		(void) visual_national_language(_Context->language);
		accept_linker_parameters_show();
		return(-1);	/* Auto3389 */

		}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 145 ) 
		&&  (my >= 175 ) 
		&&  (mx <= 239 ) 
		&&  (my <= 199 )) {
			return(2); /* General */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 165 ) 
		&&  ( my >= 235 ) 
		&&  ( mx <= 629 ) 
		&&  ( my <= 251 )) {
			return(3); /* Linker */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 165 ) 
		&&  ( my >= 265 ) 
		&&  ( mx <= 277 ) 
		&&  ( my <= 281 )) {
			return(4); /* TargetFile */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 285 ) 
		&&  ( my >= 265 ) 
		&&  ( mx <= 629 ) 
		&&  ( my <= 281 )) {
			return(5); /* TargetName */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 165 ) 
		&&  ( my >= 295 ) 
		&&  ( mx <= 291 ) 
		&&  ( my <= 311 )) {
			return(6); /* Report */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 285 ) 
		&&  ( my >= 295 ) 
		&&  ( mx <= 629 ) 
		&&  ( my <= 311 )) {
			return(7); /* ReportName */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 175 ) 
		&&  ( my >= 355 ) 
		&&  ( mx <= 259 ) 
		&&  ( my <= 371 )) {
			return(8); /* Debug */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 365 ) 
		&&  ( my >= 355 ) 
		&&  ( mx <= 491 ) 
		&&  ( my <= 371 )) {
			return(9); /* InputTrace */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 485 ) 
		&&  ( my >= 355 ) 
		&&  ( mx <= 611 ) 
		&&  ( my <= 371 )) {
			return(10); /* OutputTrace */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 265 ) 
		&&  ( my >= 355 ) 
		&&  ( mx <= 363 ) 
		&&  ( my <= 371 )) {
			return(11); /* Verbose */
		}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 240 ) 
		&&  (my >= 175 ) 
		&&  (mx <= 326 ) 
		&&  (my <= 199 )) {
			return(12); /* Modules */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 155 ) 
		&&  ( my >= 215 ) 
		&&  ( mx <= 635 ) 
		&&  ( my <= 407 )) {
			return(13); /* Modules */
		}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if ((mx >= 327 ) 
		&&  (my >= 175 ) 
		&&  (mx <= 415 ) 
		&&  (my <= 199 )) {
			return(14); /* Inclusion */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 155 ) 
		&&  ( my >= 215 ) 
		&&  ( mx <= 635 ) 
		&&  ( my <= 407 )) {
			return(15); /* IncludePath */
		}
		}
	if (( mx >= 145 ) 
	&&  ( my >= 435 ) 
	&&  ( mx <= 265 ) 
	&&  ( my <= 465 )) {
		return(16); /* Accept */
		}
	if (( mx >= 525 ) 
	&&  ( my >= 435 ) 
	&&  ( mx <= 645 ) 
	&&  ( my <= 465 )) {
		return(17); /* Cancel */
		}

	return(-1);
}


private	int	accept_linker_parameters_losefocus()
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;
		case 3 : 
			break;

		}
	return(0);

}


private	int	accept_linker_parameters_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* General */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* Linker */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(165+1,235+1,464,16,1,_Context->buffer_Linker,58);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* TargetFile */
				if (_Context->page_number == 1 ) {
				visual_check(165,265,112,16,2,16,28,_Context->msg_TargetFile[_Context->language],strlen(_Context->msg_TargetFile[_Context->language]),(_Context->value_TargetFile |2));
					_Context->keycode = visual_getch();
				visual_check(165,265,112,16,2,16,28,_Context->msg_TargetFile[_Context->language],strlen(_Context->msg_TargetFile[_Context->language]),(_Context->value_TargetFile |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* TargetName */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(285+1,265+1,344,16,1,_Context->buffer_TargetName,43);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* Report */
				if (_Context->page_number == 1 ) {
				visual_check(165,295,126,16,2,16,28,_Context->msg_Report[_Context->language],strlen(_Context->msg_Report[_Context->language]),(_Context->value_Report |2));
					_Context->keycode = visual_getch();
				visual_check(165,295,126,16,2,16,28,_Context->msg_Report[_Context->language],strlen(_Context->msg_Report[_Context->language]),(_Context->value_Report |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* ReportName */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(285+1,295+1,344,16,1,_Context->buffer_ReportName,43);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* Debug */
				if (_Context->page_number == 1 ) {
				visual_check(175,355,84,16,2,16,28,_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]),(_Context->value_Debug |2));
					_Context->keycode = visual_getch();
				visual_check(175,355,84,16,2,16,28,_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]),(_Context->value_Debug |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* InputTrace */
				if (_Context->page_number == 1 ) {
				visual_check(365,355,126,16,2,16,28,_Context->msg_InputTrace[_Context->language],strlen(_Context->msg_InputTrace[_Context->language]),(_Context->value_InputTrace |2));
					_Context->keycode = visual_getch();
				visual_check(365,355,126,16,2,16,28,_Context->msg_InputTrace[_Context->language],strlen(_Context->msg_InputTrace[_Context->language]),(_Context->value_InputTrace |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* OutputTrace */
				if (_Context->page_number == 1 ) {
				visual_check(485,355,126,16,2,16,28,_Context->msg_OutputTrace[_Context->language],strlen(_Context->msg_OutputTrace[_Context->language]),(_Context->value_OutputTrace |2));
					_Context->keycode = visual_getch();
				visual_check(485,355,126,16,2,16,28,_Context->msg_OutputTrace[_Context->language],strlen(_Context->msg_OutputTrace[_Context->language]),(_Context->value_OutputTrace |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* Verbose */
				if (_Context->page_number == 1 ) {
				visual_check(265,355,98,16,2,16,28,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),(_Context->value_Verbose |2));
					_Context->keycode = visual_getch();
				visual_check(265,355,98,16,2,16,28,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),(_Context->value_Verbose |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* Modules */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xd :
				/* Modules */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(155+1,215+1,480,192,1,_Context->buffer_Modules,720);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* Inclusion */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xf :
				/* IncludePath */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(155+1,215+1,480,192,1,_Context->buffer_IncludePath,720);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* Accept */
				visual_button(145,435,120,30,2,16,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(145,435,120,30,2,16,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x11 :
				/* Cancel */
				visual_button(525,435,120,30,2,16,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(525,435,120,30,2,16,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			accept_linker_parameters_losefocus();
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_linker_parameters_show();
			continue;
		case	0x2 :
			accept_linker_parameters_losefocus();
			_Context->page_number=3;
			_Context->focus_item=17;
			accept_linker_parameters_show();
			continue;
		case	0x3 :
			accept_linker_parameters_losefocus();
			if ( _Context->page_number < 3 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_linker_parameters_show();
			continue;
		case	0x12 :
			accept_linker_parameters_losefocus();
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_linker_parameters_show();
			continue;
			case	0x100 :
				if ((retcode=accept_linker_parameters_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto3389 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* General */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_linker_parameters_losefocus();
							_Context->page_number = 1;
							accept_linker_parameters_show();
							}
						continue;
					case	0x3 :
						/* Linker */
						continue;
					case	0x4 :
						/* TargetFile */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_TargetFile += 1;
							_Context->value_TargetFile &= 1;
							}
						continue;
					case	0x5 :
						/* TargetName */
						continue;
					case	0x6 :
						/* Report */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Report += 1;
							_Context->value_Report &= 1;
							}
						continue;
					case	0x7 :
						/* ReportName */
						continue;
					case	0x8 :
						/* Debug */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Debug += 1;
							_Context->value_Debug &= 1;
							}
						continue;
					case	0x9 :
						/* InputTrace */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_InputTrace += 1;
							_Context->value_InputTrace &= 1;
							}
						continue;
					case	0xa :
						/* OutputTrace */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_OutputTrace += 1;
							_Context->value_OutputTrace &= 1;
							}
						continue;
					case	0xb :
						/* Verbose */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Verbose += 1;
							_Context->value_Verbose &= 1;
							}
						continue;
					case	0xc :
						/* Modules */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_linker_parameters_losefocus();
							_Context->page_number = 2;
							accept_linker_parameters_show();
							}
						continue;
					case	0xd :
						/* Modules */
						continue;
					case	0xe :
						/* Inclusion */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_linker_parameters_losefocus();
							_Context->page_number = 3;
							accept_linker_parameters_show();
							}
						continue;
					case	0xf :
						/* IncludePath */
						continue;
					case	0x10 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(145,435,120,30,2,16,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(145,435,120,30,2,16,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x11 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(525,435,120,30,2,16,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(525,435,120,30,2,16,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
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
				_Context->focus_item=17;
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

public	int	accept_linker_parameters(
	char * pLinker,
	char * pTargetFile,
	char * pTargetName,
	char * pReport,
	char * pReportName,
	char * pDebug,
	char * pInputTrace,
	char * pOutputTrace,
	char * pVerbose,
	char * pModules,
	char * pIncludePath)
{
	int	status=0;
	status = accept_linker_parameters_create(
	 pLinker,
	 pTargetFile,
	 pTargetName,
	 pReport,
	 pReportName,
	 pDebug,
	 pInputTrace,
	 pOutputTrace,
	 pVerbose,
	 pModules,
	 pIncludePath);
	if ( status != 0) return(status);
	status = accept_linker_parameters_show();
		enter_modal();
	status = accept_linker_parameters_focus();
		leave_modal();
	status = accept_linker_parameters_hide();
	status = accept_linker_parameters_remove(
	 pLinker,
	 pTargetFile,
	 pTargetName,
	 pReport,
	 pReportName,
	 pDebug,
	 pInputTrace,
	 pOutputTrace,
	 pVerbose,
	 pModules,
	 pIncludePath);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vlink_c */
