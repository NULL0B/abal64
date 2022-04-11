/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : Tous
 *	Fichier : WABALDEF.H
 *	Version : 1.1a
 *	Date    : 15/07/93
 *	Systeme : Tous
 *
 *	Definitions a inclure dans tous les sources ABAL
 *
 *	[Definitions]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	03/12/92 : Debut du codage
 *
 */

/*JPH #define __PORTABLE__*/

#ifndef __ABALDEF_H__
#define __ABALDEF_H__


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DEFINITION GENERALES DE TYPES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define PRIMITIVE	extern
#define GLOBAL
#define PRIVATE		static


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DEFINITION POUR LES MODULES PORTABLES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
//SAP{
//ifdef _DOS
#if (defined(_DOS) || defined(PRL))
#define __PORTABLE__ 
#endif
//}SAP

#ifdef __PORTABLE__

#include <stdio.h>
#include <malloc.h>

#ifdef unix
#define FAR
#else
#ifdef WIN32
#define FAR
#else
#define FAR	far
#endif
#endif
#define TRUE	1
#define FALSE	0
#define SIGNEDVALUE signed

typedef SIGNEDVALUE short int SWORD;
typedef unsigned short int WORD;
typedef unsigned char BYTE;
typedef int BOOL;

#else   /* __PORTABLE */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DEFINITION POUR LES MODULES WINDOWS DEPENDANT		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
#ifdef __WINDOWS_SOURCE__

#include <windows.h>
#include <windowsx.h>
#include <malloc.h>
#include <string.h>

#define SIGNEDVALUE signed

typedef SIGNEDVALUE short int SWORD;
typedef LRESULT (FAR * MSGFCT)( HWND,UINT,WPARAM,LPARAM );
typedef BOOL (FAR * DLGFCT)( WORD,HWND,UINT,WPARAM,LPARAM );

#endif /* __WINDOWS_SOURCE__ */

#endif /* __PORTABLE__ */


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		MACROS ENGLOBANT DES APPELS DE FONCTIONS		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef __PORTABLE__

// YT : set ptmalloc in global to avoid redefinition
// ptmalloc is defined in lkmain.c
extern void * ptmalloc;
#ifdef __MALLOC
#include "lkdebug.h"
#define Xmalloc(x)		(((ptmalloc = (void FAR *) dbgalloc("",x)) == NULL) ? (void FAR *)NULL : (void FAR *)ptmalloc)
#define Xfree(x)		dbgfree(x)
#else
#define Xmalloc(x)		(((ptmalloc = (void FAR *) malloc(x)) == NULL) ? (void FAR *)NULL : (void FAR *)ptmalloc)
#define Xfree(x)		free(x)
#endif
#else  /* __PORTABLE__ */

#ifdef __WINDOWS_SOURCE__ 

void FAR * wmalloc(WORD);
void wfree(void FAR *);
SWORD wmalloc_state(void);
void wfree_all(void);

// YT : temporary 
//#define Xmalloc(x)		wmalloc(x)
//#define Xfree(x)		wfree(x)
#define Xmalloc(x)		malloc(x)
#define Xfree(x)		free(x)
#define Xmemstat()		wmalloc_state()
#define Xfreeall()		wfree_all()
#define ZFmemcpy(x,y,z)		_fmemmove((LPSTR)x,(LPSTR)y,z)

#endif	/* __WINDOWS_SOURCE__ */
#endif  /* __PORTABLE */

#define NOEFFECT	((void)0)


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		INCLUSION DES DEFINITIONS OBJET				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#include "pubexcep.h"
#include "wabalobj.h"

#endif	/* __ABALDEF_H__ */



