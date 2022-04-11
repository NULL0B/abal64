/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		Copyright (c) 2021 Amenesik / Sologic			*/
/*		--------------------------------			*/
/*									*/
/*		File	:	AO.C      				*/
/*		Version :	5.1c					*/
/*		Date	:	04/07/2021				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AO_C
#define	_AO_C

#define	OPTIMISEUR

				/* ------------------------------------ */
#include "aomain.h"		/* Type Definitions and constants	*/
#include "aotcode.h"		/* Inclusion of TCode definitions	*/
#include "aotcngf.h"		/* NGF T-Code Definitions		*/
#include "aostat.h"		/* Statistics management		*/
#include "aomacro.h"		/* Macros Used for Source Clarity	*/
#include "aoproto.h"		/* Prototypes for all Object Modules	*/
#include "aoglobal.h"		/* Data Items with Global Scope		*/
#include "aoblock.h"		/* Buffer File Block Control		*/
#include "version.h"		/* Version Copyright etc		*/
#include "aogesmes.c"		/* International messages		*/
				/* ------------------------------------ */

#define	MODULE_PROVISOIRE "\r\n   Beta Data : 04/07/2021 "

BYTE	trad_ver;		/* Tcode Version Indicator		*/
EXAWORD	LocalSymbolsSector;	/* Variable Names Sector		*/
EXAWORD	GlobalSymbolsSector;	/* Variable Names Sector		*/
EXAWORD	SymbolStatus;		/* Status of Symbols Manager		*/
EXAWORD	keep_procedures;	/* Cancels procedure removal OVL OBJ++	*/
EXAWORD	canliste;		/* Allows use of Tcode Listing		*/

#define	TCPREFIX	18+2

#ifdef	VERSION666

EXAWORD	fsame=0;
EXAWORD	TcodeGetWord(BPTR bptr)
{
	EXAWORD	result=0;
	EXAWORD	value=0;
	EXAWORD	ws=sizeof(EXAWORD);
	result = ((*(bptr + 0) & 0x00FF));
	result |= ((*(bptr + 1) & 0x00FF)<< 8);
	if ( WORDSIZE > 2 ) 
	{
		result |= ((*(bptr + 2) & 0x00FF)<<16);
		result &= 0x00FFFFFF;
		result |= ((*(bptr + 3) & 0x00FF)<<24);
		result &= 0x00FFFFFFFF;
#ifdef	ABAL64
		if ( WORDSIZE > 4 ) 
		{
			value   = (*(bptr + 4) & 0x00FF);
			value <<= 32;
			result |= value;
			result &= 0x00FFFFFFFFFF;
			value   = (*(bptr + 5) & 0x00FF);
			value <<= 40;
			result |= value;
			result &= 0x00FFFFFFFFFFFF;
			value   = (*(bptr + 6) & 0x00FF);
			value <<= 48;
			result |= value;
			result &= 0x00FFFFFFFFFFFFFF;
			value   = (*(bptr + 7) & 0x00FF);
			value <<= 56;
			result |= value;
			result &= 0xFFFFFFFFFFFFFFFF;
		}
#endif
	}
	return( result );
}

EXAWORD	TcodeWord16(BPTR bptr)
{
	EXAWORD	result=0;
	result = ((*(bptr + 0) & 0x00FF));
	result |= ((*(bptr + 1) & 0x00FF)<< 8);
	return( result );
}

EXAWORD	TcodeWord32(BPTR bptr)
{
	EXAWORD	result=0;
	result = ((*(bptr + 0) & 0x00FF));
	result |= ((*(bptr + 1) & 0x00FF)<<  8);
	result |= ((*(bptr + 2) & 0x00FF)<< 16);
	result |= ((*(bptr + 3) & 0x00FF)<< 24);
	return( result );
}

VOID	TcodePutWord(BPTR bptr,EXAWORD v)
{
	*(bptr +0) = (v & 0x00FF);
	*(bptr +1) = ((v >> 8) & 0x00FF);
	if ( WORDSIZE > 2 ) 
	{
		*(bptr +2) = ((v >>16) & 0x00FF);
		*(bptr +3) = ((v >>24) & 0x00FF);
#ifdef	ABAL64
		if ( WORDSIZE > 4 ) 
		{
			*(bptr +4) = ((v >>32) & 0x00FF);
			*(bptr +5) = ((v >>40) & 0x00FF);
			*(bptr +6) = ((v >>48) & 0x00FF);
			*(bptr +7) = ((v >>56) & 0x00FF);
		}
#endif
	}
	return;
}

#endif	/* VERSION666 */

/*	Systeme Respecting Line Feed Function
 *	-------------------------------------
 */

void	LineFeed()
{
#ifndef	UNIX
#ifndef	VMS
	oputb('\r');
#endif
#endif
	oputb('\n');
}


/*
 *	S T A T U S _ M E S S A G E 
 *	---------------------------
 *
 */
void	status_message( cptr, mptr )
BPTR	cptr;
BPTR	mptr;
{
	if ( Options.Pannel )
		announce_current_phase( cptr, mptr );
	else if ( Options.Verbose ) {
		oputs((BPTR) cptr );
		oputs((BPTR) mptr );
		LineFeed();
		}
	return;
}

/*
 *	E R R O R _ M S G ( eptr , fptr )
 *	---------------------------------
 *
 */

void	error_msg ( eptr , fptr )
BPTR	eptr;
BPTR	fptr;
{
	if ( Options.Pannel )
		draw_error_message( eptr );
	else	{
		oputs((BPTR) construct_filename((BPTR) fptr, (BPTR) ABAL_TRADUIT ));
		oputs((BPTR) " : ");
		oputs((BPTR) eptr );
		LineFeed();
		}
	return;
}

/*	Variable Name Table loader	*/
/*	--------------------------	*/
extern	EXAWORD	WORDSIZE;
EXAWORD	tcSector( BPTR tptr )
{
	EXAWORD	secteur;
	secteur = tcGetw(tptr);
	if (!( secteur ))
		return( secteur );
	else if ( secteur == MOINS_UN )
		return( 0 );
	else if ( WORDSIZE != 2 )
		return( secteur );
	else if ( secteur == 0x00FFFF )
		return( 0 );
	else	return( secteur );
}

BPTR	NameTable( tptr )
BPTR	tptr;
{

	EXAWORD	nombre;
	EXAWORD	secteur;
	EXAWORD	longeur;

	/* Read Name Table Block number */
	/* ---------------------------- */
	secteur = tcSector((tptr + WORDSIZE));

	/* Check for Name Table Existing */
	/* ----------------------------- */
	if (( secteur != 0 ) && ( secteur != MOINS_UN )) {

		/* Read Variable Count */
		/* ------------------- */
		nombre  = tcGetw( tptr );

		nombre  *= (8 + WORDSIZE);

		longeur = (nombre / BLOCK);

		if ( (nombre % BLOCK) != 0 ) {
			longeur++;
			}

		/* Attempt to Load Block of Variable Names */
		/* --------------------------------------- */
		return((BPTR) LoadBlock( Handle , secteur , longeur ));

		}
	else	{

		/* Return a NULL Pointer */
		/* --------------------- */
		return((BPTR) 0);
		}
	
}


int	enhanced_list()
{
	if ( Options.Liste == 'L' )
		return(1);
	else	return(0);
}


/*	Resets all Options to default values	*/
/*	------------------------------------	*/

