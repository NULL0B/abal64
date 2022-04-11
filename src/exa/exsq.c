/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXSQ.C
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */

/*	Method d'access S E Q U E N T I E L L E
 *	---------------------------------------
 *
 *	Note : 	The file control variables	Record_size & fin_de_fichier
 *		are stored in the file at offsets 0, and 2.
 *
 */
#include "exsq.h"

#ifdef DOS
/*
 *	DOS ==> PROLOGUE	Error code conversions
 *	----------------	----------------------
 *
 *
 */

VOID	traitfilerror( EXAWORD x , EXAWORD y )
{
#ifdef	ABAL14
	SystemError = y;
#endif
	switch ( y ) {
		case 	1	:	err_val = errno = 56; 	break;
		case 	2	:
		case 	3	:	err_val = errno = 40; 	break;
		case	4	:	err_val = errno = 51; 	break;
		case	5	:	err_val = errno = 41; 	break;
		case	6	:	err_val = errno = 50; 	break;
		case	7	:
		case	8	:	err_val = errno = 27; 	break;
		case	9	:	err_val = errno = 28; 	break;
		case	19	:	err_val = errno = 5; 	break;
		case	21	:	err_val = errno = 1; 	break;
		case	24	:	
		case	22	:	err_val = errno = 4; 	break;
		case	23	:	err_val = errno = 2; 	break;
		case	25	:	err_val = errno = 3; 	break;
		case	26	:	err_val = errno = 54; 	break;
		case	27	:	err_val = errno = 53;	break;
		case	32	:
		case	33	:	err_val = errno = 44;	break;
		case	34	:	err_val = errno = 01;	break;
		case	35	:	err_val = errno = 50;	break;
		case	36	:	err_val = errno = 04;	break;
		default		:	err_val = errno = y;	break;
		}
	return;
}
#endif

#ifndef	PRL_SF

/*
 *	S Q _ C T R L ( fid , mode )
 *	----------------------------
 *	Performs the File Control Block management 
 *	functions for all sequentiel functions
 *
 *	3 possible values of mode exist.
 *	
 *	READ (no lock)		Read and Open functions
 *	READ (locked )		Modify and write functions
 *	WRITE(liberate lock)	Write functions
 *
 */
EXAWORD release_locks( fid )
{
	if ( lseek( fid, 0L, SEEK_SET ) != -1 ) {
		(VOID) lockf( fid, F_ULOCK, BLOCK );
		}
	return( fid );
}

