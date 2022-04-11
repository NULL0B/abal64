/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1994
 *	Module  : Tous
 *	Fichier : PUBSNODE.H
 *	Version : 1.1a
 *	Date    : 20/10/94
 *	Systeme : Tous
 *
 *	Pseudoclasse : noeud de liste chainee simple
 *
 *	[Definitions publiques]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	cf. SNODE.C
 *
 */
#define  _OPTIMIZED_	

#ifndef __PUBSNODE_H__
#define __PUBSNODE_H__

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES DONNEES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

struct _snode {
	struct _snode FAR * suiv;
	void FAR * contenu;
};
typedef struct _snode C_SNODE;


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES PRIMITIVES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef LINT_ARGS

PRIMITIVE C_SNODE FAR * SnodeCreate(void);
#ifndef _OPTIMIZED_
PRIMITIVE void SnodeDelete(C_SNODE FAR *);
PRIMITIVE void FAR * SnodeGet(C_SNODE FAR *);
PRIMITIVE void SnodeSet(C_SNODE FAR *,void FAR *);
PRIMITIVE C_SNODE FAR * SnodeGetNext(C_SNODE FAR *);
PRIMITIVE void SnodeSetNext(C_SNODE FAR *,C_SNODE FAR *);
#endif /* _OPTIMIZED_ */

#else /* LINT_ARGS */

PRIMITIVE C_SNODE FAR * SnodeCreate();
#ifndef _OPTIMIZED_
PRIMITIVE void SnodeDelete();
PRIMITIVE void FAR * SnodeGet();
PRIMITIVE void SnodeSet();
PRIMITIVE C_SNODE FAR * SnodeGetNext();
PRIMITIVE void SnodeSetNext();
#endif /* _OPTIMIZED */

#endif /* LINT_ARGS */


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DEFINITION DES MACROS POUR VERSION OPTIMISEE		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef _OPTIMIZED_

#define SnodeDelete(noeud)	Xfree(noeud)
#define SnodeGet(noeud)		(((C_SNODE FAR *)noeud)->contenu)
#define SnodeSet(noeud,cont)	((C_SNODE FAR *)noeud)->contenu = (void FAR *)cont
#define SnodeGetNext(noeud)	(C_SNODE FAR *)(((C_SNODE FAR *)noeud)->suiv)
#define SnodeSetNext(noeud,ns)	((C_SNODE FAR *)noeud)->suiv = (C_SNODE FAR *)ns

#endif /* _OPTIMIZED_ */

#endif	/* __PUBSNODE_H__ */
