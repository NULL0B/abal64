/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXI.C
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */

/* Mises a jour :
 * ------------
 * 29/02/00 : (#AT) Amelioration EXA-57 - LOAD.GO modifications for ABAL v.2.2a (WIN32 only)
 * 26/10/00 : (#SP) Fixing a bug nbfics (the descriptor of the file was enlarged and so assign table
 *            can't be allocated now the size of the allocated Assign table is checked before allocation.
 *	------------ 2.2b -------------------------------------------------
 * 23/12/02 : (#FC+BG+IJM) On dépile les procédures ds exstop() pour éviter de changer le TCodeFileHandle.
 *            Ceci est nécessaire lorsqu'un chain est effectué dans une procédure d'overlay (exemple : zchain en mode zat.at)
 */

#ifndef	_EXI_C
#define	_EXI_C

#include "exinit.h"		/* General initialisations header	*/

#ifdef INTEL
#include "exprag0.h"		/* Microsoft stack checking pragma	*/
#endif

#ifdef UNIX
#ifdef	DEBUGGER
				/* ------------------------------------	*/
extern	EXAWORD	db_step_ctrl;	/* Debug Execution Cycle Flags		*/
				/* ------------------------------------	*/
#endif
#endif

#ifdef	PROLOGUE
extern	EXAWORD	RAM_TYPE;	/* Malloc Option Function Code		*/
#endif

extern	BPTR	LDS_base;	/* Procedure local Variables base	*/
extern	EXAWORD	LDS_dex;	/* Procedure local Variable protect	*/

#ifdef WIN32
#include "pubproto.h"
#else
BPTR	kode_lode(EXAWORD secteur, EXAWORD longeur);
#endif

#include "exwords.h"
#include "exptr.h"

#include "extrace.h"
#include "exasyslog.h"

#include "exiniptr.c"		/* Pointer variable initialisation	*/
#include "exinidcl.c"		/* Data memory initialisation		*/


/*		-----------------------------------			*/
/*		I N I T _ D A T A ( ID, LNG, DESC )			*/
/*		-----------------------------------			*/

#ifdef UNIX

#ifdef RT_AIX
#ifndef BPTR
#define BPTR unsigned char *
#endif
#endif

#endif

BPTR init_data(id,lng,desc)
EXAWORD id;			/* Count of variables to Initialise	*/
EXAWORD lng;			/* Length of DATA space needed		*/
BPTR	desc;			/* 1st Variable Descriptor pointer	*/
{
	BPTR	b;
#ifndef	UNIX
	EXAWORD	kode_b_lode( BPTR , EXAWORD , EXAWORD );
#else
	EXAWORD	kode_b_lode();
#endif

/* Attempt to allocate storage for Global Data Allocation zone */
/* ----------------------------------------------------------- */
if ( (b = (BPTR) allocate((USINT) lng)) != (BPTR ) 0) {

#ifdef	ABAL14

	/* Check for Global Image to Load from Disk */
	/* ---------------------------------------- */

	if (( WORDSIZE == 2 )
	&& ( DataImageSector == MOINS_UN_SHORT ))
		DataImageSector = MOINS_UN;

	if (( DataImageSector != 0 ) 
	&& ( DataImageSector  != MOINS_UN )) {
		if ( kode_b_lode( b , DataImageSector , DataImageLength ) == MOINS_UN ) {
			liberate( b );
			return( (BPTR) 0 );
			}

		return( (BPTR) b );
		}

	/* No data image present so must prepare Global Data Init State */
	/* ------------------------------------------------------------ */
#endif
	/* Perform Data Image Initialisation */
	/* --------------------------------- */
	return( initialise_data_image( desc, b, id ) );

	}					/* Endif b != 0 	*/
else 	{  
	/* Unable to allocate DATA IMAGE ZONE */
	/* ---------------------------------- */ 
	err_val = EXER_MEMFULL; return((BPTR ) 0); 
	}

}

/*	Chargement Des Noms des Variables	*/
/*	---------------------------------	*/

#ifdef	DEBUGGER

BPTR nomlode(num,sec)
EXAWORD	num;
EXAWORD	sec;
{
/*	Ensure Tcode file is Open (might have been closed via CLOSE=0) 	*/
/*	--------------------------------------------------------------	*/
	VerifTcode();
	return( kode_lode( sec, (num * 10)) );
}

VOID	lvnomlode()
{
	EXAWORD	x,y;

	if ( LocalNamesTable != (BPTR) 0 ) { 
#ifdef	VMS_OPTIMISED
		if (!(UseVmsSection))
#endif
			liberate(LocalNamesTable);

		LocalNamesTable = (BPTR) 0; 
		}
	if ( LocalDataTable == (BPTR) 0 ) return;
	x = Tcodeword( (LocalDataTable + WORDSIZE) );
	if ( x != 0 ) {
		y = Tcodeword( LocalDataTable );
		LocalNamesTable = (BPTR) nomlode(y,x);
		var_locl  = y;
		}
	return;
}

#endif

#ifdef	ABAL14
EXAWORD	kode_b_lode( memptr , secteur , longeur )
BPTR	memptr;
EXAWORD	secteur;
EXAWORD	longeur;
{
	EXAWORD	NbBlock;
	EXAWORD	NbReste;

	/* Check for and load complete BLOCKs */
	/* ---------------------------------- */
	if ((NbBlock = ( longeur / TCODEBLOCK )) > 0 ) {

		/* Attempt to load blocks */
		/* ---------------------- */
		if ( SectRead(TcodeFileHandle,memptr,(NbBlock * TCODEBLOCK),secteur) == MOINS_UN ) {

			/* Error during file read */
			/* ---------------------- */
			return( MOINS_UN );

			}
		}
	
	/* Check for and load incomplete BLOCK */
	/* ----------------------------------- */
	if ((NbReste = ( longeur % TCODEBLOCK )) > 0 ) {

		/* Attempt to load final block */
		/* --------------------------- */
		if ( SectRead(TcodeFileHandle,(BPTR) askbuf,TCODEBLOCK,(secteur+NbBlock)) == MOINS_UN ) {

			/* Error during file read */
			/* ---------------------- */
			return( MOINS_UN );

			}

		/* Transfer from Temporary Buffer to final buffer */
		/* ---------------------------------------------- */
		memcpy((BPTR) (memptr + (NbBlock * TCODEBLOCK)), (BPTR) askbuf , (USINT) NbReste );

		}
	/* Return Success */
	/* -------------- */
	return( 1 );


}

BPTR	kode_lode( EXAWORD secteur , EXAWORD longeur )
{
	BPTR	memptr=(BPTR) 0;

#ifdef	MMAP_OPTIMISED
	return( ReadMmapFile( TcodeFileHandle, secteur, longeur ) );
#endif

#ifdef	VMS_OPTIMISED
	if ( UseVmsSection ) {
		return( (MappedSection[0] + (secteur * 256)) );
		}
#endif

	/* Attempt to Allocate a buffer for the required block */
	/* --------------------------------------------------- */
	if ((memptr = (BPTR) allocate((USINT) longeur)) == (BPTR) 0) {
		return( (BPTR) 0 );
		}

	/* Perform actual loading into the buffer */
	/* -------------------------------------- */
	if ( kode_b_lode( memptr , secteur , longeur ) == MOINS_UN ) {

		liberate((BPTR) memptr );
		return( (BPTR) 0 );
		}
	else	{
		return( (BPTR) memptr );
		}

}

/* #ifdef	VMS_OPTIMISED */	

BPTR	kode_seg_lode( buffer, secteur, longueur )
BPTR	buffer;
EXAWORD	secteur;
EXAWORD	longueur;
{
#ifndef	DEBUGGER
	if (!(UseVmsSection)) {
		if (kode_b_lode( buffer,secteur, longueur ) == MOINS_UN)
			return( (BPTR) 0 );
		else	return( buffer );
		}
	return( kode_lode( secteur, longueur ) );
#else
	if (kode_b_lode( buffer,secteur, longueur ) == MOINS_UN)
		return( (BPTR) 0 );
	else	return( buffer );
#endif
}

BPTR	kode_wr_lode( secteur, longueur )
EXAWORD	secteur;
EXAWORD	longueur;
{
	BPTR	rptr;
	BPTR	mptr;

	if ((rptr = kode_lode( secteur, longueur )) == (BPTR) 0)
		return( rptr );
	if (!(UseVmsSection))
		return( rptr );

	if ((mptr = (BPTR) allocate((USINT) longueur )) == (BPTR) 0)
		return((BPTR) 0);
	memcpy( mptr, rptr, longueur );
	return( mptr );
}

/* #endif */

	/* ----------------------------------------------- */
#else	/* Old method (allocates memory in 256 byte blocks */
	/* ----------------------------------------------- */

BPTR	kode_lode(secteur,longeur)
EXAWORD	secteur,longeur;
{
register EXAWORD y;
         BPTR	memptr;

y = longeur / TCODEBLOCK;
if ((longeur % TCODEBLOCK) != 0) 
	y++;
if ((memptr = (BPTR ) calloc((USINT) (y * TCODEBLOCK),(USINT) 1)) == 0) 
	return((BPTR) 0);
else 	{
	if ( SectRead(TcodeFileHandle,memptr,(y * TCODEBLOCK),secteur) != MOINS_UN )
		return(memptr);
	liberate( memptr );
	}
return((BPTR ) 0);
}

#endif

/*
 *	F I C H F E R M ( )
 *	-------------------
 *	Closes all files and liberates all file management memory except
 *	for the file table it's self.
 *
 */
