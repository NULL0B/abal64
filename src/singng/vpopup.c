
#ifndef _vpopup_c
#define _vpopup_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vpopup.xml                                               */
/* Target         : vpopup.c                                                 */
/* Identification : 0.0-1177511939-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto2793   "Sing : Version 2.1a"
#define fr_Auto2793   "Sing : Version 2.1a"
#define it_Auto2793   "Sing : Version 2.1a"
#define es_Auto2793   "Sing : Version 2.1a"
#define de_Auto2793   "Sing : Version 2.1a"
#define nl_Auto2793   "Sing : Version 2.1a"
#define pt_Auto2793   "Sing : Version 2.1a"
#define xx_Auto2793   "Sing : Version 2.1a"
#define en__Auto2793   ""
#define fr__Auto2793   ""
#define it__Auto2793   ""
#define es__Auto2793   ""
#define de__Auto2793   ""
#define nl__Auto2793   ""
#define pt__Auto2793   ""
#define xx__Auto2793   ""
#define en_hList   ".|."
#define fr_hList   ".|."
#define it_hList   ".|."
#define es_hList   ".|."
#define de_hList   ".|."
#define nl_hList   ".|."
#define pt_hList   ".|."
#define xx_hList   ".|."
#define en__hList   ""
#define fr__hList   ""
#define it__hList   ""
#define es__hList   ""
#define de__hList   ""
#define nl__hList   ""
#define pt__hList   ""
#define xx__hList   ""
#define en__hBar   ""

private struct accept_visual_popup_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2793[8];
	char * hint_Auto2793[8];
	int	x_Auto2793;
	int	y_Auto2793;
	int	w_Auto2793;
	int	h_Auto2793;
	char * msg_hList[8];
	char * hint_hList[8];
	int	value_hList;
	int	column_hList;
	char	buffer_hList[25][80];
	int	formsort_hList;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char	*libsort_hList;	/* table intermédiaire contenant la liste des éléments a trier */
	int	*tabsort_hList;	/* numéro d'ordre des elements triés */
	char	*indsort_hList;	/* pointeur table intermédiaire de tri */
	int	nelt_hList;	/* nombre d'eléments aloués dans tabsort */
	char * row_hList;
	char * hint_hBar[8];
	int	value_hBar;
	int	limit_hBar;
	int	max_hBar;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];
