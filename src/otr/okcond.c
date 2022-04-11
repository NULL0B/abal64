#ifndef	_trcond_h
#define _trcond_h

/* #define	DEBUG_CONDITIONS */
	

/*
 *	ABAL conditional expressions are a nightmare !
 *	This is because of the boolean operators AND/OR and OX which
 *	are used equally to denote bitwise and logical operations.
 *	This is also because of the slack translation of TR and ATR
 *	which did not enforce mandatory bracing.
 */

#define	LEVELPTR struct level_control *

struct	level_control {

	WORD		negation;

/*	Operand compare Operand		*/
/*	-----------------------		*/
	WORD		operation;
	RESULTPTR	loperand;
	RESULTPTR	roperand;

/*	Operand operator Operand	*/
/*	------------------------	*/
	WORD		arithmetic;
	FACTORPTR       root;
	FACTORPTR       last;

/*	Compare Level lists	*/
/*	-------------------	*/
	WORD		combine;
	LEVELPTR	head;
	LEVELPTR	foot;
	LEVELPTR	previous;
	LEVELPTR	next;

	};

static	LEVELPTR	levelheap=(LEVELPTR) 0;

void	drop_level( LEVELPTR lptr )
{
	lptr->next = levelheap;
	levelheap  = lptr;
	return;
} 

void	conditional_cleanup()
{
	LEVELPTR	lptr;
	while ((lptr = levelheap) != (LEVELPTR) 0) {
		levelheap = lptr->next;
		liberate( lptr );
		}
	return;
}



static	LEVELPTR	allocate_for_level()
{
	LEVELPTR	lptr;
	if ((lptr = levelheap) != (LEVELPTR) 0)
		levelheap = lptr->next;
	else if (!( lptr = allocate( sizeof( struct level_control ) ) ))
		return( lptr );
	lptr->loperand = lptr->roperand = (RESULTPTR) 0;
	lptr->root = lptr->last  = (FACTORPTR) 0;
	lptr->operation = lptr->arithmetic = 0;
	lptr->combine=_LOGICAL_END;
	lptr->negation=0;
	lptr->head = lptr->foot = lptr->previous = lptr->next = (LEVELPTR) 0;
	return( lptr );
}

static	WORD use_primary_term( LEVELPTR lptr,RESULTPTR rptr )
{
	FACTORPTR	fptr;
	if ( lptr != (LEVELPTR) 0) {
		if ( lptr->negation ) {
			rptr = negate_expression( rptr );
			lptr->negation = 0;
			}
		if (!( fptr = allocate_for_factor(rptr,lptr->arithmetic) )) 
			return( syntax_error( 2891 ) );
		else	{
			if (!(fptr->previous = lptr->last))
				lptr->root = fptr;
			else	lptr->last->next = fptr;
			lptr->last = fptr;
			lptr->arithmetic = 0;
			}
		}
	return(0);
}

static	RESULTPTR	evaluate_level( LEVELPTR lptr )
{
	RESULTPTR	rptr;
	rptr = evaluate_factors( lptr->root );
	lptr->root = lptr->last  = (FACTORPTR) 0;
	return( rptr );
}		

static 	WORD	generate_conditional( LEVELPTR lptr, WORD repeat_until, WORD * truemaster, WORD * failmaster )
{
	WORD	logic;
	WORD	target=0;
	WORD	status=0;
	WORD	result;
	WORD	operation;
	if ((lptr->loperand != (RESULTPTR) 0)
	&&  (lptr->roperand != (RESULTPTR) 0)) {
		logic     = lptr->combine;
		operation = lptr->operation;
		switch (logic) {
			case _LOGICAL_END:	
			case _LOGICAL_AND:
				if (!(repeat_until))
					operation = reverse_compare( operation );
				break;
			case _LOGICAL_OR : /* AND LOGIC : INVCMP : TRUE	 */
				if (repeat_until)
					operation = reverse_compare( operation );
				break;
			}
		if ( repeat_until ) {
			if ( logic == _LOGICAL_AND )
				logic = _LOGICAL_OR;
			else	logic = _LOGICAL_AND;
			}
		else	{ 
			if ( logic == _LOGICAL_OR ) {
				if ( truemaster != (WORD *) 0  ) {
					if (!(*truemaster))
						*truemaster = new_implicite_label();
					logic  = _LOGICAL_USE;
					target = *truemaster;
					}
				}
			else if ( logic == _LOGICAL_AND ) {
				if ( failmaster != (WORD *) 0  ) {
					if (!(*failmaster))
						*failmaster = new_implicite_label();
					logic  = _LOGICAL_USE;
					target = *failmaster;
					}
				}

			}
		if ((result = evaluate_comparison(operation,lptr->loperand,lptr->roperand,logic,target)) != 0 )
			status=result;
		}
	return(status);
}

