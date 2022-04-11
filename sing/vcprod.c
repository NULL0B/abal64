
#ifndef _vcprod_c
#define _vcprod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vcprod.sng  */
/* Target         : vcprod.c  */
/* Identification : 0.0-1065019324-3876.3875 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_c_production_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_FileName[71];
	char	buffer_auto53[71];
	int	value_IsProgram;
	int	value_IsOverlay;
	char	buffer_Inclusions[211];
	int	value_Dimensions;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[7];
	} * _Context;

private	int	accept_c_production_create(
	char * pFileName,
	char * pauto53,
	char * pIsProgram,
	char * pIsOverlay,
	char * pInclusions,
	char * pDimensions)
{

	if (!(_Context = allocate( sizeof( struct accept_c_production_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=15;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 70, pFileName);
		visual_transferin(_Context->buffer_auto53, 70, pauto53);
		visual_transferin((void *) 0, 0, pIsProgram);
		if (!( pIsProgram )) _Context->value_IsProgram=0;
		else	_Context->value_IsProgram = *((int *)pIsProgram);
		visual_transferin((void *) 0, 0, pIsOverlay);
		if (!( pIsOverlay )) _Context->value_IsOverlay=0;
		else	_Context->value_IsOverlay = *((int *)pIsOverlay);
		visual_transferin(_Context->buffer_Inclusions, 210, pInclusions);
		visual_transferin((void *) 0, 0, pDimensions);
		if (!( pDimensions )) _Context->value_Dimensions=0;
		else	_Context->value_Dimensions = *((int *)pDimensions);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(100,140,600+10,320+10);
	return(0);
}

private	int	accept_c_production_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,100,140);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_c_production_remove(
	char * pFileName,
	char * pauto53,
	char * pIsProgram,
	char * pIsOverlay,
	char * pInclusions,
	char * pDimensions)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 70, pFileName);
		visual_transferout(_Context->buffer_auto53, 70, pauto53);
		visual_transferout((void *) 0, 0, pIsProgram);
		if ( pIsProgram != (char *) 0)
			*((int*)pIsProgram) = _Context->value_IsProgram;
		visual_transferout((void *) 0, 0, pIsOverlay);
		if ( pIsOverlay != (char *) 0)
			*((int*)pIsOverlay) = _Context->value_IsOverlay;
		visual_transferout(_Context->buffer_Inclusions, 210, pInclusions);
		visual_transferout((void *) 0, 0, pDimensions);
		if ( pDimensions != (char *) 0)
			*((int*)pDimensions) = _Context->value_Dimensions;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_c_production_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,100,140);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(100,140,600,320,2,"Sing : Version 1.0a",19,0x403);
	visual_image(103,162,592,294,"skin.gif",4);
	visual_frame(121,366,560,25,2);
	visual_text(120,180,560,16,2,27,0,"C Production Filename",21,258);
	visual_frame(120,200,560+2,16+2,5);
	visual_text(120+1,200+1,560,16,1,34,0,_Context->buffer_FileName,70,0);
	visual_text(120,230,560,16,2,27,0,"Identifier",10,258);
	visual_frame(120,250,560+2,16+2,5);
	visual_text(120+1,250+1,560,16,1,34,0,_Context->buffer_auto53,70,0);
	visual_check(140,370,180,20,2,34,0,"&Program with Main",18,_Context->value_IsProgram|0);
	visual_check(340,370,182,16,2,16,0,"&Visual Interface",17,_Context->value_IsOverlay|0);
	visual_button(120,410,110,30,2,34,0,"&Accept",7,0);
	visual_button(570,410,110,30,2,34,0,"&Cancel",7,0);
	visual_text(120,280,560,16,2,27,0,"Inclusions",10,258);
	visual_frame(120,300,560+2,60+2,5);
	visual_text(120+1,300+1,560,60,1,26,0,_Context->buffer_Inclusions,210,0);
	visual_select(530,370,144,80,1,0,0,parse_selection("320x200|640x400|640x480|800x600|1024x786|1280x1024",&_Context->value_Dimensions),0);
	visual_button(240,410,110,30,2,26,0,"&Edit",5,0);
	visual_button(460,410,100,30,2,27,24,"&Select",7,0);
	visual_image(380,395,50,50,"cicon.gif",0);
	visual_thaw(100,140,600,320);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}
private int on_Edit_event() {
	accept_c_production_hide();
	use_editor(_Context->buffer_FileName);
	accept_c_production_show();
	return(-1);
}
private int on_Select_event() {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_C);
	accept_c_production_show();
	return(-1);
}


private	int	accept_c_production_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 679 )  
	&&  (my >= 144 )  
	&&  (mx <= 695 )  
	&&  (my <= 160 )) {
		return(1);	/* auto2 */

		}
	if ((mx >= 663 )  
	&&  (my >= 144 )  
	&&  (mx <= 679 )  
	&&  (my <= 160 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcprod.htm");
			};
		return(-1);	/* auto2 */

		}
	if (( mx >= 120 ) 
	&&  ( my >= 200 ) 
	&&  ( mx <= 680 ) 
	&&  ( my <= 216 )) {
		return(3); /* FileName */
		}
	if (( mx >= 120 ) 
	&&  ( my >= 250 ) 
	&&  ( mx <= 680 ) 
	&&  ( my <= 266 )) {
		return(5); /* auto53 */
		}
	if (( mx >= 140 ) 
	&&  ( my >= 370 ) 
	&&  ( mx <= 320 ) 
	&&  ( my <= 390 )) {
		return(6); /* IsProgram */
		}
	if (( mx >= 340 ) 
	&&  ( my >= 370 ) 
	&&  ( mx <= 522 ) 
	&&  ( my <= 386 )) {
		return(7); /* IsOverlay */
		}
	if (( mx >= 120 ) 
	&&  ( my >= 410 ) 
	&&  ( mx <= 230 ) 
	&&  ( my <= 440 )) {
		return(8); /* Accept */
		}
	if (( mx >= 570 ) 
	&&  ( my >= 410 ) 
	&&  ( mx <= 680 ) 
	&&  ( my <= 440 )) {
		return(9); /* Cancel */
		}
	if (( mx >= 120 ) 
	&&  ( my >= 300 ) 
	&&  ( mx <= 680 ) 
	&&  ( my <= 360 )) {
		return(11); /* Inclusions */
		}
	if ((mx >= 530 ) 
	&&  (my >= 370 ) 
	&&  (mx <= 674 ) 
	&&  (my <= 386 )) {
		return(12); /* Dimensions */
		}
	if (( mx >= 240 ) 
	&&  ( my >= 410 ) 
	&&  ( mx <= 350 ) 
	&&  ( my <= 440 )) {
		return(13); /* Edit */
		}
	if (( mx >= 460 ) 
	&&  ( my >= 410 ) 
	&&  ( mx <= 560 ) 
	&&  ( my <= 440 )) {
		return(14); /* Select */
		}
	if (( mx >= 380 ) 
	&&  ( my >= 395 ) 
	&&  ( mx <= 430 ) 
	&&  ( my <= 445 )) {
		return(15); /* auto724 */
		}

	return(-1);
}


