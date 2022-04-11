/*
	Desc : fn_parse.c
	Proj : amake
	Copyright (c) 1993-98 Amenesik / Sologic  

	
	Modifications list :
	17/July/1998  JPH  Restructuration for WAMAKE32
*/

/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *	Module  : ATR
 *	Fichier : FN_PARSE.C
 *	Version : 2.1d
 *	Date    : 22/11/95
 *	Systeme : DOS / PRL / UNIX / VMS
 *
 *	Traducteur ABAL
 *
 *	[Decoupage d'un nom de fichier]
 *
 */

 /*
 * Mises a jour :
 * ------------
 *	18/07/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 *	11/09/90 : Correction bug prologue ou IP,IF et IS etaient consideres
 *		   comme des noms de fichier.
 *	04/12/90 : Prototypage fn_memcpy pour non LINT_ARGS
 *	------------ 2.1d -------------------------------------------------
 *	22/11/95 : version dediee 2.1
 */

 /*
	JPH 2/July/1998	Partial rewritting : change variable name,
		isolate one function for each system,
		add support for msdos/win32 "long filenames"
 */

#include "project.h"

#ifndef __FN_PARSE_H__
#include "fn_Parse.h"
#endif

#include <ctype.h>


#if 0 // JPH
// renamed in source fnmemcpy into xmemcpy!!!
	#ifdef LINT_ARGS
	static char *fnmemcpy(OUT char * To, IN char * From, int Length);
	#else /* ! LINT_ARGS */
	static char *fnmemcpy();
	#endif /* LINT_ARGS */


	static char *fnmemcpy(rptr , sptr , len )
	char *rptr;
	char *sptr;
	int  len;
	{
		int	x;
		for ( x = 0; x < len; x++ ) *(rptr + x ) = *(sptr + x );
		return( rptr );
	}
#endif


int fn_parse_prologue (char *Source , char *Buffer , int	Mode, int CharCount);
int fn_parse_prologue (char *Source , char *Buffer , int	Mode, int CharCount)
	{
#ifdef	prologue
#endif /* prologue */ // Placer a la fin
	int	Implicite = FALSE;

	int	i = 0;
	int 	j = 0;
	int	ResultIndex = 0;

	#define PROL_SEPARATOR	0x005C	/* '\' */

	/* -------------------------------------------- */
	/* Amenesik / Sologic :    MD0.\*\*\filename.-ext:RRWW		*/
	/* -------------------------------------------- */

	/* Check for and Transfer Network Node Name */
	/* ---------------------------------------- */
	if ( Mode & FILE_NETWORK_NODE ) 
		{ 
		}
		

	/* Check for Implicte device identifiers */
	/* ------------------------------------- */
	if ( CharCount >= 3 ) 
		{
		/*
				i?.
				012
				
				where ? == s/f/p
		*/

		if ( Source[2] == '.' ) 
			{
			if (( *Source == 'i' ) || ( *Source == 'I' )) 
				{
				switch ( Source[1] ) 	
					{
					case 's' :
					case 'S' :
					case 'f' :
					case 'F' :
					case 'p' :
					case 'P' :
					/* Scan past Device Mnemonic */
					/* ------------------------- */
					if ( Mode & FILE_DEVICE ) 
						{
						Xmemcpy
							(
							OUT	(char *) (Buffer + ResultIndex) ,
							IN		(char *) Source , 
							3 
							);
						ResultIndex += 3;
						}
					Source += 3; 
					CharCount -= 3;
					Implicite = TRUE;
					}
				}
			}
		}

	/* Check for and Transfer Device Mnemonic */
	/* -------------------------------------- */
	if (( CharCount >= 4 ) && !Implicite )
		{
		/*
				MDx.
				0123
				
				where x == 0..9
		*/
		if ( Source[3] == '.' ) 
			{
			if (( Source[2] >= '0' ) && ( Source[2] <= '9' )) 
				{

				/* Scan past Device Mnemonic */
				/* ------------------------- */
				if ( Mode & FILE_DEVICE ) 
					{
					Xmemcpy
						(
						OUT	(char *) (Buffer + ResultIndex) ,
						IN		(char *) Source , 
						4 
						);
					ResultIndex += 4;
					}
				Source += 4; 
				CharCount -= 4;
				}
			}
		}
	i = CharCount;

	/* Scan BackWards to End of Path : Start of FileName */
	/* ------------------------------------------------- */
	while ((i > 0 ) && ( Source[i] != PROL_SEPARATOR )) 
		{ i--; }

	/* Check for Path Portion Found and if So Increment */
	/* ------------------------------------------------ */
	if ( Source[i] == PROL_SEPARATOR ) 
		{
		i++;
		}

	/* Check for and perform PathName transfer */
	/* --------------------------------------- */
	if ( Mode & FILE_PATH ) 
		{
		for ( j = 0; j < i; j++ ) 
			{
			Buffer[ResultIndex] = Source[j];
			ResultIndex++;
			}
		}

	/* Check for and Transfer filename */
	/* ------------------------------- */
	while ( i < CharCount ) 
		{
		if (( Source[i] != '.') && ( Source[i] != '-' ) && ( Source[i] != ':' ) ) 
			{
			if ( Mode & FILE_NAME ) 
				{
		 		Buffer[ResultIndex] = Source[i]; 
				ResultIndex++; 
				}
			i++;
			}
		else	
			{
			break;
			}
		}

	/* Check for and Transfer 'Extension' */
	/* ---------------------------------  */
	while ( i < CharCount ) 
		{
		if ( Source[i] == ':' ) 
			{
			break;
			}
		else	
			{
			if ( Mode & FILE_EXTENSION ) 
				{
		 		Buffer[ResultIndex] = Source[i];
				ResultIndex++; 
				}
			i++;
			}
		}

	/* Check for and Transfer 'Cles d'access' */
	/* -------------------------------------  */
	if ( Mode & FILE_PROLOGUE_PW ) 
		{
		while ( i < CharCount ) 
			{
	 		Buffer[ResultIndex++] = Source[i++]; 
			}
		}
	return ResultIndex;
	}

int fn_parse_UnixNotVms (char *Source , char *Buffer , int	Mode, int CharCount);
int fn_parse_UnixNotVms (char *Source , char *Buffer , int	Mode, int CharCount)
	{
#ifdef	unix
#ifndef	vms
#endif /* ! vms */
#endif /* unix */ // Placer a la fin

	int	i = 0;
	int 	j = 0;
	int	ResultIndex = 0;

	/* -------------------------------------------- */
	/* Unix :    /r/r/filename.ext			*/
	/* -------------------------------------------- */

	/* Check for and Transfer Network Node Name */
	/* ---------------------------------------- */
	if ( Mode & FILE_NETWORK_NODE ) 
		{ 
		}

	i = CharCount;

	/* Scan BackWards to End of Path : Start of FileName */
	/* ------------------------------------------------- */
	while ((i > 0 ) && ( Source[i] != '/' )) 
		{ i--; }

	/* Check for Path Portion Found and if So Increment */
	/* ------------------------------------------------ */
	if ( Source[i] == '/' ) 
		{
		i++;
		}

	/* Check for and perform PathName transfer */
	/* --------------------------------------- */
	if ( Mode & FILE_PATH ) 
		{
		for ( j = 0; j < i; j++ ) 
			{
			Buffer[ResultIndex] = Source[j]; 
			ResultIndex++;
			}
		}

	/* Check for and Transfer filename */
	/* ------------------------------- */
	while ( i < CharCount ) 
		{
		if ( Source[i] == '.') 
			{
			break; 
			}
		else	
			{
			if ( Mode & FILE_NAME ) 
				{
		 		Buffer[ResultIndex] = Source[i];
				ResultIndex++;
				}
			i++;
			}
		}

	/* Check for and Transfer Extension */
	/* -------------------------------- */
	if ( Mode & FILE_EXTENSION ) 
		{
		while ( i < CharCount ) 
			{
	 		Buffer[ResultIndex] = Source[i]; 
			ResultIndex++;
			i++;
			}
		}
	return ResultIndex;
	}
	
int fn_parse_vms (char *Source , char *Buffer , int	Mode, int CharCount);
int fn_parse_vms (char *Source , char *Buffer , int	Mode, int CharCount)
	{
#ifdef	vms
#endif /* vms */ // Placer a la fin

	int	i = 0;
	int 	j = 0;
	int	ResultIndex = 0;
	int   DeviceIndex = 0;

	/* -------------------------------------------- */
	/* Vms :    DUA0:[*.*.]filename.ext;version	*/
	/*	    *$*:filename.ext;version		*/
	/* -------------------------------------------- */
	i = CharCount;

	/* Scan BackWards to End of Path : Start of FileName */
	/* ------------------------------------------------- */
	while ((i > 0 ) && ( Source[i] != ':' ) && ( Source[i] != ']') ) 
		{ i--; }

	switch ( Source[i] ) 
		{

		case ':' :	/* Logical Name Separator Found */
				/* ---------------------------- */

				if ( Mode & FILE_PATH ) 
					{
					Xmemcpy
						(
						OUT	(char *) (Buffer + ResultIndex) ,
						IN		Source ,
						i
						);
					ResultIndex += i;
					Buffer[ResultIndex++] = ':';
					}
				i++;
				break;

		case ']' :	/* Directory Path Separator Found */
				/* ------------------------------ */
				j = i; /*Keep End of Path Index */

				/* Scan to Start of PATH */
				/* --------------------- */
				while ((i > 0 ) && ( Source[i] != '[' )) 
					{
					i--; 
					}
				DeviceIndex = 0; /* Zero Start of DEVICE */

				/* Check for and Extract Device */
				/* ---------------------------- */
				if ( Mode & FILE_DEVICE ) 
					{
					while ( DeviceIndex < i ) 
						{
						Buffer[ResultIndex++] = Source[DeviceIndex++];
						}
					}

				/* Check for and Extract PATH */
				/* -------------------------- */
				while ( i <= j ) 
					{
					if ( Mode & FILE_PATH ) 
						{
						Buffer[ResultIndex++] = Source[i];
						}
					i++;
					}
				break;

		default  :	/* Simple Filename or Logical Name */
				/* ------------------------------- */
				break;

		}

	/* Check for and Transfer filename */
	/* ------------------------------- */
	while ( i < CharCount ) 
		{
		if ( Source[i] == '.') 
			{ 
			break;
			}
		else	
			{
			if ( Mode & FILE_NAME) 
				{
		 		Buffer[ResultIndex++] = Source[i];
				}
			i++;
			}
		}

	/* Check for and Transfer Extension */
	/* -------------------------------- */
	while ( i < CharCount ) 
		{
		if ( *(Source + i) == ';' ) 
			{
			break;
			}
		if ( Mode & FILE_NAME ) 
			{
		 	Buffer[ResultIndex++] = Source[i]; 
			}
		i++;
		}

	/* Check for and Transfer Version Number */
	/* ------------------------------------- */
	if ( Mode & FILE_VMS_VERSION ) 
		{
		while ( i < CharCount ) 
			{
	 		Buffer[ResultIndex++] = Source[i++];
			}
		}
	return ResultIndex;
	}

int fn_parse_msdos(char *Source, char *Buffer , int	Mode, int CharCount);
int fn_parse_msdos (char *Source, char *Buffer , int	Mode, int CharCount)
	{
#ifdef	msdos
#endif /* msdos */ // Placer a la fin
	int	i = 0;
	int 	j = 0;
	int	ResultIndex = 0;
	int 	LastDotIndex = 0;			/* index of last dot (begin of extension) */
	
	/*
	
		Beware : adapted to support 32bits file names:
		
			Network device name:  
				\\Name
			
			Dots in filenames:
				toto.titi.ext
			keeps only last dotted word as extension
	
	
		c:\Toto\tutu\titi.sss.ext
		\\tata\Toto\tutu\titi.sss.ext
		
		is split in following atoms...
		
		c:			\Toto\tutu\		titi.sss		.ext
		\\tata	\Toto\tutu\		titi.sss		.ext
	
	*/
	
	

	#define DOS_SEPARATOR	'\\'	/* 0x005C */

	/* -------------------------------------------- */
	/* Ms/Dos :    C:\*\*\filename.ext		*/
	/* -------------------------------------------- */

	/* Check for and transfer NetWork Node Name */
	/* ---------------------------------------- */
	if ( Mode & FILE_NETWORK_NODE ) 
		{
		}

	/* Check for and Transfer Device Mnemonic */
	/* -------------------------------------- */
	/*
		?:
		where ? == A..Z
	
	*/
	if ( CharCount >= 2 ) 
		{
		if ( Source[1] == ':' ) 
			{ 
			if ( Mode & FILE_DEVICE ) 
				{
				Xmemcpy((char *) &Buffer[ResultIndex],(char *) Source , 2 );
				ResultIndex += 2;
				}
			Source += 2; 
			CharCount-= 2; 
			}
		else if ((Source[0] == DOS_SEPARATOR) && (Source[1] == DOS_SEPARATOR))
			{
			/*
				\\NetworkName
				
			*/
			Buffer [ResultIndex++] = DOS_SEPARATOR;
			Buffer [ResultIndex++] = DOS_SEPARATOR;

			// Copy Network Name	up to (not including) next '\'
			j = 2;
			while ((j<CharCount) && (Source[j] != DOS_SEPARATOR))
				{
				Buffer [ResultIndex++] = Source[j++];
				}
			Source += j; 
			CharCount -= j; 
			}
		}

	i = CharCount;
	LastDotIndex = -1;
	/* Scan BackWards to End of Path : Start of FileName */
	/* ------------------------------------------------- */
	while ((i > 0 ) && ( Source[i] != DOS_SEPARATOR )) 
		{
		if ((Source[i] == '.') && (LastDotIndex < 0))
			{
			LastDotIndex = i;
			}
		i--; 
		}

	/* Check for Path Portion Found and if So Increment */
	/* ------------------------------------------------ */
	if ( Source[i] == DOS_SEPARATOR ) 
		{
		i++;
		}

	/* Check for and perform PathName transfer */
	/* --------------------------------------- */
	if ( Mode & FILE_PATH ) 
		{
		for ( j = 0; j < i; j++ ) 
			{
			Buffer [ResultIndex++] = Source[j];
			}
		}

	/* Check for and Transfer filename */
	/* ------------------------------- */
	while ( i < CharCount ) 
		{
		if (i == LastDotIndex)
			{ 
			break;
			}
		else	
			{
			if ( Mode & FILE_NAME ) 
				{
				// Copy filename
		 		Buffer [ResultIndex++] = Source[i];
				}
			i++;
			}
		}

	/* Check for and Transfer Extension */
	/* -------------------------------- */
	if ( Mode & FILE_EXTENSION ) 
		{
		while ( i < CharCount ) 
			{
	 		Buffer[ResultIndex++] = Source[i++]; 
			}
		}
	return ResultIndex;
	}



int	fn_parser(Source , Buffer , Mode )
char *Source;	
char *Buffer;	
int	Mode;
	{
	/*
		Note: 
			returns 	Length of result
			
		Code restructured by jph
		
		
		ai == source length		
		
	
		MODE : Extraction type Bit definitions
			   1			NetWork Node Name	
			   2			Device Mnemonic			
			   4			Path name only			
			   8 			FileName portion		
			   16			Extension and separator		
			   32			Amenesik / Sologic Password		
			   64			vms Version Number 		
	*/

	/*
		Note:  accepts two kind of terminators : \0 and \r
	*/
	
	int	CharCount = 0;
	int	ResultIndex = 0;
	int	TerminatorChar = 0;
	char* TerminatorPtr = 0;
	int	i = 0;
	
	Buffer[0]='\0';
	
	#define END_OF_LINE		0x000D
	
	/* If No Current Object */
	/* -------------------- */
	if (Source == (char *) 0 ) 
		{  return(0);  }

	/* Calculate and Test String Length */
	/* -------------------------------- */
	CharCount = 0;
	while ((Source[CharCount] != 0) && (Source[CharCount] != END_OF_LINE)) 
		CharCount++;

	if ( CharCount == 0 )
		{ return(0); }

	/* Keep terminator and ensure ZERO termination */
	/* ------------------------------------------- */
	TerminatorPtr = &Source[CharCount]; 
	TerminatorChar = *TerminatorPtr; 
	if (TerminatorChar)
		{
		// Force '\0' terminator
		*TerminatorPtr = '\0';
		}

	/* Zero out the result index */
	/* ------------------------- */


#ifdef	prologue
	ResultIndex = fn_parse_prologue (Source, Buffer, Mode, CharCount);
#endif /* prologue */

#ifdef	unix
#ifndef	vms
	ResultIndex = fn_parse_UnixNotVms (Source, Buffer, Mode, CharCount);
#endif /* ! vms */
#endif /* unix */

#ifdef	vms
	ResultIndex = fn_parse_vms (Source, Buffer, Mode, CharCount);
#endif /* vms */

#ifdef	msdos
	ResultIndex = fn_parse_msdos (Source, Buffer, Mode, CharCount);
#endif /* msdos */

	if (TerminatorChar)
		{
		// Restore original terminator
		*TerminatorPtr = TerminatorChar;
		}

	/* Return the Byte Count Transfered */
	/* -------------------------------- */
	Buffer[ResultIndex] = '\0';


	if (Mode & FILE_LOWER_CASE_RESULT)
		{
		for (i=0; i <ResultIndex ; i++)
			{
			Buffer[i] = tolower(Buffer[i]);
			}
		}
	
	return( ResultIndex );
	}

