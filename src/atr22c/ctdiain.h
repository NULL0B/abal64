
#ifndef __CT_DIAIN_H__
#define __CT_DIAIN_H__


/*
	Desc : ctDiaIn.h
	Proj : Common Tool
	Copyright (c) 1997 Amenesik / Sologic  

	Input Diagnostic Messages
		-	Error
		-	Warning
		-	Message, etc.

	Modifications list :
	1/Sept/1997  		JPH	File creation
	
*/


#include "ctDiag.h"

// -------------------------------------------------- Functions

/*

	Usage:
	
	
	ctScanDiagnostic 
		(
		Str,
		&Diag
		);

*/

#ifdef __cplusplus
extern "C" {
#endif


void ctDeclareDiagnosticReceiver (HWND DiagnosticReceiver);

void ctScanDiagnostic 
		(
		INOUT	ctDiagnosticPtr	Diagnostic,
		IN		ctConstStr			Str
		);


void ctScanAndAllocatedDiagnostic
		(
		INOUT	ctDiagnosticPtr	Diagnostic,
		IN		ctConstStr			Str,
		IN		ctBoolean			MustInitialise
		);
		
void ctFreeDiagnostic
		(
		INOUT	ctDiagnosticPtr	Diagnostic
		);

#ifdef __cplusplus
}
#endif

#endif
