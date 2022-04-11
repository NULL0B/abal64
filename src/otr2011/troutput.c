#define	DEBUG
#define	SYMBOLIC_OFFSET
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TROUTPUT.C				*/
/*		Version :	2.1d					*/
/*		Date	:	08/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TROUTPUT_C
#define	_TROUTPUT_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include <fcntl.h>
#include <string.h>
#ifdef	WIN32
#include <io.h>
#include <sys/stat.h>	/* For _S_IREAD and _S_IWRITE */
#endif
#include "stdtypes.h"
#include "translat.h"
#include "troption.h"
#include "trtcode.h"
#include "trevent.h"
#include "trexpres.h"
#include "trproc.h"
#include "triof.h"
#include "troutput.h"
#include "trsyntax.h"
#include "trclf.h"
#include "trnurone.h"
#include "trdebug.h"
#include "trparser.h"
#include "trerrors.h"
#include "trmethod.h"
#include "trinput.h"
#include "trecho.h"
#include "triter.h"
#include "trtables.h"
#include "trdirect.h"
#include "trlabels.h"
#include "trngf.h"
#include "trldf.h"
#include "trmain.h"
#include "trabal.h"
#include "tratropt.h"
#ifdef	WIN32
#include "fnparser.h"
#endif

#ifndef	UNIX
#else
WORD		generate_affectation( TCVARPTR, RESULTPTR, WORD);
BPTR		abal_crypt();
RESULTPTR	variable_result();
WORD		tcode_procedure();
WORD		tcode_library_identity();
VOID		put_sector_word();
#endif

WORD	ForceLDV=FAUX;

#define ENCODE 	1
#define	DECODE	0

#ifndef	O_BINARY
#define	O_BINARY 0
#endif

EXTERN	WORD	GlobalError;

WORD	DataUsed=0;
static	WORD	DebugLevel=0;
static	WORD	AutoConvAllowed=0;

VOID	AllowAutoConv( mode )
WORD mode;
{
	AutoConvAllowed=mode;
	return;
}

WORD	IsAutoConv()	{	return( AutoConvAllowed );	}

VOID	next_sector()
{
	if (!( Target )) return;
	Target->OutputSector++;
	if (( Target->CodeSector )
	&& ((Target->OutputSector - Target->CodeSector) > MAXOTRSECTORS )) {
		Target->OutputSector--;
		syntax_error( 8998 );
		Target->OutputPosition =0;
		}
	else	Target->OutputPosition += SECTORSIZE;
	return;
}

VOID	first_sector()
{
	if (!( Target )) return;
	Target->OutputSector = 0;
	Target->OutputPosition = 0L;
	return;
}

VOID	reset_output()
{
	if (!( Target )) return;
	Target->OutputIndex = 0;
	memset( Target->OutputBuffer, BYTEMASK, SECTORSIZE );
	return;
}

VOID	tcputlong( BPTR bptr, long v )
{
	*(bptr++) = ( v & BYTEMASK );
	*(bptr++) = ((v >>  8) & BYTEMASK );
	*(bptr++) = ((v >> 16) & BYTEMASK );
	*(bptr++) = ((v >> 24) & BYTEMASK );
	return;
}

VOID	write_target()
{
	if (( OtrOption.Generate )
	&&  (!( GlobalError ))) {
		(void) lseek( Target->OutputHandle, Target->OutputPosition, 0 );
		if (( Target->CryptCode )
		&&  ( Target->CryptCode != MOINS_UN ) 
		&&  ( Target->OutputPosition != 0L )) {
			(void) abal_crypt( Target->CryptCode,Target->OutputBuffer, HEADERSIZE,  ENCODE );
			}
		if ( write( Target->OutputHandle, Target->OutputBuffer, HEADERSIZE ) != HEADERSIZE )
			syntax_error( 1 );
		}
	return;
}

WORD	current_target_sector()
{
	if (!( Target )) 
		return(0);
	else	return( Target->OutputSector );
}

WORD	current_sector_offset()
{
	if (!( Target )) 
		return(0);
	else	return( Target->OutputIndex );
}

WORD	current_tcode_offset()
{
	if (!( Target )) 
		return(0);
	else	return( Target->OutputBytes );
}

VOID	echo_target_offset( FILE * h )
{
	if ( Target ) {
#ifdef	otr32
		if (!( h ))
			sysprintf(" %08.8x ",Target->OutputBytes);
		else	fprintf(h," %08.8x ",Target->OutputBytes);
#else
		if (!( h ))
			sysprintf(" %04.4x ",Target->OutputBytes);
		else	fprintf(h," %04.4x ",Target->OutputBytes);

#endif
		}
	return;
}


VOID	print_hex_nibble( v )
WORD	v;
{
	v &= 0x000F;
	if ( v > 9 )
		sysprintf("%c",(v-10)+'A');
	else	sysprintf("%c",(v+'0'));
	return;
}

VOID	trace_output()
{
	WORD	i,o,v;
	if (!( Target )) return;
	sysprintf("\nFile %s Sector %u \n",Target->OutputName,Target->OutputSector);
	for ( o = 0; o < 16; o++ ) {
		sysprintf("\t");
		for ( i = 0; i < 16; i++ ) {
			v = Target->OutputBuffer[(o*16)+i];
			print_hex_nibble( v >> 4 );
			print_hex_nibble( v );
			sysprintf(" ");
			}
		sysprintf("\n");
		}
	return;
}

SECTORPTR	allocate_for_sector()
{
	SECTORPTR	sptr;

	if ((sptr = SectorHeap) != (SECTORPTR) 0)
		SectorHeap = SectorHeap->next;
	else if ((sptr = (SECTORPTR) allocate( sizeof( struct otr_sector ))) != (SECTORPTR) 0 ) {
		memset( sptr->buffer, MOINS_UN, SECTORSIZE );
		sptr->next = (SECTORPTR) 0;
		}
	return( sptr );
}

VOID	store_sector()
{
	SECTORPTR	sptr;
	if (!( Target )) return;
	if ((sptr = allocate_for_sector()) != (SECTORPTR) 0) {
		memcpy(sptr->buffer,Target->OutputBuffer,SECTORSIZE);
		Target->CodeSectors[(Target->OutputSector - Target->CodeSector)] = sptr;
		}
}

VOID	flush_to_target()
{
	trace("flush_to_target()\n");
	if (!( Target )) return;
	if ( Target->CodeSector == 0 ) {
		write_target();
		if ( OtrOption.TargetTrace )
			trace_output();
		reset_output();
		}
	else	store_sector();
	reset_output();
	next_sector();
	return;
}

VOID set_accelerator_begin()
{
	if (!( Target )) return;
	Target->AcceleratorOutputBytes = Target->OutputBytes;
}

VOID set_accelerator_end()
{
	if (!( Target )) return;
	put_sector_word( Target->AcceleratorOutputBytes, Target->OutputBytes - Target->AcceleratorOutputBytes);
}

VOID	tcputbyte( v )
WORD	v;
{
	if (!( Target )) return;
	Target->OutputBytes++;
	Target->OutputBuffer[Target->OutputIndex++] = (BYTE) v;
	if ( Target->OutputIndex >= SECTORSIZE )
		flush_to_target();
	return;
}	

VOID	tcputword( v )
WORD	v;
{
	tcputbyte( v & BYTEMASK );
	tcputbyte( (v >> 8) & BYTEMASK );

#ifdef	otr32
	if ( OtrOption.WordSize > 2 ) {
		tcputbyte( (v>>16) & BYTEMASK );
		tcputbyte( (v>>24) & BYTEMASK );
		}
#endif
	return;
}

WORD	NewLineFlag = _tc_NEWLINE;

VOID	force_newline()
{
	if ( NewLineFlag == _tc_NEWLINE )
		NewLineStatus = NewLineFlag;
	return;
}

VOID	signal_new_line(mode)
WORD	mode;
{
	reset_affectation(0);
	if ( World->CurrentStructure == (TCSTRUCTPTR) 0 ) {
		trace("signal_new_line()\n");
		release_expressions(mode);
		if ( NewLineFlag == _tc_NEWLINE ) {
			NewLineStatus = NewLineFlag;
			allow_construction();
			}
		}
	return;
}

VOID	inhibit_source_newline()
{
	NewLineStatus = NewLineFlag;
	NewLineFlag = 0;
	return;
}

VOID	allow_source_newline()
{
	NewLineStatus = NewLineFlag = _tc_NEWLINE;
	return;
}


WORD	tcode_integer( n )
WORD	n;
{
	tcputword( n );
	return(0);
}

VOID	tcode_string( token )
BPTR	token;
{
	while ( *token )
		tcputbyte( *(token++) );
	tcputbyte(0);
}

#ifdef	WITH_NURAL
WORD	generate_nurone_entry(nptr, uptr )
NURONETPTR	nptr;
NURONEPTR	uptr;
{
	WORD		status;
	TCVARPTR	vptr;
	WORD	i;
	WORD	n;
	if ( uptr != (NURONEPTR) 0) {
		trace("generate_nurone_entry()\n");
		if ( uptr->output != (TCVARPTR) 0)
			tcode_integer( uptr->output->type->type );
		else	tcode_integer( 0 );
		tcode_integer( uptr->nature );
		tcode_string(  uptr->name );
		tcode_integer( uptr->inputs );
		for (vptr = uptr->input, i = 0; i < uptr->inputs; i++ ) {
			if ( uptr->state == _INPUT_LAYER )
				n = input_synapse_identity( nptr->input, vptr->name );
			else	n = nurone_identity( nptr, vptr->name );
			tcode_integer( n );
			if ((vptr = vptr->next) == (TCVARPTR) 0)
				break;
			}
		}
	return( 0 );

}

WORD	generate_network_header( nptr )
NURONETPTR	nptr;
{
	TCVARPTR	vptr;
	if ( nptr != (NURONETPTR) 0 ) {
		trace("generate_network_header()\n");
		tcode_integer( nptr->identity );
		tcode_string( nptr->name );
		tcode_integer( nptr->nurones  );
		tcode_integer( nptr->inputs   );
		tcode_integer( nptr->weights  );
		tcode_integer( (OtrOption.Symbolic & 1) );
		if ((vptr = nptr->input) != (TCVARPTR) 0) {
			do	{
				if ( vptr->type == (TCTYPPTR) 0)
					return( internal_error(119) );
				else	tcode_integer( vptr->type->type );
				}
			while ((vptr = vptr->next) != (TCVARPTR) 0);
			}
		}
	return( 0 );
}

#endif
VOID	symbolic_module_entry( fptr, n )
BPTR	fptr;
WORD	n;
{
	if (( OtrOption.Symbolic )
	&&  (DebugTarget != (OUTPUTPTR) 0)) {
		Target = DebugTarget;
		tcode_integer( n );
		tcode_string( fptr );
		Target = TcodeTarget;
		}
	return;
	
}

VOID	symbolic_file_entry( fptr, n )
BPTR	fptr;
WORD	n;
{
	if (( OtrOption.Symbolic )
	&&  (DebugTarget != (OUTPUTPTR) 0)) {
		Target = DebugTarget;
		tcode_integer( n );
		if ( fptr != (BPTR) 0 )
			tcode_string( fptr );
		Target = TcodeTarget;
		}
	return;
	
}

#include "trcorres.c"


WORD	tcode_instruction( n )
WORD	n;
{
	if ( NewLineStatus ) {
		if ( OtrOption.ListFlag & 1 )
			echo_newline();
		if ( OtrOption.Symbolic )
			symbolic_correspondance();
		}
/* sysprintf("Instruction %02.1X @ %04.1X \n",n,Target->OutputBytes); */
	tcputbyte( (n | NewLineStatus) );
	NewLineStatus = 0;
	return(0);
}

WORD	tcode_label( n )
WORD	n;
{
	tcputword( n );
	return(0);
}

WORD	implicite_label( n )
WORD	n;
{
	tcode_label( use_implicite_label( n , 0 ) );
	return(0);
}

WORD	tcode_constant( cptr )
TCCONPTR	cptr;
{
	WORD	status;
	if (!( Target )) return(0);
	if ( context_is_module )
		if (!( OtrOption.LocalConstant ))
			if ((status = add_constant_rellocation( cptr,Target->OutputSector, Target->OutputIndex  )) != 0)
				return( status );

	tcputword( cptr->identity );
	return(0);
}

WORD		tcode_variable( vptr )
TCVARPTR	vptr;
{
	WORD	status;
	if (!( Target )) return(0);
/*	sysprintf("tcode_variable(%s)\n",vptr->name);	*/
	if ( vptr->descriptor == 0 )
		if ((status = mark_variable( vptr )) != 0)
			return( status );

	/* Check for Rellocation Required */
	/* ------------------------------ */
	if (( vptr->nature )
	||  ( context_is_module ))
		if ((status = add_variable_rellocation( vptr,Target->OutputSector, Target->OutputIndex  )) != 0)
			return( status );

	if ( vptr->nature ) {
		/* This is the old ATR/ALD bug for 16bit */
		if ( OtrOption.WordSize > 2 )
			tcputword( vptr->descriptor );
		else	tcputword(( vptr->descriptor | 0xC000 ));
		}
	else	tcputword( vptr->descriptor );

	return(0);
}

WORD	tcode_variable_offset( vptr )
TCVARPTR	vptr;
{
	WORD	status;
	/* Check for Rellocation Required */
	/* ------------------------------ */
	if (!( Target )) return(0);
	
	if (( vptr->nature )
	||  ( context_is_module ))
		if ((status = add_variable_rellocation( vptr,Target->OutputSector, (Target->OutputIndex | 0xFF00)  )) != 0)
			return( status );

	if ( vptr->nature ) 
		tcputword(( MOINS_UN ));
	else	tcputword((WORD) vptr->offset );
	return(0);
}
WORD	tcode_register( n )
WORD	n;
{
	tcputbyte( n );
	return(0);
}

WORD	generate_byte( b )
WORD	b;
{
	tcputbyte( b );
	return( 0 );
}

WORD	generate_constant( cptr )
TCCONPTR	cptr;
{
	BPTR	vptr;
	WORD	i;
	WORD	hlc;
	if ( cptr != (TCCONPTR) 0 ) {

		if ( cptr->redirect ) {
			/* Linkage from Local to Global Constant Table */
			/* ------------------------------------------- */
			hlc = OtrOption.LocalConstant;
			OtrOption.LocalConstant=0;
			cptr = cptr->redirect;
			tcputbyte(0); tcputbyte(0x0080);
			tcode_constant( cptr );
			OtrOption.LocalConstant=hlc;
			}
		else if (( cptr->type != (TCTYPPTR) 0)
	      	     &&  ((vptr = cptr->value) != (BPTR) 0)
		     &&  ((cptr->type->type & 3) > 1)) {
			if ( (cptr->type->type & _TYPE_BASIC) == 3 ) {

				/* STRING Constant */
				/* --------------- */
				tcputbyte( cptr->length );
				while ( *vptr )
					tcputbyte( *(vptr++) );

				}
			else	{
				/* BCD Constant */
				/* ------------ */
				tcputbyte(0);
				tcputbyte( cptr->length );
				for ( i = 0; i < cptr->length; i++ )
					tcputbyte( *(vptr++) );				

				}
			}
		}
	return( 0 );
}

