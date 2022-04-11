
#ifndef _vcompare_c
#define _vcompare_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.46  */
/* Production     : C  */
/* Project        : vcompare.xml  */
/* Target         : vcompare.c  */
/* Identification : 0.0-1101209806-2733.2732 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "avnfile.h"
#include "singprot.h"
#define en_Auto1837   "File Compare Utility"
#define en_Auto1838   "Files"
#define en_Auto1839   "File Compare"
#define en_Auto1841   "First Filename for compare"
#define en_Auto1842   "Second Filename for compare"
#define en_Auto1843   "Differences"
#define en_FileOne   ""
#define en_SelectOne   "&>>>"
#define fr_SelectOne   "&S‚lection"
#define en_SelectTwo   "&>>>"
#define fr_SelectTwo   "&S‚lection"
#define en_FileTwo   ""
#define en_Invertor   "Inversion of compare information"
#define en_Differences   ""
#define en_DoCompare   "Compare Files"
#define en_DiffPage   "Differences"
#define en_lFile   ""
#define en_Auto1844   ""
#define en_Auto1845   ""
#define en_rFile   ""
#define en_Auto1847   "First"
#define en_Auto1848   "Previous"
#define en_Auto1849   "Next"
#define en_Auto1850   "Last"
static int	vfh[10];

private struct visual_file_compare_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[2+1];
	char * msg_Auto1837[8];
	int	x_Auto1837;
	int	y_Auto1837;
	int	w_Auto1837;
	int	h_Auto1837;
	char * msg_Auto1838[8];
	int	trigger_Auto1838;
	int	page_number;
	char * msg_Auto1839[8];
	char * msg_Auto1841[8];
	char * msg_Auto1842[8];
	char * msg_Auto1843[8];
	char	buffer_FileOne[87];
	char * msg_SelectOne[8];
	int	trigger_SelectOne;
	char * msg_SelectTwo[8];
	int	trigger_SelectTwo;
	char	buffer_FileTwo[87];
	char * msg_Invertor[8];
	int	trigger_Invertor;
	int	value_Invertor;
	char	buffer_Differences[18];
	char * msg_DoCompare[8];
	int	trigger_DoCompare;
	char * msg_DiffPage[8];
	int	trigger_DiffPage;
	char	buffer_lFile[5761];
	char	buffer_Auto1844[13];
	char	buffer_Auto1845[13];
	char	buffer_rFile[5761];
	char * msg_Auto1847[8];
	int	trigger_Auto1847;
	char * msg_Auto1848[8];
	int	trigger_Auto1848;
	char * msg_Auto1849[8];
	int	trigger_Auto1849;
	char * msg_Auto1850[8];
	int	trigger_Auto1850;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};

public	int	visual_file_compare_create(
	struct visual_file_compare_context ** cptr,
	char * pFileOne,
	char * pFileTwo)
{

	int i;
	struct visual_file_compare_context * _Context=(struct visual_file_compare_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct visual_file_compare_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=18;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileOne, 86, pFileOne);
		visual_transferin(_Context->buffer_FileTwo, 86, pFileTwo);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto1837[i]=" ";
	_Context->msg_Auto1837[0]=en_Auto1837;
	_Context->x_Auto1837=112;
	_Context->y_Auto1837=93;
	_Context->w_Auto1837=800;
	_Context->h_Auto1837=600;
	_Context->window_col=10;
	_Context->window_row=10;
	for (i=0; i < 8; i++)_Context->msg_Auto1838[i]=" ";
	_Context->msg_Auto1838[0]=en_Auto1838;
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_Auto1839[i]=" ";
	_Context->msg_Auto1839[0]=en_Auto1839;
	for (i=0; i < 8; i++)_Context->msg_Auto1841[i]=" ";
	_Context->msg_Auto1841[0]=en_Auto1841;
	for (i=0; i < 8; i++)_Context->msg_Auto1842[i]=" ";
	_Context->msg_Auto1842[0]=en_Auto1842;
	for (i=0; i < 8; i++)_Context->msg_Auto1843[i]=" ";
	_Context->msg_Auto1843[0]=en_Auto1843;
	for (i=0; i < 8; i++)_Context->msg_SelectOne[i]=" ";
	_Context->msg_SelectOne[0]=en_SelectOne;
	_Context->msg_SelectOne[1]=fr_SelectOne;
	for (i=0; i < 8; i++)_Context->msg_SelectTwo[i]=" ";
	_Context->msg_SelectTwo[0]=en_SelectTwo;
	_Context->msg_SelectTwo[1]=fr_SelectTwo;
	for (i=0; i < 8; i++)_Context->msg_Invertor[i]=" ";
	_Context->msg_Invertor[0]=en_Invertor;
	strcpy(_Context->buffer_Differences,"0");
	for (i=0; i < 8; i++)_Context->msg_DoCompare[i]=" ";
	_Context->msg_DoCompare[0]=en_DoCompare;
	for (i=0; i < 8; i++)_Context->msg_DiffPage[i]=" ";
	_Context->msg_DiffPage[0]=en_DiffPage;
	_Context->focus_pages[2]=10;
	for (i=0; i < 8; i++)_Context->msg_Auto1847[i]=" ";
	_Context->msg_Auto1847[0]=en_Auto1847;
	for (i=0; i < 8; i++)_Context->msg_Auto1848[i]=" ";
	_Context->msg_Auto1848[0]=en_Auto1848;
	for (i=0; i < 8; i++)_Context->msg_Auto1849[i]=" ";
	_Context->msg_Auto1849[0]=en_Auto1849;
	for (i=0; i < 8; i++)_Context->msg_Auto1850[i]=" ";
	_Context->msg_Auto1850[0]=en_Auto1850;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto1837,_Context->y_Auto1837,800,600);
	return(0);
}

public 	int	visual_file_compare_hide(struct visual_file_compare_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto1837,_Context->y_Auto1837);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	visual_file_compare_remove(
	struct visual_file_compare_context * _Context,
	char * pFileOne,
	char * pFileTwo)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileOne, 86, pFileOne);
		visual_transferout(_Context->buffer_FileTwo, 86, pFileTwo);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_lFile_show(struct visual_file_compare_context * _Context) {
	struct avnor_diff*dptr;
	drop_window_editor();
	open_window_editor(_Context->x_Auto1837+14,_Context->y_Auto1837+58,384,480,_Context->buffer_FileOne);
	visual_frame(_Context->x_Auto1837+14,_Context->y_Auto1837+58,384+2,480+2,5);
visual_text(_Context->x_Auto1837+14+1,_Context->y_Auto1837+58+1,384,480,vfh[8],27,28,_Context->buffer_lFile,5760,0);
;
	dptr=select_difference(0);
	if(dptr){
	editorOnSeek(0,dptr->lline);
	if(_Context->value_Invertor==0){
	switch(dptr->type){
	case 2:/*deleted fro left*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	case 1:/*inserted in left*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	case 3:/*modified*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	}
	}
	else{
	switch(dptr->type){
	case 2:/*deleted fro left*/
	editorOnHigh(dptr->lline,1);
	break;
	case 1:/*inserted in left*/
	editorOnHigh(dptr->lline,1);
	break;
	case 3:/*modified*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	}
	}
	}
	else{
	show_window_editor();
	}
	return(-1);
}
private int on_Auto1844_show(struct visual_file_compare_context * _Context) {
	struct avnor_diff*dptr;
	if(!(dptr=select_difference(0)))
	strcpy(_Context->buffer_Auto1844,"\0");
	else sprintf(_Context->buffer_Auto1844,"%u",dptr->lline);
	visual_frame(_Context->x_Auto1837+24,_Context->y_Auto1837+554,96+2,16+2,5);
visual_text(_Context->x_Auto1837+24+1,_Context->y_Auto1837+554+1,96,16,vfh[1],0,0,_Context->buffer_Auto1844,12,0);
;
	return(-1);
}
private int on_Auto1845_show(struct visual_file_compare_context * _Context) {
	struct avnor_diff*dptr;
	if(!(dptr=select_difference(0)))
	strcpy(_Context->buffer_Auto1845,"\0");
	else sprintf(_Context->buffer_Auto1845,"%u",dptr->rline);
	visual_frame(_Context->x_Auto1837+680,_Context->y_Auto1837+556,96+2,16+2,5);
visual_text(_Context->x_Auto1837+680+1,_Context->y_Auto1837+556+1,96,16,vfh[1],0,0,_Context->buffer_Auto1845,12,0);
;
	return(-1);
}
private int on_rFile_show(struct visual_file_compare_context * _Context) {
	struct avnor_diff*dptr;
	drop_window_editor();
	open_window_editor(_Context->x_Auto1837+402,_Context->y_Auto1837+58,384,480,_Context->buffer_FileTwo);
	visual_frame(_Context->x_Auto1837+402,_Context->y_Auto1837+58,384+2,480+2,5);
visual_text(_Context->x_Auto1837+402+1,_Context->y_Auto1837+58+1,384,480,vfh[8],27,28,_Context->buffer_rFile,5760,0);
;
	dptr=select_difference(0);
	if(dptr){
	editorOnSeek(0,dptr->rline);
	if(_Context->value_Invertor==0){
	switch(dptr->type){
	case 2:/*deleted fro left*/
	editorOnHigh(dptr->lline,1);
	break;
	case 1:/*inserted in left*/
	editorOnHigh(dptr->lline,1);
	break;
	case 3:/*modified*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	}
	}
	else{
	switch(dptr->type){
	case 2:/*deleted fro left*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	case 1:/*inserted in left*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	case 3:/*modified*/
	editorOnHigh(dptr->lline,dptr->lines);
	break;
	}
	}
	}
	else{
	show_window_editor();
	}
	return(-1);
}

