/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EX - C  				*/
/*		Version :	1.4a					*/
/*		Date 	:	16/01/1997				*/
/*									*/
/*----------------------------------------------------------------------*/

/* 03/01/97: Pour agf */
#include "pubagf.h"

#include "exmain.h"

/*
 *	X _ N E W L Y N E ( )
 *	---------------------
 *	Saut de ligne a l'ecran pour la baniere et les erreurs
 */
void	x_newlyne()
{
	db_xputch('\r'); db_xputch('\n');
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
	db_xcprintf((EXBPTR)askbuf);
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
	itoa(e,(EXBPTR) askbuf,7); db_xcprintf((EXBPTR) askbuf);
	return;
}

/*
 *	B A N N E R
 *	-----------
 *	Affichage de la bannier de ABAL
 */

UBINAIR	banner()
{

if ((sicico & ONSEM_CIO ) == 0) { db_initerm(); lsyskey(); sicico |= ONSEM_CIO; }
#ifdef EXTCODELIST
x_newlyne(); db_xcprintf("   Dis-assembleur du T-codes ABAL   Version ");
#endif
#ifdef EXECUTEUR
x_newlyne(); db_xcprintf((EXBPTR)"   Executeur ABAL   Version ");
#endif
#ifdef DEBUGGER
x_newlyne(); db_xcprintf((EXBPTR)"   Moniteur  ABAL   Version ");
#endif

/* Affichage du Version.Index(Niveaux) */
/* ----------------------------------- */

db_xputch(ABAL_Version);
db_xputch('.'); 
db_xputch(ABAL_Index);
#ifdef ABAL40
db_xputch('.'); 
db_xputch(ABAL_Release);
#else
db_xputch(ABAL_Release);
db_xcprintf((EXBPTR)ABAL_Prov);
db_xputch(' ');
#endif

#ifdef PROLOGUE
#ifdef PROTEGE_286
	db_xcprintf((EXBPTR)"-P3");
#endif
#endif


/*	Ligne d'identification Site Pilote 	*/
/*	----------------------------------	*/

#ifndef ABAL_DC
x_newlyne();
#endif


/*	Copyright Amenesik / Sologic s.a.		*/
/*	-----------------------		*/

x_newlyne();
db_xcprintf((EXBPTR)"   Copyright (c) 2021 Amenesik / Sologic ");

/*	Options de l'Executeur		*/
/*	----------------------		*/

x_newlyne(); db_xcprintf((EXBPTR)"   Options : ");


#ifdef DEBUGGER
#ifdef MODEL_DBGT
	db_xcprintf((EXBPTR)"**DB++** ");
#else
	db_xcprintf((EXBPTR)"**DB** ");
#endif
#endif
#ifdef	ABALTRACE
	db_xcprintf((EXBPTR)" MemTrace ");
#endif
#ifdef ABALPS
	db_xcprintf((EXBPTR)"PS ");
#endif

#ifdef ABALSF
	db_xcprintf((EXBPTR)"SF ");

#ifdef ABALSQ
		db_xcprintf((EXBPTR)"SQ ");
#endif

#ifdef ABALSI
		db_xcprintf((EXBPTR)"SI");
#ifdef ABALLV
		db_xcprintf((EXBPTR)"(LV) ");
#else
		db_xputch(' ');
#endif
#endif

#ifdef ABALMC
		db_xcprintf((EXBPTR)"MC ");
#endif

#ifdef ABALBD
		db_xcprintf((EXBPTR)"BD ");
#endif

#ifdef ABALMSG
		db_xcprintf((EXBPTR)"MSG ");
#endif
#endif
#ifdef ABALCLP
		db_xcprintf((EXBPTR)"PRC ");
#endif
#ifdef ABALME
		db_xcprintf((EXBPTR)"ME ");
#endif

#ifdef ABALTRIG
	db_xcprintf((EXBPTR)"BL ");
#endif

x_newlyne();
#ifdef MODEL_DBGT
	x_newlyne();
	db_xcprintf((EXBPTR)"   ** V E R S I O N  I N T E R N E  ** ");
	x_newlyne();
#endif
if (sicico & ONSEM_CIO) { db_finterm(); sicico &= OFSEM_CIO;}
return(EXIT_VALUE);
}

/*
 *	E D E R ( e )
 *	-------------
 *
 *	Affichage des erreurs d'execution et d'initialisation
 *
 */
