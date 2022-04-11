
#ifndef _vintro_c
#define _vintro_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vintro.xml                                               */
/* Target         : vintro.c                                                 */
/* Identification : 0.0-1177511935-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "version.h"
#include "singprot.h"
#define en_Auto2740   "Sing : Version 1.0a"
#define fr_Auto2740   "Sing : Version 1.0a"
#define it_Auto2740   "Sing : Version 1.0a"
#define es_Auto2740   "Sing : Version 1.0a"
#define de_Auto2740   "Sing : Version 1.0a"
#define nl_Auto2740   "Sing : Version 1.0a"
#define pt_Auto2740   "Sing : Version 1.0a"
#define xx_Auto2740   "Sing : Version 1.0a"
#define en_Auto2741   ""
#define en_Auto2743   "logo.jpg"
#define fr_Auto2743   "logo.jpg"
#define it_Auto2743   "logo.jpg"
#define es_Auto2743   "logo.jpg"
#define de_Auto2743   "logo.jpg"
#define nl_Auto2743   "logo.jpg"
#define pt_Auto2743   "logo.jpg"
#define xx_Auto2743   "logo.jpg"
#define en__Auto2743   ""
#define fr__Auto2743   ""
#define it__Auto2743   ""
#define es__Auto2743   ""
#define de__Auto2743   ""
#define nl__Auto2743   ""
#define pt__Auto2743   ""
#define xx__Auto2743   ""
#define en_Auto2744   "abal3.jpg"
#define fr_Auto2744   "abal3.jpg"
#define it_Auto2744   "abal3.jpg"
#define es_Auto2744   "abal3.jpg"
#define de_Auto2744   "abal3.jpg"
#define nl_Auto2744   "abal3.jpg"
#define pt_Auto2744   "abal3.jpg"
#define xx_Auto2744   "abal3.jpg"
#define en__Auto2744   ""
#define fr__Auto2744   ""
#define it__Auto2744   ""
#define es__Auto2744   ""
#define de__Auto2744   ""
#define nl__Auto2744   ""
#define pt__Auto2744   ""
#define xx__Auto2744   ""
#define en_Auto2745   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define fr_Auto2745   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define it_Auto2745   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define es_Auto2745   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define de_Auto2745   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define nl_Auto2745   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define pt_Auto2745   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define xx_Auto2745   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define en__Auto2745   ""
#define fr__Auto2745   ""
#define it__Auto2745   ""
#define es__Auto2745   ""
#define de__Auto2745   ""
#define nl__Auto2745   ""
#define pt__Auto2745   ""
#define xx__Auto2745   ""
#define en_Auto2746   "Sing"
#define fr_Auto2746   "Sing"
#define it_Auto2746   "Sing"
#define es_Auto2746   "Sing"
#define de_Auto2746   "Sing"
#define nl_Auto2746   "Sing"
#define pt_Auto2746   "Sing"
#define xx_Auto2746   "Sing"
#define en__Auto2746   ""
#define fr__Auto2746   ""
#define it__Auto2746   ""
#define es__Auto2746   ""
#define de__Auto2746   ""
#define nl__Auto2746   ""
#define pt__Auto2746   ""
#define xx__Auto2746   ""
#define en__Auto2747   ""
#define fr__Auto2747   ""
#define it__Auto2747   ""
#define es__Auto2747   ""
#define de__Auto2747   ""
#define nl__Auto2747   ""
#define pt__Auto2747   ""
#define xx__Auto2747   ""

private struct accept_introduction_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2740[8];
	char * hint_Auto2740[8];
	int	x_Auto2740;
	int	y_Auto2740;
	int	w_Auto2740;
	int	h_Auto2740;
	char * hint_Auto2741[8];
	char * msg_Auto2743[8];
	char * hint_Auto2743[8];
	char * msg_Auto2744[8];
	char * hint_Auto2744[8];
	char * msg_Auto2745[8];
	char * hint_Auto2745[8];
	char * msg_Auto2746[8];
	char * hint_Auto2746[8];
	char * msg_Auto2747[8];
	char * hint_Auto2747[8];
	char	signature[1];
	};
static int	vfh[16];

public	int	accept_introduction_create(struct accept_introduction_context **cptr)
{

	int i;
	struct accept_introduction_context * _Context=(struct accept_introduction_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_introduction_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=1;
	for (i=0; i < 8; i++)_Context->msg_Auto2740[i]=" ";
	_Context->msg_Auto2740[0]=en_Auto2740;
	_Context->msg_Auto2740[1]=fr_Auto2740;
	_Context->msg_Auto2740[2]=it_Auto2740;
	_Context->msg_Auto2740[3]=es_Auto2740;
	_Context->msg_Auto2740[4]=de_Auto2740;
	_Context->msg_Auto2740[5]=nl_Auto2740;
	_Context->msg_Auto2740[6]=pt_Auto2740;
	_Context->msg_Auto2740[7]=xx_Auto2740;
	_Context->x_Auto2740=170;
	_Context->y_Auto2740=90;
	_Context->w_Auto2740=460;
	_Context->h_Auto2740=420;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2743[i]=" ";
	_Context->msg_Auto2743[0]=en_Auto2743;
	_Context->msg_Auto2743[1]=fr_Auto2743;
	_Context->msg_Auto2743[2]=it_Auto2743;
	_Context->msg_Auto2743[3]=es_Auto2743;
	_Context->msg_Auto2743[4]=de_Auto2743;
	_Context->msg_Auto2743[5]=nl_Auto2743;
	_Context->msg_Auto2743[6]=pt_Auto2743;
	_Context->msg_Auto2743[7]=xx_Auto2743;
	_Context->hint_Auto2743[0]=en__Auto2743;
	_Context->hint_Auto2743[1]=fr__Auto2743;
	_Context->hint_Auto2743[2]=it__Auto2743;
	_Context->hint_Auto2743[3]=es__Auto2743;
	_Context->hint_Auto2743[4]=de__Auto2743;
	_Context->hint_Auto2743[5]=nl__Auto2743;
	_Context->hint_Auto2743[6]=pt__Auto2743;
	_Context->hint_Auto2743[7]=xx__Auto2743;
	for (i=0; i < 8; i++)_Context->msg_Auto2744[i]=" ";
	_Context->msg_Auto2744[0]=en_Auto2744;
	_Context->msg_Auto2744[1]=fr_Auto2744;
	_Context->msg_Auto2744[2]=it_Auto2744;
	_Context->msg_Auto2744[3]=es_Auto2744;
	_Context->msg_Auto2744[4]=de_Auto2744;
	_Context->msg_Auto2744[5]=nl_Auto2744;
	_Context->msg_Auto2744[6]=pt_Auto2744;
	_Context->msg_Auto2744[7]=xx_Auto2744;
	_Context->hint_Auto2744[0]=en__Auto2744;
	_Context->hint_Auto2744[1]=fr__Auto2744;
	_Context->hint_Auto2744[2]=it__Auto2744;
	_Context->hint_Auto2744[3]=es__Auto2744;
	_Context->hint_Auto2744[4]=de__Auto2744;
	_Context->hint_Auto2744[5]=nl__Auto2744;
	_Context->hint_Auto2744[6]=pt__Auto2744;
	_Context->hint_Auto2744[7]=xx__Auto2744;
	for (i=0; i < 8; i++)_Context->msg_Auto2745[i]=" ";
	_Context->msg_Auto2745[0]=en_Auto2745;
	_Context->msg_Auto2745[1]=fr_Auto2745;
	_Context->msg_Auto2745[2]=it_Auto2745;
	_Context->msg_Auto2745[3]=es_Auto2745;
	_Context->msg_Auto2745[4]=de_Auto2745;
	_Context->msg_Auto2745[5]=nl_Auto2745;
	_Context->msg_Auto2745[6]=pt_Auto2745;
	_Context->msg_Auto2745[7]=xx_Auto2745;
	_Context->hint_Auto2745[0]=en__Auto2745;
	_Context->hint_Auto2745[1]=fr__Auto2745;
	_Context->hint_Auto2745[2]=it__Auto2745;
	_Context->hint_Auto2745[3]=es__Auto2745;
	_Context->hint_Auto2745[4]=de__Auto2745;
	_Context->hint_Auto2745[5]=nl__Auto2745;
	_Context->hint_Auto2745[6]=pt__Auto2745;
	_Context->hint_Auto2745[7]=xx__Auto2745;
	for (i=0; i < 8; i++)_Context->msg_Auto2746[i]=" ";
	_Context->msg_Auto2746[0]=en_Auto2746;
	_Context->msg_Auto2746[1]=fr_Auto2746;
	_Context->msg_Auto2746[2]=it_Auto2746;
	_Context->msg_Auto2746[3]=es_Auto2746;
	_Context->msg_Auto2746[4]=de_Auto2746;
	_Context->msg_Auto2746[5]=nl_Auto2746;
	_Context->msg_Auto2746[6]=pt_Auto2746;
	_Context->msg_Auto2746[7]=xx_Auto2746;
	_Context->hint_Auto2746[0]=en__Auto2746;
	_Context->hint_Auto2746[1]=fr__Auto2746;
	_Context->hint_Auto2746[2]=it__Auto2746;
	_Context->hint_Auto2746[3]=es__Auto2746;
	_Context->hint_Auto2746[4]=de__Auto2746;
	_Context->hint_Auto2746[5]=nl__Auto2746;
	_Context->hint_Auto2746[6]=pt__Auto2746;
	_Context->hint_Auto2746[7]=xx__Auto2746;
	for (i=0; i < 8; i++)_Context->msg_Auto2747[i]=" ";
	_Context->hint_Auto2747[0]=en__Auto2747;
	_Context->hint_Auto2747[1]=fr__Auto2747;
	_Context->hint_Auto2747[2]=it__Auto2747;
	_Context->hint_Auto2747[3]=es__Auto2747;
	_Context->hint_Auto2747[4]=de__Auto2747;
	_Context->hint_Auto2747[5]=nl__Auto2747;
	_Context->hint_Auto2747[6]=pt__Auto2747;
	_Context->hint_Auto2747[7]=xx__Auto2747;
	return(0);
}

public 	int	accept_introduction_hide(struct accept_introduction_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	accept_introduction_remove(struct accept_introduction_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_introduction_show(struct accept_introduction_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	visual_window(170,90,460,420,vfh[2],_Context->msg_Auto2740[_Context->language],strlen(_Context->msg_Auto2740[_Context->language]),0x404);
	visual_filzone(172,92,456,416,7952,8);
	visual_image(198,194,382,262,_Context->msg_Auto2743[_Context->language],515);
	visual_image(208,100,400,120,_Context->msg_Auto2744[_Context->language],515);
	visual_text(232,472,336,32,vfh[2],168,0,_Context->msg_Auto2745[_Context->language],strlen(_Context->msg_Auto2745[_Context->language]),259);
	visual_text(274,414,240,30,vfh[6],47,0,_Context->msg_Auto2746[_Context->language],strlen(_Context->msg_Auto2746[_Context->language]),1283);
	visual_text(274,444,240,30,vfh[2],47,0,sing_version(),strlen(sing_version()),259);
	visual_thaw(170,90,460,420);

	return(0);
}
private int on_Auto2743_event(struct accept_introduction_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_introduction_event(
struct accept_introduction_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 198 ) 
	&&  ( my >= 194 ) 
	&&  ( mx <= 580 ) 
	&&  ( my <= 456 )) {
		return(1); /* Auto2743 */
		}

	return(-1);
}


public	int	accept_introduction_focus(struct accept_introduction_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto2743 */
				_Context->keycode = visual_getch();
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_introduction_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=1;
			accept_introduction_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_introduction_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2743 */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2743_event(_Context)) != -1) break;

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
				_Context->focus_item=1;
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

public	int	accept_introduction()
{
	int	status=0;
	struct accept_introduction_context * _Context=(struct accept_introduction_context*) 0;
	status = accept_introduction_create(&_Context);
	if ( status != 0) return(status);
	status = accept_introduction_show(_Context);
		enter_modal();
	status = accept_introduction_focus(_Context);
		leave_modal();
	status = accept_introduction_hide(_Context);
	status = accept_introduction_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vintro_c */
