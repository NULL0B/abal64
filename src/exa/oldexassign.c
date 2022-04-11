/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXASSIGN.C				*/
/*		Version :	1.4c / 2.1d                       	*/
/*		Date 	:	11/04/1997				*/
/*									*/
/*----------------------------------------------------------------------*/
/* Mises a jour :
 * ------------
 *	11/04/97 : Coorection bug Find des AGF (A.M.)
 *
 */

#ifndef	_EXASSIGN_C
#define	_EXASSIGN_C

#ifdef PROLOGUE
#define ASSIGN_NO_ANFC
#endif

#ifdef WIN32
/* ATTENTION :si vous modifiez FICBUFFLEN penser
 * ----------    aussi a le modifier dans exothwin.h !!!! 
 * AM110497
 */
#define	FICBUFFLEN		276
#endif

#ifdef PROLOGUE
struct	prologue_assign	{
	EXAWORD	limit;
	BPTR	storage;
	} PrlAssign;
#endif

EXAWORD	initialise_assign_allocation( nombre, unitsize )
EXAWORD	nombre;
EXAWORD	unitsize;
{
#ifdef	PROLOGUE_SLOW
	if ((PrlAssign.storage = (BPTR) allocate((nombre+1)*unitsize)) == (BPTR) 0) {
		err_val = 27;
		return( SOFTERROR );
		}
	PrlAssign.limit  = unitsize;
#endif
	return( GOODRESULT );
}

void	liberate_assign_allocation()
{
#ifdef	PROLOGUE_SLOW
	if ( PrlAssign.storage != (BPTR) 0 ) {
		liberate( PrlAssign.storage );
		PrlAssign.storage = (BPTR) 0;
		}
#endif
	return;
}

void	liberate_for_assign( nptr ) 
BPTR	nptr;
{
#ifdef	PROLOGUE_SLOW
	EXAWORD	indent;
	EXAWORD	temp;

	if ((indent = selector_check( nptr, PrlAssign.storage )) == 0)
		return;
#endif
	liberate( nptr );
	return;
}

BPTR	allocate_for_assign( fnlen, handle )
EXAWORD	fnlen;
EXAWORD	handle;
{
#ifdef PROLOGUE_SLOW
	if ( fnlen < PrlAssign.limit )
		return((BPTR) (PrlAssign.storage + ((handle-1)  * PrlAssign.limit)) );
#endif
	return( allocate( fnlen ) );
}


/*
 *	S E T N A M E ( )
 *	-----------------
 *	Allocates Filename storage zone, transfers filename string
 *	and ensures correct termination W.R.T. Operating systeme
 *	requirements.
 */

extern	EXAWORD	Anfc_Mode;

#ifdef	LINUX_MNEMONICS
/* Workzone used for the substitution of mnemonic values by env values */
EXABYTE	mnemzone[1024];	
#endif

EXAWORD	get_assign_event() { return( Anfc_Mode ); }
VOID	set_assign_event(EXAWORD v) { Anfc_Mode = v; return; }

EXAWORD	convert_mnemonics(EXAWORD workset)
{
	BPTR	workptr;
	EXAWORD	worklen;
	EXAWORD	z;
#ifdef	LINUX_MNEMONICS
	EXAWORD	mz=0;
	BPTR	mnemptr=(BPTR) 0;
#endif

	switch ( workset ) {
		case	0 :
		case	1 : workptr = workptr1; worklen = worklen1; break;
		case	2 : workptr = workptr2; worklen = worklen2; break;
		case	3 : workptr = workptr3; worklen = worklen3; break;
		default	  :
			err_val = 999;
			return( SOFTERROR );
		}

	/* -------------------------------- */
	/* Test for Auto Convertor Required */
	/* -------------------------------- */
	if ( Anfc_Mode != 0 ) {

		/*	If Automatic File Conversions Required		*/
		/*	--------------------------------------		*/
		for ( z = 0; z < worklen; z++ ) {
			switch ( Anfc_Mode & 3 ) {
				case 1	:	/* Convert to Upper */
						/* ---------------- */
					*(workptr + z) = toupper( (*(workptr+z)));
					break;
				case 2  :	/* Convert to Lower */
						/* ---------------- */
					*(workptr + z) = tolower( (*(workptr+z)));
					break;
				default : break;
				}
			}
#ifdef	LINUX_MNEMONICS

		/* Check for Mnmeonics Conversion */
		/* ------------------------------ */
		if ( Anfc_Mode & 8 ) {
			z = *(workptr+2);
			/* Detect Numeric Figure as third character */
			/* ---------------------------------------- */
			if ((z >= '0') && (z <= '9')) {

				/* Detect Ressource Separator */
				/* -------------------------- */
				z = *(workptr+3);
				if (( z == '.') || ( z == '/' )) {

					/*terminate and attempt to locate ENV */
					/* ---------------------------------- */
					*(workptr+3) = 0;
					if (!(mnemptr = getenv( workptr ))) {
						/* unknown so leave it alone */
						/* ------------------------- */
						*(workptr+3) = z;
						}
					else	{
						/* Found a substitution */
						/* -------------------- */
						strcpy(mnemzone,mnemptr);
						if ( *(workptr+4) == '/' )
							z = 4;
						else 	{
							if ( z != '/' )
								z = '/';
							*(workptr+3) = z;
							z = 3;
							}
						for (mz=strlen(mnemzone); z < worklen; z++,mz++ )
							mnemzone[mz] = *(workptr+z);
						worklen = mz;
						workptr = mnemzone;
						}
					}
				} 
			}
		for (z=0; z < worklen; z++ )
			if (*(workptr+z) == 0x005C ) /* is it backslash */
				*(workptr+z) = '/';  /* make it slash   */
#endif
		}
	switch ( workset ) {
		case	0 :
		case	1 : workptr1 = workptr; worklen1 = worklen; break;
		case	2 : workptr2 = workptr; worklen2 = worklen; break;
		case	3 : workptr3 = workptr; worklen3 = worklen; break;
		default	  :
			err_val = 999;
			return( SOFTERROR );
		}

	return( GOODRESULT );
}

