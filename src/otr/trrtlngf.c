#define	DEBUG
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRNGF.C    				*/
/*		Version :	2.1c					*/
/*		Date	:	28/09/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRRTLNGF_C
#define	_TRRTLNGF_C
#define	_TRNGF_C

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
#include "trlabels.h"
#include "trngf.h"
#include "trrtlngf.h"
#include "trgenc.h"
#include "trdebug.h"
#include "trtnode.h"
#undef 	_TRNGF_C

#ifndef	UNIX
RESULTPTR	build_string_constant( RESULTPTR, BPTR );
#else
RESULTPTR	build_string_constant();
#endif

/*	------------------------------------------------------		*/
/*	SERVICE (static) FUNCTIONS used during NGF TRANSLATION		*/
/*	------------------------------------------------------		*/

static	VOID	reset_ngf()
{
	WORD	i;

	for ( i = 0; i < 16; i++ )
		NGF.Parameter[i] = (BPTR) 0;

	NGF.Special    = 0;
	NGF.Operation  = MOINS_UN;
	NGF.Parameters = 0;
	NGF.Colon      = FAUX;
	NGF.Error      = (BPTR) 0;
	NGF.ErrorFlag  = MOINS_UN;
	NGF.ErrorAdr   = MOINS_UN;
	memset(	NGF.ErrorLabel, 0, MAX_LABEL_SIZE );
	memset(	NGF.Descriptor, 0, MAX_LABEL_SIZE );
	return;
}

static	WORD	colon_check()
{
	if (( NGF.Colon )
	||  ( is_colon()))
		return((NGF.Colon = VRAI));
	else	return(FAUX);
}

static	WORD	flush_descriptors()
{
	WORD		i;
	WORD		phase;
	WORD		descriptor;
	WORD		d;
	BPTR		lparam;
	WORD		n=0;
	WORD		status=0;
	if ((NGF.ErrorFlag != MOINS_UN )
	&&  (NGF.Error     != (BPTR) 0))
		n=1;
	else	n=0;

	for ( i = 0; i < NGF.Parameters; i++, n++ ) {

		if ((lparam = NGF.Parameter[i]) == (BPTR) 0)
			return( syntax_error(3300) );
		
		/* Calculate descriptor access information */
		/* --------------------------------------- */
		phase = (n & 1);
		descriptor = (n/2);

		/* Indicate more parameters to follow */
		/* ---------------------------------- */
		if ( phase )
			NGF.Descriptor[descriptor]     |= 0x0010;
		else if ( descriptor )
			NGF.Descriptor[(descriptor-1)] |= 0x0001;

	
		}

	i = 0;		

	return(status);
}

static	WORD	flush_parameter(i)
WORD	i;
{
	BPTR	lparam;
	if ((lparam = NGF.Parameter[i]) == (BPTR) 0)
		return( syntax_error(3300) );
	else	generate_ngf_operand( lparam,i );
	return( 0 );
}

static	pre_flush_special()
{
	switch ( NGF.Operation ) {
		case	_NGF_LOAD	:
		case 	_NGF_DFILE	:
		case 	_NGF_ATB	:
			generate_ngf_special( NGF.Special,1 );
			break;
		}
}

static	VOID	post_flush_special()
{
	switch ( NGF.Operation ) {
		case	_NGF_SEARCH	: 
			NGF.Special >>= 4;
			NGF.Special = (( NGF.Special & 1 ? 1 : 0 ) | ( NGF.Special & 4 ? 2 : 0 ));
			generate_ngf_special( NGF.Special,1 );
			break;
		case	_NGF_DOWN	: 
		case	_NGF_UP		: 
			NGF.Special >>= 4;
		case 	_NGF_CFILE	:
		case 	_NGF_COUNT	:
		case	_NGF_POSIT	:
			generate_ngf_special( NGF.Special,1 );
			break;
		}
	return;
}

