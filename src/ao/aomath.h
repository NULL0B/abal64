/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AOMATH.H   				*/
/*		Version :	1.4a					*/
/*		Date	:	25/09/1991				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AOMATH_H
#define	_AOMATH_H


#define	ABAL_BCDFORM	110
#define	ABAL_BCD2LONG	110
#define	ABAL_NDXZERO	102
#define	ABAL_NUM2BIG	106

#define	SOFTERROR	0
#define	BINAIRE	short int

#define	BCDMAX	12
#define	BCDBYT	BCDMAX * 2
#define	BCDDIG	BCDBYT * 2

#ifdef	_AOMATH_H

BYTE	mathwork[6][BCDDIG];

#endif

#endif	/* _AOMATH_H   */
	/* ----------- */

