
#ifndef _vexadb_c
#define _vexadb_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.12  */
/* Production     : C  */
/* Project        : vexadb.sng  */
/* Target         : vexadb.c  */
/* Identification : 0.0-1070464470-6033.2354 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct visual_debug_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[3+1];
	int	page_number;
	char	buffer_BreakManager[49];
	int	x_DebugCursor;
	int	y_DebugCursor;
	int	w_DebugCursor;
	int	h_DebugCursor;
	int	x_BreakPoint;
	int	y_BreakPoint;
	int	w_BreakPoint;
	int	h_BreakPoint;
	char	buffer_Dbio[2017];
	char	buffer_Prio[3605];
	int	value_VSB;
	int	limit_VSB;
	int	max_VSB;
	int	value_HSB;
	int	limit_HSB;
	int	max_HSB;
	int	value_ProcName;
	int	value_SegmName;
	int	value_GlobNames;
	int	value_LocalNames;
	int	value_AssignList;
	int	value_RegisterList;
	int	value_AttachList;
	int	value_StackList;
	int	value_LibraryList;
	int	value_ObserveList;
	int	value_BreakList;
	int	value_WatchList;
	int	value_SourceList;
	char	buffer_Syntax[425];
	int	value_AED_NORMAL;
	int	value_AED_QUOTE;
	int	value_AED_KEYWORD;
	int	value_AED_COMMENT;
	int	value_AED_PUNCTUATE;
	int	value_BreakKey;
	int	value_AsmList;
	int	value_HexaView;
	char	buffer_StatusBar[90];
	char	signature[26];
	} * _Context;
private int on_StatusBar_create() {
	WindowEditorInformation(_Context->buffer_StatusBar,89);
	return(-1);
}

public	int	visual_debug_attach()
{
	if ( visual_initialise(4|256) == -1 )
		return(56);

	else	{
		visual_palette("/home/abal3/images/standard.rgb",31);
		cicopalette(0,0);
		if ( visual_font("standard.fmf",12) != 1)
			return(40);

		if ( visual_font("arial2.fmf",10) != 2)
			return(40);

		if ( visual_font("arial3.fmf",10) != 3)
			return(40);

		if ( visual_font("arial4.fmf",10) != 4)
			return(40);

		if ( visual_font("arial5.fmf",10) != 5)
			return(40);

		if ( visual_font("arial6.fmf",10) != 6)
			return(40);

		if ( visual_font("font7.fmf",9) != 7)
			return(40);

		if ( visual_font("font8.fmf",9) != 8)
			return(40);

		if ( visual_font("font9.fmf",9) != 9)
			return(40);

		initialise_mouse();
		}
	return(0);
}

public	int	visual_debug_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

private	int	visual_debug_create(
	char * pBreakManager,
	char * pDbio,
	char * pPrio,
	char * pProcName,
	char * pSegmName,
	char * pGlobNames,
	char * pLocalNames,
	char * pAssignList,
	char * pRegisterList,
	char * pAttachList,
	char * pStackList,
	char * pLibraryList,
	char * pObserveList,
	char * pBreakList,
	char * pWatchList,
	char * pSourceList,
	char * pSyntax,
	char * pAED_NORMAL,
	char * pAED_QUOTE,
	char * pAED_KEYWORD,
	char * pAED_COMMENT,
	char * pAED_PUNCTUATE,
	char * pBreakKey,
	char * pAsmList,
	char * pHexaView,
	char * pStatusBar)
{

	int i;
	if (!(_Context = allocate( sizeof( struct visual_debug_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=53;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KSSWWWWWWWWWWWWWSWWWWWWWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_BreakManager, 48, pBreakManager);
		visual_transferin(_Context->buffer_Dbio, 2016, pDbio);
		visual_transferin(_Context->buffer_Prio, 3604, pPrio);
		visual_transferin((void *) 0, 0, pProcName);
		if (!( pProcName )) _Context->value_ProcName=0;
		else	_Context->value_ProcName = *((int *)pProcName);
		visual_transferin((void *) 0, 0, pSegmName);
		if (!( pSegmName )) _Context->value_SegmName=0;
		else	_Context->value_SegmName = *((int *)pSegmName);
		visual_transferin((void *) 0, 0, pGlobNames);
		if (!( pGlobNames )) _Context->value_GlobNames=0;
		else	_Context->value_GlobNames = *((int *)pGlobNames);
		visual_transferin((void *) 0, 0, pLocalNames);
		if (!( pLocalNames )) _Context->value_LocalNames=0;
		else	_Context->value_LocalNames = *((int *)pLocalNames);
		visual_transferin((void *) 0, 0, pAssignList);
		if (!( pAssignList )) _Context->value_AssignList=0;
		else	_Context->value_AssignList = *((int *)pAssignList);
		visual_transferin((void *) 0, 0, pRegisterList);
		if (!( pRegisterList )) _Context->value_RegisterList=0;
		else	_Context->value_RegisterList = *((int *)pRegisterList);
		visual_transferin((void *) 0, 0, pAttachList);
		if (!( pAttachList )) _Context->value_AttachList=0;
		else	_Context->value_AttachList = *((int *)pAttachList);
		visual_transferin((void *) 0, 0, pStackList);
		if (!( pStackList )) _Context->value_StackList=0;
		else	_Context->value_StackList = *((int *)pStackList);
		visual_transferin((void *) 0, 0, pLibraryList);
		if (!( pLibraryList )) _Context->value_LibraryList=0;
		else	_Context->value_LibraryList = *((int *)pLibraryList);
		visual_transferin((void *) 0, 0, pObserveList);
		if (!( pObserveList )) _Context->value_ObserveList=0;
		else	_Context->value_ObserveList = *((int *)pObserveList);
		visual_transferin((void *) 0, 0, pBreakList);
		if (!( pBreakList )) _Context->value_BreakList=0;
		else	_Context->value_BreakList = *((int *)pBreakList);
		visual_transferin((void *) 0, 0, pWatchList);
		if (!( pWatchList )) _Context->value_WatchList=0;
		else	_Context->value_WatchList = *((int *)pWatchList);
		visual_transferin((void *) 0, 0, pSourceList);
		if (!( pSourceList )) _Context->value_SourceList=0;
		else	_Context->value_SourceList = *((int *)pSourceList);
		visual_transferin(_Context->buffer_Syntax, 424, pSyntax);
		visual_transferin((void *) 0, 0, pAED_NORMAL);
		if (!( pAED_NORMAL )) _Context->value_AED_NORMAL=0;
		else	_Context->value_AED_NORMAL = *((int *)pAED_NORMAL);
		visual_transferin((void *) 0, 0, pAED_QUOTE);
		if (!( pAED_QUOTE )) _Context->value_AED_QUOTE=0;
		else	_Context->value_AED_QUOTE = *((int *)pAED_QUOTE);
		visual_transferin((void *) 0, 0, pAED_KEYWORD);
		if (!( pAED_KEYWORD )) _Context->value_AED_KEYWORD=0;
		else	_Context->value_AED_KEYWORD = *((int *)pAED_KEYWORD);
		visual_transferin((void *) 0, 0, pAED_COMMENT);
		if (!( pAED_COMMENT )) _Context->value_AED_COMMENT=0;
		else	_Context->value_AED_COMMENT = *((int *)pAED_COMMENT);
		visual_transferin((void *) 0, 0, pAED_PUNCTUATE);
		if (!( pAED_PUNCTUATE )) _Context->value_AED_PUNCTUATE=0;
		else	_Context->value_AED_PUNCTUATE = *((int *)pAED_PUNCTUATE);
		visual_transferin((void *) 0, 0, pBreakKey);
		if (!( pBreakKey )) _Context->value_BreakKey=0;
		else	_Context->value_BreakKey = *((int *)pBreakKey);
		visual_transferin((void *) 0, 0, pAsmList);
		if (!( pAsmList )) _Context->value_AsmList=0;
		else	_Context->value_AsmList = *((int *)pAsmList);
		visual_transferin((void *) 0, 0, pHexaView);
		if (!( pHexaView )) _Context->value_HexaView=0;
		else	_Context->value_HexaView = *((int *)pHexaView);
		visual_transferin(_Context->buffer_StatusBar, 89, pStatusBar);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->focus_pages[1]=2;
	WindowEditorOnCreate(61+1,70+1,840-2,576-2,7);
	_Context->x_DebugCursor=35;
	_Context->y_DebugCursor=70;
	_Context->w_DebugCursor=20;
	_Context->h_DebugCursor=20;
	_Context->x_BreakPoint=35;
	_Context->y_BreakPoint=90;
	_Context->w_BreakPoint=20;
	_Context->h_BreakPoint=20;
	_Context->focus_pages[2]=11;
	ProgramWindowOnCreate(30,70,850,556);
	_Context->max_VSB=1;
	_Context->value_VSB=1;
	_Context->limit_VSB=1;
	_Context->value_VSB=0;
	_Context->limit_VSB=556;
	_Context->max_VSB=hardrows();
	_Context->max_HSB=1;
	_Context->value_HSB=1;
	_Context->limit_HSB=1;
	_Context->value_HSB=0;
	_Context->limit_HSB=850;
	_Context->max_HSB=hardcolumns();
	_Context->focus_pages[3]=15;
	_Context->value_AED_NORMAL=0;
	_Context->value_AED_QUOTE=12;
	_Context->value_AED_KEYWORD=9;
	_Context->value_AED_COMMENT=10;
	_Context->value_AED_PUNCTUATE=0;
	_Context->value_BreakKey=1;
	on_BreakKey_event();
	_Context->value_AsmList=1;
	on_AsmList_event();
	(void) on_StatusBar_create();
	return(0);
}

private	int	visual_debug_hide()
{

	return(0);
}

private	int	visual_debug_remove(
	char * pBreakManager,
	char * pDbio,
	char * pPrio,
	char * pProcName,
	char * pSegmName,
	char * pGlobNames,
	char * pLocalNames,
	char * pAssignList,
	char * pRegisterList,
	char * pAttachList,
	char * pStackList,
	char * pLibraryList,
	char * pObserveList,
	char * pBreakList,
	char * pWatchList,
	char * pSourceList,
	char * pSyntax,
	char * pAED_NORMAL,
	char * pAED_QUOTE,
	char * pAED_KEYWORD,
	char * pAED_COMMENT,
	char * pAED_PUNCTUATE,
	char * pBreakKey,
	char * pAsmList,
	char * pHexaView,
	char * pStatusBar)
{

	int	result=_Context->keycode;
	WindowEditorOnRemove();
	ProgramWindowOnRemove();
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KSSWWWWWWWWWWWWWSWWWWWWWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_BreakManager, 48, pBreakManager);
		visual_transferout(_Context->buffer_Dbio, 2016, pDbio);
		visual_transferout(_Context->buffer_Prio, 3604, pPrio);
		visual_transferout((void *) 0, 0, pProcName);
		if ( pProcName != (char *) 0)
			*((int*)pProcName) = _Context->value_ProcName;
		visual_transferout((void *) 0, 0, pSegmName);
		if ( pSegmName != (char *) 0)
			*((int*)pSegmName) = _Context->value_SegmName;
		visual_transferout((void *) 0, 0, pGlobNames);
		if ( pGlobNames != (char *) 0)
			*((int*)pGlobNames) = _Context->value_GlobNames;
		visual_transferout((void *) 0, 0, pLocalNames);
		if ( pLocalNames != (char *) 0)
			*((int*)pLocalNames) = _Context->value_LocalNames;
		visual_transferout((void *) 0, 0, pAssignList);
		if ( pAssignList != (char *) 0)
			*((int*)pAssignList) = _Context->value_AssignList;
		visual_transferout((void *) 0, 0, pRegisterList);
		if ( pRegisterList != (char *) 0)
			*((int*)pRegisterList) = _Context->value_RegisterList;
		visual_transferout((void *) 0, 0, pAttachList);
		if ( pAttachList != (char *) 0)
			*((int*)pAttachList) = _Context->value_AttachList;
		visual_transferout((void *) 0, 0, pStackList);
		if ( pStackList != (char *) 0)
			*((int*)pStackList) = _Context->value_StackList;
		visual_transferout((void *) 0, 0, pLibraryList);
		if ( pLibraryList != (char *) 0)
			*((int*)pLibraryList) = _Context->value_LibraryList;
		visual_transferout((void *) 0, 0, pObserveList);
		if ( pObserveList != (char *) 0)
			*((int*)pObserveList) = _Context->value_ObserveList;
		visual_transferout((void *) 0, 0, pBreakList);
		if ( pBreakList != (char *) 0)
			*((int*)pBreakList) = _Context->value_BreakList;
		visual_transferout((void *) 0, 0, pWatchList);
		if ( pWatchList != (char *) 0)
			*((int*)pWatchList) = _Context->value_WatchList;
		visual_transferout((void *) 0, 0, pSourceList);
		if ( pSourceList != (char *) 0)
			*((int*)pSourceList) = _Context->value_SourceList;
		visual_transferout(_Context->buffer_Syntax, 424, pSyntax);
		visual_transferout((void *) 0, 0, pAED_NORMAL);
		if ( pAED_NORMAL != (char *) 0)
			*((int*)pAED_NORMAL) = _Context->value_AED_NORMAL;
		visual_transferout((void *) 0, 0, pAED_QUOTE);
		if ( pAED_QUOTE != (char *) 0)
			*((int*)pAED_QUOTE) = _Context->value_AED_QUOTE;
		visual_transferout((void *) 0, 0, pAED_KEYWORD);
		if ( pAED_KEYWORD != (char *) 0)
			*((int*)pAED_KEYWORD) = _Context->value_AED_KEYWORD;
		visual_transferout((void *) 0, 0, pAED_COMMENT);
		if ( pAED_COMMENT != (char *) 0)
			*((int*)pAED_COMMENT) = _Context->value_AED_COMMENT;
		visual_transferout((void *) 0, 0, pAED_PUNCTUATE);
		if ( pAED_PUNCTUATE != (char *) 0)
			*((int*)pAED_PUNCTUATE) = _Context->value_AED_PUNCTUATE;
		visual_transferout((void *) 0, 0, pBreakKey);
		if ( pBreakKey != (char *) 0)
			*((int*)pBreakKey) = _Context->value_BreakKey;
		visual_transferout((void *) 0, 0, pAsmList);
		if ( pAsmList != (char *) 0)
			*((int*)pAsmList) = _Context->value_AsmList;
		visual_transferout((void *) 0, 0, pHexaView);
		if ( pHexaView != (char *) 0)
			*((int*)pHexaView) = _Context->value_HexaView;
		visual_transferout(_Context->buffer_StatusBar, 89, pStatusBar);
		}
	_Context=liberate(_Context);

	return(result);
}
private int on_Dbio_show() {
	on_EditorColour_event();
	WindowEditorLoseFocus();
	if(WindowEditorOnEvent()==-1){
	Disassembler(_Context->buffer_Dbio,2016,24,84);
	visual_frame(61,70,840+2,576+2,5);
visual_text(61+1,70+1,840,576,7,16,0,_Context->buffer_Dbio,2016,0);
;
	}
	WindowEditorGetFocus();
	on_BreakManager_event();
	return(-1);
}
private int on_Prio_show() {
	ProgramWindowOnShow(_Context->value_HSB,_Context->value_VSB);
	return(-1);
}

private	int	visual_debug_show()
{
	visual_freeze();
	visual_window(0,0,1000,700,2,"Exadb : Version 3.1a.0.01",strlen("Exadb : Version 3.1a.0.01"),0x3);
	visual_filzone(926,56,64,604,28,11);
	if (_Context->page_number == 1 ) {
	visual_tabpage(20,30,900,630,2,"Program &Source",strlen("Program &Source"),0,34);
	} else {
		visual_tabpage(20,30,900,630,2,"Program &Source",strlen("Program &Source"),0,32);
		}
	if (_Context->page_number == 1 ) {
	visual_image(20,56,892,597,"brail.gif",3);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(30,68,877,582,258);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(33,70,24+2,576+2,5);
	visual_text(33+1,70+1,24,576,7,0,0,_Context->buffer_BreakManager,48,3);
		}
	visual_button(934,594,48,48,1,16,0,"exit.gif",strlen("exit.gif"),16);
	visual_button(934,80,48,48,1,16,0,"step.gif",strlen("step.gif"),16);
	visual_button(934,130,48,48,1,27,0,"goto.gif",strlen("goto.gif"),16);
	visual_button(934,180,48,48,1,27,0,"trap.gif",strlen("trap.gif"),16);
	visual_button(934,330,48,48,1,28,28,"clear.gif",strlen("clear.gif"),16);
	visual_button(934,230,48,48,1,16,0,"run.gif",strlen("run.gif"),16);
	visual_button(934,280,48,48,1,28,28,"view.gif",strlen("view.gif"),16);
	if (_Context->page_number == 1 ) {
	visual_frame(61,70,840+2,576+2,5);
	visual_text(61+1,70+1,840,576,7,16,0,_Context->buffer_Dbio,2016,0);
	(void) on_Dbio_show();
		}
	if (_Context->page_number == 2 ) {
	visual_tabpage(20,30,900,630,2,"Program &Output",strlen("Program &Output"),134,34);
	} else {
		visual_tabpage(20,30,900,630,2,"Program &Output",strlen("Program &Output"),134,32);
		}
	if (_Context->page_number == 2 ) {
	visual_image(20,56,894,598,"brail.gif",3);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(28,68,857,584,258);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(30,70,850+2,556+2,5);
	visual_text(30+1,70+1,850,556,1,16,0,_Context->buffer_Prio,3604,0);
	(void) on_Prio_show();
		}
	if (_Context->page_number == 2 ) {
	visual_scrollbar(888,68,20,560,1,0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,3);
		}
	if (_Context->page_number == 2 ) {
	visual_scrollbar(30,630,855,20,1,27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,3);
		}
	if (_Context->page_number == 3 ) {
	visual_tabpage(20,30,900,630,2,"&Debug Control",strlen("&Debug Control"),267,34);
	} else {
		visual_tabpage(20,30,900,630,2,"&Debug Control",strlen("&Debug Control"),267,32);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(30,70,880,580,4);
		}
	if (_Context->page_number == 3 ) {
	visual_image(20,56,894,600,"brail.gif",3);
		}
	if (_Context->page_number == 3 ) {
	visual_text(39,81,670,20,4,27,0,"ABAL++ Debug : Command and Control",strlen("ABAL++ Debug : Command and Control"),770);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,110,240,20,3,27,0,"Procedures",strlen("Procedures"),258);
		}
	if (_Context->page_number == 3 ) {
	visual_text(290,110,170,20,3,27,0,"Segments",strlen("Segments"),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(470,110,170,17,3,27,0,"Global Variables",strlen("Global Variables"),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(699,115,165,18,3,27,0,"Local Variables",strlen("Local Variables"),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,310,420,20,3,27,0,"Activate Break Points",strlen("Activate Break Points"),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,260,420,20,3,27,0,"Dynamic Libraries",strlen("Dynamic Libraries"),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(470,310,350,18,3,27,0,"Active Variable Watch Expressions",strlen("Active Variable Watch Expressions"),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(412,488,483,20,3,27,0,"Syntax and Variable Value Display",strlen("Syntax and Variable Value Display"),1281);
		}
	if (_Context->page_number == 3 ) {
	visual_text(470,160,350,20,3,27,0,"Tcode Registers",strlen("Tcode Registers"),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,160,420,20,3,27,0,"Assigned Files",strlen("Assigned Files"),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,210,420,20,3,27,0,"Attached Programs",strlen("Attached Programs"),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(470,210,348,19,3,27,0,"Stack Inspection",strlen("Stack Inspection"),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,360,420,20,3,27,0,"Source Files",strlen("Source Files"),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(470,260,350,20,3,27,0,"Observation Variables",strlen("Observation Variables"),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(216,580,150,16,2,27,0,"Add Segment Break",strlen("Add Segment Break"),259);
	visual_frame(216,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,580,150,16,2,27,0,"Add Procedure Break",strlen("Add Procedure Break"),259);
	visual_frame(40,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_text(392,580,150,16,2,27,0,"Add Variable Watch",strlen("Add Variable Watch"),259);
	visual_frame(392,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_text(568,580,150,16,2,27,0,"Global Variable",strlen("Global Variable"),259);
	visual_frame(568,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_text(744,580,150,16,2,27,0,"Local Variable",strlen("Local Variable"),259);
	visual_frame(744,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,130,240,440,1,0,0,parse_selection(GetProcedureNames(),&_Context->value_ProcName),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(290,130,170,440,1,0,0,parse_selection(GetSegmentNames(),&_Context->value_SegmName),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(470,130,200,440,1,0,0,parse_selection(GetGlobalNames(),&_Context->value_GlobNames),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(698,130,200,444,1,0,0,parse_selection(GetLocalNames(),&_Context->value_LocalNames),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,180,420,390,1,27,0,parse_selection(GetAssignList(),&_Context->value_AssignList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(470,180,429,404,1,27,0,parse_selection(GetRegisterList(),&_Context->value_RegisterList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,230,420,350,1,27,0,parse_selection(GetAttachList(),&_Context->value_AttachList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(470,230,429,351,1,27,0,parse_selection(GetStackList(),&_Context->value_StackList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,280,420,290,1,27,0,parse_selection(GetLibraryList(),&_Context->value_LibraryList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(470,280,403,298,1,27,0,parse_selection(GetObserveList(),&_Context->value_ObserveList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_button(874,280,20,19,2,27,0,"-",strlen("-"),0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,330,400,250,1,0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_button(440,330,20,19,2,40,0,"-",strlen("-"),0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(470,330,404,241,1,0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_button(876,330,20,19,2,40,0,"-",strlen("-"),0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,380,400,190,1,27,0,parse_selection(GetSourceList(),&_Context->value_SourceList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_button(440,380,20,19,2,27,0,">",strlen(">"),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(44,504,848+2,64+2,5);
	visual_text(44+1,504+1,848,64,1,16,0,_Context->buffer_Syntax,424,0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(44,412,675,24,4,27,0,"Editor Syntaxical Colours",strlen("Editor Syntaxical Colours"),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,440,112,16,2,27,0,"AED.NORMAL",strlen("AED.NORMAL"),259);
		}
	if (_Context->page_number == 3 ) {
	visual_text(192,440,112,16,2,27,0,"AED.STRING",strlen("AED.STRING"),259);
		}
	if (_Context->page_number == 3 ) {
	visual_text(332,440,112,16,2,27,0,"AED.KEYWORD",strlen("AED.KEYWORD"),259);
		}
	if (_Context->page_number == 3 ) {
	visual_text(472,440,112,16,2,27,0,"AED.COMMENT",strlen("AED.COMMENT"),259);
		}
	if (_Context->page_number == 3 ) {
	visual_text(608,440,126,16,2,27,0,"AED.PUNCTUATE",strlen("AED.PUNCTUATE"),259);
		}
	if (_Context->page_number == 3 ) {
	visual_select(44,456,120,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_NORMAL),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(192,456,120,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_QUOTE),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(336,456,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_KEYWORD),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(472,456,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_COMMENT),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(608,456,120,96,1,28,28,parse_selection(CicoColourList,&_Context->value_AED_PUNCTUATE),768);
		}
	if (_Context->page_number == 3 ) {
	visual_button(756,444,140,32,2,28,28,"&Editor Colours",strlen("&Editor Colours"),0);
		}
	if (_Context->page_number == 3 ) {
	visual_button(44,600,70,32,2,40,0,"Multiple",strlen("Multiple"),0);
		}
	if (_Context->page_number == 3 ) {
	visual_button(116,600,70,32,2,40,0,"One Shot",strlen("One Shot"),0);
		}
	if (_Context->page_number == 3 ) {
	visual_button(220,600,70,32,2,40,0,"Multiple",strlen("Multiple"),0);
		}
	if (_Context->page_number == 3 ) {
	visual_button(292,600,70,32,2,40,0,"One Shot",strlen("One Shot"),0);
		}
	if (_Context->page_number == 3 ) {
	visual_button(396,600,70,32,2,40,0,"Multiple",strlen("Multiple"),0);
		}
	if (_Context->page_number == 3 ) {
	visual_button(468,600,70,32,2,40,0,"One Shot",strlen("One Shot"),0);
		}
	if (_Context->page_number == 3 ) {
	visual_button(572,600,70,32,2,27,0,"Observe",strlen("Observe"),0);
		}
	if (_Context->page_number == 3 ) {
	visual_button(644,600,70,32,2,27,0,"Inspect",strlen("Inspect"),0);
		}
	if (_Context->page_number == 3 ) {
	visual_button(748,600,70,32,2,27,0,"Observe",strlen("Observe"),0);
		}
	if (_Context->page_number == 3 ) {
	visual_button(820,600,70,32,2,27,0,"Inspect",strlen("Inspect"),0);
		}
	visual_switch(940,412,40,16,1,12,15,"Intr",strlen("Intr"),_Context->value_BreakKey);
	visual_switch(940,432,40,16,1,12,15,"List",strlen("List"),_Context->value_AsmList);
	visual_switch(940,392,40,16,1,12,15,"Hexa",strlen("Hexa"),_Context->value_HexaView);
	visual_frame(21,663,894+2,27+2,5);
	visual_text(21+1,663+1,894,27,7,16,0,_Context->buffer_StatusBar,89,0);
	visual_thaw(0,0,1000,700);

	return(0);
}
private int on_BreakManager_event() {
	int i;
	visual_freeze();
	visual_frame(33,70,24+2,576+2,5);
visual_text(33+1,70+1,24,576,7,0,0,_Context->buffer_BreakManager,48,3);
;
	if(!(is_idb_active())){
	for(i=0;i<24;i++){
	if(IsBreakPoint(i)){
	_Context->y_BreakPoint=((70)+(i*24));
		visual_image(_Context->x_BreakPoint,_Context->y_BreakPoint,_Context->w_BreakPoint,_Context->h_BreakPoint,"break.gif",3);
;
	}
	}
	i=editorOnGetFocus();
	_Context->y_DebugCursor=((70)+(i*24));
	}
	else _Context->y_DebugCursor=70;
		visual_image(_Context->x_DebugCursor,_Context->y_DebugCursor,_Context->w_DebugCursor,_Context->h_DebugCursor,"debug.gif",3);
;
	visual_thaw(33,70,24,576);
	return(-1);
}
private int on_Exit_event() {
	return(27);
	return(-1);
}
private int on_StepInto_event() {
	if(_Context->page_number!=1){
		/* ProgramSource */
	visual_debug_losefocus();
	_Context->page_number = 1;
	visual_debug_show();
	_Context->focus_item=2;
