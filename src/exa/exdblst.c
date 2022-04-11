/*----------------------------------------------------------------------*/
/*									*/
/*		M O N I T E U R         A. B . A . L			*/
/*		-----------------EXADB---------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBLIST - C				*/
/*		Version :	1.4c / 2.1a    				*/
/*		Date 	:	12/08/1992 				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	Fonctions de Gestion du fichier Liste ( - L )			*/
/*	---------------------------------------------			*/
/*	Modified 20/07/1989 : Adapted to new ALD liste identification	*/
/*				Allows list files of Modules to be 	*/
/*				automaticly loaded and used as needed	*/
/*				(Version 1.2a)	(I.J.M.)		*/
/*	Modified 24/11/1990 : Adapted for Version 1.4a option /Lpath	*/
/*				which allows the specification of an	*/
/*				alternative list file search path	*/
/*----------------------------------------------------------------------*/
#define DEBUGGER		/* Ensure definition of Debugger	*/
#define	EXDBLISTC		/* Declare source identification	*/
/*----------------------------------------------------------------------*/

/*	Header file inclusion		*/
/*	---------------------		*/
#include "exdebug.h"		/* General debug header			*/
#include "exdbgrsy.h"		/* Graphique definition Symbols		*/
#include "exfile.h"		/* File Acces definitions		*/
#include "exadbdef.h"		/* Flag definitions			*/
#include "exproto1.h"

#ifndef	ULONG
#define	ULONG	unsigned long
#endif

/*	Local Constant definitions	*/
/*	--------------------------	*/
#define	LISTBUFFER	1024 	/* Size of List file Buffer 		*/
#define	STACKSIZE	256	/* Size of Push Pop Stack		*/
#define	MOTSIZE		64	/* Maximum size of tokens		*/
#define	FILENMAX	64	/* Maximum file name length		*/
#define	LIBELMAX	20	/* Maximum number of SOURCE LABELS 	*/

/*	External Variable References 	*/
/*	----------------------------	*/
EXTERN	EXAWORD	ScreenLin;	/* Number of Screen lines		*/
EXTERN	EXAWORD	ScreenCol;	/* Number of Screen columns		*/
EXTERN	EX_FILE_HANDLE TcodeFileHandle; /* Numero logique Fichier TCODE	*/
EXTERN	BPTR	TalkPtr[];	/* Message Pointers			*/
EXTERN	struct fichdt PTR AssignTable;	/* Assign Table Base Pointer	*/
EXTERN	EXAWORD	ListLigne;	/* Number of Screen lines for List	*/
EXTERN	EXAWORD	simcbd;		/* General File Access code		*/
EXTERN	EXAWORD	TabSize;	/* Tabulation size Count		*/
EXTERN	EXAWORD	adr_tpr;	/* Adresse de la table des procedures 	*/
EXTERN	EXAWORD	procmaxid;	/* Maximum Procedure ID			*/
EXTERN	EXAWORD	SegmentCount;	/* Total Segment Count			*/
EXTERN	EXAWORD	Couleurs[24][2];/* Window Colours			*/
EXTERN	EXAWORD	WindCord[16][2];/* Window Control Block			*/

/*	Function prototypes	*/
/*	-------------------	*/
#ifndef UNIX 
 
EXTERN	VOID	DebFrame(EXAWORD);
EXTERN	VOID	FinFrame(EXAWORD);
EXTERN	EXAWORD	ProcNumb(BPTR);
EXTERN  EXAWORD ProcNamePtr(EXAWORD,BPTR);

EXAWORD	idb_baslist(EXAWORD);
EXAWORD	PushInfo(VOID);
EXAWORD	PopInfo(VOID);
EXAWORD	LibInfo(VOID);
EXAWORD	idb_InitList(VOID);
EXAWORD	ListeSwap(EXAWORD);
VOID	fwdlignes(EXAWORD);
VOID	baklignes(EXAWORD);
VOID	idb_libelist(VOID);

#else
EXTERN	VOID	DebFrame();
EXTERN	VOID	FinFrame();
EXTERN	EXAWORD	ProcNumb();
EXTERN  EXAWORD ProcNamePtr();

EXAWORD	idb_baslist();
EXAWORD	PushInfo();
EXAWORD	PopInfo();
EXAWORD	LibInfo();
EXAWORD	idb_InitList();
EXAWORD	ListeSwap();
VOID	fwdlignes();
VOID	baklignes();
VOID	idb_libelist();

#endif

/*	Find Function Position manager		*/
/*	------------------------------		*/
EXAWORD	Trouve_F;	/* Find Keep Variables : File ID 	*/
ULONG	Trouve_S;	/* Find Keep Variables : Sector id 	*/
EXAWORD	Trouve_B;	/* Find Keep Variables : Byte   id 	*/

/*	Liste label management structure	*/
/*	--------------------------------	*/
struct	idblabel {
	BPTR	Nptr;	/* Label Name 		*/
	ULONG	Sect;	/* Sector		*/
	EXAWORD	Byte;	/* Offset		*/	
	EXAWORD	Flag;	/* Label Status Flag	*/
	EXAWORD	File;	/* Fichier Liste	*/
	};
struct idblabel PTR	GestEtt; /* LABEL MANAGER base pointer	*/
EXAWORD			LibCtrl; /* Current LABEL count		*/

/*	Debug List File position structure	*/
/*	----------------------------------	*/
struct	FileGard {
#ifdef	UNIX
	BPTR	filename;	/* Name of File for liberlox	*/
#endif
	EXAWORD	Fichier;	/* Liste file identifier	*/
	EX_FILE_HANDLE Handle;	/* File Handle 			*/
	BINAIRE	ByteLim;	/* Sector Limit			*/
	BINAIRE	ByteGod;	/* Byte Index			*/
	ULONG	SectGod;	/* Sector index 		*/
	ULONG	SectFin;	/* End Sector Id		*/
	ULONG	SectDeb;	/* Deb Sector Id		*/
	EXAWORD	ByteFin;	/* End Sector offset		*/
	EXAWORD	ByteDeb;	/* Deb Sector offset		*/
	EXAWORD	SpilGod;	/* Underspill (idb_window) God	*/
	} filegard;

/*	General List management Global Variables 	*/
/*	----------------------------------------	*/
EXABYTE	lfbuffer[LISTBUFFER];	/* list file sector Buffer	*/
EXAWORD	IdbFlag;		/* Liste file Type		*/
EXAWORD	underspill;		/* Number of undisplayed lines	*/
EXAWORD	lfSP;			/* List file stack pointer	*/
EXAWORD	lfSegId;		/* Current Segment Pointee	*/
EXAWORD	lfPrcId;		/* Current Procedure		*/
EXAWORD	xcodip;			/* Last debug adress saught	*/
BPTR	lfstack[STACKSIZE];	/* Stack for File positioning	*/
EXAWORD	MapFlag;		/* Status of MAP open		*/
EXAWORD	MapSect;		/* Map Sector in T-Code		*/	
EXAWORD	LstSect;		/* List names Sector in T-Code	*/

/*	Structures d'optimisation QuickFind 	*/
/*     -------------------------------------	*/
struct	QwikFind	{
	EXAWORD	QFL_Pid;		/* Procedure or Segment ID 	*/
	EXAWORD	QFL_FicId;		/* Liste file ID		*/
	ULONG	QFL_Sdeb;		/* Starting sector		*/
	EXAWORD	QFL_Ideb;		/* Starting offset		*/
	ULONG	QFL_Sfin;		/* Final Sector			*/
	EXAWORD	QFL_Ifin;		/* Final Offset			*/
	};
struct	QwikFind PTR idb_QFP;	/* Quick find Proc Table	*/
struct	QwikFind PTR idb_QFS;	/* Quick Find Segm Table	*/
EXAWORD	QwikFlag;			/* Status of Quick Find Init	*/

/* 	***********************************************************	*/
/*	EXDBLIST	FUNCTIONS					*/
/* 	***********************************************************	*/

/*
 *	Affichage de message memory overflow
 *	------------------------------------
 */

VOID	Debordement()
{

	force_mode_verbose();

	Verbose((BPTR)TalkPtr[84]);

	/* "Debordement de memoire" */
	/* ------------------------ */
	return;
}

/*
 *	F I N D H E R E ()
 *	------------------
 *	Sets current list condition for further FIND functions
 *
 */

VOID	FindHere()
{
					/* ---------------------------- */
	Trouve_F = filegard.Fichier;	/* Keep Current Liste ID 	*/
	Trouve_S = filegard.SectGod;	/* Keep Current Block ID 	*/
	Trouve_B = filegard.ByteGod;	/* Keep Current Offset	 	*/
	return;				/* Return to Caller		*/
					/* ---------------------------- */
}


