/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : Tous
 *	Fichier : PUBCBUF.H
 *	Version : 1.1a
 *	Date    : 19/01/93
 *	Systeme : Tous
 *
 *	Pseudoclasse : tampon circulaire
 *
 *	[Definitions publiques]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	11/01/93 : Debut du codage
 *
 */

#ifndef __PUBCBUF_H__
#define __PUBCBUF_H__

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES DONNEES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

struct _cbuf {
	WORD FAR * ptlec;		/* pointeur de lecture */
	WORD FAR * ptecr;		/* pointeur d'ecriture */
	WORD FAR * buffer;		/* pointeur sur les donnees */
	WORD nelem;			/* nombre d'elements */
};
typedef struct _cbuf C_CBUF;


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES PRIMITIVES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef LINT_ARGS

PRIMITIVE C_CBUF FAR * CbufCreate( WORD );
PRIMITIVE void CbufDelete( C_CBUF FAR * );
PRIMITIVE BOOL CbufIsEmpty( C_CBUF FAR * );
PRIMITIVE void CbufFlush( C_CBUF FAR * );
PRIMITIVE void CbufAdd( C_CBUF FAR * , WORD );
PRIMITIVE WORD CbufGet( C_CBUF FAR * );
PRIMITIVE WORD CbufPeek( C_CBUF FAR * );

#else

PRIMITIVE C_CBUF FAR * CbufCreate();
PRIMITIVE void CbufDelete();
PRIMITIVE BOOL CbufIsEmpty();
PRIMITIVE void CbufFlush();
PRIMITIVE void CbufAdd();
PRIMITIVE WORD CbufGet();
PRIMITIVE WORD CbufPeek();

#endif

#endif	/* __PUBCBUF_H__ */

