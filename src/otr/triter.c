/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.	*/
/*									*/
/*									*/
/*		File	:	TRITER.C				*/
/*		Version :	2.1d					*/
/*		Date	:	08/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRITER_C
#define	_TRITER_C

#define DEBUG

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include "stdtypes.h"
#include "translat.h"
#include "trexpres.h"
#include "triter.h"
#include "troption.h"
#include "trdebug.h"
#include "trerrors.h"
#include "trlabels.h"
#include "trecho.h"
#include "trproc.h"
#include "triof.h"
#include "troutput.h"

/*	----------------------	*/
/*	allocate_for_iteration	*/
/*	----------------------	*/
ITERPTR	allocate_for_iteration()
{
	WORD	i;
	ITERPTR	iptr;
	if ((iptr = IterationHeap) != (ITERPTR) 0)
		IterationHeap = iptr->next;
	else if ((iptr = (ITERPTR) allocate( sizeof( struct otr_iteration ))) == (ITERPTR) 0)
		return( iptr );
	iptr->next = IterationList;
	IterationList = iptr;
	iptr->repeat  = 0;
	iptr->operate = 0;
	iptr->abandon = 0;
	iptr->status  = 0;
	iptr->nature  = 0;
	iptr->variable= 0;
	iptr->context = (VPTR) 0;
	iptr->usage   = 0;
	for ( i = 0; i < 16; i++ )
		iptr->operand[i] = (RESULTPTR) 0;
	return( iptr );
}

/*	-----------------	*/
/*	release_iteration	*/
/*	-----------------	*/
VOID	release_iteration()
{
	ITERPTR	iptr;
	WORD	i;
	if ((iptr = IterationList) != (ITERPTR) 0) 
	{
		IterationList = iptr->next;
		iptr->next = IterationHeap;
		for ( i=0; i < 16; i++ )
			if ( iptr->operand[i] != (RESULTPTR) 0 )
				unprotect_operand( iptr->operand[i] );
		IterationHeap = iptr;
	}
	return;
}

/*	-----------------	*/
/*	iteration_operand	*/
/*	-----------------	*/
RESULTPTR	iteration_operand()
{
	RESULTPTR	rptr=(RESULTPTR) 0;
	ITERPTR		iptr;
	if ((iptr = IterationList) != (ITERPTR) 0)
		rptr = iptr->operand[0];
	return( rptr );
}

/*	------------------------	*/
/*	check_iteration_variable	*/
/*	------------------------	*/
WORD		check_iteration_variable( vptr )
TCVARPTR 	vptr;
{
	ITERPTR		iptr;
	if (!(iptr = IterationList))
		return(0);
	else if (!( iptr->variable ))
		return(0);
	else if ( vptr->identity != iptr->variable )
		return(0);
	else	return(1);
}

/*	----------------	*/
/*	IterationOperand	*/
/*	----------------	*/
RESULTPTR	IterationOperand(n)
WORD		n;
{
	RESULTPTR	rptr=(RESULTPTR) 0;
	ITERPTR		iptr;
	if (((iptr = IterationList) != (ITERPTR) 0)
	&&  (n  < 16))
		rptr = iptr->operand[n];
	return( rptr );
}

/*	----------------	*/
/*	 select_operand 	*/
/*	----------------	*/
WORD	select_operand( rptr )
RESULTPTR	rptr;
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(30);
	if ((iptr->operand[0] = protect_operand( rptr )) != (RESULTPTR) 0)
		return( 0 );
	else	return( 30 );
}

/*	-----------	*/
/*	try_operand	*/
/*	-----------	*/
WORD	try_operand( rptr )
RESULTPTR	rptr;
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(30);
	if ((iptr->operand[0] = protect_operand( rptr )) != (RESULTPTR) 0)
		return( 0 );
	else	return( 30 );
}

