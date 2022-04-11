
#ifndef _vlink_c
#define _vlink_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vlink.xml                                                */
/* Target         : vlink.c                                                  */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3571   ""
#define fr__Auto3571   ""
#define it__Auto3571   ""
#define es__Auto3571   ""
#define de__Auto3571   ""
#define nl__Auto3571   ""
#define pt__Auto3571   ""
#define xx__Auto3571   ""
#define en_Auto3572   "ABAL++ Object Linker"
#define fr_Auto3572   "Editeur de liens ABAL++"
#define it_Auto3572   "ABAL++ Object Linker"
#define es_Auto3572   "ABAL++ Object Linker"
#define de_Auto3572   "ABAL++ Object Linker"
#define nl_Auto3572   "ABAL++ Object Linker"
#define pt_Auto3572   "ABAL++ Object Linker"
#define xx_Auto3572   "ABAL++ Object Linker"
#define en_Auto3573   "oldicon.gif"
#define fr_Auto3573   "oldicon.gif"
#define it_Auto3573   "oldicon.gif"
#define es_Auto3573   "oldicon.gif"
#define de_Auto3573   "oldicon.gif"
#define nl_Auto3573   "oldicon.gif"
#define pt_Auto3573   "oldicon.gif"
#define xx_Auto3573   "oldicon.gif"
#define en_General   "&General"
#define fr_General   "&G‚n‚ral"
#define it_General   "&General"
#define es_General   "&General"
#define de_General   "&General"
#define nl_General   "&General"
#define pt_General   "&General"
#define xx_General   "&General"
#define en_Auto3575   "abal.gif"
#define fr_Auto3575   "abal.gif"
#define it_Auto3575   "abal.gif"
#define es_Auto3575   "abal.gif"
#define de_Auto3575   "abal.gif"
#define nl_Auto3575   "abal.gif"
#define pt_Auto3575   "abal.gif"
#define xx_Auto3575   "abal.gif"
#define en_Auto3576   "Linker Program Name"
#define fr_Auto3576   "Nom de l'‚diteur de liens"
#define it_Auto3576   "Linker Program Name"
#define es_Auto3576   "Linker Program Name"
#define de_Auto3576   "Linker Program Name"
#define nl_Auto3576   "Linker Program Name"
#define pt_Auto3576   "Linker Program Name"
#define xx_Auto3576   "Linker Program Name"
#define en_Linker   ""
#define en_TargetFile   "Targ&et File"
#define fr_TargetFile   "&Fichier cible"
#define it_TargetFile   "Targ&et File"
#define es_TargetFile   "Targ&et File"
#define de_TargetFile   "Targ&et File"
#define nl_TargetFile   "Targ&et File"
#define pt_TargetFile   "Targ&et File"
#define xx_TargetFile   "Targ&et File"
#define en_TargetName   ""
#define en_Report   "&Html Report"
#define fr_Report   "&Rapport Html"
#define it_Report   "&Html Report"
#define es_Report   "&Html Report"
#define de_Report   "&Html Report"
#define nl_Report   "&Html Report"
#define pt_Report   "&Html Report"
#define xx_Report   "&Html Report"
#define en_ReportName   ""
#define en_Debug   "&Debug"
#define fr_Debug   "&Debug"
#define it_Debug   "&Debug"
#define es_Debug   "&Debug"
#define de_Debug   "&Debug"
#define nl_Debug   "&Debug"
#define pt_Debug   "&Debug"
#define xx_Debug   "&Debug"
#define en_InputTrace   "&Trace Input"
#define fr_InputTrace   "&Trace Entr‚e"
#define it_InputTrace   "&Trace Input"
#define es_InputTrace   "&Trace Input"
#define de_InputTrace   "&Trace Input"
#define nl_InputTrace   "&Trace Input"
#define pt_InputTrace   "&Trace Input"
#define xx_InputTrace   "&Trace Input"
#define en_OutputTrace   "T&race Output"
#define fr_OutputTrace   "Trace &Sortie"
#define it_OutputTrace   "T&race Output"
#define es_OutputTrace   "T&race Output"
#define de_OutputTrace   "T&race Output"
#define nl_OutputTrace   "T&race Output"
#define pt_OutputTrace   "T&race Output"
#define xx_OutputTrace   "T&race Output"
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
#define it_Modules   "&Modules"
#define es_Modules   "&Modules"
#define de_Modules   "&Modules"
#define nl_Modules   "&Modules"
#define pt_Modules   "&Modules"
#define xx_Modules   "&Modules"
#define en_ModuleList   ""
#define en__ModuleList   ""
#define en_Inclusion   "&Inclusion"
#define fr_Inclusion   "&Inclusion"
#define it_Inclusion   "&Inclusion"
#define es_Inclusion   "&Inclusion"
#define de_Inclusion   "&Inclusion"
#define nl_Inclusion   "&Inclusion"
#define pt_Inclusion   "&Inclusion"
#define xx_Inclusion   "&Inclusion"
#define en_Auto3577   "ok.gif"
#define fr_Auto3577   "ok.gif"
#define it_Auto3577   "ok.gif"
#define es_Auto3577   "ok.gif"
#define de_Auto3577   "ok.gif"
#define nl_Auto3577   "ok.gif"
#define pt_Auto3577   "ok.gif"
#define xx_Auto3577   "ok.gif"
#define en_Auto3578   "cancel.gif"
#define fr_Auto3578   "cancel.gif"
#define it_Auto3578   "cancel.gif"
#define es_Auto3578   "cancel.gif"
#define de_Auto3578   "cancel.gif"
#define nl_Auto3578   "cancel.gif"
#define pt_Auto3578   "cancel.gif"
#define xx_Auto3578   "cancel.gif"

