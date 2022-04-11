
#ifndef _vform_c
#define _vform_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vform.xml  */
/* Target         : vform.c  */
/* Identification : 0.0-1100886760-19834.19833 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "abaltype.h"
#include "singmemb.h"
#include "singprot.h"
#define en_Auto1904   "Sing : Version 1.0a"
#define fr_Auto1904   "Sing : Version 1.0a"
#define it_Auto1904   "Sing : Version 1.0a"
#define es_Auto1904   "Sing : Version 1.0a"
#define de_Auto1904   "Sing : Version 1.0a"
#define nl_Auto1904   "Sing : Version 1.0a"
#define pt_Auto1904   "Sing : Version 1.0a"
#define xx_Auto1904   "Sing : Version 1.0a"
#define en_Auto1905   "skin.gif"
#define fr_Auto1905   "skin.gif"
#define it_Auto1905   "skin.gif"
#define es_Auto1905   "skin.gif"
#define de_Auto1905   "skin.gif"
#define nl_Auto1905   "skin.gif"
#define pt_Auto1905   "skin.gif"
#define xx_Auto1905   "skin.gif"
#define en_FormControl   "&Form Properties"
#define fr_FormControl   "&Formulaire"
#define it_FormControl   ""
#define es_FormControl   ""
#define de_FormControl   ""
#define nl_FormControl   ""
#define pt_FormControl   ""
#define xx_FormControl   ""
#define en_Auto1906   "Production Control"
#define fr_Auto1906   "Contr“le de Production"
#define it_Auto1906   ""
#define es_Auto1906   ""
#define de_Auto1906   ""
#define nl_Auto1906   ""
#define pt_Auto1906   ""
#define xx_Auto1906   ""
#define en_Auto1907   "Code Production Options"
#define fr_Auto1907   "Options Production du Code"
#define it_Auto1907   ""
#define es_Auto1907   ""
#define de_Auto1907   ""
#define nl_Auto1907   ""
#define pt_Auto1907   ""
#define xx_Auto1907   ""
#define en_Auto1908   "ARGV$="
#define fr_Auto1908   "ARGV$="
#define it_Auto1908   "ARGV$="
#define es_Auto1908   "ARGV$="
#define de_Auto1908   "ARGV$="
#define nl_Auto1908   "ARGV$="
#define pt_Auto1908   "ARGV$="
#define xx_Auto1908   "ARGV$="
#define en_Auto1909   "("
#define fr_Auto1909   "("
#define it_Auto1909   "("
#define es_Auto1909   "("
#define de_Auto1909   "("
#define nl_Auto1909   "("
#define pt_Auto1909   "("
#define xx_Auto1909   "("
#define en_Auto1910   ")"
#define fr_Auto1910   ")"
#define it_Auto1910   ")"
#define es_Auto1910   ")"
#define de_Auto1910   ")"
#define nl_Auto1910   ")"
#define pt_Auto1910   ")"
#define xx_Auto1910   ")"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_EditMethod   "&Edit Method"
#define fr_EditMethod   "&Editer Methode"
#define it_EditMethod   ""
#define es_EditMethod   ""
#define de_EditMethod   ""
#define nl_EditMethod   ""
#define pt_EditMethod   ""
#define xx_EditMethod   ""
#define en_DropMethod   "&Drop Method"
#define fr_DropMethod   "&Effacer Methode"
#define it_DropMethod   "&Drop Method"
#define es_DropMethod   "&Drop Method"
#define de_DropMethod   "&Drop Method"
#define nl_DropMethod   "&Drop Method"
#define pt_DropMethod   "&Drop Method"
#define xx_DropMethod   "&Drop Method"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
#define en_Auto1911   "Production Model"
#define fr_Auto1911   "Modele de Production"
#define it_Auto1911   ""
#define es_Auto1911   ""
#define de_Auto1911   ""
#define nl_Auto1911   ""
#define pt_Auto1911   ""
#define xx_Auto1911   ""
#define en_Auto1912   "Production Language"
#define fr_Auto1912   "Langage de Production"
#define it_Auto1912   ""
#define es_Auto1912   ""
#define de_Auto1912   ""
#define nl_Auto1912   ""
#define pt_Auto1912   ""
#define xx_Auto1912   ""
#define en_Auto1913   "National Language"
#define fr_Auto1913   "Langage Nationale"
#define it_Auto1913   ""
#define es_Auto1913   ""
#define de_Auto1913   ""
#define nl_Auto1913   ""
#define pt_Auto1913   ""
#define xx_Auto1913   ""
#define it_FormType   ""
#define es_FormType   ""
#define de_FormType   ""
#define nl_FormType   ""
#define pt_FormType   ""
#define xx_FormType   ""
#define it_ProductionLanguage   ""
#define es_ProductionLanguage   ""
#define de_ProductionLanguage   ""
#define nl_ProductionLanguage   ""
#define pt_ProductionLanguage   ""
#define xx_ProductionLanguage   ""
#define it_NationalLanguage   ""
#define es_NationalLanguage   ""
#define de_NationalLanguage   ""
#define nl_NationalLanguage   ""
#define pt_NationalLanguage   ""
#define xx_NationalLanguage   ""
#define en_International   "&Internationalisation"
#define fr_International   "&Internationalisation"
#define it_International   ""
#define es_International   ""
#define de_International   ""
#define nl_International   ""
#define pt_International   ""
#define xx_International   ""
#define en_Constants   "Inhibit &Constant Expressions"
#define fr_Constants   "Inhiber Expressions &Constants"
#define it_Constants   ""
#define es_Constants   ""
#define de_Constants   ""
#define nl_Constants   ""
#define pt_Constants   ""
#define xx_Constants   ""
#define en_MultipleLanguage   "M&ultiple Lingual Messages"
#define fr_MultipleLanguage   "&Generation Multilingue"
#define it_MultipleLanguage   ""
#define es_MultipleLanguage   ""
#define de_MultipleLanguage   ""
#define nl_MultipleLanguage   ""
#define pt_MultipleLanguage   ""
#define xx_MultipleLanguage   ""
#define en_Program   "&Stand alone Program Unit"
#define fr_Program   "&Programme autonome"
#define it_Program   ""
#define es_Program   ""
#define de_Program   ""
#define nl_Program   ""
#define pt_Program   ""
#define xx_Program   ""
#define en_Overlay   "Su&bordinate Overlay or Module"
#define fr_Overlay   "M&odule ou Programme Overlay"
#define it_Overlay   ""
#define es_Overlay   ""
#define de_Overlay   ""
#define nl_Overlay   ""
#define pt_Overlay   ""
#define xx_Overlay   ""
#define en_PopUp   "&Pop-Up style Component"
#define fr_PopUp   "Appa&rait / Disparait"
#define it_PopUp   ""
#define es_PopUp   ""
#define de_PopUp   ""
#define nl_PopUp   ""
#define pt_PopUp   ""
#define xx_PopUp   ""
#define en_Dynamic   "&Dynamic Positioning"
#define fr_Dynamic   "&Deplacement"
#define it_Dynamic   "&Dynamic Positioning"
#define es_Dynamic   "&Dynamic Positioning"
#define de_Dynamic   "&Dynamic Positioning"
#define nl_Dynamic   "&Dynamic Positioning"
#define pt_Dynamic   "&Dynamic Positioning"
#define xx_Dynamic   "&Dynamic Positioning"
#define en_CommandLine   "C&ommand Line Parameter Reception"
#define fr_CommandLine   "Ge&stion de Ligne de Commande"
#define it_CommandLine   ""
#define es_CommandLine   ""
#define de_CommandLine   ""
#define nl_CommandLine   ""
#define pt_CommandLine   ""
#define xx_CommandLine   ""
#define en_ArgVLen   ""
#define en_ArgVNb   ""
#define en_MouseEvents   "E&vent Manager"
#define fr_MouseEvents   "Eve&nements"
#define it_MouseEvents   ""
#define es_MouseEvents   ""
#define de_MouseEvents   ""
#define nl_MouseEvents   ""
#define pt_MouseEvents   ""
#define xx_MouseEvents   ""
#define en_Auto1914   "Mouse Buttons"
#define fr_Auto1914   "Boutons du Souris"
#define it_Auto1914   ""
#define es_Auto1914   ""
#define de_Auto1914   ""
#define nl_Auto1914   ""
#define pt_Auto1914   ""
#define xx_Auto1914   ""
#define en_Auto1915   "Mouse Events"
#define fr_Auto1915   "Evenements Souris"
#define it_Auto1915   ""
#define es_Auto1915   ""
#define de_Auto1915   ""
#define nl_Auto1915   ""
#define pt_Auto1915   ""
#define xx_Auto1915   ""
#define en_Auto1916   "Keyboard Events"
#define fr_Auto1916   "Evenements Clavier"
#define it_Auto1916   ""
#define es_Auto1916   ""
#define de_Auto1916   ""
#define nl_Auto1916   ""
#define pt_Auto1916   ""
#define xx_Auto1916   ""
#define en_SendLeft   "M&ouse Left Button"
#define fr_SendLeft   "&Bouton Gauche du Souris"
#define it_SendLeft   ""
#define es_SendLeft   ""
#define de_SendLeft   ""
#define nl_SendLeft   ""
#define pt_SendLeft   ""
#define xx_SendLeft   ""
#define en_SendMiddle   "M&iddle Button"
#define fr_SendMiddle   "B&outon de Mileu du Souris"
#define it_SendMiddle   ""
#define es_SendMiddle   ""
#define de_SendMiddle   ""
#define nl_SendMiddle   ""
#define pt_SendMiddle   ""
#define xx_SendMiddle   ""
#define en_SendRight   "Mo&use Right Button"
#define fr_SendRight   "Bo&uton Droite du Souris"
#define it_SendRight   ""
#define es_SendRight   ""
#define de_SendRight   ""
#define nl_SendRight   ""
#define pt_SendRight   ""
#define xx_SendRight   ""
#define en_SendDown   "Mou&se Button DOWN"
#define fr_SendDown   "Bou&ton de souris appuy‚"
#define it_SendDown   ""
#define es_SendDown   ""
#define de_SendDown   ""
#define nl_SendDown   ""
#define pt_SendDown   ""
#define xx_SendDown   ""
#define en_SendUp   "Mouse &Button UP"
#define fr_SendUp   "Bouton &de souris relach‚"
#define it_SendUp   ""
#define es_SendUp   ""
#define de_SendUp   ""
#define nl_SendUp   ""
#define pt_SendUp   ""
#define xx_SendUp   ""
#define en_SendWhileDown   "Mouse Move &While Down"
#define fr_SendWhileDown   "De&placement bouton appuy‚"
#define it_SendWhileDown   ""
#define es_SendWhileDown   ""
#define de_SendWhileDown   ""
#define nl_SendWhileDown   ""
#define pt_SendWhileDown   ""
#define xx_SendWhileDown   ""
#define en_SendMove   "Mouse &Pointer Move"
#define fr_SendMove   "Dep&lacement souris libre"
#define it_SendMove   ""
#define es_SendMove   ""
#define de_SendMove   ""
#define nl_SendMove   ""
#define pt_SendMove   ""
#define xx_SendMove   ""
#define en_MouseKey   "Mouse Eve&nt Channel"
#define fr_MouseKey   "&Gestion Canal Souris"
#define it_MouseKey   ""
#define es_MouseKey   ""
#define de_MouseKey   ""
#define nl_MouseKey   ""
#define pt_MouseKey   ""
#define xx_MouseKey   ""
#define en_WidgetTriggers   "Wi&dget Triggers"
#define fr_WidgetTriggers   "Ge&stion Touches Racourcis"
#define it_WidgetTriggers   ""
#define es_WidgetTriggers   ""
#define de_WidgetTriggers   ""
#define nl_WidgetTriggers   ""
#define pt_WidgetTriggers   ""
#define xx_WidgetTriggers   ""
#define en_Escape   "Escape &Key"
#define fr_Escape   "Tou&che d'Echappement"
#define it_Escape   ""
#define es_Escape   ""
#define de_Escape   ""
#define nl_Escape   ""
#define pt_Escape   ""
#define xx_Escape   ""
#define en_Enter   "En&ter"
#define fr_Enter   "Touc&he de Validation"
#define it_Enter   ""
#define es_Enter   ""
#define de_Enter   ""
#define nl_Enter   ""
#define pt_Enter   ""
#define xx_Enter   ""
#define en_PageUp   "Pa&ge Up"
#define fr_PageUp   "Touche Page ve&rs le Haut"
#define it_PageUp   ""
#define es_PageUp   ""
#define de_PageUp   ""
#define nl_PageUp   ""
#define pt_PageUp   ""
#define xx_PageUp   ""
#define en_PageDown   "Page Down"
#define fr_PageDown   "Touche Page vers le Bas"
#define it_PageDown   ""
#define es_PageDown   ""
#define de_PageDown   ""
#define nl_PageDown   ""
#define pt_PageDown   ""
#define xx_PageDown   ""
#define en_UpArrow   "Up Arrow"
#define fr_UpArrow   "Touche Fleche Haute"
#define it_UpArrow   ""
#define es_UpArrow   ""
#define de_UpArrow   ""
#define nl_UpArrow   ""
#define pt_UpArrow   ""
#define xx_UpArrow   ""
#define en_DownArrow   "Down Arrow"
#define fr_DownArrow   "Touche Fleche vers le Bas"
#define it_DownArrow   ""
#define es_DownArrow   ""
#define de_DownArrow   ""
#define nl_DownArrow   ""
#define pt_DownArrow   ""
#define xx_DownArrow   ""
#define en_Tabulation   "Tabulation"
#define fr_Tabulation   "Touche de Tabulation"
#define it_Tabulation   ""
#define es_Tabulation   ""
#define de_Tabulation   ""
#define nl_Tabulation   ""
#define pt_Tabulation   ""
#define xx_Tabulation   ""
#define en_DefaultBreak   "Default Break"
#define fr_DefaultBreak   "Break sur autre touche"
#define it_DefaultBreak   ""
#define es_DefaultBreak   ""
#define de_DefaultBreak   ""
#define nl_DefaultBreak   ""
#define pt_DefaultBreak   ""
#define xx_DefaultBreak   ""
#define en_FormMethods   "&Method Manager"
#define fr_FormMethods   "&Methodes"
#define it_FormMethods   ""
#define es_FormMethods   ""
#define de_FormMethods   ""
#define nl_FormMethods   ""
#define pt_FormMethods   ""
#define xx_FormMethods   ""
#define en_Methods   "Return|Name|Parameters"
#define fr_Methods   "Retour|Nom|ParamŠtres"
#define it_Methods   ""
#define es_Methods   ""
#define de_Methods   ""
#define nl_Methods   ""
#define pt_Methods   ""
#define xx_Methods   ""
#define en_ScrollBar   ""
#define fr_ScrollBar   ""
#define en_FormMemberPage   "&Member Manager"
#define fr_FormMemberPage   "&Membres"
#define it_FormMemberPage   "&Member Manager"
#define es_FormMemberPage   "&Member Manager"
#define de_FormMemberPage   "&Member Manager"
#define nl_FormMemberPage   "&Member Manager"
#define pt_FormMemberPage   "&Member Manager"
#define xx_FormMemberPage   "&Member Manager"
#define en_TypeSelect   "byte|word|bcd|string|long"
#define fr_TypeSelect   "byte|word|bcd|string|long"
#define it_TypeSelect   "byte|word|bcd|string|long"
#define es_TypeSelect   "byte|word|bcd|string|long"
#define de_TypeSelect   "byte|word|bcd|string|long"
#define nl_TypeSelect   "byte|word|bcd|string|long"
#define pt_TypeSelect   "byte|word|bcd|string|long"
#define xx_TypeSelect   "byte|word|bcd|string|long"
#define en_FormMembers   "Name|Type|Length|1st|2nd"
#define fr_FormMembers   "Nom|Type|Longueur|1ere|2eme"
#define it_FormMembers   "Name|Type|Length|1st|2nd"
#define es_FormMembers   "Name|Type|Length|1st|2nd"
#define de_FormMembers   "Name|Type|Length|1st|2nd"
#define nl_FormMembers   "Name|Type|Length|1st|2nd"
#define pt_FormMembers   "Name|Type|Length|1st|2nd"
#define xx_FormMembers   "Name|Type|Length|1st|2nd"
#define en_MemberBar   ""
#define fr_MemberBar   ""
#define en_Auto1917   "&Production"
#define fr_Auto1917   "Production"
#define it_Auto1917   "Production"
#define es_Auto1917   "Production"
#define de_Auto1917   "Produktion"
#define nl_Auto1917   "Production"
#define pt_Auto1917   "Production"
#define xx_Auto1917   "Production"
#define en_Auto1918   "Production Parameters"
#define en_Auto1919   ""
#define en_Auto1920   ""
#define en_auto7   "Production Filename"
#define fr_auto7   "Nom de Fichier de Production Abal++"
#define en_auto52   "Component Identification"
#define fr_auto52   "Identificateur de Composant"
#define it_auto52   ""
#define es_auto52   ""
#define de_auto52   ""
#define nl_auto52   ""
#define pt_auto52   ""
#define xx_auto52   ""
#define en_Auto1921   "Filename containing the Style Classes"
#define fr_Auto1921   "Nom de fichier des classes de styles"
#define it_Auto1921   "Style"
#define es_Auto1921   "Style"
#define de_Auto1921   "Style"
#define nl_Auto1921   "ARGV$="
#define pt_Auto1921   "ARGV$="
#define xx_Auto1921   "ARGV$="
#define en_Auto1922   "Classname of Screen Background Style"
#define fr_Auto1922   "Nom du classe de style du fond d'ecran"
#define it_Auto1922   "Class"
#define es_Auto1922   "Class"
#define de_Auto1922   "Class"
#define nl_Auto1922   "Class"
#define pt_Auto1922   "Class"
#define xx_Auto1922   "Class"
#define en_FileName   ""
#define en_Auto1923   "bille.gif"
#define en_Auto1924   "bille.gif"
#define en_Identity   ""
#define en_StyleSheet   ""
#define en_ClearScreen   ""
static int	vfh[10];

private struct accept_form_control_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[5+1];
	char * msg_Auto1904[8];
	int	x_Auto1904;
	int	y_Auto1904;
	int	w_Auto1904;
	int	h_Auto1904;
	char * msg_Auto1905[8];
	char * msg_FormControl[8];
	int	trigger_FormControl;
	int	s_FormControl;
	void *	p_FormControl;
	int	page_number;
	char * msg_Auto1906[8];
	char * msg_Auto1907[8];
	char * msg_Auto1908[8];
	char * msg_Auto1909[8];
	char * msg_Auto1910[8];
	char * msg_Accept[8];
	int	trigger_Accept;
	int	s_Accept;
	void *	p_Accept;
	char * msg_EditMethod[8];
	int	trigger_EditMethod;
	char * msg_DropMethod[8];
	int	trigger_DropMethod;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	int	s_Cancel;
	void *	p_Cancel;
	char * msg_Auto1911[8];
	char * msg_Auto1912[8];
	char * msg_Auto1913[8];
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
	char * msg_Constants[8];
	int	trigger_Constants;
	int	value_Constants;
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
	char * msg_Dynamic[8];
	int	trigger_Dynamic;
	int	value_Dynamic;
	char * msg_CommandLine[8];
	int	trigger_CommandLine;
	int	value_CommandLine;
	char	buffer_ArgVLen[13];
	char	buffer_ArgVNb[14];
	char * msg_MouseEvents[8];
	int	trigger_MouseEvents;
	char * msg_Auto1914[8];
	char * msg_Auto1915[8];
	char * msg_Auto1916[8];
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
	int	value_ScrollBar;
	int	limit_ScrollBar;
	int	max_ScrollBar;
	char * msg_FormMemberPage[8];
	int	trigger_FormMemberPage;
	char * msg_TypeSelect[8];
	int	x_TypeSelect;
	int	y_TypeSelect;
	int	w_TypeSelect;
	int	h_TypeSelect;
	int	fg_TypeSelect;
	int	bg_TypeSelect;
	int	fid_TypeSelect;
	int	s_TypeSelect;
	void *	p_TypeSelect;
	int	value_TypeSelect;
	char * msg_FormMembers[8];
	int	value_FormMembers;
	int	column_FormMembers;
	char	buffer_FormMembers[19][82];
	char * row_FormMembers;
	int	value_MemberBar;
	int	limit_MemberBar;
	int	max_MemberBar;
	char * msg_Auto1917[8];
	int	trigger_Auto1917;
	char * msg_Auto1918[8];
	char * msg_auto7[8];
	char * msg_auto52[8];
	char * msg_Auto1921[8];
	char * msg_Auto1922[8];
	char	buffer_FileName[76];
	char * msg_Auto1923[8];
	int	trigger_Auto1923;
	char * msg_Auto1924[8];
	int	trigger_Auto1924;
	char	buffer_Identity[79];
	char	buffer_StyleSheet[76];
	char	buffer_ClearScreen[79];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[35];
	};
static void	putstring(struct accept_form_control_context * _Context,char * rptr, int rlen, char * sptr);

/*	--------------------	*/
/*	p u t s t r i n g ()	*/
/*	--------------------	*/
static void	putstring(struct accept_form_control_context * _Context,char * rptr, int rlen, char * sptr){
	int i;
	for(i=0;i<rlen;i++){
	if(!(*(sptr+i)))
	break;
	else*(rptr+i)=*(sptr+i);
	}
	for(;i<rlen;i++){*(rptr+i)=' ';}
	return;

}