VOID	generate_data_item( t, l, vptr )
WORD	t;
WORD	l;
BPTR	vptr;
{
	WORD	i;
	if ( t == 3 ) {

		/* STRING Constant */
		/* --------------- */
		tcputbyte( l );
		while ( *vptr )
			tcputbyte( *(vptr++) );

		}
	else	{
		/* BCD Constant */
		/* ------------ */
		tcputbyte(0);
		tcputbyte( l );
		for ( i = 0; i < l; i++ )
			tcputbyte( *(vptr++) );				

		}
	return;
}

VOID	output_symbolic_variable( vptr )
TCVARPTR	vptr;
{

	Target = DebugTarget;
	tcode_string( vptr->name );
	tcode_integer( (vptr->descriptor & TOGLOBAL) );
	Target = TcodeTarget;
	return;
}

WORD	generate_descriptor( vptr, mode )
TCVARPTR	vptr;
WORD		mode;
{
	WORD	t;

	if (!( vptr->type->size))
		return( 0 );

	if (( OtrOption.Symbolic )
	&&  ( mode ))
		output_symbolic_variable(vptr);

	/* Remove Structure Signal Bit (ATR HOLE BIT) */
	/* ------------------------------------------ */
	tcputword( ((t = vptr->type->type) & 0xFF6F) );

	if ( t & 0x8000 ) {
		if ( t & 0x2000 )
			tcode_integer( vptr->host );
		}


#ifdef	otr32
	tcputword(((WORD) (vptr->offset & 0xFFFFFFFF)));
	if ((!( t & 0x8000 )) &&  ( t & 0x7F00 ))
		tcputword( (WORD)(vptr->offset >> 32) );
#else
	tcputword((WORD)(vptr->offset & 0xFFFF) );
	if ((!( t & 0x8000 ))
	&&  ( t & 0x7F00 ))
		tcputword((WORD) (vptr->offset >> 16) );
#endif
	if (( t & 3 ) > 1)
		tcode_integer(vptr->type->size);

	if ( t & _TYPE_FIRST ) {
		tcode_integer(vptr->type->first);
		if ( t & _TYPE_SECOND ) 
			tcode_integer(vptr->type->second);
		}
	return(0);
}

VOID	reset_byte_count()
{
	if (!( Target )) return;
	Target->OutputBytes = 0;
	return;
}

WORD	output_byte_count()
{
	if (!( Target )) return(0);
	else	return( Target->OutputBytes );
}

WORD	next_debug_sector()
{
	if ((OtrOption.Symbolic)
	&&  (DebugTarget != (OUTPUTPTR) 0))
		return( DebugTarget->OutputSector );
	else	return( 0 );
}

WORD	generate_data_table( tptr, fptr, mode )
TCVDTPTR	tptr;
FIELDPTR	fptr;
WORD		mode;
{
	WORD	globsize=0;
	if ( fptr != (FIELDPTR) 0)
		globsize = fptr->MaxSmallField;	
	trace("generate_data_table()\n");
	reset_byte_count();
	if (( tptr->nombre != 0 )
	||  ( globsize != 0     )) {
		tcode_integer( tptr->nombre );
		if ( mode ) {
			if ( OtrOption.Symbolic )
				tcode_integer( next_debug_sector() );
			else	tcode_integer( 0 );
			if ( fptr != (FIELDPTR) 0 )
				tcode_integer( fptr->MaxSmallField );
			else	tcode_integer( 0 );
			}
		else	{
			tcode_integer( 0 );
			tcode_integer( 0 );
			}

#ifdef	WITH_ATOC
		if (!( OtrOption.Generate ))
			atoc_variables( tptr, Context->scope, globsize );
#endif
		return( VRAI );
		}
	else	return( FAUX );
}


VOID	generate_function_entry( lptr )
TCDLBPTR	lptr;
{
	WORD	i;
	WORD	n;
	if ( lptr != (TCDLBPTR) 0 ) {
		trace("generate_function_entry()\n");
		if ( OtrOption.Verbose & 4 )
			sysprintf("DLL : %s \n",lptr->name);
		tcode_string( lptr->name );
		tcputbyte( (lptr->functions & 0x00FF) /* merci claude */ );
		/* was tcode_integer( lptr->functions ); */
		tcputbyte( (lptr->options & 0x00FF) );
		n = (18 - 2);
		for ( i = 0; i < n; i++ )
			tcputbyte(0);

		}
	return;
}

VOID	symbolic_segment_entry( sptr )
TCSEGPTR	sptr;
{
	if (( sptr != (TCSEGPTR) 0 )
	&&  ( OtrOption.Symbolic )
	&&  (DebugTarget != (OUTPUTPTR) 0)) {
		trace("symbolic_segment_entry()\n");
		Target = DebugTarget;
		if ( sptr != (TCSEGPTR) 0)
			tcode_string(sptr->name);
		else	tcputbyte(0);
		tcode_integer( sptr->identity );
		tcode_integer( sptr->offset );

		tcode_integer( sptr->sector_XRF );
		tcode_integer( sptr->symbolic.sector );
		tcode_integer( sptr->symbolic.length );
		Target = TcodeTarget;
		}
	return;
}

VOID	generate_procedure_paratypes( pptr )
TCPRCPTR	pptr;
{
	TCVARPTR	vptr;
	WORD		nombre=0;
	WORD		args=0;

	trace("generate_procedure_paratypes()\n");
	switch (( pptr->options & 0x7700 )) {
		case	_INT8_PROC	: /* 0x0100 */
			if ( pptr->options & _PTR_PROC )
				nombre = 0x8800;
			else	nombre = 0x0800;
			break;
		case	_INT16_PROC	: /* 0x0200 */
			if ( pptr->options & _PTR_PROC )
				nombre = 0x9800;
			else	nombre = 0x1800;
			break;
		case	_NUMERIC_PROC	: /* 0x0300 */
			if ( pptr->options & _PTR_PROC )
				nombre = 0xA800;
			else	nombre = 0x2800;
			break;
		case	_STRING_PROC	: /* 0x0400 */
		case	_PROC_PROC	: /* 0x1000 */
		case	_SEGM_PROC	: /* 0x2000 */
		case	_USER_PROC	: /* 0x4000 */
		case	_CODE_PROC	: /* 0x7000 */
			if ( pptr->options & _PTR_PROC )
				nombre = 0xB800;
			else	nombre = 0x3800;
			break;
		}

	if ((vptr = pptr->parameter) != (TCVARPTR) 0) {
		do	{
			args++;
			}
		while ((vptr = vptr->next) != (TCVARPTR) 0);
		}
	tcode_integer( (nombre | args) );
	if ((vptr = pptr->parameter) != (TCVARPTR) 0) {
		do	{
			if (( vptr->type->type & _TYPE_POINTER ) == _TYPE_POINTER)
				tcputbyte( ((vptr->type->type & _TYPE_BASIC ) | 0x0008 ));
			else	tcputbyte( (vptr->type->type & _TYPE_BASIC ) );
			}
		while ((vptr = vptr->next) != (TCVARPTR) 0);
		}
	trace("end of generate_procedure_paratypes()\n");
	return;
}

WORD	generate_cross_references( xptr )
XREFPTR	xptr;
{
	WORD	secteur;
	if ( xptr == (XREFPTR) 0 )
		return( 0 );
	trace("generate_cross_references()\n");
	Target = DebugTarget;
	secteur = next_debug_sector();
	do	{
		tcputbyte( xptr->type );
		tcode_integer( xptr->identity );
		tcode_integer( xptr->sector );
		tcode_integer( xptr->offset );
		}
	while ((xptr = xptr->next ) != (XREFPTR) 0);
	tcode_integer( MOINS_UN );
	flush_to_target();
	Target = TcodeTarget;
	return( secteur );
}

VOID		generate_code_rellocation( rptr )
RELOCPTR	rptr;
{
	if (rptr != (RELOCPTR) 0) {
		do	{
			tcode_integer( rptr->sector );
			tcode_integer( rptr->length );
			}
		while ((rptr = rptr->next) != (RELOCPTR) 0);
		}
	tcode_integer( 0 );		
	return;
}

VOID		generate_library_rellocation( WORD lid, RELOCPTR rptr )
{
	if (rptr != (RELOCPTR) 0) {
		do	{
			tcputbyte( lid );
			tcode_integer( rptr->sector );
			tcode_integer( rptr->length );
			}
		while ((rptr = rptr->next) != (RELOCPTR) 0);
		}
	return;
}

WORD	generate_external_member( xptr )
XTVARPTR	xptr;
{
	TCVARPTR	vptr;
	if (( xptr != (XTVARPTR) 0 )
	&&  ((vptr = xptr->variable) != (TCVARPTR) 0)) {
		trace("generate_external_member()\n");
		tcode_string( vptr->name );
		tcode_integer( (vptr->identity & TOGLOBAL) );
		generate_code_rellocation( vptr->relocation );
		}
	return(0);
}

VOID	generate_external_procedure( pptr )
TCPRCPTR	pptr;
{
	if ( pptr != (TCPRCPTR) 0 ) {
		trace("generate_external_procedure()\n");
		if ( OtrOption.Verbose )
			printf("Extern Proc %s \n",pptr->name);
		tcode_integer( pptr->module );
		tcode_string( pptr->name );
		generate_procedure_paratypes( pptr );
		generate_code_rellocation( pptr->relocation );
		}
	return;
}

VOID	generate_external_local( fptr )
XTLOCALPTR	fptr;
{
	if ( fptr != (XTLOCALPTR) 0) {
		trace("generate_external_local()\n");
		tcode_integer( fptr->number );
		tcode_integer( fptr->sector );
		tcode_integer( fptr->length );
		}
	return;
}

VOID	generate_external_field( fptr )
XTFIELDPTR	fptr;
{
	if ( fptr != (XTFIELDPTR) 0) {
		trace("generate_external_field()\n");
		tcode_integer( fptr->module );
		if ( fptr->name != (BPTR) 0 )
			tcode_string( fptr->name );
		else	tcputbyte( 0 );
		tcputbyte( fptr->nature );
		if ( fptr->nature & 0x0010 )
			tcputword( fptr->entry_XLT );
		tcputword((WORD) fptr->offset );
		tcputword((WORD) (fptr->offset >> 16) );
		tcode_integer( fptr->sector_XVT );
		}
	return;
}

VOID	generate_external_segment_entry( sptr )
XTSEGPTR	sptr;
{
	if ( sptr != (XTSEGPTR) 0 ) {
		trace("generate_external_segment_entry()\n");
		tcode_integer( sptr->module_number );
		tcode_string( sptr->name );
		tcode_integer( sptr->number );
		generate_code_rellocation( sptr->relocation );
		}
	return;
}

VOID	generate_data_label( TCLABELPTR lptr )
{
	if ( lptr != (TCLABELPTR) 0 ) {
		tcode_string( lptr->name );
		tcputbyte( lptr->field );
		tcode_integer( lptr->value );
		tcode_integer( 0 );
		}
	return;
}

VOID	generate_segment_entry( TCSEGPTR sptr )
{
	WORD	i;
	if ( sptr != (TCSEGPTR) 0 ) {
		if ( OtrOption.Symbolic )
			symbolic_segment_entry( sptr );
		trace("generate_segment_entry()\n");
		if ( OtrOption.Verbose & 1024 ) {
			sysprintf("Segment %u tc(%u,%u), lv(%u,%u), lc(%u,%u)\n",
				sptr->identity,
				sptr->details->code_sector,
				sptr->details->code_length,
				sptr->details->table_sector,
				sptr->details->table_length,
				sptr->details->const_sector,
				sptr->details->const_length);
				}
		tcode_integer( sptr->identity );
		tcode_integer( sptr->details->code_sector );
		tcode_integer( sptr->details->code_length );
		tcode_integer( sptr->details->table_sector );
		tcode_integer( sptr->details->table_length );
		tcode_integer( sptr->options );
		tcode_integer( sptr->details->const_sector );
		tcode_integer( sptr->details->const_length );
		for ( i = 0; i < 4 ; i++ )
			tcode_integer( 0 );
		}
	return;
}

VOID	symbolic_procedure_entry( pptr )
TCPRCPTR	pptr;
{
	WORD		args=0;
	WORD		nombre=0;

	if (( pptr != (TCPRCPTR) 0 )
	&&  ( DebugTarget != (OUTPUTPTR) 0)) {
		trace("symbolic_procedure_entry()\n");
		Target = DebugTarget;
		tcode_string(pptr->name);
		tcode_integer( pptr->identity );
		tcode_integer( pptr->sector_XRF );
		tcode_integer( pptr->symbolic.sector );	/* Sector Corresp 	*/
		tcode_integer( pptr->symbolic.length );	/* Length Corresp 	*/
		generate_procedure_paratypes( pptr );
		Target = TcodeTarget;
		trace("end of symbolic_procedure_entry()\n");
		}
	return;
}

VOID	start_symbolic_procedures()
{
	if (( OtrOption.Symbolic )
	&&  ( DebugTarget != (OUTPUTPTR) 0)) {
		trace("start_symbolic_procedures()\n");
		Target = DebugTarget;
		Context->Symbolic.sector_ProcedureNames = next_debug_sector();
		tcode_integer( Context->ProcedureCount );
		Target = TcodeTarget;
		}
	return;
}

WORD	start_export_procedures()
{
	WORD	sector;
	trace("start_export_procedures()\n");
	Target = TcodeTarget;
	sector = current_target_sector();
	reset_byte_count();     
	tcode_integer( Context->ExpliciteExport );
	tcode_integer( 0 );
	return( sector );
}

VOID	export_procedure_record(TCPRCPTR pptr)
{
	trace("export_procedure_record()\n");
	Target = TcodeTarget;
	tcode_string(pptr->name);
	tcode_integer( pptr->identity );
	return;
}

VOID	start_symbolic_segments()
{
	if (( OtrOption.Symbolic )
	&&  ( DebugTarget != (OUTPUTPTR) 0)) {
		trace("start_symbolic_segments()\n");
		Target = DebugTarget;
		Context->Symbolic.sector_SegmentNames = next_debug_sector();
		tcode_integer( Context->SegmentCount );
		Target = TcodeTarget;
		}
	return;
}

static	WORD	tcode_procedure_options( options )
WORD	options;
{
	WORD	result=0;
	if ( options & _DIFFERED_PROC )
		result |= 0x0008;
	if ( options & _STATIC_PROC  )
		result |= 0x0002;
	return( result );
}

