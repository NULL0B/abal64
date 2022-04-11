
#ifndef _vwebgen_c
#define _vwebgen_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vwebgen.xml  */
/* Target         : vwebgen.c  */
/* Identification : 0.0-1100518553-3522.3521 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto1549   "Sing : Version 1.0a"
#define en_Auto1551   "Html Production Parameters"
#define fr_Auto1551   "Html Production Parameters"
#define it_Auto1551   "Html Production Parameters"
#define es_Auto1551   "Html Production Parameters"
#define de_Auto1551   "Html Production Parameters"
#define nl_Auto1551   "Html Production Parameters"
#define pt_Auto1551   "Html Production Parameters"
#define xx_Auto1551   "Html Production Parameters"
#define en_Auto1552   "Filename"
#define fr_Auto1552   "Filename"
#define it_Auto1552   "Filename"
#define es_Auto1552   "Filename"
#define de_Auto1552   "Filename"
#define nl_Auto1552   "Filename"
#define pt_Auto1552   "Filename"
#define xx_Auto1552   "Filename"
#define en_Filename   ""
#define en_Title   ""
#define en_StyleSheet   ""
#define en_Nature   "Web Form|Document"
#define fr_Nature   "Web Form|Document"
#define it_Nature   "Web Form|Document"
#define es_Nature   "Web Form|Document"
#define de_Nature   "Web Form|Document"
#define nl_Nature   "Web Form|Document"
#define pt_Nature   "Web Form|Document"
#define xx_Nature   "Web Form|Document"
#define en_Generation   "Fixed Page|Scrolling"
#define fr_Generation   "Page Fixe|Defillement"
#define it_Generation   "Fixed Page|Scrolling"
#define es_Generation   "Fixed Page|Scrolling"
#define de_Generation   "Fixed Page|Scrolling"
#define nl_Generation   "Fixed Page|Scrolling"
#define pt_Generation   "Fixed Page|Scrolling"
#define xx_Generation   "Fixed Page|Scrolling"
#define en_Auto1553   "Title"
#define fr_Auto1553   "Stylesheet"
#define it_Auto1553   "Stylesheet"
#define es_Auto1553   "Stylesheet"
#define de_Auto1553   "Stylesheet"
#define nl_Auto1553   "Stylesheet"
#define pt_Auto1553   "Stylesheet"
#define xx_Auto1553   "Stylesheet"
#define en_Auto1554   "Style"
#define fr_Auto1554   "Stylesheet"
#define it_Auto1554   "Stylesheet"
#define es_Auto1554   "Stylesheet"
#define de_Auto1554   "Stylesheet"
#define nl_Auto1554   "Stylesheet"
#define pt_Auto1554   "Stylesheet"
#define xx_Auto1554   "Stylesheet"
#define en_Auto1555   "Production Type"
#define fr_Auto1555   "Production Type"
#define it_Auto1555   "Production Type"
#define es_Auto1555   "Production Type"
#define de_Auto1555   "Production Type"
#define nl_Auto1555   "Production Type"
#define pt_Auto1555   "Production Type"
#define xx_Auto1555   "Production Type"
#define en_Auto1550   "Generation"
#define fr_Auto1550   "Generation"
#define it_Auto1550   "Generation"
#define es_Auto1550   "Generation"
#define de_Auto1550   "Generation"
#define nl_Auto1550   "Generation"
#define pt_Auto1550   "Generation"
#define xx_Auto1550   "Generation"
#define en_Auto1556   "Accept"
#define fr_Auto1556   "Accept"
#define it_Auto1556   "Accept"
#define es_Auto1556   "Accept"
#define de_Auto1556   "Accept"
#define nl_Auto1556   "Accept"
#define pt_Auto1556   "Accept"
#define xx_Auto1556   "Accept"
#define en_Auto1557   "Cancel"
#define fr_Auto1557   "Cancel"
#define it_Auto1557   "Cancel"
#define es_Auto1557   "Cancel"
#define de_Auto1557   "Cancel"
#define nl_Auto1557   "Cancel"
#define pt_Auto1557   "Cancel"
#define xx_Auto1557   "Cancel"
static int	vfh[10];

private struct accept_html_production_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto1549[8];
	int	x_Auto1549;
	int	y_Auto1549;
	int	w_Auto1549;
	int	h_Auto1549;
	char * msg_Auto1551[8];
	char * msg_Auto1552[8];
	char	buffer_Filename[74];
	char	buffer_Title[74];
	char	buffer_StyleSheet[74];
	char * msg_Nature[8];
	int	value_Nature;
	char * msg_Generation[8];
	int	value_Generation;
	char * msg_Auto1553[8];
	char * msg_Auto1554[8];
	char * msg_Auto1555[8];
	char * msg_Auto1550[8];
	char * msg_Auto1556[8];
	int	trigger_Auto1556;
	char * msg_Auto1557[8];
	int	trigger_Auto1557;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[6];
	};

public	int	accept_html_production_create(
	struct accept_html_production_context ** cptr,
	char * pFilename,
	char * pTitle,
	char * pStyleSheet,
	char * pNature,
	char * pGeneration)
{

	int i;
	struct accept_html_production_context * _Context=(struct accept_html_production_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_html_production_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=8;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Filename, 73, pFilename);
		visual_transferin(_Context->buffer_Title, 73, pTitle);
		visual_transferin(_Context->buffer_StyleSheet, 73, pStyleSheet);
		visual_transferin((void *) 0, 0, pNature);
		if (!( pNature )) _Context->value_Nature=0;
		else	_Context->value_Nature = *((int *)pNature);
		visual_transferin((void *) 0, 0, pGeneration);
		if (!( pGeneration )) _Context->value_Generation=0;
		else	_Context->value_Generation = *((int *)pGeneration);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto1549[i]=" ";
	_Context->msg_Auto1549[0]=en_Auto1549;
	_Context->x_Auto1549=75;
	_Context->y_Auto1549=150;
	_Context->w_Auto1549=650;
	_Context->h_Auto1549=300;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1551[i]=" ";
	_Context->msg_Auto1551[0]=en_Auto1551;
	_Context->msg_Auto1551[1]=fr_Auto1551;
	_Context->msg_Auto1551[2]=it_Auto1551;
	_Context->msg_Auto1551[3]=es_Auto1551;
	_Context->msg_Auto1551[4]=de_Auto1551;
	_Context->msg_Auto1551[5]=nl_Auto1551;
	_Context->msg_Auto1551[6]=pt_Auto1551;
	_Context->msg_Auto1551[7]=xx_Auto1551;
	for (i=0; i < 8; i++)_Context->msg_Auto1552[i]=" ";
	_Context->msg_Auto1552[0]=en_Auto1552;
	_Context->msg_Auto1552[1]=fr_Auto1552;
	_Context->msg_Auto1552[2]=it_Auto1552;
	_Context->msg_Auto1552[3]=es_Auto1552;
	_Context->msg_Auto1552[4]=de_Auto1552;
	_Context->msg_Auto1552[5]=nl_Auto1552;
	_Context->msg_Auto1552[6]=pt_Auto1552;
	_Context->msg_Auto1552[7]=xx_Auto1552;
	for (i=0; i < 8; i++)_Context->msg_Nature[i]=" ";
	_Context->msg_Nature[0]=en_Nature;
	_Context->msg_Nature[1]=fr_Nature;
	_Context->msg_Nature[2]=it_Nature;
	_Context->msg_Nature[3]=es_Nature;
	_Context->msg_Nature[4]=de_Nature;
	_Context->msg_Nature[5]=nl_Nature;
	_Context->msg_Nature[6]=pt_Nature;
	_Context->msg_Nature[7]=xx_Nature;
	for (i=0; i < 8; i++)_Context->msg_Generation[i]=" ";
	_Context->msg_Generation[0]=en_Generation;
	_Context->msg_Generation[1]=fr_Generation;
	_Context->msg_Generation[2]=it_Generation;
	_Context->msg_Generation[3]=es_Generation;
	_Context->msg_Generation[4]=de_Generation;
	_Context->msg_Generation[5]=nl_Generation;
	_Context->msg_Generation[6]=pt_Generation;
	_Context->msg_Generation[7]=xx_Generation;
	for (i=0; i < 8; i++)_Context->msg_Auto1553[i]=" ";
	_Context->msg_Auto1553[0]=en_Auto1553;
	_Context->msg_Auto1553[1]=fr_Auto1553;
	_Context->msg_Auto1553[2]=it_Auto1553;
	_Context->msg_Auto1553[3]=es_Auto1553;
	_Context->msg_Auto1553[4]=de_Auto1553;
	_Context->msg_Auto1553[5]=nl_Auto1553;
	_Context->msg_Auto1553[6]=pt_Auto1553;
	_Context->msg_Auto1553[7]=xx_Auto1553;
	for (i=0; i < 8; i++)_Context->msg_Auto1554[i]=" ";
	_Context->msg_Auto1554[0]=en_Auto1554;
	_Context->msg_Auto1554[1]=fr_Auto1554;
	_Context->msg_Auto1554[2]=it_Auto1554;
	_Context->msg_Auto1554[3]=es_Auto1554;
	_Context->msg_Auto1554[4]=de_Auto1554;
	_Context->msg_Auto1554[5]=nl_Auto1554;
	_Context->msg_Auto1554[6]=pt_Auto1554;
	_Context->msg_Auto1554[7]=xx_Auto1554;
	for (i=0; i < 8; i++)_Context->msg_Auto1555[i]=" ";
	_Context->msg_Auto1555[0]=en_Auto1555;
	_Context->msg_Auto1555[1]=fr_Auto1555;
	_Context->msg_Auto1555[2]=it_Auto1555;
	_Context->msg_Auto1555[3]=es_Auto1555;
	_Context->msg_Auto1555[4]=de_Auto1555;
	_Context->msg_Auto1555[5]=nl_Auto1555;
	_Context->msg_Auto1555[6]=pt_Auto1555;
	_Context->msg_Auto1555[7]=xx_Auto1555;
	for (i=0; i < 8; i++)_Context->msg_Auto1550[i]=" ";
	_Context->msg_Auto1550[0]=en_Auto1550;
	_Context->msg_Auto1550[1]=fr_Auto1550;
	_Context->msg_Auto1550[2]=it_Auto1550;
	_Context->msg_Auto1550[3]=es_Auto1550;
	_Context->msg_Auto1550[4]=de_Auto1550;
	_Context->msg_Auto1550[5]=nl_Auto1550;
	_Context->msg_Auto1550[6]=pt_Auto1550;
	_Context->msg_Auto1550[7]=xx_Auto1550;
	for (i=0; i < 8; i++)_Context->msg_Auto1556[i]=" ";
	_Context->msg_Auto1556[0]=en_Auto1556;
	_Context->msg_Auto1556[1]=fr_Auto1556;
	_Context->msg_Auto1556[2]=it_Auto1556;
	_Context->msg_Auto1556[3]=es_Auto1556;
	_Context->msg_Auto1556[4]=de_Auto1556;
	_Context->msg_Auto1556[5]=nl_Auto1556;
	_Context->msg_Auto1556[6]=pt_Auto1556;
	_Context->msg_Auto1556[7]=xx_Auto1556;
	for (i=0; i < 8; i++)_Context->msg_Auto1557[i]=" ";
	_Context->msg_Auto1557[0]=en_Auto1557;
	_Context->msg_Auto1557[1]=fr_Auto1557;
	_Context->msg_Auto1557[2]=it_Auto1557;
	_Context->msg_Auto1557[3]=es_Auto1557;
	_Context->msg_Auto1557[4]=de_Auto1557;
	_Context->msg_Auto1557[5]=nl_Auto1557;
	_Context->msg_Auto1557[6]=pt_Auto1557;
	_Context->msg_Auto1557[7]=xx_Auto1557;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto1549,_Context->y_Auto1549,650+10,300+10);
	return(0);
}

public 	int	accept_html_production_hide(struct accept_html_production_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto1549,_Context->y_Auto1549);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_html_production_remove(
	struct accept_html_production_context * _Context,
	char * pFilename,
	char * pTitle,
	char * pStyleSheet,
	char * pNature,
	char * pGeneration)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Filename, 73, pFilename);
		visual_transferout(_Context->buffer_Title, 73, pTitle);
		visual_transferout(_Context->buffer_StyleSheet, 73, pStyleSheet);
		visual_transferout((void *) 0, 0, pNature);
		if ( pNature != (char *) 0)
			*((int*)pNature) = _Context->value_Nature;
		visual_transferout((void *) 0, 0, pGeneration);
		if ( pGeneration != (char *) 0)
			*((int*)pGeneration) = _Context->value_Generation;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_html_production_show(struct accept_html_production_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto1549,_Context->y_Auto1549);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto1549,_Context->y_Auto1549,650,300,vfh[2],_Context->msg_Auto1549[_Context->language],strlen(_Context->msg_Auto1549[_Context->language]),0x407);
	visual_frame(_Context->x_Auto1549+10,_Context->y_Auto1549+30,630,260,3);
	visual_text(_Context->x_Auto1549+20,_Context->y_Auto1549+40,610,30,vfh[3],16,0,_Context->msg_Auto1551[_Context->language],strlen(_Context->msg_Auto1551[_Context->language]),1283);
	visual_text(_Context->x_Auto1549+30,_Context->y_Auto1549+80,200,20,vfh[2],16,0,_Context->msg_Auto1552[_Context->language],strlen(_Context->msg_Auto1552[_Context->language]),258);
	visual_frame(_Context->x_Auto1549+30,_Context->y_Auto1549+100,584+2,16+2,5);
	visual_text(_Context->x_Auto1549+30+1,_Context->y_Auto1549+100+1,584,16,vfh[1],16,0,_Context->buffer_Filename,73,0);
	visual_frame(_Context->x_Auto1549+30,_Context->y_Auto1549+150,584+2,16+2,5);
	visual_text(_Context->x_Auto1549+30+1,_Context->y_Auto1549+150+1,584,16,vfh[1],16,0,_Context->buffer_Title,73,0);
	visual_frame(_Context->x_Auto1549+30,_Context->y_Auto1549+200,584+2,16+2,5);
	visual_text(_Context->x_Auto1549+30+1,_Context->y_Auto1549+200+1,584,16,vfh[1],16,0,_Context->buffer_StyleSheet,73,0);
	visual_select(_Context->x_Auto1549+170,_Context->y_Auto1549+250,136,48,vfh[1],16,0,parse_selection(_Context->msg_Nature[_Context->language],&_Context->value_Nature),0);
	visual_select(_Context->x_Auto1549+350,_Context->y_Auto1549+250,136,48,vfh[1],16,0,parse_selection(_Context->msg_Generation[_Context->language],&_Context->value_Generation),0);
	visual_text(_Context->x_Auto1549+30,_Context->y_Auto1549+130,200,20,vfh[2],16,0,_Context->msg_Auto1553[_Context->language],strlen(_Context->msg_Auto1553[_Context->language]),258);
	visual_text(_Context->x_Auto1549+30,_Context->y_Auto1549+180,200,20,vfh[2],16,0,_Context->msg_Auto1554[_Context->language],strlen(_Context->msg_Auto1554[_Context->language]),258);
	visual_text(_Context->x_Auto1549+170,_Context->y_Auto1549+230,140,16,vfh[2],16,0,_Context->msg_Auto1555[_Context->language],strlen(_Context->msg_Auto1555[_Context->language]),259);
	visual_text(_Context->x_Auto1549+350,_Context->y_Auto1549+230,140,16,vfh[2],16,0,_Context->msg_Auto1550[_Context->language],strlen(_Context->msg_Auto1550[_Context->language]),259);
	_Context->trigger_Auto1556=visual_trigger_code(_Context->msg_Auto1556[_Context->language],strlen(_Context->msg_Auto1556[_Context->language]));
	visual_button(_Context->x_Auto1549+30,_Context->y_Auto1549+240,112,32,vfh[2],16,0,_Context->msg_Auto1556[_Context->language],strlen(_Context->msg_Auto1556[_Context->language]),0);
	_Context->trigger_Auto1557=visual_trigger_code(_Context->msg_Auto1557[_Context->language],strlen(_Context->msg_Auto1557[_Context->language]));
	visual_button(_Context->x_Auto1549+500,_Context->y_Auto1549+240,112,32,vfh[2],16,0,_Context->msg_Auto1557[_Context->language],strlen(_Context->msg_Auto1557[_Context->language]),0);
	visual_thaw(_Context->x_Auto1549,_Context->y_Auto1549,650,300);
	visual_thaw(_Context->x_Auto1549,_Context->y_Auto1549,650,300);

	return(0);
}

private int Auto1549action(struct accept_html_production_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_html_production_hide(_Context);

		_Context->x_Auto1549 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto1549 < 0) { _Context->x_Auto1549=0; }
		_Context->y_Auto1549 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto1549 < 0) { _Context->y_Auto1549=0; }
			accept_html_production_show(_Context);

		visual_thaw(_Context->x_Auto1549,_Context->y_Auto1549,650,300);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Auto1556_event(struct accept_html_production_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto1557_event(struct accept_html_production_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_html_production_event(
struct accept_html_production_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto1556 == mb ) return(7);
		if (_Context->trigger_Auto1557 == mb ) return(8);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto1549+629) )  
	&&  (my >= (_Context->y_Auto1549+4) )  
	&&  (mx <= (_Context->x_Auto1549+646) )  
	&&  (my <= (_Context->y_Auto1549+20) )) {
		return(1);	/* Auto1549 */

		}
	if ((mx >= (_Context->x_Auto1549+613) )  
	&&  (my >= (_Context->y_Auto1549+4) )  
	&&  (mx <= (_Context->x_Auto1549+630) )  
	&&  (my <= (_Context->y_Auto1549+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vwebgen.htm");
			};
		return(-1);	/* Auto1549 */

		}
	if ((mx >= (_Context->x_Auto1549+597) )  
	&&  (my >= (_Context->y_Auto1549+4) )  
	&&  (mx <= (_Context->x_Auto1549+614) )  
	&&  (my <= (_Context->y_Auto1549+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_html_production_show(_Context);
		return(-1);	/* Auto1549 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto1549+4) )  
		&&  (my >= (_Context->y_Auto1549+4) )  
		&&  (mx <= (_Context->x_Auto1549+582) )  
		&&  (my <= (_Context->y_Auto1549+20) )) {
			return( Auto1549action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto1549+30) ) 
	&&  ( my >= (_Context->y_Auto1549+100) ) 
	&&  ( mx <= (_Context->x_Auto1549+30+584) ) 
	&&  ( my <= (_Context->y_Auto1549+100+16))) {
		return(2); /* Filename */
		}
	if (( mx >= (_Context->x_Auto1549+30) ) 
	&&  ( my >= (_Context->y_Auto1549+150) ) 
	&&  ( mx <= (_Context->x_Auto1549+30+584) ) 
	&&  ( my <= (_Context->y_Auto1549+150+16))) {
		return(3); /* Title */
		}
	if (( mx >= (_Context->x_Auto1549+30) ) 
	&&  ( my >= (_Context->y_Auto1549+200) ) 
	&&  ( mx <= (_Context->x_Auto1549+30+584) ) 
	&&  ( my <= (_Context->y_Auto1549+200+16))) {
		return(4); /* StyleSheet */
		}
	if (( mx >= (_Context->x_Auto1549+170+0) ) 
	&&  ( my >= (_Context->y_Auto1549+250) ) 
	&&  ( mx <= (_Context->x_Auto1549+170+136) ) 
	&&  ( my <= (_Context->y_Auto1549+250+16))) {
		return(5); /* Nature */
		}
	if (( mx >= (_Context->x_Auto1549+350+0) ) 
	&&  ( my >= (_Context->y_Auto1549+250) ) 
	&&  ( mx <= (_Context->x_Auto1549+350+136) ) 
	&&  ( my <= (_Context->y_Auto1549+250+16))) {
		return(6); /* Generation */
		}
	if (( mx >= (_Context->x_Auto1549+30) ) 
	&&  ( my >= (_Context->y_Auto1549+240) ) 
	&&  ( mx <= (_Context->x_Auto1549+30+112) ) 
	&&  ( my <= (_Context->y_Auto1549+240+32))) {
		return(7); /* Auto1556 */
		}
	if (( mx >= (_Context->x_Auto1549+500) ) 
	&&  ( my >= (_Context->y_Auto1549+240) ) 
	&&  ( mx <= (_Context->x_Auto1549+500+112) ) 
	&&  ( my <= (_Context->y_Auto1549+240+32))) {
		return(8); /* Auto1557 */
		}

	return(-1);
}


public	int	accept_html_production_focus(struct accept_html_production_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Filename */
				_Context->keycode = visual_edit(_Context->x_Auto1549+30+1,_Context->y_Auto1549+100+1,584,16,vfh[1],_Context->buffer_Filename,73);
			break;
			case	0x3 :
				/* Title */
				_Context->keycode = visual_edit(_Context->x_Auto1549+30+1,_Context->y_Auto1549+150+1,584,16,vfh[1],_Context->buffer_Title,73);
			break;
			case	0x4 :
				/* StyleSheet */
				_Context->keycode = visual_edit(_Context->x_Auto1549+30+1,_Context->y_Auto1549+200+1,584,16,vfh[1],_Context->buffer_StyleSheet,73);
			break;
			case	0x5 :
				/* Nature */
				_Context->keycode = visual_select(_Context->x_Auto1549+170,_Context->y_Auto1549+250,136,48,vfh[1],16,0,parse_selection(_Context->msg_Nature[_Context->language],&_Context->value_Nature),2);
				break;
			case	0x6 :
				/* Generation */
				_Context->keycode = visual_select(_Context->x_Auto1549+350,_Context->y_Auto1549+250,136,48,vfh[1],16,0,parse_selection(_Context->msg_Generation[_Context->language],&_Context->value_Generation),2);
				break;
			case	0x7 :
				/* Auto1556 */
				visual_button(_Context->x_Auto1549+30,_Context->y_Auto1549+240,112,32,vfh[2],16,0,_Context->msg_Auto1556[_Context->language],strlen(_Context->msg_Auto1556[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1549+30,_Context->y_Auto1549+240,112,32,vfh[2],16,0,_Context->msg_Auto1556[_Context->language],strlen(_Context->msg_Auto1556[_Context->language]),0);
				break;
			case	0x8 :
				/* Auto1557 */
				visual_button(_Context->x_Auto1549+500,_Context->y_Auto1549+240,112,32,vfh[2],16,0,_Context->msg_Auto1557[_Context->language],strlen(_Context->msg_Auto1557[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1549+500,_Context->y_Auto1549+240,112,32,vfh[2],16,0,_Context->msg_Auto1557[_Context->language],strlen(_Context->msg_Auto1557[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_html_production_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=8;
			accept_html_production_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_html_production_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1549 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Filename */
						continue;
					case	0x3 :
						/* Title */
						continue;
					case	0x4 :
						/* StyleSheet */
						continue;
					case	0x5 :
						/* Nature */
						continue;
					case	0x6 :
						/* Generation */
						continue;
					case	0x7 :
						/* Auto1556 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1549+30,_Context->y_Auto1549+240,112,32,vfh[2],16,0,_Context->msg_Auto1556[_Context->language],strlen(_Context->msg_Auto1556[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1549+30,_Context->y_Auto1549+240,112,32,vfh[2],16,0,_Context->msg_Auto1556[_Context->language],strlen(_Context->msg_Auto1556[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1556_event(_Context)) != -1) break;

							}
						continue;
					case	0x8 :
						/* Auto1557 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1549+500,_Context->y_Auto1549+240,112,32,vfh[2],16,0,_Context->msg_Auto1557[_Context->language],strlen(_Context->msg_Auto1557[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1549+500,_Context->y_Auto1549+240,112,32,vfh[2],16,0,_Context->msg_Auto1557[_Context->language],strlen(_Context->msg_Auto1557[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1557_event(_Context)) != -1) break;

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
				_Context->focus_item=8;
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

public	int	accept_html_production(
	char * pFilename,
	char * pTitle,
	char * pStyleSheet,
	char * pNature,
	char * pGeneration)
{
	int	status=0;
	struct accept_html_production_context * _Context=(struct accept_html_production_context*) 0;
	status = accept_html_production_create(
	&_Context,
	 pFilename,
	 pTitle,
	 pStyleSheet,
	 pNature,
	 pGeneration);
	if ( status != 0) return(status);
	status = accept_html_production_show(_Context);
		enter_modal();
	status = accept_html_production_focus(_Context);
		leave_modal();
	status = accept_html_production_hide(_Context);
	status = accept_html_production_remove(
	_Context,
	 pFilename,
	 pTitle,
	 pStyleSheet,
	 pNature,
	 pGeneration);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwebgen_c */
