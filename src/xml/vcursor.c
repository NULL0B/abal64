
#ifndef _vcursor_c
#define _vcursor_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vcursor.xml                                              */
/* Target         : vcursor.c                                                */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_EdSkin   ""
#define fr_EdSkin   "skin.gif"
#define it_EdSkin   "skin.gif"
#define es_EdSkin   "skin.gif"
#define de_EdSkin   "skin.gif"
#define nl_EdSkin   "skin.gif"
#define pt_EdSkin   "skin.gif"
#define xx_EdSkin   "skin.gif"
#define en__EdSkin   ""
#define en_AddView   "+"
#define fr_AddView   "@"
#define it_AddView   "@"
#define es_AddView   "@"
#define de_AddView   "@"
#define nl_AddView   "@"
#define pt_AddView   "@"
#define xx_AddView   "@"
#define en__AddView   ""
#define fr__AddView   ""
#define it__AddView   ""
#define es__AddView   ""
#define de__AddView   ""
#define nl__AddView   ""
#define pt__AddView   ""
#define xx__AddView   ""
#define en_AddMsg   "Camera view added"
#define fr_AddMsg   "Ajout d'une vue"
#define it_AddMsg   "Camera view added"
#define es_AddMsg   "Camera view added"
#define de_AddMsg   "Camera view added"
#define nl_AddMsg   "Camera view added"
#define pt_AddMsg   "Camera view added"
#define xx_AddMsg   "Camera view added"
#define en__AddMsg   ""
#define fr__AddMsg   ""
#define it__AddMsg   ""
#define es__AddMsg   ""
#define de__AddMsg   ""
#define nl__AddMsg   ""
#define pt__AddMsg   ""
#define xx__AddMsg   ""
#define en_DelMsg   "Camera view deleted"
#define fr_DelMsg   "Supression d'une vue"
#define it_DelMsg   "Camera view deleted"
#define es_DelMsg   "Camera view deleted"
#define de_DelMsg   "Camera view deleted"
#define nl_DelMsg   "Camera view deleted"
#define pt_DelMsg   "Camera view deleted"
#define xx_DelMsg   "Camera view deleted"
#define en__DelMsg   ""
#define fr__DelMsg   ""
#define it__DelMsg   ""
#define es__DelMsg   ""
#define de__DelMsg   ""
#define nl__DelMsg   ""
#define pt__DelMsg   ""
#define xx__DelMsg   ""
#define en_SzlView   "-"
#define fr_SzlView   "@"
#define it_SzlView   "@"
#define es_SzlView   "@"
#define de_SzlView   "@"
#define nl_SzlView   "@"
#define pt_SzlView   "@"
#define xx_SzlView   "@"
#define en__SzlView   ""
#define fr__SzlView   ""
#define it__SzlView   ""
#define es__SzlView   ""
#define de__SzlView   ""
#define nl__SzlView   ""
#define pt__SzlView   ""
#define xx__SzlView   ""
#define en_Auto3545   "3dView"
#define fr_Auto3545   "3dView"
#define it_Auto3545   "3dView"
#define es_Auto3545   "3dView"
#define de_Auto3545   "3dView"
#define nl_Auto3545   "3dView"
#define pt_Auto3545   "3dView"
#define xx_Auto3545   "3dView"
#define en_Auto3546   "View"
#define fr_Auto3546   "Vue"
#define it_Auto3546   "View"
#define es_Auto3546   "View"
#define de_Auto3546   "View"
#define nl_Auto3546   "View"
#define pt_Auto3546   "View"
#define xx_Auto3546   "View"
#define en__Auto3546   ""
#define fr__Auto3546   ""
#define it__Auto3546   ""
#define es__Auto3546   ""
#define de__Auto3546   ""
#define nl__Auto3546   ""
#define pt__Auto3546   ""
#define xx__Auto3546   ""
#define en_Auto3547   "Focus"
#define fr_Auto3547   "Focus"
#define it_Auto3547   "Focus"
#define es_Auto3547   "Focus"
#define de_Auto3547   "Focus"
#define nl_Auto3547   "Focus"
#define pt_Auto3547   "Focus"
#define xx_Auto3547   "Focus"
#define en__Auto3547   ""
#define fr__Auto3547   ""
#define it__Auto3547   ""
#define es__Auto3547   ""
#define de__Auto3547   ""
#define nl__Auto3547   ""
#define pt__Auto3547   ""
#define xx__Auto3547   ""
#define en_Auto3548   "Step"
#define fr_Auto3548   "Pas"
#define it_Auto3548   "Step"
#define es_Auto3548   "Step"
#define de_Auto3548   "Step"
#define nl_Auto3548   "Step"
#define pt_Auto3548   "Step"
#define xx_Auto3548   "Step"
#define en__Auto3548   ""
#define en_Xadjust   "X+/-"
#define fr_Xadjust   "X+/-"
#define it_Xadjust   "X+/-"
#define es_Xadjust   "X+/-"
#define de_Xadjust   "X+/-"
#define nl_Xadjust   "X+/-"
#define pt_Xadjust   "X+/-"
#define xx_Xadjust   "X+/-"
#define en_ByX   ""
#define en_Yadjust   "Y+/-"
#define fr_Yadjust   "Y+/-"
#define it_Yadjust   "Y+/-"
#define es_Yadjust   "Y+/-"
#define de_Yadjust   "Y+/-"
#define nl_Yadjust   "Y+/-"
#define pt_Yadjust   "Y+/-"
#define xx_Yadjust   "Y+/-"
#define en_ByY   ""
#define en_Zadjust   "Z+/-"
#define fr_Zadjust   "Z+/-"
#define it_Zadjust   "Z+/-"
#define es_Zadjust   "Z+/-"
#define de_Zadjust   "Z+/-"
#define nl_Zadjust   "Z+/-"
#define pt_Zadjust   "Z+/-"
#define xx_Zadjust   "Z+/-"
#define en__Zadjust   ""
#define en_ByZ   ""
#define en_MoveLeft   "lefticon.gif"
#define fr_MoveLeft   "lefticon.gif"
#define it_MoveLeft   "lefticon.gif"
#define es_MoveLeft   "lefticon.gif"
#define de_MoveLeft   "lefticon.gif"
#define nl_MoveLeft   "lefticon.gif"
#define pt_MoveLeft   "lefticon.gif"
#define xx_MoveLeft   "lefticon.gif"
#define en_MoveRight   "riteicon.gif"
#define fr_MoveRight   "riteicon.gif"
#define it_MoveRight   "riteicon.gif"
#define es_MoveRight   "riteicon.gif"
#define de_MoveRight   "riteicon.gif"
#define nl_MoveRight   "riteicon.gif"
#define pt_MoveRight   "riteicon.gif"
#define xx_MoveRight   "riteicon.gif"
#define en_FocusRight   "riteicon.gif"
#define fr_FocusRight   "riteicon.gif"
#define it_FocusRight   "riteicon.gif"
#define es_FocusRight   "riteicon.gif"
#define de_FocusRight   "riteicon.gif"
#define nl_FocusRight   "riteicon.gif"
#define pt_FocusRight   "riteicon.gif"
#define xx_FocusRight   "riteicon.gif"
#define en__FocusRight   ""
#define fr__FocusRight   ""
#define it__FocusRight   ""
#define es__FocusRight   ""
#define de__FocusRight   ""
#define nl__FocusRight   ""
#define pt__FocusRight   ""
#define xx__FocusRight   ""
#define en_FocusLeft   "lefticon.gif"
#define fr_FocusLeft   "lefticon.gif"
#define it_FocusLeft   "lefticon.gif"
#define es_FocusLeft   "lefticon.gif"
#define de_FocusLeft   "lefticon.gif"
#define nl_FocusLeft   "lefticon.gif"
#define pt_FocusLeft   "lefticon.gif"
#define xx_FocusLeft   "lefticon.gif"
#define en__FocusLeft   ""
#define fr__FocusLeft   ""
#define it__FocusLeft   ""
#define es__FocusLeft   ""
#define de__FocusLeft   ""
#define nl__FocusLeft   ""
#define pt__FocusLeft   ""
#define xx__FocusLeft   ""
#define en_FocusUp   "upicon.gif"
#define fr_FocusUp   "upicon.gif"
#define it_FocusUp   "upicon.gif"
#define es_FocusUp   "upicon.gif"
#define de_FocusUp   "upicon.gif"
#define nl_FocusUp   "upicon.gif"
#define pt_FocusUp   "upicon.gif"
#define xx_FocusUp   "upicon.gif"
#define en__FocusUp   ""
#define fr__FocusUp   ""
#define it__FocusUp   ""
#define es__FocusUp   ""
#define de__FocusUp   ""
#define nl__FocusUp   ""
#define pt__FocusUp   ""
#define xx__FocusUp   ""
#define en_FocusDown   "downicon.gif"
#define fr_FocusDown   "downicon.gif"
#define it_FocusDown   "downicon.gif"
#define es_FocusDown   "downicon.gif"
#define de_FocusDown   "downicon.gif"
#define nl_FocusDown   "downicon.gif"
#define pt_FocusDown   "downicon.gif"
#define xx_FocusDown   "downicon.gif"
#define en__FocusDown   ""
#define fr__FocusDown   ""
#define it__FocusDown   ""
#define es__FocusDown   ""
#define de__FocusDown   ""
#define nl__FocusDown   ""
#define pt__FocusDown   ""
#define xx__FocusDown   ""
#define en_MoveUp   "upicon.gif"
#define fr_MoveUp   "upicon.gif"
#define it_MoveUp   "upicon.gif"
#define es_MoveUp   "upicon.gif"
#define de_MoveUp   "upicon.gif"
#define nl_MoveUp   "upicon.gif"
#define pt_MoveUp   "upicon.gif"
#define xx_MoveUp   "upicon.gif"
#define en_MoveInOut   "plusicon.gif"
#define fr_MoveInOut   "plusicon.gif"
#define it_MoveInOut   "plusicon.gif"
#define es_MoveInOut   "plusicon.gif"
#define de_MoveInOut   "plusicon.gif"
#define nl_MoveInOut   "plusicon.gif"
#define pt_MoveInOut   "plusicon.gif"
#define xx_MoveInOut   "plusicon.gif"
#define en_MoveDown   "downicon.gif"
#define fr_MoveDown   "downicon.gif"
#define it_MoveDown   "downicon.gif"
#define es_MoveDown   "downicon.gif"
#define de_MoveDown   "downicon.gif"
#define nl_MoveDown   "downicon.gif"
#define pt_MoveDown   "downicon.gif"
#define xx_MoveDown   "downicon.gif"
#define en_GridIcon   "gridicon.gif"
#define fr_GridIcon   "gridicon.gif"
#define it_GridIcon   "gridicon.gif"
#define es_GridIcon   "gridicon.gif"
#define de_GridIcon   "gridicon.gif"
#define nl_GridIcon   "gridicon.gif"
#define pt_GridIcon   "gridicon.gif"
#define xx_GridIcon   "gridicon.gif"
#define en__GridIcon   ""
#define en_FocusZero   "plusicon.gif"
#define fr_FocusZero   "plusicon.gif"
#define it_FocusZero   "plusicon.gif"
#define es_FocusZero   "plusicon.gif"
#define de_FocusZero   "plusicon.gif"
#define nl_FocusZero   "plusicon.gif"
#define pt_FocusZero   "plusicon.gif"
#define xx_FocusZero   "plusicon.gif"
#define en__FocusZero   ""
#define en_Auto3549   "Position"
#define fr_Auto3549   "Position"
#define it_Auto3549   "Position"
#define es_Auto3549   "Position"
#define de_Auto3549   "Position"
#define nl_Auto3549   "Position"
#define pt_Auto3549   "Position"
#define xx_Auto3549   "Position"
#define en__Auto3549   ""
#define en_AtX   ""
#define en_AtY   ""
#define en_AtZ   ""

