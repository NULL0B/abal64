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

#include "exmissing.h"
#undef 	DEBUG_BASEFILE

/*
 *	R E M O V E _ D B _ R E C O R D S
 *	---------------------------------
 *
 *	Removes all data base file RECORD declaration structures for
 *	the specified DATA BASE ASSIGN handle 
 *
 */

EXAWORD	remove_bd_records( base_handle )
EXAWORD	base_handle;		
{
	BDRECORDPTR	lbdptr;
	BDRECORDPTR	rbdptr;

	if ( AssignTable != (struct fichdt PTR) 0 ) 
	{
		if ((lbdptr = (BDRECORDPTR) (*(AssignTable + base_handle)).asptr) != (BDRECORDPTR) 0) 
		{
			do	
			{
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
 *
 *	Closure of all DATABASE files associated with a DATABASE ASSIGN
 *	when that DATABASE itself is close.
 *
 */

VOID	close_base_files( EXAWORD	data_base_handle )
{
	EXAWORD	ftidx;
	EXAWORD	holdlfh;

	/* ------------------------------------------------ */
	/* Scan File table for files depending on this base */
	/* ------------------------------------------------ */
	for ( ftidx = 1; ftidx <= diezfic; ftidx++ )
	{
		/* ---------------------------------- */
		/* Check for Data Base Dependant File */
		/* ---------------------------------- */
		if ( ( (*(AssignTable + ftidx)).permf & NGF_TYP ) == NGF_MCBD )
		{
			/* ------------------------------------- */
			/* Check for file depending on this base */
			/* ------------------------------------- */
			if ( (*(AssignTable + ftidx)).dblog == data_base_handle ) 
			{

				/* ---------------------------------------- */
				/* Correction for DIT 3095 : 14/02/1994 IJM */
				/* ---------------------------------------- */
				/* EXA >= 2.1b */
				/* ----------- */

				holdlfh = lfh;
				if ((err_val = savefich()) != 0) return;

				lfh = ftidx;
			 	if ((err_val = loadfich()) != 0) return;

				(VOID) sf_close();

				if ((err_val = savefich()) != 0) return;
	
				lfh = holdlfh;
			 	if ((err_val = loadfich()) != 0) return;

				/* --------------------------- */
				/* Force file to closed Status */
				/* --------------------------- */
				(*(AssignTable + ftidx)).unlog = (EX_FILE_HANDLE)EX_UNUSED_HANDLE;

			}
		}
	}
}

/*
 *	B A S E F I L E ( opt )
 *	-----------------------
 *	Option 0 : 
 *
 *		Remove the DATABASE FILE of the current ASSIGN from the MAP
 *		of the DATABASE indicated by its parent DATABASE handle.
 *
 *	Option 1 : 
 *
 *		Add the DATABASE FILE of the current ASSIGN to the MAP
 *		of the DATABASE indicated by its parent DATABASE handle.
 *
 */

VOID	basefile( opt )
EXAWORD	opt;
{
	BPTR	tptr;
	if (( lfh <= diezfic ) 
	&&  (fidbd != 0) 
	&&  (fidbd != MOINS_UN) 
	&&  ( AssignTable != (struct fichdt PTR) 0))
	{
		if ( (tptr = (*(AssignTable + fidbd)).bdext) != (BPTR) 0)
			*(tptr + lfh) = (EXABYTE) opt;
	}
	return;
}

/*
 *	M A K E B A S E ( )
 *	-------------------
 *	
 *	Creates the DATABASE FILE tracking MAP
 *
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
 *	L O C A T E _ B D _ R E C O R D ( )
 *	-----------------------------------
 *	Management of Data base file record zones
 *	
 */

BDRECORDPTR	locate_bd_record( base_handle, file_handle )
EXAWORD	base_handle;
EXAWORD	file_handle;
{
	BDRECORDPTR	lbdptr=(BDRECORDPTR) 0;

	/* ---------------------------------- */
	/* Establish RECORD TREE base pointer */
	/* ---------------------------------- */
	if ( AssignTable != (struct fichdt PTR) 0 ) 
	{
		if ((lbdptr = (BDRECORDPTR) (*(AssignTable + base_handle)).asptr) != (BDRECORDPTR) 0) 
		{
			do	
			{
				if ( lbdptr->bdfid == file_handle )
					break;
			}
			while ((lbdptr = lbdptr->bdf_next) != (BDRECORDPTR) 0);
		}
	}
	return( lbdptr );
}

/*
 *	e s t a b l i s h _ b d _ r e c o r d  ( )
 *	------------------------------------------
 *
 *	stores the record information into the ASSIGN table
 *	DATABASE RECORD management node.
 *
 */

EXAWORD	establish_bd_record( BDRECORDPTR rptr, EXAWORD file_handle, BPTR recordptr, EXAWORD recordlen)

{
	rptr->zdxbdf = recordptr;
	rptr->zdxlen = recordlen;
	rptr->bdfid  = file_handle;
	return( 0 );
}

/*
 *	A D D _ B D _ R E C O R D ( )
 * 	----------------------------
 *
 *	Adds a DATABASE RECORD management structure to the list of
 *	DATABASE RECORDs of the DATABASE ASSIGN table entry.
 *
 */

EXAWORD	add_bd_record( base_handle,file_handle, recordptr, recordlen )
EXAWORD	base_handle;
EXAWORD	file_handle;
BPTR	recordptr;
EXAWORD	recordlen;
{
	BDRECORDPTR	lbdptr;
	BDRECORDPTR	rbdptr;

	/* ------------------------------------------------- */
	/* allocate the DATABASE RECORD management structure */
	/* ------------------------------------------------- */
	if ((lbdptr= (BDRECORDPTR) allocate((USINT) sizeof(struct bdf_zone) )) == (BDRECORDPTR) 0 )
		return( 27 );

	/* --------------------------------------------------- */
	/* insert it to the top of the list as the most recent */
	/* --------------------------------------------------- */
	if ((rbdptr = (BDRECORDPTR) (*(AssignTable + base_handle)).asptr) != (BDRECORDPTR) 0)
		rbdptr->bdf_prev = lbdptr;
	
	lbdptr->bdf_next = rbdptr;
	lbdptr->bdf_prev = (BDRECORDPTR) 0;

	/* ----------------------------------------------- */
	/* store the list and increment the RECORD counter */
	/* ----------------------------------------------- */
	(*(AssignTable + base_handle)).asptr = (BPTR) lbdptr;
	(*(AssignTable + base_handle)).aslen++;

	/* ------------------------------------------------- */
	/* store the information to this RECORD manager node */
	/* ------------------------------------------------- */
	return(	establish_bd_record( lbdptr, file_handle, recordptr, recordlen ) );
}

/*
 *	R E M O V E  _ B D _ R E C O R D ( )
 * 	------------------------------------
 *
 *	Removes a DATABASE RECORD management structure from the list of
 *	DATABASE RECORDs of the DATABASE ASSIGN table entry.
 *
 */

EXAWORD	remove_bd_record( base_handle, file_handle )
EXAWORD	base_handle;
EXAWORD	file_handle;
{
	BDRECORDPTR	lbdptr;
	BDRECORDPTR	xbdptr;
	BDRECORDPTR	rbdptr;

	/* ---------------------------------------------------------------------- */
	/* find the DATABASE FILE RECORD management node from the DATABASE ASSIGN */
	/* ---------------------------------------------------------------------- */
	if ((xbdptr = locate_bd_record( base_handle, file_handle )) != (BDRECORDPTR) 0) 
	{
		/* ------------------------------------------- */
		/* disconnect it from the list of RECORD nodes */
		/* ------------------------------------------- */
		if ((lbdptr = xbdptr->bdf_prev) != (BDRECORDPTR) 0)
			lbdptr->bdf_next = xbdptr->bdf_next;

		if ((rbdptr = xbdptr->bdf_next) != (BDRECORDPTR) 0)
			rbdptr->bdf_prev = xbdptr->bdf_prev;

		if (lbdptr == (BDRECORDPTR) 0)
			lbdptr = rbdptr;

		/* ------------------------------------------------------------ */
		/* store the remaining list of RECORD nodes in the ASSIGN table */
		/* ------------------------------------------------------------ */
		(*(AssignTable + base_handle)).asptr = (BPTR) lbdptr;
		(*(AssignTable + base_handle)).aslen--;
		liberate( xbdptr );
	}

	return( 0 );
}

/*
 *	B D R E C O R D ( )
 * 	-------------------
 *
 *	Handles the NGF RECORD operation.
 *	
 *	Either :
 *
 *	- Evaluates the DATABASE FILE RECORD buffer parameter.
 *	- Adds a RECORD management node to the DATABASE ASSIGN table.
 *
 *	Or :
 *
 *	- No DATABASE FILE RECORD buffer parameter
 *	- Removes any RECORD management node from the DATABASE ASSIGN table.
 *
 */

EXAWORD	bdrecord()
{
	BDRECORDPTR	lbdptr;

	/* ----------------------------------- */
	/* Ensure Data Base File Access Method */
	/* ----------------------------------- */
	if ((fidperm & NGF_BD) == 0) 
		return(EXER_FUNCWOT);

	/* ------------------------ */
	/* Establish Type of Action */
	/* ------------------------ */
	if ( fargset(1) != 0 ) 
	{

		/* --------------------------------------------------- */
		/* Since FARGSET(1) OK we have a RECORD to add to TREE */
		/* --------------------------------------------------- */

		/* -------------------------------------- */
		/* Collect RECORD zone length if Supplied */
		/* -------------------------------------- */
		if ( fargset(2) != 0 ) 
			worklen1 = (EXAWORD) workval2;

		/* --------------------------------------------------------------- */
		/* attempt to locate an existing RECORD node and CREATE if missing */
		/* --------------------------------------------------------------- */
		if ((lbdptr = locate_bd_record( fidbd, lfh )) == (BDRECORDPTR) 0)
			return( add_bd_record( fidbd, lfh, workptr1, worklen1 ) );

		/* --------------------------------------------------------------- */
		/* otherwise update the existing RECORD node with the RECORD infos */
		/* --------------------------------------------------------------- */
		else	return( establish_bd_record(lbdptr, lfh, workptr1, worklen1 ) );
 
	}
	else	
	{
		/* ---------------------------------------------------- */
		/* Since no Record pointer provided : Remove RECORD(s)  */
		/* ---------------------------------------------------- */

		/* ------------------------------- */
		/* Check for DataBase File Request */
		/* ------------------------------- */
		if (( fidperm & NGF_MC ) == NGF_MC) 
			return( remove_bd_record( fidbd, lfh ));

		/* -------------------------------------------------------- */
		/* if the request was to a DATABASE then remove all RECORDS */
		/* -------------------------------------------------------- */
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
	EXAWORD	x;

	/* -------------------------------- */
	/* Evaluation des arguaments T-Code */
	/* -------------------------------- */
	if (fargset(2) == 0) 
		return(err_val);

	if (fargset(1) == 0)
		return(err_val);

	/* --------------------------------------------------- */
	/* Calculate and allocate memory needed for descriptor */
	/* --------------------------------------------------- */
	if ((worklen3 = lenuze(workptr1,worklen1)) == 0)  
		return(EXER_SYNTAX);

	worklen3 /= 3;

	if ( worklen3 == 0 ) worklen3++;

	if (!bSystemLongNames)
	{
		worklen3 *= JOIN_TOKEN_LEN_STD; 
		worklen3 += JOIN_ANFC_DESC_LEN_STD;
	}
	else
	{
		worklen3 *= JOIN_TOKEN_LEN_EXT; 
		worklen3 += JOIN_ANFC_DESC_LEN_EXT;
	}

	if ((workptr3 =(BPTR) allocate((USINT) worklen3)) == (BPTR)0)
		return(EXER_MEMFULL);

	/* ------------------------- */
	/* Perform JOINTURE analysis */
	/* ------------------------- */
	if ( prepare_jointure( (BPTR) workptr2, worklen2, 3, workptr3 ) == SOFTERROR ) 
	{
		liberate(workptr3); 
		return(err_val);
	}

	/* ---------------------------------- */
	/* Perform the Rubrique List analysis */
	/* ---------------------------------- */
	workptr2 = workptr3 + (JOIN_ANFC_DESC_LEN_STD-1); 
	worklen2 = worklen3 - (JOIN_ANFC_DESC_LEN_STD-1);
	*workptr2 = (EXABYTE) 0;
	if ( questprep(4) != 0 ) {
	 
		liberate(workptr3); 
		return(EXER_RUBWOT); 
	}

	/* ------------------------ */
	/* Adjust for Jointure Name */
	/* ------------------------ */
	worklen2 += (JOIN_ANFC_DESC_LEN_STD-1);

	/* -------------------------------------------------------- */
	/* Perform the Operation SF BD 'Description d'une Jointure' */
	/* -------------------------------------------------------- */
	x = (EXAWORD) mc_key(fidreel,0,workptr3,worklen2,0x21AE,0);

	/* -------------------------- */
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

	/* ----------------------------------- */
	/* Establish Jointure Name if Provided */
	/* ----------------------------------- */
	if ( fargset(1) == 0 ) 
	{
		x = 0; 
		workptr2 = (BPTR) 0; 
		worklen2 = 0;
	}
	else 	
	{
		x = 1;
		/* -------------------------- */
		/* Allocate Jointure WorkZone */
		/* -------------------------- */
		if ((workptr3 = (BPTR) allocate((USINT) 17)) == (BPTR) 0)
			return(EXER_MEMFULL);

		/* --------------------------------- */
		/* Analyse and prepare Jointure Name */
		/* --------------------------------- */
		if ( prepare_jointure( workptr1, worklen1, 3, workptr3 ) == SOFTERROR ) 
		{
			liberate(workptr3); 
			return(err_val);
		}
		workptr2 = workptr3 + 2; worklen2 = 15;
	}

	/* ---------------------------------------------------- */
	/* Perform the operation SF BD 'Creation des Jointures' */
	/* ---------------------------------------------------- */
	y = (EXAWORD) mc_key(fidreel,x,workptr2,worklen2,0x21B6,0);

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

	/* ------------------------------------ */
	/* Establish name of Jointure to Delete */
	/* ------------------------------------ */
	if ( fargset(1) == SOFTERROR ) 	
		return(err_val);

	/* --------------------------------- */
	/* Allocate Jointure Descriptor Zone */
	/* --------------------------------- */
	if ((workptr3 = (BPTR) allocate((USINT) 19)) == (BPTR) 0) 
		return(EXER_MEMFULL);

	if ( prepare_jointure( workptr1, worklen1, worktyp1, workptr3) == SOFTERROR) 
	{
		liberate(workptr3); 
		return(err_val);
	}

	/* ------------------------------------------------ */
	/* Establish Suplimentary information in descriptor */
	/* ------------------------------------------------ */
	*(workptr3 + 17) = (EXABYTE) 3; 
	*(workptr3 + 18) = (EXABYTE) (fidreel & 0x00FF);

	/* ----------------------------- */
	/* Perform Supression (Appel MC) */
	/* ----------------------------- */
	x = killjoin(workptr3);

	/* ------------------- */
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

	/* ----------------------------- */
	/* Evaluate Arguaments in T-Code */
	/* ----------------------------- */
	if ( fargset(1) == 0 )
		return(err_val);

	if ( fargset(2) == 0 )
		return(err_val);

	/* -------------------------- */
	/* Allocate Descriptor buffer */
	/* -------------------------- */
	if ( (workptr3 = (BPTR) allocate((USINT) 34)) == (BPTR) 0) 
		return(EXER_MEMFULL);

	/* ------------------------------------------------------- */
	/* Terminate Name String then Analyse and Prepare old name */
	/* ------------------------------------------------------- */
	if ( prepare_jointure( workptr1, worklen1, worktyp1, workptr3 ) == SOFTERROR ) 
	{
		liberate(workptr3); 
		return(err_val); 
	}

	/* ------------------------------------------------------- */
	/* Terminate Name String then Analyse and Prepare old name */
	/* ------------------------------------------------------- */
	if ( prepare_jointure( workptr2, worklen2, worktyp2, (workptr3+17) ) == SOFTERROR ) 
	{
		liberate(workptr3); 
		return(err_val); 
	}

	/* ------------------------------------------- */
	/* Ensure Ressource Info of New Name == ZERO ! */
	/* ------------------------------------------- */
	*(workptr3 + 17) = (EXABYTE) 0; *(workptr3 + 18) = (EXABYTE) 0; 

	/* --------------------------------------------------- */
	/* Perform the operation SF BD 'Renommer une Jointure' */
	/* --------------------------------------------------- */
	x = (EXAWORD) mc_key(fidreel,0,(workptr3 + 2),32,0x21BF,0);

	/* ------------------------ */
	/* Liberate Descriptor Zone */
	/* ------------------------ */
	liberate(workptr3);

	if ( x == MOINS_UN ) 
		return(errno);
	else	return(0);

}

#ifdef	ABAL_CRITERIA
static	VOID bd_put_handle( dptr, dbyte )
BPTR	dptr;
EX_FILE_HANDLE	dbyte;
{	
	int	i;
	for ( i=0; i < sizeof(BPTR); i++)
	{
		*(dptr++) = (EXABYTE) (dbyte & 0x00FF);
		dbyte >>= 8;
	}
	return;
}

static	VOID bd_put_ptr( dptr, dbyte )
BPTR	dptr;
EXALONG	dbyte;
{
	int	i;
	for ( i=0; i < sizeof(BPTR); i++)
	{
		*(dptr++) = (EXABYTE) (dbyte & 0x00FF);
		dbyte >>= 8;
	}
	return;
}

static	VOID bd_put_word( dptr, dbyte )
BPTR	dptr;
EXAWORD	dbyte;
{
	int	i;
	for ( i=0; i < sizeof(short); i++)
	{
		*(dptr++) = (EXABYTE) (dbyte & 0x00FF);
		dbyte >>= 8;
	}
	return;
}
#endif	/* ABAL_CRITERIA */

/*
 *	B D _ P R E P ()
 *	----------------
 *	Perpares the Variable WORKPTR1 and WORKLEN1 for Data base DOWN/UP
 *
 */

EXAWORD	bd_prep()
{
	BDRECORDPTR	lbdptr;
	EXAWORD lerr;
	EXAWORD workdex;	

	/* ----------------------------------------- */
	/* Initialise RECORD management zone pointer */
	/* ----------------------------------------- */
	if ((lbdptr = (BDRECORDPTR) fidbuff) == (BDRECORDPTR) 0) 
	{
		err_val = ABAL_MEMORY; return(SOFTERROR); 
	}

#ifdef	ABAL64
	/* ---------------------------------------------------------- */
	/* this describes the descriptor that is used for each RECORD */
	/* ---------------------------------------------------------- */
	si_lng = ((fidblen * (sizeof(BPTR) + sizeof(BPTR) + sizeof(short int))) + 1);
#else
#ifdef	ABAL_CRITERIA
	si_lng = ((fidblen * 10) +1);	/* EXALONG + BPTR + EXAWORD : 4 + 4 + 2 = 10 */
#else
	si_lng = ((fidblen * 8) + 1);	/* EXAWORD + BPTR + EXAWORD : 2 + 4 + 2 = 8  */
#endif
#endif	/* ABAL64 */

	/* -------------------------- */
	/* Allocate Descriptor buffer */
	/* -------------------------- */
	if ((si_buf = (BPTR) allocate((USINT) si_lng)) == (BPTR) 0) 
	{
		err_val = EXER_MEMFULL; return(SOFTERROR);
	}

	/* ---------------------------- */
	/* Initialisation of Descriptor */
	/* ---------------------------- */
	workdex = 1; *si_buf = 0;

	do 	
	{
#ifdef	ABAL_CRITERIA
		*si_buf += 1;
		bd_put_handle((si_buf+workdex),(*(AssignTable + lbdptr->bdfid)).unlog);
		workdex += sizeof(BPTR);
		bd_put_ptr((si_buf+workdex),lbdptr->zdxbdf);
		workdex += sizeof(BPTR);
		bd_put_word((si_buf+workdex),lbdptr->zdxlen);
		workdex += sizeof(short);
#else
		/* ------------------------------------------------------------- */
		/* Implantation of the RECORD adresses ,lengths and File Handles */
		/* ------------------------------------------------------------- */
		(VOID) dbprep(workdex,(*(AssignTable + (*(lbdptr)).bdfid)).unlog,(*(lbdptr)).zdxbdf,(*(lbdptr)).zdxlen);
		workdex += 7; 
#endif
		lbdptr = (*(lbdptr)).bdf_next;

	}
	while (lbdptr != (BDRECORDPTR) 0 );

	/* ------------------------------ */
	/* Correction of Amenesik / Sologic SF Code */
	/* ------------------------------ */
	simcbd |= (( si_ver << 2 ) | 0x0080);

	/* ------------------------------------------ */
	/* Perform DataBase Sequentiel Read (UP/DOWN) */
	/* ------------------------------------------ */
	if ((lerr = (EXAWORD) mc_key(fidreel,si_mq,si_buf,workdex,simcbd,0)) == MOINS_UN)
		err_val = errno;
	else	err_val = 0;

	/* -------------------------- */
	/* Liberate descriptor buffer */
	/* -------------------------- */
	liberate(si_buf);

	/* --------------------------------------------------------- */
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

