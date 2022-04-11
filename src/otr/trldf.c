/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 2021 Amenesik / Sologic.			*/
/*									*/
/*									*/
/*		File	:	TRLDF.C    				*/
/*		Version :	5.1 					*/
/*		Date	:	01/05/2021				*/
/*									*/
/* --------------------------------------------------------------------	*/
/*	Modifications Log  (most recent first please!)			*/
/* --------------------------------------------------------------------	*/
/* 12/01/1996	:	Correction to allow more then one user library  */
/*			in a translation unit. Prior to this date only  */
/*			the last user library encountered was added to  */
/*			the tcode user library table. (cf TRTABLES.C)	*/
/* --------------------------------------------------------------------	*/

#ifndef	_TRLDF_C
#define	_TRLDF_C

#define	DEBUG

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include <string.h>
#include "stdtypes.h"
#include "translat.h"
#include "trsyntax.h"
#include "trparser.h"
#include "trerrors.h"
#include "trsymbol.h"
#include "trexpres.h"
#include "troption.h"
#include "trclf.h"
#include "trldf.h"
#include "trdebug.h"
#include "trtables.h"
#include "trecho.h"
#include "trinput.h"
#include "trproc.h"
#include "triof.h"
#include "troutput.h"

static	WORD	LdfNumerate;

/*	----------------	*/
/*	allocate_for_dll	*/
/*	----------------	*/
TCDLBPTR	allocate_for_dll()
{
	TCDLBPTR	lptr;

	if ((lptr = (TCDLBPTR) allocate( sizeof( struct tcode_library ) )) != (TCDLBPTR) 0) 
	{
		lptr->next    	= (TCDLBPTR) 0;
		lptr->prev    	= (TCDLBPTR) 0;
		lptr->version 	= MOINS_UN;
		lptr->title	= (BPTR) 0;
		lptr->functions = 0;
		lptr->options   = 0;
		lptr->usage	= 0;
		lptr->alias	= 0;
		lptr->name	= (BPTR) 0;
		lptr->relocation= (RELOCPTR) 0;
		lptr->access	= _LDF_PUBLIC;
		lptr->identity  = MOINS_UN;
		lptr->function  = (TCDLFPTR) 0;
	}
	return( lptr );
}

/*	----------------	*/
/*	allocate_for_dlf	*/
/*	----------------	*/
TCDLFPTR	allocate_for_dlf()
{
	TCDLFPTR	fptr;

	if ((fptr = (TCDLFPTR) allocate( sizeof( struct	tcode_library_function ) )) != (TCDLFPTR) 0) 
	{
		fptr->identity 	= MOINS_UN;
		fptr->name	= (BPTR) 0;
		fptr->library	= (TCDLBPTR) 0;
		fptr->type	= MOINS_UN;
		fptr->usage	= 0;
		fptr->parameter = (TCVARPTR) 0;
		fptr->next	= (TCDLFPTR) 0;
	}
	return( fptr );
}
	 
/*	------------	*/
/*	get_dll_type	*/
/*	------------	*/
WORD	get_dll_type()
{
	if ( remove_white_space() ) 
	{
		switch ( get_byte() ) 
		{
		case '#' : return(_TYPE_INT8);
		case '%' : return(_TYPE_INT16);
		case ':' : return(_TYPE_INT32);
		case '&' : return(_TYPE_INT64);
		case '$' : return(_TYPE_STRING);
		case '*' : return(_TYPE_NUMERIC);
		case '.' : return(_TYPE_BASIC);
		default  : unget_byte();
		}
	}
	return( MOINS_UN );
}