void	ResetOptions()
{

					/* ------------------------ */
	Options.CheckFmt	= FAUX;	/* no format labels	    */
	Options.Optimise	= FAUX;	/* Optimisation		OFF */
	Options.Global		= FAUX;	/* Global Data Image	OFF */
	Options.Strip		= FAUX;	/* Symbolic Strip	OFF */
	Options.Registers	= FAUX;	/* Register Optimise	OFF */
	Options.Inline   	= FAUX;	/* Inline Procs and Seg	OFF */
	Options.Tables		= FAUX;	/* Table Compression	OFF */
	Options.Procedures	= FAUX;	/* Proc Elimination	OFF */
	Options.Segments	= FAUX;	/* Segment Compression	OFF */
	Options.Constants	= FAUX; /* Constant Compression OFF */ 
					/* ------------------------ */
					/* ------------------------ */
	Options.Compile   	= FAUX;	/* Compilation		OFF */
	Options.Liste	  	= FAUX;	/* Tcode Mnemonic List	OFF */
	Options.Stats 		= FAUX;	/* Statistics		OFF */
	Options.Analyse		= FAUX;	/* Structure Analysis	OFF */
	Options.Verbose		= FAUX;	/* Mode Verbose		OFF */
	Options.Warnings	= FAUX; /* Warning Messages	OFF */
	Options.Pannel		= FAUX;	/* Control Pannel	OFF */
	Options.Alliance	= FAUX;
	debug     		= FAUX; /* DEBUG mode		OFF */
					/* ------------------------ */


	return;
}

/*	Display of Post-optimisation Size information	*/
/*	---------------------------------------------	*/
void	Optimized( type, mode , oldsize , newsize )
EXAWORD	type;
EXAWORD	mode;
EXAWORD	oldsize;
EXAWORD	newsize;
{
	if ( Options.Verbose ) {

		/* Check first for Global Data Table Optimisation */
		/* ---------------------------------------------- */
		if ( type & 4 ) {
			oputs(" GDT ");
			}
		else	{
			if ( type & 2 )
				oputs(" LDT");
			if ( type & 1 ) {
				oputs(" SEGM "); DecimalWord( mode );
				}
			else	{
				oputs(" PROC "); AffProc( mode );
				}
			}
		oputs((BPTR) "      ");
		oputs((BPTR) TalkPtr[12] );
		oputs((BPTR) TalkPtr[13] );
		HexAdresse( oldsize );
		oputs((BPTR) TalkPtr[14] );
		HexAdresse( newsize );
		LineFeed();
		}
	ProgramShrink += (oldsize - newsize);
	return;
}	

void	CodeOptimized(type, mode , oldsize , newsize )
EXAWORD	type;
EXAWORD	mode;
EXAWORD	oldsize;
EXAWORD	newsize;
{
	CodeShrink += (oldsize - newsize);
	if ( Options.Pannel ) {
		draw_code_report( oldsize, newsize );
		if ( newsize == 0 )
			pannel_decrement( type );
		}
	else	Optimized( type, mode, oldsize, newsize );
	return;

}

void	TableOptimized(type, mode , oldsize , newsize )
EXAWORD	type;
EXAWORD	mode;
EXAWORD	oldsize;
EXAWORD	newsize;
{
	TableShrink += (oldsize - newsize);
	if ( Options.Pannel )
		draw_table_report( oldsize, newsize );
	else	Optimized( type, mode, oldsize, newsize );
	return;
}

void	DiezCharge()
{
	diezheap = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(17*WORDSIZE))) );
	if ( diezheap == MOINS_UN ) {	diezheap = 50;		}
	diezfile = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(18*WORDSIZE))) );
	if ( diezfile == MOINS_UN ) {	diezfile = 64;		}
	dieztemp = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(19*WORDSIZE))) );
	if ( dieztemp == MOINS_UN ) {	dieztemp = 2048;	}
	diezpile = tcGetw( (((BPTR) ControlZone) +(TCPREFIX+(20*WORDSIZE))) );
	if ( diezpile == MOINS_UN ) {	diezpile = 2048;	}
	return;
}

void	rewrite_procedure_table()
{
	EXAWORD	blockid;
	EXAWORD	blocklen;

	if ( debug > 0 ) {
		LineFeed(); oputs((BPTR) TalkPtr[15]);
		}
	blockid  = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(9*WORDSIZE))));
	blocklen = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(10*WORDSIZE))));
	WriteBlock(Handle,(BPTR) tc_PDT,blockid,blocklen);
	return;
}

void	rewrite_segment_table()
{
	EXAWORD	blockid;
	EXAWORD	blocklen;

	if ( debug > 0 ) {
		LineFeed(); oputs((BPTR) TalkPtr[15]);
		}
	blockid  = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(7*WORDSIZE))));
	blocklen = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(8*WORDSIZE))));
	WriteBlock(Handle,(BPTR) tc_SDT,blockid,blocklen);
	return;
}


void	option_status( valeur )
EXAWORD	valeur;
{
	if ( valeur ) oputs((BPTR) " VRAI ");
	else	      oputs((BPTR) " FAUX ");
	return;
}

void	display_options()
{
	if ( debug != 0 ) {
		LineFeed();
		oputs((BPTR) "Optimise    : ");
		option_status( Options.Optimise );
		LineFeed();
		oputs((BPTR) "Global Data : ");
		option_status( Options.Global   );
		LineFeed();
		oputs((BPTR) "Debug Strip : ");
		option_status( Options.Strip    );
		LineFeed();
		oputs((BPTR) "Registers   : ");
		option_status( Options.Registers );
		LineFeed();
		oputs((BPTR) "Tables      : ");
		option_status( 	Options.Tables  );	
		LineFeed();
		oputs((BPTR) "Procedures  : ");
		option_status( 	Options.Procedures );
		LineFeed();
		oputs((BPTR) "Constants   : ");
		option_status( 	Options.Constants );	
		LineFeed();
		}
	return;
}


/*
 *	Entry point and Startup of Optimiser
 *	------------------------------------
 *
 */

EXAWORD	is_option_indicator( c )
EXAWORD	c;
{
	if ( c == '-' ) return( VRAI );
#ifndef	UNIX
	if ( c == '/' ) return( VRAI );
#endif
#ifdef	VMS
	if ( c == '/' ) return( VRAI );
#endif
	return( FAUX );
}

/*
 *	Display of Module identification
 *	--------------------------------
 *
 */

void	module_identification()
{
	EXAWORD	x;
#ifdef	PRL
	LineFeed();
#endif	
	oputs((BPTR) TalkPtr[1]         ); 
	oputs((BPTR) MODULE_VERSION     );
	oputs((BPTR) MODULE_PROVISOIRE  );
	oputs((BPTR) MODULE_ENVIRONMENT );
	oputs((BPTR) MODULE_COPYRIGHT   );
#ifdef ABAL64
	oputs((BPTR) " -64 ");
#endif
	LineFeed();
	for ( x = 31 ; x < 37; x++ ) {
		LineFeed();
		oputs((BPTR) TalkPtr[x]	);
		}
#ifdef	AO_LISTFILE
	if ( canliste ) {
		LineFeed();
		oputs((BPTR) "      l    :  Tcode assembler list ");
		}
#endif
	LineFeed();



#ifdef	AO_INTERNE
	LineFeed();
	oputs((BPTR) "   VERSION INTERNE  -  NE PAS DIFFUSER" );
	LineFeed();
	oputs((BPTR) "   -----------------------------------");
	LineFeed();
#endif
	return;

}


/*
 *	C R Y P T ( pkey , sptr , slen , mode )
 *	---------------------------------------
 *	Performs the T-Code header unlocking function for protection
 *	against auto-debalers.
 *
 */


BPTR	abal_crypt( pkey , sptr , slen ,mode)
EXAWORD	pkey;
BPTR	sptr;
EXAWORD	slen;
EXAWORD	mode;
{
	BPTR	rptr;
	BYTE	exkm[16][16];
	short int kdex,kdey;
	short  int rotor;
	EXAWORD	cmpt;
	EXAWORD	x,y,z,zl;
	EXAWORD	phase;

	rptr = sptr; cmpt = 0;
	for (x = 0; x < 16 ; x++) {
		for ( y =0; y < 16; y++ ) {
			exkm[x][y] = cmpt; cmpt++;
			}
		}
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
		if ( kdex > 15 ) { kdex = 0; }
		if ( kdey > 15 ) { kdey = 0; }
		if ( kdex < 0 ) { kdex = 15; }
		if ( kdey < 0 ) { kdey = 15; }
		if ((pkey & rotor ) != 0 ) {
			phase++;
			if ( phase > 7 ) { phase = 0; }
			}
		rotor <<= 1;
		if ( rotor == 0 ) { rotor = 1; }
		*(sptr++) = exkm [ kdex ][ kdey ]; slen--;
		}
 	return(rptr);
}