static	WORD	flush_parameters()
{
	WORD		i;
	WORD		status=0;
	WORD		specialx=0;
	open_rtlngf( rtlngf_names[ NGF.Operation ] );
	if ((status = flush_parameter(0)) == 0 ) {
		pre_flush_special();
		for ( i = 1; i < NGF.Parameters; i++ ) {
			if ((status = flush_parameter(i)) != 0)
				break;
			}
		post_flush_special();
		close_rtlngf();
		if ((NGF.ErrorFlag != MOINS_UN )
		&&  (NGF.Error     != (BPTR) 0)) {
			affect_rtl_status( NGF.Error );
			if ( NGF.ErrorFlag != 1 )
			test_rtl_status( NGF.ErrorLabel );
			}
		else	generate_rtl_raise();
		return(0);
		}
	return( syntax_error(3300) );
}

static	WORD	flush_error_trap()
{
	if ( NGF.ErrorAdr != MOINS_UN )
		return( dcl_implicite_label( NGF.ErrorAdr ) );
	else	return( 0 );
}

static	WORD	flush_ngf()
{
	WORD	status;
	trace("flush_ngf()\n");
	if ( NGF.Operation == MOINS_UN )
		return( syntax_error(3300) );
	if (((status = flush_descriptors())           == 0 )
	&&  ((status = flush_parameters())	      == 0 )
	&&  ((status = flush_error_trap())	      == 0 ))
		return( 0 );
	else	return( status );
}

static	WORD	start_ngf( operation )
WORD		operation;
{
	trace("start_ngf()\n");
	reset_ngf();
	NGF.Operation = operation;
	return(0);
}

static	WORD store_parameter( lparam )
BPTR    lparam;
{
	WORD	descriptor;
	WORD	phase;

	if ( NGF.Parameters >= 16 )
		return( 103 );

	/* And store Parameter Result */
	/* -------------------------- */
	if ( *lparam == '#' )
		lparam += 2;

	NGF.Parameter[NGF.Parameters++] = lparam;
	return(0);
}

static	WORD ngf_handle()
{
	BPTR	handle;
	trace("ngf_handle()\n");
	if (( is_equals() )
	&&  ((handle = IntegerExpression()) != (BPTR) 0))
		return( store_parameter( handle ) );
	else	return( syntax_error(3300) );
}

static	WORD	handle_is_zero()
{
	BPTR	rptr;
	if (((rptr = NGF.Parameter[(NGF.Parameters - 1)]) != (BPTR) 0)
	&&  ( *rptr == '0' ))
		return( VRAI );
	else	return( FAUX );	
} 

static	WORD	ngf_filename()
{
	BPTR	filename;
	trace("ngf_filename()\n");
	if (( is_comma() )
	&&  ((filename = StringExpression()) != (BPTR) 0))
		return( store_parameter( filename ) );
	else	return( syntax_error(3300) );
}

static	WORD	chain_option()
{
	BPTR	filename;
	trace("ngf_filename()\n");
	if ( is_comma() ) {
		if ((filename = StringExpression()) != (BPTR) 0)
			return( store_parameter( filename ) );
		else	return( syntax_error(3300) );
		}
	else	return( 0 );
}

static	WORD	assign_mnemonics()
{
	WORD	result=0;
	do	{
		if ( is_mnemonic("WR") )
			result |= _NGF_WR;
		else if ( is_mnemonic("EX") )
			result |= _NGF_EX;
		else if ( is_mnemonic("C") )
			result |= _NGF_C;
		else if ( is_mnemonic("DF") )
			result |= _NGF_DF;
		else if ( is_mnemonic("WO") )
			result |= (_NGF_DF | _NGF_WR);
		else if ( is_mnemonic("SQ") )
			result |= _NGF_SQ;
		else if ( is_mnemonic("SI") )
			result |= _NGF_SI;
		else if ( is_mnemonic("MC") )
			result |= _NGF_MC;
		else if ( is_mnemonic("DB") )
			result |= _NGF_DB;
		else if ( is_mnemonic("DBF") )
			result |= _NGF_DBF;
		else if ( is_mnemonic("DV") )
			result |= _NGF_DV;
		else if ( is_mnemonic("GR") )
			result |= _NGF_GR;
		else if ( is_mnemonic("IM") )
			result |= _NGF_IM;
		else if ( is_mnemonic("IPC") )
			result |= _NGF_IPC;
		else	{
			(void) syntax_error(3300);
			return( result );
			}
		}
	while ( is_comma() );
	return( result );
}