EXAWORD	read_from_list_file( file_offset , block_offset )
ULONG	file_offset;
EXAWORD	block_offset;
{
	EXAWORD	read_length;
	EXAWORD	read_size;
	EXAWORD	indent;

	/* Seek to start of block to read */
	/* ------------------------------ */
	lseek( filegard.Handle , file_offset , SEEK_SET );
	simcbd = 0x2060;

	/* Attempt to read 'LISTBUFFER' octets (currently 1024) */
	/* ---------------------------------------------------- */  
	filegard.ByteLim = read(filegard.Handle,lfbuffer,LISTBUFFER);

	/* Handle read errors */
	/* ------------------ */
	if ((filegard.ByteLim == 0) || (filegard.ByteLim == -1)) {

		filegard.ByteLim = 0;
#ifndef	VMS
#ifndef	UNIX
		read_length = 0;

		/* Reset the buffer contents to Zeros */
		/* ---------------------------------- */
		memset((BPTR) lfbuffer , 0 , LISTBUFFER );

		/* Attempt to read single sectors */
		/* ------------------------------ */
		for (indent = 0; indent < LISTBUFFER; indent += 256 ) {

			/* Seek to sector start */
			/* -------------------- */
			lseek( filegard.Handle , (file_offset+indent) , SEEK_SET );
			simcbd = 0x2060;

			/* Attempt to read the sector */
			/* -------------------------- */
			read_size = read(filegard.Handle,(lfbuffer+indent),256);

			/* If error due to sector read : Perhaps Error 48 */
			/* ---------------------------------------------- */
			if (( read_size == 0 ) || ( read_size == MOINS_UN )) {

				/* Scan till end of Sector for Ctrl Z or 0 */
				/* --------------------------------------- */
				for ( read_size = 0; read_size < 256; read_size++ ) {
					if (( *(lfbuffer + indent + read_size) == 0 ) || ( *(lfbuffer + indent + read_size ) == 0x001A )) {
						break;
						}
					}
				read_length += read_size;
				break;
				}
			/* Adjust total size read */
			/* ---------------------- */
			read_length += read_size;
			}

		/* Establish this buffer limit */
		/* --------------------------- */
		filegard.ByteLim = read_length;
#endif
#endif
		}
	/* Establish current buffer offset if provided */
	/* ------------------------------------------- */
	if ( block_offset != MOINS_UN )
		filegard.ByteGod = block_offset;

	/* Indicate number of bytes read */
	/* ----------------------------- */
	return(filegard.ByteLim);

}

/*
 *	F I N D W H E R E ( )
 *	---------------------
 *	Reposition to Last Find position
 *
 */

VOID	FindWhere()
{
	/* Check for Liste Swap Needed */
	/* --------------------------- */
	if ( Trouve_F != filegard.Fichier ) {

		/* Attempt to Swap list file */
		/* ------------------------- */
		if ( ListeSwap( Trouve_F ) == 0 ) {
			return;
			}
		}

	/* Seek and Read Last Find Block */
	/* ----------------------------- */
	filegard.SectGod = Trouve_S;
	filegard.ByteGod = Trouve_B;
	filegard.ByteLim = read_from_list_file(filegard.SectGod,filegard.ByteGod);
	return;
}

/*
 *	I D B _ M A P R E A D ( )
 *	-------------------------
 *	Loading and analysis of LISTE FILE(s) MAP Strucutre
 *
 */


EXAWORD	idb_MapRead()
{
	EXAWORD	flg,blokid,i,x;
	BPTR	wptr;
	EXAWORD	segent,prcent;

	segent = 0; prcent = 0; 
	wptr   = (BPTR) askbuf;
	flg    = 0; blokid = MapSect;

	do	{
		VerifTcode();
		if (( flg = SectRead( TcodeFileHandle , wptr ,TCODEBLOCK , blokid )) != MOINS_UN) {
			blokid++; i = 0;
			while (( i < TCODEBLOCK) && ( flg != MOINS_UN )) {
				switch ( toupper( (*(wptr + i)) ) ) {
					case 'S' : 
						(*(idb_QFS + segent)).QFL_Pid = Tcodeword( (wptr + i + 1) );
						x = Tcodeword((wptr + i + 3 ));
						(*(idb_QFS + segent)).QFL_Sdeb = 0L;
						while ( x > 0 ) {
							(*(idb_QFS + segent)).QFL_Sdeb += TCODEBLOCK;
							x--;
							}
						(*(idb_QFS + segent)).QFL_Ideb = (EXAWORD) *(wptr + i + 5 );
						x = Tcodeword((wptr + i + 6 ));
						(*(idb_QFS + segent)).QFL_Sfin = 0L;
						while ( x > 0 ) {
							(*(idb_QFS + segent)).QFL_Sfin += TCODEBLOCK;
							x--;
							}
						(*(idb_QFS + segent)).QFL_Ifin = (EXAWORD) *(wptr + i + 8 );
						(*(idb_QFS + segent)).QFL_FicId = (EXAWORD) *(wptr + i + 9 );
						segent++; i += 16; continue;
					case 'P' :
						(*(idb_QFP + prcent)).QFL_Pid = Tcodeword( (wptr + i + 1) );
						x = Tcodeword((wptr + i + 3 ));
						(*(idb_QFP + prcent)).QFL_Sdeb = 0L;
						while ( x > 0 ) {
							(*(idb_QFP + prcent)).QFL_Sdeb += TCODEBLOCK;
							x--;
							}
						(*(idb_QFP + prcent)).QFL_Ideb = (EXAWORD) *(wptr + i + 5 );
						x = Tcodeword((wptr + i + 6 ));
						(*(idb_QFP + prcent)).QFL_Sfin = 0L;
						while ( x > 0 ) {
							(*(idb_QFP + prcent)).QFL_Sfin += TCODEBLOCK;
							x--;
							}
						(*(idb_QFP + prcent)).QFL_Ifin = (EXAWORD) *(wptr + i + 8 );
						(*(idb_QFP + prcent)).QFL_FicId = (EXAWORD) *(wptr + i + 9 );
						prcent++; i += 16; continue;
					default  : flg = MOINS_UN;
					}

				}
			}
		}
	while	( flg != MOINS_UN );
	return(0);
}


/*
 *	I D B _ F L D E B U T ( )
 *	-------------------------
 *	 Seek to top of file 
 */

VOID	idb_fldebut()
{
	/* Seek and Read 1st Block of Current Liste File */
	/* --------------------------------------------- */
	filegard.SectGod = 0L;
	filegard.ByteGod = 0;
	filegard.ByteLim = read_from_list_file(filegard.SectGod,filegard.ByteGod);

	/* UpDate Find Pointer */
	/* ------------------- */
	FindHere();
}


/*
 *	I D B _ C T R L O F F ( )
 *	-------------------------
 *	Switchs off internal LOGICAL BOF EOF condition limits
 *	for CONSULT mode source inspection
 *
 */

VOID	idb_CtrlOff()
{
	filegard.SectFin = 0x7FFFFFFFL;
	filegard.SectDeb = 0L;
	filegard.ByteDeb = 0;
	filegard.ByteFin = (LISTBUFFER + 1);
	underspill = 0;
	return;
}

EXABYTE	NewListName[256];
BPTR	ListFilePath;

BPTR	MakeListFileName( filename )
BPTR	filename;
{
	EXAWORD	i;

	/* Detect alternative list file Path */
	/* --------------------------------- */
	if ( ListFilePath != (BPTR) 0 ) {

/*		x_newlyne();
 *		x_cprintf((BPTR) "Using alternative list file path : ");
 *		x_cprintf((BPTR) ListFilePath );
 */  
		/* Copy List file Path name into buffer */
		/* ------------------------------------ */
		memcpy((BPTR) NewListName, ListFilePath,(i = strlen((BPTR) ListFilePath)) );

		/* Ensure Correctly terminated path string */
		/* --------------------------------------- */
		if ( i > 0 ) {

			if (( NewListName[i-1] != PATHSEP ) && ( NewListName[i-1] != PATHSEP2)) {
				NewListName[i++] = PATHSEP;
				}
			}	

		/* Collect filename / Extension and suppliments */
		/* -------------------------------------------- */
		i += fn_parser((BPTR) filename , (BPTR) & NewListName[i], 0x0078 );

		/* Terminate New file name */
		/* ----------------------- */
		NewListName[i] = (EXABYTE) 0;

		filename = (BPTR) NewListName;

		}

	/* Terminate for The Host Systeme */
	/* ------------------------------ */
	*(filename + strlen((BPTR) filename)) = FILETERM;
	return((BPTR) filename );
}

#ifdef	UNIX
BPTR	allocate_listname( nptr )
BPTR	nptr;
{
	BPTR	lptr;
	EXAWORD	l;

	if ((lptr = (BPTR) allocate((l = strlen((BPTR) nptr )))) != (BPTR) 0)
		memcpy((BPTR) lptr, (BPTR) nptr, l);
	return( lptr );

}
#endif

/*
 *	L I S T E S W A P  ( Liste_Id )
 *	-------------------------------
 *	Attempts to establish the list file indexed by Liste_Id
 *	as the currently active list file for all Source following
 *	Step mode or Consult mode
 *	(NB : Transactional function which ensures that previous
 *	      Liste condition is maintained if an error occurs)
 *
 *	Returns :	0 (SoftError)
 *		:	1 (ok liste established)
 */

