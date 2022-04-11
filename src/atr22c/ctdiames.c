
/*
	Desc : ctDiaMes.c
	Proj : Common Tool
	Copyright (c) 1997-98 Amenesik / Sologic  

	Diagnostic Messages
		-	Error
		-	Warning
		-	Message, etc.
		
	Tool & common definition/info.

	Modifications list :
	1/Sept/1997  		JPH	File creation
	
*/

#include "ctDiaMes.h"


#include <string.h>

/*
	Fast implementation:
	
	Each message structure is transformed into a single string.
	The string is passed using "global token" and "post message".
	
	Each message string is composed of message token separated with character tab '\t'
	this character CANNOT appears in any of the token.
	
	The token cannot begin by following


*/



// -------------------------------------------------- 

void ctClearDiagnostic
		(
		INOUT		ctDiagnosticPtr		Diagnostic,
		IN			BOOL						ClearBuffer
		)
	{
	if (ClearBuffer)
		{
		Diagnostic->Buffer = 0;
		Diagnostic->BufferLength = 0;
		}

	if (Diagnostic->Buffer && Diagnostic->BufferLength)
		Diagnostic->Buffer[0] = '\0';
		
	Diagnostic->ContentLength = 0;
	
	Diagnostic->Kind = 0;
	Diagnostic->Panel = 0;
	Diagnostic->ShortMessage = 0;
	Diagnostic->Message = 0;
	Diagnostic->MessageId = 0;

	Diagnostic->ToolName = 0;
	Diagnostic->File = 0;
	Diagnostic->Column = 0;
	Diagnostic->Line = 0;
	Diagnostic->EndLine = 0;
	Diagnostic->EndColumn = 0;
	
	Diagnostic->pConnectionHandle = 0;
	}
	


// -------------------------------------------------- 



ctConstStr ctBufferAppend
		(
		OUT		ctStr					Buffer,
		IN			int 					BufferLength,
		INOUT		int *					ContentLength,
		IN			ctConstStr			Value,
		IN			int					ValueLength
		)
	{
	/*
		Append a string to the end of a limited buffer.
	
		Compute total content length 
		(I.e. total length needed to store info, independent 
		of buffer length).
		
		Accept null and empty buffer
	*/

	ctConstStr Result = 0;

	if (*ContentLength == 0)
		(*ContentLength)++;	/* for ending \0 */
	(*ContentLength) += ValueLength;
	
	
	if (Buffer && (BufferLength>0))
		{
		BufferLength--; /* for ending '\0' */

		/* Search end of string */
		while (BufferLength && *Buffer)
			{
			Buffer++;
			BufferLength--;
			}
			
		Result = Buffer;
			
		while (BufferLength-- && ValueLength--)
			{
			*Buffer++ = *Value++;
			}
			
		*Buffer++ = '\0';
		}

	return Result;
	}
	
	
	


	

// -------------------------------------------------- 


// -------------------------------------------------- 



// -------------------------------------------------- End Of File


