/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990 Amenesik Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	STDTYPES_H				*/
/*		Version :	1.1a					*/
/*		Date	:	01/12/1990				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_STDTYPES_H
#define	_STDTYPES_H

/*	------------------------------------------	*/
/*	Global Types, Sizes and Limits Definitions	*/
/*	------------------------------------------	*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef	BYTE
#define BYTE unsigned char
#endif

#ifndef	WORD
#define WORD unsigned short int
#endif

#ifndef	LONG
#define LONG unsigned long
#endif

#ifdef	ABAL_EXA
#ifdef  UNIX
#define	XPTR *	
#else
#define	XPTR far *
#endif
#else
#define XPTR *
#endif

#define BPTR BYTE XPTR
#define WPTR WORD XPTR
#define LPTR LONG XPTR

#ifdef MSC5
#define VOID void
#else
#define VOID void
#endif

#define VPTR VOID XPTR

#define	PUBLIC_SCOPE
#define	PRIVATE_SCOPE	static

#ifndef	VMS
#define	EXTERN extern
#else
#define	EXTERN extern noshare
#endif

#define	VRAI		1
#define	FAUX		0

#ifndef	MOINS_UN
#ifdef	VERSION666
#define	MOINS_UN	0xFFFFFFFFL
#else
#define	MOINS_UN	0xFFFF
#endif 
#endif

#ifndef	EXAWORD
#ifdef	VERSION666
#define	EXAWORD	LONG
#else
#define	EXAWORD	WORD
#endif
#endif

#ifndef	EXABYTE
#define	EXABYTE	BYTE
#endif

#ifndef	EXALONG
#define	EXALONG	LONG
#endif


#endif	/* _STDTYPES_H */
	/* ----------- */

