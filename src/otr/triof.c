/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.	*/
/*									*/
/*									*/
/*		File	:	TRIOF.C    				*/
/*		Version :	2.1c					*/
/*		Date	:	28/09/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRIOF_C
#define	_TRIOF_C

#undef WIN32TRACE
#define	DEBUG

/*	------------------------	*/
/*	Syntax Errors 400 to 437 	*/
/*	------------------------	*/

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include <string.h>		/* string functions */
#include <stdlib.h>		/* standard library */
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
#include "triof.h"
#include "trdebug.h"
#include "trfmt.h"
#include "trfmt.c"
#include "trproc.h"
#include "troutput.h"
#include "trecho.h"
#include "trtables.h"

#ifdef WIN32TRACE
#include "trtrace.h"
MI_TRACE_DCL_MODULE_ID(ID_KERNEL);
#endif

#define MAX_FORMAT_BUFFER_SIZE	256

EXTERN	BYTE	KeyWord[65];
EXTERN	WORD	KeyWordHash;

#ifndef	UNIX
RESULTPTR	primary_evaluation( VOID );
#else
RESULTPTR	primary_evaluation();
#endif

/*	----------------	*/
/*	 initialise_iof 	*/
/*	----------------	*/
WORD	initialise_iof()
{
	IofFree = IofFoot = IofHead = (IOFPTR) 0;
	HotFree = HotFoot = HotHead = (HOTPTR) 0;
	AskEndLabel = MOINS_UN;
	AskStartLabel = MOINS_UN;
	PrintFormatLabel = (BPTR) 0;
	return(0);
}

/*	----------------	*/
/*	allocate_for_iof	*/
/*	----------------	*/
IOFPTR	allocate_for_iof()
{
	IOFPTR	iptr;
	if ((iptr = IofFree) != (IOFPTR) 0)
		IofFree = IofFree->next;
	else if ((iptr = (IOFPTR) allocate( sizeof(struct iof_control ))) == (IOFPTR) 0)
		return( iptr );
	iptr->operation = MOINS_UN;
	iptr->operand   = (RESULTPTR) 0;
	iptr->buffer	= (BPTR) 0;
	iptr->next      = (IOFPTR) 0;
	iptr->prev      = (IOFPTR) 0;
	return( iptr );
}

/*	-------------------	*/
/*	allocate_for_hotkey	*/
/*	-------------------	*/
HOTPTR	allocate_for_hotkey()
{
	HOTPTR	iptr;
	if ((iptr = HotFree) != (HOTPTR) 0)
		HotFree = HotFree->next;
	else if ((iptr = (HOTPTR) allocate( sizeof(struct hot_control ))) == (HOTPTR) 0)
		return( iptr );
	iptr->nature    = MOINS_UN;
	iptr->operand   = (RESULTPTR) 0;
	iptr->label     = (BPTR) 0;
	iptr->gosub     = FAUX;
	iptr->next      = (HOTPTR) 0;
	return( iptr );
}

/*	-----------	*/
/*	copy_hotkey	*/
/*	-----------	*/
HOTPTR	copy_hotkey( hptr )
HOTPTR	hptr;
{
	HOTPTR	nptr;
	if ((nptr = allocate_for_hotkey()) != (HOTPTR) 0) 
	{
		nptr->nature  = hptr->nature;
		nptr->operand = hptr->operand;
		nptr->label   = hptr->label;
		nptr->gosub   = hptr->gosub;
	}
	return( nptr );
}

/*	-----------	*/
/*	release_iof	*/
/*	-----------	*/
VOID	release_iof( iptr )
IOFPTR	iptr;
{
	iptr->next = IofFree;
	if ( iptr->buffer != (BPTR) 0) 
	{
		liberate( iptr->buffer );
		iptr->buffer = (BPTR) 0;
	}
	IofFree = iptr;
	return;
}

/*	--------------	*/
/*	release_hotkey	*/
/*	--------------	*/
VOID	release_hotkey( iptr )
HOTPTR	iptr;
{
	iptr->next = HotFree;
	if ( iptr->label != (BPTR) 0)
		liberate( iptr->label );
	HotFree = iptr;
	return;
}

/*	------------	*/
/*	liberate_iof	*/
/*	------------	*/
VOID	liberate_iof()
{
	IOFPTR	iptr;
	trace("liberate_iof()\n");
	while ((iptr = IofFree) != (IOFPTR) 0) 
	{
		IofFree = IofFree->next;
		liberate( iptr );
	}
	return;
}

/*	------------	*/
/*	liberate_hot	*/
/*	------------	*/
VOID	liberate_hot()
{
	HOTPTR	iptr;
	trace("liberate_hot()\n");
	while ((iptr = HotFree) != (HOTPTR) 0) 
	{
		HotFree = HotFree->next;
		liberate( iptr );
	}
	return;
}

/*	-------------------	*/
/*	get_ask_start_label	*/
/*	-------------------	*/
WORD	get_ask_start_label()
{
	return( AskStartLabel );
}

/*	-----------------	*/
/*	 ask_start_label	*/
/*	-----------------	*/
WORD	ask_start_label()
{
	if ((AskStartLabel = new_implicite_label()) == MOINS_UN) 
		return(0);
	else if ( dcl_implicite_label( AskStartLabel ) == 0 )
		return(0);
	else	return(0);
}

/*	---------	*/
/*	start_iof	*/
/*	---------	*/
WORD	start_iof()
{
	IOFPTR	iptr;
	HOTPTR	hptr;
	trace("start_iof()\n");
	AskEndLabel = MOINS_UN;

	while ((iptr = IofHead) != (IOFPTR) 0) 
	{
		IofHead = IofHead->next;
		release_iof( iptr );
	}

	IofFoot = IofHead = (IOFPTR) 0;
	while ((hptr = HotHead) != (HOTPTR) 0) 
	{
		HotHead = HotHead->next;
		release_hotkey( hptr );
	}
	HotFoot = HotHead = (HOTPTR) 0;
	return(0);
} 