static	WORD	ngf_assign_options()
{
	BPTR	options;
	trace("ngf_assign_options()\n");
	if ( is_comma() ) {
		if (( OtrOption.Enhanced & _ENHANCED_ASSIGN )
		&&  ( is_left_brace()    )) {
			options = TypedExpression(1);
			if (!(is_right_brace()))
				return( unmatched_braces() );
			}
		else	options = IntegerResult( assign_mnemonics() );
		}
	else	options = IntegerResult(0);
	if ( options != (BPTR) 0)
		return( store_parameter( options ) );
	else	return( syntax_error(3300) );
}

static	WORD	sf_options()
{
	BPTR	options;
	trace("sf_options()\n");
	if ( is_comma() )
		options = TypedExpression(1);
	else	options = IntegerResult( (NGF.Operation == _NGF_READ ? _SQ_READ : _SQ_WRITE ) );
	if ( options != (BPTR) 0)
		return( store_parameter( options ) );
	else	return( syntax_error(3300) );
}

static	BPTR	ngf_sector( sector )
WORD	sector;
{
	BPTR	options;
	trace("ngf_sector()\n");
	if ( is_comma() )
		return( IntegerExpression() );
	else	return( IntegerResult( sector ) );

}

WORD	ngf_explicite_label()
{
	if ( get_token() ) {
		NGF.ErrorFlag = 0;
		strcpy(NGF.ErrorLabel,TokenBuffer);
		if ( is_comma() )
			return(0);
		}
	return( syntax_error(3300) );
}

WORD	ngf_implicite_label(nature)
WORD	nature;
{
	NGF.ErrorFlag = nature;
	if ( is_comma() )
		return( 0 );
	else	return( syntax_error(3300) );
}

WORD	is_mnemonic_next()
{
	return( is_mnemonic("NEXT") );
}

WORD	is_mnemonic_break()
{
	return( is_mnemonic("BREAK") );
}


WORD	is_mnemonic_label()
{
	if (is_mnemonic_next())
		return(1);
	else if (is_mnemonic_break())
		return(2);
	else	return(FAUX );
}

static	WORD	ngf_error_trap()
{
	WORD	status=0;
	WORD	varlen;
	trace("ngf_error_trap()\n");
	if ( colon_check() ) {
		if ((status = is_ampersand()) != FAUX ) {  
			unget_byte();
			if (ngf_explicite_label() != 0)
				return( syntax_error(3300) );
			}
		else if ((status = is_mnemonic_label()) != FAUX) {
			if ( ngf_implicite_label(status) != 0 )
				return( syntax_error(3300) );
			}
		if (( status )
		&&  ((NGF.Error = VariableExpression((WPTR) & varlen)) == (BPTR) 0)) {
			trace("incorrect_error_variable_expression()\n");
			return(syntax_error(3300));
			}
		}
	return(0);
}

BPTR	ngf_data_size()
{
	BPTR	rptr=(BPTR) 0;
	if ( remove_white_space() ) {
		if ( is_mnemonic("VD") )
			NGF.Special |= _ISAM_VD;
		else if (!(is_mnemonic("D"))) {
	  		(void) syntax_error(3300);
			return( rptr );
			}
		if ( is_equals() )
			rptr = IntegerExpression();
		else	rptr = IntegerResult(256);
		}
	return( rptr );
}

BPTR	ngf_index_size()
{
	BPTR	rptr=(BPTR) 0;
	if ( remove_white_space() ) {
		if ( is_mnemonic("LK") )
			NGF.Special |= _ISAM_LK;
		else if ( is_mnemonic("RK") )
			NGF.Special |= _ISAM_RK;
		else if (!(is_mnemonic("K"))) {
	  		(void) syntax_error(3300);
			return( rptr );
			}
		if ( is_equals() )
			rptr = IntegerExpression();
		else	rptr = IntegerResult(16);
		}
	return( rptr );
}

static	WORD	ngf_sizes()
{
	WORD	status;
	if (!( is_comma() ))
		return(0);
	if ((status = store_parameter( ngf_data_size() )) != 0)
		return( status );
	if (!( is_comma() ))
		return(0);
	else	return( store_parameter( ngf_index_size() ) );
}