VOID	fichferm()
{
	EXAWORD		holdtrap;
	EX_FILE_HANDLE	holdnlog;

	/* If File Table Has been allocated */
	/* -------------------------------- */
	if ( AssignTable != (struct fichdt PTR) 0 ) {

		/* Liberate Current T-Code File Infos */
		/* ---------------------------------- */
		lfh = 0; 
		if ( (*(AssignTable)).unlog == TcodeFileHandle )
			holdnlog = EX_UNUSED_HANDLE;
		else	holdnlog = TcodeFileHandle; 
		if ((err_val = loadfich()) != 0) 
			return;

		(VOID) freefich(); 

		if ((err_val = savefich()) != 0)
			return; 
		TcodeFileHandle = holdnlog;

		holdtrap = sicico;
		sicico |= ONSEM_TRP;

		/* Liberate all other File Entries */
		/* ------------------------------- */
		for ( lfh = 1; lfh <= diezfile; lfh++ ) {

			if ((err_val = loadfich()) != 0) 
				break;

			(VOID) freefich(); 

			if ((err_val = savefich()) != 0)
				break;
		} 

		sicico = holdtrap;

		errno = 0; err_val = 0;

		}

	return;
}

/*
 *	E X Z E R O ( )
 *	---------------
 *	Resets all pointers to (BPTR) 0 !!! 
 *
 */

VOID	exzero()
{
#ifdef	ABAL21
	initialise_task_control();
#endif
#ifdef	ABAL32A
	reset_thread_manager();
#endif
	VmemFid = 0;				/* Buffer  File ID   	*/
	VmemLng = 0;				/* Buffer  Length    	*/
	VmemOfs = 0;				/* Buffer  offset    	*/
	VmemDif = 0;				/* = 1;			*/
	VmemExt = 0;				/* = VmemAdj;		*/
	VmemWot = 0;				/* = adr_phy_fich;	*/
	VmemHow = 0;				/* = dleng;		*/
	TcodeWordStack   = (WPTR) 0;		/* Stack des Gosubs	*/
	TcodePushStack   = (WPTR) 0;		/* Stack des Gosubs	*/
	TcodePtrStack    = (BPTR PTR) 0;	/* Stack des Segments	*/
	fieldex   = (BPTR) 0;			/* Virtuel file Buffer	*/
	fieldlen  = 0;				/* Length of Buffer	*/
	ExportTable    = (BPTR) 0;		/* Exported Procedures	*/
	TcodeConstants = (BPTR) 0;		/* Constants Base	*/
	GlobalConstants = (BPTR) 0;		/* Global Constants	*/
	LocalDataTable = (BPTR) 0;		/* Local Descriptors	*/
	GlobalDataTable = (BPTR) 0;		/* Global descriptors	*/
	TcodeByteStack = (BPTR) 0;		/* temporary descriptor */
	LocalDataSegment = (BPTR) 0;		/* Local Data Segment	*/
	GlobalDataSegment = (BPTR) 0;		/* Global Data Segment	*/
	GlobalNamesTable = (BPTR) 0;		/* Name management	*/
	LocalNamesTable = (BPTR) 0;		/* Segment Name manager	*/
	segdata   = (BPTR) 0;			/* Segment DATA manager	*/
	TcodeSegment = (BPTR) 0;		/* Code Segment Base	*/
	TcodeSegmentTable = (struct segmform PTR) 0;	/* Segment table	*/
	GlobalErrorTrap = (ERRORPTR) 0;		/* Error management	*/
	TcodeProcTable = (struct procform PTR) 0;/* Procedure table	*/
	LDS_base  = (BPTR) 0;			/* Local Variables	*/
	LDS_dex   = 0;				/* LDS Protect level	*/
	extwrite  = 0;				/* Field=x Rewrite flag */
	Overlay_Code = (BPTR) 0;		/* Reset Code overlay	*/
	Overlay_Data = (BPTR) 0;		/* Reset Data overlay	*/
	Overlay_User = MOINS_UN;		/* Reset Overlay User	*/

#ifdef	ABAL21
	MaxOverlayConst = 0;
	Overlay_Const   = (BPTR) 0;

	reset_indirection_control();

	/* Initialisation of dynamic allocation controller */
	/* ----------------------------------------------- */
	initialise_dynamic_allocation();

	initialise_attachments();
#endif

	reset_event_procedure();
	reset_timer_procedure();
	return;	
}

/*
 *	E X L B S M ( )
 *	---------------
 *	This routine liberates all memory spaces allocated by the
 *	calling program (Called due to chainage)
 */

VOID	exit_procedures()
{
	/* While Procedure Flag True */
	/* ------------------------- */
	while (( sicico & ONSEM_PRC ) 
	&&     ( ip_next > 0 )
	&&     ( mindex  > 0 )) {

		/* Destack all Procedures */
		/* ---------------------- */
		(VOID) procedure_exit(1);

		/* Detect and remove Extern Event Handler */
		/* -------------------------------------- */
		check_extern_event();

		}

	return;
}

VOID	return_segments()
{
	while ( mindex > 0 )
		rest_segm();

}


VOID	exlbsm()
{
#ifdef	ABAL21
	liberate_task_control(1);
#endif	

/* 	Liberate PROCEDURES : CODE,TABLES et DONNEES		*/
/* 	--------------------------------------------	 	*/
	if ( TcodeProcTable != (struct procform PTR) 0 ) {

		exit_procedures();


		/* Liberate PROCEDURE CODE,LDT,LDS */
		/* ------------------------------- */
		LiberateProcedureTable( procmaxid );

		}

	/* Liberate SEGMENTS : CODE, TABLES et DONNEES		*/
	/* ---------------------------------------------------- */
	return_segments();

#ifdef	ABAL32A
	liberate_thread_manager();
#endif

#ifdef	VMS_OPTIMISED
	if (!(UseVmsSection))
#endif
		/* Liberate Static Tables CONSTANTES et TABLE VAR GLOBALE */
		/* ------------------------------------------------------ */
		if ( GlobalConstants != (BPTR) 0 )
			 liberate(GlobalConstants);

	if ( TcodeByteStack != (BPTR) 0 ) 
		liberate(TcodeByteStack);

	/* Allow Current Segment liberation */
	/* -------------------------------- */
	LiberateSegmentContext();

	/* ------------------------------------------------------ */
	/* Liberate the segment table and Resident / Public Zones */
	/* ------------------------------------------------------ */
	/* (Function in EXSEGM.C => EXCODE$(OBJ) )		  */
	/* ------------------------------------------------------ */
	LiberateSegmentTable();

	/* Check for Local Variables Qwick Zone Free needed */
	/* ------------------------------------------------ */
	if ( LDS_base != (BPTR) 0 ) 
		liberate( LDS_base );

#ifdef	VMS_OPTIMISED
	if (!(UseVmsSection)) {
#endif
		if ( Overlay_Code != (BPTR) 0 ) 
			liberate( Overlay_Code );

		if ( Overlay_Data != (BPTR) 0 )
		 	liberate( Overlay_Data );
#ifdef	ABAL21
		if ( Overlay_Const != (BPTR) 0 )
		 	liberate( Overlay_Const );
#endif

#ifdef	VMS_OPTIMISED
		}
#endif
	if ( segdata   	  != (BPTR) 0 ) 
		liberate( segdata );

#ifdef	VMS_OPTIMISED
	if (!(UseVmsSection)) {
#endif
		if ( GlobalNamesTable 	  != (BPTR) 0 ) 
			liberate(GlobalNamesTable);
		if ( LocalNamesTable 	  != (BPTR) 0 ) 
			liberate(LocalNamesTable);
#ifdef	VMS_OPTIMISED
		}
#endif

	/* Liberate Machine Virtuel : Registers, Stacks etc	*/
	/* ---------------------------------------------------- */
#ifndef FixedRegisters
	liberate( Freg ); liberate( Xreg ); liberate( Ireg ); liberate( Areg );
#endif

	/* Liberate Stack Structures */
	/* ------------------------- */
	if ( TcodeWordStack != (WPTR) 0 ) 
		liberate( TcodeWordStack );
	if ( TcodePushStack != (WPTR) 0 ) 
		liberate( TcodePushStack );

	if ( TcodePtrStack  != (BPTR PTR) 0 ) 
		liberate( TcodePtrStack );

	ip_next = 0; mindex = 0; 
	pushtop = 0; pushhold = 0;
	
	/* Liberate File Table entries	*/
	/* ---------------------------  */
	(VOID) fichferm();

	if ( AssignTable != (struct fichdt PTR) 0 ) 
		liberate(AssignTable);

	liberate_assign_allocation();

	/* Liberate Virtuel memory buffer if Used */
	/* -------------------------------------- */
	if ( fieldex != (BPTR) 0 ) 
		liberate(fieldex);
	

#ifdef	ABALPS
#ifndef	TCODELIST
	/* Liberate user functions */
	/* ----------------------- */
	if ( chain == 0 )
		liberate_dynamic_libraries();
#endif
#endif

#ifdef	VMS_OPTIMISED
	if (!(UseVmsSection))
#endif
		if (  GlobalDataTable != (BPTR) 0 )
			liberate(GlobalDataTable);

	if (  GlobalDataSegment != (BPTR) 0 ) 
		liberate(GlobalDataSegment);

#ifdef	ABAL21
	/* Liberation of all dynamic allocation objects */
	/* -------------------------------------------- */
	liberate_attachments();
	liberate_indirection_control();
	liberate_dynamic_allocation();
#endif

	release_error_traps();

	/* Reset all control pointers to Zero	  */
	/* -------------------------------------- */
	exzero();

	sicico = (ONSEM_SI | ONSEM_CIO);
	return;
}

