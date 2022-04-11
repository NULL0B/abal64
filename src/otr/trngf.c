/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic 		*/
/*									*/
/*									*/
/*		File	:	TRNGF.C    				*/
/*		Version :	2.1c					*/
/*		Date	:	28/09/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRNGF_C
#define	_TRNGF_C

#define	DEBUG

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include <string.h>
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
#include "trdebug.h"
#include "trproc.h"
#include "triof.h"
#include "troutput.h"
#include "triter.h"
#include "trecho.h"
#include "trabal.h"


#ifdef	UNIX
BPTR		get_ngf_keyword();
RESULTPTR	build_string_constant();
RESULTPTR	evaluate_integer_expression();
#endif

/*	------------------------------------------------------		*/
/*	SERVICE (static) FUNCTIONS used during NGF TRANSLATION		*/
/*	------------------------------------------------------		*/

/*	---------	*/
/*	reset_ngf	*/
/*	---------	*/
static	VOID	reset_ngf()
{
	WORD	i;

	for ( i = 0; i < 16; i++ )
		NGF.Parameter[i] = (RESULTPTR) 0;

	NGF.Special    = 0;
	NGF.Operation  = MOINS_UN;
	NGF.Parameters = 0;
	NGF.Colon      = FAUX;
	NGF.DataBase   = (RESULTPTR) 0;
	NGF.Error      = (RESULTPTR) 0;
	NGF.ErrorFlag  = MOINS_UN;
	NGF.ErrorAdr   = MOINS_UN;
	memset(	NGF.ErrorLabel, 0, MAX_LABEL_SIZE );
	memset(	NGF.Descriptor, 0, MAX_LABEL_SIZE );
	return;
}

/*	-----------	*/
/*	colon_check	*/
/*	-----------	*/
static	WORD	colon_check()
{
	if (( NGF.Colon )
	||  ( is_colon()))
		return((NGF.Colon = VRAI));
	else	return(FAUX);
}

/*	-----------------	*/
/*	flush_descriptors	*/
/*	-----------------	*/
static	WORD	flush_descriptors()
{
	WORD		i;
	WORD		phase;
	WORD		descriptor;
	WORD		d;
	RESULTPTR	lparam;
	WORD		n=0;
	WORD		status=0;
	if ((NGF.ErrorFlag != MOINS_UN )
	&&  (NGF.Error     != (RESULTPTR) 0)) 
	{
		if ((NGF.Error = mark_dead_result( NGF.Error )) == (RESULTPTR) 0)
			return( internal_error(5) );
		NGF.Descriptor[0] = (0x0080 | ( NGF.Error->nature << 5 ));
		n=1;
	}
	else	n=0;

	for ( i = 0; i < NGF.Parameters; i++, n++ ) 
	{
		if ((lparam = NGF.Parameter[i]) == (RESULTPTR) 0)
			return( syntax_error(100) );
		
		/* --------------------------------------- */
		/* Calculate descriptor access information */
		/* --------------------------------------- */
		phase = (n & 1);
		descriptor = (n/2);

		/* ---------------------------------- */
		/* Indicate more parameters to follow */
		/* ---------------------------------- */
		if ( phase )
			NGF.Descriptor[descriptor]     |= 0x0010;
		else if ( descriptor )
			NGF.Descriptor[(descriptor-1)] |= 0x0001;

		if ((lparam = mark_dead_result( lparam )) == (RESULTPTR) 0)
			return( internal_error(6) );
		else	NGF.Parameter[i] = lparam;
	
		/* -------------------------- */  
		/* Establish Parameter Nature */
		/* -------------------------- */  
		if (!( phase ))
			NGF.Descriptor[descriptor]  = (lparam->nature << 5);
		else	NGF.Descriptor[descriptor] |= (lparam->nature << 1);

	}

	i = 0;		

	if ((status = generate_ngf( NGF.Operation )) == 0 ) 
	{
		while ( 1 ) 
		{
			tcputbyte((d = NGF.Descriptor[i]));
			if ( d & 1 )
				i++;
			else	break;
		}
	}
	return(status);
}

/*	-----------------	*/
/*	 flush_parameter	*/
/*	-----------------	*/
static	WORD	flush_parameter(i)
WORD	i;
{
	RESULTPTR	lparam;
	if ((lparam = NGF.Parameter[i]) == (RESULTPTR) 0)
		return( syntax_error(101) );
	else	tcode_operand( lparam );
	return( 0 );
}

/*	-------------	*/
/*	flush_special	*/
/*	-------------	*/
static	WORD	flush_special()
{
	switch ( NGF.Operation ) 
	{
	case	_NGF_LOAD	:
	case	_NGF_INSERT	: 
	case	_NGF_MODIFY	: 
	case	_NGF_DELETE	:
	case	_NGF_SEARCH	: 
	case	_NGF_DOWN	: 
	case	_NGF_UP		: 
	case 	_NGF_CFILE	:		
	case 	_NGF_DFILE	:
	case 	_NGF_ATB	:
	case 	_NGF_COUNT	:
	case	_NGF_POSIT	:
	case	_NGF_COLLECT	:
		tcputbyte( NGF.Special ); 
		break;
	}
	return( 0 );
}

/*	----------------	*/
/*	flush_parameters	*/
/*	----------------	*/
static	WORD	flush_parameters()
{
	WORD		i;
	WORD		status=0;
	if ((NGF.ErrorFlag != MOINS_UN )
	&&  (NGF.Error     != (RESULTPTR) 0)) 
	{
		if ( NGF.ErrorFlag == 1 )
			tcode_label(use_implicite_label((NGF.ErrorAdr = new_implicite_label()) ,0));
		else	tcode_label(use_explicite_label( NGF.ErrorLabel, 0 ));
		tcode_operand( NGF.Error );
	}
	if (((status = flush_parameter(0)) == 0 )
	&&  ((status = flush_special())   == 0 )) 
	{
		for ( i = 1; i < NGF.Parameters; i++ )
			if ((status = flush_parameter(i)) != 0)
				break;
		return( status );
	}
	return( syntax_error(102) );
}

/*	----------------	*/
/*	flush_error_trap	*/
/*	----------------	*/
static	WORD	flush_error_trap()
{
	if ( NGF.ErrorAdr != MOINS_UN )
		return( dcl_implicite_label( NGF.ErrorAdr ) );
	else	return( 0 );
}

/*	--------------	*/
/*	echo_ngf_error	*/
/*	--------------	*/
static	WORD	echo_ngf_error()
{
	WORD	mode=FAUX;
	if ((NGF.ErrorFlag != MOINS_UN )
	&&  (NGF.Error     != (RESULTPTR) 0)) 
	{
		echo_colon();
		if ( NGF.ErrorFlag == 1 )
			echo_string("NEXT");
		else if ( NGF.ErrorFlag == 2 )
			echo_string("BREAK");
		else	echo_string( NGF.ErrorLabel );
		echo_comma();
		echo_operand( NGF.Error );
		mode= VRAI;
	}
	return(mode);
}

/*	-----------	*/
/*	echo_marker	*/
/*	-----------	*/
static	WORD	echo_marker( p )
WORD	p;
{
	if ( NGF.Special & _ISAM_MQ ) 
	{
		echo_comma();
		echo_operand( NGF.Parameter[ p++ ] );
	}
	return( p );
}

/*	--------	*/
/*	echo_cle	*/
/*	--------	*/
static	WORD	echo_cle( p )
WORD	p;
{
	if ( NGF.Special & _ISAM_PI ) 
	{
		echo_comma();
		echo_operand( NGF.Parameter[ p++ ] );
	}
	return( p );
}

/*	-----------	*/
/*	echo_buffer	*/
/*	-----------	*/
static	WORD	echo_buffer( p, m )
WORD	p;
WORD	m;
{
	if ( NGF.Special & _ISAM_DR ) 
	{
		if ( m )
			echo_comma();
		else	echo_colon();
		echo_operand( NGF.Parameter[ p++ ] );
		if ( NGF.Special & _ISAM_DL ) 
		{
			echo_comma();
			echo_operand( NGF.Parameter[ p++ ] );
		}
	}
	return( p );
}

