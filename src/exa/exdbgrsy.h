/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBGRSY - H				*/
/*		Date 	:	16/01/1997				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	EXDBGRSYH
#define EXDBGRSYH

/* 03/01/97: Pour agf */
#include "pubagf.h"

#ifdef	VMS_CHARSET

/*	Gestion des modes d'affichage Graphiques VMS ou PROLOGUE
 *	--------------------------------------------------------
 */

EXTERN	EXAWORD	VmsCico;			/* VMS = 0; PRL = 1	*/

#ifdef	_EXDBUI_C

EXABYTE	GrSym[2][11] = {

	/* VMS Mode Graphique codes */
	/* ------------------------ */
	0xA6 , 0xBE , 0xF0 , 0xA4 , 0xAD , 0xDE ,
	0xAF , 0xAE , 0xB8 , 0xAC , 0xD0,

	/* Amenesik / Sologic Compatible Codes */
	/* ------------------------- */
	0xB3 , 0xC4 , 0xDA , 0xBF , 0xC0 , 0xD9 ,
	0xC2 , 0xC1 , 0xC3 , 0xB4 , 0xC5

	};
#else
EXTERN EXABYTE	GrSym[2][11];
#endif

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

/*
 *	Gestion des Couleurs d'affichage dans EXADB
 *	-------------------------------------------
 */

#define	Noir		0
#define	Rouge		1
#define	Vert		2
#define	Marron		3
#define	Bleu		4
#define	Magenta		5
#define	Cyan		6
#define	GrisClair	7
#define	GrisFonce	8
#define	RougeClair	9
#define	VertClair	10
#define	Jaune		11
#define	BleuClair	12
#define	MagentaClair	13
#define	CyanClair	14
#define	Blanc		15
#define	COULEUR		(Vert | ( Noir << 4))
#define	WASHFORE	Vert
#define	WASHBACK	Noir

#endif
