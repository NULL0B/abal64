
#ifndef _vpaledit_c
#define _vpaledit_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : vpaledit.xml                                             */
/* Target         : vpaledit.c                                               */
/* Identification : 0.0-1193815486-12785.12784                               */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto2985   "Sing : Palette File Editor"
#define fr_Auto2985   "Sing : Editeur de fichiers palettes"
#define it_Auto2985   "Sing : Palette File Editor"
#define es_Auto2985   "Sing : Palette File Editor"
#define de_Auto2985   "Sing : Palette File Editor"
#define nl_Auto2985   "Sing : Palette File Editor"
#define pt_Auto2985   "Sing : Palette File Editor"
#define xx_Auto2985   "Sing : Palette File Editor"
#define en__Auto2985   ""
#define fr__Auto2985   ""
#define it__Auto2985   ""
#define es__Auto2985   ""
#define de__Auto2985   ""
#define nl__Auto2985   ""
#define pt__Auto2985   ""
#define xx__Auto2985   ""
#define en_Auto2986   ""
#define en__Auto2986   ""
#define en_Auto2987   ""
#define en__Auto2987   ""
#define en_Auto2988   ""
#define en__Auto2988   ""
#define en_Auto2989   ""
#define en__Auto2989   ""
#define en_Auto2990   ""
#define en__Auto2990   ""
#define en_Auto2991   ""
#define en__Auto2991   ""
#define en_PaletteName   ""
#define en__PaletteName   ""
#define en_Auto2992   "..."
#define fr_Auto2992   "..."
#define it_Auto2992   "..."
#define es_Auto2992   "..."
#define de_Auto2992   "..."
#define nl_Auto2992   "..."
#define pt_Auto2992   "..."
#define xx_Auto2992   "..."
#define en__Auto2992   ""
#define fr__Auto2992   ""
#define it__Auto2992   ""
#define es__Auto2992   ""
#define de__Auto2992   ""
#define nl__Auto2992   ""
#define pt__Auto2992   ""
#define xx__Auto2992   ""
#define en_Load   "load.png"
#define fr_Load   "load.png"
#define it_Load   "load.png"
#define es_Load   "load.png"
#define de_Load   "load.png"
#define nl_Load   "load.png"
#define pt_Load   "load.png"
#define xx_Load   "load.png"
#define en__Load   ""
#define fr__Load   ""
#define it__Load   ""
#define es__Load   ""
#define de__Load   ""
#define nl__Load   ""
#define pt__Load   ""
#define xx__Load   ""
#define en_Save   "floppy.png"
#define fr_Save   "floppy.png"
#define it_Save   "floppy.png"
#define es_Save   "floppy.png"
#define de_Save   "floppy.png"
#define nl_Save   "floppy.png"
#define pt_Save   "floppy.png"
#define xx_Save   "floppy.png"
#define en__Save   ""
#define fr__Save   ""
#define it__Save   ""
#define es__Save   ""
#define de__Save   ""
#define nl__Save   ""
#define pt__Save   ""
#define xx__Save   ""
#define en_Entry   ""
#define en__Entry   ""
#define en_Matrix   ""
#define en__Matrix   ""
#define en_Cursor   "sphere.gif"
#define fr_Cursor   "pen.png"
#define it_Cursor   "pen.png"
#define es_Cursor   "pen.png"
#define de_Cursor   "pen.png"
#define nl_Cursor   "pen.png"
#define pt_Cursor   "pen.png"
#define xx_Cursor   "pen.png"
#define en__Cursor   ""
#define fr__Cursor   ""
#define it__Cursor   ""
#define es__Cursor   ""
#define de__Cursor   ""
#define nl__Cursor   ""
#define pt__Cursor   ""
#define xx__Cursor   ""
#define en_Drag   "sphere.gif"
#define fr_Drag   "pourtool.png"
#define it_Drag   "pourtool.png"
#define es_Drag   "pourtool.png"
#define de_Drag   "pourtool.png"
#define nl_Drag   "pourtool.png"
#define pt_Drag   "pourtool.png"
#define xx_Drag   "pourtool.png"
#define en__Drag   ""
#define fr__Drag   ""
#define it__Drag   ""
#define es__Drag   ""
#define de__Drag   ""
#define nl__Drag   ""
#define pt__Drag   ""
#define xx__Drag   ""
#define en_Auto2993   "Palette File"
#define fr_Auto2993   "Fichier Palette"
#define it_Auto2993   "Palette File"
#define es_Auto2993   "Palette File"
#define de_Auto2993   "Datei"
#define nl_Auto2993   "Palette File"
#define pt_Auto2993   "Palette File"
#define xx_Auto2993   "Palette File"
#define en__Auto2993   ""
#define fr__Auto2993   ""
#define it__Auto2993   ""
#define es__Auto2993   ""
#define de__Auto2993   ""
#define nl__Auto2993   ""
#define pt__Auto2993   ""
#define xx__Auto2993   ""
#define en_Auto2994   "Blue"
#define fr_Auto2994   "Bleu"
#define it_Auto2994   "Blue"
#define es_Auto2994   "Blue"
#define de_Auto2994   "Blau"
#define nl_Auto2994   "Blue"
#define pt_Auto2994   "Blue"
#define xx_Auto2994   "Gorm"
#define en__Auto2994   ""
#define fr__Auto2994   ""
#define it__Auto2994   ""
#define es__Auto2994   ""
#define de__Auto2994   ""
#define nl__Auto2994   ""
#define pt__Auto2994   ""
#define xx__Auto2994   ""
#define en_Auto2995   "Green"
#define fr_Auto2995   "Vert"
#define it_Auto2995   "Green"
#define es_Auto2995   "Green"
#define de_Auto2995   "Grn"
#define nl_Auto2995   "Green"
#define pt_Auto2995   "Green"
#define xx_Auto2995   "Uanne"
#define en__Auto2995   ""
#define fr__Auto2995   ""
#define it__Auto2995   ""
#define es__Auto2995   ""
#define de__Auto2995   ""
#define nl__Auto2995   ""
#define pt__Auto2995   ""
#define xx__Auto2995   ""
#define en_Auto2996   "Red"
#define fr_Auto2996   "Rouge"
#define it_Auto2996   "Red"
#define es_Auto2996   "Red"
#define de_Auto2996   "Rot"
#define nl_Auto2996   "Red"
#define pt_Auto2996   "Red"
#define xx_Auto2996   "Dearg"
#define en__Auto2996   ""
#define fr__Auto2996   ""
#define it__Auto2996   ""
#define es__Auto2996   ""
#define de__Auto2996   ""
#define nl__Auto2996   ""
#define pt__Auto2996   ""
#define xx__Auto2996   ""
#define en_Auto2997   "Brightness"
#define fr_Auto2997   "Luminosit‚"
#define it_Auto2997   "Brightness"
#define es_Auto2997   "Brightness"
#define de_Auto2997   "Brightness"
#define nl_Auto2997   "Brightness"
#define pt_Auto2997   "Brightness"
#define xx_Auto2997   "Brightness"
#define en__Auto2997   ""
#define fr__Auto2997   ""
#define it__Auto2997   ""
#define es__Auto2997   ""
#define de__Auto2997   ""
#define nl__Auto2997   ""
#define pt__Auto2997   ""
#define xx__Auto2997   ""
#define en_Brightness   ""
#define en__Brightness   ""
#define en_RedValue   ""
#define en__RedValue   ""
#define en_BlueValue   ""
#define en__BlueValue   ""
#define en_GreenValue   ""
#define en__GreenValue   ""
#define en_RedHex   ""
#define en__RedHex   ""
#define en_BlueHex   ""
#define en__BlueHex   ""
#define en_GreenHex   ""
#define en__GreenHex   ""
#define en_BrightBar   ""
#define en__BrightBar   ""
#define en_RedBar   ""
#define en__RedBar   ""
#define en_BlueBar   ""
#define en__BlueBar   ""
#define en_GreenBar   ""
#define en__GreenBar   ""
#define en_Auto2998   "screen.gif"
#define fr_Auto2998   "screen.gif"
#define it_Auto2998   "screen.gif"
#define es_Auto2998   "screen.gif"
#define de_Auto2998   "screen.gif"
#define nl_Auto2998   "screen.gif"
#define pt_Auto2998   "screen.gif"
#define xx_Auto2998   "screen.gif"
#define en__Auto2998   ""
#define fr__Auto2998   ""
#define it__Auto2998   ""
#define es__Auto2998   ""
#define de__Auto2998   ""
#define nl__Auto2998   ""
#define pt__Auto2998   ""
#define xx__Auto2998   ""

private struct use_palette_editor_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2985[8];
	char * hint_Auto2985[8];
	int	x_Auto2985;
	int	y_Auto2985;
	int	w_Auto2985;
	int	h_Auto2985;
	char * hint_Auto2986[8];
	char * hint_Auto2987[8];
	char * hint_Auto2988[8];
	char * hint_Auto2989[8];
	char * hint_Auto2990[8];
	char * hint_Auto2991[8];
	char * hint_PaletteName[8];
	char	buffer_PaletteName[256];
	char * msg_Auto2992[8];
	int	trigger_Auto2992;
	char * hint_Auto2992[8];
	char * msg_Load[8];
	int	trigger_Load;
	char * hint_Load[8];
	char * msg_Save[8];
	int	trigger_Save;
	char * hint_Save[8];
	char * hint_Entry[8];
	char	buffer_Entry[4];
	char * hint_Matrix[8];
	char	buffer_Matrix[1145];
	char * msg_Cursor[8];
	char * hint_Cursor[8];
	int	x_Cursor;
	int	y_Cursor;
	int	w_Cursor;
	int	h_Cursor;
	int	fg_Cursor;
	int	bg_Cursor;
	int	fid_Cursor;
	char * msg_Drag[8];
	char * hint_Drag[8];
	int	x_Drag;
	int	y_Drag;
	int	w_Drag;
	int	h_Drag;
	int	fg_Drag;
	int	bg_Drag;
	int	fid_Drag;
	int	s_Drag;
	void *	p_Drag;
	char * msg_Auto2993[8];
	char * hint_Auto2993[8];
	char * msg_Auto2994[8];
	char * hint_Auto2994[8];
	char * msg_Auto2995[8];
	char * hint_Auto2995[8];
	char * msg_Auto2996[8];
	char * hint_Auto2996[8];
	char * msg_Auto2997[8];
	char * hint_Auto2997[8];
	char * hint_Brightness[8];
	char	buffer_Brightness[4];
	char * hint_RedValue[8];
	char	buffer_RedValue[4];
	char * hint_BlueValue[8];
	char	buffer_BlueValue[4];
	char * hint_GreenValue[8];
	char	buffer_GreenValue[4];
	char * hint_RedHex[8];
	char	buffer_RedHex[3];
	char * hint_BlueHex[8];
	char	buffer_BlueHex[3];
	char * hint_GreenHex[8];
	char	buffer_GreenHex[3];
	char * hint_BrightBar[8];
	int	value_BrightBar;
	int	limit_BrightBar;
	int	max_BrightBar;
	char * hint_RedBar[8];
	int	value_RedBar;
	int	limit_RedBar;
	int	max_RedBar;
	char * hint_BlueBar[8];
	int	value_BlueBar;
	int	limit_BlueBar;
	int	max_BlueBar;
	char * hint_GreenBar[8];
	int	value_GreenBar;
	int	limit_GreenBar;
	int	max_GreenBar;
	char * msg_Auto2998[8];
	int	trigger_Auto2998;
	char * hint_Auto2998[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];
