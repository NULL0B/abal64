#define	TracePrint(a,b,c,d,dl,e,el) TraTrace( b,c,d,dl,e,el )
#define	TraceDump(a,b,c,d,dl,e,el,f,fl) TraDump(b,c,d,dl,e,el,f,fl)

/*
 *	Trace Management Function :  integer arg, then string args  no result 
 *	---------------------------------------------------------------------
 *
 *	0) -	TRACE ON	( NAME$, LABEL$, MASK1%, MASK2% )
 *	1) -	TRACE OFF	( RESET% )
 *	2) -	TRACE PRINT	( MASK%, LEVEL%, LABEL$, MSG$ ) 
 *	3) -	TRACE HEX	( MASK%, LEVEL%, LABEL$, MSG$, ZONE$ )
 */

static EXAWORD	TraceIsActive[17] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

VOID	trace_print(int a, int b, char * c, int cl, char * d, int dl )
{
	if ( TraceIsActive[0] ) { 	
		TracePrint(0,a,b,c,cl,d,dl);
		}
	return;
}

VOID	trace_dump(int a, int b, char * c, int cl, char * d, int dl, char * e, int el )
{
	if ( TraceIsActive[0] ) { 	
		TraceDump(0,a,b,c,cl,d,dl,e,el);
		}
	return;
}

VOID	activate_trace( int channel )
{
	if ( channel <= 16 )
		TraceIsActive[channel] = 1;
	return;
}

VOID	disactivate_trace( int channel )
{
	if ( channel <= 16 )
		TraceIsActive[channel] = 0;
	return;
}

/*	Called from main() of EXA to ensure trace is off	*/
/*	------------------------------------------------	*/
VOID	reset_trace_control()	
{	
	int	i;
	for (i=0; i < 16; i++ ) TraceIsActive[i]=0;
}

/*
 *	Function group	CLF1 providing the new trace function stubs	
 *
 */

EXAWORD	f_clf1(x)
EXAWORD x;			/* Code of Sub-function of group	*/
{	
	EXAWORD	desc;
	EXAWORD	a=0;
	EXAWORD	b=0;
	EXAWORD	mask=0;
	BPTR	aptr=fdex;
	EXAWORD	channel=0;
	
	/* Trace Accelerator */
	/* ----------------- */
	if (( x == 2 ) || ( x == 3 )) {
		if ((channel = Tcodeword(fdex)) > 16) {
			err_val = 103;
			return( SOFTERROR );
			}
		else if ( channel <= 0 ) {
			err_val = 102;
			return( SOFTERROR );
			}
		else if (!( TraceIsActive[channel] )) {
			a = Tcodeword((fdex+WORDSIZE));
			fdex += ( a + (WORDSIZE*2) );
			return( GOODRESULT );
			}
		else	fdex += (WORDSIZE*2);
		}

	aptr = fdex;

	/* Step over descriptors */
	/* --------------------- */
	while ( *(fdex++) & 1 );
 
	switch ( x ) {

		case	0	: /* ON  */
			if ( argset(((*(aptr++) &0x0060) >> 5),0,1) == SOFTERROR) 
				return(SOFTERROR);
			else if ( workval1 > 16 ) {
				err_val = 103;
				return( SOFTERROR );
				}
			else if ( workval1 <= 0 ) {
				err_val = 102;
				return( SOFTERROR );
				}
			activate_trace(workval1);
			return( GOODRESULT );

		case	1	: /* OFF */
			if ( argset(((*(aptr++) &0x0060) >> 5),0,1) == SOFTERROR) 
				return(SOFTERROR);
			else if ( workval1 > 16 ) {
				err_val = 103;
				return( SOFTERROR );
				}
			else if ( workval1 <= 0  ) {
				err_val = 102;
				return( SOFTERROR );
				}
			disactivate_trace(workval1);
			return( GOODRESULT );

		case	2	:	/* TRACE PRINT	*/

			if ( argset(((desc &0x0006) >> 1),0,1) == SOFTERROR) 
				return(SOFTERROR);
			else	a = workval1;

			if ( argset((((desc = *(aptr++)) &0x0060) >> 5),0,1) == SOFTERROR) 
				return(SOFTERROR);
			else	b = workval1;

			if ( argset(((desc &0x0006) >> 1),0,1) == SOFTERROR) 
				return(SOFTERROR);

			if ( argset((((desc = *(aptr++)) &0x0060) >> 5),0,2) == SOFTERROR) 
				return(SOFTERROR);

			TracePrint( 	channel, a,b,
					workptr1,worklen1, 
					workptr2, worklen2 );

			return( GOODRESULT );
			
		case	3	:	/* TRACE HEX	*/

			if ( argset(((desc &0x0006) >> 1),0,1) == SOFTERROR) 
				return(SOFTERROR);
			else	a = workval1;

			if ( argset((((desc = *(aptr++)) &0x0060) >> 5),0,1) == SOFTERROR) 
				return(SOFTERROR);
			else	b = workval1;

			if ( argset(((desc &0x0006) >> 1),0,1) == SOFTERROR) 
				return(SOFTERROR);

			if ( argset((((desc = *(aptr++)) &0x0060) >> 5),0,2) == SOFTERROR) 
				return(SOFTERROR);

			if ( argset(((desc &0x0006) >> 1),0,3) == SOFTERROR) 
				return(SOFTERROR);

			TraceDump(	channel,
					a,			/* trace level	*/
					b,			/* filter 	*/
					workptr1,worklen1, 	/* title 	*/
					workptr2,worklen2, 	/* message 	*/
					workptr3,worklen3 );	/* zone    	*/

			return( GOODRESULT );

		default		:
			err_val = 56;
			return( SOFTERROR );
		}

}

