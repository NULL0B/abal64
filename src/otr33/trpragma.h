/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990,1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRPRAGMA.H				*/
/*		Version :	2.2a					*/
/*		Date	:	09/04/1998				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRPRAGMA_H
#define	_TRPRAGMA_H

#define	OTR_PRAGMA_MAX	47

#ifdef	_TRDIRECT_C

static	BPTR	otr_pragmas[ OTR_PRAGMA_MAX ] = {
	(BPTR) "TOKENSIZE",
	(BPTR) "KEYWORD",
	(BPTR) "LOCAL_CONSTANT",
	(BPTR) "ECHO_ON",
	(BPTR) "ECHO_OFF",
	(BPTR) "ECHO",
	(BPTR) "DATE",
	(BPTR) "FILE",
	(BPTR) "VALIDPTR",
	(BPTR) "REMOVEALL",
	(BPTR) "NOINITFIELDE",
	(BPTR) "HEAP",
	(BPTR) "FILES",
	(BPTR) "STACK",
	(BPTR) "MEM",
	(BPTR) "PAGENUMBER",
	(BPTR) "PRINTER_TITLE",
	(BPTR) "PRINTER_NB_LINES",
	(BPTR) "PRINTER_NB_COLUMNS",
	(BPTR) "APLUS",
	(BPTR) "PRIVATE_VARIABLE",
	(BPTR) "ATR_LINE_BUFFER",
	(BPTR) "KEYBOARD_FLUSH",
	(BPTR) "ENHANCED",
	(BPTR) "OPTIMISE",
	(BPTR) "SEMAPHORES",
	(BPTR) "SWAP_BUFFERS",
	(BPTR) "TRACE",
	(BPTR) "ANNOUNCE",
	(BPTR) "IGNORE_CASE",
	(BPTR) "LIST",
	(BPTR) "PRIORITY",
	(BPTR) "WARNINGS",
	(BPTR) "EDITOR",
	(BPTR) "ERRORS",
	(BPTR) "THROW",
	(BPTR) "SWAPSIZE",
	(BPTR) "PAGESIZE",
	(BPTR) "DEFINE",
	(BPTR) "UNDEF",
	(BPTR) "OUTPUT",
	(BPTR) "LABELSIZE",
	(BPTR) "ENTER",
	(BPTR) "LEAVE",
	(BPTR) "STYLE",
	(BPTR) "INITLOCAL",
	(BPTR) "NOFLUSH"

	};

#endif

#define	_PRAGMA_TOKEN_SIZE		0
#define	_PRAGMA_KEYWORD   		1
#define	_PRAGMA_LOCAL_CONSTANT		2
#define _PRAGMA_ECHO_ON			3
#define _PRAGMA_ECHO_OFF		4
#define _PRAGMA_ECHO			5
#define _PRAGMA_DATE			6
#define _PRAGMA_FILE			7
#define _PRAGMA_VALIDPTR		8
#define _PRAGMA_REMOVEALL		9
#define _PRAGMA_NOINITFIELDE		10
#define _PRAGMA_HEAP			11
#define _PRAGMA_FILES			12
#define _PRAGMA_STACK			13
#define _PRAGMA_MEM			14
#define _PRAGMA_PAGENUMBER		15
#define _PRAGMA_PRINTER_TITLE		16
#define _PRAGMA_PRINTER_NB_LINES	17	
#define _PRAGMA_PRINTER_NB_COLUMNS	18	
#define _PRAGMA_APLUS			19
#define _PRAGMA_PRIVATE_VARIABLE	20	
#define _PRAGMA_ATR_LINE_BUFFER		21
#define _PRAGMA_KEYBOARD_FLUSH		22
#define _PRAGMA_ENHANCED      		23
#define _PRAGMA_OPTIMISE      		24
#define _PRAGMA_SEMAPHORES    		25
#define _PRAGMA_SWAP_BUFFERS   		26
#define _PRAGMA_TRACE   		27
#define _PRAGMA_ANNOUNCE		28
#define _PRAGMA_IGNORE_CASE		29
#define	_PRAGMA_LIST			30
#define	_PRAGMA_PRIORITY		31
#define	_PRAGMA_WARNINGS		32
#define	_PRAGMA_EDITOR			33
#define	_PRAGMA_ERRORS			34
#define	_PRAGMA_THROW 			35
#define	_PRAGMA_SWAPSIZE		36
#define	_PRAGMA_PAGESIZE		37
#define	_PRAGMA_DEFINE  		38
#define	_PRAGMA_UNDEF     		39
#define	_PRAGMA_OUTPUT    		40
#define	_PRAGMA_LABEL_SIZE		41
#define	_PRAGMA_ENTER			42
#define	_PRAGMA_LEAVE			43
#define	_PRAGMA_STYLE			44
#define	_PRAGMA_INITLOCAL		45
#define	_PRAGMA_NOFLUSH			46

#endif	/* _TRPRAGMA_H */
	/* ----------- */



