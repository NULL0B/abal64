
#ifndef _vfextr_c
#define _vfextr_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.01  */
/* Production     : C  */
/* Project        : vfextr.sng  */
/* Target         : vfextr.c  */
/* Identification : 0.0-1057622498-2176.2175 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_extraction_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	value_SourceFont;
	int	value_GroupOne;
	int	value_Auto4622;
	int	value_GroupTwo;
	int	value_Auto4623;
	int	value_GroupThree;
	int	value_Auto4624;
	int	value_GroupFour;
	int	value_Auto4625;
	int	value_GroupFive;
	int	value_Recalc;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[12];
	} * _Context;

private	int	accept_extraction_create( char * pSourceFont,char * pGroupOne,char * pAuto4622,char * pGroupTwo,char * pAuto4623,char * pGroupThree,char * pAuto4624,char * pGroupFour,char * pAuto4625,char * pGroupFive,char * pRecalc)
{

	if (!(_Context = allocate( sizeof( struct accept_extraction_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=14;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pSourceFont);
		if (!( pSourceFont )) _Context->value_SourceFont=0;
		else	_Context->value_SourceFont = *((int *)pSourceFont);
		visual_transferin((void *) 0, 0, pGroupOne);
		if (!( pGroupOne )) _Context->value_GroupOne=0;
		else	_Context->value_GroupOne = *((int *)pGroupOne);
		visual_transferin((void *) 0, 0, pAuto4622);
		if (!( pAuto4622 )) _Context->value_Auto4622=0;
		else	_Context->value_Auto4622 = *((int *)pAuto4622);
		visual_transferin((void *) 0, 0, pGroupTwo);
		if (!( pGroupTwo )) _Context->value_GroupTwo=0;
		else	_Context->value_GroupTwo = *((int *)pGroupTwo);
		visual_transferin((void *) 0, 0, pAuto4623);
		if (!( pAuto4623 )) _Context->value_Auto4623=0;
		else	_Context->value_Auto4623 = *((int *)pAuto4623);
		visual_transferin((void *) 0, 0, pGroupThree);
		if (!( pGroupThree )) _Context->value_GroupThree=0;
		else	_Context->value_GroupThree = *((int *)pGroupThree);
		visual_transferin((void *) 0, 0, pAuto4624);
		if (!( pAuto4624 )) _Context->value_Auto4624=0;
		else	_Context->value_Auto4624 = *((int *)pAuto4624);
		visual_transferin((void *) 0, 0, pGroupFour);
		if (!( pGroupFour )) _Context->value_GroupFour=0;
		else	_Context->value_GroupFour = *((int *)pGroupFour);
		visual_transferin((void *) 0, 0, pAuto4625);
		if (!( pAuto4625 )) _Context->value_Auto4625=0;
		else	_Context->value_Auto4625 = *((int *)pAuto4625);
		visual_transferin((void *) 0, 0, pGroupFive);
		if (!( pGroupFive )) _Context->value_GroupFive=0;
		else	_Context->value_GroupFive = *((int *)pGroupFive);
		visual_transferin((void *) 0, 0, pRecalc);
		if (!( pRecalc )) _Context->value_Recalc=0;
		else	_Context->value_Recalc = *((int *)pRecalc);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(215,110,370+10,380+10);
	return(0);
}

private	int	accept_extraction_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,215,110);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_extraction_remove( char * pSourceFont,char * pGroupOne,char * pAuto4622,char * pGroupTwo,char * pAuto4623,char * pGroupThree,char * pAuto4624,char * pGroupFour,char * pAuto4625,char * pGroupFive,char * pRecalc)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pSourceFont);
		if ( pSourceFont != (char *) 0)
			*((int*)pSourceFont) = _Context->value_SourceFont;
		visual_transferout((void *) 0, 0, pGroupOne);
		if ( pGroupOne != (char *) 0)
			*((int*)pGroupOne) = _Context->value_GroupOne;
		visual_transferout((void *) 0, 0, pAuto4622);
		if ( pAuto4622 != (char *) 0)
			*((int*)pAuto4622) = _Context->value_Auto4622;
		visual_transferout((void *) 0, 0, pGroupTwo);
		if ( pGroupTwo != (char *) 0)
			*((int*)pGroupTwo) = _Context->value_GroupTwo;
		visual_transferout((void *) 0, 0, pAuto4623);
		if ( pAuto4623 != (char *) 0)
			*((int*)pAuto4623) = _Context->value_Auto4623;
		visual_transferout((void *) 0, 0, pGroupThree);
		if ( pGroupThree != (char *) 0)
			*((int*)pGroupThree) = _Context->value_GroupThree;
		visual_transferout((void *) 0, 0, pAuto4624);
		if ( pAuto4624 != (char *) 0)
			*((int*)pAuto4624) = _Context->value_Auto4624;
		visual_transferout((void *) 0, 0, pGroupFour);
		if ( pGroupFour != (char *) 0)
			*((int*)pGroupFour) = _Context->value_GroupFour;
		visual_transferout((void *) 0, 0, pAuto4625);
		if ( pAuto4625 != (char *) 0)
			*((int*)pAuto4625) = _Context->value_Auto4625;
		visual_transferout((void *) 0, 0, pGroupFive);
		if ( pGroupFive != (char *) 0)
			*((int*)pGroupFive) = _Context->value_GroupFive;
		visual_transferout((void *) 0, 0, pRecalc);
		if ( pRecalc != (char *) 0)
			*((int*)pRecalc) = _Context->value_Recalc;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_extraction_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,215,110);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(215,110,370,380,1,"Sing : Version 1.0a",19,0x403);
	visual_image(218,131,363,355,VisualSkin,4);
	visual_button(225,440,120,32,2,27,0,"Accept",6,0);
	visual_button(455,440,120,32,2,27,0,"Cancel",6,0);
	visual_text(225,140,350,20,3,27,0,"Extraction of Characters",24,1026);
	visual_frame(225,160,350,270,4);
	visual_text(235,180,182,16,2,27,0,"Source Font",11,2);
	visual_select(425,180,128,80,1,34,0,parse_selection(TextFontList,&_Context->value_SourceFont),0);
	visual_check(235,220,322,16,1,27,28,"Range 21H to 2Fh : punctuation group 1",38,_Context->value_GroupOne|0);
	visual_check(235,240,320,16,1,0,0,"Digits",6,_Context->value_Auto4622|0);
	visual_check(235,260,322,16,1,27,28,"Range 3Ah to 40h : punctuation group 2",38,_Context->value_GroupTwo|0);
	visual_check(235,280,320,16,1,0,0,"Uppercase Alphabet",18,_Context->value_Auto4623|0);
	visual_check(235,300,322,16,1,27,28,"Range 5Bh to 60h : symbols group 1",34,_Context->value_GroupThree|0);
	visual_check(235,320,320,16,1,0,0,"Lowercase Alphabet",18,_Context->value_Auto4624|0);
	visual_check(235,340,322,16,1,27,28,"Range 7Bh to 7Fh : symbols group 2",34,_Context->value_GroupFour|0);
	visual_check(235,360,320,16,1,0,0,"International Accented characters",33,_Context->value_Auto4625|0);
	visual_check(235,380,322,16,1,27,28,"Range 9Bh to 9Fh : symbols group 3",34,_Context->value_GroupFive|0);
	visual_check(235,400,320,20,1,0,0,"Recalculate proportions",23,_Context->value_Recalc|0);
	visual_thaw(215,110,370,380);

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


private	int	accept_extraction_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 564 )  
	&&  (my >= 114 )  
	&&  (mx <= 580 )  
	&&  (my <= 130 )) {
		return(1);	/* Auto4568 */

		}
	if ((mx >= 548 )  
	&&  (my >= 114 )  
	&&  (mx <= 564 )  
	&&  (my <= 130 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vfextr.htm");
			};
		return(-1);	/* Auto4568 */

		}
	if (( mx >= 225 ) 
	&&  ( my >= 440 ) 
	&&  ( mx <= 345 ) 
	&&  ( my <= 472 )) {
		return(2); /* Accept */
		}
	if (( mx >= 455 ) 
	&&  ( my >= 440 ) 
	&&  ( mx <= 575 ) 
	&&  ( my <= 472 )) {
		return(3); /* Cancel */
		}
	if ((mx >= 425 ) 
	&&  (my >= 180 ) 
	&&  (mx <= 553 ) 
	&&  (my <= 196 )) {
		return(4); /* SourceFont */
		}
	if (( mx >= 235 ) 
	&&  ( my >= 220 ) 
	&&  ( mx <= 557 ) 
	&&  ( my <= 236 )) {
		return(5); /* GroupOne */
		}
	if (( mx >= 235 ) 
	&&  ( my >= 240 ) 
	&&  ( mx <= 555 ) 
	&&  ( my <= 256 )) {
		return(6); /* Auto4622 */
		}
	if (( mx >= 235 ) 
	&&  ( my >= 260 ) 
	&&  ( mx <= 557 ) 
	&&  ( my <= 276 )) {
		return(7); /* GroupTwo */
		}
	if (( mx >= 235 ) 
	&&  ( my >= 280 ) 
	&&  ( mx <= 555 ) 
	&&  ( my <= 296 )) {
		return(8); /* Auto4623 */
		}
	if (( mx >= 235 ) 
	&&  ( my >= 300 ) 
	&&  ( mx <= 557 ) 
	&&  ( my <= 316 )) {
		return(9); /* GroupThree */
		}
	if (( mx >= 235 ) 
	&&  ( my >= 320 ) 
	&&  ( mx <= 555 ) 
	&&  ( my <= 336 )) {
		return(10); /* Auto4624 */
		}
	if (( mx >= 235 ) 
	&&  ( my >= 340 ) 
	&&  ( mx <= 557 ) 
	&&  ( my <= 356 )) {
		return(11); /* GroupFour */
		}
	if (( mx >= 235 ) 
	&&  ( my >= 360 ) 
	&&  ( mx <= 555 ) 
	&&  ( my <= 376 )) {
		return(12); /* Auto4625 */
		}
	if (( mx >= 235 ) 
	&&  ( my >= 380 ) 
	&&  ( mx <= 557 ) 
	&&  ( my <= 396 )) {
		return(13); /* GroupFive */
		}
	if (( mx >= 235 ) 
	&&  ( my >= 400 ) 
	&&  ( mx <= 555 ) 
	&&  ( my <= 420 )) {
		return(14); /* Recalc */
		}

	return(-1);
}


