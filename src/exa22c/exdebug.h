/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDEBUG - H				*/
/*		Version :	1.4c / 2.1a				*/
/*		Date 	:	12/11/1992				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	EXDEBUGH
#define	EXDEBUGH

#ifdef DEBUGGER
#include "ex.h"
#endif

#include "exask.h"		/* ASK Control Variables		*/
#include "extmp.h"		/* Temporary descriptor allocation	*/
#include "excico.h"		/* CICO interface definition		*/
#include "extimer.h"		/* TIMER control mechanism		*/
#include "exwork.h"		/* WORK SET Description			*/
#include "exdieze.h"		/* Dieze Constants values		*/

EXTERN	EXAWORD	err_reg, err_adr, err_ret;
EXTERN	EXAWORD 	err_ind, err_and;
EXTERN	ERRORPTR	GlobalErrorTrap;
EXTERN	BPTR	lineptr;
EXTERN	EXABYTE	err_flg, dbg_flg;
EXTERN	EXAWORD	segstop;
EXTERN	EXAWORD	ip_next, mindex;

EXTERN	BPTR	TalkPtr[];		/* Message String Pointers	*/
EXTERN	EXABYTE	trad_ver;		/* AT Traductor Version Flag	*/


EXTERN	EXAWORD	(*smach [16]) (); 

EXTERN 	EXAWORD sicico,procmaxid;

#include "exmvirt.h"

EXTERN 	EXAWORD 	var_glob;
EXTERN	EXAWORD	var_locl;
EXTERN	EXAWORD	cur_seg;
EXTERN  EXAWORD	piege;

EXTERN	BPTR	TcodeSegmentTable;
EXTERN 	BPTR	TcodeSegment;
EXTERN	BPTR	fdex;
EXTERN	BPTR	GlobalDataSegment;
EXTERN	BPTR	GlobalDataTable;
EXTERN	BPTR	LocalDataSegment;
EXTERN	BPTR	LocalDataTable;
EXTERN 	BPTR  	GlobalNamesTable;
EXTERN	BPTR	LocalNamesTable;
EXTERN  BPTR	TcodeConstants;
EXTERN	BPTR	GlobalConstants;
EXTERN	struct procform SPTR TcodeProcTable;
EXTERN	EXAWORD	chain;
EXTERN	BPTR	workptrw;
EXTERN	EXAWORD	worklenw,worktypw,workeepw,extwrite;
EXTERN	BPTR	descptrw;

#define POINTER sizeof(BPTR)

EXTERN	EXAWORD	procid;
EXTERN	EXAWORD	eventadr;

/*	Moniteur Semaphores 	*/
/*	-------------------	*/
#define	DBONSEM_KOD	0x0040
#define	DBONSEM_QAN	0x0020
#define	DBONSEM_ERR	0x0010
#define	DBONSEM_KEY	0x0008
#define	DBONSEM_TRP	0x0004
#define	DBONSEM_TRC	0x0001

#define	DBOFSEM_KOD	0xFFBF
#define	DBOFSEM_QAN	0xFFDF
#define	DBOFSEM_ERR	0xFFEF
#define	DBOFSEM_KEY	0xFFF7
#define	DBOFSEM_TRP	0xFFFB
#define	DBOFSEM_TRC	0xFFFE


EXTERN	EX_FILE_HANDLE fidreel;
#ifdef AIX_VERS
#ifdef SPARC
EXTERN	EXAWORD 	fidperm,fidblen,fidbd,fidmc1;
#else
EXTERN	EXAWORD 	fidperm,fidblen,fidbd,fidmc;
#endif
#else /* AIX_VERS */
EXTERN EXAWORD fidperm,fidblen,fidbd,fidmc;
#endif /* AIX_VERS */
EXTERN	BPTR	fidname,fidbuff,fidbase;
EXTERN	EXAWORD	lfh;
EXTERN	EX_FILE_HANDLE dbreel;
EXTERN	EXAWORD	syskey[9];
EXTERN	EXAWORD	keepvlen;
EXTERN	BPTR	keepvptr;
EXTERN	EXALONG	keepvofs;
EXTERN	EXAWORD	ExFlgSgn;
EXTERN	EXAWORD	worktyp2;
EXTERN	BINAIRE	workval2;

#include "exvtype.h"
#include "exmacro.h"

EXTERN	EXAWORD	lreg[64];
EXTERN	BPTR	preg[64];

EXAWORD	PushZone();
EXAWORD	PushInfo();
EXAWORD	VerifPtr();
#ifdef CHECK_PROTO_ARGS
BPTR	CmdShift( BPTR );
BPTR	CurrentSegmentPointer( EXAWORD );
#else
BPTR	CmdShift();
BPTR	CurrentSegmentPointer();
#endif

#ifdef DEBUGGER
#define	x_getch() db_xgetch()
#endif

#endif	/* ! EXDEBUGH */
	/* ---------- */
