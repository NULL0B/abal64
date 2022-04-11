/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 2012 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRSYNTAX.H				*/
/*		Version :	4.1a					*/
/*		Date	:	02/01/2012				*/
/*									*/
/* --------------------------------------------------------------------	*/
/* IJM : Modification for ABAL / CRITERIA POSTGRE SQL 2 Jan 2012	*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRSYNTAX_H
#define	_TRSYNTAX_H

#define	PRJ918

#ifdef	_TRSYNTAX_C

#ifdef	ABALSQL
#define	_NGF_KEYWORD_MAX	0x003F
#else
#define	_NGF_KEYWORD_MAX	0x002F
#endif

static BPTR ngf_keywords [_NGF_KEYWORD_MAX] = {
	(BPTR)	"CFILE",		/* 0x0000 */
	(BPTR)	"DFILE",		/* 0x0001 */
	(BPTR)	"RENAME",		/* 0x0002 */
	(BPTR)	"OPEN",			/* 0x0003 */
	(BPTR)	"CLOSE",		/* 0x0004 */
	(BPTR)	"READ",			/* 0x0005 */
	(BPTR)	"WRITE",		/* 0x0006 */
	(BPTR)	"INSERT",		/* 0x0007 */
	(BPTR)	"MODIF",		/* 0x0008 */
	(BPTR)	"DELETE",		/* 0x0009 */
	(BPTR)	"SEARCH",		/* 0x000A */
	(BPTR)	"DOWN",			/* 0x000B */
	(BPTR)	"UP",			/* 0x000C */
	(BPTR)	"ATB",		/* 0x000D */
	(BPTR)	"BACKSPACE",	/* 0x000E */
	(BPTR)	"EXTEND",		/* 0x000F */
	(BPTR)	"ASSIGN",		/* 0x0010 */
	(BPTR)	"LOAD",		/* 0x0011 */
	(BPTR)	"XCRI",		/* 0x0012 */
	(BPTR)	"CHAIN",	/* 0x0013 */
	(BPTR)	"KEY",		/* 0x0014 */
	(BPTR)	"CKEY",		/* 0x0015 */
	(BPTR)	"RKEY",		/* 0x0016 */
	(BPTR)	"FKEY",		/* 0x0017 */
	(BPTR)	"NKEY",		/* 0x0018 */
	(BPTR)	"LKEY",		/* 0x0019 */
	(BPTR)	"LINK",		/* 0x001A */
	(BPTR)	"CLINK",	/* 0x001B */
	(BPTR)	"LLINK",	/* 0x001C */
	(BPTR)	"POSIT",	/* 0x001D */
	(BPTR)	"COUNT",	/* 0x001E */
	(BPTR)	"STAT",		/* 0x001F */
	(BPTR)	"RECORD",	/* 0x0020 */
	(BPTR)	"JOIN",		/* 0x0021 */
	(BPTR)	"CJOIN",	/* 0x0022 */
	(BPTR)	"DJOIN",	/* 0x0023 */
	(BPTR)	"RJOIN",	/* 0x0024 */ 
	(BPTR)	"LJOIN",	/* 0x0025 */
	(BPTR)	"LFILE",	/* 0x0026 */
	(BPTR)	"FIND",		/* 0x0027 */
	(BPTR)	"FILE",		/* 0x0028 */
	(BPTR)	"NAME",		/* 0x0029 */
	(BPTR)  "SESSION",	/* 0x002A */ /* PRJ918 */
	(BPTR)  "(((*)))",	/* 0x002B */ /* OLD COLLECT */
	(BPTR)  "CONSULT",	/* 0x002C */ /* PRJEIS */
	(BPTR)  "COLLECT"	/* 0x002D */

