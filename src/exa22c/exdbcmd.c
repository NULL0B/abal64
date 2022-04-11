/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1996 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBCMD - C				*/
/*		Version :	1.4c / 2.1a				*/
/*		Date 	:	19/09/1996				*/
/*									*/
/*----------------------------------------------------------------------*/
#define DEBUGGER
#define	EXDBCMDC

				/* ------------------------------------ */
#include "exdebug.h"		/* General Executeur definitions	*/
#include "exctype.h"		/* Character types and macros		*/
#include "exdbkeys.h"		/* Debug command key definitions	*/
#include "exdbgrsy.h"		/* Debugger Colours			*/
#include "exerrno.h"		/* ERRNO and possible values		*/
				/* ------------------------------------ */
#include "exproto1.h"
#define	HISTSIZE	16

EXTERN	EXAWORD	adr_npr;	/* Secteur Noms des Procedures	*/
EXTERN	EXAWORD	trace;		/* Variable de Trace		*/
EXTERN	EXAWORD	LastTcode;	/* Next tcode to be executed	*/
EXTERN	BPTR	TalkPtr[];	/* Message pointer table	*/
EXTERN 	EXAWORD	Konsult;	/* Consultation Mode Active	*/
EXTERN	EXAWORD	ErrorMode;	/* Error Action Flag		*/
EXTERN	EXAWORD	ScreenCol;	/* Number of Screen columns	*/
EXTERN	EXAWORD	brayk,permdb;
EXTERN	EXAWORD	Abuse;			/* State of Verbaliser			*/
EXTERN	EXAWORD	TabSize;		/* Tabulation Conversion Counter	*/
EXTERN	EXAWORD	underspill;		/* Underspill of Screen / Source lines 	*/
EXTERN	EXAWORD	DbWindow;		/* Debug Window Active			*/
EXTERN	EXAWORD	ExWindow;		/* Executeur Window State		*/
EXTERN	EXAWORD	ListLigne;		/* Number of lines for Source List	*/
EXTERN	EXAWORD	ListStatus;		/* Status of Debug list file		*/
EXTERN	EXAWORD	ScreenLin;		/* Number of Screen Lines		*/

EXTERN	EXAWORD	noprompt;		/* NoPrompt Status Flag	*/
EXTERN	EXAWORD	Couleurs[24][2];	/* Window Colours	*/
EXTERN	EXAWORD	WindCord[16][2];	/* Window Control Block	*/
EXTERN	BPTR	History[HISTSIZE];	/* Historique des commandes		*/
EXTERN	EXAWORD	HistDex;		/* Index des commandes Historique	*/
EXTERN	EXAWORD	HistMax;		/* Nombre de commandes Historique	*/ 
EXTERN	EXAWORD	HistCur;		/* Current Commande Index		*/
EXTERN	EXAWORD HistCtrl;		/* Controls Ctrl Y for Historic erase   */

/*	Gestion des variables en observation		*/
/*	------------------------------------		*/

EXTERN	EXAWORD	watchdex;		/* Watch counter			*/
EXTERN	EXAWORD	watchmat[16];		/* Watch matrix				*/
EXTERN	EXAWORD	watchind[16];		/* 1st Index				*/
EXTERN	EXAWORD	watchand[16];		/* 2nd index				*/
EXTERN	EXAWORD	watchtyp[16];		/* Type de Variable			*/
EXTERN	EXAWORD	watchgod[16];		/* Procedure ou Segment (for locales )	*/

#ifdef MODEL_DBGT

/*	Gestion des options Etendus			*/
/*	---------------------------			*/

EXTERN	EXAWORD	ritewatch;		/* Observation en ecriture seulement 	*/
EXTERN	EXAWORD	QuantH[128];		/* Quanta analysis High counter		*/
EXTERN	EXAWORD	QuantL[128];		/* Quanta analysis Low counter		*/ 
EXTERN	EXAWORD	CodeHalt;		/* Tcode to halt execution		*/
#endif

#ifndef UNIX

/*	Gestion du fichier Liste (Fnom-L)	*/
/*	---------------------------------	*/
#ifdef	BEFORE_011295
EXTERN	EXAWORD	idb_listgogo(VOID);
EXTERN	EXAWORD	idb_flopen(VOID);
EXTERN	VOID	idb_flclose(VOID);
EXTERN	EXAWORD	idb_fgetc(VOID);
EXTERN	EXAWORD	idb_bgetc(VOID);
EXTERN	VOID	prnlignes(EXAWORD,EXAWORD);
EXTERN	VOID	idb_Pager(EXAWORD);
EXTERN	VOID	baklignes(EXAWORD);
EXTERN	VOID	fwdlignes(EXAWORD);
#endif


