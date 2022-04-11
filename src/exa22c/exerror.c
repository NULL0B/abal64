/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXERROR - C				*/
/*		Version :	1.4c /2.1a				*/
/*		Date 	:	02/06/1993				*/
/*									*/
/*----------------------------------------------------------------------*/

/*======================================================================*/
/*	Remarque :	Fichier d'include pour EXCALC-C			*/
/*======================================================================*/

#ifdef	ABAL21

#ifndef	BEFORE_100395
ERRORPTR ErrorTrapHeap=(ERRORPTR) 0;
#endif

EXAWORD	error_trap_count=0;

EXAWORD	allocated_error_traps()
{
	return( error_trap_count );
}

EXAWORD	push_error_context()
{
	if ( mindex >= diezstk ) { 
		err_val = ABAL_GSB2MANY; 
		return(SOFTERROR); 
		}
	else	{
		minder [mindex++] = (BPTR) GlobalErrorTrap;
		return( GOODRESULT );
		}
}

#ifndef	BEFORE_100395
VOID	drop_error_trap( lwerr )
ERRORPTR	lwerr;
{
	lwerr->previous = ErrorTrapHeap;
	ErrorTrapHeap   = lwerr;
	return;

}

ERRORPTR	allocate_for_on_error()
{
	ERRORPTR	lwerr;
	if ((lwerr = ErrorTrapHeap) != (ERRORPTR) 0) {
		if ( lwerr->previous != (ERRORPTR) 0)
			ErrorTrapHeap = lwerr->previous;
		else	ErrorTrapHeap = (ERRORPTR) 0;
		}
	else 	lwerr = (ERRORPTR) allocate(sizeof( struct errform));
	return( lwerr );
}

VOID	liberate_for_on_error()
{
	ERRORPTR	lwerr;
	while ((lwerr = ErrorTrapHeap) != (ERRORPTR) 0) {
		if ( lwerr->previous != (ERRORPTR) 0)
			ErrorTrapHeap = lwerr->previous;
		else	ErrorTrapHeap = (ERRORPTR) 0;
		liberate( lwerr );
		}
	return;
}

#endif

EXAWORD	pop_error_context()
{
	ERRORPTR lwerr;
	
	if ((lwerr = GlobalErrorTrap) != (ERRORPTR) 0) {
		if (lwerr->previous != (ERRORPTR) 0) 
			GlobalErrorTrap = lwerr->previous;
		else	{
			GlobalErrorTrap = (ERRORPTR) 0;
			sicico &= OFSEM_ERTR;
			}
		error_trap_count--;
#ifndef	BEFORE_100395
		drop_error_trap( lwerr );
#else
		liberate( lwerr );
#endif
		}
	return( GOODRESULT );
}
#endif

VOID	release_error_traps()
{
	ERRORPTR	lwerr;

	while ((lwerr = GlobalErrorTrap) != (ERRORPTR) 0) {
		if (lwerr->previous != (ERRORPTR) 0) 
			GlobalErrorTrap = lwerr->previous;
		else	{
			GlobalErrorTrap = (ERRORPTR) 0;
			sicico &= OFSEM_ERTR;
			}
		error_trap_count--;
#ifndef	BEFORE_100395
		drop_error_trap( lwerr );
#else
		liberate( lwerr );
#endif
		}
	return;
} 

#ifdef	ABAL21

EXAWORD	check_for_error_pop()
{
	if (( GlobalErrorTrap != (ERRORPTR) 0 )
	&&  (( GlobalErrorTrap->err_flg & 1))) {
		pop_error_context();
		if ( GlobalErrorTrap == (ERRORPTR) 0 )
			sicico &= OFSEM_ERTR;
		}
	return(GOODRESULT);
}

#endif

/*
 *	This is called to satisfy the CONF(23) function call in 
 *	EXCLF15.C
 */

EXAWORD	error_trapping_status()
{
	if ( GlobalErrorTrap == (ERRORPTR) 0 )
		return( 0 );	/* Indicate No Error Trapping */
	else if (GlobalErrorTrap->err_flg & 0x0003) 
		return( 2 );	/* Indicate Local  Error Trap */
	else	return( 1 );	/* Indicate Global Error Trap */
} 

