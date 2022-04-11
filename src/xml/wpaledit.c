
#ifndef _wpaledit_c
#define _wpaledit_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vpaledit.xml                                             */
/* Target         : wpaledit.c                                               */
/* Identification : 0.0-1177333296-11262.11261                               */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto2611   "Sing : Palette File Editor"
#define en__Auto2611   ""
#define en_PaletteFile   ""
#define en__PaletteFile   ""
#define en_Load   "Load"
#define en__Load   ""
#define en_Save   "Save"
#define en__Save   ""
#define en_Entry   ""
#define en__Entry   ""
#define en_Auto2612   "Palette Item"
#define en_Auto2613   "Palette File"
#define en_Auto2614   "Blue"
#define en_Auto2615   "Green"
#define en_Auto2616   "Red"
#define en_RedValue   ""
#define en__RedValue   ""
#define en_BlueValue   ""
#define en__BlueValue   ""
#define en_RedHex   ""
#define en_BlueHex   ""
#define en_GreenHex   ""
#define en_Auto2617   "-"
#define en__Auto2617   ""
#define en_RedBar   ""
#define en__RedBar   ""
#define en_BlueBar   ""
#define en__BlueBar   ""
#define en_GreenBar   ""
#define en__GreenBar   ""
#define en_Auto2618   "+"
#define en__Auto2618   ""
#define en_Auto2619   "+"
#define en_Auto2620   "+"
#define en__Auto2620   ""
#define en_Auto2621   "-"
#define en__Auto2621   ""
#define en_Auto2622   "-"
#define en__Auto2622   ""
#define en_GreenValue   ""
#define en__GreenValue   ""
#define en_Matrix   ""
#define en__Matrix   ""

private struct use_palette_editor_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2611[8];
	char * hint_Auto2611[8];
	int	x_Auto2611;
	int	y_Auto2611;
	int	w_Auto2611;
	int	h_Auto2611;
	char * hint_PaletteFile[8];
	char	buffer_PaletteFile[53];
	char * msg_Load[8];
	int	trigger_Load;
	char * hint_Load[8];
	char * msg_Save[8];
	int	trigger_Save;
	char * hint_Save[8];
	char * hint_Entry[8];
	char	buffer_Entry[10];
	char * msg_Auto2612[8];
	char * hint_Auto2612[8];
	char * msg_Auto2613[8];
	char * hint_Auto2613[8];
	char * msg_Auto2614[8];
	char * hint_Auto2614[8];
	char * msg_Auto2615[8];
	char * hint_Auto2615[8];
	char * msg_Auto2616[8];
	char * hint_Auto2616[8];
	char * hint_RedValue[8];
	char	buffer_RedValue[5];
	char * hint_BlueValue[8];
	char	buffer_BlueValue[5];
	char * hint_RedHex[8];
	char	buffer_RedHex[3];
	char * hint_BlueHex[8];
	char	buffer_BlueHex[3];
	char * hint_GreenHex[8];
	char	buffer_GreenHex[3];
	char * msg_Auto2617[8];
	int	trigger_Auto2617;
	char * hint_Auto2617[8];
	char * hint_RedBar[8];
	int	value_RedBar;
	int	limit_RedBar;
	char * hint_BlueBar[8];
	int	value_BlueBar;
	int	limit_BlueBar;
	char * hint_GreenBar[8];
	int	value_GreenBar;
	int	limit_GreenBar;
	char * msg_Auto2618[8];
	int	trigger_Auto2618;
	char * hint_Auto2618[8];
	char * msg_Auto2619[8];
	int	trigger_Auto2619;
	char * hint_Auto2619[8];
	char * msg_Auto2620[8];
	int	trigger_Auto2620;
	char * hint_Auto2620[8];
	char * msg_Auto2621[8];
	int	trigger_Auto2621;
	char * hint_Auto2621[8];
	char * msg_Auto2622[8];
	int	trigger_Auto2622;
	char * hint_Auto2622[8];
	char * hint_GreenValue[8];
	char	buffer_GreenValue[5];
	char * hint_Matrix[8];
	char	buffer_Matrix[1145];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[10];
static void	GetColour(struct use_palette_editor_context * _Context);
static void	PutColour(struct use_palette_editor_context * _Context);

/*	--------------------	*/
/*	G e t C o l o u r ()	*/
/*	--------------------	*/
static void	GetColour(struct use_palette_editor_context * _Context){
	int r;
	int g;
	int b;
	get_rgb_values(Conv(_Context->buffer_Entry),&r,&g,&b);
	sprintf(_Context->buffer_RedValue,"%u",(r&0x00FF));
	sprintf(_Context->buffer_GreenValue,"%u",(r&0x00FF));
	sprintf(_Context->buffer_BlueValue,"%u",(r&0x00FF));
	sprintf(_Context->buffer_RedHex,"%02.2X",(r&0x00FF));
	sprintf(_Context->buffer_GreenHex,"%02.2X",(r&0x00FF));
	sprintf(_Context->buffer_BlueHex,"%02.2X",(r&0x00FF));

}

/*	--------------------	*/
/*	P u t C o l o u r ()	*/
/*	--------------------	*/
static void	PutColour(struct use_palette_editor_context * _Context){
	char*pptr;
	if((pptr=get_vga_palette())!=(char*)0){
	*(pptr+(Conv(_Context->buffer_Entry)*4))=(r&0x00FF);
	*(pptr+(Conv(_Context->buffer_Entry)*4)+1)=(g&0x00FF);
	*(pptr+(Conv(_Context->buffer_Entry)*4)+2)=(b&0x00FF);
	put_palette();
	on_Matrix_show(_Context)
	}

}

