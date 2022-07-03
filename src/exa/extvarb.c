/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 2022 Amenesik / Sologic			*/
/*									*/
/*		Module  :	EXTVARB - C				*/
/*		Version :	5.1a       				*/
/*		Date 	:	03/05/2022				*/
/*									*/
/*----------------------------------------------------------------------*/
/* Remarque : Ce fichier contient les traitement des LONGS		*/
/*----------------------------------------------------------------------*/
/* #define	DEBUG_MEM_ETD 		*/
/* #define		DEBUG_EXA_SWAP  */


#ifdef	PROLOGUE2
#ifdef	ABAL21
#define	PROTEGE_286
#endif
#endif

#include "extvarb.h"

#ifdef INTEL
#include "exprag0.h"
#endif

#include "exptr.h"

#ifndef	UNIX
#ifndef	VMS
#define	reset_file_device() dpdev = 0
#endif
#endif
#ifndef	PROLOGUE
#ifndef	DOS
#define	reset_file_device() 
#endif
#endif


#define	ULONG	unsigned EXALONG

EXAWORD	ExtendedPageCounter=0;

EXAWORD	extended_page_counter()
{
	return( ExtendedPageCounter );
}

EXTERN	LSEEKTYPE	fidseek;

/* Virtuel memory  :  optimisation variables */
/* ----------------------------------------- */

EX_FILE_HANDLE	 VmemFid;	/* Buffer  File ID   	*/
EXAWORD		VmemLng;	/* Buffer  Length    	*/
LSEEKTYPE	VmemOfs;	/* Buffer  offset    	*/
EXAWORD		VmemDif;	/* = 1;			*/
EXAWORD		VmemExt;	/* = VmemAdj;		*/
LSEEKTYPE	VmemWot;	/* = adr_phy_fich;	*/
EXAWORD		VmemHow;	/* = dleng;		*/
EXAWORD		VmemPerm;	/* File Permissions	*/

EXAWORD	ProcSwap;

BPTR	workptr4;
EXAWORD	worklen4;
EXAWORD	worktyp4;
BINAIRE	workval4;

/* Virtuel memory  :  File locking variables */
/* ----------------------------------------- */
extern	EXAWORD	SemaFlag;
LSEEKTYPE	LockDebut;
ULONG		LockLength;
EX_FILE_HANDLE	LockHandle;

/*	File locking functions for Virtuel memory */
/*	----------------------------------------- */
VOID	Semaphon()
{
	if ( SemaFlag == 0 ) {
#ifndef	UNIX
#ifndef	VMS
		ExaDmex();
#endif
#endif
		SemaFlag = 1;
		}
	return;
}

EXAWORD	Semaphoff(retcode)
EXAWORD	retcode;
{
	if ( SemaFlag == 1 ) {
#ifndef	UNIX
#ifndef	VMS
		ExaFmex();
#endif
#endif
#ifndef	PROLOGUE
#ifndef DOS
#ifndef	ABAL_CRITERIA
		(VOID) lseek(LockHandle,LockDebut,SEEK_SET);
		(VOID) lockf(LockHandle,F_ULOCK,LockLength);	
#endif
#endif
#endif
		SemaFlag = 0;
		}
	return(retcode);
}

/*	
 *	I N D E N T ( worktyp , descptr , reg , retlong )
 *	-------------------------------------------------
 *	Calculates the Offset from the start of the variable
 *	for External and Extended variables using EXALONG calculations
 *	and stores the result at the adresse pointed to by RETLONG
 *	Returns the Length of the Variable or ZERO in case of index errors
 */

EXAWORD		indent(worktyp,descptr,reg,retlong)
EXAWORD		worktyp;
BPTR		descptr;
EXAWORD		reg;
LSEEKTYPE PTR	retlong;
{
	LSEEKTYPE	temp;
	LSEEKTYPE	temp2;
	LSEEKTYPE	temp3;
	EXAWORD	indleng;

	switch ( worktyp & VARB_ISOL ) {
		case VARB_FOUR  :
		case VARB_INT8  : indleng = 1; break;
		case VARB_INT16 : indleng = ABALWORDSIZE; break;
		case VARB_INT32 : indleng = (2*ABALWORDSIZE); break;
		case VARB_INT64 : indleng = (4*ABALWORDSIZE); break;
		default: indleng = Tcodeword( descptr); 
			 descptr += WORDSIZE; 
		}
	temp3 = (LSEEKTYPE) 0;
	if ( worktyp & NDX1st) {
		temp = (LSEEKTYPE)ireg [reg];
		IndexCheck( temp , descptr );
		temp3 += (LSEEKTYPE)( indleng * ( temp - 1 ) );
		if ( worktyp & NDX2nd) {
			temp = (LSEEKTYPE)areg [reg]; 	
			temp2 = (LSEEKTYPE)Tcodeword( descptr); descptr += WORDSIZE;
			IndexCheck( temp , descptr );
			temp2 *= (LSEEKTYPE)indleng; 
			temp3 += (LSEEKTYPE)( temp2 * ( temp - 1 ) );
			}
		}
	*retlong += temp3;	
	return(indleng);

}

#ifndef UNIX
#ifndef VMS
/*
 *	R A W I O F U N C ( lfid, bptr, blen, fsect , iomode)
 *	------------------------------------------------------
 *	This function handles Device access for External variables
 *	for Amenesik / Sologic 2 , Amenesik / Sologic 3 and MS/PC-DOS versions
 *
 */

EXAWORD	dpdev;		/* DOS and PROLOGUE File/Device Switch 	*/
			/* 1 ==> Device , 0 ==> File 		*/
			/* Set or reset by EXTOPEN		*/
			/* Used by SectRead and SectWrite	*/

EXAWORD	rawiofunc( lfid , bptr , blen , fsect , iomode )
EX_FILE_HANDLE lfid;
BPTR	bptr;
EXAWORD	blen;
ULONG	fsect;
EXAWORD	iomode;
{
	EXAWORD	nsect;
	EXAWORD	lerr;
	
	nsect = (blen / BLOCK);
	if (( blen % BLOCK ) > 0 ) { nsect++; }
	lerr = io_func(lfid,iomode, bptr,(nsect * BLOCK),(ULONG) fsect);
	if ( lerr == 0 ) { return( blen );   }
	else		 { return(MOINS_UN); }	
}
#endif	/* ! VMS */
#endif	/* ! NIX */

/*
 *	S e c t R e a d ( Fid , Bptr , Blen , Sector )
 *	----------------------------------------------
 *	Performs all Disk sector read operations for the executor
 *
 */

#ifndef	ABAL_TCPIP

EXAWORD	SectRead( lfid , bptr , blen , fsect )
EX_FILE_HANDLE lfid;
BPTR	bptr;
EXAWORD	blen;
ULONG	fsect;
{
	EXAWORD		result;
	LSEEKTYPE	oldpos;
	LSEEKTYPE	lsval;
	EXAWORD		rdlng;
	EXAWORD		hold_sfcode;
	EXAWORD		nbsect;

#ifndef UNIX
#ifndef	VMS
	/* Check for RAW DEVICE function */
	if ( dpdev == 1 ) {
		/* Perform RAW DEVICE READ function */
		return(rawiofunc(lfid,bptr,blen,fsect,0x0040));
	}
#endif	/* !VMS */
#endif	/* !UNIX */


#ifdef	ABAL_CRITERIA
	fidseek = (LSEEKTYPE) fsect;
	fidseek *= BLOCK;
	oldpos  = fidseek;

	result = EeEad_read( lfid, bptr, blen );
	errno = (int)result;

	if ((result == 0) || (result == 48))
		return((EXAWORD)(fidseek - oldpos));
	else   	return(MOINS_UN);

#else

	/* Position to Offset in File */
	/* -------------------------- */
	lsval = (((LSEEKTYPE) fsect) * BLOCK); 
	if ( lseek( lfid , lsval , SEEK_SET ) != -1L ) 
	{
		nbsect = blen / BLOCK; 
		if (( blen % BLOCK ) != 0 ) { nbsect++; }

#ifndef PRL_SF

		/* Perform READ from file */
		/* ---------------------- */
		rdlng = read(lfid,bptr,(nbsect * BLOCK));
		if ( rdlng == MOINS_UN ) { return(MOINS_UN); }
		if ( rdlng == 0 )        { return(MOINS_UN); }

		/* Reset Rest of buffer if needed */
		/* ------------------------------ */
		if ( rdlng != (nbsect * BLOCK)) 
		{
			memset( (bptr + rdlng),0,((nbsect * BLOCK) - rdlng));
		}
		return( rdlng );

	/* ----- */
#else	/*  PRL  */
	/* ----- */
		hold_sfcode = simcbd;
		simcbd = 0x0060;
		result = read(lfid,bptr,(nbsect * BLOCK));
		simcbd = hold_sfcode;
		return( result );

	/* ----- */
#endif	/* ! PRL */
	/* ----- */
	}
	else 	
	{ 
		err_val = errno; 
		return(MOINS_UN); 
	}

#endif
}