BYTE	TcodeNameZone[16];
BPTR	program_tcode_name()
{
	EXAWORD	i;
	for ( i=0; i < 15; i++ )
		TcodeNameZone[i] =  ControlZone[i+3];
	TcodeNameZone[i] = 0;
	while ( i > 1 ) {
		i--;
		if ( TcodeNameZone[i] == ' ' )
			TcodeNameZone[i] = 0;
		else	break;
		}
	return( (BPTR) TcodeNameZone ); 

}

EXAWORD	program_has_been_optimised()
{
	return( (( ControlZone[18] & 0x0040 ) == 0x0040 ? VRAI : FAUX ) );
}



static	void	Libraries()
{
	EXAWORD	nb;

	EXAWORD	x;
	EXAWORD	l;
	EXAWORD	wdex;
	BPTR	wptr=(BPTR) 0;
	EXAWORD	blockid;
	EXAWORD	blocklen;
	EXAWORD	fcontrol;
	blockid  = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(24*WORDSIZE))));
	blocklen = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(25*WORDSIZE))));

	if ((blockid == MOINS_UN)
	||  (!( blockid))
	||  (blocklen== MOINS_UN))
		return;
	if (!(wptr = (BPTR) LoadBlock( Handle , blockid , blocklen )))
		return;

	/* Collect Function Count */
	/* ---------------------- */
	fcontrol = tcGetw( wptr );

	/* Initialise Table des fonctions Utilisateur */
	/* ------------------------------------------ */
	for ( x = 0, wdex = WORDSIZE; x < fcontrol; x++ ) {

		/* Collect and control Length of User Library Name */
		/* ----------------------------------------------- */
		if ((l = (strlen( (BPTR) (wptr + wdex) ) + 1)) > 1) {

			oputs( "#user ");
			oputs( (wptr+wdex) );
			oputs( ", ");
			DecimalWord( x );
			wdex += l;	
			oline();
			wdex += 18;
			}
		else	break;

		}

	free( wptr );
	return;
}


