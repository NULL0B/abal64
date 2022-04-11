
#ifndef _vfselect_c
#define _vfselect_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vfselect.sng  */
/* Target         : vfselect.c  */
/* Identification : 0.0-1065019114-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct file_selector_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_Result[79];
	int	value_InfoSelector;
	int	value_FileType;
	char	buffer_Path[79];
	char	buffer_FileSelection[59];
	int	value_Slider;
	int	limit_Slider;
	int	max_Slider;
	int	value_FileNames;
	int	column_FileNames;
	char	buffer_FileNames[17][78];
	char * row_FileNames;
	int	value_FileInfos;
	int	column_FileInfos;
	char	buffer_FileInfos[17][78];
	char * row_FileInfos;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[5];
	} * _Context;
private int on_FileSelection_create() {
	get_widget_filename(_Context->buffer_FileSelection,58,_Context->value_FileType,
	_Context->buffer_Path,78);
	return(-1);
}
private int on_Slider_create() {
	_Context->value_Slider=0;
	_Context->limit_Slider=(17*4);
	_Context->max_Slider=0;
	return(-1);
}
private int on_FileNames_create() {
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
private int on_FileInfos_create() {
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

private	int	file_selector_create(
	char * pResult,
	char * pInfoSelector,
	char * pFileType,
	char * pPath,
	char * pFileSelection)
{

	if (!(_Context = allocate( sizeof( struct file_selector_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=13;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Result, 78, pResult);
		visual_transferin((void *) 0, 0, pInfoSelector);
		if (!( pInfoSelector )) _Context->value_InfoSelector=0;
		else	_Context->value_InfoSelector = *((int *)pInfoSelector);
		visual_transferin((void *) 0, 0, pFileType);
		if (!( pFileType )) _Context->value_FileType=0;
		else	_Context->value_FileType = *((int *)pFileType);
		visual_transferin(_Context->buffer_Path, 78, pPath);
		visual_transferin(_Context->buffer_FileSelection, 58, pFileSelection);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->value_InfoSelector=0;
	(void) on_FileSelection_create();
	_Context->max_Slider=1;
	_Context->value_Slider=1;
	_Context->limit_Slider=1;
	(void) on_Slider_create();
	if ( 0 > 0 ) { _Context->row_FileNames=&_Context->buffer_FileNames[0-1][0]; } ;
	(void) on_FileNames_create();
	if ( 0 > 0 ) { _Context->row_FileInfos=&_Context->buffer_FileInfos[0-1][0]; } ;
	(void) on_FileInfos_create();
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(60,25,680+10,550+10);
	return(0);
}

private	int	file_selector_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,60,25);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	file_selector_remove(
	char * pResult,
	char * pInfoSelector,
	char * pFileType,
	char * pPath,
	char * pFileSelection)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Result, 78, pResult);
		visual_transferout((void *) 0, 0, pInfoSelector);
		if ( pInfoSelector != (char *) 0)
			*((int*)pInfoSelector) = _Context->value_InfoSelector;
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
private int on_FileNames_show() {
	if(!(_Context->value_InfoSelector)){
		visual_table(80,105,630+2,300+2,1,27,0,"-|-|-|-",_Context->buffer_FileNames,0x0401,(char*) 0);

	}
	else{
		visual_table(80,105,630+2,300+2,1,27,0,"Name|Size|Time|Date",_Context->buffer_FileInfos,0x0401,(char*) 0);
;
	}
	return(-1);
}
private int on_FileInfos_show() {
	if(_Context->value_InfoSelector!=0){
		visual_table(80,105,630+2,300+2,1,27,0,"Name|Size|Time|Date",_Context->buffer_FileInfos,0x0401,(char*) 0);
;
	}
	else{
		visual_table(80,105,630+2,300+2,1,27,0,"-|-|-|-",_Context->buffer_FileNames,0x0401,(char*) 0);
;
	}
	return(-1);
}

private	int	file_selector_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,60,25);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(60,25,680,550,2,"Sing : Version 1.0a : File Selector",35,0x403);
	visual_image(62,45,673,526,"skin.gif",4);
	visual_text(80,415,490,20,2,27,0,"Current Directory Path",22,258);
	visual_text(80,55,630,16,2,27,0,"Selected Filename(s)",20,258);
	visual_frame(80,75,630+2,20+2,5);
	visual_text(80+1,75+1,630,20,1,27,0,_Context->buffer_Result,78,0);
	visual_text(240,465,470,20,2,27,0,"File Selection Criteria",23,258);
	visual_text(80,465,120,20,2,27,0,"File Type",9,258);
	visual_button(80,525,120,30,2,27,0,"&Accept",7,0);
	visual_button(240,525,120,30,2,27,0,"&Find",5,0);
	visual_switch(380,535,70,32,2,12,31,"Infos",5,_Context->value_InfoSelector);
	visual_button(460,525,110,30,2,27,0,"&Delete",7,0);
	visual_button(600,525,110,30,2,27,0,"&Cancel",7,0);
	visual_select(80,485,120,70,1,27,0,parse_selection(WidgetFileNames,&_Context->value_FileType),0);
	visual_frame(80,435,630+2,20+2,5);
	visual_text(80+1,435+1,630,20,1,0,0,_Context->buffer_Path,78,0);
	visual_frame(240,485,470+2,20+2,5);
	visual_text(240+1,485+1,470,20,1,27,0,_Context->buffer_FileSelection,58,0);
	visual_scrollbar(710,105,20,300,1,0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,3);
	(void) on_FileNames_show();
	(void) on_FileInfos_show();
	visual_thaw(60,25,680,550);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Find_event() {
	on_Path_losefocus();
	on_Slider_create();
	on_FileNames_create();
	file_selector_show();
	return(-1);
}
private int on_InfoSelector_event() {
	_Context->value_Slider=0;
	on_Slider_event();
	return(-1);
}
private int on_Delete_event() {
	delete_system_file(_Context->buffer_FileSelection,58);
	on_Find_event();
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}
private int on_Slider_event() {
	if(!(_Context->value_InfoSelector)){
	on_FileNames_create();
	}
	else{
	on_FileInfos_create();
	}
	file_selector_show();
	return(-1);
}

private int on_Slider_action() {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (105+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Slider -= 1;
		if (_Context->value_Slider < 0) 
			_Context->value_Slider = 0;
		(void) on_Slider_event();
	visual_scrollbar(710,105,20,300,1,0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
		return(-1);
		}
	if ( visual_event(6) > (105+300-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Slider += 1;
		if (_Context->value_Slider > (_Context->max_Slider-_Context->limit_Slider)) 
			_Context->value_Slider = (_Context->max_Slider-_Context->limit_Slider);
		(void) on_Slider_event();
	visual_scrollbar(710,105,20,300,1,0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
		return(-1);
		}
	visual_scrollbar(710,105,20,300,1,0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);

	do {
		while(visual_getch() != 256);
		aty = _Context->value_Slider;
		_Context->value_Slider = (((visual_event(6) - (105+20)) * _Context->max_Slider) / (300 - (2 * 20)));
		if (_Context->value_Slider < 0) 
			_Context->value_Slider = 0;
		else if (_Context->value_Slider > (_Context->max_Slider-_Context->limit_Slider)) 
			_Context->value_Slider = (_Context->max_Slider-_Context->limit_Slider);
		if (_Context->value_Slider != aty) {
		(void) on_Slider_event();
	visual_scrollbar(710,105,20,300,1,0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
			}

		}
	while (visual_event(1) != _MIMO_UP);	visual_scrollbar(710,105,20,300,1,0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,3);

	return(1);
}
private int on_FileNames_event() {
	int r;
	if(_Context->value_InfoSelector!=0){
	if(!(r=_Context->value_FileNames))
	return;
	else{
	_Context->value_FileInfos=r;
	on_FileInfos_event();
	}
	}
	else{
	if(!(r=_Context->value_FileNames))
	return;
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
	on_Find_event();
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
	on_Find_event();
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
	on_Find_event();
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
	on_Find_event();
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
	file_selector_show();
	}
	return(-1);
}
private int on_FileInfos_event() {
	int r;
	if(!(_Context->value_InfoSelector!=0)){
	on_FileNames_event();
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
	on_Find_event();
	}
	}
	else{
	fnaddfile(
	_Context->buffer_Result,78,
	_Context->buffer_Path,78,
	(_Context->row_FileInfos+0),20);
	}
	}
	file_selector_show();
	return(-1);
}


private	int	file_selector_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 719 )  
	&&  (my >= 29 )  
	&&  (mx <= 735 )  
	&&  (my <= 45 )) {
		return(1);	/* Auto773 */

		}
	if ((mx >= 703 )  
	&&  (my >= 29 )  
	&&  (mx <= 719 )  
	&&  (my <= 45 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vfselect.htm");
			};
		return(-1);	/* Auto773 */

		}
	if (( mx >= 80 ) 
	&&  ( my >= 75 ) 
	&&  ( mx <= 710 ) 
	&&  ( my <= 95 )) {
		return(2); /* Result */
		}
	if (( mx >= 80 ) 
	&&  ( my >= 525 ) 
	&&  ( mx <= 200 ) 
	&&  ( my <= 555 )) {
		return(3); /* Accept */
		}
	if (( mx >= 240 ) 
	&&  ( my >= 525 ) 
	&&  ( mx <= 360 ) 
	&&  ( my <= 555 )) {
		return(4); /* Find */
		}
	if (( mx >= 380 ) 
	&&  ( my >= 535 ) 
	&&  ( mx <= 450 ) 
	&&  ( my <= 567 )) {
		return(5); /* InfoSelector */
		}
	if (( mx >= 460 ) 
	&&  ( my >= 525 ) 
	&&  ( mx <= 570 ) 
	&&  ( my <= 555 )) {
		return(6); /* Delete */
		}
	if (( mx >= 600 ) 
	&&  ( my >= 525 ) 
	&&  ( mx <= 710 ) 
	&&  ( my <= 555 )) {
		return(7); /* Cancel */
		}
	if ((mx >= 80 ) 
	&&  (my >= 485 ) 
	&&  (mx <= 200 ) 
	&&  (my <= 501 )) {
		return(8); /* FileType */
		}
	if (( mx >= 80 ) 
	&&  ( my >= 435 ) 
	&&  ( mx <= 710 ) 
	&&  ( my <= 455 )) {
		return(9); /* Path */
		}
	if (( mx >= 240 ) 
	&&  ( my >= 485 ) 
	&&  ( mx <= 710 ) 
	&&  ( my <= 505 )) {
		return(10); /* FileSelection */
		}
	if (( mx >= 710 ) 
	&&  ( my >= 105 ) 
	&&  ( mx <= 730 ) 
	&&  ( my <= 405 )) {
		return(11); /* Slider */
		}
	if (( mx >= 80 ) 
	&&  ( my >= 105 ) 
	&&  ( mx <= 710 ) 
	&&  ( my <= 405 )) {
		if ((_Context->value_FileNames = ((visual_event(6) - 105) / 16)) < 1)
			_Context->value_FileNames=0;
else if (_Context->value_FileNames > 17 )
			_Context->value_FileNames=17;
		if ( _Context->value_FileNames > 0 ) { _Context->row_FileNames = &_Context->buffer_FileNames[(_Context->value_FileNames-1)][0]; } 
		_Context->column_FileNames = (visual_event(7) - 80);
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
	if (( mx >= 80 ) 
	&&  ( my >= 105 ) 
	&&  ( mx <= 710 ) 
	&&  ( my <= 405 )) {
		if ((_Context->value_FileInfos = ((visual_event(6) - 105) / 16)) < 1)
			_Context->value_FileInfos=0;
else if (_Context->value_FileInfos > 17 )
			_Context->value_FileInfos=17;
		if ( _Context->value_FileInfos > 0 ) { _Context->row_FileInfos = &_Context->buffer_FileInfos[(_Context->value_FileInfos-1)][0]; } 
		_Context->column_FileInfos = (visual_event(7) - 80);
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
private int on_FileType_losefocus() {
	get_widget_filename(
	_Context->buffer_FileSelection,58,
	_Context->value_FileType,
	_Context->buffer_Path,78);
	file_selector_show();
	return(-1);
}
private int on_Path_losefocus() {
	get_widget_filename(_Context->buffer_FileSelection,58,
	_Context->value_FileType,_Context->buffer_Path,78);
	file_selector_show();
	return(-1);
}


private	int	file_selector_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Result */
				_Context->keycode = visual_edit(80+1,75+1,630,20,1,_Context->buffer_Result,78);
				break;
			case	0x3 :
				/* Accept */
				visual_button(80,525,120,30,2,27,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(80,525,120,30,2,27,0,"&Accept",7,0);
				break;
			case	0x4 :
				/* Find */
				visual_button(240,525,120,30,2,27,0,"&Find",5,2);
				_Context->keycode = visual_getch();
				visual_button(240,525,120,30,2,27,0,"&Find",5,0);
				break;
			case	0x5 :
				/* InfoSelector */
				visual_switch(380,535,70,32,2,12,31,"Infos",5,(_Context->value_InfoSelector |2));
				_Context->keycode = visual_getch();
				visual_switch(380,535,70,32,2,12,31,"Infos",5,(_Context->value_InfoSelector |0));
				break;
			case	0x6 :
				/* Delete */
				visual_button(460,525,110,30,2,27,0,"&Delete",7,2);
				_Context->keycode = visual_getch();
				visual_button(460,525,110,30,2,27,0,"&Delete",7,0);
				break;
			case	0x7 :
				/* Cancel */
				visual_button(600,525,110,30,2,27,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(600,525,110,30,2,27,0,"&Cancel",7,0);
				break;
			case	0x8 :
				/* FileType */
				_Context->keycode = visual_select(80,485,120,70,1,27,0,parse_selection(WidgetFileNames,&_Context->value_FileType),2);
				(void) on_FileType_losefocus();
				break;
			case	0x9 :
				/* Path */
				_Context->keycode = visual_edit(80+1,435+1,630,20,1,_Context->buffer_Path,78);
				(void) on_Path_losefocus();
				break;
			case	0xa :
				/* FileSelection */
				_Context->keycode = visual_edit(240+1,485+1,470,20,1,_Context->buffer_FileSelection,58);
				break;
	_Context->keycode = visual_getch();
	_Context->keycode = visual_getch();

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			file_selector_show();
			continue;
		case	0x2 :
			_Context->focus_item=13;
			file_selector_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=file_selector_event()) == -1)
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
							visual_button(80,525,120,30,2,27,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(80,525,120,30,2,27,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* Find */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(240,525,120,30,2,27,0,"&Find",5,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(240,525,120,30,2,27,0,"&Find",5,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Find_event()) != -1) break;

							}
						continue;
					case	0x5 :
						/* InfoSelector */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_InfoSelector += 1;
							_Context->value_InfoSelector &= 1;
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_InfoSelector_event()) != -1) break;

							}
						continue;
					case	0x6 :
						/* Delete */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(460,525,110,30,2,27,0,"&Delete",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(460,525,110,30,2,27,0,"&Delete",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Delete_event()) != -1) break;

							}
						continue;
					case	0x7 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(600,525,110,30,2,27,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(600,525,110,30,2,27,0,"&Cancel",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

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
						(void) on_Slider_action();
						continue;
					case	0xc :
						/* FileNames */
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FileNames_event()) != -1) break;

							}
						continue;
					case	0xd :
						/* FileInfos */
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FileInfos_event()) != -1) break;

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
		case 0x841 : 
		case 0x861 : 
		/* Accept */
		visual_button(80,525,120,30,2,27,0,"&Accept",7,8);
		visual_button(80,525,120,30,2,27,0,"&Accept",7,0);
		_Context->focus_item=3;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x846 : 
		case 0x866 : 
		/* Find */
		visual_button(240,525,120,30,2,27,0,"&Find",5,8);
		visual_button(240,525,120,30,2,27,0,"&Find",5,0);
		_Context->focus_item=4;
		if ((_Context->keycode = on_Find_event()) != -1) break;
		continue;
		case 0x844 : 
		case 0x864 : 
		/* Delete */
		visual_button(460,525,110,30,2,27,0,"&Delete",7,8);
		visual_button(460,525,110,30,2,27,0,"&Delete",7,0);
		_Context->focus_item=6;
		if ((_Context->keycode = on_Delete_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(600,525,110,30,2,27,0,"&Cancel",7,8);
		visual_button(600,525,110,30,2,27,0,"&Cancel",7,0);
		_Context->focus_item=7;
		if ((_Context->keycode = on_Cancel_event()) != -1) break;
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
	char * pInfoSelector,
	char * pFileType,
	char * pPath,
	char * pFileSelection)
{
	int	status=0;
	status = file_selector_create(
	 pResult,
	 pInfoSelector,
	 pFileType,
	 pPath,
	 pFileSelection);
	if ( status != 0) return(status);
	status = file_selector_show();
		enter_modal();
	status = file_selector_focus();
		leave_modal();
	status = file_selector_hide();
	status = file_selector_remove(
	 pResult,
	 pInfoSelector,
	 pFileType,
	 pPath,
	 pFileSelection);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vfselect_c */
