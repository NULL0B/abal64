
#ifndef _manmenu_c
#define _manmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : manmenu.xml                                              */
/* Target         : manmenu.c                                                */
/* Identification : 0.0-1354230110-717.716                                   */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "manmenu.h"
static int	vfh[16];
private int on_Auto64_event(struct use_manifest_menu_context * _Context);
private int on_Auto65_event(struct use_manifest_menu_context * _Context);
private int on_Auto66_event(struct use_manifest_menu_context * _Context);
private int on_Auto67_event(struct use_manifest_menu_context * _Context);
private int on_Auto68_event(struct use_manifest_menu_context * _Context);
private int on_Auto69_event(struct use_manifest_menu_context * _Context);

public	int	use_manifest_menu_attach()
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

public	int	use_manifest_menu_attach_mode(int mode)
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

public	int	use_manifest_menu_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	use_manifest_menu_create(struct use_manifest_menu_context **cptr)
{

	int i;
	struct use_manifest_menu_context * _Context=(struct use_manifest_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct use_manifest_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=7;
	_Context->x_Auto62=310;
	_Context->y_Auto62=185;
	_Context->w_Auto62=180;
	_Context->h_Auto62=230;
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto62,_Context->y_Auto62,180,230);
	return(0);
}

public 	int	use_manifest_menu_hide(struct use_manifest_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto62,_Context->y_Auto62);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	use_manifest_menu_remove(struct use_manifest_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	use_manifest_menu_show(struct use_manifest_menu_context * _Context)
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto62,_Context->y_Auto62);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto62,_Context->y_Auto62,180,230,vfh[2],"Manifest Menu",strlen("Manifest Menu"),0x0);
	visual_frame(_Context->x_Auto62+6,_Context->y_Auto62+26,168,190,2);
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+30,160,32,vfh[2],27,28,"Add Node",strlen("Add Node"),0);
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+60,160,32,vfh[2],27,28,"Generate Manifest",strlen("Generate Manifest"),0);
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+90,160,32,vfh[2],27,28,"Load Manifest",strlen("Load Manifest"),0);
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+120,160,32,vfh[2],27,28,"Manifest Properties",strlen("Manifest Properties"),0);
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+150,160,32,vfh[2],27,28,"Save Configuration",strlen("Save Configuration"),0);
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+180,160,32,vfh[2],27,28,"Load Configuration",strlen("Load Configuration"),0);
	visual_thaw(_Context->x_Auto62,_Context->y_Auto62,180,230);

	return(0);
}
private int on_Auto64_event(struct use_manifest_menu_context * _Context) {
	return(1);
	return(-1);
}
private int on_Auto65_event(struct use_manifest_menu_context * _Context) {
	return(16);
	return(-1);
}
private int on_Auto66_event(struct use_manifest_menu_context * _Context) {
	return(17);
	return(-1);
}
private int on_Auto67_event(struct use_manifest_menu_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto68_event(struct use_manifest_menu_context * _Context) {
	return(24);
	return(-1);
}
private int on_Auto69_event(struct use_manifest_menu_context * _Context) {
	return(25);
	return(-1);
}


public	int	use_manifest_menu_event(
struct use_manifest_menu_context * _Context){
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto62+10) ) 
	&&  ( my >= (_Context->y_Auto62+30) ) 
	&&  ( mx <= (_Context->x_Auto62+10+160) ) 
	&&  ( my <= (_Context->y_Auto62+30+32))) {
		return(2); /* Auto64 */
		}
	if (( mx >= (_Context->x_Auto62+10) ) 
	&&  ( my >= (_Context->y_Auto62+60) ) 
	&&  ( mx <= (_Context->x_Auto62+10+160) ) 
	&&  ( my <= (_Context->y_Auto62+60+32))) {
		return(3); /* Auto65 */
		}
	if (( mx >= (_Context->x_Auto62+10) ) 
	&&  ( my >= (_Context->y_Auto62+90) ) 
	&&  ( mx <= (_Context->x_Auto62+10+160) ) 
	&&  ( my <= (_Context->y_Auto62+90+32))) {
		return(4); /* Auto66 */
		}
	if (( mx >= (_Context->x_Auto62+10) ) 
	&&  ( my >= (_Context->y_Auto62+120) ) 
	&&  ( mx <= (_Context->x_Auto62+10+160) ) 
	&&  ( my <= (_Context->y_Auto62+120+32))) {
		return(5); /* Auto67 */
		}
	if (( mx >= (_Context->x_Auto62+10) ) 
	&&  ( my >= (_Context->y_Auto62+150) ) 
	&&  ( mx <= (_Context->x_Auto62+10+160) ) 
	&&  ( my <= (_Context->y_Auto62+150+32))) {
		return(6); /* Auto68 */
		}
	if (( mx >= (_Context->x_Auto62+10) ) 
	&&  ( my >= (_Context->y_Auto62+180) ) 
	&&  ( mx <= (_Context->x_Auto62+10+160) ) 
	&&  ( my <= (_Context->y_Auto62+180+32))) {
		return(7); /* Auto69 */
		}

	return(-1);
}


