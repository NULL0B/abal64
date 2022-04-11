/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXCTRL - H				*/
/*		Date 	:	09.11.1987				*/
/*									*/
/*----------------------------------------------------------------------*/

#define MASK128 0x0080		/* Annulation de  I=&etiquette		*/
#define	MASK64	0x0040		/* Annulation de l'affichage		*/
#define MASK32	0x0020		/* Ne modifie pas si RC en 1ere rang	*/
#define MASK16  0x0010		/* Permet E = &etiquette si erreur	*/
#define	MASK8	0x0008		/* RC n'est pas obligatoire		*/
#define	MASK4	0x0004		/* Efface zone apres erreur de saisie	*/
#define	MASK2	0x0002		/* BELL si erreur de saisie		*/
#define	MASK1	0x0001		/* Refus de tout caractere invalide.	*/

#define	MASKU	0xE100		/* All but curser length oblig		*/
#define	MASKW	0xE000		/* All but curser length free		*/
#define	MASKA	0x8100		/* Alpha only len oblig			*/
#define	MASKD	0x8000		/* Alpha only len free			*/
#define	MASKZ	0x4100		/* Numeric only len oblig		*/
#define	MASKN	0x4000		/* Numeric only len free		*/
#define	MASKB	0xC100		/* Alpha numeric length oblig		*/
#define	MASKC	0xC000		/* Alpha numeric Length free		*/
#define	MASKSO	0x0800		/* Sign + or - obligatoire		*/
#define	MASKSF	0x0000		/* Sign - necessaire + par default	*/
#define	MASKE	0xF000		/* Accept any key to the string		*/
#define	MASKF	0x0400		/* Do not clear to end of zone input	*/
#define	MASKV	0x0200		/* Virgule not Point			*/
#define	MASKP	0x0000		/* Point not virgule			*/

/*	Default Value (Each time IOWORK is Entered	*/

#define	ASKDEF	0xC200		/* Alpha - Numeric Free length
				 * Clear to End of zone
				 * Virgule not dot
				 * MASK 3 refus and bell
				 */
