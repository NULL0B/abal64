/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMOTOR - H				*/
/*		Version	:	1.4a / 2.1a				*/
/*		Date 	:	12/11/1992				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXMOTOR_H
#define _EXMOTOR_H

#include "ex.h"			/* General executeur definitions	*/
#include "exask.h"		/* ASK Control Variables		*/
#include "excico.h"		/* CICO interface definition		*/
#include "extmp.h"		/* Temporary descriptor allocation	*/
#include "extimer.h"		/* TIMER control mechanism		*/
#include "exwork.h"		/* WORK SET Description			*/
#include "exdieze.h"		/* Dieze Constants values		*/

#define	code_secteur 0x0002
#define	code_length  0x0004
#define varl_secteur 0x0006
#define varl_length  0x0008
#define code_pointer 0x000A
#define errg_pointer 0x000C
#define errg_descrip 0x000E
#define base_varltab 0x0010
#define base_varlmem 0x0014

EXTERN BPTR	fdex;			/* T-code buffer pointer    	*/
EXTERN EX_FILE_HANDLE TcodeFileHandle;	/* Numero logique du fichier T	*/
EXTERN EXAWORD  	MaxOverlayCode;		/* Longeur max segments		*/
EXTERN BPTR 	descptr;
EXTERN EXAWORD	procid;

#include "exmvirt.h"

EXTERN	BPTR lineptr;
EXTERN	BPTR TcodeConstants;
EXTERN	BPTR GlobalConstants;
EXTERN	BPTR LocalDataTable;
EXTERN	BPTR GlobalDataTable;
EXTERN	BPTR LocalDataSegment;
EXTERN	BPTR data_varg;
EXTERN	BPTR GlobalDataSegment;
EXTERN	struct segmform PTR TcodeSegmentTable;
EXTERN	ERRORPTR GlobalErrorTrap;
EXTERN	BPTR TcodeSegment;
EXTERN	struct procform PTR TcodeProcTable;
EXTERN 	EXAWORD cur_seg;
EXTERN	EXAWORD (*smach[16]) ();	
EXTERN	EXAWORD	wwtyp,wwlen;
EXTERN	BPTR	descptrw;
EXTERN	BPTR	workptrw;
EXTERN	EXAWORD	worktypw,worklenw,extwrite,workeepw;

#ifndef LINEAR_MEM
EXTERN	BPTR	keepvptr;
EXTERN	EXAWORD	keepvlen;
EXTERN	long	keepvofs;
#endif

EXTERN	EXAWORD	datamax,datadex,datapnt;
EXTERN	BPTR	datawork;
EXTERN	EXAWORD	chain;
EXTERN	EXAWORD	loadgo;
EXTERN	BPTR	chptr;
EXTERN	EXAWORD	sicico;
EXTERN	long	bigvofs;
EXTERN	BPTR	bigbase;
EXTERN	EXAWORD	bigvlen;
EXTERN	EXAWORD	ExFlgSgn;
EXTERN	EXAWORD	StackHold;

/*	EVENT Management	*/
/* 	----------------	*/

EXTERN	EXAWORD	eventadr;	/* Adresse de traitement d'evenment	*/
#ifdef MODEL_DBGT
EXTERN	EXAWORD	ritewatch;
#endif

#include "exvtype.h"		/* Variable types etc... */

#include "exmacro.h"		/* Check macros		 */

EXTERN	EXAWORD	lreg[64];
EXTERN	BPTR	preg[64];

#ifdef	ABAL21
#ifdef	UNIX
EXTERN	EXAWORD	pushtop;
EXTERN	EXAWORD	pushhold;
#endif
#ifdef	WIN32
EXTERN	EXAWORD	pushtop;
EXTERN	EXAWORD	pushhold;
#endif
#endif

	/* ---------- */
#endif	/* _EXMOTOR_H */
	/* ---------- */
