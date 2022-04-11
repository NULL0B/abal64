/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXI.C  					*/
/*		Version	:	1.4c / 2.1d				*/
/*		Date 	:	13/05/1996				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXI_C
#define	_EXI_C

				/* ------------------------------------ */
#include "exinit.h"		/* General initialisations header	*/
				/* ------------------------------------ */

#ifdef INTEL
#include "exprag0.h"		/* Microsoft stack checking pragma	*/
#endif

#ifdef	PROLOGUE
extern	EXAWORD	RAM_TYPE;	/* Malloc Option Function Code		*/
#endif
extern	BPTR	LDS_base;	/* Procedure local Variables base	*/
extern	EXAWORD	LDS_dex;	/* Procedure local Variable protect	*/



#include "exptr.h"
				/* ------------------------------------ */
#include "exiniptr.c"		/* Pointer variable initialisation	*/
#include "exinidcl.c"		/* Data memory initialisation		*/
				/* ------------------------------------ */

/*		-----------------------------------			*/
/*		I N I T _ D A T A ( ID, LNG, DESC )			*/
/*		-----------------------------------			*/
#ifdef RT_AIX
#ifndef BPTR
#define BPTR unsigned char *
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
	if (( DataImageSector != 0 ) && ( DataImageSector != MOINS_UN )) {
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
	BPTR	rp;
	EXAWORD	y;

/*	Ensure Tcode file is Open (might have been closed via CLOSE=0) 	*/
/*	--------------------------------------------------------------	*/
	VerifTcode();

	return( kode_lode( sec, (num * 10)) );

#ifdef	PRE_ABAL_14

/*	Calculate Offset into File 	*/
/*	--------------------------	*/
	num *= 10; y = num / BLOCK;
	if (( num % BLOCK) != 0 ) { y++; }

/*	Attempt to allocate memory to receive variable names table	*/
/*	----------------------------------------------------------	*/
	if ((rp = (BPTR ) allocate((USINT) (y * BLOCK))) != 0) { 

/*		Attempt to read names table into allocated buffer	*/
/*		-------------------------------------------------	*/
		if ( SectRead(TcodeFileHandle,rp,(EXAWORD)(y * BLOCK),sec) != MOINS_UN ) { return(rp); }

/*		Liberate buffer due to read error	*/
/*		---------------------------------	*/
		liberate( rp );
		}	

	return((BPTR ) 0);

#endif	/* PRE_ABAL_14 */

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
	x = Tcodeword( (LocalDataTable + 2) );
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
	if ((NbBlock = ( longeur / BLOCK )) > 0 ) {

		/* Attempt to load blocks */
		/* ---------------------- */
		if ( SectRead(TcodeFileHandle,memptr,(NbBlock * BLOCK),secteur) == MOINS_UN ) {

			/* Error during file read */
			/* ---------------------- */
			return( MOINS_UN );

			}
		}
	
	/* Check for and load incomplete BLOCK */
	/* ----------------------------------- */
	if ((NbReste = ( longeur % BLOCK )) > 0 ) {

		/* Attempt to load final block */
		/* --------------------------- */
		if ( SectRead(TcodeFileHandle,(BPTR) askbuf,BLOCK,(secteur+NbBlock)) == MOINS_UN ) {

			/* Error during file read */
			/* ---------------------- */
			return( MOINS_UN );

			}
		/* Transfer from Temporary Buffer to final buffer */
		/* ---------------------------------------------- */
		memcpy((BPTR) (memptr + (NbBlock * BLOCK)), (BPTR) askbuf , (USINT) NbReste );

		}
	/* Return Success */
	/* -------------- */
	return( 1 );


}

