#define	DEBUG
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRPROC.C				*/
/*		Version :	2.1d					*/
/*		Date	:	16/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRPROC_C
#define	_TRPROC_C

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
#include "triter.h"
#include "trclf.h"
#include "trproc.h"
#include "trdebug.h"
#include "trtables.h"
#include "trclass.h"
#include "trecho.h"

struct	abal_extern_call	{
	TCVARPTR	variable;
	WORD		current;
	WORD		limit;
	} ExternCall = { (TCVARPTR) 0, 0, 0 };

WORD	extern_call_end()
{
	ExternCall.variable = (TCVARPTR) 0;
	ExternCall.current  = 0;
	ExternCall.limit    = 0;
	return(0);	
}

#include "tcproc.c"

/*
 *	[ EXTERN | FORWARD ]
 *
 *	PROC <name> [ ( [ <parameter_list> ] ) ] [ : <return_type> ] [,D]
 *
 */

WORD	analyse_tcode_proc_parameter( vptr, mode )
TCVARPTR	vptr;
WORD		mode;	/* 0 : Normal, 1 : Allows Macro Code Syntax (ident) */
{
	SYMBOLPTR	sptr=(SYMBOLPTR) 0;
	TCVARPTR	likeptr=(TCVARPTR) 0;
	BPTR		name=(BPTR) 0;
	WORD		nature=0;
	WORD		first_dim=1;
	WORD		second_dim=1;
	WORD		type=0;
	WORD		ucsmode=0;
	WORD		length=8;
	WORD		l;
	WORD		status=0;
	WORD		basic_type=MOINS_UN;

	if (( mode != 0       )
	&&  ( is_left_brace() ))
		type = MOINS_UN;

	else 	{
		if ( is_mnemonic( "CONST"   ) )
			vptr->access &= ~_TYPE_WRITABLE;
 
		if ( is_mnemonic( "POINTER" ) )
			type |= 0x9008;
		}

	if (!( get_token() ))
		return( syntax_error(4002) );

	if (!( type )) {
		if ((l = is_level1_keyword()) ==  _KW1_PTR) {
			if (!( get_token() ))
				return( syntax_error(4002) );
			type = 0x9008;
			}
		else	type = 8;
		}

	switch 	((nature = is_dcl_keyword())) {

		case _DCL_PROC	:	
		case _DCL_SEGM  :
		case _DCL_USER  :
		case _DCL_CODE  :
			if ((mode) && ( type == MOINS_UN))
				return( syntax_error( 4026 ) );
			if (!( get_token() ))
				return( syntax_error(4002) );
			else	break;

		case MOINS_UN   :

			switch ((ucsmode = is_level1_keyword())) {
				case _KW1_CLASS  :
				case _KW1_UNION  :
				case _KW1_STRUCT :
					if ((mode) && ( type == MOINS_UN ))
						return( syntax_error( 4028 ) );
					else	return( translate_struct_parameter( vptr, type, ucsmode ) );

				case MOINS_UN	 :
					if ((mode) && ( type == MOINS_UN ))
						break;
					else if ((status = implicite_struct_parameter( vptr, type )) != MOINS_UN)
						return( status );
					break;
				default		 :
					return( syntax_error(4004) );
				}

			break;
		default		:
			return( syntax_error(4005) );
		}

#ifdef	_BEFORE16102001
	if ((l = strlen(TokenBuffer)) > 0)
		l--;
	else	return( syntax_error(4006) );
#endif

	if (!(type & _TYPE_DEFINED)) {

		switch ((basic_type = analyse_basic_type())) {

			case	0	 :
				return( syntax_error( 4005 ) );

			case	MOINS_UN :


#ifdef	_BEFORE16102001
				switch( TokenBuffer[l] ) {

					case '%' : basic_type = _TYPE_INT16;
						   TokenBuffer[l] = 0; 
						   break;

					case '#' : basic_type = _TYPE_INT8;
						   TokenBuffer[l] = 0; 
						   break;

					case '$' : basic_type = _TYPE_STRING;
						   length = 15;
						   TokenBuffer[l] = 0; 
						   break;

					default  : basic_type = _TYPE_NUMERIC;
						   length = 8;
					}
#else	/* _SINCE_15102001 */
				if ( is_dieze() ) 
					basic_type = _TYPE_INT8;
				else if ( is_percent() ) 
					basic_type = _TYPE_INT16;
				else if ( is_colon() ) 
					basic_type = _TYPE_INT32;
				else if ( is_dollar() ) {
					basic_type = _TYPE_STRING;
					length = 15;
					}
				else	{
					basic_type = _TYPE_NUMERIC;
					length = 8;
					}
#endif
				if ( is_mnemonic( "LIKE"   ) ) {

					if ((vptr->name = allocate_for_token( TokenBuffer )) == (BPTR) 0)
						return( allocation_failure() );

					vptr->hash = keyword_hash( TokenBuffer );

					if (!( get_token() ))
						return( syntax_error( 4002 ) );
					else if (!( sptr = is_symbol( TokenBuffer ) ))
						return( syntax_error( 4002 ) );
					else if  ((sptr->type & SYMBOL_TYPE) != SYMBOL_VARB)
						return( syntax_error( 4002 ) );
					else if (!(likeptr = sptr->contents))
						return( syntax_error( 4002 ) );

					}
				break;
			default	:
				if (!( get_token() ))
					return( syntax_error( 4002 ) );
#ifdef	_BEFORE_16102001
#else
				/* Basic Named types must not have type modifier */
				if (( is_dieze()   ) 
				||  ( is_percent() ) 
				||  ( is_colon()   ) 
				||  ( is_dollar()  ))
					return( syntax_error(4006) );
#endif
			}

		type |= basic_type;
			
		}
#ifdef	_BEFORE_16102001
#else
	else	{
		/* Structured types, must not have type modifier */
		if (( is_dieze()   ) 
		||  ( is_percent() ) 
		||  ( is_dollar()  ))
			return( syntax_error(4006) );
		}
#endif

	if (!( likeptr )) {

		if ((vptr->name = allocate_for_token( TokenBuffer )) == (BPTR) 0)
			return( allocation_failure() );
		else	vptr->hash = keyword_hash( TokenBuffer );

		if (!( type & _TYPE_DEFINED )) {
			/*IJM : IMPORTANT CORRECTION 32B : 12/7/2006 */
			/* ----------------------------------------- */
			switch (( type & _TYPE_BASIC )) {
				case	_TYPE_STRING	:
				case	_TYPE_NUMERIC	: 
				if ( is_equals() ) {
					if ( nature == MOINS_UN ) {
						if ((length = integer_expression()) == 0)
							return( syntax_error( 788 ));
						} 
					else	return( syntax_error(4007) );
					}
					break;
				case	_TYPE_INT8	:
					length = 1; break;
				case	_TYPE_INT16	:
					length = 2; break;
				case	_TYPE_INT32	:
					length = 4; break;
				default			:
					length = 0; break;
				}
			}
		
		if ( nature != MOINS_UN ) {
			type = ((type & 0xFFFC) | 3);
			length = 5;
			}

		if ((vptr->type = allocate_for_type( type, length, first_dim, second_dim, (VPTR) 0 )) == (TCTYPPTR) 0)
			return( allocation_failure() );

		}
	else if ((vptr->type = allocate_for_type( 
			((likeptr->type->type & 0x00FF) | (type & 0x9008)), 
			likeptr->type->size, 
			likeptr->type->first,
			likeptr->type->second,
			likeptr->type->class )) == (TCTYPPTR) 0)
		return( allocation_failure() );


	if (( mode != 0        )
	&&  ( type == MOINS_UN )) {
		if (!( is_right_brace() ))
			return( unmatched_braces() );
		else	return( 0 );
		}
	/* Dimensions not allowed (why not) */
	/*----------------------------------*/
	else if ( is_left_brace() )
		return( syntax_error(4008) );
 	else	return( 0 );
}

