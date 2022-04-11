
#ifndef _widgmenu_c
#define _widgmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : widgmenu.xml                                             */
/* Target         : widgmenu.c                                               */
/* Identification : 0.0-1177512019-5209.5208                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Auto620   ""
#define en__Auto620   ""
#define en_Auto622   "&Messages..."
#define fr_Auto622   "&Messages..."
#define it_Auto622   "&Messages..."
#define es_Auto622   "&Messages..."
#define de_Auto622   "&Messages..."
#define nl_Auto622   "&Messages..."
#define pt_Auto622   "&Messages..."
#define xx_Auto622   "&Messages..."
#define en__Auto622   ""
#define fr__Auto622   ""
#define it__Auto622   ""
#define es__Auto622   ""
#define de__Auto622   ""
#define nl__Auto622   ""
#define pt__Auto622   ""
#define xx__Auto622   ""
#define en_Auto623   "&Help..."
#define fr_Auto623   "&Aide..."
#define it_Auto623   "&Help..."
#define es_Auto623   "&Help..."
#define de_Auto623   "&Hilfe..."
#define nl_Auto623   "&Help..."
#define pt_Auto623   "&Help..."
#define xx_Auto623   "&Help..."
#define en__Auto623   ""
#define fr__Auto623   ""
#define it__Auto623   ""
#define es__Auto623   ""
#define de__Auto623   ""
#define nl__Auto623   ""
#define pt__Auto623   ""
#define xx__Auto623   ""
#define en_Auto624   "F&ont"
#define fr_Auto624   "&Police"
#define it_Auto624   "F&ont"
#define es_Auto624   "F&ont"
#define de_Auto624   "F&ont"
#define nl_Auto624   "F&ont"
#define pt_Auto624   "F&ont"
#define xx_Auto624   "F&ont"
#define en__Auto624   ""
#define fr__Auto624   ""
#define it__Auto624   ""
#define es__Auto624   ""
#define de__Auto624   ""
#define nl__Auto624   ""
#define pt__Auto624   ""
#define xx__Auto624   ""
#define en_Auto625   "&Type"
#define fr_Auto625   "&Type"
#define it_Auto625   "&Type"
#define es_Auto625   "&Type"
#define de_Auto625   "&Type"
#define nl_Auto625   "&Type"
#define pt_Auto625   "&Type"
#define xx_Auto625   "&Type"
#define en_Auto626   "&Align"
#define fr_Auto626   "&Alignement"
#define it_Auto626   "&Align"
#define es_Auto626   "&Align"
#define de_Auto626   "&Align"
#define nl_Auto626   "&Align"
#define pt_Auto626   "&Align"
#define xx_Auto626   "&Align"
#define en__Auto626   ""
#define fr__Auto626   ""
#define it__Auto626   ""
#define es__Auto626   ""
#define de__Auto626   ""
#define nl__Auto626   ""
#define pt__Auto626   ""
#define xx__Auto626   ""
#define en_Auto627   "&Bold"
#define fr_Auto627   "&Gras"
#define it_Auto627   "&Bold"
#define es_Auto627   "&Bold"
#define de_Auto627   "&Bold"
#define nl_Auto627   "&Bold"
#define pt_Auto627   "&Bold"
#define xx_Auto627   "&Bold"
#define en_Auto628   "&Shadow"
#define fr_Auto628   "&Ombrage"
#define it_Auto628   "&Shadow"
#define es_Auto628   "&Shadow"
#define de_Auto628   "&Shadow"
#define nl_Auto628   "&Shadow"
#define pt_Auto628   "&Shadow"
#define xx_Auto628   "&Shadow"
#define en_Auto629   "&Underline"
#define fr_Auto629   "&Soulign‚"
#define it_Auto629   "&Underline"
#define es_Auto629   "&Underline"
#define de_Auto629   "&Underline"
#define nl_Auto629   "&Underline"
#define pt_Auto629   "&Underline"
#define xx_Auto629   "&Underline"
#define en_Auto630   "&Copy"
#define fr_Auto630   "&Copier"
#define it_Auto630   "&Copy"
#define es_Auto630   "&Copy"
#define de_Auto630   "&Copy"
#define nl_Auto630   "&Copy"
#define pt_Auto630   "&Copy"
#define xx_Auto630   "&Copy"
#define en_Auto631   "&Paste"
#define fr_Auto631   "Co&ller"
#define it_Auto631   "&Paste"
#define es_Auto631   "&Paste"
#define de_Auto631   "&Paste"
#define nl_Auto631   "&Paste"
#define pt_Auto631   "&Paste"
#define xx_Auto631   "&Paste"
#define en__Auto631   ""
#define fr__Auto631   ""
#define it__Auto631   ""
#define es__Auto631   ""
#define de__Auto631   ""
#define nl__Auto631   ""
#define pt__Auto631   ""
#define xx__Auto631   ""
#define en_Auto632   "&Lock"
#define fr_Auto632   "&Verrouiller"
#define it_Auto632   "&Lock"
#define es_Auto632   "&Lock"
#define de_Auto632   "&Lock"
#define nl_Auto632   "&Lock"
#define pt_Auto632   "&Lock"
#define xx_Auto632   "&Lock"
#define en__Auto632   ""
#define fr__Auto632   ""
#define it__Auto632   ""
#define es__Auto632   ""
#define de__Auto632   ""
#define nl__Auto632   ""
#define pt__Auto632   ""
#define xx__Auto632   ""
#define en_Auto633   "U&nLock"
#define fr_Auto633   "&D‚verrouiller"
#define it_Auto633   "U&nLock"
#define es_Auto633   "U&nLock"
#define de_Auto633   "U&nLock"
#define nl_Auto633   "U&nLock"
#define pt_Auto633   "U&nLock"
#define xx_Auto633   "U&nLock"
#define en__Auto633   ""
#define fr__Auto633   ""
#define it__Auto633   ""
#define es__Auto633   ""
#define de__Auto633   ""
#define nl__Auto633   ""
#define pt__Auto633   ""
#define xx__Auto633   ""
#define en_Auto634   "Automatic Displa&y"
#define fr_Auto634   "Affichage a&utomatique"
#define it_Auto634   "Automatic &Display"
#define es_Auto634   "Automatic &Display"
#define de_Auto634   "Automatic &Display"
#define nl_Auto634   "Automatic &Display"
#define pt_Auto634   "Automatic &Display"
#define xx_Auto634   "Automatic &Display"
#define en__Auto634   ""
#define fr__Auto634   ""
#define it__Auto634   ""
#define es__Auto634   ""
#define de__Auto634   ""
#define nl__Auto634   ""
#define pt__Auto634   ""
#define xx__Auto634   ""
#define en_Auto635   "Conditional S&how"
#define fr_Auto635   "Affichage cond&itionnel"
#define it_Auto635   "Conditional S&how"
#define es_Auto635   "Conditional S&how"
#define de_Auto635   "Conditional S&how"
#define nl_Auto635   "Conditional S&how"
#define pt_Auto635   "Conditional S&how"
#define xx_Auto635   "Conditional S&how"
#define en__Auto635   ""
#define fr__Auto635   ""
#define it__Auto635   ""
#define es__Auto635   ""
#define de__Auto635   ""
#define nl__Auto635   ""
#define pt__Auto635   ""
#define xx__Auto635   ""
#define en_Auto636   "Fo&reground Colour"
#define fr_Auto636   "Couleur de te&xte"
#define it_Auto636   "Fo&reground Colour"
#define es_Auto636   "Fo&reground Colour"
#define de_Auto636   "Fo&reground Colour"
#define nl_Auto636   "Fo&reground Colour"
#define pt_Auto636   "Fo&reground Colour"
#define xx_Auto636   "Fo&reground Colour"
#define en__Auto636   ""
#define fr__Auto636   ""
#define it__Auto636   ""
#define es__Auto636   ""
#define de__Auto636   ""
#define nl__Auto636   ""
#define pt__Auto636   ""
#define xx__Auto636   ""
#define en_Auto637   "Bac&kground Colour"
#define fr_Auto637   "Couleur de fo&nd"
#define it_Auto637   "Bac&kground Colour"
#define es_Auto637   "Bac&kground Colour"
#define de_Auto637   "Bac&kground Colour"
#define nl_Auto637   "Bac&kground Colour"
#define pt_Auto637   "Bac&kground Colour"
#define xx_Auto637   "Bac&kground Colour"
#define en__Auto637   ""
#define fr__Auto637   ""
#define it__Auto637   ""
#define es__Auto637   ""
#define de__Auto637   ""
#define nl__Auto637   ""
#define pt__Auto637   ""
#define xx__Auto637   ""
#define en_Auto638   "Locat&e..."
#define fr_Auto638   "&Rechercher..."
#define it_Auto638   "Locat&e..."
#define es_Auto638   "Locat&e..."
#define de_Auto638   "Locat&e..."
#define nl_Auto638   "Locat&e..."
#define pt_Auto638   "Locat&e..."
#define xx_Auto638   "Locat&e..."
#define en__Auto638   ""
#define fr__Auto638   ""
#define it__Auto638   ""
#define es__Auto638   ""
#define de__Auto638   ""
#define nl__Auto638   ""
#define pt__Auto638   ""
#define xx__Auto638   ""
#define en_Auto639   "St&yle..."
#define fr_Auto639   "St&yle..."
#define it_Auto639   "St&yle..."
#define es_Auto639   "St&yle..."
#define de_Auto639   "St&yle..."
#define nl_Auto639   "St&yle..."
#define pt_Auto639   "St&yle..."
#define xx_Auto639   "St&yle..."
#define en__Auto639   ""
#define fr__Auto639   ""
#define it__Auto639   ""
#define es__Auto639   ""
#define de__Auto639   ""
#define nl__Auto639   ""
#define pt__Auto639   ""
#define xx__Auto639   ""
#define en_Auto640   "&Delete"
#define fr_Auto640   "Suppri&mer"
#define it_Auto640   "&Delete"
#define es_Auto640   "&Delete"
#define de_Auto640   "&Delete"
#define nl_Auto640   "&Delete"
#define pt_Auto640   "&Delete"
#define xx_Auto640   "&Delete"
#define en__Auto640   ""
#define fr__Auto640   ""
#define it__Auto640   ""
#define es__Auto640   ""
#define de__Auto640   ""
#define nl__Auto640   ""
#define pt__Auto640   ""
#define xx__Auto640   ""
#define en_Auto641   "&Events..."
#define fr_Auto641   "&Events..."
#define it_Auto641   "&Events..."
#define es_Auto641   "&Events..."
#define de_Auto641   "&Events..."
#define nl_Auto641   "&Events..."
#define pt_Auto641   "&Events..."
#define xx_Auto641   "&Events..."
#define en__Auto641   ""
#define fr__Auto641   ""
#define it__Auto641   ""
#define es__Auto641   ""
#define de__Auto641   ""
#define nl__Auto641   ""
#define pt__Auto641   ""
#define xx__Auto641   ""

private struct forms_widget_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * hint_Auto620[8];
	int	s_Auto620;
	void *	p_Auto620;
	char * msg_Auto622[8];
	int	trigger_Auto622;
	char * hint_Auto622[8];
	char * msg_Auto623[8];
	int	trigger_Auto623;
	char * hint_Auto623[8];
	char * msg_Auto624[8];
	int	trigger_Auto624;
	char * hint_Auto624[8];
	char * msg_Auto625[8];
	int	trigger_Auto625;
	char * hint_Auto625[8];
	char * msg_Auto626[8];
	int	trigger_Auto626;
	char * hint_Auto626[8];
	char * msg_Auto627[8];
	int	trigger_Auto627;
	char * hint_Auto627[8];
	char * msg_Auto628[8];
	int	trigger_Auto628;
	char * hint_Auto628[8];
	char * msg_Auto629[8];
	int	trigger_Auto629;
	char * hint_Auto629[8];
	char * msg_Auto630[8];
	int	trigger_Auto630;
	char * hint_Auto630[8];
	char * msg_Auto631[8];
	int	trigger_Auto631;
	char * hint_Auto631[8];
	char * msg_Auto632[8];
	int	trigger_Auto632;
	char * hint_Auto632[8];
	char * msg_Auto633[8];
	int	trigger_Auto633;
	char * hint_Auto633[8];
	char * msg_Auto634[8];
	int	trigger_Auto634;
	char * hint_Auto634[8];
	char * msg_Auto635[8];
	int	trigger_Auto635;
	char * hint_Auto635[8];
	char * msg_Auto636[8];
	int	trigger_Auto636;
	char * hint_Auto636[8];
	char * msg_Auto637[8];
	int	trigger_Auto637;
	char * hint_Auto637[8];
	char * msg_Auto638[8];
	int	trigger_Auto638;
	char * hint_Auto638[8];
	char * msg_Auto639[8];
	int	trigger_Auto639;
	char * hint_Auto639[8];
	char * msg_Auto640[8];
	int	trigger_Auto640;
	char * hint_Auto640[8];
	char * msg_Auto641[8];
	int	trigger_Auto641;
	char * hint_Auto641[8];
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct forms_widget_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = forms_widget_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}


public	int	forms_widget_menu_create(struct forms_widget_menu_context **cptr)
{

	int i;
	struct forms_widget_menu_context * _Context=(struct forms_widget_menu_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct forms_widget_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=20;
	_Context->hint_Auto620[0]=en__Auto620;
	_Context->s_Auto620=0;
	_Context->p_Auto620=visual_buffer(384,32,184+2,424+2);
	mouse_move_on();
	for (i=0; i < 8; i++)_Context->msg_Auto622[i]=" ";
	_Context->msg_Auto622[0]=en_Auto622;
	_Context->msg_Auto622[1]=fr_Auto622;
	_Context->msg_Auto622[2]=it_Auto622;
	_Context->msg_Auto622[3]=es_Auto622;
	_Context->msg_Auto622[4]=de_Auto622;
	_Context->msg_Auto622[5]=nl_Auto622;
	_Context->msg_Auto622[6]=pt_Auto622;
	_Context->msg_Auto622[7]=xx_Auto622;
	_Context->hint_Auto622[0]=en__Auto622;
	_Context->hint_Auto622[1]=fr__Auto622;
	_Context->hint_Auto622[2]=it__Auto622;
	_Context->hint_Auto622[3]=es__Auto622;
	_Context->hint_Auto622[4]=de__Auto622;
	_Context->hint_Auto622[5]=nl__Auto622;
	_Context->hint_Auto622[6]=pt__Auto622;
	_Context->hint_Auto622[7]=xx__Auto622;
	for (i=0; i < 8; i++)_Context->msg_Auto623[i]=" ";
	_Context->msg_Auto623[0]=en_Auto623;
	_Context->msg_Auto623[1]=fr_Auto623;
	_Context->msg_Auto623[2]=it_Auto623;
	_Context->msg_Auto623[3]=es_Auto623;
	_Context->msg_Auto623[4]=de_Auto623;
	_Context->msg_Auto623[5]=nl_Auto623;
	_Context->msg_Auto623[6]=pt_Auto623;
	_Context->msg_Auto623[7]=xx_Auto623;
	_Context->hint_Auto623[0]=en__Auto623;
	_Context->hint_Auto623[1]=fr__Auto623;
	_Context->hint_Auto623[2]=it__Auto623;
	_Context->hint_Auto623[3]=es__Auto623;
	_Context->hint_Auto623[4]=de__Auto623;
	_Context->hint_Auto623[5]=nl__Auto623;
	_Context->hint_Auto623[6]=pt__Auto623;
	_Context->hint_Auto623[7]=xx__Auto623;
	for (i=0; i < 8; i++)_Context->msg_Auto624[i]=" ";
	_Context->msg_Auto624[0]=en_Auto624;
	_Context->msg_Auto624[1]=fr_Auto624;
	_Context->msg_Auto624[2]=it_Auto624;
	_Context->msg_Auto624[3]=es_Auto624;
	_Context->msg_Auto624[4]=de_Auto624;
	_Context->msg_Auto624[5]=nl_Auto624;
	_Context->msg_Auto624[6]=pt_Auto624;
	_Context->msg_Auto624[7]=xx_Auto624;
	_Context->hint_Auto624[0]=en__Auto624;
	_Context->hint_Auto624[1]=fr__Auto624;
	_Context->hint_Auto624[2]=it__Auto624;
	_Context->hint_Auto624[3]=es__Auto624;
	_Context->hint_Auto624[4]=de__Auto624;
	_Context->hint_Auto624[5]=nl__Auto624;
	_Context->hint_Auto624[6]=pt__Auto624;
	_Context->hint_Auto624[7]=xx__Auto624;
	for (i=0; i < 8; i++)_Context->msg_Auto625[i]=" ";
	_Context->msg_Auto625[0]=en_Auto625;
	_Context->msg_Auto625[1]=fr_Auto625;
	_Context->msg_Auto625[2]=it_Auto625;
	_Context->msg_Auto625[3]=es_Auto625;
	_Context->msg_Auto625[4]=de_Auto625;
	_Context->msg_Auto625[5]=nl_Auto625;
	_Context->msg_Auto625[6]=pt_Auto625;
	_Context->msg_Auto625[7]=xx_Auto625;
	for (i=0; i < 8; i++)_Context->msg_Auto626[i]=" ";
	_Context->msg_Auto626[0]=en_Auto626;
	_Context->msg_Auto626[1]=fr_Auto626;
	_Context->msg_Auto626[2]=it_Auto626;
	_Context->msg_Auto626[3]=es_Auto626;
	_Context->msg_Auto626[4]=de_Auto626;
	_Context->msg_Auto626[5]=nl_Auto626;
	_Context->msg_Auto626[6]=pt_Auto626;
	_Context->msg_Auto626[7]=xx_Auto626;
	_Context->hint_Auto626[0]=en__Auto626;
	_Context->hint_Auto626[1]=fr__Auto626;
	_Context->hint_Auto626[2]=it__Auto626;
	_Context->hint_Auto626[3]=es__Auto626;
	_Context->hint_Auto626[4]=de__Auto626;
	_Context->hint_Auto626[5]=nl__Auto626;
	_Context->hint_Auto626[6]=pt__Auto626;
	_Context->hint_Auto626[7]=xx__Auto626;
	for (i=0; i < 8; i++)_Context->msg_Auto627[i]=" ";
	_Context->msg_Auto627[0]=en_Auto627;
	_Context->msg_Auto627[1]=fr_Auto627;
	_Context->msg_Auto627[2]=it_Auto627;
	_Context->msg_Auto627[3]=es_Auto627;
	_Context->msg_Auto627[4]=de_Auto627;
	_Context->msg_Auto627[5]=nl_Auto627;
	_Context->msg_Auto627[6]=pt_Auto627;
	_Context->msg_Auto627[7]=xx_Auto627;
	for (i=0; i < 8; i++)_Context->msg_Auto628[i]=" ";
	_Context->msg_Auto628[0]=en_Auto628;
	_Context->msg_Auto628[1]=fr_Auto628;
	_Context->msg_Auto628[2]=it_Auto628;
	_Context->msg_Auto628[3]=es_Auto628;
	_Context->msg_Auto628[4]=de_Auto628;
	_Context->msg_Auto628[5]=nl_Auto628;
	_Context->msg_Auto628[6]=pt_Auto628;
	_Context->msg_Auto628[7]=xx_Auto628;
	for (i=0; i < 8; i++)_Context->msg_Auto629[i]=" ";
	_Context->msg_Auto629[0]=en_Auto629;
	_Context->msg_Auto629[1]=fr_Auto629;
	_Context->msg_Auto629[2]=it_Auto629;
	_Context->msg_Auto629[3]=es_Auto629;
	_Context->msg_Auto629[4]=de_Auto629;
	_Context->msg_Auto629[5]=nl_Auto629;
	_Context->msg_Auto629[6]=pt_Auto629;
	_Context->msg_Auto629[7]=xx_Auto629;
	for (i=0; i < 8; i++)_Context->msg_Auto630[i]=" ";
	_Context->msg_Auto630[0]=en_Auto630;
	_Context->msg_Auto630[1]=fr_Auto630;
	_Context->msg_Auto630[2]=it_Auto630;
	_Context->msg_Auto630[3]=es_Auto630;
	_Context->msg_Auto630[4]=de_Auto630;
	_Context->msg_Auto630[5]=nl_Auto630;
	_Context->msg_Auto630[6]=pt_Auto630;
	_Context->msg_Auto630[7]=xx_Auto630;
	for (i=0; i < 8; i++)_Context->msg_Auto631[i]=" ";
	_Context->msg_Auto631[0]=en_Auto631;
	_Context->msg_Auto631[1]=fr_Auto631;
	_Context->msg_Auto631[2]=it_Auto631;
	_Context->msg_Auto631[3]=es_Auto631;
	_Context->msg_Auto631[4]=de_Auto631;
	_Context->msg_Auto631[5]=nl_Auto631;
	_Context->msg_Auto631[6]=pt_Auto631;
	_Context->msg_Auto631[7]=xx_Auto631;
	_Context->hint_Auto631[0]=en__Auto631;
	_Context->hint_Auto631[1]=fr__Auto631;
	_Context->hint_Auto631[2]=it__Auto631;
	_Context->hint_Auto631[3]=es__Auto631;
	_Context->hint_Auto631[4]=de__Auto631;
	_Context->hint_Auto631[5]=nl__Auto631;
	_Context->hint_Auto631[6]=pt__Auto631;
	_Context->hint_Auto631[7]=xx__Auto631;
	for (i=0; i < 8; i++)_Context->msg_Auto632[i]=" ";
	_Context->msg_Auto632[0]=en_Auto632;
	_Context->msg_Auto632[1]=fr_Auto632;
	_Context->msg_Auto632[2]=it_Auto632;
	_Context->msg_Auto632[3]=es_Auto632;
	_Context->msg_Auto632[4]=de_Auto632;
	_Context->msg_Auto632[5]=nl_Auto632;
	_Context->msg_Auto632[6]=pt_Auto632;
	_Context->msg_Auto632[7]=xx_Auto632;
	_Context->hint_Auto632[0]=en__Auto632;
	_Context->hint_Auto632[1]=fr__Auto632;
	_Context->hint_Auto632[2]=it__Auto632;
	_Context->hint_Auto632[3]=es__Auto632;
	_Context->hint_Auto632[4]=de__Auto632;
	_Context->hint_Auto632[5]=nl__Auto632;
	_Context->hint_Auto632[6]=pt__Auto632;
	_Context->hint_Auto632[7]=xx__Auto632;
	for (i=0; i < 8; i++)_Context->msg_Auto633[i]=" ";
	_Context->msg_Auto633[0]=en_Auto633;
	_Context->msg_Auto633[1]=fr_Auto633;
	_Context->msg_Auto633[2]=it_Auto633;
	_Context->msg_Auto633[3]=es_Auto633;
	_Context->msg_Auto633[4]=de_Auto633;
	_Context->msg_Auto633[5]=nl_Auto633;
	_Context->msg_Auto633[6]=pt_Auto633;
	_Context->msg_Auto633[7]=xx_Auto633;
	_Context->hint_Auto633[0]=en__Auto633;
	_Context->hint_Auto633[1]=fr__Auto633;
	_Context->hint_Auto633[2]=it__Auto633;
	_Context->hint_Auto633[3]=es__Auto633;
	_Context->hint_Auto633[4]=de__Auto633;
	_Context->hint_Auto633[5]=nl__Auto633;
	_Context->hint_Auto633[6]=pt__Auto633;
	_Context->hint_Auto633[7]=xx__Auto633;
	for (i=0; i < 8; i++)_Context->msg_Auto634[i]=" ";
	_Context->msg_Auto634[0]=en_Auto634;
	_Context->msg_Auto634[1]=fr_Auto634;
	_Context->msg_Auto634[2]=it_Auto634;
	_Context->msg_Auto634[3]=es_Auto634;
	_Context->msg_Auto634[4]=de_Auto634;
	_Context->msg_Auto634[5]=nl_Auto634;
	_Context->msg_Auto634[6]=pt_Auto634;
	_Context->msg_Auto634[7]=xx_Auto634;
	_Context->hint_Auto634[0]=en__Auto634;
	_Context->hint_Auto634[1]=fr__Auto634;
	_Context->hint_Auto634[2]=it__Auto634;
	_Context->hint_Auto634[3]=es__Auto634;
	_Context->hint_Auto634[4]=de__Auto634;
	_Context->hint_Auto634[5]=nl__Auto634;
	_Context->hint_Auto634[6]=pt__Auto634;
	_Context->hint_Auto634[7]=xx__Auto634;
	for (i=0; i < 8; i++)_Context->msg_Auto635[i]=" ";
	_Context->msg_Auto635[0]=en_Auto635;
	_Context->msg_Auto635[1]=fr_Auto635;
	_Context->msg_Auto635[2]=it_Auto635;
	_Context->msg_Auto635[3]=es_Auto635;
	_Context->msg_Auto635[4]=de_Auto635;
	_Context->msg_Auto635[5]=nl_Auto635;
	_Context->msg_Auto635[6]=pt_Auto635;
	_Context->msg_Auto635[7]=xx_Auto635;
	_Context->hint_Auto635[0]=en__Auto635;
	_Context->hint_Auto635[1]=fr__Auto635;
	_Context->hint_Auto635[2]=it__Auto635;
	_Context->hint_Auto635[3]=es__Auto635;
	_Context->hint_Auto635[4]=de__Auto635;
	_Context->hint_Auto635[5]=nl__Auto635;
	_Context->hint_Auto635[6]=pt__Auto635;
	_Context->hint_Auto635[7]=xx__Auto635;
	for (i=0; i < 8; i++)_Context->msg_Auto636[i]=" ";
	_Context->msg_Auto636[0]=en_Auto636;
	_Context->msg_Auto636[1]=fr_Auto636;
	_Context->msg_Auto636[2]=it_Auto636;
	_Context->msg_Auto636[3]=es_Auto636;
	_Context->msg_Auto636[4]=de_Auto636;
	_Context->msg_Auto636[5]=nl_Auto636;
	_Context->msg_Auto636[6]=pt_Auto636;
	_Context->msg_Auto636[7]=xx_Auto636;
	_Context->hint_Auto636[0]=en__Auto636;
	_Context->hint_Auto636[1]=fr__Auto636;
	_Context->hint_Auto636[2]=it__Auto636;
	_Context->hint_Auto636[3]=es__Auto636;
	_Context->hint_Auto636[4]=de__Auto636;
	_Context->hint_Auto636[5]=nl__Auto636;
	_Context->hint_Auto636[6]=pt__Auto636;
	_Context->hint_Auto636[7]=xx__Auto636;
	for (i=0; i < 8; i++)_Context->msg_Auto637[i]=" ";
	_Context->msg_Auto637[0]=en_Auto637;
	_Context->msg_Auto637[1]=fr_Auto637;
	_Context->msg_Auto637[2]=it_Auto637;
	_Context->msg_Auto637[3]=es_Auto637;
	_Context->msg_Auto637[4]=de_Auto637;
	_Context->msg_Auto637[5]=nl_Auto637;
	_Context->msg_Auto637[6]=pt_Auto637;
	_Context->msg_Auto637[7]=xx_Auto637;
	_Context->hint_Auto637[0]=en__Auto637;
	_Context->hint_Auto637[1]=fr__Auto637;
	_Context->hint_Auto637[2]=it__Auto637;
	_Context->hint_Auto637[3]=es__Auto637;
	_Context->hint_Auto637[4]=de__Auto637;
	_Context->hint_Auto637[5]=nl__Auto637;
	_Context->hint_Auto637[6]=pt__Auto637;
	_Context->hint_Auto637[7]=xx__Auto637;
	for (i=0; i < 8; i++)_Context->msg_Auto638[i]=" ";
	_Context->msg_Auto638[0]=en_Auto638;
	_Context->msg_Auto638[1]=fr_Auto638;
	_Context->msg_Auto638[2]=it_Auto638;
	_Context->msg_Auto638[3]=es_Auto638;
	_Context->msg_Auto638[4]=de_Auto638;
	_Context->msg_Auto638[5]=nl_Auto638;
	_Context->msg_Auto638[6]=pt_Auto638;
	_Context->msg_Auto638[7]=xx_Auto638;
	_Context->hint_Auto638[0]=en__Auto638;
	_Context->hint_Auto638[1]=fr__Auto638;
	_Context->hint_Auto638[2]=it__Auto638;
	_Context->hint_Auto638[3]=es__Auto638;
	_Context->hint_Auto638[4]=de__Auto638;
	_Context->hint_Auto638[5]=nl__Auto638;
	_Context->hint_Auto638[6]=pt__Auto638;
	_Context->hint_Auto638[7]=xx__Auto638;
	for (i=0; i < 8; i++)_Context->msg_Auto639[i]=" ";
	_Context->msg_Auto639[0]=en_Auto639;
	_Context->msg_Auto639[1]=fr_Auto639;
	_Context->msg_Auto639[2]=it_Auto639;
	_Context->msg_Auto639[3]=es_Auto639;
	_Context->msg_Auto639[4]=de_Auto639;
	_Context->msg_Auto639[5]=nl_Auto639;
	_Context->msg_Auto639[6]=pt_Auto639;
	_Context->msg_Auto639[7]=xx_Auto639;
	_Context->hint_Auto639[0]=en__Auto639;
	_Context->hint_Auto639[1]=fr__Auto639;
	_Context->hint_Auto639[2]=it__Auto639;
	_Context->hint_Auto639[3]=es__Auto639;
	_Context->hint_Auto639[4]=de__Auto639;
	_Context->hint_Auto639[5]=nl__Auto639;
	_Context->hint_Auto639[6]=pt__Auto639;
	_Context->hint_Auto639[7]=xx__Auto639;
	for (i=0; i < 8; i++)_Context->msg_Auto640[i]=" ";
	_Context->msg_Auto640[0]=en_Auto640;
	_Context->msg_Auto640[1]=fr_Auto640;
	_Context->msg_Auto640[2]=it_Auto640;
	_Context->msg_Auto640[3]=es_Auto640;
	_Context->msg_Auto640[4]=de_Auto640;
	_Context->msg_Auto640[5]=nl_Auto640;
	_Context->msg_Auto640[6]=pt_Auto640;
	_Context->msg_Auto640[7]=xx_Auto640;
	_Context->hint_Auto640[0]=en__Auto640;
	_Context->hint_Auto640[1]=fr__Auto640;
	_Context->hint_Auto640[2]=it__Auto640;
	_Context->hint_Auto640[3]=es__Auto640;
	_Context->hint_Auto640[4]=de__Auto640;
	_Context->hint_Auto640[5]=nl__Auto640;
	_Context->hint_Auto640[6]=pt__Auto640;
	_Context->hint_Auto640[7]=xx__Auto640;
	for (i=0; i < 8; i++)_Context->msg_Auto641[i]=" ";
	_Context->msg_Auto641[0]=en_Auto641;
	_Context->msg_Auto641[1]=fr_Auto641;
	_Context->msg_Auto641[2]=it_Auto641;
	_Context->msg_Auto641[3]=es_Auto641;
	_Context->msg_Auto641[4]=de_Auto641;
	_Context->msg_Auto641[5]=nl_Auto641;
	_Context->msg_Auto641[6]=pt_Auto641;
	_Context->msg_Auto641[7]=xx_Auto641;
	_Context->hint_Auto641[0]=en__Auto641;
	_Context->hint_Auto641[1]=fr__Auto641;
	_Context->hint_Auto641[2]=it__Auto641;
	_Context->hint_Auto641[3]=es__Auto641;
	_Context->hint_Auto641[4]=de__Auto641;
	_Context->hint_Auto641[5]=nl__Auto641;
	_Context->hint_Auto641[6]=pt__Auto641;
	_Context->hint_Auto641[7]=xx__Auto641;
	return(0);
}

public 	int	forms_widget_menu_hide(struct forms_widget_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto620 != (void *) 0)
	&& (_Context->s_Auto620 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto620,384,32);
		_Context->s_Auto620=0;
		}

	return(result);
}

public	int	forms_widget_menu_remove(struct forms_widget_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto620 != (void *) 0)
		_Context->p_Auto620 = visual_drop(_Context->p_Auto620);
	_Context=liberate(_Context);

	return(result);
}

public	int	forms_widget_menu_show(struct forms_widget_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Auto620 != (void *) 0)
	&& (_Context->s_Auto620 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto620,384,32);
		_Context->s_Auto620=1;
		}
	if (((_Context->status = visual_styled_element(384,32,184,424,GetWidgetStyle(1)," ",0)) != 0)
) {
		visual_filzone(384,32,184,424,27,11);
		}
	_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
	if (((_Context->status = visual_styled_element(400,44,152,20,GetWidgetStyle(2),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
	visual_button(400,44,152,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),32);
		}
	_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
	if (((_Context->status = visual_styled_element(400,64,152,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(400,64,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
		}
	_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
	if (((_Context->status = visual_styled_element(400,84,152,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(400,84,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
		}
	_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
	if (((_Context->status = visual_styled_element(400,104,152,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(400,104,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
		}
	_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
	if (((_Context->status = visual_styled_element(400,124,152,20,GetWidgetStyle(2),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
	visual_button(400,124,152,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),32);
		}
	_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
	if (((_Context->status = visual_styled_element(400,144,152,20,GetWidgetStyle(2),_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]))) != 0)
) {
	visual_button(400,144,152,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),32);
		}
	_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
	if (((_Context->status = visual_styled_element(400,164,152,20,GetWidgetStyle(2),_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]))) != 0)
) {
	visual_button(400,164,152,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),32);
		}
	_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
	if (((_Context->status = visual_styled_element(400,184,152,20,GetWidgetStyle(2),_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]))) != 0)
) {
	visual_button(400,184,152,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),32);
		}
	_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
	if (((_Context->status = visual_styled_element(400,204,152,20,GetWidgetStyle(2),_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]))) != 0)
) {
	visual_button(400,204,152,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),32);
		}
	_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
	if (((_Context->status = visual_styled_element(400,224,152,20,GetWidgetStyle(2),_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]))) != 0)
) {
	visual_button(400,224,152,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),32);
		}
	_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
	if (((_Context->status = visual_styled_element(400,244,152,20,GetWidgetStyle(2),_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]))) != 0)
) {
	visual_button(400,244,152,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),32);
		}
	_Context->trigger_Auto633=visual_trigger_code(_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]));
	if (((_Context->status = visual_styled_element(400,264,152,20,GetWidgetStyle(2),_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]))) != 0)
) {
	visual_button(400,264,152,20,vfh[2],16,0,_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]),32);
		}
	_Context->trigger_Auto634=visual_trigger_code(_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]));
	if (((_Context->status = visual_styled_element(400,284,152,20,GetWidgetStyle(2),_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]))) != 0)
) {
	visual_button(400,284,152,20,vfh[2],16,0,_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]),32);
		}
	_Context->trigger_Auto635=visual_trigger_code(_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]));
	if (((_Context->status = visual_styled_element(400,304,152,20,GetWidgetStyle(2),_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]))) != 0)
) {
	visual_button(400,304,152,20,vfh[2],16,0,_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]),32);
		}
	_Context->trigger_Auto636=visual_trigger_code(_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]));
	if (((_Context->status = visual_styled_element(400,324,152,20,GetWidgetStyle(2),_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]))) != 0)
) {
	visual_button(400,324,152,20,vfh[2],16,0,_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]),32);
		}
	_Context->trigger_Auto637=visual_trigger_code(_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]));
	if (((_Context->status = visual_styled_element(400,344,152,20,GetWidgetStyle(2),_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]))) != 0)
) {
	visual_button(400,344,152,20,vfh[2],16,0,_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]),32);
		}
	_Context->trigger_Auto638=visual_trigger_code(_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]));
	if (((_Context->status = visual_styled_element(400,364,152,20,GetWidgetStyle(2),_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]))) != 0)
) {
	visual_button(400,364,152,20,vfh[2],16,0,_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]),32);
		}
	_Context->trigger_Auto639=visual_trigger_code(_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]));
	if (((_Context->status = visual_styled_element(400,384,152,20,GetWidgetStyle(2),_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]))) != 0)
) {
	visual_button(400,384,152,20,vfh[2],16,0,_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]),32);
		}
	_Context->trigger_Auto640=visual_trigger_code(_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]));
	if (((_Context->status = visual_styled_element(400,404,152,20,GetWidgetStyle(2),_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]))) != 0)
) {
	visual_button(400,404,152,20,vfh[2],16,0,_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]),32);
		}
	_Context->trigger_Auto641=visual_trigger_code(_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]));
	if (((_Context->status = visual_styled_element(400,424,152,20,GetWidgetStyle(2),_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]))) != 0)
) {
	visual_button(400,424,152,20,vfh[2],16,0,_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]),32);
		}
	visual_thaw(384,32,184,424);

	return(0);
}
private int on_Auto622_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_MSG);
	return(-1);
}
private int on_Auto623_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_HELP);
	return(-1);
}
private int on_Auto624_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_FONT);
	return(-1);
}
private int on_Auto625_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_TYPE);
	return(-1);
}
private int on_Auto626_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_ALIG);
	return(-1);
}
private int on_Auto627_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_BOLD);
	return(-1);
}
private int on_Auto628_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_SHADOW);
	return(-1);
}
private int on_Auto629_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_ULINE);
	return(-1);
}
private int on_Auto630_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_COPY);
	return(-1);
}
private int on_Auto631_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_PASTE);
	return(-1);
}
private int on_Auto632_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_LOCK);
	return(-1);
}
private int on_Auto633_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_UNLOCK);
	return(-1);
}
private int on_Auto634_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_AUTO);
	return(-1);
}
private int on_Auto635_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_COND);
	return(-1);
}
private int on_Auto636_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_FORE);
	return(-1);
}
private int on_Auto637_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_BACK);
	return(-1);
}
private int on_Auto638_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_FIND);
	return(-1);
}
private int on_Auto639_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_STYLE);
	return(-1);
}
private int on_Auto640_event(struct forms_widget_menu_context * _Context) {
	return(_WIDGET_DELETE);
	return(-1);
}
private int on_Auto641_event(struct forms_widget_menu_context * _Context) {
	return(widget_event_menu());
	return(-1);
}


public	int	forms_widget_menu_event(
struct forms_widget_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto622 == mb ) return(1);
		if (_Context->trigger_Auto623 == mb ) return(2);
		if (_Context->trigger_Auto624 == mb ) return(3);
		if (_Context->trigger_Auto625 == mb ) return(4);
		if (_Context->trigger_Auto626 == mb ) return(5);
		if (_Context->trigger_Auto627 == mb ) return(6);
		if (_Context->trigger_Auto628 == mb ) return(7);
		if (_Context->trigger_Auto629 == mb ) return(8);
		if (_Context->trigger_Auto630 == mb ) return(9);
		if (_Context->trigger_Auto631 == mb ) return(10);
		if (_Context->trigger_Auto632 == mb ) return(11);
		if (_Context->trigger_Auto633 == mb ) return(12);
		if (_Context->trigger_Auto634 == mb ) return(13);
		if (_Context->trigger_Auto635 == mb ) return(14);
		if (_Context->trigger_Auto636 == mb ) return(15);
		if (_Context->trigger_Auto637 == mb ) return(16);
		if (_Context->trigger_Auto638 == mb ) return(17);
		if (_Context->trigger_Auto639 == mb ) return(18);
		if (_Context->trigger_Auto640 == mb ) return(19);
		if (_Context->trigger_Auto641 == mb ) return(20);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 400 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto622 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 64 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 84 )) {
		return(2); /* Auto623 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 84 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 104 )) {
		return(3); /* Auto624 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 104 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 124 )) {
		return(4); /* Auto625 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 144 )) {
		return(5); /* Auto626 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 144 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 164 )) {
		return(6); /* Auto627 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 164 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 184 )) {
		return(7); /* Auto628 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 184 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 204 )) {
		return(8); /* Auto629 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 204 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 224 )) {
		return(9); /* Auto630 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 224 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 244 )) {
		return(10); /* Auto631 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 244 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 264 )) {
		return(11); /* Auto632 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 264 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 284 )) {
		return(12); /* Auto633 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 284 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 304 )) {
		return(13); /* Auto634 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 304 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 324 )) {
		return(14); /* Auto635 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 324 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 344 )) {
		return(15); /* Auto636 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 344 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 364 )) {
		return(16); /* Auto637 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 364 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 384 )) {
		return(17); /* Auto638 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 384 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 404 )) {
		return(18); /* Auto639 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 404 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 424 )) {
		return(19); /* Auto640 */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 424 ) 
	&&  ( mx <= 552 ) 
	&&  ( my <= 444 )) {
		return(20); /* Auto641 */
		}

	return(-1);
}


