
#ifndef _vwidget_c
#define _vwidget_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vwidget.xml                                              */
/* Target         : vwidget.c                                                */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singform.h"
#include "singprot.h"
#define en__WidgetProperties   ""
#define fr__WidgetProperties   ""
#define it__WidgetProperties   ""
#define es__WidgetProperties   ""
#define de__WidgetProperties   ""
#define nl__WidgetProperties   ""
#define pt__WidgetProperties   ""
#define xx__WidgetProperties   ""
#define en_Auto3610   "ok.gif"
#define fr_Auto3610   "ok.gif"
#define it_Auto3610   "ok.gif"
#define es_Auto3610   "ok.gif"
#define de_Auto3610   "ok.gif"
#define nl_Auto3610   "ok.gif"
#define pt_Auto3610   "ok.gif"
#define xx_Auto3610   "ok.gif"
#define en__Auto3610   ""
#define en_Auto3611   "screen.gif"
#define fr_Auto3611   "screen.gif"
#define it_Auto3611   "screen.gif"
#define es_Auto3611   "screen.gif"
#define de_Auto3611   "screen.gif"
#define nl_Auto3611   "screen.gif"
#define pt_Auto3611   "screen.gif"
#define xx_Auto3611   "screen.gif"
#define en__Auto3611   ""
#define fr__Auto3611   ""
#define it__Auto3611   ""
#define es__Auto3611   ""
#define de__Auto3611   ""
#define nl__Auto3611   ""
#define pt__Auto3611   ""
#define xx__Auto3611   ""
#define en_Toggle   "*"
#define en__Toggle   ""
#define en_Auto3612   "Full Screen Text Editor"
#define fr_Auto3612   "Editeur Plein Ecran"
#define it_Auto3612   "Full Screen Text Editor"
#define es_Auto3612   "Full Screen Text Editor"
#define de_Auto3612   "Full Screen Text Editor"
#define nl_Auto3612   "Full Screen Text Editor"
#define pt_Auto3612   "Full Screen Text Editor"
#define xx_Auto3612   "Full Screen Text Editor"
#define en__Auto3612   ""
#define fr__Auto3612   ""
#define it__Auto3612   ""
#define es__Auto3612   ""
#define de__Auto3612   ""
#define nl__Auto3612   ""
#define pt__Auto3612   ""
#define xx__Auto3612   ""
#define en_Auto3613   "National Language Messages Editor"
#define fr_Auto3613   "Editer Messages Multinationales"
#define it_Auto3613   "National Language Messages Editor"
#define es_Auto3613   "National Language Messages Editor"
#define de_Auto3613   "National Language Messages Editor"
#define nl_Auto3613   "National Language Messages Editor"
#define pt_Auto3613   "National Language Messages Editor"
#define xx_Auto3613   "National Language Messages Editor"
#define en__Auto3613   ""
#define fr__Auto3613   ""
#define it__Auto3613   ""
#define es__Auto3613   ""
#define de__Auto3613   ""
#define nl__Auto3613   ""
#define pt__Auto3613   ""
#define xx__Auto3613   ""
#define en_Auto3614   "National Language Help Editor"
#define fr_Auto3614   "Editer d'Aides Multinationales"
#define it_Auto3614   "National Language Help Editor"
#define es_Auto3614   "National Language Help Editor"
#define de_Auto3614   "National Language Help Editor"
#define nl_Auto3614   "National Language Help Editor"
#define pt_Auto3614   "National Language Help Editor"
#define xx_Auto3614   "National Language Help Editor"
#define en__Auto3614   ""
#define fr__Auto3614   ""
#define it__Auto3614   ""
#define es__Auto3614   ""
#define de__Auto3614   ""
#define nl__Auto3614   ""
#define pt__Auto3614   ""
#define xx__Auto3614   ""
#define en_NationalMessages   "natlang.gif"
#define fr_NationalMessages   "natlang.gif"
#define it_NationalMessages   "natlang.gif"
#define es_NationalMessages   "natlang.gif"
#define de_NationalMessages   "natlang.gif"
#define nl_NationalMessages   "natlang.gif"
#define pt_NationalMessages   "natlang.gif"
#define xx_NationalMessages   "natlang.gif"
#define en__NationalMessages   ""
#define fr__NationalMessages   ""
#define it__NationalMessages   ""
#define es__NationalMessages   ""
#define de__NationalMessages   ""
#define nl__NationalMessages   ""
#define pt__NationalMessages   ""
#define xx__NationalMessages   ""
#define en_NationalHelptext   "natlang.gif"
#define fr_NationalHelptext   "natlang.gif"
#define it_NationalHelptext   "natlang.gif"
#define es_NationalHelptext   "natlang.gif"
#define de_NationalHelptext   "natlang.gif"
#define nl_NationalHelptext   "natlang.gif"
#define pt_NationalHelptext   "natlang.gif"
#define xx_NationalHelptext   "natlang.gif"
#define en__NationalHelptext   ""
#define fr__NationalHelptext   ""
#define it__NationalHelptext   ""
#define es__NationalHelptext   ""
#define de__NationalHelptext   ""
#define nl__NationalHelptext   ""
#define pt__NationalHelptext   ""
#define xx__NationalHelptext   ""
#define en_Auto3615   "cancel.gif"
#define fr_Auto3615   "cancel.gif"
#define it_Auto3615   "cancel.gif"
#define es_Auto3615   "cancel.gif"
#define de_Auto3615   "cancel.gif"
#define nl_Auto3615   "cancel.gif"
#define pt_Auto3615   "cancel.gif"
#define xx_Auto3615   "cancel.gif"
#define en__Auto3615   ""
#define en_Auto3617   ""
#define fr_Auto3617   ""
#define it_Auto3617   ""
#define es_Auto3617   ""
#define de_Auto3617   ""
#define nl_Auto3617   ""
#define pt_Auto3617   ""
#define xx_Auto3617   ""
#define en__Auto3617   ""
#define en_Widget   "&Widget"
#define fr_Widget   "&Widget"
#define it_Widget   "&Widget"
#define es_Widget   "&Widget"
#define de_Widget   "&Widget"
#define nl_Widget   "&Widget"
#define pt_Widget   "&Widget"
#define xx_Widget   "&Widget"
#define en__Widget   ""
#define en_all_widget   "vwall"
#define fr_all_widget   "vwall"
#define it_all_widget   "vwall"
#define es_all_widget   "vwall"
#define de_all_widget   "vwall"
#define nl_all_widget   "vwall"
#define pt_all_widget   "vwall"
#define xx_all_widget   "vwall"
#define en__all_widget   ""
#define en_select_widget   "vwselect"
#define fr_select_widget   "vwselect"
#define it_select_widget   "vwselect"
#define es_select_widget   "vwselect"
#define de_select_widget   "vwselect"
#define nl_select_widget   "vwselect"
#define pt_select_widget   "vwselect"
#define xx_select_widget   "vwselect"
#define en__select_widget   ""
#define en_frame_widget   "vwframe"
#define fr_frame_widget   "vwselect"
#define it_frame_widget   "vwselect"
#define es_frame_widget   "vwselect"
#define de_frame_widget   "vwselect"
#define nl_frame_widget   "vwselect"
#define pt_frame_widget   "vwselect"
#define xx_frame_widget   "vwselect"
#define en__frame_widget   ""
#define en_edit_widget   "vwedit"
#define fr_edit_widget   "vwselect"
#define it_edit_widget   "vwselect"
#define es_edit_widget   "vwselect"
#define de_edit_widget   "vwselect"
#define nl_edit_widget   "vwselect"
#define pt_edit_widget   "vwselect"
#define xx_edit_widget   "vwselect"
#define en__edit_widget   ""
#define en_button_widget   "vwbutton"
#define fr_button_widget   "vwselect"
#define it_button_widget   "vwselect"
#define es_button_widget   "vwselect"
#define de_button_widget   "vwselect"
#define nl_button_widget   "vwselect"
#define pt_button_widget   "vwselect"
#define xx_button_widget   "vwselect"
#define en__button_widget   ""
#define en_check_widget   "vwcheck"
#define fr_check_widget   "vwselect"
#define it_check_widget   "vwselect"
#define es_check_widget   "vwselect"
#define de_check_widget   "vwselect"
#define nl_check_widget   "vwselect"
#define pt_check_widget   "vwselect"
#define xx_check_widget   "vwselect"
#define en__check_widget   ""
#define en_data_widget   "vwdata"
#define fr_data_widget   "vwselect"
#define it_data_widget   "vwselect"
#define es_data_widget   "vwselect"
#define de_data_widget   "vwselect"
#define nl_data_widget   "vwselect"
#define pt_data_widget   "vwselect"
#define xx_data_widget   "vwselect"
#define en__data_widget   ""
#define en_fill_widget   "vwfill"
#define fr_fill_widget   "vwselect"
#define it_fill_widget   "vwselect"
#define es_fill_widget   "vwselect"
#define de_fill_widget   "vwselect"
#define nl_fill_widget   "vwselect"
#define pt_fill_widget   "vwselect"
#define xx_fill_widget   "vwselect"
#define en__fill_widget   ""
#define en_form_widget   "vwform"
#define fr_form_widget   "vwselect"
#define it_form_widget   "vwselect"
#define es_form_widget   "vwselect"
#define de_form_widget   "vwselect"
#define nl_form_widget   "vwselect"
#define pt_form_widget   "vwselect"
#define xx_form_widget   "vwselect"
#define en__form_widget   ""
#define en_scroll_widget   "vwscroll"
#define fr_scroll_widget   "vwselect"
#define it_scroll_widget   "vwselect"
#define es_scroll_widget   "vwselect"
#define de_scroll_widget   "vwselect"
#define nl_scroll_widget   "vwselect"
#define pt_scroll_widget   "vwselect"
#define xx_scroll_widget   "vwselect"
#define en__scroll_widget   ""
#define en_progress_widget   "vwprogress"
#define fr_progress_widget   "vwselect"
#define it_progress_widget   "vwselect"
#define es_progress_widget   "vwselect"
#define de_progress_widget   "vwselect"
#define nl_progress_widget   "vwselect"
#define pt_progress_widget   "vwselect"
#define xx_progress_widget   "vwselect"
#define en__progress_widget   ""
#define en_tabpage_widget   "vwtabpage"
#define fr_tabpage_widget   "vwselect"
#define it_tabpage_widget   "vwselect"
#define es_tabpage_widget   "vwselect"
#define de_tabpage_widget   "vwselect"
#define nl_tabpage_widget   "vwselect"
#define pt_tabpage_widget   "vwselect"
#define xx_tabpage_widget   "vwselect"
#define en__tabpage_widget   ""
#define en_radio_widget   "vwradio"
#define fr_radio_widget   "vwselect"
#define it_radio_widget   "vwselect"
#define es_radio_widget   "vwselect"
#define de_radio_widget   "vwselect"
#define nl_radio_widget   "vwselect"
#define pt_radio_widget   "vwselect"
#define xx_radio_widget   "vwselect"
#define en__radio_widget   ""
#define en_window_widget   "vwwindow"
#define fr_window_widget   "vwselect"
#define it_window_widget   "vwselect"
#define es_window_widget   "vwselect"
#define de_window_widget   "vwselect"
#define nl_window_widget   "vwselect"
#define pt_window_widget   "vwselect"
#define xx_window_widget   "vwselect"
#define en__window_widget   ""
#define en_text_widget   "vwtext"
#define fr_text_widget   "vwselect"
#define it_text_widget   "vwselect"
#define es_text_widget   "vwselect"
#define de_text_widget   "vwselect"
#define nl_text_widget   "vwselect"
#define pt_text_widget   "vwselect"
#define xx_text_widget   "vwselect"
#define en__text_widget   ""
#define en_image_widget   "vwimage"
#define fr_image_widget   "vwselect"
#define it_image_widget   "vwselect"
#define es_image_widget   "vwselect"
#define de_image_widget   "vwselect"
#define nl_image_widget   "vwselect"
#define pt_image_widget   "vwselect"
#define xx_image_widget   "vwselect"
#define en__image_widget   ""
#define en_line_widget   "vwline"
#define fr_line_widget   "vwselect"
#define it_line_widget   "vwselect"
#define es_line_widget   "vwselect"
#define de_line_widget   "vwselect"
#define nl_line_widget   "vwselect"
#define pt_line_widget   "vwselect"
#define xx_line_widget   "vwselect"
#define en__line_widget   ""
#define en_switch_widget   "vwswitch"
#define fr_switch_widget   "vwselect"
#define it_switch_widget   "vwselect"
#define es_switch_widget   "vwselect"
#define de_switch_widget   "vwselect"
#define nl_switch_widget   "vwselect"
#define pt_switch_widget   "vwselect"
#define xx_switch_widget   "vwselect"
#define en__switch_widget   ""
#define en_graph_widget   "vwgraph"
#define fr_graph_widget   "vwselect"
#define it_graph_widget   "vwselect"
#define es_graph_widget   "vwselect"
#define de_graph_widget   "vwselect"
#define nl_graph_widget   "vwselect"
#define pt_graph_widget   "vwselect"
#define xx_graph_widget   "vwselect"
#define en__graph_widget   ""
#define en_OnCreate   "C&reate"
#define fr_OnCreate   "C&reate"
#define it_OnCreate   "C&reate"
#define es_OnCreate   "C&reate"
#define de_OnCreate   "C&reate"
#define nl_OnCreate   "C&reate"
#define pt_OnCreate   "C&reate"
#define xx_OnCreate   "C&reate"
#define en__OnCreate   ""
#define en_Permission   "Private|Public"
#define fr_Permission   "Priv‚|Publique"
#define it_Permission   "Private|Public"
#define es_Permission   "Private|Public"
#define de_Permission   "Private|Public"
#define nl_Permission   "Private|Public"
#define pt_Permission   "Private|Public"
#define xx_Permission   "Private|Public"
#define en__Permission   ""
#define fr__Permission   ""
#define it__Permission   ""
#define es__Permission   ""
#define de__Permission   ""
#define nl__Permission   ""
#define pt__Permission   ""
#define xx__Permission   ""
#define en_IsExtern   " |Extern"
#define fr_IsExtern   "Priv‚|Publique"
#define it_IsExtern   "Private|Public"
#define es_IsExtern   "Private|Public"
#define de_IsExtern   "Private|Public"
#define nl_IsExtern   "Private|Public"
#define pt_IsExtern   "Private|Public"
#define xx_IsExtern   "Private|Public"
#define en__IsExtern   ""
#define fr__IsExtern   ""
#define it__IsExtern   ""
#define es__IsExtern   ""
#define de__IsExtern   ""
#define nl__IsExtern   ""
#define pt__IsExtern   ""
#define xx__IsExtern   ""
#define en__CreateOptions   ""
#define en_Create   ""
#define fr_Create   ""
#define it_Create   ""
#define es_Create   ""
#define de_Create   ""
#define nl_Create   ""
#define pt_Create   ""
#define xx_Create   ""
#define en_OnShowPage   "&Show"
#define fr_OnShowPage   "&Show"
#define it_OnShowPage   "&Show"
#define es_OnShowPage   "&Show"
#define de_OnShowPage   "&Show"
#define nl_OnShowPage   "&Show"
#define pt_OnShowPage   "&Show"
#define xx_OnShowPage   "&Show"
#define en__ShowOptions   ""
#define en_Show   ""
#define fr_Show   ""
#define it_Show   ""
#define es_Show   ""
#define de_Show   ""
#define nl_Show   ""
#define pt_Show   ""
#define xx_Show   ""
#define en_OnGetFocus   "&GetFocus"
#define fr_OnGetFocus   "&GetFocus"
#define it_OnGetFocus   "&GetFocus"
#define es_OnGetFocus   "&GetFocus"
#define de_OnGetFocus   "&GetFocus"
#define nl_OnGetFocus   "&GetFocus"
#define pt_OnGetFocus   "&GetFocus"
#define xx_OnGetFocus   "&GetFocus"
#define en__FocusOptions   ""
#define en_GetFocus   ""
#define fr_GetFocus   ""
#define it_GetFocus   ""
#define es_GetFocus   ""
#define de_GetFocus   ""
#define nl_GetFocus   ""
#define pt_GetFocus   ""
#define xx_GetFocus   ""
#define en_OnEvent   "&Event"
#define fr_OnEvent   "&Event"
#define it_OnEvent   "&Event"
#define es_OnEvent   "&Event"
#define de_OnEvent   "&Event"
#define nl_OnEvent   "&Event"
#define pt_OnEvent   "&Event"
#define xx_OnEvent   "&Event"
#define en__OnEvent   ""
#define en_Auto3618   "Invoke On Mouse ..."
#define fr_Auto3618   "Activer sur ‚v‚nement .."
#define it_Auto3618   "Invoke Method On Mouse ..."
#define es_Auto3618   "Invoke Method On Mouse ..."
#define de_Auto3618   "Invoke Method On Mouse ..."
#define nl_Auto3618   "Invoke Method On Mouse ..."
#define pt_Auto3618   "Invoke Method On Mouse ..."
#define xx_Auto3618   "D‚anamh nur luchaig"
#define en__Auto3618   ""
#define en_MimoMove   "MOVE"
#define fr_MimoMove   "MOVE"
#define it_MimoMove   "MOVE"
#define es_MimoMove   "MOVE"
#define de_MimoMove   "MOVE"
#define nl_MimoMove   "MOVE"
#define pt_MimoMove   "MOVE"
#define xx_MimoMove   "MOVE"
#define en_MimoDown   "DOWN"
#define fr_MimoDown   "DOWN"
#define it_MimoDown   "DOWN"
#define es_MimoDown   "DOWN"
#define de_MimoDown   "DOWN"
#define nl_MimoDown   "DOWN"
#define pt_MimoDown   "DOWN"
#define xx_MimoDown   "DOWN"
#define en_MimoUp   "UP"
#define fr_MimoUp   "UP"
#define it_MimoUp   "UP"
#define es_MimoUp   "UP"
#define de_MimoUp   "UP"
#define nl_MimoUp   "UP"
#define pt_MimoUp   "UP"
#define xx_MimoUp   "UP"
#define en_MimoHold   "HOLD"
#define fr_MimoHold   "HOLD"
#define it_MimoHold   "HOLD"
#define es_MimoHold   "HOLD"
#define de_MimoHold   "HOLD"
#define nl_MimoHold   "HOLD"
#define pt_MimoHold   "HOLD"
#define xx_MimoHold   "HOLD"
#define en_MimoLeft   "L"
#define fr_MimoLeft   "G"
#define it_MimoLeft   "L"
#define es_MimoLeft   "L"
#define de_MimoLeft   "L"
#define nl_MimoLeft   "L"
#define pt_MimoLeft   "L"
#define xx_MimoLeft   "L"
#define en__MimoLeft   ""
#define fr__MimoLeft   ""
#define it__MimoLeft   ""
#define es__MimoLeft   ""
#define de__MimoLeft   ""
#define nl__MimoLeft   ""
#define pt__MimoLeft   ""
#define xx__MimoLeft   ""
#define en_Auto3619   "Event Types"
#define en__Auto3619   ""
#define en_Auto3620   "Buttons"
#define en__Auto3620   ""
#define en_MimoRight   "R"
#define fr_MimoRight   "D"
#define it_MimoRight   "R"
#define es_MimoRight   "R"
#define de_MimoRight   "R"
#define nl_MimoRight   "R"
#define pt_MimoRight   "R"
#define xx_MimoRight   "R"
#define en__MimoRight   ""
#define fr__MimoRight   ""
#define it__MimoRight   ""
#define es__MimoRight   ""
#define de__MimoRight   ""
#define nl__MimoRight   ""
#define pt__MimoRight   ""
#define xx__MimoRight   ""
#define en_MimoWheel   "W"
#define fr_MimoWheel   "R"
#define it_MimoWheel   "W"
#define es_MimoWheel   "W"
#define de_MimoWheel   "W"
#define nl_MimoWheel   "W"
#define pt_MimoWheel   "W"
#define xx_MimoWheel   "W"
#define en__MimoWheel   ""
#define fr__MimoWheel   ""
#define it__MimoWheel   ""
#define es__MimoWheel   ""
#define de__MimoWheel   ""
#define nl__MimoWheel   ""
#define pt__MimoWheel   ""
#define xx__MimoWheel   ""
#define en_MimoMiddle   "M"
#define fr_MimoMiddle   "M"
#define it_MimoMiddle   "M"
#define es_MimoMiddle   "M"
#define de_MimoMiddle   "M"
#define nl_MimoMiddle   "M"
#define pt_MimoMiddle   "M"
#define xx_MimoMiddle   "M"
#define en__MimoMiddle   ""
#define fr__MimoMiddle   ""
#define it__MimoMiddle   ""
#define es__MimoMiddle   ""
#define de__MimoMiddle   ""
#define nl__MimoMiddle   ""
#define pt__MimoMiddle   ""
#define xx__MimoMiddle   ""
#define en__EventOptions   ""
#define en_Event   ""
#define fr_Event   ""
#define it_Event   ""
#define es_Event   ""
#define de_Event   ""
#define nl_Event   ""
#define pt_Event   ""
#define xx_Event   ""
#define en_OnLoseFocus   "&LoseFocus"
#define fr_OnLoseFocus   "&LoseFocus"
#define it_OnLoseFocus   "&LoseFocus"
#define es_OnLoseFocus   "&LoseFocus"
#define de_OnLoseFocus   "&LoseFocus"
#define nl_OnLoseFocus   "&LoseFocus"
#define pt_OnLoseFocus   "&LoseFocus"
#define xx_OnLoseFocus   "&LoseFocus"
#define en__OnLoseFocus   ""
#define en__LoseOptions   ""
#define en_LoseFocus   ""
#define fr_LoseFocus   ""
#define it_LoseFocus   ""
#define es_LoseFocus   ""
#define de_LoseFocus   ""
#define nl_LoseFocus   ""
#define pt_LoseFocus   ""
#define xx_LoseFocus   ""
#define en_OnHidePage   "&Hide"
#define fr_OnHidePage   "&Hide"
#define it_OnHidePage   "&Hide"
#define es_OnHidePage   "&Hide"
#define de_OnHidePage   "&Hide"
#define nl_OnHidePage   "&Hide"
#define pt_OnHidePage   "&Hide"
#define xx_OnHidePage   "&Hide"
#define en__OnHidePage   ""
#define en__HideOptions   ""
#define en_Hide   ""
#define fr_Hide   ""
#define it_Hide   ""
#define es_Hide   ""
#define de_Hide   ""
#define nl_Hide   ""
#define pt_Hide   ""
#define xx_Hide   ""
#define en_OnRemove   "Re&move"
#define fr_OnRemove   "Re&move"
#define it_OnRemove   "Re&move"
#define es_OnRemove   "Re&move"
#define de_OnRemove   "Re&move"
#define nl_OnRemove   "Re&move"
#define pt_OnRemove   "Re&move"
#define xx_OnRemove   "Re&move"
#define en__OnRemove   ""
#define en__RemoveOptions   ""
#define en_Remove   ""
#define fr_Remove   ""
#define it_Remove   ""
#define es_Remove   ""
#define de_Remove   ""
#define nl_Remove   ""
#define pt_Remove   ""
#define xx_Remove   ""
#include "vwall.h"
#include "vwselect.h"
#include "vwframe.h"
#include "vwedit.h"
#include "vwbutton.h"
#include "vwcheck.h"
#include "vwdata.h"
#include "vwfill.h"
#include "vwform.h"
#include "vwscroll.h"
#include "vwprogress.h"
#include "vwtabpage.h"
#include "vwradio.h"
#include "vwwindow.h"
#include "vwtext.h"
#include "vwimage.h"
#include "vwline.h"
#include "vwswitch.h"
#include "vwgraph.h"