TCVARPTR	collect_typed_parameters(mode)
WORD		mode;		/* 0 : Standard Abal Procedure	*/
				/* 1 : Enhanced Inline Method	*/
{
	WORD		status;
	TCVARPTR	rptr=(TCVARPTR) 0;
	TCVARPTR	vptr=(TCVARPTR) 0;
	TCVARPTR	lptr=(TCVARPTR) 0;

	trace("collect_typed_parameters()\n");

	if ((  is_left_brace()  ) 
	&&  (!(is_right_brace()))) {
		do 	{
			if ((vptr = allocate_for_variable()) == (TCVARPTR) 0) {
				(void) allocation_failure();
				break;
				}
			if ((status = analyse_tcode_proc_parameter( vptr, mode )) != 0) {
				liberate_parameter_variable( vptr );
				break;
				}
			/* Check for explicite Return value */
			if ( is_question() )
				vptr->access |= _TYPE_QUESTION;
			/* Check for variable argument count */
			if ( is_period() )
				vptr->type->type = _TYPE_BASIC; /* &= MOINS_UN; */
				
			if ( lptr != (TCVARPTR) 0)
				lptr->next = vptr;
			else	rptr 	   = vptr;
			lptr = vptr;
			}
		while ( is_comma() );
		if (!(is_right_brace()))
			(void) unmatched_braces();
		}
	return( rptr );
}


