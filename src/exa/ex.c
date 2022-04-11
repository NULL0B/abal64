/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EX - C  				*/
/*		Version :	1.2d / 1.3c 				*/
/*		Date 	:	16/01/1997				*/
/*									*/
/*----------------------------------------------------------------------*/

#include "exmain.h"		/* Header file for EXA EXI EXD		*/

/* 03/01/97: Pour agf */
#include "pubagf.h"


#ifdef	DEBUGGER		/* If Model Debugger			*/
#include "exadb.h"		/* Include ExaDb Specific Header	*/
#include "exadbdef.h"		/* Debugger flag Definitions		*/
extern	UBINAIR	DbinitOk;	/* Debug Init Control Status		*/
#endif

/*	Gestion de messages compatible GESMES		*/
/*	-------------------------------------		*/
#ifndef	MSG_HX
#include "exgesmes.c"		/* Include the Message Manager		*/
#else
#include "exmsg.c"		/* Alternative message format		*/
#endif

extern	int	errno;		/* Global System Error Variable		*/

#ifndef	UNIX
UBINAIR	allocetd(UBINAIR);
#else
UBINAIR	allocetd();
#endif

#ifndef	COEXA
#ifndef	PROLOGUE
#ifndef	DOS
UBINAIR	Access(fnom,arg1,arg2)
EXBPTR	fnom;
UBINAIR	arg1,arg2;
{
	return(access(fnom,arg1));
}
#endif
#endif
#endif


/*
 *	X _ N E W L Y N E ( )
 *	---------------------
 *	Saut de ligne a l'ecran pour la baniere et les erreurs
 */
void	x_newlyne()
{
	x_putch('\r'); x_putch('\n');
	return;
}

/* 
 *	I T O X X X X ( v , dest )
 *	--------------------------
 * 	Conversion Integer 16 bits en Chaine Hexadeciamle (%04.1X)
 *
 */
	
void	itoxxxx(v,dest,s)
UBINAIR	v;			/*	Integer to convert to HEXA	*/
EXBPTR	dest;			/*	Destination for storage		*/
UBINAIR	s;
{
	register UBINAIR x,y;
if ( s > 3 ) {
	x = (v & 0xF000) >>12;
	if ( x > 9 ) { y = (( x-9) | 0x0040); }
	else { y = (x | 0x0030); }
	*dest = (EXABYTE) y; dest++;
	}
if ( s > 2 ) {	
	x = (v & 0x0F00) >>8;	
	if ( x > 9 ) { y = ((x-9) | 0x0040); }
	else { y = (x | 0x0030); }
	*dest = (EXABYTE) y; dest++;
	}
if ( s > 1 ) {
	x = (v & 0x00F0) >>4;	
	if ( x > 9 ) { y = ((x-9) | 0x0040); }
	else { y = (x | 0x0030); }
	*dest = (EXABYTE) y; dest++;
	}
if ( s > 0 ) {
	x = (v & 0x000F);
	if ( x > 9 ) { y = ((x-9) | 0x0040); }
	else { y = (x | 0x0030); }
	*(dest++) = (EXABYTE) y; 
	*dest = IO_ESP;
	}
	return;
}

/*
 *	S H O W W O R D ( v )
 *	---------------------
 *	Affichage Hexadecimale d'un EXAWORD
 *
 */

void showword( v,s )
UBINAIR	v,s;
{
	itoxxxx(v,(EXBPTR) askbuf,s);
	askbuf[s] = (EXABYTE) 0;
	x_cprintf((EXBPTR)askbuf);
	return;
}

/*
 *	I N T V I S I ( e )
 *	-------------------
 *	Affichage d'une valeur Integer
 */
void	intvisi( e )
UBINAIR	e;
{
	itoa(e,(EXBPTR) askbuf,7); x_cprintf((EXBPTR) askbuf);
	return;
}