VOID	generate_procedure_entry( pptr )
TCPRCPTR	pptr;
{
	WORD	i;
	if ( pptr != (TCPRCPTR) 0 ) {
		trace("generate_procedure_entry()\n");
		/* sysprintf("ProcTable[%u]=%s\n",pptr->identity,pptr->name); */
		if ( OtrOption.Symbolic )
			symbolic_procedure_entry( pptr );
		if ( pptr->details ) {
			tcode_integer( pptr->details->code_sector );
			tcode_integer( pptr->details->code_length );
			tcode_integer( pptr->details->table_sector );
			tcode_integer( pptr->details->table_length );
			tcode_integer( pptr->details->const_sector );
			tcode_integer( pptr->details->const_length );
			tcode_integer( 0 );
			tcode_integer( tcode_procedure_options( pptr->options ) | ( pptr->isexport ? 0x04 : 0) );
			}
		else	{
			strcpy(TokenBuffer,pptr->name);
			issue_warning( 16 );
			for ( i = 0; i < 8 ; i++ )
				tcode_integer( 0 );
			}
		trace("end of generate_procedure_entry()\n");
		}
	return;
}


WORD	generate_pause( rptr )
RESULTPTR	rptr;
{
	if (!( rptr = mark_dead_result( rptr )))
		return(999);
	if ( OtrOption.ListFlag & 1 )
		echo_pause(rptr);
	tcode_instruction( _tc_ESC   );
	switch ( rptr->nature ) {
		case _RESULT_INT   :
			tcputbyte( _esc_PSI  );
			tcode_integer( rptr->value );
			break;
		case _RESULT_CONST :
			tcputbyte( _esc_PSC  );
			tcode_constant( rptr->contents );
			break;
		case _RESULT_ALIAS :
		case _RESULT_VARB  :
		case _RESULT_VPTR  :
			tcputbyte( _esc_PSV    );
			tcode_variable( rptr->contents );
			break;
		case _RESULT_ALEXPR  :
		case _RESULT_EXPR  :
			if ((rptr = mark_dead_result( rptr )) == (RESULTPTR) 0)
				return( internal_error(8) );
			tcputbyte( _esc_PSR    );
			tcode_register( rptr->value );
			break;
		default		   :
			return( 999 );

		}
	return( 0 );
}

WORD	tc_operand( type )
WORD	type;
{
	switch ( type ) {
		case _RESULT_INT   : return( 0      );
		case _RESULT_CONST : return( 0x0020 );
		case _RESULT_ALIAS :
		case _RESULT_VPTR  :
		case _RESULT_VARB  : return( 0x0040 );
		case _RESULT_ALEXPR  :
		case _RESULT_EXPR  : return( 0x0060 );
		default		   : return( 0x00FF );
		}
}
VOID	tcode_operand( xptr )
RESULTPTR	xptr;
{
/*	sysprintf("tcode_operand(%x)\n",xptr->nature);	*/
	switch ( xptr->nature ) {
		case _RESULT_PROCPTR :
			tcode_procedure( xptr->contents );
			break;

		case _RESULT_USERPTR :
			tcode_library_identity( xptr->contents,2 );
			break;

		case _RESULT_SEGMPTR :
		case _RESULT_ALEXPR  :
		case _RESULT_EXPR : tcode_register( xptr->value );
			break;
		case _RESULT_ALIAS :
		case _RESULT_VPTR :
		case _RESULT_VARB : tcode_variable( xptr->contents ); break;
		case _RESULT_CONST: tcode_constant( xptr->contents ); break;
		case _RESULT_INT  : tcode_integer ( xptr->value ); break;
		}
	return;
}


WORD	generate_push( r )
WORD	r;
{
	tcode_instruction( _tc_PSH );
	tcode_register( r );
	return(0);
}

WORD	generate_pop( r )
WORD	r;
{
	tcode_instruction( _tc_POP );
	tcode_register( r );
	return(0);
}

WORD	generate_proc_end()
{
	if ( OtrOption.ListFlag & 1 )
		echo_instruction("END.PROC");
	tcode_instruction( _tc_ESC );
	tcputbyte( _esc_ETP );
	return( 0 );
}

WORD		generate_exit(rptr)
RESULTPTR	rptr;
{
	trace("generate_exit()\n");
	if (!( pragma_exit() ))  {
		tcode_instruction( _tc_ESC   );
		tcputbyte( _esc_RTP  );
		if ( OtrOption.ListFlag & 1 )
			echo_exit(rptr);
		return( 0 );
		}
	else	return( generate_proc_end() );
}

WORD	generate_segm_end()
{
	if ( OtrOption.ListFlag & 1 )
		echo_instruction("END.SEG");
	tcode_instruction( _tc_ESC );
	tcputbyte( _esc_ETS );
	return( 0 );
}

WORD	generate_error_abort()
{
	if ( OtrOption.ListFlag & 1 )
		echo_instruction("ON ERROR ABORT");
	tcode_instruction( _tc_ERA );
	return( 0 );
}


WORD	of_requires_register() { return((ForceLDV=VRAI)); }
WORD	of_release_register()  { return((ForceLDV=FAUX)); }

WORD	instruction_requires_LDV(int mode) 
{ 
	WORD	result=ForceLDV;
	ForceLDV=mode;
	return(result);
}

WORD		generate_of( rptr, mode )
RESULTPTR	rptr;
WORD		mode;
{
	WORD	result;
	tcode_instruction( _tc_ESC );
	if ( mode )
		tcode_instruction( _esc_GSR );
	else	tcode_instruction( _esc_JMR );
	tcode_register( rptr->value );
	result = current_tcode_offset();
	tcode_label( 0 );
	return( result );
}
	

WORD	generate_on_timer(xptr, type )
RESULTPTR	xptr;
WORD		type;
{
	if (( xptr != (RESULTPTR) 0)
	&&  ((xptr = mark_dead_result( xptr )) == (RESULTPTR) 0))
		return( internal_error(9) );
	tcode_instruction( _tc_TIM );
	if ( xptr != (RESULTPTR) 0 ) {
		tcputbyte( (tc_operand( xptr->nature ) | type) );
		tcode_operand( xptr );
		}
	else	tcputbyte( type );
	return(0);
}

WORD	generate_error( rptr )
RESULTPTR	rptr;
{
	if ( OtrOption.ListFlag & 1 )
		echo_error( rptr );
	tcode_instruction( _tc_ESC );
	tcode_instruction( (_esc_RTI | (tc_operand( rptr->nature ) >> 4) ));
	tcode_operand( rptr );
	return(0);
}

static	WORD	generate_on_error( vptr, type )
TCVARPTR 	vptr;
WORD		type;
{
	if ( type == MOINS_UN ) {
		if ( OtrOption.ListFlag & 1 )
			echo_instruction( "ON ERROR GOTO" );
		tcode_instruction( _tc_OEV );
		}
	else if ( type == _CTRL_LOCAL ) {
		if ( OtrOption.ListFlag & 1 )
			echo_instruction( "ON LOCAL ERROR GOTO" );
		tcode_instruction( _tc_OLE );
		}
	else	{
		if ( OtrOption.ListFlag & 1 )
			echo_instruction( "ONE SHOT ERROR GOTO" );
		tcode_instruction( _tc_OEO );
		}
	tcode_variable( vptr );
	return(0);
}

WORD	implicite_on_error( vptr, type, label )
TCVARPTR	vptr;
WORD		type;
WORD		label;
{
	WORD	status;
	if ((status = generate_on_error( vptr, type )) != 0)
		return( status );
	tcode_label((use_implicite_label( label, 0 )));	
	return(0);	
}

WORD	explicite_on_error( vptr, type, label )
TCVARPTR	vptr;
WORD		type;
BPTR		label;
{
	WORD	status;
	if ((status = generate_on_error( vptr, type )) != 0)
		return( status );
	tcode_label((use_explicite_label( label, 0 )));	
	return(0);	
}

WORD	generate_event_type( type )
WORD	type;
{
	switch ( type ) {
		case	1 : /* THEN */
			tcputbyte( _tc_WHN );
			tcputbyte( _ev_STOP );
			break;
		case 	2 : /* DO   */
			tcputbyte( _tc_WHN );
			tcputbyte( _ev_HALT );
			break;
		default	  : return( syntax_error(3342) );
		}
	return( 0 );
}

WORD	generate_event_false()
{
	tcputbyte( _tc_WHN );
	tcputbyte( _ev_FAUX );
	return(0);
}

WORD	generate_event_start()
{
	tcode_instruction( _tc_WHN );
	tcode_instruction( _ev_START);
	return(0);
}

WORD	generate_event()
{
	WORD	label;
	tcode_instruction( _tc_WHN );
	tcode_instruction( _ev_DCL );
	tcode_label((label = use_iteration_label(0))); 
	return( 0 );
}

#ifdef	_BEFORE_19121996
WORD	generate_extern_event( type )
WORD	type;
{
	tcode_instruction( _tc_WHN );
	switch ( type ) {
		case 0 : tcputbyte( _ev_JMI ); break;
		case 1 : tcputbyte( _ev_GSB ); break;
		case 2 : tcputbyte( _ev_CLP ); break;
		case 3 : tcputbyte( _ev_CLV ); break;
		}
	return(0);
}
#else
WORD	generate_extern_event( type, mode )
WORD	type;
WORD	mode;
{
	tcode_instruction( _tc_WHN );
	switch ( type ) {
		case 0 : tcputbyte( _ev_JMI ); break;
		case 1 : tcputbyte( _ev_GSB ); break;
		case 2 : 
			if ( mode )
				tcputbyte( _ev_OCXCLP ); 
			else	tcputbyte( _ev_CLP ); 
			break;
		case 3 : 
			if ( mode ) 
				tcputbyte( _ev_OCXCLV ); 
			else	tcputbyte( _ev_CLV ); 
			break;
		}
	return(0);
}
#endif

WORD	tcode_library_identity(lptr,mode)
TCDLBPTR lptr;
WORD mode;
{
	WORD	status;
	if (!( Target )) return(0);
	if ( context_is_module )
		if ((status = add_library_rellocation( 
				lptr,
				Target->OutputSector, 
				Target->OutputIndex  )) != 0)
			return( status );
	switch ( mode ) {
		case	1 :	/* byte sized */
			tcputbyte( lptr->identity );
			break;
		default	  :
			tcode_integer( lptr->identity );
			break;
		}			
	return(0);
}

WORD	tcode_procedure_identity( n )
WORD	n;
{
	WORD	type=0;	/* 0 : Internal,     1 : External */
	trace("tcode_procedure_identity()\n");
	if (!( Target )) return(0);

	if (( n == MOINS_UN) 
	&&  (Context->RelocateProc != (TCPRCPTR) 0)) {
		Context->RelocateProc->relocation->sector = Target->OutputSector;
		Context->RelocateProc->relocation->length = Target->OutputIndex;
		Context->RelocateProc = (TCPRCPTR) 0;
		type = 1;
		}
	if ( Context->PRC != (TCPRCPTR) 0)
		add_procedure_crossref(type,n,Target->OutputSector,Target->OutputIndex);
	else	add_segment_crossref(type,n,Target->OutputSector,Target->OutputIndex);

	tcode_integer( n );
	return(0);
}

WORD		tcode_procedure( pptr )
TCPRCPTR	pptr;
{
	return( tcode_procedure_identity( pptr->identity ) );
}

WORD		generate_event_call( pptr, vptr, mode )
TCPRCPTR	pptr;
TCVARPTR	vptr;
WORD		mode;	/* 0 Normal, 1 OCX etc Extension */
{
	WORD	status;
	if ( pptr != (TCPRCPTR) 0 ) {
		if ( pptr->identity == MOINS_UN )
			(void) rellocate_external_procedure( pptr );
		if ((status = generate_extern_event( 2,mode )) != 0)
			return( status );
		else	return( tcode_procedure( pptr ) );
		}
	else if ((status = generate_extern_event( 3, mode )) != 0)
		return( status );
	else	return( tcode_variable( vptr ) );

}

WORD	generate_event_off()
{
	tcode_instruction( _tc_WHN );
	tcputbyte( _ev_RAZ );
 	return( 0 );
}

WORD	generate_ngf( code )
WORD	code;
{
	trace("generate_ngf()\n");
	tcode_instruction( _tc_NGF );
	tcputbyte( code );
	return( 0 );
}

VOID	generate_clp_identity( xptr )
RESULTPTR	xptr;
{
	trace("generate_clp_identity()\n");
	switch ( xptr->nature ) {
		case _RESULT_ALEXPR  :
		case _RESULT_EXPR : tcode_register( xptr->value ); break;
		case _RESULT_ALIAS :
		case _RESULT_VPTR :
		case _RESULT_VARB : tcode_variable( xptr->contents ); break;
		case _RESULT_CONST: tcode_constant( xptr->contents ); break;
		case _RESULT_INT  : tcode_procedure_identity( xptr->value );
				    break;
		}
	return;
}

WORD	generate_clp()
{
	trace("generate_clp()\n");
	tcode_instruction( _tc_ESC  );
	tcputbyte( _esc_CLP );
	return( 0 );
}

WORD	generate_lde()
{
	tcode_instruction( _tc_LDE );
	return( 0 );
}


/* 	ACTIVATE PROC START	*/

static	WORD	reset_error_variable(RESULTPTR rptr)
{
	RESULTPTR	vptr;

	if (!( rptr ))
		return(0);

	switch ( rptr->nature ) {
		case _RESULT_ALIAS :
		case _RESULT_VARB  :
		case _RESULT_VPTR  :
			if (!( rptr->contents )) 
				return(0);
			else if (!( vptr = integer_result(1) ))
				return(0);
			else	return( generate_affectation( rptr->contents, vptr, 0 ) );			
		default		:
			return(0);
		}
}


static	WORD	flush_clp_error_trap(PRCPTR xptr)
{
	if ((xptr->ErrorFlag != MOINS_UN )
	&&  (xptr->Error     != (RESULTPTR) 0)) {
		if ((xptr->Error = mark_dead_result( xptr->Error )) == (RESULTPTR) 0)
			return( internal_error(5) );
		reset_error_variable( xptr->Error );
		if ( xptr->ErrorFlag != 0 )
			return( implicite_on_error( xptr->Error->contents, _CTRL_LOCAL, xptr->ErrorAdr  ) );
		else	return( explicite_on_error( xptr->Error->contents, _CTRL_BREAK, xptr->ErrorLabel ) );
		}
	return( 0 );
}

