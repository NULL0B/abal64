
#ifndef _vbase_c
#define _vbase_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : vbase.xml                                                */
/* Target         : vbase.c                                                  */
/* Identification : 0.0-1196372561-3079.3078                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto3331   ""
#define en_Auto3332   "Model Editor Options Configuration"
#define en__Auto3332   ""
#define en_HyperSpace   "Hyperview Active"
#define fr_HyperSpace   "Hyperview Active"
#define it_HyperSpace   "Hyperview Active"
#define es_HyperSpace   "Hyperview Active"
#define de_HyperSpace   "Hyperview Active"
#define nl_HyperSpace   "Hyperview Active"
#define pt_HyperSpace   "Hyperview Active"
#define xx_HyperSpace   "Hyperview Active"
#define en__HyperSpace   ""
#define fr__HyperSpace   ""
#define it__HyperSpace   ""
#define es__HyperSpace   ""
#define de__HyperSpace   ""
#define nl__HyperSpace   ""
#define pt__HyperSpace   ""
#define xx__HyperSpace   ""
#define en_HelpBubble   "Help Bubbles Active"
#define fr_HelpBubble   "Help Bubbles Active"
#define it_HelpBubble   "Help Bubbles Active"
#define es_HelpBubble   "Help Bubbles Active"
#define de_HelpBubble   "Help Bubbles Active"
#define nl_HelpBubble   "Help Bubbles Active"
#define pt_HelpBubble   "Help Bubbles Active"
#define xx_HelpBubble   "Help Bubbles Active"
#define en__HelpBubble   ""
#define fr__HelpBubble   ""
#define it__HelpBubble   ""
#define es__HelpBubble   ""
#define de__HelpBubble   ""
#define nl__HelpBubble   ""
#define pt__HelpBubble   ""
#define xx__HelpBubble   ""
#define en_Bender   "Diagonal|Direct|Routed"
#define fr_Bender   "Diagonal|Direct|Routed"
#define it_Bender   "Diagonal|Direct|Routed"
#define es_Bender   "Diagonal|Direct|Routed"
#define de_Bender   "Diagonal|Direct|Routed"
#define nl_Bender   "Diagonal|Direct|Routed"
#define pt_Bender   "Diagonal|Direct|Routed"
#define xx_Bender   "Diagonal|Direct|Routed"
#define en__Bender   ""
#define fr__Bender   ""
#define it__Bender   ""
#define es__Bender   ""
#define de__Bender   ""
#define nl__Bender   ""
#define pt__Bender   ""
#define xx__Bender   ""
#define en_TraceWidth   ""
#define en__TraceWidth   ""
#define en_TraceColour   ""
#define en__TraceColour   ""
#define en_Depth   ""
#define en__Depth   ""
#define en_TracePadding   ""
#define en__TracePadding   ""
#define en_xPadding   ""
#define en__xPadding   ""
#define en_yPadding   ""
#define en__yPadding   ""
#define en_Fraction   ""
#define en__Fraction   ""
#define en_Schema   "None|Sing|Merise|Uml"
#define fr_Schema   "None|Sing|Merise|Uml"
#define it_Schema   "None|Sing|Merise|Uml"
#define es_Schema   "None|Sing|Merise|Uml"
#define de_Schema   "None|Sing|Merise|Uml"
#define nl_Schema   "None|Sing|Merise|Uml"
#define pt_Schema   "None|Sing|Merise|Uml"
#define xx_Schema   "None|Sing|Merise|Uml"
#define en__Schema   ""
#define fr__Schema   ""
#define it__Schema   ""
#define es__Schema   ""
#define de__Schema   ""
#define nl__Schema   ""
#define pt__Schema   ""
#define xx__Schema   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en__Accept   ""
#define fr__Accept   ""
#define it__Accept   ""
#define es__Accept   ""
#define de__Accept   ""
#define nl__Accept   ""
#define pt__Accept   ""
#define xx__Accept   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""
#define fr__Cancel   ""
#define it__Cancel   ""
#define es__Cancel   ""
#define de__Cancel   ""
#define nl__Cancel   ""
#define pt__Cancel   ""
#define xx__Cancel   ""
#define en_Auto3335   "Trace Links"
#define fr_Auto3335   "Trace Links"
#define it_Auto3335   "Trace Links"
#define es_Auto3335   "Trace Links"
#define de_Auto3335   "Trace Links"
#define nl_Auto3335   "Trace Links"
#define pt_Auto3335   "Trace Links"
#define xx_Auto3335   "Trace Links"
#define en__Auto3335   ""
#define fr__Auto3335   ""
#define it__Auto3335   ""
#define es__Auto3335   ""
#define de__Auto3335   ""
#define nl__Auto3335   ""
#define pt__Auto3335   ""
#define xx__Auto3335   ""
#define en_Auto3336   "Representation"
#define en__Auto3336   ""
#define en_Auto3337   "Trace Width"
#define fr_Auto3337   "Trace Width"
#define it_Auto3337   "Trace Width"
#define es_Auto3337   "Trace Width"
#define de_Auto3337   "Trace Width"
#define nl_Auto3337   "Trace Width"
#define pt_Auto3337   "Trace Width"
#define xx_Auto3337   "Trace Width"
#define en__Auto3337   ""
#define fr__Auto3337   ""
#define it__Auto3337   ""
#define es__Auto3337   ""
#define de__Auto3337   ""
#define nl__Auto3337   ""
#define pt__Auto3337   ""
#define xx__Auto3337   ""
#define en_Auto3338   "Trace Colour"
#define fr_Auto3338   "Trace Colour"
#define it_Auto3338   "Trace Colour"
#define es_Auto3338   "Trace Colour"
#define de_Auto3338   "Trace Colour"
#define nl_Auto3338   "Trace Colour"
#define pt_Auto3338   "Trace Colour"
#define xx_Auto3338   "Trace Colour"
#define en__Auto3338   ""
#define fr__Auto3338   ""
#define it__Auto3338   ""
#define es__Auto3338   ""
#define de__Auto3338   ""
#define nl__Auto3338   ""
#define pt__Auto3338   ""
#define xx__Auto3338   ""
#define en_Auto3339   "Recursion Depth"
#define fr_Auto3339   "Recursion Depth"
#define it_Auto3339   "Recursion Depth"
#define es_Auto3339   "Recursion Depth"
#define de_Auto3339   "Recursion Depth"
#define nl_Auto3339   "Recursion Depth"
#define pt_Auto3339   "Recursion Depth"
#define xx_Auto3339   "Recursion Depth"
#define en__Auto3339   ""
#define fr__Auto3339   ""
#define it__Auto3339   ""
#define es__Auto3339   ""
#define de__Auto3339   ""
#define nl__Auto3339   ""
#define pt__Auto3339   ""
#define xx__Auto3339   ""
#define en_Auto3340   "Trace Padding"
#define fr_Auto3340   "Trace Padding"
#define it_Auto3340   "Trace Padding"
#define es_Auto3340   "Trace Padding"
#define de_Auto3340   "Trace Padding"
#define nl_Auto3340   "Trace Padding"
#define pt_Auto3340   "Trace Padding"
#define xx_Auto3340   "Trace Padding"
#define en__Auto3340   ""
#define fr__Auto3340   ""
#define it__Auto3340   ""
#define es__Auto3340   ""
#define de__Auto3340   ""
#define nl__Auto3340   ""
#define pt__Auto3340   ""
#define xx__Auto3340   ""
#define en_Auto3341   "Horizontal Model Padding"
#define fr_Auto3341   "Horizontal Model Padding"
#define it_Auto3341   "Horizontal Model Padding"
#define es_Auto3341   "Horizontal Model Padding"
#define de_Auto3341   "Horizontal Model Padding"
#define nl_Auto3341   "Horizontal Model Padding"
#define pt_Auto3341   "Horizontal Model Padding"
#define xx_Auto3341   "Horizontal Model Padding"
#define en__Auto3341   ""
#define fr__Auto3341   ""
#define it__Auto3341   ""
#define es__Auto3341   ""
#define de__Auto3341   ""
#define nl__Auto3341   ""
#define pt__Auto3341   ""
#define xx__Auto3341   ""
#define en_Auto3342   "Vertical Model Padding"
#define fr_Auto3342   "Vertical Model Padding"
#define it_Auto3342   "Vertical Model Padding"
#define es_Auto3342   "Vertical Model Padding"
#define de_Auto3342   "Vertical Model Padding"
#define nl_Auto3342   "Vertical Model Padding"
#define pt_Auto3342   "Vertical Model Padding"
#define xx_Auto3342   "Vertical Model Padding"
#define en__Auto3342   ""
#define fr__Auto3342   ""
#define it__Auto3342   ""
#define es__Auto3342   ""
#define de__Auto3342   ""
#define nl__Auto3342   ""
#define pt__Auto3342   ""
#define xx__Auto3342   ""
#define en_Auto3343   "Hyperview Fraction  :   1 /"
#define fr_Auto3343   "Hyperview Fraction    1 /"
#define it_Auto3343   "Hyperview Fraction    1 /"
#define es_Auto3343   "Hyperview Fraction    1 /"
#define de_Auto3343   "Hyperview Fraction    1 /"
#define nl_Auto3343   "Hyperview Fraction    1 /"
#define pt_Auto3343   "Hyperview Fraction    1 /"
#define xx_Auto3343   "Hyperview Fraction    1 /"
#define en__Auto3343   ""
#define fr__Auto3343   ""
#define it__Auto3343   ""
#define es__Auto3343   ""
#define de__Auto3343   ""
#define nl__Auto3343   ""
#define pt__Auto3343   ""
#define xx__Auto3343   ""

private struct accept_database_control_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3331[8];
	char * hint_Auto3331[8];
	int	x_Auto3331;
	int	y_Auto3331;
	int	w_Auto3331;
	int	h_Auto3331;
	char * msg_Auto3332[8];
	char * hint_Auto3332[8];
	char * hint_Auto3333[8];
	char * hint_Auto3334[8];
	char * msg_HyperSpace[8];
	int	trigger_HyperSpace;
	char * hint_HyperSpace[8];
	int	value_HyperSpace;
	char * msg_HelpBubble[8];
	int	trigger_HelpBubble;
	char * hint_HelpBubble[8];
	int	value_HelpBubble;
	char * msg_Bender[8];
	char * hint_Bender[8];
	int	value_Bender;
	char * hint_TraceWidth[8];
	char	buffer_TraceWidth[8];
	char * hint_TraceColour[8];
	char	buffer_TraceColour[8];
	char * hint_Depth[8];
	char	buffer_Depth[8];
	char * hint_TracePadding[8];
	char	buffer_TracePadding[8];
	char * hint_xPadding[8];
	char	buffer_xPadding[8];
	char * hint_yPadding[8];
	char	buffer_yPadding[8];
	char * hint_Fraction[8];
	char	buffer_Fraction[8];
	char * msg_Schema[8];
	char * hint_Schema[8];
	int	value_Schema;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	char * msg_Auto3335[8];
	char * hint_Auto3335[8];
	char * msg_Auto3336[8];
	char * hint_Auto3336[8];
	char * msg_Auto3337[8];
	char * hint_Auto3337[8];
	char * msg_Auto3338[8];
	char * hint_Auto3338[8];
	char * msg_Auto3339[8];
	char * hint_Auto3339[8];
	char * msg_Auto3340[8];
	char * hint_Auto3340[8];
	char * msg_Auto3341[8];
	char * hint_Auto3341[8];
	char * msg_Auto3342[8];
	char * hint_Auto3342[8];
	char * msg_Auto3343[8];
	char * hint_Auto3343[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[12];
	};
static int	vfh[16];

public	int	accept_database_control_create(
	struct accept_database_control_context ** cptr,
	char * pHyperSpace,
	char * pHelpBubble,
	char * pBender,
	char * pTraceWidth,
	char * pTraceColour,
	char * pDepth,
	char * pTracePadding,
	char * pxPadding,
	char * pyPadding,
	char * pFraction,
	char * pSchema)
{

	int i;
	struct accept_database_control_context * _Context=(struct accept_database_control_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_database_control_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=14;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pHyperSpace);
		if (!( pHyperSpace )) _Context->value_HyperSpace=0;
		else	_Context->value_HyperSpace = *((int *)pHyperSpace);
		visual_transferin((void *) 0, 0, pHelpBubble);
		if (!( pHelpBubble )) _Context->value_HelpBubble=0;
		else	_Context->value_HelpBubble = *((int *)pHelpBubble);
		visual_transferin((void *) 0, 0, pBender);
		if (!( pBender )) _Context->value_Bender=0;
		else	_Context->value_Bender = *((int *)pBender);
		visual_transferin(_Context->buffer_TraceWidth, 7, pTraceWidth);
		visual_transferin(_Context->buffer_TraceColour, 7, pTraceColour);
		visual_transferin(_Context->buffer_Depth, 7, pDepth);
		visual_transferin(_Context->buffer_TracePadding, 7, pTracePadding);
		visual_transferin(_Context->buffer_xPadding, 7, pxPadding);
		visual_transferin(_Context->buffer_yPadding, 7, pyPadding);
		visual_transferin(_Context->buffer_Fraction, 7, pFraction);
		visual_transferin((void *) 0, 0, pSchema);
		if (!( pSchema )) _Context->value_Schema=0;
		else	_Context->value_Schema = *((int *)pSchema);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3331[i]=" ";
	_Context->hint_Auto3331[0]=en__Auto3331;
	_Context->x_Auto3331=260;
	_Context->y_Auto3331=85;
	_Context->w_Auto3331=280;
	_Context->h_Auto3331=430;
	_Context->window_col=0;
	_Context->window_row=0;
	if(((_Context->y_Auto3331=visual_event(6))+430)>hardrows())
	_Context->y_Auto3331=(hardrows()-430);
	if(((_Context->x_Auto3331=visual_event(7))+280)>hardcolumns())
	_Context->x_Auto3331=(hardcolumns()-280);
	for (i=0; i < 8; i++)_Context->msg_Auto3332[i]=" ";
	_Context->msg_Auto3332[0]=en_Auto3332;
	_Context->hint_Auto3332[0]=en__Auto3332;
	for (i=0; i < 8; i++)_Context->msg_HyperSpace[i]=" ";
	_Context->msg_HyperSpace[0]=en_HyperSpace;
	_Context->msg_HyperSpace[1]=fr_HyperSpace;
	_Context->msg_HyperSpace[2]=it_HyperSpace;
	_Context->msg_HyperSpace[3]=es_HyperSpace;
	_Context->msg_HyperSpace[4]=de_HyperSpace;
	_Context->msg_HyperSpace[5]=nl_HyperSpace;
	_Context->msg_HyperSpace[6]=pt_HyperSpace;
	_Context->msg_HyperSpace[7]=xx_HyperSpace;
	_Context->hint_HyperSpace[0]=en__HyperSpace;
	_Context->hint_HyperSpace[1]=fr__HyperSpace;
	_Context->hint_HyperSpace[2]=it__HyperSpace;
	_Context->hint_HyperSpace[3]=es__HyperSpace;
	_Context->hint_HyperSpace[4]=de__HyperSpace;
	_Context->hint_HyperSpace[5]=nl__HyperSpace;
	_Context->hint_HyperSpace[6]=pt__HyperSpace;
	_Context->hint_HyperSpace[7]=xx__HyperSpace;
	for (i=0; i < 8; i++)_Context->msg_HelpBubble[i]=" ";
	_Context->msg_HelpBubble[0]=en_HelpBubble;
	_Context->msg_HelpBubble[1]=fr_HelpBubble;
	_Context->msg_HelpBubble[2]=it_HelpBubble;
	_Context->msg_HelpBubble[3]=es_HelpBubble;
	_Context->msg_HelpBubble[4]=de_HelpBubble;
	_Context->msg_HelpBubble[5]=nl_HelpBubble;
	_Context->msg_HelpBubble[6]=pt_HelpBubble;
	_Context->msg_HelpBubble[7]=xx_HelpBubble;
	_Context->hint_HelpBubble[0]=en__HelpBubble;
	_Context->hint_HelpBubble[1]=fr__HelpBubble;
	_Context->hint_HelpBubble[2]=it__HelpBubble;
	_Context->hint_HelpBubble[3]=es__HelpBubble;
	_Context->hint_HelpBubble[4]=de__HelpBubble;
	_Context->hint_HelpBubble[5]=nl__HelpBubble;
	_Context->hint_HelpBubble[6]=pt__HelpBubble;
	_Context->hint_HelpBubble[7]=xx__HelpBubble;
	for (i=0; i < 8; i++)_Context->msg_Bender[i]=" ";
	_Context->msg_Bender[0]=en_Bender;
	_Context->msg_Bender[1]=fr_Bender;
	_Context->msg_Bender[2]=it_Bender;
	_Context->msg_Bender[3]=es_Bender;
	_Context->msg_Bender[4]=de_Bender;
	_Context->msg_Bender[5]=nl_Bender;
	_Context->msg_Bender[6]=pt_Bender;
	_Context->msg_Bender[7]=xx_Bender;
	_Context->hint_Bender[0]=en__Bender;
	_Context->hint_Bender[1]=fr__Bender;
	_Context->hint_Bender[2]=it__Bender;
	_Context->hint_Bender[3]=es__Bender;
	_Context->hint_Bender[4]=de__Bender;
	_Context->hint_Bender[5]=nl__Bender;
	_Context->hint_Bender[6]=pt__Bender;
	_Context->hint_Bender[7]=xx__Bender;
	_Context->hint_TraceWidth[0]=en__TraceWidth;
	_Context->hint_TraceColour[0]=en__TraceColour;
	_Context->hint_Depth[0]=en__Depth;
	_Context->hint_TracePadding[0]=en__TracePadding;
	_Context->hint_xPadding[0]=en__xPadding;
	_Context->hint_yPadding[0]=en__yPadding;
	_Context->hint_Fraction[0]=en__Fraction;
	for (i=0; i < 8; i++)_Context->msg_Schema[i]=" ";
	_Context->msg_Schema[0]=en_Schema;
	_Context->msg_Schema[1]=fr_Schema;
	_Context->msg_Schema[2]=it_Schema;
	_Context->msg_Schema[3]=es_Schema;
	_Context->msg_Schema[4]=de_Schema;
	_Context->msg_Schema[5]=nl_Schema;
	_Context->msg_Schema[6]=pt_Schema;
	_Context->msg_Schema[7]=xx_Schema;
	_Context->hint_Schema[0]=en__Schema;
	_Context->hint_Schema[1]=fr__Schema;
	_Context->hint_Schema[2]=it__Schema;
	_Context->hint_Schema[3]=es__Schema;
	_Context->hint_Schema[4]=de__Schema;
	_Context->hint_Schema[5]=nl__Schema;
	_Context->hint_Schema[6]=pt__Schema;
	_Context->hint_Schema[7]=xx__Schema;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	_Context->hint_Accept[0]=en__Accept;
	_Context->hint_Accept[1]=fr__Accept;
	_Context->hint_Accept[2]=it__Accept;
	_Context->hint_Accept[3]=es__Accept;
	_Context->hint_Accept[4]=de__Accept;
	_Context->hint_Accept[5]=nl__Accept;
	_Context->hint_Accept[6]=pt__Accept;
	_Context->hint_Accept[7]=xx__Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	_Context->hint_Cancel[0]=en__Cancel;
	_Context->hint_Cancel[1]=fr__Cancel;
	_Context->hint_Cancel[2]=it__Cancel;
	_Context->hint_Cancel[3]=es__Cancel;
	_Context->hint_Cancel[4]=de__Cancel;
	_Context->hint_Cancel[5]=nl__Cancel;
	_Context->hint_Cancel[6]=pt__Cancel;
	_Context->hint_Cancel[7]=xx__Cancel;
	for (i=0; i < 8; i++)_Context->msg_Auto3335[i]=" ";
	_Context->msg_Auto3335[0]=en_Auto3335;
	_Context->msg_Auto3335[1]=fr_Auto3335;
	_Context->msg_Auto3335[2]=it_Auto3335;
	_Context->msg_Auto3335[3]=es_Auto3335;
	_Context->msg_Auto3335[4]=de_Auto3335;
	_Context->msg_Auto3335[5]=nl_Auto3335;
	_Context->msg_Auto3335[6]=pt_Auto3335;
	_Context->msg_Auto3335[7]=xx_Auto3335;
	_Context->hint_Auto3335[0]=en__Auto3335;
	_Context->hint_Auto3335[1]=fr__Auto3335;
	_Context->hint_Auto3335[2]=it__Auto3335;
	_Context->hint_Auto3335[3]=es__Auto3335;
	_Context->hint_Auto3335[4]=de__Auto3335;
	_Context->hint_Auto3335[5]=nl__Auto3335;
	_Context->hint_Auto3335[6]=pt__Auto3335;
	_Context->hint_Auto3335[7]=xx__Auto3335;
	for (i=0; i < 8; i++)_Context->msg_Auto3336[i]=" ";
	_Context->msg_Auto3336[0]=en_Auto3336;
	_Context->hint_Auto3336[0]=en__Auto3336;
	for (i=0; i < 8; i++)_Context->msg_Auto3337[i]=" ";
	_Context->msg_Auto3337[0]=en_Auto3337;
	_Context->msg_Auto3337[1]=fr_Auto3337;
	_Context->msg_Auto3337[2]=it_Auto3337;
	_Context->msg_Auto3337[3]=es_Auto3337;
	_Context->msg_Auto3337[4]=de_Auto3337;
	_Context->msg_Auto3337[5]=nl_Auto3337;
	_Context->msg_Auto3337[6]=pt_Auto3337;
	_Context->msg_Auto3337[7]=xx_Auto3337;
	_Context->hint_Auto3337[0]=en__Auto3337;
	_Context->hint_Auto3337[1]=fr__Auto3337;
	_Context->hint_Auto3337[2]=it__Auto3337;
	_Context->hint_Auto3337[3]=es__Auto3337;
	_Context->hint_Auto3337[4]=de__Auto3337;
	_Context->hint_Auto3337[5]=nl__Auto3337;
	_Context->hint_Auto3337[6]=pt__Auto3337;
	_Context->hint_Auto3337[7]=xx__Auto3337;
	for (i=0; i < 8; i++)_Context->msg_Auto3338[i]=" ";
	_Context->msg_Auto3338[0]=en_Auto3338;
	_Context->msg_Auto3338[1]=fr_Auto3338;
	_Context->msg_Auto3338[2]=it_Auto3338;
	_Context->msg_Auto3338[3]=es_Auto3338;
	_Context->msg_Auto3338[4]=de_Auto3338;
	_Context->msg_Auto3338[5]=nl_Auto3338;
	_Context->msg_Auto3338[6]=pt_Auto3338;
	_Context->msg_Auto3338[7]=xx_Auto3338;
	_Context->hint_Auto3338[0]=en__Auto3338;
	_Context->hint_Auto3338[1]=fr__Auto3338;
	_Context->hint_Auto3338[2]=it__Auto3338;
	_Context->hint_Auto3338[3]=es__Auto3338;
	_Context->hint_Auto3338[4]=de__Auto3338;
	_Context->hint_Auto3338[5]=nl__Auto3338;
	_Context->hint_Auto3338[6]=pt__Auto3338;
	_Context->hint_Auto3338[7]=xx__Auto3338;
	for (i=0; i < 8; i++)_Context->msg_Auto3339[i]=" ";
	_Context->msg_Auto3339[0]=en_Auto3339;
	_Context->msg_Auto3339[1]=fr_Auto3339;
	_Context->msg_Auto3339[2]=it_Auto3339;
	_Context->msg_Auto3339[3]=es_Auto3339;
	_Context->msg_Auto3339[4]=de_Auto3339;
	_Context->msg_Auto3339[5]=nl_Auto3339;
	_Context->msg_Auto3339[6]=pt_Auto3339;
	_Context->msg_Auto3339[7]=xx_Auto3339;
	_Context->hint_Auto3339[0]=en__Auto3339;
	_Context->hint_Auto3339[1]=fr__Auto3339;
	_Context->hint_Auto3339[2]=it__Auto3339;
	_Context->hint_Auto3339[3]=es__Auto3339;
	_Context->hint_Auto3339[4]=de__Auto3339;
	_Context->hint_Auto3339[5]=nl__Auto3339;
	_Context->hint_Auto3339[6]=pt__Auto3339;
	_Context->hint_Auto3339[7]=xx__Auto3339;
	for (i=0; i < 8; i++)_Context->msg_Auto3340[i]=" ";
	_Context->msg_Auto3340[0]=en_Auto3340;
	_Context->msg_Auto3340[1]=fr_Auto3340;
	_Context->msg_Auto3340[2]=it_Auto3340;
	_Context->msg_Auto3340[3]=es_Auto3340;
	_Context->msg_Auto3340[4]=de_Auto3340;
	_Context->msg_Auto3340[5]=nl_Auto3340;
	_Context->msg_Auto3340[6]=pt_Auto3340;
	_Context->msg_Auto3340[7]=xx_Auto3340;
	_Context->hint_Auto3340[0]=en__Auto3340;
	_Context->hint_Auto3340[1]=fr__Auto3340;
	_Context->hint_Auto3340[2]=it__Auto3340;
	_Context->hint_Auto3340[3]=es__Auto3340;
	_Context->hint_Auto3340[4]=de__Auto3340;
	_Context->hint_Auto3340[5]=nl__Auto3340;
	_Context->hint_Auto3340[6]=pt__Auto3340;
	_Context->hint_Auto3340[7]=xx__Auto3340;
	for (i=0; i < 8; i++)_Context->msg_Auto3341[i]=" ";
	_Context->msg_Auto3341[0]=en_Auto3341;
	_Context->msg_Auto3341[1]=fr_Auto3341;
	_Context->msg_Auto3341[2]=it_Auto3341;
	_Context->msg_Auto3341[3]=es_Auto3341;
	_Context->msg_Auto3341[4]=de_Auto3341;
	_Context->msg_Auto3341[5]=nl_Auto3341;
	_Context->msg_Auto3341[6]=pt_Auto3341;
	_Context->msg_Auto3341[7]=xx_Auto3341;
	_Context->hint_Auto3341[0]=en__Auto3341;
	_Context->hint_Auto3341[1]=fr__Auto3341;
	_Context->hint_Auto3341[2]=it__Auto3341;
	_Context->hint_Auto3341[3]=es__Auto3341;
	_Context->hint_Auto3341[4]=de__Auto3341;
	_Context->hint_Auto3341[5]=nl__Auto3341;
	_Context->hint_Auto3341[6]=pt__Auto3341;
	_Context->hint_Auto3341[7]=xx__Auto3341;
	for (i=0; i < 8; i++)_Context->msg_Auto3342[i]=" ";
	_Context->msg_Auto3342[0]=en_Auto3342;
	_Context->msg_Auto3342[1]=fr_Auto3342;
	_Context->msg_Auto3342[2]=it_Auto3342;
	_Context->msg_Auto3342[3]=es_Auto3342;
	_Context->msg_Auto3342[4]=de_Auto3342;
	_Context->msg_Auto3342[5]=nl_Auto3342;
	_Context->msg_Auto3342[6]=pt_Auto3342;
	_Context->msg_Auto3342[7]=xx_Auto3342;
	_Context->hint_Auto3342[0]=en__Auto3342;
	_Context->hint_Auto3342[1]=fr__Auto3342;
	_Context->hint_Auto3342[2]=it__Auto3342;
	_Context->hint_Auto3342[3]=es__Auto3342;
	_Context->hint_Auto3342[4]=de__Auto3342;
	_Context->hint_Auto3342[5]=nl__Auto3342;
	_Context->hint_Auto3342[6]=pt__Auto3342;
	_Context->hint_Auto3342[7]=xx__Auto3342;
	for (i=0; i < 8; i++)_Context->msg_Auto3343[i]=" ";
	_Context->msg_Auto3343[0]=en_Auto3343;
	_Context->msg_Auto3343[1]=fr_Auto3343;
	_Context->msg_Auto3343[2]=it_Auto3343;
	_Context->msg_Auto3343[3]=es_Auto3343;
	_Context->msg_Auto3343[4]=de_Auto3343;
	_Context->msg_Auto3343[5]=nl_Auto3343;
	_Context->msg_Auto3343[6]=pt_Auto3343;
	_Context->msg_Auto3343[7]=xx_Auto3343;
	_Context->hint_Auto3343[0]=en__Auto3343;
	_Context->hint_Auto3343[1]=fr__Auto3343;
	_Context->hint_Auto3343[2]=it__Auto3343;
	_Context->hint_Auto3343[3]=es__Auto3343;
	_Context->hint_Auto3343[4]=de__Auto3343;
	_Context->hint_Auto3343[5]=nl__Auto3343;
	_Context->hint_Auto3343[6]=pt__Auto3343;
	_Context->hint_Auto3343[7]=xx__Auto3343;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3331,_Context->y_Auto3331,280+10,430+10);
	return(0);
}

public 	int	accept_database_control_hide(struct accept_database_control_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3331,_Context->y_Auto3331);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_database_control_remove(
	struct accept_database_control_context * _Context,
	char * pHyperSpace,
	char * pHelpBubble,
	char * pBender,
	char * pTraceWidth,
	char * pTraceColour,
	char * pDepth,
	char * pTracePadding,
	char * pxPadding,
	char * pyPadding,
	char * pFraction,
	char * pSchema)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pHyperSpace);
		if ( pHyperSpace != (char *) 0)
			*((int*)pHyperSpace) = _Context->value_HyperSpace;
		visual_transferout((void *) 0, 0, pHelpBubble);
		if ( pHelpBubble != (char *) 0)
			*((int*)pHelpBubble) = _Context->value_HelpBubble;
		visual_transferout((void *) 0, 0, pBender);
		if ( pBender != (char *) 0)
			*((int*)pBender) = _Context->value_Bender;
		visual_transferout(_Context->buffer_TraceWidth, 7, pTraceWidth);
		visual_transferout(_Context->buffer_TraceColour, 7, pTraceColour);
		visual_transferout(_Context->buffer_Depth, 7, pDepth);
		visual_transferout(_Context->buffer_TracePadding, 7, pTracePadding);
		visual_transferout(_Context->buffer_xPadding, 7, pxPadding);
		visual_transferout(_Context->buffer_yPadding, 7, pyPadding);
		visual_transferout(_Context->buffer_Fraction, 7, pFraction);
		visual_transferout((void *) 0, 0, pSchema);
		if ( pSchema != (char *) 0)
			*((int*)pSchema) = _Context->value_Schema;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_database_control_show(struct accept_database_control_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3331,_Context->y_Auto3331);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3331,_Context->y_Auto3331,280,430,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3331,_Context->y_Auto3331,280,430,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3331+20,_Context->y_Auto3331+30,238,32,vfh[2],16,0,_Context->msg_Auto3332[_Context->language],strlen(_Context->msg_Auto3332[_Context->language]),259);
	visual_frame(_Context->x_Auto3331+20,_Context->y_Auto3331+60,240,60,4);
	visual_frame(_Context->x_Auto3331+20,_Context->y_Auto3331+120,240,230,4);
	_Context->trigger_HyperSpace=visual_trigger_code(_Context->msg_HyperSpace[_Context->language],strlen(_Context->msg_HyperSpace[_Context->language]));
	visual_check(_Context->x_Auto3331+40,_Context->y_Auto3331+70,182,16,vfh[2],16,0,_Context->msg_HyperSpace[_Context->language],strlen(_Context->msg_HyperSpace[_Context->language]),_Context->value_HyperSpace|0);
	_Context->trigger_HelpBubble=visual_trigger_code(_Context->msg_HelpBubble[_Context->language],strlen(_Context->msg_HelpBubble[_Context->language]));
	visual_check(_Context->x_Auto3331+40,_Context->y_Auto3331+90,182,16,vfh[2],16,0,_Context->msg_HelpBubble[_Context->language],strlen(_Context->msg_HelpBubble[_Context->language]),_Context->value_HelpBubble|0);
	visual_select(_Context->x_Auto3331+140,_Context->y_Auto3331+140,110,80,vfh[2],16,0,parse_selection(_Context->msg_Bender[_Context->language],&_Context->value_Bender),768);
	visual_frame(_Context->x_Auto3331+190,_Context->y_Auto3331+200,56+2,16+2,5);
	visual_text(_Context->x_Auto3331+190+1,_Context->y_Auto3331+200+1,56,16,vfh[1],16,0,_Context->buffer_TraceWidth,7,0);
	visual_frame(_Context->x_Auto3331+190,_Context->y_Auto3331+220,56+2,16+2,5);
	visual_text(_Context->x_Auto3331+190+1,_Context->y_Auto3331+220+1,56,16,vfh[1],16,0,_Context->buffer_TraceColour,7,0);
	visual_frame(_Context->x_Auto3331+190,_Context->y_Auto3331+240,56+2,16+2,5);
	visual_text(_Context->x_Auto3331+190+1,_Context->y_Auto3331+240+1,56,16,vfh[1],16,0,_Context->buffer_Depth,7,0);
	visual_frame(_Context->x_Auto3331+190,_Context->y_Auto3331+260,56+2,16+2,5);
	visual_text(_Context->x_Auto3331+190+1,_Context->y_Auto3331+260+1,56,16,vfh[1],16,0,_Context->buffer_TracePadding,7,0);
	visual_frame(_Context->x_Auto3331+190,_Context->y_Auto3331+280,56+2,16+2,5);
	visual_text(_Context->x_Auto3331+190+1,_Context->y_Auto3331+280+1,56,16,vfh[1],16,0,_Context->buffer_xPadding,7,0);
	visual_frame(_Context->x_Auto3331+190,_Context->y_Auto3331+300,56+2,16+2,5);
	visual_text(_Context->x_Auto3331+190+1,_Context->y_Auto3331+300+1,56,16,vfh[1],16,0,_Context->buffer_yPadding,7,0);
	visual_frame(_Context->x_Auto3331+190,_Context->y_Auto3331+320,56+2,16+2,5);
	visual_text(_Context->x_Auto3331+190+1,_Context->y_Auto3331+320+1,56,16,vfh[1],16,0,_Context->buffer_Fraction,7,0);
	visual_select(_Context->x_Auto3331+140,_Context->y_Auto3331+170,110,70,vfh[2],0,0,parse_selection(_Context->msg_Schema[_Context->language],&_Context->value_Schema),768);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3331+20,_Context->y_Auto3331+360,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3331+200,_Context->y_Auto3331+360,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_text(_Context->x_Auto3331+30,_Context->y_Auto3331+140,112,16,vfh[2],16,0,_Context->msg_Auto3335[_Context->language],strlen(_Context->msg_Auto3335[_Context->language]),2);
	visual_text(_Context->x_Auto3331+30,_Context->y_Auto3331+170,112,16,vfh[2],16,0,_Context->msg_Auto3336[_Context->language],strlen(_Context->msg_Auto3336[_Context->language]),2);
	visual_text(_Context->x_Auto3331+30,_Context->y_Auto3331+200,112,16,vfh[2],16,0,_Context->msg_Auto3337[_Context->language],strlen(_Context->msg_Auto3337[_Context->language]),2);
	visual_text(_Context->x_Auto3331+30,_Context->y_Auto3331+220,112,16,vfh[2],16,0,_Context->msg_Auto3338[_Context->language],strlen(_Context->msg_Auto3338[_Context->language]),2);
	visual_text(_Context->x_Auto3331+30,_Context->y_Auto3331+240,112,16,vfh[2],16,0,_Context->msg_Auto3339[_Context->language],strlen(_Context->msg_Auto3339[_Context->language]),2);
	visual_text(_Context->x_Auto3331+30,_Context->y_Auto3331+260,112,16,vfh[2],16,0,_Context->msg_Auto3340[_Context->language],strlen(_Context->msg_Auto3340[_Context->language]),2);
	visual_text(_Context->x_Auto3331+30,_Context->y_Auto3331+280,154,16,vfh[2],16,0,_Context->msg_Auto3341[_Context->language],strlen(_Context->msg_Auto3341[_Context->language]),2);
	visual_text(_Context->x_Auto3331+30,_Context->y_Auto3331+300,154,16,vfh[2],16,0,_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]),2);
	visual_text(_Context->x_Auto3331+30,_Context->y_Auto3331+320,154,16,vfh[2],16,0,_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]),2);
	visual_thaw(_Context->x_Auto3331,_Context->y_Auto3331,280,430);

	return(0);
}

private int Auto3331action(struct accept_database_control_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_database_control_hide(_Context);

		_Context->x_Auto3331 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3331 < 0) { _Context->x_Auto3331=0; }
		_Context->y_Auto3331 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3331 < 0) { _Context->y_Auto3331=0; }
			accept_database_control_show(_Context);

		visual_thaw(_Context->x_Auto3331,_Context->y_Auto3331,280,430);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_database_control_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_database_control_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_database_control_event(
struct accept_database_control_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_HyperSpace == mb ) return(2);
		if (_Context->trigger_HelpBubble == mb ) return(3);
		if (_Context->trigger_Accept == mb ) return(13);
		if (_Context->trigger_Cancel == mb ) return(14);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3331+259) )  
	&&  (my >= (_Context->y_Auto3331+4) )  
	&&  (mx <= (_Context->x_Auto3331+276) )  
	&&  (my <= (_Context->y_Auto3331+20) )) {
		return(1);	/* Auto3331 */

		}
	if ((mx >= (_Context->x_Auto3331+243) )  
	&&  (my >= (_Context->y_Auto3331+4) )  
	&&  (mx <= (_Context->x_Auto3331+260) )  
	&&  (my <= (_Context->y_Auto3331+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vbase.htm");
			};
		return(-1);	/* Auto3331 */

		}
	if ((mx >= (_Context->x_Auto3331+227) )  
	&&  (my >= (_Context->y_Auto3331+4) )  
	&&  (mx <= (_Context->x_Auto3331+244) )  
	&&  (my <= (_Context->y_Auto3331+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_database_control_show(_Context);
		return(-1);	/* Auto3331 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3331+4) )  
		&&  (my >= (_Context->y_Auto3331+4) )  
		&&  (mx <= (_Context->x_Auto3331+212) )  
		&&  (my <= (_Context->y_Auto3331+20) )) {
			return( Auto3331action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3331+40) ) 
	&&  ( my >= (_Context->y_Auto3331+70) ) 
	&&  ( mx <= (_Context->x_Auto3331+40+182) ) 
	&&  ( my <= (_Context->y_Auto3331+70+16))) {
		return(2); /* HyperSpace */
		}
	if (( mx >= (_Context->x_Auto3331+40) ) 
	&&  ( my >= (_Context->y_Auto3331+90) ) 
	&&  ( mx <= (_Context->x_Auto3331+40+182) ) 
	&&  ( my <= (_Context->y_Auto3331+90+16))) {
		return(3); /* HelpBubble */
		}
	if (( mx >= (_Context->x_Auto3331+140+0) ) 
	&&  ( my >= (_Context->y_Auto3331+140) ) 
	&&  ( mx <= (_Context->x_Auto3331+140+110) ) 
	&&  ( my <= (_Context->y_Auto3331+140+16))) {
		return(4); /* Bender */
		}
	if (( mx >= (_Context->x_Auto3331+190) ) 
	&&  ( my >= (_Context->y_Auto3331+200) ) 
	&&  ( mx <= (_Context->x_Auto3331+190+56) ) 
	&&  ( my <= (_Context->y_Auto3331+200+16))) {
		return(5); /* TraceWidth */
		}
	if (( mx >= (_Context->x_Auto3331+190) ) 
	&&  ( my >= (_Context->y_Auto3331+220) ) 
	&&  ( mx <= (_Context->x_Auto3331+190+56) ) 
	&&  ( my <= (_Context->y_Auto3331+220+16))) {
		return(6); /* TraceColour */
		}
	if (( mx >= (_Context->x_Auto3331+190) ) 
	&&  ( my >= (_Context->y_Auto3331+240) ) 
	&&  ( mx <= (_Context->x_Auto3331+190+56) ) 
	&&  ( my <= (_Context->y_Auto3331+240+16))) {
		return(7); /* Depth */
		}
	if (( mx >= (_Context->x_Auto3331+190) ) 
	&&  ( my >= (_Context->y_Auto3331+260) ) 
	&&  ( mx <= (_Context->x_Auto3331+190+56) ) 
	&&  ( my <= (_Context->y_Auto3331+260+16))) {
		return(8); /* TracePadding */
		}
	if (( mx >= (_Context->x_Auto3331+190) ) 
	&&  ( my >= (_Context->y_Auto3331+280) ) 
	&&  ( mx <= (_Context->x_Auto3331+190+56) ) 
	&&  ( my <= (_Context->y_Auto3331+280+16))) {
		return(9); /* xPadding */
		}
	if (( mx >= (_Context->x_Auto3331+190) ) 
	&&  ( my >= (_Context->y_Auto3331+300) ) 
	&&  ( mx <= (_Context->x_Auto3331+190+56) ) 
	&&  ( my <= (_Context->y_Auto3331+300+16))) {
		return(10); /* yPadding */
		}
	if (( mx >= (_Context->x_Auto3331+190) ) 
	&&  ( my >= (_Context->y_Auto3331+320) ) 
	&&  ( mx <= (_Context->x_Auto3331+190+56) ) 
	&&  ( my <= (_Context->y_Auto3331+320+16))) {
		return(11); /* Fraction */
		}
	if (( mx >= (_Context->x_Auto3331+140+0) ) 
	&&  ( my >= (_Context->y_Auto3331+170) ) 
	&&  ( mx <= (_Context->x_Auto3331+140+110) ) 
	&&  ( my <= (_Context->y_Auto3331+170+16))) {
		return(12); /* Schema */
		}
	if (( mx >= (_Context->x_Auto3331+20) ) 
	&&  ( my >= (_Context->y_Auto3331+360) ) 
	&&  ( mx <= (_Context->x_Auto3331+20+56) ) 
	&&  ( my <= (_Context->y_Auto3331+360+48))) {
		return(13); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3331+200) ) 
	&&  ( my >= (_Context->y_Auto3331+360) ) 
	&&  ( mx <= (_Context->x_Auto3331+200+56) ) 
	&&  ( my <= (_Context->y_Auto3331+360+48))) {
		return(14); /* Cancel */
		}

	return(-1);
}


