/* ---------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXPROC - C				*/
/*		Version :	1.4c / 2.1d				*/
/*		Date 	:	17/02/1997				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	Reference : EXPROC-DOC						*/
/*----------------------------------------------------------------------*/
#ifndef	_EXPROC_C
#define	_EXPROC_C

#ifdef	ABAL21
#include "exptr.h"
#endif

#ifdef DEBUGGER
#include "exproto1.h"
#endif

BPTR	LDS_base;
EXAWORD	LDS_dex;
EXAWORD	StackHold;

EXTERN	EXAWORD	diezlds;
static	EXAWORD	LoadedProcedures=0;

EXAWORD	InitQalloc()
{
	/* Allocate Procedure Local Variable Qwick Malloc Zone */
	/* --------------------------------------------------- */
	if (( LDS_base = (BPTR) malloc( diezlds )) == (BPTR) 0 )
		return(SOFTERROR);
	else	return(1);
}

#ifndef	DOS
#ifndef	PROLOGUE

/*
 *	Q A L L O C ( nboct )
 *	---------------------
 *	Quick allocation method (Last Out First In) for the local
 *	variables of procedures.
 *	The size of the Quick allocation zone is indicated by the
 *	translator directive #HEAP
 *
 */

VPTR	Qalloc( nboct )
EXAWORD	nboct;
{
	VPTR	lptr;

	/* Check for space remaining in Quick allocation zone */
	/* -------------------------------------------------- */
	if (( LDS_dex + nboct ) >= diezlds ) {

		/* Perform System Allocation */
		/* ------------------------- */
		if ((lptr = malloc( nboct )) != (VPTR) 0)
			memset((VPTR) lptr, 0, nboct );
		return( lptr );
		}

	/* Use and protect quick allocation zone */
	/* ------------------------------------- */
	lptr = (VPTR) (LDS_base + LDS_dex);
	LDS_dex += nboct;
	return( lptr );
}

VOID	Qfree( qmemptr )
BPTR	qmemptr;
{

	/* Check for Quick allocation zone pointer */
	/* --------------------------------------- */
	if (( qmemptr >= LDS_base ) && ( qmemptr < (LDS_base + diezlds)))

		/* Liberate this portion of the QALLOC zone */
		/* ---------------------------------------- */
		LDS_dex = ( qmemptr - LDS_base );		

	else	

		/* Perform system liberation of pointer */
		/* ------------------------------------ */
		free( qmemptr );

	return;
}
#endif
#endif


#ifdef ABALCLP

/* 
 *	PROCARG( number )
 *	-----------------
 *	Establishs the data set WORKSET2 wrt to the arguament type
 */

EXAWORD procarg(ac)
EXAWORD	ac;
{
	BPTR	dp;
	EXAWORD	cc,x,l,i,a;

	dp = (BPTR) (LocalDataTable + (3 * WORDSIZE)); cc = 1;
	while ( cc != ac ) {
		x = Tcodeword( dp); dp += (2 * WORDSIZE);
#ifdef	ABAL21_MERDE
		if ( x & ISDYNAMIC ) {
			if ((x & VARB_ISOL) > 1)
				dp += (3 * WORDSIZE);
			else	dp += (2 * WORDSIZE);
			}
		else	{
#endif
#ifdef	ABAL21
		if (( x & ISDYNAMIC ) && ( x & ISMEMBER ))
			dp += WORDSIZE;
#endif

		if ((x & VARB_ISOL) > 1)  
			dp += WORDSIZE;
		if (x & NDX1st) 	  { 
			if (x & NDX2nd)
				dp += (2 * WORDSIZE);
			else	dp += WORDSIZE;
			}
#ifdef	ABAL21_MERDE
			}
#endif
		cc++;
		}
	worktyp2 = Tcodeword( dp); 
#ifdef	ABAL21
	if ( worktyp2 & ISDYNAMIC )
		return( 0 );
#endif
	dp += WORDSIZE;
	workptr2 = LocalDataSegment + Tcodeword( dp); 
	dp += WORDSIZE;

	switch (worktyp2 & VARB_ISOL) {
		case VARB_INT8  : worklen2 = 1; break;
		case VARB_INT16 : worklen2 = 2; break;
		default		: worklen2 = Tcodeword( dp); 
				  dp += WORDSIZE; 
		}
	if (worktyp2 & NDX1st) { 	
		i = Tcodeword( dp);
		if (worktyp2 & NDX2nd) 	{ 
			dp += WORDSIZE; 
			a = Tcodeword( dp); 
			}
		else 	a = 1;
		}
	else 	{ i = 1; a = 1; }

	if (( a + i ) > 2 ) 
		ProcSwap = 1;

	worklen2 *= ( i * a ); worktyp2 &= VARB_ISOL; return(1);
}


/* 
 *	P RET VAL (Pointer, Count )
 *	---------------------------
 *	Transfers the Current values of the arguaments passed
 *	back to the calling routine.
 */ 

EXAWORD	pretval(bp,ac)
BPTR	bp;			/* Points to base of Arguament description */
EXAWORD	ac;			/* Current Arguament Number		   */
{
	EXAWORD	arg,x,dc,work,api,reg,attreg;
	BPTR	hb1,hb2;
	EXABYTE	ccc;
#ifdef	VERSION_XX
	EXAWORD	hil;
	EXAWORD	htg;
#endif
#ifdef	ABAL21
	BPTR	hb3,hb4;
	EXAWORD	special;
#endif

/*	Establish WORKSET2 wrt procedure local Variable		*/
/*	-----------------------------------------------		*/
#ifdef	ABAL21
/* Zero means Dynamic Variable Reference so No Recopie is required */
/* --------------------------------------------------------------- */
if (procarg(ac -1) == 0 ) 
	return(1);
#else
if (procarg(ac -1) == SOFTERROR )
	return(SOFTERROR);
#endif

/*	Collect destination DATA arguament 	*/
/*	----------------------------------	*/

dc = 0; x = 0; api = 0;
do 	{	
	if ( x == 0 ) { 
		work = (EXAWORD) *(bp++); x = 1; dc++;
		arg = (work & 0x00F0) >> 4; 
		}
	else 	{ 
		dc++; arg = (work & 0x000F); x = 0; 
		}
	if ( dc != ac ) {
                switch ( (arg & 0x0006) >> 1 ) {
                        case 0x0000 :
                        case 0x0001 :
                        case 0x0002 : api += WORDSIZE; break;
                        case 0x0003 : api += (5 * WORDSIZE); break;
			}
		}
	}
while ( ( dc != ac ) && (( arg & 0x0001 ) != 0) );

/*	Check for Errors	*/
/*	----------------	*/

if ( dc != ac ) { 
	err_val = ABAL_ARGTYPE; 
	return(SOFTERROR); 
	}

/*	Position to Arg Values	*/
/*	---------------------	*/

if ( (arg & 0x0001) != 0 ) {
        do {
        	if ( x == 0 ) { 
        		if ( ((work = *(bp++)) & 0x0010 ) == 0 )
				x = 2; 
        		else 	x = 1; 
        		}
        	else 	{
			if ( (work & 0x0001 ) == 0 ) 
				x = 2;
        		else 	x = 0;
        		}
		}
	while ( x != 2 );
	}
bp += api;	/* Calculate Arguament Pointeur */

/*	Establish WORKSET1 wrt to callers DATASETS	(WR)	*/
/*	------------------------------------------	----	*/
#ifdef	VERSION_XX
hil		 = ISLOCAL; 
htg		 = TOGLOBAL;
if ( ip_hold[ (ip_next - 5)] & ISLOCAL3  ) {
	ISLOCAL = ISLOCAL3;
	TOGLOBAL = TOGLOBAL3;
	}
else	{
	ISLOCAL = ISLOCAL4;
	TOGLOBAL = TOGLOBAL4;
	}
#endif

hb1 		 = LocalDataTable; 
hb2 		 = LocalDataSegment;
LocalDataTable   = minder [ ( mindex - 2 ) ]; 
LocalDataSegment = minder [ ( mindex - 1 ) ];


#ifdef	ABAL21
/* Check for Far Call Context */
/* -------------------------- */
/*	IJM 19/10/1995		*/
#ifndef	LONG_FILE_HANDLES
if ((special = ip_hold [ ( ip_next - 10 ) ]) != 0 ) {
/*ici*/	hb3 = GlobalDataTable;
	hb4 = GlobalDataSegment;
	GlobalDataSegment = minder [ ( mindex - 8 ) ];
	GlobalDataTable   = minder [ ( mindex - 9 ) ];
	}
#else
if ((special = ip_hold [ ( ip_next -  10) ]) != 0 ) {
	hb3 = GlobalDataTable;
	hb4 = GlobalDataSegment;
	GlobalDataSegment = minder [ ( mindex - 8 ) ];
	GlobalDataTable   = minder [ ( mindex - 9 ) ];
	}
#endif
#endif

attreg = 0;
switch ( (arg & 0x0006) >> 1 ) {
        case VARIABLE : work = Tcodeword( bp); bp += WORDSIZE;
		 	if (argsetw(5,work) == SOFTERROR) 
				return(SOFTERROR);
		 	break;
        case TEMPDESC : reg = Tcodeword( bp); bp += WORDSIZE;
		 	freg [reg] = Tcodeword( bp); bp += WORDSIZE;
		 	ireg [reg] = Tcodeword( bp); bp += WORDSIZE;
		 	areg [reg] = Tcodeword( bp); bp += WORDSIZE;
		 	xreg [reg] = Tcodeword( bp); bp += WORDSIZE;
			if ( xreg [reg] == IMMEDIAT ) 
				attreg = 1;
			else 	if (argsetw(4,reg) == SOFTERROR)
					return(SOFTERROR);
		 	break;
        default       : err_val = ABAL_ARGTYPE; return(SOFTERROR);
        }

LocalDataTable = hb1; LocalDataSegment = hb2;
#ifdef	VERSION_XX
ISLOCAL = hil; TOGLOBAL = htg;
#endif

#ifdef	ABAL21
if ( special ) {
	GlobalDataTable = hb3;
	GlobalDataSegment = hb4;
	}
#endif
#ifdef ABALME
	ProcSwap = 0; 
#ifndef LINEAR_MEM
if ( extwrite & 2 ) { 
	if ( xferout(workptr2,(worklen2 < worklen1) ? worklen2 : worklen1,keepvofs) == SOFTERROR)
		return( SOFTERROR );
	extwrite = 0; return(1);
	}
#endif	/* ! LINEAR_MEM */
#endif	/* ABALME	*/


/*	Perform the Memory result transfer	*/
/*	----------------------------------	*/
if ( attreg == 0 ) 
	while (( worklen2 > 0 ) && (worklen1 > 0)) { 
		*(workptr1++) = *(workptr2++); 
		worklen2--; worklen1--; 
		}
else	{
	switch ( worktyp2 ) {
		case VARB_INT8  : freg [reg] = (BINAIRE) ReadSchar( workptr2 );  /* *((CPTR) workptr2); */  break;
		case VARB_INT16 : freg [reg] = balgetw( workptr2 );
		}
	}
return(1);
}