/*	--------------	*/
/*	echo_rw_buffer	*/
/*	--------------	*/
static	VOID	echo_rw_buffer( p, m )
WORD	p;
WORD	m;
{
	RESULTPTR	rptr;
	if (((p+1) < NGF.Parameters )
	&&  ((rptr = NGF.Parameter[p++]) != (RESULTPTR) 0)) 
	{
		if ( m )
			echo_comma();
		else	echo_colon();
		echo_operand( rptr );
		echo_comma();
		echo_operand( NGF.Parameter[ p++ ] );
	}
	return;
}

/*	-------------------	*/
/*	echo_assign_options	*/
/*	-------------------	*/
static	VOID	echo_assign_options( optr )
RESULTPTR	optr;
{
	WORD	result;
	if (optr->nature != _RESULT_INT) 
	{
		echo_comma();
		echo_left_brace();	
		echo_operand( optr );
		echo_right_brace();
	}
	else	
	{
		/* -------------------------- */
		/* file access method options */
		/* -------------------------- */
		result = optr->value;
		if ((result & 0x00F0) == _NGF_SQ) 
		{
			echo_comma();
			echo_string("SQ");
		}
		else if ((result & 0x00F0) == _NGF_SI) 
		{
			echo_comma();
			echo_string("SI");
		}
		else if ((result & 0x00F0) == _NGF_MC) 
		{
			echo_comma();
			echo_string("MC");
		}
		else if ((result & 0x00F0) == _NGF_DB) 
		{
			echo_comma();
			echo_string("DB");
		}
		else if ((result & 0x00F0) == _NGF_SQL) 
		{
			echo_comma();
			echo_string("SQL");
		}
		else if ((result & 0x00F0) == _NGF_XML) 
		{
			echo_comma();
			echo_string("XML");
		}
		else if ((result & 0x00F0) == _NGF_DBF) 
		{
			echo_comma();
			echo_string("MC");
			echo_left_brace();
			echo_operand( NGF.DataBase );
			echo_right_brace();
		}
		else if ((result & 0x00F0) == _NGF_IM) 
		{
			echo_comma();
			echo_string("IM");
		}
		/* -------------------- */
		/* generic file options */
		/* -------------------- */
		if ( result & _NGF_WR ) 
		{
			echo_comma();
			echo_string("WR");
		}
		if ( result & _NGF_EX ) 
		{
			echo_comma();
			echo_string("EX");
		}
		if ( result & _NGF_L ) 
		{
			echo_comma();
			echo_string("L");
		}
		if ( result & _NGF_C ) 
		{
			echo_comma();
			echo_string("C");
		}
		if ( result & _NGF_DF ) 
		{
			echo_comma();
			echo_string("DF");
		}	
	}
	return;

}

/*	----------------	*/
/*	 echo_data_size 	*/
/*	----------------	*/
static	VOID	echo_data_size( rptr )
RESULTPTR	rptr;
{
	echo_comma();
	if ( NGF.Special & _ISAM_VD )
		echo_string("VD");
	else	echo_string("D");
	echo_equals();
	echo_operand( rptr );
	return;
}

/*	-------------	*/
/*	echo_cle_size	*/
/*	-------------	*/
static	VOID	echo_cle_size( rptr )
RESULTPTR	rptr;
{
	echo_comma();
	if ( NGF.Special & _ISAM_RK )
		echo_string("RK");
	else if ( NGF.Special & _ISAM_LK )
		echo_string("LK");
	else	echo_string("K");
	echo_equals();
	echo_operand( rptr );
	return;
}

/*	-------------------	*/
/*	echo_ngf_parameters	*/
/*	-------------------	*/
static	VOID	echo_ngf_parameters( p, mode )
WORD	p;
WORD	mode;
{
	RESULTPTR	rptr;
	while ((rptr = NGF.Parameter[p++]) != (RESULTPTR) 0) 
	{
		if ( mode )
			echo_comma();
		else	echo_colon();
		echo_operand( rptr );
	}
	return;
}

/*	-------------	*/
/*	echo_jointure	*/
/*	-------------	*/
static	WORD	echo_jointure( p )
WORD		p;
{
	RESULTPTR	rptr;
	if ((rptr = NGF.Parameter[p]) != (RESULTPTR) 0) 
	{
		p++;
		if ( rptr->nature != _RESULT_INT) 
		{
			echo_left_brace();
			echo_operand( rptr );
			echo_right_brace();
		}
	}
	return(p);
}

/*	------------------	*/
/*	echo_braced_option	*/
/*	------------------	*/
static	VOID	echo_braced_option( rptr )
RESULTPTR	rptr;
{
	if ( rptr == (RESULTPTR) 0 )
		return;
	else if ( rptr->nature == _RESULT_INT)
		return;
	else if ( rptr->nature != _RESULT_CONST) 
	{
		echo_comma();	
		echo_left_brace();
		echo_left_brace();
		echo_operand( rptr );
		echo_right_brace();
		echo_right_brace();
	}
	else 	
	{
		echo_comma();	
		echo_left_brace();
		echo_constant_symbol( rptr->contents );
		echo_right_brace();
	}
	return;
}

/*	-------------	*/
/*	echo_key_type	*/
/*	-------------	*/
static	WORD	echo_key_type( p )
WORD	p;
{
	RESULTPTR	rptr;
	if ((rptr = NGF.Parameter[p++]) != (RESULTPTR) 0) 
	{
		if ( rptr->nature == _RESULT_INT ) 
		{
			echo_comma();
			switch ( rptr->value ) 
			{
			case	_NGF_KEY_A	:
				echo_string("A"); break;
			case	_NGF_KEY_B	:
				echo_string("B"); 
				if ((rptr = NGF.Parameter[p++]) != (RESULTPTR) 0) 
				{
					echo_comma();
					echo_operand(rptr);
				}
				break;
			case	_NGF_KEY_F	:
				echo_string("F"); break;
			case	_NGF_KEY_N	:
				echo_string("N"); break;
			case	_NGF_KEY_D	:
				echo_string("D"); break;
			case	_NGF_KEY_T	:
				echo_string("T"); break;
			case	_NGF_KEY_L	:
				echo_string("L"); break;
			case	_NGF_KEY_H	:
				echo_string("H"); break;
			case	_NGF_KEY_S	:
				echo_string("S"); break;
			}
		}
	}
	return( p );
}

/*	-----------------	*/
/*	echo_posit_option	*/
/*	-----------------	*/
static	VOID	echo_posit_option()
{
	RESULTPTR	rptr;
	if ((rptr = NGF.Parameter[(NGF.Parameters-1)]) != (RESULTPTR) 0)
		echo_braced_option( rptr );
	return;
}