;
	visual_debug_show();
	}
	ExecuteSingleStep();
	on_StatusBar_event();
	return(-1);
}
private int on_Goto_event() {
	if(_Context->page_number==1){
	if(GotoSourceLine()!=0){
	on_Run_event();
	}
	}
	return(-1);
}
private int on_Break_event() {
	if(_Context->page_number==1){
	SetSourceBreakPoint(1);
	}
	return(-1);
}
private int on_ClearBreak_event() {
	ClearSourceBreakPoint(1);
	return(-1);
}
private int on_Run_event() {
	if(_Context->page_number!=1){
		/* ProgramSource */
	visual_debug_losefocus();
	_Context->page_number = 1;
	visual_debug_show();
	_Context->focus_item=2;
;
	visual_debug_show();
	}
	WindowEditorLoseFocus();
	ExecuteTillBreak();
	visual_debug_show();
	on_StatusBar_event();
	WindowEditorGetFocus();
	return(-1);
}
private int on_View_event() {
	int i;
	if(_Context->page_number==1){
	DebugViewVariable(_Context->buffer_Syntax,424,_Context->value_HexaView);
	for(i=0;i<89;i++){
	if(i<424)
	_Context->buffer_StatusBar[i]=_Context->buffer_Syntax[i];
	else break;
	}
	visual_frame(21,663,894+2,27+2,5);
visual_text(21+1,663+1,894,27,7,16,0,_Context->buffer_StatusBar,89,0);
;
	while(1){
	while(visual_getch()!=256);
	if(visual_event(1)==_MIMO_UP)
	break;
	}
	on_StatusBar_event();
	}
	return(-1);
}
private int on_VSB_event() {
		visual_scrollbar(888,68,20,560,1,0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,3);
;
	ProgramWindowOnShow(_Context->value_HSB,_Context->value_VSB);
		return(-1);
}

