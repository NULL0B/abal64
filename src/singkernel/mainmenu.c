
#ifndef _mainmenu_c
#define _mainmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : mainmenu.xml  */
/* Target         : mainmenu.c  */
/* Identification : 0.0-1100084484-2590.2589 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "vnatlang.h"
#include "singmenu.h"
#define en_Auto1739   ""
#define en_ToolTray   ""
#define en_Auto1740   ""
#define fr_Auto1740   "upicon.gif"
#define it_Auto1740   "upicon.gif"
#define es_Auto1740   "upicon.gif"
#define de_Auto1740   "upicon.gif"
#define nl_Auto1740   "upicon.gif"
#define pt_Auto1740   "upicon.gif"
#define xx_Auto1740   "upicon.gif"
#define en_PaletteTray   ""
#define fr_PaletteTray   "upicon.gif"
#define it_PaletteTray   "upicon.gif"
#define es_PaletteTray   "upicon.gif"
#define de_PaletteTray   "upicon.gif"
#define nl_PaletteTray   "upicon.gif"
#define pt_PaletteTray   "upicon.gif"
#define xx_PaletteTray   "upicon.gif"
#define fr_Auto1726   "&upicon.gif"
#define it_Auto1726   "&upicon.gif"
#define es_Auto1726   "&upicon.gif"
#define de_Auto1726   "&upicon.gif"
#define nl_Auto1726   "&upicon.gif"
#define pt_Auto1726   "&upicon.gif"
#define xx_Auto1726   "&upicon.gif"
#define en_Auto1741   "&File"
#define fr_Auto1741   "&Fichier"
#define it_Auto1741   "&File"
#define es_Auto1741   "&File"
#define de_Auto1741   "&File"
#define nl_Auto1741   "&File"
#define pt_Auto1741   "&File"
#define xx_Auto1741   "&File"
#define en_Auto1742   "&View"
#define fr_Auto1742   "&Vue"
#define it_Auto1742   "&View"
#define es_Auto1742   "&View"
#define de_Auto1742   "&View"
#define nl_Auto1742   "&View"
#define pt_Auto1742   "&View"
#define xx_Auto1742   "&View"
#define en_Auto1743   "&Event"
#define fr_Auto1743   "&Event"
#define it_Auto1743   "&Event"
#define es_Auto1743   "&Event"
#define de_Auto1743   "&Event"
#define nl_Auto1743   "&Event"
#define pt_Auto1743   "&Event"
#define xx_Auto1743   "&Event"
#define en_Auto1744   "&Options"
#define fr_Auto1744   "&Options"
#define it_Auto1744   "&Options"
#define es_Auto1744   "&Options"
#define de_Auto1744   "&Options"
#define nl_Auto1744   "&Options"
#define pt_Auto1744   "&Options"
#define xx_Auto1744   "&Options"
#define en_TitleOne   "visual_language_message"
#define en_TitleThree   "visual_language_message"
#define en_TitleTwo   "visual_language_message"
#define en_LinkMenu   "Project|Form|Image|Text|Trace"
#define fr_LinkMenu   "Project|Form|Image|Text|Trace"
#define it_LinkMenu   "Project|Form|Image|Text|Trace"
#define es_LinkMenu   "Project|Form|Image|Text|Trace"
#define de_LinkMenu   "Project|Form|Image|Text|Trace"
#define nl_LinkMenu   "Project|Form|Image|Text|Trace"
#define pt_LinkMenu   "Project|Form|Image|Text|Trace"
#define xx_LinkMenu   "Project|Form|Image|Text|Trace"
#define en_LinkTwo   "Project|Form|Image|Text|Trace"
#define fr_LinkTwo   "Project|Form|Image|Text|Trace"
#define it_LinkTwo   "Project|Form|Image|Text|Trace"
#define es_LinkTwo   "Project|Form|Image|Text|Trace"
#define de_LinkTwo   "Project|Form|Image|Text|Trace"
#define nl_LinkTwo   "Project|Form|Image|Text|Trace"
#define pt_LinkTwo   "Project|Form|Image|Text|Trace"
#define xx_LinkTwo   "Project|Form|Image|Text|Trace"
#define en_LinkThree   "Project|Form|Image|Text|Trace"
#define fr_LinkThree   "Project|Form|Image|Text|Trace"
#define it_LinkThree   "Project|Form|Image|Text|Trace"
#define es_LinkThree   "Project|Form|Image|Text|Trace"
#define de_LinkThree   "Project|Form|Image|Text|Trace"
#define nl_LinkThree   "Project|Form|Image|Text|Trace"
#define pt_LinkThree   "Project|Form|Image|Text|Trace"
#define xx_LinkThree   "Project|Form|Image|Text|Trace"
#define en_DebugTrigger   "vdbicon.gif"
#define fr_DebugTrigger   "vdbicon.gif"
#define it_DebugTrigger   "vdbicon.gif"
#define es_DebugTrigger   "vdbicon.gif"
#define de_DebugTrigger   "vdbicon.gif"
#define nl_DebugTrigger   "vdbicon.gif"
#define pt_DebugTrigger   "vdbicon.gif"
#define xx_DebugTrigger   "vdbicon.gif"
#define en_RuntimeTrigger   "exaicon.gif"
#define fr_RuntimeTrigger   "exaicon.gif"
#define it_RuntimeTrigger   "exaicon.gif"
#define es_RuntimeTrigger   "exaicon.gif"
#define de_RuntimeTrigger   "exaicon.gif"
#define nl_RuntimeTrigger   "exaicon.gif"
#define pt_RuntimeTrigger   "exaicon.gif"
#define xx_RuntimeTrigger   "exaicon.gif"
#define en_EditorTrigger   "aedicon.gif"
#define fr_EditorTrigger   "aedicon.gif"
#define it_EditorTrigger   "aedicon.gif"
#define es_EditorTrigger   "aedicon.gif"
#define de_EditorTrigger   "aedicon.gif"
#define nl_EditorTrigger   "aedicon.gif"
#define pt_EditorTrigger   "aedicon.gif"
#define xx_EditorTrigger   "aedicon.gif"
#define en_OtrTrigger   "otricon.gif"
#define fr_OtrTrigger   "otricon.gif"
#define it_OtrTrigger   "otricon.gif"
#define es_OtrTrigger   "otricon.gif"
#define de_OtrTrigger   "otricon.gif"
#define nl_OtrTrigger   "otricon.gif"
#define pt_OtrTrigger   "otricon.gif"
#define xx_OtrTrigger   "otricon.gif"
#define en_OldTrigger   "oldicon.gif"
#define fr_OldTrigger   "oldicon.gif"
#define it_OldTrigger   "oldicon.gif"
#define es_OldTrigger   "oldicon.gif"
#define de_OldTrigger   "oldicon.gif"
#define nl_OldTrigger   "oldicon.gif"
#define pt_OldTrigger   "oldicon.gif"
#define xx_OldTrigger   "oldicon.gif"
#define fr_PaletteTrigger   "u&picon.gif"
#define it_PaletteTrigger   "u&picon.gif"
#define es_PaletteTrigger   "u&picon.gif"
#define de_PaletteTrigger   "u&picon.gif"
#define nl_PaletteTrigger   "u&picon.gif"
#define pt_PaletteTrigger   "u&picon.gif"
#define xx_PaletteTrigger   "u&picon.gif"
static int	vfh[10];

private struct standard_main_menu_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	x_Auto1739;
	int	y_Auto1739;
	int	w_Auto1739;
	int	h_Auto1739;
	int	fg_Auto1739;
	int	bg_Auto1739;
	int	fid_Auto1739;
	int	x_ToolTray;
	int	y_ToolTray;
	int	w_ToolTray;
	int	h_ToolTray;
	int	fg_ToolTray;
	int	bg_ToolTray;
	int	fid_ToolTray;
	char * msg_Auto1740[8];
	char * msg_PaletteTray[8];
	int	x_PaletteTray;
	int	y_PaletteTray;
	int	w_PaletteTray;
	int	h_PaletteTray;
	int	fg_PaletteTray;
	int	bg_PaletteTray;
	int	fid_PaletteTray;
	char * msg_Auto1726[8];
	int	trigger_Auto1726;
	char * msg_Auto1741[8];
	int	trigger_Auto1741;
	char * msg_Auto1742[8];
	int	trigger_Auto1742;
	char * msg_Auto1743[8];
	int	trigger_Auto1743;
	char * msg_Auto1744[8];
	int	trigger_Auto1744;
	char * msg_Auto1745[8];
	int	trigger_Auto1745;
	char * msg_Auto1746[8];
	int	trigger_Auto1746;
	char * msg_Auto1747[8];
	int	trigger_Auto1747;
	char * msg_TitleOne[8];
struct visual_language_message * TitleOne;
	char * msg_TitleThree[8];
struct visual_language_message * TitleThree;
	char * msg_TitleTwo[8];
struct visual_language_message * TitleTwo;
	char * msg_LinkMenu[8];
	int	value_LinkMenu;
	char * msg_LinkTwo[8];
	int	value_LinkTwo;
	char * msg_LinkThree[8];
	int	value_LinkThree;
	char * msg_DebugTrigger[8];
	int	trigger_DebugTrigger;
	int	x_DebugTrigger;
	int	y_DebugTrigger;
	int	w_DebugTrigger;
	int	h_DebugTrigger;
	int	fg_DebugTrigger;
	int	bg_DebugTrigger;
	int	fid_DebugTrigger;
	char * msg_RuntimeTrigger[8];
	int	trigger_RuntimeTrigger;
	int	x_RuntimeTrigger;
	int	y_RuntimeTrigger;
	int	w_RuntimeTrigger;
	int	h_RuntimeTrigger;
	int	fg_RuntimeTrigger;
	int	bg_RuntimeTrigger;
	int	fid_RuntimeTrigger;
	char * msg_EditorTrigger[8];
	int	trigger_EditorTrigger;
	int	x_EditorTrigger;
	int	y_EditorTrigger;
	int	w_EditorTrigger;
	int	h_EditorTrigger;
	int	fg_EditorTrigger;
	int	bg_EditorTrigger;
	int	fid_EditorTrigger;
	char * msg_OtrTrigger[8];
	int	trigger_OtrTrigger;
	int	x_OtrTrigger;
	int	y_OtrTrigger;
	int	w_OtrTrigger;
	int	h_OtrTrigger;
	int	fg_OtrTrigger;
	int	bg_OtrTrigger;
	int	fid_OtrTrigger;
	char * msg_OldTrigger[8];
	int	trigger_OldTrigger;
	int	x_OldTrigger;
	int	y_OldTrigger;
	int	w_OldTrigger;
	int	h_OldTrigger;
	int	fg_OldTrigger;
	int	bg_OldTrigger;
	int	fid_OldTrigger;
	char * msg_PaletteTrigger[8];
	int	trigger_PaletteTrigger;
	int	x_PaletteTrigger;
	int	y_PaletteTrigger;
	int	w_PaletteTrigger;
	int	h_PaletteTrigger;
	int	fg_PaletteTrigger;
	int	bg_PaletteTrigger;
	int	fid_PaletteTrigger;
	char	signature[1];
	};
static short	recalculate_widget_position(struct standard_main_menu_context * _Context,int x, int oldw, int neww);
void	standard_menu_extension(struct standard_main_menu_context * _Context,int number, struct visual_language_message * mptr);
void	drop_menu_extension(struct standard_main_menu_context * _Context,int number);
static char	 * get_toolbar_icon(struct standard_main_menu_context * _Context);
static char	 * get_palette_icon(struct standard_main_menu_context * _Context);

/*	--------------------------------------------------------	*/
/*	r e c a l c u l a t e _ w i d g e t _ p o s i t i o n ()	*/
/*	--------------------------------------------------------	*/
static short	recalculate_widget_position(struct standard_main_menu_context * _Context,int x, int oldw, int neww){
	int distance;
	distance=(oldw-x);
	return((neww-distance));

}

