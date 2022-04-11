#ifndef	_trcond_h
#define _trcond_h

#undef	DEBUG_CONDITIONS

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
	WORD		ltype;
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
	LEVELPTR	parent;

	};

static	LEVELPTR	levelheap=(LEVELPTR) 0;

/*	----------	*/
/*	drop_level	*/
/*	----------	*/
void	drop_level( LEVELPTR lptr )
{
	lptr->next = levelheap;
	levelheap  = lptr;
	return;
} 

/*	-------------------	*/
/*	conditional_cleanup	*/
/*	-------------------	*/
void	conditional_cleanup()
{
	LEVELPTR	lptr;
	while ((lptr = levelheap) != (LEVELPTR) 0) 
	{
		levelheap = lptr->next;
		liberate( lptr );
	}
	return;
}

/*	------------------	*/
/*	allocate_for_level	*/
/*	------------------	*/
static	LEVELPTR	allocate_for_level()
{
	LEVELPTR	lptr;
	if ((lptr = levelheap) != (LEVELPTR) 0)
		levelheap = lptr->next;
	else if (!( lptr = allocate( sizeof( struct level_control ) ) ))
		return( lptr );
	lptr->loperand = lptr->roperand = (RESULTPTR) 0;
	lptr->ltype = _TYPE_NUMERIC;
	lptr->root = lptr->last  = (FACTORPTR) 0;
	lptr->operation = lptr->arithmetic = 0;
	lptr->combine=_LOGICAL_END;
	lptr->negation=0;
	lptr->parent = lptr->head = lptr->foot = lptr->previous = lptr->next = (LEVELPTR) 0;
	return( lptr );
}

/*	------------------------	*/
/*	pending_logical_operator	*/
/*	------------------------	*/
static	WORD	pending_logical_operator( LEVELPTR lptr )
{
	if ( lptr ) 
	{
		if (!( lptr->foot )) 
		{
			if ( lptr->combine != _LOGICAL_END )
				return(1);
			else	return(0);
		}
		else if ( lptr->foot->combine != _LOGICAL_END )
			return(1);
		else	return(0);
	}
	return(0);
}

/*	----------------	*/
/*	use_primary_term	*/
/*	----------------	*/
static	WORD use_primary_term( LEVELPTR lptr,RESULTPTR rptr )
{
	FACTORPTR	fptr;
	if ( pending_logical_operator(lptr ) )
		return(1);
	else if ( lptr != (LEVELPTR) 0) 
	{
		if ( lptr->negation ) 
		{
			rptr = negate_expression( rptr );
			lptr->negation = 0;
		}
		if (!( fptr = allocate_for_factor(rptr,lptr->arithmetic) )) 
			return( syntax_error( 2891 ) );
		else	
		{
			if (!(fptr->previous = lptr->last))
				lptr->root = fptr;
			else	lptr->last->next = fptr;
			lptr->last = fptr;
			lptr->arithmetic = 0;
		}
	}
	return(0);
}

/*	--------------	*/
/*	evaluate_level	*/
/*	--------------	*/
static	RESULTPTR	evaluate_level( LEVELPTR lptr )
{
	RESULTPTR	rptr;
	rptr = evaluate_factors( lptr->root );
	lptr->root = lptr->last  = (FACTORPTR) 0;
	return( rptr );
}		

/*	-------------	*/
/*	reverse_logic	*/
/*	-------------	*/
static	WORD	reverse_logic(LEVELPTR lptr, WORD * label )
{
	WORD	operation;
	operation = reverse_compare( lptr->operation );

#ifdef	DEBUG_CONDITIONS
	sysprintf("reverse_logic()\n");
#endif
	if (!( *label )) 
		*label = new_implicite_label();

	return( evaluate_comparison(operation,lptr->loperand,lptr->roperand,_LOGICAL_USE, *label ) );
}

