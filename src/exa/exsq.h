/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXSQ.H  				*/
/*		Version : 	1.4c / 2.1a				*/
/*		Date 	:	12/11/1992				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXSQ_H
#define	_EXSQ_H

#define	_EXSQ_C

#include "ex.h"
#include "exfile.h"
#include "excico.h"

#ifdef	ABAL14
extern	EXALONG	SystemError;
#endif

struct sqform {
	EXAWORD	SQxx_rec;
	EXAWORD	SQsz_rec;
	EXALONG	SQnb_rec;
	EXALONG	SQrd_rec;
	EXALONG	SQwr_rec;
	};

extern	struct sqform PTR fidbuff;

extern	EXAWORD 	fidinfo1;		/* Data Record Length 	*/
extern	EXAWORD	fidinfo2;		/* Data Key Length	*/
	
/*	SQ Control Commande code values		*/
/*	-------------------------------		*/

#define	GET_SQFCB	1		/* Read SQ file control block	*/
#define	MAJ_SQFCB	2		/* Update SQ file control block	*/
#define	LCK_SQFCB	4		/* Reads and locks SQ F.C.B.	*/

#define	FCB_LOCK	1		/* FCB locked flag		*/
#define	FCB_FREE	0		/* FCB free flag		*/
#define SOFTERROR	0		/* Soft error Value		*/

#endif	/* _EXSQ_H */
	/* ------- */
