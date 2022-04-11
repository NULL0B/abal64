
#ifndef __ALDTYPE_H__
#define __ALDTYPE_H__

/*
 *      Projet  : ABAL				Copyright Amenesik / Sologic   1997
 *      Module  : ATR
 *      Fichier : ALDTYPE.H
 *      Version : 2.1a
 *      Date    : 12/12/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Linker Abal ALD
 *
 *      [Debug interne du traducteur]
 *
 *		
 */


/*
		General include file for ALD

		Introduced by JPH for WAbal construction

		Modifications list :
		12/12/97			JPH	File creation
*/


/*
	JPH : list of changes to adapt to WALD.

	.hp, .he are not easy to manage.
	==>	restructure to place all "public" definitions in "."
	==>	add a header file 'AldType.h' (this file) included
			in every '.c' at fisrt position.

	XPTR makes ObjectMaster unhappy
	==>	replaced by XPTR * (XPTR is now empty)

	printf not supported under: window with ctConsole, DLL
	==>	replaced by lkprintf. Defines macro for every system


	new compiler switch:

	__WALD__		give version of WALD, only valid for window's ALD

					This version :
					-	Use ctDiagnostic for output
					-	Should support FAT32 compatible long names
					-	etc.


	YT : list of changes to adapt to WALD.


*/

/*
	You may define in your project/make:
		__TRACE_PATCH
		__TRACE

*/

/*
	Try to guess where we are from compiler signature

*/

#ifdef _MSC_VER
	#define KNOWN_COMPILER
#ifndef	_DOS //SAP
#ifndef	PRL //SAP
	#define __WALD__
	#define	__WINDOWS_SOURCE__
	#define	LINT_ARGS
	#define lkprintf ctPrintDefaultConsole
	/*CICO ignored*/
	#define WIN_BRUNO
	#define WIN_BRUNO_DARR
#else //SAP
	#define PROLOGUE
	#define prologue
	#define lkprintf printf //SAP
#endif //SAP
#else //SAP
	#define lkprintf printf //SAP
#endif //SAP
	#define	DOS
#ifndef	PRL //SAP
	#define	msdos
#endif //SAP
	#define	ver21
/*///	#define	OSSEG */
/*///	#define	WINVER 0X300 */
#include fuck
	#include <stdio.h>
	#include <stdlib.h> /* exit */
	#include <string.h> /* strcpy */
#endif

/* Unspecified compiler */
#ifndef KNOWN_COMPILER
#define __PORTABLE__

#endif

#ifndef lkprintf
#define lkprintf printf
#endif

#include "lkdef.h"
#ifdef	__WINDOWS_SOURCE__
#include "pubwcico.h"
#endif

#ifdef	__WINDOWS_SOURCE__
#include "lkwind.h"
#endif

/*
	Macro vide pour faciliter la lecture des sources


*/

#ifndef IN
#define IN
#endif
#ifndef INOUT
#define INOUT
#endif
#ifndef OUT
#define OUT
#endif

#define CTRL_Z 0x1a
#define LF		0x0a	/* \r 0xa */
#define CR		0x0d	/* \n 0xd */

#ifdef buf_cico
#define X_BSTART()	x_bstart()
#define X_BFLUSH()	x_bflush()
#else
#define X_BSTART()
#define X_BFLUSH()	
#endif

#include "cttype.h"
#include "lksignal.h"

#endif /* ald_type */
