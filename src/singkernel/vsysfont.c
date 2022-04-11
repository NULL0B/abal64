
#ifndef _vsysfont_c
#define _vsysfont_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vsysfont.xml  */
/* Target         : vsysfont.c  */
/* Identification : 0.0-1100085406-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "vsysfont.h"
#include "singprot.h"
#define en_Auto1412   "Sing : Version 1.0a"
#define fr_Auto1412   "Sing : Version 1.0a"
#define it_Auto1412   "Sing : Version 1.0a"
#define es_Auto1412   "Sing : Version 1.0a"
#define de_Auto1412   "Sing : Version 1.0a"
#define nl_Auto1412   "Sing : Version 1.0a"
#define pt_Auto1412   "Sing : Version 1.0a"
#define xx_Auto1412   "Sing : Version 1.0a"
#define en_Auto1437   "X/11 System Font Selection"
#define fr_Auto1437   "SÇlection de Fontes Systämes X/11"
#define it_Auto1437   "X/11 System Font Selection"
#define es_Auto1437   "X/11 System Font Selection"
#define de_Auto1437   "X/11 System Font Selection"
#define nl_Auto1437   "X/11 System Font Selection"
#define pt_Auto1437   "X/11 System Font Selection"
#define xx_Auto1437   "X/11 System Font Selection"
#define en_SelectionCriteria   "Selection Criteria"
#define fr_SelectionCriteria   "Critäre de SÇlection"
#define it_SelectionCriteria   "Selection Criteria"
#define es_SelectionCriteria   "Selection Criteria"
#define de_SelectionCriteria   "Selection Criteria"
#define nl_SelectionCriteria   "Selection Criteria"
#define pt_SelectionCriteria   "Selection Criteria"
#define xx_SelectionCriteria   "Selection Criteria"
#define en_Auto1413   "Foundry"
#define fr_Auto1413   "Contributeur"
#define it_Auto1413   "Foundry"
#define es_Auto1413   "Foundry"
#define de_Auto1413   "Foundry"
#define nl_Auto1413   "Foundry"
#define pt_Auto1413   "Foundry"
#define xx_Auto1413   "Foundry"
#define en_Auto1414   "Family"
#define fr_Auto1414   "Famille"
#define it_Auto1414   "Family"
#define es_Auto1414   "Family"
#define de_Auto1414   "Family"
#define nl_Auto1414   "Family"
#define pt_Auto1414   "Family"
#define xx_Auto1414   "Family"
#define en_Auto1415   "Weight"
#define fr_Auto1415   "Graissage"
#define it_Auto1415   "Weight"
#define es_Auto1415   "Weight"
#define de_Auto1415   "Weight"
#define nl_Auto1415   "Weight"
#define pt_Auto1415   "Weight"
#define xx_Auto1415   "Weight"
#define en_Auto1416   "Slant"
#define fr_Auto1416   "PenchÇ"
#define it_Auto1416   "Slant"
#define es_Auto1416   "Slant"
#define de_Auto1416   "Slant"
#define nl_Auto1416   "Slant"
#define pt_Auto1416   "Slant"
#define xx_Auto1416   "Slant"
#define en_Auto1417   "Set Width"
#define fr_Auto1417   "Nature"
#define it_Auto1417   "Set Width"
#define es_Auto1417   "Set Width"
#define de_Auto1417   "Set Width"
#define nl_Auto1417   "Set Width"
#define pt_Auto1417   "Set Width"
#define xx_Auto1417   "Set Width"
#define en_Auto1418   "Pixels"
#define fr_Auto1418   "Pixels"
#define it_Auto1418   "Pixels"
#define es_Auto1418   "Pixels"
#define de_Auto1418   "Pixels"
#define nl_Auto1418   "Pixels"
#define pt_Auto1418   "Pixels"
#define xx_Auto1418   "Pixels"
#define en_Auto1419   "Points (tenths)"
#define fr_Auto1419   "Points (dixiämes)"
#define it_Auto1419   "Points (tenths)"
#define es_Auto1419   "Points (tenths)"
#define de_Auto1419   "Points (tenths)"
#define nl_Auto1419   "Points (tenths)"
#define pt_Auto1419   "Points (tenths)"
#define xx_Auto1419   "Points (tenths)"
#define en_Auto1420   "Horizontal resolution (dpi)"
#define fr_Auto1420   "RÇsolution Horizontale (dpi)"
#define it_Auto1420   "Horizontal resolution (dpi)"
#define es_Auto1420   "Horizontal resolution (dpi)"
#define de_Auto1420   "Horizontal resolution (dpi)"
#define nl_Auto1420   "Horizontal resolution (dpi)"
#define pt_Auto1420   "Horizontal resolution (dpi)"
#define xx_Auto1420   "Horizontal resolution (dpi)"
#define en_Auto1421   "Vertical resolution (dpi)"
#define fr_Auto1421   "RÇsolution Verticale (dpi)"
#define it_Auto1421   "Vertical resolution (dpi)"
#define es_Auto1421   "Vertical resolution (dpi)"
#define de_Auto1421   "Vertical resolution (dpi)"
#define nl_Auto1421   "Vertical resolution (dpi)"
#define pt_Auto1421   "Vertical resolution (dpi)"
#define xx_Auto1421   "Vertical resolution (dpi)"
#define en_Auto1422   "Spacing"
#define fr_Auto1422   "Espacement"
#define it_Auto1422   "Spacing"
#define es_Auto1422   "Spacing"
#define de_Auto1422   "Spacing"
#define nl_Auto1422   "Spacing"
#define pt_Auto1422   "Spacing"
#define xx_Auto1422   "Spacing"
#define en_Auto1423   "Average Width (pixels/10)"
#define fr_Auto1423   "Largeur moyen (pixels/10)"
#define it_Auto1423   "Average Width (pixels/10)"
#define es_Auto1423   "Average Width (pixels/10)"
#define de_Auto1423   "Average Width (pixels/10)"
#define nl_Auto1423   "Average Width (pixels/10)"
#define pt_Auto1423   "Average Width (pixels/10)"
#define xx_Auto1423   "Average Width (pixels/10)"
#define en_Auto1424   "Character Set"
#define fr_Auto1424   "Jeu de caractäres"
#define it_Auto1424   "Character Set"
#define es_Auto1424   "Character Set"
#define de_Auto1424   "Character Set"
#define nl_Auto1424   "Character Set"
#define pt_Auto1424   "Character Set"
#define xx_Auto1424   "Character Set"
#define en_Auto1453   "X/11 Font Name Selection String"
#define fr_Auto1453   "Syntaxe de sÇlection de fontes X/11"
#define it_Auto1453   "X/11 Font Name Selection String"
#define es_Auto1453   "X/11 Font Name Selection String"
#define de_Auto1453   "X/11 Font Name Selection String"
#define nl_Auto1453   "X/11 Font Name Selection String"
#define pt_Auto1453   "X/11 Font Name Selection String"
#define xx_Auto1453   "X/11 Font Name Selection String"
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
#define en_setwidth   "any|normal|condensed|narrow|doublewidth"
#define fr_setwidth   "tout|normal|condensed|narrow|doublewidth"
#define it_setwidth   "any|normal|condensed|narrow|doublewidth"
#define es_setwidth   "any|normal|condensed|narrow|doublewidth"
#define de_setwidth   "any|normal|condensed|narrow|doublewidth"
#define nl_setwidth   "any|normal|condensed|narrow|doublewidth"
#define pt_setwidth   "any|normal|condensed|narrow|doublewidth"
#define xx_setwidth   "any|normal|condensed|narrow|doublewidth"
#define en_average   ""
#define en_spacing   "any|fixed|proportional"
#define fr_spacing   "tout|fixed|proportional"
#define it_spacing   "any|fixed|proportional"
#define es_spacing   "any|fixed|proportional"
#define de_spacing   "any|fixed|proportional"
#define nl_spacing   "any|fixed|proportional"
#define pt_spacing   "any|fixed|proportional"
#define xx_spacing   "any|fixed|proportional"
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
#define en_resultname   ""
#define en_Accept   "<-"
#define fr_Accept   "<-"
#define it_Accept   "<-"
#define es_Accept   "<-"
#define de_Accept   "<-"
#define nl_Accept   "<-"
#define pt_Accept   "<-"
#define xx_Accept   "<-"
#define en_SelectionResult   "Selection Result"
#define fr_SelectionResult   "RÇsultat de SÇlection"
#define it_SelectionResult   "Selection Result"
#define es_SelectionResult   "Selection Result"
#define de_SelectionResult   "Selection Result"
#define nl_SelectionResult   "Selection Result"
#define pt_SelectionResult   "Selection Result"
#define xx_SelectionResult   "Selection Result"
#define en_FontList   "System Font Name"
#define fr_FontList   "Nom de Fonte Systäme"
#define it_FontList   "System Font Name"
#define es_FontList   "System Font Name"
#define de_FontList   "System Font Name"
#define nl_FontList   "System Font Name"
#define pt_FontList   "System Font Name"
#define xx_FontList   "System Font Name"
#define en_FontBar   ""
static int	vfh[10];

private struct system_font_selector_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[2+1];
	char * msg_Auto1412[8];
	int	x_Auto1412;
	int	y_Auto1412;
	int	w_Auto1412;
	int	h_Auto1412;
	char * msg_Auto1437[8];
	char * msg_SelectionCriteria[8];
	int	trigger_SelectionCriteria;
	int	page_number;
	char * msg_Auto1413[8];
	char * msg_Auto1414[8];
	char * msg_Auto1415[8];
	char * msg_Auto1416[8];
	char * msg_Auto1417[8];
	char * msg_Auto1418[8];
	char * msg_Auto1419[8];
	char * msg_Auto1420[8];
	char * msg_Auto1421[8];
	char * msg_Auto1422[8];
	char * msg_Auto1423[8];
	char * msg_Auto1424[8];
	char * msg_Auto1453[8];
	char	buffer_foundry[62];
	char * msg_slant[8];
	int	value_slant;
	char	buffer_charset[62];
	char * msg_setwidth[8];
	int	value_setwidth;
	char	buffer_average[16];
	char * msg_spacing[8];
	int	value_spacing;
	char * msg_vresdpi[8];
	int	value_vresdpi;
	char * msg_hresdpi[8];
	int	value_hresdpi;
	char	buffer_points[16];
	char	buffer_pixels[16];
	char * msg_weight[8];
	int	value_weight;
	char * msg_family[8];
	int	value_family;
	char	buffer_Syntax[705];
	char	buffer_resultname[91];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_SelectionResult[8];
	int	trigger_SelectionResult;
	char * msg_FontList[8];
	int	value_FontList;
	int	column_FontList;
	char	buffer_FontList[25][91];
	char * row_FontList;
	int	value_FontBar;
	int	limit_FontBar;
	int	max_FontBar;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static short	notwhite(struct system_font_selector_context * _Context,char * bptr, int blen);

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
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct system_font_selector_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=19;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_resultname, 90, presultname);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto1412[i]=" ";
	_Context->msg_Auto1412[0]=en_Auto1412;
	_Context->msg_Auto1412[1]=fr_Auto1412;
	_Context->msg_Auto1412[2]=it_Auto1412;
	_Context->msg_Auto1412[3]=es_Auto1412;
	_Context->msg_Auto1412[4]=de_Auto1412;
	_Context->msg_Auto1412[5]=nl_Auto1412;
	_Context->msg_Auto1412[6]=pt_Auto1412;
	_Context->msg_Auto1412[7]=xx_Auto1412;
	_Context->x_Auto1412=0;
	_Context->y_Auto1412=0;
	_Context->w_Auto1412=790;
	_Context->h_Auto1412=590;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1437[i]=" ";
	_Context->msg_Auto1437[0]=en_Auto1437;
	_Context->msg_Auto1437[1]=fr_Auto1437;
	_Context->msg_Auto1437[2]=it_Auto1437;
	_Context->msg_Auto1437[3]=es_Auto1437;
	_Context->msg_Auto1437[4]=de_Auto1437;
	_Context->msg_Auto1437[5]=nl_Auto1437;
	_Context->msg_Auto1437[6]=pt_Auto1437;
	_Context->msg_Auto1437[7]=xx_Auto1437;
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
	for (i=0; i < 8; i++)_Context->msg_Auto1413[i]=" ";
	_Context->msg_Auto1413[0]=en_Auto1413;
	_Context->msg_Auto1413[1]=fr_Auto1413;
	_Context->msg_Auto1413[2]=it_Auto1413;
	_Context->msg_Auto1413[3]=es_Auto1413;
	_Context->msg_Auto1413[4]=de_Auto1413;
	_Context->msg_Auto1413[5]=nl_Auto1413;
	_Context->msg_Auto1413[6]=pt_Auto1413;
	_Context->msg_Auto1413[7]=xx_Auto1413;
	for (i=0; i < 8; i++)_Context->msg_Auto1414[i]=" ";
	_Context->msg_Auto1414[0]=en_Auto1414;
	_Context->msg_Auto1414[1]=fr_Auto1414;
	_Context->msg_Auto1414[2]=it_Auto1414;
	_Context->msg_Auto1414[3]=es_Auto1414;
	_Context->msg_Auto1414[4]=de_Auto1414;
	_Context->msg_Auto1414[5]=nl_Auto1414;
	_Context->msg_Auto1414[6]=pt_Auto1414;
	_Context->msg_Auto1414[7]=xx_Auto1414;
	for (i=0; i < 8; i++)_Context->msg_Auto1415[i]=" ";
	_Context->msg_Auto1415[0]=en_Auto1415;
	_Context->msg_Auto1415[1]=fr_Auto1415;
	_Context->msg_Auto1415[2]=it_Auto1415;
	_Context->msg_Auto1415[3]=es_Auto1415;
	_Context->msg_Auto1415[4]=de_Auto1415;
	_Context->msg_Auto1415[5]=nl_Auto1415;
	_Context->msg_Auto1415[6]=pt_Auto1415;
	_Context->msg_Auto1415[7]=xx_Auto1415;
	for (i=0; i < 8; i++)_Context->msg_Auto1416[i]=" ";
	_Context->msg_Auto1416[0]=en_Auto1416;
	_Context->msg_Auto1416[1]=fr_Auto1416;
	_Context->msg_Auto1416[2]=it_Auto1416;
	_Context->msg_Auto1416[3]=es_Auto1416;
	_Context->msg_Auto1416[4]=de_Auto1416;
	_Context->msg_Auto1416[5]=nl_Auto1416;
	_Context->msg_Auto1416[6]=pt_Auto1416;
	_Context->msg_Auto1416[7]=xx_Auto1416;
	for (i=0; i < 8; i++)_Context->msg_Auto1417[i]=" ";
	_Context->msg_Auto1417[0]=en_Auto1417;
	_Context->msg_Auto1417[1]=fr_Auto1417;
	_Context->msg_Auto1417[2]=it_Auto1417;
	_Context->msg_Auto1417[3]=es_Auto1417;
	_Context->msg_Auto1417[4]=de_Auto1417;
	_Context->msg_Auto1417[5]=nl_Auto1417;
	_Context->msg_Auto1417[6]=pt_Auto1417;
	_Context->msg_Auto1417[7]=xx_Auto1417;
	for (i=0; i < 8; i++)_Context->msg_Auto1418[i]=" ";
	_Context->msg_Auto1418[0]=en_Auto1418;
	_Context->msg_Auto1418[1]=fr_Auto1418;
	_Context->msg_Auto1418[2]=it_Auto1418;
	_Context->msg_Auto1418[3]=es_Auto1418;
	_Context->msg_Auto1418[4]=de_Auto1418;
	_Context->msg_Auto1418[5]=nl_Auto1418;
	_Context->msg_Auto1418[6]=pt_Auto1418;
	_Context->msg_Auto1418[7]=xx_Auto1418;
	for (i=0; i < 8; i++)_Context->msg_Auto1419[i]=" ";
	_Context->msg_Auto1419[0]=en_Auto1419;
	_Context->msg_Auto1419[1]=fr_Auto1419;
	_Context->msg_Auto1419[2]=it_Auto1419;
	_Context->msg_Auto1419[3]=es_Auto1419;
	_Context->msg_Auto1419[4]=de_Auto1419;
	_Context->msg_Auto1419[5]=nl_Auto1419;
	_Context->msg_Auto1419[6]=pt_Auto1419;
	_Context->msg_Auto1419[7]=xx_Auto1419;
	for (i=0; i < 8; i++)_Context->msg_Auto1420[i]=" ";
	_Context->msg_Auto1420[0]=en_Auto1420;
	_Context->msg_Auto1420[1]=fr_Auto1420;
	_Context->msg_Auto1420[2]=it_Auto1420;
	_Context->msg_Auto1420[3]=es_Auto1420;
	_Context->msg_Auto1420[4]=de_Auto1420;
	_Context->msg_Auto1420[5]=nl_Auto1420;
	_Context->msg_Auto1420[6]=pt_Auto1420;
	_Context->msg_Auto1420[7]=xx_Auto1420;
	for (i=0; i < 8; i++)_Context->msg_Auto1421[i]=" ";
	_Context->msg_Auto1421[0]=en_Auto1421;
	_Context->msg_Auto1421[1]=fr_Auto1421;
	_Context->msg_Auto1421[2]=it_Auto1421;
	_Context->msg_Auto1421[3]=es_Auto1421;
	_Context->msg_Auto1421[4]=de_Auto1421;
	_Context->msg_Auto1421[5]=nl_Auto1421;
	_Context->msg_Auto1421[6]=pt_Auto1421;
	_Context->msg_Auto1421[7]=xx_Auto1421;
	for (i=0; i < 8; i++)_Context->msg_Auto1422[i]=" ";
	_Context->msg_Auto1422[0]=en_Auto1422;
	_Context->msg_Auto1422[1]=fr_Auto1422;
	_Context->msg_Auto1422[2]=it_Auto1422;
	_Context->msg_Auto1422[3]=es_Auto1422;
	_Context->msg_Auto1422[4]=de_Auto1422;
	_Context->msg_Auto1422[5]=nl_Auto1422;
	_Context->msg_Auto1422[6]=pt_Auto1422;
	_Context->msg_Auto1422[7]=xx_Auto1422;
	for (i=0; i < 8; i++)_Context->msg_Auto1423[i]=" ";
	_Context->msg_Auto1423[0]=en_Auto1423;
	_Context->msg_Auto1423[1]=fr_Auto1423;
	_Context->msg_Auto1423[2]=it_Auto1423;
	_Context->msg_Auto1423[3]=es_Auto1423;
	_Context->msg_Auto1423[4]=de_Auto1423;
	_Context->msg_Auto1423[5]=nl_Auto1423;
	_Context->msg_Auto1423[6]=pt_Auto1423;
	_Context->msg_Auto1423[7]=xx_Auto1423;
	for (i=0; i < 8; i++)_Context->msg_Auto1424[i]=" ";
	_Context->msg_Auto1424[0]=en_Auto1424;
	_Context->msg_Auto1424[1]=fr_Auto1424;
	_Context->msg_Auto1424[2]=it_Auto1424;
	_Context->msg_Auto1424[3]=es_Auto1424;
	_Context->msg_Auto1424[4]=de_Auto1424;
	_Context->msg_Auto1424[5]=nl_Auto1424;
	_Context->msg_Auto1424[6]=pt_Auto1424;
	_Context->msg_Auto1424[7]=xx_Auto1424;
	for (i=0; i < 8; i++)_Context->msg_Auto1453[i]=" ";
	_Context->msg_Auto1453[0]=en_Auto1453;
	_Context->msg_Auto1453[1]=fr_Auto1453;
	_Context->msg_Auto1453[2]=it_Auto1453;
	_Context->msg_Auto1453[3]=es_Auto1453;
	_Context->msg_Auto1453[4]=de_Auto1453;
	_Context->msg_Auto1453[5]=nl_Auto1453;
	_Context->msg_Auto1453[6]=pt_Auto1453;
	_Context->msg_Auto1453[7]=xx_Auto1453;
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
	(void) on_Syntax_create(_Context);
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
	_Context->focus_pages[2]=17;
	for (i=0; i < 8; i++)_Context->msg_FontList[i]=" ";
	_Context->msg_FontList[0]=en_FontList;
	_Context->msg_FontList[1]=fr_FontList;
	_Context->msg_FontList[2]=it_FontList;
	_Context->msg_FontList[3]=es_FontList;
	_Context->msg_FontList[4]=de_FontList;
	_Context->msg_FontList[5]=nl_FontList;
	_Context->msg_FontList[6]=pt_FontList;
	_Context->msg_FontList[7]=xx_FontList;
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

public	int	system_font_selector_remove(
	struct system_font_selector_context * _Context,
	char * presultname)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	SysFontMem.family=_Context->value_family;
	SysFontMem.weight=_Context->value_weight;
	SysFontMem.pixels=atoi(_Context->buffer_pixels);
	SysFontMem.points=atoi(_Context->buffer_points);
	SysFontMem.hresdpi=_Context->value_hresdpi;
	SysFontMem.vresdpi=_Context->value_vresdpi;
	SysFontMem.spacing=_Context->value_spacing;
	SysFontMem.average=atoi(_Context->buffer_average);
	SysFontMem.setwidth=_Context->value_setwidth;
	(void) on_charset_remove(_Context);
	SysFontMem.slant=_Context->value_slant;
	(void) on_foundry_remove(_Context);
	dropsysfontlist();
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_resultname, 90, presultname);
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
	char*rptr;
	char**sptr=(char**)0;
	char*nptr;
	if((_Context->max_FontBar=getsysfontlist(&sptr,_Context->buffer_Syntax,704))!=0){
	for(i=1;i<=25;i++){
	if ( i > 0 ) { _Context->row_FontList=&_Context->buffer_FontList[i-1][0]; } ;
	rptr=(_Context->row_FontList+0);
	if((n=((i-1)+_Context->value_FontBar))<_Context->max_FontBar){
	if((nptr=*(sptr+n))!=(char*)0){
	for(x=0;x<91;x++){
	if(!(*nptr))
	*(rptr+x)=' ';
	else*(rptr+x)=*(nptr++);
	}
	}
	}
	}
	}
		visual_table(20,110,730+2,420+2,vfh[1],16,0,_Context->msg_FontList[_Context->language],_Context->buffer_FontList,0x4401,"($)");
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
	visual_window(0,0,790,590,vfh[2],_Context->msg_Auto1412[_Context->language],strlen(_Context->msg_Auto1412[_Context->language]),0x407);
	visual_text(10,30,768,29,vfh[5],16,0,_Context->msg_Auto1437[_Context->language],strlen(_Context->msg_Auto1437[_Context->language]),1283);
	if (_Context->page_number == 1 ) {
	_Context->trigger_SelectionCriteria=visual_trigger_code(_Context->msg_SelectionCriteria[_Context->language],strlen(_Context->msg_SelectionCriteria[_Context->language]));
	visual_tabpage(10,70,770,470,vfh[2],_Context->msg_SelectionCriteria[_Context->language],strlen(_Context->msg_SelectionCriteria[_Context->language]),0,2);
	} else {
		visual_tabpage(10,70,770,470,vfh[2],_Context->msg_SelectionCriteria[_Context->language],strlen(_Context->msg_SelectionCriteria[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,110,180,20,vfh[2],16,0,_Context->msg_Auto1413[_Context->language],strlen(_Context->msg_Auto1413[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,140,168,17,vfh[2],16,0,_Context->msg_Auto1414[_Context->language],strlen(_Context->msg_Auto1414[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,170,168,17,vfh[2],16,0,_Context->msg_Auto1415[_Context->language],strlen(_Context->msg_Auto1415[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(420,170,168,17,vfh[2],16,0,_Context->msg_Auto1416[_Context->language],strlen(_Context->msg_Auto1416[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,200,168,17,vfh[2],16,0,_Context->msg_Auto1417[_Context->language],strlen(_Context->msg_Auto1417[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,230,210,17,vfh[2],16,0,_Context->msg_Auto1418[_Context->language],strlen(_Context->msg_Auto1418[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(420,230,210,17,vfh[2],16,0,_Context->msg_Auto1419[_Context->language],strlen(_Context->msg_Auto1419[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,260,196,17,vfh[2],16,0,_Context->msg_Auto1420[_Context->language],strlen(_Context->msg_Auto1420[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(420,260,210,17,vfh[2],16,0,_Context->msg_Auto1421[_Context->language],strlen(_Context->msg_Auto1421[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,290,210,17,vfh[2],16,0,_Context->msg_Auto1422[_Context->language],strlen(_Context->msg_Auto1422[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(420,290,182,17,vfh[2],16,0,_Context->msg_Auto1423[_Context->language],strlen(_Context->msg_Auto1423[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,320,182,17,vfh[2],16,0,_Context->msg_Auto1424[_Context->language],strlen(_Context->msg_Auto1424[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(50,360,700,17,vfh[2],16,0,_Context->msg_Auto1453[_Context->language],strlen(_Context->msg_Auto1453[_Context->language]),1282);
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
	visual_frame(50,370,704+2,128+2,5);
	visual_text(50+1,370+1,704,128,vfh[1],16,0,_Context->buffer_Syntax,704,0);
		}
	visual_frame(20,554,720+2,16+2,5);
	visual_text(20+1,554+1,720,16,vfh[1],0,0,_Context->buffer_resultname,90,0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(750,550,20,24,vfh[8],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	if (_Context->page_number == 2 ) {
	_Context->trigger_SelectionResult=visual_trigger_code(_Context->msg_SelectionResult[_Context->language],strlen(_Context->msg_SelectionResult[_Context->language]));
	visual_tabpage(10,70,770,470,vfh[2],_Context->msg_SelectionResult[_Context->language],strlen(_Context->msg_SelectionResult[_Context->language]),145,2);
	} else {
		visual_tabpage(10,70,770,470,vfh[2],_Context->msg_SelectionResult[_Context->language],strlen(_Context->msg_SelectionResult[_Context->language]),145,0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_FontList_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	visual_scrollbar(750,110,20,420,vfh[1],16,0,_Context->value_FontBar,_Context->limit_FontBar,_Context->max_FontBar,3);
		}
	visual_thaw(0,0,790,590);
	visual_thaw(0,0,790,590);

	return(0);
}
private int on_Syntax_event(struct system_font_selector_context * _Context) {
	on_Syntax_create(_Context);
	visual_frame(50,370,704+2,128+2,5);
visual_text(50+1,370+1,704,128,vfh[1],16,0,_Context->buffer_Syntax,704,0);
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
	for(i=0;i<(90-1);i++){
	if(i<91)
	*(_Context->buffer_resultname+(i+1))=*((_Context->row_FontList+0)+i);
	else*(_Context->buffer_resultname+(i+1))=" ";
	}
	visual_frame(20,554,720+2,16+2,5);
visual_text(20+1,554+1,720,16,vfh[1],0,0,_Context->buffer_resultname,90,0);
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
		if (_Context->value_FontBar > (_Context->max_FontBar-_Context->limit_FontBar)) 
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
			if (_Context->value_FontBar > (_Context->max_FontBar-_Context->limit_FontBar)) 
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
		if (_Context->trigger_Accept == mb ) return(16);
		if (_Context->trigger_SelectionResult == mb ) return(17);
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
		return(1);	/* Auto1412 */

		}
	if ((mx >= 753 )  
	&&  (my >= 4 )  
	&&  (mx <= 769 )  
	&&  (my <= 20 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vsysfont.htm");
			};
		return(-1);	/* Auto1412 */

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
		return(-1);	/* Auto1412 */

		}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 10 ) 
		&&  (my >= 70 ) 
		&&  (mx <= 154 ) 
		&&  (my <= 94 )) {
			return(2); /* SelectionCriteria */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 260 ) 
		&&  ( my >= 110 ) 
		&&  ( mx <= 748 ) 
		&&  ( my <= 126 )) {
			return(3); /* foundry */
			}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 630 ) 
		&&  (my >= 170 ) 
		&&  (mx <= 750 ) 
		&&  (my <= 186 )) {
			return(4); /* slant */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 260 ) 
		&&  ( my >= 320 ) 
		&&  ( mx <= 748 ) 
		&&  ( my <= 336 )) {
			return(5); /* charset */
			}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 260 ) 
		&&  (my >= 200 ) 
		&&  (mx <= 380 ) 
		&&  (my <= 216 )) {
			return(6); /* setwidth */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 630 ) 
		&&  ( my >= 290 ) 
		&&  ( mx <= 750 ) 
		&&  ( my <= 306 )) {
			return(7); /* average */
			}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 260 ) 
		&&  (my >= 290 ) 
		&&  (mx <= 380 ) 
		&&  (my <= 306 )) {
			return(8); /* spacing */
			}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 630 ) 
		&&  (my >= 260 ) 
		&&  (mx <= 750 ) 
		&&  (my <= 276 )) {
			return(9); /* vresdpi */
			}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 260 ) 
		&&  (my >= 260 ) 
		&&  (mx <= 380 ) 
		&&  (my <= 276 )) {
			return(10); /* hresdpi */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 630 ) 
		&&  ( my >= 230 ) 
		&&  ( mx <= 750 ) 
		&&  ( my <= 246 )) {
			return(11); /* points */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 260 ) 
		&&  ( my >= 230 ) 
		&&  ( mx <= 380 ) 
		&&  ( my <= 246 )) {
			return(12); /* pixels */
			}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 260 ) 
		&&  (my >= 170 ) 
		&&  (mx <= 380 ) 
		&&  (my <= 186 )) {
			return(13); /* weight */
			}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 260 ) 
		&&  (my >= 140 ) 
		&&  (mx <= 748 ) 
		&&  (my <= 156 )) {
			return(14); /* family */
			}
		}
	if (( mx >= 20 ) 
	&&  ( my >= 554 ) 
	&&  ( mx <= 740 ) 
	&&  ( my <= 570 )) {
		return(15); /* resultname */
		}
	if (( mx >= 750 ) 
	&&  ( my >= 550 ) 
	&&  ( mx <= 770 ) 
	&&  ( my <= 574 )) {
		return(16); /* Accept */
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 155 ) 
		&&  (my >= 70 ) 
		&&  (mx <= 308 ) 
		&&  (my <= 94 )) {
			return(17); /* SelectionResult */
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
			if ( _Context->column_FontList < 729 ) {
				_Context->column_FontList = 1;
				}
			return(18); /* FontList */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 750 ) 
		&&  ( my >= 110 ) 
		&&  ( mx <= 770 ) 
		&&  ( my <= 530 )) {
			return(19); /* FontBar */
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
				/* foundry */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(260+1,110+1,488,16,vfh[1],_Context->buffer_foundry,61);
					on_Syntax_event(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* slant */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(630,170,120,64,vfh[1],16,0,parse_selection(_Context->msg_slant[_Context->language],&_Context->value_slant),2);
					on_Syntax_event(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* charset */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(260+1,320+1,488,16,vfh[1],_Context->buffer_charset,61);
					on_Syntax_event(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* setwidth */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(260,200,120,64,vfh[1],16,0,parse_selection(_Context->msg_setwidth[_Context->language],&_Context->value_setwidth),2);
					on_Syntax_event(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* average */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(630+1,290+1,120,16,vfh[1],_Context->buffer_average,15);
					on_Syntax_event(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* spacing */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(260,290,120,80,vfh[1],16,0,parse_selection(_Context->msg_spacing[_Context->language],&_Context->value_spacing),2);
					on_Syntax_event(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* vresdpi */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(630,260,120,96,vfh[1],16,0,parse_selection(_Context->msg_vresdpi[_Context->language],&_Context->value_vresdpi),2);
					on_Syntax_event(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* hresdpi */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(260,260,120,112,vfh[1],16,0,parse_selection(_Context->msg_hresdpi[_Context->language],&_Context->value_hresdpi),2);
					on_Syntax_event(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* points */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(630+1,230+1,120,16,vfh[1],_Context->buffer_points,15);
					on_Syntax_event(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* pixels */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(260+1,230+1,120,16,vfh[1],_Context->buffer_pixels,15);
					on_Syntax_event(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* weight */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(260,170,120,64,vfh[1],16,0,parse_selection(_Context->msg_weight[_Context->language],&_Context->value_weight),2);
					on_Syntax_event(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* family */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(260,140,488,128,vfh[1],16,0,parse_selection(_Context->msg_family[_Context->language],&_Context->value_family),2);
					on_Syntax_event(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* Accept */
				visual_button(750,550,20,24,vfh[8],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(750,550,20,24,vfh[8],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x11 :
				/* SelectionResult */
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
			_Context->focus_item=19;
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
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1412 */
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
						/* foundry */
						continue;
					case	0x4 :
						/* slant */
						continue;
					case	0x5 :
						/* charset */
						continue;
					case	0x6 :
						/* setwidth */
						continue;
					case	0x7 :
						/* average */
						continue;
					case	0x8 :
						/* spacing */
						continue;
					case	0x9 :
						/* vresdpi */
						continue;
					case	0xa :
						/* hresdpi */
						continue;
					case	0xb :
						/* points */
						continue;
					case	0xc :
						/* pixels */
						continue;
					case	0xd :
						/* weight */
						continue;
					case	0xe :
						/* family */
						continue;
					case	0xf :
						/* resultname */
						continue;
					case	0x10 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(750,550,20,24,vfh[8],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(750,550,20,24,vfh[8],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x11 :
						/* SelectionResult */
						if (visual_event(1) & _MIMO_DOWN) {
							system_font_selector_losefocus(_Context);
							_Context->page_number = 2;
							system_font_selector_show(_Context);
							}
						continue;
					case	0x12 :
						/* FontList */
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_FontList_event(_Context)) != -1) break;

							}
						continue;
					case	0x13 :
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
				_Context->focus_item=19;
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
