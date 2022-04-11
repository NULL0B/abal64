/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBFUNC - C				*/
/*		Version :	1.4c / 2.1a				*/
/*		Date 	:	03/09/1993				*/
/*									*/
/*----------------------------------------------------------------------*/
#define DEBUGGER
#ifndef	EXDBFUNCC
#define	EXDBFUNCC

				/* -----------------------------------	*/
#include "exdebug.h"		/* General debugger definitions		*/
#include "exctype.h"		/* Character types			*/
#include "extcngf.h"		/* NGF Tcode constants			*/
#include "exdbtrap.h"		/* Trap Information			*/
#include "exask.h"		/* ASK Control information		*/
#include "exdbctrl.h"		/* Control key definitions		*/
#include "exdbmimo.h"		/* Mouse definitions			*/
				/* -----------------------------------	*/
EXABYTE	ftc[64];		/* False Tcode matrix			*/
				/* -----------------------------------	*/
#include "exproto1.h"

#ifdef ABAL_CRITERIA

#include "exadsqcr.h"
EXAWORD biderr;
extern long fidseek;

#define lseek(a,b,c) 	(fidseek = b)
#define	creat(a,b) 	EeEad_create(a,b,(WPTR) &biderr )
#define	open(a,b,c)  	EeEad_open(a,b,(WPTR) &biderr )
#define	close(a)	EeEad_close(a)
#define access(a,b)	EeEad_access(a,b)
#define read(a,b,c)	yyread(a,b,c)
#define write(a,b,c)	yywrite(a,b,c)

static EXAWORD yyread(handle,buffer,blen)
EX_FILE_HANDLE handle;
BPTR buffer;
EXAWORD blen;
{ EXALONG	oldpos = fidseek;
  EXAWORD	result;
  	
	result = EeEad_read( handle, buffer, blen );
	if ((result == 0) || (result == 48))
		return((EXAWORD)(fidseek - oldpos));
	else   	return(0xFFFF);
}

static EXAWORD yywrite(handle,buffer,blen)
EX_FILE_HANDLE handle;
BPTR buffer;
EXAWORD blen;
{ EXALONG	oldpos = fidseek;
  EXAWORD	result;
  	
	result = EeEad_write( handle, buffer, blen );
	if (result == 0)	return((EXAWORD)(fidseek - oldpos));
	else 		  	return(0xFFFF);
}

#endif	/* ABAL_CRITERIA */
	/* ------------- */


#ifndef PROLOGUE
#ifndef DOS
#include <signal.h>	/* Definitions for signal trapping routines */
#endif			/* ---------------------------------------- */
#endif

EXTERN	EXABYTE	trad_ver;
EXTERN	EXAWORD	LastJumpKey;
EXTERN	EXAWORD	StopStatus;
EXTERN	EXAWORD	diezfic;
EXTERN	EXAWORD	TabSize;
EXTERN	EXAWORD	simcbd;
EXTERN	EXAWORD	Couleurs[32][2];
EXTERN	BPTR	TalkPtr[];
EXTERN	EXAWORD	ScreenLin,ScreenCol;
EXTERN	EXAWORD	Abuse;
EXTERN	EXABYTE	_tc_mnem[256][5];
EXTERN	EXABYTE	_esc_mnem[256][5];
EXTERN	BINAIRE	_tc_args[256];
EXTERN	BINAIRE	_esc_args[256];
EXTERN	EXABYTE	ngfmnem[40][8];
EXTERN	EXAWORD	ListStatus;
EXTERN	EXAWORD	adr_npr;	/* Secteur Noms des Procedures	*/
EXTERN	EXAWORD	trace;		/* Variable de Trace		*/

EXTERN	EXAWORD	brayk,permdb;

/*	Gestion des variables en observation		*/
/*	------------------------------------		*/

EXTERN	EXAWORD	watchdex;		/* Watch counter			*/
EXTERN	EXAWORD	watchmat[16];		/* Watch matrix				*/
EXTERN	EXAWORD	watchind[16];		/* 1st Index				*/
EXTERN	EXAWORD	watchand[16];		/* 2nd index				*/
EXTERN	EXAWORD	watchtyp[16];		/* Type de Variable			*/
EXTERN	EXAWORD	watchgod[16];		/* Procedure ou Segment (for locales )	*/

/*	Gestion des options Etendus			*/
/*	---------------------------			*/

#ifndef UNIX

EXTERN	BPTR	interface_msg( EXAWORD );

/*	Gestion du fichier Liste (Fnom-L)	*/
/*	---------------------------------	*/
EXTERN	EXAWORD	idb_listgogo(VOID);
EXTERN	EXAWORD	idb_flopen(VOID);
EXTERN	VOID	idb_flclose(VOID);
EXTERN	EXAWORD	idb_fgetc(VOID);
EXTERN	EXAWORD	idb_bgetc(VOID);
EXTERN	VOID	prnlignes(EXAWORD,EXAWORD);

EXAWORD	nametest(BPTR,EXAWORD);
EXAWORD 	thisvarb(EXAWORD,EXAWORD,EXAWORD);
EXAWORD	ExitMethod(EXAWORD);
VOID	Verbose(BPTR);
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

EXTERN	BPTR	interface_msg();

/*	Gestion du fichier Liste (Fnom-L)	*/
/*	---------------------------------	*/

EXTERN	VOID	idb_listgogo();
EXTERN	EXAWORD	idb_flopen();
EXTERN	VOID	idb_flclose();
EXTERN	EXAWORD	idb_fgetc();
EXTERN	EXAWORD	idb_bgetc();
EXTERN	VOID	prnlignes();

EXAWORD	nametest();
EXAWORD 	thisvarb();
EXAWORD	ExitMethod();
VOID	Verbose();
EXAWORD	dberreur();
VOID 	showword();
VOID 	dbmotor();
VOID 	dbstep();
VOID	abalreg();
EXAWORD	dbswit();
EXAWORD 	checks();
EXAWORD	teststop();
EXAWORD	testtrap();
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

#ifdef ABALPSYS
#include "exesc.c"
#endif

BPTR	CmdShift( cmdptr )
BPTR	cmdptr;
{
	while ( (( *cmdptr == ' ' ) || ( *cmdptr == IO_TAB )) && ( *cmdptr != IO_NUL )) { cmdptr++; }
	return( cmdptr );
}


/*
 *	A B A L A S K ( VID , VIND , VAND )
 *	-----------------------------------
 *	Performs IOF ASK function for Debug
 *	Variable modification function
 *	(now performs external re-write ..
 *	.. Since 08/09/1989 )
 *
 */

