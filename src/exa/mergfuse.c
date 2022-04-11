/*	M E R G E F U S E ( )
 *	---------------------
 *	This function performs user library merging for the
 *	CHAIN operation of ABAL
 *	
 *	Exemple :	
 *		Program1	UDF 0	= BIBGR - X	=>	0
 *				UDF 1   = BIBWW - X	=>	1
 *
 *		Program2	UDF 0	= BIBMM - X	=>	0
 *				UDF 1	= BIBGR - X	=>	1
 *
 *	After the Chain BIBWW will be liberated, BIBMM will be
 *	initialised , and BIBGR will be merge relocated
 *	::::						=>	1
 *							=>	0
 *
 */

EXAWORD	MergeFuse( )
{
	BPTR	wptr;	/* Pointeur sur Table du T-Code */
	EXAWORD	wdex;	/* Offset into Table 		*/
	BPTR	tptr;	/* Temporary Name Pointer	*/
	EXAWORD	x,l,z;
	struct fusework	PTR 	lfusebase;
	EXAWORD		lfusectrl;
	EXAWORD	fusedex;

#ifdef	DEBUGGER

	EXAWORD	debug_flag;	/* Debug switch for ASFUN	*/	
	
	/* Must test for normal PROGRAM CHAIN or EXADB 'G' Function */
	/* -------------------------------------------------------- */	
	if ( ExadbGoFunction != 0 ) {

		/* Reset GO FUNCTION FLAG */
		/* ---------------------- */
		ExadbGoFunction = 0;

		/* Liberate all Dynamic Libraries */
		/* ------------------------------ */
		FuseCount = LibFuse(FuseBase, FuseCount );

		/* Re-Install Dynamic libraries and Return */
		/* --------------------------------------- */
		return ( InitFuse() );

		}

	/* -------- */
#endif	/* DEBUGGER */
	/* -------- */

	/* Ensure Program has User Libraries to Merge */
	/* ------------------------------------------ */
	if (FuseBase == (struct fusework PTR) 0)
		return( InitFuse() );

	/* -------------------------------------- */
	/* PERFORM PROGRAM CHAIN : MERGE RUN_TIME */
	/* -------------------------------------- */

	/* Allocate Temporary storage buffer */
	/* --------------------------------- */
	if ((wptr = (BPTR) allocate((lng_usr * TCODEBLOCK))) == (BPTR) 0 ) {
		FuseCount = LibFuse( FuseBase,FuseCount );
		errno = 27; return(MOINS_UN);
		}

	/* Read in the function Table Sectors */
	/* ---------------------------------- */
	if ( SectRead(TcodeFileHandle,(BPTR) wptr , (lng_usr * TCODEBLOCK) , adr_usr ) == MOINS_UN ) {
		FuseCount = LibFuse( FuseBase,FuseCount );
		liberate( wptr ); 
		return( MOINS_UN );
		}

	/* Collect Function Count */
	/* ---------------------- */
	lfusectrl = Tcodeword (( (BPTR) wptr ) );

	/* Allocate Function Table */
	/* ----------------------- */
	if ((lfusebase = (struct fusework PTR) allocate( (sizeof(struct fusework) * lfusectrl ))) == (struct fusework PTR) 0) {
		FuseCount = LibFuse(FuseBase, FuseCount );
		liberate( wptr );
		errno = 27; 
		return(MOINS_UN);
		}

	/* Initialise Table des fonctions Utilisateur */
	/* ------------------------------------------ */
	for ( x = 0, wdex = WORDSIZE; x < lfusectrl; x++ ) {

		/* Collect and control Length of User Library Name */
		/* ----------------------------------------------- */
		if ((l = (strlen( (BPTR) (wptr + wdex) ) + 1)) > 1 ) {

			/* Allocate the Name Storage Pointer */
			/* --------------------------------- */
			if ((tptr = (BPTR) allocate( l )) == (BPTR) 0 ) {
				FuseCount = LibFuse( FuseBase,FuseCount );
				FuseBase = lfusebase;
				lfusectrl = LibFuse(FuseBase, x );
				liberate( wptr );
				errno = 27;
				return(MOINS_UN);
				}

			/* Store the Name to Table Zone */
			/* ---------------------------- */
			(VOID) memcpy( (BPTR) tptr , (BPTR) (wptr+wdex) , (USINT) l );

			/* Check for Function already loaded */
			/* --------------------------------- */ 
			for ( z = 0; z < FuseCount; z++ )
				if (( (*(FuseBase+z)).fusename != (BPTR) 0)
				&&  ( FuseChck( tptr , (*(FuseBase+z)).fusename ) == 0 ))
					break;

			/* If Function already Loaded */
			/* -------------------------- */
			if ( z < FuseCount ) {

				liberate( tptr );

				/* Recopie the entry ID */
				/* -------------------- */
/* #IJM 27/12/01 Begin */
				(*(lfusebase + x)).fuseload = (*(FuseBase + z)).fuseload;
				(*(lfusebase + x)).fuselock = MOINS_UN;
/* #IJM 27/12/01 End */
				(*(lfusebase + x )).fusename = (*(FuseBase + z)).fusename;
				(*(lfusebase + x )).fuseprog = (*(FuseBase + z)).fuseprog;
				(*(lfusebase + x )).fusentry = (*(FuseBase + z)).fusentry;
				(*(lfusebase + x )).fusedesc = (*(FuseBase + z)).fusedesc;
				(*(lfusebase + x )).fusetype = (*(FuseBase + z)).fusetype;

				/* Signal False to Avoid DSAC and Reset */
				/* ------------------------------------ */
				(*(FuseBase + z)).fusename = (BPTR) 0;
				(*(FuseBase + z)).fuseprog = (BPTR) 0;
				(*(FuseBase + z)).fusentry = MOINS_UN;
				(*(FuseBase + z)).fusedesc = (LDF_BDA PTR) 0;
				(*(FuseBase + z)).fusetype = 0;
				}
			else	{



				(*(lfusebase + x)).fusename = tptr;
				(*(lfusebase + x)).fuseprog = (BPTR) 0;
				(*(lfusebase + x )).fusentry = MOINS_UN;
				(*(lfusebase + x )).fusetype = 0;
				(*(lfusebase + x)).fuselock = MOINS_UN;

				/* Indicate Init Needed */
				/* -------------------- */
				if (((*(lfusebase+x)).fusedesc = (LDF_BDA PTR) allocate(sizeof(LDF_BDA))) == (LDF_BDA PTR) 0) {
					FuseCount = LibFuse( FuseBase,FuseCount );
					FuseBase = lfusebase;
					lfusectrl = LibFuse( FuseBase,x );
					liberate( wptr );
					errno = 27;
					return(MOINS_UN);
					}

				}
			}
		else	{



			(*(lfusebase + x)).fusentry = MOINS_UN;
			(*(lfusebase + x)).fuselock = MOINS_UN;
			(*(lfusebase + x)).fuseprog = (BPTR) 0;
			(*(lfusebase + x)).fusename = (BPTR) 0;
			(*(lfusebase + x)).fusedesc = (LDF_BDA PTR) 0;
			(*(lfusebase + x)).fusetype = 0;
			}
		wdex += l;
		(*(lfusebase + x)).fusefunc = Tcodeword((wptr + wdex));
		wdex += FUSE_RESERVE;
		}
	
	/* Liberate Old Function Table */
	/* --------------------------- */
	for ( x=0; x < FuseCount; x++ ) {

		/* If Function Needs liberation */
		/* ---------------------------- */	
		if ((*(FuseBase + x)).fusentry != MOINS_UN ) {

			/* If Library performed CICO redirection */
			/* ------------------------------------- */
			switch ( (*(FuseBase + x)).fusetype ) {

			case _BDA_ASFUN12 :
#ifdef	DEBUGGER
				/* Remove ASFUN Debug Window */
				/* ------------------------- */
				asfun_wsup();
#endif	
			case _BDA_ZABAL   :	
			case _BDA_ASFUN11 :
			case _BDA_REDIRECT:
				/* Perform Request to de-re-direct */
				/* ------------------------------- */
				(VOID) x_redir(0,3,(*(FuseBase + x)).fusedesc,sizeof(LDF_BDA));

				/* Remove EXADB window LINK */
				/* ------------------------ */
#ifdef	DEBUGGER
				AsfunLibId = MOINS_UN;
#endif	/* DEBUGGER */

				}

			/* Allow the library to liberate it's self */
			/* --------------------------------------- */
			(VOID) FinRunTime( (*(FuseBase+x)).fusentry );
			}

		/* Liberate the Structure if Valid */
		/* ------------------------------- */
		if ( (*(FuseBase+x)).fusedesc != (LDF_BDA PTR) 0) {
			liberate( (*(FuseBase+x)).fusedesc );
			}

		/* If Function Has a Name */
		/* ---------------------- */
		if ( (*(FuseBase+x)).fusename != (BPTR) 0) {
			liberate( (*(FuseBase+x)).fusename );
			}
		/* If Function Has a Name */
		/* ---------------------- */
		if ( (*(FuseBase+x)).fuseprog != (BPTR) 0) {
			liberate( (*(FuseBase+x)).fuseprog );
			}

		}

	/* Liberate File Work Zone and old Table */
	/* ------------------------------------- */
	liberate(FuseBase); liberate( wptr );

	/* Establish Function Controllers */
	/* ------------------------------ */
	FuseBase = lfusebase;
	FuseCount = lfusectrl;

/* This definition had been added to allow Staff Screener Dynamic Library to be Differed loading when chain merge underway */
/* In fact we were a bit heavy handed so the loop through the library table has been re-activated but the actual loading   */
/* itself is now shunted out to be performed when required, ie at the first function call. In order to correct the bug     */
/* encountered when a program(asfun,other) chains to a program(asfun,bimath,other) and back to a program(asfun,other)      */
/* the redirected overload that would have been performed by the previous version(prior to staffscreener) of this function */
/* is now stored into the LDF table to be used when the library is loaded upon first function call (wow ! no shit! )	   */

	/* Ensure all Libraries are initialised */
	/* ------------------------------------ */	
	for ( x=0, lfusectrl = 0; x < FuseCount; x++ ) {

		/* MOINS_UN means needs Init */
		/* ------------------------- */
		if (( (*(FuseBase + x)).fusentry == MOINS_UN )
			/* If Filename is valid */
			/* -------------------- */
		&&  ( (*(FuseBase + x)).fusename != (BPTR) 0 )) {

			/* Search for a liberate Library Code */
			/* ------------------------------ */
			for ( z= 0; z < FuseCount; z++ ) {

				/* If Entry already allocated */
				/* -------------------------- */
				if (( (*(FuseBase + z)).fusentry == lfusectrl )
				||  ( (*(FuseBase + z)).fuseload == lfusectrl )) {
					z = 0; 
					lfusectrl++;
					}
				}			

#ifdef	before_27122001_ijm
			/* Attempt to load dynamic library */
			/* ------------------------------- */
			if ( load_dynamic_library( FuseBase,x, 0, lfusectrl++ ) == SOFTERROR ) {

				/* Abandon due to Error */
				/* -------------------- */
				FuseCount = LibFuse(FuseBase, x ); 
				liberate( wptr );
				errno = 44;  
				return(MOINS_UN);

				}
#else
/* #IJM 27/12/01 Begin */
			/* This must be stored for use by the differed loading mechanism */
			/* ------------------------------------------------------------- */
			(*(FuseBase + x)).fuseload = lfusectrl++;
/* #IJM 27/12/01 End */
#endif

			}
		}

	return(0);

}