private int on_VSB_action() {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (68+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_VSB -= 1;
		if (_Context->value_VSB < 0) 
			_Context->value_VSB = 0;
		(void) on_VSB_event();
	visual_scrollbar(888,68,20,560,1,0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,259);
		return(-1);
		}
	if ( visual_event(6) > (68+560-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_VSB += 1;
		if (_Context->value_VSB > (_Context->max_VSB-_Context->limit_VSB)) 
			_Context->value_VSB = (_Context->max_VSB-_Context->limit_VSB);
		(void) on_VSB_event();
	visual_scrollbar(888,68,20,560,1,0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,259);
		return(-1);
		}
	visual_scrollbar(888,68,20,560,1,0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,259);

	do {
		while(visual_getch() != 256);
		aty = _Context->value_VSB;
		_Context->value_VSB = (((visual_event(6) - (68+20)) * _Context->max_VSB) / (560 - (2 * 20)));
		if (_Context->value_VSB < 0) 
			_Context->value_VSB = 0;
		else if (_Context->value_VSB > (_Context->max_VSB-_Context->limit_VSB)) 
			_Context->value_VSB = (_Context->max_VSB-_Context->limit_VSB);
		if (_Context->value_VSB != aty) {
		(void) on_VSB_event();
	visual_scrollbar(888,68,20,560,1,0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,259);
			}

		}
	while (visual_event(1) != _MIMO_UP);	visual_scrollbar(888,68,20,560,1,0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,3);

	return(1);
}
private int on_HSB_event() {
		visual_scrollbar(30,630,855,20,1,27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,3);
;
	ProgramWindowOnShow(_Context->value_HSB,_Context->value_VSB);
	return(-1);
}

private int on_HSB_action() {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (30+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_HSB -= 1;
		if (_Context->value_HSB < 0) 
			_Context->value_HSB = 0;
		(void) on_HSB_event();
	visual_scrollbar(30,630,855,20,1,27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,259);
		return(-1);
		}
	if ( visual_event(7) > (30+855-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_HSB += 1;
		if (_Context->value_HSB > (_Context->max_HSB-_Context->limit_HSB)) 
			_Context->value_HSB = (_Context->max_HSB-_Context->limit_HSB);
		(void) on_HSB_event();
	visual_scrollbar(30,630,855,20,1,27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,259);
		return(-1);
		}
	visual_scrollbar(30,630,855,20,1,27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,259);

	do {
		while(visual_getch() != 256);
		atx = _Context->value_HSB;
		_Context->value_HSB = (((visual_event(7) - (30+20)) * _Context->max_HSB) / (855 - (2 * 20)));
		if (_Context->value_HSB < 0) 
			_Context->value_HSB = 0;
		else if (_Context->value_HSB > (_Context->max_HSB-_Context->limit_HSB)) 
			_Context->value_HSB = (_Context->max_HSB-_Context->limit_HSB);
		if (_Context->value_HSB != atx) {
		(void) on_HSB_event();
	visual_scrollbar(30,630,855,20,1,27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,259);
			}

		}
	while (visual_event(1) != _MIMO_UP);	visual_scrollbar(30,630,855,20,1,27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,3);

	return(1);
}
private int on_RemoveBreak_event() {
	DeleteBreakPoint(_Context->value_BreakList);
		visual_select(40,330,400,250,1,0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_DeleteWatch_event() {
	DeleteWatchPoint(_Context->value_WatchList);
		visual_select(470,330,404,241,1,0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),768);

	return(-1);
}
private int on_InspectSource_event() {
		/* Dbio */
	/* ProgramSource */
	visual_debug_losefocus();
	_Context->page_number = 1;
	visual_debug_show();
	_Context->focus_item=2;
	visual_debug_show();
	_Context->focus_item=10;
;
	WindowEditorFileNumber(_Context->value_SourceList,0);
	return(-1);
}
private int on_Syntax_event() {
	WindowEditorOnExec(_Context->buffer_Syntax,424);
	return(-1);
}
private int on_EditorColour_event() {
	editorOnColour(1,_Context->value_AED_NORMAL,_Context->value_AED_QUOTE,_Context->value_AED_KEYWORD,_Context->value_AED_COMMENT,_Context->value_AED_PUNCTUATE);
	return(-1);
}
private int on_SetBreakAP_event() {
	ControlWindowSetBreak(1,1,_Context->value_ProcName,0);
		visual_select(40,330,400,250,1,0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_SetBreakBP_event() {
	ControlWindowSetBreak(1,0,_Context->value_ProcName,0);
		visual_select(40,330,400,250,1,0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_SetBreakAS_event() {
	ControlWindowSetBreak(0,1,_Context->value_SegmName,0);
		visual_select(40,330,400,250,1,0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_SetBreakBS_event() {
	ControlWindowSetBreak(0,0,_Context->value_SegmName,0);
		visual_select(40,330,400,250,1,0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_MultipleWatch_event() {
	ControlWindowSetBreak(2,1,_Context->value_GlobNames,0);
		visual_select(470,330,404,241,1,0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),768);

	return(-1);
}
private int on_SingleWatch_event() {
	ControlWindowSetBreak(2,0,_Context->value_GlobNames,0);
		visual_select(470,330,404,241,1,0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),768);

	return(-1);
}
private int on_InspectGlobal_event() {
	if(DebugShowVariable(_Context->buffer_Syntax,424,_Context->value_GlobNames,0,_Context->value_HexaView)!=0){
	visual_frame(44,504,848+2,64+2,5);
visual_text(44+1,504+1,848,64,1,16,0,_Context->buffer_Syntax,424,0);
;
	}
	return(-1);
}
private int on_InspectLocal_event() {
	if(DebugShowVariable(_Context->buffer_Syntax,424,_Context->value_LocalNames,1,_Context->value_HexaView)!=0){
	visual_frame(44,504,848+2,64+2,5);
visual_text(44+1,504+1,848,64,1,16,0,_Context->buffer_Syntax,424,0);
;
	}
	return(-1);
}
private int on_BreakKey_event() {
	if(_Context->value_BreakKey)
	strcpy(_Context->buffer_Syntax,"K/1B");
	else strcpy(_Context->buffer_Syntax,"K/00");
	on_Syntax_event();
	return(-1);
}
private int on_AsmList_event() {
	if(_Context->value_AsmList)
	strcpy(_Context->buffer_Syntax,"LA0");
	else strcpy(_Context->buffer_Syntax,"LA1");
	on_Syntax_event();
		/* ProgramSource */
	visual_debug_losefocus();
	_Context->page_number = 1;
	visual_debug_show();
	_Context->focus_item=2;
;
	visual_debug_show();
	return(-1);
}
private int on_StatusBar_event() {
	on_StatusBar_create();
	visual_frame(21,663,894+2,27+2,5);
visual_text(21+1,663+1,894,27,7,16,0,_Context->buffer_StatusBar,89,0);
;
	on_Dbio_show();
	return(-1);
}


private	int	visual_debug_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x1031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (mt & _MIMO_UP) {
	if ((mx >= 979 )  
	&&  (my >= 4 )  
	&&  (mx <= 995 )  
	&&  (my <= 20 )) {
		return(1);	/* Main */

		}
	if ((mx >= 963 )  
	&&  (my >= 4 )  
	&&  (mx <= 979 )  
	&&  (my <= 20 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vexadb.htm");
			};
		return(-1);	/* Main */

		}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 20 ) 
		&&  (my >= 30 ) 
		&&  (mx <= 153 ) 
		&&  (my <= 54 )) {
			return(2); /* ProgramSource */
		}
		}
	if (( mx >= 934 ) 
	&&  ( my >= 594 ) 
	&&  ( mx <= 982 ) 
	&&  ( my <= 642 )) {
		return(3); /* Exit */
		}
	if (( mx >= 934 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 982 ) 
	&&  ( my <= 128 )) {
		return(4); /* StepInto */
		}
	if (( mx >= 934 ) 
	&&  ( my >= 130 ) 
	&&  ( mx <= 982 ) 
	&&  ( my <= 178 )) {
		return(5); /* Goto */
		}
	if (( mx >= 934 ) 
	&&  ( my >= 180 ) 
	&&  ( mx <= 982 ) 
	&&  ( my <= 228 )) {
		return(6); /* Break */
		}
	if (( mx >= 934 ) 
	&&  ( my >= 330 ) 
	&&  ( mx <= 982 ) 
	&&  ( my <= 378 )) {
		return(7); /* ClearBreak */
		}
	if (( mx >= 934 ) 
	&&  ( my >= 230 ) 
	&&  ( mx <= 982 ) 
	&&  ( my <= 278 )) {
		return(8); /* Run */
		}
	if (( mx >= 934 ) 
	&&  ( my >= 280 ) 
	&&  ( mx <= 982 ) 
	&&  ( my <= 328 )) {
		return(9); /* View */
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 61 ) 
		&&  ( my >= 70 ) 
		&&  ( mx <= 901 ) 
		&&  ( my <= 646 )) {
			return(10); /* Dbio */
		}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 154 ) 
		&&  (my >= 30 ) 
		&&  (mx <= 286 ) 
		&&  (my <= 54 )) {
			return(11); /* ProgramOutput */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 30 ) 
		&&  ( my >= 70 ) 
		&&  ( mx <= 880 ) 
		&&  ( my <= 626 )) {
			return(12); /* Prio */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 888 ) 
		&&  ( my >= 68 ) 
		&&  ( mx <= 908 ) 
		&&  ( my <= 628 )) {
			return(13); /* VSB */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 30 ) 
		&&  ( my >= 630 ) 
		&&  ( mx <= 885 ) 
		&&  ( my <= 650 )) {
			return(14); /* HSB */
		}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if ((mx >= 287 ) 
		&&  (my >= 30 ) 
		&&  (mx <= 407 ) 
		&&  (my <= 54 )) {
			return(15); /* DebugControl */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 130 ) 
		&&  (mx <= 280 ) 
		&&  (my <= 146 )) {
			return(16); /* ProcName */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 290 ) 
		&&  (my >= 130 ) 
		&&  (mx <= 460 ) 
		&&  (my <= 146 )) {
			return(17); /* SegmName */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 470 ) 
		&&  (my >= 130 ) 
		&&  (mx <= 670 ) 
		&&  (my <= 146 )) {
			return(18); /* GlobNames */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 698 ) 
		&&  (my >= 130 ) 
		&&  (mx <= 898 ) 
		&&  (my <= 146 )) {
			return(19); /* LocalNames */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 180 ) 
		&&  (mx <= 460 ) 
		&&  (my <= 196 )) {
			return(20); /* AssignList */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 470 ) 
		&&  (my >= 180 ) 
		&&  (mx <= 899 ) 
		&&  (my <= 196 )) {
			return(21); /* RegisterList */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 230 ) 
		&&  (mx <= 460 ) 
		&&  (my <= 246 )) {
			return(22); /* AttachList */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 470 ) 
		&&  (my >= 230 ) 
		&&  (mx <= 899 ) 
		&&  (my <= 246 )) {
			return(23); /* StackList */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 280 ) 
		&&  (mx <= 460 ) 
		&&  (my <= 296 )) {
			return(24); /* LibraryList */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 470 ) 
		&&  (my >= 280 ) 
		&&  (mx <= 873 ) 
		&&  (my <= 296 )) {
			return(25); /* ObserveList */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 874 ) 
		&&  ( my >= 280 ) 
		&&  ( mx <= 894 ) 
		&&  ( my <= 299 )) {
			return(26); /* DeleteObservation */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 330 ) 
		&&  (mx <= 440 ) 
		&&  (my <= 346 )) {
			return(27); /* BreakList */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 440 ) 
		&&  ( my >= 330 ) 
		&&  ( mx <= 460 ) 
		&&  ( my <= 349 )) {
			return(28); /* RemoveBreak */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 470 ) 
		&&  (my >= 330 ) 
		&&  (mx <= 874 ) 
		&&  (my <= 346 )) {
			return(29); /* WatchList */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 876 ) 
		&&  ( my >= 330 ) 
		&&  ( mx <= 896 ) 
		&&  ( my <= 349 )) {
			return(30); /* DeleteWatch */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 380 ) 
		&&  (mx <= 440 ) 
		&&  (my <= 396 )) {
			return(31); /* SourceList */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 440 ) 
		&&  ( my >= 380 ) 
		&&  ( mx <= 460 ) 
		&&  ( my <= 399 )) {
			return(32); /* InspectSource */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 44 ) 
		&&  ( my >= 504 ) 
		&&  ( mx <= 892 ) 
		&&  ( my <= 568 )) {
			return(33); /* Syntax */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 44 ) 
		&&  (my >= 456 ) 
		&&  (mx <= 164 ) 
		&&  (my <= 472 )) {
			return(34); /* AED_NORMAL */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 192 ) 
		&&  (my >= 456 ) 
		&&  (mx <= 312 ) 
		&&  (my <= 472 )) {
			return(35); /* AED_QUOTE */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 336 ) 
		&&  (my >= 456 ) 
		&&  (mx <= 448 ) 
		&&  (my <= 472 )) {
			return(36); /* AED_KEYWORD */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 472 ) 
		&&  (my >= 456 ) 
		&&  (mx <= 584 ) 
		&&  (my <= 472 )) {
			return(37); /* AED_COMMENT */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 608 ) 
		&&  (my >= 456 ) 
		&&  (mx <= 728 ) 
		&&  (my <= 472 )) {
			return(38); /* AED_PUNCTUATE */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 756 ) 
		&&  ( my >= 444 ) 
		&&  ( mx <= 896 ) 
		&&  ( my <= 476 )) {
			return(39); /* EditorColour */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 44 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 114 ) 
		&&  ( my <= 632 )) {
			return(40); /* SetBreakAP */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 116 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 186 ) 
		&&  ( my <= 632 )) {
			return(41); /* SetBreakBP */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 220 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 290 ) 
		&&  ( my <= 632 )) {
			return(42); /* SetBreakAS */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 292 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 362 ) 
		&&  ( my <= 632 )) {
			return(43); /* SetBreakBS */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 396 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 466 ) 
		&&  ( my <= 632 )) {
			return(44); /* MultipleWatch */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 468 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 538 ) 
		&&  ( my <= 632 )) {
			return(45); /* SingleWatch */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 572 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 642 ) 
		&&  ( my <= 632 )) {
			return(46); /* ObserveGlobal */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 644 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 714 ) 
		&&  ( my <= 632 )) {
			return(47); /* InspectGlobal */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 748 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 818 ) 
		&&  ( my <= 632 )) {
			return(48); /* ObserveLocal */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 820 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 890 ) 
		&&  ( my <= 632 )) {
			return(49); /* InspectLocal */
		}
		}
	if (( mx >= 940 ) 
	&&  ( my >= 412 ) 
	&&  ( mx <= 980 ) 
	&&  ( my <= 428 )) {
		return(50); /* BreakKey */
		}
	if (( mx >= 940 ) 
	&&  ( my >= 432 ) 
	&&  ( mx <= 980 ) 
	&&  ( my <= 448 )) {
		return(51); /* AsmList */
		}
	if (( mx >= 940 ) 
	&&  ( my >= 392 ) 
	&&  ( mx <= 980 ) 
	&&  ( my <= 408 )) {
		return(52); /* HexaView */
		}
	if (( mx >= 21 ) 
	&&  ( my >= 663 ) 
	&&  ( mx <= 915 ) 
	&&  ( my <= 690 )) {
		return(53); /* StatusBar */
		}

	return(-1);
}
private int on_ProgramSource_losefocus() {
	WindowEditorLoseFocus();
	return(-1);
}
private int on_ProgramOutput_losefocus() {
	ProgramWindowLoseFocus();
	return(-1);
}
private int on_StatusBar_losefocus() {
	int i;
	if(_Context->keycode==13){
	if((_Context->buffer_StatusBar[0]!='D')
	&&(_Context->buffer_StatusBar[0]!='d')){
	WindowEditorOnExec(_Context->buffer_StatusBar,89);
	}
	else{
	DebugVariableSyntax(_Context->buffer_Syntax,424,_Context->buffer_StatusBar,89,_Context->value_HexaView);
	for(i=0;i<89;i++){
	if(i<424)
	_Context->buffer_StatusBar[i]=_Context->buffer_Syntax[i];
	else break;
	}
	visual_frame(21,663,894+2,27+2,5);
visual_text(21+1,663+1,894,27,7,16,0,_Context->buffer_StatusBar,89,0);
;
	}
	_Context->keycode=0;
	}
	return(-1);
}