/*	-------------	*/
/*	terminate_iof	*/
/*	-------------	*/
VOID	terminate_iof()
{
	trace("terminate_iof(START)\n");
	if (start_iof() ==0) 
	{
		liberate_iof();
		liberate_hot();
	}
	trace("terminate_iof(END)\n");
	return;
}

/*	-----------------	*/
/*	 translate_pause	*/
/*	-----------------	*/
WORD	translate_pause()
{
	RESULTPTR	rptr;
	if (!( remove_white_space() )) 
	{
		if (!( rptr = integer_result(0) ))
			return( syntax_error( 8992 ) );
		else return( generate_pause( rptr ) );
	}
	else if ((rptr = evaluate_expression(0)) != (RESULTPTR) 0)
		return( generate_pause( rptr ) );
	else	return( syntax_error( 8992 ) );
}

/*	------------------	*/
/*	is_iof_instruction	*/
/*	------------------	*/
WORD	is_iof_instruction()
{
	WORD	i;
	trace("is_iof_instruction()\n");
	uppercase_keyword();
	for ( i = 0; i < _PRINT_KEYWORD_MAX; i++ )
		if ( compare_tokens( KeyWord, print_keywords[i] ) )
			return( i );
	return( MOINS_UN );
}

/*	----------------------	*/
/*	cancel_iof_instruction	*/
/*	----------------------	*/
WORD	cancel_iof_instruction()
{
	WORD	type;
	if ((type = is_iof_instruction()) != MOINS_UN) 
	{
		cancel_keyword( & print_keywords[type] );
		return( VRAI );
	}
	else	return( MOINS_UN );
}

/*	---------	*/
/*	store_fmt	*/
/*	---------	*/
WORD	store_fmt( opcode, fptr )
WORD	opcode;
BPTR	fptr;
{
	IOFPTR	iptr;
	if ((iptr = allocate_for_iof()) == (IOFPTR) 0)
		return(27);
	if ((iptr->prev = IofFoot) == (IOFPTR) 0)
		IofHead = iptr;
	else	IofFoot->next = iptr;
	IofFoot = iptr;
	iptr->operation  = opcode;
	iptr->buffer	 = fptr;
	return( 0 );
}

/*	-------------------	*/
/*	allocate_for_format	*/
/*	-------------------	*/
BPTR	allocate_for_format()
{
	BPTR	fptr;
	if ((fptr = (BPTR) allocate(MAX_FORMAT_BUFFER_SIZE)) != (BPTR) 0) 
	{
		memset(fptr, 0x00FF, MAX_FORMAT_BUFFER_SIZE);
		*fptr = 0;
	}
	return( fptr );
}

/*	--------------------	*/
/*	convert_ascii_format	*/
/*	--------------------	*/
BPTR	convert_ascii_format( xptr )
BPTR	xptr;
{
	WORD	l=0;
	BPTR	fptr=(BPTR) 0;

	if (((l = strlen(xptr)) != 0)
	&&  ((fptr = (BPTR) allocate_for_format()) != (BPTR) 0)
	&&  ((l = atofmt( xptr, l, (fptr+1), MAX_FORMAT_BUFFER_SIZE-1)) != 0)
	&&  ( *(fptr + 1) == 0x00FE )) 
	{
		for ( l = 1; l < MAX_FORMAT_BUFFER_SIZE-1; l++ )
			if ( *(fptr +l) == 0x00FF )
				break;
		*fptr = l;
	}
	else 	
	{
		if (fptr != (BPTR) 0)
			liberate( fptr );
		fptr=(BPTR) 0;
	}
	return( fptr );
}

/*	-------------	*/
/*	store_iof_fmt	*/
/*	-------------	*/
WORD	store_iof_fmt( fptr )
BPTR	fptr;
{
	WORD	status;
	if ( fptr == (BPTR) 0 )
		fptr = (BPTR) "E";
	if ((fptr = convert_ascii_format(fptr)) == (BPTR) 0)
		return( syntax_error(400) );
	else if ((status = store_fmt( (_iof_FMT | 0x0080 ), fptr )) != 0)
		return( status );
	else	return( 0 );
}

/*	---------	*/
/*	store_iof	*/
/*	---------	*/
WORD	store_iof( xptr, opcode )
RESULTPTR	xptr;
WORD		opcode;
{
	IOFPTR	iptr;
	if ((iptr = allocate_for_iof()) == (IOFPTR) 0)
		return(27);
	if ((iptr->prev = IofFoot) == (IOFPTR) 0)
		IofHead = iptr;
	else	IofFoot->next = iptr;
	IofFoot = iptr;
	iptr->operation = opcode;
	iptr->operand   = mark_live_result( xptr );
	return( 0 );
}

/*	-------------	*/
/*	store_iof_prn	*/
/*	-------------	*/
WORD	store_iof_prn( xptr )
RESULTPTR	xptr;
{
	trace("store_iof_prn()\n");
	return( store_iof( xptr , _iof_PRN ) );
}

/*	-------------	*/
/*	translate_prn	*/
/*	-------------	*/
WORD	translate_prn( mode )
WORD	mode; 
{
	RESULTPTR	xptr;
	if ( mode ) 
	{
		if ((xptr = primary_evaluation()) == (RESULTPTR) 0)
			return( syntax_error(401) );
	}
	else if ((xptr = evaluate_expression(0)) == (RESULTPTR) 0)
		return( syntax_error(402) );

	return( store_iof_prn( xptr ) );
}

/*	-------------	*/
/*	store_iof_atb	*/
/*	-------------	*/
WORD		store_iof_atb( xptr )
RESULTPTR	xptr;
{
	trace("store_iof_atb()\n");
	return( store_iof( xptr, _iof_ATB ) );
}

/*	-------------	*/
/*	translate_atb	*/
/*	-------------	*/
WORD	translate_atb()
{
	RESULTPTR	xptr;
	if (( is_left_brace()  )
	&&  ((xptr = evaluate_typed_expression(_TYPE_INT)) != (RESULTPTR) 0)
	&&  ( is_right_brace() ))
		return( store_iof_atb( xptr ) );
	else	return( syntax_error(403) );
}