EXAWORD	ListeSwap( lid ) 
EXAWORD	lid;
{
	EXABYTE	lfblk[TCODEBLOCK];
	EXABYTE	lfnom[FILENMAX];
	BPTR	xlfnom;
	EXAWORD	mode;
	EXAWORD	lfid;
	EXAWORD	lfsect;
	EXAWORD	si,di;

	/* Check for Valid List Start Sector */
	/* --------------------------------- */
	if ((LstSect == 0) || (LstSect == MOINS_UN)) {
		return(0);
		}
	lfsect = LstSect;

	/* First Save Current Context */
	/* -------------------------- */
	if ( PushInfo() != 0 ) {	return(0);	}

	di = 0;	mode = 0;

	/* Enter File Scan Loop */
	/* -------------------- */
	VerifTcode();
	while ( 1 ) {
		/* Attempt to read a BLOCK from T-Code File */
		/* ---------------------------------------- */
		if ( SectRead(TcodeFileHandle,(BPTR) lfblk, TCODEBLOCK ,lfsect) != TCODEBLOCK ) {
			PopInfo(); return(0);
			}

		lfsect++; 
		si = 0; 

		/* Perform File Name Seek Scan */
		/* --------------------------- */
		do	{

			/* Check for Character Collect */
			/* --------------------------- */
			if ( mode == 0 ) {

				/* Transfer Byte and Test for ZERO */
				/* ------------------------------- */
				if ((lfnom[di]=lfblk[si++] ) == (EXABYTE) 0 ) {

					/* Indicate End of FileName */
					/* ------------------------ */
					mode = 1;
					}
				di++;
				}
			/* File Identifier Collect */
			/* ----------------------- */
			else	{
				lfid = (EXAWORD) lfblk[si++];

				/* Check for File ID match */
				/* ----------------------- */
				if ( lfid == lid ) {


					LibInfo();

					/* Construct the list file name */
					/* ---------------------------- */
					xlfnom = MakeListFileName((BPTR) lfnom );

					/* File ID Match : Open and Init */
					/* ----------------------------- */
					if ( Access( (BPTR) xlfnom , 0 , 0 ) != 0 ) {
						/* Acess Failure */
						/* ------------- */
						return(0);
						}
					/* Close old Liste */
					/* --------------- */
					close(filegard.Handle);
					
					/* Open New Liste */
					/* -------------- */
#ifdef UNIX
					if ( filegard.filename != (BPTR) 0 ) {
						(VOID) liberlox( filegard.filename );
						liberate( filegard.filename );
						filegard.filename = (BPTR) 0;
						}

					filegard.Handle   = open((BPTR) xlfnom , XO_LISTE , 0);
					filegard.filename = allocate_listname((BPTR) xlfnom ); 

#else
					filegard.Handle  = open((BPTR) xlfnom , XO_LISTE );
#endif
					/* Set Current List ID */
					/* ------------------- */
					filegard.Fichier = lid;
					return(1);
					}
				else	{
					/* Not Correct File so Continue */
					/* ---------------------------- */
					di = 0; mode = 0;
					} 
				}
			}
		while ( si < TCODEBLOCK );
		}

}

/*
 *	I D B _ F L O P E N ( )
 *	-----------------------
 *	Opens the list file whose ROOT name is found at ASSIGN=0
 *
 */

EXAWORD	idb_flopen( )
{
	EXABYTE	lfnom[TCODEBLOCK];
	EXAWORD	x,y;
	BPTR	tfnom;
	BPTR	xlfnom;

	GestEtt = (struct idblabel PTR) 0; LibCtrl = 0;

	/* Check for Existance of Valide ListName */
	/* -------------------------------------- */
	if (( LstSect == 0 ) || (LstSect == MOINS_UN)) { 
		return(0); 
		}

	/* Ensure tcode is open */
	/* -------------------- */
	VerifTcode();

	/* Attempt to read list file names table */
	/* ------------------------------------- */
	if (SectRead(TcodeFileHandle,(BPTR) lfnom , TCODEBLOCK , LstSect) != TCODEBLOCK ) {
		return(0);
		}

	/* Ensure correctly terminated */
	/* --------------------------- */
	for ( x = 0 ; x < TCODEBLOCK ; x++ ) {
		if ( lfnom[x] == (EXABYTE) 0 ) { lfnom[x] = FILETERM; break; }
		}

	/* Check for Errors */
	/* ---------------- */
	if ( x == TCODEBLOCK ) {	return(0); 	}
	if ( x == 0	) {	return(0);	}

#ifdef	ABAL14
	/* Construct the list file name */
	/* ---------------------------- */
	xlfnom = MakeListFileName((BPTR) lfnom );
#else
	xlfnom = (BPTR) lfnom;
#endif

	/* Test for list file accessabillity */
	/* --------------------------------- */
	if ( Access((BPTR) xlfnom,0,0) == 0 ) {
#ifdef UNIX
		filegard.Handle = open((BPTR) xlfnom , XO_LISTE , 0);
		filegard.filename = allocate_listname((BPTR) xlfnom );
#else
		filegard.Handle = open((BPTR) xlfnom , XO_LISTE );
#endif
		filegard.Fichier= 0;
		idb_fldebut(); 
		filegard.SectFin = 0x7FFFFFFFL;
		filegard.SectDeb = 0L;
		filegard.ByteDeb = 0;
		filegard.ByteFin = (LISTBUFFER + 1);
		QwikFlag = idb_InitList();
		return(1); 
		}
	x_newlyne();
	db_xcprintf((BPTR) TalkPtr[61]);
	return(0);
}

/*

/*
 *	I D B _ F L C L O S E ( )
 *	-------------------------
 *	Closes the current list file
 *
 */

VOID idb_flclose()
{
	EXAWORD	x;

	/* Close List file */
	/* --------------- */
	close(filegard.Handle);

#ifdef	UNIX
	if ( filegard.filename != (BPTR) 0 ) {
		(VOID) liberlox( filegard.filename );
		liberate( filegard.filename );
		filegard.filename = (BPTR) 0;

		}
#endif

	filegard.Handle = EX_UNUSED_HANDLE;

	/* Liberate Liste Labels */
	/* --------------------- */
	if ( GestEtt != (struct idblabel PTR) 0 ) {
		for ( x = 0; x < LibCtrl; x++ ) {
			if ( (*(GestEtt + x)).Flag != 0 ) {
				liberate( (*(GestEtt + x)).Nptr );
				}
			}
		LibCtrl = 0;	
		liberate( GestEtt );
		GestEtt = (struct idblabel PTR) 0;
		}

	/* Liberate Quick find table pointers */
	/* ---------------------------------- */
	if ( idb_QFP != (struct QwikFind PTR) 0 ) { 
		liberate( idb_QFP ); 
		idb_QFP = (struct QwikFind PTR) 0;
		}
	if ( idb_QFS != (struct QwikFind PTR) 0 ) { 
		liberate( idb_QFS ); 
		idb_QFS = (struct QwikFind PTR) 0;		
		}
	return;
}

/*
 *	I D B _ F G E T C ( )
 *	---------------------
 *	IDB Forward Get Character
 *	Returns next byte from the list file byte stream or MOINS_UN
 *	to signal End of File
 *
 */

EXAWORD	idb_fgetc()
{
	/* Check for Logical End of Code Block */
	/* ----------------------------------- */
	if ((filegard.SectGod + filegard.ByteGod) >= (filegard.SectFin + filegard.ByteFin)) {
		return(0);
		}
	if ( filegard.ByteGod >= filegard.ByteLim ) {
		/* d.ByteGod) >= (filegard.SectFin + filegard.ByteFin)) {
		return(0);
		}
	if ( filegard.ByteGod >= filegard.ByteLim ) {
		/* If Last For>= (filegard.SectFin + filegard.ByteFin)) {
		return(0);
		}
	if ( filegard.ByteGod >= filegard.ByteLim ) {
		/* If Last Forward read failed then End of File condition */
		/* ------------------------------------------------------ */
		if (filegard.ByteLim == 0) {
			return(0);
			}
		else	{
			/* Calculate next seek point */
			/* ------------------------- */
			filegard.SectGod += filegard.ByteLim;
			}

		/* Collect from list file */
		/* ---------------------- */
		if ((filegard.ByteLim = read_from_list_file(filegard.SectGod,0)) == 0)
			return(0);
		}
	if ( lfbuffer[ filegard.ByteGod ] == 0x001A ) { return(0); }
	return( lfbuffer[ filegard.ByteGod++ ] );
}

/*
 *	I D B _ B G E T C ( )
 *	---------------------
 *	IDB Backward Get Character
 *	Returns previous byte from the list file byte stream or MOINS_UN
 *	to signal beggining of File
 *
 */