/*	--------	*/
/*	echo_ngf	*/
/*	--------	*/
static	VOID	echo_ngf()
{
	WORD		a=FAUX;
	WORD		p=0;
	WORD		mode;
	WORD		b=FAUX;
	RESULTPTR	rptr;
	if ((OtrOption.ListFlag & 1)
	&&  (echo_start(VRAI)  )) 
	{
		if (( NGF.Operation != _NGF_ASSIGN )
		||  ( NGF.DataBase  == (RESULTPTR) 0))
			echo_string( get_ngf_keyword((a = NGF.Operation)) );
		else	echo_string( get_ngf_keyword((a = _NGF_FILE   ) ) );
		switch (a) 
		{
		case	_NGF_DOWN		: 
		case	_NGF_UP  		: 
			if ((NGF.Special & _ISAM_ML) == _ISAM_ML)
				echo_string(".ML");
			else if ((NGF.Special & _ISAM_M) == _ISAM_M)
				echo_string(".M");
			else if ((NGF.Special & _ISAM_L) == _ISAM_L)
				echo_string(".L");
			break;
		case	_NGF_SEARCH		:
			if ((NGF.Special & _ISAM_SML) == _ISAM_SML)
				echo_string(".ML");
			else if ((NGF.Special & _ISAM_SM) == _ISAM_SM)
				echo_string(".M");
			else if ((NGF.Special & _ISAM_SL) == _ISAM_SL)
				echo_string(".L");
			break;
		case	_NGF_LOAD		:
			echo_string(".GO");
			break;
		case	_NGF_POSIT		:
		case	_NGF_COUNT		:
			if ( NGF.Special & 1 )
				echo_string(".D");
			break;
		}
		echo_equals();
		echo_operand( NGF.Parameter[p++] );
		switch (a) 
		{
		case	_NGF_CFILE		: 
			if ((rptr = NGF.Parameter[p++]) != (RESULTPTR) 0 ) 
			{
				echo_data_size( rptr );
				if ((rptr = NGF.Parameter[p++]) != (RESULTPTR) 0 )
					echo_cle_size( rptr );
			}
			break;
		case	_NGF_DFILE 		: 
			if ( NGF.Special == 1 ) 
			{
				echo_comma();
				echo_string("(MC)");
			}
			else if ( NGF.Special == 2 ) 
			{
				echo_comma();
				echo_string("(SI)");
			}
			break;
		case	_NGF_RENAME		: 
			echo_comma();
			echo_operand( NGF.Parameter[p++] );
			break;
		case	_NGF_OPEN		: 
		case	_NGF_CLOSE		: 
			break;
		case	_NGF_READ		: 
		case	_NGF_WRITE		: 
			echo_comma();
			echo_operand( NGF.Parameter[p++] );
			echo_comma();
			echo_operand( NGF.Parameter[(NGF.Parameters-1)] );
			b = 2;
			break;
		case	_NGF_FILE		: 
			b = 2;
		case	_NGF_ASSIGN		: 
			echo_comma();
			echo_operand( NGF.Parameter[p++] );
			echo_assign_options(NGF.Parameter[p++]);
			break;
		case	_NGF_LFILE		: 
		case	_NGF_LJOIN		: 
		case	_NGF_LKEY		: 
		case	_NGF_LLINK		: 
		case	_NGF_FIND		: 
			echo_braced_option( NGF.Parameter[p++] );
		case	_NGF_RECORD		: 
		case	_NGF_STATS		: 
			b = VRAI;
			break;
		case	_NGF_CHAIN		: 
		case	_NGF_LOAD		: 
			if ((rptr = NGF.Parameter[p++]) != (RESULTPTR) 0 ) 
			{
				echo_comma();
				echo_operand( rptr );
			}
			break;
		case	_NGF_CKEY		: 
		case	_NGF_RKEY		: 
		case	_NGF_BACKSPACE		: 
		case	_NGF_NAME		: 
		case	_NGF_XCRI		: 
			break;
		case	_NGF_ATB		: 
			if ( NGF.Special & 1 ) 
			{
				echo_comma();
				echo_string("EX");
			}
			if ( NGF.Special & 2 ) 
			{
				echo_comma();
				echo_string("C");
			}
			break;
		case	_NGF_EXTEND		: 
			echo_comma();
			echo_operand( NGF.Parameter[p++] );
			break;
		case	_NGF_MODIFY		: 
		case	_NGF_INSERT		: 
		case	_NGF_SEARCH		: 
			b = VRAI;
		case	_NGF_DELETE		:
			p = echo_cle( p );	
			p = echo_marker( p );
			break;
		case	_NGF_DOWN		: 
		case	_NGF_UP  		: 
			p = echo_marker( p );
			b = VRAI;
			break;
		case	_NGF_RJOIN		: 
			p = echo_jointure( p );
			echo_comma();
			p = echo_jointure( p );
			break;
		case	_NGF_NKEY		: 
			echo_comma();
			echo_operand( NGF.Parameter[p++] );
			echo_comma();
			echo_operand( NGF.Parameter[p++] );
			break;
		case	_NGF_KEY		: 
			echo_comma();
			echo_operand( NGF.Parameter[p++] );
			echo_comma();
			echo_operand( NGF.Parameter[p++] );
			p = echo_key_type(p);
			break;
		case	_NGF_FKEY		: 
			if ((rptr = NGF.Parameter[p++]) != (RESULTPTR) 0 ) 
			{
				echo_comma();
				echo_operand( rptr );
			}
			break;
		case	_NGF_LINK		: 
		case	_NGF_CLINK		: 
			p = echo_jointure( p );
			if ((rptr = NGF.Parameter[p++]) != (RESULTPTR) 0 ) 
			{
				echo_comma();
				echo_operand( rptr );
				echo_braced_option(NGF.Parameter[p++]);
			}
			break;
		case	_NGF_SELECT	:
			p = echo_jointure( p );
			echo_comma();
			echo_operand( NGF.Parameter[p++] );
			echo_comma();
			echo_operand( NGF.Parameter[p++] );
			break;
		case	_NGF_QUERY	:
		case	_NGF_COLLECT	:
			p = echo_jointure( p );
			echo_comma();
			echo_operand( NGF.Parameter[p++] );
			break;
		case	_NGF_POSIT		: 
		case	_NGF_COUNT		: 
			p = echo_jointure( p );
			echo_comma();
			echo_operand( NGF.Parameter[p++] );
			echo_posit_option();
			b = 3;
			break;
		case	_NGF_JOIN		: 
			echo_comma();
			echo_operand( NGF.Parameter[p++] );
			break;
		case	_NGF_DJOIN		: 
		case	_NGF_CJOIN		: 
			p = echo_jointure( p );
			break;
		}
		mode = echo_ngf_error();
		if ( b == 3 ) 
		{
			if ( mode )
				echo_comma();
			else	echo_colon();
			echo_operand( NGF.Parameter[(NGF.Parameters-2)] );
		}
		else if ( b == 2 )
			echo_rw_buffer( p, mode);
		else	
		{
			if ( b )
				p = echo_buffer( p, mode, b );
			echo_ngf_parameters( p, mode );
		}
		echo_line();
	}
	return;
}

/*	---------	*/
/*	flush_ngf	*/
/*	---------	*/
static	WORD	flush_ngf()
{
	WORD	status;
	trace("flush_ngf()\n");
	if ( NGF.Operation == MOINS_UN )
		return( syntax_error(103) );
	else	echo_ngf();
	if (((status = flush_descriptors()) == 0 )
	&&  ((status = flush_parameters())  == 0 )
	&&  ((status = flush_error_trap())  == 0 ))
		return( 0 );
	else	return( status );
}

/*	---------	*/
/*	start_ngf	*/
/*	---------	*/
static	WORD	start_ngf( operation )
WORD		operation;
{
	trace("start_ngf()\n");
	reset_ngf();
	NGF.Operation = operation;
	return(0);
}

/*	---------------		*/
/*	store_parameter 	*/
/*	---------------		*/
static	WORD store_parameter( lparam )
RESULTPTR	lparam;
{

	if ( NGF.Parameters >= 16 )
		return( 103 );

	/* -------------------------- */
	/* And store Parameter Result */
	/* -------------------------- */
	NGF.Parameter[NGF.Parameters++] = mark_live_result( lparam );
	return(0);
}

/*	----------	*/
/*	ngf_handle	*/
/*	----------	*/
static	WORD ngf_handle()
{
	RESULTPTR	handle;
	trace("ngf_handle()\n");
	if (( is_equals() )
	&&  ((handle = evaluate_integer_expression()) != (RESULTPTR) 0))
		return( store_parameter( handle ) );
	else	return( syntax_error(104) );
}

/*	--------------	*/
/*	handle_is_zero	*/
/*	--------------	*/
static	WORD	handle_is_zero()
{
	RESULTPTR	rptr;
	if (((rptr = NGF.Parameter[(NGF.Parameters - 1)]) != (RESULTPTR) 0)
	&&  ( result_is_zero( rptr ) ))
		return( VRAI );
	else	return( FAUX );	
} 

/*	------------	*/
/*	ngf_filename	*/
/*	------------	*/
static	WORD	ngf_filename()
{
	RESULTPTR	filename;
	trace("ngf_filename()\n");
	if (( is_comma() )
	&&  ((filename = evaluate_expression(0)) != (RESULTPTR) 0))
		return( store_parameter( filename ) );
	else	return( syntax_error(105) );
}

/*	------------	*/
/*	chain_option	*/
/*	------------	*/
static	WORD	chain_option()
{
	RESULTPTR	filename;
	trace("ngf_filename()\n");
	if ( is_comma() ) 
	{
		if ((filename = evaluate_expression(0)) != (RESULTPTR) 0)
			return( store_parameter( filename ) );
		else	return( syntax_error(106) );
	}
	else	return( 0 );
}

