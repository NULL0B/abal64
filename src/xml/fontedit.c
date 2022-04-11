
#ifndef _fontedit_c
#define _fontedit_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vfont.xml                                                */
/* Target         : fontedit.c                                               */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct standard_font_editor_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	x_Auto3557;
	int	y_Auto3557;
	int	w_Auto3557;
	int	h_Auto3557;
	char	buffer_CharacterDec[5];
	int	value_CrossControl;
	char	buffer_Character[4];
	char	buffer_CharacterHex[5];
	int	value_FontName;
	int	x_FontTable;
	int	y_FontTable;
	int	w_FontTable;
	int	h_FontTable;
	int	fg_FontTable;
	int	bg_FontTable;
	int	fid_FontTable;
	char	buffer_FontTable[881];
	int	x_CharacterData;
	int	y_CharacterData;
	int	w_CharacterData;
	int	h_CharacterData;
	int	fg_CharacterData;
	int	bg_CharacterData;
	int	fid_CharacterData;
	char	buffer_CharacterData[967];
	int	value_vBar;
	int	limit_vBar;
	int	max_vBar;
	int	value_hBar;
	int	limit_hBar;
	int	max_hBar;
	char	buffer_FontFile[87];
	char	buffer_FontWidth[5];
	char	buffer_FontHeight[5];
	char	buffer_CharacterWidth[5];
	char	buffer_Column[5];
	char	buffer_Row[5];
	char	buffer_CharacterHeight[5];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];
private int on_FontTable_create(struct standard_font_editor_context * _Context);
private int on_CharacterData_create(struct standard_font_editor_context * _Context);
private int on_Column_create(struct standard_font_editor_context * _Context);
private int on_Row_create(struct standard_font_editor_context * _Context);
private int on_Character_show(struct standard_font_editor_context * _Context);
private int on_CharacterHex_show(struct standard_font_editor_context * _Context);
private int on_FontTable_show(struct standard_font_editor_context * _Context);
private int on_CharacterData_show(struct standard_font_editor_context * _Context);
private int on_FontFile_show(struct standard_font_editor_context * _Context);
private int on_FontWidth_show(struct standard_font_editor_context * _Context);
private int on_FontHeight_show(struct standard_font_editor_context * _Context);
private int on_CharacterWidth_show(struct standard_font_editor_context * _Context);
private int on_Column_show(struct standard_font_editor_context * _Context);
private int on_Row_show(struct standard_font_editor_context * _Context);
private int on_CharacterHeight_show(struct standard_font_editor_context * _Context);
private int on_CharacterDec_losefocus(struct standard_font_editor_context * _Context);
private int on_FontName_losefocus(struct standard_font_editor_context * _Context);
private int on_Auto3560_event(struct standard_font_editor_context * _Context);
private int on_Auto3561_event(struct standard_font_editor_context * _Context);
private int on_Auto3562_event(struct standard_font_editor_context * _Context);
private int on_Auto3563_event(struct standard_font_editor_context * _Context);
private int on_Auto3564_event(struct standard_font_editor_context * _Context);
private int on_Auto3565_event(struct standard_font_editor_context * _Context);
private int on_Auto3566_event(struct standard_font_editor_context * _Context);
private int on_Auto3567_event(struct standard_font_editor_context * _Context);
private int on_Auto3568_event(struct standard_font_editor_context * _Context);
private int on_Auto3569_event(struct standard_font_editor_context * _Context);
private int on_Auto3573_event(struct standard_font_editor_context * _Context);
private int on_CrossControl_event(struct standard_font_editor_context * _Context);
private int on_FontTable_event(struct standard_font_editor_context * _Context);
private int on_CharacterData_event(struct standard_font_editor_context * _Context);
private int on_vBar_event(struct standard_font_editor_context * _Context);
private int on_hBar_event(struct standard_font_editor_context * _Context);
private int on_FontTable_create(struct standard_font_editor_context * _Context) {
	int i;
	for(i=0;i<880;i++)
	*(_Context->buffer_FontTable+1)=' ';
	return(-1);
}
private int on_CharacterData_create(struct standard_font_editor_context * _Context) {
	int i;
	for(i=0;i<966;i++)
	*(_Context->buffer_CharacterData+i)=' ';
	return(-1);
}
private int on_Column_create(struct standard_font_editor_context * _Context) {
	sprintf(_Context->buffer_Column,"%u",1);
		return(-1);
}
private int on_Row_create(struct standard_font_editor_context * _Context) {
	sprintf(_Context->buffer_Row,"%u",1);
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
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=27;
		_Context->value_CrossControl=0;
		for (i=0; i < 3; i++)  *(_Context->buffer_Character+i)=' ';
		for (i=0; i < 4; i++)  *(_Context->buffer_CharacterHex+i)=' ';
		for (i=0; i < 880; i++)  *(_Context->buffer_FontTable+i)=' ';
		for (i=0; i < 966; i++)  *(_Context->buffer_CharacterData+i)=' ';
		_Context->max_vBar=0;
		_Context->limit_vBar=0;
		_Context->value_vBar=0;
		_Context->max_hBar=0;
		_Context->limit_hBar=0;
		_Context->value_hBar=0;
		for (i=0; i < 86; i++)  *(_Context->buffer_FontFile+i)=' ';
		for (i=0; i < 4; i++)  *(_Context->buffer_FontWidth+i)=' ';
		for (i=0; i < 4; i++)  *(_Context->buffer_FontHeight+i)=' ';
		for (i=0; i < 4; i++)  *(_Context->buffer_CharacterWidth+i)=' ';
		for (i=0; i < 4; i++)  *(_Context->buffer_Column+i)=' ';
		for (i=0; i < 4; i++)  *(_Context->buffer_Row+i)=' ';
		for (i=0; i < 4; i++)  *(_Context->buffer_CharacterHeight+i)=' ';
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_CharacterDec, 4, pCharacterDec);
		visual_transferin((void *) 0, 0, pFontName);
		if (!( pFontName )) _Context->value_FontName=0;
		else	_Context->value_FontName = *((int *)pFontName);
		}
	_Context->x_Auto3557=50;
	_Context->y_Auto3557=30;
	_Context->w_Auto3557=750;
	_Context->h_Auto3557=560;
	_Context->window_col=50;
	_Context->window_row=30;
	add_font_editor_menu();
	_Context->value_CrossControl=1;
	_Context->x_FontTable=430;
	_Context->y_FontTable=110;
	_Context->w_FontTable=320;
	_Context->h_FontTable=352;
	_Context->fg_FontTable=352;
	_Context->bg_FontTable=352;
	_Context->fid_FontTable=1;
	(void) on_FontTable_create(_Context);
	_Context->x_CharacterData=80;
	_Context->y_CharacterData=110;
	_Context->w_CharacterData=336;
	_Context->h_CharacterData=368;
	_Context->fg_CharacterData=368;
	_Context->bg_CharacterData=368;
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
	(void) on_Column_create(_Context);
	(void) on_Row_create(_Context);
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(50,30,750,560);
	return(0);
}

