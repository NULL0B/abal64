
#ifndef _vshow_c
#define _vshow_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vshow.xml                                                */
/* Target         : vshow.c                                                  */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto3590   "Sing : Version 1.0a"
#define fr_Auto3590   "Sing : Version 1.0a"
#define it_Auto3590   "Sing : Version 1.0a"
#define es_Auto3590   "Sing : Version 1.0a"
#define de_Auto3590   "Sing : Version 1.0a"
#define nl_Auto3590   "Sing : Version 1.0a"
#define pt_Auto3590   "Sing : Version 1.0a"
#define xx_Auto3590   "Sing : Version 1.0a"
#define en_Variable   ""
#define en_FirstDim   ""
#define en_SecondDim   ""
#define en_Auto3591   "("
#define fr_Auto3591   "("
#define it_Auto3591   "("
#define es_Auto3591   "("
#define de_Auto3591   "("
#define nl_Auto3591   "("
#define pt_Auto3591   "("
#define xx_Auto3591   "("
#define en_Auto3592   ")"
#define fr_Auto3592   ")"
#define it_Auto3592   ")"
#define es_Auto3592   ")"
#define de_Auto3592   ")"
#define nl_Auto3592   ")"
#define pt_Auto3592   ")"
#define xx_Auto3592   ")"
#define en_Auto3593   ","
#define fr_Auto3593   ","
#define it_Auto3593   ","
#define es_Auto3593   ","
#define de_Auto3593   ","
#define nl_Auto3593   ","
#define pt_Auto3593   ","
#define xx_Auto3593   ","
#define en_Counter   ""
#define en_Liste   "ID|Variable|Memory|Value"
#define fr_Liste   "ID|Variable|Memoire|Valeur"
#define it_Liste   "ID|Variable|Memory|Value"
#define es_Liste   "ID|Variable|Memory|Value"
#define de_Liste   "ID|Variable|Memory|Value"
#define nl_Liste   "ID|Variable|Memory|Value"
#define pt_Liste   "ID|Variable|Memory|Value"
#define xx_Liste   "ID|Variable|Memory|Value"
#define en_Slider   ""

private struct accept_variable_inspection_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3590[8];
	char * hint_Auto3590[8];
	int	x_Auto3590;
	int	y_Auto3590;
	int	w_Auto3590;
	int	h_Auto3590;
	char * hint_Variable[8];
	char	buffer_Variable[78];
	char * hint_FirstDim[8];
	char	buffer_FirstDim[6];
	char * hint_SecondDim[8];
	char	buffer_SecondDim[6];
	char * msg_Auto3591[8];
	char * hint_Auto3591[8];
	char * msg_Auto3592[8];
	char * hint_Auto3592[8];
	char * msg_Auto3593[8];
	char * hint_Auto3593[8];
	char * hint_Counter[8];
	char	buffer_Counter[7];
	char * msg_Liste[8];
	char * hint_Liste[8];
	int	value_Liste;
	int	column_Liste;
	char	buffer_Liste[9][97];
	int	formsort_Liste;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char	*libsort_Liste;	/* table intermédiaire contenant la liste des éléments a trier */
	int	*tabsort_Liste;	/* numéro d'ordre des elements triés */
	char	*indsort_Liste;	/* pointeur table intermédiaire de tri */
	int	nelt_Liste;	/* nombre d'eléments aloués dans tabsort */
	char * row_Liste;
	char * hint_Slider[8];
	int	value_Slider;
	int	limit_Slider;
	int	max_Slider;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[5];
	};
