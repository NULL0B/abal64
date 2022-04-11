
#ifndef _vhtml_c
#define _vhtml_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.09  */
/* Production     : C  */
/* Project        : vhtml.sng  */
/* Target         : vhtml.c  */
/* Identification : 0.0-1068938901-4381.4367 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
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
#define fr_Auto7133   "Titre"
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
#define en_IsSeparate   "&Separate Page Generation"
#define fr_IsSeparate   "&Pages Indiviudelles"
#define en_ForceLanguage   "&Force Language"
#define fr_ForceLanguage   "&Force Langue"
#define en_IsReport   "&Parts Listing"
#define fr_IsReport   "Liste des &pieces"
#define en_Accept   "&Accept"
#define en_Cancel   "&Cancel"

private struct accept_document_parameters_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto113[8];
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
	char	signature[9];
	} * _Context;

private	int	accept_document_parameters_create(
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
	if (!(_Context = allocate( sizeof( struct accept_document_parameters_context ) ) ))
		return(27);
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=13;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSWW");
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
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(90,105,620+10,390+10);
	return(0);
}

private	int	accept_document_parameters_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,90,105);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_document_parameters_remove(
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

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSWW");
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

private	int	accept_document_parameters_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,90,105);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(90,105,620,390,2,_Context->msg_auto113[_Context->language],strlen(_Context->msg_auto113[_Context->language]),0x407);
	visual_image(94,127,612,364,_Context->msg_Auto1192[_Context->language],4);
	visual_text(130,145,513,24,5,16,0,_Context->msg_Auto6297[_Context->language],strlen(_Context->msg_Auto6297[_Context->language]),1283);
	visual_text(110,195,84,32,2,27,0,_Context->msg_auto116[_Context->language],strlen(_Context->msg_auto116[_Context->language]),258);
	visual_text(110,235,70,16,2,27,0,_Context->msg_Auto7133[_Context->language],strlen(_Context->msg_Auto7133[_Context->language]),258);
	visual_text(110,265,84,16,2,27,0,_Context->msg_auto117[_Context->language],strlen(_Context->msg_auto117[_Context->language]),258);
	visual_text(110,335,84,32,2,27,0,_Context->msg_auto118[_Context->language],strlen(_Context->msg_auto118[_Context->language]),258);
	visual_text(110,285,84,16,2,27,0,_Context->msg_auto234[_Context->language],strlen(_Context->msg_auto234[_Context->language]),258);
	visual_text(110,305,84,16,2,27,0,_Context->msg_auto233[_Context->language],strlen(_Context->msg_auto233[_Context->language]),258);
	visual_image(640,135,50,50,_Context->msg_Auto535[_Context->language],0);
	visual_frame(200,195,488+2,32+2,5);
	visual_text(200+1,195+1,488,32,1,27,0,_Context->buffer_TitleHeading,122,0);
	visual_frame(200,235,488+2,16+2,5);
	visual_text(200+1,235+1,488,16,1,0,0,_Context->buffer_PathRoot,61,0);
	visual_frame(200,265,488+2,16+2,5);
	visual_text(200+1,265+1,488,16,1,27,0,_Context->buffer_ScreenStyle,61,0);
	visual_frame(200,285,488+2,16+2,5);
	visual_text(200+1,285+1,488,16,1,0,0,_Context->buffer_PrintStyle,61,0);
	visual_frame(200,305,488+2,16+2,5);
	visual_text(200+1,305+1,488,16,1,27,0,_Context->buffer_Logo,61,0);
	visual_frame(200,335,488+2,32+2,5);
	visual_text(200+1,335+1,488,32,1,27,0,_Context->buffer_FooterCopyright,122,0);
	_Context->trigger_IsSeparate=visual_trigger_code(_Context->msg_IsSeparate[_Context->language],strlen(_Context->msg_IsSeparate[_Context->language]));
	visual_check(110,385,224,16,2,27,0,_Context->msg_IsSeparate[_Context->language],strlen(_Context->msg_IsSeparate[_Context->language]),_Context->value_IsSeparate|0);
	_Context->trigger_ForceLanguage=visual_trigger_code(_Context->msg_ForceLanguage[_Context->language],strlen(_Context->msg_ForceLanguage[_Context->language]));
	visual_check(330,385,154,16,2,28,28,_Context->msg_ForceLanguage[_Context->language],strlen(_Context->msg_ForceLanguage[_Context->language]),_Context->value_ForceLanguage|0);
	visual_select(330,415,140,80,2,27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),768);
	_Context->trigger_IsReport=visual_trigger_code(_Context->msg_IsReport[_Context->language],strlen(_Context->msg_IsReport[_Context->language]));
	visual_check(540,385,154,16,2,27,0,_Context->msg_IsReport[_Context->language],strlen(_Context->msg_IsReport[_Context->language]),_Context->value_IsReport|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(120,435,130,30,2,27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(540,435,130,30,2,27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_thaw(90,105,620,390);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	accept_document_parameters_event()
{
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
	if (mt & _MIMO_UP) {
	if ((mx >= 689 )  
	&&  (my >= 109 )  
	&&  (mx <= 705 )  
	&&  (my <= 125 )) {
		return(1);	/* auto113 */

		}
	if ((mx >= 673 )  
	&&  (my >= 109 )  
	&&  (mx <= 689 )  
	&&  (my <= 125 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vhtml.htm");
			};
		return(-1);	/* auto113 */

		}
	if ((mx >= 657 )  
	&&  (my >= 109 )  
	&&  (mx <= 673 )  
	&&  (my <= 125 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		_Context->language--; _Context->language %=8;
			}
		(void) visual_national_language(_Context->language);
		accept_document_parameters_show();
		return(-1);	/* auto113 */

		}
		}
	if (( mx >= 200 ) 
	&&  ( my >= 195 ) 
	&&  ( mx <= 688 ) 
	&&  ( my <= 227 )) {
		return(2); /* TitleHeading */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 235 ) 
	&&  ( mx <= 688 ) 
	&&  ( my <= 251 )) {
		return(3); /* PathRoot */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 265 ) 
	&&  ( mx <= 688 ) 
	&&  ( my <= 281 )) {
		return(4); /* ScreenStyle */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 285 ) 
	&&  ( mx <= 688 ) 
	&&  ( my <= 301 )) {
		return(5); /* PrintStyle */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 305 ) 
	&&  ( mx <= 688 ) 
	&&  ( my <= 321 )) {
		return(6); /* Logo */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 335 ) 
	&&  ( mx <= 688 ) 
	&&  ( my <= 367 )) {
		return(7); /* FooterCopyright */
		}
	if (( mx >= 110 ) 
	&&  ( my >= 385 ) 
	&&  ( mx <= 334 ) 
	&&  ( my <= 401 )) {
		return(8); /* IsSeparate */
		}
	if (( mx >= 330 ) 
	&&  ( my >= 385 ) 
	&&  ( mx <= 484 ) 
	&&  ( my <= 401 )) {
		return(9); /* ForceLanguage */
		}
	if ((mx >= 330 ) 
	&&  (my >= 415 ) 
	&&  (mx <= 470 ) 
	&&  (my <= 431 )) {
		return(10); /* NationalLanguage */
		}
	if (( mx >= 540 ) 
	&&  ( my >= 385 ) 
	&&  ( mx <= 694 ) 
	&&  ( my <= 401 )) {
		return(11); /* IsReport */
		}
	if (( mx >= 120 ) 
	&&  ( my >= 435 ) 
	&&  ( mx <= 250 ) 
	&&  ( my <= 465 )) {
		return(12); /* Accept */
		}
	if (( mx >= 540 ) 
	&&  ( my >= 435 ) 
	&&  ( mx <= 670 ) 
	&&  ( my <= 465 )) {
		return(13); /* Cancel */
		}

	return(-1);
}


