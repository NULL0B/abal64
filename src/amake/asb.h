#ifndef	_asb_h
#define	_asb_h

static	char *	keywords[] = {
	(char*)	"PROGRAM",
	(char*)	"MODULE",
	(char*)	"LIBRARY",
	(char*)	"SEGMENT",
	(char*)	"ESEG",
	(char*)	"PROC",
	(char*)	"ENDPROC",
	(char*)	"CONST",
	(char*)	"FORWARD",
	(char*)	"EXTERN",
	(char*)	"FIELD",
	(char*)	"IF",
	(char*)	"ELSE",
	(char*)	"ENDIF",
	(char*)	"FOR",
	(char*)	"NEXT",
	(char*)	"WHILE",
	(char*)	"WEND",
	(char*)	"REPEAT",
	(char*)	"UNTIL",
	(char*)	"SELECT",
	(char*)	"CASE",
	(char*)	"ENDSEL",
	(char*)	"DO",
	(char*)	"LOOP",
	(char*)	"DCL",
	(char*)	"PTR",
	(char*)	"DEFAULT"
	};

#define	_KEYWORD_PROGRAM	0x0000
#define	_KEYWORD_MODULE		0x0001
#define	_KEYWORD_LIBRARY	0x0002
#define	_KEYWORD_SEGMENT	0x0003
#define	_KEYWORD_ESEG		0x0004
#define	_KEYWORD_PROC		0x0005
#define	_KEYWORD_ENDPROC	0x0006
#define	_KEYWORD_CONST		0x0007
#define	_KEYWORD_FORWARD	0x0008
#define	_KEYWORD_EXTERN		0x0009

#define	_KEYWORD_FIELD		0x000A
#define	_KEYWORD_IF		0x000B
#define	_KEYWORD_ELSE		0x000C
#define	_KEYWORD_ENDIF		0x000D
#define	_KEYWORD_FOR		0x000E
#define	_KEYWORD_NEXT		0x000F
#define	_KEYWORD_WHILE		0x0010
#define	_KEYWORD_WEND		0x0011
#define	_KEYWORD_REPEAT		0x0012
#define	_KEYWORD_UNTIL		0x0013
#define	_KEYWORD_SELECT		0x0014
#define	_KEYWORD_CASE		0x0015
#define	_KEYWORD_ENDSEL		0x0016
#define	_KEYWORD_DO		0x0017
#define	_KEYWORD_LOOP		0x0018
#define	_KEYWORD_DCL		0x0019
#define	_KEYWORD_PTR		0x001A
#define	_KEYWORD_DEFAULT	0x001B
#define	_MAX_KEYWORDS		0x001C



#endif	/* _asb_h */
	/* ------ */