public	int	accept_form_control_create(
	struct accept_form_control_context ** cptr,
	char * pFormType,
	char * pProductionLanguage,
	char * pNationalLanguage,
	char * pInternational,
	char * pConstants,
	char * pMultipleLanguage,
	char * pProgram,
	char * pOverlay,
	char * pPopUp,
	char * pDynamic,
	char * pCommandLine,
	char * pArgVLen,
	char * pArgVNb,
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
	char * pDefaultBreak,
	char * pFileName,
	char * pIdentity,
	char * pStyleSheet,
	char * pClearScreen)
{

	int i;
	struct accept_form_control_context * _Context=(struct accept_form_control_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_form_control_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=52;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWSSSS");
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
		visual_transferin((void *) 0, 0, pConstants);
		if (!( pConstants )) _Context->value_Constants=0;
		else	_Context->value_Constants = *((int *)pConstants);
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
		visual_transferin((void *) 0, 0, pDynamic);
		if (!( pDynamic )) _Context->value_Dynamic=0;
		else	_Context->value_Dynamic = *((int *)pDynamic);
		visual_transferin((void *) 0, 0, pCommandLine);
		if (!( pCommandLine )) _Context->value_CommandLine=0;
		else	_Context->value_CommandLine = *((int *)pCommandLine);
		visual_transferin(_Context->buffer_ArgVLen, 12, pArgVLen);
		visual_transferin(_Context->buffer_ArgVNb, 13, pArgVNb);
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
		visual_transferin(_Context->buffer_FileName, 75, pFileName);
		visual_transferin(_Context->buffer_Identity, 78, pIdentity);
		visual_transferin(_Context->buffer_StyleSheet, 75, pStyleSheet);
		visual_transferin(_Context->buffer_ClearScreen, 78, pClearScreen);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto1904[i]=" ";
	_Context->msg_Auto1904[0]=en_Auto1904;
	_Context->msg_Auto1904[1]=fr_Auto1904;
	_Context->msg_Auto1904[2]=it_Auto1904;
	_Context->msg_Auto1904[3]=es_Auto1904;
	_Context->msg_Auto1904[4]=de_Auto1904;
	_Context->msg_Auto1904[5]=nl_Auto1904;
	_Context->msg_Auto1904[6]=pt_Auto1904;
	_Context->msg_Auto1904[7]=xx_Auto1904;
	_Context->x_Auto1904=40;
	_Context->y_Auto1904=65;
	_Context->w_Auto1904=720;
	_Context->h_Auto1904=470;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1905[i]=" ";
	_Context->msg_Auto1905[0]=en_Auto1905;
	_Context->msg_Auto1905[1]=fr_Auto1905;
	_Context->msg_Auto1905[2]=it_Auto1905;
	_Context->msg_Auto1905[3]=es_Auto1905;
	_Context->msg_Auto1905[4]=de_Auto1905;
	_Context->msg_Auto1905[5]=nl_Auto1905;
	_Context->msg_Auto1905[6]=pt_Auto1905;
	_Context->msg_Auto1905[7]=xx_Auto1905;
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
	_Context->p_FormControl=visual_buffer(_Context->x_Auto1904+10,_Context->y_Auto1904+30,700,380);
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_Auto1906[i]=" ";
	_Context->msg_Auto1906[0]=en_Auto1906;
	_Context->msg_Auto1906[1]=fr_Auto1906;
	_Context->msg_Auto1906[2]=it_Auto1906;
	_Context->msg_Auto1906[3]=es_Auto1906;
	_Context->msg_Auto1906[4]=de_Auto1906;
	_Context->msg_Auto1906[5]=nl_Auto1906;
	_Context->msg_Auto1906[6]=pt_Auto1906;
	_Context->msg_Auto1906[7]=xx_Auto1906;
	for (i=0; i < 8; i++)_Context->msg_Auto1907[i]=" ";
	_Context->msg_Auto1907[0]=en_Auto1907;
	_Context->msg_Auto1907[1]=fr_Auto1907;
	_Context->msg_Auto1907[2]=it_Auto1907;
	_Context->msg_Auto1907[3]=es_Auto1907;
	_Context->msg_Auto1907[4]=de_Auto1907;
	_Context->msg_Auto1907[5]=nl_Auto1907;
	_Context->msg_Auto1907[6]=pt_Auto1907;
	_Context->msg_Auto1907[7]=xx_Auto1907;
	for (i=0; i < 8; i++)_Context->msg_Auto1908[i]=" ";
	_Context->msg_Auto1908[0]=en_Auto1908;
	_Context->msg_Auto1908[1]=fr_Auto1908;
	_Context->msg_Auto1908[2]=it_Auto1908;
	_Context->msg_Auto1908[3]=es_Auto1908;
	_Context->msg_Auto1908[4]=de_Auto1908;
	_Context->msg_Auto1908[5]=nl_Auto1908;
	_Context->msg_Auto1908[6]=pt_Auto1908;
	_Context->msg_Auto1908[7]=xx_Auto1908;
	for (i=0; i < 8; i++)_Context->msg_Auto1909[i]=" ";
	_Context->msg_Auto1909[0]=en_Auto1909;
	_Context->msg_Auto1909[1]=fr_Auto1909;
	_Context->msg_Auto1909[2]=it_Auto1909;
	_Context->msg_Auto1909[3]=es_Auto1909;
	_Context->msg_Auto1909[4]=de_Auto1909;
	_Context->msg_Auto1909[5]=nl_Auto1909;
	_Context->msg_Auto1909[6]=pt_Auto1909;
	_Context->msg_Auto1909[7]=xx_Auto1909;
	for (i=0; i < 8; i++)_Context->msg_Auto1910[i]=" ";
	_Context->msg_Auto1910[0]=en_Auto1910;
	_Context->msg_Auto1910[1]=fr_Auto1910;
	_Context->msg_Auto1910[2]=it_Auto1910;
	_Context->msg_Auto1910[3]=es_Auto1910;
	_Context->msg_Auto1910[4]=de_Auto1910;
	_Context->msg_Auto1910[5]=nl_Auto1910;
	_Context->msg_Auto1910[6]=pt_Auto1910;
	_Context->msg_Auto1910[7]=xx_Auto1910;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->s_Accept=0;
	_Context->p_Accept=visual_buffer(_Context->x_Auto1904+20,_Context->y_Auto1904+420,154,32);
	for (i=0; i < 8; i++)_Context->msg_EditMethod[i]=" ";
	_Context->msg_EditMethod[0]=en_EditMethod;
	_Context->msg_EditMethod[1]=fr_EditMethod;
	_Context->msg_EditMethod[2]=it_EditMethod;
	_Context->msg_EditMethod[3]=es_EditMethod;
	_Context->msg_EditMethod[4]=de_EditMethod;
	_Context->msg_EditMethod[5]=nl_EditMethod;
	_Context->msg_EditMethod[6]=pt_EditMethod;
	_Context->msg_EditMethod[7]=xx_EditMethod;
	for (i=0; i < 8; i++)_Context->msg_DropMethod[i]=" ";
	_Context->msg_DropMethod[0]=en_DropMethod;
	_Context->msg_DropMethod[1]=fr_DropMethod;
	_Context->msg_DropMethod[2]=it_DropMethod;
	_Context->msg_DropMethod[3]=es_DropMethod;
	_Context->msg_DropMethod[4]=de_DropMethod;
	_Context->msg_DropMethod[5]=nl_DropMethod;
	_Context->msg_DropMethod[6]=pt_DropMethod;
	_Context->msg_DropMethod[7]=xx_DropMethod;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->s_Cancel=0;
	_Context->p_Cancel=visual_buffer(_Context->x_Auto1904+550,_Context->y_Auto1904+420,154,32);
	for (i=0; i < 8; i++)_Context->msg_Auto1911[i]=" ";
	_Context->msg_Auto1911[0]=en_Auto1911;
	_Context->msg_Auto1911[1]=fr_Auto1911;
	_Context->msg_Auto1911[2]=it_Auto1911;
	_Context->msg_Auto1911[3]=es_Auto1911;
	_Context->msg_Auto1911[4]=de_Auto1911;
	_Context->msg_Auto1911[5]=nl_Auto1911;
	_Context->msg_Auto1911[6]=pt_Auto1911;
	_Context->msg_Auto1911[7]=xx_Auto1911;
	for (i=0; i < 8; i++)_Context->msg_Auto1912[i]=" ";
	_Context->msg_Auto1912[0]=en_Auto1912;
	_Context->msg_Auto1912[1]=fr_Auto1912;
	_Context->msg_Auto1912[2]=it_Auto1912;
	_Context->msg_Auto1912[3]=es_Auto1912;
	_Context->msg_Auto1912[4]=de_Auto1912;
	_Context->msg_Auto1912[5]=nl_Auto1912;
	_Context->msg_Auto1912[6]=pt_Auto1912;
	_Context->msg_Auto1912[7]=xx_Auto1912;
	for (i=0; i < 8; i++)_Context->msg_Auto1913[i]=" ";
	_Context->msg_Auto1913[0]=en_Auto1913;
	_Context->msg_Auto1913[1]=fr_Auto1913;
	_Context->msg_Auto1913[2]=it_Auto1913;
	_Context->msg_Auto1913[3]=es_Auto1913;
	_Context->msg_Auto1913[4]=de_Auto1913;
	_Context->msg_Auto1913[5]=nl_Auto1913;
	_Context->msg_Auto1913[6]=pt_Auto1913;
	_Context->msg_Auto1913[7]=xx_Auto1913;
	for (i=0; i < 8; i++)_Context->msg_FormType[i]=" ";
	_Context->msg_FormType[2]=it_FormType;
	_Context->msg_FormType[3]=es_FormType;
	_Context->msg_FormType[4]=de_FormType;
	_Context->msg_FormType[5]=nl_FormType;
	_Context->msg_FormType[6]=pt_FormType;
	_Context->msg_FormType[7]=xx_FormType;
	_Context->s_FormType=0;
	_Context->p_FormType=visual_buffer(_Context->x_Auto1904+50,_Context->y_Auto1904+130,168,144);
	for (i=0; i < 8; i++)_Context->msg_ProductionLanguage[i]=" ";
	_Context->msg_ProductionLanguage[2]=it_ProductionLanguage;
	_Context->msg_ProductionLanguage[3]=es_ProductionLanguage;
	_Context->msg_ProductionLanguage[4]=de_ProductionLanguage;
	_Context->msg_ProductionLanguage[5]=nl_ProductionLanguage;
	_Context->msg_ProductionLanguage[6]=pt_ProductionLanguage;
	_Context->msg_ProductionLanguage[7]=xx_ProductionLanguage;
	_Context->s_ProductionLanguage=0;
	_Context->p_ProductionLanguage=visual_buffer(_Context->x_Auto1904+280,_Context->y_Auto1904+130,168,144);
	for (i=0; i < 8; i++)_Context->msg_NationalLanguage[i]=" ";
	_Context->msg_NationalLanguage[2]=it_NationalLanguage;
	_Context->msg_NationalLanguage[3]=es_NationalLanguage;
	_Context->msg_NationalLanguage[4]=de_NationalLanguage;
	_Context->msg_NationalLanguage[5]=nl_NationalLanguage;
	_Context->msg_NationalLanguage[6]=pt_NationalLanguage;
	_Context->msg_NationalLanguage[7]=xx_NationalLanguage;
	for (i=0; i < 8; i++)_Context->msg_International[i]=" ";
	_Context->msg_International[0]=en_International;
	_Context->msg_International[1]=fr_International;
	_Context->msg_International[2]=it_International;
	_Context->msg_International[3]=es_International;
	_Context->msg_International[4]=de_International;
	_Context->msg_International[5]=nl_International;
	_Context->msg_International[6]=pt_International;
	_Context->msg_International[7]=xx_International;
	for (i=0; i < 8; i++)_Context->msg_Constants[i]=" ";
	_Context->msg_Constants[0]=en_Constants;
	_Context->msg_Constants[1]=fr_Constants;
	_Context->msg_Constants[2]=it_Constants;
	_Context->msg_Constants[3]=es_Constants;
	_Context->msg_Constants[4]=de_Constants;
	_Context->msg_Constants[5]=nl_Constants;
	_Context->msg_Constants[6]=pt_Constants;
	_Context->msg_Constants[7]=xx_Constants;
	for (i=0; i < 8; i++)_Context->msg_MultipleLanguage[i]=" ";
	_Context->msg_MultipleLanguage[0]=en_MultipleLanguage;
	_Context->msg_MultipleLanguage[1]=fr_MultipleLanguage;
	_Context->msg_MultipleLanguage[2]=it_MultipleLanguage;
	_Context->msg_MultipleLanguage[3]=es_MultipleLanguage;
	_Context->msg_MultipleLanguage[4]=de_MultipleLanguage;
	_Context->msg_MultipleLanguage[5]=nl_MultipleLanguage;
	_Context->msg_MultipleLanguage[6]=pt_MultipleLanguage;
	_Context->msg_MultipleLanguage[7]=xx_MultipleLanguage;
	for (i=0; i < 8; i++)_Context->msg_Program[i]=" ";
	_Context->msg_Program[0]=en_Program;
	_Context->msg_Program[1]=fr_Program;
	_Context->msg_Program[2]=it_Program;
	_Context->msg_Program[3]=es_Program;
	_Context->msg_Program[4]=de_Program;
	_Context->msg_Program[5]=nl_Program;
	_Context->msg_Program[6]=pt_Program;
	_Context->msg_Program[7]=xx_Program;
	_Context->s_Program=0;
	_Context->p_Program=visual_buffer(_Context->x_Auto1904+50,_Context->y_Auto1904+230,322,16);
	for (i=0; i < 8; i++)_Context->msg_Overlay[i]=" ";
	_Context->msg_Overlay[0]=en_Overlay;
	_Context->msg_Overlay[1]=fr_Overlay;
	_Context->msg_Overlay[2]=it_Overlay;
	_Context->msg_Overlay[3]=es_Overlay;
	_Context->msg_Overlay[4]=de_Overlay;
	_Context->msg_Overlay[5]=nl_Overlay;
	_Context->msg_Overlay[6]=pt_Overlay;
	_Context->msg_Overlay[7]=xx_Overlay;
	_Context->s_Overlay=0;
	_Context->p_Overlay=visual_buffer(_Context->x_Auto1904+400,_Context->y_Auto1904+230,280,16);
	for (i=0; i < 8; i++)_Context->msg_PopUp[i]=" ";
	_Context->msg_PopUp[0]=en_PopUp;
	_Context->msg_PopUp[1]=fr_PopUp;
	_Context->msg_PopUp[2]=it_PopUp;
	_Context->msg_PopUp[3]=es_PopUp;
	_Context->msg_PopUp[4]=de_PopUp;
	_Context->msg_PopUp[5]=nl_PopUp;
	_Context->msg_PopUp[6]=pt_PopUp;
	_Context->msg_PopUp[7]=xx_PopUp;
	for (i=0; i < 8; i++)_Context->msg_Dynamic[i]=" ";
	_Context->msg_Dynamic[0]=en_Dynamic;
	_Context->msg_Dynamic[1]=fr_Dynamic;
	_Context->msg_Dynamic[2]=it_Dynamic;
	_Context->msg_Dynamic[3]=es_Dynamic;
	_Context->msg_Dynamic[4]=de_Dynamic;
	_Context->msg_Dynamic[5]=nl_Dynamic;
	_Context->msg_Dynamic[6]=pt_Dynamic;
	_Context->msg_Dynamic[7]=xx_Dynamic;
	for (i=0; i < 8; i++)_Context->msg_CommandLine[i]=" ";
	_Context->msg_CommandLine[0]=en_CommandLine;
	_Context->msg_CommandLine[1]=fr_CommandLine;
	_Context->msg_CommandLine[2]=it_CommandLine;
	_Context->msg_CommandLine[3]=es_CommandLine;
	_Context->msg_CommandLine[4]=de_CommandLine;
	_Context->msg_CommandLine[5]=nl_CommandLine;
	_Context->msg_CommandLine[6]=pt_CommandLine;
	_Context->msg_CommandLine[7]=xx_CommandLine;
	for (i=0; i < 8; i++)_Context->msg_MouseEvents[i]=" ";
	_Context->msg_MouseEvents[0]=en_MouseEvents;
	_Context->msg_MouseEvents[1]=fr_MouseEvents;
	_Context->msg_MouseEvents[2]=it_MouseEvents;
	_Context->msg_MouseEvents[3]=es_MouseEvents;
	_Context->msg_MouseEvents[4]=de_MouseEvents;
	_Context->msg_MouseEvents[5]=nl_MouseEvents;
	_Context->msg_MouseEvents[6]=pt_MouseEvents;
	_Context->msg_MouseEvents[7]=xx_MouseEvents;
	_Context->focus_pages[2]=20;
	for (i=0; i < 8; i++)_Context->msg_Auto1914[i]=" ";
	_Context->msg_Auto1914[0]=en_Auto1914;
	_Context->msg_Auto1914[1]=fr_Auto1914;
	_Context->msg_Auto1914[2]=it_Auto1914;
	_Context->msg_Auto1914[3]=es_Auto1914;
	_Context->msg_Auto1914[4]=de_Auto1914;
	_Context->msg_Auto1914[5]=nl_Auto1914;
	_Context->msg_Auto1914[6]=pt_Auto1914;
	_Context->msg_Auto1914[7]=xx_Auto1914;
	for (i=0; i < 8; i++)_Context->msg_Auto1915[i]=" ";
	_Context->msg_Auto1915[0]=en_Auto1915;
	_Context->msg_Auto1915[1]=fr_Auto1915;
	_Context->msg_Auto1915[2]=it_Auto1915;
	_Context->msg_Auto1915[3]=es_Auto1915;
	_Context->msg_Auto1915[4]=de_Auto1915;
	_Context->msg_Auto1915[5]=nl_Auto1915;
	_Context->msg_Auto1915[6]=pt_Auto1915;
	_Context->msg_Auto1915[7]=xx_Auto1915;
	for (i=0; i < 8; i++)_Context->msg_Auto1916[i]=" ";
	_Context->msg_Auto1916[0]=en_Auto1916;
	_Context->msg_Auto1916[1]=fr_Auto1916;
	_Context->msg_Auto1916[2]=it_Auto1916;
	_Context->msg_Auto1916[3]=es_Auto1916;
	_Context->msg_Auto1916[4]=de_Auto1916;
	_Context->msg_Auto1916[5]=nl_Auto1916;
	_Context->msg_Auto1916[6]=pt_Auto1916;
	_Context->msg_Auto1916[7]=xx_Auto1916;
	for (i=0; i < 8; i++)_Context->msg_SendLeft[i]=" ";
	_Context->msg_SendLeft[0]=en_SendLeft;
	_Context->msg_SendLeft[1]=fr_SendLeft;
	_Context->msg_SendLeft[2]=it_SendLeft;
	_Context->msg_SendLeft[3]=es_SendLeft;
	_Context->msg_SendLeft[4]=de_SendLeft;
	_Context->msg_SendLeft[5]=nl_SendLeft;
	_Context->msg_SendLeft[6]=pt_SendLeft;
	_Context->msg_SendLeft[7]=xx_SendLeft;
	for (i=0; i < 8; i++)_Context->msg_SendMiddle[i]=" ";
	_Context->msg_SendMiddle[0]=en_SendMiddle;
	_Context->msg_SendMiddle[1]=fr_SendMiddle;
	_Context->msg_SendMiddle[2]=it_SendMiddle;
	_Context->msg_SendMiddle[3]=es_SendMiddle;
	_Context->msg_SendMiddle[4]=de_SendMiddle;
	_Context->msg_SendMiddle[5]=nl_SendMiddle;
	_Context->msg_SendMiddle[6]=pt_SendMiddle;
	_Context->msg_SendMiddle[7]=xx_SendMiddle;
	for (i=0; i < 8; i++)_Context->msg_SendRight[i]=" ";
	_Context->msg_SendRight[0]=en_SendRight;
	_Context->msg_SendRight[1]=fr_SendRight;
	_Context->msg_SendRight[2]=it_SendRight;
	_Context->msg_SendRight[3]=es_SendRight;
	_Context->msg_SendRight[4]=de_SendRight;
	_Context->msg_SendRight[5]=nl_SendRight;
	_Context->msg_SendRight[6]=pt_SendRight;
	_Context->msg_SendRight[7]=xx_SendRight;
	for (i=0; i < 8; i++)_Context->msg_SendDown[i]=" ";
	_Context->msg_SendDown[0]=en_SendDown;
	_Context->msg_SendDown[1]=fr_SendDown;
	_Context->msg_SendDown[2]=it_SendDown;
	_Context->msg_SendDown[3]=es_SendDown;
	_Context->msg_SendDown[4]=de_SendDown;
	_Context->msg_SendDown[5]=nl_SendDown;
	_Context->msg_SendDown[6]=pt_SendDown;
	_Context->msg_SendDown[7]=xx_SendDown;
	for (i=0; i < 8; i++)_Context->msg_SendUp[i]=" ";
	_Context->msg_SendUp[0]=en_SendUp;
	_Context->msg_SendUp[1]=fr_SendUp;
	_Context->msg_SendUp[2]=it_SendUp;
	_Context->msg_SendUp[3]=es_SendUp;
	_Context->msg_SendUp[4]=de_SendUp;
	_Context->msg_SendUp[5]=nl_SendUp;
	_Context->msg_SendUp[6]=pt_SendUp;
	_Context->msg_SendUp[7]=xx_SendUp;
	for (i=0; i < 8; i++)_Context->msg_SendWhileDown[i]=" ";
	_Context->msg_SendWhileDown[0]=en_SendWhileDown;
	_Context->msg_SendWhileDown[1]=fr_SendWhileDown;
	_Context->msg_SendWhileDown[2]=it_SendWhileDown;
	_Context->msg_SendWhileDown[3]=es_SendWhileDown;
	_Context->msg_SendWhileDown[4]=de_SendWhileDown;
	_Context->msg_SendWhileDown[5]=nl_SendWhileDown;
	_Context->msg_SendWhileDown[6]=pt_SendWhileDown;
	_Context->msg_SendWhileDown[7]=xx_SendWhileDown;
	for (i=0; i < 8; i++)_Context->msg_SendMove[i]=" ";
	_Context->msg_SendMove[0]=en_SendMove;
	_Context->msg_SendMove[1]=fr_SendMove;
	_Context->msg_SendMove[2]=it_SendMove;
	_Context->msg_SendMove[3]=es_SendMove;
	_Context->msg_SendMove[4]=de_SendMove;
	_Context->msg_SendMove[5]=nl_SendMove;
	_Context->msg_SendMove[6]=pt_SendMove;
	_Context->msg_SendMove[7]=xx_SendMove;
	for (i=0; i < 8; i++)_Context->msg_MouseKey[i]=" ";
	_Context->msg_MouseKey[0]=en_MouseKey;
	_Context->msg_MouseKey[1]=fr_MouseKey;
	_Context->msg_MouseKey[2]=it_MouseKey;
	_Context->msg_MouseKey[3]=es_MouseKey;
	_Context->msg_MouseKey[4]=de_MouseKey;
	_Context->msg_MouseKey[5]=nl_MouseKey;
	_Context->msg_MouseKey[6]=pt_MouseKey;
	_Context->msg_MouseKey[7]=xx_MouseKey;
	for (i=0; i < 8; i++)_Context->msg_WidgetTriggers[i]=" ";
	_Context->msg_WidgetTriggers[0]=en_WidgetTriggers;
	_Context->msg_WidgetTriggers[1]=fr_WidgetTriggers;
	_Context->msg_WidgetTriggers[2]=it_WidgetTriggers;
	_Context->msg_WidgetTriggers[3]=es_WidgetTriggers;
	_Context->msg_WidgetTriggers[4]=de_WidgetTriggers;
	_Context->msg_WidgetTriggers[5]=nl_WidgetTriggers;
	_Context->msg_WidgetTriggers[6]=pt_WidgetTriggers;
	_Context->msg_WidgetTriggers[7]=xx_WidgetTriggers;
	for (i=0; i < 8; i++)_Context->msg_Escape[i]=" ";
	_Context->msg_Escape[0]=en_Escape;
	_Context->msg_Escape[1]=fr_Escape;
	_Context->msg_Escape[2]=it_Escape;
	_Context->msg_Escape[3]=es_Escape;
	_Context->msg_Escape[4]=de_Escape;
	_Context->msg_Escape[5]=nl_Escape;
	_Context->msg_Escape[6]=pt_Escape;
	_Context->msg_Escape[7]=xx_Escape;
	_Context->s_Escape=0;
	_Context->p_Escape=visual_buffer(_Context->x_Auto1904+40,_Context->y_Auto1904+270,238,16);
	for (i=0; i < 8; i++)_Context->msg_Enter[i]=" ";
	_Context->msg_Enter[0]=en_Enter;
	_Context->msg_Enter[1]=fr_Enter;
	_Context->msg_Enter[2]=it_Enter;
	_Context->msg_Enter[3]=es_Enter;
	_Context->msg_Enter[4]=de_Enter;
	_Context->msg_Enter[5]=nl_Enter;
	_Context->msg_Enter[6]=pt_Enter;
	_Context->msg_Enter[7]=xx_Enter;
	_Context->s_Enter=0;
	_Context->p_Enter=visual_buffer(_Context->x_Auto1904+280,_Context->y_Auto1904+270,210,16);
	for (i=0; i < 8; i++)_Context->msg_PageUp[i]=" ";
	_Context->msg_PageUp[0]=en_PageUp;
	_Context->msg_PageUp[1]=fr_PageUp;
	_Context->msg_PageUp[2]=it_PageUp;
	_Context->msg_PageUp[3]=es_PageUp;
	_Context->msg_PageUp[4]=de_PageUp;
	_Context->msg_PageUp[5]=nl_PageUp;
	_Context->msg_PageUp[6]=pt_PageUp;
	_Context->msg_PageUp[7]=xx_PageUp;
	_Context->s_PageUp=0;
	_Context->p_PageUp=visual_buffer(_Context->x_Auto1904+40,_Context->y_Auto1904+310,238,16);
	for (i=0; i < 8; i++)_Context->msg_PageDown[i]=" ";
	_Context->msg_PageDown[0]=en_PageDown;
	_Context->msg_PageDown[1]=fr_PageDown;
	_Context->msg_PageDown[2]=it_PageDown;
	_Context->msg_PageDown[3]=es_PageDown;
	_Context->msg_PageDown[4]=de_PageDown;
	_Context->msg_PageDown[5]=nl_PageDown;
	_Context->msg_PageDown[6]=pt_PageDown;
	_Context->msg_PageDown[7]=xx_PageDown;
	_Context->s_PageDown=0;
	_Context->p_PageDown=visual_buffer(_Context->x_Auto1904+40,_Context->y_Auto1904+350,238,16);
	for (i=0; i < 8; i++)_Context->msg_UpArrow[i]=" ";
	_Context->msg_UpArrow[0]=en_UpArrow;
	_Context->msg_UpArrow[1]=fr_UpArrow;
	_Context->msg_UpArrow[2]=it_UpArrow;
	_Context->msg_UpArrow[3]=es_UpArrow;
	_Context->msg_UpArrow[4]=de_UpArrow;
	_Context->msg_UpArrow[5]=nl_UpArrow;
	_Context->msg_UpArrow[6]=pt_UpArrow;
	_Context->msg_UpArrow[7]=xx_UpArrow;
	_Context->s_UpArrow=0;
	_Context->p_UpArrow=visual_buffer(_Context->x_Auto1904+280,_Context->y_Auto1904+310,210,16);
	for (i=0; i < 8; i++)_Context->msg_DownArrow[i]=" ";
	_Context->msg_DownArrow[0]=en_DownArrow;
	_Context->msg_DownArrow[1]=fr_DownArrow;
	_Context->msg_DownArrow[2]=it_DownArrow;
	_Context->msg_DownArrow[3]=es_DownArrow;
	_Context->msg_DownArrow[4]=de_DownArrow;
	_Context->msg_DownArrow[5]=nl_DownArrow;
	_Context->msg_DownArrow[6]=pt_DownArrow;
	_Context->msg_DownArrow[7]=xx_DownArrow;
	_Context->s_DownArrow=0;
	_Context->p_DownArrow=visual_buffer(_Context->x_Auto1904+280,_Context->y_Auto1904+350,210,16);
	for (i=0; i < 8; i++)_Context->msg_Tabulation[i]=" ";
	_Context->msg_Tabulation[0]=en_Tabulation;
	_Context->msg_Tabulation[1]=fr_Tabulation;
	_Context->msg_Tabulation[2]=it_Tabulation;
	_Context->msg_Tabulation[3]=es_Tabulation;
	_Context->msg_Tabulation[4]=de_Tabulation;
	_Context->msg_Tabulation[5]=nl_Tabulation;
	_Context->msg_Tabulation[6]=pt_Tabulation;
	_Context->msg_Tabulation[7]=xx_Tabulation;
	_Context->s_Tabulation=0;
	_Context->p_Tabulation=visual_buffer(_Context->x_Auto1904+490,_Context->y_Auto1904+270,182,16);
	for (i=0; i < 8; i++)_Context->msg_DefaultBreak[i]=" ";
	_Context->msg_DefaultBreak[0]=en_DefaultBreak;
	_Context->msg_DefaultBreak[1]=fr_DefaultBreak;
	_Context->msg_DefaultBreak[2]=it_DefaultBreak;
	_Context->msg_DefaultBreak[3]=es_DefaultBreak;
	_Context->msg_DefaultBreak[4]=de_DefaultBreak;
	_Context->msg_DefaultBreak[5]=nl_DefaultBreak;
	_Context->msg_DefaultBreak[6]=pt_DefaultBreak;
	_Context->msg_DefaultBreak[7]=xx_DefaultBreak;
	_Context->s_DefaultBreak=0;
	_Context->p_DefaultBreak=visual_buffer(_Context->x_Auto1904+490,_Context->y_Auto1904+310,182,16);
	for (i=0; i < 8; i++)_Context->msg_FormMethods[i]=" ";
	_Context->msg_FormMethods[0]=en_FormMethods;
	_Context->msg_FormMethods[1]=fr_FormMethods;
	_Context->msg_FormMethods[2]=it_FormMethods;
	_Context->msg_FormMethods[3]=es_FormMethods;
	_Context->msg_FormMethods[4]=de_FormMethods;
	_Context->msg_FormMethods[5]=nl_FormMethods;
	_Context->msg_FormMethods[6]=pt_FormMethods;
	_Context->msg_FormMethods[7]=xx_FormMethods;
	_Context->focus_pages[3]=38;
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
	if ( 1 > 0 ) { _Context->row_Methods=&_Context->buffer_Methods[1-1][0]; } ;
	_Context->max_ScrollBar=1;
	_Context->value_ScrollBar=1;
	_Context->limit_ScrollBar=1;
	_Context->value_ScrollBar=0;
	_Context->limit_ScrollBar=19;
	_Context->max_ScrollBar=(19*2);
	for (i=0; i < 8; i++)_Context->msg_FormMemberPage[i]=" ";
	_Context->msg_FormMemberPage[0]=en_FormMemberPage;
	_Context->msg_FormMemberPage[1]=fr_FormMemberPage;
	_Context->msg_FormMemberPage[2]=it_FormMemberPage;
	_Context->msg_FormMemberPage[3]=es_FormMemberPage;
	_Context->msg_FormMemberPage[4]=de_FormMemberPage;
	_Context->msg_FormMemberPage[5]=nl_FormMemberPage;
	_Context->msg_FormMemberPage[6]=pt_FormMemberPage;
	_Context->msg_FormMemberPage[7]=xx_FormMemberPage;
	_Context->focus_pages[4]=41;
	for (i=0; i < 8; i++)_Context->msg_TypeSelect[i]=" ";
	_Context->msg_TypeSelect[0]=en_TypeSelect;
	_Context->msg_TypeSelect[1]=fr_TypeSelect;
	_Context->msg_TypeSelect[2]=it_TypeSelect;
	_Context->msg_TypeSelect[3]=es_TypeSelect;
	_Context->msg_TypeSelect[4]=de_TypeSelect;
	_Context->msg_TypeSelect[5]=nl_TypeSelect;
	_Context->msg_TypeSelect[6]=pt_TypeSelect;
	_Context->msg_TypeSelect[7]=xx_TypeSelect;
	_Context->x_TypeSelect=_Context->x_Auto1904+460;
	_Context->y_TypeSelect=_Context->y_Auto1904+60;
	_Context->w_TypeSelect=72;
	_Context->h_TypeSelect=80;
	_Context->fg_TypeSelect=80;
	_Context->bg_TypeSelect=80;
	_Context->fid_TypeSelect=1;
	_Context->s_TypeSelect=0;
	_Context->p_TypeSelect=visual_buffer(_Context->x_TypeSelect,_Context->y_TypeSelect,_Context->w_TypeSelect,_Context->h_TypeSelect);
	for (i=0; i < 8; i++)_Context->msg_FormMembers[i]=" ";
	_Context->msg_FormMembers[0]=en_FormMembers;
	_Context->msg_FormMembers[1]=fr_FormMembers;
	_Context->msg_FormMembers[2]=it_FormMembers;
	_Context->msg_FormMembers[3]=es_FormMembers;
	_Context->msg_FormMembers[4]=de_FormMembers;
	_Context->msg_FormMembers[5]=nl_FormMembers;
	_Context->msg_FormMembers[6]=pt_FormMembers;
	_Context->msg_FormMembers[7]=xx_FormMembers;
	if ( 0 > 0 ) { _Context->row_FormMembers=&_Context->buffer_FormMembers[0-1][0]; } ;
	_Context->max_MemberBar=1;
	_Context->value_MemberBar=1;
	_Context->limit_MemberBar=1;
	_Context->value_MemberBar=0;
	_Context->limit_MemberBar=19;
	_Context->max_MemberBar=(19*2);
	for (i=0; i < 8; i++)_Context->msg_Auto1917[i]=" ";
	_Context->msg_Auto1917[0]=en_Auto1917;
	_Context->msg_Auto1917[1]=fr_Auto1917;
	_Context->msg_Auto1917[2]=it_Auto1917;
	_Context->msg_Auto1917[3]=es_Auto1917;
	_Context->msg_Auto1917[4]=de_Auto1917;
	_Context->msg_Auto1917[5]=nl_Auto1917;
	_Context->msg_Auto1917[6]=pt_Auto1917;
	_Context->msg_Auto1917[7]=xx_Auto1917;
	_Context->focus_pages[5]=44;
	for (i=0; i < 8; i++)_Context->msg_Auto1918[i]=" ";
	_Context->msg_Auto1918[0]=en_Auto1918;
	for (i=0; i < 8; i++)_Context->msg_auto7[i]=" ";
	_Context->msg_auto7[0]=en_auto7;
	_Context->msg_auto7[1]=fr_auto7;
	for (i=0; i < 8; i++)_Context->msg_auto52[i]=" ";
	_Context->msg_auto52[0]=en_auto52;
	_Context->msg_auto52[1]=fr_auto52;
	_Context->msg_auto52[2]=it_auto52;
	_Context->msg_auto52[3]=es_auto52;
	_Context->msg_auto52[4]=de_auto52;
	_Context->msg_auto52[5]=nl_auto52;
	_Context->msg_auto52[6]=pt_auto52;
	_Context->msg_auto52[7]=xx_auto52;
	for (i=0; i < 8; i++)_Context->msg_Auto1921[i]=" ";
	_Context->msg_Auto1921[0]=en_Auto1921;
	_Context->msg_Auto1921[1]=fr_Auto1921;
	_Context->msg_Auto1921[2]=it_Auto1921;
	_Context->msg_Auto1921[3]=es_Auto1921;
	_Context->msg_Auto1921[4]=de_Auto1921;
	_Context->msg_Auto1921[5]=nl_Auto1921;
	_Context->msg_Auto1921[6]=pt_Auto1921;
	_Context->msg_Auto1921[7]=xx_Auto1921;
	for (i=0; i < 8; i++)_Context->msg_Auto1922[i]=" ";
	_Context->msg_Auto1922[0]=en_Auto1922;
	_Context->msg_Auto1922[1]=fr_Auto1922;
	_Context->msg_Auto1922[2]=it_Auto1922;
	_Context->msg_Auto1922[3]=es_Auto1922;
	_Context->msg_Auto1922[4]=de_Auto1922;
	_Context->msg_Auto1922[5]=nl_Auto1922;
	_Context->msg_Auto1922[6]=pt_Auto1922;
	_Context->msg_Auto1922[7]=xx_Auto1922;
	for (i=0; i < 8; i++)_Context->msg_Auto1923[i]=" ";
	_Context->msg_Auto1923[0]=en_Auto1923;
	for (i=0; i < 8; i++)_Context->msg_Auto1924[i]=" ";
	_Context->msg_Auto1924[0]=en_Auto1924;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto1904,_Context->y_Auto1904,720+10,470+10);
	return(0);
}

