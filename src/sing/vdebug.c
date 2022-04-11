
#ifndef _vdebug_c
#define _vdebug_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vdebug.xml                                               */
/* Target         : vdebug.c                                                 */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3547   ""
#define fr__Auto3547   ""
#define it__Auto3547   ""
#define es__Auto3547   ""
#define de__Auto3547   ""
#define nl__Auto3547   ""
#define pt__Auto3547   ""
#define xx__Auto3547   ""
#define en_Auto3549   "ABAL++ Runtime Options"
#define fr_Auto3549   "Options d'ex‚cution Abal++"
#define it_Auto3549   "ABAL++ Runtime Options"
#define es_Auto3549   "ABAL++ Runtime Options"
#define de_Auto3549   "ABAL++ Runtime Options"
#define nl_Auto3549   "ABAL++ Runtime Options"
#define pt_Auto3549   "ABAL++ Runtime Options"
#define xx_Auto3549   "ABAL++ Runtime Options"
#define en__Auto3549   ""
#define fr__Auto3549   ""
#define it__Auto3549   ""
#define es__Auto3549   ""
#define de__Auto3549   ""
#define nl__Auto3549   ""
#define pt__Auto3549   ""
#define xx__Auto3549   ""
#define en_Auto3550   "Abal++ Debug Utility"
#define fr_Auto3550   "Debuggeur ABAL++"
#define it_Auto3550   "Abal++ Debug Utility"
#define es_Auto3550   "Abal++ Debug Utility"
#define de_Auto3550   "Abal++ Debug Utility"
#define nl_Auto3550   "Abal++ Debug Utility"
#define pt_Auto3550   "Abal++ Debug Utility"
#define xx_Auto3550   "Abal++ Debug Utility"
#define en__Auto3550   ""
#define fr__Auto3550   ""
#define it__Auto3550   ""
#define es__Auto3550   ""
#define de__Auto3550   ""
#define nl__Auto3550   ""
#define pt__Auto3550   ""
#define xx__Auto3550   ""
#define en_Auto3551   "Abal++ Runtime"
#define fr_Auto3551   "Runtime ABAL++"
#define it_Auto3551   "Abal++ Runtime"
#define es_Auto3551   "Abal++ Runtime"
#define de_Auto3551   "Abal++ Runtime"
#define nl_Auto3551   "Abal++ Runtime"
#define pt_Auto3551   "Abal++ Runtime"
#define xx_Auto3551   "Abal++ Runtime"
#define en__Auto3551   ""
#define fr__Auto3551   ""
#define it__Auto3551   ""
#define es__Auto3551   ""
#define de__Auto3551   ""
#define nl__Auto3551   ""
#define pt__Auto3551   ""
#define xx__Auto3551   ""
#define en_Auto3552   "exaicon.gif"
#define fr_Auto3552   "exaicon.gif"
#define it_Auto3552   "exaicon.gif"
#define es_Auto3552   "exaicon.gif"
#define de_Auto3552   "exaicon.gif"
#define nl_Auto3552   "exaicon.gif"
#define pt_Auto3552   "exaicon.gif"
#define xx_Auto3552   "exaicon.gif"
#define en_Auto3553   "abal.gif"
#define fr_Auto3553   "abal.gif"
#define it_Auto3553   "abal.gif"
#define es_Auto3553   "abal.gif"
#define de_Auto3553   "abal.gif"
#define nl_Auto3553   "abal.gif"
#define pt_Auto3553   "abal.gif"
#define xx_Auto3553   "abal.gif"
#define en_Auto3554   "Abal++ Program Name"
#define fr_Auto3554   "Nom du programme Abal++"
#define it_Auto3554   "Abal++ Program Name"
#define es_Auto3554   "Abal++ Program Name"
#define de_Auto3554   "Abal++ Program Name"
#define nl_Auto3554   "Abal++ Program Name"
#define pt_Auto3554   "Abal++ Program Name"
#define xx_Auto3554   "Abal++ Program Name"
#define en__Auto3554   ""
#define fr__Auto3554   ""
#define it__Auto3554   ""
#define es__Auto3554   ""
#define de__Auto3554   ""
#define nl__Auto3554   ""
#define pt__Auto3554   ""
#define xx__Auto3554   ""
#define en_Auto3555   "Command Line Parameters"
#define fr_Auto3555   "ParamŠtres de la ligne de commande"
#define it_Auto3555   "Command Line Parameters"
#define es_Auto3555   "Command Line Parameters"
#define de_Auto3555   "Command Line Parameters"
#define nl_Auto3555   "Command Line Parameters"
#define pt_Auto3555   "Command Line Parameters"
#define xx_Auto3555   "Command Line Parameters"
#define en__Auto3555   ""
#define fr__Auto3555   ""
#define it__Auto3555   ""
#define es__Auto3555   ""
#define de__Auto3555   ""
#define nl__Auto3555   ""
#define pt__Auto3555   ""
#define xx__Auto3555   ""
#define en_Auto3556   "Debug Root Path"
#define fr_Auto3556   "Chemin racine des sources"
#define it_Auto3556   "Debug Root Path"
#define es_Auto3556   "Debug Root Path"
#define de_Auto3556   "Debug Root Path"
#define nl_Auto3556   "Debug Root Path"
#define pt_Auto3556   "Debug Root Path"
#define xx_Auto3556   "Debug Root Path"
#define en__Auto3556   ""
#define fr__Auto3556   ""
#define it__Auto3556   ""
#define es__Auto3556   ""
#define de__Auto3556   ""
#define nl__Auto3556   ""
#define pt__Auto3556   ""
#define xx__Auto3556   ""
#define en_FileName   ""
#define en_CommandLine   ""
#define en_Select   "..."
#define fr_Select   "..."
#define it_Select   "..."
#define es_Select   "..."
#define de_Select   "..."
#define nl_Select   "..."
#define pt_Select   "..."
#define xx_Select   "..."
#define en__Select   ""
#define en_IsDebug   "&Debug"
#define fr_IsDebug   "&Debug"
#define it_IsDebug   "&Debug"
#define es_IsDebug   "&Debug"
#define de_IsDebug   "&Debug"
#define nl_IsDebug   "&Debug"
#define pt_IsDebug   "&Debug"
#define xx_IsDebug   "&Debug"
#define en__IsDebug   ""
#define fr__IsDebug   ""
#define it__IsDebug   ""
#define es__IsDebug   ""
#define de__IsDebug   ""
#define nl__IsDebug   ""
#define pt__IsDebug   ""
#define xx__IsDebug   ""
#define en_Debugger   ""
#define en__Debugger   ""
#define en_ChoixDebugger   "..."
#define fr_ChoixDebugger   "..."
#define it_ChoixDebugger   "..."
#define es_ChoixDebugger   "..."
#define de_ChoixDebugger   "..."
#define nl_ChoixDebugger   "..."
#define pt_ChoixDebugger   "..."
#define xx_ChoixDebugger   "..."
#define en__ChoixDebugger   ""
#define fr__ChoixDebugger   ""
#define it__ChoixDebugger   ""
#define es__ChoixDebugger   ""
#define de__ChoixDebugger   ""
#define nl__ChoixDebugger   ""
#define pt__ChoixDebugger   ""
#define xx__ChoixDebugger   ""
#define en_DebugRoot   ""
#define en__DebugRoot   ""
#define en_ChoixDebugRoot   "..."
#define fr_ChoixDebugRoot   "..."
#define it_ChoixDebugRoot   "..."
#define es_ChoixDebugRoot   "..."
#define de_ChoixDebugRoot   "..."
#define nl_ChoixDebugRoot   "..."
#define pt_ChoixDebugRoot   "..."
#define xx_ChoixDebugRoot   "..."
#define en__ChoixDebugRoot   ""
#define fr__ChoixDebugRoot   ""
#define it__ChoixDebugRoot   ""
#define es__ChoixDebugRoot   ""
#define de__ChoixDebugRoot   ""
#define nl__ChoixDebugRoot   ""
#define pt__ChoixDebugRoot   ""
#define xx__ChoixDebugRoot   ""
#define en_Runtime   ""
#define en__Runtime   ""
#define en_ChoixRuntime   "..."
#define fr_ChoixRuntime   "..."
#define it_ChoixRuntime   "..."
#define es_ChoixRuntime   "..."
#define de_ChoixRuntime   "..."
#define nl_ChoixRuntime   "..."
#define pt_ChoixRuntime   "..."
#define xx_ChoixRuntime   "..."
#define en__ChoixRuntime   ""
#define fr__ChoixRuntime   ""
#define it__ChoixRuntime   ""
#define es__ChoixRuntime   ""
#define de__ChoixRuntime   ""
#define nl__ChoixRuntime   ""
#define pt__ChoixRuntime   ""
#define xx__ChoixRuntime   ""
#define en_Auto3557   "ok.gif"
#define fr_Auto3557   "ok.gif"
#define it_Auto3557   "ok.gif"
#define es_Auto3557   "ok.gif"
#define de_Auto3557   "ok.gif"
#define nl_Auto3557   "ok.gif"
#define pt_Auto3557   "ok.gif"
#define xx_Auto3557   "ok.gif"
#define en_Auto3558   "cancel.gif"
#define fr_Auto3558   "cancel.gif"
#define it_Auto3558   "cancel.gif"
#define es_Auto3558   "cancel.gif"
#define de_Auto3558   "cancel.gif"
#define nl_Auto3558   "cancel.gif"
#define pt_Auto3558   "cancel.gif"
#define xx_Auto3558   "cancel.gif"