static void	GetColour(struct use_palette_editor_context * _Context);
static void	PutColour(struct use_palette_editor_context * _Context);
static short	convert_integer(struct use_palette_editor_context * _Context,char * sptr, int slen);
static void	ReplaceColour(struct use_palette_editor_context * _Context,int i);

/*	--------------------	*/
/*	G e t C o l o u r ()	*/
/*	--------------------	*/
static void	GetColour(struct use_palette_editor_context * _Context){
	int r;
	int g;
	int b;
	int i;
	i=convert_integer(_Context, _Context->buffer_Entry,3);
	get_rgb_values(i,&_Context->value_RedBar,&_Context->value_GreenBar,&_Context->value_BlueBar);
	_Context->value_RedBar&=0x00FF;
	_Context->value_GreenBar&=0x00FF;
	_Context->value_BlueBar&=0x00FF;
	sprintf(_Context->buffer_RedValue,"%u",_Context->value_RedBar);
	sprintf(_Context->buffer_GreenValue,"%u",_Context->value_GreenBar);
	sprintf(_Context->buffer_BlueValue,"%u",_Context->value_BlueBar);
	sprintf(_Context->buffer_RedHex,"%02.2X",_Context->value_RedBar);
	sprintf(_Context->buffer_GreenHex,"%02.2X",_Context->value_GreenBar);
	sprintf(_Context->buffer_BlueHex,"%02.2X",_Context->value_BlueBar);

}

/*	--------------------	*/
/*	P u t C o l o u r ()	*/
/*	--------------------	*/
static void	PutColour(struct use_palette_editor_context * _Context){
	char*pptr;
	int v;
	int i;
	if((pptr=get_vga_palette())!=(char*)0){
	i=convert_integer(_Context, _Context->buffer_Entry,3);
	v=convert_integer(_Context, _Context->buffer_RedValue,3);
	*(pptr+(i*4))=(v&0x00FF);
	v=convert_integer(_Context, _Context->buffer_GreenValue,3);
	*(pptr+(i*4)+1)=(v&0x00FF);
	v=convert_integer(_Context, _Context->buffer_BlueValue,3);
	*(pptr+(i*4)+2)=(v&0x00FF);
	put_palette();
	on_Matrix_show(_Context);
	}

}

/*	--------------------------------	*/
/*	c o n v e r t _ i n t e g e r ()	*/
/*	--------------------------------	*/
static short	convert_integer(struct use_palette_editor_context * _Context,char * sptr, int slen){
	int i,l;
	int c;
	for(l=0,i=0;i<slen;i++){
	if((c=*(sptr+i))==' '){
	if(!(l))
	continue;
	else break;
	}
	else if((c>='0')&&(c<='9'))
	l=((l*10)+(c-'0'));
	}
	return(l);

}