private struct accept_linker_parameters_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[3+1];
	char * msg_Auto3571[8];
	char * hint_Auto3571[8];
	int	x_Auto3571;
	int	y_Auto3571;
	int	w_Auto3571;
	int	h_Auto3571;
	char * msg_Auto3572[8];
	char * hint_Auto3572[8];
	char * msg_Auto3573[8];
	char * hint_Auto3573[8];
	char * msg_General[8];
	int	trigger_General;
	char * hint_General[8];
	int	page_number;
	char * hint_Auto3574[8];
	char * msg_Auto3575[8];
	char * hint_Auto3575[8];
	char * msg_Auto3576[8];
	char * hint_Auto3576[8];
	char * hint_Linker[8];
	char	buffer_Linker[256];
	char * msg_TargetFile[8];
	int	trigger_TargetFile;
	char * hint_TargetFile[8];
	int	value_TargetFile;
	char * hint_TargetName[8];
	char	buffer_TargetName[256];
	char * msg_Report[8];
	int	trigger_Report;
	char * hint_Report[8];
	int	value_Report;
	char * hint_ReportName[8];
	char	buffer_ReportName[256];
	char * msg_Debug[8];
	int	trigger_Debug;
	char * hint_Debug[8];
	int	value_Debug;
	char * msg_InputTrace[8];
	int	trigger_InputTrace;
	char * hint_InputTrace[8];
	int	value_InputTrace;
	char * msg_OutputTrace[8];
	int	trigger_OutputTrace;
	char * hint_OutputTrace[8];
	int	value_OutputTrace;
	char * msg_Verbose[8];
	int	trigger_Verbose;
	char * hint_Verbose[8];
	int	value_Verbose;
	char * msg_Modules[8];
	int	trigger_Modules;
	char * hint_Modules[8];
	char * hint_ModuleList[8];
	char	buffer_ModuleList[721];
	char * msg_Inclusion[8];
	int	trigger_Inclusion;
	char * hint_Inclusion[8];
	char * hint_IncludePath[8];
	char	buffer_IncludePath[721];
	char * msg_Auto3577[8];
	int	trigger_Auto3577;
	char * hint_Auto3577[8];
	char * msg_Auto3578[8];
	int	trigger_Auto3578;
	char * hint_Auto3578[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[12];
	};
static int	vfh[16];
private int on_Auto3577_event(struct accept_linker_parameters_context * _Context);
private int on_Auto3578_event(struct accept_linker_parameters_context * _Context);

