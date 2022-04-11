
/*
	Desc : ctDiaIn.c
	Proj : Common Tool
	Copyright (c) 1997 Amenesik / Sologic  

	Input Of Diagnostic Messages
		-	Error
		-	Warning
		-	Message, etc.

	Modifications list :
	1/Sept/1997  		JPH	File creation
	
*/

#include "ctDiaIn.h"
#include "ctDiaMes.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct ctDiagnosticTokenStruct
	{
	ctConstStr		TokenStr;
	ctByte			TokenCode;
	ctByte			Parameter;
	} ctDiagnosticToken;
	
typedef ctDiagnosticToken CT_FAR * ctDiagnosticTokenPtr;
	
// -------------------------------------------------- 

ctDiagnosticToken gTokenTable [] = 
	{

	{CT_DIAGNOSTIC_MESSAGE_STR, 		CT_DIAGNOSTIC_KIND_TOKEN,	CT_DIAGNOSTIC_MESSAGE},
	
	{CT_DIAGNOSTIC_WARNING1_STR,		CT_DIAGNOSTIC_KIND_TOKEN,	CT_DIAGNOSTIC_WARNING1},
	{CT_DIAGNOSTIC_WARNING2_STR,		CT_DIAGNOSTIC_KIND_TOKEN,	CT_DIAGNOSTIC_WARNING2},
	{CT_DIAGNOSTIC_WARNING3_STR,		CT_DIAGNOSTIC_KIND_TOKEN,	CT_DIAGNOSTIC_WARNING3},
	{CT_DIAGNOSTIC_WARNING4_STR,		CT_DIAGNOSTIC_KIND_TOKEN,	CT_DIAGNOSTIC_WARNING4},
	{CT_DIAGNOSTIC_WARNING5_STR,		CT_DIAGNOSTIC_KIND_TOKEN,	CT_DIAGNOSTIC_WARNING5},
	{CT_DIAGNOSTIC_ERROR_STR,			CT_DIAGNOSTIC_KIND_TOKEN,	CT_DIAGNOSTIC_ERROR},
	{CT_DIAGNOSTIC_FATAL_STR,			CT_DIAGNOSTIC_KIND_TOKEN,	CT_DIAGNOSTIC_FATAL},

	{CT_DIAGNOSTIC_INFORMATION_STR,			CT_DIAGNOSTIC_KIND_TOKEN,	CT_DIAGNOSTIC_INFORMATION},
	{CT_DIAGNOSTIC_PROGRESSION_STR,			CT_DIAGNOSTIC_KIND_TOKEN,	CT_DIAGNOSTIC_PROGRESSION},
	{CT_DIAGNOSTIC_CLEAR_STR, 			CT_DIAGNOSTIC_KIND_TOKEN,	CT_DIAGNOSTIC_CLEAR},
	{CT_DIAGNOSTIC_BEEP_STR,			CT_DIAGNOSTIC_KIND_TOKEN,	CT_DIAGNOSTIC_BEEP},
	{CT_DIAGNOSTIC_PING_STR,			CT_DIAGNOSTIC_KIND_TOKEN,	CT_DIAGNOSTIC_PING},		/* <End> Line[,Column]*/

	{CT_DIAGNOSTIC_BUILD_STR,			CT_DIAGNOSTIC_PANEL_TOKEN,	CT_DIAGNOSTIC_BUILD},
	{CT_DIAGNOSTIC_TRACE_STR,			CT_DIAGNOSTIC_PANEL_TOKEN,	CT_DIAGNOSTIC_TRACE},
	{CT_DIAGNOSTIC_DEBUG_STR,			CT_DIAGNOSTIC_PANEL_TOKEN,	CT_DIAGNOSTIC_DEBUG},
	{CT_DIAGNOSTIC_GENERATION_STR,		CT_DIAGNOSTIC_PANEL_TOKEN,	CT_DIAGNOSTIC_GENERATION},

	{CT_DIAGNOSTIC_TOOL_NAME_STR,		CT_DIAGNOSTIC_TOOL_TOKEN,			0},		/* <ToolName> FilePath*/
	{CT_DIAGNOSTIC_FILE_STR,			CT_DIAGNOSTIC_PATH_TOKEN,			0},		/* <FilePath> FilePath*/

	{CT_DIAGNOSTIC_START_STR,			CT_DIAGNOSTIC_START_TOKEN,			0},		/* <Start> Line[,Column]*/
	{CT_DIAGNOSTIC_END_STR,				CT_DIAGNOSTIC_END_TOKEN,			0},		/* <End> Line[,Column]*/

	
	{0, 0, 0}
	};


