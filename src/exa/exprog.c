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

#include "exgesmes.h"		/* Include the GESMES Message Manager		*/

#include "exasyslog.h"


#ifdef	ABALX11
extern	int	exa_is_X11;
#endif

EXAWORD	Phaseur;		/* Tcode Init Phase Error		*/
EXAWORD	SemaFlag;		/* File Variables Dmex Condition 	*/
EXAWORD	Anfc_Mode;		/* Mode de Conversion Noms Fichiers	*/

#ifdef	BEFORE_011295
extern EXAWORD	IdbFlag;	/* Identification of IDB EXADB++	*/
#endif

#ifdef	VMS
extern	noshare int qio_usage_flag;
#endif

#ifdef	UNIX
EX_FILE_HANDLE	CloseTcodeFile(EX_FILE_HANDLE);
void	critical_message();
static	BPTR	startup_filename();
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

BPTR	Exa=(BPTR) 0;

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

EXAWORD	criteria_file_conversion()
{
#ifdef	UNIX
	return( si_conversion() );
#else
	return(0);
#endif
}

#ifdef	ABAL_CRITERIA
VOID	traitfilerror(EXAWORD nlsi, int coder)
{
	/* RAZ des conditions d'erreur */
	/* --------------------------- */
	errno = 0;

	switch (coder) {
	
	case EPERM	:	/* Not super-user */
		errno = 58; break;
#ifdef	EBADSLT
	case EBADSLT	:	/* C-Isam .idx read error in isopen() */
				/* ---------------------------------- */ 
#endif
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
#ifdef	VERSION666
if ( s > 7 ) {
	x = (v & 0xF0000000) >>(12+16);
	if ( x > 9 ) 
		y = (( x-9) | 0x0040);
	else 	y = (x | 0x0030);
	*dest = (EXABYTE) y; dest++;
	}
if ( s > 6 ) {
	x = (v & 0x0F000000) >>(8+16);
	if ( x > 9 ) 
		y = (( x-9) | 0x0040);
	else 	y = (x | 0x0030);
	*dest = (EXABYTE) y; dest++;
	}
if ( s > 5 ) {
	x = (v & 0x00F00000) >>(4+16);
	if ( x > 9 ) 
		y = (( x-9) | 0x0040);
	else 	y = (x | 0x0030);
	*dest = (EXABYTE) y; dest++;
	}
if ( s > 4 ) {
	x = (v & 0x000F0000) >>16;
	if ( x > 9 ) 
		y = (( x-9) | 0x0040);
	else 	y = (x | 0x0030);
	*dest = (EXABYTE) y; dest++;
	}
#endif
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
		case	3	:	return('.');
		case	4	:	return( ' ' );
		case	5	:	return( ' ' );

		default		:	return( ' ' );
		}
}

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
#ifdef	CRIVER42
	x_cprintf((BPTR) " / Criteria 4.2 ");
#else
	x_cprintf((BPTR) " / Criteria ?.? ");
#endif
#endif

/* 	Display of Version Release Information		*/
/* 	-------------------------------------- 		*/
	x_cprintf((BPTR)"   Version ");
	
	x_putch(ABAL_Version);
	x_putch('.'); 
	x_putch(ABAL_Index);
	x_putch('.');
	x_putch(ABAL_Release); 
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
	x_cprintf((BPTR) " -4G+");
#else
	x_cprintf((BPTR) " -16");
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

#ifdef ABALSQL
/*		Data Base Access method			*/
/*		-----------------------			*/
		x_cprintf((BPTR)"SQL ");
#endif

#ifdef ABALXML
/*	XML File Methods	*/
/*	----------------	*/
	x_cprintf((BPTR)"XML ");
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

#ifdef	ABAL_SYSLOG
	x_cprintf((BPTR) "SYSLOG ");
#endif

	x_newlyne();
	x_cprintf((BPTR) "   Process : ");
	intvisi(x_npos());
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
#ifdef	DEBUGGER
	x_cprintf((BPTR)TalkPtr[68]); 
#else
	x_cprintf((BPTR)TalkPtr[14]); 
#endif
	x_putch(' ');
	x_putch('.');
	x_putch('.');
	x_putch('/');
	x_putch('.');
	x_putch('.');
	x_newlyne(); 
	while ( x_getch() != 13 );
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

extern	EXAWORD	FuseCount;

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
	BPTR	sptr;
	BPTR	trace_tcode_filename();
