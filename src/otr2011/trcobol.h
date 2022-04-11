/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRCOBOL.H				*/
/*		Version :	2.1d					*/
/*		Date	:	26/01/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRCOBOL_H
#define	_TRCOBOL_H

#define	_DIVISION_KEYWORD_MAX	 6
#define	_IDENTIF_KEYWORD_MAX	 6
#define	_ENVIRON_KEYWORD_MAX	 3
#define	_DATADIV_KEYWORD_MAX	 5
#define	_PROCDIV_KEYWORD_MAX	 3
#define	_ENVCFG_KEYWORD_MAX	 3
#define	_ENVIO_KEYWORD_MAX	 2
#define	_FCTRL_KEYWORD_MAX	15
#define	_VCTRL_KEYWORD_MAX	34
#define	_IOCTRL_KEYWORD_MAX	 9
#define	_STATEMENT_MAX		51
#define	_DECLARATIVE_MAX	 2
#define	_NGF_STATEMENT_MAX	24

#define	COBOLPTR	struct cobol_context 	XPTR

#define	_COBOL_ANS74		0x0001
#define	_COBOL_ANS85		0x0002
#define	_COBOL_ANS91		0x0004
#define	_COBOL_ANS95		0x0008
#define	_COBOL_ANS85SS		0x0010
#define	_COBOL_ANS85RS		0x0020

struct	cobol_context	{
	BPTR		CurrentProgram;
	WORD		FillerCount;
	WORD		comma;
	WORD		version;
	WORD		options;
	WORD		CurrentDivision;
	WORD		ProcedureLabel;
	WORD		PerformInit;
	PCTRLPTR	PctrlHeap;
	PCTRLPTR	CurrentPctrl;
	FCTRLPTR	SelectHeap;
	FCTRLPTR	CurrentFctrl;
	VCTRLPTR	VctrlHeap;
	VCTRLPTR	VctrlLast;
	VCTRLPTR	CurrentVctrl;
	TCVARPTR	ErrorVariable;
	COBOLPTR	Next;
	};

#ifdef	_TRANSLAT_C

static BPTR declarative_keywords [_DECLARATIVE_MAX ] = {
	(BPTR)	"USE",
	(BPTR)	"END"
	};

static BPTR ngf_statement_keywords [_NGF_STATEMENT_MAX ] = {
	(BPTR)	"OPEN",
	(BPTR)	"CLOSE",
	(BPTR)	"READ",
	(BPTR)	"WRITE",
	(BPTR)	"REWRITE",
	(BPTR)	"START",
	(BPTR)	"DELETE",
	(BPTR)	"INPUT",
	(BPTR)	"OUTPUT",
	(BPTR)	"I-O",
	(BPTR)	"NEXT",
	(BPTR)	"RECORD",
	(BPTR)	"INTO",
	(BPTR)	"FROM",
	(BPTR)  "EXTEND",
	(BPTR)	"END-READ",
	(BPTR)	"END-WRITE",
	(BPTR)	"END-REWRITE",
	(BPTR)	"END-START",
	(BPTR)	"END-DELETE",
	(BPTR)	"AT",
	(BPTR)	"NOT",
	(BPTR)	"INVALID",
	(BPTR)	"PREVIOUS"
	};

static BPTR statement_keywords [_STATEMENT_MAX ] = {
	(BPTR)	"DISPLAY",
	(BPTR)	"ACCEPT",
	(BPTR)	"ADD",
	(BPTR)	"SUBTRACT",
	(BPTR)	"MULTIPLY",
	(BPTR)	"DIVIDE",
	(BPTR)	"STOP",
	(BPTR) 	"MOVE",
	(BPTR)	"TO",
	(BPTR)	"FROM",
	(BPTR)	"BY",
	(BPTR)	"INTO",
	(BPTR)	"GIVING",
	(BPTR)	"PERFORM",
	(BPTR)	"EXIT",
	(BPTR)	"TIMES",
	(BPTR)  "UNTIL",
	(BPTR)	"IF",
	(BPTR)	"ELSE",
	(BPTR)	"GO",
	(BPTR)  "CHAIN",
	(BPTR)	"DEPENDING",
	(BPTR)	"ON",
	(BPTR)  "END-IF",
	(BPTR)	"ENTER",
	(BPTR)  "END-PERFORM",
	(BPTR)	"COMPUTE",
	(BPTR)	"END-COMPUTE",
	(BPTR)	"CALL",
	(BPTR)	"EVALUATE",
	(BPTR)	"WHEN",
	(BPTR)	"END-EVALUATE",
	(BPTR)	"ALTER",
	(BPTR)	"INITIALIZE",
	(BPTR)	"CANCEL",
	(BPTR)	"INSPECT",
	(BPTR)	"STRING",
	(BPTR)	"UNSTRING",
	(BPTR)	"CONTINUE",
	(BPTR)	"END-ADD",
	(BPTR)	"END-SUBTRACT",
	(BPTR)	"END-MULTIPLY",
	(BPTR)	"END-DIVIDE",
	(BPTR)  "GOBACK",
	(BPTR)	"SET",
	(BPTR)  "SORT",
	(BPTR)  "SEARCH",
	(BPTR)  "MERGE",
	(BPTR)	"RETURN",
	(BPTR)	"RELEASE",
	(BPTR)	"END-SEARCH"
	};

static BPTR vctrl_keywords [_VCTRL_KEYWORD_MAX] = {
	(BPTR)	"PIC",   
	(BPTR)	"PICTURE",
	(BPTR)	"REDEFINES",
	(BPTR)  "VALUE",
	(BPTR)	"FD",
	(BPTR)	"RECORD",
	(BPTR)	"COMP",
	(BPTR)	"OCCURS",
	(BPTR)	"COMP-3",
	(BPTR)	"OF",
	(BPTR)	"FILE-ID",
	(BPTR)	"IS",
	(BPTR)  "INDEXED",
	(BPTR)  "INDEX",
	(BPTR)	"USAGE",
	(BPTR)	"COMPUTATIONAL",
	(BPTR)	"COMPUTATIONAL-3",
	(BPTR)	"DISPLAY",
	(BPTR)	"SIGN",
	(BPTR)	"LEADING",
	(BPTR)	"TRAILING",
	(BPTR)	"SYNCHRONIZED",
	(BPTR)	"SYNC",
	(BPTR)	"JUSTIFIED",
	(BPTR)	"JUST",
	(BPTR)	"BLANK",
	(BPTR)  "PACKED-DECIMAL",
	(BPTR)	"BINARY",
	(BPTR)	"GLOBAL",
	(BPTR)	"EXTERNAL",
	(BPTR)	"LABEL",
	(BPTR)	"POINTER",
	(BPTR)	"SD",
	(BPTR)	"RD"
	};

static BPTR fctrl_keywords [_FCTRL_KEYWORD_MAX] = {
	(BPTR)	"SELECT",
	(BPTR)	"ASSIGN",
	(BPTR)	"ORGANIZATION",
	(BPTR)	"RELATIVE",
	(BPTR)	"INDEXED",
	(BPTR)	"ACCESS",
	(BPTR)	"SEQUENTIAL",
	(BPTR)	"RANDOM",
	(BPTR)	"DYNAMIC",
	(BPTR)	"FILE",
	(BPTR)	"STATUS",
	(BPTR)	"RECORD",
	(BPTR)	"LINE",
	(BPTR)	"ALTERNATE",
	(BPTR)	"PASSWORD"
	};

static BPTR ioctrl_keywords [_IOCTRL_KEYWORD_MAX] = {
	(BPTR)	"RERUN",
	(BPTR)	"SAME",
	(BPTR)	"ON",
	(BPTR)	"EVERY",
	(BPTR)	"RECORDS",
	(BPTR)	"OF",
	(BPTR)	"CLOCK-TICKS",
	(BPTR)	"AREA",
	(BPTR)	"FOR"
	};

static BPTR identif_keywords [_IDENTIF_KEYWORD_MAX] = {
	(BPTR) "PROGRAM-ID",
	(BPTR) "AUTHOR",
	(BPTR) "INSTALLATION",
	(BPTR) "DATE-WRITTEN",
	(BPTR) "DATE-COMPILED",
	(BPTR) "SECURITY"
	};

static BPTR environ_keywords [_ENVIRON_KEYWORD_MAX] = {
	(BPTR)	"SECTION",
	(BPTR) 	"CONFIGURATION",
	(BPTR) 	"INPUT-OUTPUT"
	};

static BPTR envcfg_keywords [_ENVCFG_KEYWORD_MAX] = {
	(BPTR) "SOURCE-COMPUTER",
	(BPTR) "OBJECT-COMPUTER",
	(BPTR) "SPECIAL-NAMES"
	};

static BPTR envio_keywords [_ENVIO_KEYWORD_MAX] = {
	(BPTR) "FILE-CONTROL",
	(BPTR) "I-O-CONTROL"
	};

static BPTR datadiv_keywords [_DATADIV_KEYWORD_MAX] = {
	(BPTR)	"SECTION",
	(BPTR)	"FILE",
	(BPTR)	"WORKING-STORAGE",
	(BPTR)	"LINKAGE",
	(BPTR)	"SCREEN"
	};
static BPTR procdiv_keywords [_PROCDIV_KEYWORD_MAX] = {
	(BPTR)	"USING",
	(BPTR)	"DECLARATIVES",
	(BPTR)	"SECTION",
	};

static BPTR division_keywords [_DIVISION_KEYWORD_MAX] = {
	(BPTR) "DIVISION",
	(BPTR) "IDENTIFICATION",
	(BPTR) "ENVIRONMENT",
	(BPTR) "DATA",
	(BPTR) "PROCEDURE",
	(BPTR) "END"
	};

#endif

#define	_ID_DIV				1
#define	_ENV_DIV			2
#define	_DATA_DIV			3
#define	_PROC_DIV			4

#define	_STATEMENT_DISPLAY		0
#define	_STATEMENT_ACCEPT		1
#define	_STATEMENT_ADD			2
#define	_STATEMENT_SUBTRACT		3
#define	_STATEMENT_MULTIPLY		4
#define	_STATEMENT_DIVIDE		5
#define	_STATEMENT_STOP			6
#define	_STATEMENT_MOVE			7
#define	_STATEMENT_TO  			8
#define	_STATEMENT_FROM			9
#define	_STATEMENT_BY			10
#define	_STATEMENT_INTO			11
#define	_STATEMENT_GIVING		12
#define	_STATEMENT_PERFORM		13
#define	_STATEMENT_EXIT  		14
#define	_STATEMENT_TIMES		15
#define	_STATEMENT_UNTIL		16
#define	_STATEMENT_IF			17
#define	_STATEMENT_ELSE			18
#define	_STATEMENT_GO  			19
#define	_STATEMENT_CHAIN 		20
#define _STATEMENT_DEPENDING		21
#define _STATEMENT_ON			22
#define _STATEMENT_END_IF		23
#define _STATEMENT_ENTER 		24
#define _STATEMENT_END_PERFORM		25
#define _STATEMENT_COMPUTE		26
#define _STATEMENT_END_COMPUTE		27
#define	_STATEMENT_CALL			28
#define _STATEMENT_EVALUATE		29
#define _STATEMENT_WHEN			30
#define _STATEMENT_END_EVALUATE		31
#define _STATEMENT_ALTER       		32
#define _STATEMENT_INITIALIZE  		33
#define _STATEMENT_CANCEL      		34
#define _STATEMENT_INSPECT     		35
#define _STATEMENT_STRING      		36
#define _STATEMENT_UNSTRING      	37
#define _STATEMENT_CONTINUE      	38
#define _STATEMENT_END_ADD		39
#define _STATEMENT_END_SUBTRACT		40
#define _STATEMENT_END_MULTIPLY		41
#define _STATEMENT_END_DIVIDE		42
#define _STATEMENT_GOBACK		43
#define _STATEMENT_SET   		44
#define	_STATEMENT_SORT			45
#define	_STATEMENT_SEARCH		46
#define	_STATEMENT_MERGE		47
#define	_STATEMENT_RETURN		48
#define	_STATEMENT_RELEASE		49
#define	_STATEMENT_END_SEARCH		50

#define	_COBOL_OPEN			0
#define	_COBOL_CLOSE			1
#define	_COBOL_READ			2
#define	_COBOL_WRITE			3
#define	_COBOL_REWRITE			4
#define	_COBOL_START  			5
#define	_COBOL_DELETE 			6
#define	_COBOL_INPUT  			7
#define	_COBOL_OUTPUT 			8
#define	_COBOL_I_O    			9
#define	_COBOL_NEXT			10
#define	_COBOL_RECORD			11
#define	_COBOL_INTO			12
#define	_COBOL_FROM			13
#define	_COBOL_EXTEND			14
#define	_COBOL_END_READ			15
#define	_COBOL_END_WRITE		16  
#define	_COBOL_END_REWRITE		17 
#define	_COBOL_END_START		18
#define	_COBOL_END_DELETE		19
#define	_COBOL_AT			20
#define	_COBOL_NOT			21
#define	_COBOL_INVALID			22
#define	_COBOL_PREVIOUS			23

#define	_DIVISION_DIVISION		0
#define	_IDENTIFICATION_DIVISION	1
#define	_ENVIRONMENT_DIVISION		2	
#define	_DATA_DIVISION			3	
#define	_PROCEDURE_DIVISION		4
#define	_END_DIVISION      		5

#define	_IDENTIF_PROGRAM_ID		0
#define	_IDENTIF_AUTHOR			1
#define	_IDENTIF_INSTALLATION		2
#define	_IDENTIF_DATE_WRITTEN		3
#define	_IDENTIF_DATE_COMPILED		4
#define	_IDENTIF_SECURITY		5

#define	_ENVIRON_SECTION		0
#define	_ENVIRON_CONFIGURATION		1
#define	_ENVIRON_INPUT_OUTPUT		2

#define	_ENVCFG_SOURCE_COMPUTER		0
#define	_ENVCFG_OBJECT_COMPUTER		1
#define	_ENVCFG_SPECIAL_NAMES		2

#define	_ENVIO_FILE_CONTROL		0
#define	_ENVIO_I_O_CONTROL		1

#define	_FCTRL_SELECT			0
#define	_FCTRL_ASSIGN			1
#define	_FCTRL_ORGANIZATION		2
#define	_FCTRL_RELATIVE			3
#define	_FCTRL_INDEXED			4
#define	_FCTRL_ACCESS			5
#define	_FCTRL_SEQUENTIAL		6
#define	_FCTRL_RANDOM			7 
#define	_FCTRL_DYNAMIC			8 
#define	_FCTRL_FILE			9 
#define	_FCTRL_STATUS			10
#define	_FCTRL_RECORD			11
#define	_FCTRL_LINE 			12
#define	_FCTRL_ALTERNATE		13
#define	_FCTRL_PASSWORD 		14

#define	_IOCTRL_RERUN			0
#define	_IOCTRL_SAME			1

#define	_DATADIV_SECTION		0
#define	_DATADIV_FILE			1
#define	_DATADIV_WORKING_STORAGE	2
#define	_DATADIV_LINKAGE		3
#define	_DATADIV_SCREEN 		4

#define	_VCTRL_PIC			0
#define	_VCTRL_PICTURE			1
#define	_VCTRL_REDEFINES		2
#define	_VCTRL_VALUE			3
#define	_VCTRL_FD			4
#define	_VCTRL_RECORD			5
#define	_VCTRL_COMP  			6
#define	_VCTRL_OCCURS			7
#define	_VCTRL_COMP_3  			8
#define	_VCTRL_OF      			9
#define	_VCTRL_FILE_ID 			10
#define	_VCTRL_IS      			11
#define	_VCTRL_INDEXED 			12
#define	_VCTRL_INDEX 			13
#define	_VCTRL_USAGE 			14
#define	_VCTRL_COMPUTATIONAL		15
#define	_VCTRL_COMPUTATIONAL_3		16
#define	_VCTRL_DISPLAY			17
#define	_VCTRL_SIGN			18
#define	_VCTRL_LEADING			19
#define	_VCTRL_TRAILING			20
#define	_VCTRL_SYNCHRONIZED		21
#define	_VCTRL_SYNC			22
#define	_VCTRL_JUSTIFIED		23
#define	_VCTRL_JUST			24
#define	_VCTRL_BLANK			25
#define	_VCTRL_PACKED_DECIMAL		26
#define	_VCTRL_BINARY			27
#define	_VCTRL_GLOBAL			28
#define	_VCTRL_EXTERNAL			29
#define	_VCTRL_LABEL			30
#define	_VCTRL_POINTER			31
#define	_VCTRL_SD			32
#define	_VCTRL_RD			33

#define	_PROCDIV_USING			0
#define	_PROCDIV_DECLARATIVES		1
#define	_PROCDIV_SECTION		2

#define	_DECLARE_USE			0
#define	_DECLARE_END			1

#ifdef	_TRANSLAT_C
	COBOLPTR	Cobol=(COBOLPTR) 0;
#else
EXTERN	COBOLPTR	Cobol;
#endif

#ifndef	UNIX
WORD		enter_division( VOID );
WORD		enter_environ_section( VOID);
WORD		enter_data_section( VOID );
WORD		enter_control_section( VOID );
WORD		translate_file_control( VOID );
BPTR		get_parser_buffer( VOID );
RESULTPTR	evaluate_operation( WORD,RESULTPTR,RESULTPTR);
COBOLPTR	allocate_for_cobol( VOID );
COBOLPTR	liberate_for_cobol( VOID );
WORD		translate_line( BPTR );
WORD		translate_proc_div( VOID );
WORD		terminate_proc_div( VOID );
WORD		translator_startup( VOID );
WORD		translate_division( VOID );
WORD		translate_initialize( VOID );
#else
WORD		enter_division();
WORD		enter_environ_section();
WORD		enter_data_section();
WORD		enter_control_section();
WORD		translate_file_control();
BPTR		get_parser_buffer();
RESULTPTR	evaluate_operation();
COBOLPTR	allocate_for_cobol();
COBOLPTR	liberate_for_cobol();
WORD		translate_line();
WORD		translate_proc_div();
WORD		terminate_proc_div();
WORD		translator_startup();
WORD		translate_division();
WORD		translate_initialize();
#endif

#endif	/* _TRCOBOL_H */
	

