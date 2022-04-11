
#ifndef _vdata_c
#define _vdata_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vdata.sng  */
/* Target         : vdata.c  */
/* Identification : 0.0-1065019113-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_data_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_auto430[52];
	char	buffer_auto431[52];
	char	buffer_Size[12];
	char	buffer_First[52];
	char	buffer_Second[52];
	char	buffer_Initialise[256];
	int	value_Publique;
	int	value_Common;
	int	value_Pointer;
	char	signature[10];
	} * _Context;

private	int	accept_data_create(
	char * pauto430,
	char * pauto431,
	char * pSize,
	char * pFirst,
	char * pSecond,
	char * pInitialise,
	char * pPublique,
	char * pCommon,
	char * pPointer)
{

	if (!(_Context = allocate( sizeof( struct accept_data_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=12;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_auto430, 51, pauto430);
		visual_transferin(_Context->buffer_auto431, 51, pauto431);
		visual_transferin(_Context->buffer_Size, 11, pSize);
		visual_transferin(_Context->buffer_First, 51, pFirst);
		visual_transferin(_Context->buffer_Second, 51, pSecond);
		visual_transferin(_Context->buffer_Initialise, 255, pInitialise);
		visual_transferin((void *) 0, 0, pPublique);
		if (!( pPublique )) _Context->value_Publique=0;
		else	_Context->value_Publique = *((int *)pPublique);
		visual_transferin((void *) 0, 0, pCommon);
		if (!( pCommon )) _Context->value_Common=0;
		else	_Context->value_Common = *((int *)pCommon);
		visual_transferin((void *) 0, 0, pPointer);
		if (!( pPointer )) _Context->value_Pointer=0;
		else	_Context->value_Pointer = *((int *)pPointer);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	return(0);
}

private	int	accept_data_hide()
{

	return(0);
}

private	int	accept_data_remove(
	char * pauto430,
	char * pauto431,
	char * pSize,
	char * pFirst,
	char * pSecond,
	char * pInitialise,
	char * pPublique,
	char * pCommon,
	char * pPointer)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_auto430, 51, pauto430);
		visual_transferout(_Context->buffer_auto431, 51, pauto431);
		visual_transferout(_Context->buffer_Size, 11, pSize);
		visual_transferout(_Context->buffer_First, 51, pFirst);
		visual_transferout(_Context->buffer_Second, 51, pSecond);
		visual_transferout(_Context->buffer_Initialise, 255, pInitialise);
		visual_transferout((void *) 0, 0, pPublique);
		if ( pPublique != (char *) 0)
			*((int*)pPublique) = _Context->value_Publique;
		visual_transferout((void *) 0, 0, pCommon);
		if ( pCommon != (char *) 0)
			*((int*)pCommon) = _Context->value_Common;
		visual_transferout((void *) 0, 0, pPointer);
		if ( pPointer != (char *) 0)
			*((int*)pPointer) = _Context->value_Pointer;
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_data_show()
{
	visual_freeze();
	visual_window(120,150,560,300,2,"Sing : Version 1.0a",19,0x0);
	visual_frame(130,180,540,260,4);
	visual_text(140,190,518,16,2,26,0,"Data Member",11,0);
	visual_text(140,210,154,16,2,26,0,"Identity",8,0);
	visual_text(140,230,140,16,2,26,0,"Type/Class",10,0);
	visual_text(140,250,126,16,2,26,0,"Size",4,0);
	visual_text(140,270,140,16,2,26,0,"First",5,0);
	visual_text(140,290,154,16,2,26,0,"Second",6,0);
	visual_text(140,310,200,16,2,26,0,"Initialisation",14,0);
	visual_frame(250,210,408+2,16+2,5);
	visual_text(250+1,210+1,408,16,1,26,0,_Context->buffer_auto430,51,0);
	visual_frame(250,230,408+2,16+2,5);
	visual_text(250+1,230+1,408,16,1,26,0,_Context->buffer_auto431,51,0);
	visual_frame(250,250,88+2,16+2,5);
	visual_text(250+1,250+1,88,16,1,26,0,_Context->buffer_Size,11,0);
	visual_frame(250,270,408+2,16+2,5);
	visual_text(250+1,270+1,408,16,1,26,0,_Context->buffer_First,51,0);
	visual_frame(250,290,408+2,16+2,5);
	visual_text(250+1,290+1,408,16,1,26,0,_Context->buffer_Second,51,0);
	visual_frame(250,310,408+2,80+2,5);
	visual_text(250+1,310+1,408,80,1,26,0,_Context->buffer_Initialise,255,0);
	visual_button(140,400,100,32,2,26,0,"Accept",6,0);
	visual_button(560,400,100,32,2,26,0,"Cancel",6,0);
	visual_check(237,190,100,32,2,26,0,"Public",6,_Context->value_Publique|0);
	visual_check(350,190,100,32,2,26,0,"Common",6,_Context->value_Common|0);
	visual_check(450,190,100,32,2,26,0,"Pointer",7,_Context->value_Pointer|0);
	visual_thaw(120,150,560,300);

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


private	int	accept_data_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 250 ) 
	&&  ( my >= 210 ) 
	&&  ( mx <= 658 ) 
	&&  ( my <= 226 )) {
		return(2); /* auto430 */
		}
	if (( mx >= 250 ) 
	&&  ( my >= 230 ) 
	&&  ( mx <= 658 ) 
	&&  ( my <= 246 )) {
		return(3); /* auto431 */
		}
	if (( mx >= 250 ) 
	&&  ( my >= 250 ) 
	&&  ( mx <= 338 ) 
	&&  ( my <= 266 )) {
		return(4); /* Size */
		}
	if (( mx >= 250 ) 
	&&  ( my >= 270 ) 
	&&  ( mx <= 658 ) 
	&&  ( my <= 286 )) {
		return(5); /* First */
		}
	if (( mx >= 250 ) 
	&&  ( my >= 290 ) 
	&&  ( mx <= 658 ) 
	&&  ( my <= 306 )) {
		return(6); /* Second */
		}
	if (( mx >= 250 ) 
	&&  ( my >= 310 ) 
	&&  ( mx <= 658 ) 
	&&  ( my <= 390 )) {
		return(7); /* Initialise */
		}
	if (( mx >= 140 ) 
	&&  ( my >= 400 ) 
	&&  ( mx <= 240 ) 
	&&  ( my <= 432 )) {
		return(8); /* Accept */
		}
	if (( mx >= 560 ) 
	&&  ( my >= 400 ) 
	&&  ( mx <= 660 ) 
	&&  ( my <= 432 )) {
		return(9); /* Cancel */
		}
	if (( mx >= 237 ) 
	&&  ( my >= 190 ) 
	&&  ( mx <= 337 ) 
	&&  ( my <= 222 )) {
		return(10); /* Publique */
		}
	if (( mx >= 350 ) 
	&&  ( my >= 190 ) 
	&&  ( mx <= 450 ) 
	&&  ( my <= 222 )) {
		return(11); /* Common */
		}
	if (( mx >= 450 ) 
	&&  ( my >= 190 ) 
	&&  ( mx <= 550 ) 
	&&  ( my <= 222 )) {
		return(12); /* Pointer */
		}

	return(-1);
}