/*	----------------------------	*/
/*	R e p l a c e C o l o u r ()	*/
/*	----------------------------	*/
static void	ReplaceColour(struct use_palette_editor_context * _Context,int i){
	char*pptr;
	int v;
	if((pptr=get_vga_palette())!=(char*)0){
	v=convert_integer(_Context, _Context->buffer_RedValue,3);
	*(pptr+(i*4))=(v&0x00FF);
	v=convert_integer(_Context, _Context->buffer_GreenValue,3);
	*(pptr+(i*4)+1)=(v&0x00FF);
	v=convert_integer(_Context, _Context->buffer_BlueValue,3);
	*(pptr+(i*4)+2)=(v&0x00FF);
	put_palette();
	on_Matrix_show(_Context);
	}

}
private int on_PaletteName_create(struct use_palette_editor_context * _Context) {
	char*get_system_palette();
	char*pptr;
	if((pptr=get_system_palette())!=(char*)0)
	strcpy(_Context->buffer_PaletteName,pptr);
	else strcpy(_Context->buffer_PaletteName,"standard.rgb");
	return(-1);
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
	_Context->focus_items=19;
		for (i=0; i < 255; i++)  *(_Context->buffer_PaletteName+i)=' ';
		for (i=0; i < 3; i++)  *(_Context->buffer_Entry+i)=' ';
		for (i=0; i < 1144; i++)  *(_Context->buffer_Matrix+i)=' ';
		for (i=0; i < 3; i++)  *(_Context->buffer_Brightness+i)=' ';
		for (i=0; i < 3; i++)  *(_Context->buffer_RedValue+i)=' ';
		for (i=0; i < 3; i++)  *(_Context->buffer_BlueValue+i)=' ';
		for (i=0; i < 3; i++)  *(_Context->buffer_GreenValue+i)=' ';
		for (i=0; i < 2; i++)  *(_Context->buffer_RedHex+i)=' ';
		for (i=0; i < 2; i++)  *(_Context->buffer_BlueHex+i)=' ';
		for (i=0; i < 2; i++)  *(_Context->buffer_GreenHex+i)=' ';
		_Context->max_BrightBar=0;
		_Context->limit_BrightBar=0;
		_Context->value_BrightBar=0;
		_Context->max_RedBar=0;
		_Context->limit_RedBar=0;
		_Context->value_RedBar=0;
		_Context->max_BlueBar=0;
		_Context->limit_BlueBar=0;
		_Context->value_BlueBar=0;
		_Context->max_GreenBar=0;
		_Context->limit_GreenBar=0;
		_Context->value_GreenBar=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2985[i]=" ";
	_Context->msg_Auto2985[0]=en_Auto2985;
	_Context->msg_Auto2985[1]=fr_Auto2985;
	_Context->msg_Auto2985[2]=it_Auto2985;
	_Context->msg_Auto2985[3]=es_Auto2985;
	_Context->msg_Auto2985[4]=de_Auto2985;
	_Context->msg_Auto2985[5]=nl_Auto2985;
	_Context->msg_Auto2985[6]=pt_Auto2985;
	_Context->msg_Auto2985[7]=xx_Auto2985;
	_Context->hint_Auto2985[0]=en__Auto2985;
	_Context->hint_Auto2985[1]=fr__Auto2985;
	_Context->hint_Auto2985[2]=it__Auto2985;
	_Context->hint_Auto2985[3]=es__Auto2985;
	_Context->hint_Auto2985[4]=de__Auto2985;
	_Context->hint_Auto2985[5]=nl__Auto2985;
	_Context->hint_Auto2985[6]=pt__Auto2985;
	_Context->hint_Auto2985[7]=xx__Auto2985;
	_Context->x_Auto2985=170;
	_Context->y_Auto2985=15;
	_Context->w_Auto2985=460;
	_Context->h_Auto2985=570;
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->hint_Auto2986[0]=en__Auto2986;
	_Context->hint_Auto2987[0]=en__Auto2987;
	_Context->hint_Auto2988[0]=en__Auto2988;
	_Context->hint_Auto2989[0]=en__Auto2989;
	_Context->hint_Auto2990[0]=en__Auto2990;
	_Context->hint_Auto2991[0]=en__Auto2991;
	_Context->hint_PaletteName[0]=en__PaletteName;
	(void) on_PaletteName_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto2992[i]=" ";
	_Context->msg_Auto2992[0]=en_Auto2992;
	_Context->msg_Auto2992[1]=fr_Auto2992;
	_Context->msg_Auto2992[2]=it_Auto2992;
	_Context->msg_Auto2992[3]=es_Auto2992;
	_Context->msg_Auto2992[4]=de_Auto2992;
	_Context->msg_Auto2992[5]=nl_Auto2992;
	_Context->msg_Auto2992[6]=pt_Auto2992;
	_Context->msg_Auto2992[7]=xx_Auto2992;
	_Context->hint_Auto2992[0]=en__Auto2992;
	_Context->hint_Auto2992[1]=fr__Auto2992;
	_Context->hint_Auto2992[2]=it__Auto2992;
	_Context->hint_Auto2992[3]=es__Auto2992;
	_Context->hint_Auto2992[4]=de__Auto2992;
	_Context->hint_Auto2992[5]=nl__Auto2992;
	_Context->hint_Auto2992[6]=pt__Auto2992;
	_Context->hint_Auto2992[7]=xx__Auto2992;
	for (i=0; i < 8; i++)_Context->msg_Load[i]=" ";
	_Context->msg_Load[0]=en_Load;
	_Context->msg_Load[1]=fr_Load;
	_Context->msg_Load[2]=it_Load;
	_Context->msg_Load[3]=es_Load;
	_Context->msg_Load[4]=de_Load;
	_Context->msg_Load[5]=nl_Load;
	_Context->msg_Load[6]=pt_Load;
	_Context->msg_Load[7]=xx_Load;
	_Context->hint_Load[0]=en__Load;
	_Context->hint_Load[1]=fr__Load;
	_Context->hint_Load[2]=it__Load;
	_Context->hint_Load[3]=es__Load;
	_Context->hint_Load[4]=de__Load;
	_Context->hint_Load[5]=nl__Load;
	_Context->hint_Load[6]=pt__Load;
	_Context->hint_Load[7]=xx__Load;
	for (i=0; i < 8; i++)_Context->msg_Save[i]=" ";
	_Context->msg_Save[0]=en_Save;
	_Context->msg_Save[1]=fr_Save;
	_Context->msg_Save[2]=it_Save;
	_Context->msg_Save[3]=es_Save;
	_Context->msg_Save[4]=de_Save;
	_Context->msg_Save[5]=nl_Save;
	_Context->msg_Save[6]=pt_Save;
	_Context->msg_Save[7]=xx_Save;
	_Context->hint_Save[0]=en__Save;
	_Context->hint_Save[1]=fr__Save;
	_Context->hint_Save[2]=it__Save;
	_Context->hint_Save[3]=es__Save;
	_Context->hint_Save[4]=de__Save;
	_Context->hint_Save[5]=nl__Save;
	_Context->hint_Save[6]=pt__Save;
	_Context->hint_Save[7]=xx__Save;
	_Context->hint_Entry[0]=en__Entry;
	strcpy(_Context->buffer_Entry,"0");
	_Context->hint_Matrix[0]=en__Matrix;
	for (i=0; i < 8; i++)_Context->msg_Cursor[i]=" ";
	_Context->msg_Cursor[0]=en_Cursor;
	_Context->msg_Cursor[1]=fr_Cursor;
	_Context->msg_Cursor[2]=it_Cursor;
	_Context->msg_Cursor[3]=es_Cursor;
	_Context->msg_Cursor[4]=de_Cursor;
	_Context->msg_Cursor[5]=nl_Cursor;
	_Context->msg_Cursor[6]=pt_Cursor;
	_Context->msg_Cursor[7]=xx_Cursor;
	_Context->hint_Cursor[0]=en__Cursor;
	_Context->hint_Cursor[1]=fr__Cursor;
	_Context->hint_Cursor[2]=it__Cursor;
	_Context->hint_Cursor[3]=es__Cursor;
	_Context->hint_Cursor[4]=de__Cursor;
	_Context->hint_Cursor[5]=nl__Cursor;
	_Context->hint_Cursor[6]=pt__Cursor;
	_Context->hint_Cursor[7]=xx__Cursor;
	_Context->x_Cursor=_Context->x_Auto2985+20;
	_Context->y_Cursor=_Context->y_Auto2985+40;
	_Context->w_Cursor=20;
	_Context->h_Cursor=20;
	_Context->fg_Cursor=20;
	_Context->bg_Cursor=20;
	_Context->fid_Cursor=1;
	for (i=0; i < 8; i++)_Context->msg_Drag[i]=" ";
	_Context->msg_Drag[0]=en_Drag;
	_Context->msg_Drag[1]=fr_Drag;
	_Context->msg_Drag[2]=it_Drag;
	_Context->msg_Drag[3]=es_Drag;
	_Context->msg_Drag[4]=de_Drag;
	_Context->msg_Drag[5]=nl_Drag;
	_Context->msg_Drag[6]=pt_Drag;
	_Context->msg_Drag[7]=xx_Drag;
	_Context->hint_Drag[0]=en__Drag;
	_Context->hint_Drag[1]=fr__Drag;
	_Context->hint_Drag[2]=it__Drag;
	_Context->hint_Drag[3]=es__Drag;
	_Context->hint_Drag[4]=de__Drag;
	_Context->hint_Drag[5]=nl__Drag;
	_Context->hint_Drag[6]=pt__Drag;
	_Context->hint_Drag[7]=xx__Drag;
	_Context->x_Drag=_Context->x_Auto2985+40;
	_Context->y_Drag=_Context->y_Auto2985+40;
	_Context->w_Drag=20;
	_Context->h_Drag=20;
	_Context->fg_Drag=20;
	_Context->bg_Drag=20;
	_Context->fid_Drag=1;
	_Context->s_Drag=0;
	_Context->p_Drag=visual_buffer(_Context->x_Drag,_Context->y_Drag,_Context->w_Drag+2,_Context->h_Drag+2);
	for (i=0; i < 8; i++)_Context->msg_Auto2993[i]=" ";
	_Context->msg_Auto2993[0]=en_Auto2993;
	_Context->msg_Auto2993[1]=fr_Auto2993;
	_Context->msg_Auto2993[2]=it_Auto2993;
	_Context->msg_Auto2993[3]=es_Auto2993;
	_Context->msg_Auto2993[4]=de_Auto2993;
	_Context->msg_Auto2993[5]=nl_Auto2993;
	_Context->msg_Auto2993[6]=pt_Auto2993;
	_Context->msg_Auto2993[7]=xx_Auto2993;
	_Context->hint_Auto2993[0]=en__Auto2993;
	_Context->hint_Auto2993[1]=fr__Auto2993;
	_Context->hint_Auto2993[2]=it__Auto2993;
	_Context->hint_Auto2993[3]=es__Auto2993;
	_Context->hint_Auto2993[4]=de__Auto2993;
	_Context->hint_Auto2993[5]=nl__Auto2993;
	_Context->hint_Auto2993[6]=pt__Auto2993;
	_Context->hint_Auto2993[7]=xx__Auto2993;
	for (i=0; i < 8; i++)_Context->msg_Auto2994[i]=" ";
	_Context->msg_Auto2994[0]=en_Auto2994;
	_Context->msg_Auto2994[1]=fr_Auto2994;
	_Context->msg_Auto2994[2]=it_Auto2994;
	_Context->msg_Auto2994[3]=es_Auto2994;
	_Context->msg_Auto2994[4]=de_Auto2994;
	_Context->msg_Auto2994[5]=nl_Auto2994;
	_Context->msg_Auto2994[6]=pt_Auto2994;
	_Context->msg_Auto2994[7]=xx_Auto2994;
	_Context->hint_Auto2994[0]=en__Auto2994;
	_Context->hint_Auto2994[1]=fr__Auto2994;
	_Context->hint_Auto2994[2]=it__Auto2994;
	_Context->hint_Auto2994[3]=es__Auto2994;
	_Context->hint_Auto2994[4]=de__Auto2994;
	_Context->hint_Auto2994[5]=nl__Auto2994;
	_Context->hint_Auto2994[6]=pt__Auto2994;
	_Context->hint_Auto2994[7]=xx__Auto2994;
	for (i=0; i < 8; i++)_Context->msg_Auto2995[i]=" ";
	_Context->msg_Auto2995[0]=en_Auto2995;
	_Context->msg_Auto2995[1]=fr_Auto2995;
	_Context->msg_Auto2995[2]=it_Auto2995;
	_Context->msg_Auto2995[3]=es_Auto2995;
	_Context->msg_Auto2995[4]=de_Auto2995;
	_Context->msg_Auto2995[5]=nl_Auto2995;
	_Context->msg_Auto2995[6]=pt_Auto2995;
	_Context->msg_Auto2995[7]=xx_Auto2995;
	_Context->hint_Auto2995[0]=en__Auto2995;
	_Context->hint_Auto2995[1]=fr__Auto2995;
	_Context->hint_Auto2995[2]=it__Auto2995;
	_Context->hint_Auto2995[3]=es__Auto2995;
	_Context->hint_Auto2995[4]=de__Auto2995;
	_Context->hint_Auto2995[5]=nl__Auto2995;
	_Context->hint_Auto2995[6]=pt__Auto2995;
	_Context->hint_Auto2995[7]=xx__Auto2995;
	for (i=0; i < 8; i++)_Context->msg_Auto2996[i]=" ";
	_Context->msg_Auto2996[0]=en_Auto2996;
	_Context->msg_Auto2996[1]=fr_Auto2996;
	_Context->msg_Auto2996[2]=it_Auto2996;
	_Context->msg_Auto2996[3]=es_Auto2996;
	_Context->msg_Auto2996[4]=de_Auto2996;
	_Context->msg_Auto2996[5]=nl_Auto2996;
	_Context->msg_Auto2996[6]=pt_Auto2996;
	_Context->msg_Auto2996[7]=xx_Auto2996;
	_Context->hint_Auto2996[0]=en__Auto2996;
	_Context->hint_Auto2996[1]=fr__Auto2996;
	_Context->hint_Auto2996[2]=it__Auto2996;
	_Context->hint_Auto2996[3]=es__Auto2996;
	_Context->hint_Auto2996[4]=de__Auto2996;
	_Context->hint_Auto2996[5]=nl__Auto2996;
	_Context->hint_Auto2996[6]=pt__Auto2996;
	_Context->hint_Auto2996[7]=xx__Auto2996;
	for (i=0; i < 8; i++)_Context->msg_Auto2997[i]=" ";
	_Context->msg_Auto2997[0]=en_Auto2997;
	_Context->msg_Auto2997[1]=fr_Auto2997;
	_Context->msg_Auto2997[2]=it_Auto2997;
	_Context->msg_Auto2997[3]=es_Auto2997;
	_Context->msg_Auto2997[4]=de_Auto2997;
	_Context->msg_Auto2997[5]=nl_Auto2997;
	_Context->msg_Auto2997[6]=pt_Auto2997;
	_Context->msg_Auto2997[7]=xx_Auto2997;
	_Context->hint_Auto2997[0]=en__Auto2997;
	_Context->hint_Auto2997[1]=fr__Auto2997;
	_Context->hint_Auto2997[2]=it__Auto2997;
	_Context->hint_Auto2997[3]=es__Auto2997;
	_Context->hint_Auto2997[4]=de__Auto2997;
	_Context->hint_Auto2997[5]=nl__Auto2997;
	_Context->hint_Auto2997[6]=pt__Auto2997;
	_Context->hint_Auto2997[7]=xx__Auto2997;
	_Context->hint_Brightness[0]=en__Brightness;
	_Context->hint_RedValue[0]=en__RedValue;
	_Context->hint_BlueValue[0]=en__BlueValue;
	_Context->hint_GreenValue[0]=en__GreenValue;
	_Context->hint_RedHex[0]=en__RedHex;
	_Context->hint_BlueHex[0]=en__BlueHex;
	_Context->hint_GreenHex[0]=en__GreenHex;
	_Context->hint_BrightBar[0]=en__BrightBar;
	_Context->max_BrightBar=1;
	_Context->value_BrightBar=1;
	_Context->limit_BrightBar=1;
	_Context->value_BrightBar=128;
	_Context->limit_BrightBar=10;
	_Context->max_BrightBar=265;
	sprintf(_Context->buffer_Brightness,"%u",_Context->value_BrightBar);
	_Context->hint_RedBar[0]=en__RedBar;
	_Context->max_RedBar=1;
	_Context->value_RedBar=1;
	_Context->limit_RedBar=1;
	_Context->value_RedBar=0;
	_Context->limit_RedBar=10;
	_Context->max_RedBar=265;
	_Context->hint_BlueBar[0]=en__BlueBar;
	_Context->max_BlueBar=1;
	_Context->value_BlueBar=1;
	_Context->limit_BlueBar=1;
	_Context->value_BlueBar=0;
	_Context->limit_BlueBar=10;
	_Context->max_BlueBar=255;
	_Context->hint_GreenBar[0]=en__GreenBar;
	_Context->max_GreenBar=1;
	_Context->value_GreenBar=1;
	_Context->limit_GreenBar=1;
	_Context->value_GreenBar=0;
	_Context->limit_GreenBar=10;
	_Context->max_GreenBar=265;
	for (i=0; i < 8; i++)_Context->msg_Auto2998[i]=" ";
	_Context->msg_Auto2998[0]=en_Auto2998;
	_Context->msg_Auto2998[1]=fr_Auto2998;
	_Context->msg_Auto2998[2]=it_Auto2998;
	_Context->msg_Auto2998[3]=es_Auto2998;
	_Context->msg_Auto2998[4]=de_Auto2998;
	_Context->msg_Auto2998[5]=nl_Auto2998;
	_Context->msg_Auto2998[6]=pt_Auto2998;
	_Context->msg_Auto2998[7]=xx_Auto2998;
	_Context->hint_Auto2998[0]=en__Auto2998;
	_Context->hint_Auto2998[1]=fr__Auto2998;
	_Context->hint_Auto2998[2]=it__Auto2998;
	_Context->hint_Auto2998[3]=es__Auto2998;
	_Context->hint_Auto2998[4]=de__Auto2998;
	_Context->hint_Auto2998[5]=nl__Auto2998;
	_Context->hint_Auto2998[6]=pt__Auto2998;
	_Context->hint_Auto2998[7]=xx__Auto2998;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2985,_Context->y_Auto2985,460+10,570+10);
	return(0);
}

