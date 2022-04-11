/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1994 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AOSTRUCT.C  				*/
/*		Version :	1.4a / 2.1b				*/
/*		Date	:	11/05/1994				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AOSTRUCT_C
#define	_AOSTRUCT_C

#define	OPTIMISER

#include "aomain.h"
#include "aotcode.h"
#include "aotcngf.h"
#include "aostruct.h"
#include "aostream.h"
#include "aoblock.h"

#define	MAX_LEVELS	64

extern	EXAWORD	MasterPhase;

extern	BPTR	tc_SDT;
extern	BPTR	tc_PDT;
extern	EXAWORD	ln_PDT;

extern	EXAWORD	PrcId;
extern	EXAWORD	SegId;
extern	EXAWORD	debug;
extern	EXAWORD	statix;
extern	BYTE	ControlZone[256];
extern	BYTE	ConstructionZone[256];
extern	EXAWORD	OutPutStatus;

	EXAWORD	KeepStatus;
	EXAWORD	HiddenSegments;
	EXAWORD	LigneControl;
	EXAWORD	LevelControl[ MAX_LEVELS ];

	EXAWORD	GlobalMemoryFlag;
	EXAWORD	MemoryAdjust;
	EXAWORD	DescriptorAdjust;
	EXAWORD	ResultSize;

EXAWORD	locate_segment_entry( segment_number )
EXAWORD	segment_number;
{
	EXAWORD	indent;
	EXAWORD	value;
	
	for ( indent = 0; ; indent += (12 * WORDSIZE) ) {
		value = tcGetw((tc_SDT + indent));
		if ( segment_number == value )
			return( indent );
		if (( value == 0xFFFF ) && ( WORDSIZE == 2 ))
			return( value );
		else if (( value == 0xFFFFFFFF ) && ( WORDSIZE == 4 ))
			return( value );
		}		
	return(0);
}

void	disactivate_output()
{
	if ( OutPutStatus != MOINS_UN ) {
		KeepStatus   = OutPutStatus;
		if ( debug == 0 )
			OutPutStatus = MOINS_UN;
		}
	return;
}

void	activate_output()
{
	if ( OutPutStatus == MOINS_UN )
		OutPutStatus = KeepStatus;
	return;
}


EXAWORD	code_block_size( type , id )
EXAWORD	type;
EXAWORD	id;
{

	switch ( (type  & _BASIC_TYPE)) {

		case _PROCEDURE_ENTRY :
			
			return( tcGetw((tc_PDT + id + 2)) );

		case _SEGMENT_ENTRY   :

			if ((id = locate_segment_entry( id )) != MOINS_UN )
				return( tcGetw((tc_SDT + id + 4)) );
		}
	return( 0 );

}

EXAWORD	data_block_size( type , id )
EXAWORD	type;
EXAWORD	id;
{

	switch ( (type  & _BASIC_TYPE)) {

		case _PROCEDURE_ENTRY :
			
			return( tcGetw((tc_PDT + id + 6)) );

		case _SEGMENT_ENTRY   :

			if ((id = locate_segment_entry( id )) != MOINS_UN )
				return( tcGetw((tc_SDT + id + 8)) );
		}
	return( 0 );

}
void	set_segment_options( litem )
ITEMPTR	litem;
{
	EXAWORD	temp;
	EXAWORD	id;
	if ((id = locate_segment_entry( litem->identity )) != MOINS_UN ) {
		temp = tcGetw( (tc_SDT + id +  10) );
		if ( temp & 1 )
			litem->type |= _SEGMENT_RESIDENT;
		if ( temp & 2 )
			litem->type |= _SEGMENT_STATIC;
		}
	return;
}

ITEMPTR	locate_item( ltype, lident )
EXAWORD	ltype;
EXAWORD	lident;
{
	ITEMPTR	litem;

	litem = Structure;

	while ( litem != (ITEMPTR) 0) {
		if (((litem->type & _BASIC_TYPE) == (ltype & _BASIC_TYPE)) && ( litem->identity == lident ))
			break;
		litem = litem->next;
		}
	return( litem );

}

void	flush_line( level )
EXAWORD	level;
{
	EXAWORD	x;

	activate_output();
	oline();	
	if ( LigneControl < 10 )
		oputb(' ');
	if ( LigneControl < 100 )
		oputb(' ');
	if ( LigneControl < 1000 )
		oputb(' ');
	if ( LigneControl < 10000 )
		oputb(' ');
	DecimalWord( LigneControl );
	
	LigneControl++;
	x = 0; 
	while ( x <= level ) {
		switch ( LevelControl[x] ) {
			case 0 : oputs("        "); break;
			case 1 : oputs("  ÀÄÄÄ> "); break;
			case 2 : oputs("  ³     "); break;
			case 3 : oputs("  ÃÄÄÄ> "); break;
			}
		x++;
		}
	disactivate_output();
	return;
}

void	componant_line()
{
	if ( Options.Verbose ) {
		activate_output();
		oline();
		disactivate_output();
		}
	return;
}

void	repeated_message( source_item )
ITEMPTR	source_item;
{
	activate_output();
	oputs("  ( SEE LINE ");
	DecimalWord( source_item->ligne );
  	oputs("  ) ");
	disactivate_output();
	return;
}
void	recursivity_message( source_item, level )
ITEMPTR	source_item;
EXAWORD	level;
{
	activate_output();
	oputs(" * * RECURSIVE @");
	HexWord( source_item->ligne );
	oputs(" * * ");
	disactivate_output();
	return;
}

void	identity_memory_usage( litem )
ITEMPTR	litem;
{
	EXAWORD	codesize;
	oputb(' ');
	oputb('(');
	codesize = code_block_size( litem->type, litem->identity );
	HexWord( codesize );
	codesize = data_block_size( litem->type, litem->identity );
	if (( codesize != MOINS_UN ) && ( codesize != 0 )) {
		oputb(',');
		HexWord( codesize );
		}
	oputb(')');
	return;
}

void	identity_message( source_item )
ITEMPTR	source_item;
{
	if ( (source_item->type  & _BASIC_TYPE) == _SEGMENT_ENTRY ) {
		oputs("SEGM ");	
		DecimalWord( source_item->identity );
		if ( source_item->type & _SEGMENT_RESIDENT )
			oputs(",R ");
		if ( source_item->type & _SEGMENT_STATIC )
			oputs(",S ");
		if ( Options.Analyse & 0x0020 )
			identity_memory_usage( source_item );
		}
	else	{
		oputs("PROC ");	
		AffProc( source_item->identity );
		if ( Options.Analyse & 0x0020 )
			identity_memory_usage( source_item );
		}
	return;
}

void	componant_present_message( source_item, level )
ITEMPTR	source_item;
EXAWORD	level;
{
	activate_output();
	identity_message( source_item );
	oputs(" Already Present @ "); HexWord( source_item->ligne );
	disactivate_output();
	return;
}

void	componant_identity_message( source_item )
ITEMPTR	source_item;
{
	activate_output();
	identity_message( source_item );
	if ( ResultSize != 0 ) {
		oputs(" Inlined @ ");
		HexWord( ResultSize );
		}
	disactivate_output();
	return;
}

void	variable_segment_message()
{
	activate_output();
	oputs("SEGMENT by VARIABLE or REGISTER ");
	disactivate_output();
	return;
}

void	adresse_message( valeur )
EXAWORD	valeur;
{
	activate_output();
	oputs(" ADR "); HexWord( valeur );
	oputs(" : ");
	disactivate_output();

}

long	adjust_memory_occupation( litem, memusage )
ITEMPTR	litem;
long	memusage;
{
	EXAWORD	temp;
	switch ( (litem->type  & _BASIC_TYPE)) {

		case _PROCEDURE_ENTRY :
			break;

		case _SEGMENT_ENTRY   :
			if ( litem->type & _SEGMENT_RESIDENT ) {
				if (!( litem->lock & _STATUS_LOCK )) {
					temp = code_block_size( litem->type, litem->identity );
					memusage += temp;
					temp = code_block_size( litem->type, litem->identity );
					if (temp != MOINS_UN)
						memusage += temp;
					}
				}
			else	if ( memusage == 0L ) {
					temp = overlay_code_size();
					memusage += temp;
					temp = overlay_data_size();
					memusage += temp;
					}

		}	
	return( memusage );
}

void	actual_memory_usage( litem, memusage )
ITEMPTR	litem;
long	memusage;
{
	switch ((litem->type  & _BASIC_TYPE)) {

		case _PROCEDURE_ENTRY :
			break;

		case _SEGMENT_ENTRY   :
			activate_output();
			oputs(" : ");
			HexLong( memusage );
			disactivate_output();
		}
	return;
}

void	generate_analysis_report(base_item,level,memusage)
ITEMPTR		base_item;
EXAWORD		level;
long		memusage;
{
	ITEMPTR	current;
	EXAWORD		x;

	if ( base_item != (ITEMPTR) 0) {

		switch (( base_item->type & _BASIC_TYPE )) {

			case _SEGMENT_ENTRY   : componant_identity_message( base_item );
						break;

			case _PROCEDURE_ENTRY : componant_identity_message( base_item );
						break;

			case _EXIT_ENTRY      : EscMnemonic((base_item->identity >> 8));
						LevelControl[level] = 0;
						return;

			case _FILE_ENTRY      : oputs("NGF ");
						NgfMnemonic((base_item->identity >> 8));
						LevelControl[level] = 0;
						return;

			default      	      : LevelControl[level] = 0;
						return;

			}

		if ( Options.Analyse & 0x0020 ) {
			memusage = adjust_memory_occupation( base_item, memusage );
			actual_memory_usage( base_item, memusage );
			}

		/* Check for ITEM locked */
		/* --------------------- */
		if ( base_item->lock ) {
			if ( base_item->lock & _STATUS_LOCK ) {
				recursivity_message( base_item, (level + 1) );
				}
			else if ( base_item->liste != (ITEMPTR) 0 ) {
				repeated_message( base_item );
				}
			return;
			}

		/* Lock the Item and Signal Usage */
		/* ------------------------------ */
		base_item->lock  = (_STATUS_LOCK | _STATUS_DONE);
		base_item->ligne = LigneControl;


		if ((current = base_item->liste) != (ITEMPTR) 0) {
		
			LevelControl[level] = 2;
			flush_line( level );

			while ( current != (ITEMPTR) 0 ) {

				if ( current->next ) 
					LevelControl[level] = 3;
				else	LevelControl[level] = 1;
				flush_line( level );

				if (( current->identity == MOINS_UN ) && ( (current->type & _BASIC_TYPE) == _SEGMENT_ENTRY )) {
					variable_segment_message();
					HiddenSegments = VRAI;
					}
				else	{
					LevelControl[level] &= 2;
					generate_analysis_report(locate_item(current->type,current->identity),(level+1),memusage);
					LevelControl[level] |= 1;
					}
				current = current->next;
				}
			LevelControl[level] = 0;
			flush_line(level);
			}

		/* Remove Lock and Indicate Already Listed */
		/* --------------------------------------- */
		base_item->lock &= _STATUS_UNLOCK;

		}

	LevelControl[level] = 0;
	return;
}

