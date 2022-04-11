/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic  .			*/
/*									*/
/*		Module  :	EXNGF - C				*/
/*		Version :	1.4d / 2.1d				*/
/*		Date 	:	15/01/1997				*/
/*									*/
/* 22/02/96 : Close handle de recherche (FIND) pour NT/95		*/
/* 13/05/96 : ASS_FIND_VALID pour 95/NT */
/* 15/01/97 : Modif pour fihier virtuel >16 Mo */
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXNGF_C
#define	_EXNGF_C


#include "exngf.h"			/* NGF definitions		*/

#ifdef INTEL
#include "exprag0.h"			/* Stack probing OFF		*/
#endif

extern	EXAWORD	IoFlag;
extern	EXAWORD	IoFlg[33];

EXAWORD	Available_Option( method )
EXAWORD method;
{
	switch ( method ) {
#ifndef ABALMSG
		case NGF_CM    : break;
#endif
#ifndef ABALSQ
		case NGF_SQ    : break;
#endif
#ifndef ABALSI
		case NGF_SI    : break;
#endif
#ifndef ABALMC
		case NGF_MC    : break;
#endif
#ifndef ABALBD
		case NGF_MCBD  :
		case NGF_BD    : break;
#endif

		/* All Methods not excluded */
		/* ------------------------ */
		default        : return(0);
		}

	/* All Excluded Methods */
	/* -------------------- */
	return(56);
}


#ifdef ABALSI
/*==========================================================================*/
/*
 *	S I M C P R E P ( )
 *	-------------------
 *
 *	Prepares NGF/SF Function Code for SI/MC/MCBD file functions
 *
 */

VOID	simcprep(ngfop)
EXAWORD	ngfop;
{
	EXAWORD	sfext;

#ifdef	VERSION666
	if ( ngfop == _NGF_XUSER ) {
		simcbd = ngfop;
		return;
		}
#endif

	if ( ngfop > 15 ) 
		return;
	simcbd = (((EXAWORD) simcode[ngfop]) | 0x2000 ); sfext = 0;
	switch ( fidperm & NGF_TYP ) {
		case NGF_MCBD	: sfext = 0x0100;
#ifdef SPARC
				  dbreel = (AssignTable[fidbd]).unlog; 
#else
				  dbreel = (*(AssignTable + fidbd)).unlog; 
#endif
		case NGF_MC	: if ( simcbd == 0x2062 ) 
					simcbd =  0x2053; 
				  if ( simcbd == 0x202A ) 
					simcbd =  0x207F; 
				  sfext |= 0x0001; break;
		case NGF_BD	: 
			sfext = 0x0100;
			if ((ngfop == _NGF_DOWN) || (ngfop == _NGF_UP)) 
				sfext |= 0x0081;

		default		: break;
		}
	simcbd |= sfext;
	return;
}

#ifdef VERSION666

/*
 * S I _ C R I E X T _ P R E P
 * ---------------------------
 * Preparation des donnees pour la nouvelle fonction criteria CRIEXT.
 * C'est un peu comme un read/write mais aussi un peu comme un search/del/down etc
 * alors pourquoi pas lui faire son propre analysateur de parametres ! (sic)
 */

EXAWORD	si_criext_prep(rw)
EXAWORD	rw;		/* Read or write for buffer variable	*/
{
	/* Parameter 1 : Buffer Source */
	/* --------------------------- */
	if ( fargset(2) == SOFTERROR ) 
		return(SOFTERROR);
	else	si_buf = workptr2;
	
	/* Parameter 2 : Longeur buffer source (obligatoire !) */
	/* ------------------------------------------------- */
	if ( fargset(2) == SOFTERROR ) 
		return(SOFTERROR);
	else	si_lng = workval2;

	/* Parameter 3 : Buffer resultat */
	/* ----------------------------- */
	if ( fargset(0) == SOFTERROR ) 
		return(SOFTERROR);

	/* Parameter 4 :  Longueur buffer resultat (obligatoire !) */
	/* ------------------------------------------------------- */
	if ( fargset(3) == SOFTERROR ) 
		return(SOFTERROR);

	return( GOODRESULT );
}

#endif
/*==========================================================================*/
#endif	/* ABALSI */

/*
 *	F A R G S E T ( type )
 *	----------------------
 *	Gestion des arguaments des fichiers
 */

EXAWORD fargset(type)
EXAWORD	type;			/* 	Arguament Evaluation Set to prepare */
				/*	NB	0 => argsetw		    */
				/* 	Type de data desiree	*/
{
	EXAWORD	desc,reg;
	BPTR	tptr;
	reg = 0;
	switch ( amode ) {
		case 1 :	desc = (adesc & 0x00E0) >> 5;
				if (( adesc & 0x0010 ) != 0 ) 
					amode = 2;
				else 	amode = 0; 
				break;
		case 2 :
				desc = ( adesc & 0x000E) >> 1;
				if (( adesc & 1 ) != 0 ) { 
					adesc = (EXAWORD) *(adex++);
					amode = 1;
					}
				else 	amode = 0;
				break;
		default : amode = 0;
		case 0  : err_val = ABAL_TCODCODE; return(SOFTERROR);
		}

	if ( desc == 4 ) {	/* String direct in the T-Code */
		tptr = fdex;
		while ( *(fdex++) != (EXABYTE) 0 ) 
			reg++;
		switch(type) {
			case 1 : workptr1 = tptr; worklen1 = reg; 
				 worktyp1 = VARB_STR; return(1);
			case 2 : workptr2 = tptr; worklen2 = reg; 
				 worktyp2 = VARB_STR; return(1);
			case 3 : workptr3 = tptr; worklen3 = reg; 
				 worktyp3 = VARB_STR; return(1);
			case 0 :
			default: return(SOFTERROR); 
			}
		}

	if (( desc == 3 ) && ( type == 0 )) { 
		desc = 4; reg = (EXAWORD) *(fdex++); 
		}

	switch ( type ) {
		case 0	:	return(argsetw(desc,reg));
		case 1  :	return(argset1(desc,reg));
		case 2  :	return(argset2(desc,reg));
		case 3  :	return(argset3(desc,reg));
		default : 	err_val = ABAL_TCODFILE; 
				return(SOFTERROR);
		}

}

