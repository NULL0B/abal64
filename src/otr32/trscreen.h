/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRSCREEN.H				*/
/*		Version :	2.1d					*/
/*		Date	:	26/01/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRSCREEN_H
#define	_TRSCREEN_H

#define	_SCREEN_KEYWORD_MAX	 31

#define	SCREENPTR	struct cobol_screen XPTR
#define	SCREENITEM	struct cobol_screen_item XPTR

struct	cobol_screen_item	{
	WORD		special;
	WORD		tabv;
	WORD		cno;
	WORD		lno;
	WORD		atb;
	WORD		fore;
	WORD		back;
	WORD		mask;
	BPTR		value;
	BPTR		picture;
	VCTRLPTR	variable;
	SCREENITEM	next;
	};

struct	cobol_screen	{
	BPTR		name;
	SCREENITEM	contents;
	SCREENPTR	next;
	};

#ifdef	_TRSCREEN_C

SCREENPTR	ScreenHeap=(SCREENPTR) 0;

static BPTR screen_keywords [_SCREEN_KEYWORD_MAX ] = {
	(BPTR)	"LINE",
	(BPTR)	"COLUMN",
	(BPTR)	"VALUE",
	(BPTR)	"REVERSE-VIDEO",
	(BPTR)	"BLANK",
	(BPTR)	"SCREEN",
	(BPTR)  "PIC",
	(BPTR)  "PICTURE",
	(BPTR)  "USING",
	(BPTR)  "FOREGROUND-COLOR",
	(BPTR)	"BACKGROUND-COLOR",
	(BPTR)  "FOREGROUND-COLOUR",
	(BPTR)	"BACKGROUND-COLOUR",
	(BPTR)	"BELL",
	(BPTR)	"BEEP",
	(BPTR) 	"BLINK",
	(BPTR)	"ERASE",
	(BPTR)	"HIGHLIGHT",
	(BPTR)	"LOWLIGHT",
	(BPTR)	"GRID",
	(BPTR)	"LEFTLINE",
	(BPTR)	"OVERLINE",
	(BPTR)	"UNDERLINE",
	(BPTR)	"SIZE",
	(BPTR)	"AUTO",
	(BPTR)	"SECURE",
	(BPTR)	"REQUIRED",
	(BPTR)	"FULL",
	(BPTR)	"CONTROL",
	(BPTR)	"AUTOSKIP",
	(BPTR)	"COL"
	};

#endif	/* _TRSCREEN_C */

#define	_SCREEN_LINE		0
#define	_SCREEN_COLUMN		1
#define	_SCREEN_VALUE		2
#define	_SCREEN_REVERSE_VIDEO	3
#define	_SCREEN_BLANK		4
#define	_SCREEN_SCREEN		5
#define	_SCREEN_PIC   		6
#define	_SCREEN_PICTURE		7
#define	_SCREEN_USING  		8
#define	_SCREEN_FORECOLOR 	9
#define	_SCREEN_BACKCOLOR 	10
#define	_SCREEN_FORECOLOUR	11
#define	_SCREEN_BACKCOLOUR	12
#define _SCREEN_BELL		13
#define _SCREEN_BEEP		14
#define	_SCREEN_BLINK		15
#define _SCREEN_ERASE		16
#define _SCREEN_HIGHLIGHT	17
#define _SCREEN_LOWLIGHT	18
#define _SCREEN_GRID		19
#define _SCREEN_LEFTLINE	20
#define _SCREEN_OVERLINE	21
#define _SCREEN_UNDERLINE	22
#define _SCREEN_SIZE		23
#define _SCREEN_AUTO		24
#define _SCREEN_SECURE		25
#define _SCREEN_REQUIRED	26
#define _SCREEN_FULL		27
#define _SCREEN_CONTROL		28
#define _SCREEN_AUTOSKIP	29
#define _SCREEN_COL		30

#ifndef	UNIX
SCREENPTR	allocate_for_screen( BPTR );
SCREENITEM	allocate_screen_item( VOID );
VOID		liberate_screens( VOID );
#else
SCREENPTR	allocate_for_screen();
SCREENITEM	allocate_screen_item();
VOID		liberate_screens();
#endif

#endif	/* _TRSCREEN_H */
	/* ----------- */
