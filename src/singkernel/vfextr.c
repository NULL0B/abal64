
#ifndef _vfextr_c
#define _vfextr_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vfextr.xml  */
/* Target         : vfextr.c  */
/* Identification : 0.0-1100085378-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto4568   "Sing : Version 1.0a"
#define fr_Auto4568   "Sing : Version 1.0a"
#define en_Auto4822   "skin.gif"
#define fr_Auto4822   "skin.gif"
#define en_Accept   "Accept"
#define fr_Accept   "&Valider"
#define en_Cancel   "Cancel"
#define fr_Cancel   "&Annuler"
#define en_Auto4569   "Extraction of Characters"
#define fr_Auto4569   "Extraction de Caract�res"
#define it_Auto4569   "Extraction of Characters"
#define es_Auto4569   "Extraction of Characters"
#define de_Auto4569   "Extraction of Characters"
#define nl_Auto4569   "Extraction of Characters"
#define pt_Auto4569   "Extraction of Characters"
#define xx_Auto4569   "Extraction of Characters"
#define en_Auto4570   "Source Font"
#define fr_Auto4570   "Fonte Source"
#define it_Auto4570   "Source Font"
#define es_Auto4570   "Source Font"
#define de_Auto4570   "Source Font"
#define nl_Auto4570   "Source Font"
#define pt_Auto4570   "Source Font"
#define xx_Auto4570   "Source Font"
#define en_GroupOne   "Range 21H to 2Fh : punctuation group 1"
#define fr_GroupOne   "De 21H � 2Fh : punctuation groupe 1"
#define it_GroupOne   "Range 21H to 2Fh : punctuation group 1"
#define es_GroupOne   "Range 21H to 2Fh : punctuation group 1"
#define de_GroupOne   "Range 21H to 2Fh : punctuation group 1"
#define nl_GroupOne   "Range 21H to 2Fh : punctuation group 1"
#define pt_GroupOne   "Range 21H to 2Fh : punctuation group 1"
#define xx_GroupOne   "Range 21H to 2Fh : punctuation group 1"
#define en_Auto4622   "Digits"
#define fr_Auto4622   "Chiffres"
#define it_Auto4622   "Digits"
#define es_Auto4622   "Digits"
#define de_Auto4622   "Digits"
#define nl_Auto4622   "Digits"
#define pt_Auto4622   "Digits"
#define xx_Auto4622   "Digits"
#define en_GroupTwo   "Range 3Ah to 40h : punctuation group 2"
#define fr_GroupTwo   "De 3Ah � 40h : punctuation groupe 2"
#define it_GroupTwo   "Range 3Ah to 40h : punctuation group 2"
#define es_GroupTwo   "Range 3Ah to 40h : punctuation group 2"
#define de_GroupTwo   "Range 3Ah to 40h : punctuation group 2"
#define nl_GroupTwo   "Range 3Ah to 40h : punctuation group 2"
#define pt_GroupTwo   "Range 3Ah to 40h : punctuation group 2"
#define xx_GroupTwo   "Range 3Ah to 40h : punctuation group 2"
#define en_Auto4623   "Uppercase Alphabet"
#define fr_Auto4623   "Majescules"
#define it_Auto4623   "Uppercase Alphabet"
#define es_Auto4623   "Uppercase Alphabet"
#define de_Auto4623   "Uppercase Alphabet"
#define nl_Auto4623   "Uppercase Alphabet"
#define pt_Auto4623   "Uppercase Alphabet"
#define xx_Auto4623   "Uppercase Alphabet"
#define en_GroupThree   "Range 5Bh to 60h : symbols group 1"
#define fr_GroupThree   "De 5Bh � 60h : symboles groupe 1"
#define it_GroupThree   "Range 5Bh to 60h : symbols group 1"
#define es_GroupThree   "Range 5Bh to 60h : symbols group 1"
#define de_GroupThree   "Range 5Bh to 60h : symbols group 1"
#define nl_GroupThree   "Range 5Bh to 60h : symbols group 1"
#define pt_GroupThree   "Range 5Bh to 60h : symbols group 1"
#define xx_GroupThree   "Range 5Bh to 60h : symbols group 1"
#define en_Auto4624   "Lowercase Alphabet"
#define fr_Auto4624   "Minescules"
#define it_Auto4624   "Lowercase Alphabet"
#define es_Auto4624   "Lowercase Alphabet"
#define de_Auto4624   "Lowercase Alphabet"
#define nl_Auto4624   "Lowercase Alphabet"
#define pt_Auto4624   "Lowercase Alphabet"
#define xx_Auto4624   "Lowercase Alphabet"
#define en_GroupFour   "Range 7Bh to 7Fh : symbols group 2"
#define fr_GroupFour   "De 7Bh � 7Fh : symboles groupe 2"
#define it_GroupFour   "Range 7Bh to 7Fh : symbols group 2"
#define es_GroupFour   "Range 7Bh to 7Fh : symbols group 2"
#define de_GroupFour   "Range 7Bh to 7Fh : symbols group 2"
#define nl_GroupFour   "Range 7Bh to 7Fh : symbols group 2"
#define pt_GroupFour   "Range 7Bh to 7Fh : symbols group 2"
#define xx_GroupFour   "Range 7Bh to 7Fh : symbols group 2"
#define en_Auto4625   "International Accented characters"
#define fr_Auto4625   "Caract�res accentu�es internationales"
#define it_Auto4625   "International Accented characters"
#define es_Auto4625   "International Accented characters"
#define de_Auto4625   "International Accented characters"
#define nl_Auto4625   "International Accented characters"
#define pt_Auto4625   "International Accented characters"
#define xx_Auto4625   "International Accented characters"
#define en_GroupFive   "Range 9Bh to 9Fh : symbols group 3"
#define fr_GroupFive   "De 9Bh � 9Fh : symboles groupe 3"
#define it_GroupFive   "Range 9Bh to 9Fh : symbols group 3"
#define es_GroupFive   "Range 9Bh to 9Fh : symbols group 3"
#define de_GroupFive   "Range 9Bh to 9Fh : symbols group 3"
#define nl_GroupFive   "Range 9Bh to 9Fh : symbols group 3"
#define pt_GroupFive   "Range 9Bh to 9Fh : symbols group 3"
#define xx_GroupFive   "Range 9Bh to 9Fh : symbols group 3"
#define en_Recalc   "Recalculate proportions"
#define fr_Recalc   "Recalculer proportions"
#define it_Recalc   "Recalculate proportions"
#define es_Recalc   "Recalculate proportions"
#define de_Recalc   "Recalculate proportions"
#define nl_Recalc   "Recalculate proportions"
#define pt_Recalc   "Recalculate proportions"
#define xx_Recalc   "Recalculate proportions"
static int	vfh[10];

private struct accept_extraction_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto4568[8];
	int	x_Auto4568;
	int	y_Auto4568;
	int	w_Auto4568;
	int	h_Auto4568;
	char * msg_Auto4822[8];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_Auto4569[8];
	char * msg_Auto4570[8];
	char * msg_SourceFont[8];
	int	value_SourceFont;
	char * msg_GroupOne[8];
	int	trigger_GroupOne;
	int	value_GroupOne;
	char * msg_Auto4622[8];
	int	trigger_Auto4622;
	int	value_Auto4622;
	char * msg_GroupTwo[8];
	int	trigger_GroupTwo;
	int	value_GroupTwo;
	char * msg_Auto4623[8];
	int	trigger_Auto4623;
	int	value_Auto4623;
	char * msg_GroupThree[8];
	int	trigger_GroupThree;
	int	value_GroupThree;
	char * msg_Auto4624[8];
	int	trigger_Auto4624;
	int	value_Auto4624;
	char * msg_GroupFour[8];
	int	trigger_GroupFour;
	int	value_GroupFour;
	char * msg_Auto4625[8];
	int	trigger_Auto4625;
	int	value_Auto4625;
	char * msg_GroupFive[8];
	int	trigger_GroupFive;
	int	value_GroupFive;
	char * msg_Recalc[8];
	int	trigger_Recalc;
	int	value_Recalc;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[12];
	};

public	int	accept_extraction_create(
	struct accept_extraction_context ** cptr,
	char * pSourceFont,
	char * pGroupOne,
	char * pAuto4622,
	char * pGroupTwo,
	char * pAuto4623,
	char * pGroupThree,
	char * pAuto4624,
	char * pGroupFour,
	char * pAuto4625,
	char * pGroupFive,
	char * pRecalc)
{

	int i;
	struct accept_extraction_context * _Context=(struct accept_extraction_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_extraction_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=14;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pSourceFont);
		if (!( pSourceFont )) _Context->value_SourceFont=0;
		else	_Context->value_SourceFont = *((int *)pSourceFont);
		visual_transferin((void *) 0, 0, pGroupOne);
		if (!( pGroupOne )) _Context->value_GroupOne=0;
		else	_Context->value_GroupOne = *((int *)pGroupOne);
		visual_transferin((void *) 0, 0, pAuto4622);
		if (!( pAuto4622 )) _Context->value_Auto4622=0;
		else	_Context->value_Auto4622 = *((int *)pAuto4622);
		visual_transferin((void *) 0, 0, pGroupTwo);
		if (!( pGroupTwo )) _Context->value_GroupTwo=0;
		else	_Context->value_GroupTwo = *((int *)pGroupTwo);
		visual_transferin((void *) 0, 0, pAuto4623);
		if (!( pAuto4623 )) _Context->value_Auto4623=0;
		else	_Context->value_Auto4623 = *((int *)pAuto4623);
		visual_transferin((void *) 0, 0, pGroupThree);
		if (!( pGroupThree )) _Context->value_GroupThree=0;
		else	_Context->value_GroupThree = *((int *)pGroupThree);
		visual_transferin((void *) 0, 0, pAuto4624);
		if (!( pAuto4624 )) _Context->value_Auto4624=0;
		else	_Context->value_Auto4624 = *((int *)pAuto4624);
		visual_transferin((void *) 0, 0, pGroupFour);
		if (!( pGroupFour )) _Context->value_GroupFour=0;
		else	_Context->value_GroupFour = *((int *)pGroupFour);
		visual_transferin((void *) 0, 0, pAuto4625);
		if (!( pAuto4625 )) _Context->value_Auto4625=0;
		else	_Context->value_Auto4625 = *((int *)pAuto4625);
		visual_transferin((void *) 0, 0, pGroupFive);
		if (!( pGroupFive )) _Context->value_GroupFive=0;
		else	_Context->value_GroupFive = *((int *)pGroupFive);
		visual_transferin((void *) 0, 0, pRecalc);
		if (!( pRecalc )) _Context->value_Recalc=0;
		else	_Context->value_Recalc = *((int *)pRecalc);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto4568[i]=" ";
	_Context->msg_Auto4568[0]=en_Auto4568;
	_Context->msg_Auto4568[1]=fr_Auto4568;
	_Context->x_Auto4568=215;
	_Context->y_Auto4568=110;
	_Context->w_Auto4568=370;
	_Context->h_Auto4568=380;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto4822[i]=" ";
	_Context->msg_Auto4822[0]=en_Auto4822;
	_Context->msg_Auto4822[1]=fr_Auto4822;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	for (i=0; i < 8; i++)_Context->msg_Auto4569[i]=" ";
	_Context->msg_Auto4569[0]=en_Auto4569;
	_Context->msg_Auto4569[1]=fr_Auto4569;
	_Context->msg_Auto4569[2]=it_Auto4569;
	_Context->msg_Auto4569[3]=es_Auto4569;
	_Context->msg_Auto4569[4]=de_Auto4569;
	_Context->msg_Auto4569[5]=nl_Auto4569;
	_Context->msg_Auto4569[6]=pt_Auto4569;
	_Context->msg_Auto4569[7]=xx_Auto4569;
	for (i=0; i < 8; i++)_Context->msg_Auto4570[i]=" ";
	_Context->msg_Auto4570[0]=en_Auto4570;
	_Context->msg_Auto4570[1]=fr_Auto4570;
	_Context->msg_Auto4570[2]=it_Auto4570;
	_Context->msg_Auto4570[3]=es_Auto4570;
	_Context->msg_Auto4570[4]=de_Auto4570;
	_Context->msg_Auto4570[5]=nl_Auto4570;
	_Context->msg_Auto4570[6]=pt_Auto4570;
	_Context->msg_Auto4570[7]=xx_Auto4570;
	for (i=0; i < 8; i++)_Context->msg_SourceFont[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_GroupOne[i]=" ";
	_Context->msg_GroupOne[0]=en_GroupOne;
	_Context->msg_GroupOne[1]=fr_GroupOne;
	_Context->msg_GroupOne[2]=it_GroupOne;
	_Context->msg_GroupOne[3]=es_GroupOne;
	_Context->msg_GroupOne[4]=de_GroupOne;
	_Context->msg_GroupOne[5]=nl_GroupOne;
	_Context->msg_GroupOne[6]=pt_GroupOne;
	_Context->msg_GroupOne[7]=xx_GroupOne;
	for (i=0; i < 8; i++)_Context->msg_Auto4622[i]=" ";
	_Context->msg_Auto4622[0]=en_Auto4622;
	_Context->msg_Auto4622[1]=fr_Auto4622;
	_Context->msg_Auto4622[2]=it_Auto4622;
	_Context->msg_Auto4622[3]=es_Auto4622;
	_Context->msg_Auto4622[4]=de_Auto4622;
	_Context->msg_Auto4622[5]=nl_Auto4622;
	_Context->msg_Auto4622[6]=pt_Auto4622;
	_Context->msg_Auto4622[7]=xx_Auto4622;
	for (i=0; i < 8; i++)_Context->msg_GroupTwo[i]=" ";
	_Context->msg_GroupTwo[0]=en_GroupTwo;
	_Context->msg_GroupTwo[1]=fr_GroupTwo;
	_Context->msg_GroupTwo[2]=it_GroupTwo;
	_Context->msg_GroupTwo[3]=es_GroupTwo;
	_Context->msg_GroupTwo[4]=de_GroupTwo;
	_Context->msg_GroupTwo[5]=nl_GroupTwo;
	_Context->msg_GroupTwo[6]=pt_GroupTwo;
	_Context->msg_GroupTwo[7]=xx_GroupTwo;
	for (i=0; i < 8; i++)_Context->msg_Auto4623[i]=" ";
	_Context->msg_Auto4623[0]=en_Auto4623;
	_Context->msg_Auto4623[1]=fr_Auto4623;
	_Context->msg_Auto4623[2]=it_Auto4623;
	_Context->msg_Auto4623[3]=es_Auto4623;
	_Context->msg_Auto4623[4]=de_Auto4623;
	_Context->msg_Auto4623[5]=nl_Auto4623;
	_Context->msg_Auto4623[6]=pt_Auto4623;
	_Context->msg_Auto4623[7]=xx_Auto4623;
	for (i=0; i < 8; i++)_Context->msg_GroupThree[i]=" ";
	_Context->msg_GroupThree[0]=en_GroupThree;
	_Context->msg_GroupThree[1]=fr_GroupThree;
	_Context->msg_GroupThree[2]=it_GroupThree;
	_Context->msg_GroupThree[3]=es_GroupThree;
	_Context->msg_GroupThree[4]=de_GroupThree;
	_Context->msg_GroupThree[5]=nl_GroupThree;
	_Context->msg_GroupThree[6]=pt_GroupThree;
	_Context->msg_GroupThree[7]=xx_GroupThree;
	for (i=0; i < 8; i++)_Context->msg_Auto4624[i]=" ";
	_Context->msg_Auto4624[0]=en_Auto4624;
	_Context->msg_Auto4624[1]=fr_Auto4624;
	_Context->msg_Auto4624[2]=it_Auto4624;
	_Context->msg_Auto4624[3]=es_Auto4624;
	_Context->msg_Auto4624[4]=de_Auto4624;
	_Context->msg_Auto4624[5]=nl_Auto4624;
	_Context->msg_Auto4624[6]=pt_Auto4624;
	_Context->msg_Auto4624[7]=xx_Auto4624;
	for (i=0; i < 8; i++)_Context->msg_GroupFour[i]=" ";
	_Context->msg_GroupFour[0]=en_GroupFour;
	_Context->msg_GroupFour[1]=fr_GroupFour;
	_Context->msg_GroupFour[2]=it_GroupFour;
	_Context->msg_GroupFour[3]=es_GroupFour;
	_Context->msg_GroupFour[4]=de_GroupFour;
	_Context->msg_GroupFour[5]=nl_GroupFour;
	_Context->msg_GroupFour[6]=pt_GroupFour;
	_Context->msg_GroupFour[7]=xx_GroupFour;
	for (i=0; i < 8; i++)_Context->msg_Auto4625[i]=" ";
	_Context->msg_Auto4625[0]=en_Auto4625;
	_Context->msg_Auto4625[1]=fr_Auto4625;
	_Context->msg_Auto4625[2]=it_Auto4625;
	_Context->msg_Auto4625[3]=es_Auto4625;
	_Context->msg_Auto4625[4]=de_Auto4625;
	_Context->msg_Auto4625[5]=nl_Auto4625;
	_Context->msg_Auto4625[6]=pt_Auto4625;
	_Context->msg_Auto4625[7]=xx_Auto4625;
	for (i=0; i < 8; i++)_Context->msg_GroupFive[i]=" ";
	_Context->msg_GroupFive[0]=en_GroupFive;
	_Context->msg_GroupFive[1]=fr_GroupFive;
	_Context->msg_GroupFive[2]=it_GroupFive;
	_Context->msg_GroupFive[3]=es_GroupFive;
	_Context->msg_GroupFive[4]=de_GroupFive;
	_Context->msg_GroupFive[5]=nl_GroupFive;
	_Context->msg_GroupFive[6]=pt_GroupFive;
	_Context->msg_GroupFive[7]=xx_GroupFive;
	for (i=0; i < 8; i++)_Context->msg_Recalc[i]=" ";
	_Context->msg_Recalc[0]=en_Recalc;
	_Context->msg_Recalc[1]=fr_Recalc;
	_Context->msg_Recalc[2]=it_Recalc;
	_Context->msg_Recalc[3]=es_Recalc;
	_Context->msg_Recalc[4]=de_Recalc;
	_Context->msg_Recalc[5]=nl_Recalc;
	_Context->msg_Recalc[6]=pt_Recalc;
	_Context->msg_Recalc[7]=xx_Recalc;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto4568,_Context->y_Auto4568,370+10,380+10);
	return(0);
}

public 	int	accept_extraction_hide(struct accept_extraction_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto4568,_Context->y_Auto4568);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_extraction_remove(
	struct accept_extraction_context * _Context,
	char * pSourceFont,
	char * pGroupOne,
	char * pAuto4622,
	char * pGroupTwo,
	char * pAuto4623,
	char * pGroupThree,
	char * pAuto4624,
	char * pGroupFour,
	char * pAuto4625,
	char * pGroupFive,
	char * pRecalc)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pSourceFont);
		if ( pSourceFont != (char *) 0)
			*((int*)pSourceFont) = _Context->value_SourceFont;
		visual_transferout((void *) 0, 0, pGroupOne);
		if ( pGroupOne != (char *) 0)
			*((int*)pGroupOne) = _Context->value_GroupOne;
		visual_transferout((void *) 0, 0, pAuto4622);
		if ( pAuto4622 != (char *) 0)
			*((int*)pAuto4622) = _Context->value_Auto4622;
		visual_transferout((void *) 0, 0, pGroupTwo);
		if ( pGroupTwo != (char *) 0)
			*((int*)pGroupTwo) = _Context->value_GroupTwo;
		visual_transferout((void *) 0, 0, pAuto4623);
		if ( pAuto4623 != (char *) 0)
			*((int*)pAuto4623) = _Context->value_Auto4623;
		visual_transferout((void *) 0, 0, pGroupThree);
		if ( pGroupThree != (char *) 0)
			*((int*)pGroupThree) = _Context->value_GroupThree;
		visual_transferout((void *) 0, 0, pAuto4624);
		if ( pAuto4624 != (char *) 0)
			*((int*)pAuto4624) = _Context->value_Auto4624;
		visual_transferout((void *) 0, 0, pGroupFour);
		if ( pGroupFour != (char *) 0)
			*((int*)pGroupFour) = _Context->value_GroupFour;
		visual_transferout((void *) 0, 0, pAuto4625);
		if ( pAuto4625 != (char *) 0)
			*((int*)pAuto4625) = _Context->value_Auto4625;
		visual_transferout((void *) 0, 0, pGroupFive);
		if ( pGroupFive != (char *) 0)
			*((int*)pGroupFive) = _Context->value_GroupFive;
		visual_transferout((void *) 0, 0, pRecalc);
		if ( pRecalc != (char *) 0)
			*((int*)pRecalc) = _Context->value_Recalc;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_extraction_show(struct accept_extraction_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto4568,_Context->y_Auto4568);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto4568,_Context->y_Auto4568,370,380,vfh[2],_Context->msg_Auto4568[_Context->language],strlen(_Context->msg_Auto4568[_Context->language]),0x407);
	visual_image(_Context->x_Auto4568+3,_Context->y_Auto4568+21,363,355,_Context->msg_Auto4822[_Context->language],4);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto4568+10,_Context->y_Auto4568+330,120,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto4568+240,_Context->y_Auto4568+330,120,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_text(_Context->x_Auto4568+10,_Context->y_Auto4568+30,350,20,vfh[3],27,0,_Context->msg_Auto4569[_Context->language],strlen(_Context->msg_Auto4569[_Context->language]),1026);
	visual_frame(_Context->x_Auto4568+10,_Context->y_Auto4568+50,350,270,4);
	visual_text(_Context->x_Auto4568+20,_Context->y_Auto4568+70,182,16,vfh[2],27,0,_Context->msg_Auto4570[_Context->language],strlen(_Context->msg_Auto4570[_Context->language]),2);
	visual_select(_Context->x_Auto4568+210,_Context->y_Auto4568+70,128,80,vfh[1],34,0,parse_selection(TextFontList,&_Context->value_SourceFont),0);
	_Context->trigger_GroupOne=visual_trigger_code(_Context->msg_GroupOne[_Context->language],strlen(_Context->msg_GroupOne[_Context->language]));
	visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+110,322,16,vfh[1],27,28,_Context->msg_GroupOne[_Context->language],strlen(_Context->msg_GroupOne[_Context->language]),_Context->value_GroupOne|0);
	_Context->trigger_Auto4622=visual_trigger_code(_Context->msg_Auto4622[_Context->language],strlen(_Context->msg_Auto4622[_Context->language]));
	visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+130,320,16,vfh[1],0,0,_Context->msg_Auto4622[_Context->language],strlen(_Context->msg_Auto4622[_Context->language]),_Context->value_Auto4622|0);
	_Context->trigger_GroupTwo=visual_trigger_code(_Context->msg_GroupTwo[_Context->language],strlen(_Context->msg_GroupTwo[_Context->language]));
	visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+150,322,16,vfh[1],27,28,_Context->msg_GroupTwo[_Context->language],strlen(_Context->msg_GroupTwo[_Context->language]),_Context->value_GroupTwo|0);
	_Context->trigger_Auto4623=visual_trigger_code(_Context->msg_Auto4623[_Context->language],strlen(_Context->msg_Auto4623[_Context->language]));
	visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+170,320,16,vfh[1],0,0,_Context->msg_Auto4623[_Context->language],strlen(_Context->msg_Auto4623[_Context->language]),_Context->value_Auto4623|0);
	_Context->trigger_GroupThree=visual_trigger_code(_Context->msg_GroupThree[_Context->language],strlen(_Context->msg_GroupThree[_Context->language]));
	visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+190,322,16,vfh[1],27,28,_Context->msg_GroupThree[_Context->language],strlen(_Context->msg_GroupThree[_Context->language]),_Context->value_GroupThree|0);
	_Context->trigger_Auto4624=visual_trigger_code(_Context->msg_Auto4624[_Context->language],strlen(_Context->msg_Auto4624[_Context->language]));
	visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+210,320,16,vfh[1],0,0,_Context->msg_Auto4624[_Context->language],strlen(_Context->msg_Auto4624[_Context->language]),_Context->value_Auto4624|0);
	_Context->trigger_GroupFour=visual_trigger_code(_Context->msg_GroupFour[_Context->language],strlen(_Context->msg_GroupFour[_Context->language]));
	visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+230,322,16,vfh[1],27,28,_Context->msg_GroupFour[_Context->language],strlen(_Context->msg_GroupFour[_Context->language]),_Context->value_GroupFour|0);
	_Context->trigger_Auto4625=visual_trigger_code(_Context->msg_Auto4625[_Context->language],strlen(_Context->msg_Auto4625[_Context->language]));
	visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+250,320,16,vfh[1],0,0,_Context->msg_Auto4625[_Context->language],strlen(_Context->msg_Auto4625[_Context->language]),_Context->value_Auto4625|0);
	_Context->trigger_GroupFive=visual_trigger_code(_Context->msg_GroupFive[_Context->language],strlen(_Context->msg_GroupFive[_Context->language]));
	visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+270,322,16,vfh[1],27,28,_Context->msg_GroupFive[_Context->language],strlen(_Context->msg_GroupFive[_Context->language]),_Context->value_GroupFive|0);
	_Context->trigger_Recalc=visual_trigger_code(_Context->msg_Recalc[_Context->language],strlen(_Context->msg_Recalc[_Context->language]));
	visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+290,320,20,vfh[1],0,0,_Context->msg_Recalc[_Context->language],strlen(_Context->msg_Recalc[_Context->language]),_Context->value_Recalc|0);
	visual_thaw(_Context->x_Auto4568,_Context->y_Auto4568,370,380);
	visual_thaw(_Context->x_Auto4568,_Context->y_Auto4568,370,380);

	return(0);
}

private int Auto4568action(struct accept_extraction_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_extraction_hide(_Context);

		_Context->x_Auto4568 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto4568 < 0) { _Context->x_Auto4568=0; }
		_Context->y_Auto4568 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto4568 < 0) { _Context->y_Auto4568=0; }
			accept_extraction_show(_Context);

		visual_thaw(_Context->x_Auto4568,_Context->y_Auto4568,370,380);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_extraction_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_extraction_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_extraction_event(
struct accept_extraction_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(2);
		if (_Context->trigger_Cancel == mb ) return(3);
		if (_Context->trigger_GroupOne == mb ) return(5);
		if (_Context->trigger_Auto4622 == mb ) return(6);
		if (_Context->trigger_GroupTwo == mb ) return(7);
		if (_Context->trigger_Auto4623 == mb ) return(8);
		if (_Context->trigger_GroupThree == mb ) return(9);
		if (_Context->trigger_Auto4624 == mb ) return(10);
		if (_Context->trigger_GroupFour == mb ) return(11);
		if (_Context->trigger_Auto4625 == mb ) return(12);
		if (_Context->trigger_GroupFive == mb ) return(13);
		if (_Context->trigger_Recalc == mb ) return(14);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto4568+349) )  
	&&  (my >= (_Context->y_Auto4568+4) )  
	&&  (mx <= (_Context->x_Auto4568+366) )  
	&&  (my <= (_Context->y_Auto4568+20) )) {
		return(1);	/* Auto4568 */

		}
	if ((mx >= (_Context->x_Auto4568+333) )  
	&&  (my >= (_Context->y_Auto4568+4) )  
	&&  (mx <= (_Context->x_Auto4568+350) )  
	&&  (my <= (_Context->y_Auto4568+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vfextr.htm");
			};
		return(-1);	/* Auto4568 */

		}
	if ((mx >= (_Context->x_Auto4568+317) )  
	&&  (my >= (_Context->y_Auto4568+4) )  
	&&  (mx <= (_Context->x_Auto4568+334) )  
	&&  (my <= (_Context->y_Auto4568+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_extraction_show(_Context);
		return(-1);	/* Auto4568 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto4568+4) )  
		&&  (my >= (_Context->y_Auto4568+4) )  
		&&  (mx <= (_Context->x_Auto4568+302) )  
		&&  (my <= (_Context->y_Auto4568+20) )) {
			return( Auto4568action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto4568+10) ) 
	&&  ( my >= (_Context->y_Auto4568+330) ) 
	&&  ( mx <= (_Context->x_Auto4568+10+120) ) 
	&&  ( my <= (_Context->y_Auto4568+330+32))) {
		return(2); /* Accept */
		}
	if (( mx >= (_Context->x_Auto4568+240) ) 
	&&  ( my >= (_Context->y_Auto4568+330) ) 
	&&  ( mx <= (_Context->x_Auto4568+240+120) ) 
	&&  ( my <= (_Context->y_Auto4568+330+32))) {
		return(3); /* Cancel */
		}
	if (( mx >= (_Context->x_Auto4568+210+0) ) 
	&&  ( my >= (_Context->y_Auto4568+70) ) 
	&&  ( mx <= (_Context->x_Auto4568+210+128) ) 
	&&  ( my <= (_Context->y_Auto4568+70+16))) {
		return(4); /* SourceFont */
		}
	if (( mx >= (_Context->x_Auto4568+20) ) 
	&&  ( my >= (_Context->y_Auto4568+110) ) 
	&&  ( mx <= (_Context->x_Auto4568+20+322) ) 
	&&  ( my <= (_Context->y_Auto4568+110+16))) {
		return(5); /* GroupOne */
		}
	if (( mx >= (_Context->x_Auto4568+20) ) 
	&&  ( my >= (_Context->y_Auto4568+130) ) 
	&&  ( mx <= (_Context->x_Auto4568+20+320) ) 
	&&  ( my <= (_Context->y_Auto4568+130+16))) {
		return(6); /* Auto4622 */
		}
	if (( mx >= (_Context->x_Auto4568+20) ) 
	&&  ( my >= (_Context->y_Auto4568+150) ) 
	&&  ( mx <= (_Context->x_Auto4568+20+322) ) 
	&&  ( my <= (_Context->y_Auto4568+150+16))) {
		return(7); /* GroupTwo */
		}
	if (( mx >= (_Context->x_Auto4568+20) ) 
	&&  ( my >= (_Context->y_Auto4568+170) ) 
	&&  ( mx <= (_Context->x_Auto4568+20+320) ) 
	&&  ( my <= (_Context->y_Auto4568+170+16))) {
		return(8); /* Auto4623 */
		}
	if (( mx >= (_Context->x_Auto4568+20) ) 
	&&  ( my >= (_Context->y_Auto4568+190) ) 
	&&  ( mx <= (_Context->x_Auto4568+20+322) ) 
	&&  ( my <= (_Context->y_Auto4568+190+16))) {
		return(9); /* GroupThree */
		}
	if (( mx >= (_Context->x_Auto4568+20) ) 
	&&  ( my >= (_Context->y_Auto4568+210) ) 
	&&  ( mx <= (_Context->x_Auto4568+20+320) ) 
	&&  ( my <= (_Context->y_Auto4568+210+16))) {
		return(10); /* Auto4624 */
		}
	if (( mx >= (_Context->x_Auto4568+20) ) 
	&&  ( my >= (_Context->y_Auto4568+230) ) 
	&&  ( mx <= (_Context->x_Auto4568+20+322) ) 
	&&  ( my <= (_Context->y_Auto4568+230+16))) {
		return(11); /* GroupFour */
		}
	if (( mx >= (_Context->x_Auto4568+20) ) 
	&&  ( my >= (_Context->y_Auto4568+250) ) 
	&&  ( mx <= (_Context->x_Auto4568+20+320) ) 
	&&  ( my <= (_Context->y_Auto4568+250+16))) {
		return(12); /* Auto4625 */
		}
	if (( mx >= (_Context->x_Auto4568+20) ) 
	&&  ( my >= (_Context->y_Auto4568+270) ) 
	&&  ( mx <= (_Context->x_Auto4568+20+322) ) 
	&&  ( my <= (_Context->y_Auto4568+270+16))) {
		return(13); /* GroupFive */
		}
	if (( mx >= (_Context->x_Auto4568+20) ) 
	&&  ( my >= (_Context->y_Auto4568+290) ) 
	&&  ( mx <= (_Context->x_Auto4568+20+320) ) 
	&&  ( my <= (_Context->y_Auto4568+290+20))) {
		return(14); /* Recalc */
		}

	return(-1);
}


public	int	accept_extraction_focus(struct accept_extraction_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Accept */
				visual_button(_Context->x_Auto4568+10,_Context->y_Auto4568+330,120,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto4568+10,_Context->y_Auto4568+330,120,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x3 :
				/* Cancel */
				visual_button(_Context->x_Auto4568+240,_Context->y_Auto4568+330,120,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto4568+240,_Context->y_Auto4568+330,120,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0x4 :
				/* SourceFont */
				_Context->keycode = visual_select(_Context->x_Auto4568+210,_Context->y_Auto4568+70,128,80,vfh[1],34,0,parse_selection(TextFontList,&_Context->value_SourceFont),2);
				break;
			case	0x5 :
				/* GroupOne */
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+110,322,16,vfh[1],27,28,_Context->msg_GroupOne[_Context->language],strlen(_Context->msg_GroupOne[_Context->language]),(_Context->value_GroupOne |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+110,322,16,vfh[1],27,28,_Context->msg_GroupOne[_Context->language],strlen(_Context->msg_GroupOne[_Context->language]),(_Context->value_GroupOne |0));
				break;
			case	0x6 :
				/* Auto4622 */
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+130,320,16,vfh[1],0,0,_Context->msg_Auto4622[_Context->language],strlen(_Context->msg_Auto4622[_Context->language]),(_Context->value_Auto4622 |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+130,320,16,vfh[1],0,0,_Context->msg_Auto4622[_Context->language],strlen(_Context->msg_Auto4622[_Context->language]),(_Context->value_Auto4622 |0));
				break;
			case	0x7 :
				/* GroupTwo */
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+150,322,16,vfh[1],27,28,_Context->msg_GroupTwo[_Context->language],strlen(_Context->msg_GroupTwo[_Context->language]),(_Context->value_GroupTwo |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+150,322,16,vfh[1],27,28,_Context->msg_GroupTwo[_Context->language],strlen(_Context->msg_GroupTwo[_Context->language]),(_Context->value_GroupTwo |0));
				break;
			case	0x8 :
				/* Auto4623 */
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+170,320,16,vfh[1],0,0,_Context->msg_Auto4623[_Context->language],strlen(_Context->msg_Auto4623[_Context->language]),(_Context->value_Auto4623 |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+170,320,16,vfh[1],0,0,_Context->msg_Auto4623[_Context->language],strlen(_Context->msg_Auto4623[_Context->language]),(_Context->value_Auto4623 |0));
				break;
			case	0x9 :
				/* GroupThree */
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+190,322,16,vfh[1],27,28,_Context->msg_GroupThree[_Context->language],strlen(_Context->msg_GroupThree[_Context->language]),(_Context->value_GroupThree |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+190,322,16,vfh[1],27,28,_Context->msg_GroupThree[_Context->language],strlen(_Context->msg_GroupThree[_Context->language]),(_Context->value_GroupThree |0));
				break;
			case	0xa :
				/* Auto4624 */
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+210,320,16,vfh[1],0,0,_Context->msg_Auto4624[_Context->language],strlen(_Context->msg_Auto4624[_Context->language]),(_Context->value_Auto4624 |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+210,320,16,vfh[1],0,0,_Context->msg_Auto4624[_Context->language],strlen(_Context->msg_Auto4624[_Context->language]),(_Context->value_Auto4624 |0));
				break;
			case	0xb :
				/* GroupFour */
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+230,322,16,vfh[1],27,28,_Context->msg_GroupFour[_Context->language],strlen(_Context->msg_GroupFour[_Context->language]),(_Context->value_GroupFour |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+230,322,16,vfh[1],27,28,_Context->msg_GroupFour[_Context->language],strlen(_Context->msg_GroupFour[_Context->language]),(_Context->value_GroupFour |0));
				break;
			case	0xc :
				/* Auto4625 */
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+250,320,16,vfh[1],0,0,_Context->msg_Auto4625[_Context->language],strlen(_Context->msg_Auto4625[_Context->language]),(_Context->value_Auto4625 |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+250,320,16,vfh[1],0,0,_Context->msg_Auto4625[_Context->language],strlen(_Context->msg_Auto4625[_Context->language]),(_Context->value_Auto4625 |0));
				break;
			case	0xd :
				/* GroupFive */
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+270,322,16,vfh[1],27,28,_Context->msg_GroupFive[_Context->language],strlen(_Context->msg_GroupFive[_Context->language]),(_Context->value_GroupFive |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+270,322,16,vfh[1],27,28,_Context->msg_GroupFive[_Context->language],strlen(_Context->msg_GroupFive[_Context->language]),(_Context->value_GroupFive |0));
				break;
			case	0xe :
				/* Recalc */
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+290,320,20,vfh[1],0,0,_Context->msg_Recalc[_Context->language],strlen(_Context->msg_Recalc[_Context->language]),(_Context->value_Recalc |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto4568+20,_Context->y_Auto4568+290,320,20,vfh[1],0,0,_Context->msg_Recalc[_Context->language],strlen(_Context->msg_Recalc[_Context->language]),(_Context->value_Recalc |0));
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_extraction_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=14;
			accept_extraction_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_extraction_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto4568 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto4568+10,_Context->y_Auto4568+330,120,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto4568+10,_Context->y_Auto4568+330,120,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto4568+240,_Context->y_Auto4568+330,120,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto4568+240,_Context->y_Auto4568+330,120,32,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* SourceFont */
						continue;
					case	0x5 :
						/* GroupOne */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_GroupOne += 1;
							_Context->value_GroupOne &= 1;
							}
						continue;
					case	0x6 :
						/* Auto4622 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Auto4622 += 1;
							_Context->value_Auto4622 &= 1;
							}
						continue;
					case	0x7 :
						/* GroupTwo */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_GroupTwo += 1;
							_Context->value_GroupTwo &= 1;
							}
						continue;
					case	0x8 :
						/* Auto4623 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Auto4623 += 1;
							_Context->value_Auto4623 &= 1;
							}
						continue;
					case	0x9 :
						/* GroupThree */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_GroupThree += 1;
							_Context->value_GroupThree &= 1;
							}
						continue;
					case	0xa :
						/* Auto4624 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Auto4624 += 1;
							_Context->value_Auto4624 &= 1;
							}
						continue;
					case	0xb :
						/* GroupFour */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_GroupFour += 1;
							_Context->value_GroupFour &= 1;
							}
						continue;
					case	0xc :
						/* Auto4625 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Auto4625 += 1;
							_Context->value_Auto4625 &= 1;
							}
						continue;
					case	0xd :
						/* GroupFive */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_GroupFive += 1;
							_Context->value_GroupFive &= 1;
							}
						continue;
					case	0xe :
						/* Recalc */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Recalc += 1;
							_Context->value_Recalc &= 1;
							}
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
				_Context->focus_item=14;
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