WORD	procedure_parameters(pptr)
TCPRCPTR	pptr;
{
	trace( "procedure_parameters()\n" );
	pptr->parameter = collect_typed_parameters(0);
	return(0);
}

WORD	procedure_type( pptr )
TCPRCPTR	pptr;
{
	if ( pptr != (TCPRCPTR) 0 ) {
		switch ( pptr->options & _DTYPE_PROC ) {
			case _INT8_PROC 	: return(0);
			case _INT16_PROC 	: return(1);
			case _NUMERIC_PROC 	: return(2);
			case _STRING_PROC 	: return(3);
			}
		}
	return( MOINS_UN );
}

WORD	analyse_procedure_type(pptr)
TCPRCPTR	pptr;
{
	WORD		c;
	WORD		l;
	WORD		status;
	WORD		type=0;
	WORD		size=0;
	TCTYPPTR	tptr=(TCTYPPTR) 0;

	while ( 1 ) {

		if (!( remove_white_space() ))
			return( syntax_error(4009) );

		switch ((c = get_byte())) {
			case '#' :
				size = 1;
				pptr->options |= _INT8_PROC;
				break;
			case '%' :
				type |= 1;
				size =  2;
				pptr->options |= _INT16_PROC;
				break;
#ifdef	otr32
			case ':' :
				type |= 5;
				size =  4;
				pptr->options |= _INT32_PROC;
				break;
#endif
			case '$' :
				type |= 3;
				pptr->options |= _STRING_PROC;
				if ( is_equals() )
					size = integer_expression();
				else if (!(size = integer_expression()))
				 	size = 15;
				break;
			case '=' :
				type |= 2;
				pptr->options |= _NUMERIC_PROC;
				size = integer_expression();
				break;
			case '*' :
				type |= 2;
				pptr->options |= _NUMERIC_PROC;
				size = 12;
				break;

			default	 :
				unget_byte();
				if (( c >= '0' )
				&&  ( c <= '9' )) {
					type |= 2;
					pptr->options |= _NUMERIC_PROC;
					size = integer_expression();
					break;
					}
				else if (!( get_token() )) 
					return( syntax_error(4010) );
				switch (((l = is_level1_keyword() ))) {
					case _KW1_STRUCT  :
					case _KW1_UNION   :
					case _KW1_CLASS   :
						type |= 0x0013;
						pptr->options |= _STRING_PROC;
						if (!( get_token() )) 
							return( syntax_error(4011) );
						else if ((status = verify_structure_type( l, TokenBuffer )) != 0)
							return( status );
						else	break;
	
					case _KW1_PTR	  :
						type |= _TYPE_POINTER;
						pptr->options |= _PTR_PROC;
						continue;
					case _KW1_PROC    :
						type |= 0x0003;
						size  = 5;
						pptr->options |= _PROC_PROC;
						break;
					case _KW1_SEGMENT :
						type |= 0x0003;
						size  = 5;
						pptr->options |= _SEGM_PROC;
						break;
					case MOINS_UN     :
						switch 	((l = is_dcl_keyword())) {
							case _DCL_PROC	:	
								type |= 3;
								size  = 5;
								pptr->options |= _PROC_PROC;
									break;
							case _DCL_SEGM  :
								type |= 3;
								size  = 5;
								pptr->options |= _SEGM_PROC;
								break;
							case _DCL_USER  :
								pptr->options |= _USER_PROC;
								break;
							case _DCL_CODE  :
								pptr->options |= _CODE_PROC;
								break;
							default		:
								return( syntax_error(4012) );
							}
						break;
					default		  :
						return(syntax_error(4012));
					}
			}
		break;
		}

	if ((tptr = allocate_for_type( type, size, 1, 1, tptr )) == (TCTYPPTR) 0)
		return( allocation_failure() );
	else	{
		pptr->result = tptr;
		return( 0 );
		}
}

