
#ifndef _vfselect_c
#define _vfselect_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vfselect.xml                                             */
/* Target         : vfselect.c                                               */
/* Identification : 0.0-1177511935-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto2732   ""
#define fr__Auto2732   ""
#define it__Auto2732   ""
#define es__Auto2732   ""
#define de__Auto2732   ""
#define nl__Auto2732   ""
#define pt__Auto2732   ""
#define xx__Auto2732   ""
#define en_amato666   "Current Directory Path"
#define fr_amato666   "R‚pertoire courant"
#define it_amato666   "Current Directory Path"
#define es_amato666   "Current Directory Path"
#define de_amato666   "Current Directory Path"
#define nl_amato666   "Current Directory Path"
#define pt_amato666   "Current Directory Path"
#define xx_amato666   "Current Directory Path"
#define en_Auto2733   "Selected Filename(s)"
#define fr_Auto2733   "Fichier(s) s‚lectionn‚(s)"
#define it_Auto2733   "Selected Filename(s)"
#define es_Auto2733   "Selected Filename(s)"
#define de_Auto2733   "Selected Filename(s)"
#define nl_Auto2733   "Selected Filename(s)"
#define pt_Auto2733   "Selected Filename(s)"
#define xx_Auto2733   "Selected Filename(s)"
#define en_Result   ""
#define en_Auto2734   "File Selection Criteria"
#define fr_Auto2734   "CritŠre de s‚lection de fichiers"
#define it_Auto2734   "File Selection Criteria"
#define es_Auto2734   "File Selection Criteria"
#define de_Auto2734   "File Selection Criteria"
#define nl_Auto2734   "File Selection Criteria"
#define pt_Auto2734   "File Selection Criteria"
#define xx_Auto2734   "File Selection Criteria"
#define en_Auto2735   "File Type"
#define fr_Auto2735   "Type de fichier"
#define it_Auto2735   "File Type"
#define es_Auto2735   "File Type"
#define de_Auto2735   "File Type"
#define nl_Auto2735   "File Type"
#define pt_Auto2735   "File Type"
#define xx_Auto2735   "File Type"
#define en_Auto2736   "ok.gif"
#define fr_Auto2736   "ok.gif"
#define it_Auto2736   "ok.gif"
#define es_Auto2736   "ok.gif"
#define de_Auto2736   "ok.gif"
#define nl_Auto2736   "ok.gif"
#define pt_Auto2736   "ok.gif"
#define xx_Auto2736   "ok.gif"
#define en_Find   "&Find"
#define fr_Find   "&Rechercher"
#define it_Find   "&Find"
#define es_Find   "&Find"
#define de_Find   "&Find"
#define nl_Find   "&Find"
#define pt_Find   "&Find"
#define xx_Find   "&Find"
#define en_InfoSelector   "Infos"
#define fr_InfoSelector   "Infos"
#define it_InfoSelector   "Infos"
#define es_InfoSelector   "Infos"
#define de_InfoSelector   "Infos"
#define nl_InfoSelector   "Infos"
#define pt_InfoSelector   "Infos"
#define xx_InfoSelector   "Infos"
#define en_Delete   "&Delete"
#define fr_Delete   "&Suprimer"
#define it_Delete   "&Delete"
#define es_Delete   "&Delete"
#define de_Delete   "&Delete"
#define nl_Delete   "&Delete"
#define pt_Delete   "&Delete"
#define xx_Delete   "&Delete"
#define en_Auto2737   "cancel.gif"
#define fr_Auto2737   "cancel.gif"
#define it_Auto2737   "cancel.gif"
#define es_Auto2737   "cancel.gif"
#define de_Auto2737   "cancel.gif"
#define nl_Auto2737   "cancel.gif"
#define pt_Auto2737   "cancel.gif"
#define xx_Auto2737   "cancel.gif"
#define en__FileType   ""
#define en_Path   ""
#define en_FileSelection   ""
#define en_Slider   ""
#define en_FileNames   "-|-|-|-"
#define fr_FileNames   "-|-|-|-"
#define it_FileNames   "-|-|-|-"
#define es_FileNames   "-|-|-|-"
#define de_FileNames   "-|-|-|-"
#define nl_FileNames   "-|-|-|-"
#define pt_FileNames   "-|-|-|-"
#define xx_FileNames   "-|-|-|-"
#define en_FileInfos   "Name|Size|Time|Date"
#define fr_FileInfos   "Nom|Taille|Heure|Date"
#define it_FileInfos   "Name|Size|Time|Date"
#define es_FileInfos   "Name|Size|Time|Date"
#define de_FileInfos   "Name|Size|Time|Date"
#define nl_FileInfos   "Name|Size|Time|Date"
#define pt_FileInfos   "Name|Size|Time|Date"
#define xx_FileInfos   "Name|Size|Time|Date"

private struct file_selector_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2732[8];
	char * hint_Auto2732[8];
	int	x_Auto2732;
	int	y_Auto2732;
	int	w_Auto2732;
	int	h_Auto2732;
	char * msg_amato666[8];
	char * hint_amato666[8];
	char * msg_Auto2733[8];
	char * hint_Auto2733[8];
	char * hint_Result[8];
	char	buffer_Result[256];
	char * msg_Auto2734[8];
	char * hint_Auto2734[8];
	char * msg_Auto2735[8];
	char * hint_Auto2735[8];
	char * msg_Auto2736[8];
	int	trigger_Auto2736;
	char * hint_Auto2736[8];
	char * msg_Find[8];
	int	trigger_Find;
	char * hint_Find[8];
	char * msg_InfoSelector[8];
	int	trigger_InfoSelector;
	char * hint_InfoSelector[8];
	int	value_InfoSelector;
	char * msg_Delete[8];
	int	trigger_Delete;
	char * hint_Delete[8];
	char * msg_Auto2737[8];
	int	trigger_Auto2737;
	char * hint_Auto2737[8];
	char * msg_FileType[8];
	char * hint_FileType[8];
	int	value_FileType;
	char * hint_Path[8];
	char	buffer_Path[256];
	char * hint_FileSelection[8];
	char	buffer_FileSelection[256];
	char * hint_Slider[8];
	int	value_Slider;
	int	limit_Slider;
	int	max_Slider;
	char * msg_FileNames[8];
	char * hint_FileNames[8];
	int	value_FileNames;
	int	column_FileNames;
	char	buffer_FileNames[18][78];
	int	formsort_FileNames;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char	*libsort_FileNames;	/* table intermédiaire contenant la liste des éléments a trier */
	int	*tabsort_FileNames;	/* numéro d'ordre des elements triés */
	char	*indsort_FileNames;	/* pointeur table intermédiaire de tri */
	int	nelt_FileNames;	/* nombre d'eléments aloués dans tabsort */
	char * row_FileNames;
	char * msg_FileInfos[8];
	char * hint_FileInfos[8];
	int	value_FileInfos;
	int	column_FileInfos;
	char	buffer_FileInfos[18][78];
	int	formsort_FileInfos;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char	*libsort_FileInfos;	/* table intermédiaire contenant la liste des éléments a trier */
	int	*tabsort_FileInfos;	/* numéro d'ordre des elements triés */
	char	*indsort_FileInfos;	/* pointeur table intermédiaire de tri */
	int	nelt_FileInfos;	/* nombre d'eléments aloués dans tabsort */
	char * row_FileInfos;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[5];
	};
