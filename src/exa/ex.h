/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EX.H  					*/
/*		Version :	1.4b / 2.1d				*/
/*		Date 	:	25/04/1997				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef _EX_H				/* If not already included	*/
#define	_EX_H				/* Avoid multiple inclusions	*/

#define	LINT_ARGS	1		/* Activate Function checking 	*/

#include "exos.h"			/* OS dependant definitions	*/

#ifdef	VMS
#define	EXTERN	extern	noshare
#else
#define	EXTERN	extern
#endif

#include <stdio.h>			/* Standard IO functions	*/
#ifdef	UNIX
#include <stdlib.h>			/* Standard C  library		*/
#include <string.h>			/* #BG 18/01/12 */
#include <unistd.h>			/* Unix Standard functions	*/
#endif

#ifdef	WIN32
#include <string.h>
#include <math.h>
#endif	/* WIN32 */

/* #BG 27/03/12 */
#ifdef WIN32
#define cmemset				_fmemset
#define cstrcmpi			_stricmp
#define cstrncmpi			_strnicmp
#endif
#ifdef UNIX
#define cmemset				memset
#define cstrcmpi			strcasecmp
#define cstrncmpi			strncasecmp
#endif


#include "exsemaph.h"			/* IPC Semaphore Definitions	*/
#include "extcode.h"			/* Tcode Definitions		*/
#include "exkeys.h"			/* General key definitions	*/
#include "extypes.h"			/* Executeur Type Defs		*/
#include "exerror.h"			/* ABAL/BAL Error values	*/
#include "exatropt.h"			/* Translator Option Mask Value	*/

#ifndef WIN32
#ifndef O_BINARY
#define O_BINARY	0x8000
#endif
#endif

#ifndef SEEK_SET
#define SEEK_SET	0
#endif

/*
 *	Default Virtual machine Size values
 *	-----------------------------------
 */
#define	TCODEBLOCK	256		/* size of tcode block		*/
#define	ExRegMax	50		/* Default Register count	*/
#define	ExFicMax	64		/* Default File entry count	*/
#define	ExTmpMax	2048		/* Default Tempory Work Area	*/
#define	ExStkMax	300		/* Default Stack level count	*/
#define	ExLdsMax	256		/* Default Quick Alloc Size	*/

#ifndef	EXDATASEG			/* If not included by EXD-C	*/
#ifndef FixedRegisters

#define	freg	(*Freg)			/* Transform to pointer 	*/
#define	xreg	(*Xreg)			/*				*/
#define	ireg	(*Ireg)			/*				*/
#define	areg	(*Areg)			/*				*/

#endif	/* ! FixedRegisters	*/
#define	ip_hold	(*TcodeWordStack)		/*				*/
#define	minder	(*TcodePtrStack)		/*				*/
#ifdef	ABAL21
#ifdef	UNIX	
#define	sp_hold	(*TcodePushStack)		/*				*/
#endif	/* UNIX */
#ifdef	WIN32
#define	sp_hold	(*TcodePushStack)		/*				*/
#endif	/* WIN32  */
#endif  /* ABAL21 */
#endif	/* ! EXDATASEG 	*/

#include "exbcd.h"

#define GRANULE		4096		/* Provisoire			*/
#define	WORKSIZE	256		/* Limite de capacite Executeur */
#define	BLOCK		256		/* Taille des unites fichiers	*/
#define	MAXTCODE	256		/* Nombre de codes d'operation	*/
#define	NIBSHFT		4		/* Decalage d'un demi octet	*/
#define BYTSHFT		8		/* Decalage d'un octet		*/
#define	LIMTCODE	0x001F		/* Mask de limit de Tcode	*/
#define ARGBITS		0x0060		/* Arguament defining bits	*/
#define	FMTSIZE		16		/* Maximum Number  FMT filters  */
#define	DYNASIZE	16		/* Size of Dynamat matrix	*/
#define	ARGLENGTH	255		/* Size of 'Commande init maxi' */
#ifdef	ABAL64
#define	ASKBUFMAX	512		/* Longeur maxi d'un ASK = $	*/
#else
#define	ASKBUFMAX	256		/* Longeur maxi d'un ASK = $	*/
#endif

/* OBSOLETE */
/* #define STAKSIZE	1024 */		/* Pile des retours et push pop */
/* #define MAX_SEGS	64 */		/* Nombre de segments Maximum	*/
/* -------- */


#define MAX_AT_FILE	 64

/*
 *	File name control and definition
 *	--------------------------------
 */

#define	FIDMAX		64		/* Nombre maxi de fichiers	*/
					/* Ouverte a la fois		*/
#ifdef UNIX
#define	PATHTERM	'/'		/* Terminateur de chemin	*/
#define PATHSEP		'/'		/* Pathname Separator		*/
#define PATHSEP2	'/'		/* Pathname Separator		*/
#define FILESEP		'.'		/* Amenesik / Sologic Filename separateur */
#define FILEEXT		'a'		/* T-Code file extension	*/
#define FILEEXT2	't'		/* T-Code file extension	*/
#define	FNMAX		64		/* Longeur max Nom du fichier	*/
#define FILETERM	0		/* File name end mark	        */
#define	ARGFIELD	" "		/* Arguament separateur		*/
#define	CMDFIELD	' '		/* Arguament separateur		*/
#define	ID_EX_BAL	"exa"		/* Executeur ABAL		*/
#ifdef DEBUGGER
#define	ID_EX_ABAL	"exadb"		/* Executeur ABAL		*/
#else
#define	ID_EX_ABAL	"exa"		/* Executeur ABAL		*/
#endif
#endif

