/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : Tous
 *	Fichier : SLIST.C
 *	Version : 1.1a
 *	Date    : 04/01/93
 *	Systeme : Tous
 *
 *	Pseudoclasse : liste chainee simple
 *
 *	[Interface - Implementation]
 *	
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	03/12/92 : Debut du codage
 *	21/04/93 : Ajout de la fonction SlistCount
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

#include "pubslist.h"
#include "slist.h"


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DE L'INTERFACE			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * Une liste chainee simple comporte les informations :
 *	- chainage sur le premier noeud
 *	- chainage sur le noeud courant
 *	- compteur de noeuds de la liste
 * Les noeuds ont un contenu quelconque.
 * Cette structure de donnees est decrite dans le type C_SLIST.
 *
 * Des operations sont definies sur les listes :
 *	- SlistCreate        : alloue une liste et l'initialise a zero
 *	- SlistDelete        : supprimer la liste
 *	- SlistIsEmpty       : regarde si la liste est vide
 *	- SlistAddHead       : insere un noeud en tete
 * 	- SlistAddCurrent    : insere un noeud a la position courante
 *	- SlistAddTail       : insere un noeud en queue
 *	- SlistRemoveHead    : ote le noeud de tete
 *	- SlistRemoveTail    : ote le noeud de queue
 *	- SlistRemoveCurrent : ote le noeud courant
 *	- SlistGetNext       : se positionne et recupere le noeud suivant
 *	- SlistGetPrev       : se positionne et recupere le noeud precedent
 *	- SlistGetCurrent    : recupere le noeud courant
 *	- SlistGetHead       : recupere le noeud de tete
 *	- SlistRewind	     : se positionne au debut de la liste
 *	- SlistCount	     : Retourne le nombre d'element dans la liste
 *
 * -------------------------------------------------------------------------- */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DEFINITION DE L'INVARIANT DE CLASSE			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* Si la liste est vide, le nombre d'elements est nul
 * et reciproquement.
 * Le nombre d'element doit etre positif ou nul.
 */
#define CLASS_INVARIANT		{ \
		INVARIANT(liste->nodecount >= 0); \
	}
//		INVARIANT(((liste->nodecount == 0) && (liste->head == (C_SNODE FAR *)NULL)) || \
//			  ((liste->nodecount != 0) && (liste->head != (C_SNODE FAR *)NULL))); \

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			FONCTIONS DE MANIPULATION			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT SlistCreate
 *
 *	Creation d'une liste chainee simple.
 *
 *	E/ rien
 *	S/ pointeur sur la liste cree, NULL si impossible
 *
 */
C_SLIST FAR * SlistCreate()
{ C_SLIST FAR * liste;

	/* Alloue de la memoire pour la liste */
	OBCREATE(liste,C_SLIST);
	if (liste == (C_SLIST FAR *)NULL)
		return(liste);

	/* Remise a zero de la liste */
	liste->head = (C_SNODE FAR *)NULL;
	liste->current = (C_SNODE FAR *)NULL;
	liste->nodecount = 0;

	CLASS_INVARIANT;

	return(liste);
}

/* --------------------------------------------------------------------------
 *
 * FCT SlistDelete
 *
 *	Suppression d'une liste chainee simple.
 *
 *	E/ pointeur sur la liste a detruire
 *	S/ rien
 *
 */
#ifndef _OPTIMIZED_
void SlistDelete(liste)
C_SLIST FAR * liste;
{
	PRECOND(liste != (C_SLIST FAR *)NULL);
	CLASS_INVARIANT;

	/* Libere la memoire occupee par la liste */
	Xfree(liste);
}
#endif
/* --------------------------------------------------------------------------
 *
 * FCT SlistIsEmpty
 *
 *	Teste si une liste est vide
 *
 *	E/ pointeur sur la liste a tester
 *	S/ TRUE si la liste est vide
 *
 */
#ifndef _OPTIMIZED_
BOOL SlistIsEmpty(liste)
C_SLIST FAR * liste;
{
	/* La liste doit exister */
	PRECOND(liste != (C_SLIST FAR *)NULL);
	CLASS_INVARIANT;

	return((liste->nodecount == 0) ? TRUE : FALSE);
}
#endif
/* --------------------------------------------------------------------------
 *
 * FCT SlistAddHead
 *
 *	Insere un noeud en tete de liste chainee simple.
 *
 *	E/ pointeur sur la liste dans laquelle inserer
 *	   pointeur sur le noeud a inserer
 *	S/ rien
 *
 */
