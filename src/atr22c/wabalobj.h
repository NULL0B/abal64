/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1994
 *	Module  : Tous
 *	Fichier : WABALOBJ.H
 *	Version : 1.1a
 *	Date    : 20/10/94
 *	Systeme : Tous
 *
 *	Generalites sur les classes et objets du projet ABAL
 *
 *	[Definitions]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	04/12/92 : Debut du codage
 *	20/10/94 : changement definition OBCREATE
 *
 */

#ifndef __ABALOBJ_H__
#define __ABALOBJ_H__

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		GESTION DES ASSERTIONS - MODE NORMAL		     	     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef __NO_DEBUG__

#define	VAL_PRECOND	1
#define	VAL_POSTCOND	2
#define VAL_INVARIANT	3
#define VAL_CHECK	4
#define VAL_NULLPTR	5

#define PRECOND(x)	NOEFFECT
#define POSTCOND(x)	NOEFFECT
#define INVARIANT(x)	NOEFFECT
#define CHECK(x)	NOEFFECT
#define CHECKNULL(x)	NOEFFECT
#define UCHECK(x)	((x) ? NOEFFECT : AssViol(VAL_CHECK,x))
#define UCHECKNULL(x)	(((void FAR *)x != (void FAR *)NULL) ? NOEFFECT : AssViol(VAL_NULLPTR,x))


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		GESTION DES ASSERTIONS - MODE DEBUG		     	     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#else	/* __NO_DEBUG__ */

#ifdef __VERBOSE_ASSERT__

#define	TXT_PRECOND	"Precondition"
#define	TXT_POSTCOND	"Postcondition"
#define TXT_INVARIANT	"Invariant"
#define TXT_CHECK	"Controle"
#define TXT_NULLPTR	"Pointeur null"

#define PRECOND(x)	((x) ? NOEFFECT : AssViol(TXT_PRECOND,x))
#define POSTCOND(x)	((x) ? NOEFFECT : AssViol(TXT_POSTCOND,x))
#define INVARIANT(x)	((x) ? NOEFFECT : AssViol(TXT_INVARIANT,x))
#define CHECK(x)	((x) ? NOEFFECT : AssViol(TXT_CHECK,x))
#define CHECKNULL(x)	(((void FAR *)x != (void FAR *)NULL) ? NOEFFECT : AssViol(TXT_NULLPTR,x))
#define UCHECK(x)	((x) ? NOEFFECT : AssViol(TXT_CHECK,x))
#define UCHECKNULL(x)	(((void FAR *)x != (void FAR *)NULL) ? NOEFFECT : AssViol(TXT_NULLPTR,x))

#else

#define	VAL_PRECOND	1
#define	VAL_POSTCOND	2
#define VAL_INVARIANT	3
#define VAL_CHECK	4
#define VAL_NULLPTR	5

#define PRECOND(x)	((x) ? NOEFFECT : AssViol(VAL_PRECOND,x))
#define POSTCOND(x)	((x) ? NOEFFECT : AssViol(VAL_POSTCOND,x))
#define INVARIANT(x)	((x) ? NOEFFECT : AssViol(VAL_INVARIANT,x))
#define CHECK(x)	((x) ? NOEFFECT : AssViol(VAL_CHECK,x))
#define CHECKNULL(x)	(((void FAR *)x != (void FAR *)NULL) ? NOEFFECT : AssViol(VAL_NULLPTR,x))
#define UCHECK(x)	((x) ? NOEFFECT : AssViol(VAL_CHECK,x))
#define UCHECKNULL(x)	(((void FAR *)x != (void FAR *)NULL) ? NOEFFECT : AssViol(VAL_NULLPTR,x))

#endif
#endif	/* __NO_DEBUG__ */


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			GESTION DES OBJETS			     	     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define OBCREATE(x,y)	{ x = (y FAR *)Xmalloc(sizeof(y));\
			}

#define TABLECREATE(x,y,n)	{ x = (y FAR *)Xmalloc(sizeof(y)*n);\
			  UCHECKNULL(x); \
			}

#define OBDELETE(x)	{ UCHECKNULL(x); \
			  Xfree((void FAR *)x); \
			}

#endif	/* __ABALOBJ_H__ */
