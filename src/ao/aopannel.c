/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1992 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	AOPANNEL.C				*/
/*		Version :	1.1a					*/
/*		Date	:	13/10/1992				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_PANNEL_C
#define	_PANNEL_C

#include "stdtypes.h"			/* Standard type definitions	*/
#include "aopannel.h"			/* Pannel definition symbols	*/

/*
 *	CICO PRINT FUNCTION : SPACE, GENER, LEFT etc
 *	--------------------------------------------
 *
 */

PRIVATE_SCOPE void cico_space( nb )
EXAWORD	nb;
{
	while ( nb ) {
		cico_chr( ' ' );
		nb--;
		}
	return;
}


PRIVATE_SCOPE void	cico_gener( c, l )
EXAWORD	c;
EXAWORD	l;
{
	while ( l ) {
		cico_chr( c );
		l--;
		}
	return;
}

PRIVATE_SCOPE EXAWORD	cico_left( sptr, l )
BPTR	sptr;
EXAWORD	l;
{

	while (( *sptr ) && ( l )) {
		cico_chr( *(sptr++) );
		l--;
		}

	return( l ) ;
}

PRIVATE_SCOPE void	draw_frame( topcol, toplin, nbcol, nblin )
EXAWORD	topcol;
EXAWORD	toplin;
EXAWORD	nbcol;
EXAWORD	nblin;
{
	EXAWORD	ligne;

	cico_tab( topcol, toplin );
	cico_chr( TOP_LEFT_CORNER ); 
	cico_gener( HORIZONTAL_LINE, nbcol);
	cico_chr( TOP_RIGHT_CORNER );
	
	for ( ligne = 1; ligne <= nblin; ligne++ ) {
		cico_tab( topcol, toplin+ligne );
		cico_chr( VERTICAL_LINE ); 
		cico_space( nbcol);
		cico_chr( VERTICAL_LINE ); 
		}

	cico_tab( topcol, toplin+ligne );
	cico_chr( BOTTOM_LEFT_CORNER ); 
	cico_gener( HORIZONTAL_LINE, nbcol);
	cico_chr( BOTTOM_RIGHT_CORNER );
 
	return;
}

PRIVATE_SCOPE void	field_separator( c, l )
{
	cico_tab( c, l);
	cico_chr( ':' );
}

PRIVATE_SCOPE void	vertical_line( topcol,toplin, nblin )
{
	while ( nblin ) {
		cico_tab( topcol, toplin );
		cico_chr( VERTICAL_LINE );
		toplin++; nblin--;
		}
	return;
}



PRIVATE_SCOPE void	right_aligned_string( sptr, rcol, rlin, nbc )
BPTR	sptr;
EXAWORD	rcol;
EXAWORD	rlin;
EXAWORD	nbc;
{
	EXAWORD	l;
	EXAWORD	n;
	n = 0;
	while ((*sptr) && (*sptr ==' ')) sptr++; 
	if ((l = strlen( sptr )) > nbc )
		l = nbc;
	else	n = nbc - l;
	cico_tab( rcol - nbc, rlin );
	if ( n )
		cico_space( n );
	if ((l = cico_left( sptr, l )) != 0 )
		cico_space( l );

	return;
}

PRIVATE_SCOPE	void	draw_numeric( valeur , lcol, llin, nbc )
EXAWORD	valeur;
EXAWORD	lcol;
EXAWORD	llin;
EXAWORD	nbc;
{
	BYTE	buffer[16];
	EXAWORD	l;
	cico_tab( lcol, llin );
	sprintf( buffer, "%u",valeur);
	if ((l = strlen( buffer )) < nbc)
		cico_space( nbc - l );
	if ((l = cico_left( buffer, l )) != 0)
		cico_space( l );
	return;
}	

PRIVATE_SCOPE	void	draw_long_numeric( valeur , lcol, llin, nbc )
LONG	valeur;
EXAWORD	lcol;
EXAWORD	llin;
EXAWORD	nbc;
{
	BYTE	buffer[16];
	EXAWORD	l;
	cico_tab( lcol, llin );
	sprintf( buffer, "%lu",valeur);
	if ((l = strlen( buffer )) < nbc)
		cico_space( nbc - l );
	if ((l = cico_left( buffer, l )) != 0)
		cico_space( l );
	return;
}	