public	int	visual_file_compare_show(struct visual_file_compare_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto1837,_Context->y_Auto1837);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto1837,_Context->y_Auto1837,800,600,vfh[2],_Context->msg_Auto1837[_Context->language],strlen(_Context->msg_Auto1837[_Context->language]),0x7);
	if (_Context->page_number == 1 ) {
	_Context->trigger_Auto1838=visual_trigger_code(_Context->msg_Auto1838[_Context->language],strlen(_Context->msg_Auto1838[_Context->language]));
	visual_tabpage(_Context->x_Auto1837+10,_Context->y_Auto1837+30,784,560,vfh[2],_Context->msg_Auto1838[_Context->language],strlen(_Context->msg_Auto1838[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto1837+10,_Context->y_Auto1837+30,784,560,vfh[2],_Context->msg_Auto1838[_Context->language],strlen(_Context->msg_Auto1838[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto1837+30,_Context->y_Auto1837+100,740,20,vfh[3],16,0,_Context->msg_Auto1839[_Context->language],strlen(_Context->msg_Auto1839[_Context->language]),1282);
	visual_frame(_Context->x_Auto1837+30,_Context->y_Auto1837+120,740,310,4);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto1837+160,_Context->y_Auto1837+350,470,50,2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto1837+40,_Context->y_Auto1837+150,270,20,vfh[2],16,0,_Context->msg_Auto1841[_Context->language],strlen(_Context->msg_Auto1841[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto1837+40,_Context->y_Auto1837+240,266,16,vfh[2],16,0,_Context->msg_Auto1842[_Context->language],strlen(_Context->msg_Auto1842[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto1837+370,_Context->y_Auto1837+370,98,16,vfh[2],16,0,_Context->msg_Auto1843[_Context->language],strlen(_Context->msg_Auto1843[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto1837+40,_Context->y_Auto1837+180,688+2,16+2,5);
	visual_text(_Context->x_Auto1837+40+1,_Context->y_Auto1837+180+1,688,16,vfh[1],16,0,_Context->buffer_FileOne,86,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_SelectOne=visual_trigger_code(_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]));
	visual_button(_Context->x_Auto1837+732,_Context->y_Auto1837+180,20,16,vfh[8],27,24,_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_SelectTwo=visual_trigger_code(_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]));
	visual_button(_Context->x_Auto1837+732,_Context->y_Auto1837+260,20,16,vfh[8],27,24,_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto1837+40,_Context->y_Auto1837+260,688+2,16+2,5);
	visual_text(_Context->x_Auto1837+40+1,_Context->y_Auto1837+260+1,688,16,vfh[1],16,0,_Context->buffer_FileTwo,86,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Invertor=visual_trigger_code(_Context->msg_Invertor[_Context->language],strlen(_Context->msg_Invertor[_Context->language]));
	visual_check(_Context->x_Auto1837+162,_Context->y_Auto1837+318,462,16,vfh[2],27,28,_Context->msg_Invertor[_Context->language],strlen(_Context->msg_Invertor[_Context->language]),_Context->value_Invertor|0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto1837+480,_Context->y_Auto1837+370,136+2,16+2,5);
	visual_text(_Context->x_Auto1837+480+1,_Context->y_Auto1837+370+1,136,16,vfh[1],16,0,_Context->buffer_Differences,17,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_DoCompare=visual_trigger_code(_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]));
	visual_button(_Context->x_Auto1837+170,_Context->y_Auto1837+360,130,32,vfh[2],16,0,_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_DiffPage=visual_trigger_code(_Context->msg_DiffPage[_Context->language],strlen(_Context->msg_DiffPage[_Context->language]));
	visual_tabpage(_Context->x_Auto1837+10,_Context->y_Auto1837+30,784,560,vfh[2],_Context->msg_DiffPage[_Context->language],strlen(_Context->msg_DiffPage[_Context->language]),57,2);
	} else {
		visual_tabpage(_Context->x_Auto1837+10,_Context->y_Auto1837+30,784,560,vfh[2],_Context->msg_DiffPage[_Context->language],strlen(_Context->msg_DiffPage[_Context->language]),57,0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_lFile_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_Auto1844_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_Auto1845_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_rFile_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto1837+136,_Context->y_Auto1837+548,532,38,2);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Auto1847=visual_trigger_code(_Context->msg_Auto1847[_Context->language],strlen(_Context->msg_Auto1847[_Context->language]));
	visual_button(_Context->x_Auto1837+138,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1847[_Context->language],strlen(_Context->msg_Auto1847[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Auto1848=visual_trigger_code(_Context->msg_Auto1848[_Context->language],strlen(_Context->msg_Auto1848[_Context->language]));
	visual_button(_Context->x_Auto1837+270,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1848[_Context->language],strlen(_Context->msg_Auto1848[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Auto1849=visual_trigger_code(_Context->msg_Auto1849[_Context->language],strlen(_Context->msg_Auto1849[_Context->language]));
	visual_button(_Context->x_Auto1837+402,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1849[_Context->language],strlen(_Context->msg_Auto1849[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Auto1850=visual_trigger_code(_Context->msg_Auto1850[_Context->language],strlen(_Context->msg_Auto1850[_Context->language]));
	visual_button(_Context->x_Auto1837+534,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1850[_Context->language],strlen(_Context->msg_Auto1850[_Context->language]),0);
		}
	visual_thaw(_Context->x_Auto1837,_Context->y_Auto1837,800,600);
	visual_thaw(_Context->x_Auto1837,_Context->y_Auto1837,800,600);

	return(0);
}

private int Auto1837action(struct visual_file_compare_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			visual_file_compare_hide(_Context);

		_Context->x_Auto1837 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto1837 < 0) { _Context->x_Auto1837=0; }
		_Context->y_Auto1837 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto1837 < 0) { _Context->y_Auto1837=0; }
			visual_file_compare_show(_Context);

		visual_thaw(_Context->x_Auto1837,_Context->y_Auto1837,800,600);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_SelectOne_event(struct visual_file_compare_context * _Context) {
	use_file_selector(_Context->buffer_FileOne,WIDGET_FILE_AS);
	visual_frame(_Context->x_Auto1837+40,_Context->y_Auto1837+180,688+2,16+2,5);
visual_text(_Context->x_Auto1837+40+1,_Context->y_Auto1837+180+1,688,16,vfh[1],16,0,_Context->buffer_FileOne,86,0);
;
	return(-1);
}
private int on_SelectTwo_event(struct visual_file_compare_context * _Context) {
	use_file_selector(_Context->buffer_FileTwo,WIDGET_FILE_AS);
	visual_frame(_Context->x_Auto1837+40,_Context->y_Auto1837+260,688+2,16+2,5);
visual_text(_Context->x_Auto1837+40+1,_Context->y_Auto1837+260+1,688,16,vfh[1],16,0,_Context->buffer_FileTwo,86,0);
;
	return(-1);
}
private int on_DoCompare_event(struct visual_file_compare_context * _Context) {
	int nombre;
	release_differences();
	nombre=calculate_differences(_Context->buffer_FileOne,86,_Context->buffer_FileTwo,86,0);
	sprintf(_Context->buffer_Differences,"%u",nombre);
	if(nombre!=0){
		/* DiffPage */
	visual_file_compare_losefocus(_Context);
	_Context->page_number = 2;
	visual_file_compare_show(_Context);
	_Context->focus_item=10;
;
	}
	return(-1);
}
private int on_Auto1847_event(struct visual_file_compare_context * _Context) {
	select_difference(12);
		visual_file_compare_show(_Context);
;
	return(-1);
}
private int on_Auto1848_event(struct visual_file_compare_context * _Context) {
	select_difference(11);
		visual_file_compare_show(_Context);
;
	return(-1);
}
private int on_Auto1849_event(struct visual_file_compare_context * _Context) {
	select_difference(5);
		visual_file_compare_show(_Context);
;
	return(-1);
}
private int on_Auto1850_event(struct visual_file_compare_context * _Context) {
	select_difference(2);
		visual_file_compare_show(_Context);
;
	return(-1);
}


public	int	visual_file_compare_event(
struct visual_file_compare_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto1838 == mb ) return(2);
		if (_Context->trigger_SelectOne == mb ) return(4);
		if (_Context->trigger_SelectTwo == mb ) return(5);
		if (_Context->trigger_Invertor == mb ) return(7);
		if (_Context->trigger_DoCompare == mb ) return(9);
		if (_Context->trigger_DiffPage == mb ) return(10);
		if (_Context->trigger_Auto1847 == mb ) return(15);
		if (_Context->trigger_Auto1848 == mb ) return(16);
		if (_Context->trigger_Auto1849 == mb ) return(17);
		if (_Context->trigger_Auto1850 == mb ) return(18);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto1837+779) )  
	&&  (my >= (_Context->y_Auto1837+4) )  
	&&  (mx <= (_Context->x_Auto1837+796) )  
	&&  (my <= (_Context->y_Auto1837+20) )) {
		return(1);	/* Auto1837 */

		}
	if ((mx >= (_Context->x_Auto1837+763) )  
	&&  (my >= (_Context->y_Auto1837+4) )  
	&&  (mx <= (_Context->x_Auto1837+780) )  
	&&  (my <= (_Context->y_Auto1837+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcompare.htm");
			};
		return(-1);	/* Auto1837 */

		}
	if ((mx >= (_Context->x_Auto1837+747) )  
	&&  (my >= (_Context->y_Auto1837+4) )  
	&&  (mx <= (_Context->x_Auto1837+764) )  
	&&  (my <= (_Context->y_Auto1837+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		visual_file_compare_show(_Context);
		return(-1);	/* Auto1837 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto1837+4) )  
		&&  (my >= (_Context->y_Auto1837+4) )  
		&&  (mx <= (_Context->x_Auto1837+732) )  
		&&  (my <= (_Context->y_Auto1837+20) )) {
			return( Auto1837action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto1837+10+0) ) 
		&&  ( my >= (_Context->y_Auto1837+30) ) 
		&&  ( mx <= (_Context->x_Auto1837+10+56) ) 
		&&  ( my <= (_Context->y_Auto1837+30+24))) {
			return(2); /* Auto1838 */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1837+40) ) 
		&&  ( my >= (_Context->y_Auto1837+180) ) 
		&&  ( mx <= (_Context->x_Auto1837+40+688) ) 
		&&  ( my <= (_Context->y_Auto1837+180+16))) {
			return(3); /* FileOne */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1837+732) ) 
		&&  ( my >= (_Context->y_Auto1837+180) ) 
		&&  ( mx <= (_Context->x_Auto1837+732+20) ) 
		&&  ( my <= (_Context->y_Auto1837+180+16))) {
			return(4); /* SelectOne */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1837+732) ) 
		&&  ( my >= (_Context->y_Auto1837+260) ) 
		&&  ( mx <= (_Context->x_Auto1837+732+20) ) 
		&&  ( my <= (_Context->y_Auto1837+260+16))) {
			return(5); /* SelectTwo */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1837+40) ) 
		&&  ( my >= (_Context->y_Auto1837+260) ) 
		&&  ( mx <= (_Context->x_Auto1837+40+688) ) 
		&&  ( my <= (_Context->y_Auto1837+260+16))) {
			return(6); /* FileTwo */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1837+162) ) 
		&&  ( my >= (_Context->y_Auto1837+318) ) 
		&&  ( mx <= (_Context->x_Auto1837+162+462) ) 
		&&  ( my <= (_Context->y_Auto1837+318+16))) {
			return(7); /* Invertor */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1837+480) ) 
		&&  ( my >= (_Context->y_Auto1837+370) ) 
		&&  ( mx <= (_Context->x_Auto1837+480+136) ) 
		&&  ( my <= (_Context->y_Auto1837+370+16))) {
			return(8); /* Differences */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1837+170) ) 
		&&  ( my >= (_Context->y_Auto1837+360) ) 
		&&  ( mx <= (_Context->x_Auto1837+170+130) ) 
		&&  ( my <= (_Context->y_Auto1837+360+32))) {
			return(9); /* DoCompare */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto1837+10+57) ) 
		&&  ( my >= (_Context->y_Auto1837+30) ) 
		&&  ( mx <= (_Context->x_Auto1837+10+156) ) 
		&&  ( my <= (_Context->y_Auto1837+30+24))) {
			return(10); /* DiffPage */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1837+14) ) 
		&&  ( my >= (_Context->y_Auto1837+58) ) 
		&&  ( mx <= (_Context->x_Auto1837+14+384) ) 
		&&  ( my <= (_Context->y_Auto1837+58+480))) {
			return(11); /* lFile */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1837+24) ) 
		&&  ( my >= (_Context->y_Auto1837+554) ) 
		&&  ( mx <= (_Context->x_Auto1837+24+96) ) 
		&&  ( my <= (_Context->y_Auto1837+554+16))) {
			return(12); /* Auto1844 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1837+680) ) 
		&&  ( my >= (_Context->y_Auto1837+556) ) 
		&&  ( mx <= (_Context->x_Auto1837+680+96) ) 
		&&  ( my <= (_Context->y_Auto1837+556+16))) {
			return(13); /* Auto1845 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1837+402) ) 
		&&  ( my >= (_Context->y_Auto1837+58) ) 
		&&  ( mx <= (_Context->x_Auto1837+402+384) ) 
		&&  ( my <= (_Context->y_Auto1837+58+480))) {
			return(14); /* rFile */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1837+138) ) 
		&&  ( my >= (_Context->y_Auto1837+550) ) 
		&&  ( mx <= (_Context->x_Auto1837+138+130) ) 
		&&  ( my <= (_Context->y_Auto1837+550+32))) {
			return(15); /* Auto1847 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1837+270) ) 
		&&  ( my >= (_Context->y_Auto1837+550) ) 
		&&  ( mx <= (_Context->x_Auto1837+270+130) ) 
		&&  ( my <= (_Context->y_Auto1837+550+32))) {
			return(16); /* Auto1848 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1837+402) ) 
		&&  ( my >= (_Context->y_Auto1837+550) ) 
		&&  ( mx <= (_Context->x_Auto1837+402+130) ) 
		&&  ( my <= (_Context->y_Auto1837+550+32))) {
			return(17); /* Auto1849 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1837+534) ) 
		&&  ( my >= (_Context->y_Auto1837+550) ) 
		&&  ( mx <= (_Context->x_Auto1837+534+130) ) 
		&&  ( my <= (_Context->y_Auto1837+550+32))) {
			return(18); /* Auto1850 */
			}
		}

	return(-1);
}