void	generate_all_segments()
{
	EXAWORD		x;
	ITEMPTR	current;

	for ( x = 1; x < 255; x++ ) {
		if (( current = locate_item( _SEGMENT_ENTRY, x )) != (ITEMPTR) 0 ) {
			oline(); 
			generate_analysis_report( current, 0, 0L );
			oline();
			}
		}
	return;
}

generate_callers_report( current, level )
ITEMPTR	current;
EXAWORD		level;
{
	CALLERPTR	lcaller;

	if ( current != (ITEMPTR) 0) {

		switch(( current->type & _BASIC_TYPE)) {

			case _SEGMENT_ENTRY   : componant_identity_message( current );
						LevelControl[level] = 0;
						break;

			case _PROCEDURE_ENTRY : if ( Options.Analyse & 0x0002 ) {
							componant_identity_message( current );
							LevelControl[level] = 0;
							break;
							}
						return;

			case _EXIT_ENTRY      : if ( Options.Analyse & 0x0004) {
							EscMnemonic((current->identity >> 8));
							LevelControl[level] = 0;
							break;
							}
						return;

			case _FILE_ENTRY      : if ( Options.Analyse & 0x0008) {
							oputs("NGF ");
							NgfMnemonic((current->identity >> 8));
							LevelControl[level] = 0;
							break;
							}
						return;

			default		      :	LevelControl[level] = 0;
						return;

			}
		/* Check for ITEM locked */
		/* --------------------- */
		if ( current->lock ) {
			if ( current->lock & _STATUS_LOCK ) {
				recursivity_message( current, (level+1) );
				}
			else if ( current->liste != (ITEMPTR) 0 ) {
				repeated_message( current, level );
				}
			return;
			}

		/* Lock the Item and Signal Usage */
		/* ------------------------------ */
		current->lock  |= (_STATUS_LOCK | _STATUS_DONE);
		current->ligne = LigneControl;

		if ((lcaller = current->callers) != (CALLERPTR) 0) {
		
			LevelControl[level] = 2;
			flush_line( level );

			while (lcaller != (CALLERPTR) 0) {

				if ( lcaller->next ) 
					LevelControl[level] = 3;
				else	LevelControl[level] = 1;
		
				flush_line( level );
				adresse_message( lcaller->usercall->ligne );


				LevelControl[level] &= 2;
				generate_callers_report(locate_item(lcaller->owner->type,lcaller->owner->identity),(level + 1));
				LevelControl[level] |= 1;

				lcaller = lcaller->next;

				}
			LevelControl[level] = 0;
			flush_line(level);
			}
		/* Remove Lock and Indicate Already Listed */
		/* --------------------------------------- */
		current->lock &= _STATUS_UNLOCK;

		}
	LevelControl[level] = 0;
	return;
}

void	initialise_analysis()
{
	Structure = (ITEMPTR) 0;
	return;
}

void	reset_level_control()
{
	EXAWORD	x;
	for ( x = 0; x < MAX_LEVELS; x++ )
		LevelControl[x] = 0;
	LevelControl[0] = 1;

}


void	rellocate_local_descriptor( vptr, status )
BPTR	vptr;
EXAWORD	status;
{
	if (( status != MOINS_UN ) && ( DescriptorAdjust != 0 )) {
		status  = tcGetw((vptr));
		if (( status & ISLOCAL) && (!(GlobalMemoryFlag))) {
			status  = ((((status & TOGLOBAL) - (3*WORDSIZE)) + DescriptorAdjust) | ISLOCAL);
			tcPutw((vptr),status);
			}
		else	{
			if (( status & ISLOCAL) && (GlobalMemoryFlag)) {
				status  = (((status & TOGLOBAL) - (3*WORDSIZE)) + DescriptorAdjust);
				tcPutw((vptr),status);
				}
			}
		}
	return;
}

void	rellocate_local_pointer( vptr, status )
BPTR	vptr;
EXAWORD	status;
{
	EXAWORD	x;

	if (( status != MOINS_UN ) && ( MemoryAdjust != 0 )) {
		status  = ((tcGetw((vptr))) + MemoryAdjust);
		tcPutw((vptr),status);
		if ( GlobalMemoryFlag ) {
			switch (((x = *(vptr - 2)) & 0x007F)) {
				case _tc_LIL  : *(vptr - 2) = (_tc_GIL | (x & 0x0080)); break;
				case _tc_LCL  : *(vptr - 2) = (_tc_GCL | (x & 0x0080)); break;
				case _tc_LIS  : *(vptr - 2) = (_tc_GIS | (x & 0x0080)); break;
				case _tc_LCS  : *(vptr - 2) = (_tc_GCS | (x & 0x0080)); break; 
				}
			}
		}
	return;
}

void	rellocate_other_calls( titem, offset, adjust, type, identity )
ITEMPTR		titem;
EXAWORD		offset;
short int	adjust;
EXAWORD		type;
EXAWORD		identity;
{

	while ( titem != (ITEMPTR) 0 ) {
		if (!( titem->lock & _STATUS_DONE ))
			if (( (titem->type & _BASIC_TYPE) != type )
			||  ( titem->identity != identity ))
				if ( titem->ligne > offset )
					titem->ligne -= adjust;
		titem = titem->next;
		}
	return; 

}

void	rellocate_other_blocks( offset, adjust )
EXAWORD		offset;
short	int	adjust;
{
	ITEMPTR	litem;
	
	litem = Structure;

	while ( litem != (ITEMPTR) 0 ) {

		if ( litem->lock & _STATUS_INLINE )
			if ( litem->ligne > offset )
				litem->ligne -= adjust;

		litem = litem->next;
		}	
	return;
}

void	rellocate_current_calls( titem, slen, offset )
ITEMPTR		titem;
short int	slen;
EXAWORD		offset;
{
	while ( titem != (ITEMPTR) 0 ) {

		if ( titem->ligne > offset )
			titem->ligne += slen;

		titem = titem->next;
		}
	return;
}

void	adjust_label( sptr, ecart, limit )
BPTR	sptr;
EXAWORD	ecart;
EXAWORD	limit;
{
	EXAWORD	x;
	if ( ecart != 0 ) {
		if ((x = tcGetw((sptr))) > limit)
			tcPutw((sptr),(x+ecart));
		}
	ConvertLabel( sptr, sptr );
	return;
}

EXAWORD	expand_code( sptr, si, slen, ajout)
BPTR	sptr;
EXAWORD	si;
EXAWORD	slen;
EXAWORD	ajout;
{
	EXAWORD	x;

	/* Transfer code to new expanded Region */
	/* ------------------------------------ */
	for ( x = (si + slen + ajout - 1); x > si; x-- )
		*(sptr + x ) = *(sptr + x - 1);

	/* Return New Code Size */
	/* -------------------- */
	return( (slen + ajout) ); 
}

void	rellocate_ngf( sptr, type, ecart, limit )
BPTR	sptr;
EXAWORD	type;
EXAWORD	ecart;
EXAWORD	limit;
{
	BPTR	aptr;
	BPTR	vptr;
	EXAWORD	ngfcode;
	EXAWORD	mode;

	ngfcode = *(sptr + 1);
	aptr = (sptr + 2);
	vptr = aptr;

	while (*(vptr++) & 1);

	/* Check for Existance of Error Trap */
	/* --------------------------------- */
	if ( *aptr & 0x0080 ) {

		/* Then peform Conversion */
		/* ---------------------- */
		adjust_label( vptr, ecart, limit );

		if (( *aptr & 0x0060 ) == 0x0040 ) {
			rellocate_local_descriptor((vptr + 2),type);
			vptr += 4;
			}
		else	vptr += 3;
		mode = 2;
		}
	else	mode = 1;

	if ( mode == 1 ) {
		if (( *aptr & 0x0060 ) == 0x0040 ) 
			rellocate_local_descriptor(vptr,type);
		if (( *aptr & 0x0060 ) == 0x0060 )
			vptr++;
		else	vptr += 2;
		if ( *aptr & 0x0010 )
			mode = 2;
		else	mode = 0;
		}
	else	{
		if (( *aptr & 0x0006 ) == 0x0004 ) 
			rellocate_local_descriptor(vptr,type);
		if (( *aptr & 0x0006 ) == 0x0006 )
			vptr++;
		else	vptr += 2;
		if ( *(aptr++) & 1 )
			mode = 1;
		else	mode = 0;
		}

	switch ( ngfcode ) {
		case _NGF_MODIFY :
		case _NGF_INSERT :
		case _NGF_DOWN   :
		case _NGF_UP     :
		case _NGF_DELETE :
		case _NGF_SEARCH :
		case _NGF_ATB	 :
		case _NGF_ERASE  :
		case _NGF_CREATE :
		case _NGF_POSIT	 :
		case _NGF_COUNT	 : 
		case _NGF_EXEC	 : vptr++;
		}

	while ( mode ) {
		if ( mode == 1 ) {
			if (( *aptr & 0x0060 ) == 0x0040 ) 
				rellocate_local_descriptor(vptr,type);
			if (( *aptr & 0x0060 ) == 0x0060 )
				vptr++;
			else	vptr += 2;
			if ( *aptr & 0x0010 )
				mode = 2;
			else	mode = 0;
			}
		else	{
			if (( *aptr & 0x0006 ) == 0x0004 ) 
				rellocate_local_descriptor(vptr,type);
			if (( *aptr & 0x0006 ) == 0x0006 )
				vptr++;
			else	vptr += 2;
			if ( *(aptr++) & 1 )
				mode = 1;
			else	mode = 0;
			}
		}
	return;
}

EXAWORD	rellocate_fmt( sptr,type )
BPTR	sptr;
{
	if ( *sptr != _tc_CLF )
		return( FAUX );

	/* Watch out for the function FM */
	/* ----------------------------- */
	switch (*(sptr + 1)) {

		case 0x005A 	: rellocate_local_descriptor((sptr + 4),type);
		case 0x006A 	: 
		case 0x007A 	: break;
		default		: return( FAUX );
	
		}

	rellocate_local_descriptor((sptr + 2),type);
			
	return( VRAI );

}
void	rellocate_multiple_args( sptr, type )
BPTR	sptr;
EXAWORD	type;
{
	BPTR	aptr;
	BPTR	vptr;

	if ( rellocate_fmt( sptr, type ) != 0 )
		return;

	aptr = (sptr + 2);
	vptr = aptr;
	while ( *(vptr++) & 1 );
	while ( 1 ) {
		if ((*aptr & 0x0060) == 0x0040)
			rellocate_local_descriptor(vptr,type);
		if ((*aptr & 0x0060) == 0x0060)
			vptr++;
		else	vptr += 2;
		if (!(*aptr & 0x0010))   
			break;
		if ((*aptr & 0x0006) == 0x0004)
			rellocate_local_descriptor(vptr,type);
		if ((*aptr & 0x0006) == 0x0006)
			vptr++;
		else	vptr += 2;
		if (!(*(aptr++) & 1))
		break;
		}
	return;
}