private struct visual_3d_cursor_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_EdSkin[8];
	char * hint_EdSkin[8];
	char * msg_AddView[8];
	int	trigger_AddView;
	char * hint_AddView[8];
	char * msg_AddMsg[8];
	char * hint_AddMsg[8];
	char * msg_DelMsg[8];
	char * hint_DelMsg[8];
	char * msg_SzlView[8];
	int	trigger_SzlView;
	char * hint_SzlView[8];
	char * msg_Auto3545[8];
	char * hint_Auto3545[8];
	char * msg_Auto3546[8];
	char * hint_Auto3546[8];
	char * msg_Auto3547[8];
	char * hint_Auto3547[8];
	char * msg_Auto3548[8];
	char * hint_Auto3548[8];
	char * msg_Xadjust[8];
	int	trigger_Xadjust;
	char * hint_Xadjust[8];
	char * hint_ByX[8];
	char	buffer_ByX[7];
	char * msg_Yadjust[8];
	int	trigger_Yadjust;
	char * hint_Yadjust[8];
	char * hint_ByY[8];
	char	buffer_ByY[7];
	char * msg_Zadjust[8];
	int	trigger_Zadjust;
	char * hint_Zadjust[8];
	char * hint_ByZ[8];
	char	buffer_ByZ[7];
	char * msg_MoveLeft[8];
	char * hint_MoveLeft[8];
	char * msg_MoveRight[8];
	char * hint_MoveRight[8];
	char * msg_FocusRight[8];
	char * hint_FocusRight[8];
	char * msg_FocusLeft[8];
	char * hint_FocusLeft[8];
	char * msg_FocusUp[8];
	char * hint_FocusUp[8];
	char * msg_FocusDown[8];
	char * hint_FocusDown[8];
	char * msg_MoveUp[8];
	char * hint_MoveUp[8];
	char * msg_MoveInOut[8];
	char * hint_MoveInOut[8];
	char * msg_MoveDown[8];
	char * hint_MoveDown[8];
	char * msg_GridIcon[8];
	char * hint_GridIcon[8];
	int	x_GridIcon;
	int	y_GridIcon;
	int	w_GridIcon;
	int	h_GridIcon;
	int	fg_GridIcon;
	int	bg_GridIcon;
	int	fid_GridIcon;
	int	s_GridIcon;
	void *	p_GridIcon;
	char * msg_FocusZero[8];
	char * hint_FocusZero[8];
	char * msg_Auto3549[8];
	char * hint_Auto3549[8];
	char * hint_AtX[8];
	char	buffer_AtX[7];
	char * hint_AtY[8];
	char	buffer_AtY[7];
	char * hint_AtZ[8];
	char	buffer_AtZ[7];
	char	signature[1];
	};
static int	vfh[16];
private int on_ByX_create(struct visual_3d_cursor_context * _Context);
private int on_ByY_create(struct visual_3d_cursor_context * _Context);
private int on_ByZ_create(struct visual_3d_cursor_context * _Context);
private int on_AtX_show(struct visual_3d_cursor_context * _Context);
private int on_AtY_show(struct visual_3d_cursor_context * _Context);
private int on_AtZ_show(struct visual_3d_cursor_context * _Context);
private int on_MoveLeft_getfocus(struct visual_3d_cursor_context * _Context);
private int on_MoveRight_getfocus(struct visual_3d_cursor_context * _Context);
private int on_FocusRight_getfocus(struct visual_3d_cursor_context * _Context);
private int on_FocusLeft_getfocus(struct visual_3d_cursor_context * _Context);
private int on_FocusUp_getfocus(struct visual_3d_cursor_context * _Context);
private int on_FocusDown_getfocus(struct visual_3d_cursor_context * _Context);
private int on_MoveUp_getfocus(struct visual_3d_cursor_context * _Context);
private int on_MoveInOut_getfocus(struct visual_3d_cursor_context * _Context);
private int on_MoveDown_getfocus(struct visual_3d_cursor_context * _Context);
private int on_GridIcon_getfocus(struct visual_3d_cursor_context * _Context);
private int on_FocusZero_getfocus(struct visual_3d_cursor_context * _Context);
private int on_AddView_event(struct visual_3d_cursor_context * _Context);
private int on_SzlView_event(struct visual_3d_cursor_context * _Context);
private int on_Xadjust_event(struct visual_3d_cursor_context * _Context);
private int on_Yadjust_event(struct visual_3d_cursor_context * _Context);
private int on_Zadjust_event(struct visual_3d_cursor_context * _Context);
private int on_MoveLeft_event(struct visual_3d_cursor_context * _Context);
private int on_MoveRight_event(struct visual_3d_cursor_context * _Context);
private int on_FocusRight_event(struct visual_3d_cursor_context * _Context);
private int on_FocusLeft_event(struct visual_3d_cursor_context * _Context);
private int on_FocusUp_event(struct visual_3d_cursor_context * _Context);
private int on_FocusDown_event(struct visual_3d_cursor_context * _Context);
private int on_MoveUp_event(struct visual_3d_cursor_context * _Context);
private int on_MoveInOut_event(struct visual_3d_cursor_context * _Context);
private int on_MoveDown_event(struct visual_3d_cursor_context * _Context);
private int on_GridIcon_event(struct visual_3d_cursor_context * _Context);
private int on_FocusZero_event(struct visual_3d_cursor_context * _Context);
static void	_3d_motion(struct visual_3d_cursor_context * _Context,int direction);