#ifdef	ABALSQL
	,(BPTR) "CONNECT",	/* 0x002E */
	(BPTR)	"BEGIN",	/* 0x002F */
	(BPTR)	"COMMIT",	/* 0x0030 */
	(BPTR)	"ROLLBACK",	/* 0x0031 */
	(BPTR)	"PREPARE",	/* 0x0032 */
	(BPTR)	"EXEC",		/* 0x0033 */
	(BPTR)	"GETROWCOL",	/* 0x0034 */
	(BPTR)	"GETCOLNAME",	/* 0x0035 */
	(BPTR)	"FETCH",	/* 0x0036 */
	(BPTR)	"GETFIELD",	/* 0x0037 */
	(BPTR)	"DROP",		/* 0x0038 */
	(BPTR)	"GETSQLERROR",	/* 0x0039 */
	(BPTR)	"GETSERVICEINFO",/* 0x003A */
	(BPTR)	"BINDPARAM",	/* 0x003B */
	(BPTR)	"BINDCOL",	/* 0x003C */
#endif
	(BPTR)  "INXSQUERY",	/* 0x003D */
	(BPTR)  "INXSSELECT"	/* 0x003E */
	};

#define	_IOF_KEYWORD_MAX	6
	
static BPTR iof_keywords [_IOF_KEYWORD_MAX] = {
	(BPTR) "PRINT",
	(BPTR) "ASK",
	(BPTR) "PAUSE",
	(BPTR) "OP",
	(BPTR) "GET",
	(BPTR) "PUT"
	};

#define	_LEVEL1_KEYWORD_MAX	25

static BPTR level1_keywords [_LEVEL1_KEYWORD_MAX] = {
	(BPTR) "PROGRAM",
	(BPTR) "MODULE",
	(BPTR) "SEGMENT",
	(BPTR) "PROC",
	(BPTR) "END",
	(BPTR) "EXTERN",
	(BPTR) "FORWARD",
	(BPTR) "DCL",
	(BPTR) "FIELD",
	(BPTR) "PTR",
	(BPTR) "CONST",
	(BPTR) "ARG",
	(BPTR) "STRUCT",
	(BPTR) "ENDSTRUCT",
	(BPTR) "PUBLIC",
	(BPTR) "PRIVATE",
	(BPTR) "UNION",
	(BPTR) "ENDUNION",
	(BPTR) "CLASS",
	(BPTR) "ENDCLASS",
	(BPTR) "LOCAL",
	(BPTR) "LIBRARY",
	(BPTR) "__STDC",
	(BPTR) "EXPORT",
	(BPTR) "REMOTE"
	};

#define	_LEVEL2_KEYWORD_MAX	5

static BPTR level2_keywords [_LEVEL2_KEYWORD_MAX] = {
	(BPTR) "ENDLOC",
	(BPTR) "ESEG",
	(BPTR) "ENDPROC",
	(BPTR) "ENTER",
	(BPTR) "LEAVE"
	};

#define	_DCL_KEYWORD_MAX 6

static	BPTR	dcl_keywords [_DCL_KEYWORD_MAX] = {
	(BPTR) "LIKE",
	(BPTR) "PROC",
	(BPTR) "SEGM",
	(BPTR) "USER",
	(BPTR) "CODE",
	(BPTR) "FILLER"
	};

#define	_CONTROL_KEYWORD_MAX	46

static BPTR control_keywords [_CONTROL_KEYWORD_MAX] = {
	(BPTR) "IF",
	(BPTR) "ELSE",
	(BPTR) "ENDIF",
	(BPTR) "WHILE",
	(BPTR) "WEND",
	(BPTR) "REPEAT",
	(BPTR) "UNTIL",
	(BPTR) "FOR",
	(BPTR) "NEXT",
	(BPTR) "TO",
	(BPTR) "STEP",
	(BPTR) "SELECT",
	(BPTR) "CASE",
	(BPTR) "DEFAULT",
	(BPTR) "ENDSEL",
	(BPTR) "DO",
	(BPTR) "LOOP",
	(BPTR) "BREAK",
	(BPTR) "GOSUB",
	(BPTR) "RETURN",
	(BPTR) "GOTO",
	(BPTR) "CALL",
	(BPTR) "EXIT",
	(BPTR) "LDGO",
	(BPTR) "SEG",
	(BPTR) "RET",
	(BPTR) "STOP",
	(BPTR) "DATA",
	(BPTR) "ON",
	(BPTR) "OF",
	(BPTR) "OFF",
	(BPTR) "THEN",
	(BPTR) "EVENT",
	(BPTR) "EXTERN",
	(BPTR) "TIMER",
	(BPTR) "LOCAL",
	(BPTR) "ABORT",
	(BPTR) "ERROR",
	(BPTR) "RESUME",
	(BPTR) "FMT",
	(BPTR) "CALLBACK",
	(BPTR) "INITLOCAL",
	(BPTR) "INITGLOBAL",

	(BPTR) "TRY",
	(BPTR) "CATCH",
	(BPTR) "ENDTRY"

	};