EXAWORD	perform_exit_functions( flag , rptr, limit )
EXAWORD	flag;
EXAWORD	limit;
BPTR	rptr;
{
	EXAWORD	i;

	i = 0;

	/* Watch out for and disactivate Timer */
	/* ----------------------------------- */
	if (( flag & _FLAG_TIMER ) && ( limit >= 2)) {
		*(rptr + i) = (_tc_TIM | 0x0080);
		i++;
		*(rptr + i) = 0x00;
		i++;
		limit -= 2;
		}

	/* Watch out for and disactivate EVENT */
	/* ----------------------------------- */
	if (( flag & _FLAG_EVENT ) && ( limit >= 2)) {
		*(rptr + i) = (_tc_WHN | 0x0080);
		i++;
		*(rptr + i) = 0x00;
		i++;
		limit -= 2;
		}

	/* Watch out for and disactivate ERROR */
	/* ----------------------------------- */
	if (( flag & _FLAG_ERROR ) && ( limit >= 1)) {
		*(rptr + i) = (_tc_ERA | 0x0080);
		i++;
		limit--;
		}

	return( i );

}
 
short int	rellocate_inline_labels( sptr, indent, slen, ecart, type, limit, sitem, titem )
BPTR		sptr;
EXAWORD		indent;
EXAWORD		slen;
EXAWORD		ecart;
EXAWORD		type;
EXAWORD		limit;
ITEMPTR		sitem;
ITEMPTR		titem;
{
	EXAWORD		x;
	EXAWORD		y;
	EXAWORD		special;
	short int	adjust;
	BPTR		aptr;

	/* Initialise Label Manager */
	/* ------------------------ */
	if (InitLabel() != 0)
		return( 0 );

	for (adjust = 0; slen != 0; ) {

		if ( *(sptr + (indent + adjust)) == 0x00FF )
			break;

		/* Add This Adresse to List */
		/* ------------------------ */
		if ( AddLabel( indent, (indent + adjust) ) != 0) {

			/* Dismantle tree and Return */
			/* ------------------------- */
			FreeLabel();
			return( 0 );
			}

		switch (( *(sptr + (indent+adjust)) & 0x007F)) {

			case _tc_ESC :

				if ((( (type & _BASIC_TYPE) == _PROCEDURE_ENTRY ) && ( *(sptr + (indent+adjust) + 1) == _tc_RTP ))
				||  (( (type & _BASIC_TYPE) == _SEGMENT_ENTRY   ) && ( *(sptr + (indent+adjust) + 1) == _tc_RTS ))) {

					/* Watch out for Terminal EXIT or RET.SEG */
					/* -------------------------------------- */
					if ( slen > 2 ) {
#ifndef	OLD_JUMP_EXIT
						/* ---------------------------------------------- */
						/* Watch out for Locally active TIMER,EVENT,ERROR */
						/* ---------------------------------------------- */
						special = perform_exit_functions( sitem->flag, (sptr + (indent+adjust)), 1 );
		
						/* Change Tcode to RET */
						/* ------------------- */
						*(sptr + (indent+adjust+special)) = ((*(sptr + (indent+adjust)) & 0x0080) | _tc_RET);

						/* Padd Second Byte */
						/* ---------------- */
						if ( special == 0 ) 
#ifdef MERDE
							{
							memcpy( (sptr + indent + adjust + 1), ( sptr + indent + adjust + 2), (slen - 2));
						 	rellocate_current_calls( titem->liste, -1 , (indent + adjust + 2));
						 	adjust--;
						 	} 
#endif
							*(sptr + indent + adjust + 1) = _tc_RET;


						slen -= 2; indent += 2; continue;

#else
						/* Change Tcode to JMI */
						/* ------------------- */
						*(sptr + (indent+adjust)) = ((*(sptr + (indent+adjust)) & 0x0080) | _tc_JMI);

						adjust++;
						slen = expand_code(sptr,(indent+adjust),slen,1);
						tcPutw((sptr + (indent+adjust) ),(slen+indent-2));

						/* Allow Label Convertor to See */
						/* ---------------------------- */
						ConvertLabel((sptr + indent + adjust),(sptr + indent + adjust));

						/* Decrement Total Length and Avance to Next */
						/* ----------------------------------------- */
						slen -= 3; indent += 2; continue;
#endif
						}
					else	{
						/* Remove Final EXIT or RET.SEG */
						/* ---------------------------- */
						adjust -= 2; slen = 0; 
						continue;
						}
					break;
					}

				switch ( *(sptr + indent + adjust + 1) ) {

					case _tc_LDI : /* ESC SPAWN */

						adjust_label((sptr + indent + adjust + 3),ecart,limit);
						if ( *(sptr + indent + adjust + 2) == 0x0040 )
							rellocate_local_descriptor((sptr + indent + adjust + 5),type);
						break;

					case _tc_ANX : /* ESC KILL */

						if ( *(sptr + indent + adjust + 2) == 0x0040 )
							rellocate_local_descriptor((sptr + indent + adjust + 3),type);
						break;

					case _tc_CLP : 

						rellocate_multiple_args((sptr + indent + adjust),type);
						break;

					case _tc_PSV :
					case _tc_SGV :

						rellocate_local_descriptor((sptr + indent + adjust + 2),type);
						break;
	
					case _tc_GSR :
					case _tc_JMR :

						x = (tcGetw( (sptr + indent + adjust + 3 )));
						for (y = 0; y < x; y++ ) 
							adjust_label((sptr + indent + adjust + 5 + (y * 2)),ecart,limit);


					}
				break;

			case _tc_IOF  : 


				/* Enter IO Analysis Cycle */
				/* ----------------------- */

				aptr = (sptr + indent + adjust + 1);

				while ( 1 ) {

					/* Analyse IO operation Code */
					/* ------------------------- */
					switch ( (*aptr & 0x000F) ) {
						case _io_SPX  : aptr++;
								continue;
						case _io_ASK  : if ((*aptr & 0x0040) == 0x0040)
									rellocate_local_descriptor((aptr + 1), type );

						case _io_ESC  : break;
						case _io_HOT1 : 
						case _io_HOT2 : adjust_label( (aptr + 1), ecart, limit );
								aptr += 3; continue;

						case _io_KEY1 :
						case _io_KEY2 : if ((*aptr & 0x0060) == 0x0060) {
									adjust_label((aptr + 2),ecart,limit);
									aptr += 4;
									}
								else	{
									if ((*aptr & 0x0040) == 0x0040)
										rellocate_local_descriptor((aptr+1), type);
									adjust_label((aptr + 3),ecart,limit);
									aptr += 5;
									}
								continue;

						case _io_FMT  : if (!(*aptr & 0x00F0)) {
									adjust_label((aptr + 1),ecart,limit);
									aptr += 3;
									continue;
									}
								else if (*aptr & 0x0080) {
									aptr += ( *(aptr + 1) + 2);
									continue;
									}
								else if ((*aptr & 0x0060) == 0x0060)
									aptr += 2;
								else	{
									if ((*aptr & 0x0040) == 0x0040)
										rellocate_local_descriptor((aptr + 1), type );
									aptr += 3;
									}
								continue; 

						case _io_PRN  : if (*aptr & 0x0080) {
									aptr++;
									while ( *(aptr++) );
									continue;
									}

						default       : if ((*aptr & 0x0060) == 0x0060)
									aptr += 2;
								else	{
									if ((*aptr & 0x0040) == 0x0040)
										rellocate_local_descriptor((aptr + 1), type );
									aptr += 3;
									}
								continue; 

						}

					break;

					}

				break;

			case _tc_LDF  :
			case _tc_CLF  : rellocate_multiple_args((sptr + indent + adjust),type);
					break;


			case _tc_NGF  : rellocate_ngf((sptr + indent + adjust),type,ecart,limit);
					break;

			case _tc_TIM  : if ( *(sptr + indent + adjust + 1) & 0x000F ) {
						if (( *(sptr + indent + adjust + 1) & 0x0040 ) == 0x0040 )
							rellocate_local_descriptor((sptr +indent + adjust + 2), type );
						if (( *(sptr + indent + adjust + 1) & 0x0060 ) == 0x0060 )
							adjust_label((sptr + indent + adjust + 3), ecart, limit );
						else	adjust_label((sptr + indent + adjust + 4), ecart, limit );
						}
					break;

			case _tc_LIL  :
			case _tc_LCL  :
			case _tc_LIS  :
			case _tc_LCS  : rellocate_local_pointer( (sptr +indent +adjust + 2), type );
					break;

			case _tc_STV  : rellocate_local_descriptor((sptr + indent + adjust + 1), type );
			case _tc_STI  :
			case _tc_STC  : rellocate_local_descriptor((sptr + indent + adjust + 3), type );
					break;
			case _tc_STR  :
			case _tc_VPT  :
			case _tc_LDV  :
			case _tc_LXV  :
			case _tc_AXV  : rellocate_local_descriptor((sptr + indent + adjust + 2), type );
					break;

			case _tc_NGV  :
			case _tc_DTV  :	rellocate_local_descriptor((sptr + indent + adjust + 1), type );
					break;

			case _tc_OEO  :
			case _tc_OLE  :
			case _tc_OPV  :
			case _tc_OEV  :	rellocate_local_descriptor((sptr + indent + adjust + 1), type );

			case _tc_JEQR :
			case _tc_JNER :
			case _tc_JLSR :
			case _tc_JGRR :
			case _tc_JLER :
			case _tc_JGER :
			case _tc_JINR :
			case _tc_JNIR :	adjust_label((sptr + indent +adjust + 3 ),ecart,limit);
					break;

			case _tc_WHN  : if ( *(sptr + indent + adjust + 1) != _ec_DCL )
						break;

			case _tc_OER  :	adjust_label((sptr + indent +adjust + 2 ),ecart,limit);
					break;

			case _tc_ADV  :
			case _tc_SBV  :
			case _tc_MLV  :
			case _tc_DVV  :
			case _tc_MDV  :
			case _tc_ANV  :
			case _tc_ORV  :
			case _tc_XRV  :	rellocate_local_descriptor((sptr + indent + adjust + 2), type );
					break;

			case _tc_JEQV :
			case _tc_JNEV :
			case _tc_JLSV :
			case _tc_JGRV :
			case _tc_JLEV :
			case _tc_JGEV :
			case _tc_JINV :
			case _tc_JNIV :	rellocate_local_descriptor((sptr + indent + adjust + 2), type );

			case _tc_JEQC :
			case _tc_JNEC :
			case _tc_JLSC :
			case _tc_JGRC :
			case _tc_JLEC :
			case _tc_JGEC :
			case _tc_JINC :
			case _tc_JNIC : 
			case _tc_JEQI :
			case _tc_JNEI :
			case _tc_JLSI :
			case _tc_JGRI :
			case _tc_JLEI :
			case _tc_JGEI : adjust_label((sptr + indent +adjust +4),ecart,limit);
					break;
			case _tc_REQ  :
			case _tc_JMI  :
			case _tc_GSB  : adjust_label((sptr + indent +adjust + 1),ecart,limit);
					break;
			}

		/* Step over Sequence */
		/* ------------------ */
		if ((x = TcodeList( sptr, (indent + adjust), 0 )) == 0) {
			break;
			debug = 1;
			activate_output();
			(void) TcodeList( sptr, (indent + adjust), 0 );
			x = 1;
			}
		slen -= x; indent += x;
		}

	/* Back Patch OutStanding Labels */
	/* ----------------------------- */
	Resolver(); FreeLabel();

	/* Return New Increment */
	/* -------------------- */
	return(adjust);
}

