
#ifndef _newnode_c
#define _newnode_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : newnode.xml                                              */
/* Target         : newnode.c                                                */
/* Identification : 0.0-1354196808-29975.29974                               */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "newnode.h"
static int	vfh[16];
private int on_Accept_event(struct accept_new_node_context * _Context);
private int on_Cancel_event(struct accept_new_node_context * _Context);

public	int	accept_new_node_attach()
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

public	int	accept_new_node_attach_mode(int mode)
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

public	int	accept_new_node_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	accept_new_node_create(
	struct accept_new_node_context ** cptr,
	char * pNodeName,
	char * pNodeAccess,
	char * pNodeScope,
	char * pNodeType,
	char * pNodeTypeName,
	char * pNodeCategory,
	char * pNodeImage)
{

	int i;
	struct accept_new_node_context * _Context=(struct accept_new_node_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_new_node_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=10;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_NodeName, 59, pNodeName);
		visual_transferin((void *) 0, 0, pNodeAccess);
		if (!( pNodeAccess )) _Context->value_NodeAccess=0;
		else	_Context->value_NodeAccess = *((int *)pNodeAccess);
		visual_transferin((void *) 0, 0, pNodeScope);
		if (!( pNodeScope )) _Context->value_NodeScope=0;
		else	_Context->value_NodeScope = *((int *)pNodeScope);
		visual_transferin((void *) 0, 0, pNodeType);
		if (!( pNodeType )) _Context->value_NodeType=0;
		else	_Context->value_NodeType = *((int *)pNodeType);
		visual_transferin(_Context->buffer_NodeTypeName, 59, pNodeTypeName);
		visual_transferin(_Context->buffer_NodeCategory, 59, pNodeCategory);
		visual_transferin(_Context->buffer_NodeImage, 59, pNodeImage);
		}
	_Context->x_Auto44=155;
	_Context->y_Auto44=115;
	_Context->w_Auto44=490;
	_Context->h_Auto44=370;
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto44,_Context->y_Auto44,490+10,370+10);
	return(0);
}

