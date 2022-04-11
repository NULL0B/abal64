
#ifndef _vstdfont_c
#define _vstdfont_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vstdfont.xml                                             */
/* Target         : vstdfont.c                                               */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Window   ""
#define fr__Window   ""
#define it__Window   ""
#define es__Window   ""
#define de__Window   ""
#define nl__Window   ""
#define pt__Window   ""
#define xx__Window   ""
#define en_ExportFont   "Export"
#define en__ExportFont   ""
#define en_ImportFont   "Import"
#define en__ImportFont   ""
#define en_Auto3592   "+"
#define fr_Auto3592   "+"
#define it_Auto3592   "+"
#define es_Auto3592   "+"
#define de_Auto3592   "+"
#define nl_Auto3592   "+"
#define pt_Auto3592   "+"
#define xx_Auto3592   "+"
#define en_Auto3593   "+"
#define fr_Auto3593   "+"
#define it_Auto3593   "+"
#define es_Auto3593   "+"
#define de_Auto3593   "+"
#define nl_Auto3593   "+"
#define pt_Auto3593   "+"
#define xx_Auto3593   "+"
#define en_Auto3594   "-"
#define fr_Auto3594   "-"
#define it_Auto3594   "-"
#define es_Auto3594   "-"
#define de_Auto3594   "-"
#define nl_Auto3594   "-"
#define pt_Auto3594   "-"
#define xx_Auto3594   "-"
#define en_Auto3595   "-"
#define fr_Auto3595   "-"
#define it_Auto3595   "-"
#define es_Auto3595   "-"
#define de_Auto3595   "-"
#define nl_Auto3595   "-"
#define pt_Auto3595   "-"
#define xx_Auto3595   "-"
#define en_Auto3596   "+"
#define fr_Auto3596   "+"
#define it_Auto3596   "+"
#define es_Auto3596   "+"
#define de_Auto3596   "+"
#define nl_Auto3596   "+"
#define pt_Auto3596   "+"
#define xx_Auto3596   "+"
#define en_Auto3597   "+"
#define fr_Auto3597   "+"
#define it_Auto3597   "+"
#define es_Auto3597   "+"
#define de_Auto3597   "+"
#define nl_Auto3597   "+"
#define pt_Auto3597   "+"
#define xx_Auto3597   "+"
#define en_Auto3598   "-"
#define fr_Auto3598   "-"
#define it_Auto3598   "-"
#define es_Auto3598   "-"
#define de_Auto3598   "-"
#define nl_Auto3598   "-"
#define pt_Auto3598   "-"
#define xx_Auto3598   "-"
#define en_Auto3599   "-"
#define fr_Auto3599   "-"
#define it_Auto3599   "-"
#define es_Auto3599   "-"
#define de_Auto3599   "-"
#define nl_Auto3599   "-"
#define pt_Auto3599   "-"
#define xx_Auto3599   "-"
#define en_PreviousCharacter   "<<"
#define fr_PreviousCharacter   "<<"
#define it_PreviousCharacter   "<<"
#define es_PreviousCharacter   "<<"
#define de_PreviousCharacter   "<<"
#define nl_PreviousCharacter   "<<"
#define pt_PreviousCharacter   "<<"
#define xx_PreviousCharacter   "<<"
#define en_NextCharacter   ">>"
#define fr_NextCharacter   ">>"
#define it_NextCharacter   ">>"
#define es_NextCharacter   ">>"
#define de_NextCharacter   ">>"
#define nl_NextCharacter   ">>"
#define pt_NextCharacter   ">>"
#define xx_NextCharacter   ">>"
#define en_CopyCharacter   "Copy"
#define fr_CopyCharacter   "Copier"
#define it_CopyCharacter   "Copy"
#define es_CopyCharacter   "Copy"
#define de_CopyCharacter   "Copy"
#define nl_CopyCharacter   "Copy"
#define pt_CopyCharacter   "Copy"
#define xx_CopyCharacter   "Copy"
#define en_PasteCharacter   "Paste"
#define fr_PasteCharacter   "Coller"
#define it_PasteCharacter   "Paste"
#define es_PasteCharacter   "Paste"
#define de_PasteCharacter   "Paste"
#define nl_PasteCharacter   "Paste"
#define pt_PasteCharacter   "Paste"
#define xx_PasteCharacter   "Paste"
#define en__PasteCharacter   ""
#define en_FontSave   "Save"
#define fr_FontSave   "Sauv."
#define it_FontSave   "Save"
#define es_FontSave   "Save"
#define de_FontSave   "Save"
#define nl_FontSave   "Save"
#define pt_FontSave   "Save"
#define xx_FontSave   "Save"
#define en__FontSave   ""
#define en_FontReSize   "ReSize"
#define fr_FontReSize   "Taille"
#define it_FontReSize   "Calc"
#define es_FontReSize   "Calc"
#define de_FontReSize   "Calc"
#define nl_FontReSize   "Calc"
#define pt_FontReSize   "Calc"
#define xx_FontReSize   "Calc"
#define en_FontExport   "Export"
#define fr_FontExport   "Exporter"
#define it_FontExport   "Export"
#define es_FontExport   "Export"
#define de_FontExport   "Export"
#define nl_FontExport   "Export"
#define pt_FontExport   "Export"
#define xx_FontExport   "Export"
#define en_FontFrame   "Frame"
#define fr_FontFrame   "Cadre"
#define it_FontFrame   "Frame"
#define es_FontFrame   "Frame"
#define de_FontFrame   "Frame"
#define nl_FontFrame   "Frame"
#define pt_FontFrame   "Frame"
#define xx_FontFrame   "Frame"
#define en_FontLoad   "Load"
#define fr_FontLoad   "Charger"
#define it_FontLoad   "Load"
#define es_FontLoad   "Load"
#define de_FontLoad   "Load"
#define nl_FontLoad   "Load"
#define pt_FontLoad   "Load"
#define xx_FontLoad   "Load"
#define en__FontLoad   ""
#define en_Character   ""
#define en_CharacterHex   ""
#define en_CharacterDec   ""
#define en__FontName   ""
#define en_FontCellSwitch   "Font"
#define fr_FontCellSwitch   "Police"
#define it_FontCellSwitch   "Font"
#define es_FontCellSwitch   "Font"
#define de_FontCellSwitch   "Font"
#define nl_FontCellSwitch   "Font"
#define pt_FontCellSwitch   "Font"
#define xx_FontCellSwitch   "Font"
#define en__FontCellSwitch   ""
#define en_FontSwap   "fontswap"
#define fr_FontSwap   "echange"
#define it_FontSwap   "<->"
#define es_FontSwap   "<->"
#define de_FontSwap   "<->"
#define nl_FontSwap   "<->"
#define pt_FontSwap   "<->"
#define xx_FontSwap   "<->"
#define en__FontSwap   ""
#define fr__FontSwap   ""
#define it__FontSwap   ""
#define es__FontSwap   ""
#define de__FontSwap   ""
#define nl__FontSwap   ""
#define pt__FontSwap   ""
#define xx__FontSwap   ""
#define en_CellSwap   "cellswap"
#define fr_CellSwap   "cellswap"
#define it_CellSwap   "cellswap"
#define es_CellSwap   "cellswap"
#define de_CellSwap   "cellswap"
#define nl_CellSwap   "cellswap"
#define pt_CellSwap   "cellswap"
#define xx_CellSwap   "cellswap"
#define en__CellSwap   ""
#define fr__CellSwap   ""
#define it__CellSwap   ""
#define es__CellSwap   ""
#define de__CellSwap   ""
#define nl__CellSwap   ""
#define pt__CellSwap   ""
#define xx__CellSwap   ""
#define en_FontWidth   ""
#define en_FontHeight   ""
#define en__FontFile   ""
#define en_HqNameList   ""
#define en__HqNameList   ""
#define en__HqNames   ""
#define en_SetHqFont   "HQ"
#define fr_SetHqFont   "HQ"
#define it_SetHqFont   "HQ"
#define es_SetHqFont   "HQ"
#define de_SetHqFont   "HQ"
#define nl_SetHqFont   "HQ"
#define pt_SetHqFont   "HQ"
#define xx_SetHqFont   "HQ"
#define en__SetHqFont   ""
#define fr__SetHqFont   ""
#define it__SetHqFont   ""
#define es__SetHqFont   ""
#define de__SetHqFont   ""
#define nl__SetHqFont   ""
#define pt__SetHqFont   ""
#define xx__SetHqFont   ""
#define en_FixedFont   "Fixed|Proportional"
#define fr_FixedFont   "Fixe|Proportionelle"
#define it_FixedFont   "Fixed|Proportional"
#define es_FixedFont   "Fixed|Proportional"
#define de_FixedFont   "Fixed|Proportional"
#define nl_FixedFont   "Fixed|Proportional"
#define pt_FixedFont   "Fixed|Proportional"
#define xx_FixedFont   "Fixed|Proportional"
#define en__FixedFont   ""
#define en_CrossControl   "Cursor"
#define fr_CrossControl   "Curseur"
#define it_CrossControl   "Cursor"
#define es_CrossControl   "Cursor"
#define de_CrossControl   "Cursor"
#define nl_CrossControl   "Cursor"
#define pt_CrossControl   "Cursor"
#define xx_CrossControl   "Cursor"
#define en__CrossControl   ""
#define en_Column   ""
#define en_Row   ""
#define en_Auto3600   "Width"
#define fr_Auto3600   "Width"
#define it_Auto3600   "Width"
#define es_Auto3600   "Width"
#define de_Auto3600   "Width"
#define nl_Auto3600   "Width"
#define pt_Auto3600   "Width"
#define xx_Auto3600   "Width"
#define en__Auto3600   ""
#define fr__Auto3600   ""
#define it__Auto3600   ""
#define es__Auto3600   ""
#define de__Auto3600   ""
#define nl__Auto3600   ""
#define pt__Auto3600   ""
#define xx__Auto3600   ""
#define en_Auto3601   "Height"
#define fr_Auto3601   "Haut."
#define it_Auto3601   "Height"
#define es_Auto3601   "Height"
#define de_Auto3601   "Height"
#define nl_Auto3601   "Height"
#define pt_Auto3601   "Height"
#define xx_Auto3601   "Height"
#define en__Auto3601   ""
#define en_Auto3602   "Character"
#define fr_Auto3602   "CaractŠre"
#define it_Auto3602   "Character"
#define es_Auto3602   "Character"
#define de_Auto3602   "Character"
#define nl_Auto3602   "Character"
#define pt_Auto3602   "Character"
#define xx_Auto3602   "Character"
#define en__Auto3602   ""
#define en_Auto3603   "Decimal"
#define fr_Auto3603   "D‚cimal"
#define it_Auto3603   "Decimal"
#define es_Auto3603   "Decimal"
#define de_Auto3603   "Decimal"
#define nl_Auto3603   "Decimal"
#define pt_Auto3603   "Decimal"
#define xx_Auto3603   "Decimal"
#define en__Auto3603   ""
#define en_Auto3604   "Hex"
#define fr_Auto3604   "Hex"
#define it_Auto3604   "Hex"
#define es_Auto3604   "Hex"
#define de_Auto3604   "Hex"
#define nl_Auto3604   "Hex"
#define pt_Auto3604   "Hex"
#define xx_Auto3604   "Hex"
#define en__Auto3604   ""
#define en_Auto3605   "Width"
#define fr_Auto3605   "Larg."
#define it_Auto3605   "Width"
#define es_Auto3605   "Width"
#define de_Auto3605   "Width"
#define nl_Auto3605   "Width"
#define pt_Auto3605   "Width"
#define xx_Auto3605   "Width"
#define en_Auto3606   "Height"
#define fr_Auto3606   "Haut."
#define it_Auto3606   "Height"
#define es_Auto3606   "Height"
#define de_Auto3606   "Height"
#define nl_Auto3606   "Height"
#define pt_Auto3606   "Height"
#define xx_Auto3606   "Height"
#define en_FontTable   ""
#define en_CharacterData   ""
#define en__CharacterData   ""
#define en_vBar   ""
#define en_hBar   ""
#define en__hBar   ""
#define en_CharacterWidth   ""
#define en_CharacterHeight   ""

private struct standard_font_editor_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Window[8];
	char * hint_Window[8];
	int	x_Window;
	int	y_Window;
	int	w_Window;
	int	h_Window;
	char * msg_ExportFont[8];
	int	trigger_ExportFont;
	char * hint_ExportFont[8];
	char * msg_ImportFont[8];
	int	trigger_ImportFont;
	char * hint_ImportFont[8];
	char * msg_Auto3592[8];
	int	trigger_Auto3592;
	char * hint_Auto3592[8];
	char * msg_Auto3593[8];
	int	trigger_Auto3593;
	char * hint_Auto3593[8];
	char * msg_Auto3594[8];
	int	trigger_Auto3594;
	char * hint_Auto3594[8];
	char * msg_Auto3595[8];
	int	trigger_Auto3595;
	char * hint_Auto3595[8];
	char * msg_Auto3596[8];
	int	trigger_Auto3596;
	char * hint_Auto3596[8];
	char * msg_Auto3597[8];
	int	trigger_Auto3597;
	char * hint_Auto3597[8];
	char * msg_Auto3598[8];
	int	trigger_Auto3598;
	char * hint_Auto3598[8];
	char * msg_Auto3599[8];
	int	trigger_Auto3599;
	char * hint_Auto3599[8];
	char * msg_PreviousCharacter[8];
	int	trigger_PreviousCharacter;
	char * hint_PreviousCharacter[8];
	char * msg_NextCharacter[8];
	int	trigger_NextCharacter;
	char * hint_NextCharacter[8];
	char * msg_CopyCharacter[8];
	int	trigger_CopyCharacter;
	char * hint_CopyCharacter[8];
	char * msg_PasteCharacter[8];
	int	trigger_PasteCharacter;
	char * hint_PasteCharacter[8];
	char * msg_FontSave[8];
	int	trigger_FontSave;
	char * hint_FontSave[8];
	char * msg_FontReSize[8];
	int	trigger_FontReSize;
	char * hint_FontReSize[8];
	char * msg_FontExport[8];
	int	trigger_FontExport;
	char * hint_FontExport[8];
	char * msg_FontFrame[8];
	int	trigger_FontFrame;
	char * hint_FontFrame[8];
	char * msg_FontLoad[8];
	int	trigger_FontLoad;
	char * hint_FontLoad[8];
	char * hint_Character[8];
	char	buffer_Character[3];
	char * hint_CharacterHex[8];
	char	buffer_CharacterHex[4];
	char * hint_CharacterDec[8];
	char	buffer_CharacterDec[5];
	char * msg_FontName[8];
	char * hint_FontName[8];
	int	value_FontName;
	char * msg_FontCellSwitch[8];
	int	trigger_FontCellSwitch;
	char * hint_FontCellSwitch[8];
	int	value_FontCellSwitch;
	char * msg_FontSwap[8];
	int	trigger_FontSwap;
	char * hint_FontSwap[8];
	char * msg_CellSwap[8];
	int	trigger_CellSwap;
	char * hint_CellSwap[8];
	char * hint_FontWidth[8];
	char	buffer_FontWidth[5];
	char * hint_FontHeight[8];
	char	buffer_FontHeight[5];
	char * msg_FontFile[8];
	char * hint_FontFile[8];
	int	value_FontFile;
	char * hint_HqNameList[8];
	char	buffer_HqNameList[1701];
	char * msg_HqNames[8];
	char * hint_HqNames[8];
	int	value_HqNames;
	char * msg_SetHqFont[8];
	int	trigger_SetHqFont;
	char * hint_SetHqFont[8];
	char * msg_FixedFont[8];
	char * hint_FixedFont[8];
	int	value_FixedFont;
	char * msg_CrossControl[8];
	int	trigger_CrossControl;
	char * hint_CrossControl[8];
	int	value_CrossControl;
	char * hint_Column[8];
	char	buffer_Column[8];
	char * hint_Row[8];
	char	buffer_Row[8];
	char * msg_Auto3600[8];
	char * hint_Auto3600[8];
	char * msg_Auto3601[8];
	char * hint_Auto3601[8];
	char * msg_Auto3602[8];
	char * hint_Auto3602[8];
	char * msg_Auto3603[8];
	char * hint_Auto3603[8];
	char * msg_Auto3604[8];
	char * hint_Auto3604[8];
	char * msg_Auto3605[8];
	char * hint_Auto3605[8];
	char * msg_Auto3606[8];
	char * hint_Auto3606[8];
	char * hint_FontTable[8];
	int	x_FontTable;
	int	y_FontTable;
	int	w_FontTable;
	int	h_FontTable;
	int	fg_FontTable;
	int	bg_FontTable;
	int	fid_FontTable;
	char	buffer_FontTable[1105];
	char * hint_CharacterData[8];
	int	x_CharacterData;
	int	y_CharacterData;
	int	w_CharacterData;
	int	h_CharacterData;
	int	fg_CharacterData;
	int	bg_CharacterData;
	int	fid_CharacterData;
	char	buffer_CharacterData[1176];
	char * hint_vBar[8];
	int	value_vBar;
	int	limit_vBar;
	int	max_vBar;
	char * hint_hBar[8];
	int	value_hBar;
	int	limit_hBar;
	int	max_hBar;
	char * hint_CharacterWidth[8];
	char	buffer_CharacterWidth[5];
	char * hint_CharacterHeight[8];
	char	buffer_CharacterHeight[5];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];