ITEMPTR	next_patch_item( current, type, identity )
ITEMPTR	current;
EXAWORD	type;
EXAWORD	identity;
{
	while ( current != (ITEMPTR) 0 ) {
		if (!( current->lock & _STATUS_DONE ))
			if (( (current->type & _BASIC_TYPE) == type )
			&&  ( current->identity == identity))
				break;
		current = current->next;
		}
	return( current );
}



/*
 *	M E R G E _ C O D E _ B L O C K S ( ........... )
 *	-------------------------------------------------
 *
 *	This function will perform the code block merging required
 *	to inline a procedure or segment into a procedure or segment.
 *	The Target to be patched will be cut at the patch offset.
 *	Code prior to the patch offset will be copied to the result.
 *	The Source code to be inlined will then be copied to the patch
 *	offset and overwrite the previous calling mechanism (CALL/LDGO.SEG).
 *	All Labels in the inlined code will be adjusted to accomodate the
 *	patch offset starting adresse and all Block Exit mechanisms either
 *	EXIT or RET.SEG will be replaced by direct jumps (JMI) to the end
 *	of the inline code.
 *	Foreward referencing Labels in the Patch target code which exceed
 *	the patch adresse will then adjusted to reflect the code expansion.
 *	The Code which previously followed the patch offset in the original
 *	target block will then be copied after the inlined code and all
 *	forward referencing labels in this region will also be adjusted to
 *	to reflect the code expansion due to the inline patch.
 *	Finally calls in the target code block list which exceed the patch
 *	offset will be adjusted to reflect the code expansion.
 *	The final useful size of the Target code block will be returned to
 *	the calling functions "inline_componants" and "source_item_present"
 * 	to be stored in the appropiate code block control table. 
 */

EXAWORD	merge_code_blocks(rptr, sptr, slen, tptr, tlen, sitem, titem, usage_count )

			/* -------------------------------------------  */
BPTR	rptr;		/* Pointer to buffer to contain result 		*/
BPTR	sptr;		/* Pointer to buffer of code to be inlined 	*/
EXAWORD	slen;		/* Length of code to to be inlined		*/
BPTR	tptr;		/* Pointer to buffer of code to receive patch	*/
EXAWORD	tlen;		/* Length of code to receive patch		*/
ITEMPTR	sitem;		/* Source item identity structure		*/
ITEMPTR	titem;		/* Patch Target Item Controller providing list	*/
EXAWORD	usage_count;	/* Number of Calls to the Block to be inlined	*/
			/* -------------------------------------------  */
{
	EXAWORD		indent;	/* Redundant Sequence Length		*/
	EXAWORD		offset;	/* Offset of Patch 			*/
	short	int 	adjust;	/* Adjustment due to Rellocation	*/
	ITEMPTR		xitem;	/* Current Target Item Patch Element	*/

	/* Establish Current Target Patch Item and Convert to DONE */
	/* ------------------------------------------------------- */
	if ((xitem = next_patch_item( titem->liste,sitem->type,sitem->identity )) == (ITEMPTR) 0) {
		if ( tlen != 0 )
			memcpy( rptr, tptr, tlen );
		return( tlen );
		}

	offset = xitem->ligne;

	/* Lock Item to Indicate DONE */
	/* -------------------------- */
	xitem->lock |= _STATUS_DONE;
	
	/* Ensure Block is Reset to Null Value */
	/* ----------------------------------- */
	memset((BPTR) rptr, 0x00FF,(slen + tlen));

	/* Calculate Length of Redundant Sequence */
	/* -------------------------------------- */
	if ( (sitem->type & _BASIC_TYPE) == _PROCEDURE_ENTRY ) {
		indent = 5;
		adjust = 2;
		}
	else	{
		adjust = 0;
		indent = 3;
		}

	/* --------------------------------------------------------- */
	/* Arrival Here means Multiple occurance of code to inlined  */
	/* Consequently the inline code will be added to the end of  */
	/* the block, terminated by a RETURN, to be called from the  */
	/* patch adresse by a GOSUB expression			     */
	/* --------------------------------------------------------- */

	/* First Copy Target to be Patched into the Result Zone */
	/* ---------------------------------------------------- */
	memcpy((BPTR) rptr, (BPTR) tptr, tlen );

	while ( 1 )	{

		if ( adjust ) {
			rellocate_other_blocks( offset, 2 );
			rellocate_other_calls( titem->liste, offset, 2, sitem->type, sitem->identity );
			}

		/* Generate GOSUB to Inlined Routine */
		/* --------------------------------- */
		*( rptr + offset ) = (_tc_GSB | (*(rptr + offset) & 0x0080)); 

		/* If Source is not Zero then Establish New Block Adresse */
		/* ------------------------------------------------------ */
		if ( slen != 0 ) {
			tcPutw(( rptr + offset + 1),(tlen - adjust));
			}
		else	{
			tcPutw((rptr + offset + 1),sitem->ligne);
			}

		/* Check for Code Shift Required for Procedure Patch */
		/* ------------------------------------------------- */
		if (( adjust ) && ( tlen - offset - adjust )) {

			/* Transfer Post Patch Code to Post Patched Offset */
			/* ----------------------------------------------- */
			if ( (tlen - offset - indent) != 0 ) {

				memcpy( (BPTR) (rptr + offset + 3), 
				        (BPTR) (rptr + offset + indent), 
					       (tlen - (offset+indent) - (adjust - 2)) 
				      );


				tcPutw((rptr + (tlen - adjust)),MOINS_UN);

				/* PrePatch Rellocation may now be performed */
				/* ----------------------------------------- */
				(void) rellocate_inline_labels( rptr, 0, offset, 
								-2, MOINS_UN, offset,
								sitem ,titem
							      );


				/* Post Patch Rellocation may now be performed */
				/* ------------------------------------------- */
				(void) rellocate_inline_labels( 
						rptr, (offset + 3), 
						(tlen-(offset+indent)-(adjust-2)),
						 -2, MOINS_UN, offset , sitem,
						titem
					      );

				/* Correct current Target Code Size */
				/* -------------------------------- */
				adjust += 2;

				}
			}
		
		/* Collect next Patch adresse and Repeat while more to do */
		/* ------------------------------------------------------ */
		if ((xitem = next_patch_item( xitem->next,sitem->type, sitem->identity )) == (ITEMPTR) 0)
			break;

		/* Lock Item to Indicate DONE */
		/* -------------------------- */
		xitem->lock |= _STATUS_DONE;

		/* Collect New Patch Offset */
		/* ------------------------ */
		offset = xitem->ligne;	
	
		/* Correct offset if Patching Procedure Call */
		/* ----------------------------------------- */
		if ( adjust )
			offset -= (adjust - 2);
	
		}

	/* Adjustment must now be Exact */
	/* ---------------------------- */
	if ( adjust ) {
		tlen -= (adjust - 2); adjust = 0;
		}

	/* The Source Code to be inlined may now be concatenated to block */
	/* -------------------------------------------------------------- */
	if ( slen != 0 ) {

		sitem->ligne = tlen;
		sitem->lock  |= _STATUS_INLINE;

		/* Check for Procedure using READ=0 and DATA */
		/* ----------------------------------------- */
		if (( (sitem->type & _BASIC_TYPE) == _PROCEDURE_ENTRY ) && ( sitem->flag & _FLAG_DATA )) {

			/* Generate AUTO RESTORE 1 */
			/* ----------------------- */
			*(rptr + tlen) = (_tc_CLF | 0x0080); 	tlen++;
			*(rptr + tlen) = _clf_RESTORE;	     	tlen++;
			*(rptr + tlen) = 0x00;			tlen++;
			tcPutw((rptr + tlen),1);		tlen += 2; 

			}

		memcpy((BPTR) (rptr + tlen), (BPTR) sptr, slen );

		/* The Inline Code must Now be Rellocated and Modified */
		/* --------------------------------------------------- */
		adjust = rellocate_inline_labels( rptr, tlen, slen, 
						  tlen,
						  sitem->type, 0 , sitem,
						  titem
					          );


		/* ---------------------------------------------- */
		/* Watch out for Locally active TIMER,EVENT,ERROR */
		/* ---------------------------------------------- */
		slen += perform_exit_functions( sitem->flag, (rptr + tlen + slen + adjust), 5 );

		/* The Return will not be reached */
		/* ------------------------------ */
		if (  *(rptr + tlen + slen + adjust - 1)  != (_tc_RET | 0x0080) ) {

			/* Terminate Resulting Block */
			/* ------------------------- */
			*(rptr + tlen + slen + adjust) = (_tc_RET | 0x0080);

			/* Adjust Source length to include RETURN */
			/* -------------------------------------- */
			slen++;

			}

		}

	/* Return final Block Length to Caller */
	/* ----------------------------------- */
	return( (tlen + slen + adjust));

}

void	display_item_type( sitem )
ITEMPTR	sitem;
{
	if ( (sitem->type & _BASIC_TYPE) == _PROCEDURE_ENTRY ) {
		oputs((BPTR) " PROC ");
 		AffProc( sitem->identity );
		}
	else	{
		oputs((BPTR) " SEGM ");
		DecimalWord( sitem->identity );
		}
	return;
}

void	report_inlining( sitem, titem )
ITEMPTR	sitem;
ITEMPTR	titem;
{
	BYTE	buffer[256];
	if ( (sitem->type & _BASIC_TYPE) == _PROCEDURE_ENTRY )
		sprintf( buffer, "Inlining Procedure %04.1X in",sitem->identity );
	else	sprintf( buffer, "Inlining Segment   %u in",sitem->identity );
	if ( (titem->type & _BASIC_TYPE) == _PROCEDURE_ENTRY )
		sprintf( buffer, "%s Procedure %04.1X",buffer,titem->identity );
	else	sprintf( buffer, "%s Segment   %u",buffer,titem->identity );
	draw_warning( buffer );
	return;	
}

void	display_operation( sitem, titem )
ITEMPTR	sitem;
ITEMPTR	titem;
{
	ITEMPTR	xitem;
	if ( Options.Pannel ) {
 		report_inlining( sitem, titem );
		return;
		}
	if ( debug ) {
		activate_output();
		oputs((BPTR) " Inlining : ");
		display_item_type( sitem );
		oputs((BPTR) " in ");
		display_item_type( titem );
		oputs((BPTR) " at ");
		xitem = next_patch_item( titem->liste, sitem->type, sitem->identity );
		while ( xitem != (ITEMPTR) 0 ) {
			HexWord( xitem->ligne );
			if ((xitem = next_patch_item( xitem->next, sitem->type, sitem->identity )) != (ITEMPTR) 0)
				oputs(", ");
			}
		LineFeed();
		disactivate_output();
		}
	return;
}