/*	-------------	*/
/*	forward_logic	*/
/*	-------------	*/
static	WORD	forward_logic(LEVELPTR lptr, WORD * label )
{
#ifdef	DEBUG_CONDITIONS
	sysprintf("forward_logic()\n");
#endif
	if (!( *label )) 
		*label = new_implicite_label();

	return( evaluate_comparison(lptr->operation,lptr->loperand,lptr->roperand,_LOGICAL_USE, *label ) );
}

/*	--------------------	*/
/*	generate_repeatuntil	*/
/*	--------------------	*/
static 	WORD	generate_repeatuntil( LEVELPTR lptr, WORD master, WORD * truemaster, WORD * failmaster )
{
	WORD	target=0;
	WORD	status=0;

	if (lptr->loperand != (RESULTPTR) 0) 
	{
		if (!(lptr->roperand))
			return( syntax_error( 748 ) );

		switch (lptr->combine) 
		{

		case _LOGICAL_END:

			switch ( master ) 
			{
			case	_LOGICAL_END	:
				return( reverse_logic( lptr, truemaster ) );
			case	_LOGICAL_AND	:
				return( forward_logic( lptr, failmaster ) );
			case	_LOGICAL_OX 	:
			case	_LOGICAL_OR 	:
				return( reverse_logic( lptr, truemaster ) );
			}

		case _LOGICAL_AND:
			/* ---------------------------------- */
			/* this and something else	      */
			/* if this fails then use master fail */
			/* ---------------------------------- */
			return( forward_logic( lptr, failmaster ) );

		case _LOGICAL_OX :
		case _LOGICAL_OR : /* OR  LOGIC : INVCMP : FALSE */

			/* ------------------------------------ */
			/* this or something else 		*/
			/* if this succeeds then master true	*/
			/* no inversion needed !		*/
			/* ------------------------------------ */
			return( reverse_logic( lptr, truemaster ) );

		default		:
			status = syntax_error( 747 );
		}
	}
	return( status );

}

/*	------------------------	*/
/*	generate_end_conditional	*/
/*	------------------------	*/
static 	WORD	generate_end_conditional( LEVELPTR lptr, WORD * truemaster, WORD * failmaster, WORD nesting )
{
	if (!(lptr->loperand))
		return(0);
	else if (!( lptr->roperand ))
		return( syntax_error( 748 ) );
	else	return( reverse_logic( lptr, failmaster ) );
}

/*	------------------------	*/
/*	generate_and_conditional	*/
/*	------------------------	*/
static 	WORD	generate_and_conditional( LEVELPTR lptr, WORD * truemaster, WORD * failmaster, WORD nesting )
{
	if (!(lptr->loperand))
		return(0);
	else if (!( lptr->roperand ))
		return( syntax_error( 748 ) );
	else	return( reverse_logic( lptr, failmaster ) );
}

/*	-------------------------	*/
/*	 generate_or_conditional	*/
/*	-------------------------	*/
static 	WORD	generate_or_conditional( LEVELPTR lptr, WORD * truemaster, WORD * failmaster, WORD nesting )
{
	if (!(lptr->loperand))
		return(0);
	else if (!( lptr->roperand ))
		return( syntax_error( 748 ) );
	else	return( forward_logic( lptr, truemaster ) );
}

/*	--------------------------------------------------------------------------------------------		*/
/*	h y b r i d  _ c o n d i t i o n a l s ( masterlogic, hptr, truelabel, falselabel, nesting )		*/
/*	--------------------------------------------------------------------------------------------		*/

static	WORD generate_new_conditionals( 
		WORD 		masterlogic,
		LEVELPTR 	hptr, 
		WORD 		* truelabel,
		WORD 		* falselabel, 
		WORD nesting		);