/*	----------------------	*/
/*	translate_dll_function	*/
/*	----------------------	*/
static WORD	translate_dll_function()
{
	WORD		retval=MOINS_UN;
	WORD		paratype;
	WORD		parasize;
	TCDLBPTR	lptr;
	TCDLFPTR	fptr;
	TCVARPTR	vptr;
	TCVARPTR	lvptr;
	SYMBOLPTR	sptr;
	WORD		numerate=MOINS_UN;

	trace("translate_dll_function()\n");

	if ((lptr = Context->XDLT) == (TCDLBPTR) 0)
		return( syntax_error(5) );

	if ( is_mnemonic("END") ) 
	{
		restore_star_comments(1);
		restore_label_status();
		pop_operation_pointer();
		pop_source_context(MOINS_UN);
		return( 0 );
	}
	else if ( LdfNumerate ) 
	{
		numerate = collect_integer();
		if (!( is_colon() ))
			return( syntax_error(6) );
	}
	else	numerate = MOINS_UN;

	retval = get_dll_type();

	if (!( get_token() ))
		return( syntax_error(7) );

	if (( retval == MOINS_UN )
	&&  ( is_level1_keyword() == _KW1_END )) 
	{
		pop_operation_pointer();
		pop_source_context(MOINS_UN);
		return( 0 );
	}

	if ((sptr = is_symbol( TokenBuffer )) != (SYMBOLPTR) 0)
		return( symbol_already_defined(TokenBuffer) );
	if ((sptr = add_symbol( TokenBuffer, SYMBOL_USER  )) == (SYMBOLPTR) 0)
		return(allocation_failure());

	if ((fptr = allocate_for_dlf()) == (TCDLFPTR) 0)
		return( allocation_failure() );

	sptr->contents 	= (VPTR) fptr;
	fptr->name 	= sptr->name;

	if ((fptr->next = lptr->function) != (TCDLFPTR) 0) 
	{
		if ( LdfNumerate )
			fptr->identity = numerate;
		else	fptr->identity = (fptr->next->identity + 1);
	}
	else	
	{
		if ( LdfNumerate )
			fptr->identity = numerate;
		else	fptr->identity = 0;
	}
	lptr->functions++;
	lptr->function 	= fptr;
	fptr->type 	= retval;
	fptr->library 	= lptr;

	if ( is_left_brace() ) 
	{
		do	
		{
			if ((paratype = get_dll_type()) == MOINS_UN)
				break;
			switch ( paratype ) 
			{
			case	_TYPE_INT8  	: parasize = _SIZE_INT8;  break;
			case 	_TYPE_INT16 	: parasize = _SIZE_INT16; break;
			case	_TYPE_INT32 	: parasize = _SIZE_INT32; break;
			case	_TYPE_INT64 	: parasize = _SIZE_INT64; break;
			case	_TYPE_NUMERIC   : parasize = _SIZE_NUMERIC; break;
			case	_TYPE_BASIC 	: 
			case	_TYPE_STRING	: parasize = _SIZE_STRING; break;
			default	  : return( syntax_error(8) );
			}
			if ( is_question() )
				paratype |= _TYPE_PARAMETER;
			if ((vptr = allocate_for_variable()) == (TCVARPTR) 0)
				return( allocation_failure() );
			if ((vptr->type = allocate_for_type( paratype, parasize, 1, 1, (VPTR) 0 )) == (TCTYPPTR) 0)
				return( allocation_failure() );
			if (fptr->parameter == (TCVARPTR) 0) 
				fptr->parameter = vptr;
			else	lvptr->prev     = vptr;
			lvptr = vptr;
		}
		while ( is_comma() );

		if (!( is_right_brace() ))
			return( unmatched_braces() );
	}

	if ( OtrOption.ListFlag & 1 )
		echo_dll_function( fptr );
	return(0);
}

/*	---------------------	*/
/*	translate_dll_runtime	*/
/*	---------------------	*/
static WORD	translate_dll_runtime()
{
	TCDLBPTR	lptr;
	BPTR		token;
	trace("translate_dll_runtime()\n");
	if (((lptr = Context->XDLT) != (TCDLBPTR) 0)
	&&  ( get_token() )
	&&  ( is_equals() )
	&&  ( get_token() )) 
	{
		token = (BPTR) TokenBuffer;
		if ( *token == '"' ) 
		{
			token++;
			*( token + ( strlen( token ) - 1 )) = 0;
		}
		if ((lptr->name = allocate_for_string( token )) == (BPTR) 0)
			return( allocation_failure() );
		if ( is_comma() ) 
		{
			if ( is_mnemonic( "PRELOAD" ) )
				Context->XDLT->options |= 1;
			else	return( syntax_error(10) );
		}
		inhibit_star_comments();
		Context->operation = translate_dll_function;
		return(0);
	}
	return(syntax_error(9));
}