EXAWORD		recursivity_test( caller_list )
CALLERPTR	caller_list;
{
	/* Repeat while callers exist in list */
	/* ---------------------------------- */
	while ( caller_list != (CALLERPTR) 0 ) {

		/* Ensure Valid Call Owner Item */
		/* ---------------------------- */
		if ( caller_list->owner != (ITEMPTR) 0 ) {

			/* Test for Owner Locked Hence Recursive */
			/* ------------------------------------- */
			if ( caller_list->owner->lock & _STATUS_CHECK )
				return( VRAI );
	
			/* Otherwise Ensure Callers of this Item are OK */
			/* -------------------------------------------- */
			else if ( recursivity_test( caller_list->owner->callers ) )
				return( VRAI );
			}

		/* Next Entry in callers list */
		/* -------------------------- */
		caller_list = caller_list->next;
		}

	return( FAUX );
}

EXAWORD	inline_gosub_decision( sitem, liste, usage_count )
ITEMPTR	sitem;
ITEMPTR	liste;
EXAWORD	usage_count;
{
	while ( liste != (ITEMPTR) 0 ) {

		/* If not locked hence not done */
		/* ---------------------------- */
		if (!( liste->lock & _STATUS_DONE )) 

			/* Check for Identical call Identity */
			/* --------------------------------- */
			if (((liste->type  & _BASIC_TYPE) == (sitem->type & _BASIC_TYPE))
			&&  (liste->identity == sitem->identity))

				/* Adjust Usage Counter */
				/* -------------------- */
				usage_count++;

		/* Collect next possible item */
		/* -------------------------- */
		liste = liste->next;
		}

	/* Return Usage Counter to caller */
	/* ------------------------------ */
	return( usage_count );
}
void	show_context( p )
INLINEPTR	p;
{
	oputs(" Code : "); DecimalWord( p->code_sector ); oputs("  "); HexWord( p->code_length );
	oputs(" Data : "); DecimalWord( p->data_sector ); oputs("  "); HexWord( p->data_length );
	return;
}

void	update_item_control_table( item, p )
ITEMPTR		item;
INLINEPTR	p;
{
	EXAWORD	s;


	switch ( (item->type & _BASIC_TYPE) ) {

		case _PROCEDURE_ENTRY :
			
			tcPutw((tc_PDT + item->identity + 0),p->code_sector);
			tcPutw((tc_PDT + item->identity + 2),p->code_length);
			tcPutw((tc_PDT + item->identity + 4),p->data_sector);
			tcPutw((tc_PDT + item->identity + 6),p->data_length);
			if (!( p->code_sector ))
				tcPutw((tc_PDT + item->identity + 14),0);

			break;

		case _SEGMENT_ENTRY   :

			if ((s = locate_segment_entry( item->identity )) != MOINS_UN ) {
				tcPutw((tc_SDT + s + 2),p->code_sector);
				tcPutw((tc_SDT + s + 4),p->code_length);
				tcPutw((tc_SDT + s + 6),p->data_sector);
				tcPutw((tc_SDT + s + 8),p->data_length);
				}
			break;
		}
	return;

}

void	reset_inline_context( p )
INLINEPTR	p;
{
	p->code_buffer  = (BPTR) 0;
	p->code_sector  = 0;
	p->code_length  = 0;
	p->data_buffer  = (BPTR) 0;
	p->data_sector  = 0;
	p->data_length  = 0;
	p->flags        = 0;
	p->extra_length = 0;
	p->extra_buffer = (BPTR) 0;
	p->sd_adj       = 0;
	p->sm_adj       = 0;
	return;
}

EXAWORD	establish_result_locals( t, r )
INLINEPTR	t;
INLINEPTR	r;
{

	if ( t->data_length != 0 ) {
		/* Result Receives Copy of Target Local Data */
		/* ----------------------------------------- */
		if ((r->data_buffer = MakeBlock((r->data_length = t->data_length))) == (BPTR) 0)
			return( FAUX );

		/* Duplicate Source Data In Result Data */
		/* ------------------------------------ */
		(void) memcpy( r->data_buffer, t->data_buffer, t->data_length );

		r->data_sector = t->data_sector;
		}

	return( VRAI );
}

EXAWORD	handle_inline_data( s, t, r )
INLINEPTR	s;
INLINEPTR	t;
INLINEPTR	r;
{
	EXAWORD	x;

	if (s->code_length ) {	
		if ( s->flags & _FLAG_DATA ) {
			if ((x = (tcGetw((s->code_buffer + s->code_length - 2)))) != MOINS_UN) {
				r->extra_length = (s->code_length - x);
				s->code_length  = x;
				if ((r->extra_buffer = MakeBlock( r->extra_length )) == (BPTR) 0)
					return( FAUX );
				memcpy( r->extra_buffer, (s->code_buffer + x), r->extra_length );
				}	
			else	s->code_length -= 2;
			}
		else	s->code_length -= 2;
		}
	if ( t->flags & _FLAG_DATA ) {
		if ((x = (tcGetw((t->code_buffer + t->code_length - 2)))) != MOINS_UN) {
			r->extra_length = (t->code_length - x);
			t->code_length  = x;
			if ((r->extra_buffer = MakeBlock( r->extra_length )) == (BPTR) 0)
				return( FAUX );
			memcpy( r->extra_buffer, (t->code_buffer + x), r->extra_length );
			}
		else	t->code_length -= 2;

		}
	else	t->code_length -= 2;

	return( VRAI );

}

EXAWORD	duplicate_inline_context(s, t, r )
INLINEPTR	s;
INLINEPTR	t;
INLINEPTR	r;
{
	
	reset_inline_context( r );

	if ( t->code_length ) {
		if (( r->code_buffer = MakeBlock( t->code_length )) != (BPTR) 0) {
			r->code_sector = t->code_sector;
			r->code_length = t->code_length;

			if ( establish_result_locals( t, r ) == FAUX ) {
				LiberateBlock( r->code_buffer );
				reset_inline_context();
				return( FAUX );
				}

			/* Indicate Operation Possible */
			/* --------------------------- */
			r->flags = (t->flags & _FLAG_DATA);

			return(handle_inline_data(s,t,r) );
			}
		}
	return(FAUX );
}

void	liberate_inline_context( p )
INLINEPTR	p;
{
	if ( p->code_buffer != (BPTR) 0 ) {
		if ( p->code_sector )
			(void) StoreBlock( p->code_sector, p->code_buffer );
		else	LiberateBlock( p->code_buffer );
		}
	if ( p->data_buffer != (BPTR) 0 ) {
		if ( p->data_sector )
			(void) StoreBlock( p->data_sector, p->data_buffer );
		else	LiberateBlock( p->data_buffer );
		}

	if ( p->extra_buffer != (BPTR) 0 )
		LiberateBlock( p->extra_buffer );

	reset_inline_context( p );
	return;
}


EXAWORD	update_inline_context( r,s, item )
INLINEPTR	r;
INLINEPTR	s;
ITEMPTR		item;
{
	EXAWORD	result;

	/* Detect Presence of Extra Data (Read=0) */
	/* -------------------------------------- */
	if ( r->extra_length != 0 ) {

		memcpy((r->code_buffer + r->code_length), r->extra_buffer, r->extra_length);
		tcPutw((r->code_buffer + r->code_length + r->extra_length - 2),r->code_length);
		r->code_length += r->extra_length;
		if ( s->code_length ) {
			if ( s->flags & _FLAG_DATA ) 
				s->code_length += r->extra_length;
			else	s->code_length += 2;
			}
		}

	else	{
		tcPutw((r->code_buffer + r->code_length),0xFFFF);
		r->code_length += 2;
		s->code_length += 2;
		}

	/* Detect Type for Control Table Update */
	/* ------------------------------------ */
	update_item_control_table( item, r );

	/* Save Current Flags Context */
	/* -------------------------- */
	item->flag = r->flags;

	result = r->code_length;

	/* Update Block Controller */
	/* ----------------------- */
	liberate_inline_context( r );

	
	return( result );
}

EXAWORD	load_inline_context( p, item )
INLINEPTR	p;
ITEMPTR		item;
{
	EXAWORD	s;

	/* Establish Item Information */
	/* -------------------------- */
	switch ( (item->type & _BASIC_TYPE) ) {

		case _PROCEDURE_ENTRY :

			p->code_sector = tcGetw((tc_PDT + item->identity + 0));
			p->code_length = tcGetw((tc_PDT + item->identity + 2));
			p->data_sector = tcGetw((tc_PDT + item->identity + 4));
			p->data_length = tcGetw((tc_PDT + item->identity + 6));
			break;

		case _SEGMENT_ENTRY   :

			if ((s = locate_segment_entry( item->identity )) != MOINS_UN ) {
				p->code_sector = tcGetw((tc_SDT + s + 2));
				p->code_length = tcGetw((tc_SDT + s + 4));
				p->data_sector = tcGetw((tc_SDT + s + 6));
				p->data_length = tcGetw((tc_SDT + s + 8));
				break;
				}
	
		default		      : 

			return( MOINS_UN );

		}

	p->sd_adj = item->sd_adj;
	p->sm_adj = item->sm_adj;

	return( VRAI );

}

EXAWORD	establish_inline_context( handle, p, item )
EXAWORD		handle;
INLINEPTR	p;
ITEMPTR		item;
{

	/* Reset Result Structure */
	/* ---------------------- */
	reset_inline_context( p );

	if (load_inline_context( p, item ) == MOINS_UN)
		return( MOINS_UN );


	/* Avoid Using Blocks that have been devalidated */
	/* --------------------------------------------- */
	if ( p->code_sector == 0 )
		return( MOINS_UN );

	/* Ensure ZERO values rather than -1 values */
	/* ---------------------------------------- */
	if ( p->data_length == MOINS_UN )
		p->data_length = 0;

	/* Establish Options Flags */
	/* ----------------------- */
	p->flags = item->flag;

	/* Attempt to load Code Block */
	/* -------------------------- */
	if (( p->code_sector ) && ( p->code_length ))
		if ((p->code_buffer = LoadBlock( handle, p->code_sector, p->code_length)) == (BPTR) 0) {
			liberate_inline_context( p );
			return( MOINS_UN );
			}
	/* Attempt to load Data Table */
	/* -------------------------- */
	if (( p->data_sector ) && ( p->data_length ))
		if ((p->data_buffer = LoadBlock( handle, p->data_sector, p->data_length)) == (BPTR) 0) {
			liberate_inline_context( p );
			return( MOINS_UN );
			}
	return(0);
}

EXAWORD	memory_overflow( slen, tlen, limit )
EXAWORD	slen;
EXAWORD	tlen;
EXAWORD	limit;
{
	unsigned long totale;

	totale  = (unsigned long) slen;
	totale += (unsigned long) tlen;

	if ( totale > ((unsigned long) limit))
		return( VRAI );
	else	return( FAUX );

}


void	display_variables( s,t,r)
INLINEPTR	s;
INLINEPTR	t;
INLINEPTR	r;
{

	activate_output();
	oputs(" VarLoc : ");
	oputs(" Source ");
	if ( s->data_buffer != (BPTR) 0)
		DecimalWord((tcGetw(s->data_buffer)));
	else	oputs("0");
	oputs(" Target ");
	if ( t->data_buffer != (BPTR) 0)
		DecimalWord((tcGetw(t->data_buffer)));
	else    oputs("0");
	oputs(" Result ");
	if ( r->data_buffer != (BPTR) 0)
		DecimalWord((tcGetw(r->data_buffer)));
	else    oputs("0");

	LineFeed();
	disactivate_output();
	return;
}

