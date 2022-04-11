/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXIO.H   				*/
/*		Version :	2.1a					*/
/*		Date 	:	16/11/1992				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXIO_H		/* If not already included			*/
#define	_EXIO_H		/* Avoid multiple inclusions			*/

#include "ex.h"				/* Globale Executeur Header	*/
#include "exerrno.h"			/* Error number information	*/
#include "exctype.h"			/* Character test macros	*/
#include "exmask.h"			/* ASK Mask Value definitions	*/
#include "exfmt.h"			/* Format Codes (ABAL)		*/
#include "exmvirt.h"			/* Executeur Machine structure	*/
#include "exfile.h"			/* File acces permissions	*/
#include "experm.h"			/* ASSIGN permissions mask defs */
#include "exask.h"			/* ASK Control Variables	*/
#include "excico.h"			/* CICO Interface definition	*/
#include "extimer.h"			/* TIMER control mechanism	*/
#include "exwork.h"			/* WORK SET Description		*/

EXTERN  BPTR	fdex;			/* Current tcode offset		*/
EXTERN	EXAWORD	cur_seg;		/* Segment Index		*/
EXTERN	BPTR	GlobalDataTable;	/* Table Variables (+6)		*/
EXTERN	BPTR	GlobalDataSegment;	/* Data storage Base		*/
EXTERN	BPTR	LocalDataTable;		/* Table Variables locales	*/
EXTERN	BPTR	LocalDataSegment;	/* DATA Variables locales	*/
EXTERN	BPTR	TcodeConstants;		/* Current Constant Table 	*/
EXTERN	BPTR	GlobalConstants;	/* Global Constant Table	*/
EXTERN	BPTR	TcodeByteStack;		/* Descriptors temporaire	*/
EXTERN	struct extvform SPTR extv_base; /* External variable KEEP ZONE  */
EXTERN  BPTR	TcodeSegment;		/* T-Code Segment Base		*/
EXTERN	EXAWORD	ExQui;			/* Motor Control Flag		*/

EXTERN	EXAWORD	sicico;			/* Master executor semaphores	*/
EXTERN	EXAWORD 	syskey[9];		/* Systeme / Executeur Cursers	*/

/*	File Global Variables		*/
/*	---------------------		*/

EXTERN	struct fichdt SPTR AssignTable;	/* Table d'ASSIGN		*/
EXTERN	EX_FILE_HANDLE fidreel;
EXTERN	EXAWORD 	fidperm,lfh;

#ifdef AIX_VERS
#ifdef SPARC
EXTERN	EXAWORD	fidmc1,fidblen;
#else
EXTERN	EXAWORD	fidmc,fidblen;
#endif
#else /* AIX_VERS */
EXTERN	EXAWORD	fidmc,fidblen;
#endif /* AIX_VERS */
EXTERN	BPTR	fidbuff;
#ifdef PROLOGUE
EXTERN	EXALONG	fidseek;
#endif
EXTERN	EXAWORD 	tabflg,holdline;
EXTERN	BPTR	descptrw;
EXTERN	BPTR	workptrw;
EXTERN	BPTR	lineptr;
EXTERN	EXAWORD	workeepw,worklenw,worktypw,extwrite;
EXTERN	EXAWORD	SemaFlag;
EXTERN	EXAWORD	ExFlgSgn;

/*	Format Control Variables	*/
/*	------------------------	*/
#ifndef	ABAL_RTL
EXTERN	EXAWORD	fbcdc,fbcde,fbcdf;
EXTERN	BINAIRE	fbcdv;
EXTERN	EXABYTE	fbcdp,fbcdm,fbcdd,fbcdxe,fbcdxf,fmtmil,zpadn;
EXTERN	EXABYTE	sepdec,defmil;
EXTERN	EXAWORD	fmthex,fmtmilcount;
#endif




/*	Function Redefinitions		*/
/*	----------------------		*/

#ifdef DEBUGGER
#include "exdbcico.h"
#else
#ifndef	PROLOGUE
#define		exputch(c)	x_putch(c)
#endif
#endif

#define		MILSEP_CHK	fbcdc & 0x0200
#define		MILSEP_OFF	fbcdc &= 0xFDFF

#define		SIGN_CHK	fbcdc & 0x0100
#define		SIGN_OFF	fbcdc &= 0xFEFF

#define		SEPDEC_CHK	fbcdc & 0x1000
#define		SEPDEC_OFF	fbcdc &= 0xEFFF

#define		JUSTIF_L	fbcdc & 0x8000
#define		JUSTIF_R	fbcdc & 0x4000


#define		XCOL	1
#define		XLIN	2
#define		CONF2	3
#define		CONF1	4

#include "exlang.h"		/* National Language codes */
#include "exvtype.h"		/* Variable types 	   */

#endif	/* ! EXIOH */
