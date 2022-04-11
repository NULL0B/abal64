/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1994
 *	Module  : Tous
 *	Fichier : PUBSLIST.H
 *	Version : 1.1a
 *	Date    : 20/10/94
 *	Systeme : Tous
 *
 *	Pseudoclasse : liste chainee simple
 *
 *	[Definitions publiques]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	cf. SLIST.C
 *
 */

#include "pubsnode.h"

#ifndef __PUBSLIST_H__
#define __PUBSLIST_H__

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES DONNEES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

struct _slist {
	C_SNODE FAR * head;
	C_SNODE FAR * current;
	SWORD nodecount;
};
typedef struct _slist C_SLIST;


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES PRIMITIVES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef LINT_ARGS
	PRIMITIVE C_SLIST FAR * SlistCreate(void);
	PRIMITIVE void SlistAddHead(C_SLIST FAR * , C_SNODE FAR *);
	PRIMITIVE void SlistAddTail(C_SLIST FAR * , C_SNODE FAR *);
	PRIMITIVE void SlistRemoveHead(C_SLIST FAR *);
	PRIMITIVE void SlistRemoveTail(C_SLIST FAR *);
	PRIMITIVE void SlistRemoveCurrent(C_SLIST FAR *);
	PRIMITIVE C_SNODE FAR * SlistGetNext(C_SLIST FAR *);
	PRIMITIVE C_SNODE FAR * SlistGetPrev(C_SLIST FAR *);
	PRIMITIVE C_SNODE FAR * SlistGetHead(C_SLIST FAR *);
	PRIMITIVE C_SNODE FAR * SlistGetTail(C_SLIST FAR *);
	PRIMITIVE WORD SlistCount(C_SLIST FAR * liste);
	PRIMITIVE void SlistAddCurrent(C_SLIST FAR * liste,C_SNODE FAR * noeud);

	#ifndef _OPTIMIZED_
	PRIMITIVE void SlistDelete(C_SLIST FAR *);
	PRIMITIVE BOOL SlistIsEmpty(C_SLIST FAR *);
	PRIMITIVE C_SNODE FAR * SlistGetCurrent(C_SLIST FAR *);
	PRIMITIVE void SlistSetCurrent(C_SLIST FAR*,C_SNODE FAR*);
	PRIMITIVE void SlistRewind(C_SLIST FAR *);
	#endif /* _OPTIMIZED_ */

#else /* LINT_ARGS */

	PRIMITIVE C_SLIST FAR * SlistCreate();
	PRIMITIVE void SlistAddHead();
	PRIMITIVE void SlistAddTail();
	PRIMITIVE void SlistRemoveHead();
	PRIMITIVE void SlistRemoveTail();
	PRIMITIVE void SlistRemoveCurrent();
	PRIMITIVE C_SNODE FAR * SlistGetNext();
	PRIMITIVE C_SNODE FAR * SlistGetPrev();
	PRIMITIVE C_SNODE FAR * SlistGetHead();
	PRIMITIVE C_SNODE FAR * SlistGetTail();
	PRIMITIVE WORD SlistCount();
	PRIMITIVE void SlistAddCurrent();

	#ifndef _OPTIMIZED_
	PRIMITIVE void SlistDelete();
	PRIMITIVE BOOL SlistIsEmpty();
	PRIMITIVE C_SNODE FAR * SlistGetCurrent();
	PRIMITIVE void SlistSetCurrent();
	PRIMITIVE void SlistRewind();
	#endif /* _OPTIMIZED_ */

#endif /* LINT_ARGS */


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DEFINITION DES MACROS POUR VERSION OPTIMISEE		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef _OPTIMIZED_

#define SlistDelete(liste)	Xfree(liste)
#define SlistIsEmpty(liste)	((((C_SLIST FAR *)liste)->nodecount == 0) ? TRUE : FALSE)
#define SlistGetCurrent(liste)	(C_SNODE FAR *)(((C_SLIST FAR *)liste)->current)
#define SlistSetCurrent(l,n)	((C_SLIST FAR *)l)->current = (C_SNODE FAR *)n
#define SlistRewind(liste)	SlistSetCurrent(liste,NULL)

#endif /* _OPTIMIZED_ */

#endif	/* __PUBSLIST_H__ */
