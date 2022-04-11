/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic  		*/
/*									*/
/*		Module  :	EXNGF - C				*/
/*		Version :	1.4d / 2.1c				*/
/*		Date 	:	15/01/1997				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXOLDNGF_C
#define	_EXOLDNGF_C


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

#ifndef	UNIX
#ifndef	DOS
#ifndef	VMS
VOID	traitfilerror( x , y )
EXAWORD	x,y;
{
	SystemError = (EXALONG) y;	
	errno = y;
	return;
}
#endif
#endif
#endif

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
	if ( ngfop > 15 ) 
		return;
	simcbd = (((EXAWORD) simcode[ngfop]) | 0x2000 ); sfext = 0;
	switch ( fidperm & NGF_TYP ) {
		case NGF_MCBD	: sfext = 0x0100;
				  dbreel = (*(AssignTable + fidbd)).unlog; 
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

/*==========================================================================*/
#endif	/* ABALSI	Preparation of NGF Function Code (Style Amenesik / Sologic)   */

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
		case 0 :
		case 1 :	hugeint = ((LSEEKTYPE) lval * BLOCK);       break;
		case 2 :	hugeint = (bcdtol(lptr,llen) * BLOCK); break;
		case 3 :	hugeint = (atol(lptr,llen) * BLOCK);   break;
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
	struct	talkzone PTR msr;

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
	msr = (struct talkzone PTR ) allocate((USINT) worklen1 + (LONGSIZE * 2) + WORDSIZE);
	if ( msr == (struct talkzone PTR) 0 ) 
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
 *	Preparation des arguaments SI	Search,Down,Modif,Delete,UP 
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
#ifndef	PROLOGUE
#ifndef	DOS
		clen = 120;
#endif
#endif
#ifndef	UNIX
#ifndef	VMS
		clen = fidinfo2;
#endif
#endif
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
				SectWrite(VmemFid,fieldex,VmemLng,(ULONG)(VmemOfs / BLOCK));
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
	if ((prnfid = fidreel) == EX_UNUSED_HANDLE)
		prnfid = 0;	/* Indicates print file handle		 */
	prnptr  = fidbuff; 	/* Pointer to printer buffer		 */
	prnleng = fidblen;	/* Usable Length of printer buffer	 */

#ifdef AIX_VERS
#ifdef	SPARC
	prndex  = fidmc1;		/* Current Offset into Printer buffer	 */
#else
	prndex  = fidmc;		/* Current Offset into Printer buffer	 */
#endif
#else /* AIX_VERS */
	prndex  = fidmc;		/* Current Offset into Printer buffer	 */
#endif /* AIX_VERS */

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

	(*(AssignTable + prndest)).mcext  = prndex;
#ifdef	ABAL21
#ifdef	PROLOGUE
	(*(AssignTable + prndest)).LSeek = prnseek;
#endif
#endif
} 

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
 *	I M _ C L O S E
 *	---------------
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
 *	S F _ C L O S E ()
 *	-------------------------------
 *	General Device / File closing routines
 *
 */

EXAWORD	sf_close()
{
	EXAWORD	ret_cod;
	EXAWORD	holdtrap;
		

	if ( fidreel == EX_UNUSED_HANDLE ) 
		return(0);

	switch( fidperm & NGF_TYP ) {
/*==========================================================================*/
#ifdef ABALSQ
		case NGF_SQ   :	ret_cod = sq_close(fidreel); break;
#endif
/*==========================================================================*/
		case NGF_IM   :
				if ( fidreel != EX_UNUSED_HANDLE ) {
					err_val = Establish_Printer();
					holdtrap = sicico; 
					sicico |= ONSEM_TRP;
#ifdef	PROLOGUE
					(VOID)  printer_close(fidreel);
#else
					(VOID)  im_close(fidreel);
#endif
					sicico = holdtrap;
					fidreel = EX_UNUSED_HANDLE;
					prnfid  = EX_UNUSED_HANDLE;
#ifdef AIX_VERS
#ifdef	SPARC
					prndex  = 0; fidmc1 = 0;
#else
					prndex  = 0; fidmc  = 0;
#endif
#else  /* AIX_VERS */
					prndex  = 0; fidmc  = 0;
#endif /* AIX_VERS */
					ret_cod = 0; errno  = 0;
					prndest = 1;
					break;

					}
				else	{ 
					fidreel = EX_UNUSED_HANDLE;
					prnfid  = EX_UNUSED_HANDLE;
#ifdef AIX_VERS
#ifdef	SPARC
					prndex  = 0; fidmc1 = 0;
#else
					prndex  = 0; fidmc  = 0;
#endif
#else /* AIX_VERS */
					prndex  = 0; fidmc  = 0;
#endif /* AIX_VERS */
					}
				break;
		case NGF_DV   :
/*==========================================================================*/
#ifndef UNIX
#ifndef	VMS
			/* =============================================== */
			/* VIRTUAL VARIABLES DEVICE LIBERATION CHECK 	   */
			/* =============================================== */
			/* Since Neither VMS nor UNIX have specialised     */
			/* Device access functions this check needs only   */
			/* to be performed for Amenesik / Sologic and Dos Versions   */
			/* =============================================== */
			/* Check for External Variable Device to be Closed */
			/* ----------------------------------------------- */
			if ( fidperm & ASS_VIRT_VALID )

				/* Perform Liberate precautions */
				/* ---------------------------- */
				VmemLiberate();


			/* No Errors and Exit */
			/* ------------------ */
			ret_cod = 0; 
			break;
#endif
#endif
/*==========================================================================*/

		case NGF_IO   :

			/* ============================================= */
			/* VIRTUAL VARIABLES FILE : LIBERATION CHECK 	 */
			/* ============================================= */
			/* Check for External Variable File to be Closed */
			/* --------------------------------------------- */
			if ( fidperm & ASS_VIRT_VALID )

				/* Perform Liberate precautions */
				/* ---------------------------- */
				VmemLiberate();

#ifdef PROLOGUE
		case NGF_GR	:
#endif
			/* Attempt low level file close then Exit */
			/* -------------------------------------- */
#ifndef	ABAL_TCPIP
			ret_cod = close(fidreel); 
#else
			ret_cod = ad_close( fidreel );
#endif
			break;

/*==========================================================================*/
#ifdef	ABALSI
		case NGF_SI   : 
#ifdef	ABALMC
		case NGF_MC   : 
#endif
#endif
#ifndef	PROLOGUE
#ifndef	DOS
				ret_cod = aig_unix(_NGF_CLOSE); 
#endif	/* ! DOS  */
#endif	/* ! PRL  */

#ifndef	UNIX
#ifndef	VMS
				simcprep(_NGF_CLOSE);
				ret_cod = si_close(fidreel); 
#endif	/* ! VMS  */
#endif	/* ! NIX  */
				break;

#ifdef	ABALMC
#ifdef	ABALBD
		case NGF_MCBD :	basefile(0);
				remove_bd_record(fidbd,lfh);

#ifndef	PROLOGUE
#ifndef	DOS
				ret_cod = aig_unix(_NGF_CLOSE);
#endif	/* ! DOS  */
#endif	/* ! PRL  */

#ifndef	UNIX
#ifndef	VMS
				simcprep(_NGF_CLOSE);
				ret_cod = si_close(fidreel);
#endif	/* ! VMS  */
#endif	/* ! NIX  */
				break;

		case NGF_BD   : close_base_files( lfh );


#ifndef	PROLOGUE
#ifndef	DOS
				ret_cod = aig_unix(_NGF_CLOSE);
#endif	/* ! DOS  */
#endif	/* ! PRL  */

#ifndef	UNIX
#ifndef	VMS
				simcprep(_NGF_CLOSE);
				ret_cod = si_close(fidreel);
#endif	/* ! VMS  */
#endif	/* ! NIX  */
				break;
#endif	/* ABALBD */
#endif	/* ABALMC */

/*==========================================================================*/
		default	    : errno = EXER_FUNCWOT; ret_cod = MOINS_UN; break;
		}
#ifdef	COEXA
#ifdef	UNIX
	liberlox(fidname);
#endif
#endif	
	return(ret_cod);
}

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
#ifdef AIX_VERS
#ifdef	SPARC
	fidbase  = (BPTR) 0;	fidbd    = 0; fidmc1  = 0; 
#else
	fidbase  = (BPTR) 0;	fidbd    = 0; fidmc   = 0; 
#endif
#else  /* AIX_VERS */
	fidbase  = (BPTR) 0;	fidbd    = 0; fidmc   = 0; 
#endif /* AIX_VERS */
	fidinfo1 = 0;		fidinfo2 = 0;

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
	if (( fidreel != EX_UNUSED_HANDLE ) && ( fidreel < 255 ))
/*		if ( fidbd == 0 ) 		*/
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
	if ( fidperm & ASS_BUFF_VALID ) 
		liberate( fidbuff ); 
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
	return;
}

#ifndef ABAL14

/*
 *	F _ C H G T ( )
 *	---------------
 *
 *	Chargement d'un Utilitaire Systeme	LOAD.GO
 *	----------------------------------	-------
 */