EXTERN	VOID	SwapWindow(VOID);	/* Change Physical Output Status	*/
EXTERN	VOID	LoadWindow(EXAWORD);	/* Change logical Output Status		*/

EXAWORD	nametest(BPTR,EXAWORD);
EXAWORD	thisvarb(EXAWORD,EXAWORD,EXAWORD,EXAWORD);
EXAWORD	CmdWindow(EXAWORD);
VOID	posepiege(EXAWORD,EXAWORD,EXAWORD,EXAWORD);
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

/*	Procedure Name Management Functions	*/
/*	-----------------------------------	*/

EXTERN	EXAWORD	InitNomProc(VOID);
EXTERN	VOID	LibNomProc(VOID);
EXTERN	VOID	AffProcName(EXAWORD);
EXTERN	EXAWORD	ProcNumb(BPTR);

#else

/*	Gestion du fichier Liste (Fnom-L)	*/
/*	---------------------------------	*/
#ifdef	BEFORE_011295
EXTERN	EXAWORD	idb_listgogo();
EXTERN	EXAWORD	idb_flopen();
EXTERN	VOID	idb_flclose();
EXTERN	EXAWORD	idb_fgetc();
EXTERN	EXAWORD	idb_bgetc();
EXTERN	VOID	prnlignes();
EXTERN	VOID	idb_Pager();
EXTERN	VOID	baklignes();
EXTERN	VOID	fwdlignes();
#endif

EXTERN	VOID	SwapWindow();	/* Change Physical Output Status	*/
EXTERN	VOID	LoadWindow();	/* Change logical Output Status		*/

EXAWORD	nametest();
EXAWORD	thisvarb();
EXAWORD	CmdWindow();
VOID	posepiege();
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
VOID	dbstep();
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
 *	I N T V I S I ( e )
 *	-------------------
 *	Affichage d'une valeur Integer
 */
VOID	x_intvisi( e )
EXAWORD	e;
{
	itoa(e,(BPTR) askbuf,7); db_xcprintf((BPTR) askbuf);
	return;
}

/*
 *	S H O W P T R ( p )
 *	---------------------
 *	Affichage Hexadecimale d'un Pointer BIG or SMALL Modele
 *
 */

VOID showptr( p )
BPTR	p;
{
#ifdef HALFSIZE
	showword( (EXAWORD) p, 4);
#else
	EXAWORD	z;
	EXALONG    l;
	l = (EXALONG) p;
	z = (EXAWORD) (( l & 0xFFFF0000L) >> 16);
	showword(z,4);
	z = (EXAWORD) ( l & 0x0000FFFFL);
	showword(z,4);
#endif
	return;
}

/*
 *	N E W L Y N E ()
 *	----------------
 *
 */

VOID newlyne()
{
	db_xputch('\n');	db_xputch('\r');
	return;
}

/*
 *	E D E R ( e )
 *	-------------
 *
 *	Affichage des erreurs d'execution et d'initialisation
 *
 */
EXTERN	EXAWORD	InhibitEder;