PRIVATE_SCOPE void	left_string( tptr, sptr, nbc )
BPTR	tptr;
BPTR	sptr;
EXAWORD	nbc;
{
	while ((nbc) && ( *sptr )) {
		*(tptr++) = *(sptr++);
		nbc--;
		}
	*tptr = 0; 
	return;
}

PRIVATE_SCOPE void	suspend_operation();

PRIVATE_SCOPE void	left_aligned_string( sptr, rcol, rlin, nbc, filler )
BPTR	sptr;
EXAWORD	rcol;
EXAWORD	rlin;
EXAWORD	nbc;
EXAWORD	filler;
{
	cico_tab( rcol, rlin );
	while (( *sptr ) && ( *sptr == ' ')) sptr++;
	cico_chr( ' ' );
	nbc = cico_left( sptr , nbc );
	cico_chr( ' ' );
	if ( nbc ) {
		cico_paint( Pannel.LowLight, Pannel.BackGround );
		cico_gener( filler, nbc );
		}	
	cico_paint( Pannel.MedLight, Pannel.BackGround );
	if ( x_kbhit() )
		suspend_operation();

	return;
}

PRIVATE_SCOPE void	coloured_message( sptr, rcol, rlin, nbc, fore, back )
BPTR	sptr;
EXAWORD	rcol;
EXAWORD	rlin;
EXAWORD	nbc;
{
	cico_tab( rcol, rlin );
	while (( *sptr ) && ( *sptr == ' ')) sptr++;
	cico_paint( fore, back );
	cico_chr( ' ' );
	nbc = cico_left( sptr , nbc );
	cico_chr( ' ' );
	if ( nbc ) {
		cico_paint( Pannel.LowLight, Pannel.BackGround );
		cico_space( nbc );
		}	
	cico_paint( Pannel.MedLight, Pannel.BackGround );
	if ( x_kbhit() )
		suspend_operation();
	return;
}

PUBLIC_SCOPE void	terminate_control_pannel();

PRIVATE_SCOPE void	suspend_operation()
{
	EXAWORD	kv;

	if ((kv = x_getch()) == 0x001B ) {
		coloured_message( SUSPEND_MSG, 12, 16, 55, Pannel.MedLight, Pannel.BackGround );
		while ( 1 ) {
			kv = x_getch();
			switch ( kv ) {
				case 0x001B :
					coloured_message( " ", 12, 16, 55, Pannel.MedLight, Pannel.BackGround );
					return;
				case 0x000D :
					coloured_message( ABANDON_MSG, 12, 16, 55, Pannel.MedLight, Pannel.HighLight );
					terminate_control_pannel();
					exit(1);
				}
	
			}

		}
	return;
}

PRIVATE_SCOPE	void	initialise_pannel_counters()
{
	Pannel.WarningCount	= 0;
	Pannel.OptiCount	= 0;
	Pannel.ProcCount	= 0;
	Pannel.SegmCount	= 0;

	Pannel.BackGround 	= BACKGROUND_COLOUR;
	Pannel.LowLight		= LOW_LIGHT_COLOUR;
	Pannel.MedLight		= MED_LIGHT_COLOUR;
	Pannel.HighLight	= HIGH_LIGHT_COLOUR;

	Pannel.StatusMessage[0]  = 0;
	Pannel.ErrorMessage[0]   = 0;
	Pannel.SourceMessage[0]  = 0;
	Pannel.TargetMessage[0]  = 0;
	Pannel.ErrorFlag	 = -1;

	prndest = 1;	prnfid  = 0;
	return;
}


/*
 *	PUBLIC FUNCTIONS : VISIBLE FROM OTHER OBJECT MODULES
 *	----------------------------------------------------
 *	draw_frame, draw_status_message
 *	draw_target_file, draw_source_file
 *	draw_result_lines, draw_swap_buffers
 *	draw_error_count, draw_warning_count
 *	draw_class_count, draw_object_count
 *	draw_proc_count, draw_segment_count
 *
 */

PRIVATE_SCOPE	void	refresh_counters();