public 	int	accept_form_control_hide(struct accept_form_control_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_TypeSelect != (void *) 0)
	&& (_Context->s_TypeSelect != 0)) {
		(void)visual_buffer_put(_Context->p_TypeSelect,_Context->x_TypeSelect,_Context->y_TypeSelect);
		_Context->s_TypeSelect=0;
		}
	if ((_Context->p_DefaultBreak != (void *) 0)
	&& (_Context->s_DefaultBreak != 0)) {
		(void)visual_buffer_put(_Context->p_DefaultBreak,_Context->x_Auto1904+490,_Context->y_Auto1904+310);
		_Context->s_DefaultBreak=0;
		}
	if ((_Context->p_Tabulation != (void *) 0)
	&& (_Context->s_Tabulation != 0)) {
		(void)visual_buffer_put(_Context->p_Tabulation,_Context->x_Auto1904+490,_Context->y_Auto1904+270);
		_Context->s_Tabulation=0;
		}
	if ((_Context->p_DownArrow != (void *) 0)
	&& (_Context->s_DownArrow != 0)) {
		(void)visual_buffer_put(_Context->p_DownArrow,_Context->x_Auto1904+280,_Context->y_Auto1904+350);
		_Context->s_DownArrow=0;
		}
	if ((_Context->p_UpArrow != (void *) 0)
	&& (_Context->s_UpArrow != 0)) {
		(void)visual_buffer_put(_Context->p_UpArrow,_Context->x_Auto1904+280,_Context->y_Auto1904+310);
		_Context->s_UpArrow=0;
		}
	if ((_Context->p_PageDown != (void *) 0)
	&& (_Context->s_PageDown != 0)) {
		(void)visual_buffer_put(_Context->p_PageDown,_Context->x_Auto1904+40,_Context->y_Auto1904+350);
		_Context->s_PageDown=0;
		}
	if ((_Context->p_PageUp != (void *) 0)
	&& (_Context->s_PageUp != 0)) {
		(void)visual_buffer_put(_Context->p_PageUp,_Context->x_Auto1904+40,_Context->y_Auto1904+310);
		_Context->s_PageUp=0;
		}
	if ((_Context->p_Enter != (void *) 0)
	&& (_Context->s_Enter != 0)) {
		(void)visual_buffer_put(_Context->p_Enter,_Context->x_Auto1904+280,_Context->y_Auto1904+270);
		_Context->s_Enter=0;
		}
	if ((_Context->p_Escape != (void *) 0)
	&& (_Context->s_Escape != 0)) {
		(void)visual_buffer_put(_Context->p_Escape,_Context->x_Auto1904+40,_Context->y_Auto1904+270);
		_Context->s_Escape=0;
		}
	if ((_Context->p_Overlay != (void *) 0)
	&& (_Context->s_Overlay != 0)) {
		(void)visual_buffer_put(_Context->p_Overlay,_Context->x_Auto1904+400,_Context->y_Auto1904+230);
		_Context->s_Overlay=0;
		}
	if ((_Context->p_Program != (void *) 0)
	&& (_Context->s_Program != 0)) {
		(void)visual_buffer_put(_Context->p_Program,_Context->x_Auto1904+50,_Context->y_Auto1904+230);
		_Context->s_Program=0;
		}
	if ((_Context->p_ProductionLanguage != (void *) 0)
	&& (_Context->s_ProductionLanguage != 0)) {
		(void)visual_buffer_put(_Context->p_ProductionLanguage,_Context->x_Auto1904+280,_Context->y_Auto1904+130);
		_Context->s_ProductionLanguage=0;
		}
	if ((_Context->p_FormType != (void *) 0)
	&& (_Context->s_FormType != 0)) {
		(void)visual_buffer_put(_Context->p_FormType,_Context->x_Auto1904+50,_Context->y_Auto1904+130);
		_Context->s_FormType=0;
		}
	if ((_Context->p_Cancel != (void *) 0)
	&& (_Context->s_Cancel != 0)) {
		(void)visual_buffer_put(_Context->p_Cancel,_Context->x_Auto1904+550,_Context->y_Auto1904+420);
		_Context->s_Cancel=0;
		}
	if ((_Context->p_Accept != (void *) 0)
	&& (_Context->s_Accept != 0)) {
		(void)visual_buffer_put(_Context->p_Accept,_Context->x_Auto1904+20,_Context->y_Auto1904+420);
		_Context->s_Accept=0;
		}
	if ((_Context->p_FormControl != (void *) 0)
	&& (_Context->s_FormControl != 0)) {
		(void)visual_buffer_put(_Context->p_FormControl,_Context->x_Auto1904+10,_Context->y_Auto1904+30);
		_Context->s_FormControl=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto1904,_Context->y_Auto1904);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_form_control_remove(
	struct accept_form_control_context * _Context,
	char * pFormType,
	char * pProductionLanguage,
	char * pNationalLanguage,
	char * pInternational,
	char * pConstants,
	char * pMultipleLanguage,
	char * pProgram,
	char * pOverlay,
	char * pPopUp,
	char * pDynamic,
	char * pCommandLine,
	char * pArgVLen,
	char * pArgVNb,
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
	char * pDefaultBreak,
	char * pFileName,
	char * pIdentity,
	char * pStyleSheet,
	char * pClearScreen)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->p_TypeSelect != (void *) 0)
		_Context->p_TypeSelect = visual_drop(_Context->p_TypeSelect);
	if (_Context->p_DefaultBreak != (void *) 0)
		_Context->p_DefaultBreak = visual_drop(_Context->p_DefaultBreak);
	if (_Context->p_Tabulation != (void *) 0)
		_Context->p_Tabulation = visual_drop(_Context->p_Tabulation);
	if (_Context->p_DownArrow != (void *) 0)
		_Context->p_DownArrow = visual_drop(_Context->p_DownArrow);
	if (_Context->p_UpArrow != (void *) 0)
		_Context->p_UpArrow = visual_drop(_Context->p_UpArrow);
	if (_Context->p_PageDown != (void *) 0)
		_Context->p_PageDown = visual_drop(_Context->p_PageDown);
	if (_Context->p_PageUp != (void *) 0)
		_Context->p_PageUp = visual_drop(_Context->p_PageUp);
	if (_Context->p_Enter != (void *) 0)
		_Context->p_Enter = visual_drop(_Context->p_Enter);
	if (_Context->p_Escape != (void *) 0)
		_Context->p_Escape = visual_drop(_Context->p_Escape);
	if (_Context->p_Overlay != (void *) 0)
		_Context->p_Overlay = visual_drop(_Context->p_Overlay);
	if (_Context->p_Program != (void *) 0)
		_Context->p_Program = visual_drop(_Context->p_Program);
	if (_Context->p_ProductionLanguage != (void *) 0)
		_Context->p_ProductionLanguage = visual_drop(_Context->p_ProductionLanguage);
	if (_Context->p_FormType != (void *) 0)
		_Context->p_FormType = visual_drop(_Context->p_FormType);
	if (_Context->p_Cancel != (void *) 0)
		_Context->p_Cancel = visual_drop(_Context->p_Cancel);
	if (_Context->p_Accept != (void *) 0)
		_Context->p_Accept = visual_drop(_Context->p_Accept);
	if (_Context->p_FormControl != (void *) 0)
		_Context->p_FormControl = visual_drop(_Context->p_FormControl);
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWSSSS");
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
		visual_transferout((void *) 0, 0, pConstants);
		if ( pConstants != (char *) 0)
			*((int*)pConstants) = _Context->value_Constants;
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
		visual_transferout((void *) 0, 0, pDynamic);
		if ( pDynamic != (char *) 0)
			*((int*)pDynamic) = _Context->value_Dynamic;
		visual_transferout((void *) 0, 0, pCommandLine);
		if ( pCommandLine != (char *) 0)
			*((int*)pCommandLine) = _Context->value_CommandLine;
		visual_transferout(_Context->buffer_ArgVLen, 12, pArgVLen);
		visual_transferout(_Context->buffer_ArgVNb, 13, pArgVNb);
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
		visual_transferout(_Context->buffer_FileName, 75, pFileName);
		visual_transferout(_Context->buffer_Identity, 78, pIdentity);
		visual_transferout(_Context->buffer_StyleSheet, 75, pStyleSheet);
		visual_transferout(_Context->buffer_ClearScreen, 78, pClearScreen);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Methods_show(struct accept_form_control_context * _Context) {
	int l;
	for(l=1;l<=19;l++){
	if ( l > 0 ) { _Context->row_Methods=&_Context->buffer_Methods[l-1][0]; } ;
	get_forms_method_information(
	(l+_Context->value_ScrollBar),
	(_Context->row_Methods+0),17,
	(_Context->row_Methods+17),33,
	(_Context->row_Methods+50),32,
	(char*)0,0);
	}
		visual_table(_Context->x_Auto1904+20,_Context->y_Auto1904+70,660+2,330+2,vfh[1],0,0,_Context->msg_Methods[_Context->language],_Context->buffer_Methods,0x4401,"(W16,W32,$)");
;
	return(-1);
}
private int on_FormMembers_show(struct accept_form_control_context * _Context) {
	struct forms_data_member*get_forms_member(int);
	struct forms_data_member*dptr;
	int l;
	int i;
	memset(_Context->buffer_FormMembers,' ',1558);
	for(l=1;l<=19;l++){
	if(!(dptr=get_forms_member(l+_Context->value_MemberBar)))
	continue;
	if ( l > 0 ) { _Context->row_FormMembers=&_Context->buffer_FormMembers[l-1][0]; } ;
	putstring(_Context, (_Context->row_FormMembers+0),55,dptr->name);
	switch(dptr->type){
	case _ABAL_BYTE:
	putstring(_Context, (_Context->row_FormMembers+55),9,"byte");
	sprintf((_Context->row_FormMembers+64),"%u",1);
	break;
	case _ABAL_WORD:
	putstring(_Context, (_Context->row_FormMembers+55),9,"word");
	sprintf((_Context->row_FormMembers+64),"%u",2);
	break;
	case _ABAL_LONG:
	putstring(_Context, (_Context->row_FormMembers+55),9,"long");
	sprintf((_Context->row_FormMembers+64),"%u",4);
	break;
	case _ABAL_BCD:
	putstring(_Context, (_Context->row_FormMembers+55),9,"bcd");
	sprintf((_Context->row_FormMembers+64),"%u",dptr->size);
	break;
	case _ABAL_STRING:
	putstring(_Context, (_Context->row_FormMembers+55),9,"string");
	sprintf((_Context->row_FormMembers+64),"%u",dptr->size);
	break;
	}
	sprintf((_Context->row_FormMembers+70),"%u",dptr->first);
	sprintf((_Context->row_FormMembers+76),"%u",dptr->second);
	}
		visual_table(_Context->x_Auto1904+20,_Context->y_Auto1904+70,660+2,330+2,vfh[1],0,0,_Context->msg_FormMembers[_Context->language],_Context->buffer_FormMembers,0x4401,"($,W8,N4Z,N4Z,N4Z)");
;
	return(-1);
}

