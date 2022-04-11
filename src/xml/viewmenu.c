
#ifndef _viewmenu_c
#define _viewmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : viewmenu.xml                                             */
/* Target         : viewmenu.c                                               */
/* Identification : 0.0-1196107200-4252.4251                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Frame   ""
#define en__Frame   ""
#define en_Auto311   "&Run..."
#define fr_Auto311   "&Ex‚cuter..."
#define it_Auto311   "&Run..."
#define es_Auto311   "&Run..."
#define de_Auto311   "&Run..."
#define nl_Auto311   "&Run..."
#define pt_Auto311   "&Run..."
#define xx_Auto311   "&Run..."
#define en__Auto311   ""
#define fr__Auto311   ""
#define it__Auto311   ""
#define es__Auto311   ""
#define de__Auto311   ""
#define nl__Auto311   ""
#define pt__Auto311   ""
#define xx__Auto311   ""
#define en_Auto312   "&Text"
#define fr_Auto312   "&Texte"
#define it_Auto312   "&Text"
#define es_Auto312   "&Text"
#define de_Auto312   "&Text"
#define nl_Auto312   "&Text"
#define pt_Auto312   "&Text"
#define xx_Auto312   "&Text"
#define en_Auto313   "&Image"
#define fr_Auto313   "&Image"
#define it_Auto313   "&Image"
#define es_Auto313   "&Image"
#define de_Auto313   "&Image"
#define nl_Auto313   "&Image"
#define pt_Auto313   "&Image"
#define xx_Auto313   "&Image"
#define en__Auto313   ""
#define en_Auto314   "&Font..."
#define fr_Auto314   "&Police..."
#define it_Auto314   "&Font..."
#define es_Auto314   "&Font..."
#define de_Auto314   "&Font..."
#define nl_Auto314   "&Font..."
#define pt_Auto314   "&Font..."
#define xx_Auto314   "&Font..."
#define en__Auto314   ""
#define fr__Auto314   ""
#define it__Auto314   ""
#define es__Auto314   ""
#define de__Auto314   ""
#define nl__Auto314   ""
#define pt__Auto314   ""
#define xx__Auto314   ""
#define en_Auto315   "&Properties..."
#define fr_Auto315   "P&ropri‚t‚s..."
#define it_Auto315   "&Production..."
#define es_Auto315   "&Production..."
#define de_Auto315   "&Produktion..."
#define nl_Auto315   "&Production..."
#define pt_Auto315   "&Production..."
#define xx_Auto315   "&Production..."
#define en__Auto315   ""
#define fr__Auto315   ""
#define it__Auto315   ""
#define es__Auto315   ""
#define de__Auto315   ""
#define nl__Auto315   ""
#define pt__Auto315   ""
#define xx__Auto315   ""
#define en_Auto316   "&Visual"
#define fr_Auto316   "E&space de travail"
#define it_Auto316   "&Visual"
#define es_Auto316   "&Visual"
#define de_Auto316   "&Visual"
#define nl_Auto316   "&Visual"
#define pt_Auto316   "&Visual"
#define xx_Auto316   "&Visual"
#define en__Auto316   ""
#define fr__Auto316   ""
#define it__Auto316   ""
#define es__Auto316   ""
#define de__Auto316   ""
#define nl__Auto316   ""
#define pt__Auto316   ""
#define xx__Auto316   ""
#define en_Auto317   "&Database"
#define fr_Auto317   "&Base de donn‚es..."
#define it_Auto317   "&DataBase..."
#define es_Auto317   "&DataBase..."
#define de_Auto317   "&DataBase..."
#define nl_Auto317   "&DataBase..."
#define pt_Auto317   "&DataBase..."
#define xx_Auto317   "&DataBase..."
#define en__Auto317   ""
#define fr__Auto317   ""
#define it__Auto317   ""
#define es__Auto317   ""
#define de__Auto317   ""
#define nl__Auto317   ""
#define pt__Auto317   ""
#define xx__Auto317   ""
#define en_Auto318   "&Style..."
#define fr_Auto318   "St&yle..."
#define it_Auto318   "&Style..."
#define es_Auto318   "&Style..."
#define de_Auto318   "&Style..."
#define nl_Auto318   "&Style..."
#define pt_Auto318   "&Style..."
#define xx_Auto318   "&Style..."
#define en__Auto318   ""
#define fr__Auto318   ""
#define it__Auto318   ""
#define es__Auto318   ""
#define de__Auto318   ""
#define nl__Auto318   ""
#define pt__Auto318   ""
#define xx__Auto318   ""
#define en_Auto319   "&Model..."
#define fr_Auto319   "&ModŠle..."
#define it_Auto319   "&Model..."
#define es_Auto319   "&Model..."
#define de_Auto319   "&Model..."
#define nl_Auto319   "&Model..."
#define pt_Auto319   "&Model..."
#define xx_Auto319   "&Model..."
#define en__Auto319   ""
#define fr__Auto319   ""
#define it__Auto319   ""
#define es__Auto319   ""
#define de__Auto319   ""
#define nl__Auto319   ""
#define pt__Auto319   ""
#define xx__Auto319   ""
#define en_Auto320   "Tr&eeView"
#define fr_Auto320   "Arb&oresence projet"
#define it_Auto320   "Tr&eeView"
#define es_Auto320   "Tr&eeView"
#define de_Auto320   "Tr&eeView"
#define nl_Auto320   "Tr&eeView"
#define pt_Auto320   "Tr&eeView"
#define xx_Auto320   "Tr&eeView"
#define en__Auto320   ""
#define fr__Auto320   ""
#define it__Auto320   ""
#define es__Auto320   ""
#define de__Auto320   ""
#define nl__Auto320   ""
#define pt__Auto320   ""
#define xx__Auto320   ""
#define en_Auto321   "Appli&cation"
#define fr_Auto321   "Appli&cation"
#define it_Auto321   "Appli&cation"
#define es_Auto321   "Appli&cation"
#define de_Auto321   "Appli&cation"
#define nl_Auto321   "Appli&cation"
#define pt_Auto321   "Appli&cation"
#define xx_Auto321   "Appli&cation"
#define en__Auto321   ""

private struct standard_view_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * hint_Frame[8];
	int	s_Frame;
	void *	p_Frame;
	char * msg_Auto311[8];
	int	trigger_Auto311;
	char * hint_Auto311[8];
	char * msg_Auto312[8];
	int	trigger_Auto312;
	char * hint_Auto312[8];
	char * msg_Auto313[8];
	int	trigger_Auto313;
	char * hint_Auto313[8];
	char * msg_Auto314[8];
	int	trigger_Auto314;
	char * hint_Auto314[8];
	char * msg_Auto315[8];
	int	trigger_Auto315;
	char * hint_Auto315[8];
	char * msg_Auto316[8];
	int	trigger_Auto316;
	char * hint_Auto316[8];
	char * msg_Auto317[8];
	int	trigger_Auto317;
	char * hint_Auto317[8];
	char * msg_Auto318[8];
	int	trigger_Auto318;
	char * hint_Auto318[8];
	char * msg_Auto319[8];
	int	trigger_Auto319;
	char * hint_Auto319[8];
	char * msg_Auto320[8];
	int	trigger_Auto320;
	char * hint_Auto320[8];
	char * msg_Auto321[8];
	int	trigger_Auto321;
	char * hint_Auto321[8];
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct standard_view_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = standard_view_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Frame_create(struct standard_view_menu_context * _Context) {
	mouse_move_on();
	return(-1);
}

public	int	standard_view_menu_create(struct standard_view_menu_context **cptr)
{

	int i;
	struct standard_view_menu_context * _Context=(struct standard_view_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct standard_view_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=11;
	_Context->hint_Frame[0]=en__Frame;
	_Context->s_Frame=0;
	_Context->p_Frame=visual_buffer(128,32,168+2,244+2);
	(void) on_Frame_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto311[i]=" ";
	_Context->msg_Auto311[0]=en_Auto311;
	_Context->msg_Auto311[1]=fr_Auto311;
	_Context->msg_Auto311[2]=it_Auto311;
	_Context->msg_Auto311[3]=es_Auto311;
	_Context->msg_Auto311[4]=de_Auto311;
	_Context->msg_Auto311[5]=nl_Auto311;
	_Context->msg_Auto311[6]=pt_Auto311;
	_Context->msg_Auto311[7]=xx_Auto311;
	_Context->hint_Auto311[0]=en__Auto311;
	_Context->hint_Auto311[1]=fr__Auto311;
	_Context->hint_Auto311[2]=it__Auto311;
	_Context->hint_Auto311[3]=es__Auto311;
	_Context->hint_Auto311[4]=de__Auto311;
	_Context->hint_Auto311[5]=nl__Auto311;
	_Context->hint_Auto311[6]=pt__Auto311;
	_Context->hint_Auto311[7]=xx__Auto311;
	for (i=0; i < 8; i++)_Context->msg_Auto312[i]=" ";
	_Context->msg_Auto312[0]=en_Auto312;
	_Context->msg_Auto312[1]=fr_Auto312;
	_Context->msg_Auto312[2]=it_Auto312;
	_Context->msg_Auto312[3]=es_Auto312;
	_Context->msg_Auto312[4]=de_Auto312;
	_Context->msg_Auto312[5]=nl_Auto312;
	_Context->msg_Auto312[6]=pt_Auto312;
	_Context->msg_Auto312[7]=xx_Auto312;
	for (i=0; i < 8; i++)_Context->msg_Auto313[i]=" ";
	_Context->msg_Auto313[0]=en_Auto313;
	_Context->msg_Auto313[1]=fr_Auto313;
	_Context->msg_Auto313[2]=it_Auto313;
	_Context->msg_Auto313[3]=es_Auto313;
	_Context->msg_Auto313[4]=de_Auto313;
	_Context->msg_Auto313[5]=nl_Auto313;
	_Context->msg_Auto313[6]=pt_Auto313;
	_Context->msg_Auto313[7]=xx_Auto313;
	_Context->hint_Auto313[0]=en__Auto313;
	for (i=0; i < 8; i++)_Context->msg_Auto314[i]=" ";
	_Context->msg_Auto314[0]=en_Auto314;
	_Context->msg_Auto314[1]=fr_Auto314;
	_Context->msg_Auto314[2]=it_Auto314;
	_Context->msg_Auto314[3]=es_Auto314;
	_Context->msg_Auto314[4]=de_Auto314;
	_Context->msg_Auto314[5]=nl_Auto314;
	_Context->msg_Auto314[6]=pt_Auto314;
	_Context->msg_Auto314[7]=xx_Auto314;
	_Context->hint_Auto314[0]=en__Auto314;
	_Context->hint_Auto314[1]=fr__Auto314;
	_Context->hint_Auto314[2]=it__Auto314;
	_Context->hint_Auto314[3]=es__Auto314;
	_Context->hint_Auto314[4]=de__Auto314;
	_Context->hint_Auto314[5]=nl__Auto314;
	_Context->hint_Auto314[6]=pt__Auto314;
	_Context->hint_Auto314[7]=xx__Auto314;
	for (i=0; i < 8; i++)_Context->msg_Auto315[i]=" ";
	_Context->msg_Auto315[0]=en_Auto315;
	_Context->msg_Auto315[1]=fr_Auto315;
	_Context->msg_Auto315[2]=it_Auto315;
	_Context->msg_Auto315[3]=es_Auto315;
	_Context->msg_Auto315[4]=de_Auto315;
	_Context->msg_Auto315[5]=nl_Auto315;
	_Context->msg_Auto315[6]=pt_Auto315;
	_Context->msg_Auto315[7]=xx_Auto315;
	_Context->hint_Auto315[0]=en__Auto315;
	_Context->hint_Auto315[1]=fr__Auto315;
	_Context->hint_Auto315[2]=it__Auto315;
	_Context->hint_Auto315[3]=es__Auto315;
	_Context->hint_Auto315[4]=de__Auto315;
	_Context->hint_Auto315[5]=nl__Auto315;
	_Context->hint_Auto315[6]=pt__Auto315;
	_Context->hint_Auto315[7]=xx__Auto315;
	for (i=0; i < 8; i++)_Context->msg_Auto316[i]=" ";
	_Context->msg_Auto316[0]=en_Auto316;
	_Context->msg_Auto316[1]=fr_Auto316;
	_Context->msg_Auto316[2]=it_Auto316;
	_Context->msg_Auto316[3]=es_Auto316;
	_Context->msg_Auto316[4]=de_Auto316;
	_Context->msg_Auto316[5]=nl_Auto316;
	_Context->msg_Auto316[6]=pt_Auto316;
	_Context->msg_Auto316[7]=xx_Auto316;
	_Context->hint_Auto316[0]=en__Auto316;
	_Context->hint_Auto316[1]=fr__Auto316;
	_Context->hint_Auto316[2]=it__Auto316;
	_Context->hint_Auto316[3]=es__Auto316;
	_Context->hint_Auto316[4]=de__Auto316;
	_Context->hint_Auto316[5]=nl__Auto316;
	_Context->hint_Auto316[6]=pt__Auto316;
	_Context->hint_Auto316[7]=xx__Auto316;
	for (i=0; i < 8; i++)_Context->msg_Auto317[i]=" ";
	_Context->msg_Auto317[0]=en_Auto317;
	_Context->msg_Auto317[1]=fr_Auto317;
	_Context->msg_Auto317[2]=it_Auto317;
	_Context->msg_Auto317[3]=es_Auto317;
	_Context->msg_Auto317[4]=de_Auto317;
	_Context->msg_Auto317[5]=nl_Auto317;
	_Context->msg_Auto317[6]=pt_Auto317;
	_Context->msg_Auto317[7]=xx_Auto317;
	_Context->hint_Auto317[0]=en__Auto317;
	_Context->hint_Auto317[1]=fr__Auto317;
	_Context->hint_Auto317[2]=it__Auto317;
	_Context->hint_Auto317[3]=es__Auto317;
	_Context->hint_Auto317[4]=de__Auto317;
	_Context->hint_Auto317[5]=nl__Auto317;
	_Context->hint_Auto317[6]=pt__Auto317;
	_Context->hint_Auto317[7]=xx__Auto317;
	for (i=0; i < 8; i++)_Context->msg_Auto318[i]=" ";
	_Context->msg_Auto318[0]=en_Auto318;
	_Context->msg_Auto318[1]=fr_Auto318;
	_Context->msg_Auto318[2]=it_Auto318;
	_Context->msg_Auto318[3]=es_Auto318;
	_Context->msg_Auto318[4]=de_Auto318;
	_Context->msg_Auto318[5]=nl_Auto318;
	_Context->msg_Auto318[6]=pt_Auto318;
	_Context->msg_Auto318[7]=xx_Auto318;
	_Context->hint_Auto318[0]=en__Auto318;
	_Context->hint_Auto318[1]=fr__Auto318;
	_Context->hint_Auto318[2]=it__Auto318;
	_Context->hint_Auto318[3]=es__Auto318;
	_Context->hint_Auto318[4]=de__Auto318;
	_Context->hint_Auto318[5]=nl__Auto318;
	_Context->hint_Auto318[6]=pt__Auto318;
	_Context->hint_Auto318[7]=xx__Auto318;
	for (i=0; i < 8; i++)_Context->msg_Auto319[i]=" ";
	_Context->msg_Auto319[0]=en_Auto319;
	_Context->msg_Auto319[1]=fr_Auto319;
	_Context->msg_Auto319[2]=it_Auto319;
	_Context->msg_Auto319[3]=es_Auto319;
	_Context->msg_Auto319[4]=de_Auto319;
	_Context->msg_Auto319[5]=nl_Auto319;
	_Context->msg_Auto319[6]=pt_Auto319;
	_Context->msg_Auto319[7]=xx_Auto319;
	_Context->hint_Auto319[0]=en__Auto319;
	_Context->hint_Auto319[1]=fr__Auto319;
	_Context->hint_Auto319[2]=it__Auto319;
	_Context->hint_Auto319[3]=es__Auto319;
	_Context->hint_Auto319[4]=de__Auto319;
	_Context->hint_Auto319[5]=nl__Auto319;
	_Context->hint_Auto319[6]=pt__Auto319;
	_Context->hint_Auto319[7]=xx__Auto319;
	for (i=0; i < 8; i++)_Context->msg_Auto320[i]=" ";
	_Context->msg_Auto320[0]=en_Auto320;
	_Context->msg_Auto320[1]=fr_Auto320;
	_Context->msg_Auto320[2]=it_Auto320;
	_Context->msg_Auto320[3]=es_Auto320;
	_Context->msg_Auto320[4]=de_Auto320;
	_Context->msg_Auto320[5]=nl_Auto320;
	_Context->msg_Auto320[6]=pt_Auto320;
	_Context->msg_Auto320[7]=xx_Auto320;
	_Context->hint_Auto320[0]=en__Auto320;
	_Context->hint_Auto320[1]=fr__Auto320;
	_Context->hint_Auto320[2]=it__Auto320;
	_Context->hint_Auto320[3]=es__Auto320;
	_Context->hint_Auto320[4]=de__Auto320;
	_Context->hint_Auto320[5]=nl__Auto320;
	_Context->hint_Auto320[6]=pt__Auto320;
	_Context->hint_Auto320[7]=xx__Auto320;
	for (i=0; i < 8; i++)_Context->msg_Auto321[i]=" ";
	_Context->msg_Auto321[0]=en_Auto321;
	_Context->msg_Auto321[1]=fr_Auto321;
	_Context->msg_Auto321[2]=it_Auto321;
	_Context->msg_Auto321[3]=es_Auto321;
	_Context->msg_Auto321[4]=de_Auto321;
	_Context->msg_Auto321[5]=nl_Auto321;
	_Context->msg_Auto321[6]=pt_Auto321;
	_Context->msg_Auto321[7]=xx_Auto321;
	_Context->hint_Auto321[0]=en__Auto321;
	return(0);
}

public 	int	standard_view_menu_hide(struct standard_view_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Frame != (void *) 0)
	&& (_Context->s_Frame != 0)) {
		(void)visual_buffer_put(_Context->p_Frame,128,32);
		_Context->s_Frame=0;
		}

	return(result);
}
private int on_Frame_remove(struct standard_view_menu_context * _Context) {
	mouse_move_off();
	return(-1);
}

public	int	standard_view_menu_remove(struct standard_view_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	(void) on_Frame_remove(_Context);
	if (_Context->p_Frame != (void *) 0)
		_Context->p_Frame = visual_drop(_Context->p_Frame);
	_Context=liberate(_Context);

	return(result);
}

public	int	standard_view_menu_show(struct standard_view_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Frame != (void *) 0)
	&& (_Context->s_Frame == 0)) {
		(void)visual_buffer_get(_Context->p_Frame,128,32);
		_Context->s_Frame=1;
		}
	if (((_Context->status = visual_styled_element(128,32,168,244,GetWidgetStyle(1)," ",0)) != 0)
) {
		visual_filzone(128,32,168,244,27,11);
		}
	_Context->trigger_Auto311=visual_trigger_code(_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]));
	if (((_Context->status = visual_styled_element(144,44,134,20,GetWidgetStyle(2),_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]))) != 0)
) {
	visual_button(144,44,134,20,vfh[2],16,0,_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]),32);
		}
	_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
	if (((_Context->status = visual_styled_element(144,64,134,20,GetWidgetStyle(2),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
	visual_button(144,64,134,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),32);
		}
	_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
	if (((_Context->status = visual_styled_element(144,84,134,20,GetWidgetStyle(2),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
	visual_button(144,84,134,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),32);
		}
	_Context->trigger_Auto314=visual_trigger_code(_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]));
	if (((_Context->status = visual_styled_element(144,104,134,20,GetWidgetStyle(2),_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]))) != 0)
) {
	visual_button(144,104,134,20,vfh[2],16,0,_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]),32);
		}
	_Context->trigger_Auto315=visual_trigger_code(_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]));
	if (((_Context->status = visual_styled_element(144,124,134,20,GetWidgetStyle(2),_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]))) != 0)
) {
	visual_button(144,124,134,20,vfh[2],16,0,_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]),32);
		}
	_Context->trigger_Auto316=visual_trigger_code(_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]));
	if (((_Context->status = visual_styled_element(144,144,134,20,GetWidgetStyle(2),_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]))) != 0)
) {
	visual_button(144,144,134,20,vfh[2],16,0,_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]),32);
		}
	_Context->trigger_Auto317=visual_trigger_code(_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]));
	if (((_Context->status = visual_styled_element(144,164,134,20,GetWidgetStyle(2),_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]))) != 0)
) {
	visual_button(144,164,134,20,vfh[2],16,0,_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]),32);
		}
	_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
	if (((_Context->status = visual_styled_element(144,224,134,20,GetWidgetStyle(2),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
	visual_button(144,224,134,20,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),32);
		}
	_Context->trigger_Auto319=visual_trigger_code(_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]));
	if (((_Context->status = visual_styled_element(144,244,134,20,GetWidgetStyle(2),_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]))) != 0)
) {
	visual_button(144,244,134,20,vfh[2],16,0,_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]),32);
		}
	_Context->trigger_Auto320=visual_trigger_code(_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]));
	if (((_Context->status = visual_styled_element(144,184,134,20,GetWidgetStyle(2),_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]))) != 0)
) {
	visual_button(144,184,134,20,vfh[2],16,0,_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]),32);
		}
	_Context->trigger_Auto321=visual_trigger_code(_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]));
	if (((_Context->status = visual_styled_element(144,204,134,20,GetWidgetStyle(2),_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]))) != 0)
) {
	visual_button(144,204,134,20,vfh[2],16,0,_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]),32);
		}
	visual_thaw(128,32,168,244);

	return(0);
}
private int on_Auto311_event(struct standard_view_menu_context * _Context) {
	return(_EXEC_PROG);
	return(-1);
}
private int on_Auto312_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_TEXT);
	return(-1);
}
private int on_Auto313_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_IMAGE);
	return(-1);
}
private int on_Auto314_event(struct standard_view_menu_context * _Context) {
	int result;
		standard_view_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=use_font_editor();
	on_Frame_create(_Context);
		standard_view_menu_show(_Context);
;
	return(result);
	return(-1);
}
private int on_Auto315_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_PROPERTIES);
	return(-1);
}
private int on_Auto316_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_FORM);
	return(-1);
}
private int on_Auto317_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_DATABASE);
	return(-1);
}
private int on_Auto318_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_STYLE);
	return(-1);
}
private int on_Auto319_event(struct standard_view_menu_context * _Context) {
	return(view_model_menu());
	return(-1);
}
private int on_Auto320_event(struct standard_view_menu_context * _Context) {
	int result;
		standard_view_menu_hide(_Context);
;
	result=toggle_treeview();
		standard_view_menu_show(_Context);
;
	return(result);
	return(-1);
}
private int on_Auto321_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_GRAPH);
	return(-1);
}


public	int	standard_view_menu_event(
struct standard_view_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto311 == mb ) return(1);
		if (_Context->trigger_Auto312 == mb ) return(2);
		if (_Context->trigger_Auto313 == mb ) return(3);
		if (_Context->trigger_Auto314 == mb ) return(4);
		if (_Context->trigger_Auto315 == mb ) return(5);
		if (_Context->trigger_Auto316 == mb ) return(6);
		if (_Context->trigger_Auto317 == mb ) return(7);
		if (_Context->trigger_Auto318 == mb ) return(8);
		if (_Context->trigger_Auto319 == mb ) return(9);
		if (_Context->trigger_Auto320 == mb ) return(10);
		if (_Context->trigger_Auto321 == mb ) return(11);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 144 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto311 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 64 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 84 )) {
		return(2); /* Auto312 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 84 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 104 )) {
		return(3); /* Auto313 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 104 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 124 )) {
		return(4); /* Auto314 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 144 )) {
		return(5); /* Auto315 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 144 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 164 )) {
		return(6); /* Auto316 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 164 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 184 )) {
		return(7); /* Auto317 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 224 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 244 )) {
		return(8); /* Auto318 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 244 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 264 )) {
		return(9); /* Auto319 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 184 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 204 )) {
		return(10); /* Auto320 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 204 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 224 )) {
		return(11); /* Auto321 */
		}

	return(-1);
}


