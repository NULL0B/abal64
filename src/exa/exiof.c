/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXIOF.C   				*/
/*		Date 	:	24/03/1997				*/
/*		Version :	1.4c / 2.1d				*/
/*									*/
/*----------------------------------------------------------------------*/

/* Mises a jour :
 * ------------
 * 16/07/01 : (#BG) EXA-84: Support intégral du caractère Euro. (WIN32 only)
 *
 */

#ifndef	_EXIOF_C
#define	_EXIOF_C

#include	"exio.h"
#include 	"exiof.h"
#include	"exhotkey.h"

EXAWORD	ExaCriticalSection;	/* 28/08/1998 : flag exec section critique */

#ifdef UNIXWARE2
#include <signal.h>
#endif

EXAWORD sf_atb(tcode)
EXAWORD tcode;
{
	if ( argset(((tcode & 0x00E0) >> 5),0,1) == SOFTERROR ) 
		return( SOFTERROR );
	else	return( iof_atb( workval1 ) );
}

/* 
 *	S F _ F M T ( fx )
 *	------------------
 *
 *	- Etablir une pointeur vers une chaine de FORMAT
 *	
 */

EXAWORD sf_fmt(fx)
EXAWORD	fx;
{
	EXAWORD	fstrl;
	EXAWORD	lerror;

	/* Check for Immediate tcode format */
	/* -------------------------------- */ 
	if ( (fx = ((fx & 0x00E0) >> 5)) > 3 ) { 

		/* Establish current format string */
		/* ------------------------------- */
		lerror = iof_format_string((BPTR) ( fdex + 1 ),(EXAWORD) (fstrl = *fdex) );

		/* Adjust tcode pointer and return result */
		/* -------------------------------------- */
		fdex += (fstrl+1); return( lerror );
		}
	else 	{

		/* Format submitted by standard Tcode argument */
		/* ------------------------------------------- */
		fx &= 0x0003;
		ExFlgSgn = 1;
		if ( argset(fx,0,1) == SOFTERROR ) {
			ExFlgSgn = 0;
			return(SOFTERROR);
			}
		ExFlgSgn = 0;

		switch ( worktyp1 ) {	

			case VARB_BCD   : 
				workval1 = bcdtoi(workptr1,worklen1); 
				fx = 2;
	
			case VARB_FOUR  :
			case VARB_INT8  :
			case VARB_INT16 : 
			case VARB_INT32 : 
			case VARB_INT64 : 
				/* Check for dynamic substitution value */
				/* ------------------------------------ */
				if ( fx >= 2 )
					return( iof_format_value((EXAWORD) workval1));

				/* Integer is tcode segment offset */
				/* ------------------------------- */
				workptr1 = (TcodeSegment + (EXAWORD) workval1); 
				workptr1++; /* Due to Format length 1st Byte */

			case VARB_STR   : 

				return( iof_format_string( workptr1, 0 ) );

			default		:
				err_val = 115;
				return( SOFTERROR );
			}
		}


}

/* 
 *	S F _ P A I N T ( fx )
 *	----------------------
 *
 *	IOF colour functions
 *
 */

EXAWORD sf_paint(fx)
EXAWORD fx;
{
register EXAWORD fy;
	fy = fx & 0x001F;
	if (argset(((fx & 0x00E0) >> 5),0,1) == SOFTERROR)
		return(SOFTERROR);
	switch ( worktyp1 ) 
	{
	case	VARB_STR	:
#ifdef	ABAL64
		if ( fy == 8 ) 
			iof_ebackgr(workptr1,worklen1);
		else	iof_eforegr(workptr1,worklen1);
		return(GOODRESULT);
#else
		workval1 = exatoi(workptr1,worklen1); 
		break;
#endif
	case	VARB_BCD	:
		workval1 = bcdtoi(workptr1,worklen1); 
		break;
	}

/* On n'imprime les couleurs que sous windows */
#ifndef WIN1632	
	if ( prndest < 2 ) 
	{
#endif
		if ( fy == 8 ) 
			iof_backgr((workval1 & BackGroundMask));
		else	iof_foregr((workval1 & ForeGroundMask));
#ifndef WIN1632	
	}
#endif
	return(GOODRESULT);
}

