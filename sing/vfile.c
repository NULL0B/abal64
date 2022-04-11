
#ifndef _vfile_c
#define _vfile_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vfile.sng  */
/* Target         : vfile.c  */
/* Identification : 0.0-1065019114-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_file_properties_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	focus_pages[3+1];
	int	page_number;
	char	buffer_FileClass[68];
	char	buffer_Handle[16];
	char	buffer_FileName[53];
	int	value_FileType;
	char	buffer_ProductionTarget[39];
	char	buffer_Dependance[153];
	char	buffer_RecordClass[68];
	char	buffer_RecordSize[27];
	int	value_IsVariable;
	int	value_DataForm;
	int	value_Align;
	char	buffer_IndexClass[68];
	char	buffer_IndexSize[24];
	int	value_IndexForm;
	char	signature[15];
	} * _Context;

private	int	accept_file_properties_create(
	char * pFileClass,
	char * pHandle,
	char * pFileName,
	char * pFileType,
	char * pProductionTarget,
	char * pDependance,
	char * pRecordClass,
	char * pRecordSize,
	char * pIsVariable,
	char * pDataForm,
	char * pAlign,
	char * pIndexClass,
	char * pIndexSize,
	char * pIndexForm)
{

	if (!(_Context = allocate( sizeof( struct accept_file_properties_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=22;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWSWSSSWWWWSWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileClass, 67, pFileClass);
		visual_transferin(_Context->buffer_Handle, 15, pHandle);
		visual_transferin(_Context->buffer_FileName, 52, pFileName);
		visual_transferin((void *) 0, 0, pFileType);
		if (!( pFileType )) _Context->value_FileType=0;
		else	_Context->value_FileType = *((int *)pFileType);
		visual_transferin(_Context->buffer_ProductionTarget, 38, pProductionTarget);
		visual_transferin(_Context->buffer_Dependance, 152, pDependance);
		visual_transferin(_Context->buffer_RecordClass, 67, pRecordClass);
		visual_transferin(_Context->buffer_RecordSize, 26, pRecordSize);
		visual_transferin((void *) 0, 0, pIsVariable);
		if (!( pIsVariable )) _Context->value_IsVariable=0;
		else	_Context->value_IsVariable = *((int *)pIsVariable);
		visual_transferin((void *) 0, 0, pDataForm);
		if (!( pDataForm )) _Context->value_DataForm=0;
		else	_Context->value_DataForm = *((int *)pDataForm);
		visual_transferin((void *) 0, 0, pAlign);
		if (!( pAlign )) _Context->value_Align=0;
		else	_Context->value_Align = *((int *)pAlign);
		visual_transferin(_Context->buffer_IndexClass, 67, pIndexClass);
		visual_transferin(_Context->buffer_IndexSize, 23, pIndexSize);
		visual_transferin((void *) 0, 0, pIndexForm);
		if (!( pIndexForm )) _Context->value_IndexForm=0;
		else	_Context->value_IndexForm = *((int *)pIndexForm);
		}
	_Context->window_col=40;
	_Context->window_row=40;
	_Context->focus_pages[1]=3;
	_Context->focus_pages[2]=10;
	_Context->focus_pages[3]=15;
	return(0);
}

private	int	accept_file_properties_hide()
{

	return(0);
}

private	int	accept_file_properties_remove(
	char * pFileClass,
	char * pHandle,
	char * pFileName,
	char * pFileType,
	char * pProductionTarget,
	char * pDependance,
	char * pRecordClass,
	char * pRecordSize,
	char * pIsVariable,
	char * pDataForm,
	char * pAlign,
	char * pIndexClass,
	char * pIndexSize,
	char * pIndexForm)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWSWSSSWWWWSWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileClass, 67, pFileClass);
		visual_transferout(_Context->buffer_Handle, 15, pHandle);
		visual_transferout(_Context->buffer_FileName, 52, pFileName);
		visual_transferout((void *) 0, 0, pFileType);
		if ( pFileType != (char *) 0)
			*((int*)pFileType) = _Context->value_FileType;
		visual_transferout(_Context->buffer_ProductionTarget, 38, pProductionTarget);
		visual_transferout(_Context->buffer_Dependance, 152, pDependance);
		visual_transferout(_Context->buffer_RecordClass, 67, pRecordClass);
		visual_transferout(_Context->buffer_RecordSize, 26, pRecordSize);
		visual_transferout((void *) 0, 0, pIsVariable);
		if ( pIsVariable != (char *) 0)
			*((int*)pIsVariable) = _Context->value_IsVariable;
		visual_transferout((void *) 0, 0, pDataForm);
		if ( pDataForm != (char *) 0)
			*((int*)pDataForm) = _Context->value_DataForm;
		visual_transferout((void *) 0, 0, pAlign);
		if ( pAlign != (char *) 0)
			*((int*)pAlign) = _Context->value_Align;
		visual_transferout(_Context->buffer_IndexClass, 67, pIndexClass);
		visual_transferout(_Context->buffer_IndexSize, 23, pIndexSize);
		visual_transferout((void *) 0, 0, pIndexForm);
		if ( pIndexForm != (char *) 0)
			*((int*)pIndexForm) = _Context->value_IndexForm;
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_file_properties_show()
{
	visual_freeze();
	visual_window(100,95,600,410,2,"Sing : Version 1.0a : File Properties",37,0x0);
	visual_frame(110,125,580,370,2);
	visual_button(450,455,110,30,2,27,0,"Select Class",12,0);
	if (_Context->page_number == 1 ) {
	visual_tabpage(120,135,560,310,1,"File",4,0,2);
	} else {
		visual_tabpage(120,135,560,310,1,"File",4,0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(130,175,180,20,2,27,0,"Identifier",10,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(130,225,98,16,2,27,0,"Number",6,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(130,195,540+2,16+2,5);
	visual_text(130+1,195+1,540,16,1,27,0,_Context->buffer_FileClass,67,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(130,295,238,16,2,27,0,"Production Target",17,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(130,345,182,16,2,27,0,"Dependance",10,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(250,225,120+2,16+2,5);
	visual_text(250+1,225+1,120,16,1,27,0,_Context->buffer_Handle,15,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(130,265,168,16,2,27,0,"Filename",8,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(390,225,140,16,2,27,0,"Filetype",8,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(250,265,420+2,16+2,5);
	visual_text(250+1,265+1,420,16,1,27,0,_Context->buffer_FileName,52,0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(460,225,210,60,1,27,0,parse_selection("AD+SQ+SI+MC+BD",&_Context->value_FileType),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(130,315,540+2,16+2,5);
	visual_text(130+1,315+1,540,16,2,27,0,_Context->buffer_ProductionTarget,38,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(130,365,540+2,70+2,5);
	visual_text(130+1,365+1,540,70,2,27,0,_Context->buffer_Dependance,152,0);
		}
	if (_Context->page_number == 2 ) {
	visual_tabpage(120,135,560,310,1,"Data",4,49,2);
	} else {
		visual_tabpage(120,135,560,310,1,"Data",4,49,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(130,175,528,16,2,27,0,"File Data Record Description",28,0);
		}
	if (_Context->page_number == 2 ) {
	visual_line(130,195,670,195,1,27);
		}
	if (_Context->page_number == 2 ) {
	visual_text(130,235,260,20,2,27,0,"Data Record Class",17,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(130,325,264,16,2,27,0,"Data Record Size",16,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(130,265,540+2,16+2,5);
	visual_text(130+1,265+1,540,16,1,27,0,_Context->buffer_RecordClass,67,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(250,325,210+2,16+2,5);
	visual_text(250+1,325+1,210,16,1,27,0,_Context->buffer_RecordSize,26,0);
		}
	if (_Context->page_number == 2 ) {
	visual_check(480,325,176,32,2,27,0,"Variable Length",15,_Context->value_IsVariable|0);
		}
	if (_Context->page_number == 2 ) {
	visual_check(481,369,151,20,2,175,0,"Generate Form",13,_Context->value_DataForm|0);
		}
	if (_Context->page_number == 3 ) {
	visual_tabpage(120,135,560,310,1,"Index",5,98,2);
	} else {
		visual_tabpage(120,135,560,310,1,"Index",5,98,0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(130,175,532,16,2,27,0,"File Primary Index Description",30,0);
		}
	if (_Context->page_number == 3 ) {
	visual_line(130,195,660,195,1,27);
		}
	if (_Context->page_number == 3 ) {
	visual_text(130,235,290,20,2,27,0,"Primary Index Class ",20,0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(130,325,290,20,2,27,0,"Primary Index Size  ",20,0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(130,385,230,20,2,27,0,"Index Alignment ",16,0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(280,385,350,50,2,27,0,parse_selection("none+align left+align right",&_Context->value_Align),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(130,265,540+2,16+2,5);
	visual_text(130+1,265+1,540,16,1,27,0,_Context->buffer_IndexClass,67,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(280,325,186+2,16+2,5);
	visual_text(280+1,325+1,186,16,1,27,0,_Context->buffer_IndexSize,23,0);
		}
	if (_Context->page_number == 3 ) {
	visual_check(484,325,168,28,2,175,0,"Generate Form",13,_Context->value_IndexForm|0);
		}
	visual_button(569,453,110,30,2,27,0,"Cancel",6,0);
	visual_button(120,455,110,30,2,27,0,"Accept",6,0);
	visual_button(240,455,110,30,2,26,0,"Edit",4,0);
	visual_thaw(100,95,600,410);

	return(0);
}
private int on_ChooseClass_event() {
	switch(_Context->page_number){
	case 1:select_classname(_Context->buffer_FileClass);break;
	case 2:select_classname(_Context->buffer_RecordClass);break;
	case 3:select_classname(_Context->buffer_IndexClass);break;
	}
	accept_file_properties_show();
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Edit_event() {
	perform_editor(_Context->buffer_ProductionTarget);
	accept_file_properties_show();
	return(-1);
}


private	int	accept_file_properties_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 450 ) 
	&&  ( my >= 455 ) 
	&&  ( mx <= 560 ) 
	&&  ( my <= 485 )) {
		return(2); /* ChooseClass */
		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 120 ) 
		&&  (my >= 135 ) 
		&&  (mx <= 168 ) 
		&&  (my <= 159 )) {
			return(3); /* FilePage */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 130 ) 
		&&  ( my >= 195 ) 
		&&  ( mx <= 670 ) 
		&&  ( my <= 211 )) {
			return(4); /* FileClass */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 250 ) 
		&&  ( my >= 225 ) 
		&&  ( mx <= 370 ) 
		&&  ( my <= 241 )) {
			return(5); /* Handle */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 250 ) 
		&&  ( my >= 265 ) 
		&&  ( mx <= 670 ) 
		&&  ( my <= 281 )) {
			return(6); /* FileName */
		}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 460 ) 
		&&  (my >= 225 ) 
		&&  (mx <= 670 ) 
		&&  (my <= 241 )) {
			return(7); /* FileType */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 130 ) 
		&&  ( my >= 315 ) 
		&&  ( mx <= 670 ) 
		&&  ( my <= 331 )) {
			return(8); /* ProductionTarget */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 130 ) 
		&&  ( my >= 365 ) 
		&&  ( mx <= 670 ) 
		&&  ( my <= 435 )) {
			return(9); /* Dependance */
		}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 169 ) 
		&&  (my >= 135 ) 
		&&  (mx <= 217 ) 
		&&  (my <= 159 )) {
			return(10); /* DataPage */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 130 ) 
		&&  ( my >= 265 ) 
		&&  ( mx <= 670 ) 
		&&  ( my <= 281 )) {
			return(11); /* RecordClass */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 250 ) 
		&&  ( my >= 325 ) 
		&&  ( mx <= 460 ) 
		&&  ( my <= 341 )) {
			return(12); /* RecordSize */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 480 ) 
		&&  ( my >= 325 ) 
		&&  ( mx <= 656 ) 
		&&  ( my <= 357 )) {
			return(13); /* IsVariable */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 481 ) 
		&&  ( my >= 369 ) 
		&&  ( mx <= 632 ) 
		&&  ( my <= 389 )) {
			return(14); /* DataForm */
		}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if ((mx >= 218 ) 
		&&  (my >= 135 ) 
		&&  (mx <= 274 ) 
		&&  (my <= 159 )) {
			return(15); /* IndexPage */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 280 ) 
		&&  (my >= 385 ) 
		&&  (mx <= 630 ) 
		&&  (my <= 401 )) {
			return(16); /* Align */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 130 ) 
		&&  ( my >= 265 ) 
		&&  ( mx <= 670 ) 
		&&  ( my <= 281 )) {
			return(17); /* IndexClass */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 280 ) 
		&&  ( my >= 325 ) 
		&&  ( mx <= 466 ) 
		&&  ( my <= 341 )) {
			return(18); /* IndexSize */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 484 ) 
		&&  ( my >= 325 ) 
		&&  ( mx <= 652 ) 
		&&  ( my <= 353 )) {
			return(19); /* IndexForm */
		}
		}
	if (( mx >= 569 ) 
	&&  ( my >= 453 ) 
	&&  ( mx <= 679 ) 
	&&  ( my <= 483 )) {
		return(20); /* Cancel */
		}
	if (( mx >= 120 ) 
	&&  ( my >= 455 ) 
	&&  ( mx <= 230 ) 
	&&  ( my <= 485 )) {
		return(21); /* Accept */
		}
	if (( mx >= 240 ) 
	&&  ( my >= 455 ) 
	&&  ( mx <= 350 ) 
	&&  ( my <= 485 )) {
		return(22); /* Edit */
		}

	return(-1);
}