public	int	visual_file_compare_losefocus(struct visual_file_compare_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;

		}
	return(0);

}
private int on_lFile_getfocus(struct visual_file_compare_context * _Context) {
	on_lFile_show(_Context);
	return(focus_window_editor());
	return(-1);
}
private int on_rFile_getfocus(struct visual_file_compare_context * _Context) {
	on_rFile_show(_Context);
	return(focus_window_editor());
	return(-1);
}


public	int	visual_file_compare_focus(struct visual_file_compare_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto1838 */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* FileOne */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1837+40+1,_Context->y_Auto1837+180+1,688,16,vfh[1],_Context->buffer_FileOne,86);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* SelectOne */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_Auto1837+732,_Context->y_Auto1837+180,20,16,vfh[8],27,24,_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1837+732,_Context->y_Auto1837+180,20,16,vfh[8],27,24,_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* SelectTwo */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_Auto1837+732,_Context->y_Auto1837+260,20,16,vfh[8],27,24,_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1837+732,_Context->y_Auto1837+260,20,16,vfh[8],27,24,_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* FileTwo */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1837+40+1,_Context->y_Auto1837+260+1,688,16,vfh[1],_Context->buffer_FileTwo,86);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* Invertor */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto1837+162,_Context->y_Auto1837+318,462,16,vfh[2],27,28,_Context->msg_Invertor[_Context->language],strlen(_Context->msg_Invertor[_Context->language]),(_Context->value_Invertor |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1837+162,_Context->y_Auto1837+318,462,16,vfh[2],27,28,_Context->msg_Invertor[_Context->language],strlen(_Context->msg_Invertor[_Context->language]),(_Context->value_Invertor |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* Differences */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1837+480+1,_Context->y_Auto1837+370+1,136,16,vfh[1],_Context->buffer_Differences,17);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* DoCompare */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_Auto1837+170,_Context->y_Auto1837+360,130,32,vfh[2],16,0,_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1837+170,_Context->y_Auto1837+360,130,32,vfh[2],16,0,_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* DiffPage */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xb :
				/* lFile */
				if (_Context->page_number == 2 ) {
					if ((_Context->keycode = on_lFile_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* rFile */
				if (_Context->page_number == 2 ) {
					if ((_Context->keycode = on_rFile_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* Auto1847 */
				if (_Context->page_number == 2 ) {
					visual_button(_Context->x_Auto1837+138,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1847[_Context->language],strlen(_Context->msg_Auto1847[_Context->language]),1282);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1837+138,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1847[_Context->language],strlen(_Context->msg_Auto1847[_Context->language]),1280);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* Auto1848 */
				if (_Context->page_number == 2 ) {
					visual_button(_Context->x_Auto1837+270,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1848[_Context->language],strlen(_Context->msg_Auto1848[_Context->language]),1282);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1837+270,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1848[_Context->language],strlen(_Context->msg_Auto1848[_Context->language]),1280);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* Auto1849 */
				if (_Context->page_number == 2 ) {
					visual_button(_Context->x_Auto1837+402,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1849[_Context->language],strlen(_Context->msg_Auto1849[_Context->language]),1282);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1837+402,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1849[_Context->language],strlen(_Context->msg_Auto1849[_Context->language]),1280);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* Auto1850 */
				if (_Context->page_number == 2 ) {
					visual_button(_Context->x_Auto1837+534,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1850[_Context->language],strlen(_Context->msg_Auto1850[_Context->language]),1282);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1837+534,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1850[_Context->language],strlen(_Context->msg_Auto1850[_Context->language]),1280);
				} else {
				_Context->keycode = 5;
					}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			visual_file_compare_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			visual_file_compare_show(_Context);
			continue;
		case	0x2 :
			visual_file_compare_losefocus(_Context);
			_Context->page_number=2;
			_Context->focus_item=18;
			visual_file_compare_show(_Context);
			continue;
		case	0x3 :
			visual_file_compare_losefocus(_Context);
			if ( _Context->page_number < 2 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			visual_file_compare_show(_Context);
			continue;
		case	0x12 :
			visual_file_compare_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			visual_file_compare_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=visual_file_compare_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1837 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Auto1838 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_file_compare_losefocus(_Context);
							_Context->page_number = 1;
							visual_file_compare_show(_Context);
							}
						continue;
					case	0x3 :
						/* FileOne */
						continue;
					case	0x4 :
						/* SelectOne */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1837+732,_Context->y_Auto1837+180,20,16,vfh[8],27,24,_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1837+732,_Context->y_Auto1837+180,20,16,vfh[8],27,24,_Context->msg_SelectOne[_Context->language],strlen(_Context->msg_SelectOne[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SelectOne_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* SelectTwo */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1837+732,_Context->y_Auto1837+260,20,16,vfh[8],27,24,_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1837+732,_Context->y_Auto1837+260,20,16,vfh[8],27,24,_Context->msg_SelectTwo[_Context->language],strlen(_Context->msg_SelectTwo[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SelectTwo_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* FileTwo */
						continue;
					case	0x7 :
						/* Invertor */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Invertor += 1;
							_Context->value_Invertor &= 1;
							}
						continue;
					case	0x8 :
						/* Differences */
						continue;
					case	0x9 :
						/* DoCompare */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1837+170,_Context->y_Auto1837+360,130,32,vfh[2],16,0,_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1837+170,_Context->y_Auto1837+360,130,32,vfh[2],16,0,_Context->msg_DoCompare[_Context->language],strlen(_Context->msg_DoCompare[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_DoCompare_event(_Context)) != -1) break;

							}
						continue;
					case	0xa :
						/* DiffPage */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_file_compare_losefocus(_Context);
							_Context->page_number = 2;
							visual_file_compare_show(_Context);
							}
						continue;
					case	0xb :
						/* lFile */
						continue;
					case	0xc :
						/* Auto1844 */
						continue;
					case	0xd :
						/* Auto1845 */
						continue;
					case	0xe :
						/* rFile */
						continue;
					case	0xf :
						/* Auto1847 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1837+138,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1847[_Context->language],strlen(_Context->msg_Auto1847[_Context->language]),1282);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1837+138,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1847[_Context->language],strlen(_Context->msg_Auto1847[_Context->language]),1280);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1847_event(_Context)) != -1) break;

							}
						continue;
					case	0x10 :
						/* Auto1848 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1837+270,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1848[_Context->language],strlen(_Context->msg_Auto1848[_Context->language]),1282);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1837+270,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1848[_Context->language],strlen(_Context->msg_Auto1848[_Context->language]),1280);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1848_event(_Context)) != -1) break;

							}
						continue;
					case	0x11 :
						/* Auto1849 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1837+402,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1849[_Context->language],strlen(_Context->msg_Auto1849[_Context->language]),1282);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1837+402,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1849[_Context->language],strlen(_Context->msg_Auto1849[_Context->language]),1280);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1849_event(_Context)) != -1) break;

							}
						continue;
					case	0x12 :
						/* Auto1850 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1837+534,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1850[_Context->language],strlen(_Context->msg_Auto1850[_Context->language]),1282);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1837+534,_Context->y_Auto1837+550,130,32,vfh[2],16,0,_Context->msg_Auto1850[_Context->language],strlen(_Context->msg_Auto1850[_Context->language]),1280);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1850_event(_Context)) != -1) break;

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
				_Context->focus_item=18;
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

public	int	visual_file_compare(
	char * pFileOne,
	char * pFileTwo)
{
	int	status=0;
	struct visual_file_compare_context * _Context=(struct visual_file_compare_context*) 0;
	status = visual_file_compare_create(
	&_Context,
	 pFileOne,
	 pFileTwo);
	if ( status != 0) return(status);
	status = visual_file_compare_show(_Context);
		enter_modal();
	status = visual_file_compare_focus(_Context);
		leave_modal();
	status = visual_file_compare_hide(_Context);
	status = visual_file_compare_remove(
	_Context,
	 pFileOne,
	 pFileTwo);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcompare_c */