public	int	accept_form_control_show(struct accept_form_control_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto1904,_Context->y_Auto1904);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto1904,_Context->y_Auto1904,720,470,vfh[2],_Context->msg_Auto1904[_Context->language],strlen(_Context->msg_Auto1904[_Context->language]),0x407);
	visual_image(_Context->x_Auto1904+3,_Context->y_Auto1904+22,714,444,_Context->msg_Auto1905[_Context->language],4);
	if (_Context->page_number == 1 ) {
	if ((_Context->p_FormControl != (void *) 0)
	&& (_Context->s_FormControl == 0)) {
		(void)visual_buffer_get(_Context->p_FormControl,_Context->x_Auto1904+10,_Context->y_Auto1904+30);
		_Context->s_FormControl=1;
		}
	_Context->trigger_FormControl=visual_trigger_code(_Context->msg_FormControl[_Context->language],strlen(_Context->msg_FormControl[_Context->language]));
	visual_tabpage(_Context->x_Auto1904+10,_Context->y_Auto1904+30,700,380,vfh[2],_Context->msg_FormControl[_Context->language],strlen(_Context->msg_FormControl[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto1904+10,_Context->y_Auto1904+30,700,380,vfh[2],_Context->msg_FormControl[_Context->language],strlen(_Context->msg_FormControl[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto1904+20,_Context->y_Auto1904+70,680,16,vfh[2],16,0,_Context->msg_Auto1906[_Context->language],strlen(_Context->msg_Auto1906[_Context->language]),258);
	visual_frame(_Context->x_Auto1904+20,_Context->y_Auto1904+86,680,94,4);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto1904+20,_Context->y_Auto1904+190,680,16,vfh[2],16,0,_Context->msg_Auto1907[_Context->language],strlen(_Context->msg_Auto1907[_Context->language]),258);
	visual_frame(_Context->x_Auto1904+20,_Context->y_Auto1904+206,680,194,4);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto1904+340,_Context->y_Auto1904+360,70,16,vfh[2],16,0,_Context->msg_Auto1908[_Context->language],strlen(_Context->msg_Auto1908[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto1904+500,_Context->y_Auto1904+360,14,16,vfh[2],16,0,_Context->msg_Auto1909[_Context->language],strlen(_Context->msg_Auto1909[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto1904+620,_Context->y_Auto1904+360,14,16,vfh[2],16,0,_Context->msg_Auto1910[_Context->language],strlen(_Context->msg_Auto1910[_Context->language]),2);
		}
	if ((_Context->p_Accept != (void *) 0)
	&& (_Context->s_Accept == 0)) {
		(void)visual_buffer_get(_Context->p_Accept,_Context->x_Auto1904+20,_Context->y_Auto1904+420);
		_Context->s_Accept=1;
		}
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto1904+20,_Context->y_Auto1904+420,154,32,vfh[2],175,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_EditMethod=visual_trigger_code(_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]));
	visual_button(_Context->x_Auto1904+200,_Context->y_Auto1904+420,154,32,vfh[2],28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),0);
	_Context->trigger_DropMethod=visual_trigger_code(_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]));
	visual_button(_Context->x_Auto1904+370,_Context->y_Auto1904+420,154,32,vfh[2],28,28,_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]),0);
	if ((_Context->p_Cancel != (void *) 0)
	&& (_Context->s_Cancel == 0)) {
		(void)visual_buffer_get(_Context->p_Cancel,_Context->x_Auto1904+550,_Context->y_Auto1904+420);
		_Context->s_Cancel=1;
		}
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto1904+550,_Context->y_Auto1904+420,154,32,vfh[2],175,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto1904+50,_Context->y_Auto1904+110,168,16,vfh[2],16,0,_Context->msg_Auto1911[_Context->language],strlen(_Context->msg_Auto1911[_Context->language]),259);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto1904+280,_Context->y_Auto1904+110,168,16,vfh[2],16,0,_Context->msg_Auto1912[_Context->language],strlen(_Context->msg_Auto1912[_Context->language]),259);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto1904+490,_Context->y_Auto1904+110,168,16,vfh[2],16,0,_Context->msg_Auto1913[_Context->language],strlen(_Context->msg_Auto1913[_Context->language]),259);
		}
	if (_Context->page_number == 1 ) {
	if ((_Context->p_FormType != (void *) 0)
	&& (_Context->s_FormType == 0)) {
		(void)visual_buffer_get(_Context->p_FormType,_Context->x_Auto1904+50,_Context->y_Auto1904+130);
		_Context->s_FormType=1;
		}
	visual_select(_Context->x_Auto1904+50,_Context->y_Auto1904+130,168,144,vfh[1],27,0,parse_selection(FormTypeList,&_Context->value_FormType),0);
		}
	if (_Context->page_number == 1 ) {
	if ((_Context->p_ProductionLanguage != (void *) 0)
	&& (_Context->s_ProductionLanguage == 0)) {
		(void)visual_buffer_get(_Context->p_ProductionLanguage,_Context->x_Auto1904+280,_Context->y_Auto1904+130);
		_Context->s_ProductionLanguage=1;
		}
	visual_select(_Context->x_Auto1904+280,_Context->y_Auto1904+130,168,144,vfh[1],27,0,parse_selection(ProductionLanguageList,&_Context->value_ProductionLanguage),0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_Auto1904+500,_Context->y_Auto1904+130,168,144,vfh[1],27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),768);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_International=visual_trigger_code(_Context->msg_International[_Context->language],strlen(_Context->msg_International[_Context->language]));
	visual_check(_Context->x_Auto1904+50,_Context->y_Auto1904+260,322,16,vfh[2],28,28,_Context->msg_International[_Context->language],strlen(_Context->msg_International[_Context->language]),_Context->value_International|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Constants=visual_trigger_code(_Context->msg_Constants[_Context->language],strlen(_Context->msg_Constants[_Context->language]));
	visual_check(_Context->x_Auto1904+50,_Context->y_Auto1904+330,294,16,vfh[2],28,28,_Context->msg_Constants[_Context->language],strlen(_Context->msg_Constants[_Context->language]),_Context->value_Constants|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_MultipleLanguage=visual_trigger_code(_Context->msg_MultipleLanguage[_Context->language],strlen(_Context->msg_MultipleLanguage[_Context->language]));
	visual_check(_Context->x_Auto1904+400,_Context->y_Auto1904+260,280,16,vfh[2],28,28,_Context->msg_MultipleLanguage[_Context->language],strlen(_Context->msg_MultipleLanguage[_Context->language]),_Context->value_MultipleLanguage|0);
		}
	if (_Context->page_number == 1 ) {
	if ((_Context->p_Program != (void *) 0)
	&& (_Context->s_Program == 0)) {
		(void)visual_buffer_get(_Context->p_Program,_Context->x_Auto1904+50,_Context->y_Auto1904+230);
		_Context->s_Program=1;
		}
	_Context->trigger_Program=visual_trigger_code(_Context->msg_Program[_Context->language],strlen(_Context->msg_Program[_Context->language]));
	visual_check(_Context->x_Auto1904+50,_Context->y_Auto1904+230,322,16,vfh[2],27,0,_Context->msg_Program[_Context->language],strlen(_Context->msg_Program[_Context->language]),_Context->value_Program|0);
		}
	if (_Context->page_number == 1 ) {
	if ((_Context->p_Overlay != (void *) 0)
	&& (_Context->s_Overlay == 0)) {
		(void)visual_buffer_get(_Context->p_Overlay,_Context->x_Auto1904+400,_Context->y_Auto1904+230);
		_Context->s_Overlay=1;
		}
	_Context->trigger_Overlay=visual_trigger_code(_Context->msg_Overlay[_Context->language],strlen(_Context->msg_Overlay[_Context->language]));
	visual_check(_Context->x_Auto1904+400,_Context->y_Auto1904+230,280,16,vfh[2],27,0,_Context->msg_Overlay[_Context->language],strlen(_Context->msg_Overlay[_Context->language]),_Context->value_Overlay|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_PopUp=visual_trigger_code(_Context->msg_PopUp[_Context->language],strlen(_Context->msg_PopUp[_Context->language]));
	visual_check(_Context->x_Auto1904+400,_Context->y_Auto1904+300,294,16,vfh[2],27,0,_Context->msg_PopUp[_Context->language],strlen(_Context->msg_PopUp[_Context->language]),_Context->value_PopUp|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Dynamic=visual_trigger_code(_Context->msg_Dynamic[_Context->language],strlen(_Context->msg_Dynamic[_Context->language]));
	visual_check(_Context->x_Auto1904+400,_Context->y_Auto1904+330,294,16,vfh[2],27,0,_Context->msg_Dynamic[_Context->language],strlen(_Context->msg_Dynamic[_Context->language]),_Context->value_Dynamic|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_CommandLine=visual_trigger_code(_Context->msg_CommandLine[_Context->language],strlen(_Context->msg_CommandLine[_Context->language]));
	visual_check(_Context->x_Auto1904+50,_Context->y_Auto1904+300,280,16,vfh[2],28,28,_Context->msg_CommandLine[_Context->language],strlen(_Context->msg_CommandLine[_Context->language]),_Context->value_CommandLine|0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto1904+400,_Context->y_Auto1904+360,96+2,16+2,5);
	visual_text(_Context->x_Auto1904+400+1,_Context->y_Auto1904+360+1,96,16,vfh[1],0,0,_Context->buffer_ArgVLen,12,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto1904+520,_Context->y_Auto1904+360,104+2,16+2,5);
	visual_text(_Context->x_Auto1904+520+1,_Context->y_Auto1904+360+1,104,16,vfh[1],0,0,_Context->buffer_ArgVNb,13,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_MouseEvents=visual_trigger_code(_Context->msg_MouseEvents[_Context->language],strlen(_Context->msg_MouseEvents[_Context->language]));
	visual_tabpage(_Context->x_Auto1904+10,_Context->y_Auto1904+30,700,380,vfh[2],_Context->msg_MouseEvents[_Context->language],strlen(_Context->msg_MouseEvents[_Context->language]),134,2);
	} else {
		visual_tabpage(_Context->x_Auto1904+10,_Context->y_Auto1904+30,700,380,vfh[2],_Context->msg_MouseEvents[_Context->language],strlen(_Context->msg_MouseEvents[_Context->language]),134,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto1904+20,_Context->y_Auto1904+70,680,16,vfh[2],16,0,_Context->msg_Auto1914[_Context->language],strlen(_Context->msg_Auto1914[_Context->language]),258);
	visual_frame(_Context->x_Auto1904+20,_Context->y_Auto1904+86,680,44,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto1904+20,_Context->y_Auto1904+140,680,16,vfh[2],16,0,_Context->msg_Auto1915[_Context->language],strlen(_Context->msg_Auto1915[_Context->language]),258);
	visual_frame(_Context->x_Auto1904+20,_Context->y_Auto1904+156,680,74,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto1904+20,_Context->y_Auto1904+240,680,16,vfh[2],16,0,_Context->msg_Auto1916[_Context->language],strlen(_Context->msg_Auto1916[_Context->language]),258);
	visual_frame(_Context->x_Auto1904+20,_Context->y_Auto1904+256,680,134,4);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendLeft=visual_trigger_code(_Context->msg_SendLeft[_Context->language],strlen(_Context->msg_SendLeft[_Context->language]));
	visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+100,238,16,vfh[2],27,0,_Context->msg_SendLeft[_Context->language],strlen(_Context->msg_SendLeft[_Context->language]),_Context->value_SendLeft|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendMiddle=visual_trigger_code(_Context->msg_SendMiddle[_Context->language],strlen(_Context->msg_SendMiddle[_Context->language]));
	visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+100,196,16,vfh[2],27,0,_Context->msg_SendMiddle[_Context->language],strlen(_Context->msg_SendMiddle[_Context->language]),_Context->value_SendMiddle|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendRight=visual_trigger_code(_Context->msg_SendRight[_Context->language],strlen(_Context->msg_SendRight[_Context->language]));
	visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+100,196,16,vfh[2],27,0,_Context->msg_SendRight[_Context->language],strlen(_Context->msg_SendRight[_Context->language]),_Context->value_SendRight|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendDown=visual_trigger_code(_Context->msg_SendDown[_Context->language],strlen(_Context->msg_SendDown[_Context->language]));
	visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+170,224,16,vfh[2],27,0,_Context->msg_SendDown[_Context->language],strlen(_Context->msg_SendDown[_Context->language]),_Context->value_SendDown|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendUp=visual_trigger_code(_Context->msg_SendUp[_Context->language],strlen(_Context->msg_SendUp[_Context->language]));
	visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+170,196,16,vfh[2],27,0,_Context->msg_SendUp[_Context->language],strlen(_Context->msg_SendUp[_Context->language]),_Context->value_SendUp|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendWhileDown=visual_trigger_code(_Context->msg_SendWhileDown[_Context->language],strlen(_Context->msg_SendWhileDown[_Context->language]));
	visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+200,238,16,vfh[2],27,0,_Context->msg_SendWhileDown[_Context->language],strlen(_Context->msg_SendWhileDown[_Context->language]),_Context->value_SendWhileDown|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendMove=visual_trigger_code(_Context->msg_SendMove[_Context->language],strlen(_Context->msg_SendMove[_Context->language]));
	visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+200,196,16,vfh[2],16,0,_Context->msg_SendMove[_Context->language],strlen(_Context->msg_SendMove[_Context->language]),_Context->value_SendMove|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_MouseKey=visual_trigger_code(_Context->msg_MouseKey[_Context->language],strlen(_Context->msg_MouseKey[_Context->language]));
	visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+170,196,16,vfh[2],16,0,_Context->msg_MouseKey[_Context->language],strlen(_Context->msg_MouseKey[_Context->language]),_Context->value_MouseKey|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_WidgetTriggers=visual_trigger_code(_Context->msg_WidgetTriggers[_Context->language],strlen(_Context->msg_WidgetTriggers[_Context->language]));
	visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+200,210,16,vfh[2],16,0,_Context->msg_WidgetTriggers[_Context->language],strlen(_Context->msg_WidgetTriggers[_Context->language]),_Context->value_WidgetTriggers|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_Escape != (void *) 0)
	&& (_Context->s_Escape == 0)) {
		(void)visual_buffer_get(_Context->p_Escape,_Context->x_Auto1904+40,_Context->y_Auto1904+270);
		_Context->s_Escape=1;
		}
	_Context->trigger_Escape=visual_trigger_code(_Context->msg_Escape[_Context->language],strlen(_Context->msg_Escape[_Context->language]));
	visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+270,238,16,vfh[2],27,0,_Context->msg_Escape[_Context->language],strlen(_Context->msg_Escape[_Context->language]),_Context->value_Escape|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_Enter != (void *) 0)
	&& (_Context->s_Enter == 0)) {
		(void)visual_buffer_get(_Context->p_Enter,_Context->x_Auto1904+280,_Context->y_Auto1904+270);
		_Context->s_Enter=1;
		}
	_Context->trigger_Enter=visual_trigger_code(_Context->msg_Enter[_Context->language],strlen(_Context->msg_Enter[_Context->language]));
	visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+270,210,16,vfh[2],27,0,_Context->msg_Enter[_Context->language],strlen(_Context->msg_Enter[_Context->language]),_Context->value_Enter|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_PageUp != (void *) 0)
	&& (_Context->s_PageUp == 0)) {
		(void)visual_buffer_get(_Context->p_PageUp,_Context->x_Auto1904+40,_Context->y_Auto1904+310);
		_Context->s_PageUp=1;
		}
	_Context->trigger_PageUp=visual_trigger_code(_Context->msg_PageUp[_Context->language],strlen(_Context->msg_PageUp[_Context->language]));
	visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+310,238,16,vfh[2],27,0,_Context->msg_PageUp[_Context->language],strlen(_Context->msg_PageUp[_Context->language]),_Context->value_PageUp|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_PageDown != (void *) 0)
	&& (_Context->s_PageDown == 0)) {
		(void)visual_buffer_get(_Context->p_PageDown,_Context->x_Auto1904+40,_Context->y_Auto1904+350);
		_Context->s_PageDown=1;
		}
	_Context->trigger_PageDown=visual_trigger_code(_Context->msg_PageDown[_Context->language],strlen(_Context->msg_PageDown[_Context->language]));
	visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+350,238,16,vfh[2],27,0,_Context->msg_PageDown[_Context->language],strlen(_Context->msg_PageDown[_Context->language]),_Context->value_PageDown|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_UpArrow != (void *) 0)
	&& (_Context->s_UpArrow == 0)) {
		(void)visual_buffer_get(_Context->p_UpArrow,_Context->x_Auto1904+280,_Context->y_Auto1904+310);
		_Context->s_UpArrow=1;
		}
	_Context->trigger_UpArrow=visual_trigger_code(_Context->msg_UpArrow[_Context->language],strlen(_Context->msg_UpArrow[_Context->language]));
	visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+310,210,16,vfh[2],27,0,_Context->msg_UpArrow[_Context->language],strlen(_Context->msg_UpArrow[_Context->language]),_Context->value_UpArrow|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_DownArrow != (void *) 0)
	&& (_Context->s_DownArrow == 0)) {
		(void)visual_buffer_get(_Context->p_DownArrow,_Context->x_Auto1904+280,_Context->y_Auto1904+350);
		_Context->s_DownArrow=1;
		}
	_Context->trigger_DownArrow=visual_trigger_code(_Context->msg_DownArrow[_Context->language],strlen(_Context->msg_DownArrow[_Context->language]));
	visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+350,210,16,vfh[2],27,0,_Context->msg_DownArrow[_Context->language],strlen(_Context->msg_DownArrow[_Context->language]),_Context->value_DownArrow|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_Tabulation != (void *) 0)
	&& (_Context->s_Tabulation == 0)) {
		(void)visual_buffer_get(_Context->p_Tabulation,_Context->x_Auto1904+490,_Context->y_Auto1904+270);
		_Context->s_Tabulation=1;
		}
	_Context->trigger_Tabulation=visual_trigger_code(_Context->msg_Tabulation[_Context->language],strlen(_Context->msg_Tabulation[_Context->language]));
	visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+270,182,16,vfh[2],27,0,_Context->msg_Tabulation[_Context->language],strlen(_Context->msg_Tabulation[_Context->language]),_Context->value_Tabulation|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_DefaultBreak != (void *) 0)
	&& (_Context->s_DefaultBreak == 0)) {
		(void)visual_buffer_get(_Context->p_DefaultBreak,_Context->x_Auto1904+490,_Context->y_Auto1904+310);
		_Context->s_DefaultBreak=1;
		}
	_Context->trigger_DefaultBreak=visual_trigger_code(_Context->msg_DefaultBreak[_Context->language],strlen(_Context->msg_DefaultBreak[_Context->language]));
	visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+310,182,16,vfh[2],27,0,_Context->msg_DefaultBreak[_Context->language],strlen(_Context->msg_DefaultBreak[_Context->language]),_Context->value_DefaultBreak|0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_FormMethods=visual_trigger_code(_Context->msg_FormMethods[_Context->language],strlen(_Context->msg_FormMethods[_Context->language]));
	visual_tabpage(_Context->x_Auto1904+10,_Context->y_Auto1904+30,700,380,vfh[2],_Context->msg_FormMethods[_Context->language],strlen(_Context->msg_FormMethods[_Context->language]),261,2);
	} else {
		visual_tabpage(_Context->x_Auto1904+10,_Context->y_Auto1904+30,700,380,vfh[2],_Context->msg_FormMethods[_Context->language],strlen(_Context->msg_FormMethods[_Context->language]),261,0);
		}
	if (_Context->page_number == 3 ) {
	(void) on_Methods_show(_Context);
		}
	if (_Context->page_number == 3 ) {
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,3);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_FormMemberPage=visual_trigger_code(_Context->msg_FormMemberPage[_Context->language],strlen(_Context->msg_FormMemberPage[_Context->language]));
	visual_tabpage(_Context->x_Auto1904+10,_Context->y_Auto1904+30,700,380,vfh[2],_Context->msg_FormMemberPage[_Context->language],strlen(_Context->msg_FormMemberPage[_Context->language]),397,2);
	} else {
		visual_tabpage(_Context->x_Auto1904+10,_Context->y_Auto1904+30,700,380,vfh[2],_Context->msg_FormMemberPage[_Context->language],strlen(_Context->msg_FormMemberPage[_Context->language]),397,0);
		}
	if (_Context->page_number == 4 ) {
	(void) on_FormMembers_show(_Context);
		}
	if (_Context->page_number == 4 ) {
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,3);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_Auto1917=visual_trigger_code(_Context->msg_Auto1917[_Context->language],strlen(_Context->msg_Auto1917[_Context->language]));
	visual_tabpage(_Context->x_Auto1904+10,_Context->y_Auto1904+30,700,380,vfh[2],_Context->msg_Auto1917[_Context->language],strlen(_Context->msg_Auto1917[_Context->language]),537,2);
	} else {
		visual_tabpage(_Context->x_Auto1904+10,_Context->y_Auto1904+30,700,380,vfh[2],_Context->msg_Auto1917[_Context->language],strlen(_Context->msg_Auto1917[_Context->language]),537,0);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto1904+30,_Context->y_Auto1904+70,650,16,vfh[2],16,0,_Context->msg_Auto1918[_Context->language],strlen(_Context->msg_Auto1918[_Context->language]),258);
	visual_frame(_Context->x_Auto1904+30,_Context->y_Auto1904+86,650,304,4);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto1904+643,_Context->y_Auto1904+230,19,19,2);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto1904+643,_Context->y_Auto1904+130,19,19,2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto1904+40,_Context->y_Auto1904+110,540,20,vfh[2],16,0,_Context->msg_auto7[_Context->language],strlen(_Context->msg_auto7[_Context->language]),258);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto1904+40,_Context->y_Auto1904+160,616,16,vfh[2],16,0,_Context->msg_auto52[_Context->language],strlen(_Context->msg_auto52[_Context->language]),258);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto1904+40,_Context->y_Auto1904+210,616,16,vfh[2],16,0,_Context->msg_Auto1921[_Context->language],strlen(_Context->msg_Auto1921[_Context->language]),258);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto1904+40,_Context->y_Auto1904+260,616,16,vfh[2],16,0,_Context->msg_Auto1922[_Context->language],strlen(_Context->msg_Auto1922[_Context->language]),258);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto1904+40,_Context->y_Auto1904+130,600+2,16+2,5);
	visual_text(_Context->x_Auto1904+40+1,_Context->y_Auto1904+130+1,600,16,vfh[1],34,0,_Context->buffer_FileName,75,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_Auto1923=visual_trigger_code(_Context->msg_Auto1923[_Context->language],strlen(_Context->msg_Auto1923[_Context->language]));
	visual_button(_Context->x_Auto1904+644,_Context->y_Auto1904+131,16,16,vfh[8],27,28,_Context->msg_Auto1923[_Context->language],strlen(_Context->msg_Auto1923[_Context->language]),16);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_Auto1924=visual_trigger_code(_Context->msg_Auto1924[_Context->language],strlen(_Context->msg_Auto1924[_Context->language]));
	visual_button(_Context->x_Auto1904+644,_Context->y_Auto1904+231,16,16,vfh[8],27,28,_Context->msg_Auto1924[_Context->language],strlen(_Context->msg_Auto1924[_Context->language]),16);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto1904+40,_Context->y_Auto1904+180,624+2,16+2,5);
	visual_text(_Context->x_Auto1904+40+1,_Context->y_Auto1904+180+1,624,16,vfh[1],34,0,_Context->buffer_Identity,78,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto1904+40,_Context->y_Auto1904+230,600+2,16+2,5);
	visual_text(_Context->x_Auto1904+40+1,_Context->y_Auto1904+230+1,600,16,vfh[1],0,0,_Context->buffer_StyleSheet,75,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto1904+40,_Context->y_Auto1904+280,630+2,20+2,5);
	visual_text(_Context->x_Auto1904+40+1,_Context->y_Auto1904+280+1,630,20,vfh[1],0,0,_Context->buffer_ClearScreen,78,0);
		}
	visual_thaw(_Context->x_Auto1904,_Context->y_Auto1904,720,470);
	visual_thaw(_Context->x_Auto1904,_Context->y_Auto1904,720,470);

	return(0);
}