/*	----------------	*/
/*	assign_mnemonics	*/
/*	----------------	*/
static	RESULTPTR	assign_mnemonics()
{
	WORD		canvar=1;
	WORD		result=0;
	RESULTPTR	options=(RESULTPTR) 0;

	if (( OtrOption.Enhanced & _ENHANCED_ASSIGN ) &&  ( is_left_brace() )) 
	{
		options = evaluate_expression(0);
		if (!(is_right_brace()))
			return( (RESULTPTR) 0 );
		else	return( options );
	}
	else	
	{
		do	
		{
			if ( is_mnemonic("WR") )
				result |= _NGF_WR;
			else if ( is_mnemonic("EX") )
				result |= _NGF_EX;
			else if ( is_mnemonic("C") )
				result |= _NGF_C;
			else if ( is_mnemonic("L") )
				result |= _NGF_L;
			else if ( is_mnemonic("DF") )
				result |= _NGF_DF;
			else if ( is_mnemonic("WO") )
				result |= (_NGF_DF | _NGF_WR);
			else if ( is_mnemonic("SQ") )
				result |= _NGF_SQ;
			else if ( is_mnemonic("SI") )
				result |= _NGF_SI;
			else if ( is_mnemonic("SQL") )
				result |= _NGF_SQL;
			else if ( is_mnemonic("XML") )
				result |= _NGF_XML;
			else if ( is_mnemonic("MC") ) 
			{
				result |= _NGF_MC;
				if ( is_left_brace() ) 
				{
					result &= ~_NGF_MC;
					result |= _NGF_DBF;
					NGF.DataBase = evaluate_integer_expression();
					if (!( is_right_brace()))
						return( (RESULTPTR) 0 );
				}
			}
			else if ( is_mnemonic("DB") )
				result |= _NGF_DB;
			else if ( is_mnemonic("DBF") ) 
			{
				result |= _NGF_DBF;
				if ( is_left_brace() ) 
				{
					NGF.DataBase = evaluate_integer_expression();
					if (!( is_right_brace()))
						return( (RESULTPTR) 0 );	
				}
				else	return( (RESULTPTR) 0 );
			}
			else if ( is_mnemonic("DV") )
				result |= _NGF_DV;
			else if ( is_mnemonic("GR") )
				result |= _NGF_GR;
			else if ( is_mnemonic("IM") )
				result |= _NGF_IM;
			else if ( is_mnemonic("IPC") )
				result |= _NGF_IPC;
			else if (!( canvar ))
				return( (RESULTPTR) 0 );
			else  	return( evaluate_expression(0) );
			canvar=0;
		}
		while ( is_comma() );
	}
	return( integer_result( result ) );
}

/*	------------------	*/
/*	ngf_assign_options	*/
/*	------------------	*/
static	WORD	ngf_assign_options(operation)
WORD	operation;
{
	WORD		flags;
	RESULTPTR	options;
	trace("ngf_assign_options()\n");
	if ( is_comma() )
		options = assign_mnemonics();
	else	options = integer_result(0);
	if ( options != (RESULTPTR) 0)
		return( store_parameter( options ) );
	else	return( syntax_error(108) );
}

/*	----------	*/
/*	sf_options	*/
/*	----------	*/
static	WORD	sf_options()
{
	RESULTPTR	options;
	trace("sf_options()\n");
	if ( is_comma() )
		options = evaluate_integer_expression();
	else	options = integer_result( (NGF.Operation == _NGF_READ ? _SQ_READ : _SQ_WRITE ) );
	if ( options != (RESULTPTR) 0)
		return( store_parameter( options ) );
	else	return( syntax_error(109) );
}

/*	----------	*/
/*	ngf_sector	*/
/*	----------	*/
static	RESULTPTR	ngf_sector( sector )
WORD	sector;
{
	trace("ngf_sector()\n");
	if ( is_comma() )
		return( evaluate_expression(0) );
	else	return( integer_result( sector ) );

}

/*	-------------------	*/
/*	ngf_explicite_label	*/
/*	-------------------	*/
WORD	ngf_explicite_label()
{
	if ( get_label() ) 
	{
		NGF.ErrorFlag = 0;
		strcpy(NGF.ErrorLabel,TokenBuffer);
		if ( is_comma() )
			return(0);
	}
	return( syntax_error(110) );
}

/*	-------------------	*/
/*	ngf_implicite_label	*/
/*	-------------------	*/
WORD	ngf_implicite_label(nature)
WORD	nature;
{
	NGF.ErrorFlag = nature;
	if ( is_comma() )
		return( 0 );
	else	return( syntax_error(111) );
}

/*	----------------	*/
/*	is_mnemonic_next	*/
/*	----------------	*/
WORD	is_mnemonic_next()
{
	return( is_mnemonic("NEXT") );
}

/*	-----------------	*/
/*	is_mnemonic_break	*/
/*	-----------------	*/
WORD	is_mnemonic_break()
{
	return( is_mnemonic("BREAK") );
}

/*	-----------------	*/
/*	is_mnemonic_label	*/
/*	-----------------	*/
WORD	is_mnemonic_label()
{
	if (is_mnemonic_next())
		return(1);
	else if (is_mnemonic_break())
		return(2);
	else	return(FAUX );
}

/*	--------------	*/
/*	ngf_error_trap	*/
/*	--------------	*/
static	WORD	ngf_error_trap()
{
	WORD	status=0;
	trace("ngf_error_trap()\n");
	if ( colon_check() ) 
	{
		if ((status = is_ampersand()) != FAUX ) { 
		 
			unget_byte();
			if (ngf_explicite_label() != 0)
				return( syntax_error(112) );
		}
		else if ((status = is_mnemonic_label()) != FAUX) 
		{
			if ( ngf_implicite_label(status) != 0 )
				return( syntax_error(113) );
		}
		if (( status )
		&&  ((NGF.Error = evaluate_expression(0)) == (RESULTPTR) 0))
			return(syntax_error(114));
	}
	return(0);
}

/*	--------------------	*/
/*	translate_index_size	*/
/*	--------------------	*/
static WORD	translate_index_size()
{
	RESULTPTR	rptr=(RESULTPTR) 0;
	if ( remove_white_space() ) 
	{
		if ( is_mnemonic("LK") )
			NGF.Special |= _ISAM_LK;
		else if ( is_mnemonic("RK") )
			NGF.Special |= _ISAM_RK;
		else if (!(is_mnemonic("K")))
	  		return( syntax_error(115) );
		if ( is_equals() )
			rptr = evaluate_integer_expression();
		else	rptr = integer_result(16);
		return( store_parameter( rptr ) );
	}
	return(0);
}

/*	-------------------	*/
/*	translate_data_size	*/
/*	-------------------	*/
static RESULTPTR	translate_data_size()
{
	RESULTPTR	rptr=(RESULTPTR) 0;

	if ( remove_white_space() ) 
	{
		if ( is_mnemonic("VD") ) 
		{
			NGF.Special |= _ISAM_VD;
			if (!( is_equals() )) 
			{
				if (!( rptr = integer_result(4)))
					syntax_error( 8115 );
				else	return( rptr );
			}
			else if (!( rptr = evaluate_integer_expression() )) 
			{
				syntax_error( 8116 );
				return((RESULTPTR) 0 );
			}
			else	return( rptr );
		}
		else if (!(is_mnemonic("D")))
			return((RESULTPTR) 0 );
		else	
		{
			if (!( is_equals() )) 
			{
				syntax_error( 8115 );
				return((RESULTPTR) 0 );
			}
			else if (!( rptr = evaluate_integer_expression() )) 
			{
				syntax_error( 8116 );
				return((RESULTPTR) 0 );
			}
			else	return( rptr );
		}
	}
	return((RESULTPTR) 0 );
}

