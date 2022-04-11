
#ifndef _nodemenu_c
#define _nodemenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : nodemenu.xml                                             */
/* Target         : nodemenu.c                                               */
/* Identification : 0.0-1354230068-717.716                                   */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "nodemenu.h"
static int	vfh[16];
private int on_Auto58_event(struct use_node_menu_context * _Context);
private int on_Auto59_event(struct use_node_menu_context * _Context);
private int on_Auto60_event(struct use_node_menu_context * _Context);
private int on_Auto61_event(struct use_node_menu_context * _Context);

public	int	use_node_menu_attach()
{
	if ( visual_initialise(3|512) == -1 )
		return(56);

	else	{
		visual_palette("/home/abal3/images/standard.rgb",31);
		cicopalette(0,0);
		vfh[1] = visual_font("standard.fmf",12);
		vfh[2] = visual_font("arial2.fmf",10);
		vfh[3] = visual_font("arial3.fmf",10);
		vfh[4] = visual_font("arial4.fmf",10);
		vfh[5] = visual_font("arial5.fmf",10);
		vfh[6] = visual_font("arial6.fmf",10);
		vfh[7] = visual_font("font7.fmf",9);
		vfh[8] = visual_font("font8.fmf",9);
		vfh[9] = visual_font("font9.fmf",9);
		vfh[10] = visual_font("bmap0416.fmf",12);
		initialise_mouse();
		}
	return(0);
}

public	int	use_node_menu_attach_mode(int mode)
{
	if ( visual_initialise(3|mode) == -1 )
		return(56);

	else	{
		visual_palette("/home/abal3/images/standard.rgb",31);
		cicopalette(0,0);
		vfh[1] = visual_font("standard.fmf",12);
		vfh[2] = visual_font("arial2.fmf",10);
		vfh[3] = visual_font("arial3.fmf",10);
		vfh[4] = visual_font("arial4.fmf",10);
		vfh[5] = visual_font("arial5.fmf",10);
		vfh[6] = visual_font("arial6.fmf",10);
		vfh[7] = visual_font("font7.fmf",9);
		vfh[8] = visual_font("font8.fmf",9);
		vfh[9] = visual_font("font9.fmf",9);
		vfh[10] = visual_font("bmap0416.fmf",12);
		initialise_mouse();
		}
	return(0);
}

public	int	use_node_menu_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	use_node_menu_create(struct use_node_menu_context **cptr)
{

	int i;
	struct use_node_menu_context * _Context=(struct use_node_menu_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("bmap0416.fmf",12);
	if (!(_Context = allocate( sizeof( struct use_node_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=5;
	_Context->x_Auto56=310;
	_Context->y_Auto56=215;
	_Context->w_Auto56=180;
	_Context->h_Auto56=170;
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto56,_Context->y_Auto56,180,170);
	return(0);
}

public 	int	use_node_menu_hide(struct use_node_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto56,_Context->y_Auto56);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	use_node_menu_remove(struct use_node_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	use_node_menu_show(struct use_node_menu_context * _Context)
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto56,_Context->y_Auto56);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto56,_Context->y_Auto56,180,170,vfh[2],"Node Menu",strlen("Node Menu"),0x0);
	visual_frame(_Context->x_Auto56+6,_Context->y_Auto56+26,168,130,2);
	visual_button(_Context->x_Auto56+10,_Context->y_Auto56+30,160,32,vfh[2],27,28,"Add Before Current",strlen("Add Before Current"),0);
	visual_button(_Context->x_Auto56+10,_Context->y_Auto56+60,160,32,vfh[2],27,28,"Add After Current",strlen("Add After Current"),0);
	visual_button(_Context->x_Auto56+10,_Context->y_Auto56+90,160,32,vfh[2],27,28,"Delete Current Node",strlen("Delete Current Node"),0);
	visual_button(_Context->x_Auto56+10,_Context->y_Auto56+120,160,32,vfh[2],27,28,"Node Properties",strlen("Node Properties"),0);
	visual_thaw(_Context->x_Auto56,_Context->y_Auto56,180,170);

	return(0);
}
private int on_Auto58_event(struct use_node_menu_context * _Context) {
	return(2);
	return(-1);
}
private int on_Auto59_event(struct use_node_menu_context * _Context) {
	return(1);
	return(-1);
}
private int on_Auto60_event(struct use_node_menu_context * _Context) {
	return(127);
	return(-1);
}
private int on_Auto61_event(struct use_node_menu_context * _Context) {
	return(9);
	return(-1);
}


public	int	use_node_menu_event(
struct use_node_menu_context * _Context){
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto56+10) ) 
	&&  ( my >= (_Context->y_Auto56+30) ) 
	&&  ( mx <= (_Context->x_Auto56+10+160) ) 
	&&  ( my <= (_Context->y_Auto56+30+32))) {
		return(2); /* Auto58 */
		}
	if (( mx >= (_Context->x_Auto56+10) ) 
	&&  ( my >= (_Context->y_Auto56+60) ) 
	&&  ( mx <= (_Context->x_Auto56+10+160) ) 
	&&  ( my <= (_Context->y_Auto56+60+32))) {
		return(3); /* Auto59 */
		}
	if (( mx >= (_Context->x_Auto56+10) ) 
	&&  ( my >= (_Context->y_Auto56+90) ) 
	&&  ( mx <= (_Context->x_Auto56+10+160) ) 
	&&  ( my <= (_Context->y_Auto56+90+32))) {
		return(4); /* Auto60 */
		}
	if (( mx >= (_Context->x_Auto56+10) ) 
	&&  ( my >= (_Context->y_Auto56+120) ) 
	&&  ( mx <= (_Context->x_Auto56+10+160) ) 
	&&  ( my <= (_Context->y_Auto56+120+32))) {
		return(5); /* Auto61 */
		}

	return(-1);
}


