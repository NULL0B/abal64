
/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXPROC.C
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */

/*----------------------------------------------------------------------*/
/*	Reference : EXPROC-DOC																*/
/*----------------------------------------------------------------------*/
 
/*
 * Mises a jour:
 * ------------
 * 13/08/03 : (#BG) Révision complète pour gestion des BSA/BDA compatible avec les Overlays (contextes).
 * 12/09/16 : (#BG) Ajout trace syslog erreur 132 (ABAL_PRCMESS) pour MASSA
 */


#ifndef	_EXPROC_C
#define	_EXPROC_C

#include "exptr.h"

#ifdef WIN32

#ifdef DEBUGGER
#include "exprotdb.h"
#endif
#ifdef WEXADBDLL
#include "pubdgfnc.h"
#endif
#include "extrace.h"

#else

#ifdef DEBUGGER
#include "exproto1.h"
#endif
#include "exasyslog.h"
#endif //WIN32

#include "exmacro.h"
#include "extimer.h"
#include "exevent.h"

BPTR	LDS_base;
EXAWORD	LDS_dex;
EXAWORD	StackHold;
EXAWORD	LoadedProcedures=0;
EXAWORD	calledprocs=0;

EXTERN	EXAWORD	ExQui;
EXTERN	EXAWORD	diezlds;
#ifdef WIN32
EXTERN   EXAWORD  monitor_execution_mode;
#endif


EXAWORD	ca_y_est() {
	/* #BG: Pour poser un point d'arrêt */
	return(1); 
}

EXAWORD	InitQalloc()
{
	/* Allocate Procedure Local Variable Qwick Malloc Zone */
	/* --------------------------------------------------- */
	if (( LDS_base = (BPTR) allocate( diezlds )) == (BPTR) 0 )
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
		if ((lptr = allocate( nboct )) != (VPTR) 0)
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
		liberate( qmemptr );

	return;
}
#endif
#endif

#ifdef  ABAL_REMOTE
EXAWORD procedure_exit_value( EXAWORD v )
{
        xreg[53] = IMMEDIAT;
        freg[53] = v;
        return( GOODRESULT );
}

EXAWORD procedure_exit_string( EXAWORD type, BPTR value, EXAWORD length )
{
        BPTR    sptr;
        StackCheck( length );
        freg [ 53 ] = worktop;
        xreg [ 53 ] = TEMPDESC;
        sptr = (TcodeByteStack + worktop);
        TcodePmot( sptr , type );
        TcodePmot( (sptr + WORDSIZE), length);
        sptr += (2*WORDSIZE);
        memcpy( sptr, value, length );
        worktop  += (length + (2 * WORDSIZE));
        return( GOODRESULT );
}
#endif

/* 
 *	PROCARG( number )
 *	-----------------
 *	Establishs the data set WORKSET2 wrt to the arguament type
 */