/*
 *	S F _ D E V ( fx )
 *	------------------
 *
 *	IOF device select routine
 *	-------------------------
 *	1 = Console, 2 = Printer, Variable$  => A=PRINT(.....)
 *	other values directed to file handle value.
 *
 */

EXAWORD sf_dev(fx)
EXAWORD fx;
{
	EXAWORD	r;
	EXAWORD	ir;
	EXAWORD	ar;
	if (( fx & 0x00E0) == 0x0060) 
	{
		r  = (EXAWORD) *(fdex++);
		switch ( xreg[r] ) 
		{
		case	VARIABLE	:
			if ( argsetx( freg[r], r ) == SOFTERROR )
				return( SOFTERROR );
			else	break;
		default			:
			if ( argset1( r , 0 ) == SOFTERROR )
				return(SOFTERROR);
			else	break;
		}
	}
	else if ( argsetw( (fx & 0x00E0) >> 5 , 0 ) == SOFTERROR ) 
		return(SOFTERROR);

	switch ( worktyp1 ) 
	{
	case VARB_FOUR  : 
	case VARB_INT8  :
	case VARB_INT16 :
	case VARB_INT32 : 
	case VARB_INT64 : 
		return( iof_device( workval1 ) );

	case VARB_BCD   :
		return( iof_device( ((EXAWORD) bcdtoi(workptr1,worklen1))));

	case VARB_STR   :

		if ( extwrite == 1 ) 
		{
			if (( extv_base = (struct extvform PTR) allocate( sizeof(struct extvform))) == (struct extvform PTR) 0 ) 
			{
				err_val = 114; 
				return(SOFTERROR); 
			}
			sicico |= ONSEM_XVRB; 
			(*extv_base).descw = descptrw;
			(*extv_base).typew = worktypw;
			(*extv_base).keepw = workeepw;
			(*extv_base).lengw = worklenw;
			(*extv_base).wptrw = workptrw;
			extwrite = 0;
		}
		else 	sicico &= OFSEM_XVRB; 
		return( iof_device_buffer( workptr1, worklen1 ) );

	default 	  : 	return(SOFTERROR);
	}
}


/* 
 *	I N I T _ S A U T ( fx , how )
 *	------------------------------
 *
 *	Insertion d'un Regle de debranchement UTILISATEUR dans la table
 *	des descripteurs de debranchement.
 *
 *	Types :		"Bonjour" = &ettiq
 *			/0D	  = &ettiq
 *			A 	  = &ettiq etc....
 *
 */

EXAWORD 	sf_hotkey(fx,goto_gosub)
EXAWORD 	fx;
EXAWORD	goto_gosub;
{
	ExFlgSgn = 1;
	if ( argset(((fx & 0x00E0) >> 5),0,1) == SOFTERROR ) 
		return(SOFTERROR);
	fx = Tcodeword( fdex); 
	fdex += WORDSIZE;
	ExFlgSgn = 0;

	switch ( worktyp1 ) {

		case  VARB_INT8  : 
		case  VARB_INT16 : 
		case  VARB_FOUR  : 
		case  VARB_INT32 : 
		case  VARB_INT64 : 
			if ( goto_gosub != 0 )
				iof_gosub_num_hotkey( workval1, fx );
			else    iof_goto_num_hotkey( workval1, fx );
			return( GOODRESULT );

		/* Chaine de caracteres (Unique) */
		/* ----------------------------- */
		case  VARB_STR   : 

			if ( goto_gosub != 0 )
				iof_gosub_hotkeys( workptr1, worklen1, fx );
			else 	iof_goto_hotkeys( workptr1, worklen1, fx );
			return( GOODRESULT );

		}

	/* Incorrect Tcode HotKey */
	/* ---------------------- */
	return(SOFTERROR);

}

