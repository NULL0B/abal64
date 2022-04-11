
#ifndef _vsysfont_c
#define _vsysfont_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vsysfont.xml                                             */
/* Target         : vsysfont.c                                               */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "vsysfont.h"
#include "singprot.h"
#define en__Auto3593   ""
#define fr__Auto3593   ""
#define it__Auto3593   ""
#define es__Auto3593   ""
#define de__Auto3593   ""
#define nl__Auto3593   ""
#define pt__Auto3593   ""
#define xx__Auto3593   ""
#define en_Auto3594   "X/11 System Font Selection"
#define fr_Auto3594   "SÇlection de polices systämes X/11"
#define it_Auto3594   "X/11 System Font Selection"
#define es_Auto3594   "X/11 System Font Selection"
#define de_Auto3594   "X/11 System Font Selection"
#define nl_Auto3594   "X/11 System Font Selection"
#define pt_Auto3594   "X/11 System Font Selection"
#define xx_Auto3594   "X/11 System Font Selection"
#define en_SelectionCriteria   "Selection Criteria"
#define fr_SelectionCriteria   "Critäres de sÇlection"
#define it_SelectionCriteria   "Selection Criteria"
#define es_SelectionCriteria   "Selection Criteria"
#define de_SelectionCriteria   "Selection Criteria"
#define nl_SelectionCriteria   "Selection Criteria"
#define pt_SelectionCriteria   "Selection Criteria"
#define xx_SelectionCriteria   "Selection Criteria"
#define en_Set_Font   "Set Font"
#define fr_Set_Font   "Ajouter"
#define it_Set_Font   "Set Font"
#define es_Set_Font   "Set Font"
#define de_Set_Font   "Set Font"
#define nl_Set_Font   "Set Font"
#define pt_Set_Font   "Set Font"
#define xx_Set_Font   "Set Font"
#define en__Set_Font   ""
#define en_Auto3595   "Foundry"
#define fr_Auto3595   "Fabriquant"
#define it_Auto3595   "Foundry"
#define es_Auto3595   "Foundry"
#define de_Auto3595   "Foundry"
#define nl_Auto3595   "Foundry"
#define pt_Auto3595   "Foundry"
#define xx_Auto3595   "Foundry"
#define en_Auto3596   "Family"
#define fr_Auto3596   "Famille"
#define it_Auto3596   "Family"
#define es_Auto3596   "Family"
#define de_Auto3596   "Family"
#define nl_Auto3596   "Family"
#define pt_Auto3596   "Family"
#define xx_Auto3596   "Family"
#define en_Auto3597   "Weight"
#define fr_Auto3597   "Graisse"
#define it_Auto3597   "Weight"
#define es_Auto3597   "Weight"
#define de_Auto3597   "Weight"
#define nl_Auto3597   "Weight"
#define pt_Auto3597   "Weight"
#define xx_Auto3597   "Weight"
#define en_Auto3598   "Slant"
#define fr_Auto3598   "Inclinaison"
#define it_Auto3598   "Slant"
#define es_Auto3598   "Slant"
#define de_Auto3598   "Slant"
#define nl_Auto3598   "Slant"
#define pt_Auto3598   "Slant"
#define xx_Auto3598   "Slant"
#define en_Auto3599   "Set Width"
#define fr_Auto3599   "Type d'Çpaisseur"
#define it_Auto3599   "Set Width"
#define es_Auto3599   "Set Width"
#define de_Auto3599   "Set Width"
#define nl_Auto3599   "Set Width"
#define pt_Auto3599   "Set Width"
#define xx_Auto3599   "Set Width"
#define en_Auto3600   "Pixels"
#define fr_Auto3600   "Hauteur caractäre (pixels)"
#define it_Auto3600   "Pixels"
#define es_Auto3600   "Pixels"
#define de_Auto3600   "Pixels"
#define nl_Auto3600   "Pixels"
#define pt_Auto3600   "Pixels"
#define xx_Auto3600   "Pixels"
#define en_Auto3601   "Points (tenths)"
#define fr_Auto3601   "Hauteur caractäre (10äme de point)"
#define it_Auto3601   "Points (tenths)"
#define es_Auto3601   "Points (tenths)"
#define de_Auto3601   "Points (tenths)"
#define nl_Auto3601   "Points (tenths)"
#define pt_Auto3601   "Points (tenths)"
#define xx_Auto3601   "Points (tenths)"
#define en_Auto3602   "Horizontal resolution (dpi)"
#define fr_Auto3602   "RÇsolution horizontale (ppp)"
#define it_Auto3602   "Horizontal resolution (dpi)"
#define es_Auto3602   "Horizontal resolution (dpi)"
#define de_Auto3602   "Horizontal resolution (dpi)"
#define nl_Auto3602   "Horizontal resolution (dpi)"
#define pt_Auto3602   "Horizontal resolution (dpi)"
#define xx_Auto3602   "Horizontal resolution (dpi)"
#define en_Auto3603   "Vertical resolution (dpi)"
#define fr_Auto3603   "RÇsolution verticale (ppp)"
#define it_Auto3603   "Vertical resolution (dpi)"
#define es_Auto3603   "Vertical resolution (dpi)"
#define de_Auto3603   "Vertical resolution (dpi)"
#define nl_Auto3603   "Vertical resolution (dpi)"
#define pt_Auto3603   "Vertical resolution (dpi)"
#define xx_Auto3603   "Vertical resolution (dpi)"
#define en_Auto3604   "Spacing"
#define fr_Auto3604   "Espacement"
#define it_Auto3604   "Spacing"
#define es_Auto3604   "Spacing"
#define de_Auto3604   "Spacing"
#define nl_Auto3604   "Spacing"
#define pt_Auto3604   "Spacing"
#define xx_Auto3604   "Spacing"
#define en_Auto3605   "Average Width (pixels/10)"
#define fr_Auto3605   "Largeur moyenne (10äme de pixel)"
#define it_Auto3605   "Average Width (pixels/10)"
#define es_Auto3605   "Average Width (pixels/10)"
#define de_Auto3605   "Average Width (pixels/10)"
#define nl_Auto3605   "Average Width (pixels/10)"
#define pt_Auto3605   "Average Width (pixels/10)"
#define xx_Auto3605   "Average Width (pixels/10)"
#define en_Auto3606   "Character Set"
#define fr_Auto3606   "Jeu de caractäres X11"
#define it_Auto3606   "Character Set"
#define es_Auto3606   "Character Set"
#define de_Auto3606   "Character Set"
#define nl_Auto3606   "Character Set"
#define pt_Auto3606   "Character Set"
#define xx_Auto3606   "Character Set"
#define en_Auto3607   "Windows Font name"
#define fr_Auto3607   "Nom de police Windows"
#define it_Auto3607   "Windows Font name"
#define es_Auto3607   "Windows Font name"
#define de_Auto3607   "Windows Font name"
#define nl_Auto3607   "Windows Font name"
#define pt_Auto3607   "Windows Font name"
#define xx_Auto3607   "Windows Font name"
#define en__Auto3607   ""
#define en_Auto3608   "Windows Charset"
#define fr_Auto3608   "Jeu de caractäres Windows"
#define it_Auto3608   "Windows Charset"
#define es_Auto3608   "Windows Charset"
#define de_Auto3608   "Windows Charset"
#define nl_Auto3608   "Windows Charset"
#define pt_Auto3608   "Windows Charset"
#define xx_Auto3608   "Windows Charset"
#define en__Auto3608   ""
#define en_Auto3609   "Windows Nature"
#define fr_Auto3609   "Style  Windows"
#define it_Auto3609   "Character Set"
#define es_Auto3609   "Windows Nature"
#define de_Auto3609   "Windows Nature"
#define nl_Auto3609   "Windows Nature"
#define pt_Auto3609   "Windows Nature"
#define xx_Auto3609   "Windows Nature"
#define en__Auto3609   ""
#define en_Auto3610   "X/11 Font Name Selection String"
#define fr_Auto3610   "Syntaxe X11 de la police choisie"
#define it_Auto3610   "X/11 Font Name Selection String"
#define es_Auto3610   "X/11 Font Name Selection String"
#define de_Auto3610   "X/11 Font Name Selection String"
#define nl_Auto3610   "X/11 Font Name Selection String"
#define pt_Auto3610   "X/11 Font Name Selection String"
#define xx_Auto3610   "X/11 Font Name Selection String"
#define en_foundry   ""
#define en_slant   "any|roman|italic|oblique"
#define fr_slant   "tout|roman|italic|oblique"
#define it_slant   "any|roman|italic|oblique"
#define es_slant   "any|roman|italic|oblique"
#define de_slant   "any|roman|italic|oblique"
#define nl_slant   "any|roman|italic|oblique"
#define pt_slant   "any|roman|italic|oblique"
#define xx_slant   "any|roman|italic|oblique"
#define en_charset   ""
#define en_wname   ""
#define en__wname   ""
#define en_wcharset   ""
#define en__wcharset   ""
#define en_wnature   ""
#define en__wnature   ""
#define en_setwidth   "any|normal|condensed|narrow|doublewidth"
#define fr_setwidth   "tout|normal|condensed|narrow|doublewidth"
#define it_setwidth   "any|normal|condensed|narrow|doublewidth"
#define es_setwidth   "any|normal|condensed|narrow|doublewidth"
#define de_setwidth   "any|normal|condensed|narrow|doublewidth"
#define nl_setwidth   "any|normal|condensed|narrow|doublewidth"
#define pt_setwidth   "any|normal|condensed|narrow|doublewidth"
#define xx_setwidth   "any|normal|condensed|narrow|doublewidth"
#define en_average   ""
#define en_spacing   "any|fixed|proportional|character"
#define fr_spacing   "tout|fixed|proportional"
#define it_spacing   "any|fixed|proportional"
#define es_spacing   "any|fixed|proportional"
#define de_spacing   "any|fixed|proportional"
#define nl_spacing   "any|fixed|proportional"
#define pt_spacing   "any|fixed|proportional"
#define xx_spacing   "any|fixed|proportional"
#define en__spacing   ""
#define en_vresdpi   "tout|75|100|120|150|200|240|300"
#define fr_vresdpi   "any|75|100|120|150|200|240|300"
#define it_vresdpi   "any|75|100|120|150|200|240|300"
#define es_vresdpi   "any|75|100|120|150|200|240|300"
#define de_vresdpi   "any|75|100|120|150|200|240|300"
#define nl_vresdpi   "any|75|100|120|150|200|240|300"
#define pt_vresdpi   "any|75|100|120|150|200|240|300"
#define xx_vresdpi   "any|75|100|120|150|200|240|300"
#define en_hresdpi   "any|75|100|120|150|200|240|300"
#define fr_hresdpi   "tout|75|100|120|150|200|240|300"
#define it_hresdpi   "any|75|100|120|150|200|240|300"
#define es_hresdpi   "any|75|100|120|150|200|240|300"
#define de_hresdpi   "any|75|100|120|150|200|240|300"
#define nl_hresdpi   "any|75|100|120|150|200|240|300"
#define pt_hresdpi   "any|75|100|120|150|200|240|300"
#define xx_hresdpi   "any|75|100|120|150|200|240|300"
#define en_points   ""
#define en_pixels   ""
#define en_weight   "any|medium|bold|black|regular"
#define fr_weight   "tout|medium|bold|black|regular"
#define it_weight   "any|medium|bold|black|regular"
#define es_weight   "any|medium|bold|black|regular"
#define de_weight   "any|medium|bold|black|regular"
#define nl_weight   "any|medium|bold|black|regular"
#define pt_weight   "any|medium|bold|black|regular"
#define xx_weight   "any|medium|bold|black|regular"
#define en_family   "any|Charter|Courier|Helvetica|Gothic|New Century Schoolbook|Times|Symbol|Utopia|Luxi Mono|Luxi Serif|Lucida|Lucida Bright|Lucida Typewriter|Newspaper|Terminal|Fixed|Arial"
#define fr_family   "Tout|Charter|Courier|Helvetica|Gothic|New Century Schoolbook|Times|Symbol|Utopia|Luxi Mono|Luxi Serif|Lucida|Lucida Bright|Lucida Typewriter|Newspaper|Terminal|Fixed|Arial"
#define it_family   "Any|Charter|Courier|Helvetica|Gothic|New Century Schoolbook|Times|Symbol|Utopia|Luxi Mono|Luxi Serif|Lucida|Lucida Bright|Lucida Typewriter|Newspaper|Terminal|Fixed|Arial"
#define es_family   "Any|Charter|Courier|Helvetica|Gothic|New Century Schoolbook|Times|Symbol|Utopia|Luxi Mono|Luxi Serif|Lucida|Lucida Bright|Lucida Typewriter|Newspaper|Terminal|Fixed|Arial"
#define de_family   "Any|Charter|Courier|Helvetica|Gothic|New Century Schoolbook|Times|Symbol|Utopia|Luxi Mono|Luxi Serif|Lucida|Lucida Bright|Lucida Typewriter|Newspaper|Terminal|Fixed|Arial"
#define nl_family   "Any|Charter|Courier|Helvetica|Gothic|New Century Schoolbook|Times|Symbol|Utopia|Luxi Mono|Luxi Serif|Lucida|Lucida Bright|Lucida Typewriter|Newspaper|Terminal|Fixed|Arial"
#define pt_family   "Any|Charter|Courier|Helvetica|Gothic|New Century Schoolbook|Times|Symbol|Utopia|Luxi Mono|Luxi Serif|Lucida|Lucida Bright|Lucida Typewriter|Newspaper|Terminal|Fixed|Arial"
#define xx_family   "Any|Charter|Courier|Helvetica|Gothic|New Century Schoolbook|Times|Symbol|Utopia|Luxi Mono|Luxi Serif|Lucida|Lucida Bright|Lucida Typewriter|Newspaper|Terminal|Fixed|Arial"
#define en_Syntax   ""
#define en__Syntax   ""
#define en_resultname   ""
#define en__resultname   ""
#define en_Accept   "<-"
#define fr_Accept   "<-"
#define it_Accept   "<-"
#define es_Accept   "<-"
#define de_Accept   "<-"
#define nl_Accept   "<-"
#define pt_Accept   "<-"
#define xx_Accept   "<-"
#define en_SelectionResult   "Selection Result"
#define fr_SelectionResult   "RÇsultat de la sÇlection"
#define it_SelectionResult   "Selection Result"
#define es_SelectionResult   "Selection Result"
#define de_SelectionResult   "Selection Result"
#define nl_SelectionResult   "Selection Result"
#define pt_SelectionResult   "Selection Result"
#define xx_SelectionResult   "Selection Result"
#define en_FontList   "System Font Name"
#define fr_FontList   "Nom de la police systäme"
#define it_FontList   "System Font Name"
#define es_FontList   "System Font Name"
#define de_FontList   "System Font Name"
#define nl_FontList   "System Font Name"
#define pt_FontList   "System Font Name"
#define xx_FontList   "System Font Name"
#define en__FontList   ""
#define en_FontBar   ""