EXAWORD	sf_loadgo()
{
	EXAWORD	mode;
	EXAWORD	x,l;
	EXABYTE	d[2];
	BPTR	execptr;
	EXAWORD	chgtret;

	/* Collect arguament [R] */
	/* --------------------- */
	worklen3 = (EXAWORD) *(fdex++); 
	mode = 0;

	/* Collect possible Arguament */
	/* -------------------------- */
	if (( fargset(2) != SOFTERROR ) 
		/* Check for String (Refuse others) */
		/* -------------------------------- */
	&&  ( worktyp2 != VARB_STR ))
		return(ABAL_TCODCODE);
	else 	{

		/* Pas d'arguament alors Retour Chariot */
		/* ------------------------------------ */
#ifdef PROLOGUE
		d[0] = (EXABYTE) 0x000D; 
#endif
		d[1] = (EXABYTE) 0; 
		workptr2 = (BPTR) &d[0]; worklen2 = 1;
		}

	/* Check For -T or -AT */
	/* ------------------- */
	l = lenuze(fidname,64);
	for ( x = 0; x < l ; x++ ) {
#ifdef  VMS
		if ( *(fidname + x) == STARTLOG ) {
			while ( x < l ) {
				if ( *(fidname + x) == STOPLOG ) 
					break;
				else 	x++;
				}
			}
#endif
		if ( *(fidname + x) == FILESEP ) {
			mode = 1; break; 
			}
		}
	if ( mode == 1 ) {

		/* T-Code File Extension Checking */
		/* ------------------------------ */
#ifndef PROLOGUE
#ifndef DOS

		/* ABAL / BAL Tcode extension checking UNIX or VMS */
		/* ----------------------------------------------- */
		if (( tolower(*(fidname + x + 1)) == FILEEXT ) && ( tolower(*(fidname + x + 2)) == FILEEXT2 ) && ( *(fidname + x + 3) == FILETERM ))
			mode = 2;
		else	{
			if (( tolower(*(fidname + x + 1)) == FILEEXT2 ) && ( *(fidname + x + 2) == FILETERM ))
				mode = 1;
			else	mode = 0;
			}
#endif
#endif
#ifndef UNIX
#ifndef VMS

		/* ABAL / BAL Tcode extension checking Amenesik / Sologic or DOS */
		/* --------------------------------------------------- */
		if (( toupper(*(fidname + x + 1)) == FILEEXT ) && ( toupper(*(fidname + x + 2)) == FILEEXT2 ) && ( *(fidname + x + 3) == FILETERM ))
			mode = 2;
		else	{
			if (( toupper(*(fidname + x + 1)) == FILEEXT2 ) && ( *(fidname + x + 2) == FILETERM ))
				mode = 1;
			else	mode = 0;
			}
#endif
#endif

		}

	/* Check for Automatic Executeur Call */
	/* ---------------------------------- */
	if ( mode != 0 ) {

		/* An executeur is needed */
		/* ---------------------- */
		memcpy((BPTR) askbuf,fidname,(USINT) l);
		askbuf[l] = (EXABYTE) CMDFIELD;
		memcpy((BPTR) (askbuf + l + 1),workptr2,(USINT) worklen2);
		worklen2 += ( l + 1 );
		workptr2 = (BPTR) askbuf;
		if ( mode == 1 ) 
			execptr = (BPTR) ID_EX_BAL;
		else	{ 
#ifdef	PROLOGUE
		/* Since we are under Amenesik / Sologic we can Call OurSelves */
		/* ------------------------------------------------- */
			*(workptr2 + worklen2) = (EXABYTE) 0x000D;
			return(ExaCute((BPTR) workptr2));
#else
			execptr = (BPTR) ID_EX_ABAL; 
#endif
			}
		}
	else	execptr = fidname;

	/* Perform low level System utility Call */
	/* ------------------------------------- */
	chgtret = (EXAWORD) x_exec(execptr,workptr2, 0 );
#ifdef	PROLOGUE
	return (( chgtret & 0x00FF));
#else
	return ( chgtret );
#endif
}

/*
 *	F _ C H A I N ( )
 *	-----------------
 *
 *	Enchainement des modules traduits
 *
 */

EXAWORD	sf_chain()
{
	EXAWORD	x;
	err_val = 0; 

	/* Test for annulation of CHAIN */
	/* ---------------------------- */
	if ( lfh == 0 ) { 
		chain = 0; return(0); 
		}

	/* Eliminate Empty Strings */
	/* ----------------------- */
	if ( fidname == (BPTR) 0 ) 
		return(EXER_SYNTAX);

	/* Check for Buffer already Existant */
	/* --------------------------------- */
	if ( fidperm & ASS_BUFF_VALID ) { 

		/* If True then liberate it */
		/* ------------------------ */
		liberate(fidbuff); 
		fidperm &= 0xFDFF; 
		fidbuff = (BPTR) 0; 
		}

	/* Evaluate Argument */
	/* ----------------- */
	if ( fargset(2) != SOFTERROR ) {

		/* Attempt to Allocate Permanant storage space for ARG */
		/* --------------------------------------------------- */
		if ((workptr1 = (BPTR) allocate((USINT) worklen2+2)) == (BPTR) 0)
			return(EXER_MEMFULL); 

		/* For BAL compatibillity remove leading Spaces */
		/* -------------------------------------------- */
		while ( worklen2 > 0 ) {
			if ( *workptr2 != ' ' ) 
				break;
			else	{ 
				workptr2++; worklen2--; 
				}
			}

		/* Copy ARG to arg storage Zone */
		/* ---------------------------- */
		if ( worklen2 > 0 )
			memcpy(workptr1,workptr2,(USINT) worklen2);

		/* Terminate Arguament String */
		/* -------------------------- */
		*(workptr1 + worklen2) = (EXABYTE) 0x000D;

		/* Establish File Control Table Infos */
		/* ---------------------------------- */
		fidbuff =  workptr1; 		/* Pointer to ARG string 	*/
		fidblen =  (worklen2 + 2);	/* Total Length of ARG	 	*/
		fidperm |= ASS_BUFF_VALID;	/* Indicate buffer needs liberate	*/
		chain   =  lfh;			/* Indicate Chainage Table ID	*/
		err_val =  0;			/* Clear Error Value		*/
		}
	else 	{
		/* If Error Indicates no Further ARGS */
		/* ---------------------------------- */
		if ( err_val == ABAL_TCODCODE ) {

			/* Reset File Control Table Infos OK */
			/* --------------------------------- */
			fidbuff = (BPTR) 0; 	/* No Buffer			*/
			fidblen = 0;		/* No Buffer			*/
			err_val = 0; 		/* Clear Errors			*/
			chain   = lfh;		/* Indicate Chainage Table ID	*/
			}
		}

	/* If no Error has occured Analysis of Filename */
	/* -------------------------------------------- */
	if ( err_val == 0 ) {

		workptr1 = fidname;  x = FNMAX;

		do 	{
			switch ((EXAWORD) *workptr1) {
#ifdef VMS
				case    STARTLOG : 
					while ( ( x > 0 ) 
					&& 	( *workptr1 != STOPLOG ) 
					&& 	( *workptr1 != FILETERM )) { 
						x--; workptr1++; 
						} 
					if ( *workptr1 == STOPLOG ) 
						continue; 
#endif
				case	0x000D	 : 
				case	0x0000	 :
				case	0x0020	 : 
					*workptr1 = FILESEP; 

				case	FILESEP  : 
					workptr1++;
					*(workptr1++) = FILEEXT;
					*(workptr1++) = FILEEXT2;
					*(workptr1++) = FILETERM;
					x = 0; continue;
				default		 : 
					workptr1++; x--; continue; 
				}
			}
		while ( x > 0 );
		*(workptr1) = (EXABYTE) 0;
		} 
	/* Return Resulting Error Value */
	/* ---------------------------- */
	return(err_val);
}

#else	/* ABAL Version 1.3a or Greater */
	/* ---------------------------- */

#include "exloadgo.c"		/* EXECUTEUR FUNCTION : LOAD.GO=nlog 	*/
#include "exchain.c"		/* EXECUTEUR FUNCTION : CHAIN=nlog	*/

#endif

#ifndef PROLOGUE
#ifndef	DOS
#ifndef	COEXA
/*
 *	M A T B ( nlog , ex, c , wr )
 *	-----------------------------
 *
 *	Set file attribute of file 'nlog' to 'ex' and 'c' 
 *
 */


