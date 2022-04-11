
#ifndef __CT_DIAMES_H__
#define __CT_DIAMES_H__


/*
	Desc : ctDiaMes.h
	Proj : Common Tool
	Copyright (c) 1997-98 Amenesik / Sologic  

	Diagnostic Messages
		-	Error
		-	Warning
		-	Message, etc.
		
		
	Definition common to input and output!

	Modifications list :
	1/Sept/1997  		JPH	File creation
	
*/

#include "ctType.h"

#ifndef __CT_DIAG_H__
#include "ctDiag.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Diagnostic Token code */
#define CT_DIAGNOSTIC_KIND_TOKEN 	1
#define CT_DIAGNOSTIC_PANEL_TOKEN 	2
#define CT_DIAGNOSTIC_TOOL_TOKEN 	3
#define CT_DIAGNOSTIC_PATH_TOKEN 	4
#define CT_DIAGNOSTIC_START_TOKEN 	5
#define CT_DIAGNOSTIC_END_TOKEN 		6

#define CT_DIAGNOSTIC_POSITION_TOKEN 	100
#define CT_END_OF_DIAGNOSTIC_TOKEN 		200



#define CT_DIAGNOSTIC_MESSAGE_STR		"]#M["
#define CT_DIAGNOSTIC_WARNING1_STR		"]#W1["
#define CT_DIAGNOSTIC_WARNING2_STR		"]#W2["
#define CT_DIAGNOSTIC_WARNING3_STR		"]#W3["
#define CT_DIAGNOSTIC_WARNING4_STR		"]#W4["
#define CT_DIAGNOSTIC_WARNING5_STR		"]#W5["
#define CT_DIAGNOSTIC_ERROR_STR			"]#E["
#define CT_DIAGNOSTIC_FATAL_STR			"]#FE["
#define CT_DIAGNOSTIC_INFORMATION_STR	"]#I["
#define CT_DIAGNOSTIC_PROGRESSION_STR	"]#P["

#define CT_DIAGNOSTIC_CLEAR_STR			"]#Cls["
#define CT_DIAGNOSTIC_BEEP_STR			"]#Beep["

#define CT_DIAGNOSTIC_FIRST_STR			"]#>>["
#define CT_DIAGNOSTIC_LAST_STR			"]#<<["
#define CT_DIAGNOSTIC_PING_STR			"]#Ping["


#define CT_DIAGNOSTIC_BUILD_STR			"]>B["
#define CT_DIAGNOSTIC_GREP_STR			"]>G["
#define CT_DIAGNOSTIC_TRACE_STR			"]>T["
#define CT_DIAGNOSTIC_DEBUG_STR			"]>D["
#define CT_DIAGNOSTIC_GENERATION_STR	"]>G["

#define CT_DIAGNOSTIC_TOOL_NAME_STR		"]$Tn["
#define CT_DIAGNOSTIC_FILE_STR			"]$File["
#define CT_DIAGNOSTIC_START_STR			"]$Start["
#define CT_DIAGNOSTIC_END_STR				"]$End["





// -------------------------------------------------- Functions

void ctClearDiagnostic
		(
		INOUT		ctDiagnosticPtr		Diagnostic,
		IN			BOOL						ClearBuffer
		);


// -------------------------------------------------- Tool function

/*
	Append a string to the end of a limited buffer.

	Compute total content length 
	(I.e. total length needed to store info, independent 
	of buffer length).
	
	Accept null and empty buffer
*/

ctConstStr ctBufferAppend
		(
		OUT		ctStr					Buffer,
		IN			int 					BufferLength,
		INOUT		int *					ContentLength,
		IN			ctConstStr			Value,
		IN			int					ValueLength
		);

#ifdef __cplusplus
	}
#endif

#endif