private	int	accept_c_production_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x3 :
				/* FileName */
				_Context->keycode = visual_edit(120+1,200+1,560,16,1,_Context->buffer_FileName,70);
				break;
			case	0x5 :
				/* auto53 */
				_Context->keycode = visual_edit(120+1,250+1,560,16,1,_Context->buffer_auto53,70);
				break;
			case	0x6 :
				/* IsProgram */
				visual_check(140,370,180,20,2,34,0,"&Program with Main",18,(_Context->value_IsProgram |2));
				_Context->keycode = visual_getch();
				visual_check(140,370,180,20,2,34,0,"&Program with Main",18,(_Context->value_IsProgram |0));
				break;
			case	0x7 :
				/* IsOverlay */
				visual_check(340,370,182,16,2,16,0,"&Visual Interface",17,(_Context->value_IsOverlay |2));
				_Context->keycode = visual_getch();
				visual_check(340,370,182,16,2,16,0,"&Visual Interface",17,(_Context->value_IsOverlay |0));
				break;
			case	0x8 :
				/* Accept */
				visual_button(120,410,110,30,2,34,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(120,410,110,30,2,34,0,"&Accept",7,0);
				break;
			case	0x9 :
				/* Cancel */
				visual_button(570,410,110,30,2,34,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(570,410,110,30,2,34,0,"&Cancel",7,0);
				break;
			case	0xb :
				/* Inclusions */
				_Context->keycode = visual_edit(120+1,300+1,560,60,1,_Context->buffer_Inclusions,210);
				break;
			case	0xc :
				/* Dimensions */
				_Context->keycode = visual_select(530,370,144,80,1,0,0,parse_selection("320x200|640x400|640x480|800x600|1024x786|1280x1024",&_Context->value_Dimensions),2);
				break;
			case	0xd :
				/* Edit */
				visual_button(240,410,110,30,2,26,0,"&Edit",5,2);
				_Context->keycode = visual_getch();
				visual_button(240,410,110,30,2,26,0,"&Edit",5,0);
				break;
			case	0xe :
				/* Select */
				visual_button(460,410,100,30,2,27,24,"&Select",7,2);
				_Context->keycode = visual_getch();
				visual_button(460,410,100,30,2,27,24,"&Select",7,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_c_production_show();
			continue;
		case	0x2 :
			_Context->focus_item=15;
			accept_c_production_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_c_production_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto2 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x3 :
						/* FileName */
						continue;
					case	0x5 :
						/* auto53 */
						continue;
					case	0x6 :
						/* IsProgram */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsProgram += 1;
							_Context->value_IsProgram &= 1;
							}
						continue;
					case	0x7 :
						/* IsOverlay */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsOverlay += 1;
							_Context->value_IsOverlay &= 1;
							}
						continue;
					case	0x8 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(120,410,110,30,2,34,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(120,410,110,30,2,34,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x9 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(570,410,110,30,2,34,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(570,410,110,30,2,34,0,"&Cancel",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0xb :
						/* Inclusions */
						continue;
					case	0xc :
						/* Dimensions */
						continue;
					case	0xd :
						/* Edit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(240,410,110,30,2,26,0,"&Edit",5,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(240,410,110,30,2,26,0,"&Edit",5,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Edit_event()) != -1) break;

							}
						continue;
					case	0xe :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(460,410,100,30,2,27,24,"&Select",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(460,410,100,30,2,27,24,"&Select",7,0);
							}
						if ( visual_event(1) &  0x2020 ) {
						if ((_Context->keycode = on_Select_event()) != -1) break;

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
				_Context->focus_item=15;
			}
			continue;
		case 0x850 : 
		case 0x870 : 
		/* IsProgram */
		_Context->value_IsProgram += 1;
		_Context->value_IsProgram &= 1;
		_Context->focus_item=6;
		continue;
		case 0x856 : 
		case 0x876 : 
		/* IsOverlay */
		_Context->value_IsOverlay += 1;
		_Context->value_IsOverlay &= 1;
		_Context->focus_item=7;
		continue;
		case 0x841 : 
		case 0x861 : 
		/* Accept */
		visual_button(120,410,110,30,2,34,0,"&Accept",7,8);
		visual_button(120,410,110,30,2,34,0,"&Accept",7,0);
		_Context->focus_item=8;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(570,410,110,30,2,34,0,"&Cancel",7,8);
		visual_button(570,410,110,30,2,34,0,"&Cancel",7,0);
		_Context->focus_item=9;
		if ((_Context->keycode = on_Cancel_event()) != -1) break;
		continue;
		case 0x845 : 
		case 0x865 : 
		/* Edit */
		visual_button(240,410,110,30,2,26,0,"&Edit",5,8);
		visual_button(240,410,110,30,2,26,0,"&Edit",5,0);
		_Context->focus_item=13;
		if ((_Context->keycode = on_Edit_event()) != -1) break;
		continue;
		case 0x853 : 
		case 0x873 : 
		/* Select */
		visual_button(460,410,100,30,2,27,24,"&Select",7,8);
		visual_button(460,410,100,30,2,27,24,"&Select",7,0);
		_Context->focus_item=14;
		if ((_Context->keycode = on_Select_event()) != -1) break;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_c_production(
	char * pFileName,
	char * pauto53,
	char * pIsProgram,
	char * pIsOverlay,
	char * pInclusions,
	char * pDimensions)
{
	int	status=0;
	status = accept_c_production_create(
	 pFileName,
	 pauto53,
	 pIsProgram,
	 pIsOverlay,
	 pInclusions,
	 pDimensions);
	if ( status != 0) return(status);
	status = accept_c_production_show();
		enter_modal();
	status = accept_c_production_focus();
		leave_modal();
	status = accept_c_production_hide();
	status = accept_c_production_remove(
	 pFileName,
	 pauto53,
	 pIsProgram,
	 pIsOverlay,
	 pInclusions,
	 pDimensions);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcprod_c */