/*	------------------------------------------------	*/
/*	s t a n d a r d _ m e n u _ e x t e n s i o n ()	*/
/*	------------------------------------------------	*/
void	standard_menu_extension(struct standard_main_menu_context * _Context,int number, struct visual_language_message * mptr){
	if(!(_Context->value_LinkMenu)){
	_Context->value_LinkMenu=number;
	_Context->TitleOne=mptr;
	}
	else if(!(_Context->value_LinkTwo)){
	_Context->value_LinkTwo=number;
	_Context->TitleTwo=mptr;
	}
	else if(!(_Context->value_LinkThree)){
	_Context->value_LinkThree=number;
	_Context->TitleThree=mptr;
	}
		standard_main_menu_show(_Context);
;
	return;

}

/*	----------------------------------------	*/
/*	d r o p _ m e n u _ e x t e n s i o n ()	*/
/*	----------------------------------------	*/
void	drop_menu_extension(struct standard_main_menu_context * _Context,int number){
	if(_Context->value_LinkMenu==number){
	_Context->value_LinkMenu=_Context->value_LinkTwo;
	_Context->TitleOne=_Context->TitleTwo;
	_Context->value_LinkTwo=_Context->value_LinkThree;
	_Context->TitleTwo=_Context->TitleThree;
	_Context->value_LinkThree=0;
	_Context->TitleThree=visual_empty_message();
	}
	else if(_Context->value_LinkTwo==number){
	_Context->TitleTwo=_Context->TitleThree;
	_Context->value_LinkTwo=_Context->value_LinkThree;
	_Context->value_LinkThree=0;
	_Context->TitleThree=visual_empty_message();
	}
	else if(_Context->value_LinkThree==number){
	_Context->value_LinkThree=0;
	_Context->TitleThree=visual_empty_message();
	}
		standard_main_menu_show(_Context);
;
	
}

/*	----------------------------------	*/
/*	g e t _ t o o l b a r _ i c o n ()	*/
/*	----------------------------------	*/
static char	 * get_toolbar_icon(struct standard_main_menu_context * _Context){
	char*GetToolBarSwitch();
	return(GetToolBarSwitch());

}

/*	----------------------------------	*/
/*	g e t _ p a l e t t e _ i c o n ()	*/
/*	----------------------------------	*/
static char	 * get_palette_icon(struct standard_main_menu_context * _Context){
	char*GetPaletteSwitch();
	return(GetPaletteSwitch());

}
private int on_Auto1745_create(struct standard_main_menu_context * _Context) {
	_Context->TitleOne=visual_empty_message();
	return(-1);
}