WORD	procedure_return_type(pptr)
TCPRCPTR	pptr;
{
	trace( "procedure_return_type()\n" );

	if ( is_colon() )
		return( analyse_procedure_type( pptr ) );
	else	return( 0 );
}

WORD	procedure_options(pptr,mode)
TCPRCPTR	pptr;
WORD		mode;
{
	WORD	c;
	trace( "procedure_options()\n" );
	if (( is_comma() )
	&&  ( remove_white_space() )) {
		switch ((c = get_byte())) {
			case 'd' :
			case 'D' : pptr->options |= _DIFFERED_PROC;
				   break;
			default  : return( syntax_error(4014) );
			}
		}
	if ( is_mnemonic( "IN" ) ) {
		if ( mode != MOINS_UN )
			return( syntax_error(4015) );
		if ( is_mnemonic("ANY" ) )
			pptr->module = MOINS_UN;
		else if (!( get_token() ))
			return( syntax_error(4016) );
		else	pptr->module = resolve_module_number( TokenBuffer, 0 );
		}
	else if ( mode == MOINS_UN )
		pptr->module = MOINS_UN;
	else	pptr->module = 0;

	return(0);
}

#ifdef	DEBUG
WORD	showme_params( pptr )
TCPRCPTR	pptr;
{
	TCVARPTR	vptr;
	if ((vptr = pptr->parameter) != (TCVARPTR) 0) {
		do	{
			sysprintf("pp:%s \n",vptr->name);
			}
		while ((vptr = vptr->next) != (TCVARPTR) 0);
		}
	return(0);
}
#endif

TCPRCPTR	add_function_method( name, parameters, type, options, module, nature, xtern )
BPTR		name;
TCVARPTR	parameters;
TCTYPPTR	type;
WORD		options;
WORD		module;
WORD		nature;
WORD		xtern;
{
	TCPRCPTR	pptr=(TCPRCPTR) 0;

	trace("add_function_method()\n");

	if (((pptr = allocate_for_procedure()) != (TCPRCPTR) 0)
	&&  ((pptr->name = allocate_for_token( name )) != (BPTR) 0)) {
		pptr->hash       = keyword_hash( name );
		pptr->parameter  = parameters;
		pptr->function   = VRAI;
		if ( nature )
			pptr->options    |= _DIFFERED_PROC;
		pptr->module     = module;
		if ( type != (TCTYPPTR) 0 ) {
			if ((pptr->result = allocate_for_type( type->type, type->size, 1, 1, type->class )) == (TCTYPPTR) 0) {
				(void) allocation_failure();
				return( (TCPRCPTR) 0);
				}
			switch (( type->type & 3 )) {
				case	0 :
					pptr->options |= _INT8_PROC;
					break;
				case	1 :
					pptr->options |= _INT16_PROC;
					break;
				case 	3 :
					pptr->options |= _STRING_PROC;
					break;
				case 	2 :
					pptr->options |= _NUMERIC_PROC;
					break;
				}
			}
		pptr = add_procedure( pptr, xtern,FAUX );
		}
	return( pptr );
}

