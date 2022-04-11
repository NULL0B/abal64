
#ifndef __CTWINCON_H__
#define __CTWINCON_H__

/*
	Desc : ctWinCon.h  		Window's Console
	Proj : Common tools
	Copyright (c) 1997 Amenesik / Sologic  

	16/32 Windows library to get "console" behavior.
	Using "ctPrint" and "ctScan".

	Modifications list :
	9/December/1997	JPH File creation, from freeware source.
*/

#include "ctType.h"
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif



typedef struct ctConsoleStruct
	{
	/* Before: BeforeCreate */
	HINSTANCE	Instance; 
	HINSTANCE	PreviousInstance;
	LPSTR			CommandLine;	/* c:\atr ... */
	int			CommandShow;	/* SW_SHOW, SW_HIDE , ...*/

	WNDCLASS		WindowClass;

	/* After: BeforeCreate */
	HWND			WindowHandle;
	ctConstStr	WindowName;
	DWORD			WindowStyle;

	HWND			EditHandle;
	DWORD			EditStyle;
	
	long			PrintCount;
	} ctConsoleInfo;

typedef ctConsoleInfo CT_FAR * ctConsolePtr;



typedef struct ctConsoleExtraStruct
	{
	HWND			EditHandle;

	} ctConsoleExtra;
typedef ctConsoleExtra CT_FAR * ctConsoleExtraPtr;



void ctGetConsoleExtra
	(
	HWND					WindowHandle,
	ctConsoleExtraPtr	Extra
	);

void ctSetConsoleExtra
	(
	HWND					WindowHandle,
	ctConsoleExtraPtr	Extra
	);

void ctPrintConsole (ctConsolePtr Console, ctConstStr Format, ...);
void ctPrintDefaultConsole (ctConstStr Format, ...);

void ctShowConsole (ctConsolePtr Console, ctBoolean MustShow);
ctBoolean ctIsConsoleShown (ctConsolePtr Console);

extern ctConstStr GlobalConsoleClassName;
extern ctConsolePtr GlobalConsole;

/* -------------------- Function provided by client -------------------- */

/*
	Usage:
		You must provide following two functions.
		The first one is called BEFORE console window is opened
		ctConsoleMain must return one of following value:
		CT_CLOSE_CONSOLE, CT_CLOSE_CONSOLE_IF_EMPTY, CT_KEEP_CONSOLE_OPENED
*/

#define			CT_CLOSE_CONSOLE				0
#define			CT_CLOSE_CONSOLE_IF_EMPTY	1
#define			CT_KEEP_CONSOLE_OPENED		2

extern void		ctBeforeConsoleMain	(ctConsolePtr Console);
extern int		ctConsoleMain (ctConsolePtr Console);


#define CT_STORE_QUOTE_IN_ARGUMENT 			(1<<0)
#define CT_SKIP_QUOTE_IN_ARGUMENT 			(0<<0)
#define CT_STORE_QUOTE_IN_ARGUMENT_MASK 	(1<<0)

int ctParseArgument 
			(
			IN		ctConstStr	CommandLine, 
			OUT	ctStr			ArgBuffer,
			INOUT	int			ArgBufferLength,
			OUT	ctStr			ArgV[], 
			IN		int			MaxArgV,
			IN		int *			ArgC,
			IN		ctConstStr	ArgZero,
			IN		int			ParseOption
			);

/* ------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif



#endif /* __CTWINCON_H__ */
