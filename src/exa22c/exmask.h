/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMASK.H  				*/
/*		Version :	1.2e / 1.3b / 1.4a / 1.5a		*/
/*		Date 	:	02/11/1992				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXMASK_H
#define _EXMASK_H

/*
 *	Mask bit definitions
 *	--------------------
 *
 */

/*	Extended A.B.A.L. Masks		*/
/*	-----------------------		*/
#ifdef	ABAL21
#define	MASKLAST 0x8000		/* Seek to end of string if MASK 256	 */
#else
#define	MASKLAST 0x0000		/* Seek to end of string if MASK 256	 */
#endif

#ifdef	ABAL14
#define MASKBELL 0x4000		/* Ne fait pas des BIP BIP (BIP)	 */
#define MASK8192 0x2000		/* En cas de MASK 512 et 4096 keep all	 */
#endif

#define	MASK4096 0x1000		/* En Cas de MASK 512 Affectation des    */
				/* Des Characters deja Saisie avant le   */
				/* Debranchement 			 */
 
#define MASK2048 0x0800		/* RAZ du Tampon en cas du TIMER	 */

#define	MASK1024 0x0400		/* Empeche debranchement du TIMER 	 */

#define	MASK512	 0x0200		/* PermetDebranchement pendant saisie	 */
				/* a n'importe lequel position du tampon */

#define	MASK256	 0x0100		/* Activate INS DEL etc keys for ASK	 */

/*	Standard B.A.L. Masks		*/
/*	---------------------		*/

#define MASK128 0x0080		/* Annulation de  I=&etiquette		*/
#define	MASK64	0x0040		/* Annulation de l'affichage		*/
#define MASK32	0x0020		/* Ne modifie pas si RC en 1ere rang	*/
#define MASK16  0x0010		/* Permet E = &etiquette si erreur	*/
#define	MASK8	0x0008		/* RC n'est pas obligatoire		*/
#define	MASK4	0x0004		/* Efface zone apres erreur de saisie	*/
#define	MASK2	0x0002		/* BELL si erreur de saisie		*/
#define	MASK1	0x0001		/* Refus de tout caractere invalide.	*/

#define	MASKDEF	0x0003		/* MASK 3 refus and bell		*/

#endif	/* _EXMASK_H */
	/* --------- */
