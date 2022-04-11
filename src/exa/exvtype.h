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

#define	REFERENCER	12		/* Length of REFERENCE descript */

/* Variable special info */
#define	SPECIALE	0xFF00		/* Mask: Long offset variable types	*/
#define	VARB_NL		0x7F00		/* Mask: numero logique	*/

#define	ISDYNAMIC	0x8000		/* Indicates a special type	*/
#define	ISETENDU	0x4000		/* Variables dite ETENDU	*/
#define	ISMEMBER  	0x2000		/* Indicates a member type	*/
#define	ISPOINTER	0x1000		/* Indicates a pointer type	*/
#define	ISALLOC		0x1000		/* Indicates an allocated item	*/

#else
#define	SPECIALE	0x7F00		/* Checks for Extern/Etendus	*/
#define	WRITEWATCH	0x0080		/* Debug write watch flag	*/
#endif

/* Dimensions */
#define  NDX_ISOL	0x0060		/* Mask: Isolate dim */

#define	NDX1st		0x0040		/* 1st index exists    		*/
#define	NDX2nd		0x0020		/* 2nd index exists    		*/

/* Variable argument */
#define	VARB_ARG	0x0008		/* Identifies arg variables	*/

/* Variable types */
#define	VARB_ISOL	0x0007		/* Mask: Isolate Data type bits	*/

#define	VARB_INT8	0x0000		/* (A)BAL Variables #		*/
#define	VARB_INT16	0x0001		/* (A)BAL Variables %		*/
#define	VARB_BCD	0x0002		/* (A)BAL Variables Bcd		*/
#define	VARB_STR	0x0003		/* (A)BAL Variables $		*/
#define	VARB_FOUR	0x0004		/* (A)BAL Variables #		*/
#define	VARB_INT32	0x0005		/* (A)BAL Variables :		*/
#define	VARB_INT64	0x0006		/* (A)BAL Variables &		*/

#define VARB_INT(t) ((t == VARB_INT8) || (t == VARB_INT16) || (t == VARB_INT32) || (t == VARB_INT64))

#endif



