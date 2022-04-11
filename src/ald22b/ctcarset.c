
/*
	Desc : ctCarSet.cpp			Character Set
	Proj : Common Tool
	Copyright (c) 1994-98 Amenesik / Sologic  

	Conversion between Ascii character set.

	Modifications list :
	23/July/98           JPH	File creation

*/

#include "ctcarset.h"
#include <stdio.h>

#include "ctcarst1.hg"
#include "ctcarst2.hg"

#define gDefaultCharSet			gWindowsCharSet
#define gDefaultRepCharSet		gWindowsRepCharSet


// --------------------------------------------------

int pConvertChar
			(
			int				SearchedChar,
			ctRefCharPtr	FromCharSet,
			ctRefCharPtr	FromRepCharSet,
			ctRefCharPtr	ToCharSet,
			ctByte			DefaultCharacter
			);
ctRefCharPtr pGetCharSet (int CharSetId);


// --------------------------------------------------

ctBoolean ctPrepareConversion 
			(
			INOUT	ctCharSetConversionPtr	Table,
			IN		int							FromCharSetId, 
			IN		int							ToCharSetId,
			IN		int							DefaultCharacter
			)
	{
	ctBoolean 		Result = FALSE;
	ctRefCharPtr	FromCharSet = 0;
	ctRefCharPtr	FromRepCharSet = 0;
	ctRefCharPtr	ToCharSet = 0;
	int				i;
	
	if (Table)
		{
		Result = TRUE;

		FromCharSet = pGetCharSet(FromCharSetId);
		FromRepCharSet = pGetCharSet(FromCharSetId+1);
		ToCharSet = pGetCharSet(ToCharSetId);
		
		if (!FromCharSet)
			{
			Result = FALSE;
			FromCharSet = gDefaultCharSet;
			}
		
		if (!FromRepCharSet)
			{
			Result = FALSE;
			FromRepCharSet = 0;
			}

		if (!ToCharSet)
			{
			Result = FALSE;
			ToCharSet = gDefaultCharSet;
			}
			
		Table->aFromCharSet = FromCharSet;
		Table->aFromRepCharSet = FromRepCharSet;
		Table->aToCharSet = ToCharSet;
		Table->aDefaultCharacter = (ctByte) DefaultCharacter;

		/* code 0 is always set to zero */
		Table->aConvert[0]=0;
		for (i=1;i<CT_CHAR_SET_SIZE;i++)
			{
			if (FromCharSet[i]==ToCharSet[i])
				{
				/* Simple case, same character */
				Table->aConvert[i]=i;
				}
			else
				{
				/* Must search a litlle bit more */
				Table->aConvert[i]= (ctChar) pConvertChar
					(
					i, 
					FromCharSet, 
					FromRepCharSet, 
					ToCharSet, 
					(ctByte) DefaultCharacter
					);
				}
			}
		}
		
	return Result;
	}


ctByte ctConvertCharacter 
			(
			IN		ctCharSetConversionPtr	Table,
			IN		int							FromChar
			)
	{
	/*
		Note:
			FromChar==0		==>	Result==0
			FromChar!=0		==>	Result!=0
	
		Note: int is easy because it does not require any conversion!
	*/
	ctByte Result = Table->aConvert[(ctByte) FromChar];
		
	return Result;
	}


int pConvertChar
			(
			int				SearchedChar,
			ctRefCharPtr	FromCharSet,
			ctRefCharPtr	FromRepCharSet,
			ctRefCharPtr	ToCharSet,
			ctByte			DefaultCharacter
			)
	{
	/*
		if (SearchedChar >0)
		
		Result >0
		
	*/
	int				Result = 0;
	ctRefChar 		SearchedCharRef = FromCharSet[SearchedChar];
	int				i = 1;
	ctRefCharPtr	ToChar =ToCharSet;
	
	if (SearchedCharRef)
		{	
		ToChar++;
		
		while (i < CT_CHAR_SET_SIZE)
			{
			if (*ToChar++ == SearchedCharRef)
				{
				Result = i;
				break;
				}
			else
				i++;
			}
			
		if (!Result)
			{
			/* Try replacement char set */
			SearchedCharRef = FromRepCharSet[SearchedChar];	
			
			if (SearchedCharRef)
				{			
				ToChar = &FromRepCharSet[1];
				i = 1;
				
				while (i < CT_CHAR_SET_SIZE)
					{
					if (*ToChar++ == SearchedCharRef)
						{
						Result = i;
						break;
						}
					else
						i++;
					}
				}
			}
		}

	if (!Result)
		{
		if (DefaultCharacter)
			Result = DefaultCharacter;
		else
			Result = SearchedChar;
		}

	return Result;
	}