WORD	detect_extern_call( TCPRCPTR pptr, WORD mode ) 
{
	if ( mode != MOINS_UN )
		return( 0 );
	else if (!( ExternCall.variable ))
		return( 0 );
	else if ( ExternCall.current <= ExternCall.limit ) {
		pptr->extitem = ExternCall.current++;
		pptr->extcall = ExternCall.variable;
		return( 0 );
		}
	else	return( syntax_error(4017)) ;
}

TCPRCPTR	translate_signature( mode )
WORD	mode;				/* VRAI : 		 PROC 	*/
					/* FAUX : EXTERN/FORWARD PROC	*/
{
	WORD		options=0;
	WORD		status;
	TCPRCPTR	pptr=(TCPRCPTR) 0;
	trace( "translate_signature()\n" );
	if ( get_token() ) {
		if (((pptr = allocate_for_procedure()) != (TCPRCPTR) 0)
		&&  ((pptr->name = allocate_for_token( TokenBuffer)) != (BPTR) 0)) {
			pptr->hash = TokenHash;
			if (((status = procedure_parameters(pptr))  == 0)
			&&  ((status = procedure_return_type(pptr)) == 0)
			&&  ((status = procedure_options(pptr,mode)) == 0)
			&&  ((status  = detect_extern_call( pptr, mode )) == 0)
			&&  ((pptr   = add_procedure(pptr,mode,VRAI)) != (TCPRCPTR) 0)) {
				return( pptr );
				}
			}
		if ( pptr != (TCPRCPTR) 0)
			liberate_for_procedure(pptr);
		return( (TCPRCPTR) 0 );
		}
	(void) syntax_error(4017);
	return( (TCPRCPTR) 0 );
	
}

WORD	translate_proc()
{
	TCPRCPTR	pptr;

	trace( "translate_proc()\n" );
	if ((pptr = translate_signature( VRAI )) != (TCPRCPTR) 0 )
		return( start_procedure(pptr,VRAI) );
	return( 30 );
}


/*
 *
 *	-----------------------------------------------------------------
 *	EXTERN	SEGMENT <name> [ AS <integer> ] [ IN <module ] [ IN ANY ]
 *	-----------------------------------------------------------------
 *
 */

WORD	translate_extern_segment()
{
	WORD	segmnum=MOINS_UN;
	WORD	modunum=MOINS_UN;
	WORD	status=0;
	BPTR	sptr=(BPTR) 0;
	BPTR	mptr=(BPTR) 0;

	if (!( get_token() ))
		return( syntax_error(4018) );
	else if ((sptr = allocate_for_string( TokenBuffer )) == (BPTR) 0)
		return( allocation_failure() );

	if ( is_mnemonic("AS" ) )
		segmnum = integer_expression();

	if ( is_mnemonic("IN" ) ) {
		if ( is_mnemonic("ANY") )
			modunum = MOINS_UN;
		else 	{
			if (!( get_token() ))
				return( syntax_error(4019) );
			else if ((mptr = allocate_for_string( TokenBuffer )) == (BPTR) 0) {
				liberate( sptr );
				return( allocation_failure() );
				}
			modunum = resolve_module_number( mptr, 0 );
			}
		}

	status = add_external_segment( sptr, segmnum, mptr, modunum, VRAI );		
	liberate( sptr );
	if ( mptr != (BPTR) 0 )
		liberate( mptr );
	return( status );
}

WORD	translate_extern_proc()
{
	TCPRCPTR	pptr;
	if ((pptr = translate_signature( MOINS_UN )) == (TCPRCPTR) 0 )
		return( 30 );
	else	return( 0 );
}

WORD	close_extern_field(WORD mode) /* 1 : explicite : 0 implicite */
{
	XTFIELDPTR	fptr;

	/* Leaving External Field */
	/* ---------------------- */
	if ((fptr = Context->CurrentXFT) == (XTFIELDPTR) 0) {
		if ( mode ) 	{ return( syntax_error(4023) ); }
		else		{ return( 0 ); /* false */ }
		}
	else	{
		Context->CurrentXFT = fptr->next;
		fptr->next = Context->XFT;
		Context->XFT = fptr;
		(void) field_equals_r();
		if ( mode )	{ return(0); /* no error */	}
		else		{ return(1); /* true   */	}
		}
}
 	
