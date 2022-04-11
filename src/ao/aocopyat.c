/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1994 Amenesik / Sologic s.a.			*/
/*		  -------------------------------------			*/
/*									*/
/*		File	:	COPYAT.C				*/
/*		Version :	2.1c					*/
/*		Date	:	21/11/1994				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_COPYAT_C
#define	_COPYAT_C

#ifdef ABAL21
#define ABAL14
#endif

#define	OPTIMISEUR

#include "aomain.h"		/* Type Definitions and constants	*/
#include "fnparser.h"		/* Constants for FNPARSER usage calls	*/
#include "aoblock.h"		/* Buffered block management		*/

extern	BYTE	ControlZone[256];	/* Tcode Header Block		*/
extern	EXAWORD	debug;			/* Debug Status Flag		*/
extern	BPTR	TalkPtr[];		/* GesMes Message Pointers	*/
extern	BYTE	trad_ver;
extern	EXAWORD	lnPNT;			/* Procedure Names Table Length	*/
extern	BPTR	tcPNT;			/* Procedure Names Table Base	*/
extern	BPTR	GlobalDataImage;	/* Pointer to Globla Data image */
extern	EXAWORD	keep_procedures;
extern	EXAWORD	SymbolStatus;

#ifndef	UNIX_RENAME
void	HexAdresse(EXAWORD);
#else
void	HexAdresse();
#endif

#ifndef	WORDSIZE
#define	WORDSIZE sizeof( EXAWORD )
#endif
#define USINT unsigned int

BYTE	ConstructionZone[256];	/* Filename Construction Zone	*/
BYTE	ConstructionTemp[256];	/* Temporary Filename Zone	*/

EXAWORD	OutSect;		/* Copy file sector ID		*/
EXAWORD	NextFreeSector;		/* Next free sector in Tcode	*/

BLOCKPTR	allocate_for_block()
{
	BLOCKPTR	lblk;

	if ((lblk = BlockStore) != (BLOCKPTR) 0)
		BlockStore = lblk->next;
	else if ((lblk = (BLOCKPTR) malloc( sizeof( struct block_control ) )) == (BLOCKPTR) 0) {
		printf("\n * * Memory allocation failure in : allocate_for_block * *\n");
		exit(0);
		}

	/* Reset all fields before Return */
	/* ------------------------------ */
	lblk->sector 	= 0;
	lblk->buffer	= (BPTR) 0;
	lblk->next	= (BLOCKPTR) 0;

	return( lblk );

}

void	initialise_block_control()
{
	BlockControl 	= (BLOCKPTR) 0;
	BlockStore   	= (BLOCKPTR) 0;
	NextFreeSector	= 1;
	return;
}

void	terminate_block_control()
{
	BLOCKPTR	lblk;

	while ((lblk = BlockControl) != (BLOCKPTR) 0) {
		BlockControl = lblk->next;
		if ( lblk->buffer != (BPTR) 0 )
			free( lblk->buffer );
		free( lblk );
		}

	while ((lblk = BlockStore) != (BLOCKPTR) 0) {
		BlockStore = lblk->next;
		free( lblk );
		}
	
	return;
}

void		release_block_buffer( lb, previous )
BLOCKPTR	lb;
BLOCKPTR	previous;
{
	if ( lb != (BLOCKPTR) 0 ) {
		if ( previous == (BLOCKPTR) 0)
			BlockControl   = lb->next;
		else	previous->next = lb->next;
		lb->next     = BlockStore;
		BlockStore   = lb;
		}
	return;
}

/*	ReWrite of an optimised Tcode Block	*/
/*	-----------------------------------	*/

void	WriteBlock(Handle ,Buffer , Sector , Longeur )
EXAWORD	Handle;
BPTR	Buffer;
EXAWORD	Sector;
EXAWORD	Longeur;
{
	EXAWORD	NbSect;

	if ( debug > 0 ) {
		StreamString((BPTR) " Writing block : Sector(");
		HexAdresse( Sector );
		StreamString((BPTR) ")   Length (");
		HexAdresse( Longeur );
		StreamString((BPTR) ") ");
		StreamLine();
		} 

	/* Calculate Sector Count from Byte Length */
	/* --------------------------------------- */	
	NbSect = ((Longeur / BLOCK) + (((Longeur % BLOCK) == 0) ? 0 : 1));

		lseek(Handle, (long) (((long) Sector) * BLOCK) , SEEK_SET );
		write( Handle , (BPTR) Buffer , ( NbSect * BLOCK ) );
	return;

}

EXAWORD	StoreBlock( Sector, Buffer )
EXAWORD	Sector;
BPTR	Buffer;
{
	BLOCKPTR	lb;

	if ((lb = allocate_for_block()) == (BLOCKPTR) 0)
		return( MOINS_UN );

	/* Store values in fields of Structure */
	/* ----------------------------------- */
	lb->next = BlockControl;
	BlockControl = lb;
	lb->sector   = Sector;
	lb->buffer   = Buffer;
	
	return( 0 );	

}

void	LiberateBlock( blockptr ) 
BPTR	blockptr;
{
	free( blockptr );
	return;
}


