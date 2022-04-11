/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : CICO
 *	Fichier : PUBWCICO.H
 *	Version : 1.1a
 *	Date    : 01/03/93
 *	Systeme : Tous
 *
 *	Interface avec la peripherie caractere
 *
 *	[Noyau CICO - Definitions publiques]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	19/01/93 : Debut du codage
 *
 */

#ifndef __PUBWCICO_H__
#define __PUBWCICO_H__

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DEFINITIONS GENERALES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define TAMPON		0		/* numero peripherique tampon 	*/
#define ECRAN		1		/* numero peripherique ecran 	*/

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES DONNEES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

PRIMITIVE EXAWORD err_val;			/* variable d'erreur */
PRIMITIVE int	prndest;			/* support implicite */
PRIMITIVE EXAWORD prnfid;			/* handle du support */
PRIMITIVE BYTE FAR * prnptr;			/* pointeur zone de reception */
PRIMITIVE EXAWORD prnleng;			/* longueur zone de reception */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES PRIMITIVES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

PRIMITIVE WORD x_kbhit(void);
PRIMITIVE WORD x_getch(void);
PRIMITIVE void x_KbdMode(WORD);
PRIMITIVE WORD prfo(WORD , BYTE FAR * , WORD);
PRIMITIVE WORD lcfo(WORD , BYTE FAR * , WORD);

PRIMITIVE void x_putch(WORD);
PRIMITIVE void x_cprintf(BYTE FAR *);
PRIMITIVE void x_bstart(void);
PRIMITIVE void x_bflush(void);
PRIMITIVE void pos(WORD , WORD);
PRIMITIVE void atb(WORD);
PRIMITIVE void backgr(WORD);
PRIMITIVE void foregr(WORD);
PRIMITIVE void x_clear(void);
PRIMITIVE void x_bell(void);
PRIMITIVE WORD x_lin(void);
PRIMITIVE WORD x_col(void);

PRIMITIVE WORD mima(WORD , WORD);
PRIMITIVE WORD conf(WORD);
PRIMITIVE WORD x_npos(void);

PRIMITIVE WORD im_open(BYTE FAR * , WORD);
PRIMITIVE void im_close(void);

PRIMITIVE void initerm(void);
PRIMITIVE void finterm(WORD);

#endif /* __PUBWCICO_H__ */