private int  sort_item_hList(struct accept_visual_popup_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_hList(struct accept_visual_popup_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_hList(struct accept_visual_popup_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_hList */
private int compare_hList(struct accept_visual_popup_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_hList */
/* ------------------- */
/* resolve sorted item */
/* ------------------- */
private int  sort_item_hList(struct accept_visual_popup_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_hList[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_hList(struct accept_visual_popup_context * _Context,int nelts)
{
if (_Context->nelt_hList<nelts) {
	liberate(_Context->tabsort_hList);
	if ((_Context->tabsort_hList=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_hList=0;_Context->nelt_hList<nelts;_Context->nelt_hList++)
		{ _Context->tabsort_hList[_Context->nelt_hList]=_Context->nelt_hList+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_hList=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_hList=allocate(nelts*80)) != NULL)
	memset(_Context->libsort_hList,' ',nelts*80);
}

/* -------------------------------------------------------- */
/* sort the intermediate table into _Context->tabsort_hList */
/* -------------------------------------------------------- */
private void sort_hList(struct accept_visual_popup_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_hList,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_hList[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_hList[j]) && (compare_hList(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_hList[i]=k+1;
	_Context->indsort_hList[k]=1;
	};	/* for i */
liberate(_Context->libsort_hList);
liberate(_Context->indsort_hList);
}

/* ------------------------------------------------------ */
/* compare the elements a et b of _Context->libsort_hList */
/* ------------------------------------------------------ */
private int compare_hList(struct accept_visual_popup_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_hList[80*a],&_Context->libsort_hList[80*b],6);	/* comparaison zone 1 */
switch (_Context->formsort_hList) {
	case 1:	/* . ordre normal */
		return(i);

	case -1:	/* . ordre inverse */
		return(-i);

	case 2:	/* . ordre normal */
		j=memicmp(&_Context->libsort_hList[80*a+6],&_Context->libsort_hList[80*b+6],74);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -2:	/* . ordre inverse */
		j=memicmp(&_Context->libsort_hList[80*b+6],&_Context->libsort_hList[80*a+6],74);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);
	default:		/* pas de tri */
		if (a<b) return(-1);
		return(1);
	}; /* fin du switch */
}

private int on_hBar_create(struct accept_visual_popup_context * _Context) {
	_Context->value_hBar=0;
	_Context->limit_hBar=24;
	_Context->max_hBar=get_helpline_count();
	if(_Context->max_hBar<_Context->limit_hBar){
	_Context->max_hBar=_Context->limit_hBar;
	}
	return(-1);
}

public	int	accept_visual_popup_create(struct accept_visual_popup_context **cptr)
{

	int i;
	struct accept_visual_popup_context * _Context=(struct accept_visual_popup_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_visual_popup_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=2;
	_Context->formsort_hList=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_hList=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_hList=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_hList=0;_Context->nelt_hList<512;_Context->nelt_hList++)
			{ _Context->tabsort_hList[_Context->nelt_hList]=_Context->nelt_hList+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_hList=0; /* si problème d'allocation */
_Context->indsort_hList=NULL;	/* pas de pointeur de table intermédiaire */		_Context->max_hBar=0;
		_Context->limit_hBar=0;
		_Context->value_hBar=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2793[i]=" ";
	_Context->msg_Auto2793[0]=en_Auto2793;
	_Context->msg_Auto2793[1]=fr_Auto2793;
	_Context->msg_Auto2793[2]=it_Auto2793;
	_Context->msg_Auto2793[3]=es_Auto2793;
	_Context->msg_Auto2793[4]=de_Auto2793;
	_Context->msg_Auto2793[5]=nl_Auto2793;
	_Context->msg_Auto2793[6]=pt_Auto2793;
	_Context->msg_Auto2793[7]=xx_Auto2793;
	_Context->hint_Auto2793[0]=en__Auto2793;
	_Context->hint_Auto2793[1]=fr__Auto2793;
	_Context->hint_Auto2793[2]=it__Auto2793;
	_Context->hint_Auto2793[3]=es__Auto2793;
	_Context->hint_Auto2793[4]=de__Auto2793;
	_Context->hint_Auto2793[5]=nl__Auto2793;
	_Context->hint_Auto2793[6]=pt__Auto2793;
	_Context->hint_Auto2793[7]=xx__Auto2793;
	_Context->x_Auto2793=55;
	_Context->y_Auto2793=80;
	_Context->w_Auto2793=690;
	_Context->h_Auto2793=440;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_hList[i]=" ";
	_Context->msg_hList[0]=en_hList;
	_Context->msg_hList[1]=fr_hList;
	_Context->msg_hList[2]=it_hList;
	_Context->msg_hList[3]=es_hList;
	_Context->msg_hList[4]=de_hList;
	_Context->msg_hList[5]=nl_hList;
	_Context->msg_hList[6]=pt_hList;
	_Context->msg_hList[7]=xx_hList;
	_Context->hint_hList[0]=en__hList;
	_Context->hint_hList[1]=fr__hList;
	_Context->hint_hList[2]=it__hList;
	_Context->hint_hList[3]=es__hList;
	_Context->hint_hList[4]=de__hList;
	_Context->hint_hList[5]=nl__hList;
	_Context->hint_hList[6]=pt__hList;
	_Context->hint_hList[7]=xx__hList;
	if ( 0 > 0 ) { _Context->row_hList=&_Context->buffer_hList[0-1][0]; } ;
	_Context->hint_hBar[0]=en__hBar;
	_Context->max_hBar=1;
	_Context->value_hBar=1;
	_Context->limit_hBar=1;
	(void) on_hBar_create(_Context);
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2793,_Context->y_Auto2793,690+10,440+10);
	return(0);
}

public 	int	accept_visual_popup_hide(struct accept_visual_popup_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2793,_Context->y_Auto2793);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_visual_popup_remove(struct accept_visual_popup_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_hList_show(struct accept_visual_popup_context * _Context) {
	int l;
	memset(_Context->buffer_hList,' ',1920);
	for(l=1;l<=24;l++){
	if ( l > 0 ) { _Context->row_hList=&_Context->buffer_hList[l-1][0]; } ;
	get_helptext_line(
	l+_Context->value_hBar,
	(_Context->row_hList+0),6,
	(_Context->row_hList+6),74);
	}
		visual_table(_Context->x_Auto2793+10,_Context->y_Auto2793+30,644,404,vfh[1],27,28,_Context->msg_hList[_Context->language],_Context->buffer_hList,0x4400,"(N4Z,$)");
;
	return(-1);
}

public	int	accept_visual_popup_show(struct accept_visual_popup_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2793,_Context->y_Auto2793);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto2793,_Context->y_Auto2793,690,440,vfh[2],_Context->msg_Auto2793[_Context->language],strlen(_Context->msg_Auto2793[_Context->language]),0x407);
	(void) on_hList_show(_Context);
	visual_scrollbar(_Context->x_Auto2793+660,_Context->y_Auto2793+30,20,400,vfh[1],27,28,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,3);
	visual_thaw(_Context->x_Auto2793,_Context->y_Auto2793,690,440);

	return(0);
}

private int Auto2793action(struct accept_visual_popup_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_visual_popup_hide(_Context);

		_Context->x_Auto2793 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2793 < 0) { _Context->x_Auto2793=0; }
		_Context->y_Auto2793 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2793 < 0) { _Context->y_Auto2793=0; }
			accept_visual_popup_show(_Context);

		visual_thaw(_Context->x_Auto2793,_Context->y_Auto2793,690,440);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_hBar_event(struct accept_visual_popup_context * _Context) {
	on_hList_show(_Context);
	return(-1);
}

private int on_hBar_action(struct accept_visual_popup_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto2793+30+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_hBar -= 1;
		if (_Context->value_hBar < 0) 
			_Context->value_hBar = 0;
		(void) on_hBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2793+660,_Context->y_Auto2793+30,20,400,vfh[1],27,28,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto2793+30+400-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_hBar += 1;
		if (!(_Context->max_hBar))
			_Context->value_hBar = 0;
		else if ((_Context->max_hBar < _Context->limit_hBar) 
		&& (_Context->value_hBar >= _Context->max_hBar)) 
			_Context->value_hBar = (_Context->max_hBar-1);
		else if (_Context->value_hBar > (_Context->max_hBar-_Context->limit_hBar)) 
			_Context->value_hBar = (_Context->max_hBar-_Context->limit_hBar);
		(void) on_hBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2793+660,_Context->y_Auto2793+30,20,400,vfh[1],27,28,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto2793+660,_Context->y_Auto2793+30,20,400,vfh[1],27,28,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_hBar;
		_Context->value_hBar = (((visual_event(6) - (_Context->y_Auto2793+30+20)) * _Context->max_hBar) / (400 - (2 * 20)));
		if (_Context->value_hBar < 0) 
			_Context->value_hBar = 0;
		else if (_Context->value_hBar > (_Context->max_hBar-_Context->limit_hBar)) 
			_Context->value_hBar = (_Context->max_hBar-_Context->limit_hBar);
		if (_Context->value_hBar != aty) {
		(void) on_hBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2793+660,_Context->y_Auto2793+30,20,400,vfh[1],27,28,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_hBar -= (_Context->limit_hBar/2);
			if (_Context->value_hBar < 0) 
				_Context->value_hBar = 0;
		(void) on_hBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2793+660,_Context->y_Auto2793+30,20,400,vfh[1],27,28,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_hBar += (_Context->limit_hBar/2);
			if (!(_Context->max_hBar))
				_Context->value_hBar = 0;
			else if ((_Context->max_hBar < _Context->limit_hBar) 
			&& (_Context->value_hBar >= _Context->max_hBar)) 
				_Context->value_hBar = (_Context->max_hBar-1);
			else if (_Context->value_hBar > (_Context->max_hBar-_Context->limit_hBar)) 
				_Context->value_hBar = (_Context->max_hBar-_Context->limit_hBar);
		(void) on_hBar_event(_Context);
	visual_scrollbar(_Context->x_Auto2793+660,_Context->y_Auto2793+30,20,400,vfh[1],27,28,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto2793+660,_Context->y_Auto2793+30,20,400,vfh[1],27,28,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,3);

	return(1);
}


public	int	accept_visual_popup_event(
struct accept_visual_popup_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2793+669) )  
	&&  (my >= (_Context->y_Auto2793+4) )  
	&&  (mx <= (_Context->x_Auto2793+686) )  
	&&  (my <= (_Context->y_Auto2793+20) )) {
		return(1);	/* Auto2793 */

		}
	if ((mx >= (_Context->x_Auto2793+653) )  
	&&  (my >= (_Context->y_Auto2793+4) )  
	&&  (mx <= (_Context->x_Auto2793+670) )  
	&&  (my <= (_Context->y_Auto2793+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vpopup.htm");
			};
		return(-1);	/* Auto2793 */

		}
	if ((mx >= (_Context->x_Auto2793+637) )  
	&&  (my >= (_Context->y_Auto2793+4) )  
	&&  (mx <= (_Context->x_Auto2793+654) )  
	&&  (my <= (_Context->y_Auto2793+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_visual_popup_show(_Context);
		return(-1);	/* Auto2793 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2793+4) )  
		&&  (my >= (_Context->y_Auto2793+4) )  
		&&  (mx <= (_Context->x_Auto2793+622) )  
		&&  (my <= (_Context->y_Auto2793+20) )) {
			return( Auto2793action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto2793+660) ) 
	&&  ( my >= (_Context->y_Auto2793+30) ) 
	&&  ( mx <= (_Context->x_Auto2793+660+20) ) 
	&&  ( my <= (_Context->y_Auto2793+30+400))) {
		return(2); /* hBar */
		}

	return(-1);
}


public	int	accept_visual_popup_focus(struct accept_visual_popup_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* hBar */
				_Context->keycode=visual_getch();
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_visual_popup_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=2;
			accept_visual_popup_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_visual_popup_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2793 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* hBar */
					(void) on_hBar_action(_Context);
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
				_Context->focus_item=2;
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

public	int	accept_visual_popup()
{
	int	status=0;
	struct accept_visual_popup_context * _Context=(struct accept_visual_popup_context*) 0;
	status = accept_visual_popup_create(&_Context);
	if ( status != 0) return(status);
	status = accept_visual_popup_show(_Context);
		enter_modal();
	status = accept_visual_popup_focus(_Context);
		leave_modal();
	status = accept_visual_popup_hide(_Context);
	status = accept_visual_popup_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vpopup_c */