public	int	use_palette_editor_create(struct use_palette_editor_context **cptr)
{

	int i;
	struct use_palette_editor_context * _Context=(struct use_palette_editor_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct use_palette_editor_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=21;
		for (i=0; i < 52; i++)  *(_Context->buffer_PaletteFile+i)=' ';
		for (i=0; i < 9; i++)  *(_Context->buffer_Entry+i)=' ';
		for (i=0; i < 4; i++)  *(_Context->buffer_RedValue+i)=' ';
		for (i=0; i < 4; i++)  *(_Context->buffer_BlueValue+i)=' ';
		for (i=0; i < 2; i++)  *(_Context->buffer_RedHex+i)=' ';
		for (i=0; i < 2; i++)  *(_Context->buffer_BlueHex+i)=' ';
		for (i=0; i < 2; i++)  *(_Context->buffer_GreenHex+i)=' ';
		_Context->limit_RedBar=0;
		_Context->value_RedBar=0;
		_Context->limit_BlueBar=0;
		_Context->value_BlueBar=0;
		_Context->limit_GreenBar=0;
		_Context->value_GreenBar=0;
		for (i=0; i < 4; i++)  *(_Context->buffer_GreenValue+i)=' ';
		for (i=0; i < 1144; i++)  *(_Context->buffer_Matrix+i)=' ';
	for (i=0; i < 8; i++)_Context->msg_Auto2611[i]=" ";
	_Context->msg_Auto2611[0]=en_Auto2611;
	_Context->hint_Auto2611[0]=en__Auto2611;
	_Context->x_Auto2611=180;
	_Context->y_Auto2611=50;
	_Context->w_Auto2611=440;
	_Context->h_Auto2611=500;
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->hint_PaletteFile[0]=en__PaletteFile;
	_Context->buffer_PaletteFile="/home/abal3/images/standard.rgb"
	for (i=0; i < 8; i++)_Context->msg_Load[i]=" ";
	_Context->msg_Load[0]=en_Load;
	_Context->hint_Load[0]=en__Load;
	for (i=0; i < 8; i++)_Context->msg_Save[i]=" ";
	_Context->msg_Save[0]=en_Save;
	_Context->hint_Save[0]=en__Save;
	_Context->hint_Entry[0]=en__Entry;
	strcpy(_Context->buffer_Entry,"0");
	for (i=0; i < 8; i++)_Context->msg_Auto2612[i]=" ";
	_Context->msg_Auto2612[0]=en_Auto2612;
	for (i=0; i < 8; i++)_Context->msg_Auto2613[i]=" ";
	_Context->msg_Auto2613[0]=en_Auto2613;
	for (i=0; i < 8; i++)_Context->msg_Auto2614[i]=" ";
	_Context->msg_Auto2614[0]=en_Auto2614;
	for (i=0; i < 8; i++)_Context->msg_Auto2615[i]=" ";
	_Context->msg_Auto2615[0]=en_Auto2615;
	for (i=0; i < 8; i++)_Context->msg_Auto2616[i]=" ";
	_Context->msg_Auto2616[0]=en_Auto2616;
	_Context->hint_RedValue[0]=en__RedValue;
	_Context->hint_BlueValue[0]=en__BlueValue;
	for (i=0; i < 8; i++)_Context->msg_Auto2617[i]=" ";
	_Context->msg_Auto2617[0]=en_Auto2617;
	_Context->hint_Auto2617[0]=en__Auto2617;
	_Context->hint_RedBar[0]=en__RedBar;
	_Context->value_RedBar=1;
	_Context->limit_RedBar=1;
	_Context->limit_RedBar=255;
	_Context->hint_BlueBar[0]=en__BlueBar;
	_Context->value_BlueBar=1;
	_Context->limit_BlueBar=1;
	_Context->limit_BlueBar=255;
	_Context->hint_GreenBar[0]=en__GreenBar;
	_Context->value_GreenBar=1;
	_Context->limit_GreenBar=1;
	_Context->limit_GreenBar=255;
	for (i=0; i < 8; i++)_Context->msg_Auto2618[i]=" ";
	_Context->msg_Auto2618[0]=en_Auto2618;
	_Context->hint_Auto2618[0]=en__Auto2618;
	for (i=0; i < 8; i++)_Context->msg_Auto2619[i]=" ";
	_Context->msg_Auto2619[0]=en_Auto2619;
	for (i=0; i < 8; i++)_Context->msg_Auto2620[i]=" ";
	_Context->msg_Auto2620[0]=en_Auto2620;
	_Context->hint_Auto2620[0]=en__Auto2620;
	for (i=0; i < 8; i++)_Context->msg_Auto2621[i]=" ";
	_Context->msg_Auto2621[0]=en_Auto2621;
	_Context->hint_Auto2621[0]=en__Auto2621;
	for (i=0; i < 8; i++)_Context->msg_Auto2622[i]=" ";
	_Context->msg_Auto2622[0]=en_Auto2622;
	_Context->hint_Auto2622[0]=en__Auto2622;
	_Context->hint_GreenValue[0]=en__GreenValue;
	_Context->hint_Matrix[0]=en__Matrix;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2611,_Context->y_Auto2611,440+10,500+10);
	return(0);
}

