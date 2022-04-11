
#ifndef __DISPLAY_H__
#define __DISPLAY_H__


/*
	Desc : Display.h
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


extern char waBuffer[];
extern BOOL	GlobalUseDiagnostic;
extern BOOL	GlobalShowConsole;

#ifdef LINT_ARGS

#ifdef __WALD__
	void waOpenDisplay (HWND ConnectionHandle, ctConstStr ToolName);
	void waCloseDisplay (void);
	void waDisplaySetConnection (HWND ConnectionHandle);
	void pOpenConnection (HANDLE ConnectionHandle, ctConstStr ToolName);
#endif
	void waDisplayMessage (ctConstStr Message);
	void waDisplayAppendString (ctConstStr Str);
	void waDisplayAppendChar (ctChar Char);
	void waDisplayFlush (void);
	void waDisplayError (ctConstStr ErrorMessage);
	void waDisplayErrorAtLine (ctConstStr ErrorMessage, ctConstStr Path, long Line, int ErrorLevel);
	void waDisplayWarningAtLine (ctConstStr WarningMessage, ctConstStr Path, long Line, int Level);
	void waDisplayLastMessage (void);
	short waDisplayPause (ctConstStr Message);
	void waDisplay2Message (ctConstStr Message,ctConstStr Message2);
	void pConvertMessageCharSet (void);
#else

#ifdef	WIN32
#ifdef __WALD__
	#define waOpenDisplay()
	#define waCloseDisplay()
	#define waDisplaySetConnection()
	#define pOpenConnection()	
#endif
	#define waDisplayMessage()
	#define waDisplayAppendString()
	#define waDisplayAppendChar()
	#define waDisplayFlush()
	#define waDisplayError()
	#define waDisplayErrorAtLine()
	#define waDisplayWarningAtLine()
	#define waDisplayLastMessage()
	#define waDisplayPause()
	#define waDisplay2Message()
	#define pConvertMessageCharSet()
#endif
#define waDISPLAY
#endif

#endif

