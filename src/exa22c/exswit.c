/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R   A B A L				*/
/*		----------------------------				*/
/*									*/
/*		Copyright (c) 1987,1996 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXSWIT - C				*/
/*		Version :	2.1d					*/
/*		Date 	:	07/01/1998				*/
/*									*/
/*----------------------------------------------------------------------*/
/* NB This is an include file for both EXMOTOR-C and EXDBMOTO-C		*/
/*----------------------------------------------------------------------*/
/* NB The exit from the various functions may be performed by a BREAK	*/
/*    or a CONTINUE statement. The BREAK statement exit indicates that  */
/*    the external variable rewrite test must be performed before the   */
/*     next T-Code operation may be executed !!!! (04.01.1988)		*/
/*----------------------------------------------------------------------*/
/* 17/08/1990 : IJM : The TCODE tcNOP is now used to indicate arrival   */
/*            : at a trap location. The tcNOP code is returned to the   */
/*	      : calling function which will locate the tcode which had  */
/*            : previously occupied the current ADRESSE.		*/
/*----------------------------------------------------------------------*/
/* 18/07/1991 : Implimentation of Variable reference creation tcode for	*/
/*		the manipulation of structures in OBJECT ORIENTED ABAL	*/
/*----------------------------------------------------------------------*/
/* 27/02/1996 : Rappel de la boucle de messages sous NT/95		*/
/* 06/05/1996 : Support du ON EXTERN EVENT				*/
/* 15/05/1996 : MOD sur % -> division non signee			*/
/* 31/12/1997 : valeur de fdex avant appel message Windows		*/
/* 07/01/1998 : correction _ec_POP sur On extern event			*/
/* 02/09/1998 : changement logique passage des messages Windows		*/
/*----------------------------------------------------------------------*/
 
			/* Test for NEW LINE FLAG BIT indicates newline */
			/* -------------------------------------------- */
			if ( (tcode = (EXAWORD) *(fdex++)) & 0x0080) {

				/* Test for EVENT or TIMER active */
				/* ------------------------------ */
				if ((timersem & (TIME_ACTIF|EVENT_SWAP|0x1000)) != 0) {

				   /* Test for Timer ACTIF */
				   /* -------------------- */
				   if (( timersem & TIME_ACTIF) != 0) {
#ifdef DOS
					/* Update ARTO infos for DOS model */
					/* ------------------------------- */
					(VOID) dos_arto();
#endif	
					/* Test for TIMER EXPIRED condition */
					/* -------------------------------- */
					if (((EXAWORD) descarto[0] & TIME_ALARM ) == 0) {

						/* Repoint to Current TCODE */
						/* ------------------------ */
						fdex--; 

						/* Test for ON TIMER GOSUB */
						/* ----------------------- */
						if (( timersem & TIME_GOSUB ) != 0) {
							/* ------------------ */
							/* ON TIMER GOSUB     */
							/* ------------------ */
							/* Stores the current */
							/* Tcode offset in    */
							/* the Gosub Word stk */
							/* Then Re-activates  */
							/* the timer event    */
							/* (MULTIPLE SHOT)    */
							/* ------------------ */
							ip_hold [ (ip_next++) ] = (EXAWORD) (fdex - TcodeSegment); 
							(VOID) init_timer();
							}
						else 	{
							/* ------------------ */
							/* ON TIMER GOTO      */
							/* ------------------ */
							/* always cancels the */
							/* timer activity     */
							/* (ONE SHOT TIMER)   */
							/* ------------------ */
							timersem = 0;
							}

						/* ----------------------- */
						/* Establish Tcode Adresse */
						/* provided by timer event */
						/* ----------------------- */
						fdex = TcodeSegment + timeradr;

						/* --------------------- */
						/* Continue execution at */
						/* the new adresse.      */
						/* --------------------- */
						continue;

						}
					}

				   /* ------------------------------- */
				   /* HARDWARE EVENT MANAGEMENT CHECK */
				   /* ------------------------------- */
#ifdef WIN32
				   if ((timersem & 0x1000) != 0) {
					/* Let events happen ! */
					let_windows_work

					/* If an external event is available */
					if (mouse_arto != 0) {
						fdex--;
						if (handle_external_event() == SOFTERROR)
							tcode = SOFTERROR;
						continue;
					}
			   }
#endif

				   /* ------------------------------- */
				   /* SOFTWARE EVENT MANAGEMENT CHECK */
				   /* ------------------------------- */
				   /* Test for LATENT or ACTIVE event */
				   /* ------------------------------- */
				   if (( timersem & EVENT_SWAP ) != 0 ) {

					/* Check if Event is executing */
					/* --------------------------- */
					if ((timersem & EVENT_ACTIF ) == 0 ) {

						/* ------------------------- */
						/* Do Event condition Check: */
						/* ------------------------- */
						/* -1) Stack current adresse */
						/* ------------------------- */
						ip_hold [ip_next++] = (fdex - TcodeSegment);

						/* ------------------------- */
						/* -2) Collect Event adresse */ 
						/* ------------------------- */
						fdex = TcodeSegment + eventadr;

						/* ------------------------- */
						/* -3) Indicate EVENT ACTIVE */ 
						/* ------------------------- */
						timersem ^= EVENT_SWAP;

						/* ------------------------- */
						/* Continue execution at the */
						/* Event Checking Adresse    */
						/* ------------------------- */
						continue;
						}

					/* Check for EVENT ACTIVE state over */
					/* --------------------------------- */
					if ((timersem & EVENT_OVER) != 0) {

						/* Restore Latent Event Check */
						/* -------------------------- */
						timersem &= EVENT_STEP;
						timersem ^= EVENT_SWAP;
						}

					}
				   }

				/* Establish New Line Start Adresse */
				/* -------------------------------- */
				lineptr = fdex; 

				/* Perform Quick allocation Liberation */
				/* ----------------------------------- */
				worktop = workhold;
				pushtop = pushhold;

				/* Remove Newline Flag Bit */
				/* ----------------------- */
				tcode &= 0x007F;

#ifdef DEBUGGER
				/* Test for EXADB Step or Break Mode */
				/* --------------------------------- */
				if (db_step_ctrl != 0) {

					/* Test first for STEP mode */
					/* ------------------------ */
					if ((db_step_ctrl & 1) != 0) {
						return(tcode);
						}

					/* Test for WATCH mode active */
					/* -------------------------- */
					if ((db_step_ctrl & 4) != 0) {
						return(tcode);
						}	

					/* Test for ASSIGN mode active */
					/* --------------------------- */
					if ((db_step_ctrl & 8) != 0) {
						if ( AssignBreak != 0 )
							return(tcode);
						}	

					/* Test for Break Key Mode */
					/* ----------------------- */
					if ((db_step_ctrl & 2) != 0) {

						/* Test for Key Waiting */
						/* -------------------- */
						if ( opb() != 0 ) {

						    /* Return Current Tcode */
						    /* -------------------- */
						    return( tcode );

						    }
						}
					}
#endif	/* DEBUGGER */
	/* -------- */

				}

		/* 	Select Tcode Handling Routine		*/
		/*	-----------------------------		*/
#ifdef DEBUGGER
dbentry:
#endif

#ifdef WIN32
				/* Laisse passer les messages Windows */
				if (notify_abqt != 0) {
					let_windows_work
					notify_abqt = 0;
				}