public	int	standard_main_menu_create(struct standard_main_menu_context **cptr)
{

	int i;
	struct standard_main_menu_context * _Context=(struct standard_main_menu_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct standard_main_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=19;
	_Context->x_Auto1739=0;
	_Context->y_Auto1739=0;
	_Context->w_Auto1739=800;
	_Context->h_Auto1739=33;
	_Context->fg_Auto1739=33;
	_Context->bg_Auto1739=33;
	_Context->fid_Auto1739=1;
	_Context->x_ToolTray=650;
	_Context->y_ToolTray=6;
	_Context->w_ToolTray=102;
	_Context->h_ToolTray=20;
	_Context->fg_ToolTray=20;
	_Context->bg_ToolTray=20;
	_Context->fid_ToolTray=1;
	for (i=0; i < 8; i++)_Context->msg_Auto1740[i]=" ";
	_Context->msg_Auto1740[0]=en_Auto1740;
	_Context->msg_Auto1740[1]=fr_Auto1740;
	_Context->msg_Auto1740[2]=it_Auto1740;
	_Context->msg_Auto1740[3]=es_Auto1740;
	_Context->msg_Auto1740[4]=de_Auto1740;
	_Context->msg_Auto1740[5]=nl_Auto1740;
	_Context->msg_Auto1740[6]=pt_Auto1740;
	_Context->msg_Auto1740[7]=xx_Auto1740;
	for (i=0; i < 8; i++)_Context->msg_PaletteTray[i]=" ";
	_Context->msg_PaletteTray[0]=en_PaletteTray;
	_Context->msg_PaletteTray[1]=fr_PaletteTray;
	_Context->msg_PaletteTray[2]=it_PaletteTray;
	_Context->msg_PaletteTray[3]=es_PaletteTray;
	_Context->msg_PaletteTray[4]=de_PaletteTray;
	_Context->msg_PaletteTray[5]=nl_PaletteTray;
	_Context->msg_PaletteTray[6]=pt_PaletteTray;
	_Context->msg_PaletteTray[7]=xx_PaletteTray;
	_Context->x_PaletteTray=767;
	_Context->y_PaletteTray=7;
	_Context->w_PaletteTray=19;
	_Context->h_PaletteTray=18;
	_Context->fg_PaletteTray=18;
	_Context->bg_PaletteTray=18;
	_Context->fid_PaletteTray=1;
	for (i=0; i < 8; i++)_Context->msg_Auto1726[i]=" ";
	_Context->msg_Auto1726[1]=fr_Auto1726;
	_Context->msg_Auto1726[2]=it_Auto1726;
	_Context->msg_Auto1726[3]=es_Auto1726;
	_Context->msg_Auto1726[4]=de_Auto1726;
	_Context->msg_Auto1726[5]=nl_Auto1726;
	_Context->msg_Auto1726[6]=pt_Auto1726;
	_Context->msg_Auto1726[7]=xx_Auto1726;
	for (i=0; i < 8; i++)_Context->msg_Auto1741[i]=" ";
	_Context->msg_Auto1741[0]=en_Auto1741;
	_Context->msg_Auto1741[1]=fr_Auto1741;
	_Context->msg_Auto1741[2]=it_Auto1741;
	_Context->msg_Auto1741[3]=es_Auto1741;
	_Context->msg_Auto1741[4]=de_Auto1741;
	_Context->msg_Auto1741[5]=nl_Auto1741;
	_Context->msg_Auto1741[6]=pt_Auto1741;
	_Context->msg_Auto1741[7]=xx_Auto1741;
	for (i=0; i < 8; i++)_Context->msg_Auto1742[i]=" ";
	_Context->msg_Auto1742[0]=en_Auto1742;
	_Context->msg_Auto1742[1]=fr_Auto1742;
	_Context->msg_Auto1742[2]=it_Auto1742;
	_Context->msg_Auto1742[3]=es_Auto1742;
	_Context->msg_Auto1742[4]=de_Auto1742;
	_Context->msg_Auto1742[5]=nl_Auto1742;
	_Context->msg_Auto1742[6]=pt_Auto1742;
	_Context->msg_Auto1742[7]=xx_Auto1742;
	for (i=0; i < 8; i++)_Context->msg_Auto1743[i]=" ";
	_Context->msg_Auto1743[0]=en_Auto1743;
	_Context->msg_Auto1743[1]=fr_Auto1743;
	_Context->msg_Auto1743[2]=it_Auto1743;
	_Context->msg_Auto1743[3]=es_Auto1743;
	_Context->msg_Auto1743[4]=de_Auto1743;
	_Context->msg_Auto1743[5]=nl_Auto1743;
	_Context->msg_Auto1743[6]=pt_Auto1743;
	_Context->msg_Auto1743[7]=xx_Auto1743;
	for (i=0; i < 8; i++)_Context->msg_Auto1744[i]=" ";
	_Context->msg_Auto1744[0]=en_Auto1744;
	_Context->msg_Auto1744[1]=fr_Auto1744;
	_Context->msg_Auto1744[2]=it_Auto1744;
	_Context->msg_Auto1744[3]=es_Auto1744;
	_Context->msg_Auto1744[4]=de_Auto1744;
	_Context->msg_Auto1744[5]=nl_Auto1744;
	_Context->msg_Auto1744[6]=pt_Auto1744;
	_Context->msg_Auto1744[7]=xx_Auto1744;
	for (i=0; i < 8; i++)_Context->msg_Auto1745[i]=" ";
	(void) on_Auto1745_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto1746[i]=" ";
	_Context->TitleTwo=visual_empty_message();
	for (i=0; i < 8; i++)_Context->msg_Auto1747[i]=" ";
	_Context->TitleThree=visual_empty_message();
	for (i=0; i < 8; i++)_Context->msg_TitleOne[i]=" ";
	_Context->msg_TitleOne[0]=en_TitleOne;
	for (i=0; i < 8; i++)_Context->msg_TitleThree[i]=" ";
	_Context->msg_TitleThree[0]=en_TitleThree;
	for (i=0; i < 8; i++)_Context->msg_TitleTwo[i]=" ";
	_Context->msg_TitleTwo[0]=en_TitleTwo;
	for (i=0; i < 8; i++)_Context->msg_LinkMenu[i]=" ";
	_Context->msg_LinkMenu[0]=en_LinkMenu;
	_Context->msg_LinkMenu[1]=fr_LinkMenu;
	_Context->msg_LinkMenu[2]=it_LinkMenu;
	_Context->msg_LinkMenu[3]=es_LinkMenu;
	_Context->msg_LinkMenu[4]=de_LinkMenu;
	_Context->msg_LinkMenu[5]=nl_LinkMenu;
	_Context->msg_LinkMenu[6]=pt_LinkMenu;
	_Context->msg_LinkMenu[7]=xx_LinkMenu;
	for (i=0; i < 8; i++)_Context->msg_LinkTwo[i]=" ";
	_Context->msg_LinkTwo[0]=en_LinkTwo;
	_Context->msg_LinkTwo[1]=fr_LinkTwo;
	_Context->msg_LinkTwo[2]=it_LinkTwo;
	_Context->msg_LinkTwo[3]=es_LinkTwo;
	_Context->msg_LinkTwo[4]=de_LinkTwo;
	_Context->msg_LinkTwo[5]=nl_LinkTwo;
	_Context->msg_LinkTwo[6]=pt_LinkTwo;
	_Context->msg_LinkTwo[7]=xx_LinkTwo;
	for (i=0; i < 8; i++)_Context->msg_LinkThree[i]=" ";
	_Context->msg_LinkThree[0]=en_LinkThree;
	_Context->msg_LinkThree[1]=fr_LinkThree;
	_Context->msg_LinkThree[2]=it_LinkThree;
	_Context->msg_LinkThree[3]=es_LinkThree;
	_Context->msg_LinkThree[4]=de_LinkThree;
	_Context->msg_LinkThree[5]=nl_LinkThree;
	_Context->msg_LinkThree[6]=pt_LinkThree;
	_Context->msg_LinkThree[7]=xx_LinkThree;
	for (i=0; i < 8; i++)_Context->msg_DebugTrigger[i]=" ";
	_Context->msg_DebugTrigger[0]=en_DebugTrigger;
	_Context->msg_DebugTrigger[1]=fr_DebugTrigger;
	_Context->msg_DebugTrigger[2]=it_DebugTrigger;
	_Context->msg_DebugTrigger[3]=es_DebugTrigger;
	_Context->msg_DebugTrigger[4]=de_DebugTrigger;
	_Context->msg_DebugTrigger[5]=nl_DebugTrigger;
	_Context->msg_DebugTrigger[6]=pt_DebugTrigger;
	_Context->msg_DebugTrigger[7]=xx_DebugTrigger;
	_Context->x_DebugTrigger=648;
	_Context->y_DebugTrigger=4;
	_Context->w_DebugTrigger=24;
	_Context->h_DebugTrigger=24;
	_Context->fg_DebugTrigger=24;
	_Context->bg_DebugTrigger=24;
	_Context->fid_DebugTrigger=1;
	for (i=0; i < 8; i++)_Context->msg_RuntimeTrigger[i]=" ";
	_Context->msg_RuntimeTrigger[0]=en_RuntimeTrigger;
	_Context->msg_RuntimeTrigger[1]=fr_RuntimeTrigger;
	_Context->msg_RuntimeTrigger[2]=it_RuntimeTrigger;
	_Context->msg_RuntimeTrigger[3]=es_RuntimeTrigger;
	_Context->msg_RuntimeTrigger[4]=de_RuntimeTrigger;
	_Context->msg_RuntimeTrigger[5]=nl_RuntimeTrigger;
	_Context->msg_RuntimeTrigger[6]=pt_RuntimeTrigger;
	_Context->msg_RuntimeTrigger[7]=xx_RuntimeTrigger;
	_Context->x_RuntimeTrigger=668;
	_Context->y_RuntimeTrigger=4;
	_Context->w_RuntimeTrigger=24;
	_Context->h_RuntimeTrigger=24;
	_Context->fg_RuntimeTrigger=24;
	_Context->bg_RuntimeTrigger=24;
	_Context->fid_RuntimeTrigger=1;
	for (i=0; i < 8; i++)_Context->msg_EditorTrigger[i]=" ";
	_Context->msg_EditorTrigger[0]=en_EditorTrigger;
	_Context->msg_EditorTrigger[1]=fr_EditorTrigger;
	_Context->msg_EditorTrigger[2]=it_EditorTrigger;
	_Context->msg_EditorTrigger[3]=es_EditorTrigger;
	_Context->msg_EditorTrigger[4]=de_EditorTrigger;
	_Context->msg_EditorTrigger[5]=nl_EditorTrigger;
	_Context->msg_EditorTrigger[6]=pt_EditorTrigger;
	_Context->msg_EditorTrigger[7]=xx_EditorTrigger;
	_Context->x_EditorTrigger=688;
	_Context->y_EditorTrigger=4;
	_Context->w_EditorTrigger=24;
	_Context->h_EditorTrigger=24;
	_Context->fg_EditorTrigger=24;
	_Context->bg_EditorTrigger=24;
	_Context->fid_EditorTrigger=1;
	for (i=0; i < 8; i++)_Context->msg_OtrTrigger[i]=" ";
	_Context->msg_OtrTrigger[0]=en_OtrTrigger;
	_Context->msg_OtrTrigger[1]=fr_OtrTrigger;
	_Context->msg_OtrTrigger[2]=it_OtrTrigger;
	_Context->msg_OtrTrigger[3]=es_OtrTrigger;
	_Context->msg_OtrTrigger[4]=de_OtrTrigger;
	_Context->msg_OtrTrigger[5]=nl_OtrTrigger;
	_Context->msg_OtrTrigger[6]=pt_OtrTrigger;
	_Context->msg_OtrTrigger[7]=xx_OtrTrigger;
	_Context->x_OtrTrigger=708;
	_Context->y_OtrTrigger=4;
	_Context->w_OtrTrigger=24;
	_Context->h_OtrTrigger=24;
	_Context->fg_OtrTrigger=24;
	_Context->bg_OtrTrigger=24;
	_Context->fid_OtrTrigger=1;
	for (i=0; i < 8; i++)_Context->msg_OldTrigger[i]=" ";
	_Context->msg_OldTrigger[0]=en_OldTrigger;
	_Context->msg_OldTrigger[1]=fr_OldTrigger;
	_Context->msg_OldTrigger[2]=it_OldTrigger;
	_Context->msg_OldTrigger[3]=es_OldTrigger;
	_Context->msg_OldTrigger[4]=de_OldTrigger;
	_Context->msg_OldTrigger[5]=nl_OldTrigger;
	_Context->msg_OldTrigger[6]=pt_OldTrigger;
	_Context->msg_OldTrigger[7]=xx_OldTrigger;
	_Context->x_OldTrigger=728;
	_Context->y_OldTrigger=4;
	_Context->w_OldTrigger=24;
	_Context->h_OldTrigger=24;
	_Context->fg_OldTrigger=24;
	_Context->bg_OldTrigger=24;
	_Context->fid_OldTrigger=1;
	for (i=0; i < 8; i++)_Context->msg_PaletteTrigger[i]=" ";
	_Context->msg_PaletteTrigger[1]=fr_PaletteTrigger;
	_Context->msg_PaletteTrigger[2]=it_PaletteTrigger;
	_Context->msg_PaletteTrigger[3]=es_PaletteTrigger;
	_Context->msg_PaletteTrigger[4]=de_PaletteTrigger;
	_Context->msg_PaletteTrigger[5]=nl_PaletteTrigger;
	_Context->msg_PaletteTrigger[6]=pt_PaletteTrigger;
	_Context->msg_PaletteTrigger[7]=xx_PaletteTrigger;
	_Context->x_PaletteTrigger=764;
	_Context->y_PaletteTrigger=4;
	_Context->w_PaletteTrigger=24;
	_Context->h_PaletteTrigger=24;
	_Context->fg_PaletteTrigger=24;
	_Context->bg_PaletteTrigger=24;
	_Context->fid_PaletteTrigger=1;
	return(0);
}

public 	int	standard_main_menu_hide(struct standard_main_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	standard_main_menu_remove(struct standard_main_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}
private int on_Auto1739_show(struct standard_main_menu_context * _Context) {
	int ow;
	ow=_Context->w_Auto1739;
	_Context->w_Auto1739=x_conf(69);
	if(ow!=_Context->w_Auto1739){
	_Context->x_ToolTray=recalculate_widget_position(_Context, _Context->x_ToolTray,ow,_Context->w_Auto1739);
	_Context->x_DebugTrigger=recalculate_widget_position(_Context, _Context->x_DebugTrigger,ow,_Context->w_Auto1739);
	_Context->x_RuntimeTrigger=recalculate_widget_position(_Context, _Context->x_RuntimeTrigger,ow,_Context->w_Auto1739);
	_Context->x_EditorTrigger=recalculate_widget_position(_Context, _Context->x_EditorTrigger,ow,_Context->w_Auto1739);
	_Context->x_OtrTrigger=recalculate_widget_position(_Context, _Context->x_OtrTrigger,ow,_Context->w_Auto1739);
	_Context->x_OldTrigger=recalculate_widget_position(_Context, _Context->x_OldTrigger,ow,_Context->w_Auto1739);
	_Context->x_PaletteTray=recalculate_widget_position(_Context, _Context->x_PaletteTray,ow,_Context->w_Auto1739);
	_Context->x_PaletteTrigger=recalculate_widget_position(_Context, _Context->x_PaletteTrigger,ow,_Context->w_Auto1739);
	}
		visual_filzone(_Context->x_Auto1739,_Context->y_Auto1739,_Context->w_Auto1739,_Context->h_Auto1739,27,10);
;
	return(-1);
}
private int on_Auto1745_show(struct standard_main_menu_context * _Context) {
	if(_Context->TitleOne){
		_Context->trigger_Auto1745=visual_trigger_code(_Context->TitleOne->message[visual_national_language(-1)],strlen(_Context->TitleOne->message[visual_national_language(-1)]));
	visual_button(336,8,96,20,vfh[2],16,0,_Context->TitleOne->message[visual_national_language(-1)],strlen(_Context->TitleOne->message[visual_national_language(-1)]),32);

	}
	return(-1);
}
private int on_Auto1746_show(struct standard_main_menu_context * _Context) {
	if(_Context->TitleTwo){
		_Context->trigger_Auto1746=visual_trigger_code(_Context->TitleTwo->message[visual_national_language(-1)],strlen(_Context->TitleTwo->message[visual_national_language(-1)]));
	visual_button(432,8,92,20,vfh[2],16,0,_Context->TitleTwo->message[visual_national_language(-1)],strlen(_Context->TitleTwo->message[visual_national_language(-1)]),32);

	}
	return(-1);
}
private int on_Auto1747_show(struct standard_main_menu_context * _Context) {
	if(_Context->TitleThree){
		_Context->trigger_Auto1747=visual_trigger_code(_Context->TitleThree->message[visual_national_language(-1)],strlen(_Context->TitleThree->message[visual_national_language(-1)]));
	visual_button(520,8,96,20,vfh[2],16,0,_Context->TitleThree->message[visual_national_language(-1)],strlen(_Context->TitleThree->message[visual_national_language(-1)]),32);

	}
	return(-1);
}

public	int	standard_main_menu_show(struct standard_main_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	(void) on_Auto1739_show(_Context);
	visual_frame(_Context->x_ToolTray,_Context->y_ToolTray,_Context->w_ToolTray,_Context->h_ToolTray,2);
	visual_frame(13,7,19,18,2);
	visual_frame(_Context->x_PaletteTray,_Context->y_PaletteTray,_Context->w_PaletteTray,_Context->h_PaletteTray,2);
	_Context->trigger_Auto1726=visual_trigger_code(get_toolbar_icon(_Context),strlen(get_toolbar_icon(_Context)));
	visual_button(10,4,24,24,vfh[1],27,28,get_toolbar_icon(_Context),strlen(get_toolbar_icon(_Context)),48);
	_Context->trigger_Auto1741=visual_trigger_code(_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]));
	visual_button(60,8,60,20,vfh[2],16,0,_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]),32);
	_Context->trigger_Auto1742=visual_trigger_code(_Context->msg_Auto1742[_Context->language],strlen(_Context->msg_Auto1742[_Context->language]));
	visual_button(120,8,64,20,vfh[2],16,0,_Context->msg_Auto1742[_Context->language],strlen(_Context->msg_Auto1742[_Context->language]),32);
	_Context->trigger_Auto1743=visual_trigger_code(_Context->msg_Auto1743[_Context->language],strlen(_Context->msg_Auto1743[_Context->language]));
	visual_button(184,8,72,20,vfh[2],16,0,_Context->msg_Auto1743[_Context->language],strlen(_Context->msg_Auto1743[_Context->language]),32);
	_Context->trigger_Auto1744=visual_trigger_code(_Context->msg_Auto1744[_Context->language],strlen(_Context->msg_Auto1744[_Context->language]));
	visual_button(256,8,72,20,vfh[2],16,0,_Context->msg_Auto1744[_Context->language],strlen(_Context->msg_Auto1744[_Context->language]),32);
	(void) on_Auto1745_show(_Context);
	(void) on_Auto1746_show(_Context);
	(void) on_Auto1747_show(_Context);
	_Context->trigger_DebugTrigger=visual_trigger_code(_Context->msg_DebugTrigger[_Context->language],strlen(_Context->msg_DebugTrigger[_Context->language]));
	visual_button(_Context->x_DebugTrigger,_Context->y_DebugTrigger,_Context->w_DebugTrigger,_Context->h_DebugTrigger,_Context->fid_DebugTrigger,27,28,_Context->msg_DebugTrigger[_Context->language],strlen(_Context->msg_DebugTrigger[_Context->language]),48);
	_Context->trigger_RuntimeTrigger=visual_trigger_code(_Context->msg_RuntimeTrigger[_Context->language],strlen(_Context->msg_RuntimeTrigger[_Context->language]));
	visual_button(_Context->x_RuntimeTrigger,_Context->y_RuntimeTrigger,_Context->w_RuntimeTrigger,_Context->h_RuntimeTrigger,_Context->fid_RuntimeTrigger,27,28,_Context->msg_RuntimeTrigger[_Context->language],strlen(_Context->msg_RuntimeTrigger[_Context->language]),48);
	_Context->trigger_EditorTrigger=visual_trigger_code(_Context->msg_EditorTrigger[_Context->language],strlen(_Context->msg_EditorTrigger[_Context->language]));
	visual_button(_Context->x_EditorTrigger,_Context->y_EditorTrigger,_Context->w_EditorTrigger,_Context->h_EditorTrigger,_Context->fid_EditorTrigger,27,28,_Context->msg_EditorTrigger[_Context->language],strlen(_Context->msg_EditorTrigger[_Context->language]),48);
	_Context->trigger_OtrTrigger=visual_trigger_code(_Context->msg_OtrTrigger[_Context->language],strlen(_Context->msg_OtrTrigger[_Context->language]));
	visual_button(_Context->x_OtrTrigger,_Context->y_OtrTrigger,_Context->w_OtrTrigger,_Context->h_OtrTrigger,_Context->fid_OtrTrigger,27,28,_Context->msg_OtrTrigger[_Context->language],strlen(_Context->msg_OtrTrigger[_Context->language]),48);
	_Context->trigger_OldTrigger=visual_trigger_code(_Context->msg_OldTrigger[_Context->language],strlen(_Context->msg_OldTrigger[_Context->language]));
	visual_button(_Context->x_OldTrigger,_Context->y_OldTrigger,_Context->w_OldTrigger,_Context->h_OldTrigger,_Context->fid_OldTrigger,27,28,_Context->msg_OldTrigger[_Context->language],strlen(_Context->msg_OldTrigger[_Context->language]),48);
	_Context->trigger_PaletteTrigger=visual_trigger_code(get_palette_icon(_Context),strlen(get_palette_icon(_Context)));
	visual_button(_Context->x_PaletteTrigger,_Context->y_PaletteTrigger,_Context->w_PaletteTrigger,_Context->h_PaletteTrigger,_Context->fid_PaletteTrigger,27,28,get_palette_icon(_Context),strlen(get_palette_icon(_Context)),48);
	visual_thaw(0,0,800,44);

	return(0);
}
private int on_Auto1740_event(struct standard_main_menu_context * _Context) {
	return(toggle_toolbar_display());
	return(-1);
}
private int on_PaletteTray_event(struct standard_main_menu_context * _Context) {
	return(toggle_toolbar_display());
	return(-1);
}
private int on_Auto1726_event(struct standard_main_menu_context * _Context) {
	return(toggle_toolbar_display());
	return(-1);
}
private int on_DebugTrigger_event(struct standard_main_menu_context * _Context) {
	char*sptr=(char*)0;
	int automatic;
	resolve_tool_parameters(&automatic,&sptr);
	if(sptr){
	abal_debuger(sptr,automatic);
	}
	return(256);
	return(-1);
}
private int on_RuntimeTrigger_event(struct standard_main_menu_context * _Context) {
	char*sptr=(char*)0;
	int automatic;
	resolve_tool_parameters(&automatic,&sptr);
	if(sptr){
	abal_runtime(sptr,automatic);
	}
	return(256);
	return(-1);
}
private int on_EditorTrigger_event(struct standard_main_menu_context * _Context) {
	char*sptr;
	int automatic;
	resolve_tool_parameters(&automatic,&sptr);
	use_abal_editor();
	return(256);
	return(-1);
}
private int on_OtrTrigger_event(struct standard_main_menu_context * _Context) {
	char*sptr=(char*)0;
	int automatic;
	resolve_tool_parameters(&automatic,&sptr);
	if(sptr){
	use_abal_translator(sptr,automatic);
	}
	return(256);
	return(-1);
}
private int on_OldTrigger_event(struct standard_main_menu_context * _Context) {
	char*sptr=(char*)0;
	int automatic;
	resolve_tool_parameters(&automatic,&sptr);
	if(sptr){
	use_abal_linker(sptr,automatic);
	}
	return(256);
	return(-1);
}
private int on_PaletteTrigger_event(struct standard_main_menu_context * _Context) {
	return(toggle_palette_display());
	return(-1);
}