#else	/* ABAL_TCPIP */

EXAWORD	SectRead( lfid , bptr , blen , fsect )
EX_FILE_HANDLE lfid;
BPTR	bptr;
EXAWORD	blen;
ULONG	fsect;
{
	return( ad_read( lfid, bptr, blen, (unsigned EXALONG) fsect ) );
}

#endif

/*
 *	V m e m E x t e n d ( lfid , blen , fsect )
 *	-------------------------------------------
 *	Tentative d'etendre une fichier memoire virtuelle
 *	pour ressoudre les erreurs 127 en ecriture d'une
 *	variable au dela de la fin courant du fichier
 *
 *	Entree :
 *		lfid		: Logical file handle
 *		blen		: longeur requise
 *		fsect		: Secteur frontiere
 *	Sortie :
 *		MOINS_UN	: Erreur d'extend
 *		ZERO		: Ok extend effected
 */

EXAWORD	VmemExtend( lfid , blen , fsect )
EX_FILE_HANDLE lfid;
EXAWORD	blen;
ULONG	fsect;
{
	/* Check for #MEM overspill possible during READ */
	/* --------------------------------------------- */
	errno = ABAL_MEMORY;
	StackCheck( blen );

	/* On peut se contenter de faire EXTEND suivi par read */
	/* --------------------------------------------------- */
#ifdef	ABAL_CRITERIA
	do 	{ if ( (errno = EeEad_extend(lfid,16)) != 0 ) { return(SOFTERROR); } }
#else
#ifdef	ABAL_TCPIP
	do 	{ if ( (errno = ad_extend(lfid,16)) != 0 ) { return(SOFTERROR); } }
#else
	do 	{ if ( (errno = extend(lfid,16)) != 0 ) { return(SOFTERROR); } }
#endif
#endif
	while	( SectRead ( lfid , (TcodeByteStack + worktop) , blen , fsect ) != blen );
	return(1);

}

/*
 *	S e c t W r i t e ( Fid , Bptr , Blen , Sector )
 *	------------------------------------------------
 *	Performs all Disk sector Write operations for the executor
 *
 */

#ifndef	ABAL_TCPIP

EXAWORD	SectWrite( lfid , bptr , blen , fsect )
EX_FILE_HANDLE lfid;
BPTR	bptr;
EXAWORD	blen;
ULONG	fsect;
{
	EXAWORD	result;
	LSEEKTYPE	oldpos;
	LSEEKTYPE	lsval;
	EXAWORD	hold_sfcode;
	EXAWORD	nbsect;

#ifndef	UNIX
#ifndef	VMS
	/* Check for RAW DEVICE function */
	if ( dpdev == 1 ) {
		/* Perform RAW DEVICE WRITE function */
		return(rawiofunc(lfid,bptr,blen,fsect,0x0080));
	}
#endif
#endif

#ifdef	ABAL_CRITERIA
	fidseek = (LSEEKTYPE) fsect;
	fidseek *= BLOCK;
	oldpos  = fidseek;
	
	result = EeEad_write( lfid, bptr, blen );
	errno  = (int)result;
	if (result == 0)	return((EXAWORD)(fidseek - oldpos));
	else			return(MOINS_UN);

#else

	lsval = (ULONG) fsect;
	lsval *= BLOCK;
	if ( lseek( lfid , lsval , SEEK_SET ) != -1L ) {
		nbsect = (blen / BLOCK); 
		if (( blen % BLOCK ) != 0 ) { nbsect++; }
		hold_sfcode = simcbd;
		simcbd = 0x00A0;
		result = write(lfid,bptr,(nbsect * BLOCK));
		simcbd = hold_sfcode;
		return( result );
		}
	else 	{ 
		err_val = errno; 
		return(MOINS_UN); 
		}
#endif
}

#else	/* ABAL_TCPIP */

EXAWORD SectWrite( lfid , bptr , blen , fsect )
EX_FILE_HANDLE lfid;
BPTR	bptr;
EXAWORD	blen;
ULONG	fsect;
{
	return( ad_write( lfid, bptr, blen, (unsigned EXALONG) fsect ) );
}

#endif




/*	OPEN_VIRTUAL_MEMORY_FILE( )	*/
/*	---------------------------	*/
/*	Opens and or Creates a virtuel	*/
/*	memory file during variable	*/
/*	Access evaluation		*/

#ifdef	ABAL_CRITERIA

EX_FILE_HANDLE	open_virtual_memory_file( assign_handle, evperm )
EXAWORD	assign_handle;
EXAWORD	evperm;
{
	EX_FILE_HANDLE	handle;
	BPTR		evfnom;

	handle = EX_UNUSED_HANDLE;

	if((evperm & NGF_TYP)!=0){
		err_val=EXER_FUNCWOT;
		return (handle);
		}

	/* Collect filename from file table */
	/* -------------------------------- */
	evfnom = (*(AssignTable + assign_handle)).direcp;

	/* Test for File Existance and Exclusive/Sharabillity */
	/* -------------------------------------------------- */
	if (EeEad_access(evfnom,0) != 0) { 

		/* Test for Write Access Hence AUTO CREATE */
		/* --------------------------------------- */
		if (( extwrite & 0x0080) != 0) {

			/* -------------------- */
			/* Attempt to Create It */
			/* -------------------- */
			if (!(handle = EeEad_create(evfnom, evperm, (WPTR)&err_val))) {
				errno = (int)err_val;
				return((handle = EX_UNUSED_HANDLE));
			}
			else {
				(VOID) SectWrite((EX_FILE_HANDLE) handle,(BPTR) askbuf,(EXAWORD) 256,(EXAWORD) 0); 
				(void) EeEad_close( handle );
				handle = EX_UNUSED_HANDLE; 
			}
		}
	}

	/* Now it should Exist so Open It */
	/* ------------------------------ */
	if (!(handle = EeEad_open(evfnom,evperm, (WPTR)&err_val))) {
		errno = (int) err_val; 
		handle = EX_UNUSED_HANDLE; 
	}
	else	errno = 0;
	
	/* Ensure valid file handle */
	/* ------------------------ */
	if ( handle == EX_UNUSED_HANDLE ) {

#ifndef	VMS
		SystemError = errno;
#endif

		/* Watch out for EXCLUSIVE ERROR */
		/* ----------------------------- */
		if ( errno == 44 )
			err_val = errno;
		else	err_val = ABAL_EXTVARBER;
        }
        else	(*(AssignTable + assign_handle)).unlog = handle; 

	/* Return File handle to Caller */
	/* ---------------------------- */
	return(handle);

}

#else	/* ! ABAL_CRITERIA */

