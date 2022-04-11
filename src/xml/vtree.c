
#ifndef _vtree_c
#define _vtree_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vtree.xml                                                */
/* Target         : vtree.c                                                  */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3595   ""
#define fr__Auto3595   ""
#define it__Auto3595   ""
#define es__Auto3595   ""
#define de__Auto3595   ""
#define nl__Auto3595   ""
#define pt__Auto3595   ""
#define xx__Auto3595   ""
#define en_Auto3596   "TreeView Parameters"
#define fr_Auto3596   "ParamŠtres de l'arborescence projet"
#define it_Auto3596   "TreeView Parameters"
#define es_Auto3596   "TreeView Parameters"
#define de_Auto3596   "TreeView Parameters"
#define nl_Auto3596   "TreeView Parameters"
#define pt_Auto3596   "TreeView Parameters"
#define xx_Auto3596   "TreeView Parameters"
#define en_Auto3597   "Tree View font"
#define fr_Auto3597   "Police"
#define it_Auto3597   "Tree View font"
#define es_Auto3597   "Tree View font"
#define de_Auto3597   "Tree View font"
#define nl_Auto3597   "Tree View font"
#define pt_Auto3597   "Tree View font"
#define xx_Auto3597   "Tree View font"
#define en_Auto3598   "Line Spacing"
#define fr_Auto3598   "Espacement"
#define it_Auto3598   "Line Spacing"
#define es_Auto3598   "Line Spacing"
#define de_Auto3598   "Line Spacing"
#define nl_Auto3598   "Line Spacing"
#define pt_Auto3598   "Line Spacing"
#define xx_Auto3598   "Line Spacing"
#define en_Auto3599   "Zone Style"
#define fr_Auto3599   "Style"
#define it_Auto3599   "Zone Style"
#define es_Auto3599   "Zone Style"
#define de_Auto3599   "Zone Style"
#define nl_Auto3599   "Zone Style"
#define pt_Auto3599   "Zone Style"
#define xx_Auto3599   "Zone Style"
#define en__TextFont   ""
#define en_LineSpacing   ""
#define en_ZoneType   "Zoned|Plain White"
#define fr_ZoneType   "Zon‚|Blanc"
#define it_ZoneType   "Zoned|Plain White"
#define es_ZoneType   "Zoned|Plain White"
#define de_ZoneType   "Zoned|Plain White"
#define nl_ZoneType   "Zoned|Plain White"
#define pt_ZoneType   "Zoned|Plain White"
#define xx_ZoneType   "Zoned|Plain White"
#define en__ZoneType   ""
#define fr__ZoneType   ""
#define it__ZoneType   ""
#define es__ZoneType   ""
#define de__ZoneType   ""
#define nl__ZoneType   ""
#define pt__ZoneType   ""
#define xx__ZoneType   ""
#define en_SourceName   "&Source"
#define fr_SourceName   "&Source"
#define it_SourceName   "&Source"
#define es_SourceName   "&Source"
#define de_SourceName   "&Source"
#define nl_SourceName   "&Source"
#define pt_SourceName   "&Source"
#define xx_SourceName   "&Source"
#define en_TargetName   "&Target"
#define fr_TargetName   "&Cible"
#define it_TargetName   "&Target"
#define es_TargetName   "&Target"
#define de_TargetName   "&Target"
#define nl_TargetName   "&Target"
#define pt_TargetName   "&Target"
#define xx_TargetName   "&Target"
#define en_Packaging   "&Packaging"
#define fr_Packaging   "&Empactage"
#define it_Packaging   "&Packaging"
#define es_Packaging   "&Packaging"
#define de_Packaging   "&Packaging"
#define nl_Packaging   "&Packaging"
#define pt_Packaging   "&Packaging"
#define xx_Packaging   "&Packaging"
#define en_Identity   "&Identity"
#define fr_Identity   "&Identit‚"
#define it_Identity   "&Identity"
#define es_Identity   "&Identity"
#define de_Identity   "&Identity"
#define nl_Identity   "&Identity"
#define pt_Identity   "&Identity"
#define xx_Identity   "&Identity"
#define en_Auto3600   "ok.gif"
#define fr_Auto3600   "ok.gif"
#define it_Auto3600   "ok.gif"
#define es_Auto3600   "ok.gif"
#define de_Auto3600   "ok.gif"
#define nl_Auto3600   "ok.gif"
#define pt_Auto3600   "ok.gif"
#define xx_Auto3600   "ok.gif"
#define en_Auto3601   "cancel.gif"
#define fr_Auto3601   "cancel.gif"
#define it_Auto3601   "cancel.gif"
#define es_Auto3601   "cancel.gif"
#define de_Auto3601   "cancel.gif"
#define nl_Auto3601   "cancel.gif"
#define pt_Auto3601   "cancel.gif"
#define xx_Auto3601   "cancel.gif"
#define en_Restore   "&Default"
#define fr_Restore   "&D‚faut"
#define it_Restore   "&Default"
#define es_Restore   "&Default"
#define de_Restore   "&Default"
#define nl_Restore   "&Default"
#define pt_Restore   "&Default"
#define xx_Restore   "&Default"

