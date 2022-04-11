/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1991 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXCORE - C				*/
/*		Version :	1.5a					*/
/*		Date 	:	06/05/1991				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EX_CORE_C
#define	_EX_CORE_C

#ifdef	_ABAL_CORE

#include "excore.h"


/*
 *	S F _ C O R E ( )
 *	-----------------
 *	Performs a core image dump to the file assigned by the
 *	current file handle.
 *
 *	The dump file is composed of several records each with a unique
 *	record identifier.
 *	The Dump Record format is as follows :
 *	
 *	RECORD HEADER, RECORD LENGTH , RECORD DATA
 *
 *
 *	Dump Identifier		 :	_DUMP_ID
 *	T-Code Filename		 :	_DUMP_NAME
 *	Date and Time		 :	_DUMP_DATE
 *
 *	Current stack trace of   
 *	segment and procedure    
 *	nesting			 :	_DUMP_TRACE
 *
 *	Global Variables image	 :	_DUMP_GDS
 *	Extended variables image :	_DUMP_EDS
 *
 *	File Table information   :	_DUMP_FCT
 *
 *	Local Variable image for 	
 *	All nested segments and  
 *	Procedures		 :	_DUMP_VARLOC
 *	
 */

struct	core_header	{
	EXABYTE	identity[16];
	EXABYTE	filename[64];
	EXAWORD	day;
	EXAWORD	month;
	EXAWORD	year;
	EXAWORD	hour;
	EXAWORD	minute;
	EXAWORD	second;
	EXAWORD	DiezTempMax;
	EXAWORD	DiezHeapMax;
	EXAWORD	DiezPileMax;
	EXAWORD	filler[ 128 + 30 ];
	} CoreHeader;

EXABYTE	TraceBuffer[256];
EXAWORD	TraceIndex;
EXAWORD	TraceSector;
EXAWORD	TraceLocal;

void	initialise_trace_buffer()
{
	TraceIndex  = 0;
	TraceSector = 1;
	TraceLocal  = 0;
	return;
}

EXAWORD	add_trace_record( type , block , offset , varloc )
EXAWORD	type;
EXAWORD	block;
EXAWORD	offset;
EXAWORD	varloc;
{
	EXAWORD	lerror;

	switch ( type ) {

		case 1 : TraceBuffer[TraceIndex] = 'P'; break;
		case 2 : TraceBuffer[TraceIndex] = 'S'; break;
		case 0 : TraceBuffer[TraceIndex] = 'G';	break;
		default: return( MOINS_UN );

		}

	if ( varloc ) {
		TraceBuffer[TraceIndex+1] = 'L';
		TraceLocal++;
		}
	else	{
		TraceBuffer[TraceIndex+1] = ' ';
		}
	TcodePmot( ((EXBPTR) & TraceBuffer[(TraceIndex+2)]) , block  );
	TcodePmot( ((EXBPTR) & TraceBuffer[(TraceIndex+4)]) , offset );

	/* Advance trace index and post flush if required */
	/* ---------------------------------------------- */
	TraceIndex += 8;
	if ( TraceIndex >= 256 ) {
		if ((lerror = SectWrite( fidreel, (EXBPTR) TraceBuffer, 256 , TraceSector)) != MOINS_UN)
			TraceSector++;
		}
	else	{
		lerror = 0;
		}
	return( lerror );
}

EXAWORD	flush_trace_buffer()
{
	EXAWORD	lerror;

	if ( TraceIndex > 0 ) {
		TcodePmot( (& TraceBuffer[TraceIndex]) , MOINS_UN );
		if ((lerror = SectWrite( fidreel, (EXBPTR) TraceBuffer, 256 , TraceSector)) != MOINS_UN)
			TraceSector++;
		TraceIndex = 0;
		}
	else	{
		lerror = 0;
		}
	return( lerror );
}

