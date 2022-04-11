/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXFUSE.H  				*/
/*		Version :	1.4a / 2.2a				*/
/*		Date 	:	21/06/2002				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXFUSE_H		/* If Not already included 		*/
#define	_EXFUSE_H		/* Avoid multiple inclusion		*/

#include "ex.h"		/* Include Generale header			*/
#include "exerrno.h"	/* Error Code and possible values		*/
#include "exvtype.h"	/* Variable Types and definitions		*/
#include "bda.h"	/* Definitions required for Dynamic Libraries	*/
// would be this if it were not MISSING
// #include "bda_std.h"	/* Definitions required for Dynamic Libraries	*/
// -----------------------------------
#include "exask.h"	/* ASK Control Variables			*/
#include "excico.h"	/* CICO interface definition			*/
#include "extmp.h"	/* Temporary allocation controller		*/
#include "exwork.h"	/* WORK SET Description				*/
#include "exdieze.h"	/* Dieze Constants values			*/
#include "exwords.h"

#define	_BDA_ERROR	0
#define	_BDA_ORDINARY	1
#define _BDA_ASFUN12	2
#define _BDA_ASFUN11	3
#define _BDA_ZABAL   	4
#define	_BDA_REDIRECT	5
	
/*	User function management table		*/
/*	------------------------------		*/

#define	LDF_BDA	BDA_INIT

#ifndef	UNIX
#ifndef	VMS
#define	M_I86
#define	M_I286
#endif
#endif


struct	fusework	{
	BPTR		fusename;	/* Logical Name : Library .def  */
	BPTR		fuseprog;	/* Actual  Name : SetDllName	*/
	EXAWORD		fusesyst;	/* Redirection to low level id	*/
	EXAWORD		fusentry;	/* Entry logique dans le table	*/
	EXAWORD		fuseload;	/* redirection number 		*/
	EXAWORD		fusefunc;	/* Nombre de fonctions offert	*/
	EXAWORD		fusetype;	/* Type de bibliotheque		*/
	EXAWORD		fuselock;	/* Lock Attachment share	*/
	LDF_BDA PTR 	fusedesc;	/* Descripteur de bibliotheque	*/
	};

/*	Declaration of Global Variables		*/
/*	-------------------------------		*/
#ifdef ABALPS
struct	fusework PTR	FuseBase;	/* Structure Pointer		*/
EXAWORD			FuseCount;	/* Fonction Count		*/
#endif

/*	User Function FLAG definitions		*/
/*	------------------------------		*/
#define	FUSE_RESERVE	18		/* 18 octets reserved for ???   */

/*	References to External data items	*/
/*	---------------------------------	*/
EXTERN	EX_FILE_HANDLE TcodeFileHandle;	/* Tcode file handle		*/
EXTERN	EXAWORD	adr_usr;		/* Adresse secteur table user	*/
EXTERN	EXAWORD	lng_usr;		/* Longeur de cette table	*/
EXTERN	BPTR	GlobalDataSegment;	/* Global Data Segment		*/
EXTERN	BPTR	fdex;			/* Tcode Pointer		*/
EXTERN	EXAWORD	freg [], xreg [];	/* Registers			*/
EXTERN	EXAWORD 	ireg [], areg [];	/* Index Registers		*/
EXTERN	EXAWORD	amode;			/* Arg Retrieval Mode		*/
EXTERN	EXAWORD	mindex;			/* Stack of Pointers index	*/
EXTERN  EXAWORD 	ip_next;		/* EXAWORD stack index		*/
EXTERN	BPTR	adex;			/* Arguament descriptor pointer	*/
EXTERN	EXAWORD	adesc;			/* Current Arguament Descriptor	*/
EXTERN	BPTR 	TcodePtrStack;			/* Stack of Poitners to Args	*/
EXTERN	WPTR 	TcodeWordStack;		/* Stack of Poitners to Args	*/


#ifdef	DEBUGGER
#ifdef	ABALPS
#ifdef	ABAL14

					/* ---------------------------- */
EXTERN	EXAWORD	AsfunLibId;		/* Reference to library id	*/
EXTERN	EXAWORD	ExadbGoFunction;	/* Indicates Exadb Go Function  */
					/* ---------------------------- */
#include "exdbafun.h"			/* ASFUN library function proto */
					/* ---------------------------- */
#endif
#endif
#endif

#endif	/* EXFUSEH */

/* EOF */
/* --- */