WORD	translate_extern_field()
{
	WORD		status;
	WORD		module=MOINS_UN;
	WORD		zone=0;
	BPTR		nptr=(BPTR) 0;
	HUGE		offset=-1L;

	if ( is_equals() ) {
		(void) field_equals_s();
		if ( is_mnemonic("M") ) {
			field_equals_m();
			zone = 'm';
			}
		else if ( is_mnemonic("E") ) {
			if ( OtrOption.WordSize > 2 ) {
				field_equals_m();
				zone = 'm';
				}
			else	{
				field_equals_e();
				zone = 'e';
				}
			}
		else if ( is_mnemonic("A") ) {
			if ( OtrOption.WordSize > 2 ) {
				field_equals_m();
				zone = 'm';
				}
			else	{
				zone = 'e';
				}
			}
		else if (( is_mnemonic("O") )
		     ||  ( is_mnemonic("I") )) {
			if ( Context->ThisField->Field == 64 ) {
				offset = Context->ThisField->BigField;
				zone = 'E';
				}
			else	{
				zone = 'M';
				offset = Context->ThisField->SmallField;
				}
			}			
		else	return( syntax_error(4020) );
		if ( is_comma() ) {
			if ( get_token() ) {
				if ((nptr = allocate_for_string( TokenBuffer)) == (BPTR) 0)
					return( allocation_failure() );
				else if ((status = redefine_variable()) != 0)
					return( status );
				else if ( Context->ThisField->Field == 64 )
					offset = Context->ThisField->BigField;
				else	offset = (HUGE) Context->ThisField->SmallField;
				}
			else	return( syntax_error(4021) );
			if ( zone & 0x0020 ) {
				zone &= ~0x0020;
				zone |= 0x0080;
				}
			}
		if ( is_mnemonic( "IN" ) ) {
			if ( is_mnemonic("ANY" ) )
				module = MOINS_UN;
			else if (!( get_token() ))
				return( syntax_error(4022) );
			else	module = resolve_module_number( TokenBuffer, 0 );
			}
		else 	module = MOINS_UN;

		return( add_external_field(module,zone,nptr,(LONG)offset) );

		}
	else	{
		close_extern_field(1);
		}
	return 0; 
}

WORD	translate_extern_dcl(type)
WORD	type;	/* _KW1_DCL   or  _KW1_PTR */
{
	return( not_yet_available() );
}

WORD	extern_call_start()
{
	TCVARPTR	vptr=(TCVARPTR) 0;
	if (((vptr = ExternCall.variable ) != (TCVARPTR) 0)
	&&  ( ExternCall.current != 0 )
	&&  (( vptr->type->type & _TYPE_FIRST ) != 0)
	&&  (( ExternCall.limit = vptr->type->first ) != 0)
	&&  (  ExternCall.current <=  ExternCall.limit ))
		return( 0 );
	else	{
		(void) extern_call_end();
		return( syntax_error(4024) );
		}

}

WORD	translate_extern_call()
{
	TCVARPTR	variable_symbol( BPTR );

	/* ATR compatible : always clears state first */
	/* ------------------------------------------ */
	(void) extern_call_end();

	if ( get_token() ) {
		switch (is_level1_keyword()) {
			case	_KW1_END	:
				return( extern_call_end() );
			case 	MOINS_UN	: 

				if (!(ExternCall.variable = variable_symbol(TokenBuffer)))
					break;
				else if ( is_left_brace() ) {

					if (!(ExternCall.current = integer_expression()))
						break;

					else if (!( is_right_brace() ))
						break;
					}
				else	ExternCall.current = 1;

				return( extern_call_start() );

			}
		/* All errors fuck it up */
		/* --------------------- */
		(void) extern_call_end();
		}
	return( syntax_error(4024) );
}

WORD	translate_export()
{
	trace( "translate_export()\n" );
	Context->ExpliciteExport++;
	Context->IsExport=1;
	return(0);
}

