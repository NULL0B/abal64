/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987, 1992  Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMVIRT.H				*/
/*		Version :	2.1a					*/
/*		Date 	:	12/11/1992				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef EXDATASEG

#ifndef FixedRegisters
EXTERN	EXAWORD (SPTR Freg)[];	/* Registres de data 			*/
EXTERN	EXAWORD (SPTR Xreg)[];	/* Registres de status			*/
EXTERN	EXAWORD (SPTR Ireg)[];	/* Registres d'index 1er dimension	*/
EXTERN	EXAWORD (SPTR Areg)[];	/* Registres d'index 2em dimension	*/
EXTERN	EXAWORD (SPTR IP_Hold)[];	/* Integer Stack Segment Base Pointer	*/
EXTERN	EXAWORD (SPTR SP_Hold)[];	/* PushPop Stack Segment Base Pointer	*/
EXTERN	BPTR (SPTR Minder)[];	/* Pointer Stack Segment Base Pointer	*/
#else
EXTERN	EXAWORD freg[WORKSIZE],xreg[WORKSIZE],ireg[WORKSIZE],areg[WORKSIZE];
EXTERN	EXAWORD (SPTR IP_Hold)[];	/* Integer Stack Segment Base Pointer	*/
EXTERN	EXAWORD (SPTR SP_Hold)[];	/* PushPop Stack Segment Base Pointer	*/
EXTERN	BPTR (SPTR Minder)[];	/* Pointer Stack Segment Base Pointer	*/
#endif

#include "exdieze.h"			/* Dieze Constants values	*/

EXTERN	EXAWORD	mindex,ip_next;

#ifdef	VERSION_XX
#include "exvtype.h"
EXTERN	EXAWORD	ISLOCAL;
EXTERN	EXAWORD	TOGLOBAL;
#endif

#else	/* EXDATASEG Defined	*/

#ifdef	VERSION_XX
#include "exvtype.h"
EXAWORD	ISLOCAL=ISLOCAL3;
EXAWORD	TOGLOBAL=TOGLOBAL3;
#endif

#ifndef	FixedRegisters	/* If Variable Worksize	*/

WPTR	Freg;			/* Registre d'index 1er Dimens  */
WPTR	Ireg;			/* Registre d'index 1er Dimens  */
WPTR	Areg;			/* Registre d'index 1er Dimens  */
WPTR	Xreg;			/* Registre d'index 1er Dimens  */

EXAWORD	worktop = 0;		/* Next free space pointer	*/
EXAWORD	workhold = 0;		/* Current base limit		*/

EXAWORD	pushtop = 0;
EXAWORD	pushhold = 0;

WPTR	IP_Hold;		/* Integer stack pointer	*/
WPTR	SP_Hold;		/* PushPop stack pointer	*/
BPTR	(SPTR Minder);	/* Pointer stack Pointer	*/

EXAWORD	mindex,ip_next;		/* Stack index Integer/Pointer 	*/

#else	/*	Fixed Register Declaration	*/

EXAWORD		freg[WORKSIZE];		/* Registre de data		*/
EXAWORD		xreg[WORKSIZE];		/* Registre de status		*/
EXAWORD		ireg[WORKSIZE];		/* Registre d'index		*/
EXAWORD		areg[WORKSIZE];		/* Registre d'index		*/
EXAWORD		ip_next;		/* Index of integer stack   	*/
WPTR		IP_Hold;		/* Integer stack pointer	*/
WPTR		SP_Hold;		/* PushPop stack pointer	*/
BPTR		(SPTR Minder);		/* Pointer stack Pointer	*/
EXAWORD		mindex;			/* Index of pointer stack	*/
EXAWORD		worktop;		/* Current work index		*/
EXAWORD		workhold;		/* Current work protect zone	*/
EXAWORD		pushtop;		/* Current push index		*/
EXAWORD		pushhold;		/* Current push protect zone	*/

#endif
#endif