private int on_Column_create(struct standard_font_editor_context * _Context);
private int on_Row_create(struct standard_font_editor_context * _Context);
private int on_FontTable_create(struct standard_font_editor_context * _Context);
private int on_CharacterData_create(struct standard_font_editor_context * _Context);
private int on_Character_show(struct standard_font_editor_context * _Context);
private int on_CharacterHex_show(struct standard_font_editor_context * _Context);
private int on_FontWidth_show(struct standard_font_editor_context * _Context);
private int on_FontHeight_show(struct standard_font_editor_context * _Context);
private int on_HqNames_show(struct standard_font_editor_context * _Context);
private int on_FontTable_show(struct standard_font_editor_context * _Context);
private int on_CharacterData_show(struct standard_font_editor_context * _Context);
private int on_CharacterWidth_show(struct standard_font_editor_context * _Context);
private int on_CharacterHeight_show(struct standard_font_editor_context * _Context);
private int on_CharacterData_getfocus(struct standard_font_editor_context * _Context);
private int on_CharacterDec_losefocus(struct standard_font_editor_context * _Context);
private int on_FontName_losefocus(struct standard_font_editor_context * _Context);
private int on_ExportFont_event(struct standard_font_editor_context * _Context);
private int on_ImportFont_event(struct standard_font_editor_context * _Context);
private int on_Auto3592_event(struct standard_font_editor_context * _Context);
private int on_Auto3593_event(struct standard_font_editor_context * _Context);
private int on_Auto3594_event(struct standard_font_editor_context * _Context);
private int on_Auto3595_event(struct standard_font_editor_context * _Context);
private int on_Auto3596_event(struct standard_font_editor_context * _Context);
private int on_Auto3597_event(struct standard_font_editor_context * _Context);
private int on_Auto3598_event(struct standard_font_editor_context * _Context);
private int on_Auto3599_event(struct standard_font_editor_context * _Context);
private int on_PreviousCharacter_event(struct standard_font_editor_context * _Context);
private int on_NextCharacter_event(struct standard_font_editor_context * _Context);
private int on_CopyCharacter_event(struct standard_font_editor_context * _Context);
private int on_PasteCharacter_event(struct standard_font_editor_context * _Context);
private int on_FontSave_event(struct standard_font_editor_context * _Context);
private int on_FontReSize_event(struct standard_font_editor_context * _Context);
private int on_FontExport_event(struct standard_font_editor_context * _Context);
private int on_FontFrame_event(struct standard_font_editor_context * _Context);
private int on_FontLoad_event(struct standard_font_editor_context * _Context);
private int on_FontSwap_event(struct standard_font_editor_context * _Context);
private int on_CellSwap_event(struct standard_font_editor_context * _Context);
private int on_HqNameList_event(struct standard_font_editor_context * _Context);
private int on_SetHqFont_event(struct standard_font_editor_context * _Context);
private int on_FixedFont_event(struct standard_font_editor_context * _Context);
private int on_CrossControl_event(struct standard_font_editor_context * _Context);
private int on_FontTable_event(struct standard_font_editor_context * _Context);
private int on_CharacterData_event(struct standard_font_editor_context * _Context);
private int on_vBar_event(struct standard_font_editor_context * _Context);
private int on_hBar_event(struct standard_font_editor_context * _Context);
short	stdinput(struct standard_font_editor_context * _Context);
static void	crosshair(struct standard_font_editor_context * _Context);
static void	changepixel(struct standard_font_editor_context * _Context);
static char	 * check_windows_info(struct standard_font_editor_context * _Context,char * sptr);

/*	------------------	*/
/*	s t d i n p u t ()	*/
/*	------------------	*/
short	stdinput(struct standard_font_editor_context * _Context){
	int c;
	int event;
	int e;
	int x;
	int ch;
	int cw;
	int y;
	while(1){
	switch((event=visual_getch())){
	case 256:
	return(event);
	case 6:
	crosshair(_Context);
	x=atoi(_Context->buffer_Column);
	cw=atoi(_Context->buffer_CharacterWidth);
	if(x<cw)
	x++;
	else x=1;
	sprintf(_Context->buffer_Column,"%u",x);
	visual_frame(300,80,56+2,16+2,5);
visual_text(300+1,80+1,56,16,vfh[1],27,28,_Context->buffer_Column,7,3);
;
	crosshair(_Context);
	continue;
	case 0x0003:
	crosshair(_Context);
	on_NextCharacter_event(_Context);
	crosshair(_Context);
	case 0x0012:
	crosshair(_Context);
	on_PreviousCharacter_event(_Context);
	crosshair(_Context);
	case 8:
	crosshair(_Context);
	x=atoi(_Context->buffer_Column);
	cw=atoi(_Context->buffer_CharacterWidth);
	if(x>1)
	x--;
	else x=cw;
	sprintf(_Context->buffer_Column,"%u",x);
	visual_frame(300,80,56+2,16+2,5);
visual_text(300+1,80+1,56,16,vfh[1],27,28,_Context->buffer_Column,7,3);
;
	crosshair(_Context);
	continue;
	case 5:
	crosshair(_Context);
	y=atoi(_Context->buffer_Row);
	ch=atoi(_Context->buffer_CharacterHeight);
	if(y<ch)
	y++;
	else y=1;
	sprintf(_Context->buffer_Row,"%u",y);
	visual_frame(300,100,56+2,16+2,5);
visual_text(300+1,100+1,56,16,vfh[1],27,28,_Context->buffer_Row,7,3);
;
	crosshair(_Context);
	continue;
	case 11:
	crosshair(_Context);
	y=atoi(_Context->buffer_Row);
	ch=atoi(_Context->buffer_CharacterHeight);
	if(y>1)
	y--;
	else y=ch;
	sprintf(_Context->buffer_Row,"%u",y);
	visual_frame(300,100,56+2,16+2,5);
visual_text(300+1,100+1,56,16,vfh[1],27,28,_Context->buffer_Row,7,3);
;
	crosshair(_Context);
	continue;
	case 32:
	changepixel(_Context);
	on_CharacterData_show(_Context);
	continue;
	case 0x0019:/*Ctrl Y:delete line*/
	if(!(_Context->value_FontCellSwitch))
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),20,atoi(_Context->buffer_Row));
	else{
	for(c=0;c<256;c++)
	guifontfunction(_Context->value_FontName+1,c,20,atoi(_Context->buffer_Row));
	}
		standard_font_editor_show(_Context);
;
	continue;
	case 0x000E:/*Ctrl N:insert line*/
	if(!(_Context->value_FontCellSwitch))
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),21,atoi(_Context->buffer_Row));
	else{
	for(c=0;c<256;c++)
	guifontfunction(_Context->value_FontName+1,c,21,atoi(_Context->buffer_Row));
	}
		standard_font_editor_show(_Context);
;
	continue;
	case 0x007F:/*Delete:delete column*/
	if(!(_Context->value_FontCellSwitch))
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),22,atoi(_Context->buffer_Column));
	else{
	for(c=0;c<256;c++)
	guifontfunction(_Context->value_FontName+1,c,22,atoi(_Context->buffer_Column));
	}
		standard_font_editor_show(_Context);
;
	continue;
	case 0x000F:/*Insert:insert column*/
	if(!(_Context->value_FontCellSwitch))
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),23,atoi(_Context->buffer_Column));
	else{
	for(c=0;c<256;c++)
	guifontfunction(_Context->value_FontName+1,c,23,atoi(_Context->buffer_Column));
	}
		standard_font_editor_show(_Context);
;
	continue;
	default:
	return(event);
	}
	}

}

/*	--------------------	*/
/*	c r o s s h a i r ()	*/
/*	--------------------	*/
static void	crosshair(struct standard_font_editor_context * _Context){
	int fw;
	int fh;
	int atx;
	int aty;
	int cellw;
	int cellh;
	int c;
	_Context->fid_CharacterData=(_Context->value_FontName+1);
	c=atoi(_Context->buffer_CharacterDec);
	fw=fontcharactersize(c,_Context->fid_CharacterData);
	if((fh=((fw>>8)&0x00FF))>0)
	cellh=(_Context->h_CharacterData/fh);
	else cellh=0;
	if((fw=(fw&0x00FF))>0)
	cellw=(_Context->w_CharacterData/fw);
	else cellw=0;
	if(cellw>cellh)
	cellw=cellh;
	else cellh=cellw;
	if((cellw>0)&&(cellh>0)){
	if((atx=atoi(_Context->buffer_Column))>fw)
	atx=fw;
	if(atx>0)
	atx--;
	if((aty=atoi(_Context->buffer_Row))>fh)
	aty=fh;
	if(aty)
	aty--;
	atx*=cellw;
	aty*=cellh;
	xorzone(_Context->x_CharacterData+1,_Context->y_CharacterData+aty+1,_Context->w_CharacterData,cellh,0x077);
	xorzone(_Context->x_CharacterData+atx+1,_Context->y_CharacterData+1,cellw,_Context->h_CharacterData,0x077);
	}

}

/*	------------------------	*/
/*	c h a n g e p i x e l ()	*/
/*	------------------------	*/
static void	changepixel(struct standard_font_editor_context * _Context){
	int x;
	int y;
	int fw;
	int fh;
	int cellw;
	int cellh;
	int c;
	int f;
	char*dptr;
	char*fontcharacterdata(int,int);
	c=atoi(_Context->buffer_CharacterDec);
	f=(_Context->value_FontName+1);
	fw=fontcharactersize(c,f);
	if(((fh=((fw>>8)&0x00FF))!=0)
	&&((fw=(fw&0x00FF))!=0)
	&&((dptr=fontcharacterdata(c,f))!=(char*)0)){
	cellw=(_Context->w_CharacterData/fw);
	cellh=(_Context->h_CharacterData/fh);
	if(cellw>cellh)
	cellw=cellh;
	else cellh=cellw;
	if((x=atoi((_Context->buffer_Column)))>0)
	x--;
	if((y=atoi((_Context->buffer_Row)))>0)
	y--;
	if(*(dptr+((y*fw)+x))!=0)
	*(dptr+((y*fw)+x))=0;
	else*(dptr+((y*fw)+x))=1;
	on_CharacterData_show(_Context);
	}

}

/*	--------------------------------------	*/
/*	c h e c k _ w i n d o w s _ i n f o ()	*/
/*	--------------------------------------	*/
static char	 * check_windows_info(struct standard_font_editor_context * _Context,char * sptr){
	char*rptr;
	int i;
	if(!(sptr))
	return(sptr);
	i=0;
	while(*(sptr+i)!=0){
	if(*(sptr+i)=='{')
	return(sptr);
	else i++;
	}
	if(!(rptr=allocate(strlen(sptr)+16)))
	return(sptr);
	else{
	sprintf(rptr,"%s{*-0}",sptr);
	liberate(sptr);
	return(rptr);
	}
	
}
private int on_Column_create(struct standard_font_editor_context * _Context) {
	sprintf(_Context->buffer_Column,"%u",1);
		return(-1);
}
private int on_Row_create(struct standard_font_editor_context * _Context) {
	sprintf(_Context->buffer_Row,"%u",1);
		return(-1);
}
private int on_FontTable_create(struct standard_font_editor_context * _Context) {
	int i;
	for(i=0;i<1104;i++)
	*(_Context->buffer_FontTable+1)=' ';
	return(-1);
}
private int on_CharacterData_create(struct standard_font_editor_context * _Context) {
	int i;
	for(i=0;i<1175;i++)
	*(_Context->buffer_CharacterData+i)=' ';
	return(-1);
}