public	int	use_node_menu_focus(struct use_node_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto58 */
				visual_button(_Context->x_Auto56+10,_Context->y_Auto56+30,160,32,vfh[2],27,28,"Add Before Current",strlen("Add Before Current"),2);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto56+10,_Context->y_Auto56+30,160,32,vfh[2],27,28,"Add Before Current",strlen("Add Before Current"),0);
				break;
			case	0x3 :
				/* Auto59 */
				visual_button(_Context->x_Auto56+10,_Context->y_Auto56+60,160,32,vfh[2],27,28,"Add After Current",strlen("Add After Current"),2);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto56+10,_Context->y_Auto56+60,160,32,vfh[2],27,28,"Add After Current",strlen("Add After Current"),0);
				break;
			case	0x4 :
				/* Auto60 */
				visual_button(_Context->x_Auto56+10,_Context->y_Auto56+90,160,32,vfh[2],27,28,"Delete Current Node",strlen("Delete Current Node"),2);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto56+10,_Context->y_Auto56+90,160,32,vfh[2],27,28,"Delete Current Node",strlen("Delete Current Node"),0);
				break;
			case	0x5 :
				/* Auto61 */
				visual_button(_Context->x_Auto56+10,_Context->y_Auto56+120,160,32,vfh[2],27,28,"Node Properties",strlen("Node Properties"),2);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto56+10,_Context->y_Auto56+120,160,32,vfh[2],27,28,"Node Properties",strlen("Node Properties"),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			use_node_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=5;
			use_node_menu_show(_Context);
			continue;
		case	0x100 :
			if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
			if ((retcode=use_node_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto56 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto58 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto56+10,_Context->y_Auto56+30,160,32,vfh[2],27,28,"Add Before Current",strlen("Add Before Current"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto56+10,_Context->y_Auto56+30,160,32,vfh[2],27,28,"Add Before Current",strlen("Add Before Current"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto58_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto59 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto56+10,_Context->y_Auto56+60,160,32,vfh[2],27,28,"Add After Current",strlen("Add After Current"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto56+10,_Context->y_Auto56+60,160,32,vfh[2],27,28,"Add After Current",strlen("Add After Current"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto59_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto60 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto56+10,_Context->y_Auto56+90,160,32,vfh[2],27,28,"Delete Current Node",strlen("Delete Current Node"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto56+10,_Context->y_Auto56+90,160,32,vfh[2],27,28,"Delete Current Node",strlen("Delete Current Node"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto60_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto61 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto56+10,_Context->y_Auto56+120,160,32,vfh[2],27,28,"Node Properties",strlen("Node Properties"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto56+10,_Context->y_Auto56+120,160,32,vfh[2],27,28,"Node Properties",strlen("Node Properties"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto61_event(_Context)) != -1) break;

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
				_Context->focus_item=5;
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

public	int	use_node_menu()
{
	int	status=0;
	struct use_node_menu_context * _Context=(struct use_node_menu_context*) 0;
	status = use_node_menu_create(&_Context);
	if ( status != 0) return(status);
	status = use_node_menu_show(_Context);
		enter_modal();
	status = use_node_menu_focus(_Context);
		leave_modal();
	status = use_node_menu_hide(_Context);
	status = use_node_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _nodemenu_c */