void SlistAddHead(liste,noeud)
C_SLIST FAR * liste;
C_SNODE FAR * noeud;
{
	/* La liste et le noeud doivent exister */
	PRECOND(liste != (C_SLIST FAR *)NULL);
	PRECOND(noeud != (C_SNODE FAR *)NULL);
	CLASS_INVARIANT;

	/* L'insertion en tete est facile puisque les donnees
	 * de la liste comportent un pointeur vers la tete.
	 */
	SnodeSetNext(noeud,liste->head);
	liste->head = (C_SNODE FAR *)noeud;
	liste->nodecount++;

	CLASS_INVARIANT;
}

/* --------------------------------------------------------------------------
 *
 * FCT SlistAddTail
 *
 *	Insere un noeud en fin de liste chainee simple.
 *
 *	E/ pointeur sur la liste dans laquelle inserer
 *	   pointeur sur le noeud a inserer
 *	S/ rien
 *
 */
void SlistAddTail(liste,noeud)
C_SLIST FAR * liste;
C_SNODE FAR * noeud;
{ C_SNODE FAR * tnode;
  C_SNODE FAR * nnode;

	/* La liste et le noeud doivent exister */
	PRECOND(liste != (C_SLIST FAR *)NULL);
	PRECOND(noeud != (C_SNODE FAR *)NULL);
	CLASS_INVARIANT;

	/* Si la liste est vide, inserer en fin equivaut a
	 * inserer en tete.
	 */
	if (liste->head == (C_SNODE FAR *)NULL) {
		SlistAddHead(liste,noeud);
		return;
	}

	/* Sinon, il faut parcourir la liste jusqu'au dernier element.
	 * On peut optimiser le parcours en partant de l'element
	 * courant de la liste qui a toutes les chances de ne
	 * pas etre le premier de la liste.
	 */
	if (liste->current == (C_SNODE FAR *)NULL)
		tnode = liste->head;
	else
		tnode = liste->current;

	/* Tant que l'on n'est pas en fin de liste... */
	while ((nnode = SnodeGetNext(tnode)) != (C_SNODE FAR *)NULL) {
		tnode = nnode;
	}

	/* Insere a cette place */
	SnodeSetNext(noeud,(C_SNODE FAR *)NULL);
	SnodeSetNext(tnode,noeud);
	liste->nodecount++;

	CLASS_INVARIANT;
}
/* --------------------------------------------------------------------------
 *
 * FCT SlistAddCurrent
 *
 *	Insere un noeud a la position courante 
 *
 *	E/ pointeur sur la liste dans laquelle inserer
 *	   pointeur sur le noeud a inserer
 *	S/ rien
 *
 */
void SlistAddCurrent(liste,noeud)
C_SLIST FAR * liste;
C_SNODE FAR * noeud;
{ 
	C_SNODE FAR * tnode;
//JPH  C_SNODE FAR * nnode;

	/* La liste et le noeud doivent exister */
	PRECOND(liste != (C_SLIST FAR *)NULL);
	PRECOND(noeud != (C_SNODE FAR *)NULL);
	CLASS_INVARIANT;

	/* Si la liste est vide, inserer en fin equivaut a
	 * inserer en tete.
	 */
	if (liste->head == (C_SNODE FAR *)NULL) {
		SlistAddHead(liste,noeud);
		return;
	}

	/* Sinon, il faut parcourir la liste jusqu'au dernier element.
	 * On peut optimiser le parcours en partant de l'element
	 * courant de la liste qui a toutes les chances de ne
	 * pas etre le premier de la liste.
	 */
	if (liste->current == (C_SNODE FAR *)NULL)
		tnode = liste->head;
	else
		tnode = liste->current;

	/* Insere a cette place */
	SnodeSetNext(noeud,SnodeGetNext( tnode ));
	SnodeSetNext(tnode,noeud);

	/* le noeud insere devient le noueud courant */
	liste->current = noeud;

	liste->nodecount++;

	CLASS_INVARIANT;
}

/* --------------------------------------------------------------------------
 *
 * FCT SlistRemoveHead
 *
 *	Supprime un noeud en tete de liste chainee simple.
 *
 *	E/ pointeur sur la liste dans laquelle supprimer
 *	S/ rien
 *
 */