static	WORD	flush_clp_descriptors(xptr)
PRCPTR		xptr;
{
	WORD		i=0;
	WORD		phase;
	WORD		descriptor;
	WORD		d;
	RESULTPTR	lparam;
	WORD		n=0;
	WORD		mode=0;
	ARGPTR		cptr;
	WORD		status;
	TCPRCPTR	pptr=(TCPRCPTR) 0;
	TCVARPTR	vptr=(TCVARPTR) 0;

	if ((status = flush_clp_error_trap(xptr)) != 0)
		return( status );

	else if ((cptr = xptr->root) != (ARGPTR) 0) {
		if ((pptr = xptr->proc) != (TCPRCPTR) 0)
			vptr = pptr->parameter;
		cptr = xptr->last;
		do	{
			if ((lparam = cptr->operand) != (RESULTPTR) 0) {
				if ( vptr ) { 	
					if  (( vptr->type->type & _TYPE_POINTER ) == _TYPE_POINTER)
						if ( lparam->nature == _RESULT_VARB )
							lparam->nature |= _RESULT_VPT;
					vptr = vptr->next;
					}			
				if ( cptr->nature ) {
					if (!( lparam = mark_zero_result( lparam ) ))
						return( internal_error(2) );
					else	cptr->operand = lparam;
					}
				else 	{
					if ((lparam = mark_dead_result( lparam )) == (RESULTPTR) 0)
						return( internal_error(2) );
					else	cptr->operand = lparam;
					}
				}
			}
		while ((cptr = cptr->prev) != (ARGPTR) 0);
		cptr = xptr->root;
		do	{
			if ((lparam = cptr->operand) == (RESULTPTR) 0)
				return( syntax_error(3343) );
		
			mode = cptr->nature;

			/* Calculate descriptor access information */
			/* --------------------------------------- */
			phase = (n & 1);
			descriptor = (n/2);

			/* Indicate more parameters to follow */
			/* ---------------------------------- */
			if ( phase )
				xptr->descriptor[descriptor]     |= 0x0010;
			else if ( descriptor )
				xptr->descriptor[(descriptor-1)] |= 0x0001;

			/* Establish Parameter Nature */
			/* -------------------------- */  
			if (!( phase ))
				xptr->descriptor[descriptor]  = (((lparam->nature & 7) << 5) | ( mode ? 0x080 : 0 ));
			else	xptr->descriptor[descriptor] |= (((lparam->nature & 7) << 1) | ( mode ? 8 : 0));

			n++;
			}
		while ((cptr = cptr->next) != (ARGPTR) 0);
		}

	i = 0;
	if ((status = push_live_registers()) != 0 )
		return( status );
	else 	{
		if ( xptr->proc == (TCPRCPTR) 0) {
			if ((status = generate_lde()) != 0)
				return( status );
			}
		else if ((status = generate_clp()) != 0)
			return( status );
		}

	while ( 1 ) {
		tcputbyte((d = xptr->descriptor[i]));
		if ( d & 1 )
			i++;
		else	break;
		}
	return(0);
}

static	WORD	flush_clp_parameter(lparam)
RESULTPTR	lparam;
{
	trace("flush_clp_parameter()\n");
	if (lparam == (RESULTPTR) 0)
		return( syntax_error(3344) );
	else	tcode_operand( lparam );
	return( 0 );
}

static	WORD	flush_clp_parameters(xptr)
PRCPTR		xptr;
{
	ARGPTR		cptr;
	WORD		status=0;
	trace("flush_clp_parameters()\n");
	if ((cptr = xptr->root) != (ARGPTR) 0) {
		if (( xptr->proc != (TCPRCPTR) 0)
		&&  ( xptr->proc->identity == MOINS_UN ))
			(void) rellocate_external_procedure( xptr->proc );
		generate_clp_identity( cptr->operand );
		while ((cptr = cptr->next) != (ARGPTR) 0) {
			if ((status = flush_clp_parameter( cptr->operand )) != 0)
				return( status );
			}
		}

	if ((status = pop_live_registers()) != 0)
		return( status );

	if ( xptr->ErrorFlag != MOINS_UN ) {
		if ( xptr->ErrorFlag != 0 ) {
			if ((status = dcl_implicite_label( xptr->ErrorAdr )) != 0)
				return( status );
			else	return( generate_error_abort() );
			}
		}
	return( 0 );
}

static	VOID	echo_call_procedure( xptr )
PRCPTR	xptr;
{
	WORD	nombre=0;
	ARGPTR	cptr;
	WORD	mode=FAUX;
	WORD	status;
	if ((cptr = xptr->root) != (ARGPTR) 0) {
		if ((( xptr->proc != (TCPRCPTR) 0)
		  && ( xptr->proc->result != (TCTYPPTR) 0 ))
		||  ( xptr->type != (TCTYPPTR) 0 ))
			status = echo_start((mode = FAUX));
		else	status = echo_start((mode = VRAI));
		if (!( status ))
			return;
		if ( xptr->proc == (TCPRCPTR) 0) {
			echo_keyword("CALL");
			echo_left_brace();
			echo_operand(cptr->operand);
			echo_right_brace();
			}
		else	echo_string( xptr->proc->name );

		echo_left_brace();
		while ((cptr = cptr->next) != (ARGPTR) 0) {
			if ( nombre++ )
				echo_comma();
			echo_operand( cptr->operand );
			}
		echo_right_brace();
		echo_line();
		}
	return;
}

WORD	flush_clp( context )
PRCPTR	context;
{
	WORD	status=0;
	if ( OtrOption.ListFlag & 1 )
		echo_call_procedure( context );
	if (((status = flush_clp_descriptors(context)) == 0)
	&&  ((status = flush_clp_parameters(context)) == 0)) 
		return( 0 );
	else	return( status );
}

WORD		store_clp(xptr, rptr, mode )
PRCPTR		xptr;
RESULTPTR	rptr;
WORD		mode;
{
	ARGPTR		cptr;
	TCVARPTR	vptr;
	if (!( mode ))
		mode = is_question();
	else	(void) is_question();

	if ( mode & 1 ) {
		if (( rptr->nature & _RESULT_BASIC) != _RESULT_VARB )
			return( syntax_error( 889 ) );
		else if ((vptr = (TCVARPTR) rptr->contents) == (TCVARPTR) 0)
			return( internal_error( 2000 ) );
		else if (!( vptr->access & _TYPE_WRITABLE ))
			return( syntax_error( 2000 ) );
		}

	if ((cptr = allocate_for_operand()) == (ARGPTR) 0)
		return( allocation_failure() );
	cptr->operand = rptr;
	if ((cptr->prev = xptr->last) == (ARGPTR) 0)
		xptr->root = cptr;
	else	xptr->last->next = cptr;
	if ( mode )
		cptr->nature = VRAI;
	xptr->last = cptr;
	return( 0 );
}

VOID		liberate_clp( xptr )
PRCPTR		xptr;
{
	ARGPTR	cptr;
	if ( xptr != (PRCPTR) 0 ) {
		while ((cptr = xptr->root) != (ARGPTR) 0) {
			xptr->root = cptr->next;
			liberate( cptr );
			}
		liberate( xptr );
		}
	return;
}

WORD	clp_explicite_label(PRCPTR xptr)
{
	if ( get_token() ) {
		xptr->ErrorFlag = 0;
		strcpy(xptr->ErrorLabel,TokenBuffer);
		if ( is_comma() )
			return(0);
		}
	return( syntax_error(110) );
}

WORD	clp_implicite_label(PRCPTR xptr ,WORD nature)
{
	xptr->ErrorFlag = nature;
	if ( is_comma() ) {
		xptr->ErrorAdr = new_implicite_label();
		return( 0 );
		}
	else	return( syntax_error(111) );
}

WORD	clp_error_trap(	PRCPTR	xptr )
{
	WORD	status=0;
	if ( is_colon() ) {
		if ((status = is_ampersand()) != FAUX ) {  
			unget_byte();
			if (clp_explicite_label(xptr) != 0)
				return( syntax_error(112) );
			}
		else if ((status = is_mnemonic_label()) != FAUX) {
			if ( clp_implicite_label(xptr,status) != 0 )
				return( syntax_error(113) );
			}
		if (( status )
		&&  ((xptr->Error = evaluate_expression(0)) == (RESULTPTR) 0))
			return(syntax_error(114));
		}
	return(0);
}

PRCPTR		start_prc( pptr, tptr )
TCPRCPTR	pptr;
TCTYPPTR	tptr;
{
	PRCPTR	context=(PRCPTR) 0;
	
	if ((context = (PRCPTR) allocate( sizeof( struct otr_callproc ) )) != (PRCPTR) 0) {
		context->root = (ARGPTR) 0;
		context->last = (ARGPTR) 0;
		context->proc = pptr;
		context->type = tptr;
		context->Error=(RESULTPTR) 0;
		context->ErrorFlag  = MOINS_UN;
		context->ErrorAdr   = MOINS_UN;
		memset(context->ErrorLabel, 0, _MAX_PROC_LABEL );
		memset(context->descriptor, 0, _MAX_PROC_DESCRIPTOR );
		}	
	return( context );
}

WORD	ll_activate_procedure(pptr, rptr, sigptr )
TCPRCPTR	pptr;
RESULTPTR	rptr;
TCPRCPTR	sigptr;
{
	WORD		option=0;
	WORD		datatype;
	WORD		status;
	TCVARPTR	vptr;
	PRCPTR		context;

	trace( "activate_procedure()\n" );

	if ((context = start_prc( pptr,(pptr ? pptr->result :(TCTYPPTR)  0) )) == (PRCPTR) 0)
		return( allocation_failure() );

	if ((status = store_clp( context, rptr, 0 )) != 0) {
		liberate_clp( context );
		return( status );
		}

	if ((  is_left_brace()  ) 
	&&  (!(is_right_brace()))) {

		/* correction to type check extern call */
		/* ------------------------------------ */
		if (!( pptr )) { pptr = sigptr; }

		if ((pptr != (TCPRCPTR) 0)
		&&  ((vptr = pptr->parameter) == (TCVARPTR) 0)) {
			liberate_clp(context);
			return( syntax_error(3345) );
			}
		do	{
			if ( pptr != (TCPRCPTR) 0) {
				if ( vptr == (TCVARPTR) 0) {
				liberate_clp( context );
				return( syntax_error( 1040 ) );
				}
				/* ------------------------------------ */ 
				/* Correction for FRED in Painter 	*/
				/* Extern Call where proc parameter is	*/
				/* a pointer to int and must cancel	*/
				/* an eventual LDV being generated	*/
				/* ------------------------------------ */ 
				else if (((datatype = vptr->type->type) & _TYPE_POINTER ) == _TYPE_POINTER)
					option = 8; /* show its a pointer : 8  not a question : 1 */
				else	option = 0;
				}
			else	{
				datatype = MOINS_UN;
				option=0;
				}
			if ((rptr = evaluate_typed_expression(datatype)) == (RESULTPTR) 0) {
				liberate_clp( context );
				return( syntax_error(3346) );
				}
			else if ((status = store_clp( context, rptr, option )) != 0) {
				liberate_clp( context );
				return( status );
				}
			if (( pptr!= (TCPRCPTR) 0)
			&&  ( vptr!= (TCVARPTR) 0))
				vptr = vptr->next;
			}
		while 	( is_comma() );

		if (( pptr != (TCPRCPTR) 0)
		&&  ( vptr != (TCVARPTR) 0)) {
			liberate_clp( context );
			return( syntax_error( 1050 ) );
			}

		if (!(is_right_brace())) {
			liberate_clp( context );
			return( syntax_error(3347) );
			}
		}
	else if (( pptr != (TCPRCPTR) 0)
	     &&  ( pptr->parameter != (TCVARPTR) 0 )) {
		liberate_clp( context );
		return( syntax_error(3348) );
		}

	if ((status = clp_error_trap(context)) != 0)
		return( status );

	/* Generate Procedure Call */
	/* ----------------------- */
	status = flush_clp( context );

	liberate_clp( context );

	return( status );
}

WORD	activate_procedure(pptr, rptr, sigptr )
TCPRCPTR	pptr;
RESULTPTR	rptr;
TCPRCPTR	sigptr;
{
	WORD	status;
	WORD	holder;
	holder = Context->VerifyStrict;
	Context->VerifyStrict = 1;
	status = ll_activate_procedure(pptr, rptr, sigptr);
	Context->VerifyStrict = holder;
	return( status );
}

/* 	ACTIVATE PROC END	*/

WORD	generate_ldf( TCDLBPTR lptr )
{
	trace("generate_ldf()\n");
	tcode_instruction( _tc_LDF );
	tcode_library_identity( lptr,1 );
	return( 0 );
}

WORD	generate_clf( code, group )
WORD	code;
WORD	group;
{
	trace("generate_clf()\n");
	tcode_instruction( _tc_CLF );
	tcputbyte( (group | (code << 4)) );
	return( 0 );
}

WORD	generate_iof()
{
	trace("generate_iof()\n");
	tcode_instruction( _tc_IOF );
	return( 0 );
}

WORD	generate_fio( )
{
	tcputbyte( _iof_FIO );
	return( 0 );
}

WORD	generate_fmt( fptr )
BPTR	fptr;
{
	WORD	l;
	l = *(fptr++);
	tcputbyte( l );
	while ( l ) {
		tcputbyte( *(fptr++) );
		l--;
		}
	return( 0 );
}

VOID	generate_format_label( lptr )
BPTR	lptr;
{
	tcputbyte( _iof_FMT );
	tcode_label( use_explicite_label( lptr, 0 ) );
	return;
}

WORD		generate_iof_instruction( opcode, rptr )
WORD		opcode;
RESULTPTR	rptr;
{
	tcputbyte( (opcode | tc_operand(rptr->nature) ) );
	tcode_operand( rptr );
	return( 0 );
}

WORD	generate_iof_format( opcode, fptr )
WORD	opcode;
BPTR	fptr;
{
	tcputbyte( opcode );
	return( generate_fmt( fptr ) );
}

WORD	generate_iof_hotkey( hptr )
HOTPTR	hptr;
{
	WORD	status;
	BPTR	lptr;
	if ( hptr->nature != MOINS_UN ) {
		if ( hptr->gosub )
			status = generate_byte(( hptr->nature | _iof_GSBX ));
		else	status = generate_byte(( hptr->nature | _iof_HOTX ));
		if ( status )
			return( status );
		}
	else	{
		if ( hptr->gosub )
			status = generate_iof_instruction( _iof_GSBH, hptr->operand );
		else	status = generate_iof_instruction( _iof_HOT, hptr->operand );
		if ( status )
			return( status );
		}

	if (( lptr = hptr->label ) != (BPTR) 0) {
		if ( *lptr == '&' )
			tcode_label( use_explicite_label( lptr, 0 ) );
		else if ( uppercase_compare( lptr, "NEXT" ))
			tcode_label( use_implicite_label( ask_end_label(), 0 ));
		else if ( uppercase_compare( lptr, "BREAK" ))
			tcode_label( use_break_label(0) );
		else if ( uppercase_compare( lptr, "THISLINE" ))
			tcode_label( use_implicite_label( get_ask_start_label(), 0 ));
		else	return( syntax_error(3349) );
		}
	else	return( syntax_error(3350) );

	return( 0 );

}

