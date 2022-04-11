/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Project Maintanance 			*/
/*		----------------------------------			*/
/*									*/
/*		  Copyright (c) 1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	UTMACRO.H				*/
/*		Version :	1.4b					*/
/*		Date	:	15/11/1991				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_UTMACRO_H
#define	_UTMACRO_H

/*
 *	Prototypes for the functions in UTMACRO.C
 *	-----------------------------------------
 */

#ifndef	UNIX
#ifndef	VMS
EXTERN	BPTR	Expand_Macros(BPTR,BPTR);
EXTERN	BPTR	SearchName(BPTR);
EXTERN	BPTR	Recherche(BPTR);
EXTERN	int	Add_Macro(BPTR,BPTR);
EXTERN	int	Remove_Macro(BPTR);
EXTERN	int	First_Macro(BPTR XPTR, BPTR XPTR);
EXTERN	int	Next_Macro( BPTR XPTR, BPTR XPTR);
#endif
#endif

#ifndef	DOS
#ifndef	PRL
EXTERN	BPTR	Expand_Macros();
EXTERN	BPTR	SearchName();
EXTERN	BPTR	Recherche();
EXTERN	int	Add_Macro();
EXTERN	int	Remove_Macro();
EXTERN	int	First_Macro();
EXTERN	int	Next_Macro();
#endif
#endif

#endif	/* _UTMACRO_H */
	/* ---------- */
