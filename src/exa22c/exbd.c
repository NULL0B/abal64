/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1994 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXBD - C				*/
/*		Version :	1.4d / 2.1d				*/
/*		Date 	:	22/10/1995				*/
/*									*/
/*----------------------------------------------------------------------*/
/* Medium level (Noyau portable) Data Base functions			*/
/* ---------------------------------------------------------------------*/
#ifndef	_EXBD_C
#define	_EXBD_C

#include "exngf.h"		/* General file definitions		*/
#include "exbd.h"		/* RECORD zone structure definition	*/

#ifdef INTEL
#include "exprag0.h"		/* Intel (MSC/Borland) Stack Probe OFF	*/
#endif

/*
 *	R E M O V E _ D B _ R E C O R D S
 *	---------------------------------
 *	Removes all data base file RECORD declaration structures for
 *	the specified DATA BASE ASSIGN handle 
 *
 */

EXAWORD	remove_bd_records( base_handle )
EXAWORD	base_handle;		
{
	BDRECORDPTR	lbdptr;
	BDRECORDPTR	rbdptr;

	if ( AssignTable != (struct fichdt SPTR) 0 ) {
		if ((lbdptr = (BDRECORDPTR) (*(AssignTable + base_handle)).asptr) != (BDRECORDPTR) 0) {
			do	{
				rbdptr = lbdptr->bdf_next;
				liberate( lbdptr );
				}
			while (( lbdptr = rbdptr ) != (BDRECORDPTR) 0);
			}
		(*(AssignTable + base_handle)).asptr = fidbuff = (BPTR) 0;
		(*(AssignTable + base_handle)).aslen = fidblen = 0;
		}
	return( 0 );
}

/*
 *	C L O S E _ B A S E _ F I L E S ( )
 *	-----------------------------------
 *	Fermeture des fichiers d'une base de donnees implicity by the
 *	close of the respective data base.
 *
 */

VOID	close_base_files( data_base_handle )
EXAWORD	data_base_handle;
{
	EXAWORD	ftidx;
	EXAWORD	holdlfh;

	/* Scan File table for files depending on this base */
	/* ------------------------------------------------ */
	for ( ftidx = 1; ftidx <= diezfic; ftidx++ )

		/* Check for Data Base Dependant File */
		/* ---------------------------------- */
		if ( ( (*(AssignTable + ftidx)).permf & NGF_TYP ) == NGF_MCBD )

			/* Check for file depending on this base */
			/* ------------------------------------- */
			if ( (*(AssignTable + ftidx)).dblog == data_base_handle ) {


				/* Correction for DIT 3095 : 14/02/1994 IJM */
				/* ---------------------------------------- */
				/* EXA >= 2.1b */
				/* ----------- */
					holdlfh = lfh;
					if ((err_val = savefich()) != 0)
						return;

					lfh = ftidx;
				 	if ((err_val = loadfich()) != 0)
						return;
					(VOID) sf_close();
					if ((err_val = savefich()) != 0)
						return;
	
					lfh = holdlfh;
				 	if ((err_val = loadfich()) != 0)
						return;
				/* ---------------------------------------- */

				/* Force file to closed Status */
				/* --------------------------- */
				(*(AssignTable + ftidx)).unlog = (EX_FILE_HANDLE)EX_UNUSED_HANDLE;
				}
}


/*
 *	B A S E F I L E ( opt )
 *	-----------------------
 *	Option 0 : Suprime file from Base
 *	Option 1 : Add file to Base
 *
 */
VOID	basefile( opt )
EXAWORD	opt;
{
	BPTR	tptr;
	if (( lfh <= diezfic ) 
	&&  (fidbd != 0) 
	&&  (fidbd != MOINS_UN) 
	&&  ( AssignTable != (struct fichdt SPTR) 0))
		if ( (tptr = (*(AssignTable + fidbd)).bdext) != (BPTR) 0)
			*(tptr + lfh) = (EXABYTE) opt;

	return;
}

/*
 *	M A K E B A S E ( )
 *	-------------------
 */

EXAWORD	makebase()
{
	if ((fidbase = (BPTR) allocate((USINT) (diezfic + 1))) == (BPTR) 0) 
		return(EXER_MEMFULL);
	memset((BPTR) fidbase, 0, (diezfic+1) );
	fidperm |= ASS_BASE_VALID;
	return(0);
}