private struct accept_treeview_parameters_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3595[8];
	char * hint_Auto3595[8];
	int	x_Auto3595;
	int	y_Auto3595;
	int	w_Auto3595;
	int	h_Auto3595;
	char * msg_Auto3596[8];
	char * hint_Auto3596[8];
	char * msg_Auto3597[8];
	char * hint_Auto3597[8];
	char * msg_Auto3598[8];
	char * hint_Auto3598[8];
	char * msg_Auto3599[8];
	char * hint_Auto3599[8];
	char * msg_TextFont[8];
	char * hint_TextFont[8];
	int	value_TextFont;
	char * hint_LineSpacing[8];
	char	buffer_LineSpacing[6];
	char * msg_ZoneType[8];
	char * hint_ZoneType[8];
	int	value_ZoneType;
	char * msg_SourceName[8];
	int	trigger_SourceName;
	char * hint_SourceName[8];
	int	value_SourceName;
	char * msg_TargetName[8];
	int	trigger_TargetName;
	char * hint_TargetName[8];
	int	value_TargetName;
	char * msg_Packaging[8];
	int	trigger_Packaging;
	char * hint_Packaging[8];
	int	value_Packaging;
	char * msg_Identity[8];
	int	trigger_Identity;
	char * hint_Identity[8];
	int	value_Identity;
	char * msg_Auto3600[8];
	int	trigger_Auto3600;
	char * hint_Auto3600[8];
	char * msg_Auto3601[8];
	int	trigger_Auto3601;
	char * hint_Auto3601[8];
	char * msg_Restore[8];
	int	trigger_Restore;
	char * hint_Restore[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[8];
	};
static int	vfh[16];
private int on_Auto3600_event(struct accept_treeview_parameters_context * _Context);
private int on_Auto3601_event(struct accept_treeview_parameters_context * _Context);
private int on_Restore_event(struct accept_treeview_parameters_context * _Context);

