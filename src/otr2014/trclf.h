/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRCLF.H    				*/
/*		Version :	2.1c					*/
/*		Date	:	15/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRCLF_H
#define	_TRCLF_H

#include "trarg.h"

#ifdef	_TRCLF_C

#define	_MAX_ERROR_LABEL 64
#define	_MAX_CLF_DESCRIPTOR 1024

#define	CLFPTR	struct clf_context XPTR

struct	clf_context	{
	ARGPTR	root;
	ARGPTR	last;
	WORD	code;
	WORD	group;
	WORD	data;
	BYTE	descriptor[_MAX_CLF_DESCRIPTOR];
	WORD		ErrorFlag;
	WORD		ErrorAdr;
	RESULTPTR	Error;
	RESULTPTR	Target;	
	BYTE		ErrorLabel[_MAX_ERROR_LABEL];
	};



#define	_TRACE_KEYWORD_MAX	7
static BPTR trace_keywords [_TRACE_KEYWORD_MAX] = {
	(BPTR) "SET",
	(BPTR) "OFF",
	(BPTR) "PRINT",
	(BPTR) "DUMP",
	(BPTR) "SETDEF",
	(BPTR) "SETMUTE",
	(BPTR) "SETDEFMUTE"
	};

#define	_CLF_TRACE_SET				0x00
#define	_CLF_TRACE_OFF				0x01
#define	_CLF_TRACE_PRINT			0x02
#define	_CLF_TRACE_DUMP			0x03
#define	_CLF_TRACE_SETDEF			0x04
#define	_CLF_TRACE_SETMUTE		0x05
#define	_CLF_TRACE_SETDEFMUTE	0x06

#define	_MAX_CLF0	16

static BPTR 	clf0_keywords[ _MAX_CLF0 ] = {
	(BPTR) "CONV#",
	(BPTR) "CONV%",
	(BPTR) "CONV",
	(BPTR) "CONV$",
	(BPTR) "MOD",
	(BPTR) "PRINT",
	(BPTR) "#DATE",
	(BPTR) "#TIME",
	(BPTR) "#FILE",
	(BPTR) "#LINE",
	(BPTR) "NULL",
	(BPTR) "CLASS_NAME",
	(BPTR) "OBJECT_NAME",
	(BPTR) "SIZEOF",
	(BPTR) "CLASS_NUMBER",
	(BPTR) "OBJECT_NUMBER"
	};

#define	_MAX_CLF1	1

static BPTR 	clf1_keywords[ _MAX_CLF1 ] = {
	(BPTR)	"TRACE"
	};

#define	_CLF1_TRACE	0

#define	_MAX_CLF2	2

static BPTR 	clf2_keywords[ _MAX_CLF2 ] = {
	(BPTR)	"SPAWN",
	(BPTR)	"TASKID"
	};

#ifdef	ABAL32A
/*	------------------------------		*/
/*	Version Abal 3.2  Web Services		*/
/*	------------------------------		*/
/*	Tcode Thread Management Codes		*/
/*	------------------------------		*/

#define	_THREAD_MAX	10

#define	_THREAD_CREATE		0
#define	_THREAD_NUMBER		1
#define	_THREAD_PARENT  	2
#define	_THREAD_PRIORITY	3
#define	_THREAD_DURATION	4
#define	_THREAD_EVENT 		5
#define	_THREAD_REMOVE		6
#define	_THREAD_COUNT		7
#define	_THREAD_WAIT  		8
#define	_THREAD_ABQT  		9

static	BPTR	thread_keyword[ _THREAD_MAX ] = {
	(BPTR)	"CREATE",
	(BPTR)	"NUMBER",
	(BPTR)	"PARENT",
	(BPTR)	"PRIORITY",
	(BPTR)	"DURATION",
	(BPTR)	"EVENT",
	(BPTR)	"REMOVE",
	(BPTR)	"COUNT",
	(BPTR)	"WAIT",
	(BPTR)	"ABQT"
	};
#endif

#ifdef	ABAL32A
#define	_CLF3_THREAD	3
#define	_CLF4_THREAD	5
#endif

#define	_MAX_CLF3	4
static BPTR	clf3_keywords[ _MAX_CLF3 ] = {
	(BPTR) "HALT",
	(BPTR) "RAISE",
	(BPTR) "THROW",
	(BPTR) "THREAD"
	};

#define	_MAX_CLF4	6

static BPTR	clf4_keywords[ _MAX_CLF4 ] = {
	(BPTR) "OCXWAIT",
	(BPTR) "OCXNAME",
	(BPTR) "OCXCALL",
	(BPTR) "OCXGET",
	(BPTR) "OCXPUT",
	(BPTR) "THREAD"
	};

#define	_MAX_CLF5	4