/*
 *	B A N N E R
 *	-----------
 *	Affichage de la bannier de ABAL
 */

UBINAIR	banner()
{

if ((sicico & ONSEM_CIO ) == 0) { 
#ifdef	DOS
	Trap24();
#endif
	initerm(); lsyskey(); 
	sicico |= ONSEM_CIO; 
	}

x_newlyne(); x_cprintf((EXBPTR)"   ");
x_cprintf((EXBPTR) TalkPtr[1]); x_cprintf((EXBPTR)"   Version ");

/* Affichage du Version.Index(Release) */
/* ----------------------------------- */

x_putch(ABAL_Version);
x_putch('.'); 
x_putch(ABAL_Index);
x_putch(ABAL_Release);
x_cprintf((EXBPTR)ABAL_Prov);
x_putch(' ');


#ifdef PROLOGUE
#ifdef PROTEGE_286
	x_cprintf((EXBPTR)"-P3");
#endif
#endif


/*	Ligne d'identification Suplimentaire	*/
/*	------------------------------------	*/

#if ABAL_Index == '2'
x_newlyne(); x_cprintf((EXBPTR)"   ");
#ifdef	DEBUGGER
x_cprintf((EXBPTR) TalkPtr[64]);
#else
x_cprintf((EXBPTR) TalkPtr[13]);
#endif
x_putch(' ');
#ifdef BOS
x_cprintf((EXBPTR) " (B.O.S.) ");
#endif
#endif
#endif


/*	Copyright Amenesik / Sologic s.a.		*/
/*	-----------------------		*/

x_newlyne(); x_cprintf((EXBPTR)"   Copyright (c) 1988,1990  Amenesik / Sologic s.a. ");

/*	Options de l'Executeur		*/
/*	----------------------		*/

x_newlyne(); x_cprintf((EXBPTR)"   Options : ");

#ifdef COEXA
	x_cprintf((EXBPTR)"ACC ");
#endif
#ifdef DEBUGGER
	x_cprintf((EXBPTR)"DB ");
#endif

#ifdef ABALPS
	x_cprintf((EXBPTR)"PS ");
#endif

#ifdef ABALSF
	x_cprintf((EXBPTR)"SF ");

#ifdef ABALSQ
		x_cprintf((EXBPTR)"SQ ");
#endif

#ifdef ABALSI
		x_cprintf((EXBPTR)"SI");
#ifdef ABALLV
		x_cprintf((EXBPTR)"(LV) ");
#else
		x_putch(' ');
#endif
#endif

#ifdef ABALMC
		x_cprintf((EXBPTR)"MC ");
#endif

#ifdef ABALBD
		x_cprintf((EXBPTR)"BD ");
#endif

#ifdef ABALMSG
		x_cprintf((EXBPTR)"MSG ");
#endif
#endif
#ifdef ABALCLP
		x_cprintf((EXBPTR)"PRC ");
#endif
#ifdef ABALME
		x_cprintf((EXBPTR)"ME ");
#endif

#ifdef ABALTRIG
	x_cprintf((EXBPTR)"BL ");
#endif

x_newlyne();
#ifdef MODEL_DBGT
	x_newlyne();
	x_cprintf((EXBPTR)"   ** V E R S I O N  I N T E R N E  ** ");
	x_newlyne();
#endif
if (sicico & ONSEM_CIO) { 
	finterm(0); sicico &= OFSEM_CIO;
#ifdef	DOS
		UnTrap24();
#endif
	}
return(EXIT_VALUE);
}

#ifndef	DEBUGGER	/* Exclusion of EDER if Debugger		*/

/*
 *	E D E R ( e )
 *	-------------
 *
 *	Affichage des erreurs d'execution et d'initialisation
 *
 */