EXAWORD	idb_bgetc()
{
	/* Check for Logical End of Code Block */
	/* ----------------------------------- */
	if ((filegard.SectGod + filegard.ByteGod) <= (filegard.SectDeb + filegard.ByteDeb)) {
			return(0);
		}

	filegard.ByteGod--;
	if ( filegard.ByteGod < 0 ) {
		if (filegard.SectGod > 0 ) {
			filegard.SectGod -= LISTBUFFER;
			if ((EXALONG) filegard.SectGod <= 0L) {
				filegard.ByteGod = (BINAIRE) (filegard.SectGod + LISTBUFFER - 1);
				filegard.SectGod = 0L;
				}
/*
			if ((filegard.ByteLim = filegard.ByteGod = (BINAIRE) (filegard.SectGod + LISTBUFFER - 1);
				filegard.SectGod = 0L;
				}
 */
			if ((filegard.ByteLim = read_from_list_file(filegard.SectGod,MOINS_UN)) == 0 )
				return(0);
			if (filegard.SectGod != 0L ) {
				filegard.ByteGod = (filegard.ByteLim - 1);
				}
			}
		else	{ errno = 64; return(0); }
		}
	if ( lfbuffer[ filegard.ByteGod ] == 0x001A ) { return(0); }
	return( lfbuffer[ filegard.ByteGod ] );
}

/*
 *	P u s h I n f o ( )
 *	-------------------
 *	Saves current list position onto the stack
 *
 */

EXAWORD	PushInfo()
{
	struct FileGard PTR lfptr;

	/* Attempt to allocate new structure */
	/* --------------------------------- */
	if ( lfSP >= STACKSIZE ) { return(105); }
	if ( (lfptr = (struct FileGard PTR) allocate((USINT) sizeof( struct FileGard ))) == (struct FileGard PTR) 0) {
		return(ABAL_MEMORY);
		}

	/* Copy all current Values to Stacked Structure */
	/* -------------------------------------------- */
	lfptr->Fichier = filegard.Fichier;
	lfptr->Handle  = filegard.Handle;
	lfptr->ByteLim = filegard.ByteLim;
	lfptr->ByteGod = filegard.ByteGod;
	lfptr->SectGod = filegard.SectGod;
	lfptr->SectFin = filegard.SectFin;
	lfptr->ByteFin = filegard.ByteFin;
	lfptr->ByteDeb = filegard.ByteDeb;
	lfptr->SectDeb = filegard.SectDeb;
	lfptr->SpilGod = underspill;

	/* Place Structure Pointer on the Stack */
	/* ------------------------------------ */
	lfstack[lfSP++] = (BPTR) lfptr;
	return(0);
}

/*
 *	P u t  I n f o (i)
 *	------------------
 *	Saves current list position onto the stack  + i
 *
 */

EXAWORD	PutInfo(i)
EXAWORD	i;
{
	struct FileGard PTR lfptr;

	if ( lfSP >= STACKSIZE ) { return(105); }
	lfptr = (struct FileGard PTR) lfstack[lfSP+i];
	lfptr->Fichier = filegard.Fichier;
	lfptr->Handle  = filegard.Handle;
	lfptr->ByteLim = filegard.ByteLim;
	lfptr->ByteGod = filegard.ByteGod;
	lfptr->SectGod = filegard.SectGod;
	lfptr->SectFin = filegard.SectFin;
	lfptr->ByteFin = filegard.ByteFin;
	lfptr->ByteDeb = filegard.ByteDeb;
	lfptr->SectDeb = filegard.SectDeb;
	lfptr->SpilGod = underspill;
	return(0);
}

/*
 *	L i b I n f o ( )
 *	-----------------
 *	Liberates last stacked file position
 *
 */

EXAWORD	LibInfo()
{
	if ( lfSP == 0 ) 
		return(105);
	liberate( (BPTR) lfstack[--lfSP] );
	return(0);
}

/*
 *	P o p I n f o ( )
 *	-----------------
 *	Recovers last stacked list file position infos
 *
 */

EXAWORD	PopInfo()
{
	struct FileGard PTR lfptr;
	if (lfSP == 0 ) { return(105); }
	lfptr = (struct FileGard PTR) lfstack[--lfSP];
	
	/* Check for Liste Swap required */
	/* ----------------------------- */
	if ( lfptr->Fichier != filegard.Fichier ) {

		/* Attempt to swap list file */
		/* ------------------------- */
		if ( ListeSwap( lfptr->Fichier ) == 0 ) {
			return( 200 );
			}
		}

	/* Establish Poped Liste Context */
	/* ----------------------------- */
	filegard.Handle = lfptr->Handle;
	filegard.ByteLim = lfptr->ByteLim;
	filegard.ByteGod = lfptr->ByteGod;
	filegard.SectGod = lfptr->SectGod;
	filegard.ByteFin = lfptr->ByteFin;
	filegard.SectFin = lfptr->SectFin;
	filegard.SectDeb = lfptr->SectDeb;
	filegard.ByteDeb = lfptr->ByteDeb;
	underspill	 = lfptr->SpilGod;

	/* Liberate Stacked Context */
	/* ------------------------ */
	liberate( lfptr );

	/* Seek and Read List file Block */
	/* ----------------------------- */
	filegard.ByteLim = read_from_list_file(filegard.SectGod,filegard.ByteGod);
	return(0);
}

/*
 *	G e t I n f o (i)
 *	-----------------
 *	Recovers list file position infos current +- i
 *
 */

EXAWORD	GetInfo(i)
EXAWORD	i;
{
	struct FileGard PTR lfptr;
	if (lfSP == 0 ) { return(105); }
	lfptr = (struct FileGard PTR) lfstack[lfSP+i];
	filegard.Handle = lfptr->Handle;
	filegard.ByteLim = lfptr->ByteLim;
	filegard.ByteGod = lfptr->ByteGod;
	filegard.SectGod = lfptr->SectGod;
	filegard.ByteFin = lfptr->ByteFin;
	filegard.SectFin = lfptr->SectFin;
	filegard.SectDeb = lfptr->SectDeb;
	filegard.ByteDeb = lfptr->ByteDeb;
	underspill	 = lfptr->SpilGod;
	filegard.ByteLim = read_from_list_file(filegard.SectGod,filegard.ByteGod);
	return(0);
}

/*
 *	W h i t e S a u t ( )
 *	---------------------
 *	Avoids white space characters in a forward direction
 */

EXAWORD	WhiteSaut()
{
	EXAWORD	x,y;
	y = 0;
	do {
		switch ( (x = idb_fgetc()) ) {
			case ';'	: fwdlignes(1);
			case 0x0009	:
			case 0x000A 	:
			case 0x0020  	:
			case 0x000D 	: continue;
			default		: y = 1;
			}
		}
	while ( y == 0 );	
	return( x ); 
}

/*
 *	B l a n c S a u t ( )
 *	---------------------
 *	Avoids white space characters in a backward direction
 */

EXAWORD	BlancSaut()
{
	EXAWORD	x,y;
	y = 0;
	do 	{
		switch ( (x = idb_bgetc()) ) {
			case 0x0009	:
			case 0x000A 	:
			case 0x0020  	:
			case 0x000D 	: continue;
			default		: y = 1;
			}
		}
	while ( y == 0 );
	return( x ); 
}

/*
 *	I D B _ F G E T M O T ( motptr )
 *	--------------------------------
 *	Collects a token from the byte stream and stores it
 *	at the adresse pointed to by MOTPTR
 *	and returns the length
 */


EXAWORD	idb_fgetmot( motptr )
BPTR	motptr;
{
	EXAWORD	x,l;

	/* Avoid White Space */
	/* ----------------- */
	if ( (x = WhiteSaut()) == 0) { *motptr = (EXABYTE) 0; return(0); }
	l = 0;
	do 	{
		switch ( x ) {
			case ';'	: fwdlignes(1);
			case '*'	: /* Liste AK newline symbol */
					  if ( l > 0 ) { x = 0; continue; }
					  break;
			case ' '  	:
			case '\t' 	:
			case 0x000A  	:
			case '\r' 	:
			        if ( l > 0 ) {
					*(motptr++) = (EXABYTE) 0;
					x = 0; continue;
					}
				break;
			case 0x0000	:
			case MOINS_UN 	:
				x = 0; continue;
			default		:
				*(motptr++) = (EXABYTE) (toupper(x)); l++;
			}
		x = idb_fgetc();
		}
	while (( x != 0 ) && (l < MOTSIZE));
	return(l);
}

/*
 *	I D B _ B G E T M O T ( motptr )
 *	--------------------------------
 *	Collects a token from the byte stream and stores it
 *	at the adresse pointed to by MOTPTR
 *	and returns the length
 */

