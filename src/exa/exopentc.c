/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1995 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXOPENTC.C  				*/
/*		Date 	:	22/10/1995				*/
/*		Version :	1.4c / 2.1d				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXOPENTC_C
#define	_EXOPENTC_C

#ifdef	MMAP_OPTIMISED
#include "exmmaptc.c"
#endif


EX_FILE_HANDLE OpenTcodeFile( BPTR filename )
{
	EX_FILE_HANDLE handle=EX_UNUSED_HANDLE;
	EXAWORD	worklen=worklen1;
	BPTR	workptr=workptr1;
	worklen1 = strlen((workptr1=filename));
	if (!(implicite_convert_mnemonics(1))) {
		worklen1=worklen;
		workptr1=workptr;
		return( EX_UNUSED_HANDLE );
		}
	else	{
		filename = workptr1;
		*(filename+worklen1) = 0;
		worklen1=worklen;
		workptr1=workptr;
		}
#ifdef	MMAP_OPTIMISED
	return( OpenMmapFile( filename ) );
#endif
#ifdef	ABAL_CRITERIA
	if ((handle = EeEad_open((BPTR) filename, 0, (WPTR) & err_val )) == 0) {
		handle = EX_UNUSED_HANDLE;
		errno  = err_val;
		}
#ifdef	CHECK_TCODE_FILE_HANDLE
	FFcopy_file_handle( handle );
#endif

#else	/* ! ABAL_CRITERIA */

#ifndef	ABAL_TCPIP

	/*	Test for file accessible	*/
	/*	------------------------	*/
	if ( Access((BPTR) filename ,0,0) == 0) { 

		/*	Open T-Code File Now		*/
		/*	--------------------		*/
#ifdef UNIX
		handle = open((BPTR) filename ,O_BINARY,0); 
#else
#ifdef	VMS_OPTIMISED
		handle = open((BPTR) filename, (UseVmsSection ? 0x0010 : 0));
#else
		handle = open((BPTR) filename ,0);
#endif
#endif

		}
	else	{
		/* Interprete Access error return */
		/* ------------------------------ */
		if ( errno == 44 ) { err_val = 44; }
		else		   { err_val = 40; }
		}

#ifdef	VMS_OPTIMISED
	if ((UseVmsSection ) && (handle != EX_UNUSED_HANDLE)) {
		MappedSection[0] = 0; MappedSection[1] = 0; 

		if ( vms$mapsection( MappedSection, handle ) != 0 ) {
			close( handle );
			return( EX_UNUSED_HANDLE );
			}

		}
#endif

#else	/* ABAL_TCPIP */

	/* The TCPIP interface performs access/read operation */
	/* -------------------------------------------------- */
	handle = ad_open( (BPTR) filename, 0 ) );

#endif	/* ABAL_TCPIP */

#endif	/* ABAL_CRITERIA */

	/* Return Error or Handle */
	/* ---------------------- */
	return( handle );

}

#endif	/* _EXOPENTC_C */
	/* ----------- */