UBINAIR	eder( e , cmd)
UBINAIR	e,cmd;
{

	if ((sicico & ONSEM_CIO ) == 0) { 
#ifdef	DOS
		Trap24();
#endif
		initerm(); sicico |= ONSEM_CIO;
		}

	if ( e != 0 ) {
		/* Ensure Error sent to Screen OutPut */
		/* ---------------------------------- */
		prndest = 1;

		/* Debut d'un message d'erreur */
		/* --------------------------- */
		x_newlyne(); x_cprintf((EXBPTR)"   ");
		x_cprintf((EXBPTR)TalkPtr[2]);
		x_putch(' ');

		/* Erreurs d'Entree Sorties  1 a 19 */
		/* -------------------------------- */
		if ( e < 20 ) 		      {	
			x_cprintf((EXBPTR)TalkPtr[3]);
			x_putch(0x0009);
			}
		/* Erreurs Systeme 20 a 29 */
		/* ----------------------- */
		if (( e > 19 ) && ( e < 30 )) {
			x_cprintf((EXBPTR)TalkPtr[4]);
			x_putch(0x0009);
			}
		/* Erreurs Syntaxe de Commande 30 a 39 */
		/* ----------------------------------- */
		if (( e > 29 ) && ( e < 40 )) { 
			x_cprintf((EXBPTR)TalkPtr[5]);
			x_putch(0x0009);
			}
		/* Erreurs Systeme de Fichiers 40 a 96 */
		/* ----------------------------------- */
		if (( e > 39 ) && ( e < 97 )) { 
			x_cprintf((EXBPTR)TalkPtr[6]);
			x_putch(0x0009);
			}
		/* Erreurs Systemes 97 a 170 */
		/* ------------------------- */
		if (( e > 96 ) && ( e < 170)) { 
			x_cprintf((EXBPTR)TalkPtr[7]);
			x_putch(0x0009);
			}
		/* Erreurs Systeme de fichiers 170 a 190 */
		/* ------------------------------------- */
		if (( e > 169) && ( e < 190)) {
			x_cprintf((EXBPTR)TalkPtr[8]);
			x_putch(0x0009);
			}
		/* Erreurs Systeme Graphiques  190 a 196 */
		/* ------------------------------------- */
		if (( e > 189) && ( e < 197)) {
			x_cprintf((EXBPTR)TalkPtr[9]);
			x_putch(0x0009);
			}
		/* Erreurs Systemes Divers  190 a 196 */
		/* ---------------------------------- */
		if ( e > 196)		      { 
			x_cprintf((EXBPTR)TalkPtr[10]);
			x_putch(0x0009);
			}

		/* Affichage d'identite ABAL plus Adresse d'erreur */
		/* ----------------------------------------------- */
		intvisi(e); x_cprintf((EXBPTR)"  (ABAL)  ");
		if ( sicico & ONSEM_SEG ) { /* If Erreur d'execution du T-code */
			x_cprintf((EXBPTR)TalkPtr[11]); x_putch(' ');
			showword(((lineptr - TcodeSegment) -1),4);
			if ( sicico & ONSEM_PRC ) { /* If Erreur de Procedure		*/
				x_cprintf((EXBPTR)" (proc: "); intvisi(procid);
				x_putch(')');
				}
			x_cprintf((EXBPTR)" (seg: "); intvisi(cur_seg); x_putch(')');
			}
		x_newlyne();
		}
	if ( cmd == 0 ) {
		if ( sicico & ONSEM_CIO ) { 
			finterm(0); sicico &= OFSEM_CIO;
			}
		(void) close(TcodeFileHandle);	/* Close the T-Code File now		*/
#ifdef	DOS
		UnTrap24();
#endif
#ifdef	COEXA
#ifdef	UNIX
		(void) liberlox((EXBPTR) inbuf);
		(void) PurgeLox();
#endif
#endif
		}
	return(e);
}

#endif

#ifndef PROLOGUE
#ifndef DOS
#include "exsignal.c"		/* Signal management for UNIX and friends */
#endif
#endif

#ifdef	ABALTRACE
UBINAIR	membugs;
#endif

