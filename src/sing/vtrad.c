
#ifndef _vtrad_c
#define _vtrad_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vtrad.xml                                                */
/* Target         : vtrad.c                                                  */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3594   ""
#define fr__Auto3594   ""
#define it__Auto3594   ""
#define es__Auto3594   ""
#define de__Auto3594   ""
#define nl__Auto3594   ""
#define pt__Auto3594   ""
#define xx__Auto3594   ""
#define en_Auto3596   "otricon.gif"
#define fr_Auto3596   "otricon.gif"
#define it_Auto3596   "otricon.gif"
#define es_Auto3596   "otricon.gif"
#define de_Auto3596   "otricon.gif"
#define nl_Auto3596   "otricon.gif"
#define pt_Auto3596   "otricon.gif"
#define xx_Auto3596   "otricon.gif"
#define en_auto726   "abalicon.gif"
#define fr_auto726   "abalicon.gif"
#define it_auto726   "abalicon.gif"
#define es_auto726   "abalicon.gif"
#define de_auto726   "abalicon.gif"
#define nl_auto726   "abalicon.gif"
#define pt_auto726   "abalicon.gif"
#define xx_auto726   "abalicon.gif"
#define en_Auto3597   "ABAL++ Translator Options"
#define fr_Auto3597   "Options du Traducteur d'ABAL++"
#define it_Auto3597   "ABAL++ Translator Options"
#define es_Auto3597   "ABAL++ Translator Options"
#define de_Auto3597   "ABAL++ Translator Options"
#define nl_Auto3597   "ABAL++ Translator Options"
#define pt_Auto3597   "ABAL++ Translator Options"
#define xx_Auto3597   "ABAL++ Translator Options"
#define en_auto281   "Source Filename"
#define fr_auto281   "Nom du source"
#define it_auto281   "Source Filename"
#define es_auto281   "Source Filename"
#define de_auto281   "Source Filename"
#define nl_auto281   "Source Filename"
#define pt_auto281   "Source Filename"
#define xx_auto281   "Source Filename"
#define en_auto282   "Translator"
#define fr_auto282   "Traducteur"
#define it_auto282   "Translator"
#define es_auto282   "Translator"
#define de_auto282   "Translator"
#define nl_auto282   "Translator"
#define pt_auto282   "Translator"
#define xx_auto282   "Translator"
#define en_FileName   ""
#define en_Translator   ""
#define en_Debug   "&Debug"
#define fr_Debug   "&Debug"
#define en_Trace   "&Trace"
#define fr_Trace   "&Trace"
#define it_Trace   "&Trace"
#define es_Trace   "&Trace"
#define de_Trace   "&Trace"
#define nl_Trace   "&Trace"
#define pt_Trace   "&Trace"
#define xx_Trace   "&Trace"
#define en_Verbose   "&Verbose"
#define fr_Verbose   "&Bavard"
#define it_Verbose   "&Verbose"
#define es_Verbose   "&Verbose"
#define de_Verbose   "&Verbose"
#define nl_Verbose   "&Verbose"
#define pt_Verbose   "&Verbose"
#define xx_Verbose   "&Verbose"
#define en_ListFile   "&List File"
#define fr_ListFile   "&Fichier Liste"
#define it_ListFile   "&List File"
#define es_ListFile   "&List File"
#define de_ListFile   "&List File"
#define nl_ListFile   "&List File"
#define pt_ListFile   "&List File"
#define xx_ListFile   "&List File"
#define en_Optimise   "&Optimisation"
#define fr_Optimise   "&Optimisation"
#define it_Optimise   "&Optimisation"
#define es_Optimise   "&Optimisation"
#define de_Optimise   "&Optimisation"
#define nl_Optimise   "&Optimisation"
#define pt_Optimise   "&Optimisation"
#define xx_Optimise   "&Optimisation"
#define en_Compact   "&Compact"
#define fr_Compact   "&Compactage"
#define it_Compact   "&Compact"
#define es_Compact   "&Compact"
#define de_Compact   "&Compact"
#define nl_Compact   "&Compact"
#define pt_Compact   "&Compact"
#define xx_Compact   "&Compact"
#define en_Auto3598   "ok.gif"
#define fr_Auto3598   "ok.gif"
#define it_Auto3598   "ok.gif"
#define es_Auto3598   "ok.gif"
#define de_Auto3598   "ok.gif"
#define nl_Auto3598   "ok.gif"
#define pt_Auto3598   "ok.gif"
#define xx_Auto3598   "ok.gif"
#define en_Auto3599   "cancel.gif"
#define fr_Auto3599   "cancel.gif"
#define it_Auto3599   "cancel.gif"
#define es_Auto3599   "cancel.gif"
#define de_Auto3599   "cancel.gif"
#define nl_Auto3599   "cancel.gif"
#define pt_Auto3599   "cancel.gif"
#define xx_Auto3599   "cancel.gif"
#define en_auto351   "Include Paths"
#define fr_auto351   "Chemins d'inclusion"
#define it_auto351   "Include Paths"
#define es_auto351   "Include Paths"
#define de_auto351   "Include Paths"
#define nl_auto351   "Include Paths"
#define pt_auto351   "Include Paths"
#define xx_auto351   "Include Paths"
#define en_Inclusion   ""
#define en_Edit   "&Edit"
#define fr_Edit   "&Editer"
#define it_Edit   "&Edit"
#define es_Edit   "&Edit"
#define de_Edit   "&Edit"
#define nl_Edit   "&Edit"
#define pt_Edit   "&Edit"
#define xx_Edit   "&Edit"
#define en_Select   "&Select"
#define fr_Select   "&Choisir"
#define it_Select   "&Select"
#define es_Select   "&Select"
#define de_Select   "&Select"
#define nl_Select   "&Select"
#define pt_Select   "&Select"
#define xx_Select   "&Select"