EXAWORD	static_data_merger( s, t, r )
INLINEPTR	s;
INLINEPTR	t;
INLINEPTR	r;
{
#ifdef	STATIC_MERDE
	GlobalMemoryFlag = VRAI;
	s->flags |= _FLAG_STATIC_DONE;
	return( VRAI );
#else
	return( FAUX );
#endif
}

void	establish_static_data( s, t, r )
INLINEPTR	s;
INLINEPTR	t;
INLINEPTR	r;
{
	GlobalMemoryFlag = VRAI;
	return;
}

EXAWORD	dynamic_data_merger( s, t, r )
INLINEPTR	s;
INLINEPTR	t;
INLINEPTR	r;
{
	EXAWORD	x;

	GlobalMemoryFlag = FAUX;

	/* Ensure Data Merge is Possible */
	/* ----------------------------- */
	if ( memory_overflow( s->data_length, t->data_length, TOGLOBAL ) )
		return( FAUX );

	/* Currently no ARGS are allowed */
	/* ----------------------------- */
	if ( local_variable_args( s->data_buffer ) != 0 )
		return( FAUX );

	/* If target has no local data table */
	/* --------------------------------- */
	if ( t->data_length == 0 ) {

		/* Result Receives Copy of Source Local Data */
		/* ----------------------------------------- */
		if ((r->data_buffer = MakeBlock((r->data_length = s->data_length))) == (BPTR) 0)
			return( FAUX );

		/* Duplicate Source Data In Result Data */
		/* ------------------------------------ */
		(void) memcpy( r->data_buffer, s->data_buffer, s->data_length );
	
		/* Get next free sector and Establish New next free sector */
		/* ------------------------------------------------------- */
		r->data_sector = get_next_free_sector( r->data_length );

		}
	else	{
		/* Ensure that memory is sufficient */
		/* -------------------------------- */
		if ( memory_overflow( (tcGetw((s->data_buffer+4))), (tcGetw((t->data_buffer+4))), 0xFFFF ) )
			return( FAUX );

		/* Merge Data Tables */
		/* ----------------- */
		if ((r->data_buffer = MakeBlock(((r->data_length =( s->data_length + t->data_length - 6))))) == (BPTR) 0)
			return( FAUX );			

		/* Concatenate Data Tables */
		/* ----------------------- */
		(void) memcpy((BPTR) r->data_buffer, (BPTR) t->data_buffer, (EXAWORD) t->data_length );
		(void) memcpy((BPTR) (r->data_buffer + t->data_length), (BPTR) (s->data_buffer + 6), (EXAWORD) (s->data_length - 6) );

		/* Update Variable Count */
		/* --------------------- */
		x  = tcGetw((s->data_buffer));

		/* Rellocate New Variable offsets */
		/* ------------------------------ */
		rellocate_local_variables((r->data_buffer + t->data_length),x,(tcGetw((t->data_buffer+4))), t->data_length );

		x += tcGetw((t->data_buffer));
		tcPutw((r->data_buffer),x);
	
		/* Update Local Data Memory Size */
		/* ----------------------------- */
		x  = tcGetw((t->data_buffer+4));
		MemoryAdjust     = x;

		x += tcGetw((s->data_buffer+4));
		tcPutw((r->data_buffer+4),x);

		DescriptorAdjust = t->data_length;

		/* Establish Result Data */
		/* --------------------- */
		r->data_sector = t->data_sector;

		}

	return( VRAI );
}

/*
 *	M E R G E _ R U L E S _ C H E C K ( )
 *	-------------------------------------
 * 
 *	The rules which dictate whether a code block may be inlined
 *	are as follows.
 *
 *	 - The Resulting Code Block must not Exceed 0xFFFF
 *	 - The Resulting Data Table must not exceed 0x7FFF
 *	 - The Resulting Data Area must not exceed 0xFFFF	
 *
 *	 - Either source or target may use DATA but not both.
 *	 - Either source or Target may use ON EVENT but not both.
 *	 - Either source or target may use ON ERROR but not both.
 *	 - Either source or target may use ON TIMER but not both.
 *
 *	Static  Local Data will be added to the GDT and GDS
 *	Dynamic Local Data will be added to the Target LDT and LDS
 *	Code DATA items will be placed at the end of the target block.
 *
 */

EXAWORD	merge_rules_check( s, t, r )
INLINEPTR	s;
INLINEPTR	t;
INLINEPTR	r;
{
	EXAWORD	x;
	
	/* Ensure Clean Result Context */
	/* --------------------------- */
	reset_inline_context( r );

	/* Test options Flags */
	/* ------------------ */
	if ((s->flags & _FLAG_DATA) && (t->flags & _FLAG_DATA))
		return( FAUX );
	if ((s->flags & _FLAG_TIMER) && (t->flags & _FLAG_TIMER))
		return( FAUX );
	if ((s->flags & _FLAG_EVENT) && (t->flags & _FLAG_EVENT))
		return( FAUX );
	if ((s->flags & _FLAG_ERROR) && (t->flags & _FLAG_ERROR))
		return( FAUX );

	/* Ensure Code Merge is Possible */
	/* ----------------------------- */
	if ( memory_overflow( s->code_length, t->code_length, 0xFFFF ) )
		return( FAUX );

	/* No need to adjust variable descriptors and GIL,GCL,LIL etc */
	/* ---------------------------------------------------------- */
	MemoryAdjust = 0; DescriptorAdjust = 0;

	if ( debug ) 
		display_variables( s, t, r );

	/* Check for Local Data Preset */
	/* --------------------------- */
	if (s->data_length != 0 ) {

		if (!( s->flags & _FLAG_STATIC )) {
			if ( dynamic_data_merger( s, t, r ) == FAUX )
 				return( FAUX );
			}
		else 	{
			if (!(s->flags & _FLAG_STATIC_DONE)) {
				if ( static_data_merger( s, t, r ) == FAUX )
					return( FAUX );
				}
			else	{
				establish_static_data( s, t, r );
				}

			}
		}
	else	{
		if ( establish_result_locals( t, r ) == FAUX )
			return( FAUX );

		}

	/* Attempt to Allocate for Result Buffer */
	/* ------------------------------------- */
	if ((r->code_buffer = MakeBlock( (s->code_length + t->code_length + 256 ) )) == (BPTR) 0) {
		if ( r->data_buffer != (BPTR) 0) {
			if ( t->data_buffer != (BPTR) 0) 
				LiberateBlock( r->data_buffer );
			else	set_last_free_sector( r->data_length );
			r->data_buffer = (BPTR) 0;
			}
		return( FAUX );
		}

	/* Create Duplicate Target Information for Update */
	/* ---------------------------------------------- */
	r->code_sector = t->code_sector;
	r->code_length = (s->code_length + t->code_length);


	/* Remove Target Data if Present */
	/* ----------------------------- */
	if ( r->data_buffer != (BPTR) 0 ) 
		if ( t->data_buffer != (BPTR) 0 ) {
			LiberateBlock( t->data_buffer );
			t->data_buffer = (BPTR) 0;
			}
	
	/* Indicate Operation Possible */
	/* --------------------------- */
	r->flags = (t->flags | (s->flags & _FLAG_DATA));

	if ( debug )
		display_variables( s, t, r );

	/* Handle Possible Data Now */
	/* ------------------------ */
	if ( handle_inline_data( s, t, r) == FAUX )
		return( FAUX );

	return( VRAI );
}


void	display_context( s, t, r )
INLINEPTR	s;
INLINEPTR	t;
INLINEPTR	r;
{
	activate_output();
	oputs((BPTR) " Source   ");
	show_context( s );
	LineFeed();
	oputs((BPTR) " Target   ");
	show_context( t );
	LineFeed();
	oputs((BPTR) " Result   ");
	show_context( r );
	LineFeed();
	disactivate_output();
	return;
}


EXAWORD	source_item_present(handle, target_item, source_item )
EXAWORD	handle;
ITEMPTR	target_item;
ITEMPTR	source_item;
{
	struct	inline_control Source;
	struct	inline_control Target;
	struct  inline_control Result;

	CALLERPTR	this_caller;
	EXAWORD		result;

	/* Attempt to Initialise Source Context */
	/* ------------------------------------ */
	reset_inline_context( & Source );

	/* Attempt to Initialise Target Context */
	/* ------------------------------------ */
	if ( establish_inline_context( handle, & Target , target_item ) != MOINS_UN ) {

		/* Ensure Code Block Merge is Possible */
		/* ----------------------------------- */
		if ( duplicate_inline_context( &Source, &Target, &Result ) == VRAI ) {

			if (( Options.Verbose ) || ( Options.Pannel )) {
				display_operation( source_item, target_item );
				if ( debug )
					display_context( &Source, &Target, &Result );
				}

			/* Perform The Code Merge */
			/* ---------------------- */
			Result.code_length = merge_code_blocks( Result.code_buffer, Source.code_buffer, Source.code_length, Target.code_buffer, Target.code_length, source_item, target_item, 1 );

			/* Update Current Target Context */
			/* ----------------------------- */
			result = update_inline_context( & Result, &Source, target_item );
						
			/* Remove previous Target buffer */
			/* ----------------------------- */
			LiberateBlock( Target.code_buffer );
			Target.code_buffer = (BPTR) 0;
			}

		/* Save Current Target Context */
		/* --------------------------- */
		liberate_inline_context( & Target );
		}
	else	{
		/* Signal Failure */
		/* -------------- */
		result = MOINS_UN;
		}

	/* Liberate Source Block */
	/* --------------------- */
	liberate_inline_context( & Source );
	

	return( result );

}

EXAWORD	inline_source_in_target(handle, target_item, source_item )
EXAWORD	handle;
ITEMPTR	target_item;
ITEMPTR	source_item;
{
	struct	inline_control Source;
	struct	inline_control Target;
	struct  inline_control Result;

	CALLERPTR	this_caller;
	EXAWORD		result;

	/* Avoid Recursive Circumstances */
	/* ----------------------------- */
	source_item->lock |= _STATUS_CHECK;
	if ( recursivity_test( source_item->callers ) == VRAI ) {
		source_item->lock &= _STATUS_NORMAL;
		return( 0 );
		}

	source_item->lock &= _STATUS_NORMAL;

	/* Attempt to Initialise Source Context */
	/* ------------------------------------ */
	if ( establish_inline_context( handle, & Source , source_item ) == MOINS_UN )

		/* Indicate Error */
		/* -------------- */
		return( MOINS_UN );

	/* Attempt to Initialise Target Context */
	/* ------------------------------------ */
	if ( establish_inline_context( handle, & Target , target_item ) != MOINS_UN ) {

		/* Ensure Code Block Merge is Possible */
		/* ----------------------------------- */
		if ( merge_rules_check( & Source, &Target, &Result ) == VRAI ) {

			if (( Options.Verbose ) || ( Options.Pannel )) {
				display_operation( source_item, target_item );
				if ( debug )
					display_context( &Source, &Target, &Result );
				}

			/* Perform The Code Merge */
			/* ---------------------- */
			Result.code_length = merge_code_blocks( Result.code_buffer, Source.code_buffer, Source.code_length, Target.code_buffer, Target.code_length, source_item, target_item, 1 );

			/* Update Current Target Context */
			/* ----------------------------- */
			result = update_inline_context( & Result, &Source, target_item );
						
			/* Remove previous Target buffer */
			/* ----------------------------- */
			LiberateBlock( Target.code_buffer );
			Target.code_buffer = (BPTR) 0;
			}
		else	{
			source_item->keep = VRAI;
			result = 0;
			}

		/* Save Current Target Context */
		/* --------------------------- */
		liberate_inline_context( & Target );
		}
	else	{
		/* Signal Failure */
		/* -------------- */
		result = MOINS_UN;
		}

	/* Liberate Source Block */
	/* --------------------- */
	liberate_inline_context( & Source );
	

	return( result );
}


