
#ifndef _vform_c
#define _vform_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.14  */
/* Production     : C  */
/* Project        : vform.xml  */
/* Target         : vform.c  */
/* Identification : 0.0-1070655382-2299.2201 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto702   "Sing : Version 1.0a"
#define fr_Auto702   "Sing : Version 1.0a"
#define it_Auto702   "Sing : Version 1.0a"
#define es_Auto702   "Sing : Version 1.0a"
#define de_Auto702   "Sing : Version 1.0a"
#define nl_Auto702   "Sing : Version 1.0a"
#define pt_Auto702   "Sing : Version 1.0a"
#define xx_Auto702   "Sing : Version 1.0a"
#define en_Auto413   "skin.gif"
#define fr_Auto413   "skin.gif"
#define it_Auto413   "skin.gif"
#define es_Auto413   "skin.gif"
#define de_Auto413   "skin.gif"
#define nl_Auto413   "skin.gif"
#define pt_Auto413   "skin.gif"
#define xx_Auto413   "skin.gif"
#define en_FormControl   "&Form Properties"
#define fr_FormControl   "&Formulaire"
#define it_FormControl   ""
#define es_FormControl   ""
#define de_FormControl   ""
#define nl_FormControl   ""
#define pt_FormControl   ""
#define xx_FormControl   ""
#define en_Auto7156   "Production Control"
#define en_Auto1270   "Code Production Options"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_EditMethod   "E&dit Method"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
#define en_Auto706   "Production Nature"
#define en_Auto710   "Production Language"
#define en_Auto2085   "National Language"
#define en_International   "&Internationalisation"
#define en_MultipleLanguage   "Multiple &Lingual Messages"
#define en_Program   "&Stand alone Program Unit"
#define fr_Program   "&Programme autonome"
#define en_Overlay   "S&ubordinate Overlay or Module"
#define en_PopUp   "&Pop-Up style Component"
#define en_CommandLine   "&Command Line Parameter Reception"
#define fr_CommandLine   "Ligne de Commande"
#define en_MouseEvents   "&Event Manager"
#define fr_MouseEvents   "&Evenements"
#define it_MouseEvents   ""
#define es_MouseEvents   ""
#define de_MouseEvents   ""
#define nl_MouseEvents   ""
#define pt_MouseEvents   ""
#define xx_MouseEvents   ""
#define en_Auto720   "Mouse Buttons"
#define en_Auto2077   "Mouse Events"
#define en_Auto7131   "Focus Key Events"
#define en_SendLeft   "Mouse Left Button"
#define en_SendMiddle   "Middle Button"
#define en_SendRight   "Mouse Right Button"
#define en_SendDown   "Mouse Button DOWN"
#define en_SendUp   "Mouse Button UP"
#define en_SendWhileDown   "Mouse Move While Down"
#define en_SendMove   "Mouse Pointer Move"
#define en_MouseKey   "M&ouse Event Channel"
#define en_WidgetTriggers   "&Widget Triggers"
#define en_Escape   "&Escape"
#define en_Enter   "E&nter"
#define en_PageUp   "&Page Up"
#define en_PageDown   "Pa&ge Down"
#define en_UpArrow   "&Up Arrow"
#define en_DownArrow   "&Down Arrow"
#define en_Tabulation   "&Tabulation"
#define en_DefaultBreak   "Defau&lt Break"
#define en_FormMethods   "&Method Manager"
#define fr_FormMethods   "&Methodes"
#define it_FormMethods   ""
#define es_FormMethods   ""
#define de_FormMethods   ""
#define nl_FormMethods   ""
#define pt_FormMethods   ""
#define xx_FormMethods   ""
#define en_Methods   "Return|Name|Parameters"
#define fr_Methods   "Retour|Nom|Parametres"
#define it_Methods   ""
#define es_Methods   ""
#define de_Methods   ""
#define nl_Methods   ""
#define pt_Methods   ""
#define xx_Methods   ""
#define en_Auto7154   ""

private struct accept_form_control_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[3+1];
	char * msg_Auto702[8];
	char * msg_Auto413[8];
	char * msg_FormControl[8];
	int	trigger_FormControl;
	int	s_FormControl;
	void *	p_FormControl;
	int	page_number;
	char * msg_Auto7156[8];
	char * msg_Auto1270[8];
	char * msg_Accept[8];
	int	trigger_Accept;
	int	s_Accept;
	void *	p_Accept;
	char * msg_EditMethod[8];
	int	trigger_EditMethod;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	int	s_Cancel;
	void *	p_Cancel;
	char * msg_Auto706[8];
	char * msg_Auto710[8];
	char * msg_Auto2085[8];
	char * msg_FormType[8];
	int	s_FormType;
	void *	p_FormType;
	int	value_FormType;
	char * msg_ProductionLanguage[8];
	int	s_ProductionLanguage;
	void *	p_ProductionLanguage;
	int	value_ProductionLanguage;
	char * msg_NationalLanguage[8];
	int	value_NationalLanguage;
	char * msg_International[8];
	int	trigger_International;
	int	value_International;
	char * msg_MultipleLanguage[8];
	int	trigger_MultipleLanguage;
	int	value_MultipleLanguage;
	char * msg_Program[8];
	int	trigger_Program;
	int	s_Program;
	void *	p_Program;
	int	value_Program;
	char * msg_Overlay[8];
	int	trigger_Overlay;
	int	s_Overlay;
	void *	p_Overlay;
	int	value_Overlay;
	char * msg_PopUp[8];
	int	trigger_PopUp;
	int	value_PopUp;
	char * msg_CommandLine[8];
	int	trigger_CommandLine;
	int	value_CommandLine;
	char * msg_MouseEvents[8];
	int	trigger_MouseEvents;
	char * msg_Auto720[8];
	char * msg_Auto2077[8];
	char * msg_Auto7131[8];
	char * msg_SendLeft[8];
	int	trigger_SendLeft;
	int	value_SendLeft;
	char * msg_SendMiddle[8];
	int	trigger_SendMiddle;
	int	value_SendMiddle;
	char * msg_SendRight[8];
	int	trigger_SendRight;
	int	value_SendRight;
	char * msg_SendDown[8];
	int	trigger_SendDown;
	int	value_SendDown;
	char * msg_SendUp[8];
	int	trigger_SendUp;
	int	value_SendUp;
	char * msg_SendWhileDown[8];
	int	trigger_SendWhileDown;
	int	value_SendWhileDown;
	char * msg_SendMove[8];
	int	trigger_SendMove;
	int	value_SendMove;
	char * msg_MouseKey[8];
	int	trigger_MouseKey;
	int	value_MouseKey;
	char * msg_WidgetTriggers[8];
	int	trigger_WidgetTriggers;
	int	value_WidgetTriggers;
	char * msg_Escape[8];
	int	trigger_Escape;
	int	s_Escape;
	void *	p_Escape;
	int	value_Escape;
	char * msg_Enter[8];
	int	trigger_Enter;
	int	s_Enter;
	void *	p_Enter;
	int	value_Enter;
	char * msg_PageUp[8];
	int	trigger_PageUp;
	int	s_PageUp;
	void *	p_PageUp;
	int	value_PageUp;
	char * msg_PageDown[8];
	int	trigger_PageDown;
	int	s_PageDown;
	void *	p_PageDown;
	int	value_PageDown;
	char * msg_UpArrow[8];
	int	trigger_UpArrow;
	int	s_UpArrow;
	void *	p_UpArrow;
	int	value_UpArrow;
	char * msg_DownArrow[8];
	int	trigger_DownArrow;
	int	s_DownArrow;
	void *	p_DownArrow;
	int	value_DownArrow;
	char * msg_Tabulation[8];
	int	trigger_Tabulation;
	int	s_Tabulation;
	void *	p_Tabulation;
	int	value_Tabulation;
	char * msg_DefaultBreak[8];
	int	trigger_DefaultBreak;
	int	s_DefaultBreak;
	void *	p_DefaultBreak;
	int	value_DefaultBreak;
	char * msg_FormMethods[8];
	int	trigger_FormMethods;
	char * msg_Methods[8];
	int	value_Methods;
	int	column_Methods;
	char	buffer_Methods[19][82];
	char * row_Methods;
	int	value_Auto7154;
	int	limit_Auto7154;
	int	max_Auto7154;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[15];
	} * _Context;

private	int	accept_form_control_create(
	char * pFormType,
	char * pProductionLanguage,
	char * pNationalLanguage,
	char * pInternational,
	char * pMultipleLanguage,
	char * pProgram,
	char * pOverlay,
	char * pPopUp,
	char * pCommandLine,
	char * pSendLeft,
	char * pSendMiddle,
	char * pSendRight,
	char * pSendDown,
	char * pSendUp,
	char * pSendWhileDown,
	char * pSendMove,
	char * pMouseKey,
	char * pWidgetTriggers,
	char * pEscape,
	char * pEnter,
	char * pPageUp,
	char * pPageDown,
	char * pUpArrow,
	char * pDownArrow,
	char * pTabulation,
	char * pDefaultBreak)
{

	int i;
	if (!(_Context = allocate( sizeof( struct accept_form_control_context ) ) ))
		return(27);
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=35;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pFormType);
		if (!( pFormType )) _Context->value_FormType=0;
		else	_Context->value_FormType = *((int *)pFormType);
		visual_transferin((void *) 0, 0, pProductionLanguage);
		if (!( pProductionLanguage )) _Context->value_ProductionLanguage=0;
		else	_Context->value_ProductionLanguage = *((int *)pProductionLanguage);
		visual_transferin((void *) 0, 0, pNationalLanguage);
		if (!( pNationalLanguage )) _Context->value_NationalLanguage=0;
		else	_Context->value_NationalLanguage = *((int *)pNationalLanguage);
		visual_transferin((void *) 0, 0, pInternational);
		if (!( pInternational )) _Context->value_International=0;
		else	_Context->value_International = *((int *)pInternational);
		visual_transferin((void *) 0, 0, pMultipleLanguage);
		if (!( pMultipleLanguage )) _Context->value_MultipleLanguage=0;
		else	_Context->value_MultipleLanguage = *((int *)pMultipleLanguage);
		visual_transferin((void *) 0, 0, pProgram);
		if (!( pProgram )) _Context->value_Program=0;
		else	_Context->value_Program = *((int *)pProgram);
		visual_transferin((void *) 0, 0, pOverlay);
		if (!( pOverlay )) _Context->value_Overlay=0;
		else	_Context->value_Overlay = *((int *)pOverlay);
		visual_transferin((void *) 0, 0, pPopUp);
		if (!( pPopUp )) _Context->value_PopUp=0;
		else	_Context->value_PopUp = *((int *)pPopUp);
		visual_transferin((void *) 0, 0, pCommandLine);
		if (!( pCommandLine )) _Context->value_CommandLine=0;
		else	_Context->value_CommandLine = *((int *)pCommandLine);
		visual_transferin((void *) 0, 0, pSendLeft);
		if (!( pSendLeft )) _Context->value_SendLeft=0;
		else	_Context->value_SendLeft = *((int *)pSendLeft);
		visual_transferin((void *) 0, 0, pSendMiddle);
		if (!( pSendMiddle )) _Context->value_SendMiddle=0;
		else	_Context->value_SendMiddle = *((int *)pSendMiddle);
		visual_transferin((void *) 0, 0, pSendRight);
		if (!( pSendRight )) _Context->value_SendRight=0;
		else	_Context->value_SendRight = *((int *)pSendRight);
		visual_transferin((void *) 0, 0, pSendDown);
		if (!( pSendDown )) _Context->value_SendDown=0;
		else	_Context->value_SendDown = *((int *)pSendDown);
		visual_transferin((void *) 0, 0, pSendUp);
		if (!( pSendUp )) _Context->value_SendUp=0;
		else	_Context->value_SendUp = *((int *)pSendUp);
		visual_transferin((void *) 0, 0, pSendWhileDown);
		if (!( pSendWhileDown )) _Context->value_SendWhileDown=0;
		else	_Context->value_SendWhileDown = *((int *)pSendWhileDown);
		visual_transferin((void *) 0, 0, pSendMove);
		if (!( pSendMove )) _Context->value_SendMove=0;
		else	_Context->value_SendMove = *((int *)pSendMove);
		visual_transferin((void *) 0, 0, pMouseKey);
		if (!( pMouseKey )) _Context->value_MouseKey=0;
		else	_Context->value_MouseKey = *((int *)pMouseKey);
		visual_transferin((void *) 0, 0, pWidgetTriggers);
		if (!( pWidgetTriggers )) _Context->value_WidgetTriggers=0;
		else	_Context->value_WidgetTriggers = *((int *)pWidgetTriggers);
		visual_transferin((void *) 0, 0, pEscape);
		if (!( pEscape )) _Context->value_Escape=0;
		else	_Context->value_Escape = *((int *)pEscape);
		visual_transferin((void *) 0, 0, pEnter);
		if (!( pEnter )) _Context->value_Enter=0;
		else	_Context->value_Enter = *((int *)pEnter);
		visual_transferin((void *) 0, 0, pPageUp);
		if (!( pPageUp )) _Context->value_PageUp=0;
		else	_Context->value_PageUp = *((int *)pPageUp);
		visual_transferin((void *) 0, 0, pPageDown);
		if (!( pPageDown )) _Context->value_PageDown=0;
		else	_Context->value_PageDown = *((int *)pPageDown);
		visual_transferin((void *) 0, 0, pUpArrow);
		if (!( pUpArrow )) _Context->value_UpArrow=0;
		else	_Context->value_UpArrow = *((int *)pUpArrow);
		visual_transferin((void *) 0, 0, pDownArrow);
		if (!( pDownArrow )) _Context->value_DownArrow=0;
		else	_Context->value_DownArrow = *((int *)pDownArrow);
		visual_transferin((void *) 0, 0, pTabulation);
		if (!( pTabulation )) _Context->value_Tabulation=0;
		else	_Context->value_Tabulation = *((int *)pTabulation);
		visual_transferin((void *) 0, 0, pDefaultBreak);
		if (!( pDefaultBreak )) _Context->value_DefaultBreak=0;
		else	_Context->value_DefaultBreak = *((int *)pDefaultBreak);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto702[i]=" ";
	_Context->msg_Auto702[0]=en_Auto702;
	_Context->msg_Auto702[1]=fr_Auto702;
	_Context->msg_Auto702[2]=it_Auto702;
	_Context->msg_Auto702[3]=es_Auto702;
	_Context->msg_Auto702[4]=de_Auto702;
	_Context->msg_Auto702[5]=nl_Auto702;
	_Context->msg_Auto702[6]=pt_Auto702;
	_Context->msg_Auto702[7]=xx_Auto702;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto413[i]=" ";
	_Context->msg_Auto413[0]=en_Auto413;
	_Context->msg_Auto413[1]=fr_Auto413;
	_Context->msg_Auto413[2]=it_Auto413;
	_Context->msg_Auto413[3]=es_Auto413;
	_Context->msg_Auto413[4]=de_Auto413;
	_Context->msg_Auto413[5]=nl_Auto413;
	_Context->msg_Auto413[6]=pt_Auto413;
	_Context->msg_Auto413[7]=xx_Auto413;
	for (i=0; i < 8; i++)_Context->msg_FormControl[i]=" ";
	_Context->msg_FormControl[0]=en_FormControl;
	_Context->msg_FormControl[1]=fr_FormControl;
	_Context->msg_FormControl[2]=it_FormControl;
	_Context->msg_FormControl[3]=es_FormControl;
	_Context->msg_FormControl[4]=de_FormControl;
	_Context->msg_FormControl[5]=nl_FormControl;
	_Context->msg_FormControl[6]=pt_FormControl;
	_Context->msg_FormControl[7]=xx_FormControl;
	_Context->s_FormControl=0;
	_Context->p_FormControl=visual_buffer(50,95,700,380);
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_Auto7156[i]=" ";
	_Context->msg_Auto7156[0]=en_Auto7156;
	for (i=0; i < 8; i++)_Context->msg_Auto1270[i]=" ";
	_Context->msg_Auto1270[0]=en_Auto1270;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->s_Accept=0;
	_Context->p_Accept=visual_buffer(140,485,154,32);
	for (i=0; i < 8; i++)_Context->msg_EditMethod[i]=" ";
	_Context->msg_EditMethod[0]=en_EditMethod;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->s_Cancel=0;
	_Context->p_Cancel=visual_buffer(510,485,154,32);
	for (i=0; i < 8; i++)_Context->msg_Auto706[i]=" ";
	_Context->msg_Auto706[0]=en_Auto706;
	for (i=0; i < 8; i++)_Context->msg_Auto710[i]=" ";
	_Context->msg_Auto710[0]=en_Auto710;
	for (i=0; i < 8; i++)_Context->msg_Auto2085[i]=" ";
	_Context->msg_Auto2085[0]=en_Auto2085;
	for (i=0; i < 8; i++)_Context->msg_FormType[i]=" ";
	_Context->s_FormType=0;
	_Context->p_FormType=visual_buffer(90,195,168,144);
	for (i=0; i < 8; i++)_Context->msg_ProductionLanguage[i]=" ";
	_Context->s_ProductionLanguage=0;
	_Context->p_ProductionLanguage=visual_buffer(320,195,168,144);
	for (i=0; i < 8; i++)_Context->msg_NationalLanguage[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_International[i]=" ";
	_Context->msg_International[0]=en_International;
	for (i=0; i < 8; i++)_Context->msg_MultipleLanguage[i]=" ";
	_Context->msg_MultipleLanguage[0]=en_MultipleLanguage;
	for (i=0; i < 8; i++)_Context->msg_Program[i]=" ";
	_Context->msg_Program[0]=en_Program;
	_Context->msg_Program[1]=fr_Program;
	_Context->s_Program=0;
	_Context->p_Program=visual_buffer(90,355,210,20);
	for (i=0; i < 8; i++)_Context->msg_Overlay[i]=" ";
	_Context->msg_Overlay[0]=en_Overlay;
	_Context->s_Overlay=0;
	_Context->p_Overlay=visual_buffer(440,355,280,16);
	for (i=0; i < 8; i++)_Context->msg_PopUp[i]=" ";
	_Context->msg_PopUp[0]=en_PopUp;
	for (i=0; i < 8; i++)_Context->msg_CommandLine[i]=" ";
	_Context->msg_CommandLine[0]=en_CommandLine;
	_Context->msg_CommandLine[1]=fr_CommandLine;
	for (i=0; i < 8; i++)_Context->msg_MouseEvents[i]=" ";
	_Context->msg_MouseEvents[0]=en_MouseEvents;
	_Context->msg_MouseEvents[1]=fr_MouseEvents;
	_Context->msg_MouseEvents[2]=it_MouseEvents;
	_Context->msg_MouseEvents[3]=es_MouseEvents;
	_Context->msg_MouseEvents[4]=de_MouseEvents;
	_Context->msg_MouseEvents[5]=nl_MouseEvents;
	_Context->msg_MouseEvents[6]=pt_MouseEvents;
	_Context->msg_MouseEvents[7]=xx_MouseEvents;
	_Context->focus_pages[2]=15;
	for (i=0; i < 8; i++)_Context->msg_Auto720[i]=" ";
	_Context->msg_Auto720[0]=en_Auto720;
	for (i=0; i < 8; i++)_Context->msg_Auto2077[i]=" ";
	_Context->msg_Auto2077[0]=en_Auto2077;
	for (i=0; i < 8; i++)_Context->msg_Auto7131[i]=" ";
	_Context->msg_Auto7131[0]=en_Auto7131;
	for (i=0; i < 8; i++)_Context->msg_SendLeft[i]=" ";
	_Context->msg_SendLeft[0]=en_SendLeft;
	for (i=0; i < 8; i++)_Context->msg_SendMiddle[i]=" ";
	_Context->msg_SendMiddle[0]=en_SendMiddle;
	for (i=0; i < 8; i++)_Context->msg_SendRight[i]=" ";
	_Context->msg_SendRight[0]=en_SendRight;
	for (i=0; i < 8; i++)_Context->msg_SendDown[i]=" ";
	_Context->msg_SendDown[0]=en_SendDown;
	for (i=0; i < 8; i++)_Context->msg_SendUp[i]=" ";
	_Context->msg_SendUp[0]=en_SendUp;
	for (i=0; i < 8; i++)_Context->msg_SendWhileDown[i]=" ";
	_Context->msg_SendWhileDown[0]=en_SendWhileDown;
	for (i=0; i < 8; i++)_Context->msg_SendMove[i]=" ";
	_Context->msg_SendMove[0]=en_SendMove;
	for (i=0; i < 8; i++)_Context->msg_MouseKey[i]=" ";
	_Context->msg_MouseKey[0]=en_MouseKey;
	for (i=0; i < 8; i++)_Context->msg_WidgetTriggers[i]=" ";
	_Context->msg_WidgetTriggers[0]=en_WidgetTriggers;
	for (i=0; i < 8; i++)_Context->msg_Escape[i]=" ";
	_Context->msg_Escape[0]=en_Escape;
	_Context->s_Escape=0;
	_Context->p_Escape=visual_buffer(80,335,120,20);
	for (i=0; i < 8; i++)_Context->msg_Enter[i]=" ";
	_Context->msg_Enter[0]=en_Enter;
	_Context->s_Enter=0;
	_Context->p_Enter=visual_buffer(330,335,90,20);
	for (i=0; i < 8; i++)_Context->msg_PageUp[i]=" ";
	_Context->msg_PageUp[0]=en_PageUp;
	_Context->s_PageUp=0;
	_Context->p_PageUp=visual_buffer(80,375,110,20);
	for (i=0; i < 8; i++)_Context->msg_PageDown[i]=" ";
	_Context->msg_PageDown[0]=en_PageDown;
	_Context->s_PageDown=0;
	_Context->p_PageDown=visual_buffer(80,415,130,20);
	for (i=0; i < 8; i++)_Context->msg_UpArrow[i]=" ";
	_Context->msg_UpArrow[0]=en_UpArrow;
	_Context->s_UpArrow=0;
	_Context->p_UpArrow=visual_buffer(330,375,120,20);
	for (i=0; i < 8; i++)_Context->msg_DownArrow[i]=" ";
	_Context->msg_DownArrow[0]=en_DownArrow;
	_Context->s_DownArrow=0;
	_Context->p_DownArrow=visual_buffer(330,415,120,20);
	for (i=0; i < 8; i++)_Context->msg_Tabulation[i]=" ";
	_Context->msg_Tabulation[0]=en_Tabulation;
	_Context->s_Tabulation=0;
	_Context->p_Tabulation=visual_buffer(540,335,120,20);
	for (i=0; i < 8; i++)_Context->msg_DefaultBreak[i]=" ";
	_Context->msg_DefaultBreak[0]=en_DefaultBreak;
	_Context->s_DefaultBreak=0;
	_Context->p_DefaultBreak=visual_buffer(540,375,130,20);
	for (i=0; i < 8; i++)_Context->msg_FormMethods[i]=" ";
	_Context->msg_FormMethods[0]=en_FormMethods;
	_Context->msg_FormMethods[1]=fr_FormMethods;
	_Context->msg_FormMethods[2]=it_FormMethods;
	_Context->msg_FormMethods[3]=es_FormMethods;
	_Context->msg_FormMethods[4]=de_FormMethods;
	_Context->msg_FormMethods[5]=nl_FormMethods;
	_Context->msg_FormMethods[6]=pt_FormMethods;
	_Context->msg_FormMethods[7]=xx_FormMethods;
	_Context->focus_pages[3]=33;
	for (i=0; i < 8; i++)_Context->msg_Methods[i]=" ";
	_Context->msg_Methods[0]=en_Methods;
	_Context->msg_Methods[1]=fr_Methods;
	_Context->msg_Methods[2]=it_Methods;
	_Context->msg_Methods[3]=es_Methods;
	_Context->msg_Methods[4]=de_Methods;
	_Context->msg_Methods[5]=nl_Methods;
	_Context->msg_Methods[6]=pt_Methods;
	_Context->msg_Methods[7]=xx_Methods;
	if ( 0 > 0 ) { _Context->row_Methods=&_Context->buffer_Methods[0-1][0]; } ;
	_Context->max_Auto7154=1;
	_Context->value_Auto7154=1;
	_Context->limit_Auto7154=1;
	_Context->value_Auto7154=0;
	_Context->limit_Auto7154=19;
	_Context->max_Auto7154=(19*2);
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(40,65,720+10,470+10);
	return(0);
}

private	int	accept_form_control_hide()
{
	if ((_Context->p_FormControl != (void *) 0)
	&& (_Context->s_FormControl != 0)) {
		(void)visual_buffer_put(_Context->p_FormControl,50,95);
		_Context->s_FormControl=0;
		}
	if ((_Context->p_Accept != (void *) 0)
	&& (_Context->s_Accept != 0)) {
		(void)visual_buffer_put(_Context->p_Accept,140,485);
		_Context->s_Accept=0;
		}
	if ((_Context->p_Cancel != (void *) 0)
	&& (_Context->s_Cancel != 0)) {
		(void)visual_buffer_put(_Context->p_Cancel,510,485);
		_Context->s_Cancel=0;
		}
	if ((_Context->p_FormType != (void *) 0)
	&& (_Context->s_FormType != 0)) {
		(void)visual_buffer_put(_Context->p_FormType,90,195);
		_Context->s_FormType=0;
		}
	if ((_Context->p_ProductionLanguage != (void *) 0)
	&& (_Context->s_ProductionLanguage != 0)) {
		(void)visual_buffer_put(_Context->p_ProductionLanguage,320,195);
		_Context->s_ProductionLanguage=0;
		}
	if ((_Context->p_Program != (void *) 0)
	&& (_Context->s_Program != 0)) {
		(void)visual_buffer_put(_Context->p_Program,90,355);
		_Context->s_Program=0;
		}
	if ((_Context->p_Overlay != (void *) 0)
	&& (_Context->s_Overlay != 0)) {
		(void)visual_buffer_put(_Context->p_Overlay,440,355);
		_Context->s_Overlay=0;
		}
	if ((_Context->p_Escape != (void *) 0)
	&& (_Context->s_Escape != 0)) {
		(void)visual_buffer_put(_Context->p_Escape,80,335);
		_Context->s_Escape=0;
		}
	if ((_Context->p_Enter != (void *) 0)
	&& (_Context->s_Enter != 0)) {
		(void)visual_buffer_put(_Context->p_Enter,330,335);
		_Context->s_Enter=0;
		}
	if ((_Context->p_PageUp != (void *) 0)
	&& (_Context->s_PageUp != 0)) {
		(void)visual_buffer_put(_Context->p_PageUp,80,375);
		_Context->s_PageUp=0;
		}
	if ((_Context->p_PageDown != (void *) 0)
	&& (_Context->s_PageDown != 0)) {
		(void)visual_buffer_put(_Context->p_PageDown,80,415);
		_Context->s_PageDown=0;
		}
	if ((_Context->p_UpArrow != (void *) 0)
	&& (_Context->s_UpArrow != 0)) {
		(void)visual_buffer_put(_Context->p_UpArrow,330,375);
		_Context->s_UpArrow=0;
		}
	if ((_Context->p_DownArrow != (void *) 0)
	&& (_Context->s_DownArrow != 0)) {
		(void)visual_buffer_put(_Context->p_DownArrow,330,415);
		_Context->s_DownArrow=0;
		}
	if ((_Context->p_Tabulation != (void *) 0)
	&& (_Context->s_Tabulation != 0)) {
		(void)visual_buffer_put(_Context->p_Tabulation,540,335);
		_Context->s_Tabulation=0;
		}
	if ((_Context->p_DefaultBreak != (void *) 0)
	&& (_Context->s_DefaultBreak != 0)) {
		(void)visual_buffer_put(_Context->p_DefaultBreak,540,375);
		_Context->s_DefaultBreak=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,40,65);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_form_control_remove(
	char * pFormType,
	char * pProductionLanguage,
	char * pNationalLanguage,
	char * pInternational,
	char * pMultipleLanguage,
	char * pProgram,
	char * pOverlay,
	char * pPopUp,
	char * pCommandLine,
	char * pSendLeft,
	char * pSendMiddle,
	char * pSendRight,
	char * pSendDown,
	char * pSendUp,
	char * pSendWhileDown,
	char * pSendMove,
	char * pMouseKey,
	char * pWidgetTriggers,
	char * pEscape,
	char * pEnter,
	char * pPageUp,
	char * pPageDown,
	char * pUpArrow,
	char * pDownArrow,
	char * pTabulation,
	char * pDefaultBreak)
{

	int	result=_Context->keycode;
	if (_Context->p_FormControl != (void *) 0)
		_Context->p_FormControl = visual_drop(_Context->p_FormControl);
	if (_Context->p_Accept != (void *) 0)
		_Context->p_Accept = visual_drop(_Context->p_Accept);
	if (_Context->p_Cancel != (void *) 0)
		_Context->p_Cancel = visual_drop(_Context->p_Cancel);
	if (_Context->p_FormType != (void *) 0)
		_Context->p_FormType = visual_drop(_Context->p_FormType);
	if (_Context->p_ProductionLanguage != (void *) 0)
		_Context->p_ProductionLanguage = visual_drop(_Context->p_ProductionLanguage);
	if (_Context->p_Program != (void *) 0)
		_Context->p_Program = visual_drop(_Context->p_Program);
	if (_Context->p_Overlay != (void *) 0)
		_Context->p_Overlay = visual_drop(_Context->p_Overlay);
	if (_Context->p_Escape != (void *) 0)
		_Context->p_Escape = visual_drop(_Context->p_Escape);
	if (_Context->p_Enter != (void *) 0)
		_Context->p_Enter = visual_drop(_Context->p_Enter);
	if (_Context->p_PageUp != (void *) 0)
		_Context->p_PageUp = visual_drop(_Context->p_PageUp);
	if (_Context->p_PageDown != (void *) 0)
		_Context->p_PageDown = visual_drop(_Context->p_PageDown);
	if (_Context->p_UpArrow != (void *) 0)
		_Context->p_UpArrow = visual_drop(_Context->p_UpArrow);
	if (_Context->p_DownArrow != (void *) 0)
		_Context->p_DownArrow = visual_drop(_Context->p_DownArrow);
	if (_Context->p_Tabulation != (void *) 0)
		_Context->p_Tabulation = visual_drop(_Context->p_Tabulation);
	if (_Context->p_DefaultBreak != (void *) 0)
		_Context->p_DefaultBreak = visual_drop(_Context->p_DefaultBreak);
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pFormType);
		if ( pFormType != (char *) 0)
			*((int*)pFormType) = _Context->value_FormType;
		visual_transferout((void *) 0, 0, pProductionLanguage);
		if ( pProductionLanguage != (char *) 0)
			*((int*)pProductionLanguage) = _Context->value_ProductionLanguage;
		visual_transferout((void *) 0, 0, pNationalLanguage);
		if ( pNationalLanguage != (char *) 0)
			*((int*)pNationalLanguage) = _Context->value_NationalLanguage;
		visual_transferout((void *) 0, 0, pInternational);
		if ( pInternational != (char *) 0)
			*((int*)pInternational) = _Context->value_International;
		visual_transferout((void *) 0, 0, pMultipleLanguage);
		if ( pMultipleLanguage != (char *) 0)
			*((int*)pMultipleLanguage) = _Context->value_MultipleLanguage;
		visual_transferout((void *) 0, 0, pProgram);
		if ( pProgram != (char *) 0)
			*((int*)pProgram) = _Context->value_Program;
		visual_transferout((void *) 0, 0, pOverlay);
		if ( pOverlay != (char *) 0)
			*((int*)pOverlay) = _Context->value_Overlay;
		visual_transferout((void *) 0, 0, pPopUp);
		if ( pPopUp != (char *) 0)
			*((int*)pPopUp) = _Context->value_PopUp;
		visual_transferout((void *) 0, 0, pCommandLine);
		if ( pCommandLine != (char *) 0)
			*((int*)pCommandLine) = _Context->value_CommandLine;
		visual_transferout((void *) 0, 0, pSendLeft);
		if ( pSendLeft != (char *) 0)
			*((int*)pSendLeft) = _Context->value_SendLeft;
		visual_transferout((void *) 0, 0, pSendMiddle);
		if ( pSendMiddle != (char *) 0)
			*((int*)pSendMiddle) = _Context->value_SendMiddle;
		visual_transferout((void *) 0, 0, pSendRight);
		if ( pSendRight != (char *) 0)
			*((int*)pSendRight) = _Context->value_SendRight;
		visual_transferout((void *) 0, 0, pSendDown);
		if ( pSendDown != (char *) 0)
			*((int*)pSendDown) = _Context->value_SendDown;
		visual_transferout((void *) 0, 0, pSendUp);
		if ( pSendUp != (char *) 0)
			*((int*)pSendUp) = _Context->value_SendUp;
		visual_transferout((void *) 0, 0, pSendWhileDown);
		if ( pSendWhileDown != (char *) 0)
			*((int*)pSendWhileDown) = _Context->value_SendWhileDown;
		visual_transferout((void *) 0, 0, pSendMove);
		if ( pSendMove != (char *) 0)
			*((int*)pSendMove) = _Context->value_SendMove;
		visual_transferout((void *) 0, 0, pMouseKey);
		if ( pMouseKey != (char *) 0)
			*((int*)pMouseKey) = _Context->value_MouseKey;
		visual_transferout((void *) 0, 0, pWidgetTriggers);
		if ( pWidgetTriggers != (char *) 0)
			*((int*)pWidgetTriggers) = _Context->value_WidgetTriggers;
		visual_transferout((void *) 0, 0, pEscape);
		if ( pEscape != (char *) 0)
			*((int*)pEscape) = _Context->value_Escape;
		visual_transferout((void *) 0, 0, pEnter);
		if ( pEnter != (char *) 0)
			*((int*)pEnter) = _Context->value_Enter;
		visual_transferout((void *) 0, 0, pPageUp);
		if ( pPageUp != (char *) 0)
			*((int*)pPageUp) = _Context->value_PageUp;
		visual_transferout((void *) 0, 0, pPageDown);
		if ( pPageDown != (char *) 0)
			*((int*)pPageDown) = _Context->value_PageDown;
		visual_transferout((void *) 0, 0, pUpArrow);
		if ( pUpArrow != (char *) 0)
			*((int*)pUpArrow) = _Context->value_UpArrow;
		visual_transferout((void *) 0, 0, pDownArrow);
		if ( pDownArrow != (char *) 0)
			*((int*)pDownArrow) = _Context->value_DownArrow;
		visual_transferout((void *) 0, 0, pTabulation);
		if ( pTabulation != (char *) 0)
			*((int*)pTabulation) = _Context->value_Tabulation;
		visual_transferout((void *) 0, 0, pDefaultBreak);
		if ( pDefaultBreak != (char *) 0)
			*((int*)pDefaultBreak) = _Context->value_DefaultBreak;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_form_control_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,40,65);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(40,65,720,470,2,_Context->msg_Auto702[_Context->language],strlen(_Context->msg_Auto702[_Context->language]),0x407);
	visual_image(42,87,714,444,_Context->msg_Auto413[_Context->language],4);
	if ((_Context->p_FormControl != (void *) 0)
	&& (_Context->s_FormControl == 0)) {
		(void)visual_buffer_get(_Context->p_FormControl,50,95);
		_Context->s_FormControl=1;
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_FormControl=visual_trigger_code(_Context->msg_FormControl[_Context->language],strlen(_Context->msg_FormControl[_Context->language]));
	visual_tabpage(50,95,700,380,2,_Context->msg_FormControl[_Context->language],strlen(_Context->msg_FormControl[_Context->language]),0,2);
	} else {
		visual_tabpage(50,95,700,380,2,_Context->msg_FormControl[_Context->language],strlen(_Context->msg_FormControl[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(60,135,680,16,2,16,0,_Context->msg_Auto7156[_Context->language],strlen(_Context->msg_Auto7156[_Context->language]),258);
	visual_frame(60,151,680,94,4);
		}
	if (_Context->page_number == 1 ) {
	visual_text(60,305,680,16,2,16,0,_Context->msg_Auto1270[_Context->language],strlen(_Context->msg_Auto1270[_Context->language]),258);
	visual_frame(60,321,680,134,4);
		}
	if ((_Context->p_Accept != (void *) 0)
	&& (_Context->s_Accept == 0)) {
		(void)visual_buffer_get(_Context->p_Accept,140,485);
		_Context->s_Accept=1;
		}
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(140,485,154,32,2,175,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_EditMethod=visual_trigger_code(_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]));
	visual_button(320,485,154,32,2,28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),0);
	if ((_Context->p_Cancel != (void *) 0)
	&& (_Context->s_Cancel == 0)) {
		(void)visual_buffer_get(_Context->p_Cancel,510,485);
		_Context->s_Cancel=1;
		}
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(510,485,154,32,2,175,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	if (_Context->page_number == 1 ) {
	visual_text(90,175,168,16,2,16,0,_Context->msg_Auto706[_Context->language],strlen(_Context->msg_Auto706[_Context->language]),259);
		}
	if (_Context->page_number == 1 ) {
	visual_text(320,175,168,16,2,16,0,_Context->msg_Auto710[_Context->language],strlen(_Context->msg_Auto710[_Context->language]),259);
		}
	if (_Context->page_number == 1 ) {
	visual_text(530,175,168,16,2,16,0,_Context->msg_Auto2085[_Context->language],strlen(_Context->msg_Auto2085[_Context->language]),259);
		}
	if ((_Context->p_FormType != (void *) 0)
	&& (_Context->s_FormType == 0)) {
		(void)visual_buffer_get(_Context->p_FormType,90,195);
		_Context->s_FormType=1;
		}
	if (_Context->page_number == 1 ) {
	visual_select(90,195,168,144,2,27,0,parse_selection(FormTypeList,&_Context->value_FormType),0);
		}
	if ((_Context->p_ProductionLanguage != (void *) 0)
	&& (_Context->s_ProductionLanguage == 0)) {
		(void)visual_buffer_get(_Context->p_ProductionLanguage,320,195);
		_Context->s_ProductionLanguage=1;
		}
	if (_Context->page_number == 1 ) {
	visual_select(320,195,168,144,2,27,0,parse_selection(ProductionLanguageList,&_Context->value_ProductionLanguage),0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(530,195,168,144,2,27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),768);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_International=visual_trigger_code(_Context->msg_International[_Context->language],strlen(_Context->msg_International[_Context->language]));
	visual_check(90,415,182,16,2,28,28,_Context->msg_International[_Context->language],strlen(_Context->msg_International[_Context->language]),_Context->value_International|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_MultipleLanguage=visual_trigger_code(_Context->msg_MultipleLanguage[_Context->language],strlen(_Context->msg_MultipleLanguage[_Context->language]));
	visual_check(440,415,280,16,2,28,28,_Context->msg_MultipleLanguage[_Context->language],strlen(_Context->msg_MultipleLanguage[_Context->language]),_Context->value_MultipleLanguage|0);
		}
	if ((_Context->p_Program != (void *) 0)
	&& (_Context->s_Program == 0)) {
		(void)visual_buffer_get(_Context->p_Program,90,355);
		_Context->s_Program=1;
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Program=visual_trigger_code(_Context->msg_Program[_Context->language],strlen(_Context->msg_Program[_Context->language]));
	visual_check(90,355,210,20,2,27,0,_Context->msg_Program[_Context->language],strlen(_Context->msg_Program[_Context->language]),_Context->value_Program|0);
		}
	if ((_Context->p_Overlay != (void *) 0)
	&& (_Context->s_Overlay == 0)) {
		(void)visual_buffer_get(_Context->p_Overlay,440,355);
		_Context->s_Overlay=1;
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Overlay=visual_trigger_code(_Context->msg_Overlay[_Context->language],strlen(_Context->msg_Overlay[_Context->language]));
	visual_check(440,355,280,16,2,27,0,_Context->msg_Overlay[_Context->language],strlen(_Context->msg_Overlay[_Context->language]),_Context->value_Overlay|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_PopUp=visual_trigger_code(_Context->msg_PopUp[_Context->language],strlen(_Context->msg_PopUp[_Context->language]));
	visual_check(90,385,210,20,2,27,0,_Context->msg_PopUp[_Context->language],strlen(_Context->msg_PopUp[_Context->language]),_Context->value_PopUp|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_CommandLine=visual_trigger_code(_Context->msg_CommandLine[_Context->language],strlen(_Context->msg_CommandLine[_Context->language]));
	visual_check(440,385,280,16,2,28,28,_Context->msg_CommandLine[_Context->language],strlen(_Context->msg_CommandLine[_Context->language]),_Context->value_CommandLine|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_MouseEvents=visual_trigger_code(_Context->msg_MouseEvents[_Context->language],strlen(_Context->msg_MouseEvents[_Context->language]));
	visual_tabpage(50,95,700,380,2,_Context->msg_MouseEvents[_Context->language],strlen(_Context->msg_MouseEvents[_Context->language]),134,2);
	} else {
		visual_tabpage(50,95,700,380,2,_Context->msg_MouseEvents[_Context->language],strlen(_Context->msg_MouseEvents[_Context->language]),134,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(60,135,680,16,2,16,0,_Context->msg_Auto720[_Context->language],strlen(_Context->msg_Auto720[_Context->language]),258);
	visual_frame(60,151,680,44,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(60,205,680,16,2,16,0,_Context->msg_Auto2077[_Context->language],strlen(_Context->msg_Auto2077[_Context->language]),258);
	visual_frame(60,221,680,74,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(60,305,680,16,2,16,0,_Context->msg_Auto7131[_Context->language],strlen(_Context->msg_Auto7131[_Context->language]),258);
	visual_frame(60,321,680,134,4);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendLeft=visual_trigger_code(_Context->msg_SendLeft[_Context->language],strlen(_Context->msg_SendLeft[_Context->language]));
	visual_check(80,165,160,20,2,27,0,_Context->msg_SendLeft[_Context->language],strlen(_Context->msg_SendLeft[_Context->language]),_Context->value_SendLeft|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendMiddle=visual_trigger_code(_Context->msg_SendMiddle[_Context->language],strlen(_Context->msg_SendMiddle[_Context->language]));
	visual_check(330,165,140,20,2,27,0,_Context->msg_SendMiddle[_Context->language],strlen(_Context->msg_SendMiddle[_Context->language]),_Context->value_SendMiddle|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendRight=visual_trigger_code(_Context->msg_SendRight[_Context->language],strlen(_Context->msg_SendRight[_Context->language]));
	visual_check(540,165,170,20,2,27,0,_Context->msg_SendRight[_Context->language],strlen(_Context->msg_SendRight[_Context->language]),_Context->value_SendRight|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendDown=visual_trigger_code(_Context->msg_SendDown[_Context->language],strlen(_Context->msg_SendDown[_Context->language]));
	visual_check(80,235,180,20,2,27,0,_Context->msg_SendDown[_Context->language],strlen(_Context->msg_SendDown[_Context->language]),_Context->value_SendDown|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendUp=visual_trigger_code(_Context->msg_SendUp[_Context->language],strlen(_Context->msg_SendUp[_Context->language]));
	visual_check(330,235,160,20,2,27,0,_Context->msg_SendUp[_Context->language],strlen(_Context->msg_SendUp[_Context->language]),_Context->value_SendUp|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendWhileDown=visual_trigger_code(_Context->msg_SendWhileDown[_Context->language],strlen(_Context->msg_SendWhileDown[_Context->language]));
	visual_check(80,265,200,20,2,27,0,_Context->msg_SendWhileDown[_Context->language],strlen(_Context->msg_SendWhileDown[_Context->language]),_Context->value_SendWhileDown|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendMove=visual_trigger_code(_Context->msg_SendMove[_Context->language],strlen(_Context->msg_SendMove[_Context->language]));
	visual_check(330,265,170,20,2,16,0,_Context->msg_SendMove[_Context->language],strlen(_Context->msg_SendMove[_Context->language]),_Context->value_SendMove|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_MouseKey=visual_trigger_code(_Context->msg_MouseKey[_Context->language],strlen(_Context->msg_MouseKey[_Context->language]));
	visual_check(540,235,200,20,2,16,0,_Context->msg_MouseKey[_Context->language],strlen(_Context->msg_MouseKey[_Context->language]),_Context->value_MouseKey|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_WidgetTriggers=visual_trigger_code(_Context->msg_WidgetTriggers[_Context->language],strlen(_Context->msg_WidgetTriggers[_Context->language]));
	visual_check(540,265,150,20,2,16,0,_Context->msg_WidgetTriggers[_Context->language],strlen(_Context->msg_WidgetTriggers[_Context->language]),_Context->value_WidgetTriggers|0);
		}
	if ((_Context->p_Escape != (void *) 0)
	&& (_Context->s_Escape == 0)) {
		(void)visual_buffer_get(_Context->p_Escape,80,335);
		_Context->s_Escape=1;
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Escape=visual_trigger_code(_Context->msg_Escape[_Context->language],strlen(_Context->msg_Escape[_Context->language]));
	visual_check(80,335,120,20,2,27,0,_Context->msg_Escape[_Context->language],strlen(_Context->msg_Escape[_Context->language]),_Context->value_Escape|0);
		}
	if ((_Context->p_Enter != (void *) 0)
	&& (_Context->s_Enter == 0)) {
		(void)visual_buffer_get(_Context->p_Enter,330,335);
		_Context->s_Enter=1;
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Enter=visual_trigger_code(_Context->msg_Enter[_Context->language],strlen(_Context->msg_Enter[_Context->language]));
	visual_check(330,335,90,20,2,27,0,_Context->msg_Enter[_Context->language],strlen(_Context->msg_Enter[_Context->language]),_Context->value_Enter|0);
		}
	if ((_Context->p_PageUp != (void *) 0)
	&& (_Context->s_PageUp == 0)) {
		(void)visual_buffer_get(_Context->p_PageUp,80,375);
		_Context->s_PageUp=1;
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_PageUp=visual_trigger_code(_Context->msg_PageUp[_Context->language],strlen(_Context->msg_PageUp[_Context->language]));
	visual_check(80,375,110,20,2,27,0,_Context->msg_PageUp[_Context->language],strlen(_Context->msg_PageUp[_Context->language]),_Context->value_PageUp|0);
		}
	if ((_Context->p_PageDown != (void *) 0)
	&& (_Context->s_PageDown == 0)) {
		(void)visual_buffer_get(_Context->p_PageDown,80,415);
		_Context->s_PageDown=1;
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_PageDown=visual_trigger_code(_Context->msg_PageDown[_Context->language],strlen(_Context->msg_PageDown[_Context->language]));
	visual_check(80,415,130,20,2,27,0,_Context->msg_PageDown[_Context->language],strlen(_Context->msg_PageDown[_Context->language]),_Context->value_PageDown|0);
		}
	if ((_Context->p_UpArrow != (void *) 0)
	&& (_Context->s_UpArrow == 0)) {
		(void)visual_buffer_get(_Context->p_UpArrow,330,375);
		_Context->s_UpArrow=1;
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_UpArrow=visual_trigger_code(_Context->msg_UpArrow[_Context->language],strlen(_Context->msg_UpArrow[_Context->language]));
	visual_check(330,375,120,20,2,27,0,_Context->msg_UpArrow[_Context->language],strlen(_Context->msg_UpArrow[_Context->language]),_Context->value_UpArrow|0);
		}
	if ((_Context->p_DownArrow != (void *) 0)
	&& (_Context->s_DownArrow == 0)) {
		(void)visual_buffer_get(_Context->p_DownArrow,330,415);
		_Context->s_DownArrow=1;
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_DownArrow=visual_trigger_code(_Context->msg_DownArrow[_Context->language],strlen(_Context->msg_DownArrow[_Context->language]));
	visual_check(330,415,120,20,2,27,0,_Context->msg_DownArrow[_Context->language],strlen(_Context->msg_DownArrow[_Context->language]),_Context->value_DownArrow|0);
		}
	if ((_Context->p_Tabulation != (void *) 0)
	&& (_Context->s_Tabulation == 0)) {
		(void)visual_buffer_get(_Context->p_Tabulation,540,335);
		_Context->s_Tabulation=1;
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Tabulation=visual_trigger_code(_Context->msg_Tabulation[_Context->language],strlen(_Context->msg_Tabulation[_Context->language]));
	visual_check(540,335,120,20,2,27,0,_Context->msg_Tabulation[_Context->language],strlen(_Context->msg_Tabulation[_Context->language]),_Context->value_Tabulation|0);
		}
	if ((_Context->p_DefaultBreak != (void *) 0)
	&& (_Context->s_DefaultBreak == 0)) {
		(void)visual_buffer_get(_Context->p_DefaultBreak,540,375);
		_Context->s_DefaultBreak=1;
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_DefaultBreak=visual_trigger_code(_Context->msg_DefaultBreak[_Context->language],strlen(_Context->msg_DefaultBreak[_Context->language]));
	visual_check(540,375,130,20,2,27,0,_Context->msg_DefaultBreak[_Context->language],strlen(_Context->msg_DefaultBreak[_Context->language]),_Context->value_DefaultBreak|0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_FormMethods=visual_trigger_code(_Context->msg_FormMethods[_Context->language],strlen(_Context->msg_FormMethods[_Context->language]));
	visual_tabpage(50,95,700,380,2,_Context->msg_FormMethods[_Context->language],strlen(_Context->msg_FormMethods[_Context->language]),261,2);
	} else {
		visual_tabpage(50,95,700,380,2,_Context->msg_FormMethods[_Context->language],strlen(_Context->msg_FormMethods[_Context->language]),261,0);
		}
	if (_Context->page_number == 3 ) {
	visual_table(60,135,660+2,330+2,1,0,0,_Context->msg_Methods[_Context->language],_Context->buffer_Methods,0x4401,"(W16,W32,$)");
		}
	if (_Context->page_number == 3 ) {
	visual_scrollbar(720,135,20,330,1,0,0,_Context->value_Auto7154,_Context->limit_Auto7154,_Context->max_Auto7154,3);
		}
	visual_thaw(40,65,720,470);

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

private int on_Auto7154_action() {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (135+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Auto7154 -= 1;
		if (_Context->value_Auto7154 < 0) 
			_Context->value_Auto7154 = 0;
	status = accept_form_control_show();
	visual_scrollbar(720,135,20,330,1,0,0,_Context->value_Auto7154,_Context->limit_Auto7154,_Context->max_Auto7154,259);
		return(-1);
		}
	if ( visual_event(6) > (135+330-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Auto7154 += 1;
		if (_Context->value_Auto7154 > (_Context->max_Auto7154-_Context->limit_Auto7154)) 
			_Context->value_Auto7154 = (_Context->max_Auto7154-_Context->limit_Auto7154);
	status = accept_form_control_show();
	visual_scrollbar(720,135,20,330,1,0,0,_Context->value_Auto7154,_Context->limit_Auto7154,_Context->max_Auto7154,259);
		return(-1);
		}
	visual_scrollbar(720,135,20,330,1,0,0,_Context->value_Auto7154,_Context->limit_Auto7154,_Context->max_Auto7154,259);

	do {
		while(visual_getch() != 256);
		aty = _Context->value_Auto7154;
		_Context->value_Auto7154 = (((visual_event(6) - (135+20)) * _Context->max_Auto7154) / (330 - (2 * 20)));
		if (_Context->value_Auto7154 < 0) 
			_Context->value_Auto7154 = 0;
		else if (_Context->value_Auto7154 > (_Context->max_Auto7154-_Context->limit_Auto7154)) 
			_Context->value_Auto7154 = (_Context->max_Auto7154-_Context->limit_Auto7154);
		if (_Context->value_Auto7154 != aty) {
	status = accept_form_control_show();
	visual_scrollbar(720,135,20,330,1,0,0,_Context->value_Auto7154,_Context->limit_Auto7154,_Context->max_Auto7154,259);
			}

		}
	while (visual_event(1) != _MIMO_UP);	visual_scrollbar(720,135,20,330,1,0,0,_Context->value_Auto7154,_Context->limit_Auto7154,_Context->max_Auto7154,3);

	return(1);
}


private	int	accept_form_control_event()
{
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_FormControl == mb ) return(2);
		if (_Context->trigger_Accept == mb ) return(3);
		if (_Context->trigger_EditMethod == mb ) return(4);
		if (_Context->trigger_Cancel == mb ) return(5);
		if (_Context->trigger_International == mb ) return(9);
		if (_Context->trigger_MultipleLanguage == mb ) return(10);
		if (_Context->trigger_Program == mb ) return(11);
		if (_Context->trigger_Overlay == mb ) return(12);
		if (_Context->trigger_PopUp == mb ) return(13);
		if (_Context->trigger_CommandLine == mb ) return(14);
		if (_Context->trigger_MouseEvents == mb ) return(15);
		if (_Context->trigger_SendLeft == mb ) return(16);
		if (_Context->trigger_SendMiddle == mb ) return(17);
		if (_Context->trigger_SendRight == mb ) return(18);
		if (_Context->trigger_SendDown == mb ) return(19);
		if (_Context->trigger_SendUp == mb ) return(20);
		if (_Context->trigger_SendWhileDown == mb ) return(21);
		if (_Context->trigger_SendMove == mb ) return(22);
		if (_Context->trigger_MouseKey == mb ) return(23);
		if (_Context->trigger_WidgetTriggers == mb ) return(24);
		if (_Context->trigger_Escape == mb ) return(25);
		if (_Context->trigger_Enter == mb ) return(26);
		if (_Context->trigger_PageUp == mb ) return(27);
		if (_Context->trigger_PageDown == mb ) return(28);
		if (_Context->trigger_UpArrow == mb ) return(29);
		if (_Context->trigger_DownArrow == mb ) return(30);
		if (_Context->trigger_Tabulation == mb ) return(31);
		if (_Context->trigger_DefaultBreak == mb ) return(32);
		if (_Context->trigger_FormMethods == mb ) return(33);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x1031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (mt & _MIMO_UP) {
	if ((mx >= 739 )  
	&&  (my >= 69 )  
	&&  (mx <= 755 )  
	&&  (my <= 85 )) {
		return(1);	/* Auto702 */

		}
	if ((mx >= 723 )  
	&&  (my >= 69 )  
	&&  (mx <= 739 )  
	&&  (my <= 85 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vform.htm");
			};
		return(-1);	/* Auto702 */

		}
	if ((mx >= 707 )  
	&&  (my >= 69 )  
	&&  (mx <= 723 )  
	&&  (my <= 85 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		_Context->language--; _Context->language %=8;
			}
		(void) visual_national_language(_Context->language);
		accept_form_control_show();
		return(-1);	/* Auto702 */

		}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 50 ) 
		&&  (my >= 95 ) 
		&&  (mx <= 183 ) 
		&&  (my <= 119 )) {
			return(2); /* FormControl */
		}
		}
	if (( mx >= 140 ) 
	&&  ( my >= 485 ) 
	&&  ( mx <= 294 ) 
	&&  ( my <= 517 )) {
		return(3); /* Accept */
		}
	if (( mx >= 320 ) 
	&&  ( my >= 485 ) 
	&&  ( mx <= 474 ) 
	&&  ( my <= 517 )) {
		return(4); /* EditMethod */
		}
	if (( mx >= 510 ) 
	&&  ( my >= 485 ) 
	&&  ( mx <= 664 ) 
	&&  ( my <= 517 )) {
		return(5); /* Cancel */
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 90 ) 
		&&  (my >= 195 ) 
		&&  (mx <= 258 ) 
		&&  (my <= 211 )) {
			return(6); /* FormType */
		}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 320 ) 
		&&  (my >= 195 ) 
		&&  (mx <= 488 ) 
		&&  (my <= 211 )) {
			return(7); /* ProductionLanguage */
		}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 530 ) 
		&&  (my >= 195 ) 
		&&  (mx <= 698 ) 
		&&  (my <= 211 )) {
			return(8); /* NationalLanguage */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 90 ) 
		&&  ( my >= 415 ) 
		&&  ( mx <= 272 ) 
		&&  ( my <= 431 )) {
			return(9); /* International */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 440 ) 
		&&  ( my >= 415 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 431 )) {
			return(10); /* MultipleLanguage */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 90 ) 
		&&  ( my >= 355 ) 
		&&  ( mx <= 300 ) 
		&&  ( my <= 375 )) {
			return(11); /* Program */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 440 ) 
		&&  ( my >= 355 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 371 )) {
			return(12); /* Overlay */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 90 ) 
		&&  ( my >= 385 ) 
		&&  ( mx <= 300 ) 
		&&  ( my <= 405 )) {
			return(13); /* PopUp */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 440 ) 
		&&  ( my >= 385 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 401 )) {
			return(14); /* CommandLine */
		}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 184 ) 
		&&  (my >= 95 ) 
		&&  (mx <= 310 ) 
		&&  (my <= 119 )) {
			return(15); /* MouseEvents */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 165 ) 
		&&  ( mx <= 240 ) 
		&&  ( my <= 185 )) {
			return(16); /* SendLeft */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 330 ) 
		&&  ( my >= 165 ) 
		&&  ( mx <= 470 ) 
		&&  ( my <= 185 )) {
			return(17); /* SendMiddle */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 540 ) 
		&&  ( my >= 165 ) 
		&&  ( mx <= 710 ) 
		&&  ( my <= 185 )) {
			return(18); /* SendRight */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 235 ) 
		&&  ( mx <= 260 ) 
		&&  ( my <= 255 )) {
			return(19); /* SendDown */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 330 ) 
		&&  ( my >= 235 ) 
		&&  ( mx <= 490 ) 
		&&  ( my <= 255 )) {
			return(20); /* SendUp */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 265 ) 
		&&  ( mx <= 280 ) 
		&&  ( my <= 285 )) {
			return(21); /* SendWhileDown */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 330 ) 
		&&  ( my >= 265 ) 
		&&  ( mx <= 500 ) 
		&&  ( my <= 285 )) {
			return(22); /* SendMove */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 540 ) 
		&&  ( my >= 235 ) 
		&&  ( mx <= 740 ) 
		&&  ( my <= 255 )) {
			return(23); /* MouseKey */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 540 ) 
		&&  ( my >= 265 ) 
		&&  ( mx <= 690 ) 
		&&  ( my <= 285 )) {
			return(24); /* WidgetTriggers */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 335 ) 
		&&  ( mx <= 200 ) 
		&&  ( my <= 355 )) {
			return(25); /* Escape */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 330 ) 
		&&  ( my >= 335 ) 
		&&  ( mx <= 420 ) 
		&&  ( my <= 355 )) {
			return(26); /* Enter */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 375 ) 
		&&  ( mx <= 190 ) 
		&&  ( my <= 395 )) {
			return(27); /* PageUp */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 415 ) 
		&&  ( mx <= 210 ) 
		&&  ( my <= 435 )) {
			return(28); /* PageDown */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 330 ) 
		&&  ( my >= 375 ) 
		&&  ( mx <= 450 ) 
		&&  ( my <= 395 )) {
			return(29); /* UpArrow */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 330 ) 
		&&  ( my >= 415 ) 
		&&  ( mx <= 450 ) 
		&&  ( my <= 435 )) {
			return(30); /* DownArrow */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 540 ) 
		&&  ( my >= 335 ) 
		&&  ( mx <= 660 ) 
		&&  ( my <= 355 )) {
			return(31); /* Tabulation */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 540 ) 
		&&  ( my >= 375 ) 
		&&  ( mx <= 670 ) 
		&&  ( my <= 395 )) {
			return(32); /* DefaultBreak */
		}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if ((mx >= 311 ) 
		&&  (my >= 95 ) 
		&&  (mx <= 446 ) 
		&&  (my <= 119 )) {
			return(33); /* FormMethods */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 60 ) 
		&&  ( my >= 135 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 465 )) {
			if ((_Context->value_Methods = ((visual_event(6) - 135) / 16)) < 1)
				_Context->value_Methods=0;
else if (_Context->value_Methods > 19 )
				_Context->value_Methods=19;
			if ( _Context->value_Methods > 0 ) { _Context->row_Methods = &_Context->buffer_Methods[(_Context->value_Methods-1)][0]; } 
			_Context->column_Methods = (visual_event(7) - 60);
			if ( _Context->column_Methods < 137 ) {
				_Context->column_Methods = 1;
				}
			else if ( _Context->column_Methods < 402 ) {
				_Context->column_Methods = 2;
				}
			else if ( _Context->column_Methods < 659 ) {
				_Context->column_Methods = 3;
				}
			return(34); /* Methods */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 720 ) 
		&&  ( my >= 135 ) 
		&&  ( mx <= 740 ) 
		&&  ( my <= 465 )) {
			return(35); /* Auto7154 */
		}
		}

	return(-1);
}


