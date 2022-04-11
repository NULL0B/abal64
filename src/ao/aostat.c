/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1994 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AOSTAT.C   				*/
/*		Version :	2.1b					*/
/*		Date	:	11/05/1994				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AOSTAT_C
#define	_AOSTAT_C

#define	AO_STATS

#include "aomain.h"
#include "aostat.h"

extern	EXAWORD	diezheap;
extern 	EXAWORD	dieztemp;
extern 	EXAWORD	diezfile;
extern 	EXAWORD	diezpile;
extern	EXAWORD	max_block_size;
extern 	EXAWORD	ln_PDT;
extern 	EXAWORD	PrcId;
extern	BPTR	tc_PDT;
extern	BYTE	ControlZone[256];
extern 	EXAWORD	ln_SDT;
extern 	EXAWORD	SegId;
extern	BPTR	tc_SDT;

void	reset_statistics()
{
	memset((BPTR) & Stats, 0 , sizeof( struct tcode_stats ) );
	Stats.SmallestProc 	= 0xFFFF;
	Stats.SmallestSegm 	= 0xFFFF;
	return;
}

void	mf_gener( compte , valeur )
EXAWORD	compte;
EXAWORD	valeur;
{
	while ( compte != 0 ) {
		StreamByte( valeur );
		compte--;
		}
	return;
}

void	statistics_header( filename )
BPTR	filename;
{
	StreamLine(); 	mf_gener(78,'-');
	StreamLine(); 	StreamString((BPTR) " ABAL Tcode Statistical Analysis : ");
		    	StreamString((BPTR) filename );
			if ( program_has_been_optimised() )
				StreamString((BPTR) ", Optimised" );
	StreamLine(); 	mf_gener(78,'-');

	reset_statistics();
	return;
}

void	output_statistics()
{

	Stats.StartupSize += diezheap;
	Stats.StartupSize += dieztemp;
	Stats.StartupSize += (long)(( diezfile) * 32);
	Stats.StartupSize += (long)(( diezpile) * 6);
	Stats.StartupSize += (long) Stats.OverlayCode;
	Stats.StartupSize += (long) Stats.OverlayData;

	Stats.TotalCodeSize = Stats.ProcCodeSize + Stats.SegmCodeSize;
	Stats.TotalDataSize = Stats.ProcDataSize + Stats.SegmDataSize;
	
	StreamLine();	StreamString((BPTR) "                                             Totaux           ");
	StreamLine();	StreamString((BPTR) "              Nombre  Min.   Max.    Code    Tables  Donnees  ");
	StreamLine();	mf_gener( 78 , '-' );
	StreamLine();	StreamString((BPTR) " Procedures : ");
			HexAdresse( Stats.ProcCount );
			HexAdresse( Stats.SmallestProc );
			HexAdresse( Stats.LargestProc  );
			HexLong   ( Stats.ProcCodeSize );
			HexLong   ( Stats.ProcTableSize);
			HexLong   ( Stats.ProcDataSize );

	StreamLine();	StreamString((BPTR) " Segments   : ");
			HexAdresse( Stats.SegmCount    );
			HexAdresse( Stats.SmallestSegm );
			HexAdresse( Stats.LargestSegm  );
			HexLong   ( Stats.SegmCodeSize );
			HexLong   ( Stats.SegmTableSize);
			HexLong   ( Stats.SegmDataSize );

	StreamLine();	StreamString((BPTR) " Overlay    :                          ");
			HexWord   (Stats.OverlayCode );
			StreamString((BPTR) "     ");
			HexWord   (Stats.OverlayData );

	StreamLine();	mf_gener( 78 , '-' );
	StreamLine();	StreamString((BPTR) " Totaux     :                      ");
			HexLong   ( Stats.TotalCodeSize );
			HexLong   ( Stats.TotalTableSize );
			HexLong   ( Stats.TotalDataSize );
	StreamLine();	mf_gener( 78 , '-' );

	StreamLine();	StreamString((BPTR)  " #MEM ");   HexAdresse( dieztemp );
			StreamString((BPTR) "  #HEAP ");  HexAdresse( diezheap );
			StreamString((BPTR) "  #STACK "); HexAdresse( diezpile );
			StreamString((BPTR) "  #FILES "); HexAdresse( diezfile );
	StreamLine();	mf_gener( 78 , '-' );

	StreamLine();	StreamString((BPTR) " Taille totale des constants    : ");
			HexAdresse( Stats.ConstantSize );
	StreamLine();	StreamString((BPTR) " Taille Table Variable Globaux  : ");
			HexAdresse( Stats.GlobalTableSize );
	StreamLine();	StreamString((BPTR) " Taille d'allocation Globaux    : ");
			HexAdresse( Stats.GlobalDataSize );
	StreamLine();	mf_gener( 78 , '-' );

	StreamLine();	StreamString((BPTR) " Memoire de chargement          : ");
			HexLong   ( Stats.StartupSize );
	StreamLine();	mf_gener( 78 , '-' );
	StreamLine();

	return;

}

EXAWORD	overlay_code_size()
{
	return( Stats.OverlayCode );
}

EXAWORD	overlay_data_size()
{
	return( Stats.OverlayData );
}

void	procedure_statistics()
{
	EXAWORD	indent;
	EXAWORD	blocklen;
	EXAWORD	max_block_size;

	/* Check for Stats Graph required for procedures */
	/* --------------------------------------------- */
	if ( Options.Stats & STAT_PROC) {

		StreamLine(); StreamString((BPTR) "Procedures");

		if ( ! (Options.Stats & STAT_GRAPH ) )
			StreamString((BPTR) "   CODE   LDT    LDS");

		StreamLine(); mf_gener( 78,'-' );

		/* While Not End of Table */
		/* ---------------------- */
		indent = 0;

		if ( Stats.LargestProc > Stats.LargestProcData )
			max_block_size = Stats.LargestProc;
		else	max_block_size = Stats.LargestProcData;
		
		if ( Stats.LargestProcTable > max_block_size )
			max_block_size = Stats.LargestProcTable;

		while ( indent < ln_PDT ) {

			/* Check for Valid Procedure ID */
			/* ---------------------------- */
			if ((PrcId = tcGetw((tc_PDT + indent))) == MOINS_UN) {
				break;
				}

			blocklen = tcGetw((tc_PDT + indent + 2));

			if ( blocklen == 0 ) {
				indent += 16;
				continue;
				}

			StreamLine(); StreamString((BPTR) "PROC "); HexAdresse( indent );

			if ( Options.Stats & STAT_GRAPH ) {
				StreamLine(); mf_gener(5,' '); HexAdresse( blocklen );
				mf_gener(((blocklen*60)/max_block_size)+1, 'C' );
				}
			else	HexAdresse( blocklen );


			blocklen = tcGetw((tc_PDT + indent + 6));

			if ( Options.Stats & STAT_GRAPH ) {

				if ( blocklen != 0 ) {
					StreamLine(); mf_gener(5,' '); HexAdresse( blocklen );
					mf_gener(((blocklen*60)/max_block_size)+1, 'T' );
					}
				}
			else	HexAdresse( blocklen );

			if ( LocalDataPtr != (WPTR) 0 ) {

				blocklen = *(LocalDataPtr + (indent / 16));

				if ( Options.Stats & STAT_GRAPH ) {

					if ( blocklen != 0 ) {
						StreamLine(); mf_gener(5,' '); HexAdresse( blocklen );
						mf_gener(((blocklen*60)/max_block_size)+1, 'D' );
						}
					}
				else	HexAdresse( blocklen );
				}

			indent += 16;
			}

		StreamLine(); mf_gener( 78,'-' );

		if ( LocalDataPtr != (WPTR) 0 ) {
			free( LocalDataPtr );
			LocalDataPtr = (WPTR) 0;
			} 

		}
	return;

}