EX_FILE_HANDLE	open_virtual_memory_file( assign_handle, evperm )
EXAWORD	assign_handle;
EXAWORD	evperm;
{
	EX_FILE_HANDLE	handle;
	BPTR		evfnom;
	EXAWORD		cmm;
	EXAWORD		omm;

	handle = EX_UNUSED_HANDLE;

	/* Collect filename from file table */
	/* -------------------------------- */
	evfnom = (*(AssignTable + assign_handle)).direcp;

#ifdef	UNIX

	/* Establish access rights */
	/* ----------------------- */
	cmm = 0666; 
	if ((( evperm & NGF_R_W) != 0) || (( evperm & NGF_P_E) != 0))
		omm = (O_RDWR | O_BINARY); 
	else	omm = (XO_RDONLY | O_BINARY);	
	if (( evperm & NGF_I_C) == 0)
		omm |= O_SYNC; 	

#endif	/* UNIX */

	/* Test for File Existance and Exclusive/Sharabillity */
	/* -------------------------------------------------- */
	if (Access(evfnom,0,((evperm & NGF_P_E) ? 1 : 0 )) == 0) { 

#ifdef UNIX
		/* Attempt to open existing file */
		/* ----------------------------- */
#ifndef	ABAL_TCPIP
		handle = open((BPTR) evfnom,omm,0); 
#else
		handle = ad_open((BPTR) evfnom, evperm );
#endif	/* ABAL_TCPIP */

	/* --------------- */
#else	/* PRL , DOS , VMS */
	/* --------------- */

		handle = open((BPTR) evfnom,(EXAWORD) evperm); 

#endif	/* UNIX */

		}
	else 	{
		/* Check for File Not Shareable */
		/* ---------------------------- */
		if ( errno == 44 ) {
#ifdef	ABAL14
#ifndef	VMS
			SystemError = errno;
#endif
#endif
			err_val = errno; 
			return(EX_UNUSED_HANDLE);
			}

		/* Test for Write Access Hence AUTO CREATE */
		/* --------------------------------------- */
		if (( extwrite & 0x0080) != 0) {
#ifdef UNIX
			/* Attempt to create the file for UNIX */
			/* ----------------------------------- */
#ifndef	ABAL_TCPIP
			handle = creat((BPTR) evfnom, cmm );
#else
			handle = ad_creat((BPTR) evfnom, evperm );
#endif	/* ABAL_TCPIP */
 
	/* --------------- */
#else	/* PRL , DOS , VMS */
	/* --------------- */

			/* Attempt to create file for DOS PRL VMS */
			/* -------------------------------------- */
			handle = creat((BPTR) evfnom,(EXAWORD) evperm);
#endif

#ifndef PROLOGUE
#ifndef	VMS
			/* --------------------------------------- */
			/* Both MS-DOS and UNIX			   */
			/* UNIX requires that the file be Closed   */
			/* and then Reopened to ensure readability */
			/* Since all created files are WRITE only  */
			/* --------------------------------------- */
			if ( handle != MOINS_UN ) { 
#ifdef	UNIX
#ifndef	ABAL_TCPIP
				(VOID) close(handle);
				handle = open(evfnom,omm,0);
#else
				(VOID) ad_close(handle);
				handle = ad_open(evfnom,evperm);
#endif
#endif
#ifdef	DOS
				(VOID) close(handle);
				handle = open((BPTR) evfnom,(EXAWORD) evperm);
#endif
				}
#endif	/* ! VMS */
#endif	/* ! PRL */

				/* Ensure at least 1 Sector Exists */
				/* ------------------------------- */
			if ( handle != EX_UNUSED_HANDLE )
				(VOID) SectWrite((EX_FILE_HANDLE) handle,(BPTR) askbuf,(EXAWORD) 256,(EXAWORD) 0); 
			}
		}

#ifndef PROLOGUE
#ifndef	DOS
#ifndef	VMS
#ifndef	COEXA

	/* in none ACCESS versions : Ensure correct share mode */
	/* --------------------------------------------------- */
	if ( handle != EX_UNUSED_HANDLE ) 
		if ( etatlox(handle,evperm) == 0 ) { 
			err_val = 44; return(EX_UNUSED_HANDLE);
			}

#endif
#endif
#endif
#endif

	/* Ensure valid file handle */
	/* ------------------------ */
	if (( handle == EX_UNUSED_HANDLE ) || ( handle == 0)) { 

#ifdef	ABAL14
#ifndef	VMS
		SystemError = errno;
#endif
#endif

		/* Watch out for EXCLUSIVE ERROR */
		/* ----------------------------- */
		if ( errno == 44 )
			err_val = errno;
		else	err_val = ABAL_EXTVARBER;
		return(EX_UNUSED_HANDLE);

		}

	/* Update File table with new file handle */
	/* -------------------------------------- */
	(*(AssignTable + assign_handle)).unlog = handle; 

	/* Return File handle to Caller */
	/* ---------------------------- */
	return(handle);


}
#endif	/* ABAL_CRITERIA */



EX_FILE_HANDLE extopen(ix,irw)
EXAWORD	ix,irw;
{
	EXAWORD	y;
	EX_FILE_HANDLE flog;
#ifdef	UNIX
	EXAWORD	omm,cmm;
#endif
	EXAWORD	evperm;

	/* Check Validty of File Handle wrt DIEZ_FILES */
	/* ------------------------------------------- */
 	if ((y = (( ix & 0x3F00) >> 8)) > diezfic) {
		err_val = 58;
		return(EX_UNUSED_HANDLE);
		}

	/* Collect File Permissions and control validity */
	/* --------------------------------------------- */
	if (((evperm = (*(AssignTable + y)).permf) & ASS_NAME_VALID) == 0) {
		err_val = 116;
		return(EX_UNUSED_HANDLE);
		}

	/* Create Open / Create Permissions */
	/* -------------------------------- */
	VmemPerm = (evperm & (NGF_P_E | NGF_I_C));

	/* If Write Provoqued Request */
	/* -------------------------- */
	if ( irw == 1 ) { 

		/* Check for Write Permission option WR */
		/* ------------------------------------ */
		if ( ( evperm & NGF_R_W) == 0 ) { 
			err_val = ABAL_WRITPROT; 
			return(EX_UNUSED_HANDLE);
			} 
		}

	/* Collect and correct file handle */
	/* ------------------------------- */
	if ((flog = (*(AssignTable + y)).unlog) == EX_UNUSED_HANDLE)
		flog = EX_UNUSED_HANDLE;

	/* Indicate file used for VIRTUEL VARIABLES */
	/* ---------------------------------------- */
	(*(AssignTable + y)).permf |= ASS_VIRT_VALID;

#ifndef UNIX
#ifndef	VMS

	/* Special handler for DEVICE type FILES */
	/* ------------------------------------- */
	if (( evperm & NGF_TYP ) == NGF_DV) {

		/* Indicate TYPE DEVICE */
		/* -------------------- */
		dpdev  = 1;

		/* If DEVICE identity unknown */
		/* -------------------------- */
		if ( flog == EX_UNUSED_HANDLE ) {

			/* Establish DEVICE ID handle */
			/* -------------------------- */
			flog = io_open((*(AssignTable +y)).direcp);

			/* Control validity of DEVICE identity */
			/* ----------------------------------- */ 
			if (( flog == EX_UNUSED_HANDLE ) || ( flog == 0)) { 
				err_val = ABAL_EXTVARBER; 
				return(EX_UNUSED_HANDLE);
				}

			/* Update File Table information */
			/* ----------------------------- */
			(*(AssignTable + y)).unlog = flog; 

			}

		/* Return DEVICE identifier */
		/* ------------------------ */
		return( flog );
		}
	else	{ 
		/* Indicate FILE type (! DEVICE) */
		/* ----------------------------- */
		reset_file_device(); 
		}
#endif	/* PRL */
#endif	/* DOS */

	/* If file not already open */
	/* ------------------------ */
	if ( flog == EX_UNUSED_HANDLE )

		flog = open_virtual_memory_file(y, evperm );

	/* Return Resulting Handle */
	/* ----------------------- */
	return( flog );
}

/*	--------------------------------	*/
/*	V m e m B u f f e r ( length )		*/
/*	--------------------------------	*/
/*	Virtuel memory transfer buffer		*/
/*	management routines			*/
/*	(Allocates new buffer if needed)	*/
/*	--------------------------------	*/

EXAWORD	VmemBuffer( dleng )
EXAWORD	dleng;
{
	/* Ensure current buffer is big enough */
	/* ----------------------------------- */
	if ( dleng > fieldlen ) {

		/* Liberate if buffer allocated */
		/* ---------------------------- */
		if ( fieldex != (BPTR) 0 ) { 
			liberate(fieldex); 
			fieldex  = (BPTR) 0;
			fieldlen = 0;
			}

		/* Attempt to Allocate new Buffer */
		/* ------------------------------ */
		if ((fieldex = (BPTR) allocate((USINT) (dleng+1))) == (BPTR) 0) {
#ifdef	ABAL14
			SystemError = errno;
#endif
			return(SOFTERROR); 
			}

		/* Establish Current Buffer Length */
		/* ------------------------------- */
		fieldlen = dleng;

		}

	/* Indicate Buffer allocation of Validation Correct */
	/* ------------------------------------------------ */
	return(1);
}


/*
 *	E X T V A R B ( px , ix , xx , lx )
 *	-----------------------------------
 *	Performs the real adresse calculation of the external variable
 *	and transfers the value stored on the support into the temporary
 *	workspace stack and adjust the workspace index to protect the
 *	variable value.
 */