/*	---------	*/
/*	ngf_sizes	*/
/*	---------	*/
static	WORD	ngf_sizes()
{
	RESULTPTR dptr=(RESULTPTR) 0;
	WORD	status;

	if (!( is_comma() )) { return(0); }

	if ((dptr = translate_data_size()) != (RESULTPTR) 0) 
	{
		if (!( is_comma())) 
		{
			/* -------------- */
			/* D=datalen only */
			/* -------------- */
			if (( status = store_parameter( dptr )) != 0)
				return( status );
			else	return(0);
		}
	}
	else if (!( dptr = integer_result(0)))
		internal_error( 8117 );
	/* -------------------- */
	/* D=datalen, K=datalen */
	/* -------------------- */
	if (( status = store_parameter( dptr )) != 0)
		return( status );
	else	return( translate_index_size() );
}

/*	----------	*/
/*	ngf_length	*/
/*	----------	*/
static	WORD	ngf_length(l)
WORD	l;
{
	RESULTPTR	length;
	trace("ngf_length()\n");
	if ( is_comma() ) 
	{
		if ((length = evaluate_integer_expression()) == (RESULTPTR) 0)
			return( syntax_error(116) );
		else	return( store_parameter( length ) );
	}	
	else	return(store_parameter( integer_result( l ) ) );
}

/*	----------------	*/
/*	check_ngf_buffer	*/
/*	----------------	*/
static	RESULTPTR	check_ngf_buffer( rptr )
	RESULTPTR	rptr;
{
	if (!( rptr ))
		return( rptr );
	if ((rptr->nature & _RESULT_BASIC) == _RESULT_VARB)
		rptr->nature |= _RESULT_VPT;
	return( rptr );
}

/*	---------------------	*/
/*	ngf_buffer_and_length	*/
/*	---------------------	*/
static	WORD	ngf_buffer_and_length(int mode)
{
	RESULTPTR	buffer;
	WORD		status;
	TCVARPTR	vptr;
	TCCONPTR	cptr;
	WORD		l;
	if ((buffer = evaluate_expression(0)) == (RESULTPTR) 0)
		return( mode );
	else	buffer = check_ngf_buffer( buffer );
	if ((status = store_parameter( buffer )) != 0)
		return( status );
	if ((buffer->nature & _RESULT_BASIC) == _RESULT_VARB) 
	{
		if (((vptr = (TCVARPTR) buffer->contents) != (TCVARPTR) 0)
		&&  ( vptr->type != (TCTYPPTR) 0))
			l = vptr->type->size;
		else	l = 0;
	}
	else if ((buffer->nature & _RESULT_BASIC) == _RESULT_CONST) 
		{
		if ((cptr = (TCCONPTR) buffer->contents) != (TCCONPTR) 0)
			l = cptr->length;
		else	l = 0;
	}
	else	l=0;
	return( ngf_length(l) );
}

/*	----------	*/
/*	ngf_buffer	*/
/*	----------	*/
static	WORD	ngf_buffer()
{
	trace("ngf_buffer()\n");
	if ( NGF.Error != (RESULTPTR) 0) 
	{
		if (!( is_comma() ))
			return(0);
		else if (!(ngf_buffer_and_length(1)))
		return(0);
		else	return( syntax_error( 234 ) );
	}
	else	return( ngf_buffer_and_length(0) );
}

/*	------------	*/
/*	load_options	*/
/*	------------	*/
static	WORD	load_options(opcode)
WORD	opcode;
{
	RESULTPTR	filename;
	WORD		status;

	trace("load_options()\n");
	if (( opcode == _NGF_LOAD )
	&&  ( is_comma() 	  )) 
	{
		if (!( is_left_brace())) 
		{
			/* ---------------------- */
			/* command line parameter */
			/* ---------------------- */
			if (!(filename = evaluate_expression(0)))
				return( syntax_error(106) );
			else if ((status = store_parameter( filename )) != 0)
				return(status );
			else if (!( is_comma() ))
				return(0);
			else if (!( is_left_brace()))
				return( syntax_error(118) );
		}
		/* --------------------- */
		/* load.go braced option */
		/* --------------------- */
		remove_white_space();
#ifdef	ABAL32A
		if ( is_mnemonic("R") ) 
		{
			NGF.Special = 1;
		}
		else if ( is_mnemonic("TASK") ) 
		{
			NGF.Special = 2;
		}
		else if ( is_mnemonic("CAPTURE") ) 
		{
			NGF.Special = 4;
		}
		else 	return( syntax_error(117) );
#else
		switch ( get_byte() ) 
		{
		case 'R' :
		case 'r' :
			NGF.Special = 1;
			break;
		default	 :
			return( syntax_error(117) );
		}
#endif
		if (!( is_right_brace() ))
			return( unmatched_braces() );

	}
	return( 0 );
}

/*	------------	*/
/*	find_options	*/
/*	------------	*/
static	WORD	find_options()
{
	RESULTPTR	rptr;
	trace("find_options()\n");
	if ( is_comma() ) 
	{
		if ( is_left_brace() ) 
		{
			if ( is_left_brace() ) 
			{
				if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
					return( syntax_error(119) );
				if (!(is_right_brace()))
					return( unmatched_braces() );
			}
			else 	
			{
				(void) get_byte();
				if ((rptr = implicite_constant(3)) == (RESULTPTR) 0)
					return( syntax_error(120) );
			}
			if (!(is_right_brace()))
				return( unmatched_braces() );
			else	return( store_parameter( rptr ) );
		}
		else	return( syntax_error(121) );
	}
	return(store_parameter( integer_result( 0 ) ) );
}

/*	--------------------------------------------------------	*/
/*	TRANSLATION of INDIVIDUAL and GROUPED  NGF  INSTRUCTIONS	*/
/*	--------------------------------------------------------	*/

/*	----------------	*/
/*	translate_assign	*/
/*	----------------	*/
WORD	translate_assign(operation)
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( _NGF_ASSIGN ))	== 0 )
	&&  ((status = ngf_handle())			== 0 )
	&&  ((status = ngf_filename())			== 0 )
	&&  ((status = ngf_assign_options(operation))	== 0 )
	&&  ((status = ngf_error_trap())		== 0 )
	&&  ((status = ngf_buffer())			== 0 )) 
	{
		if (( NGF.DataBase != (RESULTPTR) 0)
		&&  ((status = store_parameter( NGF.DataBase )) != 0))
			return( status );
		else	return( flush_ngf() );
	}
	else	return( status      );
}

/*	-----------------	*/
/*	translate_load_go	*/
/*	-----------------	*/
WORD	translate_load_go(operation)
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation ))	== 0 )
	&&  ((status = ngf_handle())		== 0 )
	&&  ((status = load_options(operation))	== 0 )
	&&  ((status = ngf_error_trap())	== 0 ))
		return( flush_ngf() );
	else	return( status      );
}

/*	-------------------	*/
/*	translate_ngf_chain	*/
/*	-------------------	*/
WORD	translate_ngf_chain(operation)
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation ))	== 0 )
	&&  ((status = ngf_handle())		== 0 )
	&&  ((status = chain_option())		== 0 )
	&&  ((status = ngf_error_trap())	== 0 ))
		return( flush_ngf() );
	else	return( status      );
}

/*	----------------	*/
/*	 translate_find 	*/
/*	----------------	*/
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

/*	-----------------	*/
/*	 translate_cfile	*/
/*	-----------------	*/
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

/*	-------------	*/
/*	dfile_options	*/
/*	-------------	*/
static	WORD	dfile_options()
{
	if (!( is_comma() ))
		return( 0 );
	else if (!( is_left_brace() ))
		return( syntax_error(122) );
	else if ( is_mnemonic("MC") )
		NGF.Special = 1;
	else if ( is_mnemonic("SI") )
		NGF.Special = 2;
	else	return( syntax_error(123) );
	if (!( is_right_brace() ))
		return( unmatched_braces() );
	else	return( 0 );
}

/*	-----------------	*/
/*	 translate_dfile	*/
/*	-----------------	*/
WORD	translate_dfile(operation)
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation )) == 0 )
	&&  ((status = ngf_handle())           == 0 )
	&&  ((status = dfile_options())	       == 0 )
	&&  ((status = ngf_error_trap())       == 0 ))
		return( flush_ngf() );
	else	return( status      );
}

/*	----------------	*/
/*	translate_rename	*/
/*	----------------	*/
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