void	extend_target_list( target, source )
ITEMPTR	target;
ITEMPTR	source;
{
	ITEMPTR	liste;

	/* Add at the end of Target Calls List */
	/* ----------------------------------- */
	if ((liste = target->liste) == (ITEMPTR) 0) {
		target->liste = source->liste;
		}
	else	{
		while ( liste->next != (ITEMPTR) 0)
			liste = liste->next;
		liste->lock |= _STATUS_FIN_LISTE;
		liste->next  = source->liste;
		}

	/* Rellocate these calls in Inherited list items */
	/* --------------------------------------------- */
	if (( liste = source->liste ) != (ITEMPTR) 0 ) {
		do	{
			liste->ligne += source->ligne; 
			liste = liste->next;
			}
		while ( liste != (ITEMPTR) 0);
		}
	return;
}


EXAWORD	inline_componants(handle, target_item, source_item, level )
EXAWORD	handle;
ITEMPTR	target_item;
ITEMPTR	source_item;
EXAWORD	level;
{
	ITEMPTR		current;
	EXAWORD		x;
	EXAWORD		result;

	/* Check for ITEM locked */
	/* --------------------- */
	if ( source_item->lock ) {

		if ( source_item->lock & _STATUS_LOCK ) {

			if ( Options.Verbose )
				recursivity_message( source_item, (level+1) );

			}
		else	{
			if ( source_item->lock & _STATUS_INLINE ) {

				if ( Options.Verbose )
					componant_present_message( source_item, level );

				/* Perform Inline Gosub Patch Operation to Copy */
				/* Of source block already present in Target    */
				/* -------------------------------------------- */
				if ((result = source_item_present(handle, target_item, source_item )) == MOINS_UN)

					/* Propagate the resulting Error */
					/* ----------------------------- */
					return( MOINS_UN );
	
				ResultSize = code_block_size( target_item->type, target_item->identity );

				}
			}

		return(0);
		}

	if ( source_item != (ITEMPTR) 0) {

		switch ( ( source_item->type & _BASIC_TYPE) ) {

			case _SEGMENT_ENTRY   :

				source_item->ligne = ResultSize;

				if ( Options.Verbose )
					componant_identity_message( source_item );

				break;

			case _PROCEDURE_ENTRY : 

				source_item->ligne = ResultSize;

				if ( Options.Verbose )
					componant_identity_message( source_item );

				break;

			default      	      : 

				LevelControl[level] = 0;
				return( 0 );

			}

		/* Attempt to Inline this Block in Current Target */
		/* ---------------------------------------------- */
		if ( level != 0 ) {
			if ((result = inline_source_in_target(handle, target_item, source_item )) == MOINS_UN)
				return( MOINS_UN );

			/* The List of Calls in the Source must be added to the */
			/* Target List and Adjusted by the Adresse of the Block */
			/* ---------------------------------------------------- */
			if (( source_item->liste != (ITEMPTR) 0) && ( result != 0 ))
				extend_target_list( target_item, source_item );
			}

		/* Recalculate Current Total Block Size */
		/* ------------------------------------ */
		ResultSize = code_block_size( target_item->type, target_item->identity );

		/* Lock the Item and Signal Usage */
		/* ------------------------------ */
		source_item->lock  |= (_STATUS_LOCK | _STATUS_DONE);

		if ((current = source_item->liste) != (ITEMPTR) 0) {
		
			if ( Options.Verbose ) {
				LevelControl[level] = 2;
				flush_line( level );
				}

			while ( current != (ITEMPTR) 0 ) {

				if ( Options.Verbose ) {
					if ( current->next ) 
						LevelControl[level] = 3;
					else	LevelControl[level] = 1;
					flush_line( level );
					}

				if (( current->identity == MOINS_UN ) && ( (current->type & _BASIC_TYPE) == _SEGMENT_ENTRY )) {
					if ( Options.Verbose )
						variable_segment_message();

					HiddenSegments = VRAI;
					}
				else	{
					LevelControl[level] &= 2;

					if (!( current->lock & _STATUS_INLINE )) 
						if ((result = inline_componants(handle, target_item, locate_item( current->type, current->identity ), (level+1) )) == MOINS_UN)
							return( MOINS_UN );

					LevelControl[level] |= 1;
					}
				current = current->next;
				}

			if ( Options.Verbose ) {
				LevelControl[level] = 0;
				flush_line(level);
				}
			}

		/* Remove Lock and Indicate Already Listed */
		/* --------------------------------------- */
		source_item->lock &= _STATUS_UNLOCK;

		}

	LevelControl[level] = 0;
	return(0);


}

void	reset_all_componants()
{
	ITEMPTR	litem;
	ITEMPTR	xitem;

	litem = Structure;

	while ( litem != (ITEMPTR) 0) {
		if ( litem->lock ) {
			litem->lock  = 0;
			litem->ligne = 0;
			xitem = litem->liste;
			while ( xitem != (ITEMPTR) 0 ) {
				xitem->ligne = xitem->adresse;
				if ( xitem->lock & _STATUS_FIN_LISTE )
					xitem->next = (ITEMPTR) 0;
				xitem->lock = 0;
				xitem       = xitem->next;
				}
			}
		litem = litem->next;
		}
	return;
}

void	perform_segment_inlining(handle)
EXAWORD	handle;
{
	ITEMPTR	litem;
	EXAWORD	segment;
	for ( segment = 0; segment < 255; segment++ ) {
		if ((litem = locate_item( _SEGMENT_ENTRY, segment )) != (ITEMPTR) 0) {
			LigneControl = 1;
			reset_level_control();
			componant_line();
			ResultSize = 0;
			(void) inline_componants(handle, litem, litem , 0 );
			componant_line();
			reset_all_componants();
			litem->keep = VRAI;
			}
		if ( Options.Verbose )
			oline();
		}
	return;
}

void	perform_procedure_inlining(handle)
EXAWORD	handle;
{
	EXAWORD	indent;
	EXAWORD	secteur;
	EXAWORD	longueur;
	EXAWORD	status;
	BPTR	lptr;
	ITEMPTR	litem;

	for ( indent = 0; indent < ln_PDT; indent += 16 ) {

		/* Collect data table sector */
		/* ------------------------- */
		if ((secteur = (tcSector((tc_PDT + indent + 4)))) != 0 ) {

			/* Collect Length and attempt to load data table */
			/* --------------------------------------------- */
			longueur = (tcGetw((tc_PDT + indent + 6)));

			if ((lptr = LoadBlock( handle, secteur, longueur )) != (BPTR) 0) {			

				/* Test for Procedure with Parameters */
				/* ---------------------------------- */
				status = local_variable_args( lptr );

				(void) StoreBlock( secteur, lptr );

				/* Perform the Inlining of this procedure */
				/* -------------------------------------- */
				if (( litem = locate_item( _PROCEDURE_ENTRY, indent )) != (ITEMPTR) 0) {

					/* If Procedure Takes Parameters */
					/* ----------------------------- */
					if (( status != 0 ) || ( litem->keep )) {

						LigneControl = 1;
						reset_level_control();
						componant_line();
						ResultSize = 0;
						(void) inline_componants( handle, litem, litem, 0 );
						componant_line();
						reset_all_componants();
						if (!( litem->keep ) )
							litem->keep = VRAI;
						}
					}
				}
			}
		}
	return;
}

void	remove_redundant_item( litem )
ITEMPTR	litem;
{
	struct	inline_control Redundant;

	reset_inline_context( &Redundant );

	if ( load_inline_context( & Redundant, litem ) != MOINS_UN ) {
		Redundant.code_sector = 0;
		Redundant.data_sector = 0;
		update_item_control_table( litem, & Redundant );
		}

	return;
}

void	structure_report_header()
{
	activate_output();
	oline(); oputs( "PROGRAM : "); oputs( ConstructionZone );
		 oputs( " : Structure Report" ); 
	if ( Options.Analyse & 0x0020 )
		oputs( " (with memory details)" );
	if ( program_has_been_optimised() )
		oputs( " : OPTIMISED" ); 
	oline(); 
	disactivate_output();
	return;
}

void	callers_report_header()
{
	activate_output();
	oline(); oputs( "PROGRAM : "); oputs( ConstructionZone );
		 oputs( " : CALLERS REPORT" ); 
	if ( program_has_been_optimised() )
		oputs( " : OPTIMISED" ); 
	oline(); 
	disactivate_output();
	return;
}

void	componant_report_header()
{
	activate_output();
	oline(); oputs( "PROGRAM : "); oputs( ConstructionZone );
		 oputs( " : COMPONANT REPORT" ); 
	oline(); 
	disactivate_output();
	return;
}

void	terminate_analysis(handle)
EXAWORD	handle;
{
	ITEMPTR	litem;
	ITEMPTR	xitem;
	CALLERPTR	lcall;
	EXAWORD	tempopt;

	disactivate_output();

	/* First Output Report on Structure */
	/* -------------------------------- */
	if ( Options.Analyse & 0x0080 ) {

		HiddenSegments = FAUX; LigneControl   = 1; ResultSize = 0;

		reset_level_control();
		structure_report_header();
		generate_analysis_report( locate_item(_SEGMENT_ENTRY, 0), 0, 0L );
		componant_line();

		if ( HiddenSegments )
			generate_all_segments();
	
		/* Reset all Base Nodes */
		/* -------------------- */
		HiddenSegments = FAUX; LigneControl   = 1; ResultSize = 0;

		reset_level_control();
		litem = Structure;
		while ( litem != (ITEMPTR) 0){
			litem->adresse = 0;
			litem->ligne   = 0;
			litem->lock    = 0;
			litem = litem->next;
			}
	
		/* Next Output Report on Callers */
		/* ----------------------------- */
		if ( Options.Analyse & 0x0040 ) {

			tempopt = Options.Analyse;
			Options.Analyse &= 0xFFDF;

			callers_report_header();

			litem = Structure;
			while ( litem != (ITEMPTR) 0 ) {
				generate_callers_report( litem, 0 );
				componant_line();
				componant_line();
				litem = litem->next;
				}
			Options.Analyse = tempopt;
			}
		}

	/* Test for Optimisation by Inlining */
	/* --------------------------------- */
	if ( Options.Inline ) {

		/* Generate Unique Componant Repport for SEG 0 */
		/* ------------------------------------------- */
		if ( Options.Verbose )
			componant_report_header();

		perform_segment_inlining(handle);

		perform_procedure_inlining(handle);

		}

	/* Dismantle Listes and Items Listes */
	/* --------------------------------- */
	while ((litem = Structure) != (ITEMPTR) 0) {
		Structure = litem->next;

		if (!(litem->keep))
			remove_redundant_item( litem );

		while ((xitem = litem->liste) != (ITEMPTR) 0) {
			litem->liste = litem->liste->next;
			free( xitem );
			}
		while ((lcall = litem->callers) != (CALLERPTR) 0) {
			litem->callers = litem->callers->next;
			free( lcall );
			}
		free( litem );
		}
	activate_output();
	return;
}