private struct accept_widget_properties_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[8+1];
	char * msg_WidgetProperties[8];
	char * hint_WidgetProperties[8];
	int	x_WidgetProperties;
	int	y_WidgetProperties;
	int	w_WidgetProperties;
	int	h_WidgetProperties;
	char * msg_Auto3610[8];
	int	trigger_Auto3610;
	char * hint_Auto3610[8];
	char * msg_Auto3611[8];
	int	trigger_Auto3611;
	char * hint_Auto3611[8];
	char * msg_Toggle[8];
	int	trigger_Toggle;
	char * hint_Toggle[8];
	int	value_Toggle;
	char * msg_Auto3612[8];
	char * hint_Auto3612[8];
	char * msg_Auto3613[8];
	char * hint_Auto3613[8];
	char * msg_Auto3614[8];
	char * hint_Auto3614[8];
	char * msg_NationalMessages[8];
	int	trigger_NationalMessages;
	char * hint_NationalMessages[8];
	char * msg_NationalHelptext[8];
	int	trigger_NationalHelptext;
	char * hint_NationalHelptext[8];
	char * msg_Auto3615[8];
	int	trigger_Auto3615;
	char * hint_Auto3615[8];
	char * hint_Auto3616[8];
	char * hint_Auto3617[8];
	char * msg_Widget[8];
	int	trigger_Widget;
	char * hint_Widget[8];
	int	page_number;
	char * msg_all_widget[8];
	char * hint_all_widget[8];
	struct vwall_context * all_widget;
	char * msg_select_widget[8];
	char * hint_select_widget[8];
	struct vwselect_context * select_widget;
	char * msg_frame_widget[8];
	char * hint_frame_widget[8];
	struct vwframe_context * frame_widget;
	char * msg_edit_widget[8];
	char * hint_edit_widget[8];
	struct vwedit_context * edit_widget;
	char * msg_button_widget[8];
	char * hint_button_widget[8];
	struct vwbutton_context * button_widget;
	char * msg_check_widget[8];
	char * hint_check_widget[8];
	struct vwcheck_context * check_widget;
	char * msg_data_widget[8];
	char * hint_data_widget[8];
	struct vwdata_context * data_widget;
	char * msg_fill_widget[8];
	char * hint_fill_widget[8];
	struct vwfill_context * fill_widget;
	char * msg_form_widget[8];
	char * hint_form_widget[8];
	struct vwform_context * form_widget;
	char * msg_scroll_widget[8];
	char * hint_scroll_widget[8];
	struct vwscroll_context * scroll_widget;
	char * msg_progress_widget[8];
	char * hint_progress_widget[8];
	struct vwprogress_context * progress_widget;
	char * msg_tabpage_widget[8];
	char * hint_tabpage_widget[8];
	struct vwtabpage_context * tabpage_widget;
	char * msg_radio_widget[8];
	char * hint_radio_widget[8];
	struct vwradio_context * radio_widget;
	char * msg_window_widget[8];
	char * hint_window_widget[8];
	struct vwwindow_context * window_widget;
	char * msg_text_widget[8];
	char * hint_text_widget[8];
	struct vwtext_context * text_widget;
	char * msg_image_widget[8];
	char * hint_image_widget[8];
	struct vwimage_context * image_widget;
	char * msg_line_widget[8];
	char * hint_line_widget[8];
	struct vwline_context * line_widget;
	char * msg_switch_widget[8];
	char * hint_switch_widget[8];
	struct vwswitch_context * switch_widget;
	char * msg_graph_widget[8];
	char * hint_graph_widget[8];
	struct vwgraph_context * graph_widget;
	char * msg_OnCreate[8];
	int	trigger_OnCreate;
	char * hint_OnCreate[8];
	char * msg_Permission[8];
	int	trigger_Permission;
	char * hint_Permission[8];
	int	value_Permission;
	char * msg_IsExtern[8];
	int	trigger_IsExtern;
	char * hint_IsExtern[8];
	int	value_IsExtern;
	char * msg_CreateOptions[8];
	char * hint_CreateOptions[8];
	int	value_CreateOptions;
	char * hint_Create[8];
	char * buffer_Create;
	char * msg_OnShowPage[8];
	int	trigger_OnShowPage;
	char * hint_OnShowPage[8];
	char * msg_ShowOptions[8];
	char * hint_ShowOptions[8];
	int	value_ShowOptions;
	char * hint_Show[8];
	char * buffer_Show;
	char * msg_OnGetFocus[8];
	int	trigger_OnGetFocus;
	char * hint_OnGetFocus[8];
	char * msg_FocusOptions[8];
	char * hint_FocusOptions[8];
	int	value_FocusOptions;
	char * hint_GetFocus[8];
	char * buffer_GetFocus;
	char * msg_OnEvent[8];
	int	trigger_OnEvent;
	char * hint_OnEvent[8];
	char * msg_Auto3618[8];
	char * hint_Auto3618[8];
	char * msg_MimoMove[8];
	int	trigger_MimoMove;
	char * hint_MimoMove[8];
	int	value_MimoMove;
	char * msg_MimoDown[8];
	int	trigger_MimoDown;
	char * hint_MimoDown[8];
	int	value_MimoDown;
	char * msg_MimoUp[8];
	int	trigger_MimoUp;
	char * hint_MimoUp[8];
	int	value_MimoUp;
	char * msg_MimoHold[8];
	int	trigger_MimoHold;
	char * hint_MimoHold[8];
	int	value_MimoHold;
	char * msg_MimoLeft[8];
	int	trigger_MimoLeft;
	char * hint_MimoLeft[8];
	int	value_MimoLeft;
	char * msg_Auto3619[8];
	char * hint_Auto3619[8];
	char * msg_Auto3620[8];
	char * hint_Auto3620[8];
	char * msg_MimoRight[8];
	int	trigger_MimoRight;
	char * hint_MimoRight[8];
	int	value_MimoRight;
	char * msg_MimoWheel[8];
	int	trigger_MimoWheel;
	char * hint_MimoWheel[8];
	int	value_MimoWheel;
	char * msg_MimoMiddle[8];
	int	trigger_MimoMiddle;
	char * hint_MimoMiddle[8];
	int	value_MimoMiddle;
	char * msg_EventOptions[8];
	char * hint_EventOptions[8];
	int	value_EventOptions;
	char * hint_Event[8];
	char * buffer_Event;
	char * msg_OnLoseFocus[8];
	int	trigger_OnLoseFocus;
	char * hint_OnLoseFocus[8];
	char * msg_LoseOptions[8];
	char * hint_LoseOptions[8];
	int	value_LoseOptions;
	char * hint_LoseFocus[8];
	char * buffer_LoseFocus;
	char * msg_OnHidePage[8];
	int	trigger_OnHidePage;
	char * hint_OnHidePage[8];
	char * msg_HideOptions[8];
	char * hint_HideOptions[8];
	int	value_HideOptions;
	char * hint_Hide[8];
	char * buffer_Hide;
	char * msg_OnRemove[8];
	int	trigger_OnRemove;
	char * hint_OnRemove[8];
	char * msg_RemoveOptions[8];
	char * hint_RemoveOptions[8];
	int	value_RemoveOptions;
	char * hint_Remove[8];
	char * buffer_Remove;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[25];
	};
static int	vfh[16];
private int on_WidgetProperties_create(struct accept_widget_properties_context * _Context);
private int on_OnCreate_create(struct accept_widget_properties_context * _Context);
private int on_Toggle_show(struct accept_widget_properties_context * _Context);
private int on_Widget_show(struct accept_widget_properties_context * _Context);
private int on_OnCreate_show(struct accept_widget_properties_context * _Context);
private int on_Create_show(struct accept_widget_properties_context * _Context);
private int on_OnShowPage_show(struct accept_widget_properties_context * _Context);
private int on_Show_show(struct accept_widget_properties_context * _Context);
private int on_OnGetFocus_show(struct accept_widget_properties_context * _Context);
private int on_GetFocus_show(struct accept_widget_properties_context * _Context);
private int on_OnEvent_show(struct accept_widget_properties_context * _Context);
private int on_Event_show(struct accept_widget_properties_context * _Context);
private int on_OnLoseFocus_show(struct accept_widget_properties_context * _Context);
private int on_LoseFocus_show(struct accept_widget_properties_context * _Context);
private int on_OnHidePage_show(struct accept_widget_properties_context * _Context);
private int on_Hide_show(struct accept_widget_properties_context * _Context);
private int on_OnRemove_show(struct accept_widget_properties_context * _Context);
private int on_Remove_show(struct accept_widget_properties_context * _Context);
private int on_Widget_getfocus(struct accept_widget_properties_context * _Context);
private int on_Create_getfocus(struct accept_widget_properties_context * _Context);
private int on_Show_getfocus(struct accept_widget_properties_context * _Context);
private int on_GetFocus_getfocus(struct accept_widget_properties_context * _Context);
private int on_Event_getfocus(struct accept_widget_properties_context * _Context);
private int on_LoseFocus_getfocus(struct accept_widget_properties_context * _Context);
private int on_Hide_getfocus(struct accept_widget_properties_context * _Context);
private int on_Remove_getfocus(struct accept_widget_properties_context * _Context);
private int on_Auto3610_event(struct accept_widget_properties_context * _Context);
private int on_Auto3611_event(struct accept_widget_properties_context * _Context);
private int on_Toggle_event(struct accept_widget_properties_context * _Context);
private int on_NationalMessages_event(struct accept_widget_properties_context * _Context);
private int on_NationalHelptext_event(struct accept_widget_properties_context * _Context);
private int on_Auto3615_event(struct accept_widget_properties_context * _Context);
private int on_WidgetProperties_hide(struct accept_widget_properties_context * _Context);
private int on_OnCreate_remove(struct accept_widget_properties_context * _Context);
void	WidgetGetFields(struct accept_widget_properties_context * _Context);
void	WidgetPutFields(struct accept_widget_properties_context * _Context);

/*	--------------------------------	*/
/*	W i d g e t G e t F i e l d s ()	*/
/*	--------------------------------	*/
void	WidgetGetFields(struct accept_widget_properties_context * _Context){
	on_OnCreate_remove(_Context);

}

/*	--------------------------------	*/
/*	W i d g e t P u t F i e l d s ()	*/
/*	--------------------------------	*/
void	WidgetPutFields(struct accept_widget_properties_context * _Context){
	on_OnCreate_create(_Context);

}
private int on_WidgetProperties_create(struct accept_widget_properties_context * _Context) {
	extern int vfh1;
	extern struct accept_widget_properties_context*widget_properties_context;
	_Context->focus_item=8;/*Demarrer sur fenetre Widget*/
	widget_properties_context=_Context;/*pour aide en ligne*/
	vfh1=vfh[1];/*pour aide en ligne*/
	return(-1);
}
private int on_OnCreate_create(struct accept_widget_properties_context * _Context) {
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	if(use_all_widget()){
	vwall_SetVars(_Context->all_widget);
	}
	else{
	switch(*((int*)pSpecificWidgetProperties->pWidgetClass)){
	case _FILL_FRAME:
	vwfill_SetVars(_Context->fill_widget);
	break;
	case _OUTSET_FRAME:
	case _INSET_FRAME:
	case _RIDGE_FRAME:
	case _GROOVE_FRAME:
	vwframe_SetVars(_Context->frame_widget);
	break;
	case _EDIT_FRAME:
	vwedit_SetVars(_Context->edit_widget);
	break;
	case _TEXT_FRAME:
	vwtext_SetVars(_Context->text_widget);
	break;
	case _IMAGE_FRAME:
	vwimage_SetVars(_Context->image_widget);
	break;
	case _LINE_FRAME:
	vwline_SetVars(_Context->line_widget);
	break;
	case _BUTTON_FRAME:
	vwbutton_SetVars(_Context->button_widget);
	break;
	case _WINDOW_FRAME:
	vwwindow_SetVars(_Context->window_widget);
	break;
	case _TAB_FRAME:
	vwtabpage_SetVars(_Context->tabpage_widget);
	break;
	case _CHECK_FRAME:
	vwcheck_SetVars(_Context->check_widget);
	break;
	case _RADIO_FRAME:
	vwradio_SetVars(_Context->radio_widget);
	break;
	case _SELECT_FRAME:
	vwselect_SetVars(_Context->select_widget);
	break;
	case _FORM_FRAME:
	vwform_SetVars(_Context->form_widget);
	break;
	case _SCROLL_FRAME:
	vwscroll_SetVars(_Context->scroll_widget);
	break;
	case _PROGRESS_FRAME:
	vwprogress_SetVars(_Context->progress_widget);
	break;
	case _SWITCH_FRAME:
	vwswitch_SetVars(_Context->switch_widget);
	break;
	case _GRAPH_FRAME:
	vwgraph_SetVars(_Context->graph_widget);
	break;
	case _DATA_FRAME:
	vwdata_SetVars(_Context->data_widget);
	break;
	case _CUT_FRAME:
	default:
	vwall_SetVars(_Context->all_widget);
	break;
	}
	}
	return(-1);
}

