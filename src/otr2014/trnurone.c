#define DEBUG
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRNURONE.C				*/
/*		Version :	2.1d					*/
/*		Date	:	23/02/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/

#ifndef	_TRNURONE_C
#define	_TRNURONE_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include "stdtypes.h"
#include "translat.h"
#include "trparser.h"
#include "trsyntax.h"
#include "trerrors.h"
#include "trsymbol.h"
#include "troption.h"
#include "trexpres.h"
#include "trnurone.h"
#include "trdebug.h"

EXTERN	BYTE	TokenBuffer[];

NURONETPTR	allocate_for_network_class()
{
	NURONETPTR	nptr;
	trace("allocate_for_network_class()\n");
	if ((nptr = allocate( sizeof( struct otr_nural_network_class ) )) != (NURONETPTR) 0) {
		nptr->mode   = _FORWARD_LAYER;
		nptr->nature = _NATURE_SUMATE;
		nptr->name   = (BPTR) 0;
		nptr->weights= 0;
		nptr->inputs = 0;
		nptr->nurones= 0;
		nptr->input  = (TCVARPTR) 0;
		nptr->output = (TCVARPTR) 0;
		nptr->flevel = (NURONEPTR) 0;
		nptr->ilevel = (NURONEPTR) 0;
		nptr->hlevel = (NURONEPTR) 0;
		nptr->olevel = (NURONEPTR) 0;
		nptr->next   = (NURONETPTR) 0;
		}
	return( nptr );
}

NUROBJPTR	allocate_for_network_object()
{
	NUROBJPTR	nptr;
	trace("allocate_for_network_object()\n");
	if ((nptr = allocate( sizeof( struct otr_nural_network_object ) )) != (NUROBJPTR) 0) {
		nptr->name = (BPTR) 0;
		nptr->next = (NUROBJPTR) 0;
		nptr->class = (NURONETPTR) 0;
		nptr->type  = 0;
		}
	return( nptr );
}

NURONETPTR	is_nural_network_class( tptr )
BPTR	tptr;
{
	NURONETPTR	nptr;
	if ((nptr = NuralNetworkClass) !=(NURONETPTR) 0) {
		do	{
			if ( compare_tokens( tptr, nptr->name ) )
				return( nptr );
			}
		while ((nptr = nptr->next) != (NURONETPTR) 0);
		}
	return( nptr );
}

NUROBJPTR	is_nural_network_object( tptr )
BPTR	tptr;
{
	NUROBJPTR	nptr;
	trace("is_nural_netwrok_object()\n");

	if ((nptr = NuralNetworkObject) !=(NUROBJPTR) 0) {
		do	{
			if ( compare_tokens( tptr, nptr->name ) )
				return( nptr );
			}
		while ((nptr = nptr->next) != (NUROBJPTR) 0);
		}
	return( nptr );
}

static	WORD	translate_network_members();

VOID	show_synapses( vptr )
TCVARPTR	vptr;
{
	WORD	nombre=0;
	sysprintf("(");
	while ( vptr != (TCVARPTR) 0) {
		if ( nombre )
			sysprintf(",");
		sysprintf("%s",vptr->name);
		nombre++;

		vptr = vptr->next;
		}
	sysprintf(")");
	return;
}

VOID	show_network_signature( nptr )
NURONETPTR	nptr;
{
	sysprintf("NETWORK %s ",nptr->name);
	show_synapses( nptr->input );
	if ( nptr->output != (TCVARPTR) 0 )
		sysprintf(" : ");
	show_synapses( nptr->output );
	sysprintf("\n");
	return;
}

VOID	show_layer( uptr )
NURONEPTR	uptr;
{
	while ( uptr != (NURONEPTR) 0) {
		switch ( uptr->state ) {
			case _FORWARD_LAYER : sysprintf("Forward Nurone %s ",uptr->name);break;
			case _INPUT_LAYER   : sysprintf("Input   Nurone %s ",uptr->name);break;
			case _OUTPUT_LAYER  : sysprintf("Output  Nurone %s ",uptr->name);break;
			case _HIDDEN_LAYER  : sysprintf("Hidden  Nurone %s ",uptr->name);break;
			}
		show_synapses( uptr->input );
		if ( uptr->output != (TCVARPTR) 0 )
			sysprintf(" : ");
		show_synapses( uptr->output );
		sysprintf("\n");
		uptr = uptr->next;
		}
	return;
}

VOID	show_network_nodes( nptr )
NURONETPTR	nptr;
{
	show_layer( nptr->ilevel );
	show_layer( nptr->hlevel );
	show_layer( nptr->olevel );
	return;
}

VOID	show_network( nptr )
NURONETPTR	nptr;
{
	show_network_signature( nptr );
	show_network_nodes( nptr );
	return;
}

static	WORD	collect_network_definition( nptr )
NURONETPTR	nptr;
{
	TCVARPTR	vptr;
	if ((nptr->input = collect_typed_parameters(1)) != (TCVARPTR) 0) {
		vptr = nptr->input;
		do	{
			nptr->inputs++;
			}
		while ((vptr = vptr->next) != (TCVARPTR) 0);
		}	
	if ( is_colon() )
		nptr->output = collect_typed_parameters(1);
	nptr->next = NetworkDefine;
	NetworkDefine = nptr;
	push_operation_pointer();
	set_operation_pointer(translate_network_members);
	return( 0 );
}

static	WORD	translate_instance( nptr, mode )
NURONETPTR	nptr;
WORD		mode;
{
	WORD		status;
	WORD		ptrdcl=_KW1_DCL;
	NUROBJPTR	optr=(NUROBJPTR) 0;
	trace("translate_instance()\n");
	if ( is_mnemonic( "PTR" ) )
		ptrdcl = _KW1_PTR;
	if ( get_token() ) {
		if ((optr = is_nural_network_object( TokenBuffer )) != (NUROBJPTR) 0)
			return( syntax_error(500) );
		if (((optr = allocate_for_network_object()) == (NUROBJPTR) 0)
		||  ((optr->name = allocate_for_token( TokenBuffer )) == (BPTR) 0  ))
			return( allocation_failure() );
		optr->next = NuralNetworkObject;
		NuralNetworkObject = optr;
		optr->type = ptrdcl;
		optr->class = nptr;
		}
	if ( mode ) {
		if ( optr == (NUROBJPTR) 0 )
			return( syntax_error(501) );
		else if ( NetworkDefine == (NURONETPTR) 0)
			return( add_variable( optr->name, 3, 5, 1, 2, optr->type, 0, 0 ) );
		else	return( 0 );
		}
	else	{
		if (( ptrdcl != _KW1_DCL ) && ( optr == (NUROBJPTR) 0))
			return( syntax_error(502) );
		else	return( collect_network_definition(nptr) );
		}
}

static	WORD	translate_definition( tptr )
BPTR	tptr;
{
	NURONETPTR	nptr;

	if (((nptr = allocate_for_network_class()) == (NURONETPTR) 0)
	||  ((nptr->name = allocate_for_token( tptr )) == (BPTR) 0  ))
		return( allocation_failure() );
	return( translate_instance( nptr, FAUX ) );
}



static	WORD	translate_sumate()
{
	NURONETPTR	nptr;
	if ((nptr = NetworkDefine) == (NURONETPTR) 0)
		return( syntax_error(503) );
	nptr->nature = _NATURE_SUMATE;
	return( 0 );
}

static	WORD	translate_limiter()
{
	NURONETPTR	nptr;
	if ((nptr = NetworkDefine) == (NURONETPTR) 0)
		return( syntax_error(504) );
	nptr->nature = _NATURE_LIMITER;
	return( 0 );
}

static	WORD	translate_sigmoid()
{
	NURONETPTR	nptr;
	if ((nptr = NetworkDefine) == (NURONETPTR) 0)
		return( syntax_error(505) );
	nptr->nature = _NATURE_SIGMOID;
	return( 0 );
}

static	WORD	translate_endnetwork()
{
	NURONETPTR	nptr;
	if ((nptr = NetworkDefine) == (NURONETPTR) 0)
		return( syntax_error(506) );
	else	NetworkDefine = nptr->next;
	if ((nptr->next = NuralNetworkClass) == (NURONETPTR) 0)
		nptr->identity = 1;
	else	nptr->identity = (nptr->next->identity + 1);
	if ( OtrOption.Verbose & 8 )
		show_network( nptr );
	NuralNetworkClass = nptr;
	pop_operation_pointer();
	if ( nptr->flevel != (NURONEPTR) 0 )	
		return( syntax_error(507) );
	else	return(0);
}

static	WORD	translate_network()
{
	NURONETPTR nptr;
	if (!( get_token() ))
		return( syntax_error(508) );
	else if ((nptr = is_nural_network_class(TokenBuffer)) != (NURONETPTR) 0)
		return( translate_instance( nptr, VRAI ) );
	else	return( translate_definition( TokenBuffer ) );
}

static	WORD	locate_synapse( vptr, name )
TCVARPTR	vptr;
BPTR		name;
{
	do	{
		if ( compare_tokens( name, vptr->name ) )
			return( 1 );
		}
	while ((vptr = vptr->next) != (TCVARPTR) 0);
	return(0);
}

WORD	input_synapse_identity( vptr, name )
TCVARPTR	vptr;
BPTR		name;
{
	WORD	i=1;
	do	{
		if ( compare_tokens( name, vptr->name ) )
			return( i );
		else	i++;
		}
	while ((vptr = vptr->next) != (TCVARPTR) 0);
	return(0);
}


NURONEPTR	allocate_for_nurone()
{
	NURONEPTR	nptr;
	if ((nptr = allocate( sizeof( struct otr_nurone ) )) != (NURONEPTR) 0) {
		nptr->name   = (BPTR) 0;
		nptr->state  = _FORWARD_LAYER;
		nptr->inputs = 0;
		nptr->input  = (TCVARPTR) 0;
		nptr->output = (TCVARPTR) 0;
		nptr->next   = (NURONEPTR) 0;
		nptr->prev   = (NURONEPTR) 0;
		}
	return( nptr );
}


static	WORD	add_nurone( nptr, name, input, output, state )
NURONETPTR	nptr;
BPTR		name;
TCVARPTR	input;
TCVARPTR	output;
WORD		state;
{
	NURONEPTR	uptr;
	NURONEPTR	vptr;
	TCVARPTR	varptr;
	if ((uptr = allocate_for_nurone()) == (NURONEPTR) 0)
		return( allocation_failure() );
	if ((varptr = input) != (TCVARPTR) 0) {
		do	{
			nptr->weights++;
			}
		while ((varptr = varptr->next) != (TCVARPTR) 0);
		}
	if ( state )
		nptr->nurones++;
	uptr->identity = (nptr->inputs + nptr->nurones);
	uptr->name  = name;
	uptr->state = state;
	uptr->nature = nptr->nature;
	if ((uptr->input = input) != (TCVARPTR) 0) {
		do	{
			uptr->inputs++;
			}
		while ((input = input->next) != (TCVARPTR) 0);
		}
	uptr->output = output;
	switch ( state ) {
		case	_FORWARD_LAYER	:
			if ((vptr = nptr->flevel) ==(NURONEPTR) 0)
				nptr->flevel = uptr;
			else 	{
				while (vptr->next != (NURONEPTR) 0)
					vptr = vptr->next;
				vptr->next = uptr;
				}
			break;
		case	_INPUT_LAYER	:
			if ((vptr = nptr->ilevel) ==(NURONEPTR) 0)
				nptr->ilevel = uptr;
			else 	{
				while (vptr->next != (NURONEPTR) 0)
					vptr = vptr->next;
				vptr->next = uptr;
				}
			break;
		case	_OUTPUT_LAYER	:
			if ((vptr = nptr->olevel) ==(NURONEPTR) 0)
				nptr->olevel = uptr;
			else 	{
				while (vptr->next != (NURONEPTR) 0)
					vptr = vptr->next;
				vptr->next = uptr;
				}
			break;
		case	_HIDDEN_LAYER	:
			if ((vptr = nptr->hlevel) ==(NURONEPTR) 0)
				nptr->hlevel = uptr;
			else 	{
				while (vptr->next != (NURONEPTR) 0)
					vptr = vptr->next;
				vptr->next = uptr;
				}
			break;
			
		}
	return( 0 );
}

static	WORD	add_forward_nurone( nptr, name )
NURONETPTR	nptr;
BPTR		name;
{
	return( add_nurone( nptr, name, (TCVARPTR) 0, (TCVARPTR) 0, _FORWARD_LAYER) );
}


NURONEPTR	is_nurone( nptr, name )
NURONEPTR	nptr;
BPTR		name;
{
	while ( nptr != (NURONEPTR) 0) {
		if ( compare_tokens( name, nptr->name ) )
			break;
		else	nptr = nptr->next;
		}
	return( nptr );
	return(0);
}

static	NURONEPTR	locate_nurone( nptr, name )
NURONETPTR	nptr;
BPTR		name;
{
	NURONEPTR	uptr;
	if (((uptr = is_nurone( nptr->ilevel, name )) != (NURONEPTR) 0)
	||  ((uptr = is_nurone( nptr->hlevel, name )) != (NURONEPTR) 0)
	||  ((uptr = is_nurone( nptr->olevel, name )) != (NURONEPTR) 0)
	||  ((uptr = is_nurone( nptr->flevel, name )) != (NURONEPTR) 0))
		return( uptr );
	else	return( uptr );
}

WORD	nurone_identity( nptr, name )
NURONETPTR	nptr;
BPTR		name;
{
	NURONEPTR	uptr;
	if ((uptr = locate_nurone( nptr, name )) != (NURONEPTR) 0)
		return( uptr->identity );
	else	return( 0 );
}


static	WORD	build_nurone( nptr, name, input, output )
NURONETPTR	nptr;
BPTR		name;
TCVARPTR	input;
TCVARPTR	output;
{
	TCVARPTR	vptr;
	TCVARPTR	wptr;
	WORD		status;
	NURONEPTR	uptr;
	if ((uptr = locate_nurone( nptr, name )) == (NURONEPTR) 0) {
		if ((status = add_nurone(nptr, name, input, output, nptr->mode )) != 0)
			return( status );
		}
	else	{
		if ( uptr->state != 0 )
			return( syntax_error(509) );
		else if ((status = add_nurone(nptr, name, input, output, nptr->mode )) != 0)
			return( status );
		if ( uptr->next != (NURONEPTR) 0)
			uptr->next->prev = uptr->prev;
		if ( uptr->prev != (NURONEPTR) 0 ) 
			uptr->prev->next = uptr->next;
		else	nptr->flevel = uptr->next;
		liberate( uptr->name );
		liberate( uptr );				
		}
	if ((vptr = input) != (TCVARPTR) 0) {
		do	{
			if ( locate_synapse( nptr->input,vptr->name )  != 0) {
				if ( nptr->mode == _INPUT_LAYER )
					continue;
				else 	return( syntax_error(510) );
				}
			else if ( nptr->mode == _INPUT_LAYER )
				return( syntax_error(511) );
			else	{
				if (((uptr = locate_nurone(  nptr, vptr->name )) == (NURONEPTR) 0)
				&&  ((status = add_forward_nurone( nptr, vptr->name )) != 0))
					return( status );
				}
			}
		while ((vptr = vptr->next) != (TCVARPTR) 0);
		}
	if ((vptr = output) != (TCVARPTR) 0) {
		do	{
			if ( locate_synapse( nptr->output,vptr->name )  != 0) {
				if ( nptr->mode == _OUTPUT_LAYER )
					continue;
				else 	return( syntax_error(512) );
				}
			else if ( nptr->mode == _OUTPUT_LAYER )
				return( syntax_error(513) );
			else	{
				if (((uptr = locate_nurone(  nptr, vptr->name )) == (NURONEPTR) 0)
				&&  ((status = add_forward_nurone( nptr, vptr->name )) != 0))
					return( status );
				}
			}
		while ((vptr = vptr->next) != (TCVARPTR) 0);
		}
	return( 0 );
}


static	WORD	translate_nurone()
{
	NURONETPTR	nptr;
	TCVARPTR	input=(TCVARPTR) 0;
	TCVARPTR	output=(TCVARPTR) 0;
	BPTR		tptr;
	if (((nptr = NetworkDefine) == (NURONETPTR) 0)
	||  ( nptr->mode == 0 ))
		return( syntax_error(514) );
	if (!( get_token() ))
		return( syntax_error(515) );
	if ((tptr = allocate_for_token( TokenBuffer )) == (BPTR) 0)
		return( allocation_failure() );
	input = collect_typed_parameters(1);
	if ( is_colon() )
		output = collect_typed_parameters(1);
	return( build_nurone(nptr,tptr,input,output) );
}

static	WORD	translate_input()
{
	NURONETPTR	nptr;
	if ((nptr = NetworkDefine) == (NURONETPTR) 0)
		return( MOINS_UN );
	if (!( is_mnemonic( "LAYER" ) ))
		return( syntax_error(517) );
	nptr->mode = _INPUT_LAYER;
	return(0);
}

static	WORD	translate_output()
{
	NURONETPTR	nptr;
	if ((nptr = NetworkDefine) == (NURONETPTR) 0)
		return( MOINS_UN );
	if (!( is_mnemonic( "LAYER" ) ))
		return( syntax_error(519) );
	nptr->mode = _OUTPUT_LAYER;
	return(0);
}

static	WORD	translate_hidden()
{
	NURONETPTR	nptr;
	if ((nptr = NetworkDefine) == (NURONETPTR) 0)
		return( MOINS_UN );
	if (!( is_mnemonic( "LAYER" ) ))
		return( syntax_error(521) );
	nptr->mode = _HIDDEN_LAYER;
	return(0);
		
}

static	WORD	translate_layer()
{
	return( syntax_error(522) );
}
	
WORD	translate_nural_keyword( type )
WORD	type;
{
	trace("translate_nural_keyword()\n");
	switch (type) {
		case	_NURO_NETWORK	:
			return( translate_network() );
		case	_NURO_ENDNETWORK	:
			return( translate_endnetwork() );
		case	_NURO_NURONE	:
			return( translate_nurone() );
		case	_NURO_INPUT  	:
			return( translate_input() );
		case	_NURO_OUTPUT	:
			return( translate_output() );
		case	_NURO_HIDDEN	:
			return( translate_hidden() );
		case	_NURO_LAYER		:
			return( translate_layer() );
		case 	_NURO_SUMATE		:
			return( translate_sumate() );
		case 	_NURO_LIMITER		:
			return( translate_limiter() );
		case 	_NURO_SIGMOID		:
			return( translate_sigmoid() );
		default			:
			return( MOINS_UN );
		}

}

static	WORD	translate_network_members()
{
	WORD	type;
	if (!( get_token() ))
		return( 0 );
	else if ((type = is_nural_keyword()) != MOINS_UN)
		return( translate_nural_keyword(type) );
	else	return( syntax_error(523) );

}

static	WORD	flush_nurones(nptr, uptr )
NURONETPTR	nptr;
NURONEPTR	uptr;
{
	WORD	status;
	trace("flush_nural_classes()\n");
	while ( uptr != (NURONEPTR) 0) {
		if ((status = generate_nurone_entry(nptr, uptr )) != 0 )
			return( status );		
		else	uptr = uptr->next;
		}
	return( 0 );
}

WORD	flush_nural_classes()
{
	NURONETPTR	nptr;
	NURONEPTR	uptr;
	WORD		data_table_sector=0;
	WORD		data_table_length=0;
	WORD		status;

	trace("flush_nural_classes()\n");

	if ((nptr = NuralNetworkClass) != (NURONETPTR) 0) {
		data_table_sector = current_target_sector();
		do	{
			if ((status = generate_network_header( nptr )) != 0)
				break;
			if ((status = flush_nurones(nptr, nptr->ilevel)) != 0)
				break;
			if ((status = flush_nurones(nptr, nptr->hlevel)) != 0)
				break;
			if ((status = flush_nurones(nptr, nptr->olevel)) != 0)
				break;
			}
		while ((nptr = nptr->next) != (NURONETPTR) 0);
		tcode_integer( MOINS_UN );
		flush_sector();
	
		data_table_length = output_byte_count();

		/* Check for something written : otherwise cancel sector */
		/* ----------------------------------------------------- */
		if ( data_table_sector == current_target_sector() )
			data_table_sector = 0;

		}
	Context->length_NCT = data_table_length;
	return( data_table_sector );
}

WORD	nural_class_identity( vptr )
TCVARPTR	vptr;
{
	NUROBJPTR	optr;
	trace("nural_class_identity()\n");
	if ((optr = is_nural_network_object( vptr->name )) == (NUROBJPTR) 0)
		return( syntax_error(524) );
	else	return( optr->class->identity );	
}

#endif	/* _TRNURONE_C */
	/* ----------- */