void SlistRemoveHead(liste)
C_SLIST FAR * liste;
{ C_SNODE FAR * ohead;

	/* La liste doit exister et ne pas etre vide */
	PRECOND(liste != (C_SLIST FAR *)NULL);
	PRECOND(!SlistIsEmpty(liste));
	CLASS_INVARIANT;

	/* Supprimer le noeud de tete est simple... */
	ohead = liste->head;
	liste->head = SnodeGetNext(ohead);
	liste->nodecount--;

	/* Traite la suppression du noeud courant */
	if (liste->current == ohead)
		liste->current = (C_SNODE FAR *)NULL;

	CLASS_INVARIANT;
}

/* --------------------------------------------------------------------------
 *
 * FCT SlistRemoveTail
 *
 *	Supprime un noeud en fin de liste chainee simple.
 *
 *	E/ pointeur sur la liste dans laquelle supprimer
 *	S/ rien
 *
 */
void SlistRemoveTail(liste)
C_SLIST FAR * liste;
{ C_SNODE FAR * tnode;
  C_SNODE FAR * nnode;
  C_SNODE FAR * onode;


	/* La liste doit exister et ne pas etre vide */
	PRECOND(liste != (C_SLIST FAR *)NULL);
	PRECOND(!SlistIsEmpty(liste));
	CLASS_INVARIANT;

	/* Il faut deja se positionner a la fin de la liste. */
	tnode = liste->head;
	onode = (C_SNODE FAR *)NULL;

	/* Tant que l'on n'est pas en fin de liste... */
	while ((nnode = SnodeGetNext(tnode)) != (C_SNODE FAR *)NULL) {
		onode = tnode;
		tnode = nnode;
	}

	/* Mettre a jour le noeud precedent */
	if (onode == (C_SNODE FAR *)NULL)
		liste->head = onode;
	else
		SnodeSetNext(onode,(C_SNODE FAR *)NULL);

	liste->nodecount--;

	/* Traite la suppression du noeud courant */
	if (liste->current == tnode)
		liste->current = (C_SNODE FAR *)NULL;

	CLASS_INVARIANT;
}

/* --------------------------------------------------------------------------
 *
 * FCT SlistRemoveCurrent
 *
 *	Supprime le noeud courant d'une liste chainee simple.
 *
 *	E/ pointeur sur la liste dans laquelle supprimer
 *	S/ rien
 *
 */
void SlistRemoveCurrent(liste)
C_SLIST FAR * liste;
{ C_SNODE FAR * tnode;
  C_SNODE FAR * nnode;
  C_SNODE FAR * onode;


	/* La liste doit exister et ne pas etre vide,
	 * le noeud courant doit etre accessible.
	 */
	PRECOND(liste != (C_SLIST FAR *)NULL);
	PRECOND(!SlistIsEmpty(liste));
	PRECOND(liste->current != (C_SNODE FAR *)NULL);
	CLASS_INVARIANT;

	/* Il faut deja se positionner sur le noeud courant. */
	tnode = liste->head;
	onode = (C_SNODE FAR *)NULL;

	/* Tant que l'on n'y est pas... */
	while (tnode != liste->current) {
		onode = tnode;
		tnode = SnodeGetNext(tnode);
		CHECKNULL(tnode);
	}

	/* Mettre a jour le noeud precedent avec l'adresse du noeud
	 * suivant.
	 */
	nnode = SnodeGetNext(tnode);
	if (onode == (C_SNODE FAR *)NULL)
		liste->head = nnode;
	else
		SnodeSetNext(onode,nnode);
	liste->nodecount--;

	/* Traite la suppression du noeud courant */
	if (liste->current == tnode)
		liste->current = (C_SNODE FAR *)NULL;

	CLASS_INVARIANT;
}

/* --------------------------------------------------------------------------
 *
 * FCT SlistGetNext
 *
 *	Se positionne sur le noeud suivant et recupere sa valeur
 *
 *	E/ pointeur sur la liste ou chercher
 *	S/ pointeur sur le noeud suivant
 *
 */