/*
 *	L A R G S E T ( type )
 *	----------------------
 *
 *	Gestion des arguaments des fichiers (Preparation des Valeurs LONGS)
 *
 */

EXAWORD largset(type)
EXAWORD	type;			/* 	Arguament Evaluation Set to prepare */
				/*	NB	0 => argsetw		    */
				/* 	Type de data desiree	*/
{
	BPTR	lptr;
	EXAWORD	ltyp,llen;
	EXAWORD	lval;
	
	if ( fargset(type) == SOFTERROR ) 
		return(SOFTERROR);
	switch ( type ) {
		case	0 :
 		case	1 :	lptr = workptr1; ltyp = worktyp1;
				llen = worklen1; lval = workval1; break;

		case    2 : 	lptr = workptr2; ltyp = worktyp2;
				llen = worklen2; lval = workval2; break;

		case    3 :	lptr = workptr3; ltyp = worktyp3;
				llen = worklen3; lval = workval3; break;

		default   : return(SOFTERROR);
		}
	switch ( ltyp ) {
		case VARB_FOUR 	:
		case VARB_INT8 	:
#ifdef	VERSION666
		case VARB_INT32 :
#endif
		case VARB_INT16 : 	hugeint = (lval *= BLOCK); 
					break;
		case VARB_BCD	:	hugeint = (bcdtol(lptr,llen) * BLOCK);
					break;
		case VARB_STR	:	hugeint = (atol(lptr,llen) * BLOCK);
					break;
		default :	return(SOFTERROR);
		}
	return(1);
}	


#ifdef ABALMSG
#include "exipc.h"

/*
 *	M S G W O R K ()
 *	----------------
 *	Inter process communications for Systems that offer this function
 *	
 */

EXAWORD	msgwork(ngfmsgop)
EXAWORD	ngfmsgop;
{
	EXAWORD	x;
	EXAWORD	lmsgerr;
	EXAWORD	xfil;
	EXAWORD	lmsglen;
	EXAWORD	lmsgopt;
	struct	talkzone SPTR msr;

/* Test for Message File already OPEN */
/* ---------------------------------- */
if ( fidreel == EX_UNUSED_HANDLE ) {
	/* Check for Message File Exists */
	/* ----------------------------- */
	if ((x = (EXAWORD) msgget(fidblen,0666)) == MOINS_UN) {
		/* Does not exist so we must create it */
		/* ----------------------------------- */
#ifdef UNIX
		err_val = system(fidname);
#endif
#ifdef PROLOGUE
		err_val = exec((BPTR) fidname,(BPTR) " \r ",1);
#endif
		/* If Automate installed correctly OPEN message file */
		/* ------------------------------------------------- */
		if ( err_val == 0 ) {
			x = (EXAWORD) msgget(fidblen,0666); err_val = errno;
			}
		else 	return(err_val); 
		if ( x == MOINS_UN ) 
			return(err_val);
		}
	/* Save the file Handle */
	/* -------------------- */
	fidreel = (x + 1);			
	}

/* Allocate Message transfer zone */
/* ------------------------------ */
	msr = (struct talkzone SPTR ) allocate((USINT) worklen1 + (LONGSIZE * 2) + WORDSIZE);
	if ( msr == (struct talkzone SPTR) 0 ) 
		return(EXER_MEMFULL);

/* Prepare Message header info fields */
/* ---------------------------------- */	
	(*(msr)).abalid = (EXALONG) (x_npos() + 16000);
	(*(msr)).abalds = hugeint;
	(*(msr)).abaler = 0;
	lmsgopt = MSG_NOERROR;

/* Select Message function */
/* ----------------------- */
switch ( ngfmsgop & 0x00F0 ) {
	case 0x0040 :
		if (( ngfmsgop & 4 ) == 0) 
			lmsgopt |= IPC_NOWAIT; 

		/* Receive message */
		/* --------------- */
		x = 0; xfil = worklen1;
		if ((lmsgerr = (EXAWORD) msgrcv((fidreel - 1), msr, (worklen1 + (LONGSIZE *2) + WORDSIZE) , (*(msr)).abalds, lmsgopt)) != MOINS_UN) {

			lmsglen = lmsgerr - (WORDSIZE + LONGSIZE);

			/* Test for 'ORIGINAL MSG ID return' required */
			/* ------------------------------------------ */
			if ( ngfmsgop & 1 ) {
				x = (EXAWORD) (*(msr)).abalid;
				balputw( x , workptr1 );
				workptr1 += WORDSIZE; worklen1 -= WORDSIZE;
				}

			/* Test for 'THIS MSG ID return' required    */
			/* ----------------------------------------- */
			if ( ngfmsgop & 2 ) {
				x = (EXAWORD) (*(msr)).abalds;
				balputw( x , workptr1 );
				workptr1 += WORDSIZE; worklen1 -= WORDSIZE;
				}
			if ( lmsglen > worklen1 ) {
				lmsglen  = worklen1; xfil     = 0;
				}
			else	{ 
				xfil = worklen1 - lmsglen; 
				x = lmsglen;
				}

			/* Tranfer message to ABAL data zone */
			/* --------------------------------- */
			(VOID) memcpy(workptr1,(*(msr)).abaltx,(USINT) lmsglen);
			err_val = (*(msr)).abaler;
			errno = err_val;
			if ( err_val == 0 ) 
				lmsgerr = worklen1;
			else	lmsgerr = MOINS_UN;
			}

		/* Fill unused buffer zone with spaces */
		/* ----------------------------------- */
		if ( xfil > 0 ) 
			(VOID) memset((workptr1+x),' ',(USINT) xfil);
		break;
	case 0x0080 :

		/* Send Message */
		/* ------------ */
		(VOID) memcpy((*(msr)).abaltx,workptr1,(USINT) worklen1);
		lmsgerr = msgsnd((fidreel - 1),msr,(worklen1 + (LONGSIZE *2) +WORDSIZE),(IPC_NOWAIT | MSG_NOERROR)); 
		if ( lmsgerr != MOINS_UN ) 
			lmsgerr = worklen1;
		break;
	}

/* Liberate Message Zone and Return Error Status */
/* --------------------------------------------- */
liberate( msr ); return(lmsgerr);
}