EXAWORD	sq_ctrl( fid , mode )
EXAWORD	fid;			/* SQ file handle (system fid)		*/
EXAWORD	mode;			/* SQ commande code GET,LCK,LIB		*/
{
	EXAWORD	x;
	struct sqform PTR fcbptr;
	EXAWORD	lockstate;

/* Seek to File control block (1st Sector or block) */
/* ------------------------------------------------ */
if ( lseek((USINT)  fid , 0L , SEEK_SET ) != -1L ) {

   /* Check for File control block READ command */
   /* ----------------------------------------- */
   if (( mode & GET_SQFCB ) != 0 ) {

	/* Write Lock Required */
	/* ------------------- */
	while ( 1 ) {
		if ((lockstate = lockf((USINT) fid, F_TLOCK, BLOCK)) != MOINS_UN)
			break;
		switch ( errno ) {
			case EACCES : 
				continue;

			case EDEADLK : 
				err_val = 74;
				return( MOINS_UN );
 
			default      :
				traitfilerror( -1, errno );
				return( MOINS_UN );
			}
		}
		/* Allocate temporary storage zone for F.C.B. */
		/* ------------------------------------------ */ 
		if ((fcbptr = (struct sqform PTR) allocate((USINT) BLOCK)) == (struct sqform PTR) 0 ) {
			(VOID) release_locks( fid );
			errno = ABAL_MEMORY; return(MOINS_UN);
			}

		/* Perform F.C.B. Sector Read */
		/* -------------------------- */
		if (read((USINT) fid,(BPTR) fcbptr,(USINT) BLOCK) != BLOCK) { 

			/* Errors so liberate and Return Error */
			/* ----------------------------------- */
			(VOID) release_locks( fid );
			liberate(fcbptr); return(MOINS_UN);

			}

		/* Transfer current FCB info */
		/* ------------------------- */
		(*(fidbuff)).SQnb_rec = (*(fcbptr)).SQnb_rec;
		(*(fidbuff)).SQsz_rec = (*(fcbptr)).SQsz_rec;

		/* Liberate temporary buffer */
		/* ------------------------- */
		liberate(fcbptr);
		return(fid);
		}

   /* Else File control block WRITE command */
   /* ------------------------------------- */	
   else		{		
		/* Allocate temporary storage zone for F.C.B. */
		/* ------------------------------------------ */ 
		if ((fcbptr = (struct sqform PTR) allocate((USINT) BLOCK)) == (struct sqform PTR) 0 ) {
			(VOID) release_locks( fid );
			errno = ABAL_MEMORY; return(MOINS_UN);
			}
		/* Transfer current FCB info */
		/* ------------------------- */
		(*(fcbptr)).SQnb_rec = (*(fidbuff)).SQnb_rec;
		(*(fcbptr)).SQsz_rec = (*(fidbuff)).SQsz_rec;

#ifdef	SQ_MERDE
		/* Establish LOCK */
		/* -------------- */
		(*(fcbptr)).SQxx_rec = FCB_FREE;
#endif
		/* Rewrite FCB in locked condition */
		/* ------------------------------- */
		write((USINT) fid,(BPTR) fcbptr,BLOCK);

		/* Liberate temporary buffer */
		/* ------------------------- */
		liberate(fcbptr);
		(VOID) release_locks(fid);
		return( 0 );
	}
   }
return(MOINS_UN);
}

EXAWORD	sq_posit( fid , rekord )
EXAWORD	fid;
EXALONG	rekord;
{
	EXALONG	sptr;
	EXAWORD	indent;
	sptr = (EXALONG) ((rekord * ((EXALONG) (*(fidbuff)).SQsz_rec)) + BLOCK);
	indent = (EXAWORD) ( sptr % BLOCK );
	sptr -= (EXALONG) indent;
	if ( lseek((USINT) fid,sptr,SEEK_SET) == -1L ) { return(MOINS_UN); }
	else { return(indent); }
}


/*
 *	SQ_OPEN( nom , perm, ext )
 *	------------------------------
 *	Uses the provided structure to open the file. 
 *	Returns zero if OK else error value.
 *
 */

EXAWORD	sq_open( fnom ,perm )
BPTR	fnom;
EXAWORD	perm;
{
	EXAWORD	fid;
	EXAWORD	lperm;

	/* Establish File access rights */
	/* ---------------------------- */
#ifdef UNIX
	if ((( perm & 1) != 0 ) || (( perm & 2) != 0 )) { lperm = (O_RDWR | O_BINARY); }
	else			{ lperm = (O_RDWR | O_BINARY); }
	if ( ( perm & 4) == 0 ) { lperm |= O_SYNC; 		 }
#endif
#ifdef	DOS
	lperm = perm;
#endif
	/* Check for file Existance */
	/* ------------------------ */
	if ( Access( fnom ,0, ((perm & 2) ? 1 : 0)) == 0 ) {

		/* Open file */
		/* --------- */
#ifdef	UNIX
		fid = (EXAWORD) open( fnom ,(USINT) lperm ,(USINT) 0);
#endif
#ifdef	DOS
		fid = (EXAWORD) open( fnom ,(USINT) lperm );
#endif
		/* If no file open error */
		/* --------------------- */
		if (( fid != 1 ) && ( fid != 0 )) {
#ifndef	COEXA
			/* Establish File Access rights (EX) */
			/* --------------------------------- */
			if (etatlox(fid,perm) == SOFTERROR) { return(MOINS_UN); }
#endif
			/* Read File Control Block */
			/* ----------------------- */
			if (sq_ctrl(fid,GET_SQFCB) != MOINS_UN ) { 
				(*(fidbuff)).SQrd_rec = 0;
				(*(fidbuff)).SQwr_rec = (*(fidbuff)).SQnb_rec;
				/* Establish Data Record Infos */
				/* --------------------------- */
				fidinfo1 = (*(fidbuff)).SQsz_rec;
				fidinfo2 = 0;
				(VOID) release_locks(fid);
				return( fid );
				}
			}
		}
	/* Convert ERRNO to prologue Error Value */
	/* ------------------------------------- */
	traitfilerror(MOINS_UN,errno);	
	return(MOINS_UN);
}

