/*
 *	General functions which take integer arguaments and return Nothing
 *	------------------------------------------------------------------
 *
 *	0) -	WAIT 	( n )		Attente de N seconds
 *	1) -	MASK 	( n )		Etablir mask du saisie d'ASK
 *	2) -	RESTORE	( n )		Positioner le pointeur de DATA
 *	3) -	DATE	( n , s )	Etablir element de DATE
 *	4) -	KBF	( n , s )	Etablir une touche de fonction
 *	5) -	COLOUR	( f , b )	Set Standard Ask Colours
 *	6) -	ATRIBUT	( a )		Set Standard Ask Attributs
 *	7) -    HOTKEY  ( a )		Set Current HotKey
 *	8) -	LANGUAGE( a )		Set Current National Language
 *	9) -	INITDATA( 0 | 1 )	Initialise Global or Local Data
 *	A) -	END.USER( library )	Library liberation
 *	B) -	END.PROC( procid  )	Procedure liberation
 *	C) -	END.SEGM( segment )	Segment liberation
 *      D) -    EVENT   ( n , v )       Set Event parameter
 *     	E) -    SEND    ( tid, msg )	Send IPC Message
 *     	F) -    DLLNAME ( number, string ) Set name of BDA/DLL
 */

EXAWORD	f_clf7(x)
EXAWORD x;			/* Code of Sub-function of group	*/
{	
EXAWORD	desc;

/* Analyse and evaluate 1st Arguament : WORKSET 1 */
/* ---------------------------------------------- */

ExFlgSgn = 1;		/* UnSigned Characters Please */

if (argset((((desc = ((EXAWORD) *(fdex++))) & 0x0060) >> 5),0,1) == SOFTERROR) { 

	ExFlgSgn = 0;

	/* Return Error due to Arg Analysis */
	/* -------------------------------- */
	return(SOFTERROR); 
	}

ExFlgSgn = 0;

/* Select Group 7 Sub function */
/* --------------------------- */
switch ( x ) {
	case 0 : /* FUNCTION 0 : WAIT */
		 /* -----------------*/
		 (VOID) raz_timer(); 		/* Switch OFF the Timer */
		 ll_wait(workval1,10);		/* Perform SLEEP/WAIT   */
		 return(1);			/* No Error Return      */

	case 1 : /* FUNCTION 1 : MASK */
		 /* ----------------- */
		 askmask = ((EXAWORD) workval1); /* Establish MASK value */
		 return(1);			 /* No Errors possible	 */

	case 2 : /* FUNCTION 2 : RESTORE */
		 /* -------------------- */
		 if ( workval1 > datamax ) { 	/* If New value too big	*/
			err_val = ABAL_FINDATA; /* Error End Of Data	*/
			return(SOFTERROR); 	/* Indicate an Error	*/
			}
		 datadex = workval1; 		/* Indicate Value	*/
		 return(setdata(datadex));	/* Return Result 	*/

	case 3 : /* FUNCTION 3 : DATE */
		 /* ----------------- */
	case 4 : /* FUNCTION 4 : KBF  */
		 /* ----------------- */
		 if (( worktyp1 & VARB_ISOL ) == 0 ) {
			workval1 = (workval1 & 0x00FF);
			}
		 /* Analyse and evaluate 2nd Arguament : WORKSET 2 */
		 /* ---------------------------------------------- */
		 if (argset( ((desc & 0x0006) >> 1),0,2) == SOFTERROR)

		 	/* Error due to Arg evaluation */
			/* --------------------------- */
			return(SOFTERROR);
		
		 /* Test for correct Arguament Type : Should be $ */
		 /* --------------------------------------------- */
		 if ( worktyp2 != VARB_STR ) { 
			err_val = EXER_PARAM; 	/* Parameter incorrect	*/
			return(SOFTERROR); 	/* Indicate Error 	*/
			}

		 /* Separate DATE from KBF */
		 /* ---------------------- */
		 if ( x == 3 ) { 
			/* Alors Ecrire DATE */
			/* ----------------- */
			return( exdatw() ); 	
			}
		 else 	{
			/* KBF( touche_id ) = $  */
			/* --------------------- */
			/* Ensure Unsigned Value */
			/* --------------------- */
			worklen3 = (EXAWORD) workval1;
#ifdef	ABAL21
			if ( worklen3 >= 1000 ) 
				return( IpcSend( (worklen3-1000), workptr2, worklen2 ) );

			else	{
#endif
				/* Test for Exceeding KBF count */
				/* ---------------------------- */
				if (worklen3 > (conf(9) + 0x007F)) {

					/* Function Key unknown Return ERROR 111 */
					/* ------------------------------------- */
					err_val = 111; return(SOFTERROR);
					}
				/* Perform Low Level Function */
				/* -------------------------- */
				return( exkbfw() );	
#ifdef	ABAL21
				}
#endif
			}			
#ifdef	ABAL14
	case	5	:	/* ASKCOLOR */
		 /* Analyse and evaluate 2nd Arguament : WORKSET 2 */
		 /* ---------------------------------------------- */
		 if (argset( ((desc & 0x0006) >> 1),0,2) == SOFTERROR)
			return(SOFTERROR);
		 /* Establish default colour */
		 /* ------------------------ */
		 /* HIGHBYTE = FORGROUND, LOWBYTE = BACKGROUND */
		 /* ------------------------------------------ */
		 askcolour = ( ((EXAWORD) (workval1 & 0x000F) << 8) 
			     | ((EXAWORD) (workval2 & 0x000F)     ));

		 return(1);			 /* No Errors possible	 */

	case	6	:	/* ASKATB   */
		 askatrib = ((EXAWORD) workval1); /* Establish default colour */
		 return(1);			 /* No Errors possible	 */
#endif

#ifdef	ABAL21

	case	7	:	/* HOTKEY	*/
		LastJumpKey = (EXAWORD) (workval1 & 0x00FF);
		return( GOODRESULT );
		
	case	8	:	/* LANGUAGE	*/
		set_national_characteristics(( NationalLanguage = (EXAWORD) workval1));
		return( GOODRESULT );

	case	9	:	/* INITDATA */
				/* -------- */

		switch ( workval1 ) {
			case 0 : if (( GlobalDataTable != (BPTR) 0 )
				 &&  ( GlobalDataSegment != (BPTR) 0 ))
					(VOID) initialise_data_image((BPTR) (GlobalDataTable+(3*WORDSIZE)),(BPTR) GlobalDataSegment, (Tcodeword((GlobalDataTable))) );
				 break;

			case 1 : if (( LocalDataTable != (BPTR) 0 )
				 &&  ( LocalDataSegment != (BPTR) 0 ))
					(VOID) initialise_data_image((BPTR) (LocalDataTable+(3*WORDSIZE)),(BPTR) LocalDataSegment, (Tcodeword((LocalDataTable))) );
				 break;
			}

		return( GOODRESULT );

	case	10	:	/* END.USER library_number */

		release_dynamic_library( workval1 );
		return( GOODRESULT );

	case	11	:	/* END.PROC procedure_number */

		clf_procedure_release( workval1, 1 );
		return( GOODRESULT );

	case	12	:	/* END.SEGM segment_number   */

		release_segment( workval1 );
		return( GOODRESULT );

	case 	13	:	/* EVENT(n) = v	*/
				/* ------------ */

		 /* Analyse and evaluate 2nd Arguament : WORKSET 2 */
		 /* ---------------------------------------------- */
		 if (argset( ((desc & 0x0006) >> 1),0,2) == SOFTERROR)
			return(SOFTERROR);
		 else   return( set_event_parameter( workval1, workval2 ) ); 
	
	case 14 	:	/* SEND(IPCID,MESSAGE) */
				/* ------------------- */
		 if (argset( ((desc & 0x0006) >> 1),0,2) == SOFTERROR)
			return(SOFTERROR);
		 else	return( IpcSend( workval1, workptr2, worklen2 ) );

#endif

#ifndef	_EXCLF7F_C
#define _EXCLF7F_C


/*
 *	-------------------------------------------------------------
 *	F) -    DLLNAME ( lid, name)    	Set DLL Filename
 *	-------------------------------------------------------------
 *
 *	This file is included by the CLF function group file EXCLF7.C
 *	which is itself included by the CLF subsection  file EXCLF.C
 *
 */


	case 15 : /* FUNCTION 15 : DLLNAME */
		  /* --------------------- */
		 if (( worktyp1 & VARB_ISOL ) == 0 ) {
			workval1 = (workval1 & 0x00FF);
			}

		 /* Analyse and evaluate 2nd Arguament : WORKSET 2 */
		 /* ---------------------------------------------- */
		 if (argset( ((desc & 0x0006) >> 1),0,2) == SOFTERROR)

		 	/* Error due to Arg evaluation */
			/* --------------------------- */
			return(SOFTERROR);
		
		 /* Test for correct Arguament Type : Should be $ */
		 /* --------------------------------------------- */
		 if ( worktyp2 != VARB_STR ) { 
			err_val = EXER_PARAM; 	/* Parameter incorrect	*/
			return(SOFTERROR); 	/* Indicate Error 	*/
			}

		/* Set dynamic library name */
		/* ------------------------ */
		return( set_dll_filename( workval1, workptr2, worklen2 ) );
		


#endif	/* _EXCLF7F_C */
	/* ---------- */





	default	:
			/* All other Function codes ( > 4 ) */
			/* -------------------------------- */
			err_val = 56;		/* Function unknown */
			return(SOFTERROR);	/* indicate Error   */
	}
}

