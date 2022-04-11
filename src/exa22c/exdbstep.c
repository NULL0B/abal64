/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBSTEP - C				*/
/*		Version	:	1.4c / 2.1a				*/
/*		Date 	:	12/08/1992				*/
/*									*/
/*----------------------------------------------------------------------*/
#define DEBUGGER
#define	EXDBSTEPC

#include "exdebug.h"
				/* ---------------------------- */
EXTERN	EXAWORD	StackHold;	/* Stack Base for Gosubs	*/
EXTERN	EXAWORD	adr_npr;	/* Secteur Noms des Procedures	*/
EXTERN	EXAWORD	trace;		/* Variable de Trace		*/
EXTERN	EXAWORD	ExQui;		/* Motor Re-entrance Level	*/
EXTERN	EXAWORD	StopStatus;	/* Stop Status Flag 1 == TRUE	*/
EXTERN	EXAWORD	brayk,permdb;
EXTERN	BPTR	TalkPtr[];	/* Message Pointers		*/
EXTERN	EXAWORD	DbWindow;	/* Debugg Window Active			*/
EXTERN	EXAWORD	ExWindow;	/* Executeur Window State		*/

EXTERN	EXAWORD	DebugAssign;
EXTERN	EXAWORD	AssignBreak;

/*	Gestion des variables en observation		*/
/*	------------------------------------		*/
EXTERN	EXAWORD	pushtop;		/* Push Stack Control			*/
EXTERN	EXAWORD	pushhold;		/* Push Stack Control			*/

EXTERN	EXAWORD	watchdex;		/* Watch counter			*/
EXTERN	EXAWORD	watchmat[16];		/* Watch matrix				*/
EXTERN	EXAWORD	watchind[16];		/* 1st Index				*/
EXTERN	EXAWORD	watchand[16];		/* 2nd index				*/
EXTERN	EXAWORD	watchtyp[16];		/* Type de Variable			*/
EXTERN	EXAWORD	watchgod[16];		/* Procedure ou Segment (for locales )	*/

/*	Gestion des options Etendus			*/
/*	---------------------------			*/

EXTERN	EXAWORD	ritewatch;		/* Observation en ecriture seulement 	*/
EXTERN	EXAWORD	QuantH[128];		/* Quanta analysis High counter		*/
EXTERN	EXAWORD	QuantL[128];		/* Quanta analysis Low counter		*/ 
EXTERN	EXAWORD	CodeHalt;		/* Tcode to halt execution		*/

#ifndef UNIX

/*	Gestion du fichier Liste (Fnom-L)	*/
/*	---------------------------------	*/

EXTERN	EXAWORD	idb_listgogo(VOID);
EXTERN	EXAWORD	idb_flopen(VOID);
EXTERN	VOID	idb_flclose(VOID);
EXTERN	EXAWORD	idb_fgetc(VOID);
EXTERN	EXAWORD	idb_bgetc(VOID);
EXTERN	VOID	prnlignes(EXAWORD,EXAWORD);

EXAWORD	nametest( BPTR,EXAWORD);
EXAWORD	thisvarb(EXAWORD,EXAWORD,EXAWORD);
EXAWORD	dberreur(BPTR);
VOID	showword(EXAWORD,EXAWORD);
VOID	dbmotor(VOID);
VOID	dbstep(VOID);
EXAWORD	dbswit(VOID);
EXAWORD	checks(EXAWORD);
EXAWORD	teststop(VOID);
EXAWORD	setkurs(EXAWORD,EXAWORD);
BPTR	varbname(EXAWORD);
EXAWORD	getreg(VOID);
BPTR	affreg(BPTR);
EXAWORD	getint(VOID);
EXAWORD	gethint(VOID);
BPTR	affint(BPTR);
EXAWORD	getcon(VOID);
BPTR	affcon(BPTR);
EXAWORD	getett(VOID);
BPTR	affett(BPTR);
EXAWORD	getvarb(VOID);
BPTR	affvarb(BPTR);
EXAWORD	varlook(EXAWORD);
EXAWORD	varbtab(BPTR,EXAWORD);
VOID	helpscr(EXAWORD,EXAWORD);
VOID	itoxxxx(EXAWORD,BPTR,EXAWORD);

