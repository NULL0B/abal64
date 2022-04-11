/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXGO - H				*/
/*		Date 	:	16/01/1997				*/
/*									*/
/*----------------------------------------------------------------------*/

/* 03/01/97: Pour agf */
#include "pubagf.h"

#include "ex.h"			/* General Header file		 	*/
#include "extcode2.h"		/* Definition du 1er Secteur de T-Code 	*/
#include "exask.h"		/* Ask control variables		*/
#include "excico.h"		/* CICO interface definition		*/
#include "extimer.h"		/* TIMER control mechanism		*/
#include "exwork.h"		/* WORK SET Description			*/

#ifdef ABALTRACE
EXTERN	EX_FILE_HANDLE MMT_nlog;
EXTERN	UBINAIR	simcbd;
#endif

EXTERN  tkodgeti();		/* Recover integer from buffer	  	*/

EXTERN  EXABYTE inbuf[];		/* Filename buffer			*/
EXTERN  EXABYTE fbuf[];		/* T-Code Header Buffer			*/
EXTERN  EXBPTR fdex;		/* T-Code Pointer			*/
EXTERN	EXBPTR TcodeSegment;	/* T-code segment Base value		*/
EXTERN	EXBPTR	lineptr;	/* ABAL New line pointer		*/
EXTERN	UBINAIR	cur_seg;	/* Segment en cours d'execution		*/
EXTERN	UBINAIR	procid;		/* Procedure en cours d'execution	*/
EXTERN	UBINAIR	sicico;		/* Semaphore d'etat d'executeur		*/
EXTERN  BINAIRE kdex,bufdex,maxbuf,tcerr; /* General Variables		*/
EXTERN	EX_FILE_HANDLE TcodeFileHandle; /* Tcode File Handle		*/
EXTERN	UBINAIR	chain;		/* Variable d'indication du Chainage	*/

#ifdef UNIX
EXTERN	UBINAIR	idflg,idbal;	/* Process control variables		*/
#endif
#ifdef VMS_CHARSET
EXTERN	UBINAIR	VmsCico;	/* Amenesik / Sologic / VMS character set flag	*/
#endif