public	int	accept_linker_parameters_create(
	struct accept_linker_parameters_context ** cptr,
	char * pLinker,
	char * pTargetFile,
	char * pTargetName,
	char * pReport,
	char * pReportName,
	char * pDebug,
	char * pInputTrace,
	char * pOutputTrace,
	char * pVerbose,
	char * pModuleList,
	char * pIncludePath)
{

	int i;
	struct accept_linker_parameters_context * _Context=(struct accept_linker_parameters_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("bmap0414.fmf",12);
	if (!(_Context = allocate( sizeof( struct accept_linker_parameters_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=17;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWSWSWWWWSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Linker, 255, pLinker);
		visual_transferin((void *) 0, 0, pTargetFile);
		if (!( pTargetFile )) _Context->value_TargetFile=0;
		else	_Context->value_TargetFile = *((int *)pTargetFile);
		visual_transferin(_Context->buffer_TargetName, 255, pTargetName);
		visual_transferin((void *) 0, 0, pReport);
		if (!( pReport )) _Context->value_Report=0;
		else	_Context->value_Report = *((int *)pReport);
		visual_transferin(_Context->buffer_ReportName, 255, pReportName);
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
		visual_transferin(_Context->buffer_ModuleList, 720, pModuleList);
		visual_transferin(_Context->buffer_IncludePath, 720, pIncludePath);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3571[i]=" ";
	_Context->hint_Auto3571[0]=en__Auto3571;
	_Context->hint_Auto3571[1]=fr__Auto3571;
	_Context->hint_Auto3571[2]=it__Auto3571;
	_Context->hint_Auto3571[3]=es__Auto3571;
	_Context->hint_Auto3571[4]=de__Auto3571;
	_Context->hint_Auto3571[5]=nl__Auto3571;
	_Context->hint_Auto3571[6]=pt__Auto3571;
	_Context->hint_Auto3571[7]=xx__Auto3571;
	_Context->x_Auto3571=135;
	_Context->y_Auto3571=110;
	_Context->w_Auto3571=530;
	_Context->h_Auto3571=380;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3572[i]=" ";
	_Context->msg_Auto3572[0]=en_Auto3572;
	_Context->msg_Auto3572[1]=fr_Auto3572;
	_Context->msg_Auto3572[2]=it_Auto3572;
	_Context->msg_Auto3572[3]=es_Auto3572;
	_Context->msg_Auto3572[4]=de_Auto3572;
	_Context->msg_Auto3572[5]=nl_Auto3572;
	_Context->msg_Auto3572[6]=pt_Auto3572;
	_Context->msg_Auto3572[7]=xx_Auto3572;
	for (i=0; i < 8; i++)_Context->msg_Auto3573[i]=" ";
	_Context->msg_Auto3573[0]=en_Auto3573;
	_Context->msg_Auto3573[1]=fr_Auto3573;
	_Context->msg_Auto3573[2]=it_Auto3573;
	_Context->msg_Auto3573[3]=es_Auto3573;
	_Context->msg_Auto3573[4]=de_Auto3573;
	_Context->msg_Auto3573[5]=nl_Auto3573;
	_Context->msg_Auto3573[6]=pt_Auto3573;
	_Context->msg_Auto3573[7]=xx_Auto3573;
	for (i=0; i < 8; i++)_Context->msg_General[i]=" ";
	_Context->msg_General[0]=en_General;
	_Context->msg_General[1]=fr_General;
	_Context->msg_General[2]=it_General;
	_Context->msg_General[3]=es_General;
	_Context->msg_General[4]=de_General;
	_Context->msg_General[5]=nl_General;
	_Context->msg_General[6]=pt_General;
	_Context->msg_General[7]=xx_General;
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_Auto3575[i]=" ";
	_Context->msg_Auto3575[0]=en_Auto3575;
	_Context->msg_Auto3575[1]=fr_Auto3575;
	_Context->msg_Auto3575[2]=it_Auto3575;
	_Context->msg_Auto3575[3]=es_Auto3575;
	_Context->msg_Auto3575[4]=de_Auto3575;
	_Context->msg_Auto3575[5]=nl_Auto3575;
	_Context->msg_Auto3575[6]=pt_Auto3575;
	_Context->msg_Auto3575[7]=xx_Auto3575;
	for (i=0; i < 8; i++)_Context->msg_Auto3576[i]=" ";
	_Context->msg_Auto3576[0]=en_Auto3576;
	_Context->msg_Auto3576[1]=fr_Auto3576;
	_Context->msg_Auto3576[2]=it_Auto3576;
	_Context->msg_Auto3576[3]=es_Auto3576;
	_Context->msg_Auto3576[4]=de_Auto3576;
	_Context->msg_Auto3576[5]=nl_Auto3576;
	_Context->msg_Auto3576[6]=pt_Auto3576;
	_Context->msg_Auto3576[7]=xx_Auto3576;
	for (i=0; i < 8; i++)_Context->msg_TargetFile[i]=" ";
	_Context->msg_TargetFile[0]=en_TargetFile;
	_Context->msg_TargetFile[1]=fr_TargetFile;
	_Context->msg_TargetFile[2]=it_TargetFile;
	_Context->msg_TargetFile[3]=es_TargetFile;
	_Context->msg_TargetFile[4]=de_TargetFile;
	_Context->msg_TargetFile[5]=nl_TargetFile;
	_Context->msg_TargetFile[6]=pt_TargetFile;
	_Context->msg_TargetFile[7]=xx_TargetFile;
	for (i=0; i < 8; i++)_Context->msg_Report[i]=" ";
	_Context->msg_Report[0]=en_Report;
	_Context->msg_Report[1]=fr_Report;
	_Context->msg_Report[2]=it_Report;
	_Context->msg_Report[3]=es_Report;
	_Context->msg_Report[4]=de_Report;
	_Context->msg_Report[5]=nl_Report;
	_Context->msg_Report[6]=pt_Report;
	_Context->msg_Report[7]=xx_Report;
	for (i=0; i < 8; i++)_Context->msg_Debug[i]=" ";
	_Context->msg_Debug[0]=en_Debug;
	_Context->msg_Debug[1]=fr_Debug;
	_Context->msg_Debug[2]=it_Debug;
	_Context->msg_Debug[3]=es_Debug;
	_Context->msg_Debug[4]=de_Debug;
	_Context->msg_Debug[5]=nl_Debug;
	_Context->msg_Debug[6]=pt_Debug;
	_Context->msg_Debug[7]=xx_Debug;
	for (i=0; i < 8; i++)_Context->msg_InputTrace[i]=" ";
	_Context->msg_InputTrace[0]=en_InputTrace;
	_Context->msg_InputTrace[1]=fr_InputTrace;
	_Context->msg_InputTrace[2]=it_InputTrace;
	_Context->msg_InputTrace[3]=es_InputTrace;
	_Context->msg_InputTrace[4]=de_InputTrace;
	_Context->msg_InputTrace[5]=nl_InputTrace;
	_Context->msg_InputTrace[6]=pt_InputTrace;
	_Context->msg_InputTrace[7]=xx_InputTrace;
	for (i=0; i < 8; i++)_Context->msg_OutputTrace[i]=" ";
	_Context->msg_OutputTrace[0]=en_OutputTrace;
	_Context->msg_OutputTrace[1]=fr_OutputTrace;
	_Context->msg_OutputTrace[2]=it_OutputTrace;
	_Context->msg_OutputTrace[3]=es_OutputTrace;
	_Context->msg_OutputTrace[4]=de_OutputTrace;
	_Context->msg_OutputTrace[5]=nl_OutputTrace;
	_Context->msg_OutputTrace[6]=pt_OutputTrace;
	_Context->msg_OutputTrace[7]=xx_OutputTrace;
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
	_Context->msg_Modules[2]=it_Modules;
	_Context->msg_Modules[3]=es_Modules;
	_Context->msg_Modules[4]=de_Modules;
	_Context->msg_Modules[5]=nl_Modules;
	_Context->msg_Modules[6]=pt_Modules;
	_Context->msg_Modules[7]=xx_Modules;
	_Context->focus_pages[2]=12;
	_Context->hint_ModuleList[0]=en__ModuleList;
	for (i=0; i < 8; i++)_Context->msg_Inclusion[i]=" ";
	_Context->msg_Inclusion[0]=en_Inclusion;
	_Context->msg_Inclusion[1]=fr_Inclusion;
	_Context->msg_Inclusion[2]=it_Inclusion;
	_Context->msg_Inclusion[3]=es_Inclusion;
	_Context->msg_Inclusion[4]=de_Inclusion;
	_Context->msg_Inclusion[5]=nl_Inclusion;
	_Context->msg_Inclusion[6]=pt_Inclusion;
	_Context->msg_Inclusion[7]=xx_Inclusion;
	_Context->focus_pages[3]=14;
	for (i=0; i < 8; i++)_Context->msg_Auto3577[i]=" ";
	_Context->msg_Auto3577[0]=en_Auto3577;
	_Context->msg_Auto3577[1]=fr_Auto3577;
	_Context->msg_Auto3577[2]=it_Auto3577;
	_Context->msg_Auto3577[3]=es_Auto3577;
	_Context->msg_Auto3577[4]=de_Auto3577;
	_Context->msg_Auto3577[5]=nl_Auto3577;
	_Context->msg_Auto3577[6]=pt_Auto3577;
	_Context->msg_Auto3577[7]=xx_Auto3577;
	for (i=0; i < 8; i++)_Context->msg_Auto3578[i]=" ";
	_Context->msg_Auto3578[0]=en_Auto3578;
	_Context->msg_Auto3578[1]=fr_Auto3578;
	_Context->msg_Auto3578[2]=it_Auto3578;
	_Context->msg_Auto3578[3]=es_Auto3578;
	_Context->msg_Auto3578[4]=de_Auto3578;
	_Context->msg_Auto3578[5]=nl_Auto3578;
	_Context->msg_Auto3578[6]=pt_Auto3578;
	_Context->msg_Auto3578[7]=xx_Auto3578;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3571,_Context->y_Auto3571,530+10,380+10);
	return(0);
}

public 	int	accept_linker_parameters_hide(struct accept_linker_parameters_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3571,_Context->y_Auto3571);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_linker_parameters_remove(
	struct accept_linker_parameters_context * _Context,
	char * pLinker,
	char * pTargetFile,
	char * pTargetName,
	char * pReport,
	char * pReportName,
	char * pDebug,
	char * pInputTrace,
	char * pOutputTrace,
	char * pVerbose,
	char * pModuleList,
	char * pIncludePath)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWSWSWWWWSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Linker, 255, pLinker);
		visual_transferout((void *) 0, 0, pTargetFile);
		if ( pTargetFile != (char *) 0)
			*((int*)pTargetFile) = _Context->value_TargetFile;
		visual_transferout(_Context->buffer_TargetName, 255, pTargetName);
		visual_transferout((void *) 0, 0, pReport);
		if ( pReport != (char *) 0)
			*((int*)pReport) = _Context->value_Report;
		visual_transferout(_Context->buffer_ReportName, 255, pReportName);
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
		visual_transferout(_Context->buffer_ModuleList, 720, pModuleList);
		visual_transferout(_Context->buffer_IncludePath, 720, pIncludePath);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_linker_parameters_show(struct accept_linker_parameters_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3571,_Context->y_Auto3571);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3571,_Context->y_Auto3571,530,380,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3571,_Context->y_Auto3571,530,380,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3571+20,_Context->y_Auto3571+30,437,20,vfh[3],27,0,_Context->msg_Auto3572[_Context->language],strlen(_Context->msg_Auto3572[_Context->language]),1282);
	visual_image(_Context->x_Auto3571+420,_Context->y_Auto3571+40,30,30,_Context->msg_Auto3573[_Context->language],3);
	if (_Context->page_number == 1 ) {
	_Context->trigger_General=visual_trigger_code(_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]));
	visual_tabpage(_Context->x_Auto3571+10,_Context->y_Auto3571+60,500,250,vfh[2],_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto3571+10,_Context->y_Auto3571+60,500,250,vfh[2],_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3571+30,_Context->y_Auto3571+230,460,40,2);
		}
	visual_image(_Context->x_Auto3571+460,_Context->y_Auto3571+30,50,50,_Context->msg_Auto3575[_Context->language],3);
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3571+30,_Context->y_Auto3571+100,462,24,vfh[2],16,0,_Context->msg_Auto3576[_Context->language],strlen(_Context->msg_Auto3576[_Context->language]),1283);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3571+30,_Context->y_Auto3571+120,464+2,16+2,5);
	visual_text(_Context->x_Auto3571+30+1,_Context->y_Auto3571+120+1,464,16,vfh[1],16,28,_Context->buffer_Linker,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_TargetFile=visual_trigger_code(_Context->msg_TargetFile[_Context->language],strlen(_Context->msg_TargetFile[_Context->language]));
	visual_check(_Context->x_Auto3571+30,_Context->y_Auto3571+150,126,16,vfh[2],16,28,_Context->msg_TargetFile[_Context->language],strlen(_Context->msg_TargetFile[_Context->language]),_Context->value_TargetFile|0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3571+150,_Context->y_Auto3571+150,344+2,16+2,5);
	visual_text(_Context->x_Auto3571+150+1,_Context->y_Auto3571+150+1,344,16,vfh[1],16,28,_Context->buffer_TargetName,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Report=visual_trigger_code(_Context->msg_Report[_Context->language],strlen(_Context->msg_Report[_Context->language]));
	visual_check(_Context->x_Auto3571+30,_Context->y_Auto3571+180,126,16,vfh[2],16,28,_Context->msg_Report[_Context->language],strlen(_Context->msg_Report[_Context->language]),_Context->value_Report|0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3571+150,_Context->y_Auto3571+180,344+2,16+2,5);
	visual_text(_Context->x_Auto3571+150+1,_Context->y_Auto3571+180+1,344,16,vfh[1],16,28,_Context->buffer_ReportName,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Debug=visual_trigger_code(_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]));
	visual_check(_Context->x_Auto3571+40,_Context->y_Auto3571+240,84,16,vfh[2],16,28,_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]),_Context->value_Debug|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_InputTrace=visual_trigger_code(_Context->msg_InputTrace[_Context->language],strlen(_Context->msg_InputTrace[_Context->language]));
	visual_check(_Context->x_Auto3571+230,_Context->y_Auto3571+240,126,16,vfh[2],16,28,_Context->msg_InputTrace[_Context->language],strlen(_Context->msg_InputTrace[_Context->language]),_Context->value_InputTrace|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_OutputTrace=visual_trigger_code(_Context->msg_OutputTrace[_Context->language],strlen(_Context->msg_OutputTrace[_Context->language]));
	visual_check(_Context->x_Auto3571+350,_Context->y_Auto3571+240,126,16,vfh[2],16,28,_Context->msg_OutputTrace[_Context->language],strlen(_Context->msg_OutputTrace[_Context->language]),_Context->value_OutputTrace|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Verbose=visual_trigger_code(_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]));
	visual_check(_Context->x_Auto3571+130,_Context->y_Auto3571+240,98,16,vfh[2],16,28,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),_Context->value_Verbose|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Modules=visual_trigger_code(_Context->msg_Modules[_Context->language],strlen(_Context->msg_Modules[_Context->language]));
	visual_tabpage(_Context->x_Auto3571+10,_Context->y_Auto3571+60,500,250,vfh[2],_Context->msg_Modules[_Context->language],strlen(_Context->msg_Modules[_Context->language]),84,2);
	} else {
		visual_tabpage(_Context->x_Auto3571+10,_Context->y_Auto3571+60,500,250,vfh[2],_Context->msg_Modules[_Context->language],strlen(_Context->msg_Modules[_Context->language]),84,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3571+20,_Context->y_Auto3571+100,480+2,192+2,5);
	visual_text(_Context->x_Auto3571+20+1,_Context->y_Auto3571+100+1,480,192,vfh[1],16,28,_Context->buffer_ModuleList,720,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_Inclusion=visual_trigger_code(_Context->msg_Inclusion[_Context->language],strlen(_Context->msg_Inclusion[_Context->language]));
	visual_tabpage(_Context->x_Auto3571+10,_Context->y_Auto3571+60,500,250,vfh[2],_Context->msg_Inclusion[_Context->language],strlen(_Context->msg_Inclusion[_Context->language]),171,2);
	} else {
		visual_tabpage(_Context->x_Auto3571+10,_Context->y_Auto3571+60,500,250,vfh[2],_Context->msg_Inclusion[_Context->language],strlen(_Context->msg_Inclusion[_Context->language]),171,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3571+20,_Context->y_Auto3571+100,480+2,192+2,5);
	visual_text(_Context->x_Auto3571+20+1,_Context->y_Auto3571+100+1,480,192,vfh[1],16,28,_Context->buffer_IncludePath,720,0);
		}
	_Context->trigger_Auto3577=visual_trigger_code(_Context->msg_Auto3577[_Context->language],strlen(_Context->msg_Auto3577[_Context->language]));
	visual_button(_Context->x_Auto3571+10,_Context->y_Auto3571+320,56,48,vfh[2],34,0,_Context->msg_Auto3577[_Context->language],strlen(_Context->msg_Auto3577[_Context->language]),1040);
	_Context->trigger_Auto3578=visual_trigger_code(_Context->msg_Auto3578[_Context->language],strlen(_Context->msg_Auto3578[_Context->language]));
	visual_button(_Context->x_Auto3571+450,_Context->y_Auto3571+320,56,48,vfh[2],34,0,_Context->msg_Auto3578[_Context->language],strlen(_Context->msg_Auto3578[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3571,_Context->y_Auto3571,530,380);

	return(0);
}

private int General_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This page describes the general link controls for link phase command ";
			mptr[1]="line parameters.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Linker_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field provides the full path and filename of the abal module ";
			mptr[1]="linker to be used for the secondary phase of  abal program production ";
			mptr[2]="for visual models which declare subordinate modules.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TargetFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This check field, when active, causes the specific target file name ";
			mptr[1]="to be used rather than the name of the program object amongst the ";
			mptr[2]="collection of modules.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TargetName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field provides the name of the executable target program ";
			mptr[1]="file that is to be generated as a result of the  link operation.  ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Report_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This check box, when checked, activates the generation of  the link ";
			mptr[1]="phase report to the corresponding html file.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ReportName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field provides the name of the file to which the html report ";
			mptr[1]="is to generated describing the result of the  link and providing an ";
			mptr[2]="exhastive list of components combined to form the target.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Debug_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control may be checked to indicate that symbolic  information ";
			mptr[1]="is to be generated for debug purposes.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int InputTrace_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "When this check control is active detailed trace information, describing ";
			mptr[1]="the  various input modules, will be printed to the text screen.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OutputTrace_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "When this check is active detailed trace information concerning the ";
			mptr[1]="production of target blocks will be printer to the text screen.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Verbose_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "When this check control is active information messages will be printed ";
			mptr[1]="to the text screen during the link operation.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Modules_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This page provides the list of modules required to be linked.  ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ModuleList_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field displays the list of modules to be linked to produce ";
			mptr[1]="the abal executable program.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IncludePath_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field displays the list of modules to be linked to produce ";
			mptr[1]="the abal executable program.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3577_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the ACCEPT button any changes made to the various    parameters ";
			mptr[1]="will take effect.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3578_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the CANCEL button any modifications performed will be ";
			mptr[1]="   discarded.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3571action(struct accept_linker_parameters_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_linker_parameters_hide(_Context);

		_Context->x_Auto3571 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3571 < 0) { _Context->x_Auto3571=0; }
		_Context->y_Auto3571 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3571 < 0) { _Context->y_Auto3571=0; }
			accept_linker_parameters_show(_Context);

		visual_thaw(_Context->x_Auto3571,_Context->y_Auto3571,530,380);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3577_event(struct accept_linker_parameters_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3578_event(struct accept_linker_parameters_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_linker_parameters_event(
struct accept_linker_parameters_context * _Context){
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
		if (_Context->trigger_Auto3577 == mb ) return(16);
		if (_Context->trigger_Auto3578 == mb ) return(17);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3571+509) )  
	&&  (my >= (_Context->y_Auto3571+4) )  
	&&  (mx <= (_Context->x_Auto3571+526) )  
	&&  (my <= (_Context->y_Auto3571+20) )) {
		return(1);	/* Auto3571 */

		}
	if ((mx >= (_Context->x_Auto3571+493) )  
	&&  (my >= (_Context->y_Auto3571+4) )  
	&&  (mx <= (_Context->x_Auto3571+510) )  
	&&  (my <= (_Context->y_Auto3571+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vlink.htm");
			};
		return(-1);	/* Auto3571 */

		}
	if ((mx >= (_Context->x_Auto3571+477) )  
	&&  (my >= (_Context->y_Auto3571+4) )  
	&&  (mx <= (_Context->x_Auto3571+494) )  
	&&  (my <= (_Context->y_Auto3571+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_linker_parameters_show(_Context);
		return(-1);	/* Auto3571 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3571+4) )  
		&&  (my >= (_Context->y_Auto3571+4) )  
		&&  (mx <= (_Context->x_Auto3571+462) )  
		&&  (my <= (_Context->y_Auto3571+20) )) {
			return( Auto3571action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto3571+10+0) ) 
		&&  ( my >= (_Context->y_Auto3571+60) ) 
		&&  ( mx <= (_Context->x_Auto3571+10+83) ) 
		&&  ( my <= (_Context->y_Auto3571+60+24))) {
			return(2); /* General */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3571+30) ) 
		&&  ( my >= (_Context->y_Auto3571+120) ) 
		&&  ( mx <= (_Context->x_Auto3571+30+464) ) 
		&&  ( my <= (_Context->y_Auto3571+120+16))) {
			return(3); /* Linker */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3571+30) ) 
		&&  ( my >= (_Context->y_Auto3571+150) ) 
		&&  ( mx <= (_Context->x_Auto3571+30+126) ) 
		&&  ( my <= (_Context->y_Auto3571+150+16))) {
			return(4); /* TargetFile */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3571+150) ) 
		&&  ( my >= (_Context->y_Auto3571+150) ) 
		&&  ( mx <= (_Context->x_Auto3571+150+344) ) 
		&&  ( my <= (_Context->y_Auto3571+150+16))) {
			return(5); /* TargetName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3571+30) ) 
		&&  ( my >= (_Context->y_Auto3571+180) ) 
		&&  ( mx <= (_Context->x_Auto3571+30+126) ) 
		&&  ( my <= (_Context->y_Auto3571+180+16))) {
			return(6); /* Report */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3571+150) ) 
		&&  ( my >= (_Context->y_Auto3571+180) ) 
		&&  ( mx <= (_Context->x_Auto3571+150+344) ) 
		&&  ( my <= (_Context->y_Auto3571+180+16))) {
			return(7); /* ReportName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3571+40) ) 
		&&  ( my >= (_Context->y_Auto3571+240) ) 
		&&  ( mx <= (_Context->x_Auto3571+40+84) ) 
		&&  ( my <= (_Context->y_Auto3571+240+16))) {
			return(8); /* Debug */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3571+230) ) 
		&&  ( my >= (_Context->y_Auto3571+240) ) 
		&&  ( mx <= (_Context->x_Auto3571+230+126) ) 
		&&  ( my <= (_Context->y_Auto3571+240+16))) {
			return(9); /* InputTrace */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3571+350) ) 
		&&  ( my >= (_Context->y_Auto3571+240) ) 
		&&  ( mx <= (_Context->x_Auto3571+350+126) ) 
		&&  ( my <= (_Context->y_Auto3571+240+16))) {
			return(10); /* OutputTrace */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3571+130) ) 
		&&  ( my >= (_Context->y_Auto3571+240) ) 
		&&  ( mx <= (_Context->x_Auto3571+130+98) ) 
		&&  ( my <= (_Context->y_Auto3571+240+16))) {
			return(11); /* Verbose */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto3571+10+84) ) 
		&&  ( my >= (_Context->y_Auto3571+60) ) 
		&&  ( mx <= (_Context->x_Auto3571+10+170) ) 
		&&  ( my <= (_Context->y_Auto3571+60+24))) {
			return(12); /* Modules */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3571+20) ) 
		&&  ( my >= (_Context->y_Auto3571+100) ) 
		&&  ( mx <= (_Context->x_Auto3571+20+480) ) 
		&&  ( my <= (_Context->y_Auto3571+100+192))) {
			return(13); /* ModuleList */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_Auto3571+10+171) ) 
		&&  ( my >= (_Context->y_Auto3571+60) ) 
		&&  ( mx <= (_Context->x_Auto3571+10+259) ) 
		&&  ( my <= (_Context->y_Auto3571+60+24))) {
			return(14); /* Inclusion */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3571+20) ) 
		&&  ( my >= (_Context->y_Auto3571+100) ) 
		&&  ( mx <= (_Context->x_Auto3571+20+480) ) 
		&&  ( my <= (_Context->y_Auto3571+100+192))) {
			return(15); /* IncludePath */
			}
		}
	if (( mx >= (_Context->x_Auto3571+10) ) 
	&&  ( my >= (_Context->y_Auto3571+320) ) 
	&&  ( mx <= (_Context->x_Auto3571+10+56) ) 
	&&  ( my <= (_Context->y_Auto3571+320+48))) {
		return(16); /* Auto3577 */
		}
	if (( mx >= (_Context->x_Auto3571+450) ) 
	&&  ( my >= (_Context->y_Auto3571+320) ) 
	&&  ( mx <= (_Context->x_Auto3571+450+56) ) 
	&&  ( my <= (_Context->y_Auto3571+320+48))) {
		return(17); /* Auto3578 */
		}

	return(-1);
}