/* 
 *	C P Y M R X ( arguaments )
 *	--------------------------
 *
 *	Transfert d'une matrice ou tableau aux procedures
 *	-------------------------------------------------
 */

EXAWORD cpymrx(atype,avalu,dbase,dleng,reg)
EXAWORD	atype;			/* Data type of source arguament */
EXAWORD	avalu;			/* Hopefully a variable pointer  */
BPTR	dbase;			/* Base adresse of recieve zone	 */
EXAWORD	dleng;			/* Length of recieve zone	 */
EXAWORD	reg;			/* Register where needed	 */
{
	BPTR	sbase;
	EXAWORD	etdchk;
	EXALONG	bigvofs;

switch ( atype ) {
	case IMMEDIAT   :
	case KONSTANT   :
	case TEMPDESC   : err_val = ABAL_TCODFILE; return(SOFTERROR);
	case PTRSTR	:
	case PTRBCD	: sbase = preg [reg]; break;
	case VARIABLE   :

	if (avalu & ISLOCAL) {
		sbase = (LocalDataTable + (avalu & TOGLOBAL) + WORDSIZE);	
		sbase = (LocalDataSegment + Tcodeword( sbase));
		}
	else 	{
		sbase = (GlobalDataTable + avalu);
		etdchk = Tcodeword( sbase ); 
		if ((etdchk & SPECIALE) != 0 ) { 
			if ( etdchk & ISETENDU) {
				sbase += WORDSIZE;
				bigvofs = ((EXALONG) Tcodeword((sbase + WORDSIZE)) ) << 16;
				bigvofs += (EXALONG) Tcodeword(sbase); 
#ifndef LINEAR_MEM
				if (xferin( dbase , dleng , bigvofs ) == SOFTERROR)
					return( SOFTERROR );
				return(1);
#else	/* LINEAR_MEM	*/
				sbase = ExtendedMemory + bigvofs;
#endif	/* ! LINEAR_MEM	*/
				}
			else	{
				err_val = ABAL_PROCARG; return(SOFTERROR); 
				}
			}
		else 	sbase = (GlobalDataSegment + Tcodeword( (sbase + WORDSIZE) )); 
		}
	}
memcpy(dbase,sbase,dleng); return(1);	/* Duplicate tableau */

}

/* 
 *	V T O P R O C ( Arguaments )
 *	----------------------------
 *
 *	Transfert des valeurs des parametres d'appel
 *	--------------------------------------------
 */

BPTR	vtoproc(atype,avalu,vdesc,vbase,reg)
EXAWORD	atype;			/* Type of Arguament ival,cptr,vptr,tmp  */
EXAWORD	avalu;			/* Arguament Value 			 */
BPTR	vdesc;			/* Procedure Variable descriptor pointer */
BPTR	vbase;			/* Procedure data storage base 		 */
EXAWORD	reg;			/* Register to use for Indexes if needed */
{
	register	EXAWORD	pvtype;
			EXAWORD	pvindex,pvandex,pvleng,svleng;
			BPTR	sbase;

/* Get destination data type */
/* ------------------------- */
pvtype = Tcodeword( vdesc);

/* Establish Default Error Value */
/* ----------------------------- */
err_val = ABAL_PRCMESS;	

/* Ensure Arguament and Corrent Value */
/* ---------------------------------- */
if ( ((pvtype & VARB_ARG) == 0) || ( pvtype == MOINS_UN )) { 
	err_val = ABAL_PROCARG; return((BPTR) 0); 
	} /* Erreur NOT arguament or End of Procedure Variable Table ! */
else 	{
#ifdef	ABAL21
	/* Check for REFERENCER Reception Variable */
	/* --------------------------------------- */
	if (!( pvtype & ISDYNAMIC )) {

#endif
		vdesc += WORDSIZE; /* Advance Descriptor pointer to storage pointer */
		vbase += Tcodeword( vdesc); /* Calculate Variable storage zone */
		vdesc += WORDSIZE; /* Advance Descriptor pointer to length or indices */
		if ( (pvtype & 0x0003) > 1 ) {
			pvleng = Tcodeword( vdesc); vdesc += WORDSIZE;
			}
		else 	pvleng = (pvtype & 0x0001) + 1; 
		if ( (pvtype & NDX1st) != 0 ) {
			pvindex = Tcodeword( vdesc); vdesc += WORDSIZE;
			}
		else 	pvindex = 1; 
		if ( (pvtype & NDX2nd) != 0 ) {
			pvandex = Tcodeword( vdesc); vdesc += WORDSIZE;
			}
		else 	pvandex = 1; 

		/* Test for Matrix Reception */
		/* ------------------------- */
		if ((pvindex + pvandex) > 2 ) { 

			/* Perform Matrix Transfer */
			/* ----------------------- */
			if ( cpymrx(atype,avalu,vbase,(pvleng * pvindex * pvandex ),reg) != SOFTERROR )
				return(vdesc);
			else return((BPTR) 0); 
			}
#ifdef	ABAL21
		}
	else	{
		/* The Arguament Reception Variable is a Pointer */
		/* --------------------------------------------- */
		/* Calculate Pointer Location */
		/* -------------------------- */
		vbase += Tcodeword((vdesc+WORDSIZE)); 	

		/* Step over pointer description */
		/* ----------------------------- */
		if ((pvtype & VARB_ISOL) > 1)
			vdesc += (3 * WORDSIZE);
		else	vdesc += (2 * WORDSIZE);
		if (pvtype & NDX1st)
			vdesc += WORDSIZE;
		if (pvtype & NDX2nd)
			vdesc += WORDSIZE;

		}
#endif
	}

switch ( atype ) { 
	/* Convert arg types to data type,length,pointer */
	/* --------------------------------------------- */
	case IMMEDIAT : workval1 = avalu; worktyp1 = VARB_INT16; break;
	case KONSTANT : if ( argset(6,avalu,1) == SOFTERROR) 
				return((BPTR) 0);
		 	break;
	case VARIABLE : freg [reg] = avalu; xreg [reg] = VARIABLE;
			if ( argset(4,reg,1) == SOFTERROR) 
				{
				if ( err_val == 118 )
					workptr1 = (BPTR) 0;
				else	return((BPTR) 0);
				}
		  	break;
	case PTRSTR   : 
	case PTRBCD   : workptr1 = preg [reg]; worklen1 = lreg [reg];
			worktyp1 = atype & VARB_ISOL;
			break;
	case TEMPDESC : if ( argset(7,avalu,1) == SOFTERROR ) 
				return((BPTR) 0);
		 	break;
	}

#ifdef	ABAL21
	if ( pvtype & ISDYNAMIC ) {
		memset( (BPTR) vbase, 0, 5 );
		if ( workptr1 != (BPTR) 0 )
			establish_pointer_variable((BPTR) vbase, (BPTR) workptr1, REFERENCED_POINTER );
		return( vdesc );
		}
#endif

switch ( worktyp1 ) {	/* Select WRT source data type (# or % , BCD , STR */
	case VARB_INT8  : switch ( pvtype & VARB_ISOL ) {
			   case VARB_INT8  : *vbase = *workptr1; break;
			   case VARB_INT16 : balputw((EXAWORD) workval1,vbase); break;
			   case VARB_BCD   : itobcd(workval1,vbase,pvleng); break;
			   case VARB_STR   : if ( pvleng > 6 ) 
							itoa(workval1,vbase,pvleng);
						/* Str too short 4 int */
			   		     else 	return((BPTR) 0); 
			   }
			 break;
	case VARB_INT16 : switch ( pvtype & VARB_ISOL ) {
			   case VARB_INT8  : *vbase = (EXABYTE) workval1; break;
			   case VARB_INT16 : balputw((EXAWORD) workval1,vbase); break;
			   case VARB_BCD   : itobcd(workval1,vbase,pvleng); break;
			   case VARB_STR   : if ( pvleng > 6 )
							itoa(workval1,vbase,pvleng);
				 	     else	return((BPTR) 0);
			   }
			  break;
	case VARB_BCD   : switch ( pvtype & VARB_ISOL ) {
			   case VARB_INT8  : *vbase = (EXABYTE) bcdtoi(workptr1,worklen1); break;
			   case VARB_INT16 : balputw((EXAWORD) bcdtoi(workptr1,worklen1),vbase); break;
			   case VARB_BCD   :
				/* Check for Filler Required */
				/* ------------------------- */
				if ( pvleng > worklen1 ) {
					worklen2 = worklen1; 
					worklen3 = (pvleng - worklen1);
					}

				/* Else No Filler Required */
				/* ----------------------- */
				else	{ 
					worklen2 = pvleng;   
					worklen3 = 0;
					}

				/* Tranfer to Procedure Variable */
				/* ----------------------------- */
				(VOID) memcpy((BPTR) vbase, (BPTR) workptr1, (USINT) worklen2 );

				/* Perform Filler if Needed */
				/* ------------------------ */
				if ( worklen3 > 0 )
					(VOID) memset((BPTR) (vbase + worklen2),
					(((*workptr1 & 0x00F0) == 0x0040) ? 0 : MOINS_UN),
					(USINT) worklen3);

				/*  memcpy(vbase,workptr1,pvleng); */

				break;
			   case VARB_STR   : bcdtoa(workptr1,worklen1,vbase,pvleng);
			   }
			  break;
	case VARB_STR   : switch ( pvtype & VARB_ISOL ) {
			   case VARB_INT8  : *vbase = (EXABYTE) atoi(workptr1,worklen1); break;
			   case VARB_INT16 : balputw((EXAWORD) atoi(workptr1,worklen1),vbase); break;
			   case VARB_BCD   : atobcd(workptr1,vbase,pvleng,worklen1); break;
			   case VARB_STR   :
				/* Check for Filler Required */
				/* ------------------------- */
				if ( pvleng > worklen1 ) { worklen2 = worklen1; worklen3 = (pvleng - worklen1); }

				/* Else No Filler Required */
				/* ----------------------- */
				else			 { worklen2 = pvleng;   worklen3 = 0; 			}

				/* Tranfer to Procedure Variable */
				/* ----------------------------- */
				(VOID) memcpy((BPTR) vbase, (BPTR) workptr1, (USINT) worklen2 );

				/* Perform Filler if Needed */
				/* ------------------------ */
				if ( worklen3 > 0 )
					(VOID) memset((BPTR) (vbase + worklen2),' ',(USINT) worklen3);
			   }
			  break;
	}
	return((BPTR) vdesc); 

}