BPTR	MakeBlock( Longeur )
EXAWORD	Longeur;
{
	EXAWORD	NbSect;
	BPTR	lptr;

	/* Calculate Sector Count from Byte Length */
	/* --------------------------------------- */	
	NbSect = ((Longeur / BLOCK) + (((Longeur % BLOCK) == 0) ? 0 : 1));

	/* Allocate Space for the Block */
	/* ---------------------------- */
	if ((lptr = malloc ( (NbSect * BLOCK) )) == (BPTR) 0) {
		printf("\n * * Memory allocation failure in : MakeBlock * *\n");
		exit(0);
		}
	memset( lptr, 0x00FF, (NbSect * BLOCK) );
	return( lptr );


}
void	set_next_free_sector( sector, longueur )
EXAWORD	sector;
EXAWORD	longueur;
{
	EXAWORD	temp;

	temp = (longueur / BLOCK);
	if ( longueur % BLOCK )
		temp++;

	if (( sector + temp ) > NextFreeSector )
		NextFreeSector = ( sector + temp );

	return;

}

BPTR	locate_control_block( Sector )
EXAWORD	Sector;
{
	BPTR		rptr;
	BLOCKPTR	bptr;
	BLOCKPTR	lptr;

	/* Failure if No blocks stored */
	/* --------------------------- */
	if ((bptr = BlockControl) == (BLOCKPTR) 0)
		return((BPTR) 0);

	lptr = (BLOCKPTR) 0;

	do	{
		if ( bptr->sector == Sector ) {
			rptr = bptr->buffer;
			release_block_buffer( bptr, lptr );
			return( rptr );
			}
		lptr = bptr;
		bptr = bptr->next;
		}
	while ( bptr != (BLOCKPTR) 0 );

	return( (BPTR) 0 );

}

/*	Tcode block loader	*/
/*	------------------	*/
BPTR	LoadBlock( Handle , Sector , Longeur )
EXAWORD	Handle;
EXAWORD	Sector;
EXAWORD	Longeur;
{
	BPTR	lptr;
	EXAWORD	NbSect;

	if ( debug > 0 ) {
		StreamString((BPTR) " Loading block : Sector(");
		HexAdresse( Sector );
		StreamString((BPTR) ")   Length (");
		HexAdresse( Longeur );
		StreamString((BPTR) ") ");
		StreamLine();
		} 

	/* Attempt to Load it From Block Storage */
	/* ------------------------------------- */
	if ((lptr = locate_control_block( Sector )) != (BPTR) 0)
		return( lptr );

	/* Calculate Sector Count from Byte Length */
	/* --------------------------------------- */	
	NbSect = ((Longeur / BLOCK) + (((Longeur % BLOCK) == 0) ? 0 : 1));

	/* Allocate Space for the Block */
	/* ---------------------------- */
	if ((lptr = (BPTR) malloc ( (NbSect * BLOCK) )) != (BPTR) 0) {
		lseek(Handle, (long) (((long) Sector) * BLOCK) , SEEK_SET );
		if ( read( Handle , (BPTR) lptr , ( NbSect * BLOCK ) ) != (NbSect * BLOCK)) {
			free( (BPTR) lptr );
			}
		else	{
			set_next_free_sector( Sector, Longeur );
			return( (BPTR) lptr );
			}
		}
	else	{
		printf("\n * * Memory allocation failure in : LoadBlock * * \n");
		if ( Options.Stats )
			output_statistics();
		exit(0);
		}

}

EXAWORD	ReloadProcedureNames( handle, secteur )
EXAWORD	handle;
EXAWORD	secteur;
{
	/* Liberate Previous Table */
	/* ----------------------- */
	if ( tcPNT != (BPTR) 0 )
		free( tcPNT );

	/* Attempt to Load Longeur Block from File */
	/* --------------------------------------- */
	if ((tcPNT = (BPTR) LoadBlock( handle, secteur ,(lnPNT + BLOCK))) != (BPTR) 0) {

		/* Establish New Block Length */
		/* -------------------------- */
		lnPNT += BLOCK;

		return( 0 );

		}

	tcPNT = (BPTR) 0; lnPNT = 0;
	return( MOINS_UN );
}

void	LoadProcedureNames( handle, secteur )
EXAWORD	handle;
EXAWORD	secteur;
{
	EXAWORD	blocklen;
	EXAWORD	nombre;
	EXAWORD	offset;
	EXAWORD	argcount;

	/* Initialise Procedure Names Controllers */
	/* -------------------------------------- */
	lnPNT = 0; tcPNT = (BPTR) 0; nombre = 0; offset = 0;

	/* Ensure Procedure Names Exist in Tcode File */
	/* ------------------------------------------ */
	if ((secteur == 0) || (secteur == MOINS_UN))
		return;

	/* Attempt to Load Initial Block from File */
	/* --------------------------------------- */
	if ( ReloadProcedureNames( handle, secteur ) == MOINS_UN )
		return;

	/* Initialise Names Table Calculation */
	/* ---------------------------------- */
	lnPNT = BLOCK; nombre = tcGetw((tcPNT)); offset = 2;

	/* Repeat for Declared number of Procedures */
	/* ---------------------------------------- */
	while ( nombre ) {
	
		/* Check for Reload Required */
		/* ------------------------- */
		if (( offset + 12 ) > lnPNT )

			/* Attempt to Load Longeur Block from File */
			/* --------------------------------------- */
			if ( ReloadProcedureNames( handle, secteur ) == MOINS_UN )
				return;

		/* Advance to and Collect Arg Counter */
		/* ---------------------------------- */
		offset += 10; argcount = tcGetw((tcPNT + offset)); offset += 2;

		/* Load more blocks for arguaments if Required */
		/* ------------------------------------------- */
		while (( offset + argcount ) > lnPNT )

			/* Attempt to Load Longeur Block from File */
			/* --------------------------------------- */
			if ( ReloadProcedureNames( handle, secteur ) == MOINS_UN )
				return;


		offset += argcount;

		/* Next Procedure */
		/* -------------- */
		nombre--;

		}

	/* Establish Final Length */
	/* ---------------------- */
	lnPNT = offset;
	
	return;

}


