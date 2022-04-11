/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 2000
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
	// Autre Compilateurs
	#pragma message("PROLOGUE WARNING: compilateur non référencé")
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
typedef unsigned long    DWORD;
typedef signed   long    LONG;

// Other
typedef double  DOUBLE;
typedef int     BOOL;
#endif

#if defined(BDA_UNIX)

// 1 byte
typedef unsigned char BYTE;
typedef signed   char CHAR;

// 2 bytes
typedef unsigned short WORD;
// SWORD defined in "all OS" section, see below

// 4 bytes
typedef unsigned long    DWORD;
typedef signed   long    LONG;

// Other
typedef double  DOUBLE;
typedef int     BOOL;

// far FAR Far fAR FaR fAr et puis et puis
#define	far
#define	FAR

#endif

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//		Types
//    (All OS)
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#define VOID	void
typedef signed short SWORD;


typedef char far * PTRC;

#endif	/* __ABALDEF_H__ */


