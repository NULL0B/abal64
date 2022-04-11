/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1996 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXFLOPPY - C				*/
/*		Version :	1.2c					*/
/*		Date 	:	22/02/1996				*/
/*									*/
/* 22/02/96 : relais differencie entre NT et 95				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	Gestion des lecteurs de disquettes 1.2 Mo Sous Ms-Dos		*/
/*----------------------------------------------------------------------*/

#include "exngf.h"

#ifdef WIN32
#define UNDERWINNT	 	1
#define UNDERWIN95	 	2
WORD Win95orWinNT(void);
WORD floppy_io_winNT(WORD, WORD, BYTE *, WORD, WORD);
#endif

struct	bios_pram {
	EXAWORD	Secteur;
	EXAWORD	Indent;
	EXAWORD	Tracksize;
	EXAWORD	Trackmax;
	} Medium[4];

EXAWORD	io_open( device_name )
BPTR	device_name;
{
	/* Establish Diskette Parameters for BIOS Register Calculations */
	/* ------------------------------------------------------------ */

	/* 5 1/4 inch drives */
	/* ----------------- */

	/* 360 Kb Diskettes		1.2 Mb Diskettes	*/
	/* ----------------		----------------	*/
	Medium[0].Secteur   = 512;	Medium[1].Secteur   = 512;	
	Medium[0].Indent    = 2;	Medium[1].Indent    = 2;	
	Medium[0].Tracksize = 18;	Medium[1].Tracksize = 30;	
	Medium[0].Trackmax  = 39;	Medium[1].Trackmax  = 79;	


	/* 3 1/2 inch Drives */
	/* ----------------- */
	
	/* 720 Kb Diskettes		1.4 Mb Diskettes	*/
	/* ----------------		----------------	*/
	Medium[2].Secteur   = 512;	Medium[3].Secteur   = 512;	
	Medium[2].Indent    = 2;	Medium[3].Indent    = 2;	
	Medium[2].Tracksize = 18;	Medium[3].Tracksize = 36;	
	Medium[2].Trackmax  = 79;	Medium[3].Trackmax  = 79;

	/* Was previously  159 tracks for 1.44 */	

	/* Perform Low Level Open Routine */
	/* ------------------------------ */
	return(llio_open(device_name));

}