#ifdef	DEBUGGER
extern	UBINAIR	IdbFlag;	/* Liste File type Flag		 	*/
#endif

UBINAIR	SemaFlag;		/* File Variables Dmex Condition 	*/
UBINAIR	Anfc_Mode;		/* Mode de Conversion Noms Fichiers	*/


UBINAIR	AutoMate()
{
	UBINAIR	mode;
	EXBPTR	mateptr;

	/* Attempt to Read Environment Variable ABALANFC */
	/* --------------------------------------------- */
	if ((mateptr = (EXBPTR) getenv((EXBPTR)"ABALANFC")) == (EXBPTR) 0 ) {
		return(0);
		}

	/* Position to Start of String */
	/* --------------------------- */
	while (( *mateptr != '=' ) && ( *mateptr != (EXABYTE) 0 )) {
		mateptr++;
		}
	if ( *mateptr == (EXABYTE) 0 ) {
		return(0);
		}
	mode = 0; mateptr++;

	/* Analysis if String */
	/* ------------------ */
	
	while ( *mateptr != (EXABYTE) 0 ) {
		switch ( *mateptr ) {
			case 'u' :
			case 'U' : mode |= 1; break;
			case 'l' :
			case 'L' : mode |= 2; break;
			}

		mateptr++;
		}
	return( mode );		

}

#ifdef	COEXA
extern	int lockqueue;
#endif

/*	M A I N
 *	-------
 *	Entry point from OS, and Return point to OS.
 */
UBINAIR	Phaseur;		/* Tcode Init Phase Error		*/