public	int	accept_widget_properties_create(
	struct accept_widget_properties_context ** cptr,
	char * pPermission,
	char * pIsExtern,
	char * pCreateOptions,
	char * pCreate,
	char * pShowOptions,
	char * pShow,
	char * pFocusOptions,
	char * pGetFocus,
	char * pMimoMove,
	char * pMimoDown,
	char * pMimoUp,
	char * pMimoHold,
	char * pMimoLeft,
	char * pMimoRight,
	char * pMimoWheel,
	char * pMimoMiddle,
	char * pEventOptions,
	char * pEvent,
	char * pLoseOptions,
	char * pLoseFocus,
	char * pHideOptions,
	char * pHide,
	char * pRemoveOptions,
	char * pRemove)
{

	int i;
	struct accept_widget_properties_context * _Context=(struct accept_widget_properties_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_widget_properties_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=39;
	_Context->page_number=1;
		_Context->value_Toggle=0;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWTWTWTWWWWWWWWWTWTWTWT");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pPermission);
		if (!( pPermission )) _Context->value_Permission=0;
		else	_Context->value_Permission = *((int *)pPermission);
		visual_transferin((void *) 0, 0, pIsExtern);
		if (!( pIsExtern )) _Context->value_IsExtern=0;
		else	_Context->value_IsExtern = *((int *)pIsExtern);
		visual_transferin((void *) 0, 0, pCreateOptions);
		if (!( pCreateOptions )) _Context->value_CreateOptions=0;
		else	_Context->value_CreateOptions = *((int *)pCreateOptions);
				_Context->buffer_Create=(char *) 0;
		visual_transferin(&_Context->buffer_Create, 1782, pCreate);
		visual_transferin((void *) 0, 0, pShowOptions);
		if (!( pShowOptions )) _Context->value_ShowOptions=0;
		else	_Context->value_ShowOptions = *((int *)pShowOptions);
				_Context->buffer_Show=(char *) 0;
		visual_transferin(&_Context->buffer_Show, 1782, pShow);
		visual_transferin((void *) 0, 0, pFocusOptions);
		if (!( pFocusOptions )) _Context->value_FocusOptions=0;
		else	_Context->value_FocusOptions = *((int *)pFocusOptions);
				_Context->buffer_GetFocus=(char *) 0;
		visual_transferin(&_Context->buffer_GetFocus, 1782, pGetFocus);
		visual_transferin((void *) 0, 0, pMimoMove);
		if (!( pMimoMove )) _Context->value_MimoMove=0;
		else	_Context->value_MimoMove = *((int *)pMimoMove);
		visual_transferin((void *) 0, 0, pMimoDown);
		if (!( pMimoDown )) _Context->value_MimoDown=0;
		else	_Context->value_MimoDown = *((int *)pMimoDown);
		visual_transferin((void *) 0, 0, pMimoUp);
		if (!( pMimoUp )) _Context->value_MimoUp=0;
		else	_Context->value_MimoUp = *((int *)pMimoUp);
		visual_transferin((void *) 0, 0, pMimoHold);
		if (!( pMimoHold )) _Context->value_MimoHold=0;
		else	_Context->value_MimoHold = *((int *)pMimoHold);
		visual_transferin((void *) 0, 0, pMimoLeft);
		if (!( pMimoLeft )) _Context->value_MimoLeft=0;
		else	_Context->value_MimoLeft = *((int *)pMimoLeft);
		visual_transferin((void *) 0, 0, pMimoRight);
		if (!( pMimoRight )) _Context->value_MimoRight=0;
		else	_Context->value_MimoRight = *((int *)pMimoRight);
		visual_transferin((void *) 0, 0, pMimoWheel);
		if (!( pMimoWheel )) _Context->value_MimoWheel=0;
		else	_Context->value_MimoWheel = *((int *)pMimoWheel);
		visual_transferin((void *) 0, 0, pMimoMiddle);
		if (!( pMimoMiddle )) _Context->value_MimoMiddle=0;
		else	_Context->value_MimoMiddle = *((int *)pMimoMiddle);
		visual_transferin((void *) 0, 0, pEventOptions);
		if (!( pEventOptions )) _Context->value_EventOptions=0;
		else	_Context->value_EventOptions = *((int *)pEventOptions);
				_Context->buffer_Event=(char *) 0;
		visual_transferin(&_Context->buffer_Event, 1782, pEvent);
		visual_transferin((void *) 0, 0, pLoseOptions);
		if (!( pLoseOptions )) _Context->value_LoseOptions=0;
		else	_Context->value_LoseOptions = *((int *)pLoseOptions);
				_Context->buffer_LoseFocus=(char *) 0;
		visual_transferin(&_Context->buffer_LoseFocus, 1782, pLoseFocus);
		visual_transferin((void *) 0, 0, pHideOptions);
		if (!( pHideOptions )) _Context->value_HideOptions=0;
		else	_Context->value_HideOptions = *((int *)pHideOptions);
				_Context->buffer_Hide=(char *) 0;
		visual_transferin(&_Context->buffer_Hide, 1782, pHide);
		visual_transferin((void *) 0, 0, pRemoveOptions);
		if (!( pRemoveOptions )) _Context->value_RemoveOptions=0;
		else	_Context->value_RemoveOptions = *((int *)pRemoveOptions);
				_Context->buffer_Remove=(char *) 0;
		visual_transferin(&_Context->buffer_Remove, 1782, pRemove);
		}
	for (i=0; i < 8; i++)_Context->msg_WidgetProperties[i]=" ";
	_Context->hint_WidgetProperties[0]=en__WidgetProperties;
	_Context->hint_WidgetProperties[1]=fr__WidgetProperties;
	_Context->hint_WidgetProperties[2]=it__WidgetProperties;
	_Context->hint_WidgetProperties[3]=es__WidgetProperties;
	_Context->hint_WidgetProperties[4]=de__WidgetProperties;
	_Context->hint_WidgetProperties[5]=nl__WidgetProperties;
	_Context->hint_WidgetProperties[6]=pt__WidgetProperties;
	_Context->hint_WidgetProperties[7]=xx__WidgetProperties;
	_Context->x_WidgetProperties=45;
	_Context->y_WidgetProperties=30;
	_Context->w_WidgetProperties=710;
	_Context->h_WidgetProperties=540;
	_Context->window_col=0;
	_Context->window_row=0;
	(void) on_WidgetProperties_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto3610[i]=" ";
	_Context->msg_Auto3610[0]=en_Auto3610;
	_Context->msg_Auto3610[1]=fr_Auto3610;
	_Context->msg_Auto3610[2]=it_Auto3610;
	_Context->msg_Auto3610[3]=es_Auto3610;
	_Context->msg_Auto3610[4]=de_Auto3610;
	_Context->msg_Auto3610[5]=nl_Auto3610;
	_Context->msg_Auto3610[6]=pt_Auto3610;
	_Context->msg_Auto3610[7]=xx_Auto3610;
	_Context->hint_Auto3610[0]=en__Auto3610;
	for (i=0; i < 8; i++)_Context->msg_Auto3611[i]=" ";
	_Context->msg_Auto3611[0]=en_Auto3611;
	_Context->msg_Auto3611[1]=fr_Auto3611;
	_Context->msg_Auto3611[2]=it_Auto3611;
	_Context->msg_Auto3611[3]=es_Auto3611;
	_Context->msg_Auto3611[4]=de_Auto3611;
	_Context->msg_Auto3611[5]=nl_Auto3611;
	_Context->msg_Auto3611[6]=pt_Auto3611;
	_Context->msg_Auto3611[7]=xx_Auto3611;
	_Context->hint_Auto3611[0]=en__Auto3611;
	_Context->hint_Auto3611[1]=fr__Auto3611;
	_Context->hint_Auto3611[2]=it__Auto3611;
	_Context->hint_Auto3611[3]=es__Auto3611;
	_Context->hint_Auto3611[4]=de__Auto3611;
	_Context->hint_Auto3611[5]=nl__Auto3611;
	_Context->hint_Auto3611[6]=pt__Auto3611;
	_Context->hint_Auto3611[7]=xx__Auto3611;
	for (i=0; i < 8; i++)_Context->msg_Toggle[i]=" ";
	_Context->msg_Toggle[0]=en_Toggle;
	_Context->hint_Toggle[0]=en__Toggle;
	for (i=0; i < 8; i++)_Context->msg_Auto3612[i]=" ";
	_Context->msg_Auto3612[0]=en_Auto3612;
	_Context->msg_Auto3612[1]=fr_Auto3612;
	_Context->msg_Auto3612[2]=it_Auto3612;
	_Context->msg_Auto3612[3]=es_Auto3612;
	_Context->msg_Auto3612[4]=de_Auto3612;
	_Context->msg_Auto3612[5]=nl_Auto3612;
	_Context->msg_Auto3612[6]=pt_Auto3612;
	_Context->msg_Auto3612[7]=xx_Auto3612;
	_Context->hint_Auto3612[0]=en__Auto3612;
	_Context->hint_Auto3612[1]=fr__Auto3612;
	_Context->hint_Auto3612[2]=it__Auto3612;
	_Context->hint_Auto3612[3]=es__Auto3612;
	_Context->hint_Auto3612[4]=de__Auto3612;
	_Context->hint_Auto3612[5]=nl__Auto3612;
	_Context->hint_Auto3612[6]=pt__Auto3612;
	_Context->hint_Auto3612[7]=xx__Auto3612;
	for (i=0; i < 8; i++)_Context->msg_Auto3613[i]=" ";
	_Context->msg_Auto3613[0]=en_Auto3613;
	_Context->msg_Auto3613[1]=fr_Auto3613;
	_Context->msg_Auto3613[2]=it_Auto3613;
	_Context->msg_Auto3613[3]=es_Auto3613;
	_Context->msg_Auto3613[4]=de_Auto3613;
	_Context->msg_Auto3613[5]=nl_Auto3613;
	_Context->msg_Auto3613[6]=pt_Auto3613;
	_Context->msg_Auto3613[7]=xx_Auto3613;
	_Context->hint_Auto3613[0]=en__Auto3613;
	_Context->hint_Auto3613[1]=fr__Auto3613;
	_Context->hint_Auto3613[2]=it__Auto3613;
	_Context->hint_Auto3613[3]=es__Auto3613;
	_Context->hint_Auto3613[4]=de__Auto3613;
	_Context->hint_Auto3613[5]=nl__Auto3613;
	_Context->hint_Auto3613[6]=pt__Auto3613;
	_Context->hint_Auto3613[7]=xx__Auto3613;
	for (i=0; i < 8; i++)_Context->msg_Auto3614[i]=" ";
	_Context->msg_Auto3614[0]=en_Auto3614;
	_Context->msg_Auto3614[1]=fr_Auto3614;
	_Context->msg_Auto3614[2]=it_Auto3614;
	_Context->msg_Auto3614[3]=es_Auto3614;
	_Context->msg_Auto3614[4]=de_Auto3614;
	_Context->msg_Auto3614[5]=nl_Auto3614;
	_Context->msg_Auto3614[6]=pt_Auto3614;
	_Context->msg_Auto3614[7]=xx_Auto3614;
	_Context->hint_Auto3614[0]=en__Auto3614;
	_Context->hint_Auto3614[1]=fr__Auto3614;
	_Context->hint_Auto3614[2]=it__Auto3614;
	_Context->hint_Auto3614[3]=es__Auto3614;
	_Context->hint_Auto3614[4]=de__Auto3614;
	_Context->hint_Auto3614[5]=nl__Auto3614;
	_Context->hint_Auto3614[6]=pt__Auto3614;
	_Context->hint_Auto3614[7]=xx__Auto3614;
	for (i=0; i < 8; i++)_Context->msg_NationalMessages[i]=" ";
	_Context->msg_NationalMessages[0]=en_NationalMessages;
	_Context->msg_NationalMessages[1]=fr_NationalMessages;
	_Context->msg_NationalMessages[2]=it_NationalMessages;
	_Context->msg_NationalMessages[3]=es_NationalMessages;
	_Context->msg_NationalMessages[4]=de_NationalMessages;
	_Context->msg_NationalMessages[5]=nl_NationalMessages;
	_Context->msg_NationalMessages[6]=pt_NationalMessages;
	_Context->msg_NationalMessages[7]=xx_NationalMessages;
	_Context->hint_NationalMessages[0]=en__NationalMessages;
	_Context->hint_NationalMessages[1]=fr__NationalMessages;
	_Context->hint_NationalMessages[2]=it__NationalMessages;
	_Context->hint_NationalMessages[3]=es__NationalMessages;
	_Context->hint_NationalMessages[4]=de__NationalMessages;
	_Context->hint_NationalMessages[5]=nl__NationalMessages;
	_Context->hint_NationalMessages[6]=pt__NationalMessages;
	_Context->hint_NationalMessages[7]=xx__NationalMessages;
	for (i=0; i < 8; i++)_Context->msg_NationalHelptext[i]=" ";
	_Context->msg_NationalHelptext[0]=en_NationalHelptext;
	_Context->msg_NationalHelptext[1]=fr_NationalHelptext;
	_Context->msg_NationalHelptext[2]=it_NationalHelptext;
	_Context->msg_NationalHelptext[3]=es_NationalHelptext;
	_Context->msg_NationalHelptext[4]=de_NationalHelptext;
	_Context->msg_NationalHelptext[5]=nl_NationalHelptext;
	_Context->msg_NationalHelptext[6]=pt_NationalHelptext;
	_Context->msg_NationalHelptext[7]=xx_NationalHelptext;
	_Context->hint_NationalHelptext[0]=en__NationalHelptext;
	_Context->hint_NationalHelptext[1]=fr__NationalHelptext;
	_Context->hint_NationalHelptext[2]=it__NationalHelptext;
	_Context->hint_NationalHelptext[3]=es__NationalHelptext;
	_Context->hint_NationalHelptext[4]=de__NationalHelptext;
	_Context->hint_NationalHelptext[5]=nl__NationalHelptext;
	_Context->hint_NationalHelptext[6]=pt__NationalHelptext;
	_Context->hint_NationalHelptext[7]=xx__NationalHelptext;
	for (i=0; i < 8; i++)_Context->msg_Auto3615[i]=" ";
	_Context->msg_Auto3615[0]=en_Auto3615;
	_Context->msg_Auto3615[1]=fr_Auto3615;
	_Context->msg_Auto3615[2]=it_Auto3615;
	_Context->msg_Auto3615[3]=es_Auto3615;
	_Context->msg_Auto3615[4]=de_Auto3615;
	_Context->msg_Auto3615[5]=nl_Auto3615;
	_Context->msg_Auto3615[6]=pt_Auto3615;
	_Context->msg_Auto3615[7]=xx_Auto3615;
	_Context->hint_Auto3615[0]=en__Auto3615;
	_Context->hint_Auto3617[0]=en__Auto3617;
	for (i=0; i < 8; i++)_Context->msg_Widget[i]=" ";
	_Context->msg_Widget[0]=en_Widget;
	_Context->msg_Widget[1]=fr_Widget;
	_Context->msg_Widget[2]=it_Widget;
	_Context->msg_Widget[3]=es_Widget;
	_Context->msg_Widget[4]=de_Widget;
	_Context->msg_Widget[5]=nl_Widget;
	_Context->msg_Widget[6]=pt_Widget;
	_Context->msg_Widget[7]=xx_Widget;
	_Context->hint_Widget[0]=en__Widget;
	_Context->focus_pages[1]=8;
	for (i=0; i < 8; i++)_Context->msg_all_widget[i]=" ";
	_Context->msg_all_widget[0]=en_all_widget;
	_Context->msg_all_widget[1]=fr_all_widget;
	_Context->msg_all_widget[2]=it_all_widget;
	_Context->msg_all_widget[3]=es_all_widget;
	_Context->msg_all_widget[4]=de_all_widget;
	_Context->msg_all_widget[5]=nl_all_widget;
	_Context->msg_all_widget[6]=pt_all_widget;
	_Context->msg_all_widget[7]=xx_all_widget;
	_Context->hint_all_widget[0]=en__all_widget;
	_Context->all_widget = (struct vwall_context*) 0;
	_Context->status = vwall_create(&_Context->all_widget);
	vwall_position_at(_Context->all_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_select_widget[i]=" ";
	_Context->msg_select_widget[0]=en_select_widget;
	_Context->msg_select_widget[1]=fr_select_widget;
	_Context->msg_select_widget[2]=it_select_widget;
	_Context->msg_select_widget[3]=es_select_widget;
	_Context->msg_select_widget[4]=de_select_widget;
	_Context->msg_select_widget[5]=nl_select_widget;
	_Context->msg_select_widget[6]=pt_select_widget;
	_Context->msg_select_widget[7]=xx_select_widget;
	_Context->hint_select_widget[0]=en__select_widget;
	_Context->select_widget = (struct vwselect_context*) 0;
	_Context->status = vwselect_create(&_Context->select_widget);
	vwselect_position_at(_Context->select_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_frame_widget[i]=" ";
	_Context->msg_frame_widget[0]=en_frame_widget;
	_Context->msg_frame_widget[1]=fr_frame_widget;
	_Context->msg_frame_widget[2]=it_frame_widget;
	_Context->msg_frame_widget[3]=es_frame_widget;
	_Context->msg_frame_widget[4]=de_frame_widget;
	_Context->msg_frame_widget[5]=nl_frame_widget;
	_Context->msg_frame_widget[6]=pt_frame_widget;
	_Context->msg_frame_widget[7]=xx_frame_widget;
	_Context->hint_frame_widget[0]=en__frame_widget;
	_Context->frame_widget = (struct vwframe_context*) 0;
	_Context->status = vwframe_create(&_Context->frame_widget);
	vwframe_position_at(_Context->frame_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_edit_widget[i]=" ";
	_Context->msg_edit_widget[0]=en_edit_widget;
	_Context->msg_edit_widget[1]=fr_edit_widget;
	_Context->msg_edit_widget[2]=it_edit_widget;
	_Context->msg_edit_widget[3]=es_edit_widget;
	_Context->msg_edit_widget[4]=de_edit_widget;
	_Context->msg_edit_widget[5]=nl_edit_widget;
	_Context->msg_edit_widget[6]=pt_edit_widget;
	_Context->msg_edit_widget[7]=xx_edit_widget;
	_Context->hint_edit_widget[0]=en__edit_widget;
	_Context->edit_widget = (struct vwedit_context*) 0;
	_Context->status = vwedit_create(&_Context->edit_widget);
	vwedit_position_at(_Context->edit_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_button_widget[i]=" ";
	_Context->msg_button_widget[0]=en_button_widget;
	_Context->msg_button_widget[1]=fr_button_widget;
	_Context->msg_button_widget[2]=it_button_widget;
	_Context->msg_button_widget[3]=es_button_widget;
	_Context->msg_button_widget[4]=de_button_widget;
	_Context->msg_button_widget[5]=nl_button_widget;
	_Context->msg_button_widget[6]=pt_button_widget;
	_Context->msg_button_widget[7]=xx_button_widget;
	_Context->hint_button_widget[0]=en__button_widget;
	_Context->button_widget = (struct vwbutton_context*) 0;
	_Context->status = vwbutton_create(&_Context->button_widget);
	vwbutton_position_at(_Context->button_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_check_widget[i]=" ";
	_Context->msg_check_widget[0]=en_check_widget;
	_Context->msg_check_widget[1]=fr_check_widget;
	_Context->msg_check_widget[2]=it_check_widget;
	_Context->msg_check_widget[3]=es_check_widget;
	_Context->msg_check_widget[4]=de_check_widget;
	_Context->msg_check_widget[5]=nl_check_widget;
	_Context->msg_check_widget[6]=pt_check_widget;
	_Context->msg_check_widget[7]=xx_check_widget;
	_Context->hint_check_widget[0]=en__check_widget;
	_Context->check_widget = (struct vwcheck_context*) 0;
	_Context->status = vwcheck_create(&_Context->check_widget);
	vwcheck_position_at(_Context->check_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_data_widget[i]=" ";
	_Context->msg_data_widget[0]=en_data_widget;
	_Context->msg_data_widget[1]=fr_data_widget;
	_Context->msg_data_widget[2]=it_data_widget;
	_Context->msg_data_widget[3]=es_data_widget;
	_Context->msg_data_widget[4]=de_data_widget;
	_Context->msg_data_widget[5]=nl_data_widget;
	_Context->msg_data_widget[6]=pt_data_widget;
	_Context->msg_data_widget[7]=xx_data_widget;
	_Context->hint_data_widget[0]=en__data_widget;
	_Context->data_widget = (struct vwdata_context*) 0;
	_Context->status = vwdata_create(&_Context->data_widget);
	vwdata_position_at(_Context->data_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_fill_widget[i]=" ";
	_Context->msg_fill_widget[0]=en_fill_widget;
	_Context->msg_fill_widget[1]=fr_fill_widget;
	_Context->msg_fill_widget[2]=it_fill_widget;
	_Context->msg_fill_widget[3]=es_fill_widget;
	_Context->msg_fill_widget[4]=de_fill_widget;
	_Context->msg_fill_widget[5]=nl_fill_widget;
	_Context->msg_fill_widget[6]=pt_fill_widget;
	_Context->msg_fill_widget[7]=xx_fill_widget;
	_Context->hint_fill_widget[0]=en__fill_widget;
	_Context->fill_widget = (struct vwfill_context*) 0;
	_Context->status = vwfill_create(&_Context->fill_widget);
	vwfill_position_at(_Context->fill_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_form_widget[i]=" ";
	_Context->msg_form_widget[0]=en_form_widget;
	_Context->msg_form_widget[1]=fr_form_widget;
	_Context->msg_form_widget[2]=it_form_widget;
	_Context->msg_form_widget[3]=es_form_widget;
	_Context->msg_form_widget[4]=de_form_widget;
	_Context->msg_form_widget[5]=nl_form_widget;
	_Context->msg_form_widget[6]=pt_form_widget;
	_Context->msg_form_widget[7]=xx_form_widget;
	_Context->hint_form_widget[0]=en__form_widget;
	_Context->form_widget = (struct vwform_context*) 0;
	_Context->status = vwform_create(&_Context->form_widget);
	vwform_position_at(_Context->form_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_scroll_widget[i]=" ";
	_Context->msg_scroll_widget[0]=en_scroll_widget;
	_Context->msg_scroll_widget[1]=fr_scroll_widget;
	_Context->msg_scroll_widget[2]=it_scroll_widget;
	_Context->msg_scroll_widget[3]=es_scroll_widget;
	_Context->msg_scroll_widget[4]=de_scroll_widget;
	_Context->msg_scroll_widget[5]=nl_scroll_widget;
	_Context->msg_scroll_widget[6]=pt_scroll_widget;
	_Context->msg_scroll_widget[7]=xx_scroll_widget;
	_Context->hint_scroll_widget[0]=en__scroll_widget;
	_Context->scroll_widget = (struct vwscroll_context*) 0;
	_Context->status = vwscroll_create(&_Context->scroll_widget);
	vwscroll_position_at(_Context->scroll_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_progress_widget[i]=" ";
	_Context->msg_progress_widget[0]=en_progress_widget;
	_Context->msg_progress_widget[1]=fr_progress_widget;
	_Context->msg_progress_widget[2]=it_progress_widget;
	_Context->msg_progress_widget[3]=es_progress_widget;
	_Context->msg_progress_widget[4]=de_progress_widget;
	_Context->msg_progress_widget[5]=nl_progress_widget;
	_Context->msg_progress_widget[6]=pt_progress_widget;
	_Context->msg_progress_widget[7]=xx_progress_widget;
	_Context->hint_progress_widget[0]=en__progress_widget;
	_Context->progress_widget = (struct vwprogress_context*) 0;
	_Context->status = vwprogress_create(&_Context->progress_widget);
	vwprogress_position_at(_Context->progress_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_tabpage_widget[i]=" ";
	_Context->msg_tabpage_widget[0]=en_tabpage_widget;
	_Context->msg_tabpage_widget[1]=fr_tabpage_widget;
	_Context->msg_tabpage_widget[2]=it_tabpage_widget;
	_Context->msg_tabpage_widget[3]=es_tabpage_widget;
	_Context->msg_tabpage_widget[4]=de_tabpage_widget;
	_Context->msg_tabpage_widget[5]=nl_tabpage_widget;
	_Context->msg_tabpage_widget[6]=pt_tabpage_widget;
	_Context->msg_tabpage_widget[7]=xx_tabpage_widget;
	_Context->hint_tabpage_widget[0]=en__tabpage_widget;
	_Context->tabpage_widget = (struct vwtabpage_context*) 0;
	_Context->status = vwtabpage_create(&_Context->tabpage_widget);
	vwtabpage_position_at(_Context->tabpage_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_radio_widget[i]=" ";
	_Context->msg_radio_widget[0]=en_radio_widget;
	_Context->msg_radio_widget[1]=fr_radio_widget;
	_Context->msg_radio_widget[2]=it_radio_widget;
	_Context->msg_radio_widget[3]=es_radio_widget;
	_Context->msg_radio_widget[4]=de_radio_widget;
	_Context->msg_radio_widget[5]=nl_radio_widget;
	_Context->msg_radio_widget[6]=pt_radio_widget;
	_Context->msg_radio_widget[7]=xx_radio_widget;
	_Context->hint_radio_widget[0]=en__radio_widget;
	_Context->radio_widget = (struct vwradio_context*) 0;
	_Context->status = vwradio_create(&_Context->radio_widget);
	vwradio_position_at(_Context->radio_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_window_widget[i]=" ";
	_Context->msg_window_widget[0]=en_window_widget;
	_Context->msg_window_widget[1]=fr_window_widget;
	_Context->msg_window_widget[2]=it_window_widget;
	_Context->msg_window_widget[3]=es_window_widget;
	_Context->msg_window_widget[4]=de_window_widget;
	_Context->msg_window_widget[5]=nl_window_widget;
	_Context->msg_window_widget[6]=pt_window_widget;
	_Context->msg_window_widget[7]=xx_window_widget;
	_Context->hint_window_widget[0]=en__window_widget;
	_Context->window_widget = (struct vwwindow_context*) 0;
	_Context->status = vwwindow_create(&_Context->window_widget);
	vwwindow_position_at(_Context->window_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_text_widget[i]=" ";
	_Context->msg_text_widget[0]=en_text_widget;
	_Context->msg_text_widget[1]=fr_text_widget;
	_Context->msg_text_widget[2]=it_text_widget;
	_Context->msg_text_widget[3]=es_text_widget;
	_Context->msg_text_widget[4]=de_text_widget;
	_Context->msg_text_widget[5]=nl_text_widget;
	_Context->msg_text_widget[6]=pt_text_widget;
	_Context->msg_text_widget[7]=xx_text_widget;
	_Context->hint_text_widget[0]=en__text_widget;
	_Context->text_widget = (struct vwtext_context*) 0;
	_Context->status = vwtext_create(&_Context->text_widget);
	vwtext_position_at(_Context->text_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_image_widget[i]=" ";
	_Context->msg_image_widget[0]=en_image_widget;
	_Context->msg_image_widget[1]=fr_image_widget;
	_Context->msg_image_widget[2]=it_image_widget;
	_Context->msg_image_widget[3]=es_image_widget;
	_Context->msg_image_widget[4]=de_image_widget;
	_Context->msg_image_widget[5]=nl_image_widget;
	_Context->msg_image_widget[6]=pt_image_widget;
	_Context->msg_image_widget[7]=xx_image_widget;
	_Context->hint_image_widget[0]=en__image_widget;
	_Context->image_widget = (struct vwimage_context*) 0;
	_Context->status = vwimage_create(&_Context->image_widget);
	vwimage_position_at(_Context->image_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_line_widget[i]=" ";
	_Context->msg_line_widget[0]=en_line_widget;
	_Context->msg_line_widget[1]=fr_line_widget;
	_Context->msg_line_widget[2]=it_line_widget;
	_Context->msg_line_widget[3]=es_line_widget;
	_Context->msg_line_widget[4]=de_line_widget;
	_Context->msg_line_widget[5]=nl_line_widget;
	_Context->msg_line_widget[6]=pt_line_widget;
	_Context->msg_line_widget[7]=xx_line_widget;
	_Context->hint_line_widget[0]=en__line_widget;
	_Context->line_widget = (struct vwline_context*) 0;
	_Context->status = vwline_create(&_Context->line_widget);
	vwline_position_at(_Context->line_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_switch_widget[i]=" ";
	_Context->msg_switch_widget[0]=en_switch_widget;
	_Context->msg_switch_widget[1]=fr_switch_widget;
	_Context->msg_switch_widget[2]=it_switch_widget;
	_Context->msg_switch_widget[3]=es_switch_widget;
	_Context->msg_switch_widget[4]=de_switch_widget;
	_Context->msg_switch_widget[5]=nl_switch_widget;
	_Context->msg_switch_widget[6]=pt_switch_widget;
	_Context->msg_switch_widget[7]=xx_switch_widget;
	_Context->hint_switch_widget[0]=en__switch_widget;
	_Context->switch_widget = (struct vwswitch_context*) 0;
	_Context->status = vwswitch_create(&_Context->switch_widget);
	vwswitch_position_at(_Context->switch_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_graph_widget[i]=" ";
	_Context->msg_graph_widget[0]=en_graph_widget;
	_Context->msg_graph_widget[1]=fr_graph_widget;
	_Context->msg_graph_widget[2]=it_graph_widget;
	_Context->msg_graph_widget[3]=es_graph_widget;
	_Context->msg_graph_widget[4]=de_graph_widget;
	_Context->msg_graph_widget[5]=nl_graph_widget;
	_Context->msg_graph_widget[6]=pt_graph_widget;
	_Context->msg_graph_widget[7]=xx_graph_widget;
	_Context->hint_graph_widget[0]=en__graph_widget;
	_Context->graph_widget = (struct vwgraph_context*) 0;
	_Context->status = vwgraph_create(&_Context->graph_widget);
	vwgraph_position_at(_Context->graph_widget, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	for (i=0; i < 8; i++)_Context->msg_OnCreate[i]=" ";
	_Context->msg_OnCreate[0]=en_OnCreate;
	_Context->msg_OnCreate[1]=fr_OnCreate;
	_Context->msg_OnCreate[2]=it_OnCreate;
	_Context->msg_OnCreate[3]=es_OnCreate;
	_Context->msg_OnCreate[4]=de_OnCreate;
	_Context->msg_OnCreate[5]=nl_OnCreate;
	_Context->msg_OnCreate[6]=pt_OnCreate;
	_Context->msg_OnCreate[7]=xx_OnCreate;
	_Context->hint_OnCreate[0]=en__OnCreate;
	_Context->focus_pages[2]=9;
	(void) on_OnCreate_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Permission[i]=" ";
	_Context->msg_Permission[0]=en_Permission;
	_Context->msg_Permission[1]=fr_Permission;
	_Context->msg_Permission[2]=it_Permission;
	_Context->msg_Permission[3]=es_Permission;
	_Context->msg_Permission[4]=de_Permission;
	_Context->msg_Permission[5]=nl_Permission;
	_Context->msg_Permission[6]=pt_Permission;
	_Context->msg_Permission[7]=xx_Permission;
	_Context->hint_Permission[0]=en__Permission;
	_Context->hint_Permission[1]=fr__Permission;
	_Context->hint_Permission[2]=it__Permission;
	_Context->hint_Permission[3]=es__Permission;
	_Context->hint_Permission[4]=de__Permission;
	_Context->hint_Permission[5]=nl__Permission;
	_Context->hint_Permission[6]=pt__Permission;
	_Context->hint_Permission[7]=xx__Permission;
	for (i=0; i < 8; i++)_Context->msg_IsExtern[i]=" ";
	_Context->msg_IsExtern[0]=en_IsExtern;
	_Context->msg_IsExtern[1]=fr_IsExtern;
	_Context->msg_IsExtern[2]=it_IsExtern;
	_Context->msg_IsExtern[3]=es_IsExtern;
	_Context->msg_IsExtern[4]=de_IsExtern;
	_Context->msg_IsExtern[5]=nl_IsExtern;
	_Context->msg_IsExtern[6]=pt_IsExtern;
	_Context->msg_IsExtern[7]=xx_IsExtern;
	_Context->hint_IsExtern[0]=en__IsExtern;
	_Context->hint_IsExtern[1]=fr__IsExtern;
	_Context->hint_IsExtern[2]=it__IsExtern;
	_Context->hint_IsExtern[3]=es__IsExtern;
	_Context->hint_IsExtern[4]=de__IsExtern;
	_Context->hint_IsExtern[5]=nl__IsExtern;
	_Context->hint_IsExtern[6]=pt__IsExtern;
	_Context->hint_IsExtern[7]=xx__IsExtern;
	for (i=0; i < 8; i++)_Context->msg_CreateOptions[i]=" ";
	_Context->hint_CreateOptions[0]=en__CreateOptions;
	for (i=0; i < 8; i++)_Context->msg_OnShowPage[i]=" ";
	_Context->msg_OnShowPage[0]=en_OnShowPage;
	_Context->msg_OnShowPage[1]=fr_OnShowPage;
	_Context->msg_OnShowPage[2]=it_OnShowPage;
	_Context->msg_OnShowPage[3]=es_OnShowPage;
	_Context->msg_OnShowPage[4]=de_OnShowPage;
	_Context->msg_OnShowPage[5]=nl_OnShowPage;
	_Context->msg_OnShowPage[6]=pt_OnShowPage;
	_Context->msg_OnShowPage[7]=xx_OnShowPage;
	_Context->focus_pages[3]=14;
	for (i=0; i < 8; i++)_Context->msg_ShowOptions[i]=" ";
	_Context->hint_ShowOptions[0]=en__ShowOptions;
	for (i=0; i < 8; i++)_Context->msg_OnGetFocus[i]=" ";
	_Context->msg_OnGetFocus[0]=en_OnGetFocus;
	_Context->msg_OnGetFocus[1]=fr_OnGetFocus;
	_Context->msg_OnGetFocus[2]=it_OnGetFocus;
	_Context->msg_OnGetFocus[3]=es_OnGetFocus;
	_Context->msg_OnGetFocus[4]=de_OnGetFocus;
	_Context->msg_OnGetFocus[5]=nl_OnGetFocus;
	_Context->msg_OnGetFocus[6]=pt_OnGetFocus;
	_Context->msg_OnGetFocus[7]=xx_OnGetFocus;
	_Context->focus_pages[4]=17;
	for (i=0; i < 8; i++)_Context->msg_FocusOptions[i]=" ";
	_Context->hint_FocusOptions[0]=en__FocusOptions;
	for (i=0; i < 8; i++)_Context->msg_OnEvent[i]=" ";
	_Context->msg_OnEvent[0]=en_OnEvent;
	_Context->msg_OnEvent[1]=fr_OnEvent;
	_Context->msg_OnEvent[2]=it_OnEvent;
	_Context->msg_OnEvent[3]=es_OnEvent;
	_Context->msg_OnEvent[4]=de_OnEvent;
	_Context->msg_OnEvent[5]=nl_OnEvent;
	_Context->msg_OnEvent[6]=pt_OnEvent;
	_Context->msg_OnEvent[7]=xx_OnEvent;
	_Context->hint_OnEvent[0]=en__OnEvent;
	_Context->focus_pages[5]=20;
	for (i=0; i < 8; i++)_Context->msg_Auto3618[i]=" ";
	_Context->msg_Auto3618[0]=en_Auto3618;
	_Context->msg_Auto3618[1]=fr_Auto3618;
	_Context->msg_Auto3618[2]=it_Auto3618;
	_Context->msg_Auto3618[3]=es_Auto3618;
	_Context->msg_Auto3618[4]=de_Auto3618;
	_Context->msg_Auto3618[5]=nl_Auto3618;
	_Context->msg_Auto3618[6]=pt_Auto3618;
	_Context->msg_Auto3618[7]=xx_Auto3618;
	_Context->hint_Auto3618[0]=en__Auto3618;
	for (i=0; i < 8; i++)_Context->msg_MimoMove[i]=" ";
	_Context->msg_MimoMove[0]=en_MimoMove;
	_Context->msg_MimoMove[1]=fr_MimoMove;
	_Context->msg_MimoMove[2]=it_MimoMove;
	_Context->msg_MimoMove[3]=es_MimoMove;
	_Context->msg_MimoMove[4]=de_MimoMove;
	_Context->msg_MimoMove[5]=nl_MimoMove;
	_Context->msg_MimoMove[6]=pt_MimoMove;
	_Context->msg_MimoMove[7]=xx_MimoMove;
	for (i=0; i < 8; i++)_Context->msg_MimoDown[i]=" ";
	_Context->msg_MimoDown[0]=en_MimoDown;
	_Context->msg_MimoDown[1]=fr_MimoDown;
	_Context->msg_MimoDown[2]=it_MimoDown;
	_Context->msg_MimoDown[3]=es_MimoDown;
	_Context->msg_MimoDown[4]=de_MimoDown;
	_Context->msg_MimoDown[5]=nl_MimoDown;
	_Context->msg_MimoDown[6]=pt_MimoDown;
	_Context->msg_MimoDown[7]=xx_MimoDown;
	for (i=0; i < 8; i++)_Context->msg_MimoUp[i]=" ";
	_Context->msg_MimoUp[0]=en_MimoUp;
	_Context->msg_MimoUp[1]=fr_MimoUp;
	_Context->msg_MimoUp[2]=it_MimoUp;
	_Context->msg_MimoUp[3]=es_MimoUp;
	_Context->msg_MimoUp[4]=de_MimoUp;
	_Context->msg_MimoUp[5]=nl_MimoUp;
	_Context->msg_MimoUp[6]=pt_MimoUp;
	_Context->msg_MimoUp[7]=xx_MimoUp;
	for (i=0; i < 8; i++)_Context->msg_MimoHold[i]=" ";
	_Context->msg_MimoHold[0]=en_MimoHold;
	_Context->msg_MimoHold[1]=fr_MimoHold;
	_Context->msg_MimoHold[2]=it_MimoHold;
	_Context->msg_MimoHold[3]=es_MimoHold;
	_Context->msg_MimoHold[4]=de_MimoHold;
	_Context->msg_MimoHold[5]=nl_MimoHold;
	_Context->msg_MimoHold[6]=pt_MimoHold;
	_Context->msg_MimoHold[7]=xx_MimoHold;
	for (i=0; i < 8; i++)_Context->msg_MimoLeft[i]=" ";
	_Context->msg_MimoLeft[0]=en_MimoLeft;
	_Context->msg_MimoLeft[1]=fr_MimoLeft;
	_Context->msg_MimoLeft[2]=it_MimoLeft;
	_Context->msg_MimoLeft[3]=es_MimoLeft;
	_Context->msg_MimoLeft[4]=de_MimoLeft;
	_Context->msg_MimoLeft[5]=nl_MimoLeft;
	_Context->msg_MimoLeft[6]=pt_MimoLeft;
	_Context->msg_MimoLeft[7]=xx_MimoLeft;
	_Context->hint_MimoLeft[0]=en__MimoLeft;
	_Context->hint_MimoLeft[1]=fr__MimoLeft;
	_Context->hint_MimoLeft[2]=it__MimoLeft;
	_Context->hint_MimoLeft[3]=es__MimoLeft;
	_Context->hint_MimoLeft[4]=de__MimoLeft;
	_Context->hint_MimoLeft[5]=nl__MimoLeft;
	_Context->hint_MimoLeft[6]=pt__MimoLeft;
	_Context->hint_MimoLeft[7]=xx__MimoLeft;
	for (i=0; i < 8; i++)_Context->msg_Auto3619[i]=" ";
	_Context->msg_Auto3619[0]=en_Auto3619;
	_Context->hint_Auto3619[0]=en__Auto3619;
	for (i=0; i < 8; i++)_Context->msg_Auto3620[i]=" ";
	_Context->msg_Auto3620[0]=en_Auto3620;
	_Context->hint_Auto3620[0]=en__Auto3620;
	for (i=0; i < 8; i++)_Context->msg_MimoRight[i]=" ";
	_Context->msg_MimoRight[0]=en_MimoRight;
	_Context->msg_MimoRight[1]=fr_MimoRight;
	_Context->msg_MimoRight[2]=it_MimoRight;
	_Context->msg_MimoRight[3]=es_MimoRight;
	_Context->msg_MimoRight[4]=de_MimoRight;
	_Context->msg_MimoRight[5]=nl_MimoRight;
	_Context->msg_MimoRight[6]=pt_MimoRight;
	_Context->msg_MimoRight[7]=xx_MimoRight;
	_Context->hint_MimoRight[0]=en__MimoRight;
	_Context->hint_MimoRight[1]=fr__MimoRight;
	_Context->hint_MimoRight[2]=it__MimoRight;
	_Context->hint_MimoRight[3]=es__MimoRight;
	_Context->hint_MimoRight[4]=de__MimoRight;
	_Context->hint_MimoRight[5]=nl__MimoRight;
	_Context->hint_MimoRight[6]=pt__MimoRight;
	_Context->hint_MimoRight[7]=xx__MimoRight;
	for (i=0; i < 8; i++)_Context->msg_MimoWheel[i]=" ";
	_Context->msg_MimoWheel[0]=en_MimoWheel;
	_Context->msg_MimoWheel[1]=fr_MimoWheel;
	_Context->msg_MimoWheel[2]=it_MimoWheel;
	_Context->msg_MimoWheel[3]=es_MimoWheel;
	_Context->msg_MimoWheel[4]=de_MimoWheel;
	_Context->msg_MimoWheel[5]=nl_MimoWheel;
	_Context->msg_MimoWheel[6]=pt_MimoWheel;
	_Context->msg_MimoWheel[7]=xx_MimoWheel;
	_Context->hint_MimoWheel[0]=en__MimoWheel;
	_Context->hint_MimoWheel[1]=fr__MimoWheel;
	_Context->hint_MimoWheel[2]=it__MimoWheel;
	_Context->hint_MimoWheel[3]=es__MimoWheel;
	_Context->hint_MimoWheel[4]=de__MimoWheel;
	_Context->hint_MimoWheel[5]=nl__MimoWheel;
	_Context->hint_MimoWheel[6]=pt__MimoWheel;
	_Context->hint_MimoWheel[7]=xx__MimoWheel;
	for (i=0; i < 8; i++)_Context->msg_MimoMiddle[i]=" ";
	_Context->msg_MimoMiddle[0]=en_MimoMiddle;
	_Context->msg_MimoMiddle[1]=fr_MimoMiddle;
	_Context->msg_MimoMiddle[2]=it_MimoMiddle;
	_Context->msg_MimoMiddle[3]=es_MimoMiddle;
	_Context->msg_MimoMiddle[4]=de_MimoMiddle;
	_Context->msg_MimoMiddle[5]=nl_MimoMiddle;
	_Context->msg_MimoMiddle[6]=pt_MimoMiddle;
	_Context->msg_MimoMiddle[7]=xx_MimoMiddle;
	_Context->hint_MimoMiddle[0]=en__MimoMiddle;
	_Context->hint_MimoMiddle[1]=fr__MimoMiddle;
	_Context->hint_MimoMiddle[2]=it__MimoMiddle;
	_Context->hint_MimoMiddle[3]=es__MimoMiddle;
	_Context->hint_MimoMiddle[4]=de__MimoMiddle;
	_Context->hint_MimoMiddle[5]=nl__MimoMiddle;
	_Context->hint_MimoMiddle[6]=pt__MimoMiddle;
	_Context->hint_MimoMiddle[7]=xx__MimoMiddle;
	for (i=0; i < 8; i++)_Context->msg_EventOptions[i]=" ";
	_Context->hint_EventOptions[0]=en__EventOptions;
	for (i=0; i < 8; i++)_Context->msg_OnLoseFocus[i]=" ";
	_Context->msg_OnLoseFocus[0]=en_OnLoseFocus;
	_Context->msg_OnLoseFocus[1]=fr_OnLoseFocus;
	_Context->msg_OnLoseFocus[2]=it_OnLoseFocus;
	_Context->msg_OnLoseFocus[3]=es_OnLoseFocus;
	_Context->msg_OnLoseFocus[4]=de_OnLoseFocus;
	_Context->msg_OnLoseFocus[5]=nl_OnLoseFocus;
	_Context->msg_OnLoseFocus[6]=pt_OnLoseFocus;
	_Context->msg_OnLoseFocus[7]=xx_OnLoseFocus;
	_Context->hint_OnLoseFocus[0]=en__OnLoseFocus;
	_Context->focus_pages[6]=31;
	for (i=0; i < 8; i++)_Context->msg_LoseOptions[i]=" ";
	_Context->hint_LoseOptions[0]=en__LoseOptions;
	for (i=0; i < 8; i++)_Context->msg_OnHidePage[i]=" ";
	_Context->msg_OnHidePage[0]=en_OnHidePage;
	_Context->msg_OnHidePage[1]=fr_OnHidePage;
	_Context->msg_OnHidePage[2]=it_OnHidePage;
	_Context->msg_OnHidePage[3]=es_OnHidePage;
	_Context->msg_OnHidePage[4]=de_OnHidePage;
	_Context->msg_OnHidePage[5]=nl_OnHidePage;
	_Context->msg_OnHidePage[6]=pt_OnHidePage;
	_Context->msg_OnHidePage[7]=xx_OnHidePage;
	_Context->hint_OnHidePage[0]=en__OnHidePage;
	_Context->focus_pages[7]=34;
	for (i=0; i < 8; i++)_Context->msg_HideOptions[i]=" ";
	_Context->hint_HideOptions[0]=en__HideOptions;
	for (i=0; i < 8; i++)_Context->msg_OnRemove[i]=" ";
	_Context->msg_OnRemove[0]=en_OnRemove;
	_Context->msg_OnRemove[1]=fr_OnRemove;
	_Context->msg_OnRemove[2]=it_OnRemove;
	_Context->msg_OnRemove[3]=es_OnRemove;
	_Context->msg_OnRemove[4]=de_OnRemove;
	_Context->msg_OnRemove[5]=nl_OnRemove;
	_Context->msg_OnRemove[6]=pt_OnRemove;
	_Context->msg_OnRemove[7]=xx_OnRemove;
	_Context->hint_OnRemove[0]=en__OnRemove;
	_Context->focus_pages[8]=37;
	for (i=0; i < 8; i++)_Context->msg_RemoveOptions[i]=" ";
	_Context->hint_RemoveOptions[0]=en__RemoveOptions;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710+10,540+10);
	return(0);
}
private int on_WidgetProperties_hide(struct accept_widget_properties_context * _Context) {
	close_window_editor();
	return(-1);
}

public 	int	accept_widget_properties_hide(struct accept_widget_properties_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	vwgraph_hide(_Context->graph_widget);
	vwswitch_hide(_Context->switch_widget);
	vwline_hide(_Context->line_widget);
	vwimage_hide(_Context->image_widget);
	vwtext_hide(_Context->text_widget);
	vwwindow_hide(_Context->window_widget);
	vwradio_hide(_Context->radio_widget);
	vwtabpage_hide(_Context->tabpage_widget);
	vwprogress_hide(_Context->progress_widget);
	vwscroll_hide(_Context->scroll_widget);
	vwform_hide(_Context->form_widget);
	vwfill_hide(_Context->fill_widget);
	vwdata_hide(_Context->data_widget);
	vwcheck_hide(_Context->check_widget);
	vwbutton_hide(_Context->button_widget);
	vwedit_hide(_Context->edit_widget);
	vwframe_hide(_Context->frame_widget);
	vwselect_hide(_Context->select_widget);
	vwall_hide(_Context->all_widget);
	(void) on_WidgetProperties_hide(_Context);
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_WidgetProperties,_Context->y_WidgetProperties);
		_Context->ctrlbuffer=0;
		}

	return(result);
}
private int on_OnCreate_remove(struct accept_widget_properties_context * _Context) {
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	if(_Context->keycode!=27){
	if(use_all_widget()){
	vwall_GetVars(_Context->all_widget);
	}
	else{
	switch(*((int*)pSpecificWidgetProperties->pWidgetClass)){
	case _FILL_FRAME:
	vwfill_GetVars(_Context->fill_widget);
	break;
	case _OUTSET_FRAME:
	case _INSET_FRAME:
	case _RIDGE_FRAME:
	case _GROOVE_FRAME:
	vwframe_GetVars(_Context->frame_widget);
	break;
	case _EDIT_FRAME:
	vwedit_GetVars(_Context->edit_widget);
	break;
	case _TEXT_FRAME:
	vwtext_GetVars(_Context->text_widget);
	break;
	case _IMAGE_FRAME:
	vwimage_GetVars(_Context->image_widget);
	break;
	case _LINE_FRAME:
	vwline_GetVars(_Context->line_widget);
	break;
	case _BUTTON_FRAME:
	vwbutton_GetVars(_Context->button_widget);
	break;
	case _WINDOW_FRAME:
	vwwindow_GetVars(_Context->window_widget);
	break;
	case _TAB_FRAME:
	vwtabpage_GetVars(_Context->tabpage_widget);
	break;
	case _CHECK_FRAME:
	vwcheck_GetVars(_Context->check_widget);
	break;
	case _RADIO_FRAME:
	vwradio_GetVars(_Context->radio_widget);
	break;
	case _SELECT_FRAME:
	vwselect_GetVars(_Context->select_widget);
	break;
	case _FORM_FRAME:
	vwform_GetVars(_Context->form_widget);
	break;
	case _SCROLL_FRAME:
	vwscroll_GetVars(_Context->scroll_widget);
	break;
	case _PROGRESS_FRAME:
	vwprogress_GetVars(_Context->progress_widget);
	break;
	case _SWITCH_FRAME:
	vwswitch_GetVars(_Context->switch_widget);
	break;
	case _GRAPH_FRAME:
	vwgraph_GetVars(_Context->graph_widget);
	break;
	case _DATA_FRAME:
	vwdata_GetVars(_Context->data_widget);
	break;
	case _CUT_FRAME:
	default:
	vwall_GetVars(_Context->all_widget);
	break;
	}
	}
	}
	return(-1);
}

public	int	accept_widget_properties_remove(
	struct accept_widget_properties_context * _Context,
	char * pPermission,
	char * pIsExtern,
	char * pCreateOptions,
	char * pCreate,
	char * pShowOptions,
	char * pShow,
	char * pFocusOptions,
	char * pGetFocus,
	char * pMimoMove,
	char * pMimoDown,
	char * pMimoUp,
	char * pMimoHold,
	char * pMimoLeft,
	char * pMimoRight,
	char * pMimoWheel,
	char * pMimoMiddle,
	char * pEventOptions,
	char * pEvent,
	char * pLoseOptions,
	char * pLoseFocus,
	char * pHideOptions,
	char * pHide,
	char * pRemoveOptions,
	char * pRemove)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	(void) on_OnCreate_remove(_Context);
	_Context->status = vwgraph_remove(_Context->graph_widget);
	_Context->graph_widget = (struct vwgraph_context*) 0;
	_Context->status = vwswitch_remove(_Context->switch_widget);
	_Context->switch_widget = (struct vwswitch_context*) 0;
	_Context->status = vwline_remove(_Context->line_widget);
	_Context->line_widget = (struct vwline_context*) 0;
	_Context->status = vwimage_remove(_Context->image_widget);
	_Context->image_widget = (struct vwimage_context*) 0;
	_Context->status = vwtext_remove(_Context->text_widget);
	_Context->text_widget = (struct vwtext_context*) 0;
	_Context->status = vwwindow_remove(_Context->window_widget);
	_Context->window_widget = (struct vwwindow_context*) 0;
	_Context->status = vwradio_remove(_Context->radio_widget);
	_Context->radio_widget = (struct vwradio_context*) 0;
	_Context->status = vwtabpage_remove(_Context->tabpage_widget);
	_Context->tabpage_widget = (struct vwtabpage_context*) 0;
	_Context->status = vwprogress_remove(_Context->progress_widget);
	_Context->progress_widget = (struct vwprogress_context*) 0;
	_Context->status = vwscroll_remove(_Context->scroll_widget);
	_Context->scroll_widget = (struct vwscroll_context*) 0;
	_Context->status = vwform_remove(_Context->form_widget);
	_Context->form_widget = (struct vwform_context*) 0;
	_Context->status = vwfill_remove(_Context->fill_widget);
	_Context->fill_widget = (struct vwfill_context*) 0;
	_Context->status = vwdata_remove(_Context->data_widget);
	_Context->data_widget = (struct vwdata_context*) 0;
	_Context->status = vwcheck_remove(_Context->check_widget);
	_Context->check_widget = (struct vwcheck_context*) 0;
	_Context->status = vwbutton_remove(_Context->button_widget);
	_Context->button_widget = (struct vwbutton_context*) 0;
	_Context->status = vwedit_remove(_Context->edit_widget);
	_Context->edit_widget = (struct vwedit_context*) 0;
	_Context->status = vwframe_remove(_Context->frame_widget);
	_Context->frame_widget = (struct vwframe_context*) 0;
	_Context->status = vwselect_remove(_Context->select_widget);
	_Context->select_widget = (struct vwselect_context*) 0;
	_Context->status = vwall_remove(_Context->all_widget);
	_Context->all_widget = (struct vwall_context*) 0;
	if (_Context->keycode == 27 ) {
		filetransferdrop(_Context->buffer_Create);
		filetransferdrop(_Context->buffer_Show);
		filetransferdrop(_Context->buffer_GetFocus);
		filetransferdrop(_Context->buffer_Event);
		filetransferdrop(_Context->buffer_LoseFocus);
		filetransferdrop(_Context->buffer_Hide);
		filetransferdrop(_Context->buffer_Remove);
		
	} else {
		strcpy(_Context->signature,"WWWTWTWTWWWWWWWWWTWTWTWT");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pPermission);
		if ( pPermission != (char *) 0)
			*((int*)pPermission) = _Context->value_Permission;
		visual_transferout((void *) 0, 0, pIsExtern);
		if ( pIsExtern != (char *) 0)
			*((int*)pIsExtern) = _Context->value_IsExtern;
		visual_transferout((void *) 0, 0, pCreateOptions);
		if ( pCreateOptions != (char *) 0)
			*((int*)pCreateOptions) = _Context->value_CreateOptions;
		visual_transferout(&_Context->buffer_Create, 1782, pCreate);
		visual_transferout((void *) 0, 0, pShowOptions);
		if ( pShowOptions != (char *) 0)
			*((int*)pShowOptions) = _Context->value_ShowOptions;
		visual_transferout(&_Context->buffer_Show, 1782, pShow);
		visual_transferout((void *) 0, 0, pFocusOptions);
		if ( pFocusOptions != (char *) 0)
			*((int*)pFocusOptions) = _Context->value_FocusOptions;
		visual_transferout(&_Context->buffer_GetFocus, 1782, pGetFocus);
		visual_transferout((void *) 0, 0, pMimoMove);
		if ( pMimoMove != (char *) 0)
			*((int*)pMimoMove) = _Context->value_MimoMove;
		visual_transferout((void *) 0, 0, pMimoDown);
		if ( pMimoDown != (char *) 0)
			*((int*)pMimoDown) = _Context->value_MimoDown;
		visual_transferout((void *) 0, 0, pMimoUp);
		if ( pMimoUp != (char *) 0)
			*((int*)pMimoUp) = _Context->value_MimoUp;
		visual_transferout((void *) 0, 0, pMimoHold);
		if ( pMimoHold != (char *) 0)
			*((int*)pMimoHold) = _Context->value_MimoHold;
		visual_transferout((void *) 0, 0, pMimoLeft);
		if ( pMimoLeft != (char *) 0)
			*((int*)pMimoLeft) = _Context->value_MimoLeft;
		visual_transferout((void *) 0, 0, pMimoRight);
		if ( pMimoRight != (char *) 0)
			*((int*)pMimoRight) = _Context->value_MimoRight;
		visual_transferout((void *) 0, 0, pMimoWheel);
		if ( pMimoWheel != (char *) 0)
			*((int*)pMimoWheel) = _Context->value_MimoWheel;
		visual_transferout((void *) 0, 0, pMimoMiddle);
		if ( pMimoMiddle != (char *) 0)
			*((int*)pMimoMiddle) = _Context->value_MimoMiddle;
		visual_transferout((void *) 0, 0, pEventOptions);
		if ( pEventOptions != (char *) 0)
			*((int*)pEventOptions) = _Context->value_EventOptions;
		visual_transferout(&_Context->buffer_Event, 1782, pEvent);
		visual_transferout((void *) 0, 0, pLoseOptions);
		if ( pLoseOptions != (char *) 0)
			*((int*)pLoseOptions) = _Context->value_LoseOptions;
		visual_transferout(&_Context->buffer_LoseFocus, 1782, pLoseFocus);
		visual_transferout((void *) 0, 0, pHideOptions);
		if ( pHideOptions != (char *) 0)
			*((int*)pHideOptions) = _Context->value_HideOptions;
		visual_transferout(&_Context->buffer_Hide, 1782, pHide);
		visual_transferout((void *) 0, 0, pRemoveOptions);
		if ( pRemoveOptions != (char *) 0)
			*((int*)pRemoveOptions) = _Context->value_RemoveOptions;
		visual_transferout(&_Context->buffer_Remove, 1782, pRemove);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Toggle_show(struct accept_widget_properties_context * _Context) {
	if(use_all_widget())
	_Context->value_Toggle=1;
	else _Context->value_Toggle=0;
		_Context->trigger_Toggle=visual_trigger_code(_Context->msg_Toggle[_Context->language],strlen(_Context->msg_Toggle[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+87,_Context->y_WidgetProperties+494,24,26,vfh[2],40,14,_Context->msg_Toggle[_Context->language],strlen(_Context->msg_Toggle[_Context->language]),_Context->value_Toggle| 0x0030);
;
	return(-1);
}
private int on_Widget_show(struct accept_widget_properties_context * _Context) {
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	if(use_all_widget()){
		vwall_position_at(_Context->all_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwall_show(_Context->all_widget);
;
	}
	else{
	switch(*((int*)pSpecificWidgetProperties->pWidgetClass)){
	case _FILL_FRAME:
		vwfill_position_at(_Context->fill_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwfill_show(_Context->fill_widget);
;
	break;
	case _OUTSET_FRAME:
	case _INSET_FRAME:
	case _RIDGE_FRAME:
	case _GROOVE_FRAME:
		vwframe_position_at(_Context->frame_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwframe_show(_Context->frame_widget);
;
	break;
	case _EDIT_FRAME:
		vwedit_position_at(_Context->edit_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwedit_show(_Context->edit_widget);
;
	break;
	case _TEXT_FRAME:
		vwtext_position_at(_Context->text_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwtext_show(_Context->text_widget);
;
	break;
	case _IMAGE_FRAME:
		vwimage_position_at(_Context->image_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwimage_show(_Context->image_widget);
;
	break;
	case _LINE_FRAME:
		vwline_position_at(_Context->line_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwline_show(_Context->line_widget);
;
	break;
	case _BUTTON_FRAME:
		vwbutton_position_at(_Context->button_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwbutton_show(_Context->button_widget);
;
	break;
	case _WINDOW_FRAME:
		vwwindow_position_at(_Context->window_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwwindow_show(_Context->window_widget);
;
	break;
	case _TAB_FRAME:
		vwtabpage_position_at(_Context->tabpage_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwtabpage_show(_Context->tabpage_widget);
;
	break;
	case _CHECK_FRAME:
		vwcheck_position_at(_Context->check_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwcheck_show(_Context->check_widget);
;
	break;
	case _RADIO_FRAME:
		vwradio_position_at(_Context->radio_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwradio_show(_Context->radio_widget);
;
	break;
	case _SELECT_FRAME:
		vwselect_position_at(_Context->select_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwselect_show(_Context->select_widget);
;
	break;
	case _FORM_FRAME:
		vwform_position_at(_Context->form_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwform_show(_Context->form_widget);
;
	break;
	case _SCROLL_FRAME:
		vwscroll_position_at(_Context->scroll_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwscroll_show(_Context->scroll_widget);
;
	break;
	case _PROGRESS_FRAME:
		vwprogress_position_at(_Context->progress_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwprogress_show(_Context->progress_widget);
;
	break;
	case _SWITCH_FRAME:
		vwswitch_position_at(_Context->switch_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwswitch_show(_Context->switch_widget);
;
	break;
	case _GRAPH_FRAME:
		vwgraph_position_at(_Context->graph_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwgraph_show(_Context->graph_widget);
;
	break;
	case _DATA_FRAME:
		vwdata_position_at(_Context->data_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwdata_show(_Context->data_widget);
;
	break;
	case _CUT_FRAME:
	default:
		vwall_position_at(_Context->all_widget,_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+70);
	vwall_show(_Context->all_widget);
;
	break;
	}
	}
	return(-1);
}
private int on_OnCreate_show(struct accept_widget_properties_context * _Context) {
	open_window_editor(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,
	648,352,_Context->buffer_Create);
	return(-1);
}
private int on_Create_show(struct accept_widget_properties_context * _Context) {
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_OnShowPage_show(struct accept_widget_properties_context * _Context) {
	open_window_editor(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,
	648,352,_Context->buffer_Show);
	return(-1);
}
private int on_Show_show(struct accept_widget_properties_context * _Context) {
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_OnGetFocus_show(struct accept_widget_properties_context * _Context) {
	open_window_editor(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,
	648,352,_Context->buffer_GetFocus);
	return(-1);
}
private int on_GetFocus_show(struct accept_widget_properties_context * _Context) {
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_OnEvent_show(struct accept_widget_properties_context * _Context) {
	open_window_editor(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,
	648,352,_Context->buffer_Event);
	return(-1);
}
private int on_Event_show(struct accept_widget_properties_context * _Context) {
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_OnLoseFocus_show(struct accept_widget_properties_context * _Context) {
	open_window_editor(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,
	648,352,_Context->buffer_LoseFocus);
	return(-1);
}
private int on_LoseFocus_show(struct accept_widget_properties_context * _Context) {
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_OnHidePage_show(struct accept_widget_properties_context * _Context) {
	open_window_editor(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,
	648,352,_Context->buffer_Hide);
	return(-1);
}
private int on_Hide_show(struct accept_widget_properties_context * _Context) {
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_OnRemove_show(struct accept_widget_properties_context * _Context) {
	open_window_editor(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,
	648,352,_Context->buffer_Remove);
	return(-1);
}
private int on_Remove_show(struct accept_widget_properties_context * _Context) {
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
	show_window_editor();
	return(-1);
}

public	int	accept_widget_properties_show(struct accept_widget_properties_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_WidgetProperties,_Context->y_WidgetProperties);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710,540,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710,540,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	_Context->trigger_Auto3610=visual_trigger_code(_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]));
	visual_button(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]),1040);
	_Context->trigger_Auto3611=visual_trigger_code(_Context->msg_Auto3611[_Context->language],strlen(_Context->msg_Auto3611[_Context->language]));
	visual_button(_Context->x_WidgetProperties+120,_Context->y_WidgetProperties+480,56,48,vfh[2],28,28,_Context->msg_Auto3611[_Context->language],strlen(_Context->msg_Auto3611[_Context->language]),1040);
	(void) on_Toggle_show(_Context);
	visual_text(_Context->x_WidgetProperties+180,_Context->y_WidgetProperties+490,84,32,vfh[2],16,0,_Context->msg_Auto3612[_Context->language],strlen(_Context->msg_Auto3612[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+490,112,32,vfh[2],16,0,_Context->msg_Auto3613[_Context->language],strlen(_Context->msg_Auto3613[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+510,_Context->y_WidgetProperties+490,112,32,vfh[2],16,0,_Context->msg_Auto3614[_Context->language],strlen(_Context->msg_Auto3614[_Context->language]),2);
	_Context->trigger_NationalMessages=visual_trigger_code(_Context->msg_NationalMessages[_Context->language],strlen(_Context->msg_NationalMessages[_Context->language]));
	visual_button(_Context->x_WidgetProperties+270,_Context->y_WidgetProperties+480,56,48,vfh[2],28,28,_Context->msg_NationalMessages[_Context->language],strlen(_Context->msg_NationalMessages[_Context->language]),16);
	_Context->trigger_NationalHelptext=visual_trigger_code(_Context->msg_NationalHelptext[_Context->language],strlen(_Context->msg_NationalHelptext[_Context->language]));
	visual_button(_Context->x_WidgetProperties+450,_Context->y_WidgetProperties+480,56,48,vfh[2],28,28,_Context->msg_NationalHelptext[_Context->language],strlen(_Context->msg_NationalHelptext[_Context->language]),16);
	_Context->trigger_Auto3615=visual_trigger_code(_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]));
	visual_button(_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]),1040);
	visual_filzone(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+50,650,30,18,12);
	visual_filzone(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+70,670,410,18,12);
	if (_Context->page_number == 1 ) {
	_Context->trigger_Widget=visual_trigger_code(_Context->msg_Widget[_Context->language],strlen(_Context->msg_Widget[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_Widget[_Context->language],strlen(_Context->msg_Widget[_Context->language]),0,1026);
		(void) on_Widget_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_Widget[_Context->language],strlen(_Context->msg_Widget[_Context->language]),0,1024);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_OnCreate=visual_trigger_code(_Context->msg_OnCreate[_Context->language],strlen(_Context->msg_OnCreate[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnCreate[_Context->language],strlen(_Context->msg_OnCreate[_Context->language]),81,2);
		(void) on_OnCreate_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnCreate[_Context->language],strlen(_Context->msg_OnCreate[_Context->language]),81,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Permission=visual_trigger_code(_Context->msg_Permission[_Context->language],strlen(_Context->msg_Permission[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+70,80,24,vfh[2],25,26,_Context->msg_Permission[_Context->language],strlen(_Context->msg_Permission[_Context->language]),_Context->value_Permission| 0x0030);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_IsExtern=visual_trigger_code(_Context->msg_IsExtern[_Context->language],strlen(_Context->msg_IsExtern[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+70,80,24,vfh[2],25,26,_Context->msg_IsExtern[_Context->language],strlen(_Context->msg_IsExtern[_Context->language]),_Context->value_IsExtern| 0x0030);
		}
	if (_Context->page_number == 2 ) {
	visual_select(_Context->x_WidgetProperties+390,_Context->y_WidgetProperties+80,288,90,vfh[1],27,0,parse_selection(WidgetSizesOptions,&_Context->value_CreateOptions),0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_Create_show(_Context);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_OnShowPage=visual_trigger_code(_Context->msg_OnShowPage[_Context->language],strlen(_Context->msg_OnShowPage[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnShowPage[_Context->language],strlen(_Context->msg_OnShowPage[_Context->language]),159,2);
		(void) on_OnShowPage_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnShowPage[_Context->language],strlen(_Context->msg_OnShowPage[_Context->language]),159,0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetShowOptions,&_Context->value_ShowOptions),0);
		}
	if (_Context->page_number == 3 ) {
	(void) on_Show_show(_Context);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_OnGetFocus=visual_trigger_code(_Context->msg_OnGetFocus[_Context->language],strlen(_Context->msg_OnGetFocus[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnGetFocus[_Context->language],strlen(_Context->msg_OnGetFocus[_Context->language]),231,2);
		(void) on_OnGetFocus_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnGetFocus[_Context->language],strlen(_Context->msg_OnGetFocus[_Context->language]),231,0);
		}
	if (_Context->page_number == 4 ) {
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetFocusOptions,&_Context->value_FocusOptions),0);
		}
	if (_Context->page_number == 4 ) {
	(void) on_GetFocus_show(_Context);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_OnEvent=visual_trigger_code(_Context->msg_OnEvent[_Context->language],strlen(_Context->msg_OnEvent[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnEvent[_Context->language],strlen(_Context->msg_OnEvent[_Context->language]),327,2);
		(void) on_OnEvent_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnEvent[_Context->language],strlen(_Context->msg_OnEvent[_Context->language]),327,0);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+90,140,16,vfh[2],27,0,_Context->msg_Auto3618[_Context->language],strlen(_Context->msg_Auto3618[_Context->language]),1025);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_MimoMove=visual_trigger_code(_Context->msg_MimoMove[_Context->language],strlen(_Context->msg_MimoMove[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+180,_Context->y_WidgetProperties+90,48,16,vfh[1],25,26,_Context->msg_MimoMove[_Context->language],strlen(_Context->msg_MimoMove[_Context->language]),_Context->value_MimoMove| 0x0030);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_MimoDown=visual_trigger_code(_Context->msg_MimoDown[_Context->language],strlen(_Context->msg_MimoDown[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+90,48,16,vfh[1],25,26,_Context->msg_MimoDown[_Context->language],strlen(_Context->msg_MimoDown[_Context->language]),_Context->value_MimoDown| 0x0030);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_MimoUp=visual_trigger_code(_Context->msg_MimoUp[_Context->language],strlen(_Context->msg_MimoUp[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+280,_Context->y_WidgetProperties+90,48,16,vfh[1],25,26,_Context->msg_MimoUp[_Context->language],strlen(_Context->msg_MimoUp[_Context->language]),_Context->value_MimoUp| 0x0030);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_MimoHold=visual_trigger_code(_Context->msg_MimoHold[_Context->language],strlen(_Context->msg_MimoHold[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+90,48,16,vfh[1],25,26,_Context->msg_MimoHold[_Context->language],strlen(_Context->msg_MimoHold[_Context->language]),_Context->value_MimoHold| 0x0030);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_MimoLeft=visual_trigger_code(_Context->msg_MimoLeft[_Context->language],strlen(_Context->msg_MimoLeft[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+400,_Context->y_WidgetProperties+90,16,16,vfh[1],25,26,_Context->msg_MimoLeft[_Context->language],strlen(_Context->msg_MimoLeft[_Context->language]),_Context->value_MimoLeft| 0x0030);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_WidgetProperties+180,_Context->y_WidgetProperties+70,196,16,vfh[2],16,22,_Context->msg_Auto3619[_Context->language],strlen(_Context->msg_Auto3619[_Context->language]),3);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_WidgetProperties+400,_Context->y_WidgetProperties+70,70,16,vfh[2],16,22,_Context->msg_Auto3620[_Context->language],strlen(_Context->msg_Auto3620[_Context->language]),3);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_MimoRight=visual_trigger_code(_Context->msg_MimoRight[_Context->language],strlen(_Context->msg_MimoRight[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+440,_Context->y_WidgetProperties+90,16,16,vfh[1],25,26,_Context->msg_MimoRight[_Context->language],strlen(_Context->msg_MimoRight[_Context->language]),_Context->value_MimoRight| 0x0030);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_MimoWheel=visual_trigger_code(_Context->msg_MimoWheel[_Context->language],strlen(_Context->msg_MimoWheel[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+90,16,16,vfh[1],25,26,_Context->msg_MimoWheel[_Context->language],strlen(_Context->msg_MimoWheel[_Context->language]),_Context->value_MimoWheel| 0x0030);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_MimoMiddle=visual_trigger_code(_Context->msg_MimoMiddle[_Context->language],strlen(_Context->msg_MimoMiddle[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+420,_Context->y_WidgetProperties+90,16,16,vfh[1],25,26,_Context->msg_MimoMiddle[_Context->language],strlen(_Context->msg_MimoMiddle[_Context->language]),_Context->value_MimoMiddle| 0x0030);
		}
	if (_Context->page_number == 5 ) {
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_EventOptions),0);
		}
	if (_Context->page_number == 5 ) {
	(void) on_Event_show(_Context);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_OnLoseFocus=visual_trigger_code(_Context->msg_OnLoseFocus[_Context->language],strlen(_Context->msg_OnLoseFocus[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnLoseFocus[_Context->language],strlen(_Context->msg_OnLoseFocus[_Context->language]),400,2);
		(void) on_OnLoseFocus_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnLoseFocus[_Context->language],strlen(_Context->msg_OnLoseFocus[_Context->language]),400,0);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_LoseOptions),0);
		}
	if (_Context->page_number == 6 ) {
	(void) on_LoseFocus_show(_Context);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_OnHidePage=visual_trigger_code(_Context->msg_OnHidePage[_Context->language],strlen(_Context->msg_OnHidePage[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnHidePage[_Context->language],strlen(_Context->msg_OnHidePage[_Context->language]),503,2);
		(void) on_OnHidePage_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnHidePage[_Context->language],strlen(_Context->msg_OnHidePage[_Context->language]),503,0);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetHideOptions,&_Context->value_HideOptions),0);
		}
	if (_Context->page_number == 7 ) {
	(void) on_Hide_show(_Context);
		}
	if (_Context->page_number == 8 ) {
	_Context->trigger_OnRemove=visual_trigger_code(_Context->msg_OnRemove[_Context->language],strlen(_Context->msg_OnRemove[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnRemove[_Context->language],strlen(_Context->msg_OnRemove[_Context->language]),567,2);
		(void) on_OnRemove_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnRemove[_Context->language],strlen(_Context->msg_OnRemove[_Context->language]),567,0);
		}
	if (_Context->page_number == 8 ) {
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_RemoveOptions),0);
		}
	if (_Context->page_number == 8 ) {
	(void) on_Remove_show(_Context);
		}
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710,540);

	return(0);
}

private int Auto3610_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing this button any changes made to the various parameters ";
			mptr[1]="will take effect and be saved to the widget.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Presser ce bouton pour valider toutes les modifications faites sur ";
			mptr[1]="cet objet.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3611_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "By pressing on this button the full screen source editor will be actived ";
			mptr[1]="for edition of the current forms method if you are on a form method ";
			mptr[2]="tab. ";
			mptr[3]=" If you are on the first tab, this window will be redrawn.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Presser ce bouton pour activer l'‚diteur plein ‚cran afin de modifier ";
			mptr[1]="le code de la m‚thode correspondante a l'onglet actif si vous ˆtes ";
			mptr[2]="sur un onglet de m‚thode.  ";
			mptr[3]=" Si vous ˆtes sur le premier onglet, cette fenˆtre sera rafraichie. ";
			mptr[4]="   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Toggle_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This switch allows the widget properties dialog box to be switched ";
			mptr[1]="between the new widget specific version and the previous generic widget ";
			mptr[2]=" version.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int NationalMessages_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This push button gives access to the National Language Messages dialog ";
			mptr[1]="box for consultation and modification of the different national messages ";
			mptr[2]="for the current widget.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Presser ce bouton pour acceder a la boite de dialog de l'editeur des ";
			mptr[1]="messages multinationales.     ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 2 : 
			{
			char * mptr[1];
			mptr[0] = "  ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int NationalHelptext_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This push button gives access to the National Language Help Texts ";
			mptr[1]="dialog box for consultation and modification of the different national ";
			mptr[2]="help texts for the current widget.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Presser ce bouton pour acceder a la boite de dialog de l'editeur des ";
			mptr[1]="textes d'aide en ligne multinationales.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3615_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the CANCEL button any modifications performed will be ";
			mptr[1]="discarded.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Presser ce bouton pour annuler toutes les modifications faites sur ";
			mptr[1]="cet objet.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This page presents the contextual collection of widget properties ";
			mptr[1]="for  inspection and eventual modification. ";
			mptr[2]=" ";
			mptr[3]=" For each individual widget type a specific inset page will be displayed ";
			mptr[4]="showing the relevant properties of the widget type.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce page vous presents les propriŠt‚s du widgets pour consultation ";
			mptr[1]="et modification.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int all_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = "Information concerning the previous widget properties inspection and ";
			mptr[1]="modification dialog box is available by following this link Widget Properties. This dialog frame will be displayed when the generic ";
			mptr[2]="widget properties collection has been activated by the corresponding ";
			mptr[3]="switch described elsewhere in this document. The version 1.1e of Sing distributed with the version 3.1e of abal 3 offers a new collection ";
			mptr[4]="of dialog boxs, one for each of the individual widget types. These ";
			mptr[5]="dialog boxs are described in separate documents and are accessible ";
			mptr[6]="from the links below.    ";
			return(visual_online_help(mptr,7));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 2 : 
			{
			char * mptr[1];
			mptr[0] = "   ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 3 : 
			{
			char * mptr[1];
			mptr[0] = "   ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 4 : 
			{
			char * mptr[1];
			mptr[0] = "  ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int select_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Information concerning the collection of widget properties  comprising ";
			mptr[1]="the select widget is available through the following link Select Widget Properties.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Select Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int frame_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "Information concerning the collection of widget properties  comprising ";
			mptr[1]="the various frame widget types is available through the following ";
			mptr[2]="link Inset, Outset, Ridge and Groove Frame Widget Properties   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Inset, Outset, Ridge and Groove Frame Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int edit_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Information particular to the collection of widget properties  comprising ";
			mptr[1]="the edit widget is available through the following link Edit Widget Properties   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Edit Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int button_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Information concerning the collection of widget properties  comprising ";
			mptr[1]="the push button widget is available through the following link Button Widget Properties   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int check_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Information concerning the collection of widget properties  comprising ";
			mptr[1]="the check box widget is available through the following link Check Widget Properties   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int data_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "Information concerning the collection of widget properties  describing ";
			mptr[1]="the complex data object widget is available through the following ";
			mptr[2]="link Data Widget Properties   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Data Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int fill_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Information concerning the collection of widget properties  comprising ";
			mptr[1]="the fill widget is available through the following link Fill Widget Properties   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Fill Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int form_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "Information concerning the collection of widget properties  describing ";
			mptr[1]="the data table or file list widget is available through the following ";
			mptr[2]="link Form Widget Properties   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Form Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int scroll_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Information concerning the collection of widget properties  comprising ";
			mptr[1]="the scroll bar widget is available through the following link Scroll Widget Properties   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Scroll Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int progress_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "Information concerning the collection of widget properties  comprising ";
			mptr[1]="the progression bar widget is available through the following link ";
			mptr[2]="Progress Widget Properties   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Progress Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int tabpage_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "Information concerning the collection of widget properties  comprising ";
			mptr[1]="the tab page and tab system widget is available through the following ";
			mptr[2]="link Tab Page Widget Properties   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Tab Page Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int radio_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Information concerning the collection of widget properties  comprising ";
			mptr[1]="the radio button widget is available through the following link Radio Button Widget Properties   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Radio Button Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int window_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Information concerning the collection of widget properties  describing ";
			mptr[1]="the window widget is available through the following link Window Widget Properties   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Window Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int text_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Information concerning the collection of widget properties  comprising ";
			mptr[1]="the text widget is available through the following link Text Widget Properties   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Text Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int image_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Information concerning the collection of widget properties  comprising ";
			mptr[1]="the image widget is available through the following link Image Widget Properties   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Image Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int line_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Information concerning the collection of widget properties  comprising ";
			mptr[1]="the line drawing widget is available through the following link Line Widget Properties   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Line Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int switch_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "Information concerning the collection of widget properties  comprising ";
			mptr[1]="the boolean switch widget is available through the following link ";
			mptr[2]="Switch Widget Properties   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Switch Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int graph_widget_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Information concerning the collection of widget properties  comprising ";
			mptr[1]="the data graph widget is available through the following link Graph Widget Properties   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Graph Widget Properties   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OnCreate_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[9];
			mptr[0] = "This page presents the text and properties of the widget method OnCreate. ";
			mptr[1]="  ";
			mptr[2]=" ";
			mptr[3]="This method will be generated and activated,  if text has been defined, ";
			mptr[4]=" directly after the allocation and parameter transfer mechanisms and ";
			mptr[5]="provides for application specific finalisation of the  construction ";
			mptr[6]="phase for the widget.  ";
			mptr[7]=" ";
			mptr[8]="   ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Permission_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[10];
			mptr[0] = " ";
			mptr[1]=" This switch allows the access permission of the component to be established. ";
			mptr[2]=" ";
			mptr[3]=" ";
			mptr[4]="All Function methods of Public component widgets will be described ";
			mptr[5]=" in the forms module external description file making them available ";
			mptr[6]="for use outside  of the parent form. Likewise for forms overlays, ";
			mptr[7]="Function methods will be made available via the overlay method table. ";
			mptr[8]=" ";
			mptr[9]="    ";
			return(visual_online_help(mptr,10));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsExtern_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[10];
			mptr[0] = " ";
			mptr[1]=" This switch allows the access permission of the component to be established. ";
			mptr[2]=" ";
			mptr[3]=" ";
			mptr[4]="All Function methods of Public component widgets will be described ";
			mptr[5]=" in the forms module external description file making them available ";
			mptr[6]="for use outside  of the parent form. Likewise for forms overlays, ";
			mptr[7]="Function methods will be made available via the overlay method table. ";
			mptr[8]=" ";
			mptr[9]="    ";
			return(visual_online_help(mptr,10));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CreateOptions_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[20];
			mptr[0] = "This combo selection field offers control in two areas :   ";
			mptr[1]="  ";
			mptr[2]=" -   ";
			mptr[3]=" ";
			mptr[4]="Method Instance Type : Function or Inline  ";
			mptr[5]=" ";
			mptr[6]="Inline methods are generated to the source region of their activation ";
			mptr[7]="whilst function methods allow event method invokation from within ";
			mptr[8]="methods of other widgets.   ";
			mptr[9]=" -   ";
			mptr[10]=" ";
			mptr[11]="Zone Definition Type : Constant or Variable  ";
			mptr[12]=" ";
			mptr[13]="Position and Dimension information is normally generated  as and made ";
			mptr[14]="available through constants to the various library  function calls ";
			mptr[15]="and widget atributs (this.x,y,w,h). In certain cases it may be desirable ";
			mptr[16]="to be able to change their positions or dimensions during the operation ";
			mptr[17]="of the visual form. In this  case the variable option should be activated. ";
			mptr[18]="  ";
			mptr[19]="   ";
			return(visual_online_help(mptr,20));
			}
			break;
		case 1 : 
			{
			char * mptr[19];
			mptr[0] = "Ce combo selection permet de definir les options suivants :  ";
			mptr[1]="  ";
			mptr[2]="  ";
			mptr[3]=" - La nature de la methode CREATE d'un composant peut etre INLINE ou ";
			mptr[4]="FUNCTION. Lorsque ceci a ‚t‚ declar‚ de type INLINE, pendant la phase ";
			mptr[5]="de production de code, des eventuelles instructions de ce methode ";
			mptr[6]="vont se faire generer dans la methode ONCREATE du formulaire h“te. ";
			mptr[7]=" ";
			mptr[8]=" Dans le cas contraire, FUNCTION, il y aura la  production d'une procedure ";
			mptr[9]=" specifique pour encapsuler ces instructions. ";
			mptr[10]="  ";
			mptr[11]=" - Par defaut les informations de positionnement et de dimensions des ";
			mptr[12]="composents sont produits en tant qu'expressions integers constantes. ";
			mptr[13]="En consequance des composants sont fixe. ";
			mptr[14]="Ici on peut choisir d'activer la generation de variables pour  contenir ";
			mptr[15]="ces informations pour le composant specique qui a pour consequence ";
			mptr[16]="de permettre la deplacement de ce composant pendant l'execution. ";
			mptr[17]="  ";
			mptr[18]="     ";
			return(visual_online_help(mptr,19));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Create_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This field allows the method text of the construction method to be ";
			mptr[1]="edited using the standard application text editor.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OnShowPage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[10];
			mptr[0] = "This page presents the text and properties of the widget method OnShow. ";
			mptr[1]="  ";
			mptr[2]=" ";
			mptr[3]="This method will be generated and activated, if text has been defined, ";
			mptr[4]=" from the forms event method of the same name.                    ";
			mptr[5]=" ";
			mptr[6]="Tab View widgets will control the display of their sub components ";
			mptr[7]=" ";
			mptr[8]=" ";
			mptr[9]="   ";
			return(visual_online_help(mptr,10));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ShowOptions_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[25];
			mptr[0] = "This combo selection field offers control in two areas :   ";
			mptr[1]="  ";
			mptr[2]=" -   ";
			mptr[3]=" ";
			mptr[4]="Method Instance Type : Function or Inline  ";
			mptr[5]=" ";
			mptr[6]="Inline methods are generated to the source region of their activation ";
			mptr[7]="whilst function methods allow event method invocation from within ";
			mptr[8]="methods of other widgets.   ";
			mptr[9]=" -   ";
			mptr[10]=" ";
			mptr[11]="Widget Display Scheduling : Automatic : Conditional  ";
			mptr[12]=" ";
			mptr[13]="Widgets for which the display sheduling has been set to  automatic ";
			mptr[14]="will be displayed during the parent form event method of the same ";
			mptr[15]="name.  ";
			mptr[16]=" ";
			mptr[17]="When sheduling is set to conditional then display will be inhibited ";
			mptr[18]="and must be performed as required during widget method text or by ";
			mptr[19]="other programming means.  ";
			mptr[20]=" ";
			mptr[21]="This feature when combined with the variable dimensioning and positioning ";
			mptr[22]="available through the Create method properties allows the construction of versitile documnet ";
			mptr[23]="generator type programs.  ";
			mptr[24]="   ";
			return(visual_online_help(mptr,25));
			}
			break;
		case 1 : 
			{
			char * mptr[11];
			mptr[0] = " ";
			mptr[1]="  ";
			mptr[2]=" - La nature de la methode SHOW d'un composant peut etre INLINE ou FUNCTION. ";
			mptr[3]="Lorsque ceci a ‚t‚ declar‚ de type INLINE, pendant la phase de production ";
			mptr[4]="de code, des eventuelles instructions de ce methode vont se faire ";
			mptr[5]="generer dans la methode ONSHOW du formulaire h“te.  ";
			mptr[6]=" Dans le cas contraire, FUNCTION, il y aura la  production d'une procedure ";
			mptr[7]=" specifique pour encapsuler ces instructions. ";
			mptr[8]="  ";
			mptr[9]=" -   ";
			mptr[10]="   ";
			return(visual_online_help(mptr,11));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Show_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This field allows the method text of the display method to be edited ";
			mptr[1]="using the standard application text editor.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OnGetFocus_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[8];
			mptr[0] = "This page presents the text and properties of the widget method OnGetFocus. ";
			mptr[1]="  ";
			mptr[2]=" ";
			mptr[3]="This method will be generated and activated, if text has been defined, ";
			mptr[4]=" when the widget receives the keyboard focus               from the ";
			mptr[5]="parent form focus control mechanisms.  ";
			mptr[6]=" ";
			mptr[7]="   ";
			return(visual_online_help(mptr,8));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FocusOptions_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[15];
			mptr[0] = "This combo selection field offers control in two areas :   ";
			mptr[1]="  ";
			mptr[2]=" -   ";
			mptr[3]=" ";
			mptr[4]="Method Instance Type : Function or Inline  ";
			mptr[5]=" ";
			mptr[6]="Inline methods are generated to the source region of their activation ";
			mptr[7]="whilst function methods allow event method invokation from within ";
			mptr[8]="methods of other widgets.   ";
			mptr[9]=" -   ";
			mptr[10]=" ";
			mptr[11]=" Method Focus : Active or Inactive When this option is set to active ";
			mptr[12]="the widget will be included in the focus control mechanisms of its ";
			mptr[13]="parent form. Otherwise it will be excluded from receiving focus.  ";
			mptr[14]="   ";
			return(visual_online_help(mptr,15));
			}
			break;
		case 1 : 
			{
			char * mptr[11];
			mptr[0] = " ";
			mptr[1]="  ";
			mptr[2]=" - La nature de la methode FOCUS d'un composant peut etre INLINE ou FUNCTION. ";
			mptr[3]="Lorsque ceci a ‚t‚ declar‚ de type INLINE, pendant la phase de production ";
			mptr[4]="de code, des eventuelles instructions de ce methode vont se faire ";
			mptr[5]="generer dans la methode ONFOCUS du formulaire h“te.  ";
			mptr[6]=" Dans le cas contraire, FUNCTION, il y aura la  production d'une procedure ";
			mptr[7]=" specifique pour encapsuler ces instructions. ";
			mptr[8]="  ";
			mptr[9]=" -   ";
			mptr[10]="   ";
			return(visual_online_help(mptr,11));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int GetFocus_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This field allows the method text of the focus reception method to ";
			mptr[1]="be edited using the standard application text editor.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OnEvent_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[13];
			mptr[0] = "This page presents the text and properties of the widget method OnEvent. ";
			mptr[1]="  ";
			mptr[2]=" ";
			mptr[3]="This method will be generated and activated, if text has been defined, ";
			mptr[4]=" from the forms event method of the same name.                    ";
			mptr[5]=" ";
			mptr[6]="These event methods are also suitable for interwidget signal mechanisms. ";
			mptr[7]=" ";
			mptr[8]=" ";
			mptr[9]="For Button and Tab View Widgets of Overlay type , this method will ";
			mptr[10]="encapculate the overlay attachment and activation mechanisms.  ";
			mptr[11]=" ";
			mptr[12]="   ";
			return(visual_online_help(mptr,13));
			}
			break;
		case 1 : 
			{
			char * mptr[11];
			mptr[0] = " ";
			mptr[1]="  ";
			mptr[2]=" - La nature de la methode EVENT d'un composant peut etre INLINE ou FUNCTION. ";
			mptr[3]="Lorsque ceci a ‚t‚ declar‚ de type INLINE, pendant la phase de production ";
			mptr[4]="de code, des eventuelles instructions de ce methode vont se faire ";
			mptr[5]="generer dans la methode ONFOCUS du formulaire h“te.  ";
			mptr[6]=" Dans le cas contraire, FUNCTION, il y aura la  production d'une procedure ";
			mptr[7]=" specifique pour encapsuler ces instructions. ";
			mptr[8]="  ";
			mptr[9]=" -   ";
			mptr[10]="   ";
			return(visual_online_help(mptr,11));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MimoMove_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "When this switch is selected the widget specific event method  will ";
			mptr[1]="be invoked upon reception of MOUSE MOVE events.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MimoDown_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "When this switch is selected the widget specific event method  will ";
			mptr[1]="be invoked upon reception of MOUSE DOWN events.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MimoUp_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "When this switch is selected the widget specific event method  will ";
			mptr[1]="be invoked upon reception of MOUSE UP events.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MimoHold_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "When this switch is selected the widget specific event method  will ";
			mptr[1]="be invoked upon reception of MOUSE IS DOWN events.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MimoLeft_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = " ";
			mptr[1]=" This switch activates reception of mouse LEFT button events for the ";
			mptr[2]="parent widget.  ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = " ";
			mptr[1]=" Ce switch permet d'activer la reception d'evenements bouton GAUCHE ";
			mptr[2]="du souris pour le composant parent.  ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MimoRight_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = " ";
			mptr[1]=" This switch activates reception of mouse RIGHT button events for ";
			mptr[2]="the parent widget.  ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = " ";
			mptr[1]=" Ce switch permet d'activer la reception d'evenements bouton DROITE ";
			mptr[2]="du souris pour le composant parent.  ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MimoWheel_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = " ";
			mptr[1]=" This switch allows reception of mouse WHEEL events for the parent ";
			mptr[2]="widget.  ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = " ";
			mptr[1]=" Ce switch permet d'activer la reception d'evenements du souris en ";
			mptr[2]="provenance du MOLETTE pour le composant parent.  ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MimoMiddle_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = " ";
			mptr[1]=" This switch activates reception of mouse MIDDLE button events for ";
			mptr[2]="the parent widget.  ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = " ";
			mptr[1]=" Ce switch permet d'activer la reception d'evenements bouton MILEU ";
			mptr[2]="du souris pour le composant parent.  ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int EventOptions_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[16];
			mptr[0] = "This combo selection field offers control in two areas :   ";
			mptr[1]="  ";
			mptr[2]=" -   ";
			mptr[3]=" ";
			mptr[4]="Method Instance Type : Function or Inline  ";
			mptr[5]=" ";
			mptr[6]="Inline methods are generated to the source region of their activation ";
			mptr[7]="whilst function methods allow event method invocation from within ";
			mptr[8]="methods of other widgets.   ";
			mptr[9]=" -   ";
			mptr[10]=" ";
			mptr[11]=" Method Event Dispatch : Active or Inactive When this option is set ";
			mptr[12]="to active the widget will be included in the event dispatching mechanisms ";
			mptr[13]="of its parent form. Otherwise it will be oblivious to parent form ";
			mptr[14]="events.  ";
			mptr[15]="   ";
			return(visual_online_help(mptr,16));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Event_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This field allows the method text of the event handling method to ";
			mptr[1]="be edited using the standard application text editor.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OnLoseFocus_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[8];
			mptr[0] = "This page presents the text and properties of the widget method OnLoseFocus. ";
			mptr[1]="  ";
			mptr[2]=" ";
			mptr[3]="This method will be generated and activated, if text has been defined, ";
			mptr[4]=" when the widget relinquishes the keyboard focus               to ";
			mptr[5]="the parent form focus control mechanisms.  ";
			mptr[6]=" ";
			mptr[7]="   ";
			return(visual_online_help(mptr,8));
			}
			break;
		case 1 : 
			{
			char * mptr[12];
			mptr[0] = " ";
			mptr[1]="  ";
			mptr[2]=" - La nature de la methode LOSEFOCUS d'un composant peut etre INLINE ";
			mptr[3]="ou FUNCTION. Lorsque ceci a ‚t‚ declar‚ de type INLINE, pendant la ";
			mptr[4]="phase de production de code, des eventuelles instructions de ce methode ";
			mptr[5]="vont se faire generer dans la methode ONFOCUS du formulaire h“te. ";
			mptr[6]=" ";
			mptr[7]=" Dans le cas contraire, FUNCTION, il y aura la  production d'une procedure ";
			mptr[8]=" specifique pour encapsuler ces instructions. ";
			mptr[9]="  ";
			mptr[10]=" -   ";
			mptr[11]="   ";
			return(visual_online_help(mptr,12));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int LoseOptions_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[15];
			mptr[0] = "This combo selection field offers control in two areas :   ";
			mptr[1]="  ";
			mptr[2]=" -   ";
			mptr[3]=" ";
			mptr[4]="Method Instance Type : Function or Inline  ";
			mptr[5]=" ";
			mptr[6]="Inline methods are generated to the source region of their activation ";
			mptr[7]="whilst function methods allow event method invocation from within ";
			mptr[8]="methods of other widgets.   ";
			mptr[9]=" -   ";
			mptr[10]=" ";
			mptr[11]=" Method Focus : Active or Inactive When this option is set to active ";
			mptr[12]="the widget will be included in the focus control mechanisms of its ";
			mptr[13]="parent form. Otherwise it will be excluded from receiving focus.  ";
			mptr[14]="   ";
			return(visual_online_help(mptr,15));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int LoseFocus_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This field allows the method text of the focus release method to be ";
			mptr[1]="edited using the standard application text editor.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OnHidePage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = "This page presents the text and properties of the widget method OnHide. ";
			mptr[1]="  ";
			mptr[2]=" ";
			mptr[3]="This method will be generated and activated, if text has been defined, ";
			mptr[4]=" from the forms event method of the same name.                    ";
			mptr[5]=" ";
			mptr[6]="   ";
			return(visual_online_help(mptr,7));
			}
			break;
		case 1 : 
			{
			char * mptr[11];
			mptr[0] = " ";
			mptr[1]="  ";
			mptr[2]=" - La nature de la methode HIDE d'un composant peut etre INLINE ou FUNCTION. ";
			mptr[3]="Lorsque ceci a ‚t‚ declar‚ de type INLINE, pendant la phase de production ";
			mptr[4]="de code, des eventuelles instructions de ce methode vont se faire ";
			mptr[5]="generer dans la methode ONHIDE du formulaire h“te.  ";
			mptr[6]=" Dans le cas contraire, FUNCTION, il y aura la  production d'une procedure ";
			mptr[7]=" specifique pour encapsuler ces instructions. ";
			mptr[8]="  ";
			mptr[9]=" -   ";
			mptr[10]="   ";
			return(visual_online_help(mptr,11));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int HideOptions_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[10];
			mptr[0] = "This combo selection field offers control of :  ";
			mptr[1]="  ";
			mptr[2]=" -   ";
			mptr[3]=" ";
			mptr[4]="Method Instance Type : Function or Inline  ";
			mptr[5]=" ";
			mptr[6]="Inline methods are generated to the source region of their activation ";
			mptr[7]="whilst function methods allow event method invocation from within ";
			mptr[8]="methods of other widgets.   ";
			mptr[9]="           ";
			return(visual_online_help(mptr,10));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Hide_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This field allows the method text of this event method  to be edited ";
			mptr[1]="using the standard application text editor.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OnRemove_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[11];
			mptr[0] = "This page presents the text and properties of the widget method OnRemove. ";
			mptr[1]="  ";
			mptr[2]=" ";
			mptr[3]="This method will be generated and activated,  if text has been defined, ";
			mptr[4]=" directly before the outbound parameter transfer mechanisms and liberation. ";
			mptr[5]="  ";
			mptr[6]=" ";
			mptr[7]="It provides for application specific preliminaries of the destruction ";
			mptr[8]="phase for the widget.  ";
			mptr[9]=" ";
			mptr[10]="   ";
			return(visual_online_help(mptr,11));
			}
			break;
		case 1 : 
			{
			char * mptr[12];
			mptr[0] = " ";
			mptr[1]="  ";
			mptr[2]=" - La nature de la methode REMOVE d'un composant peut etre INLINE ou ";
			mptr[3]="FUNCTION. Lorsque ceci a ‚t‚ declar‚ de type INLINE, pendant la phase ";
			mptr[4]="de production de code, des eventuelles instructions de ce methode ";
			mptr[5]="vont se faire generer dans la methode ONREMOVE du formulaire h“te. ";
			mptr[6]=" ";
			mptr[7]=" Dans le cas contraire, FUNCTION, il y aura la  production d'une procedure ";
			mptr[8]=" specifique pour encapsuler ces instructions. ";
			mptr[9]="  ";
			mptr[10]=" -   ";
			mptr[11]="   ";
			return(visual_online_help(mptr,12));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int RemoveOptions_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[10];
			mptr[0] = "This combo selection field offers control of :  ";
			mptr[1]="  ";
			mptr[2]=" -   ";
			mptr[3]=" ";
			mptr[4]="Method Instance Type : Function or Inline  ";
			mptr[5]=" ";
			mptr[6]="Inline methods are generated to the source region of their activation ";
			mptr[7]="whilst function methods allow event method invocation from within ";
			mptr[8]="methods of other widgets.   ";
			mptr[9]="   ";
			return(visual_online_help(mptr,10));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Remove_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This field allows the method text of the destruction method to be ";
			mptr[1]="edited using the standard application text editor.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int WidgetPropertiesaction(struct accept_widget_properties_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_widget_properties_hide(_Context);

		_Context->x_WidgetProperties += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_WidgetProperties < 0) { _Context->x_WidgetProperties=0; }
		_Context->y_WidgetProperties += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_WidgetProperties < 0) { _Context->y_WidgetProperties=0; }
			accept_widget_properties_show(_Context);

		visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710,540);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3610_event(struct accept_widget_properties_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3611_event(struct accept_widget_properties_context * _Context) {
		accept_widget_properties_hide(_Context);
;
	switch(_Context->page_number){
	case 2:
	use_editor(_Context->buffer_Create,-1);
	visual_freeze();
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Create */
	/* OnCreate */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 2;
	accept_widget_properties_show(_Context);
	_Context->focus_item=9;
	accept_widget_properties_show(_Context);
	_Context->focus_item=13;
;
	break;
	case 3:
	use_editor(_Context->buffer_Show,-1);
	visual_freeze();
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Show */
	/* OnShowPage */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 3;
	accept_widget_properties_show(_Context);
	_Context->focus_item=14;
	accept_widget_properties_show(_Context);
	_Context->focus_item=16;
;
	break;
	case 4:
	use_editor(_Context->buffer_GetFocus,-1);
	visual_freeze();
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* GetFocus */
	/* OnGetFocus */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 4;
	accept_widget_properties_show(_Context);
	_Context->focus_item=17;
	accept_widget_properties_show(_Context);
	_Context->focus_item=19;
;
	break;
	case 5:
	use_editor(_Context->buffer_Event,-1);
	visual_freeze();
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Event */
	/* OnEvent */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 5;
	accept_widget_properties_show(_Context);
	_Context->focus_item=20;
	accept_widget_properties_show(_Context);
	_Context->focus_item=30;
;
	break;
	case 6:
	use_editor(_Context->buffer_LoseFocus,-1);
	visual_freeze();
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* LoseFocus */
	/* OnLoseFocus */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 6;
	accept_widget_properties_show(_Context);
	_Context->focus_item=31;
	accept_widget_properties_show(_Context);
	_Context->focus_item=33;
;
	break;
	case 7:
	use_editor(_Context->buffer_Hide,-1);
	visual_freeze();
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Hide */
	/* OnHidePage */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 7;
	accept_widget_properties_show(_Context);
	_Context->focus_item=34;
	accept_widget_properties_show(_Context);
	_Context->focus_item=36;
;
	break;
	case 8:
	use_editor(_Context->buffer_Remove,-1);
	visual_freeze();
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Remove */
	/* OnRemove */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 8;
	accept_widget_properties_show(_Context);
	_Context->focus_item=37;
	accept_widget_properties_show(_Context);
	_Context->focus_item=39;
;
	break;
	default:
	visual_freeze();
		accept_widget_properties_show(_Context);
;
		/* Widget */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 1;
	accept_widget_properties_show(_Context);
	_Context->focus_item=8;
;
	}
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710+10,540+10);
	if(FormZoomCheck()){return(27);}
	return(-1);
}
private int on_Toggle_event(struct accept_widget_properties_context * _Context) {
	if(change_widget_view(_Context->value_Toggle)!=0){
		/* Widget */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 1;
	accept_widget_properties_show(_Context);
	_Context->focus_item=8;
;
	}
	return(-1);
}
private int on_NationalMessages_event(struct accept_widget_properties_context * _Context) {
		accept_widget_properties_hide(_Context);
;
	edit_national_messages();
		/* Widget */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 1;
	accept_widget_properties_show(_Context);
	_Context->focus_item=8;
;
	return(-1);
}
private int on_NationalHelptext_event(struct accept_widget_properties_context * _Context) {
		accept_widget_properties_hide(_Context);
;
	edit_national_helptext();
		/* Widget */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 1;
	accept_widget_properties_show(_Context);
	_Context->focus_item=8;
;
	return(-1);
}
private int on_Auto3615_event(struct accept_widget_properties_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_widget_properties_event(
struct accept_widget_properties_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3610 == mb ) return(2);
		if (_Context->trigger_Auto3611 == mb ) return(3);
		if (_Context->trigger_Toggle == mb ) return(4);
		if (_Context->trigger_NationalMessages == mb ) return(5);
		if (_Context->trigger_NationalHelptext == mb ) return(6);
		if (_Context->trigger_Auto3615 == mb ) return(7);
		if (_Context->trigger_Widget == mb ) return(8);
		if (_Context->trigger_OnCreate == mb ) return(9);
		if (_Context->trigger_Permission == mb ) return(10);
		if (_Context->trigger_IsExtern == mb ) return(11);
		if (_Context->trigger_OnShowPage == mb ) return(14);
		if (_Context->trigger_OnGetFocus == mb ) return(17);
		if (_Context->trigger_OnEvent == mb ) return(20);
		if (_Context->trigger_MimoMove == mb ) return(21);
		if (_Context->trigger_MimoDown == mb ) return(22);
		if (_Context->trigger_MimoUp == mb ) return(23);
		if (_Context->trigger_MimoHold == mb ) return(24);
		if (_Context->trigger_MimoLeft == mb ) return(25);
		if (_Context->trigger_MimoRight == mb ) return(26);
		if (_Context->trigger_MimoWheel == mb ) return(27);
		if (_Context->trigger_MimoMiddle == mb ) return(28);
		if (_Context->trigger_OnLoseFocus == mb ) return(31);
		if (_Context->trigger_OnHidePage == mb ) return(34);
		if (_Context->trigger_OnRemove == mb ) return(37);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x1031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_WidgetProperties+689) )  
	&&  (my >= (_Context->y_WidgetProperties+4) )  
	&&  (mx <= (_Context->x_WidgetProperties+706) )  
	&&  (my <= (_Context->y_WidgetProperties+20) )) {
		return(1);	/* WidgetProperties */

		}
	if ((mx >= (_Context->x_WidgetProperties+673) )  
	&&  (my >= (_Context->y_WidgetProperties+4) )  
	&&  (mx <= (_Context->x_WidgetProperties+690) )  
	&&  (my <= (_Context->y_WidgetProperties+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vwidget.htm");
			};
		return(-1);	/* WidgetProperties */

		}
	if ((mx >= (_Context->x_WidgetProperties+657) )  
	&&  (my >= (_Context->y_WidgetProperties+4) )  
	&&  (mx <= (_Context->x_WidgetProperties+674) )  
	&&  (my <= (_Context->y_WidgetProperties+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_widget_properties_show(_Context);
		return(-1);	/* WidgetProperties */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_WidgetProperties+4) )  
		&&  (my >= (_Context->y_WidgetProperties+4) )  
		&&  (mx <= (_Context->x_WidgetProperties+642) )  
		&&  (my <= (_Context->y_WidgetProperties+20) )) {
			return( WidgetPropertiesaction(_Context) );
			}
		}
	if (( mx >= (_Context->x_WidgetProperties+20) ) 
	&&  ( my >= (_Context->y_WidgetProperties+480) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+20+56) ) 
	&&  ( my <= (_Context->y_WidgetProperties+480+48))) {
		return(2); /* Auto3610 */
		}
	if (( mx >= (_Context->x_WidgetProperties+120) ) 
	&&  ( my >= (_Context->y_WidgetProperties+480) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+120+56) ) 
	&&  ( my <= (_Context->y_WidgetProperties+480+48))) {
		return(3); /* Auto3611 */
		}
	if (( mx >= (_Context->x_WidgetProperties+87) ) 
	&&  ( my >= (_Context->y_WidgetProperties+494) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+87+24) ) 
	&&  ( my <= (_Context->y_WidgetProperties+494+26))) {
		return(4); /* Toggle */
		}
	if (( mx >= (_Context->x_WidgetProperties+270) ) 
	&&  ( my >= (_Context->y_WidgetProperties+480) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+270+56) ) 
	&&  ( my <= (_Context->y_WidgetProperties+480+48))) {
		return(5); /* NationalMessages */
		}
	if (( mx >= (_Context->x_WidgetProperties+450) ) 
	&&  ( my >= (_Context->y_WidgetProperties+480) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+450+56) ) 
	&&  ( my <= (_Context->y_WidgetProperties+480+48))) {
		return(6); /* NationalHelptext */
		}
	if (( mx >= (_Context->x_WidgetProperties+630) ) 
	&&  ( my >= (_Context->y_WidgetProperties+480) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+630+56) ) 
	&&  ( my <= (_Context->y_WidgetProperties+480+48))) {
		return(7); /* Auto3615 */
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+80) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(8); /* Widget */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+81) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+158) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(9); /* OnCreate */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+70) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+80) ) 
		&&  ( my <= (_Context->y_WidgetProperties+70+24))) {
			return(10); /* Permission */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_WidgetProperties+110) ) 
		&&  ( my >= (_Context->y_WidgetProperties+70) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+110+80) ) 
		&&  ( my <= (_Context->y_WidgetProperties+70+24))) {
			return(11); /* IsExtern */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_WidgetProperties+390+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+390+288) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(12); /* CreateOptions */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(13); /* Create */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+159) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+230) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(14); /* OnShowPage */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(15); /* ShowOptions */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(16); /* Show */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+231) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+326) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(17); /* OnGetFocus */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(18); /* FocusOptions */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(19); /* GetFocus */
			}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+327) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+399) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(20); /* OnEvent */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+180) ) 
		&&  ( my >= (_Context->y_WidgetProperties+90) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+180+48) ) 
		&&  ( my <= (_Context->y_WidgetProperties+90+16))) {
			return(21); /* MimoMove */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+230) ) 
		&&  ( my >= (_Context->y_WidgetProperties+90) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+230+48) ) 
		&&  ( my <= (_Context->y_WidgetProperties+90+16))) {
			return(22); /* MimoDown */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+280) ) 
		&&  ( my >= (_Context->y_WidgetProperties+90) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+280+48) ) 
		&&  ( my <= (_Context->y_WidgetProperties+90+16))) {
			return(23); /* MimoUp */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+330) ) 
		&&  ( my >= (_Context->y_WidgetProperties+90) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+330+48) ) 
		&&  ( my <= (_Context->y_WidgetProperties+90+16))) {
			return(24); /* MimoHold */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+400) ) 
		&&  ( my >= (_Context->y_WidgetProperties+90) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+400+16) ) 
		&&  ( my <= (_Context->y_WidgetProperties+90+16))) {
			return(25); /* MimoLeft */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+440) ) 
		&&  ( my >= (_Context->y_WidgetProperties+90) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+440+16) ) 
		&&  ( my <= (_Context->y_WidgetProperties+90+16))) {
			return(26); /* MimoRight */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+460) ) 
		&&  ( my >= (_Context->y_WidgetProperties+90) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+460+16) ) 
		&&  ( my <= (_Context->y_WidgetProperties+90+16))) {
			return(27); /* MimoWheel */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+420) ) 
		&&  ( my >= (_Context->y_WidgetProperties+90) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+420+16) ) 
		&&  ( my <= (_Context->y_WidgetProperties+90+16))) {
			return(28); /* MimoMiddle */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(29); /* EventOptions */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(30); /* Event */
			}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+400) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+502) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(31); /* OnLoseFocus */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(32); /* LoseOptions */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(33); /* LoseFocus */
			}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+503) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+566) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(34); /* OnHidePage */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(35); /* HideOptions */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(36); /* Hide */
			}
		}
	if (_Context->page_number == 8 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+567) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+652) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(37); /* OnRemove */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(38); /* RemoveOptions */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(39); /* Remove */
			}
		}

	return(-1);
}


