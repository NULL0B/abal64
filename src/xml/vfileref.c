
#ifndef _vfileref_c
#define _vfileref_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vfileref.xml                                             */
/* Target         : vfileref.c                                               */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3555   ""
#define fr__Auto3555   ""
#define it__Auto3555   ""
#define es__Auto3555   ""
#define de__Auto3555   ""
#define nl__Auto3555   ""
#define pt__Auto3555   ""
#define xx__Auto3555   ""
#define en_Auto3556   "File References"
#define fr_Auto3556   "Instances du fichier"
#define it_Auto3556   "File References"
#define es_Auto3556   "File References"
#define de_Auto3556   "File References"
#define nl_Auto3556   "File References"
#define pt_Auto3556   "File References"
#define xx_Auto3556   "File References"
#define en_Auto3557   "Class"
#define fr_Auto3557   "Nom"
#define it_Auto3557   "Nom"
#define es_Auto3557   "Name"
#define de_Auto3557   "Name"
#define nl_Auto3557   "Name"
#define pt_Auto3557   "Name"
#define xx_Auto3557   "Ainm"
#define en_Target   ""
#define en_RefList   "Forms Model"
#define fr_RefList   "Formulaires"
#define it_RefList   "Forms Model"
#define es_RefList   "Forms Model"
#define de_RefList   "Forms Model"
#define nl_RefList   "Forms Model"
#define pt_RefList   "Forms Model"
#define xx_RefList   "Forms Model"
#define en__RefList   ""
#define en_RefBar   ""

private struct file_reference_locator_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3555[8];
	char * hint_Auto3555[8];
	int	x_Auto3555;
	int	y_Auto3555;
	int	w_Auto3555;
	int	h_Auto3555;
	char * msg_Auto3556[8];
	char * hint_Auto3556[8];
	char * msg_Auto3557[8];
	char * hint_Auto3557[8];
	char * hint_Target[8];
	char	buffer_Target[256];
	char * msg_RefList[8];
	char * hint_RefList[8];
	int	value_RefList;
	int	column_RefList;
	char	buffer_RefList[32][40];
	int	formsort_RefList;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char	*libsort_RefList;	/* table intermédiaire contenant la liste des éléments a trier */
	int	*tabsort_RefList;	/* numéro d'ordre des elements triés */
	char	*indsort_RefList;	/* pointeur table intermédiaire de tri */
	int	nelt_RefList;	/* nombre d'eléments aloués dans tabsort */
	char * row_RefList;
	char * hint_RefBar[8];
	int	value_RefBar;
	int	limit_RefBar;
	int	max_RefBar;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];
