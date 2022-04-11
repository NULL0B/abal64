
/*
	Desc : ctDiaOut.c
	Proj : Common Tool
	Copyright (c) 1997-98 Amenesik / Sologic  

	Ouput Diagnostic Messages
		-	Error
		-	Warning
		-	Message, etc.

	Modifications list :
	1/Sept/1997  		JPH	File creation
	
*/

#include "ctdiaout.h"
#include "ctdiames.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>	// sprintf

#define INVALID_CONNECTION		((HANDLE)(-1))


ctDiagnostic gDefaultDiagnostic =
	{
	/* IN */
	0,									/* Buffer */
	0,									/* BufferLength */
	
	/* OUT*/
	0,			/* ContentLength */
	
	/* OUT */
	CT_DIAGNOSTIC_BUILD,			/* Panel */
	CT_DIAGNOSTIC_MESSAGE,		/*	Kind */

	0,									/* ShortMessage */
	0,									/* Message */
	0,									/* MessageId */
	
	0,									/* Path */
	0,									/* Line */
	0,									/* StartColumn */
	0,									/* EndLine */
	0,									/* EndColumn */
	
	0									/* ConnectionHandle */
	};


ctDiagnostic * GlobalDiagnostic = &gDefaultDiagnostic;




// -------------------------------------------------- 

#define APPEND_LITERAL(LIT) ctBufferAppend (Buffer,BufferLength,&ContentLength,LIT, strlen(LIT)); \
	FirstOne = FALSE;
#define APPEND_SEPARATOR()	\
	if (!FirstOne) \
		ctBufferAppend (Buffer,BufferLength,&ContentLength,"\t",1);

// -------------------------------------------------- 

		
int ctBuildDiagnostic 
		(
		IN			ctDiagnosticPtr		Diagnostic,
		OUT		ctStr						Buffer,
		OUT		int						BufferLength
		);