/*	----------------------	*/
/*	_ 3 d _ m o t i o n ()	*/
/*	----------------------	*/
static void	_3d_motion(struct visual_3d_cursor_context * _Context,int direction){
	int x,y,z;
		if ((_Context->p_GridIcon != (void *) 0)
	&& (_Context->s_GridIcon == 0)) {
		(void)visual_buffer_get(_Context->p_GridIcon,_Context->x_GridIcon,_Context->y_GridIcon);
		_Context->s_GridIcon=1;
		}
	if ((_Context->p_GridIcon != (void *) 0)
	&& (_Context->s_GridIcon == 0)) {
		(void)visual_buffer_get(_Context->p_GridIcon,_Context->x_GridIcon,_Context->y_GridIcon);
		_Context->s_GridIcon=1;
		}
	visual_image(_Context->x_GridIcon,_Context->y_GridIcon,_Context->w_GridIcon,_Context->h_GridIcon,_Context->msg_GridIcon[_Context->language],0);
;
	while(1){
		if ((_Context->p_GridIcon != (void *) 0)
	&& (_Context->s_GridIcon != 0)) {
		(void)visual_buffer_put(_Context->p_GridIcon,_Context->x_GridIcon,_Context->y_GridIcon);
		_Context->s_GridIcon=0;
		}
;
	move_3d_camera(direction,&x,&y,&z);
	sprintf(_Context->buffer_AtX,"%u",x);
	sprintf(_Context->buffer_AtY,"%u",y);
	sprintf(_Context->buffer_AtZ,"%u",z);
		visual_3d_cursor_show(_Context);
;
		if ((_Context->p_GridIcon != (void *) 0)
	&& (_Context->s_GridIcon == 0)) {
		(void)visual_buffer_get(_Context->p_GridIcon,_Context->x_GridIcon,_Context->y_GridIcon);
		_Context->s_GridIcon=1;
		}
	if ((_Context->p_GridIcon != (void *) 0)
	&& (_Context->s_GridIcon == 0)) {
		(void)visual_buffer_get(_Context->p_GridIcon,_Context->x_GridIcon,_Context->y_GridIcon);
		_Context->s_GridIcon=1;
		}
	visual_image(_Context->x_GridIcon,_Context->y_GridIcon,_Context->w_GridIcon,_Context->h_GridIcon,_Context->msg_GridIcon[_Context->language],0);
;
	if(!(visual_kbhit())){
	usleep(10);
	continue;
	}
	if((visual_getch()==256)
	&&(visual_event(1)==0x0020))
	break;
	}
		if ((_Context->p_GridIcon != (void *) 0)
	&& (_Context->s_GridIcon != 0)) {
		(void)visual_buffer_put(_Context->p_GridIcon,_Context->x_GridIcon,_Context->y_GridIcon);
		_Context->s_GridIcon=0;
		}
;

}
private int on_ByX_create(struct visual_3d_cursor_context * _Context) {
	int x;
	adjust_3d_step(1,0,&x);
	sprintf(_Context->buffer_ByX,"%u",x);
	return(-1);
}
private int on_ByY_create(struct visual_3d_cursor_context * _Context) {
	int x;
	adjust_3d_step(2,0,&x);
	sprintf(_Context->buffer_ByY,"%u",x);
	return(-1);
}
private int on_ByZ_create(struct visual_3d_cursor_context * _Context) {
	int x;
	adjust_3d_step(3,0,&x);
	sprintf(_Context->buffer_ByZ,"%u",x);
	return(-1);
}

