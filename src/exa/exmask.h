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

/* Standard B.A.L. Masks */
/* --------------------- */

#define	MASK_DEF				0x0003		/*       3 : Par defaut: Refus and BELL		*/

#define	MASK_REJECT_INV			0x0001		/*       1 : Refus de tout caractere invalide. Option par defaut */
#define	MASK_BELL				0x0002		/*       2 : Provoque l'emission d'une sonnerie a chaque caractere invalide. Option par defaut */
#define	MASK_RESET_INV			0x0004		/*       4 : Annule toute la zone de saisie si un caractere invalide est entre. La donnee doit etre entièrement re-saisie */
#define	MASK_NO_CR				0x0008		/*       8 : Un retour chariot n'est pas exige si la zone de saisie est complete */
#define MASK_ACTIV_JUMP_E		0x0010		/*      16 : Rend actif le debranchement "E=etiquette" de l'instruction ASK */
#define MASK_CR_KEEP			0x0020		/*      32 : Ne modifie pas la valeur de la variable a saisir si le premier caractere saisi est retour chariot */
#define	MASK_SECRET				0x0040		/*      64 : Annule l'affichage des caracteres saisis (mode secret).Le curseur n'est pas gere pendant la saisie avec cette option */
#define MASK_DEACTIV_JUMP_I		0x0080		/*     128 : Annule le debranchement "I=etiquette" de l'instruction ASK */

/* Extended A.B.A.L. Masks */
/* ----------------------- */

#define	MASK_ACTIV_EDIT_KEYS	0x0100		/*    256 : Permet la gestion des touches d'edition pendant la saisie (comme les touches INS, DEL, DEBUT, FIN ...) */
											/*          Permet aussi la gestion des attributs et couleurs de saisie grace aux directives ASKATB et ASKCOLOR */
#define	MASK_ACTIV_JUMP_ANY		0x0200		/*    512 : Rend les debranchements actifs pour tout caractere saisi (et non pas uniquement pour le premier) */
#define	MASK_DEACTIV_JUMP_TIMER	0x0400		/*   1024 : Inhibe, le temps de la saisie, le debranchement sur expiration d'un delai (TIMER) */
#define MASK_RAZ_TIMER			0x0800		/*   2048 : RAZ du contenu de la zone saisie s'il y a debranchement sur expiration d'un delai */
#define	MASK_KEEP_DATA			0x1000		/*   4096 : Si le masque MASK MASK_ACTIV_JUMP_ANY est actif, conserve la saisie effectuee avant le debranchement */
#define MASK_DONOT_TRUNK		0x2000		/*   8192 : Si les masques MASK_ACTIV_JUMP_ANY et MASK_KEEP_DATA sont actifs, la saisie n'est pas tronquee a la position du curseur et l'ancienne fin de ligne est conservee */
#define MASK_REPLACE_QUITE		0x4000		/*  16384 : N'emet pas de bip sonore lors de la bascule entre le mode insertion et le mode remplacement (INSERT) */
#define	MASK_CURSOR_END			0x8000		/*  32768 : Si le masque MASK_ACTIV_EDIT_KEYS est actif, positionne le curseur a la fin du texte */
#ifdef	VERSION666
#define	MASK_DONOT_PRINT		0x010000	/*  65536 : Empeche l'affichage par PRINT avant et apres un ASK lorsque ASK COLOUR l'aura fait */
#define	MASK_DETECT_EXT_EV		0x020000	/* 131072 : Permet la detection des evenements souris par ON EXTERN EVENT */
#define	MASK_EXT_EV_NEXT		0x040000	/* 262144 : Permet de passer a l'instruction suivante lors de la capture d'evenements avec ON EXTERN EVENT */
#define	MASK_IGNORE_KBD			0x080000	/* 524288 : Inutilise. Permet d'ignorer les evenements clavier avec ON EXTERN EVENT */
#define	MASK_SHIFT_LEFT  		0x100000	/* 1048576 : Inutilise sous Win. Si les masques MASK_ACTIV_JUMP_ANY, MASK_KEEP_DATA et MASK_DONOT_TRUNK sont actifs, provoque le deplacement du curseur vers la gauche */
#endif
/* #BG 21/04/20 ASK VIRTUAL KBD */
#define	MASK_VIRT_KBD			0x200000	/* 2097152 : Permet au ASK de traiter un caractere emis par EVENT via un clavier virtuel ABAL */
											/*          Ce masque est incompatible avec les masques MASK_ACTIV_JUMP_ANY, MASK_KEEP_DATA, MASK_DONOT_TRUNK et MASK_CURSOR_END, qu'il remplace en quelque sorte */

#endif	/* _EXMASK_H */
	/* --------- */