#endif
/*		
	{ EXABYTE buf[128];
	  extern void __stdcall OutputDebugStringA(BPTR);
	  extern int __cdecl wsprintfA(BPTR,BPTR, ...);
	  if (tcode == _tc_ESC) {
	  	wsprintfA(buf,"%0.8lX: %0.2X\r\n",fdex,*fdex);
	  	OutputDebugStringA(buf);
	  }
	}
*/		
				
			switch ( tcode ) {

/* ESCAPE (SEQUENCE)
 * -----------------
 */

case _tc_ESC	: 

#include "exesc.c"		/* Escape Code table switch 	*/	

case _tc_GIS	: 
	balputw( freg [ *fdex ] , (GlobalDataSegment + (Tcodeword( (fdex + 1)))));
	fdex += (WORDSIZE + 1); break;
case _tc_LIS	: 
	balputw( freg [ *fdex ] , (LocalDataSegment + (Tcodeword( (fdex + 1)))));
	fdex += (WORDSIZE + 1); break;


case _tc_GIL	:
	freg [ (e = *fdex) ] = balgetw( ( GlobalDataSegment + (Tcodeword( (fdex + 1) ) ) ));
	xreg [e] = IMMEDIAT;
	fdex += (WORDSIZE + 1); continue;
case _tc_LIL	:
	freg [ (e = *fdex) ] = balgetw( ( LocalDataSegment + (Tcodeword( (fdex + 1)) ) ));
	xreg [e] = IMMEDIAT;
	fdex += (WORDSIZE + 1); continue;
case _tc_GCL	:
	if ( ExFlgSgn == 0 ) {
		freg [ (e = *fdex) ] = (BINAIRE) ReadSchar( ( GlobalDataSegment + (Tcodeword( (fdex + 1) ) ) ));
		}
	else	{
		ExFlgSgn = 0;
		freg [ (e = *fdex) ] = (EXAWORD) *((BPTR) ( GlobalDataSegment + (Tcodeword( (fdex + 1) ) ) ));
		}
	xreg [e] = CHARONLY;
	fdex += (WORDSIZE + 1); continue;
case _tc_LCL	:
	if ( ExFlgSgn == 0 ) {
		freg [ (e = *fdex) ] = (BINAIRE) ReadSchar( ( LocalDataSegment + (Tcodeword( (fdex + 1)) ) ));
		}
	else	{
		ExFlgSgn = 0;
		freg [ (e = *fdex) ] = (EXAWORD) *((BPTR) ( LocalDataSegment + (Tcodeword( (fdex + 1)) ) ));
		}
	xreg [e] = CHARONLY;
	fdex += (WORDSIZE + 1); continue;
case _tc_GCS	:
	*((CPTR) (GlobalDataSegment + (Tcodeword( (fdex + 1) )))) = (char)( freg [ *fdex ]);
	fdex += (WORDSIZE + 1); break;
case _tc_LCS	:
	*((CPTR) (LocalDataSegment + (Tcodeword( (fdex + 1) )))) = (char)( freg [ *fdex ]);
	fdex += (WORDSIZE + 1); break;

/*	This Tcode establishes the temporary UNSIGNED character Flag for
 *	unsigned # register loading
 */ 
case _tc_SGN 	:
	ExFlgSgn = 1; continue;

						
 /* LOAD REGISTER IMMEDIATE VALUE #REGISTER IVALUE
  * -----------------------------------------------
  * Loads the Immediate integer value IVALUE into the register #REGISTER
  * and sets the status field to 0 indicating an Integer value.
  */
case _tc_LDI	:
	freg [ (e = (EXAWORD) *fdex) ] = Tcodeword( (fdex + 1) );
	xreg [ e ] = IMMEDIAT; fdex += ( WORDSIZE + 1);  continue;

/* INCREMENT ADDITIONAL INDEX REGISTER VALUE
 * -----------------------------------------
 */
case _tc_ANX	:
	areg [ (e = *(fdex++)) ]++;
	if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
	continue;

 /* LOAD 1st Index REGISTER IMMEDIATE VALUE #REGISTER IVALUE
  * --------------------------------------------------------
  * Loads the Immediate integer value IVALUE into the 1st index field 
  * of the register #REGISTER .
  */
case _tc_LXI	:
	ireg [(e = *fdex)] = Tcodeword( (fdex + 1)); 
	fdex += (WORDSIZE + 1); 
	if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
	continue;

 /* LOAD 2nd Index REGISTER IMMEDIATE VALUE #REGISTER IVALUE
  * --------------------------------------------------------
  * Loads the Immediate integer value IVALUE into the 2nd index field 
  * of the register #REGISTER .
  */
case _tc_AXI	:
	areg [(e = *fdex)] = Tcodeword( (fdex + 1)); 
	fdex += (WORDSIZE + 1); 
	if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
	continue;

/* RESET (RAZ)
 * -----------
 * Clears all temporary variable descriptors associated with the current
 * segment or procedure.
 */
case	_tc_RAZ	: 
	worktop = workhold; continue;

/* RETURN
 * ------
 * Performs a return near , after a GOSUB, during procedure or segment 
 * code execution.
 */
case _tc_RET	: 

	/* Check for Stack used for Gosubs */
	/* ------------------------------- */
	if ( ip_next == StackHold ) { 
		err_val = ABAL_RETNOGSB; 
		tcode = SOFTERROR; 
		}
	else 	{ 
		ip_next--; fdex = TcodeSegment + ip_hold [ip_next]; tcode = 1;
		}
	continue;

/* GOSUB &ADRESSE
 * --------------
 * Transfers control to the adresse &ADRESSE and saves the current adresse
 * on the stack for the return.
 */
case	_tc_GSB	:

	if (ip_next >= diezstk) { err_val = ABAL_GSB2MANY; tcode = SOFTERROR; }
	else	{
		ip_hold [ (ip_next++) ] = (EXAWORD) (fdex + 2 - TcodeSegment); 
		fdex = (BPTR) (TcodeSegment + Tcodeword( fdex));
		}
	continue;


/* INCREMENT #REGISTER
 * -------------------
 * Increments the contents of register #REGISTER if the status field
 * indicates an IVALUE.
 */
case _tc_INC	:	freg [ *(fdex++) ]++; continue;

/* GOTO	IVALUE
 * -----------
 * Unconditional jump to the adresse represented by IVALUE
 */
case _tc_JMI	:	fdex = (BPTR) (TcodeSegment + Tcodeword( fdex));
			continue;

/* STORE IVALUE to [VARPTR]
 * ------------------------
 * Saves the immediate value IVALUE to the variable pointed by
 * [VARPTR] with automatic type conversion if necessary.
 */ 
case _tc_STI	:	/* STORE Integer to Variable */
	e = Tcodeword(fdex); fdex += WORDSIZE;
ITOVARB:
	if ( (tcode = Tcodeword( fdex )) & ISLOCAL ) {
		workptr2 = LocalDataTable + ( tcode & TOGLOBAL );
		workptr1 = LocalDataSegment;
		}
	else	{
		workptr2 = GlobalDataTable + tcode;
		workptr1 = GlobalDataSegment;
		}
	fdex += WORDSIZE;
	switch ( Tcodeword( workptr2 ) ) {
		case	0x0068 :
		case	0x0060 : /* #(x,y)	*/
			CheckAreg( 0 , workptr2 );
			workptr1 += ( (areg [0] - 1) * (Tcodeword( (workptr2 + (2 * WORDSIZE)))));
		case	0x0048 :
		case	0x0040 : /* #(x)	*/
			CheckIreg( 0 , workptr2 );
			workptr1 += (ireg [0] - 1);
		case	0x0008 :
		case	0x0000 : /* #		*/
			*((CPTR) (workptr1 + (Tcodeword( (workptr2 + WORDSIZE))))) = (char) e; continue;
		case	0x0069 :
		case	0x0061 : /* %(x,y)	*/
			CheckAreg( 0 , workptr2 );
			workptr1 += ( ((areg [0] - 1) * 2) * (Tcodeword( (workptr2 + (2 * WORDSIZE)))));
		case	0x0049 :
		case	0x0041 : /* %(x)	*/
			CheckIreg( 0 , workptr2 );
			workptr1 += ((ireg [0] - 1) * 2);
		case	0x0009 :
		case	0x0001 : 
			balputw( e , ( workptr1 + (Tcodeword( (workptr2 + WORDSIZE) ) ) )); continue;
		case	0x006A :
		case	0x0062 : /* BCD(x,y)	*/
			CheckAreg( 0 , (workptr2 + WORDSIZE));
			workptr1 += ( ((areg [0] - 1) * (Tcodeword( (workptr2 + ( 2 * WORDSIZE))))) * (Tcodeword( (workptr2 + (3 * WORDSIZE)))));
		case	0x004A :
		case	0x0042 : /* BCD(x) 	*/
			CheckIreg( 0 , (workptr2 + WORDSIZE));
			workptr1 += ((ireg [0] - 1) * (Tcodeword( (workptr2 + ( 2 * WORDSIZE)))));
		case	0x000A :
		case	0x0002 : /* BCD 	*/
			(VOID) itobcd(e,(workptr1 + (Tcodeword( (workptr2 + WORDSIZE)))),Tcodeword( (workptr2 + (2 * WORDSIZE)))); continue;
		default	  :
			workval2 = (BINAIRE) e; worktyp2 = VARB_INT16;
			worktyp1 = tcode; workval1 = 0;
			if ((tcode = varbsetw()) != SOFTERROR) { VarbXfer(1); }
		}
		break;

/* CALL FUNCTION
 * -------------
 * Performs standard BAL function (See function descriptions.)
 */
case _tc_CLF	: 
	prndest = 1; tcode = (EXAWORD) *(fdex++);
				     
#ifdef PROTEGE_286	
	switch( tcode & 0x000F ) {
		case 7 : tcode = f_clf7((tcode & 0x00F0) >> 4); break;
		case 8 : tcode = f_clf8((tcode & 0x00F0) >> 4); break;
		case 9 : tcode = f_clf9((tcode & 0x00F0) >> 4); break;
		case 10: tcode = f_clfa((tcode & 0x00F0) >> 4); break;
		case 11: tcode = f_clfb((tcode & 0x00F0) >> 4); break;
		case 12: tcode = f_clfc((tcode & 0x00F0) >> 4); break;
		case 13: tcode = f_clfd((tcode & 0x00F0) >> 4); break;
		case 14: tcode = f_clfe((tcode & 0x00F0) >> 4); break;
		case 15: tcode = f_clff((tcode & 0x00F0) >> 4); break;
		default : tcode = SOFTERROR; err_val = 56;
		}
#else
	tcode = (*smach[tcode & 0x000F])((tcode & 0x00F0) >> 4);
#endif

	break;

/* NEW LINE
 * --------
 * Indicates a new source line for symbolic debugging and Correct RESUME
 * Operation.
 */
case _tc_NEW	: 	lineptr = fdex;	continue;


/* TIMER FUNCTION : 0 = OFF , 1 = GOTO , 2 = GOSUB
 * -----------------------------------------------
 */

case _tc_TIM	:
	(VOID) raz_timer(); tcode = timerwork(); continue;

 /* LOAD REGISTER CONSTANT #REGISTER {CONPTR}
  * -----------------------------------------
  * Loads the constant pointer {CONPTR} into the register #REGISTER
  * and sets the status field to 1 indicating a Constant.
  */
case _tc_LDC	:
	tcode = (EXAWORD) *(fdex++);
	freg [tcode] = Tcodeword( fdex);
	xreg [tcode] = KONSTANT;
	fdex += WORDSIZE;
	continue;

/* DECREMENT 2nd INDEX of #REGISTER
 * --------------------------------
 */
case _tc_DAX	:	areg [ (e = *(fdex++)) ]--; 
			if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
			continue;

/* LOAD 1st INDEX of #REGISTER {CONPTR}
 * ------------------------------------
 * Loads the 1st index field of register #REGISTER with the integer
 * result of the constant pointed to by {CONPTR}
 */
case _tc_LXC	:
	e = (EXAWORD) *(fdex++);
	workptr2 = (TcodeConstants + Tcodeword( fdex )); 
	fdex += WORDSIZE;
KONINDEX:
	if ((worklen2 = (EXAWORD) *(workptr2++)))
		ireg [e] = (EXAWORD) atoi( workptr2, worklen2 );
	else if (((worklen2 = (EXAWORD) *(workptr2++)) & 0x0080)) {
		workptr2 = (GlobalConstants + Tcodeword((workptr2))); 
		goto KONINDEX;
		}
	else	ireg [e] = (EXAWORD) bcdtoi( workptr2, worklen2 );

	if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
	continue;


/* LOAD 2nd INDEX of #REGISTER {CONPTR}
 * ------------------------------------
 * Loads the 2nd index field of register #REGISTER with the integer
 * result of the constant pointed to by {CONPTR}
 */
case _tc_AXC	:
	e = (EXAWORD) *(fdex++);
	workptr2 = (TcodeConstants + Tcodeword( fdex )); fdex += WORDSIZE;
KONANDEX:
	if ((worklen2 = (EXAWORD) *(workptr2++)))
		areg [e] = (EXAWORD) atoi( workptr2, worklen2 );
	else if (((worklen2 = (EXAWORD) *(workptr2++)) & 0x0080)) {
		workptr2 = (GlobalConstants + Tcodeword((workptr2))); 
		goto KONANDEX;
		}
	else	areg [e] = (EXAWORD) bcdtoi( workptr2, worklen2 );
	if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
	continue;

/* PUSH #REGISTER
 * --------------
 * Saves the 4 16 bit fields of the register #REGISTER onto the stack
 * in the following order 
 *	FREG,	IREG,	AREG,	XREG,	LREG,	PREG
 */
case _tc_PSH	:
	if (pushtop+7 >= diezstk) {
		err_val = ABAL_GSB2MANY;
		tcode = SOFTERROR;
		continue;
	}
	tcode = (EXAWORD) *(fdex++);
	sp_hold [pushtop++] = (EXAWORD) freg [ tcode ];
	sp_hold [pushtop++] = (EXAWORD) ireg [ tcode ];
	sp_hold [pushtop++] = (EXAWORD) areg [ tcode ];
	sp_hold [pushtop++] = (EXAWORD) xreg [ tcode ];
	sp_hold [pushtop++] = (EXAWORD) lreg [ tcode ];
	sp_hold [pushtop++] = (EXAWORD) PHIWORD(preg [ tcode ]);
	sp_hold [pushtop++] = (EXAWORD) PLOWORD(preg [ tcode ]);
	tcode = 1;
	continue;


/* DATA READ (Read=0,Varptr)
 * -------------------------
 *	Reads the next DATA item into the variable specified
 *	and advances the DATA pointer.
 */

case _tc_DTV	:
	tcode = Tcodeword( fdex); fdex += WORDSIZE;
	tcode = argsetw(5,tcode);
	if ( tcode != SOFTERROR ) {tcode = getdata();}
	break;

/* DATA READ (Read=0,Register)
 * ---------------------------
 *	Reads the integer value of the next DATA item into the 
 *	Register specified and advances the DATA pointer.
 */

case _tc_DTR	:
	tcode = regdata( ((EXAWORD) *(fdex++)) );
	continue;

/* DECREMENT #REGISTER
 * -------------------
 * Only if the status of #REGISTER is zero indicating an immediate Integer.
 */

case _tc_DEC	:	freg [ *(fdex++) ]--; continue;


/* GOTO	#REGISTER
 * --------------
 * Performs an unconditional jump to the adresse which results from
 * the evaluation of #REGISTER
 */
case _tc_JMR	:
	tcode = (EXAWORD) *fdex;
	switch ( xreg [tcode] ) {
		case IMMEDIAT : tcode = freg [tcode]; break;
		case KONSTANT : tcode = valcon( freg [tcode] ); break;
		case VARIABLE : tcode = valvar( freg [tcode] ,tcode ); break;
		case TEMPDESC : tcode = valtmp( freg [tcode] )   ; break;
		default : tcode = (EXAWORD) ( fdex - TcodeSegment) + 1;
		}
	fdex = (BPTR) (TcodeSegment + tcode);
	tcode = 1; continue;

/* STORE CONSTANT VARIABLE {CONPTR} [VARPTR]
 * -----------------------------------------
 * Stores the value of the constant pointed by {CONPTR} to the variable
 * pointed to by [VARPTR] with automatic type conversion if necessary.
 */

case _tc_STC	:	/* STO CON / VAR */
	tcode = SOFTERROR;
	workptr2 = (TcodeConstants + Tcodeword( fdex )); 
	fdex += WORDSIZE;
	while (1) {
		if ((worklen2 = (EXAWORD) *(workptr2++)))
			worktyp2 = VARB_STR;			
		else if (((worklen2 = (EXAWORD) *(workptr2++)) & 0x0080)) {
			workptr2 = (GlobalConstants + Tcodeword((workptr2))); 
			continue;
			}
		else	worktyp2 = VARB_BCD;
		break;
		}

	worktyp1 = Tcodeword( fdex ); fdex += WORDSIZE; workval1 = 0;
	if ((tcode = varbsetw()) != SOFTERROR) { VarbXfer(1); }
	continue;

/* Access aux Fichiers et ressources NGF / NGR
 * -------------------------------------------
 */

case _tc_NGF	:
#ifdef WIN32
//	let_windows_work
	notify_abqt = 1;
#endif

#ifdef ABALSF
	tcode = sf_ngf();
	break;
#else
	tcode = SOFTERROR; err_val = EXER_FUNCWOT; continue;
#endif

 /* OP #REGISTER &ETIQUETTE 
  * Transfers control to etiquette due to keyboard ready test and stores
  * the key value in the Register.
  */

#ifndef	ABAL21
case _tc_OPR	:
	e = (EXAWORD) *(fdex++);
	if ( opb() ) {
		fdex = TcodeSegment + Tcodeword( fdex );
		freg [ e ] = (EXAWORD) (x_getch() & 0x00FF);
		}
	else	{	freg [e] = 0; fdex += WORDSIZE;	}
	continue;
#endif
 /* OP [VARPTR] &ETIQUETTE 
  * Transfers control to etiquette due to keyboard ready test and stores
  * the key value in the variable [VARPTR] if VARPTR <> 0.
  */

case _tc_OPV	:
	tcode = Tcodeword( fdex); fdex += WORDSIZE;
	if ( tcode == 0 ) {
		if (opb()) { fdex = TcodeSegment + Tcodeword( fdex); }
		else { fdex += WORDSIZE; }
		tcode = 1;
		}
	else {
		if ( opb() ) {
			fdex = TcodeSegment + Tcodeword( fdex);
			workval2 = x_getch();
			}
		else {  fdex += WORDSIZE; workval2 = 0;	}
		worktyp2 = VARB_INT16; worktyp1 = tcode; workval1 = 0;
		if ((tcode = varbsetw()) != SOFTERROR) { VarbXfer(1); }
		continue;
		}
	break;

/* 
 * CONV( Registre , Data_type )
 * ----------------------------
 */
case _tc_CNV	:
	tcode = (EXAWORD) *(fdex++);
	e = Tcodeword( fdex);
	fdex += WORDSIZE;
	tcode = conv(tcode,e);
	continue;


 /* ON ERROR [VARPTR] &ETIQUETTE 
  * Transfers control to etiquette due to an error condition, and stores
  * the error value in the variable [VARPTR] if VARPTR <> 0.
  */

case _tc_OER	:
	tcode = (EXAWORD) *(fdex++); 
	tcode = trapgest(1,Tcodeword(fdex),tcode,0);
	fdex += WORDSIZE;
	continue;
#ifdef	ABAL21
case _tc_OLE	:
	tcode = Tcodeword(fdex); fdex += WORDSIZE;
	tcode = trapgest(tcode,Tcodeword(fdex),0,0);
	fdex += WORDSIZE;
	continue;
#endif
case _tc_OEV	:
	tcode = Tcodeword(fdex); fdex += WORDSIZE;
	tcode = trapgest(tcode,Tcodeword(fdex),0,0);
	fdex += WORDSIZE;
	continue;

#ifdef	ABAL21
case _tc_OEO	:
	tcode = Tcodeword(fdex); fdex += WORDSIZE;
	tcode = trapgest(tcode,Tcodeword(fdex),0,1);
	fdex += WORDSIZE;
	continue;
#endif

/* LOAD REGISTER VARIABLE #REGISTER [VARPTR]
 * -----------------------------------------
 * This function may result in one of two conditions.
 * If the variable pointed by [VARPTR] is an integer EXABYTE or WORDSIZE then
 * its value will by loaded into the register #REGISTER, and the status
 * will be set to 0. Otherwise the pointer [VARPTR] will be loaded and
 * the status will be set to 2 to indicate the variable pointer.
 */
case _tc_LDV	:
	e = *(fdex++);
	if ( (tcode = Tcodeword( fdex )) & ISLOCAL ) {
		workptr2 = LocalDataTable + ( tcode & TOGLOBAL );
		workptr1 = LocalDataSegment;
		}
	else	{
		workptr2 = GlobalDataTable + tcode;
		workptr1 = GlobalDataSegment;
		}
	fdex += WORDSIZE;
	switch ( Tcodeword( workptr2 ) ) {
		case	0x0068 :
		case	0x0060 : /* #(x,y)	*/
			CheckAreg( e , workptr2 );
			workptr1 += ( (areg [e] - 1) * (Tcodeword( (workptr2 + (2 * WORDSIZE)))));
		case	0x0048 :
		case	0x0040 : /* #(x)	*/
			CheckIreg( e , workptr2 );
			workptr1 += (ireg [e] - 1);
		case	0x0008 :
		case	0x0000 : /* #		*/
			if ( ExFlgSgn == 0 ) {
				xreg [e] = CHARONLY;
				freg [e] = (EXAWORD) ( (BINAIRE) ReadSchar( (workptr1 + (Tcodeword( (workptr2 + WORDSIZE)))))); continue;
				}
			else	{
				ExFlgSgn = 0;
				xreg [e] = IMMEDIAT;
				freg [e] = ( (EXAWORD) *((BPTR) (workptr1 + (Tcodeword( (workptr2 + WORDSIZE)))))); continue;
				}
		case	0x0069 :
		case	0x0061 : /* %(x,y)	*/
			CheckAreg( e , workptr2 );
			workptr1 += ( ((areg [e] - 1) * 2) * (Tcodeword( (workptr2 + (2 * WORDSIZE)))));
		case	0x0049 :
		case	0x0041 : /* %(x)	*/
			CheckIreg( e , workptr2 );
			workptr1 += ((ireg [e] - 1) * 2);
		case	0x0009 :
		case	0x0001 : 
			xreg [e] = IMMEDIAT;
			freg [e] = (EXAWORD) balgetw( ( workptr1 +    (Tcodeword( (workptr2 + WORDSIZE) ) ) )); continue;
		case	0x006A :
		case	0x006B :
		case	0x004A :
		case	0x004B :
		case	0x000A :
		case	0x000B :
		case	0x0002 : /* BCD 	*/
		case	0x0003 : /* STR 	*/
		case	0x0042 : /* BCD(x) 	*/
		case	0x0043 : /* STR(x)	*/
		case	0x0062 : /* BCD(x,y)	*/
		case	0x0063 : /* STR(x,y)	*/
			xreg [e] = VARIABLE;
			freg [e] = tcode; 
			continue;
		default	  :
			worktyp1 = tcode; workval1 = e;
			freg [e] = tcode;
			xreg [e] = VARIABLE;
			if (varbset1() != SOFTERROR) {
				switch ( worktyp1 ) {
					case VARB_INT8  :
						xreg [e] = CHARONLY; 
						freg [e] = workval1;
						continue;
					case VARB_INT16 :
						xreg [e] = IMMEDIAT; 
						freg [e] = workval1;
						continue;
					}
				}
			else	{ tcode = SOFTERROR; }
		}
	continue;

 /* ON ERROR ABORT 
  * --------------
  * Dissactivates the current error trap enabled by ON ERROR GOTO
  */
case _tc_ERA	:
	tcode = trapgest(0,0,0,0); 
	continue;

/* LOAD 1st INDEX REGISTER with VARIABLE #REGISTER [VARPTR]
 * --------------------------------------------------------
 * This function loads the integer value of the variable [VARPTR]
 * into the 1st index register of #REGISTER.
 */
case _tc_LXV	:

/* LOAD 2nd INDEX REGISTER with VARIABLE #REGISTER [VARPTR]
 * --------------------------------------------------------
 * This function loads the integer value of the variable [VARPTR]
 * into the 2nd index register of #REGISTER.
 */
case _tc_AXV	:
	fadj = WORDSIZE; e = 0;
	worktyp3 = Tcodeword( (fdex + 1) );
VARBNDX:
	ExFlgSgn = 1;
	if ( worktyp3 & ISLOCAL ) {
		workptr3 = LocalDataTable + ( worktyp3 & TOGLOBAL );
		workptr2 = LocalDataSegment;
		}
	else	{ 
		workptr3 = GlobalDataTable + worktyp3;
		workptr2 = GlobalDataSegment;
		}
	switch ( (worktyp2 = (Tcodeword( workptr3 ))) ) {
		case	0x0068 :
		case	0x0060 : /* #(x,y)	*/
				CheckAreg( e , workptr3 );
				workptr2 += ( (areg [e] - 1) * (Tcodeword( (workptr3 + (2 * WORDSIZE)))));
		case	0x0048 :
		case	0x0040 : /* #(x)	*/
				CheckIreg( e , workptr3 );
				workptr2 += (ireg [e] - 1);
		case	0x0008 :
		case	0x0000 : /* #		*/
				workval2 = ( (EXAWORD) *((BPTR) (workptr2 + (Tcodeword( (workptr3 + WORDSIZE)))))); 
				worktyp2 = VARB_INT16;
				break;
		case	0x0069 :
		case	0x0061 : /* %(x,y)	*/
				CheckAreg( e , workptr3 );
				workptr2 += ( ((areg [e] - 1) * WORDSIZE) * (Tcodeword( (workptr3 + (2 * WORDSIZE)))));
		case	0x0049 :
		case	0x0041 : /* %(x)	*/
				CheckIreg( e , workptr3 );
				workptr2 += ((ireg [e] - 1) * WORDSIZE);
		case	0x0009 :
		case	0x0001 : 
				workval2 = balgetw( ( workptr2 + (Tcodeword( (workptr3 + WORDSIZE) ) ) )); 
				break;
		case	0x006A :
		case	0x006B :
		case	0x0063 :
		case	0x0062 : /* STR ou BCD (x,y)	*/
				CheckAreg( e , (workptr3 + WORDSIZE));
				workptr2 += ( ((areg [e] - 1) * (Tcodeword( (workptr3 + ( 2 * WORDSIZE))))) * (Tcodeword( (workptr3 + (3 * WORDSIZE)))));
		case	0x004A :
		case	0x004B :
		case	0x0043 :
		case	0x0042 : /* STR ou BCD(x) 	*/
				CheckIreg( e , (workptr3 + WORDSIZE));
				workptr2 += ((ireg [e] - 1) * (Tcodeword( (workptr3 + ( 2 * WORDSIZE)))));
		case	0x000A :
		case	0x000B :
		case	0x0003 :
		case	0x0002 : /* STR ou BCD 	*/
				worklen2 = Tcodeword( (workptr3 + ( 2 * WORDSIZE)) );
				workptr2 += (Tcodeword( (workptr3 + WORDSIZE)));
WVAL2SET:
				if (( worktyp2 & VARB_ISOL ) == 2) {
					workval2 = bcdtoi( workptr2,worklen2);
					}
				else	{
					workval2 = atoi( workptr2,worklen2);
					}
				break;
		default		: worktyp2 = worktyp3; workval2 = e;
				  if ( varbset2() == SOFTERROR ) { goto CALCWHAT; }
				  if (( worktyp2 & VARB_ISOL ) < 2 ) { break; }
				  goto WVAL2SET;
		}

	ExFlgSgn = 0;
	e = (EXAWORD) *fdex; fdex += ( fadj + 1);
	if ( tcode & 4 ) {	areg [e] = workval2;	}
	else		 {	ireg [e] = workval2;	}
	if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
	continue;
	
/* POP	#REGISTER
 * Recovers the contents of the register #REGISTER from the stack
 * The 16 bit fields are recovered in the following order 
 * 	PREG,	LREG,	XREG,	AREG,	IREG,	FREG
 */
case _tc_POP	:
	if (--pushtop < 6) { 
		err_val = ABAL_RETNOGSB; tcode = SOFTERROR; 
	}
	else 	{  
		tcode = (EXAWORD) *(fdex++);
		{ EXAWORD a,b;
		  a = sp_hold [pushtop--];
		  b = sp_hold [pushtop--];
		  preg [ tcode ] = (BPTR) (PULONG(a,b));
		}
		lreg [ tcode ] = sp_hold [pushtop--];
		xreg [ tcode ] = sp_hold [pushtop--];
		areg [ tcode ] = sp_hold [pushtop--];
		ireg [ tcode ] = sp_hold [pushtop--];
		freg [ tcode ] = sp_hold [pushtop];
		tcode = 1; 
	}
	continue;


/* 
 * Chargement du registre #REG avec VARPTR
 * ---------------------------------------
 * Contrairement a l'operation LDV cette operation n'essai pas
 * d'evaluer le pointeur de variable en integer avant le chargement
 * du registre.
 *	Resultat	Freg [ reg ] = VARPTR
 *			Xreg [ reg ] = 2
 *			Ireg [ reg ] and Areg [ reg ] restent inchanges
 */

case _tc_VPT	:
	tcode = (EXAWORD) *(fdex++);
	freg [tcode] = Tcodeword( fdex);
	xreg [tcode] = VARIABLE;
	fdex += WORDSIZE;
	continue;


/* INCREMENT 1st INDEX #REGISTER
 * -----------------------------
 */
case _tc_INX	:	ireg [ ( e = (*fdex++)) ]++; 
			if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
			continue;


/* GOTO [VARPTR]
 * -------------
 * Transfers control direct to the adresse indicated by the integer values
 * of the variable [VARPTR].
 */
case _tc_JMV	:
	e = valvar(Tcodeword( fdex),0);
	fdex = (BPTR) (TcodeSegment + (EXAWORD) e);
	continue;

/* STORE [VARPTR1] to [VARPTR2]
 * ----------------------------
 * Duplicates the value of variable [VARPTR1] into the variable
 * pointed to by [VARPTR2] with automatic type conversion if needed.
 */
case _tc_STV	:
	tcode = Tcodeword( fdex);
	fdex += WORDSIZE;
	tcode = varcpy(tcode,Tcodeword( fdex),0,0);
	fdex += WORDSIZE; 
	break;

/* Entree Sortie Standard (PRINT ASK etc)
 * --------------------------------------
 * This switchs the motor to the IOF routines which continue until an
 * ask or exit code is recieved. (Sub functions ASK,PRN,TAB,DEV,FMT etc)
 */

case _tc_IOF	:
#ifdef WIN32
//	let_windows_work
	notify_abqt = 1;
#endif
	tcode = iowork();
	break;

/* NO OPERATION
 * ------------
 * This code may be used as a filler code and provoques strictly
 * no other function than to advance the code pointer to the next.
 */
case _tc_NOP	:

#ifdef	DEBUGGER
	/*	This tcode indicates a possible TRAP location 	*/
	/*	---------------------------------------------	*/
		return( _tc_NOP );
#else
 		continue;
#endif


/* LOAD #REGISTER1 via #REGISTER2
 * ------------------------------
 * Evaluates #REGISTER2 and places the result in #REGISTER1
 */
case _tc_LDR	:
	tcode = (EXAWORD) *(fdex++);
	e     = (EXAWORD) *(fdex++);
	freg [tcode] = freg [e];	
	ireg [tcode] = ireg [e];
	areg [tcode] = areg [e];
#ifdef	CONV_BCD_TO_PROC
	if ( xreg [e] & PTRSTATUS ) {	xreg [ tcode ] = VARIABLE; }
#else
	lreg [tcode] = lreg [e];
	preg [tcode] = preg [e];
#endif
	xreg [tcode] = xreg [e];
	continue;

/* NEGATE #REGISTER
 * ----------------
 */
case _tc_NGR	:

	/* Check for an Integer in a Register */
	/* ---------------------------------- */
	if (( xreg [(tcode = (EXAWORD) *(fdex++))] & 0x0003 ) == IMMEDIAT ) {

		/* Negate Data Register Value */
		/* -------------------------- */
		freg [tcode] = (-freg [tcode]); 
		tcode = 1; 

		/* No Error Possible */
		/* ----------------- */
		continue;
		}
	else	{
		/* Perform Complexe Negation */
		/* ------------------------- */
		tcode = negwork(1,tcode);

		/* Allow Error Checking and Externals Update */
		/* ----------------------------------------- */
		break;
		}

/*	OLD METHOD BUG APPARANT with A = -ABS(B)
 *	----------------------------------------
 *	tcode = (EXAWORD) *(fdex++);
 *	if ( xreg [tcode] & PTRSTATUS ) { xreg [ tcode ] = VARIABLE; }
 *	if ( xreg [tcode] == VARIABLE ) { tcode = negwork(1,tcode);  }
 *	else { freg [tcode] = (-freg [tcode]); tcode = 1; }
 *	continue;
 */

/* LOAD 1st INDEX of #REGISTER1 via #REGISTER2
 * -------------------------------------------
 * Evaluates #REGISTER2 and places the result in 1st index field 
 * of the register #REGISTER1
 */

case _tc_LXR	:
	switch ( xreg [(*(fdex + 1))] ) {
		case CHARONLY : ireg [(e = *fdex)] = ( freg [((EXAWORD) *(fdex + 1))] & 0x00FF ); fdex += WORDSIZE; break;
		case IMMEDIAT : ireg [(e = *fdex)] = freg [((EXAWORD) *(fdex + 1))]; fdex += WORDSIZE; break;
		case KONSTANT : workptr2 = (TcodeConstants + freg [((EXAWORD) *(fdex + 1))]); 
				e = *(fdex++); goto KONINDEX;
		case VARIABLE : worktyp3 = freg [ (e = ((EXAWORD) *(fdex+1))) ]; 
				fadj = 1; goto VARBNDX;
		case PTRSTR    :
			ireg [(e = *fdex)] = atoi( preg [ *(fdex+1) ] , lreg [ *(fdex+1) ] );
			fdex += WORDSIZE;
			break;
		case PTRBCD    :
			ireg [(e = *fdex)] = bcdtoi( preg [ *(fdex+1) ] , lreg [ *(fdex+1) ] );
			fdex += WORDSIZE;
			break;
		case TEMPDESC : workptr2 = (TcodeByteStack + freg [((EXAWORD) *(fdex + 1))]);
			switch( (Tcodeword( workptr2 ) ) ) {
				case VARB_STR : ireg [ (e = *fdex) ] = (EXAWORD) atoi(( workptr2 + ( 2 * WORDSIZE))  , (Tcodeword( (workptr2 + WORDSIZE) ))); break;
				case VARB_BCD : ireg [ (e = *fdex) ] = (EXAWORD) bcdtoi(( workptr2 + ( 2 * WORDSIZE))  , (Tcodeword( (workptr2 + WORDSIZE) ))); break;
				}
			fdex += WORDSIZE;
		}
PTRKILL:
	if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
	continue;

/* LOAD 2nd INDEX of #REGISTER1 via #REGISTER2
 * -------------------------------------------
 * Evaluates #REGISTER2 and places the result in 2nd index field 
 * of the register #REGISTER1
 */
case _tc_AXR	:
	switch ( xreg [(*(fdex + 1))] ) {
		case CHARONLY : areg [(e = *fdex)] = ( freg [((EXAWORD) *(fdex + 1))] & 0x00FF ); fdex += WORDSIZE; break;
		case IMMEDIAT : areg [(e = *fdex)] = freg [((EXAWORD) *(fdex + 1))]; fdex += WORDSIZE; break;
		case KONSTANT : workptr2 = (TcodeConstants + freg [((EXAWORD) *(fdex + 1))]); 
				e = *(fdex++); goto KONANDEX;
		case VARIABLE : worktyp3 = freg [ (e = ((EXAWORD) *(fdex+1))) ]; 
				fadj = 1; goto VARBNDX;
		case PTRSTR    :
			areg [(e = *fdex)] = atoi( preg [ *(fdex+1) ] , lreg [ *(fdex+1) ] );
			fdex += WORDSIZE;
			break;
		case PTRBCD    :
			areg [(e = *fdex)] = bcdtoi( preg [ *(fdex+1) ] , lreg [ *(fdex+1) ] );
			fdex += WORDSIZE;
			break;
		case TEMPDESC : workptr2 = (TcodeByteStack + freg [((EXAWORD) *(fdex + 1))]);
				switch( (Tcodeword( workptr2 ) ) ) {
					case VARB_STR : areg [ (e = *fdex) ] = (EXAWORD) atoi(( workptr2 + ( 2 * WORDSIZE))  , (Tcodeword( (workptr2 + WORDSIZE) ))); break; 
					case VARB_BCD : areg [ (e = *fdex) ] = (EXAWORD) bcdtoi(( workptr2 + ( 2 * WORDSIZE))  , (Tcodeword( (workptr2 + WORDSIZE) ))); break;
					}
				fdex += WORDSIZE;
		}
	if ( xreg [e] & PTRSTATUS ) {	xreg [ e ] = VARIABLE; }
	continue;

/* LDF : Local Defined function
 * ----------------------------
 * Allows user defined function to be called 
 *
 *	LDF /ff , /aa , /xx [ ,/yy ] , /rr
 *
 *	Where :		/ff	Entry id in user function table
 *			/aa	Argument descriptor
 *			/xx [/yy] possible 2 bytes of Arguament identity
 *			/rr	Register id for Integer result
 *
 *	Syntax ABAL	Result% = "Fonction"( Arguament )
 *			Result% = (Variable)( Arguament )
 *	
 *	Assembleur	LDF n , Arg , #r
 *
 */

case _tc_LDF	:
#ifdef	ABALPS
#ifdef	WIN32
//	let_windows_work
	notify_abqt = 1;
#endif
	tcode = DoFuse(0); break;
#ifdef	ABAL21
case _tc_LDE	:
#ifdef	WIN32
//	let_windows_work
	notify_abqt = 1;
#endif
	tcode = DoFuse(1); break;
#endif
#else
	tcode = 0; err_val = 58; 
	continue;
#endif

/* RESUME [&etiquette]
 * -------------------
 * Allows the continuation after error handling at the adresse supplied
 */
case _tc_REQ	:	tcode = trapwork( Tcodeword(fdex) );	continue;

/* ON ERROR RESUME
 * ---------------
 * Ressumes code execution at the adresse that provoqued the error
 * condition after error handling.
 */
case _tc_RES	:	tcode = trapwork(MOINS_UN);	continue;

#ifdef	ABAL21
case _tc_OEP	:	tcode = pop_error_context();	continue;
#endif

case _tc_JEQI 	:
	if ( ( xreg [ (e = *fdex) ] & 0x0803 ) != IMMEDIAT ) { goto SWITXXXX; }
	if ( freg [ e ] == (Tcodeword( (fdex + 1) )) ) { fdex = TcodeSegment + (Tcodeword( (fdex + (WORDSIZE + 1)))); continue; }
	fdex += ((2 * WORDSIZE) + 1);
	continue;
case _tc_JNEI	:
	if ( ( xreg [ (e = *fdex) ] & 0x0803 ) != IMMEDIAT ) { goto SWITXXXX; }
	if ( freg [ e ] != (Tcodeword( (fdex + 1) )) ) { fdex = TcodeSegment + (Tcodeword( (fdex + (WORDSIZE + 1)))); continue; }
	fdex += ((2 * WORDSIZE) + 1);
	continue;
case _tc_JGRI	:
	if ( ( xreg [ (e = *fdex) ] & 0x0803 ) != IMMEDIAT ) { goto SWITXXXX; }
	if ( ((BINAIRE) freg [ e ]) > ((BINAIRE) (Tcodeword( (fdex + 1) ))) ) { fdex = TcodeSegment + (Tcodeword( (fdex + (WORDSIZE + 1)))); continue; }
	fdex += ((2 * WORDSIZE) + 1);
	continue;
case _tc_JLSI	:
	if ( ( xreg [ (e = *fdex) ] & 0x0803 ) != IMMEDIAT ) { goto SWITXXXX; }
	if ( ((BINAIRE) freg [ e ]) < ((BINAIRE) (Tcodeword( (fdex + 1) ))) ) { fdex = TcodeSegment + (Tcodeword( (fdex + (WORDSIZE + 1)))); continue; }
	fdex += ((2 * WORDSIZE) + 1);
	continue;
case _tc_JLEI	:
	if ( ( xreg [ (e = *fdex) ] & 0x0803 ) != IMMEDIAT ) { goto SWITXXXX; }
	if ( ((BINAIRE) freg [ e ]) <= ((BINAIRE) (Tcodeword( (fdex + 1) ))) ) { fdex = TcodeSegment + (Tcodeword( (fdex + (WORDSIZE + 1)))); continue; }
	fdex += ((2 * WORDSIZE) + 1);
	continue;
case _tc_JGEI	:
	if ( ( xreg [ (e = *fdex) ] & 0x0803 ) != IMMEDIAT ) { goto SWITXXXX; }
	if ( ((BINAIRE) freg [ e ]) >= ((BINAIRE) (Tcodeword( (fdex + 1) ))) ) { fdex = TcodeSegment + (Tcodeword( (fdex + (WORDSIZE + 1)))); continue; }
	fdex += ((2 * WORDSIZE) + 1);
	continue;

/*==========================================================================*/
/* CALCULATE #REGISTER1 IVALUE #REGISTER2
 * --------------------------------------
 * Evaluates the expression between the contents of #REGISTER1 and
 * the immediate value IVALUE. The result is stored wrt REGISTER2 
 * and the operand data types. If INTEGER calculation is performed
 * then the target register will contain an integer result. For string
 * and BCD calculations the target register will contain a temporary
 * descriptor pointer to the result.
 *	SREG , INTEGER , DREG
 */

case	_tc_ADI	:
	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
 	freg [(tcode = *(fdex + (WORDSIZE + 1)))] = ((BINAIRE) freg [ e ] + (BINAIRE) (Tcodeword( (fdex + 1) )));
	xreg [tcode] = IMMEDIAT; fdex += (2 * WORDSIZE);
	continue;
case	_tc_SBI	:
	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
 	freg [(tcode = *(fdex + (WORDSIZE + 1)))] = ((BINAIRE) freg [ e ] - (BINAIRE) (Tcodeword( (fdex + 1) )));
	xreg [tcode] = IMMEDIAT; fdex += (2 * WORDSIZE);
	continue;
case	_tc_MLI	:
	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
 	freg [(tcode = *(fdex + (WORDSIZE + 1)))] = ((BINAIRE) freg [ e ] * (BINAIRE) (Tcodeword( (fdex + 1) )));
	xreg [tcode] = IMMEDIAT; fdex += (2 * WORDSIZE);
	continue;
case	_tc_DVI	:
	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
	if ( (workval1 = (Tcodeword( (fdex + 1) ))) == 0 )   { err_val = 102; tcode = 0; continue; }
	freg [(tcode = *(fdex + (WORDSIZE + 1)))] = ( (BINAIRE) freg [ e ] / workval1);
	xreg [tcode] = IMMEDIAT; fdex += (2 * WORDSIZE);
	continue;
case	_tc_ANI	:
	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
	freg [(tcode = *(fdex + (WORDSIZE + 1)))] = ( freg [ e ] & (Tcodeword( (fdex + 1) )));
	xreg [tcode] = IMMEDIAT;  fdex += (2 * WORDSIZE);
	continue;
case	_tc_ORI	:
	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
	freg [(tcode = *(fdex + (WORDSIZE + 1)))] = ( freg [ e ] | (Tcodeword( (fdex + 1) )));
	xreg [tcode] = IMMEDIAT;  fdex += (2 * WORDSIZE);
	continue;
case	_tc_XRI	:
	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
	freg [(tcode = *(fdex + (WORDSIZE + 1)))] = ( freg [ e ] ^ (Tcodeword( (fdex + 1) )));
	xreg [tcode] = IMMEDIAT; fdex += (2 * WORDSIZE);
	continue;
case	_tc_MDI	:
/*
 *	if ( (xreg [ (e = *fdex) ] & 0x0803) != IMMEDIAT ) { goto SWITXXXX; }
 *	if ( (workval1 = (Tcodeword( (fdex + 1) ))) == 0 )   { err_val = 102; tcode = 0; continue; }
 *	freg [(tcode = *(fdex + (WORDSIZE + 1)))] = ( (BINAIRE) freg [ e ] % workval1);
 *	freg [tcode] = abs( freg [tcode] );
 *	xreg [tcode] = IMMEDIAT; fdex += (2 * WORDSIZE);
 *	continue;
 */
SWITXXXX:
	worktyp2 = VARB_INT16; workval2 = (BINAIRE) Tcodeword(( fdex + 1 )); 
	fadj = WORDSIZE; goto SREGEVAL;

/* CALCULATE #REGISTER1 {CONPTR} #REGISTER2
 * ----------------------------------------
 * Evaluates the expression between the contents of #REGISTER1 and
 * the constant pointer {CONPTR}. The result is stored wrt REGISTER2.
 */
case 0x0038	:
case 0x0039	:
case 0x003A	:
case 0x003B	:
case 0x003C	:
case 0x003D	:
case 0x003E	:
case 0x003F	:

case	_tc_ADC	:
case	_tc_SBC	:
case	_tc_MLC	:
case	_tc_DVC	:
case	_tc_MDC	:
case	_tc_ANC	:
case	_tc_ORC	:
case	_tc_XRC	:

	workptr2 = (TcodeConstants + Tcodeword( (fdex + 1) )); fadj = WORDSIZE;
KONEVAL:
	while (1) {
		if ((worklen2 = (EXAWORD) *(workptr2++)))
			worktyp2 = VARB_STR;			
		else if (((worklen2 = (EXAWORD) *(workptr2++)) & 0x0080)) {
			workptr2 = (GlobalConstants + Tcodeword((workptr2))); 
			continue;
			}
		else	worktyp2 = VARB_BCD;
		break;
		}

	goto SREGEVAL;

/* CALCULATE #REGISTER1 [VARPTR] #REGISTER2
 * ----------------------------------------
 * Evaluates the expression between the contents of #REGISTER1 and
 * the constant pointer [VARPTR]. The result is stored wrt REGISTER2.
 */
case 0x0058	:
case 0x0059	:
case 0x005A	:
case 0x005B	:
case 0x005C	:
case 0x005D	:
case 0x005E	:
case 0x005F	:

case	_tc_ADV	:
case	_tc_SBV	:
case	_tc_MLV	:
case	_tc_DVV	:
case	_tc_MDV	:
case	_tc_ANV	:
case	_tc_ORV	:
case	_tc_XRV	:

	worktyp3 = Tcodeword( (fdex + 1) ); fadj = WORDSIZE; e = 0;
VARBEVAL:
	if ( worktyp3 & ISLOCAL ) {
		workptr3 = LocalDataTable + ( worktyp3 & TOGLOBAL );
		workptr2 = LocalDataSegment;
		}
	else	{ 
		workptr3 = GlobalDataTable + worktyp3;
		workptr2 = GlobalDataSegment;
		}
	switch ( (worktyp2 = (Tcodeword( workptr3 ))) ) {
		case	0x0068 :
		case	0x0060 : /* #(x,y)	*/
				CheckAreg( e , workptr3 );
				workptr2 += ( (areg [e] - 1) * (Tcodeword( (workptr3 + (2 * WORDSIZE)))));
		case	0x0048 :
		case	0x0040 : /* #(x)	*/
				CheckIreg( e , workptr3 );
				workptr2 += (ireg [e] - 1);
		case	0x0008 :
		case	0x0000 : /* #		*/
				workval2 = ( (BINAIRE) ReadSchar( (workptr2 + (Tcodeword( (workptr3 + WORDSIZE)))))); 
				worktyp2 = VARB_INT16;
				goto SREGEVAL;
		case	0x0069 :
		case	0x0061 : /* %(x,y)	*/
				CheckAreg( e , workptr3 );
				workptr2 += ( ((areg [e] - 1) * WORDSIZE) * (Tcodeword( (workptr3 + (2 * WORDSIZE)))));
		case	0x0049 :
		case	0x0041 : /* %(x)	*/
				CheckIreg( e , workptr3 );
				workptr2 += ((ireg [e] - 1) * WORDSIZE);
		case	0x0009 :
		case	0x0001 : 
				workval2 = balgetw( ( workptr2 + (Tcodeword( (workptr3 + WORDSIZE) ) ) )); 
				goto SREGEVAL;
		case	0x006A :
		case	0x006B :
		case	0x0063 :
		case	0x0062 : /* STR ou BCD (x,y)	*/
				CheckAreg( e , (workptr3 + WORDSIZE));
				workptr2 += ( ((areg [e] - 1) * (Tcodeword( (workptr3 + ( 2 * WORDSIZE))))) * (Tcodeword( (workptr3 + (3 * WORDSIZE)))));
		case	0x004A :
		case	0x004B :
		case	0x0043 :
		case	0x0042 : /* STR ou BCD(x) 	*/
				CheckIreg( e , (workptr3 + WORDSIZE));
				workptr2 += ((ireg [e] - 1) * (Tcodeword( (workptr3 + ( 2 * WORDSIZE)))));
		case	0x000A :
		case	0x000B :
		case	0x0003 :
		case	0x0002 : /* STR ou BCD 	*/
				worklen2 = Tcodeword( (workptr3 + ( 2 * WORDSIZE)) );
				workptr2 += (Tcodeword( (workptr3 + WORDSIZE)));
				if ( e > 0 ) {
					lreg [e] = worklen2;
					xreg [e] = ((worktyp2 & VARB_ISOL ) | PTRSTATUS);
					preg [e] = workptr2;
					}
				goto SREGEVAL;
		default		: worktyp2 = worktyp3; workval2 = e;
				  if ( varbset2() == SOFTERROR ) {
					goto CALCWHAT;
					}
				goto SREGEVAL;
		}

/* CALCULATE #REGISTER1 #REGISTER3 #REGISTER2
 * ------------------------------------------
 * Evaluates the expression between the contents of #REGISTER1 and
 * the contents of #REGISTER3. The result is stored wrt REGISTER2.
 */

case 0x0078	:
case 0x0079	:
case 0x007A	:
case 0x007B	:
case 0x007C	:
case 0x007D	:
case 0x007E	:
case 0x007F	:

case	_tc_ADR	:
case	_tc_SBR	:
case	_tc_MLR	:
case	_tc_DVR	:
case	_tc_MDR	:
case	_tc_ANR	:
case	_tc_ORR	:
case	_tc_XOR	:	

	fadj = 1;
	switch ( xreg [ (e = (EXAWORD) *( fdex + 1 )) ] ) {
		case CHARONLY  :
		case IMMEDIAT  :
			workval2 = freg [ e ]; worktyp2 = VARB_INT16;
			goto SREGEVAL;
		case KONSTANT  :
			workptr2 = (TcodeConstants + freg [ e ]);
			goto KONEVAL;
		case VARIABLE  :
			worktyp3 = freg [ e ]; 
			goto VARBEVAL;
		case PTRSTR    :
			worktyp2 = VARB_STR;
			worklen2 = lreg [e];
			workptr2 = preg [e];
			goto SREGEVAL;
		case PTRBCD    :
			worktyp2 = VARB_BCD;
			worklen2 = lreg [e];
			workptr2 = preg [e];
			goto SREGEVAL;
		case TEMPDESC  :
			workptr2 = (TcodeByteStack + freg [ e ]);
			worktyp2 = Tcodeword( workptr2 );
			worklen2 = Tcodeword( (workptr2 + WORDSIZE) );
			workptr2 += ( 2 * WORDSIZE );
		}

SREGEVAL:
	e = (EXAWORD) *fdex; fdex += (fadj + 1 );
	switch ( xreg [ e ] ) {
		case CHARONLY  :
		case IMMEDIAT  :
			workval1 = freg [ e ]; worktyp1 = 1;
			goto DOCALC;
		case KONSTANT  :
			workptr1 = (TcodeConstants + freg [ e ]);
			while (1) {
				if ((worklen1 = (EXAWORD) *(workptr1++)))
					worktyp1 = VARB_STR;			
				else if (((worklen1 = (EXAWORD) *(workptr1++)) & 0x0080)) {
					workptr1 = (GlobalConstants + Tcodeword((workptr1))); 
					continue;
					}
				else	worktyp1 = VARB_BCD;
				break;
				}
			goto DOCALC;
		case PTRSTR    :
			worktyp1 = VARB_STR;
			worklen1 = lreg [e];
			workptr1 = preg [e];
			goto DOCALC; 
		case PTRBCD    :
			worktyp1 = VARB_BCD;
			worklen1 = lreg [e];
			workptr1 = preg [e];
			goto DOCALC; 
		case VARIABLE  :
			worktyp3 = freg [ e ]; 
			if ( worktyp3 & ISLOCAL ) {
				workptr3 = LocalDataTable + ( worktyp3 & TOGLOBAL );
				workptr1 = LocalDataSegment;
				}
			else	{ 
				workptr3 = GlobalDataTable + worktyp3;
				workptr1 = GlobalDataSegment;
				}
			switch ( (worktyp1 = (Tcodeword( workptr3 ))) ) {
				case	0x0068 :
				case	0x0060 : /* #(x,y)	*/
						CheckAreg( e , workptr3 );
						workptr1 += ( (areg [e] - 1) * (Tcodeword( (workptr3 + (2 * WORDSIZE)))));
				case	0x0048 :
				case	0x0040 : /* #(x)	*/
						CheckIreg( e , workptr3 );
						workptr1 += (ireg [e] - 1);
				case	0x0008 :
				case	0x0000 : /* #		*/
						workval1 = ( (BINAIRE) ReadSchar( (workptr1 + (Tcodeword( (workptr3 + WORDSIZE)))))); 
						worktyp1 = VARB_INT16;
						goto DOCALC;
				case	0x0069 :
				case	0x0061 : /* %(x,y)	*/
						CheckAreg( e , workptr3 );
						workptr1 += ( ((areg [e] - 1) * WORDSIZE) * (Tcodeword( (workptr3 + (2 * WORDSIZE)))));
				case	0x0049 :
				case	0x0041 : /* %(x)	*/
						CheckIreg( e , workptr3 );
						workptr1 += ((ireg [e] - 1) * WORDSIZE);
				case	0x0009 :
				case	0x0001 : 
						workval1 = balgetw( ( workptr1 + (Tcodeword( (workptr3 + WORDSIZE) ) ) )); 
						goto DOCALC;
				case	0x006A :
				case	0x006B :
				case	0x0063 :
				case	0x0062 : /* STR ou BCD (x,y)	*/
						CheckAreg( e , (workptr3 + WORDSIZE) );
						workptr1 += ( ((areg [e] - 1) * (Tcodeword( (workptr3 + ( 2 * WORDSIZE))))) * (Tcodeword( (workptr3 + (3 * WORDSIZE)))));
				case	0x004A :
				case	0x004B :
				case	0x0043 :
				case	0x0042 : /* STR ou BCD(x) 	*/
						CheckIreg( e , (workptr3 + WORDSIZE));
						workptr1 += ((ireg [e] - 1) * (Tcodeword( (workptr3 + ( 2 * WORDSIZE)))));
				case	0x000A :
				case	0x000B :
				case	0x0003 :
				case	0x0002 : /* STR ou BCD 	*/
						worklen1 = Tcodeword( (workptr3 + ( 2 * WORDSIZE)) );
						workptr1 += (Tcodeword( (workptr3 + WORDSIZE)));
						lreg [e] = worklen1;
						xreg [e] = ((worktyp1 & VARB_ISOL ) | PTRSTATUS);
						preg [e] = workptr1;
						goto DOCALC;
				default		: worktyp1 = freg [(workval1 = e)]; 
						  if ( varbset1() == SOFTERROR ) { goto CALCWHAT; }
				}
			goto DOCALC;
		case TEMPDESC  :
			workptr1 = (TcodeByteStack + freg [ e ]);
			worktyp1 = Tcodeword( workptr1 );
			worklen1 = Tcodeword( (workptr1 + WORDSIZE) );
			workptr1 += ( 2 * WORDSIZE );
		}

DOCALC:
if (( tcode & 0x0010 ) == 0 ) { /* Alors Calculs */
			   	/* ------------- */
	switch ( worktyp1 & VARB_ISOL ) {
		case VARB_INT8	:
		case VARB_INT16	:
			switch ( worktyp2 & VARB_ISOL ) {
				case VARB_INT8	:
				case VARB_INT16	:
				  switch (tcode & 0x0007)	{
					case	0 : workval1 += workval2; break;
					case	1 : workval1 -= workval2; break;
					case	2 : workval1 *= workval2; break;
					case	3 : if ( workval2 != 0) { workval1 /= workval2; break; }
						    else { err_val = ABAL_NDXZERO; tcode = 0; continue; }
					case	4 : if ( workval2 == 0) { err_val = ABAL_NDXZERO; tcode = 0; continue; }
						    if ( workval1 < 0 ) { workval1 *= -1; }
						    if ( workval2 < 0 ) { workval2 *= -1; }
						    workval1 = (BINAIRE)((EXAWORD)workval1 % (EXAWORD)workval2); break;
					case	5 : workval1 &= (EXAWORD) workval2; break;
					case	6 : workval1 |= (EXAWORD) workval2; break;
					case	7 : workval1 ^= (EXAWORD) workval2; break;
					} /* End case */
				  tcode = (EXAWORD) *(fdex++);
				  if ( tcode == 0 ) { tcode = e; } 
				  freg [ tcode ] = workval1;
				  xreg [ tcode ] = IMMEDIAT;
				  continue;
				case VARB_BCD   :
					worklen1 = 4;
					PileCheck( worklen1 );
					(VOID) itobcd(workval1,(TcodeByteStack + worktop),4);
					workptr1 = (TcodeByteStack + worktop);
					worklen1 = 4; worktop += 4;
					goto DOBCD;
				case VARB_STR   :
					worklen1 = 6;
					PileCheck( worklen1 );
					(VOID) itoa(workval1,(TcodeByteStack + worktop),6);
					workptr1 = (TcodeByteStack + worktop);
					worktop += 6;
					goto DOSTR;
				}	
			goto CALCWHAT;
		case VARB_STR :
			switch ( worktyp2 & VARB_ISOL ) {
				case VARB_INT8	:
				case VARB_INT16 :
					worklen2 = 6;
					PileCheck( worklen2 );
					(VOID) itoa(workval2,(TcodeByteStack + worktop),6);
					workptr2 = (TcodeByteStack + worktop);
					worktop += 6;
					goto DOSTR;
				case VARB_BCD   :
					worklen2 = (BCDMAX * 2); 
					PileCheck( worklen2 );
					(VOID) bcdtoa( workptr2,worklen2,(TcodeByteStack + worktop),(BCDMAX * 2));
					workptr2 = (TcodeByteStack + worktop);
					worktop += (BCDMAX * 2);
				case VARB_STR :
DOSTR:
					e = (EXAWORD) *(fdex++);		/* Collect register ID		*/
					if ( e != 0 ) {
						worklen3 = (worklen2 + worklen1);	/* Calculate result length 	*/
						PileCheck( worklen3 );			/* Check temporary zone		*/
						freg [ e ] = worktop;			/* Store TEMPDESC offset	*/
						xreg [ e ] = TEMPDESC;			/* indicate TEMPDESC		*/
						workptr3 = (TcodeByteStack + worktop);	/* Calculate result pointer	*/
						TcodePmot( workptr3 , VARB_STR);	/* Create string descriptor	*/
						TcodePmot( (workptr3 + WORDSIZE),worklen3);	/* Store  string length    	*/
						workptr3 += (2 * WORDSIZE);			/* Adjust Result pointer	*/
						worktop  += (worklen3 + (2 * WORDSIZE));	/* Adjust stack pointer		*/
						}
					else	{ workptr3 = workptr1; worklen3 = worklen1; }
					tcode = strcalc( tcode & 7 );
					goto CALCEXIT;
					}
		case VARB_BCD :
			switch ( worktyp2 & VARB_ISOL ) {
				case VARB_INT8	:
				case VARB_INT16 :
					PileCheck( 4 );
					(VOID) itobcd(workval2,(TcodeByteStack + worktop),6);
					workptr2 = (TcodeByteStack + worktop);
					worklen2 = 4; worktop += 4;
					goto DOBCD;
				case VARB_STR :
					worklen2 = BCDMAX;
					PileCheck( worklen2 );
					(VOID) atobcd( workptr2,(TcodeByteStack + worktop), BCDMAX,worklen2); 
					workptr2 = (TcodeByteStack + worktop); worktop += BCDMAX;
				case VARB_BCD :
DOBCD:
					e = (EXAWORD) *(fdex++);		/* Collect register ID		*/
					if ( e != 0 ) {
						worklen3 = BCDMAX;			/* Calculate result length 	*/
						PileCheck( worklen3 );			/* Check temporary zone		*/
						freg [ e ] = worktop;			/* Store TEMPDESC offset	*/
						xreg [ e ] = TEMPDESC;			/* indicate TEMPDESC		*/
						workptr3 = (TcodeByteStack + worktop);	/* Calculate result pointer	*/
						TcodePmot( workptr3 , VARB_BCD);	/* Create string descriptor	*/
						TcodePmot( (workptr3 + WORDSIZE),worklen3);	/* Store  string length    	*/
						workptr3 += (2 * WORDSIZE);			/* Adjust Result pointer	*/
						worktop  += (BCDMAX + (2 * WORDSIZE));	/* Adjust stack pointer		*/
						}
					else	{ workptr3 = workptr1; worklen3 = worklen1; }
					if (TempZone() != SOFTERROR) { 
						tcode = bcdcalc( tcode & 7 );
						}
					else	{ tcode = SOFTERROR; }
					goto CALCEXIT;
					}
		}	
CALCEXIT:
	ExFlgSgn = 0;
	break;
INDEX2BIG:
	ExFlgSgn = 0;
	err_val = ABAL_NDX2BIG;
	tcode   = SOFTERROR;
	continue;
INDEXZERO:
	ExFlgSgn = 0;
	err_val = ABAL_NDXZERO;
	tcode   = SOFTERROR;
	continue;
CALCWHAT:
	if ( err_val == 0 ) {
		err_val = 777;
		}
	ExFlgSgn = 0;
	tcode 	= SOFTERROR;
	continue;
	}
else	{	/* Alors Compare */
		/* ------------- */

	switch ( worktyp1 & VARB_ISOL) {
		case VARB_INT8	:
		case VARB_INT16 :
			switch ( worktyp2 & VARB_ISOL) {
				case VARB_STR : workval2 = atoi  (workptr2,worklen2); break;
				case VARB_BCD : workval2 = bcdtoi(workptr2,worklen2);
				}
			tcode = compint((tcode & 7),workval2,workval1);
			continue;
		case VARB_BCD   :
			switch ( worktyp2 & VARB_ISOL) {
				case VARB_STR   : 
					PileCheck( BCDMAX );
					atobcd(workptr2,(TcodeByteStack + worktop),BCDMAX,worklen2);
					workptr2 = (TcodeByteStack + worktop); worklen2 = BCDMAX; 
					worktop += BCDMAX; break;
				case VARB_INT8  :
				case VARB_INT16 : 
					PileCheck( BCDMAX );
			 		itobcd(workval2,(workptr2 = (TcodeByteStack + worktop)),(worklen2 = BCDMAX));
				}
#ifndef INTELASM1
			if ( compbcd((tcode & 7),workptr1,workptr2) != 0) { 
				fdex = (TcodeSegment + Tcodeword( fdex ));
				}
			else	{ fdex += WORDSIZE; }
#else
			if ( bcdcomp((tcode & 7)) != 0) { fdex = (TcodeSegment + Tcodeword( fdex )); }
			else	{ fdex += WORDSIZE; }
#endif
			tcode = 1;
			continue;
		case VARB_STR   :
			switch ( worktyp2 & VARB_ISOL) {
				case VARB_INT8	:
				case VARB_INT16 :
					PileCheck( worklen1 );
					itoa(workval2,(TcodeByteStack + worktop),worklen1);
					workptr2 = (TcodeByteStack + worktop);
					worktop += worklen1;  worktyp2 = VARB_STR; break;
				case VARB_BCD   : 
					PileCheck( 24 );
					bcdtoa(workptr2,worklen2,(TcodeByteStack + worktop),24);
					workptr2 = (TcodeByteStack + worktop); worklen2 = 24;
					worktop += 24;  worktyp2 = VARB_STR;
				}
			tcode = compstr((tcode & 7)); 
			continue;
		}
	}
	continue;

#ifndef	ABAL21

#ifdef ABALPSYS

/* READ INDIRECT REGISTER
 * ----------------------
 * ( RS[ Source ] == 0 ? RD[ dest ] = RD[ RD[ Source ] ] : RD[ dest ] = 0 )
 *
 *	RIR	Target_reg , Source_selector_register 
 */
			case _tc_RIR	:
				tcode = (EXAWORD) *(fdex++);
				e     = (EXAWORD) *(fdex++);
				if (( xreg [e] == IMMEDIAT )  && ( freg [e] < diezreg )) {
						freg [tcode] = freg [ freg [e] ];
						xreg [tcode] = IMMEDIAT;
						}
				else {	freg [tcode] = 0; xreg [tcode] = IMMEDIAT; }
				tcode = 1; break;
#endif	/* ABALPSYS 	*/
#endif	/* ABAL21 	*/

/* DECREMENT 1st INDEX of #REGISTER
 * --------------------------------
 */
				case _tc_DEX	:
					ireg [ *(fdex++) ]--; continue;
/* NEGATE [VARPTR]
 * ---------------
 */
				case _tc_NGV	:
					tcode = negwork(0,Tcodeword( fdex));
					fdex += WORDSIZE; break;



case _tc_GWS :

	balputw( (Tcodeword( (fdex) )), (GlobalDataSegment + (Tcodeword( (fdex + WORDSIZE)))));
	fdex += (2 * WORDSIZE);
	continue;

case _tc_LWS :

	balputw( (Tcodeword( (fdex) )), (LocalDataSegment + (Tcodeword( (fdex + WORDSIZE)))));
	fdex += (2 * WORDSIZE);
	continue;

#ifdef	NEVER_USED_TCODE

/*
 * LOAD Interpreted #REGISTER with CONSTANT
 * ---------------------------------------- 
 * CTR #DREG , {CONSTANT}
 */

case _tc_CTR	:

	workptr2 = (TcodeConstants + Tcodeword( fdex )); fdex += WORDSIZE;
	while (1) {
		if ((worklen2 = (EXAWORD) *(workptr2++)))
			worktyp2 = VARB_STR;			
		else if (((worklen2 = (EXAWORD) *(workptr2++)) & 0x0080)) {
			workptr2 = (GlobalConstants + Tcodeword((workptr2))); 
			continue;
			}
		else	worktyp2 = VARB_BCD;
		break;
		}
	goto ON_Y_VA;
	
/*
 * LOAD Interpreted #REGISTER with VARIABLE
 * ---------------------------------------- 
 * CTR #DREG , [VARIBALE]
 */

case _tc_VTR	:
	worktyp2 = Tcodeword( fdex ); fdex += WORDSIZE; workval2 = 0;
	if ( (tcode = varbset2()) == SOFTERROR ) { continue; }
	goto ON_Y_VA;

/*
 * STORE #REGISTER to #REGISTER
 * ----------------------------
 * Stores the interpreted contents of Register #S to the interpreted
 * contents of Register #R with automatic conversion of type
 *	RTR #S , #R
 *
 *	Remarque : On essayerai de ne pas ecraser les constantes n'est pas !
 */

case _tc_RTR	:
		switch ( xreg [(e = (EXAWORD) *(fdex++))] ) {
			case CHARONLY :
			case IMMEDIAT :
				worktyp2 = VARB_INT16;
				workval2 = (BINAIRE) freg [e]; 
				break;
			case KONSTANT :
				workptr2 = (TcodeConstants + freg [e]);
				while (1) {
					if ((worklen2 = (EXAWORD) *(workptr2++)))
						worktyp2 = VARB_STR;			
					else if (((worklen2 = (EXAWORD) *(workptr2++)) & 0x0080)) {
						workptr2 = (GlobalConstants + Tcodeword((workptr2))); 
						continue;
						}
					else	worktyp2 = VARB_BCD;
					break;
					}

				break;							
			case PTRSTR    :
				worktyp2 = VARB_STR;
				worklen2 = lreg [e];
				workptr2 = preg [e];
				break;
			case PTRBCD    :
				worktyp2= VARB_BCD;
				worklen2 = lreg [e];
				workptr2 = preg [e];
				break;
			case TEMPDESC :
				workptr2 = (TcodeByteStack + freg [ e ]);
				worktyp2 = Tcodeword( workptr2 );
				worklen2 = Tcodeword( (workptr2 + WORDSIZE) );
				workptr2 += ( 2 * WORDSIZE ); 
				break;
			case VARIABLE :
				worktyp2 = freg [ (workval2 = e) ];
				if ( (tcode = varbset2()) == SOFTERROR ) { continue; }
			}
ON_Y_VA:
		switch ( xreg [(e = (EXAWORD) *(fdex++))] ) {
			case CHARONLY :
			case IMMEDIAT :
				switch ( worktyp2 & VARB_ISOL ) {
					case VARB_INT8  :
					case VARB_INT16 : freg [e] = workval2; continue;
					case VARB_BCD   : freg [e] = bcdtoi( workptr2 , worklen2); continue;
					case VARB_STR   : freg [e] = atoi( workptr2 , worklen2 ); continue;
					default		: freg [e] = 0; continue;
					}
			case KONSTANT :
				err_val  = 56; tcode = SOFTERROR; continue; 
			case PTRSTR    :
				worktyp1 = VARB_STR;
				worklen1 = lreg [e];
				workptr1 = preg [e];
				break;
			case PTRBCD    :
				worktyp1 = VARB_BCD;
				worklen1 = lreg [e];
				workptr1 = preg [e];
				break;
			case TEMPDESC :
				workptr1 = (TcodeByteStack + freg [ e ]);
				worktyp1 = Tcodeword( workptr1 );
				worklen1 = Tcodeword( (workptr1 + WORDSIZE) );
				workptr1 += ( 2 * WORDSIZE ); 
				break;
			case VARIABLE :
				worktyp1 = freg [(workval1 = e)]; 
				if ((tcode = varbsetw( )) == SOFTERROR ) { continue; }
			}
		VarbXfer(1);

#endif

/* STORE #REGISTER to [VARPTR]
 * ---------------------------
 * Stores the result of evaluation of the contents of #REGISTER to
 * the variable pointed to by [VARPTR]
 */
case _tc_STR	:
	
	switch ( xreg [(e = (EXAWORD) *(fdex++))] ) {
		case CHARONLY :
		case IMMEDIAT :
			e = freg [e]; goto ITOVARB;
		case VARIABLE : 
			tcode = varcpy(freg [e],Tcodeword( fdex),e,0);
			fdex += WORDSIZE;
			break;	
		case PTRSTR   :
			workptr2 = preg [e]; worklen2 = lreg [e];
			worktyp2 = VARB_STR; 
			worktyp1 = Tcodeword( fdex ); fdex += WORDSIZE;
			workval1 = 0;
			if ((tcode = varbsetw()) != SOFTERROR) { VarbXfer(1); }
			continue;
		case PTRBCD   :
			workptr2 = preg [e]; worklen2 = lreg [e];
			worktyp2 = VARB_BCD; 
			worktyp1 = Tcodeword( fdex ); fdex += WORDSIZE;
			workval1 = 0;
			if ((tcode = varbsetw()) != SOFTERROR) { VarbXfer(1); }
			continue;
		case TEMPDESC :
			workptr2 = (TcodeByteStack + freg [e]);
			worktyp2 = Tcodeword( workptr2 );
			worklen2 = Tcodeword( (workptr2 + WORDSIZE) );
			workptr2 += (2 * WORDSIZE); 
			worktyp1 = Tcodeword( fdex ); fdex += WORDSIZE;
			workval1 = 0;
			if ((tcode = varbsetw()) != SOFTERROR) { VarbXfer(1); }
			continue;
		}
		break;

EXVRBCNV:

	/*       Destination  H  : Source    L      	*/
	/*	----------------  -------------		*/
	switch ( (worktyp1 << 4) | worktyp2 )	{
		case 0x0000 :   *workptr1 = (EXABYTE) workval2; break;
		case 0x0001 :	*workptr1 = (EXABYTE) workval2; break;
		case 0x0002 :   *workptr1 = (EXABYTE) bcdtoi(workptr2,worklen2);
				break;
		case 0x0003 :	*workptr1 = (EXABYTE) atoi(workptr2,worklen2);
				break;
		case 0x0010 :	
		case 0x0011 :	balputw((EXAWORD) workval2,workptr1); break;
		case 0x0012 :	balputw((EXAWORD) bcdtoi(workptr2,worklen2),workptr1);
				break;
		case 0x0013 :	balputw((EXAWORD) atoi(workptr2,worklen2),workptr1);
				break;
		case 0x0020 :	
		case 0x0021 :	tcode = itobcd(workval2,workptr1,worklen1); break;
		case 0x0022 :	

			e = 0; err_val = ABAL_NUM2BIG; 
			if ( worklen1 < worklen2 ) { workptr2 = (BPTR) Squeeze(workptr2,worklen2); }
			while ((worklen1 > 0) && (worklen2 > 0)) {
				if ( e == 0 ) {
					switch ( *workptr2 & 0x00F0 ) {
						case 0x00A0 :
						case 0x00F0 : e = 1;
						}
					switch ( *workptr2 & 0x000F ) {
						case 0x000A :
						case 0x000F : e = 1;
						}
					}
				*(workptr1++) = *(workptr2++);
				worklen1--; worklen2--;
				}
			while ( worklen1 > 0 ) { *(workptr1++) = (EXABYTE) 0x00FF; worklen1--; }
			if ( worklen2 == 0 ) 	{ tcode = 1; break; }
			else			{ 
				if ((e != 0 ) || (( *workptr2 & 0x00F0 ) > 0x0090 ))  { tcode = 1; break; }
				else { tcode = e; }
				}	
			break;
		case 0x0023 : tcode = atobcd(workptr2,workptr1,worklen1,worklen2); break;
		case 0x0030 :	
		case 0x0031 : if ( e == 1 ) {
				PileCheck( 12 );
				workptr3 = (TcodeByteStack + worktop);
				worktop += 12;
				itoa(workval2,workptr3,12);
				tcode = str0fill();
				}
			      else { itoa(workval2,workptr1,worklen1); tcode = 1; }
			      break;
		case 0x0032 : if ( e == 1 ) {
				PileCheck( worklen1 );
				workptr3 = (TcodeByteStack + worktop);
				worktop += worklen1;
				bcdtoa(workptr2,worklen2,workptr3,worklen1);
				tcode = str0fill();
				}
			      else { bcdtoa(workptr2,worklen2,workptr1,worklen1); 
				     (VOID) numclean();
				     tcode = 1;
				     }
				break;
		case 0x0033 :	xmemcpy(0x0020); break;
		default	    :	tcode = SOFTERROR; err_val = 444; continue;
		}
	break;

#ifdef ABALPSYS
/* DECREMENT STACK POINTER
 * -----------------------
 * Performs decrementation of the Gosubs / Returns Stack pointer to lose
 * the last return adresse
 */ 
		case _tc_DSP	: ip_next--; continue;
#endif

/* WHEN <Event condition>
 * ----------------------
 * Declaration and management of Event conditions and operations.
 * (EVENT conditions are local to Segments and procedures, they are stacked 
 * wrt code unit due to LDGO.SEG and CALL and destacked by RET.SEG and EXIT
 *
 *	WHN	Eventcode [,&etiquette_d'evenment]
 */
case _tc_WHN	: 
	switch ((tcode = (EXAWORD) *(fdex++))) {
		case _ec_STOP:  ip_next--;
		case _ec_RAZ :	timersem &= EVENT_SEMOFF; 
				tcode = 1;
				continue;
		case _ec_DCL :	eventadr  = Tcodeword( fdex ); 
				fdex += WORDSIZE;
				if ( (timersem & EVENT_EXIST) == 0) {
					timersem &= EVENT_SEMOFF;
					timersem |= EVENT_SEMON;
					}
				continue;
		case _ec_START: if ((timersem & EVENT_EXIST ) == 0) {
					timersem &= EVENT_SEMOFF;
					fdex = (TcodeSegment + ip_hold [--ip_next]) - 1;
					continue;
					}
				timersem &= EVENT_SEMOFF;
				timersem |= EVENT_ACTIF;
		case _ec_FAUX : timersem |= EVENT_OVER;
				fdex = (TcodeSegment + ip_hold [--ip_next]) - 1;
				continue;
		case _ec_HALT : timersem |= EVENT_EXIST;
				continue;

		default	      : 
#ifdef	ABAL21
				if ( tcode & _ec_EXTERN ) {
					switch ((tcode & 0x003F)) {
						case _ec_POP   :
						case _ec_CALLI :
						case _ec_CALLV :
						case _ec_GOTO  :
						case _ec_GOSUB : activate_external_event( tcode, (Tcodeword((fdex))));
								 if ((tcode & 0x003F) != _ec_POP)	fdex += WORDSIZE;
								 continue;
						
						case _ec_RAZ   : disactivate_external_event();
								 continue;

						default        :
							tcode = SOFTERROR; 
							err_val = 56;
						}
					continue;
					}
#endif
				tcode = SOFTERROR; err_val = 56;
				continue;
		}

#ifdef ABALPSYS
/* WRITE INDIRECT REGISTER
 * -----------------------
 * Allows a register to be selected by value in a register as the target
 * for a Transfer between registers
 *
 *	WIR	Target_selector_reg , Source_register 
 */
			case _tc_WIR	:
				e = (EXAWORD) *(fdex++);
				tcode     = (EXAWORD) *(fdex++);
				if (( xreg [e] == IMMEDIAT )  && ( freg [e] < diezreg )) {
						e = freg [e];
						freg [e] = freg [tcode];
						xreg [e] = IMMEDIAT;
						}
				tcode = 1; break;
#endif


/*----------------------------------------------------------------------------*/
/* Remarque : La fin du SWITCH CASE se trouve dans le fichier niveau MOINS_UN */
/*----------------------------------------------------------------------------*/