public	int	use_manifest_menu_focus(struct use_manifest_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto64 */
				visual_button(_Context->x_Auto62+10,_Context->y_Auto62+30,160,32,vfh[2],27,28,"Add Node",strlen("Add Node"),2);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+30,160,32,vfh[2],27,28,"Add Node",strlen("Add Node"),0);
				break;
			case	0x3 :
				/* Auto65 */
				visual_button(_Context->x_Auto62+10,_Context->y_Auto62+60,160,32,vfh[2],27,28,"Generate Manifest",strlen("Generate Manifest"),2);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+60,160,32,vfh[2],27,28,"Generate Manifest",strlen("Generate Manifest"),0);
				break;
			case	0x4 :
				/* Auto66 */
				visual_button(_Context->x_Auto62+10,_Context->y_Auto62+90,160,32,vfh[2],27,28,"Load Manifest",strlen("Load Manifest"),2);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+90,160,32,vfh[2],27,28,"Load Manifest",strlen("Load Manifest"),0);
				break;
			case	0x5 :
				/* Auto67 */
				visual_button(_Context->x_Auto62+10,_Context->y_Auto62+120,160,32,vfh[2],27,28,"Manifest Properties",strlen("Manifest Properties"),2);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+120,160,32,vfh[2],27,28,"Manifest Properties",strlen("Manifest Properties"),0);
				break;
			case	0x6 :
				/* Auto68 */
				visual_button(_Context->x_Auto62+10,_Context->y_Auto62+150,160,32,vfh[2],27,28,"Save Configuration",strlen("Save Configuration"),2);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+150,160,32,vfh[2],27,28,"Save Configuration",strlen("Save Configuration"),0);
				break;
			case	0x7 :
				/* Auto69 */
				visual_button(_Context->x_Auto62+10,_Context->y_Auto62+180,160,32,vfh[2],27,28,"Load Configuration",strlen("Load Configuration"),2);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+180,160,32,vfh[2],27,28,"Load Configuration",strlen("Load Configuration"),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			use_manifest_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=7;
			use_manifest_menu_show(_Context);
			continue;
		case	0x100 :
			if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
			if ((retcode=use_manifest_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto62 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto64 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto62+10,_Context->y_Auto62+30,160,32,vfh[2],27,28,"Add Node",strlen("Add Node"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+30,160,32,vfh[2],27,28,"Add Node",strlen("Add Node"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto64_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto65 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto62+10,_Context->y_Auto62+60,160,32,vfh[2],27,28,"Generate Manifest",strlen("Generate Manifest"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+60,160,32,vfh[2],27,28,"Generate Manifest",strlen("Generate Manifest"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto65_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto66 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto62+10,_Context->y_Auto62+90,160,32,vfh[2],27,28,"Load Manifest",strlen("Load Manifest"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+90,160,32,vfh[2],27,28,"Load Manifest",strlen("Load Manifest"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto66_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto67 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto62+10,_Context->y_Auto62+120,160,32,vfh[2],27,28,"Manifest Properties",strlen("Manifest Properties"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+120,160,32,vfh[2],27,28,"Manifest Properties",strlen("Manifest Properties"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto67_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto68 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto62+10,_Context->y_Auto62+150,160,32,vfh[2],27,28,"Save Configuration",strlen("Save Configuration"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+150,160,32,vfh[2],27,28,"Save Configuration",strlen("Save Configuration"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto68_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto69 */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto62+10,_Context->y_Auto62+180,160,32,vfh[2],27,28,"Load Configuration",strlen("Load Configuration"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto62+10,_Context->y_Auto62+180,160,32,vfh[2],27,28,"Load Configuration",strlen("Load Configuration"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto69_event(_Context)) != -1) break;

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
				_Context->focus_item=7;
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

public	int	use_manifest_menu()
{
	int	status=0;
	struct use_manifest_menu_context * _Context=(struct use_manifest_menu_context*) 0;
	status = use_manifest_menu_create(&_Context);
	if ( status != 0) return(status);
	status = use_manifest_menu_show(_Context);
		enter_modal();
	status = use_manifest_menu_focus(_Context);
		leave_modal();
	status = use_manifest_menu_hide(_Context);
	status = use_manifest_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _manmenu_c */