RESULTPTR	generate_increment( rptr )
RESULTPTR	rptr;
{
	trace("generate_increment()\n");
	rptr = mark_live_result( rptr );
	tcode_instruction( _tc_INC     );
	tcode_register( rptr->value );
	if ( OtrOption.ListFlag & 1 )
		set_shadow_increment( rptr->contents );
	return( rptr );
}

RESULTPTR	generate_decrement( rptr )
RESULTPTR	rptr;
{
	trace("generate_decrement()\n");
	rptr = mark_live_result( rptr );
	tcode_instruction( _tc_DEC     );
	tcode_register( rptr->value );
	if ( OtrOption.ListFlag & 1 )
		set_shadow_decrement( rptr->contents );
	return( rptr );
}


RESULTPTR 	generate_conversion( rptr, type )
RESULTPTR	rptr;
WORD		type;
{
	trace("generate_cnv()\n");
	rptr = mark_live_result( rptr );
	tcode_instruction( _tc_CNV     );
	tcode_register( rptr->value );
	tcode_integer( type );
	shadow_conversion( rptr, type );
	rptr = mark_live_result( rptr );
	return( rptr );
}

RESULTPTR	resolve_dimensions( xptr )
RESULTPTR	xptr;
{
	TCVARPTR	vptr;
	if ((( xptr->nature & _RESULT_BASIC) == _RESULT_VARB )
	&&  ((vptr = (TCVARPTR) xptr->contents) != (TCVARPTR) 0)
	&&  ( vptr->type != (TCTYPPTR) 0)
	&&  ( vptr->type->type & 0x0060 ))
		return( ensure_register( xptr ) );
	else	return( xptr );
}

WORD	generate_first_dimension( r, rptr )
WORD		r;
RESULTPTR	rptr;
{
	WORD	HoldLDV = ForceLDV;
	ForceLDV = VRAI;
	if (( rptr != (RESULTPTR) 0)
	&&  ((rptr = resolve_dimensions( rptr )) != (RESULTPTR) 0) 
	&&  ((rptr = mark_dead_result( rptr )) != (RESULTPTR) 0)) {
		tcode_instruction( ( _tc_LXI |  tc_operand( rptr->nature )));
		tcode_register( r );
		tcode_operand( rptr );
		}
	ForceLDV = HoldLDV;
	return(0);
}

WORD	generate_next_dimension( r, rptr )
WORD		r;
RESULTPTR	rptr;
{
	WORD	HoldLDV=ForceLDV;
	ForceLDV = VRAI;
	if (( rptr != (RESULTPTR) 0)
	&&  ((rptr = resolve_dimensions( rptr )) != (RESULTPTR) 0)) {
		if ((rptr = mark_dead_result( rptr )) == (RESULTPTR) 0) {
			ForceLDV = HoldLDV;
			return( internal_error(10) );
			}
		tcode_instruction( ( _tc_AXI |  tc_operand( rptr->nature )));
		tcode_register( r );
		tcode_operand( rptr );
		}
	ForceLDV = HoldLDV;
	return(0);
}

WORD	generate_dimensions( nbreg, vptr )
WORD		nbreg;
TCVARPTR	vptr;
{
	WORD	status;
	trace("generate_dimensions()\n"); 

	if ( vptr != (TCVARPTR) 0 ) {

		/* check for and correct missing primary index */
		/* ------------------------------------------- */
		if (( vptr->type->type & _TYPE_FIRST )
		&&  (!( vptr->firstdim 	))) {
			issue_warning(20);
			if (!( vptr->firstdim = integer_result(1) ))
				return( allocation_failure() );
			}
		/* check for and correct missing secondary index */
		/* --------------------------------------------- */
		if (( vptr->type->type & _TYPE_SECOND )
		&&  (!( vptr->secondim 	  	))) {
			issue_warning(20);
			if (!( vptr->secondim = integer_result(1) ))
				return( allocation_failure() );
			}
		if ( vptr->firstdim != (VPTR) 0 ) {
			if ((status = generate_first_dimension( nbreg, (RESULTPTR) vptr->firstdim )) != 0)
				return( status );
			else if (( vptr->secondim != (VPTR) 0 )
			     &&  ((status = generate_next_dimension( nbreg, (RESULTPTR) vptr->secondim )) != 0))
				return( status );;
			}
		}
	return(0);
}

/*
 *	C O L L E C T _ D I M E N S I O N S ()
 *	--------------------------------------
 *
 *	This function is called from :
 *
 *		TRSYMBOL.is_variable()
 *
 *	in order to collect any dimensioning and structural 
 *	extensions for all variable operands.
 *
 *	NB: See also "variable_operand()" above for CLF6 targets.
 *
 */

TCVARPTR	collect_dimensions( vptr )
TCVARPTR	vptr;
{	
	RESULTPTR	rptr;

/*	sysprintf("collect_dimensions(%s:%04.1X)\n",vptr->name,vptr->identity);	*/

	while (1) {

		/* Detect Dimensioned Variable */
		/* --------------------------- */
		if (( vptr->type->type & _TYPE_FIRST )
		&&  ( use_dimensions() )
		&&  ( is_left_brace() )) {

			/* Evaluate First Dimension Expression */
			/* ----------------------------------- */
			if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0) {
				(void) syntax_error(3351);
				return( vptr );
				}
			vptr->firstdim = (VPTR) rptr;

			/* Detect Secondary Dimensions */
			/* --------------------------- */
			if (( vptr->type->type & _TYPE_SECOND )
			&&  ( is_comma() )) {

				/* Evaluate Secondary Dimension Expression */
				/* --------------------------------------- */
				if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0) {
					(void) syntax_error(3352);
					return( vptr );
					}
				vptr->secondim = (VPTR) rptr;
				}

			if (!( is_right_brace() ))
				(void) unmatched_braces();
			}

		/* Detect and Resolve Structural Elements */
		/* -------------------------------------- */
		if (( vptr->type->type & _TYPE_DEFINED )
		&&  ( is_period() )
		&&  ((vptr = resolve_structure_member( vptr )) != (TCVARPTR) 0))
			continue;
		else	return( vptr );
		}
}


WORD	negate_register( rptr )
RESULTPTR	rptr;
{
	tcode_instruction( _tc_NGR );
	tcode_register( rptr->value );
	if ( OtrOption.ListFlag & 1 )
		set_shadow_negation( rptr->contents );
	return( 0 );
}

WORD	negate_variable( rptr )
RESULTPTR	rptr;
{
	WORD	status;
	if (( rptr != (RESULTPTR) 0)
	&&  (( rptr->nature & _RESULT_BASIC) == _RESULT_VARB )) {
		if ((status = generate_dimensions( 0, rptr->contents )) !=0)
			return( status );
		}
	else	return( syntax_error(3353) );
	tcode_instruction( _tc_NGV );
	tcode_variable( rptr->contents );
	return( 0 );
}


WORD	generate_op( rptr, label )
RESULTPTR	rptr;
BPTR		label;
{
	WORD	status;
	WORD	target;
	WORD	nextlabel=0;

	/* generate eventual dimensions for an eventual operand */
	/* ---------------------------------------------------- */
	if (( rptr != (RESULTPTR) 0) &&  ((status = generate_dimensions( 0, rptr->contents )) != 0))
		return( status );

	if ( *label == '&' )
		target = use_explicite_label( label,(WORDSIZE+1) );
	else if ( uppercase_compare( label, "NEXT" ) )
		target = use_implicite_label((nextlabel = new_implicite_label()),(WORDSIZE+1));
	else if ( uppercase_compare( label,"BREAK" ))
		target = use_break_label((WORDSIZE+1));
	else	return( syntax_error(435) );

	tcode_instruction( _tc_TPC );
	if ( rptr != (RESULTPTR) 0)
		tcode_operand( rptr );
	else	tcode_integer( 0 );
	tcode_label( target );

	if ( nextlabel != 0 )
		dcl_implicite_label( nextlabel );

	return( 0 );
}

static WORD	optimised_variable_load( rptr, sptr )
RESULTPTR	rptr;
RESULTPTR 	sptr;
{
	TCVARPTR	vptr;
	WORD		operand=0;
	WORD		status;
	if ((OtrOption.Optimise & _OPTIMISE_LOAD) 
	&&  ((vptr = (TCVARPTR) sptr->contents) != (TCVARPTR) 0)
	&&  (!( sptr->nature & _RESULT_VPT ))
	&&  ( vptr->type != (TCTYPPTR) 0)) {
		/* Eliminate COMPLEX F=N,F=E,F=[B] variables */
		if ((vptr->type->type & 0xFF62) == 0) {
			if ( sptr->value & ISLOCAL ) {
#ifdef	otr32
				switch ( vptr->type->type & 5 ) {
					case	4 :
					case	0 :
						tcode_instruction( _tc_LCL );
						break;
					case	1 :
						tcode_instruction( _tc_LIL );
						break;
					case	5 :
						tcode_instruction( _tc_ESC );
						tcputbyte( _esc_LLL );
						break;
					}
#else
				if ( vptr->type->type & 3 )
					tcode_instruction( _tc_LIL );
				else	tcode_instruction( _tc_LCL );
#endif
				}
			else	{
#ifdef	otr32
				switch ( vptr->type->type & 5 ) {
					case	4 :
					case	0 :
						tcode_instruction( _tc_GCL );
						break;
					case	1 :
						tcode_instruction( _tc_GIL );
						break;
					case	5 :
						tcode_instruction( _tc_ESC );
						tcputbyte( _esc_GLL );
						break;
					}
#else
				if ( vptr->type->type & 3 )
					tcode_instruction( _tc_GIL );
				else	tcode_instruction( _tc_GCL );
#endif
				}			
			tcode_register( rptr->value );
			tcode_variable_offset( vptr );
			}
		else	{
			if ((status = generate_dimensions( rptr->value, sptr->contents )) != 0)
				return( status );
			else if ((vptr->type->type & 0x003) > 1 )
				tcode_instruction( _tc_VPT  );
			else if ((vptr->type->type & 0x060)
			     &&  (!( ForceLDV ))) 
				tcode_instruction( _tc_VPT  );
			else 	tcode_instruction( _tc_LDV  );
			/* operand = sptr->value; */
			tcode_register( rptr->value );
			tcode_variable( sptr->contents );
			/* offset( operand ); */
			}
		return( 1 );
		}
	else	return(0);
}

WORD	generate_copy_register( treg, sreg )
WORD	treg;
WORD	sreg;
{
	trace("generate_copy_register()\n");
	mark_dead_noregister( sreg );
	mark_live_noregister( treg );
	tcode_instruction( _tc_LDR  ); 
	tcode_register( treg );
	tcode_register( sreg );
	return(0);
}

RESULTPTR	generate_register_load( rptr, sptr, mode )
RESULTPTR	rptr;
RESULTPTR 	sptr;
WORD		mode;
{
	WORD	status;
	TCVARPTR vptr;
	trace("generate_register_load()\n");
	if ( OtrOption.ListFlag & 1 )
		set_shadow_result( rptr->contents, sptr );
	switch ( sptr->nature ) {
		case _RESULT_INT   : 
				shadow_integer( rptr, sptr->value );
				tcode_instruction( _tc_LDI  ); 
				tcode_register( rptr->value );
				tcode_integer( sptr->value );
				break;
		case _RESULT_CONST : 
				shadow_constant( rptr, sptr->contents );
				tcode_instruction( _tc_LDC  ); 
				tcode_register( rptr->value );
				tcode_constant( sptr->contents );
				break;
		case _RESULT_VPTR  :
		case _RESULT_VARB  : 
		case _RESULT_ALIAS :
				shadow_variable( rptr, sptr->contents );
				if (optimised_variable_load( rptr, sptr ) )
					break;
				else if ((status = generate_dimensions( rptr->value, sptr->contents )) != 0)
					return((RESULTPTR) 0);
				else if (!( vptr = sptr->contents ))
					return((RESULTPTR) 0);
				else if ((vptr->type->type & 0x003) > 1 )
					tcode_instruction( _tc_VPT  );
				else if (!( mode & _RESULT_VPT ))
					tcode_instruction( _tc_LDV );
				else	tcode_instruction( _tc_VPT );
				tcode_register( rptr->value );
				tcode_variable( sptr->contents );
				break;
		case _RESULT_ALEXPR  :
		case _RESULT_EXPR  : 
				shadow_register( rptr, sptr );
				generate_copy_register( rptr->value, sptr->value );
				break;
		}
	rptr = mark_live_result( rptr );
	return( rptr );
}

WORD	generate_label( label )
WORD	label;
{
	tcode_label( label );
	return( 0 );
}

WORD	tc_compare( opcode )
WORD	opcode;
{
	return((_tc_JEQI + (opcode-1)));
}

WORD	tc_arithmetic( opcode )
WORD	opcode;
{
	switch ( opcode ) {
		case	'+' : return( _tc_ADI );
		case	'-' : return( _tc_SBI );
		case	'*' : return( _tc_MLI );
		case	'/' : return( _tc_DVI );
		case    '%' :
		case	'!' : return( _tc_MDI );
		case	'&' : return( _tc_ANI );
		case	'|' : return( _tc_ORI );
		case	'^' : return( _tc_XRI );
		default	    : return( 0x00FF  );
		}
}

WORD		generate_compare( operator, aterm, bterm,logic, label) 
WORD		operator;
RESULTPTR	aterm;
RESULTPTR	bterm;
WORD		logic;
WORD		label;
{
	trace("generate_compare()\n");
	if ((aterm= mark_dead_result( aterm)) == (RESULTPTR) 0)
		return( internal_error(11) );
	if ((bterm= mark_dead_result( bterm)) == (RESULTPTR) 0)
		return( internal_error(12) );
	tcode_instruction( (tc_compare( operator ) | tc_operand( bterm->nature )) );
	tcode_register( aterm->value );
	tcode_operand( bterm );
	switch ( logic ) {
		case MOINS_UN  	  :
			tcode_label(use_abandon_label(0)); 
			break;
		case _LOGICAL_AND :
			tcode_label(use_abandon_label(0)); 
			break;
		case _LOGICAL_NEX :
			tcode_label(use_iteration_label(0)); 
			break;
		case _LOGICAL_OR  :
			tcode_label(use_operate_label(0)); 
			break;
		case _LOGICAL_USE :
			tcode_label(use_implicite_label( label, 0) );
			break;
		case _LOGICAL_LAB :
			tcode_label(label);
			break;
		}
	return(0);
}

RESULTPTR	generate_arithmetic( operator, aterm, bterm, rterm)
WORD		operator;
RESULTPTR	aterm;
RESULTPTR	bterm;
RESULTPTR	rterm;
{
	trace("generate_arithmetic()\n");
	if (((aterm= mark_dead_result( aterm)) == (RESULTPTR) 0)
	||  ((bterm= mark_dead_result( bterm)) == (RESULTPTR) 0)) {
		(void) internal_error(13);
		return((RESULTPTR) 0);
		}
	tcode_instruction( (tc_arithmetic( operator ) | tc_operand( bterm->nature )) );
	tcode_register( aterm->value );
	tcode_operand( bterm );
	tcode_register( rterm->value );
	shadow_expression( rterm, operator, aterm, bterm );
	rterm = mark_live_result( rterm );
	return( rterm );
}