static BPTR 	clf5_keywords[ _MAX_CLF5 ] = {
	(BPTR) "VALIDPTR",
	(BPTR) "ALIAS",
	(BPTR) "TRAIN",
	(BPTR) "LOADGO"

	};


#define	_MAX_CLF6	16

static BPTR 	clf6_keywords[ _MAX_CLF6 ] = {
	(BPTR) "CREATE", 
	(BPTR) "REMOVE",
	(BPTR) "FORGET",
	(BPTR) "FORGET",
	(BPTR) "ATTACH",
	(BPTR) "DETACH",
	(BPTR) "ALTER",
	(BPTR) "BUILD",
	(BPTR) "NNDROP",
	(BPTR) "EVALUATE",
	(BPTR) "SYNAPSE",	/* Input Synapse 	*/
	(BPTR) "SYNAPSE",	/* Output Synapse 	*/
	(BPTR) "WEIGHT",	/* Set Weight    	*/
	(BPTR) "WEIGHT",	/* Get Weight     	*/
	(BPTR) "THRESHOLD",	/* Set Threshold	*/
	(BPTR) "THRESHOLD"	/* Get Threshold	*/
	};

#define	_MAX_CLF7	16

static BPTR 	clf7_keywords[ _MAX_CLF7 ] = {
	(BPTR) "WAIT",
	(BPTR) "MASK",
	(BPTR) "RESTORE",
	(BPTR) "DATE",
	(BPTR) "KBF",
	(BPTR) "ASKCOLOR",
	(BPTR) "ASKATB",
	(BPTR) "HOTKEY",
	(BPTR) "LANG",
	(BPTR) "INITDATA",
	(BPTR) "END_USER",
	(BPTR) "END_PROC",
	(BPTR) "END_SEG",
	(BPTR) "EVENT",
	(BPTR) "IPCSEND",
	(BPTR) "LOADUSER"
	};

#define	_MAX_CLF8	6

static BPTR 	clf8_keywords[ _MAX_CLF8 ] = {
	(BPTR) "ABS",
	(BPTR) "INCLUD",
	(BPTR) "TRAN",
	(BPTR) "INSERT",
	(BPTR) "MKDIR",		/* $ */
	(BPTR) "RMDIR"		/* $ */
	};


#define	_MAX_CLF9	7

static BPTR 	clf9_keywords[ _MAX_CLF9 ] = {
	(BPTR) "ATN",
	(BPTR) "COS",
	(BPTR) "EXP",
	(BPTR) "LOG",
	(BPTR) "SIN",
	(BPTR) "SQR",
	(BPTR) "TAN"
	};

#define	_MAX_CLFA	10
#define	CLF_SHR		0x003A

static BPTR 	clfa_keywords[ _MAX_CLFA ] = {
	(BPTR) "LARGE",
	(BPTR) "SMALL",
	(BPTR) "SHL",
	(BPTR) "SHR",
	(BPTR) "INV",
	(BPTR) "FM",
	(BPTR) "FM",
	(BPTR) "FM",
	(BPTR) "ENV",
	(BPTR) "ASCIIFM"
	};

#define	_MAX_CLFB	16
#define	CLF_LEN		0x002B
#define	CLF_MOD		0x009E
#define	_CLFB_LEN	2
#define	_CLFB_LEN$	3
#define	_CLFB_DAYS	12
#define	_CLFB_RUNTIME	13
#define	_CLFB_WILDCOMP	14
#define	_CLFB_CHDIR   	15

static BPTR 	clfb_keywords[ _MAX_CLFB ] = {
	(BPTR) "HASH",
	(BPTR) "DEC",
	(BPTR) "LEN",
	(BPTR) "LEN$",
	(BPTR) "SGN",
	(BPTR) "INDEX",
	(BPTR) "INSTR",
	(BPTR) "VPTR",
	(BPTR) "FMINT",
	(BPTR) "FMFP",
	(BPTR) "POWER",
	(BPTR) "CHECKFMT",
	(BPTR) "DAYS",
	(BPTR) "RUNTIME",
	(BPTR) "WILDCOMP",
	(BPTR) "CHDIR"
	};

#define	_MAX_CLFC	8

static BPTR 	clfc_keywords[ _MAX_CLFC ] = {
	(BPTR) "LEFT",
	(BPTR) "RIGHT",
	(BPTR) "SUBSTR",
	(BPTR) "MOVE",
	(BPTR) "SWAP",
	(BPTR) "PARSE",
	(BPTR) "ABALANFC",
	(BPTR) "TOKENISE"
	};


#define	_MAX_CLFD	16
#define	_CLFD_GENER	 0
#define	_CLFD_SPACE	 1
#define	_CLFD_CHR	 7
#define	_CLFD_PROC	11
#define	_CLFD_USER	12
#define	_CLFD_SEGM	13