int main( argc , argv )
int	argc;
char *  argv[];
{
	EXAWORD	diezcons=0;
	EXAWORD	max_block_size;
	EXAWORD	d_image;
	EXAWORD	dcrypt;
	EXAWORD	blockid;
	EXAWORD	blocklen;
	EXAWORD	indent;
	EXAWORD	i,ai;
	BPTR	ListName;
	EXAWORD	compression;
	EXAWORD	before_compress;
	EXAWORD	tpds;
	BPTR	listcheck;

	listcheck = (BPTR) "L++ABAL++AO++";
	if ( *listcheck == 'L' )
		canliste = VRAI;
	else	canliste = FAUX;

	keep_procedures = FAUX;

	/* Initialise Messages */
	/* ------------------- */
	TalkWork();

	/* Initialise Tcode Salvage Mechanism */
	/* ---------------------------------- */
	initialise_recovery();

	/* Initialise all Option Variables */
	/* ------------------------------- */
	ResetOptions();

	/* Initialise Global Variables	*/
	/* ---------------------------	*/
	i = 1;	HeapSize = 0; diezheap = 0;

	/* Initialise Output stream Controller */
	/* ----------------------------------- */
	OutPutInit();

	ListName = (BPTR) 0;

	/* Analyse Optimiser Options */
	/* ------------------------- */
	while ( i < argc ) {

		/* If Command Line Option Indicator detected */
		/* ----------------------------------------- */
		if ( is_option_indicator( *(argv[i]) ) ) {

			/* Select Command Line Option */
			/* -------------------------- */
			switch ( *( argv[i] + 1 ) ) {
				case 'B' :
				case 'b' :
					set_ngf_buffer_flag();
					break;
					
				case 'K' :	
				case 'k' : 	diezcons = 1; 	break;

				case 'F' :
				case 'f' :	Options.CheckFmt = VRAI;
						break;
				case 'H' :
				case 'h' :	Options.Pannel 	= VRAI;
						if ( *( argv[i] + 2) == '1' ) {
							Options.Pannel = 2;
							ai++;
							}
						Options.Verbose = FAUX;
						break;

				/* Optimisation flag activation */
				/* ---------------------------- */
				case 'Z' :
				case 'z' :	ResetOptions(); break;


				case 'a' :
				case 'A' :	ResetOptions();
						Options.Analyse = (0x0080 | VRAI);
						ai = 2;
						while ( *( argv[i] + ai ) != (BYTE) 0 ) {
							switch ( *( argv[i] + ai ) ) {
								case 'p' :
								case 'P' : Options.Analyse |= 0x0002;
									   break;

								case 'x' :
								case 'X' : Options.Analyse |= 0x0004;
									   break;

								case 'f' :
								case 'F' : Options.Analyse |= 0x0008;
									   break;

								case 'v' :
								case 'V' : Options.Verbose = VRAI;
									   break;
										
								case 'C' :
								case 'c' : Options.Analyse |= 0x0040;
									   break;
																		   break;
										
								case 'm' :
								case 'M' : Options.Analyse |= 0x0020;
									   break;
								}
							ai++;
							}
						break;
				case 'o' :
				case 'O' :	Options.Optimise   = VRAI; 
						Options.Global     = VRAI; 
						Options.Constants  = VRAI;
						Options.Registers  = VRAI; 
						Options.Tables     = VRAI; 
						Options.Procedures = VRAI; 
						Options.Strip      = VRAI;
						Options.Analyse    = FAUX;
						ai = 2;
						while ( *( argv[i] + ai ) != (BYTE) 0 ) {
							switch ( *( argv[i] + ai ) ) {

								case 'h' :
								case 'H' : Options.Pannel  = VRAI;
									   Options.Verbose = FAUX;
									   if ( *( argv[i] + ai + 1) == '1' ) {
										Options.Pannel = 2;
										ai++;
										}
									   break;
								case 'v' :
								case 'V' : Options.Verbose   = VRAI; 
									   break;

								case 'n' :
								case 'N' : keep_procedures   = VRAI;
									   break;

								case '3' : Options.Segments  = VRAI;
								case '2' : Options.Inline    = VRAI; 
									   Options.Analyse   = 0x0002;
									   break; 

								case 'w' :
								case 'W' : Options.Warnings   = VRAI; 
									   break;
								}


							ai++;
							}
						break;

#ifdef	AO_COMPILER
				/* Compile to ASM output */
				/* --------------------- */
				case 'C' :
				case 'c' :	Options.Analyse = FAUX;
						/* Check for List file Explicite */
						/* ----------------------------- */
						if ( *((argv[i] + 2 )) != (BYTE) 0 ) {

							/* Attempt to Allocate Buffer for Storage */
							/* -------------------------------------- */
							if ((ListName = (BPTR) malloc( strlen( (BPTR) ( argv[i] + 2 ) ) + 1 )) != (BPTR) 0 ) {

								/* Copy list name to Storage Zone */
								/* ------------------------------ */
								memcpy((BPTR) ListName , (BPTR) (argv[i] + 2) , strlen( (BPTR) ( argv[i] + 2 ) ) + 1 );
								}
							}

						Options.Compile = VRAI; 
						Options.Verbose = FAUX;
					 	Options.Liste   = VRAI;
						Options.Strip   = FAUX; 
						break;

#endif	/* AO_COMPILER */
	/* ----------- */

				case 'D' :
				case 'd' :  	debug   = VRAI;
						/* Check for List file Explicite */
						/* ----------------------------- */
						if ( *((argv[i] + 2 )) != (BYTE) 0 ) {

							/* Attempt to Allocate Buffer for Storage */
							/* -------------------------------------- */
							if ((ListName = (BPTR) malloc( strlen( (BPTR) ( argv[i] + 2 ) ) + 1 )) != (BPTR) 0 ) {

								/* Copy list name to Storage Zone */
								/* ------------------------------ */
								memcpy((BPTR) ListName , (BPTR) (argv[i] + 2) , strlen( (BPTR) ( argv[i] + 2 ) ) + 1 );
								}
							}
						break;

#ifdef	AO_STATS
				case 's' :
				case 'S' :  	/* Statistiques du Tcode */
						/* --------------------- */
						Options.Stats   = STAT_VRAI; 
						Options.Compile = FAUX; 
						Options.Verbose = VRAI;
					 	Options.Liste   = FAUX;
						Options.Strip   = FAUX; 
						Options.Analyse = FAUX;
						ai = 2;
						while ( *( argv[i] + ai ) != (BYTE) 0 ) {
							switch ( *( argv[i] + ai ) ) {
								case 'h' :
								case 'H' : Options.Stats |= STAT_HEAD; break;
								case 'p' :
								case 'P' : Options.Stats |= STAT_PROC; break;
								case 's' :
								case 'S' : Options.Stats |= STAT_SEGM; break;
								case 'g' :
								case 'G' : Options.Stats |= STAT_GRAPH; break;
								case 'c' :
								case 'C' : Options.Stats |= STAT_CODE; break;
								}
							ai++; 
							}
						break;

#endif	/* AO_STATS */
	/* -------- */

#ifdef	AO_LISTFILE
				case 'x'	:
				case 'X'	:
					Options.Alliance=1;
					break;

				case 'l' :
				case 'L' :	if ( canliste ) {

							Options.Analyse = FAUX;

							/* Check for List file Explicite */
							/* ----------------------------- */
							if ( *((argv[i] + 2 )) != (BYTE) 0 ) {

								/* Attempt to Allocate Buffer for Storage */
								/* -------------------------------------- */
								if ((ListName = (BPTR) malloc( strlen( (BPTR) ( argv[i] + 2 ) ) + 1 )) != (BPTR) 0 ) {

									/* Copy list name to Storage Zone */
									/* ------------------------------ */
									memcpy((BPTR) ListName , (BPTR) (argv[i] + 2) , strlen( (BPTR) ( argv[i] + 2 ) ) + 1 );
									}
								}
							Options.Liste   = *( (argv[i] + 1 ) );
							Options.Verbose = FAUX; 
							Options.Strip   = FAUX; 
							}
						break;
#endif	/* AO_LISTFILE */
	/* ----------- */

				}

			i++;
			}
		else	{
			break;
			}
		}


#ifdef	AO_LISTFILE

	/* Check for Explicite list file */
	/* ----------------------------- */
	if ( ListName != (BPTR) 0 ) {

		/* Create and initialise list manager */
		/* ---------------------------------- */
		
		OutPutCreate( ListName );

		}
#endif

	/* No file so display banner */
	/* ------------------------- */
	if ( i == argc ) {
		module_identification();
		Options.Pannel = FAUX;
		}
	else 	{
		if ( Options.Pannel )
			initialise_control_pannel( Options.Pannel );
 		}

	/* Enter File List optimisation Loop */
	/* --------------------------------- */
	while ( i < argc ) {

		display_options();

		ProgramShrink = 0;
		CodeShrink    = 0;
		TableShrink   = 0;

		GlobalDataImage = (BPTR) 0;

		/* Attempt to Open Program File */
		/* ---------------------------- */
		if ((Handle = open((BPTR) construct_filename((BPTR) argv[i], (BPTR) ABAL_TRADUIT ) , OPENRW )) != -1) {
			if ( Options.Pannel )
				draw_source_file( construct_filename((BPTR) argv[i], (BPTR) ABAL_TRADUIT ) );
			}
		/* Attempt to Open Module File */
		/* --------------------------- */
		else if ((Handle = open((BPTR) construct_filename((BPTR) argv[i], (BPTR) ABAL_MODULE ) , OPENRW )) != -1) {
			if ( Options.Pannel )
				draw_source_file( construct_filename((BPTR) argv[i], (BPTR) ABAL_MODULE ) );
			}

		if ( Handle != -1 ) {
			/* Read in Contolling Sector */
			/* ------------------------- */
			lseek( Handle , 0L , SEEK_SET );
			if ( read( Handle , (BPTR) ControlZone , HEADERBLOCK ) == HEADERBLOCK ) {

#ifdef	VERSION666
				/* Ensure ABAL Version 2 */
				/* --------------------- */
				if ( ControlZone[0] == '3' )  
				{
					WORDSIZE = WORDSIZE32;
					ISLOCAL  = ISLOCAL4;
					TOGLOBAL  = TOGLOBAL4;
					MOINS_UN = MOINS_UN32;
				}
#ifdef ABAL64
				else if ( ControlZone[0] == '4' )  
				{
					WORDSIZE = WORDSIZE64;
					ISLOCAL  = ISLOCAL4;
					TOGLOBAL  = TOGLOBAL4;
					MOINS_UN = MOINS_UN64;
				}
#endif
				else if (( ControlZone[0] == '2' ) 	
				     ||  ( ControlZone[0] == '1' )) 
				{
					ISLOCAL  = ISLOCAL3;
					TOGLOBAL  = TOGLOBAL3;
					WORDSIZE = WORDSIZE16;
					MOINS_UN = MOINS_UN16;
				}
				else	
				{
#else
				/* Ensure ABAL Version 2 */
				/* --------------------- */
				if ( ControlZone[0] != '2' ) 
				{
#endif
					error_msg((BPTR) TalkPtr[8], (BPTR) argv[i] );

					/* Close the File Now */
					/* ------------------ */
					(void) close( Handle );
					i++;

					continue;

				}
 
				/* Unlock Control Sector */
				/* --------------------- */
				dcrypt = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(21*WORDSIZE))) );
				if (( dcrypt != 0 ) && ( dcrypt != MOINS_UN )) {
					(void) abal_crypt(dcrypt,(BPTR) (ControlZone + (TCPREFIX-2)),((21*WORDSIZE)+2),DECODE);
					}

 				/* Analyse Translator permissions byte */
				/* ----------------------------------- */
				switch ( ControlZone[19] ) {
					case 0 : break;
					case 1 : error_msg((BPTR) TalkPtr[3],(BPTR) argv[i] );
						 break;
					case 2 : error_msg((BPTR) TalkPtr[4], (BPTR) argv[i] );
						 break;
					case 3 : error_msg((BPTR) TalkPtr[5], (BPTR) argv[i] );
						 break;
					default: error_msg((BPTR) TalkPtr[6], (BPTR) argv[i] );
						 break;
					} 
				
				if ( Options.Optimise ) {

					/* Check for Already Optimised */
					/* --------------------------- */
					if ( program_has_been_optimised() ) {
						error_msg((BPTR) TalkPtr[7], (BPTR) argv[i] );
						ControlZone[19] = (BYTE) 4;
						}

					}

				/* Check for Repeat Possible */
				/* ------------------------- */
				switch ( ControlZone[19]  ) {
					case	0 :
					case	2 :
					case	1 :
					case	3 :
						break;
					default	  :
						/* Close the File Now */
						/* ------------------ */
						(void) close( Handle );
						i++;
						continue;
					}

				trad_ver = ControlZone[0];
				GlobalSymbolsSector = 0;

				if ( Options.Analyse )
					initialise_analysis();

				if ( Options.Stats & STAT_VRAI ) {
#ifdef	AO_STATS
					statistics_header((BPTR) construct_filename((BPTR) argv[i], (BPTR) ABAL_TRADUIT ));
#endif
					}
				else	{
					/* Display file name if Verbose Active */
					/* ----------------------------------- */
					if (( Options.Verbose ) || ( Options.Pannel ))
						status_message((BPTR) TalkPtr[2], program_tcode_name() );
					}

				/* Establish Block Control If Required */
				/* ----------------------------------- */
				if ( Options.Optimise )
					initialise_block_control();

				/* If Register optimisation */
				/* ------------------------ */
				if ( Options.Registers )
					initialise_shadower();

				DiezCharge();

#ifdef	AO_LISTFILE
				/* Display Program Syntax */
				/* ---------------------- */
				if ( Options.Liste ) {
					ProgStart( Options.Compile , diezheap , diezfile , dieztemp , diezpile );
					Libraries();
					}
#endif

#ifdef	AO_COMPILER
				/* Check for Compiler Active */
				/* ------------------------- */
				if ( Options.Compile )
					InitCompile();
#endif
				/* Attempt to Load Procedure Names */
				/* ------------------------------- */
				SymbolStatus = 0;
				if ( trad_ver < '2' )
					LoadProcedureNames(Handle,(tcGetw((((BPTR) ControlZone) + (TCPREFIX+(11*WORDSIZE))))));
				else	{
					initialise_symbols_manager(); 
					if ((SymbolStatus = activate_symbols_manager((BPTR) argv[i] )) == 0)
						liberate_symbols_manager();
					}

				/* Attempt to Load Global Constants Table */
				/* -------------------------------------- */
				if ((Options.Compile) || (Options.Liste) || (Options.Stats & STAT_CODE) || (Options.Optimise) || (Options.Analyse)) {

					/* Load Global Constant Table */
					/* -------------------------- */
					blockid  = tcSector( (((BPTR) ControlZone) + (TCPREFIX+(1*WORDSIZE))));
					blocklen = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(2*WORDSIZE))));