private struct system_font_selector_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[2+1];
	char * msg_Auto3593[8];
	char * hint_Auto3593[8];
	int	x_Auto3593;
	int	y_Auto3593;
	int	w_Auto3593;
	int	h_Auto3593;
	char * msg_Auto3594[8];
	char * hint_Auto3594[8];
	char * msg_SelectionCriteria[8];
	int	trigger_SelectionCriteria;
	char * hint_SelectionCriteria[8];
	int	page_number;
	char * msg_Set_Font[8];
	int	trigger_Set_Font;
	char * hint_Set_Font[8];
	char * msg_Auto3595[8];
	char * hint_Auto3595[8];
	char * msg_Auto3596[8];
	char * hint_Auto3596[8];
	char * msg_Auto3597[8];
	char * hint_Auto3597[8];
	char * msg_Auto3598[8];
	char * hint_Auto3598[8];
	char * msg_Auto3599[8];
	char * hint_Auto3599[8];
	char * msg_Auto3600[8];
	char * hint_Auto3600[8];
	char * msg_Auto3601[8];
	char * hint_Auto3601[8];
	char * msg_Auto3602[8];
	char * hint_Auto3602[8];
	char * msg_Auto3603[8];
	char * hint_Auto3603[8];
	char * msg_Auto3604[8];
	char * hint_Auto3604[8];
	char * msg_Auto3605[8];
	char * hint_Auto3605[8];
	char * msg_Auto3606[8];
	char * hint_Auto3606[8];
	char * msg_Auto3607[8];
	char * hint_Auto3607[8];
	char * msg_Auto3608[8];
	char * hint_Auto3608[8];
	char * msg_Auto3609[8];
	char * hint_Auto3609[8];
	char * msg_Auto3610[8];
	char * hint_Auto3610[8];
	char * hint_foundry[8];
	char	buffer_foundry[62];
	char * msg_slant[8];
	char * hint_slant[8];
	int	value_slant;
	char * hint_charset[8];
	char	buffer_charset[62];
	char * hint_wname[8];
	char	buffer_wname[62];
	char * hint_wcharset[8];
	char	buffer_wcharset[16];
	char * hint_wnature[8];
	char	buffer_wnature[28];
	char * msg_setwidth[8];
	char * hint_setwidth[8];
	int	value_setwidth;
	char * hint_average[8];
	char	buffer_average[16];
	char * msg_spacing[8];
	char * hint_spacing[8];
	int	value_spacing;
	char * msg_vresdpi[8];
	char * hint_vresdpi[8];
	int	value_vresdpi;
	char * msg_hresdpi[8];
	char * hint_hresdpi[8];
	int	value_hresdpi;
	char * hint_points[8];
	char	buffer_points[16];
	char * hint_pixels[8];
	char	buffer_pixels[16];
	char * msg_weight[8];
	char * hint_weight[8];
	int	value_weight;
	char * msg_family[8];
	char * hint_family[8];
	int	value_family;
	char * hint_Syntax[8];
	char	buffer_Syntax[353];
	char * hint_resultname[8];
	char	buffer_resultname[185];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_SelectionResult[8];
	int	trigger_SelectionResult;
	char * hint_SelectionResult[8];
	char * msg_FontList[8];
	char * hint_FontList[8];
	int	value_FontList;
	int	column_FontList;
	char	buffer_FontList[26][90];
	int	formsort_FontList;	/* sort 0 rien, positif numÈro de colonne, nÈgatif, numÈro de colonne tri decroissant */
	char	*libsort_FontList;	/* table intermÈdiaire contenant la liste des ÈlÈments a trier */
	int	*tabsort_FontList;	/* numÈro d'ordre des elements triÈs */
	char	*indsort_FontList;	/* pointeur table intermÈdiaire de tri */
	int	nelt_FontList;	/* nombre d'elÈments alouÈs dans tabsort */
	char * row_FontList;
	char * hint_FontBar[8];
	int	value_FontBar;
	int	limit_FontBar;
	int	max_FontBar;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];