/*	----------------	*/
/*	add_dll_function	*/
/*	----------------	*/
WORD	add_dll_function( lptr, fptr )
TCDLBPTR	lptr;
TCDLFPTR	fptr;
{
	if ((fptr->next = lptr->function) != (TCDLFPTR) 0) 
	{
		if ( fptr->identity == MOINS_UN )
			fptr->identity = (fptr->next->identity + 1);
	}
	else	fptr->identity = 0;
	lptr->function 	= fptr;
	return( fptr->identity );
}

/*	-------------------	*/
/*	add_dynamic_library	*/
/*	-------------------	*/
VOID	add_dynamic_library(lptr)
TCDLBPTR	lptr;
{
	if ((lptr->prev = Context->XDLT) != (TCDLBPTR) 0) 
	{
		if (!( lptr->alias ))
		lptr->identity = (lptr->prev->identity + 1);
		else	lptr->identity = (lptr->alias - 1);
		lptr->prev->next = lptr;
	}
	else	
	{
		Context->DLT = lptr;
		if (!( lptr->alias ))
		lptr->identity = 0;
		else	lptr->identity = (lptr->alias - 1);
	}
	if (!( lptr->alias )) 
	{
		Context->count_DLT++;
	}
	Context->XDLT = lptr;
	return;
}

/*	---------------------	*/
/*	translate_dll_version	*/
/*	---------------------	*/
static WORD	translate_dll_version()
{
	TCDLBPTR	lptr;
	WORD		vers;

	trace("translate_dll_version()\n");

	if (( get_token() )
	&&  ( is_equals() )
	&&  ((vers = collect_integer()) != 0 )) 
	{
		if ((lptr = allocate_for_dll()) == (TCDLBPTR) 0)
			return( allocation_failure() );
		else if ( is_comma() ) 
		{
			if ( is_mnemonic( "NUM" ) )
				LdfNumerate = VRAI;
			else	return( syntax_error(10) );
		}
		else	LdfNumerate = FAUX;
		lptr->version = vers;
		add_dynamic_library( lptr );
		Context->operation  = translate_dll_runtime;
		return(0);
	}
	return(syntax_error(11));
}

/*	-------------------------	*/
/*	liberate_dynamic_function	*/
/*	-------------------------	*/
VOID	liberate_dynamic_function( fptr, version )
TCDLFPTR	fptr;
WORD		version;
{
	TCVARPTR	vptr;
	if ( version != MOINS_UN ) 
	{
		while ((vptr = fptr->parameter) != (TCVARPTR) 0) 
		{
			fptr->parameter = vptr->next;
			liberate_for_variable( vptr );
		}
	}

	liberate( fptr );
	return;

}

/*	------------------------	*/
/*	liberate_dynamic_library	*/
/*	------------------------	*/
VOID	liberate_dynamic_library(lptr)
TCDLBPTR	lptr;
{
	TCDLFPTR	fptr;
	if ( lptr != (TCDLBPTR) 0) 
	{
		while ((fptr = lptr->function) != (TCDLFPTR) 0) 
		{
			lptr->function = fptr->next;
			liberate_dynamic_function( fptr, lptr->version );
		}
		if ( lptr->name != (BPTR) 0 )
			liberate( lptr->name );
		liberate( lptr );
	}
	return;
}

/*	-------------------------	*/
/*	 locate_dynamic_function	*/
/*	-------------------------	*/
TCDLFPTR	locate_dynamic_function( lptr, number )
TCDLBPTR	lptr;
WORD		number;
{
	TCDLFPTR	fptr;

	if ((fptr = lptr->function) != (TCDLFPTR) 0) 
	{
		do	
		{
			if ( fptr->identity == number )
				break;
		}
		while ((fptr = fptr->next) != (TCDLFPTR) 0);
	}
	return( fptr );
}