/*	--------------------	*/
/*	translate_open_close	*/
/*	--------------------	*/
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

/*	--------------------	*/
/*	translate_read_write	*/
/*	--------------------	*/
WORD	translate_read_write(operation)
WORD	operation;
{
	WORD		status;
	RESULTPTR	sector;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )) 
	{
		if (handle_is_zero())
			return( translate_read_data() );
		else 	if (((status = sf_options())		== 0 )
			&&  ((sector = ngf_sector(0)) != (RESULTPTR) 0)
			&&  ((status = ngf_error_trap())       	== 0 )
			&&  ((status = ngf_buffer())		== 0 )
			&&  ((status = store_parameter(sector))	== 0 ))
				return( flush_ngf() );
			else	return( status      );
	}
	else	return( status      );

}

/*	------------------------------------	*/
/*	TRANSLATION of I.S.A.M	Instructions	*/
/*	------------------------------------	*/

/*	--------------	*/
/*	updown_postfix	*/
/*	--------------	*/
static	WORD	updown_postfix()
{
	if (( is_period() )
	&&  ( remove_white_space() )) 
	{
		if ( is_mnemonic("M") )
			NGF.Special |= _ISAM_M;
		else if ( is_mnemonic("L") )
			NGF.Special |= _ISAM_L;
		else if ( is_mnemonic("ML") )
			NGF.Special |= _ISAM_ML;
		else	return( syntax_error(124) );
	}
	return( 0 );

}

/*	--------------	*/
/*	search_postfix	*/
/*	--------------	*/
static	WORD	search_postfix()
{
	if (( is_period() )
	&&  ( remove_white_space() )) 
	{
		if ( is_mnemonic("M") )
			NGF.Special |= _ISAM_SM;
		else if ( is_mnemonic("L") )
			NGF.Special |= _ISAM_SL;
		else if ( is_mnemonic("ML") )
			NGF.Special |= _ISAM_SML;
		else	return( syntax_error(125) );
	}
	return( 0 );
}

/*	------------------	*/
/*	isam_primary_index	*/
/*	------------------	*/
static	WORD	isam_primary_index()
{
	WORD	status;
	if (( NGF.Operation != _NGF_UP   )
	&&  ( NGF.Operation != _NGF_DOWN )) 
	{
		if (!( is_comma()))
			return( syntax_error(126) );
		if ((status = store_parameter( evaluate_expression(0) )) != 0)
			return( status );
		else	NGF.Special |= _ISAM_PI;
	}
	if ( is_comma() ) 
	{
		if ((status = store_parameter( evaluate_expression(0) )) != 0)
			return( status );
		else	NGF.Special |= _ISAM_MQ;
	}
	return(0);
}

/*	----------------	*/
/*	isam_data_record	*/
/*	----------------	*/
static	WORD	isam_data_record()
{
	WORD	status=0;
	WORD	mode=0;
	if ( NGF.Operation != _NGF_DELETE ) 
	{
		if ( remove_white_space() ) 
		{
			if (( is_comma()    )
			||  ((mode = is_colon()) != 0)
			||  ( colon_check() )) 
			{
				if ( mode )
					NGF.Colon = VRAI;
				if ((status = store_parameter( check_ngf_buffer ( evaluate_expression(0) ) )) != 0)
					return( status );
				else	NGF.Special |= _ISAM_DR;
				if (( is_comma() )
				&&  ((status = store_parameter( evaluate_expression(0) )) == 0))
					NGF.Special |= _ISAM_DL;
				return( status );
			}
		}
		if (( NGF.Operation != _NGF_RECORD )
		/* ------------------------------------ */
		/* IJM 17/10/2001			*/
		/* ------------------------------------ */
		/* The next three have been allowed 	*/
		/* for several reasons :		*/
		/* 1) index only files with no data	*/
		/* 2) search operations to free locks	*/
		/* ------------------------------------ */
		&&  ( NGF.Operation != _NGF_SEARCH )
		&&  ( NGF.Operation != _NGF_INSERT )
		&&  ( NGF.Operation != _NGF_MODIFY )
		&&  ( NGF.Operation != _NGF_DOWN   )
		&&  ( NGF.Operation != _NGF_UP     ))
			return( syntax_error(127) );
	}
	return(status);
}

/*	--------------	*/
/*	translate_isam	*/
/*	--------------	*/
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

/*	----------------	*/
/*	translate_insert	*/
/*	----------------	*/
static	WORD	translate_insert( operation )
WORD	operation;
{
	WORD	status;
	if ((status = start_ngf( operation )) 	== 0 )
		return( translate_isam() );
	else	return(	status );
}

/*	-------------------	*/
/*	translate_sq_modify	*/
/*	-------------------	*/
static	WORD	translate_sq_modify( operation )
{
	RESULTPTR	rptr;
	WORD		status;
	NGF.Operation = _NGF_WRITE;
	if (!( rptr = integer_result( _SQ_MODIF ) ))
		return( report_error( 9009 ) );
	else if ((status = store_parameter( rptr )) != 0)
		return( status );
	else if (((status = ngf_error_trap())   == 0 )
	     &&  ((status = ngf_buffer())	== 0 )
	     &&  ((rptr   = integer_result(0)) != (RESULTPTR) 0)
	     &&  ((status = store_parameter( rptr )) == 0))
		return( flush_ngf() );
	else	return( status      );
}

/*	----------------	*/
/*	translate_modify	*/
/*	----------------	*/
static	WORD	translate_modify( operation )
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )) 
	{
		if (!( is_comma() ))
			return( translate_sq_modify() );
		unget_byte();
		if ((status = isam_primary_index()) != 0 )
			return( status );
		if (((status = ngf_error_trap())       	== 0 )
		&&  ((status = isam_data_record())	== 0 ))
			return( flush_ngf() );
		else	return( status      );
	}
	else	return( status );
}

/*	----------------	*/
/*	translate_search	*/
/*	----------------	*/
static	WORD	translate_search( operation )
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = search_postfix())	== 0 ))
		return( translate_isam() );
	else	return( status );
}

/*	-----------------	*/
/*	translate_up_down	*/
/*	-----------------	*/
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

/*	--------	*/
/*	ngf_list	*/
/*	--------	*/
WORD	ngf_list()
{
	if (!(is_comma()))
		return(30);
	else 	return( store_parameter( evaluate_expression(3) ) );
}

/*	-----------	*/
/*	ngf_operand	*/
/*	-----------	*/
WORD	ngf_operand()
{
	if (!(is_comma()))
		return(30);
	else 	return( store_parameter( evaluate_expression(0) ) );
}

/*	-------------	*/
/*	result_format	*/
/*	-------------	*/
WORD	result_format()
{
	if (!( is_comma() ))
	 	return( store_parameter(integer_result(0)) );
	else if ( is_mnemonic( "TEXT" ))
	 	return( store_parameter(integer_result(0)) );
	else if ( is_mnemonic( "BINARY" ))
	 	return( store_parameter(integer_result(1)) );
	else 	return( store_parameter(evaluate_expression(0)) );
}

/*	--------	*/
/*	key_type	*/
/*	--------	*/
WORD	key_type()
{
	if (!(is_comma())) 
		return( store_parameter( integer_result( _NGF_KEY_A ) ) );
	else if ( is_mnemonic( "A" ) )
		return( store_parameter( integer_result( _NGF_KEY_A ) ) );
	else if ( is_mnemonic( "B" ) )
		return( store_parameter( integer_result( _NGF_KEY_B ) ) );
	else if ( is_mnemonic( "N" ) )
		return( store_parameter( integer_result( _NGF_KEY_N ) ) );
	else if ( is_mnemonic( "F" ) )
		return( store_parameter( integer_result( _NGF_KEY_F ) ) );
	else if ( is_mnemonic( "L" ) )
		return( store_parameter( integer_result( _NGF_KEY_L ) ) );
	else if ( is_mnemonic( "H" ) )
		return( store_parameter( integer_result( _NGF_KEY_H ) ) );
	else if ( is_mnemonic( "S" ) )
		return( store_parameter( integer_result( _NGF_KEY_S ) ) );
	else if ( is_mnemonic( "D" ) )
		return( store_parameter( integer_result( _NGF_KEY_D ) ) );
	else if ( is_mnemonic( "T" ) )
		return( store_parameter( integer_result( _NGF_KEY_T ) ) );
	else	return( store_parameter( evaluate_integer_expression() ) );
}