static int	vfh[16];
private int on_Slider_create(struct accept_variable_inspection_context * _Context);
private int on_Liste_show(struct accept_variable_inspection_context * _Context);
private int on_FirstDim_losefocus(struct accept_variable_inspection_context * _Context);
private int on_SecondDim_losefocus(struct accept_variable_inspection_context * _Context);
private int on_Liste_event(struct accept_variable_inspection_context * _Context);
private int on_Slider_event(struct accept_variable_inspection_context * _Context);
private int  sort_item_Liste(struct accept_variable_inspection_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_Liste(struct accept_variable_inspection_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_Liste(struct accept_variable_inspection_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_Liste */
private int compare_Liste(struct accept_variable_inspection_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_Liste */
/* ------------------- */
/* resolve sorted item */
/* ------------------- */
private int  sort_item_Liste(struct accept_variable_inspection_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_Liste[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_Liste(struct accept_variable_inspection_context * _Context,int nelts)
{
if (_Context->nelt_Liste<nelts) {
	liberate(_Context->tabsort_Liste);
	if ((_Context->tabsort_Liste=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_Liste=0;_Context->nelt_Liste<nelts;_Context->nelt_Liste++)
		{ _Context->tabsort_Liste[_Context->nelt_Liste]=_Context->nelt_Liste+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_Liste=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_Liste=allocate(nelts*97)) != NULL)
	memset(_Context->libsort_Liste,' ',nelts*97);
}

/* -------------------------------------------------------- */
/* sort the intermediate table into _Context->tabsort_Liste */
/* -------------------------------------------------------- */
private void sort_Liste(struct accept_variable_inspection_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_Liste,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_Liste[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_Liste[j]) && (compare_Liste(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_Liste[i]=k+1;
	_Context->indsort_Liste[k]=1;
	};	/* for i */
liberate(_Context->libsort_Liste);
liberate(_Context->indsort_Liste);
}

/* ------------------------------------------------------ */
/* compare the elements a et b of _Context->libsort_Liste */
/* ------------------------------------------------------ */
private int compare_Liste(struct accept_variable_inspection_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_Liste[97*a],&_Context->libsort_Liste[97*b],9);	/* comparaison zone 1 */
switch (_Context->formsort_Liste) {
	case 1:	/* ID ordre normal */
		return(i);

	case -1:	/* ID ordre inverse */
		return(-i);

	case 2:	/* Variable ordre normal */
		j=memicmp(&_Context->libsort_Liste[97*a+9],&_Context->libsort_Liste[97*b+9],25);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -2:	/* Variable ordre inverse */
		j=memicmp(&_Context->libsort_Liste[97*b+9],&_Context->libsort_Liste[97*a+9],25);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 3:	/* Memory ordre normal */
		j=memicmp(&_Context->libsort_Liste[97*a+34],&_Context->libsort_Liste[97*b+34],9);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -3:	/* Memory ordre inverse */
		j=memicmp(&_Context->libsort_Liste[97*b+34],&_Context->libsort_Liste[97*a+34],9);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 4:	/* Value ordre normal */
		j=memicmp(&_Context->libsort_Liste[97*a+43],&_Context->libsort_Liste[97*b+43],54);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -4:	/* Value ordre inverse */
		j=memicmp(&_Context->libsort_Liste[97*b+43],&_Context->libsort_Liste[97*a+43],54);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);
	default:		/* pas de tri */
		if (a<b) return(-1);
		return(1);
	}; /* fin du switch */
}

private int on_Slider_create(struct accept_variable_inspection_context * _Context) {
	int i;
	_Context->value_Slider=0;
	_Context->limit_Slider=8;
	for(_Context->max_Slider=0,i=0;i<6;i++){
	if((_Context->buffer_Counter[i]>='0')
	&&(_Context->buffer_Counter[i]<='9'))
	_Context->max_Slider=((_Context->max_Slider*10)+(_Context->buffer_Counter[i]-'0'));
	}
		return(-1);
}

public	int	accept_variable_inspection_create(
	struct accept_variable_inspection_context ** cptr,
	char * pVariable,
	char * pFirstDim,
	char * pSecondDim,
	char * pCounter)
{

	int i;
	struct accept_variable_inspection_context * _Context=(struct accept_variable_inspection_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_variable_inspection_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=7;
	_Context->formsort_Liste=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_Liste=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_Liste=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_Liste=0;_Context->nelt_Liste<512;_Context->nelt_Liste++)
			{ _Context->tabsort_Liste[_Context->nelt_Liste]=_Context->nelt_Liste+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_Liste=0; /* si problème d'allocation */
_Context->indsort_Liste=NULL;	/* pas de pointeur de table intermédiaire */		_Context->max_Slider=0;
		_Context->limit_Slider=0;
		_Context->value_Slider=0;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Variable, 77, pVariable);
		visual_transferin(_Context->buffer_FirstDim, 5, pFirstDim);
		visual_transferin(_Context->buffer_SecondDim, 5, pSecondDim);
		visual_transferin(_Context->buffer_Counter, 6, pCounter);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3590[i]=" ";
	_Context->msg_Auto3590[0]=en_Auto3590;
	_Context->msg_Auto3590[1]=fr_Auto3590;
	_Context->msg_Auto3590[2]=it_Auto3590;
	_Context->msg_Auto3590[3]=es_Auto3590;
	_Context->msg_Auto3590[4]=de_Auto3590;
	_Context->msg_Auto3590[5]=nl_Auto3590;
	_Context->msg_Auto3590[6]=pt_Auto3590;
	_Context->msg_Auto3590[7]=xx_Auto3590;
	_Context->x_Auto3590=97;
	_Context->y_Auto3590=274;
	_Context->w_Auto3590=830;
	_Context->h_Auto3590=220;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3591[i]=" ";
	_Context->msg_Auto3591[0]=en_Auto3591;
	_Context->msg_Auto3591[1]=fr_Auto3591;
	_Context->msg_Auto3591[2]=it_Auto3591;
	_Context->msg_Auto3591[3]=es_Auto3591;
	_Context->msg_Auto3591[4]=de_Auto3591;
	_Context->msg_Auto3591[5]=nl_Auto3591;
	_Context->msg_Auto3591[6]=pt_Auto3591;
	_Context->msg_Auto3591[7]=xx_Auto3591;
	for (i=0; i < 8; i++)_Context->msg_Auto3592[i]=" ";
	_Context->msg_Auto3592[0]=en_Auto3592;
	_Context->msg_Auto3592[1]=fr_Auto3592;
	_Context->msg_Auto3592[2]=it_Auto3592;
	_Context->msg_Auto3592[3]=es_Auto3592;
	_Context->msg_Auto3592[4]=de_Auto3592;
	_Context->msg_Auto3592[5]=nl_Auto3592;
	_Context->msg_Auto3592[6]=pt_Auto3592;
	_Context->msg_Auto3592[7]=xx_Auto3592;
	for (i=0; i < 8; i++)_Context->msg_Auto3593[i]=" ";
	_Context->msg_Auto3593[0]=en_Auto3593;
	_Context->msg_Auto3593[1]=fr_Auto3593;
	_Context->msg_Auto3593[2]=it_Auto3593;
	_Context->msg_Auto3593[3]=es_Auto3593;
	_Context->msg_Auto3593[4]=de_Auto3593;
	_Context->msg_Auto3593[5]=nl_Auto3593;
	_Context->msg_Auto3593[6]=pt_Auto3593;
	_Context->msg_Auto3593[7]=xx_Auto3593;
	for (i=0; i < 8; i++)_Context->msg_Liste[i]=" ";
	_Context->msg_Liste[0]=en_Liste;
	_Context->msg_Liste[1]=fr_Liste;
	_Context->msg_Liste[2]=it_Liste;
	_Context->msg_Liste[3]=es_Liste;
	_Context->msg_Liste[4]=de_Liste;
	_Context->msg_Liste[5]=nl_Liste;
	_Context->msg_Liste[6]=pt_Liste;
	_Context->msg_Liste[7]=xx_Liste;
	if ( 0 > 0 ) { _Context->row_Liste=&_Context->buffer_Liste[0-1][0]; } ;
	_Context->max_Slider=1;
	_Context->value_Slider=1;
	_Context->limit_Slider=1;
	(void) on_Slider_create(_Context);
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3590,_Context->y_Auto3590,830+10,220+10);
	return(0);
}

public 	int	accept_variable_inspection_hide(struct accept_variable_inspection_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3590,_Context->y_Auto3590);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_variable_inspection_remove(
	struct accept_variable_inspection_context * _Context,
	char * pVariable,
	char * pFirstDim,
	char * pSecondDim,
	char * pCounter)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Variable, 77, pVariable);
		visual_transferout(_Context->buffer_FirstDim, 5, pFirstDim);
		visual_transferout(_Context->buffer_SecondDim, 5, pSecondDim);
		visual_transferout(_Context->buffer_Counter, 6, pCounter);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Liste_show(struct accept_variable_inspection_context * _Context) {
	int l;
	int DebugGetVariable(int,char*,int,char*,int,char*,int,char*,int);
	memset(_Context->buffer_Liste,' ',776);
	for(l=1;l<=8;l++){
	if ( l > 0 ) { _Context->row_Liste=&_Context->buffer_Liste[l-1][0]; } ;
	if(!(DebugGetVariable(
	(_Context->value_Slider+l),
	(_Context->row_Liste+0),9,
	(_Context->row_Liste+9),25,
	(_Context->row_Liste+34),9,
	(_Context->row_Liste+43),54)))
	break;
	}
		visual_table(_Context->x_Auto3590+10,_Context->y_Auto3590+60,780,150,vfh[1],27,28,_Context->msg_Liste[_Context->language],_Context->buffer_Liste,0x4401,"(W8,W24,W8,$)");
;
	return(-1);
}

public	int	accept_variable_inspection_show(struct accept_variable_inspection_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3590,_Context->y_Auto3590);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto3590,_Context->y_Auto3590,830,220,vfh[2],_Context->msg_Auto3590[_Context->language],strlen(_Context->msg_Auto3590[_Context->language]),0x407);
	visual_frame(_Context->x_Auto3590+10,_Context->y_Auto3590+30,616+2,16+2,5);
	visual_text(_Context->x_Auto3590+10+1,_Context->y_Auto3590+30+1,616,16,vfh[1],27,28,_Context->buffer_Variable,77,0);
	visual_frame(_Context->x_Auto3590+650,_Context->y_Auto3590+30,40+2,16+2,5);
	visual_text(_Context->x_Auto3590+650+1,_Context->y_Auto3590+30+1,40,16,vfh[1],27,28,_Context->buffer_FirstDim,5,0);
	visual_frame(_Context->x_Auto3590+710,_Context->y_Auto3590+30,40+2,16+2,5);
	visual_text(_Context->x_Auto3590+710+1,_Context->y_Auto3590+30+1,40,16,vfh[1],27,28,_Context->buffer_SecondDim,5,0);
	visual_text(_Context->x_Auto3590+630,_Context->y_Auto3590+30,20,20,vfh[2],16,0,_Context->msg_Auto3591[_Context->language],strlen(_Context->msg_Auto3591[_Context->language]),1283);
	visual_text(_Context->x_Auto3590+750,_Context->y_Auto3590+30,20,20,vfh[2],16,0,_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]),1283);
	visual_text(_Context->x_Auto3590+690,_Context->y_Auto3590+30,20,20,vfh[2],16,0,_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]),1283);
	visual_frame(_Context->x_Auto3590+770,_Context->y_Auto3590+30,48+2,16+2,5);
	visual_text(_Context->x_Auto3590+770+1,_Context->y_Auto3590+30+1,48,16,vfh[1],0,0,_Context->buffer_Counter,6,0);
	(void) on_Liste_show(_Context);
	visual_scrollbar(_Context->x_Auto3590+800,_Context->y_Auto3590+60,20,150,vfh[1],27,28,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
	visual_thaw(_Context->x_Auto3590,_Context->y_Auto3590,830,220);

	return(0);
}

