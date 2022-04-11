
#ifndef _vtree_c
#define _vtree_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vtree.xml  */
/* Target         : vtree.c  */
/* Identification : 0.0-1100085493-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto1896   "Sing : Version 1.0a"
#define fr_Auto1896   "Sing : Version 1.0a"
#define it_Auto1896   "Sing : Version 1.0a"
#define es_Auto1896   "Sing : Version 1.0a"
#define de_Auto1896   "Sing : Version 1.0a"
#define nl_Auto1896   "Sing : Version 1.0a"
#define pt_Auto1896   "Sing : Version 1.0a"
#define xx_Auto1896   "Sing : Version 1.0a"
#define en_Auto1897   "TreeView Parameters"
#define fr_Auto1897   "ParamŠtres d'Arborescence"
#define it_Auto1897   "TreeView Parameters"
#define es_Auto1897   "TreeView Parameters"
#define de_Auto1897   "TreeView Parameters"
#define nl_Auto1897   "TreeView Parameters"
#define pt_Auto1897   "TreeView Parameters"
#define xx_Auto1897   "TreeView Parameters"
#define en_Auto1898   "Tree View font"
#define fr_Auto1898   "Fonte"
#define it_Auto1898   "Tree View font"
#define es_Auto1898   "Tree View font"
#define de_Auto1898   "Tree View font"
#define nl_Auto1898   "Tree View font"
#define pt_Auto1898   "Tree View font"
#define xx_Auto1898   "Tree View font"
#define en_Auto1901   "Line Spacing"
#define fr_Auto1901   "Espacement"
#define it_Auto1901   "Line Spacing"
#define es_Auto1901   "Line Spacing"
#define de_Auto1901   "Line Spacing"
#define nl_Auto1901   "Line Spacing"
#define pt_Auto1901   "Line Spacing"
#define xx_Auto1901   "Line Spacing"
#define en_Auto1903   "Zone Style"
#define fr_Auto1903   "Style de Zone"
#define it_Auto1903   "Zone Style"
#define es_Auto1903   "Zone Style"
#define de_Auto1903   "Zone Style"
#define nl_Auto1903   "Zone Style"
#define pt_Auto1903   "Zone Style"
#define xx_Auto1903   "Zone Style"
#define en_LineSpacing   ""
#define en_ZoneType   "Zoned|Plain White"
#define fr_ZoneType   "Zoned|Plain"
#define it_ZoneType   "Zoned|Plain"
#define es_ZoneType   "Zoned|Plain"
#define de_ZoneType   "Zoned|Plain"
#define nl_ZoneType   "Zoned|Plain"
#define pt_ZoneType   "Zoned|Plain"
#define xx_ZoneType   "Zoned|Plain"
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
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define it_Accept   "&Accept"
#define es_Accept   "&Accept"
#define de_Accept   "&Accept"
#define nl_Accept   "&Accept"
#define pt_Accept   "&Accept"
#define xx_Accept   "&Accept"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "V&alider"
#define it_Cancel   "&Cancel"
#define es_Cancel   "&Cancel"
#define de_Cancel   "&Cancel"
#define nl_Cancel   "&Cancel"
#define pt_Cancel   "&Cancel"
#define xx_Cancel   "&Cancel"
#define en_Restore   "&Default"
#define fr_Restore   "&Defaut"
#define it_Restore   "&Default"
#define es_Restore   "&Default"
#define de_Restore   "&Default"
#define nl_Restore   "&Default"
#define pt_Restore   "&Default"
#define xx_Restore   "&Default"
static int	vfh[10];

private struct accept_treeview_parameters_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto1896[8];
	int	x_Auto1896;
	int	y_Auto1896;
	int	w_Auto1896;
	int	h_Auto1896;
	char * msg_Auto1897[8];
	char * msg_Auto1898[8];
	char * msg_Auto1901[8];
	char * msg_Auto1903[8];
	char * msg_TextFont[8];
	int	value_TextFont;
	char	buffer_LineSpacing[6];
	char * msg_ZoneType[8];
	int	value_ZoneType;
	char * msg_SourceName[8];
	int	trigger_SourceName;
	int	value_SourceName;
	char * msg_TargetName[8];
	int	trigger_TargetName;
	int	value_TargetName;
	char * msg_Packaging[8];
	int	trigger_Packaging;
	int	value_Packaging;
	char * msg_Identity[8];
	int	trigger_Identity;
	int	value_Identity;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_Restore[8];
	int	trigger_Restore;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[8];
	};

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
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
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
	for (i=0; i < 8; i++)_Context->msg_Auto1896[i]=" ";
	_Context->msg_Auto1896[0]=en_Auto1896;
	_Context->msg_Auto1896[1]=fr_Auto1896;
	_Context->msg_Auto1896[2]=it_Auto1896;
	_Context->msg_Auto1896[3]=es_Auto1896;
	_Context->msg_Auto1896[4]=de_Auto1896;
	_Context->msg_Auto1896[5]=nl_Auto1896;
	_Context->msg_Auto1896[6]=pt_Auto1896;
	_Context->msg_Auto1896[7]=xx_Auto1896;
	_Context->x_Auto1896=155;
	_Context->y_Auto1896=190;
	_Context->w_Auto1896=490;
	_Context->h_Auto1896=220;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1897[i]=" ";
	_Context->msg_Auto1897[0]=en_Auto1897;
	_Context->msg_Auto1897[1]=fr_Auto1897;
	_Context->msg_Auto1897[2]=it_Auto1897;
	_Context->msg_Auto1897[3]=es_Auto1897;
	_Context->msg_Auto1897[4]=de_Auto1897;
	_Context->msg_Auto1897[5]=nl_Auto1897;
	_Context->msg_Auto1897[6]=pt_Auto1897;
	_Context->msg_Auto1897[7]=xx_Auto1897;
	for (i=0; i < 8; i++)_Context->msg_Auto1898[i]=" ";
	_Context->msg_Auto1898[0]=en_Auto1898;
	_Context->msg_Auto1898[1]=fr_Auto1898;
	_Context->msg_Auto1898[2]=it_Auto1898;
	_Context->msg_Auto1898[3]=es_Auto1898;
	_Context->msg_Auto1898[4]=de_Auto1898;
	_Context->msg_Auto1898[5]=nl_Auto1898;
	_Context->msg_Auto1898[6]=pt_Auto1898;
	_Context->msg_Auto1898[7]=xx_Auto1898;
	for (i=0; i < 8; i++)_Context->msg_Auto1901[i]=" ";
	_Context->msg_Auto1901[0]=en_Auto1901;
	_Context->msg_Auto1901[1]=fr_Auto1901;
	_Context->msg_Auto1901[2]=it_Auto1901;
	_Context->msg_Auto1901[3]=es_Auto1901;
	_Context->msg_Auto1901[4]=de_Auto1901;
	_Context->msg_Auto1901[5]=nl_Auto1901;
	_Context->msg_Auto1901[6]=pt_Auto1901;
	_Context->msg_Auto1901[7]=xx_Auto1901;
	for (i=0; i < 8; i++)_Context->msg_Auto1903[i]=" ";
	_Context->msg_Auto1903[0]=en_Auto1903;
	_Context->msg_Auto1903[1]=fr_Auto1903;
	_Context->msg_Auto1903[2]=it_Auto1903;
	_Context->msg_Auto1903[3]=es_Auto1903;
	_Context->msg_Auto1903[4]=de_Auto1903;
	_Context->msg_Auto1903[5]=nl_Auto1903;
	_Context->msg_Auto1903[6]=pt_Auto1903;
	_Context->msg_Auto1903[7]=xx_Auto1903;
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_ZoneType[i]=" ";
	_Context->msg_ZoneType[0]=en_ZoneType;
	_Context->msg_ZoneType[1]=fr_ZoneType;
	_Context->msg_ZoneType[2]=it_ZoneType;
	_Context->msg_ZoneType[3]=es_ZoneType;
	_Context->msg_ZoneType[4]=de_ZoneType;
	_Context->msg_ZoneType[5]=nl_ZoneType;
	_Context->msg_ZoneType[6]=pt_ZoneType;
	_Context->msg_ZoneType[7]=xx_ZoneType;
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
	_Context->pushbuffer=visual_buffer(_Context->x_Auto1896,_Context->y_Auto1896,490+10,220+10);
	return(0);
}

public 	int	accept_treeview_parameters_hide(struct accept_treeview_parameters_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto1896,_Context->y_Auto1896);
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
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto1896,_Context->y_Auto1896);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto1896,_Context->y_Auto1896,490,220,vfh[2],_Context->msg_Auto1896[_Context->language],strlen(_Context->msg_Auto1896[_Context->language]),0x407);
	visual_text(_Context->x_Auto1896+10,_Context->y_Auto1896+30,470,20,vfh[3],16,0,_Context->msg_Auto1897[_Context->language],strlen(_Context->msg_Auto1897[_Context->language]),1282);
	visual_frame(_Context->x_Auto1896+10,_Context->y_Auto1896+50,470,110,4);
	visual_text(_Context->x_Auto1896+20,_Context->y_Auto1896+70,98,16,vfh[2],16,0,_Context->msg_Auto1898[_Context->language],strlen(_Context->msg_Auto1898[_Context->language]),1282);
	visual_text(_Context->x_Auto1896+20,_Context->y_Auto1896+130,98,16,vfh[2],16,0,_Context->msg_Auto1901[_Context->language],strlen(_Context->msg_Auto1901[_Context->language]),1282);
	visual_text(_Context->x_Auto1896+260,_Context->y_Auto1896+70,84,16,vfh[2],16,0,_Context->msg_Auto1903[_Context->language],strlen(_Context->msg_Auto1903[_Context->language]),1282);
	visual_select(_Context->x_Auto1896+120,_Context->y_Auto1896+70,112,96,vfh[1],34,0,parse_selection(TextFontList,&_Context->value_TextFont),0);
	visual_frame(_Context->x_Auto1896+120,_Context->y_Auto1896+130,40+2,16+2,5);
	visual_text(_Context->x_Auto1896+120+1,_Context->y_Auto1896+130+1,40,16,vfh[1],16,0,_Context->buffer_LineSpacing,5,0);
	visual_select(_Context->x_Auto1896+350,_Context->y_Auto1896+70,120,48,vfh[1],16,0,parse_selection(_Context->msg_ZoneType[_Context->language],&_Context->value_ZoneType),0);
	_Context->trigger_SourceName=visual_trigger_code(_Context->msg_SourceName[_Context->language],strlen(_Context->msg_SourceName[_Context->language]));
	visual_check(_Context->x_Auto1896+240,_Context->y_Auto1896+100,98,16,vfh[2],16,0,_Context->msg_SourceName[_Context->language],strlen(_Context->msg_SourceName[_Context->language]),_Context->value_SourceName|0);
	_Context->trigger_TargetName=visual_trigger_code(_Context->msg_TargetName[_Context->language],strlen(_Context->msg_TargetName[_Context->language]));
	visual_check(_Context->x_Auto1896+350,_Context->y_Auto1896+100,112,16,vfh[2],16,0,_Context->msg_TargetName[_Context->language],strlen(_Context->msg_TargetName[_Context->language]),_Context->value_TargetName|0);
	_Context->trigger_Packaging=visual_trigger_code(_Context->msg_Packaging[_Context->language],strlen(_Context->msg_Packaging[_Context->language]));
	visual_check(_Context->x_Auto1896+240,_Context->y_Auto1896+130,112,16,vfh[2],16,0,_Context->msg_Packaging[_Context->language],strlen(_Context->msg_Packaging[_Context->language]),_Context->value_Packaging|0);
	_Context->trigger_Identity=visual_trigger_code(_Context->msg_Identity[_Context->language],strlen(_Context->msg_Identity[_Context->language]));
	visual_check(_Context->x_Auto1896+350,_Context->y_Auto1896+130,98,16,vfh[2],16,0,_Context->msg_Identity[_Context->language],strlen(_Context->msg_Identity[_Context->language]),_Context->value_Identity|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto1896+10,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto1896+380,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	_Context->trigger_Restore=visual_trigger_code(_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]));
	visual_button(_Context->x_Auto1896+200,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]),0);
	visual_thaw(_Context->x_Auto1896,_Context->y_Auto1896,490,220);
	visual_thaw(_Context->x_Auto1896,_Context->y_Auto1896,490,220);

	return(0);
}

private int Auto1896action(struct accept_treeview_parameters_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_treeview_parameters_hide(_Context);

		_Context->x_Auto1896 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto1896 < 0) { _Context->x_Auto1896=0; }
		_Context->y_Auto1896 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto1896 < 0) { _Context->y_Auto1896=0; }
			accept_treeview_parameters_show(_Context);

		visual_thaw(_Context->x_Auto1896,_Context->y_Auto1896,490,220);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_treeview_parameters_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_treeview_parameters_context * _Context) {
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
		if (_Context->trigger_Accept == mb ) return(9);
		if (_Context->trigger_Cancel == mb ) return(10);
		if (_Context->trigger_Restore == mb ) return(11);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto1896+469) )  
	&&  (my >= (_Context->y_Auto1896+4) )  
	&&  (mx <= (_Context->x_Auto1896+486) )  
	&&  (my <= (_Context->y_Auto1896+20) )) {
		return(1);	/* Auto1896 */

		}
	if ((mx >= (_Context->x_Auto1896+453) )  
	&&  (my >= (_Context->y_Auto1896+4) )  
	&&  (mx <= (_Context->x_Auto1896+470) )  
	&&  (my <= (_Context->y_Auto1896+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vtree.htm");
			};
		return(-1);	/* Auto1896 */

		}
	if ((mx >= (_Context->x_Auto1896+437) )  
	&&  (my >= (_Context->y_Auto1896+4) )  
	&&  (mx <= (_Context->x_Auto1896+454) )  
	&&  (my <= (_Context->y_Auto1896+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_treeview_parameters_show(_Context);
		return(-1);	/* Auto1896 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto1896+4) )  
		&&  (my >= (_Context->y_Auto1896+4) )  
		&&  (mx <= (_Context->x_Auto1896+422) )  
		&&  (my <= (_Context->y_Auto1896+20) )) {
			return( Auto1896action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto1896+120+0) ) 
	&&  ( my >= (_Context->y_Auto1896+70) ) 
	&&  ( mx <= (_Context->x_Auto1896+120+112) ) 
	&&  ( my <= (_Context->y_Auto1896+70+16))) {
		return(2); /* TextFont */
		}
	if (( mx >= (_Context->x_Auto1896+120) ) 
	&&  ( my >= (_Context->y_Auto1896+130) ) 
	&&  ( mx <= (_Context->x_Auto1896+120+40) ) 
	&&  ( my <= (_Context->y_Auto1896+130+16))) {
		return(3); /* LineSpacing */
		}
	if (( mx >= (_Context->x_Auto1896+350+0) ) 
	&&  ( my >= (_Context->y_Auto1896+70) ) 
	&&  ( mx <= (_Context->x_Auto1896+350+120) ) 
	&&  ( my <= (_Context->y_Auto1896+70+16))) {
		return(4); /* ZoneType */
		}
	if (( mx >= (_Context->x_Auto1896+240) ) 
	&&  ( my >= (_Context->y_Auto1896+100) ) 
	&&  ( mx <= (_Context->x_Auto1896+240+98) ) 
	&&  ( my <= (_Context->y_Auto1896+100+16))) {
		return(5); /* SourceName */
		}
	if (( mx >= (_Context->x_Auto1896+350) ) 
	&&  ( my >= (_Context->y_Auto1896+100) ) 
	&&  ( mx <= (_Context->x_Auto1896+350+112) ) 
	&&  ( my <= (_Context->y_Auto1896+100+16))) {
		return(6); /* TargetName */
		}
	if (( mx >= (_Context->x_Auto1896+240) ) 
	&&  ( my >= (_Context->y_Auto1896+130) ) 
	&&  ( mx <= (_Context->x_Auto1896+240+112) ) 
	&&  ( my <= (_Context->y_Auto1896+130+16))) {
		return(7); /* Packaging */
		}
	if (( mx >= (_Context->x_Auto1896+350) ) 
	&&  ( my >= (_Context->y_Auto1896+130) ) 
	&&  ( mx <= (_Context->x_Auto1896+350+98) ) 
	&&  ( my <= (_Context->y_Auto1896+130+16))) {
		return(8); /* Identity */
		}
	if (( mx >= (_Context->x_Auto1896+10) ) 
	&&  ( my >= (_Context->y_Auto1896+170) ) 
	&&  ( mx <= (_Context->x_Auto1896+10+98) ) 
	&&  ( my <= (_Context->y_Auto1896+170+32))) {
		return(9); /* Accept */
		}
	if (( mx >= (_Context->x_Auto1896+380) ) 
	&&  ( my >= (_Context->y_Auto1896+170) ) 
	&&  ( mx <= (_Context->x_Auto1896+380+98) ) 
	&&  ( my <= (_Context->y_Auto1896+170+32))) {
		return(10); /* Cancel */
		}
	if (( mx >= (_Context->x_Auto1896+200) ) 
	&&  ( my >= (_Context->y_Auto1896+170) ) 
	&&  ( mx <= (_Context->x_Auto1896+200+98) ) 
	&&  ( my <= (_Context->y_Auto1896+170+32))) {
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
				_Context->keycode = visual_select(_Context->x_Auto1896+120,_Context->y_Auto1896+70,112,96,vfh[1],34,0,parse_selection(TextFontList,&_Context->value_TextFont),2);
				break;
			case	0x3 :
				/* LineSpacing */
				_Context->keycode = visual_edit(_Context->x_Auto1896+120+1,_Context->y_Auto1896+130+1,40,16,vfh[1],_Context->buffer_LineSpacing,5);
			break;
			case	0x4 :
				/* ZoneType */
				_Context->keycode = visual_select(_Context->x_Auto1896+350,_Context->y_Auto1896+70,120,48,vfh[1],16,0,parse_selection(_Context->msg_ZoneType[_Context->language],&_Context->value_ZoneType),2);
				break;
			case	0x5 :
				/* SourceName */
				visual_check(_Context->x_Auto1896+240,_Context->y_Auto1896+100,98,16,vfh[2],16,0,_Context->msg_SourceName[_Context->language],strlen(_Context->msg_SourceName[_Context->language]),(_Context->value_SourceName |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1896+240,_Context->y_Auto1896+100,98,16,vfh[2],16,0,_Context->msg_SourceName[_Context->language],strlen(_Context->msg_SourceName[_Context->language]),(_Context->value_SourceName |0));
				break;
			case	0x6 :
				/* TargetName */
				visual_check(_Context->x_Auto1896+350,_Context->y_Auto1896+100,112,16,vfh[2],16,0,_Context->msg_TargetName[_Context->language],strlen(_Context->msg_TargetName[_Context->language]),(_Context->value_TargetName |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1896+350,_Context->y_Auto1896+100,112,16,vfh[2],16,0,_Context->msg_TargetName[_Context->language],strlen(_Context->msg_TargetName[_Context->language]),(_Context->value_TargetName |0));
				break;
			case	0x7 :
				/* Packaging */
				visual_check(_Context->x_Auto1896+240,_Context->y_Auto1896+130,112,16,vfh[2],16,0,_Context->msg_Packaging[_Context->language],strlen(_Context->msg_Packaging[_Context->language]),(_Context->value_Packaging |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1896+240,_Context->y_Auto1896+130,112,16,vfh[2],16,0,_Context->msg_Packaging[_Context->language],strlen(_Context->msg_Packaging[_Context->language]),(_Context->value_Packaging |0));
				break;
			case	0x8 :
				/* Identity */
				visual_check(_Context->x_Auto1896+350,_Context->y_Auto1896+130,98,16,vfh[2],16,0,_Context->msg_Identity[_Context->language],strlen(_Context->msg_Identity[_Context->language]),(_Context->value_Identity |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1896+350,_Context->y_Auto1896+130,98,16,vfh[2],16,0,_Context->msg_Identity[_Context->language],strlen(_Context->msg_Identity[_Context->language]),(_Context->value_Identity |0));
				break;
			case	0x9 :
				/* Accept */
				visual_button(_Context->x_Auto1896+10,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1896+10,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0xa :
				/* Cancel */
				visual_button(_Context->x_Auto1896+380,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1896+380,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0xb :
				/* Restore */
				visual_button(_Context->x_Auto1896+200,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1896+200,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]),0);
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
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1896 */
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
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1896+10,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1896+10,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0xa :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1896+380,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1896+380,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0xb :
						/* Restore */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1896+200,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1896+200,_Context->y_Auto1896+170,98,32,vfh[2],34,0,_Context->msg_Restore[_Context->language],strlen(_Context->msg_Restore[_Context->language]),0);
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