/*
 *	SQ_CLOSE( fid )
 *	------------------------------
 *	Uses the provided structure to close the file. 
 *	Returns zero if OK else error value.
 *
 */

EXAWORD	sq_close( fid )
EXAWORD	fid;
{
	/* Clear ERRNO */
	/* ----------- */
	errno = 0;

	/* Attempt to close file */
	/* --------------------- */
	if ( close((USINT) fid) != MOINS_UN ) { return(0); }

	/* Convert ERRNO to prologue error code */
	/* ------------------------------------ */	
	traitfilerror(MOINS_UN,errno); 
	return( MOINS_UN );
}

/*
 *	SQ_CREAT( nom , lng , perm )
 *	---------------------------------------------
 *	Uses the provided structure to create the file with record_size. 
 *	Returns zero if OK else error value.
 *
 */


EXAWORD	sq_creat( fnom , lrek, perm)
BPTR	fnom;
EXAWORD	lrek,perm;
{
	EXAWORD	fid;
	EXAWORD	lperm;

	/* Set Default Record size if lrek == 0 */
	/* ------------------------------------ */
	if ( lrek == 0 ) 	   { lrek = BLOCK; 		   }

	/* Establish Data Record Infos */
	/* --------------------------- */
	fidinfo1 = lrek; fidinfo2 = 0;

	/* Check for file existance */
	/* ------------------------ */
	if ( access(fnom,0) == 0 ) { errno = EXER_FILEDE; return(MOINS_UN); }


#ifdef	UNIX
	lperm = 0666;
#endif
#ifdef	DOS
	lperm = perm;
#endif
	if ( (fid = (EXAWORD) creat(fnom,lperm)) != MOINS_UN) {
		close((USINT) fid); 
#ifdef UNIX
		if ((( perm & 1) != 0 ) || (( perm & 2) != 0 )) { lperm = (O_RDWR | O_BINARY); }
		else			{ lperm = (XO_RDONLY | O_BINARY); }
		if ( ( perm & 4) == 0 ) { lperm |= O_SYNC; 		 }

		/* Check for File Access Rights */
		/* ---------------------------- */
		if ( Access(fnom,0,((perm & 2) ? 1 : 0)) != 0 ) {
			if ( errno != 44 ) {
				errno = 40;
				}
			return(MOINS_UN);
			}
	
		fid = (EXAWORD) open(fnom,(USINT) lperm,(USINT) 0);
#endif
#ifdef	DOS
		fid = (EXAWORD) open(fnom,(USINT) lperm);
#endif
		}
	if ( fid != MOINS_UN ) {
#ifndef	COEXA
		/* Establish file Access rights (EX) */
		/* --------------------------------- */
		if ( etatlox(fid,perm) == SOFTERROR ) {
			if ( errno == ABAL_NOLOCK ) { 
				unlink(fnom); 
				errno = ABAL_NOLOCK;
				}
			else	{ errno = EXER_FILEDO;   }
			return(MOINS_UN);
			}
#endif
		/* Initialise and write SQ file control block */
		/* ------------------------------------------ */
		(*(fidbuff)).SQsz_rec = lrek;	/* Record Length	*/
		(*(fidbuff)).SQnb_rec = 0;	/* Number of Records	*/
		(*(fidbuff)).SQrd_rec = 0;	/* Current Read index	*/
		(*(fidbuff)).SQwr_rec = 0;	/* Current Read index	*/
		(VOID) sq_ctrl(fid,MAJ_SQFCB);	/* Update F.C.B		*/
		return( fid );
		}
	traitfilerror(MOINS_UN,errno);	
	return( MOINS_UN );
}

