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

#define MSC5
/*	------------------------------------------	*/
/*	Global Types, Sizes and Limits Definitions	*/
/*	------------------------------------------	*/ 

#define BYTE unsigned char
#ifdef	VERSION666
#define WORD unsigned int
#else
#define WORD unsigned short int
#endif
#define LONG unsigned long
#define SWORD short int 
#define MOINS_UN 0xffff
#define XPTR *
#if unix || vms
#define FPTR XPTR
#else
#define FPTR far XPTR
#endif
#define BPTR BYTE FPTR
#define WPTR WORD XPTR
#define LPTR LONG XPTR

#ifdef MSC5
#define VOID void
#else
#define VOID BYTE
#endif

#define VPTR VOID XPTR

#define	PUBLIC_SCOPE
#define	PRIVATE_SCOPE	static

#ifndef	VMS
#define	EXTERN extern
#else
#define	EXTERN extern noshare
#endif

#endif	/* _STDTYPES_H */
	/* ----------- */