/*
 *	WORKSET 2 :	variable or expressionto check
 *	WORKSET 3 :	format string, ascii or binary
 *	RESULT  integer	ZERO : false, other : true
 *
 */

EXAWORD	sf_check_format()
{
	EXAWORD	  asklen=0;
	EXAWORD	 i;
	EXAWORD	 x;
	err_val = 0;

	/* Establish Default Result Length (without Format) */
	/* ------------------------------------------------ */
	switch ( worktyp2 ) {

		case VARB_FOUR  : 
		case VARB_INT8  : (VOID) itoa(workval2,(BPTR) askbuf, ((asklen = 4))); break;
		case VARB_INT32 : (VOID) ltoa(workval2,(BPTR) askbuf, ((asklen =24))); break;
		case VARB_INT64 : (VOID) ltoa(workval2,(BPTR) askbuf, ((asklen =48))); break;
		case VARB_INT16 : (VOID) itoa(workval2,(BPTR) askbuf, ((asklen = 6))); break;
		case VARB_BCD   : (VOID) bcdtoa(workptr2,worklen2,(BPTR) askbuf, ((asklen = (worklen2 * 2))) ); break;
		case VARB_STR   : 

			/* Limit To Maximum ASKBUF length */
			/* ------------------------------ */
			 if (( asklen = worklen2 ) > ASKBUFMAX )
				asklen = ASKBUFMAX; 
			 memcpy((BPTR)askbuf,workptr2,asklen); 
			 break;
		default :
			err_val = 108;
			 return(SOFTERROR);
		}
	for ( x=0,i=0; i < asklen; i++ ) {	
		if (!( askbuf[i] ))
			break;
		else if ( askbuf[i] != ' ' )
			x = (i+1);
		}
	asklen = x;
	askbuf[x++] = 0;
	return( iof_check_format( asklen, workptr3,worklen3 ) );

}