static	WORD	ngf_length(l)
WORD	l;
{
	BPTR	length;
	trace("ngf_length()\n");
	if ( is_comma() ) {
		if ((length = IntegerExpression()) == (BPTR) 0)
			return( syntax_error(3300) );
		else	return( store_parameter( length ) );
		}	
	else	return(store_parameter( IntegerResult( l ) ) );
}

static	WORD	ngf_buffer()
{
	BPTR		buffer;
	WORD		status;
	TCVARPTR	vptr;
	WORD		l;
	WORD	varlen=0;
	trace("ngf_buffer()\n");
	if (( NGF.Error != (BPTR) 0)
	&&  (!( is_comma() ))) {
		if ((status = store_parameter( "(BPTR) 0" )) != 0)
			return( status );
		return( ngf_length(varlen) );
		}
	if ((buffer = VariableExpression((WPTR) & varlen)) == (BPTR) 0) {
		buffer = (BPTR) "(BPTR) 0";
		varlen = 0;
		}
	if ((status = store_parameter( buffer )) != 0)
		return( status );
	return( ngf_length(varlen) );
}


static	WORD	load_options(opcode)
WORD	opcode;
{
	BPTR	rptr;
	trace("load_options()\n");
	if (( opcode == _NGF_LOAD )
	&&  ( is_comma() 	  )) {
		if ( is_left_brace() ) {
			remove_white_space();
			switch ( get_byte() ) {
				case 'R' :
				case 'r' :
					NGF.Special = 1;
					break;
				default	 :
					return( syntax_error(3300) );
				}
			if (!( is_right_brace() ))
				return( unmatched_braces() );
			}
		else	return( syntax_error(3300) );
		}
	return( 0 );
}

static	WORD	find_options()
{
	BPTR	rptr;
	trace("find_options()\n");
	if ( is_comma() ) {
		if ( is_left_brace() ) {
			if ( is_left_brace() ) {
				if ((rptr = StringExpression()) == (BPTR) 0)
					return( syntax_error(3300) );
				if (!(is_right_brace()))
					return( unmatched_braces() );
				}
			else 	{
				if (!( get_token() ))
					return( syntax_error(3300) );
				rptr = rtlstring_constant( TokenBuffer );
				}
			if (!(is_right_brace()))
				return( unmatched_braces() );
			else	return( store_parameter( rptr ) );

			}
		else	return( syntax_error(3300) );
		}
	return(store_parameter( rtlstring_constant(" ") ) );
}


/*	--------------------------------------------------------	*/
/*	TRANSLATION of INDIVIDUAL and GROUPED  NGF  INSTRUCTIONS	*/
/*	--------------------------------------------------------	*/

WORD	translate_assign(operation)
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation ))	== 0 )
	&&  ((status = ngf_handle())		== 0 )
	&&  ((status = ngf_filename())		== 0 )
	&&  ((status = ngf_assign_options())	== 0 )
	&&  ((status = ngf_error_trap())	== 0 )
	&&  ((status = ngf_buffer())		== 0 )
	&&  ((status = store_parameter("0"))    == 0 ))
		return( flush_ngf() );
	else	return( status      );
}

WORD	translate_load_chain(operation)
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation ))	== 0 )
	&&  ((status = ngf_handle())		== 0 )
	&&  ((status = chain_option())		== 0 )
	&&  ((status = load_options(operation))	== 0 )
	&&  ((status = ngf_error_trap())	== 0 ))
		return( flush_ngf() );
	else	return( status      );
}

WORD	translate_find(operation)
WORD	operation;
{
	WORD	status;
	trace("translate_find()\n");
	if (((status = start_ngf( operation ))	== 0 )
	&&  ((status = ngf_handle())		== 0 )
	&&  ((status = find_options())		== 0 )
	&&  ((status = ngf_error_trap())	== 0 )
	&&  ((status = ngf_buffer())		== 0 ))
		return( flush_ngf() );
	else	return( status      );
}