EXAWORD	matb( nlog, ex , c , wr)
EX_FILE_HANDLE nlog;
EXAWORD	ex,c,wr;
{
#ifdef UNIX	/* UNIX */
		/* ---- */

	EXALONG	shareseek;
	int	Cmode;

/* Check for WRITE Permission */
/* -------------------------- */
if ( wr != 0 ) {

	/* Seek to Start of File */
	/* --------------------- */
	shareseek = 0L;
	if (lseek(nlog,shareseek,SEEK_SET) == -1L) 
		return(MOINS_UN);

	/* Separate Action Wrt EX or SHARE */
	/* ------------------------------- */
	if ( ex != 0 ) {
		/* Attempt to place EXCLUSIVE lock */
		/* ------------------------------- */
		if ( lockf(nlog,F_TLOCK,0) != 0 ) {
			/* Failure */
			/* ------- */
			errno = EXER_FILEDO; return(MOINS_UN);				
			}
		}
	else	{
		/* Clear All current Locks */
		/* ----------------------- */
		(VOID) lockf(nlog,F_ULOCK,0);
		shareseek = 1L;
	
		/* Attempt to Establish SHARE lock */
		/* ------------------------------- */
		do	{
			if ( lseek(nlog,shareseek,SEEK_SET) == -1L ) {
				errno = EXER_FILEDO; 
				return(MOINS_UN);		
				}
			errno = 0; shareseek++;
			}
		while	(( lockf(nlog,F_TLOCK,1) != 0 ) 
		&& 	 (errno != ENOLCK) 
		&& (errno != EDEADLK));	
		if ( errno != 0 ) {
			errno = 134;
			return(SOFTERROR);
			}
		}	
	}

	/* Establish Mode COPIE or Mode SECURITY */
	/* ------------------------------------- */
	if ( wr != 0)  
		Cmode = (O_RDWR | O_BINARY);
	else	Cmode = (XO_RDONLY | O_BINARY);

	if ( c  != 0)	
		Cmode |= O_SYNC;

	return(fcntl(nlog,F_SETFL,Cmode)); 

#else	/* MS (or other) DOS */
	/* ----------------- */  
#ifdef VMS
#include "exvmsatb.c"
#endif
#endif	/* UNIX  */
}
#endif	/* COEXA */
#endif	/* ! DOS */
#endif	/* ! PRL */


#ifndef PROLOGUE

/*	E T A T L O X  ( Xfid , Xperm )			*/
/*	-------------------------------			*/
/*							*/ 
/*	Sets the file mode as EXCLUSIVE or SHARED	*/
/*							*/
/*	Note : 	LOCKF requires the file to be opened	*/
/*		with write permission so if the WR flag */
/*		has not been set then exclusivity is	*/
/*		not possible				*/

#ifndef COEXA
EXAWORD	etatlox( xfid , xperm )
EXAWORD	xfid,xperm;
{
#ifdef	UNIX	/* Not DOS nor VMS */
		/* --------------- */
	EXALONG	shareseek;

	/* Check For Exclusive mode already established */
	/* -------------------------------------------- */
	(VOID) lseek((USINT) xfid , 0L , SEEK_SET );
	if ( lockf((USINT) xfid,F_TEST,1) != 0 ) {
		/* Both EX and SHARE are refused here */
		/* ---------------------------------- */
		(VOID) close((USINT) xfid); 
		errno = EXER_FILEDO; 
		return(SOFTERROR);				
		}

	/* Separate EX from SHARE */
	/* ---------------------- */	
	if (( xperm & 2 ) != 0 ) {
		/* Attempt to place EXCLUSIVE lock */
		/* ------------------------------- */
		(VOID) lseek((USINT) xfid , 0L , SEEK_SET );
		errno = 0;
		if ( lockf((USINT) xfid,F_TLOCK,0) != 0 ) {
			/* Failure */
			/* ------- */
			err_val = errno;
			(VOID) close((USINT) xfid); 
			errno = err_val;
			if ((errno == ENOLCK) || (errno == EDEADLK))
				errno = 134;
			else	errno = EXER_FILEDO; 
			return(SOFTERROR);				
			}
		}
	else	{
		/* Check for Write Acces */
		/* --------------------- */
		if (( xperm & 1 ) != 0 ) { 
			shareseek = 1L;		
			do	{
				if ( lseek((USINT) xfid,shareseek,SEEK_SET) == -1L ) {
					/* Failure */
					/* ------- */
					err_val = errno;
					(VOID) close((USINT) xfid); 
					errno = err_val;
					if ((errno == ENOLCK) || (errno == EDEADLK))
						errno = 134;
					else	errno = EXER_FILEDO; 
					return(SOFTERROR);
					}
				errno = 0; shareseek++;
				}
			while	(( lockf((USINT) xfid,F_TLOCK,1) != 0 ) && (errno != ENOLCK ) && (errno != EDEADLK));	
			if (( errno == ENOLCK )  || ( errno == EDEADLK)) { 
				(VOID) close((USINT) xfid); 
				errno = ABAL_NOLOCK;
				return(SOFTERROR); 
				}
			}	
		}
#endif
	return(1);
}
#endif
#endif

#ifndef UNIX	/* If  not UNIX		*/
#ifndef	VMS	/* and not VMS		*/
		/* then PROLOGUE or DOS	*/

