
#ifndef __CT_DIAG_H__
#define __CT_DIAG_H__


/*
	Desc : ctDiag.h
	Proj : Common Tool
	Copyright (c) 1997-98 Amenesik / Sologic  

	Diagnostic Messages public header

	Modifications list :
	1/Sept/1997  		JPH	File creation
	
*/

#include "cttype.h"


// -------------------------------------------------- 

/* Message Kind */	
#define CT_DIAGNOSTIC_MESSAGE			0

#define CT_DIAGNOSTIC_WARNING1		1
#define CT_DIAGNOSTIC_WARNING2		2	
#define CT_DIAGNOSTIC_WARNING3		3
#define CT_DIAGNOSTIC_WARNING4		4
#define CT_DIAGNOSTIC_WARNING5		5

#define CT_DIAGNOSTIC_ERROR			10
#define CT_DIAGNOSTIC_FATAL			11

#define CT_DIAGNOSTIC_INFORMATION	20
#define CT_DIAGNOSTIC_PROGRESSION	30

#define CT_DIAGNOSTIC_CLEAR			40
#define CT_DIAGNOSTIC_BEEP				41

#define CT_DIAGNOSTIC_FIRST			50
#define CT_DIAGNOSTIC_LAST				51
#define CT_DIAGNOSTIC_PING				99		/* Test presence */



/* Message Panel */
#define CT_DIAGNOSTIC_BUILD			0
#define CT_DIAGNOSTIC_GREP				1
#define CT_DIAGNOSTIC_TRACE			2
#define CT_DIAGNOSTIC_DEBUG			3
#define CT_DIAGNOSTIC_GENERATION		4


// -------------------------------------------------- 

typedef struct ctDiagnosticStruct
	{
	/* IN */
	ctStr			Buffer;
	int			BufferLength;
	
	/* OUT*/
	/* how much is needed to store ALL content (including terminal \0) */
	int			ContentLength;	
	
	/* OUT */
	int			Panel;			/* set once */
	int			Kind;

	ctConstStr	ShortMessage;
	ctConstStr	Message;
	ctConstStr	MessageId;

	ctConstStr	ToolName;
	
	ctConstStr	File;
	long			Line;
	long			Column;
	long			EndLine;
	long			EndColumn;
	
	/* Private information */
	HWND			pConnectionHandle;	/* DON'T TOUCH IT! */
	} ctDiagnostic;
	
typedef ctDiagnostic CT_FAR * ctDiagnosticPtr;


/*
	Environement variable in which 
	diagnostic "receiver" handle is stored.
*/
#define CT_DIAGNOSTIC_HANDLE_ENV_VARIABLE "jjDiagHd"
#define CT_DIAGNOSTIC_ADD_LINE_MESSAGE		"jjDiagAddLine"



#ifndef STATIC
#ifdef __CT_DEBUG_H__
#define STATIC	/* wants to see proc name in debugger */
#else
#define STATIC	static
#endif
#endif

#endif
