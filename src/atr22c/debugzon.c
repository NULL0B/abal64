/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *	Module  : ATR
 *	Fichier : DEBUGZON.C
 *	Version : 2.1f
 *	Date    : 13/10/97
 *	Systeme : DOS / PRL / UNIX / VMS
 *
 *	Traducteur ABAL
 *
 *	[Traitement des zones de debug utiles pour june]
 *
 */

 /*
 * Mises a jour :
 * ------------
 */

/* Fichier de definition */
/* --------------------- */


#include "debugzon.h"

#define First_Byte_Only 0xFF 
#define Three_First_Byte_Only 0xFFFFFF 


#define ERROR_POP_STACK 0
#define DEFAULT_ZONE_CODE 0


long ZoneInitStack()
{
	int i;
	stackItemCount = 0;
	
	for (i=0; i<MAX_STACK_ITEM_COUNT; i++) ZoneStack[i]=0;
	return 1;
}

/*********************************************/

long ZonePushStack(actualZoneCode)
long actualZoneCode;
{
	long result;

	stackItemCount++;
	if (stackItemCount > MAX_STACK_ITEM_COUNT)
		result = 0;
	else {
		ZoneStack[stackItemCount-1]=actualZoneCode;
		result = 1;
	}
	return result;
}

/*********************************************/

long ZonePopStack ()

{
	long result;
	
	if (stackItemCount > 0) {
		result = ZoneStack[stackItemCount];
		stackItemCount--;		
	}
	else {
		result = DEFAULT_ZONE_CODE;
	}
	return result;

}

/*********************************************/

long ZoneCodeLineNumber (lineNumber, zoneCode)
long lineNumber, zoneCode;
{	
	return (lineNumber & Three_First_Byte_Only)|(zoneCode << 24);
}

/*********************************************/

long ZoneDecodeLineNumber (CodedLineNumber, ZoneCode)
long CodedLineNumber;
long *ZoneCode;
{
	long Line;

	*ZoneCode = (CodedLineNumber >> 24) & First_Byte_Only;
	Line = (CodedLineNumber & Three_First_Byte_Only);
	return Line;
}

/*********************************************/

long ZoneStackIsEmpty()
{
	return (stackItemCount == 0);
}