#endif

#ifdef ABALSI

/*
 *	S I _ P R E P 
 *	-------------
 *	Preparation des arguments SI	Search,Down,Modif,Delete,UP 
 */

EXAWORD	si_prep(rw)
EXAWORD	rw;		/* Read or write for buffer variable	*/
{
	EXAWORD	sisem;			/* Mode and semaphore		*/
	EXAWORD	clen;			/* Key Length Variable		*/

	if ( rw == 1 ) {		/* If File Write operation	*/
		/* Check ASSIGN rights = WR */
		/* ------------------------ */
		if ( (fidperm & NGF_R_W) == 0 ) { 
			err_val = ABAL_WRITPROT; return(SOFTERROR); 
			}
		}

	sisem = (EXAWORD) *(fdex++);	/* Read semaphore details */

	if ( (sisem & 1) != 0 ) {	/* Must set *Key	  */
		if ( fargset(2) == SOFTERROR ) 
			return(SOFTERROR);

		/* Must Now Establish Correctly positioned Key */
		/* ------------------------------------------- */
		clen = fidinfo2;
		if ( clen == 0 ) { 
			err_val = EXER_CLE2SMA;
			return(SOFTERROR);
		}		
		if (( worktop + clen ) > dieztmp ) {
			err_val = 114;
			return(SOFTERROR);
			}

		si_cle   = (TcodeByteStack + worktop);
		worktop += clen;
		memset((BPTR) si_cle, ' ', clen);
		if (worklen2 > clen) 
			worklen2 = clen;
		memcpy((BPTR) si_cle, (BPTR) workptr2, (USINT) worklen2);

		/* -------------------------------------------- */
		/*	Old Method of Key Preparation		*/
		/*	-----------------------------		*/
		/*		si_cle = workptr2;		*/
		/* -------------------------------------------- */
		}
	else	si_cle = (BPTR) 0;

	if ( (sisem & 2) != 0 ) {	/* Must set Marquer  */
		if ( fargset(2) == SOFTERROR ) 
			return(SOFTERROR);
		switch ( worktyp2 ) {
			case	VARB_BCD : workval2 = bcdtoi(workptr2,worklen2); break;
			case	VARB_STR : workval2 = exatoi(workptr2,worklen2); break;
			}
		si_mq = (EXAWORD) workval2;
		}
	else	si_mq = 1; 

	if ( (sisem & 4) != 0 ) {	/* Must set *Buffer   */
		if ( fargset(rw) == SOFTERROR ) 
			return(SOFTERROR); 
		si_buf = workptr1;
		}
	else	{ 
		si_buf = (BPTR) askbuf; 
		worklen1 = 0; 
		}

	if ( (sisem & 8) != 0 ) {	/* Must set exchange length */
		if ( fargset(2) == SOFTERROR ) 
			return(SOFTERROR);
		switch ( worktyp2 ) {
			case	2 : workval2 = bcdtoi(workptr2,worklen2); break;
			case	3 : workval2 = exatoi(workptr2,worklen2); break;
			}
		si_lng = (EXAWORD) workval2;
		}
	else	si_lng = worklen1;

	si_ver  = (sisem & 0x010 ) >> 4;	/* Set lock */
	si_flg  = (sisem & 0x060 ) >> 5;	/* Set flag */

#ifdef ABALBD
	if (( fidperm & NGF_TYP ) == NGF_BD)
		return(bd_prep());
#endif

	if ( (extwrite & 3) == 0 ) 
		return(1);
	if ( si_lng > worklen1)	{ 
		err_val = ABAL_NOVAREXT; 
		return(SOFTERROR); 
		}
	return(1);
}
#endif	/* ABALSI	Sequentielle Index arguament preparation	*/