int ctBuildDiagnostic 
		(
		IN			ctDiagnosticPtr		Diagnostic,
		OUT		ctStr						Buffer,
		OUT		int						BufferLength
		)
	{
	/*
		Build a diagnostic message into the buffer.
	*/
	int ContentLength = 0;
	BOOL FirstOne = TRUE;
	
	if (Buffer && BufferLength)
		Buffer[0]='\0';
	
	
	if (Diagnostic->ShortMessage && *(Diagnostic->ShortMessage))
		{
		APPEND_LITERAL (Diagnostic->ShortMessage);
		}

	if (Diagnostic->Message && *(Diagnostic->Message))
		{
		APPEND_SEPARATOR();
		APPEND_LITERAL (Diagnostic->Message);
		}

	if (Diagnostic->MessageId && *(Diagnostic->MessageId))
		{
		APPEND_SEPARATOR();
		APPEND_LITERAL (Diagnostic->MessageId);
		}

	if (Diagnostic->Kind)
		{
		APPEND_SEPARATOR();
		switch(Diagnostic->Kind)
			{
			case CT_DIAGNOSTIC_WARNING1:
				APPEND_LITERAL (CT_DIAGNOSTIC_WARNING1_STR);
				break;
			case CT_DIAGNOSTIC_WARNING2:
				APPEND_LITERAL (CT_DIAGNOSTIC_WARNING2_STR);
				break;
			case CT_DIAGNOSTIC_WARNING3:
				APPEND_LITERAL (CT_DIAGNOSTIC_WARNING3_STR);
				break;
			case CT_DIAGNOSTIC_WARNING4:
				APPEND_LITERAL (CT_DIAGNOSTIC_WARNING4_STR);
				break;
			case CT_DIAGNOSTIC_WARNING5:
				APPEND_LITERAL (CT_DIAGNOSTIC_WARNING5_STR);
				break;
				
			case CT_DIAGNOSTIC_ERROR:
				APPEND_LITERAL (CT_DIAGNOSTIC_ERROR_STR);
				break;
			case CT_DIAGNOSTIC_INFORMATION:
				APPEND_LITERAL (CT_DIAGNOSTIC_INFORMATION_STR);
				break;

			case CT_DIAGNOSTIC_PROGRESSION:
				APPEND_LITERAL (CT_DIAGNOSTIC_PROGRESSION_STR);
				break;

			case CT_DIAGNOSTIC_FATAL:
				APPEND_LITERAL (CT_DIAGNOSTIC_FATAL_STR);
				break;

			case CT_DIAGNOSTIC_CLEAR:
				APPEND_LITERAL (CT_DIAGNOSTIC_CLEAR_STR);
				break;
			case CT_DIAGNOSTIC_BEEP:
				APPEND_LITERAL (CT_DIAGNOSTIC_BEEP_STR);
				break;
			case CT_DIAGNOSTIC_FIRST:
				APPEND_LITERAL (CT_DIAGNOSTIC_FIRST_STR);
				break;
			case CT_DIAGNOSTIC_LAST:
				APPEND_LITERAL (CT_DIAGNOSTIC_LAST_STR);
				break;
			case CT_DIAGNOSTIC_PING:
				APPEND_LITERAL (CT_DIAGNOSTIC_PING_STR);
				break;

			case CT_DIAGNOSTIC_MESSAGE:
			default:
				APPEND_LITERAL (CT_DIAGNOSTIC_MESSAGE_STR);
				break;
			}
		}

	if (Diagnostic->Panel)
		{
		APPEND_SEPARATOR();
		switch(Diagnostic->Panel)
			{
			case CT_DIAGNOSTIC_TRACE:
				APPEND_LITERAL (CT_DIAGNOSTIC_TRACE_STR);
				break;
			case CT_DIAGNOSTIC_GREP:
				APPEND_LITERAL (CT_DIAGNOSTIC_GREP_STR);
				break;
			case CT_DIAGNOSTIC_DEBUG:
				APPEND_LITERAL (CT_DIAGNOSTIC_DEBUG_STR);
				break;
			case CT_DIAGNOSTIC_GENERATION:
				APPEND_LITERAL (CT_DIAGNOSTIC_GENERATION_STR);
				break;

			case CT_DIAGNOSTIC_BUILD:
			default:
				APPEND_LITERAL (CT_DIAGNOSTIC_BUILD_STR);
				break;
			}
		}
		
	if (Diagnostic->ToolName && *(Diagnostic->ToolName))
		{
		APPEND_SEPARATOR();
		APPEND_LITERAL (CT_DIAGNOSTIC_TOOL_NAME_STR);
		APPEND_LITERAL (Diagnostic->ToolName);
		}

	if (Diagnostic->File && *(Diagnostic->File))
		{
		APPEND_SEPARATOR();
		APPEND_LITERAL (CT_DIAGNOSTIC_FILE_STR);
		APPEND_LITERAL (Diagnostic->File);
		}
		
	if (Diagnostic->Line || Diagnostic->Column)
		{
		char StartBuffer [40];
		
		APPEND_SEPARATOR();
		APPEND_LITERAL (CT_DIAGNOSTIC_START_STR);
		sprintf(StartBuffer," %ld %ld", (long) Diagnostic->Line, (long) Diagnostic->Column);
		APPEND_LITERAL (StartBuffer);
		}

	if (Diagnostic->EndLine || Diagnostic->EndColumn)
		{
		char EndBuffer [40];
		
		APPEND_SEPARATOR();
		APPEND_LITERAL (CT_DIAGNOSTIC_END_STR);
		sprintf(EndBuffer," %ld %ld",(long) Diagnostic->EndLine, (long) Diagnostic->EndColumn);
		APPEND_LITERAL (EndBuffer);
		}

	return ContentLength;	
	}

	
// -------------------------------------------------- 
STATIC HWND pGetConnectionHandle(HWND ConnectionHandle);