private	int	visual_debug_losefocus()
{
	switch (_Context->page_number) {
		case 1 : 
			(void) on_ProgramSource_losefocus();
			break;
		case 2 : 
			(void) on_ProgramOutput_losefocus();
			break;
		case 3 : 
			break;

		}
	return(0);

}
private int on_ProgramSource_getfocus() {
	return(5);
	return(-1);
}
private int on_Dbio_getfocus() {
	int event,mx,my;
	while(1){
	CheckBreakPoints(0);
	on_BreakManager_event();
	event=visual_getch();
	editorOnLoseFocus();
	if(((event>='A')&&(event<='Z'))
	||((event>='a')&&(event<='z'))){
	visual_unget_event(event);
		/* StatusBar */
	visual_debug_show();
	_Context->focus_item=53;
;
	return(0);
	}
	if((event==27)||(event&_MIMO_ALT))
	break;
	else if(event==32)
	on_StepInto_event();
	else if(event==256){
	if(((mx=visual_event(7))>61)
	&&((my=visual_event(6))>70)
	&&(mx<(61+840))
	&&(my<(70+576))){
	if(visual_event(2)==1)
	editorOnUseEvent(event);
	else if(visual_event(1)==_MIMO_DOWN)
	on_View_event();
	}
	else break;
	}
	else if(event<26){
	if(!(editorOnUseEvent(event)))
	break;
	}
	}
	return(event);
	return(-1);
}


