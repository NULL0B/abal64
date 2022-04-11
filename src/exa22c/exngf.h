/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXNGF.H  				*/
/*		Version :	1.4b / 2.1a				*/
/*		Date 	:	12/11/1992				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXNGF_H		/* If not already included		*/
#define	_EXNGF_H		/* Avoid multiple inclusions		*/

#include "ex.h"			/* Global Definitions			*/
#ifndef	UNIX
#include "exctype.h"
#endif
#include "exerrno.h"		/* Error Values for Amenesik / Sologic		*/
#include "exfile.h"		/* File Access rights			*/
#include "experm.h"		/* ASSIGN Mask Permission definitions	*/
#include "extcngf.h"		/* NGF Function Codes			*/
#include "exask.h"		/* ASK Control Variables		*/
#include "extmp.h"		/* Temporary descriptor allocation	*/
#include "excico.h"		/* CICO interface definition		*/
#include "exwork.h"		/* WORK SET Description			*/
#include "exdieze.h"		/* Dieze Constants values		*/	
#include "exvtype.h"


/* 	Amenesik / Sologic  SF function codes	*/
/*	---------------------------	*/

#ifdef	UNIX
#define		PRL_RDUNIX	0x0063
#define		PRL_WRUNIX	0x00A3
#endif

#define		PRL_CHAR	0x0000
#define		PRL_DVRDIM	0x0040
#define		PRL_DVRDBF	0x0044
#define		PRL_RDSECT	0x0060
#define		PRL_RDSQ	0x0061
#define		PRL_RDBLOC	0x0064
#define		PRL_RDZC	0x007A
#define		PRL_RDZCEX	0x007E
#define		PRL_DVWRIM	0x0080
#define		PRL_DVWRBF	0x0084
#define		PRL_MDSQ	0x00A1
#define		PRL_WRSECT	0x00A0
#define		PRL_WRBLOC	0x00A4
#define		PRL_WRSQ	0x00A5
#define		PRL_WRZC	0x00BA

#ifdef PROLOGUE
#define		MAXRUBLEN	16		/* Max length of Rubr	*/
#endif

#define		MAXCRIT		16		/* Nombre par critere	*/
#define		OLDMAXCRIT	10		/* Nombre par critere	*/
#define		IMPR_BUF	16		/* Default printer buf	*/

#include "exmvirt.h"


/*	Code pointers and base	*/
/*	----------------------	*/

EXTERN	BPTR	lineptr;
EXTERN	BPTR	adex;
EXTERN	EXAWORD	adesc;
EXTERN	EXAWORD	amode;
EXTERN	BPTR	fdex;
EXTERN	BPTR	TcodeSegment;
EXTERN	struct fichdt SPTR AssignTable;
EXTERN	EXAWORD	chain;
EXTERN	EXAWORD	loadgo;

#ifdef	ABAL14
EXTERN	EXALONG 	SystemError;
#endif


EXTERN	LSEEKTYPE	hugeint;
EXTERN	EXAWORD		extwrite;

/*	Gestion des fichiers S.I. ( ou C.I.S.A.M. )	*/
/*	-------------------------------------------	*/

EXTERN	BPTR	si_cle,si_buf;
EXTERN	int	si_ver,si_flg,si_lng;
EXTERN	EXAWORD	si_mq;
EXTERN	EXAWORD	simcbd;
EXTERN	EXABYTE	simcode[16];

EXTERN	EXABYTE	mathwork[];

EXTERN	EXAWORD 	fidperm,fidblen,fidbd,fidmc;
EXTERN	BPTR	fidname,fidbuff,fidbase;

#ifdef ABAL_LONG_NAMES
EXTERN EXAWORD 	fidblen_long;
EXTERN BPTR 		fidbuff_long;
EXTERN	EXABYTE	bSystemLongNames;
EXTERN	EXABYTE	bUserLongNames;
#endif

EXTERN	EXAWORD    lfh;
EXTERN	EX_FILE_HANDLE fidreel;
EXTERN	EX_FILE_HANDLE dbreel;

#ifdef PRL_SF
EXTERN	LSEEKTYPE	fidseek;
#else
#ifdef ABAL_CRITERIA
EXTERN	LSEEKTYPE	fidseek;
#endif
#endif
EXTERN	EXAWORD	fidinfo1;
EXTERN	EXAWORD	fidinfo2;

/*	Console IO and general variable		*/
/*	-------------------------------		*/
	
EXTERN	EXAWORD	sicico;
EXTERN	EXAWORD	rubr_max;
EXTERN	BPTR	rubr_base;
EXTERN	EXABYTE	joinwork[];


EXTERN	EX_FILE_HANDLE TcodeFileHandle;

#ifndef	ABAL21
EXTERN	EXAWORD	fmtchk;
#endif

/*	EXALONG conversion function prototypes	*/
/*	-----------------------------------	*/

EXTERN	LSEEKTYPE	bcdtol();
EXTERN	LSEEKTYPE	exatol();

/*	External Variable Bufferisation Controllers	*/
/*	-------------------------------------------	*/
 
EXTERN	EX_FILE_HANDLE VmemFid;	/* Buffer  File ID   	*/
EXTERN	EXAWORD	VmemLng;	/* Buffer  Length    	*/
EXTERN	EXALONG	VmemOfs;	/* Buffer  offset    	*/
EXTERN	EXAWORD	VmemDif;	/* = 1;			*/
EXTERN	EXAWORD	VmemExt;	/* = VmemAdj;		*/
EXTERN	EXALONG	VmemWot;	/* = adr_phy_fich;	*/
EXTERN	EXAWORD	VmemHow;	/* = dleng;		*/
EXTERN	BPTR	fieldex;	/* Buffer Base pointer	*/

EXTERN	EXAWORD	LastErreur;	/* Global Last Error Adr */

#ifdef PROLOGUE
EXTERN	EXABYTE 	exdirdesc[];	/* Catalogue work buffer	*/
#endif


#ifdef PROLOGUE
#define x_npos() 	npos()
#else
#ifndef UNIX
#ifndef VMS
#define	x_npos()	0
#endif  /* ! VMS */
#endif	/* ! NIX */
#endif  /*   PRL */

#ifdef VMS
#define	unlink(Xarg1) delete(Xarg1)
#endif

#ifdef	UNIX
#ifdef	ABAL_TCPIP
#ifndef	_EXSQ_C
#include "extcpip.h"
#endif
#endif
#endif

#endif	/* EXNGFH */
	/* ------ */