/*	----------------	*/
/*	 store_iof_tabv		*/
/*	----------------	*/
WORD	store_iof_tabv( xptr )
RESULTPTR	xptr;
{
	trace("store_iof_tabv()\n");
	return( store_iof( xptr, _iof_TABV ) );
}

/*	----------------	*/
/*	 translate_tabv 	*/
/*	----------------	*/
WORD	translate_tabv()
{
	RESULTPTR	xptr;
	if (( is_left_brace() )
	&&  ((xptr = evaluate_typed_expression(_TYPE_INT)) != (RESULTPTR) 0)
	&&  ( is_right_brace() ))
		return( store_iof_tabv( xptr ) );
	else	return( syntax_error(404) );
}

/*	----------------	*/
/*	 store_iof_tabl 	*/
/*	----------------	*/
WORD	store_iof_tabl( lptr )
RESULTPTR	lptr;
{
	trace("store_iof_tabl()\n");
	return( store_iof( lptr, _iof_TABL ) );
}

/*	----------------	*/
/*	 store_iof_tabc 	*/
/*	----------------	*/
WORD	store_iof_tabc( lptr )
RESULTPTR	lptr;
{
	trace("store_iof_tabc()\n");
	return( store_iof( lptr, _iof_TABC ));
}

/*	-----------------	*/
/*	translate_iof_tab	*/
/*	-----------------	*/
WORD	translate_iof_tab(modeabal)
WORD	modeabal;
{
	RESULTPTR	lptr;
	RESULTPTR	cptr;
	WORD		status;
	if ((cptr = evaluate_typed_expression(_TYPE_INT)) == (RESULTPTR) 0)
		return( syntax_error(405) );
	
	status = is_comma();
	if (!(modeabal))
		status = VRAI;
	if ( status ) 
	{
		if (((lptr = evaluate_typed_expression(_TYPE_INT)) == (RESULTPTR) 0)
		||  ((status = store_iof_tabl( lptr )) != 0 ))
			return( syntax_error(406) );
	}
	if ( is_right_brace() )
		return( store_iof_tabc( cptr ));
	else	return( unmatched_braces() );
}

/*	-------------	*/
/*	translate_tab	*/
/*	-------------	*/
WORD	translate_tab()
{
	if ( is_left_brace() )
		return( translate_iof_tab(VRAI) );
	return( syntax_error(407) );
}

/*	--------------------	*/
/*	store_iof_foreground	*/
/*	--------------------	*/
WORD	store_iof_foreground( xptr )
RESULTPTR	xptr;
{
	return( store_iof( xptr, _iof_FORE ) );
}

/*	--------------------	*/
/*	store_iof_background	*/
/*	--------------------	*/
WORD	store_iof_background( xptr )
RESULTPTR	xptr;
{
	return( store_iof( xptr, _iof_BACK ) );
}

/*	-----------------	*/
/*	 translate_paint	*/
/*	-----------------	*/
WORD	translate_paint()
{
	RESULTPTR	xptr;
	WORD		status;
	if ( is_left_brace() ) 
	{
#ifdef	otr64
		if (((xptr = evaluate_expression(0)) == (RESULTPTR) 0)
		||  ((status = store_iof_foreground( xptr )) != 0 ))
#else
		if (((xptr = evaluate_typed_expression(_TYPE_INT)) == (RESULTPTR) 0)
		||  ((status = store_iof_foreground( xptr )) != 0 ))
#endif
			return( syntax_error(408) );
		if ( is_comma() ) 
		{
#ifdef	otr64
			if (((xptr = evaluate_expression(0)) == (RESULTPTR) 0)
			||  ((status = store_iof_background( xptr )) != 0 ))
#else
			if (((xptr = evaluate_typed_expression(_TYPE_INT)) == (RESULTPTR) 0)
			||  ((status = store_iof_background( xptr )) != 0 ))
#endif
				return( syntax_error(409) );
		}
		if ( is_right_brace() )
			return( 0 );
	}
	return( syntax_error(410) );
}

/*	---------	*/
/*	flush_fmt	*/
/*	---------	*/
WORD	flush_fmt()
{
	if ( PrintFormatLabel != (BPTR) 0 ) 
	{
		generate_format_label( PrintFormatLabel );
		liberate( PrintFormatLabel );
		PrintFormatLabel = (BPTR) 0;
	}
	return(0);
}

/*	-------------	*/
/*	ask_end_label	*/
/*	-------------	*/
WORD	ask_end_label()
{
	if ( AskEndLabel == MOINS_UN )
		return((AskEndLabel = new_implicite_label()));
	else	return(AskEndLabel);
}

/*	-----------------	*/
/*	dcl_ask_end_label	*/
/*	-----------------	*/
WORD	dcl_ask_end_label()
{
	if (( AskEndLabel != MOINS_UN )
	&&  ( dcl_implicite_label( AskEndLabel ) == 0 )) 
		return( 0 );
	else	return( 0 );
}

/*	------------	*/
/*	flush_hotkey	*/
/*	------------	*/
WORD	flush_hotkey( hptr )
HOTPTR	hptr;
{
	WORD	status;
	if (( hptr != (HOTPTR) 0)
	&&  ((status = generate_iof_hotkey( hptr )) != 0))
		return( status );
	else	return( 0 );
}

/*	-------------	*/
/*	flush_hotkeys	*/
/*	-------------	*/
WORD	flush_hotkeys()
{
	HOTPTR	hptr;
	WORD	status;
	if ((hptr = HotHead) != (HOTPTR) 0) 
	{
		do	
		{
			if ((status = flush_hotkey( hptr )) != 0)
				return( status );
		}
		while ((hptr = hptr->next) != (HOTPTR) 0);
	}
	return(0);
}

/*	---------	*/
/*	 message	*/
/*	---------	*/
WORD	message( nptr )
BPTR	nptr;
{
	sysprintf(nptr);
	return(1);
}

