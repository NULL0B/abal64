/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987, 1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXBCD.H  				*/
/*		Version :	2.1a					*/
/*		Date 	:	04/08/1992				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXBCD_H
#define	_EXBCD_H

#define	BCDMAX		12		/* Maximum number of BCD bytes	*/
#define	BCDBYT		BCDMAX * 2	/* Number of decimal places MAX	*/
#define	BCDDIG		BCDBYT * 2	/* Number of BCD digits allowed	*/

#define	BCD_MaskH	0x00F0		/* 1st Digit Separator Mask	*/
#define	BCD_MaskL	0x000F		/* 2nd digit separator mask	*/
#define	BCD_Sep_H	0x00A0		/* 1st digit decimal point	*/
#define	BCD_Sep_L	0x000A		/* 2nd digit decimal point	*/
#define	BCD_Pos		0x00C0		/* Positive Header sign		*/
#define	BCD_NegR	0x00B0		/* Normal Negative header	*/
#define	BCD_NegI	0x0040		/* Fixed negative header	*/
#define	BCD_Filler	0x00FF		/* BCD string filler		*/

#endif	/* _EXBCD_H */
	/* -------- */