EXAWORD sf_ask(sfx)
EXAWORD	sfx;
{
	EXAWORD	askholder;
	EXAWORD	lowlevelret;
	EXAWORD	LockStatus;
	EXAWORD	p,asklen;
	BPTR	d;

	askaction = 0;

	if ( askmask & MASK_ACTIV_EDIT_KEYS)
	{
		if ((askholder = set_preferentiel()) != MOINS_UN)
			askaction = 1;

		/* Ceci empeche le pre-affichage par ASKCOLOUR */ 
		if (!( askmask & MASK_DONOT_PRINT ))
		{
			/* Check if Auto Ask Action Required */
			/* --------------------------------- */
			if ( askaction != 0 )
			{
				AskDynamic      = dynadex;
				AskActionFdex 	= fdex;
				AskActionFormat	= fmtptr;
				AskActionFlag   = fmtflg;
				actioncol = AskInfos(XCOL);
				actionlin = AskInfos(XLIN);
				(void) sf_print( sfx );
				fdex   = AskActionFdex;
				fmtptr = AskActionFormat;
				fmtflg = AskActionFlag;
				dynadex = AskDynamic;
				pos( actionlin, actioncol );
			}
		}
	}

	/* Evaluate ASK result arguament WORKSET1 */
	/* -------------------------------------- */
	/* Check for Register type Arguament	  */
	/* ---------------------------------	  */
	if ( (sfx & 0x0060) == 0x0060)
	{
		/* Evaluate Register correctly	*/
		/* ---------------------------  */
		p = (EXAWORD) *(fdex++); 
		if (argsetw(4,p) == SOFTERROR)
		{
			/* Error Due to Arg Analysis */
			/* ------------------------- */
			return(SOFTERROR);
		}
	}
	else
	{
		/* Analysis of Arguament */
		/* --------------------- */
	 	if (argsetw(((sfx & 0x00E0) >> 5),0) == SOFTERROR)
		{
			/* Analysis Error */
			/* -------------- */
			return(SOFTERROR); 
		} 
	}

	/* Unlock Variable if its Locked */
	/* ----------------------------- */
	if ((LockStatus = SemaFlag) != 0)
	{
		(VOID) Semaphoff(0);
	}

	/* Establish Default Result Length (without Format) */
	/* ------------------------------------------------ */
	switch ( worktyp1 )
	{
	case  VARB_FOUR  : 
	case VARB_INT8  : (VOID) itoa(workval1,(BPTR) askbuf, ((asklen = 4))); break;
	case VARB_INT32 : (VOID) ltoa(workval1,(BPTR) askbuf, ((asklen =24))); break;
	case VARB_INT64 : (VOID) htoa(workval1,(BPTR) askbuf, ((asklen =48))); break;
	case VARB_INT16 : (VOID) itoa(workval1,(BPTR) askbuf, ((asklen = 6))); break;
	case VARB_BCD   : (VOID) bcdtoa(workptr1,worklen1,(BPTR) askbuf, ((asklen = (worklen1 * 2))) ); break;
	case VARB_STR   : 
		/* Limit To Maximum ASKBUF length */
		/* ------------------------------ */
		 if (( asklen = worklen1 ) > ASKBUFMAX )
			asklen = ASKBUFMAX; 
		 memcpy((BPTR)askbuf,workptr1,asklen); 
		 break;
	default : return(SOFTERROR);
	}
#ifdef	OLD_BUGS
	/* Establish Zero Buffer For Numeric Data Input */
	/* -------------------------------------------- */
	if ( worktyp1 != VARB_STR ) { for ( x = 0; x < 80 ; x++ ) { askbuf[x] = IO_NUL; } }
#endif
	fmthex = 0;		/* Reset Hexa control		*/
	fbcdv  = -1;		/* To control the FMT_V options */
	iof_insert_flag();	/* Insert mode always OFF	*/
	LastJumpKey = 0;	/* Reset Last Jump Key		*/

	/* Enter Low Level ASK function */
	/* ---------------------------- */
	lowlevelret = ll_ask(asklen);
	ll_ask_flag = 0;

	if (( askmask & MASK_ACTIV_EDIT_KEYS) && ( askaction ))
		reset_preferentiel( askholder );

	if (lowlevelret == SOFTERROR)
	{ 
		if (!( askmask & MASK_DONOT_PRINT ))
			undo_ask_action( sfx );
		return(SOFTERROR); 
	}

	/* Calculate String Length input */
	/* ----------------------------- */
	/* #BG 26/06/20 ASK VIRTUAL KBD: Un evt souris (x_getch()=256) fait sortir de low_level_ask()
	   et provoque ici le recalcul de la longueur du buffer
	*/
	asklen = strlen((BPTR) askbuf);

	/* Re-Establish Variable Lock if Needed */
	/* ------------------------------------ */
	if ( LockStatus != 0 )
	{
		(VOID) Semaphon();
	}

	/* Select Storage operation or Default Zero Value */
	/* ---------------------------------------------- */
	if ( asklen > 0 )
	{
		/* Something to Save to Variable */
		/* ----------------------------- */
		switch ( worktyp1 )
		{
		case VARB_FOUR  : 
		case VARB_INT8  : 
			if ( fmthex == 0 )
			{
				*workptr1 = (EXABYTE) exatoi((BPTR) askbuf,asklen); 
			}
			else
			{
				*workptr1 = (EXABYTE) hextoi((BPTR) askbuf,asklen); 
			}
			break;
		case VARB_INT16 : 
			if ( fmthex == 0 )
			{
				workval1 = exatoi((BPTR) askbuf,asklen);
			}
			else
			{
				workval1 = hextoi((BPTR) askbuf,asklen);
			}
			balputw(workval1,workptr1);
			break;
		case VARB_INT32 : 
			if ( fmthex == 0 )
			{
				workval1 = exatol((BPTR) askbuf,asklen);
			}
			else
			{
				workval1 = hextol((BPTR) askbuf,asklen);
			}
			balputl(workval1,workptr1);
			break;
		case VARB_INT64 : 
			if ( fmthex == 0 )
			{
				workval1 = exatoh((BPTR) askbuf,asklen);
			}
			else
			{
				workval1 = hextoh((BPTR) askbuf,asklen);
			}
			balput64(workval1,workptr1);
			break;
		case VARB_BCD   : 
			/*	if ( fbcdv != -1 ) { vshift(); }	*/
			/*	--------------------------------	*/

			/* Convert to BCD String */
			/* --------------------- */				
			atobcd((BPTR) &askbuf[0],workptr1,worklen1,strlen((BPTR) &askbuf[0])); 

			/* Adjust power conversion factor if required */
			/* ------------------------------------------ */	
			if ( fbcdv < 0 ) { fbcdv++; }

			/* Convert Power with respect to power desired */
			/* ------------------------------------------- */
			if ( fbcdv != 0 )
			{
				(VOID) std2bcd((BPTR) workptr1,(EXAWORD) worklen1,(BPTR) askbuf,(EXAWORD) worklen1 ,(BINAIRE) ((BINAIRE) fbcdv * -1));
				(VOID) memcpy((BPTR) workptr1 , (BPTR) askbuf, (USINT) worklen1);
			}

			break;

		case VARB_STR   : 
			d = (BPTR) &askbuf[0];
			/* Perform String Transfer to Result */
			/* --------------------------------- */
			while ( worklen1 > 0 )
			{ 
				if ( *d != IO_NUL)
				{
					*(workptr1++) = *(d++); worklen1--;
				}
				else
					break;
			}

			/* Perform String Space Filler */
			/* --------------------------- */
			while ( worklen1 > 0 )
			{
				*(workptr1++) = IO_ESP; worklen1--;
			}
		}/* switch */
	}
	else
	{
		/* Nothing to Save so Reset to Zero or Space */
		/* ----------------------------------------- */
		switch ( worktyp1 )
		{
		case VARB_FOUR  : 
		case VARB_INT8  : 
			*workptr1 = (EXABYTE) 0;
		 	break;
		case VARB_INT16 : 
			balputw( 0 , workptr1 ); 
			break;
		case VARB_INT32 : 
			balputl( 0 , workptr1 ); 
			break;
		case VARB_INT64 : 
			balput64( 0 , workptr1 ); 
			break;
		case VARB_BCD   : 
			*(workptr1++) = (EXABYTE) 0x00C0; 
			worklen1--;
			while ( worklen1 > 0 )
			{ 
				*(workptr1++) = (EXABYTE) 0x00FF;
				worklen1--;
			}
			break;
		case VARB_STR  : 
			while ( worklen1 > 0 )
			{
				*(workptr1++) = IO_ESP;
				worklen1--;
			}
			break;
		}
	}		
	fbcdv = 0;

	/* Check if Auto Ask Action Required */
	/* --------------------------------- */
	if (!( askmask & MASK_DONOT_PRINT ))
		undo_ask_action( sfx );

	return(1);
}
/*
 *	S F _ P R I N T ( fx )
 *	----------------------
 *
 *	PRINT=DEV	Formated print output
 *	---------	---------------------
 *	Where		DEV = 1		: Console
 *			DEV = 2		: Printer
 *			DEV = 0		: Variable
 *			DEV = n		: File number n
 */