// -------------------------------------------------- 	
	
STATIC ctConstStr pEatDiagnosticToken
		(
		IN		ctConstStr			Message,
		OUT	int *					TokenCode,
		OUT	int *					ParameterCode,
		OUT	ctConstStr *		Parameter,
		OUT	int *					ParameterLength
		);

STATIC ctConstStr pEatDiagnosticToken
		(
		IN		ctConstStr			Message,
		OUT	int *					TokenCode,
		OUT	int *					ParameterCode,
		OUT	ctConstStr *		Parameter,
		OUT	int *					ParameterLength
		)
	{
	ctConstStr EndOfToken = Message;
	int Lg;
	
	*TokenCode = CT_END_OF_DIAGNOSTIC_TOKEN;
	*ParameterCode = 0;
	*Parameter = 0;
	*ParameterLength = 0;

	if (Message && *Message)
		{
		ctDiagnosticTokenPtr Token = &gTokenTable[0];

		*TokenCode = CT_DIAGNOSTIC_POSITION_TOKEN;
		
		while (Token && Token->TokenStr)
			{
			Lg = strlen(Token->TokenStr);
			
			if (strncmp(Token->TokenStr,Message,Lg) ==0)
				{
				/* Match */
				EndOfToken = &Message[Lg];
				
				*TokenCode 				= Token->TokenCode;
				*ParameterCode 		= Token->Parameter;
				
				break;
				}
			Token++;
			}

		*Parameter = EndOfToken;
		Lg = 0;
		while (*EndOfToken)
			{
			if (*EndOfToken++ == '\t')
				break;				
			else
				Lg++;
			}
	
		*ParameterLength = Lg;
		}

	
	return EndOfToken;
	}

// -------------------------------------------------- 

STATIC ctConstStr pAddToDiagnosticBuffer
		(
		IN			ctConstStr						Parameter,
		IN			int								ParameterLength,
		INOUT		ctDiagnosticPtr		Diagnostic
		);

STATIC ctConstStr pAddToDiagnosticBuffer
		(
		IN			ctConstStr			Parameter,
		IN			int					ParameterLength,
		INOUT		ctDiagnosticPtr	Diagnostic
		)
	{
	/* 
		Append to the end of buffer;
		Return pointer to begin of string added 
		(in the buffer);
		
	*/
	ctConstStr Result = ctBufferAppend
		(
		Diagnostic->Buffer,
		Diagnostic->BufferLength,
		&Diagnostic->ContentLength,
		Parameter,
		ParameterLength
		);
	ctBufferAppend
		(
		Diagnostic->Buffer,
		Diagnostic->BufferLength,
		&Diagnostic->ContentLength,
		"\t",
		1
		);
		
	return Result;
	}

// -------------------------------------------------- 