/*	------------------------	*/
/*	 locate_dynamic_library		*/
/*	------------------------	*/
TCDLBPTR	locate_dynamic_library( nptr )
BPTR		nptr;
{
	TCDLBPTR	lptr;
	BPTR		name;
	WORD		c;
	WORD		alias=0;

	switch ((c = *nptr )) 
	{
	case	'<'	:
		c = '>';
	case	'"'	:
		nptr++;
		name = nptr;
		while ((*nptr) && ( *nptr != c ))
			nptr++;
		*nptr = 0;
		nptr = name;
	}

	if ((lptr = Context->DLT) != (TCDLBPTR) 0) 
	{
		do	
		{
			if ( compare_tokens( lptr->name, nptr ) ) 
			{
				if ( lptr->version != MOINS_UN ) 
				{
					alias = (lptr->identity+1);
					break;
				}
				return( lptr );
			}
		}
		while ((lptr = lptr->next) != (TCDLBPTR) 0);
	}

	if (((lptr = allocate_for_dll()) != (TCDLBPTR) 0)
	&&  ((lptr->name = allocate_for_string( nptr )) != (BPTR) 0)) 
	{
		lptr->version = MOINS_UN;
		lptr->access = Context->Visibility;
		lptr->alias  = alias;
		add_dynamic_library( lptr );
		return( lptr );
	}
	else	liberate_dynamic_library( lptr );
	return( (TCDLBPTR) 0 );
}

/*	-------------------------	*/
/*	translate_dll_description	*/
/*	-------------------------	*/
WORD	translate_dll_description( filename )
BPTR	filename;
{
	WORD	status;
	trace("translate_dll_description()\n");
	if (( filename != (BPTR) 0 )
	&&  (( status = include_source_file( filename, "def" )) != 0))
		return( status );
	push_operation_pointer();
	inhibit_label_status();
	set_operation_pointer(translate_dll_version);
	return(0);

}

/*	--------------------------	*/
/*	liberate_dynamic_libraries	*/
/*	--------------------------	*/
VOID	liberate_dynamic_libraries()
{
	TCDLBPTR	lptr;

	while ((lptr = Context->DLT) != (TCDLBPTR) 0) 
	{
		Context->DLT = lptr->next;
		liberate_dynamic_library( lptr );
	}
	return;
}

/*	----------------	*/
/*	allocate_for_ldf	*/
/*	----------------	*/
LDFPTR	allocate_for_ldf()
{
	LDFPTR	lptr;

	if ((lptr = (LDFPTR) allocate( sizeof ( struct otr_dlf ) )) != (LDFPTR) 0) 
	{
		lptr->root 	= (ARGPTR) 0;
		lptr->last	= (ARGPTR) 0;
		lptr->func	= (TCDLFPTR) 0;
	}
	return( lptr );
}

/*	---------	*/
/*	start_ldf	*/
/*	---------	*/
LDFPTR	start_ldf( fptr )
TCDLFPTR	fptr;
{
	LDFPTR	lptr;
	trace("start_ldf()\n");
	if ((lptr = allocate_for_ldf()) != (LDFPTR) 0)
		lptr->func = fptr;
	return( lptr );
}

/*	----------------	*/
/*	ldf_return_value	*/
/*	----------------	*/
RESULTPTR	ldf_return_value( type )
WORD		type;
{
	WORD		holder=0;
	RESULTPTR	rptr=(RESULTPTR) 0;
	switch ( type ) 
	{
	case _TYPE_INT8		:
	case _TYPE_INT16	:
	case _TYPE_INT32	:
	case _TYPE_INT64	:
		rptr = next_free_register();
		break;
	case _TYPE_NUMERIC	: 
		rptr = clf_abs_zero();
		break;
	case _TYPE_STRING	:
		holder = Context->UseTarget;
		Context->UseTarget = 0;
		rptr = clf_space(255);
		Context->UseTarget = holder;
		break;
	default 		:
		break;
	}
	if ( rptr != (RESULTPTR) 0)
		shadow_conversion( rptr, type );
	return( rptr );
}

/*	----------	*/
/*	ldf_target	*/
/*	----------	*/
RESULTPTR	ldf_target( xptr )
LDFPTR		xptr;
{
	TCDLFPTR	fptr;
	trace("ldf_target()\n");
	if ((fptr = xptr->func) != (TCDLFPTR) 0)
		return( ldf_return_value( fptr->type ) );
	else	return( (RESULTPTR) 0 );
}