EXAWORD	extvarb(worktyp,descptr,workset,reg)
EXAWORD	worktyp;		/* Variable Type Code			*/
BPTR	descptr;		/* Descripteur Pointeur			*/
EXAWORD	workset,reg;		/* WORKSET ID and Register to USE	*/
{
	LSEEKTYPE	dbyte;		/* File byte offset of starting block	*/
	EXAWORD		doffst;		/* Indent from start of buffer		*/
	EXAWORD		dleng;		/* Total transfer length of operation 	*/
	EX_FILE_HANDLE 	flog;		/* Current File handle			*/

	EXAWORD		y;		/* Scratch work variable		*/
	EXAWORD		extvleng;	/* Length of this variable element	*/
	BINAIRE		awval;		/* Temporary value holder		*/
	BPTR		awptr;		/* Temporary pointer to Data		*/

	EXAWORD		VmemOpt;	/* Optimisation Options EX , C only	*/
	EXAWORD		VmemAdj;	/* Indent into Buffer			*/

	/* inspection_trap(); */

	/* Ensure File coherence and existance */
	/* ----------------------------------- */
	if ( (flog = extopen(worktyp,0)) == EX_UNUSED_HANDLE ) { 
		reset_file_device();
		return(SOFTERROR); 
		}

	/* Test for R/W Acces to the Variable */
	/* ---------------------------------- */
	if ( workset == 0 ) { /* Save the important DATA DETAILS 	*/
		workeepw = reg;			/* INDEX Register	*/
		worktypw = worktyp;		/* DATA Type    	*/
		descptrw = descptr;   		/* Descriptor   	*/
		}

	/* Collect offset into file of Variable start */
	/* ------------------------------------------ */
	if ( WORDSIZE > 2 ) {
		dbyte = (((LSEEKTYPE) (Tcodeword((descptr + WORDSIZE)) )) << 32);
		}
	else	{
		dbyte = (((LSEEKTYPE) (Tcodeword((descptr + WORDSIZE)) )) << 16);
		}
	dbyte += (LSEEKTYPE) Tcodeword(descptr); descptr += (2 * WORDSIZE);

	/* Adjust byte starting point for Array variables */
	/* ---------------------------------------------- */
	if ((extvleng = indent(worktyp,descptr,reg,(LSEEKTYPE PTR) &dbyte)) == SOFTERROR) {
		reset_file_device();
		return(SOFTERROR); 
		}

	/* Calculate file byte offset of starting Block */
	/* -------------------------------------------- */
	doffst = (EXAWORD) (dbyte % BLOCK);

	/* Calculate Minimum transfer length */
	/* --------------------------------- */
	dleng = (doffst + extvleng );

						/* ---------------------- */
	y = (dleng % BLOCK); 			/* Calculate Block Rest   */
	dleng /= BLOCK;				/* Create Block Count	  */
	if ( y != 0 ) { dleng++; }		/* if Rest then + 1	  */
	dleng *= BLOCK;				/* Create BlockByte count */
	if (dleng == 0) { dleng = BLOCK; }	/* Ensure at least 1 	  */
						/* ---------------------- */
#ifndef PROLOGUE
#ifndef	DOS

	/* Test for RESULT evaluation */
	/* -------------------------- */
	if ( workset == 0 ) {

		/* Lock the File Zone (UNIX and VMS) */
		/* --------------------------------- */
		LockHandle = flog;
		LockDebut  = ((dbyte / BLOCK) * BLOCK);
		LockLength = (ULONG) dleng;
#ifndef	ABAL_CRITERIA
		lseek(LockHandle,LockDebut,SEEK_SET);
		lockf(LockHandle,F_LOCK,LockLength);
#endif
		SemaFlag = 1;	
		}
#endif
#endif
	/* Optimisation Check (bufferised Data Read) */
	/* ----------------------------------------- */
	VmemOpt = 0;
	
	/* Check for Same Memory File */
	/* -------------------------- */
	if  (flog == VmemFid ) {

		/* Check that variable start is in current buffer */
		/* ---------------------------------------------- */
		if ( dbyte >= VmemOfs ) {		 

			/* Check that variable end is also in buffer */
			/* ----------------------------------------- */
			if (( dbyte + extvleng ) <= ( VmemOfs + VmemLng)) {

				/* Read optimisation is possible */
				/* if it is required by ASSIGN,C */
				/* ----------------------------- */
				VmemOpt = VmemPerm;
				}
			}
		}
#ifndef	UNIX
#ifndef	VMS
	/* Amenesik / Sologic and DOS lock the file by Semaphore NOW !!! */
	/* --------------------------------------------------- */
	Semaphon();
#endif
#endif
	if ( VmemOpt == 0 ) { /* Optimisation FALSE */
			      /* ------------------ */

		/* Check for Differed Write waiting in Buffer */
		/* ------------------------------------------ */
		if ( VmemDif == 1 ) {

			VmemDif = 0;

			/* Re-Write the delayed write now */
			/* ------------------------------ */
			if ( SectWrite(VmemFid,fieldex,VmemLng,(VmemOfs / BLOCK)) == MOINS_UN ) {

				/* Whoops Errors : RELEASE SEMAPHORE */
				/* --------------------------------- */
#ifdef	ABAL14
#ifndef	VMS
				SystemError = errno;
#endif
#endif
				err_val = ABAL_EXTVARBER; 
				reset_file_device();
				return(Semaphoff(SOFTERROR)); 
				}
			}

		/* Allocate Buffer for Read operation */
		/* ---------------------------------- */
		if ( VmemBuffer( dleng ) == SOFTERROR ) {

			/* ------------------------------------ */
			/* Buffer allocation Errors 		*/
			/* ------------------------ 		*/
			/* Whoops Errors : RELEASE SEMAPHORE 	*/
			/* ------------------------------------	*/
#ifdef	ABAL14
			SystemError = errno;
#endif
			err_val = ABAL_MEMORY;
			reset_file_device();
			return(Semaphoff(SOFTERROR));

			}

		/* Read DATA from file into Buffer */
		/* ------------------------------- */
		if ( SectRead(flog,fieldex,dleng,(dbyte / BLOCK)) == MOINS_UN ) {

			/* Perform ERROR checking (Create file zone for WR) */
			/* ------------------------------------------------ */
			if (( extwrite & 0x0080) != 0) {

#ifdef	VMS
				/* WRITE block at offset VMS will AUTO-PADD */
				/* ---------------------------------------- */
				if ( SectWrite(flog,fieldex,dleng,(dbyte / BLOCK)) == MOINS_UN ) {

					/* Whoops Errors : RELEASE SEMAPHORE 	*/
					/* --------------------------------- 	*/
#ifdef	ABAL14
#ifndef	VMS
					SystemError = errno;
#endif
#endif
					err_val = errno; 
					reset_file_device();
					return(Semaphoff(SOFTERROR));

					}
#else
				/* Attempt to EXTEND the file to validate READ */
				/* ------------------------------------------- */
				if ( VmemExtend(flog,dleng,(dbyte / BLOCK)) == SOFTERROR ) {

					/* Whoops Errors : RELEASE SEMAPHORE 	*/
					/* --------------------------------- 	*/
#ifdef	ABAL14
#ifndef	VMS
					SystemError = errno;
#endif
#endif
					err_val = errno; 
					reset_file_device();
					return(Semaphoff(SOFTERROR));

					}

#endif
				/* Repeat file DATA read */
				/* --------------------- */
				if ( SectRead(flog,fieldex,dleng,(dbyte / BLOCK)) == MOINS_UN ) {

					/* Whoops Errors : RELEASE SEMAPHORE 	*/
					/* --------------------------------- 	*/
#ifdef	ABAL14
#ifndef	VMS
					SystemError = errno;
#endif
#endif
					err_val = ABAL_EXTVARBER;
					reset_file_device();
					return(Semaphoff(SOFTERROR)); 
					}
				}
			else 	{ 
				/* VARIABLE to READ not Found E 127	*/
				/* ---------------------------------	*/
				/* Whoops Errors : RELEASE SEMAPHORE 	*/
				/* --------------------------------- 	*/
#ifdef DOS
				if ( err_val != 48 ) {

#endif
#ifdef	ABAL14
#ifndef	VMS
					SystemError = errno;
#endif
#endif
					err_val = ABAL_EXTVARBER;
					reset_file_device();
					return(Semaphoff(SOFTERROR)); 
#ifdef	DOS
					}
#endif

				}
			}

		/* ------------------------------------------------------- */
		/* The DATA hes been read correctly from the file          */
		/* ------------------------------------------------------- */
		/* Establish Control Values for possible Bufferisation 	   */
		/* ------------------------------------------------------- */
		VmemFid = flog;			     /* Save File Handle   */
		VmemLng = dleng;		     /* Save Buffer Length */
		VmemOfs = ((dbyte / BLOCK) * BLOCK); /* Save FileByteStart */
		VmemAdj = 0;			     /* Reset Adjustment   */
		/* ------------------------------------------------------- */

		}
	else	{
		/* DATA is already in the buffer so Calculate indent */
		/* ------------------------------------------------- */
		VmemAdj = (((dbyte - VmemOfs ) / BLOCK) * BLOCK);
		}

	/* Ensure workzone  is still big enough for Result */
	/* ----------------------------------------------- */
	StackCheck( extvleng );

	/* Copy VARIABLE ELEMENT from file buffer to Work Zone	*/
	/* ---------------------------------------------------  */
	memcpy((BPTR)((awptr = (TcodeByteStack + worktop))),(BPTR)(fieldex + VmemAdj + doffst),extvleng);

	/* Protect the WorkZone used and Limit to Valid DATA Type */
	/* ------------------------------------------------------ */
	worktop += extvleng; worktyp &= VARB_ISOL;

	/* Establish Short Numeric WORKSET Values */
	/* -------------------------------------- */
	switch ( worktyp ) {
		case VARB_FOUR  :
		case VARB_INT8  : awval = (BINAIRE) ReadSchar( awptr); break;
		case VARB_INT16 : awval = balgetw(awptr);break;
		case VARB_INT32 : awval = balgetl(awptr);break;
		case VARB_INT64 : awval = balget64(awptr);break;
		default 	: awval = 0; break;
		}

	reset_file_device();

	/* Establish the required WORKSET pointer , length and DataType */
	/* ------------------------------------------------------------ */
	switch ( workset ) {
		case 0 : workptrw = awptr;
			 extwrite &= 0x007F; 
			 extwrite |= 1;
		case 1 : workptr1 = awptr; worklen1 = extvleng; 
			 workval1 = awval; worktyp1 = worktyp;  break;
		case 2 : workptr2 = awptr; worklen2 = extvleng;
			 workval2 = awval; worktyp2 = worktyp;  break;
		case 3 : workptr3 = awptr; worklen3 = extvleng;
			 workval3 = awval; worktyp3 = worktyp;  break;
		case 4 : workptr4 = awptr; worklen4 = extvleng;
			 workval4 = awval; worktyp4 = worktyp;  break;
		default: return(Semaphoff(SOFTERROR));
		}

	/* Reset Error Code for IOF Calls */
	/* ------------------------------ */
	err_val = 0; errno = 0;

	/* Check for SEMAPHORE RELEASE required */
	/* ------------------------------------ */
	if ( workset == 0 ) 	{ return(1); 		}
	else			{ return(Semaphoff(1)); }

}