public	int	visual_3d_cursor_create(struct visual_3d_cursor_context **cptr)
{

	int i;
	struct visual_3d_cursor_context * _Context=(struct visual_3d_cursor_context*)0;
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
	if (!(_Context = allocate( sizeof( struct visual_3d_cursor_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=16;
		for (i=0; i < 6; i++)  *(_Context->buffer_ByX+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_ByY+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_ByZ+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_AtX+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_AtZ+i)=' ';
	for (i=0; i < 8; i++)_Context->msg_EdSkin[i]=" ";
	_Context->msg_EdSkin[0]=en_EdSkin;
	_Context->msg_EdSkin[1]=fr_EdSkin;
	_Context->msg_EdSkin[2]=it_EdSkin;
	_Context->msg_EdSkin[3]=es_EdSkin;
	_Context->msg_EdSkin[4]=de_EdSkin;
	_Context->msg_EdSkin[5]=nl_EdSkin;
	_Context->msg_EdSkin[6]=pt_EdSkin;
	_Context->msg_EdSkin[7]=xx_EdSkin;
	_Context->hint_EdSkin[0]=en__EdSkin;
	for (i=0; i < 8; i++)_Context->msg_AddView[i]=" ";
	_Context->msg_AddView[0]=en_AddView;
	_Context->msg_AddView[1]=fr_AddView;
	_Context->msg_AddView[2]=it_AddView;
	_Context->msg_AddView[3]=es_AddView;
	_Context->msg_AddView[4]=de_AddView;
	_Context->msg_AddView[5]=nl_AddView;
	_Context->msg_AddView[6]=pt_AddView;
	_Context->msg_AddView[7]=xx_AddView;
	_Context->hint_AddView[0]=en__AddView;
	_Context->hint_AddView[1]=fr__AddView;
	_Context->hint_AddView[2]=it__AddView;
	_Context->hint_AddView[3]=es__AddView;
	_Context->hint_AddView[4]=de__AddView;
	_Context->hint_AddView[5]=nl__AddView;
	_Context->hint_AddView[6]=pt__AddView;
	_Context->hint_AddView[7]=xx__AddView;
	for (i=0; i < 8; i++)_Context->msg_AddMsg[i]=" ";
	_Context->msg_AddMsg[0]=en_AddMsg;
	_Context->msg_AddMsg[1]=fr_AddMsg;
	_Context->msg_AddMsg[2]=it_AddMsg;
	_Context->msg_AddMsg[3]=es_AddMsg;
	_Context->msg_AddMsg[4]=de_AddMsg;
	_Context->msg_AddMsg[5]=nl_AddMsg;
	_Context->msg_AddMsg[6]=pt_AddMsg;
	_Context->msg_AddMsg[7]=xx_AddMsg;
	_Context->hint_AddMsg[0]=en__AddMsg;
	_Context->hint_AddMsg[1]=fr__AddMsg;
	_Context->hint_AddMsg[2]=it__AddMsg;
	_Context->hint_AddMsg[3]=es__AddMsg;
	_Context->hint_AddMsg[4]=de__AddMsg;
	_Context->hint_AddMsg[5]=nl__AddMsg;
	_Context->hint_AddMsg[6]=pt__AddMsg;
	_Context->hint_AddMsg[7]=xx__AddMsg;
	for (i=0; i < 8; i++)_Context->msg_DelMsg[i]=" ";
	_Context->msg_DelMsg[0]=en_DelMsg;
	_Context->msg_DelMsg[1]=fr_DelMsg;
	_Context->msg_DelMsg[2]=it_DelMsg;
	_Context->msg_DelMsg[3]=es_DelMsg;
	_Context->msg_DelMsg[4]=de_DelMsg;
	_Context->msg_DelMsg[5]=nl_DelMsg;
	_Context->msg_DelMsg[6]=pt_DelMsg;
	_Context->msg_DelMsg[7]=xx_DelMsg;
	_Context->hint_DelMsg[0]=en__DelMsg;
	_Context->hint_DelMsg[1]=fr__DelMsg;
	_Context->hint_DelMsg[2]=it__DelMsg;
	_Context->hint_DelMsg[3]=es__DelMsg;
	_Context->hint_DelMsg[4]=de__DelMsg;
	_Context->hint_DelMsg[5]=nl__DelMsg;
	_Context->hint_DelMsg[6]=pt__DelMsg;
	_Context->hint_DelMsg[7]=xx__DelMsg;
	for (i=0; i < 8; i++)_Context->msg_SzlView[i]=" ";
	_Context->msg_SzlView[0]=en_SzlView;
	_Context->msg_SzlView[1]=fr_SzlView;
	_Context->msg_SzlView[2]=it_SzlView;
	_Context->msg_SzlView[3]=es_SzlView;
	_Context->msg_SzlView[4]=de_SzlView;
	_Context->msg_SzlView[5]=nl_SzlView;
	_Context->msg_SzlView[6]=pt_SzlView;
	_Context->msg_SzlView[7]=xx_SzlView;
	_Context->hint_SzlView[0]=en__SzlView;
	_Context->hint_SzlView[1]=fr__SzlView;
	_Context->hint_SzlView[2]=it__SzlView;
	_Context->hint_SzlView[3]=es__SzlView;
	_Context->hint_SzlView[4]=de__SzlView;
	_Context->hint_SzlView[5]=nl__SzlView;
	_Context->hint_SzlView[6]=pt__SzlView;
	_Context->hint_SzlView[7]=xx__SzlView;
	for (i=0; i < 8; i++)_Context->msg_Auto3545[i]=" ";
	_Context->msg_Auto3545[0]=en_Auto3545;
	_Context->msg_Auto3545[1]=fr_Auto3545;
	_Context->msg_Auto3545[2]=it_Auto3545;
	_Context->msg_Auto3545[3]=es_Auto3545;
	_Context->msg_Auto3545[4]=de_Auto3545;
	_Context->msg_Auto3545[5]=nl_Auto3545;
	_Context->msg_Auto3545[6]=pt_Auto3545;
	_Context->msg_Auto3545[7]=xx_Auto3545;
	for (i=0; i < 8; i++)_Context->msg_Auto3546[i]=" ";
	_Context->msg_Auto3546[0]=en_Auto3546;
	_Context->msg_Auto3546[1]=fr_Auto3546;
	_Context->msg_Auto3546[2]=it_Auto3546;
	_Context->msg_Auto3546[3]=es_Auto3546;
	_Context->msg_Auto3546[4]=de_Auto3546;
	_Context->msg_Auto3546[5]=nl_Auto3546;
	_Context->msg_Auto3546[6]=pt_Auto3546;
	_Context->msg_Auto3546[7]=xx_Auto3546;
	_Context->hint_Auto3546[0]=en__Auto3546;
	_Context->hint_Auto3546[1]=fr__Auto3546;
	_Context->hint_Auto3546[2]=it__Auto3546;
	_Context->hint_Auto3546[3]=es__Auto3546;
	_Context->hint_Auto3546[4]=de__Auto3546;
	_Context->hint_Auto3546[5]=nl__Auto3546;
	_Context->hint_Auto3546[6]=pt__Auto3546;
	_Context->hint_Auto3546[7]=xx__Auto3546;
	for (i=0; i < 8; i++)_Context->msg_Auto3547[i]=" ";
	_Context->msg_Auto3547[0]=en_Auto3547;
	_Context->msg_Auto3547[1]=fr_Auto3547;
	_Context->msg_Auto3547[2]=it_Auto3547;
	_Context->msg_Auto3547[3]=es_Auto3547;
	_Context->msg_Auto3547[4]=de_Auto3547;
	_Context->msg_Auto3547[5]=nl_Auto3547;
	_Context->msg_Auto3547[6]=pt_Auto3547;
	_Context->msg_Auto3547[7]=xx_Auto3547;
	_Context->hint_Auto3547[0]=en__Auto3547;
	_Context->hint_Auto3547[1]=fr__Auto3547;
	_Context->hint_Auto3547[2]=it__Auto3547;
	_Context->hint_Auto3547[3]=es__Auto3547;
	_Context->hint_Auto3547[4]=de__Auto3547;
	_Context->hint_Auto3547[5]=nl__Auto3547;
	_Context->hint_Auto3547[6]=pt__Auto3547;
	_Context->hint_Auto3547[7]=xx__Auto3547;
	for (i=0; i < 8; i++)_Context->msg_Auto3548[i]=" ";
	_Context->msg_Auto3548[0]=en_Auto3548;
	_Context->msg_Auto3548[1]=fr_Auto3548;
	_Context->msg_Auto3548[2]=it_Auto3548;
	_Context->msg_Auto3548[3]=es_Auto3548;
	_Context->msg_Auto3548[4]=de_Auto3548;
	_Context->msg_Auto3548[5]=nl_Auto3548;
	_Context->msg_Auto3548[6]=pt_Auto3548;
	_Context->msg_Auto3548[7]=xx_Auto3548;
	_Context->hint_Auto3548[0]=en__Auto3548;
	for (i=0; i < 8; i++)_Context->msg_Xadjust[i]=" ";
	_Context->msg_Xadjust[0]=en_Xadjust;
	_Context->msg_Xadjust[1]=fr_Xadjust;
	_Context->msg_Xadjust[2]=it_Xadjust;
	_Context->msg_Xadjust[3]=es_Xadjust;
	_Context->msg_Xadjust[4]=de_Xadjust;
	_Context->msg_Xadjust[5]=nl_Xadjust;
	_Context->msg_Xadjust[6]=pt_Xadjust;
	_Context->msg_Xadjust[7]=xx_Xadjust;
	(void) on_ByX_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Yadjust[i]=" ";
	_Context->msg_Yadjust[0]=en_Yadjust;
	_Context->msg_Yadjust[1]=fr_Yadjust;
	_Context->msg_Yadjust[2]=it_Yadjust;
	_Context->msg_Yadjust[3]=es_Yadjust;
	_Context->msg_Yadjust[4]=de_Yadjust;
	_Context->msg_Yadjust[5]=nl_Yadjust;
	_Context->msg_Yadjust[6]=pt_Yadjust;
	_Context->msg_Yadjust[7]=xx_Yadjust;
	(void) on_ByY_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Zadjust[i]=" ";
	_Context->msg_Zadjust[0]=en_Zadjust;
	_Context->msg_Zadjust[1]=fr_Zadjust;
	_Context->msg_Zadjust[2]=it_Zadjust;
	_Context->msg_Zadjust[3]=es_Zadjust;
	_Context->msg_Zadjust[4]=de_Zadjust;
	_Context->msg_Zadjust[5]=nl_Zadjust;
	_Context->msg_Zadjust[6]=pt_Zadjust;
	_Context->msg_Zadjust[7]=xx_Zadjust;
	_Context->hint_Zadjust[0]=en__Zadjust;
	(void) on_ByZ_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_MoveLeft[i]=" ";
	_Context->msg_MoveLeft[0]=en_MoveLeft;
	_Context->msg_MoveLeft[1]=fr_MoveLeft;
	_Context->msg_MoveLeft[2]=it_MoveLeft;
	_Context->msg_MoveLeft[3]=es_MoveLeft;
	_Context->msg_MoveLeft[4]=de_MoveLeft;
	_Context->msg_MoveLeft[5]=nl_MoveLeft;
	_Context->msg_MoveLeft[6]=pt_MoveLeft;
	_Context->msg_MoveLeft[7]=xx_MoveLeft;
	for (i=0; i < 8; i++)_Context->msg_MoveRight[i]=" ";
	_Context->msg_MoveRight[0]=en_MoveRight;
	_Context->msg_MoveRight[1]=fr_MoveRight;
	_Context->msg_MoveRight[2]=it_MoveRight;
	_Context->msg_MoveRight[3]=es_MoveRight;
	_Context->msg_MoveRight[4]=de_MoveRight;
	_Context->msg_MoveRight[5]=nl_MoveRight;
	_Context->msg_MoveRight[6]=pt_MoveRight;
	_Context->msg_MoveRight[7]=xx_MoveRight;
	for (i=0; i < 8; i++)_Context->msg_FocusRight[i]=" ";
	_Context->msg_FocusRight[0]=en_FocusRight;
	_Context->msg_FocusRight[1]=fr_FocusRight;
	_Context->msg_FocusRight[2]=it_FocusRight;
	_Context->msg_FocusRight[3]=es_FocusRight;
	_Context->msg_FocusRight[4]=de_FocusRight;
	_Context->msg_FocusRight[5]=nl_FocusRight;
	_Context->msg_FocusRight[6]=pt_FocusRight;
	_Context->msg_FocusRight[7]=xx_FocusRight;
	_Context->hint_FocusRight[0]=en__FocusRight;
	_Context->hint_FocusRight[1]=fr__FocusRight;
	_Context->hint_FocusRight[2]=it__FocusRight;
	_Context->hint_FocusRight[3]=es__FocusRight;
	_Context->hint_FocusRight[4]=de__FocusRight;
	_Context->hint_FocusRight[5]=nl__FocusRight;
	_Context->hint_FocusRight[6]=pt__FocusRight;
	_Context->hint_FocusRight[7]=xx__FocusRight;
	for (i=0; i < 8; i++)_Context->msg_FocusLeft[i]=" ";
	_Context->msg_FocusLeft[0]=en_FocusLeft;
	_Context->msg_FocusLeft[1]=fr_FocusLeft;
	_Context->msg_FocusLeft[2]=it_FocusLeft;
	_Context->msg_FocusLeft[3]=es_FocusLeft;
	_Context->msg_FocusLeft[4]=de_FocusLeft;
	_Context->msg_FocusLeft[5]=nl_FocusLeft;
	_Context->msg_FocusLeft[6]=pt_FocusLeft;
	_Context->msg_FocusLeft[7]=xx_FocusLeft;
	_Context->hint_FocusLeft[0]=en__FocusLeft;
	_Context->hint_FocusLeft[1]=fr__FocusLeft;
	_Context->hint_FocusLeft[2]=it__FocusLeft;
	_Context->hint_FocusLeft[3]=es__FocusLeft;
	_Context->hint_FocusLeft[4]=de__FocusLeft;
	_Context->hint_FocusLeft[5]=nl__FocusLeft;
	_Context->hint_FocusLeft[6]=pt__FocusLeft;
	_Context->hint_FocusLeft[7]=xx__FocusLeft;
	for (i=0; i < 8; i++)_Context->msg_FocusUp[i]=" ";
	_Context->msg_FocusUp[0]=en_FocusUp;
	_Context->msg_FocusUp[1]=fr_FocusUp;
	_Context->msg_FocusUp[2]=it_FocusUp;
	_Context->msg_FocusUp[3]=es_FocusUp;
	_Context->msg_FocusUp[4]=de_FocusUp;
	_Context->msg_FocusUp[5]=nl_FocusUp;
	_Context->msg_FocusUp[6]=pt_FocusUp;
	_Context->msg_FocusUp[7]=xx_FocusUp;
	_Context->hint_FocusUp[0]=en__FocusUp;
	_Context->hint_FocusUp[1]=fr__FocusUp;
	_Context->hint_FocusUp[2]=it__FocusUp;
	_Context->hint_FocusUp[3]=es__FocusUp;
	_Context->hint_FocusUp[4]=de__FocusUp;
	_Context->hint_FocusUp[5]=nl__FocusUp;
	_Context->hint_FocusUp[6]=pt__FocusUp;
	_Context->hint_FocusUp[7]=xx__FocusUp;
	for (i=0; i < 8; i++)_Context->msg_FocusDown[i]=" ";
	_Context->msg_FocusDown[0]=en_FocusDown;
	_Context->msg_FocusDown[1]=fr_FocusDown;
	_Context->msg_FocusDown[2]=it_FocusDown;
	_Context->msg_FocusDown[3]=es_FocusDown;
	_Context->msg_FocusDown[4]=de_FocusDown;
	_Context->msg_FocusDown[5]=nl_FocusDown;
	_Context->msg_FocusDown[6]=pt_FocusDown;
	_Context->msg_FocusDown[7]=xx_FocusDown;
	_Context->hint_FocusDown[0]=en__FocusDown;
	_Context->hint_FocusDown[1]=fr__FocusDown;
	_Context->hint_FocusDown[2]=it__FocusDown;
	_Context->hint_FocusDown[3]=es__FocusDown;
	_Context->hint_FocusDown[4]=de__FocusDown;
	_Context->hint_FocusDown[5]=nl__FocusDown;
	_Context->hint_FocusDown[6]=pt__FocusDown;
	_Context->hint_FocusDown[7]=xx__FocusDown;
	for (i=0; i < 8; i++)_Context->msg_MoveUp[i]=" ";
	_Context->msg_MoveUp[0]=en_MoveUp;
	_Context->msg_MoveUp[1]=fr_MoveUp;
	_Context->msg_MoveUp[2]=it_MoveUp;
	_Context->msg_MoveUp[3]=es_MoveUp;
	_Context->msg_MoveUp[4]=de_MoveUp;
	_Context->msg_MoveUp[5]=nl_MoveUp;
	_Context->msg_MoveUp[6]=pt_MoveUp;
	_Context->msg_MoveUp[7]=xx_MoveUp;
	for (i=0; i < 8; i++)_Context->msg_MoveInOut[i]=" ";
	_Context->msg_MoveInOut[0]=en_MoveInOut;
	_Context->msg_MoveInOut[1]=fr_MoveInOut;
	_Context->msg_MoveInOut[2]=it_MoveInOut;
	_Context->msg_MoveInOut[3]=es_MoveInOut;
	_Context->msg_MoveInOut[4]=de_MoveInOut;
	_Context->msg_MoveInOut[5]=nl_MoveInOut;
	_Context->msg_MoveInOut[6]=pt_MoveInOut;
	_Context->msg_MoveInOut[7]=xx_MoveInOut;
	for (i=0; i < 8; i++)_Context->msg_MoveDown[i]=" ";
	_Context->msg_MoveDown[0]=en_MoveDown;
	_Context->msg_MoveDown[1]=fr_MoveDown;
	_Context->msg_MoveDown[2]=it_MoveDown;
	_Context->msg_MoveDown[3]=es_MoveDown;
	_Context->msg_MoveDown[4]=de_MoveDown;
	_Context->msg_MoveDown[5]=nl_MoveDown;
	_Context->msg_MoveDown[6]=pt_MoveDown;
	_Context->msg_MoveDown[7]=xx_MoveDown;
	for (i=0; i < 8; i++)_Context->msg_GridIcon[i]=" ";
	_Context->msg_GridIcon[0]=en_GridIcon;
	_Context->msg_GridIcon[1]=fr_GridIcon;
	_Context->msg_GridIcon[2]=it_GridIcon;
	_Context->msg_GridIcon[3]=es_GridIcon;
	_Context->msg_GridIcon[4]=de_GridIcon;
	_Context->msg_GridIcon[5]=nl_GridIcon;
	_Context->msg_GridIcon[6]=pt_GridIcon;
	_Context->msg_GridIcon[7]=xx_GridIcon;
	_Context->hint_GridIcon[0]=en__GridIcon;
	_Context->x_GridIcon=114;
	_Context->y_GridIcon=500;
	_Context->w_GridIcon=16;
	_Context->h_GridIcon=20;
	_Context->fg_GridIcon=20;
	_Context->bg_GridIcon=20;
	_Context->fid_GridIcon=1;
	_Context->s_GridIcon=0;
	_Context->p_GridIcon=visual_buffer(_Context->x_GridIcon,_Context->y_GridIcon,_Context->w_GridIcon+2,_Context->h_GridIcon+2);
	for (i=0; i < 8; i++)_Context->msg_FocusZero[i]=" ";
	_Context->msg_FocusZero[0]=en_FocusZero;
	_Context->msg_FocusZero[1]=fr_FocusZero;
	_Context->msg_FocusZero[2]=it_FocusZero;
	_Context->msg_FocusZero[3]=es_FocusZero;
	_Context->msg_FocusZero[4]=de_FocusZero;
	_Context->msg_FocusZero[5]=nl_FocusZero;
	_Context->msg_FocusZero[6]=pt_FocusZero;
	_Context->msg_FocusZero[7]=xx_FocusZero;
	_Context->hint_FocusZero[0]=en__FocusZero;
	for (i=0; i < 8; i++)_Context->msg_Auto3549[i]=" ";
	_Context->msg_Auto3549[0]=en_Auto3549;
	_Context->msg_Auto3549[1]=fr_Auto3549;
	_Context->msg_Auto3549[2]=it_Auto3549;
	_Context->msg_Auto3549[3]=es_Auto3549;
	_Context->msg_Auto3549[4]=de_Auto3549;
	_Context->msg_Auto3549[5]=nl_Auto3549;
	_Context->msg_Auto3549[6]=pt_Auto3549;
	_Context->msg_Auto3549[7]=xx_Auto3549;
	_Context->hint_Auto3549[0]=en__Auto3549;
	return(0);
}

public 	int	visual_3d_cursor_hide(struct visual_3d_cursor_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_GridIcon != (void *) 0)
	&& (_Context->s_GridIcon != 0)) {
		(void)visual_buffer_put(_Context->p_GridIcon,_Context->x_GridIcon,_Context->y_GridIcon);
		_Context->s_GridIcon=0;
		}

	return(result);
}

public	int	visual_3d_cursor_remove(struct visual_3d_cursor_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->p_GridIcon != (void *) 0)
		_Context->p_GridIcon = visual_drop(_Context->p_GridIcon);
	_Context=liberate(_Context);

	return(result);
}
private int on_AtX_show(struct visual_3d_cursor_context * _Context) {
	int x;
	x=get_camera_position_x();
	sprintf(_Context->buffer_AtX,"%u",x);
	visual_frame(97,281,48+2,16+2,5);
visual_text(97+1,281+1,48,16,vfh[1],0,0,_Context->buffer_AtX,6,3);
;
	return(-1);
}
private int on_AtY_show(struct visual_3d_cursor_context * _Context) {
	int x;
	x=get_camera_position_y();
	sprintf(_Context->buffer_AtY,"%u",x);
	visual_frame(97,300,48+2,16+2,5);
visual_text(97+1,300+1,48,16,vfh[1],0,0,_Context->buffer_AtY,6,3);
;
	return(-1);
}
private int on_AtZ_show(struct visual_3d_cursor_context * _Context) {
	int x;
	x=get_camera_position_z();
	sprintf(_Context->buffer_AtZ,"%u",x);
	visual_frame(97,319,48+2,16+2,5);
visual_text(97+1,319+1,48,16,vfh[1],16,31,_Context->buffer_AtZ,6,3);
;
	return(-1);
}

public	int	visual_3d_cursor_show(struct visual_3d_cursor_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(95,170,56,400,GetWidgetStyle(7)," ",0)) != 0)
) {
		visual_filzone(95,170,56,400,21,16);
		}
	_Context->trigger_AddView=visual_trigger_code(_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]));
	visual_button(97,551,24,16,vfh[8],27,28,_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]),0);
	_Context->trigger_SzlView=visual_trigger_code(_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]));
	visual_button(123,551,24,16,vfh[8],27,28,_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]),0);
	visual_text(95,186,56,16,vfh[2],0,0,_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]),1283);
	visual_text(95,537,56,16,vfh[2],0,0,_Context->msg_Auto3546[_Context->language],strlen(_Context->msg_Auto3546[_Context->language]),1283);
	visual_text(95,469,56,16,vfh[2],0,0,_Context->msg_Auto3547[_Context->language],strlen(_Context->msg_Auto3547[_Context->language]),1283);
	visual_text(95,346,56,16,vfh[2],0,0,_Context->msg_Auto3548[_Context->language],strlen(_Context->msg_Auto3548[_Context->language]),1283);
	_Context->trigger_Xadjust=visual_trigger_code(_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]));
	visual_button(97,361,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),0);
	visual_frame(97,378,48+2,16+2,5);
	visual_text(97+1,378+1,48,16,vfh[1],0,0,_Context->buffer_ByX,6,3);
	_Context->trigger_Yadjust=visual_trigger_code(_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]));
	visual_button(97,397,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),0);
	visual_frame(97,414,48+2,16+2,5);
	visual_text(97+1,414+1,48,16,vfh[1],0,0,_Context->buffer_ByY,6,3);
	_Context->trigger_Zadjust=visual_trigger_code(_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]));
	visual_button(97,433,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),0);
	visual_frame(97,450,48+2,16+2,5);
	visual_text(97+1,450+1,48,16,vfh[1],0,0,_Context->buffer_ByZ,6,3);
	visual_image(97,218,16,20,_Context->msg_MoveLeft[_Context->language],0);
	visual_image(129,218,16,20,_Context->msg_MoveRight[_Context->language],0);
	visual_image(130,500,20,20,_Context->msg_FocusRight[_Context->language],0);
	visual_image(98,500,20,20,_Context->msg_FocusLeft[_Context->language],0);
	visual_image(114,484,20,20,_Context->msg_FocusUp[_Context->language],0);
	visual_image(114,516,20,20,_Context->msg_FocusDown[_Context->language],0);
	visual_image(113,202,16,20,_Context->msg_MoveUp[_Context->language],0);
	visual_image(113,218,16,20,_Context->msg_MoveInOut[_Context->language],0);
	visual_image(113,234,16,20,_Context->msg_MoveDown[_Context->language],0);
	visual_image(114,500,16,20,_Context->msg_FocusZero[_Context->language],0);
	visual_text(95,264,56,16,vfh[2],0,0,_Context->msg_Auto3549[_Context->language],strlen(_Context->msg_Auto3549[_Context->language]),1283);
	(void) on_AtX_show(_Context);
	(void) on_AtY_show(_Context);
	(void) on_AtZ_show(_Context);
	visual_thaw(0,30,220,420);

	return(0);
}
private int on_AddView_event(struct visual_3d_cursor_context * _Context) {
	if(!(camera_add_view())){
	status_message(_Context->msg_AddMsg[_Context->language],3);
	}
	return(-1);
}
private int on_SzlView_event(struct visual_3d_cursor_context * _Context) {
	if(!(camera_del_view())){
	status_message(_Context->msg_DelMsg[_Context->language],3);
	}
	return(-1);
}
private int on_Xadjust_event(struct visual_3d_cursor_context * _Context) {
	int x;
	int b;
	b=visual_event(2);
	adjust_3d_step(1,b,&x);
	sprintf(_Context->buffer_ByX,"%u",x);
	visual_frame(97,378,48+2,16+2,5);
visual_text(97+1,378+1,48,16,vfh[1],0,0,_Context->buffer_ByX,6,3);
;
	return(-1);
}
private int on_Yadjust_event(struct visual_3d_cursor_context * _Context) {
	int x;
	int b;
	b=visual_event(2);
	adjust_3d_step(2,b,&x);
	sprintf(_Context->buffer_ByY,"%u",x);
	visual_frame(97,414,48+2,16+2,5);
visual_text(97+1,414+1,48,16,vfh[1],0,0,_Context->buffer_ByY,6,3);
;
	return(-1);
}
private int on_Zadjust_event(struct visual_3d_cursor_context * _Context) {
	int x;
	int b;
	b=visual_event(2);
	adjust_3d_step(3,b,&x);
	sprintf(_Context->buffer_ByZ,"%u",x);
	visual_frame(97,450,48+2,16+2,5);
visual_text(97+1,450+1,48,16,vfh[1],0,0,_Context->buffer_ByZ,6,3);
;
	return(-1);
}
private int on_MoveLeft_event(struct visual_3d_cursor_context * _Context) {
	_Context->x_GridIcon=97;
	_Context->y_GridIcon=218;
	if(visual_event(2)==1)
	_3d_motion(_Context, 4);
	else _3d_motion(_Context, 2);
	return(-1);
}
private int on_MoveRight_event(struct visual_3d_cursor_context * _Context) {
	_Context->x_GridIcon=129;
	_Context->y_GridIcon=218;
	if(visual_event(2)==1)
	_3d_motion(_Context, 2);
	else _3d_motion(_Context, 4);
	return(-1);
}
private int on_FocusRight_event(struct visual_3d_cursor_context * _Context) {
	camera_x_focus(atoi(_Context->buffer_ByX));
	return(-1);
}
private int on_FocusLeft_event(struct visual_3d_cursor_context * _Context) {
	camera_x_focus(-atoi(_Context->buffer_ByX));
	return(-1);
}
private int on_FocusUp_event(struct visual_3d_cursor_context * _Context) {
	camera_y_focus(-atoi(_Context->buffer_ByY));
	return(-1);
}
private int on_FocusDown_event(struct visual_3d_cursor_context * _Context) {
	camera_y_focus(atoi(_Context->buffer_ByY));
	return(-1);
}
private int on_MoveUp_event(struct visual_3d_cursor_context * _Context) {
	_Context->x_GridIcon=113;
	_Context->y_GridIcon=202;
	if(visual_event(2)==1)
	_3d_motion(_Context, 1);
	else _3d_motion(_Context, 3);
	return(-1);
}
private int on_MoveInOut_event(struct visual_3d_cursor_context * _Context) {
	_Context->x_GridIcon=113;
	_Context->y_GridIcon=218;
	if(visual_event(2)==1)
	_3d_motion(_Context, 5);
	else _3d_motion(_Context, 6);
	return(-1);
}
private int on_MoveDown_event(struct visual_3d_cursor_context * _Context) {
	_Context->x_GridIcon=113;
	_Context->y_GridIcon=234;
	if(visual_event(2)==1)
	_3d_motion(_Context, 3);
	else _3d_motion(_Context, 1);
	return(-1);
}
private int on_GridIcon_event(struct visual_3d_cursor_context * _Context) {
	if(visual_event(2)==1)
	_3d_motion(_Context, 5);
	else _3d_motion(_Context, 6);
	return(-1);
}
private int on_FocusZero_event(struct visual_3d_cursor_context * _Context) {
	camera_xy_focus(0);
	return(-1);
}