WORD	translate_extern()
{
	WORD	type;

	trace( "translate_extern()\n" );

	Context->ExpliciteExtern++;

	if ( is_ampersand() ) {
		/* EXTERN &LABEL=[M|E] */
		if (!( get_token() ))
			return( syntax_error(4024) );
		else if (!( is_equals() ))
			return( syntax_error(4024) );
		else if ( is_mnemonic( "E" ) )
			return( 0 );
		else if ( is_mnemonic( "M" ) )
			return( 0 );
		else	return( syntax_error( 4024 ) );
		}
	else if ( get_token() ) {
		switch ((type = is_level1_keyword())) {

			case _KW1_PROC  : 
				return( translate_extern_proc() );
			case _KW1_SEGMENT  :
				return( translate_extern_segment() );
			case _KW1_FIELD :
				return( translate_extern_field() );
			case _KW1_CLASS :
				return( translate_extern_class() );
			case _KW1_DCL   :
			case _KW1_PTR   :
			case _KW1_STRUCT:
			case _KW1_UNION :
				return( translate_extern_dcl(type) );
			default		:
				switch (((type = is_control_keyword()))) {
					case	_CTRL_CALL	:
						return( translate_extern_call() );
					}
			}
		}
	return( syntax_error(4024) );
}

WORD	translate_forward()
{
	WORD	type;
	TCPRCPTR	pptr;
	trace( "translate_forward()\n" );
	if (get_token()) {
		if  ((type = is_level1_keyword()) == _KW1_PROC) {
			if  ((pptr = translate_signature( FAUX )) != (TCPRCPTR) 0)
				return(0);
			else	return( syntax_error( 4029 ) );
			}
		else	return( translate_forward_class() );
		}
	else	return( syntax_error(4025) );
}

VOID	start_verbose_report(char * sptr)
{
	if ( OtrOption.Verbose & 32 ) {
		sysprintf("<html><head><title>Otr Report:%s</title>\n",sptr);
		if ( World->StyleSheet ) {
			sysprintf("<link href=%s",World->StyleSheet);
			sysprintf(" rel=%cSTYLESHEET%c",0x0022,0x0022);
			sysprintf(" type=%ctext/css%c",0x0022,0x0022);
			sysprintf(" media=%cSCREEN%c>\n",0x0022,0x0022);
			}
		sysprintf("</head><body><table><tr><th><h1>Otr Report</h1><h1>%s</h1>\n<h2>",sptr);
		}
	return;
}

VOID	verbose_report_footer()
{
	if ( OtrOption.Verbose & 32 ) {
		if ( OtrOption.Verbose & 64 ) {
			sysprintf("</table>\n");
			OtrOption.Verbose &= ~64;
			}
		sysprintf("<p>\n");
		}
	return;
}

VOID	close_verbose_report()
{
	if ( OtrOption.Verbose & 32 ) {
		verbose_report_footer();
		sysprintf("<p></table><p></body></html>\n");
		}
	return;
}

VOID	verbose_report_header(int extmode)
{
	if ( OtrOption.Verbose & 32 ) {
		if (!( OtrOption.Verbose & 64 ))  {
			sysprintf("<table border=1><tr><th>ID<th>Code Size<th>Data Table<th>Constants");
			OtrOption.Verbose |= 64;
			}
		if ( extmode )
			sysprintf("<tr><th colspan=4>");
		else	sysprintf("<tr><th>");
		}
	return;
}

VOID	procedure_verbose( pptr )
TCPRCPTR	pptr;
{
	TCVARPTR	vptr;
	verbose_report_header(0);
	sysprintf("PROC    %s",pptr->name);
	if ( pptr->options & _DIFFERED_PROC )
		sysprintf(", D\n");
	else	sysprintf("\n");
	for (	vptr=pptr->parameter;
		vptr != (TCVARPTR) 0;
		vptr = vptr->next ) {
		if ( vptr->name )
			sysprintf("\t%s\r\n",vptr->name);
		}
	
	return;
}

#endif	/* _TRPROC_C */
	/* --------- */





