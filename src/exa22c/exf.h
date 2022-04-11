/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1994 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXF.H  					*/
/*		Version :	2.1f					*/
/*		Date 	:	30/01/1999				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef _EXF_H
#define	_EXF_H

				/* ------------------------------------ */
#include "ex.h"			/* Standard executer Definitions	*/
#include "extcode.h"		/* T-code definition			*/
#include "exctype.h"		/* Character test functions		*/
#include "exmvirt.h"		/* Virtual machine structure		*/
#include "exvtype.h"		/* ABAL DATA TYPE definitions		*/
#include "exmacro.h"		/* ABAL check macro definitions		*/
#include "experm.h"		/* Permission d'ASSIGN			*/
#include "exerrno.h"		/* Error Code and possible values	*/
#include "exask.h"		/* ASK Control Variables		*/
#include "extmp.h"		/* Temporary work control		*/
#include "excico.h"		/* CICO interface definition		*/
#include "extimer.h"		/* TIMER control mechanism		*/
#include "exwork.h"		/* WORK SET Description			*/
				/* ------------------------------------ */
#ifndef	ABAL21
EXTERN	EXABYTE 	sepdec;
#endif

EXTERN	EXAWORD	ExaRetCode;
EXTERN	EXAWORD	syskey[9];
EXTERN	BPTR	fdex;

EXTERN	BPTR	TcodeConstants;
EXTERN	BPTR	GlobalConstants;
EXTERN	struct fusework SPTR FuseBase;

EXTERN  BPTR	LocalDataTable;
EXTERN  BPTR	GlobalDataTable;
EXTERN  BPTR	LocalDataSegment;
EXTERN  BPTR	GlobalDataSegment;
EXTERN	EXAWORD 	wwtyp,wwlen;
EXTERN	EXAWORD	datamax,datadex;
EXTERN	EXABYTE	ymtabl[12];
EXTERN	ERRORPTR	GlobalErrorTrap;
EXTERN	EXAWORD	sicico;
EXTERN	EXAWORD	CompatibleBal;
EXTERN	EX_FILE_HANDLE fidreel;
EXTERN	EXAWORD	ExFlgSgn;
EXTERN	EXAWORD	LastErreur;
EXTERN	EXAWORD	diezlds;
EXTERN	EXAWORD	procid;
EXTERN	EXAWORD	cur_seg;
#ifdef	ABAL21
EXTERN	EXAWORD	LastHandle;
#endif

#ifdef  ABAL14
EXTERN	EXALONG	SystemError;
#endif

#ifndef	UNIX
#ifndef	VMS
#define	getenv(Xarg1)	Mgetenv(Xarg1)
#endif
#endif


#ifdef	PROLOGUE
#ifdef	ABAL21
EXTERN	EXAWORD	ExaRetCode;
#endif
#define		x_npos()	npos()
#else	/* ! PRL */

#ifndef	UNIX
#ifndef VMS
#ifndef	DOS

#define		x_npos() 	0

#endif	/* ! DOS  */
#endif	/* ! VMS  */
#endif	/* ! NIX  */
#endif	/*   PRL  */


#endif	/* _EXF_H */
	/* ------ */