public	int	visual_3d_cursor_event(
struct visual_3d_cursor_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_AddView == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			_Context->trigger_AddView=visual_trigger_code(_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]));
			visual_button(97,551,24,16,vfh[8],27,28,_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			_Context->trigger_AddView=visual_trigger_code(_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]));
	visual_button(97,551,24,16,vfh[8],27,28,_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_AddView_event(_Context);

			}
		_Context->focus_item=1;
		return(256);
		}
		if (_Context->trigger_SzlView == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			_Context->trigger_SzlView=visual_trigger_code(_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]));
			visual_button(123,551,24,16,vfh[8],27,28,_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			_Context->trigger_SzlView=visual_trigger_code(_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]));
	visual_button(123,551,24,16,vfh[8],27,28,_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_SzlView_event(_Context);

			}
		_Context->focus_item=2;
		return(256);
		}
		if (_Context->trigger_Xadjust == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			_Context->trigger_Xadjust=visual_trigger_code(_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]));
			visual_button(97,361,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			_Context->trigger_Xadjust=visual_trigger_code(_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]));
	visual_button(97,361,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_Xadjust_event(_Context);

			}
		_Context->focus_item=3;
		return(256);
		}
		if (_Context->trigger_Yadjust == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			_Context->trigger_Yadjust=visual_trigger_code(_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]));
			visual_button(97,397,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			_Context->trigger_Yadjust=visual_trigger_code(_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]));
	visual_button(97,397,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_Yadjust_event(_Context);

			}
		_Context->focus_item=4;
		return(256);
		}
		if (_Context->trigger_Zadjust == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			_Context->trigger_Zadjust=visual_trigger_code(_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]));
			visual_button(97,433,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			_Context->trigger_Zadjust=visual_trigger_code(_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]));
	visual_button(97,433,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_Zadjust_event(_Context);

			}
		_Context->focus_item=5;
		return(256);
		}
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 97 ) 
	&&  ( my >= 551 ) 
	&&  ( mx <= 121 ) 
	&&  ( my <= 567 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			_Context->trigger_AddView=visual_trigger_code(_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]));
			visual_button(97,551,24,16,vfh[8],27,28,_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			_Context->trigger_AddView=visual_trigger_code(_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]));
	visual_button(97,551,24,16,vfh[8],27,28,_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_AddView_event(_Context);

			}
		_Context->focus_item=1;
		return(256);
		}
	if (( mx >= 123 ) 
	&&  ( my >= 551 ) 
	&&  ( mx <= 147 ) 
	&&  ( my <= 567 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			_Context->trigger_SzlView=visual_trigger_code(_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]));
			visual_button(123,551,24,16,vfh[8],27,28,_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			_Context->trigger_SzlView=visual_trigger_code(_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]));
	visual_button(123,551,24,16,vfh[8],27,28,_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_SzlView_event(_Context);

			}
		_Context->focus_item=2;
		return(256);
		}
	if (( mx >= 97 ) 
	&&  ( my >= 361 ) 
	&&  ( mx <= 147 ) 
	&&  ( my <= 377 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			_Context->trigger_Xadjust=visual_trigger_code(_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]));
			visual_button(97,361,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			_Context->trigger_Xadjust=visual_trigger_code(_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]));
	visual_button(97,361,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_Xadjust_event(_Context);

			}
		_Context->focus_item=3;
		return(256);
		}
	if (( mx >= 97 ) 
	&&  ( my >= 397 ) 
	&&  ( mx <= 147 ) 
	&&  ( my <= 413 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			_Context->trigger_Yadjust=visual_trigger_code(_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]));
			visual_button(97,397,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			_Context->trigger_Yadjust=visual_trigger_code(_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]));
	visual_button(97,397,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_Yadjust_event(_Context);

			}
		_Context->focus_item=4;
		return(256);
		}
	if (( mx >= 97 ) 
	&&  ( my >= 433 ) 
	&&  ( mx <= 147 ) 
	&&  ( my <= 449 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			_Context->trigger_Zadjust=visual_trigger_code(_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]));
			visual_button(97,433,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			_Context->trigger_Zadjust=visual_trigger_code(_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]));
	visual_button(97,433,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_Zadjust_event(_Context);

			}
		_Context->focus_item=5;
		return(256);
		}
	if (( mx >= 97 ) 
	&&  ( my >= 218 ) 
	&&  ( mx <= 113 ) 
	&&  ( my <= 238 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_MoveLeft_event(_Context);

			}
		_Context->focus_item=6;
		return(256);
		}
	if (( mx >= 129 ) 
	&&  ( my >= 218 ) 
	&&  ( mx <= 145 ) 
	&&  ( my <= 238 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_MoveRight_event(_Context);

			}
		_Context->focus_item=7;
		return(256);
		}
	if (( mx >= 130 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 150 ) 
	&&  ( my <= 520 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_FocusRight_event(_Context);

			}
		_Context->focus_item=8;
		return(256);
		}
	if (( mx >= 98 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 118 ) 
	&&  ( my <= 520 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_FocusLeft_event(_Context);

			}
		_Context->focus_item=9;
		return(256);
		}
	if (( mx >= 114 ) 
	&&  ( my >= 484 ) 
	&&  ( mx <= 134 ) 
	&&  ( my <= 504 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_FocusUp_event(_Context);

			}
		_Context->focus_item=10;
		return(256);
		}
	if (( mx >= 114 ) 
	&&  ( my >= 516 ) 
	&&  ( mx <= 134 ) 
	&&  ( my <= 536 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_FocusDown_event(_Context);

			}
		_Context->focus_item=11;
		return(256);
		}
	if (( mx >= 113 ) 
	&&  ( my >= 202 ) 
	&&  ( mx <= 129 ) 
	&&  ( my <= 222 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_MoveUp_event(_Context);

			}
		_Context->focus_item=12;
		return(256);
		}
	if (( mx >= 113 ) 
	&&  ( my >= 218 ) 
	&&  ( mx <= 129 ) 
	&&  ( my <= 238 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_MoveInOut_event(_Context);

			}
		_Context->focus_item=13;
		return(256);
		}
	if (( mx >= 113 ) 
	&&  ( my >= 234 ) 
	&&  ( mx <= 129 ) 
	&&  ( my <= 254 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_MoveDown_event(_Context);

			}
		_Context->focus_item=14;
		return(256);
		}
	if ((mx >= _Context->x_GridIcon ) 
	&&  (my >= _Context->y_GridIcon ) 
	&&  (mx <  (_Context->x_GridIcon+_Context->w_GridIcon)) 
	&&  (my <  (_Context->y_GridIcon+_Context->h_GridIcon))) {
		if ( visual_event(1) &  0x20 ) {
		(void) on_GridIcon_event(_Context);

			}
		_Context->focus_item=15;
		return(256);
		}
	if (( mx >= 114 ) 
	&&  ( my >= 500 ) 
	&&  ( mx <= 130 ) 
	&&  ( my <= 520 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_FocusZero_event(_Context);

			}
		_Context->focus_item=16;
		return(256);
		}

	return(-1);
}
private int on_MoveLeft_getfocus(struct visual_3d_cursor_context * _Context) {
	return(visual_getch());
	return(-1);
}
private int on_MoveRight_getfocus(struct visual_3d_cursor_context * _Context) {
	return(visual_getch());
	return(-1);
}
private int on_FocusRight_getfocus(struct visual_3d_cursor_context * _Context) {
	return(visual_getch());
	return(-1);
}
private int on_FocusLeft_getfocus(struct visual_3d_cursor_context * _Context) {
	return(visual_getch());
	return(-1);
}
private int on_FocusUp_getfocus(struct visual_3d_cursor_context * _Context) {
	return(visual_getch());
	return(-1);
}
private int on_FocusDown_getfocus(struct visual_3d_cursor_context * _Context) {
	return(visual_getch());
	return(-1);
}
private int on_MoveUp_getfocus(struct visual_3d_cursor_context * _Context) {
	return(visual_getch());
	return(-1);
}
private int on_MoveInOut_getfocus(struct visual_3d_cursor_context * _Context) {
	return(visual_getch());
	return(-1);
}
private int on_MoveDown_getfocus(struct visual_3d_cursor_context * _Context) {
	return(visual_getch());
	return(-1);
}
private int on_GridIcon_getfocus(struct visual_3d_cursor_context * _Context) {
	return(visual_getch());
	return(-1);
}
private int on_FocusZero_getfocus(struct visual_3d_cursor_context * _Context) {
	return(visual_getch());
	return(-1);
}