/*
 *	C O N S T R U C T _ F I L E N A M E ( filename , extension )
 *	------------------------------------------------------------
 *	Adds the indicated extension to the filename provided
 *
 */
#ifndef	UNIX
EXAWORD	fn_parser( BPTR, BPTR, EXAWORD );
#else
EXAWORD	fn_parser();
#endif

BPTR	construct_filename( filename, extension )
BPTR	filename;
BPTR	extension;
{

	EXAWORD	l;
	ConstructionZone[0] = 0;
	l = fn_parser( (BPTR) filename, (BPTR) ConstructionZone , _NO_EXTENSION );
	strcpy((BPTR)& ConstructionZone[l] , (BPTR) extension );
	return( (BPTR) ConstructionZone );

}


#ifdef	ABAL21
BPTR	PointerInitialisation( vtype, descptr, memptr )
EXAWORD	vtype;
BPTR	descptr;
BPTR	memptr;
{
	EXAWORD	offset;

	/* Check for redefinition of Pointer */
	/* --------------------------------- */
	if ( vtype & 0x2000 )
		descptr += ( 2 * WORDSIZE );
	else	{
		offset = tcGetw( (descptr));
		descptr += WORDSIZE;
 		memset((BPTR) (memptr + offset),0,5);
		}
	if (( vtype & 3 ) > 1)
		descptr += WORDSIZE;
	if ( vtype & 0x0040 )
		descptr += WORDSIZE;
	if ( vtype & 0x0020 )
		descptr += WORDSIZE;
	return( (BPTR) descptr );

}

BPTR	ExtendedMemoryInit(vtype,descptr)
EXAWORD	vtype;
BPTR	descptr;
{
	descptr += ( 2 * WORDSIZE );
	if (( vtype & 3 ) > 1)
		descptr += WORDSIZE;
	if ( vtype & 0x0040 )
		descptr += WORDSIZE;
	if ( vtype & 0x0020 )
		descptr += WORDSIZE;
	return( (BPTR) descptr );

}

/*	---------------------------------------------------------	*/
/*	I N I T I A L I S E _ D A T A _ I M A G E ( desc, b, id )	*/
/*	---------------------------------------------------------	*/

/*

	This routine initialises the data storage space described by
	the data table provided, for either GLOBAL or LOCAL variables.

	It recieves 3 arguaments :

		1 - ID The number of variables to initialise
		    (unsigned short integer)

		2 - B The base of the pre-allocated memory area
		    to be initialised.	 
		    (unsigned char *)
	
		3 - DESC The pointer to the first Variable Descriptor in
		    the descriptor table.	
		    (unsigned char *)

	It returns the original base memory area pointer to it's caller.

	The two support functions "ExtendedMemoryInit" and 
	"PointerInitialisation" are required to initialise individual
	variables of the associated types. These two functions must  
	return the descriptor pointer to the next variable element.

*/

BPTR	initialise_data_image( desc, b, id )
BPTR	desc;
BPTR	b;
EXAWORD	id;
{
	BPTR	rb;
	BPTR	hb;
	EXAWORD	x,y,l,i,a,ll,li;
	EXAWORD	r;

	hb = rb = b;

	while ( id > 0 ) {	/* While more variables to Initialise	*/

		id--;

		/* 	Collect data type avoiding ATR bug holes	*/
		/*	----------------------------------------	*/
		do {	x = tcGetw( desc); desc += WORDSIZE;	}

		while (( x & 0x0010 ) != 0 );

		/* Collect Variable memory adresse offset from table */
		/* ------------------------------------------------- */
		if (!(x & 0xFF00 )) {

			/* Normal Global variables (! FIELD=E etc ) */
			/* ---------------------------------------- */
			y = tcGetw( desc); desc += WORDSIZE;

			}

		else 	{ 

			if ( x & 0x8000    ) {
				desc = (BPTR) PointerInitialisation( x, desc, rb );
				continue;
				}
			else 

			/* Eliminate virtual memory variables */
			/* ---------------------------------- */
			if ((x & 0x4000) != 0 ) {

				/* Variables in extended memory (FIELD=E) */
				/* -------------------------------------- */
				desc = (BPTR) ExtendedMemoryInit(x,desc);
				continue;

				}

			/* Adjust descriptor for LONG variable offset */
			/* ------------------------------------------ */
			desc += (2 * WORDSIZE); y = 0;
			}

		/*	Calculate length	*/
		/*	----------------	*/
		if ((x & 0x0003) > 1 ) { 	/* If not Integer */
			l = tcGetw( desc); 
			desc += WORDSIZE;
			}
		else 	l = ( x & 0x0001) + 1; /* Else Integer LONG/short */
		
		/*	Establish 1st Dimension	*/
		/*	-----------------------	*/
		if (( x & 0x0040 ) != 0 ) {	/* If first dimension	*/
			i = tcGetw( desc); 
			desc += WORDSIZE;
			}
		else 	i = 1; 			/* Basic dimension	*/

		/*	Establish 2nd Dimension	*/
		/*	-----------------------	*/
		if (( x & 0x0020 ) != 0 ) {	/* If 2nd   dimension	*/
			a = tcGetw( desc); 
			desc += WORDSIZE;
			}
		else 	a = 1; 			/* Basic dimension	*/

		/*	Perform if .NOT. Virtuel .NOR. ARG	*/
		/*	------------------------ --------- 	*/
		if (( x & 0x7F08 ) == 0 ) {		


			b = (BPTR) (rb + y);	

			li = i;		/* Save inner index Counter	*/

			while ( a > 0 ) {	
				a--;
				i = li;	/* Ensure inner index counter	*/
				while ( i > 0 ) {	
					i--;
					ll = l;
					switch ( x & 0x0007 ) {	
						case 0  : *((BPTR) (b++)) = 0;
							  continue;
						case 1  : tcPutw((b), 0);
							  b+= WORDSIZE;
							  continue;
						case 2  : *((BPTR) (b++)) = (BYTE) 0x00c0; ll--;
							  (VOID) memset(b,0x00FF, ll);
							  b += ll; 
							  continue;
						case 3  : (VOID) memset(b,' ', ll);
							  b += ll; 
							  continue;

						default : return((BPTR) 0);
						} /* Switch end 	*/
					}	/* Next 1er Dimension	*/
				}		/* Next 2nd Dimension	*/
			}			/* Endif NOT external	*/
		}				/* Wend more variables	*/

	return( hb );

}