EXAWORD procarg(ac)
EXAWORD	ac;
{
	BPTR	dp;
	EXAWORD	cc,x,i,a;

	dp = (BPTR) (LocalDataTable + (3 * WORDSIZE)); cc = 1;

	while ( cc != ac ) {
		x = Tcodeword(dp); dp += (2 * WORDSIZE);
		if (( x & ISDYNAMIC ) && ( x & ISMEMBER ))
			dp += WORDSIZE;
		/* IJM : IMPORTANT */
		if (((x & VARB_ISOL) > 1) &&  ((x & VARB_ISOL) < 4))  
			dp += WORDSIZE;
		if (x & NDX1st) 	  { 
			if (x & NDX2nd)
				dp += (2 * WORDSIZE);
			else
				dp += WORDSIZE;
			}
		cc++;
		}

	worktyp2 = Tcodeword(dp); 
	if ( worktyp2 & ISDYNAMIC )
		return( 0 );
	dp += WORDSIZE;
	workptr2 = LocalDataSegment + Tcodeword(dp); 
	dp += WORDSIZE;

	switch (worktyp2 & VARB_ISOL) 
	{
	case VARB_FOUR  :
	case VARB_INT8  :
		worklen2 = 1;
		break;
	case VARB_INT16 :
		worklen2 = 2;
		break;
	case VARB_INT32 :
		worklen2 = 4;
		break;
	case VARB_INT64 :
		worklen2 = 8;
		break;
	default		:
		worklen2 = Tcodeword(dp); 
		dp += WORDSIZE; 
	}

	if (worktyp2 & NDX1st) { 
		
		i = Tcodeword(dp);
		if (worktyp2 & NDX2nd) {
		 
			dp += WORDSIZE; 
			a = Tcodeword(dp); 
		}
		else	a = 1;
	}
	else 
	{
		i = 1;
		a = 1;
	}

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
	EXAWORD	hws;
#endif

	BPTR	hb3,hb4;
	EXAWORD	special;
	EXAWORD	wurdsize;

	/*	Establish WORKSET2 wrt procedure local Variable		*/
	/*	-----------------------------------------------		*/
	/* Zero means Dynamic Variable Reference so No Recopie is required */
	/* --------------------------------------------------------------- */
	if (procarg(ac -1) == 0 ) 
		return(1);

	if ( ip_hold[ (ip_next - 5)] & ISLOCAL3  ) 
	{
		wurdsize = WORD16SIZE;
	}
#ifdef	ABAL64
	else 	
	{
		wurdsize = WORD64SIZE;
	}
#else
	else 	
	{
		wurdsize = WORD32SIZE;
	}
#endif

	/*	Collect destination DATA arguament 	*/
	/*	----------------------------------	*/

	dc = 0; x = 0; api = 0;
	do 
	{	
		if ( x == 0 ) 
		{
		 
			work = (EXAWORD) *(bp++); x = 1; dc++;
			arg = (work & 0x00F0) >> 4; 
		}
		else 
		{ 
			dc++; arg = (work & 0x000F); x = 0; 
		}
		if ( dc != ac ) 
		{
			switch ( (arg & 0x0006) >> 1 ) 
			{
				case 0x0000 :
				case 0x0001 :
				case 0x0002 :
					api += wurdsize;
					break;
				case 0x0003 :
					api += (5 * wurdsize);
					break;
			}
		}
	}
	while ( ( dc != ac ) && (( arg & 0x0001 ) != 0) );

	/*	Check for Errors	*/
	/*	----------------	*/

	if ( dc != ac ) 
	{
		err_val = ABAL_ARGTYPE; 
		return(SOFTERROR); 
	}

	/*	Position to Arg Values	*/
	/*	---------------------	*/

	if ( (arg & 0x0001) != 0 ) 
	{
        	do 
		{
        		if ( x == 0 ) 
			{ 
        			if ( ((work = *(bp++)) & 0x0010 ) == 0 )
					x = 2; 
        			else 	x = 1; 
        		}
        		else 
			{
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
	hws		 = WORDSIZE;
	if ( ip_hold[ (ip_next - 5)] & ISLOCAL3  ) 
	{
		ISLOCAL = ISLOCAL3;
		TOGLOBAL = TOGLOBAL3;
#ifndef	ABAL64
		WORDSIZE = WORD16SIZE;
#endif
	}
	else 
	{
		ISLOCAL = ISLOCAL4;
		TOGLOBAL = TOGLOBAL4;
#ifndef	ABAL64
		WORDSIZE = WORD32SIZE;
#endif
	}
#endif
 
	hb1 		 = LocalDataTable; 
	hb2 		 = LocalDataSegment;
	LocalDataTable   = minder [ ( mindex - 2 ) ]; 
	LocalDataSegment = minder [ ( mindex - 1 ) ];


	/* Check for Far Call Context */
	/* -------------------------- */
	/*	IJM 19/10/1995		*/
#ifdef	LONG_FILE_HANDLES
	if ((special = ip_hold [ ( ip_next -  10) ]) != 0 ) 
	{
		hb3 = GlobalDataTable;
		hb4 = GlobalDataSegment;
		GlobalDataSegment = minder [ ( mindex - 8 /* 7 */ ) ];
		GlobalDataTable   = minder [ ( mindex - 9 /* 8 */ ) ];
	}
#else
	if ((special = ip_hold [ ( ip_next - 10 ) ]) != 0 ) 
	{
		hb3 = GlobalDataTable;
		hb4 = GlobalDataSegment;
		GlobalDataSegment = minder [ ( mindex - 8 /* 7 */ ) ];
		GlobalDataTable   = minder [ ( mindex - 9 /* 8 */ ) ]; 
	}
#endif

	attreg = 0;
	switch ( (arg & 0x0006) >> 1 ) {
        case VARIABLE :
			work = Tcodeword(bp); bp += WORDSIZE;
		 	if (argsetw(5,work) == SOFTERROR) 
				return(SOFTERROR);
		 	break;
        case TEMPDESC :
			reg = Tcodeword(bp); bp += WORDSIZE;
		 	freg [reg] = Tcodeword(bp); bp += WORDSIZE;
		 	ireg [reg] = Tcodeword(bp); bp += WORDSIZE;
		 	areg [reg] = Tcodeword(bp); bp += WORDSIZE;
		 	xreg [reg] = Tcodeword(bp); bp += WORDSIZE;
			if ( xreg [reg] == IMMEDIAT ) 
				attreg = 1;
			else if (argsetw(4,reg) == SOFTERROR)
				return(SOFTERROR);
		 	break;
        default       :
			err_val = ABAL_ARGTYPE;
			return(SOFTERROR);
        }

	LocalDataTable = hb1;
	LocalDataSegment = hb2;
#ifdef	VERSION_XX
	ISLOCAL = hil; TOGLOBAL = htg;
	WORDSIZE= hws;
#endif

	if ( special ) {
		GlobalDataTable = hb3;
		GlobalDataSegment = hb4;
		}
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
	else 
	{
		switch ( worktyp2 ) 
		{
		case VARB_FOUR  :
		case VARB_INT8  :
			freg [reg] = (BINAIRE) ReadSchar( workptr2 ); 
			break;
		case VARB_INT16 :
			freg [reg] = balgetw( workptr2 );
			break;
		case VARB_INT32 :
			freg [reg] = balgetl( workptr2 );
			break;
		case VARB_INT64 :
			freg [reg] = balget64( workptr2 );
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
		case TEMPDESC   :
			err_val = ABAL_TCODFILE;
			return(SOFTERROR);
		case PTRSTR	:
		case PTRBCD	:
			sbase = preg [reg];
			break;
		case VARIABLE   :
			if (avalu & ISLOCAL) {
				sbase = (LocalDataTable + (avalu & TOGLOBAL) + WORDSIZE);	
				sbase = (LocalDataSegment + Tcodeword(sbase));
				}
			else {
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
					else {
						err_val = ABAL_PROCARG;
						return(SOFTERROR); 
					}
				}
			else
				sbase = (GlobalDataSegment + Tcodeword( (sbase + WORDSIZE) )); 
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

#ifdef	ABAL64
#define TargetWord( w, p ) ( w == 2 ? (TcodeWord16((p))) : (w == 4 ? (TcodeWord32((p))) : (TcodeWord64((p))) ) )
#else
#define TargetWord( w, p ) ( w == 2 ? (TcodeWord16((p))) : (TcodeWord32((p))) )
#endif

static	char * OLDPROCALIAS="\0=OLDPROCALIAS";

BPTR	vtoproc(atype,avalu,vdesc,vbase,reg,tws)
EXAWORD	atype;			/* Type of Arguament ival,cptr,vptr,tmp  */
EXAWORD	avalu;			/* Arguament Value 			 */
BPTR	vdesc;			/* Procedure Variable descriptor pointer */
BPTR	vbase;			/* Procedure data storage base 		 */
EXAWORD	reg;			/* Register to use for Indexes if needed */
EXAWORD	tws;			/* Target Context Word Size		 */
{
	register	EXAWORD	pvtype;
	EXAWORD	pvindex,pvandex,pvleng;
	EXAWORD	memref=REFERENCED_POINTER;

	/* Establish Default Error Value */
	/* ----------------------------- */
	err_val = ABAL_PRCMESS;	

	/* IJM : 3.1a : Cristallin bug */
	if ((!vdesc) || (!vbase)) {
#ifdef ABAL_SYSLOG
		if (IsExaSysLog() & SYSLOG_PROC) {
			sprintf(SysLogBuffer, "Error: vtoproc: Step 1, err=%d", err_val);
			ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
			}
#endif
		return((BPTR) 0);
		}

	/* Get destination data type */
	/* ------------------------- */
	pvtype = TargetWord( tws, vdesc );
	
	/* Ensure Arguament and Corrent Value */
	/* ---------------------------------- */
	if ( ((pvtype & VARB_ARG) == 0) || ( pvtype == MOINS_UN )) { 
		err_val = ABAL_PROCARG;
#ifdef ABAL_SYSLOG
		if (IsExaSysLog() & SYSLOG_PROC) {
			sprintf(SysLogBuffer, "Error: vtoproc: Step 2, err=%d", err_val);
			ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
			}
#endif
		return((BPTR) 0); 
		} /* Erreur NOT arguament or End of Procedure Variable Table ! */
	else {
		/* Check for REFERENCER Reception Variable */
		/* --------------------------------------- */
		if (!( pvtype & ISDYNAMIC )) {

			vdesc += tws; /* Advance Descriptor pointer to storage pointer */
			vbase += TargetWord(tws,vdesc); /* Calculate Variable storage zone */
			vdesc += tws; /* Advance Descriptor pointer to length or indices */
			/* ----------------------------------------------------- */
			/* IJM : IMPORTANT 32 BIT INTEGER CORRECTION : 12/7/2006 */
			/* ----------------------------------------------------- */
			switch (pvtype & VARB_ISOL) {
				case VARB_FOUR  :
				case VARB_INT8  :
					pvleng = 1;
					break;
				case VARB_INT16 :
					pvleng = 2;
					break;
				case VARB_INT32 :
					pvleng = 4;
					break;
				case VARB_INT64 :
					pvleng = 8;
					break;
				default		:
					pvleng = TargetWord( tws, vdesc );
					vdesc += tws;
				}

			if ( (pvtype & NDX1st) != 0 ) {
				pvindex = TargetWord(tws,vdesc);
				vdesc += tws;
				}
			else 
				pvindex = 1;

			if ( (pvtype & NDX2nd) != 0 ) {
				pvandex = TargetWord(tws,vdesc);
				vdesc += tws;
				}
			else
				pvandex = 1; 

			/* Test for Matrix Reception */
			/* ------------------------- */
			if ((pvindex + pvandex) > 2 ) { 

				/* Perform Matrix Transfer */
				/* ----------------------- */
				if ( cpymrx(atype,avalu,vbase,(pvleng * pvindex * pvandex ),reg) != SOFTERROR )
					return(vdesc);
				else {
#ifdef ABAL_SYSLOG 
					if (IsExaSysLog() & SYSLOG_PROC) {
						sprintf(SysLogBuffer, "Error: vtoproc: Step 3, err=%d", err_val);
						ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
						}
#endif
					return((BPTR) 0); 
					}
				}
			}
		else {
			/* The Arguament Reception Variable is a Pointer */
			/* --------------------------------------------- */
			/* Calculate Pointer Location */
			/* -------------------------- */
			vbase += TargetWord(tws,(vdesc+tws)); 	

			/* Step over pointer description */
			/* ----------------------------- */
			switch ((pvtype & VARB_ISOL)) 
			{
				case	VARB_INT8	:
				case	VARB_INT16	:
				case	VARB_INT32	:
				case	VARB_INT64	:
					vdesc += (2 * tws);
					break;
				default :
					vdesc += (3 * tws);
					break;
			}

			if (pvtype & NDX1st)
				vdesc += tws;
			if (pvtype & NDX2nd)
				vdesc += tws;
			}
		}

	switch ( atype ) { 
		/* Convert arg types to data type,length,pointer */
		/* --------------------------------------------- */
		case IMMEDIAT :
			workval1 = avalu;
			worktyp1 = VARB_INT16;
			break;
		case KONSTANT :
			if ( argset(6,avalu,1) == SOFTERROR) {
#ifdef ABAL_SYSLOG
				if (IsExaSysLog() & SYSLOG_PROC) {
					sprintf(SysLogBuffer, "Error: vtoproc: Step 4, err=%d", err_val);
					ExaSysLog(,EXA_SYSLOG_ERROR SysLogBuffer);
					}
#endif
				return((BPTR) 0);
				}
		 	break;
		case VARIABLE :
			freg [reg] = avalu;
			xreg [reg] = VARIABLE;
			if ((memref = argset(4,reg,1)) == SOFTERROR) 
			{
				if ( err_val == 118 )
					workptr1 = (BPTR) 0;
				else 
				{
#ifdef ABAL_SYSLOG
					if (IsExaSysLog() & SYSLOG_PROC) 
					{
						sprintf(SysLogBuffer, "Error: vtoproc: Step 5, err=%d", err_val);
						ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
					}
#endif
					return((BPTR) 0);
				}
			}
	  		break;
		case PTRSTR   : 
		case PTRBCD   :
			workptr1 = preg [reg];
			worklen1 = lreg [reg];
			worktyp1 = atype & VARB_ISOL;
			break;
		case TEMPDESC :
			if ( argset(7,avalu,1) == SOFTERROR ) { 
#ifdef ABAL_SYSLOG
				if (IsExaSysLog() & SYSLOG_PROC) {
					sprintf(SysLogBuffer, "Error: vtoproc: Step 6, err=%d", err_val);
					ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
					}
#endif
				return((BPTR) 0);
				}
		 	break;
		}

	if ( pvtype & ISDYNAMIC ) {
		memset( (BPTR) vbase, 0, PTRSIZE );
		if ( workptr1 != (BPTR) 0 )
			if ( *OLDPROCALIAS ) {
				memref = REFERENCED_POINTER;
				}
			establish_pointer_variable((BPTR) vbase, (BPTR) workptr1, memref );
		return( vdesc );
		}

	switch ( worktyp1 ) {	/* Select WRT source data type (# or % , BCD , STR */
		case VARB_FOUR  :
		case VARB_INT8  :
			switch ( pvtype & VARB_ISOL ) {
				case VARB_FOUR  :
				case VARB_INT8  :
					*vbase = *workptr1;
					break;
				case VARB_INT16 :
					balputw((EXAWORD) workval1,vbase);
					break;
				case VARB_INT32 :
					balputl((EXAWORD) workval1,vbase);
					break;
				case VARB_INT64 :
					balput64((EXAWORD) workval1,vbase);
					break;
				case VARB_BCD   :
					itobcd(workval1,vbase,pvleng);
					break;
				case VARB_STR   :
					if ( pvleng > 6 ) 
						itoa(workval1,vbase,pvleng);
						/* Str too short 4 int */
					else {
#ifdef ABAL_SYSLOG
						if (IsExaSysLog() & SYSLOG_PROC) {
							sprintf(SysLogBuffer, "Error: vtoproc: Step 7, err=%d", err_val);
							ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
							}
#endif
						return((BPTR) 0); 
						}
				}
			break;

		case VARB_INT16 :
			switch ( pvtype & VARB_ISOL ) {
				case VARB_FOUR  :
				case VARB_INT8  :
					*vbase = (EXABYTE) workval1;
					break;
				case VARB_INT16 :
					balputw((EXAWORD) workval1,vbase);
					break;
				case VARB_INT32 :
					balputl((EXAWORD) workval1,vbase);
					break;
				case VARB_INT64 :
					balput64((EXAWORD) workval1,vbase);
					break;
				case VARB_BCD   :
					itobcd(workval1,vbase,pvleng);
					break;
				case VARB_STR   :
					if ( pvleng > 6 )
						itoa(workval1,vbase,pvleng);
					else {
#ifdef ABAL_SYSLOG
						if (IsExaSysLog() & SYSLOG_PROC) {
							sprintf(SysLogBuffer, "Error: vtoproc: Step 8, err=%d", err_val);
							ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
						}
#endif
						return((BPTR) 0);
					}
				}
			break;

		case VARB_INT32 : 
			switch ( pvtype & VARB_ISOL ) {
				case VARB_FOUR  :
				case VARB_INT8  : 
				case VARB_INT16 : 
				case VARB_INT32 :
					balputl((EXAWORD) workval1,vbase);
					break;
				case VARB_INT64 :
					balput64((EXAWORD) workval1,vbase);
					break;
				case VARB_BCD   :
					ltobcd(workval1,vbase,pvleng);
					break;
				case VARB_STR   :
					if ( pvleng > 24 )
						ltoa(workval1,vbase,pvleng);
					else {
#ifdef ABAL_SYSLOG
						if (IsExaSysLog() & SYSLOG_PROC) {
							sprintf(SysLogBuffer, "Error: vtoproc: Step 9, err=%d", err_val);
							ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
							}
#endif
						return((BPTR) 0);
					}
				}
			break;

		case VARB_INT64 : 
			switch ( pvtype & VARB_ISOL ) 
			{
			case VARB_FOUR  :
			case VARB_INT8  : 
			case VARB_INT16 : 
			case VARB_INT32 :
				balputl((EXAWORD) workval1,vbase);
				break;
			case VARB_INT64 :
				balput64((EXAWORD) workval1,vbase);
				break;
			case VARB_BCD   :
				htobcd(workval1,vbase,pvleng);
				break;
			case VARB_STR   :
				if ( pvleng > 24 )
					ltoa(workval1,vbase,pvleng);
				else 
				{
#ifdef ABAL_SYSLOG
					if (IsExaSysLog() & SYSLOG_PROC) 
					{
						sprintf(SysLogBuffer, "Error: vtoproc: Step 9, err=%d", err_val);
						ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
					}
#endif
					return((BPTR) 0);
				}
			}
			break;

		case VARB_BCD   :
			switch ( pvtype & VARB_ISOL ) {
				case VARB_FOUR  :
				case VARB_INT8  :
					*vbase = (EXABYTE) bcdtoi(workptr1,worklen1);
					break;
				case VARB_INT16 :
					balputw((EXAWORD) bcdtoi(workptr1,worklen1),vbase);
					break;
				case VARB_INT32 :
					balputl((EXAWORD) bcdtol(workptr1,worklen1),vbase);
					break;
				case VARB_INT64 :
					balput64((EXAWORD) bcdtoh(workptr1,worklen1),vbase);
					break;
				case VARB_BCD   :
					/* Check for Filler Required */
					/* ------------------------- */
					if ( pvleng > worklen1 ) {
						worklen2 = worklen1; 
						worklen3 = (pvleng - worklen1);
						}
					/* Else No Filler Required */
					/* ----------------------- */
					else { 
						worklen2 = pvleng;   
						worklen3 = 0;
						}

					/* Tranfer to Procedure Variable */
					/* ----------------------------- */
					(VOID) memcpy((BPTR) vbase, (BPTR) workptr1, (USINT) worklen2 );

					/* Perform Filler if Needed */
					/* ------------------------ */
					if ( worklen3 > 0 )
						(VOID) memset((BPTR) (vbase + worklen2), (((*workptr1 & 0x00F0) == 0x0040) ? 0 : MOINS_UN), (USINT) worklen3);

					/*  memcpy(vbase,workptr1,pvleng); */
					break;

				case VARB_STR   :
					bcdtoa(workptr1,worklen1,vbase,pvleng);
				}
			break;

		case VARB_STR   :
			switch ( pvtype & VARB_ISOL ) {
				case VARB_FOUR  :
				case VARB_INT8  :
					*vbase = (EXABYTE) atoi(workptr1,worklen1);
					break;
				case VARB_INT16 :
					balputw((EXAWORD) atoi(workptr1,worklen1),vbase);
					break;
				case VARB_INT32 :
					balputl((EXAWORD) atol(workptr1,worklen1),vbase);
					break;
				case VARB_INT64 :
					balput64((EXAWORD) atoh(workptr1,worklen1),vbase);
					break;
				case VARB_BCD   :
				   atobcd(workptr1,vbase,pvleng,worklen1);
				   break;
				case VARB_STR   :
					/* Check for Filler Required */
					/* ------------------------- */
					if ( pvleng > worklen1 ) {
						worklen2 = worklen1;
						worklen3 = (pvleng - worklen1);
						}
					/* Else No Filler Required */
					/* ----------------------- */
					else {
						worklen2 = pvleng;
						worklen3 = 0;
						}

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
	else
		--ip_next;

	/* Common part of procedure abandon mechanism */
	/* ------------------------------------------ */
	datadex = (EXAWORD) ip_hold [--ip_next];
	datapnt = (EXAWORD) ip_hold [--ip_next];
	datamax = (EXAWORD) ip_hold [--ip_next];
	procid  = (EXAWORD) ip_hold [--ip_next];
	
	/* this should have been done years ago */
	/* ------------------------------------ */
	setdata(datadex);

	return;
}

EXAWORD	CallProcFar;
EXTERN	OVLOBJPTR	TcodeContext;

EXAWORD	procabb( level )
EXAWORD	level;
{
	EXAWORD	v;
	EXAWORD	tv;
	EXAWORD	he;
	EXAWORD	ev;
	EXAWORD	dieze_mem_usage;
	/* #BG 24/06/19 Pour trace */
	BPTR	eptr1, eptr2;
	BPTR	trace_tcode_filename();

	MI_TRACE_DCL_TFN("procabb");

	eptr1 = trace_tcode_filename();

	dieze_mem_usage = workhold;

	if ( level & 2 ) {	/* If Destack part 2 required */

		/* Recover Stack, Timer and Event Context */
		/* -------------------------------------- */
		StackHold =  (EXAWORD)  ip_hold [--ip_next];
		eventadr  =  (EXAWORD)  ip_hold [--ip_next];
		v = (EXAWORD)  ip_hold [--ip_next];

		/* we can ignore this now */
		/* ---------------------- */
		he = (EXAWORD)  ip_hold [--ip_next];

		switch (( timersem & EVENT_KEEP )) {
			case	EVENT_CALL 	:
				v = ( EVENT_CALL | (v & EVENT_WIPE));
				break;
			case	EVENT_VARB	:
				v = ( EVENT_VARB | (v & EVENT_WIPE));
				break;
			default :
				break;
			}

		if (!( timersem & TIME_CALL ))
			timersem = v;
		else
			timersem = ((v & TIME_RAZ) | ( timersem & ~TIME_RAZ ));

		enable_hard_event();

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
#ifndef	ABAL64
			WORDSIZE=WORD16SIZE;
#endif
			}
		else	{
			ISLOCAL=ISLOCAL4;
			TOGLOBAL=TOGLOBAL4;
#ifndef	ABAL64
			WORDSIZE=WORD32SIZE;
#endif
			}
#endif
		/* Destack LDS status flag */
		/* ----------------------- */
		if (ip_hold [--ip_next] == 0)
			if ( LocalDataSegment != (BPTR) 0 ) {
				liberate(LocalDataSegment);
				LocalDataSegment = (BPTR) 0;
			}

		/* Collect Gosub Stack protection limit */
		/* ------------------------------------ */
		workhold  =  (EXAWORD) 	ip_hold [--ip_next];
		pushhold  =  (EXAWORD)	ip_hold [--ip_next];
		/* Collect Code and Data Base Pointers */
		/* ----------------------------------- */
		LocalDataSegment    =  minder [--mindex];
		LocalDataTable      =  minder [--mindex];
		TcodeSegment 	    =  minder [--mindex];

		/* Recover Previous Constant Table Pointer */
		/* --------------------------------------- */
		TcodeConstants	    = minder [--mindex];
		
		/* Recover callers error trap context */
		/* ---------------------------------- */
/*		if ( sicico & ERROR_TEST )	*/
			GlobalErrorTrap = (ERRORPTR) minder [--mindex];

		/* Establish Tcode Return Adresse */
		/* ------------------------------ */
		fdex      =  (TcodeSegment + (EXAWORD) ip_hold [--ip_next]);

		}

	if ((CallProcFar = ip_hold [ --ip_next ]) != 0 ) {
		/* Restore working environment */

#ifndef	LONG_FILE_HANDLES
		TcodeFileHandle   = ip_hold [ --ip_next ];
#endif

		procmaxid         = ip_hold [ --ip_next ];
		TcodeConstants    = minder  [ --mindex  ];
		GlobalConstants   = minder  [ --mindex  ];
		GlobalDataSegment = minder  [ --mindex  ];
		GlobalDataTable	  = minder  [ --mindex  ];
#ifdef WIN32
		TcodeFileName   = minder  [ --mindex  ];	/* #BG 17/10/01 */

		/* #BG 24/06/19 Trace le nom du fichier TCode courant (si changement) conjointemant aux assignations
		   pour mettre en evidence un eventuel buffer MC invalide car declare dans un autre TCode (cf pb EIS, ARGA)
		*/
		if (strcmp(TcodeFileName, TcodeContext->filename))
			MI_TRACE((CI_TRA_F_INFO_HIGH,ID_KERNEL|ID_ASSIGN,TFN, "TcodeFileName=%s -> %s", TcodeContext->filename, TcodeFileName));
#endif

#ifdef	LONG_FILE_HANDLES
		if ((TcodeFileHandle   = (EX_FILE_HANDLE) minder  [ --mindex  ]) == EX_UNUSED_HANDLE)
			ca_y_est();
#endif

#ifdef	DEBUGGER
		force_debug_context((BPTR) ( minder [ --mindex ] ));	/* #BG 27/03/17 DEBUGPTR non defini ici */
#endif
		TcodeContext	  = (OVLOBJPTR) minder  [ --mindex  ]; 
		FuseBase         = TcodeContext->libraries;
		FuseCount        = TcodeContext->nbdll;
		TcodeProcTable	  = (struct  procform PTR) minder  [ --mindex  ];
		ExportTable       = TcodeContext->callbacks;
 #ifdef WEXADBDLL
		if (monitor_execution_mode==1)
			StepIntoTrapClean();
		ReloadBreakList();
 #endif
		}

	procabb2( dieze_mem_usage );

	/* Reinitialise DATA manager */
	/* ------------------------- */
	if ( datadex < datamax ) 
	{
		if ( level & 4 ) 
			level &= setdata(datadex);
	}
	else
		level = 1; 

	if ( err_val == 0 ) 
	{
		err_val = ABAL_PRCMESS;	
	}

#ifdef ABAL_SYSLOG
	/* #BG 24/06/19 Trace le nom du fichier TCode courant (si changement) conjointemant aux assignations
	   pour mettre en evidence un eventuel buffer MC invalide car declare dans un autre TCode (cf pb EIS, ARGA)
	*/
	eptr2 = trace_tcode_filename();
	if ((eptr1 != (char*)0) && (eptr2 != (char*)0))
		if (strcmp(eptr1, eptr2))
			MI_TRACE((CI_TRA_F_INFO_HIGH,ID_KERNEL|ID_ASSIGN,TFN, "TcodeFileName=%s -> %s", eptr1, eptr2));
#endif

	return(level & 1);
}

/* 
 *	F _ C L P ( )
 *	-------------
 *
 *	Appel d'un procedure
 *	--------------------
 */


/*
 *	L O A D _ P R O C E D U R E ( procedure_identity )
 *	--------------------------------------------------
 *
 */

static	EXAWORD	load_procedure(TcodeProcTable, procid, failure )
struct  procform PTR	TcodeProcTable;
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
	||  ( (*(TcodeProcTable + procid)).code_length == 0 )) {
		err_val = ABAL_PRCMAX;
		return( failure );
		}

/* A garder!
#ifdef _DEBUG
#ifndef WEXADBDLL
// #BG 22/08/11 Pour debug. 
	{
		BPTR bpItem = NULL;
		bpItem = (BPTR)get_procedure_name(procid * (8*WORDSIZE));
		bpItem = NULL;
	}
#endif
#endif
*/
	/* Attempt to Load Procedure Code from Tcode File */
	/* ---------------------------------------------- */
	if ((   (*(TcodeProcTable + procid)).code_segment = (BPTR) kode_lode(
		(*(TcodeProcTable + procid)).code_sector ,
		(*(TcodeProcTable + procid)).code_length )) == (BPTR) 0)

		return( SOFTERROR );

	else
		LoadedProcedures++;

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
	if ( ((*(TcodeProcTable + procid)).data_sector == 0) || ((*(TcodeProcTable + procid)).data_length == 0) )
#ifdef WIN32
	{
#ifdef	DEBUGGER
		/* EXADB Can now Position any BREAK POINTS */
		/* #BG: Usefull for breaks in procedures loaded dynamically (,d) */
		/* --------------------------------------- */
		if ( sicico & (ONSEM_SEG | ONSEM_PRC))
			(void) ProcedureTrapWork( 1, procid );
#endif

		return( GOODRESULT );
	}
#else
		return( GOODRESULT );
#endif

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
		/*#BG 07/10/16 Respecter ce parenthesage sous peine de pcrash ! */
		if ( ( (*(TcodeProcTable + procid)).data_segment =
			(BPTR) init_data( Tcodeword(dpb), Tcodeword((dpb + (2*WORDSIZE))), (dpb + (3*WORDSIZE)) )
			 ) == (BPTR) 0)
			return(SOFTERROR);

#ifdef	DEBUGGER
	/* EXADB Can now Position any BREAK POINTS */
	/* --------------------------------------- */
/* #BG: Needed for procedures loaded dynamically (,d) */
	if ( sicico & (ONSEM_SEG | ONSEM_PRC))
		(void) ProcedureTrapWork( 1, procid );
#endif

	/* Indicate Success */
	/* ---------------- */
	return( GOODRESULT );
}


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

VOID	special_procedure_push()
{
#ifdef	DEBUGGER
	BPTR	active_debug_context(VOID);
#endif
	minder  [mindex++]  = (BPTR) TcodeProcTable;
	minder  [mindex++]  = (BPTR) TcodeContext;
#ifdef	DEBUGGER
	minder  [mindex++]  = (BPTR) active_debug_context();
#endif
#ifdef	LONG_FILE_HANDLES
	if ((minder  [mindex++] = (BPTR) TcodeFileHandle) == EX_UNUSED_HANDLE)
		ca_y_est();;
#endif
#ifdef WIN32
	minder  [mindex++] = (BPTR) TcodeFileName;	/* #BG 17/10/01 */
#endif
	ip_hold [ip_next++] = procmaxid;
#ifndef	LONG_FILE_HANDLES
	ip_hold [ip_next++] = TcodeFileHandle;
#endif
	return;
}

EXAWORD	initial_procedure_push()
{
	/* Ensure stacks offer sufficient depth for the context push */
	/* --------------------------------------------------------- */ 
	if ((( ip_next + 17 ) >= diezstk) ||  (( mindex + 13) >= diezstk ) ) {
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
	else {
		sicico &= ~ISLOCAL3;
		}
#endif
	return( GOODRESULT );

}

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
	ip_hold [ip_next++] = pushhold; 
	ip_hold [ip_next++] = workhold; 

	/* Calculate current Temporary Zone Base Limit */
	/* ------------------------------------------- */
	workhold = worktop;
	pushhold = pushtop;

	/* Stack up TIMER,EVENT and Flags */
	/* ------------------------------ */
	ip_hold [ip_next++] = static_local_data;
	ip_hold [ip_next++] = sicico;
	ip_hold [ip_next++] = HardEvent;
	ip_hold [ip_next++] = timersem;
	ip_hold [ip_next++] = eventadr;

	ip_hold [ip_next++] = StackHold;

	/* Establish Stack Protection */
	/* -------------------------- */
	StackHold = ip_next;

	/* Cancel Possible EVENT activity */
	/* ------------------------------ */
	timersem &= EVENT_SEMOFF;

	disable_hard_event();

	/* Check for and Save Callers Error Trap Context */
	/* --------------------------------------------- */	
	minder [mindex++] = (BPTR) GlobalErrorTrap;

	/* Reset to ON ERROR ABORT for starting procedure */
	/* ---------------------------------------------- */
	GlobalErrorTrap = (ERRORPTR) 0;
	sicico &= ( OFSEM_ERR & OFSEM_TRP );

	/* Perform Global to Local Constant Table Stacking and Swap */
 	/* -------------------------------------------------------- */
	minder [mindex++]   = TcodeConstants;
	TcodeConstants 	    = pcp;

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

	if ( procid != MOINS_UN )
		(*(TcodeProcTable + procid)).callers++;

#ifdef	VERSION_XX
	finalise_indirection();
#endif
	return( GOODRESULT );

}

#ifdef	ABAL4
EXAWORD		add_remote_value( BPTR rptr, BPTR type, EXAWORD value, EXAWORD bytes )
{
	EXAWORD	mask;
	EXAWORD	shift;
	sprintf(rptr,"%s ",type);
	rptr += strlen( rptr );
	switch ( bytes )
	{
	case	1 : mask = 0x00FF; shift = 0;  break;
	case	2 : mask = 0x00FF00; shift = 8;  break;
	case	4 : mask = 0x00FF000000; shift = 24; break;
#ifdef	ABAL64
	case	8 : mask = 0x00FF00000000000000; shift = 56; break;
#endif
	default	  : return( SOFTERROR );
	}
	while ( bytes-- )
	{
		sprintf(rptr,"%02.2X",((value & mask) >> shift));
		rptr += 2;
		mask >>= 8;
		shift -= 8;
	}
	*(rptr++) = ' ';
	*(rptr++) = 0;
	return( GOODRESULT );
}

VOID	add_remote_string( BPTR wptr, BPTR type, BPTR value, EXAWORD length )
{
	sprintf(wptr,"%s %u ",type,length);
	wptr += strlen( wptr );
	while ( length-- )
	{
		sprintf(wptr,"%02.2X",(*(value++) & 0x00FF));
		wptr += 2;
	}		
	*(wptr++) = ' ';
	*(wptr++) = 0;
	return;
}

BPTR	add_remote_parameter( BPTR rptr, EXAWORD type, EXAWORD argc )
{
	if ( argset1( type, 0 ) == SOFTERROR )
		return( SOFTERROR );
	else
	{
		switch( worktyp1 )
		{
		case	VARB_FOUR	:
		case	VARB_INT8	:
			add_remote_value(rptr,"B",workval1,1);
			break;
		case	VARB_INT16	:
			add_remote_value(rptr,"W",workval1,2);
			break;
		case	VARB_INT32	:
			add_remote_value(rptr,"L",workval1,4);
			break;
		case	VARB_INT64	:
			add_remote_value(rptr,"H",workval1,8);
			break;
		case	VARB_BCD	:
			add_remote_string(rptr,"N",workptr1,worklen1);
			break;
		case	VARB_STR	:
			add_remote_string(rptr,"S",workptr1,worklen1);
			break;
		default			:
			err_val = 100;
			return(SOFTERROR);
		}
		return((rptr+strlen(rptr)));
	}			
}

EXAWORD call_remote_procedure(EXAWORD callprocid, OVLOBJPTR attlog, EXAWORD argc, BPTR xp)
{
	EXAWORD	c=0;
	EXAWORD	parameters=0;
	BPTR	rptr;
	BPTR	pptr;
	rptr = pptr = (TcodeByteStack + worktop);		/* Get workspace pointer   */
	while ( argc-- )
	{
		/* ----------------------- */
		/* second nibble parameter */
		/* ----------------------- */
		if (!(c =  *(xp++)))
			break;
		else if (!( c & 0x0010 ))
			break;
		else if (!( rptr = add_remote_parameter( rptr, ((c & 0x0006) >> 1), parameters++ ) ))
			return( SOFTERROR );

		/* ---------------------- */
		/* first nibble parameter */
		/* ---------------------- */
		if (!( c & 1 ))
			break;
		else if (!( argc-- ))
			break;
		{
			c =  *xp;
			if (!( rptr = add_remote_parameter( rptr, ((c & 0x0060) >> 5), parameters++ ) ))
				return( SOFTERROR );
		}
	}
	if ( parameters )
		return( call_remote_parameters( callprocid, attlog->remote, parameters, pptr ) );
	else	return( call_remote_number( callprocid, attlog->remote ) );
}
#endif

BPTR	procedure_data_table( EXAWORD procid )
{
	BPTR	ptp;
	EXAWORD	sect_data;
	EXAWORD	leng_data;
	if ((ptp = (*(TcodeProcTable + procid)).table_segment) != (BPTR) 0)
		return( ptp );
	else if (((sect_data = (*(TcodeProcTable + procid)).data_sector) == 0 )
	     ||  ((leng_data = (*(TcodeProcTable + procid)).data_length) == 0 ))
		return((BPTR) 0);
	else if ((ptp = (BPTR) kode_lode(sect_data,leng_data)) == (BPTR) 0)
		return((BPTR) 0);
	else 	return( ( (*(TcodeProcTable + procid)).table_segment = ptp ) );
}


/*	-------------------------------------------	*/
/*		c a l l _ p r o c e d u r e 		*/
/*	-------------------------------------------	*/

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
	EXAWORD	status;
	EXAWORD CallerWordSize=WORDSIZE;
	EXAWORD TargetWordSize=WORDSIZE;

#ifdef WEXADBDLL
	/* Stack managment for StepOver */
	/* ---------------------------- */
	if (StepOverMode > 0)
		(StepOverMode)++;
#endif

/* Initialise all control variables */
	/* -------------------------------- */
#ifdef	VERSION_XX
	prepare_indirection();
#endif
	calledprocs++;
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
	worktop += ( arg_counter + ( (arg_counter * 2) * (CallerWordSize * 5)));

	/* Check for temporary workspace overflow */
	/* -------------------------------------- */
	if ( worktop > dieztmp ) 
	{
		procabb2( oldtop );
		err_val = ABAL_MEMORY;
		return(SOFTERROR);
	}

	while (arg_counter--) 
	{

		/* Part 1 High nibble => 1st of 2 possible Arguaments */
		/* -------------------------------------------------- */
		if ((arg_type = (((EXAWORD) *xp)  & 0x0060) >> 5) != 3) 
		{
			arg_value = Tcodeword(fdex); 
			fdex += CallerWordSize;
			TcodePmot( sp , arg_value); 
			sp += CallerWordSize;
			temp_zone_used += CallerWordSize;
			reg = 0; /* Default Register for Imm Varptrs */
		}
		else 
		{
			reg = (EXAWORD) *(fdex++); 
			arg_value = (EXAWORD) freg [reg];
			TcodePmot( sp, reg); 	    
			sp += CallerWordSize;
			TcodePmot( sp, arg_value ); 
			sp += CallerWordSize;
			TcodePmot( sp, ireg [reg]); 
			sp += CallerWordSize;
			TcodePmot( sp, areg [reg]); 
			sp += CallerWordSize;
			if ( xreg [reg] & PTRSTATUS ) 
			{
				TcodePmot( sp , VARIABLE ); 
			}
			else 
			{
				TcodePmot( sp, xreg [reg]); 
			}
			sp += CallerWordSize;
			temp_zone_used += (5 * CallerWordSize); 
			arg_type = ((EXAWORD) xreg [reg] & 0x0803); 
		}

		/*	DO 1st TRANSFER HERE ( Z points to or is Arguament )	*/
		/*	----------------------------------------------------	*/

		/* Check for First Pass */
		/* -------------------- */
		if (go == 1) 
		{

			/* Must initialise local Variables Now */
			/* ----------------------------------- */
			go = 0; hsb = TcodeSegment; special = 0;
			if ( arg_type &  2 ) 
			{
				if ( (( reg == 0 )
				&&    ( argset(5,arg_value,1) == SOFTERROR))
				||   (( reg != 0 )
				&&    ( argset(4,reg,1) == SOFTERROR)) ) 
				{
					procabb2( oldtop );
					return( SOFTERROR );
				}

				switch (( worktyp1 & VARB_ISOL )) 
				{
					case VARB_FOUR	:
					case VARB_INT8	:
					case VARB_INT16	:
					case VARB_INT32	:
					case VARB_INT64	:
						arg_value = workval1;
						break;
					case VARB_STR   :
						if ( *workptr1 == 5 ) 
						{
							arg_value = balgetw((workptr1 + 3));
							break;
						}
						else if (( *workptr1 == PROGRAM_POINTER )
						     && (( arg_value = connect_program_procedure( workptr1 )) != MOINS_UN )) 
						{
							if (!(TargetWordSize = TcodeContext->wordsize)) 
							{
								if (!(TargetWordSize = TcodeContext->wordsize = WORDSIZE)) 
								{
									err_val = 100;
									procabb2( oldtop );
									return(SOFTERROR);
									}
								}
							special = 1;
							break;
						}
#ifdef	ABAL64
						else if (( *workptr1 == OFFSET_POINTER )
						     && (( arg_value = resolve_program_procedure( workptr1 )) != MOINS_UN )) 
						{
							break;
						}
#endif
#ifdef	ABAL4
						/* ------------------------ */
						/* remote procedure pointer */
						/* ------------------------ */
						else if ( *workptr1 == REMOTE_POINTER ) 
						{
							arg_value = connect_remote_procedure( workptr1, (arg_counter*2)+1, xp );
							lerrval = err_val;
							procabb2( oldtop );
							err_val = lerrval;
							return( arg_value );
						}
#endif
					case VARB_BCD	:
						err_val = 56;
						procabb2( oldtop );
						return(SOFTERROR);
					}
				}

			/* Check for a Valid Procedure identifier */
			/* -------------------------------------- */
			if (( arg_value % (8*TargetWordSize) )) 
			{
				err_val = 333;
				procabb2( oldtop );
				return(SOFTERROR);
			}
			ip_hold [ip_next++] = special;

	 		if ((procid = (arg_value / (8*TargetWordSize))) >= procmaxid ) {
				/* Invalid procedure identifier */
				/* ---------------------------- */
				TcodeSegment = hsb;
				err_val = ABAL_PRCMAX; 
				procabb2( oldtop );
				return(SOFTERROR);
				}

			/* Collect Code Base and Variable Table Base */
			/* ----------------------------------------- */
			while ((TcodeSegment  = (*(TcodeProcTable + procid)).code_segment) == (BPTR) 0) 
			{
				WORDSIZE = TargetWordSize;
				status = load_procedure(TcodeProcTable, procid,SOFTERROR );
				WORDSIZE = CallerWordSize;
				if ( status == SOFTERROR ) 
				{
					TcodeSegment = hsb;
					procabb2( oldtop );
					return(SOFTERROR);
				}
			}

			/* If Procedure has local Variables */
			/* -------------------------------- */
			if ((ptp = (*(TcodeProcTable + procid)).table_segment) != (BPTR) 0) 
			{
				/* If Variables are of DYNAMIC storage CLASS */
				/* ----------------------------------------- */
				if ((  (*(TcodeProcTable + procid)).options & 0x0002) == 0 ) 
				{
#ifdef	ABAL64
					if ( TargetWordSize > 4 ) 
					{
						memsize = (TcodeWord64( (ptp + (2*TargetWordSize))));
					}
					else 
#endif
					if ( TargetWordSize > 2 ) 
					{
						memsize = (TcodeWord32( (ptp + (2*TargetWordSize))));
					}
					else	
					{
						memsize = (TcodeWord16( (ptp + (2*TargetWordSize))));
					}

					/* Attempt to allocate for LDS */
					/* --------------------------- */
					if ((pdp = (BPTR) allocate( memsize )) == (BPTR) 0) 
					{
						/* Restore Context and Report */
						/* -------------------------- */
						TcodeSegment = hsb;
#ifdef WIN32
						special = ip_hold[--ip_next]; //#FCH+BGI 26/05/2008
#endif
						procabb2( oldtop );
						err_val = 27;
						return(SOFTERROR);
					}					
					
					memset((BPTR) pdp, 0, (USINT) memsize );

					/* Static Data FALSE */
					/* ----------------- */
					static_local_data = 0;
				}
				else 	
				{ 
					/* Load Pre-allocated Data Zone Pointer */
					/* ------------------------------------ */
					pdp = (*(TcodeProcTable + procid)).data_segment;

					/* Static Data TRUE */
					/* ---------------- */
					static_local_data = 1;
				}

			/* Create Data Table Pointer Starting Point */
			/* ---------------------------------------- */
			dvp = ptp + (3*TargetWordSize);
			}
			else	
			{
				/* Dissable Local Data Segment */
				/* --------------------------- */
				dvp = (BPTR) 0;
			}

			/*	Establish new DATA management 	*/
			/*	-----------------------------	*/
			ddx = (*(TcodeProcTable + procid)).code_length;


			datapnt = Tcodeword((TcodeSegment + ddx - TargetWordSize));

			if ( datapnt == 0xFFFF ) 
			{ 
				/* Indicate No DATA available */
				/* -------------------------- */
				datamax = 0; 
				datadex = 1;
			}
			else 	
			{
				/* Initialise DATA for READ=0 */
				/* -------------------------- */
				datamax = Tcodeword((TcodeSegment + ddx - (TargetWordSize * 2)));
				if ( setdata(1) == SOFTERROR ) 
				{ 
					TcodeSegment = hsb; 
					lerrval = err_val; 
					(void) procabb(4); 
					err_val = lerrval;
#ifdef ABAL_SYSLOG
					if (IsExaSysLog() & SYSLOG_PROC) 
					{
						sprintf(SysLogBuffer, "Error: call_procedure: Step 1, err=%d", err_val);
						ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
					}
#endif
					return(SOFTERROR);
				}
				datadex = 1;
			}
		}

		else 	
			/* Perform Arguament Transfer */
			/* -------------------------- */
			dvp = (BPTR) vtoproc(arg_type,arg_value,dvp,pdp,reg,TargetWordSize); 

		/* Check for Errors */
		/* ---------------- */
		if (( dvp == (BPTR) 0) && ( ptp != (BPTR) 0)) {  
			TcodeSegment = hsb; 
			lerrval = err_val; 
			(void) procabb(4); 
			err_val = lerrval;
#ifdef ABAL_SYSLOG
			if (IsExaSysLog() & SYSLOG_PROC) {
				sprintf(SysLogBuffer, "Error: call_procedure: Step 2, err=%d", err_val);
				ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
				}
#endif
			return(SOFTERROR);
			}

		/* Part 2 Low  nibble => 2nd of 2 possible Arguaments */
		/* -------------------------------------------------- */
		if ( ((EXAWORD) *xp) & 0x0010 ) {	/* If 2nd Arg Valid   */
			if ((arg_type = (((EXAWORD) *xp)  & 0x0006) >> 1) != 3) {
				arg_value = Tcodeword(fdex); 
				fdex += CallerWordSize;
				TcodePmot( sp,arg_value); 
				sp += CallerWordSize;
				temp_zone_used += CallerWordSize; 
				reg = 0; /* Default Register for Imm Varptrs */
				}
			else 	{
				reg = (EXAWORD) *(fdex++); 
				arg_value = (EXAWORD) freg [reg];
				TcodePmot( sp,reg); 	   sp += CallerWordSize;
				TcodePmot( sp,arg_value);  sp += CallerWordSize;
				TcodePmot( sp,ireg [reg]); sp += CallerWordSize;
				TcodePmot( sp,areg [reg]); sp += CallerWordSize;
				if ( xreg [reg] & PTRSTATUS ) { TcodePmot( sp , VARIABLE ); }
				else			      {	TcodePmot( sp, xreg [reg]); }
				sp += CallerWordSize;
				temp_zone_used += (5 * CallerWordSize); 
				arg_type = ((EXAWORD) xreg [reg] & 0x0803); 
				}

			/*	DO 2nd TRANSFER HERE ( Z points to or is Arguament )	*/
			/* 	----------------------------------------------------	*/
			if ((dvp = (BPTR) vtoproc(arg_type,arg_value,dvp,pdp,reg,TargetWordSize)) == (BPTR) 0) {
				TcodeSegment = hsb; 
				lerrval = err_val; 
				(void) procabb(4); 
				err_val = lerrval;
#ifdef ABAL_SYSLOG
				if (IsExaSysLog() & SYSLOG_PROC) {
					sprintf(SysLogBuffer, "Error: call_procedure: Step 3, err=%d", err_val);
					ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
					}
#endif
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
			temp_zone_used += CallerWordSize;
			break; 
			}	/* End ELSE */

		}	/* End WHILE (arg_counter) */

	/* Calculate Gosub Base Protection Limit for New Procedure */
	/* ------------------------------------------------------- */
	worktop = (oldtop + temp_zone_used);	

	if ( special != 0 ) {
		minder  [mindex++]  = GlobalDataTable;
		minder  [mindex++]  = GlobalDataSegment;
		minder  [mindex++]  = GlobalConstants;
		minder  [mindex++]  = TcodeConstants;
		collect_indirect_gds();
		}

	pcp = collect_procedure_constants( procid );

	return( final_procedure_push( hsb, pcp, pdp, ptp, static_local_data ) );
}

EXAWORD	disactivate_procedure()
{
	/* detect stack underflow conditions */
	/* --------------------------------- */
	if ( mindex < 2 ) {
		err_val = ABAL_RETNOGSB;
		return( SOFTERROR );
		}
	else	{
		TcodeSegment = minder [--mindex];
		fdex         = minder [--mindex];
		timersem |= 0x1000;
		return( GOODRESULT );
		}
}


EXAWORD	execute_pseudo_code(BPTR tccs)
{
	minder [mindex++]   = fdex;
	minder [mindex++]   = TcodeSegment;
	fdex = TcodeSegment = tccs;
	err_val = 0;
	ExQui++;
	(void) llmotor(); /* toujours HARD ERROR donc */
	ExQui--;
	TcodeSegment 	= minder [--mindex];
	fdex 		= minder [--mindex];
	return(err_val);
}


EXAWORD	activate_procedure( arg_value, nature )
EXAWORD	arg_value;
EXAWORD	nature;
{
	WORD	holdworktop=worktop;
	WORD	i;

	/* detect stack overflow conditions */
	/* -------------------------------- */
	if (( mindex+2 ) >= diezstk ) {
		err_val = ABAL_GSB2MANY;
		return( SOFTERROR );
		}
	StackCheck(((3*WORDSIZE)+PTRSIZE+2+2));

	/* Ok just do it : Stack up current */
	/* -------------------------------- */
	minder [mindex++]   = fdex;
	minder [mindex++]   = TcodeSegment;

	TcodeSegment =  TcodeByteStack;
	fdex         = (TcodeByteStack + worktop);

	/* Build and step over procedure pointer */
	/* ------------------------------------- */ 
	TcodePmot(fdex,VARB_STR); fdex += WORDSIZE;
	TcodePmot(fdex,PTRSIZE);		fdex += WORDSIZE;
	memcpy(fdex,eventproc,PTRSIZE);		fdex += PTRSIZE;

	/* Register 53 procedure pointer */
	/* ----------------------------- */
	xreg[53] = TEMPDESC; freg[53] = worktop;

	/* Generate False Tcode Procedure Call */
	/* ----------------------------------- */
	*fdex = 0x0060; *(fdex+1) = 53;
	
	/* Generate False Event Pop */
	/* ------------------------ */
	*(fdex+2) = _tc_WHN;
	*(fdex+3) = ( _ec_POP | _ec_EXTERN);
	TcodePmot((fdex+4),arg_value);

	/* Call Procedure */
	/* -------------- */
	worktop += ((3*WORDSIZE)+PTRSIZE+2+2);
	timersem &= 0xE000;

	/* Attempt to execute the procedure Call */
	/* ------------------------------------- */
	if ( call_procedure() != SOFTERROR ) {
		return( GOODRESULT );
		}
	else	{
#if defined(AVIION)||defined(RT_AIX)||defined(LINUX)
		WORD	i;
		printf("\r\nEvent Call Failure : PROC PTR [ ");
		for (i=0; i < 5; i++ ) {
			printf("%02.2X ",eventproc[i]);
			}
		printf("] : e ( %u )\r\n",err_val);
#endif
		worktop 	= holdworktop;
		TcodeSegment 	= minder [--mindex];
		fdex 		= minder [--mindex];
		return( SOFTERROR );
		}
}

EXAWORD	disactivate_timer_procedure()
{
	/* detect stack underflow conditions */
	/* --------------------------------- */
	if ( mindex < 2 ) {
		err_val = ABAL_RETNOGSB;
		return( SOFTERROR );
		}
	else	{
		TcodeSegment = minder [--mindex];
		fdex         = minder [--mindex];
		return( GOODRESULT );
	}
}

EXAWORD	activate_timer_procedure( target, timer )
EXAWORD	target;
EXAWORD	timer;
{
	WORD	holdworktop=worktop;

	/* detect stack overflow conditions */
	/* -------------------------------- */
	if (( mindex+2 ) >= diezstk ) {
		err_val = ABAL_GSB2MANY;
		return( SOFTERROR );
		}
	StackCheck(((4*WORDSIZE)+PTRSIZE+2+2));

	/* Ok just do it */
	/* ------------- */
	minder [mindex++]   = fdex;
	minder [mindex++]   = TcodeSegment;

	TcodeSegment =  TcodeByteStack;
	fdex         = (TcodeByteStack + worktop);

	/* Build and step over procedure pointer */
	/* ------------------------------------- */ 
	TcodePmot(fdex,VARB_STR); fdex += WORDSIZE;
	TcodePmot(fdex,PTRSIZE);		fdex += WORDSIZE;
	memcpy(fdex,timerproc,PTRSIZE);		fdex += PTRSIZE;

	/* Register 53 procedure pointer */
	/* ----------------------------- */
	xreg[53] = TEMPDESC;		freg[53] = worktop;

	/* Generate False Tcode Procedure Call */
	/* ----------------------------------- */
	*fdex = 0x0060; *(fdex+1) = 53;
	
	/* Generate False TIMER CALL */
	/* ------------------------- */
	*(fdex+2) = _tc_TIM; *(fdex+3) = 0x04;
	TcodePmot((fdex+4),timer);
	TcodePmot((fdex+WORDSIZE+4),target);

	/* Call Procedure */
	/* -------------- */
	worktop += ((4*WORDSIZE)+PTRSIZE+2+2)/*7*/;

	/* Attempt to execute the procedure Call */
	/* ------------------------------------- */
	if ( call_procedure() != SOFTERROR ) {
		return( GOODRESULT );
		}
	else	{
		worktop 	= holdworktop;
		TcodeSegment 	= minder [--mindex];
		fdex 		= minder [--mindex];
		return( SOFTERROR );
		}
}

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

BPTR	ProcedureCodePointer( procid, offset )
EXAWORD	procid;
EXAWORD	offset;
{
	BPTR	bptr;

	if (!( TcodeProcTable ))
		return((BPTR) 0);
	else if (( bptr = (*(TcodeProcTable + procid)).code_segment) == (BPTR) 0)
		return( bptr );
	else
		return( (bptr + offset) );
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
	else
		return( 0 );
}


static	VOID	ll_procedure_release( TcodeProcTable, procid, mode )
struct procform PTR TcodeProcTable;
EXAWORD	procid;
EXAWORD	mode;
{
#if defined(RT_AIX) || defined(AVIION) ||defined(LINUX)
	VOID	release_procedure();
#else
	VOID	release_procedure( struct procform PTR, EXAWORD );
#endif

	/* Check for and Signal END.PROC */
	/* ----------------------------- */
	if ( mode )
		(*(TcodeProcTable + procid)).options |= 0x0080;

	/* If liberation has been requested or is pending and no users */
	/* ----------------------------------------------------------- */
	if ( ( (*(TcodeProcTable + procid)).callers == 0 ) &&
	     ( (*(TcodeProcTable + procid)).options & 0x0080 )
	   )
		release_procedure( TcodeProcTable, procid );

	return;
}

VOID	clf_procedure_release( procid, mode )
EXAWORD	procid;
EXAWORD	mode;
{

	ll_procedure_release( TcodeProcTable, procid, mode );
	return;
}

VOID	procedure_release( TcodeProcTable, procid, mode )
struct procform PTR TcodeProcTable;
EXAWORD	procid;
EXAWORD	mode;
{
	/* Decrement callers usage counter (if not null) */
	/* --------------------------------------------- */
	if ( (*(TcodeProcTable + procid)).callers )
		(*(TcodeProcTable + procid)).callers--;

	ll_procedure_release( TcodeProcTable, procid, mode );

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
	struct  procform PTR MyTable;
	MyTable = TcodeProcTable;

	oldhold = ip_next;

	check_for_error_pop();

#ifdef WEXADBDLL
	/* Stack managment for StepOver */
	/* ---------------------------- */
	if (StepOverMode > 1)
		(StepOverMode)--;
#endif

	/* Check for and avoid EVENT processing underway */
	/* --------------------------------------------- */
	if (( timersem & EVENT_EXIST ) != 0 ) 
		ip_next--;

	ip_next = StackHold;

	/*	Recover Callers Arguament details	*/
	/*	---------------------------------	*/
/*	IJM 19/10/1995		*/
#ifdef	LONG_FILE_HANDLES
	if ( ip_hold [ ( ip_next - 10 ) ] == 0 )
		ri = ip_hold [ ( ip_next - 11) ];
	else	ri = ip_hold [ ( ip_next - 12) ];
#else
	if ( ip_hold [ ( ip_next - 10 ) ] == 0 )
		ri = ip_hold [ ( ip_next - 11) ];
	else	ri = ip_hold [ ( ip_next - 13) ];
#endif

	rp = (TcodeByteStack + ri); hp = rp; ac = 1;

	/*	Check Arguaments for Return value required	*/
	/*	------------------------------------------	*/

	do {
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
	else {
#ifdef ABAL_SYSLOG
		sprintf(SysLogBuffer, "Error: procedure_exit: result=%d", result);
		ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
#endif
	}

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
struct	procform PTR	TcodeProcTable;
EXAWORD			tabdex;
{
	/* Liberate CS */
	/* ----------- */
#ifdef	DEBUG_END_PROC
	x_cprintf((BPTR)"rp()");
#endif
	if ( (*(TcodeProcTable + tabdex)).code_segment != (BPTR) 0) {

/* A garder!
#ifdef _DEBUG
#ifndef WEXADBDLL
// #BG 22/08/11 Pour debug. 
	{
		BPTR bpItem = NULL;
		bpItem = (BPTR)get_procedure_name(tabdex * (8*WORDSIZE));
		bpItem = NULL;
	}
#endif
#endif
*/

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
	(*(TcodeProcTable + tabdex)).callers = 0;
	(*(TcodeProcTable + tabdex)).options &= 0x007F;

	return;
}

VOID	liberate_procedure_table( TcodeProcTable, procmaxid )
struct	procform PTR 	TcodeProcTable;
EXAWORD			procmaxid;
{
	EXAWORD	tabdex;

	if ( TcodeProcTable != ( struct procform PTR ) 0 ) { 
		tabdex = 0;
		while ( tabdex < procmaxid ) {
			release_procedure(TcodeProcTable, tabdex );
			tabdex++;
			}

		/* Liberate Procedure Table */
		/* ------------------------ */
		liberate( TcodeProcTable );
		TcodeProcTable = ( struct procform PTR ) 0;
		}
	return;
}

VOID	LiberateProcedureTable( procmaxid )
EXAWORD	procmaxid;
{
	if ( ExportTable ) {
		liberate( ExportTable );
		ExportTable = (BPTR) 0;
		}
	liberate_procedure_table( TcodeProcTable, procmaxid );
	return;
}


/* 
 *	Chargement et Initialisation des procedures
 *	-------------------------------------------
 */
struct procform PTR load_tcode_procedures( procmaxid , wpb )
EXAWORD	procmaxid;
BPTR	wpb;
{
	EXAWORD			procid;
	struct procform PTR 	TcodeProcTable;

	procid    = 0; 

	/* Attempt to allocate for Internal Procedure Control Structure */
	/* ------------------------------------------------------------ */
	if ((TcodeProcTable = (struct procform PTR) allocate( sizeof( struct procform)* procmaxid)) == (struct procform PTR) 0)
		return( TcodeProcTable );
	else	
		memset( (BPTR) TcodeProcTable,0, sizeof( struct procform)* procmaxid );

	/* then Load Procedure Code and LD Tables */
	/* -------------------------------------- */
	while ( procid < procmaxid ) {

		/* Load Procedure Control Table Information */
		/* ---------------------------------------- */
		(*(TcodeProcTable + procid)).code_sector  = Tcodeword((wpb));
		(*(TcodeProcTable + procid)).code_length  = Tcodeword((wpb+(1*WORDSIZE)));
		(*(TcodeProcTable + procid)).data_sector  = Tcodeword((wpb+(2*WORDSIZE)));
		(*(TcodeProcTable + procid)).data_length  = Tcodeword((wpb+(3*WORDSIZE)));
#ifdef	ABA21
		(*(TcodeProcTable + procid)).callers      = 0;
#endif
		if (((*(TcodeProcTable + procid)).const_sector = Tcodeword((wpb+(4*WORDSIZE))) ) == MOINS_UN)
			(*(TcodeProcTable + procid)).const_sector = 0;

		if (((*(TcodeProcTable + procid)).const_length = Tcodeword((wpb+(5*WORDSIZE)))) == MOINS_UN)
			(*(TcodeProcTable + procid)).const_length = 0;

		/* Collect Options and Check if Overlay or Resident */
		/* ------------------------------------------------ */
		if ((( (*(TcodeProcTable + procid)).options = (Tcodeword((wpb + (7*WORDSIZE))))) & 0x0008) == 0) {

			/* Attempt to load this Resident procedure */
			/* --------------------------------------- */
			if ( load_procedure(TcodeProcTable, procid, GOODRESULT ) == SOFTERROR ) {

				/* Dismantle Procedure Table */
				/* ------------------------- */
				liberate_procedure_table(TcodeProcTable,procid);

				/* Indicate Procedure Loading Failure */
				/* ---------------------------------- */
				return((struct procform PTR) 0);

				}

			}

		/* Next Procedure Table Entry */
		/* -------------------------- */
		procid++; wpb += (8*WORDSIZE);

		}
	return(TcodeProcTable);
}

BPTR	load_tcode_callbacks(EXAWORD s, EXAWORD l)
{
	BPTR	ExportTable=(BPTR) 0;

	/* Attempt to load the Procedure Export Table */
	/* ------------------------------------------ */
	if (( s != 0 ) && ( l != 0 )) {
		ExportTable = (BPTR) kode_lode( s, l );
		}
	return( ExportTable );
}

EXAWORD load_procedure_table()
{
	BPTR	wpb;

	/* Attempt to load Procedure table from Tcode File */
	/* ----------------------------------------------- */
	if ((wpb = (BPTR) kode_lode(adr_tpr,lng_tpr)) == (BPTR) 0)
		return( SOFTERROR );

	ExportTable = load_tcode_callbacks(ExportTableSector,ExportTableLength);

	/* Initialise Control Variables */
	/* ---------------------------- */
	StackHold = 0;
	LDS_dex   = 0; 	
	procmaxid = lng_tpr / (8*WORDSIZE); 
	
	TcodeProcTable = (struct procform PTR) load_tcode_procedures( procmaxid, wpb );

	liberate( wpb );

	if (TcodeProcTable == (struct procform PTR) 0) {
		err_val = 27;
		return( SOFTERROR );
		}
	else	return( GOODRESULT );
}


	/* --------- */
#endif	/* _EXPROC_C */
	/* --------- */

