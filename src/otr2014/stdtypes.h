/* -------------------------------------------------------------------- */
/*                                                                      */
/*              Project ABAL : Macro pre-processer                      */
/*                                                                      */
/*               Copyright (c) 1990 Amenesik / Sologic s.a.                       */
/*                                                                      */
/*                                                                      */
/*              File    :       STDTYPES_H                              */
/*              Version :       1.1a                                    */
/*              Date    :       01/12/1990                              */
/*                                                                      */
/* -------------------------------------------------------------------- */
#ifndef _STDTYPES_H
#define _STDTYPES_H

#include "hosts.h"

/*      ------------------------------------------      */
/*      Global Types, Sizes and Limits Definitions      */
/*      ------------------------------------------      */ 
#ifndef BYTE
#define BYTE unsigned char
#endif

#ifndef WORD
#ifdef	otr16
#define WORD unsigned short int
#define WORD16 WORD
#endif
#ifdef	otr32
#define WORD unsigned long int
#define WORD16 unsigned short int
#endif
#ifdef	otr64
#define WORD unsigned long long
#define WORD32 unsigned long int
#define WORD16 unsigned short int
#endif
#else
#include word has been defined else where
#endif

#ifndef LONG
#define LONG unsigned long
#endif

#ifndef	HUGE
#ifdef	otr64
#define	HUGE	unsigned long long
#endif
#ifdef	otr16
#define	HUGE	LONG
#endif
#ifdef	otr32
#ifndef WIN32
#define	HUGE	unsigned long long
#else
#define	HUGE	unsigned __int64
//#define	HUGE	ULONG64
#endif
#endif
#endif

#ifdef	WIN32
#define	FAR
#else
#ifdef	UNIX
#define	FAR
#else
#define	FAR far
#endif
#endif

#ifdef  ABAL_EXA
#define XPTR FAR *      
#else
#define XPTR *
#endif

#define BPTR BYTE XPTR
#define WPTR WORD XPTR
#define LPTR LONG XPTR
#define HPTR HUGE XPTR

#ifdef	WIN32
#define	VOID void
#else
#ifdef	UNIX
#define	VOID void
#else
#ifdef MSC5
#define VOID void
#else
#define VOID BYTE
#endif
#endif
#endif

#define VPTR VOID XPTR

#define PUBLIC_SCOPE
#define PRIVATE_SCOPE   static

#ifndef VMS
#define EXTERN extern
#else
#define EXTERN extern noshare
#endif

#define VRAI            1
#define FAUX            0

#define BYTESIZE 	1
#define	WORD16SIZE	2
#define	WORD32SIZE	4
#define	WORD64SIZE	8

#ifdef	otr64
#define	WORDSIZE	WORD64SIZE
#define MOINS_UN        0xFFFFFFFFFFFFFFFFL
#else
#ifdef	otr32
#define	WORDSIZE	WORD32SIZE
#define MOINS_UN        0xFFFFFFFFL
#else
#define	MOINS_UN	0xFFFF
#define	WORDSIZE	WORD16SIZE
#endif
#endif

#endif  /* _STDTYPES_H */
	/* ----------- */