#ifdef	UNIX
	BPTR	eptr;
	EXAWORD	visible=1;
#endif

	if ( e != 0 ) {

#ifdef	LINUX
		exa_application_error(e);
#endif
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

#ifdef	UNIX
		if ( CheckExaSysLog() ) {
			BYTE	message[512];
			BPTR	mptr;

			sprintf((mptr=message),"process: %u , %s: %u , seg: %u",x_npos(),TalkPtr[2],e,cur_seg);
			mptr += strlen(mptr);
			if ( sicico & ONSEM_PRC ) {
#ifdef	VERSION666
				sprintf(mptr," proc: %08.8X",procid);
#else
				sprintf(mptr," proc: %04.4X",procid);
#endif
				}
			mptr += strlen(mptr);
#ifdef	VERSION666
			sprintf(mptr,":%08.8X ",((lineptr - TcodeSegment) -1));
#else
			sprintf(mptr,":%04.4X ",((lineptr - TcodeSegment) -1));
#endif
			critical_message(message);

			return;
			}
		else	{
#endif
			/* Debut d'un message d'erreur */
			/* --------------------------- */
			x_newlyne(); 
			x_cprintf((BPTR)"   ");
			x_cprintf((BPTR)TalkPtr[2]);
			x_putch(' ');

			/* Erreurs d'Entree Sorties  1 a 19 */
			/* -------------------------------- */
			if ( e < 20 ) {	
				x_cprintf((BPTR)TalkPtr[3]);
				x_putch(' ');
				}
			/* Erreurs Systeme 20 a 29 */
			/* ----------------------- */
			if (( e > 19 ) && ( e < 30 )) {
				x_cprintf((BPTR)TalkPtr[4]);
				x_putch(' ');
				}
			/* Erreurs Syntaxe de Commande 30 a 39 */
			/* ----------------------------------- */
			if (( e > 29 ) && ( e < 40 )) { 
				x_cprintf((BPTR)TalkPtr[5]);
				x_putch(' ');
				}
			/* Erreurs Systeme de Fichiers 40 a 96 */
			/* ----------------------------------- */
			if (( e > 39 ) && ( e < 97 )) { 
				x_cprintf((BPTR)TalkPtr[6]);
				x_putch(' ');
				}
			/* Erreurs Systemes 97 a 170 */
			/* ------------------------- */
			if (( e > 96 ) && ( e < 170)) { 
				x_cprintf((BPTR)TalkPtr[7]);
				x_putch(' ');
				}
			/* Erreurs Systeme de fichiers 170 a 190 */
			/* ------------------------------------- */
			if (( e > 169) && ( e < 190)) {
				x_cprintf((BPTR)TalkPtr[8]);
				x_putch(' ');
				}
			/* Erreurs Systeme Graphiques  190 a 196 */
			/* ------------------------------------- */
			if (( e > 189) && ( e < 197)) {
				x_cprintf((BPTR)TalkPtr[9]);
				x_putch(' ');
				}
			/* Erreurs Systemes Divers  190 a 196 */
			/* ---------------------------------- */
			if ( e > 196)		      { 
				x_cprintf((BPTR)TalkPtr[10]);
				x_putch(' ');
				}
	
			/* Affichage d'identite ABAL plus Adresse d'erreur */
			/* ----------------------------------------------- */
			intvisi(e); x_cprintf((BPTR)"  (ABAL)  ");
	
			if (((sptr = trace_tcode_filename()) != (BPTR) 0) 
			||  ((sptr = startup_filename()    ) != (BPTR) 0)) {
				x_newlyne();
				x_cprintf((BPTR)"   ");
				x_cprintf((BPTR)TalkPtr[8]);
				x_cprintf((BPTR) ": ");
				x_cprintf((BPTR) sptr);
				x_cprintf((BPTR) " ");
				}
			if ( sicico & ONSEM_SEG ) { /* If Erreur d'execution du T-code */
				x_cprintf((BPTR)TalkPtr[11]); x_putch(' ');
				showword(((lineptr - TcodeSegment) -1),(2*WORDSIZE));
				if ( sicico & ONSEM_PRC ) { /* If Erreur de Procedure		*/
					x_cprintf((BPTR)" (proc: "); 
#ifdef	VERSION666
					showword( (procid * (8*WORDSIZE)),(2*WORDSIZE));
#else
					intvisi(procid);
#endif
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

#ifdef	UNIX
		}
#endif
	return;
}
#endif /* WIN1632 */

#include "exsignal.c"		/* System specific Signal/Interrupt Traps */



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

EXAWORD	TcodeOverlayName( rptr , sptr )
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
			if ((eptr = (BPTR) getenv((BPTR)"OVLPATH")) != (BPTR) 0)

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
 *	E x i t M a i n ( status, filename )
 *	------------------------------------
 *	Provides a centralised exit routine from main.
 *	Recieves exit status which it returns.
 *	Usage : ExitMain(status,filename);
 *
 *	Performs all necessary ressource liberation
 *	CICO SF etc
 *
 */

static	BPTR	StartUpFileName=(BPTR)0;
static	BPTR	startup_filename()
{
	return( StartUpFileName );
}


VOID	ExitMain( Error , FileName )
EXAWORD	Error;
BPTR	FileName;
{

/*	Check for and Perform Error Display	*/
/*	-----------------------------------	*/
	/* ------------------------ */
	/* to ensure screen message */
	/* ------------------------ */
	if ( exa_is_X11 > 1 ) 
		default_access_controller();
	else	initialise_access_controller();
	if ( Error != 0 ) { 
		StartUpFileName = FileName;		
#ifdef	DEBUGGER
		syseder( Error );
#else
		eder( Error ); 
#endif
		StartUpFileName = (BPTR) 0;
		}

/* 	Liberate Console Manager	*/
/*	------------------------	*/
	iof_liberation();
#ifdef	DEBUGGER
	finterm(0);
#endif
/*	Liberate File Manager		*/
/*	---------------------		*/
//#BG 22/11/11	si_fin();
	MA_fin();

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
#endif


int	close_abal_program()
{
	EXAWORD	exit_error;

	err_val = 0;

#ifdef	ABAL21
	liberate_task_control(1);
#endif	

#ifdef ABALME
	if ( adr_tfu != 0 ) {
		(VOID) liberate_extended_memory();
		}
#endif

/*	Indicate end of Execution Phase		*/
/*	-------------------------------		*/
	sicico &= OFSEM_SEG;

#ifndef PROLOGUE
#ifndef DOS
	initialise_access_controller();
					/* ------------------------------- */
	if (!( would_autopush() ))	/* ensure no autopush/pop active   */
		x_newlyne();		/* Ensure new line for UNIX prompt */
	exsignal(99);			/* Liberate Signal trapping	   */
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
	return(ExaRetCode);
	/* EXIT_VALUE */
}

int	load_abal_program( loadname, options )
BPTR	loadname;
EXAWORD	options;
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
	BPTR	eptr;

#ifdef	ABAL32A
	reset_thread_manager();
	reset_indirection_control();
#endif

#ifdef	VERSION666
	if ((eptr = getenv( "CLOSEZERO" )) != (char *) 0) {
		x = 0;
		while ( *eptr ) {
			if (( *eptr >= '0') && ( *eptr <= '9'))
				x = ((x * 10) + ( *(eptr++) - '0'));
			else	break;
			}
		set_allow_close_zero( x );
		}

	if ((eptr = getenv( "ALLOCPAD" )) != (char *) 0) {
		x = 0;
		while ( *eptr ) {
			if (( *eptr >= '0') && ( *eptr <= '9'))
				x = ((x * 10) + ( *(eptr++) - '0'));
			else	break;
			}
		set_allocate_padding( x );
		}
#endif
#ifdef LINUX
	exsignal(0);		/* Initialise Signal management traps	*/
	preparesignalfailure(status);

	get_default_loadgo_mode();	//INTERNAL_LOADGO_AT

	/* #BG 04/09/20 */
	CheckExaSysLog();
#endif

#ifdef HPUX
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
	FuseCount = 0;		/* Reset dynamic libraries present count*/
	SemaFlag = 0;		/* Indicate No DMEX Active		*/
	cmd_recu = 1;		/* Indicate Command Concatination TRUE	*/
	prndest  = 1;		/* Initialise CICO Destination		*/
	chain    = 0;		/* Reset the chain controller		*/
	loadgo   = 0;		/* Reset the chain controller		*/
	timersem = 0;		/* Reset the Timer controller		*/
	TcodeFileHandle = EX_UNUSED_HANDLE; /* T-Code File Handle Reset	*/
	bufdex	 = 0;		/* Reset Filename Buffer index		*/

#ifdef	ABAL21
	set_time_factor( 10 );
	set_wait_factor( 10 );
#endif

#ifdef	COEXA
	lockqueue = -1;		/* Ensure Message file handle == FALSE	*/
#endif

	SetCicoContext((cicocontext = (BPTR) 0));

/*	Perform Environment Initialisation	*/
/*	----------------------------------	*/
#ifdef ABAL_CRITERIA

	TalkWork();
	if ((exit_error = si_init()) != 0) {

#ifdef	ABALX11
		if (!(exa_is_X11 = open_console())) {
#endif
			exa_is_X11 = 0;
			initerm();
#ifdef	ABALX11
			if (!( getenv("ABALNOCLR") ))
				x_clear();
			}
#endif
		eder( exit_error ); 

#ifdef	ABALX11
		if (!( exa_is_X11 )
		||  ( close_console() != 0 ))
#endif
			finterm(0);

		return(ExaRetCode);
		}

	iof_initialisation();

#else	/* ABAL_CRITERIA */
	EntryMain();
#endif  /* ABAL_CRITERIA */


/*	Establish Curser Key Values for ASK		*/
/*	-----------------------------------		*/
	lsyskey(); 
	sicico = 1; /* ONSEM_CIO; */

#ifndef PROLOGUE
#ifndef	DOS
/*	Perform UNIX and VMS Signal Trapping 	*/
/*	------------------------------------	*/
	idflg = 0; idbal = 0;	/* Initialise Process control varaibles	*/
#ifndef LINUX
#ifndef	HPUX
	ReadEnvSig();		/* Read trapped signals */
	exsignal(0);		/* Initialise Signal management traps	*/
#endif
#endif

#ifdef UNIX
	if ( cicocontext == (BPTR) 0 ) {
#endif
		if (!( getenv("ABALNOCLR") ))
			x_clear();	/* Effacement de l'ecran pre-alable	*/
		}
#ifdef UNIX
	else	x_wipe();
#endif

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

	/* ---------------------------------------------- */
	/* TCODE FILENAME CONSTRUCTIONAL ANALYSIS	  */
	/* --------------------------------------	  */ 
	/* Analyse ARGV[CALDEX] and place result in INBUF */
	/* ---------------------------------------------- */
	(VOID) TcodeFileName( (BPTR) inbuf , (BPTR) loadname );



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
	ExitMain(errno,inbuf);
	return(err_val);

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

/* 	Initialise T-Code and if Correct Transfer control to MOTOR	*/
/* 	----------------------------------------------------------	*/

if ( tkodgo(1,(BPTR) 0) == 1 ) 	{ 
	return(0);
	}
else	{
	close_abal_program();
	return(27);
	}

}

/*	---------------------------------	*/
/*	Pseudo Tcode Generation for Calls 	*/
/*	---------------------------------	*/

static	BYTE	DllCs[512];

EXAWORD	call_abal_program(prcid,registers)
EXAWORD prcid;
EXAWORD	registers;
{
	EXAWORD	tcip=0;
	EXAWORD	optarg=0;
	EXAWORD	args=0;

	DllCs[tcip++] = _tc_ESC;
	DllCs[tcip++] = _tc_CLP;
	for ( args=0; args < registers; args++ ) {
		if (!( args & 1 )) {
			optarg |= 0x16;
			}
		else	{
			optarg |= 1;
			DllCs[tcip++] = optarg;
			optarg=0x060;
			}	
		}
	DllCs[tcip++] = optarg;
	prcid *= (8 * WORDSIZE);
	TcodePmot(&DllCs[tcip],prcid);
	tcip += WORDSIZE;

	for ( args=0; args < registers; args++ ) {
		DllCs[tcip++] = (BYTE) (args+1);
		}

	DllCs[tcip++] = _tc_ESC;
	DllCs[tcip++] = _tc_ESC;
	return( execute_pseudo_code(DllCs) );
}

EXAWORD	ldgo_abal_program(EXAWORD segid)
{
	EXAWORD	tcip=0;
	DllCs[tcip++] = _tc_ESC;
	if ( segid < 256 ) {
		DllCs[tcip++] = _tc_SGI;
		DllCs[tcip++] = (BYTE) segid;
		}
	else	{
		DllCs[tcip++] = _Esc_SGW;
		TcodePmot(&DllCs[tcip],segid);
		tcip += WORDSIZE;
		}
	DllCs[tcip++] = _tc_ESC;
	DllCs[tcip++] = _tc_ESC;
	return( execute_pseudo_code(DllCs) );
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