/*
 *	Virtual file variable Closing precautions
 *	-----------------------------------------
 *	Rewrite of unwritten buffers
 *	Loss of identity of current buffered condition
 *
 */

VOID	VmemLiberate()
{
	/* Check for EX or C mode buffering possible */
	/* ----------------------------------------- */
	if (( fidperm & (NGF_I_C | NGF_P_E)) == (NGF_I_C | NGF_P_E)) {

		/* Check for This file in Buffer */
		/* ----------------------------- */
		if ( VmemFid == fidreel ) {

			/* Check if Buffer needs Written */
			/* ----------------------------- */
			if ( VmemDif == 1 ) {

				/* Clear flag and Rewrite */
				/* ---------------------- */
				VmemDif = 0;
				SectWrite(VmemFid,fieldex,VmemLng,(ULONG)((VmemOfs / BLOCK)));
				}

			/* Avoid reusage of Buffer */
			/* ----------------------- */
			VmemFid = EX_UNUSED_HANDLE;
			}

		}			

	/* Ensure file buffing cancelled */
	/* ----------------------------- */
	if ( VmemFid == fidreel )
		VmemFid = EX_UNUSED_HANDLE;

	/* Remove Virtual File Identity */
	/* ---------------------------- */
	fidperm &= 0x07FF; return;

}

/*
 *	E S T A B L I S H _ P R I N T E R ( )
 *	-------------------------------------
 *	As its name implies establish's the current file information
 *	as a printer handling context
 *	Returns ZERO for initialisation of ERR_VAL
 *
 */

EXAWORD	Establish_Printer()
{
				/* ------------------------------------- */
	prndest = lfh; 		/* Indicates Printer when Greater than 1 */
#ifdef LINUX
	prnfid = fidreel;
	if (prnfid == EX_UNUSED_PRINTER)
#else
	if ((prnfid = fidreel) == EX_UNUSED_PRINTER)
#endif
		prnfid = 0;	/* Indicates print file handle		 */
	prnptr  = fidbuff; 	/* Pointer to printer buffer		 */
	prnleng = fidblen;	/* Usable Length of printer buffer	 */
#ifdef SPARC
	prndex  = fidmc1;		/* Current Offset into Printer buffer	 */
#else
	prndex  = fidmc;		/* Current Offset into Printer buffer	 */
#endif
#ifdef	ABAL21
#ifdef	PROLOGUE
	prnmode = (fidperm & ASS_PRINT_FILE);	/* Transmit permissions	 */
	prnseek = fidseek;	/* Establish Current File Offset	 */
#endif
#endif
	return(0);		/* Return ZERO for err_val		 */
				/* ------------------------------------- */
}	

/* -------------------------------------------------------- */
/* Check if File handle is greater than ASSIGN table limits */
/* -------------------------------------------------------- */
EXAWORD	check_valid_assign_handle( nhandle )
EXAWORD	nhandle;
{ 
	if ( nhandle > diezfic ) 	{ 
		err_val = 58; 	
		return( SOFTERROR );
		}
	else	return( GOODRESULT );
}

/*
 *	Called from EXF to honour COL and LIN for PRINTERS
 *	--------------------------------------------------
 *
 */

VOID	update_cico_printer()
{
	if ( check_valid_assign_handle( prndest ) == SOFTERROR )
		return;
#ifdef SPARC
	(AssignTable[prndest]).mcext  = prndex;
#else
	(*(AssignTable + prndest)).mcext  = prndex;
#endif
#ifdef	ABAL21
#ifdef	PROLOGUE
	(*(AssignTable + prndest)).LSeek = prnseek;
#endif
#endif
} 

EXAWORD	sf_open();

EXAWORD	activate_cico_printer( handle )
EXAWORD	handle;
{ EXAWORD error;

	/* Check first for correct ASSIGN and Handle */
	/* ----------------------------------------- */
	if ( check_valid_assign_handle( handle ) == SOFTERROR )
		return( SOFTERROR );

	/* Load file table information */
	/* --------------------------- */
	lfh = handle; 
	if ((err_val = loadfich()) != 0)
		return( SOFTERROR );

	/* Device = 2 , Could be Assigned ! */
	/* -------------------------------- */
	if ( handle == 2 ) {

		/* If No Assign for Dev 2 then Default Printer */
		/* ------------------------------------------- */
		if ((fidperm & ASS_NAME_VALID) == 0) { 
			prnfid = 0; 
			return(GOODRESULT); 
			}

		/* if not ASSIGN , IM then default printer */
		/* --------------------------------------- */
		if (( fidperm & NGF_TYP) != NGF_IM) { 
			prnfid = 0; 
			return(GOODRESULT); 
			}

		}

	/* If No Assign for Device then Error  Printer */
	/* ------------------------------------------- */
	if ((fidperm & ASS_NAME_VALID) == 0) { 
		err_val = 116; 
		return( SOFTERROR ); 
		}

	/* If Not ASSIGN , IM then Device print error */
	/* ------------------------------------------ */
	if (( fidperm & NGF_TYP) != NGF_IM) { 
		err_val = ABAL_ASKID; 
		return(SOFTERROR); 
		}

	/* If Not ASSIGN , WR then Write protect error */
	/* ------------------------------------------- */
	if (( fidperm & NGF_R_W ) == 0 ) { 
		err_val = ABAL_WRITPROT; 
		return(SOFTERROR); 
		} 

	/* Open the Device if not already opened */
	/* ------------------------------------- */
	if ( fidreel == EX_UNUSED_HANDLE ) { 	
		(VOID) sf_open(); 
		if ((error = savefich()) != 0) {
			err_val = error;
			return( SOFTERROR );
		}
	}

	/* Error if OPEN error */
	/* ------------------- */
	if ( fidreel == EX_UNUSED_HANDLE )
		return(SOFTERROR);

	/* Establish Device control Context */
	/* -------------------------------- */
	err_val = Establish_Printer();

	/* Return Good Result */
	/* ------------------ */
	return(GOODRESULT);

}


