/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXCODE.H  				*/
/*		Version	:	1.4a / 2.1a				*/
/*		Date 	:	15/04/1993				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXCODE_H		/* if not already included		*/
#define	_EXCODE_H		/* Avoid multiple inclusions		*/

#include "ex.h"			/* General Executeur Header		*/
#include "exmvirt.h"		/* Virtual Machine definitions		*/
#include "excico.h"		/* CICO interface definition		*/
#include "extimer.h"		/* TIMER control mechanism		*/
#include "extmp.h"		/* Temporary descriptor allocation	*/
#include "exwork.h"		/* WORK SET Description			*/
#include "exovl.h"		/* Overlay control mechanisms		*/

#define	dbg_flg		((trad_opt & 1) == 1)

/*
 *	Declarations des Elements EXTERNES
 *	----------------------------------
 */

EXTERN	EXAWORD	sicico;
EXTERN	EXAWORD	eventadr;

 
/*	Standard T-Code Structure manipulation variables		*/
/*	------------------------------------------------		*/
EXTERN	BPTR	fdex;
EXTERN	BPTR	TcodeSegment;
EXTERN	BPTR	TcodeConstants;
EXTERN	BPTR	GlobalConstants;
EXTERN	BPTR	GlobalDataTable;
EXTERN	BPTR	GlobalDataSegment;
EXTERN	BPTR	LocalDataSegment;
EXTERN	BPTR	LocalDataTable;
EXTERN	BPTR	LocalNamesTable;
EXTERN	struct segmform SPTR TcodeSegmentTable;
EXTERN	struct procform SPTR TcodeProcTable;
EXTERN	ERRORPTR	GlobalErrorTrap;

#ifndef LINEAR_MEM
EXTERN	BPTR	keepvptr;
EXTERN	EXAWORD	keepvlen;
EXTERN	long	keepvofs;
#endif

EXTERN	EXAWORD	StackHold;
EXTERN	EXAWORD	pushtop;
EXTERN	EXAWORD	pushhold;

EXTERN	EXAWORD	datapnt,datamax,datadex;
EXTERN	EX_FILE_HANDLE TcodeFileHandle;
EXTERN	EXAWORD	cur_seg,MaxOverlayCode;
EXTERN	BPTR	segdata;
EXTERN	EXAWORD	SegmentCount;
EXTERN	EXAWORD	l_max_vls,segstop;
EXTERN	EXABYTE	trad_opt;

#ifdef LINEAR_MEM
EXTERN	BPTR	ExtendedMemory;
#endif


EXTERN	EXAWORD	lng_tpr,adr_tpr;
EXTERN	EX_FILE_HANDLE TcodeFileHandle;
EXTERN	EXAWORD	datapnt,datadex,datamax;

EXTERN	BPTR	init_data();
EXTERN	EXAWORD	procid,procmaxid;
EXTERN	EXAWORD	extwrite;
EXTERN	EXAWORD	ProcSwap;
EXTERN	EX_FILE_HANDLE fidreel;
EXTERN	EXAWORD	lfh;
EXTERN	BPTR	fidname;

#include "exvtype.h"		/* DATA types definitions */

EXTERN	EXAWORD	lreg[64];
EXTERN	BPTR	preg[64];

#ifdef	VMS_OPTIMISED
EXTERN	EXAWORD	UseVmsSection;
#endif

#ifdef	ABAL21
EXTERN	EXAWORD	HardEvent;
#endif

#define	SEGM_TABLE_AK	12
#define SEGM_TABLE_LK	14
#define SEGM_TABLE_OP	10


#endif	/* _EXCODE_H */
	/* --------- */
