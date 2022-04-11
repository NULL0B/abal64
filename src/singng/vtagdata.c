
#ifndef _vtagdata_c
#define _vtagdata_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.33                                                */
/* Production     : C                                                        */
/* Project        : vtagdata.xml                                             */
/* Target         : vtagdata.c                                               */
/* Identification : 0.0-1188337541-4920.4919                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto2898   "Sing : Version 1.0a"
#define en__Auto2898   ""
#define en_Auto2899   "Html Document : Hyperlink Selection"
#define en__Auto2899   ""
#define en_hList   "Href|Text"
#define en__hList   ""
#define en__hBar   ""
#define en_Auto2900   "Resulting Anchor Expression"
#define en__Auto2900   ""
#define en_Result   ""
#define en__Result   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en__Accept   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""

private struct choose_html_tag_data_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2898[8];
	char * hint_Auto2898[8];
	int	x_Auto2898;
	int	y_Auto2898;
	int	w_Auto2898;
	int	h_Auto2898;
	char * msg_Auto2899[8];
	char * hint_Auto2899[8];
	char * msg_hList[8];
	char * hint_hList[8];
	int	value_hList;
	int	column_hList;
	char	buffer_hList[18][94];
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
	char * msg_Auto2900[8];
	char * hint_Auto2900[8];
	char * hint_Result[8];
	char	buffer_Result[256];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];
private int  sort_item_hList(struct choose_html_tag_data_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_hList(struct choose_html_tag_data_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_hList(struct choose_html_tag_data_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_hList */
private int compare_hList(struct choose_html_tag_data_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_hList */
/* ------------------- */
/* resolve sorted item */
/* ------------------- */
private int  sort_item_hList(struct choose_html_tag_data_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_hList[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_hList(struct choose_html_tag_data_context * _Context,int nelts)
{
if (_Context->nelt_hList<nelts) {
	liberate(_Context->tabsort_hList);
	if ((_Context->tabsort_hList=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_hList=0;_Context->nelt_hList<nelts;_Context->nelt_hList++)
		{ _Context->tabsort_hList[_Context->nelt_hList]=_Context->nelt_hList+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_hList=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_hList=allocate(nelts*94)) != NULL)
	memset(_Context->libsort_hList,' ',nelts*94);
}

/* -------------------------------------------------------- */
/* sort the intermediate table into _Context->tabsort_hList */
/* -------------------------------------------------------- */
private void sort_hList(struct choose_html_tag_data_context * _Context,int nelts)
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
private int compare_hList(struct choose_html_tag_data_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_hList[94*a],&_Context->libsort_hList[94*b],33);	/* comparaison zone 1 */
switch (_Context->formsort_hList) {
	case 1:	/* Href ordre normal */
		return(i);

	case -1:	/* Href ordre inverse */
		return(-i);

	case 2:	/* Text ordre normal */
		j=memicmp(&_Context->libsort_hList[94*a+33],&_Context->libsort_hList[94*b+33],61);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -2:	/* Text ordre inverse */
		j=memicmp(&_Context->libsort_hList[94*b+33],&_Context->libsort_hList[94*a+33],61);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);
	default:		/* pas de tri */
		if (a<b) return(-1);
		return(1);
	}; /* fin du switch */
}


public	int	choose_html_tag_data_create(
	struct choose_html_tag_data_context ** cptr,
	char * pResult)
{

	int i;
	struct choose_html_tag_data_context * _Context=(struct choose_html_tag_data_context*)0;
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
	if (!(_Context = allocate( sizeof( struct choose_html_tag_data_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	_Context->formsort_hList=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_hList=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_hList=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_hList=0;_Context->nelt_hList<512;_Context->nelt_hList++)
			{ _Context->tabsort_hList[_Context->nelt_hList]=_Context->nelt_hList+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_hList=0; /* si problème d'allocation */
_Context->indsort_hList=NULL;	/* pas de pointeur de table intermédiaire */		_Context->max_hBar=0;
		_Context->limit_hBar=0;
		_Context->value_hBar=0;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Result, 255, pResult);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto2898[i]=" ";
	_Context->msg_Auto2898[0]=en_Auto2898;
	_Context->hint_Auto2898[0]=en__Auto2898;
	_Context->x_Auto2898=0;
	_Context->y_Auto2898=85;
	_Context->w_Auto2898=800;
	_Context->h_Auto2898=430;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2899[i]=" ";
	_Context->msg_Auto2899[0]=en_Auto2899;
	_Context->hint_Auto2899[0]=en__Auto2899;
	for (i=0; i < 8; i++)_Context->msg_hList[i]=" ";
	_Context->msg_hList[0]=en_hList;
	_Context->hint_hList[0]=en__hList;
	if ( 0 > 0 ) { _Context->row_hList=&_Context->buffer_hList[0-1][0]; } ;
	_Context->hint_hBar[0]=en__hBar;
	_Context->max_hBar=1;
	_Context->value_hBar=1;
	_Context->limit_hBar=1;
	for (i=0; i < 8; i++)_Context->msg_Auto2900[i]=" ";
	_Context->msg_Auto2900[0]=en_Auto2900;
	_Context->hint_Auto2900[0]=en__Auto2900;
	_Context->hint_Result[0]=en__Result;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	_Context->hint_Accept[0]=en__Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	_Context->hint_Cancel[0]=en__Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2898,_Context->y_Auto2898,800+10,430+10);
	return(0);
}

public 	int	choose_html_tag_data_hide(struct choose_html_tag_data_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2898,_Context->y_Auto2898);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	choose_html_tag_data_remove(
	struct choose_html_tag_data_context * _Context,
	char * pResult)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Result, 255, pResult);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	choose_html_tag_data_show(struct choose_html_tag_data_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2898,_Context->y_Auto2898);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto2898,_Context->y_Auto2898,800,430,vfh[2],_Context->msg_Auto2898[_Context->language],strlen(_Context->msg_Auto2898[_Context->language]),0x407);
	visual_text(_Context->x_Auto2898+10,_Context->y_Auto2898+30,759,20,vfh[3],16,0,_Context->msg_Auto2899[_Context->language],strlen(_Context->msg_Auto2899[_Context->language]),1283);
	visual_table(_Context->x_Auto2898+10,_Context->y_Auto2898+60,756,292,vfh[1],0,0,_Context->msg_hList[_Context->language],_Context->buffer_hList,0x4401,"(W32,$)");
	visual_scrollbar(_Context->x_Auto2898+770,_Context->y_Auto2898+60,20,290,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,3);
	visual_text(_Context->x_Auto2898+80,_Context->y_Auto2898+370,616,16,vfh[2],16,0,_Context->msg_Auto2900[_Context->language],strlen(_Context->msg_Auto2900[_Context->language]),259);
	visual_frame(_Context->x_Auto2898+80,_Context->y_Auto2898+390,616+2,16+2,5);
	visual_text(_Context->x_Auto2898+80+1,_Context->y_Auto2898+390+1,616,16,vfh[1],27,28,_Context->buffer_Result,255,0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto2898+10,_Context->y_Auto2898+370,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto2898+710,_Context->y_Auto2898+370,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_thaw(_Context->x_Auto2898,_Context->y_Auto2898,800,430);

	return(0);
}

private int Accept_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the ACCEPT button any changes made to the various    parameters ";
			mptr[1]="will take effect.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Cancel_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the CANCEL button any modifications performed will be ";
			mptr[1]="   discarded.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2898action(struct choose_html_tag_data_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			choose_html_tag_data_hide(_Context);

		_Context->x_Auto2898 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2898 < 0) { _Context->x_Auto2898=0; }
		_Context->y_Auto2898 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2898 < 0) { _Context->y_Auto2898=0; }
			choose_html_tag_data_show(_Context);

		visual_thaw(_Context->x_Auto2898,_Context->y_Auto2898,800,430);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_hList_event(struct choose_html_tag_data_context * _Context) {
	int l;
	l=_Context->value_hList;
	if(l>0){
	l+=_Context->value_hBar;
	tag_selection_result(_Context->buffer_Result,255,l);
	visual_frame(_Context->x_Auto2898+80,_Context->y_Auto2898+390,616+2,16+2,5);
visual_text(_Context->x_Auto2898+80+1,_Context->y_Auto2898+390+1,616,16,vfh[1],27,28,_Context->buffer_Result,255,0);
;
	}
	return(-1);
}

