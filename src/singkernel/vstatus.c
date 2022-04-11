
#ifndef _vstatus_c
#define _vstatus_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vstatus.xml  */
/* Target         : vstatus.c  */
/* Identification : 0.0-1100085454-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Frame   ""
#define en_Tray   ""
#define en_ZoneOne   ""
#define en_ZoneThree   ""
#define en_ZoneTwo   ""
static int	vfh[10];

private struct visual_status_bar_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	x_Frame;
	int	y_Frame;
	int	w_Frame;
	int	h_Frame;
	int	fg_Frame;
	int	bg_Frame;
	int	fid_Frame;
	int	x_Tray;
	int	y_Tray;
	int	w_Tray;
	int	h_Tray;
	int	fg_Tray;
	int	bg_Tray;
	int	fid_Tray;
	int	x_ZoneOne;
	int	y_ZoneOne;
	int	w_ZoneOne;
	int	h_ZoneOne;
	int	fg_ZoneOne;
	int	bg_ZoneOne;
	int	fid_ZoneOne;
	char	buffer_ZoneOne[32];
	int	x_ZoneThree;
	int	y_ZoneThree;
	int	w_ZoneThree;
	int	h_ZoneThree;
	int	fg_ZoneThree;
	int	bg_ZoneThree;
	int	fid_ZoneThree;
	char	buffer_ZoneThree[32];
	int	x_ZoneTwo;
	int	y_ZoneTwo;
	int	w_ZoneTwo;
	int	h_ZoneTwo;
	int	fg_ZoneTwo;
	int	bg_ZoneTwo;
	int	fid_ZoneTwo;
	char	buffer_ZoneTwo[32];
	char	signature[1];
	};
void	status_bar_message(struct visual_status_bar_context * _Context,int item, char * mptr);

/*	--------------------------------------	*/
/*	s t a t u s _ b a r _ m e s s a g e ()	*/
/*	--------------------------------------	*/
void	status_bar_message(struct visual_status_bar_context * _Context,int item, char * mptr){
	int i=0;
	switch(item){
	case 1:
	for(i=0;i<31;i++){
	if(!(*mptr))
	break;
	else{
	*(_Context->buffer_ZoneOne+i)=*(mptr++);
	}
	}
	for(;i<31;i++)
	*(_Context->buffer_ZoneOne+i)=' ';
	break;
	case 2:
	for(i=0;i<31;i++){
	if(!(*mptr))
	break;
	else{
	*(_Context->buffer_ZoneTwo+i)=*(mptr++);
	}
	}
	for(;i<31;i++)
	*(_Context->buffer_ZoneTwo+i)=' ';
	break;
	case 3:
	for(i=0;i<31;i++){
	if(!(*mptr))
	break;
	else{
	*(_Context->buffer_ZoneThree+i)=*(mptr++);
	}
	}
	for(;i<31;i++)
	*(_Context->buffer_ZoneThree+i)=' ';
	break;
		}
		visual_status_bar_show(_Context);
;

}