/*	------------------------	*/
/*	convert_explicite_format	*/
/*	------------------------	*/
BPTR	convert_explicite_format()
{
	WORD	l=0;
	BPTR	fptr=(BPTR) 0;

	if (((l = get_format()) != 0)
	&&  ((fptr = (BPTR) allocate_for_format()) != (BPTR) 0)
	&&  ((l = atofmt( TokenBuffer, l, (fptr+1), MAX_FORMAT_BUFFER_SIZE-1)) != 0)
	&&  ( *(fptr + 1) == 0x00FE )) 
	{
		for ( l = 1; l < MAX_FORMAT_BUFFER_SIZE-1; l++ )
			if ( *(fptr +l) == 0x00FF )
				break;
		*fptr = l;
	}
	else 
	{
		if (fptr != (BPTR) 0)
			liberate( fptr );
		fptr=(BPTR) 0;
	}
	return( fptr );
}

/*	-------------	*/
/*	translate_fmt	*/
/*	-------------	*/
WORD	translate_fmt()
{
	WORD	status;
	BPTR	fptr;
	BYTE	dummy[3];
	dummy[0] = 2; 
	dummy[0] = 0xFE; 
	dummy[0] = 0xFF; 
	trace("translate_fmt()\n");
	if (!( is_left_brace() ))
		return( syntax_error(411) );
	else if ((fptr = convert_explicite_format()) == (BPTR) 0)
		return( syntax_error(412) );
	else if ((status = generate_fmt( fptr )) != 0)
		return( status );
	else if (!( is_right_brace() ))
		return( unmatched_braces() );
	else	return( 0 );
}

/*	----------------	*/
/*	translate_format	*/
/*	----------------	*/
WORD	translate_format()
{
	RESULTPTR	rptr;
	BPTR		fptr;
	WORD		status;
	trace("translate_format()\n");
	if ( is_left_brace() )	
	{
		/* -------------------- */
		/* Double Opening Brace */
		/* -------------------- */
		trace("implicite_format_expression\n");
		/* -------------------------------- */
		/* Format Expression (variable etc) */
		/* -------------------------------- */
		do	
		{
			if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
				return( syntax_error(413) );
			if ((status = store_iof( rptr, _iof_FMT )) != 0 )
				return(status);
		}
		while ( is_comma() );
		if (!(is_right_brace()))
			return( syntax_error(414) );
	}
	else
	{			
		/* -------------------- */
		/* Single Opening Brace */
		/* -------------------- */
		trace("explicite_format_string\n");
		/* ----------------------- */
		/* Explicite Format String */
		/* ----------------------- */
		if ((fptr = convert_explicite_format()) == (BPTR) 0)
			return( syntax_error(415) );
		if ((status = store_fmt( (_iof_FMT | 0x0080 ), fptr )) != 0)
			return( status );
	}

	/* ----------------------------- */
	/* Check for final closing brace */
	/* ----------------------------- */
	if ( is_right_brace() )
		return(0);
	else	return( syntax_error(416) );
}

/*	-----------	*/
/*	iof_special	*/
/*	-----------	*/
WORD	iof_special( opcode )
WORD	opcode;
{
	return( store_iof( (RESULTPTR) 0, opcode ));
}

/*	------------------	*/
/*	translate_iof_bell	*/
/*	------------------	*/
WORD	translate_iof_bell()
{
	return( iof_special( _iof_BELL ) );
}

/*	-------------------	*/
/*	translate_iof_clear	*/
/*	-------------------	*/
WORD	translate_iof_clear()
{
	trace("translate_iof_clear()\n");
	return( iof_special( _iof_CLEAR ) );
}

/*	------------------	*/
/*	translate_iof_atom	*/
/*	------------------	*/
WORD	translate_iof_atom()
{
	switch (is_iof_instruction()) 
	{
	case _IOF_TAB		: return( translate_tab() 	);
	case _IOF_TABV		: return( translate_tabv()	);
	case _IOF_PAINT		: return( translate_paint()	);
	case _IOF_ATB		: return( translate_atb()	);
	case _IOF_PAGE		:
	case _IOF_CLEAR		: return( translate_iof_clear()	);
	case _IOF_BELL		: return( iof_special(_iof_BELL));
	case _IOF_HOME		: return( iof_special(_iof_HOME));
	case MOINS_UN		: return( MOINS_UN );
	default			: return( syntax_error(417) );
	}
}

/*	----------------	*/
/*	iof_instructions	*/
/*	----------------	*/
WORD	iof_instructions(askmode)
WORD	askmode;
{
	WORD		instruction=0;
	WORD		status=0;
	WORD		operands=0;
	trace("iof_instructions()\n");
	do	
	{
		if ( evaluate_token() ) 
		{
			switch ((status = translate_iof_atom())) 
			{
			case	0 	 :
				break;

			case	MOINS_UN :
				if ((status = translate_prn(VRAI)) != 0)
					return( syntax_error(418) );
				else	break;
			default		 :
				return( status );
			}
		}
		else if ( is_equals() ) 
		{
			if ( operands != 0 )
				return( syntax_error(419) );
			else if ( askmode == 1 ) 
			{
				unget_byte();
				return( 0 );
			}
			else	return( syntax_error(419) );
		}
		else if ( is_right_brace() ) 
		{
			if ( operands != 0 )
				return( syntax_error(419) );
			else if ( askmode == 2 ) 
			{
				unget_byte();
				return(0);
			}
			else	return( syntax_error(420) );
		}
		else if ( is_left_brace() ) 
		{
			if ((status = translate_format()) != 0 )
				return( syntax_error(421) );
		}
		else if ((status = translate_prn( FAUX )) != 0)
			return( status );
		operands++;
	}
	while ( is_comma() );
	return(0);
}