#endif

BPTR init_data(id,lng,desc)
EXAWORD id;			/* Count of variables to Initialise	*/
EXAWORD lng;			/* Length of DATA space needed		*/
BPTR	desc;			/* 1st Variable Descriptor pointer	*/
{
	BPTR	b;
	BPTR	rb;
	EXAWORD	x,y,l,i,a,ll,li;
	EXAWORD	r;
	EXAWORD	NbSect;

/* Calculate Sector Count from Byte Length */
/* --------------------------------------- */	
NbSect = ((lng / BLOCK) + (((lng % BLOCK) == 0) ? 0 : 1));
	
/* Attempt to allocate DATA IMAGE preparation zone */
/* ----------------------------------------------- */
if ((b = (BPTR) malloc((NbSect * BLOCK))) != (BPTR) 0) {

#ifdef	ABAL21

	return( initialise_data_image( desc, b, id ) );

#else

	/* Perform DATA IMAGE preparation */
	/* ------------------------------ */
	rb = b;
	while ( id > 0 ) {	/* While more variables to Initialise	*/
		id--;
		/* 	Collect data type	*/
		/*	-----------------	*/
		do {	x = tcGetw( desc ); desc += 2;	}
		while (( x & 0x0010 ) != 0 );

		if ( (x & 0x7F00 ) == 0 ) { /* If not External Variable */
			y = tcGetw( desc ); desc += 2;
			}
		else { desc += 4; y = 0; }

		/*	Calculate length	*/
		/*	----------------	*/
		if ( (x & 0x0003) > 1 ) { /* If not Integer */
			l = tcGetw( desc ); desc += 2;
			}
		else { l = ( x & 0x0001) + 1; }	/* Else Integer long/short */
		
		/*	Establish 1st Dimension	*/
		/*	-----------------------	*/
		if (( x & 0x0040 ) != 0 ) {	/* If first dimension	*/
			i = tcGetw( desc); desc += 2;
			}
		else { i = 1; }			/* Basic dimension	*/

		/*	Establish 2nd Dimension	*/
		/*	-----------------------	*/
		if (( x & 0x0020 ) != 0 ) {	/* If 2nd   dimension	*/
			a = tcGetw( desc); desc += 2;
			}
		else { a = 1; }			/* Basic dimension	*/

		/*	Perform if .NOT. External	*/
		/*	-------------------------	*/

		if (( x & 0x7F00) == 0 ) {		
			b = rb + y;	/* Establish Storage pointer 	*/
			li = i;		/* Save inner index Counter	*/
			while ( a > 0 ) {	a--;
				i = li;	/* Ensure inner index counter	*/
				while ( i > 0 ) {	i--;
					ll = l;
					switch ( x & 0x0007 ) {	
						case 0  : *((BPTR) (b++)) = 0; continue;
						case 1  : tcPutw( b , 0 );
							  b += 2; continue;
						case 2  : *((BPTR) (b++)) = (BYTE) 0x00c0; ll--;
							  (void) memset(b,0x00FF,  ll);
							  b += ll; continue;
						case 3  : (void) memset(b,' ',  ll);
							  b += ll; continue;
						default : return((BPTR) 0);

						} /* Switch end 	*/
					}	/* Next 1er Dimension	*/
				}		/* Next 2nd Dimension	*/
			}			/* Endif NOT external	*/
		}				/* Wend more variables	*/
	return((BPTR) rb);			/* Return data pointeur */
#endif
	}					/* Endif b != 0 	*/
else 	{  return( (BPTR) 0); }
}

EXAWORD	CreateGlobalDataImage( gdtptr )
BPTR	gdtptr;
{
	EXAWORD	varb_count;
	EXAWORD	alloc_size;
	BPTR	lptr;

	varb_count = tcGetw( (gdtptr ) );
	alloc_size = tcGetw( (gdtptr + 4) );

	if (( GlobalDataImage = init_data( varb_count, alloc_size, (gdtptr + 6))) == (BPTR) 0 ) {
#ifdef	BEFORE_09091994
		LineFeed();
		oputs((BPTR) "Global Data Initialisation failure ");
		LineFeed();
		Options.Global = FAUX;
#else
		;
#endif
		}

	return(Options.Global);
}