private struct accept_traduction_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3594[8];
	char * hint_Auto3594[8];
	int	x_Auto3594;
	int	y_Auto3594;
	int	w_Auto3594;
	int	h_Auto3594;
	char * hint_Auto3595[8];
	char * msg_Auto3596[8];
	char * hint_Auto3596[8];
	char * msg_auto726[8];
	char * hint_auto726[8];
	char * msg_Auto3597[8];
	char * hint_Auto3597[8];
	char * msg_auto281[8];
	char * hint_auto281[8];
	char * msg_auto282[8];
	char * hint_auto282[8];
	char * hint_FileName[8];
	char	buffer_FileName[256];
	char * hint_Translator[8];
	char	buffer_Translator[256];
	char * msg_Debug[8];
	int	trigger_Debug;
	char * hint_Debug[8];
	int	value_Debug;
	char * msg_Trace[8];
	int	trigger_Trace;
	char * hint_Trace[8];
	int	value_Trace;
	char * msg_Verbose[8];
	int	trigger_Verbose;
	char * hint_Verbose[8];
	int	value_Verbose;
	char * msg_ListFile[8];
	int	trigger_ListFile;
	char * hint_ListFile[8];
	int	value_ListFile;
	char * msg_Optimise[8];
	int	trigger_Optimise;
	char * hint_Optimise[8];
	int	value_Optimise;
	char * msg_Compact[8];
	int	trigger_Compact;
	char * hint_Compact[8];
	int	value_Compact;
	char * msg_Auto3598[8];
	int	trigger_Auto3598;
	char * hint_Auto3598[8];
	char * msg_Auto3599[8];
	int	trigger_Auto3599;
	char * hint_Auto3599[8];
	char * msg_auto351[8];
	char * hint_auto351[8];
	char * hint_Inclusion[8];
	char	buffer_Inclusion[256];
	char * msg_Edit[8];
	int	trigger_Edit;
	char * hint_Edit[8];
	char * msg_Select[8];
	int	trigger_Select;
	char * hint_Select[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[10];
	};
static int	vfh[16];
private int on_Auto3598_event(struct accept_traduction_context * _Context);
private int on_Auto3599_event(struct accept_traduction_context * _Context);
private int on_Edit_event(struct accept_traduction_context * _Context);
private int on_Select_event(struct accept_traduction_context * _Context);

