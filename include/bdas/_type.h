/*
 *	Definitions communes
 *	--------------------
 *
 *	Copyright (c) 1990 Prologue s.a.
 *
 *	type.h - definitions des types de variables
 *
 *	$Header: /home/Produits/Abal3/include/bdas/_type.h,v 1.1.1.1 2003/11/27 09:42:07 jamie Exp $
 *
 */


/*
 *	octet non signe
 *	---------------
 */

#ifndef	_type_h
#define	_type_h

#ifndef _BYTE_DEFINED

#ifdef byte
#undef byte
#endif /* byte */

#ifndef RT_AIX
typedef unsigned char byte;
#else
#define byte unsigned char
#endif

#define _BYTE_DEFINED
#endif /* _BYTE_DEFINED */

#ifdef BYTE
#undef BYTE
#endif /* BYTE */

#define BYTE unsigned char


#ifdef CHAR
#undef CHAR
#endif /* CHAR */

#define CHAR char 
#ifdef VOID
#undef  VOID
#endif /*  VOID */

#define  VOID void 

#ifdef BOOL
#undef BOOL
#endif /* BOOOOOOOL y en a marre */

#define BOOL int

#ifdef NULL
#undef NULL
#endif /* c'est vraiment NUUULLLL  */

#define NULL 0

/*
 *	mot de 16 bits non signe
 *	------------------------
 */
#ifdef	VERSION666
#define	EXAWORD unsigned long int
#else
#define	EXAWORD unsigned short int
#endif

#ifndef _WORD_DEFINED

#ifdef word
#undef word
#endif /* word */

typedef unsigned short word;

#define _WORD_DEFINED
#endif /* _WORD_DEFINED */

#ifdef WORD
#undef WORD
#endif /* WORD */

#define WORD unsigned short 

#ifdef SWORD
#undef SWORD
#endif /* SWORD */

#define SWORD short 

#ifdef LONG
#undef LONG
#endif /* LONG */

#define LONG long

#ifdef HUGE
#undef HUGE
#endif /* HUGE */

#define HUGE long long
 
/*
 *	mot de 32 bits non signe
 *	------------------------
 */

#ifndef _DWORD_DEFINED

#ifdef dword
#undef dword
#endif /* dword */

typedef unsigned long dword;

#define _DWORD_DEFINED
#endif /* _DWORD_DEFINED */


/*
 *	booleen
 *	-------
 */

#ifndef _BOOL_DEFINED

#ifdef bool
#undef bool
#endif /* bool */

#ifdef FALSE
#undef FALSE
#endif /* FALSE */

#ifdef TRUE
#undef TRUE
#endif /* TRUE */

#ifdef _NO_ENUM

#define FALSE	0
#define TRUE	1
typedef int bool;

#else

typedef enum {FALSE, TRUE} bool;	/* booleen			*/

#endif /* _NO_ENUM */

#define _BOOL_DEFINED
#endif /* _BOOL_DEFINED */


/*
 *	modificateur d'allocation
 *	-------------------------
 */

#ifndef _FAR_DEFINED

#ifndef FAR

#if M_I8086 || M_I186 || M_I286
#define FAR far
#else
#define FAR
#endif /* M_I8086 || M_I186 || M_I286 */

#endif /* FAR */

#define _FAR_DEFINED
#endif /* _FAR_DEFINED */

#ifndef	PTR
#define	PTR *
#endif

#ifndef	GN
#define GN(a) (a *) 0
#endif

/* fin de fichier */

#endif /* _type_h */