/*	-------------	*/
/*	translate_key	*/
/*	-------------	*/
WORD	translate_key( operation )
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )) 
	{
		switch ( operation ) 
		{
		case _NGF_KEY :
			if ((status = ngf_operand()) != 0)
				return( syntax_error(128) );
			else if ((status = ngf_operand()) != 0)
				return( syntax_error(129) );
			else if ((status = key_type()) != 0 )
				return( syntax_error(130) );
			while ( ngf_operand() == 0 );
			break;

		case _NGF_NKEY :
			if ((status = ngf_operand()) != 0)
				return( syntax_error(131) );
			else if ((status = ngf_operand()) != 0)
				return( syntax_error(132) );
			else	break;

		case _NGF_FKEY :
			(void) ngf_operand();
			break;
		default		:
			return( syntax_error(133) );
		}
		if ((status = ngf_error_trap())       	== 0 )
			return( flush_ngf() );
	}
	return( status      );
}

/*	-------------------------	*/
/*	collect_possible_jointure	*/
/*	-------------------------	*/
WORD	collect_possible_jointure(mode)
WORD	mode;
{
	WORD	status;
	if ( is_left_brace() ) 
	{
		if ((status = store_parameter( evaluate_expression(0) )) != 0 )
			return( status );
		else if (!( is_right_brace()))
			return( unmatched_braces() );
	}
	else if ( mode ) 
	{
		/* ---------------------------------------------------- */
		/* Called from LINK and CLINK : Requires dummy Jointure */
		/* ---------------------------------------------------- */
		if ((status = store_parameter( integer_result(0) )) != 0)
			return( status );
	}
	return( 0 );
}

/*	--------------	*/
/*	translate_join	*/
/*	--------------	*/
WORD	translate_join( operation )
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = collect_possible_jointure(0)) == 0 )) 
	{
		switch ( operation ) 
		{
		case _NGF_RJOIN :
			if (!(is_comma()))
				return( syntax_error(134) );
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
			return( syntax_error(135) );
		}
		if ((status = ngf_error_trap()) == 0 )
			return( flush_ngf() );
		else	return( status );
	}
	else	return( status      );
}

/*	--------------	*/
/*	translate_list	*/
/*	--------------	*/
WORD	translate_list( operation )
WORD	operation;
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = find_options())		== 0 )
	&&  ((status = ngf_error_trap())       	== 0 )
	&&  ((status = isam_data_record())	== 0 ))
		return( flush_ngf() );
	else	return( status      );
}

/*	-----------	*/
/*	link_option	*/
/*	-----------	*/
WORD	link_option()
{
	WORD	status;
	if (is_comma()) 
	{
		trace("link_option()\n");
		if  (is_left_brace()) 
		{
			if ( is_left_brace() ) 
			{
				if ((status = store_parameter( evaluate_expression(0) )) != 0)
					return( status );
				else if (!(is_right_brace()))
					return( unmatched_braces() );
			}
			else	
			{
				if ( is_mnemonic( "A" ) ) 
				{
					if ((status = store_parameter(build_string_constant( allocate_for_result(), "A" ) )) != 0)
						return( status );
				}
				else if ( is_mnemonic( "D" ) ) 
				{
					if ((status = store_parameter(build_string_constant( allocate_for_result(), "D" ) )) != 0)
						return( status );
				}
				else	return( syntax_error(136) );
			}
			if (!(is_right_brace()))
				return( unmatched_braces() );
			else	return( 0 );
		}
		else	return( store_parameter( evaluate_expression(0) ) );
	}
	else	return( store_parameter( integer_result( 0 ) ) );
}

/*	--------------	*/
/*	translate_link	*/
/*	--------------	*/
WORD	translate_link( operation )
WORD	operation;
{
	WORD	status;
	trace("translate_link()\n");
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )) 
	{
		if ((status = collect_possible_jointure(1)) != 0 )
			return( status );
		if ((status = ngf_operand()) == 0)
			if ((status = link_option()) != 0)
				return( status );
		if ((status = ngf_error_trap()) == 0 )
			return( flush_ngf() );
	}
	return( status      );
}

/*	------------	*/
/*	posit_option	*/
/*	------------	*/
WORD	posit_option()
{
	if ( is_period() ) 
	{
		if ( is_mnemonic("D") )
			NGF.Special = 1;
		else	return( syntax_error(137) );
	}
	return( 0 );
}

/*	-----------------	*/
/*	question_jointure	*/
/*	-----------------	*/
WORD	question_jointure()
{
	WORD	status;
	if ( is_left_brace() ) 
	{
		if ((status = store_parameter( evaluate_expression(0) )) != 0)
			return( status );
		else if (!(is_right_brace()))
			return( unmatched_braces() );
		else	return( 0 );
	}
	else	return( store_parameter( integer_result( 0 ) ) );
}

/*	-----------------	*/
/*	 question_option	*/
/*	-----------------	*/
RESULTPTR	question_option()
{
	RESULTPTR	rptr;

	if (is_comma()) 
	{
		trace("link_option()\n");
		if  (is_left_brace()) 
		{
			if ( is_left_brace() ) 
			{
				if ((rptr = evaluate_expression(0)) == 0)
					return( rptr );
				else if (!(is_right_brace()))
					return((RESULTPTR) 0);
			}
			else	
			{
				if ( is_mnemonic( "U" ) ) 
				{
					if ((rptr = build_string_constant( allocate_for_result(), "U" )) == (RESULTPTR) 0)
						return( rptr );
				}
				else if ( is_mnemonic( "S" ) ) 
				{
					if ((rptr = build_string_constant( allocate_for_result(), "S" )) == (RESULTPTR) 0)
						return( rptr );
				}
				else	return((RESULTPTR) 0 );
			}
			if (!(is_right_brace()))
				return((RESULTPTR) 0);
			else	return( rptr );
		}
		else	return( evaluate_expression(0) );
	}
	else	return( integer_result( 0 ) );
}

/*	-----------------	*/
/*	 question_target	*/
/*	-----------------	*/
WORD	question_target()
{
	(void) is_comma();
	return( store_parameter(evaluate_expression(0)) );
}

/*	-----------------	*/
/*	 question_result	*/
/*	-----------------	*/
WORD	question_result()
{
	(void) is_comma();
	return( store_parameter(evaluate_expression(0)) );
}

/*	--------------------	*/
/*	translate_inxs_query	*/
/*	--------------------	*/
WORD	translate_inxs_query( operation )
{
	WORD		status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_error_trap())       	== 0 ))
		return( flush_ngf() );
	else	return( status      );
}

/*	------------------	*/
/*	translate_question	*/
/*	------------------	*/
WORD	translate_question( operation )
WORD	operation;
{
	WORD		status;
	RESULTPTR	qptr;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = posit_option())		== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = question_jointure())	== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((qptr   = question_option()) != (RESULTPTR) 0)
	&&  ((status = ngf_error_trap())       	== 0 )
	&&  ((status = question_target())       == 0 )
	&&  ((status = store_parameter(qptr))   == 0 ))
		return( flush_ngf() );
	else	return( status      );
}

/*	---------------------	*/
/*	translate_inxs_select	*/
/*	---------------------	*/
WORD	translate_inxs_select( operation )
WORD	operation;
{
	WORD		status;
	RESULTPTR	qptr;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = posit_option())		== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = question_jointure())	== 0 )
	&&  ((status = ngf_list())		== 0 )
	&&  ((qptr   = question_option()) != (RESULTPTR) 0)
	&&  ((status = ngf_error_trap())       	== 0 )
	&&  ((status = question_target())       == 0 )
	&&  ((status = question_result())       == 0 )
	&&  ((status = store_parameter(qptr))   == 0 ))
		return( flush_ngf() );
	else	return( status      );
}

