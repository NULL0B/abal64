
#ifndef _vcursor_c
#define _vcursor_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vcursor.xml  */
/* Target         : vcursor.c  */
/* Identification : 0.0-1100084507-2590.2589 */
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
#define en_Auto1567   "3dView"
#define fr_Auto1567   "3dView"
#define it_Auto1567   "3dView"
#define es_Auto1567   "3dView"
#define de_Auto1567   "3dView"
#define nl_Auto1567   "3dView"
#define pt_Auto1567   "3dView"
#define xx_Auto1567   "3dView"
#define en_Auto1568   "Step"
#define fr_Auto1568   "Pas"
#define it_Auto1568   "Step"
#define es_Auto1568   "Step"
#define de_Auto1568   "Step"
#define nl_Auto1568   "Step"
#define pt_Auto1568   "Step"
#define xx_Auto1568   "Step"
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
#define en_Auto1575   "Position"
#define fr_Auto1575   "Position"
#define it_Auto1575   "Position"
#define es_Auto1575   "Position"
#define de_Auto1575   "Position"
#define nl_Auto1575   "Position"
#define pt_Auto1575   "Position"
#define xx_Auto1575   "Position"
#define en_AtX   ""
#define en_AtY   ""
#define en_AtZ   ""
static int	vfh[10];

private struct visual_3d_cursor_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_EdSkin[8];
	char * msg_Auto1567[8];
	char * msg_Auto1568[8];
	char * msg_Xadjust[8];
	int	trigger_Xadjust;
	char	buffer_ByX[7];
	char * msg_Yadjust[8];
	int	trigger_Yadjust;
	char	buffer_ByY[7];
	char * msg_Zadjust[8];
	int	trigger_Zadjust;
	char	buffer_ByZ[7];
	char * msg_MoveLeft[8];
	char * msg_MoveRight[8];
	char * msg_MoveUp[8];
	char * msg_MoveInOut[8];
	char * msg_MoveDown[8];
	char * msg_GridIcon[8];
	int	x_GridIcon;
	int	y_GridIcon;
	int	w_GridIcon;
	int	h_GridIcon;
	int	fg_GridIcon;
	int	bg_GridIcon;
	int	fid_GridIcon;
	int	s_GridIcon;
	void *	p_GridIcon;
	char * msg_Auto1575[8];
	char	buffer_AtX[7];
	char	buffer_AtY[7];
	char	buffer_AtZ[7];
	int	x_,y_,w_,h_;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
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
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct visual_3d_cursor_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=9;
	for (i=0; i < 8; i++)_Context->msg_EdSkin[i]=" ";
	_Context->msg_EdSkin[0]=en_EdSkin;
	_Context->msg_EdSkin[1]=fr_EdSkin;
	_Context->msg_EdSkin[2]=it_EdSkin;
	_Context->msg_EdSkin[3]=es_EdSkin;
	_Context->msg_EdSkin[4]=de_EdSkin;
	_Context->msg_EdSkin[5]=nl_EdSkin;
	_Context->msg_EdSkin[6]=pt_EdSkin;
	_Context->msg_EdSkin[7]=xx_EdSkin;
	for (i=0; i < 8; i++)_Context->msg_Auto1567[i]=" ";
	_Context->msg_Auto1567[0]=en_Auto1567;
	_Context->msg_Auto1567[1]=fr_Auto1567;
	_Context->msg_Auto1567[2]=it_Auto1567;
	_Context->msg_Auto1567[3]=es_Auto1567;
	_Context->msg_Auto1567[4]=de_Auto1567;
	_Context->msg_Auto1567[5]=nl_Auto1567;
	_Context->msg_Auto1567[6]=pt_Auto1567;
	_Context->msg_Auto1567[7]=xx_Auto1567;
	for (i=0; i < 8; i++)_Context->msg_Auto1568[i]=" ";
	_Context->msg_Auto1568[0]=en_Auto1568;
	_Context->msg_Auto1568[1]=fr_Auto1568;
	_Context->msg_Auto1568[2]=it_Auto1568;
	_Context->msg_Auto1568[3]=es_Auto1568;
	_Context->msg_Auto1568[4]=de_Auto1568;
	_Context->msg_Auto1568[5]=nl_Auto1568;
	_Context->msg_Auto1568[6]=pt_Auto1568;
	_Context->msg_Auto1568[7]=xx_Auto1568;
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
	_Context->x_GridIcon=36;
	_Context->y_GridIcon=104;
	_Context->w_GridIcon=16;
	_Context->h_GridIcon=20;
	_Context->fg_GridIcon=20;
	_Context->bg_GridIcon=20;
	_Context->fid_GridIcon=1;
	_Context->s_GridIcon=0;
	_Context->p_GridIcon=visual_buffer(_Context->x_GridIcon,_Context->y_GridIcon,_Context->w_GridIcon,_Context->h_GridIcon);
	for (i=0; i < 8; i++)_Context->msg_Auto1575[i]=" ";
	_Context->msg_Auto1575[0]=en_Auto1575;
	_Context->msg_Auto1575[1]=fr_Auto1575;
	_Context->msg_Auto1575[2]=it_Auto1575;
	_Context->msg_Auto1575[3]=es_Auto1575;
	_Context->msg_Auto1575[4]=de_Auto1575;
	_Context->msg_Auto1575[5]=nl_Auto1575;
	_Context->msg_Auto1575[6]=pt_Auto1575;
	_Context->msg_Auto1575[7]=xx_Auto1575;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(469271488,3224439157,775913,2201873152);
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
	visual_frame(4,148,48+2,16+2,5);