/*
 *	E X T R I T E ( px , ix , xx , lx , vp )
 *	----------------------------------------
 *	Re-ecriture de la valeur d'un variable Externe sur support
 *	magnetique (Traitement du Field = nlog) . The current value
 *	of the variable is taken from the workspace stack previously
 *	prepared by the EXTVARB function.
 */

EXAWORD	extrite(worktyp,descptr,reg,vp)
EXAWORD	worktyp;		/* Variable Type Code			*/
BPTR	descptr;		/* Descripteur Pointeur			*/
EXAWORD	reg;			/* WORKSET ID and Register to USE	*/
BPTR	vp;			/* Pointer to the Workspace Value	*/
{
	LSEEKTYPE	adr_phy_fich;
	EXAWORD		offs_sect;
	EX_FILE_HANDLE 	flog;
	EXAWORD	dleng,y;
	EXAWORD		extvleng;
	EXAWORD		VmemOpt;
	EXAWORD		VmemAdj;

	/* inspection_trap(); */

	/* Ensure File coherence and existance */
	/* ----------------------------------- */
	if ( (flog = extopen(worktyp,1)) == EX_UNUSED_HANDLE ) {
		reset_file_device();
		return(Semaphoff(SOFTERROR));
		}

	/* Calculate Variable start offset */
	/* ------------------------------- */
	if ( WORDSIZE > 2 ) {
		adr_phy_fich = (((ULONG) (Tcodeword((descptr + WORDSIZE)) )) << 32);
		}
	else	{
		adr_phy_fich = (((ULONG) (Tcodeword((descptr + WORDSIZE)) )) << 16);
		}
	adr_phy_fich += (ULONG) Tcodeword(descptr); descptr += (2 * WORDSIZE);

	/* Adjust starting offset for Array Variables */
	/* ------------------------------------------ */
	if ((extvleng = indent( worktyp , descptr , reg ,(LSEEKTYPE PTR) &adr_phy_fich)) == SOFTERROR) {
		reset_file_device();
		return(Semaphoff(SOFTERROR)); 
		}

	/* Recalculate Variable physical Block adresse */
	/* ------------------------------------------- */
	offs_sect = (EXAWORD) (adr_phy_fich % BLOCK);
	dleng = (offs_sect + extvleng );
	y = (dleng % BLOCK); dleng /= BLOCK;
	if ( y != 0 ) { dleng++; }
	dleng *= BLOCK;
	if (dleng == 0) { dleng = BLOCK; }

	/* Optimisation Check (bufferised Data Read) */
	/* ----------------------------------------- */
	VmemOpt = 0;
	
	/* Check for Same Memory File */
	/* -------------------------- */
	if  (flog == VmemFid ) {

		/* Check for legal file offset */
		/* --------------------------- */
		if ( adr_phy_fich >= VmemOfs ) {		 

			/* Check for Legal Length */
			/* ---------------------- */
			if (( adr_phy_fich + extvleng ) <= ( VmemOfs + VmemLng)) {
				VmemOpt = VmemPerm;
				}
			}
		}
	
	if ( VmemOpt == 0 ) { /* Optimisation FALSE */
			      /* ------------------ */

		/* Test for and allocate new buffer if needed */
		/* ------------------------------------------ */
		if ( VmemBuffer( dleng ) == SOFTERROR ) {
#ifdef	ABAL14
			SystemError = errno;
#endif
			err_val = ABAL_MEMORY; 
			reset_file_device();
			return(Semaphoff(SOFTERROR)); 
			}


		/* Perform Read operation	*/
		/* -----------------------------*/
		if ( SectRead(flog,fieldex,dleng,(adr_phy_fich / BLOCK)) == MOINS_UN ) {
#ifdef	ABAL14
#ifndef	VMS
			SystemError = errno;
#endif
#endif
			err_val = ABAL_EXTVARBER; 
			reset_file_device();
			return(Semaphoff(SOFTERROR)); 
			}

		VmemFid = flog;		/* Save File Handle 	*/
		VmemLng = dleng;	/* Save Buffer Length	*/
		VmemOfs = ((adr_phy_fich / BLOCK) * BLOCK); /* Save Buffer start	*/
		VmemAdj = 0;
		}
	else	{
		VmemAdj = (((adr_phy_fich - VmemOfs ) / BLOCK) * BLOCK);
		}

	/* Transfer from Work stack Zone	*/
	/* -----------------------------------  */
	memcpy((fieldex + VmemAdj + offs_sect),vp,extvleng);

	/* Test for Optimised WRITE (EX,C only ) */
	/* ------------------------------------- */ 
	if ( VmemOpt != 0x0006 ) {

		/* Re-write on the Support		*/
		/* ------------------------------------ */
		VmemDif = 0;
		if ( SectWrite(flog,(fieldex+VmemAdj),dleng,(adr_phy_fich / BLOCK)) == MOINS_UN ) {
#ifdef	ABAL14
#ifndef	VMS
			SystemError = errno;
#endif
#endif
			err_val = ABAL_EXTVARBER; 
			reset_file_device();
			return(Semaphoff(SOFTERROR)); 
			}
		}
	else	{ /* Set Buffer Needs Write Flag */
		  /* --------------------------- */
		VmemDif = 1;
		VmemExt = VmemAdj;
		VmemWot = adr_phy_fich;
		VmemHow = dleng;
		}
	reset_file_device();
	return(Semaphoff(1));

}

