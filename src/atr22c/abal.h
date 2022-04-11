/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 2002
 *      Module  : ATR
 *      Fichier : ABAL.HS
 *      Version : 2.2b
 *      Date    : 06/11/02
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions de l'analyseur lexical]
 *
 */

/*
 * Mises a jour :
 *	------------ 2.2b -------------------------------------------------
 */

#ifndef	_abal_h
#define	_abal_h

#define	VTYPE_ISOL	0x0003

#define	VTYPE_BYTE		0
#define	VTYPE_WORD		1
#define	VTYPE_BCD		2
#define	VTYPE_STRING	3

#define	PRIMARY_INDEX	0x0040
#define	SECOND_INDEX	0x0020

#ifdef	VERSION_XX

#define	IS_EXTERN		0xC000
#define	IS_LOCAL3		0x8000
#define	TO_GLOBAL3		0x7FFF
#define	IS_LOCAL4		0x0001
#define	TO_GLOBAL4		0xFFFE

#ifdef	_gestfic_c
unsigned short int is_local = IS_LOCAL3;
unsigned short int to_global = TO_GLOBAL3;
#else
extern	unsigned short int is_local;
extern	unsigned short int to_global;
#endif

#define	ISLOCAL		is_local
#define	TOGLOBAL		to_global

#else		// VERSION_XX

#define	IS_EXTERN	0xC000
#define	ISLOCAL		0x8000
#define	TOGLOBAL		0x7FFF

#endif	// VERSION_XX

#endif	/* _abal_h */