#ifdef	ABAL14
VOID	eder( e)
#else
EXAWORD	eder(e,x)
EXAWORD	x;
#endif
EXAWORD	e;
{
	if ( InhibitEder == 1 ) return;

	if ( e != 0 ) {
		if ( ExWindow == 0 ) { LoadWindow((EXAWORD) 0); } 
		WdwLimit(12,5,78);
		if (PushZone(WindCord[12][0],WindCord[12][1],5,78,0x0013,Couleurs[12][0],Couleurs[12][1]) != 0 ) {
			Debordement();
			}
		/* Debut d'un message d'erreur */
		/* --------------------------- */
		db_xcprintf((BPTR)"   ");
		db_xcprintf((BPTR)TalkPtr[2]);
		db_xputch(' ');

		/* Erreurs d'Entree Sorties  1 a 19 */
		/* -------------------------------- */
		if ( e < 20 ) 		      {	
			db_xcprintf((BPTR)TalkPtr[3]);
			db_xputch(0x0009);
			}
		/* Erreurs Systeme 20 a 29 */
		/* ----------------------- */
		if (( e > 19 ) && ( e < 30 )) {
			db_xcprintf((BPTR)TalkPtr[4]);
			db_xputch(0x0009);
			}
		/* Erreurs Syntaxe de Commande 30 a 39 */
		/* ----------------------------------- */
		if (( e > 29 ) && ( e < 40 )) { 
			db_xcprintf((BPTR)TalkPtr[5]);
			db_xputch(0x0009);
			}
		/* Erreurs Systeme de Fichiers 40 a 96 */
		/* ----------------------------------- */
		if (( e > 39 ) && ( e < 97 )) { 
			db_xcprintf((BPTR)TalkPtr[6]);
			db_xputch(0x0009);
			}
		/* Erreurs Systemes 97 a 170 */
		/* ------------------------- */
		if (( e > 96 ) && ( e < 170)) { 
			db_xcprintf((BPTR)TalkPtr[7]);
			db_xputch(0x0009);
			}
		/* Erreurs Systeme de fichiers 170 a 190 */
		/* ------------------------------------- */
		if (( e > 169) && ( e < 190)) {
			db_xcprintf((BPTR)TalkPtr[8]);
			db_xputch(0x0009);
			}
		/* Erreurs Systeme Graphiques  190 a 196 */
		/* ------------------------------------- */
		if (( e > 189) && ( e < 197)) {
			db_xcprintf((BPTR)TalkPtr[9]);
			db_xputch(0x0009);
			}
		/* Erreurs Systemes Divers  190 a 196 */
		/* ---------------------------------- */
		if ( e > 196)		      { 
			db_xcprintf((BPTR)TalkPtr[10]);
			db_xputch(0x0009);
			}

		/* Affichage d'identite ABAL plus Adresse d'erreur */
		/* ----------------------------------------------- */
		intvisi(e); db_xcprintf((BPTR)"  (ABAL)  ");
		if ( sicico & ONSEM_SEG ) { /* If Erreur d'execution du T-code */
			db_xcprintf((BPTR)TalkPtr[11]); db_xputch(' ');
			showword(((lineptr - TcodeSegment) -1),4);
			if ( sicico & ONSEM_PRC ) { /* If Erreur de Procedure		*/
				db_xcprintf((BPTR)" (proc: "); intvisi(procid);
				db_xputch(')');
				}
			db_xcprintf((BPTR)" (seg: "); intvisi(cur_seg); db_xputch(')');
			}

		x_getch(); PopZone();

		/* Check for Error Adresse == Line adresse */
		/* --------------------------------------- */
		if ( ErrorMode == 0 ) {
			fdex = (TcodeSegment + ((lineptr - TcodeSegment) - 1));
			}
		/* Else leave the Adresse as it is For IDB */
		/* --------------------------------------- */
		}
#ifdef	ABAL14
	return;
#else
	return(x);
#endif
}

/*
 *	D B C G E T S ( rptr )
 *	----------------------
 *
 *	Accept keyboard input of Debugger command line syntax
 *	string pointed to by *rptr.
 *
 */

BPTR	dbcgets( rptr )
BPTR	rptr;
{
	BPTR	wptr;
	EXABYTE	c;
	EXAWORD	ml;

#ifdef	BUF_CICO
	x_bflush();
#endif
	ml = (EXAWORD) *rptr;	
	wptr = rptr;
	rptr += 2;
	while ( ml > 0 ) {
		c = x_getch();
		if ( c == IO_RC ) { ml = 0; }
		else {
			if ( c == syskey[IO_BAK] ) {
				ml++; rptr--;
				db_xputch(c); continue;
				}
			if ( c == syskey[IO_FOR] ) {
				ml--; db_xputch(*(rptr++));
				continue;
				}
			switch ( c ) {
				case IO_ESC :	return((BPTR) 0);
				case IO_ESP :	*(rptr++) = c;
						db_xputch(c); 
						if ( ml == (EXAWORD) *wptr) {
							ml = 0; continue; 
							}
						ml--; continue;
				default	    :	*(rptr++) = c; ml--; 
						db_xputch(c); continue;
				}
			}
		}
	*((BPTR) (wptr + 1)) = (EXABYTE) ( ((EXAWORD) *wptr) - ml);
	*(rptr++) = (EXABYTE) 0;
	return((BPTR) (wptr +2) );
}
VOID	RazHist()
{
	EXAWORD	x;
	if (( HistMax > 0 ) && ( HistCtrl > 0 )) {
		if ( History[HistCur] != (BPTR) 0 ) {
			liberate( History[HistCur] );
			}

		x = HistCur; HistMax--;
		while ( x < HistMax ) {
			History[x] = History[x+1];
			x++;
			}
		/* Reset Pointer To Zero !!! */
		/* ------------------------- */
		History[HistMax] = (BPTR) 0; 
		HistDex = HistMax;
		if ( HistMax == 0 ) { HistCur = 0; } 
		else	{
			if ( HistCur >= (HistMax-1) ) { HistCur = (HistMax-1); }
			}
		}
	return;		
}

