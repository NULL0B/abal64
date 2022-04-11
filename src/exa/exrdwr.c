/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXRDWR - C				*/
/*		Date 	:	27/09/1994				*/
/*		Version :	1.4e / 2.1c				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	EXRDWRC		/* If not already included			*/
#define	EXRDWRC		/* Avoid multiple inclusions			*/
			/* -------------------------------------------- */

#ifdef	ABAL_CRITERIA

#include "exxml.h"

/**************************************************************************/
/*** SI AVEC AD/SEQ/SI/MC/BD detaches avec interfaces crwin ***************/
/**************************************************************************/

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

/**** A revoir #ifdef	ABAL_UNIX_IO	*/
/*****#include "exdiskio.c"		*/
/*****#endif				*/

EXAWORD	sf_read_write()
{
	EXAWORD 	transfert;
	LSEEKTYPE	position;
	EXAWORD		ngfcode;
	EXAWORD		option;
	EXAWORD		ret_cod;

	/* If Error collecting operation Code Return Error */
	/* ----------------------------------------------- */
	if ( fargset(1) == SOFTERROR ) 
		return(err_val);

	/* Establish local and global Operation Code Value */
	/* ----------------------------------------------- */	
	simcbd = ngfcode = (EXAWORD) workval1;

	/* If Error collecting Buffer Return Error Value */
	/* --------------------------------------------- */
	if ( fargset((ngfcode & 0x0080) >> 7) == SOFTERROR) 
		return(err_val); 

	/* If Error collecting length Return Error Value */
	/* --------------------------------------------- */
	if ( fargset(2) == SOFTERROR ) 
		return(err_val);

	/* Determine whether to use length */
	/* ------------------------------- */
	if ( worktyp2 < 2 ) 
		worklen1 = workval2;

	/* Collect Sector/Message Value or RETURN ERROR */
	/* --------------------------------------------	*/
	if ( largset(3) == SOFTERROR ) 
		return(err_val);

	/* Select FILE ACCESS METHOD */
	/* ------------------------- */
	switch((fidperm & NGF_TYP)) {

#ifdef	ABALXML
/* ******************************************************************** */
/* 		XML SOURCE STREAM PARSER  FUNCTIONS			*/
/* ******************************************************************** */
	case NGF_XML	:
		switch ( (ngfcode & 0x00FF) ) {
			case	_XML_WRITEALL	: /* using white space */
			case	_XML_WRITE	:
				return( AbalXmlWrite( fidbuff, ngfcode, workptr1, worklen1 ) );
			case	_XML_READALL	: /* keeping white space */
			case	_XML_READ	:
				return( AbalXmlParse( fidbuff, ngfcode, workptr1, worklen1 ) );
			default		:
				return( AbalXmlInfo( fidbuff, ngfcode, workptr1, worklen1 ) );
			}
	/* ------- */
#endif	/* ABALXML */
	/* ------- */

/* ******************************************************************** */
/*		IPC MESSAGE COMMUNICATION FUNCTIONS			*/
/* ******************************************************************** */

	case NGF_CM  :

#ifdef ABALMSG

	/*	Convert from LSEEK value	*/
	/*	------------------------	*/
		hugeint /= BLOCK;

	/*	Perform IPC function and RETURN ERROR		*/
	/*	-------------------------------------		*/
		return( msgwork(ngfcode) );

#else

	/*	IPC MESSAGE OPTION NOT AVAILABLE	*/
	/*	--------------------------------	*/
		return(56);

	/* ------- */
#endif	/* ABALMSG */
	/* ------- */

/* ******************************************************************** */
/*		PRINTER INTERFACE HANDLING FUNCTIONS			*/
/* ******************************************************************** */

	case NGF_IM  :

	/*	PRINT WRITE OPTION NOT AVAILABLE	*/
	/*	--------------------------------	*/
		return(56);

/* ******************************************************************** */
/*		RAW DEVICE (DISK/DISKETTE) FUNCTIONS			*/
/* ******************************************************************** */
	case NGF_DV  :

#ifndef UNIX
#ifndef VMS

	/* 	Perform RAW DEVICE function and Return Error Status 	*/
	/* 	---------------------------------------------------	*/
	return(io_func((EXAWORD)fidreel,ngfcode, workptr1,worklen1,(EXALONG) (hugeint / BLOCK)));

#endif
#endif
#ifdef	UNIX
	switch ( ngfcode ) {
		case	PRL_WRUNIX	:
			if ( write( fidreel, workptr1,worklen1 ) != worklen1 ) {
				traitfilerror(-1,errno);
				return( err_val );
				}
			else	return((err_val = 0));

		case	PRL_RDUNIX	:
#ifdef	LINUX
			fcntl( fidreel,F_SETFL,FNDELAY);
#else
			fcntl( fidreel,F_SETFL,O_NDELAY);
#endif
			if ((transfert = read( fidreel, workptr1,worklen1 )) != worklen1 ) {
				if ( transfert )
					err_val = 48;
				else	err_val = 53;
				}
			else	err_val = 0;
			fcntl( fidreel,F_SETFL,0);
			return( err_val );
		default			:
			return((err_val = 56));
		}
#endif

/* ******************************************************************** */
/*		GRAPHICAL INTERFACE SCREEN FUNCTIONS			*/
/* ******************************************************************** */

	case NGF_GR  :

/* ******************************************************************** */
/*		SECTORISED STANDARD FILE FUNCTIONS			*/
/* ******************************************************************** */

case NGF_IO  :

	/* Perform Primary Function Group Selection */
	/* ---------------------------------------- */
	switch ( ngfcode ) {
					/* ---------------------------- */
		case PRL_CHAR	:	/* REQUEST FOR CHARACTERISTICS	*/
					/* ---------------------------- */

			/* Perform Function and Return Status */
			/* ---------------------------------- */
			return(ngf_infos());

					/* ---------------------------- */
		case PRL_RDBLOC :	/* READ  BLOCK 			*/
		case PRL_WRBLOC :	/* WRITE BLOCK 			*/
					/* ---------------------------- */
			position=(LSEEKTYPE) ((hugeint / BLOCK) * worklen1);
			break;

					/* ---------------------------- */
		case PRL_DVRDIM	:	/* READ  DEVICE NON-BUFFERISED 	*/
		case PRL_DVRDBF	:	/* READ  DEVICE BUFFERISED	*/
		case PRL_DVWRIM	:	/* WRITE DEVICE NON-BUFFERISED 	*/
		case PRL_DVWRBF	:	/* WRITE DEVICE BUFFERISED	*/
		case PRL_RDSECT	:	/* READ  SECTORISED FILE	*/
		case PRL_WRSECT	:	/* WRITE SECTORISED FILE	*/
					/* ---------------------------- */
			position=hugeint;
			break;

		default :		/* ALL OTHER CODES		*/
					/* ---------------		*/
/* ? */
			position=hugeint;
			break;

		}

	/* Perform Secondary Function Group Selection */
	/* ------------------------------------------ */
	switch ( ngfcode ) {
		case	PRL_WRUNIX	:
			if ( write( fidreel, workptr1,worklen1 ) != worklen1 ) {
				traitfilerror(-1,errno);
				return( err_val );
				}
			else	return((err_val = 0));

		case	PRL_RDUNIX	:
			if ((transfert = read( fidreel, workptr1,worklen1 )) != worklen1 ) {
				if ( transfert)
					return((err_val = 48));
				else	return((err_val = 53));
				}
			else	return((err_val = 0));

					/* ---------------------------- */
		case PRL_DVRDIM	:	/* READ  DEVICE NON-BUFFERISED 	*/
		case PRL_DVRDBF	:	/* READ  DEVICE BUFFERISED	*/
		case PRL_RDSECT	:	/* READ  SECTORISED FILE	*/
		case PRL_RDBLOC :	/* READ  BLOCK 			*/
					/* ---------------------------- */

		/* Attempt requested READ operation */
		/* -------------------------------- */
		fidseek=position;
		ret_cod=EeEad_read(fidreel, workptr1, worklen1);
		transfert=(EXAWORD)(fidseek-(LSEEKTYPE)position);
		if (ret_cod == 48)	/* on a lu quelque chose mais pas tout*/
			{
			/* Calculate length to be reset to Zero */
			/* ------------------------------------ */
			workval1 = (worklen1 - transfert);

			/* Reset Rest or One Sector to ZERO */
			/* -------------------------------- */
			if ( (workval1 % 256) > 0 )
				(VOID) memset((workptr1 + transfert),0,(USINT) (workval1 % 256));

			/* Establish End of File Error */
			/* --------------------------- */
			err_val = EXER_FILEFIN;
			}
		else
			{ err_val=ret_cod; }
		/* Return the prepared ERROR Status */
		/* -------------------------------- */
		return(err_val); 

					/* ---------------------------- */
		case PRL_DVWRIM	:	/* WRITE DEVICE NON-BUFFERISED 	*/
		case PRL_DVWRBF	:	/* WRITE DEVICE BUFFERISED	*/
		case PRL_WRSECT	:	/* WRITE SECTORISED FILE	*/
		case PRL_WRBLOC :	/* WRITE BLOCK 			*/
					/* ---------------------------- */

#ifdef PRL_SF
					/* ---------------------------- */
		default		:	/* POSSIBLE TTY BSC X25 CODES   */
					/* ---------------------------- */
#endif

		/* Attempt requested Write operation */
		/* --------------------------------- */
		fidseek=position;
		ret_cod=EeEad_write(fidreel, workptr1, worklen1);
		return((errno=err_val=ret_cod));
		}

/* ******************************************************************** */
/*		SI , I.S.A.M. , RMS interface				*/
/* ******************************************************************** */
case NGF_MC :

	/* Reset Option to ZERO */
	/* -------------------- */
	option = 0;

	/* Select Requested operation */
	/* -------------------------- */
	switch ( ngfcode ) {

	case    PRL_CHAR   : return(ngf_infos());

	default		   : return(56);
	}

case NGF_SI :

	/* Reset Option to ZERO */
	/* -------------------- */
	option = 0;

	/* Select Requested operation */
	/* -------------------------- */
	switch ( ngfcode ) {

	case    PRL_CHAR   : return(ngf_infos());

	case	PRL_WRZC   : if (!(ret_cod = EeEsi_writezc(fidreel,workptr1,worklen1)))
					ret_cod = worklen1;
				else	{ errno=err_val=ret_cod; ret_cod=MOINS_UN; }

			     break;

	case	PRL_RDZCEX : option = 1;
	case	PRL_RDZC   : if (!(ret_cod = EeEsi_readzc(fidreel,option,workptr1,worklen1)))
					ret_cod = worklen1;
				else	{ errno=err_val=ret_cod; ret_cod=MOINS_UN; }

			     break;

	default		   : return(56);
	}

	/* Check for Errors and Buffer fill */
	/* -------------------------------- */
	if (ret_cod == MOINS_UN) 
		return(err_val);
	if ( ret_cod < worklen1 )
		memset((workptr1 + ret_cod),' ',(worklen1 - ret_cod));

	return(0);


/* ******************************************************************** */
/*		SEQUENTIEL FILE ACCESS METHOD				*/
/* ******************************************************************** */

case NGF_SQ :

	/* If not REQUEST FOR CHARACTERISTICS */
	/* ---------------------------------- */
	if ( ngfcode != PRL_CHAR ) {

		/* Perform requested file function */
		/* ------------------------------- */
		switch ( ngfcode ) {
			case 0x0061 : 
				if (ret_cod=EeEsq_read(fidreel,workptr1,worklen1))
					{ errno=err_val=ret_cod; ret_cod=MOINS_UN; }
				break;
			case 0x00A5 : 
				if (ret_cod=EeEsq_write(fidreel,workptr1,worklen1))
					{ errno=err_val=ret_cod; ret_cod=MOINS_UN; }
				break;
			case 0x00A1 : 
				if (ret_cod=EeEsq_modif(fidreel,workptr1,worklen1))
					{ errno=err_val=ret_cod; ret_cod=MOINS_UN; }
				break;
			default :
				errno = EXER_FUNCWOT; ret_cod=MOINS_UN;
			}

		if ( ret_cod == MOINS_UN )
			return(errno);
		else	return(0);
		}
	else	/* Perform Characteristics Function */
		/* -------------------------------- */
		return(ngf_infos());

	}

	/* FUNCTION NOT KNOWN */
	/* ------------------ */
	return(56);

}