private struct accept_debug_parameters_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3547[8];
	char * hint_Auto3547[8];
	int	x_Auto3547;
	int	y_Auto3547;
	int	w_Auto3547;
	int	h_Auto3547;
	char * hint_Auto3548[8];
	char * msg_Auto3549[8];
	char * hint_Auto3549[8];
	char * msg_Auto3550[8];
	char * hint_Auto3550[8];
	char * msg_Auto3551[8];
	char * hint_Auto3551[8];
	char * msg_Auto3552[8];
	char * hint_Auto3552[8];
	char * msg_Auto3553[8];
	char * hint_Auto3553[8];
	char * msg_Auto3554[8];
	char * hint_Auto3554[8];
	char * msg_Auto3555[8];
	char * hint_Auto3555[8];
	char * msg_Auto3556[8];
	char * hint_Auto3556[8];
	char * hint_FileName[8];
	char	buffer_FileName[256];
	char * hint_CommandLine[8];
	char	buffer_CommandLine[256];
	char * msg_Select[8];
	int	trigger_Select;
	char * hint_Select[8];
	char * msg_IsDebug[8];
	int	trigger_IsDebug;
	char * hint_IsDebug[8];
	int	value_IsDebug;
	char * hint_Debugger[8];
	char	buffer_Debugger[256];
	char * msg_ChoixDebugger[8];
	int	trigger_ChoixDebugger;
	char * hint_ChoixDebugger[8];
	char * hint_DebugRoot[8];
	char	buffer_DebugRoot[256];
	char * msg_ChoixDebugRoot[8];
	int	trigger_ChoixDebugRoot;
	char * hint_ChoixDebugRoot[8];
	char * hint_Runtime[8];
	char	buffer_Runtime[256];
	char * msg_ChoixRuntime[8];
	int	trigger_ChoixRuntime;
	char * hint_ChoixRuntime[8];
	char * msg_Auto3557[8];
	int	trigger_Auto3557;
	char * hint_Auto3557[8];
	char * msg_Auto3558[8];
	int	trigger_Auto3558;
	char * hint_Auto3558[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[7];
	};