public	int	accept_traduction_create(
	struct accept_traduction_context ** cptr,
	char * pFileName,
	char * pTranslator,
	char * pDebug,
	char * pTrace,
	char * pVerbose,
	char * pListFile,
	char * pOptimise,
	char * pCompact,
	char * pInclusion)
{

	int i;
	struct accept_traduction_context * _Context=(struct accept_traduction_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_traduction_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=14;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWWWWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 255, pFileName);
		visual_transferin(_Context->buffer_Translator, 255, pTranslator);
		visual_transferin((void *) 0, 0, pDebug);
		if (!( pDebug )) _Context->value_Debug=0;
		else	_Context->value_Debug = *((int *)pDebug);
		visual_transferin((void *) 0, 0, pTrace);
		if (!( pTrace )) _Context->value_Trace=0;
		else	_Context->value_Trace = *((int *)pTrace);
		visual_transferin((void *) 0, 0, pVerbose);
		if (!( pVerbose )) _Context->value_Verbose=0;
		else	_Context->value_Verbose = *((int *)pVerbose);
		visual_transferin((void *) 0, 0, pListFile);
		if (!( pListFile )) _Context->value_ListFile=0;
		else	_Context->value_ListFile = *((int *)pListFile);
		visual_transferin((void *) 0, 0, pOptimise);
		if (!( pOptimise )) _Context->value_Optimise=0;
		else	_Context->value_Optimise = *((int *)pOptimise);
		visual_transferin((void *) 0, 0, pCompact);
		if (!( pCompact )) _Context->value_Compact=0;
		else	_Context->value_Compact = *((int *)pCompact);
		visual_transferin(_Context->buffer_Inclusion, 255, pInclusion);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3594[i]=" ";
	_Context->hint_Auto3594[0]=en__Auto3594;
	_Context->hint_Auto3594[1]=fr__Auto3594;
	_Context->hint_Auto3594[2]=it__Auto3594;
	_Context->hint_Auto3594[3]=es__Auto3594;
	_Context->hint_Auto3594[4]=de__Auto3594;
	_Context->hint_Auto3594[5]=nl__Auto3594;
	_Context->hint_Auto3594[6]=pt__Auto3594;
	_Context->hint_Auto3594[7]=xx__Auto3594;
	_Context->x_Auto3594=170;
	_Context->y_Auto3594=105;
	_Context->w_Auto3594=460;
	_Context->h_Auto3594=390;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3596[i]=" ";
	_Context->msg_Auto3596[0]=en_Auto3596;
	_Context->msg_Auto3596[1]=fr_Auto3596;
	_Context->msg_Auto3596[2]=it_Auto3596;
	_Context->msg_Auto3596[3]=es_Auto3596;
	_Context->msg_Auto3596[4]=de_Auto3596;
	_Context->msg_Auto3596[5]=nl_Auto3596;
	_Context->msg_Auto3596[6]=pt_Auto3596;
	_Context->msg_Auto3596[7]=xx_Auto3596;
	for (i=0; i < 8; i++)_Context->msg_auto726[i]=" ";
	_Context->msg_auto726[0]=en_auto726;
	_Context->msg_auto726[1]=fr_auto726;
	_Context->msg_auto726[2]=it_auto726;
	_Context->msg_auto726[3]=es_auto726;
	_Context->msg_auto726[4]=de_auto726;
	_Context->msg_auto726[5]=nl_auto726;
	_Context->msg_auto726[6]=pt_auto726;
	_Context->msg_auto726[7]=xx_auto726;
	for (i=0; i < 8; i++)_Context->msg_Auto3597[i]=" ";
	_Context->msg_Auto3597[0]=en_Auto3597;
	_Context->msg_Auto3597[1]=fr_Auto3597;
	_Context->msg_Auto3597[2]=it_Auto3597;
	_Context->msg_Auto3597[3]=es_Auto3597;
	_Context->msg_Auto3597[4]=de_Auto3597;
	_Context->msg_Auto3597[5]=nl_Auto3597;
	_Context->msg_Auto3597[6]=pt_Auto3597;
	_Context->msg_Auto3597[7]=xx_Auto3597;
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
	for (i=0; i < 8; i++)_Context->msg_ListFile[i]=" ";
	_Context->msg_ListFile[0]=en_ListFile;
	_Context->msg_ListFile[1]=fr_ListFile;
	_Context->msg_ListFile[2]=it_ListFile;
	_Context->msg_ListFile[3]=es_ListFile;
	_Context->msg_ListFile[4]=de_ListFile;
	_Context->msg_ListFile[5]=nl_ListFile;
	_Context->msg_ListFile[6]=pt_ListFile;
	_Context->msg_ListFile[7]=xx_ListFile;
	for (i=0; i < 8; i++)_Context->msg_Optimise[i]=" ";
	_Context->msg_Optimise[0]=en_Optimise;
	_Context->msg_Optimise[1]=fr_Optimise;
	_Context->msg_Optimise[2]=it_Optimise;
	_Context->msg_Optimise[3]=es_Optimise;
	_Context->msg_Optimise[4]=de_Optimise;
	_Context->msg_Optimise[5]=nl_Optimise;
	_Context->msg_Optimise[6]=pt_Optimise;
	_Context->msg_Optimise[7]=xx_Optimise;
	for (i=0; i < 8; i++)_Context->msg_Compact[i]=" ";
	_Context->msg_Compact[0]=en_Compact;
	_Context->msg_Compact[1]=fr_Compact;
	_Context->msg_Compact[2]=it_Compact;
	_Context->msg_Compact[3]=es_Compact;
	_Context->msg_Compact[4]=de_Compact;
	_Context->msg_Compact[5]=nl_Compact;
	_Context->msg_Compact[6]=pt_Compact;
	_Context->msg_Compact[7]=xx_Compact;
	for (i=0; i < 8; i++)_Context->msg_Auto3598[i]=" ";
	_Context->msg_Auto3598[0]=en_Auto3598;
	_Context->msg_Auto3598[1]=fr_Auto3598;
	_Context->msg_Auto3598[2]=it_Auto3598;
	_Context->msg_Auto3598[3]=es_Auto3598;
	_Context->msg_Auto3598[4]=de_Auto3598;
	_Context->msg_Auto3598[5]=nl_Auto3598;
	_Context->msg_Auto3598[6]=pt_Auto3598;
	_Context->msg_Auto3598[7]=xx_Auto3598;
	for (i=0; i < 8; i++)_Context->msg_Auto3599[i]=" ";
	_Context->msg_Auto3599[0]=en_Auto3599;
	_Context->msg_Auto3599[1]=fr_Auto3599;
	_Context->msg_Auto3599[2]=it_Auto3599;
	_Context->msg_Auto3599[3]=es_Auto3599;
	_Context->msg_Auto3599[4]=de_Auto3599;
	_Context->msg_Auto3599[5]=nl_Auto3599;
	_Context->msg_Auto3599[6]=pt_Auto3599;
	_Context->msg_Auto3599[7]=xx_Auto3599;
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
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3594,_Context->y_Auto3594,460+10,390+10);
	return(0);
}