public	int	accept_widget_properties_losefocus(struct accept_widget_properties_context * _Context)
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
		case 6 : 
			break;
		case 7 : 
			break;
		case 8 : 
			break;

		}
	return(0);

}
private int on_Widget_getfocus(struct accept_widget_properties_context * _Context) {
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	if(use_all_widget()){
		_Context->keycode = vwall_focus(_Context->all_widget);
;
	}
	else{
	switch(*((int*)pSpecificWidgetProperties->pWidgetClass)){
	case _FILL_FRAME:
		_Context->keycode = vwfill_focus(_Context->fill_widget);
;
	break;
	case _OUTSET_FRAME:
	case _INSET_FRAME:
	case _RIDGE_FRAME:
	case _GROOVE_FRAME:
		_Context->keycode = vwframe_focus(_Context->frame_widget);
;
	break;
	case _EDIT_FRAME:
		_Context->keycode = vwedit_focus(_Context->edit_widget);
;
	break;
	case _TEXT_FRAME:
		_Context->keycode = vwtext_focus(_Context->text_widget);
;
	break;
	case _IMAGE_FRAME:
		_Context->keycode = vwimage_focus(_Context->image_widget);
;
	break;
	case _LINE_FRAME:
		_Context->keycode = vwline_focus(_Context->line_widget);
;
	break;
	case _BUTTON_FRAME:
		_Context->keycode = vwbutton_focus(_Context->button_widget);
;
	break;
	case _WINDOW_FRAME:
		_Context->keycode = vwwindow_focus(_Context->window_widget);
;
	break;
	case _TAB_FRAME:
		_Context->keycode = vwtabpage_focus(_Context->tabpage_widget);
;
	break;
	case _CHECK_FRAME:
		_Context->keycode = vwcheck_focus(_Context->check_widget);
;
	break;
	case _RADIO_FRAME:
		_Context->keycode = vwradio_focus(_Context->radio_widget);
;
	break;
	case _SELECT_FRAME:
		_Context->keycode = vwselect_focus(_Context->select_widget);
;
	break;
	case _FORM_FRAME:
		_Context->keycode = vwform_focus(_Context->form_widget);
;
	break;
	case _SCROLL_FRAME:
		_Context->keycode = vwscroll_focus(_Context->scroll_widget);
;
	break;
	case _PROGRESS_FRAME:
		_Context->keycode = vwprogress_focus(_Context->progress_widget);
;
	break;
	case _SWITCH_FRAME:
		_Context->keycode = vwswitch_focus(_Context->switch_widget);
;
	break;
	case _GRAPH_FRAME:
		_Context->keycode = vwgraph_focus(_Context->graph_widget);
;
	break;
	case _DATA_FRAME:
		_Context->keycode = vwdata_focus(_Context->data_widget);
;
	break;
	case _CUT_FRAME:
	default:
		_Context->keycode = vwall_focus(_Context->all_widget);
;
	break;
	}
	}
	if(_Context->keycode!=26){
	return(_Context->keycode);
	}
	else{
		/* Widget */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 1;
	accept_widget_properties_show(_Context);
	_Context->focus_item=8;
;
	return(0);
	}
	return(-1);
}
private int on_Create_getfocus(struct accept_widget_properties_context * _Context) {
	return(focus_window_editor());
	return(-1);
}
private int on_Show_getfocus(struct accept_widget_properties_context * _Context) {
	return(focus_window_editor());
	return(-1);
}
private int on_GetFocus_getfocus(struct accept_widget_properties_context * _Context) {
	return(focus_window_editor());
	return(-1);
}
private int on_Event_getfocus(struct accept_widget_properties_context * _Context) {
	return(focus_window_editor());
	return(-1);
}
private int on_LoseFocus_getfocus(struct accept_widget_properties_context * _Context) {
	return(focus_window_editor());
	return(-1);
}
private int on_Hide_getfocus(struct accept_widget_properties_context * _Context) {
	return(focus_window_editor());
	return(-1);
}
private int on_Remove_getfocus(struct accept_widget_properties_context * _Context) {
	return(focus_window_editor());
	return(-1);
}