public 	int	use_palette_editor_hide(struct use_palette_editor_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2611,_Context->y_Auto2611);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	use_palette_editor_remove(struct use_palette_editor_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Entry_show(struct use_palette_editor_context * _Context) {
	GetColour(_Context);
	visual_frame(_Context->x_Auto2611+20,_Context->y_Auto2611+450,72+2,16+2,5);
visual_text(_Context->x_Auto2611+20+1,_Context->y_Auto2611+450+1,72,16,vfh[1],27,28,_Context->buffer_Entry,9,0);
;
	visual_frame(_Context->x_Auto2611+150,_Context->y_Auto2611+430,32+2,16+2,5);
visual_text(_Context->x_Auto2611+150+1,_Context->y_Auto2611+430+1,32,16,vfh[1],27,28,_Context->buffer_RedValue,4,0);
;
	visual_frame(_Context->x_Auto2611+150,_Context->y_Auto2611+450,32+2,16+2,5);
visual_text(_Context->x_Auto2611+150+1,_Context->y_Auto2611+450+1,32,16,vfh[1],27,28,_Context->buffer_GreenValue,4,0);
;
	visual_frame(_Context->x_Auto2611+150,_Context->y_Auto2611+470,32+2,16+2,5);
visual_text(_Context->x_Auto2611+150+1,_Context->y_Auto2611+470+1,32,16,vfh[1],27,28,_Context->buffer_BlueValue,4,0);
;
	visual_frame(_Context->x_Auto2611+190,_Context->y_Auto2611+430,16+2,16+2,5);
visual_text(_Context->x_Auto2611+190+1,_Context->y_Auto2611+430+1,16,16,vfh[1],0,0,_Context->buffer_RedHex,2,0);
;
	visual_frame(_Context->x_Auto2611+190,_Context->y_Auto2611+450,16+2,16+2,5);
visual_text(_Context->x_Auto2611+190+1,_Context->y_Auto2611+450+1,16,16,vfh[1],0,0,_Context->buffer_GreenHex,2,0);
;
	visual_frame(_Context->x_Auto2611+190,_Context->y_Auto2611+470,16+2,16+2,5);
visual_text(_Context->x_Auto2611+190+1,_Context->y_Auto2611+470+1,16,16,vfh[1],0,0,_Context->buffer_BlueHex,2,0);
;
	on_RedBar_show(_Context);
	on_GreenBar_show(_Context);
	on_BlueBar_show(_Context);
	return(-1);
}
private int on_RedBar_show(struct use_palette_editor_context * _Context) {
	_Context->value_RedBar=Conv(_Context->buffer_RedValue);
		visual_progress(_Context->x_Auto2611+240,_Context->y_Auto2611+430,150,20,vfh[1],12,21,_Context->value_RedBar,_Context->limit_RedBar,0);
;
	return(-1);
}
private int on_BlueBar_show(struct use_palette_editor_context * _Context) {
	_Context->value_BlueBar=Conv(_Context->buffer_BlueValue);
		visual_progress(_Context->x_Auto2611+240,_Context->y_Auto2611+470,150,20,vfh[1],9,21,_Context->value_BlueBar,_Context->limit_BlueBar,0);
;
	return(-1);
}
private int on_GreenBar_show(struct use_palette_editor_context * _Context) {
	_Context->value_GreenBar=Conv(_Context->buffer_GreenValue);
		visual_progress(_Context->x_Auto2611+240,_Context->y_Auto2611+450,150,20,vfh[1],10,21,_Context->value_GreenBar,_Context->limit_GreenBar,0);
;
	return(-1);
}
private int on_Matrix_show(struct use_palette_editor_context * _Context) {
	int l,c,w,h;
	w=(416/16)
	h=(352/16)
	visual_freeze()
	for(l=1;l<=16;l++){
	for(c=1;c<=16;c++){
	visual_filzone(
	_Context->x_Auto2611+10+((c-1)*w),
	_Context->y_Auto2611+70+((l-1)*h),w,h,((c-1)+((l-1)*16)),0)
	}
	}
	visual_thaw(_Context->x_Auto2611+10,_Context->y_Auto2611+70,416,352)
		return(-1);
}

public	int	use_palette_editor_show(struct use_palette_editor_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2611,_Context->y_Auto2611);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto2611,_Context->y_Auto2611,440,500,vfh[2],_Context->msg_Auto2611[_Context->language],strlen(_Context->msg_Auto2611[_Context->language]),0x407);
	visual_frame(_Context->x_Auto2611+10,_Context->y_Auto2611+50,416+2,16+2,5);
	visual_text(_Context->x_Auto2611+10+1,_Context->y_Auto2611+50+1,416,16,vfh[1],27,28,_Context->buffer_PaletteFile,52,0);
	_Context->trigger_Load=visual_trigger_code(_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]));
	visual_button(_Context->x_Auto2611+310,_Context->y_Auto2611+30,56,16,vfh[8],27,28,_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]),0);
	_Context->trigger_Save=visual_trigger_code(_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]));
	visual_button(_Context->x_Auto2611+370,_Context->y_Auto2611+30,56,16,vfh[8],27,28,_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]),0);
	(void) on_Entry_show(_Context);
	visual_text(_Context->x_Auto2611+20,_Context->y_Auto2611+430,84,16,vfh[2],16,0,_Context->msg_Auto2612[_Context->language],strlen(_Context->msg_Auto2612[_Context->language]),1282);
	visual_text(_Context->x_Auto2611+10,_Context->y_Auto2611+30,84,16,vfh[2],16,0,_Context->msg_Auto2613[_Context->language],strlen(_Context->msg_Auto2613[_Context->language]),1282);
	visual_text(_Context->x_Auto2611+110,_Context->y_Auto2611+470,42,16,vfh[2],12,0,_Context->msg_Auto2614[_Context->language],strlen(_Context->msg_Auto2614[_Context->language]),1282);
	visual_text(_Context->x_Auto2611+110,_Context->y_Auto2611+450,42,16,vfh[2],10,0,_Context->msg_Auto2615[_Context->language],strlen(_Context->msg_Auto2615[_Context->language]),1282);
	visual_text(_Context->x_Auto2611+110,_Context->y_Auto2611+430,42,16,vfh[2],9,0,_Context->msg_Auto2616[_Context->language],strlen(_Context->msg_Auto2616[_Context->language]),1282);
	visual_frame(_Context->x_Auto2611+150,_Context->y_Auto2611+430,32+2,16+2,5);
	visual_text(_Context->x_Auto2611+150+1,_Context->y_Auto2611+430+1,32,16,vfh[1],27,28,_Context->buffer_RedValue,4,0);
	visual_frame(_Context->x_Auto2611+150,_Context->y_Auto2611+470,32+2,16+2,5);
	visual_text(_Context->x_Auto2611+150+1,_Context->y_Auto2611+470+1,32,16,vfh[1],27,28,_Context->buffer_BlueValue,4,0);
	visual_frame(_Context->x_Auto2611+190,_Context->y_Auto2611+430,16+2,16+2,5);
	visual_text(_Context->x_Auto2611+190+1,_Context->y_Auto2611+430+1,16,16,vfh[1],0,0,_Context->buffer_RedHex,2,0);
	visual_frame(_Context->x_Auto2611+190,_Context->y_Auto2611+470,16+2,16+2,5);
	visual_text(_Context->x_Auto2611+190+1,_Context->y_Auto2611+470+1,16,16,vfh[1],0,0,_Context->buffer_BlueHex,2,0);
	visual_frame(_Context->x_Auto2611+190,_Context->y_Auto2611+450,16+2,16+2,5);
	visual_text(_Context->x_Auto2611+190+1,_Context->y_Auto2611+450+1,16,16,vfh[1],0,0,_Context->buffer_GreenHex,2,0);
	_Context->trigger_Auto2617=visual_trigger_code(_Context->msg_Auto2617[_Context->language],strlen(_Context->msg_Auto2617[_Context->language]));
	visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+430,24,16,vfh[8],27,28,_Context->msg_Auto2617[_Context->language],strlen(_Context->msg_Auto2617[_Context->language]),0);
	(void) on_RedBar_show(_Context);
	(void) on_BlueBar_show(_Context);
	(void) on_GreenBar_show(_Context);
	_Context->trigger_Auto2618=visual_trigger_code(_Context->msg_Auto2618[_Context->language],strlen(_Context->msg_Auto2618[_Context->language]));
	visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+430,24,16,vfh[8],27,28,_Context->msg_Auto2618[_Context->language],strlen(_Context->msg_Auto2618[_Context->language]),0);
	_Context->trigger_Auto2619=visual_trigger_code(_Context->msg_Auto2619[_Context->language],strlen(_Context->msg_Auto2619[_Context->language]));
	visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+470,24,16,vfh[8],27,28,_Context->msg_Auto2619[_Context->language],strlen(_Context->msg_Auto2619[_Context->language]),0);
	_Context->trigger_Auto2620=visual_trigger_code(_Context->msg_Auto2620[_Context->language],strlen(_Context->msg_Auto2620[_Context->language]));
	visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+450,24,16,vfh[8],27,28,_Context->msg_Auto2620[_Context->language],strlen(_Context->msg_Auto2620[_Context->language]),0);
	_Context->trigger_Auto2621=visual_trigger_code(_Context->msg_Auto2621[_Context->language],strlen(_Context->msg_Auto2621[_Context->language]));
	visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+450,24,16,vfh[8],27,28,_Context->msg_Auto2621[_Context->language],strlen(_Context->msg_Auto2621[_Context->language]),0);
	_Context->trigger_Auto2622=visual_trigger_code(_Context->msg_Auto2622[_Context->language],strlen(_Context->msg_Auto2622[_Context->language]));
	visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+470,24,16,vfh[8],27,28,_Context->msg_Auto2622[_Context->language],strlen(_Context->msg_Auto2622[_Context->language]),0);
	visual_frame(_Context->x_Auto2611+150,_Context->y_Auto2611+450,32+2,16+2,5);
	visual_text(_Context->x_Auto2611+150+1,_Context->y_Auto2611+450+1,32,16,vfh[1],27,28,_Context->buffer_GreenValue,4,0);
	(void) on_Matrix_show(_Context);
	visual_thaw(_Context->x_Auto2611,_Context->y_Auto2611,440,500);

	return(0);
}
private int on_Auto2617_event(struct use_palette_editor_context * _Context) {
	if(Conv(_Context->buffer_RedValue)>0){
	sprintf(_Context->buffer_RedValue,"%u",Conv(_Context->buffer_RedValue)-1);
	PutColour(_Context);
	on_Entry_show(_Context);
	}
		return(-1);
}
private int on_Auto2618_event(struct use_palette_editor_context * _Context) {
	if(Conv(_Context->buffer_RedValue)<255){
	sprintf(_Context->buffer_RedValue,"%u",Conv(_Context->buffer_RedValue)+1);
	PutColour(_Context);
	on_Entry_show(_Context);
	}
	return(-1);
}
private int on_Auto2619_event(struct use_palette_editor_context * _Context) {
		if(Conv(_Context->buffer_BlueValue)<255)
	_Context->buffer_BlueValue=Print(($),Conv$(Conv(_Context->buffer_BlueValue)+1))
	PutColour(_Context)
	on_Entry_show(_Context)
	Endif
	return(-1);
}
private int on_Auto2620_event(struct use_palette_editor_context * _Context) {
	if(Conv(_Context->buffer_GreenValue)<255){
	sprintf(_Context->buffer_GreenValue,"%u",Conv(_Context->buffer_GreenValue)+1);
	PutColour(_Context);
	on_Entry_show(_Context);
	}
	return(-1);
}
private int on_Auto2621_event(struct use_palette_editor_context * _Context) {
	if(Conv(_Context->buffer_GreenValue)>0){
	sprintf(_Context->buffer_GreenValue,"%u",Conv(_Context->buffer_GreenValue)-1);
	PutColour(_Context);
	on_Entry_show(_Context);
	}
	return(-1);
}
private int on_Auto2622_event(struct use_palette_editor_context * _Context) {
	if(Conv(_Context->buffer_BlueValue)>0){
	sprintf(_Context->buffer_BlueValue,"%u",Conv(_Context->buffer_BlueValue)-1);
	PutColour(_Context);
	on_Entry_show(_Context);
	}
	return(-1);
}
private int on_Matrix_event(struct use_palette_editor_context * _Context) {
	int l,c,w,h;
	int x=visual_event(7);
	int y=visual_event(6);
	x-=_Context->x_Auto2611+10;
	y-=_Context->y_Auto2611+70;
	w=416/16
	h=352/16;
	x/=w;
	y/=h;
	c=(x+(y*16))
	sprintf(_Context->buffer_Entry,"%u",c);
	on_Entry_show(_Context);
	return(-1);
}


