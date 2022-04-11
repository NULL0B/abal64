/*
 *	Definitions communes
 *	--------------------
 *
 *	Copyright (c) 1990 Amenesik Sologic s.a.
 *
 *	type.h - definitions des types de variables
 *
 *	$Header: /home/Produits/Abal3/include/_type.h,v 1.1.1.1 2003/11/27 09:42:07 jamie Exp $
 *
 */


/*
 *	octet non signe
 *	---------------
 */

#ifndef	__type_h
#define	__type_h




#ifndef _BYTE_DEFINED

#ifndef byte

#ifndef RT_AIX
typedef unsigned char byte;
#else
#define byte unsigned char
#endif

#endif /* byte */

#define _BYTE_DEFINED
#endif /* _BYTE_DEFINED */

#ifndef BYTE
#define BYTE unsigned char
#endif /* BYTE */


#ifndef CHAR
#define CHAR char 
#endif /* CHAR */

#ifndef VOID
#define  VOID void 
#endif /*  VOID */

#ifndef BOOL
#define BOOL int
#endif 

#ifndef NULL
#define NULL 0
#endif 

/*
 *	mot de 16 bits non signe
 *	------------------------
 */

#ifndef _WORD_DEFINED

#ifndef word
#ifdef	VERSION666
typedef unsigned long word;
#else
typedef unsigned short word;
#endif
#endif /* word */

#define _WORD_DEFINED
#endif /* _WORD_DEFINED */

#ifndef WORD
#ifdef	VERSION666
typedef unsigned long WORD;
#else  
typedef unsigned short WORD;
#endif
#endif

#ifndef SWORD
#define SWORD short 
#endif /* SWORD */

#ifndef LONG
#define LONG long
#endif /* LONG */
 
/*
 *	mot de 32 bits non signe
 *	------------------------
 */

#ifndef _DWORD_DEFINED

#ifndef dword
typedef unsigned long dword;
#endif /* dword */

#define _DWORD_DEFINED
#endif /* _DWORD_DEFINED */


/*
 *	booleen
 *	-------
 */

#ifndef _BOOL_DEFINED

#ifndef bool

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

#endif /* bool */

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
#endif /* __type_h */


