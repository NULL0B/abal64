/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : Tous
 *	Fichier : PUBNOLOG.H
 *	Version : 1.1a
 *	Date    : 10/03/93
 *	Systeme : Tous
 *
 *	Pseudoclasse : table de numeros logiques
 *
 *	[Definitions publiques]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	16/12/92 : Debut du codage
 *
 */

#ifndef __PUBNOLOG_H__
#define __PUBNOLOG_H__

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES DONNEES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

struct _nolog {
	WORD nbits;
	WORD nbytes;
	BYTE FAR *tnl;
};
typedef struct _nolog C_NOLOG;


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DEFINITIONS DES CONSTANTES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define ISFULL	0xFFFF


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES PRIMITIVES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef LINT_ARGS

PRIMITIVE C_NOLOG FAR * NologCreate(WORD);
PRIMITIVE void NologDelete(C_NOLOG FAR *);
PRIMITIVE WORD NologAllocate(C_NOLOG FAR *);
PRIMITIVE void NologLiberate(C_NOLOG FAR *,WORD);
PRIMITIVE BOOL NologIsUsed(C_NOLOG FAR *,WORD);

#else

PRIMITIVE C_NOLOG FAR * NologCreate();
PRIMITIVE void NologDelete();
PRIMITIVE WORD NologAllocate();
PRIMITIVE void NologLiberate();
PRIMITIVE BOOL NologIsUsed();

#endif

#endif	/* __PUBNOLOG_H__ */