void	add_to_caller_list(xitem, xcaller )
ITEMPTR	xitem;
CALLERPTR	xcaller;
{
	CALLERPTR	lcaller;

	if ((lcaller = xitem->callers) == (CALLERPTR) 0) {
		xitem->callers = xcaller;
		}
	else	{
		while (( lcaller->next ) != (CALLERPTR) 0 )
			lcaller = lcaller->next;
		lcaller->next = xcaller;
		}
	return;
}

CALLERPTR	allocate_for_caller()
{
	CALLERPTR	citem;
	if ((citem = (CALLERPTR) malloc( sizeof ( struct caller_item ) )) != (CALLERPTR) 0 ) {
		citem->usercall = (ITEMPTR) 0;
		citem->owner    = (ITEMPTR) 0;
		citem->next   = (CALLERPTR) 0;
		citem->status = FAUX;
		}
	return( citem );
}

ITEMPTR	allocate_for_item()
{
	ITEMPTR	litem;

	if ((litem = (ITEMPTR) malloc( sizeof( struct program_structure ) )) != (ITEMPTR) 0) {
		litem->next  	= (ITEMPTR) 0;
		litem->liste 	= (ITEMPTR) 0;
		litem->callers  = (CALLERPTR) 0;
		litem->type  	= MOINS_UN;
		litem->identity = MOINS_UN;
		litem->lock  	= FAUX;
		litem->flag     = 0;
		litem->ligne    = 0;
		litem->adresse  = 0;
		litem->keep     = FAUX;
		litem->sd_adj	= 0;
		litem->sm_adj	= 0;
		}
	return( litem );

}
void	add_to_base_item_list( item )
ITEMPTR	item;
{
	ITEMPTR	litem;

	if ( Structure == (ITEMPTR) 0 )
		Structure = item;
	else	{
		litem = Structure;
		while ( litem->next ) 
			litem = litem->next;
		litem->next = item;
		}
	if ( (item->type & _BASIC_TYPE) == _SEGMENT_ENTRY )
		set_segment_options( item );

	return;
}

void	add_to_item_list( entry, item )
ITEMPTR	entry;
ITEMPTR	item;
{
	ITEMPTR	litem;
	CALLERPTR	lcaller;

	if ( entry->liste == (ITEMPTR) 0)
		entry->liste = item;
	else	{
		litem = entry->liste;
		while ( litem->next != (ITEMPTR) 0)
			litem = litem->next;
		litem->next = item;
		}

	if ((litem = locate_item(item->type,item->identity)) == (ITEMPTR) 0) {

		/* Forward Referenced Items May be Added to the list */
		/* ------------------------------------------------- */
		if ((litem = allocate_for_item()) != (ITEMPTR) 0) {
			litem->type 	 = item->type;
			litem->identity = item->identity;
			add_to_base_item_list( litem );
			}
		}

	if ((lcaller = allocate_for_caller()) != (CALLERPTR) 0 ) {
		lcaller->usercall = item;
		lcaller->owner    = entry;
		add_to_caller_list(litem, lcaller );
		}

	return;
}


EXAWORD	Analyser( sptr, si, slen )
BPTR	sptr;
EXAWORD	si;
EXAWORD	slen;
{
	EXAWORD	x;
	EXAWORD	z;
	ITEMPTR	current;
	ITEMPTR	xitem;

	/* Ensure Tcode analysis is invisible */
	/* ---------------------------------- */
	if (!( Options.Verbose ))
		disactivate_output();		


	/* Check for DATA and Ignore */
	/* ------------------------- */
	if ((x = tcGetw((sptr + slen - WORDSIZE))) != MOINS_UN)
		slen = x;
	else	slen -= WORDSIZE;

	/* Check if Code Block has already been forward referenced */
	/* ------------------------------------------------------- */
	if (( current = locate_item( ( MasterPhase!= 0 ? _SEGMENT_ENTRY : _PROCEDURE_ENTRY ) , ( MasterPhase!= 0 ? SegId : PrcId ) )) == (ITEMPTR) 0) {

		/* Allocate new code block control item */
		/* ------------------------------------ */
		if ((current = allocate_for_item()) == (ITEMPTR) 0) {
	
			/* Ensure Tcode analysis is visible */
			/* -------------------------------- */
			activate_output();

			/* Return Indication 'No Optimisation' */
			/* ----------------------------------- */
			return( 0 );

			}


		if ( MasterPhase) {
			current->type 	  = _SEGMENT_ENTRY;
			current->identity = SegId;
			/* printf("Segment : %u\n",SegId); */
			}
		else	{
			current->type 	  = _PROCEDURE_ENTRY;
			current->identity = PrcId;
			/* printf("Procedure : /%08.1X\n",PrcId); */
			}
		 
		/* Add item to Base List */
		/* --------------------- */
		add_to_base_item_list(current);

		}


	if ( statix & 2 )
		current->flag |= _FLAG_STATIC;

	xitem = (ITEMPTR) 0;

	/* Repeat till end of Code Block */
	/* ----------------------------- */
	while ( slen > WORDSIZE ) {

		if ( *(sptr + si) == 0x00FF )
			break;

		if ((Options.CheckFmt )
		/* Check for T-Code Format Strings */
		/* ------------------------------- */
		&& (((EXAWORD) *(sptr + si + 1)) == 0x00FE)) {

			/* Collect Preceeding Octet 		*/
			/* Presumed to be Format string  Length */
			/* ------------------------------------ */
			x = (((EXAWORD) *(sptr + si)));

			/* Test for not exceeding Current Segment */
			/* -------------------------------------- */
			if ( x < slen ) {

				/* Test for Valid End of Format Marker */
				/* ----------------------------------- */
				if (((EXAWORD) *(sptr + si + x)) == 0x00FF) {

					/* Check for GOTO or GOSUB */
					/* ----------------------- */
					if ((( *(sptr+si) & 0x007F ) == _tc_GSB ) || (( *(sptr+si) & 0x007F ) == _tc_JMI )) {
						z = tcGetw((sptr + si + 1));
						if (( z < (si + slen) ) && ( *(sptr + z) & 0x0080 ))
							z = MOINS_UN;
						}
					else	{
						z = 0;
						}
					if ( z == 0 ) {
						/* Looks like a Format String */
						/* -------------------------- */

						x++;

						si += x; slen-= x;
						continue;

						}
					}
				}
			}

		/* Interprete Possible Structural Element */
		/* -------------------------------------- */
		switch (( *(sptr + si) & 0x007F )) {

			case _tc_ESC :
			
				switch ( *(sptr + si + 1) ) {

					case 0x0070   :
						if (( Options.Inline ) && (!(Options.Segments)))
							break;
						if ((xitem = allocate_for_item()) == (ITEMPTR) 0) {
		
							/* Ensure Tcode analysis is visible */
							/* -------------------------------- */
							activate_output();
							return( 0 );
							}

						xitem->type 	  = _SEGMENT_ENTRY;
						xitem->identity   = tcGetw( (sptr + si + 2) );
						break;

					case _tc_SGI :

						if (( Options.Inline ) && (!(Options.Segments)))
							break;
						if ((xitem = allocate_for_item()) == (ITEMPTR) 0) {
		
							/* Ensure Tcode analysis is visible */
							/* -------------------------------- */
							activate_output();
							return( 0 );
							}

						xitem->type 	  = _SEGMENT_ENTRY;
						xitem->identity = *(sptr + si + 2);
						break;

					case _tc_SGR :
					case _tc_SGV :

						if ( Options.Inline )
							break;

						if ((xitem = allocate_for_item()) == (ITEMPTR) 0) {
		
							/* Ensure Tcode analysis is visible */
							/* -------------------------------- */
							activate_output();

							return( 0 );

							}

						xitem->type = _SEGMENT_ENTRY;
						xitem->identity = MOINS_UN;
						break;

					case _tc_CLP :

						/* Check if Procedures are Required */
						/* -------------------------------- */
						if ( Options.Analyse & 0x0002 ) {
							if (( *(sptr +si + 2) & 0x0010 ) && ( Options.Inline ))
								break;
							if ( *(sptr +si + 2) & 0x0060 ) 
								break;

							if ((xitem = allocate_for_item()) == (ITEMPTR) 0) {
		
								/* Ensure Tcode analysis is visible */
								/* -------------------------------- */
								activate_output();

								return( 0 );

								}

							xitem->type = _PROCEDURE_ENTRY;

							for ( x = 0;; x++) {
								if ( *(sptr + si + x + 2) & 1 )
									continue;
								x++;
								break;
								}

							xitem->identity = tcGetw((sptr + si + x + 2));
							}
						break;

					case _tc_RTP :
					case _tc_RTS :
					case _tc_STP :	

						if ( Options.Analyse & 0x0004 ) {

							if ((xitem = allocate_for_item()) == (ITEMPTR) 0) {
		
								/* Ensure Tcode analysis is visible */
								/* -------------------------------- */
								activate_output();

								return( 0 );

								}

							xitem->type = _EXIT_ENTRY;
							xitem->identity = tcGetw((sptr + si));

							}
						break;

					}

				break;

			case _tc_DTR :
			case _tc_DTV :
				current->flag |= _FLAG_DATA;
				break;

			case _tc_TIM :
				current->flag |= _FLAG_TIMER;
				break;

			case _tc_WHN :
				current->flag |= _FLAG_EVENT;
				break;

			case _tc_OER :
			case _tc_OEV :
			case _tc_ERA :
			case _tc_RES :
			case _tc_REQ :
				current->flag |= _FLAG_ERROR;
				break;

			case _tc_NGF :	

				if ( Options.Analyse & 0x0008 ) {

					if ((xitem = allocate_for_item()) == (ITEMPTR) 0) {

						/* Ensure Tcode analysis is visible */
						/* -------------------------------- */
						activate_output();
						return( 0 );

						}

					xitem->type = _FILE_ENTRY;
					xitem->identity = tcGetw((sptr + si));

					}
				break;


			}

		/* Check for New Item Found */
		/* ------------------------ */
		if ( xitem != (ITEMPTR) 0 ) {
			xitem->adresse = si;
			xitem->ligne   = si;
			add_to_item_list( current, xitem );
			xitem = (ITEMPTR) 0;
			}					

		/* Calculate Length of Tcode Sequence */
		/* ---------------------------------- */
		if ((x = TcodeList(sptr, si, 0)) == 0)
			break;

		/* Position to Next Sequence */
		/* ------------------------- */
		si += x; if ( slen > x )
				slen -= x;  
			 else  slen = 0;

		}

	/* Ensure Tcode analysis is visible */
	/* -------------------------------- */
	activate_output();

	/* Return Indication 'No Optimisation' */
	/* ----------------------------------- */
	return( 0 );

}



#endif	/* _AOSTRUCT_C */
	/* ----------- */

