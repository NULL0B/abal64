/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1994
 *	Module  : Tous
 *	Fichier : PUBEXCEP.H
 *	Version : 1.1a
 *	Date    : 28/07/94
 *	Systeme : Windows 3/NT
 *
 *	Traitement des exceptions
 *
 *	[Definitions publiques]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	05/01/93 : Debut du codage
 *	10/06/94 : correction affectation Current.Value dans le TRY
 *	16/06/94 : changement THROW_SAME pour remonter la cause initiale
 *	28/07/94 : compactage noms fichiers dans les assertions
 *
 */

#ifndef __PUBEXCEP_H__
#define __PUBEXCEP_H__

#include <setjmp.h>
#include <stdlib.h>

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES DONNEES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

struct _ExcContext {
	WORD Value;			/* valeur de l'exception */
	BYTE FAR * Kind;		/* type d'appelant */
	BYTE FAR * CheckExpr;		/* condition non remplie */
	BYTE FAR * CallerFilename;	/* nom fichier bloc appelant */
	WORD CallerLinenumber;		/* numero ligne bloc appelant */
	BYTE FAR * ExcFilename;		/* nom fichier exception */
	WORD ExcLinenumber;		/* numero ligne exception */
};
typedef struct _ExcContext EXCEPTION_CONTEXT;


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			MACROS DE GESTION DES EXCEPTIONS		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define Xsetjmp(x)	(WORD)setjmp(x)
#define Xlongjmp(x,y)	longjmp((x),(int)(y))

#define TRY	{ jmp_buf tx;					\
		  EXCEPTION_CONTEXT Current;			\
								\
		  _ExcPushCtx((EXCEPTION_CONTEXT FAR *)&Current,\
			      (BYTE FAR *)&ThF[0],__LINE__);	\
		  while(TRUE) {					\
			  _ExcPushLink((jmp_buf FAR *)&tx);	\
			  if (Xsetjmp(tx) == 0) {\



#define CATCH		  }                                     \
			  else {				\
				_ExcPopLink((EXCEPTION_CONTEXT FAR *)&Current);	\


#define END_CATCH		_ExcPopCtx();			\
				break;				\
			  }					\
			  _ExcPopBoth();			\
			  break;				\
		  }						\
		}



#define RETRY		continue;

#define THROW(x)	_ExcThrow(x,(BYTE FAR *)&ThF[0],__LINE__);

#define THROW_SAME	_ExcThrow(Current.Value,Current.ExcFilename,Current.ExcLinenumber);


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			MACROS DE GESTION DES ASSERTIONS		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef __VERBOSE_ASSERT__
#define AssViol(x,y)	(_ExcSetAndThrow((BYTE FAR *)x,(BYTE FAR *)#y,(BYTE FAR *)&ThF[0],(WORD)__LINE__))
#else
#define AssViol(x,y)	(_ExcSetAndThrow(x,(BYTE FAR *)&ThF[0],(WORD)__LINE__))
#endif


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTIONS DES PRIMITIVES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef LINT_ARGS

PRIMITIVE void InitException( void );
PRIMITIVE void EndException( void );
PRIMITIVE void _ExcThrow( WORD,BYTE FAR *,WORD );
PRIMITIVE void _ExcPushCtx( EXCEPTION_CONTEXT FAR *,BYTE FAR *,WORD );
PRIMITIVE void _ExcSetCtx( BYTE FAR *,BYTE FAR * );
PRIMITIVE void _ExcPushLink( jmp_buf FAR * );
PRIMITIVE void _ExcPopLink( EXCEPTION_CONTEXT FAR * );
PRIMITIVE void _ExcPopCtx( void );
PRIMITIVE void _ExcPopBoth( void );
#ifdef __VERBOSE_ASSERT__
PRIMITIVE void _ExcSetAndThrow( BYTE FAR *,BYTE FAR *,BYTE FAR *,WORD );
#else
PRIMITIVE void _ExcSetAndThrow( WORD,BYTE FAR *,WORD );
#endif

#else

PRIMITIVE void InitException();
PRIMITIVE void EndException();
PRIMITIVE void _ExcThrow();
PRIMITIVE void _ExcPushCtx();
PRIMITIVE void _ExcSetCtx();
PRIMITIVE void _ExcPushLink();
PRIMITIVE void _ExcPopLink();
PRIMITIVE void _ExcPopCtx();
PRIMITIVE void _ExcPopBoth();
PRIMITIVE void _ExcSetAndThrow();

#endif

#endif  /* __PUBEXCEP_H__ */