/*	---------	*/
/*	flush_iof	*/
/*	---------	*/
WORD		flush_iof()
{
	WORD	status;
	IOFPTR	iptr;

	if ((iptr = IofHead) != (IOFPTR) 0) 
	{
		do	
		{
			if ( iptr->operation != MOINS_UN ) 
			{
				if ( iptr->operation & 0x0080 ) 
				{
					/* --------------------- */
					/* Explicite Format Code */
					/* --------------------- */
					if ((status = generate_iof_format(iptr->operation, iptr->buffer )) != 0)
						return( status );
				}
				else if ( iptr->operand != (RESULTPTR) 0) 
				{
					if ((status = generate_iof_instruction( iptr->operation, iptr->operand )) != 0)
						return( status );
				}
				else if ((status = generate_byte( iptr->operation )) != 0)
					return( status );
			}
		}
		while ((iptr = iptr->next) != (IOFPTR) 0);
	}
	return(0);
}

/*	------------	*/
/*	flush_device	*/
/*	------------	*/
WORD	flush_device( device )
RESULTPTR	device;
{
	if (!( result_is_one( device ) ))
		return( generate_iof_instruction( _iof_DEV, device ));
	else	return( 0 );
}

/*	--------------------	*/
/*	check_print_operands	*/
/*	--------------------	*/
WORD	check_print_operands( device, mode )
RESULTPTR	device;
WORD		mode;
{
	IOFPTR	iptr;
	IOFPTR	lptr;
	trace("check_print_operands()\n");
	if ((iptr = IofFoot) != (IOFPTR) 0) 
	{
		do	
		{
			lptr = (IOFPTR) 0;
			if (( iptr->operation != MOINS_UN )
			&&  ( iptr->operand != (RESULTPTR) 0)) 
			{
				if ( iptr->operation == _iof_TABC ) 
				{
					if (((lptr = iptr->prev) != (IOFPTR) 0 )
					&&  (lptr->operation == _iof_TABL)) 
					{
						if  ((lptr->operand = mark_dead_result( lptr->operand )) == (RESULTPTR) 0)
							return( internal_error(63) );
					}
					else 	lptr = (IOFPTR) 0;
				}
				if  ((iptr->operand = mark_dead_result( iptr->operand )) == (RESULTPTR) 0)
					return( internal_error(3) );
				if ( lptr != (IOFPTR) 0 )
					iptr = lptr;
			}
		}
		while ((iptr = iptr->prev) != (IOFPTR) 0);
	}
	if ( mode )
		if ((device = mark_dead_result( device )) == (RESULTPTR) 0)
			return( internal_error(4) );
	return( 0 );
}

/*	---------------------	*/
/*	check_hotkey_operands	*/
/*	---------------------	*/
WORD	check_hotkey_operands()
{
	return(0);
}

/*	------------------	*/
/*	check_ask_operands	*/
/*	------------------	*/
WORD	check_ask_operands( device )
RESULTPTR	device;
{
	IOFPTR	iptr;
	if ((iptr = IofFoot) != (IOFPTR) 0) 
	{
		do	
		{
			if (( iptr->operation != MOINS_UN )
			&&  ( iptr->operand != (RESULTPTR) 0))
				iptr->operand = mark_dead_result( iptr->operand );
		}
		while ((iptr = iptr->prev) != (IOFPTR) 0);
	}
	check_hotkey_operands();
	device = mark_dead_result( device );
	return( 0 );
}

/*	----------------	*/
/*	check_ask_target	*/
/*	----------------	*/
WORD	check_ask_target( rptr )
RESULTPTR	rptr;
{
	rptr = mark_dead_result( rptr );
	return( 0 );
}

/*	--------------------	*/
/*	echo_iof_instruction	*/
/*	--------------------	*/
static	VOID	echo_iof_instruction( opcode, operand )
WORD		opcode;
RESULTPTR	operand;
{
	WORD	mode=1;
	switch ( opcode ) 
	{
	case	_iof_TABC	:
		echo_keyword("TAB("); break;
	case	_iof_ATB	:
		echo_keyword("ATB("); break;
	case	_iof_ASK	: 
	case	_iof_PRN	:
		mode = 0; break;
	case	_iof_TABV	:
		echo_keyword("TABV("); break;
	case	_iof_CLEAR	:
		echo_keyword("CLEAR"); break;
	case	_iof_HOME 	:
		echo_keyword("HOME"); break;
	case	_iof_BELL 	:
		echo_keyword("BELL"); break;
	case	_iof_GSBX	:
	case	_iof_HOTX	:
	case	_iof_GSBH	:
	case	_iof_FIO 	:
	case	_iof_HOT 	:
	case	_iof_FMT	:
	case	_iof_DEV	:
		return;
	}
	if ( operand != (RESULTPTR) 0) 
	{
		echo_operand( operand );
		if ( mode )
			echo_right_brace();
	}
	return;
}

/*	--------	*/
/*	echo_tab	*/
/*	--------	*/
static	IOFPTR	echo_tab( iptr )
IOFPTR	iptr;
{
	IOFPTR	jptr;
	echo_keyword("TAB(");
	echo_operand( iptr->operand );
	if (( jptr = iptr->next) != (IOFPTR) 0) 
	{
		if ( jptr->operation == _iof_TABC ) 
		{
			echo_comma();
			echo_operand( jptr->operand );
			iptr = jptr;
		}
	}
	echo_right_brace();
	return( iptr );
}

/*	----------	*/
/*	echo_paint	*/
/*	----------	*/
static	IOFPTR	echo_paint( iptr )
IOFPTR	iptr;
{
	IOFPTR	jptr;
	echo_keyword("PAINT(");
	echo_operand( iptr->operand );
	if (( jptr = iptr->next) != (IOFPTR) 0) 
	{
		if ( jptr->operation == _iof_BACK ) 
		{
			echo_comma();
			echo_operand( jptr->operand );
			iptr = jptr;
		}
	}
	echo_right_brace();
	return( iptr );
}

