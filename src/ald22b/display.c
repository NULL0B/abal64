
/*
	Desc : waDisplay.c
	Proj : WALD
	Copyright (c) 1998 Amenesik / Sologic  

	Display procedure for WALD
		-	Error
		-	Warning
		-	Message, etc.
		
		
	Note: under all other systems, the function does nothing.
*/

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	09/07/98 : JPH	File creation
 *	28/06/01 : (#BG) Suppression de "error:" devant chaque message.
 * 08/11/01 : (#BG) Réunification des fichiers waDisplay.* et waDisp.*
 */

#include <stdio.h>

#include "project.h"
#include "display.h"

#ifdef __WALD__
#include "ctdiaout.h"
#include "ctwincon.h"
#include "ctcarset.h"	// Pour pConvertMessageCharSet()
#endif


// -------------------------------------------------- 

#define MAX_MESSAGE_LENGTH	400

// ------ public globals
char waBuffer[MAX_MESSAGE_LENGTH];
BOOL	GlobalUseDiagnostic = TRUE;
BOOL	GlobalShowConsole = FALSE;


// ------ private globals
ctChar	gMessage[MAX_MESSAGE_LENGTH];
int		gLastOfMessage = 0;


// -------------------------------------------------- Display using Diagnostic OR Console

#ifdef __WALD__

void waOpenDisplay (HWND ConnectionHandle, ctConstStr ToolName)
{
	gLastOfMessage = 0;
	gMessage[gLastOfMessage]='\0';

	pOpenConnection(ConnectionHandle, ToolName);	
}


void waCloseDisplay (void)
{
	ctCloseDiagnostic (0);
} 


void waDisplaySetConnection (HWND ConnectionHandle)
{
	/*
		Reset connection after an (un)successfull open.
	*/
	
	pOpenConnection(ConnectionHandle,GlobalDiagnostic->ToolName);
}


void pOpenConnection (HANDLE ConnectionHandle, ctConstStr ToolName)
{
	if (!ctOpenDiagnostic (0, ConnectionHandle, ToolName)){
		GlobalUseDiagnostic = FALSE;
		GlobalShowConsole = TRUE;
	};
}

#endif

// -------------------------------------------------- Display using Diagnostic OR Console

short waDisplayPause (ctConstStr Message)
{
	/*
		return -1 to stop??
		0 otherwise ??
	*/
	waDisplayFlush ();
	
#ifndef __WALD__
	lkprintf("%s",Message); getch();
	return 0;
#else
	return MessageBox(0,Message,CT_APPLICATION_NAME,0);
#endif
}


void waDisplayLastMessage (void)
{
	waDisplayFlush ();
	lkprintf("\n");
}


void waDisplayError (ctConstStr ErrorMessage)
{
	int			ErrorLevel = 0;
	ctConstStr 	ShortMessage = 0;
	ctConstStr 	MessageId = 0;
	ctConstStr 	Path = 0;
	int			Line = 0;
	int			Column = 0;
	
	int ToBeImplemented = 1;
	// Add line where error occurs, error level etc.
	waDisplayAppendString (ErrorMessage);
		
	pConvertMessageCharSet ();

#ifdef __WALD__
	ctOutputError (ErrorLevel, ShortMessage, gMessage, MessageId, Path, Line, Column);
#endif

/* #BG 28/06/01	lkprintf("Error %d - %s \n",ErrorLevel, gMessage);*/
	lkprintf("%s \n", gMessage);
	gLastOfMessage = 0;
	gMessage[gLastOfMessage]='\0';
}


void waDisplayFlush (void)
{
	/*
		Flush current output
	*/	
	
	if (gLastOfMessage)
	{
		pConvertMessageCharSet ();

#ifdef __WALD__
		ctOutputMessage
			(
			0,				// ShortMessage
			gMessage,	// MessageStr
			0,				// MessageId
			0,				//	Path
			0,				// Line
			0				// Column
			);
#endif

		lkprintf("%s\n",gMessage);
	}

	gLastOfMessage = 0;
	gMessage[gLastOfMessage]='\0';
}


void waDisplayAppendChar (ctChar Char)
{
	// Add char to current message
	
	if (gLastOfMessage < (MAX_MESSAGE_LENGTH-1)){
		if (Char) gMessage[gLastOfMessage++] = Char;
		gMessage[gLastOfMessage] = '\0';
	}
}


void waDisplayAppendString (ctConstStr Str)
{
	// Add string to current message
	
	while (*Str)
		waDisplayAppendChar (*Str++);
}


void waDisplayMessage (ctConstStr Message)
{

	waDisplayAppendString (Message);

	// Display a new message
	pConvertMessageCharSet ();

#ifdef __WALD__
	ctOutputMessage 
		(
		0,				// ShortMessage
		gMessage,	// MessageStr
		0,				// MessageId
		0,				//	Path
		0,				// Line
		0				// Column
		);
#endif

	lkprintf("%s\n",gMessage);
	gLastOfMessage = 0;
	gMessage[gLastOfMessage]='\0';
}


void waDisplay2Message (ctConstStr Message,ctConstStr Message2)
{
	waDisplayAppendString(Message);
	waDisplayAppendChar(' ');		
	waDisplayMessage(Message2);
}


void waDisplayErrorAtLine (ctConstStr ErrorMessage, ctConstStr Path, long Line, int ErrorLevel)
{
	ctConstStr 	ShortMessage = 0;
	ctConstStr 	MessageId = 0;
	long			Column = 0;
	
	waDisplayAppendString (ErrorMessage);
	
	pConvertMessageCharSet ();

#ifdef __WALD__
	ctOutputError (ErrorLevel, ShortMessage, gMessage, MessageId, Path, Line, Column);
#endif

	lkprintf("Error %d - %s @%s %ld\n",ErrorLevel,gMessage,Path,Line);
	gLastOfMessage = 0;
	gMessage[gLastOfMessage]='\0';
}


void waDisplayWarningAtLine (ctConstStr WarningMessage, ctConstStr Path, long Line, int Level)
{
	ctConstStr 	ShortMessage = 0;
	ctConstStr 	MessageId = 0;
	long			Column = 0;
	
	waDisplayAppendString (WarningMessage);

	pConvertMessageCharSet ();

#ifdef __WALD__
	ctOutputWarning (Level, ShortMessage, gMessage, MessageId, Path, Line, Column);
#endif

	lkprintf("Warning %d - %s @%s %ld\n",Level,gMessage,Path,Line);
	gLastOfMessage = 0;
	gMessage[gLastOfMessage]='\0';
}


void pConvertMessageCharSet (void)
{
	/*
		Convert message's alphabet.
		
		Message are expressed in DOS CharacterSet!
		
		under windows, must be converted to Windows!
		
	*/

#ifdef __WALD__

	static ctCharSetConversion		Table;
	static ctBoolean					IsInited = 0;
	
	if (!IsInited)
	{
		IsInited = TRUE;
		
		ctPrepareConversion 
			(
			&Table, 
			CT_DOS_CHARSET, 
			CT_WINDOWS_CHARSET, 
			'?' 						// DefaultCharacter
			);
	}

	ctConvertString (&Table, gMessage);

#endif
}


// -------------------------------------------------- End Of File