static int	vfh[16];
private int on_Select_event(struct accept_debug_parameters_context * _Context);
private int on_ChoixDebugger_event(struct accept_debug_parameters_context * _Context);
private int on_ChoixDebugRoot_event(struct accept_debug_parameters_context * _Context);
private int on_ChoixRuntime_event(struct accept_debug_parameters_context * _Context);
private int on_Auto3557_event(struct accept_debug_parameters_context * _Context);
private int on_Auto3558_event(struct accept_debug_parameters_context * _Context);

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
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("bmap0414.fmf",12);
	if (!(_Context = allocate( sizeof( struct accept_debug_parameters_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=13;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 255, pFileName);
		visual_transferin(_Context->buffer_CommandLine, 255, pCommandLine);
		visual_transferin((void *) 0, 0, pIsDebug);
		if (!( pIsDebug )) _Context->value_IsDebug=0;
		else	_Context->value_IsDebug = *((int *)pIsDebug);
		visual_transferin(_Context->buffer_Debugger, 255, pDebugger);
		visual_transferin(_Context->buffer_DebugRoot, 255, pDebugRoot);
		visual_transferin(_Context->buffer_Runtime, 255, pRuntime);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3547[i]=" ";
	_Context->hint_Auto3547[0]=en__Auto3547;
	_Context->hint_Auto3547[1]=fr__Auto3547;
	_Context->hint_Auto3547[2]=it__Auto3547;
	_Context->hint_Auto3547[3]=es__Auto3547;
	_Context->hint_Auto3547[4]=de__Auto3547;
	_Context->hint_Auto3547[5]=nl__Auto3547;
	_Context->hint_Auto3547[6]=pt__Auto3547;
	_Context->hint_Auto3547[7]=xx__Auto3547;
	_Context->x_Auto3547=135;
	_Context->y_Auto3547=75;
	_Context->w_Auto3547=530;
	_Context->h_Auto3547=450;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3549[i]=" ";
	_Context->msg_Auto3549[0]=en_Auto3549;
	_Context->msg_Auto3549[1]=fr_Auto3549;
	_Context->msg_Auto3549[2]=it_Auto3549;
	_Context->msg_Auto3549[3]=es_Auto3549;
	_Context->msg_Auto3549[4]=de_Auto3549;
	_Context->msg_Auto3549[5]=nl_Auto3549;
	_Context->msg_Auto3549[6]=pt_Auto3549;
	_Context->msg_Auto3549[7]=xx_Auto3549;
	_Context->hint_Auto3549[0]=en__Auto3549;
	_Context->hint_Auto3549[1]=fr__Auto3549;
	_Context->hint_Auto3549[2]=it__Auto3549;
	_Context->hint_Auto3549[3]=es__Auto3549;
	_Context->hint_Auto3549[4]=de__Auto3549;
	_Context->hint_Auto3549[5]=nl__Auto3549;
	_Context->hint_Auto3549[6]=pt__Auto3549;
	_Context->hint_Auto3549[7]=xx__Auto3549;
	for (i=0; i < 8; i++)_Context->msg_Auto3550[i]=" ";
	_Context->msg_Auto3550[0]=en_Auto3550;
	_Context->msg_Auto3550[1]=fr_Auto3550;
	_Context->msg_Auto3550[2]=it_Auto3550;
	_Context->msg_Auto3550[3]=es_Auto3550;
	_Context->msg_Auto3550[4]=de_Auto3550;
	_Context->msg_Auto3550[5]=nl_Auto3550;
	_Context->msg_Auto3550[6]=pt_Auto3550;
	_Context->msg_Auto3550[7]=xx_Auto3550;
	_Context->hint_Auto3550[0]=en__Auto3550;
	_Context->hint_Auto3550[1]=fr__Auto3550;
	_Context->hint_Auto3550[2]=it__Auto3550;
	_Context->hint_Auto3550[3]=es__Auto3550;
	_Context->hint_Auto3550[4]=de__Auto3550;
	_Context->hint_Auto3550[5]=nl__Auto3550;
	_Context->hint_Auto3550[6]=pt__Auto3550;
	_Context->hint_Auto3550[7]=xx__Auto3550;
	for (i=0; i < 8; i++)_Context->msg_Auto3551[i]=" ";
	_Context->msg_Auto3551[0]=en_Auto3551;
	_Context->msg_Auto3551[1]=fr_Auto3551;
	_Context->msg_Auto3551[2]=it_Auto3551;
	_Context->msg_Auto3551[3]=es_Auto3551;
	_Context->msg_Auto3551[4]=de_Auto3551;
	_Context->msg_Auto3551[5]=nl_Auto3551;
	_Context->msg_Auto3551[6]=pt_Auto3551;
	_Context->msg_Auto3551[7]=xx_Auto3551;
	_Context->hint_Auto3551[0]=en__Auto3551;
	_Context->hint_Auto3551[1]=fr__Auto3551;
	_Context->hint_Auto3551[2]=it__Auto3551;
	_Context->hint_Auto3551[3]=es__Auto3551;
	_Context->hint_Auto3551[4]=de__Auto3551;
	_Context->hint_Auto3551[5]=nl__Auto3551;
	_Context->hint_Auto3551[6]=pt__Auto3551;
	_Context->hint_Auto3551[7]=xx__Auto3551;
	for (i=0; i < 8; i++)_Context->msg_Auto3552[i]=" ";
	_Context->msg_Auto3552[0]=en_Auto3552;
	_Context->msg_Auto3552[1]=fr_Auto3552;
	_Context->msg_Auto3552[2]=it_Auto3552;
	_Context->msg_Auto3552[3]=es_Auto3552;
	_Context->msg_Auto3552[4]=de_Auto3552;
	_Context->msg_Auto3552[5]=nl_Auto3552;
	_Context->msg_Auto3552[6]=pt_Auto3552;
	_Context->msg_Auto3552[7]=xx_Auto3552;
	for (i=0; i < 8; i++)_Context->msg_Auto3553[i]=" ";
	_Context->msg_Auto3553[0]=en_Auto3553;
	_Context->msg_Auto3553[1]=fr_Auto3553;
	_Context->msg_Auto3553[2]=it_Auto3553;
	_Context->msg_Auto3553[3]=es_Auto3553;
	_Context->msg_Auto3553[4]=de_Auto3553;
	_Context->msg_Auto3553[5]=nl_Auto3553;
	_Context->msg_Auto3553[6]=pt_Auto3553;
	_Context->msg_Auto3553[7]=xx_Auto3553;
	for (i=0; i < 8; i++)_Context->msg_Auto3554[i]=" ";
	_Context->msg_Auto3554[0]=en_Auto3554;
	_Context->msg_Auto3554[1]=fr_Auto3554;
	_Context->msg_Auto3554[2]=it_Auto3554;
	_Context->msg_Auto3554[3]=es_Auto3554;
	_Context->msg_Auto3554[4]=de_Auto3554;
	_Context->msg_Auto3554[5]=nl_Auto3554;
	_Context->msg_Auto3554[6]=pt_Auto3554;
	_Context->msg_Auto3554[7]=xx_Auto3554;
	_Context->hint_Auto3554[0]=en__Auto3554;
	_Context->hint_Auto3554[1]=fr__Auto3554;
	_Context->hint_Auto3554[2]=it__Auto3554;
	_Context->hint_Auto3554[3]=es__Auto3554;
	_Context->hint_Auto3554[4]=de__Auto3554;
	_Context->hint_Auto3554[5]=nl__Auto3554;
	_Context->hint_Auto3554[6]=pt__Auto3554;
	_Context->hint_Auto3554[7]=xx__Auto3554;
	for (i=0; i < 8; i++)_Context->msg_Auto3555[i]=" ";
	_Context->msg_Auto3555[0]=en_Auto3555;
	_Context->msg_Auto3555[1]=fr_Auto3555;
	_Context->msg_Auto3555[2]=it_Auto3555;
	_Context->msg_Auto3555[3]=es_Auto3555;
	_Context->msg_Auto3555[4]=de_Auto3555;
	_Context->msg_Auto3555[5]=nl_Auto3555;
	_Context->msg_Auto3555[6]=pt_Auto3555;
	_Context->msg_Auto3555[7]=xx_Auto3555;
	_Context->hint_Auto3555[0]=en__Auto3555;
	_Context->hint_Auto3555[1]=fr__Auto3555;
	_Context->hint_Auto3555[2]=it__Auto3555;
	_Context->hint_Auto3555[3]=es__Auto3555;
	_Context->hint_Auto3555[4]=de__Auto3555;
	_Context->hint_Auto3555[5]=nl__Auto3555;
	_Context->hint_Auto3555[6]=pt__Auto3555;
	_Context->hint_Auto3555[7]=xx__Auto3555;
	for (i=0; i < 8; i++)_Context->msg_Auto3556[i]=" ";
	_Context->msg_Auto3556[0]=en_Auto3556;
	_Context->msg_Auto3556[1]=fr_Auto3556;
	_Context->msg_Auto3556[2]=it_Auto3556;
	_Context->msg_Auto3556[3]=es_Auto3556;
	_Context->msg_Auto3556[4]=de_Auto3556;
	_Context->msg_Auto3556[5]=nl_Auto3556;
	_Context->msg_Auto3556[6]=pt_Auto3556;
	_Context->msg_Auto3556[7]=xx_Auto3556;
	_Context->hint_Auto3556[0]=en__Auto3556;
	_Context->hint_Auto3556[1]=fr__Auto3556;
	_Context->hint_Auto3556[2]=it__Auto3556;
	_Context->hint_Auto3556[3]=es__Auto3556;
	_Context->hint_Auto3556[4]=de__Auto3556;
	_Context->hint_Auto3556[5]=nl__Auto3556;
	_Context->hint_Auto3556[6]=pt__Auto3556;
	_Context->hint_Auto3556[7]=xx__Auto3556;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	_Context->msg_Select[2]=it_Select;
	_Context->msg_Select[3]=es_Select;
	_Context->msg_Select[4]=de_Select;
	_Context->msg_Select[5]=nl_Select;
	_Context->msg_Select[6]=pt_Select;
	_Context->msg_Select[7]=xx_Select;
	_Context->hint_Select[0]=en__Select;
	for (i=0; i < 8; i++)_Context->msg_IsDebug[i]=" ";
	_Context->msg_IsDebug[0]=en_IsDebug;
	_Context->msg_IsDebug[1]=fr_IsDebug;
	_Context->msg_IsDebug[2]=it_IsDebug;
	_Context->msg_IsDebug[3]=es_IsDebug;
	_Context->msg_IsDebug[4]=de_IsDebug;
	_Context->msg_IsDebug[5]=nl_IsDebug;
	_Context->msg_IsDebug[6]=pt_IsDebug;
	_Context->msg_IsDebug[7]=xx_IsDebug;
	_Context->hint_IsDebug[0]=en__IsDebug;
	_Context->hint_IsDebug[1]=fr__IsDebug;
	_Context->hint_IsDebug[2]=it__IsDebug;
	_Context->hint_IsDebug[3]=es__IsDebug;
	_Context->hint_IsDebug[4]=de__IsDebug;
	_Context->hint_IsDebug[5]=nl__IsDebug;
	_Context->hint_IsDebug[6]=pt__IsDebug;
	_Context->hint_IsDebug[7]=xx__IsDebug;
	_Context->hint_Debugger[0]=en__Debugger;
	for (i=0; i < 8; i++)_Context->msg_ChoixDebugger[i]=" ";
	_Context->msg_ChoixDebugger[0]=en_ChoixDebugger;
	_Context->msg_ChoixDebugger[1]=fr_ChoixDebugger;
	_Context->msg_ChoixDebugger[2]=it_ChoixDebugger;
	_Context->msg_ChoixDebugger[3]=es_ChoixDebugger;
	_Context->msg_ChoixDebugger[4]=de_ChoixDebugger;
	_Context->msg_ChoixDebugger[5]=nl_ChoixDebugger;
	_Context->msg_ChoixDebugger[6]=pt_ChoixDebugger;
	_Context->msg_ChoixDebugger[7]=xx_ChoixDebugger;
	_Context->hint_ChoixDebugger[0]=en__ChoixDebugger;
	_Context->hint_ChoixDebugger[1]=fr__ChoixDebugger;
	_Context->hint_ChoixDebugger[2]=it__ChoixDebugger;
	_Context->hint_ChoixDebugger[3]=es__ChoixDebugger;
	_Context->hint_ChoixDebugger[4]=de__ChoixDebugger;
	_Context->hint_ChoixDebugger[5]=nl__ChoixDebugger;
	_Context->hint_ChoixDebugger[6]=pt__ChoixDebugger;
	_Context->hint_ChoixDebugger[7]=xx__ChoixDebugger;
	_Context->hint_DebugRoot[0]=en__DebugRoot;
	for (i=0; i < 8; i++)_Context->msg_ChoixDebugRoot[i]=" ";
	_Context->msg_ChoixDebugRoot[0]=en_ChoixDebugRoot;
	_Context->msg_ChoixDebugRoot[1]=fr_ChoixDebugRoot;
	_Context->msg_ChoixDebugRoot[2]=it_ChoixDebugRoot;
	_Context->msg_ChoixDebugRoot[3]=es_ChoixDebugRoot;
	_Context->msg_ChoixDebugRoot[4]=de_ChoixDebugRoot;
	_Context->msg_ChoixDebugRoot[5]=nl_ChoixDebugRoot;
	_Context->msg_ChoixDebugRoot[6]=pt_ChoixDebugRoot;
	_Context->msg_ChoixDebugRoot[7]=xx_ChoixDebugRoot;
	_Context->hint_ChoixDebugRoot[0]=en__ChoixDebugRoot;
	_Context->hint_ChoixDebugRoot[1]=fr__ChoixDebugRoot;
	_Context->hint_ChoixDebugRoot[2]=it__ChoixDebugRoot;
	_Context->hint_ChoixDebugRoot[3]=es__ChoixDebugRoot;
	_Context->hint_ChoixDebugRoot[4]=de__ChoixDebugRoot;
	_Context->hint_ChoixDebugRoot[5]=nl__ChoixDebugRoot;
	_Context->hint_ChoixDebugRoot[6]=pt__ChoixDebugRoot;
	_Context->hint_ChoixDebugRoot[7]=xx__ChoixDebugRoot;
	_Context->hint_Runtime[0]=en__Runtime;
	for (i=0; i < 8; i++)_Context->msg_ChoixRuntime[i]=" ";
	_Context->msg_ChoixRuntime[0]=en_ChoixRuntime;
	_Context->msg_ChoixRuntime[1]=fr_ChoixRuntime;
	_Context->msg_ChoixRuntime[2]=it_ChoixRuntime;
	_Context->msg_ChoixRuntime[3]=es_ChoixRuntime;
	_Context->msg_ChoixRuntime[4]=de_ChoixRuntime;
	_Context->msg_ChoixRuntime[5]=nl_ChoixRuntime;
	_Context->msg_ChoixRuntime[6]=pt_ChoixRuntime;
	_Context->msg_ChoixRuntime[7]=xx_ChoixRuntime;
	_Context->hint_ChoixRuntime[0]=en__ChoixRuntime;
	_Context->hint_ChoixRuntime[1]=fr__ChoixRuntime;
	_Context->hint_ChoixRuntime[2]=it__ChoixRuntime;
	_Context->hint_ChoixRuntime[3]=es__ChoixRuntime;
	_Context->hint_ChoixRuntime[4]=de__ChoixRuntime;
	_Context->hint_ChoixRuntime[5]=nl__ChoixRuntime;
	_Context->hint_ChoixRuntime[6]=pt__ChoixRuntime;
	_Context->hint_ChoixRuntime[7]=xx__ChoixRuntime;
	for (i=0; i < 8; i++)_Context->msg_Auto3557[i]=" ";
	_Context->msg_Auto3557[0]=en_Auto3557;
	_Context->msg_Auto3557[1]=fr_Auto3557;
	_Context->msg_Auto3557[2]=it_Auto3557;
	_Context->msg_Auto3557[3]=es_Auto3557;
	_Context->msg_Auto3557[4]=de_Auto3557;
	_Context->msg_Auto3557[5]=nl_Auto3557;
	_Context->msg_Auto3557[6]=pt_Auto3557;
	_Context->msg_Auto3557[7]=xx_Auto3557;
	for (i=0; i < 8; i++)_Context->msg_Auto3558[i]=" ";
	_Context->msg_Auto3558[0]=en_Auto3558;
	_Context->msg_Auto3558[1]=fr_Auto3558;
	_Context->msg_Auto3558[2]=it_Auto3558;
	_Context->msg_Auto3558[3]=es_Auto3558;
	_Context->msg_Auto3558[4]=de_Auto3558;
	_Context->msg_Auto3558[5]=nl_Auto3558;
	_Context->msg_Auto3558[6]=pt_Auto3558;
	_Context->msg_Auto3558[7]=xx_Auto3558;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3547,_Context->y_Auto3547,530+10,450+10);
	return(0);
}

public 	int	accept_debug_parameters_hide(struct accept_debug_parameters_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3547,_Context->y_Auto3547);
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
		visual_transferout(_Context->buffer_FileName, 255, pFileName);
		visual_transferout(_Context->buffer_CommandLine, 255, pCommandLine);
		visual_transferout((void *) 0, 0, pIsDebug);
		if ( pIsDebug != (char *) 0)
			*((int*)pIsDebug) = _Context->value_IsDebug;
		visual_transferout(_Context->buffer_Debugger, 255, pDebugger);
		visual_transferout(_Context->buffer_DebugRoot, 255, pDebugRoot);
		visual_transferout(_Context->buffer_Runtime, 255, pRuntime);
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
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3547,_Context->y_Auto3547);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3547,_Context->y_Auto3547,530,450,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3547,_Context->y_Auto3547,530,450,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_frame(_Context->x_Auto3547+198,_Context->y_Auto3547+394,136,25,2);
	visual_text(_Context->x_Auto3547+30,_Context->y_Auto3547+30,370,30,vfh[3],27,0,_Context->msg_Auto3549[_Context->language],strlen(_Context->msg_Auto3549[_Context->language]),1282);
	visual_text(_Context->x_Auto3547+30,_Context->y_Auto3547+220,470,20,vfh[2],27,0,_Context->msg_Auto3550[_Context->language],strlen(_Context->msg_Auto3550[_Context->language]),2);
	visual_text(_Context->x_Auto3547+30,_Context->y_Auto3547+320,470,20,vfh[2],27,0,_Context->msg_Auto3551[_Context->language],strlen(_Context->msg_Auto3551[_Context->language]),2);
	visual_image(_Context->x_Auto3547+420,_Context->y_Auto3547+20,40,60,_Context->msg_Auto3552[_Context->language],3);
	visual_image(_Context->x_Auto3547+460,_Context->y_Auto3547+20,50,60,_Context->msg_Auto3553[_Context->language],3);
	visual_text(_Context->x_Auto3547+30,_Context->y_Auto3547+80,470,20,vfh[2],27,0,_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]),2);
	visual_text(_Context->x_Auto3547+30,_Context->y_Auto3547+130,470,20,vfh[2],27,0,_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]),2);
	visual_text(_Context->x_Auto3547+30,_Context->y_Auto3547+270,470,20,vfh[2],27,0,_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]),2);
	visual_frame(_Context->x_Auto3547+30,_Context->y_Auto3547+100,456+2,16+2,5);
	visual_text(_Context->x_Auto3547+30+1,_Context->y_Auto3547+100+1,456,16,vfh[1],16,0,_Context->buffer_FileName,255,0);
	visual_frame(_Context->x_Auto3547+30,_Context->y_Auto3547+150,480+2,64+2,5);
	visual_text(_Context->x_Auto3547+30+1,_Context->y_Auto3547+150+1,480,64,vfh[1],16,28,_Context->buffer_CommandLine,255,0);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+100,20,20,vfh[1],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	_Context->trigger_IsDebug=visual_trigger_code(_Context->msg_IsDebug[_Context->language],strlen(_Context->msg_IsDebug[_Context->language]));
	visual_check(_Context->x_Auto3547+210,_Context->y_Auto3547+400,116,17,vfh[2],16,0,_Context->msg_IsDebug[_Context->language],strlen(_Context->msg_IsDebug[_Context->language]),_Context->value_IsDebug|0);
	visual_frame(_Context->x_Auto3547+30,_Context->y_Auto3547+240,456+2,16+2,5);
	visual_text(_Context->x_Auto3547+30+1,_Context->y_Auto3547+240+1,456,16,vfh[1],16,28,_Context->buffer_Debugger,255,0);
	_Context->trigger_ChoixDebugger=visual_trigger_code(_Context->msg_ChoixDebugger[_Context->language],strlen(_Context->msg_ChoixDebugger[_Context->language]));
	visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+240,20,20,vfh[1],27,28,_Context->msg_ChoixDebugger[_Context->language],strlen(_Context->msg_ChoixDebugger[_Context->language]),0);
	visual_frame(_Context->x_Auto3547+30,_Context->y_Auto3547+290,456+2,16+2,5);
	visual_text(_Context->x_Auto3547+30+1,_Context->y_Auto3547+290+1,456,16,vfh[1],16,28,_Context->buffer_DebugRoot,255,0);
	_Context->trigger_ChoixDebugRoot=visual_trigger_code(_Context->msg_ChoixDebugRoot[_Context->language],strlen(_Context->msg_ChoixDebugRoot[_Context->language]));
	visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+290,20,20,vfh[8],27,28,_Context->msg_ChoixDebugRoot[_Context->language],strlen(_Context->msg_ChoixDebugRoot[_Context->language]),0);
	visual_frame(_Context->x_Auto3547+30,_Context->y_Auto3547+340,456+2,16+2,5);
	visual_text(_Context->x_Auto3547+30+1,_Context->y_Auto3547+340+1,456,16,vfh[1],16,28,_Context->buffer_Runtime,255,0);
	_Context->trigger_ChoixRuntime=visual_trigger_code(_Context->msg_ChoixRuntime[_Context->language],strlen(_Context->msg_ChoixRuntime[_Context->language]));
	visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+340,20,20,vfh[1],27,28,_Context->msg_ChoixRuntime[_Context->language],strlen(_Context->msg_ChoixRuntime[_Context->language]),0);
	_Context->trigger_Auto3557=visual_trigger_code(_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]));
	visual_button(_Context->x_Auto3547+30,_Context->y_Auto3547+380,56,48,vfh[2],34,0,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),1040);
	_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
	visual_button(_Context->x_Auto3547+440,_Context->y_Auto3547+380,56,48,vfh[2],34,0,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3547,_Context->y_Auto3547,530,450);

	return(0);
}