ctStr ctConvertString
			(
			IN		ctCharSetConversionPtr	Table,
			INOUT	ctStr							Str
			)
	{
	ctStr Result = Str;
	
	while (*Str)
		{
		*Str=Table->aConvert[(ctByte) *Str];
		Str++;
		}
	
	return Result;
	}



ctRefCharPtr pGetCharSet (int CharSetId)
	{
	ctRefCharPtr Result = 0;
	
	/*
		Every charset has an associated "rep"lacement charset
		with same ID+1!
	*/
	
	switch (CharSetId)
		{
		case CT_WINDOWS_CHARSET:
			Result = gWindowsCharSet;
			break;

		case CT_WINDOWS_REP_CHARSET:
			Result = gWindowsRepCharSet;
			break;
			
		case CT_PROLOGUE_CHARSET:
			Result = gPrologueCharSet;
			break;

		case CT_PROLOGUE_REP_CHARSET:
			Result = gPrologueRepCharSet;
			break;

		case CT_DOS_CHARSET:
			Result = gDosCharSet;
			break;
			
		case CT_DOS_REP_CHARSET:
			Result = gDosRepCharSet;
			break;
			
		case CT_VMS_CHARSET:
			Result = gVMSCharSet;
			break;
			
		case CT_VMS_REP_CHARSET:
			Result = gVMSRepCharSet;
			break;
			
		case CT_UNIX_CHARSET:
			Result = gUnixCharSet;
			break;
			
		case CT_UNIX_REP_CHARSET:
			Result = gUnixRepCharSet;
			break;
			
		case CT_MACINTOSH_CHARSET:
			Result = gMacintoshCharSet;
			break;
			
		case CT_MACINTOSH_REP_CHARSET:
			Result = gMacintoshRepCharSet;
			break;
			
		case CT_ASCII7_CHARSET:
			Result = gAscii7CharSet;
			break;
			
		case CT_ASCII7_REP_CHARSET:
			Result = gAscii7RepCharSet;
			break;
			
		case CT_DEFAULT_CHARSET:
			Result = gDefaultCharSet;
			break;
	
		case CT_DEFAULT_REP_CHARSET:
			Result = gDefaultRepCharSet;
			break;
	
		default:
			ODSu("Undefined character set id:%d",CharSetId);
			Result = gDefaultCharSet;
		}
	return Result;
	}


ctStr ctConvertStringToBuffer
			(
			IN		ctCharSetConversionPtr	Table,
			IN		ctConstStr					FromString,
			OUT	ctStr							ToBuffer,
			IN		int							ToBufferLength
			)
	{
	ctStr Result = 0;
	
	if (ToBuffer && ToBufferLength)
		{
		Result = ToBuffer;
		
		if (!FromString)
			FromString = "";
			
		ToBufferLength--;	
		while (ToBufferLength-- && *FromString)
			{
			*ToBuffer++=(Table->aConvert[(ctByte)*FromString]);
			}
		*ToBuffer='\0';
		}
	
	return Result;
	}

void ctDumpConversion (ctCharSetConversionPtr	Table)
	{
	int 		i;
	ctByte	Car =0;
	ctByte	Line[40];
	
	#define PRINTABLE(C) ((C<32) ? '.' : C)
	
	ODSu("Default character :%c",Table->aDefaultCharacter);
	ODS("   {");
	for (i=0;i<256;i++)
		{
		Car = Table->aConvert[i];
		sprintf
			(
			Line,
			"   %d %x '%c' ==> %d %x '%c'",
			i,i,PRINTABLE(i),Car,Car,PRINTABLE(Car)
			);
		ODS(Line);
		}
	ODS("   }");
	}