public 	int	use_palette_editor_hide(struct use_palette_editor_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Drag != (void *) 0)
	&& (_Context->s_Drag != 0)) {
		(void)visual_buffer_put(_Context->p_Drag,_Context->x_Drag,_Context->y_Drag);
		_Context->s_Drag=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2985,_Context->y_Auto2985);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	use_palette_editor_remove(struct use_palette_editor_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->p_Drag != (void *) 0)
		_Context->p_Drag = visual_drop(_Context->p_Drag);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Entry_show(struct use_palette_editor_context * _Context) {
	GetColour(_Context);
	/*visual_frame(_Context->x_Auto2985+415,_Context->y_Auto2985+21,24+2,16+2,5);
visual_text(_Context->x_Auto2985+415+1,_Context->y_Auto2985+21+1,24,16,vfh[1],16,31,_Context->buffer_Entry,3,0);
;*/
	visual_frame(_Context->x_Auto2985+95,_Context->y_Auto2985+440,24+2,16+2,5);
visual_text(_Context->x_Auto2985+95+1,_Context->y_Auto2985+440+1,24,16,vfh[1],16,31,_Context->buffer_RedValue,3,0);
;
	visual_frame(_Context->x_Auto2985+121,_Context->y_Auto2985+440,16+2,16+2,5);
visual_text(_Context->x_Auto2985+121+1,_Context->y_Auto2985+440+1,16,16,vfh[1],16,31,_Context->buffer_RedHex,2,0);
;
		visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+440,290,20,vfh[1],27,28,_Context->value_RedBar,_Context->limit_RedBar,_Context->max_RedBar,259);
;
	visual_frame(_Context->x_Auto2985+95,_Context->y_Auto2985+460,24+2,16+2,5);
visual_text(_Context->x_Auto2985+95+1,_Context->y_Auto2985+460+1,24,16,vfh[1],16,31,_Context->buffer_GreenValue,3,0);
;
	visual_frame(_Context->x_Auto2985+121,_Context->y_Auto2985+460,16+2,16+2,5);
visual_text(_Context->x_Auto2985+121+1,_Context->y_Auto2985+460+1,16,16,vfh[1],16,31,_Context->buffer_GreenHex,2,0);
;
		visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+460,290,20,vfh[1],27,28,_Context->value_GreenBar,_Context->limit_GreenBar,_Context->max_GreenBar,259);
;
	visual_frame(_Context->x_Auto2985+95,_Context->y_Auto2985+480,24+2,16+2,5);
visual_text(_Context->x_Auto2985+95+1,_Context->y_Auto2985+480+1,24,16,vfh[1],16,31,_Context->buffer_BlueValue,3,0);
;
	visual_frame(_Context->x_Auto2985+121,_Context->y_Auto2985+480,16+2,16+2,5);
visual_text(_Context->x_Auto2985+121+1,_Context->y_Auto2985+480+1,16,16,vfh[1],16,31,_Context->buffer_BlueHex,2,0);
;
		visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+480,290,20,vfh[1],27,28,_Context->value_BlueBar,_Context->limit_BlueBar,_Context->max_BlueBar,259);
;
	on_BrightBar_show(_Context);
	return(-1);
}
private int on_Matrix_show(struct use_palette_editor_context * _Context) {
	int l,c,w,h,i,n;
	int d;
	char msg[32];
	int truecolour;
	if(!(get_pixel_format()))
	truecolour=1;
	else truecolour=0;
	w=(416/16);
	h=(352/16);
	i=convert_integer(_Context, _Context->buffer_Entry,3);
	visual_freeze();
	for(l=1;l<=16;l++){
	for(c=1;c<=16;c++){
	n=((c-1)+((l-1)*16));
	sprintf(msg,"%u",n);
	visual_filzone(
	_Context->x_Auto2985+20+((c-1)*w),
	_Context->y_Auto2985+40+((l-1)*h),w,h,n,0);
	if((!(n))||(n==16))
	d=15;
	else d=16;
	visual_text(
	_Context->x_Auto2985+20+((c-1)*w),
	_Context->y_Auto2985+40+((l-1)*h),w,h,vfh[1],d,0,msg,strlen(msg),3);
	if(n==i){
	if(truecolour)
	relieved(_Context->x_Auto2985+20+((c-1)*w),_Context->y_Auto2985+40+((l-1)*h),w,h,0x1613);
	else relief(_Context->x_Auto2985+20+((c-1)*w),_Context->y_Auto2985+40+((l-1)*h),w,h,0x0016,0,0x0013);
	_Context->x_Cursor=_Context->x_Auto2985+20+((c-1)*w);
	_Context->y_Cursor=_Context->y_Auto2985+40+((l-1)*h);
	_Context->w_Cursor=w;
	_Context->h_Cursor=h;
		visual_image(_Context->x_Cursor,_Context->y_Cursor,_Context->w_Cursor,_Context->h_Cursor,_Context->msg_Cursor[_Context->language],1539);
;
		}
	else if(truecolour)
	relieved(_Context->x_Auto2985+20+((c-1)*w),_Context->y_Auto2985+40+((l-1)*h),w,h,0x1316);
	else relief(_Context->x_Auto2985+20+((c-1)*w),_Context->y_Auto2985+40+((l-1)*h),w,h,0x0013,0,0x0016);
	}
	}
	visual_thaw(_Context->x_Auto2985+20,_Context->y_Auto2985+40,416,352);
		return(-1);
}
private int on_BrightBar_show(struct use_palette_editor_context * _Context) {
	_Context->value_BrightBar=((_Context->value_RedBar+_Context->value_GreenBar+_Context->value_BlueBar)/3);
	sprintf(_Context->buffer_Brightness,"%u",_Context->value_BrightBar);
		visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+420,290,20,vfh[1],27,28,_Context->value_BrightBar,_Context->limit_BrightBar,_Context->max_BrightBar,259);

	visual_frame(_Context->x_Auto2985+114,_Context->y_Auto2985+420,24+2,16+2,5);
visual_text(_Context->x_Auto2985+114+1,_Context->y_Auto2985+420+1,24,16,vfh[1],16,31,_Context->buffer_Brightness,3,0);

	return(-1);
}

