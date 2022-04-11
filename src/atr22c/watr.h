/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1995
 *	Module  : ATR
 *	Fichier : WATR.H
 *	Version : 1.1a
 *	Date    : 10/08/96
 *	Systeme : Windows 3/NT
 *
 *	Demarrage du traducteur
 *
 *	[Definitions privees]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	cf. WBANN.C
 *
 */

#ifndef __WATR_H__
#define __WATR_H__

#include "ctdiag.h"
#include "ctCarSet.h"
#include "longName.h"
#include "abalcico.h"

lnHandle LongNameContext;


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES DONNEES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

static BYTE Arguments[256];
static BOOL TraductionEnCours;
static BOOL AbortRequired;
extern int nberr, nbwarn;
extern WORD OptIdra;
extern ctDiagnostic Diag;
extern ctCharSetConversion ConversionTable;

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES PRIMITIVES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* Primitives privees */

static LRESULT OnWmClose( HWND,UINT,WPARAM,LPARAM );
static LRESULT OnWmDestroy( HWND,UINT,WPARAM,LPARAM );
extern int majn(int,char **);
extern int asyncab(int);


/* Primitives publiques */

//int InitApp( WNDCLASS FAR *,HINSTANCE,LPSTR,int );
//int InitInstance( HWND FAR *,HINSTANCE,LPSTR,int );
//LRESULT AppMain( HWND,UINT,WPARAM,LPARAM );
#ifdef WIN32
void Epoch(BYTE *);
#endif

#endif  /* __WATR_H__ */