public	int	standard_main_menu_event(
struct standard_main_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto1726 == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(10,4,24,24,vfh[1],27,28,get_toolbar_icon(_Context),strlen(get_toolbar_icon(_Context)),50);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(10,4,24,24,vfh[1],27,28,get_toolbar_icon(_Context),strlen(get_toolbar_icon(_Context)),48);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_Auto1726_event(_Context);

			}
		_Context->focus_item=3;
		return(256);
		}
		if (_Context->trigger_Auto1741 == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(60,8,60,20,vfh[2],16,0,_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]),34);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(60,8,60,20,vfh[2],16,0,_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]),32);
			}
		if ( visual_event(1) &  0x20 ) {
		{
		int result;
		if(visual_event(1)==_MIMO_MOVE)
		return(-1);
		switch((result=standard_file_menu())){
		case 27:
		case 13:
		return(-1);
		default:
		return(result);
		}
		}

			}
		_Context->focus_item=4;
		return(256);
		}
		if (_Context->trigger_Auto1742 == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(120,8,64,20,vfh[2],16,0,_Context->msg_Auto1742[_Context->language],strlen(_Context->msg_Auto1742[_Context->language]),34);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(120,8,64,20,vfh[2],16,0,_Context->msg_Auto1742[_Context->language],strlen(_Context->msg_Auto1742[_Context->language]),32);
			}
		if ( visual_event(1) &  0x20 ) {
		{
		int result;
		if(visual_event(1)==_MIMO_MOVE)
		return(-1);
		switch((result=standard_view_menu())){
		case 27:
		case 13:
		return(-1);
		default:
		return(result);
		}
		}

			}
		_Context->focus_item=5;
		return(256);
		}
		if (_Context->trigger_Auto1743 == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(184,8,72,20,vfh[2],16,0,_Context->msg_Auto1743[_Context->language],strlen(_Context->msg_Auto1743[_Context->language]),34);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(184,8,72,20,vfh[2],16,0,_Context->msg_Auto1743[_Context->language],strlen(_Context->msg_Auto1743[_Context->language]),32);
			}
		if ( visual_event(1) &  0x120 ) {
		int result;
		if(visual_event(1)==_MIMO_MOVE)
		return(-1);
		switch((result=standard_event_menu())){
		case 27:
		case 13:
		return(-1);
		default:
		return(result);
		}

			}
		_Context->focus_item=6;
		return(256);
		}
		if (_Context->trigger_Auto1744 == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(256,8,72,20,vfh[2],16,0,_Context->msg_Auto1744[_Context->language],strlen(_Context->msg_Auto1744[_Context->language]),34);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(256,8,72,20,vfh[2],16,0,_Context->msg_Auto1744[_Context->language],strlen(_Context->msg_Auto1744[_Context->language]),32);
			}
		if ( visual_event(1) &  0x20 ) {
		{
		int result;
		switch(visual_event(1)){
		case _MIMO_UP:
		switch((result=standard_option_menu())){
		case 27:
		case 13:
		return(-1);
		default:
		return(result);
		}
		default:
		return(-1);
		}
		}

			}
		_Context->focus_item=7;
		return(256);
		}
		if (_Context->trigger_Auto1745 == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(336,8,96,20,vfh[2],16,0,_Context->TitleOne->message[visual_national_language(-1)],strlen(_Context->TitleOne->message[visual_national_language(-1)]),34);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(336,8,96,20,vfh[2],16,0,_Context->TitleOne->message[visual_national_language(-1)],strlen(_Context->TitleOne->message[visual_national_language(-1)]),32);
			}
		if ( visual_event(1) &  0x20 ) {
		{
		int result=-1;
		if(!(_Context->TitleOne))
		return(-1);
		if(visual_event(1)==_MIMO_MOVE)
		return(-1);
		switch(_Context->value_LinkMenu){
		case 1:result=project_editor_menu();break;
		case 2:result=forms_editor_menu();break;
		case 3:result=image_editor_menu();break;
		case 4:result=text_editor_menu();break;
		case 5:result=trace_editor_menu();break;
		case 6:/*result=font_editor_menu();*/break;
		case 7:result=forms_widget_menu();break;
		}
		switch(result){
		case 27:
		case 13:
		return(-1);
		default:
		return(result);
		}
		}

			}
		_Context->focus_item=8;
		return(256);
		}
		if (_Context->trigger_Auto1746 == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(432,8,92,20,vfh[2],16,0,_Context->TitleTwo->message[visual_national_language(-1)],strlen(_Context->TitleTwo->message[visual_national_language(-1)]),34);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(432,8,92,20,vfh[2],16,0,_Context->TitleTwo->message[visual_national_language(-1)],strlen(_Context->TitleTwo->message[visual_national_language(-1)]),32);
			}
		if ( visual_event(1) &  0x20 ) {
		{
		int result=-1;
		if(!(_Context->TitleTwo))
		return(-1);
		if(visual_event(1)==_MIMO_MOVE)
		return(-1);
		switch(_Context->value_LinkTwo){
		case 1:result=project_editor_menu();break;
		case 2:result=forms_editor_menu();break;
		case 3:result=image_editor_menu();break;
		case 4:result=text_editor_menu();break;
		case 5:result=trace_editor_menu();break;
		case 6:/*result=font_editor_menu();*/break;
		case 7:result=forms_widget_menu();break;
		}
		switch(result){
		case 27:
		case 13:
		return(-1);
		default:
		return(result);
		}
		}

			}
		_Context->focus_item=9;
		return(256);
		}
		if (_Context->trigger_Auto1747 == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(520,8,96,20,vfh[2],16,0,_Context->TitleThree->message[visual_national_language(-1)],strlen(_Context->TitleThree->message[visual_national_language(-1)]),34);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(520,8,96,20,vfh[2],16,0,_Context->TitleThree->message[visual_national_language(-1)],strlen(_Context->TitleThree->message[visual_national_language(-1)]),32);
			}
		if ( visual_event(1) &  0x20 ) {
		{
		int result=-1;
		if(!(_Context->TitleThree))
		return(-1);
		if(visual_event(1)==_MIMO_MOVE)
		return(-1);
		switch(_Context->value_LinkThree){
		case 1:result=project_editor_menu();break;
		case 2:result=forms_editor_menu();break;
		case 3:result=image_editor_menu();break;
		case 4:result=text_editor_menu();break;
		case 5:result=trace_editor_menu();break;
		case 6:/*result=font_editor_menu();*/break;
		case 7:result=forms_widget_menu();break;
		}
		switch(result){
		case 27:
		case 13:
		return(-1);
		default:
		return(result);
		}
		}

			}
		_Context->focus_item=10;
		return(256);
		}
		if (_Context->trigger_DebugTrigger == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(_Context->x_DebugTrigger,_Context->y_DebugTrigger,_Context->w_DebugTrigger,_Context->h_DebugTrigger,_Context->fid_DebugTrigger,27,28,_Context->msg_DebugTrigger[_Context->language],strlen(_Context->msg_DebugTrigger[_Context->language]),50);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(_Context->x_DebugTrigger,_Context->y_DebugTrigger,_Context->w_DebugTrigger,_Context->h_DebugTrigger,_Context->fid_DebugTrigger,27,28,_Context->msg_DebugTrigger[_Context->language],strlen(_Context->msg_DebugTrigger[_Context->language]),48);
			}
		if ( visual_event(1) &  0x10 ) {
		(void) on_DebugTrigger_event(_Context);

			}
		_Context->focus_item=14;
		return(256);
		}
		if (_Context->trigger_RuntimeTrigger == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(_Context->x_RuntimeTrigger,_Context->y_RuntimeTrigger,_Context->w_RuntimeTrigger,_Context->h_RuntimeTrigger,_Context->fid_RuntimeTrigger,27,28,_Context->msg_RuntimeTrigger[_Context->language],strlen(_Context->msg_RuntimeTrigger[_Context->language]),50);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(_Context->x_RuntimeTrigger,_Context->y_RuntimeTrigger,_Context->w_RuntimeTrigger,_Context->h_RuntimeTrigger,_Context->fid_RuntimeTrigger,27,28,_Context->msg_RuntimeTrigger[_Context->language],strlen(_Context->msg_RuntimeTrigger[_Context->language]),48);
			}
		if ( visual_event(1) &  0x10 ) {
		(void) on_RuntimeTrigger_event(_Context);

			}
		_Context->focus_item=15;
		return(256);
		}
		if (_Context->trigger_EditorTrigger == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(_Context->x_EditorTrigger,_Context->y_EditorTrigger,_Context->w_EditorTrigger,_Context->h_EditorTrigger,_Context->fid_EditorTrigger,27,28,_Context->msg_EditorTrigger[_Context->language],strlen(_Context->msg_EditorTrigger[_Context->language]),50);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(_Context->x_EditorTrigger,_Context->y_EditorTrigger,_Context->w_EditorTrigger,_Context->h_EditorTrigger,_Context->fid_EditorTrigger,27,28,_Context->msg_EditorTrigger[_Context->language],strlen(_Context->msg_EditorTrigger[_Context->language]),48);
			}
		if ( visual_event(1) &  0x10 ) {
		(void) on_EditorTrigger_event(_Context);

			}
		_Context->focus_item=16;
		return(256);
		}
		if (_Context->trigger_OtrTrigger == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(_Context->x_OtrTrigger,_Context->y_OtrTrigger,_Context->w_OtrTrigger,_Context->h_OtrTrigger,_Context->fid_OtrTrigger,27,28,_Context->msg_OtrTrigger[_Context->language],strlen(_Context->msg_OtrTrigger[_Context->language]),50);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(_Context->x_OtrTrigger,_Context->y_OtrTrigger,_Context->w_OtrTrigger,_Context->h_OtrTrigger,_Context->fid_OtrTrigger,27,28,_Context->msg_OtrTrigger[_Context->language],strlen(_Context->msg_OtrTrigger[_Context->language]),48);
			}
		if ( visual_event(1) &  0x10 ) {
		(void) on_OtrTrigger_event(_Context);

			}
		_Context->focus_item=17;
		return(256);
		}
		if (_Context->trigger_OldTrigger == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(_Context->x_OldTrigger,_Context->y_OldTrigger,_Context->w_OldTrigger,_Context->h_OldTrigger,_Context->fid_OldTrigger,27,28,_Context->msg_OldTrigger[_Context->language],strlen(_Context->msg_OldTrigger[_Context->language]),50);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(_Context->x_OldTrigger,_Context->y_OldTrigger,_Context->w_OldTrigger,_Context->h_OldTrigger,_Context->fid_OldTrigger,27,28,_Context->msg_OldTrigger[_Context->language],strlen(_Context->msg_OldTrigger[_Context->language]),48);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_OldTrigger_event(_Context);

			}
		_Context->focus_item=18;
		return(256);
		}
		if (_Context->trigger_PaletteTrigger == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(_Context->x_PaletteTrigger,_Context->y_PaletteTrigger,_Context->w_PaletteTrigger,_Context->h_PaletteTrigger,_Context->fid_PaletteTrigger,27,28,get_palette_icon(_Context),strlen(get_palette_icon(_Context)),50);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(_Context->x_PaletteTrigger,_Context->y_PaletteTrigger,_Context->w_PaletteTrigger,_Context->h_PaletteTrigger,_Context->fid_PaletteTrigger,27,28,get_palette_icon(_Context),strlen(get_palette_icon(_Context)),48);
			}
		if ( visual_event(1) &  0x10 ) {
		(void) on_PaletteTrigger_event(_Context);

			}
		_Context->focus_item=19;
		return(256);
		}
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3131)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 13 ) 
	&&  ( my >= 7 ) 
	&&  ( mx <= 32 ) 
	&&  ( my <= 25 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_Auto1740_event(_Context);

			}
		_Context->focus_item=1;
		return(256);
		}
	if ((mx >= _Context->x_PaletteTray ) 
	&&  (my >= _Context->y_PaletteTray ) 
	&&  (mx <  (_Context->x_PaletteTray+_Context->w_PaletteTray)) 
	&&  (my <  (_Context->y_PaletteTray+_Context->h_PaletteTray))) {
		if ( visual_event(1) &  0x20 ) {
		(void) on_PaletteTray_event(_Context);

			}
		_Context->focus_item=2;
		return(256);
		}
	if (( mx >= 10 ) 
	&&  ( my >= 4 ) 
	&&  ( mx <= 34 ) 
	&&  ( my <= 28 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(10,4,24,24,vfh[1],27,28,get_toolbar_icon(_Context),strlen(get_toolbar_icon(_Context)),50);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(10,4,24,24,vfh[1],27,28,get_toolbar_icon(_Context),strlen(get_toolbar_icon(_Context)),48);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_Auto1726_event(_Context);

			}
		_Context->focus_item=3;
		return(256);
		}
	if (( mx >= 60 ) 
	&&  ( my >= 8 ) 
	&&  ( mx <= 120 ) 
	&&  ( my <= 28 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(60,8,60,20,vfh[2],16,0,_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]),34);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(60,8,60,20,vfh[2],16,0,_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]),32);
			}
		if ( visual_event(1) &  0x20 ) {
		{
		int result;
		if(visual_event(1)==_MIMO_MOVE)
		return(-1);
		switch((result=standard_file_menu())){
		case 27:
		case 13:
		return(-1);
		default:
		return(result);
		}
		}

			}
		_Context->focus_item=4;
		return(256);
		}
	if (( mx >= 120 ) 
	&&  ( my >= 8 ) 
	&&  ( mx <= 184 ) 
	&&  ( my <= 28 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(120,8,64,20,vfh[2],16,0,_Context->msg_Auto1742[_Context->language],strlen(_Context->msg_Auto1742[_Context->language]),34);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(120,8,64,20,vfh[2],16,0,_Context->msg_Auto1742[_Context->language],strlen(_Context->msg_Auto1742[_Context->language]),32);
			}
		if ( visual_event(1) &  0x20 ) {
		{
		int result;
		if(visual_event(1)==_MIMO_MOVE)
		return(-1);
		switch((result=standard_view_menu())){
		case 27:
		case 13:
		return(-1);
		default:
		return(result);
		}
		}

			}
		_Context->focus_item=5;
		return(256);
		}
	if (( mx >= 184 ) 
	&&  ( my >= 8 ) 
	&&  ( mx <= 256 ) 
	&&  ( my <= 28 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(184,8,72,20,vfh[2],16,0,_Context->msg_Auto1743[_Context->language],strlen(_Context->msg_Auto1743[_Context->language]),34);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(184,8,72,20,vfh[2],16,0,_Context->msg_Auto1743[_Context->language],strlen(_Context->msg_Auto1743[_Context->language]),32);
			}
		if ( visual_event(1) &  0x120 ) {
		int result;
		if(visual_event(1)==_MIMO_MOVE)
		return(-1);
		switch((result=standard_event_menu())){
		case 27:
		case 13:
		return(-1);
		default:
		return(result);
		}

			}
		_Context->focus_item=6;
		return(256);
		}
	if (( mx >= 256 ) 
	&&  ( my >= 8 ) 
	&&  ( mx <= 328 ) 
	&&  ( my <= 28 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(256,8,72,20,vfh[2],16,0,_Context->msg_Auto1744[_Context->language],strlen(_Context->msg_Auto1744[_Context->language]),34);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(256,8,72,20,vfh[2],16,0,_Context->msg_Auto1744[_Context->language],strlen(_Context->msg_Auto1744[_Context->language]),32);
			}
		if ( visual_event(1) &  0x20 ) {
		{
		int result;
		switch(visual_event(1)){
		case _MIMO_UP:
		switch((result=standard_option_menu())){
		case 27:
		case 13:
		return(-1);
		default:
		return(result);
		}
		default:
		return(-1);
		}
		}

			}
		_Context->focus_item=7;
		return(256);
		}
	if (( mx >= 336 ) 
	&&  ( my >= 8 ) 
	&&  ( mx <= 432 ) 
	&&  ( my <= 28 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(336,8,96,20,vfh[2],16,0,_Context->TitleOne->message[visual_national_language(-1)],strlen(_Context->TitleOne->message[visual_national_language(-1)]),34);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(336,8,96,20,vfh[2],16,0,_Context->TitleOne->message[visual_national_language(-1)],strlen(_Context->TitleOne->message[visual_national_language(-1)]),32);
			}
		if ( visual_event(1) &  0x20 ) {
		{
		int result=-1;
		if(!(_Context->TitleOne))
		return(-1);
		if(visual_event(1)==_MIMO_MOVE)
		return(-1);
		switch(_Context->value_LinkMenu){
		case 1:result=project_editor_menu();break;
		case 2:result=forms_editor_menu();break;
		case 3:result=image_editor_menu();break;
		case 4:result=text_editor_menu();break;
		case 5:result=trace_editor_menu();break;
		case 6:/*result=font_editor_menu();*/break;
		case 7:result=forms_widget_menu();break;
		}
		switch(result){
		case 27:
		case 13:
		return(-1);
		default:
		return(result);
		}
		}

			}
		_Context->focus_item=8;
		return(256);
		}
	if (( mx >= 432 ) 
	&&  ( my >= 8 ) 
	&&  ( mx <= 524 ) 
	&&  ( my <= 28 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(432,8,92,20,vfh[2],16,0,_Context->TitleTwo->message[visual_national_language(-1)],strlen(_Context->TitleTwo->message[visual_national_language(-1)]),34);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(432,8,92,20,vfh[2],16,0,_Context->TitleTwo->message[visual_national_language(-1)],strlen(_Context->TitleTwo->message[visual_national_language(-1)]),32);
			}
		if ( visual_event(1) &  0x20 ) {
		{
		int result=-1;
		if(!(_Context->TitleTwo))
		return(-1);
		if(visual_event(1)==_MIMO_MOVE)
		return(-1);
		switch(_Context->value_LinkTwo){
		case 1:result=project_editor_menu();break;
		case 2:result=forms_editor_menu();break;
		case 3:result=image_editor_menu();break;
		case 4:result=text_editor_menu();break;
		case 5:result=trace_editor_menu();break;
		case 6:/*result=font_editor_menu();*/break;
		case 7:result=forms_widget_menu();break;
		}
		switch(result){
		case 27:
		case 13:
		return(-1);
		default:
		return(result);
		}
		}

			}
		_Context->focus_item=9;
		return(256);
		}
	if (( mx >= 520 ) 
	&&  ( my >= 8 ) 
	&&  ( mx <= 616 ) 
	&&  ( my <= 28 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(520,8,96,20,vfh[2],16,0,_Context->TitleThree->message[visual_national_language(-1)],strlen(_Context->TitleThree->message[visual_national_language(-1)]),34);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(520,8,96,20,vfh[2],16,0,_Context->TitleThree->message[visual_national_language(-1)],strlen(_Context->TitleThree->message[visual_national_language(-1)]),32);
			}
		if ( visual_event(1) &  0x20 ) {
		{
		int result=-1;
		if(!(_Context->TitleThree))
		return(-1);
		if(visual_event(1)==_MIMO_MOVE)
		return(-1);
		switch(_Context->value_LinkThree){
		case 1:result=project_editor_menu();break;
		case 2:result=forms_editor_menu();break;
		case 3:result=image_editor_menu();break;
		case 4:result=text_editor_menu();break;
		case 5:result=trace_editor_menu();break;
		case 6:/*result=font_editor_menu();*/break;
		case 7:result=forms_widget_menu();break;
		}
		switch(result){
		case 27:
		case 13:
		return(-1);
		default:
		return(result);
		}
		}

			}
		_Context->focus_item=10;
		return(256);
		}
	if (( mx >= 316 ) 
	&&  ( my >= 4 ) 
	&&  ( mx <= 346 ) 
	&&  ( my <= 44 )) {
		}
	if (( mx >= 524 ) 
	&&  ( my >= 4 ) 
	&&  ( mx <= 554 ) 
	&&  ( my <= 44 )) {
		}
	if (( mx >= 428 ) 
	&&  ( my >= 4 ) 
	&&  ( mx <= 458 ) 
	&&  ( my <= 44 )) {
		}
	if ((mx >= 392 ) 
	&&  (my >= 4 ) 
	&&  (mx <= 424 ) 
	&&  (my <= 12 )) {
		_Context->focus_item=11;
		return(256);
		}
	if ((mx >= 488 ) 
	&&  (my >= 4 ) 
	&&  (mx <= 520 ) 
	&&  (my <= 12 )) {
		_Context->focus_item=12;
		return(256);
		}
	if ((mx >= 576 ) 
	&&  (my >= 4 ) 
	&&  (mx <= 608 ) 
	&&  (my <= 12 )) {
		_Context->focus_item=13;
		return(256);
		}
	if ((mx >= _Context->x_DebugTrigger ) 
	&&  (my >= _Context->y_DebugTrigger ) 
	&&  (mx <  (_Context->x_DebugTrigger+_Context->w_DebugTrigger)) 
	&&  (my <  (_Context->y_DebugTrigger+_Context->h_DebugTrigger))) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(_Context->x_DebugTrigger,_Context->y_DebugTrigger,_Context->w_DebugTrigger,_Context->h_DebugTrigger,_Context->fid_DebugTrigger,27,28,_Context->msg_DebugTrigger[_Context->language],strlen(_Context->msg_DebugTrigger[_Context->language]),50);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(_Context->x_DebugTrigger,_Context->y_DebugTrigger,_Context->w_DebugTrigger,_Context->h_DebugTrigger,_Context->fid_DebugTrigger,27,28,_Context->msg_DebugTrigger[_Context->language],strlen(_Context->msg_DebugTrigger[_Context->language]),48);
			}
		if ( visual_event(1) &  0x10 ) {
		(void) on_DebugTrigger_event(_Context);

			}
		_Context->focus_item=14;
		return(256);
		}
	if ((mx >= _Context->x_RuntimeTrigger ) 
	&&  (my >= _Context->y_RuntimeTrigger ) 
	&&  (mx <  (_Context->x_RuntimeTrigger+_Context->w_RuntimeTrigger)) 
	&&  (my <  (_Context->y_RuntimeTrigger+_Context->h_RuntimeTrigger))) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(_Context->x_RuntimeTrigger,_Context->y_RuntimeTrigger,_Context->w_RuntimeTrigger,_Context->h_RuntimeTrigger,_Context->fid_RuntimeTrigger,27,28,_Context->msg_RuntimeTrigger[_Context->language],strlen(_Context->msg_RuntimeTrigger[_Context->language]),50);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(_Context->x_RuntimeTrigger,_Context->y_RuntimeTrigger,_Context->w_RuntimeTrigger,_Context->h_RuntimeTrigger,_Context->fid_RuntimeTrigger,27,28,_Context->msg_RuntimeTrigger[_Context->language],strlen(_Context->msg_RuntimeTrigger[_Context->language]),48);
			}
		if ( visual_event(1) &  0x10 ) {
		(void) on_RuntimeTrigger_event(_Context);

			}
		_Context->focus_item=15;
		return(256);
		}
	if ((mx >= _Context->x_EditorTrigger ) 
	&&  (my >= _Context->y_EditorTrigger ) 
	&&  (mx <  (_Context->x_EditorTrigger+_Context->w_EditorTrigger)) 
	&&  (my <  (_Context->y_EditorTrigger+_Context->h_EditorTrigger))) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(_Context->x_EditorTrigger,_Context->y_EditorTrigger,_Context->w_EditorTrigger,_Context->h_EditorTrigger,_Context->fid_EditorTrigger,27,28,_Context->msg_EditorTrigger[_Context->language],strlen(_Context->msg_EditorTrigger[_Context->language]),50);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(_Context->x_EditorTrigger,_Context->y_EditorTrigger,_Context->w_EditorTrigger,_Context->h_EditorTrigger,_Context->fid_EditorTrigger,27,28,_Context->msg_EditorTrigger[_Context->language],strlen(_Context->msg_EditorTrigger[_Context->language]),48);
			}
		if ( visual_event(1) &  0x10 ) {
		(void) on_EditorTrigger_event(_Context);

			}
		_Context->focus_item=16;
		return(256);
		}
	if ((mx >= _Context->x_OtrTrigger ) 
	&&  (my >= _Context->y_OtrTrigger ) 
	&&  (mx <  (_Context->x_OtrTrigger+_Context->w_OtrTrigger)) 
	&&  (my <  (_Context->y_OtrTrigger+_Context->h_OtrTrigger))) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(_Context->x_OtrTrigger,_Context->y_OtrTrigger,_Context->w_OtrTrigger,_Context->h_OtrTrigger,_Context->fid_OtrTrigger,27,28,_Context->msg_OtrTrigger[_Context->language],strlen(_Context->msg_OtrTrigger[_Context->language]),50);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(_Context->x_OtrTrigger,_Context->y_OtrTrigger,_Context->w_OtrTrigger,_Context->h_OtrTrigger,_Context->fid_OtrTrigger,27,28,_Context->msg_OtrTrigger[_Context->language],strlen(_Context->msg_OtrTrigger[_Context->language]),48);
			}
		if ( visual_event(1) &  0x10 ) {
		(void) on_OtrTrigger_event(_Context);

			}
		_Context->focus_item=17;
		return(256);
		}
	if ((mx >= _Context->x_OldTrigger ) 
	&&  (my >= _Context->y_OldTrigger ) 
	&&  (mx <  (_Context->x_OldTrigger+_Context->w_OldTrigger)) 
	&&  (my <  (_Context->y_OldTrigger+_Context->h_OldTrigger))) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(_Context->x_OldTrigger,_Context->y_OldTrigger,_Context->w_OldTrigger,_Context->h_OldTrigger,_Context->fid_OldTrigger,27,28,_Context->msg_OldTrigger[_Context->language],strlen(_Context->msg_OldTrigger[_Context->language]),50);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(_Context->x_OldTrigger,_Context->y_OldTrigger,_Context->w_OldTrigger,_Context->h_OldTrigger,_Context->fid_OldTrigger,27,28,_Context->msg_OldTrigger[_Context->language],strlen(_Context->msg_OldTrigger[_Context->language]),48);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_OldTrigger_event(_Context);

			}
		_Context->focus_item=18;
		return(256);
		}
	if ((mx >= _Context->x_PaletteTrigger ) 
	&&  (my >= _Context->y_PaletteTrigger ) 
	&&  (mx <  (_Context->x_PaletteTrigger+_Context->w_PaletteTrigger)) 
	&&  (my <  (_Context->y_PaletteTrigger+_Context->h_PaletteTrigger))) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(_Context->x_PaletteTrigger,_Context->y_PaletteTrigger,_Context->w_PaletteTrigger,_Context->h_PaletteTrigger,_Context->fid_PaletteTrigger,27,28,get_palette_icon(_Context),strlen(get_palette_icon(_Context)),50);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(_Context->x_PaletteTrigger,_Context->y_PaletteTrigger,_Context->w_PaletteTrigger,_Context->h_PaletteTrigger,_Context->fid_PaletteTrigger,27,28,get_palette_icon(_Context),strlen(get_palette_icon(_Context)),48);
			}
		if ( visual_event(1) &  0x10 ) {
		(void) on_PaletteTrigger_event(_Context);

			}
		_Context->focus_item=19;
		return(256);
		}

	return(-1);
}