public 	int	accept_new_node_hide(struct accept_new_node_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto44,_Context->y_Auto44);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_new_node_remove(
	struct accept_new_node_context * _Context,
	char * pNodeName,
	char * pNodeAccess,
	char * pNodeScope,
	char * pNodeType,
	char * pNodeTypeName,
	char * pNodeCategory,
	char * pNodeImage)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_NodeName, 59, pNodeName);
		visual_transferout((void *) 0, 0, pNodeAccess);
		if ( pNodeAccess != (char *) 0)
			*((int*)pNodeAccess) = _Context->value_NodeAccess;
		visual_transferout((void *) 0, 0, pNodeScope);
		if ( pNodeScope != (char *) 0)
			*((int*)pNodeScope) = _Context->value_NodeScope;
		visual_transferout((void *) 0, 0, pNodeType);
		if ( pNodeType != (char *) 0)
			*((int*)pNodeType) = _Context->value_NodeType;
		visual_transferout(_Context->buffer_NodeTypeName, 59, pNodeTypeName);
		visual_transferout(_Context->buffer_NodeCategory, 59, pNodeCategory);
		visual_transferout(_Context->buffer_NodeImage, 59, pNodeImage);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_new_node_show(struct accept_new_node_context * _Context)
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto44,_Context->y_Auto44);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto44,_Context->y_Auto44,490,370,vfh[2],"Accords Manifest Editor: Define Node",strlen("Accords Manifest Editor: Define Node"),0x403);
	visual_frame(_Context->x_Auto44+140,_Context->y_Auto44+300,220,50,4);
	visual_text(_Context->x_Auto44+10,_Context->y_Auto44+30,462,16,vfh[2],16,0,"Node Name",strlen("Node Name"),2);
	visual_text(_Context->x_Auto44+10,_Context->y_Auto44+200,462,16,vfh[2],16,0,"Node Category",strlen("Node Category"),2);
	visual_text(_Context->x_Auto44+10,_Context->y_Auto44+250,462,16,vfh[2],16,0,"Node Image",strlen("Node Image"),2);
	visual_text(_Context->x_Auto44+10,_Context->y_Auto44+150,462,16,vfh[2],16,0,"Node Type Name",strlen("Node Type Name"),2);
	visual_text(_Context->x_Auto44+50,_Context->y_Auto44+90,110,16,vfh[2],16,0,"Node Access",strlen("Node Access"),3);
	visual_text(_Context->x_Auto44+190,_Context->y_Auto44+90,110,16,vfh[2],16,0,"Node Scope",strlen("Node Scope"),3);
	visual_text(_Context->x_Auto44+330,_Context->y_Auto44+90,110,16,vfh[2],16,0,"Node Type",strlen("Node Type"),3);
	visual_frame(_Context->x_Auto44+10,_Context->y_Auto44+50,472+2,16+2,5);
	visual_text(_Context->x_Auto44+10+1,_Context->y_Auto44+50+1,472,16,vfh[1],16,15,_Context->buffer_NodeName,59,0);
	visual_select(_Context->x_Auto44+50,_Context->y_Auto44+110,110,48,vfh[1],27,28,parse_selection("Private|Public",&_Context->value_NodeAccess),0);
	visual_select(_Context->x_Auto44+190,_Context->y_Auto44+110,110,48,vfh[1],27,28,parse_selection("Normal|Common",&_Context->value_NodeScope),0);
	visual_select(_Context->x_Auto44+330,_Context->y_Auto44+110,110,48,vfh[1],27,28,parse_selection("Simple |Complex",&_Context->value_NodeType),0);
	visual_frame(_Context->x_Auto44+10,_Context->y_Auto44+170,472+2,16+2,5);
	visual_text(_Context->x_Auto44+10+1,_Context->y_Auto44+170+1,472,16,vfh[1],16,15,_Context->buffer_NodeTypeName,59,0);
	visual_frame(_Context->x_Auto44+10,_Context->y_Auto44+220,472+2,16+2,5);
	visual_text(_Context->x_Auto44+10+1,_Context->y_Auto44+220+1,472,16,vfh[1],16,15,_Context->buffer_NodeCategory,59,0);
	visual_frame(_Context->x_Auto44+10,_Context->y_Auto44+270,472+2,16+2,5);
	visual_text(_Context->x_Auto44+10+1,_Context->y_Auto44+270+1,472,16,vfh[1],16,15,_Context->buffer_NodeImage,59,0);
	visual_button(_Context->x_Auto44+150,_Context->y_Auto44+310,98,32,vfh[2],27,28,"Accept",strlen("Accept"),0);
	visual_button(_Context->x_Auto44+250,_Context->y_Auto44+310,98,32,vfh[2],27,28,"Cancel",strlen("Cancel"),0);
	visual_thaw(_Context->x_Auto44,_Context->y_Auto44,490,370);

	return(0);
}
private int on_Accept_event(struct accept_new_node_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_new_node_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_new_node_event(
struct accept_new_node_context * _Context){
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto44+469) )  
	&&  (my >= (_Context->y_Auto44+4) )  
	&&  (mx <= (_Context->x_Auto44+486) )  
	&&  (my <= (_Context->y_Auto44+20) )) {
		return(1);	/* Auto44 */

		}
	if ((mx >= (_Context->x_Auto44+453) )  
	&&  (my >= (_Context->y_Auto44+4) )  
	&&  (mx <= (_Context->x_Auto44+470) )  
	&&  (my <= (_Context->y_Auto44+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("newnode.htm");
			};
		return(-1);	/* Auto44 */

		}
		}
	if (( mx >= (_Context->x_Auto44+10) ) 
	&&  ( my >= (_Context->y_Auto44+50) ) 
	&&  ( mx <= (_Context->x_Auto44+10+472) ) 
	&&  ( my <= (_Context->y_Auto44+50+16))) {
		return(2); /* NodeName */
		}
	if (( mx >= (_Context->x_Auto44+50+0) ) 
	&&  ( my >= (_Context->y_Auto44+110) ) 
	&&  ( mx <= (_Context->x_Auto44+50+110) ) 
	&&  ( my <= (_Context->y_Auto44+110+16))) {
		return(3); /* NodeAccess */
		}
	if (( mx >= (_Context->x_Auto44+190+0) ) 
	&&  ( my >= (_Context->y_Auto44+110) ) 
	&&  ( mx <= (_Context->x_Auto44+190+110) ) 
	&&  ( my <= (_Context->y_Auto44+110+16))) {
		return(4); /* NodeScope */
		}
	if (( mx >= (_Context->x_Auto44+330+0) ) 
	&&  ( my >= (_Context->y_Auto44+110) ) 
	&&  ( mx <= (_Context->x_Auto44+330+110) ) 
	&&  ( my <= (_Context->y_Auto44+110+16))) {
		return(5); /* NodeType */
		}
	if (( mx >= (_Context->x_Auto44+10) ) 
	&&  ( my >= (_Context->y_Auto44+170) ) 
	&&  ( mx <= (_Context->x_Auto44+10+472) ) 
	&&  ( my <= (_Context->y_Auto44+170+16))) {
		return(6); /* NodeTypeName */
		}
	if (( mx >= (_Context->x_Auto44+10) ) 
	&&  ( my >= (_Context->y_Auto44+220) ) 
	&&  ( mx <= (_Context->x_Auto44+10+472) ) 
	&&  ( my <= (_Context->y_Auto44+220+16))) {
		return(7); /* NodeCategory */
		}
	if (( mx >= (_Context->x_Auto44+10) ) 
	&&  ( my >= (_Context->y_Auto44+270) ) 
	&&  ( mx <= (_Context->x_Auto44+10+472) ) 
	&&  ( my <= (_Context->y_Auto44+270+16))) {
		return(8); /* NodeImage */
		}
	if (( mx >= (_Context->x_Auto44+150) ) 
	&&  ( my >= (_Context->y_Auto44+310) ) 
	&&  ( mx <= (_Context->x_Auto44+150+98) ) 
	&&  ( my <= (_Context->y_Auto44+310+32))) {
		return(9); /* Accept */
		}
	if (( mx >= (_Context->x_Auto44+250) ) 
	&&  ( my >= (_Context->y_Auto44+310) ) 
	&&  ( mx <= (_Context->x_Auto44+250+98) ) 
	&&  ( my <= (_Context->y_Auto44+310+32))) {
		return(10); /* Cancel */
		}

	return(-1);
}


