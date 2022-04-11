/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	STDTYPES_H				*/
/*		Version :	1.1a					*/
/*		Date	:	01/12/1990				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_STDTYPES_H
#define	_STDTYPES_H

#include "hosts.h"

/*	------------------------------------------	*/
/*	Global Types, Sizes and Limits Definitions	*/
/*	------------------------------------------	*/ 
#ifndef	BYTE
#define BYTE unsigned char
#endif

#ifndef	WORD
#define WORD unsigned short int
#endif

#ifndef	LONG
#define LONG unsigned long
#endif

#ifdef	DOS
#ifndef	FAR
#define FAR far
#endif
#endif

#ifdef	ABAL_EXA
#define	XPTR far *	
#else
#define XPTR *
#endif

#define BPTR BYTE XPTR
#define WPTR WORD XPTR
#define LPTR LONG XPTR

#ifdef MSC5
#define VOID void
#else
#ifdef MSC7
#define VOID void
#else
#define VOID BYTE
#endif
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
#define	MOINS_UN	0xFFFF

#endif	/* _STDTYPES_H */
	/* ----------- */