#ifndef MODEL_DBGT
UBINAIR	eder( e , cmd)
UBINAIR	e,cmd;
{
	if ((sicico & ONSEM_CIO ) == 0) { db_initerm(); sicico |= ONSEM_CIO;}
	if ( e != 0 ) {
		x_newlyne(); db_xcprintf((EXBPTR)"   Erreur ");
		if ( e < 20 ) 		      {	db_xcprintf((EXBPTR)"d'E/S\t"); 	}
		if (( e > 19 ) && ( e < 30 )) { db_xcprintf((EXBPTR)"Systeme\t");	}
		if (( e > 29 ) && ( e < 40 )) { db_xcprintf((EXBPTR)"de Commande\t");}
		if (( e > 39 ) && ( e < 97 )) { db_xcprintf((EXBPTR)"Fichier\t");	}
		if (( e > 96 ) && ( e < 170)) { db_xcprintf((EXBPTR)"Systeme\t");	}
		if (( e > 169) && ( e < 190)) { db_xcprintf((EXBPTR)"Fichier\t");	}
		if (( e > 189) && ( e < 197)) { db_xcprintf((EXBPTR)"Graphique\t");}
		if ( e > 196)		      { db_xcprintf((EXBPTR)"Systeme\t");	}
		intvisi(e); db_xcprintf((EXBPTR)"  (ABAL)  ");
		if ( sicico & ONSEM_SEG ) { /* If Erreur d'execution du T-code */
			db_xcprintf((EXBPTR)"a l'adresse "); showword(((lineptr - TcodeSegment) -1),4);
			if ( sicico & ONSEM_PRC ) { /* If Erreur de Procedure		*/
				db_xcprintf((EXBPTR)" (proc: "); intvisi(procid);
				db_xputch(')');
				}
			db_xcprintf((EXBPTR)" (seg: "); intvisi(cur_seg); db_xputch(')');
			}
		x_newlyne();
		}
	if ( cmd == 0 ) {
		if ( sicico & ONSEM_CIO ) { db_finterm(); sicico &= OFSEM_CIO;}
		(void) close(TcodeFileHandle);	/* Close the T-Code File now		*/
		}
	return(e);
}
#endif

#ifndef PROLOGUE
#ifndef DOS
#include "exsignal.c"		/* Signal management for UNIX and friends */
#endif
#endif

#include "exidbdef.h"		/* Idb Flag definitions			  */

#ifndef UNIX
#ifndef DOS
UBINAIR	Maccess(fnom,w)
EXBPTR	fnom;
UBINAIR	w;
{
	UBINAIR tlog;
	if ( (tlog = open( fnom , w )) != MOINS_UN ) {
		(void) close(tlog);
		return(0);
		}
	return(MOINS_UN);
}
#endif
#endif
#ifdef	ABALTRACE
UBINAIR	membugs;
#endif

EXABYTE	LidBuf[16];	/* Liste Extension Buffer */

/*	M A I N
 *	-------
 *	Entry point from OS, and Return point to OS.
 */

extern	UBINAIR	IdbFlag;	/* Liste File type Flag			*/

