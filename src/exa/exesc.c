/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1996 Amenesik / Sologic S.A.		*/
/*									*/
/*		Module  :	EXESC - C				*/
/*		Version :	2.1d					*/
/*		Date 	:	08/07/1998				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	Extended tcodes for Speed optimisations				*/
/*----------------------------------------------------------------------*/


switch ( *(fdex++)  ) 
{


/* ESC from motor loop
 * -------------------
 * This T-Code allows return to the IO execution loop
 *
 */

case	_tc_ESC	:
	/* YT080798 :	Correction du plantage en sortie d'une edition
						d'un rapport Report Maker.
						On remet err_val a 0	
	 */

	err_val = 0;

	if ( ExQui != 0 ) { return(0); }
	err_val = 56; tcode = SOFTERROR; 
	continue;

case (_tc_OEV | 0x80) :
	tcode = (EXAWORD) *(fdex++); 
	tcode = trapgest(tcode,Tcodeword(fdex),tcode,4);
	fdex += WORDSIZE;
	break;
	
case (_tc_OLE | 0x80) :
	tcode = (EXAWORD) *(fdex++); 
	tcode = trapgest(tcode,Tcodeword(fdex),tcode,8);
	fdex += WORDSIZE;
	break;

/* PAUSE IVALUE
 * ------------ 
 * Display the IVALUE and await carraige return validation.
 */
case _tc_PSI	:

/* PAUSE {CONPTR}
 * --------------
 * Displays the constant pointed to by {CONPTR} and awaits the validation
 * by a carriage return.
 */ 
case _tc_PSC	:

/* PAUSE [VARPTR]
 * --------------
 * Displays the variable pointed by [VARPTR] and awaits validation
 * carriage return.
 */
case _tc_PSV	:

/* PAUSE #REGISTER
 * ---------------
 * Displays the result of register #REGISTER and awaits validation
 * via carriage return.
 */
case _tc_PSR	:
	tcode = f_pause((EXAWORD) *(fdex - 1)); continue;

/* CALL SEGMENT IVALUE
 * -------------------
 * Transfers control to the segment indicated by IVALUE
 * N.B.	: IVALUE is an 8 bit unsigned integer !
 */

case	_tc_SGI	:
	if (!( timersem & TIME_CALL ))
		(void) raz_timer();
	e = (EXAWORD) *(fdex++);
#ifdef DEBUGGER
	SegmentTrapWork(0);
#endif
	tcode = ldgo_seg(e,(fdex - TcodeSegment));
#ifdef	DEBUGGER
	SegmentTrapWork(1);
#endif
	fdex = TcodeSegment; continue;

#ifdef	ABAL21
case	_Esc_SGW	:
	if (!( timersem & TIME_CALL ))
		(void) raz_timer();
	e = (EXAWORD) Tcodeword( (fdex) ); 
	fdex += WORDSIZE;
#ifdef DEBUGGER
	SegmentTrapWork(0);
#endif
	tcode = ldgo_seg(e,(fdex - TcodeSegment));
#ifdef	DEBUGGER
	SegmentTrapWork(1);
#endif
	fdex = TcodeSegment; continue;

#endif	/* ABAL21 */
	/* ------ */

/* CALL SEGMENT #REGISTER
 * ----------------------
 * This transfers control to the segment indicated by the contents
 * of the register #REGISTER.
 */
case _tc_SGR	:
	if (!( timersem & TIME_CALL ))
		(void) raz_timer();
	e = (EXAWORD) *(fdex++);
#ifdef DEBUGGER
	SegmentTrapWork(0);
#endif
	tcode = ldgo_seg(freg [e],(fdex - TcodeSegment));
#ifdef DEBUGGER
	SegmentTrapWork(1);
#endif
	fdex = TcodeSegment; continue;

/* CALL SEGMENT [VARPTR]
 * ---------------------
 * Transfers control to the segment indicated by the integer value
 * of the variable pointed to by [VARPTR].
 */
case _tc_SGV	:
	if (!( timersem & TIME_CALL ))
		(void) raz_timer();
	e = valvar(Tcodeword( fdex),0);
	fdex += WORDSIZE;
#ifdef DEBUGGER
	SegmentTrapWork(0);
#endif
	tcode = ldgo_seg(e,(fdex - TcodeSegment));
#ifdef DEBUGGER
	SegmentTrapWork(1);
#endif
	fdex = TcodeSegment; continue;

/* CALL PROCEDURE (ARGLIST)
 * ------------------------
 * Transfers control to the procedure and passes the values of the
 * arguaments in ARGLIST.
 */
case _tc_CLP	:
	if (!( timersem & TIME_CALL ))
		(void) raz_timer(); 
#ifdef WEXADBDLL
	if (StepIntoMode)
		StepIntoTrapWork();
#endif
	tcode = call_procedure();
	break;

/* EXIT
 * ----
 * Causes the return from the current procedure to the segment or
 * procedure precedant with transmission of results if required.
 */

case _tc_RTP	:
	if (!( timersem & TIME_CALL ))
		(void) raz_timer(); 
	tcode = procedure_exit(_tc_RTP);
#ifdef WEXADBDLL
	StepOverTrapWork(1); 
#endif
	break;

#ifdef	ABAL21

/* END.PROC */
/* -------- */
case _Esc_ETP	:
	if (!( timersem & TIME_CALL ))
		(void) raz_timer(); 
	tcode = procedure_exit(_Esc_ETP);
	break;

/* LEAVE with ERROR
 * ----------------
 * Unstacks all Nested Procedures and or Segments until an a code block,
 * either Procedural or Segmental, is encountered with an active error 
 * trapping mechanism. If Ne Error Trap is found then the error value
 * Provided is display as a standard ABAL error message. Otherwise the
 * Error Reception Variable is updated the Error Trap is Activated.
 */

case _Esc_RTI	:
case _Esc_RTV	:
case _Esc_RTR	:
	fdex--; 
	if (!( timersem & TIME_CALL ))
		(void) raz_timer(); 
	tcode = f_rte( *(fdex++) ); 
	break;

#endif

/* STOP
 * ----
 * End of execution of the current T-Code file program
 * with eventual CHAIN operation to the next T-Code file.
 */ 

case _tc_STP	:
		(void) raz_timer(); 
      err_val = 0; 
      tcode = exstop(); 
			continue;

/* RETURN SEGMENT	END SEGMENT
 * --------------	-----------
 * Returns control to the execution of the preceeding segment and 
 * re-establishes all control values for that segment.
 * (may liberate resident or public zones (ETS))
 */
case _tc_ETS    :
case _tc_RTS	:
	if ( mindex == 0) { err_val = ABAL_RETNOGSB; tcode = SOFTERROR; }
	else	{
		if (!( timersem & TIME_CALL ))
			(void) raz_timer();
		tcode = setdtcur(cur_seg);
		if (tcode != 0) {
#ifdef DEBUGGER
			SegmentTrapWork(0);
#endif
			tcode = ret_seg( ((*(fdex - 1))  & 1) );	
#ifdef DEBUGGER
			SegmentTrapWork(1);
#endif
			}
		}
	continue;

#ifdef	ABAL21

case _tc_ERA	:	/* ESC _tcRGT  */
	fdex = (BPTR) (TcodeSegment + freg[ *(fdex++) ]);
	tcode = GOODRESULT;
	continue;

case _tc_NGR	:	/* ESC _tc_RGS */
	if (ip_next >= diezstk) { 
		err_val = ABAL_GSB2MANY; 
		tcode = SOFTERROR; 
		}
	else	{
		ip_hold [ (ip_next++) ] = (EXAWORD) (fdex + 1 - TcodeSegment); 
		fdex = (BPTR) (TcodeSegment + freg[ *(fdex++) ]);
		tcode = GOODRESULT;
		}
	continue;

#endif


/*	JUMP with respect to Register Value
 *	-----------------------------------
 *	ESC JMR ( #reg , %maxval , &etiq1 , .... , &etiqmax )
 *	
 *	The Jump Will be ignored if the register evaluates to Zero
 *	or a value greater than %maxval, Otherwise the Label will be
 *	selected from the ordered table for the jump Destination adresse
 */

case _tc_JMR	:
	tcode = freg [ ((EXAWORD) *fdex) ];
	/* If Value is not Zero and Less or Equal to Table Limits */
	/* ------------------------------------------------------ */
	if (( tcode != 0 ) && ( tcode <= Tcodeword((fdex + 1)) )) {
		fdex = (BPTR) ( TcodeSegment + Tcodeword( (fdex + 1 + (tcode * WORDSIZE)) ) );
		}
	else	{
		fdex += (((Tcodeword((fdex + 1)) + 1) * WORDSIZE) + 1 );
		}
	tcode = 1; continue;

/*	GOSUB with respect to Register Value
 *	------------------------------------
 *	ESC GSR ( #reg , %maxval , &etiq1 , .... , &etiqmax )
 *	
 *	The Gosub Will be ignored if the register evaluates to Zero
 *	or a value greater than %maxval, Otherwise the Label will be
 *	selected from the ordered table for the jump Destination adresse
 *	the return adresse will be the next instruction (as for other Values)
 */

case _tc_GSR	:
	if (ip_next >= diezstk) { err_val = ABAL_GSB2MANY; tcode = SOFTERROR; }
	else	{

		tcode = freg [ ((EXAWORD) *fdex) ];
		/* If Value is not Zero and Less or Equal to Table Limits */
		/* ------------------------------------------------------ */
		if (( tcode != 0 ) && ( tcode <= Tcodeword((fdex + 1)) )) {
			ip_hold [ (ip_next++) ] = (EXAWORD) ((fdex - TcodeSegment) + (((Tcodeword((fdex + 1)) + 1) * WORDSIZE) + 1 ));
			fdex = (BPTR) ( TcodeSegment + Tcodeword( (fdex + 1 + (tcode * WORDSIZE)) ) );
			}
		else	{
			fdex += (((Tcodeword((fdex + 1)) + 1) * WORDSIZE) + 1 );
			}
		
		tcode = 1; 
		}
	continue;

#ifdef	ABAL32A

case _Esc_SPAWN    :	/* Generation of Parallel Process */
			/* ------------------------------ */

	tcode = TcodeSpawn(); break;

case _Esc_LIBER	   :	/* Liberation of Parallel Process */
			/* ------------------------------ */

	tcode = SpawnExit(); break;

#endif	/* ABAL16 */
	/* ------ */

#ifdef	VERSION666
#ifdef	_tc_SGL
case _tc_SGL :
	balputl( (Tcodeword( (fdex) )), (GlobalDataSegment + (Tcodeword( (fdex + WORDSIZE)))));
	fdex += (2 * WORDSIZE);
	tcode=1; break;
#endif
#ifdef	_tc_SLL
case _tc_SLL :
	balputl( (Tcodeword( (fdex) )), (LocalDataSegment + (Tcodeword( (fdex + WORDSIZE)))));
	fdex += (2 * WORDSIZE);
	tcode=1; break;
#endif
#ifdef	_tc_GLS
case _tc_GLS	: 
	balputl( freg [ *fdex ] , (GlobalDataSegment + (Tcodeword( (fdex + 1)))));
	fdex += (WORDSIZE + 1); tcode=1; break;
#endif
#ifdef	_tc_LLS
case _tc_LLS	: 
	balputl( freg [ *fdex ] , (LocalDataSegment + (Tcodeword( (fdex + 1)))));
	fdex += (WORDSIZE + 1); tcode=1; break;
#endif
#ifdef	_tc_GLL
case _tc_GLL	:	/* Load Global Long */
	freg [ (e = *fdex) ] = balgetl( ( GlobalDataSegment + (Tcodeword( (fdex + 1) ) ) ));
	xreg [e] = IMMEDIAT;
	fdex += (WORDSIZE + 1); tcode=1; break;
#endif
#ifdef	_tc_LLL
case _tc_LLL	:	/* Load Local Long */
	freg [ (e = *fdex) ] = balgetl( ( LocalDataSegment + (Tcodeword( (fdex + 1)) ) ));
	xreg [e] = IMMEDIAT;
	fdex += (WORDSIZE + 1); tcode=1; break;
#endif
#ifdef	_tc_SGH
case _tc_SGH :
	balput64( (Tcodeword( (fdex) )), (GlobalDataSegment + (Tcodeword( (fdex + WORDSIZE)))));
	fdex += (2 * WORDSIZE);
	tcode=1; break;
#endif
#ifdef	_tc_SLH
case _tc_SLH :
	balput64( (Tcodeword( (fdex) )), (LocalDataSegment + (Tcodeword( (fdex + WORDSIZE)))));
	fdex += (2 * WORDSIZE);
	tcode=1; break;
#endif
#ifdef	_tc_GHS
case _tc_GHS	: 
	balput64( freg [ *fdex ] , (GlobalDataSegment + (Tcodeword( (fdex + 1)))));
	fdex += (WORDSIZE + 1); tcode=1; break;
#endif
#ifdef	_tc_LHS
case _tc_LHS	: 
	balput64( freg [ *fdex ] , (LocalDataSegment + (Tcodeword( (fdex + 1)))));
	fdex += (WORDSIZE + 1); tcode=1; break;
#endif
#ifdef	_tc_GHL
case _tc_GHL	:	/* Load Global Long */
	freg [ (e = *fdex) ] = balget64( ( GlobalDataSegment + (Tcodeword( (fdex + 1) ) ) ));
	xreg [e] = IMMEDIAT;
	fdex += (WORDSIZE + 1); tcode=1; break;
#endif
#ifdef	_tc_LHL
case _tc_LHL	:	/* Load Local Long */
	freg [ (e = *fdex) ] = balget64( ( LocalDataSegment + (Tcodeword( (fdex + 1)) ) ));
	xreg [e] = IMMEDIAT;
	fdex += (WORDSIZE + 1); tcode=1; break;
#endif
#endif	/* VERSION666 */

default		: err_val = 56; continue;

}
break;