EXAWORD	idb_bgetmot( motptr )
BPTR motptr;
{
	EXABYTE	lmots[MOTSIZE+1];
	EXAWORD	x,y,l;
	if ( (x = BlancSaut()) == 0) { *motptr = (EXABYTE) 0; return(0); }
	y = MOTSIZE;
	lmots[--y] = ((EXABYTE) toupper(x)); l = 1;
	do 	{
		switch ( (x = idb_bgetc()) ) {
			case '*'	: /* Liste AK newline symbol */
			case ' '  	:
			case '\t' 	:
			case 0x000A	:
			case '\r' 	:
				x = 0; continue;
			case 0x0000	:
			case MOINS_UN 	:
				x = 0; continue;
			default		:
				lmots[--y] = (EXABYTE) (toupper(x)); l++;
			}
		}
	while (( x != 0 ) && (l < MOTSIZE));
	while ( y < MOTSIZE ) { *(motptr++) = lmots[y++]; }
	*(motptr++) = (EXABYTE) 0;
	return(l);
}

/*
 *	F W D L I G N E S ( nb )
 *	------------------------
 *	Advances NB lignes
 *
 */

VOID	fwdlignes( nb )
EXAWORD	nb;	
{
	while ( nb > 0 ) {
		switch ( idb_fgetc() ) {
			case 0x000A	: nb--;  	continue;
			case 0x0000	:
			case MOINS_UN	: nb = 0;	continue;
			}
		}
	underspill = 0;
	return;
}

/*
 *	B A K L I G N E S ( nb )
 *	------------------------
 *	Goes back NB lignes
 *
 */

VOID	baklignes( nb )
EXAWORD	nb;
{
	while ( nb > 0 ) {
		switch ( idb_bgetc() ) {
			case 0x000A	: nb--;  continue;
			case 0x0000	:
			case MOINS_UN	: underspill = nb; return;
			}

		}
	underspill = 0;
	return;
}

/*
 *	F L U S H O U T ( )
 *	-------------------
 *	Flushs buffers and restores curser / Screen atributs
 *	for the function PRNLIGNES which follows
 */

VOID	FlushOut()
{
#ifdef	BUF_CICO
	/* Flush Screen buffers if Buffers Active */
	/* -------------------------------------- */
	x_bflush();
#endif
	/* Reset Screen Atributs and Return */
	/* -------------------------------- */
	ColourAtb(0);
	Painter(Couleurs[14][0],Couleurs[14][1]);
	db_xatb(26); return;
}

/*
 *	P R N L I G N E S ( nb )
 *	------------------------
 *	Prints to screen NB lignes and positions the highlight
 *	bar curser on the middle line
 *	The Line output is limited to Screen line length !
 *	Tabulations are converted to TAB SPACE count !
 */

VOID	prnlignes( nb , natb ) 
EXAWORD	nb;
EXAWORD	natb;
{
	EXAWORD	x;
	EXAWORD	cno,kurser;
	EXAWORD	marge,width;
	EXAWORD	spill;
	kurser = ((nb/2) - 1); marge = WindCord[14][1]; cno = 0;
	width = (((ScreenCol - 2) - marge) + 1);
#ifdef	BUF_CICO
	x_bstart();
#endif
	/* Cancel then position Curseur */
	/* ---------------------------- */
	db_xatb(25); db_xpos(((ScreenLin - nb) - 1),marge);
	Painter(Couleurs[14][0],Couleurs[14][1]);

	DebFrame( width );
	db_xpos((ScreenLin - nb),marge); db_xputch(GRSYM_B3);
	spill = underspill;
	while ( spill  > 0 ) {
		while (cno < width ) { db_xputch(' '); cno++; }
		db_xputch(GRSYM_B3);
		nb--; spill--; cno = 0;
		db_xpos((ScreenLin - nb),marge);
		db_xputch(GRSYM_B3);
		if ( opb() ) { FlushOut(); return; }
		}
	while ( nb > 1 ) {
		switch ( (x = idb_fgetc()) ) {
			case 0x000A   :	while ( cno < width ) { db_xputch(' '); cno++; }	
					ColourAtb(0);
					Painter(Couleurs[14][0],Couleurs[14][1]);
					db_xputch(GRSYM_B3);
					nb--; db_xpos((ScreenLin - nb),marge);
					if ( nb > 1      )	{ db_xputch(GRSYM_B3); 	}
					if ( nb == kurser) 	{ ColourAtb(natb); 	}
					cno = 0;
					if ( opb() ) { FlushOut(); return; }
			case 0x001C   :
			case 0x000C   : 
			case 0x000D   :	continue;
			case 0x0000   :
			case MOINS_UN :
					while ( nb > 1 ) {
					 	while ( cno < width ) { db_xputch(' '); cno++; }
					 	ColourAtb(0); 
						Painter(Couleurs[14][0],Couleurs[14][1]);
						db_xputch(GRSYM_B3);
					 	nb--; db_xpos((ScreenLin - nb),marge);
					 	if ( nb > 1      )	{ db_xputch(GRSYM_B3); 	}
					 	if ( nb == kurser) 	{ ColourAtb(natb); 	}
					 	cno = 0;
						if ( opb() ) { FlushOut(); return; }
					 	}
					nb = 0; continue;
			case '\t'     : if ( cno < width ) {
						do 	{
							db_xputch(' ');
							cno++;
							}
						while (( cno < width ) && (( cno % TabSize ) != 0));
						}
					continue;
			default	      : if ( x < 0x0020 ) { continue; }
					if (cno < width ) { db_xputch( x ); cno++; }
			}
		}
	FinFrame(width);
	FlushOut(); return;

}

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
EXAWORD	idb_wildseek( seekptr )
BPTR	seekptr;
{

	EXABYTE	lmots[MOTSIZE+1];
	EXAWORD	Ctrl,ldex;
	EXAWORD	Goch,Gech;
	
	/* Ensure Not an empty search String */
	/* --------------------------------- */
	if (strlen(seekptr) == 0) { return(0); }
	Ctrl = 0;
	/* Collect First Byte for Index Seeking */
	/* ------------------------------------ */
	do { Goch = (EXAWORD) *(seekptr + Ctrl); Ctrl++; }
	while ( (Goch != 0) && ( Goch == '*' ) && ( Goch != '?'));

	/* Ensure Something to Find */
	/* ------------------------ */
	if ( Goch == 0 ) { return(0); }
	Ctrl = 2;

	/* Initialise Find Offset */
	/* ---------------------- */
	FindWhere();
	do	{
		/* Perform Index Searching */
		/* ----------------------- */
		if ( Ctrl == 0 ) { return(0); }
		do	{ Gech = toupper( (EXAWORD) idb_fgetc() ); }
		while ( (Gech != 0 ) && (Goch != '?') && ( Gech != Goch ) );
		if ( Gech == 0 ) { return(0); }

		/* Collect a Word */
		/* -------------- */
		lmots[0] = Gech; ldex = 1; Ctrl = 1;
		do {	switch ( (Gech = toupper( (EXAWORD) idb_fgetc() )) ) {
				case 0x000D	: continue;
				case 0x0000	: Ctrl = 0; continue;
				case ' '	:
				case 0x0009	:
				case 0x000A	: Ctrl = 2; continue;
				default		: if ( Gech > ' ' ) {
							lmots[ldex++] = (EXABYTE) Gech;
							continue;
							}
						  Ctrl = 2; 
				}

		   }
		while (( Ctrl == 1 ) && ( ldex < MOTSIZE ));
		lmots[ldex++] = (EXABYTE) 0;
		}
		/* Check for Wild String Match */
		/* --------------------------- */
	while	( CompWild((BPTR) lmots , seekptr) != 0 );
	FindHere();
	return(1);

}

/*
 *	I D B _ F S T R S E E K ( strptr )
 *	----------------------------------
 *	Searches for the string strptr in a forward direction
 *
 */

EXAWORD	idb_fstrseek(strptr)
BPTR	strptr;
{
	EXAWORD	l,i,lt;
	EXABYTE	lmots[MOTSIZE+1];

if ((lt = strlen(strptr)) == 0) { return(0); }

do	{
	if ( (l = idb_fgetmot( (BPTR) lmots )) == 0) { return(0); }
	if ( l != lt ) { continue; }
	i = 0;
	while (( l > 0 ) && ( lmots[i] == *(strptr + i) )) { l--; i++; } 
	}
while	( l != 0 );
return(1);
}

/*
 *	I D B _ B S T R S E E K ( strptr )
 *	----------------------------------
 *	Searches for the string strptr in a backward direction
 *
 */

EXAWORD	idb_bstrseek(strptr)
BPTR	strptr;
{
	EXAWORD	l,i,lt;
	EXABYTE	lmots[MOTSIZE+1];

if ((lt = strlen(strptr)) == 0) { return(0); }

do	{
	if ( (l = idb_bgetmot( (BPTR) lmots )) == 0) { return(0); }
	if ( l != lt ) { continue; }
	i = 0;
	while (( l > 0 ) && ( lmots[i] == *(strptr + i) )) { l--; i++; } 
	}
while	( l != 0 );
return(1);
}