#ifdef	AO_STATS
					Stats.ConstantSize = blocklen;
					Stats.StartupSize += blocklen;
#endif
					if ((blockid != 0 ) && (blockid != MOINS_UN)) {
						if ((tcGKT = (BPTR) LoadBlock( Handle , blockid , blocklen )) == (BPTR) 0) {
							if (( Options.Verbose ) || ( Options.Pannel ))
								status_message( (BPTR) TalkPtr[16], (BPTR) "\0" );

							/* Close the File Now */
							/* ------------------ */
							(void) close( Handle );
							i++;
							continue;
							}
						tcGKL = blocklen;
						if (( diezcons )
						&&  ( Options.Liste )) {
							DumpConstantTable( tcGKT, tcGKL );
							}
						if ( Options.Constants ) {
							if ( initialise_constant_compression( blocklen ) == MOINS_UN )
								Options.Constants = FAUX;
							else	sectGKT = blockid;
							}
						else	{
							sectGKT = 0;
							} 
						}
					else	{
						tcGKT = (BPTR) 0;
						tcGKL = 0;
						}
					}
				else	{
					tcGKT = (BPTR) 0;
					tcGKL = 0;
					}
	
				/* Load Global Variable Table */
				/* -------------------------- */
				blockid  = tcSector( (((BPTR) ControlZone) + (TCPREFIX+(3*WORDSIZE))));
				blocklen = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(4*WORDSIZE))));

				if ((blockid != 0 ) && (blockid != MOINS_UN)) {

#ifdef	AO_STATS
					Stats.StartupSize += blocklen;
					Stats.TotalTableSize += blocklen;
					Stats.GlobalTableSize = blocklen;
#endif
					if ((tcGDT = (BPTR) LoadBlock( Handle , blockid , blocklen )) == (BPTR) 0) {
						if (( Options.Verbose ) || ( Options.Pannel ))
							status_message( (BPTR) TalkPtr[17],(BPTR) "\0" );

						/* Close the File Now */
						/* ------------------ */
						(void) close( Handle );
						i++;
						continue;
						}
#ifdef	AO_STATS
					Stats.GlobalDataSize = (EXAWORD) (tcGetw((tcGDT+(2*WORDSIZE))));
					Stats.StartupSize   += Stats.GlobalDataSize;
#endif
					/* Check for table compression */
					/* --------------------------- */
					if (( Options.Tables ) && ( Options.Global )) {

						/* Allocate a block for new GDT image */
						/* ---------------------------------- */
						if (( newGDT = MakeBlock( blocklen )) == (BPTR) 0)
							Options.Tables = FAUX;

						/* Prepare Global Data Image */
						/* ------------------------- */
						if ( Options.Strip ) {

							/* Check for Data image already present */
							/* ------------------------------------ */
							d_image = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(28*WORDSIZE))) );
							if ((d_image == 0) || ( d_image == MOINS_UN )) {
								if ( CreateGlobalDataImage( tcGDT ) == FAUX ) {
#ifdef	BEFORE_09091994
									status_message( (BPTR) TalkPtr[18],(BPTR) "\0" );
									/* Close the File Now */
									/* ------------------ */
									(void) close( Handle );
									i++;
									continue;
#endif
									}
								}
							else	{
								Options.Global = FAUX;
								}
							}

						GlobalSymbolsSector = tcGetw((tcGDT + WORDSIZE));

						/* Initialise New Data Table */
 						/* ------------------------- */
						TableInit( tcGDT , newGDT, 0 );

						/* Watch out for and Convert ARG */
						/* ----------------------------- */
						d_image = tcGetw( (((BPTR) ControlZone) + TCPREFIX) );
						if ((d_image != 0) && ( d_image != MOINS_UN )) {

							/* Convert the ARG variable */
							/* ------------------------ */
							d_image = convert_variable_identifier( tcGDT , newGDT , d_image );

							/* And patch into tcode header */
							/* --------------------------- */
							tcPutw( (((BPTR) ControlZone) + TCPREFIX) , d_image );
							}
						}
					else	{
						newGDT = (BPTR) 0;
						}

#ifdef	AO_LISTFILE
					/* Check for list output */
					/* --------------------- */
					if (Options.Liste ) {
						if ( trad_ver < '2' )
						 	tcGNT = (BPTR) NameTable( tcGDT );
						DataTable( tcGDT , Options.Compile ,tcGNT, 0 );
						}
					else	{
						tcGNT = (BPTR) 0;
						}
#else
						tcGNT = (BPTR) 0;