static WORD	optimised_variable_store( vptr, rptr )
TCVARPTR	vptr;
RESULTPTR	rptr;
{
	if ((OtrOption.Optimise & _OPTIMISE_STORE) 
	&&  ((vptr != (TCVARPTR) 0)
	&&  ( vptr->type != (TCTYPPTR) 0)
	&&  ( vptr->type->type & 0xFF62) == 0)) {
		if (!( is_shadow_integer( rptr ) )) {
			return(0);
			}
		else if ( vptr->identity & ISLOCAL ) {
#ifdef	otr32
				switch ( vptr->type->type & 5 ) {
					case	4 :
					case	0 :
						tcode_instruction( _tc_LCS );
						break;
					case	1 :
						tcode_instruction( _tc_LIS );
						break;
					case	5 :
						tcode_instruction( _tc_ESC );
						tcputbyte( _esc_LLS );
						break;
					}
#else
			if ( vptr->type->type & 3 )
				tcode_instruction( _tc_LIS );
			else	tcode_instruction( _tc_LCS );
#endif
			}
		else	{
#ifdef	otr32
				switch ( vptr->type->type & 5 ) {
					case	4 :
					case	0 :
						tcode_instruction( _tc_GCS );
						break;
					case	1 :
						tcode_instruction( _tc_GIS );
						break;
					case	5 :
						tcode_instruction( _tc_ESC );
						tcputbyte( _esc_GLS );
						break;
					}
#else
			if ( vptr->type->type & 3 )
				tcode_instruction( _tc_GIS );
			else	tcode_instruction( _tc_GCS );
#endif
			}			
		tcode_register( rptr->value );
		tcode_variable_offset( vptr );
		return(1);
		}
	else	return(0);
}

WORD	explicite_ldi( reg, value )
WORD	reg;
WORD	value;
{
	tcode_instruction( _tc_LDI );
	tcode_register( reg );
	tcode_integer( value );
	return(0);
}

WORD	generate_optimised_sti( vptr, value )
TCVARPTR	vptr;
WORD		value;
{
	if ( OtrOption.ListFlag & 1 )
		echo_sti( vptr, value );
	if ( OtrOption.Optimise & _OPTIMISE_STORE ) {
		if ( vptr->identity & ISLOCAL ) {
#ifdef	otr32
			if (( vptr->type->type & 5) == 5) {
				tcode_instruction( _tc_ESC );	
				tcode_instruction( _esc_SLL );	
				}
			else	
#endif
				tcputbyte( _tc_LWS );	
			}
		else	{
#ifdef	otr32
			if (( vptr->type->type & 5) == 5) {
				tcode_instruction( _tc_ESC );	
				tcputbyte( _esc_SGL );	
				}
			else	
#endif
			tcode_instruction( _tc_GWS );	
			}
		tcode_integer( value );
		tcode_variable_offset( vptr );
		}
	else	{
		tcode_instruction( _tc_STI );
		tcode_integer( value );
		tcode_variable( vptr );
		}
	return( 0 );
}

WORD	dimensioned_variable( vptr )
TCVARPTR	vptr;
{
	return( vptr->type->type & _TYPE_FIRST );
}

WORD	alias_affectation( vptr, rptr )
TCVARPTR	vptr;
RESULTPTR	rptr;
{
	rptr->nature &= ~_RESULT_POINTER;
	if (( vptr->type->type & _TYPE_POINTER ) != _TYPE_POINTER ) {
		issue_warning( 15 );
		return( MOINS_UN );
		}
	else	return( clf_alias( variable_result( vptr ), rptr ) );
}

RESULTPTR	force_ensure_register( rptr )
RESULTPTR	rptr;
{
	WORD	HoldLDV=ForceLDV;
	ForceLDV = VRAI;
	rptr = ensure_register( rptr );
	ForceLDV = HoldLDV;
	return( rptr );
}

WORD	detect_integer_conversion(vptr)
TCVARPTR	vptr;
{
	WORD	lt;
	WORD	rt;

	if ( AutoConvAllowed ) 
		return(0);
	else if ((!( vptr )) || (!( vptr->type )))
		return(0);
	else 	{
		switch ( vptr->type->type & _TYPE_BASIC ) {
			case	_TYPE_INT8	:
			case	_TYPE_INT16	:
			case	_TYPE_INT32	:
			case	_TYPE_NUMERIC	:
				return(0);
			case	_TYPE_STRING	:
			default			:
				strcpy(TokenBuffer,vptr->name);
				if (!( OtrOption.Strict & 2 ))
					return(issue_warning(2));
				else	return(syntax_error(55));
			}
		}
}

WORD	detect_constant_conversion(vptr, cptr)
TCVARPTR	vptr;
TCCONPTR	cptr;
{
	WORD	lt;
	WORD	rt;
	if ( AutoConvAllowed ) { return(0); }
	if ((!( vptr ))
	||  (!( cptr ))
	||  (!( vptr->type ))
	||  (!( cptr->type )))
		return(0);
	else 	{
		if ( fundemental_type( cptr->type->type ) != fundemental_type( vptr->type->type ) ) {
			strcpy(TokenBuffer,vptr->name);
			if (!( OtrOption.Strict & 2 ))
				return(issue_warning(2));
			else	return(syntax_error(55));
			}
		else if (!( OtrOption.Strict ))
			return(0);
		else if ((lt = normalised_type( cptr->type->type )) != (rt = normalised_type( vptr->type->type ) )) {
			if ( rt < lt ) {
				strcpy(TokenBuffer,vptr->name);
				issue_warning( 2 );
				return(0);
				}
			else	return(0);
			}	
		else 	return(0);
		}	
}

WORD	detect_variable_conversion(vptr, wptr)
TCVARPTR	vptr;
TCVARPTR	wptr;
{
	WORD	lt;
	WORD	rt;
	if ( AutoConvAllowed ) { return(0); }
	if ((!( vptr ))
	||  (!( wptr ))
	||  (!( vptr->type ))
	||  (!( wptr->type )))
		return(0);
	else 	{
		if ( fundemental_type( wptr->type->type ) != fundemental_type( vptr->type->type ) ) {
			strcpy(TokenBuffer,wptr->name);
			if (!( OtrOption.Strict & 2 ))
				return(issue_warning(2));
			else	return(syntax_error(55));
			return(0);
			}
		else if (!( OtrOption.Strict ))
			return(0);
		else if ((lt = normalised_type( wptr->type->type )) != ( rt = normalised_type( vptr->type->type )) ) {
			if ( rt < lt ) {
				strcpy(TokenBuffer,wptr->name);
				issue_warning( 2 );
				return(0);
				}	
			else	return(0);
			}	
		else	return(0);
		}	
}

WORD	generate_affectation( vptr, rptr, withecho )
TCVARPTR	vptr;
RESULTPTR	rptr;
WORD		withecho;
{
	WORD	status;
	trace("generate_affectation()\n");

	if (!( vptr->access & _TYPE_WRITABLE ))
		return( syntax_error( 2000 ) );

	if (( vptr->type->type & _TYPE_DEFINED )
	&&  ((status = object_affectation( vptr, rptr )) != MOINS_UN))
		return( status );
	else if (( rptr->nature & _RESULT_POINTER )
	     &&  ((status = alias_affectation( vptr, rptr )) != MOINS_UN))
		return( status );

	if ( OtrOption.ListFlag & 1 )
		echo_affectation( vptr, rptr, withecho );

	if ((status = generate_dimensions( 0, vptr )) != 0)
		return( status );

	switch ( rptr->nature ) {
		case _RESULT_INT   :
			if ((status = detect_integer_conversion( vptr )) != 0)
				return( status );		
			tcode_instruction( _tc_STI  );
			tcode_integer( rptr->value );
			break;
		case _RESULT_CONST :
			if ((status = detect_constant_conversion( vptr, rptr->contents  )) != 0)
				return( status );		
			tcode_instruction( _tc_STC  );
			tcode_constant( rptr->contents );
			break;
		case _RESULT_VPTR  :
		case _RESULT_VARB  :
		case _RESULT_ALIAS :
			if ((status = detect_variable_conversion( vptr, rptr->contents  )) != 0)
				return( status );		
			if (!( dimensioned_variable( rptr->contents ) )) {
				if ((status = generate_dimensions( 0, rptr->contents )) != 0)
					return( status );
				tcode_instruction( _tc_STV    );
				tcode_variable( rptr->contents );
				break;
				}
			else if ((rptr = force_ensure_register( rptr )) == (RESULTPTR) 0)
				return( allocation_failure() );
			else if ((rptr = mark_dead_result( rptr )) == (RESULTPTR) 0)
				return( internal_error(14) );
			else	{
				tcode_instruction( _tc_STR    );
				tcode_register( rptr->value );
				break;
				}

		case _RESULT_ALEXPR  :
		case _RESULT_EXPR  :
			if ((rptr = mark_dead_result( rptr )) == (RESULTPTR) 0)
				return( internal_error(14) );
	
			if ( optimised_variable_store(vptr,rptr) )
				return( 0 );
			tcode_instruction( _tc_STR    );
			tcode_register( rptr->value );
			break;
		default		   :
			return( 999 );

		}
	tcode_variable( vptr );
	return( 0 );
}

WORD	variable_to_variable( sptr, rptr )
TCVARPTR	sptr;
TCVARPTR	rptr;
{
	WORD	status;
	trace("variable_to_variable()\n");
	if (((status = generate_dimensions( 0, sptr )) != 0)
	||  ((status = generate_dimensions( 0, rptr )) != 0))
		return( status );
	tcode_instruction( _tc_STV    );
	tcode_variable( sptr );
	tcode_variable( rptr );
	return(0);
}

WORD	generate_stop()
{
	trace("generate_stop()\n");
	signal_new_line(FAUX);
	if ( OtrOption.ListFlag & 1 )
		echo_instruction("STOP");
	tcode_instruction( _tc_ESC   );
	tcputbyte( _esc_STP  );
	return( 0 );
}

WORD	generate_new()
{
	tcputbyte( _tc_NEW );
	return(1);	/* Allowas RAZ */
}

WORD	generate_raz()
{
	tcputbyte( _tc_RAZ );
	return( 0 );
}

WORD	generate_retseg()
{
	if ( OtrOption.ListFlag & 1 )
		echo_instruction("RET.SEG");
	tcode_instruction( _tc_ESC   );
	tcputbyte( _esc_RTS  );
	return( 0 );
}

VOID	tcode_segment_word( n )
WORD	n;
{
	if (!( Target )) return;
	if (( n == MOINS_UN) 
	&&  (Context->RelocateSegment != (XTSEGPTR) 0)) {
		Context->RelocateSegment->relocation->sector = Target->OutputSector;
		Context->RelocateSegment->relocation->length = Target->OutputIndex;
		Context->RelocateSegment = (XTSEGPTR) 0;
		}
	tcode_integer( n );
	return;
}


WORD	generate_clfendseg(rptr)
RESULTPTR	rptr;
{
	tcode_instruction( _tc_CLF   );
	tcputbyte( _clf_ETS  );
	switch ( rptr->nature ) {
		case _RESULT_INT   :
			tcputbyte( 0x0000    );
			tcode_segment_word(rptr->value);
			break;
		case _RESULT_VPTR  :
		case _RESULT_VARB  :
		case _RESULT_ALIAS :
			tcputbyte( 0x0040  );
			tcode_variable( rptr->contents );
			break;
		case _RESULT_ALEXPR  :
		case _RESULT_EXPR  :
			if ((rptr = mark_dead_result( rptr )) == (RESULTPTR) 0)
				return( internal_error(15) );
			tcputbyte( 0x0060 );
			tcode_register( rptr->value );
			break;
		}
	return( 0 );
}

WORD	generate_call_segment( vptr )
TCVARPTR	vptr;
{
	WORD	status;
	if ((status = generate_dimensions( 0, vptr )) !=0 )
		return( status );
	tcode_instruction( _tc_LDE );
	tcputbyte( 0x0040 );
	tcode_variable( vptr );
	return( 0 );
}

WORD	generate_ldgoseg(rptr,type,identity)
RESULTPTR	rptr;
WORD		type;
WORD		identity;	
{
	WORD	n;
	WORD	status;

	if (!( Target )) return(0);
	trace("generate_ldgoseg()\n");

	if ((( rptr->nature & _RESULT_BASIC) == _RESULT_VARB )) {
		if ((status = generate_dimensions( 0, rptr->contents )) !=0)
			return( status );
		}

	tcode_instruction( _tc_ESC );
	switch ( rptr->nature ) {
		case _RESULT_CONST :
			if ((n = constant_value( rptr->contents )) == MOINS_UN)
				return( syntax_error(3354) );
			else if ( n  <= 0x00FE ) {
				tcputbyte( _esc_SGI  );
				tcputbyte( n );
				}
			else	{
				tcputbyte( _esc_SGW  );
				if (( context_is_module )
				&&  ( type != MOINS_UN  ))
					add_segment_crossref(type,identity,Target->OutputSector,Target->OutputIndex);
				tcode_segment_word( n );
				}
			break;
		case _RESULT_INT   :
			trace("case _RESULT_INT\n");
			if ( (n = rptr->value) <= 0x00FE ) {
				tcputbyte( _esc_SGI  );
				tcputbyte( n );
				}
			else	{
				tcputbyte( _esc_SGW  );
				if (( context_is_module )
				&&  ( type != MOINS_UN  ))
					add_segment_crossref(type,identity,Target->OutputSector,Target->OutputIndex);
				tcode_segment_word( n );
				}
			break;
		case _RESULT_VPTR  :
		case _RESULT_VARB  :
		case _RESULT_ALIAS :
			tcputbyte( _esc_SGV    );
			tcode_variable( rptr->contents );
			break;
		case _RESULT_ALEXPR  :
		case _RESULT_EXPR  :
			if ((rptr = mark_dead_result( rptr )) == (RESULTPTR) 0)
				return( internal_error(15) );
			tcputbyte( _esc_SGR    );
			tcode_register( rptr->value );
			break;
		default		   :
			return( syntax_error(3355) );

		}
	return( 0 );
}

WORD	generate_return()
{
	trace("generate_return()\n");
	if ( OtrOption.ListFlag & 1 )
		echo_instruction("RETURN");
	tcode_instruction( _tc_RET );
	return( 0 );
}

WORD	generate_resume( mode, label )
WORD	mode;
WORD	label;
{
	if ( mode ) {
		tcode_instruction( _tc_REQ );
		tcode_label( label );
		}
	else	tcode_instruction( _tc_RES );
	return( 0 );
}

