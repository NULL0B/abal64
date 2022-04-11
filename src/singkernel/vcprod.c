
#ifndef _vcprod_c
#define _vcprod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vcprod.xml  */
/* Target         : vcprod.c  */
/* Identification : 0.0-1100519960-7158.7157 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#include "singlang.h"
#define en_auto2   "Sing : Version 1.0a"
#define fr_auto2   "Sing : Version 1.0a"
#define en_Auto1157   "skin.gif"
#define fr_Auto1157   "skin.gif"
#define en_auto7   "C Production Filename"
#define fr_auto7   "Nom de Fichier Cible C"
#define it_auto7   "C Production Filename"
#define es_auto7   "C Production Filename"
#define de_auto7   "C Production Filename"
#define nl_auto7   "C Production Filename"
#define pt_auto7   "C Production Filename"
#define xx_auto7   "C Production Filename"
#define en_auto52   "Identifier"
#define fr_auto52   "Identifiant"
#define it_auto52   "Identifier"
#define es_auto52   "Identifier"
#define de_auto52   "Identifier"
#define nl_auto52   "Identifier"
#define pt_auto52   "Identifier"
#define xx_auto52   "Identifier"
#define en_Identifier   ""
#define en_IsProgram   "&Program avec Main"
#define fr_IsProgram   "&Program with Main"
#define it_IsProgram   "&Program with Main"
#define es_IsProgram   "&Program with Main"
#define de_IsProgram   "&Program with Main"
#define nl_IsProgram   "&Program with Main"
#define pt_IsProgram   "&Program with Main"
#define xx_IsProgram   "&Program with Main"
#define en_IsOverlay   "&Visual Interface"
#define fr_IsOverlay   "Interface &Visual"
#define it_IsOverlay   "&Visual Interface"
#define es_IsOverlay   "&Visual Interface"
#define de_IsOverlay   "&Visual Interface"
#define nl_IsOverlay   "&Visual Interface"
#define pt_IsOverlay   "&Visual Interface"
#define xx_IsOverlay   "&Visual Interface"
#define en_IsTrueColour   "&TrueColour"
#define fr_IsTrueColour   "&TrueColour"
#define it_IsTrueColour   "&TrueColour"
#define es_IsTrueColour   "&TrueColour"
#define de_IsTrueColour   "&TrueColour"
#define nl_IsTrueColour   "&TrueColour"
#define pt_IsTrueColour   "&TrueColour"
#define xx_IsTrueColour   "&TrueColour"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
#define en_auto641   "Inclusions"
#define fr_auto641   "Inclusions"
#define it_auto641   "Inclusions"
#define es_auto641   "Inclusions"
#define de_auto641   "Inclusions"
#define nl_auto641   "Inclusions"
#define pt_auto641   "Inclusions"
#define xx_auto641   "Inclusions"
#define en_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define fr_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define en_Edit   "&Edit"
#define fr_Edit   "&Edition"
#define en_Select   "&Select"
#define fr_Select   "&S‚lection"
#define en_auto724   "cicon.gif"
static int	vfh[10];

private struct accept_c_production_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto2[8];
	int	x_auto2;
	int	y_auto2;
	int	w_auto2;
	int	h_auto2;
	char * msg_Auto1157[8];
	char * msg_auto7[8];
	char	buffer_FileName[71];
	char * msg_auto52[8];
	char	buffer_Identifier[71];
	char * msg_IsProgram[8];
	int	trigger_IsProgram;
	int	value_IsProgram;
	char * msg_IsOverlay[8];
	int	trigger_IsOverlay;
	int	value_IsOverlay;
	char * msg_IsTrueColour[8];
	int	trigger_IsTrueColour;
	int	value_IsTrueColour;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_auto641[8];
	char	buffer_Inclusions[211];
	char * msg_Dimensions[8];
	int	value_Dimensions;
	char * msg_Edit[8];
	int	trigger_Edit;
	char * msg_Select[8];
	int	trigger_Select;
	char * msg_auto724[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[8];
	};

public	int	accept_c_production_create(
	struct accept_c_production_context ** cptr,
	char * pFileName,
	char * pIdentifier,
	char * pIsProgram,
	char * pIsOverlay,
	char * pIsTrueColour,
	char * pInclusions,
	char * pDimensions)
{

	int i;
	struct accept_c_production_context * _Context=(struct accept_c_production_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_c_production_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=16;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 70, pFileName);
		visual_transferin(_Context->buffer_Identifier, 70, pIdentifier);
		visual_transferin((void *) 0, 0, pIsProgram);
		if (!( pIsProgram )) _Context->value_IsProgram=0;
		else	_Context->value_IsProgram = *((int *)pIsProgram);
		visual_transferin((void *) 0, 0, pIsOverlay);
		if (!( pIsOverlay )) _Context->value_IsOverlay=0;
		else	_Context->value_IsOverlay = *((int *)pIsOverlay);
		visual_transferin((void *) 0, 0, pIsTrueColour);
		if (!( pIsTrueColour )) _Context->value_IsTrueColour=0;
		else	_Context->value_IsTrueColour = *((int *)pIsTrueColour);
		visual_transferin(_Context->buffer_Inclusions, 210, pInclusions);
		visual_transferin((void *) 0, 0, pDimensions);
		if (!( pDimensions )) _Context->value_Dimensions=0;
		else	_Context->value_Dimensions = *((int *)pDimensions);
		}
	for (i=0; i < 8; i++)_Context->msg_auto2[i]=" ";
	_Context->msg_auto2[0]=en_auto2;
	_Context->msg_auto2[1]=fr_auto2;
	_Context->x_auto2=100;
	_Context->y_auto2=140;
	_Context->w_auto2=600;
	_Context->h_auto2=320;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1157[i]=" ";
	_Context->msg_Auto1157[0]=en_Auto1157;
	_Context->msg_Auto1157[1]=fr_Auto1157;
	for (i=0; i < 8; i++)_Context->msg_auto7[i]=" ";
	_Context->msg_auto7[0]=en_auto7;
	_Context->msg_auto7[1]=fr_auto7;
	_Context->msg_auto7[2]=it_auto7;
	_Context->msg_auto7[3]=es_auto7;
	_Context->msg_auto7[4]=de_auto7;
	_Context->msg_auto7[5]=nl_auto7;
	_Context->msg_auto7[6]=pt_auto7;
	_Context->msg_auto7[7]=xx_auto7;
	for (i=0; i < 8; i++)_Context->msg_auto52[i]=" ";
	_Context->msg_auto52[0]=en_auto52;
	_Context->msg_auto52[1]=fr_auto52;
	_Context->msg_auto52[2]=it_auto52;
	_Context->msg_auto52[3]=es_auto52;
	_Context->msg_auto52[4]=de_auto52;
	_Context->msg_auto52[5]=nl_auto52;
	_Context->msg_auto52[6]=pt_auto52;
	_Context->msg_auto52[7]=xx_auto52;
	for (i=0; i < 8; i++)_Context->msg_IsProgram[i]=" ";
	_Context->msg_IsProgram[0]=en_IsProgram;
	_Context->msg_IsProgram[1]=fr_IsProgram;
	_Context->msg_IsProgram[2]=it_IsProgram;
	_Context->msg_IsProgram[3]=es_IsProgram;
	_Context->msg_IsProgram[4]=de_IsProgram;
	_Context->msg_IsProgram[5]=nl_IsProgram;
	_Context->msg_IsProgram[6]=pt_IsProgram;
	_Context->msg_IsProgram[7]=xx_IsProgram;
	for (i=0; i < 8; i++)_Context->msg_IsOverlay[i]=" ";
	_Context->msg_IsOverlay[0]=en_IsOverlay;
	_Context->msg_IsOverlay[1]=fr_IsOverlay;
	_Context->msg_IsOverlay[2]=it_IsOverlay;
	_Context->msg_IsOverlay[3]=es_IsOverlay;
	_Context->msg_IsOverlay[4]=de_IsOverlay;
	_Context->msg_IsOverlay[5]=nl_IsOverlay;
	_Context->msg_IsOverlay[6]=pt_IsOverlay;
	_Context->msg_IsOverlay[7]=xx_IsOverlay;
	for (i=0; i < 8; i++)_Context->msg_IsTrueColour[i]=" ";
	_Context->msg_IsTrueColour[0]=en_IsTrueColour;
	_Context->msg_IsTrueColour[1]=fr_IsTrueColour;
	_Context->msg_IsTrueColour[2]=it_IsTrueColour;
	_Context->msg_IsTrueColour[3]=es_IsTrueColour;
	_Context->msg_IsTrueColour[4]=de_IsTrueColour;
	_Context->msg_IsTrueColour[5]=nl_IsTrueColour;
	_Context->msg_IsTrueColour[6]=pt_IsTrueColour;
	_Context->msg_IsTrueColour[7]=xx_IsTrueColour;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	for (i=0; i < 8; i++)_Context->msg_auto641[i]=" ";
	_Context->msg_auto641[0]=en_auto641;
	_Context->msg_auto641[1]=fr_auto641;
	_Context->msg_auto641[2]=it_auto641;
	_Context->msg_auto641[3]=es_auto641;
	_Context->msg_auto641[4]=de_auto641;
	_Context->msg_auto641[5]=nl_auto641;
	_Context->msg_auto641[6]=pt_auto641;
	_Context->msg_auto641[7]=xx_auto641;
	for (i=0; i < 8; i++)_Context->msg_Dimensions[i]=" ";
	_Context->msg_Dimensions[0]=en_Dimensions;
	_Context->msg_Dimensions[1]=fr_Dimensions;
	for (i=0; i < 8; i++)_Context->msg_Edit[i]=" ";
	_Context->msg_Edit[0]=en_Edit;
	_Context->msg_Edit[1]=fr_Edit;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	for (i=0; i < 8; i++)_Context->msg_auto724[i]=" ";
	_Context->msg_auto724[0]=en_auto724;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto2,_Context->y_auto2,600+10,320+10);
	return(0);
}

public 	int	accept_c_production_hide(struct accept_c_production_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_c_production_remove(
	struct accept_c_production_context * _Context,
	char * pFileName,
	char * pIdentifier,
	char * pIsProgram,
	char * pIsOverlay,
	char * pIsTrueColour,
	char * pInclusions,
	char * pDimensions)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 70, pFileName);
		visual_transferout(_Context->buffer_Identifier, 70, pIdentifier);
		visual_transferout((void *) 0, 0, pIsProgram);
		if ( pIsProgram != (char *) 0)
			*((int*)pIsProgram) = _Context->value_IsProgram;
		visual_transferout((void *) 0, 0, pIsOverlay);
		if ( pIsOverlay != (char *) 0)
			*((int*)pIsOverlay) = _Context->value_IsOverlay;
		visual_transferout((void *) 0, 0, pIsTrueColour);
		if ( pIsTrueColour != (char *) 0)
			*((int*)pIsTrueColour) = _Context->value_IsTrueColour;
		visual_transferout(_Context->buffer_Inclusions, 210, pInclusions);
		visual_transferout((void *) 0, 0, pDimensions);
		if ( pDimensions != (char *) 0)
			*((int*)pDimensions) = _Context->value_Dimensions;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_c_production_show(struct accept_c_production_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_auto2,_Context->y_auto2,600,320,vfh[2],_Context->msg_auto2[_Context->language],strlen(_Context->msg_auto2[_Context->language]),0x407);
	visual_image(_Context->x_auto2+3,_Context->y_auto2+22,592,294,_Context->msg_Auto1157[_Context->language],4);
	visual_frame(_Context->x_auto2+21,_Context->y_auto2+226,560,25,2);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+40,560,16,vfh[2],27,0,_Context->msg_auto7[_Context->language],strlen(_Context->msg_auto7[_Context->language]),258);
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+60,560+2,16+2,5);
	visual_text(_Context->x_auto2+20+1,_Context->y_auto2+60+1,560,16,vfh[1],34,0,_Context->buffer_FileName,70,0);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+90,560,16,vfh[2],27,0,_Context->msg_auto52[_Context->language],strlen(_Context->msg_auto52[_Context->language]),258);
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+110,560+2,16+2,5);
	visual_text(_Context->x_auto2+20+1,_Context->y_auto2+110+1,560,16,vfh[1],34,0,_Context->buffer_Identifier,70,0);
	_Context->trigger_IsProgram=visual_trigger_code(_Context->msg_IsProgram[_Context->language],strlen(_Context->msg_IsProgram[_Context->language]));
	visual_check(_Context->x_auto2+30,_Context->y_auto2+230,168,16,vfh[2],34,0,_Context->msg_IsProgram[_Context->language],strlen(_Context->msg_IsProgram[_Context->language]),_Context->value_IsProgram|0);
	_Context->trigger_IsOverlay=visual_trigger_code(_Context->msg_IsOverlay[_Context->language],strlen(_Context->msg_IsOverlay[_Context->language]));
	visual_check(_Context->x_auto2+190,_Context->y_auto2+230,140,16,vfh[2],16,0,_Context->msg_IsOverlay[_Context->language],strlen(_Context->msg_IsOverlay[_Context->language]),_Context->value_IsOverlay|0);
	_Context->trigger_IsTrueColour=visual_trigger_code(_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]));
	visual_check(_Context->x_auto2+340,_Context->y_auto2+230,126,16,vfh[2],16,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),_Context->value_IsTrueColour|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+270,110,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto2+470,_Context->y_auto2+270,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+140,560,16,vfh[2],27,0,_Context->msg_auto641[_Context->language],strlen(_Context->msg_auto641[_Context->language]),258);
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+160,560+2,60+2,5);
	visual_text(_Context->x_auto2+20+1,_Context->y_auto2+160+1,560,60,vfh[1],26,0,_Context->buffer_Inclusions,210,0);
	visual_select(_Context->x_auto2+470,_Context->y_auto2+230,104,80,vfh[1],0,0,parse_selection(_Context->msg_Dimensions[_Context->language],&_Context->value_Dimensions),0);
	_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(_Context->x_auto2+140,_Context->y_auto2+270,110,30,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto2+360,_Context->y_auto2+270,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	visual_image(_Context->x_auto2+280,_Context->y_auto2+255,50,50,_Context->msg_auto724[_Context->language],0);
	visual_thaw(_Context->x_auto2,_Context->y_auto2,600,320);
	visual_thaw(_Context->x_auto2,_Context->y_auto2,600,320);

	return(0);
}

private int auto2action(struct accept_c_production_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_c_production_hide(_Context);

		_Context->x_auto2 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto2 < 0) { _Context->x_auto2=0; }
		_Context->y_auto2 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto2 < 0) { _Context->y_auto2=0; }
			accept_c_production_show(_Context);

		visual_thaw(_Context->x_auto2,_Context->y_auto2,600,320);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_c_production_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_c_production_context * _Context) {
	return(27);
	return(-1);
}
private int on_Edit_event(struct accept_c_production_context * _Context) {
		accept_c_production_hide(_Context);
;
	use_editor(_Context->buffer_FileName,_GENERATE_C);
		accept_c_production_show(_Context);
;
	return(-1);
}
private int on_Select_event(struct accept_c_production_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_C);
		accept_c_production_show(_Context);
;
	return(-1);
}


public	int	accept_c_production_event(
struct accept_c_production_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsProgram == mb ) return(6);
		if (_Context->trigger_IsOverlay == mb ) return(7);
		if (_Context->trigger_IsTrueColour == mb ) return(8);
		if (_Context->trigger_Accept == mb ) return(9);
		if (_Context->trigger_Cancel == mb ) return(10);
		if (_Context->trigger_Edit == mb ) return(14);
		if (_Context->trigger_Select == mb ) return(15);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto2+579) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+596) )  
	&&  (my <= (_Context->y_auto2+20) )) {
		return(1);	/* auto2 */

		}
	if ((mx >= (_Context->x_auto2+563) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+580) )  
	&&  (my <= (_Context->y_auto2+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcprod.htm");
			};
		return(-1);	/* auto2 */

		}
	if ((mx >= (_Context->x_auto2+547) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+564) )  
	&&  (my <= (_Context->y_auto2+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_c_production_show(_Context);
		return(-1);	/* auto2 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto2+4) )  
		&&  (my >= (_Context->y_auto2+4) )  
		&&  (mx <= (_Context->x_auto2+532) )  
		&&  (my <= (_Context->y_auto2+20) )) {
			return( auto2action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+60) ) 
	&&  ( mx <= (_Context->x_auto2+20+560) ) 
	&&  ( my <= (_Context->y_auto2+60+16))) {
		return(3); /* FileName */
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+110) ) 
	&&  ( mx <= (_Context->x_auto2+20+560) ) 
	&&  ( my <= (_Context->y_auto2+110+16))) {
		return(5); /* Identifier */
		}
	if (( mx >= (_Context->x_auto2+30) ) 
	&&  ( my >= (_Context->y_auto2+230) ) 
	&&  ( mx <= (_Context->x_auto2+30+168) ) 
	&&  ( my <= (_Context->y_auto2+230+16))) {
		return(6); /* IsProgram */
		}
	if (( mx >= (_Context->x_auto2+190) ) 
	&&  ( my >= (_Context->y_auto2+230) ) 
	&&  ( mx <= (_Context->x_auto2+190+140) ) 
	&&  ( my <= (_Context->y_auto2+230+16))) {
		return(7); /* IsOverlay */
		}
	if (( mx >= (_Context->x_auto2+340) ) 
	&&  ( my >= (_Context->y_auto2+230) ) 
	&&  ( mx <= (_Context->x_auto2+340+126) ) 
	&&  ( my <= (_Context->y_auto2+230+16))) {
		return(8); /* IsTrueColour */
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+270) ) 
	&&  ( mx <= (_Context->x_auto2+20+110) ) 
	&&  ( my <= (_Context->y_auto2+270+30))) {
		return(9); /* Accept */
		}
	if (( mx >= (_Context->x_auto2+470) ) 
	&&  ( my >= (_Context->y_auto2+270) ) 
	&&  ( mx <= (_Context->x_auto2+470+110) ) 
	&&  ( my <= (_Context->y_auto2+270+30))) {
		return(10); /* Cancel */
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+160) ) 
	&&  ( mx <= (_Context->x_auto2+20+560) ) 
	&&  ( my <= (_Context->y_auto2+160+60))) {
		return(12); /* Inclusions */
		}
	if (( mx >= (_Context->x_auto2+470+0) ) 
	&&  ( my >= (_Context->y_auto2+230) ) 
	&&  ( mx <= (_Context->x_auto2+470+104) ) 
	&&  ( my <= (_Context->y_auto2+230+16))) {
		return(13); /* Dimensions */
		}
	if (( mx >= (_Context->x_auto2+140) ) 
	&&  ( my >= (_Context->y_auto2+270) ) 
	&&  ( mx <= (_Context->x_auto2+140+110) ) 
	&&  ( my <= (_Context->y_auto2+270+30))) {
		return(14); /* Edit */
		}
	if (( mx >= (_Context->x_auto2+360) ) 
	&&  ( my >= (_Context->y_auto2+270) ) 
	&&  ( mx <= (_Context->x_auto2+360+100) ) 
	&&  ( my <= (_Context->y_auto2+270+30))) {
		return(15); /* Select */
		}
	if (( mx >= (_Context->x_auto2+280) ) 
	&&  ( my >= (_Context->y_auto2+255) ) 
	&&  ( mx <= (_Context->x_auto2+280+50) ) 
	&&  ( my <= (_Context->y_auto2+255+50))) {
		return(16); /* auto724 */
		}

	return(-1);
}