/*	---------------------	*/
/*	flush_ldf_descriptors	*/
/*	---------------------	*/
static	WORD	flush_ldf_descriptors(xptr, iptr, rptr )
LDFPTR		xptr;
RESULTPTR	rptr;
RESULTPTR	iptr;
{
	WORD		i=0;
	WORD		phase;
	WORD		descriptor;
	WORD		d;
	RESULTPTR	lparam;
	WORD		n=0;
	ARGPTR		cptr;
	WORD		special;
	WORD		status;

	if ( xptr->func != (TCDLFPTR) 0) 
	{
		xptr->func->library->usage++;
		xptr->func->usage++;
	}

	if ( rptr != (RESULTPTR) 0) 
	{
		if (( rptr = mark_live_result( rptr )) == (RESULTPTR) 0)
			return( internal_error(1) );

		/* -------------------------------------- */
		/* watch out for bcd and string returns ! */
		/* -------------------------------------- */
		switch (( result_type( rptr ) & _TYPE_BASIC )) 
		{
			case	_TYPE_NUMERIC	:
			case	_TYPE_STRING	:
				break;
			case	_TYPE_INT8	:
			case	_TYPE_INT16	:
			case	_TYPE_INT32	:
			case	_TYPE_INT64	:
				xptr->descriptor[0] = (( rptr->nature << 5 ) | 0x0080);
				n++;
		}
	}

	if ( iptr != (RESULTPTR) 0) 
	{
		if (( iptr = mark_dead_result( iptr )) == (RESULTPTR) 0)
			return( internal_error(1) );
		if ( n )
			xptr->descriptor[0] |= (( iptr->nature << 1 ) | 0x0010);
		else	xptr->descriptor[0] = ( iptr->nature << 5 );
		n++;
	}

	if ( rptr != (RESULTPTR) 0) 
	{

		/* -------------------------------------- */
		/* watch out for bcd and string returns ! */
		/* -------------------------------------- */
		switch (( result_type( rptr ) & _TYPE_BASIC )) 
		{
			case	_TYPE_NUMERIC	:
			case	_TYPE_STRING	:
				if ( n )
					xptr->descriptor[0] |= (( rptr->nature << 1 ) | 0x0018);
				else	xptr->descriptor[0] = (( rptr->nature << 5 ) | 0x0080);
				n++;
				break;
			case	_TYPE_INT8	:
			case	_TYPE_INT16	:
			case	_TYPE_INT32	:
			case	_TYPE_INT64	:
				break;
		}
	}

	if ((cptr = xptr->root) != (ARGPTR) 0) 
	{
		cptr = xptr->last;
		do	
		{
			if ((lparam = cptr->operand) != (RESULTPTR) 0) 
			{
				if ( cptr->nature )
					cptr->operand = mark_zero_result( lparam );
				else	cptr->operand = mark_dead_result( lparam );
			}
		}
		while ((cptr = cptr->prev) != (ARGPTR) 0);
		cptr = xptr->root;
		do	
		{
			/* --------------------------------------- */
			/* Calculate descriptor access information */
			/* --------------------------------------- */
			phase = (n & 1);
			descriptor = (n/2);

			if ((lparam = cptr->operand) == (RESULTPTR) 0)
				return( syntax_error(12) );
		
			/* ---------------------------------- */
			/* Indicate more parameters to follow */
			/* ---------------------------------- */
			if ( phase )
				xptr->descriptor[descriptor]     |= 0x0010;
			else if ( descriptor )
				xptr->descriptor[(descriptor-1)] |= 0x0001;

			if ( cptr->nature ) 
				special = 4;
			else	special = 0;

			/* -------------------------- */  
			/* Establish Parameter Nature */
			/* -------------------------- */  
			if (!( phase ))
				xptr->descriptor[descriptor]  = ((lparam->nature | special)<< 5);
			else	xptr->descriptor[descriptor] |= ((lparam->nature | special) << 1);
			n++;
		}
		while ((cptr = cptr->next) != (ARGPTR) 0);
	}

	i = 0;
	if ( xptr->func != (TCDLFPTR) 0 ) 
	{
		if ((status = generate_ldf( xptr->func->library )) != 0)
			return( status );
	}
	else if ((status = generate_lde()) != 0)
		return( status );

	while ( 1 ) 
	{
		tcputbyte((d = xptr->descriptor[i]));
		if ( d & 1 )
			i++;
		else	break;
	}
	return(0);
}