EXAWORD	abalask( vid , vind , vand )
EXAWORD	vid,vind,vand;
{
	BPTR 	wptr;		/* Tcode pointer storage	*/
	EXAWORD	vidl,vidh;	/* Variable ID values		*/
	EXAWORD	svind,svand;	/* SV registre index 0		*/
	EXAWORD	HoldMask;	/* SV MASK courante	        */
	EXAWORD	HoldHotKey;	/* SV Hotkey courant		*/
	EXAWORD	tcpi;
	EXAWORD	hotres;


	/* Sauve MASK courante */
	/* ------------------- */	
	HoldMask = askmask; HoldHotKey = LastJumpKey;
	
	/* VALID BELL ERROR */
	/* ---------------- */
	askmask = (32 | 2 | 1);

	/* Establish possible Index Registers	*/
	/* ----------------------------------	*/
	svind = ireg [ 0 ];	ireg [ 0 ] = vind;
	svand = areg [ 0 ];	areg [ 0 ] = vand;

	vidl = (vid & 0x00FF);
	vidh = ((vid & 0xFF00) >> 8);

	/* Generate False T-Code : Ask=1:tabv(1)=var			*/
	/* -----------------------------------------			*/
	tcpi = 0;
#ifdef	ABAL21
	ftc[(tcpi++)] = 0x006E; 		/* X = 			*/
	ftc[(tcpi++)] = 0;			/* & 0 Low		*/
	ftc[(tcpi++)] = 0;			/* & 0 High		*/
	ftc[(tcpi++)] = 0x000E; 		/* I = 			*/
	ftc[(tcpi++)] = 0;			/* & 0 Low		*/
	ftc[(tcpi++)] = 0;			/* & 0 High		*/
	ftc[(tcpi++)] = 0x002E; 		/* U = 			*/
	ftc[(tcpi++)] = 0;			/* & 0 Low		*/
	ftc[(tcpi++)] = 0;			/* & 0 High		*/
	ftc[(tcpi++)] = 0x003E; 		/* D = 			*/
	ftc[(tcpi++)] = 0;			/* & 0 Low		*/
	ftc[(tcpi++)] = 0;			/* & 0 High		*/
#endif
	ftc[(tcpi++)] = 0x004C; 		/* ASK			*/
	ftc[(tcpi++)] = vidl;  			/* Varb ID low		*/
	ftc[(tcpi++)] = vidh;			/* Varb ID High		*/

	/* Establish T-Code pointer and Execute then restore pointer	*/
	/* ---------------------------------------------------------	*/
	wptr = fdex; fdex = (BPTR) ftc; (VOID) iowork();

	/* Restore Original MASK */
	/* --------------------- */
	askmask = HoldMask;	hotres = LastJumpKey;

	/* Check for External Variable rewrite needed */
	/* ------------------------------------------ */
	if ( extwrite & 1 ) { 
		(VOID) extrite(worktypw,descptrw,workeepw,workptrw);
		extwrite &= 0x000E;
		}
			/* ------------------------ */
#ifdef ABALME		/* FIELD=E option allowed   */
			/* ------------------------ */

	/* Check for Extended Variable rewrite	*/
	/* -----------------------------------	*/
	if ( extwrite & 2 ) { 

			/* ----------------- */
#ifndef LINEAR_MEM	/* Not Linear Memory */
			/* ----------------- */

		(VOID) xferout(keepvptr,keepvlen,keepvofs); 

	/* ------------ */
#endif	/* ! LINEAR_MEM */
	/* ------------ */
	
		extwrite = 0;

		}
	
	/* ------------ */
#endif	/*   ABALME	*/
	/* ------------ */

	/* Restore Original Registers and T-Code Index	*/
	/* -------------------------------------------	*/
	fdex = wptr; ireg [ 0 ] = svind; areg [ 0 ] = svand;
	LastJumpKey = HoldHotKey;
	return( hotres );

}

VOID	abalprn( vid, vind , vand )
EXAWORD	vid,vind,vand;
{
	BPTR 	wptr;		/* Tcode pointer storage	*/
	EXAWORD	vidl,vidh;	/* Variable ID values		*/
	EXAWORD	svind,svand;	/* SV registre index 0		*/

	svind = ireg [ 0 ];	ireg [ 0 ] = vind;
	svand = areg [ 0 ];	areg [ 0 ] = vand;

	vidl = (vid & 0x00FF);
	vidh = ((vid & 0xFF00) >> 8);
	/* Generate False T-Code : Print=1:tabv(1),var			*/
	/* -------------------------------------------			*/
	ftc[0] = 0x0044; ftc[1]  = vidl; ftc[2] = vidh;  /* PRN(Var)	*/
	ftc[3] = 0x0000;				 /* ESC		*/

	/* Establish T-Code pointer and Execute then restore pointer	*/
	/* ---------------------------------------------------------	*/
	wptr = fdex; fdex = (BPTR) &ftc[0]; (VOID) iowork(); fdex = wptr;
	ireg [ 0 ] = svind; areg [ 0 ] = svand;
	return;
}

#ifdef	MODEL_DBGT

EXAWORD	xLno,xCno;
EXAWORD	xTopLno,xTopCno;
EXAWORD	xMaxLno,xMaxCno;
EXAWORD	xStatus;

VOID	InitLiner( lno, cno, nbl , nbc )
EXAWORD	lno;
EXAWORD	cno;
EXAWORD	nbl;
EXAWORD	nbc;
{
	xLno = lno; xTopLno = lno; 
	xCno = cno; xTopCno = cno;
	xMaxLno = nbl;
	xMaxCno = nbc;
	xStatus = 0;
	db_xpos(xLno++,xCno);
	return;
}

VOID	StreamByte(c)
EXAWORD	c;
{
	if ( c == 9 )
		c = ' ';

	if ( xCno >= xMaxCno )
		xStatus |= 1;

	if ( xStatus == 0 ) {
		db_xputch( c );
		xCno++;
		}
	return;
}
VOID	StreamString( s )
BPTR	s;
{
	while ( *s != (EXABYTE) 0 ) {
		StreamByte( *(s++) );
		}
	return;
} 
VOID	StreamLine()
{
	while ((xCno < xMaxCno) && ((xStatus & 1) == 0)) {
		StreamByte(' ');
		}
	if ( xLno < xMaxLno ) {
		db_xpos(xLno++,(xCno=xTopCno));
		xStatus &= 0xFFFE;
		}
	else	xStatus |= 2;
	return;
}

EXAWORD	not_end_of_tc_window()
{
	if (( xStatus & 2 ) == 0 )
		return( 1 );
	else	return( 0 );
}

VOID	StreamPage()
{
	while ( not_end_of_tc_window() )
		StreamLine(); 
	return;
}

#endif

#ifdef	ABAL14

VOID	TempString( tptr , reg )
BPTR	tptr;
EXAWORD	reg;
{
	EXAWORD	i;
	i = 0;
	while ( *tptr != IO_NUL ) {
		*(TcodeByteStack + worktop + i + 4) = *(tptr++); i++;
		}
	*(TcodeByteStack + worktop + i + 4) = ' '; i++;
	TcodePmot( (TcodeByteStack + worktop) , 3 );
	TcodePmot( (TcodeByteStack + worktop + 2) , i );

	/* Establish Assign Register */
	/* ------------------------- */
	freg [reg] = worktop; xreg [reg] = TEMPDESC;
	return;
}

BPTR	current_tcode_filename()
{
	/* Load file table entry 0 */
	/* ----------------------- */
	lfh = 0; 
	if ((err_val = loadfich()) != 0)
		return((BPTR) 0); 
	else	return( fidname ); 
}

