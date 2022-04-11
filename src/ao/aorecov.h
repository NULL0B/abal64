/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	RECOVERY.H  				*/
/*		Version :	1.4a					*/
/*		Date	:	24/09/1991				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_RECOVERY_H
#define	_RECOVERY_H

#define	RECOVERY	struct recovery XPTR

struct	recovery	{
	EXAWORD		offset;
	EXAWORD		length;
	BYTE		buffer[16];
	RECOVERY	next;
	};


#ifdef	_RECOVERY_C
	RECOVERY	Salvage;
	RECOVERY	Storage;
#else
extern	RECOVERY	Salvage;
#endif


#endif	/* _RECOVERY_H */
	/* ----------- */