EXAWORD	tcode_stack_allocation( mode )
EXAWORD	mode;
{

	ip_next = 0; mindex = 0;   worktop = 0;
	pushtop = 0; pushhold = 0; workhold = 0;

/*	Allocation of Gosub's Stack 	*/
/*	---------------------------	*/
	if ((TcodeWordStack = (WPTR) calloc((USINT)  diezstk , sizeof(EXAWORD))) == (WPTR) 0 ){
		loadgo=chain=0;
		if ( mode )
			exlbsm();
		Phaseur = 1;
		return(SOFTERROR);
		}

/*	Allocation of PushPop Stack 	*/
/*	---------------------------	*/
	if ((TcodePushStack = (WPTR) calloc((USINT)  diezstk , sizeof(EXAWORD))) == (WPTR) 0 ){
		loadgo=chain=0;
		if ( mode )
			exlbsm();
		Phaseur = 1;
		return(SOFTERROR);
		}

/*	Allocation of Pointer's Stack	*/
/*	-----------------------------	*/
	if ((TcodePtrStack  = (BPTR PTR) calloc((USINT)  diezstk , (USINT) sizeof(BPTR ) )) == (BPTR PTR) 0) {
		loadgo=chain=0;
		if ( mode )
			exlbsm();
		Phaseur = 1;
		return(SOFTERROR);
		}

/*	Allocation of Temporary WorkZone	*/
/*	--------------------------------	*/
	if ((TcodeByteStack = (BPTR ) calloc((USINT) dieztmp,(USINT) 1)) == (BPTR) 0) {
		loadgo=chain=0;	
		if ( mode )
			exlbsm();
		Phaseur = 2;
		return(SOFTERROR); 
		}

#ifdef	USING_DIEZE_HEAP
/*	Allocation of Quick allocation Memory	*/
/*	-------------------------------------	*/
	if ( InitQalloc() == SOFTERROR ) {
		loadgo=chain=0;
		if ( mode )
			exlbsm();
		Phaseur = 3;
		return(SOFTERROR);
		}
#endif
	return( GOODRESULT );

}

EXAWORD	tcode_stack_liberation()
{
	exit_procedures();

	return_segments();

	if (TcodeWordStack != (WPTR) 0 ) 	{	liberate( TcodeWordStack );		}
	if (TcodePushStack != (WPTR) 0 ) 	{	liberate( TcodePushStack );		}
	if (TcodePtrStack != (BPTR PTR) 0 )	{	liberate( TcodePtrStack );		}
	if (TcodeByteStack != (BPTR) 0)	{	liberate( TcodeByteStack );	}
	if ( LDS_base != (BPTR) 0 ) 	{	liberate( LDS_base );		}

	return( GOODRESULT );

}


/*
 *	I N I T	( )
 *	-----------
 *	Initialisation module.
 *
 */

EXAWORD InitialiseTcodeProgram()
{
	EXAWORD x;
	BPTR	temp_base;
#ifdef	VMS_OPTIMISED
	BPTR	TempSection[2];
#endif

/*	----------------------------		*/
/*	Liberate memory if necessary		*/
/*	----------------------------		*/

	if ( chain != 0 ) 
	{
 
#ifdef	VMS_OPTIMISED
		TempSection[0] = MappedSection[0];
		TempSection[1] = MappedSection[1];
		MappedSection[0] = HoldSection[0];
		MappedSection[1] = HoldSection[1];
#endif
		exlbsm(); 		
#ifdef	VMS_OPTIMISED
		MappedSection[0] = TempSection[0];
		MappedSection[1] = TempSection[1];
#endif
	}
	else	exzero();

	/*	Establish Compatibillity mode Now	*/
	/*	---------------------------------	*/
	CompatibleBal = (trad_opt & EXOPT_BAL);

	/*	Allocate memory for Virtual Machine	*/
	/*	-----------------------------------	*/

#ifndef	FixedRegisters

	Freg	= (WPTR) calloc((USINT)  diezreg + 8 ,(USINT)  WORDSIZE );
	Xreg	= (WPTR) calloc((USINT)  diezreg + 8 ,(USINT)  WORDSIZE );
	Ireg	= (WPTR) calloc((USINT)  diezreg + 8 ,(USINT)  WORDSIZE );
	Areg	= (WPTR) calloc((USINT)  diezreg + 8 ,(USINT)  WORDSIZE );

	if (( Freg == (WPTR) 0 ) || ( Xreg == (WPTR) 0 )) 
		return(SOFTERROR);
	if (( Ireg == (WPTR) 0 ) || ( Areg == (WPTR) 0 )) 
		return(SOFTERROR);
#endif

	if ( tcode_stack_allocation(1) == SOFTERROR )
		return( SOFTERROR );

	
	/*	Allocation of File Table     		*/
	/*	------------------------     	 	*/
	if ((AssignTable = (struct fichdt PTR) allocate((USINT) (diezfic + 1)* (USINT) sizeof( struct fichdt ) )) == (struct fichdt PTR) 0 ) 
	{
		loadgo=chain=0;
		exlbsm();
		Phaseur = 3;
		return(SOFTERROR);  
	}
	else	memset((BPTR) AssignTable,0,(USINT) (diezfic + 1)* (USINT) sizeof( struct fichdt ));

	if ( initialise_assign_allocation( (diezfic+1) , 48 ) != GOODRESULT ) 
	{
		loadgo=chain=0;
		exlbsm();
		Phaseur = 3;
		return(SOFTERROR);
	}

	/*	Initialisaion of File Table Handles	*/
	/*	-----------------------------------	*/
	for (x = 0; x <= diezfic; x++ ) (*(AssignTable +x)).unlog = EX_UNUSED_HANDLE;
	
	/*	Establish ASSIGN=0 Informations		*/
	/*	-------------------------------		*/

	/* #BG 06/02/12
	   Si le pointeur sur le service de MA est NULL, c'est le service de MA par defaut qui s'applique
	   (inutile d'affecter explicitement le nom du service de MA par defaut).
	*/

	x = 0; 
	while (inbuf[x] != FILETERM) x++; 
	x++;

	if ((temp_base = (BPTR) allocate( (USINT) (x+1))) == (BPTR) 0 ) 
	{
		loadgo=chain=0;
		exlbsm();
		Phaseur = 3;
		return(SOFTERROR);
	}

	(VOID) memcpy((BPTR) temp_base, (BPTR) inbuf, (USINT) x);
	*(temp_base + x) = (EXABYTE) 0;

	/* #BG 06/02/12 ABALSQL */
	/* -------------------- */
	(*(AssignTable)).url = (BPTR) temp_base;
	(*(AssignTable)).direcp = (BPTR) temp_base; 

#ifdef	ABAL21
	BuildSwapFileName((BPTR) temp_base);
#endif

	temp_base = (BPTR) 0;

	(*(AssignTable)).unlog  = TcodeFileHandle;
	(*(AssignTable)).permf  = 0x0100;
	(*(AssignTable)).aslen = 0;
	(*(AssignTable)).asptr  = (BPTR ) 0;



#ifdef ABALME
	/* 	Allocate extended memory	*/
	/*	------------------------	*/
#ifdef	ABAL21
	if (( adr_tfu != 0 )
	||  ( meg_tfu != 0 )) 
#else
	if ( adr_tfu != 0 )  
#endif
	{
		if ((err_val = (EXAWORD) allocate_extended_memory(adr_tfu)) != 0) 
		{ 
			loadgo=chain=0;
			exlbsm();
			Phaseur = 4;
			return(SOFTERROR); 
		}
	}
#endif
	/*	Load in Variables Table on ERREUR AB  		*/
	/*	------------------------------------		*/
	if (lng_tvg != 0 ) 
	{
		if ((GlobalDataTable = (BPTR) kode_lode(adr_tvg,lng_tvg)) == (BPTR) 0) 
		{
			loadgo=chain=0;
			exlbsm();
			Phaseur = 5;
			return(SOFTERROR); 
		}
		else 	
		{
			temp_base = GlobalDataTable; 
			var_glob = Tcodeword( GlobalDataTable); GlobalDataTable += WORDSIZE;
			nom_glob = Tcodeword( GlobalDataTable); GlobalDataTable += WORDSIZE;
			len_glob = Tcodeword( GlobalDataTable); GlobalDataTable += WORDSIZE;
#ifndef EXECUTEUR
			if (nom_glob != 0) 
			{ 
#ifdef	DEBUGGER
				GlobalNamesTable = (BPTR) nomlode(var_glob,nom_glob); 
#else
				GlobalNamesTable = (BPTR) 0;
#endif
			}
			else	GlobalNamesTable = (BPTR) 0; 
#endif

			/* ---------------------------------------------------- */
			/* Remarque :						*/
			/* ---------------------------------------------------- */
			/*	 VAR_glob is the count of variables		*/
			/*	 NOM_glob is the disk sector which contains 	*/
			/*	          the names of the variables.		*/
			/*	 LEN_glob is the length of variable Space	*/
			/*	          actual variable value.		*/
			/*	 BASE_VARG points to the first Descriptor	*/
			/* ---------------------------------------------------- */

			/* Are there any Global Variables ? */
			/* -------------------------------- */
			if ( len_glob > 0 ) 
			{
				if ((GlobalDataSegment = (BPTR) init_data(var_glob,len_glob,GlobalDataTable)) == (BPTR ) 0) 
				{
					/* Allocation or Analysis Error */
					/* ---------------------------- */
					GlobalDataTable = temp_base;
					loadgo=chain=0;
					exlbsm(); 
					Phaseur = 6;
					return(SOFTERROR); 
				}
			}
			/* Ok only External or File Variables */
			/* ---------------------------------- */
			else	GlobalDataSegment = (BPTR) 0;

			GlobalDataTable = temp_base;
		}	
	}

#ifdef	ABALPS
#ifndef	TCODELIST
	/*	Chargement des Fonctions Utilisateurs		*/
	/*	-------------------------------------		*/
	if (adr_usr != 0) 
	{
		if ( chain == 0 ) 
		{
			if ( InitFuse() == MOINS_UN ) 
			{
				loadgo=chain=0;
				exlbsm();
				Phaseur = 7;
				return(SOFTERROR);
			} 
		}
		else if ( MergeFuse() == MOINS_UN ) 
		{
			loadgo=chain=0;
			exlbsm();
			Phaseur = 7;
			return(SOFTERROR);
		}
	}
#endif
#endif

	/*	Destroy Chainage Condition if it Exists		*/
	/*	---------------------------------------		*/
	loadgo = chain = 0;

	/*	Load in Constantes Table on ERREUR IG  		*/
	/*	-------------------------------------		*/
	if (lng_tcg != 0) 
	{
		if ((GlobalConstants = kode_lode(adr_tcg,lng_tcg)) == (BPTR) 0) 
		{
			exlbsm();
			Phaseur = 8;
			return(SOFTERROR);
		}
	}
	else	GlobalConstants = (BPTR) 0; 

	TcodeConstants = GlobalConstants;

	/*	Load in Segment Table on ERREUR AB   		*/
	/*	----------------------------------		*/
	if (lng_tsg != 0 ) 
	{
		if (LoadSegmentTable(adr_tsg,lng_tsg) == 0) 
		{
			exlbsm();
			Phaseur = 9;
			return(SOFTERROR);
		}
	}
	else 
	{ 
		exlbsm();
		Phaseur = 10;
		return(SOFTERROR);
	}

	/*	Load in the Procedures				*/
	/*	----------------------				*/
	if (adr_tpr != 0) 
	{
		if ( load_procedure_table() == 0) 
		{
			exlbsm();
			Phaseur = 11;
			return(SOFTERROR);
		} 
	}
	else	TcodeProcTable = (struct procform PTR) 0;

/*		Set up the Standard function pointers		*/
/*		-------------------------------------		*/
#ifdef	ABAL64
	smach[3]  = f_clf3;		/* Display Functions */
#endif
#ifdef	ABAL21
	smach[1]  = f_clf1;		/* Object Create/Destroy	*/
	smach[5]  = f_clf5;		/* Object Create/Destroy	*/
	smach[6]  = f_clf6;		/* Object Create/Destroy	*/
#endif
	smach[7]  = f_clf7;		/*                      	*/
	smach[8]  = f_clf8;		/*                  		*/
	smach[9]  = f_clf9;		/* Trig Functions		*/
	smach[10] = f_clfa;		/* Group A string / string 	*/
	smach[11] = f_clfb;		/* Group B string / Integr 	*/
	smach[12] = f_clfc;		/* Group C string / string 	*/
	smach[13] = f_clfd;		/* Group D Gener / Space 	*/
	smach[14] = f_clfe;		/* FIX,ROUN,FPT,INT,VAL		*/
	smach[15] = f_clff;		/* COL LIN NPOS etc		*/

	/* Month / Year table for DATE(4) !!!	*/
	/* ----------------------------------   */
	ymtabl[0] = 31;			/* Janvier		*/
	ymtabl[1] = 28;			/* Fevrier		*/
	ymtabl[2] = 31;			/* Mars			*/
	ymtabl[3] = 30;			/* Avril		*/
	ymtabl[4] = 31;			/* Mai			*/
	ymtabl[5] = 30;			/* Juin			*/
	ymtabl[6] = 31;			/* Juillet		*/
	ymtabl[7] = 31;			/* Aout			*/
	ymtabl[8] = 30;			/* Septembre		*/
	ymtabl[9] = 31;			/* Octobre		*/
	ymtabl[10] = 30;		/* Novembre		*/
	ymtabl[11] = 31;		/* Decembre		*/

	/*	Initialise Programme control Values 		*/
	/*	-----------------------------------		*/

	pushtop   = 0; 
	pushhold  = 0;
	worktop   = 0;			/* Workspace Index reset	*/
	ip_next	  = 0;			/* and GOSUB RETURN index    	*/
	mindex	  = 0;			/* Pointer index to zero	*/
	StackHold = 0;			/* Stack Protection Base	*/
	ExFlgSgn  = 0;			/* Characters are signed	*/

	/* Initialise all IOF default values */
	/* --------------------------------- */
	iof_reset();

	LastFore = conf(17);
	LastBack = conf(18);

	cur_seg = 0; 			/* Reset Current Segment	*/

	/* Reset current Data Controllers */
	/* ------------------------------ */
	datapnt = 0; datadex = 0; datamax = 0;

	rnd_var = 157;			/* Random generator Seed	*/
	chain = 0;			/* Kill chain control handle	*/
	ProcSwap = 0;			/* Variables etendu (ProcRets)	*/
	SystemError = 0L;		/* Reset System Error Value	*/

	/* Attempt to Load Segment 0 */
	/* ------------------------- */
	if ( ldgo_seg(0,0) == 0 ) 
	{	
		exlbsm();		/* Liberate due to Error	*/
		Phaseur = 12;		/* Establish Error Phase Value	*/
		return(SOFTERROR);	/* Return Zero Status		*/
	}

#ifdef	ABAL21
	initialise_indirection_control();
#endif

	SystemError = 0L;		/* Reset System Error Value	*/
	return( GOODRESULT );
}