static	WORD generate_conditionals(LEVELPTR xptr,LEVELPTR hptr,WORD repeat_until,WORD master,WORD * tmaster,WORD * fmaster)
{
	WORD		truelabel=0;
	LEVELPTR	lptr;
	WORD		status=0;
	WORD		result;
	WORD		logic;
	WORD		operation;
	WORD		numbers;
	WORD		memory=_LOGICAL_END;

	/* if no conditional combination list : then generate compare */
	/* ---------------------------------------------------------- */
	if (!( hptr->head ))
		status = generate_conditional( hptr, repeat_until, tmaster,fmaster);

	else	{
		/* check for logical ambiguity mixing AND/OR/OX */
		/* -------------------------------------------- */
		for ( 	lptr=hptr->head, memory=_LOGICAL_END;
			lptr != (LEVELPTR) 0;
			lptr = lptr->next ) {
			if ( memory == _LOGICAL_END )
				memory = lptr->combine;
			else if ( lptr->combine == _LOGICAL_END )
				continue;
			else if ( lptr->combine != memory ) {
				sysprintf("ambiguous logical conditions\n");
				break;
				}
			}

		/* #include "dbcond.c" */

		for ( 	lptr=hptr->head;
			lptr != (LEVELPTR) 0;
			lptr = lptr->next) {
			if ( repeat_until ) {
				if ((result = generate_conditionals(hptr,lptr,repeat_until,memory,tmaster,fmaster)) != 0)
					status = result;
				continue;
				}
			else	{
				switch ( lptr->combine ) {
					case	_LOGICAL_AND	:
						if ((result = generate_conditionals(hptr,lptr,repeat_until, memory &truelabel,fmaster)) != 0)
							status = result;
						break;
					case	_LOGICAL_OR 	:
						if ((result = generate_conditionals(hptr,lptr,repeat_until, memorytmaster, &truelabel)) != 0)
							status = result;
						break;
					default			:
						if ((result = generate_conditionals(hptr,lptr,repeat_until, memorytmaster,fmaster)) != 0)
							status = result;
						break;
					}
				}
			}
		if ( truelabel ) {
			status = dcl_implicite_label( truelabel );
			}

		}
	while ((lptr=hptr->head) != (LEVELPTR) 0) {
		hptr->head = lptr->next;
		drop_level( lptr );
		}
	return(status);
}

static	WORD integrate_levels(LEVELPTR hptr,LEVELPTR lptr)
{
	LEVELPTR	xptr;
	while ((xptr=lptr->head) != (LEVELPTR) 0) {
		lptr->head = xptr->next;
		if (!( xptr->previous = hptr->foot ))
			hptr->head = xptr;
		else	hptr->foot->next = xptr;
		hptr->foot = xptr;
		}
	drop_level( lptr );
	return(0);
}

static	WORD integrate_result(LEVELPTR hptr,LEVELPTR lptr)
{
	WORD	status;
	status = use_primary_term( hptr, lptr->loperand );
	drop_level( lptr );
	return( status );
}

static	WORD terminate_level(LEVELPTR hptr,LEVELPTR lptr,WORD repeat_until)
{
	WORD		state;

	if ( lptr != (LEVELPTR) 0) {

		if ( lptr->head ) {
			if ( hptr != (LEVELPTR) 0) {
				if (!( lptr->previous = hptr->foot ))
					hptr->head = lptr;
				else	hptr->foot->next = lptr;
				hptr->foot = lptr;
				return(0);
				}
			else	return( generate_conditionals(hptr, lptr,repeat_until,_LOGICAL_END, (WORD *) 0,(WORD *) 0 ) );
			}
		else if (!( lptr->loperand )) { 
			/* no left operand so : unary operand */
			if (!( lptr->loperand = evaluate_level( lptr ) )) {
				/* no operand : maybe combinatory logic */
				if ( hptr != (LEVELPTR) 0) 
					return( integrate_levels( hptr, lptr ) );
				else	return( generate_conditionals(hptr, lptr,repeat_until,_LOGICAL_END,(WORD *) 0,(WORD *) 0 ) );
				}
			else if ( hptr != (LEVELPTR)0) 
				return( integrate_result( hptr, lptr ) );
			else	return( generate_conditionals(hptr, lptr,repeat_until,(WORD *) 0,(WORD *) 0 ) );
			}
		else if ( lptr->operation != 0) {
			if (!( lptr->roperand ))
				lptr->roperand = evaluate_level( lptr );
			}

		if ( hptr != (LEVELPTR) 0) {
			if (!( lptr->previous = hptr->foot ))
				hptr->head = lptr;
			else	hptr->foot->next = lptr;
			hptr->foot = lptr;
			}
		else	return( generate_conditionals(hptr, lptr,repeat_until, (WORD *) 0,(WORD *) 0 ) );
		}
	return(0);
}