private int Auto1904action(struct accept_form_control_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_form_control_hide(_Context);

		_Context->x_Auto1904 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto1904 < 0) { _Context->x_Auto1904=0; }
		_Context->y_Auto1904 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto1904 < 0) { _Context->y_Auto1904=0; }
			accept_form_control_show(_Context);

		visual_thaw(_Context->x_Auto1904,_Context->y_Auto1904,720,470);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_form_control_context * _Context) {
	return(13);
	return(-1);
}
private int on_EditMethod_event(struct accept_form_control_context * _Context) {
	int i;
	if(_Context->page_number==3){
	if(!(i=_Context->value_Methods))
	i=1;
		accept_form_control_hide(_Context);

	edit_forms_method(i);
		accept_form_control_show(_Context);

	}
	return(-1);
}
private int on_DropMethod_event(struct accept_form_control_context * _Context) {
	int i;
	if(_Context->page_number==3){
	i=_Context->value_Methods;
	if(i>0){
		accept_form_control_hide(_Context);

	drop_forms_method(i);
		accept_form_control_show(_Context);

	}
	}
	return(-1);
}
private int on_Cancel_event(struct accept_form_control_context * _Context) {
	return(27);
	return(-1);
}
private int on_Methods_event(struct accept_form_control_context * _Context) {
	int l;
	l=_Context->value_Methods;
	if(l>0){
	if ( l > 0 ) { _Context->row_Methods=&_Context->buffer_Methods[l-1][0]; } ;
	if(visual_event(2)==_MIMO_RIGHT)
	on_EditMethod_event(_Context);
	}
		return(-1);
}

