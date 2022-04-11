
#ifndef _vrelate_c
#define _vrelate_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : vrelate.xml                                              */
/* Target         : vrelate.c                                                */
/* Identification : 0.0-1196372557-3079.3078                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_database_relation_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	x_Auto3330;
	int	y_Auto3330;
	int	w_Auto3330;
	int	h_Auto3330;
	char	buffer_Name[46];
	char	buffer_Jointure[46];
	int	value_sNature;
	int	value_tNature;
	char	buffer_SourceClass[46];
	char	buffer_SourceMember[46];
	char	buffer_TargetClass[46];
	char	buffer_TargetMember[46];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[9];
	};
static int	vfh[16];

public	int	accept_database_relation_create(
	struct accept_database_relation_context ** cptr,
	char * pName,
	char * pJointure,
	char * psNature,
	char * ptNature,
	char * pSourceClass,
	char * pSourceMember,
	char * pTargetClass,
	char * pTargetMember)
{

	int i;
	struct accept_database_relation_context * _Context=(struct accept_database_relation_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_database_relation_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=11;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Name, 45, pName);
		visual_transferin(_Context->buffer_Jointure, 45, pJointure);
		visual_transferin((void *) 0, 0, psNature);
		if (!( psNature )) _Context->value_sNature=0;
		else	_Context->value_sNature = *((int *)psNature);
		visual_transferin((void *) 0, 0, ptNature);
		if (!( ptNature )) _Context->value_tNature=0;
		else	_Context->value_tNature = *((int *)ptNature);
		visual_transferin(_Context->buffer_SourceClass, 45, pSourceClass);
		visual_transferin(_Context->buffer_SourceMember, 45, pSourceMember);
		visual_transferin(_Context->buffer_TargetClass, 45, pTargetClass);
		visual_transferin(_Context->buffer_TargetMember, 45, pTargetMember);
		}
	_Context->x_Auto3330=0;
	_Context->y_Auto3330=0;
	_Context->w_Auto3330=680;
	_Context->h_Auto3330=250;
	_Context->window_col=0;
	_Context->window_row=0;
	if(((_Context->y_Auto3330=visual_event(6))+250)>hardrows())
	_Context->y_Auto3330=(hardrows()-250);
	if(((_Context->x_Auto3330=visual_event(7))+680)>hardcolumns())
	_Context->x_Auto3330=(hardcolumns()-680);
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3330,_Context->y_Auto3330,680+10,250+10);
	return(0);
}

public 	int	accept_database_relation_hide(struct accept_database_relation_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3330,_Context->y_Auto3330);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_database_relation_remove(
	struct accept_database_relation_context * _Context,
	char * pName,
	char * pJointure,
	char * psNature,
	char * ptNature,
	char * pSourceClass,
	char * pSourceMember,
	char * pTargetClass,
	char * pTargetMember)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Name, 45, pName);
		visual_transferout(_Context->buffer_Jointure, 45, pJointure);
		visual_transferout((void *) 0, 0, psNature);
		if ( psNature != (char *) 0)
			*((int*)psNature) = _Context->value_sNature;
		visual_transferout((void *) 0, 0, ptNature);
		if ( ptNature != (char *) 0)
			*((int*)ptNature) = _Context->value_tNature;
		visual_transferout(_Context->buffer_SourceClass, 45, pSourceClass);
		visual_transferout(_Context->buffer_SourceMember, 45, pSourceMember);
		visual_transferout(_Context->buffer_TargetClass, 45, pTargetClass);
		visual_transferout(_Context->buffer_TargetMember, 45, pTargetMember);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_database_relation_show(struct accept_database_relation_context * _Context)
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3330,_Context->y_Auto3330);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3330,_Context->y_Auto3330,680,250,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3330,_Context->y_Auto3330,680,250,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x403);
		}
	visual_text(_Context->x_Auto3330+10,_Context->y_Auto3330+30,667,20,vfh[3],16,0,"Database File Relation",strlen("Database File Relation"),1283);
	visual_frame(_Context->x_Auto3330+10,_Context->y_Auto3330+50,660,180,4);
	visual_text(_Context->x_Auto3330+20,_Context->y_Auto3330+70,126,16,vfh[2],16,0,"Relation Name",strlen("Relation Name"),257);
	visual_text(_Context->x_Auto3330+20,_Context->y_Auto3330+90,126,16,vfh[2],16,0,"Jointure Name",strlen("Jointure Name"),257);
	visual_text(_Context->x_Auto3330+530,_Context->y_Auto3330+100,56,16,vfh[2],16,0,"Nature",strlen("Nature"),257);
	visual_text(_Context->x_Auto3330+530,_Context->y_Auto3330+160,56,16,vfh[2],16,0,"Nature",strlen("Nature"),257);
	visual_text(_Context->x_Auto3330+20,_Context->y_Auto3330+120,126,16,vfh[2],16,0,"Source Class",strlen("Source Class"),257);
	visual_text(_Context->x_Auto3330+20,_Context->y_Auto3330+140,126,16,vfh[2],16,0,"Member",strlen("Member"),257);
	visual_text(_Context->x_Auto3330+20,_Context->y_Auto3330+180,126,16,vfh[2],16,0,"Target Class",strlen("Target Class"),257);
	visual_text(_Context->x_Auto3330+20,_Context->y_Auto3330+200,126,16,vfh[2],16,0,"Member",strlen("Member"),257);
	visual_frame(_Context->x_Auto3330+160,_Context->y_Auto3330+70,360+2,16+2,5);
	visual_text(_Context->x_Auto3330+160+1,_Context->y_Auto3330+70+1,360,16,vfh[1],16,22,_Context->buffer_Name,45,0);
	visual_frame(_Context->x_Auto3330+160,_Context->y_Auto3330+90,360+2,16+2,5);
	visual_text(_Context->x_Auto3330+160+1,_Context->y_Auto3330+90+1,360,16,vfh[1],16,22,_Context->buffer_Jointure,45,0);
	visual_select(_Context->x_Auto3330+530,_Context->y_Auto3330+120,56,64,vfh[2],27,28,parse_selection("0/1|1/1|0/N|1/N",&_Context->value_sNature),768);
	visual_select(_Context->x_Auto3330+530,_Context->y_Auto3330+180,56,64,vfh[2],27,28,parse_selection("0/1|1/1|0/N|1/N",&_Context->value_tNature),768);
	visual_frame(_Context->x_Auto3330+160,_Context->y_Auto3330+120,360+2,16+2,5);
	visual_text(_Context->x_Auto3330+160+1,_Context->y_Auto3330+120+1,360,16,vfh[1],16,22,_Context->buffer_SourceClass,45,0);
	visual_frame(_Context->x_Auto3330+160,_Context->y_Auto3330+140,360+2,16+2,5);
	visual_text(_Context->x_Auto3330+160+1,_Context->y_Auto3330+140+1,360,16,vfh[1],16,22,_Context->buffer_SourceMember,45,0);
	visual_frame(_Context->x_Auto3330+160,_Context->y_Auto3330+180,360+2,16+2,5);
	visual_text(_Context->x_Auto3330+160+1,_Context->y_Auto3330+180+1,360,16,vfh[1],27,22,_Context->buffer_TargetClass,45,0);
	visual_frame(_Context->x_Auto3330+160,_Context->y_Auto3330+200,360+2,16+2,5);
	visual_text(_Context->x_Auto3330+160+1,_Context->y_Auto3330+200+1,360,16,vfh[1],16,22,_Context->buffer_TargetMember,45,0);
	visual_button(_Context->x_Auto3330+610,_Context->y_Auto3330+80,48,48,vfh[1],27,28,"ok.gif",strlen("ok.gif"),1040);
	visual_button(_Context->x_Auto3330+610,_Context->y_Auto3330+150,48,48,vfh[1],27,28,"cancel.gif",strlen("cancel.gif"),1040);
	visual_thaw(_Context->x_Auto3330,_Context->y_Auto3330,680,250);

	return(0);
}

private int Auto3330action(struct accept_database_relation_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_database_relation_hide(_Context);

		_Context->x_Auto3330 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3330 < 0) { _Context->x_Auto3330=0; }
		_Context->y_Auto3330 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3330 < 0) { _Context->y_Auto3330=0; }
			accept_database_relation_show(_Context);

		visual_thaw(_Context->x_Auto3330,_Context->y_Auto3330,680,250);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_database_relation_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_database_relation_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_database_relation_event(
struct accept_database_relation_context * _Context){
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3330+659) )  
	&&  (my >= (_Context->y_Auto3330+4) )  
	&&  (mx <= (_Context->x_Auto3330+676) )  
	&&  (my <= (_Context->y_Auto3330+20) )) {
		return(1);	/* Auto3330 */

		}
	if ((mx >= (_Context->x_Auto3330+643) )  
	&&  (my >= (_Context->y_Auto3330+4) )  
	&&  (mx <= (_Context->x_Auto3330+660) )  
	&&  (my <= (_Context->y_Auto3330+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vrelate.htm");
			};
		return(-1);	/* Auto3330 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3330+4) )  
		&&  (my >= (_Context->y_Auto3330+4) )  
		&&  (mx <= (_Context->x_Auto3330+612) )  
		&&  (my <= (_Context->y_Auto3330+20) )) {
			return( Auto3330action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3330+160) ) 
	&&  ( my >= (_Context->y_Auto3330+70) ) 
	&&  ( mx <= (_Context->x_Auto3330+160+360) ) 
	&&  ( my <= (_Context->y_Auto3330+70+16))) {
		return(2); /* Name */
		}
	if (( mx >= (_Context->x_Auto3330+160) ) 
	&&  ( my >= (_Context->y_Auto3330+90) ) 
	&&  ( mx <= (_Context->x_Auto3330+160+360) ) 
	&&  ( my <= (_Context->y_Auto3330+90+16))) {
		return(3); /* Jointure */
		}
	if (( mx >= (_Context->x_Auto3330+530+0) ) 
	&&  ( my >= (_Context->y_Auto3330+120) ) 
	&&  ( mx <= (_Context->x_Auto3330+530+56) ) 
	&&  ( my <= (_Context->y_Auto3330+120+16))) {
		return(4); /* sNature */
		}
	if (( mx >= (_Context->x_Auto3330+530+0) ) 
	&&  ( my >= (_Context->y_Auto3330+180) ) 
	&&  ( mx <= (_Context->x_Auto3330+530+56) ) 
	&&  ( my <= (_Context->y_Auto3330+180+16))) {
		return(5); /* tNature */
		}
	if (( mx >= (_Context->x_Auto3330+160) ) 
	&&  ( my >= (_Context->y_Auto3330+120) ) 
	&&  ( mx <= (_Context->x_Auto3330+160+360) ) 
	&&  ( my <= (_Context->y_Auto3330+120+16))) {
		return(6); /* SourceClass */
		}
	if (( mx >= (_Context->x_Auto3330+160) ) 
	&&  ( my >= (_Context->y_Auto3330+140) ) 
	&&  ( mx <= (_Context->x_Auto3330+160+360) ) 
	&&  ( my <= (_Context->y_Auto3330+140+16))) {
		return(7); /* SourceMember */
		}
	if (( mx >= (_Context->x_Auto3330+160) ) 
	&&  ( my >= (_Context->y_Auto3330+180) ) 
	&&  ( mx <= (_Context->x_Auto3330+160+360) ) 
	&&  ( my <= (_Context->y_Auto3330+180+16))) {
		return(8); /* TargetClass */
		}
	if (( mx >= (_Context->x_Auto3330+160) ) 
	&&  ( my >= (_Context->y_Auto3330+200) ) 
	&&  ( mx <= (_Context->x_Auto3330+160+360) ) 
	&&  ( my <= (_Context->y_Auto3330+200+16))) {
		return(9); /* TargetMember */
		}
	if (( mx >= (_Context->x_Auto3330+610) ) 
	&&  ( my >= (_Context->y_Auto3330+80) ) 
	&&  ( mx <= (_Context->x_Auto3330+610+48) ) 
	&&  ( my <= (_Context->y_Auto3330+80+48))) {
		return(10); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3330+610) ) 
	&&  ( my >= (_Context->y_Auto3330+150) ) 
	&&  ( mx <= (_Context->x_Auto3330+610+48) ) 
	&&  ( my <= (_Context->y_Auto3330+150+48))) {
		return(11); /* Cancel */
		}

	return(-1);
}
private int on_Name_losefocus(struct accept_database_relation_context * _Context) {
	visual_frame(_Context->x_Auto3330+160,_Context->y_Auto3330+70,360+2,16+2,5);
visual_text(_Context->x_Auto3330+160+1,_Context->y_Auto3330+70+1,360,16,vfh[1],16,22,_Context->buffer_Name,45,0);
;
	return(-1);
}


