/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBWTCH - H				*/
/*		Date 	:	06/08/1993				*/
/*		Version :	2.1a					*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBWTCH_H
#define	_EXDBWTCH_H

#define	WATCHPTR struct watchform PTR
#define	WATCHVMAX 64
#define WATCH_COUNT 1
#define WATCH_EXIST 0

/*	-----------------------------	*/
/*	Watch event control structure	*/
/*	-----------------------------	*/
struct	watchform {
	BPTR		name;		/* Variable name syntax 	*/
	BPTR		value;		/* Original Value		*/
	BPTR		where;		/* Pointer to memory		*/
	EXAWORD		length;		/* Length of watch zone		*/
	EXAWORD		type;		/* Type of variable/Watch	*/
	EXAWORD		index;		/* 				*/
	EXAWORD		andex;		/* Variable Dimensions		*/
	EXAWORD		descriptor;	/* Variable Descriptor		*/
	WATCHPTR	next;		/* Pointer to Next		*/
	WATCHPTR	previous;	/* Pointer to previous		*/
	};

#ifdef	_EXDBWTCH_C

	WATCHPTR	WatchBase;
	EXAWORD		WatchVlen;
	EXAWORD		WatchVcode;
	EXABYTE		WatchVbuf[WATCHVMAX+1];

EXTERN	EXAWORD	db_step_ctrl;
EXTERN	EXAWORD	ScreenFlg;		/* EXDBCICO Screen status flags	*/
EXTERN	EXAWORD	ScreenLin;		/* Number of ScreenLines	*/
EXTERN	EXAWORD	ScreenCol;		/* Screen Column Count		*/
EXTERN	EXAWORD	Couleurs[24][2];	/* Window Colours 		*/
EXTERN	EXAWORD	WindCord[16][2];	/* Window Control Block		*/
EXTERN	BPTR	TalkPtr[];		/* Message String Pointers	*/
EXTERN	BPTR	CmdShift();

#endif

/*	----------------------------------	*/
/*	Function prototypes for EXDBWTCH.C	*/
/*	----------------------------------	*/
#ifndef	UNIX

VOID WatchFlags(VOID);
VOID WatchMessage(BPTR);
VOID WatchFree(WATCHPTR);
BPTR WatchVariableName(WATCHPTR);
EXAWORD WatchEventCount(BPTR,EXAWORD);
EXAWORD WatchMake(BPTR,EXAWORD,EXAWORD,EXAWORD,EXAWORD);
VOID WatchShowValue(WATCHPTR);
short int WllComp(BPTR,BPTR,EXAWORD);
EXAWORD WatchCompare(BPTR,BPTR,EXAWORD,EXAWORD);
VOID RemoveWatchElement(WATCHPTR);
VOID WatchAction(WATCHPTR);
EXAWORD WatchMan(EXAWORD);
VOID WatchInit(VOID);
VOID WatchRaz(VOID);
VOID WatchEventList(BPTR);
VOID WatchEventSupr(BPTR);
VOID WatchFunctions(BPTR);
BPTR WatchValue(BPTR);
EXAWORD check_watch(EXAWORD,BPTR);
#else
VOID WatchFlags();
VOID WatchMessage();
VOID WatchFree();
BPTR WatchVariableName();
EXAWORD WatchEventCount();
EXAWORD WatchMake();
VOID WatchShowValue();
short int WllComp();
EXAWORD WatchCompare();
VOID RemoveWatchElement();
VOID WatchAction();
EXAWORD WatchMan();
VOID WatchInit();
VOID WatchRaz();
VOID WatchEventList();
VOID WatchEventSupr();
VOID WatchFunctions();
BPTR WatchValue();
EXAWORD check_watch();

#endif
#endif	/* _EXDBWTCH_H */
	/* ----------- */

