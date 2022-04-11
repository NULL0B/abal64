/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1999 Amenesik / Sologic  		*/
/*									*/
/*		Module  :	EXMAIN - C  				*/
/*		Date 	:	16/06/1999				*/
/*		Version :	1.4e / 2.1f 				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXMAIN_C
#define	_EXMAIN_C

#define _EXA_TRACE_ALLOC
#include "exmain.h"		/* Header file for EXA EXI EXD		*/
#ifdef	ABAL_TCPIP
#include "extcpip.h"
#endif
#ifdef	DEBUGGER		/* If Model Debugger			*/
#include "exadb.h"		/* Include ExaDb Specific Header	*/
#include "exadbdef.h"		/* Debugger flag Definitions		*/
#include "exproto1.h"
extern	EXAWORD	DbinitOk;	/* Debug Init Control Status		*/
extern	BPTR	ListFilePath;	/* Path For alternative list file	*/
#endif

#ifdef	ABALX11
extern	int	exa_is_X11;
#endif

#define MODULE_COPYRIGHT    "\r\n   Copyright (c) 1987, 2006 Amenesik / Sologic "

/*	Gestion de messages compatible GESMES		*/
/*	-------------------------------------		*/

#include "exgesmes.h"		/* Include the Message Manager		*/

EXAWORD	Phaseur;		/* Tcode Init Phase Error		*/
EXAWORD	SemaFlag;		/* File Variables Dmex Condition 	*/
EXAWORD	Anfc_Mode;		/* Mode de Conversion Noms Fichiers	*/

#ifdef	BEFORE_011295
extern EXAWORD	IdbFlag;	/* Identification of IDB EXADB++	*/
#endif

#ifdef	VMS
extern	noshare int qio_usage_flag;
#endif

#ifdef	COEXA
extern	int lockqueue;		/* Message Communication Channel ACCESS	*/
#endif

EXAWORD   	UseVmsSection;
#ifdef	VMS_OPTIMISED
EXBPTR	MappedSection[2];
EXBPTR	HoldSection[2];
#endif

#ifndef	UNIX
EXAWORD	allocate_extended_memory(EXAWORD);
VOID	liberate_extended_memory();
#else
EXAWORD allocate_extended_memory();	
VOID liberate_extended_memory();	
#endif

#ifndef	PROLOGUE3
	EXAWORD	ExaRetCode;
#else
EXTERN	EXAWORD	ExaRetCode;
#endif

#ifndef	COEXA
#ifndef	PROLOGUE
#ifndef	DOS
EXAWORD	Access(fnom,arg1,arg2)
BPTR	fnom;
EXAWORD	arg1,arg2;
{
#ifdef	ABAL_CRITERIA
	return(EeEad_access(fnom,arg1));
#else
	return(access(fnom,arg1));
#endif
}
#endif
#endif
#endif

#ifdef	ABAL_CRITERIA
VOID	traitfilerror(EXAWORD nlsi, int coder)
{
	/* RAZ des conditions d'erreur */
	/* --------------------------- */
	errno = 0;

	switch (coder) {
	
	case EPERM	:	/* Not super-user */
		errno = 58; break;
	case EBADSLT	:	/* C-Isam .idx read error in isopen() */
				/* ---------------------------------- */ 
	case ENOENT	:	/* No such file or directory */
		errno = 40; break; 
	case ESRCH	:	/* No such process */
		errno = 23; break; 
	case EINTR	:	/* interrupted system call */
		errno = 2; break; 
	case EIO	:	/* I/O error */
		errno = 2; break; 
	case ENXIO	:	/* No such device or address */
		errno = 53; break; 
	case E2BIG	:	/* Arg list too long */
		errno = 30; break; 
	case ENOEXEC	:	/* Exec format error */
		errno = 36; break; 
	case EBADF	:	/* Bad file number */
		errno = 50; break; 
	case ECHILD	:	/* No children	*/
		errno = 20; break; 
	case EAGAIN	:	/* No more processes */
		errno = 24; break; 
	case EACCES	:	/* Permission denied	*/
		errno = 58; break; 
	case EFAULT	:	/* Bad address	*/
		errno = 53; break; 
	case ENOTBLK	:	/* Block device required */
		errno = 60; break; 
	case EBUSY	:	/* Mount device busy */
		errno = 44; break; 
	case EEXIST	:	/* File exists	*/
		errno = 41; break; 
	case ENODEV	:	/* No such device */
		errno = 40; break; 
	case ENOTDIR	:	/* Not a directory */
		errno = 30; break; 
	case EISDIR	:	/* Is a directory */
		errno = 30; break; 
	case EINVAL	:	/* Invalid argument */
		errno = 20; break; 
	case EMFILE	:	/* Too many open files	*/
		errno = 51; break; 
	case ETXTBSY	:	/* Text file busy */
		errno = 44; break; 
	case EFBIG	:	/* File too large */
		errno = 45; break;
	case EDEADLK	:	/* Lockf DeadLock	 */
	case ENOLCK	:	/* No More Systeme Locks */
		errno = 134; break;
	case ENOSPC	:	/* No space left on device */
		errno = 46; break; 
	case ESPIPE	:	/* Illegal seek	*/
		errno = 53; break; 
	case EROFS	:	/* Read only file system */
		errno = 47; break; 
	case EDOM	:	/* Math arg out of domain of func */
		errno = 108; break; 
	case ERANGE	:	/* Math result not representable */
		errno = 108; break; 
	case ENFILE  	:
		errno = 72; break;

	default	     	: 
		if ( coder == 0 ) { errno = 58;    }
		else		 { errno = coder; }
		
	}
	return;
}
#endif

