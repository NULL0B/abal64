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


/*	------------------------------------------	*/
/*	Global Types, Sizes and Limits Definitions	*/
/*	------------------------------------------	*/ 

#define BYTE unsigned char
#ifdef	VERSION666
#ifdef ABAL64
#define EXAWORD unsigned long long int
#define WORD64 unsigned long long int
#define WORD32 unsigned long  int
#define WORD16 unsigned short int
#define LONG unsigned long
#else
#define EXAWORD unsigned long  int
#define WORD16 unsigned short int
#define LONG unsigned long
#endif
#else
#define EXAWORD unsigned short int
#define LONG unsigned long
#endif

#ifndef	UNIX
#ifdef WIN32
#define XPTR *
#define SPTR *
#else
#define XPTR far *
#define SPTR far *
#endif
#else
#define XPTR *
#define SPTR *
#endif

#define BPTR BYTE XPTR
#define WPTR EXAWORD XPTR
#define LPTR LONG XPTR

#define VOID void

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

#ifdef	VERSION666
#define	MOINS_UN16	0xFFFF
#define	MOINS_UN32	0xFFFFFFFFL
#define	MOINS_UN64	0xFFFFFFFFFFFFFFFFL
#define	MOINS_UN	MinusOne
#define	WORDSIZE	ExaWordSize 
#define	PTRSIZE	ExaPtrSize 
#define	WORDSIZE16	2
#define	WORDSIZE32	4
#define	WORDSIZE64	8
#else
#define	MOINS_UN	0xFFFF
#define	WORDSIZE	sizeof( EXAWORD )
#endif

#ifdef	VERSION666
#ifdef	_AO_C
EXAWORD	MOINS_UN=MOINS_UN16;
EXAWORD	WORDSIZE=WORDSIZE16;
#else
extern	EXAWORD	MOINS_UN;
extern	EXAWORD	WORDSIZE;
#endif
#endif


#endif	/* _STDTYPES_H */
	/* ----------- */