EXAWORD	gosub_core_trace( current , limit )
EXAWORD	current;
EXAWORD	limit;
{
	EXAWORD	lerror;

	while ( current > limit ) {
		current--;
		if ((lerror = add_trace_record( 0, 0, ip_hold [ current], 0)) == MOINS_UN)
			return( lerror );
		}
	return( 0 );
}

EXAWORD	add_trace_data_image( data_image , data_length )
EXBPTR	data_image;
EXAWORD	data_length;
{
	EXAWORD	indent;
	EXAWORD	lerror;

	indent = 0;

	while ( data_length > 256 ) {
		if ((lerror = SectWrite( fidreel , (data_image + indent) , 256 , TraceSector)) == MOINS_UN)
			return( MOINS_UN );
		TraceSector++;
		data_length -= 256;
		indent      += 256;
		}
	if ( data_length != 0 ) {
		(void) memset( (EXBPTR) TraceBuffer, 0, 256 );
		(void) memcpy( (EXBPTR) TraceBuffer, (data_image + indent) , data_length);
		if ((lerror = SectWrite( fidreel , (data_image + indent) , 256 , TraceSector)) == MOINS_UN)
			return( MOINS_UN );
		TraceSector++;
		}
	return( 0 );
}


EXAWORD	trace_local_data()
{
	EXAWORD	lerror;
	EXAWORD	i;
	EXAWORD	ContextFlag;
	EXAWORD	ContextWP;
	EXAWORD	ContextPP;
	EXAWORD	ContextType;
	EXAWORD	ContextOffs;
	EXAWORD	ContextHold;
	EXAWORD	segdt;
	EXBPTR	tcLDS;
	EXBPTR	tcLDT;

	struct context EXSPTR sgcp;

	if ( LocalDataTable != (EXBPTR) 0 ) 
		if ((lerror = add_trace_data_image( LocalDataSegment , (Tcodeword((LocalDataTable + 4))) )) == MOINS_UN)
			return( MOINS_UN );

	/* Output stack trace information */
	/* ------------------------------ */
	ContextFlag 	= sicico;
	ContextWP	= StackHold;
	ContextPP	= mindex;

	/* While inside procedure */
	/* ---------------------- */
	while ( ContextFlag & ONSEM_PRC ) {

		ContextFlag = ip_hold [ (ContextWP -  4) ];	/* SICICO   */
		ContextOffs = ip_hold [ (ContextWP -  7) ];	/* FDEX-SB  */
		ContextHold = ip_hold [ (ContextWP -  1) ];	/* STACKHLD */

		/* Adjust Context stacking pointers */
		/* -------------------------------- */
		ContextWP -= 12;

		tcLDT = minder [ ( ContextPP - 2 ) ];
		tcLDS = minder [ ( ContextPP - 1 ) ];

		if ( tcLDT != (EXBPTR) 0 ) 
			if ((lerror = add_trace_data_image( tcLDS , (Tcodeword((tcLDT + 4))) )) == MOINS_UN)
				return( MOINS_UN );

		if ( ContextFlag & ERROR_TEST )
			ContextPP -= 4;
		else
			ContextPP -= 3;

		/* Remove possible Gosubs */
		/* ---------------------- */
		ContextWP = ContextHold;

		}

	/* Generate Segment Local Data */
	/* --------------------------- */
	while ( ContextPP > 0 ) {

		ContextPP--;

		sgcp = (struct context EXSPTR) minder [ ContextPP ];

		if ((tcLDS = sgcp->seg_DS) != (EXBPTR) 0) {
			if ((segdt = seg_find(sgcp->seg_ID)) == MOINS_UN)
				return( MOINS_UN );
			if ((lerror = add_trace_data_image( tcLDS ,(*(TcodeSegmentTable + segdt)).segm_LD)) == MOINS_UN)
				return( MOINS_UN );
			}
		
		}
	return( 0 );
}

void	OutputByte( c )
EXAWORD	c;
{
	if ( TraceIndex >= 256 ) {
		if ( SectWrite( fidreel , (EXBPTR) TraceBuffer , 256 , TraceSector ) != MOINS_UN )
			TraceSector++;
		TraceIndex = 0;
		}
	TraceBuffer[TraceIndex++] = (EXABYTE) c;
	return;	

}