EXAWORD	io_func(did,dop,bptr,blen,logiq)
EXAWORD	did;		/* Diskette ID Code 1 -> 2 :: 'A' -> 'B'	*/
EXAWORD	dop;		/* Operation Code x40 x60, x80 xA0		*/ 
BPTR	bptr;		/* Transfer buffer				*/
EXAWORD	blen;		/* Length of Buffer				*/
EXALONG	logiq;		/* Logical Starting Sector	0 -> MaxSect	*/
{
	EXAWORD	RegAx;		/* AX Register for BIOS Call	*/
	EXAWORD	RegCx;		/* CX Register for BIOS Call	*/
	EXAWORD	RegDx;		/* DX Register for BIOS Call	*/
	BPTR	BiosBuf;	/* Buffer Pointer for BIOS Call	*/
	EXAWORD	Track,Head,Secteur,xlen;
	EXAWORD	raw_media;
	
	/* Select BIOS Function Code or Error if Illegal OP */
	/* ------------------------------------------------ */
	switch ( (dop & 0x00FF) )	{
		case 0x0040	:	/* Device Read			*/
		case 0x0044	:	/* Bufferised device Read	*/
		case 0x0060	:	/* File Read			*/
			RegAx = 0x0200; break;
		case 0x0080	:	/* Device Read			*/
		case 0x0084	:	/* Bufferised device Read	*/
		case 0x00A0	:	/* File Read			*/
			RegAx = 0x0300; break;
		default		:	/* All other codes illegal	*/
			err_val = errno = 56;
			return(MOINS_UN);
		}

#ifdef WIN32
	if (Win95orWinNT() == UNDERWINNT) {
		errno=0;
		err_val=floppy_io_winNT(did,RegAx,bptr,blen,logiq);
		if(err_val!=0){
			errno=err_val;
			return(MOINS_UN);
			}
		return (0);
		}
#endif


	/* Establish Drive Media 1.2Mo or 320Ko */
	/* ------------------------------------ */
	switch ( (raw_media = Media_Type( did )) ) {
		case 0x0081 :	/* 360 Ko Drive			*/
		case 0x0000 :	/* 48 tpi 360 Kb unestablished  */
		case 0x0001 :	/* 48 tpi 1.2 Mb unestablished  */
		case 0x0003 :	/* 48 tpi 360 Kb established    */
		case 0x0004 :	/* 48 tpi 1.2 Mb established    */

			/* 320 Kb Floppy Parameters */
			raw_media = 0; break;

		case 0x0082 :	/* 1.Mo Drive		       */
		case 0x0002 :	/* 96 tpi 1.2 Mb unestablished */
		case 0x0005 :	/* 96 tpi 1.2 Mb established   */ 

			/* 1.2 Mb Floppy Parameters */
			raw_media = 1; break;

		case 0x0083 :	/* 720 3 1/2 drive		*/
		case 0x0008 :	/* 3 1/2 inch PS type floppy	*/

			/* 720 Floppy parameters */
			raw_media = 2; break;

		case 0x0084 :	/* 1.44 Mo 3 1/2 Drive		*/

			/* 1.44 Mb Floppy Parameters	*/
			raw_media = 3; break;

		default	    :	/* All other Values ... Error   */
			errno = err_val = EXER_DEVFAIL;
			sprintf(SysLogBuffer, "Error: io_func failed: Unknown media, err_val=%d", err_val);
			ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
			return(MOINS_UN);
		}

	/* Allocate BIOS Buffer */
	/* -------------------- */
	if ((BiosBuf = (BPTR) allocate( Medium[raw_media].Secteur )) == (BPTR) 0 ) {
		err_val = errno = 27; return(err_val);
		}

	/* Adjust Logique towards Physique to avoid BOOTSTRAP */
	/* -------------------------------------------------- */
	logiq += Medium[raw_media].Indent;	errno = 0;

/* Check for Impaire Start Sector */
/* ------------------------------ */
if ((logiq & 1 ) != 0 ) { 

	logiq >>= 1;

	/* Calculate BIOS Register Values */
	/* ------------------------------ */
	Track 	= (EXAWORD) (logiq / ((EXALONG) Medium[raw_media].Tracksize) );
	Secteur	= (EXAWORD) ((logiq % ((EXALONG) Medium[raw_media].Tracksize)) + 1);
	if ( Secteur > (Medium[raw_media].Tracksize / 2)) 	{ Secteur -= (Medium[raw_media].Tracksize / 2); Head = 0x0100;	}
	else							{ Head = 0;			}
	if ( Track > Medium[raw_media].Trackmax ) {
		liberate(BiosBuf); err_val = errno = 04;  return(MOINS_UN); 
		}
	RegAx = ((RegAx & 0xFF00) | 1);
	RegDx = (did | Head); 
	RegCx = (Secteur | (Track << 8 ));

	/* Read Sector into Buffer */
	/* ----------------------- */
	if ((err_val = floppy_io((RegAx & 0x02FF),(BPTR) BiosBuf,RegCx,RegDx)) != 0) {
		liberate(BiosBuf); errno = err_val;  return(MOINS_UN); 
		}

	/* Calculate Transfer Length */
	/* ------------------------- */
	xlen = (blen > 256 ? 256 : blen);

	/* Perform Read and Write Operations */
	/* --------------------------------- */
	if ((RegAx & 0x0100) != 0 ) {

		/* Transfer Data to be written */
		/* --------------------------- */
		memcpy((BPTR) (BiosBuf+256),bptr,xlen); 

		/* Perform Write Operation via BIOS */
		/* -------------------------------- */
		if ((err_val = floppy_io(RegAx,(BPTR) BiosBuf,RegCx,RegDx)) != 0) {
			liberate(BiosBuf); errno = err_val;  return(MOINS_UN); 
			}
		}
	else	{
		/* Transfer in Data from Read operation */
		/* ------------------------------------ */
		memcpy(bptr,(BPTR) (BiosBuf+256),xlen); 
		}
	/* Adjust Sector and Buffer Control Infos */
	/* -------------------------------------- */
	logiq += 1; blen -= xlen;
	bptr += xlen;
	}
else	{
	logiq >>= 1;
	}		


/* Repeat Sectorised Operation */ 
/* --------------------------- */
while (	blen > 0 ) {

	/* Calculate BIOS Registers */
	/* ------------------------ */
	Track 	= (EXAWORD) (logiq / ((EXALONG) Medium[raw_media].Tracksize) );
	Secteur	= (EXAWORD) ((logiq % ((EXALONG) Medium[raw_media].Tracksize)) + 1);
	if ( Secteur > (Medium[raw_media].Tracksize / 2)) 	{ Secteur -= (Medium[raw_media].Tracksize / 2); Head = 0x0100;	}
	else							{ Head = 0;			}
	if ( Track > Medium[raw_media].Trackmax ) {
		liberate(BiosBuf); err_val = errno = 04;  return(MOINS_UN); 
		}
	RegAx = ((RegAx & 0xFF00) | 1);
	RegDx = (did | Head); 
	RegCx = (Secteur | (Track << 8 ));

	/* Check for Read Operation Required */
	/* --------------------------------- */
	if (( (RegAx & 0x0100) == 0 ) || ( blen < Medium[raw_media].Secteur )) {

		/* Perform diskette sector Read Now */
		/* -------------------------------- */
		if ((err_val = floppy_io((RegAx & 0x02FF),(BPTR) BiosBuf,RegCx,RegDx)) != 0) {
			liberate(BiosBuf); errno = err_val; return(MOINS_UN); 
			}
		}

	/* Perform Buffer Transfers */
	/* ------------------------ */
	xlen = (blen > Medium[raw_media].Secteur ? Medium[raw_media].Secteur : blen);

	/* Separate Read from Write Transfer */
	/* --------------------------------- */
	if ((RegAx & 0x0100) != 0) {

		/* Perform Data Write Transfer and BIOS OP */
		/* --------------------------------------- */
		memcpy(BiosBuf,bptr,xlen); 
		if ((err_val = floppy_io(RegAx,(BPTR) BiosBuf,RegCx,RegDx)) != 0) {
			liberate(BiosBuf); errno = err_val;  return(MOINS_UN); 
			}
		}
	else	{

		/* Transfer in Data Read from diskette */
		/* ----------------------------------- */
		memcpy(bptr,BiosBuf,xlen); 
		}
	logiq += 1; blen -= xlen;
	bptr += xlen;
	}

	liberate(BiosBuf);
	return(0);

}