ctBoolean ctOpenDiagnostic
		(
		INOUT		ctDiagnosticPtr		Diagnostic,
		IN			HWND						ConnectionHandle,
		IN			ctConstStr				ToolName
		)
	{
	/*
		return TRUE	if is opened

	*/
	ctBoolean Result = FALSE;

	if (!Diagnostic)
		Diagnostic = GlobalDiagnostic;

	ctClearDiagnostic (Diagnostic,TRUE);

	Diagnostic->pConnectionHandle = pGetConnectionHandle(ConnectionHandle);
	Diagnostic->ToolName = ToolName;
	
	if (Diagnostic->pConnectionHandle)
		{
		// Envoi d'un message de ping (are you there)
		Diagnostic->Kind = CT_DIAGNOSTIC_PING;
		ctOutputDiagnostic (Diagnostic);
		Diagnostic->Kind = CT_DIAGNOSTIC_MESSAGE;
		
		// If nobody there, connection handle is set to 0!
		}
	

	Result = (
				(Diagnostic->pConnectionHandle != 0)
				&& (Diagnostic->pConnectionHandle != INVALID_CONNECTION)
				);

	return Result;
	}

ctBoolean ctCloseDiagnostic
		(
		INOUT		ctDiagnosticPtr		Diagnostic
		)
	{
	/*
		return TRUE if was opened !

	*/

	ctBoolean Result = FALSE;

	if (!Diagnostic)
		Diagnostic = GlobalDiagnostic;

	Result = (Diagnostic->pConnectionHandle != 0);

	//int ToBeCompleted = TRUE;		// envoi message de fin, nettoie


	return Result;
	}


// -------------------------------------------------- 

STATIC HWND pGetConnectionHandle(HWND ConnectionHandle)
	{
	/*
		Get connection handle in environement variable
		
	*/
	ctBoolean	DiagnosticRerouted = FALSE;
	HWND Result = 0;
	char Buffer[30];
		
	if (ConnectionHandle)
		Result = ConnectionHandle;
	else
		{
		/*
			First, search in environment variable
			
		*/
		DWORD Lg = GetEnvironmentVariable
			(
			CT_DIAGNOSTIC_HANDLE_ENV_VARIABLE,	// address of environment variable name 
			(LPTSTR) Buffer,	// address of buffer for variable value 
			(DWORD) sizeof(Buffer)
			);	
		
		if (Lg >0)
			{
			long HandleAsLong = 0;
			sscanf(Buffer,"%lx", &HandleAsLong);
ODSlu("ConnectionHandle %lx", HandleAsLong);
		
			Result = (HANDLE) HandleAsLong;
			}
		}
				
	/* Read 'DiagnosticRerouted ' from 'ct.ini' */
	DiagnosticRerouted = GetPrivateProfileInt
		(
		"Diagnostic",
		"Rerouted",
		FALSE,	
		"ct.ini" 
	   );
		
	WritePrivateProfileString
 		(
		"Diagnostic",
		"Rerouted",	
		(DiagnosticRerouted?"1":"0"),
		"ct.ini" 
	   );

	
	if (!Result || DiagnosticRerouted)
		{
		/*
			Search the TRACE32 debug terminal
		*/
		#ifdef WIN32
		#define TRACE_WINDOW_CLASS		"TraceAtom32"
		#else
		#define TRACE_WINDOW_CLASS		"Trace"
		#endif
		HWND TraceWindow = FindWindow(TRACE_WINDOW_CLASS,0);

		if (TraceWindow)
			Result = TraceWindow;

		if (!Result)
			{
			Result = INVALID_CONNECTION;
			ODS("### ERROR - ctDiaOut::pGetConnectionHandle - Cannot get env. variable");
			}
		}
	
	return Result;
	}

// -------------------------------------------------- 



STATIC ctBoolean pOutputDiagnosticStr
		(
		IN			ctDiagnosticPtr		Diagnostic,
		IN			ctStr						DiagnosticStr
		);