static	WORD hybrid_conditionals( 
		WORD 		masterlogic,
		LEVELPTR 	hptr, 
		WORD 		* truelabel,
		WORD 		* falselabel, 
		WORD nesting		)
{
	LEVELPTR	lptr;
	WORD		status=0;
	WORD		result=0;

	for ( 	lptr=hptr->head; lptr != (LEVELPTR) 0; lptr = lptr->next) 
	{
		switch ( lptr->combine ) 
		{
		case	_LOGICAL_END	:	 
			if (!( lptr->head )) 
			{
				if ((result = generate_end_conditional( lptr, truelabel,falselabel,nesting)) !=0)
					status = result;
			}
			else if ((result = generate_new_conditionals(lptr->combine,lptr,truelabel,falselabel,(nesting+1))) != 0)
				status = result;
			continue;

		case	_LOGICAL_AND	:
			if (!( lptr->head )) 
			{
				if ((result = generate_and_conditional( lptr, truelabel,falselabel,nesting)) !=0)
					status = result;
			}
			else if ((result = generate_new_conditionals(lptr->combine,lptr,truelabel,falselabel,(nesting+1))) != 0)
				status = result;
			continue;

		case	_LOGICAL_OR	:	 
			if (!( lptr->head )) 
			{
				if ((result = generate_or_conditional( lptr, truelabel,falselabel,nesting)) !=0)
					status = result;
			}
			else if ((result = generate_new_conditionals(hptr->combine, lptr,truelabel,falselabel,(nesting+1))) != 0)
				status = result;
			continue;
		}						
	}
	return( status );

}

/*	--------------	*/
/*	parental_logic	*/
/*	--------------	*/
static	WORD	parental_logic( LEVELPTR lptr )
{
	while ( lptr ) 
	{
		if ( lptr->combine != _LOGICAL_END )
			return( lptr->combine );
		else 	lptr = lptr->parent;
	}
	return( _LOGICAL_END );
}

/*	-----------------------------------------------------------------------------------------------		*/
/*	g e n e r a t e _ c o n d i t i o n a l s ( masterlogic, hptr, truelabel, falselabel, nesting )		*/
/*	-----------------------------------------------------------------------------------------------		*/