public	int	accept_database_control_focus(struct accept_database_control_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* HyperSpace */
				visual_check(_Context->x_Auto3331+40,_Context->y_Auto3331+70,182,16,vfh[2],16,0,_Context->msg_HyperSpace[_Context->language],strlen(_Context->msg_HyperSpace[_Context->language]),(_Context->value_HyperSpace |2));
				_Context->keycode = visual_getch();
				_Context->trigger_HyperSpace=visual_trigger_code(_Context->msg_HyperSpace[_Context->language],strlen(_Context->msg_HyperSpace[_Context->language]));
	visual_check(_Context->x_Auto3331+40,_Context->y_Auto3331+70,182,16,vfh[2],16,0,_Context->msg_HyperSpace[_Context->language],strlen(_Context->msg_HyperSpace[_Context->language]),_Context->value_HyperSpace|0);
				break;
			case	0x3 :
				/* HelpBubble */
				visual_check(_Context->x_Auto3331+40,_Context->y_Auto3331+90,182,16,vfh[2],16,0,_Context->msg_HelpBubble[_Context->language],strlen(_Context->msg_HelpBubble[_Context->language]),(_Context->value_HelpBubble |2));
				_Context->keycode = visual_getch();
				_Context->trigger_HelpBubble=visual_trigger_code(_Context->msg_HelpBubble[_Context->language],strlen(_Context->msg_HelpBubble[_Context->language]));
	visual_check(_Context->x_Auto3331+40,_Context->y_Auto3331+90,182,16,vfh[2],16,0,_Context->msg_HelpBubble[_Context->language],strlen(_Context->msg_HelpBubble[_Context->language]),_Context->value_HelpBubble|0);
				break;
			case	0x4 :
				/* Bender */
				_Context->keycode = visual_select(_Context->x_Auto3331+140,_Context->y_Auto3331+140,110,80,vfh[2],16,0,parse_selection(_Context->msg_Bender[_Context->language],&_Context->value_Bender),770);
				break;
			case	0x5 :
				/* TraceWidth */
				_Context->keycode = visual_edit(_Context->x_Auto3331+190+1,_Context->y_Auto3331+200+1,56,16,vfh[1],_Context->buffer_TraceWidth,7);
			break;
			case	0x6 :
				/* TraceColour */
				_Context->keycode = visual_edit(_Context->x_Auto3331+190+1,_Context->y_Auto3331+220+1,56,16,vfh[1],_Context->buffer_TraceColour,7);
			break;
			case	0x7 :
				/* Depth */
				_Context->keycode = visual_edit(_Context->x_Auto3331+190+1,_Context->y_Auto3331+240+1,56,16,vfh[1],_Context->buffer_Depth,7);
			break;
			case	0x8 :
				/* TracePadding */
				_Context->keycode = visual_edit(_Context->x_Auto3331+190+1,_Context->y_Auto3331+260+1,56,16,vfh[1],_Context->buffer_TracePadding,7);
			break;
			case	0x9 :
				/* xPadding */
				_Context->keycode = visual_edit(_Context->x_Auto3331+190+1,_Context->y_Auto3331+280+1,56,16,vfh[1],_Context->buffer_xPadding,7);
			break;
			case	0xa :
				/* yPadding */
				_Context->keycode = visual_edit(_Context->x_Auto3331+190+1,_Context->y_Auto3331+300+1,56,16,vfh[1],_Context->buffer_yPadding,7);
			break;
			case	0xb :
				/* Fraction */
				_Context->keycode = visual_edit(_Context->x_Auto3331+190+1,_Context->y_Auto3331+320+1,56,16,vfh[1],_Context->buffer_Fraction,7);
			break;
			case	0xc :
				/* Schema */
				_Context->keycode = visual_select(_Context->x_Auto3331+140,_Context->y_Auto3331+170,110,70,vfh[2],0,0,parse_selection(_Context->msg_Schema[_Context->language],&_Context->value_Schema),770);
				break;
			case	0xd :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_Auto3331+20,_Context->y_Auto3331+360,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3331+20,_Context->y_Auto3331+360,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0xe :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Auto3331+200,_Context->y_Auto3331+360,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3331+200,_Context->y_Auto3331+360,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_database_control_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=14;
			accept_database_control_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_database_control_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3331 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* HyperSpace */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_HyperSpace += 1;
						_Context->value_HyperSpace &= 1;
						}
					continue;
				case	0x3 :
					/* HelpBubble */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_HelpBubble += 1;
						_Context->value_HelpBubble &= 1;
						}
					continue;
				case	0x4 :
					/* Bender */
					continue;
				case	0x5 :
					/* TraceWidth */
					continue;
				case	0x6 :
					/* TraceColour */
					continue;
				case	0x7 :
					/* Depth */
					continue;
				case	0x8 :
					/* TracePadding */
					continue;
				case	0x9 :
					/* xPadding */
					continue;
				case	0xa :
					/* yPadding */
					continue;
				case	0xb :
					/* Fraction */
					continue;
				case	0xc :
					/* Schema */
					continue;
				case	0xd :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3331+20,_Context->y_Auto3331+360,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3331+20,_Context->y_Auto3331+360,56,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0xe :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3331+200,_Context->y_Auto3331+360,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3331+200,_Context->y_Auto3331+360,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
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

public	int	accept_database_control(
	char * pHyperSpace,
	char * pHelpBubble,
	char * pBender,
	char * pTraceWidth,
	char * pTraceColour,
	char * pDepth,
	char * pTracePadding,
	char * pxPadding,
	char * pyPadding,
	char * pFraction,
	char * pSchema)
{
	int	status=0;
	struct accept_database_control_context * _Context=(struct accept_database_control_context*) 0;
	status = accept_database_control_create(
	&_Context,
	 pHyperSpace,
	 pHelpBubble,
	 pBender,
	 pTraceWidth,
	 pTraceColour,
	 pDepth,
	 pTracePadding,
	 pxPadding,
	 pyPadding,
	 pFraction,
	 pSchema);
	if ( status != 0) return(status);
	status = accept_database_control_show(_Context);
		enter_modal();
	status = accept_database_control_focus(_Context);
		leave_modal();
	status = accept_database_control_hide(_Context);
	status = accept_database_control_remove(
	_Context,
	 pHyperSpace,
	 pHelpBubble,
	 pBender,
	 pTraceWidth,
	 pTraceColour,
	 pDepth,
	 pTracePadding,
	 pxPadding,
	 pyPadding,
	 pFraction,
	 pSchema);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vbase_c */