/*
 *	SQ_READ( fid , bptr , blen )
 *	----------------------------
 *	Uses the provided structure to read the next record from the file
 *	into the buffer pointed to by *buffer.
 *	Returns zero if OK else MOINS_UN and ERRNO = error value.
 *
 */

EXAWORD	sq_read( fid , bptr , blen )

EXAWORD	 fid;			/* Numero logique du fichier SQ	*/
BPTR	 bptr;			/* pointer to ABAL data zone	*/
EXAWORD	 blen;			/* Length of record to read	*/

{
	EXAWORD	indent;		/* Offset from sector boundary	*/
	BPTR	wptr;		/* Temporary buffer pointer	*/
	EXAWORD	wlen;		/* Temporary buffer length	*/

	/* Clear Error Variable */
	/* -------------------- */

	errno = 0;

	/* Check for incorrect record length */
	/* --------------------------------- */
	if ( blen != (*(fidbuff)).SQsz_rec )  {
		errno = EXER_REK2SMA; return(MOINS_UN);
		}

	/* Read (no lock) File control block */
	/* --------------------------------- */
	if (sq_ctrl(fid,GET_SQFCB) == MOINS_UN) {
		return(MOINS_UN);
		}

	/* Check for Read beyond end of file */
	/* --------------------------------- */
	if ( (*(fidbuff)).SQrd_rec >= (*(fidbuff)).SQnb_rec ) {
		(VOID) release_locks( fid );
		errno = EXER_FILEFIN; return(MOINS_UN);
		}

	/* Position within file to Required record */
	/* --------------------------------------- */
	if ( (indent = sq_posit( fid , (*(fidbuff)).SQrd_rec )) != MOINS_UN ) {

		/* Calculate Transfer Length */
		/* ------------------------- */
		wlen = (( (*(fidbuff)).SQsz_rec + indent ) / BLOCK );
		if ((( (*(fidbuff)).SQsz_rec + indent) % BLOCK) > 0 ) { wlen++; }
		wlen *= BLOCK;

		/* Allocate tempory storage buffer */
		/* ------------------------------- */
		if ( (wptr = (BPTR) allocate((USINT)  wlen )) == (BPTR) 0) {
			(VOID) release_locks( fid );
			errno = ABAL_MEMORY; return(MOINS_UN);
			}

		/* Perform file read into temp buffer */
		/* ---------------------------------- */
		if ( read((USINT) fid,wptr,(USINT) wlen) < ( (*(fidbuff)).SQsz_rec + indent )) {
			(VOID) release_locks( fid );
			errno = EXER_DEVDESC; return(MOINS_UN);
			}

		/* Transfer to ABAL data zone */
		/* -------------------------- */
		(VOID) memcpy(bptr,(wptr + indent),(USINT) blen);

		/* Liberate tempory buffer */
		/* ----------------------- */
		(VOID) liberate(wptr);

		/* Update record id index */
		/* ---------------------- */
		(*(fidbuff)).SQrd_rec++;
		(VOID) release_locks( fid );
		return(blen);
		}
	/* Convert systeme error to Amenesik / Sologic error */
	/* --------------------------------------- */
	traitfilerror(MOINS_UN,errno);	
	return( MOINS_UN );
}


/*
 *	SQ_WRITE( fid , (char *) buffer , (ubin) buffer_size )
 *	---------------------------------------------------------------------
 *	Uses the provided structure to write a new record at the end of file
 *	from the buffer pointed to by *buffer.
 *	Returns zero if OK else error value.
 *
 */