#else	/* NOT ABAL_CRITERIA */

/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXRDWR - C				*/
/*		Date 	:	27/09/1994				*/
/*		Version :	1.4e / 2.1c				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	ABAL_TCPIP

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

#ifdef	ABAL_UNIX_IO
#include "exdiskio.c"
#endif


EXAWORD	sf_read_write()
{
	EXAWORD	ngfcode;
	EXAWORD	option;
	EXAWORD	ret_cod;

	/* If Error collecting operation Code Return Error */
	/* ----------------------------------------------- */
	if ( fargset(1) == SOFTERROR ) 
		return(err_val);

	/* Establish local and global Operation Code Value */
	/* ----------------------------------------------- */	
	simcbd = ngfcode = (EXAWORD) workval1;

	/* If Error collecting Buffer Return Error Value */
	/* --------------------------------------------- */
	if ( fargset((ngfcode & 0x0080) >> 7) == SOFTERROR) 
		return(err_val); 

	/* If Error collecting length Return Error Value */
	/* --------------------------------------------- */
	if ( fargset(2) == SOFTERROR ) 
		return(err_val);

	/* Determine whether to use length */
	/* ------------------------------- */
	if ( worktyp2 < 2 ) 
		worklen1 = workval2;

	/* Collect Sector/Message Value or RETURN ERROR */
	/* --------------------------------------------	*/
	if ( largset(3) == SOFTERROR ) 
		return(err_val);

	/* Select FILE ACCESS METHOD */
	/* ------------------------- */
	switch((fidperm & NGF_TYP)) {

/* ******************************************************************** */
/*		IPC MESSAGE COMMUNICATION FUNCTIONS			*/
/* ******************************************************************** */

	case NGF_CM  :

#ifdef ABALMSG

	/*	Convert from LSEEK value	*/
	/*	------------------------	*/
		hugeint /= BLOCK;

	/*	Perform IPC function and RETURN ERROR		*/
	/*	-------------------------------------		*/
		return( msgwork(ngfcode) );

#else

	/*	IPC MESSAGE OPTION NOT AVAILABLE	*/
	/*	--------------------------------	*/
		return(56);

	/* ------- */
#endif	/* ABALMSG */
	/* ------- */

/* ******************************************************************** */
/*		PRINTER INTERFACE HANDLING FUNCTIONS			*/
/* ******************************************************************** */

	case NGF_IM  :

#ifdef	ABAL14

	/*	Eliminate all operations except WRITE 	*/
	/*	-------------------------------------	*/
		if (( ngfcode & 0x00FF ) != 0x00A0 )
			return((err_val = 56));

	/*	Establish Printer 			*/
	/*	-----------------			*/
		err_val = Establish_Printer();

	/* 	While no Error Perform Print output	*/
	/*	-----------------------------------	*/
		while ((err_val == 0) && (worklen1 > 0)) { 
			x_putch(*(workptr1++)); 
			worklen1--; 
			}

	/*	Return Error Status			*/
	/* 	-------------------			*/			
		return( err_val );

#else

	/*	PRINT WRITE OPTION NOT AVAILABLE	*/
	/*	--------------------------------	*/
		return(56);

	/* ------ */
#endif	/* ABAL14 */
	/* ------ */

/* ******************************************************************** */
/*		RAW DEVICE (DISK/DISKETTE) FUNCTIONS			*/
/* ******************************************************************** */
	case NGF_DV  :

#ifndef UNIX
#ifndef VMS

	/* 	Perform RAW DEVICE function and Return Error Status 	*/
	/* 	---------------------------------------------------	*/
	return(io_func(fidreel,ngfcode, workptr1,worklen1,(EXALONG) (hugeint / BLOCK)));

#endif
#endif

/* ******************************************************************** */
/*		GRAPHICAL INTERFACE SCREEN FUNCTIONS			*/
/* ******************************************************************** */

	case NGF_GR  :

/* ******************************************************************** */
/*		SECTORISED STANDARD FILE FUNCTIONS			*/
/* ******************************************************************** */

case NGF_IO  :

	/* Perform Primary Function Group Selection */
	/* ---------------------------------------- */
	switch ( ngfcode ) {

					/* ---------------------------- */
		case PRL_CHAR	:	/* REQUEST FOR CHARACTERISTICS	*/
					/* ---------------------------- */

			/* Perform Function and Return Status */
			/* ---------------------------------- */
			return(ngf_infos());

					/* ---------------------------- */
		case PRL_RDBLOC :	/* READ  BLOCK 			*/
		case PRL_WRBLOC :	/* WRITE BLOCK 			*/
					/* ---------------------------- */

#ifdef	PROLOGUE
			/* Attempt to Seek to file offset or RETURN ERROR */
			/* ---------------------------------------------- */
			if ( lseek(fidreel,(EXALONG) hugeint, SEEK_SET) == -1L )
				return((err_val = EXER_ADRSECT));
#else
			/* Attempt to Seek to file offset or RETURN ERROR */
			/* ---------------------------------------------- */
			if ( lseek(fidreel,(EXALONG) ((hugeint / BLOCK) * worklen1),SEEK_SET) == -1L )
				return((err_val = EXER_ADRSECT));

#endif
			break;

					/* ---------------------------- */
		case PRL_DVRDIM	:	/* READ  DEVICE NON-BUFFERISED 	*/
		case PRL_DVRDBF	:	/* READ  DEVICE BUFFERISED	*/
#ifdef	ABAL_UNIX_IO
			return( diskread(fidreel,(EXAWORD)(hugeint/BLOCK),workptr1,worklen1) );
#endif
		case PRL_DVWRIM	:	/* WRITE DEVICE NON-BUFFERISED 	*/
		case PRL_DVWRBF	:	/* WRITE DEVICE BUFFERISED	*/
#ifdef	ABAL_UNIX_IO
			return( diskwrite(fidreel,(EXAWORD)(hugeint/BLOCK),workptr1,worklen1) );
#endif
		case PRL_RDSECT	:	/* READ  SECTORISED FILE	*/
		case PRL_WRSECT	:	/* WRITE SECTORISED FILE	*/
					/* ---------------------------- */

			/* Attempt to seek to Sector offset or RETURN ERROR */
			/* ------------------------------------------------ */
			if ( lseek(fidreel,hugeint,SEEK_SET) == -1L )
				return((err_val = EXER_ADRSECT));
			break;

		case	PRL_WRUNIX	:
		case	PRL_RDUNIX	:
			break;

		default :		/* ALL OTHER CODES		*/
					/* ---------------		*/
#ifndef PRL_SF
			return(56);
#else

			/* Attempt to seek to Sector offset or RETURN ERROR */
			/* ------------------------------------------------ */
			if ( lseek(fidreel,hugeint,SEEK_SET) == -1L )
				return((err_val = EXER_ADRSECT));
			break;

	/* -------- */
#endif	/* ! PRL_SF */
	/* -------- */

		}

	/* Perform Secondary Function Group Selection */
	/* ------------------------------------------ */
	switch ( ngfcode ) {
					/* ---------------------------- */
		case PRL_DVRDIM	:	/* READ  DEVICE NON-BUFFERISED 	*/
		case PRL_DVRDBF	:	/* READ  DEVICE BUFFERISED	*/
		case PRL_RDSECT	:	/* READ  SECTORISED FILE	*/
		case PRL_RDBLOC :	/* READ  BLOCK 			*/
					/* ---------------------------- */

		/* Attempt requested READ operation */
		/* -------------------------------- */
		if ((ret_cod = read(fidreel,workptr1,worklen1)) == worklen1)

			/* READ Performed With No Error */
			/* ---------------------------- */
			return(0);
	
		/* If Something has been read then End of File reached */
		/* --------------------------------------------------- */
		if (( ret_cod != MOINS_UN ) && ( ret_cod != 0 )) {

			/* Calculate length to be reset to Zero */
			/* ------------------------------------ */
			workval1 = (worklen1 - ret_cod);

			/* Reset Rest or One Sector to ZERO */
			/* -------------------------------- */
			if ( (workval1 % 256) > 0 )
				(VOID) memset((workptr1 + ret_cod),0,(USINT) (workval1 % 256));

			/* Establish End of File Error */
			/* --------------------------- */
			err_val = EXER_FILEFIN;

			}
#ifndef	PROLOGUE
#ifndef	DOS
		/* Since err_val will have been set by prologue and DOS */
		/* ---------------------------------------------------- */
		else	err_val = EXER_ADRSECT;
#endif
#endif
		/* Return the prepared ERROR Status */
		/* -------------------------------- */
		return(err_val); 

					/* ---------------------------- */
		case PRL_DVWRIM	:	/* WRITE DEVICE NON-BUFFERISED 	*/
		case PRL_DVWRBF	:	/* WRITE DEVICE BUFFERISED	*/
		case PRL_WRSECT	:	/* WRITE SECTORISED FILE	*/
		case PRL_WRBLOC :	/* WRITE BLOCK 			*/
					/* ---------------------------- */

#ifdef PRL_SF
					/* ---------------------------- */
		default		:	/* POSSIBLE TTY BSC X25 CODES   */
					/* ---------------------------- */
#endif

		/* Attempt requested Write operation */
		/* --------------------------------- */
		if ((ret_cod = write(fidreel,workptr1,worklen1)) != worklen1) {

#ifndef PROLOGUE
			/* CONVERT ERROR VALUE to PROLOGUE type ERROR */
			/* ------------------------------------------ */
			traitfilerror(-1,errno);
#endif
			/* RETURN ERROR VALUE */
			/* ------------------ */
			return(errno);
			}
		else	/* SUCCESFUL WRITE OPERATION */
			/* ------------------------- */
			return(0);

		}

/* ******************************************************************** */
/*		SI , I.S.A.M. , RMS interface				*/
/* ******************************************************************** */
case NGF_SI :

#ifdef ABALSI

	/* Reset Option to ZERO */
	/* -------------------- */
	option = 0;

	/* Select Requested operation */
	/* -------------------------- */
	switch ( ngfcode ) {

	case    PRL_CHAR   : return(ngf_infos());

#ifndef PROLOGUE
#ifndef	DOS

	case	PRL_WRZC   : if ((ret_cod = si_writezc(fidreel,fidname,workptr1,worklen1)) != MOINS_UN)
					ret_cod = worklen1;
			     break;

	case	PRL_RDZCEX : option = 1;
	case	PRL_RDZC   : if ((ret_cod = si_readzc(fidreel,option,fidname,workptr1,worklen1)) != MOINS_UN)
					ret_cod = worklen1;
			     break;

#endif	/* ! DOS */
#endif	/* ! PRL */

#ifndef UNIX
#ifndef	VMS

	case	PRL_WRZC   : if ((ret_cod = si_writezc(fidreel,workptr1,worklen1)) != MOINS_UN)
					ret_cod = worklen1;
			     break;

	case	PRL_RDZCEX : option = 1;
	case	PRL_RDZC   : if ((ret_cod = si_readzc(fidreel,option,workptr1,worklen1)) != MOINS_UN)
					ret_cod = worklen1;
			     break;

#endif	/* ! VMS */
#endif	/* ! NIX */

	default		   : return(56);
	}

	/* Check for Errors and Buffer fill */
	/* -------------------------------- */
	if (ret_cod == MOINS_UN) 
		return(err_val);
	if ( ret_cod < worklen1 )
		memset((workptr1 + ret_cod),' ',(worklen1 - ret_cod));

	return(0);

#else	
	/* SI FUNCTIONS NOT AVAILABLE */
	/* -------------------------- */
	return(56);

	/* ------ */
#endif	/* ABALSI */
	/* ------ */

/* ******************************************************************** */
/*		SEQUENTIEL FILE ACCESS METHOD				*/
/* ******************************************************************** */

case NGF_SQ :

#ifdef ABALSQ

	/* If not REQUEST FOR CHARACTERISTICS */
	/* ---------------------------------- */
	if ( ngfcode != PRL_CHAR ) {

		/* Perform requested file function */
		/* ------------------------------- */
		ret_cod = sq_func(fidreel,workptr1,worklen1,ngfcode);

		if ( ret_cod == MOINS_UN )
			return(errno);
		else	return(0);
		}
	else	/* Perform Characteristics Function */
		/* -------------------------------- */
		return(ngf_infos());

#else	
	/* SEQUENTIEL ACCESS METHOD NOT AVAILABLE */
	/* -------------------------------------- */
	return(56);

	/* ------ */
#endif	/* ABALSQ */
	/* ------ */

	}

	/* FUNCTION NOT KNOWN */
	/* ------------------ */
	return(56);

}