/*
 *	Generation d'un nombre alleatoire
 *	---------------------------------
 */

BINAIRE	x_rand(goval)
BINAIRE	goval;
{
	BINAIRE	rnd;

	if ( goval != 0 ) { rnd_var = goval; }
	rnd_var = ((rnd_var * 1061) + 3251) / 16;
	rnd = (BINAIRE) ((rnd_var * 32767) / 100000L );
	return((rnd & 0x7FFF));
}

/* 
 *	Ascii to EXALONG (Signed)
 *	-------------------------
 */

LSEEKTYPE	exatol(cp,len)
BPTR		cp;
EXAWORD		len;
{
register LSEEKTYPE	x;
	 EXAWORD 	y;

/*	Parse out any leading white space 	*/
/*	---------------------------------	*/
	while (( *cp == ' ' ) && (len > 0)) { cp++; len--; }

x = 0;
if ( *cp == '-' ) { cp++; y = 1; } 
else { y = 0; }
while ( len > 0 ) {
	if (( *cp >= '0' ) && ( *cp <= '9' ) ) {
		x *= 10;
		x += ((EXAWORD) *cp & 0x000F); len--; cp++;
		}
	else { break; }
	}
if ( y == 1 ) { x = -x; }
return(x);
}

/* 
 *	BCD   to EXALONG (Signed)
 *	-------------------------
 */

LSEEKTYPE	bcdtol(cp,len)
BPTR	cp;		/*	Pointer to BCD String to convert	*/
EXAWORD	len;		/*	Maximum length of string		*/
{
#ifndef	VERSION666
register 
#endif
	LSEEKTYPE	x=0;
	 EXAWORD y;
	 EXAWORD bcd,nib;

if ( (((EXAWORD) *cp) & 0x00F0 ) == 0x0040 ) { cp = (BPTR) negbcdcpy(cp,len); }
x = 0; nib = 1; y = 0;
while ( nib > 0 ) {
	if ( nib == 1 ) {
		if ( len > 0 ) { bcd = (EXAWORD) *(cp++); len--; }
		else { nib = 0; continue; }
		switch ( bcd & 0x00F0 ) {
			case 0x00B0 :	y = 1; nib = 2; break;
			case 0x00C0 :	nib = 2; break;
			case 0x00F0 :
			case 0x00A0 : 	nib = 0; break;
			default	    : 	x *= 10; x += (( bcd & 0x00F0 ) >> 4 );
					nib = 2; break;
			}
		}
	else {
		switch ( bcd & 0x000F ) {
			case 0x000F :
			case 0x000A : 	nib = 0; break;
			default	    :	x *= 10; x += ( bcd & 0x000F );
					nib = 1; break;

			}
		}
	}
if ( y == 1 ) { x = -x; }
return(x);
}

#ifdef	ABAL14
#ifndef	ABAL64
/*
 *	L TO B C D (LONG_value, bcdptr , bcdlen   )
 *	-------------------------------------------
 *	Converts a EXALONG value to a bcd value
 *	Returns an error if the EXALONG is too big
 *	to be stored in the bcd result zone
 */

EXAWORD	ltobcd( EXALONG longvalue, BPTR bcdptr , EXAWORD bcdlen )
{
	register EXAWORD y;
		 EXALONG	 x;
		 EXAWORD flag;
		 EXAWORD bcd,nib;

/* Detect Special Case which causes Problems */
/* ----------------------------------------- */
if ( (EXAWORD) longvalue == 0x80000000L) {	

	/* Special Case longvalue = -2,147,483,648 */
	/* --------------------------------------- */

	if ( bcdlen < 6 ) 		{ err_val = ABAL_BCDFORM; return(0);   }

	*(bcdptr++) = (EXABYTE) 0x00B2; *(bcdptr++) = (EXABYTE) 0x0014;
	*(bcdptr++) = (EXABYTE) 0x0074; *(bcdptr++) = (EXABYTE) 0x0083;
	*(bcdptr++) = (EXABYTE) 0x0064; *(bcdptr++) = (EXABYTE) 0x008F;
	bcdlen -= 6;

	while ( bcdlen > 0 ) 	{ *(bcdptr++) = (EXABYTE) 0x00FF; bcdlen--; }
	return(1);

	}

/* Detect Negative values and Establish BCD Sign Nibble */
/* ---------------------------------------------------- */
if ( ((EXAWORD) longvalue & 0x80000000L) != 0 ) { 
	bcd = 0x00B0; longvalue = -longvalue ;
	}
else 	{ 
	bcd = 0x00C0; 
	}

/* Enter EXALONG VALUE Conversion mechanism */
/* ------------------------------------- */
nib = 2;
if ( longvalue != 0L ) {

	x = 1000000000L; flag = 0;
	while (( x >= 1L ) && (bcdlen > 0)) {
		y = ( longvalue / x );
		if ( y != 0 ) { 
			if ( nib == 1 ) { 
				bcd = (y << 4); nib = 2; 
				}
			else 	{
			 	bcd |= y; nib = 1; *(bcdptr++) = (EXABYTE) bcd;
				bcdlen--; bcd = 0x00FF;
				if ( bcdlen == 0 ) { break; }
				}
			longvalue %= x; flag = 1; x /= 10L; 
			}
		else 	{
		 	if ( flag == 0 ) { x /= 10L; }
			else 	{
				if ( nib == 1 ) { bcd = (y << 4); nib = 2; }
				else 	{
				 	bcd |= y; nib = 1; *(bcdptr++) = (EXABYTE) bcd;
					bcdlen--; bcd = 0x00FF;
					if ( bcdlen == 0 ) { break; }
					}
				longvalue %= x; flag = 1; x /= 10L; 
				}
			}
		}

	/* Test for BCD result overflow */
	/* ---------------------------- */
	if ( x >= 1 ) { err_val = ABAL_BCDFORM; return(SOFTERROR); }

	/* Establish Last Waiting Digit */
	/* ---------------------------- */
	if (( bcdlen > 0 ) && ( nib == 2)) {
		*(bcdptr++) = (EXABYTE) (bcd | 0x000F); bcdlen--;
		}
	}
else 	{ *(bcdptr++) = (EXABYTE) 0x00C0; bcdlen--; }

/* Pad too end of String with Bcd Filler Bytes */
/* ------------------------------------------- */
while ( bcdlen > 0 ) { *(bcdptr++) = (EXABYTE) 0x00FF; bcdlen--; }

return(1);

}

