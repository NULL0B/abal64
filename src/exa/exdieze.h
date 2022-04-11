/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDIEZE.H  				*/
/*		Date 	:	12/11/1992				*/
/*		Version :	1.4c / 2.1a				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDIEZE_H
#define	_EXDIEZE_H

EXTERN EXAWORD	diezreg;	/* Number of registers (User)		*/
EXTERN EXAWORD	diezfic;	/* Number of ASSIGN table entries	*/
EXTERN EXAWORD	dieztmp;	/* Temporary variable space (octets)	*/
EXTERN EXAWORD	diezstk;	/* Integer and pointer stack depth	*/
EXTERN EXAWORD	diezlds;	/* Maximum Local Variable Quick Alloc	*/
EXTERN EXAWORD	diezfile;	/* Tempory file count for Chainage	*/

#ifdef	ABAL14
EXTERN EXAWORD	diezmin;	/* Taille minimum des allocation malloc	*/
#endif	/* ABAL14 */

#ifdef	ABAL21
EXTERN EXAWORD	DiezePageSize;	/* Extended Memory Page Size		*/
EXTERN EXAWORD	DiezeSwapSize;	/* Swap Buffer Maximum Count		*/
EXTERN EXAWORD	DiezeEtendu;	/* Extended Memory Options Flags	*/ 
#endif	/* ABAL21 */

#endif	/* _EXDIEZE_H */
	/* ---------- */