C_SNODE FAR * SlistGetNext(liste)
C_SLIST FAR * liste;
{
	/* La liste doit exister */
	PRECOND(liste != (C_SLIST FAR *)NULL);
	CLASS_INVARIANT;

	/* Partir du debut si la notion de noeud courant n'a
	 * pas encore ete validee.
	 */
	if (liste->current == (C_SNODE FAR *)NULL)
		liste->current = liste->head;
	else {
		liste->current = SnodeGetNext(liste->current);
	}

	CLASS_INVARIANT;
	return(liste->current);
}

/* --------------------------------------------------------------------------
 *
 * FCT SlistGetPrev
 *
 *	Se positionne sur le noeud precedent et recupere sa valeur
 *
 *	E/ pointeur sur la liste ou chercher
 *	S/ pointeur sur le noeud precedent
 *
 */
C_SNODE FAR * SlistGetPrev(liste)
C_SLIST FAR * liste;
{ C_SNODE FAR *tnode;
  C_SNODE FAR *nnode;

	/* La liste doit exister */
	PRECOND(liste != (C_SLIST FAR *)NULL);
	CLASS_INVARIANT;

	/* Si la notion de noeud courant n'a pas encore ete validee,
	 * c'est qu'il n'y a pas de precedent.
	 * Il en est de meme si le noeud courant est la tete de liste.
	 */
	if ((liste->current == (C_SNODE FAR *)NULL) ||
	    (liste->current == liste->head))
		return((C_SNODE FAR *)NULL);

	/* Il faut deja se positionner sur le noeud courant en
	 * balayant la liste depuis le debut.
	 */
	tnode = liste->head;

	/* Tant que l'on n'y est pas... */
	while ((nnode = SnodeGetNext(tnode)) != liste->current) {
		tnode = nnode;
	}

	liste->current = tnode;

	CLASS_INVARIANT;
	return(tnode);
}

/* --------------------------------------------------------------------------
 *
 * FCT SlistGetCurrent
 *
 *	Recupere le noeud courant d'une liste chainee simple.
 *
 *	E/ pointeur sur la liste ou chercher
 *	S/ pointeur sur le noeud courant
 *
 */
#ifndef _OPTIMIZED_
C_SNODE FAR * SlistGetCurrent(liste)
C_SLIST FAR * liste;
{
	/* La liste doit exister */
	PRECOND(liste != (C_SLIST FAR *)NULL);
	CLASS_INVARIANT;

	return(liste->current);
}
#endif

/* --------------------------------------------------------------------------
 *
 * FCT SlistGetHead
 *
 *	Recupere le noeud de tete d'une liste chainee simple.
 *
 *	E/ pointeur sur la liste ou chercher
 *	S/ pointeur sur le noeud de tete
 *
 */
C_SNODE FAR * SlistGetHead(liste)
C_SLIST FAR * liste;
{
	/* La liste doit exister */
	PRECOND(liste != (C_SLIST FAR *)NULL);
	CLASS_INVARIANT;

	return(liste->head);
}

/* --------------------------------------------------------------------------
 *
 * FCT SlistRewind
 *
 *	Se positionne en tete de liste.
 *
 *	E/ pointeur sur la liste ou chercher
 *	S/ rien
 *
 */
#ifndef _OPTIMIZED_
void SlistRewind(liste)
C_SLIST FAR * liste;
{
	/* La liste doit exister */
	PRECOND(liste != (C_SLIST FAR *)NULL);
	CLASS_INVARIANT;

	liste->current = (C_SNODE FAR *)NULL;
}
#endif
/* --------------------------------------------------------------------------
 *
 * FCT SlistCount
 *
 *	Retourne le nombre d'element dans la liste
 *
 *	E/ liste
 *	S/ le nombre d'element 
 *
 */
WORD SlistCount( liste )
C_SLIST FAR * liste;
{
	
	/* La liste doit exister */


	PRECOND(liste != (C_SLIST FAR *)NULL);
	CLASS_INVARIANT;

	return( liste->nodecount );
}

/* --------------------------------------------------------------------------
 *
 * FCT SlistSetCurrent
 *
 *	Determine le nouveau noeud courrant d'une liste
 *
 *	E/ liste, noeud
 *	S/ rien
 *
 */
#ifndef _OPTIMIZED_
void SlistSetCurrent( liste, noeud )
C_SLIST FAR * liste;
C_SNODE FAR * noeud;
{

	/* La liste doit exister */
	PRECOND(liste != (C_SLIST FAR *)NULL);
	CLASS_INVARIANT;

	liste->current = noeud;

}
#endif