#ifdef	PROLOGUE

/*
 *	P R I N T E R _ C L O S E
 *	-------------------------
 */

EXAWORD	printer_close( printer_handle )
EX_FILE_HANDLE	printer_handle;
{
#ifdef	ABAL21
#ifdef	PROLOGUE
	if ( prnmode ) {
		for ( ; prndex < prnleng; prndex++ )
			*(prnptr + prndex) = 0x001A;
		printer_flush();
		return( close(printer_handle) ); 
		}
#endif
#endif
	IoFlag = IoFlg[prndest];
	flush_printer_buffer();
	return( close(printer_handle) ); 
}

#endif	/* PROLOGUE */
	/* -------- */

/*
 *	F R E E F I C H ( )
 *	-------------------
 *	Liberates a file table entry
 *
 */

EXAWORD	razfich( retarg )
EXAWORD	retarg;
{
	/* Ensure All elements Reset to Zero */
	/* --------------------------------- */
	fidname  = (BPTR) 0; 	fidreel  = EX_UNUSED_HANDLE; 
	fidbuff  = (BPTR) 0; 	fidblen  = 0; fidperm = 0;
#ifdef SPARC
	fidbase  = (BPTR) 0;	fidbd    = 0; fidmc1   = 0; 
#else
	fidbase  = (BPTR) 0;	fidbd    = 0; fidmc   = 0; 
#endif
	fidinfo1 = 0;		fidinfo2 = 0;

#ifdef ABAL_LONG_NAMES
	bSystemLongNames = 0;
	bUserLongNames	 = 0;
#endif

#ifdef	ABAL_LAN
	if ( fidnetwork != (VPTR) 0 ) {
		liberate_network( fidnetwork );
		fidnetwork = (VPTR) 0;
		}
#endif
	return( retarg );
}

VOID	freefich()
{
	void	liberate_for_assign( BPTR );

	/* Close the file if OPEN */
	/* ---------------------- */
	if ( fidreel != EX_UNUSED_HANDLE ) 
		(VOID) sf_close();


#ifdef ABALBD_MERDE
	/* Liberate RECORD management for BD Files */
	/* --------------------------------------- */
	if (( fidperm & NGF_TYP) == NGF_BD ) {
		remove_bd_records();
/*		ltmp = amode; amode = 3; (VOID) bdrecord(); amode = ltmp; */
		}
#endif

	/* Liberate All allocated Pointers */
	/* ------------------------------- */
	if ( fidperm & ASS_NAME_VALID ) 
		liberate_for_assign( fidname );

	if ( fidperm & ASS_BUFF_VALID ) {

#ifdef WIN32
#define SEEKHANDLEOFFSET	269
	/* Sous NT/95, fermer le handle de recherche */
	{ EXALONG SeekHandle;
	  void __stdcall FindClose(EXALONG);

	  if ( fidperm & ASS_FIND_VALID ) {
			memcpy((BPTR)&SeekHandle,(BPTR)(fidbuff + SEEKHANDLEOFFSET),4);
			if (SeekHandle != 0L)	  FindClose(SeekHandle);
	  }
	}
#endif

		liberate( fidbuff ); 
	}

	if ( fidperm & ASS_BASE_VALID ) 
		liberate( fidbase ); 

#ifdef	VMS
	/* VMS Find file structure needs liberation */
	/* ---------------------------------------- */
	if ( fidperm & ASS_FIND_VALID ) 
		(VOID) findclose( fidbd );
#endif

#ifdef	PROLOGUE
	/* Amenesik / Sologic RESIDENT Load.Go Structure */
	/* ----------------------------------- */
	if ( fidperm & ASS_LOAD_VALID ) 
		DisCharge(fidbuff);
#endif
#ifdef ABALBD_MERDE
	/* Liberate DATA BASE LINKAGE */
	/* -------------------------- */
	if (( fidbd != 0 ) && ( fidbd != MOINS_UN ))
		(VOID) basefile(0);
#endif
	(VOID) razfich( 0 );

#ifdef	PROLOGUE
	fidseek = (LSEEKTYPE)0;
#endif
}


/*	E T A T L O X  ( Xfid , Xperm )			*/
/*	-------------------------------			*/
/*							*/ 
/*	Sets the file mode as EXCLUSIVE or SHARED	*/
/*							*/
/*	Note : 	LOCKF requires the file to be opened	*/
/*		with write permission so if the WR flag */
/*		has not been set then exclusivity is	*/
/*		not possible				*/

#ifndef PROLOGUE
#ifndef COEXA
EXAWORD	etatlox( xfid , xperm )
EXAWORD	xfid,xperm;
{
	return(1);
}
#endif	/* !COEXA */
#endif	/* !PROLOGUE */



