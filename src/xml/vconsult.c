
#ifndef _vconsult_c
#define _vconsult_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vconsult.xml                                             */
/* Target         : vconsult.c                                               */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "vconsultp.h"
#define en__Auto3641   ""
#define fr__Auto3641   ""
#define it__Auto3641   ""
#define es__Auto3641   ""
#define de__Auto3641   ""
#define nl__Auto3641   ""
#define pt__Auto3641   ""
#define xx__Auto3641   ""
#define en_Auto3642   "ok.gif"
#define fr_Auto3642   "ok.gif"
#define it_Auto3642   "ok.gif"
#define es_Auto3642   "ok.gif"
#define de_Auto3642   "ok.gif"
#define nl_Auto3642   "ok.gif"
#define pt_Auto3642   "ok.gif"
#define xx_Auto3642   "ok.gif"
#define en__Auto3642   ""
#define fr__Auto3642   ""
#define it__Auto3642   ""
#define es__Auto3642   ""
#define de__Auto3642   ""
#define nl__Auto3642   ""
#define pt__Auto3642   ""
#define xx__Auto3642   ""
#define en_Contenu   ""
#define en__Contenu   ""
#define en__HScroll   ""
#define en__VScroll   ""

private struct accept_consult_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3641[8];
	char * hint_Auto3641[8];
	int	x_Auto3641;
	int	y_Auto3641;
	int	w_Auto3641;
	int	h_Auto3641;
	char * msg_Auto3642[8];
	int	trigger_Auto3642;
	char * hint_Auto3642[8];
	char * hint_Contenu[8];
	char	buffer_Contenu[1351];
	char * hint_HScroll[8];
	int	value_HScroll;
	int	limit_HScroll;
	int	max_HScroll;
	char * hint_VScroll[8];
	int	value_VScroll;
	int	limit_VScroll;
	int	max_VScroll;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];
private int on_Contenu_show(struct accept_consult_context * _Context);
private int on_Auto3642_event(struct accept_consult_context * _Context);

public	int	accept_consult_create(struct accept_consult_context **cptr)
{

	int i;
	struct accept_consult_context * _Context=(struct accept_consult_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_consult_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
		for (i=0; i < 1350; i++)  *(_Context->buffer_Contenu+i)=' ';
		_Context->max_HScroll=0;
		_Context->limit_HScroll=0;
		_Context->value_HScroll=0;
		_Context->max_VScroll=0;
		_Context->limit_VScroll=0;
		_Context->value_VScroll=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3641[i]=" ";
	_Context->hint_Auto3641[0]=en__Auto3641;
	_Context->hint_Auto3641[1]=fr__Auto3641;
	_Context->hint_Auto3641[2]=it__Auto3641;
	_Context->hint_Auto3641[3]=es__Auto3641;
	_Context->hint_Auto3641[4]=de__Auto3641;
	_Context->hint_Auto3641[5]=nl__Auto3641;
	_Context->hint_Auto3641[6]=pt__Auto3641;
	_Context->hint_Auto3641[7]=xx__Auto3641;
	_Context->x_Auto3641=80;
	_Context->y_Auto3641=85;
	_Context->w_Auto3641=640;
	_Context->h_Auto3641=430;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3642[i]=" ";
	_Context->msg_Auto3642[0]=en_Auto3642;
	_Context->msg_Auto3642[1]=fr_Auto3642;
	_Context->msg_Auto3642[2]=it_Auto3642;
	_Context->msg_Auto3642[3]=es_Auto3642;
	_Context->msg_Auto3642[4]=de_Auto3642;
	_Context->msg_Auto3642[5]=nl_Auto3642;
	_Context->msg_Auto3642[6]=pt_Auto3642;
	_Context->msg_Auto3642[7]=xx_Auto3642;
	_Context->hint_Auto3642[0]=en__Auto3642;
	_Context->hint_Auto3642[1]=fr__Auto3642;
	_Context->hint_Auto3642[2]=it__Auto3642;
	_Context->hint_Auto3642[3]=es__Auto3642;
	_Context->hint_Auto3642[4]=de__Auto3642;
	_Context->hint_Auto3642[5]=nl__Auto3642;
	_Context->hint_Auto3642[6]=pt__Auto3642;
	_Context->hint_Auto3642[7]=xx__Auto3642;
	_Context->hint_Contenu[0]=en__Contenu;
	fConsult=(FILE*)0;
	_Context->hint_HScroll[0]=en__HScroll;
	_Context->max_HScroll=1;
	_Context->value_HScroll=1;
	_Context->limit_HScroll=1;
	_Context->limit_HScroll=18;
	_Context->max_HScroll=HMaxConsult;
	_Context->value_HScroll=0;
	_Context->hint_VScroll[0]=en__VScroll;
	_Context->max_VScroll=1;
	_Context->value_VScroll=1;
	_Context->limit_VScroll=1;
	_Context->limit_VScroll=75;
	_Context->max_VScroll=LMaxConsult;
	_Context->value_VScroll=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3641,_Context->y_Auto3641,640+10,430+10);
	return(0);
}