/*	-------------------	*/
/*	flush_ldf_parameter	*/
/*	-------------------	*/
static	WORD	flush_ldf_parameter(lparam)
RESULTPTR	lparam;
{
	if (lparam == (RESULTPTR) 0)
		return( syntax_error(13) );
	else	tcode_operand( lparam );
	return( 0 );
}

/*	--------------------	*/
/*	flush_ldf_parameters	*/
/*	--------------------	*/
static	WORD	flush_ldf_parameters(xptr, iptr, rptr )
LDFPTR		xptr;
RESULTPTR	iptr;
RESULTPTR	rptr;
{
	ARGPTR		cptr;
	WORD		status=0;

	if ( rptr != (RESULTPTR) 0) 
	{
		/* -------------------------------------- */
		/* watch out for bcd and string returns ! */
		/* -------------------------------------- */
		switch (( result_type( rptr ) & _TYPE_BASIC )) 
		{
		case	_TYPE_NUMERIC	:
		case	_TYPE_STRING	:
			break;
		case	_TYPE_INT8	:
		case	_TYPE_INT16	:
		case	_TYPE_INT32	:
		case	_TYPE_INT64	:
			flush_ldf_parameter( rptr );
			rptr = (RESULTPTR) 0;
			break;
		}
	}

	if ( iptr != (RESULTPTR) 0)
		flush_ldf_parameter( iptr );

	if ( rptr != (RESULTPTR) 0) 
	{
		/* -------------------------------------- */
		/* watch out for bcd and string returns ! */
		/* -------------------------------------- */
		switch (( result_type( rptr ) & _TYPE_BASIC )) 
		{
		case	_TYPE_NUMERIC	:
		case	_TYPE_STRING	:
			flush_ldf_parameter( rptr );
			rptr = (RESULTPTR) 0;
			break;
		case	_TYPE_INT8	:
		case	_TYPE_INT16	:
		case	_TYPE_INT32	:
		case	_TYPE_INT64	:
			break;
		}
	}

	if ((cptr = xptr->root) != (ARGPTR) 0) 
	{
		do	
		{
			if ((status = flush_ldf_parameter( cptr->operand )) != 0)
				return( status );
		}
		while ((cptr = cptr->next) != (ARGPTR) 0);
	}
	return( 0 );
}

/*	---------	*/
/*	flush_ldf	*/
/*	---------	*/
RESULTPTR	flush_ldf( xptr, iptr )
LDFPTR		xptr;
RESULTPTR	iptr;
{
	RESULTPTR	rptr=(RESULTPTR) 0;
	WORD		status;
	trace("flush_ldf()\n");
	if (((rptr = ldf_target(xptr)) != (RESULTPTR) 0)
	&&  ((status = flush_ldf_descriptors(xptr,iptr, rptr ))  == 0)
	&&  ((status = flush_ldf_parameters(xptr,iptr, rptr ))   == 0))
		return( rptr );
	else	return( rptr );
	return( rptr );
}

/*	------------------	*/
/*	flush_indirect_ldf	*/
/*	------------------	*/
RESULTPTR	flush_indirect_ldf( xptr, iptr, tptr )
LDFPTR		xptr;
RESULTPTR	iptr;
TCTYPPTR	tptr;
{
	RESULTPTR	rptr=(RESULTPTR) 0;
	WORD		status;
	trace("flush_ldf()\n");
	if (((rptr = ldf_return_value(tptr->type)) != (RESULTPTR) 0)
	&&  ((status = flush_ldf_descriptors(xptr,iptr, rptr ))  == 0)
	&&  ((status = flush_ldf_parameters(xptr,iptr, rptr ))   == 0))
		return( rptr );
	else	return( rptr );
	return( rptr );
}

/*	----------------	*/
/*	 flush_void_ldf 	*/
/*	----------------	*/
WORD		flush_void_ldf( xptr, iptr )
LDFPTR		xptr;
RESULTPTR	iptr;
{
	WORD		status=0;

	trace("flush_void_ldf()\n");
	if  (((status = flush_ldf_descriptors(xptr,iptr, (RESULTPTR) 0 ))  == 0)
	&&   ((status = flush_ldf_parameters(xptr,iptr, (RESULTPTR) 0 ))   == 0))
		return( status );
	else	return( status );
}