#ifndef UNIX	/* If  not UNIX		*/
#ifndef	VMS	/* and not VMS		*/
		/* then PROLOGUE or DOS	*/
#ifdef	ABAL21
EXAWORD	printer_open( prname, propt )
BPTR	prname;
EXAWORD	propt;
{
	EXAWORD	handle;
	EXAWORD	fterm=0;
	EXAWORD	namelen=0;
	EXAWORD	mode=0;

#ifdef	PROLOGUE
	while ( 1 ) {
		if ( *(prname + namelen) == 0 )
			break;
		else if ( *(prname + namelen) == '(' ) {
			fterm = *(prname + namelen);
			*(prname + namelen) = 0;
			}
		else	namelen++;
		}

	/* Special Options */
	/* --------------- */
	if ( fterm != 0 ) {

		aptr = (BPTR) (prname + namelen+1);
		while (( *aptr ) && (*aptr == ' '))
			aptr++;
		if (( *aptr == 'F' ) || ( *aptr == 'f' ))
			mode = 1;
		else if (( *aptr == 'N' ) || ( *aptr == 'n' ))
			mode = 3;

		}

	/* Check for file removal */
	/* ---------------------- */
	if ( mode & 2 )
		(VOID) unlink((BPTR) prname );

#endif

	/* Create a new file */
	/* ----------------- */
	if ((handle = im_open(prname, propt )) != MOINS_UN)
		if ( mode )
			fidperm  |= ASS_PRINT_FILE;

#ifdef	PROLOGUE
	fidseek = (LSEEKTYPE)0;
#endif

	/* Restore Name Terminator if present */
	/* ---------------------------------- */
	if ( fterm != 0 )
		*(prname + namelen) = fterm;	

	return( handle );



}
#endif

#endif /* VMS */
#endif /* UNIX */


/*
 *	L O A D F I C H ( )
 *	-------------------
 *	Copies the file table to Globale variables
 */ 

BPTR	assigned_filename( lfh )
EXAWORD	lfh;
{
#ifdef SPARC
	return(  (AssignTable[lfh]).direcp );
#else
	return(  (*(AssignTable + lfh)).direcp );
#endif
}

EXAWORD	loadfich()
{
#ifdef	PROLOGUE
	if ( stack_inspecter() != 0 )
		return( 666 );
#endif
	/* Load Current File table Infos  */
	/* -----------------------------  */
#ifdef SPARC
	fidperm = (AssignTable[lfh]).permf;
	fidreel = (AssignTable[lfh]).unlog;
	fidname = (AssignTable[lfh]).direcp;
	fidbuff = (AssignTable[lfh]).asptr;
	fidblen = (AssignTable[lfh]).aslen;
	fidbd   = (AssignTable[lfh]).dblog;
	fidmc1  = (AssignTable[lfh]).mcext;
	fidbase = (AssignTable[lfh]).bdext;
	fidinfo1= (AssignTable[lfh]).enrdata;
	fidinfo2= (AssignTable[lfh]).enrcle;
#else
	fidperm = (*(AssignTable + lfh)).permf;
	fidreel = (*(AssignTable + lfh)).unlog;
	fidname = (*(AssignTable + lfh)).direcp;
	fidbuff = (*(AssignTable + lfh)).asptr;
	fidblen = (*(AssignTable + lfh)).aslen;
	fidbd   = (*(AssignTable + lfh)).dblog;
	fidmc   = (*(AssignTable + lfh)).mcext;
	fidbase = (*(AssignTable + lfh)).bdext;

#ifdef	PRL_SF
	fidseek = (*(AssignTable + lfh)).LSeek;
#endif
	fidinfo1 = (*(AssignTable + lfh)).enrdata;
	fidinfo2 = (*(AssignTable + lfh)).enrcle;
#endif
#ifdef	ABAL_LAN
	fidnetwork = (*(AssignTable + lfh)).network_info;
#endif

#ifdef ABAL_LONG_NAMES
  bUserLongNames=(*(AssignTable + lfh)).bUserLongNamesMode;
  bSystemLongNames=(*(AssignTable + lfh)).bSystemLongNamesMode;
#endif

	return(0);
}

/*
 *	S A V E F I C H ( )
 *	-------------------
 *	Saves file variables into File table @LFH
 */