/*
 *	R E L A N C E R ( cmdptr )
 *	--------------------------
 *	Allows a program to be restarted with a command line ARG
 *
 *	Syntax :	G [new_tcode_file] [,arguament]
 *
 */

EXAWORD	ExadbGoFunction;

VOID	Relancer( cmdptr )
BPTR	cmdptr;
{
				/* ------------------------------------ */
	EXAWORD	mode;		/* Options [tcode_file] [,arguament]	*/
	BPTR	tptr;		/* Pointer to tcode file name		*/
	EXAWORD	tlen;		/* Length of Tcode FileName		*/
	BPTR	aptr;		/* Pointer to Arguament			*/
	EXAWORD	alen;		/* Length of Arguament			*/
	EXAWORD	Tcode_Err;	/* Possible Tcode Error Return Value	*/
				/* ------------------------------------ */

	(VOID) VerifPtr( cmdptr );

	/* Remove any white space */
	/* ---------------------- */
	while (((*cmdptr==IO_ESP)||(*cmdptr==IO_TAB))&&(*cmdptr != IO_NUL)) { 
		cmdptr++; 
		}

	/* Establish possible options */
	/* -------------------------- */
	mode = 0; tlen = 0; alen = 0;
	if ( *cmdptr != IO_NUL ) {
		
		/* Scan for new tcode filename */
		/* --------------------------- */
		tptr = cmdptr;
		while ( *cmdptr != IO_NUL ) {
			switch ( *cmdptr ) {
				case IO_ESP : while ( *cmdptr == IO_ESP ) cmdptr++;
				case IO_TAB :
				case ','    :
					break;
				default     :
					cmdptr++; tlen++;
					continue;	
				}
			break;
			}
		
		if (( tlen > 0 ) && ( *cmdptr == ',')) {
			mode = 4;
			}

		/* Terminate if Required */
		/* --------------------- */
		if ( *cmdptr != IO_NUL ) { 
			*(cmdptr++) = (EXABYTE) IO_NUL;
			}

		/* Remove any white space */
		/* ---------------------- */
		while (((*cmdptr==IO_ESP)||(*cmdptr==IO_TAB))&&(*cmdptr != IO_NUL)) { 
			cmdptr++; 
			}

		/* Scan for possible Arguament */
		/* --------------------------- */
		aptr = cmdptr;
		while ( *cmdptr != IO_NUL) { cmdptr++; alen++; }

		if (( tlen > 0 ) && ( alen == 0 ) && ((mode & 4) == 0)) {
			alen = tlen; tlen = 0;
			aptr = tptr;
			}
		mode = 0;
		if ( tlen > 0 ) { mode |= 1;	}
		if ( alen > 0 ) { mode |= 2;	}
		}

	/* Arrival here means ready for Command Execution */
	/* ---------------------------------------------- */
	/* Mode signification				  */
	/* 	0	:	current tcode no ARG	  */
	/* 	1	:	new tcode no ARG	  */
	/* 	2	:	current tcode with ARG	  */
	/* 	3	:	new tcode with ARG	  */
	/* ---------------------------------------------- */

	/* Check for Current Tcode */
	/* ----------------------- */
	if (( mode & 1 ) == 0 ) {

		tptr = current_tcode_filename();


		}

	/* Prepare file name in temporary Zone */
	/* ----------------------------------- */
	TempString( tptr , 1 );

	/* Generate Assign Syntax */
	/* ---------------------- */
	ftc[0] = _NGF_ASSIGN;		/* Operation NGF ASSIGN	*/
	ftc[1] = 0x0017;		/* IMMEDIATE / REGISTRE	*/
	ftc[2] = 0x0010;		/* IMMEDIATE / **FIN**	*/
	ftc[3] = 0x0001; ftc[4] = 0x00;	/* FTI == 1		*/
	ftc[5] = 0x0001;		/* Filename REGISTRE 1	*/
	ftc[6] = 0x00;   ftc[7] = 0x00;	/* Permissions Rien 0	*/

	/* Call to NGF function executeur */
	/* ------------------------------ */
	tptr = fdex; fdex = (BPTR) ftc;
	Tcode_Err = sf_ngf(); fdex = tptr;

	if ( Tcode_Err != SOFTERROR ) {

		/* Generate Chain Syntax */
		/* --------------------- */
		ftc[0] = _NGF_CHAIN;
		
		/* Check for Command line Arg */
		/* -------------------------- */
		if ((mode & 2) == 0) {
			ftc[1] = 0x00;	/* IMMEDIATE / **FIN** 	*/
			ftc[2] = 0x01;	/* FTI Low Byte		*/ 
			ftc[3] = 0x00;	/* FTI High Byte	*/ 
			}
		else	{
			/* Prepare arguament in temporary Zone */
			/* ----------------------------------- */
			TempString( aptr , 1 );
			ftc[1] = 0x0016;		/* IMMEDIATE / REGFIN  	*/
			ftc[2] = 0x0001; ftc[3] = 0x00;	/* FTI == 1		*/
			ftc[4] = 0x0001;		/* Filename REGISTRE 1	*/
			}

		/* Call to NGF function executeur */
		/* ------------------------------ */
		tptr = fdex; fdex = (BPTR) ftc;
		Tcode_Err = sf_ngf(); fdex = tptr;

		/* If no Error then perform STOP */
		/* ----------------------------- */
		if ( Tcode_Err != SOFTERROR ) { 

			/* If no Error due to Stop */
			/* ----------------------- */
			ExadbGoFunction = 1;

			if ( exstop() != SOFTERROR ) { 

				/* Re-Activate any STOPPED program */
				/* ------------------------------- */
				StopStatus = 0;
				}

			ExadbGoFunction = 0;

			}
		}
	return;
}

#endif

VOID	force_mode_verbose()
{
	ListStatus |= 0x0008;
	return; 
}

VOID	Debordement()
{

	force_mode_verbose();

	Verbose((BPTR)TalkPtr[84]);

	/* "Debordement de memoire" */
	/* ------------------------ */
	return;
}

#ifdef	MODEL_DBGT

/*
 *	R E G W O R K ( Reg , Mode )
 *	----------------------------
 *	Mode = 0 : Affichage du continu d'un registre D,S,I,A
 *	Mode = 1 : Saisie Registres D,S,I,A
 */