EXAWORD	sq_write( fid , bptr , blen )
EXAWORD	 fid;				/* Numero logique du fichier SQ	*/
BPTR	 bptr;				/* Pointer to ABAL data zone	*/
EXAWORD	 blen;				/* Length of ABAL data zone	*/
{

	EXAWORD	indent;		/* Offset from sector boundary	*/
	BPTR	wptr;		/* Temporary buffer pointer	*/
	EXAWORD	wlen;		/* Temporary buffer length	*/

	/* Clear Error Variable */
	/* -------------------- */

	errno = 0;

	/* Check for incorrect record length */
	/* --------------------------------- */
	if ( blen != (*(fidbuff)).SQsz_rec )  {
		errno = EXER_REK2BIG; return(MOINS_UN);
		}

	/* Read (*Lock *) File control block */
	/* --------------------------------- */
	if (sq_ctrl(fid,(GET_SQFCB | LCK_SQFCB)) == MOINS_UN) {
		return(MOINS_UN);
		}

	/* Position within file to Required record */
	/* --------------------------------------- */
	if ( (indent = sq_posit( fid , (*(fidbuff)).SQnb_rec )) != MOINS_UN ) {

		/* Calculate Transfer Length */
		/* ------------------------- */
		wlen = (( (*(fidbuff)).SQsz_rec + indent ) / BLOCK );
		if ((( (*(fidbuff)).SQsz_rec + indent) % BLOCK) > 0 ) { wlen++; }
		wlen *= BLOCK;

		/* Allocate tempory storage buffer */
		/* ------------------------------- */
		if ( (wptr = (BPTR) allocate((USINT)  wlen )) != (BPTR) 0) {

			/* Perform file read into temp buffer */
			/* ---------------------------------- */
			(VOID) read((USINT) fid,wptr,(USINT) wlen);
			(VOID) sq_posit(fid , (*(fidbuff)).SQnb_rec );

			/* Transfer to ABAL data zone */
			/* -------------------------- */
			(VOID) memcpy((wptr + indent),bptr,(USINT) blen);
			indent = write((USINT) fid,wptr,wlen);

			/* Liberate tempory buffer */
			/* ----------------------- */
			(VOID) liberate(wptr);
		
			/* Check for Write errors */
			/* ---------------------- */
			if ( indent == wlen ) {
				/* Update record id index */
				/* ---------------------- */
				(*(fidbuff)).SQrd_rec = (*(fidbuff)).SQnb_rec++;
				(*(fidbuff)).SQwr_rec = (*(fidbuff)).SQnb_rec;
				/* Update Disk File Control zone */
				/* ----------------------------- */
				if ( sq_ctrl(fid,MAJ_SQFCB) != MOINS_UN) {
					return(blen);
					}
				}	
			else	{ errno = EXER_VOLFULL; }
			}
		else 	{	errno = ABAL_MEMORY;	}
		/* Liberate file control block */
		/* --------------------------- */
		(VOID) sq_ctrl(fid,MAJ_SQFCB);
		return(MOINS_UN);
		}
	/* Liberate file control block */
	/* --------------------------- */
	(VOID) sq_ctrl(fid,MAJ_SQFCB);

	/* Convert systeme error to Amenesik / Sologic error */
	/* --------------------------------------- */
	traitfilerror(MOINS_UN,errno);	
	return( MOINS_UN );
}

/*
 *	SQ_MODIF( fid , (char *) buffer , (ubin) buffer_size )
 *	---------------------------------------------------------------------
 *	Uses the provided structure to modify the current record of file
 *	from the buffer pointed to by *buffer.
 *	Returns zero if OK else error value.
 *
 */