private int Auto3590action(struct accept_variable_inspection_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_variable_inspection_hide(_Context);

		_Context->x_Auto3590 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3590 < 0) { _Context->x_Auto3590=0; }
		_Context->y_Auto3590 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3590 < 0) { _Context->y_Auto3590=0; }
			accept_variable_inspection_show(_Context);

		visual_thaw(_Context->x_Auto3590,_Context->y_Auto3590,830,220);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Liste_event(struct accept_variable_inspection_context * _Context) {
	int l;
	int i;
	l=_Context->value_Liste;
	if(l!=0){
	if ( l > 0 ) { _Context->row_Liste=&_Context->buffer_Liste[l-1][0]; } ;
	DebugDumpZone((_Context->row_Liste+9),25,(_Context->row_Liste+34),9);
	}
	return(-1);
}
private int on_Slider_event(struct accept_variable_inspection_context * _Context) {
	on_Liste_show(_Context);
	return(-1);
}

private int on_Slider_action(struct accept_variable_inspection_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto3590+60+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Slider -= 1;
		if (_Context->value_Slider < 0) 
			_Context->value_Slider = 0;
		(void) on_Slider_event(_Context);
	visual_scrollbar(_Context->x_Auto3590+800,_Context->y_Auto3590+60,20,150,vfh[1],27,28,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto3590+60+150-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Slider += 1;
		if (!(_Context->max_Slider))
			_Context->value_Slider = 0;
		else if ((_Context->max_Slider < _Context->limit_Slider) 
		&& (_Context->value_Slider >= _Context->max_Slider)) 
			_Context->value_Slider = (_Context->max_Slider-1);
		else if (_Context->value_Slider > (_Context->max_Slider-_Context->limit_Slider)) 
			_Context->value_Slider = (_Context->max_Slider-_Context->limit_Slider);
		(void) on_Slider_event(_Context);
	visual_scrollbar(_Context->x_Auto3590+800,_Context->y_Auto3590+60,20,150,vfh[1],27,28,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto3590+800,_Context->y_Auto3590+60,20,150,vfh[1],27,28,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_Slider;
		_Context->value_Slider = (((visual_event(6) - (_Context->y_Auto3590+60+20)) * _Context->max_Slider) / (150 - (2 * 20)));
		if (_Context->value_Slider < 0) 
			_Context->value_Slider = 0;
		else if (_Context->value_Slider > (_Context->max_Slider-_Context->limit_Slider)) 
			_Context->value_Slider = (_Context->max_Slider-_Context->limit_Slider);
		if (_Context->value_Slider != aty) {
		(void) on_Slider_event(_Context);
	visual_scrollbar(_Context->x_Auto3590+800,_Context->y_Auto3590+60,20,150,vfh[1],27,28,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
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
	visual_scrollbar(_Context->x_Auto3590+800,_Context->y_Auto3590+60,20,150,vfh[1],27,28,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_Slider += (_Context->limit_Slider/2);
			if (!(_Context->max_Slider))
				_Context->value_Slider = 0;
			else if ((_Context->max_Slider < _Context->limit_Slider) 
			&& (_Context->value_Slider >= _Context->max_Slider)) 
				_Context->value_Slider = (_Context->max_Slider-1);
			else if (_Context->value_Slider > (_Context->max_Slider-_Context->limit_Slider)) 
				_Context->value_Slider = (_Context->max_Slider-_Context->limit_Slider);
		(void) on_Slider_event(_Context);
	visual_scrollbar(_Context->x_Auto3590+800,_Context->y_Auto3590+60,20,150,vfh[1],27,28,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto3590+800,_Context->y_Auto3590+60,20,150,vfh[1],27,28,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);

	return(1);
}


public	int	accept_variable_inspection_event(
struct accept_variable_inspection_context * _Context){
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
	if ((mx >= (_Context->x_Auto3590+809) )  
	&&  (my >= (_Context->y_Auto3590+4) )  
	&&  (mx <= (_Context->x_Auto3590+826) )  
	&&  (my <= (_Context->y_Auto3590+20) )) {
		return(1);	/* Auto3590 */

		}
	if ((mx >= (_Context->x_Auto3590+793) )  
	&&  (my >= (_Context->y_Auto3590+4) )  
	&&  (mx <= (_Context->x_Auto3590+810) )  
	&&  (my <= (_Context->y_Auto3590+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vshow.htm");
			};
		return(-1);	/* Auto3590 */

		}
	if ((mx >= (_Context->x_Auto3590+777) )  
	&&  (my >= (_Context->y_Auto3590+4) )  
	&&  (mx <= (_Context->x_Auto3590+794) )  
	&&  (my <= (_Context->y_Auto3590+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_variable_inspection_show(_Context);
		return(-1);	/* Auto3590 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3590+4) )  
		&&  (my >= (_Context->y_Auto3590+4) )  
		&&  (mx <= (_Context->x_Auto3590+762) )  
		&&  (my <= (_Context->y_Auto3590+20) )) {
			return( Auto3590action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3590+10) ) 
	&&  ( my >= (_Context->y_Auto3590+30) ) 
	&&  ( mx <= (_Context->x_Auto3590+10+616) ) 
	&&  ( my <= (_Context->y_Auto3590+30+16))) {
		return(2); /* Variable */
		}
	if (( mx >= (_Context->x_Auto3590+650) ) 
	&&  ( my >= (_Context->y_Auto3590+30) ) 
	&&  ( mx <= (_Context->x_Auto3590+650+40) ) 
	&&  ( my <= (_Context->y_Auto3590+30+16))) {
		return(3); /* FirstDim */
		}
	if (( mx >= (_Context->x_Auto3590+710) ) 
	&&  ( my >= (_Context->y_Auto3590+30) ) 
	&&  ( mx <= (_Context->x_Auto3590+710+40) ) 
	&&  ( my <= (_Context->y_Auto3590+30+16))) {
		return(4); /* SecondDim */
		}
	if (( mx >= (_Context->x_Auto3590+770) ) 
	&&  ( my >= (_Context->y_Auto3590+30) ) 
	&&  ( mx <= (_Context->x_Auto3590+770+48) ) 
	&&  ( my <= (_Context->y_Auto3590+30+16))) {
		return(5); /* Counter */
		}
	if (( mx >= (_Context->x_Auto3590+10) ) 
	&&  ( my >= (_Context->y_Auto3590+60) ) 
	&&  ( mx <= (_Context->x_Auto3590+10+780) ) 
	&&  ( my <= (_Context->y_Auto3590+60+150))) {
		if ((_Context->value_Liste = ((visual_event(6) - (_Context->y_Auto3590+60)) / 16)) < 1)
			_Context->value_Liste=0;
else if (_Context->value_Liste > 8 )
			_Context->value_Liste=8;
		if ( _Context->value_Liste > 0 ) { _Context->row_Liste = &_Context->buffer_Liste[(_Context->value_Liste-1)][0]; } 
		_Context->column_Liste = (visual_event(7) - (_Context->x_Auto3590+10));
		if ( _Context->column_Liste < 72 ) {
			_Context->column_Liste = 1;
			}
		else if ( _Context->column_Liste < 272 ) {
			_Context->column_Liste = 2;
			}
		else if ( _Context->column_Liste < 344 ) {
			_Context->column_Liste = 3;
			}
		else if ( _Context->column_Liste < 776 ) {
			_Context->column_Liste = 4;
			}
		if ((!(_Context->value_Liste)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
			if (_Context->formsort_Liste==_Context->column_Liste) /* si colonne choisie concerne déjà le tri */
				_Context->formsort_Liste=-_Context->column_Liste;	/* alors tri décroissant */
			else
				_Context->formsort_Liste=_Context->column_Liste; };	/* sinon tri croissant */
		return(6); /* Liste */
		}
	if (( mx >= (_Context->x_Auto3590+800) ) 
	&&  ( my >= (_Context->y_Auto3590+60) ) 
	&&  ( mx <= (_Context->x_Auto3590+800+20) ) 
	&&  ( my <= (_Context->y_Auto3590+60+150))) {
		return(7); /* Slider */
		}

	return(-1);
}
private int on_FirstDim_losefocus(struct accept_variable_inspection_context * _Context) {
	DebugSetDimensions(_Context->buffer_FirstDim,5,_Context->buffer_SecondDim,5);
		accept_variable_inspection_show(_Context);
;
	return(-1);
}
private int on_SecondDim_losefocus(struct accept_variable_inspection_context * _Context) {
	DebugSetDimensions(_Context->buffer_FirstDim,5,_Context->buffer_SecondDim,5);
		accept_variable_inspection_show(_Context);
;
	return(-1);
}


public	int	accept_variable_inspection_focus(struct accept_variable_inspection_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Variable */
				_Context->keycode = visual_edit(_Context->x_Auto3590+10+1,_Context->y_Auto3590+30+1,616,16,vfh[1],_Context->buffer_Variable,77);
			break;
			case	0x3 :
				/* FirstDim */
				_Context->keycode = visual_edit(_Context->x_Auto3590+650+1,_Context->y_Auto3590+30+1,40,16,vfh[1],_Context->buffer_FirstDim,5);
				(void) on_FirstDim_losefocus(_Context);
			break;
			case	0x4 :
				/* SecondDim */
				_Context->keycode = visual_edit(_Context->x_Auto3590+710+1,_Context->y_Auto3590+30+1,40,16,vfh[1],_Context->buffer_SecondDim,5);
				(void) on_SecondDim_losefocus(_Context);
			break;
			case	0x7 :
				/* Slider */
				_Context->keycode=visual_getch();
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_variable_inspection_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=7;
			accept_variable_inspection_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_variable_inspection_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3590 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Variable */
					continue;
				case	0x3 :
					/* FirstDim */
					continue;
				case	0x4 :
					/* SecondDim */
					continue;
				case	0x5 :
					/* Counter */
					continue;
				case	0x6 :
					/* Liste */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_Liste_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Slider */
					(void) on_Slider_action(_Context);
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
				_Context->focus_item=7;
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

public	int	accept_variable_inspection(
	char * pVariable,
	char * pFirstDim,
	char * pSecondDim,
	char * pCounter)
{
	int	status=0;
	struct accept_variable_inspection_context * _Context=(struct accept_variable_inspection_context*) 0;
	status = accept_variable_inspection_create(
	&_Context,
	 pVariable,
	 pFirstDim,
	 pSecondDim,
	 pCounter);
	if ( status != 0) return(status);
	status = accept_variable_inspection_show(_Context);
		enter_modal();
	status = accept_variable_inspection_focus(_Context);
		leave_modal();
	status = accept_variable_inspection_hide(_Context);
	status = accept_variable_inspection_remove(
	_Context,
	 pVariable,
	 pFirstDim,
	 pSecondDim,
	 pCounter);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vshow_c */
