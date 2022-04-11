/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1994 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AOMAIN.H    				*/
/*		Version :	2.1b					*/
/*		Date	:	11/05/1994				*/
/*									*/
/* -------------------------------------------------------------------- */

#ifndef	_OPTIMISE_H
#define	_OPTIMISE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "allocate.h"

#ifdef	PRL2
#define	PRL
#endif

#ifdef	PRL3
#define	PRL
#endif
#ifdef	PRL
#define PROLOGUE
#endif

/* ******************************************************************** */
/*	POST OPTIMISER MODEL OPTION DEFINITIONS				*/	
/* ******************************************************************** */
/* #define AO_INTERNE */

/* #define AO_COMPILER */ /* Activates Compilation functions	*/

#define AO_LISTFILE /* Activates Liste and Statistics	*/

#ifndef	MODEL_DBGT
/* #define AO_STATS */   /* Activates Statistical information	*/
#endif

#ifdef	AO_COMPILER		/* If Compiler defined			*/
#ifndef	AO_LISTFILE		/* and list module not defined		*/
#define	AO_LISTFILE		/* Activate list module			*/
#endif
#endif

#ifdef	AO_STATS		/* If Statistics are Active		*/
#ifndef	AO_LISTFILE		/* and list module not defined		*/
#define	AO_LISTFILE		/* Activate list module			*/
#endif
#endif

/* ******************************************************************** */

#include "stdtypes.h"


#define ENCODE 	 1
#define	DECODE	 0
#ifdef	ABAL64
#define	HEADERBLOCK 512
#else
#define	HEADERBLOCK 256
#endif
#define	BLOCK	 256

#ifdef	VERSION666
#define	tcGetw(a) TcodeGetWord(a)
#define	tcPutw(a,v) TcodePutWord(a,v)

#define	ISLOCAL3	0x00008000L
#define	TOGLOBAL3	0x00007FFFL

#define	ISLOCAL4	0x00000001L
#define	TOGLOBAL4	0xFFFFFFFEL

#define	ISLOCAL		TcodeIsLocal
#define	TOGLOBAL	TcodeToGlobal

#ifndef	_AO_C
extern	EXAWORD ISLOCAL;
extern	EXAWORD TOGLOBAL;
#else
EXAWORD	ISLOCAL=ISLOCAL3;
EXAWORD	TOGLOBAL=TOGLOBAL3;
#endif

#else

#define	ISLOCAL		0x8000
#define	TOGLOBAL	0x7FFF

#ifdef	PRL

#define	tcGetw(bptr) *((EXAWORD XPTR) (bptr))

#define tcPutw(bptr,v) *((EXAWORD XPTR) (bptr)) = v

#else

#define	tcGetw(bptr)  ( (((EXAWORD) *(bptr + 1)) << 8) | ((EXAWORD) *(bptr)))

#define tcPutw(bptr,v) { \
		*(bptr) = (BYTE) (v & 0x00FF); \
		*(bptr + 1) = (BYTE) ((v >> 8) & 0x00FF); \
		}
#endif
#endif

#define	tcMove(arg) { \
		for (mz=arg;mz>0;mz--,slen--,ri++,si++) { *(rptr+ri) = *(sptr+si); } \
		}

#define tcBreak(x) { \
		m = x; break; \
		}
		

#ifndef	SEEK_SET
#define SEEK_SET 0
#endif

#ifdef	PRL
#define	OPENRW	2
#define	CREATRW	2
#define	TEMP_TRADUIT "-ot"
#define	ABAL_TRADUIT "-at"
#define	TEMP_MODULE  "-o"
#define	ABAL_MODULE  "-o"
#endif

#ifdef	DOS
#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>
#define	OPENRW	(O_RDWR | O_BINARY)
#define	CREATRW	(S_IWRITE | S_IREAD | O_BINARY)
#define	TEMP_TRADUIT ".ot"
#define	ABAL_TRADUIT ".at"
#define	TEMP_MODULE  ".o"
#define	ABAL_MODULE  ".o"
#endif

#ifdef	UNIX
#include <fcntl.h>
#define	OPENRW O_RDWR
#define	CREATRW 0666
#define	TEMP_TRADUIT ".ot"
#define	ABAL_TRADUIT ".at"
#define	TEMP_MODULE  ".o"
#define	ABAL_MODULE  ".o"
#endif

#ifdef	VMS
#define	OPENRW 3
#define	CREATRW 3
#define	TEMP_TRADUIT ".ot"
#define	ABAL_TRADUIT ".at"
#define	TEMP_MODULE  ".o"
#define	ABAL_MODULE  ".o"
#endif

#define	PROCEDURE_DIFFERED	0x0008
#define	PROCEDURE_USED		0x0004
#define	PROCEDURE_STATIC 	0x0002

/*	Command line options provided by User ( or hard coded )		*/
/*	-------------------------------------------------------		*/
struct	optimiser_options	{
					/* ---------------------------- */
	EXAWORD	CheckFmt;		/* format label checking	*/
	EXAWORD	Optimise;		/* Activates Optimisation	*/
	EXAWORD	Compile;		/* Activates Compilation	*/
	EXAWORD	Liste;			/* Activates Tcode Listing	*/
	EXAWORD	Stats;			/* Activates Statistics		*/
	EXAWORD	Analyse;		/* Activates Structure Analysis */
					/* ---------------------------- */
	EXAWORD	Global;			/* Global Data Optimisation	*/
	EXAWORD	Strip;			/* Removal of Symbolic Infos	*/
	EXAWORD	Registers;		/* Remove Redundant Expressions */
	EXAWORD	Inline;			/* Inline Code Blocks		*/
	EXAWORD	Tables;			/* Compress Data Tables		*/
	EXAWORD	Procedures;		/* Remove Unused Procedures	*/
	EXAWORD	Constants;		/* Compress Constants Table	*/
	EXAWORD	Verbose;		/* Verbalise during operation	*/
	EXAWORD	Warnings;		/* Output Warnings if needed 	*/
	EXAWORD	Segments;		/* Compression of Segments	*/
	EXAWORD	Pannel;
	EXAWORD	Alliance;		/* Inhibits  un-necessary	*/
					/* ---------------------------- */
	};

EXAWORD	TcodeGetWord(BPTR bptr);
void   	LineFeed();
VOID   TcodePutWord(BPTR bptr,EXAWORD v);

#ifdef	_OPTIMISE_C
	struct	optimiser_options	Options;
#else
extern	struct	optimiser_options	Options;
#endif

#ifdef WIN32
#ifndef AVIION
#ifndef UNIXWARE
EXAWORD	read(EXAWORD,BPTR,EXAWORD);
EXAWORD	write(EXAWORD,BPTR,EXAWORD);
long 	lseek( EXAWORD, long, EXAWORD );
#endif
#endif
#endif /* AIX_VERS */
#ifdef	WIN32ETC
EXAWORD	open( BPTR, EXAWORD );
EXAWORD	close( EXAWORD );
EXAWORD	creat( BPTR, EXAWORD );
EXAWORD	unlink( BPTR );
EXAWORD	link( BPTR, BPTR );
#endif

#include "aostream.h"


#endif	/* _OPTIMISE_H */
	/* ----------- */