public	int	use_palette_editor_show(struct use_palette_editor_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2985,_Context->y_Auto2985);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto2985,_Context->y_Auto2985,460,570,GetWidgetStyle(0),_Context->msg_Auto2985[_Context->language],strlen(_Context->msg_Auto2985[_Context->language]))) != 0)
) {
		visual_window(_Context->x_Auto2985,_Context->y_Auto2985,460,570,vfh[2],_Context->msg_Auto2985[_Context->language],strlen(_Context->msg_Auto2985[_Context->language]),0x407);
		}
	visual_frame(_Context->x_Auto2985+18,_Context->y_Auto2985+38,421,357,2);
	visual_frame(_Context->x_Auto2985+18,_Context->y_Auto2985+411,421,100,4);
	visual_frame(_Context->x_Auto2985+18,_Context->y_Auto2985+512,421,50,4);
	visual_frame(_Context->x_Auto2985+30,_Context->y_Auto2985+440,110,20,2);
	visual_frame(_Context->x_Auto2985+30,_Context->y_Auto2985+480,110,20,2);
	visual_frame(_Context->x_Auto2985+30,_Context->y_Auto2985+460,110,20,2);
	visual_frame(_Context->x_Auto2985+30,_Context->y_Auto2985+540,256+2,16+2,5);
	visual_text(_Context->x_Auto2985+30+1,_Context->y_Auto2985+540+1,256,16,vfh[1],16,31,_Context->buffer_PaletteName,255,0);
	_Context->trigger_Auto2992=visual_trigger_code(_Context->msg_Auto2992[_Context->language],strlen(_Context->msg_Auto2992[_Context->language]));
	visual_button(_Context->x_Auto2985+287,_Context->y_Auto2985+540,20,16,vfh[8],27,28,_Context->msg_Auto2992[_Context->language],strlen(_Context->msg_Auto2992[_Context->language]),0);
	_Context->trigger_Load=visual_trigger_code(_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]));
	visual_button(_Context->x_Auto2985+350,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]),1296);
	_Context->trigger_Save=visual_trigger_code(_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]));
	visual_button(_Context->x_Auto2985+309,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]),1296);
	(void) on_Entry_show(_Context);
	(void) on_Matrix_show(_Context);
	visual_text(_Context->x_Auto2985+30,_Context->y_Auto2985+525,256,16,vfh[2],16,0,_Context->msg_Auto2993[_Context->language],strlen(_Context->msg_Auto2993[_Context->language]),1282);
	visual_text(_Context->x_Auto2985+33,_Context->y_Auto2985+483,56,16,vfh[2],9,0,_Context->msg_Auto2994[_Context->language],strlen(_Context->msg_Auto2994[_Context->language]),1281);
	visual_text(_Context->x_Auto2985+33,_Context->y_Auto2985+463,56,16,vfh[2],10,0,_Context->msg_Auto2995[_Context->language],strlen(_Context->msg_Auto2995[_Context->language]),1281);
	visual_text(_Context->x_Auto2985+33,_Context->y_Auto2985+442,56,16,vfh[2],12,0,_Context->msg_Auto2996[_Context->language],strlen(_Context->msg_Auto2996[_Context->language]),1281);
	visual_text(_Context->x_Auto2985+33,_Context->y_Auto2985+421,70,16,vfh[2],31,0,_Context->msg_Auto2997[_Context->language],strlen(_Context->msg_Auto2997[_Context->language]),1281);
	visual_frame(_Context->x_Auto2985+114,_Context->y_Auto2985+420,24+2,16+2,5);
	visual_text(_Context->x_Auto2985+114+1,_Context->y_Auto2985+420+1,24,16,vfh[1],16,31,_Context->buffer_Brightness,3,0);
	(void) on_BrightBar_show(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+440,290,20,vfh[1],27,28,_Context->value_RedBar,_Context->limit_RedBar,_Context->max_RedBar,259);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+480,290,20,vfh[1],27,28,_Context->value_BlueBar,_Context->limit_BlueBar,_Context->max_BlueBar,259);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+460,290,20,vfh[1],27,28,_Context->value_GreenBar,_Context->limit_GreenBar,_Context->max_GreenBar,259);
	_Context->trigger_Auto2998=visual_trigger_code(_Context->msg_Auto2998[_Context->language],strlen(_Context->msg_Auto2998[_Context->language]));
	visual_button(_Context->x_Auto2985+391,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Auto2998[_Context->language],strlen(_Context->msg_Auto2998[_Context->language]),1296);
	visual_thaw(_Context->x_Auto2985,_Context->y_Auto2985,460,570);

	return(0);
}

private int PaletteName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows a palette filename to be specified for the ";
			mptr[1]="palette load and save operations performed by the corresponding push ";
			mptr[2]="buttons.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Load_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this button is actioned the current colour palette information ";
			mptr[1]="will be loaded from the Rgb palette file described by the preceeding palette filename input ";
			mptr[2]="field.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Save_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this button is actioned the current colour palette information ";
			mptr[1]="will be saved to the Rgb palette file described by the preceeding palette filename input ";
			mptr[2]="field.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Entry_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[9];
			mptr[0] = " ";
			mptr[1]=" This edit field displays the palette colour code of the currently ";
			mptr[2]="selected  colour.   ";
			mptr[3]="The current colour is usually selected by clicking, with the left ";
			mptr[4]="button of  the mouse, on the required entry in the palette display ";
			mptr[5]="zone.  ";
			mptr[6]=" The value may be modified by hand in order to bring a specific colour ";
			mptr[7]="code for inspection and modification.  ";
			mptr[8]="   ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Matrix_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[9];
			mptr[0] = " ";
			mptr[1]=" This area of the palette editor displays the effective colours described ";
			mptr[2]="by the  256 colour triad information records. The current colour may ";
			mptr[3]="be selected by a left click event over the required colour.  ";
			mptr[4]=" ";
			mptr[5]=" The RGB colour information of a particular palette entry may be copied ";
			mptr[6]="to another location by a simple drag and drop operation activetool the ";
			mptr[7]="mouse.  ";
			mptr[8]="    ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Cursor_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This symbol represents the currently selected palette entry.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Drag_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This symbol is displayed when a colour copy drag and drop operation ";
			mptr[1]="is underway.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int RedValue_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field presents the decimal value of the Red fraction of ";
			mptr[1]=" the currently selected colour for inspection and eventual modification. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int BlueValue_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field presents the decimal value of the Blue fraction of ";
			mptr[1]=" the currently selected colour for inspection and eventual modification. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int GreenValue_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field presents the decimal value of the Green fraction of ";
			mptr[1]=" the currently selected colour for inspection and eventual modification. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int BrightBar_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This scrollbar control allows fine tuning of the Red fraction of  ";
			mptr[1]="the currently selected colour palette entry.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int RedBar_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This scrollbar control allows fine tuning of the Red fraction of  ";
			mptr[1]="the currently selected colour palette entry.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int BlueBar_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This scrollbar control allows fine tuning of the Blue fraction of ";
			mptr[1]=" the currently selected colour palette entry.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int GreenBar_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This scrollbar control allows fine tuning of the Green fraction of ";
			mptr[1]=" the currently selected colour palette entry.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2998_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "When this button is actioned the current colour palette information ";
			mptr[1]="will be used to redisplay the current model editor.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2985action(struct use_palette_editor_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			use_palette_editor_hide(_Context);

		_Context->x_Auto2985 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2985 < 0) { _Context->x_Auto2985=0; }
		_Context->y_Auto2985 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2985 < 0) { _Context->y_Auto2985=0; }
			use_palette_editor_show(_Context);

		visual_thaw(_Context->x_Auto2985,_Context->y_Auto2985,460,570);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto2992_event(struct use_palette_editor_context * _Context) {
	use_file_selector(_Context->buffer_PaletteName,WIDGET_FILE_RGB);
		use_palette_editor_show(_Context);
;
	return(-1);
}
private int on_Load_event(struct use_palette_editor_context * _Context) {
	if(load_palette(_Context->buffer_PaletteName)==0){
		use_palette_editor_show(_Context);

	}
	return(-1);
}
private int on_Save_event(struct use_palette_editor_context * _Context) {
	FILE*h;
	char*pptr;
	if(!(pptr=get_vga_palette()))
	return(-1);
	else if(!(h=fopen(_Context->buffer_PaletteName,"w")))
	return(-1);
	else{
	fwrite(pptr,256,4,h);
	fclose(h);
	return(-1);
	}
	return(-1);
}
private int on_Matrix_event(struct use_palette_editor_context * _Context) {
	int l,c,w,h;
	int k;
	int x=visual_event(7);
	int y=visual_event(6);
	x-=_Context->x_Auto2985+20;
	y-=_Context->y_Auto2985+40;
	w=416/16;
	h=352/16;
	x/=w;
	y/=h;
	c=(x+(y*16));
	switch(visual_event(1)){
	case _MIMO_DOWN:
	sprintf(_Context->buffer_Entry,"%u",c);
	on_Entry_show(_Context);
	on_Matrix_show(_Context);
	if((k=on_Drag_event(_Context))!=-1){
	if(k!=c){
	ReplaceColour(_Context, k);
	}
	}
	}
	return(-1);
}
private int on_Drag_event(struct use_palette_editor_context * _Context) {
	int l,c,w,h;
	int x,y;
	int event=0;
	while(1){
	_Context->x_Drag=visual_event(7);
	_Context->y_Drag=visual_event(6);
		if ((_Context->p_Drag != (void *) 0)
	&& (_Context->s_Drag == 0)) {
		(void)visual_buffer_get(_Context->p_Drag,_Context->x_Drag,_Context->y_Drag);
		_Context->s_Drag=1;
		}
	if ((_Context->p_Drag != (void *) 0)
	&& (_Context->s_Drag == 0)) {
		(void)visual_buffer_get(_Context->p_Drag,_Context->x_Drag,_Context->y_Drag);
		_Context->s_Drag=1;
		}
	visual_image(_Context->x_Drag,_Context->y_Drag,_Context->w_Drag,_Context->h_Drag,_Context->msg_Drag[_Context->language],1029);
;
	event=visual_getch();
		if ((_Context->p_Drag != (void *) 0)
	&& (_Context->s_Drag != 0)) {
		(void)visual_buffer_put(_Context->p_Drag,_Context->x_Drag,_Context->y_Drag);
		_Context->s_Drag=0;
		}
;
	if((event==256)
	&&(visual_event(1)==_MIMO_UP)){
	x=visual_event(7);
	y=visual_event(6);
	if((x>_Context->x_Auto2985+20)
	&&(y>_Context->y_Auto2985+40)
	&&(x<(_Context->x_Auto2985+20+416))
	&&(y<(_Context->y_Auto2985+40+352))){
	x-=_Context->x_Auto2985+20;
	y-=_Context->y_Auto2985+40;
	w=(416/16);
	h=(352/16);
	x/=w;
	y/=h;
	c=(x+(y*16));
	return(c);
	}
	else return(-1);
	}
	}
		return(-1);
}
private int on_BrightBar_event(struct use_palette_editor_context * _Context) {
	int b;
	int v;
	b=convert_integer(_Context, _Context->buffer_Brightness,3);
	if(_Context->value_BrightBar>b){
	v=(_Context->value_BrightBar-b);
	if(((_Context->value_RedBar+v)<=255)
	&&((_Context->value_GreenBar+v)<=255)
	&&((_Context->value_BlueBar+v)<=255)){
	_Context->value_RedBar+=v;
	_Context->value_GreenBar+=v;
	_Context->value_BlueBar+=v;
	}
	}
	else if(_Context->value_BrightBar<b){
	v=(b-_Context->value_BrightBar);
	if((_Context->value_RedBar>=v)
	&&(_Context->value_GreenBar>=v)
	&&(_Context->value_BlueBar>=v)){
	_Context->value_RedBar-=v;
	_Context->value_GreenBar-=v;
	_Context->value_BlueBar-=v;
	}
	}
	sprintf(_Context->buffer_RedValue,"%u",_Context->value_RedBar);
	sprintf(_Context->buffer_GreenValue,"%u",_Context->value_GreenBar);
	sprintf(_Context->buffer_BlueValue,"%u",_Context->value_BlueBar);
	PutColour(_Context);
	sprintf(_Context->buffer_Brightness,"%u",_Context->value_BrightBar);
	visual_frame(_Context->x_Auto2985+114,_Context->y_Auto2985+420,24+2,16+2,5);
visual_text(_Context->x_Auto2985+114+1,_Context->y_Auto2985+420+1,24,16,vfh[1],16,31,_Context->buffer_Brightness,3,0);
;
	on_Entry_show(_Context);
	return(-1);
}