private int on_ScrollBar_action(struct accept_form_control_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto1904+70+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_ScrollBar -= 1;
		if (_Context->value_ScrollBar < 0) 
			_Context->value_ScrollBar = 0;
	status = accept_form_control_show(_Context);
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto1904+70+330-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_ScrollBar += 1;
		if (_Context->value_ScrollBar > (_Context->max_ScrollBar-_Context->limit_ScrollBar)) 
			_Context->value_ScrollBar = (_Context->max_ScrollBar-_Context->limit_ScrollBar);
	status = accept_form_control_show(_Context);
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_ScrollBar;
		_Context->value_ScrollBar = (((visual_event(6) - (_Context->y_Auto1904+70+20)) * _Context->max_ScrollBar) / (330 - (2 * 20)));
		if (_Context->value_ScrollBar < 0) 
			_Context->value_ScrollBar = 0;
		else if (_Context->value_ScrollBar > (_Context->max_ScrollBar-_Context->limit_ScrollBar)) 
			_Context->value_ScrollBar = (_Context->max_ScrollBar-_Context->limit_ScrollBar);
		if (_Context->value_ScrollBar != aty) {
	status = accept_form_control_show(_Context);
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_ScrollBar -= (_Context->limit_ScrollBar/2);
			if (_Context->value_ScrollBar < 0) 
				_Context->value_ScrollBar = 0;
	status = accept_form_control_show(_Context);
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_ScrollBar += (_Context->limit_ScrollBar/2);
			if (_Context->value_ScrollBar > (_Context->max_ScrollBar-_Context->limit_ScrollBar)) 
				_Context->value_ScrollBar = (_Context->max_ScrollBar-_Context->limit_ScrollBar);
	status = accept_form_control_show(_Context);
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,3);

	return(1);
}
private int on_MemberBar_event(struct accept_form_control_context * _Context) {
	on_FormMembers_show(_Context);
	return(-1);
}

private int on_MemberBar_action(struct accept_form_control_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto1904+70+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_MemberBar -= 1;
		if (_Context->value_MemberBar < 0) 
			_Context->value_MemberBar = 0;
		(void) on_MemberBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto1904+70+330-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_MemberBar += 1;
		if (_Context->value_MemberBar > (_Context->max_MemberBar-_Context->limit_MemberBar)) 
			_Context->value_MemberBar = (_Context->max_MemberBar-_Context->limit_MemberBar);
		(void) on_MemberBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_MemberBar;
		_Context->value_MemberBar = (((visual_event(6) - (_Context->y_Auto1904+70+20)) * _Context->max_MemberBar) / (330 - (2 * 20)));
		if (_Context->value_MemberBar < 0) 
			_Context->value_MemberBar = 0;
		else if (_Context->value_MemberBar > (_Context->max_MemberBar-_Context->limit_MemberBar)) 
			_Context->value_MemberBar = (_Context->max_MemberBar-_Context->limit_MemberBar);
		if (_Context->value_MemberBar != aty) {
		(void) on_MemberBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_MemberBar -= (_Context->limit_MemberBar/2);
			if (_Context->value_MemberBar < 0) 
				_Context->value_MemberBar = 0;
		(void) on_MemberBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_MemberBar += (_Context->limit_MemberBar/2);
			if (_Context->value_MemberBar > (_Context->max_MemberBar-_Context->limit_MemberBar)) 
				_Context->value_MemberBar = (_Context->max_MemberBar-_Context->limit_MemberBar);
		(void) on_MemberBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto1904+680,_Context->y_Auto1904+70,20,330,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,3);

	return(1);
}
private int on_Auto1923_event(struct accept_form_control_context * _Context) {
		accept_form_control_hide(_Context);
;
	standard_text_editor(_Context->buffer_FileName,75);
		accept_form_control_show(_Context);
;
	return(-1);
}
private int on_Auto1924_event(struct accept_form_control_context * _Context) {
		accept_form_control_hide(_Context);
;
	standard_text_editor(_Context->buffer_StyleSheet,75);
		accept_form_control_show(_Context);
;
	return(-1);
}


public	int	accept_form_control_event(
struct accept_form_control_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_FormControl == mb ) return(2);
		if (_Context->trigger_Accept == mb ) return(3);
		if (_Context->trigger_EditMethod == mb ) return(4);
		if (_Context->trigger_DropMethod == mb ) return(5);
		if (_Context->trigger_Cancel == mb ) return(6);
		if (_Context->trigger_International == mb ) return(10);
		if (_Context->trigger_Constants == mb ) return(11);
		if (_Context->trigger_MultipleLanguage == mb ) return(12);
		if (_Context->trigger_Program == mb ) return(13);
		if (_Context->trigger_Overlay == mb ) return(14);
		if (_Context->trigger_PopUp == mb ) return(15);
		if (_Context->trigger_Dynamic == mb ) return(16);
		if (_Context->trigger_CommandLine == mb ) return(17);
		if (_Context->trigger_MouseEvents == mb ) return(20);
		if (_Context->trigger_SendLeft == mb ) return(21);
		if (_Context->trigger_SendMiddle == mb ) return(22);
		if (_Context->trigger_SendRight == mb ) return(23);
		if (_Context->trigger_SendDown == mb ) return(24);
		if (_Context->trigger_SendUp == mb ) return(25);
		if (_Context->trigger_SendWhileDown == mb ) return(26);
		if (_Context->trigger_SendMove == mb ) return(27);
		if (_Context->trigger_MouseKey == mb ) return(28);
		if (_Context->trigger_WidgetTriggers == mb ) return(29);
		if (_Context->trigger_Escape == mb ) return(30);
		if (_Context->trigger_Enter == mb ) return(31);
		if (_Context->trigger_PageUp == mb ) return(32);
		if (_Context->trigger_PageDown == mb ) return(33);
		if (_Context->trigger_UpArrow == mb ) return(34);
		if (_Context->trigger_DownArrow == mb ) return(35);
		if (_Context->trigger_Tabulation == mb ) return(36);
		if (_Context->trigger_DefaultBreak == mb ) return(37);
		if (_Context->trigger_FormMethods == mb ) return(38);
		if (_Context->trigger_FormMemberPage == mb ) return(41);
		if (_Context->trigger_Auto1917 == mb ) return(44);
		if (_Context->trigger_Auto1923 == mb ) return(48);
		if (_Context->trigger_Auto1924 == mb ) return(49);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x1031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto1904+699) )  
	&&  (my >= (_Context->y_Auto1904+4) )  
	&&  (mx <= (_Context->x_Auto1904+716) )  
	&&  (my <= (_Context->y_Auto1904+20) )) {
		return(1);	/* Auto1904 */

		}
	if ((mx >= (_Context->x_Auto1904+683) )  
	&&  (my >= (_Context->y_Auto1904+4) )  
	&&  (mx <= (_Context->x_Auto1904+700) )  
	&&  (my <= (_Context->y_Auto1904+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vform.htm");
			};
		return(-1);	/* Auto1904 */

		}
	if ((mx >= (_Context->x_Auto1904+667) )  
	&&  (my >= (_Context->y_Auto1904+4) )  
	&&  (mx <= (_Context->x_Auto1904+684) )  
	&&  (my <= (_Context->y_Auto1904+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_form_control_show(_Context);
		return(-1);	/* Auto1904 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto1904+4) )  
		&&  (my >= (_Context->y_Auto1904+4) )  
		&&  (mx <= (_Context->x_Auto1904+652) )  
		&&  (my <= (_Context->y_Auto1904+20) )) {
			return( Auto1904action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto1904+10+0) ) 
		&&  ( my >= (_Context->y_Auto1904+30) ) 
		&&  ( mx <= (_Context->x_Auto1904+10+133) ) 
		&&  ( my <= (_Context->y_Auto1904+30+24))) {
			return(2); /* FormControl */
			}
		}
	if (( mx >= (_Context->x_Auto1904+20) ) 
	&&  ( my >= (_Context->y_Auto1904+420) ) 
	&&  ( mx <= (_Context->x_Auto1904+20+154) ) 
	&&  ( my <= (_Context->y_Auto1904+420+32))) {
		return(3); /* Accept */
		}
	if (( mx >= (_Context->x_Auto1904+200) ) 
	&&  ( my >= (_Context->y_Auto1904+420) ) 
	&&  ( mx <= (_Context->x_Auto1904+200+154) ) 
	&&  ( my <= (_Context->y_Auto1904+420+32))) {
		return(4); /* EditMethod */
		}
	if (( mx >= (_Context->x_Auto1904+370) ) 
	&&  ( my >= (_Context->y_Auto1904+420) ) 
	&&  ( mx <= (_Context->x_Auto1904+370+154) ) 
	&&  ( my <= (_Context->y_Auto1904+420+32))) {
		return(5); /* DropMethod */
		}
	if (( mx >= (_Context->x_Auto1904+550) ) 
	&&  ( my >= (_Context->y_Auto1904+420) ) 
	&&  ( mx <= (_Context->x_Auto1904+550+154) ) 
	&&  ( my <= (_Context->y_Auto1904+420+32))) {
		return(6); /* Cancel */
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1904+50+0) ) 
		&&  ( my >= (_Context->y_Auto1904+130) ) 
		&&  ( mx <= (_Context->x_Auto1904+50+168) ) 
		&&  ( my <= (_Context->y_Auto1904+130+16))) {
			return(7); /* FormType */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1904+280+0) ) 
		&&  ( my >= (_Context->y_Auto1904+130) ) 
		&&  ( mx <= (_Context->x_Auto1904+280+168) ) 
		&&  ( my <= (_Context->y_Auto1904+130+16))) {
			return(8); /* ProductionLanguage */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1904+500+0) ) 
		&&  ( my >= (_Context->y_Auto1904+130) ) 
		&&  ( mx <= (_Context->x_Auto1904+500+168) ) 
		&&  ( my <= (_Context->y_Auto1904+130+16))) {
			return(9); /* NationalLanguage */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1904+50) ) 
		&&  ( my >= (_Context->y_Auto1904+260) ) 
		&&  ( mx <= (_Context->x_Auto1904+50+322) ) 
		&&  ( my <= (_Context->y_Auto1904+260+16))) {
			return(10); /* International */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1904+50) ) 
		&&  ( my >= (_Context->y_Auto1904+330) ) 
		&&  ( mx <= (_Context->x_Auto1904+50+294) ) 
		&&  ( my <= (_Context->y_Auto1904+330+16))) {
			return(11); /* Constants */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1904+400) ) 
		&&  ( my >= (_Context->y_Auto1904+260) ) 
		&&  ( mx <= (_Context->x_Auto1904+400+280) ) 
		&&  ( my <= (_Context->y_Auto1904+260+16))) {
			return(12); /* MultipleLanguage */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1904+50) ) 
		&&  ( my >= (_Context->y_Auto1904+230) ) 
		&&  ( mx <= (_Context->x_Auto1904+50+322) ) 
		&&  ( my <= (_Context->y_Auto1904+230+16))) {
			return(13); /* Program */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1904+400) ) 
		&&  ( my >= (_Context->y_Auto1904+230) ) 
		&&  ( mx <= (_Context->x_Auto1904+400+280) ) 
		&&  ( my <= (_Context->y_Auto1904+230+16))) {
			return(14); /* Overlay */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1904+400) ) 
		&&  ( my >= (_Context->y_Auto1904+300) ) 
		&&  ( mx <= (_Context->x_Auto1904+400+294) ) 
		&&  ( my <= (_Context->y_Auto1904+300+16))) {
			return(15); /* PopUp */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1904+400) ) 
		&&  ( my >= (_Context->y_Auto1904+330) ) 
		&&  ( mx <= (_Context->x_Auto1904+400+294) ) 
		&&  ( my <= (_Context->y_Auto1904+330+16))) {
			return(16); /* Dynamic */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1904+50) ) 
		&&  ( my >= (_Context->y_Auto1904+300) ) 
		&&  ( mx <= (_Context->x_Auto1904+50+280) ) 
		&&  ( my <= (_Context->y_Auto1904+300+16))) {
			return(17); /* CommandLine */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1904+400) ) 
		&&  ( my >= (_Context->y_Auto1904+360) ) 
		&&  ( mx <= (_Context->x_Auto1904+400+96) ) 
		&&  ( my <= (_Context->y_Auto1904+360+16))) {
			return(18); /* ArgVLen */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1904+520) ) 
		&&  ( my >= (_Context->y_Auto1904+360) ) 
		&&  ( mx <= (_Context->x_Auto1904+520+104) ) 
		&&  ( my <= (_Context->y_Auto1904+360+16))) {
			return(19); /* ArgVNb */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto1904+10+134) ) 
		&&  ( my >= (_Context->y_Auto1904+30) ) 
		&&  ( mx <= (_Context->x_Auto1904+10+260) ) 
		&&  ( my <= (_Context->y_Auto1904+30+24))) {
			return(20); /* MouseEvents */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+40) ) 
		&&  ( my >= (_Context->y_Auto1904+100) ) 
		&&  ( mx <= (_Context->x_Auto1904+40+238) ) 
		&&  ( my <= (_Context->y_Auto1904+100+16))) {
			return(21); /* SendLeft */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+280) ) 
		&&  ( my >= (_Context->y_Auto1904+100) ) 
		&&  ( mx <= (_Context->x_Auto1904+280+196) ) 
		&&  ( my <= (_Context->y_Auto1904+100+16))) {
			return(22); /* SendMiddle */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+490) ) 
		&&  ( my >= (_Context->y_Auto1904+100) ) 
		&&  ( mx <= (_Context->x_Auto1904+490+196) ) 
		&&  ( my <= (_Context->y_Auto1904+100+16))) {
			return(23); /* SendRight */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+40) ) 
		&&  ( my >= (_Context->y_Auto1904+170) ) 
		&&  ( mx <= (_Context->x_Auto1904+40+224) ) 
		&&  ( my <= (_Context->y_Auto1904+170+16))) {
			return(24); /* SendDown */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+280) ) 
		&&  ( my >= (_Context->y_Auto1904+170) ) 
		&&  ( mx <= (_Context->x_Auto1904+280+196) ) 
		&&  ( my <= (_Context->y_Auto1904+170+16))) {
			return(25); /* SendUp */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+40) ) 
		&&  ( my >= (_Context->y_Auto1904+200) ) 
		&&  ( mx <= (_Context->x_Auto1904+40+238) ) 
		&&  ( my <= (_Context->y_Auto1904+200+16))) {
			return(26); /* SendWhileDown */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+280) ) 
		&&  ( my >= (_Context->y_Auto1904+200) ) 
		&&  ( mx <= (_Context->x_Auto1904+280+196) ) 
		&&  ( my <= (_Context->y_Auto1904+200+16))) {
			return(27); /* SendMove */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+490) ) 
		&&  ( my >= (_Context->y_Auto1904+170) ) 
		&&  ( mx <= (_Context->x_Auto1904+490+196) ) 
		&&  ( my <= (_Context->y_Auto1904+170+16))) {
			return(28); /* MouseKey */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+490) ) 
		&&  ( my >= (_Context->y_Auto1904+200) ) 
		&&  ( mx <= (_Context->x_Auto1904+490+210) ) 
		&&  ( my <= (_Context->y_Auto1904+200+16))) {
			return(29); /* WidgetTriggers */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+40) ) 
		&&  ( my >= (_Context->y_Auto1904+270) ) 
		&&  ( mx <= (_Context->x_Auto1904+40+238) ) 
		&&  ( my <= (_Context->y_Auto1904+270+16))) {
			return(30); /* Escape */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+280) ) 
		&&  ( my >= (_Context->y_Auto1904+270) ) 
		&&  ( mx <= (_Context->x_Auto1904+280+210) ) 
		&&  ( my <= (_Context->y_Auto1904+270+16))) {
			return(31); /* Enter */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+40) ) 
		&&  ( my >= (_Context->y_Auto1904+310) ) 
		&&  ( mx <= (_Context->x_Auto1904+40+238) ) 
		&&  ( my <= (_Context->y_Auto1904+310+16))) {
			return(32); /* PageUp */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+40) ) 
		&&  ( my >= (_Context->y_Auto1904+350) ) 
		&&  ( mx <= (_Context->x_Auto1904+40+238) ) 
		&&  ( my <= (_Context->y_Auto1904+350+16))) {
			return(33); /* PageDown */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+280) ) 
		&&  ( my >= (_Context->y_Auto1904+310) ) 
		&&  ( mx <= (_Context->x_Auto1904+280+210) ) 
		&&  ( my <= (_Context->y_Auto1904+310+16))) {
			return(34); /* UpArrow */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+280) ) 
		&&  ( my >= (_Context->y_Auto1904+350) ) 
		&&  ( mx <= (_Context->x_Auto1904+280+210) ) 
		&&  ( my <= (_Context->y_Auto1904+350+16))) {
			return(35); /* DownArrow */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+490) ) 
		&&  ( my >= (_Context->y_Auto1904+270) ) 
		&&  ( mx <= (_Context->x_Auto1904+490+182) ) 
		&&  ( my <= (_Context->y_Auto1904+270+16))) {
			return(36); /* Tabulation */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1904+490) ) 
		&&  ( my >= (_Context->y_Auto1904+310) ) 
		&&  ( mx <= (_Context->x_Auto1904+490+182) ) 
		&&  ( my <= (_Context->y_Auto1904+310+16))) {
			return(37); /* DefaultBreak */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_Auto1904+10+261) ) 
		&&  ( my >= (_Context->y_Auto1904+30) ) 
		&&  ( mx <= (_Context->x_Auto1904+10+396) ) 
		&&  ( my <= (_Context->y_Auto1904+30+24))) {
			return(38); /* FormMethods */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto1904+20) ) 
		&&  ( my >= (_Context->y_Auto1904+70) ) 
		&&  ( mx <= (_Context->x_Auto1904+20+660) ) 
		&&  ( my <= (_Context->y_Auto1904+70+330))) {
			if ((_Context->value_Methods = ((visual_event(6) - (_Context->y_Auto1904+70)) / 16)) < 1)
				_Context->value_Methods=0;
else if (_Context->value_Methods > 19 )
				_Context->value_Methods=19;
			if ( _Context->value_Methods > 0 ) { _Context->row_Methods = &_Context->buffer_Methods[(_Context->value_Methods-1)][0]; } 
			_Context->column_Methods = (visual_event(7) - (_Context->x_Auto1904+20));
			if ( _Context->column_Methods < 137 ) {
				_Context->column_Methods = 1;
				}
			else if ( _Context->column_Methods < 402 ) {
				_Context->column_Methods = 2;
				}
			else if ( _Context->column_Methods < 659 ) {
				_Context->column_Methods = 3;
				}
			return(39); /* Methods */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto1904+680) ) 
		&&  ( my >= (_Context->y_Auto1904+70) ) 
		&&  ( mx <= (_Context->x_Auto1904+680+20) ) 
		&&  ( my <= (_Context->y_Auto1904+70+330))) {
			return(40); /* ScrollBar */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_Auto1904+10+397) ) 
		&&  ( my >= (_Context->y_Auto1904+30) ) 
		&&  ( mx <= (_Context->x_Auto1904+10+536) ) 
		&&  ( my <= (_Context->y_Auto1904+30+24))) {
			return(41); /* FormMemberPage */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto1904+20) ) 
		&&  ( my >= (_Context->y_Auto1904+70) ) 
		&&  ( mx <= (_Context->x_Auto1904+20+660) ) 
		&&  ( my <= (_Context->y_Auto1904+70+330))) {
			if ((_Context->value_FormMembers = ((visual_event(6) - (_Context->y_Auto1904+70)) / 16)) < 1)
				_Context->value_FormMembers=0;
else if (_Context->value_FormMembers > 19 )
				_Context->value_FormMembers=19;
			if ( _Context->value_FormMembers > 0 ) { _Context->row_FormMembers = &_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0]; } 
			_Context->column_FormMembers = (visual_event(7) - (_Context->x_Auto1904+20));
			if ( _Context->column_FormMembers < 441 ) {
				_Context->column_FormMembers = 1;
				}
			else if ( _Context->column_FormMembers < 514 ) {
				_Context->column_FormMembers = 2;
				}
			else if ( _Context->column_FormMembers < 563 ) {
				_Context->column_FormMembers = 3;
				}
			else if ( _Context->column_FormMembers < 612 ) {
				_Context->column_FormMembers = 4;
				}
			else if ( _Context->column_FormMembers < 661 ) {
				_Context->column_FormMembers = 5;
				}
			return(42); /* FormMembers */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto1904+680) ) 
		&&  ( my >= (_Context->y_Auto1904+70) ) 
		&&  ( mx <= (_Context->x_Auto1904+680+20) ) 
		&&  ( my <= (_Context->y_Auto1904+70+330))) {
			return(43); /* MemberBar */
			}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if (( mx >= (_Context->x_Auto1904+10+537) ) 
		&&  ( my >= (_Context->y_Auto1904+30) ) 
		&&  ( mx <= (_Context->x_Auto1904+10+638) ) 
		&&  ( my <= (_Context->y_Auto1904+30+24))) {
			return(44); /* Auto1917 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto1904+40) ) 
		&&  ( my >= (_Context->y_Auto1904+130) ) 
		&&  ( mx <= (_Context->x_Auto1904+40+600) ) 
		&&  ( my <= (_Context->y_Auto1904+130+16))) {
			return(47); /* FileName */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto1904+644) ) 
		&&  ( my >= (_Context->y_Auto1904+131) ) 
		&&  ( mx <= (_Context->x_Auto1904+644+16) ) 
		&&  ( my <= (_Context->y_Auto1904+131+16))) {
			return(48); /* Auto1923 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto1904+644) ) 
		&&  ( my >= (_Context->y_Auto1904+231) ) 
		&&  ( mx <= (_Context->x_Auto1904+644+16) ) 
		&&  ( my <= (_Context->y_Auto1904+231+16))) {
			return(49); /* Auto1924 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto1904+40) ) 
		&&  ( my >= (_Context->y_Auto1904+180) ) 
		&&  ( mx <= (_Context->x_Auto1904+40+624) ) 
		&&  ( my <= (_Context->y_Auto1904+180+16))) {
			return(50); /* Identity */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto1904+40) ) 
		&&  ( my >= (_Context->y_Auto1904+230) ) 
		&&  ( mx <= (_Context->x_Auto1904+40+600) ) 
		&&  ( my <= (_Context->y_Auto1904+230+16))) {
			return(51); /* StyleSheet */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto1904+40) ) 
		&&  ( my >= (_Context->y_Auto1904+280) ) 
		&&  ( mx <= (_Context->x_Auto1904+40+630) ) 
		&&  ( my <= (_Context->y_Auto1904+280+20))) {
			return(52); /* ClearScreen */
			}
		}

	return(-1);
}
private int on_FormMembers_losefocus(struct accept_form_control_context * _Context) {
	int n,l,f,s;
	l=_Context->value_FormMembers;
	if(l>0){
	if ( l > 0 ) { _Context->row_FormMembers=&_Context->buffer_FormMembers[l-1][0]; } ;
	switch(_Context->column_FormMembers){
	case 2:
	break;
	case 1:
	case 3:
	case 4:
	case 5:
	n=atoi((_Context->row_FormMembers+64));
	f=atoi((_Context->row_FormMembers+70));
	s=atoi((_Context->row_FormMembers+76));
	put_forms_member(l+_Context->value_MemberBar,(_Context->row_FormMembers+0),55,n,f,s);
	}
	}
	on_FormMembers_show(_Context);
	return(-1);
}