/*	-----------	*/
/*	echo_format	*/
/*	-----------	*/
VOID	echo_format( fptr )
BPTR	fptr;		
{
	WORD	x,y,n;
	WORD	fmtlng;

	fmtlng	= (WORD) *(fptr++);

	if ( *(fptr++) != (BYTE) 0x00FE )
		return; 
	else	echo_byte('('); 

	while (1) 
	{
		switch ((y = (WORD) *(fptr++))) 
		{
		case	FMT_D	: x = 'D' ; break;
		case	FMT_A	: x = 'A' ; break;
		case	FMT_N	: x = 'N' ; break;
		case	FMT_Z	: x = 'Z' ; break;
		case	FMT_C	: x = 'C' ; break;
		case	FMT_B	: x = 'B' ; break;
		case	FMT_W	: x = 'W' ; break;
		case	FMT_U	: x = 'U' ; break;
		case	FMT_V   : 
			echo_byte('V'); fptr++;  
			continue;
		case	FMT_P	: 
			echo_byte('.'); 
			continue;
		case	FMT_DOL : 
			echo_byte('$'); 
			continue;
		case	FMT_PR	:
			echo_byte('"'); 
			x = *(fptr++);
			while (x > 0) { echo_byte(*(fptr++)); x--;}
			echo_byte('"'); 
			continue;
		case	FMT_LF  : x = '/' ; break;
		case	FMT_ATB	: x = '\\' ; break;
		case	FMT_TAB	: x = 'T' ; break;
		case	FMT_ESP	: x = 'X' ; break;
		case	FMT_SEP	: echo_byte(',');  continue;
		case	FMT_STR	: echo_byte('E');  continue;
		case	FMT_CUT	: echo_byte('F');  continue;
		case	FMT_ZER	: echo_byte('*');  continue;
		case	FMT_JL	: echo_byte('L');  continue;
		case	FMT_JR	: echo_byte('R');  continue;
		case	FMT_NEG	: x = '-'; break;
		case	FMT_PNG	: x = '+'; break;
		case	FMT_MIL : echo_byte('S');  continue;
		case	FMT_DYN : echo_byte('?');  continue;
		case	FMT_MCH	: 
			echo_byte('S');
			echo_byte('(');
			echo_byte(*(fptr++)); 
			echo_byte(')');
			continue;
		case	FMT_DCH	: 
			echo_byte('$');
			echo_byte('(');
			echo_byte(*(fptr++)); 
			echo_byte(')');
			continue;
		case	FMT_ZCH	:
			echo_byte('*');
			echo_byte('(');
			echo_byte(*(fptr++)); 
			echo_byte(')');
			continue;
		case	FMT_FIN	:
		default		: 
			echo_byte(')'); 
			return;
		}
		echo_byte( x ); 

		x = (WORD) *(fptr++);
	
		if (( x != 1 ) || ( y & 0x0020 )) 
		{
			if ( x == 0 ) 	
			{
				echo_byte('0');
			}
			else	
			{
				for ( n = 100; n > 0; n /= 10 ) 
				{
					if (( x / n ) > 0 ) 
					{
						echo_byte((( x / n) | 0x0030));
					}
					x %= n;
				}
			}
		}
	}
	return;
}

/*	-----------------	*/
/*	echo_iof_operands	*/
/*	-----------------	*/
static	VOID	echo_iof_operands()
{
	IOFPTR	iptr;

	if ((iptr = IofHead) != (IOFPTR) 0) 
	{
		while(1) 
		{
			if ( iptr->operation != MOINS_UN ) 
			{
				if ( iptr->operation & 0x0080 )
					echo_format(iptr->buffer );
				else if ( iptr->operation == _iof_TABL ) 
				{
					if ((iptr = echo_tab( iptr )) == (IOFPTR) 0)
						break;
				}
				else if ( iptr->operation == _iof_FORE ) 
				{
					if ((iptr = echo_paint( iptr )) == (IOFPTR) 0)
						break;
				}
				else 	echo_iof_instruction( iptr->operation, iptr->operand );
			}
			if ((iptr = iptr->next) != (IOFPTR) 0)
				echo_comma();
			else	break;
		}
	}
	return;
}

/*	------------	*/
/*	echo_hotkeys	*/
/*	------------	*/
static	VOID	echo_hotkeys()
{
	HOTPTR	hptr;
	if ((hptr = HotHead) != (HOTPTR) 0) 
	{
		while (1) 
		{
			echo_comma();
			if ( hptr->nature != MOINS_UN ) 
			{
				switch ( hptr->nature ) 
				{
				case _hot_I : echo_string("I"); break;
				case _hot_U : echo_string("U"); break;
				case _hot_D : echo_string("D"); break;
				case _hot_L : echo_string("L"); break;
				case _hot_X : echo_string("X"); break;
				case _hot_T : echo_string("T"); break;
				case _hot_E : echo_string("E"); break;
				}
			}
			else	echo_operand( hptr->operand );
			echo_equals();
			if ( hptr->gosub )
				echo_left_brace();
			if ( hptr->label != (BPTR) 0)
				echo_string( hptr->label );
			if ( hptr->gosub )
				echo_left_brace();
			if ((hptr = hptr->next) == (HOTPTR) 0)
				break;
		}
	}
	return;
}

/*	----------	*/
/*	echo_print	*/
/*	----------	*/
WORD		echo_print( device )
RESULTPTR	device;
{
	if (( OtrOption.ListFlag & 1 )
	&&  ( echo_start(VRAI)   )) 
	{
		echo_keyword("PRINT=");
		echo_operand(device);
		echo_colon();
		echo_iof_operands();
		echo_line();
	}
	return(0);
}

/*	--------	*/
/*	echo_ask	*/
/*	--------	*/
WORD		echo_ask( device, target )
RESULTPTR	device;
RESULTPTR	target;
{
	if (( OtrOption.ListFlag & 1 )
	&&  ( echo_start(VRAI)   )) 
	{
		echo_keyword("ASK=");
		echo_operand(device);
		echo_hotkeys();
		echo_colon();
		echo_iof_operands();
		echo_equals();
		echo_operand( target );
		echo_line();
	}
	return(0);
}

/*	-----------	*/
/*	flush_print	*/
/*	-----------	*/
WORD		flush_print( device, mode )
RESULTPTR	device;
WORD		mode;
{
	WORD	status;
	trace("flush_print()\n");
	if (((status = check_print_operands(device,mode)) == 0)
	&&  ((status = echo_print(device)) == 0)
	&&  ((status = generate_iof()) == 0)
	&&  ((status = flush_device(device)) == 0)
	&&  ((status = flush_fmt())    == 0)
	&&  ((status = flush_iof())    == 0))
		return( generate_fio() );
	else	return( status );
}