/*
 *	C R Y P T ( pkey , sptr , slen , mode )
 *	---------------------------------------
 *	Performs the T-Code header unlocking function for protection
 *	against auto-debalers.
 *
 */

#define ENCODE 	1
#define	DECODE	0

BPTR	abal_crypt( unsigned short int pkey, BPTR sptr, unsigned short int slen, unsigned short int mode)
{
	BPTR	rptr;
	EXABYTE	exkm[16][16];
	short int kdex,kdey;
	unsigned short int 	rotor;
	unsigned short int 	cmpt;
	unsigned short int 	x,y;
	unsigned short int 	phase;

	rptr = sptr; cmpt = 0;
	for (x = 0; x < 16 ; x++) 
		for ( y =0; y < 16; y++ )
			exkm[x][y] = (EXABYTE) (cmpt++); 

	rotor = 1; phase = pkey & 0x0007;
	while ( slen > 0 ) {
		if ( mode == ENCODE ) { 
			kdex = ((unsigned short int ) *sptr ) / 16;
			kdey = ((unsigned short int ) *sptr) % 16;
			switch ( phase ) {
				case 1 : kdey++;
				case 0 : kdex--; break;
				case 2 : kdey++; break;
				case 3 : kdey++; 
				case 4 : kdex++; break;
				case 5 : kdex++;
				case 6 : kdey--; break;
				case 7 : kdex--; kdey--;
				}
			}
		else	{
			for ( x = 0; x < 16; x++ ) {
				for ( y = 0; y < 16; y++ ) {
					if ( exkm[x][y] == *sptr ) {
						kdex = x; x = 16;
						kdey = y; y = 16;
						}
					}
				}
			switch ( phase ) {
				case 1 : kdey--;
				case 0 : kdex++; break;
				case 2 : kdey--; break;
				case 3 : kdey--; 
				case 4 : kdex--; break;
				case 5 : kdex--;
				case 6 : kdey++; break;
				case 7 : kdex++; kdey++;
				}
			}
		if ( kdex > 15 ) 
			kdex = 0; 
		if ( kdey > 15 ) 
			kdey = 0; 
		if ( kdex <  0 ) 
			kdex = 15;
		if ( kdey <  0 ) 
			kdey = 15; 
		if ((pkey & rotor ) != 0 ) {
			phase++;
			if ( phase > 7 ) 
				phase = 0;
			}
		rotor <<= 1;
		if ( (rotor & 0xFFFF) == 0 ) 
			rotor = 1;
		*(sptr++) = exkm [ kdex ][ kdey ]; slen--;
		}
 	return(rptr);
}


#ifndef ABAL_CRITERIA
#ifdef PRL_SF
EXALONG	lseek( fid , offst , flg )
EXAWORD	fid;				/* Numero Logique du Fichier 	*/
LSEEKTYPE	offst;				/* Offset  Octets dans fichier	*/
EXAWORD	flg;				/* 0 Depuis debut 1 pos courant */
{

	fidseek =  offst;		/* Establish Global Variable	*/
	return(fidseek);		/* Return Current LSEEK Value	*/

}
#endif
#endif

#ifdef	VMS_OPTIMISED

BPTR	load_header( nlog, buffer )
EXAWORD	nlog;
BPTR	buffer;
{
	if (UseVmsSection) {
		memcpy( buffer, MappedSection[0], TCODEBLOCK );
		return( buffer );
		}

	(void) lseek(nlog,0L,SEEK_SET); simcbd = 0x0060;
	if (read((USINT) nlog,(BPTR) buffer, TCODEBLOCK) == TCODEBLOCK)
		return( buffer );
	else	return((BPTR) 0);
}

#endif


EXAWORD	version_verification( EXAWORD trad_ver, EXAWORD trad_ind, EXAWORD trad_typ, EXAWORD min_ver )
{
	/*	Test for Correct BAL Version ABAL = 3, BAL = 1		*/
	/*	----------------------------------------------		*/
#ifdef	VERSION_XX
	if ( trad_typ == '4' ) {
		/* Extended (64K) Variables Table */
		ISLOCAL  = ISLOCAL4;
		TOGLOBAL = TOGLOBAL4;
		}
	else
#endif
	if (trad_typ != '3') {
		err_val = ABAL_ERRSEGM;
		return(SOFTERROR);
		}
#ifdef	VERSION_XX
	else if ( trad_ver < '3' ) {
		ISLOCAL  = ISLOCAL3;
		TOGLOBAL = TOGLOBAL3;
		}
	else	{
		ISLOCAL  = ISLOCAL4;
		TOGLOBAL = TOGLOBAL4;
		}
#endif

	/*	Test for Coherent EXA / ATR Version 1 2 etc   	*/
	/*	-------------------------------------------	*/
	if (trad_ver > ABAL_Version ) {
		err_val = ABAL_ERRSEGM;
		return(SOFTERROR);
		}

	/*	Test for Coherent EXA / ATR Indice 4 5  etc   	*/
	/*	-------------------------------------------	*/
	if ((trad_ver == ABAL_Version ) 
	&&  (trad_ind > ABAL_Index    )) {
		err_val = ABAL_ERRSEGM;
		return(SOFTERROR);
		}

	/* Check for Minimum Version Required */
	/* ---------------------------------- */
	if (( min_ver != 0 )
	&&  ( trad_ver < min_ver )) {
		err_val = ABAL_OPNOTPOSS;
		return( SOFTERROR );
		}
	else	return( GOODRESULT );
}

#define	OFFSET_TIMESTAMP 0x00F0