VOID	regwork( reg , mode )
EXAWORD	reg,mode;
{
	/* ------------------------------- */
	/* MODE == 0 affichage du registre */
	/* MODE == 1 affichage + Saisie	   */
	/* ------------------------------- */

	BPTR	wptr;
	EXAWORD	wlen;
	EXAWORD	cno[6];
	EXAWORD phase,job;
	if ( reg < (diezreg + 4 ) ) {
	   if (PushZone( 6,2,3,(ScreenCol - 2),0x0003 ) != 0 ) {
		Debordement();
		return;
		}
	   do   {
		db_xpos(3,4);
		ColourAtb(1); db_xputch('R'); db_xputch('(');
		intvisi( reg ); db_xputch(')'); ColourAtb(0);

		db_xcprintf((BPTR)"  RD: "); 
		cno[0] = db_xcol(); ColourAtb(2); 
		showword(freg [reg],4); ColourAtb(0);

		db_xcprintf((BPTR)"  RX: ");
		cno[1] = db_xcol(); ColourAtb(2); 
		showword(xreg [reg],4); ColourAtb(0);

		db_xcprintf((BPTR)"  RI: ");
		cno[2] = db_xcol(); ColourAtb(2); 
		showword(ireg [reg],4); ColourAtb(0);

		db_xcprintf((BPTR)"  RA: ");
		cno[3] = db_xcol(); ColourAtb(2); 
		showword(areg [reg],4); ColourAtb(0);

		db_xcprintf((BPTR)"   SP: "); cno[4] = db_xcol();
		ColourAtb(2); showword(ip_next,4);	ColourAtb(0);
		db_xcprintf((BPTR)"  PSP: "); cno[5] = db_xcol();
		ColourAtb(2); showword(mindex,4);	ColourAtb(0);
		db_xputch(' ');
		if ( mode == 1 ) {
		   for (phase =0; phase < 6; phase++ ) {
			db_xpos(3,cno[phase]);
			if ( (wptr = (BPTR) dbstrget(4)) != (BPTR) 0) { 
				wlen = strlen(wptr);
				switch ( phase ) {
					case 0 : freg [reg] = hextoi(wptr,wlen);
						 break;
					case 1 : xreg [reg] = hextoi(wptr,wlen);
						 break;
					case 2 : ireg [reg] = hextoi(wptr,wlen);
						 break;
					case 3 : areg [reg] = hextoi(wptr,wlen);
						 break;
					case 4 : ip_next = hextoi(wptr,wlen);
						 break;
					case 5 : mindex = hextoi(wptr,wlen);
						 break;
					} /* End Switch */
				}  /* End If != (BPTR) 0 */
			} /* End For Phase */
		    } /* End If Mode == 1 */
		    /* Pause and POP */
		    /* ------------- */
			
		    switch ( x_getch() ) {
			case '+'	: if ( reg < (diezreg + 4)) { reg++; }
					  break;
			case '-'	: if ( reg > 0 ) { reg--; }
					  break;
			case '?'	: abalreg( reg ); break;
			default	        : job = 0x001B;	
			}
		     }
		while ( job != 0x001B );
		PopZone();
		} /* End If Registre Valable */
	return;
}

/*
 *	A B A L R E G ( reg )
 *	---------------------
 *	Affichage de l'interpretation d'un registre 
 */

VOID	abalreg( reg )
EXAWORD	reg;
{
	BPTR 	wptr;		/* Tcode pointer storage	*/

	/* Generate False T-Code : Print=1:tabv(1),var			*/
	/* -------------------------------------------			*/
	if (PushZone(6,2,5,(ScreenCol - 2),0x0003) != 0 ) {
		Debordement();
		return;
		}
	ftc[0] = 0x0064; ftc[1]  = reg;  ftc[2] = 0x0000; /* Prn(Reg)	*/
	/* Establish T-Code pointer and Execute then restore pointer	*/
	/* ---------------------------------------------------------	*/
	wptr = fdex; fdex = (BPTR) ftc; (VOID) iowork(); fdex = wptr;
	switch ( ExitMethod(1)) {
		case 0 : PopZone(); break;
		case 1 : LibZone(); break;
		}
	return;
}

/*
 *	R E G I S T R E ()
 *	------------------
 *	Display a set of registers RD : RS : RI : RA
 *
 */

VOID registre(cmdptr)
BPTR	cmdptr;
{
	EXAWORD reg,xl;
	EXAWORD	mode;
	BPTR	wptr;
	EXAWORD	wlen;

	while (( *cmdptr == IO_ESP ) && ( *cmdptr != IO_NUL )) { cmdptr++; }
	if ( *cmdptr == IO_NUL ) { return; }
	wptr = cmdptr; wlen = 0;
	while (( *wptr != '=' ) && ( *wptr != IO_NUL ) && ( *wptr != '?')) { 
		wptr++; wlen++; 
		}
	switch ( *wptr ) {
		case '=' :	mode = 1; break;
		case '?' :	mode = 2; break;
		default	 :	mode = 0; break;
		}
	reg = atoi(cmdptr,wlen); cmdptr = wptr; 
	if ( mode == 2 )	{ abalreg( reg ); return; }
	regwork( reg ,(mode & 1));
	return; 
}


#endif

#ifdef	ABAL14

#ifdef	ABAL21
void	display_assign_entry( nc, nl , item )
EXAWORD	nc;
EXAWORD	nl;
EXAWORD	item;
{
	EXAWORD	hlfh=lfh;
	EXAWORD	l;
	x_bstart();
	if (( lfh = item ) > diezfic )
		left_string( nc, nl, 64, (BPTR) " ");
	else	{
		if ((err_val = loadfich()) != 0) {
			left_string( nc, nl, 64, (BPTR) " ");
			x_bflush();
			lfh = hlfh;
			return;
			};
		db_xpos( nl, nc+1 );
		l = display_integer( item );
		for ( ; l < 6; l++ )
			db_xputch(' ');
		if ( fidname != (BPTR) 0) {
			exadb_strcpy((BPTR) askbuf, (BPTR) fidname );
			if ( fidperm & 1 ) 
				exadb_strcat((BPTR) askbuf,(BPTR) ",WR"); 
			if ( fidperm & 2 ) 
				exadb_strcat((BPTR) askbuf,(BPTR) ",EX");
			if ( fidperm & 4 ) 
				exadb_strcat((BPTR) askbuf,(BPTR) ",C");
			if ( fidperm & 8 ) 
				exadb_strcat((BPTR) askbuf,(BPTR) ",DF"); 
			if (!( fidperm & 16 )) {
				switch (( fidperm & 0x00E0 ) >> 5 ) {		
					case 0 : exadb_strcat((BPTR) askbuf,(BPTR) ",AD"); break;
					case 1 : exadb_strcat((BPTR) askbuf,(BPTR) ",SQ"); break;
					case 2 : exadb_strcat((BPTR) askbuf,(BPTR) ",SI"); break;
					case 3 : exadb_strcat((BPTR) askbuf,(BPTR) ",MC"); break;
					case 4 : exadb_strcat((BPTR) askbuf,(BPTR) ",BD"); break;
					case 7 : exadb_strcat((BPTR) askbuf,(BPTR) ",MC(");
						 exadb_itoa((BPTR) (&askbuf[strlen((BPTR) askbuf)]),fidbd);
						 exadb_strcat((BPTR) askbuf,(BPTR) ")" );

					}
				}
			exadb_strcat((BPTR) askbuf,(BPTR) "[" );
			exadb_itoa((BPTR) (&askbuf[exadb_strlen((BPTR) askbuf)]),fidreel);
			exadb_strcat((BPTR) askbuf,(BPTR) "]" );
			left_string( nc+7, nl, 57, (BPTR) askbuf  );
			}
		else	left_string( nc+7, nl, 57, (BPTR) " " );
		}
	x_bflush();
	lfh = hlfh;
	return;
}

