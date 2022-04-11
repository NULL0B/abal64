
#ifndef _vwatch_c
#define _vwatch_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vwatch.xml                                               */
/* Target         : vwatch.c                                                 */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto3600   "Debug Memory Inspection"
#define fr_Auto3600   "Modification de la M‚moire"
#define it_Auto3600   "Debug Memory Inspection"
#define es_Auto3600   "Debug Memory Inspection"
#define de_Auto3600   "Debug Memory Inspection"
#define nl_Auto3600   "Debug Memory Inspection"
#define pt_Auto3600   "Debug Memory Inspection"
#define xx_Auto3600   "Debug Memory Inspection"
#define en_Auto3601   ""
#define en_Adresse   ""
#define en_VariableName   ""
#define en_DumpZone   "MEMORY|00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F|0123456789ABCDEF"
#define fr_DumpZone   "MEMORY|00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F|0123456789ABCDEF"
#define it_DumpZone   "MEMORY|00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F|0123456789ABCDEF"
#define es_DumpZone   "MEMORY|00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F|0123456789ABCDEF"
#define de_DumpZone   "MEMORY|00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F|0123456789ABCDEF"
#define nl_DumpZone   "MEMORY|00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F|0123456789ABCDEF"
#define pt_DumpZone   "MEMORY|00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F|0123456789ABCDEF"
#define xx_DumpZone   "MEMORY|00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F|0123456789ABCDEF"
#define en__DumpZone   ""
#define en_DragBar   ""
#define en__DragBar   ""

private struct accept_watch_inspection_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3600[8];
	char * hint_Auto3600[8];
	int	x_Auto3600;
	int	y_Auto3600;
	int	w_Auto3600;
	int	h_Auto3600;
	char * hint_Auto3601[8];
	char * hint_Adresse[8];
	char	buffer_Adresse[10];
	char * hint_VariableName[8];
	char	buffer_VariableName[68];
	char * msg_DumpZone[8];
	char * hint_DumpZone[8];
	int	value_DumpZone;
	int	column_DumpZone;
	char	buffer_DumpZone[26][74];
	int	formsort_DumpZone;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char	*libsort_DumpZone;	/* table intermédiaire contenant la liste des éléments a trier */
	int	*tabsort_DumpZone;	/* numéro d'ordre des elements triés */
	char	*indsort_DumpZone;	/* pointeur table intermédiaire de tri */
	int	nelt_DumpZone;	/* nombre d'eléments aloués dans tabsort */
	char * row_DumpZone;
	char * hint_DragBar[8];
	int	value_DragBar;
	int	limit_DragBar;
	int	max_DragBar;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];