public	int	visual_status_bar_create(struct visual_status_bar_context **cptr)
{

	int i;
	struct visual_status_bar_context * _Context=(struct visual_status_bar_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct visual_status_bar_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=0;
	_Context->x_Frame=170;
	_Context->y_Frame=90;
	_Context->w_Frame=790;
	_Context->h_Frame=30;
	_Context->fg_Frame=30;
	_Context->bg_Frame=30;
	_Context->fid_Frame=1;
	_Context->x_Tray=171;
	_Context->y_Tray=91;
	_Context->w_Tray=788;
	_Context->h_Tray=28;
	_Context->fg_Tray=28;
	_Context->bg_Tray=28;
	_Context->fid_Tray=1;
	_Context->x_ZoneOne=178;
	_Context->y_ZoneOne=97;
	_Context->w_ZoneOne=252;
	_Context->h_ZoneOne=16;
	_Context->fg_ZoneOne=16;
	_Context->bg_ZoneOne=16;
	_Context->fid_ZoneOne=1;
	_Context->x_ZoneThree=698;
	_Context->y_ZoneThree=97;
	_Context->w_ZoneThree=252;
	_Context->h_ZoneThree=16;
	_Context->fg_ZoneThree=16;
	_Context->bg_ZoneThree=16;
	_Context->fid_ZoneThree=1;
	_Context->x_ZoneTwo=438;
	_Context->y_ZoneTwo=97;
	_Context->w_ZoneTwo=252;
	_Context->h_ZoneTwo=16;
	_Context->fg_ZoneTwo=16;
	_Context->bg_ZoneTwo=16;
	_Context->fid_ZoneTwo=1;
	return(0);
}

public 	int	visual_status_bar_hide(struct visual_status_bar_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	visual_status_bar_remove(struct visual_status_bar_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

public	int	visual_status_bar_show(struct visual_status_bar_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	{
	int aty;
	int ow;
	int oh;
	_Context->x_Frame=170;_Context->y_Frame=90;_Context->w_Frame=790;_Context->h_Frame=30;;
	ow=_Context->w_Frame;
	_Context->w_Frame=(inner_width(2)+1);
	oh=_Context->y_Frame;
	aty=x_conf(68);
	if((_Context->x_Frame=inner_left())>0)
	_Context->x_Frame++;
	_Context->y_Frame=(aty-(_Context->h_Frame+2));
	_Context->h_Frame+=1;
	_Context->x_ZoneOne=178;_Context->y_ZoneOne=97;_Context->w_ZoneOne=252;_Context->h_ZoneOne=16;;
	_Context->x_ZoneTwo=438;_Context->y_ZoneTwo=97;_Context->w_ZoneTwo=252;_Context->h_ZoneTwo=16;;
	_Context->x_ZoneThree=698;_Context->y_ZoneThree=97;_Context->w_ZoneThree=252;_Context->h_ZoneThree=16;;
	_Context->y_ZoneOne=((_Context->y_ZoneOne-oh)+_Context->y_Frame)+1;
	_Context->y_ZoneTwo=((_Context->y_ZoneTwo-oh)+_Context->y_Frame)+1;
	_Context->y_ZoneThree=((_Context->y_ZoneThree-oh)+_Context->y_Frame)+1;
	_Context->w_ZoneOne=_Context->w_ZoneTwo=_Context->w_ZoneThree=((_Context->w_Frame-40)/3);
	_Context->x_ZoneOne=(_Context->x_Frame+10);
	_Context->x_ZoneTwo=(_Context->x_ZoneOne+_Context->w_ZoneOne+10);
	_Context->x_ZoneThree=(_Context->x_ZoneTwo+_Context->w_ZoneTwo+10);
	_Context->x_Tray=_Context->x_Frame+1;_Context->y_Tray=_Context->y_Frame+1;
	_Context->w_Tray=_Context->w_Frame-2;
	_Context->h_Tray=_Context->h_Frame-2;
		visual_frame(_Context->x_Frame,_Context->y_Frame,_Context->w_Frame,_Context->h_Frame,1);
;
	}
		visual_filzone(_Context->x_Tray,_Context->y_Tray,_Context->w_Tray,_Context->h_Tray,0,6);
	visual_frame(_Context->x_ZoneOne,_Context->y_ZoneOne,_Context->w_ZoneOne+2,_Context->h_ZoneOne+2,5);
	visual_text(_Context->x_ZoneOne+1,_Context->y_ZoneOne+1,_Context->w_ZoneOne,_Context->h_ZoneOne,_Context->fid_ZoneOne,27,0,_Context->buffer_ZoneOne,31,3);
	visual_frame(_Context->x_ZoneThree,_Context->y_ZoneThree,_Context->w_ZoneThree+2,_Context->h_ZoneThree+2,5);
	visual_text(_Context->x_ZoneThree+1,_Context->y_ZoneThree+1,_Context->w_ZoneThree,_Context->h_ZoneThree,_Context->fid_ZoneThree,27,0,_Context->buffer_ZoneThree,31,3);
	visual_frame(_Context->x_ZoneTwo,_Context->y_ZoneTwo,_Context->w_ZoneTwo+2,_Context->h_ZoneTwo+2,5);
	visual_text(_Context->x_ZoneTwo+1,_Context->y_ZoneTwo+1,_Context->w_ZoneTwo,_Context->h_ZoneTwo,_Context->fid_ZoneTwo,27,0,_Context->buffer_ZoneTwo,31,3);
	visual_thaw(0,0,790,30);

	return(0);
}


public	int	visual_status_bar_event(
struct visual_status_bar_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);

	return(-1);
}


public	int	visual_status_bar_focus(struct visual_status_bar_context * _Context)
{
	int retcode=0;
	_Context->keycode=13;


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	visual_status_bar()
{
	int	status=0;
	struct visual_status_bar_context * _Context=(struct visual_status_bar_context*) 0;
	status = visual_status_bar_create(&_Context);
	if ( status != 0) return(status);
	status = visual_status_bar_show(_Context);
	status = visual_status_bar_focus(_Context);
	status = visual_status_bar_hide(_Context);
	status = visual_status_bar_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vstatus_c */