#ifdef	ABAL21
EXAWORD	printer_open( prname, propt )
BPTR	prname;
EXAWORD	propt;
{
#ifdef PROLOGUE
	BPTR	aptr;
#endif
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
#ifndef PROLOGUE
	if ((handle = im_open( prname, propt )) != MOINS_UN)
#else
	if ((handle = im_open( prname, propt, mode )) != EX_UNUSED_HANDLE)
#endif
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

/*
 *	S F _ O P E N ( )
 *	-----------------
 *	File or device opening routine (Automatique ! )
 *
 */

EXAWORD sf_open()
{
	EXAWORD	y;

switch( fidperm & NGF_TYP ) {
/*==========================================================================*/
#ifdef ABALSQ
	case NGF_SQ :	fidreel = sq_open( fidname , fidperm );
			break;
#endif
/*==========================================================================*/
	case NGF_IM :	if (( fidperm & NGF_P_E ) != 0 ) {
#ifdef	ABAL21
				fidreel = printer_open( fidname, fidperm );
#else				
				fidreel = im_open( fidname , fidperm ); 
#endif
				errno = err_val;
				}
			else	{
				fidreel = EX_UNUSED_HANDLE; 
				err_val = 56; errno = 56;
				}
			break;

	case NGF_DV :	fidreel = io_open( fidname ); break;
#ifdef	PROLOGUE
	case NGF_GR :
#endif
	case NGF_IO :	y = fidperm;
			if ((fidreel = open( fidname , fidperm )) == EX_UNUSED_HANDLE)
				traitfilerror(MOINS_UN,errno); 
			break;
/*==========================================================================*/
#ifdef ABALSI
	case NGF_SI   :	/* Sequentielle indexe 	*/
#ifdef ABALMC
	case NGF_MC   :	/* Multicritere		*/
#ifdef ABALBD
	case NGF_MCBD : /* Data base File	*/
	case NGF_BD   : /* Dictionaire database	*/
#endif	/* ABALBD */
#endif	/* ABALMC */
			/* Prepare NGF_Code */
			/* ---------------- */
			simcprep(_NGF_OPEN);	
			fidreel = si_open( fidname , fidperm , dbreel);
			break;
#endif	/* ABALSI */
/*==========================================================================*/
#ifdef ABALMSG
	case NGF_CM : /* IPC Message file */

			errno   = 0; fidreel = EX_UNUSED_HANDLE; 
			err_val = 0; break;
#endif	/* ABALMSG */
/*==========================================================================*/
	default	    : /* Non Active Options */
			errno   = EXER_FUNCWOT; 
			fidreel = EX_UNUSED_HANDLE;
			break;
	}
if ( fidreel == EX_UNUSED_HANDLE) 
	return((err_val = errno));
else	return(0);
}
#endif	/* ! VMS */
#endif	/* ! NIX */

#ifndef PROLOGUE	/* If  not PROLOGUE	*/
#ifndef DOS		/* and not DOS		*/
			/* then UNIX and VMS	*/
/*
 *	S F _ O P E N ( )
 *	-----------------
 *	File or device opening routine (Automatique ! )
 *
 */

EXAWORD sf_open()
{
EXAWORD	y;
EXAWORD	ph;

switch( fidperm & NGF_TYP ) {
/*==========================================================================*/
#ifdef ABALSQ	/* Sequentielle acces methode */
		/* -------------------------- */
	case NGF_SQ :	fidreel = sq_open( fidname , fidperm );
			break;
#endif	/* ABALSQ */
/*==========================================================================*/
	case NGF_IM :	/* Printer file / Device opening 	*/
			/* -----------------------------	*/
#ifdef	ABALSPOOL
			ph = im_open(fidname,(fidperm | NGF_I_C));
			if (ph == MOINS_UN)
				fidreel = EX_UNUSED_HANDLE;
			else	fidreel = (EX_FILE_HANDLE)ph;
						/* --------------------- */ 
			errno = err_val;	/* CICO uses err_val !!! */
						/* --------------------- */ 
			break;
#else
			fidperm |= NGF_I_D;
#endif
	case NGF_DV :	/* Raw device Disk etc opening		*/
			/* ---------------------------		*/

	case NGF_IO :	/* Standard Direct Sector Acces files	*/
			/* ----------------------------------	*/
#ifdef	ABAL_TCPIP
			fidreel = ad_open( fidname, fidperm );
#else
#ifdef VMS
			fidreel = open( fidname , fidperm );
#else
		/* First Check for Access Rights */
		/* ----------------------------- */
		if ( Access(fidname,0,((fidperm & NGF_P_E) ? 1 : 0 )) != 0 ) {
			if ( errno != 44 ) 
				errno = 40;
			fidreel = EX_UNUSED_HANDLE;
			break;
			}

		/* Check first for Differred READ/WRITE only */
		/* ----------------------------------------- */ 
		if ((fidperm & NGF_I_D) != 0 ) {		/* Alors Stream Open */
			if ((fidperm & NGF_R_W) != 0 ) {	/* WRITE ONLY	     */
				fidreel = open ( fidname , O_WRONLY , 0);
#ifndef	COEXA
				if ( fidreel != EX_UNUSED_HANDLE) {
					if ( etatlox(fidreel,fidperm) == SOFTERROR ) {
						fidreel = EX_UNUSED_HANDLE;
						break;
						}
					}
#endif	
				}
			else	fidreel = open ( fidname , O_RDONLY , 0);
			}
		/* Else Classique IO / Acces Direct Methods */
		/* ---------------------------------------- */
		else	{
			if ((( fidperm & NGF_R_W) != 0 ) || (( fidperm & NGF_P_E) != 0 )) 
				y = (O_RDWR | O_BINARY);
			else	y = (XO_RDONLY | O_BINARY);
			if ( ( fidperm & NGF_I_C) == 0 ) 
				y |= O_SYNC;
			if ((fidreel = open( fidname , y , 0 )) != MOINS_UN) { 
#ifndef	COEXA
				if ( etatlox(fidreel,fidperm) == SOFTERROR ) {
					fidreel = EX_UNUSED_HANDLE;
					break;
					}
#endif
				}
			}
		if ( fidreel == EX_UNUSED_HANDLE ) { 
			(VOID) liberlox((BPTR) fidname);
			traitfilerror(MOINS_UN,errno);
			}

#endif	/* VMS	      */
#endif	/* ABAL_TCPIP */

			break;
/*==========================================================================*/
#ifdef ABALSI
	case NGF_SI   : /* Sequentielle indexe	*/
#ifdef ABALMC
	case NGF_MC   :	/* Multicritere		*/
#ifdef ABALBD
	case NGF_MCBD : /* Data base file	*/
	case NGF_BD   : /* Data base Dictionary	*/
#endif	/* ABALBD */
#endif	/* ABALMC */
			/* Unix File Dispatcher (Aiguilleur) */
			/* --------------------------------- */
			fidreel = aig_unix(_NGF_OPEN); break;
#endif	/* ABALSI */
/*==========================================================================*/
#ifdef ABALMSG	/* IPC Message file */
		/* ---------------- */
	case NGF_CM : 	errno   = 0; fidreel = EX_UNUSED_HANDLE; 
			err_val = 0; break;
#endif	/* ABALMSG */
/*==========================================================================*/
	default	    : 	/* All non active acces methodes */

			errno   = EXER_FUNCWOT; 
			fidreel = EX_UNUSED_HANDLE; break;
	}
if ( fidreel == EX_UNUSED_HANDLE) 
	return((err_val = errno)); 
else	return(0);
}
#endif	/* UNIX and VMS SF_OPEN */
#endif	/* -------------------- */


#ifndef PRL_SF
#ifndef	VMS
#ifndef	ABAL_TCPIP
/*
 * 	E X T E N D ( lfid , nbsect )
 *	-----------------------------
 *	Adds nbsect Sectors or Blocks to the end of the file
 *	allows pre-allocation or reservation of disk space
 *	for the file
 *
 */

EXAWORD	extend( lfid , nbsect )
EXAWORD	lfid,nbsect;
{

	EXALONG	fin_fic;
	EXABYTE	sbuf[BLOCK];
	EXAWORD	spill;

/* Seek to End of File (if possible) */
/* --------------------------------- */
if (( fin_fic = lseek( lfid , 0L , 2 ) ) == -1L ) { 
	errno = EXER_DEVDESC; 
	return(MOINS_UN); 
	}

/* Check for File end not Complete Sector */
/* -------------------------------------- */
if (( spill = (EXAWORD) (fin_fic % BLOCK)) > 0 ) {

	/* Complete the Last Sector */
	/* ------------------------ */
	(VOID) memset( sbuf , 0 , (USINT) BLOCK );
	if ( lseek(lfid,(EXALONG) ( fin_fic - spill ) , SEEK_SET ) == -1L ) {
		errno = EXER_DEVDESC; return(MOINS_UN); 
		}
	if ( read(	lfid,sbuf,spill) != spill ) {
		errno = EXER_DEVDESC; return(MOINS_UN); 
		}
	if ( lseek(lfid,(EXALONG) ( fin_fic - spill ) , SEEK_SET ) == -1L ) {
		errno = EXER_DEVDESC; return(MOINS_UN); 
		}
	if ( write(lfid,sbuf,BLOCK) != BLOCK ) {
		errno = EXER_VOLFULL; return(MOINS_UN); 
		}
	}
/* Add the New sectors at the end of the file */
/* ------------------------------------------ */
(VOID) memset( sbuf , 0 , (USINT) BLOCK );
while ( nbsect > 0 ) {
	if ( write(lfid,sbuf,BLOCK) != BLOCK ) {
		errno = EXER_VOLFULL; return(MOINS_UN); 
		}
	nbsect--;
	}
/* Clear all Errors */
/* ---------------- */
errno = 0; err_val = 0; return(0);

}

#endif	/* ! ABAL_TCPIP */
#endif	/* ! VMS    	*/
#endif	/* ! PRL_SF 	*/

/*
 *	L O A D F I C H ( )
 *	-------------------
 *	Copies the file table to Globale variables
 */ 

BPTR	assigned_filename( lfh )
EXAWORD	lfh;
{
	return(  (*(AssignTable + lfh)).direcp );
}

EXAWORD	loadfich()
{
	/* Load Current File table Infos  */
	/* -----------------------------  */
#ifdef	PROLOGUE
	if ( stack_inspecter() != 0 )
		return( 666 );
#endif
	fidperm = (*(AssignTable + lfh)).permf;
	fidreel = (*(AssignTable + lfh)).unlog;
	fidname = (*(AssignTable + lfh)).direcp;
	fidbuff = (*(AssignTable + lfh)).asptr;
	fidblen = (*(AssignTable + lfh)).aslen;
	fidbd   = (*(AssignTable + lfh)).dblog;
#ifdef AIX_VERS
#ifdef SPARC
	fidmc1  = (*(AssignTable + lfh)).mcext;
#else
	fidmc   = (*(AssignTable + lfh)).mcext;
#endif
#else /* AIX_VERS */
	fidmc   = (*(AssignTable + lfh)).mcext;
#endif /* AIX_VERS */
	fidbase = (*(AssignTable + lfh)).bdext;

#ifdef	PRL_SF
	fidseek = (*(AssignTable + lfh)).LSeek;
#endif
	fidinfo1 = (*(AssignTable + lfh)).enrdata;
	fidinfo2 = (*(AssignTable + lfh)).enrcle;
#ifdef	ABAL_LAN
	fidnetwork = (*(AssignTable + lfh)).network_info;
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
	(*(AssignTable + lfh)).direcp = fidname;
	(*(AssignTable + lfh)).asptr  = fidbuff;
	(*(AssignTable + lfh)).aslen  = fidblen;
	(*(AssignTable + lfh)).dblog  = fidbd;
	(*(AssignTable + lfh)).bdext  = fidbase;
#ifdef AIX_VERS
#ifdef SPARC
	(*(AssignTable + lfh)).mcext  = fidmc1;
#else
	(*(AssignTable + lfh)).mcext  = fidmc;
#endif
#else  /* AIX_VERS */
	(*(AssignTable + lfh)).mcext  = fidmc;
#endif /* AIX_VERS */

#ifdef	PRL_SF
	(*(AssignTable + lfh)).LSeek = fidseek;
#endif
	(*(AssignTable + lfh)).enrdata = fidinfo1;
	(*(AssignTable + lfh)).enrcle  = fidinfo2;

#ifdef	ABAL_LAN
	(*(AssignTable + lfh)).network_info = fidnetwork;
#endif
	return(0);
}

/*	ASSIGN and NAME		SF/NGF Functions	*/
/*	---------------		----------------	*/	
#include  "exassign.c"
	

#ifndef PROLOGUE
#ifndef DOS
/*==========================================================================*/
/*
 *	E X _ M A T B ( atbperm )
 *	-------------------------
 *	Modification des Attributs d'ouvreture sous UNIX
 *
 */

EXAWORD	ex_matb( atbperm )
EXAWORD	atbperm;
{
	return(0);
}

/*==========================================================================*/
#endif	/* ! DOS */
#endif	/* ! PRL */

#include "exfind.c"

/*
 *	NGF_INFOS()	
 *	-----------
 *	Returns information concerning the current file characteristics
 *	
 *	DATA LENGTH , KEY LENGTH , KEY TYPE
 *
 */

#ifndef	UNIX
#ifndef	VMS

#define	sq_lgdata( fidreel ) fidinfo1
#define	sq_lgcle( fidreel )  0
#define	sq_type( fidreel ) 0x0001
#define	si_lgdata( fidreel ) fidinfo1
#define	si_lgcle( fidreel ) fidinfo2
#define	si_type( fidreel ) 0x0002

#endif	/* ! VMS  */
#endif 	/* ! UNIX */
	
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

#include "exrdwr.c"

#ifdef	ABAL_CORE
#include "excore.c"
#endif

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

#ifdef	ABAL21
				/* -------------------------------------- */
EXAWORD	LastHandle;		/* Storage of ASSIGN handle used for last */
				/* NGF operation READ WRITE OPEN etc	  */
				/* -------------------------------------- */
#endif

EXAWORD	sf_ngf()
{
#ifdef UNIX
struct stat stat_buf;
#endif
#ifdef ABALSF

	/* Local Variables */
	/* --------------- */
	EXAWORD	sfx,etrap,ret_cod,eptr,eflag;
	EXAWORD	fperm;
	EXAWORD	ngfop;
        EXAWORD	y,z;
	EXAWORD	probe;


	/* Initialise Error Code and collect NGF function code */
	/* --------------------------------------------------- */
	ret_cod = 0; sfx = (EXAWORD) *(fdex++); SystemError = 0L;

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
		eptr = Tcodeword( fdex); fdex += WORDSIZE;

		/* Test for and Collect Variable ID */
		/* -------------------------------- */
		if ( (adesc & 0x0060) != 0x0060 ) { 
			etrap = Tcodeword( fdex);
			fdex += WORDSIZE;
			}
		else 	/* Else collect Register ID */
			/* ------------------------ */
			etrap = (EXAWORD) *(fdex++); 

		/* Indicate ON LOCAL ERROR GOTO */
		/* ---------------------------- */
		eflag = adesc;

		/* Adjust arg manager information */
		/* ------------------------------ */
		amode =2;

		}
	else 	/* Indicate ON LOCAL ERROR ABORT */
		/* ----------------------------- */
		eflag = 0; 

/* Collect Internal file handle */
/* ---------------------------- */
if ( fargset(1) != SOFTERROR ) 	{ 

  /* Control file handle for Validity */
  /* -------------------------------- */
  if ( check_valid_assign_handle((lfh = (EXAWORD) workval1)) == SOFTERROR ) {
	ret_cod = err_val;
	probe = 1;
	}
  else 	{
  probe = 0;		/* Rewrite of file table is possible	*/
#ifdef ABAL21
 LastHandle = lfh;	/* Store Assign Handle for Conf(27)	*/
#endif

  /* Establish File control variables */
  /* -------------------------------- */
 if ((err_val = loadfich()) != 0)
	return( SOFTERROR );

  fperm = fidperm & NGF_TYP;

  /* Test for ASSIGN ACCESS METHOD Available */
  /* --------------------------------------- */
  if ((err_val = Available_Option((fidperm & NGF_TYP))) != 0) {
	ret_cod = err_val; goto ngferro;
	}

  /* Check for file not OPEN */
  /* ----------------------- */
  if ( fidreel == EX_UNUSED_HANDLE ) {	
	/* Eliminate Codes which do not require an open file */
	/* ------------------------------------------------- */
	switch ( sfx & 0x007F ) 	{
		case _NGF_LOADGO	:
		case _NGF_CHAIN		:
		case _NGF_DFILE		:
		case _NGF_KEY           :
		case _NGF_RKEY          :
		case _NGF_FKEY          :
#ifdef UNIX
		case _NGF_RENAME	:
#endif	/* UNIX */
		case _NGF_FIND		:
		case _NGF_CFILE 	:
		case _NGF_OPEN		: 
		case _NGF_CLOSE		: 
#ifdef	ABAL_CORE
		case _NGF_CORE		:
#endif		
#ifdef	ABAL21
		case _NGF_NAME		:
#endif
			/* Check for valid ASSIGN file entry */
			/* --------------------------------- */
			if ((fidperm & ASS_NAME_VALID) == 0) { 
				ret_cod = MOINS_UN;
				errno = ABAL_NUMLOG116;
				}
		case _NGF_ASSIGN 	:

					  break;
		default			:
				/* Check for valid ASSIGN file entry */
				/* --------------------------------- */
				if ((fidperm & ASS_NAME_VALID) == 0) { 
					probe = 1;	/* Do not Rewrite */
					ret_cod = MOINS_UN;
					errno = ABAL_NUMLOG116;
					}
				else	{
					 if ( fperm != NGF_CM) {
						sf_open();
					  	if ( fidreel == EX_UNUSED_HANDLE ) 
							ret_cod = MOINS_UN;
						}
					}
		}
	}
  else  {
	/* Check for Automatic file close required */
	/* --------------------------------------- */
	switch ( sfx & 0x007F ) {
#ifdef	UNIX
		case _NGF_RENAME :
#endif  /* UNIX */
		case _NGF_DFILE  :
		case _NGF_OPEN   :
		case _NGF_CFILE  :
			if ( (ret_cod = sf_close() ) != MOINS_UN )
				fidreel = EX_UNUSED_HANDLE;
		}
	}

/*	EXECUTEUR ABAL FILE and DEVICE INTERFACE FUNCTIONS
 *	--------------------------------------------------
 *	Certain of these functions may be unavailable on specific
 *	file access methods or ressource characteristiques.
 */

/* Check for Error due to Auto Open/Close or No Assign */
/* --------------------------------------------------- */
if ( ret_cod != MOINS_UN ) {

#ifdef	ABALSI
	/* Prepare SI MC access codes */
	/* -------------------------- */
	simcprep((sfx & 0x007F));
#endif
	/* Establish default error conditions */
	/* ---------------------------------- */
	ret_cod = MOINS_UN; errno = EXER_FUNCWOT;

	/* Select ABAL NGF function */
	/* ------------------------ */
	switch ( sfx & 0x007F ) {

/*	Special Functions
 *	-----------------
 *	ASSIGN 	Declares the file or ressource for exploitation by EX
 *	LOAD.GO Execute utilitaire systeme
 *	CHAIN	Prepares the T-Code Chaining system
 *	FIND	Searches directory for file name 
 *	CORE	Performs dump of current executer core image
 *	NAME	Returns Current Assign Name and Type
 */

case	_NGF_ASSIGN	:	ret_cod = sf_assign();	break;
case	_NGF_LOADGO	:	ret_cod = sf_loadgo();
				errno &= 0x00FF;	break;
case	_NGF_CHAIN	:	ret_cod = sf_chain();	break;
case	_NGF_FIND	:	ret_cod = sf_find();	break;

#ifdef	ABAL_CORE
case	_NGF_CORE	:	ret_cod = sf_core();	break;
#endif

#ifdef	ABAL21
case	_NGF_NAME	:	ret_cod = sf_name();	break;
#endif 

/*	NGF CREATE ( Nlog , [ access method specific params ] )
 *	-------------------------------------------------------
 *	This function will create any of the 5 basic file types wrt
 *	file type declared in the relevant ASSIGN function.
 *	Errors may be due to : No write permission, File already exists,
 *	Unable to create a device/ressource or unsupported file access
 *	types.
 */

case _NGF_CFILE  :
	if ( (fidperm & NGF_R_W) == 0 ) { 
		ret_cod = ABAL_WRITPROT; 
		break; 
		}
#ifdef UNIX
	y = 0666;
#else
	y=0;
#endif
#ifndef	PROLOGUE
	y |= (O_BINARY | O_RDWR);
#endif
	fmtchk = (EXAWORD) *(fdex++);	/* Collect extra descriptor */
	workval1 = 0; workval2 = 0; errno = 0; fidreel = EX_UNUSED_HANDLE;
	z = 0;

	/* Establish Data and Key Lengths */
	/* ------------------------------ */
	if ( fargset(1) != SOFTERROR ) { 
		z |= 0x0010; 
		if ( fargset(2) != SOFTERROR ) 
			z |= 0x0020;
		}
	else	{ 
		workval1 = 0; 
		z |= 0x0010; 
		}

	errno = EXER_SYNTAX;	/* Default Error Code */
	switch( fperm ) {
#ifdef ABALSQ
		case NGF_SQ   : if ( z & 0x0010 ) {
					if ( workval1 == 0 ) 
						workval1 = 256; 
					fidreel = sq_creat( fidname , (EXAWORD) workval1 , fidperm); 
					}
				break;
#endif
		case NGF_IO   : if (access(fidname,0) == 0 ) {
					fidreel = EX_UNUSED_HANDLE;
					errno = EXER_FILEDE;
					break;
					}
#ifndef UNIX
				fidreel = creat( fidname , fidperm ); 
#endif
#ifndef PROLOGUE
#ifndef VMS
#ifndef DOS
#ifdef	ABAL_TCPIP	
				fidreel = ad_creat( fidname , fidperm );
#else
				if ((fidreel = creat( fidname , 0666 )) != EX_UNUSED_HANDLE) {
					(VOID) close(fidreel);
					if ( Access(fidname,0,((fidperm & NGF_P_E)? 1 : 0)) == 0 ) { 
						y = ( O_RDWR | O_BINARY);
						if ( ( fidperm & NGF_I_C) == 0 ) 
							y |= O_SYNC; 
						if ((fidreel = open( fidname , y , 0 )) != MOINS_UN) { 
#ifndef	COEXA						
							if ( etatlox(fidreel,fidperm) == SOFTERROR ) {
								if ( errno == ABAL_NOLOCK ) { 
									unlink(fidname); 
									errno = ABAL_NOLOCK;
									}
								else 	errno   = EXER_FILEDO; 
								fidreel = EX_UNUSED_HANDLE;
								break;
								}
#endif
							}
						}
					else	fidreel = EX_UNUSED_HANDLE;
					}
#endif	/* ABAL_TCPIP */
				if ( fidreel == EX_UNUSED_HANDLE) 
					traitfilerror(MOINS_UN,errno);
#endif
#endif
#endif
				break;
/*===========================================================================*/
#ifndef	PROLOGUE
#ifndef	DOS
#ifdef	ABALSI
		case NGF_SI	:
#ifdef	ABALMC
		case NGF_MC	:
#ifdef	ABALBD
		case NGF_MCBD	:
		case NGF_BD	: 
#endif	/* ABALBD */
#endif	/* ABALMC */
		fidreel = aig_unix(_NGF_CFILE); break;
#endif	/* ABALSI */
#endif	/* ! DOS  */
#endif	/* ! PRL  */
/*===========================================================================*/
#ifndef	UNIX
#ifndef	VMS
#ifdef ABALSI
		case NGF_SI   :
#ifdef ABALMC
		case NGF_MC   :
#ifdef ABALBD
		case NGF_MCBD : 
		case NGF_BD   : 
#endif	/* ABALMC */
#endif	/* ABALBD */
				fidreel = si_create(fidname,workval2,workval1,fidperm ,(fmtchk & 7),dbreel);
				break;
#endif	/* ABALSI */
#endif	/* ! VMS  */
#endif	/* ! NIX  */
/*===========================================================================*/
		default	      :	errno = EXER_FUNCWOT; break;
		}

	if ( fidreel == EX_UNUSED_HANDLE) 
		ret_cod = errno;
	else 	ret_cod = 0;
	break;

/*===========================================================================*/
/*	NGF ERASE ( Nlog , [ Access specific params ] )
 *	-----------------------------------------------
 *	This function will erase the filename(s) from the current directory
 *	Errors may be due to : File already open, File inexistant
 *	Unknown access type etc.
 */
	
case _NGF_DFILE	 :
	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 ) { 
		ret_cod = ABAL_WRITPROT; break; 
		}
#ifdef UNIX
#ifdef AIX_VERS
	if ( ( (fidperm & NGF_TYP) == NGF_SQ) || ( (fidperm & NGF_TYP) == NGF_IO) )
	 {
	  if (stat(fidname,&stat_buf) == 0)
#else
	if (stat(fidname,&stat_buf)!= MOINS_UN)
#endif

	{
		if(S_ISDIR(stat_buf.st_mode))
		{
			ret_cod =EXER_FORBID;
			break;
		}
	}
	else
	{
		traitfilerror( MOINS_UN, errno );
		ret_cod = err_val = errno;
		break;
	}
#ifdef AIX_VERS
	}
#endif

#endif  /* UNIX */

	fmtchk = (((EXAWORD) *(fdex++)) & 0x0003);
	y = (*(AssignTable + fidbd)).unlog;
	switch ( fperm ) {
		case NGF_IO   :
/*===========================================================================*/
#ifdef ABALSQ
		case NGF_SQ   :	
#endif
/*===========================================================================*/
#ifdef	ABAL_TCPIP

			ret_cod = ad_sq_delete( fidname, fidperm );

#else	/* ! ABAL_TCPIP */

			if ( Access((BPTR) fidname,0,1) == 0 ) {
#ifdef	COEXA
				(VOID)    liberlox((BPTR) fidname);
#endif

				if ((ret_cod = unlink((BPTR) fidname)) == MOINS_UN) {
#ifdef	UNIX
					traitfilerror( MOINS_UN, errno );
#endif
					ret_cod = err_val = errno;
					}
				}
			else	{
				if ( errno == 44 ) 
					ret_cod = errno;
				else	{
#ifdef	UNIX
					traitfilerror( MOINS_UN, errno );
#endif
					ret_cod = err_val = errno;
					}
				}
#endif	/* ABAL_TCPIP */
			break;
/*===========================================================================*/
#ifndef	PROLOGUE
#ifndef	DOS
#ifdef	ABALSI
		case NGF_SI	:
#ifdef	ABALMC
		case NGF_MC	:
#ifdef	ABALBD
		case NGF_MCBD	:
		case NGF_BD	: 
#endif	/* ABALBD */
#endif	/* ABALMC */
				ret_cod = aig_unix(_NGF_DFILE); break;
#endif	/* ABALSI */
#endif	/* ! DOS  */
#endif	/* ! PRL  */
/*===========================================================================*/
#ifndef	UNIX
#ifndef	VMS
#ifdef	ABALSI
		case NGF_SI	:
#ifdef	ABALMC
		case NGF_MC	:
#ifdef	ABALBD
		case NGF_MCBD	:
		case NGF_BD	: 
#endif	/* ABALBD */
#endif	/* ABALMC */
			ret_cod = si_unlink(fidname,fmtchk,y); break;
#endif	/* ABALSI */
#endif	/* ! VMS  */
#endif	/* ! NIX  */
/*===========================================================================*/
		default	      : ret_cod = EXER_FUNCWOT;
		}

	fidreel = EX_UNUSED_HANDLE;

	if ( ret_cod == MOINS_UN ) 
		ret_cod = errno;

	break;

/*	NGF RENAME ( Oldname , Newname )
 *	--------------------------------
 *	Renames the file(s) indicated by Nlog as Newname
 *	Errors should be self-evident. (Duplicate or illegal names or
 *	illegal acess etc ).
 */

case _NGF_RENAME :
	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 ) { 
		ret_cod = ABAL_WRITPROT; 
		break;
		}

	/* Check for EXCLUSIVE Option     */
	/* ------------------------------ */
	if ((fidperm & NGF_P_E) == 0 ) 	{ 
		ret_cod = 44; 
		break; 
		}

	/* Collect NewName Arguament      */
	/* ------------------------------ */
	if ( fargset(1) != SOFTERROR ) 	{ 
		workptr2 = (TcodeByteStack + worktop);
		worklen2 = lenuze(workptr1,worklen1);
		if (( worktop + worklen2 ) > dieztmp ) {
			ret_cod = 114; 
			break;
			}
		if ( worklen2 > 0 )
			(VOID) memcpy( workptr2 , workptr1 , (USINT) worklen2 );
		*(workptr2 + worklen2) = FILETERM;
		workptr1 = workptr2; 
		worklen1 = worklen2;
		switch( fperm ) {
#ifndef	UNIX
			case NGF_IO   : 
#ifdef	ABALSQ
			case NGF_SQ   : 
#endif	
				ret_cod = ngf_rename(workptr1,fidreel,0x202C); 
				break;
#endif

#ifndef PROLOGUE
#ifndef VMS
#ifndef DOS
			case NGF_IO   : 
#ifdef ABALSQ
			case NGF_SQ   : 
#endif
#ifdef	ABAL_TCPIP
				ret_cod = ad_sq_rename(fidname,workptr1); 
				break;
#else
				ret_cod = xrename(fidname,workptr1); 
				break;
#endif	/* ABAL_TCPIP */
#endif  /*   DOS  */
#endif	/*   VMS  */
#endif	/*   PRL  */

#ifndef	UNIX
#ifndef	VMS
#ifdef  ABALSI
			case NGF_SI   :
#ifdef	ABALMC
			case NGF_MC   :
#ifdef	ABALBD
			case NGF_BD   :
			case NGF_MCBD : 
#endif	/* ABALBD */
#endif	/* ABALMC */
				(VOID) simcprep(_NGF_RENAME);
				ret_cod = ngf_rename(workptr1,fidreel,simcbd);
				break;
#endif	/* ABALSI */
#endif	/* ! VMS  */
#endif	/* ! NIX  */

#ifndef PROLOGUE
#ifndef	DOS
#ifdef	ABALSI
			case NGF_SI   :
#ifdef	ABALMC
			case NGF_MC   :
#ifdef	ABALBD
			case NGF_BD   :
			case NGF_MCBD : 
#endif	/* ABALBD */
#endif	/* ABALMC */
				ret_cod = aig_unix(_NGF_RENAME); 
				break;
#endif	/* ABALSI */
#endif	/* ! DOS  */
#endif	/* ! PRL  */
			default	     : 

				ret_cod = MOINS_UN; 
				errno = EXER_FUNCWOT;

			}
		/* Check for RENAME errors */
		/* ----------------------- */
		if ( ret_cod == MOINS_UN ) 
			ret_cod = errno; 
		else 	{
			/* Ensure ABAL knows the new file name */
			/* ----------------------------------- */
			liberate_for_assign(fidname); 
			if ( setname() == SOFTERROR ) 
				ret_cod = err_val; 
			}
		}
	else 	ret_cod = err_val;
	break;

/*	NGF OPEN ( Nlog , [ Access method specific params ] )
 *	-----------------------------------------------------
 *	Opens the file or device wrt to permissions supplied in
 *	the corresponding ASSIGN function.
 */

case _NGF_OPEN   :
	sf_open();
	if ( fidreel == EX_UNUSED_HANDLE ) 
		ret_cod = errno; 
	else 	ret_cod = 0; 
	break;

/*	NGF CLOSE ( Nlog )
 *	------------------
 *	Closes the file or device specified by Nlog
 */

case _NGF_CLOSE  :
	ret_cod = sf_close();
	if ( ret_cod == 0 ) 
		fidreel = EX_UNUSED_HANDLE;
	break;

case _NGF_EXTEND	:
	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 ) { 
		ret_cod = ABAL_WRITPROT; 
		break; 
		}

	switch( fperm ) {
		case	NGF_DV	:
		case	NGF_CM	:
		case	NGF_IM	:
		case	NGF_GR	: 

			ret_cod = ABAL_OPNOTPOSS; 
			break;
#ifndef PROLOGUE
#ifdef	ABALSI
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#endif	/* ABALMC */
#ifdef	ABALBD
		case NGF_BD   :
		case NGF_MCBD : 
#endif	/* ABALBD */
			if ( fargset(1) == SOFTERROR ) { 
				ret_cod = err_val; 
				break; 
				}
			ret_cod = 0; 
			err_val = 0; 
			errno = 0;
			break;
#endif	/* ABALSI */
#endif  /* ! PRL  */

		default		: 

			if ( fargset(1) == SOFTERROR ) { 
				ret_cod = err_val; 
				break; 
				}
#ifdef	ABAL_TCPIP
			ret_cod = ad_sq_extend(fidreel , workval1 );
#else
			ret_cod = extend(fidreel , workval1 );
#endif	/* ABAL_TCPIP */
			break;
		}
	break;

/*	NGF READ ( Nlog, Debut, Destvar, Length, [ access specific params ] )
 *	---------------------------------------------------------------------
 *	This function reads or writes Length octets from or to the file
 * 	or device specified by Nlog into or from the buffer indicated by 
 *	Destvar starting at file position Debut. 
 *
 *	N.B.	The significance of "Debut" is relative to the file or
 *		device requirements. In certain cases this may be ignored.
 *
 *	TCODE STRUCTURES
 *	----------------
 *	NGF , READ  , DESC , ERROR , HANDLE , CODE , BUFFER , LENGTH , SECTOR
 *	NGF , WRITE , DESC , ERROR , HANDLE , CODE , BUFFER , LENGTH , SECTOR
 */

case _NGF_WRITE	 :

	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 ) { 
		ret_cod = ABAL_WRITPROT; 
		break; 
		}

case _NGF_READ   :

	/* Perform ACCESS METHOD DEPENDANT read or write operation */
	/* ------------------------------------------------------- */
	ret_cod = sf_read_write(); 
	break;


#ifdef ABALSQ
/*==========================================================================*/
case	_NGF_REWIND	:
	switch( fperm ) {

		case 	NGF_SQ	:	
			ret_cod = sq_rewind(fidreel); 
			break;

		default		:
			ret_cod = ABAL_OPNOTPOSS; 
			break;
		}
	break;
/*==========================================================================*/
#endif

	/* Modification des Attributs d'exploitation */
	/* ----------------------------------------- */

case _NGF_ATB	 :

	/* Create Temporary Permissions Word */
	/* --------------------------------- */
	y = ((fidperm & 0xFFF9) | ( ((EXAWORD) *(fdex++)) << 1) );

	switch( fperm ) {

#ifndef	PROLOGUE
#ifndef	DOS
#ifdef	ABALSI
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#ifdef	ABALBD
		case NGF_MCBD : 
		case NGF_BD   :
#endif	/* ABALBD */
#endif	/* ABALMC */
			z = fidperm; 
			fidperm = y;
			if ((ret_cod = aig_unix(_NGF_ATB)) != 0)
				fidperm = z; 
			break;
#endif	/* ABALSI */
#endif	/* ! DOS  */
#endif	/* ! PRL  */

#ifndef	UNIX
#ifndef	VMS
#ifdef	ABALSI
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#ifdef	ABALBD
		case NGF_MCBD : 
		case NGF_BD   : 
#endif	/* ABALBD */
#endif	/* ABALMC */
			if ((ret_cod = si_matb(fidreel , y )) == 0) 
				fidperm = y; 
			break;

#endif	/* ABALSI */
#endif	/* ! VMS  */
#endif	/* ! NIX  */

		default       : 

#ifdef	COEXA

#ifdef	ABAL_TCPIP
			if ((ret_cod = ad_sq_matb(fidname,((y & NGF_P_E) >> 1),((y & NGF_I_C) >> 2),(y & NGF_R_W))) == 0 )
#else
			if ((ret_cod = matb(fidname,((y & NGF_P_E) >> 1),((y & NGF_I_C) >> 2),(y & NGF_R_W))) == 0 )
#endif	/* ABAL_TCPIP */
#else	/* ! COEXA */
			if ((ret_cod = matb(fidreel,((y & NGF_P_E) >> 1),((y & NGF_I_C) >> 2),(y & NGF_R_W))) == 0 )
#endif	/* COEXA */
				fidperm = y;
			break;

		}
	break;


#ifdef ABALSI
/*==========================================================================*/
/* SISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISI */
/* SISISISISISISI                                            SISISISISISISI */
/* SISISISISISISI   S E Q U E N T I E L L E   I N D E X E    SISISISISISISI */
/* SISISISISISISI                                            SISISISISISISI */
/* SISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISISI */
/*==========================================================================*/

	/* Insertion d'une nouvelle cle plus article */
	/* ----------------------------------------- */

case _NGF_INSERT :
	switch( fperm ) {
#ifndef	PROLOGUE
#ifndef	DOS
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#ifdef	ABALBD
		case NGF_MCBD :	
#endif	/* ABALBD */
#endif	/* ABALMC */
			if ( si_prep(1) == SOFTERROR )
				ret_cod = err_val; 
			else	ret_cod = aig_unix(_NGF_INSERT); 
			break;
#endif	/* ! DOS */
#endif	/* ! PRL */

#ifndef	UNIX
#ifndef	VMS
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#ifdef	ABALBD
		case NGF_MCBD :	
#endif	/* ABALBD */
#endif	/* ABALMC */
			if ( si_prep(1) == SOFTERROR ) 
				ret_cod = err_val;
			else	ret_cod = si_insert(fidreel,si_cle,si_mq,si_buf,si_lng);
			break;
#endif	/* ! VMS */
#endif	/* ! NIX */

		}
	break;

	/* Supression d'une cle + article ou Niveau  */
	/* ----------------------------------------- */

case _NGF_DELETE :
	switch( fperm ) {
#ifndef	PROLOGUE
#ifndef	DOS
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#ifdef	ABALBD
		case NGF_MCBD :	
#endif	/* ABALBD */
#endif	/* ABALMC */
			if ( si_prep(1) == SOFTERROR ) 
				ret_cod = err_val;
			else	ret_cod = aig_unix(_NGF_DELETE); 
			break;
#endif	/* ! DOS */
#endif	/* ! PRL */

#ifndef	UNIX
#ifndef	VMS
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#ifdef	ABALBD
		case NGF_MCBD :	
#endif	/* ABALBD */
#endif	/* ABALMC */
			if ( si_prep(1) == SOFTERROR ) 
				ret_cod = err_val;
			else	ret_cod = si_delete(fidreel,si_cle,si_mq);
			break;
#endif	/* ! VMS */
#endif	/* ! NIX */
		}
	break;

	/* Modification d'un article ou Niveau d'Index (Mq) */
	/* ------------------------------------------------ */

case _NGF_MODIFY :
	switch( fperm ) {
#ifndef	PROLOGUE
#ifndef	DOS
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#ifdef	ABALBD
		case NGF_MCBD :	
#endif	/* ABALBD */
#endif	/* ABALMC */
			if ( si_prep(1) == SOFTERROR ) 
				ret_cod = err_val; 
			else	ret_cod = aig_unix(_NGF_MODIFY); 
			break;

#endif	/* ! DOS */
#endif	/* ! PRL */

#ifndef	UNIX
#ifndef	VMS
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#ifdef	ABALBD
		case NGF_MCBD :	
#endif	/* ABALBD */
#endif	/* ABALMC */
			if ( si_prep(1) == SOFTERROR ) 
				ret_cod = err_val; 
			else	ret_cod = si_modif(fidreel,si_cle,si_mq,si_buf,si_lng);
			break;
#endif	/* ! VMS */
#endif	/* ! NIX */
		}
	break;

	/* Recherche de Cle + Article + Index */
	/* ---------------------------------- */
case _NGF_SEARCH :
	switch( fperm ) {
#ifndef	PROLOGUE
#ifndef	DOS
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#ifdef	ABALBD
		case NGF_MCBD :	
#endif	/* ABALBD */
#endif	/* ABALMC */
			if ( si_prep(0) == SOFTERROR ) 
				ret_cod = err_val; 
			else	ret_cod = aig_unix(_NGF_SEARCH); 
			break;

#endif	/* ! DOS */
#endif	/* ! PRL */

#ifndef	UNIX
#ifndef	VMS
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#ifdef	ABALBD
		case NGF_MCBD :	
#endif	/* ABALBD */
#endif	/* ABALMC */
			if ( si_prep(0) == SOFTERROR ) 
				ret_cod = err_val; 
			else	ret_cod = si_search(fidreel,si_ver,si_flg,si_cle,si_mq,si_buf,si_lng);
			break;
#endif	/* ! VMS */
#endif	/* ! NIX */
		}
	break;

	/* Lecture Sequentielle Croissante */
	/* ------------------------------- */

case _NGF_DOWN 	 :
	switch( fperm ) {
#ifndef	PROLOGUE
#ifndef	DOS
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#ifdef	ABALBD
		case NGF_MCBD :	
		case NGF_BD   :
#endif	/* ABALBD */
#endif	/* ABALMC */
			if ( si_prep(0) == SOFTERROR ) 
				ret_cod = err_val; 
			else	ret_cod = aig_unix(_NGF_DOWN); 
			break;

#endif	/* ! DOS */
#endif	/* ! PRL */

#ifndef	UNIX
#ifndef	VMS
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#ifdef	ABALBD
		case NGF_MCBD :	
		case NGF_BD   :
#endif	/* ABALBD */
#endif	/* ABALMC */
			if ( si_prep(0) == SOFTERROR ) 
				ret_cod = err_val; 
			else	ret_cod = si_down(fidreel,si_ver,si_flg,si_mq,si_buf,si_lng);
			break;
#endif	/* ! VMS */
#endif	/* ! NIX */
		}
	break;

	/* Lecture Sequentielle De-Croissante */
	/* ---------------------------------- */

case _NGF_UP   	 :
	switch( fperm ) {
#ifndef	PROLOGUE
#ifndef	DOS
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#ifdef	ABALBD
		case NGF_MCBD :	
		case NGF_BD   :
#endif	/* ABALBD */
#endif	/* ABALMC */
			if ( si_prep(0) == SOFTERROR ) 
				ret_cod = err_val;
			else	ret_cod = aig_unix(_NGF_UP); 
			break;
#endif	/* ! DOS */
#endif	/* ! PRL */

#ifndef	UNIX
#ifndef	VMS
		case NGF_SI   :
#ifdef	ABALMC
		case NGF_MC   :
#ifdef	ABALBD
		case NGF_MCBD :	
		case NGF_BD   :
#endif	/* ABALBD */
#endif	/* ABALMC */
			if ( si_prep(0) == SOFTERROR ) 
				ret_cod = err_val;
			else	ret_cod = si_up(fidreel,si_ver,si_flg,si_mq,si_buf,si_lng);
			break;
#endif	/* ! VMS */
#endif	/* ! NIX */
		}
	break;

#ifdef ABALMC
/*==========================================================================*/
/* MCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMC */
/* MCMCMCMCMCMCMC                                            MCMCMCMCMCMCMC */
/* MCMCMCMCMCMCMC        M U L T I  -  C R I T E R E         MCMCMCMCMCMCMC */
/* MCMCMCMCMCMCMC                                            MCMCMCMCMCMCMC */
/* MCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMCMC */
/*==========================================================================*/

case	_NGF_KEY	: 
	ret_cod = rubrdcl();
	break;

case	_NGF_CKEY	: 
	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 ) 
		ret_cod = ABAL_WRITPROT;
	else	ret_cod = rubrdef(); 		
	break;

