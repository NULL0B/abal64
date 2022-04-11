/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1991,1993 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	ABAL.H					*/
/*		Version :	1.1a					*/
/*		Date	:	28/07/1993				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	ABALH
#define ABALH

#define	CONSTPTR	struct aplus_constant XPTR
#define	ABALSTATUS	struct abal_status

struct	aplus_constant {
	BPTR		name;
	EXAWORD		type;
	EXAWORD		value;
	EXAWORD		flag;
	CONSTPTR	next;
	};

struct	abal_status {
	TYPEPTR	ExitType;
	EXAWORD	Exit;
	EXAWORD	RetSeg;
	EXAWORD	Stop;
	EXAWORD	Data;
	EXAWORD	Destructor;
	EXAWORD	Special;
	EXAWORD	PostCondition;
	TRAPPTR	Exception;
	EXABYTE	ProgModName[16];
	};

#ifdef	ABALC

#define ABALKEYWORDMAX 	48

static BPTR abal_keywords [ABALKEYWORDMAX] = {
	(BPTR) "CONST",
	(BPTR) "ENDLOC",
	(BPTR) "SEGMENT",
	(BPTR) "ESEG",
	(BPTR) "PROC",
	(BPTR) "ENDPROC",
	(BPTR) "PROGRAM",
	(BPTR) "MODULE",
	(BPTR) "DCL",
	(BPTR) "EXTERN",
	(BPTR) "END",
	(BPTR) "EVENT",
	(BPTR) "FIELD",
	(BPTR) "EXIT",
	(BPTR) "STOP",
	(BPTR) "RET",
	(BPTR) "SEG",
	(BPTR) "DATA",
	(BPTR) "SIZEOF",
	(BPTR) "VERSION",
	(BPTR) "RUNTIME",
	(BPTR) "ARG",
	(BPTR) "ALTER",
	(BPTR) "OBJECT_FIELD",
	(BPTR) "CLASS_NUMBER",
	(BPTR) "OBJECT_NUMBER",
	(BPTR) "CLASS_NAME",
	(BPTR) "OBJECT_NAME",
	(BPTR) "ENTER",
	(BPTR) "LEAVE",
	(BPTR) "PTR",
	(BPTR) "FORWARD",
	(BPTR) "HALT",
	(BPTR) "USER",
	(BPTR) "RAISE",
	(BPTR) "RESUME",
	(BPTR) "BREAK",
	(BPTR) "CREATE",
	(BPTR) "FORGET",
	(BPTR) "REMOVE",
	(BPTR) "ERROR",
	(BPTR) "THIS",
	(BPTR) "ALIAS",
	(BPTR) "ATTACH",
	(BPTR) "DETACH",
	(BPTR) "NEW_FIELD",
	(BPTR) "THROW",
	(BPTR) "CLASS_SIZE"
	};

EXAWORD	HashKeyWords[ ABALKEYWORDMAX ];

#endif

#define	_ABAL_CONST	0
#define	_ABAL_ENDLOC	1
#define	_ABAL_SEGMENT	2
#define	_ABAL_ESEG	3
#define	_ABAL_PROC	4
#define	_ABAL_ENDPROC	5
#define	_ABAL_PROGRAM	6
#define	_ABAL_MODULE	7
#define	_ABAL_DCL	8
#define	_ABAL_EXTERN	9
#define	_ABAL_END	10
#define	_ABAL_EVENT	11
#define	_ABAL_FIELD	12
#define	_ABAL_EXIT	13
#define	_ABAL_STOP	14
#define	_ABAL_RET	15
#define	_ABAL_SEG	16
#define _ABAL_DATA	17
#define	_ABAL_SIZEOF	18
#define	_ABAL_VERSION	19
#define	_ABAL_RUNTIME	20
#define	_ABAL_ARG	21
#define	_ABAL_ALTER	22
#define	_ABAL_OBJ_FIELD	23
#define	_ABAL_CLS_NUMBER	24
#define	_ABAL_OBJ_NUMBER	25
#define	_ABAL_CLS_NAME  	26
#define	_ABAL_OBJ_NAME  	27
#define	_ABAL_RESTART		28
#define	_ABAL_LEAVE		29
#define	_ABAL_PTR		30
#define	_ABAL_FORWARD		31
#define	_ABAL_HALT		32
#define	_ABAL_USER		33
#define	_ABAL_RAISE		34
#define	_ABAL_RESUME		35
#define	_ABAL_BREAK		36
#define	_ABAL_CREATE		37
#define	_ABAL_FORGET		38
#define	_ABAL_REMOVE		39
#define	_ABAL_ERROR		40
#define	_ABAL_THIS		41
#define	_ABAL_ALIAS		42
#define	_ABAL_ATTACH		43
#define	_ABAL_DETACH		44
#define	_ABAL_NEW_FIELD		45
#define	_ABAL_THROW    		46
#define	_ABAL_CLS_SIZE		47

#ifdef	ABALC

CONSTPTR	ConstBase;
ABALSTATUS	AbalStatus;

#else

extern	CONSTPTR	ConstBase;
extern	ABALSTATUS	AbalStatus;

#endif

#define	ABAL_PROGRAM	"Program\t"
#define	ABAL_MODULE	"Module\t"
#define	ABAL_EXTERN	"Extern\t"
#define	ABAL_FORWARD	"Forward\t"
#define	ABAL_CONST	"Const\t"
#define	ABAL_PROC	"Proc\t"
#define	ABAL_SEGMENT	"Segment "
#define	ABAL_ENDPROC	"EndProc"
#define	ABAL_ESEG	"Eseg "
#define	ABAL_ENDLOC	"EndLoc"
#define	ABAL_ENDEVENT	"End Event"
#define	ABAL_STOP	"Stop"
#define	ABAL_EXIT	"Exit"
#define	ABAL_OVERLAY	"Ldgo.Seg\t"
#define	ABAL_RETSEG	"Ret.Seg"
#define	ABAL_RET	"Ret"
#define	ABAL_SEG	"Seg"
#define	ABAL_END	"End "
#define	ABAL_GOTO	"Goto "
#define	ABAL_CALL	"Call "
#define	ABAL_GOSUB	"\tGosub "
#define	ABAL_RAISE	"Error "
#define	ABAL_RETURN	"\tReturn "
#define	ABAL_INITLOCAL	"\tInitLocal"
#define	ABAL_BREAK	"Break"
#define	ABAL_RESUME	"Resume"
#define	ABAL_CREATE	"Create "
#define	ABAL_FORGET	"Forget "
#define	ABAL_REMOVE	"Remove "
#define ABAL_ATTACH 	"Attach "
#define ABAL_DETACH	"Detach "
#define	ABAL_ALTER	"Alter "

#ifndef CHECK_PROTO_ARGS
EXAWORD		is_abal_keyword();
EXAWORD		constant_value();
CONSTPTR	is_constant();
#else
CONSTPTR	is_constant( BPTR );
EXAWORD		is_abal_keyword( BPTR );
EXAWORD		constant_value( BPTR );
#endif

#endif	/* ABALH */
	/* ----- */