EXAWORD	htobcd( EXAWORD longvalue, BPTR bcdptr , EXAWORD bcdlen )
{
	register EXAWORD y;
		 EXALONG	 x;
		 EXAWORD flag;
		 EXAWORD bcd,nib;

	/* ----------------------------------------- */
	/* Detect Special Case which causes Problems */
	/* ----------------------------------------- */
	if ( (EXAWORD) longvalue == 0x8000000000000000L) 
	{

		/* ----------------------------------------------- */
		/* Special Case longvalue = -9223372036854775807   */
		/* ----------------------------------------------- */
		if ( bcdlen < 10 ) 		{ err_val = ABAL_BCDFORM; return(0);   }

	
		*(bcdptr++) = (EXABYTE) 0x00B9; *(bcdptr++) = (EXABYTE) 0x0022;
		*(bcdptr++) = (EXABYTE) 0x0033; *(bcdptr++) = (EXABYTE) 0x0072;
		*(bcdptr++) = (EXABYTE) 0x0003; *(bcdptr++) = (EXABYTE) 0x0068;
		*(bcdptr++) = (EXABYTE) 0x0054; *(bcdptr++) = (EXABYTE) 0x0077;
		*(bcdptr++) = (EXABYTE) 0x0058; *(bcdptr++) = (EXABYTE) 0x0007;
		bcdlen -= 10;

		while ( bcdlen > 0 ) 	{ *(bcdptr++) = (EXABYTE) 0x00FF; bcdlen--; }
		return(GOODRESULT);
	}

	/* ---------------------------------------------------- */
	/* Detect Negative values and Establish BCD Sign Nibble */
	/* ---------------------------------------------------- */
	if ( ((EXAWORD) longvalue & 0x8000000000000000L) != 0 ) 
	{ 
		bcd = 0x00B0; longvalue = -longvalue ;
	}
	else 	
	{
		bcd = 0x00C0; 
	}

	/* ---------------------------------------- */
	/* Enter EXALONG VALUE Conversion mechanism */
	/* ---------------------------------------- */
	nib = 2;
	if ( longvalue != 0L ) 
	{
		x = 1000000000000000000L; flag = 0;
		while (( x >= 1L ) && (bcdlen > 0)) 
		{
			y = ( longvalue / x );
			if ( y != 0 ) 
			{ 
				if ( nib == 1 ) 
				{ 
					bcd = (y << 4); nib = 2; 
				}
				else 	
				{
				 	bcd |= y; nib = 1; *(bcdptr++) = (EXABYTE) bcd;
					bcdlen--; bcd = 0x00FF;
					if ( bcdlen == 0 ) { break; }
				}
				longvalue %= x; flag = 1; x /= 10L; 
			}
			else 	
			{
			 	if ( flag == 0 ) { x /= 10L; }
				else 	
				{
					if ( nib == 1 ) { bcd = (y << 4); nib = 2; }
					else 	
					{
					 	bcd |= y; nib = 1; *(bcdptr++) = (EXABYTE) bcd;
						bcdlen--; bcd = 0x00FF;
						if ( bcdlen == 0 ) { break; }
					}
					longvalue %= x; flag = 1; x /= 10L; 
				}
			}
		}
	
		/* ---------------------------- */
		/* Test for BCD result overflow */
		/* ---------------------------- */
		if ( x >= 1 ) { err_val = ABAL_BCDFORM; return(SOFTERROR); }
	
		/* ---------------------------- */
		/* Establish Last Waiting Digit */
		/* ---------------------------- */
		if (( bcdlen > 0 ) && ( nib == 2)) 
		{
			*(bcdptr++) = (EXABYTE) (bcd | 0x000F); bcdlen--;
		}
	}
	else 	{ *(bcdptr++) = (EXABYTE) 0x00C0; bcdlen--; }

	/* ------------------------------------------ */
	/* Pad to end of String with Bcd Filler Bytes */
	/* ------------------------------------------ */
	while ( bcdlen > 0 ) { *(bcdptr++) = (EXABYTE) 0x00FF; bcdlen--; }

	return(GOODRESULT);

}
#endif
#endif


/* ==================================================================== */
/*	G E S T I O N   D E   L A   M E M O I R E   E T E N D U E	*/
/* ==================================================================== */
#ifdef PROTEGE_286

#ifdef	ABAL21
#include "exetdbuf.h"
extern	EXAWORD	DiezeEtendu;
extern	EXAWORD	DiezePageSize;
extern	EXAWORD	DiezeSwapSize;
#define	ETDPAGE DiezePageSize
#define PAGEPTR BUFFERHANDLE
#ifdef	DEBUG_EXA_SWAP
EXAWORD	ExtendedPages=0;
VPTR	allocate_extended_page()
{
	VPTR	vptr;
	x_cprintf((BPTR) "allocate_extended_page(");
	intvisi( ExtendedPages++ );
	x_cprintf((BPTR) ") : ");

	if ((vptr = allocate_buffer()) != (VPTR) 0)
		x_cprintf((BPTR) "OK\r\n");
	else	x_cprintf((BPTR) "FAIL\r\n");
	return( vptr );
}
#else	/* ! DEBUG_EXA_SWAP */
#define allocate_extended_page() allocate_buffer()
#endif	/* DEBUG_EXA_SWAP */

#define	liberate_extended_page(p) release_buffer(p)

#else	/* ! ABAL21 */

#define	ETDPAGE	0x0800
#define PAGEPTR BPTR

#endif	/* ABAL21 */


#define	EMEMPTR	struct etdform PTR
struct	etdform	{
	EXAWORD	nbpage;
	PAGEPTR	pageptr[2];
};
EMEMPTR	ExtendedMemory;


#ifdef	ABAL21
BPTR	resolve_extended_pointer(n) 
EXAWORD	n;
{
	/* Check for allocation required and perform */
	/* ----------------------------------------- */
	if (( (*(ExtendedMemory)).pageptr[n] == (PAGEPTR) 0)
	&&  (( (*(ExtendedMemory)).pageptr[n] = allocate_extended_page()) == (PAGEPTR) 0))
		return( (BPTR) 0 );

	/* Resolve allocated page text pointer */
	/* ----------------------------------- */
	return( validate_buffer( (*(ExtendedMemory)).pageptr[n] ) );
}

#else	/* ! ABAL21 */

#define resolve_extended_pointer(n) (*(ExtendedMemory)).pageptr[n]
#define	allocate_extended_page(n)  (PAGEPTR) allocate(ETDPAGE * 16)
#define liberate_extended_page( p ) liberate( p );

#endif	/* ABAL21 */


EXAWORD xferin( bigbase , vlen , vofs )
BPTR	bigbase;
EXAWORD	vlen;
ULONG	vofs;
{
	EXAWORD	page_indent;
	EXAWORD	page_number;
	EXAWORD	transfer_length;
	BPTR	pageptr;

	page_number = (vofs / (ETDPAGE * 16));
	page_indent = (vofs % (ETDPAGE * 16));

	while ( vlen != 0 ) {

		/* Watch out for more than a page still to be transfered */
		/* ----------------------------------------------------- */
		if (( page_indent + vlen ) > (ETDPAGE * 16) )
			transfer_length = ((ETDPAGE * 16) - page_indent);
		else	transfer_length = vlen;

		if ((pageptr = resolve_extended_pointer( (page_number++) )) == (BPTR) 0) {
			err_val = 27;
			return( SOFTERROR );
			}

		/* Transfer current portion to result buffer */
		/* ----------------------------------------- */
		memcpy(bigbase,(BPTR) ( pageptr + page_indent) , transfer_length);

		/* Adjust trasfer control variables */
		/* -------------------------------- */
		bigbase    += transfer_length;
		vlen       -= transfer_length;
		page_indent = 0;
		}

	return(1);
}

EXAWORD xferout( bigbase , vlen , vofs )
BPTR	bigbase;
EXAWORD	vlen;
ULONG	vofs;
{
	EXAWORD	page_indent;
	EXAWORD	page_number;
	EXAWORD	transfer_length;
	BPTR	pageptr;

	page_number = (vofs / (ETDPAGE * 16));
	page_indent = (vofs % (ETDPAGE * 16));

	while ( vlen != 0 ) {

		/* Watch out for more than a page still to be transfered */
		/* ----------------------------------------------------- */
		if (( page_indent + vlen ) > (ETDPAGE * 16) )
			transfer_length = ((ETDPAGE * 16) - page_indent);
		else	transfer_length = vlen;

		if ((pageptr = resolve_extended_pointer( (page_number++) )) == (BPTR) 0) {
			err_val = 28;
			return( SOFTERROR );
			}
		/* Transfer current portion to result buffer */
		/* ----------------------------------------- */
		memcpy((BPTR) ( pageptr + page_indent),(BPTR) bigbase , transfer_length);

		/* Adjust trasfer control variables */
		/* -------------------------------- */
		bigbase    += transfer_length;
		vlen       -= transfer_length;
		page_indent = 0;
		}
	return(1);
}

/*
 *	L I B E R A T E _ E X T E N D E D _ M E M O R Y ( nbpara )
 *	----------------------------------------------------------
 *	Liberation de la memoire etendu FIELD = E : Mode Memoire Paginee
 */

VOID   	liberate_extended_memory()
{
	EXAWORD	x,y;
	if ( ExtendedMemory != (EMEMPTR) 0 ) {
		x = (*(ExtendedMemory)).nbpage;
		for ( y = 0; y <= x; y++ )
			if ( (*(ExtendedMemory)).pageptr[y] != (PAGEPTR) 0)
				liberate_extended_page( (*(ExtendedMemory)).pageptr[y] );
		liberate(ExtendedMemory);
		ExtendedMemory = (EMEMPTR) 0;
#ifdef	ABAL21
		liberate_buffer_controller();
#endif
		}

	return;
}
#ifdef DEBUG_MEM_ETD
VOID	show_extended_parameters()
{
	x_cprintf((BPTR) "\n\rEtended Memory Parameters : ");
	x_cprintf((BPTR) "\n\r  Page Size : ");
	intvisi( DiezePageSize ); 
	x_cprintf((BPTR) "\n\r  SwapCount : ");
	intvisi( DiezeSwapSize ); 
	x_cprintf((BPTR) "\n\r  Options   : ");
	intvisi( DiezeEtendu ); 
	x_cprintf((BPTR) "\n\r" );
	x_getch();
}
#endif