public	int	accept_treeview_parameters_create(
	struct accept_treeview_parameters_context ** cptr,
	char * pTextFont,
	char * pLineSpacing,
	char * pZoneType,
	char * pSourceName,
	char * pTargetName,
	char * pPackaging,
	char * pIdentity)
{

	int i;
	struct accept_treeview_parameters_context * _Context=(struct accept_treeview_parameters_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_treeview_parameters_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=11;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pTextFont);
		if (!( pTextFont )) _Context->value_TextFont=0;
		else	_Context->value_TextFont = *((int *)pTextFont);
		visual_transferin(_Context->buffer_LineSpacing, 5, pLineSpacing);
		visual_transferin((void *) 0, 0, pZoneType);
		if (!( pZoneType )) _Context->value_ZoneType=0;
		else	_Context->value_ZoneType = *((int *)pZoneType);
		visual_transferin((void *) 0, 0, pSourceName);
		if (!( pSourceName )) _Context->value_SourceName=0;
		else	_Context->value_SourceName = *((int *)pSourceName);
		visual_transferin((void *) 0, 0, pTargetName);
		if (!( pTargetName )) _Context->value_TargetName=0;
		else	_Context->value_TargetName = *((int *)pTargetName);
		visual_transferin((void *) 0, 0, pPackaging);
		if (!( pPackaging )) _Context->value_Packaging=0;
		else	_Context->value_Packaging = *((int *)pPackaging);
		visual_transferin((void *) 0, 0, pIdentity);
		if (!( pIdentity )) _Context->value_Identity=0;
		else	_Context->value_Identity = *((int *)pIdentity);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3595[i]=" ";
	_Context->hint_Auto3595[0]=en__Auto3595;
	_Context->hint_Auto3595[1]=fr__Auto3595;
	_Context->hint_Auto3595[2]=it__Auto3595;
	_Context->hint_Auto3595[3]=es__Auto3595;
	_Context->hint_Auto3595[4]=de__Auto3595;
	_Context->hint_Auto3595[5]=nl__Auto3595;
	_Context->hint_Auto3595[6]=pt__Auto3595;
	_Context->hint_Auto3595[7]=xx__Auto3595;
	_Context->x_Auto3595=155;
	_Context->y_Auto3595=185;
	_Context->w_Auto3595=490;
	_Context->h_Auto3595=230;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3597[i]=" ";
	_Context->msg_Auto3597[0]=en_Auto3597;
	_Context->msg_Auto3597[1]=fr_Auto3597;
	_Context->msg_Auto3597[2]=it_Auto3597;
	_Context->msg_Auto3597[3]=es_Auto3597;
	_Context->msg_Auto3597[4]=de_Auto3597;
	_Context->msg_Auto3597[5]=nl_Auto3597;
	_Context->msg_Auto3597[6]=pt_Auto3597;
	_Context->msg_Auto3597[7]=xx_Auto3597;
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
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->hint_TextFont[0]=en__TextFont;
	for (i=0; i < 8; i++)_Context->msg_ZoneType[i]=" ";
	_Context->msg_ZoneType[0]=en_ZoneType;
	_Context->msg_ZoneType[1]=fr_ZoneType;
	_Context->msg_ZoneType[2]=it_ZoneType;
	_Context->msg_ZoneType[3]=es_ZoneType;
	_Context->msg_ZoneType[4]=de_ZoneType;
	_Context->msg_ZoneType[5]=nl_ZoneType;
	_Context->msg_ZoneType[6]=pt_ZoneType;
	_Context->msg_ZoneType[7]=xx_ZoneType;
	_Context->hint_ZoneType[0]=en__ZoneType;
	_Context->hint_ZoneType[1]=fr__ZoneType;
	_Context->hint_ZoneType[2]=it__ZoneType;
	_Context->hint_ZoneType[3]=es__ZoneType;
	_Context->hint_ZoneType[4]=de__ZoneType;
	_Context->hint_ZoneType[5]=nl__ZoneType;
	_Context->hint_ZoneType[6]=pt__ZoneType;
	_Context->hint_ZoneType[7]=xx__ZoneType;
	for (i=0; i < 8; i++)_Context->msg_SourceName[i]=" ";
	_Context->msg_SourceName[0]=en_SourceName;
	_Context->msg_SourceName[1]=fr_SourceName;
	_Context->msg_SourceName[2]=it_SourceName;
	_Context->msg_SourceName[3]=es_SourceName;
	_Context->msg_SourceName[4]=de_SourceName;
	_Context->msg_SourceName[5]=nl_SourceName;
	_Context->msg_SourceName[6]=pt_SourceName;
	_Context->msg_SourceName[7]=xx_SourceName;
	for (i=0; i < 8; i++)_Context->msg_TargetName[i]=" ";
	_Context->msg_TargetName[0]=en_TargetName;
	_Context->msg_TargetName[1]=fr_TargetName;
	_Context->msg_TargetName[2]=it_TargetName;
	_Context->msg_TargetName[3]=es_TargetName;
	_Context->msg_TargetName[4]=de_TargetName;
	_Context->msg_TargetName[5]=nl_TargetName;
	_Context->msg_TargetName[6]=pt_TargetName;
	_Context->msg_TargetName[7]=xx_TargetName;
	for (i=0; i < 8; i++)_Context->msg_Packaging[i]=" ";
	_Context->msg_Packaging[0]=en_Packaging;
	_Context->msg_Packaging[1]=fr_Packaging;
	_Context->msg_Packaging[2]=it_Packaging;
	_Context->msg_Packaging[3]=es_Packaging;
	_Context->msg_Packaging[4]=de_Packaging;
	_Context->msg_Packaging[5]=nl_Packaging;
	_Context->msg_Packaging[6]=pt_Packaging;
	_Context->msg_Packaging[7]=xx_Packaging;
	for (i=0; i < 8; i++)_Context->msg_Identity[i]=" ";
	_Context->msg_Identity[0]=en_Identity;
	_Context->msg_Identity[1]=fr_Identity;
	_Context->msg_Identity[2]=it_Identity;
	_Context->msg_Identity[3]=es_Identity;
	_Context->msg_Identity[4]=de_Identity;
	_Context->msg_Identity[5]=nl_Identity;
	_Context->msg_Identity[6]=pt_Identity;
	_Context->msg_Identity[7]=xx_Identity;
	for (i=0; i < 8; i++)_Context->msg_Auto3600[i]=" ";
	_Context->msg_Auto3600[0]=en_Auto3600;
	_Context->msg_Auto3600[1]=fr_Auto3600;
	_Context->msg_Auto3600[2]=it_Auto3600;
	_Context->msg_Auto3600[3]=es_Auto3600;
	_Context->msg_Auto3600[4]=de_Auto3600;
	_Context->msg_Auto3600[5]=nl_Auto3600;
	_Context->msg_Auto3600[6]=pt_Auto3600;
	_Context->msg_Auto3600[7]=xx_Auto3600;
	for (i=0; i < 8; i++)_Context->msg_Auto3601[i]=" ";
	_Context->msg_Auto3601[0]=en_Auto3601;
	_Context->msg_Auto3601[1]=fr_Auto3601;
	_Context->msg_Auto3601[2]=it_Auto3601;
	_Context->msg_Auto3601[3]=es_Auto3601;
	_Context->msg_Auto3601[4]=de_Auto3601;
	_Context->msg_Auto3601[5]=nl_Auto3601;
	_Context->msg_Auto3601[6]=pt_Auto3601;
	_Context->msg_Auto3601[7]=xx_Auto3601;
	for (i=0; i < 8; i++)_Context->msg_Restore[i]=" ";
	_Context->msg_Restore[0]=en_Restore;
	_Context->msg_Restore[1]=fr_Restore;
	_Context->msg_Restore[2]=it_Restore;
	_Context->msg_Restore[3]=es_Restore;
	_Context->msg_Restore[4]=de_Restore;
	_Context->msg_Restore[5]=nl_Restore;
	_Context->msg_Restore[6]=pt_Restore;
	_Context->msg_Restore[7]=xx_Restore;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3595,_Context->y_Auto3595,490+10,230+10);
	return(0);
}