visual_text(4+1,148+1,48,16,vfh[1],0,0,_Context->buffer_AtX,6,3);
;
	return(-1);
}
private int on_AtY_show(struct visual_3d_cursor_context * _Context) {
	int x;
	x=get_camera_position_y();
	sprintf(_Context->buffer_AtY,"%u",x);
	visual_frame(4,170,48+2,16+2,5);
visual_text(4+1,170+1,48,16,vfh[1],0,0,_Context->buffer_AtY,6,3);
;
	return(-1);
}
private int on_AtZ_show(struct visual_3d_cursor_context * _Context) {
	int x;
	x=get_camera_position_z();
	sprintf(_Context->buffer_AtZ,"%u",x);
	visual_frame(4,192,48+2,16+2,5);
visual_text(4+1,192+1,48,16,vfh[1],16,31,_Context->buffer_AtZ,6,3);
;
	return(-1);
}

public	int	visual_3d_cursor_show(struct visual_3d_cursor_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	visual_filzone(2,40,54,316,5397,0);
	visual_text(2,48,56,16,vfh[2],0,0,_Context->msg_Auto1567[_Context->language],strlen(_Context->msg_Auto1567[_Context->language]),1283);
	visual_text(2,218,56,16,vfh[2],0,0,_Context->msg_Auto1568[_Context->language],strlen(_Context->msg_Auto1568[_Context->language]),1283);
	_Context->trigger_Xadjust=visual_trigger_code(_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]));
	visual_button(4,235,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),0);
	visual_frame(4,252,48+2,16+2,5);
	visual_text(4+1,252+1,48,16,vfh[1],0,0,_Context->buffer_ByX,6,3);
	_Context->trigger_Yadjust=visual_trigger_code(_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]));
	visual_button(4,275,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),0);
	visual_frame(4,292,48+2,16+2,5);
	visual_text(4+1,292+1,48,16,vfh[1],0,0,_Context->buffer_ByY,6,3);
	_Context->trigger_Zadjust=visual_trigger_code(_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]));
	visual_button(4,315,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),0);
	visual_frame(4,332,48+2,16+2,5);
	visual_text(4+1,332+1,48,16,vfh[1],0,0,_Context->buffer_ByZ,6,3);
	visual_image(4,88,16,20,_Context->msg_MoveLeft[_Context->language],0);
	visual_image(36,88,16,20,_Context->msg_MoveRight[_Context->language],0);
	visual_image(20,72,16,20,_Context->msg_MoveUp[_Context->language],0);
	visual_image(20,88,16,20,_Context->msg_MoveInOut[_Context->language],0);
	visual_image(20,104,16,20,_Context->msg_MoveDown[_Context->language],0);
	visual_text(0,133,59,17,vfh[2],0,0,_Context->msg_Auto1575[_Context->language],strlen(_Context->msg_Auto1575[_Context->language]),1283);
	(void) on_AtX_show(_Context);
	(void) on_AtY_show(_Context);
	(void) on_AtZ_show(_Context);
	visual_thaw(0,40,64,316);

	return(0);
}
private int on_Xadjust_event(struct visual_3d_cursor_context * _Context) {
	int x;
	int b;
	b=visual_event(2);
	adjust_3d_step(1,b,&x);
	sprintf(_Context->buffer_ByX,"%u",x);
	visual_frame(4,252,48+2,16+2,5);
visual_text(4+1,252+1,48,16,vfh[1],0,0,_Context->buffer_ByX,6,3);
;
	return(-1);
}
private int on_Yadjust_event(struct visual_3d_cursor_context * _Context) {
	int x;
	int b;
	b=visual_event(2);
	adjust_3d_step(2,b,&x);
	sprintf(_Context->buffer_ByY,"%u",x);
	visual_frame(4,292,48+2,16+2,5);
visual_text(4+1,292+1,48,16,vfh[1],0,0,_Context->buffer_ByY,6,3);
;
	return(-1);
}
private int on_Zadjust_event(struct visual_3d_cursor_context * _Context) {
	int x;
	int b;
	b=visual_event(2);
	adjust_3d_step(3,b,&x);
	sprintf(_Context->buffer_ByZ,"%u",x);
	visual_frame(4,332,48+2,16+2,5);
visual_text(4+1,332+1,48,16,vfh[1],0,0,_Context->buffer_ByZ,6,3);
;
	return(-1);
}
private int on_MoveLeft_event(struct visual_3d_cursor_context * _Context) {
	_Context->x_GridIcon=4;
	_Context->y_GridIcon=88;
	if(visual_event(2)==1)
	_3d_motion(_Context, 4);
	else _3d_motion(_Context, 2);
	return(-1);
}
private int on_MoveRight_event(struct visual_3d_cursor_context * _Context) {
	_Context->x_GridIcon=36;
	_Context->y_GridIcon=88;
	if(visual_event(2)==1)
	_3d_motion(_Context, 2);
	else _3d_motion(_Context, 4);
	return(-1);
}
private int on_MoveUp_event(struct visual_3d_cursor_context * _Context) {
	_Context->x_GridIcon=20;
	_Context->y_GridIcon=72;
	if(visual_event(2)==1)
	_3d_motion(_Context, 1);
	else _3d_motion(_Context, 3);
	return(-1);
}
private int on_MoveInOut_event(struct visual_3d_cursor_context * _Context) {
	_Context->x_GridIcon=20;
	_Context->y_GridIcon=88;
	if(visual_event(2)==1)
	_3d_motion(_Context, 5);
	else _3d_motion(_Context, 6);
	return(-1);
}
private int on_MoveDown_event(struct visual_3d_cursor_context * _Context) {
	_Context->x_GridIcon=20;
	_Context->y_GridIcon=104;
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


public	int	visual_3d_cursor_event(
struct visual_3d_cursor_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Xadjust == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(4,235,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(4,235,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_Xadjust_event(_Context);

			}
		_Context->focus_item=1;
		return(256);
		}
		if (_Context->trigger_Yadjust == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(4,275,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(4,275,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_Yadjust_event(_Context);

			}
		_Context->focus_item=2;
		return(256);
		}
		if (_Context->trigger_Zadjust == mb ){
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(4,315,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(4,315,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_Zadjust_event(_Context);

			}
		_Context->focus_item=3;
		return(256);
		}
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 4 ) 
	&&  ( my >= 235 ) 
	&&  ( mx <= 54 ) 
	&&  ( my <= 251 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(4,235,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(4,235,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_Xadjust_event(_Context);

			}
		_Context->focus_item=1;
		return(256);
		}
	if (( mx >= 4 ) 
	&&  ( my >= 275 ) 
	&&  ( mx <= 54 ) 
	&&  ( my <= 291 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(4,275,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(4,275,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_Yadjust_event(_Context);

			}
		_Context->focus_item=2;
		return(256);
		}
	if (( mx >= 4 ) 
	&&  ( my >= 315 ) 
	&&  ( mx <= 54 ) 
	&&  ( my <= 331 )) {
		if (visual_event(1) & _MIMO_DOWN) {
			visual_button(4,315,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),2);
			}
		else if (visual_event(1) & _MIMO_UP) {
			visual_button(4,315,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),0);
			}
		if ( visual_event(1) &  0x20 ) {
		(void) on_Zadjust_event(_Context);

			}
		_Context->focus_item=3;
		return(256);
		}
	if (( mx >= 4 ) 
	&&  ( my >= 88 ) 
	&&  ( mx <= 20 ) 
	&&  ( my <= 108 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_MoveLeft_event(_Context);

			}
		_Context->focus_item=4;
		return(256);
		}
	if (( mx >= 36 ) 
	&&  ( my >= 88 ) 
	&&  ( mx <= 52 ) 
	&&  ( my <= 108 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_MoveRight_event(_Context);

			}
		_Context->focus_item=5;
		return(256);
		}
	if (( mx >= 20 ) 
	&&  ( my >= 72 ) 
	&&  ( mx <= 36 ) 
	&&  ( my <= 92 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_MoveUp_event(_Context);

			}
		_Context->focus_item=6;
		return(256);
		}
	if (( mx >= 20 ) 
	&&  ( my >= 88 ) 
	&&  ( mx <= 36 ) 
	&&  ( my <= 108 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_MoveInOut_event(_Context);

			}
		_Context->focus_item=7;
		return(256);
		}
	if (( mx >= 20 ) 
	&&  ( my >= 104 ) 
	&&  ( mx <= 36 ) 
	&&  ( my <= 124 )) {
		if ( visual_event(1) &  0x10 ) {
		(void) on_MoveDown_event(_Context);

			}
		_Context->focus_item=8;
		return(256);
		}
	if ((mx >= _Context->x_GridIcon ) 
	&&  (my >= _Context->y_GridIcon ) 
	&&  (mx <  (_Context->x_GridIcon+_Context->w_GridIcon)) 
	&&  (my <  (_Context->y_GridIcon+_Context->h_GridIcon))) {
		if ( visual_event(1) &  0x20 ) {
		(void) on_GridIcon_event(_Context);

			}
		_Context->focus_item=9;
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


public	int	visual_3d_cursor_focus(struct visual_3d_cursor_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Xadjust */
				visual_button(4,235,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(4,235,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),0);
				break;
			case	0x2 :
				/* Yadjust */
				visual_button(4,275,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(4,275,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),0);
				break;
			case	0x3 :
				/* Zadjust */
				visual_button(4,315,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(4,315,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),0);
				break;
			case	0x4 :
				/* MoveLeft */
				if ((_Context->keycode = on_MoveLeft_getfocus(_Context)) != -1) break;
				break;
			case	0x5 :
				/* MoveRight */
				if ((_Context->keycode = on_MoveRight_getfocus(_Context)) != -1) break;
				break;
			case	0x6 :
				/* MoveUp */
				if ((_Context->keycode = on_MoveUp_getfocus(_Context)) != -1) break;
				break;
			case	0x7 :
				/* MoveInOut */
				if ((_Context->keycode = on_MoveInOut_getfocus(_Context)) != -1) break;
				break;
			case	0x8 :
				/* MoveDown */
				if ((_Context->keycode = on_MoveDown_getfocus(_Context)) != -1) break;
				break;
			case	0x9 :
				/* GridIcon */
				if ((_Context->keycode = on_GridIcon_getfocus(_Context)) != -1) break;
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
			_Context->focus_item=9;
			visual_3d_cursor_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=visual_3d_cursor_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Xadjust */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(4,235,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(4,235,50,16,vfh[8],27,28,_Context->msg_Xadjust[_Context->language],strlen(_Context->msg_Xadjust[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Xadjust_event(_Context)) != -1) break;

							}
						continue;
					case	0x2 :
						/* Yadjust */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(4,275,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(4,275,50,16,vfh[8],27,28,_Context->msg_Yadjust[_Context->language],strlen(_Context->msg_Yadjust[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Yadjust_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Zadjust */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(4,315,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(4,315,50,16,vfh[8],27,28,_Context->msg_Zadjust[_Context->language],strlen(_Context->msg_Zadjust[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Zadjust_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* MoveLeft */
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_MoveLeft_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* MoveRight */
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_MoveRight_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* MoveUp */
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_MoveUp_event(_Context)) != -1) break;

							}
						continue;
					case	0x7 :
						/* MoveInOut */
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_MoveInOut_event(_Context)) != -1) break;

							}
						continue;
					case	0x8 :
						/* MoveDown */
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_MoveDown_event(_Context)) != -1) break;

							}
						continue;
					case	0x9 :
						/* GridIcon */
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_GridIcon_event(_Context)) != -1) break;

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
				_Context->focus_item=9;
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
