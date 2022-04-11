/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXVTYPE.H
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */

/*
 * Mises a jour :
 * ------------
 *	------------ 2.2b -------------------------------------------------
 */

#ifndef _EXVTYPE_H			/* If not already defined	*/
#define _EXVTYPE_H			/* Avoid Redefinitions		*/

/*	General Error Return Values	*/
/*	---------------------------	*/

#define	SOFTERROR	0		/* Soft (trapable) Errors	*/
#define	HARDERROR	MOINS_UN	/* Untrapable errors		*/
#define	GOODRESULT	1		/* Operation terminated well	*/

/*	Register contents types		*/
/*	-----------------------		*/

#define	IMMEDIAT	0		/* Immediate integer 16 bits	*/
#define KONSTANT	1		/* Constant pointer		*/
#define	VARIABLE	2		/* Variable identifier		*/
#define	TEMPDESC	3		/* Temporary descriptor		*/
#define	CHARONLY	4		/* Special flag for # varbs 	*/

#define	PTRSTATUS	0x0800
#define	PTRBCD		0x0802
#define	PTRSTR		0x0803

/*	-------------------------	*/
/*	Variable types bit fields	*/
/*	-------------------------	*/
#ifdef	VERSION_XX
#define	ISLOCAL3	0x8000		/* Checks for local variables	*/
#define	TOGLOBAL3	0x7FFF		/* Converts to valid offset	*/
#define	ISLOCAL4	0x0001		/* Checks for local variables	*/
#define	TOGLOBAL4	0xFFFFFFFE	/* Converts to valid offset	*/
#define	ISLOCAL		IsLocal		/* Checks for local variables	*/
#define	TOGLOBAL	ToGlobal	/* Converts to valid offset	*/
#else
#define	ISLOCAL		0x8000		/* Checks for local variables	*/
#define	TOGLOBAL	0x7FFF		/* Converts to valid offset	*/
#endif
#ifdef	ABAL21
/* 	--------------------------------- 	*/
/* 	Pointer and Referencing Constants 	*/
/* 	--------------------------------- 	*/
#define	SPECIALE	0xFF00		/* Long offset variable types	*/
#define	ISDYNAMIC	0x8000		/* Indicates a special type	*/
#define	ISMEMBER  	0x2000		/* Indicates a member type	*/
#define	ISPOINTER	0x1000		/* Indicates a pointer type	*/
#define	ISALLOC		0x1000		/* Indicates an allocated item	*/
#define	REFERENCER	12		/* Length of REFERENCE descript */

#else
#define	SPECIALE	0x7F00		/* Checks for Extern/Etendus	*/
#define	WRITEWATCH	0x0080		/* Debug write watch flag	*/
#endif

#define	ISETENDU	0x4000		/* Variables dite ETENDU	*/
#define	VARB_ISOL	0x0007		/* Isolate Data type bits	*/
#define	VARB_ARG	0x0008		/* Identifies arg variables	*/
#define	NDX1st		0x0040		/* 1st index exists    		*/
#define	NDX2nd		0x0020		/* 2nd index exists    		*/
#define	VARB_INT8	0		/* (A)BAL Variables #		*/
#define	VARB_INT16	1		/* (A)BAL Variables %		*/
#define	VARB_BCD	2		/* (A)BAL Variables Bcd		*/
#define	VARB_STR	3		/* (A)BAL Variables $		*/
#define	VARB_FOUR	4		/* (A)BAL Variables #		*/
#define	VARB_INT32	5		/* (A)BAL Variables %%		*/

#endif