EXAWORD	sf_print(EXAWORD fx)
{
	EXAWORD	status=GOODRESULT;

	/*	Etablir WORKSET 1	*/
	/*	-----------------	*/

	if (( fx & 0x0080 ) != 0) { 
		/* The argument is a constant in tcode */
		/* ----------------------------------- */ 
		workptr1 = fdex; worktyp1 = VARB_STR; worklen1 = 0;
		while ( *(fdex++) != IO_NUL ) 
			worklen1++; 
		}	
	else if ( argset( (( fx & 0x0060) >> 5),0,1) == SOFTERROR) 
		return(SOFTERROR);

	/*
	 *	Choisir en fonction du Type des donnees
	 *	---------------------------------------
	 */

	OpenVisualPrint();

	switch ( worktyp1 ) {

		case    VARB_FOUR  :
		case	VARB_INT8  :	

				if ( workval1 < 0 ) 
					workval1 |= 0x7F00;

		case	VARB_INT16 :
		case	VARB_INT32 :
		case	VARB_INT64 :

				status = iof_print_int( workval1, worktyp1 );
				break;

		case	VARB_BCD   :	

				status = iof_print_bcd( workptr1, worklen1 );
				break;

		case	VARB_STR : 	

				status = iof_print_str( workptr1, worklen1 );
				break;

		default		 :
				status = SOFTERROR;

		}
	return( CloseVisualFont( status ) );

}