public 	int	accept_traduction_hide(struct accept_traduction_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3594,_Context->y_Auto3594);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_traduction_remove(
	struct accept_traduction_context * _Context,
	char * pFileName,
	char * pTranslator,
	char * pDebug,
	char * pTrace,
	char * pVerbose,
	char * pListFile,
	char * pOptimise,
	char * pCompact,
	char * pInclusion)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWWWWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 255, pFileName);
		visual_transferout(_Context->buffer_Translator, 255, pTranslator);
		visual_transferout((void *) 0, 0, pDebug);
		if ( pDebug != (char *) 0)
			*((int*)pDebug) = _Context->value_Debug;
		visual_transferout((void *) 0, 0, pTrace);
		if ( pTrace != (char *) 0)
			*((int*)pTrace) = _Context->value_Trace;
		visual_transferout((void *) 0, 0, pVerbose);
		if ( pVerbose != (char *) 0)
			*((int*)pVerbose) = _Context->value_Verbose;
		visual_transferout((void *) 0, 0, pListFile);
		if ( pListFile != (char *) 0)
			*((int*)pListFile) = _Context->value_ListFile;
		visual_transferout((void *) 0, 0, pOptimise);
		if ( pOptimise != (char *) 0)
			*((int*)pOptimise) = _Context->value_Optimise;
		visual_transferout((void *) 0, 0, pCompact);
		if ( pCompact != (char *) 0)
			*((int*)pCompact) = _Context->value_Compact;
		visual_transferout(_Context->buffer_Inclusion, 255, pInclusion);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_traduction_show(struct accept_traduction_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3594,_Context->y_Auto3594);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3594,_Context->y_Auto3594,460,390,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3594,_Context->y_Auto3594,460,390,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_frame(_Context->x_Auto3594+21,_Context->y_Auto3594+168,420,60,2);
	visual_image(_Context->x_Auto3594+350,_Context->y_Auto3594+30,30,20,_Context->msg_Auto3596[_Context->language],3);
	visual_image(_Context->x_Auto3594+390,_Context->y_Auto3594+30,51,50,_Context->msg_auto726[_Context->language],0);
	visual_text(_Context->x_Auto3594+20,_Context->y_Auto3594+30,392,32,vfh[3],34,0,_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]),770);
	visual_text(_Context->x_Auto3594+20,_Context->y_Auto3594+70,414,16,vfh[2],34,0,_Context->msg_auto281[_Context->language],strlen(_Context->msg_auto281[_Context->language]),256);
	visual_text(_Context->x_Auto3594+20,_Context->y_Auto3594+120,415,16,vfh[2],34,0,_Context->msg_auto282[_Context->language],strlen(_Context->msg_auto282[_Context->language]),256);
	visual_frame(_Context->x_Auto3594+20,_Context->y_Auto3594+90,416+2,16+2,5);
	visual_text(_Context->x_Auto3594+20+1,_Context->y_Auto3594+90+1,416,16,vfh[1],16,28,_Context->buffer_FileName,255,0);
	visual_frame(_Context->x_Auto3594+20,_Context->y_Auto3594+140,416+2,16+2,5);
	visual_text(_Context->x_Auto3594+20+1,_Context->y_Auto3594+140+1,416,16,vfh[1],16,28,_Context->buffer_Translator,255,0);
	_Context->trigger_Debug=visual_trigger_code(_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]));
	visual_check(_Context->x_Auto3594+30,_Context->y_Auto3594+180,84,16,vfh[2],34,0,_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]),_Context->value_Debug|0);
	_Context->trigger_Trace=visual_trigger_code(_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]));
	visual_check(_Context->x_Auto3594+30,_Context->y_Auto3594+200,84,16,vfh[2],34,0,_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]),_Context->value_Trace|0);
	_Context->trigger_Verbose=visual_trigger_code(_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]));
	visual_check(_Context->x_Auto3594+160,_Context->y_Auto3594+180,98,16,vfh[2],27,0,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),_Context->value_Verbose|0);
	_Context->trigger_ListFile=visual_trigger_code(_Context->msg_ListFile[_Context->language],strlen(_Context->msg_ListFile[_Context->language]));
	visual_check(_Context->x_Auto3594+160,_Context->y_Auto3594+200,98,16,vfh[2],27,0,_Context->msg_ListFile[_Context->language],strlen(_Context->msg_ListFile[_Context->language]),_Context->value_ListFile|0);
	_Context->trigger_Optimise=visual_trigger_code(_Context->msg_Optimise[_Context->language],strlen(_Context->msg_Optimise[_Context->language]));
	visual_check(_Context->x_Auto3594+290,_Context->y_Auto3594+180,126,16,vfh[2],34,0,_Context->msg_Optimise[_Context->language],strlen(_Context->msg_Optimise[_Context->language]),_Context->value_Optimise|0);
	_Context->trigger_Compact=visual_trigger_code(_Context->msg_Compact[_Context->language],strlen(_Context->msg_Compact[_Context->language]));
	visual_check(_Context->x_Auto3594+290,_Context->y_Auto3594+200,126,16,vfh[2],34,0,_Context->msg_Compact[_Context->language],strlen(_Context->msg_Compact[_Context->language]),_Context->value_Compact|0);
	_Context->trigger_Auto3598=visual_trigger_code(_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]));
	visual_button(_Context->x_Auto3594+20,_Context->y_Auto3594+330,56,48,vfh[2],34,0,_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]),1040);
	_Context->trigger_Auto3599=visual_trigger_code(_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]));
	visual_button(_Context->x_Auto3594+380,_Context->y_Auto3594+330,56,48,vfh[2],34,0,_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]),1040);
	visual_text(_Context->x_Auto3594+20,_Context->y_Auto3594+240,419,20,vfh[2],34,0,_Context->msg_auto351[_Context->language],strlen(_Context->msg_auto351[_Context->language]),256);
	visual_frame(_Context->x_Auto3594+20,_Context->y_Auto3594+260,416+2,64+2,5);
	visual_text(_Context->x_Auto3594+20+1,_Context->y_Auto3594+260+1,416,64,vfh[1],16,28,_Context->buffer_Inclusion,255,0);
	_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(_Context->x_Auto3594+120,_Context->y_Auto3594+340,98,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_Auto3594+240,_Context->y_Auto3594+340,98,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	visual_thaw(_Context->x_Auto3594,_Context->y_Auto3594,460,390);

	return(0);
}