static	WORD generate_new_conditionals( 
		WORD 		masterlogic,
		LEVELPTR 	hptr, 
		WORD 		* truelabel,
		WORD 		* falselabel, 
		WORD nesting		)
{
	WORD		templabel=0;
	WORD		thislabel=0;
	LEVELPTR	lptr;
	WORD		status=0;
	WORD		result=0;
	WORD		opcode=_LOGICAL_END;
	WORD		whoops=0;
	WORD		i;

#ifdef	DEBUG_CONDITIONS
	sysprintf("generate_new_conditionals( masterlogic=%d ) \n",masterlogic);
#endif
	/* ---------------------------------------------------------- */
	/* if no conditional combination list : then generate compare */
	/* ---------------------------------------------------------- */
	if (!( hptr->head )) 
	{
		switch ( parental_logic( hptr ) ) 
		{
		case	_LOGICAL_END	:
			status = generate_end_conditional( hptr, truelabel,falselabel,nesting);
			break;
		case	_LOGICAL_AND	:
			status = generate_and_conditional( hptr, truelabel,falselabel,nesting);
			break;
		case	_LOGICAL_OR 	:
			status = generate_or_conditional( hptr, truelabel,falselabel,nesting);
			break;
		}
	}
	else	
	{
		/* ------------------------------------------------------ */
		/* Scan this level to detect Boolean Combinational Nature */
		/* ------------------------------------------------------ */
		for ( 	lptr=hptr->head; lptr != (LEVELPTR) 0; lptr = lptr->next) 
		{
			if ( opcode == _LOGICAL_END )
				opcode = lptr->combine;

			else if ( lptr->combine == _LOGICAL_END )
				continue;

			else if ( opcode != lptr->combine ) 
			{
				/* ------------------------------------ */
				/* mixed booleans require hybrid vigour */
				/* ------------------------------------ */
				issue_warning( 19 );
				return(hybrid_conditionals(parental_logic( hptr ) /* masterlogic */,hptr,truelabel,falselabel,nesting));
				break;
			}
		}

		/* ----------------------- */
		/* allocate or local label */
		/* ----------------------- */
		if ( parental_logic( hptr ) /* masterlogic */ != _LOGICAL_END ) 
			thislabel = new_implicite_label();

		/* ------------------------- */
		/* Distinguish between types */
		/* ------------------------- */
		switch ( opcode ) 
		{
		case	_LOGICAL_AND	:

			/* ------------------------------ */
			/* IF NOT COMPARE THEN GOTO FALSE */
			/* ------------------------------ */
#ifdef	DEBUG_CONDITIONS
			sysprintf("_LOGICAL_AND\n");
#endif
			for ( 	lptr=hptr->head; lptr != (LEVELPTR) 0; lptr = lptr->next) 
			{
				if (!( lptr->head )) 
				{
					if ( lptr->combine != _LOGICAL_END ) 
					{
						if ((result = generate_and_conditional( lptr, 
							( parental_logic( hptr ) != _LOGICAL_END ? &thislabel :  truelabel),falselabel,nesting)) !=0)
							status = result;
					}
					else 	
					{
						if ( parental_logic( hptr ) == _LOGICAL_OR ) 
						{
							if ((result = generate_or_conditional( lptr,truelabel,( parental_logic( hptr ) 
								!= _LOGICAL_END ? &thislabel : falselabel),nesting)) !=0)
								status = result;
						}
						else if ( parental_logic( lptr->parent ) == _LOGICAL_OR ) 
						{
							if ((result = generate_or_conditional( lptr,truelabel,( parental_logic( hptr ) 
								!= _LOGICAL_END ? &thislabel : falselabel),nesting)) !=0)
								status = result;
						}
						else if ((result = generate_and_conditional( lptr, ( parental_logic( hptr ) 
							!= _LOGICAL_END ? &thislabel :  truelabel),falselabel,nesting)) !=0)
							status = result;
					}
				}
				else 	
				{
					/* --------------------------------------------- */
					/* Recursive call for generation of conditionals */
					/* --------------------------------------------- */
					templabel = new_implicite_label();

					if ( lptr->combine == _LOGICAL_END ) 
					{
						if ((result = generate_new_conditionals(lptr->combine, lptr, truelabel ,falselabel,(nesting+1))) != 0)
							status = result;
					}
					else	
					{
						if ((result = generate_new_conditionals(lptr->combine, lptr,&templabel,falselabel,(nesting+1))) != 0)
							status = result;
					}					
					dcl_implicite_label(templabel);
				}
			}
			break;

		case	_LOGICAL_END	:

			/* ------------------------------ */
			/* IF NOT COMPARE THEN GOTO FALSE */
			/* ------------------------------ */
			for ( 	lptr=hptr->head; lptr != (LEVELPTR) 0; lptr = lptr->next) 
			{
				if (!( lptr->head )) 
				{
					if ((result = generate_end_conditional( lptr, ( parental_logic( hptr ) 
						!= _LOGICAL_END ? &thislabel :  truelabel),falselabel,nesting)) !=0)
						status = result;
				}
				else 	
				{
					/* --------------------------------------------- */
					/* Recursive call for generation of conditionals */
					/* --------------------------------------------- */
					if ((result = generate_new_conditionals(lptr->combine, lptr,( parental_logic( hptr ) 
						!= _LOGICAL_END ? &thislabel : truelabel),falselabel,(nesting+1))) != 0)
						status = result;
				}
			}
			break;

		case	_LOGICAL_OR	:

#ifdef	DEBUG_CONDITIONS
			sysprintf("_LOGICAL_OR\n");
#endif
			/* ------------------------- */
			/* IF COMPARE THEN GOTO TRUE */
			/* ------------------------- */
			for ( 	lptr=hptr->head; lptr != (LEVELPTR) 0; 	lptr = lptr->next) 
			{
				if (!( lptr->head )) 
				{
					if ( lptr->combine != _LOGICAL_END ) 
					{
						if ((result = generate_or_conditional( lptr, truelabel ,
							( parental_logic( hptr ) != _LOGICAL_END ? &thislabel :  falselabel),nesting)) !=0)
							status = result;
					}
					else if ( parental_logic( lptr->parent ) == _LOGICAL_OR ) 
					{
						if ((result = generate_or_conditional( lptr, truelabel ,
							( parental_logic( hptr ) != _LOGICAL_END ? &thislabel :  falselabel),nesting)) !=0)
							status = result;
					}
					else 	
					{
						if ((result = generate_end_conditional( lptr, 
							( parental_logic( hptr ) != _LOGICAL_END ? &thislabel : truelabel ), falselabel,nesting)) !=0)
							status = result;
					}
				}
				else 	
				{
					/* --------------------------------------------- */
					/* Recursive call for generation of conditionals */
					/* --------------------------------------------- */
					templabel = new_implicite_label();

					if ( lptr->combine == _LOGICAL_END ) 
					{
						if ((result = generate_new_conditionals(lptr->combine, lptr, truelabel ,falselabel,(nesting+1))) != 0)
							status = result;
					}
					else if ((result = generate_new_conditionals(lptr->combine, lptr,truelabel ,&templabel,(nesting+1))) != 0)
						status = result;

					dcl_implicite_label(templabel);
				}
			}
			break;
		}

		/* ----------------------- */
		/* Declare our local label */
		/* ----------------------- */
		if ( thislabel ) 
			status = dcl_implicite_label( thislabel );
	}

	/* ---------------------------- */
	/* drop all from this level now */
	/* ---------------------------- */
	while ((lptr=hptr->head) != (LEVELPTR) 0) 
	{
		hptr->head = lptr->next;
		drop_level( lptr );
	}
	return(status);
}