STATIC ctBoolean pOutputDiagnosticStr
		(
		IN			ctDiagnosticPtr		Diagnostic,
		IN			ctStr						DiagnosticStr
		)
	{
	/*
		---------- Get the connection handle
	
	*/
	ctBoolean	Result = FALSE;
	HWND			ConnectionHandle = 0;
	
	ConnectionHandle = Diagnostic->pConnectionHandle;
	
	if (!ConnectionHandle && (ConnectionHandle != INVALID_CONNECTION))
		{
		/* Search connection handle in Environement */
		ConnectionHandle = Diagnostic->pConnectionHandle =
										 pGetConnectionHandle(0);
		}

	/*
		---------- Output the message
	
	*/

	if (ConnectionHandle && (ConnectionHandle != INVALID_CONNECTION))
		{
		/*
			Send Message & get the result back
		*/
		static UINT AddLineMessage = 0;
		LRESULT	MesResult = 0;
		ATOM		Atom;
		UINT		Size = strlen(DiagnosticStr);
		
		if (!AddLineMessage)
			{
			AddLineMessage = RegisterWindowMessage(CT_DIAGNOSTIC_ADD_LINE_MESSAGE);
			}
		
		Atom = GlobalAddAtom (DiagnosticStr);
		
		
		MesResult = SendMessage
			(
			ConnectionHandle,
			AddLineMessage, 
			(WPARAM) Size,
			(LPARAM) Atom 
			);

		GlobalDeleteAtom(Atom);

		ConnectionHandle = (HWND) MesResult;
		if (!MesResult)
			{
			/* Close the connection */
			ConnectionHandle = INVALID_CONNECTION;
			}
		
		Diagnostic->pConnectionHandle = ConnectionHandle;
		}
	else
		{
		ODS_("NC:");
		ODS(DiagnosticStr);
		}

	return Result;
	}
	

// -------------------------------------------------- Indirect Mode

ctBoolean ctOutputDiagnostic
		(
		INOUT		ctDiagnosticPtr		Diagnostic
		)
	{
	ctBoolean 	Result = FALSE;
	int			ContentLength = 0;

	if (!Diagnostic)
		Diagnostic = GlobalDiagnostic;

	
	/*
		Do all what's required to output the message.
	*/
	
	
	
	/*
		---------- Translate Diagnostic into a line!
	
	*/

#ifdef __CT_DEBUG__
	if (!Diagnostic->ToolName)
		Diagnostic->ToolName = CT_APPLICATION_NAME;

#endif



	if (Diagnostic->Buffer && Diagnostic->BufferLength)
		{
		/* Use static buffer */
		
		ctBuildDiagnostic (Diagnostic,Diagnostic->Buffer,Diagnostic->BufferLength);
		pOutputDiagnosticStr (Diagnostic,Diagnostic->Buffer);
		}
	else
		{
		ctStr Buffer = 0;
		
		ContentLength = ctBuildDiagnostic (Diagnostic,0,0);
		Buffer = malloc (ContentLength);
		ctBuildDiagnostic (Diagnostic,Buffer,ContentLength);

		pOutputDiagnosticStr (Diagnostic,Buffer);
		
		free(Buffer);
		}
		
	return Result;
	}



ctBoolean ctOutputErrorDiagnostic
		(
		INOUT		ctDiagnosticPtr	Diagnostic,
		IN			int					Level,
		IN			ctConstStr			ShortMessage,
		IN			ctConstStr			Message,
		IN			ctConstStr			MessageId
		)
	{
	if (!Diagnostic)
		Diagnostic = GlobalDiagnostic;

	Diagnostic->ShortMessage = ShortMessage;	
	Diagnostic->Message = Message;	
	Diagnostic->MessageId = MessageId;	
	
	if (Level >0)
		Diagnostic->Kind = CT_DIAGNOSTIC_FATAL;
	else
		Diagnostic->Kind = CT_DIAGNOSTIC_ERROR;
	
	return ctOutputDiagnostic(Diagnostic);
	}


ctBoolean ctOutputWarningDiagnostic
		(
		INOUT		ctDiagnosticPtr	Diagnostic,
		IN			int					Level,
		IN			ctConstStr			ShortMessage,
		IN			ctConstStr			Message,
		IN			ctConstStr			MessageId
		)
	{
	if (!Diagnostic)
		Diagnostic = GlobalDiagnostic;
		
	Diagnostic->ShortMessage = ShortMessage;	
	Diagnostic->Message = Message;	
	Diagnostic->MessageId = MessageId;	
	
	if ((Level >3) || (Level<1))
		Level = 1;
		
	Diagnostic->Kind = CT_DIAGNOSTIC_WARNING1 + Level -1;

	return ctOutputDiagnostic(Diagnostic);
	}
	