private int on_BrightBar_action(struct use_palette_editor_context * _Context) {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (_Context->x_Auto2985+140+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_BrightBar -= 1;
		if (_Context->value_BrightBar < 0) 
			_Context->value_BrightBar = 0;
		(void) on_BrightBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+420,290,20,vfh[1],27,28,_Context->value_BrightBar,_Context->limit_BrightBar,_Context->max_BrightBar,259);
		return(-1);
		}
	if ( visual_event(7) > (_Context->x_Auto2985+140+290-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_BrightBar += 1;
		if (!(_Context->max_BrightBar))
			_Context->value_BrightBar = 0;
		else if ((_Context->max_BrightBar < _Context->limit_BrightBar) 
		&& (_Context->value_BrightBar >= _Context->max_BrightBar)) 
			_Context->value_BrightBar = (_Context->max_BrightBar-1);
		else if (_Context->value_BrightBar > (_Context->max_BrightBar-_Context->limit_BrightBar)) 
			_Context->value_BrightBar = (_Context->max_BrightBar-_Context->limit_BrightBar);
		(void) on_BrightBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+420,290,20,vfh[1],27,28,_Context->value_BrightBar,_Context->limit_BrightBar,_Context->max_BrightBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+420,290,20,vfh[1],27,28,_Context->value_BrightBar,_Context->limit_BrightBar,_Context->max_BrightBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		atx = _Context->value_BrightBar;
		_Context->value_BrightBar = (((visual_event(7) - (_Context->x_Auto2985+140+20)) * _Context->max_BrightBar) / (290 - (2 * 20)));
		if (_Context->value_BrightBar < 0) 
			_Context->value_BrightBar = 0;
		else if (_Context->value_BrightBar > (_Context->max_BrightBar-_Context->limit_BrightBar)) 
			_Context->value_BrightBar = (_Context->max_BrightBar-_Context->limit_BrightBar);
		if (_Context->value_BrightBar != atx) {
		(void) on_BrightBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+420,290,20,vfh[1],27,28,_Context->value_BrightBar,_Context->limit_BrightBar,_Context->max_BrightBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_BrightBar -= (_Context->limit_BrightBar/2);
			if (_Context->value_BrightBar < 0) 
				_Context->value_BrightBar = 0;
		(void) on_BrightBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+420,290,20,vfh[1],27,28,_Context->value_BrightBar,_Context->limit_BrightBar,_Context->max_BrightBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_BrightBar += (_Context->limit_BrightBar/2);
			if (!(_Context->max_BrightBar))
				_Context->value_BrightBar = 0;
			else if ((_Context->max_BrightBar < _Context->limit_BrightBar) 
			&& (_Context->value_BrightBar >= _Context->max_BrightBar)) 
				_Context->value_BrightBar = (_Context->max_BrightBar-1);
			else if (_Context->value_BrightBar > (_Context->max_BrightBar-_Context->limit_BrightBar)) 
				_Context->value_BrightBar = (_Context->max_BrightBar-_Context->limit_BrightBar);
		(void) on_BrightBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+420,290,20,vfh[1],27,28,_Context->value_BrightBar,_Context->limit_BrightBar,_Context->max_BrightBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+420,290,20,vfh[1],27,28,_Context->value_BrightBar,_Context->limit_BrightBar,_Context->max_BrightBar,259);

	return(1);
}
private int on_RedBar_event(struct use_palette_editor_context * _Context) {
	sprintf(_Context->buffer_RedValue,"%u",_Context->value_RedBar);
	PutColour(_Context);
	on_Entry_show(_Context);
	return(-1);
}

private int on_RedBar_action(struct use_palette_editor_context * _Context) {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (_Context->x_Auto2985+140+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_RedBar -= 1;
		if (_Context->value_RedBar < 0) 
			_Context->value_RedBar = 0;
		(void) on_RedBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+440,290,20,vfh[1],27,28,_Context->value_RedBar,_Context->limit_RedBar,_Context->max_RedBar,259);
		return(-1);
		}
	if ( visual_event(7) > (_Context->x_Auto2985+140+290-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_RedBar += 1;
		if (!(_Context->max_RedBar))
			_Context->value_RedBar = 0;
		else if ((_Context->max_RedBar < _Context->limit_RedBar) 
		&& (_Context->value_RedBar >= _Context->max_RedBar)) 
			_Context->value_RedBar = (_Context->max_RedBar-1);
		else if (_Context->value_RedBar > (_Context->max_RedBar-_Context->limit_RedBar)) 
			_Context->value_RedBar = (_Context->max_RedBar-_Context->limit_RedBar);
		(void) on_RedBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+440,290,20,vfh[1],27,28,_Context->value_RedBar,_Context->limit_RedBar,_Context->max_RedBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+440,290,20,vfh[1],27,28,_Context->value_RedBar,_Context->limit_RedBar,_Context->max_RedBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		atx = _Context->value_RedBar;
		_Context->value_RedBar = (((visual_event(7) - (_Context->x_Auto2985+140+20)) * _Context->max_RedBar) / (290 - (2 * 20)));
		if (_Context->value_RedBar < 0) 
			_Context->value_RedBar = 0;
		else if (_Context->value_RedBar > (_Context->max_RedBar-_Context->limit_RedBar)) 
			_Context->value_RedBar = (_Context->max_RedBar-_Context->limit_RedBar);
		if (_Context->value_RedBar != atx) {
		(void) on_RedBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+440,290,20,vfh[1],27,28,_Context->value_RedBar,_Context->limit_RedBar,_Context->max_RedBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_RedBar -= (_Context->limit_RedBar/2);
			if (_Context->value_RedBar < 0) 
				_Context->value_RedBar = 0;
		(void) on_RedBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+440,290,20,vfh[1],27,28,_Context->value_RedBar,_Context->limit_RedBar,_Context->max_RedBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_RedBar += (_Context->limit_RedBar/2);
			if (!(_Context->max_RedBar))
				_Context->value_RedBar = 0;
			else if ((_Context->max_RedBar < _Context->limit_RedBar) 
			&& (_Context->value_RedBar >= _Context->max_RedBar)) 
				_Context->value_RedBar = (_Context->max_RedBar-1);
			else if (_Context->value_RedBar > (_Context->max_RedBar-_Context->limit_RedBar)) 
				_Context->value_RedBar = (_Context->max_RedBar-_Context->limit_RedBar);
		(void) on_RedBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+440,290,20,vfh[1],27,28,_Context->value_RedBar,_Context->limit_RedBar,_Context->max_RedBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+440,290,20,vfh[1],27,28,_Context->value_RedBar,_Context->limit_RedBar,_Context->max_RedBar,259);

	return(1);
}
private int on_BlueBar_event(struct use_palette_editor_context * _Context) {
	sprintf(_Context->buffer_BlueValue,"%u",_Context->value_BlueBar);
	PutColour(_Context);
	on_Entry_show(_Context);
	return(-1);
}

private int on_BlueBar_action(struct use_palette_editor_context * _Context) {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (_Context->x_Auto2985+140+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_BlueBar -= 1;
		if (_Context->value_BlueBar < 0) 
			_Context->value_BlueBar = 0;
		(void) on_BlueBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+480,290,20,vfh[1],27,28,_Context->value_BlueBar,_Context->limit_BlueBar,_Context->max_BlueBar,259);
		return(-1);
		}
	if ( visual_event(7) > (_Context->x_Auto2985+140+290-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_BlueBar += 1;
		if (!(_Context->max_BlueBar))
			_Context->value_BlueBar = 0;
		else if ((_Context->max_BlueBar < _Context->limit_BlueBar) 
		&& (_Context->value_BlueBar >= _Context->max_BlueBar)) 
			_Context->value_BlueBar = (_Context->max_BlueBar-1);
		else if (_Context->value_BlueBar > (_Context->max_BlueBar-_Context->limit_BlueBar)) 
			_Context->value_BlueBar = (_Context->max_BlueBar-_Context->limit_BlueBar);
		(void) on_BlueBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+480,290,20,vfh[1],27,28,_Context->value_BlueBar,_Context->limit_BlueBar,_Context->max_BlueBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+480,290,20,vfh[1],27,28,_Context->value_BlueBar,_Context->limit_BlueBar,_Context->max_BlueBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		atx = _Context->value_BlueBar;
		_Context->value_BlueBar = (((visual_event(7) - (_Context->x_Auto2985+140+20)) * _Context->max_BlueBar) / (290 - (2 * 20)));
		if (_Context->value_BlueBar < 0) 
			_Context->value_BlueBar = 0;
		else if (_Context->value_BlueBar > (_Context->max_BlueBar-_Context->limit_BlueBar)) 
			_Context->value_BlueBar = (_Context->max_BlueBar-_Context->limit_BlueBar);
		if (_Context->value_BlueBar != atx) {
		(void) on_BlueBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+480,290,20,vfh[1],27,28,_Context->value_BlueBar,_Context->limit_BlueBar,_Context->max_BlueBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_BlueBar -= (_Context->limit_BlueBar/2);
			if (_Context->value_BlueBar < 0) 
				_Context->value_BlueBar = 0;
		(void) on_BlueBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+480,290,20,vfh[1],27,28,_Context->value_BlueBar,_Context->limit_BlueBar,_Context->max_BlueBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_BlueBar += (_Context->limit_BlueBar/2);
			if (!(_Context->max_BlueBar))
				_Context->value_BlueBar = 0;
			else if ((_Context->max_BlueBar < _Context->limit_BlueBar) 
			&& (_Context->value_BlueBar >= _Context->max_BlueBar)) 
				_Context->value_BlueBar = (_Context->max_BlueBar-1);
			else if (_Context->value_BlueBar > (_Context->max_BlueBar-_Context->limit_BlueBar)) 
				_Context->value_BlueBar = (_Context->max_BlueBar-_Context->limit_BlueBar);
		(void) on_BlueBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+480,290,20,vfh[1],27,28,_Context->value_BlueBar,_Context->limit_BlueBar,_Context->max_BlueBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+480,290,20,vfh[1],27,28,_Context->value_BlueBar,_Context->limit_BlueBar,_Context->max_BlueBar,259);

	return(1);
}
private int on_GreenBar_event(struct use_palette_editor_context * _Context) {
	sprintf(_Context->buffer_GreenValue,"%u",_Context->value_GreenBar);
	PutColour(_Context);
	on_Entry_show(_Context);
	return(-1);
}

private int on_GreenBar_action(struct use_palette_editor_context * _Context) {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (_Context->x_Auto2985+140+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_GreenBar -= 1;
		if (_Context->value_GreenBar < 0) 
			_Context->value_GreenBar = 0;
		(void) on_GreenBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+460,290,20,vfh[1],27,28,_Context->value_GreenBar,_Context->limit_GreenBar,_Context->max_GreenBar,259);
		return(-1);
		}
	if ( visual_event(7) > (_Context->x_Auto2985+140+290-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_GreenBar += 1;
		if (!(_Context->max_GreenBar))
			_Context->value_GreenBar = 0;
		else if ((_Context->max_GreenBar < _Context->limit_GreenBar) 
		&& (_Context->value_GreenBar >= _Context->max_GreenBar)) 
			_Context->value_GreenBar = (_Context->max_GreenBar-1);
		else if (_Context->value_GreenBar > (_Context->max_GreenBar-_Context->limit_GreenBar)) 
			_Context->value_GreenBar = (_Context->max_GreenBar-_Context->limit_GreenBar);
		(void) on_GreenBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+460,290,20,vfh[1],27,28,_Context->value_GreenBar,_Context->limit_GreenBar,_Context->max_GreenBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+460,290,20,vfh[1],27,28,_Context->value_GreenBar,_Context->limit_GreenBar,_Context->max_GreenBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		atx = _Context->value_GreenBar;
		_Context->value_GreenBar = (((visual_event(7) - (_Context->x_Auto2985+140+20)) * _Context->max_GreenBar) / (290 - (2 * 20)));
		if (_Context->value_GreenBar < 0) 
			_Context->value_GreenBar = 0;
		else if (_Context->value_GreenBar > (_Context->max_GreenBar-_Context->limit_GreenBar)) 
			_Context->value_GreenBar = (_Context->max_GreenBar-_Context->limit_GreenBar);
		if (_Context->value_GreenBar != atx) {
		(void) on_GreenBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+460,290,20,vfh[1],27,28,_Context->value_GreenBar,_Context->limit_GreenBar,_Context->max_GreenBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_GreenBar -= (_Context->limit_GreenBar/2);
			if (_Context->value_GreenBar < 0) 
				_Context->value_GreenBar = 0;
		(void) on_GreenBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+460,290,20,vfh[1],27,28,_Context->value_GreenBar,_Context->limit_GreenBar,_Context->max_GreenBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_GreenBar += (_Context->limit_GreenBar/2);
			if (!(_Context->max_GreenBar))
				_Context->value_GreenBar = 0;
			else if ((_Context->max_GreenBar < _Context->limit_GreenBar) 
			&& (_Context->value_GreenBar >= _Context->max_GreenBar)) 
				_Context->value_GreenBar = (_Context->max_GreenBar-1);
			else if (_Context->value_GreenBar > (_Context->max_GreenBar-_Context->limit_GreenBar)) 
				_Context->value_GreenBar = (_Context->max_GreenBar-_Context->limit_GreenBar);
		(void) on_GreenBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+460,290,20,vfh[1],27,28,_Context->value_GreenBar,_Context->limit_GreenBar,_Context->max_GreenBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto2985+140,_Context->y_Auto2985+460,290,20,vfh[1],27,28,_Context->value_GreenBar,_Context->limit_GreenBar,_Context->max_GreenBar,259);

	return(1);
}
private int on_Auto2998_event(struct use_palette_editor_context * _Context) {
		use_palette_editor_hide(_Context);
;
	draw_console();
		use_palette_editor_show(_Context);
;
	return(-1);
}


public	int	use_palette_editor_event(
struct use_palette_editor_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto2992 == mb ) return(3);
		if (_Context->trigger_Load == mb ) return(4);
		if (_Context->trigger_Save == mb ) return(5);
		if (_Context->trigger_Auto2998 == mb ) return(19);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2985+439) )  
	&&  (my >= (_Context->y_Auto2985+4) )  
	&&  (mx <= (_Context->x_Auto2985+456) )  
	&&  (my <= (_Context->y_Auto2985+20) )) {
		return(1);	/* Auto2985 */

		}
	if ((mx >= (_Context->x_Auto2985+423) )  
	&&  (my >= (_Context->y_Auto2985+4) )  
	&&  (mx <= (_Context->x_Auto2985+440) )  
	&&  (my <= (_Context->y_Auto2985+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vpaledit.htm");
			};
		return(-1);	/* Auto2985 */

		}
	if ((mx >= (_Context->x_Auto2985+407) )  
	&&  (my >= (_Context->y_Auto2985+4) )  
	&&  (mx <= (_Context->x_Auto2985+424) )  
	&&  (my <= (_Context->y_Auto2985+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		use_palette_editor_show(_Context);
		return(-1);	/* Auto2985 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2985+4) )  
		&&  (my >= (_Context->y_Auto2985+4) )  
		&&  (mx <= (_Context->x_Auto2985+392) )  
		&&  (my <= (_Context->y_Auto2985+20) )) {
			return( Auto2985action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto2985+30) ) 
	&&  ( my >= (_Context->y_Auto2985+540) ) 
	&&  ( mx <= (_Context->x_Auto2985+30+256) ) 
	&&  ( my <= (_Context->y_Auto2985+540+16))) {
		return(2); /* PaletteName */
		}
	if (( mx >= (_Context->x_Auto2985+287) ) 
	&&  ( my >= (_Context->y_Auto2985+540) ) 
	&&  ( mx <= (_Context->x_Auto2985+287+20) ) 
	&&  ( my <= (_Context->y_Auto2985+540+16))) {
		return(3); /* Auto2992 */
		}
	if (( mx >= (_Context->x_Auto2985+350) ) 
	&&  ( my >= (_Context->y_Auto2985+517) ) 
	&&  ( mx <= (_Context->x_Auto2985+350+40) ) 
	&&  ( my <= (_Context->y_Auto2985+517+40))) {
		return(4); /* Load */
		}
	if (( mx >= (_Context->x_Auto2985+309) ) 
	&&  ( my >= (_Context->y_Auto2985+517) ) 
	&&  ( mx <= (_Context->x_Auto2985+309+40) ) 
	&&  ( my <= (_Context->y_Auto2985+517+40))) {
		return(5); /* Save */
		}
	if (( mx >= (_Context->x_Auto2985+415) ) 
	&&  ( my >= (_Context->y_Auto2985+21) ) 
	&&  ( mx <= (_Context->x_Auto2985+415+24) ) 
	&&  ( my <= (_Context->y_Auto2985+21+16))) {
		return(6); /* Entry */
		}
	if (( mx >= (_Context->x_Auto2985+20) ) 
	&&  ( my >= (_Context->y_Auto2985+40) ) 
	&&  ( mx <= (_Context->x_Auto2985+20+416) ) 
	&&  ( my <= (_Context->y_Auto2985+40+352))) {
		return(7); /* Matrix */
		}
	if (( mx >= (_Context->x_Auto2985+114) ) 
	&&  ( my >= (_Context->y_Auto2985+420) ) 
	&&  ( mx <= (_Context->x_Auto2985+114+24) ) 
	&&  ( my <= (_Context->y_Auto2985+420+16))) {
		return(8); /* Brightness */
		}
	if (( mx >= (_Context->x_Auto2985+95) ) 
	&&  ( my >= (_Context->y_Auto2985+440) ) 
	&&  ( mx <= (_Context->x_Auto2985+95+24) ) 
	&&  ( my <= (_Context->y_Auto2985+440+16))) {
		return(9); /* RedValue */
		}
	if (( mx >= (_Context->x_Auto2985+95) ) 
	&&  ( my >= (_Context->y_Auto2985+480) ) 
	&&  ( mx <= (_Context->x_Auto2985+95+24) ) 
	&&  ( my <= (_Context->y_Auto2985+480+16))) {
		return(10); /* BlueValue */
		}
	if (( mx >= (_Context->x_Auto2985+95) ) 
	&&  ( my >= (_Context->y_Auto2985+460) ) 
	&&  ( mx <= (_Context->x_Auto2985+95+24) ) 
	&&  ( my <= (_Context->y_Auto2985+460+16))) {
		return(11); /* GreenValue */
		}
	if (( mx >= (_Context->x_Auto2985+121) ) 
	&&  ( my >= (_Context->y_Auto2985+440) ) 
	&&  ( mx <= (_Context->x_Auto2985+121+16) ) 
	&&  ( my <= (_Context->y_Auto2985+440+16))) {
		return(12); /* RedHex */
		}
	if (( mx >= (_Context->x_Auto2985+121) ) 
	&&  ( my >= (_Context->y_Auto2985+480) ) 
	&&  ( mx <= (_Context->x_Auto2985+121+16) ) 
	&&  ( my <= (_Context->y_Auto2985+480+16))) {
		return(13); /* BlueHex */
		}
	if (( mx >= (_Context->x_Auto2985+121) ) 
	&&  ( my >= (_Context->y_Auto2985+460) ) 
	&&  ( mx <= (_Context->x_Auto2985+121+16) ) 
	&&  ( my <= (_Context->y_Auto2985+460+16))) {
		return(14); /* GreenHex */
		}
	if (( mx >= (_Context->x_Auto2985+140) ) 
	&&  ( my >= (_Context->y_Auto2985+420) ) 
	&&  ( mx <= (_Context->x_Auto2985+140+290) ) 
	&&  ( my <= (_Context->y_Auto2985+420+20))) {
		return(15); /* BrightBar */
		}
	if (( mx >= (_Context->x_Auto2985+140) ) 
	&&  ( my >= (_Context->y_Auto2985+440) ) 
	&&  ( mx <= (_Context->x_Auto2985+140+290) ) 
	&&  ( my <= (_Context->y_Auto2985+440+20))) {
		return(16); /* RedBar */
		}
	if (( mx >= (_Context->x_Auto2985+140) ) 
	&&  ( my >= (_Context->y_Auto2985+480) ) 
	&&  ( mx <= (_Context->x_Auto2985+140+290) ) 
	&&  ( my <= (_Context->y_Auto2985+480+20))) {
		return(17); /* BlueBar */
		}
	if (( mx >= (_Context->x_Auto2985+140) ) 
	&&  ( my >= (_Context->y_Auto2985+460) ) 
	&&  ( mx <= (_Context->x_Auto2985+140+290) ) 
	&&  ( my <= (_Context->y_Auto2985+460+20))) {
		return(18); /* GreenBar */
		}
	if (( mx >= (_Context->x_Auto2985+391) ) 
	&&  ( my >= (_Context->y_Auto2985+517) ) 
	&&  ( mx <= (_Context->x_Auto2985+391+40) ) 
	&&  ( my <= (_Context->y_Auto2985+517+40))) {
		return(19); /* Auto2998 */
		}

	return(-1);
}
private int on_Matrix_getfocus(struct use_palette_editor_context * _Context) {
	return(visual_getch());
	return(-1);
}


public	int	use_palette_editor_focus(struct use_palette_editor_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* PaletteName */
				_Context->keycode = visual_edit(_Context->x_Auto2985+30+1,_Context->y_Auto2985+540+1,256,16,vfh[1],_Context->buffer_PaletteName,255);
			break;
			case	0x3 :
				/* Auto2992 */
				_Context->trigger_Auto2992=visual_trigger_code(_Context->msg_Auto2992[_Context->language],strlen(_Context->msg_Auto2992[_Context->language]));
				visual_button(_Context->x_Auto2985+287,_Context->y_Auto2985+540,20,16,vfh[8],27,28,_Context->msg_Auto2992[_Context->language],strlen(_Context->msg_Auto2992[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2992=visual_trigger_code(_Context->msg_Auto2992[_Context->language],strlen(_Context->msg_Auto2992[_Context->language]));
	visual_button(_Context->x_Auto2985+287,_Context->y_Auto2985+540,20,16,vfh[8],27,28,_Context->msg_Auto2992[_Context->language],strlen(_Context->msg_Auto2992[_Context->language]),0);
				break;
			case	0x4 :
				/* Load */
				_Context->trigger_Load=visual_trigger_code(_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]));
				visual_button(_Context->x_Auto2985+350,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]),1298);
				_Context->keycode = visual_getch();
				_Context->trigger_Load=visual_trigger_code(_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]));
	visual_button(_Context->x_Auto2985+350,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]),1296);
				break;
			case	0x5 :
				/* Save */
				_Context->trigger_Save=visual_trigger_code(_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]));
				visual_button(_Context->x_Auto2985+309,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]),1298);
				_Context->keycode = visual_getch();
				_Context->trigger_Save=visual_trigger_code(_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]));
	visual_button(_Context->x_Auto2985+309,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]),1296);
				break;
			case	0x6 :
				/* Entry */
				_Context->keycode = visual_edit(_Context->x_Auto2985+415+1,_Context->y_Auto2985+21+1,24,16,vfh[1],_Context->buffer_Entry,3);
				on_Entry_show(_Context);
			break;
			case	0x7 :
				/* Matrix */
				_Context->keycode = on_Matrix_getfocus(_Context);
			break;
			case	0x8 :
				/* Brightness */
				_Context->keycode = visual_edit(_Context->x_Auto2985+114+1,_Context->y_Auto2985+420+1,24,16,vfh[1],_Context->buffer_Brightness,3);
			break;
			case	0x9 :
				/* RedValue */
				_Context->keycode = visual_edit(_Context->x_Auto2985+95+1,_Context->y_Auto2985+440+1,24,16,vfh[1],_Context->buffer_RedValue,3);
				PutColour(_Context);
					use_palette_editor_show(_Context);