/*	---------------------	*/
/*	generate_repeatuntils	*/
/*	---------------------	*/
static	WORD generate_repeatuntils(WORD terminate,LEVELPTR hptr,WORD * tmaster,WORD * fmaster)
{
	WORD		thislabel=0;
	LEVELPTR	lptr;
	WORD		status=0;
	WORD		result=0;
	WORD		opcode=_LOGICAL_END;

	/* ---------------------------------------------------------- */
	/* if no conditional combination list : then generate compare */
	/* ---------------------------------------------------------- */
	if (!( hptr->head ))
		status = generate_repeatuntil( hptr, terminate, tmaster,fmaster);

	else	
	{
		for ( 	lptr=hptr->head;
			lptr != (LEVELPTR) 0;
			lptr = lptr->next) 
		{
			if ( opcode == _LOGICAL_END )
				opcode = lptr->combine;
			else if ( lptr->combine == _LOGICAL_END )
				break;
			else if ( opcode != lptr->combine ) 
			{
				issue_warning( 19 );
				break;
			}
		}
		for ( 	lptr=hptr->head;
			lptr != (LEVELPTR) 0;
			lptr = lptr->next) 
		{
			switch ( hptr->combine ) 
			{
			case	_LOGICAL_AND	:
				/* ----------------------------------- */
				/* false will quit, true must continue */
				/* ----------------------------------- */
				if (!( lptr->head )) 
				{
					if ((result = generate_repeatuntil( lptr, hptr->combine, &thislabel,fmaster)) !=0)
						status = result;
				}
				else if ((result = generate_repeatuntils(hptr->combine,lptr,&thislabel,fmaster)) != 0)
					status = result;
				continue;

			case	_LOGICAL_END	:	 
			case	_LOGICAL_OR	:	 
				/* ------------------------------------- */
				/* false will continue, true may operate */
				/* ------------------------------------- */
				if (!( lptr->head )) 
				{
					if ((result = generate_repeatuntil( lptr, hptr->combine, tmaster,&thislabel)) !=0)
						status = result;
				}
				else if ((result = generate_repeatuntils(hptr->combine, lptr,tmaster,&thislabel)) != 0)
					status = result;
				continue;
			}
		}						
		if ( thislabel ) 
			status = dcl_implicite_label( thislabel );
	}
	while ((lptr=hptr->head) != (LEVELPTR) 0) 
	{
		hptr->head = lptr->next;
		drop_level( lptr );
	}
	return(status);
}