static	WORD use_arithmetical_operator(LEVELPTR	lptr,WORD opcode)
{
	if ( lptr != (LEVELPTR) 0) {
		if ( opcode == '-' ) {
			/* watch out for negation */
			if (!( lptr->loperand )) { 
				if (!( lptr->root     )) {
					/* nothing happend yet */
					if (!( lptr->negation )) {
						lptr->negation = 1; 
						return(0);
						}
					else	{
						/* double negation */	
						lptr->negation = 0;
						return(0);
						}
					}
				else	{
					lptr->arithmetic = opcode;
					return(0);
					}	
				}
			else if (!( lptr->arithmetic )) {
				lptr->arithmetic = opcode;
				return(0);
				}	
			else if (!( lptr->negation )) {
				lptr->negation = 1;
				return(0);
				}
			else	{
				lptr->negation = 0;
				return(0);
				}
			}
		lptr->arithmetic = opcode;
		}
	return(0);
}

static	WORD use_compare_operator(LEVELPTR lptr,WORD opcode)
{
	if ( lptr != (LEVELPTR) 0) {
		if (!( lptr->loperand ))
			lptr->loperand = evaluate_level( lptr );
		else	return( syntax_error( 2891 ) );
		lptr->operation = opcode;
		}
	return(0);
}

static	WORD use_logical_operator(LEVELPTR lptr, WORD opcode)
{
	if ( lptr ) {
		if (!( lptr->foot ))
			lptr->combine = opcode;
		else	lptr->foot->combine = opcode;
		}

	return(0);
}

static	WORD	parse_conditionals(LEVELPTR host,WORD repeat_until,WORD mode)
{
	RESULTPTR	rptr;
	WORD		operation;
	LEVELPTR	lptr;

	if (!(lptr = allocate_for_level()))
		return( allocation_failure() );
	else if ( repeat_until )
		lptr->combine = _LOGICAL_OR;
	while ( remove_white_space() ) {

		if ( is_left_brace() ) {
			if (!( parse_conditionals(lptr,repeat_until,1)))
				continue;
			else	return( syntax_error( 12121 ) );
			}
		else if ( is_right_brace() ) 
			break;
		else if ((operation = comparison_operator(repeat_until)) != 0) {
			if (( use_compare_operator(lptr,operation) )) 
				return( syntax_error( 12121 ) );
			else	continue;
			}
		else if ((operation = is_numeric())) {
			if (!( get_token() )) {
				if ((operation != '/')
				&&  (operation != '-'))
					return( syntax_error( 12121 ) );
				}
			else if (!( rptr = numeric_term() ))
				return( syntax_error( 12121 ) );
			else if (( use_primary_term(lptr, rptr ) ))
				return( syntax_error( 12121 ) );
			else	continue;
			}
		else if ( is_mnemonic("AND") ) {
			if (( use_logical_operator(lptr, _LOGICAL_AND ) ))
				return( syntax_error( 12121 ) );
			else	continue;
			}
		else if ( is_mnemonic("OR") ) {
			if (( use_logical_operator(lptr, _LOGICAL_OR ) ))
				return( syntax_error( 12121 ) );
			else	continue;
			}
		else if ( is_mnemonic("XOR") ) {
			if (( use_logical_operator(lptr, _LOGICAL_OX  ) ))
				return( syntax_error( 12121 ) );
			else	continue;
			}

		if ((operation = arithmetical_operator()) != 0) {
			if (( use_arithmetical_operator(lptr,operation) )) 
				return( syntax_error( 12121 ) );
			else	continue;
			}
		else if (!( get_token() ))
			break;
		else if (!( rptr = primary_evaluation() ))
			return( syntax_error( 12121 ) );
		else if (( use_primary_term(lptr, rptr ) ))
			return( syntax_error( 12121 ) );
		else	continue;

		}
	return(terminate_level(host,lptr,repeat_until));
}


WORD	terminate_conditionals()
{
	return(0);
}

WORD	new_conditional_expression(WORD repeat_until)
{
#ifdef	DEBUG_CONDITIONS
	sysprintf("\n %s : ",(repeat_until ? "until" : "while"));
#endif
	return( parse_conditionals((LEVELPTR) 0,repeat_until,0));
}


#endif	/* _trcond_h */
	/* --------- */

