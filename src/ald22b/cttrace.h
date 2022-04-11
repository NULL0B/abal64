#ifndef	__CTTRACE_H__
#define	__CTTRACE_H__

/*
	Desc : ctTrace.c  		Implement Trace for windows
	Proj : Common Tool
	Copyright (c) 1996-98 Amenesik / Sologic  

	Implement 'ctOutputDebugString' under window
		- redirect output to "Trace" application

	This uses code from "ex-Altim" developement teams.
	Let them be thanked for they work.

	Note: This file is same as "TracePub.h".

	Available switch:
	__CT_TRACE_CONTROL__			ifdef, trace is output only if 'ctTraceIsOn'
										global int variable is <>0.

	Modifications list :
	24/OCtober/1996	JPH File creation, from 'ctrace.cpp' (Altim team).
*/

//-------------------------------------------------- Maximum

#define 	TRACE_MAX_LINE				256
#define	TRACE_MAX_MODULE_NAME	100
#define  TRACE_MAX_PATH				256

//-------------------------------------------------- Preference

#define TRACE_PREFERENCE_FILENAME				"RMML.INI"

#define TRACE_PREF_SECTION_PRINT		"TraceMenuPrintf"
#define TRACE_PREF_ENTRY_ITEMCOUNT			"NbrItem"
#define TRACE_PREF_ENTRY_TEXTCOLOR		"ColorTexte"
#define TRACE_PREF_ENTRY_MENUGRAYED		"MenuGrayed"
#define TRACE_PREF_ENTRY_MOTHER				"Mere"
#define TRACE_PREF_ENTRY_MOTHERICON		"MereIcone"
#define TRACE_PREF_ENTRY_BACKCOLOR		"ColorFond"
#define TRACE_PREF_ENTRY_TEXTCOLOR		"ColorTexte"
#define TRACE_PREF_ENTRY_MAINICON_NORMAL		"IconeNormal"
#define TRACE_PREF_ENTRY_MAINICON_ASLEEP		"IconeDort"
#define TRACE_PREF_ENTRY_MAINICON_MESSAGE		"IconeMessage"

#define TRACE_PREF_SECTION_SIZE		"TracesSizes"



//-------------------------------------------------- Messages

/*

	Trace existe en deux version 16 et 32 bits.

*/

#ifdef WIN32
#define TRACE_WINDOW_CLASS		"TraceAtom32"
#else
#define TRACE_WINDOW_CLASS		"Trace"
#endif

/*
	Mode "Connection" 16/32 bits:
	
		OuvreCon (WParam= UINT Option , LParam= ATOM ModuleName) 
				: LResult= UINT HandleConnection
			Called once to open a connection.

		TraceAtomeCon (WParam= UINT HandleConnection, LParam= ATOM Message) 
				: LResult= UINT HandleConnection
			Called to print a trace message.

	where:
		ModuleName/Message = Global atom that contains actual string (module name/message).
		HandleConnection = Handle allocated by TRACE.EXE

*/
#define TRACE_MESSAGE_OUVRE_CON			"TraceOuvreCon"		// Ouvre une connection
#define TRACE_MESSAGE_ATOM_CON	"TraceAtomeCon"		// Print un atome sur connection
//#define TRACE_MESSAGE_4CAR_CON	"Trace4CarCon"			// Print 4 Car sur connection

/*
	Mode "Window" 16/32 bits:
	
		DeclareWin (WParam= HANDLE Window, LParam= ATOM ModuleName) 
				: LResult= UINT HandleConnection
			Called once to open a connection.

		TraceAtomeWin (WParam= HANDLE Window, LParam= ATOM Message) 
				: LResult= UINT HandleConnection
			Called to print a trace message.

	where:
		ModuleName/Message = Global atom that contains actual string (module name/message).
		HandleConnection = Handle allocated by TRACE.EXE
		Window = Windows's handle (handle of an window or of an application).

*/
// Mode "Window" 16/32 bits
#define TRACE_MESSAGE_DECLARE_WIN		"TraceDeclareWin"		// Declare un HD (par atome)
#define TRACE_MESSAGE_ATOME_WIN	"TraceAtomeWin"		// Print un atome sur HD

/*
	Mode "Window" 16 bits ONLY:
	
		Declare16Win (WParam= HANDLE Window, LParam= LPTSTR ModuleName) 
				: LResult= UINT HandleConnection
			Called once to open a connection.

		TraceAtome16Win (WParam= HANDLE Window, LParam= LPTSTR Message) 
				: LResult= UINT HandleConnection
			Called to print a trace message.

	where:
		HandleConnection = Handle allocated by TRACE.EXE
		Window = Windows's handle (handle of an window or of an application).

*/
// Mode "Window" compatible 16 uniquement
#define TRACE_MESSAGE16_PRINT_WIN		"Trace"
#define TRACE_MESSAGE16_DECLARE_WIN		"Declare"

#define TRACE_MESSAGE16_ESPION_WIN		"Espion"
#define TRACE_MESSAGE32_ESPION_WIN		"Espion32"

//-------------------------------------------------- Connection option

/*
	Use following constant for parameter "Options" in
	'OuvreCon' messages.

*/

#define TRACE_OPTION_AUTO_NEW_LINE		(0<<0)		// All messages are followed by new line (default)
#define TRACE_OPTION_EXPLICIT_NEW_LINE	(1<<0)		// New line are explicit


#endif

// end __CTTRACE_H__

