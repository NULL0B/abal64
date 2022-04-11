/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : Tous
 *	Fichier : WABALDEF.H
 *	Version : 1.1a
 *	Date    : 12/08/93
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

#ifndef __ABALDEF_H__
#define __ABALDEF_H__


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DEFINITION GENERALES DE TYPES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define PRIMITIVE	extern
#define GLOBAL
#define PRIVATE		static

#ifdef WIN32
#define NOTFASTCALL
#define SAVEREGS
#else
#define NOTFASTCALL __cdecl
#define SAVEREGS __saveregs
#endif


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DEFINITION POUR LES MODULES PORTABLES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
#ifdef __PORTABLE__

#include <stdio.h>
#include <malloc.h>

#ifdef WIN32
#define FAR
#else
#define FAR	far
#endif

#define LINT_ARGS			/* controle des arguments */

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

void FAR * wmalloc(WORD);
void wfree(void FAR *);
SWORD wmalloc_state(void);
void wfree_all(void);          

#define Xmalloc(x)		wmalloc(x)
#define Xfree(x)		wfree(x)
#define Xmemstat()		wmalloc_state()
#define Xfreeall()		wfree_all()
#define ZFmemcpy(x,y,z)		_fmemmove((LPSTR)x,(LPSTR)y,z)

#define NOEFFECT	((void)0)


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		INCLUSION DES DEFINITIONS OBJET				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#include "pubexcep.h"
#include "wabalobj.h"

#endif	/* __ABALDEF_H__ */
