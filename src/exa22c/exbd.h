/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987, 1994 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXBD - H				*/
/*		Version :	1.4d / 2.1c				*/
/*		Date 	:	20/06/1994				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXBD_H		
#define	_EXBD_H		

#define	BDRECORDPTR    struct	bdf_zone SPTR 

struct	bdf_zone {
	EXAWORD    bdfid;			/* File handle associated	*/
	BPTR	zdxbdf;			/* Zone d'echange du fichier	*/
	EXAWORD	zdxlen;			/* Longeur de la zone d'echange	*/
	BDRECORDPTR	bdf_prev;	/* Pointer sur zone precedante	*/
	BDRECORDPTR	bdf_next;	/* Pointer sur zone suivante	*/
	};

#endif	/* _EXBD_H */
	/* ------- */