public	int	accept_new_node_focus(struct accept_new_node_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* NodeName */
				_Context->keycode = visual_edit(_Context->x_Auto44+10+1,_Context->y_Auto44+50+1,472,16,vfh[1],_Context->buffer_NodeName,59);
			break;
			case	0x3 :
				/* NodeAccess */
				_Context->keycode = visual_select(_Context->x_Auto44+50,_Context->y_Auto44+110,110,48,vfh[1],27,28,parse_selection("Private|Public",&_Context->value_NodeAccess),2);
				break;
			case	0x4 :
				/* NodeScope */
				_Context->keycode = visual_select(_Context->x_Auto44+190,_Context->y_Auto44+110,110,48,vfh[1],27,28,parse_selection("Normal|Common",&_Context->value_NodeScope),2);
				break;
			case	0x5 :
				/* NodeType */
				_Context->keycode = visual_select(_Context->x_Auto44+330,_Context->y_Auto44+110,110,48,vfh[1],27,28,parse_selection("Simple |Complex",&_Context->value_NodeType),2);
				break;
			case	0x6 :
				/* NodeTypeName */
				_Context->keycode = visual_edit(_Context->x_Auto44+10+1,_Context->y_Auto44+170+1,472,16,vfh[1],_Context->buffer_NodeTypeName,59);
			break;
			case	0x7 :
				/* NodeCategory */
				_Context->keycode = visual_edit(_Context->x_Auto44+10+1,_Context->y_Auto44+220+1,472,16,vfh[1],_Context->buffer_NodeCategory,59);
			break;
			case	0x8 :
				/* NodeImage */
				_Context->keycode = visual_edit(_Context->x_Auto44+10+1,_Context->y_Auto44+270+1,472,16,vfh[1],_Context->buffer_NodeImage,59);
			break;
			case	0x9 :
				/* Accept */
				visual_button(_Context->x_Auto44+150,_Context->y_Auto44+310,98,32,vfh[2],27,28,"Accept",strlen("Accept"),2);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto44+150,_Context->y_Auto44+310,98,32,vfh[2],27,28,"Accept",strlen("Accept"),0);
				break;
			case	0xa :
				/* Cancel */
				visual_button(_Context->x_Auto44+250,_Context->y_Auto44+310,98,32,vfh[2],27,28,"Cancel",strlen("Cancel"),2);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto44+250,_Context->y_Auto44+310,98,32,vfh[2],27,28,"Cancel",strlen("Cancel"),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_new_node_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=10;
			accept_new_node_show(_Context);
			continue;
		case	0x100 :
			if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
			if ((retcode=accept_new_node_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto44 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* NodeName */
					continue;
				case	0x3 :
					/* NodeAccess */
					continue;
				case	0x4 :
					/* NodeScope */
					continue;
				case	0x5 :
					/* NodeType */
					continue;
				case	0x6 :
					/* NodeTypeName */
					continue;
				case	0x7 :
					/* NodeCategory */
					continue;
				case	0x8 :
					/* NodeImage */
					continue;
				case	0x9 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto44+150,_Context->y_Auto44+310,98,32,vfh[2],27,28,"Accept",strlen("Accept"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto44+150,_Context->y_Auto44+310,98,32,vfh[2],27,28,"Accept",strlen("Accept"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto44+250,_Context->y_Auto44+310,98,32,vfh[2],27,28,"Cancel",strlen("Cancel"),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto44+250,_Context->y_Auto44+310,98,32,vfh[2],27,28,"Cancel",strlen("Cancel"),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

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
				_Context->focus_item=10;
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

public	int	accept_new_node(
	char * pNodeName,
	char * pNodeAccess,
	char * pNodeScope,
	char * pNodeType,
	char * pNodeTypeName,
	char * pNodeCategory,
	char * pNodeImage)
{
	int	status=0;
	struct accept_new_node_context * _Context=(struct accept_new_node_context*) 0;
	status = accept_new_node_create(
	&_Context,
	 pNodeName,
	 pNodeAccess,
	 pNodeScope,
	 pNodeType,
	 pNodeTypeName,
	 pNodeCategory,
	 pNodeImage);
	if ( status != 0) return(status);
	status = accept_new_node_show(_Context);
		enter_modal();
	status = accept_new_node_focus(_Context);
		leave_modal();
	status = accept_new_node_hide(_Context);
	status = accept_new_node_remove(
	_Context,
	 pNodeName,
	 pNodeAccess,
	 pNodeScope,
	 pNodeType,
	 pNodeTypeName,
	 pNodeCategory,
	 pNodeImage);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _newnode_c */
