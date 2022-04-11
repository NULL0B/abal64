/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : Tous
 *	Fichier : EXCEP.H
 *	Version : 1.1a
 *	Date    : 25/05/93
 *	Systeme : Windows 3/NT
 *
 *	Traitement des exceptions
 *
 *	[Definitions privees]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	05/01/93 : Debut du codage
 *
 */

#ifndef __EXCEP_H__
#define __EXCEP_H__


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES MESSAGES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifndef __VERBOSE_ASSERT__

#define	TXT_PRECOND	"Precondition"
#define	TXT_POSTCOND	"Postcondition"
#define TXT_INVARIANT	"Invariant"
#define TXT_CHECK	"Controle"
#define TXT_NULLPTR	"Pointeur null"
#define TXT_UNKNOWN	"Inconnue"
#define TXT_CHECKEXPR	"Cf sources"

#endif


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES DONNEES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

C_SLIST FAR *ExceptionList;
C_SLIST FAR *ExceptionContextList;



/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTIONS DES PRIMITIVES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef LINT_ARGS
extern void AlertBox( BYTE FAR * );
#else
extern void AlertBox();
#endif

#endif  /* __EXCEP_H__ */