void	segment_statistics()
{
	EXAWORD	indent;
	EXAWORD	blocklen;

	/* Check if Segment Statistics are required */
	/* ---------------------------------------- */
	if (Options.Stats & STAT_SEGM) {

		blocklen = tcGetw( (((BPTR) ControlZone) + 36));
		indent = 0; ln_SDT = blocklen;

		StreamLine(); StreamString((BPTR) "Segments");

		if ( ! (Options.Stats & STAT_GRAPH ) )
			StreamString((BPTR) "     CODE   LDT    LDS");

		StreamLine(); mf_gener( 78,'-' );

		/* While Not End of Table */
		/* ---------------------- */
		while ( indent < ln_SDT ) {

			/* Check for Valid Segment ID */
			/* -------------------------- */
			if ((SegId = tcGetw((tc_SDT + indent))) == MOINS_UN) {
				break;
				}

			StreamLine();	StreamString((BPTR) "SEGM ");
					HexAdresse( SegId );

			/* Segment Code Size */
			/* ----------------- */
			blocklen = tcGetw((tc_SDT + indent + 4));

			HexAdresse( blocklen );
	
			/* Segment Local Data table length */
			/* ------------------------------- */
			blocklen = tcGetw((tc_SDT + indent + 8));

			HexAdresse( blocklen );

			if ( blocklen != 0 ) {

				/* Segment Local Data Segment length */
				/* --------------------------------- */
				if ( LocalDataPtr != (WPTR) 0 )
					blocklen = *(LocalDataPtr + (indent / 32));

				}

			HexAdresse( blocklen );

			indent += 24;

			}
		StreamLine(); mf_gener( 78,'-' );
		if ( LocalDataPtr != (WPTR) 0 ) {
			free( LocalDataPtr );
			LocalDataPtr = (WPTR) 0;
			} 

		}
	return;
}

#endif	/* _AOSTAT_C */
	/* --------- */