public 	int	accept_consult_hide(struct accept_consult_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3641,_Context->y_Auto3641);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_consult_remove(struct accept_consult_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Contenu_show(struct accept_consult_context * _Context) {
	int i,j,l;
	char t[1024];
	memset(_Context->buffer_Contenu,' ',1350);
	if(fConsult==NULL)
	fConsult=fopen(FileNameConsult,"r");
	fseek(fConsult,0,SEEK_SET);
	i=0;
	while(i++<_Context->value_HScroll)fgets(t,1023,fConsult);
	for(i=0;i<18;i++)
	{
	t[0]=0;
	fgets(t,1023,fConsult);
	if(_Context->value_VScroll)
	{
	if(_Context->value_VScroll>(int)strlen(t))
	t[0]=0;
	else
	strcpy(t,&t[_Context->value_VScroll]);
	};
	if((int)strlen(t)<75)
	l=strlen(t);
	else
	l=75;
	for(j=0;j<l;j++)if(t[j]<' ')t[j]=' ';
	memcpy(&_Context->buffer_Contenu[i*75],t,l);
	};
	visual_frame(_Context->x_Auto3641+10,_Context->y_Auto3641+30,600+2,300+2,5);
visual_text(_Context->x_Auto3641+10+1,_Context->y_Auto3641+30+1,600,300,vfh[1],0,0,_Context->buffer_Contenu,1350,0);
;
	return(-1);
}

public	int	accept_consult_show(struct accept_consult_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3641,_Context->y_Auto3641);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3641,_Context->y_Auto3641,640,430,GetWidgetStyle(0),FileNameConsult,strlen(FileNameConsult))) != 0)
) {
		visual_window(_Context->x_Auto3641,_Context->y_Auto3641,640,430,vfh[2],FileNameConsult,strlen(FileNameConsult),0x407);
		}
	_Context->trigger_Auto3642=visual_trigger_code(_Context->msg_Auto3642[_Context->language],strlen(_Context->msg_Auto3642[_Context->language]));
	visual_button(_Context->x_Auto3641+290,_Context->y_Auto3641+360,56,48,vfh[2],34,0,_Context->msg_Auto3642[_Context->language],strlen(_Context->msg_Auto3642[_Context->language]),1040);
	(void) on_Contenu_show(_Context);
	visual_scrollbar(_Context->x_Auto3641+610,_Context->y_Auto3641+30,20,300,vfh[1],0,0,_Context->value_HScroll,_Context->limit_HScroll,_Context->max_HScroll,259);
	visual_scrollbar(_Context->x_Auto3641+10,_Context->y_Auto3641+330,600,20,vfh[1],0,0,_Context->value_VScroll,_Context->limit_VScroll,_Context->max_VScroll,259);
	visual_thaw(_Context->x_Auto3641,_Context->y_Auto3641,640,430);

	return(0);
}

private int Auto3641action(struct accept_consult_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_consult_hide(_Context);

		_Context->x_Auto3641 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3641 < 0) { _Context->x_Auto3641=0; }
		_Context->y_Auto3641 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3641 < 0) { _Context->y_Auto3641=0; }
			accept_consult_show(_Context);

		visual_thaw(_Context->x_Auto3641,_Context->y_Auto3641,640,430);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3642_event(struct accept_consult_context * _Context) {
	if(fConsult!=NULL)
	{
	fclose(fConsult);
	fConsult=NULL;
	};
	return(13);
	return(-1);
}