/*
 *	B D R E C O R D ( )
 *	-------------------
 *	Management of Data base file record zones
 *	
 */

BDRECORDPTR	locate_bd_record( base_handle, file_handle )
EXAWORD	base_handle;
EXAWORD	file_handle;
{
	BDRECORDPTR	lbdptr=(BDRECORDPTR) 0;

	/* Establish RECORD TREE base pointer */
	/* ---------------------------------- */

	if ( AssignTable != (struct fichdt SPTR) 0 ) {
		if ((lbdptr = (BDRECORDPTR) (*(AssignTable + base_handle)).asptr) != (BDRECORDPTR) 0) {
			do	{
				if ( lbdptr->bdfid == file_handle )
					break;
				}
			while ((lbdptr = lbdptr->bdf_next) != (BDRECORDPTR) 0);
			}
		}
	return( lbdptr );
}

#ifdef	_SHOW_POINTER_BUGS
VOID	ptrvisi( recordptr )
EXALONG	recordptr;
{
	showword( (((EXAWORD) (recordptr >> 16)) & 0xFFFF), 4 );
	x_putch(':');
	showword( (((EXAWORD) recordptr) & 0xFFFF), 4 );
	return;
}
#endif

EXAWORD	establish_bd_record( xbdptr, file_handle, recordptr, recordlen )
BDRECORDPTR	xbdptr;	
EXAWORD		file_handle;
BPTR		recordptr;
EXAWORD		recordlen;
{
#ifdef	_DEBUG_CRITERIA_RECORDS
	x_cprintf((BPTR) "establish_bd_record("); intvisi( file_handle );
	x_putch(' '); intvisi( recordlen ); x_putch(' ');
	ptrvisi( recordptr );
	x_cprintf((BPTR) ")\r\n"); x_getch();
#endif
	xbdptr->zdxbdf = recordptr;
	xbdptr->zdxlen = recordlen;
	xbdptr->bdfid  = file_handle;
	return( 0 );
}

EXAWORD	add_bd_record( base_handle,file_handle, recordptr, recordlen )
EXAWORD	base_handle;
EXAWORD	file_handle;
BPTR	recordptr;
EXAWORD	recordlen;
{
	BDRECORDPTR	lbdptr;
	BDRECORDPTR	rbdptr;

#ifdef	_DEBUG_CRITERIA_RECORDS
		x_cprintf((BPTR) "\r\nadd_bd_record(");
		intvisi( base_handle ); x_putch(' '); 
		intvisi( file_handle ); x_putch(' '); 
		intvisi( recordlen );   x_putch(' ');
		ptrvisi( recordptr );
		x_putch(')'); 
		x_getch();
#endif


	if ((lbdptr= (BDRECORDPTR) allocate((USINT) sizeof(struct bdf_zone) )) == (BDRECORDPTR) 0 )
		return( 27 );

	if ((rbdptr = (BDRECORDPTR) (*(AssignTable + base_handle)).asptr) != (BDRECORDPTR) 0)
		rbdptr->bdf_prev = lbdptr;
	
	lbdptr->bdf_next = rbdptr;
	lbdptr->bdf_prev = (BDRECORDPTR) 0;

	(*(AssignTable + base_handle)).asptr = (BPTR) lbdptr;
	(*(AssignTable + base_handle)).aslen++;

	return(	establish_bd_record( lbdptr, file_handle, recordptr, recordlen ) );
}

EXAWORD	remove_bd_record( base_handle, file_handle )
EXAWORD	base_handle;
EXAWORD	file_handle;
{
	BDRECORDPTR	lbdptr;
	BDRECORDPTR	xbdptr;
	BDRECORDPTR	rbdptr;
	
	if ((xbdptr = locate_bd_record( base_handle, file_handle )) != (BDRECORDPTR) 0) {
		if ((lbdptr = xbdptr->bdf_prev) != (BDRECORDPTR) 0)
			lbdptr->bdf_next = xbdptr->bdf_next;
		if ((rbdptr = xbdptr->bdf_next) != (BDRECORDPTR) 0)
			rbdptr->bdf_prev = xbdptr->bdf_prev;
		if (lbdptr == (BDRECORDPTR) 0)
			lbdptr = rbdptr;
		(*(AssignTable + base_handle)).asptr = (BPTR) lbdptr;
		(*(AssignTable + base_handle)).aslen--;
		liberate( xbdptr );
		}
	return( 0 );
}