EXAWORD	sq_modif( fid , bptr , blen )
EXAWORD	 fid;
BPTR	bptr;
EXAWORD	 blen;
{
	EXAWORD	indent;		/* Offset from sector boundary	*/
	BPTR	wptr;		/* Temporary buffer pointer	*/
	EXAWORD	wlen;		/* Temporary buffer length	*/

	/* Clear Error Variable */
	/* -------------------- */

	errno = 0;

	/* Check for incorrect record length */
	/* --------------------------------- */
	if ( blen != (*(fidbuff)).SQsz_rec )  {
		errno = EXER_REK2BIG; return(MOINS_UN);
		}

	/* Read (no lock) File control block */
	/* --------------------------------- */
	if (sq_ctrl(fid,GET_SQFCB) == MOINS_UN) {
		return(MOINS_UN);
		}

	/* Check for Read beyond end of file */
	/* --------------------------------- */
	if ( (*(fidbuff)).SQrd_rec >= (*(fidbuff)).SQnb_rec ) {
		(VOID) 	release_locks(fid);
		errno = EXER_FILEFIN; return(MOINS_UN);
		}


	/* Position within file to Required record */
	/* --------------------------------------- */
	if ( (indent = sq_posit( fid , (*(fidbuff)).SQrd_rec )) != MOINS_UN ) {

		/* Calculate Transfer Length */
		/* ------------------------- */
		wlen = (( (*(fidbuff)).SQsz_rec + indent ) / BLOCK );
		if ((( (*(fidbuff)).SQsz_rec + indent) % BLOCK) > 0 ) { wlen++; }
		wlen *= BLOCK;

		/* Allocate tempory storage buffer */
		/* ------------------------------- */
		if ( (wptr = (BPTR) allocate((USINT)  wlen )) == (BPTR) 0) {
			(VOID) release_locks( fid );
			errno = ABAL_MEMORY; return(MOINS_UN);
			}

		/* Perform file read into temp buffer */
		/* ---------------------------------- */
		if ( read((USINT) fid,wptr,(USINT) wlen) < ( (*(fidbuff)).SQsz_rec + indent )) {
			(VOID) release_locks( fid );
			errno = EXER_ADRSECT; return(MOINS_UN);
			}

		/* Reposition to Record */
		/* -------------------- */
		(VOID) sq_posit( fid , (*(fidbuff)).SQrd_rec );

		/* Transfer to ABAL data zone */
		/* -------------------------- */
		(VOID) memcpy((wptr + indent),bptr,(USINT) blen);
		indent = write((USINT) fid,wptr,wlen);

		/* Liberate tempory buffer */
		/* ----------------------- */
		(VOID) liberate(wptr);
		(VOID) release_locks( fid );

		/* Check for Write errors */
		/* ---------------------- */
		if ( indent != wlen ) {
			errno = EXER_VOLFULL; return( MOINS_UN );
			}
		return(blen);
		}

	/* Convert systeme error to Amenesik / Sologic error */
	/* --------------------------------------- */
	traitfilerror(MOINS_UN,errno);	
	return( MOINS_UN );
}

/*
 *	SQ_REWIND( fid )
 *	----------------
 *	Uses the provided structure to position pointer to previous record.
 *	from the buffer pointed to by *buffer.
 *	Returns zero if OK else error value.
 *
 */

EXAWORD	sq_rewind( fid )
EXAWORD	 fid;
{
	/* Check for backspace beyond start of File */
	/* ---------------------------------------- */
	if ( (*(fidbuff)).SQrd_rec > 0 ) {
		(*(fidbuff)).SQrd_rec--;
		return(0);
		}
	else	{
		errno = EXER_FICHDEB;
		return(MOINS_UN);
		}

}

/*
 *	S Q _ F U N C ( fid , bptr , blen , func )
 *	------------------------------------------
 *
 *	AIGUILLAGE des fonctions Sequentielles
 *	SQ_READ, SQ_WRITE, SQ_MODIF
 *
 */

EXAWORD	sq_func( fid , bptr , blen , func )
EXAWORD	fid;
BPTR	bptr;
EXAWORD	blen;
EXAWORD	func;
{
	switch ( func ) {
		case 0x0061 : return(sq_read(fid,bptr,blen));
		case 0x00A5 : return(sq_write(fid,bptr,blen));
		case 0x00A1 : return(sq_modif(fid,bptr,blen));
		}
	errno = EXER_FUNCWOT;
	return( MOINS_UN );
}

EXAWORD	sq_lgdata( fid )
EXAWORD	fid;
{
	return( fidinfo1 );
}
EXAWORD	sq_lgcle( fid )
EXAWORD	fid;
{
	return( fidinfo2 );
}
EXAWORD	sq_type( fid )
EXAWORD	fid;
{
	return(0x0001);
}

#endif
