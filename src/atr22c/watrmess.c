/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1996
 *	Module  : ATR
 *	Fichier : WATRMESS.C
 *	Version : 2.2a
 *	Date    : 24/09/97
 *	Systeme : Windows 95/NT
 *
 *	Message du traducteur dans un output windows
 * 
 *	[Code]
 *
 */


/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *  28/03/01 : (#BG) Add current source file name in Message Box title.
 *  28/03/01 : (#BG) Modify x_cprintf() for multiple calls of TranslateForWindows() for the same message.
 */


#define __WINDOWS_SOURCE__		/* source pour Windows */
#include "ctdiaout.h"
#include "ctdiag.h"
#include "longname.h"
#include "watrmess.h"
#include "watr.h"
#include "ctCarSet.h"
#include "Trmess.hg"
#include "Trmess.he"
#include <stdio.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL ctReOpenDiagnostic(int JuneHandle)
{
	OptIdra = ctOpenDiagnostic (&Diag, (HWND)JuneHandle, "");
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL ctOutputErrorDiagnostic2
		(
		IN			int					Level,
		IN			ctConstStr			FileName,
		IN			long				Line,
		IN			long				Column,
		IN			ctConstStr			ShortMessage,
		IN			ctConstStr			MessageStr
		)
{
	char* message;
	int length1=0;
	int length2=0;
	BOOL result;
	char* temp;

	if (ShortMessage) length1 = strlen (ShortMessage);
	if (MessageStr) length2 = strlen (MessageStr);
	
	
	message = malloc(length1+length2+2);
	temp = malloc(length1+1);
	
	strcpy(temp, ShortMessage);
	if (MessageStr) 
//		message = strcat((char*)ShortMessage, MessageStr);
		sprintf(message, "%s %s", ShortMessage, MessageStr);
	else
		message = (char*)ShortMessage;

	
	Diag.File=FileName;
	Diag.Line=Line;
	Diag.Column=Column;
	
	TranslateForWindows(message);
	result = ctOutputErrorDiagnostic(&Diag, Level, message, NULL, 0);
	strcpy((char*)ShortMessage, temp);

	free(message);
	free(temp);

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL ctOutputWarningDiagnostic2
		(
		IN			int					Level,
		IN			ctConstStr			FileName,
		IN			long				Line,
		IN			long				Column,
		IN			ctConstStr			ShortMessage,
		IN			ctConstStr			MessageStr
		)
{
	char* message;
	int length1=0;
	int length2=0;
	BOOL result;
	char* temp;

	if (ShortMessage) length1 = strlen (ShortMessage);
	if (MessageStr) length2 = strlen (MessageStr);
	
	
	message = malloc(length1+length2+2);
	temp = malloc(length1+1);
	
	strcpy(temp, ShortMessage);
	if (MessageStr) 
//		message = strcat((char*)ShortMessage, MessageStr);
		sprintf(message,"%s %s",(char*)ShortMessage, (char*)MessageStr);
	else
		message = (char*)ShortMessage;

	
	Diag.File=FileName;
	Diag.Line=Line;
	Diag.Column=Column;

	TranslateForWindows(message);
	result = ctOutputWarningDiagnostic(&Diag, Level, message, NULL, 0);
	strcpy((char*)ShortMessage, temp);

	free(message);
	free(temp);

	return result;

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL ctOutputMessageDiagnostic2
		(
		IN			ctConstStr			ShortMessage,
		IN			ctConstStr			MessageStr
		)
{
	TranslateForWindows((char*)ShortMessage);
	TranslateForWindows((char*)MessageStr);

	return ctOutputMessageDiagnostic(&Diag, ShortMessage, MessageStr, 0);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ctSetToolName (IN ctConstStr ToolName)
{
	Diag.ToolName=ToolName;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char ouinonInMsgBox(const char* message, char* FileName, char* VarName, char ryes, char rno, int askToContinue)
/* ouinon dans une messageBox pour les #rdef et #include */
{
	char Title[128];
	char* Buf;
	int Result;


	Buf = malloc(strlen(message) + strlen(VarName) + strlen(GetUserMessage(errlex0bis)) + 5);

	/* #BG 28/03/01 */
	strcpy(Buf, message);
	TranslateForWindows((char*)Buf);

	if (askToContinue)
		sprintf(Buf,"%s \"%s\"\n%s",Buf,VarName,GetUserMessage(errlex0bis));
	else
		sprintf(Buf,"%s \"%s\"",Buf,VarName);

	/* #BG 28/03/01 */
	sprintf(Title, "WATR \"%s\"", FileName);

	/* ouinon */
	Result = MessageBox(NULL, Buf, Title, MB_YESNO|MB_APPLMODAL);

	free(Buf);

	if (Result == IDYES) 
		return ryes;
	else
		return rno;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL TranslateForWindows(char* message)
{
	if (message) ctConvertString(&ConversionTable, message);
	return TRUE;
}


#ifdef USE_LONG_NAMES // Non défini

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void lnLongToShort2
		(
		IN		ctConstStr		LongName,
		OUT	ctStr				ShortName,
		IN		long			ShortNameLength
		)
{
	lnLongToShort(LongNameContext, LongName, ShortName, ShortNameLength);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void lnIsLong2
		(
		IN		ctConstStr		ShortName,
		OUT	ctBoolean *		IsResult
		)
{
	lnIsLong(LongNameContext,ShortName,IsResult);
}

#endif