private int on_Syntax_create(struct system_font_selector_context * _Context);
private int on_resultname_create(struct system_font_selector_context * _Context);
private int on_FontList_show(struct system_font_selector_context * _Context);
private int on_Set_Font_event(struct system_font_selector_context * _Context);
private int on_Syntax_event(struct system_font_selector_context * _Context);
private int on_Accept_event(struct system_font_selector_context * _Context);
private int on_FontList_event(struct system_font_selector_context * _Context);
private int on_FontBar_event(struct system_font_selector_context * _Context);
private int on_foundry_remove(struct system_font_selector_context * _Context);
private int on_charset_remove(struct system_font_selector_context * _Context);
private int on_wname_remove(struct system_font_selector_context * _Context);
private int on_wcharset_remove(struct system_font_selector_context * _Context);
private int on_wnature_remove(struct system_font_selector_context * _Context);
private int on_resultname_remove(struct system_font_selector_context * _Context);
static short	notwhite(struct system_font_selector_context * _Context,char * bptr, int blen);
private int  sort_item_FontList(struct system_font_selector_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_FontList(struct system_font_selector_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_FontList(struct system_font_selector_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_FontList */
private int compare_FontList(struct system_font_selector_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_FontList */

/*	------------------	*/
/*	n o t w h i t e ()	*/
/*	------------------	*/
static short	notwhite(struct system_font_selector_context * _Context,char * bptr, int blen){
	int i,l;
	for(l=0,i=0;i<blen;i++){
	if(!(*(bptr+i)))
	break;
	else if(*(bptr+i)!=' ')
	l=(i+1);
	}
	return(l);
	
}
/* ------------------- */
/* resolve sorted item */
/* ------------------- */
private int  sort_item_FontList(struct system_font_selector_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_FontList[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_FontList(struct system_font_selector_context * _Context,int nelts)
{
if (_Context->nelt_FontList<nelts) {
	liberate(_Context->tabsort_FontList);
	if ((_Context->tabsort_FontList=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_FontList=0;_Context->nelt_FontList<nelts;_Context->nelt_FontList++)
		{ _Context->tabsort_FontList[_Context->nelt_FontList]=_Context->nelt_FontList+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_FontList=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_FontList=allocate(nelts*90)) != NULL)
	memset(_Context->libsort_FontList,' ',nelts*90);
}

/* ----------------------------------------------------------- */
/* sort the intermediate table into _Context->tabsort_FontList */
/* ----------------------------------------------------------- */
private void sort_FontList(struct system_font_selector_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_FontList,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_FontList[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_FontList[j]) && (compare_FontList(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_FontList[i]=k+1;
	_Context->indsort_FontList[k]=1;
	};	/* for i */
liberate(_Context->libsort_FontList);
liberate(_Context->indsort_FontList);
}

/* --------------------------------------------------------- */
/* compare the elements a et b of _Context->libsort_FontList */
/* --------------------------------------------------------- */
private int compare_FontList(struct system_font_selector_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_FontList[90*a],&_Context->libsort_FontList[90*b],90);	/* comparaison zone 1 */
switch (_Context->formsort_FontList) {
	case 1:	/* System Font Name ordre normal */
		return(i);

	case -1:	/* System Font Name ordre inverse */
		return(-i);
	default:		/* pas de tri */
		if (a<b) return(-1);
		return(1);
	}; /* fin du switch */
}

private int on_Syntax_create(struct system_font_selector_context * _Context) {
	int i;
	char*rptr;
	strcpy((rptr=_Context->buffer_Syntax),"*");rptr+=strlen(rptr);
	if((i=notwhite(_Context, _Context->buffer_foundry,61))!=0){
	memcpy(rptr,_Context->buffer_foundry,i);
	*(rptr+i)=0;
	}
	strcat(rptr,"-");rptr+=strlen(rptr);
	switch(_Context->value_family){
	case 0:strcat(rptr,"*");break;
	case 1:strcat(rptr,"charter");break;
	case 2:strcat(rptr,"courier");break;
	case 3:strcat(rptr,"helvetica");break;
	case 4:strcat(rptr,"gothic");break;
	case 5:strcat(rptr,"new century schoolbook");break;
	case 6:strcat(rptr,"times");break;
	case 7:strcat(rptr,"symbol");break;
	case 8:strcat(rptr,"utopia");break;
	case 9:strcat(rptr,"luxi moni");break;
	case 10:strcat(rptr,"luxi serif");break;
	case 11:strcat(rptr,"lucida");break;
	case 12:strcat(rptr,"lucidabright");break;
	case 13:strcat(rptr,"lucidatypewriter");break;
	case 14:strcat(rptr,"newspaper");break;
	case 15:strcat(rptr,"terminal");break;
	case 16:strcat(rptr,"fixed");break;
	case 17:strcat(rptr,"arial");break;
	}
	strcat(rptr,"-");rptr+=strlen(rptr);
	switch(_Context->value_weight){
	case 0:strcat(rptr,"*");break;
	case 1:strcat(rptr,"medium");break;
	case 2:strcat(rptr,"bold");break;
	case 3:strcat(rptr,"black");break;
	case 4:strcat(rptr,"regular");break;
	}
	strcat(rptr,"-");rptr+=strlen(rptr);
	switch(_Context->value_slant){
	case 0:strcat(rptr,"*");break;
	case 1:strcat(rptr,"r");break;
	case 2:strcat(rptr,"i");break;
	case 3:strcat(rptr,"o");break;
	}
	strcat(rptr,"-");rptr+=strlen(rptr);
	switch(_Context->value_setwidth){
	case 0:strcat(rptr,"*");break;
	case 1:strcat(rptr,"normal");break;
	case 2:strcat(rptr,"condensed");break;
	case 3:strcat(rptr,"narrow");break;
	case 4:strcat(rptr,"double width");break;
	}
	strcat(rptr,"-");rptr+=strlen(rptr);
	if((i=notwhite(_Context, _Context->buffer_pixels,15))!=0){
	memcpy(rptr,_Context->buffer_pixels,i);
	*(rptr+i)=0;
	}
	else strcat(rptr,"*");
	strcat(rptr,"-");rptr+=strlen(rptr);
	if((i=notwhite(_Context, _Context->buffer_points,15))!=0){
	memcpy(rptr,_Context->buffer_points,i);
	*(rptr+i)=0;
	}
	else strcat(rptr,"*");
	strcat(rptr,"-");rptr+=strlen(rptr);
	switch(_Context->value_hresdpi){
	case 0:strcat(rptr,"*");break;
	case 1:strcat(rptr,"75");break;
	case 2:strcat(rptr,"100");break;
	case 3:strcat(rptr,"120");break;
	case 4:strcat(rptr,"150");break;
	case 5:strcat(rptr,"200");break;
	case 6:strcat(rptr,"240");break;
	case 7:strcat(rptr,"300");break;
	}
	strcat(rptr,"-");rptr+=strlen(rptr);
	switch(_Context->value_vresdpi){
	case 0:strcat(rptr,"*");break;
	case 1:strcat(rptr,"75");break;
	case 2:strcat(rptr,"100");break;
	case 3:strcat(rptr,"120");break;
	case 4:strcat(rptr,"150");break;
	case 5:strcat(rptr,"200");break;
	case 6:strcat(rptr,"240");break;
	case 7:strcat(rptr,"300");break;
	}
	strcat(rptr,"-");rptr+=strlen(rptr);
	switch(_Context->value_spacing){
	case 0:strcat(rptr,"*");break;
	case 1:strcat(rptr,"m");break;
	case 2:strcat(rptr,"p");break;
	case 3:strcat(rptr,"c");break;
	}
	strcat(rptr,"-");rptr+=strlen(rptr);
	if((i=notwhite(_Context, _Context->buffer_average,15))!=0){
	memcpy(rptr,_Context->buffer_average,i);
	*(rptr+i)=0;
	}
	else strcat(rptr,"*");
	strcat(rptr,"-");rptr+=strlen(rptr);
	if((i=notwhite(_Context, _Context->buffer_charset,61))!=0){
	memcpy(rptr,_Context->buffer_charset,i);
	*(rptr+i)=0;
	}
	else strcat(rptr,"*");
	strcat(rptr,"{");rptr+=strlen(rptr);
	if((i=notwhite(_Context, _Context->buffer_wname,61))!=0){
	memcpy(rptr,_Context->buffer_wname,i);
	*(rptr+i)=0;
	}
	else strcat(rptr,"*");
	strcat(rptr,"-");rptr+=strlen(rptr);
	if((i=notwhite(_Context, _Context->buffer_wcharset,15))!=0){
	memcpy(rptr,_Context->buffer_wcharset,i);
	*(rptr+i)=0;
	}
	else strcat(rptr,"*");
	strcat(rptr,"-");rptr+=strlen(rptr);
	if((i=notwhite(_Context, _Context->buffer_wnature,27))!=0){
	memcpy(rptr,_Context->buffer_wnature,i);
	*(rptr+i)=0;
	}
	else strcat(rptr,"*");
	return(-1);
}
private int on_resultname_create(struct system_font_selector_context * _Context) {
	int i;
	int j;
	int k;
	int m;
	for(i=0;i<184;i++){
	if((_Context->buffer_resultname[i]=='{')&&(i>0)){
	_Context->buffer_resultname[i++]=' ';
	for(j=0;j<61;j++){
	if(_Context->buffer_resultname[i+j]=='-')
	break;
	else _Context->buffer_wname[j]=_Context->buffer_resultname[i+j];
	_Context->buffer_resultname[i+j]=' ';
	}
	if(_Context->buffer_resultname[i+j]!='-')
	break;
	_Context->buffer_resultname[i+j]=' ';
	j++;
	for(k=0;k<15;k++){
	if(_Context->buffer_resultname[i+j+k]=='-')
	break;
	else _Context->buffer_wcharset[k]=_Context->buffer_resultname[i+j+k];
	_Context->buffer_resultname[i+j+k]=' ';
	}
	if(_Context->buffer_resultname[i+j+k]!='-')
	break;
	_Context->buffer_resultname[i+j+k]=' ';
	k++;
	for(m=0;m<27;m++){
	if(_Context->buffer_resultname[i+j+k+m]==' ')
	break;
	else _Context->buffer_wnature[m]=_Context->buffer_resultname[i+j+k+m];
	_Context->buffer_resultname[i+j+k+m]=' ';
	}
	_Context->buffer_resultname[i+j+k+m]=' ';
	break;
	}
	}
	return(-1);
}

public	int	system_font_selector_create(
	struct system_font_selector_context ** cptr,
	char * presultname)
{

	int i;
	struct system_font_selector_context * _Context=(struct system_font_selector_context*)0;
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
	if (!(_Context = allocate( sizeof( struct system_font_selector_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=23;
	_Context->page_number=1;
		for (i=0; i < 61; i++)  *(_Context->buffer_foundry+i)=' ';
		_Context->value_slant=0;
		for (i=0; i < 61; i++)  *(_Context->buffer_charset+i)=' ';
		for (i=0; i < 61; i++)  *(_Context->buffer_wname+i)=' ';
		for (i=0; i < 15; i++)  *(_Context->buffer_wcharset+i)=' ';
		for (i=0; i < 27; i++)  *(_Context->buffer_wnature+i)=' ';
		_Context->value_setwidth=0;
		for (i=0; i < 15; i++)  *(_Context->buffer_average+i)=' ';
		_Context->value_spacing=0;
		_Context->value_vresdpi=0;
		_Context->value_hresdpi=0;
		for (i=0; i < 15; i++)  *(_Context->buffer_points+i)=' ';
		for (i=0; i < 15; i++)  *(_Context->buffer_pixels+i)=' ';
		_Context->value_weight=0;
		_Context->value_family=0;
		for (i=0; i < 352; i++)  *(_Context->buffer_Syntax+i)=' ';
	_Context->formsort_FontList=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_FontList=NULL;	/* pas de table intermÈdiaire de tri */
	if ((_Context->tabsort_FontList=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_FontList=0;_Context->nelt_FontList<512;_Context->nelt_FontList++)
			{ _Context->tabsort_FontList[_Context->nelt_FontList]=_Context->nelt_FontList+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_FontList=0; /* si problËme d'allocation */
_Context->indsort_FontList=NULL;	/* pas de pointeur de table intermÈdiaire */		_Context->max_FontBar=0;
		_Context->limit_FontBar=0;
		_Context->value_FontBar=0;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_resultname, 184, presultname);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3593[i]=" ";
	_Context->hint_Auto3593[0]=en__Auto3593;
	_Context->hint_Auto3593[1]=fr__Auto3593;
	_Context->hint_Auto3593[2]=it__Auto3593;
	_Context->hint_Auto3593[3]=es__Auto3593;
	_Context->hint_Auto3593[4]=de__Auto3593;
	_Context->hint_Auto3593[5]=nl__Auto3593;
	_Context->hint_Auto3593[6]=pt__Auto3593;
	_Context->hint_Auto3593[7]=xx__Auto3593;
	_Context->x_Auto3593=0;
	_Context->y_Auto3593=0;
	_Context->w_Auto3593=790;
	_Context->h_Auto3593=590;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3594[i]=" ";
	_Context->msg_Auto3594[0]=en_Auto3594;
	_Context->msg_Auto3594[1]=fr_Auto3594;
	_Context->msg_Auto3594[2]=it_Auto3594;
	_Context->msg_Auto3594[3]=es_Auto3594;
	_Context->msg_Auto3594[4]=de_Auto3594;
	_Context->msg_Auto3594[5]=nl_Auto3594;
	_Context->msg_Auto3594[6]=pt_Auto3594;
	_Context->msg_Auto3594[7]=xx_Auto3594;
	for (i=0; i < 8; i++)_Context->msg_SelectionCriteria[i]=" ";
	_Context->msg_SelectionCriteria[0]=en_SelectionCriteria;
	_Context->msg_SelectionCriteria[1]=fr_SelectionCriteria;
	_Context->msg_SelectionCriteria[2]=it_SelectionCriteria;
	_Context->msg_SelectionCriteria[3]=es_SelectionCriteria;
	_Context->msg_SelectionCriteria[4]=de_SelectionCriteria;
	_Context->msg_SelectionCriteria[5]=nl_SelectionCriteria;
	_Context->msg_SelectionCriteria[6]=pt_SelectionCriteria;
	_Context->msg_SelectionCriteria[7]=xx_SelectionCriteria;
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_Set_Font[i]=" ";
	_Context->msg_Set_Font[0]=en_Set_Font;
	_Context->msg_Set_Font[1]=fr_Set_Font;
	_Context->msg_Set_Font[2]=it_Set_Font;
	_Context->msg_Set_Font[3]=es_Set_Font;
	_Context->msg_Set_Font[4]=de_Set_Font;
	_Context->msg_Set_Font[5]=nl_Set_Font;
	_Context->msg_Set_Font[6]=pt_Set_Font;
	_Context->msg_Set_Font[7]=xx_Set_Font;
	_Context->hint_Set_Font[0]=en__Set_Font;
	for (i=0; i < 8; i++)_Context->msg_Auto3595[i]=" ";
	_Context->msg_Auto3595[0]=en_Auto3595;
	_Context->msg_Auto3595[1]=fr_Auto3595;
	_Context->msg_Auto3595[2]=it_Auto3595;
	_Context->msg_Auto3595[3]=es_Auto3595;
	_Context->msg_Auto3595[4]=de_Auto3595;
	_Context->msg_Auto3595[5]=nl_Auto3595;
	_Context->msg_Auto3595[6]=pt_Auto3595;
	_Context->msg_Auto3595[7]=xx_Auto3595;
	for (i=0; i < 8; i++)_Context->msg_Auto3596[i]=" ";
	_Context->msg_Auto3596[0]=en_Auto3596;
	_Context->msg_Auto3596[1]=fr_Auto3596;
	_Context->msg_Auto3596[2]=it_Auto3596;
	_Context->msg_Auto3596[3]=es_Auto3596;
	_Context->msg_Auto3596[4]=de_Auto3596;
	_Context->msg_Auto3596[5]=nl_Auto3596;
	_Context->msg_Auto3596[6]=pt_Auto3596;
	_Context->msg_Auto3596[7]=xx_Auto3596;
	for (i=0; i < 8; i++)_Context->msg_Auto3597[i]=" ";
	_Context->msg_Auto3597[0]=en_Auto3597;
	_Context->msg_Auto3597[1]=fr_Auto3597;
	_Context->msg_Auto3597[2]=it_Auto3597;
	_Context->msg_Auto3597[3]=es_Auto3597;
	_Context->msg_Auto3597[4]=de_Auto3597;
	_Context->msg_Auto3597[5]=nl_Auto3597;
	_Context->msg_Auto3597[6]=pt_Auto3597;
	_Context->msg_Auto3597[7]=xx_Auto3597;
	for (i=0; i < 8; i++)_Context->msg_Auto3598[i]=" ";
	_Context->msg_Auto3598[0]=en_Auto3598;
	_Context->msg_Auto3598[1]=fr_Auto3598;
	_Context->msg_Auto3598[2]=it_Auto3598;
	_Context->msg_Auto3598[3]=es_Auto3598;
	_Context->msg_Auto3598[4]=de_Auto3598;
	_Context->msg_Auto3598[5]=nl_Auto3598;
	_Context->msg_Auto3598[6]=pt_Auto3598;
	_Context->msg_Auto3598[7]=xx_Auto3598;
	for (i=0; i < 8; i++)_Context->msg_Auto3599[i]=" ";
	_Context->msg_Auto3599[0]=en_Auto3599;
	_Context->msg_Auto3599[1]=fr_Auto3599;
	_Context->msg_Auto3599[2]=it_Auto3599;
	_Context->msg_Auto3599[3]=es_Auto3599;
	_Context->msg_Auto3599[4]=de_Auto3599;
	_Context->msg_Auto3599[5]=nl_Auto3599;
	_Context->msg_Auto3599[6]=pt_Auto3599;
	_Context->msg_Auto3599[7]=xx_Auto3599;
	for (i=0; i < 8; i++)_Context->msg_Auto3600[i]=" ";
	_Context->msg_Auto3600[0]=en_Auto3600;
	_Context->msg_Auto3600[1]=fr_Auto3600;
	_Context->msg_Auto3600[2]=it_Auto3600;
	_Context->msg_Auto3600[3]=es_Auto3600;
	_Context->msg_Auto3600[4]=de_Auto3600;
	_Context->msg_Auto3600[5]=nl_Auto3600;
	_Context->msg_Auto3600[6]=pt_Auto3600;
	_Context->msg_Auto3600[7]=xx_Auto3600;
	for (i=0; i < 8; i++)_Context->msg_Auto3601[i]=" ";
	_Context->msg_Auto3601[0]=en_Auto3601;
	_Context->msg_Auto3601[1]=fr_Auto3601;
	_Context->msg_Auto3601[2]=it_Auto3601;
	_Context->msg_Auto3601[3]=es_Auto3601;
	_Context->msg_Auto3601[4]=de_Auto3601;
	_Context->msg_Auto3601[5]=nl_Auto3601;
	_Context->msg_Auto3601[6]=pt_Auto3601;
	_Context->msg_Auto3601[7]=xx_Auto3601;
	for (i=0; i < 8; i++)_Context->msg_Auto3602[i]=" ";
	_Context->msg_Auto3602[0]=en_Auto3602;
	_Context->msg_Auto3602[1]=fr_Auto3602;
	_Context->msg_Auto3602[2]=it_Auto3602;
	_Context->msg_Auto3602[3]=es_Auto3602;
	_Context->msg_Auto3602[4]=de_Auto3602;
	_Context->msg_Auto3602[5]=nl_Auto3602;
	_Context->msg_Auto3602[6]=pt_Auto3602;
	_Context->msg_Auto3602[7]=xx_Auto3602;
	for (i=0; i < 8; i++)_Context->msg_Auto3603[i]=" ";
	_Context->msg_Auto3603[0]=en_Auto3603;
	_Context->msg_Auto3603[1]=fr_Auto3603;
	_Context->msg_Auto3603[2]=it_Auto3603;
	_Context->msg_Auto3603[3]=es_Auto3603;
	_Context->msg_Auto3603[4]=de_Auto3603;
	_Context->msg_Auto3603[5]=nl_Auto3603;
	_Context->msg_Auto3603[6]=pt_Auto3603;
	_Context->msg_Auto3603[7]=xx_Auto3603;
	for (i=0; i < 8; i++)_Context->msg_Auto3604[i]=" ";
	_Context->msg_Auto3604[0]=en_Auto3604;
	_Context->msg_Auto3604[1]=fr_Auto3604;
	_Context->msg_Auto3604[2]=it_Auto3604;
	_Context->msg_Auto3604[3]=es_Auto3604;
	_Context->msg_Auto3604[4]=de_Auto3604;
	_Context->msg_Auto3604[5]=nl_Auto3604;
	_Context->msg_Auto3604[6]=pt_Auto3604;
	_Context->msg_Auto3604[7]=xx_Auto3604;
	for (i=0; i < 8; i++)_Context->msg_Auto3605[i]=" ";
	_Context->msg_Auto3605[0]=en_Auto3605;
	_Context->msg_Auto3605[1]=fr_Auto3605;
	_Context->msg_Auto3605[2]=it_Auto3605;
	_Context->msg_Auto3605[3]=es_Auto3605;
	_Context->msg_Auto3605[4]=de_Auto3605;
	_Context->msg_Auto3605[5]=nl_Auto3605;
	_Context->msg_Auto3605[6]=pt_Auto3605;
	_Context->msg_Auto3605[7]=xx_Auto3605;
	for (i=0; i < 8; i++)_Context->msg_Auto3606[i]=" ";
	_Context->msg_Auto3606[0]=en_Auto3606;
	_Context->msg_Auto3606[1]=fr_Auto3606;
	_Context->msg_Auto3606[2]=it_Auto3606;
	_Context->msg_Auto3606[3]=es_Auto3606;
	_Context->msg_Auto3606[4]=de_Auto3606;
	_Context->msg_Auto3606[5]=nl_Auto3606;
	_Context->msg_Auto3606[6]=pt_Auto3606;
	_Context->msg_Auto3606[7]=xx_Auto3606;
	for (i=0; i < 8; i++)_Context->msg_Auto3607[i]=" ";
	_Context->msg_Auto3607[0]=en_Auto3607;
	_Context->msg_Auto3607[1]=fr_Auto3607;
	_Context->msg_Auto3607[2]=it_Auto3607;
	_Context->msg_Auto3607[3]=es_Auto3607;
	_Context->msg_Auto3607[4]=de_Auto3607;
	_Context->msg_Auto3607[5]=nl_Auto3607;
	_Context->msg_Auto3607[6]=pt_Auto3607;
	_Context->msg_Auto3607[7]=xx_Auto3607;
	_Context->hint_Auto3607[0]=en__Auto3607;
	for (i=0; i < 8; i++)_Context->msg_Auto3608[i]=" ";
	_Context->msg_Auto3608[0]=en_Auto3608;
	_Context->msg_Auto3608[1]=fr_Auto3608;
	_Context->msg_Auto3608[2]=it_Auto3608;
	_Context->msg_Auto3608[3]=es_Auto3608;
	_Context->msg_Auto3608[4]=de_Auto3608;
	_Context->msg_Auto3608[5]=nl_Auto3608;
	_Context->msg_Auto3608[6]=pt_Auto3608;
	_Context->msg_Auto3608[7]=xx_Auto3608;
	_Context->hint_Auto3608[0]=en__Auto3608;
	for (i=0; i < 8; i++)_Context->msg_Auto3609[i]=" ";
	_Context->msg_Auto3609[0]=en_Auto3609;
	_Context->msg_Auto3609[1]=fr_Auto3609;
	_Context->msg_Auto3609[2]=it_Auto3609;
	_Context->msg_Auto3609[3]=es_Auto3609;
	_Context->msg_Auto3609[4]=de_Auto3609;
	_Context->msg_Auto3609[5]=nl_Auto3609;
	_Context->msg_Auto3609[6]=pt_Auto3609;
	_Context->msg_Auto3609[7]=xx_Auto3609;
	_Context->hint_Auto3609[0]=en__Auto3609;
	for (i=0; i < 8; i++)_Context->msg_Auto3610[i]=" ";
	_Context->msg_Auto3610[0]=en_Auto3610;
	_Context->msg_Auto3610[1]=fr_Auto3610;
	_Context->msg_Auto3610[2]=it_Auto3610;
	_Context->msg_Auto3610[3]=es_Auto3610;
	_Context->msg_Auto3610[4]=de_Auto3610;
	_Context->msg_Auto3610[5]=nl_Auto3610;
	_Context->msg_Auto3610[6]=pt_Auto3610;
	_Context->msg_Auto3610[7]=xx_Auto3610;
	if(SysFontMem.foundry!=(char*)0)
	strcpy(_Context->buffer_foundry,SysFontMem.foundry);
	for (i=0; i < 8; i++)_Context->msg_slant[i]=" ";
	_Context->msg_slant[0]=en_slant;
	_Context->msg_slant[1]=fr_slant;
	_Context->msg_slant[2]=it_slant;
	_Context->msg_slant[3]=es_slant;
	_Context->msg_slant[4]=de_slant;
	_Context->msg_slant[5]=nl_slant;
	_Context->msg_slant[6]=pt_slant;
	_Context->msg_slant[7]=xx_slant;
	_Context->value_slant=SysFontMem.slant;
	if(SysFontMem.charset!=(char*)0)
	strcpy(_Context->buffer_charset,SysFontMem.charset);
	_Context->hint_wname[0]=en__wname;
	if(SysFontMem.charset!=(char*)0)
	strcpy(_Context->buffer_wname,SysFontMem.charset);
	_Context->hint_wcharset[0]=en__wcharset;
	if(SysFontMem.charset!=(char*)0)
	strcpy(_Context->buffer_wcharset,SysFontMem.charset);
	_Context->hint_wnature[0]=en__wnature;
	if(SysFontMem.charset!=(char*)0)
	strcpy(_Context->buffer_wnature,SysFontMem.charset);
	for (i=0; i < 8; i++)_Context->msg_setwidth[i]=" ";
	_Context->msg_setwidth[0]=en_setwidth;
	_Context->msg_setwidth[1]=fr_setwidth;
	_Context->msg_setwidth[2]=it_setwidth;
	_Context->msg_setwidth[3]=es_setwidth;
	_Context->msg_setwidth[4]=de_setwidth;
	_Context->msg_setwidth[5]=nl_setwidth;
	_Context->msg_setwidth[6]=pt_setwidth;
	_Context->msg_setwidth[7]=xx_setwidth;
	_Context->value_setwidth=SysFontMem.setwidth;
	if(SysFontMem.average!=0)
	sprintf(_Context->buffer_average,"%u",SysFontMem.average);
	for (i=0; i < 8; i++)_Context->msg_spacing[i]=" ";
	_Context->msg_spacing[0]=en_spacing;
	_Context->msg_spacing[1]=fr_spacing;
	_Context->msg_spacing[2]=it_spacing;
	_Context->msg_spacing[3]=es_spacing;
	_Context->msg_spacing[4]=de_spacing;
	_Context->msg_spacing[5]=nl_spacing;
	_Context->msg_spacing[6]=pt_spacing;
	_Context->msg_spacing[7]=xx_spacing;
	_Context->hint_spacing[0]=en__spacing;
	_Context->value_spacing=SysFontMem.spacing;
	for (i=0; i < 8; i++)_Context->msg_vresdpi[i]=" ";
	_Context->msg_vresdpi[0]=en_vresdpi;
	_Context->msg_vresdpi[1]=fr_vresdpi;
	_Context->msg_vresdpi[2]=it_vresdpi;
	_Context->msg_vresdpi[3]=es_vresdpi;
	_Context->msg_vresdpi[4]=de_vresdpi;
	_Context->msg_vresdpi[5]=nl_vresdpi;
	_Context->msg_vresdpi[6]=pt_vresdpi;
	_Context->msg_vresdpi[7]=xx_vresdpi;
	_Context->value_vresdpi=SysFontMem.vresdpi;
	for (i=0; i < 8; i++)_Context->msg_hresdpi[i]=" ";
	_Context->msg_hresdpi[0]=en_hresdpi;
	_Context->msg_hresdpi[1]=fr_hresdpi;
	_Context->msg_hresdpi[2]=it_hresdpi;
	_Context->msg_hresdpi[3]=es_hresdpi;
	_Context->msg_hresdpi[4]=de_hresdpi;
	_Context->msg_hresdpi[5]=nl_hresdpi;
	_Context->msg_hresdpi[6]=pt_hresdpi;
	_Context->msg_hresdpi[7]=xx_hresdpi;
	_Context->value_hresdpi=SysFontMem.hresdpi;
	if(SysFontMem.points!=0)
	sprintf(_Context->buffer_points,"%u",SysFontMem.points);
	if(SysFontMem.pixels!=0)
	sprintf(_Context->buffer_pixels,"%u",SysFontMem.pixels);
	for (i=0; i < 8; i++)_Context->msg_weight[i]=" ";
	_Context->msg_weight[0]=en_weight;
	_Context->msg_weight[1]=fr_weight;
	_Context->msg_weight[2]=it_weight;
	_Context->msg_weight[3]=es_weight;
	_Context->msg_weight[4]=de_weight;
	_Context->msg_weight[5]=nl_weight;
	_Context->msg_weight[6]=pt_weight;
	_Context->msg_weight[7]=xx_weight;
	_Context->value_weight=SysFontMem.weight;
	for (i=0; i < 8; i++)_Context->msg_family[i]=" ";
	_Context->msg_family[0]=en_family;
	_Context->msg_family[1]=fr_family;
	_Context->msg_family[2]=it_family;
	_Context->msg_family[3]=es_family;
	_Context->msg_family[4]=de_family;
	_Context->msg_family[5]=nl_family;
	_Context->msg_family[6]=pt_family;
	_Context->msg_family[7]=xx_family;
	_Context->value_family=SysFontMem.family;
	_Context->hint_Syntax[0]=en__Syntax;
	(void) on_Syntax_create(_Context);
	_Context->hint_resultname[0]=en__resultname;
	(void) on_resultname_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	for (i=0; i < 8; i++)_Context->msg_SelectionResult[i]=" ";
	_Context->msg_SelectionResult[0]=en_SelectionResult;
	_Context->msg_SelectionResult[1]=fr_SelectionResult;
	_Context->msg_SelectionResult[2]=it_SelectionResult;
	_Context->msg_SelectionResult[3]=es_SelectionResult;
	_Context->msg_SelectionResult[4]=de_SelectionResult;
	_Context->msg_SelectionResult[5]=nl_SelectionResult;
	_Context->msg_SelectionResult[6]=pt_SelectionResult;
	_Context->msg_SelectionResult[7]=xx_SelectionResult;
	_Context->focus_pages[2]=21;
	for (i=0; i < 8; i++)_Context->msg_FontList[i]=" ";
	_Context->msg_FontList[0]=en_FontList;
	_Context->msg_FontList[1]=fr_FontList;
	_Context->msg_FontList[2]=it_FontList;
	_Context->msg_FontList[3]=es_FontList;
	_Context->msg_FontList[4]=de_FontList;
	_Context->msg_FontList[5]=nl_FontList;
	_Context->msg_FontList[6]=pt_FontList;
	_Context->msg_FontList[7]=xx_FontList;
	_Context->hint_FontList[0]=en__FontList;
	if ( 0 > 0 ) { _Context->row_FontList=&_Context->buffer_FontList[0-1][0]; } ;
	_Context->max_FontBar=1;
	_Context->value_FontBar=1;
	_Context->limit_FontBar=1;
	_Context->value_FontBar=0;
	_Context->limit_FontBar=25;
	_Context->max_FontBar=25;
		_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(0,0,790+10,590+10);
	return(0);
}

public 	int	system_font_selector_hide(struct system_font_selector_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,0,0);
		_Context->ctrlbuffer=0;
		}

	return(result);
}
private int on_foundry_remove(struct system_font_selector_context * _Context) {
	int i;
	int l;
	char*sptr;
	if(SysFontMem.foundry!=(char*)0){
	liberate(SysFontMem.foundry);
	SysFontMem.foundry=(char*)0;
	}
	if((l=notwhite(_Context, _Context->buffer_foundry,61))>0){
	if((sptr=allocate((l+1)))!=(char*)0){
	for(i=0;i<l;i++)
	*(sptr+i)=_Context->buffer_foundry[i];
	*(sptr+i)=0;
	SysFontMem.foundry=sptr;
	}
	}
	return(-1);
}
private int on_charset_remove(struct system_font_selector_context * _Context) {
	int i;
	int l;
	char*sptr;
	if(SysFontMem.charset!=(char*)0){
	liberate(SysFontMem.charset);
	SysFontMem.charset=(char*)0;
	}
	if((l=notwhite(_Context, _Context->buffer_charset,61))>0){
	if((sptr=allocate((l+1)))!=(char*)0){
	for(i=0;i<l;i++)
	*(sptr+i)=_Context->buffer_charset[i];
	*(sptr+i)=0;
	SysFontMem.charset=sptr;
	}
	}
	return(-1);
}
private int on_wname_remove(struct system_font_selector_context * _Context) {
	int i;
	int l;
	char*sptr;
	if(SysFontMem.charset!=(char*)0){
	liberate(SysFontMem.charset);
	SysFontMem.charset=(char*)0;
	}
	if((l=notwhite(_Context, _Context->buffer_wname,61))>0){
	if((sptr=allocate((l+1)))!=(char*)0){
	for(i=0;i<l;i++)
	*(sptr+i)=_Context->buffer_wname[i];
	*(sptr+i)=0;
	SysFontMem.charset=sptr;
	}
	}
	return(-1);
}
private int on_wcharset_remove(struct system_font_selector_context * _Context) {
	int i;
	int l;
	char*sptr;
	if(SysFontMem.charset!=(char*)0){
	liberate(SysFontMem.charset);
	SysFontMem.charset=(char*)0;
	}
	if((l=notwhite(_Context, _Context->buffer_wcharset,15))>0){
	if((sptr=allocate((l+1)))!=(char*)0){
	for(i=0;i<l;i++)
	*(sptr+i)=_Context->buffer_wcharset[i];
	*(sptr+i)=0;
	SysFontMem.charset=sptr;
	}
	}
	return(-1);
}
private int on_wnature_remove(struct system_font_selector_context * _Context) {
	int i;
	int l;
	char*sptr;
	if(SysFontMem.charset!=(char*)0){
	liberate(SysFontMem.charset);
	SysFontMem.charset=(char*)0;
	}
	if((l=notwhite(_Context, _Context->buffer_wnature,27))>0){
	if((sptr=allocate((l+1)))!=(char*)0){
	for(i=0;i<l;i++)
	*(sptr+i)=_Context->buffer_wnature[i];
	*(sptr+i)=0;
	SysFontMem.charset=sptr;
	}
	}
	return(-1);
}
private int on_resultname_remove(struct system_font_selector_context * _Context) {
	int i;
	int jl;
	int j;
	int k;
	int m;
	for(i=184;i>0;){
	i--;
	if(_Context->buffer_resultname[i]!=' '){
	i++;
	break;
	}
	}
	_Context->buffer_resultname[i]='{';i++;
	for(j=0,jl=0;j<61;j++)
	if(_Context->buffer_wname[j]!=' ')
	jl=(j+1);
	for(j=0;j<jl;j++){
	_Context->buffer_resultname[i+j]=_Context->buffer_wname[j];
	}
	if(!(j)){_Context->buffer_resultname[i+j]='*';j++;}
	_Context->buffer_resultname[i+j]='-';j++;
	for(k=0;k<15;k++){
	if(_Context->buffer_wcharset[k]==' ')
	break;
	else _Context->buffer_resultname[i+j+k]=_Context->buffer_wcharset[k];
	}
	if(!(k)){_Context->buffer_resultname[i+j+k]='*';k++;}
	_Context->buffer_resultname[i+j+k]='-';k++;
	for(m=0;m<27;m++){
	if(_Context->buffer_wnature[m]==' ')
	break;
	else _Context->buffer_resultname[i+j+k+m]=_Context->buffer_wnature[m];
	}
	if(!(m)){_Context->buffer_resultname[i+j+k+m]='*';m++;}
	_Context->buffer_resultname[i+j+k+m]=' ';m++;
	return(-1);
}

public	int	system_font_selector_remove(
	struct system_font_selector_context * _Context,
	char * presultname)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	(void) on_resultname_remove(_Context);
	SysFontMem.family=_Context->value_family;
	SysFontMem.weight=_Context->value_weight;
	SysFontMem.pixels=atoi(_Context->buffer_pixels);
	SysFontMem.points=atoi(_Context->buffer_points);
	SysFontMem.hresdpi=_Context->value_hresdpi;
	SysFontMem.vresdpi=_Context->value_vresdpi;
	SysFontMem.spacing=_Context->value_spacing;
	SysFontMem.average=atoi(_Context->buffer_average);
	SysFontMem.setwidth=_Context->value_setwidth;
	(void) on_wnature_remove(_Context);
	(void) on_wcharset_remove(_Context);
	(void) on_wname_remove(_Context);
	(void) on_charset_remove(_Context);
	SysFontMem.slant=_Context->value_slant;
	(void) on_foundry_remove(_Context);
	dropsysfontlist();
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_resultname, 184, presultname);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_FontList_show(struct system_font_selector_context * _Context) {
	int i;
	int n;
	int x;
	int z;
	char*rptr;
	char**sptr=(char**)0;
	char*nptr;
	/*check for and remove windfows syntax suplement*/
	/*----------------------------------------------*/
	for(z=0;z<352;z++){
	if(_Context->buffer_Syntax[z]=='{'){
	_Context->buffer_Syntax[z]=0;
	break;
	}
	}
		if((_Context->max_FontBar=getsysfontlist(&sptr,_Context->buffer_Syntax,352))!=0){
	for(i=1;i<=25;i++){
	if ( i > 0 ) { _Context->row_FontList=&_Context->buffer_FontList[i-1][0]; } ;
	rptr=(_Context->row_FontList+0);
	if((n=((i-1)+_Context->value_FontBar))<_Context->max_FontBar){
	if((nptr=*(sptr+n))!=(char*)0){
	for(x=0;x<90;x++){
	if(!(*nptr))
	*(rptr+x)=' ';
	else*(rptr+x)=*(nptr++);
	}
	}
	}
	}
	}
	if(z<352){
	_Context->buffer_Syntax[z]='{';
	}
		visual_table(20,110,730,420,vfh[1],16,0,_Context->msg_FontList[_Context->language],_Context->buffer_FontList,0x4401,"($)");
;
	return(-1);
}

public	int	system_font_selector_show(struct system_font_selector_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,0,0);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(0,0,790,590,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(0,0,790,590,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(10,30,768,29,vfh[5],16,0,_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]),1283);
	if (_Context->page_number == 1 ) {
	_Context->trigger_SelectionCriteria=visual_trigger_code(_Context->msg_SelectionCriteria[_Context->language],strlen(_Context->msg_SelectionCriteria[_Context->language]));
	visual_tabpage(10,70,770,470,vfh[2],_Context->msg_SelectionCriteria[_Context->language],strlen(_Context->msg_SelectionCriteria[_Context->language]),0,2);
	} else {
		visual_tabpage(10,70,770,470,vfh[2],_Context->msg_SelectionCriteria[_Context->language],strlen(_Context->msg_SelectionCriteria[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Set_Font=visual_trigger_code(_Context->msg_Set_Font[_Context->language],strlen(_Context->msg_Set_Font[_Context->language]));
	visual_button(50,480,88,32,vfh[2],27,28,_Context->msg_Set_Font[_Context->language],strlen(_Context->msg_Set_Font[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,110,180,20,vfh[2],16,0,_Context->msg_Auto3595[_Context->language],strlen(_Context->msg_Auto3595[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,140,168,17,vfh[2],16,0,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,170,168,17,vfh[2],16,0,_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(420,170,168,17,vfh[2],16,0,_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,200,168,17,vfh[2],16,0,_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,230,210,17,vfh[2],16,0,_Context->msg_Auto3600[_Context->language],strlen(_Context->msg_Auto3600[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(420,230,210,17,vfh[2],16,0,_Context->msg_Auto3601[_Context->language],strlen(_Context->msg_Auto3601[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,260,196,17,vfh[2],16,0,_Context->msg_Auto3602[_Context->language],strlen(_Context->msg_Auto3602[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(420,260,210,17,vfh[2],16,0,_Context->msg_Auto3603[_Context->language],strlen(_Context->msg_Auto3603[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,290,210,17,vfh[2],16,0,_Context->msg_Auto3604[_Context->language],strlen(_Context->msg_Auto3604[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(420,290,207,17,vfh[2],16,0,_Context->msg_Auto3605[_Context->language],strlen(_Context->msg_Auto3605[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,320,182,17,vfh[2],16,0,_Context->msg_Auto3606[_Context->language],strlen(_Context->msg_Auto3606[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,340,182,17,vfh[2],16,0,_Context->msg_Auto3607[_Context->language],strlen(_Context->msg_Auto3607[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,360,182,17,vfh[2],16,0,_Context->msg_Auto3608[_Context->language],strlen(_Context->msg_Auto3608[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(400,360,126,16,vfh[2],16,0,_Context->msg_Auto3609[_Context->language],strlen(_Context->msg_Auto3609[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,390,700,17,vfh[2],16,0,_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(260,110,488+2,16+2,5);
	visual_text(260+1,110+1,488,16,vfh[1],16,0,_Context->buffer_foundry,61,0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(630,170,120,64,vfh[1],16,0,parse_selection(_Context->msg_slant[_Context->language],&_Context->value_slant),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(260,320,488+2,16+2,5);
	visual_text(260+1,320+1,488,16,vfh[1],16,0,_Context->buffer_charset,61,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(260,340,488+2,16+2,5);
	visual_text(260+1,340+1,488,16,vfh[1],16,0,_Context->buffer_wname,61,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(260,360,120+2,16+2,5);
	visual_text(260+1,360+1,120,16,vfh[1],16,0,_Context->buffer_wcharset,15,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(530,360,216+2,16+2,5);
	visual_text(530+1,360+1,216,16,vfh[1],16,0,_Context->buffer_wnature,27,0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(260,200,120,64,vfh[1],16,0,parse_selection(_Context->msg_setwidth[_Context->language],&_Context->value_setwidth),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(630,290,120+2,16+2,5);
	visual_text(630+1,290+1,120,16,vfh[1],16,0,_Context->buffer_average,15,0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(260,290,120,80,vfh[1],16,0,parse_selection(_Context->msg_spacing[_Context->language],&_Context->value_spacing),0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(630,260,120,96,vfh[1],16,0,parse_selection(_Context->msg_vresdpi[_Context->language],&_Context->value_vresdpi),0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(260,260,120,112,vfh[1],16,0,parse_selection(_Context->msg_hresdpi[_Context->language],&_Context->value_hresdpi),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(630,230,120+2,16+2,5);
	visual_text(630+1,230+1,120,16,vfh[1],16,0,_Context->buffer_points,15,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(260,230,120+2,16+2,5);
	visual_text(260+1,230+1,120,16,vfh[1],16,0,_Context->buffer_pixels,15,0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(260,170,120,64,vfh[1],16,0,parse_selection(_Context->msg_weight[_Context->language],&_Context->value_weight),0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(260,140,488,128,vfh[1],16,0,parse_selection(_Context->msg_family[_Context->language],&_Context->value_family),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(50,410,704+2,64+2,5);
	visual_text(50+1,410+1,704,64,vfh[1],16,0,_Context->buffer_Syntax,352,0);
		}
	visual_frame(10,540,736+2,32+2,5);
	visual_text(10+1,540+1,736,32,vfh[1],0,0,_Context->buffer_resultname,184,0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(750,540,28,32,vfh[8],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	if (_Context->page_number == 2 ) {
	_Context->trigger_SelectionResult=visual_trigger_code(_Context->msg_SelectionResult[_Context->language],strlen(_Context->msg_SelectionResult[_Context->language]));
	visual_tabpage(10,70,770,470,vfh[2],_Context->msg_SelectionResult[_Context->language],strlen(_Context->msg_SelectionResult[_Context->language]),150,2);
	} else {
		visual_tabpage(10,70,770,470,vfh[2],_Context->msg_SelectionResult[_Context->language],strlen(_Context->msg_SelectionResult[_Context->language]),150,0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_FontList_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	visual_scrollbar(750,110,20,420,vfh[1],16,0,_Context->value_FontBar,_Context->limit_FontBar,_Context->max_FontBar,3);
		}
	visual_thaw(0,0,790,590);

	return(0);
}

private int SelectionCriteria_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This page presents the complete collection of fields required for ";
			mptr[1]="the selection of X/11 system font files.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int foundry_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the font foundry or provider name to be specified. ";
			mptr[1]="If left blank it will default to star allowing selection of any foundry ";
			mptr[2]="name.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int slant_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This control allows the font slant to be chosen.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int charset_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the character set name to be specified. This ";
			mptr[1]="will default to any when left blank.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int wname_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the character set name to be specified. This ";
			mptr[1]="will default to any when left blank.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int wcharset_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the character set name to be specified. This ";
			mptr[1]="will default to any when left blank.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int wnature_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the character set name to be specified. This ";
			mptr[1]="will default to any when left blank.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int setwidth_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "The font width characteristics may be selected by this control.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int average_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "You may specify here a required average character with. Again zero ";
			mptr[1]="values have a special meaning.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int spacing_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of the font spacing type between fixed ";
			mptr[1]="and proportional.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int vresdpi_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of the vertical resolution for which ";
			mptr[1]="the font  originally was intended.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int hresdpi_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of the horizontal resolution for which ";
			mptr[1]="the font  originally was intended.     ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int points_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the required dimensions of the font to be specified ";
			mptr[1]="in points or rather tenths of a point. This field will default to ";
			mptr[2]="any but be careful of zero values which have a special meaning.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int pixels_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the required pixel dimension of the font to ";
			mptr[1]="be specified. This field will default to any but be careful of zero ";
			mptr[2]="values which have a special meaning.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int weight_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This control allows the selection of the required font weight.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int family_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This selection control offser the complete list of font family types ";
			mptr[1]="currently available.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Syntax_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field displays the resulting selection syntax comprising ";
			mptr[1]="the various fields as will be presented to the font selection manager ";
			mptr[2]="to provide the selection result.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int resultname_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field shows the currently selected font name that may be ";
			mptr[1]="returned to the calling process by clicking on the validation button ";
			mptr[2]="to the right.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SelectionResult_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This page presents the list of system fonts matching the constructed ";
			mptr[1]="font selection syntax.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FontList_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This table shows the first ten thousand fonts which match the selection ";
			mptr[1]="criteria.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}
private int on_Set_Font_event(struct system_font_selector_context * _Context) {
	int i;
	*(_Context->buffer_resultname+0)='{';
	for(i=0;i<(184-1);i++){
	if(i<352)
	*(_Context->buffer_resultname+(i+1))=*(_Context->buffer_Syntax+i);
	else*(_Context->buffer_resultname+(i+1))=' ';
	}
	visual_frame(10,540,736+2,32+2,5);
visual_text(10+1,540+1,736,32,vfh[1],0,0,_Context->buffer_resultname,184,0);
;
	return(-1);
}
private int on_Syntax_event(struct system_font_selector_context * _Context) {
	on_Syntax_create(_Context);
	visual_frame(50,410,704+2,64+2,5);
visual_text(50+1,410+1,704,64,vfh[1],16,0,_Context->buffer_Syntax,352,0);
;
	dropsysfontlist();
	return(-1);
}
private int on_Accept_event(struct system_font_selector_context * _Context) {
	return(13);
	return(-1);
}
private int on_FontList_event(struct system_font_selector_context * _Context) {
	int l;
	int i;
	l=_Context->value_FontList;
	if(l>0){
	if ( l > 0 ) { _Context->row_FontList=&_Context->buffer_FontList[l-1][0]; } ;
	*(_Context->buffer_resultname+0)='{';
	for(i=0;i<(184-1);i++){
	if(i<90)
	*(_Context->buffer_resultname+(i+1))=*((_Context->row_FontList+0)+i);
	else*(_Context->buffer_resultname+(i+1))=' ';
	}
	visual_frame(10,540,736+2,32+2,5);
visual_text(10+1,540+1,736,32,vfh[1],0,0,_Context->buffer_resultname,184,0);
;
	}
	return(-1);
}
private int on_FontBar_event(struct system_font_selector_context * _Context) {
	on_FontList_show(_Context);
	return(-1);
}

private int on_FontBar_action(struct system_font_selector_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (110+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_FontBar -= 1;
		if (_Context->value_FontBar < 0) 
			_Context->value_FontBar = 0;
		(void) on_FontBar_event(_Context);
	visual_scrollbar(750,110,20,420,vfh[1],16,0,_Context->value_FontBar,_Context->limit_FontBar,_Context->max_FontBar,259);
		return(-1);
		}
	if ( visual_event(6) > (110+420-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_FontBar += 1;
		if (!(_Context->max_FontBar))
			_Context->value_FontBar = 0;
		else if ((_Context->max_FontBar < _Context->limit_FontBar) 
		&& (_Context->value_FontBar >= _Context->max_FontBar)) 
			_Context->value_FontBar = (_Context->max_FontBar-1);
		else if (_Context->value_FontBar > (_Context->max_FontBar-_Context->limit_FontBar)) 
			_Context->value_FontBar = (_Context->max_FontBar-_Context->limit_FontBar);
		(void) on_FontBar_event(_Context);
	visual_scrollbar(750,110,20,420,vfh[1],16,0,_Context->value_FontBar,_Context->limit_FontBar,_Context->max_FontBar,259);
		return(-1);
		}
	visual_scrollbar(750,110,20,420,vfh[1],16,0,_Context->value_FontBar,_Context->limit_FontBar,_Context->max_FontBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_FontBar;
		_Context->value_FontBar = (((visual_event(6) - (110+20)) * _Context->max_FontBar) / (420 - (2 * 20)));
		if (_Context->value_FontBar < 0) 
			_Context->value_FontBar = 0;
		else if (_Context->value_FontBar > (_Context->max_FontBar-_Context->limit_FontBar)) 
			_Context->value_FontBar = (_Context->max_FontBar-_Context->limit_FontBar);
		if (_Context->value_FontBar != aty) {
		(void) on_FontBar_event(_Context);
	visual_scrollbar(750,110,20,420,vfh[1],16,0,_Context->value_FontBar,_Context->limit_FontBar,_Context->max_FontBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_FontBar -= (_Context->limit_FontBar/2);
			if (_Context->value_FontBar < 0) 
				_Context->value_FontBar = 0;
		(void) on_FontBar_event(_Context);
	visual_scrollbar(750,110,20,420,vfh[1],16,0,_Context->value_FontBar,_Context->limit_FontBar,_Context->max_FontBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_FontBar += (_Context->limit_FontBar/2);
			if (!(_Context->max_FontBar))
				_Context->value_FontBar = 0;
			else if ((_Context->max_FontBar < _Context->limit_FontBar) 
			&& (_Context->value_FontBar >= _Context->max_FontBar)) 
				_Context->value_FontBar = (_Context->max_FontBar-1);
			else if (_Context->value_FontBar > (_Context->max_FontBar-_Context->limit_FontBar)) 
				_Context->value_FontBar = (_Context->max_FontBar-_Context->limit_FontBar);
		(void) on_FontBar_event(_Context);
	visual_scrollbar(750,110,20,420,vfh[1],16,0,_Context->value_FontBar,_Context->limit_FontBar,_Context->max_FontBar,259);
			break;
		}
	visual_scrollbar(750,110,20,420,vfh[1],16,0,_Context->value_FontBar,_Context->limit_FontBar,_Context->max_FontBar,3);

	return(1);
}


public	int	system_font_selector_event(
struct system_font_selector_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_SelectionCriteria == mb ) return(2);
		if (_Context->trigger_Set_Font == mb ) return(3);
		if (_Context->trigger_Accept == mb ) return(20);
		if (_Context->trigger_SelectionResult == mb ) return(21);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= 769 )  
	&&  (my >= 4 )  
	&&  (mx <= 785 )  
	&&  (my <= 20 )) {
		return(1);	/* Auto3593 */

		}
	if ((mx >= 753 )  
	&&  (my >= 4 )  
	&&  (mx <= 769 )  
	&&  (my <= 20 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vsysfont.htm");
			};
		return(-1);	/* Auto3593 */

		}
	if ((mx >= 737 )  
	&&  (my >= 4 )  
	&&  (mx <= 753 )  
	&&  (my <= 20 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		system_font_selector_show(_Context);
		return(-1);	/* Auto3593 */

		}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 10 ) 
		&&  (my >= 70 ) 
		&&  (mx <= 159 ) 
		&&  (my <= 94 )) {
			return(2); /* SelectionCriteria */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 50 ) 
		&&  ( my >= 480 ) 
		&&  ( mx <= 138 ) 
		&&  ( my <= 512 )) {
			return(3); /* Set_Font */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 260 ) 
		&&  ( my >= 110 ) 
		&&  ( mx <= 748 ) 
		&&  ( my <= 126 )) {
			return(4); /* foundry */
			}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 630 ) 
		&&  (my >= 170 ) 
		&&  (mx <= 750 ) 
		&&  (my <= 186 )) {
			return(5); /* slant */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 260 ) 
		&&  ( my >= 320 ) 
		&&  ( mx <= 748 ) 
		&&  ( my <= 336 )) {
			return(6); /* charset */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 260 ) 
		&&  ( my >= 340 ) 
		&&  ( mx <= 748 ) 
		&&  ( my <= 356 )) {
			return(7); /* wname */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 260 ) 
		&&  ( my >= 360 ) 
		&&  ( mx <= 380 ) 
		&&  ( my <= 376 )) {
			return(8); /* wcharset */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 530 ) 
		&&  ( my >= 360 ) 
		&&  ( mx <= 746 ) 
		&&  ( my <= 376 )) {
			return(9); /* wnature */
			}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 260 ) 
		&&  (my >= 200 ) 
		&&  (mx <= 380 ) 
		&&  (my <= 216 )) {
			return(10); /* setwidth */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 630 ) 
		&&  ( my >= 290 ) 
		&&  ( mx <= 750 ) 
		&&  ( my <= 306 )) {
			return(11); /* average */
			}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 260 ) 
		&&  (my >= 290 ) 
		&&  (mx <= 380 ) 
		&&  (my <= 306 )) {
			return(12); /* spacing */
			}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 630 ) 
		&&  (my >= 260 ) 
		&&  (mx <= 750 ) 
		&&  (my <= 276 )) {
			return(13); /* vresdpi */
			}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 260 ) 
		&&  (my >= 260 ) 
		&&  (mx <= 380 ) 
		&&  (my <= 276 )) {
			return(14); /* hresdpi */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 630 ) 
		&&  ( my >= 230 ) 
		&&  ( mx <= 750 ) 
		&&  ( my <= 246 )) {
			return(15); /* points */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 260 ) 
		&&  ( my >= 230 ) 
		&&  ( mx <= 380 ) 
		&&  ( my <= 246 )) {
			return(16); /* pixels */
			}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 260 ) 
		&&  (my >= 170 ) 
		&&  (mx <= 380 ) 
		&&  (my <= 186 )) {
			return(17); /* weight */
			}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 260 ) 
		&&  (my >= 140 ) 
		&&  (mx <= 748 ) 
		&&  (my <= 156 )) {
			return(18); /* family */
			}
		}
	if (( mx >= 10 ) 
	&&  ( my >= 540 ) 
	&&  ( mx <= 746 ) 
	&&  ( my <= 572 )) {
		return(19); /* resultname */
		}
	if (( mx >= 750 ) 
	&&  ( my >= 540 ) 
	&&  ( mx <= 778 ) 
	&&  ( my <= 572 )) {
		return(20); /* Accept */
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 160 ) 
		&&  (my >= 70 ) 
		&&  (mx <= 324 ) 
		&&  (my <= 94 )) {
			return(21); /* SelectionResult */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 20 ) 
		&&  ( my >= 110 ) 
		&&  ( mx <= 750 ) 
		&&  ( my <= 530 )) {
			if ((_Context->value_FontList = ((visual_event(6) - (110)) / 16)) < 1)
				_Context->value_FontList=0;
else if (_Context->value_FontList > 25 )
				_Context->value_FontList=25;
			if ( _Context->value_FontList > 0 ) { _Context->row_FontList = &_Context->buffer_FontList[(_Context->value_FontList-1)][0]; } 
			_Context->column_FontList = (visual_event(7) - (20));
			if ( _Context->column_FontList < 720 ) {
				_Context->column_FontList = 1;
				}
			if ((!(_Context->value_FontList)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
				if (_Context->formsort_FontList==_Context->column_FontList) /* si colonne choisie concerne dÈj‡ le tri */
					_Context->formsort_FontList=-_Context->column_FontList;	/* alors tri dÈcroissant */
				else
					_Context->formsort_FontList=_Context->column_FontList; };	/* sinon tri croissant */
			return(22); /* FontList */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 750 ) 
		&&  ( my >= 110 ) 
		&&  ( mx <= 770 ) 
		&&  ( my <= 530 )) {
			return(23); /* FontBar */
			}
		}

	return(-1);
}


public	int	system_font_selector_losefocus(struct system_font_selector_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;

		}
	return(0);

}


public	int	system_font_selector_focus(struct system_font_selector_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* SelectionCriteria */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* Set_Font */
				if (_Context->page_number == 1 ) {
					_Context->trigger_Set_Font=visual_trigger_code(_Context->msg_Set_Font[_Context->language],strlen(_Context->msg_Set_Font[_Context->language]));
					visual_button(50,480,88,32,vfh[2],27,28,_Context->msg_Set_Font[_Context->language],strlen(_Context->msg_Set_Font[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_Set_Font=visual_trigger_code(_Context->msg_Set_Font[_Context->language],strlen(_Context->msg_Set_Font[_Context->language]));
	visual_button(50,480,88,32,vfh[2],27,28,_Context->msg_Set_Font[_Context->language],strlen(_Context->msg_Set_Font[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* foundry */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(260+1,110+1,488,16,vfh[1],_Context->buffer_foundry,61);
					on_Syntax_event(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* slant */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(630,170,120,64,vfh[1],16,0,parse_selection(_Context->msg_slant[_Context->language],&_Context->value_slant),2);
					on_Syntax_event(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* charset */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(260+1,320+1,488,16,vfh[1],_Context->buffer_charset,61);
					on_Syntax_event(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* wname */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(260+1,340+1,488,16,vfh[1],_Context->buffer_wname,61);
					on_Syntax_event(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* wcharset */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(260+1,360+1,120,16,vfh[1],_Context->buffer_wcharset,15);
					on_Syntax_event(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* wnature */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(530+1,360+1,216,16,vfh[1],_Context->buffer_wnature,27);
					on_Syntax_event(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* setwidth */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(260,200,120,64,vfh[1],16,0,parse_selection(_Context->msg_setwidth[_Context->language],&_Context->value_setwidth),2);
					on_Syntax_event(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* average */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(630+1,290+1,120,16,vfh[1],_Context->buffer_average,15);
					on_Syntax_event(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* spacing */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(260,290,120,80,vfh[1],16,0,parse_selection(_Context->msg_spacing[_Context->language],&_Context->value_spacing),2);
					on_Syntax_event(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* vresdpi */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(630,260,120,96,vfh[1],16,0,parse_selection(_Context->msg_vresdpi[_Context->language],&_Context->value_vresdpi),2);
					on_Syntax_event(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* hresdpi */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(260,260,120,112,vfh[1],16,0,parse_selection(_Context->msg_hresdpi[_Context->language],&_Context->value_hresdpi),2);
					on_Syntax_event(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* points */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(630+1,230+1,120,16,vfh[1],_Context->buffer_points,15);
					on_Syntax_event(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* pixels */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(260+1,230+1,120,16,vfh[1],_Context->buffer_pixels,15);
					on_Syntax_event(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* weight */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(260,170,120,64,vfh[1],16,0,parse_selection(_Context->msg_weight[_Context->language],&_Context->value_weight),2);
					on_Syntax_event(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* family */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(260,140,488,128,vfh[1],16,0,parse_selection(_Context->msg_family[_Context->language],&_Context->value_family),2);
					on_Syntax_event(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(750,540,28,32,vfh[8],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(750,540,28,32,vfh[8],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x15 :
				/* SelectionResult */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x17 :
				/* FontBar */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			system_font_selector_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			system_font_selector_show(_Context);
			continue;
		case	0x2 :
			system_font_selector_losefocus(_Context);
			_Context->page_number=2;
			_Context->focus_item=23;
			system_font_selector_show(_Context);
			continue;
		case	0x3 :
			system_font_selector_losefocus(_Context);
			if ( _Context->page_number < 2 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			system_font_selector_show(_Context);
			continue;
		case	0x12 :
			system_font_selector_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			system_font_selector_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=system_font_selector_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (SelectionCriteria_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (foundry_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (slant_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (charset_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (wname_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (wcharset_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (wnature_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (setwidth_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (average_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (spacing_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (vresdpi_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (hresdpi_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (points_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (pixels_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (weight_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (family_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (resultname_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (SelectionResult_help(_Context) != 0) { continue; }
						else { break; }
					case	0x16 :
						if (FontList_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3593 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* SelectionCriteria */
					if (visual_event(1) & _MIMO_DOWN) {
						system_font_selector_losefocus(_Context);
						_Context->page_number = 1;
						system_font_selector_show(_Context);
						}
					continue;
				case	0x3 :
					/* Set_Font */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Set_Font=visual_trigger_code(_Context->msg_Set_Font[_Context->language],strlen(_Context->msg_Set_Font[_Context->language]));
						visual_button(50,480,88,32,vfh[2],27,28,_Context->msg_Set_Font[_Context->language],strlen(_Context->msg_Set_Font[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Set_Font=visual_trigger_code(_Context->msg_Set_Font[_Context->language],strlen(_Context->msg_Set_Font[_Context->language]));
	visual_button(50,480,88,32,vfh[2],27,28,_Context->msg_Set_Font[_Context->language],strlen(_Context->msg_Set_Font[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Set_Font_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* foundry */
					continue;
				case	0x5 :
					/* slant */
					continue;
				case	0x6 :
					/* charset */
					continue;
				case	0x7 :
					/* wname */
					continue;
				case	0x8 :
					/* wcharset */
					continue;
				case	0x9 :
					/* wnature */
					continue;
				case	0xa :
					/* setwidth */
					continue;
				case	0xb :
					/* average */
					continue;
				case	0xc :
					/* spacing */
					continue;
				case	0xd :
					/* vresdpi */
					continue;
				case	0xe :
					/* hresdpi */
					continue;
				case	0xf :
					/* points */
					continue;
				case	0x10 :
					/* pixels */
					continue;
				case	0x11 :
					/* weight */
					continue;
				case	0x12 :
					/* family */
					continue;
				case	0x13 :
					/* resultname */
					continue;
				case	0x14 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(750,540,28,32,vfh[8],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(750,540,28,32,vfh[8],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x15 :
					/* SelectionResult */
					if (visual_event(1) & _MIMO_DOWN) {
						system_font_selector_losefocus(_Context);
						_Context->page_number = 2;
						system_font_selector_show(_Context);
						}
					continue;
				case	0x16 :
					/* FontList */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_FontList_event(_Context)) != -1) break;

						}
					continue;
				case	0x17 :
					/* FontBar */
					(void) on_FontBar_action(_Context);
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
				_Context->focus_item=23;
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

public	int	system_font_selector(
	char * presultname)
{
	int	status=0;
	struct system_font_selector_context * _Context=(struct system_font_selector_context*) 0;
	status = system_font_selector_create(
	&_Context,
	 presultname);
	if ( status != 0) return(status);
	status = system_font_selector_show(_Context);
		enter_modal();
	status = system_font_selector_focus(_Context);
		leave_modal();
	status = system_font_selector_hide(_Context);
	status = system_font_selector_remove(
	_Context,
	 presultname);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vsysfont_c */