public	int	standard_font_editor_create(
	struct standard_font_editor_context ** cptr,
	char * pCharacterDec,
	char * pFontName)
{

	int i;
	struct standard_font_editor_context * _Context=(struct standard_font_editor_context*)0;
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
	if (!(_Context = allocate( sizeof( struct standard_font_editor_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=34;
		for (i=0; i < 2; i++)  *(_Context->buffer_Character+i)=' ';
		for (i=0; i < 3; i++)  *(_Context->buffer_CharacterHex+i)=' ';
		_Context->value_FontCellSwitch=0;
		for (i=0; i < 4; i++)  *(_Context->buffer_FontWidth+i)=' ';
		for (i=0; i < 4; i++)  *(_Context->buffer_FontHeight+i)=' ';
		_Context->value_FontFile=0;
		for (i=0; i < 1700; i++)  *(_Context->buffer_HqNameList+i)=' ';
		_Context->value_HqNames=0;
		_Context->value_FixedFont=0;
		_Context->value_CrossControl=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_Column+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Row+i)=' ';
		for (i=0; i < 1104; i++)  *(_Context->buffer_FontTable+i)=' ';
		for (i=0; i < 1175; i++)  *(_Context->buffer_CharacterData+i)=' ';
		_Context->max_vBar=0;
		_Context->limit_vBar=0;
		_Context->value_vBar=0;
		_Context->max_hBar=0;
		_Context->limit_hBar=0;
		_Context->value_hBar=0;
		for (i=0; i < 4; i++)  *(_Context->buffer_CharacterWidth+i)=' ';
		for (i=0; i < 4; i++)  *(_Context->buffer_CharacterHeight+i)=' ';
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_CharacterDec, 4, pCharacterDec);
		visual_transferin((void *) 0, 0, pFontName);
		if (!( pFontName )) _Context->value_FontName=0;
		else	_Context->value_FontName = *((int *)pFontName);
		}
	for (i=0; i < 8; i++)_Context->msg_Window[i]=" ";
	_Context->hint_Window[0]=en__Window;
	_Context->hint_Window[1]=fr__Window;
	_Context->hint_Window[2]=it__Window;
	_Context->hint_Window[3]=es__Window;
	_Context->hint_Window[4]=de__Window;
	_Context->hint_Window[5]=nl__Window;
	_Context->hint_Window[6]=pt__Window;
	_Context->hint_Window[7]=xx__Window;
	_Context->x_Window=0;
	_Context->y_Window=0;
	_Context->w_Window=790;
	_Context->h_Window=590;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_ExportFont[i]=" ";
	_Context->msg_ExportFont[0]=en_ExportFont;
	_Context->hint_ExportFont[0]=en__ExportFont;
	for (i=0; i < 8; i++)_Context->msg_ImportFont[i]=" ";
	_Context->msg_ImportFont[0]=en_ImportFont;
	_Context->hint_ImportFont[0]=en__ImportFont;
	for (i=0; i < 8; i++)_Context->msg_Auto3592[i]=" ";
	_Context->msg_Auto3592[0]=en_Auto3592;
	_Context->msg_Auto3592[1]=fr_Auto3592;
	_Context->msg_Auto3592[2]=it_Auto3592;
	_Context->msg_Auto3592[3]=es_Auto3592;
	_Context->msg_Auto3592[4]=de_Auto3592;
	_Context->msg_Auto3592[5]=nl_Auto3592;
	_Context->msg_Auto3592[6]=pt_Auto3592;
	_Context->msg_Auto3592[7]=xx_Auto3592;
	for (i=0; i < 8; i++)_Context->msg_Auto3593[i]=" ";
	_Context->msg_Auto3593[0]=en_Auto3593;
	_Context->msg_Auto3593[1]=fr_Auto3593;
	_Context->msg_Auto3593[2]=it_Auto3593;
	_Context->msg_Auto3593[3]=es_Auto3593;
	_Context->msg_Auto3593[4]=de_Auto3593;
	_Context->msg_Auto3593[5]=nl_Auto3593;
	_Context->msg_Auto3593[6]=pt_Auto3593;
	_Context->msg_Auto3593[7]=xx_Auto3593;
	for (i=0; i < 8; i++)_Context->msg_Auto3594[i]=" ";
	_Context->msg_Auto3594[0]=en_Auto3594;
	_Context->msg_Auto3594[1]=fr_Auto3594;
	_Context->msg_Auto3594[2]=it_Auto3594;
	_Context->msg_Auto3594[3]=es_Auto3594;
	_Context->msg_Auto3594[4]=de_Auto3594;
	_Context->msg_Auto3594[5]=nl_Auto3594;
	_Context->msg_Auto3594[6]=pt_Auto3594;
	_Context->msg_Auto3594[7]=xx_Auto3594;
	for (i=0; i < 8; i++)_Context->msg_Auto3595[i]=" ";
	_Context->msg_Auto3595[0]=en_Auto3595;
	_Context->msg_Auto3595[1]=fr_Auto3595;
	_Context->msg_Auto3595[2]=it_Auto3595;
	_Context->msg_Auto3595[3]=es_Auto3595;
	_Context->msg_Auto3595[4]=de_Auto3595;
	_Context->msg_Auto3595[5]=nl_Auto3595;
	_Context->msg_Auto3595[6]=pt_Auto3595;
	_Context->msg_Auto3595[7]=xx_Auto3595;
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
	for (i=0; i < 8; i++)_Context->msg_PreviousCharacter[i]=" ";
	_Context->msg_PreviousCharacter[0]=en_PreviousCharacter;
	_Context->msg_PreviousCharacter[1]=fr_PreviousCharacter;
	_Context->msg_PreviousCharacter[2]=it_PreviousCharacter;
	_Context->msg_PreviousCharacter[3]=es_PreviousCharacter;
	_Context->msg_PreviousCharacter[4]=de_PreviousCharacter;
	_Context->msg_PreviousCharacter[5]=nl_PreviousCharacter;
	_Context->msg_PreviousCharacter[6]=pt_PreviousCharacter;
	_Context->msg_PreviousCharacter[7]=xx_PreviousCharacter;
	for (i=0; i < 8; i++)_Context->msg_NextCharacter[i]=" ";
	_Context->msg_NextCharacter[0]=en_NextCharacter;
	_Context->msg_NextCharacter[1]=fr_NextCharacter;
	_Context->msg_NextCharacter[2]=it_NextCharacter;
	_Context->msg_NextCharacter[3]=es_NextCharacter;
	_Context->msg_NextCharacter[4]=de_NextCharacter;
	_Context->msg_NextCharacter[5]=nl_NextCharacter;
	_Context->msg_NextCharacter[6]=pt_NextCharacter;
	_Context->msg_NextCharacter[7]=xx_NextCharacter;
	for (i=0; i < 8; i++)_Context->msg_CopyCharacter[i]=" ";
	_Context->msg_CopyCharacter[0]=en_CopyCharacter;
	_Context->msg_CopyCharacter[1]=fr_CopyCharacter;
	_Context->msg_CopyCharacter[2]=it_CopyCharacter;
	_Context->msg_CopyCharacter[3]=es_CopyCharacter;
	_Context->msg_CopyCharacter[4]=de_CopyCharacter;
	_Context->msg_CopyCharacter[5]=nl_CopyCharacter;
	_Context->msg_CopyCharacter[6]=pt_CopyCharacter;
	_Context->msg_CopyCharacter[7]=xx_CopyCharacter;
	for (i=0; i < 8; i++)_Context->msg_PasteCharacter[i]=" ";
	_Context->msg_PasteCharacter[0]=en_PasteCharacter;
	_Context->msg_PasteCharacter[1]=fr_PasteCharacter;
	_Context->msg_PasteCharacter[2]=it_PasteCharacter;
	_Context->msg_PasteCharacter[3]=es_PasteCharacter;
	_Context->msg_PasteCharacter[4]=de_PasteCharacter;
	_Context->msg_PasteCharacter[5]=nl_PasteCharacter;
	_Context->msg_PasteCharacter[6]=pt_PasteCharacter;
	_Context->msg_PasteCharacter[7]=xx_PasteCharacter;
	_Context->hint_PasteCharacter[0]=en__PasteCharacter;
	for (i=0; i < 8; i++)_Context->msg_FontSave[i]=" ";
	_Context->msg_FontSave[0]=en_FontSave;
	_Context->msg_FontSave[1]=fr_FontSave;
	_Context->msg_FontSave[2]=it_FontSave;
	_Context->msg_FontSave[3]=es_FontSave;
	_Context->msg_FontSave[4]=de_FontSave;
	_Context->msg_FontSave[5]=nl_FontSave;
	_Context->msg_FontSave[6]=pt_FontSave;
	_Context->msg_FontSave[7]=xx_FontSave;
	_Context->hint_FontSave[0]=en__FontSave;
	for (i=0; i < 8; i++)_Context->msg_FontReSize[i]=" ";
	_Context->msg_FontReSize[0]=en_FontReSize;
	_Context->msg_FontReSize[1]=fr_FontReSize;
	_Context->msg_FontReSize[2]=it_FontReSize;
	_Context->msg_FontReSize[3]=es_FontReSize;
	_Context->msg_FontReSize[4]=de_FontReSize;
	_Context->msg_FontReSize[5]=nl_FontReSize;
	_Context->msg_FontReSize[6]=pt_FontReSize;
	_Context->msg_FontReSize[7]=xx_FontReSize;
	for (i=0; i < 8; i++)_Context->msg_FontExport[i]=" ";
	_Context->msg_FontExport[0]=en_FontExport;
	_Context->msg_FontExport[1]=fr_FontExport;
	_Context->msg_FontExport[2]=it_FontExport;
	_Context->msg_FontExport[3]=es_FontExport;
	_Context->msg_FontExport[4]=de_FontExport;
	_Context->msg_FontExport[5]=nl_FontExport;
	_Context->msg_FontExport[6]=pt_FontExport;
	_Context->msg_FontExport[7]=xx_FontExport;
	for (i=0; i < 8; i++)_Context->msg_FontFrame[i]=" ";
	_Context->msg_FontFrame[0]=en_FontFrame;
	_Context->msg_FontFrame[1]=fr_FontFrame;
	_Context->msg_FontFrame[2]=it_FontFrame;
	_Context->msg_FontFrame[3]=es_FontFrame;
	_Context->msg_FontFrame[4]=de_FontFrame;
	_Context->msg_FontFrame[5]=nl_FontFrame;
	_Context->msg_FontFrame[6]=pt_FontFrame;
	_Context->msg_FontFrame[7]=xx_FontFrame;
	for (i=0; i < 8; i++)_Context->msg_FontLoad[i]=" ";
	_Context->msg_FontLoad[0]=en_FontLoad;
	_Context->msg_FontLoad[1]=fr_FontLoad;
	_Context->msg_FontLoad[2]=it_FontLoad;
	_Context->msg_FontLoad[3]=es_FontLoad;
	_Context->msg_FontLoad[4]=de_FontLoad;
	_Context->msg_FontLoad[5]=nl_FontLoad;
	_Context->msg_FontLoad[6]=pt_FontLoad;
	_Context->msg_FontLoad[7]=xx_FontLoad;
	_Context->hint_FontLoad[0]=en__FontLoad;
	for (i=0; i < 8; i++)_Context->msg_FontName[i]=" ";
	_Context->hint_FontName[0]=en__FontName;
	for (i=0; i < 8; i++)_Context->msg_FontCellSwitch[i]=" ";
	_Context->msg_FontCellSwitch[0]=en_FontCellSwitch;
	_Context->msg_FontCellSwitch[1]=fr_FontCellSwitch;
	_Context->msg_FontCellSwitch[2]=it_FontCellSwitch;
	_Context->msg_FontCellSwitch[3]=es_FontCellSwitch;
	_Context->msg_FontCellSwitch[4]=de_FontCellSwitch;
	_Context->msg_FontCellSwitch[5]=nl_FontCellSwitch;
	_Context->msg_FontCellSwitch[6]=pt_FontCellSwitch;
	_Context->msg_FontCellSwitch[7]=xx_FontCellSwitch;
	_Context->hint_FontCellSwitch[0]=en__FontCellSwitch;
	for (i=0; i < 8; i++)_Context->msg_FontSwap[i]=" ";
	_Context->msg_FontSwap[0]=en_FontSwap;
	_Context->msg_FontSwap[1]=fr_FontSwap;
	_Context->msg_FontSwap[2]=it_FontSwap;
	_Context->msg_FontSwap[3]=es_FontSwap;
	_Context->msg_FontSwap[4]=de_FontSwap;
	_Context->msg_FontSwap[5]=nl_FontSwap;
	_Context->msg_FontSwap[6]=pt_FontSwap;
	_Context->msg_FontSwap[7]=xx_FontSwap;
	_Context->hint_FontSwap[0]=en__FontSwap;
	_Context->hint_FontSwap[1]=fr__FontSwap;
	_Context->hint_FontSwap[2]=it__FontSwap;
	_Context->hint_FontSwap[3]=es__FontSwap;
	_Context->hint_FontSwap[4]=de__FontSwap;
	_Context->hint_FontSwap[5]=nl__FontSwap;
	_Context->hint_FontSwap[6]=pt__FontSwap;
	_Context->hint_FontSwap[7]=xx__FontSwap;
	for (i=0; i < 8; i++)_Context->msg_CellSwap[i]=" ";
	_Context->msg_CellSwap[0]=en_CellSwap;
	_Context->msg_CellSwap[1]=fr_CellSwap;
	_Context->msg_CellSwap[2]=it_CellSwap;
	_Context->msg_CellSwap[3]=es_CellSwap;
	_Context->msg_CellSwap[4]=de_CellSwap;
	_Context->msg_CellSwap[5]=nl_CellSwap;
	_Context->msg_CellSwap[6]=pt_CellSwap;
	_Context->msg_CellSwap[7]=xx_CellSwap;
	_Context->hint_CellSwap[0]=en__CellSwap;
	_Context->hint_CellSwap[1]=fr__CellSwap;
	_Context->hint_CellSwap[2]=it__CellSwap;
	_Context->hint_CellSwap[3]=es__CellSwap;
	_Context->hint_CellSwap[4]=de__CellSwap;
	_Context->hint_CellSwap[5]=nl__CellSwap;
	_Context->hint_CellSwap[6]=pt__CellSwap;
	_Context->hint_CellSwap[7]=xx__CellSwap;
	for (i=0; i < 8; i++)_Context->msg_FontFile[i]=" ";
	_Context->hint_FontFile[0]=en__FontFile;
	_Context->hint_HqNameList[0]=en__HqNameList;
	for (i=0; i < 8; i++)_Context->msg_HqNames[i]=" ";
	_Context->hint_HqNames[0]=en__HqNames;
	for (i=0; i < 8; i++)_Context->msg_SetHqFont[i]=" ";
	_Context->msg_SetHqFont[0]=en_SetHqFont;
	_Context->msg_SetHqFont[1]=fr_SetHqFont;
	_Context->msg_SetHqFont[2]=it_SetHqFont;
	_Context->msg_SetHqFont[3]=es_SetHqFont;
	_Context->msg_SetHqFont[4]=de_SetHqFont;
	_Context->msg_SetHqFont[5]=nl_SetHqFont;
	_Context->msg_SetHqFont[6]=pt_SetHqFont;
	_Context->msg_SetHqFont[7]=xx_SetHqFont;
	_Context->hint_SetHqFont[0]=en__SetHqFont;
	_Context->hint_SetHqFont[1]=fr__SetHqFont;
	_Context->hint_SetHqFont[2]=it__SetHqFont;
	_Context->hint_SetHqFont[3]=es__SetHqFont;
	_Context->hint_SetHqFont[4]=de__SetHqFont;
	_Context->hint_SetHqFont[5]=nl__SetHqFont;
	_Context->hint_SetHqFont[6]=pt__SetHqFont;
	_Context->hint_SetHqFont[7]=xx__SetHqFont;
	for (i=0; i < 8; i++)_Context->msg_FixedFont[i]=" ";
	_Context->msg_FixedFont[0]=en_FixedFont;
	_Context->msg_FixedFont[1]=fr_FixedFont;
	_Context->msg_FixedFont[2]=it_FixedFont;
	_Context->msg_FixedFont[3]=es_FixedFont;
	_Context->msg_FixedFont[4]=de_FixedFont;
	_Context->msg_FixedFont[5]=nl_FixedFont;
	_Context->msg_FixedFont[6]=pt_FixedFont;
	_Context->msg_FixedFont[7]=xx_FixedFont;
	_Context->hint_FixedFont[0]=en__FixedFont;
	_Context->value_FixedFont=0;
	for (i=0; i < 8; i++)_Context->msg_CrossControl[i]=" ";
	_Context->msg_CrossControl[0]=en_CrossControl;
	_Context->msg_CrossControl[1]=fr_CrossControl;
	_Context->msg_CrossControl[2]=it_CrossControl;
	_Context->msg_CrossControl[3]=es_CrossControl;
	_Context->msg_CrossControl[4]=de_CrossControl;
	_Context->msg_CrossControl[5]=nl_CrossControl;
	_Context->msg_CrossControl[6]=pt_CrossControl;
	_Context->msg_CrossControl[7]=xx_CrossControl;
	_Context->hint_CrossControl[0]=en__CrossControl;
	_Context->value_CrossControl=0;
	(void) on_Column_create(_Context);
	(void) on_Row_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto3600[i]=" ";
	_Context->msg_Auto3600[0]=en_Auto3600;
	_Context->msg_Auto3600[1]=fr_Auto3600;
	_Context->msg_Auto3600[2]=it_Auto3600;
	_Context->msg_Auto3600[3]=es_Auto3600;
	_Context->msg_Auto3600[4]=de_Auto3600;
	_Context->msg_Auto3600[5]=nl_Auto3600;
	_Context->msg_Auto3600[6]=pt_Auto3600;
	_Context->msg_Auto3600[7]=xx_Auto3600;
	_Context->hint_Auto3600[0]=en__Auto3600;
	_Context->hint_Auto3600[1]=fr__Auto3600;
	_Context->hint_Auto3600[2]=it__Auto3600;
	_Context->hint_Auto3600[3]=es__Auto3600;
	_Context->hint_Auto3600[4]=de__Auto3600;
	_Context->hint_Auto3600[5]=nl__Auto3600;
	_Context->hint_Auto3600[6]=pt__Auto3600;
	_Context->hint_Auto3600[7]=xx__Auto3600;
	for (i=0; i < 8; i++)_Context->msg_Auto3601[i]=" ";
	_Context->msg_Auto3601[0]=en_Auto3601;
	_Context->msg_Auto3601[1]=fr_Auto3601;
	_Context->msg_Auto3601[2]=it_Auto3601;
	_Context->msg_Auto3601[3]=es_Auto3601;
	_Context->msg_Auto3601[4]=de_Auto3601;
	_Context->msg_Auto3601[5]=nl_Auto3601;
	_Context->msg_Auto3601[6]=pt_Auto3601;
	_Context->msg_Auto3601[7]=xx_Auto3601;
	_Context->hint_Auto3601[0]=en__Auto3601;
	for (i=0; i < 8; i++)_Context->msg_Auto3602[i]=" ";
	_Context->msg_Auto3602[0]=en_Auto3602;
	_Context->msg_Auto3602[1]=fr_Auto3602;
	_Context->msg_Auto3602[2]=it_Auto3602;
	_Context->msg_Auto3602[3]=es_Auto3602;
	_Context->msg_Auto3602[4]=de_Auto3602;
	_Context->msg_Auto3602[5]=nl_Auto3602;
	_Context->msg_Auto3602[6]=pt_Auto3602;
	_Context->msg_Auto3602[7]=xx_Auto3602;
	_Context->hint_Auto3602[0]=en__Auto3602;
	for (i=0; i < 8; i++)_Context->msg_Auto3603[i]=" ";
	_Context->msg_Auto3603[0]=en_Auto3603;
	_Context->msg_Auto3603[1]=fr_Auto3603;
	_Context->msg_Auto3603[2]=it_Auto3603;
	_Context->msg_Auto3603[3]=es_Auto3603;
	_Context->msg_Auto3603[4]=de_Auto3603;
	_Context->msg_Auto3603[5]=nl_Auto3603;
	_Context->msg_Auto3603[6]=pt_Auto3603;
	_Context->msg_Auto3603[7]=xx_Auto3603;
	_Context->hint_Auto3603[0]=en__Auto3603;
	for (i=0; i < 8; i++)_Context->msg_Auto3604[i]=" ";
	_Context->msg_Auto3604[0]=en_Auto3604;
	_Context->msg_Auto3604[1]=fr_Auto3604;
	_Context->msg_Auto3604[2]=it_Auto3604;
	_Context->msg_Auto3604[3]=es_Auto3604;
	_Context->msg_Auto3604[4]=de_Auto3604;
	_Context->msg_Auto3604[5]=nl_Auto3604;
	_Context->msg_Auto3604[6]=pt_Auto3604;
	_Context->msg_Auto3604[7]=xx_Auto3604;
	_Context->hint_Auto3604[0]=en__Auto3604;
	for (i=0; i < 8; i++)_Context->msg_Auto3605[i]=" ";
	_Context->msg_Auto3605[0]=en_Auto3605;
	_Context->msg_Auto3605[1]=fr_Auto3605;
	_Context->msg_Auto3605[2]=it_Auto3605;
	_Context->msg_Auto3605[3]=es_Auto3605;
	_Context->msg_Auto3605[4]=de_Auto3605;
	_Context->msg_Auto3605[5]=nl_Auto3605;
	_Context->msg_Auto3605[6]=pt_Auto3605;
	_Context->msg_Auto3605[7]=xx_Auto3605;
	for (i=0; i < 8; i++)_Context->msg_Auto3606[i]=" ";
	_Context->msg_Auto3606[0]=en_Auto3606;
	_Context->msg_Auto3606[1]=fr_Auto3606;
	_Context->msg_Auto3606[2]=it_Auto3606;
	_Context->msg_Auto3606[3]=es_Auto3606;
	_Context->msg_Auto3606[4]=de_Auto3606;
	_Context->msg_Auto3606[5]=nl_Auto3606;
	_Context->msg_Auto3606[6]=pt_Auto3606;
	_Context->msg_Auto3606[7]=xx_Auto3606;
	_Context->x_FontTable=390;
	_Context->y_FontTable=130;
	_Context->w_FontTable=368;
	_Context->h_FontTable=384;
	_Context->fg_FontTable=384;
	_Context->bg_FontTable=384;
	_Context->fid_FontTable=1;
	(void) on_FontTable_create(_Context);
	_Context->hint_CharacterData[0]=en__CharacterData;
	_Context->x_CharacterData=10;
	_Context->y_CharacterData=130;
	_Context->w_CharacterData=376;
	_Context->h_CharacterData=400;
	_Context->fg_CharacterData=400;
	_Context->bg_CharacterData=400;
	_Context->fid_CharacterData=1;
	(void) on_CharacterData_create(_Context);
	_Context->max_vBar=1;
	_Context->value_vBar=1;
	_Context->limit_vBar=1;
	_Context->value_vBar=0;
	_Context->max_vBar=16;
	_Context->limit_vBar=16;
	_Context->hint_hBar[0]=en__hBar;
	_Context->max_hBar=1;
	_Context->value_hBar=1;
	_Context->limit_hBar=1;
	_Context->value_hBar=0;
	_Context->max_hBar=16;
	_Context->limit_hBar=16;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(0,0,790+10,590+10);
	return(0);
}

public 	int	standard_font_editor_hide(struct standard_font_editor_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,0,0);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	standard_font_editor_remove(
	struct standard_font_editor_context * _Context,
	char * pCharacterDec,
	char * pFontName)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_CharacterDec, 4, pCharacterDec);
		visual_transferout((void *) 0, 0, pFontName);
		if ( pFontName != (char *) 0)
			*((int*)pFontName) = _Context->value_FontName;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Character_show(struct standard_font_editor_context * _Context) {
	sprintf(_Context->buffer_Character,"%c",atoi(_Context->buffer_CharacterDec));
	visual_frame(100,70,16+2,16+2,5);
visual_text(100+1,70+1,16,16,vfh[1],27,28,_Context->buffer_Character,2,3);
;
	return(-1);
}
private int on_CharacterHex_show(struct standard_font_editor_context * _Context) {
	sprintf(_Context->buffer_CharacterHex,"%x",atoi(_Context->buffer_CharacterDec));
	visual_frame(100,90,24+2,16+2,5);
visual_text(100+1,90+1,24,16,vfh[1],27,28,_Context->buffer_CharacterHex,3,3);
;
	return(-1);
}
private int on_FontWidth_show(struct standard_font_editor_context * _Context) {
	int fw;
	int c;
	int f;
	f=(_Context->value_FontName+1);
	fw=(guifontsize(f)&0x00FF);
	sprintf(_Context->buffer_FontWidth,"%u",fw);
	visual_frame(540,80,32+2,16+2,5);
visual_text(540+1,80+1,32,16,vfh[1],27,28,_Context->buffer_FontWidth,4,0);
;
	return(-1);
}
private int on_FontHeight_show(struct standard_font_editor_context * _Context) {
	int fh;
	int c;
	int f;
	f=(_Context->value_FontName+1);
	fh=((guifontsize(f)>>8)&0x00FF);
	sprintf(_Context->buffer_FontHeight,"%u",fh);
	visual_frame(690,80,32+2,16+2,5);
visual_text(690+1,80+1,32,16,vfh[1],27,28,_Context->buffer_FontHeight,4,0);
;
	return(-1);
}
private int on_HqNames_show(struct standard_font_editor_context * _Context) {
	on_HqNameList_event(_Context);
		visual_select(10,50,532,144,vfh[2],27,28,parse_selection(_Context->buffer_HqNameList,&_Context->value_HqNames),512);

	return(-1);
}
private int on_FontTable_show(struct standard_font_editor_context * _Context) {
	int x;
	int y;
	int fw;
	int fh;
	int nbx;
	int nby;
	int atx;
	int aty;
	int cellw;
	int cellh;
	char chaine[2];
	visual_frame(_Context->x_FontTable,_Context->y_FontTable,_Context->w_FontTable+2,_Context->h_FontTable+2,5);
visual_text(_Context->x_FontTable+1,_Context->y_FontTable+1,_Context->w_FontTable,_Context->h_FontTable,_Context->fid_FontTable,27,28,_Context->buffer_FontTable,1104,0);
;
	chaine[1]=0;
	_Context->fid_FontTable=(_Context->value_FontName+1);
	fw=guifontsize(_Context->fid_FontTable);
	fh=((fw>>8)&0x00FF);
	if((fw=(fw&0x00FF))!=0){
	if((nbx=(_Context->w_FontTable/fw))>16)
	nbx=16;
	if((nby=(_Context->h_FontTable/fh))>16)
	nby=16;
	cellw=(_Context->w_FontTable/nbx);
	cellh=(_Context->h_FontTable/nby);
	if((_Context->limit_vBar=nby)==16)
	_Context->value_vBar=0;
	if((_Context->limit_hBar=nbx)==16)
	_Context->value_hBar=0;
	for(y=0;y<nby;y++){
	aty=((_Context->y_FontTable+1)+(y*cellh));
	for(x=0;x<nbx;x++){
	chaine[0]=((y+_Context->value_vBar)*16)+(x+_Context->value_hBar);
	atx=((_Context->x_FontTable+1)+(x*cellw));
	visual_text(atx,aty,cellw,cellh,_Context->fid_FontTable,16,0,chaine,1,3);
	}
	}
	}
	return(-1);
}
private int on_CharacterData_show(struct standard_font_editor_context * _Context) {
	int x;
	int y;
	int fw;
	int fh;
	int nbx;
	int nby;
	int atx;
	int aty;
	int cellw;
	int cellh;
	int c;
	char*dptr;
	char*fontcharacterdata(int,int);
	visual_frame(_Context->x_CharacterData,_Context->y_CharacterData,_Context->w_CharacterData+2,_Context->h_CharacterData+2,5);
visual_text(_Context->x_CharacterData+1,_Context->y_CharacterData+1,_Context->w_CharacterData,_Context->h_CharacterData,_Context->fid_CharacterData,27,28,_Context->buffer_CharacterData,1175,0);
;
	c=atoi(_Context->buffer_CharacterDec);
	_Context->fid_CharacterData=(_Context->value_FontName+1);
	fw=fontcharactersize(c,_Context->fid_CharacterData);
	fh=((fw>>8)&0x00FF);
	if(((fw=(fw&0x00FF))!=0)
	&&((dptr=fontcharacterdata(c,_Context->fid_CharacterData))!=(char*)0)){
	cellw=(_Context->w_CharacterData/fw);
	cellh=(_Context->h_CharacterData/fh);
	if(cellw>cellh)
	cellw=cellh;
	else cellh=cellw;
	visual_freeze();
	for(y=0;y<fh;y++){
	aty=((_Context->y_CharacterData+1)+(y*cellh));
	for(x=0;x<fw;x++){
	atx=((_Context->x_CharacterData+1)+(x*cellw));
	if(*(dptr+((y*fw)+x))!=0)
	filzone(atx,aty,cellw-1,cellh-1,16);
	else filzone(atx,aty,cellw,cellh,15);
	}
	}
	if(_Context->value_CrossControl){crosshair(_Context);}
	visual_thaw(_Context->x_CharacterData,_Context->y_CharacterData,_Context->w_CharacterData,_Context->h_CharacterData);
	}
	return(-1);
}
private int on_CharacterWidth_show(struct standard_font_editor_context * _Context) {
	int fw;
	int c;
	int f;
	c=atoi(_Context->buffer_CharacterDec);
	f=(_Context->value_FontName+1);
	fw=(fontcharactersize(c,f)&0x00FF);
	sprintf(_Context->buffer_CharacterWidth,"%u",fw);
	visual_frame(120,540,32+2,16+2,5);
visual_text(120+1,540+1,32,16,vfh[1],27,28,_Context->buffer_CharacterWidth,4,0);
;
	return(-1);
}
private int on_CharacterHeight_show(struct standard_font_editor_context * _Context) {
	int fh;
	int c;
	int f;
	c=atoi(_Context->buffer_CharacterDec);
	f=(_Context->value_FontName+1);
	fh=((fontcharactersize(c,f)>>8)&0x00FF);
	sprintf(_Context->buffer_CharacterHeight,"%u",fh);
	visual_frame(120,560,32+2,16+2,5);
visual_text(120+1,560+1,32,16,vfh[1],27,28,_Context->buffer_CharacterHeight,4,0);
;
	return(-1);
}