#else	/* ABAL_TCPIP */

EXAWORD	sf_read_write()
{
	EXAWORD	ngfcode;
	EXAWORD	option;
	EXAWORD	ret_cod;

	/* If Error collecting operation Code Return Error */
	/* ----------------------------------------------- */
	if ( fargset(1) == SOFTERROR ) 
		return(err_val);

	/* Establish local and global Operation Code Value */
	/* ----------------------------------------------- */	
	simcbd = ngfcode = (EXAWORD) workval1;

	/* If Error collecting Buffer Return Error Value */
	/* --------------------------------------------- */
	if ( fargset((ngfcode & 0x0080) >> 7) == SOFTERROR) 
		return(err_val); 

	/* If Error collecting length Return Error Value */
	/* --------------------------------------------- */
	if ( fargset(2) == SOFTERROR ) 
		return(err_val);

	/* Determine whether to use length */
	/* ------------------------------- */
	if ( worktyp2 < 2 ) 
		worklen1 = workval2;

	/* Collect Sector/Message Value or RETURN ERROR */
	/* --------------------------------------------	*/
	if ( largset(3) == SOFTERROR ) 
		return(err_val);

	/* Select FILE ACCESS METHOD */
	/* ------------------------- */
	switch((fidperm & NGF_TYP)) {

/* ******************************************************************** */
/*		IPC MESSAGE COMMUNICATION FUNCTIONS			*/
/* ******************************************************************** */

	case NGF_CM  :

#ifdef ABALMSG

	/*	Convert from LSEEK value	*/
	/*	------------------------	*/
		hugeint /= BLOCK;

	/*	Perform IPC function and RETURN ERROR		*/
	/*	-------------------------------------		*/
		return( msgwork(ngfcode) );

#else

	/*	IPC MESSAGE OPTION NOT AVAILABLE	*/
	/*	--------------------------------	*/
		return(56);

	/* ------- */
#endif	/* ABALMSG */
	/* ------- */

/* ******************************************************************** */
/*		PRINTER INTERFACE HANDLING FUNCTIONS			*/
/* ******************************************************************** */

	case NGF_IM  :

#ifdef	ABAL14

	/*	Eliminate all operations except WRITE 	*/
	/*	-------------------------------------	*/
		if (( ngfcode & 0x00FF ) != 0x00A0 )
			return((err_val = 56));

	/*	Establish Printer 			*/
	/*	-----------------			*/
		err_val = Establish_Printer();

	/* 	While no Error Perform Print output	*/
	/*	-----------------------------------	*/
		while ((err_val == 0) && (worklen1 > 0)) { 
			x_putch(*(workptr1++)); 
			worklen1--; 
			}

	/*	Return Error Status			*/
	/* 	-------------------			*/			
		return( err_val );

#else

	/*	PRINT WRITE OPTION NOT AVAILABLE	*/
	/*	--------------------------------	*/
		return(56);

	/* ------ */
#endif	/* ABAL14 */
	/* ------ */

/* ******************************************************************** */
/*		RAW DEVICE (DISK/DISKETTE) FUNCTIONS			*/
/* ******************************************************************** */
	case NGF_DV  :

#ifndef UNIX
#ifndef VMS

	/* 	Perform RAW DEVICE function and Return Error Status 	*/
	/* 	---------------------------------------------------	*/
	return(io_func(fidreel,ngfcode, workptr1,worklen1,(EXALONG) (hugeint / BLOCK)));

#endif
#endif

/* ******************************************************************** */
/*		GRAPHICAL INTERFACE SCREEN FUNCTIONS			*/
/* ******************************************************************** */

	case NGF_GR  :

/* ******************************************************************** */
/*		SECTORISED STANDARD FILE FUNCTIONS			*/
/* ******************************************************************** */

case NGF_IO  :

	/* Perform Primary Function Group Selection */
	/* ---------------------------------------- */
	switch ( ngfcode ) {

					/* ---------------------------- */
		case PRL_CHAR	:	/* REQUEST FOR CHARACTERISTICS	*/
					/* ---------------------------- */

			/* Perform Function and Return Status */
			/* ---------------------------------- */
			return( ngf_infos() );

					/* ---------------------------- */
		case PRL_RDBLOC :	/* READ  BLOCK 			*/
			return( bloc_read( fidreel, workptr1, worklen1, (hugeint / BLOCK) ) );

		case PRL_WRBLOC :	/* WRITE BLOCK 			*/
					/* ---------------------------- */
			return( bloc_write( fidreel, workptr1, worklen1, (hugeint / BLOCK) ) );

					/* ---------------------------- */
		case PRL_DVRDIM	:	/* READ  DEVICE NON-BUFFERISED 	*/
		case PRL_DVRDBF	:	/* READ  DEVICE BUFFERISED	*/
		case PRL_RDSECT	:	/* READ  SECTORISED FILE	*/
			return( ad_read( fidreel, workptr1, worklen1, (hugeint / BLOCK) ) );

		case PRL_DVWRIM	:	/* WRITE DEVICE NON-BUFFERISED 	*/
		case PRL_DVWRBF	:	/* WRITE DEVICE BUFFERISED	*/
		case PRL_WRSECT	:	/* WRITE SECTORISED FILE	*/
					/* ---------------------------- */
			return( ad_write( fidreel, workptr1, worklen1, (hugeint / BLOCK) ) );

		default :		/* ALL OTHER CODES		*/
					/* ---------------		*/
#ifndef PRL_SF
			return(56);
#else

			/* Attempt to seek to Sector offset or RETURN ERROR */
			/* ------------------------------------------------ */
			if ( lseek(fidreel,hugeint,SEEK_SET) == -1L )
				return((err_val = EXER_ADRSECT));
			break;

	/* -------- */
#endif	/* ! PRL_SF */
	/* -------- */

		}

/* ******************************************************************** */
/*		SI , I.S.A.M. , RMS interface				*/
/* ******************************************************************** */
case NGF_SI :

#ifdef ABALSI

	/* Reset Option to ZERO */
	/* -------------------- */
	option = 0;

	/* Select Requested operation */
	/* -------------------------- */
	switch ( ngfcode ) {

	case    PRL_CHAR   : return(ngf_infos());

#ifndef PROLOGUE
#ifndef	DOS

	case	PRL_WRZC   : if ((ret_cod = si_writezc(fidreel,fidname,workptr1,worklen1)) != MOINS_UN)
					ret_cod = worklen1;
			     break;

	case	PRL_RDZCEX : option = 1;
	case	PRL_RDZC   : if ((ret_cod = si_readzc(fidreel,option,fidname,workptr1,worklen1)) != MOINS_UN)
					ret_cod = worklen1;
			     break;

#endif	/* ! DOS */
#endif	/* ! PRL */

#ifndef UNIX
#ifndef	VMS

	case	PRL_WRZC   : if ((ret_cod = si_writezc(fidreel,workptr1,worklen1)) != MOINS_UN)
					ret_cod = worklen1;
			     break;

	case	PRL_RDZCEX : option = 1;
	case	PRL_RDZC   : if ((ret_cod = si_readzc(fidreel,option,workptr1,worklen1)) != MOINS_UN)
					ret_cod = worklen1;
			     break;

#endif	/* ! VMS */
#endif	/* ! NIX */

	default		   : return(56);
	}

	/* Check for Errors and Buffer fill */
	/* -------------------------------- */
	if (ret_cod == MOINS_UN) 
		return(err_val);
	if ( ret_cod < worklen1 )
		memset((workptr1 + ret_cod),' ',(worklen1 - ret_cod));

	return(0);

#else	
	/* SI FUNCTIONS NOT AVAILABLE */
	/* -------------------------- */
	return(56);

	/* ------ */
#endif	/* ABALSI */
	/* ------ */

/* ******************************************************************** */
/*		SEQUENTIEL FILE ACCESS METHOD				*/
/* ******************************************************************** */

case NGF_SQ :

#ifdef ABALSQ

	/* If not REQUEST FOR CHARACTERISTICS */
	/* ---------------------------------- */
	if ( ngfcode != PRL_CHAR ) {

		/* Perform requested file function */
		/* ------------------------------- */
		ret_cod = sq_func(fidreel,workptr1,worklen1,ngfcode);

		if ( ret_cod == MOINS_UN )
			return(errno);
		else	return(0);
		}
	else	/* Perform Characteristics Function */
		/* -------------------------------- */
		return(ngf_infos());

#else	
	/* SEQUENTIEL ACCESS METHOD NOT AVAILABLE */
	/* -------------------------------------- */
	return(56);

	/* ------ */
#endif	/* ABALSQ */
	/* ------ */

	}

	/* FUNCTION NOT KNOWN */
	/* ------------------ */
	return(56);

}


#endif

#endif	/* ABAL_CRITERIA */


	/* ------- */
#endif	/* EXRDWRC */
	/* ------- */

