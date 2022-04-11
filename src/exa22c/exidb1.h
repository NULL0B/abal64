/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDB1 - C				*/
/*		Date 	:	09/11/1988				*/
/*									*/
/*----------------------------------------------------------------------*/
#define DEBUGGER

#include "exdebug.h"
#include "exctype.h"
#include "exmnem.h"


/*
 *	UNIX Signal management
 *	----------------------
 */

#ifdef UNIX
#include <signal.h>	/* Definitions for signal trapping routines */
typedef int (*pf)();
static pf sysf[20];
UBINAIR	siggot;
#endif

extern	UBINAIR	adr_npr;	/* Secteur Noms des Procedures	*/
extern	UBINAIR	trace;		/* Variable de Trace		*/

UBINAIR	brayk,permdb,trapdex;

UBINAIR	dbpiege[64];		/* Trap offset Values			*/
UBINAIR	dbsegtrap[64];		/* Trap Segment Values			*/
UBINAIR	dbtraptyp[64];		/* Trap Types 0 -> Segment 1 -> Proc    */
UBINAIR	dbpile[512];
UBINAIR	dbpilep;

/*	Gestion des variables en observation		*/
/*	------------------------------------		*/

UBINAIR	watchdex;		/* Watch counter			*/
UBINAIR	watchmat[16];		/* Watch matrix				*/
UBINAIR	watchind[16];		/* 1st Index				*/
UBINAIR	watchand[16];		/* 2nd index				*/
UBINAIR	watchtyp[16];		/* Type de Variable			*/
UBINAIR	watchgod[16];		/* Procedure ou Segment (for locales )	*/

#ifdef MODEL_DBGT

/*	Gestion des options Etendus			*/
/*	---------------------------			*/

UBINAIR	ritewatch;		/* Observation en ecriture seulement 	*/
UBINAIR	QuantH[128];		/* Quanta analysis High counter		*/
UBINAIR	QuantL[128];		/* Quanta analysis Low counter		*/ 
UBINAIR	CodeHalt;		/* Tcode to halt execution		*/

/*	Gestion du fichier Liste (Fnom-L)	*/
/*	---------------------------------	*/
extern	void	idb_listgogo();
extern	UBINAIR	idb_flopen();
extern	void	idb_flcose();
extern	UBINAIR	idb_fgetc();
extern	UBINAIR	idb_bgetc();
extern	void	prnlignes();
#endif

UBINAIR	dberreur();
UBINAIR	findkode();
void showword();
void dbmotor();
void dbstep();
UBINAIR	dbswit();
UBINAIR checks();
UBINAIR	teststop();
UBINAIR	testtrap();
EXBPTR	viewcode();
EXBPTR	viewcodb();
UBINAIR	setkurs();
EXBPTR	varbname();
EXBPTR	oppsh();
EXBPTR	uoppsh();
EXBPTR	iofvisi();
EXBPTR	ioargs();
EXBPTR	fngf();
EXBPTR	dbug_clp();
EXBPTR	bibwork();
EXBPTR	affunc();
UBINAIR	getreg();
EXBPTR	affreg();
UBINAIR	getint();
UBINAIR	gethint();
EXBPTR	affint();
UBINAIR	getcon();
EXBPTR	affcon();
UBINAIR getett();
EXBPTR	affett();
UBINAIR	getvarb();
EXBPTR	affvarb();
UBINAIR	clp_aff();
UBINAIR	varlook();
UBINAIR	varbvalu();
UBINAIR	varbtab();
void	helpscr();
void	itoxxxx();

/*	Procedure Name Management Functions	*/
/*	-----------------------------------	*/

extern	UBINAIR	InitNomProc();
extern	void	LibNomProc();
extern	void	AffProcName();
extern	UBINAIR	ProcNumb();

#ifndef UNIX
UBINAIR	nametest( EXBPTR );
UBINAIR thisvarb(UBINAIR,UBINAIR,UBINAIR);
#else
UBINAIR	nametest();
UBINAIR thisvarb();
#endif

#ifdef ABALPS
#include "exesc.c"
#endif