void	OutputWord( c )
EXAWORD	c;
{
	OutputByte( ( c & 0x00FF ) );
	OutputByte( ((c & 0xFF00) >> 8 ) );
	return;
}


EXAWORD	file_table_analysis()
{
	EXAWORD	lerror;
	EXAWORD	ldiezfic;
	EXAWORD	lperm;
	EXAWORD	l;
	EXBPTR	nameptr;

	for ( ldiezfic = 0; ldiezfic <= diezfic; ldiezfic++ ) {

		/* Check if currently used */
		/* ----------------------- */
		if ((lperm = (*(AssignTable + ldiezfic)).permf) & 0x0100 ) {

			OutputWord( ldiezfic );
			OutputWord( lperm );		
			OutputWord( (*(AssignTable + ldiezfic)).unlog );		
			OutputWord( (*(AssignTable + ldiezfic)).aslen );
			OutputWord( (*(AssignTable + ldiezfic)).dblog );
			OutputWord( (*(AssignTable + ldiezfic)).mcext );
			OutputWord( (*(AssignTable + ldiezfic)).enrdata );
			OutputWord( (*(AssignTable + ldiezfic)).enrcle );
			nameptr = (*(AssignTable + ldiezfic)).direcp;
			while ( *nameptr != FILETERM )
				OutputByte( *(nameptr++) );
			OutputByte( 0 );

			}

		}

	return( flush_trace_buffer() );

}