private	int	accept_form_control_losefocus()
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;
		case 3 : 
			break;

		}
	return(0);

}


private	int	accept_form_control_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FormControl */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* Accept */
				visual_button(140,485,154,32,2,175,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(140,485,154,32,2,175,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x4 :
				/* EditMethod */
				visual_button(320,485,154,32,2,28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(320,485,154,32,2,28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),0);
				break;
			case	0x5 :
				/* Cancel */
				visual_button(510,485,154,32,2,175,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(510,485,154,32,2,175,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0x6 :
				/* FormType */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(90,195,168,144,2,27,0,parse_selection(FormTypeList,&_Context->value_FormType),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* ProductionLanguage */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(320,195,168,144,2,27,0,parse_selection(ProductionLanguageList,&_Context->value_ProductionLanguage),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* NationalLanguage */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(530,195,168,144,2,27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* International */
				if (_Context->page_number == 1 ) {
				visual_check(90,415,182,16,2,28,28,_Context->msg_International[_Context->language],strlen(_Context->msg_International[_Context->language]),(_Context->value_International |2));
					_Context->keycode = visual_getch();
				visual_check(90,415,182,16,2,28,28,_Context->msg_International[_Context->language],strlen(_Context->msg_International[_Context->language]),(_Context->value_International |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* MultipleLanguage */
				if (_Context->page_number == 1 ) {
				visual_check(440,415,280,16,2,28,28,_Context->msg_MultipleLanguage[_Context->language],strlen(_Context->msg_MultipleLanguage[_Context->language]),(_Context->value_MultipleLanguage |2));
					_Context->keycode = visual_getch();
				visual_check(440,415,280,16,2,28,28,_Context->msg_MultipleLanguage[_Context->language],strlen(_Context->msg_MultipleLanguage[_Context->language]),(_Context->value_MultipleLanguage |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* Program */
				if (_Context->page_number == 1 ) {
				visual_check(90,355,210,20,2,27,0,_Context->msg_Program[_Context->language],strlen(_Context->msg_Program[_Context->language]),(_Context->value_Program |2));
					_Context->keycode = visual_getch();
				visual_check(90,355,210,20,2,27,0,_Context->msg_Program[_Context->language],strlen(_Context->msg_Program[_Context->language]),(_Context->value_Program |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* Overlay */
				if (_Context->page_number == 1 ) {
				visual_check(440,355,280,16,2,27,0,_Context->msg_Overlay[_Context->language],strlen(_Context->msg_Overlay[_Context->language]),(_Context->value_Overlay |2));
					_Context->keycode = visual_getch();
				visual_check(440,355,280,16,2,27,0,_Context->msg_Overlay[_Context->language],strlen(_Context->msg_Overlay[_Context->language]),(_Context->value_Overlay |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* PopUp */
				if (_Context->page_number == 1 ) {
				visual_check(90,385,210,20,2,27,0,_Context->msg_PopUp[_Context->language],strlen(_Context->msg_PopUp[_Context->language]),(_Context->value_PopUp |2));
					_Context->keycode = visual_getch();
				visual_check(90,385,210,20,2,27,0,_Context->msg_PopUp[_Context->language],strlen(_Context->msg_PopUp[_Context->language]),(_Context->value_PopUp |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* CommandLine */
				if (_Context->page_number == 1 ) {
				visual_check(440,385,280,16,2,28,28,_Context->msg_CommandLine[_Context->language],strlen(_Context->msg_CommandLine[_Context->language]),(_Context->value_CommandLine |2));
					_Context->keycode = visual_getch();
				visual_check(440,385,280,16,2,28,28,_Context->msg_CommandLine[_Context->language],strlen(_Context->msg_CommandLine[_Context->language]),(_Context->value_CommandLine |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* MouseEvents */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x10 :
				/* SendLeft */
				if (_Context->page_number == 2 ) {
				visual_check(80,165,160,20,2,27,0,_Context->msg_SendLeft[_Context->language],strlen(_Context->msg_SendLeft[_Context->language]),(_Context->value_SendLeft |2));
					_Context->keycode = visual_getch();
				visual_check(80,165,160,20,2,27,0,_Context->msg_SendLeft[_Context->language],strlen(_Context->msg_SendLeft[_Context->language]),(_Context->value_SendLeft |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* SendMiddle */
				if (_Context->page_number == 2 ) {
				visual_check(330,165,140,20,2,27,0,_Context->msg_SendMiddle[_Context->language],strlen(_Context->msg_SendMiddle[_Context->language]),(_Context->value_SendMiddle |2));
					_Context->keycode = visual_getch();
				visual_check(330,165,140,20,2,27,0,_Context->msg_SendMiddle[_Context->language],strlen(_Context->msg_SendMiddle[_Context->language]),(_Context->value_SendMiddle |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* SendRight */
				if (_Context->page_number == 2 ) {
				visual_check(540,165,170,20,2,27,0,_Context->msg_SendRight[_Context->language],strlen(_Context->msg_SendRight[_Context->language]),(_Context->value_SendRight |2));
					_Context->keycode = visual_getch();
				visual_check(540,165,170,20,2,27,0,_Context->msg_SendRight[_Context->language],strlen(_Context->msg_SendRight[_Context->language]),(_Context->value_SendRight |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* SendDown */
				if (_Context->page_number == 2 ) {
				visual_check(80,235,180,20,2,27,0,_Context->msg_SendDown[_Context->language],strlen(_Context->msg_SendDown[_Context->language]),(_Context->value_SendDown |2));
					_Context->keycode = visual_getch();
				visual_check(80,235,180,20,2,27,0,_Context->msg_SendDown[_Context->language],strlen(_Context->msg_SendDown[_Context->language]),(_Context->value_SendDown |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* SendUp */
				if (_Context->page_number == 2 ) {
				visual_check(330,235,160,20,2,27,0,_Context->msg_SendUp[_Context->language],strlen(_Context->msg_SendUp[_Context->language]),(_Context->value_SendUp |2));
					_Context->keycode = visual_getch();
				visual_check(330,235,160,20,2,27,0,_Context->msg_SendUp[_Context->language],strlen(_Context->msg_SendUp[_Context->language]),(_Context->value_SendUp |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* SendWhileDown */
				if (_Context->page_number == 2 ) {
				visual_check(80,265,200,20,2,27,0,_Context->msg_SendWhileDown[_Context->language],strlen(_Context->msg_SendWhileDown[_Context->language]),(_Context->value_SendWhileDown |2));
					_Context->keycode = visual_getch();
				visual_check(80,265,200,20,2,27,0,_Context->msg_SendWhileDown[_Context->language],strlen(_Context->msg_SendWhileDown[_Context->language]),(_Context->value_SendWhileDown |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* SendMove */
				if (_Context->page_number == 2 ) {
				visual_check(330,265,170,20,2,16,0,_Context->msg_SendMove[_Context->language],strlen(_Context->msg_SendMove[_Context->language]),(_Context->value_SendMove |2));
					_Context->keycode = visual_getch();
				visual_check(330,265,170,20,2,16,0,_Context->msg_SendMove[_Context->language],strlen(_Context->msg_SendMove[_Context->language]),(_Context->value_SendMove |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* MouseKey */
				if (_Context->page_number == 2 ) {
				visual_check(540,235,200,20,2,16,0,_Context->msg_MouseKey[_Context->language],strlen(_Context->msg_MouseKey[_Context->language]),(_Context->value_MouseKey |2));
					_Context->keycode = visual_getch();
				visual_check(540,235,200,20,2,16,0,_Context->msg_MouseKey[_Context->language],strlen(_Context->msg_MouseKey[_Context->language]),(_Context->value_MouseKey |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* WidgetTriggers */
				if (_Context->page_number == 2 ) {
				visual_check(540,265,150,20,2,16,0,_Context->msg_WidgetTriggers[_Context->language],strlen(_Context->msg_WidgetTriggers[_Context->language]),(_Context->value_WidgetTriggers |2));
					_Context->keycode = visual_getch();
				visual_check(540,265,150,20,2,16,0,_Context->msg_WidgetTriggers[_Context->language],strlen(_Context->msg_WidgetTriggers[_Context->language]),(_Context->value_WidgetTriggers |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* Escape */
				if (_Context->page_number == 2 ) {
				visual_check(80,335,120,20,2,27,0,_Context->msg_Escape[_Context->language],strlen(_Context->msg_Escape[_Context->language]),(_Context->value_Escape |2));
					_Context->keycode = visual_getch();
				visual_check(80,335,120,20,2,27,0,_Context->msg_Escape[_Context->language],strlen(_Context->msg_Escape[_Context->language]),(_Context->value_Escape |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* Enter */
				if (_Context->page_number == 2 ) {
				visual_check(330,335,90,20,2,27,0,_Context->msg_Enter[_Context->language],strlen(_Context->msg_Enter[_Context->language]),(_Context->value_Enter |2));
					_Context->keycode = visual_getch();
				visual_check(330,335,90,20,2,27,0,_Context->msg_Enter[_Context->language],strlen(_Context->msg_Enter[_Context->language]),(_Context->value_Enter |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* PageUp */
				if (_Context->page_number == 2 ) {
				visual_check(80,375,110,20,2,27,0,_Context->msg_PageUp[_Context->language],strlen(_Context->msg_PageUp[_Context->language]),(_Context->value_PageUp |2));
					_Context->keycode = visual_getch();
				visual_check(80,375,110,20,2,27,0,_Context->msg_PageUp[_Context->language],strlen(_Context->msg_PageUp[_Context->language]),(_Context->value_PageUp |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* PageDown */
				if (_Context->page_number == 2 ) {
				visual_check(80,415,130,20,2,27,0,_Context->msg_PageDown[_Context->language],strlen(_Context->msg_PageDown[_Context->language]),(_Context->value_PageDown |2));
					_Context->keycode = visual_getch();
				visual_check(80,415,130,20,2,27,0,_Context->msg_PageDown[_Context->language],strlen(_Context->msg_PageDown[_Context->language]),(_Context->value_PageDown |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* UpArrow */
				if (_Context->page_number == 2 ) {
				visual_check(330,375,120,20,2,27,0,_Context->msg_UpArrow[_Context->language],strlen(_Context->msg_UpArrow[_Context->language]),(_Context->value_UpArrow |2));
					_Context->keycode = visual_getch();
				visual_check(330,375,120,20,2,27,0,_Context->msg_UpArrow[_Context->language],strlen(_Context->msg_UpArrow[_Context->language]),(_Context->value_UpArrow |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* DownArrow */
				if (_Context->page_number == 2 ) {
				visual_check(330,415,120,20,2,27,0,_Context->msg_DownArrow[_Context->language],strlen(_Context->msg_DownArrow[_Context->language]),(_Context->value_DownArrow |2));
					_Context->keycode = visual_getch();
				visual_check(330,415,120,20,2,27,0,_Context->msg_DownArrow[_Context->language],strlen(_Context->msg_DownArrow[_Context->language]),(_Context->value_DownArrow |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* Tabulation */
				if (_Context->page_number == 2 ) {
				visual_check(540,335,120,20,2,27,0,_Context->msg_Tabulation[_Context->language],strlen(_Context->msg_Tabulation[_Context->language]),(_Context->value_Tabulation |2));
					_Context->keycode = visual_getch();
				visual_check(540,335,120,20,2,27,0,_Context->msg_Tabulation[_Context->language],strlen(_Context->msg_Tabulation[_Context->language]),(_Context->value_Tabulation |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* DefaultBreak */
				if (_Context->page_number == 2 ) {
				visual_check(540,375,130,20,2,27,0,_Context->msg_DefaultBreak[_Context->language],strlen(_Context->msg_DefaultBreak[_Context->language]),(_Context->value_DefaultBreak |2));
					_Context->keycode = visual_getch();
				visual_check(540,375,130,20,2,27,0,_Context->msg_DefaultBreak[_Context->language],strlen(_Context->msg_DefaultBreak[_Context->language]),(_Context->value_DefaultBreak |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* FormMethods */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
		case	0x22 :
			/* Methods */
			if (_Context->page_number == 3 ) {
				_Context->row_Methods = &_Context->buffer_Methods[(_Context->value_Methods-1)][0];
				switch (_Context->column_Methods) {
				case	0x1 :
					_Context->keycode=visual_edit((60+4),(135+(_Context->value_Methods*16)+2),128,16,1,&_Context->buffer_Methods[(_Context->value_Methods-1)][0],16);
				visual_text((60+4),(135+(_Context->value_Methods*16)+2),128,16,1,0,(24-((_Context->value_Methods-1)&1)),&_Context->buffer_Methods[(_Context->value_Methods-1)][0],16,0);
					break;
				case	0x2 :
					_Context->keycode=visual_edit((60+140),(135+(_Context->value_Methods*16)+2),256,16,1,&_Context->buffer_Methods[(_Context->value_Methods-1)][17],32);
				visual_text((60+140),(135+(_Context->value_Methods*16)+2),256,16,1,0,(24-((_Context->value_Methods-1)&1)),&_Context->buffer_Methods[(_Context->value_Methods-1)][17],32,0);
					break;
				case	0x3 :
					_Context->keycode=visual_edit((60+404),(135+(_Context->value_Methods*16)+2),248,16,1,&_Context->buffer_Methods[(_Context->value_Methods-1)][50],31);
				visual_text((60+404),(135+(_Context->value_Methods*16)+2),248,16,1,0,(24-((_Context->value_Methods-1)&1)),&_Context->buffer_Methods[(_Context->value_Methods-1)][50],31,0);
					break;
					}
				if ( _Context->keycode == 9 ) {
					_Context->column_Methods++;
					if ( _Context->column_Methods > 3 ) {
						_Context->column_Methods=1;
						_Context->value_Methods++;
						if ( _Context->value_Methods > 19 ) {
							_Context->value_Methods=1;
							}
						}
					_Context->keycode=0;
					}
			else	_Context->keycode=5;
				}

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			accept_form_control_losefocus();
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_form_control_show();
			continue;
		case	0x2 :
			accept_form_control_losefocus();
			_Context->page_number=3;
			_Context->focus_item=35;
			accept_form_control_show();
			continue;
		case	0x3 :
			accept_form_control_losefocus();
			if ( _Context->page_number < 3 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_form_control_show();
			continue;
		case	0x12 :
			accept_form_control_losefocus();
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_form_control_show();
			continue;
			case	0x100 :
				if ((retcode=accept_form_control_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto702 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* FormControl */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_form_control_losefocus();
							_Context->page_number = 1;
							accept_form_control_show();
							}
						continue;
					case	0x3 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(140,485,154,32,2,175,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(140,485,154,32,2,175,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* EditMethod */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(320,485,154,32,2,28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(320,485,154,32,2,28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),0);
							}
						continue;
					case	0x5 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(510,485,154,32,2,175,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(510,485,154,32,2,175,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0x6 :
						/* FormType */
						continue;
					case	0x7 :
						/* ProductionLanguage */
						continue;
					case	0x8 :
						/* NationalLanguage */
						continue;
					case	0x9 :
						/* International */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_International += 1;
							_Context->value_International &= 1;
							}
						continue;
					case	0xa :
						/* MultipleLanguage */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MultipleLanguage += 1;
							_Context->value_MultipleLanguage &= 1;
							}
						continue;
					case	0xb :
						/* Program */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Program += 1;
							_Context->value_Program &= 1;
							}
						continue;
					case	0xc :
						/* Overlay */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Overlay += 1;
							_Context->value_Overlay &= 1;
							}
						continue;
					case	0xd :
						/* PopUp */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_PopUp += 1;
							_Context->value_PopUp &= 1;
							}
						continue;
					case	0xe :
						/* CommandLine */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_CommandLine += 1;
							_Context->value_CommandLine &= 1;
							}
						continue;
					case	0xf :
						/* MouseEvents */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_form_control_losefocus();
							_Context->page_number = 2;
							accept_form_control_show();
							}
						continue;
					case	0x10 :
						/* SendLeft */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SendLeft += 1;
							_Context->value_SendLeft &= 1;
							}
						continue;
					case	0x11 :
						/* SendMiddle */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SendMiddle += 1;
							_Context->value_SendMiddle &= 1;
							}
						continue;
					case	0x12 :
						/* SendRight */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SendRight += 1;
							_Context->value_SendRight &= 1;
							}
						continue;
					case	0x13 :
						/* SendDown */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SendDown += 1;
							_Context->value_SendDown &= 1;
							}
						continue;
					case	0x14 :
						/* SendUp */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SendUp += 1;
							_Context->value_SendUp &= 1;
							}
						continue;
					case	0x15 :
						/* SendWhileDown */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SendWhileDown += 1;
							_Context->value_SendWhileDown &= 1;
							}
						continue;
					case	0x16 :
						/* SendMove */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SendMove += 1;
							_Context->value_SendMove &= 1;
							}
						continue;
					case	0x17 :
						/* MouseKey */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MouseKey += 1;
							_Context->value_MouseKey &= 1;
							}
						continue;
					case	0x18 :
						/* WidgetTriggers */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_WidgetTriggers += 1;
							_Context->value_WidgetTriggers &= 1;
							}
						continue;
					case	0x19 :
						/* Escape */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Escape += 1;
							_Context->value_Escape &= 1;
							}
						continue;
					case	0x1a :
						/* Enter */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Enter += 1;
							_Context->value_Enter &= 1;
							}
						continue;
					case	0x1b :
						/* PageUp */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_PageUp += 1;
							_Context->value_PageUp &= 1;
							}
						continue;
					case	0x1c :
						/* PageDown */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_PageDown += 1;
							_Context->value_PageDown &= 1;
							}
						continue;
					case	0x1d :
						/* UpArrow */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UpArrow += 1;
							_Context->value_UpArrow &= 1;
							}
						continue;
					case	0x1e :
						/* DownArrow */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_DownArrow += 1;
							_Context->value_DownArrow &= 1;
							}
						continue;
					case	0x1f :
						/* Tabulation */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Tabulation += 1;
							_Context->value_Tabulation &= 1;
							}
						continue;
					case	0x20 :
						/* DefaultBreak */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_DefaultBreak += 1;
							_Context->value_DefaultBreak &= 1;
							}
						continue;
					case	0x21 :
						/* FormMethods */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_form_control_losefocus();
							_Context->page_number = 3;
							accept_form_control_show();
							}
						continue;
					case	0x22 :
						/* Methods */
						continue;
					case	0x23 :
						/* Auto7154 */
						(void) on_Auto7154_action();
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
				_Context->focus_item=35;
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

public	int	accept_form_control(
	char * pFormType,
	char * pProductionLanguage,
	char * pNationalLanguage,
	char * pInternational,
	char * pMultipleLanguage,
	char * pProgram,
	char * pOverlay,
	char * pPopUp,
	char * pCommandLine,
	char * pSendLeft,
	char * pSendMiddle,
	char * pSendRight,
	char * pSendDown,
	char * pSendUp,
	char * pSendWhileDown,
	char * pSendMove,
	char * pMouseKey,
	char * pWidgetTriggers,
	char * pEscape,
	char * pEnter,
	char * pPageUp,
	char * pPageDown,
	char * pUpArrow,
	char * pDownArrow,
	char * pTabulation,
	char * pDefaultBreak)
{
	int	status=0;
	status = accept_form_control_create(
	 pFormType,
	 pProductionLanguage,
	 pNationalLanguage,
	 pInternational,
	 pMultipleLanguage,
	 pProgram,
	 pOverlay,
	 pPopUp,
	 pCommandLine,
	 pSendLeft,
	 pSendMiddle,
	 pSendRight,
	 pSendDown,
	 pSendUp,
	 pSendWhileDown,
	 pSendMove,
	 pMouseKey,
	 pWidgetTriggers,
	 pEscape,
	 pEnter,
	 pPageUp,
	 pPageDown,
	 pUpArrow,
	 pDownArrow,
	 pTabulation,
	 pDefaultBreak);
	if ( status != 0) return(status);
	status = accept_form_control_show();
		enter_modal();
	status = accept_form_control_focus();
		leave_modal();
	status = accept_form_control_hide();
	status = accept_form_control_remove(
	 pFormType,
	 pProductionLanguage,
	 pNationalLanguage,
	 pInternational,
	 pMultipleLanguage,
	 pProgram,
	 pOverlay,
	 pPopUp,
	 pCommandLine,
	 pSendLeft,
	 pSendMiddle,
	 pSendRight,
	 pSendDown,
	 pSendUp,
	 pSendWhileDown,
	 pSendMove,
	 pMouseKey,
	 pWidgetTriggers,
	 pEscape,
	 pEnter,
	 pPageUp,
	 pPageDown,
	 pUpArrow,
	 pDownArrow,
	 pTabulation,
	 pDefaultBreak);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vform_c */