public	int	use_palette_editor_event(
struct use_palette_editor_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Load == mb ) return(3);
		if (_Context->trigger_Save == mb ) return(4);
		if (_Context->trigger_Auto2617 == mb ) return(11);
		if (_Context->trigger_Auto2618 == mb ) return(15);
		if (_Context->trigger_Auto2619 == mb ) return(16);
		if (_Context->trigger_Auto2620 == mb ) return(17);
		if (_Context->trigger_Auto2621 == mb ) return(18);
		if (_Context->trigger_Auto2622 == mb ) return(19);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2611+419) )  
	&&  (my >= (_Context->y_Auto2611+4) )  
	&&  (mx <= (_Context->x_Auto2611+436) )  
	&&  (my <= (_Context->y_Auto2611+20) )) {
		return(1);	/* Auto2611 */

		}
	if ((mx >= (_Context->x_Auto2611+403) )  
	&&  (my >= (_Context->y_Auto2611+4) )  
	&&  (mx <= (_Context->x_Auto2611+420) )  
	&&  (my <= (_Context->y_Auto2611+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("wpaledit.htm");
			};
		return(-1);	/* Auto2611 */

		}
	if ((mx >= (_Context->x_Auto2611+387) )  
	&&  (my >= (_Context->y_Auto2611+4) )  
	&&  (mx <= (_Context->x_Auto2611+404) )  
	&&  (my <= (_Context->y_Auto2611+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		use_palette_editor_show(_Context);
		return(-1);	/* Auto2611 */

		}
		}
	if (( mx >= (_Context->x_Auto2611+10) ) 
	&&  ( my >= (_Context->y_Auto2611+50) ) 
	&&  ( mx <= (_Context->x_Auto2611+10+416) ) 
	&&  ( my <= (_Context->y_Auto2611+50+16))) {
		return(2); /* PaletteFile */
		}
	if (( mx >= (_Context->x_Auto2611+310) ) 
	&&  ( my >= (_Context->y_Auto2611+30) ) 
	&&  ( mx <= (_Context->x_Auto2611+310+56) ) 
	&&  ( my <= (_Context->y_Auto2611+30+16))) {
		return(3); /* Load */
		}
	if (( mx >= (_Context->x_Auto2611+370) ) 
	&&  ( my >= (_Context->y_Auto2611+30) ) 
	&&  ( mx <= (_Context->x_Auto2611+370+56) ) 
	&&  ( my <= (_Context->y_Auto2611+30+16))) {
		return(4); /* Save */
		}
	if (( mx >= (_Context->x_Auto2611+20) ) 
	&&  ( my >= (_Context->y_Auto2611+450) ) 
	&&  ( mx <= (_Context->x_Auto2611+20+72) ) 
	&&  ( my <= (_Context->y_Auto2611+450+16))) {
		return(5); /* Entry */
		}
	if (( mx >= (_Context->x_Auto2611+150) ) 
	&&  ( my >= (_Context->y_Auto2611+430) ) 
	&&  ( mx <= (_Context->x_Auto2611+150+32) ) 
	&&  ( my <= (_Context->y_Auto2611+430+16))) {
		return(6); /* RedValue */
		}
	if (( mx >= (_Context->x_Auto2611+150) ) 
	&&  ( my >= (_Context->y_Auto2611+470) ) 
	&&  ( mx <= (_Context->x_Auto2611+150+32) ) 
	&&  ( my <= (_Context->y_Auto2611+470+16))) {
		return(7); /* BlueValue */
		}
	if (( mx >= (_Context->x_Auto2611+190) ) 
	&&  ( my >= (_Context->y_Auto2611+430) ) 
	&&  ( mx <= (_Context->x_Auto2611+190+16) ) 
	&&  ( my <= (_Context->y_Auto2611+430+16))) {
		return(8); /* RedHex */
		}
	if (( mx >= (_Context->x_Auto2611+190) ) 
	&&  ( my >= (_Context->y_Auto2611+470) ) 
	&&  ( mx <= (_Context->x_Auto2611+190+16) ) 
	&&  ( my <= (_Context->y_Auto2611+470+16))) {
		return(9); /* BlueHex */
		}
	if (( mx >= (_Context->x_Auto2611+190) ) 
	&&  ( my >= (_Context->y_Auto2611+450) ) 
	&&  ( mx <= (_Context->x_Auto2611+190+16) ) 
	&&  ( my <= (_Context->y_Auto2611+450+16))) {
		return(10); /* GreenHex */
		}
	if (( mx >= (_Context->x_Auto2611+210) ) 
	&&  ( my >= (_Context->y_Auto2611+430) ) 
	&&  ( mx <= (_Context->x_Auto2611+210+24) ) 
	&&  ( my <= (_Context->y_Auto2611+430+16))) {
		return(11); /* Auto2617 */
		}
	if (( mx >= (_Context->x_Auto2611+240) ) 
	&&  ( my >= (_Context->y_Auto2611+430) ) 
	&&  ( mx <= (_Context->x_Auto2611+240+150) ) 
	&&  ( my <= (_Context->y_Auto2611+430+20))) {
		return(12); /* RedBar */
		}
	if (( mx >= (_Context->x_Auto2611+240) ) 
	&&  ( my >= (_Context->y_Auto2611+470) ) 
	&&  ( mx <= (_Context->x_Auto2611+240+150) ) 
	&&  ( my <= (_Context->y_Auto2611+470+20))) {
		return(13); /* BlueBar */
		}
	if (( mx >= (_Context->x_Auto2611+240) ) 
	&&  ( my >= (_Context->y_Auto2611+450) ) 
	&&  ( mx <= (_Context->x_Auto2611+240+150) ) 
	&&  ( my <= (_Context->y_Auto2611+450+20))) {
		return(14); /* GreenBar */
		}
	if (( mx >= (_Context->x_Auto2611+400) ) 
	&&  ( my >= (_Context->y_Auto2611+430) ) 
	&&  ( mx <= (_Context->x_Auto2611+400+24) ) 
	&&  ( my <= (_Context->y_Auto2611+430+16))) {
		return(15); /* Auto2618 */
		}
	if (( mx >= (_Context->x_Auto2611+400) ) 
	&&  ( my >= (_Context->y_Auto2611+470) ) 
	&&  ( mx <= (_Context->x_Auto2611+400+24) ) 
	&&  ( my <= (_Context->y_Auto2611+470+16))) {
		return(16); /* Auto2619 */
		}
	if (( mx >= (_Context->x_Auto2611+400) ) 
	&&  ( my >= (_Context->y_Auto2611+450) ) 
	&&  ( mx <= (_Context->x_Auto2611+400+24) ) 
	&&  ( my <= (_Context->y_Auto2611+450+16))) {
		return(17); /* Auto2620 */
		}
	if (( mx >= (_Context->x_Auto2611+210) ) 
	&&  ( my >= (_Context->y_Auto2611+450) ) 
	&&  ( mx <= (_Context->x_Auto2611+210+24) ) 
	&&  ( my <= (_Context->y_Auto2611+450+16))) {
		return(18); /* Auto2621 */
		}
	if (( mx >= (_Context->x_Auto2611+210) ) 
	&&  ( my >= (_Context->y_Auto2611+470) ) 
	&&  ( mx <= (_Context->x_Auto2611+210+24) ) 
	&&  ( my <= (_Context->y_Auto2611+470+16))) {
		return(19); /* Auto2622 */
		}
	if (( mx >= (_Context->x_Auto2611+150) ) 
	&&  ( my >= (_Context->y_Auto2611+450) ) 
	&&  ( mx <= (_Context->x_Auto2611+150+32) ) 
	&&  ( my <= (_Context->y_Auto2611+450+16))) {
		return(20); /* GreenValue */
		}
	if (( mx >= (_Context->x_Auto2611+10) ) 
	&&  ( my >= (_Context->y_Auto2611+70) ) 
	&&  ( mx <= (_Context->x_Auto2611+10+416) ) 
	&&  ( my <= (_Context->y_Auto2611+70+352))) {
		return(21); /* Matrix */
		}

	return(-1);
}
private int on_PaletteFile_losefocus(struct use_palette_editor_context * _Context) {
	on_Load_event(_Context)
	return(-1);
}
private int on_Matrix_getfocus(struct use_palette_editor_context * _Context) {
	return(visual_getch())
	return(-1);
}


public	int	use_palette_editor_focus(struct use_palette_editor_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* PaletteFile */
				_Context->keycode = visual_edit(_Context->x_Auto2611+10+1,_Context->y_Auto2611+50+1,416,16,vfh[1],_Context->buffer_PaletteFile,52);
				(void) on_PaletteFile_losefocus(_Context);
			break;
			case	0x3 :
				/* Load */
				_Context->trigger_Load=visual_trigger_code(_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]));
				visual_button(_Context->x_Auto2611+310,_Context->y_Auto2611+30,56,16,vfh[8],27,28,_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Load=visual_trigger_code(_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]));
	visual_button(_Context->x_Auto2611+310,_Context->y_Auto2611+30,56,16,vfh[8],27,28,_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]),0);
				break;
			case	0x4 :
				/* Save */
				_Context->trigger_Save=visual_trigger_code(_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]));
				visual_button(_Context->x_Auto2611+370,_Context->y_Auto2611+30,56,16,vfh[8],27,28,_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Save=visual_trigger_code(_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]));
	visual_button(_Context->x_Auto2611+370,_Context->y_Auto2611+30,56,16,vfh[8],27,28,_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]),0);
				break;
			case	0x5 :
				/* Entry */
				_Context->keycode = visual_edit(_Context->x_Auto2611+20+1,_Context->y_Auto2611+450+1,72,16,vfh[1],_Context->buffer_Entry,9);
				on_Entry_show(_Context);
			break;
			case	0x6 :
				/* RedValue */
				_Context->keycode = visual_edit(_Context->x_Auto2611+150+1,_Context->y_Auto2611+430+1,32,16,vfh[1],_Context->buffer_RedValue,4);
				PutColour(_Context);
					use_palette_editor_show(_Context);

				;
			break;
			case	0x7 :
				/* BlueValue */
				_Context->keycode = visual_edit(_Context->x_Auto2611+150+1,_Context->y_Auto2611+470+1,32,16,vfh[1],_Context->buffer_BlueValue,4);
				PutColour(_Context);
					use_palette_editor_show(_Context);