#define	_LOGICAL_KEYWORD_MAX	3

static BPTR logical_keywords [_LOGICAL_KEYWORD_MAX] = {
	(BPTR) "AND",
	(BPTR) "OR",
	(BPTR) "OX"
	};

#define	_NURAL_KEYWORD_MAX	10

static	BPTR	nural_keywords [ _NURAL_KEYWORD_MAX ] = {
	(BPTR)	"NETWORK",
	(BPTR)	"NURONE",
	(BPTR)	"INPUT",
	(BPTR)	"OUTPUT",
	(BPTR)	"HIDDEN",
	(BPTR)	"LAYER",
	(BPTR)	"ENDNETWORK",
	(BPTR)	"SUMATE",
	(BPTR)  "LIMITER",
	(BPTR)  "SIGMOID"
	};

#endif	/* _TRSYNTAX_C */

#include "trtcngf.h"
#include "trtciof.h"

#define	_LOGICAL_AND	0
#define	_LOGICAL_OR 	1
#define	_LOGICAL_OX 	2
#define _LOGICAL_USE    3
#define _LOGICAL_LAB    4
#define _LOGICAL_NEX    5
#define	_LOGICAL_END 	MOINS_UN

#define	_NURO_NETWORK		0
#define	_NURO_NURONE		1
#define	_NURO_INPUT  		2
#define	_NURO_OUTPUT		3
#define	_NURO_HIDDEN		4
#define	_NURO_LAYER		5
#define	_NURO_ENDNETWORK	6
#define	_NURO_SUMATE    	7
#define	_NURO_LIMITER   	8
#define	_NURO_SIGMOID   	9


#define	_KW1_PROGRAM	0
#define	_KW1_MODULE	1
#define	_KW1_SEGMENT	2
#define	_KW1_PROC	3
#define	_KW1_END	4
#define	_KW1_EXTERN	5
#define	_KW1_FORWARD	6
#define	_KW1_DCL	7
#define	_KW1_FIELD	8
#define	_KW1_PTR	9
#define	_KW1_CONST	10
#define	_KW1_ARG	11
#define	_KW1_STRUCT	12
#define	_KW1_ENDSTRUCT	13
#define	_KW1_PUBLIC   	14
#define	_KW1_PRIVATE  	15
#define	_KW1_UNION	16
#define	_KW1_ENDUNION	17
#define	_KW1_CLASS	18
#define	_KW1_ENDCLASS	19
#define _KW1_LOCAL	20
#define _KW1_LIBRARY	21
#define _KW1_STDC	22
#define _KW1_EXPORT	23
#define _KW1_REMOTE	24

/*	-------------------------------------------------------		*/
/*	These values do not represent keywords, rather concepts		*/
/*	-------------------------------------------------------		*/
#define	_KW1_OVL     	55	/* Explicite Overlay Pointer		*/
#define	_KW1_OBJ     	66	/* Instance Implicite PTR, member DCL	*/
#define	_KW1_CMN	77	/* Implicite PTR			*/
#define	_KW1_IND	88	/* Implicite PTR			*/
/*	-------------------------------------------------------		*/



#define	_KW2_ENDLOC 	0
#define	_KW2_ESEG  	1
#define	_KW2_ENDPROC  	2
#define	_KW2_ENTER    	3
#define	_KW2_LEAVE    	4

