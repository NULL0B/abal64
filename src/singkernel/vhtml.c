
#ifndef _vhtml_c
#define _vhtml_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vhtml.xml  */
/* Target         : vhtml.c  */
/* Identification : 0.0-1100085327-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_auto113   "Sing : Version 1.0a"
#define fr_auto113   "Sing : Version 1.0a"
#define it_auto113   "Sing : Version 1.0a"
#define es_auto113   "Sing : Version 1.0a"
#define de_auto113   "Sing : Version 1.0a"
#define nl_auto113   "Sing : Version 1.0a"
#define pt_auto113   "Sing : Version 1.0a"
#define xx_auto113   "Sing : Version 1.0a"
#define en_Auto1192   "skin.gif"
#define fr_Auto1192   "skin.gif"
#define it_Auto1192   "skin.gif"
#define es_Auto1192   "skin.gif"
#define de_Auto1192   "skin.gif"
#define nl_Auto1192   "skin.gif"
#define pt_Auto1192   "skin.gif"
#define xx_Auto1192   "skin.gif"
#define en_Auto6297   "Document Production Parameters"
#define fr_Auto6297   "ParamŠtres de Production de Documents"
#define en_auto116   "Title"
#define fr_auto116   "Titre"
#define en_Auto7133   "Path Root"
#define fr_Auto7133   "Chemin"
#define it_Auto7133   ""
#define es_Auto7133   ""
#define de_Auto7133   ""
#define nl_Auto7133   ""
#define pt_Auto7133   ""
#define xx_Auto7133   ""
#define en_auto117   "Screen Style"
#define fr_auto117   "Style Ecran"
#define en_auto118   "Footer"
#define fr_auto118   "Pied de page"
#define en_auto234   "Print Style"
#define fr_auto234   "Style Edition"
#define en_auto233   "Logo"
#define fr_auto233   "Logo"
#define it_auto233   "Logo"
#define es_auto233   "Logo"
#define de_auto233   "Logo"
#define nl_auto233   "Logo"
#define pt_auto233   "Logo"
#define xx_auto233   "Logo"
#define en_Auto535   "htmlicon.gif"
#define fr_Auto535   "htmlicon.gif"
#define it_Auto535   "htmlicon.gif"
#define es_Auto535   "htmlicon.gif"
#define de_Auto535   "htmlicon.gif"
#define nl_Auto535   "htmlicon.gif"
#define pt_Auto535   "htmlicon.gif"
#define xx_Auto535   "htmlicon.gif"
#define en_PathRoot   ""
#define fr_PathRoot   ""
#define en_IsSeparate   "&Separate Page Generation"
#define fr_IsSeparate   "&Pages Indiviudelles"
#define en_ForceLanguage   "&Force Language"
#define fr_ForceLanguage   "&Force Langue"
#define en_IsReport   "&Parts Listing"
#define fr_IsReport   "Liste des &pieces"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
static int	vfh[10];

private struct accept_document_parameters_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto113[8];
	int	x_auto113;
	int	y_auto113;
	int	w_auto113;
	int	h_auto113;
	char * msg_Auto1192[8];
	char * msg_Auto6297[8];
	char * msg_auto116[8];
	char * msg_Auto7133[8];
	char * msg_auto117[8];
	char * msg_auto118[8];
	char * msg_auto234[8];
	char * msg_auto233[8];
	char * msg_Auto535[8];
	char	buffer_TitleHeading[123];
	char	buffer_PathRoot[62];
	char	buffer_ScreenStyle[62];
	char	buffer_PrintStyle[62];
	char	buffer_Logo[62];
	char	buffer_FooterCopyright[123];
	char * msg_IsSeparate[8];
	int	trigger_IsSeparate;
	int	value_IsSeparate;
	char * msg_ForceLanguage[8];
	int	trigger_ForceLanguage;
	int	value_ForceLanguage;
	char * msg_NationalLanguage[8];
	int	value_NationalLanguage;
	char * msg_IsReport[8];
	int	trigger_IsReport;
	int	value_IsReport;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[11];
	};

public	int	accept_document_parameters_create(
	struct accept_document_parameters_context ** cptr,
	char * pTitleHeading,
	char * pPathRoot,
	char * pScreenStyle,
	char * pPrintStyle,
	char * pLogo,
	char * pFooterCopyright,
	char * pIsSeparate,
	char * pForceLanguage,
	char * pNationalLanguage,
	char * pIsReport)
{

	int i;
	struct accept_document_parameters_context * _Context=(struct accept_document_parameters_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_document_parameters_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=13;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_TitleHeading, 122, pTitleHeading);
		visual_transferin(_Context->buffer_PathRoot, 61, pPathRoot);
		visual_transferin(_Context->buffer_ScreenStyle, 61, pScreenStyle);
		visual_transferin(_Context->buffer_PrintStyle, 61, pPrintStyle);
		visual_transferin(_Context->buffer_Logo, 61, pLogo);
		visual_transferin(_Context->buffer_FooterCopyright, 122, pFooterCopyright);
		visual_transferin((void *) 0, 0, pIsSeparate);
		if (!( pIsSeparate )) _Context->value_IsSeparate=0;
		else	_Context->value_IsSeparate = *((int *)pIsSeparate);
		visual_transferin((void *) 0, 0, pForceLanguage);
		if (!( pForceLanguage )) _Context->value_ForceLanguage=0;
		else	_Context->value_ForceLanguage = *((int *)pForceLanguage);
		visual_transferin((void *) 0, 0, pNationalLanguage);
		if (!( pNationalLanguage )) _Context->value_NationalLanguage=0;
		else	_Context->value_NationalLanguage = *((int *)pNationalLanguage);
		visual_transferin((void *) 0, 0, pIsReport);
		if (!( pIsReport )) _Context->value_IsReport=0;
		else	_Context->value_IsReport = *((int *)pIsReport);
		}
	for (i=0; i < 8; i++)_Context->msg_auto113[i]=" ";
	_Context->msg_auto113[0]=en_auto113;
	_Context->msg_auto113[1]=fr_auto113;
	_Context->msg_auto113[2]=it_auto113;
	_Context->msg_auto113[3]=es_auto113;
	_Context->msg_auto113[4]=de_auto113;
	_Context->msg_auto113[5]=nl_auto113;
	_Context->msg_auto113[6]=pt_auto113;
	_Context->msg_auto113[7]=xx_auto113;
	_Context->x_auto113=90;
	_Context->y_auto113=105;
	_Context->w_auto113=620;
	_Context->h_auto113=390;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1192[i]=" ";
	_Context->msg_Auto1192[0]=en_Auto1192;
	_Context->msg_Auto1192[1]=fr_Auto1192;
	_Context->msg_Auto1192[2]=it_Auto1192;
	_Context->msg_Auto1192[3]=es_Auto1192;
	_Context->msg_Auto1192[4]=de_Auto1192;
	_Context->msg_Auto1192[5]=nl_Auto1192;
	_Context->msg_Auto1192[6]=pt_Auto1192;
	_Context->msg_Auto1192[7]=xx_Auto1192;
	for (i=0; i < 8; i++)_Context->msg_Auto6297[i]=" ";
	_Context->msg_Auto6297[0]=en_Auto6297;
	_Context->msg_Auto6297[1]=fr_Auto6297;
	for (i=0; i < 8; i++)_Context->msg_auto116[i]=" ";
	_Context->msg_auto116[0]=en_auto116;
	_Context->msg_auto116[1]=fr_auto116;
	for (i=0; i < 8; i++)_Context->msg_Auto7133[i]=" ";
	_Context->msg_Auto7133[0]=en_Auto7133;
	_Context->msg_Auto7133[1]=fr_Auto7133;
	_Context->msg_Auto7133[2]=it_Auto7133;
	_Context->msg_Auto7133[3]=es_Auto7133;
	_Context->msg_Auto7133[4]=de_Auto7133;
	_Context->msg_Auto7133[5]=nl_Auto7133;
	_Context->msg_Auto7133[6]=pt_Auto7133;
	_Context->msg_Auto7133[7]=xx_Auto7133;
	for (i=0; i < 8; i++)_Context->msg_auto117[i]=" ";
	_Context->msg_auto117[0]=en_auto117;
	_Context->msg_auto117[1]=fr_auto117;
	for (i=0; i < 8; i++)_Context->msg_auto118[i]=" ";
	_Context->msg_auto118[0]=en_auto118;
	_Context->msg_auto118[1]=fr_auto118;
	for (i=0; i < 8; i++)_Context->msg_auto234[i]=" ";
	_Context->msg_auto234[0]=en_auto234;
	_Context->msg_auto234[1]=fr_auto234;
	for (i=0; i < 8; i++)_Context->msg_auto233[i]=" ";
	_Context->msg_auto233[0]=en_auto233;
	_Context->msg_auto233[1]=fr_auto233;
	_Context->msg_auto233[2]=it_auto233;
	_Context->msg_auto233[3]=es_auto233;
	_Context->msg_auto233[4]=de_auto233;
	_Context->msg_auto233[5]=nl_auto233;
	_Context->msg_auto233[6]=pt_auto233;
	_Context->msg_auto233[7]=xx_auto233;
	for (i=0; i < 8; i++)_Context->msg_Auto535[i]=" ";
	_Context->msg_Auto535[0]=en_Auto535;
	_Context->msg_Auto535[1]=fr_Auto535;
	_Context->msg_Auto535[2]=it_Auto535;
	_Context->msg_Auto535[3]=es_Auto535;
	_Context->msg_Auto535[4]=de_Auto535;
	_Context->msg_Auto535[5]=nl_Auto535;
	_Context->msg_Auto535[6]=pt_Auto535;
	_Context->msg_Auto535[7]=xx_Auto535;
	for (i=0; i < 8; i++)_Context->msg_IsSeparate[i]=" ";
	_Context->msg_IsSeparate[0]=en_IsSeparate;
	_Context->msg_IsSeparate[1]=fr_IsSeparate;
	for (i=0; i < 8; i++)_Context->msg_ForceLanguage[i]=" ";
	_Context->msg_ForceLanguage[0]=en_ForceLanguage;
	_Context->msg_ForceLanguage[1]=fr_ForceLanguage;
	for (i=0; i < 8; i++)_Context->msg_NationalLanguage[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_IsReport[i]=" ";
	_Context->msg_IsReport[0]=en_IsReport;
	_Context->msg_IsReport[1]=fr_IsReport;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto113,_Context->y_auto113,620+10,390+10);
	return(0);
}

public 	int	accept_document_parameters_hide(struct accept_document_parameters_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto113,_Context->y_auto113);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_document_parameters_remove(
	struct accept_document_parameters_context * _Context,
	char * pTitleHeading,
	char * pPathRoot,
	char * pScreenStyle,
	char * pPrintStyle,
	char * pLogo,
	char * pFooterCopyright,
	char * pIsSeparate,
	char * pForceLanguage,
	char * pNationalLanguage,
	char * pIsReport)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_TitleHeading, 122, pTitleHeading);
		visual_transferout(_Context->buffer_PathRoot, 61, pPathRoot);
		visual_transferout(_Context->buffer_ScreenStyle, 61, pScreenStyle);
		visual_transferout(_Context->buffer_PrintStyle, 61, pPrintStyle);
		visual_transferout(_Context->buffer_Logo, 61, pLogo);
		visual_transferout(_Context->buffer_FooterCopyright, 122, pFooterCopyright);
		visual_transferout((void *) 0, 0, pIsSeparate);
		if ( pIsSeparate != (char *) 0)
			*((int*)pIsSeparate) = _Context->value_IsSeparate;
		visual_transferout((void *) 0, 0, pForceLanguage);
		if ( pForceLanguage != (char *) 0)
			*((int*)pForceLanguage) = _Context->value_ForceLanguage;
		visual_transferout((void *) 0, 0, pNationalLanguage);
		if ( pNationalLanguage != (char *) 0)
			*((int*)pNationalLanguage) = _Context->value_NationalLanguage;
		visual_transferout((void *) 0, 0, pIsReport);
		if ( pIsReport != (char *) 0)
			*((int*)pIsReport) = _Context->value_IsReport;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_document_parameters_show(struct accept_document_parameters_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto113,_Context->y_auto113);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_auto113,_Context->y_auto113,620,390,vfh[2],_Context->msg_auto113[_Context->language],strlen(_Context->msg_auto113[_Context->language]),0x407);
	visual_image(_Context->x_auto113+4,_Context->y_auto113+22,612,364,_Context->msg_Auto1192[_Context->language],4);
	visual_text(_Context->x_auto113+40,_Context->y_auto113+40,513,24,vfh[5],16,0,_Context->msg_Auto6297[_Context->language],strlen(_Context->msg_Auto6297[_Context->language]),1283);
	visual_text(_Context->x_auto113+20,_Context->y_auto113+90,84,32,vfh[2],27,0,_Context->msg_auto116[_Context->language],strlen(_Context->msg_auto116[_Context->language]),258);
	visual_text(_Context->x_auto113+20,_Context->y_auto113+130,70,16,vfh[2],27,0,_Context->msg_Auto7133[_Context->language],strlen(_Context->msg_Auto7133[_Context->language]),258);
	visual_text(_Context->x_auto113+20,_Context->y_auto113+160,84,16,vfh[2],27,0,_Context->msg_auto117[_Context->language],strlen(_Context->msg_auto117[_Context->language]),258);
	visual_text(_Context->x_auto113+20,_Context->y_auto113+230,84,32,vfh[2],27,0,_Context->msg_auto118[_Context->language],strlen(_Context->msg_auto118[_Context->language]),258);
	visual_text(_Context->x_auto113+20,_Context->y_auto113+180,84,16,vfh[2],27,0,_Context->msg_auto234[_Context->language],strlen(_Context->msg_auto234[_Context->language]),258);
	visual_text(_Context->x_auto113+20,_Context->y_auto113+200,84,16,vfh[2],27,0,_Context->msg_auto233[_Context->language],strlen(_Context->msg_auto233[_Context->language]),258);
	visual_image(_Context->x_auto113+550,_Context->y_auto113+30,50,50,_Context->msg_Auto535[_Context->language],0);
	visual_frame(_Context->x_auto113+110,_Context->y_auto113+90,488+2,32+2,5);
	visual_text(_Context->x_auto113+110+1,_Context->y_auto113+90+1,488,32,vfh[1],27,0,_Context->buffer_TitleHeading,122,0);
	visual_frame(_Context->x_auto113+110,_Context->y_auto113+130,488+2,16+2,5);
	visual_text(_Context->x_auto113+110+1,_Context->y_auto113+130+1,488,16,vfh[1],0,0,_Context->buffer_PathRoot,61,0);
	visual_frame(_Context->x_auto113+110,_Context->y_auto113+160,488+2,16+2,5);
	visual_text(_Context->x_auto113+110+1,_Context->y_auto113+160+1,488,16,vfh[1],27,0,_Context->buffer_ScreenStyle,61,0);
	visual_frame(_Context->x_auto113+110,_Context->y_auto113+180,488+2,16+2,5);
	visual_text(_Context->x_auto113+110+1,_Context->y_auto113+180+1,488,16,vfh[1],0,0,_Context->buffer_PrintStyle,61,0);
	visual_frame(_Context->x_auto113+110,_Context->y_auto113+200,488+2,16+2,5);
	visual_text(_Context->x_auto113+110+1,_Context->y_auto113+200+1,488,16,vfh[1],27,0,_Context->buffer_Logo,61,0);
	visual_frame(_Context->x_auto113+110,_Context->y_auto113+230,488+2,32+2,5);
	visual_text(_Context->x_auto113+110+1,_Context->y_auto113+230+1,488,32,vfh[1],27,0,_Context->buffer_FooterCopyright,122,0);
	_Context->trigger_IsSeparate=visual_trigger_code(_Context->msg_IsSeparate[_Context->language],strlen(_Context->msg_IsSeparate[_Context->language]));
	visual_check(_Context->x_auto113+20,_Context->y_auto113+280,224,16,vfh[2],27,0,_Context->msg_IsSeparate[_Context->language],strlen(_Context->msg_IsSeparate[_Context->language]),_Context->value_IsSeparate|0);
	_Context->trigger_ForceLanguage=visual_trigger_code(_Context->msg_ForceLanguage[_Context->language],strlen(_Context->msg_ForceLanguage[_Context->language]));
	visual_check(_Context->x_auto113+240,_Context->y_auto113+280,154,16,vfh[2],28,28,_Context->msg_ForceLanguage[_Context->language],strlen(_Context->msg_ForceLanguage[_Context->language]),_Context->value_ForceLanguage|0);
	visual_select(_Context->x_auto113+240,_Context->y_auto113+310,140,80,vfh[2],27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),768);
	_Context->trigger_IsReport=visual_trigger_code(_Context->msg_IsReport[_Context->language],strlen(_Context->msg_IsReport[_Context->language]));
	visual_check(_Context->x_auto113+450,_Context->y_auto113+280,154,16,vfh[2],27,0,_Context->msg_IsReport[_Context->language],strlen(_Context->msg_IsReport[_Context->language]),_Context->value_IsReport|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto113+30,_Context->y_auto113+330,130,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto113+450,_Context->y_auto113+330,130,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_thaw(_Context->x_auto113,_Context->y_auto113,620,390);
	visual_thaw(_Context->x_auto113,_Context->y_auto113,620,390);

	return(0);
}

private int auto113action(struct accept_document_parameters_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_document_parameters_hide(_Context);

		_Context->x_auto113 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto113 < 0) { _Context->x_auto113=0; }
		_Context->y_auto113 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto113 < 0) { _Context->y_auto113=0; }
			accept_document_parameters_show(_Context);

		visual_thaw(_Context->x_auto113,_Context->y_auto113,620,390);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_document_parameters_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_document_parameters_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_document_parameters_event(
struct accept_document_parameters_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsSeparate == mb ) return(8);
		if (_Context->trigger_ForceLanguage == mb ) return(9);
		if (_Context->trigger_IsReport == mb ) return(11);
		if (_Context->trigger_Accept == mb ) return(12);
		if (_Context->trigger_Cancel == mb ) return(13);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto113+599) )  
	&&  (my >= (_Context->y_auto113+4) )  
	&&  (mx <= (_Context->x_auto113+616) )  
	&&  (my <= (_Context->y_auto113+20) )) {
		return(1);	/* auto113 */

		}
	if ((mx >= (_Context->x_auto113+583) )  
	&&  (my >= (_Context->y_auto113+4) )  
	&&  (mx <= (_Context->x_auto113+600) )  
	&&  (my <= (_Context->y_auto113+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vhtml.htm");
			};
		return(-1);	/* auto113 */

		}
	if ((mx >= (_Context->x_auto113+567) )  
	&&  (my >= (_Context->y_auto113+4) )  
	&&  (mx <= (_Context->x_auto113+584) )  
	&&  (my <= (_Context->y_auto113+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_document_parameters_show(_Context);
		return(-1);	/* auto113 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto113+4) )  
		&&  (my >= (_Context->y_auto113+4) )  
		&&  (mx <= (_Context->x_auto113+552) )  
		&&  (my <= (_Context->y_auto113+20) )) {
			return( auto113action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto113+110) ) 
	&&  ( my >= (_Context->y_auto113+90) ) 
	&&  ( mx <= (_Context->x_auto113+110+488) ) 
	&&  ( my <= (_Context->y_auto113+90+32))) {
		return(2); /* TitleHeading */
		}
	if (( mx >= (_Context->x_auto113+110) ) 
	&&  ( my >= (_Context->y_auto113+130) ) 
	&&  ( mx <= (_Context->x_auto113+110+488) ) 
	&&  ( my <= (_Context->y_auto113+130+16))) {
		return(3); /* PathRoot */
		}
	if (( mx >= (_Context->x_auto113+110) ) 
	&&  ( my >= (_Context->y_auto113+160) ) 
	&&  ( mx <= (_Context->x_auto113+110+488) ) 
	&&  ( my <= (_Context->y_auto113+160+16))) {
		return(4); /* ScreenStyle */
		}
	if (( mx >= (_Context->x_auto113+110) ) 
	&&  ( my >= (_Context->y_auto113+180) ) 
	&&  ( mx <= (_Context->x_auto113+110+488) ) 
	&&  ( my <= (_Context->y_auto113+180+16))) {
		return(5); /* PrintStyle */
		}
	if (( mx >= (_Context->x_auto113+110) ) 
	&&  ( my >= (_Context->y_auto113+200) ) 
	&&  ( mx <= (_Context->x_auto113+110+488) ) 
	&&  ( my <= (_Context->y_auto113+200+16))) {
		return(6); /* Logo */
		}
	if (( mx >= (_Context->x_auto113+110) ) 
	&&  ( my >= (_Context->y_auto113+230) ) 
	&&  ( mx <= (_Context->x_auto113+110+488) ) 
	&&  ( my <= (_Context->y_auto113+230+32))) {
		return(7); /* FooterCopyright */
		}
	if (( mx >= (_Context->x_auto113+20) ) 
	&&  ( my >= (_Context->y_auto113+280) ) 
	&&  ( mx <= (_Context->x_auto113+20+224) ) 
	&&  ( my <= (_Context->y_auto113+280+16))) {
		return(8); /* IsSeparate */
		}
	if (( mx >= (_Context->x_auto113+240) ) 
	&&  ( my >= (_Context->y_auto113+280) ) 
	&&  ( mx <= (_Context->x_auto113+240+154) ) 
	&&  ( my <= (_Context->y_auto113+280+16))) {
		return(9); /* ForceLanguage */
		}
	if (( mx >= (_Context->x_auto113+240+0) ) 
	&&  ( my >= (_Context->y_auto113+310) ) 
	&&  ( mx <= (_Context->x_auto113+240+140) ) 
	&&  ( my <= (_Context->y_auto113+310+16))) {
		return(10); /* NationalLanguage */
		}
	if (( mx >= (_Context->x_auto113+450) ) 
	&&  ( my >= (_Context->y_auto113+280) ) 
	&&  ( mx <= (_Context->x_auto113+450+154) ) 
	&&  ( my <= (_Context->y_auto113+280+16))) {
		return(11); /* IsReport */
		}
	if (( mx >= (_Context->x_auto113+30) ) 
	&&  ( my >= (_Context->y_auto113+330) ) 
	&&  ( mx <= (_Context->x_auto113+30+130) ) 
	&&  ( my <= (_Context->y_auto113+330+30))) {
		return(12); /* Accept */
		}
	if (( mx >= (_Context->x_auto113+450) ) 
	&&  ( my >= (_Context->y_auto113+330) ) 
	&&  ( mx <= (_Context->x_auto113+450+130) ) 
	&&  ( my <= (_Context->y_auto113+330+30))) {
		return(13); /* Cancel */
		}

	return(-1);
}


public	int	accept_document_parameters_focus(struct accept_document_parameters_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* TitleHeading */
				_Context->keycode = visual_edit(_Context->x_auto113+110+1,_Context->y_auto113+90+1,488,32,vfh[1],_Context->buffer_TitleHeading,122);
			break;
			case	0x3 :
				/* PathRoot */
				_Context->keycode = visual_edit(_Context->x_auto113+110+1,_Context->y_auto113+130+1,488,16,vfh[1],_Context->buffer_PathRoot,61);
			break;
			case	0x4 :
				/* ScreenStyle */
				_Context->keycode = visual_edit(_Context->x_auto113+110+1,_Context->y_auto113+160+1,488,16,vfh[1],_Context->buffer_ScreenStyle,61);
			break;
			case	0x5 :
				/* PrintStyle */
				_Context->keycode = visual_edit(_Context->x_auto113+110+1,_Context->y_auto113+180+1,488,16,vfh[1],_Context->buffer_PrintStyle,61);
			break;
			case	0x6 :
				/* Logo */
				_Context->keycode = visual_edit(_Context->x_auto113+110+1,_Context->y_auto113+200+1,488,16,vfh[1],_Context->buffer_Logo,61);
			break;
			case	0x7 :
				/* FooterCopyright */
				_Context->keycode = visual_edit(_Context->x_auto113+110+1,_Context->y_auto113+230+1,488,32,vfh[1],_Context->buffer_FooterCopyright,122);
			break;
			case	0x8 :
				/* IsSeparate */
				visual_check(_Context->x_auto113+20,_Context->y_auto113+280,224,16,vfh[2],27,0,_Context->msg_IsSeparate[_Context->language],strlen(_Context->msg_IsSeparate[_Context->language]),(_Context->value_IsSeparate |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto113+20,_Context->y_auto113+280,224,16,vfh[2],27,0,_Context->msg_IsSeparate[_Context->language],strlen(_Context->msg_IsSeparate[_Context->language]),(_Context->value_IsSeparate |0));
				break;
			case	0x9 :
				/* ForceLanguage */
				visual_check(_Context->x_auto113+240,_Context->y_auto113+280,154,16,vfh[2],28,28,_Context->msg_ForceLanguage[_Context->language],strlen(_Context->msg_ForceLanguage[_Context->language]),(_Context->value_ForceLanguage |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto113+240,_Context->y_auto113+280,154,16,vfh[2],28,28,_Context->msg_ForceLanguage[_Context->language],strlen(_Context->msg_ForceLanguage[_Context->language]),(_Context->value_ForceLanguage |0));
				break;
			case	0xa :
				/* NationalLanguage */
				_Context->keycode = visual_select(_Context->x_auto113+240,_Context->y_auto113+310,140,80,vfh[2],27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),770);
				break;
			case	0xb :
				/* IsReport */
				visual_check(_Context->x_auto113+450,_Context->y_auto113+280,154,16,vfh[2],27,0,_Context->msg_IsReport[_Context->language],strlen(_Context->msg_IsReport[_Context->language]),(_Context->value_IsReport |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto113+450,_Context->y_auto113+280,154,16,vfh[2],27,0,_Context->msg_IsReport[_Context->language],strlen(_Context->msg_IsReport[_Context->language]),(_Context->value_IsReport |0));
				break;
			case	0xc :
				/* Accept */
				visual_button(_Context->x_auto113+30,_Context->y_auto113+330,130,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto113+30,_Context->y_auto113+330,130,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0xd :
				/* Cancel */
				visual_button(_Context->x_auto113+450,_Context->y_auto113+330,130,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto113+450,_Context->y_auto113+330,130,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_document_parameters_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=13;
			accept_document_parameters_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_document_parameters_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto113 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* TitleHeading */
						continue;
					case	0x3 :
						/* PathRoot */
						continue;
					case	0x4 :
						/* ScreenStyle */
						continue;
					case	0x5 :
						/* PrintStyle */
						continue;
					case	0x6 :
						/* Logo */
						continue;
					case	0x7 :
						/* FooterCopyright */
						continue;
					case	0x8 :
						/* IsSeparate */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsSeparate += 1;
							_Context->value_IsSeparate &= 1;
							}
						continue;
					case	0x9 :
						/* ForceLanguage */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_ForceLanguage += 1;
							_Context->value_ForceLanguage &= 1;
							}
						continue;
					case	0xa :
						/* NationalLanguage */
						continue;
					case	0xb :
						/* IsReport */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsReport += 1;
							_Context->value_IsReport &= 1;
							}
						continue;
					case	0xc :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto113+30,_Context->y_auto113+330,130,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto113+30,_Context->y_auto113+330,130,30,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0xd :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto113+450,_Context->y_auto113+330,130,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto113+450,_Context->y_auto113+330,130,30,vfh[2],27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
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

public	int	accept_document_parameters(
	char * pTitleHeading,
	char * pPathRoot,
	char * pScreenStyle,
	char * pPrintStyle,
	char * pLogo,
	char * pFooterCopyright,
	char * pIsSeparate,
	char * pForceLanguage,
	char * pNationalLanguage,
	char * pIsReport)
{
	int	status=0;
	struct accept_document_parameters_context * _Context=(struct accept_document_parameters_context*) 0;
	status = accept_document_parameters_create(
	&_Context,
	 pTitleHeading,
	 pPathRoot,
	 pScreenStyle,
	 pPrintStyle,
	 pLogo,
	 pFooterCopyright,
	 pIsSeparate,
	 pForceLanguage,
	 pNationalLanguage,
	 pIsReport);
	if ( status != 0) return(status);
	status = accept_document_parameters_show(_Context);
		enter_modal();
	status = accept_document_parameters_focus(_Context);
		leave_modal();
	status = accept_document_parameters_hide(_Context);
	status = accept_document_parameters_remove(
	_Context,
	 pTitleHeading,
	 pPathRoot,
	 pScreenStyle,
	 pPrintStyle,
	 pLogo,
	 pFooterCopyright,
	 pIsSeparate,
	 pForceLanguage,
	 pNationalLanguage,
	 pIsReport);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vhtml_c */
