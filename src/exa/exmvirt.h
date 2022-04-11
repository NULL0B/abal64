/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXVIRT.H
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */

#ifndef EXDATASEG

#ifndef FixedRegisters
EXTERN	EXAWORD (PTR Freg)[];	/* Registres de data 			*/
EXTERN	EXAWORD (PTR Xreg)[];	/* Registres de status			*/
EXTERN	EXAWORD (PTR Ireg)[];	/* Registres d'index 1er dimension	*/
EXTERN	EXAWORD (PTR Areg)[];	/* Registres d'index 2em dimension	*/
EXTERN	EXAWORD (PTR TcodeWordStack)[];	/* Integer Stack Segment Base Pointer	*/
EXTERN	EXAWORD (PTR TcodePushStack)[];	/* PushPop Stack Segment Base Pointer	*/
EXTERN	BPTR (PTR TcodePtrStack)[];	/* Pointer Stack Segment Base Pointer	*/
#else
EXTERN	EXAWORD freg[WORKSIZE];
EXTERN	EXAWORD	xreg[WORKSIZE];
EXTERN	EXAWORD	ireg[WORKSIZE];
EXTERN	EXAWORD	areg[WORKSIZE];
EXTERN	EXAWORD (PTR TcodeWordStack)[];	/* Integer Stack Segment Base Pointer	*/
EXTERN	EXAWORD (PTR TcodePushStack)[];	/* PushPop Stack Segment Base Pointer	*/
EXTERN	BPTR (PTR TcodePtrStack)[];	/* Pointer Stack Segment Base Pointer	*/
#endif

#include "exdieze.h"			/* Dieze Constants values	*/

EXTERN	EXAWORD	mindex,ip_next;


#include "exwords.h"

#else	/* EXDATASEG Defined	*/

#ifdef	VERSION_XX
#include "exvtype.h"
EXAWORD	ISLOCAL=ISLOCAL3;
EXAWORD	TOGLOBAL=TOGLOBAL3;
#endif

#ifdef	VERSION666
EXAWORD	MinusOne=MOINS_UN16;	/* 16 bit startup */
EXAWORD ExaWordSize=2;		/* 2 bytes/word   */
EXAWORD ExaPtrSize=5;		/* 5 bytes/PTR    */
#else
#define	ExaWordMask 0xFFFF
#define	ExaWordSize 2
#define	ExaPtrSize 5
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

WPTR	TcodeWordStack;		/* Integer stack pointer	*/
WPTR	TcodePushStack;		/* PushPop stack pointer	*/
BPTR	(PTR TcodePtrStack);	/* Pointer stack Pointer	*/

EXAWORD	mindex,ip_next;		/* Stack index Integer/Pointer 	*/

#else	/*	Fixed Register Declaration	*/

EXAWORD		freg[WORKSIZE];		/* Registre de data		*/
EXAWORD		xreg[WORKSIZE];		/* Registre de status		*/
EXAWORD		ireg[WORKSIZE];		/* Registre d'index		*/
EXAWORD		areg[WORKSIZE];		/* Registre d'index		*/
EXAWORD		ip_next;		/* Index of integer stack   	*/
WPTR		TcodeWordStack;		/* Integer stack pointer	*/
WPTR		TcodePushStack;		/* PushPop stack pointer	*/
BPTR		(PTR TcodePtrStack);		/* Pointer stack Pointer	*/
EXAWORD		mindex;			/* Index of pointer stack	*/
EXAWORD		worktop;		/* Current work index		*/
EXAWORD		workhold;		/* Current work protect zone	*/
EXAWORD		pushtop;		/* Current push index		*/
EXAWORD		pushhold;		/* Current push protect zone	*/

#endif
#endif