EXAWORD	idb_seekprc( prcname )
EXAWORD	prcname;
{
	EXABYTE	pname[9];		/* Procedure Name 	*/
	EXABYTE	lmots[MOTSIZE+1];	/* Local Test Zone	*/
	EXAWORD	i,l;			/* General Variables	*/

/* If Qwick find infos are present */
/* ------------------------------- */
if ( QwikFlag == 0 ) {

	/* Scan Table for Procedure ID */
	/* --------------------------- */
	for ( i = 0; i < procmaxid; i++ ) {

		/* Check for Procedure ID matching */
		/* ------------------------------- */
		if ( (*(idb_QFP + i)).QFL_Pid == prcname ) {

			/* Check for List Swap Needed */
			/* -------------------------- */
			if ( (*(idb_QFP + i)).QFL_FicId != filegard.Fichier ) {

				/* Attempt to Swap list file */
				/* ------------------------- */
				if ( ListeSwap( (*(idb_QFP + i)).QFL_FicId ) == 0 ) {
					return(0);
					}

				}

			/* Establish List Control Zone */
			/* --------------------------- */
			filegard.SectGod = (*(idb_QFP + i)).QFL_Sdeb;
			filegard.ByteGod = (*(idb_QFP + i)).QFL_Ideb;
			filegard.SectFin = (*(idb_QFP + i)).QFL_Sfin;
			filegard.ByteFin = (*(idb_QFP + i)).QFL_Ifin;
			filegard.ByteDeb = filegard.ByteGod;
			filegard.SectDeb = filegard.SectGod;

			/* Seek and Read the Starting Block of Liste */
			/* ----------------------------------------- */
			filegard.ByteLim = read_from_list_file(filegard.SectGod,filegard.ByteGod);
			return(1);
			}
		}
	return(0);
	}
if ( ProcNamePtr( prcname , (BPTR) pname ) == MOINS_UN)  { return(0); }
if ( PushInfo() != 0 ) { return(0); }
(VOID) idb_fldebut();

do	{
	if ( idb_fstrseek( (BPTR) "PROC" ) == 0 ) { (VOID) PopInfo(); return(0); }
	if ( (l = idb_fgetmot( (BPTR) lmots)) == 0 )	   { (VOID) PopInfo(); return(0); }
	lmots[l] = (EXABYTE) 0;
	for ( i = 0; i < l ; i++ ) {
		if ( lmots[i] == '(' ) {
			lmots[i] = (EXABYTE) 0;
			l = i;
			break;
			}
		}
	for ( i = 0; i < 8, l > 0 ; i++ , l-- ) {
		if ( pname[i] != lmots[i] ) { break; }
		}
	}
while ( l > 0 );
lfPrcId = prcname; xcodip = 0; lfSegId = EXDB_FFFF;
baklignes(1); LibInfo();
return(1);
}


EXAWORD	idb_seekseg( segid )
EXAWORD	segid;
{
	EXABYTE	lmots[MOTSIZE];
	EXAWORD	i,l;

/* If Qwick Find Infos are present */
/* ------------------------------- */
if ( QwikFlag == 0 ) {

	/* Scan Table for matching Segment ID */
	/* ---------------------------------- */
	for ( i = 0; i < SegmentCount; i++ ) {

		/* Check for Segment ID Matching */
		/* ----------------------------- */
		if ( (*(idb_QFS + i)).QFL_Pid == segid ) {
	
			/* Check for List Swap Needed */
			/* -------------------------- */
			if ( (*(idb_QFS + i)).QFL_FicId != filegard.Fichier ) {

				/* Attempt to Swap list file */
				/* ------------------------- */
				if ( ListeSwap( (*(idb_QFS + i)).QFL_FicId ) == 0 ) {
					return(0);
					}
				}

			/* Establish List Control Zone */
			/* --------------------------- */
			filegard.SectGod = (*(idb_QFS + i)).QFL_Sdeb;
			filegard.ByteGod = (*(idb_QFS + i)).QFL_Ideb;
			filegard.ByteDeb = filegard.ByteGod;
			filegard.SectDeb = filegard.SectGod;
			filegard.SectFin = (*(idb_QFS + i)).QFL_Sfin;
			filegard.ByteFin = (*(idb_QFS + i)).QFL_Ifin;

			/* Seek and Read the Starting Block of Liste */
			/* ----------------------------------------- */
			filegard.ByteLim = read_from_list_file(filegard.SectGod,filegard.ByteGod);
			return(1);
			}
		}
	return(0);
	}
if ( PushInfo() != 0 ) { return(0); }
(VOID) idb_fldebut();

do	{
	if ( idb_fstrseek( (BPTR) "SEGMENT" ) == 0 ) { (VOID) PopInfo(); return(0); }
	if ( (l = idb_fgetmot( (BPTR) lmots)) == 0 ) { (VOID) PopInfo(); return(0); }
	lmots[l] = ' ';
	}
while ( ((EXAWORD) atoi((BPTR) lmots , l )) != segid);
lfSegId = segid; xcodip = 0; lfPrcId = EXDB_FFFF;
baklignes(1); LibInfo();
return(1);
}

/*
 *	I D B _ L I S T G O G O ( )
 *	---------------------------
 *	Attempts to intialise list file management and position to
 *	Segment Zero
 *	
 */

EXAWORD	idb_listgogo()
{
	EXAWORD	goodres;

if ( IdbFlag & IDB_TALK ) { 	goodres = 0x0009; 	}
else			  {	goodres = 0x0001;	}

if ( idb_flopen() != 0 )  { 
	/* Seek Segment Zero if Possible */
	/* ----------------------------- */
	if ( idb_seekseg( 0 ) == 0 )  { 
		/* List Active but Zone Not Found ! */
		/* -------------------------------- */
		return(goodres); 
		}
	else	{
		/* List Active and Segment Found */
		/* ----------------------------- */
		lfSegId = 0; xcodip = 0; lfPrcId = EXDB_FFFF;
		return((goodres | 0x0004));
		}
	}
else	{
	/* List Not Active */
	/* --------------- */
	return(0);
	}
}

VOID	GenIpStr( sptr , i )
BPTR	sptr;
EXAWORD	i;
{

	*(sptr++) = '('; itoxxxx(i,sptr,4); *(sptr + 4) = ')';
	*(sptr + 5) = (EXABYTE) 0; xcodip = i;
	return;

}

/*
 *	I D B _ L O C A T E ( codip )
 *	-----------------------------
 *	Positions to the nearest line in the source
 *	for idb_window
 *
 */

VOID	idb_locate( codip )
EXAWORD	codip;				/* Offset to be saught	*/
{
	EXABYTE	lword[MOTSIZE+1];	/* Local token buffer	*/
	EXAWORD	thisip;			/* Token Convert int	*/
	EXAWORD	wlen;			/* Token length		*/

	if ( codip > xcodip ) {

		if ( PushInfo() != 0 ) 
			return;
		if (idb_baslist( codip ) == 0 ) {
			PopInfo();
			return;
			}
		LibInfo();

		}

	thisip = 0;	xcodip = codip;

	do 	{
		/* Save Current Infos */
		/* ------------------ */
		if ( PushInfo() != 0 ) 
			return;

		/* Seek Line Start */
		/* --------------- */
		fwdlignes(1);

		/* If Liste Type -ml Jump Source line number */
		/* ----------------------------------------- */
		if ( ((IdbFlag & IDB_ASM) == 0 )
		&&    ( idb_fgetmot( (BPTR) lword ) == 0 )) { 
			PopInfo(); 
			return;
			}

		/* Collect Next Word (if None then Restore last Info) */
		/* -------------------------------------------------- */
		if ( (wlen = idb_fgetmot( (BPTR) lword )) == 0 ) { 
			PopInfo(); 
			return;
			}

		/* Terminate and Convert to Integer */
		/* -------------------------------- */
		lword[wlen] = (EXABYTE) 0;
		if ( lword[0] != '(' )
			thisip = 0; 
		else	thisip = hextoi( (BPTR) &lword[1] , 4); 

		/* Loose last State if less or Equal */
		/* --------------------------------- */
		if ( thisip <= codip ) 
			LibInfo();
		}
	while (thisip <= codip);			
	PopInfo();
	return;
}

VOID	idb_Pager( natb )
EXAWORD	natb;
{
	/* Save our Current Details */
	/* ------------------------ */
	if ( PushInfo() != 0 ) 
		return;

	/* Display N lines */
	/* --------------- */
	prnlignes( ListLigne , natb ); 

	/* Recover Liste pointer */
	/* --------------------- */
	(VOID) PopInfo();
	return;
}

EXAWORD	ExternChck()
{
	EXAWORD	reflg,l;
	EXABYTE	lmots[MOTSIZE+1];
	if (PushInfo() != 0) { return(27); }
	idb_bgetmot((BPTR) lmots);	/* ProcName String 	*/
	idb_bgetmot((BPTR) lmots);	/* "PROC"   String 	*/
	l= idb_bgetmot((BPTR) lmots);	/* "EXTERN"		*/
	lmots[l] = (EXABYTE) 0;
	reflg = CompWild( (BPTR) lmots , (BPTR) "EXTERN" );
	PopInfo();
	return( reflg );

}