public	int	forms_widget_menu_focus(struct forms_widget_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto622 */
				_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
				if (((_Context->status = visual_styled_element(400,44,152,20,GetWidgetStyle(3),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
					visual_button(400,44,152,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
				if (((_Context->status = visual_styled_element(400,44,152,20,GetWidgetStyle(2),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
	visual_button(400,44,152,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto623 */
				_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
				if (((_Context->status = visual_styled_element(400,64,152,20,GetWidgetStyle(3),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
					visual_button(400,64,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
				if (((_Context->status = visual_styled_element(400,64,152,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(400,64,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto624 */
				_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
				if (((_Context->status = visual_styled_element(400,84,152,20,GetWidgetStyle(3),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
					visual_button(400,84,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
				if (((_Context->status = visual_styled_element(400,84,152,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(400,84,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto625 */
				_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
				if (((_Context->status = visual_styled_element(400,104,152,20,GetWidgetStyle(3),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
					visual_button(400,104,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
				if (((_Context->status = visual_styled_element(400,104,152,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(400,104,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto626 */
				_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
				if (((_Context->status = visual_styled_element(400,124,152,20,GetWidgetStyle(3),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
					visual_button(400,124,152,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
				if (((_Context->status = visual_styled_element(400,124,152,20,GetWidgetStyle(2),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
	visual_button(400,124,152,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto627 */
				_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
				if (((_Context->status = visual_styled_element(400,144,152,20,GetWidgetStyle(3),_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]))) != 0)
) {
					visual_button(400,144,152,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
				if (((_Context->status = visual_styled_element(400,144,152,20,GetWidgetStyle(2),_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]))) != 0)
) {
	visual_button(400,144,152,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* Auto628 */
				_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
				if (((_Context->status = visual_styled_element(400,164,152,20,GetWidgetStyle(3),_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]))) != 0)
) {
					visual_button(400,164,152,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
				if (((_Context->status = visual_styled_element(400,164,152,20,GetWidgetStyle(2),_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]))) != 0)
) {
	visual_button(400,164,152,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto629 */
				_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
				if (((_Context->status = visual_styled_element(400,184,152,20,GetWidgetStyle(3),_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]))) != 0)
) {
					visual_button(400,184,152,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
				if (((_Context->status = visual_styled_element(400,184,152,20,GetWidgetStyle(2),_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]))) != 0)
) {
	visual_button(400,184,152,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),32);
				}
				break;
			case	0x9 :
				/* Auto630 */
				_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
				if (((_Context->status = visual_styled_element(400,204,152,20,GetWidgetStyle(3),_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]))) != 0)
) {
					visual_button(400,204,152,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
				if (((_Context->status = visual_styled_element(400,204,152,20,GetWidgetStyle(2),_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]))) != 0)
) {
	visual_button(400,204,152,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),32);
				}
				break;
			case	0xa :
				/* Auto631 */
				_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
				if (((_Context->status = visual_styled_element(400,224,152,20,GetWidgetStyle(3),_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]))) != 0)
) {
					visual_button(400,224,152,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
				if (((_Context->status = visual_styled_element(400,224,152,20,GetWidgetStyle(2),_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]))) != 0)
) {
	visual_button(400,224,152,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),32);
				}
				break;
			case	0xb :
				/* Auto632 */
				_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
				if (((_Context->status = visual_styled_element(400,244,152,20,GetWidgetStyle(3),_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]))) != 0)
) {
					visual_button(400,244,152,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
				if (((_Context->status = visual_styled_element(400,244,152,20,GetWidgetStyle(2),_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]))) != 0)
) {
	visual_button(400,244,152,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),32);
				}
				break;
			case	0xc :
				/* Auto633 */
				_Context->trigger_Auto633=visual_trigger_code(_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]));
				if (((_Context->status = visual_styled_element(400,264,152,20,GetWidgetStyle(3),_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]))) != 0)
) {
					visual_button(400,264,152,20,vfh[2],16,0,_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto633=visual_trigger_code(_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]));
				if (((_Context->status = visual_styled_element(400,264,152,20,GetWidgetStyle(2),_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]))) != 0)
) {
	visual_button(400,264,152,20,vfh[2],16,0,_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]),32);
				}
				break;
			case	0xd :
				/* Auto634 */
				_Context->trigger_Auto634=visual_trigger_code(_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]));
				if (((_Context->status = visual_styled_element(400,284,152,20,GetWidgetStyle(3),_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]))) != 0)
) {
					visual_button(400,284,152,20,vfh[2],16,0,_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto634=visual_trigger_code(_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]));
				if (((_Context->status = visual_styled_element(400,284,152,20,GetWidgetStyle(2),_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]))) != 0)
) {
	visual_button(400,284,152,20,vfh[2],16,0,_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]),32);
				}
				break;
			case	0xe :
				/* Auto635 */
				_Context->trigger_Auto635=visual_trigger_code(_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]));
				if (((_Context->status = visual_styled_element(400,304,152,20,GetWidgetStyle(3),_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]))) != 0)
) {
					visual_button(400,304,152,20,vfh[2],16,0,_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto635=visual_trigger_code(_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]));
				if (((_Context->status = visual_styled_element(400,304,152,20,GetWidgetStyle(2),_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]))) != 0)
) {
	visual_button(400,304,152,20,vfh[2],16,0,_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]),32);
				}
				break;
			case	0xf :
				/* Auto636 */
				_Context->trigger_Auto636=visual_trigger_code(_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]));
				if (((_Context->status = visual_styled_element(400,324,152,20,GetWidgetStyle(3),_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]))) != 0)
) {
					visual_button(400,324,152,20,vfh[2],16,0,_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto636=visual_trigger_code(_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]));
				if (((_Context->status = visual_styled_element(400,324,152,20,GetWidgetStyle(2),_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]))) != 0)
) {
	visual_button(400,324,152,20,vfh[2],16,0,_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]),32);
				}
				break;
			case	0x10 :
				/* Auto637 */
				_Context->trigger_Auto637=visual_trigger_code(_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]));
				if (((_Context->status = visual_styled_element(400,344,152,20,GetWidgetStyle(3),_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]))) != 0)
) {
					visual_button(400,344,152,20,vfh[2],16,0,_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto637=visual_trigger_code(_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]));
				if (((_Context->status = visual_styled_element(400,344,152,20,GetWidgetStyle(2),_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]))) != 0)
) {
	visual_button(400,344,152,20,vfh[2],16,0,_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]),32);
				}
				break;
			case	0x11 :
				/* Auto638 */
				_Context->trigger_Auto638=visual_trigger_code(_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]));
				if (((_Context->status = visual_styled_element(400,364,152,20,GetWidgetStyle(3),_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]))) != 0)
) {
					visual_button(400,364,152,20,vfh[2],16,0,_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto638=visual_trigger_code(_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]));
				if (((_Context->status = visual_styled_element(400,364,152,20,GetWidgetStyle(2),_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]))) != 0)
) {
	visual_button(400,364,152,20,vfh[2],16,0,_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]),32);
				}
				break;
			case	0x12 :
				/* Auto639 */
				_Context->trigger_Auto639=visual_trigger_code(_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]));
				if (((_Context->status = visual_styled_element(400,384,152,20,GetWidgetStyle(3),_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]))) != 0)
) {
					visual_button(400,384,152,20,vfh[2],16,0,_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto639=visual_trigger_code(_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]));
				if (((_Context->status = visual_styled_element(400,384,152,20,GetWidgetStyle(2),_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]))) != 0)
) {
	visual_button(400,384,152,20,vfh[2],16,0,_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]),32);
				}
				break;
			case	0x13 :
				/* Auto640 */
				_Context->trigger_Auto640=visual_trigger_code(_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]));
				if (((_Context->status = visual_styled_element(400,404,152,20,GetWidgetStyle(3),_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]))) != 0)
) {
					visual_button(400,404,152,20,vfh[2],16,0,_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto640=visual_trigger_code(_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]));
				if (((_Context->status = visual_styled_element(400,404,152,20,GetWidgetStyle(2),_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]))) != 0)
) {
	visual_button(400,404,152,20,vfh[2],16,0,_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]),32);
				}
				break;
			case	0x14 :
				/* Auto641 */
				_Context->trigger_Auto641=visual_trigger_code(_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]));
				if (((_Context->status = visual_styled_element(400,424,152,20,GetWidgetStyle(3),_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]))) != 0)
) {
					visual_button(400,424,152,20,vfh[2],16,0,_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto641=visual_trigger_code(_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]));
				if (((_Context->status = visual_styled_element(400,424,152,20,GetWidgetStyle(2),_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]))) != 0)
) {
	visual_button(400,424,152,20,vfh[2],16,0,_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]),32);
				}
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
			_Context->focus_item=20;
			forms_widget_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  384 )
				|| ( visual_event(6) <  32 )
				|| ( visual_event(7) >  568 )
				|| ( visual_event(6) >  456 )) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=forms_widget_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto622 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
						if (((_Context->status = visual_styled_element(400,44,152,20,GetWidgetStyle(3),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
							visual_button(400,44,152,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
						if (((_Context->status = visual_styled_element(400,44,152,20,GetWidgetStyle(2),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
	visual_button(400,44,152,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto622_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto623 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
						if (((_Context->status = visual_styled_element(400,64,152,20,GetWidgetStyle(3),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
							visual_button(400,64,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
						if (((_Context->status = visual_styled_element(400,64,152,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(400,64,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto623_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto624 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
						if (((_Context->status = visual_styled_element(400,84,152,20,GetWidgetStyle(3),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
							visual_button(400,84,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
						if (((_Context->status = visual_styled_element(400,84,152,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(400,84,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto624_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto625 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
						if (((_Context->status = visual_styled_element(400,104,152,20,GetWidgetStyle(3),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
							visual_button(400,104,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
						if (((_Context->status = visual_styled_element(400,104,152,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(400,104,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto625_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto626 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
						if (((_Context->status = visual_styled_element(400,124,152,20,GetWidgetStyle(3),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
							visual_button(400,124,152,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
						if (((_Context->status = visual_styled_element(400,124,152,20,GetWidgetStyle(2),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
	visual_button(400,124,152,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto626_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto627 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
						if (((_Context->status = visual_styled_element(400,144,152,20,GetWidgetStyle(3),_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]))) != 0)
) {
							visual_button(400,144,152,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
						if (((_Context->status = visual_styled_element(400,144,152,20,GetWidgetStyle(2),_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]))) != 0)
) {
	visual_button(400,144,152,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto627_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto628 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
						if (((_Context->status = visual_styled_element(400,164,152,20,GetWidgetStyle(3),_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]))) != 0)
) {
							visual_button(400,164,152,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
						if (((_Context->status = visual_styled_element(400,164,152,20,GetWidgetStyle(2),_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]))) != 0)
) {
	visual_button(400,164,152,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto628_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto629 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
						if (((_Context->status = visual_styled_element(400,184,152,20,GetWidgetStyle(3),_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]))) != 0)
) {
							visual_button(400,184,152,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
						if (((_Context->status = visual_styled_element(400,184,152,20,GetWidgetStyle(2),_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]))) != 0)
) {
	visual_button(400,184,152,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto629_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto630 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
						if (((_Context->status = visual_styled_element(400,204,152,20,GetWidgetStyle(3),_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]))) != 0)
) {
							visual_button(400,204,152,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
						if (((_Context->status = visual_styled_element(400,204,152,20,GetWidgetStyle(2),_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]))) != 0)
) {
	visual_button(400,204,152,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto630_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto631 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
						if (((_Context->status = visual_styled_element(400,224,152,20,GetWidgetStyle(3),_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]))) != 0)
) {
							visual_button(400,224,152,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
						if (((_Context->status = visual_styled_element(400,224,152,20,GetWidgetStyle(2),_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]))) != 0)
) {
	visual_button(400,224,152,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto631_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Auto632 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
						if (((_Context->status = visual_styled_element(400,244,152,20,GetWidgetStyle(3),_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]))) != 0)
) {
							visual_button(400,244,152,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
						if (((_Context->status = visual_styled_element(400,244,152,20,GetWidgetStyle(2),_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]))) != 0)
) {
	visual_button(400,244,152,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto632_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* Auto633 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto633=visual_trigger_code(_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]));
						if (((_Context->status = visual_styled_element(400,264,152,20,GetWidgetStyle(3),_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]))) != 0)
) {
							visual_button(400,264,152,20,vfh[2],16,0,_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto633=visual_trigger_code(_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]));
						if (((_Context->status = visual_styled_element(400,264,152,20,GetWidgetStyle(2),_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]))) != 0)
) {
	visual_button(400,264,152,20,vfh[2],16,0,_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto633_event(_Context)) != -1) break;

						}
					continue;
				case	0xd :
					/* Auto634 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto634=visual_trigger_code(_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]));
						if (((_Context->status = visual_styled_element(400,284,152,20,GetWidgetStyle(3),_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]))) != 0)
) {
							visual_button(400,284,152,20,vfh[2],16,0,_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto634=visual_trigger_code(_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]));
						if (((_Context->status = visual_styled_element(400,284,152,20,GetWidgetStyle(2),_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]))) != 0)
) {
	visual_button(400,284,152,20,vfh[2],16,0,_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto634_event(_Context)) != -1) break;

						}
					continue;
				case	0xe :
					/* Auto635 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto635=visual_trigger_code(_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]));
						if (((_Context->status = visual_styled_element(400,304,152,20,GetWidgetStyle(3),_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]))) != 0)
) {
							visual_button(400,304,152,20,vfh[2],16,0,_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto635=visual_trigger_code(_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]));
						if (((_Context->status = visual_styled_element(400,304,152,20,GetWidgetStyle(2),_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]))) != 0)
) {
	visual_button(400,304,152,20,vfh[2],16,0,_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto635_event(_Context)) != -1) break;

						}
					continue;
				case	0xf :
					/* Auto636 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto636=visual_trigger_code(_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]));
						if (((_Context->status = visual_styled_element(400,324,152,20,GetWidgetStyle(3),_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]))) != 0)
) {
							visual_button(400,324,152,20,vfh[2],16,0,_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto636=visual_trigger_code(_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]));
						if (((_Context->status = visual_styled_element(400,324,152,20,GetWidgetStyle(2),_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]))) != 0)
) {
	visual_button(400,324,152,20,vfh[2],16,0,_Context->msg_Auto636[_Context->language],strlen(_Context->msg_Auto636[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto636_event(_Context)) != -1) break;

						}
					continue;
				case	0x10 :
					/* Auto637 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto637=visual_trigger_code(_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]));
						if (((_Context->status = visual_styled_element(400,344,152,20,GetWidgetStyle(3),_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]))) != 0)
) {
							visual_button(400,344,152,20,vfh[2],16,0,_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto637=visual_trigger_code(_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]));
						if (((_Context->status = visual_styled_element(400,344,152,20,GetWidgetStyle(2),_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]))) != 0)
) {
	visual_button(400,344,152,20,vfh[2],16,0,_Context->msg_Auto637[_Context->language],strlen(_Context->msg_Auto637[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto637_event(_Context)) != -1) break;

						}
					continue;
				case	0x11 :
					/* Auto638 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto638=visual_trigger_code(_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]));
						if (((_Context->status = visual_styled_element(400,364,152,20,GetWidgetStyle(3),_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]))) != 0)
) {
							visual_button(400,364,152,20,vfh[2],16,0,_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto638=visual_trigger_code(_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]));
						if (((_Context->status = visual_styled_element(400,364,152,20,GetWidgetStyle(2),_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]))) != 0)
) {
	visual_button(400,364,152,20,vfh[2],16,0,_Context->msg_Auto638[_Context->language],strlen(_Context->msg_Auto638[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto638_event(_Context)) != -1) break;

						}
					continue;
				case	0x12 :
					/* Auto639 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto639=visual_trigger_code(_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]));
						if (((_Context->status = visual_styled_element(400,384,152,20,GetWidgetStyle(3),_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]))) != 0)
) {
							visual_button(400,384,152,20,vfh[2],16,0,_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto639=visual_trigger_code(_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]));
						if (((_Context->status = visual_styled_element(400,384,152,20,GetWidgetStyle(2),_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]))) != 0)
) {
	visual_button(400,384,152,20,vfh[2],16,0,_Context->msg_Auto639[_Context->language],strlen(_Context->msg_Auto639[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto639_event(_Context)) != -1) break;

						}
					continue;
				case	0x13 :
					/* Auto640 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto640=visual_trigger_code(_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]));
						if (((_Context->status = visual_styled_element(400,404,152,20,GetWidgetStyle(3),_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]))) != 0)
) {
							visual_button(400,404,152,20,vfh[2],16,0,_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto640=visual_trigger_code(_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]));
						if (((_Context->status = visual_styled_element(400,404,152,20,GetWidgetStyle(2),_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]))) != 0)
) {
	visual_button(400,404,152,20,vfh[2],16,0,_Context->msg_Auto640[_Context->language],strlen(_Context->msg_Auto640[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto640_event(_Context)) != -1) break;

						}
					continue;
				case	0x14 :
					/* Auto641 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto641=visual_trigger_code(_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]));
						if (((_Context->status = visual_styled_element(400,424,152,20,GetWidgetStyle(3),_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]))) != 0)
) {
							visual_button(400,424,152,20,vfh[2],16,0,_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto641=visual_trigger_code(_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]));
						if (((_Context->status = visual_styled_element(400,424,152,20,GetWidgetStyle(2),_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]))) != 0)
) {
	visual_button(400,424,152,20,vfh[2],16,0,_Context->msg_Auto641[_Context->language],strlen(_Context->msg_Auto641[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto641_event(_Context)) != -1) break;

						}
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
				_Context->focus_item=20;
			}
			continue;
		case	0x0 :
			
			continue;
		case	0xffffffff :
			
			continue;

			}
		break;
		}

	return( _Context->keycode );
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
