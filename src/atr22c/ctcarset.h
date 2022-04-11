#ifndef __CTCARSET_H__
#define __CTCARSET_H__

/*
	Desc : ctCarSet.h			Character Set
	Proj : Common Tool
	Copyright (c) 1994-98 Amenesik / Sologic  

	Conversion between Ascii character set.

	Modifications list :
	23/July/98           JPH	File creation

*/

#include "ctType.h"

/*
	Usage:
		ctCharSetConversion	DosToPrologue;
		
		Ok = ctPrepareConversion 
				(
				&DosToPrologue,
				CT_DOS_CHARSET, 
				CT_PROLOGUE_CHARSET
				);
		
		...
		DosCar = 'é';
		char Buffer[xxx];
		char DosString[xxx];
		char DosString[xxx];
		
		PrologueCar = ctConvertChar(&DosToPrologue,DosCar);
		ctConvertStringToBuffer(&DosToPrologue,"AÏe l'été",Buffer,sizeof(Buffer));
		ctConvertString(&DosToPrologue,DosString);
*/

/*
	ctRefChar	Reference of a char.
					== ID + flags
*/

#define CT_CHAR_SET_SIZE 256

typedef ct2Bytes 	ctRefChar;
typedef ctRefChar CT_FAR * ctRefCharPtr;
typedef ctRefChar ctCharSet[];
typedef ctChar		ctCharConversionArray[CT_CHAR_SET_SIZE];

/* -------------------------------------------------- ctCharSetConversion */

typedef struct ctCharSetConversionStruct ctCharSetConversion;
typedef ctCharSetConversion CT_FAR * ctCharSetConversionPtr;
struct ctCharSetConversionStruct 
	{
	ctRefCharPtr				aFromCharSet;
	ctRefCharPtr				aFromRepCharSet;
	ctRefCharPtr				aToCharSet;
	ctCharConversionArray	aConvert;
	ctChar						aDefaultCharacter;
	};

#define CT_DEFAULT_CHARSET				0
#define CT_WINDOWS_CHARSET				2
#define CT_PROLOGUE_CHARSET			4
#define CT_DOS_CHARSET					6
#define CT_VMS_CHARSET					8
#define CT_UNIX_CHARSET					10
#define CT_MACINTOSH_CHARSET			12
#define CT_ASCII7_CHARSET				14

/*Replacement charset DO NOT USE DIRECTLY */
#define CT_DEFAULT_REP_CHARSET 		1
#define CT_WINDOWS_REP_CHARSET		3
#define CT_PROLOGUE_REP_CHARSET		5
#define CT_DOS_REP_CHARSET				7
#define CT_VMS_REP_CHARSET				9
#define CT_UNIX_REP_CHARSET			11
#define CT_MACINTOSH_REP_CHARSET		13
#define CT_ASCII7_REP_CHARSET			15

#ifdef __cplusplus
extern "C"
	{
#endif

/* Must be called first! */
ctBoolean ctPrepareConversion 
			(
			INOUT	ctCharSetConversionPtr	Table,
			IN		int							FromCharSetId, 
			IN		int							ToCharSetId,
			IN		int							DefaultCharacter
			);
		
/* Convert one char */
ctByte ctConvertCharacter 
			(
			IN		ctCharSetConversionPtr	Table,
			IN		int							FromChar
			);
			
/* Copy converted string into buffer */
ctStr ctConvertStringToBuffer
			(
			IN		ctCharSetConversionPtr	Table,
			IN		ctConstStr					FromString,
			OUT	ctStr							ToBuffer,
			IN		int							ToBufferLenght
			);

/* Converted string "in place" */
ctStr ctConvertString
			(
			IN		ctCharSetConversionPtr	Table,
			INOUT	ctStr							Str
			);

/* Dump conversion table */
void ctDumpConversion (ctCharSetConversionPtr	Table);

#ifdef __cplusplus
	}
#endif

#endif