/*	-------------	*/
/*	SelectOperand	*/
/*	-------------	*/
WORD	SelectOperand( rptr,n )
RESULTPTR	rptr;
WORD		n;
{
	ITERPTR	iptr;
	if (((iptr = IterationList) == (ITERPTR) 0)
	||  ( n >= 16 ))
		return(30);
	if ((iptr->operand[n] = protect_operand( rptr )) != (RESULTPTR) 0)
		return( 0 );
	else	return( 30 );
}

/*	-----------------	*/
/*	 iteration_usage	*/
/*	-----------------	*/
WORD	iteration_usage()
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return( 0 );
	else	return( iptr->usage );
}

/*	----------------------	*/
/*	adjust_iteration_usage	*/
/*	----------------------	*/
VOID	adjust_iteration_usage()
{
	ITERPTR	iptr;
	if ((iptr = IterationList) != (ITERPTR) 0)
		iptr->usage++;
	return;
}

/*	--------------	*/
/*	iteration_else	*/
/*	--------------	*/
WORD	iteration_else()
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(0);
	else if ( iptr->nature != _ITERATION_IF )
		return(iptr->nature);
	else 	
	{
		iptr->nature = _ITERATION_ELSE;
		return(_ITERATION_IF);
	}
}

/*	--------------------	*/
/*	get_iteration_labels	*/
/*	--------------------	*/
WORD	get_iteration_labels( WORD * labeltrue, WORD * labelfail )
{
	ITERPTR	iptr;
	if (!(iptr = IterationList))
		return(102);
	else 	
	{
		if ( iptr->nature == _ITERATION_REPEAT ) 
		{
			*labeltrue = iptr->abandon;
			*labelfail = iptr->operate;
		}
		else	
		{
			*labeltrue = iptr->operate;
			*labelfail = iptr->abandon;
		}
		return( 0 );
	}
}

/*	---------------------	*/
/*	get_iteration_context	*/
/*	---------------------	*/
VPTR	get_iteration_context()
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return( (VPTR) 0 );
	else	return( iptr->context );
}

/*	---------------------	*/
/*	set_iteration_context	*/
/*	---------------------	*/
WORD	set_iteration_context( vptr )
VPTR	vptr;
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return( syntax_error(16) );
	iptr->context = vptr;
	return(0);
}			

/*	-------------------	*/
/*	get_iteration_label	*/
/*	-------------------	*/
WORD	get_iteration_label(BPTR ilabel)
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(0);
	if (!( iptr->status & 1 )) { 
		sprintf(ilabel,"$%u",iptr->repeat);
		if (add_explicite_label( ilabel ))
			iptr->status |= 1;
		else	return(0);
		}
	return( iptr->repeat );
}

/*	-------------------	*/
/*	dcl_iteration_label	*/
/*	-------------------	*/
WORD	dcl_iteration_label()
{
	BYTE	ilabel[MAX_LABEL_SIZE];
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(0);
	if (!( iptr->status & 1 )) { 
		sprintf(ilabel,"$%u",iptr->repeat);
		if (add_explicite_label( ilabel ))
			iptr->status |= 1;
		else	return(0);
		}
	return( iptr->repeat );
}

/*	----------------	*/
/*	 enter_event_do 	*/
/*	----------------	*/
WORD	enter_event_do()
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(syntax_error(17));
	if ( OtrOption.ListFlag & 1 )
		echo_instruction("DO");
	iptr->status |= 0x1000;
	return(0);
}

/*	----------------	*/
/*	enter_event_then	*/
/*	----------------	*/
WORD	enter_event_then()
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(syntax_error(18));
	if ( OtrOption.ListFlag & 1 )
		echo_instruction("THEN");
	iptr->status |= 0x2000;
	return(0);
}

/*	-----------------	*/
/*	awaiting_event_do	*/
/*	-----------------	*/
WORD	awaiting_event_do()
{
	ITERPTR	iptr;
	if (((iptr = IterationList) != (ITERPTR) 0)
	&&  (iptr->nature == _ITERATION_EVENT )
	&&  ((iptr->status & 0x3000) == 0))
		return(VRAI);
 	else	return(FAUX);
}