public	int	accept_database_relation_focus(struct accept_database_relation_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Name */
				_Context->keycode = visual_edit(_Context->x_Auto3330+160+1,_Context->y_Auto3330+70+1,360,16,vfh[1],_Context->buffer_Name,45);
				(void) on_Name_losefocus(_Context);
			break;
			case	0x3 :
				/* Jointure */
				_Context->keycode = visual_edit(_Context->x_Auto3330+160+1,_Context->y_Auto3330+90+1,360,16,vfh[1],_Context->buffer_Jointure,45);
			break;
			case	0x4 :
				/* sNature */
				_Context->keycode = visual_select(_Context->x_Auto3330+530,_Context->y_Auto3330+120,56,64,vfh[2],27,28,parse_selection("0/1|1/1|0/N|1/N",&_Context->value_sNature),770);
				break;
			case	0x5 :
				/* tNature */
				_Context->keycode = visual_select(_Context->x_Auto3330+530,_Context->y_Auto3330+180,56,64,vfh[2],27,28,parse_selection("0/1|1/1|0/N|1/N",&_Context->value_tNature),770);
				break;
			case	0xa :
				/* Accept */
				visual_button(_Context->x_Auto3330+610,_Context->y_Auto3330+80,48,48,vfh[1],27,28,"ok.gif",strlen("ok.gif"),1042);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto3330+610,_Context->y_Auto3330+80,48,48,vfh[1],27,28,"ok.gif",strlen("ok.gif"),1040);
				break;
			case	0xb :
				/* Cancel */
				visual_button(_Context->x_Auto3330+610,_Context->y_Auto3330+150,48,48,vfh[1],27,28,"cancel.gif",strlen("cancel.gif"),1042);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto3330+610,_Context->y_Auto3330+150,48,48,vfh[1],27,28,"cancel.gif",strlen("cancel.gif"),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_database_relation_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=11;
			accept_database_relation_show(_Context);
			continue;
		case	0x100 :
			if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_Auto3330 )
				|| ( visual_event(6) < _Context->y_Auto3330  )
				|| ( visual_event(7) > (_Context->x_Auto3330+_Context->w_Auto3330))
				|| ( visual_event(6) >  (_Context->y_Auto3330+_Context->h_Auto3330))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=accept_database_relation_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3330 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Name */
					continue;
				case	0x3 :
					/* Jointure */
					continue;
				case	0x4 :
					/* sNature */
					continue;
				case	0x5 :
					/* tNature */
					continue;
				case	0x6 :
					/* SourceClass */
					continue;
				case	0x7 :
					/* SourceMember */
					continue;
				case	0x8 :
					/* TargetClass */
					continue;
				case	0x9 :
					/* TargetMember */
					continue;
				case	0xa :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto3330+610,_Context->y_Auto3330+80,48,48,vfh[1],27,28,"ok.gif",strlen("ok.gif"),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto3330+610,_Context->y_Auto3330+80,48,48,vfh[1],27,28,"ok.gif",strlen("ok.gif"),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto3330+610,_Context->y_Auto3330+150,48,48,vfh[1],27,28,"cancel.gif",strlen("cancel.gif"),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto3330+610,_Context->y_Auto3330+150,48,48,vfh[1],27,28,"cancel.gif",strlen("cancel.gif"),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

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
				_Context->focus_item=11;
			}
			continue;
		case	0x0 :
			
			continue;
		case	0xffffffff :
			
			continue;

			}
		break;
		}

	return( _Context->keycode );
}

public	int	accept_database_relation(
	char * pName,
	char * pJointure,
	char * psNature,
	char * ptNature,
	char * pSourceClass,
	char * pSourceMember,
	char * pTargetClass,
	char * pTargetMember)
{
	int	status=0;
	struct accept_database_relation_context * _Context=(struct accept_database_relation_context*) 0;
	status = accept_database_relation_create(
	&_Context,
	 pName,
	 pJointure,
	 psNature,
	 ptNature,
	 pSourceClass,
	 pSourceMember,
	 pTargetClass,
	 pTargetMember);
	if ( status != 0) return(status);
	status = accept_database_relation_show(_Context);
		enter_modal();
	status = accept_database_relation_focus(_Context);
		leave_modal();
	status = accept_database_relation_hide(_Context);
	status = accept_database_relation_remove(
	_Context,
	 pName,
	 pJointure,
	 psNature,
	 ptNature,
	 pSourceClass,
	 pSourceMember,
	 pTargetClass,
	 pTargetMember);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vrelate_c */
