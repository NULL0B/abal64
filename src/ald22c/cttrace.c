/*
	Desc : ctTrace.c  		Implement Trace for windows
	Proj : Common Tool
	Copyright (c) 1996-98 Amenesik / Sologic  

	Implement 'ctOutputDebugString' under window
		- redirect output to "Trace" application

	This uses code from "ex-Altim" developement teams.
	Let them be thanked for they work.


	Available switch:
	__CT_TRACE_CONTROL__			ifdef, trace is output only if 'ctTraceIsOn'
										global int variable is <>0.

	Modifications list :
	24/OCtober/1996	JPH File creation, from 'ctrace.cpp' (Altim team).
	7/November/96		JPH Implement connected mode.
	15/April/98			JPH	Add IF_TRACE & IF_TRACE_ON
*/

#define CT_TRACE_EXTERN(DCL,INIT)	DCL = INIT;

// also include "ctDebug.h"
#include "cttype.h"
#include <string.h>	// pour strlen

// Just to remember that windows is required !
#ifndef __WINDOWS_H
#include <Windows.h>
#endif

#include <stdlib.h>	// itoa
#include "cttrace.h"

int ctTraceIsOn = 1;


// -------------------------------------------------- Output control

const char	TraceWindowName[] = TRACE_WINDOW_CLASS;
const char	OpenMessageName[] = TRACE_MESSAGE_OUVRE_CON;
const char	TraceMessageName[] = TRACE_MESSAGE_ATOM_CON;

static HWND TraceWindow = 0;
static UINT OpenMessage = 0;
static UINT TraceMessage = 0;
static WORD TraceConnectionHandle = 0;

static void pInit (void)
	{
	if (!ctTraceIsOn)
		return;

	OpenMessage = RegisterWindowMessage (OpenMessageName);
	TraceMessage = RegisterWindowMessage (TraceMessageName);

	TraceWindow = FindWindow (TraceWindowName, NULL);

	if (TraceWindow)
		{
		ATOM Atom = GlobalAddAtom(CT_APPLICATION_NAME);

		if (Atom)
			{
			TraceConnectionHandle = (WORD) SendMessage
				(
				TraceWindow,
				OpenMessage,
				(WPARAM) TRACE_OPTION_EXPLICIT_NEW_LINE,
				(LPARAM) Atom
				);

			GlobalDeleteAtom(Atom);
			}
		}
	}


void ctOutputDebugString (ctConstStr  MessageStr)
	{
	// Be sure to have the string in a safe place !
	// Check it's not an infinite string!

	if (ctTraceIsOn)
		{
		if (TraceMessage == 0)
			pInit();

		if (TraceWindow)
			{
			ATOM	Atom = GlobalAddAtom (MessageStr);

			TraceConnectionHandle = (WORD) SendMessage
					(
					TraceWindow,
					TraceMessage,
					(WPARAM) TraceConnectionHandle,
					(LPARAM) Atom
					);
			GlobalDeleteAtom (Atom);
			}
		}
	}



/* -------------------------------------------------- External trace */


#ifdef CT_INI_FILE

ctBoolean pEntryExist(ctConstStr EntryName);
ctBoolean pEntryExist(ctConstStr EntryName)
	{
	#define IMPOSSIBLE_VALUE "ImPossybLeValuué 143&"

	ctBoolean Result = FALSE;
	char Buffer [20];

	WIN GetPrivateProfileString
			(
			(LPCSTR) "Trace",
			(LPCSTR) EntryName,
			IMPOSSIBLE_VALUE,
			Buffer, sizeof(Buffer),
			(LPCSTR) CT_INI_FILE
			);

	if (strcmp(Buffer,IMPOSSIBLE_VALUE)!=0)
		{	// Item exist
		Result = TRUE;
		}
	else
		{ // Item does not exist
		Result = FALSE;
		}

	return Result;
	}

UINT pReadInt (ctConstStr EntryName, UINT DefaultValue);
UINT pReadInt (ctConstStr EntryName, UINT DefaultValue)
	{
	UINT Result = DefaultValue;

	if (pEntryExist(EntryName))
		{
		Result = WIN GetPrivateProfileInt
				(
				(LPCSTR) "Trace",
				(LPCSTR) EntryName,
				DefaultValue,
				(LPCSTR) CT_INI_FILE
				);
		}
	else
		{
		char Buffer[30];
		itoa(DefaultValue,Buffer,10);

		WIN WritePrivateProfileString
			(
			(LPCSTR) "Trace",
			(LPCSTR) EntryName,
			(LPCSTR) Buffer,
			(LPCSTR) CT_INI_FILE
			);
		}

	return Result;
	}

void ctInitTraceSwitch (void)
	{
	/*
		Note : all flags are defined as extern
		value in begin of "ctContext.cpp"

		gGlobalTraceXXXX

		Read
	*/

	if (gGlobalTrace = pReadInt("GeneralTraceSwitch",0))
		{
		//ctTraceLexA
		gGlobalTraceCLex = pReadInt("Lex analyser (C part)",0);
		}
	}

#endif