void ctScanDiagnostic 
		(
		INOUT	ctDiagnosticPtr	Diagnostic,
		IN		ctConstStr			Str
		)
	{
	ctStr					Car;
	int 					TokenCode;
	int 					ParameterCode;
	ctConstStr 			Parameter;
	int 					ParameterLength;
	int					Cpt = 0;		// for token by position
	
	ctClearDiagnostic (Diagnostic,FALSE);
	
	do
		{
		Str = pEatDiagnosticToken
			(
			Str,
			OUT	&TokenCode,
			OUT	&ParameterCode,
			OUT	&Parameter,
			OUT	&ParameterLength
			);
		
		switch (TokenCode)
			{
			case CT_END_OF_DIAGNOSTIC_TOKEN:
				break;
				
			case CT_DIAGNOSTIC_KIND_TOKEN:
				Diagnostic->Kind = ParameterCode;
				break;
				
			case CT_DIAGNOSTIC_PANEL_TOKEN:
				Diagnostic->Panel = ParameterCode;
				break;

			case CT_DIAGNOSTIC_TOOL_TOKEN:
				Diagnostic->ToolName = pAddToDiagnosticBuffer (Parameter,ParameterLength,Diagnostic);
				break;
				
			case CT_DIAGNOSTIC_PATH_TOKEN:
				Diagnostic->File = pAddToDiagnosticBuffer (Parameter,ParameterLength,Diagnostic);
				break;
				
			case CT_DIAGNOSTIC_START_TOKEN:
				sscanf(Parameter,"%ld,%ld",&Diagnostic->Line,&Diagnostic->Column);
			
				break;
				
			case CT_DIAGNOSTIC_END_TOKEN:
				sscanf(Parameter,"%ld,%ld",&Diagnostic->EndLine,&Diagnostic->EndColumn);
				break;
			
			default:
				Cpt++;
				switch(Cpt)
					{
					case 1:
						Diagnostic->ShortMessage = 
							pAddToDiagnosticBuffer (Parameter,ParameterLength,Diagnostic);
						break;
					case 2:
						Diagnostic->Message = 
							pAddToDiagnosticBuffer (Parameter,ParameterLength,Diagnostic);
						break;
					case 3:
						Diagnostic->MessageId = 
							pAddToDiagnosticBuffer (Parameter,ParameterLength,Diagnostic);
						break;
						
					default:
						; /* should never happen */
					}
			}
		}
	while (TokenCode != CT_END_OF_DIAGNOSTIC_TOKEN);
	
	/* Replace All '\t' by a \0*/
	if (Diagnostic->Buffer && Diagnostic->BufferLength)
		{
		Car = Diagnostic->Buffer;
		while (*Car)
			if (*Car=='\t')
				*Car++= '\0';
			else
				Car++;
		}
	}
	



// -------------------------------------------------- 


void ctScanAndAllocatedDiagnostic
		(
		INOUT	ctDiagnosticPtr	Diagnostic,
		IN		ctConstStr			Str,
		IN		ctBoolean			MustInitialise
		)
	{
	if (MustInitialise)
		ctClearDiagnostic(Diagnostic,TRUE);
	else
		{
		ctFreeDiagnostic (Diagnostic);
		}
	
	ctScanDiagnostic (Diagnostic,Str);
	
	if (Diagnostic->ContentLength)
		{
		Diagnostic->Buffer = malloc(Diagnostic->ContentLength);
		Diagnostic->BufferLength = Diagnostic->ContentLength;
		
		ctScanDiagnostic (Diagnostic,Str);
		}
	}

// -------------------------------------------------- 
		
void ctFreeDiagnostic
		(
		INOUT	ctDiagnosticPtr	Diagnostic
		)
	{
	if (Diagnostic->Buffer)
		{
		free(Diagnostic->Buffer);
		}
	
	Diagnostic->Buffer = 0;
	Diagnostic->BufferLength = 0;
	}

void ctDeclareDiagnosticReceiver (HWND DiagnosticReceiver)
	{
	/*
		Store handle in environement variable
	*/
	
	long HandleAsLong;
	char Buffer [30];
	
	HandleAsLong = (long) DiagnosticReceiver;
	sprintf(Buffer,"%lx",HandleAsLong);
	
	if (
		!SetEnvironmentVariable
			(
	    	CT_DIAGNOSTIC_HANDLE_ENV_VARIABLE,	/* address of environment variable name */
   	 	(LPCTSTR) Buffer 	/* address of new value for variable */
   		)
		)
		{
		ODS("### ERROR - ctDiaOut::ctDeclareDiagnosticReceiver - Cannot set env. variable");
		}	
	}



// -------------------------------------------------- End Of File