WORD	generate_goto_register( rptr )
RESULTPTR	rptr;
{
	tcode_instruction( _tc_ESC );
	tcputbyte( _esc_RGT );
	tcode_register( rptr->value );
	return( 0 );
}

WORD	generate_gosub_register( rptr )
RESULTPTR	rptr;
{
	tcode_instruction( _tc_ESC );
	tcputbyte( _esc_RGS );
	tcode_register( rptr->value );
	return( 0 );
}

WORD	generate_goto( adrlabel )
WORD	adrlabel;
{
	tcode_instruction( _tc_JMI );
	tcode_label( adrlabel );
	return( 0 );
}

WORD	generate_iteration()
{
	return( generate_goto( use_iteration_label( 1 ) ));
}

WORD	generate_abandon()
{
	return( generate_goto( use_abandon_label( 1 ) ));
}

WORD	generate_gosub( adrlabel )
WORD	adrlabel;
{
	trace("generate_gosub()\n");
	tcode_instruction( _tc_GSB );
	tcode_label( adrlabel );
	return( 0 );
}

WORD	generate_gosub_label( token )
BPTR	token;
{
	if ( OtrOption.ListFlag & 1 )
		echo_gosub_label( token );
	return( generate_gosub( use_explicite_label( token, 1) ));
}

WORD		generate_read_data( rptr )
RESULTPTR	rptr;
{
	WORD	status;
	DataUsed++;
	if ((status = generate_dimensions( 0, rptr->contents )) != 0)
		return( status );
	tcode_instruction( _tc_DTV );
	tcode_operand( rptr );
	return( 0 );
}

VOID	flush_sector()
{
	trace( "flush_sector()\n");
	if (!( Target )) return;
	else if ( Target->OutputIndex != 0 )
		flush_to_target();
}

VOID	flush_debug_sector()
{
	if (!( Target )) return;
	if ( OtrOption.Symbolic ) {
		trace( "flush_debug_sector()\n");
		Target = DebugTarget;
		if ( Target->OutputIndex != 0 )
			flush_to_target();
		Target = TcodeTarget;
		}
}

WORD	terminate_procedure_table()
{
	trace("terminate_procedure_table()\n");
	flush_sector();
	return( output_byte_count() );
}

WORD	terminate_segment_table()
{
	trace("terminate_segment_table()\n");
	tcode_integer( MOINS_UN );
	flush_sector();
	return( output_byte_count() );
}

WORD	terminate_external_segments()
{
	trace("terminate_external_segments()\n");
	flush_sector();
	return( output_byte_count() );
}

WORD	terminate_external_procedures()
{
	trace("terminate_external_procedures()\n");
	flush_sector();
	return( output_byte_count() );
}

WORD	terminate_external_fields()
{
	trace("terminate_external_fields()\n");
	flush_sector();
	return( output_byte_count() );
}

WORD	terminate_library_modules()
{
	trace("terminate_library_modules()\n");
	flush_sector();
	return( output_byte_count() );
}

VOID	commit_code_block()
{
	SECTORPTR	sptr;
	WORD		sector=0;

	if (!( Target )) return;

#ifdef	WITH_ATOC
	if (!( OtrOption.Generate ))
		tcode_to_c( Target->OutputBytes );
#endif
	Target->OutputSector   = Target->CodeSector;
	Target->OutputPosition = Target->CodePosition;
	Target->CodeSector   = 0;
	Target->CodePosition = 0L;
	while ((sptr = Target->CodeSectors[sector]) != (SECTORPTR) 0) {
		memcpy(Target->OutputBuffer,sptr->buffer,SECTORSIZE);
		flush_to_target();
		sptr->next = SectorHeap;
		SectorHeap = sptr;
		Target->CodeSectors[sector++]= (SECTORPTR) 0;
		if ( sector >= MAXOTRSECTORS ) 
			break;
		}
	return;
}

WORD	get_sector_byte( atadr )
WORD	atadr;
{
	SECTORPTR	sptr;
	if (!( Target )) return(0);
	if ((sptr = Target->CodeSectors[((atadr >> 8) & MAXSECTORMASK)]) == (SECTORPTR) 0)
		return( Target->OutputBuffer[(atadr & SECTORMASK)] );
	else	return( sptr->buffer[(atadr & SECTORMASK)] );
}

WORD	get_sector_word( WORD atadr )
{
	WORD	result=0;
	result =  (get_sector_byte(atadr)   & BYTEMASK);
	result |=((get_sector_byte(atadr+1) & BYTEMASK) << 8);
#ifdef	otr32
	if ( OtrOption.WordSize > 2 ) {
		result |=((get_sector_byte(atadr+2) & BYTEMASK) << 16);
		result |=((get_sector_byte(atadr+3) & BYTEMASK) << 24);
		}
#endif
	return( result );	
}

VOID	put_sector_byte( atadr, value )
WORD	atadr;
WORD	value;
{
	SECTORPTR	sptr;
	if (!( Target )) return;
	if ((sptr = Target->CodeSectors[((atadr >> 8) & MAXSECTORMASK )]) != (SECTORPTR) 0)
		sptr->buffer[(atadr & SECTORMASK)] = (BYTE) value;
	else	Target->OutputBuffer[(atadr & SECTORMASK)] = (BYTE) value;
	return;
}

VOID	put_sector_word(atadr,withadr)
WORD 	atadr;
WORD 	withadr;
{
	put_sector_byte(atadr,(withadr & BYTEMASK));
	put_sector_byte( (atadr+1), ((withadr >> 8) & BYTEMASK));
#ifdef	otr32
	if ( OtrOption.WordSize > 2 ) {
		put_sector_byte( (atadr+2),((withadr >> 16) & BYTEMASK));
		put_sector_byte( (atadr+3), ((withadr >> 24) & BYTEMASK));
		}
#endif
}

WORD	backpatch_label( atadr, withadr )
WORD	atadr;
WORD	withadr;
{
	WORD		result=MOINS_UN;

	if (!( Target )) return(MOINS_UN);
	trace("backpatch_label()\n");
	if ( atadr != MOINS_UN ) {
		if (( atadr == withadr )
		||  ( atadr > Target->OutputBytes )) {
#ifdef	otr32
			sysprintf("backpatch( at 0x%08.1X ( > 0x%08.1X ) with 0x%08.1X\n",atadr,Target->OutputBytes,withadr);
#else
			sysprintf("backpatch( at 0x%04.1X ( > 0x%04.1X ) with 0x%04.1X\n",atadr,Target->OutputBytes,withadr);
#endif
			(void) internal_error( 1313 );
			return( MOINS_UN );
			}
		result = get_sector_word(atadr);
		put_sector_word(atadr,withadr);
		return( result );
		}
	return( atadr );
}

WORD	backpatch_value( atadr, value )
WORD	atadr;
WORD	value;
{
	WORD		result=MOINS_UN;

	if (!( Target )) return(MOINS_UN);
	trace("backpatch_value()\n");
	if ( atadr != MOINS_UN ) {
		result = get_sector_word(atadr);
		put_sector_word(atadr,value);
		return( result );
		}
	return( atadr );
}

WORD	terminate_code_block()
{
	WORD	result;
	if (!( Target )) return(0);
	trace("terminate_code_block()\n");
	if (( Context->DataCount == 0 ) && ( DataUsed ))
		(void) issue_warning( 14 );
	flush_data_control();
	result = Target->OutputBytes;
	flush_sector();
	terminate_iterations();
	terminate_labels();
	if ( Target->CodeSector )
		commit_code_block();
	DataUsed = 0;
	return(result);
}

VOID	bufferise_sectors()
{
	if (!( Target )) return;
	Target->CodeSector   = current_target_sector();
	Target->CodePosition = Target->OutputPosition;
	return;
}

VOID	terminate_correspondances( sptr )
TCDBGPTR	sptr;
{
	if (!( Target )) return;
	if (( OtrOption.Symbolic )
	&&  ( DebugTarget != (OUTPUTPTR) 0 )) {
		Target = DebugTarget;
		tcode_integer( MOINS_UN );
		if ((sptr->length = output_byte_count()) != 0)
			flush_sector();
		else	sptr->sector = 0;
		Context->Correspondance = FAUX;
		Target = TcodeTarget;
		}
	return;
}

VOID	start_correspondances( sptr )
TCDBGPTR	sptr;
{
	WORD	i;
	if (!( Target )) return;
	if (( OtrOption.Symbolic )
	&&  ( DebugTarget != (OUTPUTPTR) 0 )) {
		sptr->sector = DebugTarget->OutputSector;
		sptr->length = DebugTarget->OutputBytes = 0;
		Target = DebugTarget;
		Context->Correspondance = VRAI;
		for ( i = 0; i < 4; i++ )
			tcode_integer(0);
		Target = TcodeTarget;
		}
	return;
}

VOID	generate_init_local()
{
	clf_initlocal();
	return;
}


VOID	start_code_block()
{
	DataUsed = 0;
	bufferise_sectors();
	initialise_labels();
	if ( OtrOption.InitLocal ) 
		generate_init_local();
	return;
}