#ifdef VMS
#define	PATHTERM	'\0'		/* Terminateur de chemin	*/
#define PATHSEP		':'		/* Pathname Separator		*/
#define	PATHSEP2	']'		/* Alternative			*/
#define FILESEP		'.'		/* Amenesik / Sologic Filename separateur */
#define FILEEXT		'a'		/* T-Code file extension	*/
#define FILEEXT2	't'		/* T-Code file extension	*/
#define	FNMAX		255		/* Longeur max Nom du fichier	*/
#define FILETERM	0		/* File name end mark	        */
#define	ARGFIELD	" "		/* Arguament separateur		*/
#define	CMDFIELD	' '		/* Arguament separateur		*/
#define	ID_EX_BAL	"exa"		/* Executeur ABAL		*/
#ifdef DEBUGGER
#define	ID_EX_ABAL	"exadb"		/* Executeur ABAL		*/
#else
#define	ID_EX_ABAL	"exa"		/* Executeur ABAL		*/
#endif
#endif

#ifdef DOS
#define	PATHTERM	'\\'		/* Terminateur de chemin	*/
#define PATHSEP		'\\'		/* Pathname Separator		*/
#define PATHSEP2	'\\'		/* Pathname Separator		*/
#define FILESEP		'.'		/* Amenesik / Sologic Filename separateur */
#define FILEEXT		'A'		/* T-Code file extension	*/
#define FILEEXT2	'T'		/* T-Code file extension	*/
#ifdef WIN32
#define	FNMAX		270		/* Longeur max Nom du fichier	*/
#else
#define	FNMAX		64		/* Longeur max Nom du fichier	*/
#endif
#define FILETERM	0		/* File name end mark	        */
#define	ARGFIELD	" "		/* Arguament separateur		*/
#define	CMDFIELD	' '		/* Arguament separateur		*/
#define	ID_EX_BAL	"ex"		/* Executeur BAL		*/
#ifdef DEBUGGER
#define	ID_EX_ABAL	"exadb"		/* Executeur ABAL		*/
#else
#define	ID_EX_ABAL	"exa"		/* Executeur ABAL		*/
#endif
#endif

#ifdef PROLOGUE
#define	PATHTERM	'.'		/* Terminateur de chemin	*/
#define PATHSEP		'\\'		/* Pathname Separator		*/
#define PATHSEP2	'\\'		/* Pathname Separator		*/
#define FILESEP		'-'		/* Amenesik / Sologic Filename separateur */
#define FILEEXT		'A'		/* T-Code file extension	*/
#define FILEEXT2	'T'		/* T-Code file extension	*/
#define	FNMAX		255		/* Longeur max Nom du fichier	*/
#define FILETERM	' '		/* File name end mark	        */
#define	ARGFIELD	","		/* Arguament separateur		*/
#define	CMDFIELD	','		/* Arguament separateur		*/
#define	ID_EX_BAL	"ex "		/* Executeur BAL		*/
#ifdef DEBUGGER
#define	ID_EX_ABAL	"exadb"		/* Executeur ABAL		*/
#else
#define	ID_EX_ABAL	"exa"		/* Executeur ABAL		*/
#endif
#endif

#define RETCHAR		13		/* Caractere Retour chariot	*/
#define	DECIMUL		','		/* Default decimal point	*/

/*
 *	Machine / Hardware dependant Macros for EXAWORD accessing
 *	------------------------------------------------------
 *
 */

#define tkodgetc()	((EXABYTE) *(fdex++))

#define f_saut()	(fdex = TcodeSegment + Tcodeword( fdex ))

#include "exword.h"			/* Macros for EXAWORD access	  */
#include "exfich.h"			/* Structure of File table	   */
#include "exsegt.h"			/* Structure of segments tables	   */
#include "exprct.h"			/* Structure of Procedure table	   */
#include "exkeep.h"			/* Structure of Ext Varb Keep zone */
#include "exproto.h"			/* All function prototypes	   */
#include "exreg.h"			/* Speciale register useages	   */
#include "exformat.h"			/* IOF and BCD control structure   */

#define	ALSMID "exa"
#include "allocate.h"			/* Allocation and liberation	   */

#ifndef	UNIX
#ifndef VMS
#include "exrdef.h" 			/* Redefinitions of Function	   */
EXAWORD	access(BPTR,EXAWORD);		/* Systeme Function Access 2 Arg   */
#endif	/* ! VMS  */
#endif	/* ! UNIX */

#define	atoi(a,b) exatoi(a,b)
#define	atol(a,b) exatol(a,b)

#include "exwords.h"

#endif	/* _EX_H */
	/* ----- */