/*	-------------	*/
/*	flush_iof_ask	*/
/*	-------------	*/
WORD		flush_iof_ask( device, target )
RESULTPTR	device;
RESULTPTR	target;
{
	WORD		status=30;
	if (((status = check_ask_operands( device )) == 0)
	&&  ((status = check_ask_target( target )) == 0 )
	&&  ((status = echo_ask(device,target)) == 0)
	&&  ((status = generate_iof())  == 0 )
	&&  ((status = flush_device(device)) == 0)
	&&  ((status = flush_hotkeys()) == 0 )
	&&  ((status = flush_iof())     == 0 )
	&&  ((status = generate_iof_instruction( _iof_ASK, target )) == 0))
		return( dcl_ask_end_label() );
	else	return( syntax_error(422) );
}

/*	---------	*/
/*	flush_ask	*/
/*	---------	*/
WORD		flush_ask( device )
RESULTPTR	device;
{
	RESULTPTR	target;
	WORD		status=30;
	if ( is_equals() ) 
	{
		do	
		{
			if ( evaluate_token() ) 
			{
				switch ((status = translate_iof_atom())) 
				{
				case	0 :
					continue;

				case	MOINS_UN :
					if ((target = primary_evaluation()) != (RESULTPTR) 0) 
					{
						if (( target->nature & _RESULT_BASIC ) == _RESULT_VARB)
							target->nature = _RESULT_VPTR;
						return( flush_iof_ask( device, target ) );
					}
					else	return( syntax_error( 423 ) );
				default		 :
					return( status );
				}
			}
			else if ( is_left_brace() ) 
			{
				if ((status = translate_format()) != 0 )
					return( syntax_error(424) );
			}
			else if ((status = translate_prn( FAUX )) != 0)
				return( status );
		}
		while ( is_comma()  );
	}
	return(syntax_error(425));
}

/*	-------------------------	*/
/*	 translate_format_labels	*/
/*	-------------------------	*/
WORD	translate_format_labels()
{
	if ( is_comma() ) 
	{
		if ((!( get_label() ))
		||  ( TokenBuffer[0] != '&' ))
			return( syntax_error(426) );
		else if ((PrintFormatLabel = allocate_for_string( TokenBuffer )) == (BPTR) 0)
			return( allocation_failure() );
	}
	return( 0 ); 
}

/*	---------	*/
/*	 iof_eol	*/
/*	---------	*/
WORD	iof_eol()
{
	if (!( remove_white_space() ))
		return(0);	
	else if ( is_newline() )
		return(0);
	else	return(1);
}

/*	-----------------	*/
/*	 translate_print	*/
/*	-----------------	*/
WORD	translate_print()
{
	RESULTPTR	device;
	WORD		status=0;
	if (( is_equals() )
	&&  ((status = start_iof()) == 0)
	&&  ((device = evaluate_expression(0)) != (RESULTPTR) 0)
	&&  ((status = translate_format_labels()) == 0 )
	&&  ( is_colon()  )
	&&  ((status = iof_instructions(0)) == 0 )
	&&  ((status = iof_eol()) == 0))
		return( flush_print( device, VRAI ) );
	else	return( syntax_error(427) );	
}

/*	-------------------	*/
/*	translate_clf_print	*/
/*	-------------------	*/
WORD	translate_clf_print(device)
RESULTPTR	device;
{
	WORD		status=0;
	if (( is_left_brace() )
	&&  ((status = start_iof()) == 0)
	&&  ((status = iof_instructions(2)) == 0 )
	&&  ( is_right_brace() ))
		return( flush_print( device, VRAI ) );
	else	return( syntax_error(428) );	
}

/*	------------	*/
/*	store_hotkey	*/
/*	------------	*/
WORD	store_hotkey( hptr )
HOTPTR	hptr;
{
	if ( HotFoot == (HOTPTR) 0 )
		HotHead = hptr;
	else	HotFoot->next = hptr;
	HotFoot = hptr;
	return( 0 );
}

/*	------------------------	*/
/*	translate_hotkey_adresse	*/
/*	------------------------	*/
WORD	translate_hotkey_adresse( hptr )
HOTPTR	hptr;
{
	hptr->gosub = is_left_brace();
	if (!( get_label() ))
		return( syntax_error(429) );
	if ((hptr->label = (BPTR) allocate( strlen( TokenBuffer )+1 )) == (BPTR) 0)
		return( allocation_failure() );
	else	strcpy(hptr->label,TokenBuffer);
	if (( hptr->gosub ) &&  (!( is_right_brace())))
		return( syntax_error(430) );
	else	return( 0 );
}

/*	--------------------------	*/
/*	translate_implicite_hotkey	*/
/*	--------------------------	*/
WORD	translate_implicite_hotkey( identity )
WORD	identity;
{
	WORD		status;
	HOTPTR		hptr;
	if (( is_equals() )
	&&  ((hptr = allocate_for_hotkey()) != (HOTPTR) 0)
	&&  ((status = translate_hotkey_adresse(hptr)) == 0  )) 
	{
		hptr->nature = identity;
		return( store_hotkey( hptr ) );
	}
	else	return( status );
}

/*	-------------------------	*/
/*	 store_implicite_hotkeys	*/
/*	-------------------------	*/
WORD	store_implicite_hotkeys( kptr, label )
BPTR	kptr;
BPTR	label;
{
	WORD		status;
	WORD		keycode;
	HOTPTR		hptr;
	trace("store_implicite_hotkeys()\n");
	while ((keycode = *(kptr++)) != 0 ) 
	{
		if  (((hptr = allocate_for_hotkey()) != (HOTPTR) 0)
		&&   ((hptr->label = (BPTR) allocate_for_string( label )) != (BPTR) 0)) 
		{
			hptr->gosub = FAUX;
			switch ( keycode ) 
			{
			case 'I' :
				trace("Escape\n");
				hptr->nature = _hot_I;
				break;
			case 'U' :
				hptr->nature = _hot_U;
				break;
			case 'D' :
				hptr->nature = _hot_D;
				break;
			case 'L' :
				hptr->nature = _hot_L;
				break;
			default	:
				return( syntax_error(431) );
			}
			if ((status = store_hotkey( hptr )) != 0)
				return( status );
		}
		else	return( allocation_failure() );
	}
	return( 0 );
}

