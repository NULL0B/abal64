#ifndef	TRVALUE_C
#define TRVALUE_C

static	WORD	AllocatedSwapValues=0;
static	WORD	LiberatedSwapValues=0;

VALUEPTR	allocate_for_value()
{
	VALUEPTR	lptr;

#ifdef	SWAP_CTRL
	VALUEBUF	vptr;

	trace("allocate_for_swapvalue()\n");

	if (( lptr = allocate_buffer()) == (VALUEPTR) 0)
		return( lptr );

	if (( vptr = validate_buffer( lptr )) != (VALUEBUF) 0) {
		vptr->irite = 0;
		vptr->iread = 0;
		vptr->next  = (VALUEPTR) 0;
		AllocatedSwapValues++;
		return( lptr );
		}
	else	{
		release_buffer( lptr );
		return((VALUEPTR) 0);
		}
#else

	trace("allocate_for_value()\n");

	if (( lptr = (VALUEPTR) allocate( sizeof(struct tcode_value))) != (VALUEPTR) 0) {

		lptr->irite = 0;
		lptr->iread = 0;
		lptr->next  = (VALUEPTR) 0;

		}
	else	{
		allocation_failure();
		}
	return( lptr );

#endif
}

VALUEPTR	liberate_value( valueptr )
VALUEPTR	valueptr;
{
	VALUEPTR	xvalue;

#ifdef	SWAP_CTRL
	VALUEBUF	xbuffer;
	trace("liberate_swapvalue()\n");
#else
	trace("liberate_value()\n");
#endif
	while ((xvalue = valueptr) != (VALUEPTR) 0 ) {

#ifdef	SWAP_CTRL
		if ((xbuffer = (VALUEBUF) validate_buffer( xvalue )) == (VALUEBUF) 0) {
			return((VALUEPTR) 0);
			}
		valueptr = xbuffer->next;
		release_buffer( xvalue );		
		LiberatedSwapValues++;
#else
		valueptr = valueptr->next;
		liberate( xvalue );
#endif
		}

	return((VALUEPTR) 0);
}

VALUEPTR	memory_target( MemoryTarget , c )
VALUEPTR	MemoryTarget;
WORD		c;
{

#ifdef	SWAP_CTRL
	VALUEBUF	vbuffer;

	if ((MemoryTarget == (VALUEPTR) 0)
	||  ((vbuffer = validate_buffer( MemoryTarget )) == (VALUEBUF) 0))
		return( (VALUEPTR) 0 );
	
	vbuffer->text[vbuffer->irite++] = (BYTE) c;

	if ( vbuffer->irite >= TEXT_MAX ) {

		if (( vbuffer->next = allocate_for_value()) != (VALUEPTR) 0) {
			MemoryTarget = vbuffer->next;
			}
		else	{
			(void) allocation_failure();
			return((VALUEPTR) 0);
			}
		}

	return( MemoryTarget );

#else
	/* Store the byte to the Macro value Storage buffer */
	/* ------------------------------------------------ */
	MemoryTarget->text[MemoryTarget->irite++] = (BYTE) c;

	/* Test for End of Macro Storage zone */
	/* ---------------------------------- */
	if ( MemoryTarget->irite >= TEXT_MAX ) {

		/* Allocate a new Storage zone */
		/* --------------------------- */
		if (( MemoryTarget->next = allocate_for_value()) != (VALUEPTR) 0) {

			/* Initialise value structure */
			/* -------------------------- */
			MemoryTarget = MemoryTarget->next;
			}
		else	{
			(void) allocation_failure();
			return((VALUEPTR) 0);
			}
		}

	/* Return current Storage pointer */
	/* ------------------------------ */
	return( MemoryTarget );
#endif

}

VOID	value_statistics()
{
	if (( AllocatedSwapValues != LiberatedSwapValues )
	||  ( OtrOption.Verbose & 2 ))
		sysprintf("Value buffer : Allocated : %u , Liberated : %u \n",AllocatedSwapValues,LiberatedSwapValues);
	return;
}

#endif	/* TRVALUE_C */
	/* -------- */