public 	int	accept_treeview_parameters_hide(struct accept_treeview_parameters_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3595,_Context->y_Auto3595);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_treeview_parameters_remove(
	struct accept_treeview_parameters_context * _Context,
	char * pTextFont,
	char * pLineSpacing,
	char * pZoneType,
	char * pSourceName,
	char * pTargetName,
	char * pPackaging,
	char * pIdentity)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pTextFont);
		if ( pTextFont != (char *) 0)
			*((int*)pTextFont) = _Context->value_TextFont;
		visual_transferout(_Context->buffer_LineSpacing, 5, pLineSpacing);
		visual_transferout((void *) 0, 0, pZoneType);
		if ( pZoneType != (char *) 0)
			*((int*)pZoneType) = _Context->value_ZoneType;
		visual_transferout((void *) 0, 0, pSourceName);
		if ( pSourceName != (char *) 0)
			*((int*)pSourceName) = _Context->value_SourceName;
		visual_transferout((void *) 0, 0, pTargetName);
		if ( pTargetName != (char *) 0)
			*((int*)pTargetName) = _Context->value_TargetName;
		visual_transferout((void *) 0, 0, pPackaging);
		if ( pPackaging != (char *) 0)
			*((int*)pPackaging) = _Context->value_Packaging;
		visual_transferout((void *) 0, 0, pIdentity);
		if ( pIdentity != (char *) 0)
			*((int*)pIdentity) = _Context->value_Identity;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_treeview_parameters_show(struct accept_treeview_parameters_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3595,_Context->y_Auto3595);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3595,_Context->y_Auto3595,490,230,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3595,_Context->y_Auto3595,490,230,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3595+10,_Context->y_Auto3595+30,470,20,vfh[3],16,0,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),1282);
	visual_frame(_Context->x_Auto3595+10,_Context->y_Auto3595+50,470,110,4);
	visual_text(_Context->x_Auto3595+20,_Context->y_Auto3595+70,98,16,vfh[2],16,0,_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]),1282);
	visual_text(_Context->x_Auto3595+20,_Context->y_Auto3595+130,98,16,vfh[2],16,0,_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]),1282);
	visual_text(_Context->x_Auto3595+260,_Context->y_Auto3595+70,84,16,vfh[2],16,0,_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]),1282);
	visual_select(_Context->x_Auto3595+120,_Context->y_Auto3595+70,112,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),768);
	visual_frame(_Context->x_Auto3595+120,_Context->y_Auto3595+130,40+2,16+2,5);
	visual_text(_Context->x_Auto3595+120+1,_Context->y_Auto3595+130+1,40,16,vfh[1],16,0,_Context->buffer_LineSpacing,5,0);
	visual_select(_Context->x_Auto3595+350,_Context->y_Auto3595+70,120,48,vfh[2],16,0,parse_selection(_Context->msg_ZoneType[_Context->language],&_Context->value_ZoneType),768);
	_Context->trigger_SourceName=visual_trigger_code(_Context->msg_SourceName[_Context->language],strlen(_Context->msg_SourceName[_Context->language]));
	visual_check(_Context->x_Auto3595+240,_Context->y_Auto3595+100,98,16,vfh[2],16,0,_Context->msg_SourceName[_Context->language],strlen(_Context->msg_SourceName[_Context->language]),_Context->value_SourceName|0);
	_Context->trigger_TargetName=visual_trigger_code(_Context->msg_TargetName[_Context->language],strlen(_Context->msg_TargetName[_Context->language]));
	visual_check(_Context->x_Auto3595+350,_Context->y_Auto3595+100,112,16,vfh[2],16,0,_Context->msg_TargetName[_Context->language],strlen(_Context->msg_TargetName[_Context->language]),_Context->value_TargetName|0);
	_Context->trigger_Packaging=visual_trigger_code(_Context->msg_Packaging[_Context->language],strlen(_Context->msg_Packaging[_Context->language]));
	visual_check(_Context->x_Auto3595+240,_Context->y_Auto3595+130,112,16,vfh[2],16,0,_Context->msg_Packaging[_Context->language],strlen(_Context->msg_Packaging[_Context->language]),_Context->value_Packaging|0);
	_Context->trigger_Identity=visual_trigger_code(_Context->msg_Identity[_Context->language],strlen(_Context->msg_Identity[_Context->language]));
	visual_check(_Context->x_Auto3595+350,_Context->y_Auto3595+130,98,16,vfh[2],16,0,_Context->msg_Identity[_Context->language],strlen(_Context->msg_Identity[_Context->language]),_Context->value_Identity|0);
	_Context->trigger_Auto3600=visual_trigger_code(_Context->msg_Auto3600[_Context->language],strlen(_Context->msg_Auto3600[_Context->language]));
	visual_button(_Context->x_Auto3595+10,_Context->y_Auto3595+170,56,48,vfh[2],34,0,_Context->msg_Auto3600[_Context->language],strlen(_Context->msg_Auto3600[_Context->language]),1040);
	_Context->trigger_Auto3601=visual_trigger_code(_Context->msg_Auto3601[_Context->language],strlen(_Context->msg_Auto3601[_Context->language]));
	visual_button(_Context->x_Auto3595+420,_Context->y_Auto3595+170,56,48,vfh[2],34,0,_Context->msg_Auto3601[_Context->language],strlen(_Context->msg_Auto3601[_Context->language]),1040);
	_Context->trigger_Restore=visual_trigger_code(_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]));
	visual_button(_Context->x_Auto3595+200,_Context->y_Auto3595+180,98,32,vfh[2],34,0,_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]),0);
	visual_thaw(_Context->x_Auto3595,_Context->y_Auto3595,490,230);

	return(0);
}