case	_NGF_NKEY	: 
	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 ) 
		ret_cod = ABAL_WRITPROT; 
	else	ret_cod = rubrnom();
  	break;

case	_NGF_FKEY	: 
	ret_cod = rubrfld();
	break;

case	_NGF_RKEY	: 
	ret_cod = rubrraz();
	break;

case	_NGF_LKEY	: 
	ret_cod = rubrlst(0x205B,0);  
	break;

case	_NGF_LINK	: 
	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 ) 
		ret_cod = ABAL_WRITPROT;
	else	ret_cod = linkwork(0x20AF,0); 
	break;

case	_NGF_CLINK	: 
	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 )
		ret_cod = ABAL_WRITPROT;
	else	ret_cod = linkwork(0x20B7,1);
	break;

case	_NGF_LLINK	: 
	ret_cod = rubrlst(0x205F,0);
	break;

case	_NGF_POSIT	:
case	_NGF_COUNT	: 
	ret_cod = intero(0x20A3,sfx & 1); 
	break;

case	_NGF_STATS	: 
	if ((fperm & NGF_MC) == NGF_MC) 
		ngfop = 0x207B;
	else 	ngfop = 0x207A;
	ret_cod = rubrlst(ngfop,0); 
	break;

#ifdef ABALBD
/*==========================================================================*/
/* BDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBD */
/* BDBDBDBDBDBDBD                                            BDBDBDBDBDBDBD */
/* BDBDBDBDBDBDBD        B A S E  de  D O N N E E S          BDBDBDBDBDBDBD */
/* BDBDBDBDBDBDBD                                            BDBDBDBDBDBDBD */
/* BDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBD */
/*==========================================================================*/