VOID	AddHist()
{

	EXAWORD	x;
	BPTR	wptr;
if ( HistCur == HistDex ) {

	/* Check for and ignore zero length strings */
	/* ---------------------------------------- */
	if ( (x = strlen((BPTR) askbuf)) == 0 ) 
		return;

	/* Allocate a suitable Storage Zone */
	/* -------------------------------- */
	if ((wptr = (BPTR) allocate((USINT)( x+1) )) == (BPTR) 0 ) 
		return;

	/* Transfer String to Historique Storage Zone */
	/* ------------------------------------------ */
	memcpy((BPTR) wptr,(BPTR) askbuf,(USINT) (x + 1));

	/* Check for and Liberate previous occupant */
	/* ---------------------------------------- */
	if ( History[HistDex] != (BPTR) 0 )
		liberate( History[HistDex] );
	History [HistDex++] = (BPTR) wptr;

	/* Update Cyclic buffer management Variables */
	/* ----------------------------------------- */
	if ( HistMax <  HISTSIZE )
		HistMax++;
	if ( HistDex >= HISTSIZE ) 
		HistDex = 0;
	}
return;

}

EXAWORD	UpHist(nbc)
EXAWORD	nbc;
{
if ( HistMax > 0 ) {
	if ( HistCur == 0 ) { HistCur = (HistMax - 1);  }
	else		    { HistCur--;	  	}
	nbc = strlen((BPTR) History[HistCur]);
	memcpy((BPTR) askbuf ,(BPTR) History[HistCur] , (USINT) (nbc+1));
	HistCtrl = 1;
	return(nbc);
	}
return(0);
}

EXAWORD	DwnHist(nbc)
EXAWORD	nbc;
{
	if ( HistMax > 0 ) {
		if ( HistCur >= (HistMax-1) ) 	{ HistCur = 0; 	}
		else		    	  	{ HistCur++;	}
		nbc = strlen((BPTR) History[HistCur]);
		memcpy((BPTR) askbuf , History[HistCur] , (USINT) (nbc+1));
		HistCtrl = 1;
		return(nbc);
		}
	return(0);
}

#ifdef	BEFORE_011295
VOID	MenuUp(natb , nbl )
EXAWORD natb;
EXAWORD	nbl;
{
	if ( ListStatus & 1 ) {
		if (Konsult == 0) {
			if (PushInfo() != 0) { return; } 
			idb_CtrlOff();
			Konsult = 1;
			}
		baklignes(nbl);
		idb_Pager(natb);
		db_xpos((2 - ((ListLigne / 2) - 1)),(WindCord[14][1]+1));
		FindHere();
		}
	return;
}

VOID	MenuDwn( natb ,nbl )
EXAWORD	natb;
EXAWORD	nbl;
{
	if ( ListStatus & 1 ) {
		if (Konsult == 0) {
			if ( PushInfo() != 0 ) { return; }
			idb_CtrlOff();
			Konsult = 1;
			}
		fwdlignes(nbl); if (nbl > 1) { idb_bgetc(); }
		idb_Pager(natb);
		db_xpos((ScreenLin - ((ListLigne / 2) - 1))  , (WindCord[14][1]+1));
		FindHere();
		}
	return;
}

VOID	MenuPos( VirtLyne )
EXAWORD	VirtLyne;
{
	ColourAtb(0); ColourAtb(2);
	if ( conf(14) == 0 ) {
		idb_Latb(VirtLyne,2);
		}
	else	{
		idb_Lpaint(VirtLyne,Noir,GrisClair);
		}
	idb_Lrefresh(VirtLyne);
	db_xpos(VirtLyne,(WindCord[14][1]+1));
	ColourAtb(0);
	return;
}

VOID	MenuDpos( VirtLyne )
EXAWORD	VirtLyne;
{
	ColourAtb(0);
	if ( conf(14) == 0 ) {
		idb_Latb(VirtLyne,0);
		}
	else	{
		idb_Lpaint(VirtLyne,wotfore(),wotback());
		}
	idb_Lrefresh(VirtLyne);
	db_xpos(VirtLyne,(WindCord[14][1]+1));
	return;
}