main(argc,argv)			/* Entry point from PROLOGUE 		*/
BINAIRE argc;			/* Arguament count 			*/
EXABYTE *  argv[];			/* Arguament pointers 			*/
{
	UBINAIR	cmd_recu;	/* Indicates command analysis needed	*/
	UBINAIR	x;		/* General Variable			*/
	UBINAIR	y; 		/* General for next Variable		*/
#ifdef	PROLOGUE
	EXABYTE *	d;		/* Recieves keyboard pointer    	*/
#endif
	EXABYTE 	locarg[ARGLENGTH+1];	/* Local Arguament Storage		*/
	UBINAIR	caldex;		/* Index in ARGV matrix			*/
	UBINAIR	status;		/* Semaphore Arg Status			*/

#ifdef	ABAL14
	EXBPTR	dptr;		/* Pointer to Dedicated Name		*/
#endif

#ifdef	COEXA
	lockqueue = -1;		/* Ensure Message file handle == FALSE	*/
#endif

	TalkWork();		/* Initialise the Message Pointers 	*/

	SemaFlag = 0;		/* Indicate No DMEX Active		*/
	cmd_recu = 1;		/* Indicate Command Concatination TRUE	*/

#ifdef VMS_CHARSET
/* Check for Environment Variable PROLOGUE defined */
/* ----------------------------------------------- */
if ( getenv( "PROLOGUE" ) == (EXBPTR) 0 ) {
	VmsCico = 0;		/* Indicate Vms/Vax default char set	*/
	}			/* ---------------------------------	*/
else	{
	VmsCico = 1;		/* Indicate Amenesik / Sologic Character Set	*/
	}			/* -------------------------------	*/
#endif

prndest  = 1;			/* Initialise CICO Destination		*/
#ifdef	DOS
		Trap24();
#endif
initerm();			/* Initialise Terminal I/O routines	*/
#ifdef	DEBUGGER
if ( DbinitOk == 0 ) {		/* If Initialisation Failure		*/
	finterm(0);		/* Liberate Console			*/
#ifdef	DOS
		UnTrap24();
#endif
	return(EXIT_VALUE);	/* And Exit Gracefully			*/
	}			/* -------------------			*/
#endif
lsyskey();			/* Read default Key values		*/

sicico = ONSEM_CIO; 		/* set semaphore to show init performed	*/
chain    = 0;			/* Reset the chain controller		*/
timersem = 0;			/* Reset the Timer controller		*/
TcodeFileHandle     = 0;			/* T-Code File Handle Reset		*/
bufdex	 = 0;			/* Reset Filename Buffer index		*/

#ifndef PROLOGUE
#ifndef	DOS
	idflg = 0; idbal = 0;	/* Initialise Process control varaibles	*/
	exsignal(0);		/* Initialise Signal management traps	*/
	if (!( getenv("ABALNOCLR") ))
		x_clear();	/* Effacement de l'ecran pre-alable	*/
#endif
#endif

Anfc_Mode = AutoMate();	/* Initialise the Auto File Converteuse		*/

/*	Ramassage des arguaments Eventuelles 	*/
/*	------------------------------------	*/

caldex = 1; status = 0;		/* Establish Arguament Index		*/

#ifdef	DEBUGGER
	IdbFlag = 0;		/* Default liste = -ml ATR output	*/
#ifdef PROLOGUE
	/* Check for DEBUG Systeme Protection Bit Positioned */
	/* ------------------------------------------------- */
	if (( conf(8) & 0x0020 ) == 0 ) {
		(void) eder(58,0); 
#ifdef	DOS
		UnTrap24();
#endif
		finterm(0);
		return(EXIT_VALUE);
		}
#endif
#endif

/* Establish Executeur Environment options */
/* --------------------------------------- */
while ((caldex < argc) && ( *(argv[caldex]) == OPTIONFLAG )) { 

	status++;	/* Increment ARGC adjust value */
#ifdef	ABALTRACE
	membugs = 0;
#endif
	/* Select Option Character */
	/* ----------------------- */
	switch ( ( toupper( *(argv[caldex] + 1) ) ) ) {
#ifdef	MODEL_DBGT
		case 'A'	: IdbFlag |= IDB_ASM; 	/* Assembleur liste */
				  caldex++; continue;
#endif
#ifdef	ABALTRACE
		case 'T'	: membugs = 1; caldex++; continue;
#endif
		default		: (void) eder(EXER_SYNTAX,0); 
#ifdef	DEBUGGER
				  (void) finterm(0);
#ifdef	DOS
		  		  UnTrap24();
#endif
#endif
				  return(EXIT_VALUE);
		}
	} 	

#ifdef	ABAL14

/*	Perform Dedication Tests	*/
/*	------------------------	*/
if (( dptr = (EXBPTR) dedicated()) != (EXBPTR) 0 ) {

	/* Executeur has been dedicated to a particular T-Code */
	/* --------------------------------------------------- */
	memcpy((EXBPTR) inbuf, (EXBPTR) dptr,(bufdex = strlen((EXBPTR) dptr)));

	inbuf[bufdex] = FILETERM;

	}

else	{

#endif

	/*	Test for FILENAME provided	*/
	/*	--------------------------	*/

	if (caldex >= argc) {	/* If no arguaments 	*/

#ifndef PROLOGUE
		(void) banner(); return(EXIT_VALUE);
#else
		bufdex = 0;
		x_putch(',');		/* Amenesik / Sologic 2 & 3 EXECUTEUR PROMPT */

	 	askbuf[0] = FNMAX;	/* Maximum Filename length	   */

	 	d = (EXABYTE *) cgets(askbuf);

	 	if (askbuf[1] > 1) { 

			argc++;

			/* Transfer filename to Filename Zone */
			/* ---------------------------------- */
			while (( *d != ' ' ) && ( *d != 0 ) && ( *d != 0x0009 )) {
				inbuf[bufdex++] = *(d++);
				}

			/* Terminate filename */
			/* ------------------ */
			inbuf[bufdex++] = 0;

			/* Avoid white space */
			/* ----------------- */
			while ((( *d == ' ' ) || ( *d == 0x0009 )) && ( *d != 0)) {
				d++;
				}

			/* Test for and transfer Initial Command String */
			/* -------------------------------------------- */
			if ( *d != 0 ) {
				argc++;				
				argv[2] = d;
				}

			/* Indicate Command Concatination FALSE */
			/* ------------------------------------ */
			cmd_recu = 0;

			}
	 	else 	{ 
			return(banner()); 
			}
		inbuf[--bufdex] = RETCHAR;	/* Terminate string for ANFC 	*/
#endif
		}

	/*	Else if given at command line		*/
	/*	-----------------------------		*/

	else 	{
		while ((bufdex < FNMAX) && ( (inbuf[bufdex++] = *(argv[caldex]++)) != 0));
		inbuf[--bufdex] = RETCHAR;
		}

	/* Filename is now in INBUF[] ready for assign and open */
	/* ----------------------------------------------------	*/

	maxbuf = bufdex;	/* Create buffer length count 	*/
	bufdex = 0;		/* Reset buffer index 		*/

	/* Watch out for DOS/UNIX Path info ../rep/etc/nomfic.t */
	/* ---------------------------------------------------- */
	while (( inbuf[bufdex] == '.' ) || ( inbuf[bufdex] == PATHSEP )) { 
		bufdex++; 
		}

	/* Locate file separator if ANY */
	/* ---------------------------- */
#ifdef PROLOGUE
	while ((inbuf[bufdex] != RETCHAR) && (inbuf[bufdex] != FILESEP) &&( inbuf[bufdex] != ':') && (bufdex <= maxbuf)) {
		bufdex++; 
		}
	if ( inbuf[bufdex] == ':' ) {	/* On a trouvee les cles sans extension */
		for ( x = (bufdex + 4) ; x >= bufdex; x-- ) {
			inbuf[x + 3] = inbuf[x];
			}	
		for ( x = 1; x <= 4; x++ ) {
			if ( inbuf[bufdex + x + 3] == RETCHAR ) { break; }
			}
		}
	else	{	x = 0; 	}
	if ( inbuf[bufdex] != FILESEP ) {
		inbuf[bufdex++] = FILESEP;	/* Establish Filename extension 	*/
		inbuf[bufdex++] = FILEEXT;	/* Set the extension character		*/
		inbuf[bufdex++] = FILEEXT2;	/* Set the extension character		*/
		}
	else 	{ 
		while (inbuf[bufdex] != RETCHAR) { 
			bufdex++; 
			} 
		}
	bufdex += x;

	/* ---------- */
#else	/* ! PROLOGUE */
	/* ---------- */
	x = 0;
	while ((inbuf[bufdex] != RETCHAR)  && (bufdex <= maxbuf)) {

#ifdef	VMS
		if ((inbuf[bufdex] == FILESEP) && ( x == 0 )) 	{ break; }
		if ( inbuf[bufdex] == STARTLOG )  		{ x = 1; }
		if ( inbuf[bufdex] == STOPLOG )  		{ x = 0; }
		bufdex++; 

	/* ----- */
#else	/* ! VMS */
	/* ----- */

	/* If We have found the name/extension separator */
	/* --------------------------------------------- */
		if ( inbuf[bufdex] == FILESEP ) { 

			/* Scan until end of string or PATH separator */
			/* ------------------------------------------ */
			y = 0;
			while ( inbuf[bufdex+y] != RETCHAR ) {

				/* Stop scan if Path separator found */
				/* --------------------------------- */
				if ( inbuf[bufdex+y] == PATHSEP ) {
					break;
					}
				else	{
					y++;
					}
				}
			/* if not a PATHSEP then ok Exit from Initial Scan */
			/* ----------------------------------------------- */
			if ( inbuf[bufdex+y] != PATHSEP ) {
				break; 	
				}
			else	{
				bufdex+=y;
				}
			}
		else	{ 
			bufdex++;
			}
#endif

		}

	if ( inbuf[bufdex] != FILESEP ) {
		inbuf[bufdex++] = FILESEP;	/* Establish Filename extension 	*/
		inbuf[bufdex++] = FILEEXT;	/* Set the extension character		*/
		inbuf[bufdex++] = FILEEXT2;	/* Set the extension character		*/
		}
	else 	{ 
		while (inbuf[bufdex] != RETCHAR) { 
			bufdex++; 
			} 
		}
#endif

	/* Place the correct file terminator wrt OS requirements */
	/* ----------------------------------------------------- */
	inbuf[ bufdex ] = FILETERM;

#ifdef	ABAL14
	}
#endif

/*	Test for file existance		*/
/*	-----------------------		*/

if ( Access((EXBPTR) inbuf,0,0) == 0) { 
#ifdef UNIX
	TcodeFileHandle = open((EXBPTR) inbuf,O_BINARY,0); 
#else
	TcodeFileHandle = open((EXBPTR) inbuf,0);
#endif
	}
else 	{ 
	/* Exit due to Error with T-Code File */
	/* ---------------------------------- */
	if (errno != 44) {
		traitfilerror(-1,errno);
		(void) eder(errno,0); 	
		}
	else	{ 
		(void) eder(44,0);
		}
#ifdef	DEBUGGER
	(void) finterm(0);
#ifdef	DOS
	UnTrap24();
#endif
#endif
	return(EXIT_VALUE);
	}


/*	Check for S.I. C-Isam Init needed	*/
/*	---------------------------------	*/
#ifdef ABALSI
si_init(); sicico |= ONSEM_SI;	/* Init S.I. and set flag */
#endif

/*	VMS & UNIX Require the PROLOGUE SF CODES be initialised 	*/
/*	-------------------------------------------------------		*/
#ifdef UNIX
#ifdef ABALSF
	(void) sf_init();
#endif
#endif

#ifdef VMS
#ifdef ABALSF
	(void) sf_init();
#endif
#endif

/* 	Concatenation des Arguaments de la ligne de commande		*/
/*	----------------------------------------------------		*/
	if ( cmd_recu != 0 ) {

		locarg[0] = (EXABYTE) 0; caldex++;
		while ( caldex < argc ) {

			/* Check for More Space in ARG accumulator */
			/* --------------------------------------- */
			if (( strlen((EXBPTR) locarg) + strlen( (EXBPTR) argv[caldex] )) < ARGLENGTH ) {

				/* Concatenate current with next Arg */
				/* --------------------------------- */
				(void ) strcat(locarg,argv[caldex]);
				caldex++;

				/* If Not the Last Arg then Separate Field */
				/* --------------------------------------- */
				if ( caldex < argc ) { (void) strcat(locarg,ARGFIELD); }
				}
			else	{
				break;
				}
			}

		/* Reposition for ARG Collector */
		/* ---------------------------- */
		argv[2] = locarg; 

		}

/* 	Initialise T-Code and if Correct Transfer control to MOTOR	*/
/* 	----------------------------------------------------------	*/

#ifdef	ABALTRACE
	if ( membugs & 1 ) {
		simcbd = 0x2022;
		(void) si_unlink((EXBPTR)"MMALLOC   ");
		simcbd = 0x2032;
		MMT_nlog = si_create((EXBPTR)"MMALLOC  ",2,8,0,0);
		}	
	else	{ MMT_nlog = 0; }
#endif

if ( tkodgo((argc-status),(EXBPTR) argv[2]) == 1 ) 	{ 

#ifdef DEBUGGER
		err_val = dbmain(); 
#endif

#ifdef	EXTCODELIST
	inbuf[ --bufdex ] = 'k'; sicico |= ONSEM_SEG; err_val = dbmain((EXBPTR) inbuf); 
#endif
#ifdef	EXAMINE
		(void) InitMine();
#endif
#ifdef	EXECUTEUR
		err_val = motor();
#endif
#ifdef	EXAMINE
		(void) SaveMine();
#endif
#ifdef ABALME
	if ( adr_tfu != 0    )	   { (void) allocetd(0);  }
#endif

	}
else	{	/* T-Code StartUp Failure */
		/* ---------------------- */
		if ( Phaseur != 0 ) {
			x_newlyne(); x_cprintf((EXBPTR)"   ");
			x_cprintf((EXBPTR)"T-Code initialisation error Phase # ");
			intvisi(Phaseur);
			x_newlyne();
			}
	}
sicico &= OFSEM_SEG;

/*	Check for S.I. / C-Isam Liberation Needed	*/
/*	-----------------------------------------	*/
#ifdef ABALSI
if ( sicico & ONSEM_SI )	{ si_fin(); sicico &= OFSEM_SI; }
#endif

#ifndef PROLOGUE
#ifndef DOS
	x_newlyne();	/* Ensure new line for UNIX prompt */
	exsignal(99);	/* Liberate Signal trapping	   */
#endif
#endif

(void) close(TcodeFileHandle);	/* Close the T-Code File now		*/

#ifdef	UNIX
#ifdef	COEXA
	(void) liberlox((EXBPTR) inbuf);
	(void) PurgeLox();
#endif
#endif

if ( err_val != 0 ) 	{ 
	(void) eder(err_val,0); 
	}

/*	Check for liberation of Console Manager		*/
/*	---------------------------------------		*/
if ( sicico & ONSEM_CIO ) 	{ finterm(0); sicico &= OFSEM_CIO;}

#ifdef	DOS
	UnTrap24();
#endif

return(EXIT_VALUE);	/* Return to Amenesik / Sologic or OS 		*/
}

