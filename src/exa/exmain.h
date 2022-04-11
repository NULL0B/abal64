/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMAIN.H  				*/
/*		Version :	1.4a / 2.1a				*/
/*		Date 	:	16/01/1997				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXMAIN_H		/* If not already included		*/
#define	_EXMAIN_H		/* Avoid multiple inclusions		*/

/* 03/01/97: Pour agf */
#include "pubagf.h"

#include "ex.h"			/* General Header file		 	*/
#ifndef	UNIX
#include "exctype.h"
#endif
#include "exerrno.h"		/* Error Code and possible values	*/
#include "extcode2.h"		/* Definition du 1er Secteur de T-Code 	*/
#include "exask.h"		/* ASK Control Variables		*/
#include "excico.h"		/* CICO interface definition		*/
#include "extimer.h"		/* TIMER control mechanism		*/	
#include "exwork.h"		/* WORK SET Description			*/

EXTERN  EXAWORD	tkodgeti();	/* Recover integer from buffer	  	*/
EXTERN  EXABYTE 	inbuf[];	/* Filename buffer			*/
EXTERN  BPTR 	fdex;		/* T-Code Pointer			*/
EXTERN	BPTR 	TcodeSegment;	/* T-code segment Base value		*/
EXTERN	BPTR	lineptr;	/* ABAL New line pointer		*/
EXTERN	EXAWORD	cur_seg;	/* Segment en cours d'execution		*/
EXTERN	EXAWORD	procid;		/* Procedure en cours d'execution	*/
EXTERN	EXAWORD	sicico;		/* Semaphore d'etat d'executeur		*/
EXTERN  BINAIRE kdex,bufdex,maxbuf;
EXTERN	EX_FILE_HANDLE TcodeFileHandle; /* Tcode File Handle		*/
EXTERN	EXAWORD	chain;		/* Variable d'indication du Chainage	*/
EXTERN	EXAWORD	loadgo;		/* Variable d'indication du Chainage	*/
EXTERN	EXAWORD	MaxIpcSem;	/* Number of User Ipc Semaphores	*/
#ifndef	PROLOGUE
#ifndef DOS 
EXTERN	EXAWORD	idflg,idbal;	/* Process control variables		*/
#endif
#endif

#ifdef 	VMS_CHARSET
EXTERN	EXAWORD	VmsCico;	/* Amenesik / Sologic / VMS character set flag	*/
#endif

EX_FILE_HANDLE OpenTcodeFile( BPTR filename );
#ifdef WIN32
void  Trap24(void);
void  UnTrap24(void);
#endif
#include "exmissing.h"
#endif	/* _EXMAIN_H */