case	_NGF_RECORD	: 
	ret_cod = bdrecord();
	break;

case	_NGF_JOIN	: 
	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 ) 
		ret_cod = ABAL_WRITPROT;
	else	ret_cod = dcljoin(); 
	break;

case	_NGF_CJOIN	: 
	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 ) 
		ret_cod = ABAL_WRITPROT;
	else	ret_cod = makejoin();
	break;

case	_NGF_DJOIN	: 
	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 ) 
		ret_cod = ABAL_WRITPROT;
	else	ret_cod = suprjoin();
	break;

case	_NGF_RJOIN	: 
	/* Check for WRITE Option allowed */
	/* ------------------------------ */
	if ( (fidperm & NGF_R_W) == 0 ) 
		ret_cod = ABAL_WRITPROT;
	else	ret_cod = namejoin();
	break;

case	_NGF_LJOIN	: 
	ret_cod = rubrlst(0x205E,7);
	break;
case	_NGF_LFILE	: 
	ret_cod = rubrlst(0x205E,3);
	break;

/*==========================================================================*/
#endif	/* ABALBD	Fonctions Niveaux Base de donnees 	*/
#endif	/* ABALMC	Fonctions Niveaux Multicritere		*/
#endif	/* ABALSI	Fonctions Niveaux Sequentielle Indexe	*/
	}
      }
   }
}
/*	EXIT TREATMENT
 *	--------------
 *	Local error trap handling is performed here in case of errors.
 */
	/* Store current file control variables */
	/* ------------------------------------ */
	if (( probe == 0 ) 
	&&  ((err_val = savefich()) != 0))
		return( SOFTERROR );

	if ( ret_cod == MOINS_UN ) 
		ret_cod = errno;