#define	_DCL_NORMAL	0
#define	_DCL_LIKE	0
#define	_DCL_PROC   	1
#define	_DCL_SEGM  	2
#define	_DCL_USER   	3
#define _DCL_CODE	4
#define	_DCL_FILLER	5

#define _CTRL_IF	0	
#define _CTRL_ELSE	1	
#define _CTRL_ENDIF	2	
#define _CTRL_WHILE	3	
#define _CTRL_WEND	4	
#define _CTRL_REPEAT	5	
#define _CTRL_UNTIL	6	
#define _CTRL_FOR	7	
#define _CTRL_NEXT	8	
#define _CTRL_TO	9	
#define _CTRL_STEP	10	
#define _CTRL_SELECT	11	
#define _CTRL_CASE	12	
#define _CTRL_DEFAULT	13	
#define _CTRL_ENDSEL	14	
#define _CTRL_DO	15	
#define _CTRL_LOOP	16	
#define _CTRL_BREAK	17	
#define _CTRL_GOSUB	18	
#define _CTRL_RETURN	19	
#define _CTRL_GOTO	20	
#define _CTRL_CALL	21	
#define _CTRL_EXIT	22	
#define _CTRL_LDGO	23	
#define _CTRL_SEG	24	
#define _CTRL_RET	25	
#define _CTRL_STOP	26	
#define _CTRL_DATA	27	
#define _CTRL_ON	28	
#define _CTRL_OF	29	
#define _CTRL_OFF	30	
#define _CTRL_THEN	31	
#define _CTRL_EVENT	32	
#define _CTRL_EXTERN	33	
#define _CTRL_TIMER	34	
#define _CTRL_LOCAL	35	
#define _CTRL_ABORT	36	
#define _CTRL_ERROR	37	
#define _CTRL_RESUME    38
#define _CTRL_FMT	39
#define _CTRL_CALLBACK	40
#define _CTRL_INITLOCAL	41
#define _CTRL_INITGLOBAL 42
#define _CTRL_TRY 	43
#define _CTRL_CATCH 	44
#define _CTRL_ENDTRY	45
#define _CTRL_EXPORT	46

#ifndef	UNIX

WORD	compare_tokens( BPTR , BPTR );
WORD	uppercase_compare( BPTR , BPTR );
WORD	uppercase_ncompare( BPTR , BPTR, WORD );
VOID	uppercase_keyword( VOID );
WORD	keyword_hash( BPTR );
BPTR	get_ngf_keyword( WORD );
WORD	is_ngf_keyword( VOID );
#ifdef	WITH_NURAL
WORD	is_nural_keyword( VOID );
#endif
VOID	ick_statistics( VOID );
BPTR	get_class_keyword( WORD );
WORD	is_class_keyword( VOID );
WORD	is_iof_keyword( VOID );
WORD	is_level1_keyword( VOID );
WORD	is_level2_keyword( VOID );
WORD	is_dcl_keyword( VOID );
WORD	is_control_keyword( VOID );
WORD	is_logical_keyword( VOID );
WORD	comparison_operator( WORD );
VOID	cancel_keyword( BPTR XPTR );
VOID	set_keyword_status( WORD );
#else
WORD	compare_tokens( );
WORD	uppercase_compare( );
WORD	uppercase_ncompare( );
VOID	uppercase_keyword( );
WORD	keyword_hash( );
BPTR	get_ngf_keyword( );
WORD	is_ngf_keyword( );
#ifdef	WITH_NURAL
WORD	is_nural_keyword( );
#endif
VOID	ick_statistics( );
BPTR	get_class_keyword( );
WORD	is_class_keyword( );
WORD	is_iof_keyword( );
WORD	is_level1_keyword( );
WORD	is_level2_keyword( );
WORD	is_dcl_keyword( );
WORD	is_control_keyword( );
WORD	is_logical_keyword( );
WORD	comparison_operator( );
VOID	cancel_keyword( );
VOID	set_keyword_status( );

#endif

#endif 	/* _TRSYNTAX_H */
	/* ----------- */