EXAWORD	sf_core()
{
	EXAWORD	lerror;
	EXAWORD	i;
	EXAWORD	ContextFlag;
	EXAWORD	ContextWP;
	EXAWORD	ContextPP;
	EXAWORD	ContextType;
	EXAWORD	ContextOffs;
	EXAWORD	ContextHold;
	struct context EXSPTR sgcp;

	/* Check for existing file */
	/* ----------------------- */
	if ((lerror = Access( fidname , 0, 1 )) == 0 )
		return( 41 );

	/* Create Core Dump file */
	/* --------------------- */
	if ((fidreel = (EX_FILE_HANDLE)creat( fidname , 0666 )) == MOINS_UN)
		return( errno );
 	

	/* Create Core Header Block */
	/* ------------------------ */
	Mstrcpy((EXBPTR) CoreHeader.identity,(EXBPTR) "AT_CORE_V14");
	Mstrcpy((EXBPTR) CoreHeader.filename, (*(AssignTable)).direcp );

	CoreHeader.day 		= date( 3 );
	CoreHeader.month	= date( 2 );
	CoreHeader.year		= date( 1 );
	CoreHeader.hour 	= date( 5 );
	CoreHeader.minute	= date( 6 );
	CoreHeader.second	= date( 7 );
	CoreHeader.DiezTempMax	= worktop;
	CoreHeader.DiezHeapMax	= LDS_dex;
	CoreHeader.DiezPileMax	= ( ip_next > mindex ? ip_next : mindex );

	memset((EXBPTR) CoreHeader.filler , 0xFFFF , (128 + 36 ));

	/* Write Core Header Block to File */
	/* ------------------------------- */
	if ((lerror = SectWrite( fidreel, (EXBPTR) & CoreHeader, TCODEBLOCK, 0)) == MOINS_UN)
		return( err_val );

	/* Create Core Stack Trace List */
	/* ---------------------------- */
	initialise_trace_buffer();


	/* Output File table */
	/* ----------------- */
	if ((lerror = file_table_analysis()) == MOINS_UN)
		return( lerror );

	/* Establish current adresse record */
	/* -------------------------------- */
	if ( sicico & ONSEM_PRC ) {
		if ((lerror = add_trace_record( 1, procid , (( lineptr - TcodeSegment ) - 1),(LocalDataTable != (EXBPTR) 0 ? 1 : 0))) == MOINS_UN)
			return( lerror );
		}
	else	{
		if ((lerror = add_trace_record( 2, cur_seg, (( lineptr - TcodeSegment ) - 1),(LocalDataTable != (EXBPTR) 0 ? 1 : 0))) == MOINS_UN)
			return( lerror );
		}

	/* Perform Gosub tracing */
	/* --------------------- */
	if ((lerror = gosub_core_trace( ip_next , StackHold )) == MOINS_UN )
		return( lerror );

	/* Output stack trace information */
	/* ------------------------------ */
	ContextFlag 	= sicico;
	ContextWP	= StackHold;
	ContextPP	= mindex;

	/* While inside procedure */
	/* ---------------------- */
	while ( ContextFlag & ONSEM_PRC ) {

		ContextFlag = ip_hold [ (ContextWP -  4) ];	/* SICICO   */
		ContextOffs = ip_hold [ (ContextWP -  7) ];	/* FDEX-SB  */
		ContextHold = ip_hold [ (ContextWP -  1) ];	/* STACKHLD */

		if ( ContextFlag & ONSEM_PRC ) {
			ContextType = ip_hold [ (ContextWP - 12) ];	/* PROCID   */
			if ((lerror = add_trace_record( 1, ContextType, ContextOffs,( minder [ (ContextPP - 1) ] != (EXBPTR) 0 ? 1 : 0) )) == MOINS_UN)
				return( lerror );
			}
		else	{
			if ((lerror = add_trace_record( 2, cur_seg, ContextOffs,( minder [ (ContextPP - 1) ] != (EXBPTR) 0 ? 1 : 0))) == MOINS_UN)
				return( lerror );
			}

		/* Adjust Context stacking pointers */
		/* -------------------------------- */
		ContextWP -= 12;
		if ( ContextFlag & ERROR_TEST ) {
			ContextPP -= 4;
			}
		else	{
			ContextPP -= 3;
			}

		/* Perform Gosub tracing */
		/* --------------------- */
		if ((lerror = gosub_core_trace( ContextWP , ContextHold )) == MOINS_UN )
			return( lerror );

		/* Remove possible Gosubs */
		/* ---------------------- */
		ContextWP = ContextHold;

		}

	/* Destack Possible Segments */
	/* ------------------------- */
	while ( ContextPP > 0 ) {

		ContextPP--;
		sgcp = (struct context EXSPTR) minder [ ContextPP ];

		if ((lerror = add_trace_record( 2, sgcp->seg_ID, sgcp->seg_IP,(sgcp->seg_DS != (EXBPTR) 0 ? 1 : 0 ) )) == MOINS_UN)
			return( lerror );

		/* Display possible stacked Gosubs */
		/* ------------------------------- */
		if ((lerror = gosub_core_trace( sgcp->seg_SP, sgcp->seg_SH)) == MOINS_UN )
			return( lerror );
		
		}

	/* Flush trace buffer */
	/* ------------------ */
	if ((lerror = flush_trace_buffer()) == MOINS_UN)
		return( lerror );

	/* Generate Data Segment images */
	/* ---------------------------- */
	/* Check for Global Variables */
	/* -------------------------- */
	if ( len_glob > 0 ) 
		if ((lerror = add_trace_data_image( GlobalDataSegment , len_glob )) == MOINS_UN )
			return( lerror );


	/* Check for Local Variables */
	/* ------------------------- */
	if ( TraceLocal != 0 )
		if ((lerror = trace_local_data()) == MOINS_UN )
			return( lerror );

#ifdef	VMS
	/* Allow VMS to Dump the file table */
	/* -------------------------------- */
	vms_file_table_dump( fidreel, TraceSector );
#endif

	/* Close the core file now */
	/* ----------------------- */
 	(void) close( fidreel ); fidreel = 0;

	/* Indicate success */
	/* ---------------- */
	return( 0 );
}

#else	/* ! _ABAL_CORE */

EXAWORD	sf_core()
{
	return( 56 );
}

#endif	/* _ABAL_CORE */

	/* ---------- */
#endif	/* _EX_CORE_C */
	/* ---------- */
