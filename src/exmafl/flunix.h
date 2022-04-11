/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1997
 *	Module  : EXA
 *	Fichier : FLUNIX.H
 *	Version : 1.1b
 *	Date    : 10/04/97
 *	Systeme : Unix
 *
 *	Methodes d'acces
 *
 *	[DLL acces direct + sequentiel - Definitions privees]
 *
 */

#ifndef __FLUNIX_H__
#define __FLUNIX_H__

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DESCRIPTION DES PRIMITIVES	(LINT_ARGS)		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef LINT_ARGS 

static HNLOG fl_xopen(CPTR,S32,S32,S16PTR);
static HNLOG fl_xcreate(CPTR,S32,S32,S16PTR);
static S16 fl_xunlink(CPTR);
static void cmemmove(BPTR,BPTR,U16);
static S16 ErrorConvBib(S16);
static U16 AbalLock(EHANDLE,LSEEKTYPE,U32);
static U16 AbalUnlock(EHANDLE,LSEEKTYPE,U32);
static S16 MakeCompleteName(TASKENVIRON SPTR,CPTR,CPTR);
#ifdef __DEBUG__
void TraceBegin(void);
#endif

extern void liberlox(char *);
extern Access(char *, int, int);

#else /* LINT_ARGS */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DESCRIPTION DES PRIMITIVES	(sans LINT_ARGS)	     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

static HNLOG fl_xopen();
static HNLOG fl_xcreate();
static S16 fl_xunlink();
static void cmemmove();
static S16 ErrorConvBib();
static U16 AbalLock();
static U16 AbalUnlock();
static S16 MakeCompleteName();
#ifdef __DEBUG__
void TraceBegin();
#endif

extern void liberlox();
extern Access();

#endif /* LINT_ARGS */

#endif /* __FLUNIX_H__ */