/*	-----------------	*/
/*	dcl_operate_label	*/
/*	-----------------	*/
WORD	dcl_operate_label()
{
	BYTE	ilabel[MAX_LABEL_SIZE];
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(0);
	if (!( iptr->status & 4 )) {
	 
		sprintf(ilabel,"$%u",iptr->operate);
		if (add_explicite_label( ilabel ))
			iptr->status |= 4;
		else	return(0);
	}
	return( iptr->operate );
}

/*	-----------------	*/
/*	dcl_abandon_label	*/
/*	-----------------	*/
WORD	dcl_abandon_label()
{
	BYTE	ilabel[MAX_LABEL_SIZE];
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(0);
	if (!(iptr->status & 2)) 
	{
		sprintf(ilabel,"$%u",iptr->abandon);
		if (add_explicite_label( ilabel ))
			iptr->status |= 2;
		else	return( 0 );
	}
	return( iptr->abandon);
}

/*	-------------------	*/
/*	new_implicite_label	*/
/*	-------------------	*/
WORD	new_implicite_label()
{
	LabelCounter++;
	return( LabelCounter );
}

/*	-----------------	*/
/*	new_operate_label	*/
/*	-----------------	*/
WORD	new_operate_label()
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(0);
	else	
	{
		iptr->status &= ~4;
	 	return((iptr->operate = new_implicite_label()));
	}
}

/*	-----------------	*/
/*	new_abandon_label	*/
/*	-----------------	*/
WORD	new_abandon_label()
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(0);
	else	
	{
		iptr->status &= ~2;
	 	return((iptr->abandon = new_implicite_label()));
	}
}

/*	-----------------	*/
/*	new_iterate_label	*/
/*	-----------------	*/
WORD	new_iterate_label()
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(0);
	else 	
	{
		iptr->status &= ~1;
		return((iptr->repeat = new_implicite_label()));
	}
}

/*	-----------------	*/
/*	 enter_iteration	*/
/*	-----------------	*/
WORD		enter_iteration( type, vptr )
WORD		type;
TCVARPTR	vptr;
{
	ITERPTR	iptr;

	if ((iptr = allocate_for_iteration()) == (ITERPTR) 0)
		return(27);

	iptr->nature   = type;
	iptr->repeat   = new_implicite_label();
	iptr->operate  = new_implicite_label();
	iptr->abandon  = new_implicite_label();

	if ( vptr != (TCVARPTR) 0 ) 
		iptr->variable = vptr->identity;
	else	iptr->variable = 0;

	if ( OtrOption.ListFlag & 1 )
		echo_enter_iteration(type);

	switch ( type ) 
	{
	case _ITERATION_EACH   :
	case _ITERATION_WHILE  :
	case _ITERATION_DO     : 
	case _ITERATION_REPEAT :
	case _ITERATION_FOR    :
		if ( dcl_iteration_label() )
			return(0);
		else	return(1);
	default		       :
		return( 0 );
	}
}

#ifdef	_DEBUG_ITER_ERROR
/*	--------------------	*/
/*	debug_iteration_type	*/
/*	--------------------	*/
VOID	debug_iteration_type()
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		sysprintf("No Current Iteration\n");
	else	
	{
		switch ( iptr->nature ) 
		{
		case	_ITERATION_IF		:
			sysprintf("Iteration IF \n"); break;
		case	_ITERATION_ELSE		:
			sysprintf("Iteration ELSE \n"); break;
		case	_ITERATION_SELECT	:
			sysprintf("Iteration SELECT \n"); break;
		case	_ITERATION_TRY   	:
			sysprintf("Iteration TRY    \n"); break;
		case	_ITERATION_DO		:
			sysprintf("Iteration DO \n"); break;
		case	_ITERATION_WHILE	:
			sysprintf("Iteration WHILE \n"); break;
		case	_ITERATION_REPEAT	:
			sysprintf("Iteration REPEAT \n"); break;
		case	_ITERATION_FOR		:
			sysprintf("Iteration FOR \n"); break;
		case	_ITERATION_EVENT	:
			sysprintf("Iteration EVENT \n"); break;
		case	_ITERATION_EACH 	:
			sysprintf("Iteration EACH  \n"); break;
		default				:
			sysprintf("Iteration ??? %u \n",iptr->nature); break;
		}
	}
	return;
}
#endif