ctBoolean ctOutputMessageDiagnostic
		(
		INOUT		ctDiagnosticPtr	Diagnostic,
		IN			ctConstStr			ShortMessage,
		IN			ctConstStr			Message,
		IN			ctConstStr			MessageId
		)
	{
	if (!Diagnostic)
		Diagnostic = GlobalDiagnostic;
		
	Diagnostic->ShortMessage = ShortMessage;	
	Diagnostic->Message = Message;	
	Diagnostic->MessageId = MessageId;	
	
	Diagnostic->Kind = CT_DIAGNOSTIC_MESSAGE;

	return ctOutputDiagnostic(Diagnostic);
	}


void ctSetDiagFileLine
		(
		INOUT		ctDiagnosticPtr		Diagnostic,
		IN			ctConstStr				PathFile,
		IN			long						Line,
		IN			long						Column,
		IN			long						EndLine,
		IN			long						EndColumn
		)
	{
	if (!Diagnostic)
		Diagnostic = GlobalDiagnostic;
		
	Diagnostic->File = PathFile;
	Diagnostic->Line = Line;
	Diagnostic->Column = Column;
	Diagnostic->EndLine = EndLine;
	Diagnostic->EndColumn = EndColumn;
	}


void ctSetDiagLine
		(
		INOUT		ctDiagnosticPtr		Diagnostic,
		IN			long						Line,
		IN			long						Column,
		IN			long						EndLine,
		IN			long						EndColumn
		)
	{
	if (!Diagnostic)
		Diagnostic = GlobalDiagnostic;

	Diagnostic->Line = Line;
	Diagnostic->Column = Column;
	Diagnostic->EndLine = EndLine;
	Diagnostic->EndColumn = EndColumn;
	}

// -------------------------------------------------- Direct Mode


/*
	Direct mode:
		Parameter are repeated for every call.
		
		See "GlobalDiagnostic" for default.
		Panel == Build
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
		)
	{
	ctDiagnosticPtr Diagnostic = GlobalDiagnostic;
	
	Diagnostic->File = Path;
	Diagnostic->Line = Line;
	Diagnostic->Column = Column;
	Diagnostic->EndLine = 0;
	Diagnostic->EndColumn = 0;
	
	ctOutputErrorDiagnostic
		(
		Diagnostic,
		Level,
		ShortMessage,
		MessageStr,
		MessageId
		);
	}


void ctOutputWarning
		(
		int				Level,
		ctConstStr		ShortMessage,
		ctConstStr		MessageStr,
		ctConstStr		MessageId,
		ctConstStr		Path,
		int				Line,
		int				Column
		)
	{
	ctDiagnosticPtr Diagnostic = GlobalDiagnostic;
	
	Diagnostic->File = Path;
	Diagnostic->Line = Line;
	Diagnostic->Column = Column;
	Diagnostic->EndLine = 0;
	Diagnostic->EndColumn = 0;
	
	ctOutputWarningDiagnostic
		(
		Diagnostic,
		Level,
		ShortMessage,
		MessageStr,
		MessageId
		);
	}

void ctOutputMessage
		(
		ctConstStr		ShortMessage,
		ctConstStr		MessageStr,
		ctConstStr		MessageId,
		ctConstStr		Path,
		int				Line,
		int				Column
		)
	{
	ctDiagnosticPtr Diagnostic = GlobalDiagnostic;
	
	Diagnostic->File = Path;
	Diagnostic->Line = Line;
	Diagnostic->Column = Column;
	Diagnostic->EndLine = 0;
	Diagnostic->EndColumn = 0;
	
	ctOutputMessageDiagnostic
		(
		Diagnostic,
		ShortMessage,
		MessageStr,
		MessageId
		);
	}



ctBoolean ctDiagnosticAvailable (HWND ConnectionHandle)
	{
	ctBoolean Result = FALSE;
	HWND Handle;

	if ((ConnectionHandle == 0) || (ConnectionHandle == INVALID_CONNECTION))
		{
		Handle = pGetConnectionHandle(0);
		if ((ConnectionHandle != 0) && (ConnectionHandle != INVALID_CONNECTION))
			Result = TRUE;
		}
	else
		{
		Result = TRUE;
		}
	return Result;
	}


// -------------------------------------------------- End Of File


