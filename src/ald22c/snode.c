/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : Tous
 *	Fichier : SNODE.C
 *	Version : 1.1a
 *	Date    : 07/01/93
 *	Systeme : Tous
 *
 *	Pseudoclasse : noeud de liste chainee simple
 *
 *	[Interface - Implementation]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	03/12/92 : Debut du codage
 *
 */

#include "aldtype.h"
#if 0 
// JPH
	#define __PORTABLE__			/* Source portable */

	/* Inclusions importees */

	#include "wabaldef.h"


	/* Inclusions exportees et privees */

	#define PRIMITIVE GLOBAL
#endif

#include "pubsnode.h"
#include "snode.h"


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DE L'INTERFACE			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * Un noeud de liste chainee simple comporte les informations :
 *	- chainage sur le noeud suivant
 *	- pointeur sur l'element "contenu"
 * Le contenu est quelconque, et n'est pas controle ici.
 * Cette structure de donnees est decrite dans le type C_SNODE.
 *
 * Des operations sont definies sur les noeuds :
 *	- SnodeCreate  : alloue un noeud et l'initialise a zero
 *	- SnodeDelete  : supprimer le noeud
 *	- SnodeGet     : recupere un pointeur sur le contenu
 *	- SnodeSet     : attache un contenu
 *	- SnodeGetNext : recupere un pointeur sur le noeud suivant
 *	- SnodeSetNext : met en place le chainage vers le noeud suivant
 *
 * -------------------------------------------------------------------------- */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			FONCTIONS DE MANIPULATION			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT SnodeCreate
 *
 *	Creation d'un noeud de liste chainee simple.
 *
 *	E/ rien
 *	S/ pointeur sur le noeud cree, NULL si impossible
 *
 */
C_SNODE FAR * SnodeCreate()
{ C_SNODE FAR * noeud;

	/* Alloue de la memoire pour le noeud */
	OBCREATE(noeud,C_SNODE);
	if (noeud == (C_SNODE FAR *)NULL)
		return(noeud);

	/* Remise a zero du noeud */
	noeud->suiv = (C_SNODE FAR *)NULL;
	noeud->contenu = (void FAR *)NULL;

	return(noeud);
}

/* --------------------------------------------------------------------------
 *
 * FCT SnodeDelete
 *
 *	Suppression d'un noeud de liste chainee simple.
 *
 *	E/ pointeur sur le noeud a detruire
 *	S/ rien
 *
 */
#ifndef _OPTIMIZED_
void SnodeDelete(noeud)
C_SNODE FAR * noeud;
{
	PRECOND(noeud != (C_SNODE FAR *)NULL);

	/* Libere la memoire occupee par le noeud */
	Xfree(noeud);
}
#endif
/* --------------------------------------------------------------------------
 *
 * FCT SnodeGet
 *
 *	Recupere un pointeur sur le contenu d'un noeud.
 *
 *	E/ pointeur sur le noeud dont on veut le contenu
 *	S/ pointeur sur le contenu
 *
 */
#ifndef _OPTIMIZED_
void FAR * SnodeGet(noeud)
C_SNODE FAR * noeud;
{
	PRECOND(noeud != (C_SNODE FAR *)NULL);

	return((void FAR *)noeud->contenu);
}
#endif
/* --------------------------------------------------------------------------
 *
 * FCT SnodeSet
 *
 *	Attache un contenu a un noeud.
 *
 *	E/ pointeur sur le noeud ou on veut s'attacher
 *	   pointeur sur le contenu
 *	S/ rien
 *
 */
#ifndef _OPTIMIZED_

void SnodeSet(noeud,cont)
C_SNODE FAR * noeud;
void FAR * cont;
{
	PRECOND(noeud != (C_SNODE FAR *)NULL);

	noeud->contenu = (void FAR *)cont;
}

#endif

/* --------------------------------------------------------------------------
 *
 * FCT SnodeGetNext
 *
 *	Recupere le chainage vers le noeud suivant.
 *
 *	E/ pointeur sur le noeud dont on veut le chainage
 *	S/ pointeur sur le noeud suivant
 *
 */
#ifndef _OPTIMIZED_
C_SNODE FAR * SnodeGetNext(noeud)
C_SNODE FAR * noeud;
{
	PRECOND(noeud != (C_SNODE FAR *)NULL);

	return((C_SNODE FAR *)noeud->suiv);
}
#endif
/* --------------------------------------------------------------------------
 *
 * FCT SnodeSetNext
 *
 *	Met en place le chainage vers le noeud suivant.
 *
 *	E/ pointeur sur le noeud dont on veut modifier le chainage
 *	   pointeur sur le noeud suivant
 *	S/ rien
 *
 */
#ifndef _OPTIMIZED_
void SnodeSetNext(noeud,nsuiv)
C_SNODE FAR * noeud;
C_SNODE FAR * nsuiv;
{
	PRECOND(noeud != (C_SNODE FAR *)NULL);

	noeud->suiv = (C_SNODE FAR *)nsuiv;
}
#endif