PRIVATE_SCOPE	void	redraw_pannel()
{
	cico_paint( Pannel.LowLight, Pannel.BackGround );

	draw_frame( PANNEL_COL, PANNEL_LIN, PANNEL_WIDTH, PANNEL_HEIGHT );

	right_aligned_string( RESULT_FILE_MSG, 18,  9,  8 );
	field_separator( 19,  9 );	
	right_aligned_string( SOURCE_FILE_MSG, 18, 10,  8 );
	field_separator( 19, 10 );
	
	right_aligned_string( CODE_SHRINK_MSG, 29, 12, 19 );
	field_separator( 30, 12 );
	right_aligned_string( TABLE_SHRINK_MSG, 29, 13, 19 );
	field_separator( 30, 13 );

	vertical_line(   43, 12, 2 );

	right_aligned_string(  PROC_COUNT_MSG, 56, 12, 11 );
	field_separator( 57, 12 );
	right_aligned_string(  SEGM_COUNT_MSG, 56, 13, 11 );
	field_separator( 57, 13 );

	cico_paint( Pannel.MedLight, Pannel.BackGround );
	refresh_counters();

	cico_flush;
	return;
}


PUBLIC_SCOPE	void	pre_trace_editor()
{
	cico_curser_on;
	cico_save_screen;
	return;
}

PUBLIC_SCOPE	void	post_trace_editor()
{
	cico_recover_screen;
	cico_curser_off;
	return;
}


PUBLIC_SCOPE	void	refresh_pannel( b,h,l,m )
EXAWORD	b;
EXAWORD	h;
EXAWORD	l;
EXAWORD	m;
{
	Pannel.BackGround 	= b;
	Pannel.LowLight		= l;
	Pannel.MedLight		= m;
	Pannel.HighLight	= h;
	redraw_pannel();
	return;
}

PUBLIC_SCOPE	void	initialise_control_pannel( init_state )
EXAWORD	init_state;
{
	EXAWORD	l;

	cico_initialisation(init_state);
	initialise_pannel_counters();
	Pannel.InitState = init_state;
	cico_bufferisation;
	cico_curser_off;
	redraw_pannel();
	return;
}



PUBLIC_SCOPE void	terminate_control_pannel()
{
	cico_tab( 1, PANNEL_LIN + PANNEL_HEIGHT + 2 );
	cico_curser_on;
	cico_paint( 7, 0 );
	cico_liberation;
	return;
}		


PUBLIC_SCOPE void	draw_target_file( fptr )
BPTR	fptr;
{
	left_aligned_string( fptr, 21, 9, 49, ' ' );
	left_string( Pannel.TargetMessage, fptr, 49 );
	return;
}

PUBLIC_SCOPE void	draw_source_file( fptr )
BPTR	fptr;
{
	left_aligned_string( fptr, 21,10, 49, ' ' );
	left_string( Pannel.SourceMessage, fptr, 49 );
	return;
}

PUBLIC_SCOPE	void	draw_warning_count( adjustment )
EXAWORD	adjustment; 
{
	Pannel.WarningCount += adjustment;
	draw_numeric( Pannel.WarningCount, 32, 12, 7 );
	return;
}

PUBLIC_SCOPE	void	draw_proc_count( adjustment ) 
EXAWORD	adjustment; 
{
	Pannel.ProcCount += adjustment;
	draw_numeric( Pannel.ProcCount, 59, 13, 7 );
	return;
}

PUBLIC_SCOPE	void	pannel_decrement( type )
EXAWORD	type;
{
	switch ( type ) {
		case 0 : Pannel.ProcCount--;
			 draw_numeric( Pannel.ProcCount, 59, 13, 7 );
			 break;
		case 1 : Pannel.SegmCount--;
			 draw_numeric( Pannel.SegmCount, 59, 12, 7 );
			 break;
		}
	return;
}

PUBLIC_SCOPE	void	draw_segm_count( adjustment )
EXAWORD	adjustment; 
{
	Pannel.SegmCount += adjustment;
	draw_numeric( Pannel.SegmCount, 59, 12, 7 );
	return;
}

PUBLIC_SCOPE	void	draw_code_shrink( adjustment )
short int adjustment; 
{
	if ( adjustment != 0 )
		Pannel.CodeShrink += adjustment;
	draw_long_numeric( Pannel.CodeShrink, 32, 12, 7 );
	return;
}