#ifndef	VMS
EXAWORD	Access( fnom , mode , share )
BPTR	fnom;
EXAWORD	mode;
EXAWORD	share;
{
	EXAWORD	handle;

	if ((handle = open( fnom , OPENRW )) != MOINS_UN ) {
		close( handle );
		return( 0 );
		}
	else	{
		return(MOINS_UN);
		}

}
#endif

void	liberlox( fnom )
BPTR	fnom;
{
	return;
}


EXAWORD	get_next_free_sector( longueur )
EXAWORD	longueur;
{
	EXAWORD	current;
	
	current = NextFreeSector;

	NextFreeSector += (longueur / BLOCK);
	if ( longueur % BLOCK )
		NextFreeSector++;

	return( current );

}

void	set_last_free_sector( longueur )
EXAWORD	longueur;
{
	NextFreeSector -= (longueur / BLOCK);
	if ( longueur % BLOCK )
		NextFreeSector--;
	return;

}



/*
 *	Calculates next result sector for AT copy function
 *	--------------------------------------------------
 *
 */

void	NextSector( Longeur )
EXAWORD	Longeur;
{
	EXAWORD	Used;

	/* Check for Debug display of Sector Conversions */
	/* --------------------------------------------- */
	if ( debug > 0  ) { HexAdresse( Longeur ); HexAdresse( OutSect ); }

	/* Calculate Sector Count from Byte Length */
	/* --------------------------------------- */	
	Used = ((Longeur / BLOCK) + (((Longeur % BLOCK) == 0) ? 0 : 1));
	OutSect += Used;

	/* Check for Debug Display of Sector Conversions */
	/* --------------------------------------------- */
	if ( debug > 0  ) {
		oputb('+'); 	HexAdresse( Used );
		oputb('=');	HexAdresse( OutSect );
		}

	return;

}

EXAWORD	TransferVariableNames( Handle, lhandle, blockid, varcount )

				/* ---------------------------- */
EXAWORD	Handle;			/* Source file handle		*/
EXAWORD	lhandle;		/* Target File Handle		*/
EXAWORD	blockid;		/* Source block Id		*/
EXAWORD	varcount;		/* Number of Names to be Copied */
				/* ---------------------------- */
{
	EXAWORD	result;

	if ( Options.Strip )
		return( 0 );

	/* To Be Completed */
	/* --------------- */
	result = OutSect;
	return( result );

}

/*
 *	Copies a block of tcode from source to result
 *	---------------------------------------------
 *
 */

EXAWORD	CopyBlock( Handle , lhandle , blockid , blocklen , Mode )

				/* ---------------------------- */
EXAWORD	Handle;			/* Source file handle		*/
EXAWORD	lhandle;		/* Target File Handle		*/
EXAWORD	blockid;		/* Source block Id		*/
EXAWORD	blocklen;		/* Sources block length		*/
EXAWORD	Mode;			/* 0  : Code    1 : Variables	*/
				/* ---------------------------- */

{

				/* ---------------------------- */
	BPTR	wptr;		/* Local Buffer Pointer		*/
	BPTR	mptr;		/* GLOBAL DATA IMAGE ZONE	*/
	EXAWORD	mlen;		/* GLOBAL DATA IMAGE LENGTH	*/
	EXAWORD	x;		/* General Usage Variable	*/
				/* ---------------------------- */

	/* Read Blocks from Source File */
	/* ---------------------------- */
	if ((wptr = (BPTR) LoadBlock( Handle , blockid , blocklen )) != (BPTR) 0) {

		/* Check for Variable Table Mode */
		/* ----------------------------- */
		if ( Mode != 0 ) {

			/* Check for LOCAL variable table */
			/* ------------------------------ */
			if ( Mode  ==  1 ) {

				
				if ( trad_ver < '2' ) {
					/* Handle Variable Names Table */
					/* --------------------------- */
					x = TransferVariableNames( Handle, lhandle, (tcGetw((wptr + 2))), (tcGetw((wptr+4))) );

					/* Update Data Table with Names Sector */
					/* ----------------------------------- */
					tcPutw( (wptr + 2) , x );
					}

				}
			else	{
				/* Check for IMAGE option */
				/* ---------------------- */
				if ( Options.Global ) {

					/* GLOBAL data table IMAGE preparation */
					/* ----------------------------------- */
					if ( GlobalDataImage != (BPTR) 0 ) {

						mlen = tcGetw((wptr+4));

						/* Locate Global Data Image */
						/* ------------------------ */
						tcPutw((&ControlZone[76]),OutSect);
						tcPutw((&ControlZone[78]),mlen);

						/* Write GLOBAL IMAGE to disk */
						/* -------------------------- */
						WriteBlock( lhandle , GlobalDataImage , OutSect , mlen );

						/* Liberate and Calculate next Sector */
						/* ---------------------------------- */
						NextSector( mlen );
						}
					}
				else	{
					/* Remove Variable Name Table */
					/* -------------------------- */
					tcPutw( (wptr + 2) , 0 );
					}

				/* Patch Sector ID into Header block */
				/* --------------------------------- */
				tcPutw((&ControlZone[26]),OutSect);


				}
			}

		/* Write Blocks to Target file */
		/* --------------------------- */
		WriteBlock( lhandle , wptr , OutSect , blocklen );
		free ( wptr );
		NextSector( blocklen );
		return(0);
		}
	else	{
		return( MOINS_UN );
		}

}

/*
 *	Performs a Clean and tidy exit from COPYAT
 *	------------------------------------------
 *
 */