WORD	translate_cfile(operation)
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation ))	== 0 )
	&&  ((status = ngf_handle())		== 0 )
	&&  ((status = ngf_sizes())		== 0 )
	&&  ((status = ngf_error_trap())	== 0 ))
		return( flush_ngf() );
	else	return( status      );
}

WORD	translate_dfile(operation)
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation )) == 0 )
	&&  ((status = ngf_handle())           == 0 )
	&&  ((status = ngf_error_trap())       == 0 ))
		return( flush_ngf() );
	else	return( status      );
}

WORD	translate_rename(operation)
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation )) == 0 )
	&&  ((status = ngf_handle())           == 0 )
	&&  ((status = ngf_filename())         == 0 )
	&&  ((status = ngf_error_trap())       == 0 ))
		return( flush_ngf() );
	else	return( status      );
}

WORD	translate_open_close(operation)
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation )) == 0 )
	&&  ((status = ngf_handle())           == 0 )
	&&  ((status = ngf_error_trap())       == 0 ))
		return( flush_ngf() );
	else	return( status      );
}

BPTR	long_ngf_sector( sector )
BPTR	sector;
{
	BPTR	tptr;
	if ((tptr = allocate_for_tnode(strlen(sector)+16)) != (TNODEPTR) 0)
		sprintf(tptr,"(LONG)(%s)",sector);
	return( tptr );
}

WORD	translate_read_write(operation)
WORD	operation;
{
	WORD		status;
	BPTR		sector;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )) {
		if (handle_is_zero())
			return( translate_read_data() );
		else 	if (((status = sf_options())		== 0 )
			&&  ((sector = ngf_sector(0)) != (BPTR) 0    )
			&&  ((sector = long_ngf_sector(sector)) != (BPTR) 0)
			&&  ((status = store_parameter(sector))	== 0 )
			&&  ((status = ngf_error_trap())       	== 0 )
			&&  ((status = ngf_buffer())		== 0 ))
				return( flush_ngf() );
			else	return( status      );
		}
	else	return( status      );

}

/*	------------------------------------	*/
/*	TRANSLATION of I.S.A.M	Instructions	*/
/*	------------------------------------	*/
static	WORD	updown_postfix()
{
	if (( is_period() )
	&&  ( remove_white_space() )) {
		if ( is_mnemonic("M") )
			NGF.Special |= _ISAM_M;
		else if ( is_mnemonic("L") )
			NGF.Special |= _ISAM_L;
		else if ( is_mnemonic("ML") )
			NGF.Special |= _ISAM_ML;
		else	return( syntax_error(3300) );
		}
	return( 0 );

}

static	WORD	search_postfix()
{
	if (( is_period() )
	&&  ( remove_white_space() )) {
		if ( is_mnemonic("M") )
			NGF.Special |= _ISAM_SM;
		else if ( is_mnemonic("L") )
			NGF.Special |= _ISAM_SL;
		else if ( is_mnemonic("ML") )
			NGF.Special |= _ISAM_SML;
		else	return( syntax_error(3300) );
		}
	return( 0 );
}

static	WORD	isam_primary_index()
{
	WORD	status;
	if (( NGF.Operation != _NGF_UP   )
	&&  ( NGF.Operation != _NGF_DOWN )) {
		if (!( is_comma()))
			return( syntax_error(3300) );
		if ((status = store_parameter( StringExpression() )) != 0)
			return( status );
		else	NGF.Special |= _ISAM_PI;
		}
	if ( is_comma() ) {
		if ((status = store_parameter( IntegerExpression() )) != 0)
			return( status );
		else	NGF.Special |= _ISAM_MQ;
		}
	return(0);
}

static	WORD	isam_data_record()
{
	WORD	status=0;
	WORD	varlen=0;
	if ( NGF.Operation != _NGF_DELETE ) {
		if ((!( is_comma()    ))
		&&  (!( colon_check() )))
			return( syntax_error(3300) );
		if ((status = store_parameter( VariableExpression((WPTR) & varlen) )) != 0)
			return( status );
		else	NGF.Special |= _ISAM_DR;
		if ( is_comma() ) {
			if ((status = store_parameter( IntegerExpression() )) == 0)
				NGF.Special |= _ISAM_DL;
			}
		else if ((status = store_parameter( IntegerResult(varlen)  )) == 0)
			NGF.Special |= _ISAM_DL;
		}
	return(status);
}

