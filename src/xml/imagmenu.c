
#ifndef _imagmenu_c
#define _imagmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : imagmenu.xml                                             */
/* Target         : imagmenu.c                                               */
/* Identification : 0.0-1177512019-5209.5208                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Auto622   ""
#define en__Auto622   ""
#define en_Auto623   "&Copy"
#define fr_Auto623   "&Copier"
#define it_Auto623   "&Copy"
#define es_Auto623   "&Copy"
#define de_Auto623   "&Copy"
#define nl_Auto623   "&Copy"
#define pt_Auto623   "&Copy"
#define xx_Auto623   "&Copy"
#define en_Auto624   "&Paste"
#define fr_Auto624   "Co&ller"
#define it_Auto624   "&Paste"
#define es_Auto624   "&Paste"
#define de_Auto624   "&Paste"
#define nl_Auto624   "&Paste"
#define pt_Auto624   "&Paste"
#define xx_Auto624   "&Paste"
#define en__Auto624   ""
#define fr__Auto624   ""
#define it__Auto624   ""
#define es__Auto624   ""
#define de__Auto624   ""
#define nl__Auto624   ""
#define pt__Auto624   ""
#define xx__Auto624   ""
#define en_Auto625   "&Rotate 90ø"
#define fr_Auto625   "&Rotation 90ø"
#define it_Auto625   "&Rotate 90"
#define es_Auto625   "&Rotate 90"
#define de_Auto625   "&Rotate 90"
#define nl_Auto625   "&Rotate 90"
#define pt_Auto625   "&Rotate 90"
#define xx_Auto625   "&Rotate 90"
#define en__Auto625   ""
#define fr__Auto625   ""
#define it__Auto625   ""
#define es__Auto625   ""
#define de__Auto625   ""
#define nl__Auto625   ""
#define pt__Auto625   ""
#define xx__Auto625   ""
#define en_Auto626   "R&otate 180ø"
#define fr_Auto626   "Rot&ation 180ø"
#define it_Auto626   "R&otate 180"
#define es_Auto626   "R&otate 180"
#define de_Auto626   "R&otate 180"
#define nl_Auto626   "R&otate 180"
#define pt_Auto626   "R&otate 180"
#define xx_Auto626   "R&otate 180"
#define en__Auto626   ""
#define fr__Auto626   ""
#define it__Auto626   ""
#define es__Auto626   ""
#define de__Auto626   ""
#define nl__Auto626   ""
#define pt__Auto626   ""
#define xx__Auto626   ""
#define en_Auto627   "Ro&tate 270ø"
#define fr_Auto627   "Rotatio&n 270ø"
#define it_Auto627   "Ro&tate 270"
#define es_Auto627   "Ro&tate 270"
#define de_Auto627   "Ro&tate 270"
#define nl_Auto627   "Ro&tate 270"
#define pt_Auto627   "Ro&tate 270"
#define xx_Auto627   "Ro&tate 270"
#define en__Auto627   ""
#define fr__Auto627   ""
#define it__Auto627   ""
#define es__Auto627   ""
#define de__Auto627   ""
#define nl__Auto627   ""
#define pt__Auto627   ""
#define xx__Auto627   ""
#define en_Auto628   "C&hange Colour"
#define fr_Auto628   "C&hanger la couleur"
#define it_Auto628   "C&hange Colour"
#define es_Auto628   "C&hange Colour"
#define de_Auto628   "C&hange Colour"
#define nl_Auto628   "C&hange Colour"
#define pt_Auto628   "C&hange Colour"
#define xx_Auto628   "C&hange Colour"
#define en__Auto628   ""
#define fr__Auto628   ""
#define it__Auto628   ""
#define es__Auto628   ""
#define de__Auto628   ""
#define nl__Auto628   ""
#define pt__Auto628   ""
#define xx__Auto628   ""
#define en_Auto629   "&Grey Scale"
#define fr_Auto629   "Tons de &gris"
#define it_Auto629   "&Grey Scale"
#define es_Auto629   "&Grey Scale"
#define de_Auto629   "&Grey Scale"
#define nl_Auto629   "&Grey Scale"
#define pt_Auto629   "&Grey Scale"
#define xx_Auto629   "&Grey Scale"
#define en__Auto629   ""
#define fr__Auto629   ""
#define it__Auto629   ""
#define es__Auto629   ""
#define de__Auto629   ""
#define nl__Auto629   ""
#define pt__Auto629   ""
#define xx__Auto629   ""
#define en_Auto630   "&Vertical Mirror"
#define fr_Auto630   "Miroir &vertical"
#define it_Auto630   "&Vertical Mirror"
#define es_Auto630   "&Vertical Mirror"
#define de_Auto630   "&Vertical Mirror"
#define nl_Auto630   "&Vertical Mirror"
#define pt_Auto630   "&Vertical Mirror"
#define xx_Auto630   "&Vertical Mirror"
#define en__Auto630   ""
#define fr__Auto630   ""
#define it__Auto630   ""
#define es__Auto630   ""
#define de__Auto630   ""
#define nl__Auto630   ""
#define pt__Auto630   ""
#define xx__Auto630   ""
#define en_Auto631   "Hor&izontal Mirror"
#define fr_Auto631   "Miroir &horizontal"
#define it_Auto631   "Hor&izontal Mirror"
#define es_Auto631   "Hor&izontal Mirror"
#define de_Auto631   "Hor&izontal Mirror"
#define nl_Auto631   "Hor&izontal Mirror"
#define pt_Auto631   "Hor&izontal Mirror"
#define xx_Auto631   "Hor&izontal Mirror"
#define en__Auto631   ""
#define fr__Auto631   ""
#define it__Auto631   ""
#define es__Auto631   ""
#define de__Auto631   ""
#define nl__Auto631   ""
#define pt__Auto631   ""
#define xx__Auto631   ""
#define en_Auto632   "&Dimensions..."
#define fr_Auto632   "&Dimensions..."
#define it_Auto632   "&Dimensions..."
#define es_Auto632   "&Dimensions..."
#define de_Auto632   "&Dimensions..."
#define nl_Auto632   "&Dimensions..."
#define pt_Auto632   "&Dimensions..."
#define xx_Auto632   "&Dimensions..."
#define en__Auto632   ""
#define fr__Auto632   ""
#define it__Auto632   ""
#define es__Auto632   ""
#define de__Auto632   ""
#define nl__Auto632   ""
#define pt__Auto632   ""
#define xx__Auto632   ""

private struct image_editor_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * hint_Auto622[8];
	int	s_Auto622;
	void *	p_Auto622;
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
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct image_editor_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = image_editor_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}


public	int	image_editor_menu_create(struct image_editor_menu_context **cptr)
{

	int i;
	struct image_editor_menu_context * _Context=(struct image_editor_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct image_editor_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=10;
	_Context->hint_Auto622[0]=en__Auto622;
	_Context->s_Auto622=0;
	_Context->p_Auto622=visual_buffer(264,36,184+2,224+2);
	mouse_move_on();
	for (i=0; i < 8; i++)_Context->msg_Auto623[i]=" ";
	_Context->msg_Auto623[0]=en_Auto623;
	_Context->msg_Auto623[1]=fr_Auto623;
	_Context->msg_Auto623[2]=it_Auto623;
	_Context->msg_Auto623[3]=es_Auto623;
	_Context->msg_Auto623[4]=de_Auto623;
	_Context->msg_Auto623[5]=nl_Auto623;
	_Context->msg_Auto623[6]=pt_Auto623;
	_Context->msg_Auto623[7]=xx_Auto623;
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
	_Context->hint_Auto625[0]=en__Auto625;
	_Context->hint_Auto625[1]=fr__Auto625;
	_Context->hint_Auto625[2]=it__Auto625;
	_Context->hint_Auto625[3]=es__Auto625;
	_Context->hint_Auto625[4]=de__Auto625;
	_Context->hint_Auto625[5]=nl__Auto625;
	_Context->hint_Auto625[6]=pt__Auto625;
	_Context->hint_Auto625[7]=xx__Auto625;
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
	_Context->hint_Auto627[0]=en__Auto627;
	_Context->hint_Auto627[1]=fr__Auto627;
	_Context->hint_Auto627[2]=it__Auto627;
	_Context->hint_Auto627[3]=es__Auto627;
	_Context->hint_Auto627[4]=de__Auto627;
	_Context->hint_Auto627[5]=nl__Auto627;
	_Context->hint_Auto627[6]=pt__Auto627;
	_Context->hint_Auto627[7]=xx__Auto627;
	for (i=0; i < 8; i++)_Context->msg_Auto628[i]=" ";
	_Context->msg_Auto628[0]=en_Auto628;
	_Context->msg_Auto628[1]=fr_Auto628;
	_Context->msg_Auto628[2]=it_Auto628;
	_Context->msg_Auto628[3]=es_Auto628;
	_Context->msg_Auto628[4]=de_Auto628;
	_Context->msg_Auto628[5]=nl_Auto628;
	_Context->msg_Auto628[6]=pt_Auto628;
	_Context->msg_Auto628[7]=xx_Auto628;
	_Context->hint_Auto628[0]=en__Auto628;
	_Context->hint_Auto628[1]=fr__Auto628;
	_Context->hint_Auto628[2]=it__Auto628;
	_Context->hint_Auto628[3]=es__Auto628;
	_Context->hint_Auto628[4]=de__Auto628;
	_Context->hint_Auto628[5]=nl__Auto628;
	_Context->hint_Auto628[6]=pt__Auto628;
	_Context->hint_Auto628[7]=xx__Auto628;
	for (i=0; i < 8; i++)_Context->msg_Auto629[i]=" ";
	_Context->msg_Auto629[0]=en_Auto629;
	_Context->msg_Auto629[1]=fr_Auto629;
	_Context->msg_Auto629[2]=it_Auto629;
	_Context->msg_Auto629[3]=es_Auto629;
	_Context->msg_Auto629[4]=de_Auto629;
	_Context->msg_Auto629[5]=nl_Auto629;
	_Context->msg_Auto629[6]=pt_Auto629;
	_Context->msg_Auto629[7]=xx_Auto629;
	_Context->hint_Auto629[0]=en__Auto629;
	_Context->hint_Auto629[1]=fr__Auto629;
	_Context->hint_Auto629[2]=it__Auto629;
	_Context->hint_Auto629[3]=es__Auto629;
	_Context->hint_Auto629[4]=de__Auto629;
	_Context->hint_Auto629[5]=nl__Auto629;
	_Context->hint_Auto629[6]=pt__Auto629;
	_Context->hint_Auto629[7]=xx__Auto629;
	for (i=0; i < 8; i++)_Context->msg_Auto630[i]=" ";
	_Context->msg_Auto630[0]=en_Auto630;
	_Context->msg_Auto630[1]=fr_Auto630;
	_Context->msg_Auto630[2]=it_Auto630;
	_Context->msg_Auto630[3]=es_Auto630;
	_Context->msg_Auto630[4]=de_Auto630;
	_Context->msg_Auto630[5]=nl_Auto630;
	_Context->msg_Auto630[6]=pt_Auto630;
	_Context->msg_Auto630[7]=xx_Auto630;
	_Context->hint_Auto630[0]=en__Auto630;
	_Context->hint_Auto630[1]=fr__Auto630;
	_Context->hint_Auto630[2]=it__Auto630;
	_Context->hint_Auto630[3]=es__Auto630;
	_Context->hint_Auto630[4]=de__Auto630;
	_Context->hint_Auto630[5]=nl__Auto630;
	_Context->hint_Auto630[6]=pt__Auto630;
	_Context->hint_Auto630[7]=xx__Auto630;
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
	return(0);
}

public 	int	image_editor_menu_hide(struct image_editor_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto622 != (void *) 0)
	&& (_Context->s_Auto622 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto622,264,36);
		_Context->s_Auto622=0;
		}

	return(result);
}

public	int	image_editor_menu_remove(struct image_editor_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto622 != (void *) 0)
		_Context->p_Auto622 = visual_drop(_Context->p_Auto622);
	_Context=liberate(_Context);

	return(result);
}

public	int	image_editor_menu_show(struct image_editor_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Auto622 != (void *) 0)
	&& (_Context->s_Auto622 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto622,264,36);
		_Context->s_Auto622=1;
		}
	if (((_Context->status = visual_styled_element(264,36,184,224,GetWidgetStyle(1)," ",0)) != 0)
) {
		visual_filzone(264,36,184,224,27,11);
		}
	_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
	if (((_Context->status = visual_styled_element(280,48,152,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(280,48,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
		}
	_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
	if (((_Context->status = visual_styled_element(280,68,152,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(280,68,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
		}
	_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
	if (((_Context->status = visual_styled_element(280,88,152,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(280,88,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
		}
	_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
	if (((_Context->status = visual_styled_element(280,108,152,20,GetWidgetStyle(2),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
	visual_button(280,108,152,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),32);
		}
	_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
	if (((_Context->status = visual_styled_element(280,128,152,20,GetWidgetStyle(2),_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]))) != 0)
) {
	visual_button(280,128,152,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),32);
		}
	_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
	if (((_Context->status = visual_styled_element(280,148,152,20,GetWidgetStyle(2),_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]))) != 0)
) {
	visual_button(280,148,152,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),32);
		}
	_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
	if (((_Context->status = visual_styled_element(280,168,152,20,GetWidgetStyle(2),_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]))) != 0)
) {
	visual_button(280,168,152,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),32);
		}
	_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
	if (((_Context->status = visual_styled_element(280,188,152,20,GetWidgetStyle(2),_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]))) != 0)
) {
	visual_button(280,188,152,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),32);
		}
	_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
	if (((_Context->status = visual_styled_element(280,208,152,20,GetWidgetStyle(2),_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]))) != 0)
) {
	visual_button(280,208,152,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),32);
		}
	_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
	if (((_Context->status = visual_styled_element(280,228,152,20,GetWidgetStyle(2),_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]))) != 0)
) {
	visual_button(280,228,152,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),32);
		}
	visual_thaw(264,36,184,224);

	return(0);
}
private int on_Auto623_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_COPY);
	return(-1);
}
private int on_Auto624_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_PASTE);
	return(-1);
}
private int on_Auto625_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_ROTATE1);
	return(-1);
}
private int on_Auto626_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_ROTATE2);
	return(-1);
}
private int on_Auto627_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_ROTATE3);
	return(-1);
}
private int on_Auto628_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_COLOUR);
	return(-1);
}
private int on_Auto629_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_GREY);
	return(-1);
}
private int on_Auto630_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_REFLECTY);
	return(-1);
}
private int on_Auto631_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_REFLECTX);
	return(-1);
}
private int on_Auto632_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_CHANGE);
	return(-1);
}


public	int	image_editor_menu_event(
struct image_editor_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto623 == mb ) return(1);
		if (_Context->trigger_Auto624 == mb ) return(2);
		if (_Context->trigger_Auto625 == mb ) return(3);
		if (_Context->trigger_Auto626 == mb ) return(4);
		if (_Context->trigger_Auto627 == mb ) return(5);
		if (_Context->trigger_Auto628 == mb ) return(6);
		if (_Context->trigger_Auto629 == mb ) return(7);
		if (_Context->trigger_Auto630 == mb ) return(8);
		if (_Context->trigger_Auto631 == mb ) return(9);
		if (_Context->trigger_Auto632 == mb ) return(10);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 280 ) 
	&&  ( my >= 48 ) 
	&&  ( mx <= 432 ) 
	&&  ( my <= 68 )) {
		return(1); /* Auto623 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 432 ) 
	&&  ( my <= 88 )) {
		return(2); /* Auto624 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 88 ) 
	&&  ( mx <= 432 ) 
	&&  ( my <= 108 )) {
		return(3); /* Auto625 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 108 ) 
	&&  ( mx <= 432 ) 
	&&  ( my <= 128 )) {
		return(4); /* Auto626 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 128 ) 
	&&  ( mx <= 432 ) 
	&&  ( my <= 148 )) {
		return(5); /* Auto627 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 148 ) 
	&&  ( mx <= 432 ) 
	&&  ( my <= 168 )) {
		return(6); /* Auto628 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 168 ) 
	&&  ( mx <= 432 ) 
	&&  ( my <= 188 )) {
		return(7); /* Auto629 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 188 ) 
	&&  ( mx <= 432 ) 
	&&  ( my <= 208 )) {
		return(8); /* Auto630 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 208 ) 
	&&  ( mx <= 432 ) 
	&&  ( my <= 228 )) {
		return(9); /* Auto631 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 228 ) 
	&&  ( mx <= 432 ) 
	&&  ( my <= 248 )) {
		return(10); /* Auto632 */
		}

	return(-1);
}