/*	Global Error Goto Trap Point	*/
/*	----------------------------	*/	
ngferro:
	if (( ret_cod != 0 ) && ((eflag & 0x0080 ) == 0 )) {

		/* No Local Error Handler So Return Error */
		/* -------------------------------------- */
		err_val = ret_cod; 
		return(SOFTERROR);
		}

	/* Local Error Handling Update */
	/* --------------------------- */
	if ( eflag & 0x0080 ) {	
		/* Check for Error needs Trapping */
		/* ------------------------------ */
		if ( ret_cod != 0 ) { 
			LastErreur = ((EXAWORD) (lineptr - TcodeSegment) -1);
			fdex = (TcodeSegment + eptr); 
			}
		freg [diezreg + 2] = ret_cod;
		xreg [diezreg + 2] = 0;
		err_val   = 0;
		switch ( eflag & 0x0060 ) {
			case 0x0060 : 	
				ireg [0] = ireg [etrap];
				areg [0] = areg [etrap];
				etrap = freg [etrap];
			default	    : 	
				vputs(diezreg + 2,etrap); 
				break;
			}
		}		
	return(1);

#else	/* ! ABALSF */
	err_val = EXER_FUNCWOT;
	return(SOFTERROR);
#endif	/*   ABALSF */

}
#ifdef	BUG_ALTHOFF
#include "exalthof.c"
#endif
	
#ifdef INTEL
#include "exprag1.h"
#endif

#endif	/* _EXOLDNGF_C */
	/* ----------- */