static int	vfh[16];
private int  sort_item_FileNames(struct file_selector_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_FileNames(struct file_selector_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_FileNames(struct file_selector_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_FileNames */
private int compare_FileNames(struct file_selector_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_FileNames */
private int  sort_item_FileInfos(struct file_selector_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_FileInfos(struct file_selector_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_FileInfos(struct file_selector_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_FileInfos */
private int compare_FileInfos(struct file_selector_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_FileInfos */
/* ------------------- */
/* resolve sorted item */
/* ------------------- */
private int  sort_item_FileNames(struct file_selector_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_FileNames[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_FileNames(struct file_selector_context * _Context,int nelts)
{
if (_Context->nelt_FileNames<nelts) {
	liberate(_Context->tabsort_FileNames);
	if ((_Context->tabsort_FileNames=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_FileNames=0;_Context->nelt_FileNames<nelts;_Context->nelt_FileNames++)
		{ _Context->tabsort_FileNames[_Context->nelt_FileNames]=_Context->nelt_FileNames+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_FileNames=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_FileNames=allocate(nelts*78)) != NULL)
	memset(_Context->libsort_FileNames,' ',nelts*78);
}

/* ------------------------------------------------------------ */
/* sort the intermediate table into _Context->tabsort_FileNames */
/* ------------------------------------------------------------ */
private void sort_FileNames(struct file_selector_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_FileNames,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_FileNames[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_FileNames[j]) && (compare_FileNames(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_FileNames[i]=k+1;
	_Context->indsort_FileNames[k]=1;
	};	/* for i */
liberate(_Context->libsort_FileNames);
liberate(_Context->indsort_FileNames);
}

/* ---------------------------------------------------------- */
/* compare the elements a et b of _Context->libsort_FileNames */
/* ---------------------------------------------------------- */
private int compare_FileNames(struct file_selector_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_FileNames[78*a],&_Context->libsort_FileNames[78*b],20);	/* comparaison zone 1 */
switch (_Context->formsort_FileNames) {
	case 1:	/* - ordre normal */
		return(i);

	case -1:	/* - ordre inverse */
		return(-i);

	case 2:	/* - ordre normal */
		j=memicmp(&_Context->libsort_FileNames[78*a+20],&_Context->libsort_FileNames[78*b+20],20);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -2:	/* - ordre inverse */
		j=memicmp(&_Context->libsort_FileNames[78*b+20],&_Context->libsort_FileNames[78*a+20],20);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 3:	/* - ordre normal */
		j=memicmp(&_Context->libsort_FileNames[78*a+40],&_Context->libsort_FileNames[78*b+40],19);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -3:	/* - ordre inverse */
		j=memicmp(&_Context->libsort_FileNames[78*b+40],&_Context->libsort_FileNames[78*a+40],19);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 4:	/* - ordre normal */
		j=memicmp(&_Context->libsort_FileNames[78*a+59],&_Context->libsort_FileNames[78*b+59],19);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -4:	/* - ordre inverse */
		j=memicmp(&_Context->libsort_FileNames[78*b+59],&_Context->libsort_FileNames[78*a+59],19);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);
	default:		/* pas de tri */
		if (a<b) return(-1);
		return(1);
	}; /* fin du switch */
}

/* ------------------- */
/* resolve sorted item */
/* ------------------- */
private int  sort_item_FileInfos(struct file_selector_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_FileInfos[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_FileInfos(struct file_selector_context * _Context,int nelts)
{
if (_Context->nelt_FileInfos<nelts) {
	liberate(_Context->tabsort_FileInfos);
	if ((_Context->tabsort_FileInfos=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_FileInfos=0;_Context->nelt_FileInfos<nelts;_Context->nelt_FileInfos++)
		{ _Context->tabsort_FileInfos[_Context->nelt_FileInfos]=_Context->nelt_FileInfos+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_FileInfos=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_FileInfos=allocate(nelts*78)) != NULL)
	memset(_Context->libsort_FileInfos,' ',nelts*78);
}

/* ------------------------------------------------------------ */
/* sort the intermediate table into _Context->tabsort_FileInfos */
/* ------------------------------------------------------------ */
private void sort_FileInfos(struct file_selector_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_FileInfos,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_FileInfos[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_FileInfos[j]) && (compare_FileInfos(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_FileInfos[i]=k+1;
	_Context->indsort_FileInfos[k]=1;
	};	/* for i */
liberate(_Context->libsort_FileInfos);
liberate(_Context->indsort_FileInfos);
}

/* ---------------------------------------------------------- */
/* compare the elements a et b of _Context->libsort_FileInfos */
/* ---------------------------------------------------------- */
private int compare_FileInfos(struct file_selector_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_FileInfos[78*a],&_Context->libsort_FileInfos[78*b],43);	/* comparaison zone 1 */
switch (_Context->formsort_FileInfos) {
	case 1:	/* Name ordre normal */
		return(i);

	case -1:	/* Name ordre inverse */
		return(-i);

	case 2:	/* Size ordre normal */
		j=memicmp(&_Context->libsort_FileInfos[78*a+43],&_Context->libsort_FileInfos[78*b+43],13);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -2:	/* Size ordre inverse */
		j=memicmp(&_Context->libsort_FileInfos[78*b+43],&_Context->libsort_FileInfos[78*a+43],13);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 3:	/* Time ordre normal */
		j=memicmp(&_Context->libsort_FileInfos[78*a+56],&_Context->libsort_FileInfos[78*b+56],11);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -3:	/* Time ordre inverse */
		j=memicmp(&_Context->libsort_FileInfos[78*b+56],&_Context->libsort_FileInfos[78*a+56],11);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 4:	/* Date ordre normal */
		j=memicmp(&_Context->libsort_FileInfos[78*a+67],&_Context->libsort_FileInfos[78*b+67],11);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -4:	/* Date ordre inverse */
		j=memicmp(&_Context->libsort_FileInfos[78*b+67],&_Context->libsort_FileInfos[78*a+67],11);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);
	default:		/* pas de tri */
		if (a<b) return(-1);
		return(1);
	}; /* fin du switch */
}

private int on_FileSelection_create(struct file_selector_context * _Context) {
	get_widget_filename(_Context->buffer_FileSelection,255,_Context->value_FileType,
	_Context->buffer_Path,255);
	return(-1);
}
private int on_Slider_create(struct file_selector_context * _Context) {
	_Context->value_Slider=0;
	_Context->limit_Slider=(17*4);
	_Context->max_Slider=0;
	return(-1);
}
private int on_FileNames_create(struct file_selector_context * _Context) {
	int w,r,c,n;
	int i=_Context->value_Slider;
	if(4>0){
	for(r=0;r<17;r++)
	for(c=0;c<78;c++)
	_Context->buffer_FileNames[r][c]=' ';
	if(!(_Context->value_InfoSelector)){
	if(_Context->value_Slider!=0)
	n=1;
	else n=0;
	for(r=1;r<=17;r++){
	if ( r > 0 ) { _Context->row_FileNames=&_Context->buffer_FileNames[r-1][0]; } ;
	if((_Context->max_Slider=filefinder(
	(_Context->row_FileNames+0),20,
	&_Context->buffer_FileSelection,255,n,i))==0)
	break;
	if(filefinder((_Context->row_FileNames+20),20,
	&_Context->buffer_FileSelection,255,(n=1),(i=0))==0)
	break;
	if(filefinder((_Context->row_FileNames+40),19,
	&_Context->buffer_FileSelection,255,n,i)==0)
	break;
	if(filefinder((_Context->row_FileNames+59),19,
	&_Context->buffer_FileSelection,255,n,i)==0)
	break;
	}
	}
	}
	return(-1);
}
private int on_FileInfos_create(struct file_selector_context * _Context) {
	int w,r,c,n;
	int i=_Context->value_Slider;
	if(4>0){
	for(r=0;r<17;r++)
	for(c=0;c<78;c++)
	_Context->buffer_FileInfos[r][c]=' ';
	if(_Context->value_Slider!=0)
	n=1;
	else n=0;
	if(_Context->value_InfoSelector!=0){
	for(r=1;r<=17;r++){
	if ( r > 0 ) { _Context->row_FileInfos=&_Context->buffer_FileInfos[r-1][0]; } ;
	if((_Context->max_Slider=fileinformer(
	(_Context->row_FileInfos+0),
	43,13,11,11,
	&_Context->buffer_FileSelection,255,n,i))==0)
	break;
	n=1;i=0;
	}
	}
	}
	return(-1);
}

public	int	file_selector_create(
	struct file_selector_context ** cptr,
	char * pResult,
	char * pFileType,
	char * pPath,
	char * pFileSelection)
{

	int i;
	struct file_selector_context * _Context=(struct file_selector_context*)0;
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
	if (!(_Context = allocate( sizeof( struct file_selector_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=13;
		_Context->value_InfoSelector=0;
		_Context->max_Slider=0;
		_Context->limit_Slider=0;
		_Context->value_Slider=0;
	_Context->formsort_FileNames=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_FileNames=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_FileNames=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_FileNames=0;_Context->nelt_FileNames<512;_Context->nelt_FileNames++)
			{ _Context->tabsort_FileNames[_Context->nelt_FileNames]=_Context->nelt_FileNames+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_FileNames=0; /* si problème d'allocation */
_Context->indsort_FileNames=NULL;	/* pas de pointeur de table intermédiaire */	_Context->formsort_FileInfos=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_FileInfos=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_FileInfos=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_FileInfos=0;_Context->nelt_FileInfos<512;_Context->nelt_FileInfos++)
			{ _Context->tabsort_FileInfos[_Context->nelt_FileInfos]=_Context->nelt_FileInfos+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_FileInfos=0; /* si problème d'allocation */
_Context->indsort_FileInfos=NULL;	/* pas de pointeur de table intermédiaire */	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Result, 255, pResult);
		visual_transferin((void *) 0, 0, pFileType);
		if (!( pFileType )) _Context->value_FileType=0;
		else	_Context->value_FileType = *((int *)pFileType);
		visual_transferin(_Context->buffer_Path, 255, pPath);
		visual_transferin(_Context->buffer_FileSelection, 255, pFileSelection);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto2732[i]=" ";
	_Context->hint_Auto2732[0]=en__Auto2732;
	_Context->hint_Auto2732[1]=fr__Auto2732;
	_Context->hint_Auto2732[2]=it__Auto2732;
	_Context->hint_Auto2732[3]=es__Auto2732;
	_Context->hint_Auto2732[4]=de__Auto2732;
	_Context->hint_Auto2732[5]=nl__Auto2732;
	_Context->hint_Auto2732[6]=pt__Auto2732;
	_Context->hint_Auto2732[7]=xx__Auto2732;
	_Context->x_Auto2732=60;
	_Context->y_Auto2732=25;
	_Context->w_Auto2732=680;
	_Context->h_Auto2732=550;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_amato666[i]=" ";
	_Context->msg_amato666[0]=en_amato666;
	_Context->msg_amato666[1]=fr_amato666;
	_Context->msg_amato666[2]=it_amato666;
	_Context->msg_amato666[3]=es_amato666;
	_Context->msg_amato666[4]=de_amato666;
	_Context->msg_amato666[5]=nl_amato666;
	_Context->msg_amato666[6]=pt_amato666;
	_Context->msg_amato666[7]=xx_amato666;
	for (i=0; i < 8; i++)_Context->msg_Auto2733[i]=" ";
	_Context->msg_Auto2733[0]=en_Auto2733;
	_Context->msg_Auto2733[1]=fr_Auto2733;
	_Context->msg_Auto2733[2]=it_Auto2733;
	_Context->msg_Auto2733[3]=es_Auto2733;
	_Context->msg_Auto2733[4]=de_Auto2733;
	_Context->msg_Auto2733[5]=nl_Auto2733;
	_Context->msg_Auto2733[6]=pt_Auto2733;
	_Context->msg_Auto2733[7]=xx_Auto2733;
	for (i=0; i < 8; i++)_Context->msg_Auto2734[i]=" ";
	_Context->msg_Auto2734[0]=en_Auto2734;
	_Context->msg_Auto2734[1]=fr_Auto2734;
	_Context->msg_Auto2734[2]=it_Auto2734;
	_Context->msg_Auto2734[3]=es_Auto2734;
	_Context->msg_Auto2734[4]=de_Auto2734;
	_Context->msg_Auto2734[5]=nl_Auto2734;
	_Context->msg_Auto2734[6]=pt_Auto2734;
	_Context->msg_Auto2734[7]=xx_Auto2734;
	for (i=0; i < 8; i++)_Context->msg_Auto2735[i]=" ";
	_Context->msg_Auto2735[0]=en_Auto2735;
	_Context->msg_Auto2735[1]=fr_Auto2735;
	_Context->msg_Auto2735[2]=it_Auto2735;
	_Context->msg_Auto2735[3]=es_Auto2735;
	_Context->msg_Auto2735[4]=de_Auto2735;
	_Context->msg_Auto2735[5]=nl_Auto2735;
	_Context->msg_Auto2735[6]=pt_Auto2735;
	_Context->msg_Auto2735[7]=xx_Auto2735;
	for (i=0; i < 8; i++)_Context->msg_Auto2736[i]=" ";
	_Context->msg_Auto2736[0]=en_Auto2736;
	_Context->msg_Auto2736[1]=fr_Auto2736;
	_Context->msg_Auto2736[2]=it_Auto2736;
	_Context->msg_Auto2736[3]=es_Auto2736;
	_Context->msg_Auto2736[4]=de_Auto2736;
	_Context->msg_Auto2736[5]=nl_Auto2736;
	_Context->msg_Auto2736[6]=pt_Auto2736;
	_Context->msg_Auto2736[7]=xx_Auto2736;
	for (i=0; i < 8; i++)_Context->msg_Find[i]=" ";
	_Context->msg_Find[0]=en_Find;
	_Context->msg_Find[1]=fr_Find;
	_Context->msg_Find[2]=it_Find;
	_Context->msg_Find[3]=es_Find;
	_Context->msg_Find[4]=de_Find;
	_Context->msg_Find[5]=nl_Find;
	_Context->msg_Find[6]=pt_Find;
	_Context->msg_Find[7]=xx_Find;
	for (i=0; i < 8; i++)_Context->msg_InfoSelector[i]=" ";
	_Context->msg_InfoSelector[0]=en_InfoSelector;
	_Context->msg_InfoSelector[1]=fr_InfoSelector;
	_Context->msg_InfoSelector[2]=it_InfoSelector;
	_Context->msg_InfoSelector[3]=es_InfoSelector;
	_Context->msg_InfoSelector[4]=de_InfoSelector;
	_Context->msg_InfoSelector[5]=nl_InfoSelector;
	_Context->msg_InfoSelector[6]=pt_InfoSelector;
	_Context->msg_InfoSelector[7]=xx_InfoSelector;
	_Context->value_InfoSelector=0;
	for (i=0; i < 8; i++)_Context->msg_Delete[i]=" ";
	_Context->msg_Delete[0]=en_Delete;
	_Context->msg_Delete[1]=fr_Delete;
	_Context->msg_Delete[2]=it_Delete;
	_Context->msg_Delete[3]=es_Delete;
	_Context->msg_Delete[4]=de_Delete;
	_Context->msg_Delete[5]=nl_Delete;
	_Context->msg_Delete[6]=pt_Delete;
	_Context->msg_Delete[7]=xx_Delete;
	for (i=0; i < 8; i++)_Context->msg_Auto2737[i]=" ";
	_Context->msg_Auto2737[0]=en_Auto2737;
	_Context->msg_Auto2737[1]=fr_Auto2737;
	_Context->msg_Auto2737[2]=it_Auto2737;
	_Context->msg_Auto2737[3]=es_Auto2737;
	_Context->msg_Auto2737[4]=de_Auto2737;
	_Context->msg_Auto2737[5]=nl_Auto2737;
	_Context->msg_Auto2737[6]=pt_Auto2737;
	_Context->msg_Auto2737[7]=xx_Auto2737;
	for (i=0; i < 8; i++)_Context->msg_FileType[i]=" ";
	_Context->hint_FileType[0]=en__FileType;
	_Context->value_FileType=detect_file_extension(_Context->buffer_Result,255,_Context->value_FileType);
	(void) on_FileSelection_create(_Context);
	_Context->max_Slider=1;
	_Context->value_Slider=1;
	_Context->limit_Slider=1;
	(void) on_Slider_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_FileNames[i]=" ";
	_Context->msg_FileNames[0]=en_FileNames;
	_Context->msg_FileNames[1]=fr_FileNames;
	_Context->msg_FileNames[2]=it_FileNames;
	_Context->msg_FileNames[3]=es_FileNames;
	_Context->msg_FileNames[4]=de_FileNames;
	_Context->msg_FileNames[5]=nl_FileNames;
	_Context->msg_FileNames[6]=pt_FileNames;
	_Context->msg_FileNames[7]=xx_FileNames;
	if ( 0 > 0 ) { _Context->row_FileNames=&_Context->buffer_FileNames[0-1][0]; } ;
	(void) on_FileNames_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_FileInfos[i]=" ";
	_Context->msg_FileInfos[0]=en_FileInfos;
	_Context->msg_FileInfos[1]=fr_FileInfos;
	_Context->msg_FileInfos[2]=it_FileInfos;
	_Context->msg_FileInfos[3]=es_FileInfos;
	_Context->msg_FileInfos[4]=de_FileInfos;
	_Context->msg_FileInfos[5]=nl_FileInfos;
	_Context->msg_FileInfos[6]=pt_FileInfos;
	_Context->msg_FileInfos[7]=xx_FileInfos;
	if ( 0 > 0 ) { _Context->row_FileInfos=&_Context->buffer_FileInfos[0-1][0]; } ;
	(void) on_FileInfos_create(_Context);
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2732,_Context->y_Auto2732,680+10,550+10);
	return(0);
}

public 	int	file_selector_hide(struct file_selector_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2732,_Context->y_Auto2732);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	file_selector_remove(
	struct file_selector_context * _Context,
	char * pResult,
	char * pFileType,
	char * pPath,
	char * pFileSelection)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Result, 255, pResult);
		visual_transferout((void *) 0, 0, pFileType);
		if ( pFileType != (char *) 0)
			*((int*)pFileType) = _Context->value_FileType;
		visual_transferout(_Context->buffer_Path, 255, pPath);
		visual_transferout(_Context->buffer_FileSelection, 255, pFileSelection);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_FileNames_show(struct file_selector_context * _Context) {
	if(!(_Context->value_InfoSelector)){
		visual_table(_Context->x_Auto2732+20,_Context->y_Auto2732+80,630,300,vfh[1],27,0,_Context->msg_FileNames[_Context->language],_Context->buffer_FileNames,0x0401,(char*) 0);

	}
	else{
		visual_table(_Context->x_Auto2732+20,_Context->y_Auto2732+80,630,300,vfh[1],27,0,_Context->msg_FileInfos[_Context->language],_Context->buffer_FileInfos,0x4401,"($,N11Z,W10,W10)");
;
	}
	return(-1);
}
private int on_FileInfos_show(struct file_selector_context * _Context) {
	if(_Context->value_InfoSelector!=0){
		visual_table(_Context->x_Auto2732+20,_Context->y_Auto2732+80,630,300,vfh[1],27,0,_Context->msg_FileInfos[_Context->language],_Context->buffer_FileInfos,0x4401,"($,N11Z,W10,W10)");
;
	}
	else{
		visual_table(_Context->x_Auto2732+20,_Context->y_Auto2732+80,630,300,vfh[1],27,0,_Context->msg_FileNames[_Context->language],_Context->buffer_FileNames,0x0401,(char*) 0);
;
	}
	return(-1);
}

public	int	file_selector_show(struct file_selector_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2732,_Context->y_Auto2732);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto2732,_Context->y_Auto2732,680,550,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto2732,_Context->y_Auto2732,680,550,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto2732+20,_Context->y_Auto2732+390,490,20,vfh[2],27,0,_Context->msg_amato666[_Context->language],strlen(_Context->msg_amato666[_Context->language]),258);
	visual_text(_Context->x_Auto2732+20,_Context->y_Auto2732+30,630,16,vfh[2],27,0,_Context->msg_Auto2733[_Context->language],strlen(_Context->msg_Auto2733[_Context->language]),258);
	visual_frame(_Context->x_Auto2732+20,_Context->y_Auto2732+50,630+2,20+2,5);
	visual_text(_Context->x_Auto2732+20+1,_Context->y_Auto2732+50+1,630,20,vfh[1],27,0,_Context->buffer_Result,255,0);
	visual_text(_Context->x_Auto2732+180,_Context->y_Auto2732+440,470,20,vfh[2],27,0,_Context->msg_Auto2734[_Context->language],strlen(_Context->msg_Auto2734[_Context->language]),258);
	visual_text(_Context->x_Auto2732+20,_Context->y_Auto2732+440,120,20,vfh[2],27,0,_Context->msg_Auto2735[_Context->language],strlen(_Context->msg_Auto2735[_Context->language]),258);
	_Context->trigger_Auto2736=visual_trigger_code(_Context->msg_Auto2736[_Context->language],strlen(_Context->msg_Auto2736[_Context->language]));
	visual_button(_Context->x_Auto2732+20,_Context->y_Auto2732+490,56,48,vfh[2],34,0,_Context->msg_Auto2736[_Context->language],strlen(_Context->msg_Auto2736[_Context->language]),1040);
	_Context->trigger_Find=visual_trigger_code(_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]));
	visual_button(_Context->x_Auto2732+180,_Context->y_Auto2732+500,120,30,vfh[2],27,0,_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]),0);
	_Context->trigger_InfoSelector=visual_trigger_code(_Context->msg_InfoSelector[_Context->language],strlen(_Context->msg_InfoSelector[_Context->language]));
	visual_switch(_Context->x_Auto2732+320,_Context->y_Auto2732+500,56,32,vfh[2],12,31,_Context->msg_InfoSelector[_Context->language],strlen(_Context->msg_InfoSelector[_Context->language]),_Context->value_InfoSelector| 0x0030);
	_Context->trigger_Delete=visual_trigger_code(_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]));
	visual_button(_Context->x_Auto2732+400,_Context->y_Auto2732+500,110,30,vfh[2],27,0,_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]),0);
	_Context->trigger_Auto2737=visual_trigger_code(_Context->msg_Auto2737[_Context->language],strlen(_Context->msg_Auto2737[_Context->language]));
	visual_button(_Context->x_Auto2732+590,_Context->y_Auto2732+490,56,48,vfh[2],34,0,_Context->msg_Auto2737[_Context->language],strlen(_Context->msg_Auto2737[_Context->language]),1040);
	visual_select(_Context->x_Auto2732+20,_Context->y_Auto2732+460,120,80,vfh[2],27,0,parse_selection(WidgetFileNames,&_Context->value_FileType),768);
	visual_frame(_Context->x_Auto2732+20,_Context->y_Auto2732+410,630+2,20+2,5);
	visual_text(_Context->x_Auto2732+20+1,_Context->y_Auto2732+410+1,630,20,vfh[1],0,0,_Context->buffer_Path,255,0);
	visual_frame(_Context->x_Auto2732+180,_Context->y_Auto2732+460,470+2,20+2,5);
	visual_text(_Context->x_Auto2732+180+1,_Context->y_Auto2732+460+1,470,20,vfh[1],27,0,_Context->buffer_FileSelection,255,0);
	visual_scrollbar(_Context->x_Auto2732+650,_Context->y_Auto2732+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,3);
	(void) on_FileNames_show(_Context);
	(void) on_FileInfos_show(_Context);
	visual_thaw(_Context->x_Auto2732,_Context->y_Auto2732,680,550);

	return(0);
}

private int Result_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field displays the current result value of the file selection ";
			mptr[1]="dialog frame.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2736_help()
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

private int Find_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "By pressing on this button the combined path and file type criteria ";
			mptr[1]="will be combined and displayed in the file seclection value. This ";
			mptr[2]="resulting search pattern will be used to perform the search operation ";
			mptr[3]="whose results will be displayed in the main  output table.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Delete_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the delete button the file represented by the  current ";
			mptr[1]="result edit field may be deleted.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2737_help()
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

private int FileType_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This select control provides a list of file types extensions.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Path_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows a path name to be specified. The path will ";
			mptr[1]="be used in conjunction with the file type value giving rise to the ";
			mptr[2]="file search pattern.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FileSelection_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit filed displays the current search pattern comprising the ";
			mptr[1]="path field and the file type extension. It may be modified by hand ";
			mptr[2]="prior to pressing the find button to perform the search operation. ";
			mptr[3]=" ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FileNames_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This table field displayes the results of the most recent file selection ";
			mptr[1]="operation. By clicking on a filename it will be copied into the result ";
			mptr[2]="field.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FileInfos_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This table field displayes the results of the most recent file selection ";
			mptr[1]="operation. By clicking on a filename it will be copied into the result ";
			mptr[2]="field.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2732action(struct file_selector_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			file_selector_hide(_Context);

		_Context->x_Auto2732 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2732 < 0) { _Context->x_Auto2732=0; }
		_Context->y_Auto2732 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2732 < 0) { _Context->y_Auto2732=0; }
			file_selector_show(_Context);

		visual_thaw(_Context->x_Auto2732,_Context->y_Auto2732,680,550);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto2736_event(struct file_selector_context * _Context) {
	return(13);
	return(-1);
}
private int on_Find_event(struct file_selector_context * _Context) {
	on_Path_losefocus(_Context);
	on_Slider_create(_Context);
	on_FileNames_create(_Context);
		file_selector_show(_Context);
;
	return(-1);
}
private int on_InfoSelector_event(struct file_selector_context * _Context) {
	_Context->value_Slider=0;
	on_Slider_event(_Context);
	return(-1);
}
private int on_Delete_event(struct file_selector_context * _Context) {
	delete_system_file(_Context->buffer_FileSelection,255);
	on_Find_event(_Context);
	return(-1);
}
private int on_Auto2737_event(struct file_selector_context * _Context) {
	return(27);
	return(-1);
}
private int on_Slider_event(struct file_selector_context * _Context) {
	if(!(_Context->value_InfoSelector)){
	on_FileNames_create(_Context);
	_Context->limit_Slider=(17*4);
	}
	else{
	on_FileInfos_create(_Context);
	_Context->limit_Slider=17;
	}
		file_selector_show(_Context);
;
	return(-1);
}

private int on_Slider_action(struct file_selector_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto2732+80+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Slider -= 1;
		if (_Context->value_Slider < 0) 
			_Context->value_Slider = 0;
		(void) on_Slider_event(_Context);
	visual_scrollbar(_Context->x_Auto2732+650,_Context->y_Auto2732+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto2732+80+300-20) ) {
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
	visual_scrollbar(_Context->x_Auto2732+650,_Context->y_Auto2732+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto2732+650,_Context->y_Auto2732+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_Slider;
		_Context->value_Slider = (((visual_event(6) - (_Context->y_Auto2732+80+20)) * _Context->max_Slider) / (300 - (2 * 20)));
		if (_Context->value_Slider < 0) 
			_Context->value_Slider = 0;
		else if (_Context->value_Slider > (_Context->max_Slider-_Context->limit_Slider)) 
			_Context->value_Slider = (_Context->max_Slider-_Context->limit_Slider);
		if (_Context->value_Slider != aty) {
		(void) on_Slider_event(_Context);
	visual_scrollbar(_Context->x_Auto2732+650,_Context->y_Auto2732+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
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
	visual_scrollbar(_Context->x_Auto2732+650,_Context->y_Auto2732+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
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
	visual_scrollbar(_Context->x_Auto2732+650,_Context->y_Auto2732+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto2732+650,_Context->y_Auto2732+80,20,300,vfh[1],0,0,_Context->value_Slider,_Context->limit_Slider,_Context->max_Slider,3);

	return(1);
}
private int on_FileNames_event(struct file_selector_context * _Context) {
	int r;
	if(_Context->value_InfoSelector!=0){
	if(!(r=_Context->value_FileNames))
	return(-1);
	else{
	_Context->value_FileInfos=r;
	on_FileInfos_event(_Context);
	}
	}
	else{
	if(!(r=_Context->value_FileNames))
	return(-1);
	if ( r > 0 ) { _Context->row_FileNames=&_Context->buffer_FileNames[r-1][0]; } ;
	if(visual_event(2)==1){
	switch(_Context->column_FileNames){
	case 1:
	if(!(fnisdirectory((_Context->row_FileNames+0),20))){
	fntransfer(
	_Context->buffer_Result,255,
	_Context->buffer_Path,255,
	(_Context->row_FileNames+0),20);
	}
	else{
	fnchangedirectory(
	_Context->buffer_Path,255,
	(_Context->row_FileNames+0),20
	);
	on_Find_event(_Context);
	}
	break;
	case 2:
	if(!(fnisdirectory((_Context->row_FileNames+0),20))){
	fntransfer(
	_Context->buffer_Result,255,
	_Context->buffer_Path,255,
	(_Context->row_FileNames+20),20);
	}
	else{
	fnchangedirectory(
	_Context->buffer_Path,255,
	(_Context->row_FileNames+20),20
	);
	on_Find_event(_Context);
	}
	break;
	case 3:
	if(!(fnisdirectory((_Context->row_FileNames+0),20))){
	fntransfer(
	_Context->buffer_Result,255,
	_Context->buffer_Path,255,
	(_Context->row_FileNames+40),19);
	}
	else{
	fnchangedirectory(
	_Context->buffer_Path,255,
	(_Context->row_FileNames+40),19
	);
	on_Find_event(_Context);
	}
	break;
	case 4:
	if(!(fnisdirectory((_Context->row_FileNames+0),20))){
	fntransfer(
	_Context->buffer_Result,255,
	_Context->buffer_Path,255,
	(_Context->row_FileNames+59),19);
	}
	else{
	fnchangedirectory(
	_Context->buffer_Path,255,
	(_Context->row_FileNames+59),19
	);
	on_Find_event(_Context);
	}
	break;
	}
	}
	else{
	switch(_Context->column_FileNames){
	case 1:fnaddfile(
	_Context->buffer_Result,255,
	_Context->buffer_Path,255,
	(_Context->row_FileNames+0),20);
	break;
	case 2:fnaddfile(
	_Context->buffer_Result,255,
	_Context->buffer_Path,255,
	(_Context->row_FileNames+20),20);
	break;
	case 3:fnaddfile(
	_Context->buffer_Result,255,
	_Context->buffer_Path,255,
	(_Context->row_FileNames+40),19);
	break;
	case 4:fnaddfile(
	_Context->buffer_Result,255,
	_Context->buffer_Path,255,
	(_Context->row_FileNames+59),19);
	break;
	}
	}
		file_selector_show(_Context);
;
	}
	return(-1);
}
private int on_FileInfos_event(struct file_selector_context * _Context) {
	int r;
	if(!(_Context->value_InfoSelector!=0)){
	on_FileNames_event(_Context);
	}
	else{
	if(!(r=_Context->value_FileNames))
	return;
	_Context->value_FileInfos=r;
	if ( r > 0 ) { _Context->row_FileInfos=&_Context->buffer_FileInfos[r-1][0]; } ;
	if(visual_event(2)==1){
	if(!(fnisdirectory((_Context->row_FileInfos+0),43))){
	fntransfer(
	_Context->buffer_Result,255,
	_Context->buffer_Path,255,
	(_Context->row_FileInfos+0),43);
	}
	else{
	fnchangedirectory(
	_Context->buffer_Path,255,
	(_Context->row_FileInfos+0),43
	);
	on_Find_event(_Context);
	}
	}
	else{
	fnaddfile(
	_Context->buffer_Result,255,
	_Context->buffer_Path,255,
	(_Context->row_FileInfos+0),43);
	}
	}
		file_selector_show(_Context);
;
	return(-1);
}


public	int	file_selector_event(
struct file_selector_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto2736 == mb ) return(3);
		if (_Context->trigger_Find == mb ) return(4);
		if (_Context->trigger_InfoSelector == mb ) return(5);
		if (_Context->trigger_Delete == mb ) return(6);
		if (_Context->trigger_Auto2737 == mb ) return(7);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2732+659) )  
	&&  (my >= (_Context->y_Auto2732+4) )  
	&&  (mx <= (_Context->x_Auto2732+676) )  
	&&  (my <= (_Context->y_Auto2732+20) )) {
		return(1);	/* Auto2732 */

		}
	if ((mx >= (_Context->x_Auto2732+643) )  
	&&  (my >= (_Context->y_Auto2732+4) )  
	&&  (mx <= (_Context->x_Auto2732+660) )  
	&&  (my <= (_Context->y_Auto2732+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vfselect.htm");
			};
		return(-1);	/* Auto2732 */

		}
	if ((mx >= (_Context->x_Auto2732+627) )  
	&&  (my >= (_Context->y_Auto2732+4) )  
	&&  (mx <= (_Context->x_Auto2732+644) )  
	&&  (my <= (_Context->y_Auto2732+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		file_selector_show(_Context);
		return(-1);	/* Auto2732 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2732+4) )  
		&&  (my >= (_Context->y_Auto2732+4) )  
		&&  (mx <= (_Context->x_Auto2732+612) )  
		&&  (my <= (_Context->y_Auto2732+20) )) {
			return( Auto2732action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto2732+20) ) 
	&&  ( my >= (_Context->y_Auto2732+50) ) 
	&&  ( mx <= (_Context->x_Auto2732+20+630) ) 
	&&  ( my <= (_Context->y_Auto2732+50+20))) {
		return(2); /* Result */
		}
	if (( mx >= (_Context->x_Auto2732+20) ) 
	&&  ( my >= (_Context->y_Auto2732+490) ) 
	&&  ( mx <= (_Context->x_Auto2732+20+56) ) 
	&&  ( my <= (_Context->y_Auto2732+490+48))) {
		return(3); /* Auto2736 */
		}
	if (( mx >= (_Context->x_Auto2732+180) ) 
	&&  ( my >= (_Context->y_Auto2732+500) ) 
	&&  ( mx <= (_Context->x_Auto2732+180+120) ) 
	&&  ( my <= (_Context->y_Auto2732+500+30))) {
		return(4); /* Find */
		}
	if (( mx >= (_Context->x_Auto2732+320) ) 
	&&  ( my >= (_Context->y_Auto2732+500) ) 
	&&  ( mx <= (_Context->x_Auto2732+320+56) ) 
	&&  ( my <= (_Context->y_Auto2732+500+32))) {
		return(5); /* InfoSelector */
		}
	if (( mx >= (_Context->x_Auto2732+400) ) 
	&&  ( my >= (_Context->y_Auto2732+500) ) 
	&&  ( mx <= (_Context->x_Auto2732+400+110) ) 
	&&  ( my <= (_Context->y_Auto2732+500+30))) {
		return(6); /* Delete */
		}
	if (( mx >= (_Context->x_Auto2732+590) ) 
	&&  ( my >= (_Context->y_Auto2732+490) ) 
	&&  ( mx <= (_Context->x_Auto2732+590+56) ) 
	&&  ( my <= (_Context->y_Auto2732+490+48))) {
		return(7); /* Auto2737 */
		}
	if (( mx >= (_Context->x_Auto2732+20+0) ) 
	&&  ( my >= (_Context->y_Auto2732+460) ) 
	&&  ( mx <= (_Context->x_Auto2732+20+120) ) 
	&&  ( my <= (_Context->y_Auto2732+460+16))) {
		return(8); /* FileType */
		}
	if (( mx >= (_Context->x_Auto2732+20) ) 
	&&  ( my >= (_Context->y_Auto2732+410) ) 
	&&  ( mx <= (_Context->x_Auto2732+20+630) ) 
	&&  ( my <= (_Context->y_Auto2732+410+20))) {
		return(9); /* Path */
		}
	if (( mx >= (_Context->x_Auto2732+180) ) 
	&&  ( my >= (_Context->y_Auto2732+460) ) 
	&&  ( mx <= (_Context->x_Auto2732+180+470) ) 
	&&  ( my <= (_Context->y_Auto2732+460+20))) {
		return(10); /* FileSelection */
		}
	if (( mx >= (_Context->x_Auto2732+650) ) 
	&&  ( my >= (_Context->y_Auto2732+80) ) 
	&&  ( mx <= (_Context->x_Auto2732+650+20) ) 
	&&  ( my <= (_Context->y_Auto2732+80+300))) {
		return(11); /* Slider */
		}
	if (( mx >= (_Context->x_Auto2732+20) ) 
	&&  ( my >= (_Context->y_Auto2732+80) ) 
	&&  ( mx <= (_Context->x_Auto2732+20+630) ) 
	&&  ( my <= (_Context->y_Auto2732+80+300))) {
		if ((_Context->value_FileNames = ((visual_event(6) - (_Context->y_Auto2732+80)) / 16)) < 1)
			_Context->value_FileNames=0;
else if (_Context->value_FileNames > 17 )
			_Context->value_FileNames=17;
		if ( _Context->value_FileNames > 0 ) { _Context->row_FileNames = &_Context->buffer_FileNames[(_Context->value_FileNames-1)][0]; } 
		_Context->column_FileNames = (visual_event(7) - (_Context->x_Auto2732+20));
		if ( _Context->column_FileNames < 160 ) {
			_Context->column_FileNames = 1;
			}
		else if ( _Context->column_FileNames < 320 ) {
			_Context->column_FileNames = 2;
			}
		else if ( _Context->column_FileNames < 472 ) {
			_Context->column_FileNames = 3;
			}
		else if ( _Context->column_FileNames < 624 ) {
			_Context->column_FileNames = 4;
			}
		if ((!(_Context->value_FileNames)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
			if (_Context->formsort_FileNames==_Context->column_FileNames) /* si colonne choisie concerne déjà le tri */
				_Context->formsort_FileNames=-_Context->column_FileNames;	/* alors tri décroissant */
			else
				_Context->formsort_FileNames=_Context->column_FileNames; };	/* sinon tri croissant */
		return(12); /* FileNames */
		}
	if (( mx >= (_Context->x_Auto2732+20) ) 
	&&  ( my >= (_Context->y_Auto2732+80) ) 
	&&  ( mx <= (_Context->x_Auto2732+20+630) ) 
	&&  ( my <= (_Context->y_Auto2732+80+300))) {
		if ((_Context->value_FileInfos = ((visual_event(6) - (_Context->y_Auto2732+80)) / 16)) < 1)
			_Context->value_FileInfos=0;
else if (_Context->value_FileInfos > 17 )
			_Context->value_FileInfos=17;
		if ( _Context->value_FileInfos > 0 ) { _Context->row_FileInfos = &_Context->buffer_FileInfos[(_Context->value_FileInfos-1)][0]; } 
		_Context->column_FileInfos = (visual_event(7) - (_Context->x_Auto2732+20));
		if ( _Context->column_FileInfos < 344 ) {
			_Context->column_FileInfos = 1;
			}
		else if ( _Context->column_FileInfos < 448 ) {
			_Context->column_FileInfos = 2;
			}
		else if ( _Context->column_FileInfos < 536 ) {
			_Context->column_FileInfos = 3;
			}
		else if ( _Context->column_FileInfos < 624 ) {
			_Context->column_FileInfos = 4;
			}
		if ((!(_Context->value_FileInfos)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
			if (_Context->formsort_FileInfos==_Context->column_FileInfos) /* si colonne choisie concerne déjà le tri */
				_Context->formsort_FileInfos=-_Context->column_FileInfos;	/* alors tri décroissant */
			else
				_Context->formsort_FileInfos=_Context->column_FileInfos; };	/* sinon tri croissant */
		return(13); /* FileInfos */
		}

	return(-1);
}
private int on_FileType_losefocus(struct file_selector_context * _Context) {
	get_widget_filename(
	_Context->buffer_FileSelection,255,
	_Context->value_FileType,
	_Context->buffer_Path,255);
		file_selector_show(_Context);
;
	return(-1);
}
private int on_Path_losefocus(struct file_selector_context * _Context) {
	get_widget_filename(_Context->buffer_FileSelection,255,
	_Context->value_FileType,_Context->buffer_Path,255);
		file_selector_show(_Context);
;
	return(-1);
}


public	int	file_selector_focus(struct file_selector_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Result */
				_Context->keycode = visual_edit(_Context->x_Auto2732+20+1,_Context->y_Auto2732+50+1,630,20,vfh[1],_Context->buffer_Result,255);
			break;
			case	0x3 :
				/* Auto2736 */
				_Context->trigger_Auto2736=visual_trigger_code(_Context->msg_Auto2736[_Context->language],strlen(_Context->msg_Auto2736[_Context->language]));
				visual_button(_Context->x_Auto2732+20,_Context->y_Auto2732+490,56,48,vfh[2],34,0,_Context->msg_Auto2736[_Context->language],strlen(_Context->msg_Auto2736[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2736=visual_trigger_code(_Context->msg_Auto2736[_Context->language],strlen(_Context->msg_Auto2736[_Context->language]));
	visual_button(_Context->x_Auto2732+20,_Context->y_Auto2732+490,56,48,vfh[2],34,0,_Context->msg_Auto2736[_Context->language],strlen(_Context->msg_Auto2736[_Context->language]),1040);
				break;
			case	0x4 :
				/* Find */
				_Context->trigger_Find=visual_trigger_code(_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]));
				visual_button(_Context->x_Auto2732+180,_Context->y_Auto2732+500,120,30,vfh[2],27,0,_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Find=visual_trigger_code(_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]));
	visual_button(_Context->x_Auto2732+180,_Context->y_Auto2732+500,120,30,vfh[2],27,0,_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]),0);
				break;
			case	0x5 :
				/* InfoSelector */
				visual_switch(_Context->x_Auto2732+320,_Context->y_Auto2732+500,56,32,vfh[2],12,31,_Context->msg_InfoSelector[_Context->language],strlen(_Context->msg_InfoSelector[_Context->language]),(_Context->value_InfoSelector | 2 | 0x0030 ));
				_Context->keycode = visual_getch();
				_Context->trigger_InfoSelector=visual_trigger_code(_Context->msg_InfoSelector[_Context->language],strlen(_Context->msg_InfoSelector[_Context->language]));
	visual_switch(_Context->x_Auto2732+320,_Context->y_Auto2732+500,56,32,vfh[2],12,31,_Context->msg_InfoSelector[_Context->language],strlen(_Context->msg_InfoSelector[_Context->language]),_Context->value_InfoSelector| 0x0030);
				break;
			case	0x6 :
				/* Delete */
				_Context->trigger_Delete=visual_trigger_code(_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]));
				visual_button(_Context->x_Auto2732+400,_Context->y_Auto2732+500,110,30,vfh[2],27,0,_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Delete=visual_trigger_code(_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]));
	visual_button(_Context->x_Auto2732+400,_Context->y_Auto2732+500,110,30,vfh[2],27,0,_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]),0);
				break;
			case	0x7 :
				/* Auto2737 */
				_Context->trigger_Auto2737=visual_trigger_code(_Context->msg_Auto2737[_Context->language],strlen(_Context->msg_Auto2737[_Context->language]));
				visual_button(_Context->x_Auto2732+590,_Context->y_Auto2732+490,56,48,vfh[2],34,0,_Context->msg_Auto2737[_Context->language],strlen(_Context->msg_Auto2737[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2737=visual_trigger_code(_Context->msg_Auto2737[_Context->language],strlen(_Context->msg_Auto2737[_Context->language]));
	visual_button(_Context->x_Auto2732+590,_Context->y_Auto2732+490,56,48,vfh[2],34,0,_Context->msg_Auto2737[_Context->language],strlen(_Context->msg_Auto2737[_Context->language]),1040);
				break;
			case	0x8 :
				/* FileType */
				_Context->keycode = visual_select(_Context->x_Auto2732+20,_Context->y_Auto2732+460,120,80,vfh[2],27,0,parse_selection(WidgetFileNames,&_Context->value_FileType),770);
				(void) on_FileType_losefocus(_Context);
				break;
			case	0x9 :
				/* Path */
				_Context->keycode = visual_edit(_Context->x_Auto2732+20+1,_Context->y_Auto2732+410+1,630,20,vfh[1],_Context->buffer_Path,255);
				(void) on_Path_losefocus(_Context);
			break;
			case	0xa :
				/* FileSelection */
				_Context->keycode = visual_edit(_Context->x_Auto2732+180+1,_Context->y_Auto2732+460+1,470,20,vfh[1],_Context->buffer_FileSelection,255);
			break;
			case	0xc :
				/* FileNames */
	_Context->keycode = visual_getch();
				if ( _Context->keycode == 9 ) {
					_Context->column_FileNames++;
					if ( _Context->column_FileNames > 0 ) {
						_Context->column_FileNames=1;
						_Context->value_FileNames++;
						if ( _Context->value_FileNames > 0 ) {
							_Context->value_FileNames=1;
							}
						}
					_Context->keycode=0;
					}
			break;
			case	0xd :
				/* FileInfos */
				if (!_Context->value_FileInfos) _Context->value_FileInfos=1;	/* pour etre sur qu'on edite pas le titre */
				_Context->row_FileInfos = &_Context->buffer_FileInfos[(_Context->value_FileInfos-1)][0];
				switch (_Context->column_FileInfos) {
				case	0x1 :
					_Context->keycode=visual_edit((_Context->x_Auto2732+20+2),(_Context->y_Auto2732+80+(_Context->value_FileInfos*16)+2),336,16,vfh[1],&_Context->buffer_FileInfos[(_Context->value_FileInfos-1)][0],42);
				visual_text((_Context->x_Auto2732+20+2),(_Context->y_Auto2732+80+(_Context->value_FileInfos*16)+2),336,16,vfh[1],27,(24-((_Context->value_FileInfos-1)&1)),&_Context->buffer_FileInfos[(_Context->value_FileInfos-1)][0],42,0);
					break;
				case	0x2 :
					_Context->keycode=visual_edit((_Context->x_Auto2732+20+346),(_Context->y_Auto2732+80+(_Context->value_FileInfos*16)+2),96,16,vfh[1],&_Context->buffer_FileInfos[(_Context->value_FileInfos-1)][43],12);
				visual_text((_Context->x_Auto2732+20+346),(_Context->y_Auto2732+80+(_Context->value_FileInfos*16)+2),96,16,vfh[1],27,(24-((_Context->value_FileInfos-1)&1)),&_Context->buffer_FileInfos[(_Context->value_FileInfos-1)][43],12,0);
					break;
				case	0x3 :
					_Context->keycode=visual_edit((_Context->x_Auto2732+20+450),(_Context->y_Auto2732+80+(_Context->value_FileInfos*16)+2),80,16,vfh[1],&_Context->buffer_FileInfos[(_Context->value_FileInfos-1)][56],10);
				visual_text((_Context->x_Auto2732+20+450),(_Context->y_Auto2732+80+(_Context->value_FileInfos*16)+2),80,16,vfh[1],27,(24-((_Context->value_FileInfos-1)&1)),&_Context->buffer_FileInfos[(_Context->value_FileInfos-1)][56],10,0);
					break;
				case	0x4 :
					_Context->keycode=visual_edit((_Context->x_Auto2732+20+538),(_Context->y_Auto2732+80+(_Context->value_FileInfos*16)+2),80,16,vfh[1],&_Context->buffer_FileInfos[(_Context->value_FileInfos-1)][67],10);
				visual_text((_Context->x_Auto2732+20+538),(_Context->y_Auto2732+80+(_Context->value_FileInfos*16)+2),80,16,vfh[1],27,(24-((_Context->value_FileInfos-1)&1)),&_Context->buffer_FileInfos[(_Context->value_FileInfos-1)][67],10,0);
					break;
					}
				if ( _Context->keycode == 9 ) {
					_Context->column_FileInfos++;
					if ( _Context->column_FileInfos > 4 ) {
						_Context->column_FileInfos=1;
						_Context->value_FileInfos++;
						if ( _Context->value_FileInfos > 17 ) {
							_Context->value_FileInfos=1;
							}
						}
					_Context->keycode=0;
					}
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			file_selector_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=13;
			file_selector_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=file_selector_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (Result_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Auto2736_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Find_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Delete_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (Auto2737_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (FileType_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (Path_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (FileSelection_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (FileNames_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (FileInfos_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2732 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Result */
					continue;
				case	0x3 :
					/* Auto2736 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2736=visual_trigger_code(_Context->msg_Auto2736[_Context->language],strlen(_Context->msg_Auto2736[_Context->language]));
						visual_button(_Context->x_Auto2732+20,_Context->y_Auto2732+490,56,48,vfh[2],34,0,_Context->msg_Auto2736[_Context->language],strlen(_Context->msg_Auto2736[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2736=visual_trigger_code(_Context->msg_Auto2736[_Context->language],strlen(_Context->msg_Auto2736[_Context->language]));
	visual_button(_Context->x_Auto2732+20,_Context->y_Auto2732+490,56,48,vfh[2],34,0,_Context->msg_Auto2736[_Context->language],strlen(_Context->msg_Auto2736[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2736_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Find */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Find=visual_trigger_code(_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]));
						visual_button(_Context->x_Auto2732+180,_Context->y_Auto2732+500,120,30,vfh[2],27,0,_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Find=visual_trigger_code(_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]));
	visual_button(_Context->x_Auto2732+180,_Context->y_Auto2732+500,120,30,vfh[2],27,0,_Context->msg_Find[_Context->language],strlen(_Context->msg_Find[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Find_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* InfoSelector */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_InfoSelector += 1;
						_Context->value_InfoSelector &= 1;
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_InfoSelector_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Delete */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Delete=visual_trigger_code(_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]));
						visual_button(_Context->x_Auto2732+400,_Context->y_Auto2732+500,110,30,vfh[2],27,0,_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Delete=visual_trigger_code(_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]));
	visual_button(_Context->x_Auto2732+400,_Context->y_Auto2732+500,110,30,vfh[2],27,0,_Context->msg_Delete[_Context->language],strlen(_Context->msg_Delete[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Delete_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto2737 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2737=visual_trigger_code(_Context->msg_Auto2737[_Context->language],strlen(_Context->msg_Auto2737[_Context->language]));
						visual_button(_Context->x_Auto2732+590,_Context->y_Auto2732+490,56,48,vfh[2],34,0,_Context->msg_Auto2737[_Context->language],strlen(_Context->msg_Auto2737[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2737=visual_trigger_code(_Context->msg_Auto2737[_Context->language],strlen(_Context->msg_Auto2737[_Context->language]));
	visual_button(_Context->x_Auto2732+590,_Context->y_Auto2732+490,56,48,vfh[2],34,0,_Context->msg_Auto2737[_Context->language],strlen(_Context->msg_Auto2737[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2737_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* FileType */
					continue;
				case	0x9 :
					/* Path */
					continue;
				case	0xa :
					/* FileSelection */
					continue;
				case	0xb :
					/* Slider */
					(void) on_Slider_action(_Context);
					continue;
				case	0xc :
					/* FileNames */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FileNames_event(_Context)) != -1) break;

						}
					continue;
				case	0xd :
					/* FileInfos */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FileInfos_event(_Context)) != -1) break;

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
				_Context->focus_item=13;
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

public	int	file_selector(
	char * pResult,
	char * pFileType,
	char * pPath,
	char * pFileSelection)
{
	int	status=0;
	struct file_selector_context * _Context=(struct file_selector_context*) 0;
	status = file_selector_create(
	&_Context,
	 pResult,
	 pFileType,
	 pPath,
	 pFileSelection);
	if ( status != 0) return(status);
	status = file_selector_show(_Context);
		enter_modal();
	status = file_selector_focus(_Context);
		leave_modal();
	status = file_selector_hide(_Context);
	status = file_selector_remove(
	_Context,
	 pResult,
	 pFileType,
	 pPath,
	 pFileSelection);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vfselect_c */