private int FileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows modification or selection of the name of the ";
			mptr[1]="ABAL 3 program to be run or debugged.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CommandLine_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows any eventual command line parameters to be ";
			mptr[1]="specified prior to launching the program.   ";
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
			char * mptr[3];
			mptr[0] = "The Select button provides access  to the file selection dialog frame ";
			mptr[1]="allowing prompted selection of the filename of the ABAL3 program to ";
			mptr[2]="be run or debugged.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsDebug_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This check control switchs the operational mode between debug and ";
			mptr[1]="runtime. When checked the debug utility will be lauched otherwise ";
			mptr[2]="the standard runtime module will be used to run the program.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Debugger_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This constant edit field presents the name of the ABAL 3 debug utility ";
			mptr[1]="as defined by the Options Configure Exadb parameter of the Configuration Options dialog ";
			mptr[2]="box.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DebugRoot_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows the debug root path to be specified. This value ";
			mptr[1]="may be required if the source files of the program to debugged have ";
			mptr[2]="been translated without explicite path information and are not present ";
			mptr[3]="in the current working directory.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Runtime_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This constant edit field presents the name of the ABAL 3 runtime utility ";
			mptr[1]="as defined by the Options Configure Exa parameter of the Configuration Options dialog ";
			mptr[2]="box.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3557_help()
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