private	int	visual_debug_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* ProgramSource */
				if (_Context->page_number == 1 ) {
					if ((_Context->keycode = on_ProgramSource_getfocus()) != -1) break;
					(void) on_ProgramSource_losefocus();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xa :
				/* Dbio */
				if (_Context->page_number == 1 ) {
					if ((_Context->keycode = on_Dbio_getfocus()) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* ProgramOutput */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
					(void) on_ProgramOutput_losefocus();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xc :
				/* Prio */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(30+1,70+1,850,556,1,_Context->buffer_Prio,3604);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* DebugControl */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x10 :
				/* ProcName */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,130,240,440,1,0,0,parse_selection(GetProcedureNames(),&_Context->value_ProcName),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* SegmName */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(290,130,170,440,1,0,0,parse_selection(GetSegmentNames(),&_Context->value_SegmName),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* GlobNames */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(470,130,200,440,1,0,0,parse_selection(GetGlobalNames(),&_Context->value_GlobNames),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* LocalNames */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(698,130,200,444,1,0,0,parse_selection(GetLocalNames(),&_Context->value_LocalNames),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* AssignList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,180,420,390,1,27,0,parse_selection(GetAssignList(),&_Context->value_AssignList),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* RegisterList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(470,180,429,404,1,27,0,parse_selection(GetRegisterList(),&_Context->value_RegisterList),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* AttachList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,230,420,350,1,27,0,parse_selection(GetAttachList(),&_Context->value_AttachList),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* StackList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(470,230,429,351,1,27,0,parse_selection(GetStackList(),&_Context->value_StackList),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* LibraryList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,280,420,290,1,27,0,parse_selection(GetLibraryList(),&_Context->value_LibraryList),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* ObserveList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(470,280,403,298,1,27,0,parse_selection(GetObserveList(),&_Context->value_ObserveList),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* DeleteObservation */
				if (_Context->page_number == 3 ) {
					visual_button(874,280,20,19,2,27,0,"-",strlen("-"),2);
					_Context->keycode = visual_getch();
					visual_button(874,280,20,19,2,27,0,"-",strlen("-"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* BreakList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,330,400,250,1,0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* RemoveBreak */
				if (_Context->page_number == 3 ) {
					visual_button(440,330,20,19,2,40,0,"-",strlen("-"),2);
					_Context->keycode = visual_getch();
					visual_button(440,330,20,19,2,40,0,"-",strlen("-"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* WatchList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(470,330,404,241,1,0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* DeleteWatch */
				if (_Context->page_number == 3 ) {
					visual_button(876,330,20,19,2,40,0,"-",strlen("-"),2);
					_Context->keycode = visual_getch();
					visual_button(876,330,20,19,2,40,0,"-",strlen("-"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* SourceList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,380,400,190,1,27,0,parse_selection(GetSourceList(),&_Context->value_SourceList),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* InspectSource */
				if (_Context->page_number == 3 ) {
					visual_button(440,380,20,19,2,27,0,">",strlen(">"),2);
					_Context->keycode = visual_getch();
					visual_button(440,380,20,19,2,27,0,">",strlen(">"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* Syntax */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(44+1,504+1,848,64,1,_Context->buffer_Syntax,424);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* AED_NORMAL */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(44,456,120,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_NORMAL),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* AED_QUOTE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(192,456,120,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_QUOTE),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* AED_KEYWORD */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(336,456,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_KEYWORD),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x25 :
				/* AED_COMMENT */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(472,456,112,96,1,27,0,parse_selection(CicoColourList,&_Context->value_AED_COMMENT),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* AED_PUNCTUATE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(608,456,120,96,1,28,28,parse_selection(CicoColourList,&_Context->value_AED_PUNCTUATE),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* EditorColour */
				if (_Context->page_number == 3 ) {
					visual_button(756,444,140,32,2,28,28,"&Editor Colours",strlen("&Editor Colours"),2);
					_Context->keycode = visual_getch();
					visual_button(756,444,140,32,2,28,28,"&Editor Colours",strlen("&Editor Colours"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x28 :
				/* SetBreakAP */
				if (_Context->page_number == 3 ) {
					visual_button(44,600,70,32,2,40,0,"Multiple",strlen("Multiple"),2);
					_Context->keycode = visual_getch();
					visual_button(44,600,70,32,2,40,0,"Multiple",strlen("Multiple"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* SetBreakBP */
				if (_Context->page_number == 3 ) {
					visual_button(116,600,70,32,2,40,0,"One Shot",strlen("One Shot"),2);
					_Context->keycode = visual_getch();
					visual_button(116,600,70,32,2,40,0,"One Shot",strlen("One Shot"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2a :
				/* SetBreakAS */
				if (_Context->page_number == 3 ) {
					visual_button(220,600,70,32,2,40,0,"Multiple",strlen("Multiple"),2);
					_Context->keycode = visual_getch();
					visual_button(220,600,70,32,2,40,0,"Multiple",strlen("Multiple"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2b :
				/* SetBreakBS */
				if (_Context->page_number == 3 ) {
					visual_button(292,600,70,32,2,40,0,"One Shot",strlen("One Shot"),2);
					_Context->keycode = visual_getch();
					visual_button(292,600,70,32,2,40,0,"One Shot",strlen("One Shot"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2c :
				/* MultipleWatch */
				if (_Context->page_number == 3 ) {
					visual_button(396,600,70,32,2,40,0,"Multiple",strlen("Multiple"),2);
					_Context->keycode = visual_getch();
					visual_button(396,600,70,32,2,40,0,"Multiple",strlen("Multiple"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2d :
				/* SingleWatch */
				if (_Context->page_number == 3 ) {
					visual_button(468,600,70,32,2,40,0,"One Shot",strlen("One Shot"),2);
					_Context->keycode = visual_getch();
					visual_button(468,600,70,32,2,40,0,"One Shot",strlen("One Shot"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2e :
				/* ObserveGlobal */
				if (_Context->page_number == 3 ) {
					visual_button(572,600,70,32,2,27,0,"Observe",strlen("Observe"),2);
					_Context->keycode = visual_getch();
					visual_button(572,600,70,32,2,27,0,"Observe",strlen("Observe"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2f :
				/* InspectGlobal */
				if (_Context->page_number == 3 ) {
					visual_button(644,600,70,32,2,27,0,"Inspect",strlen("Inspect"),2);
					_Context->keycode = visual_getch();
					visual_button(644,600,70,32,2,27,0,"Inspect",strlen("Inspect"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x30 :
				/* ObserveLocal */
				if (_Context->page_number == 3 ) {
					visual_button(748,600,70,32,2,27,0,"Observe",strlen("Observe"),2);
					_Context->keycode = visual_getch();
					visual_button(748,600,70,32,2,27,0,"Observe",strlen("Observe"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x31 :
				/* InspectLocal */
				if (_Context->page_number == 3 ) {
					visual_button(820,600,70,32,2,27,0,"Inspect",strlen("Inspect"),2);
					_Context->keycode = visual_getch();
					visual_button(820,600,70,32,2,27,0,"Inspect",strlen("Inspect"),0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x32 :
				/* BreakKey */
				visual_switch(940,412,40,16,1,12,15,"Intr",strlen("Intr"),(_Context->value_BreakKey |2));
				_Context->keycode = visual_getch();
				visual_switch(940,412,40,16,1,12,15,"Intr",strlen("Intr"),(_Context->value_BreakKey |0));
				break;
			case	0x33 :
				/* AsmList */
				visual_switch(940,432,40,16,1,12,15,"List",strlen("List"),(_Context->value_AsmList |2));
				_Context->keycode = visual_getch();
				visual_switch(940,432,40,16,1,12,15,"List",strlen("List"),(_Context->value_AsmList |0));
				break;
			case	0x34 :
				/* HexaView */
				visual_switch(940,392,40,16,1,12,15,"Hexa",strlen("Hexa"),(_Context->value_HexaView |2));
				_Context->keycode = visual_getch();
				visual_switch(940,392,40,16,1,12,15,"Hexa",strlen("Hexa"),(_Context->value_HexaView |0));
				break;
			case	0x35 :
				/* StatusBar */
				_Context->keycode = visual_edit(21+1,663+1,894,27,7,_Context->buffer_StatusBar,89);
				(void) on_StatusBar_losefocus();
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			visual_debug_losefocus();
			_Context->page_number=1;
			_Context->focus_item=1;
			visual_debug_show();
			continue;
		case	0x2 :
			visual_debug_losefocus();
			_Context->page_number=3;
			_Context->focus_item=53;
			visual_debug_show();
			continue;
		case	0x3 :
			visual_debug_losefocus();
			if ( _Context->page_number < 3 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			visual_debug_show();
			continue;
		case	0x12 :
			visual_debug_losefocus();
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			visual_debug_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=visual_debug_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Main */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* ProgramSource */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_debug_losefocus();
							_Context->page_number = 1;
							visual_debug_show();
							}
						continue;
					case	0x3 :
						/* Exit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(934,594,48,48,1,16,0,"exit.gif",strlen("exit.gif"),24);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(934,594,48,48,1,16,0,"exit.gif",strlen("exit.gif"),16);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Exit_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* StepInto */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(934,80,48,48,1,16,0,"step.gif",strlen("step.gif"),24);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(934,80,48,48,1,16,0,"step.gif",strlen("step.gif"),16);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_StepInto_event()) != -1) break;

							}
						continue;
					case	0x5 :
						/* Goto */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(934,130,48,48,1,27,0,"goto.gif",strlen("goto.gif"),24);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(934,130,48,48,1,27,0,"goto.gif",strlen("goto.gif"),16);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Goto_event()) != -1) break;

							}
						continue;
					case	0x6 :
						/* Break */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(934,180,48,48,1,27,0,"trap.gif",strlen("trap.gif"),24);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(934,180,48,48,1,27,0,"trap.gif",strlen("trap.gif"),16);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Break_event()) != -1) break;

							}
						continue;
					case	0x7 :
						/* ClearBreak */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(934,330,48,48,1,28,28,"clear.gif",strlen("clear.gif"),24);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(934,330,48,48,1,28,28,"clear.gif",strlen("clear.gif"),16);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_ClearBreak_event()) != -1) break;

							}
						continue;
					case	0x8 :
						/* Run */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(934,230,48,48,1,16,0,"run.gif",strlen("run.gif"),24);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(934,230,48,48,1,16,0,"run.gif",strlen("run.gif"),16);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Run_event()) != -1) break;

							}
						continue;
					case	0x9 :
						/* View */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(934,280,48,48,1,28,28,"view.gif",strlen("view.gif"),24);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(934,280,48,48,1,28,28,"view.gif",strlen("view.gif"),16);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_View_event()) != -1) break;

							}
						continue;
					case	0xa :
						/* Dbio */
						continue;
					case	0xb :
						/* ProgramOutput */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_debug_losefocus();
							_Context->page_number = 2;
							visual_debug_show();
							}
						continue;
					case	0xc :
						/* Prio */
						continue;
					case	0xd :
						/* VSB */
						(void) on_VSB_action();
						continue;
					case	0xe :
						/* HSB */
						(void) on_HSB_action();
						continue;
					case	0xf :
						/* DebugControl */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_debug_losefocus();
							_Context->page_number = 3;
							visual_debug_show();
							}
						continue;
					case	0x10 :
						/* ProcName */
						continue;
					case	0x11 :
						/* SegmName */
						continue;
					case	0x12 :
						/* GlobNames */
						continue;
					case	0x13 :
						/* LocalNames */
						continue;
					case	0x14 :
						/* AssignList */
						continue;
					case	0x15 :
						/* RegisterList */
						continue;
					case	0x16 :
						/* AttachList */
						continue;
					case	0x17 :
						/* StackList */
						continue;
					case	0x18 :
						/* LibraryList */
						continue;
					case	0x19 :
						/* ObserveList */
						continue;
					case	0x1a :
						/* DeleteObservation */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(874,280,20,19,2,27,0,"-",strlen("-"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(874,280,20,19,2,27,0,"-",strlen("-"),0);
							}
						continue;
					case	0x1b :
						/* BreakList */
						continue;
					case	0x1c :
						/* RemoveBreak */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(440,330,20,19,2,40,0,"-",strlen("-"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(440,330,20,19,2,40,0,"-",strlen("-"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_RemoveBreak_event()) != -1) break;

							}
						continue;
					case	0x1d :
						/* WatchList */
						continue;
					case	0x1e :
						/* DeleteWatch */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(876,330,20,19,2,40,0,"-",strlen("-"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(876,330,20,19,2,40,0,"-",strlen("-"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_DeleteWatch_event()) != -1) break;

							}
						continue;
					case	0x1f :
						/* SourceList */
						continue;
					case	0x20 :
						/* InspectSource */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(440,380,20,19,2,27,0,">",strlen(">"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(440,380,20,19,2,27,0,">",strlen(">"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_InspectSource_event()) != -1) break;

							}
						continue;
					case	0x21 :
						/* Syntax */
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Syntax_event()) != -1) break;

							}
						continue;
					case	0x22 :
						/* AED_NORMAL */
						continue;
					case	0x23 :
						/* AED_QUOTE */
						continue;
					case	0x24 :
						/* AED_KEYWORD */
						continue;
					case	0x25 :
						/* AED_COMMENT */
						continue;
					case	0x26 :
						/* AED_PUNCTUATE */
						continue;
					case	0x27 :
						/* EditorColour */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(756,444,140,32,2,28,28,"&Editor Colours",strlen("&Editor Colours"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(756,444,140,32,2,28,28,"&Editor Colours",strlen("&Editor Colours"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_EditorColour_event()) != -1) break;

							}
						continue;
					case	0x28 :
						/* SetBreakAP */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(44,600,70,32,2,40,0,"Multiple",strlen("Multiple"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(44,600,70,32,2,40,0,"Multiple",strlen("Multiple"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SetBreakAP_event()) != -1) break;

							}
						continue;
					case	0x29 :
						/* SetBreakBP */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(116,600,70,32,2,40,0,"One Shot",strlen("One Shot"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(116,600,70,32,2,40,0,"One Shot",strlen("One Shot"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SetBreakBP_event()) != -1) break;

							}
						continue;
					case	0x2a :
						/* SetBreakAS */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(220,600,70,32,2,40,0,"Multiple",strlen("Multiple"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(220,600,70,32,2,40,0,"Multiple",strlen("Multiple"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SetBreakAS_event()) != -1) break;

							}
						continue;
					case	0x2b :
						/* SetBreakBS */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(292,600,70,32,2,40,0,"One Shot",strlen("One Shot"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(292,600,70,32,2,40,0,"One Shot",strlen("One Shot"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SetBreakBS_event()) != -1) break;

							}
						continue;
					case	0x2c :
						/* MultipleWatch */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(396,600,70,32,2,40,0,"Multiple",strlen("Multiple"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(396,600,70,32,2,40,0,"Multiple",strlen("Multiple"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_MultipleWatch_event()) != -1) break;

							}
						continue;
					case	0x2d :
						/* SingleWatch */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(468,600,70,32,2,40,0,"One Shot",strlen("One Shot"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(468,600,70,32,2,40,0,"One Shot",strlen("One Shot"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SingleWatch_event()) != -1) break;

							}
						continue;
					case	0x2e :
						/* ObserveGlobal */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(572,600,70,32,2,27,0,"Observe",strlen("Observe"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(572,600,70,32,2,27,0,"Observe",strlen("Observe"),0);
							}
						continue;
					case	0x2f :
						/* InspectGlobal */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(644,600,70,32,2,27,0,"Inspect",strlen("Inspect"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(644,600,70,32,2,27,0,"Inspect",strlen("Inspect"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_InspectGlobal_event()) != -1) break;

							}
						continue;
					case	0x30 :
						/* ObserveLocal */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(748,600,70,32,2,27,0,"Observe",strlen("Observe"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(748,600,70,32,2,27,0,"Observe",strlen("Observe"),0);
							}
						continue;
					case	0x31 :
						/* InspectLocal */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(820,600,70,32,2,27,0,"Inspect",strlen("Inspect"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(820,600,70,32,2,27,0,"Inspect",strlen("Inspect"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_InspectLocal_event()) != -1) break;

							}
						continue;
					case	0x32 :
						/* BreakKey */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_BreakKey += 1;
							_Context->value_BreakKey &= 1;
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_BreakKey_event()) != -1) break;

							}
						continue;
					case	0x33 :
						/* AsmList */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_AsmList += 1;
							_Context->value_AsmList &= 1;
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_AsmList_event()) != -1) break;

							}
						continue;
					case	0x34 :
						/* HexaView */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_HexaView += 1;
							_Context->value_HexaView &= 1;
							}
						continue;
					case	0x35 :
						/* StatusBar */
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_StatusBar_event()) != -1) break;

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
				_Context->focus_item=53;
			}
			continue;
		case 0x873 : 
		case 0x853 : 
			/* ProgramSource */
						visual_debug_losefocus();
			_Context->page_number = 1;
			visual_debug_show();
			_Context->focus_item=2;
			continue;
			continue;
		case 0x86f : 
		case 0x84f : 
			/* ProgramOutput */
						visual_debug_losefocus();
			_Context->page_number = 2;
			visual_debug_show();
			_Context->focus_item=11;
			continue;
			continue;
		case 0x864 : 
		case 0x844 : 
			/* DebugControl */
						visual_debug_losefocus();
			_Context->page_number = 3;
			visual_debug_show();
			_Context->focus_item=15;
			continue;
			continue;
		case 0x865 : 
		case 0x845 : 
			if (_Context->page_number == 3) {
				/* EditorColour */
				visual_button(756,444,140,32,2,28,28,"&Editor Colours",strlen("&Editor Colours"),8);
				visual_button(756,444,140,32,2,28,28,"&Editor Colours",strlen("&Editor Colours"),0);
				_Context->focus_item=39;
				if ((_Context->keycode = on_EditorColour_event()) != -1) break;
				continue;
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

public	int	visual_debug(
	char * pBreakManager,
	char * pDbio,
	char * pPrio,
	char * pProcName,
	char * pSegmName,
	char * pGlobNames,
	char * pLocalNames,
	char * pAssignList,
	char * pRegisterList,
	char * pAttachList,
	char * pStackList,
	char * pLibraryList,
	char * pObserveList,
	char * pBreakList,
	char * pWatchList,
	char * pSourceList,
	char * pSyntax,
	char * pAED_NORMAL,
	char * pAED_QUOTE,
	char * pAED_KEYWORD,
	char * pAED_COMMENT,
	char * pAED_PUNCTUATE,
	char * pBreakKey,
	char * pAsmList,
	char * pHexaView,
	char * pStatusBar)
{
	int	status=0;
	status = visual_debug_create(
	 pBreakManager,
	 pDbio,
	 pPrio,
	 pProcName,
	 pSegmName,
	 pGlobNames,
	 pLocalNames,
	 pAssignList,
	 pRegisterList,
	 pAttachList,
	 pStackList,
	 pLibraryList,
	 pObserveList,
	 pBreakList,
	 pWatchList,
	 pSourceList,
	 pSyntax,
	 pAED_NORMAL,
	 pAED_QUOTE,
	 pAED_KEYWORD,
	 pAED_COMMENT,
	 pAED_PUNCTUATE,
	 pBreakKey,
	 pAsmList,
	 pHexaView,
	 pStatusBar);
	if ( status != 0) return(status);
	status = visual_debug_show();
		enter_modal();
	status = visual_debug_focus();
		leave_modal();
	status = visual_debug_hide();
	status = visual_debug_remove(
	 pBreakManager,
	 pDbio,
	 pPrio,
	 pProcName,
	 pSegmName,
	 pGlobNames,
	 pLocalNames,
	 pAssignList,
	 pRegisterList,
	 pAttachList,
	 pStackList,
	 pLibraryList,
	 pObserveList,
	 pBreakList,
	 pWatchList,
	 pSourceList,
	 pSyntax,
	 pAED_NORMAL,
	 pAED_QUOTE,
	 pAED_KEYWORD,
	 pAED_COMMENT,
	 pAED_PUNCTUATE,
	 pBreakKey,
	 pAsmList,
	 pHexaView,
	 pStatusBar);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vexadb_c */