public	int	standard_main_menu_focus(struct standard_main_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x3 :
				/* Auto1726 */
				visual_button(10,4,24,24,vfh[1],27,28,get_toolbar_icon(_Context),strlen(get_toolbar_icon(_Context)),50);
				_Context->keycode = visual_getch();
				visual_button(10,4,24,24,vfh[1],27,28,get_toolbar_icon(_Context),strlen(get_toolbar_icon(_Context)),48);
				break;
			case	0x4 :
				/* Auto1741 */
				visual_button(60,8,60,20,vfh[2],16,0,_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(60,8,60,20,vfh[2],16,0,_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]),32);
				break;
			case	0x5 :
				/* Auto1742 */
				visual_button(120,8,64,20,vfh[2],16,0,_Context->msg_Auto1742[_Context->language],strlen(_Context->msg_Auto1742[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(120,8,64,20,vfh[2],16,0,_Context->msg_Auto1742[_Context->language],strlen(_Context->msg_Auto1742[_Context->language]),32);
				break;
			case	0x6 :
				/* Auto1743 */
				visual_button(184,8,72,20,vfh[2],16,0,_Context->msg_Auto1743[_Context->language],strlen(_Context->msg_Auto1743[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(184,8,72,20,vfh[2],16,0,_Context->msg_Auto1743[_Context->language],strlen(_Context->msg_Auto1743[_Context->language]),32);
				break;
			case	0x7 :
				/* Auto1744 */
				visual_button(256,8,72,20,vfh[2],16,0,_Context->msg_Auto1744[_Context->language],strlen(_Context->msg_Auto1744[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(256,8,72,20,vfh[2],16,0,_Context->msg_Auto1744[_Context->language],strlen(_Context->msg_Auto1744[_Context->language]),32);
				break;
			case	0x8 :
				/* Auto1745 */
				visual_button(336,8,96,20,vfh[2],16,0,_Context->TitleOne->message[visual_national_language(-1)],strlen(_Context->TitleOne->message[visual_national_language(-1)]),34);
				_Context->keycode = visual_getch();
				visual_button(336,8,96,20,vfh[2],16,0,_Context->TitleOne->message[visual_national_language(-1)],strlen(_Context->TitleOne->message[visual_national_language(-1)]),32);
				break;
			case	0x9 :
				/* Auto1746 */
				visual_button(432,8,92,20,vfh[2],16,0,_Context->TitleTwo->message[visual_national_language(-1)],strlen(_Context->TitleTwo->message[visual_national_language(-1)]),34);
				_Context->keycode = visual_getch();
				visual_button(432,8,92,20,vfh[2],16,0,_Context->TitleTwo->message[visual_national_language(-1)],strlen(_Context->TitleTwo->message[visual_national_language(-1)]),32);
				break;
			case	0xa :
				/* Auto1747 */
				visual_button(520,8,96,20,vfh[2],16,0,_Context->TitleThree->message[visual_national_language(-1)],strlen(_Context->TitleThree->message[visual_national_language(-1)]),34);
				_Context->keycode = visual_getch();
				visual_button(520,8,96,20,vfh[2],16,0,_Context->TitleThree->message[visual_national_language(-1)],strlen(_Context->TitleThree->message[visual_national_language(-1)]),32);
				break;
			case	0xe :
				/* DebugTrigger */
				visual_button(_Context->x_DebugTrigger,_Context->y_DebugTrigger,_Context->w_DebugTrigger,_Context->h_DebugTrigger,_Context->fid_DebugTrigger,27,28,_Context->msg_DebugTrigger[_Context->language],strlen(_Context->msg_DebugTrigger[_Context->language]),50);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_DebugTrigger,_Context->y_DebugTrigger,_Context->w_DebugTrigger,_Context->h_DebugTrigger,_Context->fid_DebugTrigger,27,28,_Context->msg_DebugTrigger[_Context->language],strlen(_Context->msg_DebugTrigger[_Context->language]),48);
				break;
			case	0xf :
				/* RuntimeTrigger */
				visual_button(_Context->x_RuntimeTrigger,_Context->y_RuntimeTrigger,_Context->w_RuntimeTrigger,_Context->h_RuntimeTrigger,_Context->fid_RuntimeTrigger,27,28,_Context->msg_RuntimeTrigger[_Context->language],strlen(_Context->msg_RuntimeTrigger[_Context->language]),50);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_RuntimeTrigger,_Context->y_RuntimeTrigger,_Context->w_RuntimeTrigger,_Context->h_RuntimeTrigger,_Context->fid_RuntimeTrigger,27,28,_Context->msg_RuntimeTrigger[_Context->language],strlen(_Context->msg_RuntimeTrigger[_Context->language]),48);
				break;
			case	0x10 :
				/* EditorTrigger */
				visual_button(_Context->x_EditorTrigger,_Context->y_EditorTrigger,_Context->w_EditorTrigger,_Context->h_EditorTrigger,_Context->fid_EditorTrigger,27,28,_Context->msg_EditorTrigger[_Context->language],strlen(_Context->msg_EditorTrigger[_Context->language]),50);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_EditorTrigger,_Context->y_EditorTrigger,_Context->w_EditorTrigger,_Context->h_EditorTrigger,_Context->fid_EditorTrigger,27,28,_Context->msg_EditorTrigger[_Context->language],strlen(_Context->msg_EditorTrigger[_Context->language]),48);
				break;
			case	0x11 :
				/* OtrTrigger */
				visual_button(_Context->x_OtrTrigger,_Context->y_OtrTrigger,_Context->w_OtrTrigger,_Context->h_OtrTrigger,_Context->fid_OtrTrigger,27,28,_Context->msg_OtrTrigger[_Context->language],strlen(_Context->msg_OtrTrigger[_Context->language]),50);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_OtrTrigger,_Context->y_OtrTrigger,_Context->w_OtrTrigger,_Context->h_OtrTrigger,_Context->fid_OtrTrigger,27,28,_Context->msg_OtrTrigger[_Context->language],strlen(_Context->msg_OtrTrigger[_Context->language]),48);
				break;
			case	0x12 :
				/* OldTrigger */
				visual_button(_Context->x_OldTrigger,_Context->y_OldTrigger,_Context->w_OldTrigger,_Context->h_OldTrigger,_Context->fid_OldTrigger,27,28,_Context->msg_OldTrigger[_Context->language],strlen(_Context->msg_OldTrigger[_Context->language]),50);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_OldTrigger,_Context->y_OldTrigger,_Context->w_OldTrigger,_Context->h_OldTrigger,_Context->fid_OldTrigger,27,28,_Context->msg_OldTrigger[_Context->language],strlen(_Context->msg_OldTrigger[_Context->language]),48);
				break;
			case	0x13 :
				/* PaletteTrigger */
				visual_button(_Context->x_PaletteTrigger,_Context->y_PaletteTrigger,_Context->w_PaletteTrigger,_Context->h_PaletteTrigger,_Context->fid_PaletteTrigger,27,28,get_palette_icon(_Context),strlen(get_palette_icon(_Context)),50);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_PaletteTrigger,_Context->y_PaletteTrigger,_Context->w_PaletteTrigger,_Context->h_PaletteTrigger,_Context->fid_PaletteTrigger,27,28,get_palette_icon(_Context),strlen(get_palette_icon(_Context)),48);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			standard_main_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=19;
			standard_main_menu_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=standard_main_menu_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1740 */
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_Auto1740_event(_Context)) != -1) break;

							}
						continue;
					case	0x2 :
						/* PaletteTray */
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_PaletteTray_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Auto1726 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(10,4,24,24,vfh[1],27,28,get_toolbar_icon(_Context),strlen(get_toolbar_icon(_Context)),50);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(10,4,24,24,vfh[1],27,28,get_toolbar_icon(_Context),strlen(get_toolbar_icon(_Context)),48);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1726_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto1741 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(60,8,60,20,vfh[2],16,0,_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(60,8,60,20,vfh[2],16,0,_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						{
						int result;
						if(visual_event(1)==_MIMO_MOVE)
						return(-1);
						switch((result=standard_file_menu())){
						case 27:
						case 13:
						return(-1);
						default:
						return(result);
						}
						}

							}
						continue;
					case	0x5 :
						/* Auto1742 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(120,8,64,20,vfh[2],16,0,_Context->msg_Auto1742[_Context->language],strlen(_Context->msg_Auto1742[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(120,8,64,20,vfh[2],16,0,_Context->msg_Auto1742[_Context->language],strlen(_Context->msg_Auto1742[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						{
						int result;
						if(visual_event(1)==_MIMO_MOVE)
						return(-1);
						switch((result=standard_view_menu())){
						case 27:
						case 13:
						return(-1);
						default:
						return(result);
						}
						}

							}
						continue;
					case	0x6 :
						/* Auto1743 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(184,8,72,20,vfh[2],16,0,_Context->msg_Auto1743[_Context->language],strlen(_Context->msg_Auto1743[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(184,8,72,20,vfh[2],16,0,_Context->msg_Auto1743[_Context->language],strlen(_Context->msg_Auto1743[_Context->language]),32);
							}
						if ( visual_event(1) &  0x120 ) {
						int result;
						if(visual_event(1)==_MIMO_MOVE)
						return(-1);
						switch((result=standard_event_menu())){
						case 27:
						case 13:
						return(-1);
						default:
						return(result);
						}

							}
						continue;
					case	0x7 :
						/* Auto1744 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(256,8,72,20,vfh[2],16,0,_Context->msg_Auto1744[_Context->language],strlen(_Context->msg_Auto1744[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(256,8,72,20,vfh[2],16,0,_Context->msg_Auto1744[_Context->language],strlen(_Context->msg_Auto1744[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						{
						int result;
						switch(visual_event(1)){
						case _MIMO_UP:
						switch((result=standard_option_menu())){
						case 27:
						case 13:
						return(-1);
						default:
						return(result);
						}
						default:
						return(-1);
						}
						}

							}
						continue;
					case	0x8 :
						/* Auto1745 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(336,8,96,20,vfh[2],16,0,_Context->TitleOne->message[visual_national_language(-1)],strlen(_Context->TitleOne->message[visual_national_language(-1)]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(336,8,96,20,vfh[2],16,0,_Context->TitleOne->message[visual_national_language(-1)],strlen(_Context->TitleOne->message[visual_national_language(-1)]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						{
						int result=-1;
						if(!(_Context->TitleOne))
						return(-1);
						if(visual_event(1)==_MIMO_MOVE)
						return(-1);
						switch(_Context->value_LinkMenu){
						case 1:result=project_editor_menu();break;
						case 2:result=forms_editor_menu();break;
						case 3:result=image_editor_menu();break;
						case 4:result=text_editor_menu();break;
						case 5:result=trace_editor_menu();break;
						case 6:/*result=font_editor_menu();*/break;
						case 7:result=forms_widget_menu();break;
						}
						switch(result){
						case 27:
						case 13:
						return(-1);
						default:
						return(result);
						}
						}

							}
						continue;
					case	0x9 :
						/* Auto1746 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(432,8,92,20,vfh[2],16,0,_Context->TitleTwo->message[visual_national_language(-1)],strlen(_Context->TitleTwo->message[visual_national_language(-1)]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(432,8,92,20,vfh[2],16,0,_Context->TitleTwo->message[visual_national_language(-1)],strlen(_Context->TitleTwo->message[visual_national_language(-1)]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						{
						int result=-1;
						if(!(_Context->TitleTwo))
						return(-1);
						if(visual_event(1)==_MIMO_MOVE)
						return(-1);
						switch(_Context->value_LinkTwo){
						case 1:result=project_editor_menu();break;
						case 2:result=forms_editor_menu();break;
						case 3:result=image_editor_menu();break;
						case 4:result=text_editor_menu();break;
						case 5:result=trace_editor_menu();break;
						case 6:/*result=font_editor_menu();*/break;
						case 7:result=forms_widget_menu();break;
						}
						switch(result){
						case 27:
						case 13:
						return(-1);
						default:
						return(result);
						}
						}

							}
						continue;
					case	0xa :
						/* Auto1747 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(520,8,96,20,vfh[2],16,0,_Context->TitleThree->message[visual_national_language(-1)],strlen(_Context->TitleThree->message[visual_national_language(-1)]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(520,8,96,20,vfh[2],16,0,_Context->TitleThree->message[visual_national_language(-1)],strlen(_Context->TitleThree->message[visual_national_language(-1)]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						{
						int result=-1;
						if(!(_Context->TitleThree))
						return(-1);
						if(visual_event(1)==_MIMO_MOVE)
						return(-1);
						switch(_Context->value_LinkThree){
						case 1:result=project_editor_menu();break;
						case 2:result=forms_editor_menu();break;
						case 3:result=image_editor_menu();break;
						case 4:result=text_editor_menu();break;
						case 5:result=trace_editor_menu();break;
						case 6:/*result=font_editor_menu();*/break;
						case 7:result=forms_widget_menu();break;
						}
						switch(result){
						case 27:
						case 13:
						return(-1);
						default:
						return(result);
						}
						}

							}
						continue;
					case	0xb :
						/* LinkMenu */
						continue;
					case	0xc :
						/* LinkTwo */
						continue;
					case	0xd :
						/* LinkThree */
						continue;
					case	0xe :
						/* DebugTrigger */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_DebugTrigger,_Context->y_DebugTrigger,_Context->w_DebugTrigger,_Context->h_DebugTrigger,_Context->fid_DebugTrigger,27,28,_Context->msg_DebugTrigger[_Context->language],strlen(_Context->msg_DebugTrigger[_Context->language]),50);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_DebugTrigger,_Context->y_DebugTrigger,_Context->w_DebugTrigger,_Context->h_DebugTrigger,_Context->fid_DebugTrigger,27,28,_Context->msg_DebugTrigger[_Context->language],strlen(_Context->msg_DebugTrigger[_Context->language]),48);
							}
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_DebugTrigger_event(_Context)) != -1) break;

							}
						continue;
					case	0xf :
						/* RuntimeTrigger */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_RuntimeTrigger,_Context->y_RuntimeTrigger,_Context->w_RuntimeTrigger,_Context->h_RuntimeTrigger,_Context->fid_RuntimeTrigger,27,28,_Context->msg_RuntimeTrigger[_Context->language],strlen(_Context->msg_RuntimeTrigger[_Context->language]),50);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_RuntimeTrigger,_Context->y_RuntimeTrigger,_Context->w_RuntimeTrigger,_Context->h_RuntimeTrigger,_Context->fid_RuntimeTrigger,27,28,_Context->msg_RuntimeTrigger[_Context->language],strlen(_Context->msg_RuntimeTrigger[_Context->language]),48);
							}
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_RuntimeTrigger_event(_Context)) != -1) break;

							}
						continue;
					case	0x10 :
						/* EditorTrigger */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_EditorTrigger,_Context->y_EditorTrigger,_Context->w_EditorTrigger,_Context->h_EditorTrigger,_Context->fid_EditorTrigger,27,28,_Context->msg_EditorTrigger[_Context->language],strlen(_Context->msg_EditorTrigger[_Context->language]),50);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_EditorTrigger,_Context->y_EditorTrigger,_Context->w_EditorTrigger,_Context->h_EditorTrigger,_Context->fid_EditorTrigger,27,28,_Context->msg_EditorTrigger[_Context->language],strlen(_Context->msg_EditorTrigger[_Context->language]),48);
							}
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_EditorTrigger_event(_Context)) != -1) break;

							}
						continue;
					case	0x11 :
						/* OtrTrigger */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_OtrTrigger,_Context->y_OtrTrigger,_Context->w_OtrTrigger,_Context->h_OtrTrigger,_Context->fid_OtrTrigger,27,28,_Context->msg_OtrTrigger[_Context->language],strlen(_Context->msg_OtrTrigger[_Context->language]),50);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_OtrTrigger,_Context->y_OtrTrigger,_Context->w_OtrTrigger,_Context->h_OtrTrigger,_Context->fid_OtrTrigger,27,28,_Context->msg_OtrTrigger[_Context->language],strlen(_Context->msg_OtrTrigger[_Context->language]),48);
							}
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_OtrTrigger_event(_Context)) != -1) break;

							}
						continue;
					case	0x12 :
						/* OldTrigger */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_OldTrigger,_Context->y_OldTrigger,_Context->w_OldTrigger,_Context->h_OldTrigger,_Context->fid_OldTrigger,27,28,_Context->msg_OldTrigger[_Context->language],strlen(_Context->msg_OldTrigger[_Context->language]),50);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_OldTrigger,_Context->y_OldTrigger,_Context->w_OldTrigger,_Context->h_OldTrigger,_Context->fid_OldTrigger,27,28,_Context->msg_OldTrigger[_Context->language],strlen(_Context->msg_OldTrigger[_Context->language]),48);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_OldTrigger_event(_Context)) != -1) break;

							}
						continue;
					case	0x13 :
						/* PaletteTrigger */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_PaletteTrigger,_Context->y_PaletteTrigger,_Context->w_PaletteTrigger,_Context->h_PaletteTrigger,_Context->fid_PaletteTrigger,27,28,get_palette_icon(_Context),strlen(get_palette_icon(_Context)),50);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_PaletteTrigger,_Context->y_PaletteTrigger,_Context->w_PaletteTrigger,_Context->h_PaletteTrigger,_Context->fid_PaletteTrigger,27,28,get_palette_icon(_Context),strlen(get_palette_icon(_Context)),48);
							}
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_PaletteTrigger_event(_Context)) != -1) break;

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
				_Context->focus_item=19;
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

public	int	standard_main_menu()
{
	int	status=0;
	struct standard_main_menu_context * _Context=(struct standard_main_menu_context*) 0;
	status = standard_main_menu_create(&_Context);
	if ( status != 0) return(status);
	status = standard_main_menu_show(_Context);
	status = standard_main_menu_focus(_Context);
	status = standard_main_menu_hide(_Context);
	status = standard_main_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _mainmenu_c */