/*	-------------------	*/
/*	use_implicite_label	*/
/*	-------------------	*/
WORD	use_implicite_label( target, indent )
WORD	target;
WORD	indent;
{
	BYTE	ilabel[MAX_LABEL_SIZE];
	WORD	result;

	sprintf(ilabel,"$%u",target);
	if ( tcode_labels() )
		return((result = use_explicite_label( ilabel, indent )));
	else 	
	{
		result = use_explicite_label( ilabel, indent );
		return( target );
	}
}

/*	-------------------	*/
/*	use_iteration_label	*/
/*	-------------------	*/
WORD	use_iteration_label( indent )
WORD	indent;
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(0);
	else	return( use_implicite_label( iptr->repeat, indent ) );
}

/*	-----------------	*/
/*	use_operate_label	*/
/*	-----------------	*/
WORD	use_operate_label( indent )
WORD	indent;
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(0);
	else	return( use_implicite_label( iptr->operate, indent ) );
}

/*	-----------------	*/
/*	use_abandon_label	*/
/*	-----------------	*/
WORD	use_abandon_label( indent )
WORD	indent;
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(0);
	else	return( use_implicite_label( iptr->abandon, indent ) );
}

/*	-------------------	*/
/*	break_prior_to_case	*/
/*	-------------------	*/
WORD	break_prior_to_case()
{
	ITERPTR	iptr;
	if (!(iptr = IterationList))
		return(30);
	else if ((iptr->nature == _ITERATION_SELECT ) || (iptr->nature == _ITERATION_TRY   ))
		return( generate_goto(use_implicite_label(iptr->abandon,1)));
	else	return( 30 );
}

/*	--------------------	*/
/*	goto_operation_label	*/
/*	--------------------	*/
WORD	goto_operation_label()
{
	ITERPTR	iptr;
	if ((iptr = IterationList) != (ITERPTR) 0)
		return( generate_goto(use_implicite_label(iptr->operate,1)));
	else	return( 30 );
}

/*	-----------------	*/
/*	 use_break_label	*/
/*	-----------------	*/
WORD	use_break_label( offset )
WORD	offset;
{
	ITERPTR	iptr;
	if ((iptr = IterationList) != (ITERPTR) 0) 
	{
		do	
		{
			switch ( iptr->nature ) 
			{
			case _ITERATION_REPEAT :
			case _ITERATION_DO     :
			case _ITERATION_WHILE  :
			case _ITERATION_FOR    :
			case _ITERATION_EACH   :
				return( use_implicite_label(iptr->abandon,offset));
			}
		}
		while ((iptr = iptr->next) != (ITERPTR) 0);
	}
	return( syntax_error(19) );
}

/*	--------------------	*/
/*	break_from_iteration	*/
/*	--------------------	*/
WORD	break_from_iteration()
{
	ITERPTR	iptr;
	if ((iptr = IterationList) != (ITERPTR) 0) 
	{
		do	
		{
			switch ( iptr->nature ) 
			{
			case _ITERATION_REPEAT :
			case _ITERATION_DO     :
			case _ITERATION_WHILE  :
			case _ITERATION_FOR    :
			case _ITERATION_EACH   :
				if ( OtrOption.ListFlag & 1 )
					echo_instruction( "BREAK" );
				return( generate_goto(use_implicite_label(iptr->abandon,1)));
			}
		}
		while ((iptr = iptr->next) != (ITERPTR) 0);
	}
	return( syntax_error(20) );
}	

/*	----------------	*/
/*	 iteration_type 	*/
/*	----------------	*/
WORD	iteration_type()
{
	ITERPTR	iptr;
	if ((iptr = IterationList) == (ITERPTR) 0)
		return(0);
	else	return( iptr->nature );
}