public	int	standard_view_menu_focus(struct standard_view_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto311 */
				_Context->trigger_Auto311=visual_trigger_code(_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]));
				if (((_Context->status = visual_styled_element(144,44,134,20,GetWidgetStyle(3),_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]))) != 0)
) {
					visual_button(144,44,134,20,vfh[2],16,0,_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto311=visual_trigger_code(_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]));
				if (((_Context->status = visual_styled_element(144,44,134,20,GetWidgetStyle(2),_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]))) != 0)
) {
	visual_button(144,44,134,20,vfh[2],16,0,_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto312 */
				_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
				if (((_Context->status = visual_styled_element(144,64,134,20,GetWidgetStyle(3),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
					visual_button(144,64,134,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
				if (((_Context->status = visual_styled_element(144,64,134,20,GetWidgetStyle(2),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
	visual_button(144,64,134,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto313 */
				_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
				if (((_Context->status = visual_styled_element(144,84,134,20,GetWidgetStyle(3),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
					visual_button(144,84,134,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
				if (((_Context->status = visual_styled_element(144,84,134,20,GetWidgetStyle(2),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
	visual_button(144,84,134,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto314 */
				_Context->trigger_Auto314=visual_trigger_code(_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]));
				if (((_Context->status = visual_styled_element(144,104,134,20,GetWidgetStyle(3),_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]))) != 0)
) {
					visual_button(144,104,134,20,vfh[2],16,0,_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto314=visual_trigger_code(_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]));
				if (((_Context->status = visual_styled_element(144,104,134,20,GetWidgetStyle(2),_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]))) != 0)
) {
	visual_button(144,104,134,20,vfh[2],16,0,_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto315 */
				_Context->trigger_Auto315=visual_trigger_code(_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]));
				if (((_Context->status = visual_styled_element(144,124,134,20,GetWidgetStyle(3),_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]))) != 0)
) {
					visual_button(144,124,134,20,vfh[2],16,0,_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto315=visual_trigger_code(_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]));
				if (((_Context->status = visual_styled_element(144,124,134,20,GetWidgetStyle(2),_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]))) != 0)
) {
	visual_button(144,124,134,20,vfh[2],16,0,_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto316 */
				_Context->trigger_Auto316=visual_trigger_code(_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]));
				if (((_Context->status = visual_styled_element(144,144,134,20,GetWidgetStyle(3),_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]))) != 0)
) {
					visual_button(144,144,134,20,vfh[2],16,0,_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto316=visual_trigger_code(_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]));
				if (((_Context->status = visual_styled_element(144,144,134,20,GetWidgetStyle(2),_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]))) != 0)
) {
	visual_button(144,144,134,20,vfh[2],16,0,_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* Auto317 */
				_Context->trigger_Auto317=visual_trigger_code(_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]));
				if (((_Context->status = visual_styled_element(144,164,134,20,GetWidgetStyle(3),_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]))) != 0)
) {
					visual_button(144,164,134,20,vfh[2],16,0,_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto317=visual_trigger_code(_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]));
				if (((_Context->status = visual_styled_element(144,164,134,20,GetWidgetStyle(2),_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]))) != 0)
) {
	visual_button(144,164,134,20,vfh[2],16,0,_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto318 */
				_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
				if (((_Context->status = visual_styled_element(144,224,134,20,GetWidgetStyle(3),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
					visual_button(144,224,134,20,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
				if (((_Context->status = visual_styled_element(144,224,134,20,GetWidgetStyle(2),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
	visual_button(144,224,134,20,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),32);
				}
				break;
			case	0x9 :
				/* Auto319 */
				_Context->trigger_Auto319=visual_trigger_code(_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]));
				if (((_Context->status = visual_styled_element(144,244,134,20,GetWidgetStyle(3),_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]))) != 0)
) {
					visual_button(144,244,134,20,vfh[2],16,0,_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto319=visual_trigger_code(_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]));
				if (((_Context->status = visual_styled_element(144,244,134,20,GetWidgetStyle(2),_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]))) != 0)
) {
	visual_button(144,244,134,20,vfh[2],16,0,_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]),32);
				}
				break;
			case	0xa :
				/* Auto320 */
				_Context->trigger_Auto320=visual_trigger_code(_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]));
				if (((_Context->status = visual_styled_element(144,184,134,20,GetWidgetStyle(3),_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]))) != 0)
) {
					visual_button(144,184,134,20,vfh[2],16,0,_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto320=visual_trigger_code(_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]));
				if (((_Context->status = visual_styled_element(144,184,134,20,GetWidgetStyle(2),_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]))) != 0)
) {
	visual_button(144,184,134,20,vfh[2],16,0,_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]),32);
				}
				break;
			case	0xb :
				/* Auto321 */
				_Context->trigger_Auto321=visual_trigger_code(_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]));
				if (((_Context->status = visual_styled_element(144,204,134,20,GetWidgetStyle(3),_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]))) != 0)
) {
					visual_button(144,204,134,20,vfh[2],16,0,_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto321=visual_trigger_code(_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]));
				if (((_Context->status = visual_styled_element(144,204,134,20,GetWidgetStyle(2),_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]))) != 0)
) {
	visual_button(144,204,134,20,vfh[2],16,0,_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			standard_view_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=11;
			standard_view_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  128 )
				|| ( visual_event(6) <  32 )
				|| ( visual_event(7) >  296 )
				|| ( visual_event(6) >  276 )) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=standard_view_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto311 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto311=visual_trigger_code(_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]));
						if (((_Context->status = visual_styled_element(144,44,134,20,GetWidgetStyle(3),_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]))) != 0)
) {
							visual_button(144,44,134,20,vfh[2],16,0,_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto311=visual_trigger_code(_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]));
						if (((_Context->status = visual_styled_element(144,44,134,20,GetWidgetStyle(2),_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]))) != 0)
) {
	visual_button(144,44,134,20,vfh[2],16,0,_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto311_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto312 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
						if (((_Context->status = visual_styled_element(144,64,134,20,GetWidgetStyle(3),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
							visual_button(144,64,134,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
						if (((_Context->status = visual_styled_element(144,64,134,20,GetWidgetStyle(2),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
	visual_button(144,64,134,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto312_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto313 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
						if (((_Context->status = visual_styled_element(144,84,134,20,GetWidgetStyle(3),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
							visual_button(144,84,134,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
						if (((_Context->status = visual_styled_element(144,84,134,20,GetWidgetStyle(2),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
	visual_button(144,84,134,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto313_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto314 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto314=visual_trigger_code(_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]));
						if (((_Context->status = visual_styled_element(144,104,134,20,GetWidgetStyle(3),_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]))) != 0)
) {
							visual_button(144,104,134,20,vfh[2],16,0,_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto314=visual_trigger_code(_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]));
						if (((_Context->status = visual_styled_element(144,104,134,20,GetWidgetStyle(2),_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]))) != 0)
) {
	visual_button(144,104,134,20,vfh[2],16,0,_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto314_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto315 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto315=visual_trigger_code(_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]));
						if (((_Context->status = visual_styled_element(144,124,134,20,GetWidgetStyle(3),_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]))) != 0)
) {
							visual_button(144,124,134,20,vfh[2],16,0,_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto315=visual_trigger_code(_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]));
						if (((_Context->status = visual_styled_element(144,124,134,20,GetWidgetStyle(2),_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]))) != 0)
) {
	visual_button(144,124,134,20,vfh[2],16,0,_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto315_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto316 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto316=visual_trigger_code(_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]));
						if (((_Context->status = visual_styled_element(144,144,134,20,GetWidgetStyle(3),_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]))) != 0)
) {
							visual_button(144,144,134,20,vfh[2],16,0,_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto316=visual_trigger_code(_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]));
						if (((_Context->status = visual_styled_element(144,144,134,20,GetWidgetStyle(2),_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]))) != 0)
) {
	visual_button(144,144,134,20,vfh[2],16,0,_Context->msg_Auto316[_Context->language],strlen(_Context->msg_Auto316[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto316_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto317 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto317=visual_trigger_code(_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]));
						if (((_Context->status = visual_styled_element(144,164,134,20,GetWidgetStyle(3),_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]))) != 0)
) {
							visual_button(144,164,134,20,vfh[2],16,0,_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto317=visual_trigger_code(_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]));
						if (((_Context->status = visual_styled_element(144,164,134,20,GetWidgetStyle(2),_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]))) != 0)
) {
	visual_button(144,164,134,20,vfh[2],16,0,_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto317_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto318 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
						if (((_Context->status = visual_styled_element(144,224,134,20,GetWidgetStyle(3),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
							visual_button(144,224,134,20,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
						if (((_Context->status = visual_styled_element(144,224,134,20,GetWidgetStyle(2),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
	visual_button(144,224,134,20,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto318_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto319 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto319=visual_trigger_code(_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]));
						if (((_Context->status = visual_styled_element(144,244,134,20,GetWidgetStyle(3),_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]))) != 0)
) {
							visual_button(144,244,134,20,vfh[2],16,0,_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto319=visual_trigger_code(_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]));
						if (((_Context->status = visual_styled_element(144,244,134,20,GetWidgetStyle(2),_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]))) != 0)
) {
	visual_button(144,244,134,20,vfh[2],16,0,_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto319_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto320 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto320=visual_trigger_code(_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]));
						if (((_Context->status = visual_styled_element(144,184,134,20,GetWidgetStyle(3),_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]))) != 0)
) {
							visual_button(144,184,134,20,vfh[2],16,0,_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto320=visual_trigger_code(_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]));
						if (((_Context->status = visual_styled_element(144,184,134,20,GetWidgetStyle(2),_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]))) != 0)
) {
	visual_button(144,184,134,20,vfh[2],16,0,_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto320_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Auto321 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto321=visual_trigger_code(_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]));
						if (((_Context->status = visual_styled_element(144,204,134,20,GetWidgetStyle(3),_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]))) != 0)
) {
							visual_button(144,204,134,20,vfh[2],16,0,_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto321=visual_trigger_code(_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]));
						if (((_Context->status = visual_styled_element(144,204,134,20,GetWidgetStyle(2),_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]))) != 0)
) {
	visual_button(144,204,134,20,vfh[2],16,0,_Context->msg_Auto321[_Context->language],strlen(_Context->msg_Auto321[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto321_event(_Context)) != -1) break;

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
				_Context->focus_item=11;
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

public	int	standard_view_menu()
{
	int	status=0;
	struct standard_view_menu_context * _Context=(struct standard_view_menu_context*) 0;
	status = standard_view_menu_create(&_Context);
	if ( status != 0) return(status);
	status = standard_view_menu_show(_Context);
		enter_modal();
	status = standard_view_menu_focus(_Context);
		leave_modal();
	status = standard_view_menu_hide(_Context);
	status = standard_view_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _viewmenu_c */