/*
 *	X _ N E W L Y N E ( )
 *	---------------------
 *	Saut de ligne a l'ecran pour la baniere et les erreurs
 */
VOID	x_newlyne()
{
#ifdef RT_AIX
	prndest=1;
#endif
	x_putch('\r'); x_putch('\n');
	return;
}

/* 
 *	I T O X X X X ( v , dest )
 *	--------------------------
 * 	Conversion Integer 16 bits en Chaine Hexadeciamle (%04.1X)
 *
 */
	
VOID	itoxxxx(v,dest,s)
EXAWORD	v;			/*	Integer to convert to HEXA	*/
BPTR	dest;			/*	Destination for storage		*/
EXAWORD	s;
{
	register EXAWORD x,y;
if ( s > 3 ) {
	x = (v & 0xF000) >>12;
	if ( x > 9 ) 
		y = (( x-9) | 0x0040);
	else 	y = (x | 0x0030);
	*dest = (EXABYTE) y; dest++;
	}
if ( s > 2 ) {	
	x = (v & 0x0F00) >>8;	
	if ( x > 9 ) 
		y = ((x-9) | 0x0040);
	else 	y = (x | 0x0030);
	*dest = (EXABYTE) y; dest++;
	}
if ( s > 1 ) {
	x = (v & 0x00F0) >>4;	
	if ( x > 9 ) 
		y = ((x-9) | 0x0040);
	else 	y = (x | 0x0030);
	*dest = (EXABYTE) y; dest++;
	}
if ( s > 0 ) {
	x = (v & 0x000F);
	if ( x > 9 ) 
		y = ((x-9) | 0x0040);
	else 	y = (x | 0x0030);
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

VOID showword( v,s )
EXAWORD	v,s;
{
	itoxxxx(v,(BPTR) askbuf,s);
	askbuf[s] = (EXABYTE) 0;
	x_cprintf((BPTR)askbuf);
	return;
}

VOID	adresse_tracor( tcadr ) 
EXAWORD	tcadr;
{
	x_putch('(');
	showword( tcadr, 4 );
	x_putch(')');
	x_putch(13); x_putch(10);
	x_bflush();
	return;

}

/*
 *	I N T V I S I ( e )
 *	-------------------
 *	Affichage d'une valeur Integer
 */
VOID	intvisi( e )
EXAWORD	e;
{
	itoa(e,(BPTR) askbuf,7); x_cprintf((BPTR) askbuf);
	return;
}

/*
 *	B A N N E R
 *	-----------
 *	Affichage de la bannier de ABAL
 */

WORD	version_component( int item )
{
	switch ( item ) {
		case	0	:	return(ABAL_Version);
		case	1	:	return(ABAL_Index);
		case	2	:	return(ABAL_Release); 
		case	3	:	return(ABAL_ProvOne);
		case	4	:	return(ABAL_ProvTwo);
		case	5	:	return(ABAL_ProvThree);
		default		:	return( ' ' );
		}
}

#ifndef	VERSION66
EXAWORD	visual_screen_capture()
{
	return(0);
}
#endif

VOID banner()
{

#ifndef	WIN32
#ifndef	WIN16

/*	Display Module identification String		*/
/*	------------------------------------		*/
	x_newlyne(); 
	x_cprintf((BPTR)"   "); 
	x_cprintf((BPTR) TalkPtr[1]);

#ifdef	DOS
	switch ((IsAbalExtendedDos())) {
		case 0 :	/* DOS NORMAL */
			break;
		case 1 :
			x_cprintf((BPTR) " / Extended DOS " );
			break;
		case 2 :
			x_cprintf((BPTR) " / Netware " );
			break;
		case 3 :
			x_cprintf((BPTR) " / Windows " );
			break;
		case 4 :
			x_cprintf((BPTR) " / OS/2    " );
			break;
		}
#endif

#ifdef	ABAL_CRITERIA
		x_cprintf((BPTR) " / Criteria ");
#endif

/* 	Display of Version Release Information		*/
/* 	-------------------------------------- 		*/
	x_cprintf((BPTR)"   Version ");
	
	x_putch(ABAL_Version);
	x_putch('.'); 
	x_putch(ABAL_Index);
	x_putch(ABAL_Release); 
	x_putch('.'); 
	x_putch(ABAL_ProvOne);
	x_putch('.'); 
	x_putch(ABAL_ProvTwo);
	x_putch(ABAL_ProvThree);
	x_putch(' ');

/*	Display Possible O.S. Identification		*/
/*	------------------------------------		*/
#ifdef PROLOGUE
#ifdef PROTEGE_286
	x_cprintf((BPTR)"-P3");
#endif
#endif

#ifdef	IBM_PS
	x_cprintf((BPTR)"-PS/2 "); 
#endif

#ifdef DOS
#ifdef DOS_ETENDU
	x_cprintf((BPTR)"-DOS PROTECTED MODE" );
#endif
#endif

#ifdef	ABALX11
	if ( exa_is_X11 )
		x_cprintf((BPTR) "-X11");
#endif

#ifdef	VERSION666
	x_cprintf((BPTR) " -32");
#else
	x_cprintf((BPTR) " -16");
#endif

#ifdef	VERSION_XX
	x_cprintf((BPTR) " -XX");
#endif

/*	Display of Standard COPYRIGHT	*/
/*	----------------------------------	*/
	x_cprintf((BPTR) MODULE_COPYRIGHT   );

/*	Display of Executer Options		*/
/*	---------------------------		*/

	x_newlyne(); x_cprintf((BPTR)"   Options : ");

#ifdef COEXA
/*	File Access manager Required		*/
/*	----------------------------		*/
	x_cprintf((BPTR)"ACC ");
#endif

#ifdef DEBUGGER
/*	Identification of EXADB			*/
/*	-----------------------			*/
	x_cprintf((BPTR)"DB ");
#endif

#ifdef ABALPS
/*	Dynamic libraries and User Functions	*/
/*	------------------------------------	*/
	x_cprintf((BPTR)"PS ");
#endif

#ifdef ABALSF
/*	File System Interface provided		*/
/*	------------------------------		*/
	x_cprintf((BPTR)"SF ");

#ifdef ABALSQ
/*		Sequentiel access method		*/
/*		------------------------		*/
		x_cprintf((BPTR)"SQ ");
#endif

#ifdef ABALSI
/*		I.S.A.M (SI or RMS or C.I.S.A.M.)	*/
/*		---------------------------------	*/
		x_cprintf((BPTR)"SI");

#ifdef ABALLV
/*		SI Variable length data records		*/
/*		-------------------------------		*/
		x_cprintf((BPTR)"(LV) ");
#else
		x_putch(' ');
#endif
#endif

#ifdef ABALMC
/*		Multiple indexed Data S.I.		*/
/*		--------------------------		*/ 
		x_cprintf((BPTR)"MC ");
#endif

#ifdef ABALBD
/*		Data Base Access method			*/
/*		-----------------------			*/
		x_cprintf((BPTR)"BD ");
#endif

#ifdef ABALMSG
/*		IPC Message interface			*/
/*		---------------------			*/
		x_cprintf((BPTR)"MSG ");
#endif
#endif

#ifdef ABALCLP
/*	Procedure Functions Provided		*/
/*	----------------------------		*/
	x_cprintf((BPTR)"PRC ");
#endif

#ifdef ABALME
/*	Extended memory Option Available	*/
/*	--------------------------------	*/
	x_cprintf((BPTR)"ME ");
#endif

#ifdef ABALTRIG
/*	Trigonometric and Logorithmic Library	*/
/*	-------------------------------------	*/
	x_cprintf((BPTR)"BL ");
#endif

#ifdef	ABAL_LAN
	x_cprintf((BPTR) "LAN ");
#endif

#ifdef	ABAL_TCPIP
	x_cprintf((BPTR) "TCP/IP ");
#endif

	x_newlyne();

#ifdef MODEL_DBGT
/*	Internal Extended Debugger		*/
/*	--------------------------		*/
	x_newlyne();
	x_cprintf((BPTR)"   ** V E R S I O N  I N T E R N E  ** ");
	x_newlyne();
#endif

#endif	/* WIN16 */
#endif	/* WIN32 */
	return;
}

#ifdef	ABALX11
static	void	exit_validation()
{
	x_newlyne(); 
	x_putch(' '); x_putch(' '); x_putch(' '); 
	x_cprintf((BPTR)TalkPtr[14]); 
	x_putch(' ');
	x_putch('.');
	x_putch('.');
	x_putch('/');
	x_putch('.');
	x_putch('.');
	x_newlyne(); 
	(void) x_getch();
	return;
}
#endif

/*
 *	E D E R ( e )
 *	-------------
 *
 *	Affichage des erreurs d'execution et d'initialisation
 *
 */

extern	EXAWORD	FuseCtrl;

#ifdef WIN1632
#include "weder.c"
#else

#ifndef	DEBUGGER
VOID eder( e )
#else
VOID syseder( e )
#endif	
EXAWORD	e;
{
	if ( e != 0 ) {

#ifdef	SCREAM
		iscream( "eder",e);
#endif

#ifdef	PROLOGUE
#ifndef	DEBUGGER
		/* Perform PRL_EDER(0) to disactivate any ASG */
		/* ------------------------------------------ */
		HaltAsg();
#endif
#endif

#ifdef	ABAL14
#ifdef	ABALPS
		/* Liberate first any user libraries */
		/* --------------------------------- */
		liberate_dynamic_libraries();
#endif
#endif

		/* Ensure Error sent to Screen OutPut */
		/* ---------------------------------- */
		prndest = 1;

		


		/* Debut d'un message d'erreur */
		/* --------------------------- */
		x_newlyne(); x_cprintf((BPTR)"   ");
		x_cprintf((BPTR)TalkPtr[2]);
		x_putch(' ');

		/* Erreurs d'Entree Sorties  1 a 19 */
		/* -------------------------------- */
		if ( e < 20 ) {	
			x_cprintf((BPTR)TalkPtr[3]);
			x_putch(0x0009);
			}
		/* Erreurs Systeme 20 a 29 */
		/* ----------------------- */
		if (( e > 19 ) && ( e < 30 )) {
			x_cprintf((BPTR)TalkPtr[4]);
			x_putch(0x0009);
			}
		/* Erreurs Syntaxe de Commande 30 a 39 */
		/* ----------------------------------- */
		if (( e > 29 ) && ( e < 40 )) { 
			x_cprintf((BPTR)TalkPtr[5]);
			x_putch(0x0009);
			}
		/* Erreurs Systeme de Fichiers 40 a 96 */
		/* ----------------------------------- */
		if (( e > 39 ) && ( e < 97 )) { 
			x_cprintf((BPTR)TalkPtr[6]);
			x_putch(0x0009);
			}
		/* Erreurs Systemes 97 a 170 */
		/* ------------------------- */
		if (( e > 96 ) && ( e < 170)) { 
			x_cprintf((BPTR)TalkPtr[7]);
			x_putch(0x0009);
			}
		/* Erreurs Systeme de fichiers 170 a 190 */
		/* ------------------------------------- */
		if (( e > 169) && ( e < 190)) {
			x_cprintf((BPTR)TalkPtr[8]);
			x_putch(0x0009);
			}
		/* Erreurs Systeme Graphiques  190 a 196 */
		/* ------------------------------------- */
		if (( e > 189) && ( e < 197)) {
			x_cprintf((BPTR)TalkPtr[9]);
			x_putch(0x0009);
			}
		/* Erreurs Systemes Divers  190 a 196 */
		/* ---------------------------------- */
		if ( e > 196)		      { 
			x_cprintf((BPTR)TalkPtr[10]);
			x_putch(0x0009);
			}

		/* Affichage d'identite ABAL plus Adresse d'erreur */
		/* ----------------------------------------------- */
		intvisi(e); x_cprintf((BPTR)"  (ABAL)  ");

		if ( sicico & ONSEM_SEG ) { /* If Erreur d'execution du T-code */
			x_cprintf((BPTR)TalkPtr[11]); x_putch(' ');
			showword(((lineptr - TcodeSegment) -1),4);
			if ( sicico & ONSEM_PRC ) { /* If Erreur de Procedure		*/
				x_cprintf((BPTR)" (proc: "); intvisi(procid);
				x_putch(')');
				}
			x_cprintf((BPTR)" (seg: "); intvisi(cur_seg); x_putch(')');
			}
		x_newlyne();
		x_bflush();
#ifdef	ABALX11
		if ( exa_is_X11 > 1 ) {	
			exit_validation();
			}
#endif
		}

	return;
}
#endif /* WIN1632 */

#include "exsignal.c"		/* System specific Signal/Interrupt Traps */


/*
 *	A u t o M a t e ( )
 *	-------------------
 *	Initialisation of File Name Conversion routines
 *
 */	

EXAWORD	AutoMate()
{
	EXAWORD	mode;
	BPTR	mateptr;

	/* Attempt to Read Environment Variable ABALANFC */
	/* --------------------------------------------- */
	if ((mateptr = (BPTR) getenv((BPTR)"ABALANFC")) == (BPTR) 0 )
		return(0);

	/* Position to Start of String */
	/* --------------------------- */
	while (( *mateptr != '=' ) && ( *mateptr != (EXABYTE) 0 )) 
		mateptr++;

	if ( *mateptr == (EXABYTE) 0 ) 
		return(0);

	mode = 0; mateptr++;

	/* Analysis of ANFC Conversion Control String */
	/* ------------------------------------------ */
	while ( *mateptr != (EXABYTE) 0 ) {
		switch ( *(mateptr++) ) {
			case 'u' :
			case 'U' : mode |= 1; break;
			case 'l' :
			case 'L' : mode |= 2; break;
#ifdef	ABAL14
			/* f<filename> indicates a file which contains ANFC */
			/* ------------------------------------------------ */
			case 'f' :
			case 'F' : mode |= 4; break;
#endif
			case 'm' :
			case 'M' : mode |= 8; break;
			}
		}

	return( mode );		

}


/*
 *	T c o d e F i l e N a m e ( result , source )
 *	---------------------------------------------
 *	Analysis of Tcode Filename pointed to by the 'source' pointer
 *	addition of extension if needed, and addition of default
 *	tcode path taken from the value of the ABALPATH environnement
 *	variable .
 *
 */

BPTR	ExtensionPointer;
EXAWORD	DedicationFlag;

#ifdef	ABAL21
#ifdef	DEBUGGER
EXABYTE	exadb_file_root[64];
#endif
#endif

EXAWORD	TcodeFileName( rptr , sptr )
BPTR	rptr;
BPTR	sptr;
{
	EXAWORD	maxbuf;
	EXAWORD	status;
	BPTR	eptr;
	EXABYTE	localname[270];

#ifdef	ABAL21
#ifdef	DEBUGGER
	(void) fn_parser( (BPTR) sptr, (BPTR) exadb_file_root, 0x000F );
#endif
#endif

	/* Initialise local Variables */
	/* -------------------------- */
	maxbuf = 0; status = 0x007F;

	/* Test for Network or Device Names */
	/* -------------------------------- */
	if ( fn_parser( sptr , rptr , 0x0003 ) == 0 ) {
	
		/* Neither Device nor Network name */
		/* ------------------------------- */
		status &= 0xFFFC;

		/* Test for PATH information       */
		/* -------------------------	   */
		if ( fn_parser( sptr , rptr , 0x0004 ) == 0 ) {

			/* No Path information so Establish Default */
			/* ---------------------------------------- */
			status &= 0xFFF8;

			/* Read environnement variable ATPATH */
			/* ---------------------------------- */
			if ((eptr = (BPTR) getenv((BPTR)"ATPATH")) != (BPTR) 0)

				/* Copy value into Result Zone */
				/* --------------------------- */
				if ((maxbuf = strlen((BPTR) eptr )) > 0)
					memcpy( rptr , eptr , maxbuf+1 );
			}
		}

	/* Test for Executeur Dedication */
	/* ----------------------------- */
	if ( DedicationFlag != MOINS_UN ) {

		/* Remove The Current Extension */
		/* ---------------------------- */
		(VOID) fn_parser( sptr, (BPTR) localname , (status & 0x000F));
		sptr = (BPTR) localname;
		}

	/* Test for a filename extension provided */
	/* -------------------------------------- */
	if ( fn_parser( sptr , (rptr+maxbuf) , 0x0010 ) == 0 ) {

		/* Copy the Device./path/filename */
		/* ------------------------------ */
		maxbuf += fn_parser( sptr, (rptr+maxbuf) , (status & 0x000F));

		/* Correction for Blank terminated filenames */
		/* ----------------------------------------- */
		if ( maxbuf > 0 )
			while ( *(rptr + maxbuf - 1) == ' ' ) {
				*(rptr + maxbuf - 1) = 0;
				maxbuf--;
				}

		/* Add the default extension */
		/* ------------------------- */
		memcpy((BPTR) (rptr + maxbuf) , (BPTR) ExtensionPointer , 3);
		maxbuf += 3;
		
		/* Add Version number or Password details */
		/* -------------------------------------- */
		maxbuf += fn_parser( sptr , (BPTR) (rptr + maxbuf), (status & 0x0060));
		}
	else	/* Copy the entire filename into the result buffer */
		/* ----------------------------------------------- */
		maxbuf += fn_parser(sptr , (rptr+maxbuf) , (status & 0x00FF));

	/* Place the correct file terminator wrt OS requirements */
	/* ----------------------------------------------------- */
	*(rptr + maxbuf) = FILETERM;

	return(maxbuf);

}

/*
 *	E x i t M a i n ( status )
 *	--------------------------
 *	Provides a centralised exit routine from main.
 *	Recieves exit status which it returns.
 *	Usage : ExitMain(status);
 *
 *	Performs all necessary ressource liberation
 *	CICO SF etc
 *
 */

VOID	ExitMain( Error )
EXAWORD	Error;
{

/*	Check for and Perform Error Display	*/
/*	-----------------------------------	*/
	if ( Error != 0 ) { 
#ifdef	DEBUGGER
		syseder( Error );
#else
		eder( Error ); 
#endif
		}

/* 	Liberate Console Manager	*/
/*	------------------------	*/
	iof_liberation();
#ifdef	DEBUGGER
	finterm(0);
#endif
/*	Liberate File Manager		*/
/*	---------------------		*/
	si_fin(); 

#ifdef	DOS

/*	Release the INT 24 Trap		*/
/*	-----------------------		*/
	UnTrap24();

#endif

#ifdef	COEXA

/*	Release any Reserved Files	*/
/*	--------------------------	*/
	PurgeLox();

#endif

#ifndef	BEFORE_100395
	liberate_for_on_error();
#endif

/*	Return recieved exit Status 	*/
/*	---------------------------	*/
#ifdef	_EXA_TRACE_ALLOC
	close_allocation_trace();
#endif
	return;

}

/*
 *	E n t r y M a i n ( )
 *	---------------------
 *	Provides a centralised Initialisation function
 *	for the executer's own needs (CICO SF etc)
 *
 */
VOID	EntryMain()
{
/*	Initialise message Management	*/
/*	-----------------------------	*/
	TalkWork();

/*	Initialise File Access Manager	*/
/*	------------------------------	*/
	si_init();

/*	Initialise CICO and IOF mechanisms	*/
/*	----------------------------------	*/
	iof_initialisation();

/*	Return to Main		*/
/*	--------------		*/
	return;

}

/*
 *	O p e n T c o d e F i l e ( filename )
 *	--------------------------------------
 *	Opens the tcode file with respect to host system, performing
 *	any ancilliary work required to ensure a coherent context.
 *
 */

EX_FILE_HANDLE	CloseTcodeFile( handle )
EX_FILE_HANDLE	handle;
{
	if ( handle != EX_UNUSED_HANDLE )
		
#ifdef	ABAL_CRITERIA
		(VOID) EeEad_close( handle );
#else
#ifndef	ABAL_TCPIP
		(VOID) close( handle );
#else
		(VOID) ad_close( handle );
#endif
#endif

	return( EX_UNUSED_HANDLE );

}

#ifdef	ABAL21
EXABYTE	SwapNameBuffer[256];

VOID	BuildSwapFileName( nptr )
BPTR	nptr;
{
	EXAWORD	i=0;
	EXAWORD	n=0;
	SwapNameBuffer[0] = 0;

#ifdef WIN32
	return;
#endif

	if ((i = fn_parser((BPTR) nptr, (BPTR) SwapNameBuffer, 0x000F )) == 0 )
		memcpy((BPTR) SwapNameBuffer,(BPTR) "exaswp", strlen((BPTR) "exaswp")+1);
	i = 0;
	while ( SwapNameBuffer[i] != 0 )
		i++;
#ifdef	DOS
#ifdef WIN16
	n = (x_npos() % 1000);
#else
	n = 0;
#endif
#else
#ifdef  UNIX
	n = (x_npos() % 1000);
#else
	n = (npos() % 1000);
#endif
#endif
	SwapNameBuffer[i++] = '.';
	SwapNameBuffer[i++] = ((n / 100) + '0'); n %= 100;
	SwapNameBuffer[i++] = ((n / 10) + '0'); n %= 10;
	SwapNameBuffer[i++] = (n + '0');
	SwapNameBuffer[i++] = 0;
	return;
}

BPTR	SwapFileName()
{
	return( (BPTR) SwapNameBuffer );
}

#endif

#include "exopentc.c"
	
/*
 *	M A I N ( argc , argv[] )
 *	-------------------------
 *
 *	Entry from OS	( activation of ressource managers )
 *
 *	if Initialisation of tcode succesful
 *
 *		Enter Execution Cycle
 *
 *		Perform Tcode Liberation
 *
 *	Return to OS	( after ressource manager liberation )
 *
 */

#ifdef	VMS
EXAWORD	VmsBatchFlag;
#endif

#ifdef	ABAL21
extern	EXAWORD	LastHandle;
BPTR 	Exa=(BPTR) 0;
#endif

#ifdef	WIN1632
majn(argc,argv)			/* Entry point from SYSTEME 		*/
#else
main(argc,argv)			/* Entry point from SYSTEME 		*/
#endif	/* WIN1632 */

BINAIRE argc;			/* Arguament count 			*/
EXABYTE *  argv[];			/* Arguament pointers 			*/
{
#ifdef UNIX
	BPTR	cicocontext=(BPTR) 0;
#endif
	EXAWORD	cmd_recu;	/* Indicates command analysis needed	*/
	EXAWORD	x;		/* General Variable			*/
	EXAWORD	y; 		/* General for next Variable		*/
#ifdef	PROLOGUE
	EXABYTE *	d;		/* Recieves keyboard pointer    	*/
#endif
	EXABYTE 	locarg[ARGLENGTH+1];	/* Local Arguament Storage		*/
	EXAWORD	caldex;		/* Index in ARGV matrix			*/
	BINAIRE	status;		/* Semaphore Arg Status			*/
	EXAWORD	exit_error;
	BPTR	dptr;		/* Pointer to Dedicated Name		*/
	Exa = argv[0];
#ifdef LINUX
	exsignal(0);		/* Initialise Signal management traps	*/
	preparesignalfailure(status);
#endif

#ifdef	_EXA_TRACE_ALLOC
	start_allocation_trace();
#endif

#ifdef	ABAL14
	ExaRetCode = EXIT_VALUE;
	initialise_mallocate();
#endif
	reset_trace_control();
	reset_mima_lang();	/* Ensure Mima Atb(7) and Atb(8) OK	*/

#ifdef	ABAL21
	MaxIpcSem = _MAX_SEMAPHORES;
	reset_task_manager();
	LastHandle = 0;
#endif
#ifdef	VMS
	VmsBatchFlag = 0;
#endif

#ifdef	VMS_OPTIMISED
	EXBPTR	sectionptr;

#ifndef	DEBUGGER
	if ((sectionptr = getenv("ABALSECTION")) != (BPTR) 0) { 
		if ( *sectionptr == '1' )
			UseVmsSection = 1;
		else	UseVmsSection = 2;
		}
	else	UseVmsSection = 0;
#else
	UseVmsSection = 0;
#endif
	MappedSection[0] = (BPTR) 0;
	MappedSection[1] = (BPTR) 0;
#endif


/*	Initialise all necessary variables	*/
/*	----------------------------------	*/
	ExtensionPointer = (BPTR) ".at";
	DedicationFlag	 = MOINS_UN;
	FuseCtrl = 0;		/* Reset dynamic libraries present count*/
	SemaFlag = 0;		/* Indicate No DMEX Active		*/
	cmd_recu = 1;		/* Indicate Command Concatination TRUE	*/
	prndest  = 1;		/* Initialise CICO Destination		*/
	chain    = 0;		/* Reset the chain controller		*/
	timersem = 0;		/* Reset the Timer controller		*/
	TcodeFileHandle = EX_UNUSED_HANDLE; /* T-Code File Handle Reset	*/
	bufdex	 = 0;		/* Reset Filename Buffer index		*/

#ifdef	ABAL21
	set_time_factor( 10 );
#endif

#ifdef	COEXA
	lockqueue = -1;		/* Ensure Message file handle == FALSE	*/
#endif

#ifdef UNIX
	if (( argc > 1 ) 
	&&  ( *( argv[1] ) == '-' )
	&&  (( *( argv[1] + 1 ) == 'X' )
	||   ( *( argv[1] + 1 ) == 'x' )))
#if defined(RT_AIX) || defined(LINUX)
	    {
		SetCicoContext((cicocontext = (BPTR) (argv[1] + 2)));
		x=2;
		while ( ( *(argv[1] +x) != 0x00) && ( *(argv[1] + x) != ' '))
		  x++;
		while ( *(argv[1] + x) == ' ')  x++;
		if ( argv[1] [x] != 0x00) argv[1] += x;
	    }
#else
		SetCicoContext((cicocontext = (BPTR) (argv[1] + 2)));
#endif
	else	
		{	
		SetCicoContext((cicocontext = (BPTR) 0));
		}
#endif

/*	Perform Environment Initialisation	*/
/*	----------------------------------	*/
#ifdef ABAL_CRITERIA
	TalkWork();
	exit_error = si_init();
	if (exit_error != 0) {

#ifdef	DEBUGGER
		initerm();
		syseder( exit_error );
		finterm(0);
#else

#ifdef	ABALX11
		if (!(exa_is_X11 = open_console())) {
#endif
			initerm();
#ifdef	ABALX11
			x_clear();
			}
#endif
		eder( exit_error ); 

#ifdef	ABALX11
	if (!( exa_is_X11 )
	||  ( close_console() != 0 ))
#endif
			finterm(0);
#endif	/* DEBUGGER */
		return(ExaRetCode);
		}
	iof_initialisation();

#else	/* ABAL_CRITERIA */
	EntryMain();
#endif  /* ABAL_CRITERIA */


#ifdef	DEBUGGER
#ifdef	ABAL21
	/* cancel_window_coordinates(); */
#endif

/*	Check for Initialisation failure 	*/
/*	--------------------------------	*/
	if ( DbinitOk == 0 ) {	

/* 		Perform Ressource liberation 	*/
/*		---------------------------- 	*/
		ExitMain(0); 
		return(ExaRetCode);

		}

/*	Establish Default list file type	*/
/*	--------------------------------	*/	
#ifdef	BEFORE_011295
	IdbFlag = 0;
#endif

#ifdef PROLOGUE

/* 	Check for DEBUG Systeme Protection Bit Positioned 	*/
/* 	------------------------------------------------- 	*/
	if (( conf(8) & 0x0020 ) == 0 ) {

/*		DEBUGGER usage if Forbidden by the Systeme 	*/
/*		------------------------------------------	*/	
		ExitMain(58); return(ExaRetCode);
		}

#endif	/* PROLOGUE */
	/* -------- */
#endif	/* DEBUGGER */
	/* -------- */

/*	Establish Curser Key Values for ASK		*/
/*	-----------------------------------		*/
	lsyskey(); sicico = ONSEM_CIO;

#ifndef PROLOGUE
#ifndef	DOS
/*	Perform UNIX and VMS Signal Trapping 	*/
/*	------------------------------------	*/
	idflg = 0; idbal = 0;	/* Initialise Process control varaibles	*/
#ifndef LINUX
	ReadEnvSig();		/* Read trapped signals */
	exsignal(0);		/* Initialise Signal management traps	*/
#endif

#ifdef UNIX
	if ( cicocontext == (BPTR) 0 )
#endif
		x_clear();		/* Effacement de l'ecran pre-alable	*/
	else	x_wipe();		/* Reset all buffers please		*/

#endif	/* ! PRL */
#endif	/* ! DOS */

/*	Initialise Automatic File Conversion 		*/
/*	------------------------------------		*/
	Anfc_Mode = AutoMate();	

#ifdef	BEFORE_011295
#ifdef	DEBUGGER
	ListFilePath = (BPTR) 0;
#endif
#endif

/*	Collect any possible Arguaments 	*/
/*	-------------------------------		*/
	caldex = 1; status = 0;

/* 	Establish Executeur Environment options */
/* 	--------------------------------------- */
	while ((caldex < argc) && (( *(argv[caldex]) == OPTIONFLAG) || ( *(argv[caldex]) == '-' ))) { 

		status++;	/* Increment ARGC adjust value */

		/* Select Option Character */
		/* ----------------------- */
		switch ( ( toupper( *(argv[caldex] + 1) ) ) ) {
#ifdef	BEFORE_011295
#ifdef	DEBUGGER
			case 'L'	: ListFilePath = (BPTR) (argv[caldex] + 2);
					  caldex++;
					  break;
#endif	/* DEBUGER */
#endif  /* BEFORE 011295 */
#ifdef	VMS
			case 'B'	: VmsBatchFlag = 1;
					  caldex++;
					  break;
#endif /* VMS */
#ifdef UNIX
			case 'X'	:
					  caldex++;
					  break;
					
#endif /* UNIX */
			default		: ExitMain(EXER_SYNTAX); 
					  return(EXIT_VALUE);
			}
		} 	

#ifdef	BEFORE_011295
#ifdef	DEBUGGER
	if ( ListFilePath == (BPTR) 0 )
		ListFilePath = (BPTR) getenv((BPTR) "LISTPATH" );
#endif
#endif

#ifdef	ABAL14


/*	Perform Dedication Tests	*/
/*	------------------------	*/
if (( dptr = (BPTR) dedicated()) != (BPTR) 0 ) {

	ExtensionPointer = (BPTR) ".ov";
	DedicationFlag   = 1;
	/* Executeur has been dedicated to a particular T-Code */
	/* --------------------------------------------------- */
	memcpy((BPTR) inbuf, (BPTR) dptr,((bufdex = strlen((BPTR) dptr))+1));
	inbuf[bufdex] = FILETERM;
	if ( argc > 1 )
		status--; 
	}

else	{

#endif

	/*	Test for FILENAME provided	*/
	/*	--------------------------	*/

	if (caldex >= argc) {	/* If no arguaments 	*/

#ifndef PROLOGUE

	/* 	No FileName so BANNER then EXIT 	*/
	/* 	-------------------------------		*/
		banner();

#ifdef	ABALX11
#ifndef	DEBUGGER
		if ( exa_is_X11 > 1 ) {	
			exit_validation();
			}
#endif
#endif

		ExitMain(0);
		return(EXIT_VALUE);

#else
	/* 	Display PROLOGUE command prompt		*/
	/* 	-------------------------------		*/
		x_putch(','); askbuf[(bufdex = 0)] = FNMAX;

	/*	Allow input of Filename and Arg		*/
	/*	-------------------------------		*/
	 	d = (EXABYTE *) cgets(askbuf);

	/*	Analysis and interpretation of Name	*/
	/* 	-----------------------------------	*/
	 	if (askbuf[1] > 0) { 
			argc++;
			argv[caldex] = d;

			/* Transfer filename to Filename Zone */
			/* ---------------------------------- */
			while (( *d != ' ' ) && ( *d != 0 ) && ( *d != 0x0009 )) 
				d++;

			if ( *d != (EXABYTE) 0 ) 
				*(d++) = (EXABYTE) 0;

			/* Avoid white space */
			/* ----------------- */
			while ((( *d == ' ' ) || ( *d == 0x0009 )) && ( *d != 0)) 
				d++;

			/* Test for and transfer Initial Command String */
			/* -------------------------------------------- */
			if ( *d != 0 ) {
				argc++;				
				argv[(caldex+1)] = d;
				}

			}
	 	else 	{ 

		/*	No FileName so BANNER then EXIT		*/
		/*	-------------------------------		*/
			banner();
			ExitMain(0);
			return(EXIT_VALUE);
			}
#endif
		}

	/* ---------------------------------------------- */
	/* TCODE FILENAME CONSTRUCTIONAL ANALYSIS	  */
	/* --------------------------------------	  */ 
	/* Analyse ARGV[CALDEX] and place result in INBUF */
	/* ---------------------------------------------- */
	(VOID) TcodeFileName( (BPTR) inbuf , (BPTR) argv[caldex++] );


#ifdef	ABAL14
	}
#endif


/*	Attempt to open Tcode file 	*/
/*	--------------------------	*/
if ((TcodeFileHandle = OpenTcodeFile((BPTR) inbuf )) == EX_UNUSED_HANDLE) {

	/* Exit due to Error with T-Code File */
	/* ---------------------------------- */
	if (errno != 44) 
		traitfilerror(-1,errno);

	err_val = errno;

	/* Perform Liberation */
	/* ------------------ */
	ExitMain(errno);
	return(EXIT_VALUE);

	}


/*	VMS & UNIX Require the PROLOGUE SF CODES be initialised 	*/
/*	-------------------------------------------------------		*/
#ifndef	PROLOGUE
#ifndef DOS
#ifdef ABALSF
	(VOID) sf_init();
#endif
#endif
#endif

/* 	Concatenation des Arguaments de la ligne de commande		*/
/*	----------------------------------------------------		*/
	if ( cmd_recu != 0 ) {

		locarg[0] = (EXABYTE) 0;
		while ( caldex < argc ) {

			/* Check for More Space in ARG accumulator */
			/* --------------------------------------- */
			if (( strlen((BPTR) locarg) + strlen( (BPTR) argv[caldex] )) < ARGLENGTH ) {

				/* Concatenate current with next Arg */
				/* --------------------------------- */
#ifndef	PROLOGUE
				(VOID ) strcat( locarg, argv[caldex]);
#else
				(VOID ) strcat((BPTR) locarg,(BPTR) argv[caldex]);
#endif
				caldex++;

#ifndef	PROLOGUE
				/* If Not the Last Arg then Separate Field */
				/* --------------------------------------- */
				if ( caldex < argc )
					(VOID) strcat( locarg, ARGFIELD);

#else
				/* If Not the Last Arg then Separate Field */
				/* --------------------------------------- */
				if ( caldex < argc )
					(VOID) strcat((BPTR) locarg,(BPTR) ARGFIELD);
#endif
				}
			else	break;
			}

		/* Reposition for ARG Collector */
		/* ---------------------------- */
		argv[2] = locarg; 
		}

/* 	Initialise T-Code and if Correct Transfer control to MOTOR	*/
/* 	----------------------------------------------------------	*/

if ( tkodgo((argc-status),(BPTR) argv[2]) == 1 ) 	{ 


#ifdef DEBUGGER
		initialise_history();
		err_val = dbmain(); 
		liberate_history();
#endif

#ifdef	EXAMINE
		(VOID) InitMine();
#endif
#ifdef	BUG_ALTHOFF
	init_trace_open_files();
#endif
#ifdef	EXECUTEUR
		
		err_val = motor();
#endif

#ifdef	BUG_ALTHOFF
	flush_trace_open_files();
#endif

#ifdef	EXAMINE
		(VOID) SaveMine();
#endif
#ifdef	ABAL21
		liberate_task_control(1);
#endif	

#ifdef ABALME
		if ( adr_tfu != 0    )
			(VOID) liberate_extended_memory();
#endif
	}
else	{	/* T-Code StartUp Failure */
		/* ---------------------- */
		if ( Phaseur != 0 ) {
			x_newlyne(); x_cprintf((BPTR)"   ");
			x_cprintf((BPTR)"T-Code initialisation error Phase # ");
			intvisi(Phaseur);
			x_newlyne();
			err_val = 27;
			}
	}

/*	Indicate end of Execution Phase		*/
/*	-------------------------------		*/
	sicico &= OFSEM_SEG;

#ifndef PROLOGUE
#ifndef DOS
			/* ------------------------------- */
	x_newlyne();	/* Ensure new line for UNIX prompt */
	exsignal(99);	/* Liberate Signal trapping	   */
			/* ------------------------------- */
#endif
#endif

/*	Close and Release T-Code File	*/
/*	-----------------------------	*/
	exit_error = err_val;

	TcodeFileHandle = CloseTcodeFile( TcodeFileHandle );


/* 	Return to O.S after Ressource Liberation 	*/
/* 	---------------------------------------- 	*/
	ExitMain(exit_error);
	return(EXIT_VALUE);

}

/*
 *	A R G I N I T ( vp , sp )
 *	-------------------------
 *	Traitement du ARG du ABAL , passage de la commande initiale
 *	au variable de reception specifie par ARG.
 *
 */

EXAWORD arginit(vp,sp)
EXAWORD	vp;
BPTR	sp;
{
	EXAWORD	amaxi;

	err_val = ABAL_TCODFILE; amaxi = ARGLENGTH;

	/* Evaluate ARG Variable */
	/* --------------------- */
	if ( argsetw(5,vp) == 0 ) 
		return( 0 );
	else 	{ 

		/* Transfer from ARG to Variable */
		/* ----------------------------- */
		while (( worklen1 > 0 ) && ( amaxi > 0 )) {
			if ((*sp == IO_NUL ) || ( *sp == IO_RC )) 
				break;
			else 	{
				*(workptr1++) = *(sp++);
				worklen1--; amaxi--;
				}
			}

		/* Establish CARRIAGE RETURN */
		/* ------------------------- */
		if ( worklen1 == 0 ) 
			workptr1--;
		*(workptr1++) = IO_RC; 
		if ( worklen1 > 0 ) 
			worklen1--;

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

EXAWORD	argdefo(vp)
EXAWORD	vp;
{
	err_val = ABAL_TCODFILE;

	/* Evaluate ARG Variable */
	/* --------------------- */
	if ( argsetw(5,vp) == 0 ) 
		return(0);

	/* Establish CARRIAGE RETURN */
	/* ------------------------- */
	*(workptr1++) = IO_RC; worklen1--;

	/* SPACE file to End of String */
	/* --------------------------- */
	while ( worklen1 > 0 ) { *(workptr1++) = IO_ESP; worklen1--; }
	return(1);
 
}

#endif	/* _EXMAIN_C */
	/* --------- */