BPTR	abal_crypt( pkey , sptr , slen ,mode)
WORD16	pkey;
BPTR	sptr;
WORD16	slen;
WORD16	mode;
{
	BPTR	rptr;
	BYTE	exkm[16][16];
	short int kdex,kdey;
	WORD16	rotor;
	WORD16	cmpt;
	WORD16	x,y;
	WORD16	phase;
	rptr = sptr; cmpt = 0;
	for (x = 0; x < 16 ; x++) {
		for ( y =0; y < 16; y++ ) {
			exkm[x][y] = (BYTE) cmpt; cmpt++;
			}
		}
	rotor = 1; phase = pkey & 0x0007;
	while ( slen > 0 ) {
		if ( mode == ENCODE ) { 
			kdex = ((WORD16) *sptr) / 16;
			kdey = ((WORD16) *sptr) % 16;
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

VOID	generate_header( pnom, type, mode )
BPTR	pnom;
WORD	type;	/* program or module */
WORD	mode;	/* 0 : Tcode .AT or .O  , 1 : Debug .DBG or .DBO */
{
	long	time(long *);
	WORD	i;
	if (!( Target )) return;
	first_sector();

#ifdef	otr32
	tcputbyte(OtrOption.TcodeVersion);			/* 0x00 */
	tcputbyte('1');						/* x01 */
	tcputbyte('3');						/* x02 */
#else
	tcputbyte('2');						/* 0x00 */
	tcputbyte('1');						/* x01 */

	if ( ISLOCAL & ISLOCAL3 )
		tcputbyte('3');					/* x02 */
	else	tcputbyte('4');					/* x02 */
#endif
	if ( mode != MOINS_UN ) {
		for ( i = 0; i < 15; i++ )			/* x03 */
			tcputbyte( *(pnom++) );

		/* NB the 0x0040 inhibits optimisation by AO */
		/* ----------------------------------------- */
		if (!( type & _CONTEXT_NOCLR ))
			i = (TROPT_OPTIMISE                 | (OtrOption.Symbolic & TROPT_DEBUG));
		else	i = ((TROPT_OPTIMISE | TROPT_CLEAR) | (OtrOption.Symbolic & TROPT_DEBUG));

		if ( OtrOption.KeyboardFlush ) {
			i |= TROPT_AFLUSH;
			}

		if ( OtrOption.NoFlush ) {
			i |= TROPT_BFLUSH;
			}

		if (!( OtrOption.UpperCase )) {
			i |= TROPT_SENSITIVE;
			}

		tcputbyte( i );	/* x12 */

		if  ( context_is_module	      )
			tcputbyte( 3 );		/* x13 */

		else if (( Context->sector_XTS != 0)
		     ||  ( Context->sector_XPT != 0)
		     ||  ( Context->sector_XFT != 0))
			tcputbyte( 1 );
		else	tcputbyte( 0 );
		tcode_integer( Context->ArgumentVariable );	/* x14	*/
		tcode_integer( Context->sector_GCT );		/* x16  */
		tcode_integer( Context->length_GCT );		/* x18	*/
		tcode_integer( Context->sector_GVT );		/* x1A	*/
		tcode_integer( Context->length_GVT );		/* x1C	*/
		tcode_integer( Context->megas_ETD  );		/* x1E	*/
		tcode_integer( Context->paras_ETD  );		/* x20 	*/
		if (( OtrOption.Symbolic )			/* x22  */
		&&  ( mode )) {
			tcode_integer(0);
			tcode_integer(0);
			}
		else	{
			tcode_integer( Context->sector_SDT );	/* x22	*/
			tcode_integer( Context->length_SDT );	/* x24	*/
			}
		tcode_integer( Context->sector_PDT );		/* x26	*/
		tcode_integer( Context->length_PDT );		/* x28	*/
		if (( OtrOption.Symbolic )			/* x2A	*/
		&&  ( mode ))
			tcode_integer( Context->Symbolic.sector_ProcedureNames );
		else	tcode_integer( 0 );
		tcode_integer( Context->biggest_LDT );		/* x2C */
		tcode_integer( Context->biggest_LDS );		/* x2E */

		if (( OtrOption.Symbolic )			/* x2A	*/
		&&  ( mode )) {
			tcode_integer( Context->sector_XPT ); 	/* x30 */
			tcode_integer( Context->sector_TRV ); 	/* x32 */
			tcode_integer( Context->sector_TRC ); 	/* x34 */
			}
		else	{
			tcode_integer( 0 );	/* Adr Tab Relloc Proc  x30 */
			tcode_integer( 0 );	/* Adr Tab Relloc Varb  x32 */
			tcode_integer( 0 );	/* Adr Tab Relloc Const x34 */
			}
		tcode_integer( Context->DiezeHeap );		/* x36 	*/
		tcode_integer( Context->DiezeFiles);		/* x38	*/
		tcode_integer( Context->DiezeMem  );		/* x3A	*/
		tcode_integer( Context->DiezeStack);		/* x3C	*/
	
		tcode_integer( 1958   );	/* Encryption Code x3E	*/
		tcode_integer( 0 );		/* MAP Sector	   x40	*/

		if (( OtrOption.Symbolic )
		&&  ( mode ))			/* List Sector 	   x42	*/
			tcode_integer( Context->Symbolic.sector_ListNames );
		else	tcode_integer( 0 );

		/* Dynamic Library Table */
		/* --------------------- */
		if (( OtrOption.Symbolic )			/* x44	*/
		&&  ( mode )) {
			tcode_integer(0);
			tcode_integer(0);
			}
		else	{
			if ( Context->sector_DLT ) {
				tcode_integer( Context->sector_DLT );/* x44	*/
				tcode_integer(((Context->length_DLT / SECTORSIZE) +1));/* x46	*/
				}
			else	{
				tcode_integer(0);
				tcode_integer(0);
				}	
			}

		tcode_integer( Context->sector_TRL );
						/* Adr Relloc LDF   x48	*/
		tcode_integer( 0 );		/* Val Min ALSM     x4A	*/

		tcode_integer( 0 );		/* Adr Image GDS    x4C : 28 */
		tcode_integer( 0 );		/* Lng Image GDS    x4E	: 29 */

		/* END OF VERSION 1.4 COMPATIBLE ZONE			*/
		/* ---------------------------------------------------- */
		/* START OF VERSION 2.1 COMPATIBLE ZONE			*/

		tcode_integer( pragma_page_size() ); 	/* Etd Page Size    x50 : 30	*/
		tcode_integer( pragma_swap_size() ); 	/* Max Swap Buffer  x52 : 31	*/
		tcode_integer( 0 );			/* Max Optimisation x54 : 32 	*/

		if (( OtrOption.Symbolic )
		&&  ( mode ))			/* x56 : 33	*/
			tcode_integer( Context->Symbolic.sector_SegmentNames );
		else	tcode_integer( 0 );

		if (( OtrOption.Symbolic )
		&&  ( mode ))			/* x58 : 34	*/
			tcode_integer( Context->sector_XTS ); /* Adr Tab Ext Seg */
		else	tcode_integer( 0 );

		if (( OtrOption.Symbolic )
		&&  ( mode ))	{		/* --------------------- */
			tcode_integer(Context->sector_XFT);/* VarExt x5A  : 35 */
			tcode_integer(Context->sector_XMT);/* NomMod x5C  : 36 */
			tcode_integer(0);	/* Adr Tab Csp Vgb   x5E  : 37*/
			tcode_integer(0);	/* Adr Tab Csp Cnst  x60  : 38 */
			tcode_integer(0);	/* Lng Tab Csp Cnst  x62  : 39 */
						/* --------------------- */
			}
		else	{
			if ( Context->ExpliciteExport ) {
				tcode_integer( Context->sector_PXT ); /* x5A : 35 */
				tcode_integer( Context->length_PXT ); /* x5C : 36 */
				}
			else	{
				tcode_integer( 0 );
				tcode_integer( 0 );
				}
			for ( i = 0; i < 3; i++ )
				tcode_integer( 0 ); /* Filler x5A -> x62 */
			}

		if (( OtrOption.Symbolic )
		&&  ( mode ))			/* x64	*/
			tcode_integer( Context->Symbolic.sector_FileNames );
		else	tcode_integer( 0 );

		if (( OtrOption.Symbolic )
		&&  ( mode ))	{		/* ------------------------ */
			tcode_integer( Context->sector_GLT );	/* Adr Tab Labels	x66 */
			tcode_integer( Context->sector_XDT );	/* Adr Tab Var Ext	x68 */
			tcode_integer( Context->length_XDT );	/* Lng Tab Var Ext	x6A */
			tcode_integer( 0 );	/* Adr Nom Const Bin	x6C */
			tcode_integer( 0 );	/* Adr Nom Const	x6E */
			tcode_integer( 0 );	/* Reserved 		x70 */
						/* ------------------------ */
			}
		else	{
			for ( i = 0; i < 6; i++ )
				tcode_integer( 0 ); /* Filler x66 -> x70    */
			}
		tcode_integer( Context->SegmentNumber );	/* x72 */

		/* END OF VERSION 2.1 COMPATIBLE ZONE			    */
		/* -------------------------------------------------------- */
		/* START OF OTR/CTR MIXED LANGUAGE ZONE			    */

		tcode_integer( Context->LanguageCode );		/* x74 	    */

		if (( OtrOption.Symbolic )
		&&  ( mode )) {
			tcode_integer( Context->sector_XLT );	/* x76	    */
			tcode_integer( 0 );                  	/* x78	    */
			tcode_integer( 0 );                   	/* x7A	    */
			tcode_integer( 0 );                   	/* x7C	    */
			tcode_integer( Context->DebugNature );  /* x7E	    */
			}
		else	{
			tcode_integer( Context->Semaphores );
			tcode_integer( Context->sector_NCT );	/* x78	    */
			tcode_integer( Context->length_NCT );	/* x7A	    */
			tcode_integer( 0 );                   	/* x7C	    */
			tcode_integer( 0 );                   	/* x7E	    */
			}

		/* END OF VERSION 3.2 COMPATIBLE ZONE			    */
		/* -------------------------------------------------------- */
		/* START OF VERSION 3.3			    */

#ifdef ABAL33A
		/* Reserve space for time stamp */
		tcode_integer( MOINS_UN );
		tcode_integer( MOINS_UN );	

		if (( OtrOption.Symbolic )
		&&  ( mode )) {
			tcode_integer( 0 );
			tcode_integer( 0 );
		}
		else {
			tcode_integer( Context->sector_LMT );
			tcode_integer( Context->length_LMT );
		}
#endif

		(void) abal_crypt( 1958,(BPTR) & Target->OutputBuffer[(9*WORD16SIZE)],((21*OtrOption.WordSize)+(2*BYTESIZE)), ENCODE );

		/* Time stamp (fixed position for all versions) */
		/* -------------------------------------------- */
		tcputlong(&Target->OutputBuffer[OFFSET_TIMESTAMP],time((long*)0));
		}
	flush_sector();
	return;

}

VOID	generate_tcode_header(pnom, type )
BPTR	pnom;
WORD	type;
{
	if (!( Target )) return;
	generate_header( pnom, type, 0 );
	return;
}

VOID	generate_debug_header(pnom, type )
BPTR	pnom;
WORD	type;
{
	if (!( Target )) return;
	if (( OtrOption.Symbolic )
	&&  ( DebugTarget != (OUTPUTPTR) 0)) {
		Target = DebugTarget;
		generate_header( pnom, type, 1 );
		Target = TcodeTarget;
		}
	return;
}

OUTPUTPTR	terminate_target_context( tptr, keepfile )
OUTPUTPTR	tptr;
WORD		keepfile;	/* 1 : YES KEEP, 0 : NO DELETE	*/
{
	trace("terminate_target_context()\n");
	if ((Target = tptr) != (OUTPUTPTR) 0) {
		if ( Target->OutputHandle != 0 ) {
			flush_sector();
			if ( Target->CodeSector )
				commit_code_block();
			close( Target->OutputHandle );
			if ( GlobalError )
				unlink( Target->OutputName );
			else if (( Context->sector_XTS == 0 )
			     &&  ( Context->sector_XPT == 0 )
			     &&  ( Context->sector_XFT == 0 )
			     &&  (!( context_is_module     ))) {
				/* Not a Module (.AT, .APL, .DBG, temporary extensions) */
				unlink( Target->ResultName );
				if ( keepfile )
					rename( Target->OutputName,Target->ResultName);
				else	unlink( Target->OutputName );
#ifdef WIN32		
				if (OtrOption.TargetType == 2) {
					/* Module was expected by caller: all extensions accepted except .AT */
					if (compare_tokens(Target->ResultName + strlen(Target->ResultName) - 3, ".at")) {
						unlink( Target->ResultName );
						incorrect_target_type();
						}
					}
#endif
				}
			else	{
				/* Module (.O, .DBO, temporary extensions) */
				unlink( Target->ObjectName );
				rename( Target->OutputName,Target->ObjectName);
#ifdef WIN32
				if (OtrOption.TargetType == 1) {
					/* Program was expected by caller */
					if (OtrOption.NoAutoLink || (Context->length_LMT == 0) ) {
						/* Autolink disabled or nothing to link */
						unlink( Target->ResultName );
						incorrect_target_type();
						}
					}
#endif
				}
			Target->OutputHandle = 0;
			}
		liberate( Target );
		Target = (OUTPUTPTR) 0;
		}
	return( (OUTPUTPTR) 0);
}

WORD	set_target_encryption( valeur )
WORD	valeur;
{
	if ( Target != (OUTPUTPTR) 0 )
		Target->CryptCode = valeur;
	return(0);
}

WORD	get_target_encryption( VOID )
{
	if ( Target != (OUTPUTPTR) 0 )
		return( Target->CryptCode );
	else	return( MOINS_UN );
}

OUTPUTPTR	create_target_context( filename, extension, extension2, extension3 )
BPTR		filename;
BPTR		extension;
BPTR		extension2;
BPTR		extension3;
{
	WORD	l;

	if ((Target = (OUTPUTPTR) allocate( sizeof( struct otr_output ) )) != (OUTPUTPTR) 0) {

		Target->OutputHandle = 0;
		Target->CodeSector   = 0;
		Target->CodePosition = 0L;
		Target->CryptCode    = MOINS_UN;

		SectorHeap   = (SECTORPTR) 0;

/*
		memset( Target->CodeSectors, 0, MAXOTRSECTORS*sizeof( SECTORPTR ));
 */
		for ( l = 0; l < MAXOTRSECTORS; l++ )
			Target->CodeSectors[l] = (SECTORPTR) 0;
		reset_byte_count();
		reset_output();
		first_sector();
		(VOID) fn_parser( filename, Target->FilenameRoot, 0x000F );
		if ( OtrOption.Generate ) {

			if ((l = fn_parser( filename, Target->ResultName, 0x000F )) == 0) {
				(void) target_file_error( filename, 30 );
				return( terminate_target_context( Target , 0 ) );
				}
			strcat( Target->ResultName, extension2 );

			if ((l = fn_parser( filename, Target->OutputName, 0x000F )) == 0) {
				(void) target_file_error( filename, 30 );
				return( terminate_target_context( Target , 0 ) ); 
				}
			strcat( Target->OutputName, extension3 );

			if ((l = fn_parser( filename, Target->ObjectName, 0x000F )) == 0) {
				(void) target_file_error( filename, 30 );
				return( terminate_target_context( Target , 0 ) );
				}
			strcat( Target->ObjectName, extension );

			if (context_is_program) {
				if (is_target_file_busy(Target->ResultName)) {
					(void) target_file_busy();
					return( terminate_target_context( Target , 0 ) );
					}
			}

			unlink( Target->OutputName );
#ifdef WIN32
			if (( Target->OutputHandle = creat( Target->OutputName, _S_IREAD | _S_IWRITE )) == MOINS_UN ) {
#else
			if (( Target->OutputHandle = creat( Target->OutputName, 0666 )) == MOINS_UN ) {
#endif
				(void) target_file_error( Target->OutputName, 41 );
				return( terminate_target_context( Target , 0 ) );
				}
			else	{
				close( Target->OutputHandle );
				if (( Target->OutputHandle = open( Target->OutputName,(O_RDWR | O_BINARY) )) == MOINS_UN ) {
					(void) target_file_error( Target->OutputName, 40 );
					return( terminate_target_context( Target, 0 ) );
					}
				}
			}
		}
	return(Target);
}

VOID	use_debug_file()
{
	Target = DebugTarget;
	return;
}

VOID	use_tcode_file()
{
	Target = TcodeTarget;
	return;
}

BPTR	get_target_root()
{
	if ( TcodeTarget != (OUTPUTPTR) 0 )
		return( TcodeTarget->FilenameRoot );
	else	return((BPTR) 0);
}

WORD	initialise_apl_output( filename )
BPTR	filename;
{
	TcodeTarget = (OUTPUTPTR) 0;
	DebugTarget = (OUTPUTPTR) 0;

	if ((TcodeTarget = create_target_context( filename, ".mcl", ".apl", ".opl" )) == (OUTPUTPTR) 0)
		return( target_file_error( filename, 46 ) );

	if ( OtrOption.Symbolic ) {
		if ((DebugTarget = create_target_context( filename,".msl",".asl",".osl" )) == (OUTPUTPTR) 0)
			return( target_file_error( filename, 46 ) );
		else	generate_header( "DEBUG            ", 0, MOINS_UN );
		}

	Target = TcodeTarget;
	return( 0 );
}

WORD	initialise_output( filename )
BPTR	filename;
{

	TcodeTarget = (OUTPUTPTR) 0;
	DebugTarget = (OUTPUTPTR) 0;

	if ((TcodeTarget = create_target_context( filename, ".o", ".at", ".ot" )) == (OUTPUTPTR) 0)
		return( target_file_error( filename, 46 ) );

	if ( OtrOption.Symbolic ) {
		if ((DebugTarget = create_target_context( filename,".dbo",".dbg",".odb" )) == (OUTPUTPTR) 0)
			return( target_file_error( filename, 46 ) );
		else	generate_header( "DEBUG            ", 0, MOINS_UN );
		}

	Target = TcodeTarget;
	return( 0 );
}

#ifdef ABAL33A

#ifndef WIN32
static	WORD	run_linker(BPTR args)
{
	BPTR	cptr;
	WORD	status=0;

	if ((cptr = (BPTR)allocate( strlen(args) + 16 )) != (BPTR)0) {
		sprintf(cptr,"old32 %s", args);
		status = system(cptr);
		liberate(cptr);
	}
	else status = allocation_failure();
	return status;
}
#endif

static	VOID	perform_autolink(BPTR filename)
{
	BPTR args;
	WORD status = 0;

	if (OtrOption.AutoLink != (BPTR)0) {
		args = OtrOption.AutoLink;

		if (OtrOption.Verbose) 
			sysprintf("AutoLink args: %s\r\n", args);

		status = run_linker(args);
	}
	else {
		if ((args = (BPTR) allocate(build_linker_default_options((BPTR)0) + strlen(filename) + 1 + 128 /*security*/)) != (BPTR)0) {
			if (build_linker_default_options(args)) {
				strcat(args, filename);
				if (OtrOption.Verbose) 
					sysprintf("AutoLink args: %s\r\n", args);
				status = run_linker(args);
			}
			liberate(args);
		}
	}
	if (OtrOption.Verbose) {
		if (!( status ))
			sysprintf("link completed\r\n");
		else {
			sysprintf("link not completed\r\n");
			internal_error(22005);
		}
	}
}
#endif

VOID	terminate_output()
{
	SECTORPTR	sptr;
	BYTE			filename[256];

	trace("terminate_output()\n");

#ifdef ABAL33A
	sprintf(filename, " %s.o", get_target_root());
#endif
	if ( TcodeTarget != (OUTPUTPTR) 0)
		TcodeTarget = terminate_target_context( TcodeTarget, 1 );

	if ( DebugTarget != (OUTPUTPTR) 0)
		DebugTarget = terminate_target_context( DebugTarget, (OtrOption.Symbolic & 1) );

#ifdef ABAL33A
	if ((context_is_program) && (OtrOption.NoAutoLink == FAUX))
		if (Context->length_LMT != 0)	/* Something to link */
			if (!( Context->ExpliciteExtern ))
				perform_autolink(filename);
#endif

	trace("liberate_sector_heap()\n");
	while ((sptr = SectorHeap) != (SECTORPTR) 0) {
		trace("sector\n");
		SectorHeap = SectorHeap->next;
		liberate( sptr );
		}

	return;
}

WORD	generate_comment(mode)
WORD	mode;
{
	return(0);
}

#endif	/* _TROUTPUT_C */
	/* ----------- */