public	int	image_editor_menu_focus(struct image_editor_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto623 */
				_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
				if (((_Context->status = visual_styled_element(280,48,152,20,GetWidgetStyle(3),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
					visual_button(280,48,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
				if (((_Context->status = visual_styled_element(280,48,152,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(280,48,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto624 */
				_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
				if (((_Context->status = visual_styled_element(280,68,152,20,GetWidgetStyle(3),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
					visual_button(280,68,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
				if (((_Context->status = visual_styled_element(280,68,152,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(280,68,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto625 */
				_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
				if (((_Context->status = visual_styled_element(280,88,152,20,GetWidgetStyle(3),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
					visual_button(280,88,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
				if (((_Context->status = visual_styled_element(280,88,152,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(280,88,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto626 */
				_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
				if (((_Context->status = visual_styled_element(280,108,152,20,GetWidgetStyle(3),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
					visual_button(280,108,152,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
				if (((_Context->status = visual_styled_element(280,108,152,20,GetWidgetStyle(2),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
	visual_button(280,108,152,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto627 */
				_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
				if (((_Context->status = visual_styled_element(280,128,152,20,GetWidgetStyle(3),_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]))) != 0)
) {
					visual_button(280,128,152,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
				if (((_Context->status = visual_styled_element(280,128,152,20,GetWidgetStyle(2),_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]))) != 0)
) {
	visual_button(280,128,152,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto628 */
				_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
				if (((_Context->status = visual_styled_element(280,148,152,20,GetWidgetStyle(3),_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]))) != 0)
) {
					visual_button(280,148,152,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
				if (((_Context->status = visual_styled_element(280,148,152,20,GetWidgetStyle(2),_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]))) != 0)
) {
	visual_button(280,148,152,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* Auto629 */
				_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
				if (((_Context->status = visual_styled_element(280,168,152,20,GetWidgetStyle(3),_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]))) != 0)
) {
					visual_button(280,168,152,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
				if (((_Context->status = visual_styled_element(280,168,152,20,GetWidgetStyle(2),_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]))) != 0)
) {
	visual_button(280,168,152,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto630 */
				_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
				if (((_Context->status = visual_styled_element(280,188,152,20,GetWidgetStyle(3),_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]))) != 0)
) {
					visual_button(280,188,152,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
				if (((_Context->status = visual_styled_element(280,188,152,20,GetWidgetStyle(2),_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]))) != 0)
) {
	visual_button(280,188,152,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),32);
				}
				break;
			case	0x9 :
				/* Auto631 */
				_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
				if (((_Context->status = visual_styled_element(280,208,152,20,GetWidgetStyle(3),_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]))) != 0)
) {
					visual_button(280,208,152,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
				if (((_Context->status = visual_styled_element(280,208,152,20,GetWidgetStyle(2),_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]))) != 0)
) {
	visual_button(280,208,152,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),32);
				}
				break;
			case	0xa :
				/* Auto632 */
				_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
				if (((_Context->status = visual_styled_element(280,228,152,20,GetWidgetStyle(3),_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]))) != 0)
) {
					visual_button(280,228,152,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
				if (((_Context->status = visual_styled_element(280,228,152,20,GetWidgetStyle(2),_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]))) != 0)
) {
	visual_button(280,228,152,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			image_editor_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=10;
			image_editor_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  264 )
				|| ( visual_event(6) <  36 )
				|| ( visual_event(7) >  448 )
				|| ( visual_event(6) >  260 )) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=image_editor_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto623 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
						if (((_Context->status = visual_styled_element(280,48,152,20,GetWidgetStyle(3),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
							visual_button(280,48,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
						if (((_Context->status = visual_styled_element(280,48,152,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(280,48,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto623_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto624 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
						if (((_Context->status = visual_styled_element(280,68,152,20,GetWidgetStyle(3),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
							visual_button(280,68,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
						if (((_Context->status = visual_styled_element(280,68,152,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(280,68,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto624_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto625 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
						if (((_Context->status = visual_styled_element(280,88,152,20,GetWidgetStyle(3),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
							visual_button(280,88,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
						if (((_Context->status = visual_styled_element(280,88,152,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(280,88,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto625_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto626 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
						if (((_Context->status = visual_styled_element(280,108,152,20,GetWidgetStyle(3),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
							visual_button(280,108,152,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
						if (((_Context->status = visual_styled_element(280,108,152,20,GetWidgetStyle(2),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
	visual_button(280,108,152,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto626_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto627 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
						if (((_Context->status = visual_styled_element(280,128,152,20,GetWidgetStyle(3),_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]))) != 0)
) {
							visual_button(280,128,152,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
						if (((_Context->status = visual_styled_element(280,128,152,20,GetWidgetStyle(2),_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]))) != 0)
) {
	visual_button(280,128,152,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto627_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto628 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
						if (((_Context->status = visual_styled_element(280,148,152,20,GetWidgetStyle(3),_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]))) != 0)
) {
							visual_button(280,148,152,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
						if (((_Context->status = visual_styled_element(280,148,152,20,GetWidgetStyle(2),_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]))) != 0)
) {
	visual_button(280,148,152,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto628_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto629 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
						if (((_Context->status = visual_styled_element(280,168,152,20,GetWidgetStyle(3),_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]))) != 0)
) {
							visual_button(280,168,152,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
						if (((_Context->status = visual_styled_element(280,168,152,20,GetWidgetStyle(2),_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]))) != 0)
) {
	visual_button(280,168,152,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto629_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto630 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
						if (((_Context->status = visual_styled_element(280,188,152,20,GetWidgetStyle(3),_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]))) != 0)
) {
							visual_button(280,188,152,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
						if (((_Context->status = visual_styled_element(280,188,152,20,GetWidgetStyle(2),_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]))) != 0)
) {
	visual_button(280,188,152,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto630_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto631 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
						if (((_Context->status = visual_styled_element(280,208,152,20,GetWidgetStyle(3),_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]))) != 0)
) {
							visual_button(280,208,152,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
						if (((_Context->status = visual_styled_element(280,208,152,20,GetWidgetStyle(2),_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]))) != 0)
) {
	visual_button(280,208,152,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto631_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto632 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
						if (((_Context->status = visual_styled_element(280,228,152,20,GetWidgetStyle(3),_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]))) != 0)
) {
							visual_button(280,228,152,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
						if (((_Context->status = visual_styled_element(280,228,152,20,GetWidgetStyle(2),_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]))) != 0)
) {
	visual_button(280,228,152,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto632_event(_Context)) != -1) break;

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
				_Context->focus_item=10;
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

public	int	image_editor_menu()
{
	int	status=0;
	struct image_editor_menu_context * _Context=(struct image_editor_menu_context*) 0;
	status = image_editor_menu_create(&_Context);
	if ( status != 0) return(status);
	status = image_editor_menu_show(_Context);
		enter_modal();
	status = image_editor_menu_focus(_Context);
		leave_modal();
	status = image_editor_menu_hide(_Context);
	status = image_editor_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _imagmenu_c */
