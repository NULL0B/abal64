#ifndef	_TRARG_C
#define	_TRARG_C

VOID	initialise_operands()
{
	ArgHeap = (ARGPTR) 0;
	return;
}

VOID	liberate_operands()
{
	ARGPTR	aptr;
	while ((aptr = ArgHeap) != (ARGPTR) 0) {
		ArgHeap = ArgHeap->next;
		liberate( aptr );
		}
	return;
}

VOID	release_operands( xptr )
ARGPTR	xptr;
{
	ARGPTR	aptr;
	while ((aptr = xptr) != (ARGPTR) 0) {
		xptr = xptr->next;
		aptr->next = ArgHeap;
		ArgHeap = aptr;
		}
	return;
}

ARGPTR	allocate_for_operand()
{
	ARGPTR	cptr;
	if ((cptr = ArgHeap) != (ARGPTR) 0)
		ArgHeap = ArgHeap->next;
	else if ((cptr = (ARGPTR) allocate( sizeof ( struct clf_operand ))) == (ARGPTR) 0 )
		return( cptr );

	cptr->operand = (RESULTPTR) 0;
	cptr->nature  = 0;
	cptr->format  = (BPTR)   0;
	cptr->next    = (ARGPTR) 0;
	cptr->prev    = (ARGPTR) 0;
	return( cptr );
}


#endif	/* _TRARG_C */
	/* -------- */