/*	---------	*/
/*	store_ldf	*/
/*	---------	*/
WORD		store_ldf(xptr, rptr, status )
LDFPTR		xptr;
RESULTPTR	rptr;
WORD		status;
{
	ARGPTR	cptr;
	trace("store_ldf()\n");
	if ((cptr = allocate_for_operand()) == (ARGPTR) 0)
		return( allocation_failure() );
	cptr->operand = rptr;
	if ((cptr->prev = xptr->last) == (ARGPTR) 0)
		xptr->root = cptr;
	else	xptr->last->next = cptr;
	if ( status  )
		cptr->nature = VRAI;
	xptr->last = cptr;
	return( 0 );
}

/*	---------------------	*/
/*	evaluate_dll_function	*/
/*	---------------------	*/
RESULTPTR	evaluate_dll_function( fptr )
TCDLFPTR	fptr;
{
	RESULTPTR	rptr=(RESULTPTR) 0;
	RESULTPTR	iptr=(RESULTPTR) 0;
	LDFPTR		xptr;
	TCVARPTR	vptr;

	trace("evaluate_dll_function()\n");

	if ((xptr = start_ldf( fptr )) == (LDFPTR) 0)
		return( (RESULTPTR) 0 ); 

	if ((iptr = integer_result( fptr->identity )) == (RESULTPTR) 0)
		return( iptr );

	if ( is_left_brace() ) 
	{
		if ((vptr = fptr->parameter) != (TCVARPTR) 0) 
		{
			do	
			{
				if ( is_right_brace() ) 
				{
					unget_byte();
					break;
				}
				else if ( vptr == (TCVARPTR) 0 ) 
				{
					(void) syntax_error( 1040 );
					return((RESULTPTR) 0 );
				}
				else if ((rptr = evaluate_typed_expression((vptr->type->type & _TYPE_BASIC))) == (RESULTPTR) 0)
					return( (RESULTPTR) 0 );
				else	store_ldf( xptr, rptr, (vptr->type->type & _TYPE_PARAMETER) );
				if (( vptr->type->type & _TYPE_BASIC ) != _TYPE_BASIC)
					vptr = vptr->prev;
			}
			while ( is_comma() );
		}
		if (!( is_right_brace() )) 
		{
			(void) unmatched_braces();
			return((RESULTPTR) 0 );
		}
	}
	return( flush_ldf( xptr, iptr ) );
}

/*	---------------------	*/
/*	activate_dll_function	*/
/*	---------------------	*/
WORD		activate_dll_function( fptr )
TCDLFPTR	fptr;
{
	RESULTPTR	rptr=(RESULTPTR) 0;
	RESULTPTR	iptr=(RESULTPTR) 0;
	LDFPTR		xptr;
	TCVARPTR	vptr;

	trace("activate_dll_function()\n");

	if ((xptr = start_ldf( fptr )) == (LDFPTR) 0)
		return( allocation_failure() ); 

	if ((iptr = integer_result( fptr->identity )) == (RESULTPTR) 0)
		return( allocation_failure() );

	if ( is_left_brace() ) 
	{
		if ((vptr = fptr->parameter) != (TCVARPTR) 0) 
		{
			do	
			{
				if ( is_right_brace() ) 
				{
					unget_byte();
					break;
				}
				else if ( vptr == (TCVARPTR) 0 )
					return(syntax_error( 1040 ));
				else if ((rptr = evaluate_typed_expression((vptr->type->type & _TYPE_BASIC))) == (RESULTPTR) 0)
					return( syntax_error(15) );
				else	store_ldf( xptr, rptr, (vptr->type->type & _TYPE_PARAMETER) );

				if (( vptr->type->type & _TYPE_BASIC ) != _TYPE_BASIC)
					vptr = vptr->prev;
			}
			while ( is_comma() );
		}
		if (!( is_right_brace() )) 
			return( unmatched_braces() );
	}
	return( flush_void_ldf( xptr, iptr ) );
}

	/* -------- */
#endif	/* _TRLDF_C */
	/* -------- */