public	int	accept_form_control_losefocus(struct accept_form_control_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;
		case 3 : 
			break;
		case 4 : 
			break;
		case 5 : 
			break;

		}
	return(0);

}
private int on_FormMembers_getfocus(struct accept_form_control_context * _Context) {
	int Status;
	int l;
	struct forms_data_member*get_forms_member(int);
	struct forms_data_member*dptr;
	if(_Context->column_FormMembers==2){
	l=_Context->value_FormMembers;
	if(!(dptr=get_forms_member(l+_Context->value_MemberBar))){
		_Context->row_FormMembers = &_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0];
	switch (_Context->column_FormMembers) {
	case	0x1 :
		_Context->keycode=visual_edit((_Context->x_Auto1904+20+2),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),432,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0],54);
	visual_text((_Context->x_Auto1904+20+2),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),432,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0],54,0);
		break;
	case	0x2 :
		_Context->keycode=visual_edit((_Context->x_Auto1904+20+442),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),64,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][55],8);
	visual_text((_Context->x_Auto1904+20+442),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),64,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][55],8,0);
		break;
	case	0x3 :
		_Context->keycode=visual_edit((_Context->x_Auto1904+20+514),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][64],5);
	visual_text((_Context->x_Auto1904+20+514),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][64],5,0);
		break;
	case	0x4 :
		_Context->keycode=visual_edit((_Context->x_Auto1904+20+562),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][70],5);
	visual_text((_Context->x_Auto1904+20+562),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][70],5,0);
		break;
	case	0x5 :
		_Context->keycode=visual_edit((_Context->x_Auto1904+20+610),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][76],5);
	visual_text((_Context->x_Auto1904+20+610),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][76],5,0);
		break;
		}
;
	}
	else{
	_Context->x_TypeSelect=_Context->x_Auto1904+460;_Context->y_TypeSelect=_Context->y_Auto1904+60;_Context->w_TypeSelect=72;_Context->h_TypeSelect=80;;
	_Context->y_TypeSelect+=((l+1)*16);
	_Context->value_TypeSelect=dptr->type;
		if ((_Context->p_TypeSelect != (void *) 0)
	&& (_Context->s_TypeSelect == 0)) {
		(void)visual_buffer_get(_Context->p_TypeSelect,_Context->x_TypeSelect,_Context->y_TypeSelect);
		_Context->s_TypeSelect=1;
		}
	if ((_Context->p_TypeSelect != (void *) 0)
	&& (_Context->s_TypeSelect == 0)) {
		(void)visual_buffer_get(_Context->p_TypeSelect,_Context->x_TypeSelect,_Context->y_TypeSelect);
		_Context->s_TypeSelect=1;
		}
	visual_select(_Context->x_TypeSelect,_Context->y_TypeSelect,_Context->w_TypeSelect,_Context->h_TypeSelect,_Context->fid_TypeSelect,0,0,parse_selection(_Context->msg_TypeSelect[_Context->language],&_Context->value_TypeSelect),0);
;
		_Context->keycode = visual_select(_Context->x_TypeSelect,_Context->y_TypeSelect,_Context->w_TypeSelect,_Context->h_TypeSelect,_Context->fid_TypeSelect,0,0,parse_selection(_Context->msg_TypeSelect[_Context->language],&_Context->value_TypeSelect),2);
;
		if ((_Context->p_TypeSelect != (void *) 0)
	&& (_Context->s_TypeSelect != 0)) {
		(void)visual_buffer_put(_Context->p_TypeSelect,_Context->x_TypeSelect,_Context->y_TypeSelect);
		_Context->s_TypeSelect=0;
		}
;
	dptr->type=_Context->value_TypeSelect;
	}
	}
	else{
		_Context->row_FormMembers = &_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0];
	switch (_Context->column_FormMembers) {
	case	0x1 :
		_Context->keycode=visual_edit((_Context->x_Auto1904+20+2),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),432,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0],54);
	visual_text((_Context->x_Auto1904+20+2),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),432,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0],54,0);
		break;
	case	0x2 :
		_Context->keycode=visual_edit((_Context->x_Auto1904+20+442),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),64,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][55],8);
	visual_text((_Context->x_Auto1904+20+442),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),64,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][55],8,0);
		break;
	case	0x3 :
		_Context->keycode=visual_edit((_Context->x_Auto1904+20+514),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][64],5);
	visual_text((_Context->x_Auto1904+20+514),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][64],5,0);
		break;
	case	0x4 :
		_Context->keycode=visual_edit((_Context->x_Auto1904+20+562),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][70],5);
	visual_text((_Context->x_Auto1904+20+562),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][70],5,0);
		break;
	case	0x5 :
		_Context->keycode=visual_edit((_Context->x_Auto1904+20+610),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][76],5);
	visual_text((_Context->x_Auto1904+20+610),(_Context->y_Auto1904+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][76],5,0);
		break;
		}
;
	}
		return(-1);
}