private int on_HScroll_action(struct accept_consult_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto3641+30+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_HScroll -= 1;
		if (_Context->value_HScroll < 0) 
			_Context->value_HScroll = 0;
	status = accept_consult_show(_Context);
	visual_scrollbar(_Context->x_Auto3641+610,_Context->y_Auto3641+30,20,300,vfh[1],0,0,_Context->value_HScroll,_Context->limit_HScroll,_Context->max_HScroll,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto3641+30+300-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_HScroll += 1;
		if (!(_Context->max_HScroll))
			_Context->value_HScroll = 0;
		else if ((_Context->max_HScroll < _Context->limit_HScroll) 
		&& (_Context->value_HScroll >= _Context->max_HScroll)) 
			_Context->value_HScroll = (_Context->max_HScroll-1);
		else if (_Context->value_HScroll > (_Context->max_HScroll-_Context->limit_HScroll)) 
			_Context->value_HScroll = (_Context->max_HScroll-_Context->limit_HScroll);
	status = accept_consult_show(_Context);
	visual_scrollbar(_Context->x_Auto3641+610,_Context->y_Auto3641+30,20,300,vfh[1],0,0,_Context->value_HScroll,_Context->limit_HScroll,_Context->max_HScroll,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto3641+610,_Context->y_Auto3641+30,20,300,vfh[1],0,0,_Context->value_HScroll,_Context->limit_HScroll,_Context->max_HScroll,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_HScroll;
		_Context->value_HScroll = (((visual_event(6) - (_Context->y_Auto3641+30+20)) * _Context->max_HScroll) / (300 - (2 * 20)));
		if (_Context->value_HScroll < 0) 
			_Context->value_HScroll = 0;
		else if (_Context->value_HScroll > (_Context->max_HScroll-_Context->limit_HScroll)) 
			_Context->value_HScroll = (_Context->max_HScroll-_Context->limit_HScroll);
		if (_Context->value_HScroll != aty) {
	status = accept_consult_show(_Context);
	visual_scrollbar(_Context->x_Auto3641+610,_Context->y_Auto3641+30,20,300,vfh[1],0,0,_Context->value_HScroll,_Context->limit_HScroll,_Context->max_HScroll,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_HScroll -= (_Context->limit_HScroll/2);
			if (_Context->value_HScroll < 0) 
				_Context->value_HScroll = 0;
	status = accept_consult_show(_Context);
	visual_scrollbar(_Context->x_Auto3641+610,_Context->y_Auto3641+30,20,300,vfh[1],0,0,_Context->value_HScroll,_Context->limit_HScroll,_Context->max_HScroll,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_HScroll += (_Context->limit_HScroll/2);
			if (!(_Context->max_HScroll))
				_Context->value_HScroll = 0;
			else if ((_Context->max_HScroll < _Context->limit_HScroll) 
			&& (_Context->value_HScroll >= _Context->max_HScroll)) 
				_Context->value_HScroll = (_Context->max_HScroll-1);
			else if (_Context->value_HScroll > (_Context->max_HScroll-_Context->limit_HScroll)) 
				_Context->value_HScroll = (_Context->max_HScroll-_Context->limit_HScroll);
	status = accept_consult_show(_Context);
	visual_scrollbar(_Context->x_Auto3641+610,_Context->y_Auto3641+30,20,300,vfh[1],0,0,_Context->value_HScroll,_Context->limit_HScroll,_Context->max_HScroll,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto3641+610,_Context->y_Auto3641+30,20,300,vfh[1],0,0,_Context->value_HScroll,_Context->limit_HScroll,_Context->max_HScroll,259);

	return(1);
}

private int on_VScroll_action(struct accept_consult_context * _Context) {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (_Context->x_Auto3641+10+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_VScroll -= 1;
		if (_Context->value_VScroll < 0) 
			_Context->value_VScroll = 0;
	status = accept_consult_show(_Context);
	visual_scrollbar(_Context->x_Auto3641+10,_Context->y_Auto3641+330,600,20,vfh[1],0,0,_Context->value_VScroll,_Context->limit_VScroll,_Context->max_VScroll,259);
		return(-1);
		}
	if ( visual_event(7) > (_Context->x_Auto3641+10+600-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_VScroll += 1;
		if (!(_Context->max_VScroll))
			_Context->value_VScroll = 0;
		else if ((_Context->max_VScroll < _Context->limit_VScroll) 
		&& (_Context->value_VScroll >= _Context->max_VScroll)) 
			_Context->value_VScroll = (_Context->max_VScroll-1);
		else if (_Context->value_VScroll > (_Context->max_VScroll-_Context->limit_VScroll)) 
			_Context->value_VScroll = (_Context->max_VScroll-_Context->limit_VScroll);
	status = accept_consult_show(_Context);
	visual_scrollbar(_Context->x_Auto3641+10,_Context->y_Auto3641+330,600,20,vfh[1],0,0,_Context->value_VScroll,_Context->limit_VScroll,_Context->max_VScroll,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto3641+10,_Context->y_Auto3641+330,600,20,vfh[1],0,0,_Context->value_VScroll,_Context->limit_VScroll,_Context->max_VScroll,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		atx = _Context->value_VScroll;
		_Context->value_VScroll = (((visual_event(7) - (_Context->x_Auto3641+10+20)) * _Context->max_VScroll) / (600 - (2 * 20)));
		if (_Context->value_VScroll < 0) 
			_Context->value_VScroll = 0;
		else if (_Context->value_VScroll > (_Context->max_VScroll-_Context->limit_VScroll)) 
			_Context->value_VScroll = (_Context->max_VScroll-_Context->limit_VScroll);
		if (_Context->value_VScroll != atx) {
	status = accept_consult_show(_Context);
	visual_scrollbar(_Context->x_Auto3641+10,_Context->y_Auto3641+330,600,20,vfh[1],0,0,_Context->value_VScroll,_Context->limit_VScroll,_Context->max_VScroll,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_VScroll -= (_Context->limit_VScroll/2);
			if (_Context->value_VScroll < 0) 
				_Context->value_VScroll = 0;
	status = accept_consult_show(_Context);
	visual_scrollbar(_Context->x_Auto3641+10,_Context->y_Auto3641+330,600,20,vfh[1],0,0,_Context->value_VScroll,_Context->limit_VScroll,_Context->max_VScroll,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_VScroll += (_Context->limit_VScroll/2);
			if (!(_Context->max_VScroll))
				_Context->value_VScroll = 0;
			else if ((_Context->max_VScroll < _Context->limit_VScroll) 
			&& (_Context->value_VScroll >= _Context->max_VScroll)) 
				_Context->value_VScroll = (_Context->max_VScroll-1);
			else if (_Context->value_VScroll > (_Context->max_VScroll-_Context->limit_VScroll)) 
				_Context->value_VScroll = (_Context->max_VScroll-_Context->limit_VScroll);
	status = accept_consult_show(_Context);
	visual_scrollbar(_Context->x_Auto3641+10,_Context->y_Auto3641+330,600,20,vfh[1],0,0,_Context->value_VScroll,_Context->limit_VScroll,_Context->max_VScroll,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto3641+10,_Context->y_Auto3641+330,600,20,vfh[1],0,0,_Context->value_VScroll,_Context->limit_VScroll,_Context->max_VScroll,259);

	return(1);
}


public	int	accept_consult_event(
struct accept_consult_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3642 == mb ) return(2);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3641+619) )  
	&&  (my >= (_Context->y_Auto3641+4) )  
	&&  (mx <= (_Context->x_Auto3641+636) )  
	&&  (my <= (_Context->y_Auto3641+20) )) {
		return(1);	/* Auto3641 */

		}
	if ((mx >= (_Context->x_Auto3641+603) )  
	&&  (my >= (_Context->y_Auto3641+4) )  
	&&  (mx <= (_Context->x_Auto3641+620) )  
	&&  (my <= (_Context->y_Auto3641+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vconsult.htm");
			};
		return(-1);	/* Auto3641 */

		}
	if ((mx >= (_Context->x_Auto3641+587) )  
	&&  (my >= (_Context->y_Auto3641+4) )  
	&&  (mx <= (_Context->x_Auto3641+604) )  
	&&  (my <= (_Context->y_Auto3641+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_consult_show(_Context);
		return(-1);	/* Auto3641 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3641+4) )  
		&&  (my >= (_Context->y_Auto3641+4) )  
		&&  (mx <= (_Context->x_Auto3641+572) )  
		&&  (my <= (_Context->y_Auto3641+20) )) {
			return( Auto3641action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3641+290) ) 
	&&  ( my >= (_Context->y_Auto3641+360) ) 
	&&  ( mx <= (_Context->x_Auto3641+290+56) ) 
	&&  ( my <= (_Context->y_Auto3641+360+48))) {
		return(2); /* Auto3642 */
		}
	if (( mx >= (_Context->x_Auto3641+610) ) 
	&&  ( my >= (_Context->y_Auto3641+30) ) 
	&&  ( mx <= (_Context->x_Auto3641+610+20) ) 
	&&  ( my <= (_Context->y_Auto3641+30+300))) {
		return(3); /* HScroll */
		}
	if (( mx >= (_Context->x_Auto3641+10) ) 
	&&  ( my >= (_Context->y_Auto3641+330) ) 
	&&  ( mx <= (_Context->x_Auto3641+10+600) ) 
	&&  ( my <= (_Context->y_Auto3641+330+20))) {
		return(4); /* VScroll */
		}

	return(-1);
}


public	int	accept_consult_focus(struct accept_consult_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto3642 */
				_Context->trigger_Auto3642=visual_trigger_code(_Context->msg_Auto3642[_Context->language],strlen(_Context->msg_Auto3642[_Context->language]));
				visual_button(_Context->x_Auto3641+290,_Context->y_Auto3641+360,56,48,vfh[2],34,0,_Context->msg_Auto3642[_Context->language],strlen(_Context->msg_Auto3642[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3642=visual_trigger_code(_Context->msg_Auto3642[_Context->language],strlen(_Context->msg_Auto3642[_Context->language]));
	visual_button(_Context->x_Auto3641+290,_Context->y_Auto3641+360,56,48,vfh[2],34,0,_Context->msg_Auto3642[_Context->language],strlen(_Context->msg_Auto3642[_Context->language]),1040);
				break;
			case	0x3 :
				/* HScroll */
				_Context->keycode=visual_getch();
				break;
			case	0x4 :
				/* VScroll */
				_Context->keycode=visual_getch();
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_consult_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=4;
			accept_consult_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_consult_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3641 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto3642 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3642=visual_trigger_code(_Context->msg_Auto3642[_Context->language],strlen(_Context->msg_Auto3642[_Context->language]));
						visual_button(_Context->x_Auto3641+290,_Context->y_Auto3641+360,56,48,vfh[2],34,0,_Context->msg_Auto3642[_Context->language],strlen(_Context->msg_Auto3642[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3642=visual_trigger_code(_Context->msg_Auto3642[_Context->language],strlen(_Context->msg_Auto3642[_Context->language]));
	visual_button(_Context->x_Auto3641+290,_Context->y_Auto3641+360,56,48,vfh[2],34,0,_Context->msg_Auto3642[_Context->language],strlen(_Context->msg_Auto3642[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3642_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* HScroll */
					(void) on_HScroll_action(_Context);
					continue;
				case	0x4 :
					/* VScroll */
					(void) on_VScroll_action(_Context);
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
				_Context->focus_item=4;
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

public	int	accept_consult()
{
	int	status=0;
	struct accept_consult_context * _Context=(struct accept_consult_context*) 0;
	status = accept_consult_create(&_Context);
	if ( status != 0) return(status);
	status = accept_consult_show(_Context);
		enter_modal();
	status = accept_consult_focus(_Context);
		leave_modal();
	status = accept_consult_hide(_Context);
	status = accept_consult_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vconsult_c */