private int TextFont_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of the font to be used for the display ";
			mptr[1]="of  information in the tree view window.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int LineSpacing_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the inter line spacing of the treeview window ";
			mptr[1]="to be inspected and modified.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ZoneType_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of the style to be used for the display ";
			mptr[1]="of information int hte tree view window.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SourceName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this control is activated then the xml ressource, image name ";
			mptr[1]="or text source file  name of project items will be displayed in the ";
			mptr[2]="tree view window.   ";
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
			char * mptr[2];
			mptr[0] = "When this control is activated then the production target filenames ";
			mptr[1]="of progject  items will be displayed in the tree view window.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Packaging_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this control is activated then the production packaging type ";
			mptr[1]="of forms model components will be displayed in the tree view window. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Identity_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "When this control is activated then the forms model identity will ";
			mptr[1]="be displayed in the treeview window.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3600_help()
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

private int Auto3601_help()
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

private int Restore_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The default treeview display parameters may be restored by pressing ";
			mptr[1]="on this button.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3595action(struct accept_treeview_parameters_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_treeview_parameters_hide(_Context);

		_Context->x_Auto3595 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3595 < 0) { _Context->x_Auto3595=0; }
		_Context->y_Auto3595 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3595 < 0) { _Context->y_Auto3595=0; }
			accept_treeview_parameters_show(_Context);

		visual_thaw(_Context->x_Auto3595,_Context->y_Auto3595,490,230);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3600_event(struct accept_treeview_parameters_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3601_event(struct accept_treeview_parameters_context * _Context) {
	return(27);
	return(-1);
}
private int on_Restore_event(struct accept_treeview_parameters_context * _Context) {
	_Context->value_TextFont=1;
	strcpy(_Context->buffer_LineSpacing,"0");
	_Context->value_ZoneType=1;
	_Context->value_SourceName=1;
	_Context->value_TargetName=1;
	_Context->value_Packaging=1;
		return(-1);
}


public	int	accept_treeview_parameters_event(
struct accept_treeview_parameters_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_SourceName == mb ) return(5);
		if (_Context->trigger_TargetName == mb ) return(6);
		if (_Context->trigger_Packaging == mb ) return(7);
		if (_Context->trigger_Identity == mb ) return(8);
		if (_Context->trigger_Auto3600 == mb ) return(9);
		if (_Context->trigger_Auto3601 == mb ) return(10);
		if (_Context->trigger_Restore == mb ) return(11);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3595+469) )  
	&&  (my >= (_Context->y_Auto3595+4) )  
	&&  (mx <= (_Context->x_Auto3595+486) )  
	&&  (my <= (_Context->y_Auto3595+20) )) {
		return(1);	/* Auto3595 */

		}
	if ((mx >= (_Context->x_Auto3595+453) )  
	&&  (my >= (_Context->y_Auto3595+4) )  
	&&  (mx <= (_Context->x_Auto3595+470) )  
	&&  (my <= (_Context->y_Auto3595+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vtree.htm");
			};
		return(-1);	/* Auto3595 */

		}
	if ((mx >= (_Context->x_Auto3595+437) )  
	&&  (my >= (_Context->y_Auto3595+4) )  
	&&  (mx <= (_Context->x_Auto3595+454) )  
	&&  (my <= (_Context->y_Auto3595+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_treeview_parameters_show(_Context);
		return(-1);	/* Auto3595 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3595+4) )  
		&&  (my >= (_Context->y_Auto3595+4) )  
		&&  (mx <= (_Context->x_Auto3595+422) )  
		&&  (my <= (_Context->y_Auto3595+20) )) {
			return( Auto3595action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3595+120+0) ) 
	&&  ( my >= (_Context->y_Auto3595+70) ) 
	&&  ( mx <= (_Context->x_Auto3595+120+112) ) 
	&&  ( my <= (_Context->y_Auto3595+70+16))) {
		return(2); /* TextFont */
		}
	if (( mx >= (_Context->x_Auto3595+120) ) 
	&&  ( my >= (_Context->y_Auto3595+130) ) 
	&&  ( mx <= (_Context->x_Auto3595+120+40) ) 
	&&  ( my <= (_Context->y_Auto3595+130+16))) {
		return(3); /* LineSpacing */
		}
	if (( mx >= (_Context->x_Auto3595+350+0) ) 
	&&  ( my >= (_Context->y_Auto3595+70) ) 
	&&  ( mx <= (_Context->x_Auto3595+350+120) ) 
	&&  ( my <= (_Context->y_Auto3595+70+16))) {
		return(4); /* ZoneType */
		}
	if (( mx >= (_Context->x_Auto3595+240) ) 
	&&  ( my >= (_Context->y_Auto3595+100) ) 
	&&  ( mx <= (_Context->x_Auto3595+240+98) ) 
	&&  ( my <= (_Context->y_Auto3595+100+16))) {
		return(5); /* SourceName */
		}
	if (( mx >= (_Context->x_Auto3595+350) ) 
	&&  ( my >= (_Context->y_Auto3595+100) ) 
	&&  ( mx <= (_Context->x_Auto3595+350+112) ) 
	&&  ( my <= (_Context->y_Auto3595+100+16))) {
		return(6); /* TargetName */
		}
	if (( mx >= (_Context->x_Auto3595+240) ) 
	&&  ( my >= (_Context->y_Auto3595+130) ) 
	&&  ( mx <= (_Context->x_Auto3595+240+112) ) 
	&&  ( my <= (_Context->y_Auto3595+130+16))) {
		return(7); /* Packaging */
		}
	if (( mx >= (_Context->x_Auto3595+350) ) 
	&&  ( my >= (_Context->y_Auto3595+130) ) 
	&&  ( mx <= (_Context->x_Auto3595+350+98) ) 
	&&  ( my <= (_Context->y_Auto3595+130+16))) {
		return(8); /* Identity */
		}
	if (( mx >= (_Context->x_Auto3595+10) ) 
	&&  ( my >= (_Context->y_Auto3595+170) ) 
	&&  ( mx <= (_Context->x_Auto3595+10+56) ) 
	&&  ( my <= (_Context->y_Auto3595+170+48))) {
		return(9); /* Auto3600 */
		}
	if (( mx >= (_Context->x_Auto3595+420) ) 
	&&  ( my >= (_Context->y_Auto3595+170) ) 
	&&  ( mx <= (_Context->x_Auto3595+420+56) ) 
	&&  ( my <= (_Context->y_Auto3595+170+48))) {
		return(10); /* Auto3601 */
		}
	if (( mx >= (_Context->x_Auto3595+200) ) 
	&&  ( my >= (_Context->y_Auto3595+180) ) 
	&&  ( mx <= (_Context->x_Auto3595+200+98) ) 
	&&  ( my <= (_Context->y_Auto3595+180+32))) {
		return(11); /* Restore */
		}

	return(-1);
}


public	int	accept_treeview_parameters_focus(struct accept_treeview_parameters_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_Auto3595+120,_Context->y_Auto3595+70,112,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),770);
				break;
			case	0x3 :
				/* LineSpacing */
				_Context->keycode = visual_edit(_Context->x_Auto3595+120+1,_Context->y_Auto3595+130+1,40,16,vfh[1],_Context->buffer_LineSpacing,5);
			break;
			case	0x4 :
				/* ZoneType */
				_Context->keycode = visual_select(_Context->x_Auto3595+350,_Context->y_Auto3595+70,120,48,vfh[2],16,0,parse_selection(_Context->msg_ZoneType[_Context->language],&_Context->value_ZoneType),770);
				break;
			case	0x5 :
				/* SourceName */
				visual_check(_Context->x_Auto3595+240,_Context->y_Auto3595+100,98,16,vfh[2],16,0,_Context->msg_SourceName[_Context->language],strlen(_Context->msg_SourceName[_Context->language]),(_Context->value_SourceName |2));
				_Context->keycode = visual_getch();
				_Context->trigger_SourceName=visual_trigger_code(_Context->msg_SourceName[_Context->language],strlen(_Context->msg_SourceName[_Context->language]));
	visual_check(_Context->x_Auto3595+240,_Context->y_Auto3595+100,98,16,vfh[2],16,0,_Context->msg_SourceName[_Context->language],strlen(_Context->msg_SourceName[_Context->language]),_Context->value_SourceName|0);
				break;
			case	0x6 :
				/* TargetName */
				visual_check(_Context->x_Auto3595+350,_Context->y_Auto3595+100,112,16,vfh[2],16,0,_Context->msg_TargetName[_Context->language],strlen(_Context->msg_TargetName[_Context->language]),(_Context->value_TargetName |2));
				_Context->keycode = visual_getch();
				_Context->trigger_TargetName=visual_trigger_code(_Context->msg_TargetName[_Context->language],strlen(_Context->msg_TargetName[_Context->language]));
	visual_check(_Context->x_Auto3595+350,_Context->y_Auto3595+100,112,16,vfh[2],16,0,_Context->msg_TargetName[_Context->language],strlen(_Context->msg_TargetName[_Context->language]),_Context->value_TargetName|0);
				break;
			case	0x7 :
				/* Packaging */
				visual_check(_Context->x_Auto3595+240,_Context->y_Auto3595+130,112,16,vfh[2],16,0,_Context->msg_Packaging[_Context->language],strlen(_Context->msg_Packaging[_Context->language]),(_Context->value_Packaging |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Packaging=visual_trigger_code(_Context->msg_Packaging[_Context->language],strlen(_Context->msg_Packaging[_Context->language]));
	visual_check(_Context->x_Auto3595+240,_Context->y_Auto3595+130,112,16,vfh[2],16,0,_Context->msg_Packaging[_Context->language],strlen(_Context->msg_Packaging[_Context->language]),_Context->value_Packaging|0);
				break;
			case	0x8 :
				/* Identity */
				visual_check(_Context->x_Auto3595+350,_Context->y_Auto3595+130,98,16,vfh[2],16,0,_Context->msg_Identity[_Context->language],strlen(_Context->msg_Identity[_Context->language]),(_Context->value_Identity |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Identity=visual_trigger_code(_Context->msg_Identity[_Context->language],strlen(_Context->msg_Identity[_Context->language]));
	visual_check(_Context->x_Auto3595+350,_Context->y_Auto3595+130,98,16,vfh[2],16,0,_Context->msg_Identity[_Context->language],strlen(_Context->msg_Identity[_Context->language]),_Context->value_Identity|0);
				break;
			case	0x9 :
				/* Auto3600 */
				_Context->trigger_Auto3600=visual_trigger_code(_Context->msg_Auto3600[_Context->language],strlen(_Context->msg_Auto3600[_Context->language]));
				visual_button(_Context->x_Auto3595+10,_Context->y_Auto3595+170,56,48,vfh[2],34,0,_Context->msg_Auto3600[_Context->language],strlen(_Context->msg_Auto3600[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3600=visual_trigger_code(_Context->msg_Auto3600[_Context->language],strlen(_Context->msg_Auto3600[_Context->language]));
	visual_button(_Context->x_Auto3595+10,_Context->y_Auto3595+170,56,48,vfh[2],34,0,_Context->msg_Auto3600[_Context->language],strlen(_Context->msg_Auto3600[_Context->language]),1040);
				break;
			case	0xa :
				/* Auto3601 */
				_Context->trigger_Auto3601=visual_trigger_code(_Context->msg_Auto3601[_Context->language],strlen(_Context->msg_Auto3601[_Context->language]));
				visual_button(_Context->x_Auto3595+420,_Context->y_Auto3595+170,56,48,vfh[2],34,0,_Context->msg_Auto3601[_Context->language],strlen(_Context->msg_Auto3601[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3601=visual_trigger_code(_Context->msg_Auto3601[_Context->language],strlen(_Context->msg_Auto3601[_Context->language]));
	visual_button(_Context->x_Auto3595+420,_Context->y_Auto3595+170,56,48,vfh[2],34,0,_Context->msg_Auto3601[_Context->language],strlen(_Context->msg_Auto3601[_Context->language]),1040);
				break;
			case	0xb :
				/* Restore */
				_Context->trigger_Restore=visual_trigger_code(_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]));
				visual_button(_Context->x_Auto3595+200,_Context->y_Auto3595+180,98,32,vfh[2],34,0,_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Restore=visual_trigger_code(_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]));
	visual_button(_Context->x_Auto3595+200,_Context->y_Auto3595+180,98,32,vfh[2],34,0,_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_treeview_parameters_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=11;
			accept_treeview_parameters_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_treeview_parameters_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (TextFont_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (LineSpacing_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (ZoneType_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (SourceName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (TargetName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (Packaging_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (Identity_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (Auto3600_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Auto3601_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Restore_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3595 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* TextFont */
					continue;
				case	0x3 :
					/* LineSpacing */
					continue;
				case	0x4 :
					/* ZoneType */
					continue;
				case	0x5 :
					/* SourceName */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SourceName += 1;
						_Context->value_SourceName &= 1;
						}
					continue;
				case	0x6 :
					/* TargetName */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_TargetName += 1;
						_Context->value_TargetName &= 1;
						}
					continue;
				case	0x7 :
					/* Packaging */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Packaging += 1;
						_Context->value_Packaging &= 1;
						}
					continue;
				case	0x8 :
					/* Identity */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Identity += 1;
						_Context->value_Identity &= 1;
						}
					continue;
				case	0x9 :
					/* Auto3600 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3600=visual_trigger_code(_Context->msg_Auto3600[_Context->language],strlen(_Context->msg_Auto3600[_Context->language]));
						visual_button(_Context->x_Auto3595+10,_Context->y_Auto3595+170,56,48,vfh[2],34,0,_Context->msg_Auto3600[_Context->language],strlen(_Context->msg_Auto3600[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3600=visual_trigger_code(_Context->msg_Auto3600[_Context->language],strlen(_Context->msg_Auto3600[_Context->language]));
	visual_button(_Context->x_Auto3595+10,_Context->y_Auto3595+170,56,48,vfh[2],34,0,_Context->msg_Auto3600[_Context->language],strlen(_Context->msg_Auto3600[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3600_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto3601 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3601=visual_trigger_code(_Context->msg_Auto3601[_Context->language],strlen(_Context->msg_Auto3601[_Context->language]));
						visual_button(_Context->x_Auto3595+420,_Context->y_Auto3595+170,56,48,vfh[2],34,0,_Context->msg_Auto3601[_Context->language],strlen(_Context->msg_Auto3601[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3601=visual_trigger_code(_Context->msg_Auto3601[_Context->language],strlen(_Context->msg_Auto3601[_Context->language]));
	visual_button(_Context->x_Auto3595+420,_Context->y_Auto3595+170,56,48,vfh[2],34,0,_Context->msg_Auto3601[_Context->language],strlen(_Context->msg_Auto3601[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3601_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Restore */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Restore=visual_trigger_code(_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]));
						visual_button(_Context->x_Auto3595+200,_Context->y_Auto3595+180,98,32,vfh[2],34,0,_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Restore=visual_trigger_code(_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]));
	visual_button(_Context->x_Auto3595+200,_Context->y_Auto3595+180,98,32,vfh[2],34,0,_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Restore_event(_Context)) != -1) break;

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

public	int	accept_treeview_parameters(
	char * pTextFont,
	char * pLineSpacing,
	char * pZoneType,
	char * pSourceName,
	char * pTargetName,
	char * pPackaging,
	char * pIdentity)
{
	int	status=0;
	struct accept_treeview_parameters_context * _Context=(struct accept_treeview_parameters_context*) 0;
	status = accept_treeview_parameters_create(
	&_Context,
	 pTextFont,
	 pLineSpacing,
	 pZoneType,
	 pSourceName,
	 pTargetName,
	 pPackaging,
	 pIdentity);
	if ( status != 0) return(status);
	status = accept_treeview_parameters_show(_Context);
		enter_modal();
	status = accept_treeview_parameters_focus(_Context);
		leave_modal();
	status = accept_treeview_parameters_hide(_Context);
	status = accept_treeview_parameters_remove(
	_Context,
	 pTextFont,
	 pLineSpacing,
	 pZoneType,
	 pSourceName,
	 pTargetName,
	 pPackaging,
	 pIdentity);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vtree_c */