/*	------------------	*/
/*	flush_conditionals	*/
/*	------------------	*/
static	WORD flush_conditionals(LEVELPTR hptr,WORD repeat_until)
{
	WORD	labeltrue;
	WORD	labelfail;
	WORD	result;
	if (( result = get_iteration_labels( &labeltrue, &labelfail ))!=0)
		return( result );
	else if (!( repeat_until ))
		return( generate_new_conditionals(_LOGICAL_END,hptr,&labeltrue,&labelfail,0) );
	else if (!( repeat_until & 2 ))
		return( generate_repeatuntils(_LOGICAL_END,hptr,&labeltrue,&labelfail) );
	else	return( generate_new_conditionals(_LOGICAL_END,hptr,&labeltrue,&labelfail,0) );
}

/*	----------------	*/
/*	integrate_levels	*/
/*	----------------	*/
static	WORD integrate_levels(LEVELPTR hptr,LEVELPTR lptr)
{
	LEVELPTR	xptr;
#ifdef	DEBUG_CONDITIONS
	sysprintf("integrate levels\n");
#endif
	while ((xptr=lptr->head) != (LEVELPTR) 0) 
	{
		lptr->head = xptr->next;
		if (!( xptr->previous = hptr->foot ))
			hptr->head = xptr;
		else	hptr->foot->next = xptr;
		hptr->foot = xptr;
		xptr->parent=hptr;
	}
	drop_level( lptr );
	return(0);
}

/*	----------------	*/
/*	integrate_result	*/
/*	----------------	*/
static	WORD integrate_result(LEVELPTR hptr,LEVELPTR lptr)
{
	WORD	status;
	status = use_primary_term( hptr, lptr->loperand );
	drop_level( lptr );
	return( status );
}

/*	-----------------	*/
/*	 terminate_level	*/
/*	-----------------	*/
static	WORD terminate_level(LEVELPTR hptr,LEVELPTR lptr,WORD repeat_until)
{

#ifdef	DEBUG_CONDITIONS
	sysprintf("terminate  level \n");
#endif
	if ( lptr != (LEVELPTR) 0) 
	{
		if ( lptr->head ) 
		{
			if ( hptr != (LEVELPTR) 0) 
			{
				if (!( lptr->previous = hptr->foot ))
					hptr->head = lptr;
				else	hptr->foot->next = lptr;
				hptr->foot = lptr;
				lptr->parent=hptr;
				return(0);
			}
			else	
			{
				return( flush_conditionals(lptr,repeat_until ));
			}
		}
		else if (!( lptr->loperand )) 
		{ 
			/* ---------------------------------- */
			/* no left operand so : unary operand */
			/* ---------------------------------- */
			if (!( lptr->loperand = evaluate_level( lptr ) )) 
			{
				/* ------------------------------------ */
				/* no operand : maybe combinatory logic */
				/* ------------------------------------ */
				if ( hptr != (LEVELPTR) 0) 
					return( integrate_levels( hptr, lptr ) );
				else	return( flush_conditionals(lptr,repeat_until ));
			}
			else if ( hptr != (LEVELPTR)0) 
				return( integrate_result( hptr, lptr ) );
			else	return( flush_conditionals( lptr,repeat_until ));
		}
		else if ( lptr->operation != 0) 
		{
			if (!( lptr->roperand ))
				lptr->roperand = evaluate_level( lptr );
		}
		if ( hptr != (LEVELPTR) 0) 
		{
			if (!( lptr->previous = hptr->foot ))
				hptr->head = lptr;
			else	hptr->foot->next = lptr;
			hptr->foot = lptr;
			lptr->parent=hptr;
			return(0);
		}
		else	
		{
			return( flush_conditionals(lptr,repeat_until));
		}
	}
	return(0);
}