/*	--------------------------	*/
/*	translate_explicite_hotkey	*/
/*	--------------------------	*/
WORD	translate_explicite_hotkey()
{
	WORD		status=30;
	HOTPTR		hptr;
	if (((hptr = allocate_for_hotkey()) != (HOTPTR) 0)
	&&  ((hptr->operand = evaluate_expression(0)) != (RESULTPTR) 0)
	&&  ( is_equals() )
	&&  ((status = translate_hotkey_adresse(hptr)) == 0 ))
		return( store_hotkey( hptr ) );
	else	return( status );
}

/*	------------------------	*/
/*	translate_primary_hotkey	*/
/*	------------------------	*/
WORD	translate_primary_hotkey()
{
	WORD		status=30;
	HOTPTR		hptr;
	if (((hptr = allocate_for_hotkey()) != (HOTPTR) 0)
	&&  ((hptr->operand = primary_evaluation()) != (RESULTPTR) 0)
	&&  ( is_equals() )
	&&  ((status = translate_hotkey_adresse(hptr)) == 0 ))
		return( store_hotkey( hptr ) );
	else	return( status );
}

/*	-----------------	*/
/*	translate_hotkeys	*/
/*	-----------------	*/
WORD	translate_hotkeys()
{
	WORD	c=32;
	WORD	status;
	while ( is_comma() ) 
	{
		if ( evaluate_token() ) 
		{
			if ( uppercase_compare(TokenBuffer,"I") ) 
			{
				if ((status = translate_implicite_hotkey(_hot_I)) != 0 )
					return( status );
			}
			else if ( uppercase_compare(TokenBuffer,"U") ) 
			{
				if ((status = translate_implicite_hotkey(_hot_U)) != 0 )
					return( status );
			}
			else if ( uppercase_compare(TokenBuffer,"D") ) 
			{
				if ((status = translate_implicite_hotkey(_hot_D)) != 0 )
					return( status );
			}
			else if ( uppercase_compare(TokenBuffer,"L") ) 
			{
				if ((status = translate_implicite_hotkey(_hot_L)) != 0 )
					return( status );
			}
			else if ( uppercase_compare(TokenBuffer,"X") ) 
			{
				if ((status = translate_implicite_hotkey(_hot_X)) != 0 )
					return( status );
			}
			else if ( uppercase_compare(TokenBuffer,"E") ) 
			{
				if ((status = translate_implicite_hotkey(_hot_E)) != 0 )
					return( status );
			}
			else if ( uppercase_compare(TokenBuffer,"T") ) 
			{
				if ((status = translate_implicite_hotkey(_hot_T)) != 0 )
					return( status );
			}
			else if ((status = translate_primary_hotkey()) != 0 )
				return( status );
		}
		else if ((status = translate_explicite_hotkey()) != 0 )
			return( status );
	}
	return( 0 ); 
}

/*	-------------	*/
/*	translate_ask	*/
/*	-------------	*/
WORD	translate_ask()
{
	RESULTPTR	device;
	WORD		status=0;
	ask_start_label();
	if (( is_equals() )
	&&  ((status = start_iof()) == 0)
	&&  ((device = evaluate_expression(0)) != (RESULTPTR) 0)
	&&  ((status = translate_hotkeys()) == 0 )
	&&  ( is_colon()  )
	&&  ((status = iof_instructions(1)) == 0 ))
		return( flush_ask( device ) );
	else	return( syntax_error(433) );	
}

/*	------------	*/
/*	translate_op	*/
/*	------------	*/
WORD	translate_op()
{
	WORD		nextlabel=0;
	BYTE		label[_MAX_OTR_TOKEN+1];
	WORD		target=0;
	WORD		status;
	RESULTPTR	rptr=(RESULTPTR) 0;

	if (( get_label() ) 
	&&  ( copy_token( label, 64) )) 
	{
		if ( is_comma() )
			if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
				return( syntax_error(434) );
		if ((status = generate_op( rptr, label )) != 0)
			return( status );
		else	return( 0 );
	}
	else	return( syntax_error(436) );
}

/*	-------------	*/
/*	translate_iof	*/
/*	-------------	*/
WORD	translate_iof()
{
	WORD	type;
	if ((type = is_iof_keyword()) == MOINS_UN)
		return( MOINS_UN );
	if ( OtrOption.ListFlag & 1 )
		set_echo_prefix();
	switch ( type ) 
	{
	case	_IOF_PRINT	:
		return( translate_print() );
	case	_IOF_ASK	:
		if ( OtrOption.NoInput ) 
			return( inhibited_function() );
		else	return( translate_ask() );
	case	_IOF_PAUSE	:
		if ( OtrOption.NoInput ) 
			return( inhibited_function() );
		else	return( translate_pause() );
	case	_IOF_OP		:
		if ( OtrOption.NoInput ) 
			return( inhibited_function() );
		else	return( translate_op() );
	case	_IOF_GET	:
	case	_IOF_PUT	:
		return( not_yet_available() );
	default	:
		return( MOINS_UN );
	}
}

/*	---------	*/
/*	clf_print	*/
/*	---------	*/
WORD		clf_print( target, format, value )
RESULTPTR	target;
BPTR		format;
RESULTPTR	value;
{
	WORD	status;
	if  (((status = start_iof()) == 0)
	&&   ((status = store_iof_fmt( format )) == 0 )
	&&   ((status = store_iof_prn( value  )) == 0 ))
		return( flush_print( target,FAUX ) );
	else	return( syntax_error(437) );
}

	/* -------- */
#endif	/* _TRIOF_C */
	/* -------- */