private int Auto3558_help()
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

private int Auto3547action(struct accept_debug_parameters_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_debug_parameters_hide(_Context);

		_Context->x_Auto3547 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3547 < 0) { _Context->x_Auto3547=0; }
		_Context->y_Auto3547 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3547 < 0) { _Context->y_Auto3547=0; }
			accept_debug_parameters_show(_Context);

		visual_thaw(_Context->x_Auto3547,_Context->y_Auto3547,530,450);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Select_event(struct accept_debug_parameters_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_AT);
		accept_debug_parameters_show(_Context);
;
	return(-1);
}
private int on_ChoixDebugger_event(struct accept_debug_parameters_context * _Context) {
	use_file_selector(_Context->buffer_Debugger,WIDGET_FILE_EXE);
		accept_debug_parameters_show(_Context);
;
	return(-1);
}
private int on_ChoixDebugRoot_event(struct accept_debug_parameters_context * _Context) {
	switch(visual_national_language(-1))
	{
	case 1:
	if(ChoixRep(_Context->buffer_DebugRoot,"Repertoire de stockage des sources"))
		accept_debug_parameters_show(_Context);
;
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	if(ChoixRep(_Context->buffer_DebugRoot,"Directory for the AS documents"))
		accept_debug_parameters_show(_Context);
;
	break;
	};
	return(-1);
}
private int on_ChoixRuntime_event(struct accept_debug_parameters_context * _Context) {
	use_file_selector(_Context->buffer_Runtime,WIDGET_FILE_EXE);
		accept_debug_parameters_show(_Context);
;
	return(-1);
}
private int on_Auto3557_event(struct accept_debug_parameters_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3558_event(struct accept_debug_parameters_context * _Context) {
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
		if (_Context->trigger_ChoixDebugger == mb ) return(7);
		if (_Context->trigger_ChoixDebugRoot == mb ) return(9);
		if (_Context->trigger_ChoixRuntime == mb ) return(11);
		if (_Context->trigger_Auto3557 == mb ) return(12);
		if (_Context->trigger_Auto3558 == mb ) return(13);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3547+509) )  
	&&  (my >= (_Context->y_Auto3547+4) )  
	&&  (mx <= (_Context->x_Auto3547+526) )  
	&&  (my <= (_Context->y_Auto3547+20) )) {
		return(1);	/* Auto3547 */

		}
	if ((mx >= (_Context->x_Auto3547+493) )  
	&&  (my >= (_Context->y_Auto3547+4) )  
	&&  (mx <= (_Context->x_Auto3547+510) )  
	&&  (my <= (_Context->y_Auto3547+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vdebug.htm");
			};
		return(-1);	/* Auto3547 */

		}
	if ((mx >= (_Context->x_Auto3547+477) )  
	&&  (my >= (_Context->y_Auto3547+4) )  
	&&  (mx <= (_Context->x_Auto3547+494) )  
	&&  (my <= (_Context->y_Auto3547+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_debug_parameters_show(_Context);
		return(-1);	/* Auto3547 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3547+4) )  
		&&  (my >= (_Context->y_Auto3547+4) )  
		&&  (mx <= (_Context->x_Auto3547+462) )  
		&&  (my <= (_Context->y_Auto3547+20) )) {
			return( Auto3547action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3547+30) ) 
	&&  ( my >= (_Context->y_Auto3547+100) ) 
	&&  ( mx <= (_Context->x_Auto3547+30+456) ) 
	&&  ( my <= (_Context->y_Auto3547+100+16))) {
		return(2); /* FileName */
		}
	if (( mx >= (_Context->x_Auto3547+30) ) 
	&&  ( my >= (_Context->y_Auto3547+150) ) 
	&&  ( mx <= (_Context->x_Auto3547+30+480) ) 
	&&  ( my <= (_Context->y_Auto3547+150+64))) {
		return(3); /* CommandLine */
		}
	if (( mx >= (_Context->x_Auto3547+490) ) 
	&&  ( my >= (_Context->y_Auto3547+100) ) 
	&&  ( mx <= (_Context->x_Auto3547+490+20) ) 
	&&  ( my <= (_Context->y_Auto3547+100+20))) {
		return(4); /* Select */
		}
	if (( mx >= (_Context->x_Auto3547+210) ) 
	&&  ( my >= (_Context->y_Auto3547+400) ) 
	&&  ( mx <= (_Context->x_Auto3547+210+116) ) 
	&&  ( my <= (_Context->y_Auto3547+400+17))) {
		return(5); /* IsDebug */
		}
	if (( mx >= (_Context->x_Auto3547+30) ) 
	&&  ( my >= (_Context->y_Auto3547+240) ) 
	&&  ( mx <= (_Context->x_Auto3547+30+456) ) 
	&&  ( my <= (_Context->y_Auto3547+240+16))) {
		return(6); /* Debugger */
		}
	if (( mx >= (_Context->x_Auto3547+490) ) 
	&&  ( my >= (_Context->y_Auto3547+240) ) 
	&&  ( mx <= (_Context->x_Auto3547+490+20) ) 
	&&  ( my <= (_Context->y_Auto3547+240+20))) {
		return(7); /* ChoixDebugger */
		}
	if (( mx >= (_Context->x_Auto3547+30) ) 
	&&  ( my >= (_Context->y_Auto3547+290) ) 
	&&  ( mx <= (_Context->x_Auto3547+30+456) ) 
	&&  ( my <= (_Context->y_Auto3547+290+16))) {
		return(8); /* DebugRoot */
		}
	if (( mx >= (_Context->x_Auto3547+490) ) 
	&&  ( my >= (_Context->y_Auto3547+290) ) 
	&&  ( mx <= (_Context->x_Auto3547+490+20) ) 
	&&  ( my <= (_Context->y_Auto3547+290+20))) {
		return(9); /* ChoixDebugRoot */
		}
	if (( mx >= (_Context->x_Auto3547+30) ) 
	&&  ( my >= (_Context->y_Auto3547+340) ) 
	&&  ( mx <= (_Context->x_Auto3547+30+456) ) 
	&&  ( my <= (_Context->y_Auto3547+340+16))) {
		return(10); /* Runtime */
		}
	if (( mx >= (_Context->x_Auto3547+490) ) 
	&&  ( my >= (_Context->y_Auto3547+340) ) 
	&&  ( mx <= (_Context->x_Auto3547+490+20) ) 
	&&  ( my <= (_Context->y_Auto3547+340+20))) {
		return(11); /* ChoixRuntime */
		}
	if (( mx >= (_Context->x_Auto3547+30) ) 
	&&  ( my >= (_Context->y_Auto3547+380) ) 
	&&  ( mx <= (_Context->x_Auto3547+30+56) ) 
	&&  ( my <= (_Context->y_Auto3547+380+48))) {
		return(12); /* Auto3557 */
		}
	if (( mx >= (_Context->x_Auto3547+440) ) 
	&&  ( my >= (_Context->y_Auto3547+380) ) 
	&&  ( mx <= (_Context->x_Auto3547+440+56) ) 
	&&  ( my <= (_Context->y_Auto3547+380+48))) {
		return(13); /* Auto3558 */
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
				_Context->keycode = visual_edit(_Context->x_Auto3547+30+1,_Context->y_Auto3547+100+1,456,16,vfh[1],_Context->buffer_FileName,255);
			break;
			case	0x3 :
				/* CommandLine */
				_Context->keycode = visual_edit(_Context->x_Auto3547+30+1,_Context->y_Auto3547+150+1,480,64,vfh[1],_Context->buffer_CommandLine,255);
			break;
			case	0x4 :
				/* Select */
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
				visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+100,20,20,vfh[1],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+100,20,20,vfh[1],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0x5 :
				/* IsDebug */
				visual_check(_Context->x_Auto3547+210,_Context->y_Auto3547+400,116,17,vfh[2],16,0,_Context->msg_IsDebug[_Context->language],strlen(_Context->msg_IsDebug[_Context->language]),(_Context->value_IsDebug |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsDebug=visual_trigger_code(_Context->msg_IsDebug[_Context->language],strlen(_Context->msg_IsDebug[_Context->language]));
	visual_check(_Context->x_Auto3547+210,_Context->y_Auto3547+400,116,17,vfh[2],16,0,_Context->msg_IsDebug[_Context->language],strlen(_Context->msg_IsDebug[_Context->language]),_Context->value_IsDebug|0);
				break;
			case	0x6 :
				/* Debugger */
				_Context->keycode = visual_edit(_Context->x_Auto3547+30+1,_Context->y_Auto3547+240+1,456,16,vfh[1],_Context->buffer_Debugger,255);
			break;
			case	0x7 :
				/* ChoixDebugger */
				_Context->trigger_ChoixDebugger=visual_trigger_code(_Context->msg_ChoixDebugger[_Context->language],strlen(_Context->msg_ChoixDebugger[_Context->language]));
				visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+240,20,20,vfh[1],27,28,_Context->msg_ChoixDebugger[_Context->language],strlen(_Context->msg_ChoixDebugger[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_ChoixDebugger=visual_trigger_code(_Context->msg_ChoixDebugger[_Context->language],strlen(_Context->msg_ChoixDebugger[_Context->language]));
	visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+240,20,20,vfh[1],27,28,_Context->msg_ChoixDebugger[_Context->language],strlen(_Context->msg_ChoixDebugger[_Context->language]),0);
				break;
			case	0x8 :
				/* DebugRoot */
				_Context->keycode = visual_edit(_Context->x_Auto3547+30+1,_Context->y_Auto3547+290+1,456,16,vfh[1],_Context->buffer_DebugRoot,255);
			break;
			case	0x9 :
				/* ChoixDebugRoot */
				_Context->trigger_ChoixDebugRoot=visual_trigger_code(_Context->msg_ChoixDebugRoot[_Context->language],strlen(_Context->msg_ChoixDebugRoot[_Context->language]));
				visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+290,20,20,vfh[8],27,28,_Context->msg_ChoixDebugRoot[_Context->language],strlen(_Context->msg_ChoixDebugRoot[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_ChoixDebugRoot=visual_trigger_code(_Context->msg_ChoixDebugRoot[_Context->language],strlen(_Context->msg_ChoixDebugRoot[_Context->language]));
	visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+290,20,20,vfh[8],27,28,_Context->msg_ChoixDebugRoot[_Context->language],strlen(_Context->msg_ChoixDebugRoot[_Context->language]),0);
				break;
			case	0xa :
				/* Runtime */
				_Context->keycode = visual_edit(_Context->x_Auto3547+30+1,_Context->y_Auto3547+340+1,456,16,vfh[1],_Context->buffer_Runtime,255);
			break;
			case	0xb :
				/* ChoixRuntime */
				_Context->trigger_ChoixRuntime=visual_trigger_code(_Context->msg_ChoixRuntime[_Context->language],strlen(_Context->msg_ChoixRuntime[_Context->language]));
				visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+340,20,20,vfh[1],27,28,_Context->msg_ChoixRuntime[_Context->language],strlen(_Context->msg_ChoixRuntime[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_ChoixRuntime=visual_trigger_code(_Context->msg_ChoixRuntime[_Context->language],strlen(_Context->msg_ChoixRuntime[_Context->language]));
	visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+340,20,20,vfh[1],27,28,_Context->msg_ChoixRuntime[_Context->language],strlen(_Context->msg_ChoixRuntime[_Context->language]),0);
				break;
			case	0xc :
				/* Auto3557 */
				_Context->trigger_Auto3557=visual_trigger_code(_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]));
				visual_button(_Context->x_Auto3547+30,_Context->y_Auto3547+380,56,48,vfh[2],34,0,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3557=visual_trigger_code(_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]));
	visual_button(_Context->x_Auto3547+30,_Context->y_Auto3547+380,56,48,vfh[2],34,0,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),1040);
				break;
			case	0xd :
				/* Auto3558 */
				_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
				visual_button(_Context->x_Auto3547+440,_Context->y_Auto3547+380,56,48,vfh[2],34,0,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
	visual_button(_Context->x_Auto3547+440,_Context->y_Auto3547+380,56,48,vfh[2],34,0,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),1040);
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
			_Context->focus_item=13;
			accept_debug_parameters_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_debug_parameters_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (FileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (CommandLine_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Select_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (IsDebug_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Debugger_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (DebugRoot_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Runtime_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Auto3557_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (Auto3558_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3547 */
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
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
						visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+100,20,20,vfh[1],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+100,20,20,vfh[1],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
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
					/* ChoixDebugger */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixDebugger=visual_trigger_code(_Context->msg_ChoixDebugger[_Context->language],strlen(_Context->msg_ChoixDebugger[_Context->language]));
						visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+240,20,20,vfh[1],27,28,_Context->msg_ChoixDebugger[_Context->language],strlen(_Context->msg_ChoixDebugger[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixDebugger=visual_trigger_code(_Context->msg_ChoixDebugger[_Context->language],strlen(_Context->msg_ChoixDebugger[_Context->language]));
	visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+240,20,20,vfh[1],27,28,_Context->msg_ChoixDebugger[_Context->language],strlen(_Context->msg_ChoixDebugger[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixDebugger_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* DebugRoot */
					continue;
				case	0x9 :
					/* ChoixDebugRoot */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixDebugRoot=visual_trigger_code(_Context->msg_ChoixDebugRoot[_Context->language],strlen(_Context->msg_ChoixDebugRoot[_Context->language]));
						visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+290,20,20,vfh[8],27,28,_Context->msg_ChoixDebugRoot[_Context->language],strlen(_Context->msg_ChoixDebugRoot[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixDebugRoot=visual_trigger_code(_Context->msg_ChoixDebugRoot[_Context->language],strlen(_Context->msg_ChoixDebugRoot[_Context->language]));
	visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+290,20,20,vfh[8],27,28,_Context->msg_ChoixDebugRoot[_Context->language],strlen(_Context->msg_ChoixDebugRoot[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixDebugRoot_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Runtime */
					continue;
				case	0xb :
					/* ChoixRuntime */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixRuntime=visual_trigger_code(_Context->msg_ChoixRuntime[_Context->language],strlen(_Context->msg_ChoixRuntime[_Context->language]));
						visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+340,20,20,vfh[1],27,28,_Context->msg_ChoixRuntime[_Context->language],strlen(_Context->msg_ChoixRuntime[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixRuntime=visual_trigger_code(_Context->msg_ChoixRuntime[_Context->language],strlen(_Context->msg_ChoixRuntime[_Context->language]));
	visual_button(_Context->x_Auto3547+490,_Context->y_Auto3547+340,20,20,vfh[1],27,28,_Context->msg_ChoixRuntime[_Context->language],strlen(_Context->msg_ChoixRuntime[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixRuntime_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* Auto3557 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3557=visual_trigger_code(_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]));
						visual_button(_Context->x_Auto3547+30,_Context->y_Auto3547+380,56,48,vfh[2],34,0,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3557=visual_trigger_code(_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]));
	visual_button(_Context->x_Auto3547+30,_Context->y_Auto3547+380,56,48,vfh[2],34,0,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3557_event(_Context)) != -1) break;

						}
					continue;
				case	0xd :
					/* Auto3558 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
						visual_button(_Context->x_Auto3547+440,_Context->y_Auto3547+380,56,48,vfh[2],34,0,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
	visual_button(_Context->x_Auto3547+440,_Context->y_Auto3547+380,56,48,vfh[2],34,0,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3558_event(_Context)) != -1) break;

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
				_Context->focus_item=13;
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