EXAWORD	sf_tabl( EXAWORD tcode )
{

	if ( argset(((tcode & 0x0060) >> 5),0,2) == SOFTERROR)
		return( SOFTERROR );
	else	iof_tabl( workval2 );

	return( GOODRESULT );

}

EXAWORD	sf_tabc( EXAWORD tcode )
{
 
	if ( argset(((tcode & 0x0060) >> 5),0,2) == SOFTERROR)
		return( SOFTERROR );
	else    iof_tabc( workval2 );
	
	return( GOODRESULT );

}

EXAWORD	sf_tabv( EXAWORD tcode )
{
	if ( argset(((tcode & 0x00E0) >> 5),0,1) == SOFTERROR ) 
		return( SOFTERROR );
	else	iof_tabv( workval1 );
	return( GOODRESULT );

}

/* 
 *	I O W O R K ( )
 *	---------------
 *
 *	Entry point for Character IO (Print, Ask etc)
 *	---------------------------------------------
 */

EXAWORD ll_iowork()
{
	register EXAWORD tcode;
		 EXAWORD EscOut,EscIn;
#ifdef UNIXWARE2
	int ret;
#endif

	/* Initialise IOF Control variable state */
	/* ------------------------------------- */
	iof_start();

	EscIn  = MOINS_UN; EscOut = MOINS_UN;

do {
	/* Select CICO subfunction Code */
	/* ---------------------------- */
	switch ( ((tcode = (EXAWORD) *(fdex++)) & 0x000F) ) {

		case 0 : /* Check for Exit Escape Code */
			 /* -------------------------- */
			 if ( tcode == 0     ) { continue; }
			 if ( tcode & 0x0010 ) {
				 /* Request for Motor Execution */
				 /* --------------------------- */
				 ExQui++;
				 if ( llmotor() == MOINS_UN ) { tcode = 0; }
				 ExQui--; continue;
				}
			 if ( tcode & 0x0020 ) {
				/* Request for Extended Tcode Zone @Gosub adr */
				/* ------------------------------------------ */
				EscIn = Tcodeword( fdex );
				EscOut = ( ((EXAWORD) ( fdex - TcodeSegment )) + WORDSIZE);
				fdex = (BPTR) (TcodeSegment + EscIn);
				continue;
				}
			 if ( tcode & 0x0040 ) {
				if ( EscOut != MOINS_UN ) {
					fdex = (TcodeSegment + EscOut);
					EscOut = MOINS_UN;	
					continue;
					}
				}
			tcode = 0; err_val = 56;
			continue;

		case 1 : /* HOTKEY definitions */
			 /* ------------------ */
			 tcode = sf_hotkey(tcode,_GOTO_HOTKEY); break;

		case 2 : /* Tabulation COLUMN */
			 /* ----------------- */
#ifdef UNIXWARE2
			ret = sighold(SIGALRM);
#endif
			 tcode = sf_tabc( tcode ); break;

		case 3 : /* DEVICE atribute management */
			 /* -------------------------- */
#ifdef UNIXWARE2
			ret = sighold(SIGALRM);
#endif
			 tcode = sf_atb(tcode); break;

		case 4 : /* PRINT output */
			 /* ------------ */ 
#ifdef UNIXWARE2
			ret = sighold(SIGALRM);
#endif
			tcode = sf_print(tcode);
			if ( (( fmtflg & 3 ) == 0 ) && ((fmtflg & 4) != 0)) {
				fmtptr = fmtbase;
				fmtflg |= 3;
				dynadex = 0;	
				}
			break;

		case 5 : /* TABV(x) Line Feed Ret Char */
			 /* -------------------------- */
#ifdef UNIXWARE2
			ret = sighold(SIGALRM);
#endif
			tcode = sf_tabv( tcode ); break;

		case 6  : /* FORMAT information */
			  /* ------------------ */
			  tcode = sf_fmt(tcode); break;

		case 7 :  /* DEVICE selection */
			  /* ---------------- */
			  tcode = sf_dev(tcode); break;

		case 8  : /* COLOUR management */
			  /* ----------------- */
#ifdef UNIXWARE2
			ret = sighold(SIGALRM);
#endif
			  tcode = sf_paint(tcode); break;
		case 10 : tcode = sf_paint(tcode); break;

		case 9 :  /* SPECIAL Functions (BELL , PAGE , CLEAR , HOME) */
			  /* ---------------------------------------------- */ 
#ifdef UNIXWARE2
			ret = sighold(SIGALRM);
#endif
			  switch ( tcode ) {
				case 0x0009 : 
					if ( prndest > 1 ) 
						x_clear(); 
					else	{ 
						atb(0); x_clear(); 
						}
					break;
				case 0x0029 : 
					if ( prndest > 1 ) 
						exputch(0x001C);
					else	pos(1,1);
					break;
				case 0x0049 : x_bell(); break;
				}
			break;

		case 11 : /* Tabulation LINE */
			  /* --------------- */
#ifdef UNIXWARE2
			ret = sighold(SIGALRM);
#endif
			  tcode = sf_tabl(tcode); break;
	

		case 12 : /* KEYBOARD input (ASK) */
			  /* -------------------- */
#ifdef BUF_CICO
			x_bflush();	/* Flush Cico buffers Now !!! */
#endif
#ifdef	ABAL21
			IpcRaise(_SEMAPHORE_CICO);
#endif
			tcode = sf_ask(tcode);
#ifdef	ABAL21
			IpcDrop(_SEMAPHORE_CICO);
#endif
			tcode = 0;
			break;

		case 13 : tcode = iof_special_hotkey(tcode,_GOSUB_HOTKEY);
			  tcode = 1; 
			  break;

		case 14 :
			  tcode = iof_special_hotkey(tcode,_GOTO_HOTKEY);
			  tcode = 1; 
			  break;

		case 15 : tcode = sf_hotkey(tcode,_GOSUB_HOTKEY);
		          break;

		default : tcode = 0; break;

		}

    }
while ( tcode != 0 );		/* While Not Error and Not end of ASK */


/* Terminate IOF cycle */
/* ------------------- */ 
#ifdef UNIXWARE2
	ret = iof_flush();
	sigrelse(SIGALRM);
	return(ret);
#else
return( iof_flush() );
#endif
}

EXAWORD	iowork()
{
EXAWORD IoworkResult;

	ExaCriticalSection = 1;			/* IOF is not interruptible */
	IoworkResult = ll_iowork();
	ExaCriticalSection = 0;
	
	if ( IoworkResult == SOFTERROR )
		return( SOFTERROR );
#ifdef	PROLOGUE
	else if ( stack_inspecter() != 0 ) {
		err_val = 669;
		return( SOFTERROR );
		}
#endif
	else	return( GOODRESULT );
}

#endif	/* _EXIOF_C */
	/* -------- */