/*	----------------	*/
/*	 implicite_goto 	*/
/*	----------------	*/
WORD	implicite_goto(xlabel)
WORD	xlabel;
{
	if ( OtrOption.ListFlag & 1 )
		echo_implicite_goto( xlabel );
	return( generate_goto(use_implicite_label(xlabel,1)));
}

/*	-----------------	*/
/*	 implicite_gosub	*/
/*	-----------------	*/
WORD	implicite_gosub(xlabel)
WORD	xlabel;
{
	return( generate_gosub(use_implicite_label(xlabel,1)));
}

/*	-------------------	*/
/*	dcl_implicite_label	*/
/*	-------------------	*/
WORD	dcl_implicite_label(xlabel)
WORD	xlabel;
{
	BYTE	ilabel[MAX_LABEL_SIZE];
	sprintf(ilabel,"$%u",xlabel);
	if (add_explicite_label( ilabel ))
		return(0);
	else	return(1);
}

/*	-----------------	*/
/*	 leave_iteration	*/
/*	-----------------	*/
WORD	leave_iteration()
{
	ITERPTR	iptr;

	trace("leave_iteration()\n");

	if ((iptr = IterationList) == (ITERPTR) 0)
		return(102);

	if ( OtrOption.ListFlag & 1 )
		echo_leave_iteration( iptr->nature );

	switch ( iptr->nature ) 
	{
	case _ITERATION_REPEAT :
	case _ITERATION_WHILE  :
	case _ITERATION_DO     :
	case _ITERATION_FOR    :
	case _ITERATION_EACH   :
		generate_iteration();
		break;
	case _ITERATION_EVENT  :
		if ( iptr->status & 0x1000 )
			generate_event_start();
		dcl_operate_label();
	}

	(void) dcl_abandon_label();
	(void) dcl_iteration_label();
	release_iteration();
	return(0);
}

/*	-----------------	*/
/*	 iteration_error	*/
/*	-----------------	*/
VOID	iteration_error()
{
	ITERPTR	iptr;
	if ((iptr = IterationList) != (ITERPTR) 0) 
	{
		switch ( iptr->nature ) 
		{
		case _ITERATION_IF :
			error_message("Expected ELSE/ENDIF"); break;
		case _ITERATION_ELSE :
			error_message("Expected ENDIF"); break;
		case _ITERATION_DO :
			error_message("Expected LOOP"); break;
		case _ITERATION_REPEAT :
			error_message("Expected UNTIL"); break;
		case _ITERATION_WHILE :
			error_message("Expected WEND"); break;
		case _ITERATION_EACH :
		case _ITERATION_FOR :
			error_message("Expected NEXT"); break;
		case _ITERATION_SELECT :
			error_message("Expected ENDSEL"); break;
		case _ITERATION_TRY    :
			error_message("Expected ENDTRY"); break;
		default			:
			error_message("Unknown iteration"); break;
		}
	}
	return;
}

/*	--------------------	*/
/*	terminate_iterations	*/
/*	--------------------	*/
VOID	terminate_iterations()
{
	while ( IterationList != (ITERPTR) 0) 
	{
		iteration_error();
		release_iteration();
	}
	LabelCounter = 1;
	return;
}

/*	---------------------	*/
/*	initialise_iterations	*/
/*	---------------------	*/
VOID	initialise_iterations()
{
	IterationList = (ITERPTR) 0;
	IterationHeap = (ITERPTR) 0;
	LabelCounter  = 1;
	return;
}

/*	-------------------	*/
/*	liberate_iterations	*/
/*	-------------------	*/
VOID	liberate_iterations()
{
	ITERPTR	iptr;
	terminate_iterations();
	while ((iptr = IterationHeap) != (ITERPTR) 0) 
	{
		IterationHeap = iptr->next;
		liberate( iptr );
	}
	return;
}

	/* --------- */
#endif	/* _TRITER_C */
	/* --------- */
