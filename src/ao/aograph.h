/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	AOGRAPH.H				*/
/*		Version :	2.1b					*/
/*		Date	:	11/05/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_GRAPHICS_H
#define	_GRAPHICS_H

#ifdef	VMS

/*	Gestion des modes d'affichage Graphiques VMS ou PROLOGUE
 *	--------------------------------------------------------
 */

EXTERN	EXAWORD	VmsCico;			/* VMS = 0; PRL = 1	*/

static BYTE	GrSym[2][11] = {

	/* VMS Mode Graphique codes */
	/* ------------------------ */
	0xA6 , 0xBE , 0xF0 , 0xA4 , 0xAD , 0xDE ,
	0xAF , 0xAE , 0xB8 , 0xAC , 0xD0,

	/* Amenesik / Sologic Compatible Codes */
	/* ------------------------- */
	0xB3 , 0xC4 , 0xDA , 0xBF , 0xC0 , 0xD9 ,
	0xC2 , 0xC1 , 0xC3 , 0xB4 , 0xC5

	};

#define	GRSYM_B3	(GrSym[(VmsCico)][0])	/* Verticale 		*/
#define	GRSYM_C4	(GrSym[(VmsCico)][1])	/* Horizontale		*/
#define	GRSYM_DA	(GrSym[(VmsCico)][2])	/* Coin Haut Gauche	*/
#define	GRSYM_BF	(GrSym[(VmsCico)][3])	/* Coin Haut Droite	*/	
#define	GRSYM_C0	(GrSym[(VmsCico)][4])	/* Coin Bas  Gauche	*/
#define	GRSYM_D9	(GrSym[(VmsCico)][5])	/* Coin Bas  Droite	*/
#define	GRSYM_C2	(GrSym[(VmsCico)][6])	/* Horizontale		*/
#define	GRSYM_C1	(GrSym[(VmsCico)][7])	/* Coin Haut Gauche	*/
#define	GRSYM_C3	(GrSym[(VmsCico)][8])	/* Coin Haut Droite	*/	
#define	GRSYM_B4	(GrSym[(VmsCico)][9])	/* Coin Bas  Gauche	*/
#define	GRSYM_C5	(GrSym[(VmsCico)][10])	/* Coin Bas  Droite	*/

#else	/* ! VMS */
	/* ----- */

#define	GRSYM_B3	0x00B3			/* Verticale 		*/
#define	GRSYM_C4	0x00C4			/* Horizontale		*/
#define	GRSYM_DA	0x00DA			/* Coin Haut Gauche	*/
#define	GRSYM_BF	0x00BF			/* Coin Haut Droite	*/	
#define	GRSYM_C0	0x00C0			/* Coin Bas  Gauche	*/
#define	GRSYM_D9	0x00D9			/* Coin Bas  Droite	*/
#define	GRSYM_C2	0x00C2
#define	GRSYM_C1	0x00C1
#define	GRSYM_C3	0x00C3	
#define	GRSYM_B4	0x00B4
#define	GRSYM_C5	0x00C5

#endif

#define	TOP_LEFT_CORNER  	GRSYM_DA
#define	HORIZONTAL_LINE  	GRSYM_C4
#define	TOP_RIGHT_CORNER 	GRSYM_BF
#define	VERTICAL_LINE 	 	GRSYM_B3
#define	BOTTOM_LEFT_CORNER 	GRSYM_C0
#define	BOTTOM_RIGHT_CORNER 	GRSYM_D9

#endif	/* _GRAPHICS_H */
	/* ----------- */

