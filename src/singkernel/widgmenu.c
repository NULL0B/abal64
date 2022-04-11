
#ifndef _widgmenu_c
#define _widgmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : widgmenu.xml  */
/* Target         : widgmenu.c  */
/* Identification : 0.0-1100084453-2590.2589 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Auto1605   ""
#define en_Auto1607   "&Messages"
#define fr_Auto1607   "&Messages"
#define it_Auto1607   "&Messages"
#define es_Auto1607   "&Messages"
#define de_Auto1607   "&Messages"
#define nl_Auto1607   "&Messages"
#define pt_Auto1607   "&Messages"
#define xx_Auto1607   "&Messages"
#define en_Auto1609   "&Item Help"
#define fr_Auto1609   "&Aide d'Item"
#define it_Auto1609   "&Item Help"
#define es_Auto1609   "&Item Help"
#define de_Auto1609   "&Item Help"
#define nl_Auto1609   "&Item Help"
#define pt_Auto1609   "&Item Help"
#define xx_Auto1609   "&Item Help"
#define en_Auto1610   "&Form Help"
#define fr_Auto1610   "A&ide Formulaire"
#define it_Auto1610   "&Form Help"
#define es_Auto1610   "&Form Help"
#define de_Auto1610   "&Form Help"
#define nl_Auto1610   "&Form Help"
#define pt_Auto1610   "&Form Help"
#define xx_Auto1610   "&Form Help"
#define en_Auto1611   "F&ont"
#define fr_Auto1611   "&Police"
#define it_Auto1611   "F&ont"
#define es_Auto1611   "F&ont"
#define de_Auto1611   "F&ont"
#define nl_Auto1611   "F&ont"
#define pt_Auto1611   "F&ont"
#define xx_Auto1611   "F&ont"
#define en_Auto1711   "&Type"
#define fr_Auto1711   "&Type"
#define it_Auto1711   "&Type"
#define es_Auto1711   "&Type"
#define de_Auto1711   "&Type"
#define nl_Auto1711   "&Type"
#define pt_Auto1711   "&Type"
#define xx_Auto1711   "&Type"
#define en_Auto1737   "&Align"
#define fr_Auto1737   "A&lignement"
#define it_Auto1737   "&Align"
#define es_Auto1737   "&Align"
#define de_Auto1737   "&Align"
#define nl_Auto1737   "&Align"
#define pt_Auto1737   "&Align"
#define xx_Auto1737   "&Align"
#define en_Auto1741   "&Bold"
#define fr_Auto1741   "&Gras"
#define it_Auto1741   "&Bold"
#define es_Auto1741   "&Bold"
#define de_Auto1741   "&Bold"
#define nl_Auto1741   "&Bold"
#define pt_Auto1741   "&Bold"
#define xx_Auto1741   "&Bold"
#define en_Auto1612   "&Shadow"
#define fr_Auto1612   "&Ombrage"
#define it_Auto1612   "&Shadow"
#define es_Auto1612   "&Shadow"
#define de_Auto1612   "&Shadow"
#define nl_Auto1612   "&Shadow"
#define pt_Auto1612   "&Shadow"
#define xx_Auto1612   "&Shadow"
#define en_Auto1749   "&Underline"
#define fr_Auto1749   "&Soulign‚"
#define it_Auto1749   "&Underline"
#define es_Auto1749   "&Underline"
#define de_Auto1749   "&Underline"
#define nl_Auto1749   "&Underline"
#define pt_Auto1749   "&Underline"
#define xx_Auto1749   "&Underline"
#define en_Auto1629   "&Copy"
#define fr_Auto1629   "&Copier"
#define it_Auto1629   "&Copy"
#define es_Auto1629   "&Copy"
#define de_Auto1629   "&Copy"
#define nl_Auto1629   "&Copy"
#define pt_Auto1629   "&Copy"
#define xx_Auto1629   "&Copy"
#define en_Auto1732   "&Paste"
#define fr_Auto1732   "Coll&er"
#define it_Auto1732   "&Paste"
#define es_Auto1732   "&Paste"
#define de_Auto1732   "&Paste"
#define nl_Auto1732   "&Paste"
#define pt_Auto1732   "&Paste"
#define xx_Auto1732   "&Paste"
#define en_Auto1733   "&Lock"
#define fr_Auto1733   "&Verouiller"
#define it_Auto1733   "&Lock"
#define es_Auto1733   "&Lock"
#define de_Auto1733   "&Lock"
#define nl_Auto1733   "&Lock"
#define pt_Auto1733   "&Lock"
#define xx_Auto1733   "&Lock"
#define en_Auto1734   "U&nLock"
#define fr_Auto1734   "&D‚verouiller"
#define it_Auto1734   "U&nLock"
#define es_Auto1734   "U&nLock"
#define de_Auto1734   "U&nLock"
#define nl_Auto1734   "U&nLock"
#define pt_Auto1734   "U&nLock"
#define xx_Auto1734   "U&nLock"
#define en_Auto1735   "Automatic Displa&y"
#define fr_Auto1735   "A&ffichage Automatique"
#define it_Auto1735   "Automatic &Display"
#define es_Auto1735   "Automatic &Display"
#define de_Auto1735   "Automatic &Display"
#define nl_Auto1735   "Automatic &Display"
#define pt_Auto1735   "Automatic &Display"
#define xx_Auto1735   "Automatic &Display"
#define en_Auto1736   "Conditional S&how"
#define fr_Auto1736   "Co&nditionelle"
#define it_Auto1736   "Conditional S&how"
#define es_Auto1736   "Conditional S&how"
#define de_Auto1736   "Conditional S&how"
#define nl_Auto1736   "Conditional S&how"
#define pt_Auto1736   "Conditional S&how"
#define xx_Auto1736   "Conditional S&how"
#define en_Auto1738   "Fo&reground Colour"
#define fr_Auto1738   "Co&uleur de texte"
#define it_Auto1738   "Fo&reground Colour"
#define es_Auto1738   "Fo&reground Colour"
#define de_Auto1738   "Fo&reground Colour"
#define nl_Auto1738   "Fo&reground Colour"
#define pt_Auto1738   "Fo&reground Colour"
#define xx_Auto1738   "Fo&reground Colour"
#define en_Auto1739   "Bac&kground Colour"
#define fr_Auto1739   "Couleu&r de fond"
#define it_Auto1739   "Bac&kground Colour"
#define es_Auto1739   "Bac&kground Colour"
#define de_Auto1739   "Bac&kground Colour"
#define nl_Auto1739   "Bac&kground Colour"
#define pt_Auto1739   "Bac&kground Colour"
#define xx_Auto1739   "Bac&kground Colour"
#define en_Auto1747   "Locat&e"
#define fr_Auto1747   "Rec&hercher"
#define it_Auto1747   "Locat&e"
#define es_Auto1747   "Locat&e"
#define de_Auto1747   "Locat&e"
#define nl_Auto1747   "Locat&e"
#define pt_Auto1747   "Locat&e"
#define xx_Auto1747   "Locat&e"
#define en_Auto1781   "&Delete"
#define fr_Auto1781   "Rechercher"
#define it_Auto1781   "Locate"
#define es_Auto1781   "Locate"
#define de_Auto1781   "Locate"
#define nl_Auto1781   "Locate"
#define pt_Auto1781   "Locate"
#define xx_Auto1781   "Locate"
static int	vfh[10];

private struct forms_widget_menu_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	s_Auto1605;
	void *	p_Auto1605;
	char * msg_Auto1607[8];
	int	trigger_Auto1607;
	char * msg_Auto1609[8];
	int	trigger_Auto1609;
	char * msg_Auto1610[8];
	int	trigger_Auto1610;
	char * msg_Auto1611[8];
	int	trigger_Auto1611;
	char * msg_Auto1711[8];
	int	trigger_Auto1711;
	char * msg_Auto1737[8];
	int	trigger_Auto1737;
	char * msg_Auto1741[8];
	int	trigger_Auto1741;
	char * msg_Auto1612[8];
	int	trigger_Auto1612;
	char * msg_Auto1749[8];
	int	trigger_Auto1749;
	char * msg_Auto1629[8];
	int	trigger_Auto1629;
	char * msg_Auto1732[8];
	int	trigger_Auto1732;
	char * msg_Auto1733[8];
	int	trigger_Auto1733;
	char * msg_Auto1734[8];
	int	trigger_Auto1734;
	char * msg_Auto1735[8];
	int	trigger_Auto1735;
	char * msg_Auto1736[8];
	int	trigger_Auto1736;
	char * msg_Auto1738[8];
	int	trigger_Auto1738;
	char * msg_Auto1739[8];
	int	trigger_Auto1739;
	char * msg_Auto1747[8];
	int	trigger_Auto1747;
	char * msg_Auto1781[8];
	int	trigger_Auto1781;
	char	signature[1];
	};

public	int	forms_widget_menu_create(struct forms_widget_menu_context **cptr)
{

	int i;
	struct forms_widget_menu_context * _Context=(struct forms_widget_menu_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct forms_widget_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=19;
	_Context->s_Auto1605=0;
	_Context->p_Auto1605=visual_buffer(384,32,184,332);
	mouse_move_on();
	for (i=0; i < 8; i++)_Context->msg_Auto1607[i]=" ";
	_Context->msg_Auto1607[0]=en_Auto1607;
	_Context->msg_Auto1607[1]=fr_Auto1607;
	_Context->msg_Auto1607[2]=it_Auto1607;
	_Context->msg_Auto1607[3]=es_Auto1607;
	_Context->msg_Auto1607[4]=de_Auto1607;
	_Context->msg_Auto1607[5]=nl_Auto1607;
	_Context->msg_Auto1607[6]=pt_Auto1607;
	_Context->msg_Auto1607[7]=xx_Auto1607;
	for (i=0; i < 8; i++)_Context->msg_Auto1609[i]=" ";
	_Context->msg_Auto1609[0]=en_Auto1609;
	_Context->msg_Auto1609[1]=fr_Auto1609;
	_Context->msg_Auto1609[2]=it_Auto1609;
	_Context->msg_Auto1609[3]=es_Auto1609;
	_Context->msg_Auto1609[4]=de_Auto1609;
	_Context->msg_Auto1609[5]=nl_Auto1609;
	_Context->msg_Auto1609[6]=pt_Auto1609;
	_Context->msg_Auto1609[7]=xx_Auto1609;
	for (i=0; i < 8; i++)_Context->msg_Auto1610[i]=" ";
	_Context->msg_Auto1610[0]=en_Auto1610;
	_Context->msg_Auto1610[1]=fr_Auto1610;
	_Context->msg_Auto1610[2]=it_Auto1610;
	_Context->msg_Auto1610[3]=es_Auto1610;
	_Context->msg_Auto1610[4]=de_Auto1610;
	_Context->msg_Auto1610[5]=nl_Auto1610;
	_Context->msg_Auto1610[6]=pt_Auto1610;
	_Context->msg_Auto1610[7]=xx_Auto1610;
	for (i=0; i < 8; i++)_Context->msg_Auto1611[i]=" ";
	_Context->msg_Auto1611[0]=en_Auto1611;
	_Context->msg_Auto1611[1]=fr_Auto1611;
	_Context->msg_Auto1611[2]=it_Auto1611;
	_Context->msg_Auto1611[3]=es_Auto1611;
	_Context->msg_Auto1611[4]=de_Auto1611;
	_Context->msg_Auto1611[5]=nl_Auto1611;
	_Context->msg_Auto1611[6]=pt_Auto1611;
	_Context->msg_Auto1611[7]=xx_Auto1611;
	for (i=0; i < 8; i++)_Context->msg_Auto1711[i]=" ";
	_Context->msg_Auto1711[0]=en_Auto1711;
	_Context->msg_Auto1711[1]=fr_Auto1711;
	_Context->msg_Auto1711[2]=it_Auto1711;
	_Context->msg_Auto1711[3]=es_Auto1711;
	_Context->msg_Auto1711[4]=de_Auto1711;
	_Context->msg_Auto1711[5]=nl_Auto1711;
	_Context->msg_Auto1711[6]=pt_Auto1711;
	_Context->msg_Auto1711[7]=xx_Auto1711;
	for (i=0; i < 8; i++)_Context->msg_Auto1737[i]=" ";
	_Context->msg_Auto1737[0]=en_Auto1737;
	_Context->msg_Auto1737[1]=fr_Auto1737;
	_Context->msg_Auto1737[2]=it_Auto1737;
	_Context->msg_Auto1737[3]=es_Auto1737;
	_Context->msg_Auto1737[4]=de_Auto1737;
	_Context->msg_Auto1737[5]=nl_Auto1737;
	_Context->msg_Auto1737[6]=pt_Auto1737;
	_Context->msg_Auto1737[7]=xx_Auto1737;
	for (i=0; i < 8; i++)_Context->msg_Auto1741[i]=" ";
	_Context->msg_Auto1741[0]=en_Auto1741;
	_Context->msg_Auto1741[1]=fr_Auto1741;
	_Context->msg_Auto1741[2]=it_Auto1741;
	_Context->msg_Auto1741[3]=es_Auto1741;
	_Context->msg_Auto1741[4]=de_Auto1741;
	_Context->msg_Auto1741[5]=nl_Auto1741;
	_Context->msg_Auto1741[6]=pt_Auto1741;
	_Context->msg_Auto1741[7]=xx_Auto1741;
	for (i=0; i < 8; i++)_Context->msg_Auto1612[i]=" ";
	_Context->msg_Auto1612[0]=en_Auto1612;
	_Context->msg_Auto1612[1]=fr_Auto1612;
	_Context->msg_Auto1612[2]=it_Auto1612;
	_Context->msg_Auto1612[3]=es_Auto1612;
	_Context->msg_Auto1612[4]=de_Auto1612;
	_Context->msg_Auto1612[5]=nl_Auto1612;
	_Context->msg_Auto1612[6]=pt_Auto1612;
	_Context->msg_Auto1612[7]=xx_Auto1612;
	for (i=0; i < 8; i++)_Context->msg_Auto1749[i]=" ";
	_Context->msg_Auto1749[0]=en_Auto1749;
	_Context->msg_Auto1749[1]=fr_Auto1749;
	_Context->msg_Auto1749[2]=it_Auto1749;
	_Context->msg_Auto1749[3]=es_Auto1749;
	_Context->msg_Auto1749[4]=de_Auto1749;
	_Context->msg_Auto1749[5]=nl_Auto1749;
	_Context->msg_Auto1749[6]=pt_Auto1749;
	_Context->msg_Auto1749[7]=xx_Auto1749;
	for (i=0; i < 8; i++)_Context->msg_Auto1629[i]=" ";
	_Context->msg_Auto1629[0]=en_Auto1629;
	_Context->msg_Auto1629[1]=fr_Auto1629;
	_Context->msg_Auto1629[2]=it_Auto1629;
	_Context->msg_Auto1629[3]=es_Auto1629;
	_Context->msg_Auto1629[4]=de_Auto1629;
	_Context->msg_Auto1629[5]=nl_Auto1629;
	_Context->msg_Auto1629[6]=pt_Auto1629;
	_Context->msg_Auto1629[7]=xx_Auto1629;
	for (i=0; i < 8; i++)_Context->msg_Auto1732[i]=" ";
	_Context->msg_Auto1732[0]=en_Auto1732;
	_Context->msg_Auto1732[1]=fr_Auto1732;
	_Context->msg_Auto1732[2]=it_Auto1732;
	_Context->msg_Auto1732[3]=es_Auto1732;
	_Context->msg_Auto1732[4]=de_Auto1732;
	_Context->msg_Auto1732[5]=nl_Auto1732;
	_Context->msg_Auto1732[6]=pt_Auto1732;
	_Context->msg_Auto1732[7]=xx_Auto1732;
	for (i=0; i < 8; i++)_Context->msg_Auto1733[i]=" ";
	_Context->msg_Auto1733[0]=en_Auto1733;
	_Context->msg_Auto1733[1]=fr_Auto1733;
	_Context->msg_Auto1733[2]=it_Auto1733;
	_Context->msg_Auto1733[3]=es_Auto1733;
	_Context->msg_Auto1733[4]=de_Auto1733;
	_Context->msg_Auto1733[5]=nl_Auto1733;
	_Context->msg_Auto1733[6]=pt_Auto1733;
	_Context->msg_Auto1733[7]=xx_Auto1733;
	for (i=0; i < 8; i++)_Context->msg_Auto1734[i]=" ";
	_Context->msg_Auto1734[0]=en_Auto1734;
	_Context->msg_Auto1734[1]=fr_Auto1734;
	_Context->msg_Auto1734[2]=it_Auto1734;
	_Context->msg_Auto1734[3]=es_Auto1734;
	_Context->msg_Auto1734[4]=de_Auto1734;
	_Context->msg_Auto1734[5]=nl_Auto1734;
	_Context->msg_Auto1734[6]=pt_Auto1734;
	_Context->msg_Auto1734[7]=xx_Auto1734;
	for (i=0; i < 8; i++)_Context->msg_Auto1735[i]=" ";
	_Context->msg_Auto1735[0]=en_Auto1735;
	_Context->msg_Auto1735[1]=fr_Auto1735;
	_Context->msg_Auto1735[2]=it_Auto1735;
	_Context->msg_Auto1735[3]=es_Auto1735;
	_Context->msg_Auto1735[4]=de_Auto1735;
	_Context->msg_Auto1735[5]=nl_Auto1735;
	_Context->msg_Auto1735[6]=pt_Auto1735;
	_Context->msg_Auto1735[7]=xx_Auto1735;
	for (i=0; i < 8; i++)_Context->msg_Auto1736[i]=" ";
	_Context->msg_Auto1736[0]=en_Auto1736;
	_Context->msg_Auto1736[1]=fr_Auto1736;
	_Context->msg_Auto1736[2]=it_Auto1736;
	_Context->msg_Auto1736[3]=es_Auto1736;
	_Context->msg_Auto1736[4]=de_Auto1736;
	_Context->msg_Auto1736[5]=nl_Auto1736;
	_Context->msg_Auto1736[6]=pt_Auto1736;
	_Context->msg_Auto1736[7]=xx_Auto1736;
	for (i=0; i < 8; i++)_Context->msg_Auto1738[i]=" ";
	_Context->msg_Auto1738[0]=en_Auto1738;
	_Context->msg_Auto1738[1]=fr_Auto1738;
	_Context->msg_Auto1738[2]=it_Auto1738;
	_Context->msg_Auto1738[3]=es_Auto1738;
	_Context->msg_Auto1738[4]=de_Auto1738;
	_Context->msg_Auto1738[5]=nl_Auto1738;
	_Context->msg_Auto1738[6]=pt_Auto1738;
	_Context->msg_Auto1738[7]=xx_Auto1738;
	for (i=0; i < 8; i++)_Context->msg_Auto1739[i]=" ";
	_Context->msg_Auto1739[0]=en_Auto1739;
	_Context->msg_Auto1739[1]=fr_Auto1739;
	_Context->msg_Auto1739[2]=it_Auto1739;
	_Context->msg_Auto1739[3]=es_Auto1739;
	_Context->msg_Auto1739[4]=de_Auto1739;
	_Context->msg_Auto1739[5]=nl_Auto1739;
	_Context->msg_Auto1739[6]=pt_Auto1739;
	_Context->msg_Auto1739[7]=xx_Auto1739;
	for (i=0; i < 8; i++)_Context->msg_Auto1747[i]=" ";
	_Context->msg_Auto1747[0]=en_Auto1747;
	_Context->msg_Auto1747[1]=fr_Auto1747;
	_Context->msg_Auto1747[2]=it_Auto1747;
	_Context->msg_Auto1747[3]=es_Auto1747;
	_Context->msg_Auto1747[4]=de_Auto1747;
	_Context->msg_Auto1747[5]=nl_Auto1747;
	_Context->msg_Auto1747[6]=pt_Auto1747;
	_Context->msg_Auto1747[7]=xx_Auto1747;
	for (i=0; i < 8; i++)_Context->msg_Auto1781[i]=" ";
	_Context->msg_Auto1781[0]=en_Auto1781;
	_Context->msg_Auto1781[1]=fr_Auto1781;
	_Context->msg_Auto1781[2]=it_Auto1781;
	_Context->msg_Auto1781[3]=es_Auto1781;
	_Context->msg_Auto1781[4]=de_Auto1781;
	_Context->msg_Auto1781[5]=nl_Auto1781;
	_Context->msg_Auto1781[6]=pt_Auto1781;
	_Context->msg_Auto1781[7]=xx_Auto1781;
	return(0);
}

public 	int	forms_widget_menu_hide(struct forms_widget_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto1605 != (void *) 0)
	&& (_Context->s_Auto1605 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto1605,384,32);
		_Context->s_Auto1605=0;
		}

	return(result);
}

public	int	forms_widget_menu_remove(struct forms_widget_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto1605 != (void *) 0)
		_Context->p_Auto1605 = visual_drop(_Context->p_Auto1605);
	_Context=liberate(_Context);

	return(result);
}

public	int	forms_widget_menu_show(struct forms_widget_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Auto1605 != (void *) 0)
	&& (_Context->s_Auto1605 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto1605,384,32);
		_Context->s_Auto1605=1;
		}
	visual_filzone(384,32,184,332,27,11);
	_Context->trigger_Auto1607=visual_trigger_code(_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]));
	visual_button(400,44,152,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
	_Context->trigger_Auto1609=visual_trigger_code(_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]));
	visual_button(400,60,152,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
	_Context->trigger_Auto1610=visual_trigger_code(_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]));
	visual_button(400,76,152,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
	_Context->trigger_Auto1611=visual_trigger_code(_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]));
	visual_button(400,92,152,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
	_Context->trigger_Auto1711=visual_trigger_code(_Context->msg_Auto1711[_Context->language],strlen(_Context->msg_Auto1711[_Context->language]));
	visual_button(400,108,152,20,vfh[2],16,0,_Context->msg_Auto1711[_Context->language],strlen(_Context->msg_Auto1711[_Context->language]),32);
	_Context->trigger_Auto1737=visual_trigger_code(_Context->msg_Auto1737[_Context->language],strlen(_Context->msg_Auto1737[_Context->language]));
	visual_button(400,124,152,20,vfh[2],16,0,_Context->msg_Auto1737[_Context->language],strlen(_Context->msg_Auto1737[_Context->language]),32);
	_Context->trigger_Auto1741=visual_trigger_code(_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]));
	visual_button(400,140,152,20,vfh[2],16,0,_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]),32);
	_Context->trigger_Auto1612=visual_trigger_code(_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]));
	visual_button(400,156,152,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),32);
	_Context->trigger_Auto1749=visual_trigger_code(_Context->msg_Auto1749[_Context->language],strlen(_Context->msg_Auto1749[_Context->language]));
	visual_button(400,172,152,20,vfh[2],16,0,_Context->msg_Auto1749[_Context->language],strlen(_Context->msg_Auto1749[_Context->language]),32);
	_Context->trigger_Auto1629=visual_trigger_code(_Context->msg_Auto1629[_Context->language],strlen(_Context->msg_Auto1629[_Context->language]));
	visual_button(400,188,152,20,vfh[2],16,0,_Context->msg_Auto1629[_Context->language],strlen(_Context->msg_Auto1629[_Context->language]),32);
	_Context->trigger_Auto1732=visual_trigger_code(_Context->msg_Auto1732[_Context->language],strlen(_Context->msg_Auto1732[_Context->language]));
	visual_button(400,204,152,20,vfh[2],16,0,_Context->msg_Auto1732[_Context->language],strlen(_Context->msg_Auto1732[_Context->language]),32);
	_Context->trigger_Auto1733=visual_trigger_code(_Context->msg_Auto1733[_Context->language],strlen(_Context->msg_Auto1733[_Context->language]));
	visual_button(400,220,152,20,vfh[2],16,0,_Context->msg_Auto1733[_Context->language],strlen(_Context->msg_Auto1733[_Context->language]),32);
	_Context->trigger_Auto1734=visual_trigger_code(_Context->msg_Auto1734[_Context->language],strlen(_Context->msg_Auto1734[_Context->language]));
	visual_button(400,236,152,20,vfh[2],16,0,_Context->msg_Auto1734[_Context->language],strlen(_Context->msg_Auto1734[_Context->language]),32);
	_Context->trigger_Auto1735=visual_trigger_code(_Context->msg_Auto1735[_Context->language],strlen(_Context->msg_Auto1735[_Context->language]));
	visual_button(400,252,152,20,vfh[2],16,0,_Context->msg_Auto1735[_Context->language],strlen(_Context->msg_Auto1735[_Context->language]),32);
	_Context->trigger_Auto1736=visual_trigger_code(_Context->msg_Auto1736[_Context->language],strlen(_Context->msg_Auto1736[_Context->language]));
	visual_button(400,268,152,20,vfh[2],16,0,_Context->msg_Auto1736[_Context->language],strlen(_Context->msg_Auto1736[_Context->language]),32);
	_Context->trigger_Auto1738=visual_trigger_code(_Context->msg_Auto1738[_Context->language],strlen(_Context->msg_Auto1738[_Context->language]));
	visual_button(400,284,152,20,vfh[2],16,0,_Context->msg_Auto1738[_Context->language],strlen(_Context->msg_Auto1738[_Context->language]),32);
	_Context->trigger_Auto1739=visual_trigger_code(_Context->msg_Auto1739[_Context->language],strlen(_Context->msg_Auto1739[_Context->language]));
	visual_button(400,300,152,20,vfh[2],16,0,_Context->msg_Auto1739[_Context->language],strlen(_Context->msg_Auto1739[_Context->language]),32);
	_Context->trigger_Auto1747=visual_trigger_code(_Context->msg_Auto1747[_Context->language],strlen(_Context->msg_Auto1747[_Context->language]));
	visual_button(400,316,152,20,vfh[2],16,0,_Context->msg_Auto1747[_Context->language],strlen(_Context->msg_Auto1747[_Context->language]),32);
	_Context->trigger_Auto1781=visual_trigger_code(_Context->msg_Auto1781[_Context->language],strlen(_Context->msg_Auto1781[_Context->language]));
	visual_button(400,332,152,20,vfh[2],16,0,_Context->msg_Auto1781[_Context->language],strlen(_Context->msg_Auto1781[_Context->language]),32);
	visual_thaw(384,32,184,332);

	return(0);
}
private int on_Auto1607_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_MSG);
	return(-1);
}
private int on_Auto1609_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_HELP);
	return(-1);
}
private int on_Auto1610_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_FORM);
	return(-1);
}
private int on_Auto1611_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_FONT);
	return(-1);
}
private int on_Auto1711_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_TYPE);
	return(-1);
}
private int on_Auto1737_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_ALIG);
	return(-1);
}
private int on_Auto1741_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_BOLD);
	return(-1);
}
private int on_Auto1612_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_SHADOW);
	return(-1);
}
private int on_Auto1749_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_ULINE);
	return(-1);
}
private int on_Auto1629_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_COPY);
	return(-1);
}
private int on_Auto1732_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_PASTE);
	return(-1);
}
private int on_Auto1733_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_LOCK);
	return(-1);
}
private int on_Auto1734_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_UNLOCK);
	return(-1);
}
private int on_Auto1735_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_AUTO);
	return(-1);
}
private int on_Auto1736_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_COND);
	return(-1);
}
private int on_Auto1738_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_FORE);
	return(-1);
}
private int on_Auto1739_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_BACK);
	return(-1);
}
private int on_Auto1747_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_FIND);
	return(-1);
}
private int on_Auto1781_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_DELETE);
	return(-1);
}


public	int	forms_widget_menu_event(
struct forms_widget_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto1607 == mb ) return(1);
		if (_Context->trigger_Auto1609 == mb ) return(2);
		if (_Context->trigger_Auto1610 == mb ) return(3);
		if (_Context->trigger_Auto1611 == mb ) return(4);
		if (_Context->trigger_Auto1711 == mb ) return(5);
		if (_Context->trigger_Auto1737 == mb ) return(6);
		if (_Context->trigger_Auto1741 == mb ) return(7);
		if (_Context->trigger_Auto1612 == mb ) return(8);
		if (_Context->trigger_Auto1749 == mb ) return(9);
		if (_Context->trigger_Auto1629 == mb ) return(10);
		if (_Context->trigger_Auto1732 == mb ) return(11);
		if (_Context->trigger_Auto1733 == mb ) return(12);
		if (_Context->trigger_Auto1734 == mb ) return(13);
		if (_Context->trigger_Auto1735 == mb ) return(14);
		if (_Context->trigger_Auto1736 == mb ) return(15);
		if (_Context->trigger_Auto1738 == mb ) return(16);
		if (_Context->trigger_Auto1739 == mb ) return(17);
		if (_Context->trigger_Auto1747 == mb ) return(18);
		if (_Context->trigger_Auto1781 == mb ) return(19);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 400 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto1607 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 60 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 80 )) {
		return(2); /* Auto1609 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 76 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 96 )) {
		return(3); /* Auto1610 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 92 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 112 )) {
		return(4); /* Auto1611 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 108 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 128 )) {
		return(5); /* Auto1711 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 144 )) {
		return(6); /* Auto1737 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 140 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 160 )) {
		return(7); /* Auto1741 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 156 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 176 )) {
		return(8); /* Auto1612 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 172 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 192 )) {
		return(9); /* Auto1749 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 188 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 208 )) {
		return(10); /* Auto1629 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 204 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 224 )) {
		return(11); /* Auto1732 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 220 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 240 )) {
		return(12); /* Auto1733 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 236 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 256 )) {
		return(13); /* Auto1734 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 252 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 272 )) {
		return(14); /* Auto1735 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 268 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 288 )) {
		return(15); /* Auto1736 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 284 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 304 )) {
		return(16); /* Auto1738 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 300 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 320 )) {
		return(17); /* Auto1739 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 316 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 336 )) {
		return(18); /* Auto1747 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 332 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 352 )) {
		return(19); /* Auto1781 */
		}

	return(-1);
}