private	int	accept_file_properties_losefocus()
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;
		case 3 : 
			break;

		}
	return(0);

}


private	int	accept_file_properties_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* ChooseClass */
				visual_button(450,455,110,30,2,27,0,"Select Class",12,2);
				_Context->keycode = visual_getch();
				visual_button(450,455,110,30,2,27,0,"Select Class",12,0);
				break;
			case	0x3 :
				/* FilePage */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x4 :
				/* FileClass */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(130+1,195+1,540,16,1,_Context->buffer_FileClass,67);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* Handle */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(250+1,225+1,120,16,1,_Context->buffer_Handle,15);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* FileName */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(250+1,265+1,420,16,1,_Context->buffer_FileName,52);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* FileType */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(460,225,210,60,1,27,0,parse_selection("AD+SQ+SI+MC+BD",&_Context->value_FileType),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* ProductionTarget */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(130+1,315+1,540,16,2,_Context->buffer_ProductionTarget,38);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* Dependance */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(130+1,365+1,540,70,2,_Context->buffer_Dependance,152);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* DataPage */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xb :
				/* RecordClass */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(130+1,265+1,540,16,1,_Context->buffer_RecordClass,67);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* RecordSize */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(250+1,325+1,210,16,1,_Context->buffer_RecordSize,26);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* IsVariable */
				if (_Context->page_number == 2 ) {
				visual_check(480,325,176,32,2,27,0,"Variable Length",15,(_Context->value_IsVariable |2));
					_Context->keycode = visual_getch();
				visual_check(480,325,176,32,2,27,0,"Variable Length",15,(_Context->value_IsVariable |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* DataForm */
				if (_Context->page_number == 2 ) {
				visual_check(481,369,151,20,2,175,0,"Generate Form",13,(_Context->value_DataForm |2));
					_Context->keycode = visual_getch();
				visual_check(481,369,151,20,2,175,0,"Generate Form",13,(_Context->value_DataForm |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* IndexPage */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x10 :
				/* Align */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(280,385,350,50,2,27,0,parse_selection("none+align left+align right",&_Context->value_Align),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* IndexClass */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(130+1,265+1,540,16,1,_Context->buffer_IndexClass,67);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* IndexSize */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(280+1,325+1,186,16,1,_Context->buffer_IndexSize,23);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* IndexForm */
				if (_Context->page_number == 3 ) {
				visual_check(484,325,168,28,2,175,0,"Generate Form",13,(_Context->value_IndexForm |2));
					_Context->keycode = visual_getch();
				visual_check(484,325,168,28,2,175,0,"Generate Form",13,(_Context->value_IndexForm |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* Cancel */
				visual_button(569,453,110,30,2,27,0,"Cancel",6,2);
				_Context->keycode = visual_getch();
				visual_button(569,453,110,30,2,27,0,"Cancel",6,0);
				break;
			case	0x15 :
				/* Accept */
				visual_button(120,455,110,30,2,27,0,"Accept",6,2);
				_Context->keycode = visual_getch();
				visual_button(120,455,110,30,2,27,0,"Accept",6,0);
				break;
			case	0x16 :
				/* Edit */
				visual_button(240,455,110,30,2,26,0,"Edit",4,2);
				_Context->keycode = visual_getch();
				visual_button(240,455,110,30,2,26,0,"Edit",4,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			accept_file_properties_losefocus();
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_file_properties_show();
			continue;
		case	0x2 :
			accept_file_properties_losefocus();
			_Context->page_number=3;
			_Context->focus_item=22;
			accept_file_properties_show();
			continue;
		case	0x3 :
			accept_file_properties_losefocus();
			if ( _Context->page_number < 3 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_file_properties_show();
			continue;
		case	0x12 :
			accept_file_properties_losefocus();
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_file_properties_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_file_properties_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto553 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* ChooseClass */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(450,455,110,30,2,27,0,"Select Class",12,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(450,455,110,30,2,27,0,"Select Class",12,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_ChooseClass_event()) != -1) break;

							}
						continue;
					case	0x3 :
						/* FilePage */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_file_properties_losefocus();
							_Context->page_number = 1;
							accept_file_properties_show();
							}
						continue;
					case	0x4 :
						/* FileClass */
						continue;
					case	0x5 :
						/* Handle */
						continue;
					case	0x6 :
						/* FileName */
						continue;
					case	0x7 :
						/* FileType */
						continue;
					case	0x8 :
						/* ProductionTarget */
						continue;
					case	0x9 :
						/* Dependance */
						continue;
					case	0xa :
						/* DataPage */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_file_properties_losefocus();
							_Context->page_number = 2;
							accept_file_properties_show();
							}
						continue;
					case	0xb :
						/* RecordClass */
						continue;
					case	0xc :
						/* RecordSize */
						continue;
					case	0xd :
						/* IsVariable */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsVariable += 1;
							_Context->value_IsVariable &= 1;
							}
						continue;
					case	0xe :
						/* DataForm */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_DataForm += 1;
							_Context->value_DataForm &= 1;
							}
						continue;
					case	0xf :
						/* IndexPage */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_file_properties_losefocus();
							_Context->page_number = 3;
							accept_file_properties_show();
							}
						continue;
					case	0x10 :
						/* Align */
						continue;
					case	0x11 :
						/* IndexClass */
						continue;
					case	0x12 :
						/* IndexSize */
						continue;
					case	0x13 :
						/* IndexForm */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IndexForm += 1;
							_Context->value_IndexForm &= 1;
							}
						continue;
					case	0x14 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(569,453,110,30,2,27,0,"Cancel",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(569,453,110,30,2,27,0,"Cancel",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0x15 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(120,455,110,30,2,27,0,"Accept",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(120,455,110,30,2,27,0,"Accept",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x16 :
						/* Edit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(240,455,110,30,2,26,0,"Edit",4,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(240,455,110,30,2,26,0,"Edit",4,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Edit_event()) != -1) break;

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
				_Context->focus_item=22;
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

public	int	accept_file_properties(
	char * pFileClass,
	char * pHandle,
	char * pFileName,
	char * pFileType,
	char * pProductionTarget,
	char * pDependance,
	char * pRecordClass,
	char * pRecordSize,
	char * pIsVariable,
	char * pDataForm,
	char * pAlign,
	char * pIndexClass,
	char * pIndexSize,
	char * pIndexForm)
{
	int	status=0;
	status = accept_file_properties_create(
	 pFileClass,
	 pHandle,
	 pFileName,
	 pFileType,
	 pProductionTarget,
	 pDependance,
	 pRecordClass,
	 pRecordSize,
	 pIsVariable,
	 pDataForm,
	 pAlign,
	 pIndexClass,
	 pIndexSize,
	 pIndexForm);
	if ( status != 0) return(status);
	status = accept_file_properties_show();
		enter_modal();
	status = accept_file_properties_focus();
		leave_modal();
	status = accept_file_properties_hide();
	status = accept_file_properties_remove(
	 pFileClass,
	 pHandle,
	 pFileName,
	 pFileType,
	 pProductionTarget,
	 pDependance,
	 pRecordClass,
	 pRecordSize,
	 pIsVariable,
	 pDataForm,
	 pAlign,
	 pIndexClass,
	 pIndexSize,
	 pIndexForm);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vfile_c */