EXAWORD	bdrecord()
{
	BDRECORDPTR	lbdptr;

	/* Ensure Data Base File Access Method */
	/* ----------------------------------- */
	if ((fidperm & NGF_BD) == 0) 
		return(EXER_FUNCWOT);

	/* Establish Type of Action */
	/* ------------------------ */
	if ( fargset(1) != 0 ) {

		/* Since FARGSET(1) OK we have a RECORD to add to TREE */
		/* --------------------------------------------------- */

		/* Collect RECORD zone length if Supplied */
		/* -------------------------------------- */
		if ( fargset(2) != 0 ) 
			worklen1 = (EXAWORD) workval2;

#ifdef	_DEBUG_CRITERIA_RECORDS
		x_cprintf((BPTR) "\r\nbdrecord( ");
		intvisi( lfh ); x_putch(' '); 
		ptrvisi( workptr1 ); x_putch(' ');
		intvisi( worklen1 );x_putch(' '); 
		intvisi( fidbd );x_putch(')'); 
		x_getch();
#endif
		if ((lbdptr = locate_bd_record( fidbd, lfh )) == (BDRECORDPTR) 0)
			return( add_bd_record( fidbd, lfh, workptr1, worklen1 ) );
		else	return( establish_bd_record(lbdptr, lfh, workptr1, worklen1 ) );
 
		}
	else	{
		/* Since no Record pointer provided : Remove RECORD(s)  */
		/* ---------------------------------------------------- */

		/* Check for DataBase File Request */
		/* ------------------------------- */
		if (( fidperm & NGF_MC ) == NGF_MC) 
			return( remove_bd_record( fidbd, lfh ));
		else	return( remove_bd_records( lfh ) );
		}
}

/*
 *	D C L J O I N  ( )
 *	------------------
 *	Declaration d'un jointure de la Base de Donnees
 *
 */

EXAWORD	dcljoin( )
{
	EXAWORD	maxcolname;
	EXAWORD	x;
/* Evaluation des arguaments T-Code */
/* -------------------------------- */
if (fargset(2) == 0) 
	return(err_val);
if (fargset(1) == 0)
	return(err_val);

/* Calculate and allocate memory needed for descriptor */
/* --------------------------------------------------- */
if ((worklen3 = lenuze(workptr1,worklen1)) == 0)  
	return(EXER_SYNTAX);

worklen3 /= 3;

if ( worklen3 == 0 ) 
	worklen3++;


/* ijm 31/01/2005 error 88 : JOIN */
/* ------------------------------ */
maxcolname = (bSystemLongNames ? (MAX_RUB_NAME_LEN_EXT) : (MAX_RUB_NAME_LEN_STD));
worklen3 *= (maxcolname*2)+1; 	/* was 33 */
worklen3 += (maxcolname+2);	/* was 18 */

if ((workptr3 =(BPTR) allocate((USINT) worklen3)) == (BPTR)0)
	return(EXER_MEMFULL);

/* Perform JOINTURE analysis */
/* ------------------------- */
if ( prepare_jointure( (BPTR) workptr2, worklen2, 3, workptr3 ) == SOFTERROR ) {
	liberate(workptr3); 
	return(err_val);
	}

/* Perform the Rubrique List analysis */
/* ---------------------------------- */
workptr2 = workptr3 + 17; 
worklen2 = worklen3 - 17;
*workptr2 = (EXABYTE) 0;
if ( questprep(4) != 0 ) { 
	liberate(workptr3); 
	return(EXER_RUBWOT); 
	}

/* Adjust for Jointure Name */
/* ------------------------ */
worklen2 += 17;

/* Perform the Operation SF BD 'Description d'une Jointure' */
/* -------------------------------------------------------- */
x = (EXAWORD) mc_key(fidreel,0,workptr3,worklen2,0x21AE);

/* Liberate descriptor buffer */
/* -------------------------- */
liberate(workptr3);
if ( x == MOINS_UN ) 
	return(errno);
else	return(0);

}

/*
 *	M A K E J O I N  ( )
 *	--------------------
 *	Creation d'un jointure, ou mise a jour de toutes les jointures 
 *	de la Base de Donnees
 *
 */