static BPTR 	clfd_keywords[ _MAX_CLFD ] = {
	(BPTR) "GENER",
	(BPTR) "SPACE",
	(BPTR) "DATE",
	(BPTR) "KBF",
	(BPTR) "CURDIR",
	(BPTR) "CURVOL",
	(BPTR) "HEX",
	(BPTR) "CHR",
	(BPTR) "REPSTR",
	(BPTR) "CRYPT",
	(BPTR) "SYSERROR",
	(BPTR) "PROC", 
	(BPTR) "USER", 
	(BPTR) "SEGMENT", 
	(BPTR) "IPCTEST",	/* 14 D */
	(BPTR) "IPCWAIT"
	};


#define	_MAX_CLFE	9

static BPTR 	clfe_keywords[ _MAX_CLFE ] = {
	(BPTR) "FIX",
	(BPTR) "ROUN",
	(BPTR) "FP",
	(BPTR) "INT",
	(BPTR) "VAL",
	(BPTR) "STDFORM",
	(BPTR) "REAL",
	(BPTR) "STRN",
	(BPTR) "LONG"
	};


#define	_MAX_CLFF	11

static BPTR 	clff_keywords[ _MAX_CLFF ] = {
	(BPTR) "COL",
	(BPTR) "LIN",
	(BPTR) "PROCESS", 
	(BPTR) "RND",
	(BPTR) "MASK", 
	(BPTR) "CONF",
	(BPTR) "ERRADR",
	(BPTR) "RESTORE", 
	(BPTR) "EVENTADR",
	(BPTR) "HOTKEY", 
	(BPTR) "EVENT"
	};

#endif

/*	CLF GROUP 3	*/
/* 	-----------	*/
#define	_CLF_HALT	0
#define	_CLF_RAISE	1
#define	_CLF_THROW	2



/*	CLF GROUP 4	*/
/* 	-----------	*/
#define	_CLF_OCXWAIT	0
#define	_CLF_OCXNAME	1
#define	_CLF_OCXCALL	2
#define	_CLF_OCXGET	3
#define	_CLF_OCXPUT	4


/*	CLF GROUP 6	*/
/*	-----------	*/

#define	_CLF_CREATE		0x00 
#define	_CLF_REMOVE		0x01
#define	_CLF_FORGET		0x02
#define	_CLF_ALIAS		0x03
#define	_CLF_ATTACH		0x04
#define	_CLF_DETACH		0x05
#define	_CLF_ALTER		0x06
#define	_CLF_BUILD		0x07
#define	_CLF_DROP 		0x08
#define	_CLF_EVALUATE 		0x09
#define	_CLF_SYNAPSE		0x0A
#define	_CLF_OUTPUT_SYNAPSE	0x0B
#define	_CLF_WEIGHT 		0x0C
#define	_CLF_OUTPUT_WEIGHT	0x0D
#define	_CLF_THRESHOLD		0x0E
#define	_CLF_OUTPUT_THRESHOLD	0x0F

/*	CLF GROUP 7	*/
/*	-----------	*/

#define	_CLF_WAIT		0x00
#define	_CLF_MASK		0x01
#define	_CLF_RESTORE		0x02
#define	_CLF_DATE		0x03
#define	_CLF_KBF		0x04
#define	_CLF_ASKCOLOR		0x05
#define	_CLF_ASKATB		0x06
#define	_CLF_HOTKEY		0x07
#define	_CLF_LANG		0x08
#define	_CLF_INITDATA		0x09
#define	_CLF_END_USER		0x0A
#define	_CLF_END_PROC		0x0B
#define	_CLF_END_SEG		0x0C
#define	_CLF_EVENT		0x0D
#define	_CLF_SEND		0x0E

/*	CLF GROUP 0	*/
/*	-----------	*/

#define	_CLF_CONV0		0x00
#define	_CLF_CONV1		0x01
#define	_CLF_CONV		0x02
#define	_CLF_CONV3		0x03
#define	_CLF_MOD  		0x04
#define	_CLF_PRINT		0x05
#define	_CLF_TRDATE		0x06
#define	_CLF_TRTIME		0x07
#define	_CLF_TRFILE		0x08
#define	_CLF_TRLINE		0x09
#define	_CLF_NULL  		0x0A
#define	_CLF_CLASS_NAME		0x0B
#define	_CLF_OBJECT_NAME	0x0C
#define	_CLF_SIZEOF		0x0D
#define	_CLF_CLASS_NUMBER	0x0E
#define	_CLF_OBJECT_NUMBER	0x0F