private	int	accept_document_parameters_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* TitleHeading */
				_Context->keycode = visual_edit(200+1,195+1,488,32,1,_Context->buffer_TitleHeading,122);
				break;
			case	0x3 :
				/* PathRoot */
				_Context->keycode = visual_edit(200+1,235+1,488,16,1,_Context->buffer_PathRoot,61);
				break;
			case	0x4 :
				/* ScreenStyle */
				_Context->keycode = visual_edit(200+1,265+1,488,16,1,_Context->buffer_ScreenStyle,61);
				break;
			case	0x5 :
				/* PrintStyle */
				_Context->keycode = visual_edit(200+1,285+1,488,16,1,_Context->buffer_PrintStyle,61);
				break;
			case	0x6 :
				/* Logo */
				_Context->keycode = visual_edit(200+1,305+1,488,16,1,_Context->buffer_Logo,61);
				break;
			case	0x7 :
				/* FooterCopyright */
				_Context->keycode = visual_edit(200+1,335+1,488,32,1,_Context->buffer_FooterCopyright,122);
				break;
			case	0x8 :
				/* IsSeparate */
				visual_check(110,385,224,16,2,27,0,_Context->msg_IsSeparate[_Context->language],strlen(_Context->msg_IsSeparate[_Context->language]),(_Context->value_IsSeparate |2));
				_Context->keycode = visual_getch();
				visual_check(110,385,224,16,2,27,0,_Context->msg_IsSeparate[_Context->language],strlen(_Context->msg_IsSeparate[_Context->language]),(_Context->value_IsSeparate |0));
				break;
			case	0x9 :
				/* ForceLanguage */
				visual_check(330,385,154,16,2,28,28,_Context->msg_ForceLanguage[_Context->language],strlen(_Context->msg_ForceLanguage[_Context->language]),(_Context->value_ForceLanguage |2));
				_Context->keycode = visual_getch();
				visual_check(330,385,154,16,2,28,28,_Context->msg_ForceLanguage[_Context->language],strlen(_Context->msg_ForceLanguage[_Context->language]),(_Context->value_ForceLanguage |0));
				break;
			case	0xa :
				/* NationalLanguage */
				_Context->keycode = visual_select(330,415,140,80,2,27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),770);
				break;
			case	0xb :
				/* IsReport */
				visual_check(540,385,154,16,2,27,0,_Context->msg_IsReport[_Context->language],strlen(_Context->msg_IsReport[_Context->language]),(_Context->value_IsReport |2));
				_Context->keycode = visual_getch();
				visual_check(540,385,154,16,2,27,0,_Context->msg_IsReport[_Context->language],strlen(_Context->msg_IsReport[_Context->language]),(_Context->value_IsReport |0));
				break;
			case	0xc :
				/* Accept */
				visual_button(120,435,130,30,2,27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(120,435,130,30,2,27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0xd :
				/* Cancel */
				visual_button(540,435,130,30,2,27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(540,435,130,30,2,27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_document_parameters_show();
			continue;
		case	0x2 :
			_Context->focus_item=13;
			accept_document_parameters_show();
			continue;
			case	0x100 :
				if ((retcode=accept_document_parameters_event()) == -1)
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
							visual_button(120,435,130,30,2,27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(120,435,130,30,2,27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0xd :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(540,435,130,30,2,27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(540,435,130,30,2,27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

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
	status = accept_document_parameters_create(
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
	status = accept_document_parameters_show();
		enter_modal();
	status = accept_document_parameters_focus();
		leave_modal();
	status = accept_document_parameters_hide();
	status = accept_document_parameters_remove(
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
