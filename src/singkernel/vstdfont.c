
#ifndef _vstdfont_c
#define _vstdfont_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vstdfont.xml  */
/* Target         : vstdfont.c  */
/* Identification : 0.0-1100887232-19834.19833 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto1462   "Sing 1.0a : Font Editor"
#define fr_Auto1462   "Sing 1.0a : Editeur de Fontes"
#define it_Auto1462   "Sing 1.0a : Font Editor"
#define es_Auto1462   "Sing 1.0a : Font Editor"
#define de_Auto1462   "Sing 1.0a : Font Editor"
#define nl_Auto1462   "Sing 1.0a : Font Editor"
#define pt_Auto1462   "Sing 1.0a : Font Editor"
#define xx_Auto1462   "Sing 1.0a : Font Editor"
#define en_Auto1469   "+"
#define fr_Auto1469   "+"
#define it_Auto1469   "+"
#define es_Auto1469   "+"
#define de_Auto1469   "+"
#define nl_Auto1469   "+"
#define pt_Auto1469   "+"
#define xx_Auto1469   "+"
#define en_Auto1470   "+"
#define fr_Auto1470   "+"
#define it_Auto1470   "+"
#define es_Auto1470   "+"
#define de_Auto1470   "+"
#define nl_Auto1470   "+"
#define pt_Auto1470   "+"
#define xx_Auto1470   "+"
#define en_Auto1471   "-"
#define fr_Auto1471   "-"
#define it_Auto1471   "-"
#define es_Auto1471   "-"
#define de_Auto1471   "-"
#define nl_Auto1471   "-"
#define pt_Auto1471   "-"
#define xx_Auto1471   "-"
#define en_Auto1472   "-"
#define fr_Auto1472   "-"
#define it_Auto1472   "-"
#define es_Auto1472   "-"
#define de_Auto1472   "-"
#define nl_Auto1472   "-"
#define pt_Auto1472   "-"
#define xx_Auto1472   "-"
#define en_Auto1473   "+"
#define fr_Auto1473   "+"
#define it_Auto1473   "+"
#define es_Auto1473   "+"
#define de_Auto1473   "+"
#define nl_Auto1473   "+"
#define pt_Auto1473   "+"
#define xx_Auto1473   "+"
#define en_Auto1474   "+"
#define fr_Auto1474   "+"
#define it_Auto1474   "+"
#define es_Auto1474   "+"
#define de_Auto1474   "+"
#define nl_Auto1474   "+"
#define pt_Auto1474   "+"
#define xx_Auto1474   "+"
#define en_Auto1475   "-"
#define fr_Auto1475   "-"
#define it_Auto1475   "-"
#define es_Auto1475   "-"
#define de_Auto1475   "-"
#define nl_Auto1475   "-"
#define pt_Auto1475   "-"
#define xx_Auto1475   "-"
#define en_Auto1476   "-"
#define fr_Auto1476   "-"
#define it_Auto1476   "-"
#define es_Auto1476   "-"
#define de_Auto1476   "-"
#define nl_Auto1476   "-"
#define pt_Auto1476   "-"
#define xx_Auto1476   "-"
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
#define en_FontSave   "Save"
#define fr_FontSave   "Sauver"
#define it_FontSave   "Save"
#define es_FontSave   "Save"
#define de_FontSave   "Save"
#define nl_FontSave   "Save"
#define pt_FontSave   "Save"
#define xx_FontSave   "Save"
#define en_FontReSize   "ReSize"
#define fr_FontReSize   "Taille"
#define it_FontReSize   "Calc"
#define es_FontReSize   "Calc"
#define de_FontReSize   "Calc"
#define nl_FontReSize   "Calc"
#define pt_FontReSize   "Calc"
#define xx_FontReSize   "Calc"
#define en_FontExport   "Export"
#define fr_FontExport   "Export"
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
#define en_Character   ""
#define en_CharacterHex   ""
#define en_CharacterDec   ""
#define en_FontCellSwitch   "FONT"
#define fr_FontCellSwitch   "FONTE"
#define it_FontCellSwitch   "FONT"
#define es_FontCellSwitch   "FONT"
#define de_FontCellSwitch   "FONT"
#define nl_FontCellSwitch   "FONT"
#define pt_FontCellSwitch   "FONT"
#define xx_FontCellSwitch   "FONT"
#define en_FontWidth   ""
#define en_FontHeight   ""
#define en_FontFile   ""
#define en_FixedFont   "Fixed|Proportional"
#define fr_FixedFont   "Fixe|Proportionelle"
#define it_FixedFont   "Fixed|Proportional"
#define es_FixedFont   "Fixed|Proportional"
#define de_FixedFont   "Fixed|Proportional"
#define nl_FixedFont   "Fixed|Proportional"
#define pt_FixedFont   "Fixed|Proportional"
#define xx_FixedFont   "Fixed|Proportional"
#define en_CrossControl   "Cursor"
#define fr_CrossControl   "Curseur"
#define it_CrossControl   "Cursor"
#define es_CrossControl   "Cursor"
#define de_CrossControl   "Cursor"
#define nl_CrossControl   "Cursor"
#define pt_CrossControl   "Cursor"
#define xx_CrossControl   "Cursor"
#define en_Column   ""
#define en_Row   ""
#define en_Auto1483   "Width"
#define fr_Auto1483   "Larg."
#define it_Auto1483   "Width"
#define es_Auto1483   "Width"
#define de_Auto1483   "Width"
#define nl_Auto1483   "Width"
#define pt_Auto1483   "Width"
#define xx_Auto1483   "Width"
#define en_Auto1484   "Height"
#define fr_Auto1484   "Haut."
#define it_Auto1484   "Height"
#define es_Auto1484   "Height"
#define de_Auto1484   "Height"
#define nl_Auto1484   "Height"
#define pt_Auto1484   "Height"
#define xx_Auto1484   "Height"
#define en_Auto1485   "Font"
#define fr_Auto1485   "Police"
#define it_Auto1485   "Font"
#define es_Auto1485   "Font"
#define de_Auto1485   "Font"
#define nl_Auto1485   "Font"
#define pt_Auto1485   "Font"
#define xx_Auto1485   "Font"
#define en_Auto1486   "Character"
#define fr_Auto1486   "CaractŠre"
#define it_Auto1486   "Character"
#define es_Auto1486   "Character"
#define de_Auto1486   "Character"
#define nl_Auto1486   "Character"
#define pt_Auto1486   "Character"
#define xx_Auto1486   "Character"
#define en_Auto1487   "Decimal"
#define fr_Auto1487   "Decimale"
#define it_Auto1487   "Decimal"
#define es_Auto1487   "Decimal"
#define de_Auto1487   "Decimal"
#define nl_Auto1487   "Decimal"
#define pt_Auto1487   "Decimal"
#define xx_Auto1487   "Decimal"
#define en_Auto1488   "Hex"
#define fr_Auto1488   "Hex"
#define it_Auto1488   "Hex"
#define es_Auto1488   "Hex"
#define de_Auto1488   "Hex"
#define nl_Auto1488   "Hex"
#define pt_Auto1488   "Hex"
#define xx_Auto1488   "Hex"
#define en_Auto1489   "Width"
#define fr_Auto1489   "Larg."
#define it_Auto1489   "Width"
#define es_Auto1489   "Width"
#define de_Auto1489   "Width"
#define nl_Auto1489   "Width"
#define pt_Auto1489   "Width"
#define xx_Auto1489   "Width"
#define en_Auto1492   "Height"
#define fr_Auto1492   "Haut."
#define it_Auto1492   "Height"
#define es_Auto1492   "Height"
#define de_Auto1492   "Height"
#define nl_Auto1492   "Height"
#define pt_Auto1492   "Height"
#define xx_Auto1492   "Height"
#define en_FontTable   ""
#define en_CharacterData   ""
#define en_vBar   ""
#define en_hBar   ""
#define en_CharacterWidth   ""
#define en_CharacterHeight   ""
static int	vfh[10];

private struct standard_font_editor_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto1462[8];
	int	x_Auto1462;
	int	y_Auto1462;
	int	w_Auto1462;
	int	h_Auto1462;
	char * msg_Auto1469[8];
	int	trigger_Auto1469;
	char * msg_Auto1470[8];
	int	trigger_Auto1470;
	char * msg_Auto1471[8];
	int	trigger_Auto1471;
	char * msg_Auto1472[8];
	int	trigger_Auto1472;
	char * msg_Auto1473[8];
	int	trigger_Auto1473;
	char * msg_Auto1474[8];
	int	trigger_Auto1474;
	char * msg_Auto1475[8];
	int	trigger_Auto1475;
	char * msg_Auto1476[8];
	int	trigger_Auto1476;
	char * msg_PreviousCharacter[8];
	int	trigger_PreviousCharacter;
	char * msg_NextCharacter[8];
	int	trigger_NextCharacter;
	char * msg_CopyCharacter[8];
	int	trigger_CopyCharacter;
	char * msg_PasteCharacter[8];
	int	trigger_PasteCharacter;
	char * msg_FontSave[8];
	int	trigger_FontSave;
	char * msg_FontReSize[8];
	int	trigger_FontReSize;
	char * msg_FontExport[8];
	int	trigger_FontExport;
	char * msg_FontFrame[8];
	int	trigger_FontFrame;
	char * msg_FontLoad[8];
	int	trigger_FontLoad;
	char	buffer_Character[3];
	char	buffer_CharacterHex[4];
	char	buffer_CharacterDec[5];
	char * msg_FontName[8];
	int	value_FontName;
	char * msg_FontCellSwitch[8];
	int	trigger_FontCellSwitch;
	int	value_FontCellSwitch;
	char	buffer_FontWidth[5];
	char	buffer_FontHeight[5];
	char	buffer_FontFile[62];
	char * msg_FixedFont[8];
	int	value_FixedFont;
	char * msg_CrossControl[8];
	int	trigger_CrossControl;
	int	value_CrossControl;
	char	buffer_Column[4];
	char	buffer_Row[4];
	char * msg_Auto1483[8];
	char * msg_Auto1484[8];
	char * msg_Auto1485[8];
	char * msg_Auto1486[8];
	char * msg_Auto1487[8];
	char * msg_Auto1488[8];
	char * msg_Auto1489[8];
	char * msg_Auto1492[8];
	int	x_FontTable;
	int	y_FontTable;
	int	w_FontTable;
	int	h_FontTable;
	int	fg_FontTable;
	int	bg_FontTable;
	int	fid_FontTable;
	char	buffer_FontTable[1105];
	int	x_CharacterData;
	int	y_CharacterData;
	int	w_CharacterData;
	int	h_CharacterData;
	int	fg_CharacterData;
	int	bg_CharacterData;
	int	fid_CharacterData;
	char	buffer_CharacterData[1176];
	int	value_vBar;
	int	limit_vBar;
	int	max_vBar;
	int	value_hBar;
	int	limit_hBar;
	int	max_hBar;
	char	buffer_CharacterWidth[5];
	char	buffer_CharacterHeight[5];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
short	stdinput(struct standard_font_editor_context * _Context);
static void	crosshair(struct standard_font_editor_context * _Context);
static void	changepixel(struct standard_font_editor_context * _Context);

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
	visual_frame(710,40,24+2,16+2,5);
visual_text(710+1,40+1,24,16,vfh[1],27,28,_Context->buffer_Column,3,3);
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
	visual_frame(710,40,24+2,16+2,5);
visual_text(710+1,40+1,24,16,vfh[1],27,28,_Context->buffer_Column,3,3);
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
	visual_frame(740,40,24+2,16+2,5);
visual_text(740+1,40+1,24,16,vfh[1],27,28,_Context->buffer_Row,3,3);
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
	visual_frame(740,40,24+2,16+2,5);
visual_text(740+1,40+1,24,16,vfh[1],27,28,_Context->buffer_Row,3,3);
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
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct standard_font_editor_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=27;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_CharacterDec, 4, pCharacterDec);
		visual_transferin((void *) 0, 0, pFontName);
		if (!( pFontName )) _Context->value_FontName=0;
		else	_Context->value_FontName = *((int *)pFontName);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto1462[i]=" ";
	_Context->msg_Auto1462[0]=en_Auto1462;
	_Context->msg_Auto1462[1]=fr_Auto1462;
	_Context->msg_Auto1462[2]=it_Auto1462;
	_Context->msg_Auto1462[3]=es_Auto1462;
	_Context->msg_Auto1462[4]=de_Auto1462;
	_Context->msg_Auto1462[5]=nl_Auto1462;
	_Context->msg_Auto1462[6]=pt_Auto1462;
	_Context->msg_Auto1462[7]=xx_Auto1462;
	_Context->x_Auto1462=0;
	_Context->y_Auto1462=0;
	_Context->w_Auto1462=790;
	_Context->h_Auto1462=590;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1469[i]=" ";
	_Context->msg_Auto1469[0]=en_Auto1469;
	_Context->msg_Auto1469[1]=fr_Auto1469;
	_Context->msg_Auto1469[2]=it_Auto1469;
	_Context->msg_Auto1469[3]=es_Auto1469;
	_Context->msg_Auto1469[4]=de_Auto1469;
	_Context->msg_Auto1469[5]=nl_Auto1469;
	_Context->msg_Auto1469[6]=pt_Auto1469;
	_Context->msg_Auto1469[7]=xx_Auto1469;
	for (i=0; i < 8; i++)_Context->msg_Auto1470[i]=" ";
	_Context->msg_Auto1470[0]=en_Auto1470;
	_Context->msg_Auto1470[1]=fr_Auto1470;
	_Context->msg_Auto1470[2]=it_Auto1470;
	_Context->msg_Auto1470[3]=es_Auto1470;
	_Context->msg_Auto1470[4]=de_Auto1470;
	_Context->msg_Auto1470[5]=nl_Auto1470;
	_Context->msg_Auto1470[6]=pt_Auto1470;
	_Context->msg_Auto1470[7]=xx_Auto1470;
	for (i=0; i < 8; i++)_Context->msg_Auto1471[i]=" ";
	_Context->msg_Auto1471[0]=en_Auto1471;
	_Context->msg_Auto1471[1]=fr_Auto1471;
	_Context->msg_Auto1471[2]=it_Auto1471;
	_Context->msg_Auto1471[3]=es_Auto1471;
	_Context->msg_Auto1471[4]=de_Auto1471;
	_Context->msg_Auto1471[5]=nl_Auto1471;
	_Context->msg_Auto1471[6]=pt_Auto1471;
	_Context->msg_Auto1471[7]=xx_Auto1471;
	for (i=0; i < 8; i++)_Context->msg_Auto1472[i]=" ";
	_Context->msg_Auto1472[0]=en_Auto1472;
	_Context->msg_Auto1472[1]=fr_Auto1472;
	_Context->msg_Auto1472[2]=it_Auto1472;
	_Context->msg_Auto1472[3]=es_Auto1472;
	_Context->msg_Auto1472[4]=de_Auto1472;
	_Context->msg_Auto1472[5]=nl_Auto1472;
	_Context->msg_Auto1472[6]=pt_Auto1472;
	_Context->msg_Auto1472[7]=xx_Auto1472;
	for (i=0; i < 8; i++)_Context->msg_Auto1473[i]=" ";
	_Context->msg_Auto1473[0]=en_Auto1473;
	_Context->msg_Auto1473[1]=fr_Auto1473;
	_Context->msg_Auto1473[2]=it_Auto1473;
	_Context->msg_Auto1473[3]=es_Auto1473;
	_Context->msg_Auto1473[4]=de_Auto1473;
	_Context->msg_Auto1473[5]=nl_Auto1473;
	_Context->msg_Auto1473[6]=pt_Auto1473;
	_Context->msg_Auto1473[7]=xx_Auto1473;
	for (i=0; i < 8; i++)_Context->msg_Auto1474[i]=" ";
	_Context->msg_Auto1474[0]=en_Auto1474;
	_Context->msg_Auto1474[1]=fr_Auto1474;
	_Context->msg_Auto1474[2]=it_Auto1474;
	_Context->msg_Auto1474[3]=es_Auto1474;
	_Context->msg_Auto1474[4]=de_Auto1474;
	_Context->msg_Auto1474[5]=nl_Auto1474;
	_Context->msg_Auto1474[6]=pt_Auto1474;
	_Context->msg_Auto1474[7]=xx_Auto1474;
	for (i=0; i < 8; i++)_Context->msg_Auto1475[i]=" ";
	_Context->msg_Auto1475[0]=en_Auto1475;
	_Context->msg_Auto1475[1]=fr_Auto1475;
	_Context->msg_Auto1475[2]=it_Auto1475;
	_Context->msg_Auto1475[3]=es_Auto1475;
	_Context->msg_Auto1475[4]=de_Auto1475;
	_Context->msg_Auto1475[5]=nl_Auto1475;
	_Context->msg_Auto1475[6]=pt_Auto1475;
	_Context->msg_Auto1475[7]=xx_Auto1475;
	for (i=0; i < 8; i++)_Context->msg_Auto1476[i]=" ";
	_Context->msg_Auto1476[0]=en_Auto1476;
	_Context->msg_Auto1476[1]=fr_Auto1476;
	_Context->msg_Auto1476[2]=it_Auto1476;
	_Context->msg_Auto1476[3]=es_Auto1476;
	_Context->msg_Auto1476[4]=de_Auto1476;
	_Context->msg_Auto1476[5]=nl_Auto1476;
	_Context->msg_Auto1476[6]=pt_Auto1476;
	_Context->msg_Auto1476[7]=xx_Auto1476;
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
	for (i=0; i < 8; i++)_Context->msg_FontSave[i]=" ";
	_Context->msg_FontSave[0]=en_FontSave;
	_Context->msg_FontSave[1]=fr_FontSave;
	_Context->msg_FontSave[2]=it_FontSave;
	_Context->msg_FontSave[3]=es_FontSave;
	_Context->msg_FontSave[4]=de_FontSave;
	_Context->msg_FontSave[5]=nl_FontSave;
	_Context->msg_FontSave[6]=pt_FontSave;
	_Context->msg_FontSave[7]=xx_FontSave;
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
	for (i=0; i < 8; i++)_Context->msg_FontName[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_FontCellSwitch[i]=" ";
	_Context->msg_FontCellSwitch[0]=en_FontCellSwitch;
	_Context->msg_FontCellSwitch[1]=fr_FontCellSwitch;
	_Context->msg_FontCellSwitch[2]=it_FontCellSwitch;
	_Context->msg_FontCellSwitch[3]=es_FontCellSwitch;
	_Context->msg_FontCellSwitch[4]=de_FontCellSwitch;
	_Context->msg_FontCellSwitch[5]=nl_FontCellSwitch;
	_Context->msg_FontCellSwitch[6]=pt_FontCellSwitch;
	_Context->msg_FontCellSwitch[7]=xx_FontCellSwitch;
	for (i=0; i < 8; i++)_Context->msg_FixedFont[i]=" ";
	_Context->msg_FixedFont[0]=en_FixedFont;
	_Context->msg_FixedFont[1]=fr_FixedFont;
	_Context->msg_FixedFont[2]=it_FixedFont;
	_Context->msg_FixedFont[3]=es_FixedFont;
	_Context->msg_FixedFont[4]=de_FixedFont;
	_Context->msg_FixedFont[5]=nl_FixedFont;
	_Context->msg_FixedFont[6]=pt_FixedFont;
	_Context->msg_FixedFont[7]=xx_FixedFont;
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
	_Context->value_CrossControl=0;
	(void) on_Column_create(_Context);
	(void) on_Row_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto1483[i]=" ";
	_Context->msg_Auto1483[0]=en_Auto1483;
	_Context->msg_Auto1483[1]=fr_Auto1483;
	_Context->msg_Auto1483[2]=it_Auto1483;
	_Context->msg_Auto1483[3]=es_Auto1483;
	_Context->msg_Auto1483[4]=de_Auto1483;
	_Context->msg_Auto1483[5]=nl_Auto1483;
	_Context->msg_Auto1483[6]=pt_Auto1483;
	_Context->msg_Auto1483[7]=xx_Auto1483;
	for (i=0; i < 8; i++)_Context->msg_Auto1484[i]=" ";
	_Context->msg_Auto1484[0]=en_Auto1484;
	_Context->msg_Auto1484[1]=fr_Auto1484;
	_Context->msg_Auto1484[2]=it_Auto1484;
	_Context->msg_Auto1484[3]=es_Auto1484;
	_Context->msg_Auto1484[4]=de_Auto1484;
	_Context->msg_Auto1484[5]=nl_Auto1484;
	_Context->msg_Auto1484[6]=pt_Auto1484;
	_Context->msg_Auto1484[7]=xx_Auto1484;
	for (i=0; i < 8; i++)_Context->msg_Auto1485[i]=" ";
	_Context->msg_Auto1485[0]=en_Auto1485;
	_Context->msg_Auto1485[1]=fr_Auto1485;
	_Context->msg_Auto1485[2]=it_Auto1485;
	_Context->msg_Auto1485[3]=es_Auto1485;
	_Context->msg_Auto1485[4]=de_Auto1485;
	_Context->msg_Auto1485[5]=nl_Auto1485;
	_Context->msg_Auto1485[6]=pt_Auto1485;
	_Context->msg_Auto1485[7]=xx_Auto1485;
	for (i=0; i < 8; i++)_Context->msg_Auto1486[i]=" ";
	_Context->msg_Auto1486[0]=en_Auto1486;
	_Context->msg_Auto1486[1]=fr_Auto1486;
	_Context->msg_Auto1486[2]=it_Auto1486;
	_Context->msg_Auto1486[3]=es_Auto1486;
	_Context->msg_Auto1486[4]=de_Auto1486;
	_Context->msg_Auto1486[5]=nl_Auto1486;
	_Context->msg_Auto1486[6]=pt_Auto1486;
	_Context->msg_Auto1486[7]=xx_Auto1486;
	for (i=0; i < 8; i++)_Context->msg_Auto1487[i]=" ";
	_Context->msg_Auto1487[0]=en_Auto1487;
	_Context->msg_Auto1487[1]=fr_Auto1487;
	_Context->msg_Auto1487[2]=it_Auto1487;
	_Context->msg_Auto1487[3]=es_Auto1487;
	_Context->msg_Auto1487[4]=de_Auto1487;
	_Context->msg_Auto1487[5]=nl_Auto1487;
	_Context->msg_Auto1487[6]=pt_Auto1487;
	_Context->msg_Auto1487[7]=xx_Auto1487;
	for (i=0; i < 8; i++)_Context->msg_Auto1488[i]=" ";
	_Context->msg_Auto1488[0]=en_Auto1488;
	_Context->msg_Auto1488[1]=fr_Auto1488;
	_Context->msg_Auto1488[2]=it_Auto1488;
	_Context->msg_Auto1488[3]=es_Auto1488;
	_Context->msg_Auto1488[4]=de_Auto1488;
	_Context->msg_Auto1488[5]=nl_Auto1488;
	_Context->msg_Auto1488[6]=pt_Auto1488;
	_Context->msg_Auto1488[7]=xx_Auto1488;
	for (i=0; i < 8; i++)_Context->msg_Auto1489[i]=" ";
	_Context->msg_Auto1489[0]=en_Auto1489;
	_Context->msg_Auto1489[1]=fr_Auto1489;
	_Context->msg_Auto1489[2]=it_Auto1489;
	_Context->msg_Auto1489[3]=es_Auto1489;
	_Context->msg_Auto1489[4]=de_Auto1489;
	_Context->msg_Auto1489[5]=nl_Auto1489;
	_Context->msg_Auto1489[6]=pt_Auto1489;
	_Context->msg_Auto1489[7]=xx_Auto1489;
	for (i=0; i < 8; i++)_Context->msg_Auto1492[i]=" ";
	_Context->msg_Auto1492[0]=en_Auto1492;
	_Context->msg_Auto1492[1]=fr_Auto1492;
	_Context->msg_Auto1492[2]=it_Auto1492;
	_Context->msg_Auto1492[3]=es_Auto1492;
	_Context->msg_Auto1492[4]=de_Auto1492;
	_Context->msg_Auto1492[5]=nl_Auto1492;
	_Context->msg_Auto1492[6]=pt_Auto1492;
	_Context->msg_Auto1492[7]=xx_Auto1492;
	_Context->x_FontTable=390;
	_Context->y_FontTable=110;
	_Context->w_FontTable=368;
	_Context->h_FontTable=384;
	_Context->fg_FontTable=384;
	_Context->bg_FontTable=384;
	_Context->fid_FontTable=1;
	(void) on_FontTable_create(_Context);
	_Context->x_CharacterData=10;
	_Context->y_CharacterData=110;
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
	visual_frame(80,40,16+2,16+2,5);
visual_text(80+1,40+1,16,16,vfh[1],27,28,_Context->buffer_Character,2,3);
;
	return(-1);
}
private int on_CharacterHex_show(struct standard_font_editor_context * _Context) {
	sprintf(_Context->buffer_CharacterHex,"%x",atoi(_Context->buffer_CharacterDec));
	visual_frame(140,40,24+2,16+2,5);
visual_text(140+1,40+1,24,16,vfh[1],27,28,_Context->buffer_CharacterHex,3,3);
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
	visual_frame(590,40,32+2,16+2,5);
visual_text(590+1,40+1,32,16,vfh[1],27,28,_Context->buffer_FontWidth,4,0);
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
	visual_frame(590,70,32+2,16+2,5);
visual_text(590+1,70+1,32,16,vfh[1],27,28,_Context->buffer_FontHeight,4,0);
;
	return(-1);
}
private int on_FontFile_show(struct standard_font_editor_context * _Context) {
	char*nptr;
	char*guifontname(int);
	int f;
	int i;
	f=(_Context->value_FontName+1);
	if(!(nptr=guifontname(f)))
	nptr=" ";
	for(i=0;i<61;i++){
	if(!(*(nptr+i)))
	break;
	else*(_Context->buffer_FontFile+i)=*(nptr+i);
	}
	for(;i<61;i++)
	*(_Context->buffer_FontFile+i)=' ';
	visual_frame(20,70,488+2,16+2,5);
visual_text(20+1,70+1,488,16,vfh[1],27,28,_Context->buffer_FontFile,61,0);
;
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
	visual_frame(120,530,32+2,16+2,5);
visual_text(120+1,530+1,32,16,vfh[1],27,28,_Context->buffer_CharacterWidth,4,0);
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
	visual_frame(120,550,32+2,16+2,5);
visual_text(120+1,550+1,32,16,vfh[1],27,28,_Context->buffer_CharacterHeight,4,0);
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
	visual_window(0,0,790,590,vfh[2],_Context->msg_Auto1462[_Context->language],strlen(_Context->msg_Auto1462[_Context->language]),0x407);
	visual_frame(10,520,770,60,2);
	visual_frame(10,30,770,70,2);
	_Context->trigger_Auto1469=visual_trigger_code(_Context->msg_Auto1469[_Context->language],strlen(_Context->msg_Auto1469[_Context->language]));
	visual_button(630,40,16,16,vfh[8],27,28,_Context->msg_Auto1469[_Context->language],strlen(_Context->msg_Auto1469[_Context->language]),0);
	_Context->trigger_Auto1470=visual_trigger_code(_Context->msg_Auto1470[_Context->language],strlen(_Context->msg_Auto1470[_Context->language]));
	visual_button(630,70,16,16,vfh[8],27,28,_Context->msg_Auto1470[_Context->language],strlen(_Context->msg_Auto1470[_Context->language]),0);
	_Context->trigger_Auto1471=visual_trigger_code(_Context->msg_Auto1471[_Context->language],strlen(_Context->msg_Auto1471[_Context->language]));
	visual_button(570,70,16,16,vfh[8],27,28,_Context->msg_Auto1471[_Context->language],strlen(_Context->msg_Auto1471[_Context->language]),0);
	_Context->trigger_Auto1472=visual_trigger_code(_Context->msg_Auto1472[_Context->language],strlen(_Context->msg_Auto1472[_Context->language]));
	visual_button(570,40,16,16,vfh[8],27,28,_Context->msg_Auto1472[_Context->language],strlen(_Context->msg_Auto1472[_Context->language]),0);
	_Context->trigger_Auto1473=visual_trigger_code(_Context->msg_Auto1473[_Context->language],strlen(_Context->msg_Auto1473[_Context->language]));
	visual_button(160,530,16,16,vfh[8],27,28,_Context->msg_Auto1473[_Context->language],strlen(_Context->msg_Auto1473[_Context->language]),0);
	_Context->trigger_Auto1474=visual_trigger_code(_Context->msg_Auto1474[_Context->language],strlen(_Context->msg_Auto1474[_Context->language]));
	visual_button(160,550,16,16,vfh[8],27,28,_Context->msg_Auto1474[_Context->language],strlen(_Context->msg_Auto1474[_Context->language]),0);
	_Context->trigger_Auto1475=visual_trigger_code(_Context->msg_Auto1475[_Context->language],strlen(_Context->msg_Auto1475[_Context->language]));
	visual_button(100,550,16,16,vfh[8],27,28,_Context->msg_Auto1475[_Context->language],strlen(_Context->msg_Auto1475[_Context->language]),0);
	_Context->trigger_Auto1476=visual_trigger_code(_Context->msg_Auto1476[_Context->language],strlen(_Context->msg_Auto1476[_Context->language]));
	visual_button(100,530,16,16,vfh[8],27,28,_Context->msg_Auto1476[_Context->language],strlen(_Context->msg_Auto1476[_Context->language]),0);
	_Context->trigger_PreviousCharacter=visual_trigger_code(_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]));
	visual_button(20,530,28,34,vfh[2],27,28,_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]),0);
	_Context->trigger_NextCharacter=visual_trigger_code(_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]));
	visual_button(180,530,28,34,vfh[2],27,28,_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]),0);
	_Context->trigger_CopyCharacter=visual_trigger_code(_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]));
	visual_button(220,530,70,34,vfh[2],27,28,_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]),0);
	_Context->trigger_PasteCharacter=visual_trigger_code(_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]));
	visual_button(300,530,70,34,vfh[2],27,28,_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]),0);
	_Context->trigger_FontSave=visual_trigger_code(_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]));
	visual_button(380,530,70,34,vfh[2],16,0,_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]),0);
	_Context->trigger_FontReSize=visual_trigger_code(_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]));
	visual_button(460,530,70,34,vfh[2],16,0,_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]),0);
	_Context->trigger_FontExport=visual_trigger_code(_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]));
	visual_button(540,530,70,34,vfh[2],16,0,_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]),0);
	_Context->trigger_FontFrame=visual_trigger_code(_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]));
	visual_button(620,530,70,34,vfh[2],16,0,_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]),0);
	_Context->trigger_FontLoad=visual_trigger_code(_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]));
	visual_button(700,530,70,34,vfh[2],16,0,_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]),0);
	(void) on_Character_show(_Context);
	(void) on_CharacterHex_show(_Context);
	visual_frame(230,40,32+2,16+2,5);
	visual_text(230+1,40+1,32,16,vfh[1],27,28,_Context->buffer_CharacterDec,4,0);
	visual_select(310,40,144,160,vfh[1],34,0,parse_selection(TextFontList,&_Context->value_FontName),0);
	_Context->trigger_FontCellSwitch=visual_trigger_code(_Context->msg_FontCellSwitch[_Context->language],strlen(_Context->msg_FontCellSwitch[_Context->language]));
	visual_switch(460,40,48,16,vfh[1],44,31,_Context->msg_FontCellSwitch[_Context->language],strlen(_Context->msg_FontCellSwitch[_Context->language]),_Context->value_FontCellSwitch| 0x0000);
	(void) on_FontWidth_show(_Context);
	(void) on_FontHeight_show(_Context);
	(void) on_FontFile_show(_Context);
	visual_select(650,70,120,48,vfh[1],31,44,parse_selection(_Context->msg_FixedFont[_Context->language],&_Context->value_FixedFont),0);
	_Context->trigger_CrossControl=visual_trigger_code(_Context->msg_CrossControl[_Context->language],strlen(_Context->msg_CrossControl[_Context->language]));
	visual_switch(650,40,56,16,vfh[1],44,31,_Context->msg_CrossControl[_Context->language],strlen(_Context->msg_CrossControl[_Context->language]),_Context->value_CrossControl| 0x0000);
	visual_frame(710,40,24+2,16+2,5);
	visual_text(710+1,40+1,24,16,vfh[1],27,28,_Context->buffer_Column,3,3);
	visual_frame(740,40,24+2,16+2,5);
	visual_text(740+1,40+1,24,16,vfh[1],27,28,_Context->buffer_Row,3,3);
	visual_text(520,40,56,17,vfh[2],16,0,_Context->msg_Auto1483[_Context->language],strlen(_Context->msg_Auto1483[_Context->language]),1282);
	visual_text(520,70,56,17,vfh[2],16,0,_Context->msg_Auto1484[_Context->language],strlen(_Context->msg_Auto1484[_Context->language]),1282);
	visual_text(270,40,56,17,vfh[2],16,0,_Context->msg_Auto1485[_Context->language],strlen(_Context->msg_Auto1485[_Context->language]),1282);
	visual_text(20,40,70,17,vfh[2],16,0,_Context->msg_Auto1486[_Context->language],strlen(_Context->msg_Auto1486[_Context->language]),1282);
	visual_text(170,40,56,16,vfh[2],16,0,_Context->msg_Auto1487[_Context->language],strlen(_Context->msg_Auto1487[_Context->language]),1282);
	visual_text(110,40,28,17,vfh[2],16,0,_Context->msg_Auto1488[_Context->language],strlen(_Context->msg_Auto1488[_Context->language]),1282);
	visual_text(60,530,42,17,vfh[2],16,0,_Context->msg_Auto1489[_Context->language],strlen(_Context->msg_Auto1489[_Context->language]),1282);
	visual_text(60,550,42,16,vfh[2],16,0,_Context->msg_Auto1492[_Context->language],strlen(_Context->msg_Auto1492[_Context->language]),1282);
	(void) on_FontTable_show(_Context);
	(void) on_CharacterData_show(_Context);
	visual_scrollbar(760,110,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
	visual_scrollbar(390,492,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
	(void) on_CharacterWidth_show(_Context);
	(void) on_CharacterHeight_show(_Context);
	visual_thaw(0,0,790,590);
	visual_thaw(0,0,790,590);

	return(0);
}
private int on_Auto1469_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),6,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto1470_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),8,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto1471_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),7,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto1472_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),5,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto1473_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),2,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto1474_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),4,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto1475_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),3,0);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto1476_event(struct standard_font_editor_context * _Context) {
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
	visual_frame(230,40,32+2,16+2,5);
visual_text(230+1,40+1,32,16,vfh[1],27,28,_Context->buffer_CharacterDec,4,0);
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
	visual_frame(230,40,32+2,16+2,5);
visual_text(230+1,40+1,32,16,vfh[1],27,28,_Context->buffer_CharacterDec,4,0);
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
	if(!(font_paste_cell(c,f)))
	on_CharacterData_show(_Context);
	return(-1);
}
private int on_FontSave_event(struct standard_font_editor_context * _Context) {
	char*allocate_string(char*);
	char*sptr;
	if((sptr=allocate_string(_Context->buffer_FontFile))!=(char*)0){
	if(accept_fontsave(&sptr)!=27)
	guifontsave(_Context->value_FontName+1,sptr);
	if(sptr)
	liberate(sptr);
	}
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
	if((sptr=allocate_string(_Context->buffer_FontFile))!=(char*)0){
	if(accept_fontload(&sptr,&isansi)!=27){
	holder=iso_conversion_value(isansi);
	load_font(_Context->value_FontName+1,sptr);
	holder=iso_conversion_value(holder);
	on_FontName_losefocus(_Context);
	}
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
	mx=visual_event(7);
	my=visual_event(6);
	if(((x=((mx-_Context->x_CharacterData)/cellw))<fw)
	&&((y=((my-_Context->y_CharacterData)/cellh))<fh)){
	sprintf(_Context->buffer_Column,"%u",(x+1));
	visual_frame(710,40,24+2,16+2,5);
visual_text(710+1,40+1,24,16,vfh[1],27,28,_Context->buffer_Column,3,3);
;
	sprintf(_Context->buffer_Row,"%u",(y+1));
	visual_frame(740,40,24+2,16+2,5);
visual_text(740+1,40+1,24,16,vfh[1],27,28,_Context->buffer_Row,3,3);
;
	if(visual_event(2)==_MIMO_LEFT)
	changepixel(_Context);
	else on_CharacterData_show(_Context);
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
	if ( visual_event(6) < (110+20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_vBar -= 1;
		if (_Context->value_vBar < 0) 
			_Context->value_vBar = 0;
		(void) on_vBar_event(_Context);
	visual_scrollbar(760,110,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
		return(-1);
		}
	if ( visual_event(6) > (110+380-20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_vBar += 1;
		if (_Context->value_vBar > (_Context->max_vBar-_Context->limit_vBar)) 
			_Context->value_vBar = (_Context->max_vBar-_Context->limit_vBar);
		(void) on_vBar_event(_Context);
	visual_scrollbar(760,110,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
		return(-1);
		}
	visual_scrollbar(760,110,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);

	do {
		while(stdinput(_Context) != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_vBar;
		_Context->value_vBar = (((visual_event(6) - (110+20)) * _Context->max_vBar) / (380 - (2 * 20)));
		if (_Context->value_vBar < 0) 
			_Context->value_vBar = 0;
		else if (_Context->value_vBar > (_Context->max_vBar-_Context->limit_vBar)) 
			_Context->value_vBar = (_Context->max_vBar-_Context->limit_vBar);
		if (_Context->value_vBar != aty) {
		(void) on_vBar_event(_Context);
	visual_scrollbar(760,110,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
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
	visual_scrollbar(760,110,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_vBar += (_Context->limit_vBar/2);
			if (_Context->value_vBar > (_Context->max_vBar-_Context->limit_vBar)) 
				_Context->value_vBar = (_Context->max_vBar-_Context->limit_vBar);
		(void) on_vBar_event(_Context);
	visual_scrollbar(760,110,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
			break;
		}
	visual_scrollbar(760,110,20,380,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);

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
	visual_scrollbar(390,492,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
		return(-1);
		}
	if ( visual_event(7) > (390+370-20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_hBar += 1;
		if (_Context->value_hBar > (_Context->max_hBar-_Context->limit_hBar)) 
			_Context->value_hBar = (_Context->max_hBar-_Context->limit_hBar);
		(void) on_hBar_event(_Context);
	visual_scrollbar(390,492,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
		return(-1);
		}
	visual_scrollbar(390,492,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);

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
	visual_scrollbar(390,492,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
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
	visual_scrollbar(390,492,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_hBar += (_Context->limit_hBar/2);
			if (_Context->value_hBar > (_Context->max_hBar-_Context->limit_hBar)) 
				_Context->value_hBar = (_Context->max_hBar-_Context->limit_hBar);
		(void) on_hBar_event(_Context);
	visual_scrollbar(390,492,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
			break;
		}
	visual_scrollbar(390,492,370,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);

	return(1);
}


public	int	standard_font_editor_event(
struct standard_font_editor_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto1469 == mb ) return(2);
		if (_Context->trigger_Auto1470 == mb ) return(3);
		if (_Context->trigger_Auto1471 == mb ) return(4);
		if (_Context->trigger_Auto1472 == mb ) return(5);
		if (_Context->trigger_Auto1473 == mb ) return(6);
		if (_Context->trigger_Auto1474 == mb ) return(7);
		if (_Context->trigger_Auto1475 == mb ) return(8);
		if (_Context->trigger_Auto1476 == mb ) return(9);
		if (_Context->trigger_PreviousCharacter == mb ) return(10);
		if (_Context->trigger_NextCharacter == mb ) return(11);
		if (_Context->trigger_CopyCharacter == mb ) return(12);
		if (_Context->trigger_PasteCharacter == mb ) return(13);
		if (_Context->trigger_FontSave == mb ) return(14);
		if (_Context->trigger_FontReSize == mb ) return(15);
		if (_Context->trigger_FontExport == mb ) return(16);
		if (_Context->trigger_FontFrame == mb ) return(17);
		if (_Context->trigger_FontLoad == mb ) return(18);
		if (_Context->trigger_FontCellSwitch == mb ) return(21);
		if (_Context->trigger_CrossControl == mb ) return(23);
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
		return(1);	/* Auto1462 */

		}
	if ((mx >= 753 )  
	&&  (my >= 4 )  
	&&  (mx <= 769 )  
	&&  (my <= 20 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vstdfont.htm");
			};
		return(-1);	/* Auto1462 */

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
		return(-1);	/* Auto1462 */

		}
		}
	if (( mx >= 630 ) 
	&&  ( my >= 40 ) 
	&&  ( mx <= 646 ) 
	&&  ( my <= 56 )) {
		return(2); /* Auto1469 */
		}
	if (( mx >= 630 ) 
	&&  ( my >= 70 ) 
	&&  ( mx <= 646 ) 
	&&  ( my <= 86 )) {
		return(3); /* Auto1470 */
		}
	if (( mx >= 570 ) 
	&&  ( my >= 70 ) 
	&&  ( mx <= 586 ) 
	&&  ( my <= 86 )) {
		return(4); /* Auto1471 */
		}
	if (( mx >= 570 ) 
	&&  ( my >= 40 ) 
	&&  ( mx <= 586 ) 
	&&  ( my <= 56 )) {
		return(5); /* Auto1472 */
		}
	if (( mx >= 160 ) 
	&&  ( my >= 530 ) 
	&&  ( mx <= 176 ) 
	&&  ( my <= 546 )) {
		return(6); /* Auto1473 */
		}
	if (( mx >= 160 ) 
	&&  ( my >= 550 ) 
	&&  ( mx <= 176 ) 
	&&  ( my <= 566 )) {
		return(7); /* Auto1474 */
		}
	if (( mx >= 100 ) 
	&&  ( my >= 550 ) 
	&&  ( mx <= 116 ) 
	&&  ( my <= 566 )) {
		return(8); /* Auto1475 */
		}
	if (( mx >= 100 ) 
	&&  ( my >= 530 ) 
	&&  ( mx <= 116 ) 
	&&  ( my <= 546 )) {
		return(9); /* Auto1476 */
		}
	if (( mx >= 20 ) 
	&&  ( my >= 530 ) 
	&&  ( mx <= 48 ) 
	&&  ( my <= 564 )) {
		return(10); /* PreviousCharacter */
		}
	if (( mx >= 180 ) 
	&&  ( my >= 530 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 564 )) {
		return(11); /* NextCharacter */
		}
	if (( mx >= 220 ) 
	&&  ( my >= 530 ) 
	&&  ( mx <= 290 ) 
	&&  ( my <= 564 )) {
		return(12); /* CopyCharacter */
		}
	if (( mx >= 300 ) 
	&&  ( my >= 530 ) 
	&&  ( mx <= 370 ) 
	&&  ( my <= 564 )) {
		return(13); /* PasteCharacter */
		}
	if (( mx >= 380 ) 
	&&  ( my >= 530 ) 
	&&  ( mx <= 450 ) 
	&&  ( my <= 564 )) {
		return(14); /* FontSave */
		}
	if (( mx >= 460 ) 
	&&  ( my >= 530 ) 
	&&  ( mx <= 530 ) 
	&&  ( my <= 564 )) {
		return(15); /* FontReSize */
		}
	if (( mx >= 540 ) 
	&&  ( my >= 530 ) 
	&&  ( mx <= 610 ) 
	&&  ( my <= 564 )) {
		return(16); /* FontExport */
		}
	if (( mx >= 620 ) 
	&&  ( my >= 530 ) 
	&&  ( mx <= 690 ) 
	&&  ( my <= 564 )) {
		return(17); /* FontFrame */
		}
	if (( mx >= 700 ) 
	&&  ( my >= 530 ) 
	&&  ( mx <= 770 ) 
	&&  ( my <= 564 )) {
		return(18); /* FontLoad */
		}
	if (( mx >= 230 ) 
	&&  ( my >= 40 ) 
	&&  ( mx <= 262 ) 
	&&  ( my <= 56 )) {
		return(19); /* CharacterDec */
		}
	if ((mx >= 310 ) 
	&&  (my >= 40 ) 
	&&  (mx <= 454 ) 
	&&  (my <= 56 )) {
		return(20); /* FontName */
		}
	if (( mx >= 460 ) 
	&&  ( my >= 40 ) 
	&&  ( mx <= 508 ) 
	&&  ( my <= 56 )) {
		return(21); /* FontCellSwitch */
		}
	if ((mx >= 650 ) 
	&&  (my >= 70 ) 
	&&  (mx <= 770 ) 
	&&  (my <= 86 )) {
		return(22); /* FixedFont */
		}
	if (( mx >= 650 ) 
	&&  ( my >= 40 ) 
	&&  ( mx <= 706 ) 
	&&  ( my <= 56 )) {
		return(23); /* CrossControl */
		}
	if ((mx >= _Context->x_FontTable ) 
	&&  (my >= _Context->y_FontTable ) 
	&&  (mx <  (_Context->x_FontTable+_Context->w_FontTable)) 
	&&  (my <  (_Context->y_FontTable+_Context->h_FontTable))) {
		return(24); /* FontTable */
		}
	if ((mx >= _Context->x_CharacterData ) 
	&&  (my >= _Context->y_CharacterData ) 
	&&  (mx <  (_Context->x_CharacterData+_Context->w_CharacterData)) 
	&&  (my <  (_Context->y_CharacterData+_Context->h_CharacterData))) {
		return(25); /* CharacterData */
		}
	if (( mx >= 760 ) 
	&&  ( my >= 110 ) 
	&&  ( mx <= 780 ) 
	&&  ( my <= 490 )) {
		return(26); /* vBar */
		}
	if (( mx >= 390 ) 
	&&  ( my >= 492 ) 
	&&  ( mx <= 760 ) 
	&&  ( my <= 512 )) {
		return(27); /* hBar */
		}

	return(-1);
}
private int on_CharacterDec_losefocus(struct standard_font_editor_context * _Context) {
	visual_frame(230,40,32+2,16+2,5);
visual_text(230+1,40+1,32,16,vfh[1],27,28,_Context->buffer_CharacterDec,4,0);
;
	on_CharacterHex_show(_Context);
	on_Character_show(_Context);
	on_CharacterData_show(_Context);
	on_CharacterWidth_show(_Context);
	on_CharacterHeight_show(_Context);
	return(-1);
}
private int on_FontName_losefocus(struct standard_font_editor_context * _Context) {
		standard_font_editor_hide(_Context);
;
		standard_font_editor_show(_Context);
;
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
			case	0x2 :
				/* Auto1469 */
				visual_button(630,40,16,16,vfh[8],27,28,_Context->msg_Auto1469[_Context->language],strlen(_Context->msg_Auto1469[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(630,40,16,16,vfh[8],27,28,_Context->msg_Auto1469[_Context->language],strlen(_Context->msg_Auto1469[_Context->language]),0);
				break;
			case	0x3 :
				/* Auto1470 */
				visual_button(630,70,16,16,vfh[8],27,28,_Context->msg_Auto1470[_Context->language],strlen(_Context->msg_Auto1470[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(630,70,16,16,vfh[8],27,28,_Context->msg_Auto1470[_Context->language],strlen(_Context->msg_Auto1470[_Context->language]),0);
				break;
			case	0x4 :
				/* Auto1471 */
				visual_button(570,70,16,16,vfh[8],27,28,_Context->msg_Auto1471[_Context->language],strlen(_Context->msg_Auto1471[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(570,70,16,16,vfh[8],27,28,_Context->msg_Auto1471[_Context->language],strlen(_Context->msg_Auto1471[_Context->language]),0);
				break;
			case	0x5 :
				/* Auto1472 */
				visual_button(570,40,16,16,vfh[8],27,28,_Context->msg_Auto1472[_Context->language],strlen(_Context->msg_Auto1472[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(570,40,16,16,vfh[8],27,28,_Context->msg_Auto1472[_Context->language],strlen(_Context->msg_Auto1472[_Context->language]),0);
				break;
			case	0x6 :
				/* Auto1473 */
				visual_button(160,530,16,16,vfh[8],27,28,_Context->msg_Auto1473[_Context->language],strlen(_Context->msg_Auto1473[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(160,530,16,16,vfh[8],27,28,_Context->msg_Auto1473[_Context->language],strlen(_Context->msg_Auto1473[_Context->language]),0);
				break;
			case	0x7 :
				/* Auto1474 */
				visual_button(160,550,16,16,vfh[8],27,28,_Context->msg_Auto1474[_Context->language],strlen(_Context->msg_Auto1474[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(160,550,16,16,vfh[8],27,28,_Context->msg_Auto1474[_Context->language],strlen(_Context->msg_Auto1474[_Context->language]),0);
				break;
			case	0x8 :
				/* Auto1475 */
				visual_button(100,550,16,16,vfh[8],27,28,_Context->msg_Auto1475[_Context->language],strlen(_Context->msg_Auto1475[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(100,550,16,16,vfh[8],27,28,_Context->msg_Auto1475[_Context->language],strlen(_Context->msg_Auto1475[_Context->language]),0);
				break;
			case	0x9 :
				/* Auto1476 */
				visual_button(100,530,16,16,vfh[8],27,28,_Context->msg_Auto1476[_Context->language],strlen(_Context->msg_Auto1476[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(100,530,16,16,vfh[8],27,28,_Context->msg_Auto1476[_Context->language],strlen(_Context->msg_Auto1476[_Context->language]),0);
				break;
			case	0xa :
				/* PreviousCharacter */
				visual_button(20,530,28,34,vfh[2],27,28,_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(20,530,28,34,vfh[2],27,28,_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]),0);
				break;
			case	0xb :
				/* NextCharacter */
				visual_button(180,530,28,34,vfh[2],27,28,_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(180,530,28,34,vfh[2],27,28,_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]),0);
				break;
			case	0xc :
				/* CopyCharacter */
				visual_button(220,530,70,34,vfh[2],27,28,_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(220,530,70,34,vfh[2],27,28,_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]),0);
				break;
			case	0xd :
				/* PasteCharacter */
				visual_button(300,530,70,34,vfh[2],27,28,_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(300,530,70,34,vfh[2],27,28,_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]),0);
				break;
			case	0xe :
				/* FontSave */
				visual_button(380,530,70,34,vfh[2],16,0,_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(380,530,70,34,vfh[2],16,0,_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]),0);
				break;
			case	0xf :
				/* FontReSize */
				visual_button(460,530,70,34,vfh[2],16,0,_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(460,530,70,34,vfh[2],16,0,_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]),0);
				break;
			case	0x10 :
				/* FontExport */
				visual_button(540,530,70,34,vfh[2],16,0,_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(540,530,70,34,vfh[2],16,0,_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]),0);
				break;
			case	0x11 :
				/* FontFrame */
				visual_button(620,530,70,34,vfh[2],16,0,_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(620,530,70,34,vfh[2],16,0,_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]),0);
				break;
			case	0x12 :
				/* FontLoad */
				visual_button(700,530,70,34,vfh[2],16,0,_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]),2);
				_Context->keycode = stdinput(_Context);
				visual_button(700,530,70,34,vfh[2],16,0,_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]),0);
				break;
			case	0x13 :
				/* CharacterDec */
				_Context->keycode = visual_edit(230+1,40+1,32,16,vfh[1],_Context->buffer_CharacterDec,4);
				(void) on_CharacterDec_losefocus(_Context);
			break;
			case	0x14 :
				/* FontName */
				_Context->keycode = visual_select(310,40,144,160,vfh[1],34,0,parse_selection(TextFontList,&_Context->value_FontName),2);
				(void) on_FontName_losefocus(_Context);
				break;
			case	0x15 :
				/* FontCellSwitch */
				visual_switch(460,40,48,16,vfh[1],44,31,_Context->msg_FontCellSwitch[_Context->language],strlen(_Context->msg_FontCellSwitch[_Context->language]),(_Context->value_FontCellSwitch | 2 | 0x0000 ));
				_Context->keycode = stdinput(_Context);
				visual_switch(460,40,48,16,vfh[1],44,31,_Context->msg_FontCellSwitch[_Context->language],strlen(_Context->msg_FontCellSwitch[_Context->language]),(_Context->value_FontCellSwitch | 0 | 0x0000 ));
				break;
			case	0x16 :
				/* FixedFont */
				_Context->keycode = visual_select(650,70,120,48,vfh[1],31,44,parse_selection(_Context->msg_FixedFont[_Context->language],&_Context->value_FixedFont),2);
				break;
			case	0x17 :
				/* CrossControl */
				visual_switch(650,40,56,16,vfh[1],44,31,_Context->msg_CrossControl[_Context->language],strlen(_Context->msg_CrossControl[_Context->language]),(_Context->value_CrossControl | 2 | 0x0000 ));
				_Context->keycode = stdinput(_Context);
				visual_switch(650,40,56,16,vfh[1],44,31,_Context->msg_CrossControl[_Context->language],strlen(_Context->msg_CrossControl[_Context->language]),(_Context->value_CrossControl | 0 | 0x0000 ));
				break;
			case	0x19 :
				/* CharacterData */
				if ((_Context->keycode = on_CharacterData_getfocus(_Context)) != -1) break;
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
			_Context->focus_item=27;
			standard_font_editor_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=standard_font_editor_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1462 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Auto1469 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(630,40,16,16,vfh[8],27,28,_Context->msg_Auto1469[_Context->language],strlen(_Context->msg_Auto1469[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(630,40,16,16,vfh[8],27,28,_Context->msg_Auto1469[_Context->language],strlen(_Context->msg_Auto1469[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1469_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Auto1470 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(630,70,16,16,vfh[8],27,28,_Context->msg_Auto1470[_Context->language],strlen(_Context->msg_Auto1470[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(630,70,16,16,vfh[8],27,28,_Context->msg_Auto1470[_Context->language],strlen(_Context->msg_Auto1470[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1470_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto1471 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(570,70,16,16,vfh[8],27,28,_Context->msg_Auto1471[_Context->language],strlen(_Context->msg_Auto1471[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(570,70,16,16,vfh[8],27,28,_Context->msg_Auto1471[_Context->language],strlen(_Context->msg_Auto1471[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1471_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Auto1472 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(570,40,16,16,vfh[8],27,28,_Context->msg_Auto1472[_Context->language],strlen(_Context->msg_Auto1472[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(570,40,16,16,vfh[8],27,28,_Context->msg_Auto1472[_Context->language],strlen(_Context->msg_Auto1472[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1472_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* Auto1473 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(160,530,16,16,vfh[8],27,28,_Context->msg_Auto1473[_Context->language],strlen(_Context->msg_Auto1473[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(160,530,16,16,vfh[8],27,28,_Context->msg_Auto1473[_Context->language],strlen(_Context->msg_Auto1473[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1473_event(_Context)) != -1) break;

							}
						continue;
					case	0x7 :
						/* Auto1474 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(160,550,16,16,vfh[8],27,28,_Context->msg_Auto1474[_Context->language],strlen(_Context->msg_Auto1474[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(160,550,16,16,vfh[8],27,28,_Context->msg_Auto1474[_Context->language],strlen(_Context->msg_Auto1474[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1474_event(_Context)) != -1) break;

							}
						continue;
					case	0x8 :
						/* Auto1475 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(100,550,16,16,vfh[8],27,28,_Context->msg_Auto1475[_Context->language],strlen(_Context->msg_Auto1475[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(100,550,16,16,vfh[8],27,28,_Context->msg_Auto1475[_Context->language],strlen(_Context->msg_Auto1475[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1475_event(_Context)) != -1) break;

							}
						continue;
					case	0x9 :
						/* Auto1476 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(100,530,16,16,vfh[8],27,28,_Context->msg_Auto1476[_Context->language],strlen(_Context->msg_Auto1476[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(100,530,16,16,vfh[8],27,28,_Context->msg_Auto1476[_Context->language],strlen(_Context->msg_Auto1476[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1476_event(_Context)) != -1) break;

							}
						continue;
					case	0xa :
						/* PreviousCharacter */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(20,530,28,34,vfh[2],27,28,_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(20,530,28,34,vfh[2],27,28,_Context->msg_PreviousCharacter[_Context->language],strlen(_Context->msg_PreviousCharacter[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_PreviousCharacter_event(_Context)) != -1) break;

							}
						continue;
					case	0xb :
						/* NextCharacter */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(180,530,28,34,vfh[2],27,28,_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(180,530,28,34,vfh[2],27,28,_Context->msg_NextCharacter[_Context->language],strlen(_Context->msg_NextCharacter[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_NextCharacter_event(_Context)) != -1) break;

							}
						continue;
					case	0xc :
						/* CopyCharacter */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(220,530,70,34,vfh[2],27,28,_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(220,530,70,34,vfh[2],27,28,_Context->msg_CopyCharacter[_Context->language],strlen(_Context->msg_CopyCharacter[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_CopyCharacter_event(_Context)) != -1) break;

							}
						continue;
					case	0xd :
						/* PasteCharacter */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(300,530,70,34,vfh[2],27,28,_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(300,530,70,34,vfh[2],27,28,_Context->msg_PasteCharacter[_Context->language],strlen(_Context->msg_PasteCharacter[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_PasteCharacter_event(_Context)) != -1) break;

							}
						continue;
					case	0xe :
						/* FontSave */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(380,530,70,34,vfh[2],16,0,_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(380,530,70,34,vfh[2],16,0,_Context->msg_FontSave[_Context->language],strlen(_Context->msg_FontSave[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FontSave_event(_Context)) != -1) break;

							}
						continue;
					case	0xf :
						/* FontReSize */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(460,530,70,34,vfh[2],16,0,_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(460,530,70,34,vfh[2],16,0,_Context->msg_FontReSize[_Context->language],strlen(_Context->msg_FontReSize[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FontReSize_event(_Context)) != -1) break;

							}
						continue;
					case	0x10 :
						/* FontExport */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(540,530,70,34,vfh[2],16,0,_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(540,530,70,34,vfh[2],16,0,_Context->msg_FontExport[_Context->language],strlen(_Context->msg_FontExport[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FontExport_event(_Context)) != -1) break;

							}
						continue;
					case	0x11 :
						/* FontFrame */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(620,530,70,34,vfh[2],16,0,_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(620,530,70,34,vfh[2],16,0,_Context->msg_FontFrame[_Context->language],strlen(_Context->msg_FontFrame[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FontFrame_event(_Context)) != -1) break;

							}
						continue;
					case	0x12 :
						/* FontLoad */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(700,530,70,34,vfh[2],16,0,_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(700,530,70,34,vfh[2],16,0,_Context->msg_FontLoad[_Context->language],strlen(_Context->msg_FontLoad[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FontLoad_event(_Context)) != -1) break;

							}
						continue;
					case	0x13 :
						/* CharacterDec */
						continue;
					case	0x14 :
						/* FontName */
						continue;
					case	0x15 :
						/* FontCellSwitch */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_FontCellSwitch += 1;
							_Context->value_FontCellSwitch &= 1;
							}
						continue;
					case	0x16 :
						/* FixedFont */
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FixedFont_event(_Context)) != -1) break;

							}
						continue;
					case	0x17 :
						/* CrossControl */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_CrossControl += 1;
							_Context->value_CrossControl &= 1;
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_CrossControl_event(_Context)) != -1) break;

							}
						continue;
					case	0x18 :
						/* FontTable */
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FontTable_event(_Context)) != -1) break;

							}
						continue;
					case	0x19 :
						/* CharacterData */
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_CharacterData_event(_Context)) != -1) break;

							}
						continue;
					case	0x1a :
						/* vBar */
						(void) on_vBar_action(_Context);
						continue;
					case	0x1b :
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
				_Context->focus_item=27;
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

	while( visual_kbhit() ) (void) stdinput(_Context);
	return(status);
}
/* End of File */

#endif /* _vstdfont_c */
