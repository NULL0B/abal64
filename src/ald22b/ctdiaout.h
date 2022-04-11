
#ifndef __CT_DIAOUT_H__
#define __CT_DIAOUT_H__


/*
	Desc : ctDiaOut.h
	Proj : Common Tool
	Copyright (c) 1997-98 Amenesik / Sologic  

	Ouput Diagnostic Messages
		-	Error
		-	Warning
		-	Message, etc.

	Modifications list :
	1/Sept/1997  		JPH	File creation
	
*/

#include "ctdiag.h"

#ifdef __cplusplus
extern "C" {
#endif

/*


	Usage for "indirect mode" (multi-context):
	
	
	CONTEXT.Diag == a ctDiagnostic instance;
	
	
	
	ctOpenDiagnostic
			(
			&CONTEXT.Diag, Handle // or 0
			);


	// Change output File 
	CONTEXT.Diag.File = "\toto\titi.cpp";
	
		// Change output line
		ctSetDiagLine (&CONTEXT.Diag, 12,32,12,45);
	
		// Ouput Error
		ctOutputErrorDiagnostic (&CONTEXT.Diag, 1, "Big error",0,0);

		// Output warning
		ctOutputWarningDiagnostic (&CONTEXT.Diag, 1, "Should'nt do that",0,0);
		
		// Output message
		SetFileLine(&CONTEXT.Diag,0,0,0,0,0);
		ctOutputMessageDiagnostic (&CONTEXT.Diag, 1, "Big error",0,0);


	ctCloseDiagnostic (CONTEXT.Diag);

*/


/*


	Usage for "direct mode" (NO multi-context):
	
	



*/


// -------------------------------------------------- Initialisation function


ctBoolean ctOpenDiagnostic
		(
		INOUT		ctDiagnosticPtr		Diagnostic,
		IN			HWND						ConnectionHandle,
		IN			ctConstStr				ToolName
		);

ctBoolean ctCloseDiagnostic
		(
		INOUT		ctDiagnosticPtr		Diagnostic
		);
	

// -------------------------------------------------- Indirect mode Functions

ctBoolean ctOutputDiagnostic
		(
		INOUT		ctDiagnosticPtr	Diagnostic
		);

ctBoolean ctOutputErrorDiagnostic
		(
		INOUT		ctDiagnosticPtr	Diagnostic,
		IN			int					Level,
		IN			ctConstStr			ShortMessage,
		IN			ctConstStr			MessageStr,
		IN			ctConstStr			MessageId
		);

ctBoolean ctOutputWarningDiagnostic
		(
		INOUT		ctDiagnosticPtr	Diagnostic,
		IN			int					Level,
		IN			ctConstStr			ShortMessage,
		IN			ctConstStr			MessageStr,
		IN			ctConstStr			MessageId
		);

ctBoolean ctOutputMessageDiagnostic
		(
		INOUT		ctDiagnosticPtr	Diagnostic,
		IN			ctConstStr			ShortMessage,
		IN			ctConstStr			MessageStr,
		IN			ctConstStr			MessageId
		);

void ctSetDiagFileLine
		(
		INOUT		ctDiagnosticPtr		Diagnostic,
		IN			ctConstStr				PathFile,
		IN			long						Line,
		IN			long						Column,
		IN			long						EndLine,
		IN			long						EndColumn
		);

void ctSetDiagLine
		(
		INOUT		ctDiagnosticPtr		Diagnostic,
		IN			long						Line,
		IN			long						Column,
		IN			long						EndLine,
		IN			long						EndColumn
		);

// -------------------------------------------------- Direct mode Functions


extern ctDiagnostic * GlobalDiagnostic;

/*
	Direct mode:
		Parameter are repeated for every call.
		

	The global value 'ctGlobalDiagnostic' is used to
	store default value and state information;

*/

void ctOutputError
		(
		int				Level,
		ctConstStr		ShortMessage,
		ctConstStr		MessageStr,
		ctConstStr		MessageId,
		ctConstStr		Path,
		int				Line,
		int				Column
		);

void ctOutputWarning
		(
		int				Level,
		ctConstStr		ShortMessage,
		ctConstStr		MessageStr,
		ctConstStr		MessageId,
		ctConstStr		Path,
		int				Line,
		int				Column
		);

void ctOutputMessage
		(
		ctConstStr		ShortMessage,
		ctConstStr		MessageStr,
		ctConstStr		MessageId,
		ctConstStr		Path,
		int				Line,
		int				Column
		);


#ifdef __cplusplus
	}
#endif


// -------------------------------------------------- Functions


#endif