public	int	accept_linker_parameters_losefocus(struct accept_linker_parameters_context * _Context)
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


public	int	accept_linker_parameters_focus(struct accept_linker_parameters_context * _Context)
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
					_Context->keycode = visual_edit(_Context->x_Auto3571+30+1,_Context->y_Auto3571+120+1,464,16,vfh[1],_Context->buffer_Linker,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* TargetFile */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3571+30,_Context->y_Auto3571+150,126,16,vfh[2],16,28,_Context->msg_TargetFile[_Context->language],strlen(_Context->msg_TargetFile[_Context->language]),(_Context->value_TargetFile |2));
					_Context->keycode = visual_getch();
					_Context->trigger_TargetFile=visual_trigger_code(_Context->msg_TargetFile[_Context->language],strlen(_Context->msg_TargetFile[_Context->language]));
	visual_check(_Context->x_Auto3571+30,_Context->y_Auto3571+150,126,16,vfh[2],16,28,_Context->msg_TargetFile[_Context->language],strlen(_Context->msg_TargetFile[_Context->language]),_Context->value_TargetFile|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* TargetName */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3571+150+1,_Context->y_Auto3571+150+1,344,16,vfh[1],_Context->buffer_TargetName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* Report */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3571+30,_Context->y_Auto3571+180,126,16,vfh[2],16,28,_Context->msg_Report[_Context->language],strlen(_Context->msg_Report[_Context->language]),(_Context->value_Report |2));
					_Context->keycode = visual_getch();
					_Context->trigger_Report=visual_trigger_code(_Context->msg_Report[_Context->language],strlen(_Context->msg_Report[_Context->language]));
	visual_check(_Context->x_Auto3571+30,_Context->y_Auto3571+180,126,16,vfh[2],16,28,_Context->msg_Report[_Context->language],strlen(_Context->msg_Report[_Context->language]),_Context->value_Report|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* ReportName */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3571+150+1,_Context->y_Auto3571+180+1,344,16,vfh[1],_Context->buffer_ReportName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* Debug */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3571+40,_Context->y_Auto3571+240,84,16,vfh[2],16,28,_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]),(_Context->value_Debug |2));
					_Context->keycode = visual_getch();
					_Context->trigger_Debug=visual_trigger_code(_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]));
	visual_check(_Context->x_Auto3571+40,_Context->y_Auto3571+240,84,16,vfh[2],16,28,_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]),_Context->value_Debug|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* InputTrace */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3571+230,_Context->y_Auto3571+240,126,16,vfh[2],16,28,_Context->msg_InputTrace[_Context->language],strlen(_Context->msg_InputTrace[_Context->language]),(_Context->value_InputTrace |2));
					_Context->keycode = visual_getch();
					_Context->trigger_InputTrace=visual_trigger_code(_Context->msg_InputTrace[_Context->language],strlen(_Context->msg_InputTrace[_Context->language]));
	visual_check(_Context->x_Auto3571+230,_Context->y_Auto3571+240,126,16,vfh[2],16,28,_Context->msg_InputTrace[_Context->language],strlen(_Context->msg_InputTrace[_Context->language]),_Context->value_InputTrace|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* OutputTrace */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3571+350,_Context->y_Auto3571+240,126,16,vfh[2],16,28,_Context->msg_OutputTrace[_Context->language],strlen(_Context->msg_OutputTrace[_Context->language]),(_Context->value_OutputTrace |2));
					_Context->keycode = visual_getch();
					_Context->trigger_OutputTrace=visual_trigger_code(_Context->msg_OutputTrace[_Context->language],strlen(_Context->msg_OutputTrace[_Context->language]));
	visual_check(_Context->x_Auto3571+350,_Context->y_Auto3571+240,126,16,vfh[2],16,28,_Context->msg_OutputTrace[_Context->language],strlen(_Context->msg_OutputTrace[_Context->language]),_Context->value_OutputTrace|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* Verbose */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3571+130,_Context->y_Auto3571+240,98,16,vfh[2],16,28,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),(_Context->value_Verbose |2));
					_Context->keycode = visual_getch();
					_Context->trigger_Verbose=visual_trigger_code(_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]));
	visual_check(_Context->x_Auto3571+130,_Context->y_Auto3571+240,98,16,vfh[2],16,28,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),_Context->value_Verbose|0);
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
				/* ModuleList */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3571+20+1,_Context->y_Auto3571+100+1,480,192,vfh[1],_Context->buffer_ModuleList,720);
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
					_Context->keycode = visual_edit(_Context->x_Auto3571+20+1,_Context->y_Auto3571+100+1,480,192,vfh[1],_Context->buffer_IncludePath,720);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* Auto3577 */
				_Context->trigger_Auto3577=visual_trigger_code(_Context->msg_Auto3577[_Context->language],strlen(_Context->msg_Auto3577[_Context->language]));
				visual_button(_Context->x_Auto3571+10,_Context->y_Auto3571+320,56,48,vfh[2],34,0,_Context->msg_Auto3577[_Context->language],strlen(_Context->msg_Auto3577[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3577=visual_trigger_code(_Context->msg_Auto3577[_Context->language],strlen(_Context->msg_Auto3577[_Context->language]));
	visual_button(_Context->x_Auto3571+10,_Context->y_Auto3571+320,56,48,vfh[2],34,0,_Context->msg_Auto3577[_Context->language],strlen(_Context->msg_Auto3577[_Context->language]),1040);
				break;
			case	0x11 :
				/* Auto3578 */
				_Context->trigger_Auto3578=visual_trigger_code(_Context->msg_Auto3578[_Context->language],strlen(_Context->msg_Auto3578[_Context->language]));
				visual_button(_Context->x_Auto3571+450,_Context->y_Auto3571+320,56,48,vfh[2],34,0,_Context->msg_Auto3578[_Context->language],strlen(_Context->msg_Auto3578[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3578=visual_trigger_code(_Context->msg_Auto3578[_Context->language],strlen(_Context->msg_Auto3578[_Context->language]));
	visual_button(_Context->x_Auto3571+450,_Context->y_Auto3571+320,56,48,vfh[2],34,0,_Context->msg_Auto3578[_Context->language],strlen(_Context->msg_Auto3578[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			accept_linker_parameters_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_linker_parameters_show(_Context);
			continue;
		case	0x2 :
			accept_linker_parameters_losefocus(_Context);
			_Context->page_number=3;
			_Context->focus_item=17;
			accept_linker_parameters_show(_Context);
			continue;
		case	0x3 :
			accept_linker_parameters_losefocus(_Context);
			if ( _Context->page_number < 3 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_linker_parameters_show(_Context);
			continue;
		case	0x12 :
			accept_linker_parameters_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_linker_parameters_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_linker_parameters_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (General_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Linker_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (TargetFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (TargetName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Report_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (ReportName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (Debug_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (InputTrace_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (OutputTrace_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Verbose_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Modules_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (ModuleList_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (IncludePath_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (Auto3577_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (Auto3578_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3571 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* General */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_linker_parameters_losefocus(_Context);
						_Context->page_number = 1;
						accept_linker_parameters_show(_Context);
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
						accept_linker_parameters_losefocus(_Context);
						_Context->page_number = 2;
						accept_linker_parameters_show(_Context);
						}
					continue;
				case	0xd :
					/* ModuleList */
					continue;
				case	0xe :
					/* Inclusion */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_linker_parameters_losefocus(_Context);
						_Context->page_number = 3;
						accept_linker_parameters_show(_Context);
						}
					continue;
				case	0xf :
					/* IncludePath */
					continue;
				case	0x10 :
					/* Auto3577 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3577=visual_trigger_code(_Context->msg_Auto3577[_Context->language],strlen(_Context->msg_Auto3577[_Context->language]));
						visual_button(_Context->x_Auto3571+10,_Context->y_Auto3571+320,56,48,vfh[2],34,0,_Context->msg_Auto3577[_Context->language],strlen(_Context->msg_Auto3577[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3577=visual_trigger_code(_Context->msg_Auto3577[_Context->language],strlen(_Context->msg_Auto3577[_Context->language]));
	visual_button(_Context->x_Auto3571+10,_Context->y_Auto3571+320,56,48,vfh[2],34,0,_Context->msg_Auto3577[_Context->language],strlen(_Context->msg_Auto3577[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3577_event(_Context)) != -1) break;

						}
					continue;
				case	0x11 :
					/* Auto3578 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3578=visual_trigger_code(_Context->msg_Auto3578[_Context->language],strlen(_Context->msg_Auto3578[_Context->language]));
						visual_button(_Context->x_Auto3571+450,_Context->y_Auto3571+320,56,48,vfh[2],34,0,_Context->msg_Auto3578[_Context->language],strlen(_Context->msg_Auto3578[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3578=visual_trigger_code(_Context->msg_Auto3578[_Context->language],strlen(_Context->msg_Auto3578[_Context->language]));
	visual_button(_Context->x_Auto3571+450,_Context->y_Auto3571+320,56,48,vfh[2],34,0,_Context->msg_Auto3578[_Context->language],strlen(_Context->msg_Auto3578[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3578_event(_Context)) != -1) break;

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
	char * pModuleList,
	char * pIncludePath)
{
	int	status=0;
	struct accept_linker_parameters_context * _Context=(struct accept_linker_parameters_context*) 0;
	status = accept_linker_parameters_create(
	&_Context,
	 pLinker,
	 pTargetFile,
	 pTargetName,
	 pReport,
	 pReportName,
	 pDebug,
	 pInputTrace,
	 pOutputTrace,
	 pVerbose,
	 pModuleList,
	 pIncludePath);
	if ( status != 0) return(status);
	status = accept_linker_parameters_show(_Context);
		enter_modal();
	status = accept_linker_parameters_focus(_Context);
		leave_modal();
	status = accept_linker_parameters_hide(_Context);
	status = accept_linker_parameters_remove(
	_Context,
	 pLinker,
	 pTargetFile,
	 pTargetName,
	 pReport,
	 pReportName,
	 pDebug,
	 pInputTrace,
	 pOutputTrace,
	 pVerbose,
	 pModuleList,
	 pIncludePath);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vlink_c */