public	int	standard_font_editor_show(struct standard_font_editor_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,0,0);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(0,0,790,590,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(0,0,790,590,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	_Context->trigger_ExportFont=visual_trigger_code(_Context->msg_ExportFont[_Context->language],strlen(_Context->msg_ExportFont[_Context->language]));
	visual_button(150,80,60,16,vfh[8],27,28,_Context->msg_ExportFont[_Context->language],strlen(_Context->msg_ExportFont[_Context->language]),0);
	_Context->trigger_ImportFont=visual_trigger_code(_Context->msg_ImportFont[_Context->language],strlen(_Context->msg_ImportFont[_Context->language]));
	visual_button(150,96,60,16,vfh[8],27,28,_Context->msg_ImportFont[_Context->language],strlen(_Context->msg_ImportFont[_Context->language]),0);
	_Context->trigger_Auto3592=visual_trigger_code(_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]));
	visual_button(580,80,16,16,vfh[8],27,28,_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]),0);
	_Context->trigger_Auto3593=visual_trigger_code(_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]));
	visual_button(730,80,16,16,vfh[8],27,28,_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]),0);
	_Context->trigger_Auto3594=visual_trigger_code(_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]));
	visual_button(670,80,16,16,vfh[8],27,28,_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]),0);
	_Context->trigger_Auto3595=visual_trigger_code(_Context->msg_Auto3595[_Context->language],strlen(_Context->msg_Auto3595[_Context->language]));
	visual_button(520,80,16,16,vfh[8],27,28,_Context->msg_Auto3595[_Context->language],strlen(_Context->msg_Auto3595[_Context->language]),0);
	_Context->trigger_Auto3596=visual_trigger_code(_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]));
	visual_button(160,540,16,16,vfh[8],27,28,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),0);
	_Context->trigger_Auto3597=visual_trigger_code(_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]));
	visual_button(160,560,16,16,vfh[8],27,28,_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]),0);
	_Context->trigger_Auto3598=visual_trigger_code(_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]));
	visual_button(100,560,16,16,vfh[8],27,28,_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]),0);
	_Context->trigger_Auto3599=visual_trigger_code(_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]));
	visual_button(100,540,16,16,vfh[8],27,28,_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]),0);
	_Context->trigger_PreviousCharacter=visual_trigger_code(_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]));
	visual_button(20,540,28,34,vfh[2],27,28,_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]),0);
	_Context->trigger_NextCharacter=visual_trigger_code(_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]));
	visual_button(180,540,28,34,vfh[2],27,28,_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]),0);
	_Context->trigger_CopyCharacter=visual_trigger_code(_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]));
	visual_button(220,540,70,34,vfh[2],27,28,_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]),0);
	_Context->trigger_PasteCharacter=visual_trigger_code(_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]));
	visual_button(300,540,70,34,vfh[2],27,28,_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]),0);
	_Context->trigger_FontSave=visual_trigger_code(_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]));
	visual_button(380,540,70,34,vfh[2],16,0,_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]),0);
	_Context->trigger_FontReSize=visual_trigger_code(_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]));
	visual_button(460,540,70,34,vfh[2],16,0,_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]),0);
	_Context->trigger_FontExport=visual_trigger_code(_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]));
	visual_button(540,540,70,34,vfh[2],16,0,_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]),0);
	_Context->trigger_FontFrame=visual_trigger_code(_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]));
	visual_button(620,540,70,34,vfh[2],16,0,_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]),0);
	_Context->trigger_FontLoad=visual_trigger_code(_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]));
	visual_button(700,540,70,34,vfh[2],16,0,_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]),0);
	(void) on_Character_show(_Context);
	(void) on_CharacterHex_show(_Context);
	visual_frame(100,110,32+2,16+2,5);
	visual_text(100+1,110+1,32,16,vfh[1],27,28,_Context->buffer_CharacterDec,4,0);
	visual_select(612,50,154,144,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_FontName),768);
	_Context->trigger_FontCellSwitch=visual_trigger_code(_Context->msg_FontCellSwitch[_Context->language],strlen(_Context->msg_FontCellSwitch[_Context->language]));
	visual_switch(360,80,56,32,vfh[2],44,31,_Context->msg_FontCellSwitch[_Context->language],strlen(_Context->msg_FontCellSwitch[_Context->language]),_Context->value_FontCellSwitch| 0x0030);
	_Context->trigger_FontSwap=visual_trigger_code(_Context->msg_FontSwap[_Context->language],strlen(_Context->msg_FontSwap[_Context->language]));
	visual_button(420,80,52,16,vfh[8],27,28,_Context->msg_FontSwap[_Context->language],strlen(_Context->msg_FontSwap[_Context->language]),0);
	_Context->trigger_CellSwap=visual_trigger_code(_Context->msg_CellSwap[_Context->language],strlen(_Context->msg_CellSwap[_Context->language]));
	visual_button(420,96,52,16,vfh[8],27,28,_Context->msg_CellSwap[_Context->language],strlen(_Context->msg_CellSwap[_Context->language]),0);
	(void) on_FontWidth_show(_Context);
	(void) on_FontHeight_show(_Context);
	visual_select(10,30,756,176,vfh[2],27,28,parse_selection(FontFileList,&_Context->value_FontFile),512);
	(void) on_HqNames_show(_Context);
	_Context->trigger_SetHqFont=visual_trigger_code(_Context->msg_SetHqFont[_Context->language],strlen(_Context->msg_SetHqFont[_Context->language]));
	visual_button(550,50,48,16,vfh[8],27,28,_Context->msg_SetHqFont[_Context->language],strlen(_Context->msg_SetHqFont[_Context->language]),0);
	visual_select(480,100,266,64,vfh[2],31,44,parse_selection(_Context->msg_FixedFont[_Context->language],&_Context->value_FixedFont),768);
	_Context->trigger_CrossControl=visual_trigger_code(_Context->msg_CrossControl[_Context->language],strlen(_Context->msg_CrossControl[_Context->language]));
	visual_switch(220,80,70,32,vfh[2],44,31,_Context->msg_CrossControl[_Context->language],strlen(_Context->msg_CrossControl[_Context->language]),_Context->value_CrossControl| 0x0030);
	visual_frame(300,80,56+2,16+2,5);
	visual_text(300+1,80+1,56,16,vfh[1],27,28,_Context->buffer_Column,7,3);
	visual_frame(300,100,56+2,16+2,5);
	visual_text(300+1,100+1,56,16,vfh[1],27,28,_Context->buffer_Row,7,3);
	visual_text(460,80,56,16,vfh[2],16,0,_Context->msg_Auto3600[_Context->language],strlen(_Context->msg_Auto3600[_Context->language]),1281);
	visual_text(610,80,56,16,vfh[2],16,0,_Context->msg_Auto3601[_Context->language],strlen(_Context->msg_Auto3601[_Context->language]),1281);
	visual_text(10,70,84,16,vfh[2],16,0,_Context->msg_Auto3602[_Context->language],strlen(_Context->msg_Auto3602[_Context->language]),1281);
	visual_text(20,110,70,16,vfh[2],16,0,_Context->msg_Auto3603[_Context->language],strlen(_Context->msg_Auto3603[_Context->language]),1281);
	visual_text(50,90,42,16,vfh[2],16,0,_Context->msg_Auto3604[_Context->language],strlen(_Context->msg_Auto3604[_Context->language]),1281);
	visual_text(60,540,42,17,vfh[2],16,0,_Context->msg_Auto3605[_Context->language],strlen(_Context->msg_Auto3605[_Context->language]),1282);
	visual_text(60,560,42,16,vfh[2],16,0,_Context->msg_Auto3606[_Context->language],strlen(_Context->msg_Auto3606[_Context->language]),1282);
	(void) on_FontTable_show(_Context);
	(void) on_CharacterData_show(_Context);
	visual_scrollbar(760,130,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
	visual_scrollbar(390,510,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
	(void) on_CharacterWidth_show(_Context);
	(void) on_CharacterHeight_show(_Context);
	visual_thaw(0,0,790,590);

	return(0);
}

private int PreviousCharacter_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This push button allows the character preceeding the current to be ";
			mptr[1]="loading into the character data matrix for inspection and modification. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int NextCharacter_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This push button allows the character following the current to be ";
			mptr[1]="loading into the character data matrix for inspection and modification. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CopyCharacter_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The current character matrix will be copied for pasting by clicking ";
			mptr[1]="on this button. The character dimensions, width and height, are saved ";
			mptr[2]="with the character data.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PasteCharacter_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "Character matrix data, both pixel values and dimensison, saved by ";
			mptr[1]="the Copy function will be pasted into the current character cell by pressing ";
			mptr[2]="this button.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FontSave_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This push button gives access to the Font Save dialog box allowing ";
			mptr[1]="a target font filename to be specified and accepted. The currently ";
			mptr[2]="selected font will then be written, in standard portable FMF format, to the file of the indicated name.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FontReSize_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[12];
			mptr[0] = "This push button allows font dimensions to be recalculated or redistributed ";
			mptr[1]="depending on the sate of the FixedFont selection value.  ";
			mptr[2]=" ";
			mptr[3]=" When FixedFont indicates a fixed pitch font, the global font dimensions ";
			mptr[4]="indicated by the FontWidth and FontHeight fields will be applied to all character cells, ";
			mptr[5]="either expanding the characters or clipping them to  adapt.  ";
			mptr[6]=" ";
			mptr[7]=" When FixedFont indicates a proportional spaced font, all font character ";
			mptr[8]="cells will be recalculated to their exact data useage size plus one. ";
			mptr[9]=" ";
			mptr[10]=" ";
			mptr[11]="   ";
			return(visual_online_help(mptr,12));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FontExport_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "This push button gives access to the Image Save dialog box allowing ";
			mptr[1]="an image name to be specified and accepted. An image name provided ";
			mptr[2]="in this way will be used as the name of the image file to which an ";
			mptr[3]="image of the entire font character set is to be written and saved. ";
			mptr[4]="The font image will be organised as a standard 256 character set table. ";
			mptr[5]="   ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FontFrame_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "When this button is pressed the semi-graphical character of the current ";
			mptr[1]="font will be regenerated respecting the global font dimensions.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FontLoad_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This push button gives access to the Font Load dialog box allowing ";
			mptr[1]="a font filename to be specified and accepted. The currently selected ";
			mptr[2]="font will then be loading into the current entry of the font table ";
			mptr[3]="and will become the current font.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Character_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field displays the character currently loaded into the character ";
			mptr[1]="matrix editor on the left.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CharacterHex_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field displays the hexadecimal value of the character currently ";
			mptr[1]="loaded  into the character matrix editor on the left.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CharacterDec_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "The initial value of this edit field is passed as a parameter to the ";
			mptr[1]="dialog box and displays the decimal value of the character currently ";
			mptr[2]="loaded into the character matrix editor on the left. This edit field ";
			mptr[3]="may be modified by hand or by pressing on either of the character ";
			mptr[4]="cell forward or back buttons below. The final value of this field ";
			mptr[5]="will be returned to the caller on completion.    ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FontName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "The initial value of this field will be received as a parameter to ";
			mptr[1]="the dialog box and will be returned to the caller on exit. The selection ";
			mptr[2]="mechanism allows the font table entry, on which the editor is to work, ";
			mptr[3]="to be selected. Each of the 256 font table entries may hold be loaded ";
			mptr[4]="with an individual font.    ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FontCellSwitch_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This switch controls the behaviour of the row insert/delete and the ";
			mptr[1]="column insert delete functions of the font data editor. When active ";
			mptr[2]="the operation will be performed for all 256 characters cells of the ";
			mptr[3]="font. When disabled the function will be performed on the current ";
			mptr[4]="character only.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FontWidth_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field displays the width in pixels of the currently selected ";
			mptr[1]="font table entry. It may be increased by clicking on the + button to its right or decreased by clicking on the - to its left. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FontHeight_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field displays the height in pixels of the currently selected ";
			mptr[1]="font table entry. The value displayed here may be increased by clicking ";
			mptr[2]="on the + button to its right or decreased by clicking on the - to its left. ";
			mptr[3]="  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FontFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "The selection mechanism displays the current font table entry filename ";
			mptr[1]=" and allows the font table entry, on which the editor is to work, ";
			mptr[2]="to be selected. Each of the 256 font table entries may hold be loaded ";
			mptr[3]="with an individual font.    ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int HqNames_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This multiple selection list offers the list of alternative system ";
			mptr[1]="fonts associated with this font file, for inspection and or modification. ";
			mptr[2]="These alterative system fonts will be employed by the high quality ";
			mptr[3]=" printing mechanisms at print densities higher than 75 dpi.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SetHqFont_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This button gives direct access to the  system font selection dialog ";
			mptr[1]="box for the selection of alternative fonts for use by the high quality ";
			mptr[2]="printing mechanisms.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FixedFont_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This selection mechanism allows the nature of the font to be altered ";
			mptr[1]="between fixed and proportional. This flag will be used by the ReSize function.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CrossControl_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[24];
			mptr[0] = "This switch item controls display of the font matrix editor switching ";
			mptr[1]="the cursor on and off allowing font character data to be modified ";
			mptr[2]="using the standard editor keys   ";
			mptr[3]=" ";
			mptr[4]="   ";
			mptr[5]=" Key Description  ";
			mptr[6]=" UP ARROW move up one matrix row, or wrap arround to bottom row.  ";
			mptr[7]=" DOWN ARROW move down one matrix row, or wrap arround to top row.  ";
			mptr[8]=" LEFT ARROW move left one matrix column, or wrap arround to right edge. ";
			mptr[9]=" ";
			mptr[10]=" RIGHT ARROW move right one matrix column, or wrap arround to left edge. ";
			mptr[11]=" ";
			mptr[12]=" CTRL Y Delete matrix row at the cursor position pulling up rows beneath. ";
			mptr[13]=" ";
			mptr[14]=" CTRL N Insert matrix row at the cursor position pushing down the current ";
			mptr[15]="row and all rows beneath.  ";
			mptr[16]=" DELETE Delete entire matrix column at the cursor position pulling left ";
			mptr[17]=" all columns to the right.  ";
			mptr[18]=" INSERT Insert a new matrix column at the cursor position pushing all ";
			mptr[19]="matrix columns to the right.  ";
			mptr[20]=" SPACE Toggle the matrix pixel value under the cursor position between. ";
			mptr[21]="  ";
			mptr[22]=" ";
			mptr[23]="   ";
			return(visual_online_help(mptr,24));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Column_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field displays the current character matrix cursor column ";
			mptr[1]="position.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Row_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field displays the current character matrix cursor row position. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CharacterWidth_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field displays the width in pixels of the current character ";
			mptr[1]="in the  font character matrix. It may be increased by clicking on ";
			mptr[2]="the + button to its right or decreased by clicking on the - to its left. ";
			mptr[3]="  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CharacterHeight_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field displays the height in pixels of the current character ";
			mptr[1]="in the  font character matrix. It may be increased by clicking on ";
			mptr[2]="the + button to its right or decreased by clicking on the - to its left. ";
			mptr[3]="  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}
private int on_ExportFont_event(struct standard_font_editor_context * _Context) {
	font_export(_Context->value_FontName);
	return(-1);
}
private int on_ImportFont_event(struct standard_font_editor_context * _Context) {
	font_import(_Context->value_FontName);
	return(-1);
}
private int on_Auto3592_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),6,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3593_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),8,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3594_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),7,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3595_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),5,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3596_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),2,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3597_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),4,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3598_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),3,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3599_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),1,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_PreviousCharacter_event(struct standard_font_editor_context * _Context) {
	int v;
	v=atoi(_Context->buffer_CharacterDec);
	if(v>0)
	v-=1;
	else v=255;
	sprintf(_Context->buffer_CharacterDec,"%u",v);
	on_CharacterDec_losefocus(_Context);
	#ifdef old_merde
	visual_frame(100,110,32+2,16+2,5);
visual_text(100+1,110+1,32,16,vfh[1],27,28,_Context->buffer_CharacterDec,4,0);
;
	on_CharacterHex_show(_Context);
	on_Character_show(_Context);
	on_CharacterData_show(_Context);
	on_CharacterWidth_show(_Context);
	on_CharacterHeight_show(_Context);
	#endif
	return(-1);
}
private int on_NextCharacter_event(struct standard_font_editor_context * _Context) {
	int v;
	v=((atoi(_Context->buffer_CharacterDec)+1)&0x00FF);
	sprintf(_Context->buffer_CharacterDec,"%u",v);
	on_CharacterDec_losefocus(_Context);
	#ifdef old_merde
	visual_frame(100,110,32+2,16+2,5);
visual_text(100+1,110+1,32,16,vfh[1],27,28,_Context->buffer_CharacterDec,4,0);
;
	on_CharacterHex_show(_Context);
	on_Character_show(_Context);
	on_CharacterData_show(_Context);
	on_CharacterWidth_show(_Context);
	on_CharacterHeight_show(_Context);
	#endif
	return(-1);
}
private int on_CopyCharacter_event(struct standard_font_editor_context * _Context) {
	int c;
	int f;
	c=atoi(_Context->buffer_CharacterDec);
	f=(_Context->value_FontName+1);
	font_copy_cell(c,f);
	return(-1);
}
private int on_PasteCharacter_event(struct standard_font_editor_context * _Context) {
	int c;
	int f;
	c=atoi(_Context->buffer_CharacterDec);
	f=(_Context->value_FontName+1);
	if(!(font_paste_cell(c,f))){
	on_CharacterData_show(_Context);
	on_FontTable_show(_Context);
	}
	return(-1);
}
private int on_FontSave_event(struct standard_font_editor_context * _Context) {
	char*allocate_string(char*);
	char*sptr=(char*)0;
	char*nptr;
	if((nptr=guifontname(_Context->value_FontName+1))!=(char*)0)
	sptr=allocate_string(nptr);
	else sptr=(char*)0;
	if(accept_fontsave(&sptr)!=27)
	guifontsave(_Context->value_FontName+1,sptr);
	if(sptr)
	liberate(sptr);
	return(-1);
}
private int on_FontReSize_event(struct standard_font_editor_context * _Context) {
	int width;
	switch(_Context->value_FixedFont){
	case 0:
	width=((atoi(_Context->buffer_FontWidth)&0x00FF)
	|((atoi(_Context->buffer_FontHeight)&0x00FF)<<8));
	break;
	default:
	width=0;
	}
	if(!(font_recalculate(_Context->value_FontName+1,width))){
	on_FontName_losefocus(_Context);
	}
	return(-1);
}
private int on_FontExport_event(struct standard_font_editor_context * _Context) {
	if(!(font_export_image(_Context->value_FontName+1))){
	on_FontName_losefocus(_Context);
	}
	return(-1);
}
private int on_FontFrame_event(struct standard_font_editor_context * _Context) {
	if(!(font_semi_graphics(_Context->value_FontName+1))){
	on_FontName_losefocus(_Context);
	}
	return(-1);
}
private int on_FontLoad_event(struct standard_font_editor_context * _Context) {
	int isansi=1;
	int holder;
	char*allocate_string(char*);
	char*sptr;
	char*nptr;
	if((nptr=guifontname(_Context->value_FontName+1))!=(char*)0)
	sptr=allocate_string(nptr);
	else sptr=(char*)0;
	if(accept_fontload(&sptr,&isansi)!=27){
	holder=iso_conversion_value(isansi);
	load_font(_Context->value_FontName+1,sptr);
	holder=iso_conversion_value(holder);
	on_FontName_losefocus(_Context);
	}
	if(sptr)
	liberate(sptr);
	return(-1);
}
private int on_FontSwap_event(struct standard_font_editor_context * _Context) {
	standard_font_swap(_Context->value_FontFile+1);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_CellSwap_event(struct standard_font_editor_context * _Context) {
	int c;
	int s;
	int t;
	status_message("define source character",2);
	while(1){
	switch((c=stdinput(_Context))){
	case 27:
	status_message("character swap cancelled",2);
	return(-1);
	case 256:
	if(visual_event(1)!=_MIMO_UP)
	continue;
	else break;
	default:
	continue;
	}
	break;
	}
	on_FontTable_event(_Context);
	s=Conv(_Context->buffer_CharacterDec);
	status_message("define target character",2);
	while(1){
	switch((c=stdinput(_Context))){
	case 27:
	status_message("character swap cancelled",2);
	return(-1);
	case 256:
	if(visual_event(1)!=_MIMO_UP)
	continue;
	else break;
	default:
	continue;
	}
	break;
	}
	on_FontTable_event(_Context);
	t=Conv(_Context->buffer_CharacterDec);
	standard_cell_swap(_Context->value_FontFile+1,s,t);
		standard_font_editor_show(_Context);
;
	status_message("character swap completed",2);
	return(-1);
}
private int on_HqNameList_event(struct standard_font_editor_context * _Context) {
	char*get_hq_fontname(int,int);
	int set_hq_fontname(int,int,char*);
	int i;
	char*hqn;
	strcpy(_Context->buffer_HqNameList,"\0");
	for(i=0;i<8;i++){
	if(i)
	strcat(_Context->buffer_HqNameList,"|");
	if((hqn=get_hq_fontname(_Context->value_FontName+1,i))!=(char*)0)
	strcat(_Context->buffer_HqNameList,hqn);
	}
		return(-1);
}
private int on_SetHqFont_event(struct standard_font_editor_context * _Context) {
	char*get_hq_fontname(int,int);
	int set_hq_fontname(int,int,char*);
	char*sptr=(char*)0;
	sptr=get_hq_fontname(_Context->value_FontName+1,_Context->value_HqNames);
	if(system_font_selector(&sptr)!=27){
	sptr=check_windows_info(_Context, sptr);
	if(!(set_hq_fontname(_Context->value_FontName+1,_Context->value_HqNames,sptr))){
	on_HqNameList_event(_Context);
		visual_select(10,50,532,144,vfh[2],27,28,parse_selection(_Context->buffer_HqNameList,&_Context->value_HqNames),512);

	}
	}
	else{
	if(sptr)
	liberate(sptr);
	}
		return(-1);
}
private int on_FixedFont_event(struct standard_font_editor_context * _Context) {
	on_CharacterData_show(_Context);
	return(-1);
}
private int on_CrossControl_event(struct standard_font_editor_context * _Context) {
	on_CharacterData_show(_Context);
	return(-1);
}
private int on_FontTable_event(struct standard_font_editor_context * _Context) {
	int c;
	int x;
	int y;
	int fw;
	int fh;
	int nbx;
	int nby;
	int atx;
	int aty;
	int cellw;
	int cellh;
	int mx;
	int my;
	_Context->fid_FontTable=(_Context->value_FontName+1);
	fw=guifontsize(_Context->fid_FontTable);
	fh=((fw>>8)&0x00FF);
	if((fw=(fw&0x00FF))!=0){
	if((nbx=(_Context->w_FontTable/fw))>16)
	nbx=16;
	if((nby=(_Context->h_FontTable/fh))>16)
	nby=16;
	cellw=(_Context->w_FontTable/nbx);
	cellh=(_Context->h_FontTable/nby);
	mx=visual_event(7);
	my=visual_event(6);
	x=((mx-_Context->x_FontTable)/cellw);
	y=((my-_Context->y_FontTable)/cellh);
	c=((y+_Context->value_vBar)*16)+(x+_Context->value_hBar);
	sprintf(_Context->buffer_CharacterDec,"%u",c);
	on_CharacterDec_losefocus(_Context);
	}
	return(-1);
}
private int on_CharacterData_event(struct standard_font_editor_context * _Context) {
	int event;
	int mx;
	int my;
	int x;
	int y;
	int fw;
	int fh;
	int nbx;
	int nby;
	int atx;
	int aty;
	int cellw;
	int cellh;
	int c;
	int lastc=-1;
	int lastr=-1;
	_Context->fid_CharacterData=(_Context->value_FontName+1);
	c=atoi(_Context->buffer_CharacterDec);
	fw=fontcharactersize(c,_Context->fid_CharacterData);
	fh=((fw>>8)&0x00FF);
	if((fw=(fw&0x00FF))!=0){
	cellw=(_Context->w_CharacterData/fw);
	cellh=(_Context->h_CharacterData/fh);
	if(cellw>cellh)
	cellw=cellh;
	else cellh=cellw;
	while(1){
	mx=visual_event(7);
	my=visual_event(6);
	if(((x=((mx-_Context->x_CharacterData)/cellw))<fw)
	&&((y=((my-_Context->y_CharacterData)/cellh))<fh)){
	if((lastc!=x)
	||(lastr!=y)){
	sprintf(_Context->buffer_Column,"%u",(x+1));
	visual_frame(300,80,56+2,16+2,5);
visual_text(300+1,80+1,56,16,vfh[1],27,28,_Context->buffer_Column,7,3);
;
	sprintf(_Context->buffer_Row,"%u",(y+1));
	visual_frame(300,100,56+2,16+2,5);
visual_text(300+1,100+1,56,16,vfh[1],27,28,_Context->buffer_Row,7,3);
;
	if(visual_event(2)==_MIMO_LEFT)
	changepixel(_Context);
	else on_CharacterData_show(_Context);
	lastc=x;
	lastr=y;
	}
	}
	while((event=mimo_getch())!=256);
	if(visual_event(1)==_MIMO_UP)
	break;
	}
		}
	return(-1);
}
private int on_vBar_event(struct standard_font_editor_context * _Context) {
	on_FontTable_show(_Context);
	return(-1);
}

private int on_vBar_action(struct standard_font_editor_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (130+20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_vBar -= 1;
		if (_Context->value_vBar < 0) 
			_Context->value_vBar = 0;
		(void) on_vBar_event(_Context);
	visual_scrollbar(760,130,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
		return(-1);
		}
	if ( visual_event(6) > (130+380-20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_vBar += 1;
		if (!(_Context->max_vBar))
			_Context->value_vBar = 0;
		else if ((_Context->max_vBar < _Context->limit_vBar) 
		&& (_Context->value_vBar >= _Context->max_vBar)) 
			_Context->value_vBar = (_Context->max_vBar-1);
		else if (_Context->value_vBar > (_Context->max_vBar-_Context->limit_vBar)) 
			_Context->value_vBar = (_Context->max_vBar-_Context->limit_vBar);
		(void) on_vBar_event(_Context);
	visual_scrollbar(760,130,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
		return(-1);
		}
	visual_scrollbar(760,130,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);

	do {
		while(stdinput(_Context) != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_vBar;
		_Context->value_vBar = (((visual_event(6) - (130+20)) * _Context->max_vBar) / (380 - (2 * 20)));
		if (_Context->value_vBar < 0) 
			_Context->value_vBar = 0;
		else if (_Context->value_vBar > (_Context->max_vBar-_Context->limit_vBar)) 
			_Context->value_vBar = (_Context->max_vBar-_Context->limit_vBar);
		if (_Context->value_vBar != aty) {
		(void) on_vBar_event(_Context);
	visual_scrollbar(760,130,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_vBar -= (_Context->limit_vBar/2);
			if (_Context->value_vBar < 0) 
				_Context->value_vBar = 0;
		(void) on_vBar_event(_Context);
	visual_scrollbar(760,130,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_vBar += (_Context->limit_vBar/2);
			if (!(_Context->max_vBar))
				_Context->value_vBar = 0;
			else if ((_Context->max_vBar < _Context->limit_vBar) 
			&& (_Context->value_vBar >= _Context->max_vBar)) 
				_Context->value_vBar = (_Context->max_vBar-1);
			else if (_Context->value_vBar > (_Context->max_vBar-_Context->limit_vBar)) 
				_Context->value_vBar = (_Context->max_vBar-_Context->limit_vBar);
		(void) on_vBar_event(_Context);
	visual_scrollbar(760,130,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
			break;
		}
	visual_scrollbar(760,130,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);

	return(1);
}
private int on_hBar_event(struct standard_font_editor_context * _Context) {
	on_FontTable_show(_Context);
	return(-1);
}

private int on_hBar_action(struct standard_font_editor_context * _Context) {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (390+20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_hBar -= 1;
		if (_Context->value_hBar < 0) 
			_Context->value_hBar = 0;
		(void) on_hBar_event(_Context);
	visual_scrollbar(390,510,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
		return(-1);
		}
	if ( visual_event(7) > (390+370-20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_hBar += 1;
		if (!(_Context->max_hBar))
			_Context->value_hBar = 0;
		else if ((_Context->max_hBar < _Context->limit_hBar) 
		&& (_Context->value_hBar >= _Context->max_hBar)) 
			_Context->value_hBar = (_Context->max_hBar-1);
		else if (_Context->value_hBar > (_Context->max_hBar-_Context->limit_hBar)) 
			_Context->value_hBar = (_Context->max_hBar-_Context->limit_hBar);
		(void) on_hBar_event(_Context);
	visual_scrollbar(390,510,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
		return(-1);
		}
	visual_scrollbar(390,510,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);

	do {
		while(stdinput(_Context) != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		atx = _Context->value_hBar;
		_Context->value_hBar = (((visual_event(7) - (390+20)) * _Context->max_hBar) / (370 - (2 * 20)));
		if (_Context->value_hBar < 0) 
			_Context->value_hBar = 0;
		else if (_Context->value_hBar > (_Context->max_hBar-_Context->limit_hBar)) 
			_Context->value_hBar = (_Context->max_hBar-_Context->limit_hBar);
		if (_Context->value_hBar != atx) {
		(void) on_hBar_event(_Context);
	visual_scrollbar(390,510,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_hBar -= (_Context->limit_hBar/2);
			if (_Context->value_hBar < 0) 
				_Context->value_hBar = 0;
		(void) on_hBar_event(_Context);
	visual_scrollbar(390,510,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_hBar += (_Context->limit_hBar/2);
			if (!(_Context->max_hBar))
				_Context->value_hBar = 0;
			else if ((_Context->max_hBar < _Context->limit_hBar) 
			&& (_Context->value_hBar >= _Context->max_hBar)) 
				_Context->value_hBar = (_Context->max_hBar-1);
			else if (_Context->value_hBar > (_Context->max_hBar-_Context->limit_hBar)) 
				_Context->value_hBar = (_Context->max_hBar-_Context->limit_hBar);
		(void) on_hBar_event(_Context);
	visual_scrollbar(390,510,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
			break;
		}
	visual_scrollbar(390,510,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);

	return(1);
}


public	int	standard_font_editor_event(
struct standard_font_editor_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_ExportFont == mb ) return(2);
		if (_Context->trigger_ImportFont == mb ) return(3);
		if (_Context->trigger_Auto3592 == mb ) return(4);
		if (_Context->trigger_Auto3593 == mb ) return(5);
		if (_Context->trigger_Auto3594 == mb ) return(6);
		if (_Context->trigger_Auto3595 == mb ) return(7);
		if (_Context->trigger_Auto3596 == mb ) return(8);
		if (_Context->trigger_Auto3597 == mb ) return(9);
		if (_Context->trigger_Auto3598 == mb ) return(10);
		if (_Context->trigger_Auto3599 == mb ) return(11);
		if (_Context->trigger_PreviousCharacter == mb ) return(12);
		if (_Context->trigger_NextCharacter == mb ) return(13);
		if (_Context->trigger_CopyCharacter == mb ) return(14);
		if (_Context->trigger_PasteCharacter == mb ) return(15);
		if (_Context->trigger_FontSave == mb ) return(16);
		if (_Context->trigger_FontReSize == mb ) return(17);
		if (_Context->trigger_FontExport == mb ) return(18);
		if (_Context->trigger_FontFrame == mb ) return(19);
		if (_Context->trigger_FontLoad == mb ) return(20);
		if (_Context->trigger_FontCellSwitch == mb ) return(23);
		if (_Context->trigger_FontSwap == mb ) return(24);
		if (_Context->trigger_CellSwap == mb ) return(25);
		if (_Context->trigger_SetHqFont == mb ) return(28);
		if (_Context->trigger_CrossControl == mb ) return(30);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= 769 )  
	&&  (my >= 4 )  
	&&  (mx <= 785 )  
	&&  (my <= 20 )) {
		return(1);	/* Window */

		}
	if ((mx >= 753 )  
	&&  (my >= 4 )  
	&&  (mx <= 769 )  
	&&  (my <= 20 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vstdfont.htm");
			};
		return(-1);	/* Window */

		}
	if ((mx >= 737 )  
	&&  (my >= 4 )  
	&&  (mx <= 753 )  
	&&  (my <= 20 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		standard_font_editor_show(_Context);
		return(-1);	/* Window */

		}
		}
	if (( mx >= 150 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 210 ) 
	&&  ( my <= 96 )) {
		return(2); /* ExportFont */
		}
	if (( mx >= 150 ) 
	&&  ( my >= 96 ) 
	&&  ( mx <= 210 ) 
	&&  ( my <= 112 )) {
		return(3); /* ImportFont */
		}
	if (( mx >= 580 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 596 ) 
	&&  ( my <= 96 )) {
		return(4); /* Auto3592 */
		}
	if (( mx >= 730 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 746 ) 
	&&  ( my <= 96 )) {
		return(5); /* Auto3593 */
		}
	if (( mx >= 670 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 686 ) 
	&&  ( my <= 96 )) {
		return(6); /* Auto3594 */
		}
	if (( mx >= 520 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 536 ) 
	&&  ( my <= 96 )) {
		return(7); /* Auto3595 */
		}
	if (( mx >= 160 ) 
	&&  ( my >= 540 ) 
	&&  ( mx <= 176 ) 
	&&  ( my <= 556 )) {
		return(8); /* Auto3596 */
		}
	if (( mx >= 160 ) 
	&&  ( my >= 560 ) 
	&&  ( mx <= 176 ) 
	&&  ( my <= 576 )) {
		return(9); /* Auto3597 */
		}
	if (( mx >= 100 ) 
	&&  ( my >= 560 ) 
	&&  ( mx <= 116 ) 
	&&  ( my <= 576 )) {
		return(10); /* Auto3598 */
		}
	if (( mx >= 100 ) 
	&&  ( my >= 540 ) 
	&&  ( mx <= 116 ) 
	&&  ( my <= 556 )) {
		return(11); /* Auto3599 */
		}
	if (( mx >= 20 ) 
	&&  ( my >= 540 ) 
	&&  ( mx <= 48 ) 
	&&  ( my <= 574 )) {
		return(12); /* PreviousCharacter */
		}
	if (( mx >= 180 ) 
	&&  ( my >= 540 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 574 )) {
		return(13); /* NextCharacter */
		}
	if (( mx >= 220 ) 
	&&  ( my >= 540 ) 
	&&  ( mx <= 290 ) 
	&&  ( my <= 574 )) {
		return(14); /* CopyCharacter */
		}
	if (( mx >= 300 ) 
	&&  ( my >= 540 ) 
	&&  ( mx <= 370 ) 
	&&  ( my <= 574 )) {
		return(15); /* PasteCharacter */
		}
	if (( mx >= 380 ) 
	&&  ( my >= 540 ) 
	&&  ( mx <= 450 ) 
	&&  ( my <= 574 )) {
		return(16); /* FontSave */
		}
	if (( mx >= 460 ) 
	&&  ( my >= 540 ) 
	&&  ( mx <= 530 ) 
	&&  ( my <= 574 )) {
		return(17); /* FontReSize */
		}
	if (( mx >= 540 ) 
	&&  ( my >= 540 ) 
	&&  ( mx <= 610 ) 
	&&  ( my <= 574 )) {
		return(18); /* FontExport */
		}
	if (( mx >= 620 ) 
	&&  ( my >= 540 ) 
	&&  ( mx <= 690 ) 
	&&  ( my <= 574 )) {
		return(19); /* FontFrame */
		}
	if (( mx >= 700 ) 
	&&  ( my >= 540 ) 
	&&  ( mx <= 770 ) 
	&&  ( my <= 574 )) {
		return(20); /* FontLoad */
		}
	if (( mx >= 100 ) 
	&&  ( my >= 110 ) 
	&&  ( mx <= 132 ) 
	&&  ( my <= 126 )) {
		return(21); /* CharacterDec */
		}
	if ((mx >= 612 ) 
	&&  (my >= 50 ) 
	&&  (mx <= 766 ) 
	&&  (my <= 66 )) {
		return(22); /* FontName */
		}
	if (( mx >= 360 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 416 ) 
	&&  ( my <= 112 )) {
		return(23); /* FontCellSwitch */
		}
	if (( mx >= 420 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 472 ) 
	&&  ( my <= 96 )) {
		return(24); /* FontSwap */
		}
	if (( mx >= 420 ) 
	&&  ( my >= 96 ) 
	&&  ( mx <= 472 ) 
	&&  ( my <= 112 )) {
		return(25); /* CellSwap */
		}
	if ((mx >= 10 ) 
	&&  (my >= 30 ) 
	&&  (mx <= 766 ) 
	&&  (my <= 46 )) {
		return(26); /* FontFile */
		}
	if ((mx >= 10 ) 
	&&  (my >= 50 ) 
	&&  (mx <= 542 ) 
	&&  (my <= 66 )) {
		return(27); /* HqNames */
		}
	if (( mx >= 550 ) 
	&&  ( my >= 50 ) 
	&&  ( mx <= 598 ) 
	&&  ( my <= 66 )) {
		return(28); /* SetHqFont */
		}
	if ((mx >= 480 ) 
	&&  (my >= 100 ) 
	&&  (mx <= 746 ) 
	&&  (my <= 116 )) {
		return(29); /* FixedFont */
		}
	if (( mx >= 220 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 290 ) 
	&&  ( my <= 112 )) {
		return(30); /* CrossControl */
		}
	if ((mx >= _Context->x_FontTable ) 
	&&  (my >= _Context->y_FontTable ) 
	&&  (mx <  (_Context->x_FontTable+_Context->w_FontTable)) 
	&&  (my <  (_Context->y_FontTable+_Context->h_FontTable))) {
		return(31); /* FontTable */
		}
	if ((mx >= _Context->x_CharacterData ) 
	&&  (my >= _Context->y_CharacterData ) 
	&&  (mx <  (_Context->x_CharacterData+_Context->w_CharacterData)) 
	&&  (my <  (_Context->y_CharacterData+_Context->h_CharacterData))) {
		return(32); /* CharacterData */
		}
	if (( mx >= 760 ) 
	&&  ( my >= 130 ) 
	&&  ( mx <= 780 ) 
	&&  ( my <= 510 )) {
		return(33); /* vBar */
		}
	if (( mx >= 390 ) 
	&&  ( my >= 510 ) 
	&&  ( mx <= 760 ) 
	&&  ( my <= 530 )) {
		return(34); /* hBar */
		}

	return(-1);
}
private int on_CharacterDec_losefocus(struct standard_font_editor_context * _Context) {
	visual_frame(100,110,32+2,16+2,5);
visual_text(100+1,110+1,32,16,vfh[1],27,28,_Context->buffer_CharacterDec,4,0);
;
	on_CharacterHex_show(_Context);
	on_Character_show(_Context);
	on_CharacterData_show(_Context);
	on_CharacterWidth_show(_Context);
	on_CharacterHeight_show(_Context);
	return(-1);
}
private int on_FontName_losefocus(struct standard_font_editor_context * _Context) {
	visual_freeze();
		standard_font_editor_hide(_Context);
;
	_Context->value_FontFile=_Context->value_FontName;
	on_HqNameList_event(_Context);
		standard_font_editor_show(_Context);
;
	visual_thaw(0,0,790+10,590+10);
	return(-1);
}
private int on_CharacterData_getfocus(struct standard_font_editor_context * _Context) {
	return(stdinput(_Context));
	return(-1);
}


public	int	standard_font_editor_focus(struct standard_font_editor_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x4 :
				/* Auto3592 */
				_Context->trigger_Auto3592=visual_trigger_code(_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]));
				visual_button(580,80,16,16,vfh[8],27,28,_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto3592=visual_trigger_code(_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]));
	visual_button(580,80,16,16,vfh[8],27,28,_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]),0);
				break;
			case	0x5 :
				/* Auto3593 */
				_Context->trigger_Auto3593=visual_trigger_code(_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]));
				visual_button(730,80,16,16,vfh[8],27,28,_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto3593=visual_trigger_code(_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]));
	visual_button(730,80,16,16,vfh[8],27,28,_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]),0);
				break;
			case	0x6 :
				/* Auto3594 */
				_Context->trigger_Auto3594=visual_trigger_code(_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]));
				visual_button(670,80,16,16,vfh[8],27,28,_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto3594=visual_trigger_code(_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]));
	visual_button(670,80,16,16,vfh[8],27,28,_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]),0);
				break;
			case	0x7 :
				/* Auto3595 */
				_Context->trigger_Auto3595=visual_trigger_code(_Context->msg_Auto3595[_Context->language],strlen(_Context->msg_Auto3595[_Context->language]));
				visual_button(520,80,16,16,vfh[8],27,28,_Context->msg_Auto3595[_Context->language],strlen(_Context->msg_Auto3595[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto3595=visual_trigger_code(_Context->msg_Auto3595[_Context->language],strlen(_Context->msg_Auto3595[_Context->language]));
	visual_button(520,80,16,16,vfh[8],27,28,_Context->msg_Auto3595[_Context->language],strlen(_Context->msg_Auto3595[_Context->language]),0);
				break;
			case	0x8 :
				/* Auto3596 */
				_Context->trigger_Auto3596=visual_trigger_code(_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]));
				visual_button(160,540,16,16,vfh[8],27,28,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto3596=visual_trigger_code(_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]));
	visual_button(160,540,16,16,vfh[8],27,28,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),0);
				break;
			case	0x9 :
				/* Auto3597 */
				_Context->trigger_Auto3597=visual_trigger_code(_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]));
				visual_button(160,560,16,16,vfh[8],27,28,_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto3597=visual_trigger_code(_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]));
	visual_button(160,560,16,16,vfh[8],27,28,_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]),0);
				break;
			case	0xa :
				/* Auto3598 */
				_Context->trigger_Auto3598=visual_trigger_code(_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]));
				visual_button(100,560,16,16,vfh[8],27,28,_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto3598=visual_trigger_code(_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]));
	visual_button(100,560,16,16,vfh[8],27,28,_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]),0);
				break;
			case	0xb :
				/* Auto3599 */
				_Context->trigger_Auto3599=visual_trigger_code(_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]));
				visual_button(100,540,16,16,vfh[8],27,28,_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto3599=visual_trigger_code(_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]));
	visual_button(100,540,16,16,vfh[8],27,28,_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]),0);
				break;
			case	0xc :
				/* PreviousCharacter */
				_Context->trigger_PreviousCharacter=visual_trigger_code(_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]));
				visual_button(20,540,28,34,vfh[2],27,28,_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_PreviousCharacter=visual_trigger_code(_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]));
	visual_button(20,540,28,34,vfh[2],27,28,_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]),0);
				break;
			case	0xd :
				/* NextCharacter */
				_Context->trigger_NextCharacter=visual_trigger_code(_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]));
				visual_button(180,540,28,34,vfh[2],27,28,_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_NextCharacter=visual_trigger_code(_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]));
	visual_button(180,540,28,34,vfh[2],27,28,_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]),0);
				break;
			case	0xe :
				/* CopyCharacter */
				_Context->trigger_CopyCharacter=visual_trigger_code(_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]));
				visual_button(220,540,70,34,vfh[2],27,28,_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_CopyCharacter=visual_trigger_code(_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]));
	visual_button(220,540,70,34,vfh[2],27,28,_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]),0);
				break;
			case	0xf :
				/* PasteCharacter */
				_Context->trigger_PasteCharacter=visual_trigger_code(_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]));
				visual_button(300,540,70,34,vfh[2],27,28,_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_PasteCharacter=visual_trigger_code(_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]));
	visual_button(300,540,70,34,vfh[2],27,28,_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]),0);
				break;
			case	0x10 :
				/* FontSave */
				_Context->trigger_FontSave=visual_trigger_code(_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]));
				visual_button(380,540,70,34,vfh[2],16,0,_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_FontSave=visual_trigger_code(_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]));
	visual_button(380,540,70,34,vfh[2],16,0,_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]),0);
				break;
			case	0x11 :
				/* FontReSize */
				_Context->trigger_FontReSize=visual_trigger_code(_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]));
				visual_button(460,540,70,34,vfh[2],16,0,_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_FontReSize=visual_trigger_code(_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]));
	visual_button(460,540,70,34,vfh[2],16,0,_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]),0);
				break;
			case	0x12 :
				/* FontExport */
				_Context->trigger_FontExport=visual_trigger_code(_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]));
				visual_button(540,540,70,34,vfh[2],16,0,_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_FontExport=visual_trigger_code(_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]));
	visual_button(540,540,70,34,vfh[2],16,0,_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]),0);
				break;
			case	0x13 :
				/* FontFrame */
				_Context->trigger_FontFrame=visual_trigger_code(_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]));
				visual_button(620,540,70,34,vfh[2],16,0,_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_FontFrame=visual_trigger_code(_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]));
	visual_button(620,540,70,34,vfh[2],16,0,_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]),0);
				break;
			case	0x14 :
				/* FontLoad */
				_Context->trigger_FontLoad=visual_trigger_code(_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]));
				visual_button(700,540,70,34,vfh[2],16,0,_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_FontLoad=visual_trigger_code(_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]));
	visual_button(700,540,70,34,vfh[2],16,0,_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]),0);
				break;
			case	0x15 :
				/* CharacterDec */
				_Context->keycode = visual_edit(100+1,110+1,32,16,vfh[1],_Context->buffer_CharacterDec,4);
				(void) on_CharacterDec_losefocus(_Context);
			break;
			case	0x16 :
				/* FontName */
				_Context->keycode = visual_select(612,50,154,144,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_FontName),770);
				(void) on_FontName_losefocus(_Context);
				break;
			case	0x17 :
				/* FontCellSwitch */
				visual_switch(360,80,56,32,vfh[2],44,31,_Context->msg_FontCellSwitch[_Context->language],strlen(_Context->msg_FontCellSwitch[_Context->language]),(_Context->value_FontCellSwitch | 2 | 0x0030 ));
				_Context->keycode = stdinput(_Context);
				_Context->trigger_FontCellSwitch=visual_trigger_code(_Context->msg_FontCellSwitch[_Context->language],strlen(_Context->msg_FontCellSwitch[_Context->language]));
	visual_switch(360,80,56,32,vfh[2],44,31,_Context->msg_FontCellSwitch[_Context->language],strlen(_Context->msg_FontCellSwitch[_Context->language]),_Context->value_FontCellSwitch| 0x0030);
				break;
			case	0x18 :
				/* FontSwap */
				_Context->trigger_FontSwap=visual_trigger_code(_Context->msg_FontSwap[_Context->language],strlen(_Context->msg_FontSwap[_Context->language]));
				visual_button(420,80,52,16,vfh[8],27,28,_Context->msg_FontSwap[_Context->language],strlen(_Context->msg_FontSwap[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_FontSwap=visual_trigger_code(_Context->msg_FontSwap[_Context->language],strlen(_Context->msg_FontSwap[_Context->language]));
	visual_button(420,80,52,16,vfh[8],27,28,_Context->msg_FontSwap[_Context->language],strlen(_Context->msg_FontSwap[_Context->language]),0);
				break;
			case	0x19 :
				/* CellSwap */
				_Context->trigger_CellSwap=visual_trigger_code(_Context->msg_CellSwap[_Context->language],strlen(_Context->msg_CellSwap[_Context->language]));
				visual_button(420,96,52,16,vfh[8],27,28,_Context->msg_CellSwap[_Context->language],strlen(_Context->msg_CellSwap[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_CellSwap=visual_trigger_code(_Context->msg_CellSwap[_Context->language],strlen(_Context->msg_CellSwap[_Context->language]));
	visual_button(420,96,52,16,vfh[8],27,28,_Context->msg_CellSwap[_Context->language],strlen(_Context->msg_CellSwap[_Context->language]),0);
				break;
			case	0x1a :
				/* FontFile */
				_Context->keycode = visual_select(10,30,756,176,vfh[2],27,28,parse_selection(FontFileList,&_Context->value_FontFile),514);
				visual_freeze();
					standard_font_editor_hide(_Context);
;
				_Context->value_FontName=_Context->value_FontFile;
				on_HqNameList_event(_Context);
					standard_font_editor_show(_Context);
;
				visual_thaw(0,0,790+10,590+10);
				break;
			case	0x1b :
				/* HqNames */
				_Context->keycode = visual_select(10,50,532,144,vfh[2],27,28,parse_selection(_Context->buffer_HqNameList,&_Context->value_HqNames),514);
				break;
			case	0x1c :
				/* SetHqFont */
				_Context->trigger_SetHqFont=visual_trigger_code(_Context->msg_SetHqFont[_Context->language],strlen(_Context->msg_SetHqFont[_Context->language]));
				visual_button(550,50,48,16,vfh[8],27,28,_Context->msg_SetHqFont[_Context->language],strlen(_Context->msg_SetHqFont[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_SetHqFont=visual_trigger_code(_Context->msg_SetHqFont[_Context->language],strlen(_Context->msg_SetHqFont[_Context->language]));
	visual_button(550,50,48,16,vfh[8],27,28,_Context->msg_SetHqFont[_Context->language],strlen(_Context->msg_SetHqFont[_Context->language]),0);
				break;
			case	0x1d :
				/* FixedFont */
				_Context->keycode = visual_select(480,100,266,64,vfh[2],31,44,parse_selection(_Context->msg_FixedFont[_Context->language],&_Context->value_FixedFont),770);
				break;
			case	0x1e :
				/* CrossControl */
				visual_switch(220,80,70,32,vfh[2],44,31,_Context->msg_CrossControl[_Context->language],strlen(_Context->msg_CrossControl[_Context->language]),(_Context->value_CrossControl | 2 | 0x0030 ));
				_Context->keycode = stdinput(_Context);
				_Context->trigger_CrossControl=visual_trigger_code(_Context->msg_CrossControl[_Context->language],strlen(_Context->msg_CrossControl[_Context->language]));
	visual_switch(220,80,70,32,vfh[2],44,31,_Context->msg_CrossControl[_Context->language],strlen(_Context->msg_CrossControl[_Context->language]),_Context->value_CrossControl| 0x0030);
				break;
			case	0x20 :
				/* CharacterData */
				_Context->keycode = on_CharacterData_getfocus(_Context);
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			standard_font_editor_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=34;
			standard_font_editor_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=standard_font_editor_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0xc :
						if (PreviousCharacter_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (NextCharacter_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (CopyCharacter_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (PasteCharacter_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (FontSave_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (FontReSize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (FontExport_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (FontFrame_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (FontLoad_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (CharacterDec_help(_Context) != 0) { continue; }
						else { break; }
					case	0x16 :
						if (FontName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x17 :
						if (FontCellSwitch_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1a :
						if (FontFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1b :
						if (HqNames_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1c :
						if (SetHqFont_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1d :
						if (FixedFont_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1e :
						if (CrossControl_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Window */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* ExportFont */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ExportFont=visual_trigger_code(_Context->msg_ExportFont[_Context->language],strlen(_Context->msg_ExportFont[_Context->language]));
						visual_button(150,80,60,16,vfh[8],27,28,_Context->msg_ExportFont[_Context->language],strlen(_Context->msg_ExportFont[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ExportFont=visual_trigger_code(_Context->msg_ExportFont[_Context->language],strlen(_Context->msg_ExportFont[_Context->language]));
	visual_button(150,80,60,16,vfh[8],27,28,_Context->msg_ExportFont[_Context->language],strlen(_Context->msg_ExportFont[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ExportFont_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* ImportFont */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ImportFont=visual_trigger_code(_Context->msg_ImportFont[_Context->language],strlen(_Context->msg_ImportFont[_Context->language]));
						visual_button(150,96,60,16,vfh[8],27,28,_Context->msg_ImportFont[_Context->language],strlen(_Context->msg_ImportFont[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ImportFont=visual_trigger_code(_Context->msg_ImportFont[_Context->language],strlen(_Context->msg_ImportFont[_Context->language]));
	visual_button(150,96,60,16,vfh[8],27,28,_Context->msg_ImportFont[_Context->language],strlen(_Context->msg_ImportFont[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ImportFont_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto3592 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3592=visual_trigger_code(_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]));
						visual_button(580,80,16,16,vfh[8],27,28,_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3592=visual_trigger_code(_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]));
	visual_button(580,80,16,16,vfh[8],27,28,_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3592_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto3593 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3593=visual_trigger_code(_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]));
						visual_button(730,80,16,16,vfh[8],27,28,_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3593=visual_trigger_code(_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]));
	visual_button(730,80,16,16,vfh[8],27,28,_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3593_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto3594 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3594=visual_trigger_code(_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]));
						visual_button(670,80,16,16,vfh[8],27,28,_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3594=visual_trigger_code(_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]));
	visual_button(670,80,16,16,vfh[8],27,28,_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3594_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto3595 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3595=visual_trigger_code(_Context->msg_Auto3595[_Context->language],strlen(_Context->msg_Auto3595[_Context->language]));
						visual_button(520,80,16,16,vfh[8],27,28,_Context->msg_Auto3595[_Context->language],strlen(_Context->msg_Auto3595[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3595=visual_trigger_code(_Context->msg_Auto3595[_Context->language],strlen(_Context->msg_Auto3595[_Context->language]));
	visual_button(520,80,16,16,vfh[8],27,28,_Context->msg_Auto3595[_Context->language],strlen(_Context->msg_Auto3595[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3595_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto3596 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3596=visual_trigger_code(_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]));
						visual_button(160,540,16,16,vfh[8],27,28,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3596=visual_trigger_code(_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]));
	visual_button(160,540,16,16,vfh[8],27,28,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3596_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto3597 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3597=visual_trigger_code(_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]));
						visual_button(160,560,16,16,vfh[8],27,28,_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3597=visual_trigger_code(_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]));
	visual_button(160,560,16,16,vfh[8],27,28,_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3597_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto3598 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3598=visual_trigger_code(_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]));
						visual_button(100,560,16,16,vfh[8],27,28,_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3598=visual_trigger_code(_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]));
	visual_button(100,560,16,16,vfh[8],27,28,_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3598_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Auto3599 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3599=visual_trigger_code(_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]));
						visual_button(100,540,16,16,vfh[8],27,28,_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3599=visual_trigger_code(_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]));
	visual_button(100,540,16,16,vfh[8],27,28,_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3599_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* PreviousCharacter */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_PreviousCharacter=visual_trigger_code(_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]));
						visual_button(20,540,28,34,vfh[2],27,28,_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_PreviousCharacter=visual_trigger_code(_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]));
	visual_button(20,540,28,34,vfh[2],27,28,_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_PreviousCharacter_event(_Context)) != -1) break;

						}
					continue;
				case	0xd :
					/* NextCharacter */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_NextCharacter=visual_trigger_code(_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]));
						visual_button(180,540,28,34,vfh[2],27,28,_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_NextCharacter=visual_trigger_code(_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]));
	visual_button(180,540,28,34,vfh[2],27,28,_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_NextCharacter_event(_Context)) != -1) break;

						}
					continue;
				case	0xe :
					/* CopyCharacter */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_CopyCharacter=visual_trigger_code(_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]));
						visual_button(220,540,70,34,vfh[2],27,28,_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_CopyCharacter=visual_trigger_code(_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]));
	visual_button(220,540,70,34,vfh[2],27,28,_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_CopyCharacter_event(_Context)) != -1) break;

						}
					continue;
				case	0xf :
					/* PasteCharacter */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_PasteCharacter=visual_trigger_code(_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]));
						visual_button(300,540,70,34,vfh[2],27,28,_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_PasteCharacter=visual_trigger_code(_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]));
	visual_button(300,540,70,34,vfh[2],27,28,_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_PasteCharacter_event(_Context)) != -1) break;

						}
					continue;
				case	0x10 :
					/* FontSave */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_FontSave=visual_trigger_code(_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]));
						visual_button(380,540,70,34,vfh[2],16,0,_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_FontSave=visual_trigger_code(_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]));
	visual_button(380,540,70,34,vfh[2],16,0,_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FontSave_event(_Context)) != -1) break;

						}
					continue;
				case	0x11 :
					/* FontReSize */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_FontReSize=visual_trigger_code(_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]));
						visual_button(460,540,70,34,vfh[2],16,0,_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_FontReSize=visual_trigger_code(_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]));
	visual_button(460,540,70,34,vfh[2],16,0,_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FontReSize_event(_Context)) != -1) break;

						}
					continue;
				case	0x12 :
					/* FontExport */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_FontExport=visual_trigger_code(_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]));
						visual_button(540,540,70,34,vfh[2],16,0,_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_FontExport=visual_trigger_code(_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]));
	visual_button(540,540,70,34,vfh[2],16,0,_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FontExport_event(_Context)) != -1) break;

						}
					continue;
				case	0x13 :
					/* FontFrame */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_FontFrame=visual_trigger_code(_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]));
						visual_button(620,540,70,34,vfh[2],16,0,_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_FontFrame=visual_trigger_code(_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]));
	visual_button(620,540,70,34,vfh[2],16,0,_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FontFrame_event(_Context)) != -1) break;

						}
					continue;
				case	0x14 :
					/* FontLoad */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_FontLoad=visual_trigger_code(_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]));
						visual_button(700,540,70,34,vfh[2],16,0,_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_FontLoad=visual_trigger_code(_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]));
	visual_button(700,540,70,34,vfh[2],16,0,_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FontLoad_event(_Context)) != -1) break;

						}
					continue;
				case	0x15 :
					/* CharacterDec */
					continue;
				case	0x16 :
					/* FontName */
					continue;
				case	0x17 :
					/* FontCellSwitch */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_FontCellSwitch += 1;
						_Context->value_FontCellSwitch &= 1;
						}
					continue;
				case	0x18 :
					/* FontSwap */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_FontSwap=visual_trigger_code(_Context->msg_FontSwap[_Context->language],strlen(_Context->msg_FontSwap[_Context->language]));
						visual_button(420,80,52,16,vfh[8],27,28,_Context->msg_FontSwap[_Context->language],strlen(_Context->msg_FontSwap[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_FontSwap=visual_trigger_code(_Context->msg_FontSwap[_Context->language],strlen(_Context->msg_FontSwap[_Context->language]));
	visual_button(420,80,52,16,vfh[8],27,28,_Context->msg_FontSwap[_Context->language],strlen(_Context->msg_FontSwap[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FontSwap_event(_Context)) != -1) break;

						}
					continue;
				case	0x19 :
					/* CellSwap */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_CellSwap=visual_trigger_code(_Context->msg_CellSwap[_Context->language],strlen(_Context->msg_CellSwap[_Context->language]));
						visual_button(420,96,52,16,vfh[8],27,28,_Context->msg_CellSwap[_Context->language],strlen(_Context->msg_CellSwap[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_CellSwap=visual_trigger_code(_Context->msg_CellSwap[_Context->language],strlen(_Context->msg_CellSwap[_Context->language]));
	visual_button(420,96,52,16,vfh[8],27,28,_Context->msg_CellSwap[_Context->language],strlen(_Context->msg_CellSwap[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_CellSwap_event(_Context)) != -1) break;

						}
					continue;
				case	0x1a :
					/* FontFile */
					continue;
				case	0x1b :
					/* HqNames */
					continue;
				case	0x1c :
					/* SetHqFont */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SetHqFont=visual_trigger_code(_Context->msg_SetHqFont[_Context->language],strlen(_Context->msg_SetHqFont[_Context->language]));
						visual_button(550,50,48,16,vfh[8],27,28,_Context->msg_SetHqFont[_Context->language],strlen(_Context->msg_SetHqFont[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SetHqFont=visual_trigger_code(_Context->msg_SetHqFont[_Context->language],strlen(_Context->msg_SetHqFont[_Context->language]));
	visual_button(550,50,48,16,vfh[8],27,28,_Context->msg_SetHqFont[_Context->language],strlen(_Context->msg_SetHqFont[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SetHqFont_event(_Context)) != -1) break;

						}
					continue;
				case	0x1d :
					/* FixedFont */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FixedFont_event(_Context)) != -1) break;

						}
					continue;
				case	0x1e :
					/* CrossControl */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_CrossControl += 1;
						_Context->value_CrossControl &= 1;
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_CrossControl_event(_Context)) != -1) break;

						}
					continue;
				case	0x1f :
					/* FontTable */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FontTable_event(_Context)) != -1) break;

						}
					continue;
				case	0x20 :
					/* CharacterData */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_CharacterData_event(_Context)) != -1) break;

						}
					continue;
				case	0x21 :
					/* vBar */
					(void) on_vBar_action(_Context);
					continue;
				case	0x22 :
					/* hBar */
					(void) on_hBar_action(_Context);
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
				_Context->focus_item=34;
			}
			continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) stdinput(_Context);
	return(0);

}

public	int	standard_font_editor(
	char * pCharacterDec,
	char * pFontName)
{
	int	status=0;
	struct standard_font_editor_context * _Context=(struct standard_font_editor_context*) 0;
	status = standard_font_editor_create(
	&_Context,
	 pCharacterDec,
	 pFontName);
	if ( status != 0) return(status);
	status = standard_font_editor_show(_Context);
		enter_modal();
	status = standard_font_editor_focus(_Context);
		leave_modal();
	status = standard_font_editor_hide(_Context);
	status = standard_font_editor_remove(
	_Context,
	 pCharacterDec,
	 pFontName);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vstdfont_c */