/*	CLF GROUP D	*/
/*	-----------	*/
#define	_CLF_GENER		0x00
#define	_CLF_SPACE		0x01
#define	_CLF_GETDATE		0x02
#define	_CLF_GETKBF		0x03
#define	_CLF_CURDIR		0x04
#define	_CLF_CURVOL		0x05
#define	_CLF_HEX		0x06
#define	_CLF_CHR		0x07
#define	_CLF_REPSTR		0x08
#define	_CLF_CRYPT		0x09
#define	_CLF_SYSERROR		0x0A
#define	_CLF_PROC 		0x0B
#define	_CLF_USER 		0x0C
#define	_CLF_SEGM		0x0D
#define	_CLF_IPCTEST		0x0E
#define	_CLF_IPCWAIT		0x0F


/*	---------------------------------------------------	*/
/*	Prototypes for external callers of PUBLIC functions	*/
/*	---------------------------------------------------	*/
#ifdef	_C_RTL_GEN
#define	CLFRETPTR BPTR
#else	
#define	CLFRETPTR RESULTPTR
#endif


#ifndef	UNIX

/* Internal functions to trclf.c
VOID		release_clf_context( CLFPTR );
WORD		release_void_context( CLFPTR, WORD );
RESULTPTR	release_context( CLFPTR, RESULTPTR );
VOID		flush_clf_format( BPTR );
RESULTPTR	make_target_variable( WORD );
WORD		store_clf_fmt( CLFPTR, BPTR );
WORD		store_clf(CLFPTR, RESULTPTR );
WORD		get_string_parameter( CLFPTR );
WORD		get_integer_parameter( CLFPTR );
WORD		get_numeric_parameter( CLFPTR );
WORD		get_parameter( CLFPTR );
WORD		get_zone_parameter( CLFPTR );
WORD		get_address_parameter( CLFPTR );
WORD		optional_parameters( CLFPTR );
WORD		eligible_for_clf6( WORD , TCVARPTR );
WORD		clf6_parameters( CLFPTR );
WORD		clf_explicite_label( CLFPTR );
WORD		clf_implicite_label( CLFPTR, WORD );
WORD		clf_error_trap( CLFPTR );
WORD		translate_clf6( WORD );
*/
WORD		use_dimensions( VOID );
RESULTPTR	affect_proc_pointer( WORD );
WORD		is_clf0( VOID );
WORD		is_clf1( VOID );
WORD		is_clf2( VOID );
WORD		is_clf3( VOID );
WORD		is_clf4( VOID );
WORD		is_clf6( VOID );
WORD		is_clf5( VOID );
WORD		is_clf7( VOID );
WORD		is_clf8( VOID );
WORD		is_clf9( VOID );
WORD		is_clfa( VOID );
WORD		is_clfb( VOID );
WORD		is_clfc( VOID );
WORD		is_clfd( VOID );
WORD		is_clfe( VOID );
WORD		is_clff( VOID );
WORD		translate_clf( VOID );
RESULTPTR	evaluate_clf( VOID );
RESULTPTR	clf_abs_zero( VOID );
RESULTPTR	clf_space( WORD );
WORD		clf_initlocal( VOID );
WORD		clf_initglobal( VOID );
RESULTPTR	clf_reg_alias( RESULTPTR );
RESULTPTR	clf_date( WORD );
RESULTPTR	clf_validptr( TCVARPTR );
WORD		clf_create( RESULTPTR );
WORD		clf_alias( RESULTPTR, RESULTPTR );
WORD		clf_funcptr( RESULTPTR, RESULTPTR, TCPRCPTR );
WORD		clf_userptr( RESULTPTR, RESULTPTR, RESULTPTR );
WORD		clf_segmptr( RESULTPTR, RESULTPTR );
WORD		clf_remove( RESULTPTR );
WORD		clf_forget( RESULTPTR );
WORD		clf_mask( WORD );
WORD		clf_lang( WORD );
RESULTPTR	clf_hotkey( VOID );
RESULTPTR	clf_conf( WORD );
RESULTPTR	clf_round( RESULTPTR, WORD );
RESULTPTR	clf_index( RESULTPTR, RESULTPTR );
RESULTPTR	clf_includ( RESULTPTR, RESULTPTR );
RESULTPTR	clf_substr( RESULTPTR, RESULTPTR, RESULTPTR );
RESULTPTR	clf_gener( RESULTPTR, RESULTPTR );
WORD		cancel_clf_instruction( VOID );

#else
WORD		translate_clf();
CLFRETPTR	evaluate_clf();
CLFRETPTR	clf_space();
CLFRETPTR	clf_round();
CLFRETPTR	clf_reg_alias();
CLFRETPTR	clf_date();
CLFRETPTR	clf_hotkey();
CLFRETPTR	clf_abs_zero();
CLFRETPTR	clf_conf();
CLFRETPTR	intrinsic_functions();
CLFRETPTR	clf_substr();
CLFRETPTR	clf_index();
CLFRETPTR	clf_includ();
CLFRETPTR	clf_gener();
#endif

#endif	/* _TRCLF_H */
	/* -------- */