EXAWORD setname()
{
	EXAWORD	z;
	BPTR	nptr;
	EXAWORD	keepall;
	if ( worktyp1 != VARB_STR )	 { 
		err_val = EXER_SYNTAX; 
		return(SOFTERROR);
		}
	while (( *workptr1 == IO_ESP ) && ( worklen1 > 0 )) { 
		workptr1++; worklen1--; 
		} 
	if ( worklen1 == 0 ) { 
		err_val = EXER_SYNTAX; 
		return(SOFTERROR); 
		}
#ifdef WIN32
	if ((worklen1 = lenuzend(workptr1,worklen1)) == 0) {
#else
	if ((worklen1 = lenuze(workptr1,worklen1)) == 0) {
#endif
		err_val = EXER_SYNTAX; 
		return(SOFTERROR); 
		}
	else if ( convert_mnemonics(1) != GOODRESULT )
		return( SOFTERROR );

	/* Allocate Permanate Storage Zone */
	/* ------------------------------- */
	if((nptr = (BPTR) allocate_for_assign((USINT) (worklen1+6),lfh)) == (BPTR) 0) {
		err_val = EXER_MEMFULL; 
		return(SOFTERROR); 
		}
	fidname = nptr; keepall = 0;
	while ( worklen1 > 0 ) {
		switch ( *workptr1 ) {
#ifndef WIN32
			case ' ' : if ( keepall == 1 ) 
					break; 
#endif
			case 0   : *(nptr++) = FILETERM; 
				   worklen1 = 0; continue;
			case '(' : keepall = 1; break;
			case ')' : keepall = 0; break;
			}
		*(nptr++) = *(workptr1++); 
		worklen1--;
		}
	/* Check for Right Bracket Not yet Found */
	/* ------------------------------------- */
	if ( keepall == 1 ) {
		liberate_for_assign( fidname );
		err_val = EXER_SYNTAX; 
		fidname = (BPTR) 0;
		return(SOFTERROR); 
		}

	/* Ok No Syntax Problems */
	/* --------------------- */
	*(nptr++) = FILETERM;
	*(nptr++) = (EXABYTE) 0;
	return(1);
}


EXAWORD	check_implicite_join_file( jptr )
BPTR	jptr;
{
	EXAWORD	l;

	if (((l = fn_parser( (BPTR) jptr, (BPTR) askbuf, 0x0007 )) == 0)
	&&  ((l = fn_parser( (BPTR) fidname, (BPTR) askbuf, 0x0007 )) != 0)) {
		l += fn_parser((BPTR) jptr, (BPTR) (& askbuf[l]), 0x0078 );
		return( l );
		}
	else	return( 0 );
}

EXAWORD	check_implicite_base_file()
{
	EXAWORD	l;

	/* Check for implicite base file with no path device or network infos */
	/* ------------------------------------------------------------------ */
	if (((l = fn_parser( (BPTR) fidname, (BPTR) askbuf, 0x0007 )) == 0)
	&&  ((l = fn_parser( (BPTR) (*(AssignTable + fidbd)).direcp, (BPTR) askbuf, 0x0007 )) != 0)) {
		l += fn_parser((BPTR) fidname, (BPTR) (& askbuf[l]), 0x0078 );
		liberate_for_assign( fidname );
		askbuf[l++] = ' ';
		askbuf[l] = 0;

		/* Allocate Permanate Storage Zone */
		/* ------------------------------- */
		if((fidname = (BPTR) allocate_for_assign((USINT) (strlen((BPTR) askbuf)+6),lfh)) == (BPTR) 0) {
			err_val = EXER_MEMFULL; 
			return(SOFTERROR); 
			}
		memcpy( (BPTR) fidname, (BPTR) askbuf, strlen(askbuf)+1 );
		}
	return(GOODRESULT);

}


/*
 *	S F _ A S S ( )
 *	---------------
 *	Voir EXSF-DOC
 */

EXAWORD	assign_failure( error_value )
EXAWORD	error_value;
{
	freefich();
	return( error_value );
}

#ifdef ASSIGN_NO_ANFC
BPTR	_DV_CTRL=(BPTR) "0_NO_CTRL";
				/* 0_NO_CTRL	avec ANFC ctrl */
				/* 1_NO_CTRL	sans ANFC ctrl */				

EXAWORD	file_or_ressource()
{
	switch ( frsplit(fidname) ) {
		case 0  :	
			/* A Ressource name */
			/* ---------------- */
			switch ( (fidperm & NGF_TYP) ) {
				case NGF_SQ   :
				case NGF_SI   :
				case NGF_MC   :
				case NGF_BD   :
				case NGF_MCBD :

					/* These access methods fail */
					/* ------------------------- */
					return(assign_failure((err_val = 119)));
	
				default       :
	
					/* Convert to Device Type */
					/* ---------------------- */
					fidperm |= NGF_DV;
	
				}

		case 1  :	/* A file name */
				/* ----------- */
				break;
		default : return(assign_failure(errno));
		}
	return( 0 );
}
#endif


EXAWORD sf_assign()
{
	EXAWORD	dbperm;
	EX_FILE_HANDLE hldlog;
	EX_FILE_HANDLE tmplog;
	EXAWORD	dblinkid;
#ifdef ASSIGN_NO_ANFC
	EXAWORD	lerrno;
	BPTR	lfidnom;
#endif

#ifndef UNIX
#ifndef VMS
	EXAWORD	frsplit(BPTR); /* Prototype of Amenesik / Sologic Ressource / File */
#endif
#endif
	/* Avoid RE-ASSIGN of Current Tcode */
	/* -------------------------------- */
	if ( lfh == 0 )
		return( 56 );

	/* Liberate Table entry if needed */
	/* ------------------------------ */
	if ( fidperm & ASS_NAME_VALID ) 
		(VOID) freefich();

	/* Collect and establish File name pointer */
	/* --------------------------------------- */
	if ( fargset(1) == SOFTERROR )  
		return(razfich(err_val));

	if ( setname()  == SOFTERROR ) 	
		return(razfich(err_val));

	/* Collect and establish File permissions  */
	/* --------------------------------------  */
	if ( fargset(1) == SOFTERROR ) 	
		return(assign_failure(err_val));

	/* Establish File Permissions WORDSIZE */
	/* ------------------------------- */
	fidperm = ((((EXAWORD) workval1) & 0x00FF) | ASS_NAME_VALID);

	/* Test for ASSIGN ACCESS METHOD Available */
	/* --------------------------------------- */
	if ((err_val = Available_Option((fidperm & NGF_TYP))) != 0)
		return(assign_failure(err_val));

#ifndef UNIX
#ifndef VMS

/*
 *	Ressource ou Fichier ?
 *	----------------------
 *	Due to the different actions to be performed (eg READ=1,/40 Disque  )
 *						     (.. READ=1,/60 Fichier )
 *	It is neccessary to separate the Ressource I.D mnemonics from
 *	the real file names using the special device / file separator
 */
	if ((fidperm & NGF_TYP) != NGF_IM) {

#ifdef ASSIGN_NO_ANFC
		if ( *_DV_CTRL != '1' ) {
			if ((lerrno = file_or_ressource()) != 0)
				return( lerrno );
			}
		else	{
			if (!(fidperm & NGF_TYP)) {
				for (lfidnom = (BPTR) fidname; *lfidnom != 0; lfidnom++ )
					if (( *lfidnom == '(' )
					&&  (( *(lfidnom+1) == 'd' ) || ( *(lfidnom+1) == 'D'))
					&&  (( *(lfidnom+2) == 'v' ) || ( *(lfidnom+2) == 'V'))
					&&  (  *(lfidnom+3) == ')' )) {
						fidperm |= NGF_DV;
						*lfidnom = 0;
						break;
						}

				}		
			}
#else

		switch ( frsplit(fidname) ) {
			case 0  :	
				/* A Ressource name */
				/* ---------------- */
				switch ( (fidperm & NGF_TYP) ) {
					case NGF_SQ   :
					case NGF_SI   :
					case NGF_MC   :
					case NGF_BD   :
					case NGF_MCBD :

						/* These access methods fail */
						/* ------------------------- */
						return(assign_failure((err_val = 119)));
	
					default       :
	
						/* Convert to Device Type */
						/* ---------------------- */
						fidperm |= NGF_DV;
	
					}

			case 1  :	/* A file name */
					/* ----------- */
					break;
			default : return(assign_failure(errno));
			}
#endif
		}

#endif	/* PRL */
#endif	/* DOS */

#ifdef ABALMC
	/* Special treatement for MC and MCBD Files */
	/* ---------------------------------------- */
	if ((fidperm & (NGF_MC | NGF_DV))==NGF_MC) {

		/* Get KEY workzone buffer pointer */
		/* ------------------------------- */
		if ( fargset(1) == SOFTERROR ) { 
			/* If MCBD alors Error else MC sans Tampon */
			/* --------------------------------------- */
			if (fidperm & NGF_BD) 
				return(assign_failure(err_val));
			else	{ 
				worktyp1 = 0; workptr1 = (BPTR) 0;
				}
			}
		if ( workptr1 != (BPTR) 0 ) {	/* Got Something 	 */
			dblinkid = workval1;	/* Keep Possible Link ID */
			fidbuff = workptr1;	/* And Buffer Pointer	 */
			fidblen = worklen1;	/* And Buffer Length     */
			/* Get KEY workzone buffer Length  */
			/* ------------------------------  */
			if ( fargset(1) == SOFTERROR ) { 
				if (fidperm & NGF_BD) {
					fidbuff = (BPTR) 0;
					fidblen = 0;
					}
				}
			else	fidblen = (EXAWORD) workval1;
			}
		else	{
			fidbuff = (BPTR) 0;
			fidblen = 0;
			}

#ifdef ABALBD
		/* Check if the MC file is a DATA BASE FILE (BD | MC) */
		/* -------------------------------------------------- */
		if (fidperm & NGF_BD) {

			/* Get DataBase linkage Number */
			/* --------------------------- */
			if (( fidblen != 0 ) && ( fidbuff != (BPTR) 0)) {
				if ( fargset(1) == SOFTERROR ) 
					return(assign_failure(err_val));
				}
			else	workval1 = dblinkid;

			fidbd = (EXAWORD) workval1;
			/* Check for Incorrect DATA BASE linkage */
			/* ------------------------------------- */
			if ( fidbd == lfh ) 
				return(assign_failure(ABAL_NUMLOG116));

			/* Collect and Duplicate DATA BASE file permissions */
			/* ------------------------------------------------ */
			dbperm = (*(AssignTable + fidbd)).permf;

			/* Ensure the linkage is a DATA BASE entry */
			/* --------------------------------------- */
			if ((dbperm & NGF_TYP) != NGF_BD) 
				return(assign_failure(ABAL_NUMLOG116));

			/* Create permissions for this SUB file */
			/* ------------------------------------ */
			fidperm |= ( dbperm & 0x000F);

			/* Attempt to open the database if required */
			/* ---------------------------------------- */
			if ( (*(AssignTable + fidbd)).unlog == EX_UNUSED_HANDLE ) {

				/* Save current context and Collect DB context */
				/* ------------------------------------------- */
				if ((err_val = savefich()) != 0)
					return( err_val ); 
				dbperm = lfh; lfh = fidbd;
				if ((err_val = loadfich()) != 0)
					return( err_val ); 

				/* Attempt to open the DATA BASE now */
				/* --------------------------------- */
				(VOID) sf_open();

				/* Check for SUCCESS and save context if OK */
				/* ---------------------------------------- */
				if (((tmplog = fidreel) != EX_UNUSED_HANDLE) 
				&&  ((err_val = savefich()) != 0))
					return( err_val );

				/* Recover DATA BASE FILE context */
				/* ------------------------------ */
				lfh = dbperm; 
				if ((err_val = loadfich()) != 0)
					return( err_val );

				/* Check for DATA BASE SUCCESS : Else Error */
				/* ---------------------------------------- */
				if ( tmplog == EX_UNUSED_HANDLE )
					return(assign_failure(err_val));

				}

			/* Add this file to the list of DATA BASE files */
			/* -------------------------------------------- */
			(VOID) basefile(1);

			check_implicite_base_file();

			}

#endif	/* ABALBD */
		}
#endif	/* ABALMC */

#ifdef ABALBD

	/* Establish RECORD Management Zone for Pure BD files */
	/* -------------------------------------------------- */
	if (( fidperm & NGF_TYP ) == NGF_BD ) 
		return(makebase());

#endif	/* ABALBD */

	/* Establish Print Buffer for PRINTER Files (IM) */
	/* --------------------------------------------- */
	if (( fidperm & NGF_TYP ) == NGF_IM ) { 
		if ( fargset(1) != SOFTERROR ) 
			fidbuff = workptr1;
		else 	{
			if ( (fidbuff = (BPTR) allocate((USINT) IMPR_BUF)) == (BPTR) 0) 
				return( assign_failure(ABAL_MEMORY) );
			worklen1 = IMPR_BUF; 
			fidperm |= ASS_BUFF_VALID;
			}
		if ( fargset(2) != SOFTERROR ) 
			fidblen = workval2;
		else 	fidblen = worklen1;
		}
#ifdef ABALMSG
	/* Establish MSG File ID if MSG MODULE */
	/* ----------------------------------- */
	if (( fidperm & NGF_TYP ) == NGF_CM ) {
		fidbuff = (BPTR) 0;
		if ( fargset(1) != SOFTERROR ) 	
			fidblen = workval1;
		else	fidblen = 0; 	
		(VOID) fargset(1);	/* Ignore possible leng */
		return(0);
		}	
#endif	/* ABALMSG */

#ifndef PROLOGUE
#ifdef  ABALSQ
	/* SQ Buffer management for Non Amenesik / Sologic O.S. 's */
	/* --------------------------------------------- */
	if (( fidperm & NGF_TYP ) == NGF_SQ ) {
		/* Allocate Sector buffer for SQ Structure */
		/* --------------------------------------- */
#ifndef WIN32
		if ((fidbuff = (BPTR) allocate((USINT)  BLOCK )) == (BPTR) 0 ) 
#else
			/* AM110497 : Ajouter car pb avec le find */
		if ((fidbuff = (BPTR) allocate((USINT)  FICBUFFLEN )) == (BPTR) 0 ) 
#endif
			return(assign_failure( ABAL_MEMORY ));


		/* Set BUF FREE Flag bit */
		/* --------------------- */
		fidperm |= ASS_BUFF_VALID;
		}
#endif	/* ABALSQ */
#endif	/* ! PRL  */
	return(0);
}


#ifdef	ABAL21

EXAWORD	sf_name()
{
	EXAWORD	mode,xlen;
	EXAWORD	error_status;

	/* Collect Result Buffer Arguament */
	/* ------------------------------- */
	if ( fargset(0) == SOFTERROR )
		return( err_val );

	/* Collect Possible Buffer Length */
	/* ------------------------------ */
	if ( fargset(2) != SOFTERROR )
		worklen1 = workval2;

	/* Ensure Buffer is EXALONG enough for at least the Type */
	/* -------------------------------------------------- */
	if ( worklen1 < 2 )
		return( 30 );
	
	/* Establish FILE RIGHTS and NGF ACCESS METHOD */
	/* ------------------------------------------- */
	mode = ( fidperm & 0x00FF );
	xlen = 0;
	balputw( mode, workptr1 ); workptr1 += WORDSIZE; worklen1 -= WORDSIZE;
	
	/* Calculate Assigned Name Length */
	/* ------------------------------ */ 
	while (( *(fidname + xlen) != 0 ) && ( *(fidname + xlen) != 0x000D ))
 		xlen++;

	/* Check for Data Loss : ERROR 63 */
	/* ------------------------------ */
	if ( xlen > worklen1 ) {
		error_status = 63;
		xlen = worklen1;
		}
	else	error_status = 0;

	/* Transfer FileName to Result Buffer */
	/* ---------------------------------- */	
	if ( xlen > 0 )
		memcpy( workptr1, fidname, xlen ); 

	worklen1 -= xlen;

	/* Padd String With Spaces */
	/* ----------------------- */
	if ( worklen1 > 0 ) 
		memset( (workptr1 + xlen), ' ', worklen1 );

	return( error_status );
}

	/* ------ */
#endif	/* ABAL21 */
	/* ------ */

	/* ----------- */
#endif	/* _EXASSIGN_C */
	/* ----------- */