#endif

					}
				else	{
					tcGDT  = (BPTR) 0;
					tcGNT  = (BPTR) 0;
					newGDT = (BPTR) 0;
					}


				/* Load Procedure Control Infos */
				/* ---------------------------- */
				blockid  = tcSector( (((BPTR) ControlZone) + (TCPREFIX+(9*WORDSIZE))));
				blocklen = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(10*WORDSIZE))));

				BlockChange = 0;

				/* Evaluate Existance of Procedures */
				/* -------------------------------- */
            if (( blockid != 0 ) && ( blocklen != 0 )) {
#ifdef   AO_STATS               
               Stats.StartupSize += blocklen;
               Stats.TotalTableSize += blocklen;

               if ( Options.Stats & STAT_PROC )
                  LocalDataPtr = (WPTR) malloc( (blocklen / (8*WORDSIZE)) * (WORDSIZE));
               else
                  LocalDataPtr = (WPTR) 0;
#endif

               /* Load Procedure Control Table */
               /* ---------------------------- */
               if ((tc_PDT = (BPTR) LoadBlock( Handle , blockid , blocklen )) != (BPTR) 0) {

                  /* Perform Procedure Optimisations */
                  /* ------------------------------- */
                  indent = 0; ln_PDT = blocklen;

                  /* Indicate Procedure Phase */
                  /* ------------------------ */
                  MasterPhase = 0;

                  /* While Not End of Table */
                  /* ---------------------- */
                  while ( indent < ln_PDT ) {

                     /* Check for Valid Procedure ID */
                     /* ---------------------------- */
                     if ((PrcId = tcGetw((tc_PDT + indent))) == MOINS_UN) {
                        break;
                        }

                     if ( Options.Verbose )
                        procedure_verbose( indent );


                     /* If Procedure Elimination not required : FORCE INCLUSION */
                     /* ------------------------------------------------------- */
                     if (! (Options.Procedures) ) {
                        PrcId = tcGetw((tc_PDT + indent + (7*WORDSIZE)));
                        PrcId |= PROCEDURE_USED;
                        tcPutw(((BPTR) (tc_PDT + indent + (7*WORDSIZE))),PrcId);
                        }

                     PrcId    = indent;
                     blockid  = tcSector((tc_PDT + indent + (2*WORDSIZE)));
                     blocklen = tcGetw((tc_PDT + indent + (3*WORDSIZE)));
                     if (( blocklen != 0 ) && ( blockid != 0 )) {
#ifdef   AO_STATS                  
                        Stats.StartupSize += blocklen;
                        Stats.TotalTableSize += blocklen;
                        Stats.ProcCount++;
                        Stats.ProcTableSize += blocklen;

                        if ( blocklen > Stats.LargestProcTable )
                           Stats.LargestProcTable = blocklen;

#endif
                        /* Attempt to Load the Procedure Variable Table */
                        /* ------------------------------------------ */
                        if ((tcLDT = LoadBlock(Handle,blockid,blocklen)) == (BPTR) 0) {
                           break;
                           }
#ifdef   AO_STATS
                        tpds = (EXAWORD) (tcGetw((tcLDT+(2*WORDSIZE))));
                        if ( LocalDataPtr != (WPTR) 0)
                           *(LocalDataPtr + (indent/(8*WORDSIZE))) = tpds; 

                        Stats.ProcDataSize += tpds;
                        if ( tpds > Stats.LargestProcData )
                           Stats.LargestProcData = tpds;
#endif
                        
                        /* Check for Table compression */
                        /* --------------------------- */
                        if (Options.Tables ) {
                           if ((newLDT = MakeBlock( blocklen )) == (BPTR) 0) {
                              free( tcLDT );
                              tcLDT = (BPTR) 0;
                              break;
                              }
                           LocalSymbolsSector = tcGetw((tcLDT+WORDSIZE));
                           TableInit( tcLDT , newLDT, 0x8000 );
                           if (( SymbolStatus ) && ( LocalSymbolsSector != 0 ))
                              collect_local_variables( 1, indent);
                           }
                        else   {
                           newLDT = (BPTR) 0;
                           LocalSymbolsSector = 0;
                           }
                        tcLNT = (BPTR) 0;
                        if ( Options.Liste ) {
                           LocalSymbolsSector = tcGetw((tcLDT+WORDSIZE));
                           if ( trad_ver < '2' )
                              tcLNT = (BPTR) NameTable( tcLDT );
                           else if ((SymbolStatus) && ( LocalSymbolsSector != 0 ) && (!Options.Tables))
                              collect_local_variables( 1, indent);
                           }
                        }
                     else   {
                        tcLDT = (BPTR) 0;
                        tcLNT = (BPTR) 0;
#ifdef   AO_STATS
                        if ( LocalDataPtr != (WPTR) 0)
                           *(LocalDataPtr + (indent/(8*WORDSIZE))) = 0;
#endif
                        newLDT = (BPTR) 0;
                        }
                     blockid  = tcSector((tc_PDT + indent + (4*WORDSIZE)));
                     blocklen = tcGetw((tc_PDT + indent + (5*WORDSIZE)));
                     if ((blocklen != 0) && ( blockid != 0)) {
                        if ((tcLCT = LoadBlock(Handle,blockid,blocklen)) == (BPTR) 0) {
                           break;
                           }
                        Options.Constants = FAUX;
                        }
                     else   tcLCT = (BPTR) 0;

                     blockid  = tcSector((tc_PDT + indent + 0));
                     blocklen = tcGetw((tc_PDT + indent + WORDSIZE));
                     statix   = tcGetw((tc_PDT + indent + (7*WORDSIZE)));

                     /* Ensure Procedure code block exists */
                     /* ---------------------------------- */
                     if ((blocklen != 0) && ( blockid != 0)) {
#ifdef   AO_STATS
                        Stats.StartupSize += blocklen;
                        Stats.ProcCodeSize += blocklen;
                        if ( blocklen < Stats.SmallestProc )
                           Stats.SmallestProc = blocklen;
                        if ( blocklen > Stats.LargestProc )
                           Stats.LargestProc = blocklen;
#endif
                        /* Attempt to Load the Procedure */
                        /* ----------------------------- */
                        if ((tcCS = LoadBlock(Handle,blockid,blocklen)) == (BPTR) 0) {
                           break;
                           }

                        BlockLen = blocklen;

                        /* Optimise the Procedure Code */
                        /* --------------------------- */
                        if ( Optimiser((BPTR) tcCS , blocklen ) != 0) {

                           /* Check for Procedure Size Change */
                           /* ------------------------------- */
                           if ( BlockLen != blocklen ) {
   
                              /* Modify Table */
                              /* ------------ */
                              tcPutw((tc_PDT + indent + WORDSIZE) , BlockLen);
                              BlockChange = 1;
                              }
   
                           /* ReWrite the Procedure Code */
                           /* -------------------------- */
                           WriteBlock(Handle,(BPTR) tcCS,blockid,BlockLen);
   

                           /* Display Message */
                           /* --------------- */
                           CodeOptimized(0,PrcId, blocklen , BlockLen );
                           }
                        else   {
                           BlockLen = blocklen;
                           }
      
                        /* Check for Inline Analysis Required */
                        /* ---------------------------------- */
                        if ( Options.Inline )
                           Analyser((BPTR) tcCS, 0, BlockLen );

                        /* Liberate the Procedure */
                        /* ---------------------- */
                        free((BPTR) tcCS );

                        /* Check for Table Compression */
                        /* --------------------------- */
                        if (( Options.Tables ) && ( newLDT != (BPTR) 0 )) {

                           before_compress = tcGetw((tc_PDT + indent + (3*WORDSIZE)));
                           compression = data_table_compression( newLDT , tcLDT, tcLNT );
                           StoreTcodeWord((tcLDT + WORDSIZE),LocalSymbolsSector );
                           WriteBlock( Handle , tcLDT , (tcGetw((tc_PDT + indent + (2*WORDSIZE)))) , compression );
                           StoreTcodeWord((tc_PDT + indent + (3*WORDSIZE)), compression);
                           BlockChange = 1;
                           if ( SymbolStatus )
                              rewrite_local_variables( LocalSymbolsSector );
                           TableOptimized(2,PrcId, before_compress , compression );
                              
                           /* Then liberate local new table */
                           /* ----------------------------- */
                           if ( newLDT != (BPTR) 0 ) {
                              free( newLDT );
                              newLDT = (BPTR) 0;
                              }
                           }
      
                        /* Liberate Local Names if Loaded */
                        if ( tcLDT != (BPTR) 0 ) {
                        /* ------------------------------ */
                           if ( tcLNT != (BPTR) 0 ) {
                              free((BPTR) tcLNT );
                              tcLNT = (BPTR) 0;
                              }
                           if (( trad_ver > '1' ) && (SymbolStatus) && (LocalSymbolsSector != 0))
                              release_local_variables();
                           }

                        /* Liberate Local Table if Loaded */
                        /* ------------------------------ */
                        if ( tcLDT != (BPTR) 0 ) {
                           free((BPTR) tcLDT );
                           tcLDT = (BPTR) 0;
                           }
                        }

                     if ( tcLCT != (BPTR) 0 ) {
                        free( tcLCT );
                        tcLCT = (BPTR) 0;
                        }

                     /* Next Table Entry */
                     /* ---------------- */
                     indent += (8*WORDSIZE);
                     }

                  /* Check for Table Changed */
                  /* ----------------------- */
                  if ( BlockChange != 0 ) 

                     /* Save Procedure Control Infos */
                     /* ---------------------------- */
                     rewrite_procedure_table();

                  BlockChange = 0;

#ifdef   AO_STATS
                  procedure_statistics();
#endif

                  }
               else   status_message( (BPTR) TalkPtr[19], "\0" );
               }

            /* Enter Segment Mode */
            /* ------------------ */
            MasterPhase = 1;   

            /* Load Segment Control Table */
            /* -------------------------- */
            blockid  = tcSector( (((BPTR) ControlZone) + (TCPREFIX+(7*WORDSIZE))));
            blocklen = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(8*WORDSIZE))));

            if ((tc_SDT = (BPTR) LoadBlock( Handle , blockid , blocklen )) != (BPTR) 0) {

#ifdef   AO_STATS
               if ( Options.Stats & STAT_SEGM )
                  LocalDataPtr = (WPTR) malloc( (blocklen / (16*WORDSIZE)) * WORDSIZE);
               else
                  LocalDataPtr = (WPTR) 0;

               Stats.StartupSize += blocklen;
               Stats.TotalTableSize += blocklen;
#endif

               /* Perform Code Optimisation */
               /* ------------------------- */
               /* Enter Segment Handling Loop */
               /* --------------------------- */
               indent = 0; ln_SDT = blocklen;

               /* While Not End of Table */
               /* ---------------------- */
               while ( indent < ln_SDT ) {

                  /* Check for Valid Segment ID */
                  /* -------------------------- */
                  if ((SegId = tcGetw((tc_SDT + indent))) == MOINS_UN) {
                     break;
                     }
#ifdef   AO_STATS
                  Stats.SegmCount++;
#endif
                  if ( Options.Verbose ) 
                     segment_verbose( SegId );

                  blockid  = tcSector((tc_SDT + indent + (3*WORDSIZE)));
                  blocklen = tcGetw((tc_SDT + indent + (4*WORDSIZE)));
                  statix   = tcGetw((tc_SDT + indent + (5*WORDSIZE)));

                  if (( blocklen != 0 ) && ( blockid != 0 )) {
#ifdef   AO_STATS

                     Stats.TotalTableSize += blocklen;
                     Stats.SegmTableSize  += blocklen;
                     if ( blocklen > Stats.OverlayData )
                        Stats.OverlayData = blocklen;
#endif
                     /* Attempt to Load the Segment Variable Table */
                     /* ------------------------------------------ */
                     if ((tcLDT = LoadBlock(Handle,blockid,blocklen)) == (BPTR) 0) {
                        break;
                        }

#ifdef   AO_STATS
                     tpds = (EXAWORD) (tcGetw((tcLDT+(2*WORDSIZE))));
                     if ( LocalDataPtr != (WPTR) 0)
                        *(LocalDataPtr + (indent/(16*WORDSIZE))) = tpds; 
                     Stats.SegmDataSize += tpds;
                     if ( tpds > Stats.LargestSegmData )
                        Stats.LargestSegmData = tpds;
#endif

                     /* Check for Table compression */
                     /* --------------------------- */
                     if (Options.Tables ) {
                        if ((newLDT = MakeBlock( blocklen )) == (BPTR) 0) {
                           free( tcLDT );
                           tcLDT = (BPTR) 0;
                           break;
                           }
                        LocalSymbolsSector = tcGetw((tcLDT+WORDSIZE));
                        TableInit( tcLDT , newLDT, 0x8000 );
                        if (( SymbolStatus ) && (LocalSymbolsSector != 0))
                           collect_local_variables( 0, SegId);
                        }
                     else   {
                        newLDT = (BPTR) 0;
                        LocalSymbolsSector = 0;
                        }

                     tcLNT = (BPTR) 0;
                     if  ( Options.Liste )  {
                           LocalSymbolsSector = tcGetw((tcLDT+WORDSIZE));
                        if ( trad_ver < '2' )
                           tcLNT = (BPTR) NameTable( tcLDT );
                        else if (( SymbolStatus ) && (LocalSymbolsSector != 0) && (! Options.Tables))
                           collect_local_variables(0, SegId);
                        }
                     }
                  else   {
                     tcLDT  = (BPTR) 0;
                     tcLNT  = (BPTR) 0;
                     newLDT = (BPTR) 0;
                     }

                  blockid  = tcSector((tc_SDT + indent + (6*WORDSIZE)));
                  blocklen = tcGetw((tc_SDT + indent + (7*WORDSIZE)));
                  if (( blocklen != 0 ) && ( blockid != 0 )) {
                     /* Attempt to Load the Segment Constant Table */
                     /* ------------------------------------------ */
                     if ((tcLCT = LoadBlock(Handle,blockid,blocklen)) == (BPTR) 0) {
                        break;
                        }
                     Options.Constants = FAUX;
                     }
                  else   tcLCT = (BPTR) 0;

                  blockid  = tcSector((tc_SDT + indent + WORDSIZE));
                  blocklen = tcGetw((tc_SDT + indent + (2*WORDSIZE)));

                  if (( blockid != 0 ) && ( blockid != MOINS_UN )) {

#ifdef   AO_STATS   
                     Stats.SegmCodeSize += blocklen;
                     if ( blocklen < Stats.SmallestSegm )
                        Stats.SmallestSegm = blocklen;
                     if ( blocklen > Stats.LargestSegm )
                        Stats.LargestSegm = blocklen;
                     if ( blocklen > Stats.OverlayCode )
                        Stats.OverlayCode = blocklen;
#endif
   
                     /* Attempt to Load the Segment */
                     /* --------------------------- */
                     if ((tcCS = LoadBlock(Handle,blockid,blocklen)) == (BPTR) 0) {
                        break;
                        }

                     BlockLen = blocklen;

                     /* Optimise the Segment Code */
                     /* ------------------------- */
                     if (Optimiser((BPTR) tcCS , blocklen ) != 0) {   
   
                        /* Check for Segment Size Change */
                        /* ----------------------------- */
                        if ( BlockLen != blocklen ) {
   
                           /* Modify Table */
                           /* ------------ */
                           tcPutw((tc_SDT + indent + (2*WORDSIZE)) , BlockLen);
                           BlockChange = 1;
                           }

                        /* ReWrite the Segment */
                        /* ------------------- */
                        WriteBlock(Handle,(BPTR) tcCS,blockid,BlockLen);


                        /* Display Message */
                        /* --------------- */
                        CodeOptimized(1,SegId, blocklen , BlockLen );
                        }
                     else   BlockLen = blocklen;

                     /* Check for Inline Analysis Required */
                     /* ---------------------------------- */
                     if ( Options.Inline )
                        Analyser((BPTR) tcCS, 0, BlockLen );

                     /* Liberate the Segment */
                     /* -------------------- */
                     free((BPTR) tcCS );

                     }

                  /* Check for table compression */
                  /* --------------------------- */
                  if (( Options.Tables ) && ( newLDT != (BPTR) 0)) {

                     before_compress = tcGetw((tc_SDT + indent + (4*WORDSIZE)));
                     compression = data_table_compression( newLDT , tcLDT, tcLNT );

                     /* Terminate modified table */
                     /* ------------------------ */
                     StoreTcodeWord((tcLDT + WORDSIZE),LocalSymbolsSector );
                     WriteBlock( Handle , tcLDT , (tcGetw((tc_SDT + indent + (3*WORDSIZE)))) , compression );
                     StoreTcodeWord((tc_SDT + indent + (4*WORDSIZE)), compression );
                     BlockChange = 1;
                     if ( SymbolStatus )
                        rewrite_local_variables( LocalSymbolsSector );
                     TableOptimized(3,SegId, before_compress , compression );

                     /* Then liberate the new table */
                     /* --------------------------- */
                     if ( newLDT != (BPTR) 0) {
                        free((BPTR) newLDT );
                        newLDT = (BPTR) 0;
                        }

                     }

                  /* Liberate Local Names if Loaded */
                  /* ------------------------------ */
                  if ( tcLDT != (BPTR) 0 ) {
                     if ( tcLNT != (BPTR) 0 ) {
                        free((BPTR) tcLNT );
                        tcLNT = (BPTR) 0;
                        }
                     if (( trad_ver > '1' ) && (SymbolStatus) && (LocalSymbolsSector != 0))
                        release_local_variables();
                     }

                  /* Liberate Local Table if Loaded */
                  /* ------------------------------ */
                  if ( tcLDT != (BPTR) 0 ) {
                     free((BPTR) tcLDT );
                     tcLDT = (BPTR) 0;
                     }

                  /* Liberate Local Table if Loaded */
                  /* ------------------------------ */
                  if ( tcLCT != (BPTR) 0 ) {
                     free((BPTR) tcLCT );
                     tcLCT = (BPTR) 0;
                     }

                  /* Next Table Entry */
                  /* ---------------- */
                  indent += (12*WORDSIZE);
                  }

               /* Check for Table Changed */
               /* ----------------------- */
               if ( BlockChange != 0 ) {

                  /* Save Segment Control Infos */
                  /* -------------------------- */
                  blockid  = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(7*WORDSIZE))));
                  blocklen = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(8*WORDSIZE))));
                  WriteBlock(Handle,(BPTR) tc_SDT,blockid,blocklen);

                  }

               BlockChange = 0;