void	display_assign_page( tc, tl, entry, nb )
EXAWORD	tc;
EXAWORD	tl;
EXAWORD	entry;
EXAWORD	nb;
{
	EXAWORD	item;
	for ( item = 0; item < nb; item++ )
		display_assign_entry( tc, tl+item, (entry+item) );
	return;
}

void	display_assign_table(entry)
EXAWORD	entry;
{
	EXAWORD	item=0;
	EXAWORD	c;
	EXAWORD	x;
	EXAWORD	maxlines=13;
	EXAWORD	toplin=6;
	EXAWORD	topcol=2;
	EXAWORD	nbcol=64;
	EXAWORD	findentry=0;

	maxlines = avoid_observations( 13 );
	if (!( maxlines & 1 ))
		maxlines--;

	mouse_title_box(topcol, toplin, nbcol, maxlines, (BPTR) interface_msg(163) );
	display_assign_page( (topcol+1), (toplin+1), entry, maxlines );
	while ( 1 ) {
		symbolic_atribut(2);
		display_assign_entry((topcol+1), (toplin+1+item), (entry+item) );
		symbolic_atribut(0);
		c = mouse_or_keyboard();
		display_assign_entry( (topcol+1), (toplin+1+item), (entry+item) );
		switch ( c ) {
			case	CTRL_F :
				if ((findentry = standard_integer_ask( (BPTR) "Assign Number ")) != MOINS_UN) {
					entry = findentry;
					item = 0;
					break;
					}
				continue;

			case	0x001B :
				pop_mouse();
				return;

			case	CTRL_E	:
				if ( item < (maxlines-1) )
					item++;
				else	{
					entry++;
					break;
					}
				continue;

			case	CTRL_L	:
				item = entry = 0;
				break;

			case	CTRL_K	:
				if ( item > 0  )
					item--;
				else if ( entry > 0 ) {
					entry--;
					break;
					}
				continue;

			case	CTRL_C	:
				for ( x=0; x < (maxlines/2); x++ )
					entry++;
				break;

			case	CTRL_R	:
				for ( x=0; x < (maxlines/2); x++ )
					if ( entry == 0 )
						break;
					else	entry--;
				break;

			case	CTRL_D	:
				if ( DbMouse.position != 0 )
					item = (DbMouse.position - 1);
				continue;
			}
		display_assign_page((topcol+1) ,(toplin+1), entry, maxlines );
		}

}

VOID	fichview( cmdptr )
BPTR	cmdptr;
{
	EXAWORD	xl;
	EXAWORD	start=0;
	EXAWORD	breakpoint=0;

	while (( *cmdptr == IO_ESP ) && ( *cmdptr != IO_NUL)) 
		cmdptr++; 

	if ( *cmdptr != IO_NUL ) {
		if ( *cmdptr == '=' )
			breakpoint = *(cmdptr++);

		xl = strlen(cmdptr); 
		start = atoi(cmdptr,xl);
		if ( breakpoint ) {
			set_debug_assign( start );
			return;
			}
		}

	if ( start <=  diezfic ) 
		display_assign_table( start );

	return;
}
#else	/* Prior to ABAL 2.1 */
	/* ----------------- */

#include "exdbfich.c"

#endif

#endif

#ifdef	MODEL_DBGT

EXAWORD	AoNbl;
EXAWORD	AoNbc;


EXAWORD	OutputTcodeListe(lno,cno,nbl,nbc,mode,sptr,si)
EXAWORD	lno;
EXAWORD	cno;
EXAWORD	nbl;
EXAWORD	nbc;
EXAWORD	mode;
BPTR	sptr;
EXAWORD	si;
{
	EXAWORD	seq_len;
	EXAWORD	holder;
	EXAWORD	tcode;
	EXAWORD	courrant;

	/* Save Window Zone and display window */
	/* ----------------------------------- */
	if (PushZone(lno,cno,nbl,nbc,(mode | 0x0013),Couleurs[14][0],Couleurs[14][1]) != 0) {
		Debordement();
		return;
		}
	AoNbl = nbl; AoNbc = nbc; courrant = 2;

	/* Initialise Tcode list function stream manager */
	/* --------------------------------------------- */
	InitLiner((lno+1),(cno+1), nbl ,(nbc-1));
	ColourAtb(courrant);
	do 	{

		/* Check validity of Tcode Pointer */
		/* ------------------------------- */
		if ( VerifPtr( (sptr + si) ) != 0 ) {
			break;
			}

		/* Watch out for and Indicate Break Points */
		/* --------------------------------------- */
		if ((holder = *(sptr + si)) == _tc_NOP ) {
			if ((tcode = real_tcode( si )) != MOINS_UN ){
				*(sptr + si) = tcode;	
				ColourAtb(1);
				}
			}

		/* Liste Current Adresse */
		/* --------------------- */
		seq_len = TcodeList( sptr , si , 0);

		/* Check for and Reposition Break Points */
		/* ------------------------------------- */
		if (( holder == _tc_NOP ) && ( tcode != MOINS_UN )) {
			*(sptr + si) = _tc_NOP;
			ColourAtb(courrant);
			}

		/* Nothing to do !!! */
		/* ----------------- */
		if ( seq_len == 0 )
			break;

		/* Position to next Sequence */
		/* ------------------------- */
		si += seq_len;
		
		/* Check for end of current Tcode Sequence */
		/* --------------------------------------- */
		if (( *(sptr + si) & 0x0080 )
		&& ( courrant ))	 
			ColourAtb((courrant=0));


		}
	while ( not_end_of_tc_window() );

	return(si);
}

VOID	ExamineTcode(lno,cno,nbl,nbc,sptr,si)
EXAWORD	lno;
EXAWORD	cno;
EXAWORD	nbl;
EXAWORD	nbc;
BPTR	sptr;
EXAWORD	si;
{
	EXAWORD	x;

	do	{
		/* Perform Tcode Listing */
		/* --------------------- */
		si = OutputTcodeListe(lno,cno,nbl,nbc,0,sptr,si);

		/* Detect User Exit Method */
		/* ----------------------- */
		switch ((x = ExitMethod(2))) {
			case 0 : PopZone(); break;
			case 2 :
			case 1 : LibZone(); break;
			}
		}
	while ( x == 2 );

	return;

}

/*
 *	L I S T E T C O D E ( )
 *	-----------------------
 *
 */
VOID	ListeTcode(lno,cno,nbl,nbc)
EXAWORD	lno;
EXAWORD	cno;
EXAWORD	nbl;
EXAWORD	nbc;
{
	EXAWORD	mode;
	EXAWORD	ici;

	/* Calculate Tcode Adresse */
	/* ----------------------- */
	if ( fdex == TcodeSegment )
		ici = 0;
	else	ici = (EXAWORD) ((fdex - TcodeSegment) - 1);

	/* Detect if TCODE window Size has changed */
	/* --------------------------------------- */
	if ((AoNbl != nbl) || (AoNbc != nbc))
		mode = 0;
	else	mode = 0;

	/* Perform Tcode Listing */
	/* --------------------- */
	(VOID) OutputTcodeListe(lno,cno,nbl,nbc,mode,TcodeSegment,ici);


	/* Liberate Pushed Window */
	/* ---------------------- */
	LibZone();
	return;

}

