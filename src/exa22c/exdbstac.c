

EXAWORD	Nouvelle( lno )
EXAWORD	lno;
{
	if ( lno < (WindCord[1][0]+19)) {
		db_xpos(lno++,(WindCord[1][1]+1));
		return( lno );
		}

	switch ( ExitMethod(3) ) {
		case 0 : PopZone(); return(0);
		case 1 : LibZone(); return(0);
		}
		
	db_xpos((lno = (WindCord[1][0]+2)),(WindCord[1][1]+1));
	return( ++lno );

}


/*
 *	G O S U B I N G ( current , limit , line )
 *	------------------------------------------
 *	Display of current RETURN adresses
 *
 */

EXAWORD	Gosubing( current , limit , line )
EXAWORD	current;
EXAWORD	limit;
EXAWORD	line;
{
	EXAWORD	x;

	/* Check for something */
	/* ------------------- */
	while ( current > limit ) {
		current--;
		if ((line = Nouvelle( line )) == 0) {
			return( 0 );
			} 
		db_xputch('&');
		showword( ip_hold [ current ] , 4 );
		db_xputch(' ');
		}
	return ( line );

}

EXAWORD	SegmTrace( i , o , l )
EXAWORD	i;
EXAWORD	o;
EXAWORD	l;
{
	if ((l = Nouvelle( l )) == 0) {
		return( 0 );
		} 
	db_xcprintf((BPTR) "SEGM "); x_intvisi( i );
	db_xputch(':'); showword(o,4); db_xputch(' ');
	return( l );
}

EXAWORD	ProcTrace( i , o , l )
EXAWORD	i;
EXAWORD	o;
EXAWORD	l;
{
	if ((l = Nouvelle( l )) == 0) {
		return( 0 );
		} 
	db_xcprintf((BPTR) "PROC "); AffProcName(( i * 16 ));
	db_xputch(':'); showword(o,4); db_xputch(' ');
	return( l );
}

/*
 *	S T A K T R A C E ( )
 *	---------------------
 *	Display of current execution context
 *	GOSUBS , PROCEDURES , SEGMENTS
 *	
 */

VOID	stack_trace()
{
	EXAWORD	lno;
	EXAWORD	ContextFlag;
	EXAWORD	ContextWP;
	EXAWORD	ContextPP;
	EXAWORD	ContextType;
	EXAWORD	ContextOffs;
	EXAWORD	ContextHold;
	struct context SPTR sgcp;

	/* Reposition window and display */
	/* ----------------------------- */
	WdwLimit(1,20,24);

	if ( PushZone(WindCord[1][0],WindCord[1][1],20,24,0x0013,Couleurs[1][0],Couleurs[1][1]) != 0) {
		Debordement();
		return;
		}

	/* Display Window message */
	/* ---------------------- */
	db_xputch(' '); db_xcprintf((BPTR)TalkPtr[54]); db_xputch(' ');

	/* Display Current Code Unit */
	/* ------------------------- */
	if ( sicico & ONSEM_PRC ) {
		if ((lno = ProcTrace( procid , CurrentTcodeOffset(0) , (lno = (WindCord[1][0]+2)))) == 0) {
			return;
			}
		}
	else	{
		if ((lno = SegmTrace( cur_seg , CurrentTcodeOffset(0) , (lno = (WindCord[1][0]+2)))) == 0) {
			return;
			}
		}

	/* First display pending RETURN adresses */
	/* ------------------------------------- */
	if ((lno = Gosubing( ip_next , StackHold , lno )) == 0 ) {
		return;
		}


	/* Now analyse the current stack context */
	/* ------------------------------------- */
	ContextFlag = sicico; ContextWP = StackHold; ContextPP = mindex;

	/* Destack possible procedures */
	/* --------------------------- */
	while ( ContextFlag & ONSEM_PRC ) {
		ContextFlag = ip_hold [ (ContextWP -  4) ];	/* SICICO   */
		ContextOffs = ip_hold [ (ContextWP -  7) ];	/* FDEX-SB  */
		ContextHold = ip_hold [ (ContextWP -  1) ];	/* STACKHLD */

		if ( ContextFlag & ONSEM_PRC ) {
			ContextType = ip_hold [ (ContextWP - 12) ];	/* PROCID   */
			if ((lno = ProcTrace( ContextType , ContextOffs , lno )) == 0) {
				return;
				}
			}
		else	{
			if ((lno = SegmTrace( cur_seg , ContextOffs , lno )) == 0) {
				return;
				}
			}

		/* Adjust Context stacking pointers */
		/* -------------------------------- */
		ContextWP -= 12;
		if ( ContextFlag & ERROR_TEST ) {
			ContextPP -= 4;
			}
		else	{
			ContextPP -= 3;
			}

		/* Display possible stacked Gosubs */
		/* ------------------------------- */
		if ((lno = Gosubing(ContextWP,ContextHold,lno)) == 0) {
			return;
			}

		/* Remove possible Gosubs */
		/* ---------------------- */
		ContextWP = ContextHold;

		}

	/* Destack Possible Segments */
	/* ------------------------- */
	while ( ContextPP > 0 ) {
		ContextPP--;
		sgcp = (struct context SPTR) minder [ ContextPP ];
		if ((lno = SegmTrace( sgcp->seg_ID , sgcp->seg_IP , lno )) == 0) {
			return;
			}
		/* Display possible stacked Gosubs */
		/* ------------------------------- */
		if ((lno = Gosubing(sgcp->seg_SP,sgcp->seg_SH,lno)) == 0) {
			return;
			}
		
		}

	/* Perform Exit method check */
	/* ------------------------- */
	switch ( ExitMethod(1) ) {
		case 0 : PopZone(); break;
		case 1 : LibZone(); break;
		}
	return;
}