public	int	accept_form_control_focus(struct accept_form_control_context * _Context)
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
				visual_button(_Context->x_Auto1904+20,_Context->y_Auto1904+420,154,32,vfh[2],175,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1904+20,_Context->y_Auto1904+420,154,32,vfh[2],175,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x4 :
				/* EditMethod */
				visual_button(_Context->x_Auto1904+200,_Context->y_Auto1904+420,154,32,vfh[2],28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1904+200,_Context->y_Auto1904+420,154,32,vfh[2],28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),0);
				break;
			case	0x5 :
				/* DropMethod */
				visual_button(_Context->x_Auto1904+370,_Context->y_Auto1904+420,154,32,vfh[2],28,28,_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1904+370,_Context->y_Auto1904+420,154,32,vfh[2],28,28,_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]),0);
				break;
			case	0x6 :
				/* Cancel */
				visual_button(_Context->x_Auto1904+550,_Context->y_Auto1904+420,154,32,vfh[2],175,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1904+550,_Context->y_Auto1904+420,154,32,vfh[2],175,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0x7 :
				/* FormType */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto1904+50,_Context->y_Auto1904+130,168,144,vfh[1],27,0,parse_selection(FormTypeList,&_Context->value_FormType),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* ProductionLanguage */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto1904+280,_Context->y_Auto1904+130,168,144,vfh[1],27,0,parse_selection(ProductionLanguageList,&_Context->value_ProductionLanguage),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* NationalLanguage */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto1904+500,_Context->y_Auto1904+130,168,144,vfh[1],27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* International */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto1904+50,_Context->y_Auto1904+260,322,16,vfh[2],28,28,_Context->msg_International[_Context->language],strlen(_Context->msg_International[_Context->language]),(_Context->value_International |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+50,_Context->y_Auto1904+260,322,16,vfh[2],28,28,_Context->msg_International[_Context->language],strlen(_Context->msg_International[_Context->language]),(_Context->value_International |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* Constants */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto1904+50,_Context->y_Auto1904+330,294,16,vfh[2],28,28,_Context->msg_Constants[_Context->language],strlen(_Context->msg_Constants[_Context->language]),(_Context->value_Constants |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+50,_Context->y_Auto1904+330,294,16,vfh[2],28,28,_Context->msg_Constants[_Context->language],strlen(_Context->msg_Constants[_Context->language]),(_Context->value_Constants |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* MultipleLanguage */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto1904+400,_Context->y_Auto1904+260,280,16,vfh[2],28,28,_Context->msg_MultipleLanguage[_Context->language],strlen(_Context->msg_MultipleLanguage[_Context->language]),(_Context->value_MultipleLanguage |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+400,_Context->y_Auto1904+260,280,16,vfh[2],28,28,_Context->msg_MultipleLanguage[_Context->language],strlen(_Context->msg_MultipleLanguage[_Context->language]),(_Context->value_MultipleLanguage |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* Program */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto1904+50,_Context->y_Auto1904+230,322,16,vfh[2],27,0,_Context->msg_Program[_Context->language],strlen(_Context->msg_Program[_Context->language]),(_Context->value_Program |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+50,_Context->y_Auto1904+230,322,16,vfh[2],27,0,_Context->msg_Program[_Context->language],strlen(_Context->msg_Program[_Context->language]),(_Context->value_Program |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* Overlay */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto1904+400,_Context->y_Auto1904+230,280,16,vfh[2],27,0,_Context->msg_Overlay[_Context->language],strlen(_Context->msg_Overlay[_Context->language]),(_Context->value_Overlay |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+400,_Context->y_Auto1904+230,280,16,vfh[2],27,0,_Context->msg_Overlay[_Context->language],strlen(_Context->msg_Overlay[_Context->language]),(_Context->value_Overlay |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* PopUp */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto1904+400,_Context->y_Auto1904+300,294,16,vfh[2],27,0,_Context->msg_PopUp[_Context->language],strlen(_Context->msg_PopUp[_Context->language]),(_Context->value_PopUp |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+400,_Context->y_Auto1904+300,294,16,vfh[2],27,0,_Context->msg_PopUp[_Context->language],strlen(_Context->msg_PopUp[_Context->language]),(_Context->value_PopUp |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* Dynamic */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto1904+400,_Context->y_Auto1904+330,294,16,vfh[2],27,0,_Context->msg_Dynamic[_Context->language],strlen(_Context->msg_Dynamic[_Context->language]),(_Context->value_Dynamic |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+400,_Context->y_Auto1904+330,294,16,vfh[2],27,0,_Context->msg_Dynamic[_Context->language],strlen(_Context->msg_Dynamic[_Context->language]),(_Context->value_Dynamic |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* CommandLine */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto1904+50,_Context->y_Auto1904+300,280,16,vfh[2],28,28,_Context->msg_CommandLine[_Context->language],strlen(_Context->msg_CommandLine[_Context->language]),(_Context->value_CommandLine |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+50,_Context->y_Auto1904+300,280,16,vfh[2],28,28,_Context->msg_CommandLine[_Context->language],strlen(_Context->msg_CommandLine[_Context->language]),(_Context->value_CommandLine |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* ArgVLen */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1904+400+1,_Context->y_Auto1904+360+1,96,16,vfh[1],_Context->buffer_ArgVLen,12);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* ArgVNb */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1904+520+1,_Context->y_Auto1904+360+1,104,16,vfh[1],_Context->buffer_ArgVNb,13);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* MouseEvents */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x15 :
				/* SendLeft */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+100,238,16,vfh[2],27,0,_Context->msg_SendLeft[_Context->language],strlen(_Context->msg_SendLeft[_Context->language]),(_Context->value_SendLeft |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+100,238,16,vfh[2],27,0,_Context->msg_SendLeft[_Context->language],strlen(_Context->msg_SendLeft[_Context->language]),(_Context->value_SendLeft |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* SendMiddle */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+100,196,16,vfh[2],27,0,_Context->msg_SendMiddle[_Context->language],strlen(_Context->msg_SendMiddle[_Context->language]),(_Context->value_SendMiddle |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+100,196,16,vfh[2],27,0,_Context->msg_SendMiddle[_Context->language],strlen(_Context->msg_SendMiddle[_Context->language]),(_Context->value_SendMiddle |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* SendRight */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+100,196,16,vfh[2],27,0,_Context->msg_SendRight[_Context->language],strlen(_Context->msg_SendRight[_Context->language]),(_Context->value_SendRight |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+100,196,16,vfh[2],27,0,_Context->msg_SendRight[_Context->language],strlen(_Context->msg_SendRight[_Context->language]),(_Context->value_SendRight |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* SendDown */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+170,224,16,vfh[2],27,0,_Context->msg_SendDown[_Context->language],strlen(_Context->msg_SendDown[_Context->language]),(_Context->value_SendDown |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+170,224,16,vfh[2],27,0,_Context->msg_SendDown[_Context->language],strlen(_Context->msg_SendDown[_Context->language]),(_Context->value_SendDown |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* SendUp */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+170,196,16,vfh[2],27,0,_Context->msg_SendUp[_Context->language],strlen(_Context->msg_SendUp[_Context->language]),(_Context->value_SendUp |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+170,196,16,vfh[2],27,0,_Context->msg_SendUp[_Context->language],strlen(_Context->msg_SendUp[_Context->language]),(_Context->value_SendUp |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* SendWhileDown */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+200,238,16,vfh[2],27,0,_Context->msg_SendWhileDown[_Context->language],strlen(_Context->msg_SendWhileDown[_Context->language]),(_Context->value_SendWhileDown |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+200,238,16,vfh[2],27,0,_Context->msg_SendWhileDown[_Context->language],strlen(_Context->msg_SendWhileDown[_Context->language]),(_Context->value_SendWhileDown |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* SendMove */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+200,196,16,vfh[2],16,0,_Context->msg_SendMove[_Context->language],strlen(_Context->msg_SendMove[_Context->language]),(_Context->value_SendMove |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+200,196,16,vfh[2],16,0,_Context->msg_SendMove[_Context->language],strlen(_Context->msg_SendMove[_Context->language]),(_Context->value_SendMove |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* MouseKey */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+170,196,16,vfh[2],16,0,_Context->msg_MouseKey[_Context->language],strlen(_Context->msg_MouseKey[_Context->language]),(_Context->value_MouseKey |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+170,196,16,vfh[2],16,0,_Context->msg_MouseKey[_Context->language],strlen(_Context->msg_MouseKey[_Context->language]),(_Context->value_MouseKey |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* WidgetTriggers */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+200,210,16,vfh[2],16,0,_Context->msg_WidgetTriggers[_Context->language],strlen(_Context->msg_WidgetTriggers[_Context->language]),(_Context->value_WidgetTriggers |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+200,210,16,vfh[2],16,0,_Context->msg_WidgetTriggers[_Context->language],strlen(_Context->msg_WidgetTriggers[_Context->language]),(_Context->value_WidgetTriggers |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* Escape */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+270,238,16,vfh[2],27,0,_Context->msg_Escape[_Context->language],strlen(_Context->msg_Escape[_Context->language]),(_Context->value_Escape |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+270,238,16,vfh[2],27,0,_Context->msg_Escape[_Context->language],strlen(_Context->msg_Escape[_Context->language]),(_Context->value_Escape |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* Enter */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+270,210,16,vfh[2],27,0,_Context->msg_Enter[_Context->language],strlen(_Context->msg_Enter[_Context->language]),(_Context->value_Enter |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+270,210,16,vfh[2],27,0,_Context->msg_Enter[_Context->language],strlen(_Context->msg_Enter[_Context->language]),(_Context->value_Enter |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* PageUp */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+310,238,16,vfh[2],27,0,_Context->msg_PageUp[_Context->language],strlen(_Context->msg_PageUp[_Context->language]),(_Context->value_PageUp |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+310,238,16,vfh[2],27,0,_Context->msg_PageUp[_Context->language],strlen(_Context->msg_PageUp[_Context->language]),(_Context->value_PageUp |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* PageDown */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+350,238,16,vfh[2],27,0,_Context->msg_PageDown[_Context->language],strlen(_Context->msg_PageDown[_Context->language]),(_Context->value_PageDown |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+40,_Context->y_Auto1904+350,238,16,vfh[2],27,0,_Context->msg_PageDown[_Context->language],strlen(_Context->msg_PageDown[_Context->language]),(_Context->value_PageDown |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* UpArrow */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+310,210,16,vfh[2],27,0,_Context->msg_UpArrow[_Context->language],strlen(_Context->msg_UpArrow[_Context->language]),(_Context->value_UpArrow |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+310,210,16,vfh[2],27,0,_Context->msg_UpArrow[_Context->language],strlen(_Context->msg_UpArrow[_Context->language]),(_Context->value_UpArrow |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* DownArrow */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+350,210,16,vfh[2],27,0,_Context->msg_DownArrow[_Context->language],strlen(_Context->msg_DownArrow[_Context->language]),(_Context->value_DownArrow |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+280,_Context->y_Auto1904+350,210,16,vfh[2],27,0,_Context->msg_DownArrow[_Context->language],strlen(_Context->msg_DownArrow[_Context->language]),(_Context->value_DownArrow |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* Tabulation */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+270,182,16,vfh[2],27,0,_Context->msg_Tabulation[_Context->language],strlen(_Context->msg_Tabulation[_Context->language]),(_Context->value_Tabulation |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+270,182,16,vfh[2],27,0,_Context->msg_Tabulation[_Context->language],strlen(_Context->msg_Tabulation[_Context->language]),(_Context->value_Tabulation |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x25 :
				/* DefaultBreak */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+310,182,16,vfh[2],27,0,_Context->msg_DefaultBreak[_Context->language],strlen(_Context->msg_DefaultBreak[_Context->language]),(_Context->value_DefaultBreak |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1904+490,_Context->y_Auto1904+310,182,16,vfh[2],27,0,_Context->msg_DefaultBreak[_Context->language],strlen(_Context->msg_DefaultBreak[_Context->language]),(_Context->value_DefaultBreak |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* FormMethods */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x27 :
				/* Methods */
				if (_Context->page_number == 3 ) {
					_Context->row_Methods = &_Context->buffer_Methods[(_Context->value_Methods-1)][0];
					switch (_Context->column_Methods) {
					case	0x1 :
						_Context->keycode=visual_edit((_Context->x_Auto1904+20+2),(_Context->y_Auto1904+70+(_Context->value_Methods*16)+2),128,16,vfh[1],&_Context->buffer_Methods[(_Context->value_Methods-1)][0],16);
					visual_text((_Context->x_Auto1904+20+2),(_Context->y_Auto1904+70+(_Context->value_Methods*16)+2),128,16,vfh[1],0,(24-((_Context->value_Methods-1)&1)),&_Context->buffer_Methods[(_Context->value_Methods-1)][0],16,0);
						break;
					case	0x2 :
						_Context->keycode=visual_edit((_Context->x_Auto1904+20+138),(_Context->y_Auto1904+70+(_Context->value_Methods*16)+2),256,16,vfh[1],&_Context->buffer_Methods[(_Context->value_Methods-1)][17],32);
					visual_text((_Context->x_Auto1904+20+138),(_Context->y_Auto1904+70+(_Context->value_Methods*16)+2),256,16,vfh[1],0,(24-((_Context->value_Methods-1)&1)),&_Context->buffer_Methods[(_Context->value_Methods-1)][17],32,0);
						break;
					case	0x3 :
						_Context->keycode=visual_edit((_Context->x_Auto1904+20+402),(_Context->y_Auto1904+70+(_Context->value_Methods*16)+2),248,16,vfh[1],&_Context->buffer_Methods[(_Context->value_Methods-1)][50],31);
					visual_text((_Context->x_Auto1904+20+402),(_Context->y_Auto1904+70+(_Context->value_Methods*16)+2),248,16,vfh[1],0,(24-((_Context->value_Methods-1)&1)),&_Context->buffer_Methods[(_Context->value_Methods-1)][50],31,0);
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
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* FormMemberPage */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x2a :
				/* FormMembers */
				if (_Context->page_number == 4 ) {
					(void) on_FormMembers_getfocus(_Context);
					(void) on_FormMembers_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2c :
				/* Auto1917 */
				if (_Context->page_number == 5 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x2f :
				/* FileName */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1904+40+1,_Context->y_Auto1904+130+1,600,16,vfh[1],_Context->buffer_FileName,75);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x30 :
				/* Auto1923 */
				if (_Context->page_number == 5 ) {
					visual_button(_Context->x_Auto1904+644,_Context->y_Auto1904+131,16,16,vfh[8],27,28,_Context->msg_Auto1923[_Context->language],strlen(_Context->msg_Auto1923[_Context->language]),786);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1904+644,_Context->y_Auto1904+131,16,16,vfh[8],27,28,_Context->msg_Auto1923[_Context->language],strlen(_Context->msg_Auto1923[_Context->language]),784);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x31 :
				/* Auto1924 */
				if (_Context->page_number == 5 ) {
					visual_button(_Context->x_Auto1904+644,_Context->y_Auto1904+231,16,16,vfh[8],27,28,_Context->msg_Auto1924[_Context->language],strlen(_Context->msg_Auto1924[_Context->language]),786);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1904+644,_Context->y_Auto1904+231,16,16,vfh[8],27,28,_Context->msg_Auto1924[_Context->language],strlen(_Context->msg_Auto1924[_Context->language]),784);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x32 :
				/* Identity */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1904+40+1,_Context->y_Auto1904+180+1,624,16,vfh[1],_Context->buffer_Identity,78);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x33 :
				/* StyleSheet */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1904+40+1,_Context->y_Auto1904+230+1,600,16,vfh[1],_Context->buffer_StyleSheet,75);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x34 :
				/* ClearScreen */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1904+40+1,_Context->y_Auto1904+280+1,630,20,vfh[1],_Context->buffer_ClearScreen,78);
				} else {
					_Context->keycode = 5;
					}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			accept_form_control_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_form_control_show(_Context);
			continue;
		case	0x2 :
			accept_form_control_losefocus(_Context);
			_Context->page_number=5;
			_Context->focus_item=52;
			accept_form_control_show(_Context);
			continue;
		case	0x3 :
			accept_form_control_losefocus(_Context);
			if ( _Context->page_number < 5 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_form_control_show(_Context);
			continue;
		case	0x12 :
			accept_form_control_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_form_control_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_form_control_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1904 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* FormControl */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_form_control_losefocus(_Context);
							_Context->page_number = 1;
							accept_form_control_show(_Context);
							}
						continue;
					case	0x3 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1904+20,_Context->y_Auto1904+420,154,32,vfh[2],175,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1904+20,_Context->y_Auto1904+420,154,32,vfh[2],175,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* EditMethod */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1904+200,_Context->y_Auto1904+420,154,32,vfh[2],28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1904+200,_Context->y_Auto1904+420,154,32,vfh[2],28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_EditMethod_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* DropMethod */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1904+370,_Context->y_Auto1904+420,154,32,vfh[2],28,28,_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1904+370,_Context->y_Auto1904+420,154,32,vfh[2],28,28,_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_DropMethod_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1904+550,_Context->y_Auto1904+420,154,32,vfh[2],175,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1904+550,_Context->y_Auto1904+420,154,32,vfh[2],175,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0x7 :
						/* FormType */
						continue;
					case	0x8 :
						/* ProductionLanguage */
						continue;
					case	0x9 :
						/* NationalLanguage */
						continue;
					case	0xa :
						/* International */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_International += 1;
							_Context->value_International &= 1;
							}
						continue;
					case	0xb :
						/* Constants */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Constants += 1;
							_Context->value_Constants &= 1;
							}
						continue;
					case	0xc :
						/* MultipleLanguage */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MultipleLanguage += 1;
							_Context->value_MultipleLanguage &= 1;
							}
						continue;
					case	0xd :
						/* Program */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Program += 1;
							_Context->value_Program &= 1;
							}
						continue;
					case	0xe :
						/* Overlay */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Overlay += 1;
							_Context->value_Overlay &= 1;
							}
						continue;
					case	0xf :
						/* PopUp */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_PopUp += 1;
							_Context->value_PopUp &= 1;
							}
						continue;
					case	0x10 :
						/* Dynamic */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Dynamic += 1;
							_Context->value_Dynamic &= 1;
							}
						continue;
					case	0x11 :
						/* CommandLine */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_CommandLine += 1;
							_Context->value_CommandLine &= 1;
							}
						continue;
					case	0x12 :
						/* ArgVLen */
						continue;
					case	0x13 :
						/* ArgVNb */
						continue;
					case	0x14 :
						/* MouseEvents */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_form_control_losefocus(_Context);
							_Context->page_number = 2;
							accept_form_control_show(_Context);
							}
						continue;
					case	0x15 :
						/* SendLeft */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SendLeft += 1;
							_Context->value_SendLeft &= 1;
							}
						continue;
					case	0x16 :
						/* SendMiddle */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SendMiddle += 1;
							_Context->value_SendMiddle &= 1;
							}
						continue;
					case	0x17 :
						/* SendRight */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SendRight += 1;
							_Context->value_SendRight &= 1;
							}
						continue;
					case	0x18 :
						/* SendDown */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SendDown += 1;
							_Context->value_SendDown &= 1;
							}
						continue;
					case	0x19 :
						/* SendUp */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SendUp += 1;
							_Context->value_SendUp &= 1;
							}
						continue;
					case	0x1a :
						/* SendWhileDown */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SendWhileDown += 1;
							_Context->value_SendWhileDown &= 1;
							}
						continue;
					case	0x1b :
						/* SendMove */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SendMove += 1;
							_Context->value_SendMove &= 1;
							}
						continue;
					case	0x1c :
						/* MouseKey */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MouseKey += 1;
							_Context->value_MouseKey &= 1;
							}
						continue;
					case	0x1d :
						/* WidgetTriggers */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_WidgetTriggers += 1;
							_Context->value_WidgetTriggers &= 1;
							}
						continue;
					case	0x1e :
						/* Escape */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Escape += 1;
							_Context->value_Escape &= 1;
							}
						continue;
					case	0x1f :
						/* Enter */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Enter += 1;
							_Context->value_Enter &= 1;
							}
						continue;
					case	0x20 :
						/* PageUp */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_PageUp += 1;
							_Context->value_PageUp &= 1;
							}
						continue;
					case	0x21 :
						/* PageDown */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_PageDown += 1;
							_Context->value_PageDown &= 1;
							}
						continue;
					case	0x22 :
						/* UpArrow */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UpArrow += 1;
							_Context->value_UpArrow &= 1;
							}
						continue;
					case	0x23 :
						/* DownArrow */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_DownArrow += 1;
							_Context->value_DownArrow &= 1;
							}
						continue;
					case	0x24 :
						/* Tabulation */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Tabulation += 1;
							_Context->value_Tabulation &= 1;
							}
						continue;
					case	0x25 :
						/* DefaultBreak */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_DefaultBreak += 1;
							_Context->value_DefaultBreak &= 1;
							}
						continue;
					case	0x26 :
						/* FormMethods */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_form_control_losefocus(_Context);
							_Context->page_number = 3;
							accept_form_control_show(_Context);
							}
						continue;
					case	0x27 :
						/* Methods */
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_Methods_event(_Context)) != -1) break;

							}
						continue;
					case	0x28 :
						/* ScrollBar */
						(void) on_ScrollBar_action(_Context);
						continue;
					case	0x29 :
						/* FormMemberPage */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_form_control_losefocus(_Context);
							_Context->page_number = 4;
							accept_form_control_show(_Context);
							}
						continue;
					case	0x2a :
						/* FormMembers */
						continue;
					case	0x2b :
						/* MemberBar */
						(void) on_MemberBar_action(_Context);
						continue;
					case	0x2c :
						/* Auto1917 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_form_control_losefocus(_Context);
							_Context->page_number = 5;
							accept_form_control_show(_Context);
							}
						continue;
					case	0x2f :
						/* FileName */
						continue;
					case	0x30 :
						/* Auto1923 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1904+644,_Context->y_Auto1904+131,16,16,vfh[8],27,28,_Context->msg_Auto1923[_Context->language],strlen(_Context->msg_Auto1923[_Context->language]),786);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1904+644,_Context->y_Auto1904+131,16,16,vfh[8],27,28,_Context->msg_Auto1923[_Context->language],strlen(_Context->msg_Auto1923[_Context->language]),784);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1923_event(_Context)) != -1) break;

							}
						continue;
					case	0x31 :
						/* Auto1924 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1904+644,_Context->y_Auto1904+231,16,16,vfh[8],27,28,_Context->msg_Auto1924[_Context->language],strlen(_Context->msg_Auto1924[_Context->language]),786);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1904+644,_Context->y_Auto1904+231,16,16,vfh[8],27,28,_Context->msg_Auto1924[_Context->language],strlen(_Context->msg_Auto1924[_Context->language]),784);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1924_event(_Context)) != -1) break;

							}
						continue;
					case	0x32 :
						/* Identity */
						continue;
					case	0x33 :
						/* StyleSheet */
						continue;
					case	0x34 :
						/* ClearScreen */
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
				_Context->focus_item=52;
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
	char * pConstants,
	char * pMultipleLanguage,
	char * pProgram,
	char * pOverlay,
	char * pPopUp,
	char * pDynamic,
	char * pCommandLine,
	char * pArgVLen,
	char * pArgVNb,
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
	char * pDefaultBreak,
	char * pFileName,
	char * pIdentity,
	char * pStyleSheet,
	char * pClearScreen)
{
	int	status=0;
	struct accept_form_control_context * _Context=(struct accept_form_control_context*) 0;
	status = accept_form_control_create(
	&_Context,
	 pFormType,
	 pProductionLanguage,
	 pNationalLanguage,
	 pInternational,
	 pConstants,
	 pMultipleLanguage,
	 pProgram,
	 pOverlay,
	 pPopUp,
	 pDynamic,
	 pCommandLine,
	 pArgVLen,
	 pArgVNb,
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
	 pDefaultBreak,
	 pFileName,
	 pIdentity,
	 pStyleSheet,
	 pClearScreen);
	if ( status != 0) return(status);
	status = accept_form_control_show(_Context);
		enter_modal();
	status = accept_form_control_focus(_Context);
		leave_modal();
	status = accept_form_control_hide(_Context);
	status = accept_form_control_remove(
	_Context,
	 pFormType,
	 pProductionLanguage,
	 pNationalLanguage,
	 pInternational,
	 pConstants,
	 pMultipleLanguage,
	 pProgram,
	 pOverlay,
	 pPopUp,
	 pDynamic,
	 pCommandLine,
	 pArgVLen,
	 pArgVNb,
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
	 pDefaultBreak,
	 pFileName,
	 pIdentity,
	 pStyleSheet,
	 pClearScreen);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vform_c */