#endif

VOID	clear_info_line( cur_col )
EXAWORD	cur_col;
{
	atb(21);
/*	
 *	while ( cur_col < ScreenCol ) {
 *		db_xputch(' ');
 *		cur_col++;
 *		}
 */
	return;

}


VOID	Verbose_version1( msgptr )
BPTR	msgptr;
{
	EXAWORD	lno,cno,natb,lcno,lpaint,msgl;
	
if ( ListStatus & 0x0008 ) {
	if ( ScreenCol > 30 ) {
		lno 	= db_xlin(); 
		cno 	= db_xcol(); 
		natb	= wotatb();
		lpaint	= (wotfore() | (wotback() << 4));
		WindowOff();
#ifdef BUF_CICO
		x_bstart();
#endif
		db_xpos(ScreenLin,30); 
		clear_info_line(30);
		ColourAtb(2);
		if ( (msgl = strlen(msgptr)) > (ScreenCol - 32) ) {
			*(msgptr + (ScreenCol - 32)) = (EXABYTE) 0;
			}
		if ( msgl > 0 ) {
			db_xputch(' '); 
			db_xcprintf( (BPTR) msgptr ); 
			db_xputch(' ');
			}
		ColourAtb(0);
		db_xpos(lno,cno); 
		db_xatb(natb); 
		Painter((lpaint & 0x000F),(lpaint >> 4));
#ifdef BUF_CICO
		x_bflush();
#endif
		WindowOn();
		Abuse = 2;
		}
	}
else	Abuse = 0;
return;
}

VOID	Verbose( mptr )
BPTR	mptr;
{
#ifdef	ABAL21
	if ( trad_ver > '1' )
		standard_message( (BPTR) mptr );
	else
#endif
		Verbose_version1( (BPTR) mptr );
	return;
}

VOID	VerboseOn()
{
	EXAWORD	lno,cno;
	lno = db_xlin(); cno = db_xcol();
	ListStatus |= 0x0008;
	WhereAreWe(ScreenLin,1);
	Verbose((BPTR)"\0");
	db_xpos(lno,cno);
	return; 
}

VOID	VerboseOff()
{
	EXAWORD	lno,cno;
	lno = db_xlin(); cno = db_xcol();
	db_xpos(ScreenLin,1); 
	clear_info_line(1);
	db_xpos(lno,cno);
	ListStatus &= 0xFFF7;
	return;

}

EXAWORD	Validate(how)
EXAWORD	how;
{
	EXAWORD	l,k;
	l = ListStatus;
	ListStatus |= 0x0008;
	switch ( how )  {
#ifndef	ABAL21
		case 2 :
#endif
		case 0 :
			Verbose((BPTR)TalkPtr[82]);
			/* "Appuyez sur une touche pour continuer" */
			/* --------------------------------------- */
			break;
		case 1 :
			Verbose((BPTR)TalkPtr[83]);
			/* "ESC pour arreter" */
			/* ------------------ */
			break;
#ifdef	ABAL21
		case 2 :
			centered_string(2,22,78,(BPTR) TalkPtr[82] );
			db_xpos( 22, 2 );
			break;
#endif
		}
	k = x_getch();
	Verbose((BPTR)"\0");
	ListStatus = l;
	return(k);
}

EXAWORD	ExitMethod(e)
EXAWORD	e;
{
	EXAWORD	x;
	while (1) {
#ifdef	ABAL21
		x = mouse_or_keyboard();
#else
		x = db_xgetch();
#endif
		switch ( x ) {
			case IO_ESC : return(0);
			case 0x0004 :
			case 0x000D : return(1);
			case 0x0003 :
			case 0x000C :
			case 0x0012 :
			case 0x0020 : if ( e & 2 ) { return(2); } 
			}
		}
	return(0);
}

#ifndef PROLOGUE
#ifndef DOS
EXAWORD	VerifVal;		/* Verifiction Flag for PTR Check */
EXABYTE	VerifZ2;		/* Legal Adresse for Signal Trap  */
BPTR	VerifZ1;		/* Pointer to be Checked	  */

VOID	VerifTrp( sigid )
int	sigid;
{
	VerifZ1 = &VerifZ2;
	VerifVal = 1;
}

EXAWORD	VerifPtr( wptr )
BPTR	wptr;
{
	EXAWORD	x;

	int	(*HoldBus)();
	int	(*HoldMem)();

	VerifVal = 0;
	VerifZ1 = wptr;
	HoldBus = signal( SIGBUS , VerifTrp );
	HoldMem = signal( SIGSEGV , VerifTrp);
	x = (EXAWORD) *VerifZ1;	
	(VOID) signal( SIGBUS , HoldBus );
	(VOID) signal( SIGSEGV, HoldMem );
	return( VerifVal );
}
#else	/* DOS !!! */
/*
	EXAWORD	VerifPtr( wptr )
	BPTR	wptr;
	{
		return(0);
	}
*/

#endif
#endif

/*	-------------------------------		*/
/*	Gestion des parametres du EXADB		*/
/*	-------------------------------		*/
/*	Couleurs des fenetres			*/
/*	Tabulations				*/
/*	Touche d'echappement			*/
/*	Touche de bascule Fenetres (Ctrl W)	*/
/*	Positionement des fenetres		*/
/*	-------------------------------		*/

#define	PARASIZE	256

static	char	ParaNomf[] = "exadb.cfg";

EXAWORD	WindCord[16][2];
EXAWORD	ctrlx,ctrly;

EX_FILE_HANDLE ParaFile( mode )
EXAWORD	mode;
{
	EX_FILE_HANDLE llog;
	EXAWORD	perm;
	BPTR	fnom;
	fnom = (BPTR) ParaNomf;
#ifdef	UNIX
	perm = 0666;
#else
	perm = 0x0001;
#endif
	if ( access(fnom,0) == 0 ) {
#ifdef	UNIX
		llog = open(fnom,perm,0);
#else
		llog = open(fnom,perm);
#endif
		}
	else	{
		if ( mode == 1 ) {	/* Sauve Parametres */
			llog = creat(fnom,perm);
			close( llog );
#ifdef UNIX
			llog = open(fnom,perm,0);
#else
			llog = open(fnom,perm);
#endif
			}
		else	{
			llog = EX_UNUSED_HANDLE;
			}
			
		}
	return( llog );
}

VOID	ParaSauve()
{
	BPTR	bptr;
	EXAWORD	x,i;
	EX_FILE_HANDLE nlog;
	if (( nlog = ParaFile(1)) != EX_UNUSED_HANDLE) {
		/* Allocate Temporary Buffer */
		/* ------------------------- */
		if ((bptr = (BPTR) allocate( PARASIZE )) != (BPTR) 0 ) {
			/* Transfer From Working Matrices */
			/* ------------------------------ */
			for ( x = 0, i = 0; x < 16 ; x++ ) {
				TcodePmot( (bptr + i)              , (WindCord[x][0]));
				TcodePmot( (bptr + i + WORDSIZE)       , (WindCord[x][1]));
				TcodePmot( (bptr + i + (2 * WORDSIZE)) , (Couleurs[x][0]));
				TcodePmot( (bptr + i + (3 * WORDSIZE)) , (Couleurs[x][1]));
				i = i + ( 4 * WORDSIZE );
				}
			TcodePmot( (bptr + i)       , TabSize );
			TcodePmot( (bptr + i + WORDSIZE), brayk   );

			/* Write to Parameter File */
			/* ----------------------- */
			lseek(nlog,0L,SEEK_SET);
			simcbd = 0x20A0;
			(VOID) write(nlog,(BPTR) bptr , PARASIZE );
			liberate( bptr );
			}
		else	{
			Debordement();
			}
		close( nlog );
		}
	return;
}