#ifdef   AO_STATS
               /* Output Segment Statistics */
               /* ------------------------- */
               segment_statistics();
#endif


               }
            else   status_message( (BPTR) TalkPtr[20],(BPTR) "\0" );

            /* Check for Table compression */
            /* --------------------------- */
            if (( Options.Tables ) && ( newGDT != (BPTR) 0)) {

               /* Terminate modified table */
               /* ------------------------ */
               before_compress = tcGetw( (((BPTR) ControlZone) + (TCPREFIX+(4*WORDSIZE))) );
               compression = data_table_compression( newGDT , tcGDT, tcGNT );
               StoreTcodeWord((tcGDT + WORDSIZE),GlobalSymbolsSector );
               WriteBlock( Handle , tcGDT , (tcGetw((((BPTR) ControlZone) + (TCPREFIX+(3*WORDSIZE))))) ,compression );
               StoreTcodeWord((((BPTR) ControlZone) + (TCPREFIX+(3*WORDSIZE))),compression);
               if ( SymbolStatus )
                  rewrite_global_variables( GlobalSymbolsSector );
               TableOptimized(4,0, before_compress , compression );

               /* Then liberate the new table */
               /* --------------------------- */
               if ( newGDT != (BPTR) 0) {
                  free((BPTR) newGDT );
                  newGDT = (BPTR) 0;
                  }
               }

            /* Liberate Global Names if Loaded */
            /* ------------------------------- */
            if ( tcGNT != (BPTR) 0) {
               free((BPTR) tcGNT );
               tcGNT = (BPTR) 0;
               }

            /* Liberate Global Table if Loaded */
            /* ------------------------------- */
            if ( tcGDT != (BPTR) 0) {
               free((BPTR) tcGDT );
               tcGDT = (BPTR) 0;
               }

            /* Liberate Constants Table if Loaded */
            /* ---------------------------------- */
            if ( tcGKT != (BPTR) 0) {

               free((BPTR) tcGKT );
               tcGKT = (BPTR) 0;
   
               /* Check for Constant Table Update Required */
               /* ---------------------------------------- */
               if ( Options.Constants ) {
                  blocklen = terminate_constant_compression( Handle, sectGKT );
                  tcPutw( (((BPTR) ControlZone) + (TCPREFIX+(2*WORDSIZE))) , blocklen );
                  ProgramShrink += (tcGKL - blocklen); 
                  }

               tcGKL = 0;

               }

            display_options();

            /* Perform Analysis Report if Required */
            /* ----------------------------------- */
            if ( Options.Analyse )
               terminate_analysis(Handle);


            /* Liberate Constants table */
            /* ------------------------ */
            if ( tcGKT != (BPTR) 0 ) {
               free( tcGKT );
               tcGKT = (BPTR) 0;
               }

            /* Attempt to Copy to Compressed File */
            /* ---------------------------------- */
            if ( Options.Optimise ) {

               if ( tc_PDT != (BPTR) 0 )
                  rewrite_procedure_table();
               if ( tc_SDT != (BPTR) 0 )
                  rewrite_segment_table();

               /* Liberate Procedure Names Table */
               /* ------------------------------ */
               if (( trad_ver > '1' ) && ( SymbolStatus))
                  liberate_symbols_manager();

               Handle = CopyFile(Handle,(BPTR) argv[i] );
               SymbolStatus = 0; 
               }


            /* Liberate Block Control if Active */
            /* -------------------------------- */
            if ( Options.Optimise )
               terminate_block_control();

            /* Liberate Procedure Control Table */
            /* -------------------------------- */
            if ( tc_PDT != (BPTR) 0 ) {
               free( (BPTR) tc_PDT );
               tc_PDT = (BPTR) 0;
               }

            /* Liberate Segment Control Table */
            /* ------------------------------ */
            if ( tc_SDT != (BPTR) 0 ) {
               free( (BPTR) tc_SDT );
               tc_SDT = (BPTR) 0;
               }

            /* Liberate Procedure Names Table */
            /* ------------------------------ */
            if (( trad_ver > '1' ) && ( SymbolStatus))
               liberate_symbols_manager();

            else   {
               if ( tcPNT != (BPTR) 0 ) {
                  free( (BPTR) tcPNT );
                  tcPNT = (BPTR) 0;
                  }
               }

            /* Check for and liberate Global Data Image */
            /* ---------------------------------------- */
            if (( Options.Global ) && ( GlobalDataImage != (BPTR) 0)) {
               free( GlobalDataImage );
               GlobalDataImage = (BPTR) 0;
               }