static	WORD	translate_isam()
{
	WORD	status;
	if (((status = ngf_handle())           	== 0 )
	&&  ((status = isam_primary_index()) 	== 0 )
	&&  ((status = ngf_error_trap())       	== 0 )
	&&  ((status = isam_data_record())	== 0 ))
		return( flush_ngf() );
	else	return( status      );
}

static	WORD	translate_insert( operation )
WORD	operation;
{
	WORD	status;
	if ((status = start_ngf( operation )) 	== 0 )
		return( translate_isam() );
	else	return( status );
}

static	WORD	translate_search( operation )
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = search_postfix())	== 0 ))
		return( translate_isam() );
	else	return( status );
}

static	WORD	translate_up_down( operation )
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = updown_postfix())	== 0 ))
		return( translate_isam() );
	else	return( status );
}

/*	--------------------------------------	*/
/*	TRANSLATION of M.I.S.A.M  Instructions	*/
/*	--------------------------------------	*/
WORD	ngf_operand()
{
	if (!(is_comma()))
		return(30);
	else 	return( store_parameter( EvaluateExpression() ) );
}

WORD	ngf_string_operand()
{
	if (!(is_comma()))
		return( store_parameter( "(BPTR) 0,0" ) );
	else 	return( store_parameter( StringExpression() ) );
}

WORD	ngf_void_string()
{
	return( store_parameter( "(BPTR) 0, 0" ) );
}

WORD	key_type()
{
	if (!(is_comma())) 
		return( store_parameter( IntegerResult( 3 ) ) );
	else if ( is_mnemonic( "A" ) )
		return( store_parameter( IntegerResult( 3 ) ) );
	else if ( is_mnemonic( "B" ) )
		return( store_parameter( IntegerResult( 2 ) ) );
	else if ( is_mnemonic( "N" ) )
		return( store_parameter( IntegerResult( 1 ) ) );
	else	return( store_parameter( EvaluateExpression() ) );
}

WORD	translate_key( operation )
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )) {
		switch ( operation ) {
			case _NGF_KEY :
				if ((status = ngf_operand()) != 0)
					return( syntax_error(3300) );
				else if ((status = ngf_operand()) != 0)
					return( syntax_error(3300) );
				else if ((status = key_type()) != 0 )
					return( syntax_error(3300) );
				while ( ngf_operand() == 0 );
				break;

			case _NGF_NKEY :
				if ((status = ngf_operand()) != 0)
					return( syntax_error(3300) );
				else if ((status = ngf_operand()) != 0)
					return( syntax_error(3300) );
				else	break;

			case _NGF_FKEY :
				if (((status = ngf_string_operand()) != 0 )
				&&  ((status = ngf_void_string()) != 0    ))
					return( status );
				else	break;
			default		:
				return( syntax_error(3300) );
			}
		if ((status = ngf_error_trap())       	== 0 )
			return( flush_ngf() );
		}
	return( status      );
}

WORD	collect_possible_jointure(mode)
WORD	mode;
{
	WORD	status;
	if ( is_left_brace() ) {
		if ((status = store_parameter( StringExpression() )) != 0 )
			return( status );
		else if (!( is_right_brace()))
			return( unmatched_braces() );
		}
	else if ( mode ) {
		/* Called from LINK and CLINK : Requires dummy Jointure */
		/* ---------------------------------------------------- */
		if ((status = store_parameter( IntegerResult(0) )) != 0)
			return( status );
		}
	return( 0 );
}

BPTR	possible_jointure()
{
	WORD	status;
	BPTR	jptr;
	if ( is_left_brace() ) {
		jptr = StringExpression();
		if (!( is_right_brace()))
			jptr = "<unmatched_braces>,0";
		}
	else	jptr = "(BPTR) 0,0";
	return(jptr );
}