public 	int	standard_font_editor_hide(struct standard_font_editor_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,50,30);
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
	drop_font_editor_menu();
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
	visual_frame(150,70,24+2,16+2,5);
visual_text(150+1,70+1,24,16,vfh[1],27,28,_Context->buffer_Character,3,3);
;
	return(-1);
}
private int on_CharacterHex_show(struct standard_font_editor_context * _Context) {
	sprintf(_Context->buffer_CharacterHex,"%x",atoi(_Context->buffer_CharacterDec));
	visual_frame(220,70,32+2,16+2,5);
visual_text(220+1,70+1,32,16,vfh[1],27,28,_Context->buffer_CharacterHex,4,3);
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
visual_text(_Context->x_FontTable+1,_Context->y_FontTable+1,_Context->w_FontTable,_Context->h_FontTable,_Context->fid_FontTable,27,28,_Context->buffer_FontTable,880,0);
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
visual_text(_Context->x_CharacterData+1,_Context->y_CharacterData+1,_Context->w_CharacterData,_Context->h_CharacterData,_Context->fid_CharacterData,27,28,_Context->buffer_CharacterData,966,0);
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
private int on_FontFile_show(struct standard_font_editor_context * _Context) {
	char*nptr;
	char*guifontname(int);
	int f;
	int i;
	f=(_Context->value_FontName+1);
	if(!(nptr=guifontname(f)))
	nptr=" ";
	for(i=0;i<86;i++){
	if(!(*(nptr+i)))
	break;
	else*(_Context->buffer_FontFile+i)=*(nptr+i);
	}
	for(;i<86;i++)
	*(_Context->buffer_FontFile+i)=' ';
	visual_frame(80,550,688+2,16+2,5);
visual_text(80+1,550+1,688,16,vfh[1],27,28,_Context->buffer_FontFile,86,0);
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
	visual_frame(700,500,32+2,16+2,5);
visual_text(700+1,500+1,32,16,vfh[1],27,28,_Context->buffer_FontWidth,4,0);
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
	visual_frame(700,520,32+2,16+2,5);
visual_text(700+1,520+1,32,16,vfh[1],27,28,_Context->buffer_FontHeight,4,0);
;
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
	visual_frame(200,500,32+2,16+2,5);
visual_text(200+1,500+1,32,16,vfh[1],27,28,_Context->buffer_CharacterWidth,4,0);
;
	return(-1);
}
private int on_Column_show(struct standard_font_editor_context * _Context) {
	int fw;
	int c;
	int f;
	c=atoi(_Context->buffer_CharacterDec);
	f=(_Context->value_FontName+1);
	fw=(fontcharactersize(c,f)&0x00FF);
	sprintf(_Context->buffer_Column,"%u",fw);
	visual_frame(340,500,32+2,16+2,5);
visual_text(340+1,500+1,32,16,vfh[1],27,28,_Context->buffer_Column,4,3);
;
	return(-1);
}
private int on_Row_show(struct standard_font_editor_context * _Context) {
	int fw;
	int c;
	int f;
	c=atoi(_Context->buffer_CharacterDec);
	f=(_Context->value_FontName+1);
	fw=(fontcharactersize(c,f)&0x00FF);
	sprintf(_Context->buffer_Row,"%u",fw);
	visual_frame(340,520,32+2,16+2,5);
visual_text(340+1,520+1,32,16,vfh[1],27,28,_Context->buffer_Row,4,3);
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
	visual_frame(200,520,32+2,16+2,5);
visual_text(200+1,520+1,32,16,vfh[1],27,28,_Context->buffer_CharacterHeight,4,0);
;
	return(-1);
}

public	int	standard_font_editor_show(struct standard_font_editor_context * _Context)
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,50,30);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(50,30,750,560,vfh[2],"Sing 1.0a : Font Editor",strlen("Sing 1.0a : Font Editor"),0x1);
	visual_frame(70,490,710,90,2);
	visual_frame(70,60,710,40,2);
	visual_button(80,500,28,34,vfh[2],27,28,"-",strlen("-"),0);
	visual_button(390,500,28,34,vfh[2],27,28,"+",strlen("+"),0);
	visual_button(740,500,16,16,vfh[8],27,28,"+",strlen("+"),0);
	visual_button(740,520,16,16,vfh[8],27,28,"+",strlen("+"),0);
	visual_button(680,520,16,16,vfh[8],27,28,"-",strlen("-"),0);
	visual_button(680,500,16,16,vfh[8],27,28,"-",strlen("-"),0);
	visual_button(240,500,16,16,vfh[8],27,28,"+",strlen("+"),0);
	visual_button(240,520,16,16,vfh[8],27,28,"+",strlen("+"),0);
	visual_button(180,520,16,16,vfh[8],27,28,"-",strlen("-"),0);
	visual_button(180,500,16,16,vfh[8],27,28,"-",strlen("-"),0);
	visual_button(550,500,56,34,vfh[2],16,0,"Load",strlen("Load"),0);
	visual_button(520,500,28,34,vfh[2],16,0,"AB",strlen("AB"),0);
	visual_button(490,500,28,34,vfh[2],16,0,"AB",strlen("AB"),0);
	visual_button(430,500,56,34,vfh[2],16,0,"Save",strlen("Save"),0);
	visual_frame(330,70,32+2,16+2,5);
	visual_text(330+1,70+1,32,16,vfh[1],27,28,_Context->buffer_CharacterDec,4,0);
	visual_switch(380,70,28,16,vfh[2],212,127,"X",strlen("X"),_Context->value_CrossControl| 0x0030);
	(void) on_Character_show(_Context);
	(void) on_CharacterHex_show(_Context);
	visual_select(480,70,280,96,vfh[1],34,0,parse_selection(TextFontList,&_Context->value_FontName),0);
	visual_text(620,500,56,17,vfh[2],16,0,"Width",strlen("Width"),1282);
	visual_text(620,520,56,17,vfh[2],16,0,"Height",strlen("Height"),1282);
	visual_text(430,70,42,17,vfh[2],16,0,"Font",strlen("Font"),1282);
	visual_text(80,70,84,17,vfh[2],16,0,"Character",strlen("Character"),1282);
	visual_text(270,70,56,17,vfh[2],16,0,"Decimal",strlen("Decimal"),1282);
	visual_text(190,70,28,17,vfh[2],16,0,"Hex",strlen("Hex"),1282);
	visual_text(120,500,56,17,vfh[2],16,0,"Width",strlen("Width"),1282);
	visual_text(280,500,56,17,vfh[2],16,0,"Column",strlen("Column"),1283);
	visual_text(280,520,56,17,vfh[2],16,0,"Row",strlen("Row"),1282);
	visual_text(120,520,56,17,vfh[2],16,0,"Height",strlen("Height"),1282);
	(void) on_FontTable_show(_Context);
	(void) on_CharacterData_show(_Context);
	visual_scrollbar(754,110,20,350,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
	visual_scrollbar(430,465,323,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
	(void) on_FontFile_show(_Context);
	(void) on_FontWidth_show(_Context);
	(void) on_FontHeight_show(_Context);
	(void) on_CharacterWidth_show(_Context);
	(void) on_Column_show(_Context);
	(void) on_Row_show(_Context);
	(void) on_CharacterHeight_show(_Context);
	visual_thaw(50,30,750,560);

	return(0);
}
private int on_Auto3560_event(struct standard_font_editor_context * _Context) {
	int v;
	v=atoi(_Context->buffer_CharacterDec);
	if(v>0)
	v-=1;
	else v=255;
	sprintf(_Context->buffer_CharacterDec,"%u",v);
	on_CharacterDec_losefocus(_Context);
	#ifdef old_merde
	visual_frame(330,70,32+2,16+2,5);
visual_text(330+1,70+1,32,16,vfh[1],27,28,_Context->buffer_CharacterDec,4,0);
;
	on_CharacterHex_show(_Context);
	on_Character_show(_Context);
	on_CharacterData_show(_Context);
	on_CharacterWidth_show(_Context);
	on_CharacterHeight_show(_Context);
	#endif
	return(-1);
}
private int on_Auto3561_event(struct standard_font_editor_context * _Context) {
	int v;
	v=((atoi(_Context->buffer_CharacterDec)+1)&0x00FF);
	sprintf(_Context->buffer_CharacterDec,"%u",v);
	on_CharacterDec_losefocus(_Context);
	#ifdef old_merde
	visual_frame(330,70,32+2,16+2,5);
visual_text(330+1,70+1,32,16,vfh[1],27,28,_Context->buffer_CharacterDec,4,0);
;
	on_CharacterHex_show(_Context);
	on_Character_show(_Context);
	on_CharacterData_show(_Context);
	on_CharacterWidth_show(_Context);
	on_CharacterHeight_show(_Context);
	#endif
	return(-1);
}
private int on_Auto3562_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),6);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3563_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),8);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3564_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),7);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3565_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),5);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3566_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),2);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3567_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),4);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3568_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),3);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3569_event(struct standard_font_editor_context * _Context) {
	guifontfunction(_Context->value_FontName+1,atoi(_Context->buffer_CharacterDec),1);
		standard_font_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3573_event(struct standard_font_editor_context * _Context) {
	char*allocate_string(char*);
	char*sptr;
	if((sptr=allocate_string(_Context->buffer_FontFile))!=(char*)0){
	if(accept_fontsave(&sptr)!=27)
	guifontsave(_Context->value_FontName+1,sptr);
	liberate(sptr);
	}
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
	char*dptr;
	char*fontcharacterdata(int,int);
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
	mx=visual_event(7);
	my=visual_event(6);
	if(((x=((mx-_Context->x_CharacterData)/cellw))<fw)
	&&((y=((my-_Context->y_CharacterData)/cellh))<fh)){
	if(visual_event(2)==_MIMO_LEFT){
	if(*(dptr+((y*fw)+x))!=0)
	*(dptr+((y*fw)+x))=0;
	else*(dptr+((y*fw)+x))=1;
	}
	sprintf(_Context->buffer_Column,"%u",x);
	visual_frame(340,500,32+2,16+2,5);
visual_text(340+1,500+1,32,16,vfh[1],27,28,_Context->buffer_Column,4,3);
;
	sprintf(_Context->buffer_Row,"%u",y);
	visual_frame(340,520,32+2,16+2,5);
visual_text(340+1,520+1,32,16,vfh[1],27,28,_Context->buffer_Row,4,3);
;
	on_CharacterData_show(_Context);
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
	visual_scrollbar(754,110,20,350,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
		return(-1);
		}
	if ( visual_event(6) > (110+350-20) ) {
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
	visual_scrollbar(754,110,20,350,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
		return(-1);
		}
	visual_scrollbar(754,110,20,350,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);

	do {
		while(stdinput(_Context) != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_vBar;
		_Context->value_vBar = (((visual_event(6) - (110+20)) * _Context->max_vBar) / (350 - (2 * 20)));
		if (_Context->value_vBar < 0) 
			_Context->value_vBar = 0;
		else if (_Context->value_vBar > (_Context->max_vBar-_Context->limit_vBar)) 
			_Context->value_vBar = (_Context->max_vBar-_Context->limit_vBar);
		if (_Context->value_vBar != aty) {
		(void) on_vBar_event(_Context);
	visual_scrollbar(754,110,20,350,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
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
	visual_scrollbar(754,110,20,350,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
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
	visual_scrollbar(754,110,20,350,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
			break;
		}
	visual_scrollbar(754,110,20,350,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);

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

	if ( visual_event(7) < (430+20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_hBar -= 1;
		if (_Context->value_hBar < 0) 
			_Context->value_hBar = 0;
		(void) on_hBar_event(_Context);
	visual_scrollbar(430,465,323,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
		return(-1);
		}
	if ( visual_event(7) > (430+323-20) ) {
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
	visual_scrollbar(430,465,323,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
		return(-1);
		}
	visual_scrollbar(430,465,323,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);

	do {
		while(stdinput(_Context) != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		atx = _Context->value_hBar;
		_Context->value_hBar = (((visual_event(7) - (430+20)) * _Context->max_hBar) / (323 - (2 * 20)));
		if (_Context->value_hBar < 0) 
			_Context->value_hBar = 0;
		else if (_Context->value_hBar > (_Context->max_hBar-_Context->limit_hBar)) 
			_Context->value_hBar = (_Context->max_hBar-_Context->limit_hBar);
		if (_Context->value_hBar != atx) {
		(void) on_hBar_event(_Context);
	visual_scrollbar(430,465,323,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
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
	visual_scrollbar(430,465,323,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
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
	visual_scrollbar(430,465,323,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
			break;
		}
	visual_scrollbar(430,465,323,20,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);

	return(1);
}


public	int	standard_font_editor_event(
struct standard_font_editor_context * _Context){
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= 779 )  
	&&  (my >= 34 )  
	&&  (mx <= 795 )  
	&&  (my <= 50 )) {
		return(1);	/* Auto3557 */

		}
		}
	if (( mx >= 80 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 108 ) 
	&&  ( my <= 534 )) {
		return(2); /* Auto3560 */
		}
	if (( mx >= 390 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 418 ) 
	&&  ( my <= 534 )) {
		return(3); /* Auto3561 */
		}
	if (( mx >= 740 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 756 ) 
	&&  ( my <= 516 )) {
		return(4); /* Auto3562 */
		}
	if (( mx >= 740 ) 
	&&  ( my >= 520 ) 
	&&  ( mx <= 756 ) 
	&&  ( my <= 536 )) {
		return(5); /* Auto3563 */
		}
	if (( mx >= 680 ) 
	&&  ( my >= 520 ) 
	&&  ( mx <= 696 ) 
	&&  ( my <= 536 )) {
		return(6); /* Auto3564 */
		}
	if (( mx >= 680 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 696 ) 
	&&  ( my <= 516 )) {
		return(7); /* Auto3565 */
		}
	if (( mx >= 240 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 256 ) 
	&&  ( my <= 516 )) {
		return(8); /* Auto3566 */
		}
	if (( mx >= 240 ) 
	&&  ( my >= 520 ) 
	&&  ( mx <= 256 ) 
	&&  ( my <= 536 )) {
		return(9); /* Auto3567 */
		}
	if (( mx >= 180 ) 
	&&  ( my >= 520 ) 
	&&  ( mx <= 196 ) 
	&&  ( my <= 536 )) {
		return(10); /* Auto3568 */
		}
	if (( mx >= 180 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 196 ) 
	&&  ( my <= 516 )) {
		return(11); /* Auto3569 */
		}
	if (( mx >= 550 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 606 ) 
	&&  ( my <= 534 )) {
		return(12); /* Auto3570 */
		}
	if (( mx >= 520 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 548 ) 
	&&  ( my <= 534 )) {
		return(13); /* Auto3571 */
		}
	if (( mx >= 490 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 518 ) 
	&&  ( my <= 534 )) {
		return(14); /* Auto3572 */
		}
	if (( mx >= 430 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 486 ) 
	&&  ( my <= 534 )) {
		return(15); /* Auto3573 */
		}
	if (( mx >= 330 ) 
	&&  ( my >= 70 ) 
	&&  ( mx <= 362 ) 
	&&  ( my <= 86 )) {
		return(16); /* CharacterDec */
		}
	if (( mx >= 380 ) 
	&&  ( my >= 70 ) 
	&&  ( mx <= 408 ) 
	&&  ( my <= 86 )) {
		return(17); /* CrossControl */
		}
	if ((mx >= 480 ) 
	&&  (my >= 70 ) 
	&&  (mx <= 760 ) 
	&&  (my <= 86 )) {
		return(18); /* FontName */
		}
	if ((mx >= _Context->x_FontTable ) 
	&&  (my >= _Context->y_FontTable ) 
	&&  (mx <  (_Context->x_FontTable+_Context->w_FontTable)) 
	&&  (my <  (_Context->y_FontTable+_Context->h_FontTable))) {
		return(19); /* FontTable */
		}
	if ((mx >= _Context->x_CharacterData ) 
	&&  (my >= _Context->y_CharacterData ) 
	&&  (mx <  (_Context->x_CharacterData+_Context->w_CharacterData)) 
	&&  (my <  (_Context->y_CharacterData+_Context->h_CharacterData))) {
		return(20); /* CharacterData */
		}
	if (( mx >= 754 ) 
	&&  ( my >= 110 ) 
	&&  ( mx <= 774 ) 
	&&  ( my <= 460 )) {
		return(21); /* vBar */
		}
	if (( mx >= 430 ) 
	&&  ( my >= 465 ) 
	&&  ( mx <= 753 ) 
	&&  ( my <= 485 )) {
		return(22); /* hBar */
		}
	if (( mx >= 80 ) 
	&&  ( my >= 550 ) 
	&&  ( mx <= 768 ) 
	&&  ( my <= 566 )) {
		return(23); /* FontFile */
		}
	if (( mx >= 700 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 732 ) 
	&&  ( my <= 516 )) {
		return(24); /* FontWidth */
		}
	if (( mx >= 700 ) 
	&&  ( my >= 520 ) 
	&&  ( mx <= 732 ) 
	&&  ( my <= 536 )) {
		return(25); /* FontHeight */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 232 ) 
	&&  ( my <= 516 )) {
		return(26); /* CharacterWidth */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 520 ) 
	&&  ( mx <= 232 ) 
	&&  ( my <= 536 )) {
		return(27); /* CharacterHeight */
		}

	return(-1);
}
private int on_CharacterDec_losefocus(struct standard_font_editor_context * _Context) {
	visual_frame(330,70,32+2,16+2,5);
visual_text(330+1,70+1,32,16,vfh[1],27,28,_Context->buffer_CharacterDec,4,0);
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


public	int	standard_font_editor_focus(struct standard_font_editor_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto3560 */
				visual_button(80,500,28,34,vfh[2],27,28,"-",strlen("-"),2);
				_Context->keycode = stdinput(_Context);
	visual_button(80,500,28,34,vfh[2],27,28,"-",strlen("-"),0);
				break;
			case	0x3 :
				/* Auto3561 */
				visual_button(390,500,28,34,vfh[2],27,28,"+",strlen("+"),2);
				_Context->keycode = stdinput(_Context);
	visual_button(390,500,28,34,vfh[2],27,28,"+",strlen("+"),0);
				break;
			case	0x4 :
				/* Auto3562 */
				visual_button(740,500,16,16,vfh[8],27,28,"+",strlen("+"),2);
				_Context->keycode = stdinput(_Context);
	visual_button(740,500,16,16,vfh[8],27,28,"+",strlen("+"),0);
				break;
			case	0x5 :
				/* Auto3563 */
				visual_button(740,520,16,16,vfh[8],27,28,"+",strlen("+"),2);
				_Context->keycode = stdinput(_Context);
	visual_button(740,520,16,16,vfh[8],27,28,"+",strlen("+"),0);
				break;
			case	0x6 :
				/* Auto3564 */
				visual_button(680,520,16,16,vfh[8],27,28,"-",strlen("-"),2);
				_Context->keycode = stdinput(_Context);
	visual_button(680,520,16,16,vfh[8],27,28,"-",strlen("-"),0);
				break;
			case	0x7 :
				/* Auto3565 */
				visual_button(680,500,16,16,vfh[8],27,28,"-",strlen("-"),2);
				_Context->keycode = stdinput(_Context);
	visual_button(680,500,16,16,vfh[8],27,28,"-",strlen("-"),0);
				break;
			case	0x8 :
				/* Auto3566 */
				visual_button(240,500,16,16,vfh[8],27,28,"+",strlen("+"),2);
				_Context->keycode = stdinput(_Context);
	visual_button(240,500,16,16,vfh[8],27,28,"+",strlen("+"),0);
				break;
			case	0x9 :
				/* Auto3567 */
				visual_button(240,520,16,16,vfh[8],27,28,"+",strlen("+"),2);
				_Context->keycode = stdinput(_Context);
	visual_button(240,520,16,16,vfh[8],27,28,"+",strlen("+"),0);
				break;
			case	0xa :
				/* Auto3568 */
				visual_button(180,520,16,16,vfh[8],27,28,"-",strlen("-"),2);
				_Context->keycode = stdinput(_Context);
	visual_button(180,520,16,16,vfh[8],27,28,"-",strlen("-"),0);
				break;
			case	0xb :
				/* Auto3569 */
				visual_button(180,500,16,16,vfh[8],27,28,"-",strlen("-"),2);
				_Context->keycode = stdinput(_Context);
	visual_button(180,500,16,16,vfh[8],27,28,"-",strlen("-"),0);
				break;
			case	0xc :
				/* Auto3570 */
				visual_button(550,500,56,34,vfh[2],16,0,"Load",strlen("Load"),2);
				_Context->keycode = stdinput(_Context);
	visual_button(550,500,56,34,vfh[2],16,0,"Load",strlen("Load"),0);
				break;
			case	0xd :
				/* Auto3571 */
				visual_button(520,500,28,34,vfh[2],16,0,"AB",strlen("AB"),2);
				_Context->keycode = stdinput(_Context);
	visual_button(520,500,28,34,vfh[2],16,0,"AB",strlen("AB"),0);
				break;
			case	0xe :
				/* Auto3572 */
				visual_button(490,500,28,34,vfh[2],16,0,"AB",strlen("AB"),2);
				_Context->keycode = stdinput(_Context);
	visual_button(490,500,28,34,vfh[2],16,0,"AB",strlen("AB"),0);
				break;
			case	0xf :
				/* Auto3573 */
				visual_button(430,500,56,34,vfh[2],16,0,"Save",strlen("Save"),2);
				_Context->keycode = stdinput(_Context);
	visual_button(430,500,56,34,vfh[2],16,0,"Save",strlen("Save"),0);
				break;
			case	0x10 :
				/* CharacterDec */
				_Context->keycode = visual_edit(330+1,70+1,32,16,vfh[1],_Context->buffer_CharacterDec,4);
				(void) on_CharacterDec_losefocus(_Context);
			break;
			case	0x11 :
				/* CrossControl */
				visual_switch(380,70,28,16,vfh[2],212,127,"X",strlen("X"),(_Context->value_CrossControl | 2 | 0x0030 ));
				_Context->keycode = stdinput(_Context);
	visual_switch(380,70,28,16,vfh[2],212,127,"X",strlen("X"),_Context->value_CrossControl| 0x0030);
				break;
			case	0x12 :
				/* FontName */
				_Context->keycode = visual_select(480,70,280,96,vfh[1],34,0,parse_selection(TextFontList,&_Context->value_FontName),2);
				(void) on_FontName_losefocus(_Context);
				break;
			case	0x17 :
				/* FontFile */
				_Context->keycode = visual_edit(80+1,550+1,688,16,vfh[1],_Context->buffer_FontFile,86);
			break;
			case	0x18 :
				/* FontWidth */
				_Context->keycode = visual_edit(700+1,500+1,32,16,vfh[1],_Context->buffer_FontWidth,4);
			break;
			case	0x19 :
				/* FontHeight */
				_Context->keycode = visual_edit(700+1,520+1,32,16,vfh[1],_Context->buffer_FontHeight,4);
			break;
			case	0x1a :
				/* CharacterWidth */
				_Context->keycode = visual_edit(200+1,500+1,32,16,vfh[1],_Context->buffer_CharacterWidth,4);
			break;
			case	0x1b :
				/* CharacterHeight */
				_Context->keycode = visual_edit(200+1,520+1,32,16,vfh[1],_Context->buffer_CharacterHeight,4);
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
			if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
			if ((retcode=standard_font_editor_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3557 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto3560 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(80,500,28,34,vfh[2],27,28,"-",strlen("-"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(80,500,28,34,vfh[2],27,28,"-",strlen("-"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3560_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto3561 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(390,500,28,34,vfh[2],27,28,"+",strlen("+"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(390,500,28,34,vfh[2],27,28,"+",strlen("+"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3561_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto3562 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(740,500,16,16,vfh[8],27,28,"+",strlen("+"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(740,500,16,16,vfh[8],27,28,"+",strlen("+"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3562_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto3563 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(740,520,16,16,vfh[8],27,28,"+",strlen("+"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(740,520,16,16,vfh[8],27,28,"+",strlen("+"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3563_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto3564 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(680,520,16,16,vfh[8],27,28,"-",strlen("-"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(680,520,16,16,vfh[8],27,28,"-",strlen("-"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3564_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto3565 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(680,500,16,16,vfh[8],27,28,"-",strlen("-"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(680,500,16,16,vfh[8],27,28,"-",strlen("-"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3565_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto3566 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(240,500,16,16,vfh[8],27,28,"+",strlen("+"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(240,500,16,16,vfh[8],27,28,"+",strlen("+"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3566_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto3567 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(240,520,16,16,vfh[8],27,28,"+",strlen("+"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(240,520,16,16,vfh[8],27,28,"+",strlen("+"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3567_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto3568 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(180,520,16,16,vfh[8],27,28,"-",strlen("-"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(180,520,16,16,vfh[8],27,28,"-",strlen("-"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3568_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Auto3569 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(180,500,16,16,vfh[8],27,28,"-",strlen("-"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(180,500,16,16,vfh[8],27,28,"-",strlen("-"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3569_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* Auto3570 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(550,500,56,34,vfh[2],16,0,"Load",strlen("Load"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(550,500,56,34,vfh[2],16,0,"Load",strlen("Load"),0);
						}
					continue;
				case	0xd :
					/* Auto3571 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(520,500,28,34,vfh[2],16,0,"AB",strlen("AB"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(520,500,28,34,vfh[2],16,0,"AB",strlen("AB"),0);
						}
					continue;
				case	0xe :
					/* Auto3572 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(490,500,28,34,vfh[2],16,0,"AB",strlen("AB"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(490,500,28,34,vfh[2],16,0,"AB",strlen("AB"),0);
						}
					continue;
				case	0xf :
					/* Auto3573 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(430,500,56,34,vfh[2],16,0,"Save",strlen("Save"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(430,500,56,34,vfh[2],16,0,"Save",strlen("Save"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3573_event(_Context)) != -1) break;

						}
					continue;
				case	0x10 :
					/* CharacterDec */
					continue;
				case	0x11 :
					/* CrossControl */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_CrossControl += 1;
						_Context->value_CrossControl &= 1;
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_CrossControl_event(_Context)) != -1) break;

						}
					continue;
				case	0x12 :
					/* FontName */
					continue;
				case	0x13 :
					/* FontTable */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FontTable_event(_Context)) != -1) break;

						}
					continue;
				case	0x14 :
					/* CharacterData */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_CharacterData_event(_Context)) != -1) break;

						}
					continue;
				case	0x15 :
					/* vBar */
					(void) on_vBar_action(_Context);
					continue;
				case	0x16 :
					/* hBar */
					(void) on_hBar_action(_Context);
					continue;
				case	0x17 :
					/* FontFile */
					continue;
				case	0x18 :
					/* FontWidth */
					continue;
				case	0x19 :
					/* FontHeight */
					continue;
				case	0x1a :
					/* CharacterWidth */
					continue;
				case	0x1b :
					/* CharacterHeight */
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

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _fontedit_c */