public	int	accept_c_production_focus(struct accept_c_production_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x3 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_auto2+20+1,_Context->y_auto2+60+1,560,16,vfh[1],_Context->buffer_FileName,70);
			break;
			case	0x5 :
				/* Identifier */
				_Context->keycode = visual_edit(_Context->x_auto2+20+1,_Context->y_auto2+110+1,560,16,vfh[1],_Context->buffer_Identifier,70);
			break;
			case	0x6 :
				/* IsProgram */
				visual_check(_Context->x_auto2+30,_Context->y_auto2+230,168,16,vfh[2],34,0,_Context->msg_IsProgram[_Context->language],strlen(_Context->msg_IsProgram[_Context->language]),(_Context->value_IsProgram |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+30,_Context->y_auto2+230,168,16,vfh[2],34,0,_Context->msg_IsProgram[_Context->language],strlen(_Context->msg_IsProgram[_Context->language]),(_Context->value_IsProgram |0));
				break;
			case	0x7 :
				/* IsOverlay */
				visual_check(_Context->x_auto2+190,_Context->y_auto2+230,140,16,vfh[2],16,0,_Context->msg_IsOverlay[_Context->language],strlen(_Context->msg_IsOverlay[_Context->language]),(_Context->value_IsOverlay |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+190,_Context->y_auto2+230,140,16,vfh[2],16,0,_Context->msg_IsOverlay[_Context->language],strlen(_Context->msg_IsOverlay[_Context->language]),(_Context->value_IsOverlay |0));
				break;
			case	0x8 :
				/* IsTrueColour */
				visual_check(_Context->x_auto2+340,_Context->y_auto2+230,126,16,vfh[2],16,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),(_Context->value_IsTrueColour |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+340,_Context->y_auto2+230,126,16,vfh[2],16,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),(_Context->value_IsTrueColour |0));
				break;
			case	0x9 :
				/* Accept */
				visual_button(_Context->x_auto2+20,_Context->y_auto2+270,110,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+20,_Context->y_auto2+270,110,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0xa :
				/* Cancel */
				visual_button(_Context->x_auto2+470,_Context->y_auto2+270,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+470,_Context->y_auto2+270,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0xc :
				/* Inclusions */
				_Context->keycode = visual_edit(_Context->x_auto2+20+1,_Context->y_auto2+160+1,560,60,vfh[1],_Context->buffer_Inclusions,210);
			break;
			case	0xd :
				/* Dimensions */
				_Context->keycode = visual_select(_Context->x_auto2+470,_Context->y_auto2+230,104,80,vfh[1],0,0,parse_selection(_Context->msg_Dimensions[_Context->language],&_Context->value_Dimensions),2);
				break;
			case	0xe :
				/* Edit */
				visual_button(_Context->x_auto2+140,_Context->y_auto2+270,110,30,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+140,_Context->y_auto2+270,110,30,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
				break;
			case	0xf :
				/* Select */
				visual_button(_Context->x_auto2+360,_Context->y_auto2+270,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+360,_Context->y_auto2+270,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0x10 :
				/* auto724 */
				_Context->keycode = visual_getch();
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_c_production_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=16;
			accept_c_production_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_c_production_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto2 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x3 :
						/* FileName */
						continue;
					case	0x5 :
						/* Identifier */
						continue;
					case	0x6 :
						/* IsProgram */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsProgram += 1;
							_Context->value_IsProgram &= 1;
							}
						continue;
					case	0x7 :
						/* IsOverlay */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsOverlay += 1;
							_Context->value_IsOverlay &= 1;
							}
						continue;
					case	0x8 :
						/* IsTrueColour */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsTrueColour += 1;
							_Context->value_IsTrueColour &= 1;
							}
						continue;
					case	0x9 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+20,_Context->y_auto2+270,110,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+20,_Context->y_auto2+270,110,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0xa :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+470,_Context->y_auto2+270,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+470,_Context->y_auto2+270,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0xc :
						/* Inclusions */
						continue;
					case	0xd :
						/* Dimensions */
						continue;
					case	0xe :
						/* Edit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+140,_Context->y_auto2+270,110,30,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+140,_Context->y_auto2+270,110,30,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Edit_event(_Context)) != -1) break;

							}
						continue;
					case	0xf :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+360,_Context->y_auto2+270,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+360,_Context->y_auto2+270,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

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
				_Context->focus_item=16;
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

public	int	accept_c_production(
	char * pFileName,
	char * pIdentifier,
	char * pIsProgram,
	char * pIsOverlay,
	char * pIsTrueColour,
	char * pInclusions,
	char * pDimensions)
{
	int	status=0;
	struct accept_c_production_context * _Context=(struct accept_c_production_context*) 0;
	status = accept_c_production_create(
	&_Context,
	 pFileName,
	 pIdentifier,
	 pIsProgram,
	 pIsOverlay,
	 pIsTrueColour,
	 pInclusions,
	 pDimensions);
	if ( status != 0) return(status);
	status = accept_c_production_show(_Context);
		enter_modal();
	status = accept_c_production_focus(_Context);
		leave_modal();
	status = accept_c_production_hide(_Context);
	status = accept_c_production_remove(
	_Context,
	 pFileName,
	 pIdentifier,
	 pIsProgram,
	 pIsOverlay,
	 pIsTrueColour,
	 pInclusions,
	 pDimensions);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcprod_c */