/*
 *	E R R E U R S ( )
 *	-----------------
 *	Gestion des erreurs d'execution du T-Code
 *
 */

EXAWORD erreurs()
{

			/* ------------------------------------- */
prndest = 1;		/* Ensure Screen Device Selected now !!! */
			/* ------------------------------------- */

if ( err_val == 0 ) {

	/* ----------- */
	/* Normal STOP */
	/* ----------- */
	chain = 0;
	return(HARDERROR); 

	}

/* Test for Error trap declared */
/* ---------------------------- */
if (sicico & ERROR_TEST) {	/* Was ONSEM_TRP        */
				/* -------------        */ 
				/* sicico &= OFSEM_TRP; */
				/* -------------------- */

	/* Test for ERROR variable declared */
	/* -------------------------------- */
	if ( GlobalErrorTrap->err_var != 0 ) {
		ireg [ERROREG] = GlobalErrorTrap->err_ind; 
		areg [ERROREG] = GlobalErrorTrap->err_and;
		freg [ERROREG] = err_val; 
		xreg [ERROREG] = IMMEDIAT; err_val = 0;
		vputs((ERROREG),GlobalErrorTrap->err_var);
		}
	else	{ 
		/* Save value to Error Register */
		/* ---------------------------- */
		if (GlobalErrorTrap->err_reg != 0 ) {
			freg [ GlobalErrorTrap->err_reg ] = err_val;
			xreg [ GlobalErrorTrap->err_reg ] = IMMEDIAT;
			err_val = 0;
			}
		}
	/* Establish SEGMENT OFFSET of instruction creating Error */
	/* ------------------------------------------------------ */
	GlobalErrorTrap->err_adr = (EXAWORD) (lineptr - TcodeSegment) -1;

	/* Indicate error trapping underway and perform Trap Code */
	/* ------------------------------------------------------ */
	sicico |= ONSEM_ERR;	
	fdex = (BPTR) (TcodeSegment + GlobalErrorTrap->err_trp);

	/* Continue T-Code Execution */
	/* ------------------------- */
	return(1);
	}
				/* ---------------------------- */
chain = 0;			/* Disactivate any active chain	*/
eder(err_val);	 		/* Display the Error	   	*/
return(HARDERROR);		/* Indicate Abort	   	*/
				/* ---------------------------- */
}


/*
 *	T R A P G E S T ( varerr , adrtrp )
 *	-----------------------------------
 *
 *	Error trap management , Install and liberation.
 *	ON ERROR GOTO &Etiq , Variable
 *	ON ERROR ABORT
 *
 */