VOID	ParaCharge()
{
#ifdef	BEFORE_011295
	EX_FILE_HANDLE nlog;
	EXAWORD	x,i;
	BPTR	bptr;
	
	ctrlx = 0; ctrly = 0;

	/* Attempt to open Parameter File */
	/* ------------------------------ */
	if (( nlog = ParaFile(0)) != EX_UNUSED_HANDLE ) {
		/* Allocate Temporary Buffer */
		/* ------------------------- */
		if ((bptr = (BPTR) allocate( PARASIZE )) != (BPTR) 0 ) {
			/* Read From Parameter File */
			/* ------------------------ */
			lseek(nlog,0L,SEEK_SET);
			simcbd = 0x2060;
			if ( read(nlog,(BPTR) bptr , PARASIZE ) == PARASIZE ) {
				/* Transfer to Working Matrices */
				/* ---------------------------- */
				for ( x = 0, i = 0; x < 16 ; x++ ) {
					WindCord[x][0] = Tcodeword( (bptr + i) );
					WindCord[x][1] = Tcodeword( (bptr + i + WORDSIZE) );
					Couleurs[x][0] = Tcodeword( (bptr + i + (2 * WORDSIZE)) );
					Couleurs[x][1] = Tcodeword( (bptr + i + (3 * WORDSIZE)) );
					i = i + ( 4 * WORDSIZE );
					}
				TabSize = Tcodeword( (bptr + i) );
				brayk   = Tcodeword( (bptr + i + WORDSIZE) );
				}
			liberate( bptr );
			}
		else	{
			Debordement();
			}
		close( nlog );
		}
#endif
	return;
}

/*	Modification of Parametres	*/
/*	--------------------------	*/

VOID	WdwLimit( wdw , nbl , nbc ) 
EXAWORD	wdw,nbl,nbc;
{
	/* Control Starting Position feasabillity */
	/* -------------------------------------- */
	if ( WindCord[wdw][1] > ( ScreenCol - nbc ) ) {
		WindCord[wdw][1] = (ScreenCol - nbc);
		}
	if ( WindCord[wdw][0] > ( ScreenLin - nbl ) ) {
		WindCord[wdw][0] = (ScreenLin - nbl );
		}
	if (((BINAIRE) WindCord[wdw][0] ) <= 0 ) {
		WindCord[wdw][0] = 1;
		}
	if (((BINAIRE) WindCord[wdw][1] ) <= 0 ) {
		WindCord[wdw][1] = 1;
		}
	return;
}

VOID	ParaNorm(x,y)
EXAWORD	x,y;
{
	switch ( y ) {
	case 0 :
	if ( x != 14 ) {
		wdw_xpos(x+2,38);
		db_xcprintf((BPTR)"   ");
		wdw_xpos(x+2,38);
		intvisi(WindCord[x][0]);	/* Column ID 	*/	
		wdw_xpos(x+2,38);
		}
	break;
	case 1 :
		wdw_xpos(x+2,43);
		db_xcprintf((BPTR)"   ");
		wdw_xpos(x+2,43);
		intvisi(WindCord[x][1]);	/* Line ID	*/
		db_xputch(' ');
		wdw_xpos(x+2,43);
		break;
	case 2 :
		wdw_xpos(x+2,48);
		db_xcprintf((BPTR)"   ");
		wdw_xpos(x+2,48);
		intvisi(Couleurs[x][0]);	/* Colour Fore  */
		db_xputch(' ');
		wdw_xpos(x+2,48);
		break;
	case 3 :
		wdw_xpos(x+2,53);
		db_xcprintf((BPTR)"   ");
		wdw_xpos(x+2,53);
		intvisi(Couleurs[x][1]);	/* Colour Back	*/
		db_xputch(' ');
		wdw_xpos(x+2,53);

	}
return;
}

VOID	ParaHigh(x,y)
EXAWORD	x,y;
{
	ColourAtb(2);
	ParaNorm(x,y);
	ColourAtb(0);
	return;
}


VOID	ParaPlus(x,y)
EXAWORD	x,y;
{
	ParaNorm(x,y);
	switch ( y ) {
		case 0 : if ( WindCord[x][0] < ScreenLin ) {
				WindCord[x][0] += 1;
				}
			else	{
				WindCord[x][0] = 1;
				}
			break;
		case 1 : if ( WindCord[x][1] < ScreenCol ) {
				WindCord[x][1] += 1;
				}
			else	{
				WindCord[x][1] = 1;
				}
			break;
		case 2 : if ( Couleurs[x][0] < 15 ) {
				Couleurs[x][0] += 1;
				}
			else	{
				Couleurs[x][0] = 0;
				}
			break;
		case 3 : if ( Couleurs[x][1] < 7 ) {
				Couleurs[x][1] += 1;
				}
			break;
		}	
	ParaHigh(x,y);
	return;
}

VOID	ParaLess(x,y)
EXAWORD	x,y;
{
	ParaNorm(x,y);
	switch ( y ) {
		case 0 : if ( WindCord[x][0] > 1 ) {
				WindCord[x][0] -= 1;
				}
			else	{
				WindCord[x][0] = 1;
				}
			break;
		case 1 : if ( WindCord[x][1] > 1 ) {
				WindCord[x][1] -= 1;
				}
			else	{
				WindCord[x][1] = 1;
				}
			break;
		case 2 : if ( Couleurs[x][0] > 0 ) {
				Couleurs[x][0] -= 1;
				}
			else	{
				Couleurs[x][0] = 15;
				}
			break;
		case 3 : if ( Couleurs[x][1] > 0 ) {
				Couleurs[x][1] -= 1;
				}
			else	{
				Couleurs[x][1] = 7;
				}
			break;
		}	
	ParaHigh(x,y);
	return;
}


