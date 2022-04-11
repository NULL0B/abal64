#ifndef	_EXCLF14_C
#define	_EXCLF14_C

EXAWORD f_clfe(x)
EXAWORD x;
{
	EXAWORD	desc,descx,fflg;
	EXABYTE	c;
	EXAWORD	work1,leng1,work2,leng2,work3,leng3,opr1,opr2,opr3;
	EXAWORD	reg1,reg2,reg3;

	 
	if ( ((desc = (EXAWORD) *(fdex++)) & 1) != 0) 
		descx = (EXAWORD) *(fdex++);

	if (( desc & 0x0060 ) != 0x0060 ) {
		if (argsetw(((desc & 0x0060) >> 5),0) == SOFTERROR) 
			return(SOFTERROR);
		if (argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR) 
			return(SOFTERROR);
		}
	else 	{
		reg1 = (EXAWORD) *(fdex++); 
		if (argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR) 
			return(SOFTERROR); 
		worktyp1 = VARB_BCD; worklen1 = 12;
		if (argsetw(6,reg1) == SOFTERROR) 
			return(SOFTERROR);
		}
	if (worktyp2 < VARB_BCD) { 
		StackCheck( BCDMAX );
		workptr2 = (TcodeByteStack + worktop);
		worktyp2 = VARB_BCD;
		worktop += BCDMAX;
		itobcd(workval2,workptr2,BCDMAX);
		worklen2 = BCDMAX;
		}

	if (( desc & 1) != 0) {
		if (argset(((descx & 0x0060) >> 5),0,3) == SOFTERROR) 
			return(SOFTERROR);
		if ( worktyp3 == VARB_BCD ) 
			workval3 = bcdtoi(workptr3,worklen3);
		}
	else	{ 
		worktyp3 = VARB_INT16; 
		workval3 = 0; 
		}

	switch ( x ) {	/* Select BCD Function */

	case	0 :		/* A=FIX(B,N) 	*/
				/* ----------	*/

		  if ( workval3 < 0 ) { 
			err_val = ABAL_BCD2LONG; 
			return(SOFTERROR);
			}

		  return(bcdfix(workptr2,workptr1,worklen2,worklen1,workval3,(desc & 1)));

	case	1 :		/* A=ROUN(B,N)	*/
				/* -----------	*/

		  if ( workval3 < 0 ) 
			workval3 = 0;

		  opr1 = bcdarr(workptr2,workptr1,worklen2,worklen1,workval3); 
		  break;

	case	2 :		/* A=FPT(B)	*/
				/* --------	*/

		  opr1 = bcddec(workptr2,workptr1,worklen2,worklen1); 
		  break;

	case	3 :		/* A=INT(B)	*/
				/* --------	*/
		  opr1 = bcdint(workptr2,workptr1,worklen2,worklen1); 
		  break;

	case	4 :		/* A=VAL(B,N)	*/
				/* ----------   */
		  workval3--; 
		  workptr2 += workval3;
		  atobcd(workptr2,workptr1,worklen1,(worklen2 - workval3)); 
		  break;

	case    5 :		/* A = STDFORM(B) */ 
				/* -------------- */

		return( bcd2std(workptr2,worklen2,workptr1,worklen1) );

	case    6 : 		/* A = REAL(B,Pow%) */
				/* ---------------- */

		return( std2bcd(workptr2,worklen2,workptr1,worklen1,workval3) );

	case 	7 :		/* A$= STRN(B)  */
				/* -----------  */
		/* Check for BackPatch of TempDesc Needed */
		/* -------------------------------------- */
		if (( desc & 0x0060 ) != 0x0060 )
			return(bcdtoa(workptr2,worklen2,workptr1,worklen1));

		TcodePmot( (workptr1 - (2 * WORDSIZE)) , VARB_STR );
		worktop += ( 24 - worklen1 );
		(VOID) bcdtoa(workptr2,worklen2,workptr1,24);
		worklen1 = lenuze(workptr1,24);
		TcodePmot( (workptr1 - WORDSIZE) , worklen1 );
		return(1);
	
	case	8 : 		/* A$= EXALONG(B)	*/
				/* -----------  */
		*((LPTR) workptr1) = bcdtol(workptr2,worklen2); 
		return(1);

	default	  : 

		err_val = EXER_FUNCWOT; 
		return(SOFTERROR);

		}
	opr1++;
	return(1);
}

	/* ---------- */
#endif 	/* _EXCLF14_C */
	/* ---------- */