EXAWORD	makejoin( )
{
	EXAWORD	x,y;

/* Establish Jointure Name if Provided */
/* ----------------------------------- */
if ( fargset(1) == 0 ) {
	x = 0; 
	workptr2 = (BPTR) 0; 
	worklen2 = 0;
	}
else 	{
	x = 1;
	/* Allocate Jointure WorkZone */
	/* -------------------------- */
	if ((workptr3 = (BPTR) allocate((USINT) 17)) == (BPTR) 0)
		return(EXER_MEMFULL);

	/* Analyse and prepare Jointure Name */
	/* --------------------------------- */
	if ( prepare_jointure( workptr1, worklen1, 3, workptr3 ) == SOFTERROR ) {
		liberate(workptr3); 
		return(err_val);
		}
	workptr2 = workptr3 + 2; worklen2 = 15;
	}

/* Perform the operation SF BD 'Creation des Jointures' */
/* ---------------------------------------------------- */
y = (EXAWORD) mc_key(fidreel,x,workptr2,worklen2,0x21B6);
if ( x != 0 ) 
	liberate(workptr3);
if ( y == MOINS_UN ) 
	return(errno);
else	return(0);

}

/*
 *	S U P R J O I N  ( )
 *	--------------------
 *	Supression d'un jointure de la Base de Donnees
 *
 */

EXAWORD	suprjoin( )
{
	EXAWORD	x;

/* Establish name of Jointure to Delete */
/* ------------------------------------ */
if ( fargset(1) == SOFTERROR ) 	
	return(err_val);

/* Allocate Jointure Descriptor Zone */
/* --------------------------------- */
if ((workptr3 = (BPTR) allocate((USINT) 19)) == (BPTR) 0) 
	return(EXER_MEMFULL);

if ( prepare_jointure( workptr1, worklen1, worktyp1, workptr3) == SOFTERROR) {
	liberate(workptr3); 
	return(err_val);
	}

/* Establish Suplimentary information in descriptor */
/* ------------------------------------------------ */
*(workptr3 + 17) = (EXABYTE) 3; 
*(workptr3 + 18) = (EXABYTE) (fidreel & 0x00FF);

/* Perform Supression (Appel MC) */
/* ----------------------------- */
x = killjoin(workptr3);

/* Liberate Descriptor */
/* ------------------- */
liberate(workptr3); 

if ( x == MOINS_UN)
	return(errno);
else 	return(0);
}

/*
 *	N A M E J O I N  ( )
 *	--------------------
 *	Renommer un jointure de la Base de Donnees
 *
 */

EXAWORD	namejoin( )
{
	EXAWORD	x;

/* Evaluate Arguaments in T-Code */
/* ----------------------------- */
if ( fargset(1) == 0 )
	return(err_val);

if ( fargset(2) == 0 )
	return(err_val);

/* Allocate Descriptor buffer */
/* -------------------------- */
if ( (workptr3 = (BPTR) allocate((USINT) 34)) == (BPTR) 0) 
	return(EXER_MEMFULL);

/* Terminate Name String then Analyse and Prepare old name */
/* ------------------------------------------------------- */
if ( prepare_jointure( workptr1, worklen1, worktyp1, workptr3 ) == SOFTERROR ) {
	liberate(workptr3); 
	return(err_val); 
	}

/* Terminate Name String then Analyse and Prepare old name */
/* ------------------------------------------------------- */
if ( prepare_jointure( workptr2, worklen2, worktyp2, (workptr3+17) ) == SOFTERROR ) {
	liberate(workptr3); 
	return(err_val); 
	}

/* Ensure Ressource Info of New Name == ZERO ! */
/* ------------------------------------------- */
*(workptr3 + 17) = (EXABYTE) 0; *(workptr3 + 18) = (EXABYTE) 0; 

/* Perform the operation SF BD 'Renommer une Jointure' */
/* --------------------------------------------------- */
x = (EXAWORD) mc_key(fidreel,0,(workptr3 + 2),32,0x21BF);

/* Liberate Descriptor Zone */
/* ------------------------ */
liberate(workptr3);

if ( x == MOINS_UN ) 
	return(errno);
else	return(0);

}

/*
 *	B D _ P R E P ()
 *	----------------
 *	Perpares the Variable WORKPTR1 and WORKLEN1 for Data base DOWN/UP
 *
 */