public	int	forms_widget_menu_focus(struct forms_widget_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto1607 */
				visual_button(400,44,152,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,44,152,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
				break;
			case	0x2 :
				/* Auto1609 */
				visual_button(400,60,152,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,60,152,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
				break;
			case	0x3 :
				/* Auto1610 */
				visual_button(400,76,152,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,76,152,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
				break;
			case	0x4 :
				/* Auto1611 */
				visual_button(400,92,152,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,92,152,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
				break;
			case	0x5 :
				/* Auto1711 */
				visual_button(400,108,152,20,vfh[2],16,0,_Context->msg_Auto1711[_Context->language],strlen(_Context->msg_Auto1711[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,108,152,20,vfh[2],16,0,_Context->msg_Auto1711[_Context->language],strlen(_Context->msg_Auto1711[_Context->language]),32);
				break;
			case	0x6 :
				/* Auto1737 */
				visual_button(400,124,152,20,vfh[2],16,0,_Context->msg_Auto1737[_Context->language],strlen(_Context->msg_Auto1737[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,124,152,20,vfh[2],16,0,_Context->msg_Auto1737[_Context->language],strlen(_Context->msg_Auto1737[_Context->language]),32);
				break;
			case	0x7 :
				/* Auto1741 */
				visual_button(400,140,152,20,vfh[2],16,0,_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,140,152,20,vfh[2],16,0,_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]),32);
				break;
			case	0x8 :
				/* Auto1612 */
				visual_button(400,156,152,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,156,152,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),32);
				break;
			case	0x9 :
				/* Auto1749 */
				visual_button(400,172,152,20,vfh[2],16,0,_Context->msg_Auto1749[_Context->language],strlen(_Context->msg_Auto1749[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,172,152,20,vfh[2],16,0,_Context->msg_Auto1749[_Context->language],strlen(_Context->msg_Auto1749[_Context->language]),32);
				break;
			case	0xa :
				/* Auto1629 */
				visual_button(400,188,152,20,vfh[2],16,0,_Context->msg_Auto1629[_Context->language],strlen(_Context->msg_Auto1629[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,188,152,20,vfh[2],16,0,_Context->msg_Auto1629[_Context->language],strlen(_Context->msg_Auto1629[_Context->language]),32);
				break;
			case	0xb :
				/* Auto1732 */
				visual_button(400,204,152,20,vfh[2],16,0,_Context->msg_Auto1732[_Context->language],strlen(_Context->msg_Auto1732[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,204,152,20,vfh[2],16,0,_Context->msg_Auto1732[_Context->language],strlen(_Context->msg_Auto1732[_Context->language]),32);
				break;
			case	0xc :
				/* Auto1733 */
				visual_button(400,220,152,20,vfh[2],16,0,_Context->msg_Auto1733[_Context->language],strlen(_Context->msg_Auto1733[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,220,152,20,vfh[2],16,0,_Context->msg_Auto1733[_Context->language],strlen(_Context->msg_Auto1733[_Context->language]),32);
				break;
			case	0xd :
				/* Auto1734 */
				visual_button(400,236,152,20,vfh[2],16,0,_Context->msg_Auto1734[_Context->language],strlen(_Context->msg_Auto1734[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,236,152,20,vfh[2],16,0,_Context->msg_Auto1734[_Context->language],strlen(_Context->msg_Auto1734[_Context->language]),32);
				break;
			case	0xe :
				/* Auto1735 */
				visual_button(400,252,152,20,vfh[2],16,0,_Context->msg_Auto1735[_Context->language],strlen(_Context->msg_Auto1735[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,252,152,20,vfh[2],16,0,_Context->msg_Auto1735[_Context->language],strlen(_Context->msg_Auto1735[_Context->language]),32);
				break;
			case	0xf :
				/* Auto1736 */
				visual_button(400,268,152,20,vfh[2],16,0,_Context->msg_Auto1736[_Context->language],strlen(_Context->msg_Auto1736[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,268,152,20,vfh[2],16,0,_Context->msg_Auto1736[_Context->language],strlen(_Context->msg_Auto1736[_Context->language]),32);
				break;
			case	0x10 :
				/* Auto1738 */
				visual_button(400,284,152,20,vfh[2],16,0,_Context->msg_Auto1738[_Context->language],strlen(_Context->msg_Auto1738[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,284,152,20,vfh[2],16,0,_Context->msg_Auto1738[_Context->language],strlen(_Context->msg_Auto1738[_Context->language]),32);
				break;
			case	0x11 :
				/* Auto1739 */
				visual_button(400,300,152,20,vfh[2],16,0,_Context->msg_Auto1739[_Context->language],strlen(_Context->msg_Auto1739[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,300,152,20,vfh[2],16,0,_Context->msg_Auto1739[_Context->language],strlen(_Context->msg_Auto1739[_Context->language]),32);
				break;
			case	0x12 :
				/* Auto1747 */
				visual_button(400,316,152,20,vfh[2],16,0,_Context->msg_Auto1747[_Context->language],strlen(_Context->msg_Auto1747[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,316,152,20,vfh[2],16,0,_Context->msg_Auto1747[_Context->language],strlen(_Context->msg_Auto1747[_Context->language]),32);
				break;
			case	0x13 :
				/* Auto1781 */
				visual_button(400,332,152,20,vfh[2],16,0,_Context->msg_Auto1781[_Context->language],strlen(_Context->msg_Auto1781[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(400,332,152,20,vfh[2],16,0,_Context->msg_Auto1781[_Context->language],strlen(_Context->msg_Auto1781[_Context->language]),32);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			forms_widget_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=19;
			forms_widget_menu_show(_Context);
			continue;
			case	0x100 :
				if (!( visual_event(1)  & _MIMO_ALT )) { 
					if (( visual_event(7) <  384 )
					|| ( visual_event(6) <  32 )
					|| ( visual_event(7) >  568 )
					|| ( visual_event(6) >  364 )) {
						if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
						else { return(256); }
						}
					}
				if ((retcode=forms_widget_menu_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1607 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,44,152,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,44,152,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1607_event(_Context)) != -1) break;

							}
						continue;
					case	0x2 :
						/* Auto1609 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,60,152,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,60,152,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1609_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Auto1610 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,76,152,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,76,152,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1610_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto1611 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,92,152,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,92,152,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1611_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Auto1711 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,108,152,20,vfh[2],16,0,_Context->msg_Auto1711[_Context->language],strlen(_Context->msg_Auto1711[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,108,152,20,vfh[2],16,0,_Context->msg_Auto1711[_Context->language],strlen(_Context->msg_Auto1711[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1711_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* Auto1737 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,124,152,20,vfh[2],16,0,_Context->msg_Auto1737[_Context->language],strlen(_Context->msg_Auto1737[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,124,152,20,vfh[2],16,0,_Context->msg_Auto1737[_Context->language],strlen(_Context->msg_Auto1737[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1737_event(_Context)) != -1) break;

							}
						continue;
					case	0x7 :
						/* Auto1741 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,140,152,20,vfh[2],16,0,_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,140,152,20,vfh[2],16,0,_Context->msg_Auto1741[_Context->language],strlen(_Context->msg_Auto1741[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1741_event(_Context)) != -1) break;

							}
						continue;
					case	0x8 :
						/* Auto1612 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,156,152,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,156,152,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1612_event(_Context)) != -1) break;

							}
						continue;
					case	0x9 :
						/* Auto1749 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,172,152,20,vfh[2],16,0,_Context->msg_Auto1749[_Context->language],strlen(_Context->msg_Auto1749[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,172,152,20,vfh[2],16,0,_Context->msg_Auto1749[_Context->language],strlen(_Context->msg_Auto1749[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1749_event(_Context)) != -1) break;

							}
						continue;
					case	0xa :
						/* Auto1629 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,188,152,20,vfh[2],16,0,_Context->msg_Auto1629[_Context->language],strlen(_Context->msg_Auto1629[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,188,152,20,vfh[2],16,0,_Context->msg_Auto1629[_Context->language],strlen(_Context->msg_Auto1629[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1629_event(_Context)) != -1) break;

							}
						continue;
					case	0xb :
						/* Auto1732 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,204,152,20,vfh[2],16,0,_Context->msg_Auto1732[_Context->language],strlen(_Context->msg_Auto1732[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,204,152,20,vfh[2],16,0,_Context->msg_Auto1732[_Context->language],strlen(_Context->msg_Auto1732[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1732_event(_Context)) != -1) break;

							}
						continue;
					case	0xc :
						/* Auto1733 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,220,152,20,vfh[2],16,0,_Context->msg_Auto1733[_Context->language],strlen(_Context->msg_Auto1733[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,220,152,20,vfh[2],16,0,_Context->msg_Auto1733[_Context->language],strlen(_Context->msg_Auto1733[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1733_event(_Context)) != -1) break;

							}
						continue;
					case	0xd :
						/* Auto1734 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,236,152,20,vfh[2],16,0,_Context->msg_Auto1734[_Context->language],strlen(_Context->msg_Auto1734[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,236,152,20,vfh[2],16,0,_Context->msg_Auto1734[_Context->language],strlen(_Context->msg_Auto1734[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1734_event(_Context)) != -1) break;

							}
						continue;
					case	0xe :
						/* Auto1735 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,252,152,20,vfh[2],16,0,_Context->msg_Auto1735[_Context->language],strlen(_Context->msg_Auto1735[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,252,152,20,vfh[2],16,0,_Context->msg_Auto1735[_Context->language],strlen(_Context->msg_Auto1735[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1735_event(_Context)) != -1) break;

							}
						continue;
					case	0xf :
						/* Auto1736 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,268,152,20,vfh[2],16,0,_Context->msg_Auto1736[_Context->language],strlen(_Context->msg_Auto1736[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,268,152,20,vfh[2],16,0,_Context->msg_Auto1736[_Context->language],strlen(_Context->msg_Auto1736[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1736_event(_Context)) != -1) break;

							}
						continue;
					case	0x10 :
						/* Auto1738 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,284,152,20,vfh[2],16,0,_Context->msg_Auto1738[_Context->language],strlen(_Context->msg_Auto1738[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,284,152,20,vfh[2],16,0,_Context->msg_Auto1738[_Context->language],strlen(_Context->msg_Auto1738[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1738_event(_Context)) != -1) break;

							}
						continue;
					case	0x11 :
						/* Auto1739 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,300,152,20,vfh[2],16,0,_Context->msg_Auto1739[_Context->language],strlen(_Context->msg_Auto1739[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,300,152,20,vfh[2],16,0,_Context->msg_Auto1739[_Context->language],strlen(_Context->msg_Auto1739[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1739_event(_Context)) != -1) break;

							}
						continue;
					case	0x12 :
						/* Auto1747 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,316,152,20,vfh[2],16,0,_Context->msg_Auto1747[_Context->language],strlen(_Context->msg_Auto1747[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,316,152,20,vfh[2],16,0,_Context->msg_Auto1747[_Context->language],strlen(_Context->msg_Auto1747[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1747_event(_Context)) != -1) break;

							}
						continue;
					case	0x13 :
						/* Auto1781 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,332,152,20,vfh[2],16,0,_Context->msg_Auto1781[_Context->language],strlen(_Context->msg_Auto1781[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,332,152,20,vfh[2],16,0,_Context->msg_Auto1781[_Context->language],strlen(_Context->msg_Auto1781[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1781_event(_Context)) != -1) break;

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
				_Context->focus_item=19;
			}
			continue;
			case	0x0 :
			
			continue;
			case	0xffffffff :
			
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	forms_widget_menu()
{
	int	status=0;
	struct forms_widget_menu_context * _Context=(struct forms_widget_menu_context*) 0;
	status = forms_widget_menu_create(&_Context);
	if ( status != 0) return(status);
	status = forms_widget_menu_show(_Context);
		enter_modal();
	status = forms_widget_menu_focus(_Context);
		leave_modal();
	status = forms_widget_menu_hide(_Context);
	status = forms_widget_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _widgmenu_c */