public	int	visual_3d_cursor_focus(struct visual_3d_cursor_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* AddView */
				_Context->trigger_AddView=visual_trigger_code(_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]));
				visual_button(97,551,24,16,vfh[8],27,28,_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_AddView=visual_trigger_code(_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]));
	visual_button(97,551,24,16,vfh[8],27,28,_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]),0);
				break;
			case	0x2 :
				/* SzlView */
				_Context->trigger_SzlView=visual_trigger_code(_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]));
				visual_button(123,551,24,16,vfh[8],27,28,_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_SzlView=visual_trigger_code(_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]));
	visual_button(123,551,24,16,vfh[8],27,28,_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]),0);
				break;
			case	0x3 :
				/* Xadjust */
				_Context->trigger_Xadjust=visual_trigger_code(_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]));
				visual_button(97,361,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Xadjust=visual_trigger_code(_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]));
	visual_button(97,361,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),0);
				break;
			case	0x4 :
				/* Yadjust */
				_Context->trigger_Yadjust=visual_trigger_code(_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]));
				visual_button(97,397,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Yadjust=visual_trigger_code(_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]));
	visual_button(97,397,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),0);
				break;
			case	0x5 :
				/* Zadjust */
				_Context->trigger_Zadjust=visual_trigger_code(_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]));
				visual_button(97,433,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Zadjust=visual_trigger_code(_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]));
	visual_button(97,433,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),0);
				break;
			case	0x6 :
				/* MoveLeft */
				_Context->keycode = on_MoveLeft_getfocus(_Context);
				break;
			case	0x7 :
				/* MoveRight */
				_Context->keycode = on_MoveRight_getfocus(_Context);
				break;
			case	0x8 :
				/* FocusRight */
				_Context->keycode = on_FocusRight_getfocus(_Context);
				break;
			case	0x9 :
				/* FocusLeft */
				_Context->keycode = on_FocusLeft_getfocus(_Context);
				break;
			case	0xa :
				/* FocusUp */
				_Context->keycode = on_FocusUp_getfocus(_Context);
				break;
			case	0xb :
				/* FocusDown */
				_Context->keycode = on_FocusDown_getfocus(_Context);
				break;
			case	0xc :
				/* MoveUp */
				_Context->keycode = on_MoveUp_getfocus(_Context);
				break;
			case	0xd :
				/* MoveInOut */
				_Context->keycode = on_MoveInOut_getfocus(_Context);
				break;
			case	0xe :
				/* MoveDown */
				_Context->keycode = on_MoveDown_getfocus(_Context);
				break;
			case	0xf :
				/* GridIcon */
				_Context->keycode = on_GridIcon_getfocus(_Context);
				break;
			case	0x10 :
				/* FocusZero */
				_Context->keycode = on_FocusZero_getfocus(_Context);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			visual_3d_cursor_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=16;
			visual_3d_cursor_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=visual_3d_cursor_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* AddView */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_AddView=visual_trigger_code(_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]));
						visual_button(97,551,24,16,vfh[8],27,28,_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_AddView=visual_trigger_code(_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]));
	visual_button(97,551,24,16,vfh[8],27,28,_Context->msg_AddView[_Context->language],strlen(_Context->msg_AddView[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_AddView_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* SzlView */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SzlView=visual_trigger_code(_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]));
						visual_button(123,551,24,16,vfh[8],27,28,_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SzlView=visual_trigger_code(_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]));
	visual_button(123,551,24,16,vfh[8],27,28,_Context->msg_SzlView[_Context->language],strlen(_Context->msg_SzlView[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SzlView_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Xadjust */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Xadjust=visual_trigger_code(_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]));
						visual_button(97,361,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Xadjust=visual_trigger_code(_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]));
	visual_button(97,361,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Xadjust_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Yadjust */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Yadjust=visual_trigger_code(_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]));
						visual_button(97,397,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Yadjust=visual_trigger_code(_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]));
	visual_button(97,397,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Yadjust_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Zadjust */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Zadjust=visual_trigger_code(_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]));
						visual_button(97,433,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Zadjust=visual_trigger_code(_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]));
	visual_button(97,433,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Zadjust_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* MoveLeft */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_MoveLeft_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* MoveRight */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_MoveRight_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* FocusRight */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_FocusRight_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* FocusLeft */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_FocusLeft_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* FocusUp */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_FocusUp_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* FocusDown */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_FocusDown_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* MoveUp */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_MoveUp_event(_Context)) != -1) break;

						}
					continue;
				case	0xd :
					/* MoveInOut */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_MoveInOut_event(_Context)) != -1) break;

						}
					continue;
				case	0xe :
					/* MoveDown */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_MoveDown_event(_Context)) != -1) break;

						}
					continue;
				case	0xf :
					/* GridIcon */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_GridIcon_event(_Context)) != -1) break;

						}
					continue;
				case	0x10 :
					/* FocusZero */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_FocusZero_event(_Context)) != -1) break;

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

public	int	visual_3d_cursor()
{
	int	status=0;
	struct visual_3d_cursor_context * _Context=(struct visual_3d_cursor_context*) 0;
	status = visual_3d_cursor_create(&_Context);
	if ( status != 0) return(status);
	status = visual_3d_cursor_show(_Context);
	status = visual_3d_cursor_focus(_Context);
	status = visual_3d_cursor_hide(_Context);
	status = visual_3d_cursor_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcursor_c */
