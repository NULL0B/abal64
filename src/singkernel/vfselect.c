
#ifndef _vfselect_c
#define _vfselect_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vfselect.xml  */
/* Target         : vfselect.c  */
/* Identification : 0.0-1100887306-19951.19950 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto773   "Sing : Version 1.0a : File Selector"
#define en_SkinImage   "skin.gif"
#define fr_SkinImage   "skin.gif"
#define en_amato666   "Current Directory Path"
#define fr_amato666   "R‚pertoire courant"
#define it_amato666   ""
#define es_amato666   ""
#define de_amato666   ""
#define nl_amato666   ""
#define pt_amato666   ""
#define xx_amato666   ""
#define en_Auto781   "Selected Filename(s)"
#define fr_Auto781   "Fichier(s) Selection‚(s)"
#define it_Auto781   ""
#define es_Auto781   ""
#define de_Auto781   ""
#define nl_Auto781   ""
#define pt_Auto781   ""
#define xx_Auto781   ""
#define en_Auto775   "File Selection Criteria"
#define fr_Auto775   "CritŠre de S‚lection de Fichiers"
#define it_Auto775   ""
#define es_Auto775   ""
#define de_Auto775   ""
#define nl_Auto775   ""
#define pt_Auto775   ""
#define xx_Auto775   ""
#define en_Auto779   "File Type"
#define fr_Auto779   "Type de Fichier"
#define it_Auto779   ""
#define es_Auto779   ""
#define de_Auto779   ""
#define nl_Auto779   ""
#define pt_Auto779   ""
#define xx_Auto779   ""
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Find   "&Find"
#define fr_Find   "&Rechercher"
#define en_InfoSelector   "Infos"
#define fr_InfoSelector   "Infos"
#define it_InfoSelector   "Infos"
#define es_InfoSelector   "Infos"
#define de_InfoSelector   "Infos"
#define nl_InfoSelector   "Infos"
#define pt_InfoSelector   "Infos"
#define xx_InfoSelector   "Infos"
#define en_Delete   "&Delete"
#define fr_Delete   "&Suprimer"
#define it_Delete   ""
#define es_Delete   ""
#define de_Delete   ""
#define nl_Delete   ""
#define pt_Delete   ""
#define xx_Delete   ""
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
#define en_Path   ""
#define en_Slider   ""
#define en_FileNames   "-|-|-|-"
#define fr_FileNames   "-|-|-|-"
#define it_FileNames   "-|-|-|-"
#define es_FileNames   "-|-|-|-"
#define de_FileNames   "-|-|-|-"
#define nl_FileNames   "-|-|-|-"
#define pt_FileNames   "-|-|-|-"
#define xx_FileNames   "-|-|-|-"
#define en_FileInfos   "Name|Size|Time|Date"
#define fr_FileInfos   "Nom|Taille|Heure|Date"
#define it_FileInfos   "Name|Size|Time|Date"
#define es_FileInfos   "Name|Size|Time|Date"
#define de_FileInfos   "Name|Size|Time|Date"
#define nl_FileInfos   "Name|Size|Time|Date"
#define pt_FileInfos   "Name|Size|Time|Date"
#define xx_FileInfos   "Name|Size|Time|Date"
static int	vfh[10];

private struct file_selector_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto773[8];
	int	x_Auto773;
	int	y_Auto773;
	int	w_Auto773;
	int	h_Auto773;
	char * msg_SkinImage[8];
	char * msg_amato666[8];
	char * msg_Auto781[8];
	char	buffer_Result[79];
	char * msg_Auto775[8];
	char * msg_Auto779[8];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Find[8];
	int	trigger_Find;
	char * msg_InfoSelector[8];
	int	trigger_InfoSelector;
	int	value_InfoSelector;
	char * msg_Delete[8];
	int	trigger_Delete;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_FileType[8];
	int	value_FileType;
	char	buffer_Path[79];
	char	buffer_FileSelection[59];
	int	value_Slider;
	int	limit_Slider;
	int	max_Slider;
	char * msg_FileNames[8];
	int	value_FileNames;
	int	column_FileNames;
	char	buffer_FileNames[17][78];
	char * row_FileNames;
	char * msg_FileInfos[8];
	int	value_FileInfos;
	int	column_FileInfos;
	char	buffer_FileInfos[17][78];
	char * row_FileInfos;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[5];
	};
private int on_FileSelection_create(struct file_selector_context * _Context) {
	get_widget_filename(_Context->buffer_FileSelection,58,_Context->value_FileType,
	_Context->buffer_Path,78);
	return(-1);
}
private int on_Slider_create(struct file_selector_context * _Context) {
	_Context->value_Slider=0;
	_Context->limit_Slider=(17*4);
	_Context->max_Slider=0;
	return(-1);
}
private int on_FileNames_create(struct file_selector_context * _Context) {
	int w,r,c,n;
	int i=_Context->value_Slider;
	if(4>0){
	for(r=0;r<17;r++)
	for(c=0;c<78;c++)
	_Context->buffer_FileNames[r][c]=' ';
	if(!(_Context->value_InfoSelector)){
	if(_Context->value_Slider!=0)
	n=1;
	else n=0;
	for(r=1;r<=17;r++){
	if ( r > 0 ) { _Context->row_FileNames=&_Context->buffer_FileNames[r-1][0]; } ;
	if((_Context->max_Slider=filefinder(
	(_Context->row_FileNames+0),20,
	&_Context->buffer_FileSelection,58,n,i))==0)
	break;
	if(filefinder((_Context->row_FileNames+20),20,
	&_Context->buffer_FileSelection,58,(n=1),(i=0))==0)
	break;
	if(filefinder((_Context->row_FileNames+40),19,
	&_Context->buffer_FileSelection,58,n,i)==0)
	break;
	if(filefinder((_Context->row_FileNames+59),19,
	&_Context->buffer_FileSelection,58,n,i)==0)
	break;
	}
	}
	}
	return(-1);
}
private int on_FileInfos_create(struct file_selector_context * _Context) {
	int w,r,c,n;
	int i=_Context->value_Slider;
	if(4>0){
	for(r=0;r<17;r++)
	for(c=0;c<78;c++)
	_Context->buffer_FileInfos[r][c]=' ';
	if(_Context->value_Slider!=0)
	n=1;
	else n=0;
	if(_Context->value_InfoSelector!=0){
	for(r=1;r<=17;r++){
	if ( r > 0 ) { _Context->row_FileInfos=&_Context->buffer_FileInfos[r-1][0]; } ;
	if((_Context->max_Slider=fileinformer(
	(_Context->row_FileInfos+0),
	20+20+19+19,
	&_Context->buffer_FileSelection,58,n,i))==0)
	break;
	n=1;i=0;
	}
	}
	}
	return(-1);
}

public	int	file_selector_create(
	struct file_selector_context ** cptr,
	char * pResult,
	char * pFileType,
	char * pPath,
	char * pFileSelection)
{

	int i;
	struct file_selector_context * _Context=(struct file_selector_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct file_selector_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=13;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Result, 78, pResult);
		visual_transferin((void *) 0, 0, pFileType);
		if (!( pFileType )) _Context->value_FileType=0;
		else	_Context->value_FileType = *((int *)pFileType);
		visual_transferin(_Context->buffer_Path, 78, pPath);
		visual_transferin(_Context->buffer_FileSelection, 58, pFileSelection);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto773[i]=" ";
	_Context->msg_Auto773[0]=en_Auto773;
	_Context->x_Auto773=60;
	_Context->y_Auto773=25;
	_Context->w_Auto773=680;
	_Context->h_Auto773=550;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_SkinImage[i]=" ";
	_Context->msg_SkinImage[0]=en_SkinImage;
	_Context->msg_SkinImage[1]=fr_SkinImage;
	for (i=0; i < 8; i++)_Context->msg_amato666[i]=" ";
	_Context->msg_amato666[0]=en_amato666;
	_Context->msg_amato666[1]=fr_amato666;
	_Context->msg_amato666[2]=it_amato666;
	_Context->msg_amato666[3]=es_amato666;
	_Context->msg_amato666[4]=de_amato666;
	_Context->msg_amato666[5]=nl_amato666;
	_Context->msg_amato666[6]=pt_amato666;
	_Context->msg_amato666[7]=xx_amato666;
	for (i=0; i < 8; i++)_Context->msg_Auto781[i]=" ";
	_Context->msg_Auto781[0]=en_Auto781;
	_Context->msg_Auto781[1]=fr_Auto781;
	_Context->msg_Auto781[2]=it_Auto781;
	_Context->msg_Auto781[3]=es_Auto781;
	_Context->msg_Auto781[4]=de_Auto781;
	_Context->msg_Auto781[5]=nl_Auto781;
	_Context->msg_Auto781[6]=pt_Auto781;
	_Context->msg_Auto781[7]=xx_Auto781;
	for (i=0; i < 8; i++)_Context->msg_Auto775[i]=" ";
	_Context->msg_Auto775[0]=en_Auto775;
	_Context->msg_Auto775[1]=fr_Auto775;
	_Context->msg_Auto775[2]=it_Auto775;
	_Context->msg_Auto775[3]=es_Auto775;
	_Context->msg_Auto775[4]=de_Auto775;
	_Context->msg_Auto775[5]=nl_Auto775;
	_Context->msg_Auto775[6]=pt_Auto775;
	_Context->msg_Auto775[7]=xx_Auto775;
	for (i=0; i < 8; i++)_Context->msg_Auto779[i]=" ";
	_Context->msg_Auto779[0]=en_Auto779;
	_Context->msg_Auto779[1]=fr_Auto779;
	_Context->msg_Auto779[2]=it_Auto779;
	_Context->msg_Auto779[3]=es_Auto779;
	_Context->msg_Auto779[4]=de_Auto779;
	_Context->msg_Auto779[5]=nl_Auto779;
	_Context->msg_Auto779[6]=pt_Auto779;
	_Context->msg_Auto779[7]=xx_Auto779;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Find[i]=" ";
	_Context->msg_Find[0]=en_Find;
	_Context->msg_Find[1]=fr_Find;
	for (i=0; i < 8; i++)_Context->msg_InfoSelector[i]=" ";
	_Context->msg_InfoSelector[0]=en_InfoSelector;
	_Context->msg_InfoSelector[1]=fr_InfoSelector;
	_Context->msg_InfoSelector[2]=it_InfoSelector;
	_Context->msg_InfoSelector[3]=es_InfoSelector;
	_Context->msg_InfoSelector[4]=de_InfoSelector;
	_Context->msg_InfoSelector[5]=nl_InfoSelector;
	_Context->msg_InfoSelector[6]=pt_InfoSelector;
	_Context->msg_InfoSelector[7]=xx_InfoSelector;
	_Context->value_InfoSelector=0;
	for (i=0; i < 8; i++)_Context->msg_Delete[i]=" ";
	_Context->msg_Delete[0]=en_Delete;
	_Context->msg_Delete[1]=fr_Delete;
	_Context->msg_Delete[2]=it_Delete;
	_Context->msg_Delete[3]=es_Delete;
	_Context->msg_Delete[4]=de_Delete;
	_Context->msg_Delete[5]=nl_Delete;
	_Context->msg_Delete[6]=pt_Delete;
	_Context->msg_Delete[7]=xx_Delete;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	for (i=0; i < 8; i++)_Context->msg_FileType[i]=" ";
	_Context->value_FileType=detect_file_extension(_Context->buffer_Result,78,_Context->value_FileType);
	(void) on_FileSelection_create(_Context);
	_Context->max_Slider=1;
	_Context->value_Slider=1;
	_Context->limit_Slider=1;
	(void) on_Slider_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_FileNames[i]=" ";
	_Context->msg_FileNames[0]=en_FileNames;
	_Context->msg_FileNames[1]=fr_FileNames;
	_Context->msg_FileNames[2]=it_FileNames;
	_Context->msg_FileNames[3]=es_FileNames;
	_Context->msg_FileNames[4]=de_FileNames;
	_Context->msg_FileNames[5]=nl_FileNames;
	_Context->msg_FileNames[6]=pt_FileNames;
	_Context->msg_FileNames[7]=xx_FileNames;
	if ( 0 > 0 ) { _Context->row_FileNames=&_Context->buffer_FileNames[0-1][0]; } ;
	(void) on_FileNames_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_FileInfos[i]=" ";
	_Context->msg_FileInfos[0]=en_FileInfos;
	_Context->msg_FileInfos[1]=fr_FileInfos;
	_Context->msg_FileInfos[2]=it_FileInfos;
	_Context->msg_FileInfos[3]=es_FileInfos;
	_Context->msg_FileInfos[4]=de_FileInfos;
	_Context->msg_FileInfos[5]=nl_FileInfos;
	_Context->msg_FileInfos[6]=pt_FileInfos;
	_Context->msg_FileInfos[7]=xx_FileInfos;
	if ( 0 > 0 ) { _Context->row_FileInfos=&_Context->buffer_FileInfos[0-1][0]; } ;
	(void) on_FileInfos_create(_Context);
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto773,_Context->y_Auto773,680+10,550+10);
	return(0);
}

public 	int	file_selector_hide(struct file_selector_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto773,_Context->y_Auto773);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	file_selector_remove(
	struct file_selector_context * _Context,
	char * pResult,
	char * pFileType,
	char * pPath,
	char * pFileSelection)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Result, 78, pResult);
		visual_transferout((void *) 0, 0, pFileType);
		if ( pFileType != (char *) 0)
			*((int*)pFileType) = _Context->value_FileType;
		visual_transferout(_Context->buffer_Path, 78, pPath);
		visual_transferout(_Context->buffer_FileSelection, 58, pFileSelection);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_FileNames_show(struct file_selector_context * _Context) {
	if(!(_Context->value_InfoSelector)){
		visual_table(_Context->x_Auto773+20,_Context->y_Auto773+80,630+2,300+2,vfh[1],27,0,_Context->msg_FileNames[_Context->language],_Context->buffer_FileNames,0x0401,(char*) 0);

	}
	else{
		visual_table(_Context->x_Auto773+20,_Context->y_Auto773+80,630+2,300+2,vfh[1],27,0,_Context->msg_FileInfos[_Context->language],_Context->buffer_FileInfos,0x0401,(char*) 0);
;
	}
	return(-1);
}
private int on_FileInfos_show(struct file_selector_context * _Context) {
	if(_Context->value_InfoSelector!=0){
		visual_table(_Context->x_Auto773+20,_Context->y_Auto773+80,630+2,300+2,vfh[1],27,0,_Context->msg_FileInfos[_Context->language],_Context->buffer_FileInfos,0x0401,(char*) 0);
;
	}
	else{
		visual_table(_Context->x_Auto773+20,_Context->y_Auto773+80,630+2,300+2,vfh[1],27,0,_Context->msg_FileNames[_Context->language],_Context->buffer_FileNames,0x0401,(char*) 0);
;
	}
	return(-1);
}

public	int	file_selector_show(struct file_selector_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto773,_Context->y_Auto773);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto773,_Context->y_Auto773,680,550,vfh[2],_Context->msg_Auto773[_Context->language],strlen(_Context->msg_Auto773[_Context->language]),0x407);
	visual_image(_Context->x_Auto773+2,_Context->y_Auto773+20,673,526,_Context->msg_SkinImage[_Context->language],4);
	visual_text(_Context->x_Auto773+20,_Context->y_Auto773+390,490,20,vfh[2],27,0,_Context->msg_amato666[_Context->language],strlen(_Context->msg_amato666[_Context->language]),258);
	visual_text(_Context->x_Auto773+20,_Context->y_Auto773+30,630,16,vfh[2],27,0,_Context->msg_Auto781[_Context->language],strlen(_Context->msg_Auto781[_Context->language]),258);
	visual_frame(_Context->x_Auto773+20,_Context->y_Auto773+50,630+2,20+2,5);
	visual_text(_Context->x_Auto773+20+1,_Context->y_Auto773+50+1,630,20,vfh[1],27,0,_Context->buffer_Result,78,0);
	visual_text(_Context->x_Auto773+180,_Context->y_Auto773+440,470,20,vfh[2],27,0,_Context->msg_Auto775[_Context->language],strlen(_Context->msg_Auto775[_Context->language]),258);
	visual_text(_Context->x_Auto773+20,_Context->y_Auto773+440,120,20,vfh[2],27,0,_Context->msg_Auto779[_Context->language],strlen(_Context->msg_Auto779[_Context->language]),258);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto773+20,_Context->y_Auto773+500,120,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Find=visual_trigger_code(_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]));
	visual_button(_Context->x_Auto773+180,_Context->y_Auto773+500,120,30,vfh[2],27,0,_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]),0);
	_Context->trigger_InfoSelector=visual_trigger_code(_Context->msg_InfoSelector[_Context->language],strlen(_Context->msg_InfoSelector[_Context->language]));
	visual_switch(_Context->x_Auto773+320,_Context->y_Auto773+510,70,32,vfh[2],12,31,_Context->msg_InfoSelector[_Context->language],strlen(_Context->msg_InfoSelector[_Context->language]),_Context->value_InfoSelector| 0x0030);
	_Context->trigger_Delete=visual_trigger_code(_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]));
	visual_button(_Context->x_Auto773+400,_Context->y_Auto773+500,110,30,vfh[2],27,0,_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto773+540,_Context->y_Auto773+500,110,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_select(_Context->x_Auto773+20,_Context->y_Auto773+460,120,70,vfh[1],27,0,parse_selection(WidgetFileNames,&_Context->value_FileType),0);
	visual_frame(_Context->x_Auto773+20,_Context->y_Auto773+410,630+2,20+2,5);
	visual_text(_Context->x_Auto773+20+1,_Context->y_Auto773+410+1,630,20,vfh[1],0,0,_Context->buffer_Path,78,0);
	visual_frame(_Context->x_Auto773+180,_Context->y_Auto773+460,470+2,20+2,5);
	visual_text(_Context->x_Auto773+180+1,_Context->y_Auto773+460+1,470,20,vfh[1],27,0,_Context->buffer_FileSelection,58,0);
	visual_scrollbar(_Context->x_Auto773+650,_Context->y_Auto773+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,3);
	(void) on_FileNames_show(_Context);
	(void) on_FileInfos_show(_Context);
	visual_thaw(_Context->x_Auto773,_Context->y_Auto773,680,550);
	visual_thaw(_Context->x_Auto773,_Context->y_Auto773,680,550);

	return(0);
}

private int Auto773action(struct file_selector_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			file_selector_hide(_Context);

		_Context->x_Auto773 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto773 < 0) { _Context->x_Auto773=0; }
		_Context->y_Auto773 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto773 < 0) { _Context->y_Auto773=0; }
			file_selector_show(_Context);

		visual_thaw(_Context->x_Auto773,_Context->y_Auto773,680,550);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct file_selector_context * _Context) {
	return(13);
	return(-1);
}
private int on_Find_event(struct file_selector_context * _Context) {
	on_Path_losefocus(_Context);
	on_Slider_create(_Context);
	on_FileNames_create(_Context);
		file_selector_show(_Context);
;
	return(-1);
}
private int on_InfoSelector_event(struct file_selector_context * _Context) {
	_Context->value_Slider=0;
	on_Slider_event(_Context);
	return(-1);
}
private int on_Delete_event(struct file_selector_context * _Context) {
	delete_system_file(_Context->buffer_FileSelection,58);
	on_Find_event(_Context);
	return(-1);
}
private int on_Cancel_event(struct file_selector_context * _Context) {
	return(27);
	return(-1);
}
private int on_Slider_event(struct file_selector_context * _Context) {
	if(!(_Context->value_InfoSelector)){
	on_FileNames_create(_Context);
	}
	else{
	on_FileInfos_create(_Context);
	}
		file_selector_show(_Context);
;
	return(-1);
}

private int on_Slider_action(struct file_selector_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto773+80+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Slider -= 1;
		if (_Context->value_Slider < 0) 
			_Context->value_Slider = 0;
		(void) on_Slider_event(_Context);
	visual_scrollbar(_Context->x_Auto773+650,_Context->y_Auto773+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto773+80+300-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Slider += 1;
		if (_Context->value_Slider > (_Context->max_Slider-_Context->limit_Slider)) 
			_Context->value_Slider = (_Context->max_Slider-_Context->limit_Slider);
		(void) on_Slider_event(_Context);
	visual_scrollbar(_Context->x_Auto773+650,_Context->y_Auto773+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto773+650,_Context->y_Auto773+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_Slider;
		_Context->value_Slider = (((visual_event(6) - (_Context->y_Auto773+80+20)) * _Context->max_Slider) / (300 - (2 * 20)));
		if (_Context->value_Slider < 0) 
			_Context->value_Slider = 0;
		else if (_Context->value_Slider > (_Context->max_Slider-_Context->limit_Slider)) 
			_Context->value_Slider = (_Context->max_Slider-_Context->limit_Slider);
		if (_Context->value_Slider != aty) {
		(void) on_Slider_event(_Context);
	visual_scrollbar(_Context->x_Auto773+650,_Context->y_Auto773+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_Slider -= (_Context->limit_Slider/2);
			if (_Context->value_Slider < 0) 
				_Context->value_Slider = 0;
		(void) on_Slider_event(_Context);
	visual_scrollbar(_Context->x_Auto773+650,_Context->y_Auto773+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_Slider += (_Context->limit_Slider/2);
			if (_Context->value_Slider > (_Context->max_Slider-_Context->limit_Slider)) 
				_Context->value_Slider = (_Context->max_Slider-_Context->limit_Slider);
		(void) on_Slider_event(_Context);
	visual_scrollbar(_Context->x_Auto773+650,_Context->y_Auto773+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto773+650,_Context->y_Auto773+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,3);

	return(1);
}
private int on_FileNames_event(struct file_selector_context * _Context) {
	int r;
	if(_Context->value_InfoSelector!=0){
	if(!(r=_Context->value_FileNames))
	return(-1);
	else{
	_Context->value_FileInfos=r;
	on_FileInfos_event(_Context);
	}
	}
	else{
	if(!(r=_Context->value_FileNames))
	return(-1);
	if ( r > 0 ) { _Context->row_FileNames=&_Context->buffer_FileNames[r-1][0]; } ;
	if(visual_event(2)==1){
	switch(_Context->column_FileNames){
	case 1:
	if(!(fnisdirectory((_Context->row_FileNames+0),20))){
	fntransfer(
	_Context->buffer_Result,78,
	_Context->buffer_Path,78,
	(_Context->row_FileNames+0),20);
	}
	else{
	fnchangedirectory(
	_Context->buffer_Path,78,
	(_Context->row_FileNames+0),20
	);
	on_Find_event(_Context);
	}
	break;
	case 2:
	if(!(fnisdirectory((_Context->row_FileNames+0),20))){
	fntransfer(
	_Context->buffer_Result,78,
	_Context->buffer_Path,78,
	(_Context->row_FileNames+20),20);
	}
	else{
	fnchangedirectory(
	_Context->buffer_Path,78,
	(_Context->row_FileNames+20),20
	);
	on_Find_event(_Context);
	}
	break;
	case 3:
	if(!(fnisdirectory((_Context->row_FileNames+0),20))){
	fntransfer(
	_Context->buffer_Result,78,
	_Context->buffer_Path,78,
	(_Context->row_FileNames+40),19);
	}
	else{
	fnchangedirectory(
	_Context->buffer_Path,78,
	(_Context->row_FileNames+40),19
	);
	on_Find_event(_Context);
	}
	break;
	case 4:
	if(!(fnisdirectory((_Context->row_FileNames+0),20))){
	fntransfer(
	_Context->buffer_Result,78,
	_Context->buffer_Path,78,
	(_Context->row_FileNames+59),19);
	}
	else{
	fnchangedirectory(
	_Context->buffer_Path,78,
	(_Context->row_FileNames+59),19
	);
	on_Find_event(_Context);
	}
	break;
	}
	}
	else{
	switch(_Context->column_FileNames){
	case 1:fnaddfile(
	_Context->buffer_Result,78,
	_Context->buffer_Path,78,
	(_Context->row_FileNames+0),20);
	break;
	case 2:fnaddfile(
	_Context->buffer_Result,78,
	_Context->buffer_Path,78,
	(_Context->row_FileNames+20),20);
	break;
	case 3:fnaddfile(
	_Context->buffer_Result,78,
	_Context->buffer_Path,78,
	(_Context->row_FileNames+40),19);
	break;
	case 4:fnaddfile(
	_Context->buffer_Result,78,
	_Context->buffer_Path,78,
	(_Context->row_FileNames+59),19);
	break;
	}
	}
		file_selector_show(_Context);
;
	}
	return(-1);
}
private int on_FileInfos_event(struct file_selector_context * _Context) {
	int r;
	if(!(_Context->value_InfoSelector!=0)){
	on_FileNames_event(_Context);
	}
	else{
	if(!(r=_Context->value_FileNames))
	return;
	_Context->value_FileInfos=r;
	if ( r > 0 ) { _Context->row_FileInfos=&_Context->buffer_FileInfos[r-1][0]; } ;
	if(visual_event(2)==1){
	if(!(fnisdirectory((_Context->row_FileInfos+0),20))){
	fntransfer(
	_Context->buffer_Result,78,
	_Context->buffer_Path,78,
	(_Context->row_FileInfos+0),20);
	}
	else{
	fnchangedirectory(
	_Context->buffer_Path,78,
	(_Context->row_FileInfos+0),20
	);
	on_Find_event(_Context);
	}
	}
	else{
	fnaddfile(
	_Context->buffer_Result,78,
	_Context->buffer_Path,78,
	(_Context->row_FileInfos+0),20);
	}
	}
		file_selector_show(_Context);
;
	return(-1);
}


public	int	file_selector_event(
struct file_selector_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(3);
		if (_Context->trigger_Find == mb ) return(4);
		if (_Context->trigger_InfoSelector == mb ) return(5);
		if (_Context->trigger_Delete == mb ) return(6);
		if (_Context->trigger_Cancel == mb ) return(7);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto773+659) )  
	&&  (my >= (_Context->y_Auto773+4) )  
	&&  (mx <= (_Context->x_Auto773+676) )  
	&&  (my <= (_Context->y_Auto773+20) )) {
		return(1);	/* Auto773 */

		}
	if ((mx >= (_Context->x_Auto773+643) )  
	&&  (my >= (_Context->y_Auto773+4) )  
	&&  (mx <= (_Context->x_Auto773+660) )  
	&&  (my <= (_Context->y_Auto773+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vfselect.htm");
			};
		return(-1);	/* Auto773 */

		}
	if ((mx >= (_Context->x_Auto773+627) )  
	&&  (my >= (_Context->y_Auto773+4) )  
	&&  (mx <= (_Context->x_Auto773+644) )  
	&&  (my <= (_Context->y_Auto773+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		file_selector_show(_Context);
		return(-1);	/* Auto773 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto773+4) )  
		&&  (my >= (_Context->y_Auto773+4) )  
		&&  (mx <= (_Context->x_Auto773+612) )  
		&&  (my <= (_Context->y_Auto773+20) )) {
			return( Auto773action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto773+20) ) 
	&&  ( my >= (_Context->y_Auto773+50) ) 
	&&  ( mx <= (_Context->x_Auto773+20+630) ) 
	&&  ( my <= (_Context->y_Auto773+50+20))) {
		return(2); /* Result */
		}
	if (( mx >= (_Context->x_Auto773+20) ) 
	&&  ( my >= (_Context->y_Auto773+500) ) 
	&&  ( mx <= (_Context->x_Auto773+20+120) ) 
	&&  ( my <= (_Context->y_Auto773+500+30))) {
		return(3); /* Accept */
		}
	if (( mx >= (_Context->x_Auto773+180) ) 
	&&  ( my >= (_Context->y_Auto773+500) ) 
	&&  ( mx <= (_Context->x_Auto773+180+120) ) 
	&&  ( my <= (_Context->y_Auto773+500+30))) {
		return(4); /* Find */
		}
	if (( mx >= (_Context->x_Auto773+320) ) 
	&&  ( my >= (_Context->y_Auto773+510) ) 
	&&  ( mx <= (_Context->x_Auto773+320+70) ) 
	&&  ( my <= (_Context->y_Auto773+510+32))) {
		return(5); /* InfoSelector */
		}
	if (( mx >= (_Context->x_Auto773+400) ) 
	&&  ( my >= (_Context->y_Auto773+500) ) 
	&&  ( mx <= (_Context->x_Auto773+400+110) ) 
	&&  ( my <= (_Context->y_Auto773+500+30))) {
		return(6); /* Delete */
		}
	if (( mx >= (_Context->x_Auto773+540) ) 
	&&  ( my >= (_Context->y_Auto773+500) ) 
	&&  ( mx <= (_Context->x_Auto773+540+110) ) 
	&&  ( my <= (_Context->y_Auto773+500+30))) {
		return(7); /* Cancel */
		}
	if (( mx >= (_Context->x_Auto773+20+0) ) 
	&&  ( my >= (_Context->y_Auto773+460) ) 
	&&  ( mx <= (_Context->x_Auto773+20+120) ) 
	&&  ( my <= (_Context->y_Auto773+460+16))) {
		return(8); /* FileType */
		}
	if (( mx >= (_Context->x_Auto773+20) ) 
	&&  ( my >= (_Context->y_Auto773+410) ) 
	&&  ( mx <= (_Context->x_Auto773+20+630) ) 
	&&  ( my <= (_Context->y_Auto773+410+20))) {
		return(9); /* Path */
		}
	if (( mx >= (_Context->x_Auto773+180) ) 
	&&  ( my >= (_Context->y_Auto773+460) ) 
	&&  ( mx <= (_Context->x_Auto773+180+470) ) 
	&&  ( my <= (_Context->y_Auto773+460+20))) {
		return(10); /* FileSelection */
		}
	if (( mx >= (_Context->x_Auto773+650) ) 
	&&  ( my >= (_Context->y_Auto773+80) ) 
	&&  ( mx <= (_Context->x_Auto773+650+20) ) 
	&&  ( my <= (_Context->y_Auto773+80+300))) {
		return(11); /* Slider */
		}
	if (( mx >= (_Context->x_Auto773+20) ) 
	&&  ( my >= (_Context->y_Auto773+80) ) 
	&&  ( mx <= (_Context->x_Auto773+20+630) ) 
	&&  ( my <= (_Context->y_Auto773+80+300))) {
		if ((_Context->value_FileNames = ((visual_event(6) - (_Context->y_Auto773+80)) / 16)) < 1)
			_Context->value_FileNames=0;
else if (_Context->value_FileNames > 17 )
			_Context->value_FileNames=17;
		if ( _Context->value_FileNames > 0 ) { _Context->row_FileNames = &_Context->buffer_FileNames[(_Context->value_FileNames-1)][0]; } 
		_Context->column_FileNames = (visual_event(7) - (_Context->x_Auto773+20));
		if ( _Context->column_FileNames < 161 ) {
			_Context->column_FileNames = 1;
			}
		else if ( _Context->column_FileNames < 322 ) {
			_Context->column_FileNames = 2;
			}
		else if ( _Context->column_FileNames < 475 ) {
			_Context->column_FileNames = 3;
			}
		else if ( _Context->column_FileNames < 628 ) {
			_Context->column_FileNames = 4;
			}
		return(12); /* FileNames */
		}
	if (( mx >= (_Context->x_Auto773+20) ) 
	&&  ( my >= (_Context->y_Auto773+80) ) 
	&&  ( mx <= (_Context->x_Auto773+20+630) ) 
	&&  ( my <= (_Context->y_Auto773+80+300))) {
		if ((_Context->value_FileInfos = ((visual_event(6) - (_Context->y_Auto773+80)) / 16)) < 1)
			_Context->value_FileInfos=0;
else if (_Context->value_FileInfos > 17 )
			_Context->value_FileInfos=17;
		if ( _Context->value_FileInfos > 0 ) { _Context->row_FileInfos = &_Context->buffer_FileInfos[(_Context->value_FileInfos-1)][0]; } 
		_Context->column_FileInfos = (visual_event(7) - (_Context->x_Auto773+20));
		if ( _Context->column_FileInfos < 161 ) {
			_Context->column_FileInfos = 1;
			}
		else if ( _Context->column_FileInfos < 322 ) {
			_Context->column_FileInfos = 2;
			}
		else if ( _Context->column_FileInfos < 475 ) {
			_Context->column_FileInfos = 3;
			}
		else if ( _Context->column_FileInfos < 628 ) {
			_Context->column_FileInfos = 4;
			}
		return(13); /* FileInfos */
		}

	return(-1);
}
private int on_FileType_losefocus(struct file_selector_context * _Context) {
	get_widget_filename(
	_Context->buffer_FileSelection,58,
	_Context->value_FileType,
	_Context->buffer_Path,78);
		file_selector_show(_Context);
;
	return(-1);
}
private int on_Path_losefocus(struct file_selector_context * _Context) {
	get_widget_filename(_Context->buffer_FileSelection,58,
	_Context->value_FileType,_Context->buffer_Path,78);
		file_selector_show(_Context);
;
	return(-1);
}


public	int	file_selector_focus(struct file_selector_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Result */
				_Context->keycode = visual_edit(_Context->x_Auto773+20+1,_Context->y_Auto773+50+1,630,20,vfh[1],_Context->buffer_Result,78);
			break;
			case	0x3 :
				/* Accept */
				visual_button(_Context->x_Auto773+20,_Context->y_Auto773+500,120,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto773+20,_Context->y_Auto773+500,120,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x4 :
				/* Find */
				visual_button(_Context->x_Auto773+180,_Context->y_Auto773+500,120,30,vfh[2],27,0,_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto773+180,_Context->y_Auto773+500,120,30,vfh[2],27,0,_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]),0);
				break;
			case	0x5 :
				/* InfoSelector */
				visual_switch(_Context->x_Auto773+320,_Context->y_Auto773+510,70,32,vfh[2],12,31,_Context->msg_InfoSelector[_Context->language],strlen(_Context->msg_InfoSelector[_Context->language]),(_Context->value_InfoSelector | 2 | 0x0030 ));
				_Context->keycode = visual_getch();
				visual_switch(_Context->x_Auto773+320,_Context->y_Auto773+510,70,32,vfh[2],12,31,_Context->msg_InfoSelector[_Context->language],strlen(_Context->msg_InfoSelector[_Context->language]),(_Context->value_InfoSelector | 0 | 0x0030 ));
				break;
			case	0x6 :
				/* Delete */
				visual_button(_Context->x_Auto773+400,_Context->y_Auto773+500,110,30,vfh[2],27,0,_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto773+400,_Context->y_Auto773+500,110,30,vfh[2],27,0,_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]),0);
				break;
			case	0x7 :
				/* Cancel */
				visual_button(_Context->x_Auto773+540,_Context->y_Auto773+500,110,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto773+540,_Context->y_Auto773+500,110,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0x8 :
				/* FileType */
				_Context->keycode = visual_select(_Context->x_Auto773+20,_Context->y_Auto773+460,120,70,vfh[1],27,0,parse_selection(WidgetFileNames,&_Context->value_FileType),2);
				(void) on_FileType_losefocus(_Context);
				break;
			case	0x9 :
				/* Path */
				_Context->keycode = visual_edit(_Context->x_Auto773+20+1,_Context->y_Auto773+410+1,630,20,vfh[1],_Context->buffer_Path,78);
				(void) on_Path_losefocus(_Context);
			break;
			case	0xa :
				/* FileSelection */
				_Context->keycode = visual_edit(_Context->x_Auto773+180+1,_Context->y_Auto773+460+1,470,20,vfh[1],_Context->buffer_FileSelection,58);
			break;
			case	0xc :
				/* FileNames */
	_Context->keycode = visual_getch();
				if ( _Context->keycode == 9 ) {
					_Context->column_FileNames++;
					if ( _Context->column_FileNames > 0 ) {
						_Context->column_FileNames=1;
						_Context->value_FileNames++;
						if ( _Context->value_FileNames > 0 ) {
							_Context->value_FileNames=1;
							}
						}
					_Context->keycode=0;
					}
			break;
			case	0xd :
				/* FileInfos */
	_Context->keycode = visual_getch();
				if ( _Context->keycode == 9 ) {
					_Context->column_FileInfos++;
					if ( _Context->column_FileInfos > 0 ) {
						_Context->column_FileInfos=1;
						_Context->value_FileInfos++;
						if ( _Context->value_FileInfos > 0 ) {
							_Context->value_FileInfos=1;
							}
						}
					_Context->keycode=0;
					}
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			file_selector_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=13;
			file_selector_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=file_selector_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto773 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Result */
						continue;
					case	0x3 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto773+20,_Context->y_Auto773+500,120,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto773+20,_Context->y_Auto773+500,120,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Find */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto773+180,_Context->y_Auto773+500,120,30,vfh[2],27,0,_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto773+180,_Context->y_Auto773+500,120,30,vfh[2],27,0,_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Find_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* InfoSelector */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_InfoSelector += 1;
							_Context->value_InfoSelector &= 1;
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_InfoSelector_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* Delete */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto773+400,_Context->y_Auto773+500,110,30,vfh[2],27,0,_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto773+400,_Context->y_Auto773+500,110,30,vfh[2],27,0,_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Delete_event(_Context)) != -1) break;

							}
						continue;
					case	0x7 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto773+540,_Context->y_Auto773+500,110,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto773+540,_Context->y_Auto773+500,110,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0x8 :
						/* FileType */
						continue;
					case	0x9 :
						/* Path */
						continue;
					case	0xa :
						/* FileSelection */
						continue;
					case	0xb :
						/* Slider */
						(void) on_Slider_action(_Context);
						continue;
					case	0xc :
						/* FileNames */
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FileNames_event(_Context)) != -1) break;

							}
						continue;
					case	0xd :
						/* FileInfos */
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FileInfos_event(_Context)) != -1) break;

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

public	int	file_selector(
	char * pResult,
	char * pFileType,
	char * pPath,
	char * pFileSelection)
{
	int	status=0;
	struct file_selector_context * _Context=(struct file_selector_context*) 0;
	status = file_selector_create(
	&_Context,
	 pResult,
	 pFileType,
	 pPath,
	 pFileSelection);
	if ( status != 0) return(status);
	status = file_selector_show(_Context);
		enter_modal();
	status = file_selector_focus(_Context);
		leave_modal();
	status = file_selector_hide(_Context);
	status = file_selector_remove(
	_Context,
	 pResult,
	 pFileType,
	 pPath,
	 pFileSelection);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vfselect_c */