/*
 *	A R G I N I T ( vp , sp )
 *	-------------------------
 *	Traitement du ARG du ABAL , passage de la commande initiale
 *	au variable de reception specifie par ARG.
 *
 */

UBINAIR arginit(vp,sp)
UBINAIR	vp;
EXBPTR	sp;
{
	UBINAIR	amaxi;

	err_val = ABAL_TCODFILE; amaxi = ARGLENGTH;

	/* Evaluate ARG Variable */
	/* --------------------- */
	if ( argsetw(5,vp) == 0 ) { return(0); }
	else 	{ 
		/* Transfer from ARG to Variable */
		/* ----------------------------- */
		while (( worklen1 > 0 ) && ( amaxi > 0 )) {
			if ((*sp == IO_NUL ) || ( *sp == IO_RC )) { break; }
			else 	{
				*(workptr1++) = *(sp++);
				worklen1--; amaxi--;
				}
			}

		/* Establish CARRIAGE RETURN */
		/* ------------------------- */
		if ( worklen1 == 0 ) { workptr1--; }
		*(workptr1++) = IO_RC; 
		if ( worklen1 > 0 ) { worklen1--; }

		/* SPACE file to End of String */
		/* --------------------------- */
		while ( worklen1 > 0 ) { *(workptr1++) = IO_ESP; worklen1--; }
		return(1);
		} 
}

/*
 *	A R G D E F O ( vp )
 *	--------------------
 *	Initialisation de la variable de reception du ARG avec Retour
 *	Chariot (/0D) (ARG Defaut )
 *
 */

UBINAIR	argdefo(vp)
UBINAIR	vp;
{
	err_val = ABAL_TCODFILE;

	/* Evaluate ARG Variable */
	/* --------------------- */
	if ( argsetw(5,vp) == 0 ) { return(0); }

	/* Establish CARRIAGE RETURN */
	/* ------------------------- */
	*(workptr1++) = IO_RC; worklen1--;

	/* SPACE file to End of String */
	/* --------------------------- */
	while ( worklen1 > 0 ) { *(workptr1++) = IO_ESP; worklen1--; }
	return(1);
 
}
