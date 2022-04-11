/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1996 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBMENU.H				*/
/*		Date 	:	19/09/1996				*/
/*		Version :	1.4e / 2.1c				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBMENU_H
#define	_EXDBMENU_H

#define	FIRST_MSG_14 109
#define  LAST_MSG_14 116

#ifdef	MODEL_DBGT
#include "exmnem.h"		/* T-Code Mnemonics			*/
#endif

#include "exdbmimo.h"

/* 	For 'C' Versions of execution motor		*/
/*	-----------------------------------		*/
#ifndef	PROLOGUE
#ifndef	DOS
#define dbentry(arg1) lldbmotor(arg1)
#endif
#endif
#ifdef WIN32
#define dbentry(arg1) lldbmotor(arg1)
#endif


EXTERN	EXAWORD	ExadbGoFunction;	/* Indicates GO Function !CHAIN */
EXTERN 	EXAWORD	ExQui;			/* Motor Re-Entrance control	*/
EXTERN	EXAWORD	StackHold;		/* Gosub Stack protection	*/
EXTERN	EXAWORD	adr_npr;		/* Secteur Noms des Procedures	*/
EXTERN	EXAWORD	trace;			/* Variable de Trace		*/
EXTERN	int	errno;			/* Systeme Error Variable	*/
EXTERN	EXAWORD	ScreenFlg;		/* EXDBCICO Screen status flags	*/
EXTERN	EXAWORD	ScreenLin;		/* Number of ScreenLines	*/
EXTERN	EXAWORD	ScreenCol;		/* Screen Column Count		*/
EXTERN	EXAWORD	Couleurs[24][2];	/* Window Colours 		*/
EXTERN	EXAWORD	WindCord[16][2];	/* Window Control Block		*/

EXAWORD	StopStatus;			/* FALSE until STOP executed	*/
EXAWORD	brayk,permdb;		/* Break Key 				*/ 
EXAWORD	Abuse;			/* State of Verbaliser			*/
EXAWORD	TabSize;		/* Tabulation Conversion Counter	*/
EXAWORD	Konsult;		/* Consultation Controller		*/
EXAWORD	ErrorMode;		/* Error Action Flag (Which adresse)	*/
				/* Zero ==> Newline, Else Real Adresse	*/
EXAWORD	DbWindow;		/* Debugg Window Active			*/
EXAWORD	ExWindow;		/* Executeur Window State		*/
EXAWORD	ListLigne;		/* Number of lines for Source List	*/
EXAWORD	ListStatus;		/* Status of Debug list file		*/
EXAWORD	noprompt;		/* No Prompt refresh required		*/
BPTR	History[16];		/* Historique des commandes		*/
EXAWORD	HistDex;		/* Index des commandes Historique	*/
EXAWORD	HistMax;		/* Limit des commandes Historique	*/ 
EXAWORD	HistCur;		/* Current Commande			*/
EXAWORD	HistCtrl;		/* History delete controlleur		*/
				/* ------------------------------------ */
EXAWORD	LastTcode;		/* Last Tcode returned from executeur	*/
EXAWORD	db_step_ctrl;		/* Step mode control variable for motor	*/
				/* ------------------------------------ */

#include "exdbobs.h"

#ifdef	ABAL14

/*	Memory zone watch management 		*/
/*	----------------------------		*/
#include "exdbwtch.h"

#endif

#ifdef	ABAL21
EXTERN	EXABYTE	exadb_file_root[64];
#endif

#ifdef MODEL_DBGT

/*	Gestion des options Etendus			*/
/*	---------------------------			*/

EXAWORD	ritewatch;		/* Observation en ecriture seulement 	*/
#endif

#ifndef UNIX

EXAWORD	nametest( BPTR, EXAWORD );
EXAWORD	thisvarb(EXAWORD,EXAWORD,EXAWORD,EXAWORD);

/*	Gestion du fichier Liste (Fnom-L)	*/
/*	---------------------------------	*/