private int on_hBar_action(struct choose_html_tag_data_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto2898+60+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_hBar -= 1;
		if (_Context->value_hBar < 0) 
			_Context->value_hBar = 0;
	status = choose_html_tag_data_show(_Context);
	visual_scrollbar(_Context->x_Auto2898+770,_Context->y_Auto2898+60,20,290,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto2898+60+290-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_hBar += 1;
		if (!(_Context->max_hBar))
			_Context->value_hBar = 0;
		else if ((_Context->max_hBar < _Context->limit_hBar) 
		&& (_Context->value_hBar >= _Context->max_hBar)) 
			_Context->value_hBar = (_Context->max_hBar-1);
		else if (_Context->value_hBar > (_Context->max_hBar-_Context->limit_hBar)) 
			_Context->value_hBar = (_Context->max_hBar-_Context->limit_hBar);
	status = choose_html_tag_data_show(_Context);
	visual_scrollbar(_Context->x_Auto2898+770,_Context->y_Auto2898+60,20,290,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto2898+770,_Context->y_Auto2898+60,20,290,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_hBar;
		_Context->value_hBar = (((visual_event(6) - (_Context->y_Auto2898+60+20)) * _Context->max_hBar) / (290 - (2 * 20)));
		if (_Context->value_hBar < 0) 
			_Context->value_hBar = 0;
		else if (_Context->value_hBar > (_Context->max_hBar-_Context->limit_hBar)) 
			_Context->value_hBar = (_Context->max_hBar-_Context->limit_hBar);
		if (_Context->value_hBar != aty) {
	status = choose_html_tag_data_show(_Context);
	visual_scrollbar(_Context->x_Auto2898+770,_Context->y_Auto2898+60,20,290,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_hBar -= (_Context->limit_hBar/2);
			if (_Context->value_hBar < 0) 
				_Context->value_hBar = 0;
	status = choose_html_tag_data_show(_Context);
	visual_scrollbar(_Context->x_Auto2898+770,_Context->y_Auto2898+60,20,290,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
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
	status = choose_html_tag_data_show(_Context);
	visual_scrollbar(_Context->x_Auto2898+770,_Context->y_Auto2898+60,20,290,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto2898+770,_Context->y_Auto2898+60,20,290,vfh[1],0,0,_Context->value_hBar,_Context->limit_hBar,_Context->max_hBar,3);

	return(1);
}
private int on_Accept_event(struct choose_html_tag_data_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct choose_html_tag_data_context * _Context) {
	return(27);
	return(-1);
}


public	int	choose_html_tag_data_event(
struct choose_html_tag_data_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(5);
		if (_Context->trigger_Cancel == mb ) return(6);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2898+779) )  
	&&  (my >= (_Context->y_Auto2898+4) )  
	&&  (mx <= (_Context->x_Auto2898+796) )  
	&&  (my <= (_Context->y_Auto2898+20) )) {
		return(1);	/* Auto2898 */

		}
	if ((mx >= (_Context->x_Auto2898+763) )  
	&&  (my >= (_Context->y_Auto2898+4) )  
	&&  (mx <= (_Context->x_Auto2898+780) )  
	&&  (my <= (_Context->y_Auto2898+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vtagdata.htm");
			};
		return(-1);	/* Auto2898 */

		}
	if ((mx >= (_Context->x_Auto2898+747) )  
	&&  (my >= (_Context->y_Auto2898+4) )  
	&&  (mx <= (_Context->x_Auto2898+764) )  
	&&  (my <= (_Context->y_Auto2898+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		choose_html_tag_data_show(_Context);
		return(-1);	/* Auto2898 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2898+4) )  
		&&  (my >= (_Context->y_Auto2898+4) )  
		&&  (mx <= (_Context->x_Auto2898+732) )  
		&&  (my <= (_Context->y_Auto2898+20) )) {
			return( Auto2898action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto2898+10) ) 
	&&  ( my >= (_Context->y_Auto2898+60) ) 
	&&  ( mx <= (_Context->x_Auto2898+10+756) ) 
	&&  ( my <= (_Context->y_Auto2898+60+292))) {
		if ((_Context->value_hList = ((visual_event(6) - (_Context->y_Auto2898+60)) / 16)) < 1)
			_Context->value_hList=0;
else if (_Context->value_hList > 17 )
			_Context->value_hList=17;
		if ( _Context->value_hList > 0 ) { _Context->row_hList = &_Context->buffer_hList[(_Context->value_hList-1)][0]; } 
		_Context->column_hList = (visual_event(7) - (_Context->x_Auto2898+10));
		if ( _Context->column_hList < 264 ) {
			_Context->column_hList = 1;
			}
		else if ( _Context->column_hList < 752 ) {
			_Context->column_hList = 2;
			}
		if ((!(_Context->value_hList)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
			if (_Context->formsort_hList==_Context->column_hList) /* si colonne choisie concerne déjà le tri */
				_Context->formsort_hList=-_Context->column_hList;	/* alors tri décroissant */
			else
				_Context->formsort_hList=_Context->column_hList; };	/* sinon tri croissant */
		return(2); /* hList */
		}
	if (( mx >= (_Context->x_Auto2898+770) ) 
	&&  ( my >= (_Context->y_Auto2898+60) ) 
	&&  ( mx <= (_Context->x_Auto2898+770+20) ) 
	&&  ( my <= (_Context->y_Auto2898+60+290))) {
		return(3); /* hBar */
		}
	if (( mx >= (_Context->x_Auto2898+80) ) 
	&&  ( my >= (_Context->y_Auto2898+390) ) 
	&&  ( mx <= (_Context->x_Auto2898+80+616) ) 
	&&  ( my <= (_Context->y_Auto2898+390+16))) {
		return(4); /* Result */
		}
	if (( mx >= (_Context->x_Auto2898+10) ) 
	&&  ( my >= (_Context->y_Auto2898+370) ) 
	&&  ( mx <= (_Context->x_Auto2898+10+56) ) 
	&&  ( my <= (_Context->y_Auto2898+370+48))) {
		return(5); /* Accept */
		}
	if (( mx >= (_Context->x_Auto2898+710) ) 
	&&  ( my >= (_Context->y_Auto2898+370) ) 
	&&  ( mx <= (_Context->x_Auto2898+710+56) ) 
	&&  ( my <= (_Context->y_Auto2898+370+48))) {
		return(6); /* Cancel */
		}

	return(-1);
}


public	int	choose_html_tag_data_focus(struct choose_html_tag_data_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* hList */
				if (!_Context->value_hList) _Context->value_hList=1;	/* pour etre sur qu'on edite pas le titre */
				_Context->row_hList = &_Context->buffer_hList[(_Context->value_hList-1)][0];
				switch (_Context->column_hList) {
				case	0x1 :
					_Context->keycode=visual_edit((_Context->x_Auto2898+10+2),(_Context->y_Auto2898+60+(_Context->value_hList*16)+2),256,16,vfh[1],&_Context->buffer_hList[(_Context->value_hList-1)][0],32);
				visual_text((_Context->x_Auto2898+10+2),(_Context->y_Auto2898+60+(_Context->value_hList*16)+2),256,16,vfh[1],0,(24-((_Context->value_hList-1)&1)),&_Context->buffer_hList[(_Context->value_hList-1)][0],32,0);
					break;
				case	0x2 :
					_Context->keycode=visual_edit((_Context->x_Auto2898+10+266),(_Context->y_Auto2898+60+(_Context->value_hList*16)+2),480,16,vfh[1],&_Context->buffer_hList[(_Context->value_hList-1)][33],60);
				visual_text((_Context->x_Auto2898+10+266),(_Context->y_Auto2898+60+(_Context->value_hList*16)+2),480,16,vfh[1],0,(24-((_Context->value_hList-1)&1)),&_Context->buffer_hList[(_Context->value_hList-1)][33],60,0);
					break;
					}
				if ( _Context->keycode == 9 ) {
					_Context->column_hList++;
					if ( _Context->column_hList > 2 ) {
						_Context->column_hList=1;
						_Context->value_hList++;
						if ( _Context->value_hList > 17 ) {
							_Context->value_hList=1;
							}
						}
					_Context->keycode=0;
					}
			break;
			case	0x3 :
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
			choose_html_tag_data_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=6;
			choose_html_tag_data_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=choose_html_tag_data_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x5 :
						if (Accept_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Cancel_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2898 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* hList */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_hList_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* hBar */
					(void) on_hBar_action(_Context);
					continue;
				case	0x4 :
					/* Result */
					continue;
				case	0x5 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto2898+10,_Context->y_Auto2898+370,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto2898+10,_Context->y_Auto2898+370,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto2898+710,_Context->y_Auto2898+370,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto2898+710,_Context->y_Auto2898+370,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
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
				_Context->focus_item=6;
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

public	int	choose_html_tag_data(
	char * pResult)
{
	int	status=0;
	struct choose_html_tag_data_context * _Context=(struct choose_html_tag_data_context*) 0;
	status = choose_html_tag_data_create(
	&_Context,
	 pResult);
	if ( status != 0) return(status);
	status = choose_html_tag_data_show(_Context);
		enter_modal();
	status = choose_html_tag_data_focus(_Context);
		leave_modal();
	status = choose_html_tag_data_hide(_Context);
	status = choose_html_tag_data_remove(
	_Context,
	 pResult);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vtagdata_c */