WORD	translate_join( operation )
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = collect_possible_jointure(0)) == 0 )) {
		switch ( operation ) {
			case _NGF_RJOIN :
				if (!(is_comma()))
					return( syntax_error(3300) );
				else if  ((status = collect_possible_jointure(0)) != 0 )
					return( status );
				else	break;
			case _NGF_DJOIN	:
			case _NGF_CJOIN	:
				break;
			case _NGF_JOIN	:
				if ((status = ngf_operand()) != 0)
					return( status );
				else	break;

			default		:
				return( syntax_error(3300) );
			}
		if ((status = ngf_error_trap()) == 0 )
			return( flush_ngf() );
		else	return( status );
		}
	else	return( status      );
}

WORD	translate_list( operation )
WORD	operation;
{
	WORD	status;
	BPTR	buffer;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = find_options())		== 0 )
	&&  ((status = ngf_error_trap())       	== 0 )
	&&  ((status = ngf_buffer())            == 0 ))
		return( flush_ngf() );
	else	return( status      );
}

WORD	link_option()
{
	WORD	status;
	if (is_comma()) {
		trace("link_option()\n");
		if  (is_left_brace()) {
			if ( is_left_brace() ) {
				if ((status = store_parameter( StringExpression() )) != 0)
					return( status );
				else if (!(is_right_brace()))
					return( unmatched_braces() );
				}
			else	{
				if ( is_mnemonic( "A" ) ) {
					if ((status = store_parameter(rtlstring_constant("A"))) != 0)
						return( status );
					}
				else if ( is_mnemonic( "D" ) ) {
					if ((status = store_parameter(rtlstring_constant("D"))) != 0)
						return( status );
					}
				else	return( syntax_error(3300) );
				}
			if (!(is_right_brace()))
				return( unmatched_braces() );
			else	return( 0 );
			}
		else	return( store_parameter( StringExpression() ) );
		}
	else	return( store_parameter( rtlstring_constant(" ") ) );
}


WORD	translate_link( operation )
WORD	operation;
{
	WORD	status;
	BPTR	jptr;
	trace("translate_link()\n");
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )) {
		jptr = possible_jointure();
		if ((status = ngf_string_operand()) == 0)
			if ((status = link_option()) != 0)
				return( status );
		if ((status = store_parameter( jptr )) != 0 )
			return( status );
		if ((status = ngf_error_trap()) == 0 )
			return( flush_ngf() );
		}
	return( status      );
}

WORD	posit_option()
{
	if ( is_period() ) {
		if ( is_mnemonic("D") )
			NGF.Special = 1;
		else	return( syntax_error(3300) );
		}
	return( 0 );
}

BPTR	question_jointure()
{
	WORD	status;
	BPTR	jptr="(BPTR) 0,0";
	if ( is_left_brace() ) {
		jptr = StringExpression();
		if (!(is_right_brace()))
			jptr = "<unmatched_braces>,0";
		}
	return( jptr );
}

BPTR	question_option()
{
	WORD		status;
	BPTR		rptr;
	if (is_comma()) {
		trace("question_option()\n");
		if  (is_left_brace()) {
			if ( is_left_brace() ) {
				if ((rptr = StringExpression()) == 0)
					return( rptr );
				else if (!(is_right_brace()))
					return((BPTR) 0);
				}
			else	{
				if ( is_mnemonic( "U" ) )
					rptr = rtlstring_constant("U");
				else if ( is_mnemonic( "S" ) )
					rptr = rtlstring_constant("S");
				else	rptr = rtlstring_constant(" ");
				}
			if (!(is_right_brace()))
				return("<unmatched_braces>,0");
			else	return( rptr );
			}
		else	return( StringExpression() );
		}
	else	return( rtlstring_constant(" ") );
}
	
WORD	question_target()
{
	WORD	varlen=0;
	WORD	status;
	(void) is_comma();
	if ((status = store_parameter(VariableExpression((WPTR) & varlen))) != 0)
		return( status  );
	else	return( store_parameter( IntegerResult( varlen ) ) );
}

WORD	translate_question( operation )
WORD	operation;
{
	WORD		status;
	BPTR		qptr;
	BPTR		jptr;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = posit_option())		== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((jptr   = question_jointure()) != (BPTR) 0 )
	&&  ((status = ngf_string_operand())	== 0 )
	&&  ((qptr   = question_option()) != (BPTR)0 )
	&&  ((status = store_parameter(qptr))   == 0 )
	&&  ((status = ngf_error_trap())       	== 0 )
	&&  ((status = question_target())       == 0 )
	&&  ((status = store_parameter(jptr))   == 0 ))
		return( flush_ngf() );
	else	return( status      );
}

