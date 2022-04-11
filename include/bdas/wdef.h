/*
 *	Projet  : ABAL			Copyright Prologue s.a. (c) 1992, 2000
 *	Module  : bibliothèque dynamique pour WEXA
 *	Fichier : WDEF.H
 *	Version : 2.00
 *	Date    : 20/04/2000
 *	Systeme : Windows 3/95/98/NT/2000
 *
 *	Definitions a inclure dans tous les sources ABAL de BDA
 *
 *	[Definitions]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	20/04/2000 : mise à jour v2.00
 *	28/11/2000 : mise à jour v2.01 FCH ajout compatibilité Twin16
 */

#ifndef __ABALDEF_H__
#define __ABALDEF_H__

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//    Compiler identification
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#undef BDA_VC
#undef BDA_VC152
#undef BDA_VC42
#undef BDA_VC6
#undef BDA_BORLAND

#if defined(_MSC_VER)
	// Compilateurs Microsoft
	#define BDA_VC

	#if   _MSC_VER == 800
		#pragma message("PROLOGUE MSG: compilateur VC1.52")
		#define BDA_VC152
	#elif _MSC_VER == 1000
		#pragma message("PROLOGUE MSG: compilateur VC4.2")
		#define BDA_VC42
	#elif _MSC_VER == 1200
		#pragma message("PROLOGUE MSG: compilateur VC6.0")
		#define BDA_VC6
	#else
		#pragma message("PROLOGUE WARNING: compilateur VC non référencé")
	#endif

#elif defined(__BORLANDC__)
	// Compilateurs Borland
	#pragma message("PROLOGUE MSG: compilateur BORLAND")
	#define BDA_BORLAND

#else
#ifndef	UNIX
	// Autre Compilateurs
	#pragma message("PROLOGUE WARNING: compilateur non référencé")
#endif
#endif

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//    OS Identification
//      Notes for Windows and VC:
//        WINVER, _WIN32_WINDOWS et _WIN32_IE 
//        peuvent être utilisés pour différencier W95, W98, WNT4, W2000 
//        (voir MSDN)
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#undef	BDA_WIN16
#undef	BDA_WIN32
#undef	BDA_UNIX
#undef	BDA_VMS
#undef	BDA_TWIN32
#undef	BDA_TWIN16

#if defined(unix)
#ifndef	UNIX
	#pragma message("PROLOGUE MSG: Unix")
#endif
	#define BDA_UNIX
#elif defined(UNIX)
	#pragma message("PROLOGUE MSG: Unix")
	#define BDA_UNIX
#elif defined(vms)
	#pragma message("PROLOGUE MSG: VMS")
	#define BDA_VMS

#elif defined(__Prl)
	#pragma message("PROLOGUE MSG: Twin16")
	#define BDA_TWIN16

#elif defined (_WIN32)
	#pragma message("PROLOGUE MSG: Win32")
	#define BDA_WIN32

#elif defined(_WINDOWS)
	#pragma message("PROLOGUE MSG: Win16")
	#define BDA_WIN16

#else
	#error PROLOGUE ERROR: undefined OS requested
#endif

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//		General includes
//    (Depending on OS)
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#if defined(BDA_WIN16) || defined(BDA_WIN32)

#include <windows.h>
#include <windowsx.h>
#include <malloc.h>
#include <string.h>

#elif defined(BDA_TWIN16)

#include	"stdio.h"
#include	"stdlib.h"
#include	"malloc.h"

#endif

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//    Header of APIs and callback functions
//    (Windows) (void for others) 
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//    Note: WINAPI est défini dans Windows.h
//          à vérifier si c'est identique sous Borland...
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#if defined(BDA_WIN16)
	#define BDA_WINAPI	CALLBACK __loadds
#elif defined(BDA_WIN32)
	#define BDA_WINAPI	CALLBACK
#else
	#define BDA_WINAPI
	#define PASCAL
#endif



// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//		Header of functions
//    (Depending on OS)
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// utilisé pour que la définition et la déclaration de variables
// globales soient localisées dans un même fichier (typiquement,
// pubwbda.h)
#define BDA_EXTERN	extern

#define BDA_PRIVATE static

#if defined(BDA_VMS)
#define BDA_GLOBAL	noshare
#else
#define BDA_GLOBAL
#endif 

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//		Other defines
//    (Depending on OS)
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Boolean values
#define FALSE	0
#define TRUE	1
#define GLOBAL  
// Pointers
#define PTR   *

#if defined(BDA_TWIN16)
#define FAR far
#endif



// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//		Types
//    (Twin) (Windows, theese types are already defined in windows includes)
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#if defined(BDA_TWIN16)

// 1 byte
typedef unsigned char BYTE;
typedef signed   char CHAR;

// 2 bytes
typedef unsigned short WORD;
// SWORD defined in "all OS" section, see below

// 4 bytes
typedef unsigned long    	DWORD;
typedef signed   long    	LONG;
typedef unsigned long    	ULONG;

// 8 bytes
typedef unsigned long long    	UHUGE;
typedef signed   long long    	HUGE;

// Other
typedef double  DOUBLE;
typedef int     BOOL;
#endif


// ----------------------------------------------------------------------------------------
// This needs a little bit more care when forcing the type definitions !!!!! IJM 29/12/2004
// ----------------------------------------------------------------------------------------
#if defined(BDA_UNIX)

// 1 byte
#ifndef	BYTE
typedef unsigned char BYTE;
#endif
#ifndef	CHAR
typedef signed   char CHAR;
#endif

// 2 bytes
#ifndef	WORD
typedef unsigned short WORD;
#endif

// SWORD defined in "all OS" section, see below

// 4 bytes
#ifndef	DWORD
typedef unsigned long    DWORD;
#endif

#ifndef	LONG
typedef signed   long    LONG;
typedef unsigned long    ULONG;
#endif

// 8 bytes
#ifndef	HUGE
typedef unsigned   long long   HUGE;
#endif

// Other
#ifndef	DOUBLE
typedef double  DOUBLE;
#endif

#ifndef	BOOLI
#ifndef	BOOL
typedef int     BOOL;
#endif
#else
typedef unsigned char BOOL;
#endif

// far FAR Far fAR FaR fAr et puis et puis
#define	far
#define	FAR

#define LOBYTE(w)  ((unsigned char)(w))
#define HIBYTE(w)  ((unsigned char)(((unsigned int)(w) >> 8) & 0xFF))
#define LOWORD(l)  ((unsigned short)(unsigned long)(l))
#define HIWORD(l)  ((unsigned short)((((unsigned long)(l)) >> 16) & 0xFFFF))
#endif

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//		Types
//    (All OS)
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
/*
 *	NULL pointer type
 *	-----------------
 */
#ifdef GN
#undef GN
#endif /* GN */
#define GN(x)	(x PTR) NULL

#define VOID	void
typedef signed short SWORD;

#ifndef	EXAWORD
#ifdef	VERSION666
#ifdef	ABAL64
#define	EXAWORD HUGE
#else
#define	EXAWORD ULONG
#endif
#else
#define	EXAWORD WORD
#endif
#endif

typedef char far * PTRC;

#endif	/* __ABALDEF_H__ */