EXAWORD	savefich()
{
#ifdef	PROLOGUE
	if ( stack_inspecter() != 0 )
		return( 667 );
#endif
	/* Store Current File info In Table */
	/* -------------------------------- */
	(*(AssignTable + lfh)).permf  = fidperm;
	(*(AssignTable + lfh)).unlog  = fidreel;

	/* Ensure Correct File Handle for Current T-Code */
	/* --------------------------------------------- */
	if ( lfh == 0 ) TcodeFileHandle = fidreel;
#ifdef SPARC
	(AssignTable[lfh]).direcp = fidname;
	(AssignTable[lfh]).asptr  = fidbuff;
	(AssignTable[lfh]).aslen  = fidblen;
	(AssignTable[lfh]).dblog  = fidbd;
	(AssignTable[lfh]).bdext  = fidbase;
	(AssignTable[lfh]).mcext  = fidmc1;
	(AssignTable[lfh]).enrdata = fidinfo1;
	(AssignTable[lfh]).enrcle  = fidinfo2;
#ifdef	ABAL_LAN
	(AssignTable[lfh]).network_info = fidnetwork;
#endif

#else		/* NOT SPARc */
	(*(AssignTable + lfh)).direcp = fidname;
	(*(AssignTable + lfh)).asptr  = fidbuff;
	(*(AssignTable + lfh)).aslen  = fidblen;
	(*(AssignTable + lfh)).dblog  = fidbd;
	(*(AssignTable + lfh)).bdext  = fidbase;
	(*(AssignTable + lfh)).mcext  = fidmc;

#ifdef	PRL_SF
	(*(AssignTable + lfh)).LSeek = fidseek;
#endif
	(*(AssignTable + lfh)).enrdata = fidinfo1;
	(*(AssignTable + lfh)).enrcle  = fidinfo2;

#ifdef	ABAL_LAN
	(*(AssignTable + lfh)).network_info = fidnetwork;
#endif
#endif		/* NOT SPARC */

#ifdef ABAL_LONG_NAMES
	(*(AssignTable + lfh)).bUserLongNamesMode = bUserLongNames;
	(*(AssignTable + lfh)).bSystemLongNamesMode = bSystemLongNames;
#endif

	return(0);		
}



/*
 *	NGF_INFOS()	
 *	-----------
 *	Returns information concerning the current file characteristics
 *	
 *	DATA LENGTH , KEY LENGTH , KEY TYPE
 *
 */

#define	sq_lgdata( fidreel ) fidinfo1
#define	sq_lgcle( fidreel )  0
#define	sq_type( fidreel ) 0x0001
#define	si_lgdata( fidreel ) fidinfo1
#define	si_lgcle( fidreel ) fidinfo2
#define	si_type( fidreel ) 0x0002
	
EXAWORD	ngf_infos()
{
	EXAWORD	xfiletype;

	switch (( fidperm & NGF_TYP )) {
		case NGF_IO	: fidinfo1  = 256;
				  fidinfo2  = 0;
				  xfiletype = 0;
				  break;
		case NGF_SQ	: fidinfo1  = sq_lgdata( fidreel );
				  fidinfo2  = sq_lgcle ( fidreel );
				  xfiletype = sq_type  ( fidreel );
				  break;
		case NGF_SI	: fidinfo1  = si_lgdata( fidreel );
				  fidinfo2  = si_lgcle ( fidreel );
				  xfiletype = si_type  ( fidreel ); 
				  break;

		/* --------------------------------------- */	
		/* Attention Code manquant pour ABAL_TCPIP */
		/* --------------------------------------- */
		default		: return((err_val = 56)); 

		}

	if ( worklen1 >= 2 ) 
		balputw(fidinfo1,workptr1);

	if ( worklen1 >= 4 ) 
		balputw(fidinfo2,(workptr1 + WORDSIZE));

	if ( worklen1 >= 5 ) 
		*(workptr1 + (2 * WORDSIZE) + 1) = (EXABYTE) xfiletype;
		
	return(0);
}

			
#include "exllngf.c"

/*
 *	----------------------------------------------------------------
 *	S F _ N G F ()
 *	--------------
 *	Entree de la Systeme de gestion des fichiers et resources d'ABAL
 *	----------------------------------------------------------------
 *	Performs TCODE interpretation, function dispatching,
 *	and error handling for all functions operating on 
 *	ASSIGNED files.
 *	----------------------------------------------------------------
 *			IO GR DV CM IM SQ SI MC BD MCBD
 *	----------------------------------------------------------------
 */

				/* -------------------------------------- */
EXAWORD	LastHandle;		/* Storage of ASSIGN handle used for last */
				/* NGF operation READ WRITE OPEN etc	  */
				/* -------------------------------------- */