public	int	accept_widget_properties_focus(struct accept_widget_properties_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto3610 */
				_Context->trigger_Auto3610=visual_trigger_code(_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]));
				visual_button(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3610=visual_trigger_code(_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]));
	visual_button(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]),1040);
				break;
			case	0x4 :
				/* Toggle */
				visual_switch(_Context->x_WidgetProperties+87,_Context->y_WidgetProperties+494,24,26,vfh[2],40,14,_Context->msg_Toggle[_Context->language],strlen(_Context->msg_Toggle[_Context->language]),(_Context->value_Toggle | 2 | 0x0030 ));
				_Context->keycode = visual_getch();
				_Context->trigger_Toggle=visual_trigger_code(_Context->msg_Toggle[_Context->language],strlen(_Context->msg_Toggle[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+87,_Context->y_WidgetProperties+494,24,26,vfh[2],40,14,_Context->msg_Toggle[_Context->language],strlen(_Context->msg_Toggle[_Context->language]),_Context->value_Toggle| 0x0030);
				break;
			case	0x7 :
				/* Auto3615 */
				_Context->trigger_Auto3615=visual_trigger_code(_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]));
				visual_button(_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3615=visual_trigger_code(_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]));
	visual_button(_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]),1040);
				break;
			case	0x8 :
				/* Widget */
				if (_Context->page_number == 1 ) {
					_Context->keycode = on_Widget_getfocus(_Context);
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x9 :
				/* OnCreate */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xa :
				/* Permission */
				if (_Context->page_number == 2 ) {
				visual_switch(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+70,80,24,vfh[2],25,26,_Context->msg_Permission[_Context->language],strlen(_Context->msg_Permission[_Context->language]),(_Context->value_Permission | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
					_Context->trigger_Permission=visual_trigger_code(_Context->msg_Permission[_Context->language],strlen(_Context->msg_Permission[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+70,80,24,vfh[2],25,26,_Context->msg_Permission[_Context->language],strlen(_Context->msg_Permission[_Context->language]),_Context->value_Permission| 0x0030);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* IsExtern */
				if (_Context->page_number == 2 ) {
				visual_switch(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+70,80,24,vfh[2],25,26,_Context->msg_IsExtern[_Context->language],strlen(_Context->msg_IsExtern[_Context->language]),(_Context->value_IsExtern | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
					_Context->trigger_IsExtern=visual_trigger_code(_Context->msg_IsExtern[_Context->language],strlen(_Context->msg_IsExtern[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+70,80,24,vfh[2],25,26,_Context->msg_IsExtern[_Context->language],strlen(_Context->msg_IsExtern[_Context->language]),_Context->value_IsExtern| 0x0030);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* CreateOptions */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+390,_Context->y_WidgetProperties+80,288,90,vfh[1],27,0,parse_selection(WidgetSizesOptions,&_Context->value_CreateOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* Create */
				if (_Context->page_number == 2 ) {
					_Context->keycode = on_Create_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* OnShowPage */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xf :
				/* ShowOptions */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetShowOptions,&_Context->value_ShowOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* Show */
				if (_Context->page_number == 3 ) {
					_Context->keycode = on_Show_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* OnGetFocus */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x12 :
				/* FocusOptions */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetFocusOptions,&_Context->value_FocusOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* GetFocus */
				if (_Context->page_number == 4 ) {
					_Context->keycode = on_GetFocus_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* OnEvent */
				if (_Context->page_number == 5 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x15 :
				/* MimoMove */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+180,_Context->y_WidgetProperties+90,48,16,vfh[1],25,26,_Context->msg_MimoMove[_Context->language],strlen(_Context->msg_MimoMove[_Context->language]),(_Context->value_MimoMove | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
					_Context->trigger_MimoMove=visual_trigger_code(_Context->msg_MimoMove[_Context->language],strlen(_Context->msg_MimoMove[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+180,_Context->y_WidgetProperties+90,48,16,vfh[1],25,26,_Context->msg_MimoMove[_Context->language],strlen(_Context->msg_MimoMove[_Context->language]),_Context->value_MimoMove| 0x0030);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* MimoDown */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+90,48,16,vfh[1],25,26,_Context->msg_MimoDown[_Context->language],strlen(_Context->msg_MimoDown[_Context->language]),(_Context->value_MimoDown | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
					_Context->trigger_MimoDown=visual_trigger_code(_Context->msg_MimoDown[_Context->language],strlen(_Context->msg_MimoDown[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+90,48,16,vfh[1],25,26,_Context->msg_MimoDown[_Context->language],strlen(_Context->msg_MimoDown[_Context->language]),_Context->value_MimoDown| 0x0030);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* MimoUp */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+280,_Context->y_WidgetProperties+90,48,16,vfh[1],25,26,_Context->msg_MimoUp[_Context->language],strlen(_Context->msg_MimoUp[_Context->language]),(_Context->value_MimoUp | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
					_Context->trigger_MimoUp=visual_trigger_code(_Context->msg_MimoUp[_Context->language],strlen(_Context->msg_MimoUp[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+280,_Context->y_WidgetProperties+90,48,16,vfh[1],25,26,_Context->msg_MimoUp[_Context->language],strlen(_Context->msg_MimoUp[_Context->language]),_Context->value_MimoUp| 0x0030);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* MimoHold */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+90,48,16,vfh[1],25,26,_Context->msg_MimoHold[_Context->language],strlen(_Context->msg_MimoHold[_Context->language]),(_Context->value_MimoHold | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
					_Context->trigger_MimoHold=visual_trigger_code(_Context->msg_MimoHold[_Context->language],strlen(_Context->msg_MimoHold[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+90,48,16,vfh[1],25,26,_Context->msg_MimoHold[_Context->language],strlen(_Context->msg_MimoHold[_Context->language]),_Context->value_MimoHold| 0x0030);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* MimoLeft */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+400,_Context->y_WidgetProperties+90,16,16,vfh[1],25,26,_Context->msg_MimoLeft[_Context->language],strlen(_Context->msg_MimoLeft[_Context->language]),(_Context->value_MimoLeft | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
					_Context->trigger_MimoLeft=visual_trigger_code(_Context->msg_MimoLeft[_Context->language],strlen(_Context->msg_MimoLeft[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+400,_Context->y_WidgetProperties+90,16,16,vfh[1],25,26,_Context->msg_MimoLeft[_Context->language],strlen(_Context->msg_MimoLeft[_Context->language]),_Context->value_MimoLeft| 0x0030);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* MimoRight */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+440,_Context->y_WidgetProperties+90,16,16,vfh[1],25,26,_Context->msg_MimoRight[_Context->language],strlen(_Context->msg_MimoRight[_Context->language]),(_Context->value_MimoRight | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
					_Context->trigger_MimoRight=visual_trigger_code(_Context->msg_MimoRight[_Context->language],strlen(_Context->msg_MimoRight[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+440,_Context->y_WidgetProperties+90,16,16,vfh[1],25,26,_Context->msg_MimoRight[_Context->language],strlen(_Context->msg_MimoRight[_Context->language]),_Context->value_MimoRight| 0x0030);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* MimoWheel */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+90,16,16,vfh[1],25,26,_Context->msg_MimoWheel[_Context->language],strlen(_Context->msg_MimoWheel[_Context->language]),(_Context->value_MimoWheel | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
					_Context->trigger_MimoWheel=visual_trigger_code(_Context->msg_MimoWheel[_Context->language],strlen(_Context->msg_MimoWheel[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+90,16,16,vfh[1],25,26,_Context->msg_MimoWheel[_Context->language],strlen(_Context->msg_MimoWheel[_Context->language]),_Context->value_MimoWheel| 0x0030);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* MimoMiddle */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+420,_Context->y_WidgetProperties+90,16,16,vfh[1],25,26,_Context->msg_MimoMiddle[_Context->language],strlen(_Context->msg_MimoMiddle[_Context->language]),(_Context->value_MimoMiddle | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
					_Context->trigger_MimoMiddle=visual_trigger_code(_Context->msg_MimoMiddle[_Context->language],strlen(_Context->msg_MimoMiddle[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+420,_Context->y_WidgetProperties+90,16,16,vfh[1],25,26,_Context->msg_MimoMiddle[_Context->language],strlen(_Context->msg_MimoMiddle[_Context->language]),_Context->value_MimoMiddle| 0x0030);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* EventOptions */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_EventOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* Event */
				if (_Context->page_number == 5 ) {
					_Context->keycode = on_Event_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* OnLoseFocus */
				if (_Context->page_number == 6 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x20 :
				/* LoseOptions */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_LoseOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* LoseFocus */
				if (_Context->page_number == 6 ) {
					_Context->keycode = on_LoseFocus_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* OnHidePage */
				if (_Context->page_number == 7 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x23 :
				/* HideOptions */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetHideOptions,&_Context->value_HideOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* Hide */
				if (_Context->page_number == 7 ) {
					_Context->keycode = on_Hide_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x25 :
				/* OnRemove */
				if (_Context->page_number == 8 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x26 :
				/* RemoveOptions */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_RemoveOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* Remove */
				if (_Context->page_number == 8 ) {
					_Context->keycode = on_Remove_getfocus(_Context);
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
			accept_widget_properties_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_widget_properties_show(_Context);
			continue;
		case	0x2 :
			accept_widget_properties_losefocus(_Context);
			_Context->page_number=8;
			_Context->focus_item=39;
			accept_widget_properties_show(_Context);
			continue;
		case	0x3 :
			accept_widget_properties_losefocus(_Context);
			if ( _Context->page_number < 8 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_widget_properties_show(_Context);
			continue;
		case	0x12 :
			accept_widget_properties_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_widget_properties_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_widget_properties_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (Auto3610_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Auto3611_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Toggle_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (NationalMessages_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (NationalHelptext_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (Auto3615_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (Widget_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (OnCreate_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Permission_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (IsExtern_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (CreateOptions_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (Create_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (OnShowPage_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (ShowOptions_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (Show_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (OnGetFocus_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (FocusOptions_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (GetFocus_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (OnEvent_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (MimoMove_help(_Context) != 0) { continue; }
						else { break; }
					case	0x16 :
						if (MimoDown_help(_Context) != 0) { continue; }
						else { break; }
					case	0x17 :
						if (MimoUp_help(_Context) != 0) { continue; }
						else { break; }
					case	0x18 :
						if (MimoHold_help(_Context) != 0) { continue; }
						else { break; }
					case	0x19 :
						if (MimoLeft_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1a :
						if (MimoRight_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1b :
						if (MimoWheel_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1c :
						if (MimoMiddle_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1d :
						if (EventOptions_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1e :
						if (Event_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1f :
						if (OnLoseFocus_help(_Context) != 0) { continue; }
						else { break; }
					case	0x20 :
						if (LoseOptions_help(_Context) != 0) { continue; }
						else { break; }
					case	0x21 :
						if (LoseFocus_help(_Context) != 0) { continue; }
						else { break; }
					case	0x22 :
						if (OnHidePage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x23 :
						if (HideOptions_help(_Context) != 0) { continue; }
						else { break; }
					case	0x24 :
						if (Hide_help(_Context) != 0) { continue; }
						else { break; }
					case	0x25 :
						if (OnRemove_help(_Context) != 0) { continue; }
						else { break; }
					case	0x26 :
						if (RemoveOptions_help(_Context) != 0) { continue; }
						else { break; }
					case	0x27 :
						if (Remove_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* WidgetProperties */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto3610 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3610=visual_trigger_code(_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]));
						visual_button(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3610=visual_trigger_code(_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]));
	visual_button(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x30 ) {
					if ((_Context->keycode = on_Auto3610_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto3611 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3611=visual_trigger_code(_Context->msg_Auto3611[_Context->language],strlen(_Context->msg_Auto3611[_Context->language]));
						visual_button(_Context->x_WidgetProperties+120,_Context->y_WidgetProperties+480,56,48,vfh[2],28,28,_Context->msg_Auto3611[_Context->language],strlen(_Context->msg_Auto3611[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3611=visual_trigger_code(_Context->msg_Auto3611[_Context->language],strlen(_Context->msg_Auto3611[_Context->language]));
	visual_button(_Context->x_WidgetProperties+120,_Context->y_WidgetProperties+480,56,48,vfh[2],28,28,_Context->msg_Auto3611[_Context->language],strlen(_Context->msg_Auto3611[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x30 ) {
					if ((_Context->keycode = on_Auto3611_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Toggle */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Toggle += 1;
						_Context->value_Toggle &= 1;
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Toggle_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* NationalMessages */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_NationalMessages=visual_trigger_code(_Context->msg_NationalMessages[_Context->language],strlen(_Context->msg_NationalMessages[_Context->language]));
						visual_button(_Context->x_WidgetProperties+270,_Context->y_WidgetProperties+480,56,48,vfh[2],28,28,_Context->msg_NationalMessages[_Context->language],strlen(_Context->msg_NationalMessages[_Context->language]),18);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_NationalMessages=visual_trigger_code(_Context->msg_NationalMessages[_Context->language],strlen(_Context->msg_NationalMessages[_Context->language]));
	visual_button(_Context->x_WidgetProperties+270,_Context->y_WidgetProperties+480,56,48,vfh[2],28,28,_Context->msg_NationalMessages[_Context->language],strlen(_Context->msg_NationalMessages[_Context->language]),16);
						}
					if ( visual_event(1) &  0x30 ) {
					if ((_Context->keycode = on_NationalMessages_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* NationalHelptext */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_NationalHelptext=visual_trigger_code(_Context->msg_NationalHelptext[_Context->language],strlen(_Context->msg_NationalHelptext[_Context->language]));
						visual_button(_Context->x_WidgetProperties+450,_Context->y_WidgetProperties+480,56,48,vfh[2],28,28,_Context->msg_NationalHelptext[_Context->language],strlen(_Context->msg_NationalHelptext[_Context->language]),18);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_NationalHelptext=visual_trigger_code(_Context->msg_NationalHelptext[_Context->language],strlen(_Context->msg_NationalHelptext[_Context->language]));
	visual_button(_Context->x_WidgetProperties+450,_Context->y_WidgetProperties+480,56,48,vfh[2],28,28,_Context->msg_NationalHelptext[_Context->language],strlen(_Context->msg_NationalHelptext[_Context->language]),16);
						}
					if ( visual_event(1) &  0x30 ) {
					if ((_Context->keycode = on_NationalHelptext_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto3615 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3615=visual_trigger_code(_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]));
						visual_button(_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3615=visual_trigger_code(_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]));
	visual_button(_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x30 ) {
					if ((_Context->keycode = on_Auto3615_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Widget */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_properties_losefocus(_Context);
						_Context->page_number = 1;
						accept_widget_properties_show(_Context);
						}
					continue;
				case	0x9 :
					/* OnCreate */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_properties_losefocus(_Context);
						_Context->page_number = 2;
						accept_widget_properties_show(_Context);
						}
					continue;
				case	0xa :
					/* Permission */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Permission += 1;
						_Context->value_Permission &= 1;
						}
					continue;
				case	0xb :
					/* IsExtern */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsExtern += 1;
						_Context->value_IsExtern &= 1;
						}
					continue;
				case	0xc :
					/* CreateOptions */
					continue;
				case	0xd :
					/* Create */
					continue;
				case	0xe :
					/* OnShowPage */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_properties_losefocus(_Context);
						_Context->page_number = 3;
						accept_widget_properties_show(_Context);
						}
					continue;
				case	0xf :
					/* ShowOptions */
					continue;
				case	0x10 :
					/* Show */
					continue;
				case	0x11 :
					/* OnGetFocus */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_properties_losefocus(_Context);
						_Context->page_number = 4;
						accept_widget_properties_show(_Context);
						}
					continue;
				case	0x12 :
					/* FocusOptions */
					continue;
				case	0x13 :
					/* GetFocus */
					continue;
				case	0x14 :
					/* OnEvent */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_properties_losefocus(_Context);
						_Context->page_number = 5;
						accept_widget_properties_show(_Context);
						}
					continue;
				case	0x15 :
					/* MimoMove */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MimoMove += 1;
						_Context->value_MimoMove &= 1;
						}
					continue;
				case	0x16 :
					/* MimoDown */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MimoDown += 1;
						_Context->value_MimoDown &= 1;
						}
					continue;
				case	0x17 :
					/* MimoUp */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MimoUp += 1;
						_Context->value_MimoUp &= 1;
						}
					continue;
				case	0x18 :
					/* MimoHold */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MimoHold += 1;
						_Context->value_MimoHold &= 1;
						}
					continue;
				case	0x19 :
					/* MimoLeft */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MimoLeft += 1;
						_Context->value_MimoLeft &= 1;
						}
					continue;
				case	0x1a :
					/* MimoRight */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MimoRight += 1;
						_Context->value_MimoRight &= 1;
						}
					continue;
				case	0x1b :
					/* MimoWheel */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MimoWheel += 1;
						_Context->value_MimoWheel &= 1;
						}
					continue;
				case	0x1c :
					/* MimoMiddle */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MimoMiddle += 1;
						_Context->value_MimoMiddle &= 1;
						}
					continue;
				case	0x1d :
					/* EventOptions */
					continue;
				case	0x1e :
					/* Event */
					continue;
				case	0x1f :
					/* OnLoseFocus */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_properties_losefocus(_Context);
						_Context->page_number = 6;
						accept_widget_properties_show(_Context);
						}
					continue;
				case	0x20 :
					/* LoseOptions */
					continue;
				case	0x21 :
					/* LoseFocus */
					continue;
				case	0x22 :
					/* OnHidePage */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_properties_losefocus(_Context);
						_Context->page_number = 7;
						accept_widget_properties_show(_Context);
						}
					continue;
				case	0x23 :
					/* HideOptions */
					continue;
				case	0x24 :
					/* Hide */
					continue;
				case	0x25 :
					/* OnRemove */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_properties_losefocus(_Context);
						_Context->page_number = 8;
						accept_widget_properties_show(_Context);
						}
					continue;
				case	0x26 :
					/* RemoveOptions */
					continue;
				case	0x27 :
					/* Remove */
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
				_Context->focus_item=39;
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

public	int	accept_widget_properties(
	char * pPermission,
	char * pIsExtern,
	char * pCreateOptions,
	char * pCreate,
	char * pShowOptions,
	char * pShow,
	char * pFocusOptions,
	char * pGetFocus,
	char * pMimoMove,
	char * pMimoDown,
	char * pMimoUp,
	char * pMimoHold,
	char * pMimoLeft,
	char * pMimoRight,
	char * pMimoWheel,
	char * pMimoMiddle,
	char * pEventOptions,
	char * pEvent,
	char * pLoseOptions,
	char * pLoseFocus,
	char * pHideOptions,
	char * pHide,
	char * pRemoveOptions,
	char * pRemove)
{
	int	status=0;
	struct accept_widget_properties_context * _Context=(struct accept_widget_properties_context*) 0;
	status = accept_widget_properties_create(
	&_Context,
	 pPermission,
	 pIsExtern,
	 pCreateOptions,
	 pCreate,
	 pShowOptions,
	 pShow,
	 pFocusOptions,
	 pGetFocus,
	 pMimoMove,
	 pMimoDown,
	 pMimoUp,
	 pMimoHold,
	 pMimoLeft,
	 pMimoRight,
	 pMimoWheel,
	 pMimoMiddle,
	 pEventOptions,
	 pEvent,
	 pLoseOptions,
	 pLoseFocus,
	 pHideOptions,
	 pHide,
	 pRemoveOptions,
	 pRemove);
	if ( status != 0) return(status);
	status = accept_widget_properties_show(_Context);
		enter_modal();
	status = accept_widget_properties_focus(_Context);
		leave_modal();
	status = accept_widget_properties_hide(_Context);
	status = accept_widget_properties_remove(
	_Context,
	 pPermission,
	 pIsExtern,
	 pCreateOptions,
	 pCreate,
	 pShowOptions,
	 pShow,
	 pFocusOptions,
	 pGetFocus,
	 pMimoMove,
	 pMimoDown,
	 pMimoUp,
	 pMimoHold,
	 pMimoLeft,
	 pMimoRight,
	 pMimoWheel,
	 pMimoMiddle,
	 pEventOptions,
	 pEvent,
	 pLoseOptions,
	 pLoseFocus,
	 pHideOptions,
	 pHide,
	 pRemoveOptions,
	 pRemove);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwidget_c */