EXAWORD	TcodeVersion2Header(BPTR aptr)
{
	BPTR	tfdex;		/* Temporary Storage for FDEX	*/
	BPTR	lptr;
	EXAWORD	t;		/* General Counter Variable	*/
	EXAWORD	dcrypt;		/* Tcode header Decryption ID	*/

	/* Save and re-initialise FDEX */
	/* --------------------------- */
	tfdex = fdex;	fdex  = aptr;

#ifdef	VERSION666
	WORDSIZE = 2; 
	PTRSIZE  = 5;
	ISLOCAL  = ISLOCAL3;
	TOGLOBAL = TOGLOBAL3;
	MOINS_UN  = MOINS_UN16;
#endif
#ifdef	ABAL14

	/* Check for Dedicated Executeur */
	/* ----------------------------- */
	if ( CryptCode != 0 )

		/* Dedicated Executeur T-Code Needs DeCrypted */
		/* ------------------------------------------ */
		abal_crypt(CryptCode,(BPTR) fdex , 256 ,DECODE);

#endif

	/* Collect Decryption Code */
	/* ----------------------- */
	dcrypt 		=	TcodeWord16( (fdex + ((21 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 62 */ ) );
	encryptiontime  =	TcodeWord32( (fdex + OFFSET_TIMESTAMP) );

#ifdef	ABALPS

	/* Adresse Table F.U.	*/
	/* ------------------	*/
	adr_usr		=	TcodeWord16( (fdex + (24 * WORDSIZE) + (2*BYTESIZE)  + TCPREFIX /* 68 */ ) );
	lng_usr		=	TcodeWord16( (fdex + (25 * WORDSIZE) + (2*BYTESIZE)  + TCPREFIX /* 70 */ ) );

	if (adr_usr == MOINS_UN) { adr_usr = 0; }


#endif

	/* --------------------------------------------------- */
	/* NOTE : Offset 72 is used for UserLibrary Relocation */
	/* --------------------------------------------------- */

#ifdef	ABAL14
#ifdef	PROLOGUE3
	/* Taille minimum des allocation memoire */
	/* ------------------------------------- */
	diezmin		= 	TcodeWord16( (fdex + (27 * WORDSIZE) +(2*BYTESIZE) + TCPREFIX /*74*/) );

	if (( diezmin == MOINS_UN ) || ( diezmin == 0 ))
		diezmin = 16;
#else
	/* Not Amenesik / Sologic 3 */
	/* -------------- */
	diezmin = 16;
#endif
	/* Collect possible Global Data Image */
	/* ---------------------------------- */
	DataImageSector = TcodeWord16( (fdex + (28 * WORDSIZE) +(2*BYTESIZE) + TCPREFIX  /*76*/) );
	DataImageLength = TcodeWord16( (fdex + (29 * WORDSIZE) +(2*BYTESIZE) + TCPREFIX  /*78*/) ); 

#endif
#ifdef	ABAL21
	/* Collect Extended Memory Options */
	/* ------------------------------- */
	DiezePageSize   = TcodeWord16( (fdex + (30 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  /*80*/) );
	DiezeSwapSize   = TcodeWord16( (fdex + (31 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  /*82*/) );
	DiezeEtendu     = TcodeWord16( (fdex + (33 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  /*86*/) );

	if ( DiezeEtendu == MOINS_UN )
		DiezeEtendu = 0;

	ExportTableSector =TcodeWord16( (fdex + (35 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  ) );
	ExportTableLength =TcodeWord16( (fdex + (36 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  ) );

	MaxIpcSem       = TcodeInteger( (fdex + (49 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  /* 118 = 0x0076 */) );

	if (( MaxIpcSem < 16 ) || ( MaxIpcSem == MOINS_UN ))
		MaxIpcSem = _MAX_SEMAPHORES;

#endif	/* ABAL21 */


	/* Decryptage des informations essentielles */
	/* ---------------------------------------- */
	if (( dcrypt != 0 ) && ( dcrypt != MOINS_UN ))
		abal_crypt(dcrypt,(BPTR) (fdex + TCPREFIX /*18*/),((21 * WORDSIZE)+(2*BYTESIZE)) /*44*/,DECODE);

	trad_ver 	= 	tkodgetc();	/* Tcode Version		*/
	trad_ind 	= 	tkodgetc();	/* Tcode Indice			*/
	trad_typ 	= 	tkodgetc();	/* Translator Type		*/

	/* Collect Program 'Name' */
	/* ---------------------- */
	for (t=0 ; t < 15 ; (trad_nom[t++]=tkodgetc()));

	trad_opt 	= 	tkodgetc();	/* Translator Options		*/
	trad_perm 	= 	tkodgetc();	/* Translator permissions	*/
#ifdef	DISSASSEMBLEUR
	trad_perm	=	0;
#endif
	adr_arg 	=	tkodgetw16();	/* ARG Variable identifier	*/
	adr_tcg 	= 	tkodgetw16();	/* Sector Constant Table	*/
	lng_tcg		=	tkodgetw16();	/* Constant Table Lengt		*/
	adr_tvg		=	tkodgetw16();	/* Sector GDT			*/
	lng_tvg		=	tkodgetw16();	/* Length GDT			*/
#ifdef	ABAL21
	meg_tfu		= 	tkodgetw16();
#else
	fdex += WORDSIZE;				/* Nb blocs 1Mo  Mem Etd 	*/
#endif
	adr_tfu		=	tkodgetw16();	/* Nb Paragraphs MEM ETD 	*/
	adr_tsg		=	tkodgetw16();	/* Segment Table Sector 	*/
	lng_tsg		=	tkodgetw16();	/* Segment Table Length		*/
	adr_tpr		=	tkodgetw16();	/* Procedure Table Sector	*/
	lng_tpr		=	tkodgetw16();	/* Procedure Table Length	*/
	adr_npr		=	tkodgetw16();	/* Procedure Names Sector	*/
	l_max_vls	=	tkodgetw16();	/* Maximum Local Variable Alloc	*/
	fdex += ( 4 * WORDSIZE );			/* Skip the Next 4 Words	*/

	/* Required Procedure LDS preallocation zone (in bytes) */
	/* ---------------------------------------------------- */
	diezlds		=	tkodgetw16(); 
	if ( diezlds == MOINS_UN )
		diezlds = ExLdsMax;

	/* Register Count : Static = 64 */
	/* ---------------------------- */
	diezreg		=	ExRegMax;

	/* Required file table Size (in files) */
	/* ----------------------------------- */
	diezfic		=	tkodgetw16(); 
	if ( diezfic == MOINS_UN )
		diezfic = ExFicMax;

	/* Required temporary workspace (in bytes) */
	/* --------------------------------------- */
	dieztmp		=	tkodgetw16(); 
#ifdef	VERSION666
	if ( dieztmp == MOINS_UN )
		dieztmp = (ExTmpMax*2);
	else	dieztmp = (dieztmp*2);
#else
	if ( dieztmp == MOINS_UN )
		dieztmp = ExTmpMax;
#endif

	/* Required Stack Size (in levels) */
	/* ------------------------------- */
	diezstk		=	tkodgetw16(); 
	if ( diezstk == MOINS_UN )
		diezstk = ExStkMax;

	/* Restore original FDEX (in case of CHAIN errors) */
	/* ----------------------------------------------- */
	fdex = tfdex;

	return( GOODRESULT );
}

#ifdef	VERSION666
EXAWORD TcodeVersion32Header(BPTR aptr)
{
	BPTR	tfdex;		/* Temporary Storage for FDEX	*/
	BPTR	lptr;
	BYTE	c;
	EXAWORD	i;
	EXAWORD	t;		/* General Counter Variable	*/
	EXAWORD	dcrypt;		/* Tcode header Decryption ID	*/

	/* Save and re-initialise FDEX */
	/* --------------------------- */
	tfdex = fdex;	fdex  = aptr;

#ifdef	ABAL14

	/* Check for Dedicated Executeur */
	/* ----------------------------- */
	if ( CryptCode != 0 )

		/* Dedicated Executeur T-Code Needs DeCrypted */
		/* ------------------------------------------ */
		abal_crypt(CryptCode,(BPTR) fdex , 256 ,DECODE);

#endif

	/* Collect Decryption Code */
	/* ----------------------- */
	dcrypt 		=	TcodeWord16( (fdex + ((21 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 62 */ ) );
	encryptiontime  =	TcodeWord32( (fdex + OFFSET_TIMESTAMP) );


#ifdef	ABALPS

	/* Adresse Table F.U.	*/
	/* ------------------	*/
	adr_usr		=	TcodeWord32( (fdex + (24 * WORDSIZE) + (2*BYTESIZE)  + TCPREFIX /* 68 */ ) );
	lng_usr		=	TcodeWord32( (fdex + (25 * WORDSIZE) + (2*BYTESIZE)  + TCPREFIX /* 70 */ ) );

	if (adr_usr == MOINS_UN) { adr_usr = 0; }


#endif

	/* --------------------------------------------------- */
	/* NOTE : Offset 72 is used for UserLibrary Relocation */
	/* --------------------------------------------------- */

#ifdef	ABAL14
#ifdef	PROLOGUE3
	/* Taille minimum des allocation memoire */
	/* ------------------------------------- */
	diezmin		= 	TcodeWord32( (fdex + (27 * WORDSIZE) +(2*BYTESIZE) + TCPREFIX /*74*/) );

	if (( diezmin == MOINS_UN ) || ( diezmin == 0 ))
		diezmin = 16;
#else
	/* Not Amenesik / Sologic 3 */
	/* -------------- */
	diezmin = 16;
#endif
	/* Collect possible Global Data Image */
	/* ---------------------------------- */
	DataImageSector = TcodeWord32( (fdex + (28 * WORDSIZE) +(2*BYTESIZE) + TCPREFIX  /*76*/) );
	DataImageLength = TcodeWord32( (fdex + (29 * WORDSIZE) +(2*BYTESIZE) + TCPREFIX  /*78*/) ); 

#endif
#ifdef	ABAL21
	/* Collect Extended Memory Options */
	/* ------------------------------- */
	DiezePageSize   = TcodeWord32( (fdex + (30 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  /*80*/) );
	DiezeSwapSize   = TcodeWord32( (fdex + (31 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  /*82*/) );
	DiezeEtendu     = TcodeWord32( (fdex + (33 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  /*86*/) );

	if ( DiezeEtendu == MOINS_UN )
		DiezeEtendu = 0;

	ExportTableSector =TcodeWord32( (fdex + (35 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  ) );
	ExportTableLength =TcodeWord32( (fdex + (36 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  ) );

	MaxIpcSem       = TcodeWord32( (fdex + (49 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  /* 118 = 0x0076 */) );

	if (( MaxIpcSem < 16 ) || ( MaxIpcSem == MOINS_UN ))
		MaxIpcSem = _MAX_SEMAPHORES;

#endif	/* ABAL21 */

	/* Decryptage des informations essentielles */
	/* ---------------------------------------- */
	if (( dcrypt != 0 ) && ( dcrypt != MOINS_UN ))
		abal_crypt(dcrypt,(BPTR) (fdex + TCPREFIX),(22 * WORDSIZE) /*44*/,DECODE);

	trad_ver 	= 	tkodgetc();	/* Tcode Version		*/
	trad_ind 	= 	tkodgetc();	/* Tcode Indice			*/
	trad_typ 	= 	tkodgetc();	/* Translator Type		*/

	/* Collect Program 'Name' */
	/* ---------------------- */
	for (t=0 ; t < 15 ; (trad_nom[t++]=tkodgetc()));

	trad_opt 	= 	tkodgetc();	/* Translator Options		*/
	trad_perm 	= 	tkodgetc();	/* Translator permissions	*/
#ifdef	DISSASSEMBLEUR
	trad_perm	=	0;
#endif
	adr_arg 	=	tkodgetw32();	/* ARG Variable identifier	*/
	adr_tcg 	= 	tkodgetw32();	/* Sector Constant Table	*/
	lng_tcg		=	tkodgetw32();	/* Constant Table Lengt		*/
	adr_tvg		=	tkodgetw32();	/* Sector GDT			*/
	lng_tvg		=	tkodgetw32();	/* Length GDT			*/
#ifdef	ABAL21
	meg_tfu		= 	tkodgetw32();
#else
	fdex += WORDSIZE;				/* Nb blocs 1Mo  Mem Etd 	*/
#endif
	adr_tfu		=	tkodgetw32();	/* Nb Paragraphs MEM ETD 	*/
	adr_tsg		=	tkodgetw32();	/* Segment Table Sector 	*/
	lng_tsg		=	tkodgetw32();	/* Segment Table Length		*/
	adr_tpr		=	tkodgetw32();	/* Procedure Table Sector	*/
	lng_tpr		=	tkodgetw32();	/* Procedure Table Length	*/
	adr_npr		=	tkodgetw32();	/* Procedure Names Sector	*/
	l_max_vls	=	tkodgetw32();	/* Maximum Local Variable Alloc	*/
	fdex += ( 4 * WORDSIZE );			/* Skip the Next 4 Words	*/

	/* Required Procedure LDS preallocation zone (in bytes) */
	/* ---------------------------------------------------- */
	diezlds		=	tkodgetw32(); 
	if ( diezlds == MOINS_UN )
		diezlds = ExLdsMax;

	/* Register Count : Static = 64 */
	/* ---------------------------- */
	diezreg		=	ExRegMax;

	/* Required file table Size (in files) */
	/* ----------------------------------- */
	diezfic		=	tkodgetw32(); 
	if ( diezfic == MOINS_UN )
		diezfic = ExFicMax;

	/* Required temporary workspace (in bytes) */
	/* --------------------------------------- */
	dieztmp		=	tkodgetw32(); 
#ifdef	VERSION666
	if ( dieztmp == MOINS_UN )
		dieztmp = (ExTmpMax*2);
	else	dieztmp = (dieztmp*2);
#else
	if ( dieztmp == MOINS_UN )
		dieztmp = ExTmpMax;
#endif
	/* Required Stack Size (in levels) */
	/* ------------------------------- */
	diezstk		=	tkodgetw32(); 
	if ( diezstk == MOINS_UN )
		diezstk = ExStkMax;

	/* Restore original FDEX (in case of CHAIN errors) */
	/* ----------------------------------------------- */
	fdex = tfdex;

	return( GOODRESULT );
}

#ifdef	ABAL64
EXAWORD TcodeVersion64Header(BPTR aptr)
{
	BPTR	tfdex;		/* Temporary Storage for FDEX	*/
	BPTR	lptr;
	BYTE	c;
	EXAWORD	i;
	EXAWORD	t;		/* General Counter Variable	*/
	EXAWORD	dcrypt;		/* Tcode header Decryption ID	*/

	/* Save and re-initialise FDEX */
	/* --------------------------- */
	tfdex = fdex;	fdex  = aptr;

#ifdef	ABAL14

	/* Check for Dedicated Executeur */
	/* ----------------------------- */
	if ( CryptCode != 0 )

		/* Dedicated Executeur T-Code Needs DeCrypted */
		/* ------------------------------------------ */
		abal_crypt(CryptCode,(BPTR) fdex , 256 ,DECODE);

#endif

	/* Collect Decryption Code */
	/* ----------------------- */
	dcrypt 		=	TcodeWord16( (fdex + ((21 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 62 */ ) );
	encryptiontime  =	TcodeWord64( (fdex + OFFSET_TIMESTAMP) );

#ifdef	ABALPS

	/* Adresse Table F.U.	*/
	/* ------------------	*/
	adr_usr		=	TcodeWord64( (fdex + (24 * WORDSIZE) + (2*BYTESIZE)  + TCPREFIX /* 68 */ ) );
	lng_usr		=	TcodeWord64( (fdex + (25 * WORDSIZE) + (2*BYTESIZE)  + TCPREFIX /* 70 */ ) );

	if (adr_usr == MOINS_UN) { adr_usr = 0; }


#endif

	/* --------------------------------------------------- */
	/* NOTE : Offset 72 is used for UserLibrary Relocation */
	/* --------------------------------------------------- */

#ifdef	ABAL14
#ifdef	PROLOGUE3
	/* Taille minimum des allocation memoire */
	/* ------------------------------------- */
	diezmin		= 	TcodeWord64( (fdex + (27 * WORDSIZE) +(2*BYTESIZE) + TCPREFIX /*74*/) );

	if (( diezmin == MOINS_UN ) || ( diezmin == 0 ))
		diezmin = 16;
#else
	/* Not Amenesik / Sologic 3 */
	/* -------------- */
	diezmin = 16;
#endif
	/* Collect possible Global Data Image */
	/* ---------------------------------- */
	DataImageSector = TcodeWord64( (fdex + (28 * WORDSIZE) +(2*BYTESIZE) + TCPREFIX  /*76*/) );
	DataImageLength = TcodeWord64( (fdex + (29 * WORDSIZE) +(2*BYTESIZE) + TCPREFIX  /*78*/) ); 

#endif
#ifdef	ABAL21
	/* Collect Extended Memory Options */
	/* ------------------------------- */
	DiezePageSize   = TcodeWord64( (fdex + (30 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  /*80*/) );
	DiezeSwapSize   = TcodeWord64( (fdex + (31 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  /*82*/) );
	DiezeEtendu     = TcodeWord64( (fdex + (33 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  /*86*/) );

	if ( DiezeEtendu == MOINS_UN )
		DiezeEtendu = 0;

	ExportTableSector =TcodeWord64( (fdex + (35 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  ) );
	ExportTableLength =TcodeWord64( (fdex + (36 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  ) );

	MaxIpcSem       = TcodeWord64( (fdex + (49 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX  /* 118 = 0x0076 */) );

	if (( MaxIpcSem < 16 ) || ( MaxIpcSem == MOINS_UN ))
		MaxIpcSem = _MAX_SEMAPHORES;

#endif	/* ABAL21 */

	/* Decryptage des informations essentielles */
	/* ---------------------------------------- */
	if (( dcrypt != 0 ) && ( dcrypt != MOINS_UN ))
		abal_crypt(dcrypt,(BPTR) (fdex + TCPREFIX),(22 * WORDSIZE) /*44*/,DECODE);

	trad_ver 	= 	tkodgetc();	/* Tcode Version		*/
	trad_ind 	= 	tkodgetc();	/* Tcode Indice			*/
	trad_typ 	= 	tkodgetc();	/* Translator Type		*/

	/* Collect Program 'Name' */
	/* ---------------------- */
	for (t=0 ; t < 15 ; (trad_nom[t++]=tkodgetc()));

	trad_opt 	= 	tkodgetc();	/* Translator Options		*/
	trad_perm 	= 	tkodgetc();	/* Translator permissions	*/
#ifdef	DISSASSEMBLEUR
	trad_perm	=	0;
#endif
	adr_arg 	=	tkodgetw64();	/* ARG Variable identifier	*/
	adr_tcg 	= 	tkodgetw64();	/* Sector Constant Table	*/
	lng_tcg		=	tkodgetw64();	/* Constant Table Lengt		*/
	adr_tvg		=	tkodgetw64();	/* Sector GDT			*/
	lng_tvg		=	tkodgetw64();	/* Length GDT			*/
#ifdef	ABAL21
	meg_tfu		= 	tkodgetw64();
#else
	fdex += WORDSIZE;				/* Nb blocs 1Mo  Mem Etd 	*/
#endif
	adr_tfu		=	tkodgetw64();	/* Nb Paragraphs MEM ETD 	*/
	adr_tsg		=	tkodgetw64();	/* Segment Table Sector 	*/
	lng_tsg		=	tkodgetw64();	/* Segment Table Length		*/
	adr_tpr		=	tkodgetw64();	/* Procedure Table Sector	*/
	lng_tpr		=	tkodgetw64();	/* Procedure Table Length	*/
	adr_npr		=	tkodgetw64();	/* Procedure Names Sector	*/
	l_max_vls	=	tkodgetw64();	/* Maximum Local Variable Alloc	*/
	fdex += ( 4 * WORDSIZE );			/* Skip the Next 4 Words	*/

	/* Required Procedure LDS preallocation zone (in bytes) */
	/* ---------------------------------------------------- */
	diezlds		=	tkodgetw64(); 
	if ( diezlds == MOINS_UN )
		diezlds = ExLdsMax;

	/* Register Count : Static = 64 */
	/* ---------------------------- */
	diezreg		=	ExRegMax;

	/* Required file table Size (in files) */
	/* ----------------------------------- */
	diezfic		=	tkodgetw64(); 
	if ( diezfic == MOINS_UN )
		diezfic = ExFicMax;

	/* Required temporary workspace (in bytes) */
	/* --------------------------------------- */
	dieztmp		=	tkodgetw64(); 
#ifdef	VERSION666
	if ( dieztmp == MOINS_UN )
		dieztmp = (ExTmpMax*4);
	else	dieztmp = (dieztmp*4);
#else
	if ( dieztmp == MOINS_UN )
		dieztmp = ExTmpMax;
#endif
	/* Required Stack Size (in levels) */
	/* ------------------------------- */
	diezstk		=	tkodgetw64(); 
	if ( diezstk == MOINS_UN )
		diezstk = ExStkMax;

	/* Restore original FDEX (in case of CHAIN errors) */
	/* ----------------------------------------------- */
	fdex = tfdex;

	return( GOODRESULT );
}

EXAWORD	TcodeVersion4Header(BPTR aptr)
{
	WORDSIZE = 8; 
	PTRSIZE  = 9;
	ISLOCAL  = ISLOCAL4;
	TOGLOBAL = TOGLOBAL4;
	MOINS_UN  = MOINS_UN64;

	return( TcodeVersion64Header(aptr) );
}
#endif

EXAWORD	TcodeVersion3Header(BPTR aptr)
{
	WORDSIZE = 4; 
	PTRSIZE  = 5;
	ISLOCAL  = ISLOCAL4;
	TOGLOBAL = TOGLOBAL4;
	MOINS_UN  = MOINS_UN32;

	return( TcodeVersion32Header(aptr) );
}

#endif

/*
 *	T C O D E H E A D E R ( argc , tcodefilehandle )
 *	-------------------------------------
 *	Performs the loading and analysis of the TCODE header BLOCK
 *	Returns SOFTERROR if error occurs, otherwise returns 1
 */

#ifdef	DEBUGGER
#ifdef	VERSION666
EXAWORD	IDB_ASM_FLAG=0;
void	activate_assembler_list(EXAWORD v) { IDB_ASM_FLAG |= v;	return;	}
void	inhibit_assembler_list(EXAWORD v) { IDB_ASM_FLAG &= ~v;	return;	}
EXAWORD	is_idb_active() { return( IDB_ASM_FLAG ); }
#else
#ifdef MODEL_DBGT
EXAWORD	IDB_ASM_FLAG;
#endif
#endif
#endif

EXAWORD	TcodeHeader( argc ,tcodefilehandle )
EXAWORD		argc;			/* Possible ARG Flag		*/
EX_FILE_HANDLE	tcodefilehandle;	/* TCODE file handle		*/
{
	EXAWORD	t;

/*	Read in the Program header block (Sector 0)			*/
/*	-------------------------------------------			*/
#ifdef	VMS_OPTIMISED
if ((lptr = load_header(nlog, askbuf)) != (BPTR) 0) {

#else

#ifdef	ABAL_CRITERIA

   if ((t = SectRead( tcodefilehandle, (BPTR) askbuf, ASKBUFMAX, 0 )) != MOINS_UN )  {

#else
   (VOID) lseek(tcodefilehandle,0L,SEEK_SET);	simcbd = 0x0060;

   if (read((USINT) tcodefilehandle,(BPTR) askbuf, ASKBUFMAX) == ASKBUFMAX) {

#endif
#endif

	switch (askbuf[0]) {
		case	'1'	:	/* ABAL Version 1 */
		case	'2'	:	/* ABAL Version 2 */
			if ( TcodeVersion2Header(askbuf) == SOFTERROR )
				return( SOFTERROR );
			else	break;
#ifdef	VERSION666
		case	'3'	:	/* ABAL Version 3 */
			if ( TcodeVersion3Header(askbuf) == SOFTERROR )
				return( SOFTERROR );
			else	break;
#endif
#ifdef	ABAL64
		case	'4'	:	/* ABAL Version Open Abal Version '4' */
			if ( TcodeVersion4Header(askbuf) == SOFTERROR )
				return( SOFTERROR );
			else	break;
#endif
		default		:
			err_val = ABAL_ERRSEGM;
			return(SOFTERROR);
		}

	}

/* Tcode READ error detection and reporting */
/* ---------------------------------------- */
else 	{
	err_val = errno; 
	return(SOFTERROR); 
	}	

#ifdef DEBUGGER
if ( version_verification( trad_ver, trad_ind, trad_typ, 0 /* ABAL_Version */ ) == SOFTERROR )
#else
if ( version_verification( trad_ver, trad_ind, trad_typ, 0 ) == SOFTERROR )
#endif
	return( SOFTERROR );

/*	Test for Correct Source translation	*/
/*	-----------------------------------	*/
if ( trad_perm != 0 ) {
	err_val = EXER_BINAIRE;
	return(SOFTERROR); 
	}

#ifdef DEBUGGER
/*	Test for Option DEBUG	required	*/
/*	--------------------------------	*/
if (((EXAWORD) trad_opt & EXOPT_DEBUG ) == 0 ) { 
#ifdef	VERSION666
	activate_assembler_list(1);
#else
#ifndef MODEL_DBGT
	err_val = 56;
	return(SOFTERROR); 
#else
	IDB_ASM_FLAG = 1;
#endif
#endif
	}	
#ifdef MODEL_DBGT
else	IDB_ASM_FLAG = 0;
#endif

#endif

/*	Check for Arguament Requirement		*/
/*	-------------------------------		*/
if (( argc > 2 ) && (adr_arg == 0)) {
	err_val = EXER_SYNTAX;
	return(SOFTERROR); 
	}

/*	Tcode Header Loaded and Initialised	*/
/*	-----------------------------------	*/
return( GOODRESULT );

}

/*
 *	T K O D G O ( argc , argv )
 *	---------------------------
 */

EXAWORD	tkodgo(	EXAWORD	argc,	BPTR	argp)
{
Phaseur  = 0;	/* Establish Current Init Phase Flag  	*/
LastErreur = 0;	/* Startup Error Track Variable		*/
timersem = 0;	/* Always reset timer and Event Flags 	*/

/*	Read and Control Tcode Header Block	*/
/*	-----------------------------------	*/
#ifdef WIN32
if ( chain == 0 )
#else
if (( chain == 0 ) && ( loadgo == 0 ))
#endif
	if ( TcodeHeader(argc,TcodeFileHandle) == SOFTERROR ) 
		return(SOFTERROR);

#ifdef	PROLOGUE2
	RAM_TYPE = 0x50C3;	/* Attempt Rampage Allocations		*/
#endif
#ifdef	PROLOGUE3
	RAM_TYPE = 0x5083;	/* Normal Protected Mode Allocations	*/
#endif

/*	Perform then test for Correct Initialisation	*/
/*	--------------------------------------------	*/

if (InitialiseTcodeProgram() == SOFTERROR) 
	return(SOFTERROR);

/*	Ensure all CICO goes to the Screen From Now On	*/
/*	----------------------------------------------  */
prndest = 1; prnfid = 0;

/*	Test for Arguament reception Variable	*/
/*	-------------------------------------	*/
if ( adr_arg != 0 ) {

	/*	Test for Command line arguament	*/
	/*	-------------------------------	*/
	if ( argc > 2 )
		/*	Transfer Arguament	*/
		/*	------------------	*/
		(VOID) arginit(adr_arg,argp);

	/*	Else dummy Arg = Carriage Ret	*/
	/*	-----------------------------	*/
	else 	(VOID) argdefo(adr_arg);

	}

#ifdef	VMS
	if ( VmsBatchFlag )
		return( 1 );
#endif

/*	Test for Option /C Clear screen		*/
/*	-------------------------------		*/
#ifdef	WIN1632
if ( ((EXAWORD) trad_opt & EXOPT_CLEAR ) != 0 ) {
	x_clear();
	}
else	{
	InitPop();
	}
InitPop2();

#else /* WIN1632 */

if ( ((EXAWORD) trad_opt & EXOPT_CLEAR ) != 0 ) 
#ifdef RT_AIX
   {
	x_clear();
	x_bflush();
   }
#else
	x_clear();
#endif	/* RT_AIX */
#endif /* WIN1632 */


/*	Test for Option /F Flush Keyboard	*/
/*	---------------------------------	*/
if ( ((EXAWORD) trad_opt & EXOPT_AFLUSH) != 0 )
	while ( opb() ) 
		x_getch(); 

/* 	Return GoodResult	*/
/*	-----------------	*/
return( GOODRESULT );
}

#ifndef	PROLOGUE

/*
 *	P R N C L E A R ( )
 *	-------------------
 *	Liberation de l'imprimante standard (pour UNIX / VMS / DOS)
 *
 */

VOID	prnclear()
{
#ifndef	DOS
	prndest = 2; prnfid = 0; 
	x_putch(0x001A);
#endif
	prndest = 1;
	return;
}

#endif


VOID	liberate_virtual_machine()
{
	diezfile = diezfic;
	prndest  = 1;
	(VOID) exlbsm();	
	prndest  = 1;
	return;
}

EX_FILE_HANDLE	open_tcode_file( fptr )
BPTR	fptr;
{
	EX_FILE_HANDLE	lnlog;

	/* Attempt to Open new tcode file */
	/* ------------------------------ */
	if ((lnlog = OpenTcodeFile((BPTR) fptr)) == EX_UNUSED_HANDLE) {

		if ( errno != 44 ) 
			traitfilerror(-1,errno);

		err_val = errno;   

#ifdef	COEXA
		/* Liberate ACCESS entry if Required */
		/* --------------------------------- */
		(VOID) liberlox((BPTR) fptr );
#endif
		return( EX_UNUSED_HANDLE );

		}
	else	return( lnlog );
}

/*
 *	EX STOP	
 *	-------
 *	Performs memory liberation and CHAIN management.
 *	Returns 1 if chain is active and initialisation is good, else
 *	returns 0 for an error which may be caught by a local error trap
 *	or returns MOINS_UN in all other conditions.
 */

EXAWORD	AllowExaStop=1;	/* Allow stop */

EXAWORD	get_stop_event()	
{	return(AllowExaStop);		}

VOID	set_stop_event( v )
EXAWORD	v;
{	AllowExaStop = v; return;	}

EXAWORD	exstop()
{
	MI_TRACE_DCL_TFN("exstop");

	EXAWORD	x,lerr,argc;
	EX_FILE_HANDLE lnlog;
	BPTR	fptr;
	BPTR	largptr;
	EXAWORD	oldetd;
	EXAWORD	holdtrap;
#ifdef	VERSION_XX
	EXAWORD	holdislocal=ISLOCAL;
	EXAWORD	holdtoglobal=TOGLOBAL;
	EXAWORD	newislocal=ISLOCAL;
	EXAWORD	newtoglobal=TOGLOBAL;
#ifdef	VERSION666
	EXAWORD	holdwordsize=WORDSIZE;
	EXAWORD	newwordsize=WORDSIZE;
#endif
#endif
#ifdef	DEBUGGER
	EXAWORD	ProcCtrl;
#ifdef UNIX
	EXAWORD	HoldStepCtrl;
#endif
#endif

#ifdef	ABAL32A
	if (!( AllowExaStop & 1 )) {
		err_val = 58;
		return(SOFTERROR);
		}
#endif

#ifdef	DEBUGGER
	ProcCtrl   = adr_npr;
	StopStatus = 1;
#endif

#ifdef	ABAL21
	ensure_parent();
#endif

	/* Ensure T-Code file is Open */
	/* -------------------------- */
	(VOID) VerifTcode();

#ifdef	ABAL21
	check_for_error_pop();
#endif

	/* Ensure Screen Device Selected */
	/* ----------------------------- */
	prndest = 1;

	(VOID) Semaphoff(0);

	prndest = 1;	


#ifdef	VMS
	if (!( VmsBatchFlag ))  {
#endif

	/*	Check For BAL Compatibility Flag	*/
	/*	--------------------------------	*/
	if ( ((EXAWORD) trad_opt & EXOPT_BFLUSH) == 0 ) {

		if ( getenv("BALFLUSH") ) 
			/* Avalez le premier caractere dans Tampon Clavier */
			/* ----------------------------------------------- */
			if ( opb() )	
				x_getch();

		}

	/*	Test for Option /F Flush Keyboard	*/
	/*	---------------------------------	*/
	if ( ((EXAWORD) trad_opt & EXOPT_CFLUSH) != 0 )

		/* Perform KeyBoard Flush operation */
		/* -------------------------------- */
		while ( opb() ) 
			x_getch();

#ifdef	VMS
	}
#endif

	/*	Test for Chain == 0 Indicates Normal STOP and EXIT	*/
	/* 	--------------------------------------------------	*/
	if ( chain == 0 ) {

		/*	Fermeture de l'imprimante implicite !	*/
		/* 	-------------------------------------	*/
		holdtrap = sicico;
		sicico |= ONSEM_TRP;
		err_val = 0; prndest = 2; (VOID) prnclear(); prndest = 1;
		err_val = 0;
		sicico = holdtrap;

		return(SOFTERROR);

		}

	/*	Test for Illegal Chain File Handle	*/
	/* 	----------------------------------	*/
	if ( chain >= diezfic) {
		err_val = ABAL_OPNOTPOSS;
		return(SOFTERROR);  
		}

	/* Collect filename and Test for Existance and Shared Access */
	/* --------------------------------------------------------- */
	fptr = (*(AssignTable + chain)).direcp;

#ifdef	VMS_OPTIMISED
		HoldSection[0] = MappedSection[0];
		HoldSection[1] = MappedSection[1];

		if ( UseVmsSection == 2 )
			if ( vms$delsection( nlog ) != 0 )
				return( SOFTERROR );
#endif

	if ((lnlog = open_tcode_file((BPTR) fptr )) == EX_UNUSED_HANDLE ) {
#ifdef	VMS_OPTIMISED
		MappedSection[0] = HoldSection[0];
		MappedSection[1] = HoldSection[1];
#endif

#ifdef	VERSION_XX
		ISLOCAL=holdislocal;
		TOGLOBAL=holdtoglobal;
#ifdef	VERSION666
		WORDSIZE = holdwordsize;
	if ((PTRSIZE = (WORDSIZE+1)) < 5) 
		PTRSIZE = 5;;
#endif
#endif
		return( SOFTERROR );
		}

	/* Save current File Table Size */
	/* ---------------------------- */
	diezfile = diezfic; oldetd = adr_tfu;

	/*	Read and Check T-Code header Conformity	*/
	/*	---------------------------------------	*/
	if ((*(AssignTable + chain)).aslen == 0 ) 
		argc = 1; 
	else	argc = 3;

	if ( TcodeHeader(argc,lnlog) == 0 ) {
		lerr = err_val;
		lnlog = CloseTcodeFile( lnlog );

#ifdef	VMS_OPTIMISED
		MappedSection[0] = HoldSection[0];
		MappedSection[1] = HoldSection[1];
#endif

#ifdef	COEXA
		/* Liberate ACCESS entry if Required */
		/* --------------------------------- */
		(VOID) liberlox((BPTR) fptr );
#endif

		/* Force Reload of Previous T-Code Header */
		/* -------------------------------------- */
		(VOID) TcodeHeader(1,TcodeFileHandle);
		err_val = lerr;
#ifdef	VERSION_XX
		ISLOCAL=holdislocal;
		TOGLOBAL=holdtoglobal;
#ifdef	VERSION666
		WORDSIZE = holdwordsize;
	if ((PTRSIZE = (WORDSIZE+1)) < 5) 
		PTRSIZE = 5;
#endif
#endif
		return(SOFTERROR);
		}

/**
 **>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 ** This is the point of no return for The Chainage operation 
 **
 **	-------------		-----------------
 ** 	W A R N I N G		A T T E N T I O N
 **	-------------		-----------------
 **
 ** ALL ERRORS ENCOUNTERED AFTER THIS POINT CANNOT BE CAUGHT
 ** BY AN ON ERROR GOTO INSTRUCTION SINCE THE TCODE WILL BE
 ** IN AN UNRECOVERABLE PARTIAL STATE. 
 **>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 **/
#ifdef	VERSION_XX
	newislocal 	= ISLOCAL;
	newtoglobal	= TOGLOBAL;
#ifdef	VERSION666
	newwordsize	= WORDSIZE;
#endif
#endif

/* #FC+BG+IJM 23/12/02
	On dépile les procédures pour éviter de changer le TCodeFileHandle.
	Ceci est nécessaire lorsqu'un Chain est effectué dans une procédure d'Overlay
	(exemple: zchain en mode zat.at)
*/
	exit_procedures();

#ifdef	VERSION_XX
	ISLOCAL  = newislocal;
	TOGLOBAL = newtoglobal;
#ifdef	VERSION666
	WORDSIZE = newwordsize;
#endif
#endif

#ifdef ABALME
	/* Liberate Allocated Extended Memory Now */
	/* -------------------------------------- */
	if ( oldetd != 0    )
		(VOID) liberate_extended_memory();
		
#endif

	/*	Fermeture de l'imprimante implicite !	*/
	/* 	-------------------------------------	*/
	(VOID) prnclear();

	/*	Implimantation of new tcode file	*/
	/*	--------------------------------	*/

	TcodeFileHandle = lnlog; x = 0;

	while ( x < FNMAX ) {
		if ((inbuf[x] = *(fptr++)) == FILETERM)
			break;
		else	x++;
		}

	/*	Initialisation of New T-Code		*/
	/*	----------------------------		*/

	largptr = (BPTR) 0;

	/* #BG 22/07/16 Trace */
	MI_TRACE((CI_TRA_F_INFO_HIGH, ID_KERNEL, TFN, "CHAIN: pid=%u, chain=%u, progname=%s", getpid(), chain, AssignTable[chain].direcp));
	if (IsExaSysLog() & SYSLOG_LOAD) {
		sprintf(SysLogBuffer, "CHAIN: chain=%u, progname=%s", chain, AssignTable[chain].direcp);
		ExaSysLog(EXA_SYSLOG_INFO, SysLogBuffer);
	}

	if ((*(AssignTable + chain)).aslen == 0 ) 
		x = 1;
	else {
		if ((largptr = (BPTR) allocate( (*(AssignTable + chain)).aslen + 1 )) != (BPTR) 0) {
			memcpy(largptr,(*(AssignTable + chain)).asptr,(USINT) (*(AssignTable + chain)).aslen );
			*(largptr + (*(AssignTable + chain)).aslen ) = (EXABYTE) 0;
			}
		x = 3 ; 
		}

#ifdef	VMS_OPTIMISED
	(void) vms$killsection( HoldSection );
#endif

	/*	Restart the T-Code 	*/
	/*	------------------	*/
	x = tkodgo( x , largptr );

	/* 	Check for and Liberate ARG Pointer 	*/
	/*	---------------------------------- 	*/
	if ( largptr != (BPTR) 0 ) 
		liberate( largptr );

	/*	Check for Good Restart Status 		*/
	/*	-----------------------------		*/
	if ( x == 1 ) { 

#ifdef 	DEBUGGER
		StopStatus = 0;

		/* Restart the IDB Control Structures */
		/* ---------------------------------- */
#ifdef WIN32
		// FCH+BGI 24092004 
		// On initialise les nouvelles infos de debug
		idb_startup();
#else
		HoldStepCtrl = db_step_ctrl;
		(VOID) idb_restart(ProcCtrl);
		db_step_ctrl = (HoldStepCtrl & 3);
#endif
#endif

		/* Return GoodResult */
		/* ----------------- */
		return( GOODRESULT ); 
		}

	/*	Serious Error so Report It	*/
	/*	--------------------------	*/
	return(SOFTERROR);
}

#ifdef INTEL
#include "exprag1.h"
#endif

	/* ------ */
#endif	/* _EXI_C */
	/* ------ */