;
			break;
			case	0xb :
				/* Auto2617 */
				_Context->trigger_Auto2617=visual_trigger_code(_Context->msg_Auto2617[_Context->language],strlen(_Context->msg_Auto2617[_Context->language]));
				visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+430,24,16,vfh[8],27,28,_Context->msg_Auto2617[_Context->language],strlen(_Context->msg_Auto2617[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2617=visual_trigger_code(_Context->msg_Auto2617[_Context->language],strlen(_Context->msg_Auto2617[_Context->language]));
	visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+430,24,16,vfh[8],27,28,_Context->msg_Auto2617[_Context->language],strlen(_Context->msg_Auto2617[_Context->language]),0);
				break;
			case	0xf :
				/* Auto2618 */
				_Context->trigger_Auto2618=visual_trigger_code(_Context->msg_Auto2618[_Context->language],strlen(_Context->msg_Auto2618[_Context->language]));
				visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+430,24,16,vfh[8],27,28,_Context->msg_Auto2618[_Context->language],strlen(_Context->msg_Auto2618[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2618=visual_trigger_code(_Context->msg_Auto2618[_Context->language],strlen(_Context->msg_Auto2618[_Context->language]));
	visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+430,24,16,vfh[8],27,28,_Context->msg_Auto2618[_Context->language],strlen(_Context->msg_Auto2618[_Context->language]),0);
				break;
			case	0x10 :
				/* Auto2619 */
				_Context->trigger_Auto2619=visual_trigger_code(_Context->msg_Auto2619[_Context->language],strlen(_Context->msg_Auto2619[_Context->language]));
				visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+470,24,16,vfh[8],27,28,_Context->msg_Auto2619[_Context->language],strlen(_Context->msg_Auto2619[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2619=visual_trigger_code(_Context->msg_Auto2619[_Context->language],strlen(_Context->msg_Auto2619[_Context->language]));
	visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+470,24,16,vfh[8],27,28,_Context->msg_Auto2619[_Context->language],strlen(_Context->msg_Auto2619[_Context->language]),0);
				break;
			case	0x11 :
				/* Auto2620 */
				_Context->trigger_Auto2620=visual_trigger_code(_Context->msg_Auto2620[_Context->language],strlen(_Context->msg_Auto2620[_Context->language]));
				visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+450,24,16,vfh[8],27,28,_Context->msg_Auto2620[_Context->language],strlen(_Context->msg_Auto2620[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2620=visual_trigger_code(_Context->msg_Auto2620[_Context->language],strlen(_Context->msg_Auto2620[_Context->language]));
	visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+450,24,16,vfh[8],27,28,_Context->msg_Auto2620[_Context->language],strlen(_Context->msg_Auto2620[_Context->language]),0);
				break;
			case	0x12 :
				/* Auto2621 */
				_Context->trigger_Auto2621=visual_trigger_code(_Context->msg_Auto2621[_Context->language],strlen(_Context->msg_Auto2621[_Context->language]));
				visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+450,24,16,vfh[8],27,28,_Context->msg_Auto2621[_Context->language],strlen(_Context->msg_Auto2621[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2621=visual_trigger_code(_Context->msg_Auto2621[_Context->language],strlen(_Context->msg_Auto2621[_Context->language]));
	visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+450,24,16,vfh[8],27,28,_Context->msg_Auto2621[_Context->language],strlen(_Context->msg_Auto2621[_Context->language]),0);
				break;
			case	0x13 :
				/* Auto2622 */
				_Context->trigger_Auto2622=visual_trigger_code(_Context->msg_Auto2622[_Context->language],strlen(_Context->msg_Auto2622[_Context->language]));
				visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+470,24,16,vfh[8],27,28,_Context->msg_Auto2622[_Context->language],strlen(_Context->msg_Auto2622[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2622=visual_trigger_code(_Context->msg_Auto2622[_Context->language],strlen(_Context->msg_Auto2622[_Context->language]));
	visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+470,24,16,vfh[8],27,28,_Context->msg_Auto2622[_Context->language],strlen(_Context->msg_Auto2622[_Context->language]),0);
				break;
			case	0x14 :
				/* GreenValue */
				_Context->keycode = visual_edit(_Context->x_Auto2611+150+1,_Context->y_Auto2611+450+1,32,16,vfh[1],_Context->buffer_GreenValue,4);
				PutColour(_Context);
					use_palette_editor_show(_Context);
;
			break;
			case	0x15 :
				/* Matrix */
				if ((_Context->keycode = on_Matrix_getfocus(_Context)) != -1) break;
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			use_palette_editor_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=21;
			use_palette_editor_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=use_palette_editor_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2611 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* PaletteFile */
					continue;
				case	0x3 :
					/* Load */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Load=visual_trigger_code(_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]));
						visual_button(_Context->x_Auto2611+310,_Context->y_Auto2611+30,56,16,vfh[8],27,28,_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Load=visual_trigger_code(_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]));
	visual_button(_Context->x_Auto2611+310,_Context->y_Auto2611+30,56,16,vfh[8],27,28,_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]),0);
						}
					continue;
				case	0x4 :
					/* Save */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Save=visual_trigger_code(_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]));
						visual_button(_Context->x_Auto2611+370,_Context->y_Auto2611+30,56,16,vfh[8],27,28,_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Save=visual_trigger_code(_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]));
	visual_button(_Context->x_Auto2611+370,_Context->y_Auto2611+30,56,16,vfh[8],27,28,_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]),0);
						}
					continue;
				case	0x5 :
					/* Entry */
					continue;
				case	0x6 :
					/* RedValue */
					continue;
				case	0x7 :
					/* BlueValue */
					continue;
				case	0x8 :
					/* RedHex */
					continue;
				case	0x9 :
					/* BlueHex */
					continue;
				case	0xa :
					/* GreenHex */
					continue;
				case	0xb :
					/* Auto2617 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2617=visual_trigger_code(_Context->msg_Auto2617[_Context->language],strlen(_Context->msg_Auto2617[_Context->language]));
						visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+430,24,16,vfh[8],27,28,_Context->msg_Auto2617[_Context->language],strlen(_Context->msg_Auto2617[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2617=visual_trigger_code(_Context->msg_Auto2617[_Context->language],strlen(_Context->msg_Auto2617[_Context->language]));
	visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+430,24,16,vfh[8],27,28,_Context->msg_Auto2617[_Context->language],strlen(_Context->msg_Auto2617[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2617_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* RedBar */
					continue;
				case	0xd :
					/* BlueBar */
					continue;
				case	0xe :
					/* GreenBar */
					continue;
				case	0xf :
					/* Auto2618 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2618=visual_trigger_code(_Context->msg_Auto2618[_Context->language],strlen(_Context->msg_Auto2618[_Context->language]));
						visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+430,24,16,vfh[8],27,28,_Context->msg_Auto2618[_Context->language],strlen(_Context->msg_Auto2618[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2618=visual_trigger_code(_Context->msg_Auto2618[_Context->language],strlen(_Context->msg_Auto2618[_Context->language]));
	visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+430,24,16,vfh[8],27,28,_Context->msg_Auto2618[_Context->language],strlen(_Context->msg_Auto2618[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2618_event(_Context)) != -1) break;

						}
					continue;
				case	0x10 :
					/* Auto2619 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2619=visual_trigger_code(_Context->msg_Auto2619[_Context->language],strlen(_Context->msg_Auto2619[_Context->language]));
						visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+470,24,16,vfh[8],27,28,_Context->msg_Auto2619[_Context->language],strlen(_Context->msg_Auto2619[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2619=visual_trigger_code(_Context->msg_Auto2619[_Context->language],strlen(_Context->msg_Auto2619[_Context->language]));
	visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+470,24,16,vfh[8],27,28,_Context->msg_Auto2619[_Context->language],strlen(_Context->msg_Auto2619[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2619_event(_Context)) != -1) break;

						}
					continue;
				case	0x11 :
					/* Auto2620 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2620=visual_trigger_code(_Context->msg_Auto2620[_Context->language],strlen(_Context->msg_Auto2620[_Context->language]));
						visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+450,24,16,vfh[8],27,28,_Context->msg_Auto2620[_Context->language],strlen(_Context->msg_Auto2620[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2620=visual_trigger_code(_Context->msg_Auto2620[_Context->language],strlen(_Context->msg_Auto2620[_Context->language]));
	visual_button(_Context->x_Auto2611+400,_Context->y_Auto2611+450,24,16,vfh[8],27,28,_Context->msg_Auto2620[_Context->language],strlen(_Context->msg_Auto2620[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2620_event(_Context)) != -1) break;

						}
					continue;
				case	0x12 :
					/* Auto2621 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2621=visual_trigger_code(_Context->msg_Auto2621[_Context->language],strlen(_Context->msg_Auto2621[_Context->language]));
						visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+450,24,16,vfh[8],27,28,_Context->msg_Auto2621[_Context->language],strlen(_Context->msg_Auto2621[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2621=visual_trigger_code(_Context->msg_Auto2621[_Context->language],strlen(_Context->msg_Auto2621[_Context->language]));
	visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+450,24,16,vfh[8],27,28,_Context->msg_Auto2621[_Context->language],strlen(_Context->msg_Auto2621[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2621_event(_Context)) != -1) break;

						}
					continue;
				case	0x13 :
					/* Auto2622 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2622=visual_trigger_code(_Context->msg_Auto2622[_Context->language],strlen(_Context->msg_Auto2622[_Context->language]));
						visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+470,24,16,vfh[8],27,28,_Context->msg_Auto2622[_Context->language],strlen(_Context->msg_Auto2622[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2622=visual_trigger_code(_Context->msg_Auto2622[_Context->language],strlen(_Context->msg_Auto2622[_Context->language]));
	visual_button(_Context->x_Auto2611+210,_Context->y_Auto2611+470,24,16,vfh[8],27,28,_Context->msg_Auto2622[_Context->language],strlen(_Context->msg_Auto2622[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2622_event(_Context)) != -1) break;

						}
					continue;
				case	0x14 :
					/* GreenValue */
					continue;
				case	0x15 :
					/* Matrix */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Matrix_event(_Context)) != -1) break;

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
				_Context->focus_item=21;
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

public	int	use_palette_editor()
{
	int	status=0;
	struct use_palette_editor_context * _Context=(struct use_palette_editor_context*) 0;
	status = use_palette_editor_create(&_Context);
	if ( status != 0) return(status);
	status = use_palette_editor_show(_Context);
		enter_modal();
	status = use_palette_editor_focus(_Context);
		leave_modal();
	status = use_palette_editor_hide(_Context);
	status = use_palette_editor_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _wpaledit_c */