;
				;
			break;
			case	0xa :
				/* BlueValue */
				_Context->keycode = visual_edit(_Context->x_Auto2985+95+1,_Context->y_Auto2985+480+1,24,16,vfh[1],_Context->buffer_BlueValue,3);
				PutColour(_Context);
					use_palette_editor_show(_Context);
;
			break;
			case	0xb :
				/* GreenValue */
				_Context->keycode = visual_edit(_Context->x_Auto2985+95+1,_Context->y_Auto2985+460+1,24,16,vfh[1],_Context->buffer_GreenValue,3);
				PutColour(_Context);
					use_palette_editor_show(_Context);
;
			break;
			case	0xf :
				/* BrightBar */
				_Context->keycode=visual_getch();
				break;
			case	0x10 :
				/* RedBar */
				_Context->keycode=visual_getch();
				break;
			case	0x11 :
				/* BlueBar */
				_Context->keycode=visual_getch();
				break;
			case	0x12 :
				/* GreenBar */
				_Context->keycode=visual_getch();
				break;
			case	0x13 :
				/* Auto2998 */
				_Context->trigger_Auto2998=visual_trigger_code(_Context->msg_Auto2998[_Context->language],strlen(_Context->msg_Auto2998[_Context->language]));
				visual_button(_Context->x_Auto2985+391,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Auto2998[_Context->language],strlen(_Context->msg_Auto2998[_Context->language]),1298);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2998=visual_trigger_code(_Context->msg_Auto2998[_Context->language],strlen(_Context->msg_Auto2998[_Context->language]));
	visual_button(_Context->x_Auto2985+391,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Auto2998[_Context->language],strlen(_Context->msg_Auto2998[_Context->language]),1296);
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
			_Context->focus_item=19;
			use_palette_editor_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=use_palette_editor_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (PaletteName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Load_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Save_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Entry_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (Matrix_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (RedValue_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (BlueValue_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (GreenValue_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (BrightBar_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (RedBar_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (BlueBar_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (GreenBar_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (Auto2998_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2985 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* PaletteName */
					continue;
				case	0x3 :
					/* Auto2992 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2992=visual_trigger_code(_Context->msg_Auto2992[_Context->language],strlen(_Context->msg_Auto2992[_Context->language]));
						visual_button(_Context->x_Auto2985+287,_Context->y_Auto2985+540,20,16,vfh[8],27,28,_Context->msg_Auto2992[_Context->language],strlen(_Context->msg_Auto2992[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2992=visual_trigger_code(_Context->msg_Auto2992[_Context->language],strlen(_Context->msg_Auto2992[_Context->language]));
	visual_button(_Context->x_Auto2985+287,_Context->y_Auto2985+540,20,16,vfh[8],27,28,_Context->msg_Auto2992[_Context->language],strlen(_Context->msg_Auto2992[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2992_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Load */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Load=visual_trigger_code(_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]));
						visual_button(_Context->x_Auto2985+350,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]),1298);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Load=visual_trigger_code(_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]));
	visual_button(_Context->x_Auto2985+350,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Load[_Context->language],strlen(_Context->msg_Load[_Context->language]),1296);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Load_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Save */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Save=visual_trigger_code(_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]));
						visual_button(_Context->x_Auto2985+309,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]),1298);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Save=visual_trigger_code(_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]));
	visual_button(_Context->x_Auto2985+309,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Save[_Context->language],strlen(_Context->msg_Save[_Context->language]),1296);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Save_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Entry */
					continue;
				case	0x7 :
					/* Matrix */
					if ( visual_event(1) &  0x30 ) {
					if ((_Context->keycode = on_Matrix_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Brightness */
					continue;
				case	0x9 :
					/* RedValue */
					continue;
				case	0xa :
					/* BlueValue */
					continue;
				case	0xb :
					/* GreenValue */
					continue;
				case	0xc :
					/* RedHex */
					continue;
				case	0xd :
					/* BlueHex */
					continue;
				case	0xe :
					/* GreenHex */
					continue;
				case	0xf :
					/* BrightBar */
					(void) on_BrightBar_action(_Context);
					continue;
				case	0x10 :
					/* RedBar */
					(void) on_RedBar_action(_Context);
					continue;
				case	0x11 :
					/* BlueBar */
					(void) on_BlueBar_action(_Context);
					continue;
				case	0x12 :
					/* GreenBar */
					(void) on_GreenBar_action(_Context);
					continue;
				case	0x13 :
					/* Auto2998 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2998=visual_trigger_code(_Context->msg_Auto2998[_Context->language],strlen(_Context->msg_Auto2998[_Context->language]));
						visual_button(_Context->x_Auto2985+391,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Auto2998[_Context->language],strlen(_Context->msg_Auto2998[_Context->language]),1298);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2998=visual_trigger_code(_Context->msg_Auto2998[_Context->language],strlen(_Context->msg_Auto2998[_Context->language]));
	visual_button(_Context->x_Auto2985+391,_Context->y_Auto2985+517,40,40,vfh[8],27,28,_Context->msg_Auto2998[_Context->language],strlen(_Context->msg_Auto2998[_Context->language]),1296);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2998_event(_Context)) != -1) break;

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

#endif /* _vpaledit_c */