EXAWORD	sf_ngf()
{

				/* ------------------------------------ */
	EXAWORD	NgfTcode;	/* NGF Operation Function Code		*/
	EXAWORD	ErrorFlag;	/* Error Trap Existance and Nature	*/
	EXAWORD	ErrorLabel;	/* Target Label When Error Trap Valid	*/
	EXAWORD	ErrorTrap;	/* Stores Register or Variable identity	*/
	EXAWORD	ReturnCode;	/* Operation Termination status value	*/
	EXAWORD	error;		/* Error during file saving		*/
				/* ------------------------------------ */

	/* Initialise Error Code and collect NGF function code */
	/* --------------------------------------------------- */
	ReturnCode = errno = err_val = 0; 
	SystemError = 0L;

	NgfTcode = (EXAWORD) *(fdex++); 

	/* Scan past file arguaments to Values */
	/* ----------------------------------- */
	adex = fdex; while ( ((EXAWORD) *(fdex++)) & 1);

	/* Initialise arguament collector */
	/* ------------------------------ */
	adesc = *(adex++); amode = 1;

	/* Test for local error trap required */
	/* ---------------------------------- */
	if ( adesc & 0x0080 ) {	

		/* Collect Error Adresse label */
		/* --------------------------- */
		ErrorLabel = Tcodeword( fdex); fdex += WORDSIZE;

		/* Test for and Collect Variable ID */
		/* -------------------------------- */
		if ( (adesc & 0x0060) != 0x0060 ) { 
			ErrorTrap = Tcodeword( fdex);
			fdex += WORDSIZE;
			}
		else 	/* Else collect Register ID */
			/* ------------------------ */
			ErrorTrap = (EXAWORD) *(fdex++); 

		/* Indicate ON LOCAL ERROR GOTO */
		/* ---------------------------- */
		ErrorFlag = adesc;

		/* Adjust arg manager information */
		/* ------------------------------ */
		amode =2;

		}

	else 	/* Indicate ON LOCAL ERROR ABORT */
		/* ----------------------------- */
		ErrorFlag = 0; 

	/* Collect Internal file handle */
	/* ---------------------------- */
	if (( fargset(1) == SOFTERROR )

	/* Control file handle for Validity */
	/* -------------------------------- */
	|| ( check_valid_assign_handle((lfh = (EXAWORD) workval1)) == SOFTERROR ))
		ReturnCode = err_val;

	else 	{	/* OK So Far */
			/* --------- */

		/* Store Assign Handle for Conf(27) */
		/* -------------------------------- */
		LastHandle = lfh;	

		/* Establish File control variables */
		/* -------------------------------- */
		if ((err_val = loadfich()) != 0)
			return( SOFTERROR );	

		/* Test for ASSIGN ACCESS METHOD Available */
		/* --------------------------------------- */
		if ((err_val = Available_Option((fidperm & NGF_TYP))) != 0)
			ReturnCode = err_val; 

		else	{ 	/* OK So Far */
				/* --------- */

			/* Check for file not OPEN */
			/* ----------------------- */
			if ( fidreel == EX_UNUSED_HANDLE ) {	

				/* Eliminate Codes which do not require an open file */
				/* ------------------------------------------------- */
				switch ( NgfTcode & 0x007F ) 	{
					case _NGF_LOADGO	:
					case _NGF_CHAIN		:
					case _NGF_DFILE		:
					case _NGF_KEY           :
					case _NGF_RKEY          :
					case _NGF_FKEY          :
					case _NGF_FIND		:
					case _NGF_CFILE 	:
					case _NGF_OPEN		: 
					case _NGF_CLOSE		: 
					case _NGF_CORE		:
					case _NGF_NAME		:

						/* Check for valid ASSIGN file entry */
						/* --------------------------------- */
						if ((fidperm & ASS_NAME_VALID) == 0)
			ReturnCode = errno = ABAL_NUMLOG116;

					case _NGF_ASSIGN 	:

						  break;
					default			:
						/* Check for valid ASSIGN file entry */
						/* --------------------------------- */
						if ((fidperm & ASS_NAME_VALID) == 0)
							ReturnCode = errno = ABAL_NUMLOG116;
						else	{
							 if (( fidperm & NGF_TYP) != NGF_CM) {
								sf_open();
							  	if ( fidreel == EX_UNUSED_HANDLE ) 
									ReturnCode = err_val = errno;
								}
							}
						}
				}
			else  	{
				/* Check for Automatic file close required */
				/* --------------------------------------- */
				switch ( NgfTcode & 0x007F ) {
					case _NGF_DFILE  :
					case _NGF_OPEN   :
					case _NGF_CFILE  :
						if ( (ReturnCode = sf_close() ) != MOINS_UN )
							fidreel = EX_UNUSED_HANDLE;
					}
				}

			/* Check for Error due to Auto Open/Close or No Assign */
			/* --------------------------------------------------- */
			if ( ReturnCode == 0 ) {

#ifdef	ABALSI
				/* Prepare SI MC access codes */
				/* -------------------------- */
				simcprep((NgfTcode & 0x007F));
#endif
				/* Establish default error conditions */
				/* ---------------------------------- */
				ReturnCode = errno = EXER_FUNCWOT;

				ReturnCode = ngf_operation_cycle((NgfTcode & 0x007F));
				}

			/* Store current file control variables */
			/* ------------------------------------ */
			if ((error = savefich()) != 0) {
				err_val = error;
				return( SOFTERROR );
			}
		}
	}

/*	----------------------------------------------------		*/
/*	END OF NGF MOTOR CYCLE : STORE POTENTIAL ERROR VALUE		*/
/*	----------------------------------------------------		*/

	if (( ReturnCode != 0 ) && ((ErrorFlag & 0x0080 ) == 0 )) {

		/* No Local Error Handler So Return Error */
		/* -------------------------------------- */
		err_val = ReturnCode; 
		return(SOFTERROR);
		}

	else	{

		/* Local Error Handling Update */
		/* --------------------------- */
		if ( ErrorFlag & 0x0080 ) {	
			/* Check for Error needs Trapping */
			/* ------------------------------ */
			if ( ReturnCode != 0 ) { 
				LastErreur = ((EXAWORD) (lineptr - TcodeSegment) -1);
				fdex = (TcodeSegment + ErrorLabel); 
				}
			freg [diezreg + 2] = ReturnCode;
			xreg [diezreg + 2] = 0;
			err_val   = 0;
			switch ( ErrorFlag & 0x0060 ) {
				case 0x0060 : 	
					ireg [0] = ireg [ErrorTrap];
					areg [0] = areg [ErrorTrap];
					ErrorTrap = freg [ErrorTrap];
				default	    : 	
					vputs(diezreg + 2,ErrorTrap); 
					break;
				}
			}		
		return(GOODRESULT);
		}

	/* ------------------------ */
}	/* End of Function sf_ngf() */
	/* ------------------------ */

#ifdef INTEL
#include "exprag1.h"
#endif

#endif	/* _EXNGF_C */
	/* -------- */

	