private int FileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The SOURCE edit field presents the full path and filename of the  ";
			mptr[1]="  source file to be translated.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Translator_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The TRANSLATOR edit field presents the full path and file name of ";
			mptr[1]="t he ABAL Translator to be used to translate the source.  ";
			return(visual_online_help(mptr,2));
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
			mptr[0] = "The DEBUG check box, when checked, activates translation with gener ";
			mptr[1]="ation of a list for an eventual debug operation.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Trace_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The TRACE checkbox activates the collection of errors encountered ";
			mptr[1]="   during translation for use by the standard ABAL trace mechanism. ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
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
			char * mptr[3];
			mptr[0] = "When the VERBOSE checkbox is checked the translation operation will ";
			mptr[1]="   display textual information abouts its progression to the releve ";
			mptr[2]="nt    text screen output device or window.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ListFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When the VERBOSE checkbox is checked the translation operation will ";
			mptr[1]="   display textual information abouts its progression to the releve ";
			mptr[2]="nt    text screen output device or window.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Optimise_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The OPTIMISATION check box activates the translator optimisation  ";
			mptr[1]="  mechanisms.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Compact_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The OPTIMISATION check box activates the translator optimisation  ";
			mptr[1]="  mechanisms.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3598_help()
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

private int Auto3599_help()
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

private int Inclusion_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "The INCLUDE PATHS edit field presents the various include paths to ";
			mptr[1]="   be used for the resolution of the various include files required ";
			mptr[2]="      for the translation of the source. The command line switch of ";
			mptr[3]=" -I or   /I is not to be included as it will be added by the transl ";
			mptr[4]="ation       mechanism prior to the activation of the translator.  ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Edit_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressingthe EDIT button the SOURCE file name will be made    available ";
			mptr[1]="for inspection by the Standard Text Editor Mechanisms  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Select_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The Select button allows access  to the file selection dialog frame ";
			mptr[1]="allowing prompted selection of the filename.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3594action(struct accept_traduction_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_traduction_hide(_Context);

		_Context->x_Auto3594 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3594 < 0) { _Context->x_Auto3594=0; }
		_Context->y_Auto3594 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3594 < 0) { _Context->y_Auto3594=0; }
			accept_traduction_show(_Context);

		visual_thaw(_Context->x_Auto3594,_Context->y_Auto3594,460,390);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3598_event(struct accept_traduction_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3599_event(struct accept_traduction_context * _Context) {
	return(27);
	return(-1);
}
private int on_Edit_event(struct accept_traduction_context * _Context) {
		accept_traduction_hide(_Context);
;
	use_editor(_Context->buffer_FileName,0);
		accept_traduction_show(_Context);
;
	return(-1);
}
private int on_Select_event(struct accept_traduction_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_AS);
		accept_traduction_show(_Context);
;
	return(-1);
}