/*	-------------------------	*/
/*	use_arithmetical_operator	*/
/*	-------------------------	*/
static	WORD use_arithmetical_operator(LEVELPTR	lptr,WORD opcode)
{
	RESULTPTR	optr;

	if ( lptr != (LEVELPTR) 0) 
	{
		if ( opcode == '-' ) 
		{
			/* ---------------------- */
			/* watch out for negation */
			/* ---------------------- */
			if ( lptr->operation )
				optr = lptr->roperand;
			else 	optr = lptr->loperand;

			if (!( optr )) {
			 
				if (!( lptr->root )) 
				{
					/* ------------------- */
					/* nothing happend yet */
					/* ------------------- */
					if (!( lptr->negation )) 
					{
						lptr->negation = 1; 
						return(0);
					}
					else	
					{
						/* --------------- */
						/* double negation */	
						/* --------------- */
						lptr->negation = 0;
						return(0);
					}
				}
				else	
				{
					lptr->arithmetic = opcode;
					return(0);
				}	
			}
			else if (!( lptr->arithmetic )) 
			{
				lptr->arithmetic = opcode;
				return(0);
			}	
			else if (!( lptr->negation )) 
			{
				lptr->negation = 1;
				return(0);
			}
			else	
			{
				lptr->negation = 0;
				return(0);
			}
		}
		lptr->arithmetic = opcode;
	}
	return(0);
}

/*	--------------------	*/
/*	use_compare_operator	*/
/*	--------------------	*/
static	WORD use_compare_operator(LEVELPTR lptr,WORD opcode)
{
	if ( lptr != (LEVELPTR) 0) 
	{
		if (!( lptr->loperand )) 
		{
			if (!( lptr->loperand = evaluate_level( lptr ) ))
				return( syntax_error( 2891 ) );
		}
		else	return( syntax_error( 2891 ) );

		lptr->operation = opcode;
		lptr->ltype = result_type( lptr->loperand ); /* not used */
	}
	return(0);
}

/*	--------------------	*/
/*	use_logical_operator	*/
/*	--------------------	*/
static	WORD use_logical_operator(LEVELPTR lptr, WORD opcode)
{
	if ( pending_logical_operator(lptr) )
		return(1);

	else if ( lptr ) 
	{
		/* -------------------------------------- */
		/* test something happening at this level */
		/* -------------------------------------- */
		if  (  lptr->root ) 
		{
			/* -------------- */
		 	/* pending factor */
			/* -------------- */
			if ( lptr->arithmetic )
				return(1);

			switch ( opcode ) 
			{
			case	_LOGICAL_AND	:
				lptr->arithmetic = '&';
				break;
			case	_LOGICAL_OR 	:
				lptr->arithmetic = '|'; 
				break;
			case	_LOGICAL_OX 	:
				lptr->arithmetic = '^';
				break;
			default			:
				return(1);
			}
			return( 0 );
		}
		else	
		{
			if (!( lptr->foot ))
				lptr->combine = opcode;
			else	lptr->foot->combine = opcode;
		}
	}
	return(0);
}