private	int	accept_extraction_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Accept */
				visual_button(225,440,120,32,2,27,0,"Accept",6,2);
				_Context->keycode = visual_getch();
				visual_button(225,440,120,32,2,27,0,"Accept",6,0);
				break;
			case	0x3 :
				/* Cancel */
				visual_button(455,440,120,32,2,27,0,"Cancel",6,2);
				_Context->keycode = visual_getch();
				visual_button(455,440,120,32,2,27,0,"Cancel",6,0);
				break;
			case	0x4 :
				/* SourceFont */
				_Context->keycode = visual_select(425,180,128,80,1,34,0,parse_selection(TextFontList,&_Context->value_SourceFont),2);
				break;
			case	0x5 :
				/* GroupOne */
				visual_check(235,220,322,16,1,27,28,"Range 21H to 2Fh : punctuation group 1",38,(_Context->value_GroupOne |2));
				_Context->keycode = visual_getch();
				visual_check(235,220,322,16,1,27,28,"Range 21H to 2Fh : punctuation group 1",38,(_Context->value_GroupOne |0));
				break;
			case	0x6 :
				/* Auto4622 */
				visual_check(235,240,320,16,1,0,0,"Digits",6,(_Context->value_Auto4622 |2));
				_Context->keycode = visual_getch();
				visual_check(235,240,320,16,1,0,0,"Digits",6,(_Context->value_Auto4622 |0));
				break;
			case	0x7 :
				/* GroupTwo */
				visual_check(235,260,322,16,1,27,28,"Range 3Ah to 40h : punctuation group 2",38,(_Context->value_GroupTwo |2));
				_Context->keycode = visual_getch();
				visual_check(235,260,322,16,1,27,28,"Range 3Ah to 40h : punctuation group 2",38,(_Context->value_GroupTwo |0));
				break;
			case	0x8 :
				/* Auto4623 */
				visual_check(235,280,320,16,1,0,0,"Uppercase Alphabet",18,(_Context->value_Auto4623 |2));
				_Context->keycode = visual_getch();
				visual_check(235,280,320,16,1,0,0,"Uppercase Alphabet",18,(_Context->value_Auto4623 |0));
				break;
			case	0x9 :
				/* GroupThree */
				visual_check(235,300,322,16,1,27,28,"Range 5Bh to 60h : symbols group 1",34,(_Context->value_GroupThree |2));
				_Context->keycode = visual_getch();
				visual_check(235,300,322,16,1,27,28,"Range 5Bh to 60h : symbols group 1",34,(_Context->value_GroupThree |0));
				break;
			case	0xa :
				/* Auto4624 */
				visual_check(235,320,320,16,1,0,0,"Lowercase Alphabet",18,(_Context->value_Auto4624 |2));
				_Context->keycode = visual_getch();
				visual_check(235,320,320,16,1,0,0,"Lowercase Alphabet",18,(_Context->value_Auto4624 |0));
				break;
			case	0xb :
				/* GroupFour */
				visual_check(235,340,322,16,1,27,28,"Range 7Bh to 7Fh : symbols group 2",34,(_Context->value_GroupFour |2));
				_Context->keycode = visual_getch();
				visual_check(235,340,322,16,1,27,28,"Range 7Bh to 7Fh : symbols group 2",34,(_Context->value_GroupFour |0));
				break;
			case	0xc :
				/* Auto4625 */
				visual_check(235,360,320,16,1,0,0,"International Accented characters",33,(_Context->value_Auto4625 |2));
				_Context->keycode = visual_getch();
				visual_check(235,360,320,16,1,0,0,"International Accented characters",33,(_Context->value_Auto4625 |0));
				break;
			case	0xd :
				/* GroupFive */
				visual_check(235,380,322,16,1,27,28,"Range 9Bh to 9Fh : symbols group 3",34,(_Context->value_GroupFive |2));
				_Context->keycode = visual_getch();
				visual_check(235,380,322,16,1,27,28,"Range 9Bh to 9Fh : symbols group 3",34,(_Context->value_GroupFive |0));
				break;
			case	0xe :
				/* Recalc */
				visual_check(235,400,320,20,1,0,0,"Recalculate proportions",23,(_Context->value_Recalc |2));
				_Context->keycode = visual_getch();
				visual_check(235,400,320,20,1,0,0,"Recalculate proportions",23,(_Context->value_Recalc |0));
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_extraction_show();
			continue;
		case	0x2 :
			_Context->focus_item=14;
			accept_extraction_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_extraction_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto4568 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(225,440,120,32,2,27,0,"Accept",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(225,440,120,32,2,27,0,"Accept",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x3 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(455,440,120,32,2,27,0,"Cancel",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(455,440,120,32,2,27,0,"Cancel",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* SourceFont */
						continue;
					case	0x5 :
						/* GroupOne */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_GroupOne += 1;
							_Context->value_GroupOne &= 1;
							}
						continue;
					case	0x6 :
						/* Auto4622 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Auto4622 += 1;
							_Context->value_Auto4622 &= 1;
							}
						continue;
					case	0x7 :
						/* GroupTwo */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_GroupTwo += 1;
							_Context->value_GroupTwo &= 1;
							}
						continue;
					case	0x8 :
						/* Auto4623 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Auto4623 += 1;
							_Context->value_Auto4623 &= 1;
							}
						continue;
					case	0x9 :
						/* GroupThree */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_GroupThree += 1;
							_Context->value_GroupThree &= 1;
							}
						continue;
					case	0xa :
						/* Auto4624 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Auto4624 += 1;
							_Context->value_Auto4624 &= 1;
							}
						continue;
					case	0xb :
						/* GroupFour */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_GroupFour += 1;
							_Context->value_GroupFour &= 1;
							}
						continue;
					case	0xc :
						/* Auto4625 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Auto4625 += 1;
							_Context->value_Auto4625 &= 1;
							}
						continue;
					case	0xd :
						/* GroupFive */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_GroupFive += 1;
							_Context->value_GroupFive &= 1;
							}
						continue;
					case	0xe :
						/* Recalc */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Recalc += 1;
							_Context->value_Recalc &= 1;
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
				_Context->focus_item=14;
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

public	int	accept_extraction( char * pSourceFont,char * pGroupOne,char * pAuto4622,char * pGroupTwo,char * pAuto4623,char * pGroupThree,char * pAuto4624,char * pGroupFour,char * pAuto4625,char * pGroupFive,char * pRecalc)
{
	int	status=0;
	status = accept_extraction_create(  pSourceFont, pGroupOne, pAuto4622, pGroupTwo, pAuto4623, pGroupThree, pAuto4624, pGroupFour, pAuto4625, pGroupFive, pRecalc);
	if ( status != 0) return(status);
	status = accept_extraction_show();
		enter_modal();
	status = accept_extraction_focus();
		leave_modal();
	status = accept_extraction_hide();
	status = accept_extraction_remove(  pSourceFont, pGroupOne, pAuto4622, pGroupTwo, pAuto4623, pGroupThree, pAuto4624, pGroupFour, pAuto4625, pGroupFive, pRecalc);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vfextr_c */