EXTERN	EXAWORD	tcode_correspondance(EXAWORD,EXAWORD,EXAWORD,EXAWORD);
EXTERN	EXAWORD	idb_listgogo(VOID);
EXTERN	EXAWORD	idb_window(EXAWORD,EXAWORD,EXAWORD);
EXTERN	EXAWORD	idb_flopen(VOID);
EXTERN	VOID	idb_flclose(VOID);
EXTERN	EXAWORD	idb_fgetc(VOID);
EXTERN	EXAWORD	idb_bgetc(VOID);
EXTERN	VOID	prnlignes(EXAWORD,EXAWORD);
EXTERN	VOID	idb_Pager(EXAWORD);
EXTERN	VOID	baklignes(EXAWORD);
EXTERN	VOID	fwdlignes(EXAWORD);
EXTERN	VOID	SwapWindow(VOID);	/* Change Physical Output Status	*/
EXTERN	VOID	LoadWindow(EXAWORD);	/* Change logical Output Status		*/
EXTERN	BPTR	dbcgets(BPTR);	/* Get a command string from keyboard	*/
EXTERN	BPTR	WatchValue(BPTR);	/* Get a watch break point value	*/
EXTERN	BPTR	CurrentSegmentPointer(EXAWORD); 
EXAWORD 	varmod(BPTR,EXAWORD);
EXAWORD	CmdWindow(EXAWORD);
VOID	Verbose(BPTR);
#ifndef ABAL21
VOID	Observe(VOID);
VOID	dumpzone(BPTR,EXAWORD);
#else
EXAWORD	Observe(EXAWORD);
VOID	dumpzone(BPTR,EXAWORD,EXAWORD);
#endif
EXAWORD	dberreur(BPTR);
VOID	showword(EXAWORD,EXAWORD);
VOID	dbmotor(VOID);
VOID	dbstep(VOID);
EXTERN	EXAWORD	dbswit(VOID);
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
EXAWORD	variable_value(VOID);

/*	Procedure Name Management Functions	*/
/*	-----------------------------------	*/

EXTERN	EXAWORD	InitNomProc(VOID);
EXTERN	VOID	LibNomProc(VOID);
EXTERN	VOID	AffProcName(EXAWORD);
EXTERN	EXAWORD	ProcNumb(BPTR);
EXTERN	BPTR	CmdShift(BPTR);
EXTERN	BPTR	kode_lode(EXAWORD,EXAWORD);

#else

EXAWORD	nametest();
EXAWORD	thisvarb();

/*	Gestion du fichier Liste (Fnom-L)	*/
/*	---------------------------------	*/

EXTERN	EXAWORD	tcode_correspondance();
EXTERN	EXAWORD	idb_listgogo();
EXTERN	EXAWORD	idb_window();
EXTERN	EXAWORD	idb_flopen();
EXTERN	VOID	idb_flclose();
EXTERN	EXAWORD	idb_fgetc();
EXTERN	EXAWORD	idb_bgetc();
EXTERN	VOID	prnlignes();
EXTERN	VOID	idb_Pager();
EXTERN	VOID	baklignes();
EXTERN	VOID	fwdlignes();
EXTERN	VOID	SwapWindow();	/* Change Physical Output Status	*/
EXTERN	VOID	LoadWindow();	/* Change logical Output Status		*/
EXTERN	BPTR	dbcgets();	/* Get a command string from keyboard	*/
EXTERN	BPTR	WatchValue();	/* Get a watch break point value	*/
EXTERN	BPTR	CurrentSegmentPointer(); 
EXAWORD 	varmod();
EXAWORD	CmdWindow();
VOID	dumpzone();
VOID	Verbose();
#ifndef ABAL21
VOID	Observe();
#else
EXAWORD	Observe();
#endif
EXAWORD	dberreur();
VOID	showword();
VOID	dbmotor();
VOID 	dbstep();
EXTERN	EXAWORD	dbswit();
EXAWORD	checks();
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
EXAWORD	getett();
BPTR	affett();
EXAWORD	getvarb();
BPTR	affvarb();
EXAWORD	varlook();
EXAWORD	varbtab();
VOID	helpscr();
VOID	itoxxxx();
EXAWORD	variable_value();

/*	Procedure Name Management Functions	*/
/*	-----------------------------------	*/

EXTERN	EXAWORD	InitNomProc();
EXTERN	VOID	LibNomProc();
EXTERN	VOID	AffProcName();
EXTERN	EXAWORD	ProcNumb();
EXTERN	BPTR	CmdShift();
EXTERN	BPTR	kode_lode();

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

struct	code_block {
	EXAWORD	segproc;
	EXAWORD	number;
	EXAWORD	offset;
	} Local_Identity;

#ifdef	EXDBMENUC
	struct	code_block LastDebug;
	struct	code_block LastExec;
#else
EXTERN	struct	code_block LastDebug;
EXTERN	struct	code_block LastExec;
#endif

struct	code_block Local_User;

#endif	/* _EXDBMENU_H */
	/* ----------- */