private int on_RefList_show(struct file_reference_locator_context * _Context);
private int on_Target_getfocus(struct file_reference_locator_context * _Context);
private int on_RefList_event(struct file_reference_locator_context * _Context);
private int on_RefBar_event(struct file_reference_locator_context * _Context);
private int  sort_item_RefList(struct file_reference_locator_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_RefList(struct file_reference_locator_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_RefList(struct file_reference_locator_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_RefList */
private int compare_RefList(struct file_reference_locator_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_RefList */
/* ------------------- */
/* resolve sorted item */
/* ------------------- */
private int  sort_item_RefList(struct file_reference_locator_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_RefList[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_RefList(struct file_reference_locator_context * _Context,int nelts)
{
if (_Context->nelt_RefList<nelts) {
	liberate(_Context->tabsort_RefList);
	if ((_Context->tabsort_RefList=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_RefList=0;_Context->nelt_RefList<nelts;_Context->nelt_RefList++)
		{ _Context->tabsort_RefList[_Context->nelt_RefList]=_Context->nelt_RefList+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_RefList=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_RefList=allocate(nelts*40)) != NULL)
	memset(_Context->libsort_RefList,' ',nelts*40);
}

/* ---------------------------------------------------------- */
/* sort the intermediate table into _Context->tabsort_RefList */
/* ---------------------------------------------------------- */
private void sort_RefList(struct file_reference_locator_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_RefList,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_RefList[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_RefList[j]) && (compare_RefList(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_RefList[i]=k+1;
	_Context->indsort_RefList[k]=1;
	};	/* for i */
liberate(_Context->libsort_RefList);
liberate(_Context->indsort_RefList);
}

/* -------------------------------------------------------- */
/* compare the elements a et b of _Context->libsort_RefList */
/* -------------------------------------------------------- */
private int compare_RefList(struct file_reference_locator_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_RefList[40*a],&_Context->libsort_RefList[40*b],40);	/* comparaison zone 1 */
switch (_Context->formsort_RefList) {
	case 1:	/* Forms Model ordre normal */
		return(i);

	case -1:	/* Forms Model ordre inverse */
		return(-i);
	default:		/* pas de tri */
		if (a<b) return(-1);
		return(1);
	}; /* fin du switch */
}


public	int	file_reference_locator_create(
	struct file_reference_locator_context ** cptr,
	char * pTarget)
{

	int i;
	struct file_reference_locator_context * _Context=(struct file_reference_locator_context*)0;
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
	if (!(_Context = allocate( sizeof( struct file_reference_locator_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
	_Context->formsort_RefList=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_RefList=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_RefList=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_RefList=0;_Context->nelt_RefList<512;_Context->nelt_RefList++)
			{ _Context->tabsort_RefList[_Context->nelt_RefList]=_Context->nelt_RefList+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_RefList=0; /* si problème d'allocation */
_Context->indsort_RefList=NULL;	/* pas de pointeur de table intermédiaire */		_Context->max_RefBar=0;
		_Context->limit_RefBar=0;
		_Context->value_RefBar=0;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Target, 255, pTarget);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3555[i]=" ";
	_Context->hint_Auto3555[0]=en__Auto3555;
	_Context->hint_Auto3555[1]=fr__Auto3555;
	_Context->hint_Auto3555[2]=it__Auto3555;
	_Context->hint_Auto3555[3]=es__Auto3555;
	_Context->hint_Auto3555[4]=de__Auto3555;
	_Context->hint_Auto3555[5]=nl__Auto3555;
	_Context->hint_Auto3555[6]=pt__Auto3555;
	_Context->hint_Auto3555[7]=xx__Auto3555;
	_Context->x_Auto3555=10;
	_Context->y_Auto3555=10;
	_Context->w_Auto3555=370;
	_Context->h_Auto3555=620;
	_Context->window_col=10;
	_Context->window_row=10;
	for (i=0; i < 8; i++)_Context->msg_Auto3556[i]=" ";
	_Context->msg_Auto3556[0]=en_Auto3556;
	_Context->msg_Auto3556[1]=fr_Auto3556;
	_Context->msg_Auto3556[2]=it_Auto3556;
	_Context->msg_Auto3556[3]=es_Auto3556;
	_Context->msg_Auto3556[4]=de_Auto3556;
	_Context->msg_Auto3556[5]=nl_Auto3556;
	_Context->msg_Auto3556[6]=pt_Auto3556;
	_Context->msg_Auto3556[7]=xx_Auto3556;
	for (i=0; i < 8; i++)_Context->msg_Auto3557[i]=" ";
	_Context->msg_Auto3557[0]=en_Auto3557;
	_Context->msg_Auto3557[1]=fr_Auto3557;
	_Context->msg_Auto3557[2]=it_Auto3557;
	_Context->msg_Auto3557[3]=es_Auto3557;
	_Context->msg_Auto3557[4]=de_Auto3557;
	_Context->msg_Auto3557[5]=nl_Auto3557;
	_Context->msg_Auto3557[6]=pt_Auto3557;
	_Context->msg_Auto3557[7]=xx_Auto3557;
	for (i=0; i < 8; i++)_Context->msg_RefList[i]=" ";
	_Context->msg_RefList[0]=en_RefList;
	_Context->msg_RefList[1]=fr_RefList;
	_Context->msg_RefList[2]=it_RefList;
	_Context->msg_RefList[3]=es_RefList;
	_Context->msg_RefList[4]=de_RefList;
	_Context->msg_RefList[5]=nl_RefList;
	_Context->msg_RefList[6]=pt_RefList;
	_Context->msg_RefList[7]=xx_RefList;
	_Context->hint_RefList[0]=en__RefList;
	if ( 0 > 0 ) { _Context->row_RefList=&_Context->buffer_RefList[0-1][0]; } ;
	_Context->max_RefBar=1;
	_Context->value_RefBar=1;
	_Context->limit_RefBar=1;
	_Context->value_RefBar=0;
	_Context->limit_RefBar=31;
	_Context->max_RefBar=file_reference_count();
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3555,_Context->y_Auto3555,370+10,620+10);
	return(0);
}

public 	int	file_reference_locator_hide(struct file_reference_locator_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3555,_Context->y_Auto3555);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	file_reference_locator_remove(
	struct file_reference_locator_context * _Context,
	char * pTarget)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Target, 255, pTarget);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_RefList_show(struct file_reference_locator_context * _Context) {
	int i;
	for(i=1;i<=31;i++){
	if ( i > 0 ) { _Context->row_RefList=&_Context->buffer_RefList[i-1][0]; } ;
	get_file_reference(i+_Context->value_RefBar,(_Context->row_RefList+0),40);
	}
		visual_table(_Context->x_Auto3555+10,_Context->y_Auto3555+80,330,530,vfh[1],0,28,_Context->msg_RefList[_Context->language],_Context->buffer_RefList,0x4401,"($)");
;
	return(-1);
}

public	int	file_reference_locator_show(struct file_reference_locator_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3555,_Context->y_Auto3555);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3555,_Context->y_Auto3555,370,620,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3555,_Context->y_Auto3555,370,620,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3555+10,_Context->y_Auto3555+30,322,20,vfh[3],16,0,_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]),1282);
	visual_text(_Context->x_Auto3555+10,_Context->y_Auto3555+60,42,16,vfh[2],16,0,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),258);
	visual_frame(_Context->x_Auto3555+48,_Context->y_Auto3555+60,288+2,16+2,5);
	visual_text(_Context->x_Auto3555+48+1,_Context->y_Auto3555+60+1,288,16,vfh[1],0,28,_Context->buffer_Target,255,0);
	(void) on_RefList_show(_Context);
	visual_scrollbar(_Context->x_Auto3555+340,_Context->y_Auto3555+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);
	visual_thaw(_Context->x_Auto3555,_Context->y_Auto3555,370,620);

	return(0);
}

private int Target_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field provides the name of the file class for which the ";
			mptr[1]="list of  instance references is to be located.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int RefList_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This control displays the actual list of forms models which instance ";
			mptr[1]="data objects of the indicated file class. ";
			mptr[2]=" ";
			mptr[3]=" The corresponding forms model may be activated for inspection in ";
			mptr[4]="the forms  editor by clicking with the LEFT button of the mouse on the required forms model name.    ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int RefBar_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The scroll bar may be used to scroll through the list of  forms model ";
			mptr[1]="references if this exceeds the visual page.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3555action(struct file_reference_locator_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			file_reference_locator_hide(_Context);

		_Context->x_Auto3555 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3555 < 0) { _Context->x_Auto3555=0; }
		_Context->y_Auto3555 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3555 < 0) { _Context->y_Auto3555=0; }
			file_reference_locator_show(_Context);

		visual_thaw(_Context->x_Auto3555,_Context->y_Auto3555,370,620);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_RefList_event(struct file_reference_locator_context * _Context) {
	int l;
	char result[16];
	l=_Context->value_RefList;
	if(l>0){
		file_reference_locator_hide(_Context);
;
	use_file_reference(_Context->value_RefBar+l,result,16);
	draw_console();
		file_reference_locator_show(_Context);
;
	}
	return(-1);
}
private int on_RefBar_event(struct file_reference_locator_context * _Context) {
	on_RefList_show(_Context);
	return(-1);
}

private int on_RefBar_action(struct file_reference_locator_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto3555+80+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_RefBar -= 1;
		if (_Context->value_RefBar < 0) 
			_Context->value_RefBar = 0;
		(void) on_RefBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3555+340,_Context->y_Auto3555+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto3555+80+530-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_RefBar += 1;
		if (!(_Context->max_RefBar))
			_Context->value_RefBar = 0;
		else if ((_Context->max_RefBar < _Context->limit_RefBar) 
		&& (_Context->value_RefBar >= _Context->max_RefBar)) 
			_Context->value_RefBar = (_Context->max_RefBar-1);
		else if (_Context->value_RefBar > (_Context->max_RefBar-_Context->limit_RefBar)) 
			_Context->value_RefBar = (_Context->max_RefBar-_Context->limit_RefBar);
		(void) on_RefBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3555+340,_Context->y_Auto3555+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto3555+340,_Context->y_Auto3555+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_RefBar;
		_Context->value_RefBar = (((visual_event(6) - (_Context->y_Auto3555+80+20)) * _Context->max_RefBar) / (530 - (2 * 20)));
		if (_Context->value_RefBar < 0) 
			_Context->value_RefBar = 0;
		else if (_Context->value_RefBar > (_Context->max_RefBar-_Context->limit_RefBar)) 
			_Context->value_RefBar = (_Context->max_RefBar-_Context->limit_RefBar);
		if (_Context->value_RefBar != aty) {
		(void) on_RefBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3555+340,_Context->y_Auto3555+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_RefBar -= (_Context->limit_RefBar/2);
			if (_Context->value_RefBar < 0) 
				_Context->value_RefBar = 0;
		(void) on_RefBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3555+340,_Context->y_Auto3555+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_RefBar += (_Context->limit_RefBar/2);
			if (!(_Context->max_RefBar))
				_Context->value_RefBar = 0;
			else if ((_Context->max_RefBar < _Context->limit_RefBar) 
			&& (_Context->value_RefBar >= _Context->max_RefBar)) 
				_Context->value_RefBar = (_Context->max_RefBar-1);
			else if (_Context->value_RefBar > (_Context->max_RefBar-_Context->limit_RefBar)) 
				_Context->value_RefBar = (_Context->max_RefBar-_Context->limit_RefBar);
		(void) on_RefBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3555+340,_Context->y_Auto3555+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto3555+340,_Context->y_Auto3555+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);

	return(1);
}


public	int	file_reference_locator_event(
struct file_reference_locator_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3555+349) )  
	&&  (my >= (_Context->y_Auto3555+4) )  
	&&  (mx <= (_Context->x_Auto3555+366) )  
	&&  (my <= (_Context->y_Auto3555+20) )) {
		return(1);	/* Auto3555 */

		}
	if ((mx >= (_Context->x_Auto3555+333) )  
	&&  (my >= (_Context->y_Auto3555+4) )  
	&&  (mx <= (_Context->x_Auto3555+350) )  
	&&  (my <= (_Context->y_Auto3555+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vfileref.htm");
			};
		return(-1);	/* Auto3555 */

		}
	if ((mx >= (_Context->x_Auto3555+317) )  
	&&  (my >= (_Context->y_Auto3555+4) )  
	&&  (mx <= (_Context->x_Auto3555+334) )  
	&&  (my <= (_Context->y_Auto3555+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		file_reference_locator_show(_Context);
		return(-1);	/* Auto3555 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3555+4) )  
		&&  (my >= (_Context->y_Auto3555+4) )  
		&&  (mx <= (_Context->x_Auto3555+302) )  
		&&  (my <= (_Context->y_Auto3555+20) )) {
			return( Auto3555action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3555+48) ) 
	&&  ( my >= (_Context->y_Auto3555+60) ) 
	&&  ( mx <= (_Context->x_Auto3555+48+288) ) 
	&&  ( my <= (_Context->y_Auto3555+60+16))) {
		return(2); /* Target */
		}
	if (( mx >= (_Context->x_Auto3555+10) ) 
	&&  ( my >= (_Context->y_Auto3555+80) ) 
	&&  ( mx <= (_Context->x_Auto3555+10+330) ) 
	&&  ( my <= (_Context->y_Auto3555+80+530))) {
		if ((_Context->value_RefList = ((visual_event(6) - (_Context->y_Auto3555+80)) / 16)) < 1)
			_Context->value_RefList=0;
else if (_Context->value_RefList > 31 )
			_Context->value_RefList=31;
		if ( _Context->value_RefList > 0 ) { _Context->row_RefList = &_Context->buffer_RefList[(_Context->value_RefList-1)][0]; } 
		_Context->column_RefList = (visual_event(7) - (_Context->x_Auto3555+10));
		if ( _Context->column_RefList < 320 ) {
			_Context->column_RefList = 1;
			}
		if ((!(_Context->value_RefList)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
			if (_Context->formsort_RefList==_Context->column_RefList) /* si colonne choisie concerne déjà le tri */
				_Context->formsort_RefList=-_Context->column_RefList;	/* alors tri décroissant */
			else
				_Context->formsort_RefList=_Context->column_RefList; };	/* sinon tri croissant */
		return(3); /* RefList */
		}
	if (( mx >= (_Context->x_Auto3555+340) ) 
	&&  ( my >= (_Context->y_Auto3555+80) ) 
	&&  ( mx <= (_Context->x_Auto3555+340+20) ) 
	&&  ( my <= (_Context->y_Auto3555+80+530))) {
		return(4); /* RefBar */
		}

	return(-1);
}
private int on_Target_getfocus(struct file_reference_locator_context * _Context) {
	return(visual_getch());
	return(-1);
}


public	int	file_reference_locator_focus(struct file_reference_locator_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Target */
				_Context->keycode = on_Target_getfocus(_Context);
			break;
			case	0x4 :
				/* RefBar */
				_Context->keycode=visual_getch();
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			file_reference_locator_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=4;
			file_reference_locator_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=file_reference_locator_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (Target_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (RefList_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (RefBar_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3555 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Target */
					continue;
				case	0x3 :
					/* RefList */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_RefList_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* RefBar */
					(void) on_RefBar_action(_Context);
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

public	int	file_reference_locator(
	char * pTarget)
{
	int	status=0;
	struct file_reference_locator_context * _Context=(struct file_reference_locator_context*) 0;
	status = file_reference_locator_create(
	&_Context,
	 pTarget);
	if ( status != 0) return(status);
	status = file_reference_locator_show(_Context);
		enter_modal();
	status = file_reference_locator_focus(_Context);
		leave_modal();
	status = file_reference_locator_hide(_Context);
	status = file_reference_locator_remove(
	_Context,
	 pTarget);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vfileref_c */