/*	-----------------	*/
/*	translate_collect	*/
/*	-----------------	*/
WORD	translate_collect( operation )
WORD	operation;
{
	WORD		status;
	RESULTPTR	qptr;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = posit_option())		== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = question_jointure())	== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((qptr   = question_option()) != (RESULTPTR) 0)
	&&  ((status = ngf_error_trap())       	== 0 )
	&&  ((status = question_target())       == 0 )
	&&  ((status = question_result())       == 0 )
	&&  ((status = store_parameter(qptr))   == 0 ))
		return( flush_ngf() );
	else	return( status      );
}

/*	-----------	*/
/*	atb_options	*/
/*	-----------	*/
WORD	atb_options()
{
	NGF.Special = 0;
	while ( 1 ) 
	{
		if (!( is_comma() ))
			return( 0 );
		else if ( is_mnemonic( "EX" ) )
			NGF.Special |= 1;
		else if ( is_mnemonic( "C"  ) )
			NGF.Special |= 2;
		else	return( syntax_error(138) );
	}
}

/*	----------------	*/
/*	translate_divers	*/
/*	----------------	*/
WORD	translate_divers( operation )
WORD	operation;
{
	WORD		status;
	RESULTPTR	sector;
	RESULTPTR	option;
	if (((status = start_ngf( operation )) == 0 )
	&&  ((status = ngf_handle())           == 0 )) 
	{
		switch ( NGF.Operation ) 
		{
		case _NGF_XCRI	:
			if (!( is_comma() ))
				return( syntax_error(9800) );
			else if ((status = ngf_buffer_and_length(1)) != 0)
				return( status );
			else	break;

		case _NGF_EXTEND :
			if (((sector = ngf_sector(16)) != (RESULTPTR) 0 )
			&&  ((status = store_parameter(sector))	== 0 ))
				break;
			else	return( status );

		case _NGF_ATB	 :
			if ((status = atb_options()) != 0)
				return( status );
			else	break;

		case	_NGF_STATS 	: 
			if (((option = integer_result(0)) != (RESULTPTR) 0 )
			&&  ((status = store_parameter(option))	== 0 ))
				break;
			else	return( status );

		}
		if ((status = ngf_error_trap()) == 0 ) 
		{
			switch ( NGF.Operation ) 
			{
			case	_NGF_XCRI	:
				if (( status = ngf_buffer()) != 0)
					return( status );
				else	break;

			case	_NGF_STATS 	: 
			case	_NGF_NAME  	: 
			case	_NGF_RECORD	: 
				if ((status = isam_data_record()) != 0 )
					return( status );
			}
			return( flush_ngf() );
		}
	}
	return( status );
}

#ifdef	PRJ918
/*	-----------------	*/
/*	 session_options	*/
/*	-----------------	*/
static	WORD	session_options()
{
	RESULTPTR	rptr;
	trace("session_options()\n");
	if ( is_comma() ) 
	{
		if ( is_left_brace() ) 
		{
			if ( is_left_brace() ) 
			{
				if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
					return( syntax_error(119) );
				if (!(is_right_brace()))
					return( unmatched_braces() );
			}
			else 	
			{
				(void) get_byte();
				if ((rptr = implicite_constant(3)) == (RESULTPTR) 0)
					return( syntax_error(120) );
			}
			if (!(is_right_brace()))
				return( unmatched_braces() );
			else	return( store_parameter( rptr ) );
		}
		else	return( syntax_error(121) );
	}
	return(store_parameter( integer_result( 0 ) ) );
}

/*	-----------------	*/
/*	 session_operand	*/
/*	-----------------	*/
static	WORD	session_operand()
{
	WORD	status;
	if ((status = ngf_operand()) == 30)
		return(0);
	else	return(status);
}

/*	-----------------	*/
/*	translate_session	*/
/*	-----------------	*/
static	WORD	translate_session(WORD operation)
{
	WORD	status;
	trace("translate_session()\n");
	if (((status = start_ngf( operation ))	== 0 )
	&&  ((status = ngf_handle())		== 0 )
	&&  ((status = session_options())	== 0 )
	&&  ((status = session_operand())	== 0 )
	&&  ((status = ngf_error_trap())	== 0 )
	&&  ((status = ngf_buffer())		== 0 ))
		return( flush_ngf() );
	else	return( status      );
	return( MOINS_UN );
}
#endif

/*	----------------------------------------------------	*/
/*	  t r a n s l a t e _ c o n s u l t (  operation )	*/
/*	----------------------------------------------------	*/
/*	Proposition de Laurence Chambenois pour EIS pour la	*/
/*	recuperation d'information de protection, entre autre	*/
/*	depuis criteria.					*/
/*	----------------------------------------------------	*/
/*	CONSULT=handle,operand:&Label,variable,buffer,length	*/
/*	----------------------------------------------------	*/
/*	IJM : 29/06/2007					*/
/*	----------------------------------------------------	*/
static	WORD	translate_consult(WORD operation)
{
	WORD	status;
	trace("translate_consult()\n");
	if (((status = start_ngf( operation ))	== 0 )
	&&  ((status = ngf_handle())		== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_error_trap())	== 0 )
	&&  ((status = ngf_buffer())		== 0 ))
		return( flush_ngf() );
	else	return( status      );
	return( MOINS_UN );
}

#ifdef	ABALSQL
#include "trsql.c"
#endif

/*	---------------------------------------------------	*/
/*		t r a n s l a t e _ n g f			*/
/*	---------------------------------------------------	*/
/*	main entry point for the translation of NGF keyword	*/
/*	prefixed file instructions.				*/
/*	---------------------------------------------------	*/

WORD	translate_ngf()
{
	WORD	type;

	if ((type = is_ngf_keyword()) == MOINS_UN)
		return( MOINS_UN );

	if ( OtrOption.ListFlag & 1 )
		set_echo_prefix();

	switch (type) 
	{
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
			return( syntax_error(139) );
		return( translate_load_go( type ) );
	case	_NGF_CHAIN		: 
		return( translate_ngf_chain( type ) );
	case	_NGF_XCRI		: 
	case	_NGF_CKEY		: 
	case	_NGF_RKEY		: 
	case	_NGF_STATS		: 
	case	_NGF_RECORD		: 
	case	_NGF_BACKSPACE		: 
	case	_NGF_NAME		: 
	case	_NGF_ATB		: 
	case	_NGF_EXTEND		: 
		return( translate_divers( type ) );
	case	_NGF_MODIFY		: 
		return( translate_modify(type) );
	case	_NGF_INSERT		: 
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
	case	_NGF_QUERY		:
		return( translate_inxs_query(type) );
	case	_NGF_SELECT		:
		return( translate_inxs_select(type) );
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
	case	_NGF_CONSULT		:
		return(translate_consult(type));
#ifdef	PRJ918
	case	_NGF_SESSION		:
		return(translate_session(type));
#endif
	case	_NGF_COLLECT		:
		return(translate_collect(type));
#ifdef	ABALSQL
	case	_NGF_CONNECT		:
		return( translate_sql_connect(type) );
	case	_NGF_BEGIN		:
		return( translate_sql_begin(type) );
	case	_NGF_COMMIT		:
		return( translate_sql_commit(type) );
	case	_NGF_ROLLBACK		:
		return( translate_sql_rollback(type) );
	case	_NGF_PREPARE		:
		return( translate_sql_prepare(type) );
	case	_NGF_EXEC		:
		return( translate_sql_exec(type) );
	case	_NGF_GETROWCOL		:
		return( translate_sql_getrowcol(type) );
	case	_NGF_GETCOLNAME		:
		return( translate_sql_getcolname(type) );
	case	_NGF_FETCH		:
		return( translate_sql_fetch(type) );
	case	_NGF_GETFIELD		:
		return( translate_sql_getfield(type) );
	case	_NGF_DROP		:
		return( translate_sql_drop(type) );
	case	_NGF_GETSQLERROR	:
		return( translate_sql_getsqlerror(type) );
	case	_NGF_GETSERVICEINFO	:
		return( translate_sql_getserviceinfo(type) );
	case	_NGF_BINDPARAM	:
		return( translate_sql_bindparam(type) );
	case	_NGF_BINDCOL	:
		return( translate_sql_bindcol(type) );
#endif
	default				:
		return( MOINS_UN );
	}
}

	/* -------- */
#endif	/* _TRNGF_C */
	/* -------- */