EXAWORD	trapgest( varerr , adrtrp , regtrp, trapmode )
EXAWORD	varerr,adrtrp,regtrp,trapmode;
{
	ERRORPTR	lwerr;

/*	ERROR VARIABLE == 0 and ERROR ADRESSE = 0 : ON ERROR ABORT 	*/
/*	----------------------------------------------------------	*/
	if (( varerr == 0 ) && (adrtrp == 0)) {	

		/* ON ERROR ABORT */
		/* -------------- */
		if ( sicico & ERROR_TEST ) {
#ifdef	ABAL21
			/* Remove if ONE SHOT error trap */
			/* ----------------------------- */
			check_for_error_pop();
#endif
			if ((lwerr = GlobalErrorTrap) != (ERRORPTR) 0 ) {
				if (lwerr->previous != (ERRORPTR) 0)
					GlobalErrorTrap = lwerr->previous;
				else	{
					GlobalErrorTrap = (ERRORPTR) 0;
					sicico &= OFSEM_ERTR;
					}
				error_trap_count--;
#ifndef	BEFORE_100395
				drop_error_trap( lwerr );
#else
				liberate( lwerr );
#endif
				}
			}
		if ( GlobalErrorTrap == (ERRORPTR) 0 )
			sicico &= OFSEM_ERTR;
		}
	else	{

		/* ON ERROR GOTO */
		/* ------------- */
#ifndef	BEFORE_100395
		if  ((lwerr = (ERRORPTR) allocate_for_on_error()) == (ERRORPTR) 0) {
#else
		if  ((lwerr = (ERRORPTR) allocate(sizeof( struct errform))) == (ERRORPTR) 0 ) {
#endif
			err_val = 27;
			return(SOFTERROR);
			}
		error_trap_count++;

		if ( varerr >= 6 ) {
			lwerr->err_reg = 0;
			lwerr->err_var = varerr;
			lwerr->err_trp = adrtrp;
			lwerr->err_ind = ireg [0];
			lwerr->err_and = areg [0];
#ifdef	ABAL21
			lwerr->err_flg = trapmode;
#endif
			}
		else	{
			lwerr->err_reg = 0;
			lwerr->err_var = freg [regtrp];
			lwerr->err_trp = adrtrp;
			lwerr->err_ind = ireg [regtrp];
			lwerr->err_and = areg [regtrp];
#ifdef	ABAL21
			lwerr->err_flg = trapmode;
#endif
			}

		if ((sicico & ONSEM_ERR) == 0 )
			lwerr->err_adr = MOINS_UN;

		if ( trapmode ) {
			lwerr->previous = GlobalErrorTrap;
			GlobalErrorTrap = lwerr;
			}
		else	{

			if ((GlobalErrorTrap != (ERRORPTR) 0)
			&&  ((GlobalErrorTrap->err_flg & 0x0003) == 0)) {
				if ( GlobalErrorTrap->previous != (ERRORPTR) 0)
					lwerr->previous = GlobalErrorTrap->previous;
				else	lwerr->previous = (ERRORPTR) 0;
				GlobalErrorTrap->previous = (ERRORPTR) 0;
				release_error_traps();
				}
			else	lwerr->previous = GlobalErrorTrap;
			GlobalErrorTrap = lwerr;
			}

		sicico &= OFSEM_ERTR;
		sicico |= ONSEM_TRP;
		}
/*
	x_cprintf((BPTR) "GestErrorType ("); intvisi( trapmode );
	x_cprintf((BPTR) ") ErrorTrapCount("); intvisi( error_trap_count );
	x_cprintf((BPTR) ")\r"); x_getch();
 */
	return(GOODRESULT);
}



/*
 *	T R A P W O R K ( etiq )
 *	------------------------
 *	Resumer l'execution apres une piege erreur
 *	RESUME &Etiq ou RESUME
 */

EXAWORD	trapwork( etiq )
EXAWORD	etiq;
{

	err_val = ABAL_RESNOTRAP;		

	if (( sicico & ONSEM_TRP ) == 0 ) {
		sicico &= OFSEM_ERTR;	/* Whoops No ON ERROR GOTO	*/
		return(SOFTERROR);	/* SoftError No Trap		*/
		}	

	if ( sicico & ONSEM_ERR ) {		

		/* RESUME &ETIQUETTE */
		/* ----------------- */
		if ( etiq != MOINS_UN )
			fdex = (TcodeSegment + etiq);

		/* RESUME ERRADR */
		/* ------------- */
		else 	fdex = (TcodeSegment + GlobalErrorTrap->err_adr);

#ifdef	ABAL21
		/* Remove if ONE SHOT error trap */
		/* ----------------------------- */
		if (( GlobalErrorTrap != (ERRORPTR) 0 )
		&&  ( GlobalErrorTrap->err_flg & 1 )) {
			pop_error_context();
			if ( GlobalErrorTrap == (ERRORPTR) 0 ) {
				err_val = 0;
				sicico &= OFSEM_ERTR;
				return( GOODRESULT );
				}
			}
#endif
		}
	else 	{ 
		err_val = ABAL_RESNONEED; /* No Error for Resume	  */
		sicico &= OFSEM_ERTR;	/* Whoops Kill Error Handling	  */
		return(SOFTERROR); 	/* Erreur , pas d'erreur en cours */
		}

	err_val = 0;			/* Clear errors			  */
	sicico &= OFSEM_ERR; 		/* Clear ERROR en cours		  */
	sicico |= ONSEM_TRP;		/* Reactivate error traping	  */
	return(GOODRESULT);		/* Resume motor execution	  */

}