#ifdef	ABAL_CRITERIA
static	VOID bd_put_handle( dptr, dbyte )
BPTR	dptr;
EX_FILE_HANDLE	dbyte;
{	
	*(dptr++) = (EXABYTE) (dbyte & 0x00FF);
	*(dptr++) = (EXABYTE) ((dbyte >> 8) & 0x00FF);
	*(dptr++) = (EXABYTE) ((dbyte >>16) & 0x00FF);
	*(dptr++) = (EXABYTE) ((dbyte >> 24) & 0x00FF);
	return;
}

static	VOID bd_put_ptr( dptr, dbyte )
BPTR	dptr;
EXALONG	dbyte;
{
	*(dptr++) = (EXABYTE) (dbyte & 0x00FF);
	*(dptr++) = (EXABYTE) ((dbyte >> 8) & 0x00FF);
	*(dptr++) = (EXABYTE) ((dbyte >>16) & 0x00FF);
	*(dptr++) = (EXABYTE) ((dbyte >> 24) & 0x00FF);
	return;
}

static	VOID bd_put_word( dptr, dbyte )
BPTR	dptr;
EXAWORD	dbyte;
{
	*(dptr++) = (EXABYTE) (dbyte & 0x00FF);
	*(dptr++) = (EXABYTE) ((dbyte >> 8) & 0x00FF);
	return;
}
#endif	/* ABAL_CRITERIA */

EXAWORD	bd_prep()
{
	BDRECORDPTR	lbdptr;
	EXAWORD lerr;
	EXAWORD workdex;	

	/* Initialise RECORD management zone pointer */
	/* ----------------------------------------- */
	if ((lbdptr = (BDRECORDPTR) fidbuff) == (BDRECORDPTR) 0) {
		err_val = ABAL_MEMORY; return(SOFTERROR); 
		}

#ifdef	ABAL_CRITERIA
	si_lng = ((fidblen * 10) +1);	/* EXALONG + BPTR + EXAWORD : 4 + 4 + 2 = 10 */
#else
	si_lng = ((fidblen * 8) + 1);	/* EXAWORD + BPTR + EXAWORD : 2 + 4 + 2 = 8  */
#endif

	/* Allocate Descriptor buffer */
	/* -------------------------- */
	if ((si_buf = (BPTR) allocate((USINT) 1*(USINT) si_lng)) == (BPTR) 0) {
		err_val = EXER_MEMFULL; return(SOFTERROR);
		}

	/* Initialisation of Descriptor */
	/* ---------------------------- */
	workdex = 1; *si_buf = 0;

	do 	{
#ifdef	ABAL_CRITERIA
		*si_buf += 1;
		bd_put_handle((si_buf+workdex),(*(AssignTable + lbdptr->bdfid)).unlog);
		workdex += 4;
		bd_put_ptr((si_buf+workdex),lbdptr->zdxbdf);
		workdex += 4;
		bd_put_word((si_buf+workdex),lbdptr->zdxlen);
		workdex += 2;
#else
		/* Implantation of the RECORD adresses ,lengths and File Handles */
		/* ------------------------------------------------------------- */
		(VOID) dbprep(workdex,(*(AssignTable + (*(lbdptr)).bdfid)).unlog,(*(lbdptr)).zdxbdf,(*(lbdptr)).zdxlen);
		workdex += 7; 
#endif
		lbdptr = (*(lbdptr)).bdf_next;

		}
	while (lbdptr != (BDRECORDPTR) 0 );

	/* Correction of Amenesik / Sologic SF Code */
	/* ------------------------------ */
	simcbd |= (( si_ver << 2 ) | 0x0080);

	/* Perform DataBase Sequentiel Read (UP/DOWN) */
	/* ------------------------------------------ */
	if ((lerr = (EXAWORD) mc_key(fidreel,si_mq,si_buf,workdex,simcbd)) == MOINS_UN)
		err_val = errno;
	else	err_val = 0;

	/* Liberate descriptor buffer */
	/* -------------------------- */
	liberate(si_buf);

	/* Remarque : Always returns Zero to provoque Switch Break ! */
	/* --------------------------------------------------------- */
	return(SOFTERROR);

}

#ifdef INTEL
#include "exprag1.h"
#endif

	/* ------- */
#endif	/* _EXBD_C */
	/* ------- */