BPTR	kode_lode( secteur , longeur )
EXAWORD	secteur;
EXAWORD	longeur;
{
	BPTR	memptr;

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

	if ((mptr = (BPTR) malloc((USINT) longueur )) == (BPTR) 0)
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

y = longeur / BLOCK;
if ((longeur % BLOCK) != 0) 
	y++;
if ((memptr = (BPTR ) calloc((USINT) (y * BLOCK),(USINT) 1)) == 0) 
	return((BPTR) 0);
else 	{
	if ( SectRead(TcodeFileHandle,memptr,(y * BLOCK),secteur) != MOINS_UN )
		return(memptr);
	free( memptr );
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
	if ( AssignTable != (struct fichdt SPTR) 0 ) {

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
	VmemFid = 0;				/* Buffer  File ID   	*/
	VmemLng = 0;				/* Buffer  Length    	*/
	VmemOfs = 0;				/* Buffer  offset    	*/
	VmemDif = 0;				/* = 1;			*/
	VmemExt = 0;				/* = VmemAdj;		*/
	VmemWot = 0;				/* = adr_phy_fich;	*/
	VmemHow = 0;				/* = dleng;		*/
	IP_Hold   = (WPTR) 0;			/* Stack des Gosubs	*/
	SP_Hold   = (WPTR) 0;			/* Stack des Gosubs	*/
	Minder    = (BPTR SPTR) 0;		/* Stack des Segments	*/
	fieldex   = (BPTR) 0;			/* Virtuel file Buffer	*/
	fieldlen  = 0;				/* Length of Buffer	*/
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
	TcodeSegmentTable = (struct segmform SPTR) 0;	/* Segment table	*/
	GlobalErrorTrap = (ERRORPTR) 0;		/* Error management	*/
	TcodeProcTable = (struct procform SPTR) 0;/* Procedure table	*/
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
	&&     ( mindex  > 0 ))

		/* Destack all Procedures */
		/* ---------------------- */
		(VOID) procedure_exit(1);
	return;
}

VOID	return_segments()
{
	while ( mindex > 0 )
		rest_segm();

}


VOID	exlbsm()
{
	EXAWORD	tabdex;

#ifdef	ABAL21
	liberate_task_control(1);
#endif	

/* 	Liberate PROCEDURES : CODE,TABLES et DONNEES		*/
/* 	--------------------------------------------	 	*/
	if ( TcodeProcTable != (struct procform SPTR) 0 ) {

		exit_procedures();


		/* Liberate PROCEDURE CODE,LDT,LDS */
		/* ------------------------------- */
		LiberateProcedureTable( procmaxid );

		}

	/* Liberate SEGMENTS : CODE, TABLES et DONNEES		*/
	/* ---------------------------------------------------- */
	return_segments();

#ifdef	VMS_OPTIMISED
	if (!(UseVmsSection))
#endif
		/* Liberate Static Tables CONSTANTES et TABLE VAR GLOBALE */
		/* ------------------------------------------------------ */
		if ( GlobalConstants != (BPTR) 0 )
			 liberate(GlobalConstants);

	if ( TcodeByteStack != (BPTR) 0 ) 
		free(TcodeByteStack);

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
		free( LDS_base );

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
	free( Freg ); free( Xreg ); free( Ireg ); free( Areg );
#endif

	/* Liberate Stack Structures */
	/* ------------------------- */
	if ( IP_Hold != (WPTR) 0 ) 
		free( IP_Hold );
	if ( SP_Hold != (WPTR) 0 ) 
		free( SP_Hold );

	if ( Minder  != (BPTR SPTR) 0 ) 
		free( Minder );

	ip_next = 0; mindex = 0; 
	pushtop = 0; pushhold = 0;
	
	/* Liberate File Table entries	*/
	/* ---------------------------  */
	(VOID) fichferm();

	if ( AssignTable != (struct fichdt SPTR) 0 ) 
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
	if ((IP_Hold = (WPTR) calloc((USINT)  diezstk , (USINT) WORDSIZE)) == (WPTR) 0 ){
		chain=0;
		if ( mode )
			exlbsm();
		Phaseur = 1;
		return(SOFTERROR);
		}

/*	Allocation of PushPop Stack 	*/
/*	---------------------------	*/
	if ((SP_Hold = (WPTR) calloc((USINT)  diezstk , (USINT) WORDSIZE)) == (WPTR) 0 ){
		chain=0;
		if ( mode )
			exlbsm();
		Phaseur = 1;
		return(SOFTERROR);
		}

/*	Allocation of Pointer's Stack	*/
/*	-----------------------------	*/
	if ((Minder  = (BPTR SPTR) calloc((USINT)  diezstk , (USINT) sizeof(BPTR ) )) == (BPTR SPTR) 0) {
		chain=0;
		if ( mode )
			exlbsm();
		Phaseur = 1;
		return(SOFTERROR);
		}

/*	Allocation of Temporary WorkZone	*/
/*	--------------------------------	*/
	if ((TcodeByteStack = (BPTR ) calloc((USINT) dieztmp,(USINT) 1)) == (BPTR) 0) {
		chain=0;	
		if ( mode )
			exlbsm();
		Phaseur = 2;
		return(SOFTERROR); 
		}

#ifdef	USING_DIEZE_HEAP
/*	Allocation of Quick allocation Memory	*/
/*	-------------------------------------	*/
	if ( InitQalloc() == SOFTERROR ) {
		chain=0;
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

	if (IP_Hold != (WPTR) 0 )
		free( IP_Hold );
	if (SP_Hold != (WPTR) 0 )
		free( SP_Hold );
	if (Minder != (BPTR SPTR) 0 )
		free( Minder );
	if (TcodeByteStack != (BPTR) 0 )
		free( TcodeByteStack );
	if ( LDS_base != (BPTR) 0 ) 
		free( LDS_base );
	return( GOODRESULT );

}


/*
 *	I N I T	( )
 *	-----------
 *	Initialisation module.
 *
 */

EXAWORD init()
{
	EXAWORD x;
	BPTR	temp_base;
#ifdef	VMS_OPTIMISED
	BPTR	TempSection[2];
#endif

/*	Liberate memory if necessary		*/
/*	----------------------------		*/

if ( chain != 0 ) { 
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
if ((AssignTable = (struct fichdt SPTR) allocate((USINT) (diezfic + 1)* (USINT) sizeof( struct fichdt ) )) == (struct fichdt SPTR) 0 ) { 
	chain=0;
	exlbsm();
	Phaseur = 3;
	return(SOFTERROR);  
	}
else	memset((BPTR) AssignTable,0,(USINT) (diezfic + 1)* (USINT) sizeof( struct fichdt ));

if ( initialise_assign_allocation( (diezfic+1) , 48 ) != GOODRESULT ) {
	chain=0;
	exlbsm();
	Phaseur = 3;
	return(SOFTERROR);
	}

/*	Initialisaion of File Table Handles	*/
/*	-----------------------------------	*/
for (x = 0; x <= diezfic; x++ )
	(*(AssignTable +x)).unlog = EX_UNUSED_HANDLE;
	
/*	Establish ASSIGN=0 Informations		*/
/*	-------------------------------		*/
	x = 0; 
	while (inbuf[x] != FILETERM) 
		x++; 
	x++;

if ((temp_base = (BPTR) allocate( (USINT) (x+1))) == (BPTR) 0 ) {
	chain=0;
	exlbsm();
	Phaseur = 3;
	return(SOFTERROR);
	}
(VOID) memcpy((BPTR) temp_base, (BPTR) inbuf, (USINT) x);
*(temp_base + x) = (EXABYTE) 0;
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
/*
 *		Allocate extended memory
 *		------------------------
 */
#ifdef	ABAL21
if (( adr_tfu != 0 )
||  ( meg_tfu != 0 )) {
#else
if ( adr_tfu != 0 ) { 
#endif
	if ((err_val = (EXAWORD) allocate_extended_memory(adr_tfu)) != 0) { 
		chain=0;
		exlbsm();
		Phaseur = 4;
		return(SOFTERROR); 
		}
	}
#endif
/*		Load in Variables Table on ERREUR AB  		*/
/*		------------------------------------		*/

if (lng_tvg != 0 ) {
	if ((GlobalDataTable = (BPTR) kode_lode(adr_tvg,lng_tvg)) == (BPTR) 0) { 
		chain=0;
		exlbsm();
		Phaseur = 5;
		return(SOFTERROR); 
		}
	else 	{
		temp_base = GlobalDataTable; 
		var_glob = Tcodeword( GlobalDataTable); GlobalDataTable += WORDSIZE;
		nom_glob = Tcodeword( GlobalDataTable); GlobalDataTable += WORDSIZE;
		len_glob = Tcodeword( GlobalDataTable); GlobalDataTable += WORDSIZE;
#ifndef EXECUTEUR
		if (nom_glob != 0) { 
#ifdef	DEBUGGER
			GlobalNamesTable = (BPTR) nomlode(var_glob,nom_glob); 
#else
			GlobalNamesTable = (BPTR) 0;
#endif
			}
		else 	GlobalNamesTable = (BPTR) 0; 
#endif

/* Remarque : VAR_glob is the count of variables	
 *	      NOM_glob is the disk sector which contains
 *	      the names of the variables.
 *	      LEN_glob is the length of variable Space
 *	      actual variable value.			
 *	      BASE_VARG points to the first Descriptor
 */
		/* Are there any Global Variables ? */
		/* -------------------------------- */
		if ( len_glob > 0 ) {
			if ((GlobalDataSegment = (BPTR) init_data(var_glob,len_glob,GlobalDataTable)) == (BPTR ) 0) {
				/* Allocation or Analysis Error */
				/* ---------------------------- */
				GlobalDataTable = temp_base;
				chain=0;
				exlbsm(); 
				Phaseur = 6;
				return(SOFTERROR); 
				}
			}
		else	
			/* Ok only External or File Variables */
			/* ---------------------------------- */
			GlobalDataSegment = (BPTR) 0;
		GlobalDataTable = temp_base;
		}	
	}

#ifdef	ABALPS
#ifndef	TCODELIST
/*		Chargement des Fonctions Utilisateurs		*/
/*		-------------------------------------		*/

if (adr_usr != 0) {
	if ( chain == 0 ) {
		if ( InitFuse() == MOINS_UN ) {
			chain=0;
			exlbsm();
			Phaseur = 7;
			return(SOFTERROR);
			} 
		}
	else	{
		if ( MergeFuse() == MOINS_UN ) {
			chain=0;
			exlbsm();
			Phaseur = 7;
			return(SOFTERROR);
			}
		}
	}
#endif
#endif

/*	Destroy Chainage Condition if it Exists		*/
/*	---------------------------------------		*/

	chain = 0;

/*		Load in Constantes Table on ERREUR IG  		*/
/*		-------------------------------------		*/

if (lng_tcg != 0) {
	if ((GlobalConstants = kode_lode(adr_tcg,lng_tcg)) == (BPTR) 0) {
		exlbsm();
		Phaseur = 8;
		return(SOFTERROR);
		}
	}
else	GlobalConstants = (BPTR) 0; 
TcodeConstants = GlobalConstants;

/*		Load in Segment Table on ERREUR AB   		*/
/*		----------------------------------		*/
		
if (lng_tsg != 0 ) {
	if (segt_lode(adr_tsg,lng_tsg) == 0) {
		exlbsm();
		Phaseur = 9;
		return(SOFTERROR);
		}
	}
else  	{ 
	exlbsm();
	Phaseur = 10;
	return(SOFTERROR);
	}

/*		Load in the Procedures				*/
/*		----------------------				*/

if (adr_tpr != 0) {
	if ( load_procedure_table() == 0) {
		exlbsm();
		Phaseur = 11;
		return(SOFTERROR);
		} 
	}
else	TcodeProcTable = (struct procform SPTR) 0;

/*		Set up the Standard function pointers		*/
/*		-------------------------------------		*/
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

/*		Initialise Programme control Values 		*/
/*		-----------------------------------		*/

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
	if ( ldgo_seg(0,0) == 0 ) {	/* Seek and Load Segment 0	*/
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

BPTR	exa_crypt( pkey , sptr , slen ,mode)
EXAWORD	pkey;
BPTR	sptr;
EXAWORD	slen;
EXAWORD	mode;
{
	BPTR	rptr;
	EXABYTE	exkm[16][16];
	BINAIRE	kdex,kdey;
	EXAWORD	rotor;
	EXAWORD	cmpt;
	EXAWORD	x,y;
	EXAWORD	phase;
	rptr = sptr; cmpt = 0;
	for (x = 0; x < 16 ; x++) 
		for ( y =0; y < 16; y++ )
			exkm[x][y] = (EXABYTE) (cmpt++); 

	rotor = 1; phase = pkey & 0x0007;
	while ( slen > 0 ) {
		if ( mode == ENCODE ) { 
			kdex = ((EXAWORD) *sptr) / 16;
			kdey = ((EXAWORD) *sptr) % 16;
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
/*	printf("crypt(%d,%d,%x,%x,%u)\n",kdex,kdey,rotor,phase,slen); */
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
		if ( rotor == 0 ) 
			rotor = 1;
		*(sptr++) = exkm [ kdex ][ kdey ]; slen--;
		}
 	return(rptr);
}


#ifndef ABAL_CRITERIA
#ifdef PRL_SF
EXALONG	lseek( fid , offst , flg )
EXAWORD	fid;				/* Numero Logique du Fichier 	*/
EXALONG	offst;				/* Offset  Octets dans fichier	*/
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
		memcpy( buffer, MappedSection[0], BLOCK );
		return( buffer );
		}

	(void) lseek(nlog,0L,SEEK_SET); simcbd = 0x0060;
	if (read((USINT) nlog,(BPTR) buffer, BLOCK) == BLOCK)
		return( buffer );
	else	return((BPTR) 0);
}

#endif


EXAWORD	version_verification( trad_ver, trad_ind, trad_typ, min_ver )
EXAWORD	trad_ver;
EXAWORD	trad_ind;
EXAWORD	trad_typ;
EXAWORD	min_ver;
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
	else	{
		ISLOCAL  = ISLOCAL3;
		TOGLOBAL = TOGLOBAL3;
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

/*
 *	T C O D E H E A D E R ( argc , tcodefilehandle )
 *	-------------------------------------
 *	Performs the loading and analysis of the TCODE header BLOCK
 *	Returns SOFTERROR if error occurs, otherwise returns 1
 */
#ifdef MODEL_DBGT
EXAWORD	IDB_ASM_FLAG;
#endif

EXAWORD	TcodeHeader( argc ,tcodefilehandle )
EXAWORD		argc;			/* Possible ARG Flag		*/
EX_FILE_HANDLE	tcodefilehandle;	/* TCODE file handle		*/
{
	BPTR	tfdex;		/* Temporary Storage for FDEX	*/
	BPTR	lptr;
	EXAWORD	t;		/* General Counter Variable	*/
	EXAWORD	dcrypt;		/* Tcode header Decryption ID	*/

/*	Read in the Program header block (Sector 0)			*/
/*	-------------------------------------------			*/
#ifdef	VMS_OPTIMISED
if ((lptr = load_header(nlog, askbuf)) != (BPTR) 0) {
	tfdex = fdex; fdex = (BPTR) lptr;

#else

#ifdef	ABAL_CRITERIA

   if ((t = SectRead( tcodefilehandle, (BPTR) askbuf, BLOCK, 0 )) != MOINS_UN )  {

#else
   (VOID) lseek(tcodefilehandle,0L,SEEK_SET);	simcbd = 0x0060;

   if (read((USINT) tcodefilehandle,(BPTR) askbuf, BLOCK) == BLOCK) {

#endif
	/* Save and re-initialise FDEX */
	/* --------------------------- */
	tfdex = fdex;	fdex  = (BPTR) askbuf;
#endif

#ifdef	ABAL14

	/* Check for Dedicated Executeur */
	/* ----------------------------- */
	if ( CryptCode != 0 )

		/* Dedicated Executeur T-Code Needs DeCrypted */
		/* ------------------------------------------ */
		(VOID) exa_crypt(CryptCode,(BPTR) fdex , 256 ,DECODE);

#endif

	/* Collect Decryption Code */
	/* ----------------------- */
	dcrypt 		=	Tcodeword( (fdex + 62 ) );

#ifdef	BEFORE_011295
#ifdef	DEBUGGER
	/* Collect Debug list infos */
	/* ------------------------ */
	MapSect		=	Tcodeword( (fdex + 64 ) );
	LstSect		=	Tcodeword( (fdex + 66 ) );
#endif
#endif

#ifdef	ABALPS

	/* Adresse Table F.U.	*/
	/* ------------------	*/
	adr_usr		=	Tcodeword( (fdex + 68 ) );
	lng_usr		=	Tcodeword( (fdex + 70 ) );

	if (adr_usr == MOINS_UN) { adr_usr = 0; }


#endif

	/* --------------------------------------------------- */
	/* NOTE : Offset 72 is used for UserLibrary Relocation */
	/* --------------------------------------------------- */

#ifdef	ABAL14
#ifdef	PROLOGUE3
	/* Taille minimum des allocation memoire */
	/* ------------------------------------- */
	diezmin		= 	Tcodeword( (fdex + 74) );

	if (( diezmin == MOINS_UN ) || ( diezmin == 0 ))
		diezmin = 16;
#else
	/* Not Amenesik / Sologic 3 */
	/* -------------- */
	diezmin = 16;
#endif
	/* Collect possible Global Data Image */
	/* ---------------------------------- */
	DataImageSector = Tcodeword( (fdex + 76) );
	DataImageLength = Tcodeword( (fdex + 78) ); 

#endif
#ifdef	ABAL21
	/* Collect Extended Memory Options */
	/* ------------------------------- */
	DiezePageSize   = Tcodeword( (fdex + 80) );
	DiezeSwapSize   = Tcodeword( (fdex + 82) );
	DiezeEtendu     = Tcodeword( (fdex + 86) );

	if ( DiezeEtendu == MOINS_UN )
		DiezeEtendu = 0;

	MaxIpcSem       = Tcodeword( (fdex + 0x0076) );

	if (( MaxIpcSem < 16 ) || ( MaxIpcSem == MOINS_UN ))
		MaxIpcSem = _MAX_SEMAPHORES;

#endif	/* ABAL21 */


	/* Decryptage des informations essentielles */
	/* ---------------------------------------- */
	if (( dcrypt != 0 ) && ( dcrypt != MOINS_UN ))
		(VOID) exa_crypt(dcrypt,(BPTR) (fdex + 18),44,DECODE);

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
	adr_arg 	=	tkodgeti();	/* ARG Variable identifier	*/
	adr_tcg 	= 	tkodgeti();	/* Sector Constant Table	*/
	lng_tcg		=	tkodgeti();	/* Constant Table Lengt		*/
	adr_tvg		=	tkodgeti();	/* Sector GDT			*/
	lng_tvg		=	tkodgeti();	/* Length GDT			*/
#ifdef	ABAL21
	meg_tfu		= 	tkodgeti();
#else
	fdex += WORDSIZE;				/* Nb blocs 1Mo  Mem Etd 	*/
#endif
	adr_tfu		=	tkodgeti();	/* Nb Paragraphs MEM ETD 	*/
	adr_tsg		=	tkodgeti();	/* Segment Table Sector 	*/
	lng_tsg		=	tkodgeti();	/* Segment Table Length		*/
	adr_tpr		=	tkodgeti();	/* Procedure Table Sector	*/
	lng_tpr		=	tkodgeti();	/* Procedure Table Length	*/
	adr_npr		=	tkodgeti();	/* Procedure Names Sector	*/
	l_max_vls	=	tkodgeti();	/* Maximum Local Variable Alloc	*/
	fdex += ( 4 * WORDSIZE );			/* Skip the Next 4 Words	*/

	/* Required Procedure LDS preallocation zone (in bytes) */
	/* ---------------------------------------------------- */
	diezlds		=	tkodgeti(); 
	if ( diezlds == MOINS_UN )
		diezlds = ExLdsMax;

	/* Register Count : Static = 64 */
	/* ---------------------------- */
	diezreg		=	ExRegMax;

	/* Required file table Size (in files) */
	/* ----------------------------------- */
	diezfic		=	tkodgeti(); 
	if ( diezfic == MOINS_UN )
		diezfic = ExFicMax;

	/* Required temporary workspace (in bytes) */
	/* --------------------------------------- */
	dieztmp		=	tkodgeti(); 
	if ( dieztmp == MOINS_UN )
		dieztmp = ExTmpMax;

	/* Required Stack Size (in levels) */
	/* ------------------------------- */
	diezstk		=	tkodgeti(); 
	if ( diezstk == MOINS_UN )
		diezstk = ExStkMax;

	/* Restore original FDEX (in case of CHAIN errors) */
	/* ----------------------------------------------- */
	fdex = tfdex;
	}

/* Tcode READ error detection and reporting */
/* ---------------------------------------- */
else 	{
	err_val = errno; 
	return(SOFTERROR); 
	}	

#ifdef DEBUGGER
if ( version_verification( trad_ver, trad_ind, trad_typ, ABAL_Version ) == SOFTERROR )
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
#ifndef MODEL_DBGT
	err_val = 56;
	return(SOFTERROR); 
#else
	IDB_ASM_FLAG = 1;
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
if ( chain == 0 )
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

if (init() == SOFTERROR) 
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

EXAWORD	exstop()
{
	EXAWORD	x,lerr,argc;
	EX_FILE_HANDLE lnlog;
	BPTR	fptr;
	BPTR	largptr;
	EXAWORD	oldetd;
	EXAWORD	holdtrap;
#ifdef	VERSION_XX
	EXAWORD	holdislocal=ISLOCAL;
	EXAWORD	holdtoglobal=TOGLOBAL;
#endif
#ifdef	DEBUGGER
	EXAWORD	ProcCtrl;
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
	if ( ((EXAWORD) trad_opt & EXOPT_BFLUSH) == 0 ) 

		/* Avalez le premiere character dans Tampon Clavier */
		/* ------------------------------------------------ */
		if ( opb() )	
			x_getch();

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
if ( chain == 0      ) {

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

/* #FC+BG+IJM 23/12/02
	On d‚pile les proc‚dures pour ‚viter de changer le TCodeFileHandle.
	Ceci est n‚cessaire lorsqu'un Chain est effectu‚ dans une proc‚dure d'Overlay
	(exemple : zchain en mode zat.at)
*/
	exit_procedures();

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

if ((*(AssignTable + chain)).aslen == 0 ) 
	x = 1;
else 	{
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
	(VOID) idb_restart(ProcCtrl);
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