/*
 *	I D B _ I N I T L I S T ()
 *	--------------------------
 *	Initialisation of QUICK FIND management Tables
 *	and interrogation of MAP Sectors
 *	Returns ZERO OK
 *	Else	Error Value
 *
 */

EXAWORD	idb_InitList()
{

	EXAWORD	x;
	EXAWORD	l,i;
	EXABYTE	lmots[MOTSIZE+1];
	EXAWORD	ExtPFlg;
	EX_FILE_HANDLE MapHandle;

	/* Check for MAP secteur in T-Code */
	/* ------------------------------- */
	if (( MapSect == 0 ) || ( MapSect == MOINS_UN )) 
		return(40);

	/* Allocate Quick Find Table For Procedures */
	/* ---------------------------------------- */
	if ( adr_tpr != 0 ) {
		if ( (idb_QFP = (struct QwikFind PTR) allocate((USINT) ((procmaxid + 1) * sizeof(struct QwikFind)))) == (struct QwikFind PTR) 0 ) 
			return(27); 
		}
	else	idb_QFP = (struct QwikFind PTR) 0;

	/* Allocate Quick Find Table For Segments */
	/* -------------------------------------- */
	if ( (idb_QFS = (struct QwikFind PTR) allocate((USINT) ((SegmentCount + 1) * sizeof(struct QwikFind)))) == (struct QwikFind PTR) 0 ) 
		return(27); 

	return(idb_MapRead());
}

EXAWORD	idb_uplist( codip )
EXAWORD	codip;
{

	EXAWORD	thisip;
	EXAWORD	x;
	EXABYTE	lmots[MOTSIZE+1];
	EXAWORD	l;

	thisip = xcodip;

	do	{
		x = ((thisip - codip) / 4);
		if ( x > 0 ) { 
			baklignes(x+1); 

			if ( ((IdbFlag & IDB_ASM) == 0 )
			&&   (idb_fgetmot((BPTR) lmots) ) == 0 ) 
					return(0);

			if ((l = idb_fgetmot((BPTR) lmots) ) == 0) 
				return(0);
			lmots[l] = (EXABYTE) 0;
			if ( lmots[0] == '(' )
				thisip = hextoi( (BPTR) &lmots[1] , 4 );
			else	thisip = 0; 

			if ((IdbFlag & IDB_ASM) == 0 )
				(VOID) idb_bgetmot((BPTR) lmots);
				
			(VOID) idb_bgetmot((BPTR) lmots);
			}
		else	thisip = 0; 
		}
	while	( thisip > codip );
	return(1);
}

EXAWORD	FwdEcart( ecart )
EXAWORD	ecart;
{
	if ( PopInfo() != 0 )   { return(0); }
	if ( ecart > 64 )       { return(0); }
	if ( PushInfo() != 0 )  { return(0); }
	return((ecart+4));
}


EXAWORD	idb_baslist( codip )
EXAWORD	codip;
{

	EXAWORD	thisip;
	EXAWORD	x;
	EXABYTE	lmots[MOTSIZE+1];
	EXAWORD	l;
	EXAWORD	ecart;

	/* Save current list position */
	/* -------------------------- */
	if ( PushInfo() != 0 ) { return(0); }

	/* Calculate search details */
	/* ------------------------ */
	thisip = xcodip; ecart = 16;
	
	do	{
		x = ((codip - thisip) / ecart);
		if ( x > 0 ) { 
			fwdlignes((x+1)); 
			if ((IdbFlag & IDB_ASM) == 0 ) {
				if (idb_fgetmot((BPTR) lmots) == 0 ) { 
					if ((ecart = FwdEcart(ecart)) == 0) {
						return(0);
						}
					continue;
					}
				}
			if ((l = idb_fgetmot((BPTR) lmots) ) == 0) {
				if ((ecart = FwdEcart(ecart)) == 0) {
					return(0);
					}
				continue;
				}
			lmots[l] = (EXABYTE) 0;
			if ( lmots[0] == '(' ) {
				thisip = hextoi( (BPTR) &lmots[1] , 4 );
				}
			else	{ 
				continue;
				}
			if ((IdbFlag & IDB_ASM) == 0 ) {
				(VOID) idb_bgetmot((BPTR) lmots);
				}
			(VOID) idb_bgetmot((BPTR) lmots);
			}
		else	{ 
			thisip = codip;
			}
		}
	while	( thisip < codip );
	LibInfo();
	xcodip = thisip;
	idb_uplist(codip);
	return(1);
}

EXAWORD idb_window( csval , codip , csmode )

EXAWORD	csval,codip,csmode;

{
	EXABYTE	codipstr[8];

	if ( csmode == 0 ) {	/* Alors Recherche Segment */

		/* Check for Current Segment OK */
		/* ---------------------------- */
		if ( csval != lfSegId ) {

			/* Must Seek Start of Segment */
			/* -------------------------- */
			if ( idb_seekseg( csval) == 0) { return(0x0001); }
			lfSegId = csval; xcodip = 0; lfPrcId = EXDB_FFFF;
			}
		else	{
			if ( codip < xcodip ) {
				if ( codip < (xcodip - codip)) {
					if ( idb_seekseg( csval) == 0) { return(0x0001); }
					lfSegId = csval; xcodip = 0; lfPrcId = EXDB_FFFF;
					}
				else	{
					if ( idb_uplist( codip ) == 0 ) {
						if ( idb_seekseg( csval) == 0) { return(0x0001); }
						lfSegId = csval; xcodip = 0; lfPrcId = EXDB_FFFF;
						}
					}
				}
			}
		}
	else	{ 
		/* Check For Procedure Currently Active */
		/* ------------------------------------ */
		if ( csval != lfPrcId ) {
			/* Must Seek Start of Procedure */
			/* ---------------------------- */
			if ( idb_seekprc( csval ) == 0) { return(0x0001); }
			lfPrcId = csval; xcodip = 0; lfSegId = EXDB_FFFF;
			}
		else	{	
			/* Check For depassement d'offset */
			/* ------------------------------ */
			if ( codip < xcodip ) {
				if ( codip < (xcodip - codip)) {
					if ( idb_seekprc( csval ) == 0) { return(0x0001); }
					lfPrcId = csval; xcodip = 0; lfSegId = EXDB_FFFF;
					}
				else	{
					if ( idb_uplist( codip ) == 0 ) {
						if ( idb_seekprc( csval ) == 0) { return(0x0001); }
						lfPrcId = csval; xcodip = 0; lfSegId = EXDB_FFFF;
						}
					}
				}
			}
		}

	idb_locate(codip);

	/* Go back 6 lines for Window effect */
	/* --------------------------------- */
	underspill = 0;
	baklignes( (( ListLigne / 2 ) + 1) );
	idb_Pager(2);
	return(0x0005);
}

/*
 *	I D B _ S A D R ( V , R , F )
 *	-----------------------------
 *	This functions returns the Segment / Procedure ID
 *	and a flag to indicate whether segment or Procedure
 *	for the current List Display Line (VirtLyne)
 */
	
EXAWORD	idb_Sadr( VirtLyne , res1 , res2 )
EXAWORD	VirtLyne;
WPTR	res1;
WPTR	res2;
{
	EXAWORD	lsk;
	EXAWORD	i;
	EXAWORD	spill;
	ULONG	where;

	/* Exclude impossibility */
	/* --------------------- */
	if ( QwikFlag != 0 ) { return(MOINS_UN); } 

	/* Save Current Liste Status */
	/* ------y */
	/* --------------------- */
	if ( QwikFlag != 0 ) { return(MOINS_UN); } 

	/* Save Current Liste Status */
	/* ------------------------- */
	if (PushInfo() != 0) { return(MOINS_UN); }

	/* Calculate start line id Real */
	/* ---------------------------- */
	lsk = ((ScreenLin - ListLigne) + 1);

	spill = underspill;

	/* Seek to the Virtual Line */
	/* ------------------------ */
	while ( lsk < VirtLyne ) { 
		if ( spill > 0 ) 	{ spill--; 	}
		else			{ fwdlignes(1); }
		lsk++;
		}
	
	where = filegard.SectGod + filegard.ByteGod;
	
	/* Search for Segment zone */
	/* ----------------------- */
	i = 0;
	while ( i < SegmentCount ) {
		if (( where >= ( (*(idb_QFS + i)).QFL_Sdeb + (*(idb_QFS + i)).QFL_Ideb ) ) && ( where <= ( (*(idb_QFS + i)).QFL_Sfin + (*(idb_QFS + i)).QFL_Ifin)) && ((*(idb_QFS + i)).QFL_FicId == filegard.Fichier )) {
			*res2 = 0;  *res1 = (*(idb_QFS + i )).QFL_Pid;
			PopInfo(); return(0);
			}
		i++;
		}
	i = 0;

	/* Search for Procedure Zone */
	/* ------------------------- */
	while ( i < procmaxid ) {
		if (( where >= ( (*(idb_QFP + i)).QFL_Sdeb + (*(idb_QFP + i)).QFL_Ideb ) ) && ( where <= ( (*(idb_QFP + i)).QFL_Sfin + (*(idb_QFP + i)).QFL_Ifin)) && ((*(idb_QFP + i)).QFL_FicId == filegard.Fichier )) {
			*res2 = 1;  *res1 = ((*(idb_QFP + i )).QFL_Pid / 16);
			PopInfo(); return(0);
			}
		i++;
		}
	
	/* Recover Liste Infos */
	/* ------------------- */
	PopInfo();
	return(MOINS_UN);

}
BPTR	JumpWord( lptr )
BPTR	lptr;
{
	/* Jump White Space */
	/* ---------------- */
	while (( *lptr != (EXABYTE) 0 ) && ( *lptr == ' ')) { lptr++; }
	/* Jump None  Space */
	/* ---------------- */
	while (( *lptr != (EXABYTE) 0 ) && ( *lptr != ' ')) { lptr++; }
	/* Jump White Space */
	/* ---------------- */
	while (( *lptr != (EXABYTE) 0 ) && ( *lptr == ' ')) { lptr++; }
	return((BPTR) lptr); 

}