public	int	accept_extraction(
	char * pSourceFont,
	char * pGroupOne,
	char * pAuto4622,
	char * pGroupTwo,
	char * pAuto4623,
	char * pGroupThree,
	char * pAuto4624,
	char * pGroupFour,
	char * pAuto4625,
	char * pGroupFive,
	char * pRecalc)
{
	int	status=0;
	struct accept_extraction_context * _Context=(struct accept_extraction_context*) 0;
	status = accept_extraction_create(
	&_Context,
	 pSourceFont,
	 pGroupOne,
	 pAuto4622,
	 pGroupTwo,
	 pAuto4623,
	 pGroupThree,
	 pAuto4624,
	 pGroupFour,
	 pAuto4625,
	 pGroupFive,
	 pRecalc);
	if ( status != 0) return(status);
	status = accept_extraction_show(_Context);
		enter_modal();
	status = accept_extraction_focus(_Context);
		leave_modal();
	status = accept_extraction_hide(_Context);
	status = accept_extraction_remove(
	_Context,
	 pSourceFont,
	 pGroupOne,
	 pAuto4622,
	 pGroupTwo,
	 pAuto4623,
	 pGroupThree,
	 pAuto4624,
	 pGroupFour,
	 pAuto4625,
	 pGroupFive,
	 pRecalc);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vfextr_c */