BPTR	SwapFileName();
EXAWORD	exa_swap_message(type)
EXAWORD	type;
{
#ifdef	DEBUG_EXA_SWAP
	switch ( type ) {
		case	0:
			x_cprintf((BPTR)"\r\nSwap File Created\r\n");
			break;
		default	 :
			x_cprintf((BPTR)"\r\nSwap File Error :");
			intvisi(type);
			x_cprintf((BPTR)"\r\n");
			break;
		 }
	x_getch();
#endif
	return(0);
}

/*
 *	A L L O C A T E _ E X T E N D E D _ M E M O R Y ( nbpara )
 *	----------------------------------------------------------
 *	Allocation de la memoire etendu FIELD = E : Mode Memoire Paginee 
 */
EXAWORD	allocate_extended_memory( nbparas )
EXAWORD	nbparas;
{
	EXAWORD	x = 1;
	EXAWORD	y;
#ifdef	ABAL21

	/* Verify Page Size Value */
	/* ---------------------- */
	if (( ETDPAGE == 0 ) || ( ETDPAGE == MOINS_UN ))
		ETDPAGE = 0x800;
	/* Verify Swap Size */
	/* ---------------- */
	if (( DiezeSwapSize == 0 ) || ( DiezeSwapSize == MOINS_UN ))
		DiezeSwapSize = 16;
#endif
#ifdef	DEBUG_MEM_ETD
	show_extended_parameters();
#endif

#ifdef	ABAL21
	if ( nbparas > ETDPAGE )
		x += (nbparas / ETDPAGE);
	if ( meg_tfu ) 
		x += (((0xFFFF /ETDPAGE)+1) * meg_tfu);
	if ( x >= 16383 )
		return( 28 );

#else
	x = (nbparas / ETDPAGE );
#endif
	/* Allocate Page control table */
	/* --------------------------- */
	if ((ExtendedMemory = (EMEMPTR) allocate( ((x+1)  * sizeof(PAGEPTR)) + WORDSIZE )) == (EMEMPTR) 0)
		return(EXER_MEMFULL);
	memset( ExtendedMemory, 0, ((x+1)  * sizeof(PAGEPTR)) + WORDSIZE );
#ifdef	ABAL21

	if ( initialise_buffer_control( (BPTR) SwapFileName(), (ETDPAGE * 16), DiezeSwapSize, 3 ) != 0 )
		return(EXER_MEMFULL);
	else 	set_swap_message( exa_swap_message );
#endif		

	/* Establish page count in table */
	/* ----------------------------- */
	ExtendedPageCounter = (*(ExtendedMemory)).nbpage = x;

	/* Pre-initialisation of Page pointers to NULL */
	/* ------------------------------------------- */
	for ( y = 0; y <= x; y++ )
		(*(ExtendedMemory)).pageptr[y] = (PAGEPTR) 0;

#ifndef	ABAL21 

	/* Pre-allocation of Pages Required */
	/* -------------------------------- */
	for ( y = 0; y < x ; y++ ) {
		if (( (*(ExtendedMemory)).pageptr[y] = allocate_extended_page(1)) == (PAGEPTR) 0) {
			liberate_extended_memory();
			return(EXER_MEMFULL); 
			}
		}

	/* Allocate last partial page */
	/* -------------------------- */
	if (( (*(ExtendedMemory)).pageptr[x] = allocate_extended_page(1)) == (PAGEPTR) 0) {
		liberate_extended_memory();
		return(EXER_MEMFULL); 
		}
#endif

	/* Indicate Success */
	/* ---------------- */
	return(0);	
}
#endif	/* PROTEGE_286 */


#ifdef 	ABALME
#ifdef	LINEAR_MEM

/*
 *	A L L O C A T E _ E X T E N D E D _ M E M O R Y ( nbpara )
 *	----------------------------------------------------------
 *	Allocation de la memoire etendu FIELD = E : Mode Memoire Lineaire
 */

EXAWORD	allocate_extended_memory( nbpara )
EXAWORD	nbpara;
{	USINT x;

	x = ((USINT)nbpara) * 16;
	x += ((USINT)meg_tfu) * (16 * 65536);

	if ((ExtendedMemory = (BPTR ) allocate(x)) == (BPTR) 0) 
		return(EXER_MEMFULL); 
	else	return(0);
}

/*
 *	L I B E R A T E _ E X T E N D E D _ M E M O R Y ( nbpara )
 *	----------------------------------------------------------
 *	Liberation de la memoire etendu FIELD = E : Mode Memoire Lineaire
 */

VOID	liberate_extended_memory()
{
	if ( ExtendedMemory != (BPTR) 0 ) {
		liberate(ExtendedMemory); 
		ExtendedMemory = (BPTR ) 0; 
		}
	return;
}

#endif	/* LINEAR_MEM 	*/
#endif  /* ABALME	*/

/*
 *	R E A D H U G E ( worktyp , descptr , workset ,reg )
 *	----------------------------------------------------
 *	Performs transfer of Huge Variable into local workspace
 *	(if SMALL MODEL) , or calculates a huge pointer if BIG model
 */


EXAWORD	readhuge( worktyp , descptr , workset, reg )
EXAWORD	worktyp;
BPTR	descptr;
EXAWORD	workset,reg;
{
	BINAIRE awval;

		/* ---------------------------------- */
#ifdef ABALME	/* If 'Memoire Etendu' option allowed */
		/* ---------------------------------- */

	bigvofs = ((ULONG) Tcodeword((descptr + WORDSIZE)) ) << 16;
	bigvofs += (ULONG) Tcodeword(descptr); descptr += (2 * WORDSIZE);
	if ( ProcSwap == 0 ) {
		if ((bigvlen = indent(worktyp,descptr,reg,(LSEEKTYPE PTR) &bigvofs)) == SOFTERROR) {
			return(SOFTERROR); 
			}
		}

			/* -------------------------------------------- */
#ifndef LINEAR_MEM	/* If not linear memory (then segmented memory)	*/
			/* -------------------------------------------- */

	if ( ProcSwap == 0 ) {
		StackCheck( bigvlen );
		bigbase = ( TcodeByteStack + worktop ); worktop += bigvlen;
		if ( xferin( bigbase , bigvlen , bigvofs ) == SOFTERROR )
			return( SOFTERROR );
		}

	/* ------------ */
#else	/* ! LINEAR_MEM */
	/* ------------ */

	bigbase = (BPTR) ( ExtendedMemory + bigvofs);

	/* ---------- */
#endif	/* LINEAR_MEM */
	/* ---------- */
#ifdef	ABAL21
	if ( worktyp & (ISPOINTER | ISDYNAMIC | ISMEMBER) ) {
		err_val = 56;
		return( SOFTERROR );
		}
	else	{
#endif
		worktyp &= VARB_ISOL;
		switch ( worktyp ) {
			case VARB_FOUR  :
			case VARB_INT8  : awval = (BINAIRE) ReadSchar( bigbase); break;
			case VARB_INT16 : awval = balgetw(bigbase);break;
			case VARB_INT32 : awval = balgetl(bigbase);break;
			case VARB_INT64 : awval = balget64(bigbase);break;
			default 	: awval = 0; break;
			}

		switch ( workset ) {
			case 0 : extwrite |= 2;

#ifndef LINEAR_MEM

			 	 keepvptr = bigbase; keepvlen = bigvlen; keepvofs = bigvofs;

	/* ---------- */
#endif	/* LINEAR_MEM */
	/* ---------- */

			case 1 : workptr1 = bigbase; worklen1 = bigvlen; 
				 workval1 = awval; worktyp1 = worktyp;  break;
			case 2 : workptr2 = bigbase; worklen2 = bigvlen; 
				 workval2 = awval; worktyp2 = worktyp;  break;	
			case 3 : workptr3 = bigbase; worklen3 = bigvlen;
				 workval3 = awval; worktyp3 = worktyp;  break;
			case 4 : workptr4 = bigbase; worklen4 = bigvlen;
				 workval4 = awval; worktyp4 = worktyp;  break;
			default: return(HARDERROR);
			}

#ifdef	ABAL21
		}
#endif
	/* ------ */
#endif	/* ABALME */
	/* ------ */

	return(1);

}

#ifdef	ABAL21
#include "exinietd.c"
#endif

#ifdef INTEL
#include "exprag1.h"
#endif