VOID	MenuZoom( VirtLyne )
EXAWORD	VirtLyne;
{
	EXAWORD	Goch,lmax;
	EXAWORD	l,width,leng;

	/* Save Current Screen Infos */
	/* ------------------------- */
	if (PushInfo() != 0) {
		Debordement();
		return;
		} 

	/* Position within the Source to The Required Line */
	/* ----------------------------------------------- */
	l = ((((ScreenLin - 2) - ListLigne) + 2) + underspill);
	fwdlignes( ( VirtLyne - l ) );


	/* Calculate Window Size Required */
	/* ------------------------------ */
	lmax = idb_LineLen();
	if ((lmax + 3) < (ScreenCol - WindCord[3][1])) {
		width = lmax + 3;
		leng  = 3;
		}
	else	{
		width = ((ScreenCol - 1) - WindCord[3][1]);
		leng  = ((lmax / width) + 3);
		
		if (( leng + WindCord[3][0] ) >= ScreenLin ) {
			leng = (ScreenLin - WindCord[3][0]);
			lmax = ((leng - 2) * (width - 2));
			}
		}
	WdwLimit(3,leng,width);
	
	/* Save Window area and generate Frame */
	/* ----------------------------------- */
	if (PushZone(WindCord[3][0],WindCord[3][1],leng,width,0x0013,Couleurs[3][0],Couleurs[3][1]) != 0 ) {
		Debordement();
		PopInfo();
		return;
		} 

	/* Display the Line in the Zoom Window */
	/* ----------------------------------- */
	do 	{
		switch ( (Goch = (EXAWORD) idb_fgetc() ) ) {
			case 0x000D : continue;
			case 0x000A :
			case 0x0000 : Goch = 0; continue;
			case 0x0009 : Goch = ' ';
			default	    : if ( Goch >= ' ' ) {	
						db_xputch(Goch); lmax--; 
						}
			}			
		}
	while	(( Goch != 0 ) && ( lmax > 0 )) ;

	/* Perform Exit Checking */
	/* --------------------- */
	switch ( ExitMethod(1) ) {
		case 0 : PopZone(); break;
		case 1 : LibZone(); break;
		} 

	/* Recover Screen List Infos */
	/* ------------------------- */
#ifdef	BEFORE_011295
	PopInfo();
#endif
	return;
}



EXAWORD	ModifWindow(Cmd , VirtLyne )
EXAWORD	Cmd;
EXAWORD	VirtLyne;
{
	EXAWORD	spillx,lno,x;

	/* Check for Consultation Mode Active */
	/* ---------------------------------- */
	if ( Konsult != 0 )	{
		/* -------------------------------- */
		/* "Interdite en mode Consultation" */
		/* -------------------------------- */
		Verbose((BPTR)TalkPtr[71]);
		return(VirtLyne);
		}

	/* Adjust Execution Infos with respect to Window */
	/* --------------------------------------------- */
	switch ( Cmd ) {
		case DB_WDWGROW : 
			if ( ListLigne < (ScreenLin - 2)) {
				ListLigne += 2;
				
				if ( underspill > 0 ) 	{ underspill++; }
				else			{ baklignes(1); }
				if ( VirtLyne > (ScreenLin - ListLigne)) { 
					VirtLyne--; 
					}
				}
			break;
		case DB_WDWCUT  : 
			if ( ListLigne > 6 ) {
				/* Clear the Window Space */
				/* ---------------------- */
				lno = (ScreenLin - (ListLigne+1));
				x   = 2;
				while ( x > 0 ) {
					x--;
					db_xpos(lno,WindCord[14][1]); db_xatb(21);
					lno++;
					}
				ListLigne -= 2;
				if ( underspill > 0 ) 	{ underspill--; }
				else			{ fwdlignes(1);	}
				if ( VirtLyne < (ScreenLin - 2) ) 	{ VirtLyne++;	}
				}
			break;
		}
	idb_Pager(0); MenuPos( VirtLyne ); 
	return(VirtLyne);

}

#endif	/* BEFORE_011295 */


void	set_tabulation_size( nptr )
BPTR	nptr;
{
	EXAWORD	z;
	z = atoi((BPTR) nptr , 2 );
	if ( z > 0 ) 
		TabSize = z; 
	return;
}

void	establish_tabulation()
{
	if ( CmdWindow(2) == 0 ) {
		set_tabulation_size((BPTR) askbuf);
		}
	return;
}