public	int	accept_traduction_event(
struct accept_traduction_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Debug == mb ) return(4);
		if (_Context->trigger_Trace == mb ) return(5);
		if (_Context->trigger_Verbose == mb ) return(6);
		if (_Context->trigger_ListFile == mb ) return(7);
		if (_Context->trigger_Optimise == mb ) return(8);
		if (_Context->trigger_Compact == mb ) return(9);
		if (_Context->trigger_Auto3598 == mb ) return(10);
		if (_Context->trigger_Auto3599 == mb ) return(11);
		if (_Context->trigger_Edit == mb ) return(13);
		if (_Context->trigger_Select == mb ) return(14);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3594+439) )  
	&&  (my >= (_Context->y_Auto3594+4) )  
	&&  (mx <= (_Context->x_Auto3594+456) )  
	&&  (my <= (_Context->y_Auto3594+20) )) {
		return(1);	/* Auto3594 */

		}
	if ((mx >= (_Context->x_Auto3594+423) )  
	&&  (my >= (_Context->y_Auto3594+4) )  
	&&  (mx <= (_Context->x_Auto3594+440) )  
	&&  (my <= (_Context->y_Auto3594+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vtrad.htm");
			};
		return(-1);	/* Auto3594 */

		}
	if ((mx >= (_Context->x_Auto3594+407) )  
	&&  (my >= (_Context->y_Auto3594+4) )  
	&&  (mx <= (_Context->x_Auto3594+424) )  
	&&  (my <= (_Context->y_Auto3594+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_traduction_show(_Context);
		return(-1);	/* Auto3594 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3594+4) )  
		&&  (my >= (_Context->y_Auto3594+4) )  
		&&  (mx <= (_Context->x_Auto3594+392) )  
		&&  (my <= (_Context->y_Auto3594+20) )) {
			return( Auto3594action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3594+20) ) 
	&&  ( my >= (_Context->y_Auto3594+90) ) 
	&&  ( mx <= (_Context->x_Auto3594+20+416) ) 
	&&  ( my <= (_Context->y_Auto3594+90+16))) {
		return(2); /* FileName */
		}
	if (( mx >= (_Context->x_Auto3594+20) ) 
	&&  ( my >= (_Context->y_Auto3594+140) ) 
	&&  ( mx <= (_Context->x_Auto3594+20+416) ) 
	&&  ( my <= (_Context->y_Auto3594+140+16))) {
		return(3); /* Translator */
		}
	if (( mx >= (_Context->x_Auto3594+30) ) 
	&&  ( my >= (_Context->y_Auto3594+180) ) 
	&&  ( mx <= (_Context->x_Auto3594+30+84) ) 
	&&  ( my <= (_Context->y_Auto3594+180+16))) {
		return(4); /* Debug */
		}
	if (( mx >= (_Context->x_Auto3594+30) ) 
	&&  ( my >= (_Context->y_Auto3594+200) ) 
	&&  ( mx <= (_Context->x_Auto3594+30+84) ) 
	&&  ( my <= (_Context->y_Auto3594+200+16))) {
		return(5); /* Trace */
		}
	if (( mx >= (_Context->x_Auto3594+160) ) 
	&&  ( my >= (_Context->y_Auto3594+180) ) 
	&&  ( mx <= (_Context->x_Auto3594+160+98) ) 
	&&  ( my <= (_Context->y_Auto3594+180+16))) {
		return(6); /* Verbose */
		}
	if (( mx >= (_Context->x_Auto3594+160) ) 
	&&  ( my >= (_Context->y_Auto3594+200) ) 
	&&  ( mx <= (_Context->x_Auto3594+160+98) ) 
	&&  ( my <= (_Context->y_Auto3594+200+16))) {
		return(7); /* ListFile */
		}
	if (( mx >= (_Context->x_Auto3594+290) ) 
	&&  ( my >= (_Context->y_Auto3594+180) ) 
	&&  ( mx <= (_Context->x_Auto3594+290+126) ) 
	&&  ( my <= (_Context->y_Auto3594+180+16))) {
		return(8); /* Optimise */
		}
	if (( mx >= (_Context->x_Auto3594+290) ) 
	&&  ( my >= (_Context->y_Auto3594+200) ) 
	&&  ( mx <= (_Context->x_Auto3594+290+126) ) 
	&&  ( my <= (_Context->y_Auto3594+200+16))) {
		return(9); /* Compact */
		}
	if (( mx >= (_Context->x_Auto3594+20) ) 
	&&  ( my >= (_Context->y_Auto3594+330) ) 
	&&  ( mx <= (_Context->x_Auto3594+20+56) ) 
	&&  ( my <= (_Context->y_Auto3594+330+48))) {
		return(10); /* Auto3598 */
		}
	if (( mx >= (_Context->x_Auto3594+380) ) 
	&&  ( my >= (_Context->y_Auto3594+330) ) 
	&&  ( mx <= (_Context->x_Auto3594+380+56) ) 
	&&  ( my <= (_Context->y_Auto3594+330+48))) {
		return(11); /* Auto3599 */
		}
	if (( mx >= (_Context->x_Auto3594+20) ) 
	&&  ( my >= (_Context->y_Auto3594+260) ) 
	&&  ( mx <= (_Context->x_Auto3594+20+416) ) 
	&&  ( my <= (_Context->y_Auto3594+260+64))) {
		return(12); /* Inclusion */
		}
	if (( mx >= (_Context->x_Auto3594+120) ) 
	&&  ( my >= (_Context->y_Auto3594+340) ) 
	&&  ( mx <= (_Context->x_Auto3594+120+98) ) 
	&&  ( my <= (_Context->y_Auto3594+340+32))) {
		return(13); /* Edit */
		}
	if (( mx >= (_Context->x_Auto3594+240) ) 
	&&  ( my >= (_Context->y_Auto3594+340) ) 
	&&  ( mx <= (_Context->x_Auto3594+240+98) ) 
	&&  ( my <= (_Context->y_Auto3594+340+32))) {
		return(14); /* Select */
		}

	return(-1);
}


public	int	accept_traduction_focus(struct accept_traduction_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_Auto3594+20+1,_Context->y_Auto3594+90+1,416,16,vfh[1],_Context->buffer_FileName,255);
			break;
			case	0x3 :
				/* Translator */
				_Context->keycode = visual_edit(_Context->x_Auto3594+20+1,_Context->y_Auto3594+140+1,416,16,vfh[1],_Context->buffer_Translator,255);
			break;
			case	0x4 :
				/* Debug */
				visual_check(_Context->x_Auto3594+30,_Context->y_Auto3594+180,84,16,vfh[2],34,0,_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]),(_Context->value_Debug |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Debug=visual_trigger_code(_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]));
	visual_check(_Context->x_Auto3594+30,_Context->y_Auto3594+180,84,16,vfh[2],34,0,_Context->msg_Debug[_Context->language],strlen(_Context->msg_Debug[_Context->language]),_Context->value_Debug|0);
				break;
			case	0x5 :
				/* Trace */
				visual_check(_Context->x_Auto3594+30,_Context->y_Auto3594+200,84,16,vfh[2],34,0,_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]),(_Context->value_Trace |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Trace=visual_trigger_code(_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]));
	visual_check(_Context->x_Auto3594+30,_Context->y_Auto3594+200,84,16,vfh[2],34,0,_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]),_Context->value_Trace|0);
				break;
			case	0x6 :
				/* Verbose */
				visual_check(_Context->x_Auto3594+160,_Context->y_Auto3594+180,98,16,vfh[2],27,0,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),(_Context->value_Verbose |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Verbose=visual_trigger_code(_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]));
	visual_check(_Context->x_Auto3594+160,_Context->y_Auto3594+180,98,16,vfh[2],27,0,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),_Context->value_Verbose|0);
				break;
			case	0x7 :
				/* ListFile */
				visual_check(_Context->x_Auto3594+160,_Context->y_Auto3594+200,98,16,vfh[2],27,0,_Context->msg_ListFile[_Context->language],strlen(_Context->msg_ListFile[_Context->language]),(_Context->value_ListFile |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ListFile=visual_trigger_code(_Context->msg_ListFile[_Context->language],strlen(_Context->msg_ListFile[_Context->language]));
	visual_check(_Context->x_Auto3594+160,_Context->y_Auto3594+200,98,16,vfh[2],27,0,_Context->msg_ListFile[_Context->language],strlen(_Context->msg_ListFile[_Context->language]),_Context->value_ListFile|0);
				break;
			case	0x8 :
				/* Optimise */
				visual_check(_Context->x_Auto3594+290,_Context->y_Auto3594+180,126,16,vfh[2],34,0,_Context->msg_Optimise[_Context->language],strlen(_Context->msg_Optimise[_Context->language]),(_Context->value_Optimise |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Optimise=visual_trigger_code(_Context->msg_Optimise[_Context->language],strlen(_Context->msg_Optimise[_Context->language]));
	visual_check(_Context->x_Auto3594+290,_Context->y_Auto3594+180,126,16,vfh[2],34,0,_Context->msg_Optimise[_Context->language],strlen(_Context->msg_Optimise[_Context->language]),_Context->value_Optimise|0);
				break;
			case	0x9 :
				/* Compact */
				visual_check(_Context->x_Auto3594+290,_Context->y_Auto3594+200,126,16,vfh[2],34,0,_Context->msg_Compact[_Context->language],strlen(_Context->msg_Compact[_Context->language]),(_Context->value_Compact |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Compact=visual_trigger_code(_Context->msg_Compact[_Context->language],strlen(_Context->msg_Compact[_Context->language]));
	visual_check(_Context->x_Auto3594+290,_Context->y_Auto3594+200,126,16,vfh[2],34,0,_Context->msg_Compact[_Context->language],strlen(_Context->msg_Compact[_Context->language]),_Context->value_Compact|0);
				break;
			case	0xa :
				/* Auto3598 */
				_Context->trigger_Auto3598=visual_trigger_code(_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]));
				visual_button(_Context->x_Auto3594+20,_Context->y_Auto3594+330,56,48,vfh[2],34,0,_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3598=visual_trigger_code(_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]));
	visual_button(_Context->x_Auto3594+20,_Context->y_Auto3594+330,56,48,vfh[2],34,0,_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]),1040);
				break;
			case	0xb :
				/* Auto3599 */
				_Context->trigger_Auto3599=visual_trigger_code(_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]));
				visual_button(_Context->x_Auto3594+380,_Context->y_Auto3594+330,56,48,vfh[2],34,0,_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3599=visual_trigger_code(_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]));
	visual_button(_Context->x_Auto3594+380,_Context->y_Auto3594+330,56,48,vfh[2],34,0,_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]),1040);
				break;
			case	0xc :
				/* Inclusion */
				_Context->keycode = visual_edit(_Context->x_Auto3594+20+1,_Context->y_Auto3594+260+1,416,64,vfh[1],_Context->buffer_Inclusion,255);
			break;
			case	0xd :
				/* Edit */
				_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
				visual_button(_Context->x_Auto3594+120,_Context->y_Auto3594+340,98,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(_Context->x_Auto3594+120,_Context->y_Auto3594+340,98,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
				break;
			case	0xe :
				/* Select */
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
				visual_button(_Context->x_Auto3594+240,_Context->y_Auto3594+340,98,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_Auto3594+240,_Context->y_Auto3594+340,98,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_traduction_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=14;
			accept_traduction_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_traduction_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (FileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Translator_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Debug_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Trace_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Verbose_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (ListFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (Optimise_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (Compact_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Auto3598_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Auto3599_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Inclusion_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (Edit_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (Select_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3594 */
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
					/* ListFile */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ListFile += 1;
						_Context->value_ListFile &= 1;
						}
					continue;
				case	0x8 :
					/* Optimise */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Optimise += 1;
						_Context->value_Optimise &= 1;
						}
					continue;
				case	0x9 :
					/* Compact */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Compact += 1;
						_Context->value_Compact &= 1;
						}
					continue;
				case	0xa :
					/* Auto3598 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3598=visual_trigger_code(_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]));
						visual_button(_Context->x_Auto3594+20,_Context->y_Auto3594+330,56,48,vfh[2],34,0,_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3598=visual_trigger_code(_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]));
	visual_button(_Context->x_Auto3594+20,_Context->y_Auto3594+330,56,48,vfh[2],34,0,_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3598_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Auto3599 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3599=visual_trigger_code(_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]));
						visual_button(_Context->x_Auto3594+380,_Context->y_Auto3594+330,56,48,vfh[2],34,0,_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3599=visual_trigger_code(_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]));
	visual_button(_Context->x_Auto3594+380,_Context->y_Auto3594+330,56,48,vfh[2],34,0,_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3599_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* Inclusion */
					continue;
				case	0xd :
					/* Edit */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
						visual_button(_Context->x_Auto3594+120,_Context->y_Auto3594+340,98,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(_Context->x_Auto3594+120,_Context->y_Auto3594+340,98,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Edit_event(_Context)) != -1) break;

						}
					continue;
				case	0xe :
					/* Select */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
						visual_button(_Context->x_Auto3594+240,_Context->y_Auto3594+340,98,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_Auto3594+240,_Context->y_Auto3594+340,98,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

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
				_Context->focus_item=14;
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
	char * pListFile,
	char * pOptimise,
	char * pCompact,
	char * pInclusion)
{
	int	status=0;
	struct accept_traduction_context * _Context=(struct accept_traduction_context*) 0;
	status = accept_traduction_create(
	&_Context,
	 pFileName,
	 pTranslator,
	 pDebug,
	 pTrace,
	 pVerbose,
	 pListFile,
	 pOptimise,
	 pCompact,
	 pInclusion);
	if ( status != 0) return(status);
	status = accept_traduction_show(_Context);
		enter_modal();
	status = accept_traduction_focus(_Context);
		leave_modal();
	status = accept_traduction_hide(_Context);
	status = accept_traduction_remove(
	_Context,
	 pFileName,
	 pTranslator,
	 pDebug,
	 pTrace,
	 pVerbose,
	 pListFile,
	 pOptimise,
	 pCompact,
	 pInclusion);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vtrad_c */