PUBLIC_SCOPE	void	draw_table_shrink( adjustment )
short int adjustment; 
{
	if ( adjustment != 0 )
		Pannel.TableShrink += adjustment;
	draw_long_numeric( Pannel.TableShrink, 32, 13, 7 );
	return;
}

PUBLIC_SCOPE	void	draw_table_report( before, after )
EXAWORD	before;
EXAWORD	after;
{
	BYTE	buffer[256];
	draw_table_shrink( ( before - after ) );
	sprintf( buffer, "Table optimised from %u to %u",before,after);
	coloured_message( buffer, 12, 15, 55, Pannel.MedLight, Pannel.BackGround );
	left_string( Pannel.ErrorMessage, buffer, 55 );
	return;
}

PUBLIC_SCOPE	void	draw_code_report( before, after )
EXAWORD	before;
EXAWORD	after;
{
	BYTE	buffer[256];
	draw_code_shrink( ( before - after ) );
	sprintf( buffer, "Code  optimised from %u to %u",before,after);
	coloured_message( buffer, 12, 15, 55, Pannel.MedLight, Pannel.BackGround );
	left_string( Pannel.ErrorMessage, buffer, 55 );
	return;
}

void	draw_status_message( mptr )
BPTR	mptr;
{
	left_string( Pannel.StatusMessage, mptr, 53 );
	left_aligned_string( mptr, 12, 7, 55, HORIZONTAL_LINE );
	return;
}


PUBLIC_SCOPE	void	draw_procedure( optr )
EXAWORD	optr;
{
	BYTE	buffer[160];
	sprintf( buffer, "%s : %04.1X",PROC_STATUS_MSG,optr); 
	draw_proc_count( 1 );
	draw_status_message( buffer );
	return;
}

PUBLIC_SCOPE	void	announce_current_phase( mptr, aptr )
BPTR	mptr;
BPTR	aptr;
{
	BYTE	buffer[160];
	sprintf( buffer, "%s : %s",mptr, aptr );
	left_string( Pannel.StatusMessage, buffer, 53 );
	cico_paint( Pannel.MedLight, Pannel.BackGround );
	left_aligned_string( buffer, 12, 7, 55, HORIZONTAL_LINE );
	return;
}

PUBLIC_SCOPE	void	draw_optimisations( adjustment )
EXAWORD	adjustment;
{
	Pannel.OptiCount += adjustment;
/*	draw_numeric( Pannel.OptiCount, 32, 13, 7 );	*/
	return;
}

PUBLIC_SCOPE	void	draw_segment( segid )
EXAWORD	segid;
{
	BYTE	buffer[160];
	sprintf( buffer, "%s : %u", SEGM_STATUS_MSG, segid);
	draw_segm_count( 1 );
	left_string( Pannel.StatusMessage, buffer, 53 );
	left_aligned_string( buffer, 12, 7, 55, HORIZONTAL_LINE );
	return;
}

PUBLIC_SCOPE	void	draw_error_message( eptr )
BPTR	eptr;
{
	coloured_message( eptr, 12, 15, 55, Pannel.MedLight, Pannel.HighLight );
	left_string( Pannel.ErrorMessage, eptr, 55 );
	Pannel.ErrorFlag = 1;
	return;
}

PUBLIC_SCOPE	void	draw_warning( eptr )
BPTR	eptr;
{
	coloured_message( eptr, 12, 15, 55, Pannel.MedLight, Pannel.BackGround );
	left_string( Pannel.ErrorMessage, eptr, 55 );
	Pannel.ErrorFlag = 0;
	return;
}

PRIVATE_SCOPE	void	refresh_strings()
{
	left_aligned_string( Pannel.StatusMessage, 12, 7, 55, HORIZONTAL_LINE );
	left_aligned_string( Pannel.TargetMessage, 21, 9, 49, ' ' );
	left_aligned_string( Pannel.SourceMessage, 21,10, 49, ' ' );
	coloured_message( Pannel.ErrorMessage, 12, 15, 55, Pannel.MedLight, Pannel.BackGround );
	return;
}

PRIVATE_SCOPE	void	refresh_counters()
{
	refresh_strings();
	draw_proc_count( 0 );
	draw_segm_count( 0 );
	draw_code_shrink( 0 );
	draw_table_shrink( 0 );
	return;
}

#endif	/* _PANNEL_C */
	/* --------- */