private int on_DumpZone_show(struct accept_watch_inspection_context * _Context);
private int on_DragBar_event(struct accept_watch_inspection_context * _Context);
private int  sort_item_DumpZone(struct accept_watch_inspection_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_DumpZone(struct accept_watch_inspection_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_DumpZone(struct accept_watch_inspection_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_DumpZone */
private int compare_DumpZone(struct accept_watch_inspection_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_DumpZone */
/* ------------------- */
/* resolve sorted item */
/* ------------------- */
private int  sort_item_DumpZone(struct accept_watch_inspection_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_DumpZone[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_DumpZone(struct accept_watch_inspection_context * _Context,int nelts)
{
if (_Context->nelt_DumpZone<nelts) {
	liberate(_Context->tabsort_DumpZone);
	if ((_Context->tabsort_DumpZone=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_DumpZone=0;_Context->nelt_DumpZone<nelts;_Context->nelt_DumpZone++)
		{ _Context->tabsort_DumpZone[_Context->nelt_DumpZone]=_Context->nelt_DumpZone+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_DumpZone=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_DumpZone=allocate(nelts*74)) != NULL)
	memset(_Context->libsort_DumpZone,' ',nelts*74);
}

/* ----------------------------------------------------------- */
/* sort the intermediate table into _Context->tabsort_DumpZone */
/* ----------------------------------------------------------- */
private void sort_DumpZone(struct accept_watch_inspection_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_DumpZone,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_DumpZone[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_DumpZone[j]) && (compare_DumpZone(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_DumpZone[i]=k+1;
	_Context->indsort_DumpZone[k]=1;
	};	/* for i */
liberate(_Context->libsort_DumpZone);
liberate(_Context->indsort_DumpZone);
}

/* --------------------------------------------------------- */
/* compare the elements a et b of _Context->libsort_DumpZone */
/* --------------------------------------------------------- */
private int compare_DumpZone(struct accept_watch_inspection_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_DumpZone[74*a],&_Context->libsort_DumpZone[74*b],9);	/* comparaison zone 1 */
switch (_Context->formsort_DumpZone) {
	case 1:	/* MEMORY ordre normal */
		return(i);

	case -1:	/* MEMORY ordre inverse */
		return(-i);

	case 2:	/* 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F ordre normal */
		j=memicmp(&_Context->libsort_DumpZone[74*a+9],&_Context->libsort_DumpZone[74*b+9],49);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -2:	/* 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F ordre inverse */
		j=memicmp(&_Context->libsort_DumpZone[74*b+9],&_Context->libsort_DumpZone[74*a+9],49);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 3:	/* 0123456789ABCDEF ordre normal */
		j=memicmp(&_Context->libsort_DumpZone[74*a+58],&_Context->libsort_DumpZone[74*b+58],16);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -3:	/* 0123456789ABCDEF ordre inverse */
		j=memicmp(&_Context->libsort_DumpZone[74*b+58],&_Context->libsort_DumpZone[74*a+58],16);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);
	default:		/* pas de tri */
		if (a<b) return(-1);
		return(1);
	}; /* fin du switch */
}


public	int	accept_watch_inspection_create(
	struct accept_watch_inspection_context ** cptr,
	char * pAdresse,
	char * pVariableName)
{

	int i;
	struct accept_watch_inspection_context * _Context=(struct accept_watch_inspection_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_watch_inspection_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=5;
	_Context->formsort_DumpZone=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_DumpZone=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_DumpZone=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_DumpZone=0;_Context->nelt_DumpZone<512;_Context->nelt_DumpZone++)
			{ _Context->tabsort_DumpZone[_Context->nelt_DumpZone]=_Context->nelt_DumpZone+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_DumpZone=0; /* si problème d'allocation */
_Context->indsort_DumpZone=NULL;	/* pas de pointeur de table intermédiaire */		_Context->max_DragBar=0;
		_Context->limit_DragBar=0;
		_Context->value_DragBar=0;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Adresse, 9, pAdresse);
		visual_transferin(_Context->buffer_VariableName, 67, pVariableName);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3600[i]=" ";
	_Context->msg_Auto3600[0]=en_Auto3600;
	_Context->msg_Auto3600[1]=fr_Auto3600;
	_Context->msg_Auto3600[2]=it_Auto3600;
	_Context->msg_Auto3600[3]=es_Auto3600;
	_Context->msg_Auto3600[4]=de_Auto3600;
	_Context->msg_Auto3600[5]=nl_Auto3600;
	_Context->msg_Auto3600[6]=pt_Auto3600;
	_Context->msg_Auto3600[7]=xx_Auto3600;
	_Context->x_Auto3600=70;
	_Context->y_Auto3600=45;
	_Context->w_Auto3600=660;
	_Context->h_Auto3600=510;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_DumpZone[i]=" ";
	_Context->msg_DumpZone[0]=en_DumpZone;
	_Context->msg_DumpZone[1]=fr_DumpZone;
	_Context->msg_DumpZone[2]=it_DumpZone;
	_Context->msg_DumpZone[3]=es_DumpZone;
	_Context->msg_DumpZone[4]=de_DumpZone;
	_Context->msg_DumpZone[5]=nl_DumpZone;
	_Context->msg_DumpZone[6]=pt_DumpZone;
	_Context->msg_DumpZone[7]=xx_DumpZone;
	_Context->hint_DumpZone[0]=en__DumpZone;
	if ( 0 > 0 ) { _Context->row_DumpZone=&_Context->buffer_DumpZone[0-1][0]; } ;
	_Context->hint_DragBar[0]=en__DragBar;
	_Context->max_DragBar=1;
	_Context->value_DragBar=1;
	_Context->limit_DragBar=1;
	_Context->value_DragBar=0;
	_Context->limit_DragBar=16;
	_Context->max_DragBar=0x8000;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3600,_Context->y_Auto3600,660+10,510+10);
	return(0);
}

public 	int	accept_watch_inspection_hide(struct accept_watch_inspection_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3600,_Context->y_Auto3600);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_watch_inspection_remove(
	struct accept_watch_inspection_context * _Context,
	char * pAdresse,
	char * pVariableName)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Adresse, 9, pAdresse);
		visual_transferout(_Context->buffer_VariableName, 67, pVariableName);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_DumpZone_show(struct accept_watch_inspection_context * _Context) {
	unsigned char*vptr;
	unsigned char*cptr;
	unsigned char*sptr;
	unsigned long value=0L;
	char muffer[16];
	int vlen;
	int l;
	int i;
	int x;
	int y;
	int c;
	/*calculate the start adresse*/
	/*---------------------------*/
	for(x=0;x<9;x++){
	if(!(c=_Context->buffer_Adresse[x]))
	break;
	else if(c==' ')
	break;
	else if((c>='0')&&(c<='9'))
	value=((value*16L)+((long)(c-'0')));
	else if((c>='a')&&(c<='f'))
	value=((value*16L)+((long)((c-'a')+10)));
	else if((c>='A')&&(c<='F'))
	value=((value*16L)+((long)((c-'A')+10)));
	}
	/*Add in the scrollbar offset*/
	/*---------------------------*/
	sptr=(unsigned char*)(value+(_Context->value_DragBar*16));
	memset(_Context->buffer_DumpZone,' ',1850);
	for(l=1;l<=25;l++){
	/*Calculate and display the adresse*/
	/*---------------------------------*/
	if ( l > 0 ) { _Context->row_DumpZone=&_Context->buffer_DumpZone[l-1][0]; } ;
	sprintf(muffer,"%08.8X",(sptr+((l-1)*16)));
	vptr=(_Context->row_DumpZone+0);vlen=9;
	for(x=0;x<vlen;x++){
	if(!(muffer[x]))
	break;
	else*(vptr+x)=muffer[x];
	}
	/*display the hexadecimal and character data*/
	/*------------------------------------------*/
	vptr=(_Context->row_DumpZone+9);vlen=49;
	cptr=(_Context->row_DumpZone+58);vlen=16;
	for(x=0;x<16;x++){
	if(VerifPtr((sptr+((l-1)*16)+x)))
	break;
	c=(*(sptr+((l-1)*16)+x)&0x00FF);
	if(c>=32)
	*(cptr++)=c;
	else*(cptr++)='.';
	sprintf(muffer,"%02.2X",c);
	vptr++;
	*(vptr++)=muffer[0];
	*(vptr++)=muffer[1];
	}
	}
	visual_freeze();
		visual_table(_Context->x_Auto3600+20,_Context->y_Auto3600+60,596,420,vfh[1],27,28,_Context->msg_DumpZone[_Context->language],_Context->buffer_DumpZone,0x4406,"(W8,W48,$)");
;
	visual_thaw(_Context->x_Auto3600+20,_Context->y_Auto3600+60,596,420);
	return(-1);
}

public	int	accept_watch_inspection_show(struct accept_watch_inspection_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3600,_Context->y_Auto3600);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto3600,_Context->y_Auto3600,660,510,vfh[2],_Context->msg_Auto3600[_Context->language],strlen(_Context->msg_Auto3600[_Context->language]),0x407);
	visual_frame(_Context->x_Auto3600+10,_Context->y_Auto3600+30,640,470,3);
	visual_frame(_Context->x_Auto3600+20,_Context->y_Auto3600+40,72+2,16+2,5);
	visual_text(_Context->x_Auto3600+20+1,_Context->y_Auto3600+40+1,72,16,vfh[1],27,28,_Context->buffer_Adresse,9,0);
	visual_frame(_Context->x_Auto3600+100,_Context->y_Auto3600+40,540+2,16+2,5);
	visual_text(_Context->x_Auto3600+100+1,_Context->y_Auto3600+40+1,540,16,vfh[1],27,28,_Context->buffer_VariableName,67,0);
	(void) on_DumpZone_show(_Context);
	visual_scrollbar(_Context->x_Auto3600+620,_Context->y_Auto3600+60,20,420,vfh[1],27,28,_Context->value_DragBar,_Context->limit_DragBar,_Context->max_DragBar,259);
	visual_thaw(_Context->x_Auto3600,_Context->y_Auto3600,660,510);

	return(0);
}

private int Auto3600action(struct accept_watch_inspection_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_watch_inspection_hide(_Context);

		_Context->x_Auto3600 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3600 < 0) { _Context->x_Auto3600=0; }
		_Context->y_Auto3600 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3600 < 0) { _Context->y_Auto3600=0; }
			accept_watch_inspection_show(_Context);

		visual_thaw(_Context->x_Auto3600,_Context->y_Auto3600,660,510);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_DragBar_event(struct accept_watch_inspection_context * _Context) {
	on_DumpZone_show(_Context);
	return(-1);
}

private int on_DragBar_action(struct accept_watch_inspection_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto3600+60+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_DragBar -= 1;
		if (_Context->value_DragBar < 0) 
			_Context->value_DragBar = 0;
		(void) on_DragBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3600+620,_Context->y_Auto3600+60,20,420,vfh[1],27,28,_Context->value_DragBar,_Context->limit_DragBar,_Context->max_DragBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto3600+60+420-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_DragBar += 1;
		if (!(_Context->max_DragBar))
			_Context->value_DragBar = 0;
		else if ((_Context->max_DragBar < _Context->limit_DragBar) 
		&& (_Context->value_DragBar >= _Context->max_DragBar)) 
			_Context->value_DragBar = (_Context->max_DragBar-1);
		else if (_Context->value_DragBar > (_Context->max_DragBar-_Context->limit_DragBar)) 
			_Context->value_DragBar = (_Context->max_DragBar-_Context->limit_DragBar);
		(void) on_DragBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3600+620,_Context->y_Auto3600+60,20,420,vfh[1],27,28,_Context->value_DragBar,_Context->limit_DragBar,_Context->max_DragBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto3600+620,_Context->y_Auto3600+60,20,420,vfh[1],27,28,_Context->value_DragBar,_Context->limit_DragBar,_Context->max_DragBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_DragBar;
		_Context->value_DragBar = (((visual_event(6) - (_Context->y_Auto3600+60+20)) * _Context->max_DragBar) / (420 - (2 * 20)));
		if (_Context->value_DragBar < 0) 
			_Context->value_DragBar = 0;
		else if (_Context->value_DragBar > (_Context->max_DragBar-_Context->limit_DragBar)) 
			_Context->value_DragBar = (_Context->max_DragBar-_Context->limit_DragBar);
		if (_Context->value_DragBar != aty) {
		(void) on_DragBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3600+620,_Context->y_Auto3600+60,20,420,vfh[1],27,28,_Context->value_DragBar,_Context->limit_DragBar,_Context->max_DragBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_DragBar -= (_Context->limit_DragBar/2);
			if (_Context->value_DragBar < 0) 
				_Context->value_DragBar = 0;
		(void) on_DragBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3600+620,_Context->y_Auto3600+60,20,420,vfh[1],27,28,_Context->value_DragBar,_Context->limit_DragBar,_Context->max_DragBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_DragBar += (_Context->limit_DragBar/2);
			if (!(_Context->max_DragBar))
				_Context->value_DragBar = 0;
			else if ((_Context->max_DragBar < _Context->limit_DragBar) 
			&& (_Context->value_DragBar >= _Context->max_DragBar)) 
				_Context->value_DragBar = (_Context->max_DragBar-1);
			else if (_Context->value_DragBar > (_Context->max_DragBar-_Context->limit_DragBar)) 
				_Context->value_DragBar = (_Context->max_DragBar-_Context->limit_DragBar);
		(void) on_DragBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3600+620,_Context->y_Auto3600+60,20,420,vfh[1],27,28,_Context->value_DragBar,_Context->limit_DragBar,_Context->max_DragBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto3600+620,_Context->y_Auto3600+60,20,420,vfh[1],27,28,_Context->value_DragBar,_Context->limit_DragBar,_Context->max_DragBar,259);

	return(1);
}


public	int	accept_watch_inspection_event(
struct accept_watch_inspection_context * _Context){
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
	if ((mx >= (_Context->x_Auto3600+639) )  
	&&  (my >= (_Context->y_Auto3600+4) )  
	&&  (mx <= (_Context->x_Auto3600+656) )  
	&&  (my <= (_Context->y_Auto3600+20) )) {
		return(1);	/* Auto3600 */

		}
	if ((mx >= (_Context->x_Auto3600+623) )  
	&&  (my >= (_Context->y_Auto3600+4) )  
	&&  (mx <= (_Context->x_Auto3600+640) )  
	&&  (my <= (_Context->y_Auto3600+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vwatch.htm");
			};
		return(-1);	/* Auto3600 */

		}
	if ((mx >= (_Context->x_Auto3600+607) )  
	&&  (my >= (_Context->y_Auto3600+4) )  
	&&  (mx <= (_Context->x_Auto3600+624) )  
	&&  (my <= (_Context->y_Auto3600+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_watch_inspection_show(_Context);
		return(-1);	/* Auto3600 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3600+4) )  
		&&  (my >= (_Context->y_Auto3600+4) )  
		&&  (mx <= (_Context->x_Auto3600+592) )  
		&&  (my <= (_Context->y_Auto3600+20) )) {
			return( Auto3600action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3600+20) ) 
	&&  ( my >= (_Context->y_Auto3600+40) ) 
	&&  ( mx <= (_Context->x_Auto3600+20+72) ) 
	&&  ( my <= (_Context->y_Auto3600+40+16))) {
		return(2); /* Adresse */
		}
	if (( mx >= (_Context->x_Auto3600+100) ) 
	&&  ( my >= (_Context->y_Auto3600+40) ) 
	&&  ( mx <= (_Context->x_Auto3600+100+540) ) 
	&&  ( my <= (_Context->y_Auto3600+40+16))) {
		return(3); /* VariableName */
		}
	if (( mx >= (_Context->x_Auto3600+20) ) 
	&&  ( my >= (_Context->y_Auto3600+60) ) 
	&&  ( mx <= (_Context->x_Auto3600+20+596) ) 
	&&  ( my <= (_Context->y_Auto3600+60+420))) {
		if ((_Context->value_DumpZone = ((visual_event(6) - (_Context->y_Auto3600+60)) / 16)) < 1)
			_Context->value_DumpZone=0;
else if (_Context->value_DumpZone > 25 )
			_Context->value_DumpZone=25;
		if ( _Context->value_DumpZone > 0 ) { _Context->row_DumpZone = &_Context->buffer_DumpZone[(_Context->value_DumpZone-1)][0]; } 
		_Context->column_DumpZone = (visual_event(7) - (_Context->x_Auto3600+20));
		if ( _Context->column_DumpZone < 72 ) {
			_Context->column_DumpZone = 1;
			}
		else if ( _Context->column_DumpZone < 464 ) {
			_Context->column_DumpZone = 2;
			}
		else if ( _Context->column_DumpZone < 592 ) {
			_Context->column_DumpZone = 3;
			}
		if ((!(_Context->value_DumpZone)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
			if (_Context->formsort_DumpZone==_Context->column_DumpZone) /* si colonne choisie concerne déjà le tri */
				_Context->formsort_DumpZone=-_Context->column_DumpZone;	/* alors tri décroissant */
			else
				_Context->formsort_DumpZone=_Context->column_DumpZone; };	/* sinon tri croissant */
		return(4); /* DumpZone */
		}
	if (( mx >= (_Context->x_Auto3600+620) ) 
	&&  ( my >= (_Context->y_Auto3600+60) ) 
	&&  ( mx <= (_Context->x_Auto3600+620+20) ) 
	&&  ( my <= (_Context->y_Auto3600+60+420))) {
		return(5); /* DragBar */
		}

	return(-1);
}


public	int	accept_watch_inspection_focus(struct accept_watch_inspection_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Adresse */
				_Context->keycode = visual_edit(_Context->x_Auto3600+20+1,_Context->y_Auto3600+40+1,72,16,vfh[1],_Context->buffer_Adresse,9);
				on_DumpZone_show(_Context);
							break;
			case	0x5 :
				/* DragBar */
				_Context->keycode=visual_getch();
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_watch_inspection_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=5;
			accept_watch_inspection_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_watch_inspection_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3600 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Adresse */
					continue;
				case	0x3 :
					/* VariableName */
					continue;
				case	0x4 :
					/* DumpZone */
					continue;
				case	0x5 :
					/* DragBar */
					(void) on_DragBar_action(_Context);
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
				_Context->focus_item=5;
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

public	int	accept_watch_inspection(
	char * pAdresse,
	char * pVariableName)
{
	int	status=0;
	struct accept_watch_inspection_context * _Context=(struct accept_watch_inspection_context*) 0;
	status = accept_watch_inspection_create(
	&_Context,
	 pAdresse,
	 pVariableName);
	if ( status != 0) return(status);
	status = accept_watch_inspection_show(_Context);
		enter_modal();
	status = accept_watch_inspection_focus(_Context);
		leave_modal();
	status = accept_watch_inspection_hide(_Context);
	status = accept_watch_inspection_remove(
	_Context,
	 pAdresse,
	 pVariableName);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwatch_c */