VOID	ParaModif()
{
	EXAWORD	x,y;
	EXAWORD	width,ylimit;

	if ( conf(14) == 1 ) { width = 57; ylimit = 3; }
	else		     { width = 47; ylimit = 1; }
	
	WdwLimit(11,19,width);

	/* Sauvegarde et generation du fenetre */
	/* ----------------------------------- */
	if ( PushZone(WindCord[11][0],WindCord[11][1],19,width,0x0013,Couleurs[11][0],Couleurs[11][1]) != 0 ) {
		Debordement();
		return;
		}

#ifdef	BUF_CICO
	x_bstart();
#endif

	/* Titre du Fenetre */
	/* ---------------- */
	wdw_xpos(1,2);
	ColourAtb(2);
	db_xcprintf((BPTR)TalkPtr[93]);
	ColourAtb(0);
	
	/* Affichage des parametres courantes */
	/* ---------------------------------- */
	for (x = 0; x < 15; x++ ) {
		wdw_xpos(x+2,2);
		db_xcprintf((BPTR)TalkPtr[(x+94)]);
		for ( y = 0; y <= ylimit; y++ ) {
			ParaNorm(x,y);
			}
		}

	/* Saisie des Parametres */
	/* --------------------- */

	ParaHigh(ctrlx,ctrly);

#ifdef	BUF_CICO
	x_bflush();
#endif

	while ( 1 ) {
		x = x_getch();
		if ( x == IO_ESC ) { PopZone(); return; }
		if ( x == syskey[IO_UP] ) {
			ParaNorm(ctrlx,ctrly);
			if ( ctrlx > 0  ) { ctrlx--;	 	}
			else		  { ctrlx = 14;		}
			ParaHigh(ctrlx,ctrly);
			continue;
			}
		if ( x == syskey[IO_BAS]) {
			ParaNorm(ctrlx,ctrly);
			if ( ctrlx < 14 ) { ctrlx++; 		}
			else		  { ctrlx = 0;		}
			ParaHigh(ctrlx,ctrly);
			continue;
			}
		if ( x == 0x0008 ) {
			ParaNorm(ctrlx,ctrly);
			if ( ctrly > 0  ) { ctrly--;	 		}
			else		  { ctrly = ylimit;		}
			if (( ctrlx == 14 ) && ( ctrly == 0 )) { ctrly = ylimit; }
			ParaHigh(ctrlx,ctrly);
			continue;
			}
		if ( x == 0x0006 ) {
			ParaNorm(ctrlx,ctrly);
			if ( ctrly < ylimit ) 	{ ctrly++;	 	}
			else		  	{ ctrly = 0;		}
			if (( ctrlx == 14 ) && ( ctrly == 0 )) { ctrly = 1; }
			ParaHigh(ctrlx,ctrly);
			continue;
			}
		if ( x == '+' ) {
			ParaPlus(ctrlx,ctrly);
			continue;
			}
		if ( x == '-' ) {
			ParaLess(ctrlx,ctrly);
			continue;
			}
	

		}

}

/*	Parameter Menu		*/
/*	--------------		*/

VOID	ParamMenu()
{
	EXAWORD	x,ctrl,y;
	EXAWORD	width;

	width = 0; ctrl = 0;

	/* Calculate Menu Width Required */
	/* ----------------------------- */
	for ( x = 0; x < 3; x++ ) {
		if ((y = strlen(TalkPtr[(x+90)])) > width) {
			width = y;
			}
		}

	width += 4;

	/* Ensure and Correct feasability */
	/* ------------------------------ */
	WdwLimit( 0 , 5 , width );
	
	while ( 1 )	{

	/* Save Window Zone and display window */
	/* ----------------------------------- */
	if ( PushZone(6,2,5,width,0x0013,Couleurs[0][0],Couleurs[0][1]) != 0 ) {
		Debordement();
		return;
		}
#ifdef	BUF_CICO
	x_bstart();
#endif
	/* Display menu Strings */
	/* -------------------- */
	for (x = 0; x < 3; x++ ) {
		if ( x == ctrl ) {
			wdw_xpos((x+1),2);
			ColourAtb(2);
			db_xcprintf((BPTR)TalkPtr[(x+90)]);
			ColourAtb(0);
			}
		else	{
			wdw_xpos((x+1),2);
			db_xcprintf((BPTR)TalkPtr[(x+90)]);
			}
		}
#ifdef	BUF_CICO
	x_bflush();
#endif

	/* Enter Menu Choice Loop */
	/* ---------------------- */
	x    = 0;
	while ( x == 0 ) {
		x = x_getch();

		/* Escape Means Exit */
		/* ----------------- */
		if ( x == IO_ESC ) { x = MOINS_UN; continue; }

		/* Up Arrow Menu Choice */
		/* -------------------- */
		if ( x == syskey[IO_UP] ) {
			wdw_xpos((ctrl+1),2);
			db_xcprintf((BPTR)TalkPtr[(ctrl+90)]);
			if ( ctrl > 0 ) { ctrl--; }
			else		{ ctrl=2; }
			x = 0;
			wdw_xpos((ctrl+1),2);
			ColourAtb(2);
			db_xcprintf((BPTR)TalkPtr[(ctrl+90)]);
			ColourAtb(0);
			continue;
			}

		/* Down Arrow Menu Choice */
		/* ---------------------- */
		if ( x == syskey[IO_BAS] ) {
			wdw_xpos((ctrl+1),2);
			db_xcprintf((BPTR)TalkPtr[(ctrl+90)]);
			if ( ctrl < 2 ) { ctrl++; }
			else		{ ctrl=0; }
			x = 0;
			wdw_xpos((ctrl+1),2);
			ColourAtb(2);
			db_xcprintf((BPTR)TalkPtr[(ctrl+90)]);
			ColourAtb(0);
			continue;
			}

		/* Validation Accept Menu Choice */
		/* ----------------------------- */
		if ( x == 0x000D ) { x = (ctrl + 1); continue;  }
		
		/* All other keys Ignored */
		/* ---------------------- */
		x = 0;
		}

	/* Restore Original Window Zone */
	/* ---------------------------- */
	PopZone();

	/* Check for Exit Choice */
	/* --------------------- */
	if ( x == MOINS_UN ) { return; }

	/* Perform Selected Choice */
	/* ----------------------- */
	switch ( ctrl ) {
		case 0 :	/* Modify Parametres */
				/* ----------------- */
			ParaModif(); continue;

		case 1 :	/* Save Parameters   */
				/* ---------------   */
			ParaSauve(); continue;

		case 2 :	/* Load Parameters   */
				/* ---------------   */
			ParaCharge(); continue;

		}
	}

}

#ifndef	ABAL21
#define XPTR SPTR
#include "exdbhist.c"
#endif

EXAWORD	CompWild( tptr , wptr )
BPTR	tptr;
BPTR	wptr;
{
	EXAWORD	wlen,tlen;

	wlen = strlen(wptr); tlen = strlen(tptr);

	while (( tlen > 0 ) && (wlen > 0)) {

		switch ( *wptr ) {
			case '*' : if ( CompWild( tptr , (wptr + 1)) == 0 ) {
					return(0);
					}
				   tptr++; tlen--;
				   continue; 
			default  : if ( *tptr != *wptr ) { return(MOINS_UN); }
			case '?' : wptr++; tptr++; wlen--; tlen--; continue;
			}
		}
	if (( tlen == 0 ) && ( wlen == 0 )) { return(0); }
	if ( tlen == 0 ) {
		while ( wlen > 0 ) {
			if (( *wptr != '*' ) && ( *wptr != '?' )) { return(MOINS_UN); }
			wlen--; wptr++;
			}
		return(0);
		}
	if (( wlen == 0 ) && ( *(wptr - 1) == '*')) { return(0); }
	return(MOINS_UN);

}

#endif	/* EXDBFUNCC */
	/* --------- */