#ifdef	BEFORE_011295
EXAWORD	dbstrget( x , y )
EXAWORD	x,y;
{
	EXAWORD	Mode,Madr;
	EXAWORD	MPrcSeg,Mcs;
	EXAWORD	c,z,ccc;
	EXAWORD	nbc,err;
	EXAWORD	VirtLyne;
	EXAWORD	VirtLim;

	/* Initialise Historique Controlleurs */
	/* ---------------------------------- */
	HistCur  = HistDex; HistCtrl = 0; nbc = 0;

	if ( y == 0 ) {
		VirtLyne = db_xlin(); 
		VirtLim  = (ScreenLin - ListLigne); 	ccc 	 = 0x0020;
		}
	else	{ ccc = 0; }	

	do  {
	    if ( y == 0 ) {
		if ( Abuse > 0 ) {
			Abuse--; if ( Abuse == 0 ) { Verbose((BPTR)"\0"); }
			}
		}
	    c = x_getch();

	    if ( y == 0 )	{	/* Mode Commande (not mode Find) */

	
		/* Deplacements Ligne Haut et Bas */
		/* ------------------------------ */
		if ( c == syskey[IO_UP] ) {

			if ((ListStatus & 1) && ( ExWindow == 0 )) { 
				if ( VirtLyne == VirtLim ) {
					MenuUp(0,1);
					}
				else	{
					MenuDpos(VirtLyne);
				/*	idb_Latb(VirtLyne,0);		*/
				/*	idb_Lrefresh(VirtLyne);		*/
					VirtLyne--;
					}
				MenuPos( VirtLyne );
				}
			continue;
			}
		if ( c == syskey[IO_BAS] )  {
			if ((ListStatus & 1) && ( ExWindow == 0 )) {
				if ( VirtLyne == (ScreenLin - 2) ) { 
					MenuDwn(0,1); 
					}
				else	{
					MenuDpos(VirtLyne);
				/*	idb_Latb(VirtLyne,0);		*/
				/*	idb_Lrefresh(VirtLyne);		*/
					VirtLyne++;
					}
				MenuPos( VirtLyne );
				}
			continue;
			}

		switch ( c ) {

			case	DB_TRAPA   : /* Fixed break point 	*/
					     /* ----------------- 	*/

			case	DB_TRAPB   : /* One Shot Break point	*/
					     /* -------------------- 	*/
 
				if (( ListStatus & 1 ) && (ExWindow == 0)) {
					Mode = (c & 1); /* Permanant or Temp Trap */
					Madr = idb_Ladr(VirtLyne);
					if ( errno == 0 ) {
						if (idb_Sadr(VirtLyne,(WPTR) &Mcs , (WPTR) &MPrcSeg ) == 0) {
							(VOID) posepiege(Mcs,Madr,MPrcSeg,Mode);
							}
						else	{ 
							Verbose((BPTR)TalkPtr[72]);
							/* " Segment / Procedure not found " */
							/* --------------------------------- */ 
							}
						}
					else	{ 
						Verbose((BPTR)TalkPtr[73]);
						/* " Adresse non-Trouve " */
						/* ---------------------- */
						}
					}
				continue;

			case	DB_HEADER   :	/* Head of Segm or Proc */
						/* -------------------- */
			if (( ListStatus & 1 ) && (ExWindow == 0)) {	
				if ( Konsult == 0 ) {
					if (PushInfo() != 0) {
						Debordement();
						continue;
						}
					Konsult = 1;
					idb_CtrlOff();
					}	

				if (idb_Sadr(VirtLyne,(WPTR) &Mcs , (WPTR) &MPrcSeg ) == 0) {
					if ( MPrcSeg == 0 ) { 
						z = idb_seekseg( Mcs );
						}
					else	{
						z = idb_seekprc( Mcs * 16 );
						}
					if ( z != 0 ) { idb_Pager( 0 ); } 
					}
				}
			continue;

			case	DB_ZOOM	   :	/* Line Zoom Consult	*/
						/* -----------------	*/
				if (( ListStatus & 1 ) && (ExWindow == 0)) { 
					MenuZoom(VirtLyne); 
					}
				continue;
				
			case	DB_POINT   :	/* Consult List Libelle	*/
						/* --------------------	*/
			if (( ListStatus & 1 ) && (ExWindow == 0)) {
				if ( Konsult == 0 ) {
					if (PushInfo() != 0) {
						Debordement();
						continue;
						}
					Konsult = 1;
					idb_CtrlOff();
					}	
				Verbose((BPTR)TalkPtr[74]);
				/* "Libelle a rechercher" */
				/* ---------------------- */
				if ( CmdWindow(32) == 0 ) {
					idb_libelle((BPTR) askbuf ); 
					MenuUp(2,0);
					MenuPos(VirtLyne);
					}
				}
			continue;

			case    DB_TAB	   :	/* Etablir TabSize	*/
						/* ---------------	*/

			if (( ListStatus & 1 ) && (ExWindow == 0)) {
				Verbose((BPTR)TalkPtr[75]);
				/* "Longeur des tabulations" */
				/* ------------------------- */
				establish_tabulation();
				}
			continue;

			case	DB_WIPE	   :	/* Detruire une libelle */
						/* -------------------- */
			if (( ListStatus & 1 ) && (ExWindow == 0)) {
				Verbose((BPTR)TalkPtr[76]);
				/* "Libelle a suprimer" */
				/* -------------------- */
				if ( CmdWindow(32) == 0 ) {
					idb_libelkill((BPTR) askbuf);
					}
				}
			continue;

			case	DB_HOME    :	/* Definir une libelle  */
						/* -------------------  */
			if (( ListStatus & 1 ) && (ExWindow == 0)) {
					Verbose((BPTR)TalkPtr[77]);
					/* "Libelle a definir" */
					/* ------------------- */
					if ( CmdWindow(32) == 0 ) {
						idb_libeladd( (BPTR) askbuf ); 
						}
					MenuPos(VirtLyne);
					}
				continue;

			case	DB_WDWGROW :	/* Increase List Window	*/
						/* -------------------- */
			if (( ListStatus & 1 ) && (ExWindow == 0)) {
					Verbose((BPTR)TalkPtr[78]);
					/* "Fenetre agrandi" */
					/* ----------------- */
					VirtLyne = ModifWindow(DB_WDWGROW,VirtLyne);
					VirtLim  = (ScreenLin - ListLigne);
 					}
				continue;

			case	DB_WDWCUT  :	/* Decrease List Window	*/
						/* -------------------- */
			if (( ListStatus & 1 ) && (ExWindow == 0)) {
					Verbose((BPTR)TalkPtr[79]);
					/* "Fenetre diminue" */
					/* ----------------- */
					VirtLyne = ModifWindow(DB_WDWCUT,VirtLyne);
					VirtLim  = (ScreenLin - ListLigne);
					}
				continue;

			case	DB_PARAM   :	/* Modification Parameters */
						/* ----------------------- */

			if (( ListStatus & 1 ) && (ExWindow == 0)) {
				ParamMenu();
				}
			continue;

			case	0x0037     :
			case	0x001C	   :	/* Position to Top of Source */
						/* ------------------------- */

				if (( ListStatus & 1 ) && (ExWindow == 0)) {
					if ( Konsult == 0 ) {
						if (PushInfo() != 0) {	
							Debordement();
							continue;
							}
						Konsult = 1;
						idb_CtrlOff();
						}	
					idb_Pager(0);
					MenuPos( VirtLyne );
					}
				continue;

			case	DB_FIND    :	/* Text Find (Wild)	*/
						/* ----------------	*/
			if (( ListStatus & 1 ) && (ExWindow == 0)) {
				Verbose((BPTR)TalkPtr[80]);
				/* "Chaine a rechercher" */
				/* --------------------- */
				if ( Konsult == 0 ) {
					if (PushInfo() != 0) {
						Debordement();
						continue;
						}
					Konsult = 1;
					idb_CtrlOff();
					}	
				if ( CmdWindow( 32 ) == 0 ) {
				   if ( askbuf[1] > 0 ) {
					if (PushInfo() != 0) {
						Debordement();
						continue;
						}
					if ( idb_wildseek((BPTR) askbuf) != 0 ) {
						LibInfo(); 
						if (idb_bgetc() != 0x000A) {
							idb_fgetc();
							}
						baklignes( (ListLigne / 2) + 1 );
						idb_Pager(0);
						VirtLyne = (ScreenLin - ((ListLigne/2)-1));
						}
					else	{
						Verbose((BPTR)TalkPtr[81]);
						/* "Chaine non-trouve" */
						/* ------------------- */
#ifdef	BEFORE_011295
						PopInfo(); 
#endif
						}
					}
				    }
				MenuPos( VirtLyne );
				}
			continue;

			case	DB_PAGEUP  :	/* Consult Page Up	*/
						/* ---------------	*/
			if (( ListStatus & 1 ) && (ExWindow == 0)) {
				MenuUp( 0 ,((ListLigne / 2) + 1));
				MenuPos( VirtLyne );
				}
			continue;

			case	DB_PAGEDWN :	/* Consult Page Down	*/
						/* -----------------	*/
			if (( ListStatus & 1 ) && (ExWindow == 0)) {
				MenuDwn( 0 ,((ListLigne / 2) + 1));
				MenuPos( VirtLyne );
				}
			continue;

			case	DB_VIEW	   : 	/* Refresh current Page */
						/* -------------------- */
			if (( ListStatus & 1 ) && (ExWindow == 0)) {
				idb_Pager(0);
				MenuPos( VirtLyne );
				}
			continue;

			case	DB_RETURN  :	/* Return to Exec Page	*/
						/* -------------------	*/
				if (( ListStatus & 1 ) && (ExWindow == 0)) {
					if (Konsult == 1) { 
						Konsult = 0;
						PopInfo();
						idb_Pager(0);
						}
					noprompt  = 0;	
					MenuDpos(VirtLyne);
					VirtLyne = (ScreenLin - ((ListLigne/2)-1));
					MenuPos( VirtLyne );
					}
				continue;

			case	DB_HELP	   :	/* HelpScreen Cmds Ctrl	*/
						/* --------------------	*/
			if (( ListStatus & 1 ) && (ExWindow == 0)) {
				helpscr((EXAWORD) 13 , (EXAWORD) 32 );  
				}
			continue;

			case	DB_INFOS   :	/* Bascule Mode Verbose	*/
						/* -------------------- */
				if ( ListStatus & 0x0008 ) { VerboseOff(); 	}
				else			   { VerboseOn();	}
				continue;

			case	DB_EXEC	   :	/* Execute from point   */
						/* ------------------   */

				/* Test for list window active and visible */
				/* --------------------------------------- */
				if (((ListStatus & 1) == 0) || (ExWindow != 0)) {
					continue;
					}

				/* Collect pointed line adresse */
				/* ---------------------------- */
				errno = 0; Madr = idb_Ladr(VirtLyne);

				/* Ensure no error encountered */
				/* --------------------------- */
				if ( errno != 0 ) {
					continue;
					}

				/* Collect Segment/Procedure adresse */
				/* --------------------------------- */
				if (idb_Sadr(VirtLyne,(WPTR) &Mcs , (WPTR) &MPrcSeg ) != 0) {
					continue;
					}

				/* Ensure correct code block type PRC/SEG */
				/* -------------------------------------- */
				if (((MPrcSeg == 0) && (sicico & ONSEM_PRC)) || ((MPrcSeg != 0) && ((sicico & ONSEM_PRC) == 0))) {
					continue;
					}

				/* Ensure correct code block identity */
				/* ---------------------------------- */
				if (((sicico & ONSEM_PRC) == 0) && ( cur_seg != Mcs )) {
					continue;
					}
				if ((sicico & ONSEM_PRC) && ( procid != Mcs )) {
					continue;
					} 

				/* Establish new tcode execution adresse */
				/* ------------------------------------- */
				fdex = (TcodeSegment + Madr); LastTcode = MOINS_UN;

				c = DB_RUN;	/* Force Run Mode       */
						/* -------------------- */

			case	DB_STEP    :	/* Execute Single Step	*/
						/* -------------------	*/

			case	DB_RUN	   :	/* Execute till Break	*/
						/* ------------------	*/
				return( c );

			case	DB_EXITKEY :	/* Exit from Moniter	*/
						/* -----------------	*/
				DbSight();
				return( c );
			}
		   }
		DbSight();
		/* All other Key sequences Arrive here for Cmd Window */
		/* -------------------------------------------------- */
		if ( c > ccc ) {
			if ( y == 0 ) { 
				WdwLimit(5,3,70);
				if (PushZone(WindCord[5][0],WindCord[5][1],3,70,0x0013,Couleurs[5][0],Couleurs[5][1]) != 0) {
					Debordement();
					continue;
					}
				HistCtrl = 0;   
				}
			for ( err = 0; err <= 70; err++) { askbuf[err] = (EXABYTE) 0; }
			nbc = 0;
			while ( nbc < x ) {
				if ( c == IO_RC ) 		{ askbuf[nbc++] = (EXABYTE) 0; AddHist();	break;	}
				if ( c == DB_EXITKEY )		{ if ( y == 0 ) { nbc = 0; break; } 
								  else { return(c); }
								}
				if ( c == syskey[IO_BAK] ) 	{ 
					if ( nbc > 0 ) { 
						nbc--; 
						db_xputch(c);
			 			c = 0;	
						}
					else	{ 
						if ( y == 0 ) { break;     }
						else          { return(c); }
						} 
					}
				if ( c == syskey[IO_FOR] ) 	{ 
					if ( askbuf[nbc] != (EXABYTE) 0 ) {
						db_xputch((EXAWORD) askbuf[nbc++] );
						}
				 	c = 0;	
					}
				if ( c == syskey[IO_UP]  )	{ 
					c = nbc;
					if ( (nbc = UpHist()) > 0 ) { 
						wdw_xpos(1,2);
						while ( c > 0 ) { db_xputch(' '); c--; }
						wdw_xpos(1,2); 
						db_xcprintf((BPTR) askbuf); 
						}
					else	{ nbc = c; }
					c = x_getch(); continue; 
					} 
				if ( c == syskey[IO_BAS] )	{ 
					c = nbc;
					if ((nbc = DwnHist()) > 0) {
						wdw_xpos(1,2);
						while ( c > 0 ) { db_xputch(' '); c--; }
						wdw_xpos(1,2); 
						db_xcprintf((BPTR) askbuf); 
						}
					else	{ nbc = c; }
					c = x_getch(); continue; 
					}
				switch ( c ) {
					case 0        :	break;
					case DB_WIPE  : RazHist();
					case DB_ABORT : 
						wdw_xpos(1,2);
						for (err = 0; err <= nbc; err++ ) { askbuf [err] = (EXABYTE) 0; db_xputch(' '); }
						wdw_xpos(1,2); nbc = 0;
						HistCur = HistDex;
						break;
					default : 
						if ( c >= ' ' ) {
							if ((askbuf[0] != '!') && (askbuf[0] != 'G')) {
								c = toupper(c);
								}
	 						askbuf[nbc++] = (EXABYTE) c; 
							db_xputch( c );
							}
					}
#ifdef	BUF_CICO
				x_bflush();
#endif
				c = x_getch();
				}
			if ( y == 0 ) { PopZone(); HistCtrl = 0; }
			}
		}
	while ( nbc == 0 );
	return(0);	

}
#endif