VOID	FindIci()
{
	idb_CtrlOff();
	filegard.ByteLim = read_from_list_file(filegard.SectGod,filegard.ByteGod);
	FindHere();
	return;
}

EXAWORD	idb_libelle( lptr )
BPTR	lptr;
{
	EXAWORD	x;

/* Check for Empty String :=> List Selection */
/* ----------------------------------------- */
if ( strlen( lptr ) == 0 ) {	idb_libelist();		}
else	{
	if ( GestEtt != (struct idblabel PTR) 0 ) { 
		x = 0;
		while ( x < LibCtrl ) {
			/* Check for LABEL match */
			/* --------------------- */
			if ( CompWild((*(GestEtt + x)).Nptr,lptr) == 0 ) {

				/* Check for Liste Swap Needed */
				/* --------------------------- */
				if ( (*(GestEtt + x)).File != filegard.Fichier ) {

					/* Attempt to Swap list file */
					/* ------------------------- */
					if ( ListeSwap( (*(GestEtt + x)).File ) == 0 ) {
						return(1);
						}

					}
				/* Reposition within Liste File */
				/* ---------------------------- */
				filegard.SectGod = (*(GestEtt + x)).Sect;
				filegard.ByteGod = (*(GestEtt + x)).Byte;
				FindIci(); return(0);
				}
			x++;
			}
		}
	if ( CompWild((BPTR) lptr,(BPTR) "SEGMENT*") == 0 ) {
		lptr = (BPTR) JumpWord((BPTR) lptr);
		if ( *lptr != (EXABYTE) 0 ) {
			x = atoi((BPTR) lptr , 3);
			if ( idb_seekseg( x ) != 0 ) {
				FindIci(); 
				return(0);
				}
			}
		}
	if ( CompWild((BPTR) lptr,(BPTR) "PROC*") == 0 ) {
		lptr = (BPTR) JumpWord((BPTR) lptr);
		if ( *lptr != (EXABYTE) 0 ) {
			x = ProcNumb((BPTR) lptr);
			if ( idb_seekprc( (x * 16) ) != 0 ) {
				FindIci(); 
				return(0);
				}
			}
		}
	Verbose((BPTR)TalkPtr[85]);
	/* "Libelle in-existante" */
	/* ---------------------- */
	return(1);
	}
return(0);
}
VOID	idb_libelkill(lptr)
BPTR	lptr;
{
	EXAWORD	x,y,z;

if ( GestEtt != (struct idblabel PTR) 0 ) { 
	x = 0; z = 0;
	while ( x < LibCtrl ) {
		if ( CompWild((*(GestEtt + x)).Nptr,lptr) == 0 ) {
			liberate( (*(GestEtt + x)).Nptr ); 
			if ( LibCtrl > 0 ) { LibCtrl--; }
			for ( y = x; y < LibCtrl; y++ ) {
				(*(GestEtt + y)).Nptr = (*(GestEtt + (y+1))).Nptr;
				(*(GestEtt + y)).Sect = (*(GestEtt + (y+1))).Sect;
				(*(GestEtt + y)).Byte = (*(GestEtt + (y+1))).Byte;
				(*(GestEtt + y)).File = (*(GestEtt + (y+1))).File;
				}
			z++;
			}
		else	{ x++; }
		}
	if ( z > 0 ) 	{	 
			Verbose((BPTR)TalkPtr[86]);
			/* "Libelle suprimee" */
			/* ------------------ */
			return; 
			}
	}
Verbose((BPTR)TalkPtr[85]);
/* "Libelle in-existante" */
/* ---------------------- */
return;
}

VOID	idb_libelist()
{
	EXAWORD	x,y,lno;
	if ( LibCtrl > 0 ) {
		WdwLimit(2,(LibCtrl+2),36);
	   	if ( PushZone(WindCord[2][0],WindCord[2][1],(LibCtrl+2),36,0x0013,Couleurs[2][0],Couleurs[2][1]) != 0 ) { 
			Debordement();
			return; 
			}
		y = 0;
		do 	{
			lno = 1;	
			for ( x = 0; x < LibCtrl; x++ ) {
				wdw_xpos(lno++,2); 
				if ( x == y ) { ColourAtb(2); }
				else	      { ColourAtb(0); }
				db_xcprintf( (*(GestEtt + x)).Nptr );
				}
			x = x_getch();
			if ( x == syskey[IO_BAS] ) {
				y++;
				if ( y >= LibCtrl ) { y = 0; }
				continue;
				}
			if ( x == syskey[IO_UP] ) {
				if ( y > 0 ) 	{ y--; 		   }
				else		{ y = LibCtrl - 1; }
				continue;
				}
			if (( x == 0x001C ) || ( x == 0x0037 ) || ( x == 0x000C)) {
				idb_fldebut(); idb_CtrlOff();
				x = IO_ESC;
				}
			}
		while ((x != IO_RC) && ( x != IO_ESC));
		PopZone();
		if ( x == IO_RC ) {	(VOID) idb_libelle( (*(GestEtt + y)).Nptr ); }
		}
	return;
}

VOID	idb_libeladd( lptr )
BPTR	lptr;
{
	EXAWORD	x,y;
	BPTR	wptr;
	if ( GestEtt == (struct idblabel PTR) 0 ) {
		if ( (GestEtt = (struct idblabel PTR) allocate((USINT) (sizeof( struct idblabel ) * LIBELMAX ))) == (struct idblabel PTR) 0) {
			Debordement();
			return;
			}
		}
	x = 0;

	/* Check for Label Replacement */
	/* --------------------------- */
	while (( x < LibCtrl ) && ( CompWild(lptr,(*(GestEtt + x)).Nptr) != 0 )) { x++; }
				
	if ( x < LIBELMAX ) {
		y = strlen( lptr );
		if ( y > 0 ) {
			wptr = (BPTR) allocate((USINT) (y + 1));
			if ( wptr != (BPTR) 0 ) {
				(*(GestEtt + x)).Nptr = wptr;
				memcpy(wptr,lptr,(USINT) (y + 1));
				(*(GestEtt + x)).Sect = filegard.SectGod;
				(*(GestEtt + x)).Byte = filegard.ByteGod;
				(*(GestEtt + x)).File = filegard.Fichier;
				if ( x == LibCtrl ) {
					Verbose((BPTR)TalkPtr[87]);
					/* "Libelle ajoutee" */
					/* ----------------- */
					LibCtrl++;
					}
				else	{ 
					Verbose((BPTR)TalkPtr[88]);
					/* "Libelle modifiee" */
					/* ------------------ */ 
					}
				}
			else	{ 
				Debordement();
				}
			}
		}
	else	{	
		Verbose((BPTR)TalkPtr[89]);
		/* "Debordement de la table des libelles" */
		/* -------------------------------------- */
		}
	return;
}


EXAWORD	idb_LineLen()
{
	EXAWORD	compt,c;

	/* Save Current List Position */
	/* ------------------------
		}
	return;
}


EXAWORD	idb_LineLen()
{
	EXAWORD	compt,c;

	/* Save Current List Position */
	/* -------------------------- */
	if ( PushInfo() != 0 ) { return(1); }

	/* Scan and Count till end of Line or Source */
	/* --------------------------- */
	if ( PushInfo() != 0 ) { return(1); }

	/* Scan and Count till end of Line or Source */
	/* ----------------------------------------- */
	compt = 1;
	while ( 1 ) {
		switch ((c = idb_fgetc())) {
			case 0x000A	: 
			case 0x0000	:
			case MOINS_UN	: PopInfo(); return(compt);
			case 0x0009	: c = 0x0020;
			default		: if ( c >= 0x0020 ) { compt++; }
			}
		}
}