#ifdef   AO_LISTFILE
            /* Display Program Syntax */
            /* ---------------------- */
            if ( Options.Liste )
               ProgEnd( Options.Compile );
#endif

#ifdef   AO_COMPILER
            /* Check for Compiler Active */
            /* ------------------------- */
            if ( Options.Compile ) 
               EndCompile();
#endif

            /* Indicate total size change */
            /* -------------------------- */
            if (( Options.Verbose ) && ( Options.Optimise )) {
               LineFeed(); oputs((BPTR) TalkPtr[21] );
               oputs((BPTR) construct_filename((BPTR) argv[i], (BPTR) ABAL_TRADUIT ) );
               oputs((BPTR) " : ");
               oputs((BPTR) TalkPtr[22] );
               HexAdresse( ProgramShrink );
               oputs((BPTR) " : Code ");
               HexAdresse( CodeShrink );
               oputs((BPTR) " + Tables ");
               HexAdresse( TableShrink );
               LineFeed();
               redundancy_information();
               }

            }
         else   status_message((BPTR) TalkPtr[23], "\0" );

      	/* Close the File Now */
			/* ------------------ */
			(void) close( Handle );
			}
		else	status_message( (BPTR) TalkPtr[24], (BPTR) construct_filename((BPTR) argv[i], (BPTR) ABAL_TRADUIT ) );


		/* If Register optimisation */
		/* ------------------------ */
		if ( Options.Registers )
			terminate_shadower();

#ifdef	AO_STATS
		if ( Options.Stats & STAT_HEAD )
			output_statistics();
#endif

		/* Next Arguament Index */
		/* -------------------- */
		i++;
		}

#ifdef	AO_LISTFILE

	/* Check for List file is in use */
	/* ----------------------------- */
	if ( ListName != (BPTR) 0 ) {

		/* Close and liberate list file */
		/* ---------------------------- */
		OutPutClose();

		free ( (BPTR) ListName );
		}

#endif
	/* Liberate all Tcode Salvage Mechanisms */
	/* ------------------------------------- */
	terminate_recovery();

	/* Return to Caller */
	/* ---------------- */
	if ( Options.Pannel )
		terminate_control_pannel();

#ifdef	VMS
	return(1);
#else
	return(0);
#endif

}

#endif	/* _OPTIMISE_C */
	/* ----------- */