/*
 *	P R O C A B B ( level )
 *	-----------------------
 *	Abandon Appel ou retour de procedure en cours de traitement
 *	Restaurer le contexte d'entree et rends Exit (Level & 1 & errors)
 *
 *	The value LEVEL recieved from the caller indicates the following
 *
 *	BIT 0 :	 Callers required exit status , Zero , or 1 (False , True)
 *	BIT 1 :  All pointers are to be destacked if TRUE
 *	BIT 2 :  DATA management reset required if   TRUE
 *	BITS 3 - 15 , Reserved for extensions 
 */

#ifdef	ABAL21

VOID	procabb2( level )
EXAWORD	level;
{
	/* -------------------------------------------------------------- */
	/* ABAL 1.5 and above offers the possibility of return values 	  */
	/* via the instruction EXIT. These values may have been generated */
	/* in the zone #MEM which may be deteced by the fact that the	  */
	/* current #MEM usage offset in 'worktop' is not equal to the	  */
	/* current #MEM protection offset normally in 'workhold' but here */
	/* available as the parameter 'level'. NB this logic expects that */
	/* The EXIT instruction is of NEWLINE type which assures that the */
	/* The usage offset and protection offset are identical.	  */
	/* Two possible situations exist : EXIT ( string_expression )	  */
	/* and EXIT ( integer or no expression ) which can be seen as	  */
	/* follows :							  */
	/*								  */
	/* 1)	EXIT( string_expression )				  */
	/*	-------------------------				  */
	/*	It can be seen below that WT is not equal to WH which 	  */
	/*	indicates this syntax and WT must be retransmitted back	  */
	/*	to the callers context in order to protect the value of   */
	/*	the returned expression.				  */
	/*								  */
	/*  WH	|		|		|			  */
	/* #MEM --------------------------------------------------------- */
	/*  WT	|		|		|		|	  */
	/*								  */
	/* 2)	EXIT( integer or no expression )			  */
	/*	--------------------------------			  */
	/*	It can be seen below that WT is equal to WH which 	  */
	/*	indicates this syntax and WT may be restored to the 	  */
	/*	callers value which had been stacked up during the        */
	/*	call to the procedure.  				  */
	/*								  */
	/*  WH	|		|		|			  */
	/* #MEM --------------------------------------------------------- */
	/*  WT	|		|		|			  */
	/*								  */
	/* -------------------------------------------------------------- */

	if ( level == worktop )
		worktop = (EXAWORD) ip_hold [--ip_next];
	else	--ip_next;

#else	/* ! ABAL21 */
	/* -------- */

VOID	procabb2()
{
	/* -------------------------------------------------------------- */
	/* Prior to ABAL 15 no return value is permited via EXIT so the */
	/* callers WORTOP value must be restored from the integer stack */
	/* -------------------------------------------------------------- */

	worktop = (EXAWORD) ip_hold [--ip_next];

#endif

	/* Common part of procedure abandon mechanism */
	/* ------------------------------------------ */
	datadex = (EXAWORD) ip_hold [--ip_next];
	datapnt = (EXAWORD) ip_hold [--ip_next];
	datamax = (EXAWORD) ip_hold [--ip_next];
	procid  = (EXAWORD) ip_hold [--ip_next];
	
	return;
}

EXAWORD	CallProcFar;

#ifdef	ABAL21
EXTERN	OVLOBJPTR	TcodeContext;
#endif

EXAWORD	procabb( level )
EXAWORD	level;
{
#ifdef	ABAL21
	EXAWORD	dieze_mem_usage;

	dieze_mem_usage = workhold;
#endif
	if ( level & 2 ) {	/* If Destack part 2 required */


		/* Recover Stack, Timer and Event Context */
		/* -------------------------------------- */
		StackHold =  (EXAWORD)  ip_hold [--ip_next];
		eventadr  =  (EXAWORD)  ip_hold [--ip_next];
		timersem  =  (EXAWORD)  ip_hold [--ip_next];
#ifdef	ABAL21
		HardEvent = (EXAWORD)  ip_hold [--ip_next];
		enable_hard_event();
#endif
		/* Liberation of Error Structure */
		/* ----------------------------- */
		if ( sicico & ERROR_TEST )
			release_error_traps();

		/* Destack context status flags */
		/* ---------------------------- */
		sicico	=  (EXAWORD)  ip_hold [--ip_next];

#ifdef	VERSION_XX
		if ( sicico & ISLOCAL3 ) {
			ISLOCAL=ISLOCAL3;
			TOGLOBAL=TOGLOBAL3;
			}
		else	{
			ISLOCAL=ISLOCAL4;
			TOGLOBAL=TOGLOBAL4;
			}
#endif
		/* Destack LDS status flag */
		/* ----------------------- */
		if (ip_hold [--ip_next] == 0)
			if ( LocalDataSegment != (BPTR) 0 ) 
				liberate(LocalDataSegment);

		/* Collect Gosub Stack protection limit */
		/* ------------------------------------ */
		workhold  =  (EXAWORD) 	ip_hold [--ip_next];
#ifdef	ABAL21
		pushhold  =  (EXAWORD)	ip_hold [--ip_next];
#endif
		/* Collect Code and Data Base Pointers */
		/* ----------------------------------- */
		LocalDataSegment    =  minder [--mindex];
		LocalDataTable      =  minder [--mindex];
		TcodeSegment 	    =  minder [--mindex];

#ifdef	ABAL21
		/* Recover Previous Constant Table Pointer */
		/* --------------------------------------- */
		TcodeConstants	    = minder [--mindex];
#endif
		
		/* Recover callers error trap context */
		/* ---------------------------------- */
/*		if ( sicico & ERROR_TEST )	*/
			GlobalErrorTrap = (ERRORPTR) minder [--mindex];

		/* Establish Tcode Return Adresse */
		/* ------------------------------ */
		fdex      =  (TcodeSegment + (EXAWORD) ip_hold [--ip_next]);

		}
#ifdef	ABAL21
	if ((CallProcFar = ip_hold [ --ip_next ]) != 0 ) {
#ifndef	LONG_FILE_HANDLES
		TcodeFileHandle   = ip_hold [ --ip_next ];
#endif
		procmaxid         = ip_hold [ --ip_next ];
		TcodeConstants    = minder  [ --mindex  ];
		GlobalConstants   = minder  [ --mindex  ];
		GlobalDataSegment = minder  [ --mindex  ];
		GlobalDataTable	  = minder  [ --mindex  ];
#ifdef	LONG_FILE_HANDLES
		TcodeFileHandle   = (EX_FILE_HANDLE) minder  [ --mindex  ];
#endif
#ifdef	DEBUGGER
		force_debug_context((BPTR) ( minder [ --mindex ] ));
#endif
		TcodeContext	  = (OVLOBJPTR) minder  [ --mindex  ]; 
		TcodeProcTable	  = (struct  procform SPTR)	minder  [ --mindex  ];
		}
#endif

#ifdef	ABAL21
	procabb2( dieze_mem_usage );
#else
	procabb2();
#endif
	/* Reinitialise DATA manager */
	/* ------------------------- */
	if ( datadex < datamax ) {
		if ( level & 4 ) 
			level &= setdata(datadex);
		}
	else 	level = 1; 

	if ( err_val == 0 ) 
		err_val = ABAL_PRCMESS;

	return(level & 1);

}

#endif

/* 
 *	F _ C L P ( )
 *	-------------
 *
 *	Appel d'un procedure
 *	--------------------
 */

#ifdef	ABAL21

/*
 *	L O A D _ P R O C E D U R E ( procedure_identity )
 *	--------------------------------------------------
 *
 */

static	EXAWORD	load_procedure(TcodeProcTable, procid, failure )
struct  procform SPTR	TcodeProcTable;
EXAWORD			procid;
EXAWORD			failure;
{
	BPTR	dpb=(BPTR) 0;

	/* Ensure Tcode file is open */
	/* ------------------------- */
	if ( VerifTcode() == SOFTERROR )
		return( SOFTERROR );

	/* Ensure correct sector  and not empty procedure */
	/* ---------------------------------------------- */
	if (( (*(TcodeProcTable + procid)).code_sector == 0 )
	||  ( (*(TcodeProcTable + procid)).code_length == 0 ))  {
		err_val = ABAL_PRCMAX;
		return( failure );
		}

	/* Attempt to Load Procedure Code from Tcode File */
	/* ---------------------------------------------- */
	if ((   (*(TcodeProcTable + procid)).code_segment = (BPTR) kode_lode(
		(*(TcodeProcTable + procid)).code_sector ,
		(*(TcodeProcTable + procid)).code_length )) == (BPTR) 0) 

		return( SOFTERROR );

	else	LoadedProcedures++;

#ifdef	DEBUG_END_PROC
	x_cprintf((BPTR)"lp("); intvisi(procid); x_putch(')');
#endif

	/* Test for Local Constant Table Present in Tcode  */
	/* ----------------------------------------------- */
	if (( (*(TcodeProcTable + procid)).const_sector != 0 )
	&&  ( (*(TcodeProcTable + procid)).const_length != 0 ))

		/* Attempt to load the Procedure Constant   Table */
		/* ---------------------------------------------- */
		if ((   (*(TcodeProcTable + procid)).const_segment = (BPTR) kode_lode(
			(*(TcodeProcTable + procid)).const_sector ,
			(*(TcodeProcTable + procid)).const_length )) == (BPTR) 0)

			return( SOFTERROR );
	
	/* Check for Presence of Local Variable Table     */
	/* ---------------------------------------------- */
	if (( (*(TcodeProcTable + procid)).data_sector == 0 )
	||  ( (*(TcodeProcTable + procid)).data_length == 0 ))
		return( GOODRESULT );

	/* Attempt to load the Procedure Local Data Table */
	/* ---------------------------------------------- */
	if ((   (*(TcodeProcTable + procid)).table_segment = (BPTR) kode_lode(
		(*(TcodeProcTable + procid)).data_sector ,
		(*(TcodeProcTable + procid)).data_length )) == (BPTR) 0)

		return( SOFTERROR );


	dpb = (*(TcodeProcTable + procid)).table_segment;

	/* Watch out for STATIC procedure variables */
	/* ---------------------------------------- */
	if (( (*(TcodeProcTable + procid)).options & 0x0002) != 0 )
	
		/* Attempt to Initialise Static Variables */
		/* -------------------------------------- */
		if (( (*(TcodeProcTable + procid)).data_segment = (BPTR) init_data(
			(Tcodeword( (dpb    ) )),
			(Tcodeword( (dpb + 4) )),
			            (dpb + 6)    )) == (BPTR) 0)

			return(SOFTERROR);


#ifdef	ABAL21
#ifdef	DEBUGGER
	/* EXADB Can now Position any BREAK POINTS */
	/* --------------------------------------- */
	if ( sicico & (ONSEM_SEG | ONSEM_PRC))
		(void) ProcedureTrapWork( 1, procid );
#endif
#endif

	/* Indicate Success */
	/* ---------------- */
	return( GOODRESULT );

}


#endif

/*
 *	EXECUTER FUNCTION : CALL PROCEDURE
 *	----------------------------------
 *
 */
#ifdef	UNIX
EXAWORD	push_tcode_offset()
{
	if (ip_next >= diezstk) 
		return((err_val = ABAL_GSB2MANY));
	ip_hold [ (ip_next++) ] = (EXAWORD) (fdex - TcodeSegment); 
	return((err_val = 0));
}
#endif
#ifdef	WIN32
EXAWORD	push_tcode_offset()
{
	if (ip_next >= diezstk) 
		return((err_val = ABAL_GSB2MANY));
	ip_hold [ (ip_next++) ] = (EXAWORD) (fdex - TcodeSegment); 
	return((err_val = 0));
}
#endif

#ifdef	ABAL21
VOID	special_procedure_push()
{
#ifdef	DEBUGGER
	BPTR	active_debug_context(VOID);
#endif
	minder  [mindex++]  = (BPTR) TcodeProcTable;
#ifdef	ABAL21
	minder  [mindex++]  = (BPTR) TcodeContext;
#endif
#ifdef	DEBUGGER
	minder  [mindex++]  = (BPTR) active_debug_context();
#endif
#ifdef	LONG_FILE_HANDLES
	minder  [mindex++] = (BPTR) TcodeFileHandle;
#endif
	ip_hold [ip_next++] = procmaxid;
#ifndef	LONG_FILE_HANDLES
	ip_hold [ip_next++] = TcodeFileHandle;
#endif
	return;

}
#endif

EXAWORD	initial_procedure_push()
{
	/* Ensure stacks offer sufficient depth for the context push */
	/* --------------------------------------------------------- */ 
	if ((( ip_next + 17 ) >= diezstk) 
	||  (( mindex + 12) >= diezstk ) ) {
  		err_val = ABAL_GSB2MANY; 
		return(SOFTERROR);
		}

	/* Stack up initial context portion before arguament analysis */
	/* ---------------------------------------------------------- */
	ip_hold [ip_next++] = procid;		/* Save current Proc ID	   */
	ip_hold [ip_next++] = datamax;		/* Save max data 	   */
	ip_hold [ip_next++] = datapnt;		/* Save data offset 	   */
	ip_hold [ip_next++] = datadex;		/* Save current data index */
	ip_hold [ip_next++] = (EXAWORD) worktop;	/* And store for return    */

#ifdef	VERSION_XX
	if ( ISLOCAL & ISLOCAL3 ) {
		sicico |= ISLOCAL3;
		}
	else	{
		sicico &= ~ISLOCAL3;
		}
#endif
	return( GOODRESULT );

}

#ifdef	ABAL21
BPTR	collect_procedure_constants( procid )
EXAWORD	procid;
{
	BPTR	pcp;
	/* Collect Local or Establish Global Constants Pointer */
	/* --------------------------------------------------- */
	if ((pcp = (*(TcodeProcTable + procid)).const_segment) == (BPTR) 0)
		pcp = TcodeConstants;
	return( pcp );
}
#endif

EXAWORD	final_procedure_push( hsb, pcp, pdp, ptp, static_local_data )
BPTR	hsb;
BPTR	pcp;
BPTR	pdp;
BPTR	ptp;
EXAWORD	static_local_data;
{
	/* Save Code and Stack Index's */
	/* --------------------------- */	
	ip_hold [ip_next++] = (EXAWORD) (fdex - hsb);

#ifdef	ABAL21
	ip_hold [ip_next++] = pushhold; 
#endif
	ip_hold [ip_next++] = workhold; 

	/* Calculate current Temporary Zone Base Limit */
	/* ------------------------------------------- */
	workhold = worktop;
#ifdef	ABAL21
	pushhold = pushtop;
#endif
	/* Stack up TIMER,EVENT and Flags */
	/* ------------------------------ */
	ip_hold [ip_next++] = static_local_data;
	ip_hold [ip_next++] = sicico;
#ifdef	ABAL21
	ip_hold [ip_next++] = HardEvent;
#endif
	ip_hold [ip_next++] = timersem;
	ip_hold [ip_next++] = eventadr;

	ip_hold [ip_next++] = StackHold;

	/* Establish Stack Protection */
	/* -------------------------- */
	StackHold = ip_next;

	/* Cancel Possible EVENT activity */
	/* ------------------------------ */
	timersem &= EVENT_SEMOFF;

#ifdef	ABAL21
	disable_hard_event();
#endif

	/* Check for and Save Callers Error Trap Context */
	/* --------------------------------------------- */	
/*	if ( sicico & ERROR_TEST ) {	*/

		minder [mindex++] = (BPTR) GlobalErrorTrap;

		/* Reset to ON ERROR ABORT for starting procedure */
		/* ---------------------------------------------- */
		GlobalErrorTrap = (ERRORPTR) 0;
		sicico &= ( OFSEM_ERR & OFSEM_TRP );

/*		}	*/

#ifdef	ABAL21
	/* Perform Global to Local Constant Table Stacking and Swap */
 	/* -------------------------------------------------------- */
	minder [mindex++]   = TcodeConstants;
	TcodeConstants 	    = pcp;
#endif

	/* Stack up Code and Data Base Pointers */
	/* ------------------------------------ */
	minder [mindex++]   = hsb;
	minder [mindex++]   = LocalDataTable;
	minder [mindex++]   = LocalDataSegment;


	/* Establish starting procedure Code and Data Base Pointers */
	/* -------------------------------------------------------- */
	LocalDataSegment = pdp; 
	LocalDataTable   = ptp; 
	fdex 		 = TcodeSegment;

	/* Set Flag to indicate Procedure Active */
	/* ------------------------------------- */
	sicico |= ONSEM_PRC;

#ifdef	ABAL21
	if ( procid != MOINS_UN )
		(*(TcodeProcTable + procid)).callers++;
#endif

#ifdef	VERSION_XX
	finalise_indirection();
#endif
	return( GOODRESULT );

}

EXAWORD call_procedure()
{
	BPTR	sp,xp,hsb,ptp,pdp,dvp,svp,stp;
	BPTR	pcp;
	EXAWORD jx,jz,mask,reg,go,svl,ddx;

	EXAWORD	temp_zone_used;
	EXAWORD	arg_counter;
	EXAWORD	arg_type;
	EXAWORD	arg_value;
	EXAWORD	static_local_data;
	EXAWORD	oldtop;
	EXAWORD	lerrval;
	EXAWORD	special;
	EXAWORD	memsize;

	/* Initialise all control variables */
	/* -------------------------------- */
#ifdef	VERSION_XX
	prepare_indirection();
#endif
	go = 1;	
	arg_counter = 1; 
	pdp = (BPTR) 0; 
	ptp = (BPTR) 0;
	pcp = (BPTR) 0;
	sp = (TcodeByteStack + worktop);	/* Get workspace pointer   */

	if ( initial_procedure_push() == SOFTERROR )
		return( SOFTERROR );

	/* Collect argument Starting pointer */
	/* --------------------------------- */
	xp = sp;

	/* Scan past argument descriptors */
	/* ------------------------------ */
	while (( *(sp++) = *(fdex++) ) & 0x0001 )
		arg_counter++;

	/* Establish size of temp zone used for ARG descriptors */
	/* ---------------------------------------------------- */ 
	temp_zone_used = arg_counter; 

	/* Adjust the worktop pointer to allow extended variable management */
	/* ---------------------------------------------------------------- */
	oldtop = worktop; 
	worktop += ( arg_counter + ( (arg_counter * 2) * (WORDSIZE * 5)));

	/* Check for temporary workspace overflow */
	/* -------------------------------------- */
	if ( worktop > dieztmp ) {
#ifdef	ABAL21
		procabb2( oldtop );
#else
		procabb2();
#endif
		err_val = ABAL_MEMORY;
		return(SOFTERROR);
		}

	while (arg_counter--) {

		/* Part 1 High nibble => 1st of 2 possible Arguaments */
		/* -------------------------------------------------- */
		if ((arg_type = (((EXAWORD) *xp)  & 0x0060) >> 5) != 3) {
			arg_value = Tcodeword( fdex); 
			fdex += WORDSIZE;
			TcodePmot( sp , arg_value); 
			sp += WORDSIZE;
			temp_zone_used += WORDSIZE;
			reg = 0; /* Default Register for Imm Varptrs */
			}
		else 	{
			reg = (EXAWORD) *(fdex++); 
			arg_value = (EXAWORD) freg [reg];
			TcodePmot( sp, reg); 	    
			sp += WORDSIZE;
			TcodePmot( sp, arg_value ); 
			sp += WORDSIZE;
			TcodePmot( sp, ireg [reg]); 
			sp += WORDSIZE;
			TcodePmot( sp, areg [reg]); 
			sp += WORDSIZE;
			if ( xreg [reg] & PTRSTATUS ) { 
				TcodePmot( sp , VARIABLE ); 
				}
			else	{	
				TcodePmot( sp, xreg [reg]); 
				}
			sp += WORDSIZE;
			temp_zone_used += (5 * WORDSIZE); 
			arg_type = ((EXAWORD) xreg [reg] & 0x0803); 
			}


	/*	DO 1st TRANSFER HERE ( Z points to or is Arguament )	*/
	/*	----------------------------------------------------	*/

		/* Check for First Pass */
		/* -------------------- */
		if (go == 1) {

			/* Must initialise local Variables Now */
			/* ----------------------------------- */
			go = 0; hsb = TcodeSegment; special = 0;
#ifdef	ABAL21
			if ( arg_type &  2 ) {
				if ( (( reg == 0 )
				&&    ( argset(5,arg_value,1) == SOFTERROR))
				||   (( reg != 0 )
				&&    ( argset(4,reg,1) == SOFTERROR)) ) { 
					procabb2( oldtop );
					return( SOFTERROR );
					}
				switch (( worktyp1 & 0x0003 )) {
					case 0 :
					case 1 : arg_value = workval1;
						 break;
					case 3 : if ( *workptr1 == 5 ) {
							arg_value = balgetw((workptr1 + 3));
							break;
							}
						 else if (( *workptr1 == 0x0085 )
						      && (( arg_value = connect_program_procedure( workptr1 )) != MOINS_UN )) {
								special = 1;
								break;
								}
					case 2 : err_val = 56;
						 procabb2( oldtop );
						 return(SOFTERROR);
					}
				}
			ip_hold [ip_next++] = special;
#endif

			/* Check for a Valid Procedure identifier */
			/* -------------------------------------- */
	 		if ((procid = (arg_value / 16)) >= procmaxid ) {

				/* Invalid procedure identifier */
				/* ---------------------------- */
				TcodeSegment = hsb;
				err_val = ABAL_PRCMAX; 
#ifdef	ABAL21
				procabb2( oldtop );
#else
				procabb2();
#endif
				return(SOFTERROR);
				}

			/* Collect Code Base and Variable Table Base */
			/* ----------------------------------------- */
#ifdef	ABAL21
			while ((TcodeSegment  = (*(TcodeProcTable + procid)).code_segment) == (BPTR) 0)
				if ( load_procedure(TcodeProcTable, procid,SOFTERROR ) == SOFTERROR ) {
					TcodeSegment = hsb;
					procabb2( oldtop );
					return(SOFTERROR);
					}


#else
			TcodeSegment = (*(TcodeProcTable + procid)).code_segment;
#endif
			/* If Procedure has local Variables */
			/* -------------------------------- */
			if ((ptp = (*(TcodeProcTable + procid)).table_segment) != (BPTR) 0) {

				/* If Variables are of DYNAMIC storage CLASS */
					/* ----------------------------------------- */
					if ((  (*(TcodeProcTable + procid)).options & 0x0002) == 0 ) {

						/* Attempt to allocate for LDS */
						/* --------------------------- */
						if ((pdp = (BPTR) allocate( (memsize = (USINT) (Tcodeword( (ptp + 4)))))) == (BPTR) 0) {

							/* Restore Context and Report */
							/* -------------------------- */
							TcodeSegment = hsb;
#ifdef	ABAL21
							procabb2( oldtop );
#else
							procabb2();
#endif
							err_val = 27;
							return(SOFTERROR);
							}					
						memset((BPTR) pdp, 0, (USINT) memsize );

						/* Static Data FALSE */
						/* ----------------- */
						static_local_data = 0;
						}
					else 	{ 
						/* Load Pre-allocated Data Zone Pointer */
						/* ------------------------------------ */
						pdp = (*(TcodeProcTable + procid)).data_segment;

						/* Static Data TRUE */
						/* ---------------- */
						static_local_data = 1;
						}

					/* Create Data Table Pointer Starting Point */
					/* ---------------------------------------- */
					dvp = ptp + 6;
					}
				else	{
					/* Dissable Local Data Segment */
					/* --------------------------- */
					dvp = (BPTR) 0;
					}

				/*	Establish new DATA management 	*/
				/*	-----------------------------	*/
				ddx = (*(TcodeProcTable + procid)).code_length;


			datapnt = Tcodeword( (TcodeSegment + ddx - WORDSIZE));
			if ( datapnt == 0xFFFF ) { 
				/* Indicate No DATA available */
				/* -------------------------- */
				datamax = 0; 
				datadex = 1;
				}
			else 	{
				/* Initialise DATA for READ=0 */
				/* -------------------------- */
				datamax = Tcodeword( (TcodeSegment + ddx - (WORDSIZE * 2)));
				if ( setdata(1) == SOFTERROR ) { 
					TcodeSegment = hsb; 
					lerrval = err_val; 
					(void) procabb(4); 
					err_val = lerrval;
					return(SOFTERROR);
					}
				datadex = 1;
				}

			}
		/* Perform Arguament Transfer */
		/* -------------------------- */
		else 	dvp = (BPTR) vtoproc(arg_type,arg_value,dvp,pdp,reg); 

		/* Check for Errors */
		/* ---------------- */
		if (( dvp == (BPTR) 0) && ( ptp != (BPTR) 0)) {  
			TcodeSegment = hsb; 
			lerrval = err_val; 
			(void) procabb(4); 
			err_val = lerrval;
			return(SOFTERROR);
			}

		/* Part 2 Low  nibble => 2nd of 2 possible Arguaments */
		/* -------------------------------------------------- */
		if ( ((EXAWORD) *xp) & 0x0010 ) {	/* If 2nd Arg Valid   */
			if ((arg_type = (((EXAWORD) *xp)  & 0x0006) >> 1) != 3) {
				arg_value = Tcodeword( fdex); 
				fdex += WORDSIZE;
				TcodePmot( sp,arg_value); 
				sp += WORDSIZE;
				temp_zone_used += WORDSIZE; 
				reg = 0; /* Default Register for Imm Varptrs */
				}
			else 	{
				reg = (EXAWORD) *(fdex++); 
				arg_value = (EXAWORD) freg [reg];
				TcodePmot( sp,reg); 	   sp += WORDSIZE;
				TcodePmot( sp,arg_value);  sp += WORDSIZE;
				TcodePmot( sp,ireg [reg]); sp += WORDSIZE;
				TcodePmot( sp,areg [reg]); sp += WORDSIZE;
				if ( xreg [reg] & PTRSTATUS ) { TcodePmot( sp , VARIABLE ); }
				else			      {	TcodePmot( sp, xreg [reg]); }
				sp += WORDSIZE;
				temp_zone_used += (5 * WORDSIZE); 
				arg_type = ((EXAWORD) xreg [reg] & 0x0803); 
				}

		/*	DO 2nd TRANSFER HERE ( Z points to or is Arguament )	*/
		/* 	----------------------------------------------------	*/
			if ((dvp = (BPTR) vtoproc(arg_type,arg_value,dvp,pdp,reg)) == (BPTR) 0) {
				TcodeSegment = hsb; 
				lerrval = err_val; 
				(void) procabb(4); 
				err_val = lerrval;
				return(SOFTERROR);
				}

			if ( (EXAWORD) *xp & 0x0001 ) 
				xp++;
			else 	{
				arg_counter = 1; 
				break; 
				}	/* ENDIF Valid Next Arg */
			}		/* ENDIF 2nd Valid Arguament */
		else 	{ 
			arg_counter = 1; 
			temp_zone_used += WORDSIZE; 
			break; 
			}	/* End ELSE      */

		}		/* End WHILE (arg_counter) */

	/* Calculate Gosub Base Protection Limit for New Procedure */
	/* ------------------------------------------------------- */
	worktop = (oldtop + temp_zone_used);	

#ifdef	ABAL21
	if ( special != 0 ) {

		minder  [mindex++]  = GlobalDataTable;
		minder  [mindex++]  = GlobalDataSegment;
		minder  [mindex++]  = GlobalConstants;
		minder  [mindex++]  = TcodeConstants;
		collect_indirect_gds();
		}
#endif

#ifdef	ABAL21
	pcp = collect_procedure_constants( procid );
#else
	pcp = (BPTR) TcodeConstants;
#endif
	return( final_procedure_push( hsb, pcp, pdp, ptp, static_local_data ) );

}

#ifdef	ABAL21
EXAWORD	disactivate_procedure()
{
	TcodeSegment = minder [--mindex];
	fdex         = minder [--mindex];
	timersem |= 0x1000;
	return( GOODRESULT );
}

EXAWORD	activate_procedure( arg_value, nature )
EXAWORD	arg_value;
EXAWORD	nature;
{

	minder [mindex++]   = fdex;
	minder [mindex++]   = TcodeSegment;

	TcodeSegment =  TcodeByteStack;
	fdex         = (TcodeByteStack + worktop);

	/* Generate False Tcode Procedure Call */
	/* ----------------------------------- */
	switch ( nature ) {
		case 0x9000 : *fdex = 0x0040; break;
		default     : *fdex = 0; 
		}

	TcodePmot((fdex+1),arg_value);
	*(fdex+3) = _tc_WHN;
	*(fdex+4) = ( _ec_POP | _ec_EXTERN);
	TcodePmot((fdex+5),arg_value);

	worktop += 7;
	timersem &= 0xE000;
	return( call_procedure() );
}

#endif

#ifdef	ABAL21

EXAWORD	indirect_procedure_call( tcptr )
BPTR	tcptr;
{
	fdex = tcptr;
	return( call_procedure() );
}

EXAWORD	indirect_segment_call( tcptr )
BPTR	tcptr;
{
	EXAWORD	segment_number;
#if defined(AVIION)||defined(RT_AIX)||defined(LINUX)
	EXAWORD	ldgo_seg();
#else
	EXAWORD	ldgo_seg( EXAWORD, EXAWORD );
#endif
	/* Workset 1 has been established before this call */
	/* ----------------------------------------------- */
	if ( *workptr1 == SEGMENT_POINTER ) {
		segment_number = balgetw((workptr1+3));
		return( ldgo_seg( segment_number, (fdex - TcodeSegment) ) );	
		}
	else	{
		err_val = 56;
		return( SOFTERROR );
		}
}
#endif

BPTR	ProcedureCodePointer( procid, offset )
EXAWORD	procid;
EXAWORD	offset;
{
	BPTR	bptr;

	if (( bptr = (*(TcodeProcTable + procid)).code_segment) == (BPTR) 0)
		return( bptr );
	else	return( (bptr + offset) );
} 

/* 
 *	F _ R T P ( )
 *	-------------
 *
 *	Retour d'un procedure
 *	Avec retour des valeurs des arguaments ( si necessaire )
 *
 */

EXAWORD	loaded_procedures()
{
	/* execution statistics CONF(62) */
	/* ----------------------------- */
	return( LoadedProcedures );
}


EXAWORD	procedure_callers( procid )
EXAWORD	procid;
{
	return( (*(TcodeProcTable + procid)).callers );
}

EXAWORD	procedure_loaded( procid )
EXAWORD	procid;
{
	if ( (*(TcodeProcTable + procid)).code_segment != (BPTR) 0 )
		return( 1 );
	else	return( 0 );
}


static	VOID	ll_procedure_release( TcodeProcTable, procid, mode )
struct procform SPTR TcodeProcTable;
EXAWORD	procid;
EXAWORD	mode;
{

#ifdef	ABAL21
#if defined(RT_AIX) || defined(AVIION) ||defined(LINUX)
	VOID	release_procedure();
#else
	VOID	release_procedure( struct procform SPTR, EXAWORD );
#endif


	/* Check for and Signal END.PROC */
	/* ----------------------------- */
	if ( mode )
		(*(TcodeProcTable + procid)).options |= 0x0080;

	/* If liberation has been requested or is pending and no users */
	/* ----------------------------------------------------------- */
	if (( (*(TcodeProcTable + procid)).callers == 0 )
	&&  ( (*(TcodeProcTable + procid)).options & 0x0080) )
		release_procedure( TcodeProcTable, procid );

#endif
	return;
}

VOID	clf_procedure_release( procid, mode )
EXAWORD	procid;
EXAWORD	mode;
{

#ifdef	ABAL21
	ll_procedure_release( TcodeProcTable, procid, mode );

#endif
	return;
}

VOID	procedure_release( TcodeProcTable, procid, mode )
struct procform SPTR TcodeProcTable;
EXAWORD	procid;
EXAWORD	mode;
{

#ifdef	ABAL21

	/* Decrement callers usage counter (if not null) */
	/* --------------------------------------------- */
	if ( (*(TcodeProcTable + procid)).callers )
		(*(TcodeProcTable + procid)).callers--;


	ll_procedure_release( TcodeProcTable, procid, mode );

#endif
	return;
}

EXAWORD procedure_exit( exit_type )
EXAWORD	exit_type;		/* 0 EXIT, 1 END.PROC */
{
#ifdef ABALCLP
	BPTR	rp,hp;
	EXAWORD	ri,ac;
	EXAWORD	oldhold;
	EXAWORD	result;
	EXAWORD	whoami=procid;
	struct  procform SPTR MyTable;
	MyTable = TcodeProcTable;

	oldhold = ip_next;

#ifdef	ABAL21
	check_for_error_pop();
#endif

	/* Check for and avoid EVENT processing underway */
	/* --------------------------------------------- */
	if (( timersem & EVENT_EXIST ) != 0 ) 
		ip_next--;

	ip_next = StackHold;

	/*	Recover Callers Arguament details	*/
	/*	---------------------------------	*/
#ifdef	ABAL21
/*	IJM 19/10/1995		*/
#ifndef	LONG_FILE_HANDLES
	if ( ip_hold [ ( ip_next - 10 ) ] == 0 )
		ri = ip_hold [ ( ip_next - 11) ];
	else	ri = ip_hold [ ( ip_next - 13) ];
#else
	if ( ip_hold [ ( ip_next - 10 ) ] == 0 )
		ri = ip_hold [ ( ip_next - 11) ];
	else	ri = ip_hold [ ( ip_next - 12) ];
#endif
#else
	ri = ip_hold [ ( ip_next - 8) ];
#endif

	rp = (TcodeByteStack + ri); hp = rp; ac = 1;

	/*	Check Arguaments for Return value required	*/
	/*	------------------------------------------	*/

do 	{
	ri = (EXAWORD) *(rp++);
	if ( (ri & 0x0080) != 0 ) { /* Alors rend premier Arg value 	*/
		if ( pretval(hp,ac) == SOFTERROR ) { 	
			ProcSwap = 0;
			ip_next = oldhold;
			return(SOFTERROR); 
			}
		}
	ac++;
	if ( (ri & 0x0008) != 0 ) { /* Alors rend 2eme Arg value	*/
		if ( pretval(hp,ac) == SOFTERROR ) { 
			ProcSwap = 0;
			ip_next = oldhold;
			return(SOFTERROR); 
			}
		}
	ac++;
	}
while ( (ri & 0x0001) != 0 );
ProcSwap = 0;

/*
 *	Destack the callers context and initialise his data
 *	---------------------------------------------------
 */
	if ((result = procabb(7)) != SOFTERROR )
		procedure_release( MyTable, whoami, ( exit_type & 1 ) );

	return( result );

				/* Bit 2 : Setdata	      = TRUE
				 * Bit 1 : destack PTRS       = TRUE
				 * Bit 0 : Actual exit value  = 1
				 */
#else
	return(SOFTERROR);
#endif
}

VOID	release_procedure(TcodeProcTable, tabdex )
struct	procform SPTR	TcodeProcTable;
EXAWORD			tabdex;
{
	/* Liberate CS */
	/* ----------- */
#ifdef	DEBUG_END_PROC
	x_cprintf((BPTR)"rp()");
#endif
	if ( (*(TcodeProcTable + tabdex)).code_segment != (BPTR) 0) {
#ifdef	VMS_OPTIMISED
		if (!(UseVmsSection))
#endif
			liberate( (*(TcodeProcTable + tabdex)).code_segment );

		(*(TcodeProcTable + tabdex)).code_segment = (BPTR) 0;

		if ( LoadedProcedures != 0 )
			LoadedProcedures--;

		}


	/* AM 170297 : Liberate Local constant table if Valid */
	/* -------------------------------------------------- */
	if ( (*(TcodeProcTable + tabdex)).const_segment != (BPTR) 0) {

#ifdef	VMS_OPTIMISED
		if (!(UseVmsSection))
#endif
			liberate( (*(TcodeProcTable + tabdex)).const_segment );

		(*(TcodeProcTable + tabdex)).const_segment = (BPTR) 0;
		}



	/* Liberate LDT if Valid */
	/* --------------------- */
	if ( (*(TcodeProcTable + tabdex)).table_segment != (BPTR) 0) {

#ifdef	VMS_OPTIMISED
		if (!(UseVmsSection))
#endif
			liberate( (*(TcodeProcTable + tabdex)).table_segment );

		(*(TcodeProcTable + tabdex)).table_segment = (BPTR) 0;
		}

	/* Liberate LDS if Valid : NB Must Be of STATIC Class */
	/* -------------------------------------------------- */
	if ( (*(TcodeProcTable + tabdex)).data_segment != (BPTR) 0) {
		liberate( (*(TcodeProcTable + tabdex)).data_segment );
		(*(TcodeProcTable + tabdex)).data_segment = (BPTR) 0;
		}
#ifdef	ABAL21
	(*(TcodeProcTable + tabdex)).callers = 0;
	(*(TcodeProcTable + tabdex)).options &= 0x007F;
#endif
	return;
}

VOID	liberate_procedure_table( TcodeProcTable, procmaxid )
struct	procform SPTR 	TcodeProcTable;
EXAWORD			procmaxid;
{

	EXAWORD	tabdex;

	if ( TcodeProcTable != ( struct procform SPTR ) 0 ) { 

		tabdex = 0;

		while ( tabdex < procmaxid ) {

			release_procedure(TcodeProcTable, tabdex );
	
			tabdex++;
			}

		/* Liberate Procedure Table */
		/* ------------------------ */
		liberate( TcodeProcTable );
		TcodeProcTable = ( struct procform SPTR ) 0;

		}
	return;

}
VOID	LiberateProcedureTable( procmaxid )
EXAWORD	procmaxid;
{
	liberate_procedure_table( TcodeProcTable, procmaxid );
	return;
}


/* 
 *	Chargement et Initialisation des procedures
 *	-------------------------------------------
 */

#ifdef	ABAL21

struct procform SPTR load_tcode_procedures( procmaxid , wpb )
EXAWORD	procmaxid;
BPTR	wpb;
{
	EXAWORD			procid;
	struct procform SPTR 	TcodeProcTable;

	procid    = 0; 

	/* Attempt to allocate for Internal Procedure Control Structure */
	/* ------------------------------------------------------------ */
	if ((TcodeProcTable = (struct procform SPTR) allocate( sizeof( struct procform)* procmaxid)) == (struct procform SPTR) 0)
		return( TcodeProcTable );
	else	memset( (BPTR) TcodeProcTable,0, sizeof( struct procform)* procmaxid );

	/* then Load Procedure Code and LD Tables */
	/* -------------------------------------- */
	while ( procid < procmaxid ) {

		/* Load Procedure Control Table Information */
		/* ---------------------------------------- */
		(*(TcodeProcTable + procid)).code_sector  = Tcodeword((wpb));
		(*(TcodeProcTable + procid)).code_length  = Tcodeword((wpb+2));
		(*(TcodeProcTable + procid)).data_sector  = Tcodeword((wpb+4));
		(*(TcodeProcTable + procid)).data_length  = Tcodeword((wpb+6));
#ifdef	ABA21
		(*(TcodeProcTable + procid)).callers      = 0;
#endif
		if (((*(TcodeProcTable + procid)).const_sector = Tcodeword((wpb+8)) ) == MOINS_UN)
			(*(TcodeProcTable + procid)).const_sector = 0;

		if (((*(TcodeProcTable + procid)).const_length = Tcodeword((wpb+10))) == MOINS_UN)
			(*(TcodeProcTable + procid)).const_length = 0;

		/* Collect Options and Check if Overlay or Resident */
		/* ------------------------------------------------ */
		if ((( (*(TcodeProcTable + procid)).options = (Tcodeword((wpb + 14)))) & 0x0008) == 0) {

			/* Attempt to load this Resident procedure */
			/* --------------------------------------- */
			if ( load_procedure(TcodeProcTable, procid, GOODRESULT ) == SOFTERROR ) {

				/* Dismantle Procedure Table */
				/* ------------------------- */
				liberate_procedure_table(TcodeProcTable,procid);

				/* Indicate Procedure Loading Failure */
				/* ---------------------------------- */
				return((struct procform SPTR) 0);

				}

			}

		/* Next Procedure Table Entry */
		/* -------------------------- */
		procid++; wpb += 16;

		}
	return(TcodeProcTable);
}

EXAWORD load_procedure_table()
{
	BPTR	wpb;
	EXAWORD	procid;

	/* Attempt to load Procedure table from Tcode File */
	/* ----------------------------------------------- */
	if ((wpb = (BPTR) kode_lode(adr_tpr,lng_tpr)) == (BPTR) 0)
		return( SOFTERROR );

	/* Initialise Control Variables */
	/* ---------------------------- */
	StackHold = 0;
	LDS_dex   = 0; 	
	procmaxid = lng_tpr / 16; 
	
	TcodeProcTable = (struct procform SPTR) load_tcode_procedures( procmaxid, wpb );

	liberate( wpb );

	if (TcodeProcTable == (struct procform SPTR) 0) {
		err_val = 27;
		return( SOFTERROR );
		}
	else	return( GOODRESULT );
}


#else	/* Not ABAL21 */

#ifdef	ABAL14

EXAWORD load_procedure_table()
{
	EXAWORD sect_proc;
	EXAWORD	leng_proc;
	EXAWORD	sect_data;
	EXAWORD leng_data;

	BPTR	wpb;
	BPTR	tpb;
	BPTR	dpb;
	BPTR	vpb;

	/* Ensure Tcode file is open */
	/* ------------------------- */
	if ( VerifTcode() == SOFTERROR ) {
		return( SOFTERROR );
		}
#ifdef	VMS_OPTIMISED
	/* Attempt to load Procedure table from Tcode File */
	/* ----------------------------------------------- */
	if ((TcodeProcTable = (struct procform SPTR) kode_wr_lode(adr_tpr,lng_tpr)) == (struct procform SPTR) 0) {
		return( SOFTERROR );
		}

#else
	/* Attempt to load Procedure table from Tcode File */
	/* ----------------------------------------------- */
	if ((TcodeProcTable = (struct procform SPTR) kode_lode(adr_tpr,lng_tpr)) == (struct procform SPTR) 0) {
		return( SOFTERROR );
		}
#endif

	/* Initialise Control Variables */
	/* ---------------------------- */
	StackHold = 0;
	LDS_dex   = 0; 	
	procid    = 0; 
	wpb       = (BPTR) TcodeProcTable;
	procmaxid = lng_tpr / 16;

	/* then Load Procedure Code and LD Tables */
	/* -------------------------------------- */
	while ( procid < procmaxid ) {

		/* Initialise Code and Data Pointers */
		/* --------------------------------- */
		dpb = (BPTR) 0; vpb = (BPTR) 0;

		/* Collect Sector and Length from Tcode Table */
		/*------------------------------------------- */
		sect_proc = Tcodeword( (wpb) );
		leng_proc = Tcodeword( (wpb + 2) ); 
	
		/* Reorganise Procedure Options Word */
		/* --------------------------------- */
		(*(TcodeProcTable + procid)).options = (Tcodeword( (wpb + 14) ));

		/* Watch out for REMOVED PROCEDURES (optimised for size ) */
		/* ------------------------------------------------------ */
		if (( sect_proc != 0 ) && ( leng_proc != 0 ) ) {

			/* Attempt to Load Procedure Code from Tcode File */
			/* ---------------------------------------------- */
			if ((tpb = (BPTR) kode_lode(sect_proc,leng_proc)) == (BPTR) 0) {

				/* Dismantle Procedure Table */
				/* ------------------------- */
				LiberateProcedureTable(procid);

				/* Indicate Procedure Loading Failure */
				/* ---------------------------------- */
				return(SOFTERROR);

				}

			/* Collect and Check Procedure Local data Starting Sector */
			/* ------------------------------------------------------ */
			if ( ((sect_data = (Tcodeword( (wpb + 4) ) ))) != 0) {

				/* Collect Local Data Table Length */
				/* ------------------------------- */
				leng_data = Tcodeword( (wpb + 6));

				/* Attempt to load the Procedure Local Data Table */
				/* ---------------------------------------------- */
				if ((dpb = (BPTR) kode_lode(sect_data,leng_data)) == (BPTR) 0) {

					/* Dismantle Procedure Table */
					/* ------------------------- */
					liberate((BPTR) tpb );
					LiberateProcedureTable(procid);

					/* Indicate Procedure Loading Failure */
					/* ---------------------------------- */
					return(SOFTERROR);

					}

				/* Watch out for STATIC procedure variables */
				/* ---------------------------------------- */
				if (((*(TcodeProcTable + procid)).options & 0x0002) != 0 ) {	

					/* Attempt to Initialise Static Variables */
					/* -------------------------------------- */
					if ((vpb = (BPTR) init_data((Tcodeword( (dpb) )),(Tcodeword( (dpb + 4) )),(dpb + 6) )) == (BPTR) 0) {

						/* Dismantle Procedure Table */
						/* ------------------------- */
						liberate((BPTR) tpb );
						liberate((BPTR) dpb );
						LiberateProcedureTable(procid);

						/* Indicate Procedure Loading Failure */
						/* ---------------------------------- */
						return(SOFTERROR);

						}
					}
				else 	{ 
					/* Reset Local Variable Storage Zone Pointer */
					/* ----------------------------------------- */
					vpb = (BPTR) 0; 
					}

				}	/* End IF local variables */
					/* ---------------------- */

			}
		else	{
			/* Procedure is not required */
			/* ------------------------- */
			tpb 		= (BPTR) 0;
			dpb		= (BPTR) 0;
			vpb		= (BPTR) 0;
			leng_proc 	= 0;
			}

		/* Store the established procedure pointers to table */
		/* ------------------------------------------------- */
		(*(TcodeProcTable + procid)).code_segment = tpb;	/* Code  pointer */
		(*(TcodeProcTable + procid)).table_segment = dpb;	/* table pointer */
		(*(TcodeProcTable + procid)).data_segment = vpb; 	/* Data  pointer */
		(*(TcodeProcTable + procid)).code_length = leng_proc;	

		/* Next Procedure Table Entry */
		/* -------------------------- */
		procid++; wpb += 16;

		}			/* End WHILE */
					/* --------- */

	/* Indicate Success */
	/* ---------------- */
	return(1);
}

	/* ------------------ */
#else	/* prior to  ABAL 1.4 */
	/* ------------------ */

EXAWORD load_procedure_table()
{
	EXAWORD	x,y,z;
	EXALONG	a;
	register BPTR	wpb,tpb;
		 BPTR	dpb,vpb;
	EXAWORD sect_proc,leng_proc,sect_data,leng_data,leng_hold;

	StackHold = 0;

	/* Adjust Table Size to Disk Block Size */
	/* ------------------------------------ */
	y = lng_tpr / BLOCK;
	if (lng_tpr % BLOCK) { y++;}
	procmaxid = lng_tpr / 16;
	lng_tpr = y * BLOCK;

	/* Allocate Procedure Table Memory Storage */
	/* --------------------------------------- */
	if ((TcodeProcTable = (struct procform SPTR) allocate(lng_tpr)) != (struct procform SPTR) 0) {
		memset(TcodeProcTable,0,lng_tpr);
		if ( VerifTcode() == SOFTERROR ) {
			liberate(TcodeProcTable);
			TcodeProcTable = (struct procform SPTR) 0; 
			return(SOFTERROR);
			}
		if ( SectRead(TcodeFileHandle, (BPTR) TcodeProcTable,lng_tpr,adr_tpr) == MOINS_UN ) {
			liberate(TcodeProcTable);
			TcodeProcTable = (struct procform SPTR) 0; 
			return(SOFTERROR);
			}
		}
	else 	{ 
		return(SOFTERROR); 
		}


	/* Initialise Variables then Load Procedure Code and LD Tables */
	/* ----------------------------------------------------------- */
	LDS_dex = 0; procid = 0; wpb = (BPTR) TcodeProcTable;
	while ( procid < procmaxid ) {
		sect_proc = Tcodeword( wpb);
		dpb = (BPTR) 0; vpb = (BPTR) 0;

		/* Load in the Procedure CODE	*/
		/*------------------------------*/

		leng_proc = Tcodeword( (wpb + 2)); /* Get Length */
		leng_hold = leng_proc;	/* Duplicate for Storage */
		y = leng_proc / BLOCK; if (leng_proc % BLOCK) { y++; }
		leng_proc = y * BLOCK;

		if ((tpb = (BPTR) calloc(leng_proc,1)) != (BPTR) 0) { /* Allocation de table procedures */
			if ( SectRead(TcodeFileHandle,tpb,leng_proc,sect_proc) == MOINS_UN ) {
				liberate(TcodeProcTable); TcodeProcTable = (struct procform SPTR) 0; 
				free(LDS_base);  LDS_base = (BPTR) 0;
				return(SOFTERROR);
				}
			}
		else 	{ 
			liberate(TcodeProcTable); TcodeProcTable = (struct procform SPTR) 0; 
			free(LDS_base);  LDS_base = (BPTR) 0;
			return(SOFTERROR); 
			}
		if ( ((sect_data = Tcodeword( (wpb + 4) ) )) != 0) {

			/* Load in the Local variable TABLE	*/
			/*--------------------------------------*/
		
			leng_data = Tcodeword( (wpb + 6));
			y = leng_data / BLOCK; if (leng_data % BLOCK) { y++; }
			leng_data = y * BLOCK;
	
			if ((dpb = (BPTR) malloc(leng_data)) != 0) { /* Allocation de table procedures */
				if ( SectRead(TcodeFileHandle,dpb,leng_data,sect_data) == MOINS_UN ) {
					liberate(dpb); liberate(tpb);
					liberate(TcodeProcTable); TcodeProcTable = (struct procform SPTR) 0; 
					free(LDS_base);  LDS_base = (BPTR) 0;
					return(SOFTERROR);
					}
				else 	{	/* Variable Treatment here */
					if ( (*(TcodeProcTable + procid)).options != 0 ) {	
						x = Tcodeword( dpb);
						y = Tcodeword( (dpb + 2));
						z = Tcodeword( (dpb + 4));
						vpb = init_data(x,z,(dpb + 6));	
						}
					else { vpb = (BPTR) 0; }
					}
				}
			else 	{
				liberate(tpb);
				liberate(TcodeProcTable); TcodeProcTable = (struct procform SPTR) 0; 
				free(LDS_base);  LDS_base = (BPTR) 0;
				return(SOFTERROR); 
				}
			}			/* End IF local variables */
	/* 
	 * Store the established procedure pointers in table
	 * ------------------------------------------------- 
	 */

		(*(TcodeProcTable + procid)).code_segment = tpb;	/* Code Segment pointer */
		(*(TcodeProcTable + procid)).table_segment = dpb;	/* Variable table ptr   */
		(*(TcodeProcTable + procid)).data_segment = vpb; 	/* Data segment pointer */
		(*(TcodeProcTable + procid)).code_length = leng_hold;	/* Code length 		*/
		procid++; wpb += 16;
		}			/* End WHILE	*/
	return(1);
}

	/* --------- */
#endif	/* ABAL14    */
	/* --------- */
#endif	/* ABAL21    */
	/* --------- */
#endif	/* _EXPROC_C */
	/* --------- */