/*	Procedure Name Management Functions	*/
/*	-----------------------------------	*/

EXTERN	EXAWORD	InitNomProc(VOID);
EXTERN	VOID	LibNomProc(VOID);
EXTERN	VOID	AffProcName(EXAWORD);
EXTERN	EXAWORD	ProcNumb(BPTR);

#else

/*	Gestion du fichier Liste (Fnom-L)	*/
/*	---------------------------------	*/

EXTERN	VOID	idb_listgogo();
EXTERN	EXAWORD	idb_flopen();
EXTERN	VOID	idb_flclose();
EXTERN	EXAWORD	idb_fgetc();
EXTERN	EXAWORD	idb_bgetc();
EXTERN	VOID	prnlignes();

EXAWORD	nametest();
EXAWORD	thisvarb();
EXAWORD	dberreur();
VOID 	showword();
VOID 	dbmotor();
VOID 	dbstep();
EXAWORD	dbswit(VOID);
EXAWORD 	checks();
EXAWORD	teststop();
EXAWORD	setkurs();
BPTR	varbname();
EXAWORD	getreg();
BPTR	affreg();
EXAWORD	getint();
EXAWORD	gethint();
BPTR	affint();
EXAWORD	getcon();
BPTR	affcon();
EXAWORD 	getett();
BPTR	affett();
EXAWORD	getvarb();
BPTR	affvarb();
EXAWORD	varlook();
EXAWORD	varbtab();
VOID	helpscr();
VOID	itoxxxx();

/*	Procedure Name Management Functions	*/
/*	-----------------------------------	*/

EXTERN	EXAWORD	InitNomProc();
EXTERN	VOID	LibNomProc();
EXTERN	VOID	AffProcName();
EXTERN	EXAWORD	ProcNumb();

#endif

/*
EXAWORD	findkode();
BPTR	viewcode();
BPTR	viewcodb();
BPTR	oppsh();
BPTR	uoppsh();
BPTR	iofvisi();
BPTR	ioargs();
BPTR	fngf();
BPTR	dbug_clp();
BPTR	bibwork();
BPTR	affunc();
EXAWORD	clp_aff();
EXAWORD	varbvalu();
*/

/*
 *	D B S W I T ( )
 *	---------------
 *	Performs the code switching function to execute 1 Tcode operation
 *
 */

EXAWORD	dbswit()
{
	register	EXAWORD	tcode,e,b;
			EXAWORD	fadj;
#ifdef MODEL_DBGT
	/* Quantative Analysis of T-Code Execution */
	/* --------------------------------------- */
	if ( permdb & DBONSEM_QAN ) {
		b = (((EXAWORD) *fdex) & 0x007F);
		QuantL[b]++;
		if ( QuantL[b] == 0 ) { QuantH[b]++; }
		}
#endif	

	b = 0;
	while ( b == 0 ) {
		b = 1;
#include "exswit.c"
			default		: tcode = 0; err_val =56;continue;
			}
		if ( extwrite & 1 ) { 
			tcode = extrite(worktypw,descptrw,workeepw,workptrw);
			extwrite &= 0x000E;
			}
#ifdef ABALME
		if ( extwrite & 2 ) { 
#ifndef LINEAR_MEM
			if ((tcode = xferout(keepvptr,keepvlen,keepvofs)) == SOFTERROR)
				continue;
#endif
			tcode =1; extwrite = 0;
			}
#endif

	}
if ( tcode == 0 ) { 
	if ( ExQui == 0 ) {
		if ( err_val != 0 ) { return(erreurs()); }
		else	{
			tcode = MOINS_UN;
			newlyne(); 
			db_xcprintf((BPTR) TalkPtr[60]);
			db_xcprintf((BPTR)" (STOP) ");
			StopStatus = 1;
			return(MOINS_UN);
			}
		}
	else	{
		tcode = MOINS_UN;
		}
	}
return(tcode);
}