main(argc,argv)			/* Entry point from PROLOGUE 		*/
BINAIRE argc;			/* Arguament count 			*/
EXABYTE	*argv[];		/* Arguament pointers 			*/
{
	UBINAIR	x;		/* Genaral for next Variable		*/
	EXABYTE *	d;		/* Recieves keyboard pointer    	*/
	BINAIRE t;		/* General Variable			*/
	EXABYTE 	locarg[72];	/* Local Arguament Storage		*/
	UBINAIR	caldex;		/* Index in ARGV matrix			*/
	UBINAIR	status;		/* Semaphore Arg Status			*/
#ifdef VMS_CHARSET
	VmsCico = 0;		/* Indicate Vms/Vax default char set	*/
#endif
db_initerm();			/* Initialise Terminal I/O routines	*/
lsyskey();			/* Read default Key values		*/
sicico = ONSEM_CIO; 		/* set semaphore to show init performed	*/
chain    = 0;			/* Reset the chain controller		*/
timersem = 0;			/* Reset the Timer controller		*/
prndest  = 1;			/* Initialise CICO Destination		*/
TcodeFileHandle = EX_UNUSED_HANDLE; /* T-Code File Handle Reset		*/
bufdex	 = 0;			/* Reset Filename Buffer index		*/

#ifndef PROLOGUE
#ifndef DOS
	idflg = 0; idbal = 0;	/* Initialise Process control varaibles	*/
	exsignal(0);		/* Initialise Signal management traps	*/
	x_clear();		/* Effacement de l'ecran pre-alable	*/
#endif
#endif
/*	Ramassage des arguaments Eventuelles 	*/
/*	------------------------------------	*/

caldex = 1; status = 0;		/* Establish Arguament Index		*/
#ifdef	ABALTRACE
	membugs = 0;		/* Default Malloc/Free tracing OFF	*/
#endif
	IdbFlag = 0;		/* Default liste = -ml ATR output	*/

/* Establish Executeur Environment options */
/* --------------------------------------- */
while ((caldex < argc) && ( *(argv[caldex]) == OPTIONFLAG )) { 

	status++;	/* Increment ARGC adjust value */
	/* Select Option Character */
	/* ----------------------- */
	switch ( ( toupper( *(argv[caldex] + 1) ) ) ) {
#ifdef VMS_CHARSET
		case 'P'	: VmsCico = 1; break;
		case 'V'	: VmsCico = 0; break;
#endif
		case 'D'	: IdbFlag |= IDB_TALK;	/* Dialogue On	    */
				  break;
		case 'A'	: IdbFlag |= IDB_ASM; 	/* Assembleur liste */
				  break;
		case 'L'	: IdbFlag |= IDB_LID;	/* Liste extension  */
				  x = 1;
				  do 	{ LidBuf[x-2] = *(argv[caldex] + (++x)); }
				  while ( *(argv[caldex] + x) != (EXABYTE) 0 );
				  break;
#ifdef	ABALTRACE
		case 'T'	: membugs = 1; break;
#endif
		default		: (void) eder(EXER_SYNTAX,0); return(EXIT_VALUE);
		}
	caldex++;
	} 	

/*	Test for FILENAME provided					*/
/*	--------------------------					*/

if (caldex >= argc) {		/* If no arguaments 			*/

#ifndef PROLOGUE
	(void) banner(); return(EXIT_VALUE);
#else
	bufdex = 0;
	db_xputch(',');		/* Amenesik / Sologic 2 & 3 EXECUTEUR PROMPT	*/
 	askbuf[0] = FNMAX;	
 	d = (EXABYTE *) cgets(askbuf);
 	if (askbuf[1] > 1) { while ((inbuf[bufdex++] = *(d++)) != 0); }
 	else { return(banner()); }
	inbuf[--bufdex] = RETCHAR;	/* Terminate string for ANFC 	*/
#endif
	}

/*	Else if given at command line					*/
/*	-----------------------------					*/

else 	{
	while ((bufdex < FNMAX) && ( (inbuf[bufdex++] = *(argv[caldex]++)) != 0));
	inbuf[--bufdex] = RETCHAR;
	}

/* Filename is now in INBUF[] ready for assign and open 		*/
/* ----------------------------------------------------			*/

maxbuf = bufdex;		/* Create buffer length count 		*/
bufdex = 0;			/* Reset buffer index 			*/

/* Watch out for DOS/UNIX Path info ../rep/etc/nomfic.t */
/* ---------------------------------------------------- */
while (( inbuf[bufdex] == '.' ) || ( inbuf[bufdex] == PATHSEP )) { bufdex++; }

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
else { while (inbuf[bufdex] != RETCHAR) { bufdex++; } }
bufdex += x;
#else
while ((inbuf[bufdex] != RETCHAR) && (inbuf[bufdex] != FILESEP) && (bufdex <= maxbuf)) {
		bufdex++; 
		}
if ( inbuf[bufdex] != FILESEP ) {
	inbuf[bufdex++] = FILESEP;	/* Establish Filename extension 	*/
	inbuf[bufdex++] = FILEEXT;	/* Set the extension character		*/
	inbuf[bufdex++] = FILEEXT2;	/* Set the extension character		*/
	}
else { while (inbuf[bufdex] != RETCHAR) { bufdex++; } }
#endif

/* Place the correct file terminator wrt OS requirements */
/* ----------------------------------------------------- */
inbuf[ bufdex ] = FILETERM;

/*	Test for file existance						*/
/*	-----------------------						*/

if ( access(inbuf,0) == 0) { 
#ifndef PROLOGUE
#ifndef VMS
	TcodeFileHandle = open(inbuf,O_BINARY,0); 
#endif
#endif
#ifndef UNIX
#ifndef DOS
	TcodeFileHandle = open(inbuf,0); 
#endif
#endif
}
else 	{ 
	(void) eder(EXER_FILEWOT,0);
	return(EXIT_VALUE);
	}	/* Return to prologue or OS 	*/


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
	locarg[0] = (EXABYTE) 0; caldex++;
	while ( caldex < argc ) {
		strcat(locarg,argv[caldex]);
		caldex++;
		if ( caldex < argc ) { strcat(locarg,ARGFIELD); }
		}
	argv[2] = locarg; 

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

#ifdef	EXECUTEUR
		err_val = motor();
#endif

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

/*	Check for liberation of Console Manager		*/
/*	---------------------------------------		*/
if ( sicico & ONSEM_CIO ) 	{ db_finterm(); sicico &= OFSEM_CIO;}

(void) close(TcodeFileHandle);	/* Close the T-Code File now		*/
if ( err_val != 0 ) 	{ (void) eder(err_val,0); }
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
	if ( argsetw(5,vp) == 0 ) { return(0); }
	else { while (( worklen1 > 0 ) && ( amaxi > 0 )) {
			if ((*sp == IO_NUL ) || ( *sp == IO_RC )) { break; }
			else {	*(workptr1++) = *(sp++);
				worklen1--; amaxi--;
				}
			}
		if ( worklen1 == 0 ) { workptr1--; }
		*(workptr1++) = IO_RC;
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
	if ( argsetw(5,vp) == 0 ) { return(0); }
	*(workptr1++) = IO_RC; worklen1--;
	while ( worklen1 > 0 ) { *(workptr1++) = IO_ESP; worklen1--; }
	return(1);
 
}