EXAWORD	Abandon( Handle , lhandle , lnom )
EXAWORD	Handle;
EXAWORD	lhandle;
BPTR	lnom;
{
	close ( Handle  );	/* Close original T-Code File 	*/
	close ( lhandle );	/* Close New T-Code File	*/
	liberlox ( lnom );	/* Liberate New T-Code File	*/
	unlink  ( lnom  );	/* Delete New file 		*/
	return( MOINS_UN );	/* Indicate a serious error	*/
}

/*
 *	COPYFILE : Performs a Copy and strip of a .at to .ot
 *	----------------------------------------------------
 */

EXAWORD	CopyFile( Handle , FileName )

				/* ------------------------------------ */
EXAWORD	Handle;			/* Original .at Filehandle		*/
BPTR	FileName;		/* Original .at FileName		*/
				/* ------------------------------------ */

{
				/* ------------------------------------ */
	BPTR	lnom;		/* Local .ot Result file name		*/
	BPTR	ctrlptr;	/* Segment or Procedure Control Zone	*/
	EXAWORD	ctrlid;		/* Segment or Procedure Control Sector	*/
	EXAWORD	ctrlen;		/* Segment or Procedure Control length	*/
	EXAWORD	blockid;	/* Block Control Sector			*/
	EXAWORD	blocklen;	/* Block Control length			*/
	EXAWORD	lhandle;	/* Result .ot File handle		*/
	EXAWORD	proc_used;	/* Flag for procedure usage		*/
	EXAWORD	indent;		/* Indentation into Code Control Tables	*/
	EXAWORD	total_size;	/* Code plus Data Memory usage		*/
	EXAWORD	v,w;		/* General variables			*/
	EXAWORD	l_max_vls;	/* Largset Segment Overlay Table Zone	*/
				/* ------------------------------------ */

	/* Analyse file name and and ot Extension */
	/* -------------------------------------- */
	if ((lnom = (BPTR) construct_filename((BPTR) FileName, (BPTR) TEMP_TRADUIT)) == (BPTR) 0 ) {
		return( Handle );
		}

	if ( Options.Pannel )
		draw_target_file( lnom );

	if ( debug > 0  ) {
		/* Display Result file name */
		/* ------------------------ */
		StreamString((BPTR) lnom );
		}

	/* Check for File Exists */
	/* --------------------- */
	if (Access( lnom , 0 , 2 ) == 0 ) {
		
		/* Liberate file and Delete */
		/* ------------------------ */
		liberlox ( lnom ); unlink ( lnom );

		}

	/* Attempt to Create a new file */
	/* ---------------------------- */
	if ((lhandle = creat( (BPTR) lnom , CREATRW )) == MOINS_UN ) {
		status_message( (BPTR) TalkPtr[27], (BPTR) lnom );
		return( Handle );
		}

	/* To Correct O_BINARY bug */
	/* ----------------------- */
	(void) close( lhandle );
	lhandle = open( (BPTR) lnom, OPENRW );

	/* ----------------------------------------------------- */
	/* Now Copy all blocks excluding Debug Infos to New File */
	/* ----------------------------------------------------- */

	OutSect = 1;

	/* Copy Constants if Existant */
	/* -------------------------- */
	if (( blockid = tcGetw((&ControlZone[22]))) != 0 ) {
		if ( debug > 0 ) {
			StreamLine(); StreamString((BPTR) "Constants      : ");
			}
		blocklen = tcGetw((&ControlZone[24]));
		tcPutw((&ControlZone[22]), OutSect );
		if ( CopyBlock( Handle , lhandle , blockid , blocklen ,0) == MOINS_UN ) {
			return( Abandon( Handle , lhandle , lnom ) );
			}
		}

	/* Copy Global and Extended Variable Table */
	/* --------------------------------------- */
	if (( blockid = tcGetw((&ControlZone[26]))) != 0 ) {
		if ( debug > 0 ) {
			StreamLine(); StreamString((BPTR) "GlobalVariables : ");
			}
		blocklen = tcGetw((&ControlZone[28]));
		tcPutw((&ControlZone[26]),OutSect);
		if ( CopyBlock( Handle , lhandle , blockid , blocklen ,2) == MOINS_UN ) {
			return( Abandon( Handle , lhandle , lnom ) );
			}
		}

	/* Load Segment Control Table */
	/* -------------------------- */
	if (( ctrlid = tcSector((&ControlZone[34]))) != 0 ) {
		ctrlen = tcGetw((&ControlZone[36]));
		if ((ctrlptr = (BPTR) LoadBlock( Handle , ctrlid , ctrlen )) == (BPTR) 0) {
			return( Abandon( Handle , lhandle , lnom ) );
			}
		}
	else	{
		return( Abandon( Handle , lhandle , lnom ) );
		}

	/* Copy Segment code and Data Descriptor blocks */
	/* -------------------------------------------- */
	indent = 0; l_max_vls = 0;
	
	while ( indent < ctrlen ) {

		if (( blockid = tcGetw((ctrlptr + indent ))) != 0xFFFF) { 

			if ( debug > 0  ) { 
				StreamLine(); HexAdresse( blockid );
				}

			/* Segment Data Descriptors */
			/* ------------------------ */
			if (( blockid = tcGetw((ctrlptr + indent + 6))) != 0 ) {
				if ( debug > 0  ) {
					StreamString((BPTR) "Segment Data   : ");
					}
				blocklen = tcGetw((ctrlptr + indent + 8));
				tcPutw(((BPTR)(ctrlptr + indent + 6)), OutSect );
				if ( blocklen > l_max_vls )
					l_max_vls = blocklen;

				if ( CopyBlock( Handle , lhandle , blockid , blocklen ,1) == MOINS_UN ) {
					free ( ctrlptr );
					return( Abandon( Handle , lhandle , lnom ) );
					}
				}
			else	tcPutw((ctrlptr + indent + 8),0);

			/* Segment Local Constants  */
			/* ------------------------ */
			if (( blockid = tcGetw((ctrlptr + indent +12))) != 0 ) {
				if ( debug > 0  ) {
					StreamString((BPTR) "Segment Constants  : ");
					}
				blocklen = tcGetw((ctrlptr + indent + 14));
				tcPutw(((BPTR)(ctrlptr + indent + 12)), OutSect );

				if ( CopyBlock( Handle , lhandle , blockid , blocklen ,0) == MOINS_UN ) {
					free ( ctrlptr );
					return( Abandon( Handle , lhandle , lnom ) );
					}
				}
			else	tcPutw((ctrlptr + indent + 14),0);

			/* Segment Code block */
			/* ------------------ */
			if (( blockid = tcGetw((ctrlptr + indent + 2))) != 0 ) {
				if ( debug > 0  ) {
					StreamLine(); StreamString((BPTR) "Segment Code   : ");
					}
				blocklen = tcGetw((ctrlptr + indent + 4));
				tcPutw(((BPTR)(ctrlptr + indent + 2)), OutSect );
				if ( CopyBlock( Handle , lhandle , blockid , blocklen ,0) == MOINS_UN ) {
					free ( ctrlptr );
					return( Abandon( Handle , lhandle , lnom ) );
					}
				}
			else	tcPutw((ctrlptr + indent + 2),0);
			}

		indent += 24;

		}


	/* Copy and update Segment Table */
	/* ----------------------------- */
	if ( debug > 0  ) {
		StreamLine(); StreamString((BPTR) "Segment Table  : ");
		}
	tcPutw(((BPTR)(&ControlZone[34])), OutSect );
	tcPutw(((BPTR)(&ControlZone[44])),l_max_vls);
	WriteBlock( lhandle , (BPTR) ctrlptr , OutSect , ctrlen );
	NextSector( ctrlen );
	free ( (BPTR) ctrlptr );

	/* Load Procedure Control Table */
	/* ---------------------------- */
	if (( ctrlid = tcSector((&ControlZone[38]))) != 0 ) {
		if ( debug > 0  ) {
			StreamLine(); StreamString((BPTR) "Procedure Table  : ");
			}
		ctrlen = tcGetw((&ControlZone[40]));
		if ((ctrlptr = (BPTR) LoadBlock( Handle , ctrlid , ctrlen )) == (BPTR) 0) {
			return( Abandon( Handle , lhandle , lnom ) );
			}

		/* Copy Procedure Code and Data Descriptor Blocks */
		/* ---------------------------------------------- */
		indent = 0;

		while ( indent < ctrlen ) {

			if ( debug > 0 ) {

				StreamLine(); StreamString((BPTR) " Procedure Entry ");
				HexAdresse( indent ); StreamString((BPTR) " : ");
				for ( w = 0; w < 16; w += 2 ) {
					v = tcGetw(((BPTR) (ctrlptr + indent + w)));
					HexAdresse( v );
					} 
				}

			/* Test if procedure has been used */
			/* ------------------------------- */
			proc_used = tcGetw(((BPTR)(ctrlptr + indent + 14)));
			if (keep_procedures)
				proc_used |= PROCEDURE_USED;

			if ( debug > 0 ) {
				StreamString((BPTR) " Flags "); HexAdresse( proc_used );
				}

			if (( proc_used & PROCEDURE_USED ) && ( proc_used != 0xFFFF)) {

				/* Procedure Data Descriptors */
				/* -------------------------- */
				if (( blockid = tcGetw(((BPTR)(ctrlptr + indent + 4)))) != 0 ) {
					if ( debug > 0  ) {
						StreamLine(); StreamString((BPTR) "Procedure Data : ");
						}
					blocklen = tcGetw(((BPTR)(ctrlptr + indent + 6)));
					tcPutw(((BPTR)(ctrlptr + indent + 4)),OutSect);
					if ( CopyBlock( Handle , lhandle , blockid , blocklen , 1 ) == MOINS_UN ) {
						free ( ctrlptr );
						return( Abandon( Handle , lhandle , lnom ) );
						}
					}

				/* Procedure Local Constants  */
				/* -------------------------- */
				if (( blockid = tcGetw((ctrlptr + indent +8))) != 0 ) {
					if ( debug > 0  ) {
						StreamString((BPTR) "Procedure Constants  : ");
						}
					blocklen = tcGetw((ctrlptr + indent + 10));
					tcPutw(((BPTR)(ctrlptr + indent + 8)), OutSect );

					if ( CopyBlock( Handle , lhandle , blockid , blocklen ,0) == MOINS_UN ) {
						free ( ctrlptr );
						return( Abandon( Handle , lhandle , lnom ) );
						}
					}
				else	tcPutw((ctrlptr + indent + 10),0);

				/* Procedure Code block */
				/* -------------------- */
				if (( blockid = tcGetw(((BPTR)(ctrlptr + indent)))) != 0 ) {
					if ( debug > 0  ) {
						StreamLine(); StreamString((BPTR) "Procedure Code : ");
						}
					blocklen = tcGetw(((BPTR)(ctrlptr + indent + 2)));
					tcPutw(((BPTR)(ctrlptr + indent)),OutSect);
					if ( CopyBlock( Handle , lhandle , blockid , blocklen , 0 ) == MOINS_UN ) {
						free ( ctrlptr );
						return( Abandon( Handle , lhandle , lnom ) );
						}
					}
				}
			else	{
				if (( debug > 0 ) || (Options.Verbose) || (Options.Pannel)) {
					if ((total_size =  (tcGetw(((BPTR) (ctrlptr + indent + 2))))) != 0)
						CodeOptimized(0,indent,total_size, 0);
					if ((total_size = (tcGetw(((BPTR) (ctrlptr + indent + 6))))) != 0)
						TableOptimized(2,indent,total_size, 0);
					}
				tcPutw(((BPTR)(ctrlptr + indent + 0)),0);
				tcPutw(((BPTR)(ctrlptr + indent + 2)),0);
				tcPutw(((BPTR)(ctrlptr + indent + 4)),0);
				tcPutw(((BPTR)(ctrlptr + indent + 6)),0);
				}
			proc_used &= PROCEDURE_STATIC;
			proc_used |= PROCEDURE_DIFFERED;
			tcPutw(((BPTR)(ctrlptr + indent + 14)),proc_used);
			indent += 16;
	
			}
	
		/* Copy and Update Procedure Table */
		/* ------------------------------- */
		if ( debug > 0  ) {
			StreamLine(); StreamString((BPTR) "Procedure Table: ");
			}
		tcPutw(((BPTR)(&ControlZone[38])),OutSect );
		WriteBlock( lhandle , (BPTR) ctrlptr , OutSect , ctrlen );
		NextSector( ctrlen );
		free ((BPTR) ctrlptr );
	
		}

	/* Copy User Library table if existant */
	/* ----------------------------------- */
	if (( blockid = tcGetw((&ControlZone[68]))) != 0 ) {
		if ( blockid != 0xFFFF ) {
			if ( debug > 0 ) {
				StreamLine(); StreamString((BPTR) "User libraries : ");
				}
			blocklen = ((tcGetw((&ControlZone[70]))) * 256);
			tcPutw((&ControlZone[68]), OutSect );
			if ( CopyBlock( Handle , lhandle , blockid , blocklen ,0) == MOINS_UN ) {
				return( Abandon( Handle , lhandle , lnom ) );
				}
			}
		}

	/* Check for Removal of Symbolic Information */
	/* ----------------------------------------- */
	if ((!(Options.Strip)) && (trad_ver < '2')) {

		/* Copy Procedure Names Table if Existant */
		/* -------------------------------------- */
		if (( blockid = tcGetw((&ControlZone[42]))) != 0 ) {
			if ( blockid != 0xFFFF ) {
				if ( debug > 0 ) {
					StreamLine(); StreamString((BPTR) "Procedure Names: ");
					}
				blocklen = lnPNT;
				tcPutw((&ControlZone[42]), OutSect );
				if ( CopyBlock( Handle , lhandle , blockid , blocklen ,0) == MOINS_UN )
					return( Abandon( Handle , lhandle , lnom ) );
				}
			}

		}

	else if (!( SymbolStatus )) {

		/* --------------------------- */
		/* Cancel Symbolic Information */
		/* --------------------------- */

						 /* ---------------------- */
		tcPutw((&ControlZone[42]),0); 	 /* Procedure Names 	   */
						 /* ---------------------- */
		ControlZone[18] &= 0x00FE;	 /* Debug Infos  Cancelled */
						 /* ---------------------- */

		}

	/* 	Remove DEBUG Liste Information since no longer valid	*/
	/* 	----------------------------------------------------	*/ 
	if ( Options.Optimise ) {
						 /* ---------------------- */
		tcPutw((&ControlZone[64]),0);    /* Debug Map Sector	   */
		tcPutw((&ControlZone[66]),0);    /* Debug Filename Sector  */
		ControlZone[18] |= 0x00C0;	 /* Optimisation indicator */
						 /* ---------------------- */
		}

	/* Copy and Update Control Zone Information */
	/* ---------------------------------------- */
	ctrlen = tcGetw((&ControlZone[62]));
	if (( ctrlen != 0 ) && ( ctrlen != MOINS_UN ))
		(void) abal_crypt(ctrlen,(BPTR) (&ControlZone[18]),44,ENCODE);
	WriteBlock( lhandle , (BPTR) ControlZone , 0 , 256 );

	/* Close the old Remove t-Code file now */
	/* ------------------------------------ */
	close ( Handle );

	/* Duplicate the filename Now */
	/* -------------------------- */
	strcpy((BPTR) ConstructionTemp,(BPTR) ConstructionZone );

	if ( unlink ((BPTR) construct_filename((BPTR) FileName,(BPTR) ABAL_TRADUIT) ) == MOINS_UN) {
		oputs((BPTR) TalkPtr[25] );
		oputs((BPTR) ConstructionZone );
		LineFeed();
		}

	/* Rename New Tcode Now */
	/* -------------------- */
	(void) close( lhandle );
	if ( rename((BPTR) ConstructionTemp,(BPTR) ConstructionZone ) == MOINS_UN) {
		oputs((BPTR) TalkPtr[26] );
		oputs((BPTR) ConstructionTemp );
		oputs((BPTR) " : ");
		oputs((BPTR) ConstructionZone );
		LineFeed();
		}

	/* Return new T-Code file Handle */
	/* ----------------------------- */
	return( lhandle );

}

#endif	/* _COPYAT_C */
	/* --------- */