WORD	atb_options()
{
	NGF.Special = 0;
	while ( 1 ) {
		if (!( is_comma() ))
			return( 0 );
		else if ( is_mnemonic( "EX" ) )
			NGF.Special |= 1;
		else if ( is_mnemonic( "C"  ) )
			NGF.Special |= 2;
		else	return( syntax_error(3300) );
		}
}

WORD	translate_divers( operation )
WORD	operation;
{
	WORD		status;
	BPTR		sector;
	if (((status = start_ngf( operation )) == 0 )
	&&  ((status = ngf_handle())           == 0 )) {
		switch ( NGF.Operation ) {

			case _NGF_EXTEND :
				if (((sector = ngf_sector(16)) != (BPTR) 0 )
				&&  ((status = store_parameter(sector))	== 0 ))
					break;
				else	return( status );

			case _NGF_ATB	 :
				if ((status = atb_options()) != 0)
					return( status );
				else	break;

			}

		if ((status = ngf_error_trap()) == 0 ) {
	
			switch ( NGF.Operation ) {
				case	_NGF_STATS 	: 
				case	_NGF_NAME  	: 
				case	_NGF_RECORD	: 
					if ((status = isam_data_record()) != 0 )
						return( status );
				}

			return( flush_ngf() );

			}
		}
	return( status      );
}

WORD	translate_ngf()
{
	WORD	type;

	switch ((type = is_ngf_keyword( TokenBuffer ))) {
		case	_NGF_CFILE		: 
			return(translate_cfile(type));
		case	_NGF_DFILE 		: 
			return(translate_dfile(type));
		case	_NGF_RENAME		: 
			return(translate_rename(type));
		case	_NGF_OPEN		: 
		case	_NGF_CLOSE		: 
			return(translate_open_close(type));
		case	_NGF_READ		: 
		case	_NGF_WRITE		: 
			return(translate_read_write(type));
		case	_NGF_FILE		: 
		case	_NGF_ASSIGN		: 
			return(translate_assign(type));
		case	_NGF_FIND		: 
			return( translate_find( type ) );
		case	_NGF_LOAD		: 
			if ((!( is_period() ))
			||  (!( is_mnemonic("GO") )))
				return( syntax_error(3300) );
		case	_NGF_CHAIN		: 
			return( translate_load_chain( type ) );
		case	_NGF_CKEY		: 
		case	_NGF_RKEY		: 
		case	_NGF_STATS		: 
		case	_NGF_RECORD		: 
		case	_NGF_BACKSPACE		: 
		case	_NGF_NAME		: 
		case	_NGF_XCRI		: 
		case	_NGF_ATB		: 
		case	_NGF_EXTEND		: 
			return( translate_divers( type ) );
		case	_NGF_INSERT		: 
		case	_NGF_MODIFY		: 
		case	_NGF_DELETE		:
			return( translate_insert(type) );
		case	_NGF_SEARCH		: 
			return( translate_search(type) );
		case	_NGF_DOWN		: 
		case	_NGF_UP  		: 
			return( translate_up_down(type) );
		case	_NGF_KEY		: 
		case	_NGF_FKEY		: 
		case	_NGF_NKEY		: 
			return( translate_key(type) );
		case	_NGF_LINK		: 
		case	_NGF_CLINK		: 
			return( translate_link(type) );
		case	_NGF_POSIT		: 
		case	_NGF_COUNT		: 
			return( translate_question(type) );
		case	_NGF_JOIN		: 
		case	_NGF_CJOIN		: 
		case	_NGF_DJOIN		: 
		case	_NGF_RJOIN		: 
			return( translate_join( type ) );
		case	_NGF_LFILE		: 
		case	_NGF_LJOIN		: 
		case	_NGF_LKEY		: 
		case	_NGF_LLINK		: 
			return(translate_list(type));
		default 			:
			return( MOINS_UN );
		}

}

#endif	/* _TRNGF_C */
	/* -------- */