private	int	accept_data_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* auto430 */
				_Context->keycode = visual_edit(250+1,210+1,408,16,1,_Context->buffer_auto430,51);
				break;
			case	0x3 :
				/* auto431 */
				_Context->keycode = visual_edit(250+1,230+1,408,16,1,_Context->buffer_auto431,51);
				break;
			case	0x4 :
				/* Size */
				_Context->keycode = visual_edit(250+1,250+1,88,16,1,_Context->buffer_Size,11);
				break;
			case	0x5 :
				/* First */
				_Context->keycode = visual_edit(250+1,270+1,408,16,1,_Context->buffer_First,51);
				break;
			case	0x6 :
				/* Second */
				_Context->keycode = visual_edit(250+1,290+1,408,16,1,_Context->buffer_Second,51);
				break;
			case	0x7 :
				/* Initialise */
				_Context->keycode = visual_edit(250+1,310+1,408,80,1,_Context->buffer_Initialise,255);
				break;
			case	0x8 :
				/* Accept */
				visual_button(140,400,100,32,2,26,0,"Accept",6,2);
				_Context->keycode = visual_getch();
				visual_button(140,400,100,32,2,26,0,"Accept",6,0);
				break;
			case	0x9 :
				/* Cancel */
				visual_button(560,400,100,32,2,26,0,"Cancel",6,2);
				_Context->keycode = visual_getch();
				visual_button(560,400,100,32,2,26,0,"Cancel",6,0);
				break;
			case	0xa :
				/* Publique */
				visual_check(237,190,100,32,2,26,0,"Public",6,(_Context->value_Publique |2));
				_Context->keycode = visual_getch();
				visual_check(237,190,100,32,2,26,0,"Public",6,(_Context->value_Publique |0));
				break;
			case	0xb :
				/* Common */
				visual_check(350,190,100,32,2,26,0,"Common",6,(_Context->value_Common |2));
				_Context->keycode = visual_getch();
				visual_check(350,190,100,32,2,26,0,"Common",6,(_Context->value_Common |0));
				break;
			case	0xc :
				/* Pointer */
				visual_check(450,190,100,32,2,26,0,"Pointer",7,(_Context->value_Pointer |2));
				_Context->keycode = visual_getch();
				visual_check(450,190,100,32,2,26,0,"Pointer",7,(_Context->value_Pointer |0));
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_data_show();
			continue;
		case	0x2 :
			_Context->focus_item=12;
			accept_data_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_data_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Window */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* auto430 */
						continue;
					case	0x3 :
						/* auto431 */
						continue;
					case	0x4 :
						/* Size */
						continue;
					case	0x5 :
						/* First */
						continue;
					case	0x6 :
						/* Second */
						continue;
					case	0x7 :
						/* Initialise */
						continue;
					case	0x8 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(140,400,100,32,2,26,0,"Accept",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(140,400,100,32,2,26,0,"Accept",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x9 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(560,400,100,32,2,26,0,"Cancel",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(560,400,100,32,2,26,0,"Cancel",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0xa :
						/* Publique */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Publique += 1;
							_Context->value_Publique &= 1;
							}
						continue;
					case	0xb :
						/* Common */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Common += 1;
							_Context->value_Common &= 1;
							}
						continue;
					case	0xc :
						/* Pointer */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Pointer += 1;
							_Context->value_Pointer &= 1;
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
				_Context->focus_item=12;
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

public	int	accept_data(
	char * pauto430,
	char * pauto431,
	char * pSize,
	char * pFirst,
	char * pSecond,
	char * pInitialise,
	char * pPublique,
	char * pCommon,
	char * pPointer)
{
	int	status=0;
	status = accept_data_create(
	 pauto430,
	 pauto431,
	 pSize,
	 pFirst,
	 pSecond,
	 pInitialise,
	 pPublique,
	 pCommon,
	 pPointer);
	if ( status != 0) return(status);
	status = accept_data_show();
		enter_modal();
	status = accept_data_focus();
		leave_modal();
	status = accept_data_hide();
	status = accept_data_remove(
	 pauto430,
	 pauto431,
	 pSize,
	 pFirst,
	 pSecond,
	 pInitialise,
	 pPublique,
	 pCommon,
	 pPointer);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vdata_c */