/*	------------------	*/
/*	parse_conditionals	*/
/*	------------------	*/
static	WORD	parse_conditionals(LEVELPTR host,WORD repeat_until,WORD bracing,WORD nesting)
{
	WORD		status=0;
	RESULTPTR	rptr;
	WORD		operation;
	LEVELPTR	lptr;
	RESULTPTR	secondary_evaluation();
	WORD	i;
	WORD		complexe=0;
	if (!(lptr = allocate_for_level()))
		return( allocation_failure() );
#ifdef	DEBUG_CONDITIONS
	for (i=0; i < nesting; i++ )
		sysprintf("\t");	
	sysprintf("entry parse_conditionals: %s \n",(host ? "host" : "nohost" ));
#endif

	while ( remove_white_space() ) 
	{
		if ( is_left_brace() ) 
		{
			if (!( parse_conditionals(lptr,repeat_until,1,(nesting+1))))
				continue;
			else	return( syntax_error( 9021 ) );
		}
		else if ( is_right_brace() ) 
		{
			if ( bracing )
				bracing--;
			else	return( syntax_error( 9022 ) );
			break;
		}
		else if ((operation = comparison_operator(repeat_until)) != 0) 
		{
			reset_affectation(0);
			if (( use_compare_operator(lptr,operation) )) 
				return( syntax_error( 9023 ) );
			else	continue;
		}
		else if ((operation = is_numeric())) 
		{
			if (( operation == '-' )
			&&  (!( lptr->arithmetic ))
			&&  ( lptr->last != (FACTORPTR) 0)) 
			{
				if ((operation = arithmetical_operator()) != '-') 
					return( syntax_error( 9024 ) );
				else if (( use_arithmetical_operator(lptr,operation) )) 
					return( syntax_error( 9025 ) );
				else	continue;
			}
			else if (!( get_token() )) 
			{
				if ( operation == '-' ) 
				{
					/* ------------------------- */
					/* unary constant operations */
					/* ------------------------- */
					if ((operation = arithmetical_operator()) != '-') 
						return( syntax_error( 9024 ) );
					else if (( use_arithmetical_operator(lptr,operation) )) 
						return( syntax_error( 9025 ) );
					else	continue;
				}
				else if ( operation != '/')
					return( syntax_error( 9026 ) );
			}
			else if (!( rptr = numeric_term() ))
				return( syntax_error( 9027 ) );
			else if (!( rptr = secondary_evaluation( rptr ) ))
				return( syntax_error( 9027 ) );
			else if (( use_primary_term(lptr, rptr ) ))
				return( syntax_error( 9028 ) );
			else	continue;
		}
		else if ( is_mnemonic("AND") ) 
		{
			complexe++;
			reset_affectation(0);
			if (( use_logical_operator(lptr, _LOGICAL_AND ) ))
				return( syntax_error( 9029 ) );
			else	continue;
		}
		else if ( is_mnemonic("OR") ) 
		{
			complexe++;
			reset_affectation(0);
			if (( use_logical_operator(lptr, _LOGICAL_OR ) ))
				return( syntax_error( 9030 ) );
			else	continue;
		}
		else if ( is_mnemonic("XOR") ) 
		{
			complexe++;
			reset_affectation(0);
			if (( use_logical_operator(lptr, _LOGICAL_OX  ) ))
				return( syntax_error( 9031 ) );
			else	continue;
		}

		if ((operation = arithmetical_operator()) != 0) 
		{
			if (( use_arithmetical_operator(lptr,operation) )) 
				return( syntax_error( 9024 ) );
			else	continue;
		}
		else if (!( get_token() ))
			break;
		else if (!( rptr = primary_evaluation() ))
			return( syntax_error( 9032 ) );
		else if (( use_primary_term(lptr, rptr ) ))
			return( syntax_error( 9032 ) );
		else	continue;
	}
	if ( bracing )
		status = syntax_error( 9033 );
	else if ( complexe )
		status = terminate_level(host,lptr,repeat_until);
	else if (!( host ))
		status = terminate_level(host,lptr,repeat_until);
	else if (!( lptr->head )) 
		status = terminate_level(host,lptr,repeat_until);
	else	
	{
		/* ---------------------------- */
		/* simplification required here */
		/* ---------------------------- */
#ifdef	DEBUG_CONDITIONS
		for (i=0; i < nesting; i++ )
			sysprintf("\t");	
		sysprintf("simplification performed\n"); 		
#endif
		status = terminate_level(host,lptr->head,repeat_until);
		drop_level( lptr );
	}

#ifdef	DEBUG_CONDITIONS
	for (i=0; i < nesting; i++ )
		sysprintf("\t");	
	sysprintf("leave parse_conditionals: %s status = %u \n",(host ? "host" : "nohost" ),status);
#endif
	return( status );
}

/*	----------------------	*/
/*	terminate_conditionals	*/
/*	----------------------	*/
WORD	terminate_conditionals()
{
	return(0);
}

/*	--------------------------	*/
/*	new_conditional_expression	*/
/*	--------------------------	*/
WORD	new_conditional_expression(WORD repeat_until)	/* 0 : IF/WHILE, 1:UNTIL, 2:WHEN */
{
	WORD	status;
#ifdef	DEBUG_CONDITIONS
	sysprintf("%s : \n",(repeat_until ? "repeat" : "while/if"));
#endif
	status = parse_conditionals((LEVELPTR) 0,repeat_until,0,0);
#ifdef	DEBUG_CONDITIONS
	sysprintf("%s(%u)\n",(repeat_until ? "until" : "wend/endif"),status);
#endif
	return( status );
}

#endif	/* _trcond_h */
	/* --------- */

