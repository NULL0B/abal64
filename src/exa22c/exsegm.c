/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXSEGM - C				*/
/*		Version	:	1.4c / 2.1d				*/
/*		Date 	:	07/05/1996				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	Reference	:	EXSEGM - DOC				*/
/*----------------------------------------------------------------------*/

/*
 *	V E R I F T C O D E ( )
 *	-----------------------
 *	Checks the validity of current Tcode file handle
 *	for LDGO.SEG and RET.SEG which should implicitly
 *	reopen the current T-Code file if it has been
 *	closed due to a :
 *		CLOSE=0
 *	statement during program execution
 *
 */

int	VerifTcode()
{

	if ( TcodeFileHandle == EX_UNUSED_HANDLE ) {
		lfh = 0;

		if ((err_val = loadfich()) != 0)
			return( SOFTERROR );

		if ((fidreel = OpenTcodeFile((BPTR) fidname )) == EX_UNUSED_HANDLE) {
			return(SOFTERROR);
			}
		if ((err_val = savefich()) != 0)
			return( SOFTERROR );
		}
	return( 1 );
}


/*
 *	C o n t r o l F r e e ( pointer_pointer )
 *	-----------------------------------------
 *	Performs controlled liberation of possibly NUL pointers
 *	to Resident and Public zones in RET.SEG
 *
 */
 
VOID	ControlFree( ptrptr )
BPTR	SPTR ptrptr;
{
	if ( *ptrptr != (BPTR) 0 ) {
#ifdef	VMS_OPTIMISED
		if (!(UseVmsSection))
#endif
			free ( *ptrptr );
		*ptrptr = (BPTR) 0;
		}
	return;
}

VOID	ControlLiberate( ptrptr )
BPTR	SPTR ptrptr;
{
	if ( *ptrptr != (BPTR) 0 ) {
#ifdef	VMS_OPTIMISED
		if (!(UseVmsSection))
#endif
			liberate( *ptrptr );
		*ptrptr = (BPTR) 0;
		}
	return;
}

/* 
 *		Recherche Segment Table Entry		
 *		-----------------------------		
 *	Finds the segment table entry information for the required
 *	t-code segment.
 *
 *	Entry		:	Segment number
 *
 *	Exit		:	MOINS_UN	Erreur Segment not found
 *			:	! MOINS_UN	Pointer to table entry
 *
 *	Modifies	:	Nothing
 *
 *	External	:	TcodeSegmentTable
 *
 */

EXAWORD	seg_find(SegmentId)
EXAWORD SegmentId;
{
	
	return( ((Overlay_Map[ SegmentId ] != 0xFFFF) ? Overlay_Map[ SegmentId ] : MOINS_UN ) );

}

/*
 *	K E E P _ S E G M ( )
 *	---------------------
 *
 *	This function creates and saves the current segment context.
 *	Segment ID, tcode pointer, On error control information,
 *	current Integer stack index and local data storage base.
 *
 */

EXAWORD	keep_segm(tcp)
EXAWORD	tcp;
{
	struct context SPTR sgcp;

	/* Check for Pointer Stack overflow */
	/* -------------------------------- */
	if ( mindex >= diezstk ) { 
		err_val = ABAL_GSB2MANY; 
		return(SOFTERROR); 
		}

	/* Attempt to allocate Segment Context */
	/* ----------------------------------- */
	if ((sgcp = (struct context SPTR) allocate(sizeof(struct context))) == (struct context SPTR) 0) {
		err_val = EXER_MEMFULL; 
		return(SOFTERROR); 
		}

	/* ATTENTION : bug TCC correction */
	/* ------------------------------ */
	if (( sicico & ERROR_TEST ) == 0)
		GlobalErrorTrap = (ERRORPTR) 0;

	/* Transfer current context to stacked context */
	/* ------------------------------------------- */
	sgcp->seg_ID = cur_seg;
	sgcp->seg_IP = tcp;
#ifdef	ABAL21
	sgcp->seg_KS = TcodeConstants;
#endif
	sgcp->seg_CS = TcodeSegment;
	sgcp->seg_SP = ip_next;
	sgcp->seg_EP = GlobalErrorTrap;
	sgcp->seg_SH = StackHold;
	sgcp->seg_SM = sicico;
	sgcp->seg_DS = LocalDataSegment;
	sgcp->seg_EVS = timersem;
	sgcp->seg_EVA = eventadr;
#ifdef	ABAL21
	sgcp->seg_EVH = HardEvent;
#endif
	minder [mindex++] = (BPTR) sgcp;

	/* Reset Internal status semaphores */
	/* -------------------------------- */
	StackHold = ip_next;
	sicico &= ( OFSEM_ERR & OFSEM_TRP & OFSEM_VLDT);
	timersem &= EVENT_SEMOFF;

#ifdef	ABAL21
	disable_hard_event();
#endif
	/* Reset Local Data and Error Pointers */
	/* ----------------------------------- */
	LocalDataSegment = (BPTR) 0;
	GlobalErrorTrap = (ERRORPTR) 0;

	return(1);

}

VOID	LiberateSegmentContext()
{
	EXAWORD	segdt;

	/* Ensure segment table is valid */
	/* ----------------------------- */
	if ( TcodeSegmentTable == (struct segmform SPTR) 0 ) return;

	/* Attempt Liberation of Current Local DS */
	/* -------------------------------------- */
	if ( (segdt = seg_find(cur_seg)) == MOINS_UN) return;

	/* If Segment Local Data is NOT PUBLIC */
	/* ----------------------------------- */
	if (((*(TcodeSegmentTable + segdt)).segm_OP & 0x0002 ) == 0) {

		/* Perform Controlled Liberation of LOCAL DS */
		/* ----------------------------------------- */
		ControlLiberate((BPTR SPTR) & LocalDataSegment);

#ifdef	ABAL21
		if ( (*(TcodeSegmentTable + segdt)).segm_AK != 0 ) {
			ControlLiberate((BPTR SPTR) & (*(TcodeSegmentTable + segdt)).segm_KS );
			}
#endif

		}


	/* Test for and liberate Error Trap */
	/* -------------------------------- */
	if ( sicico & ERROR_TEST )
		release_error_traps();

	return;

}

/*
 *	R E S T _ S E G M ( )
 *	---------------------
 *
 *	This function restores a segment's context which had 
 *	previously been saved during the LDGO.SEG 
 *	
 */

EXAWORD	rest_segm()
{
	struct context  SPTR sgcp;

	/* Check for and avoid stack wrap over */
	/* ----------------------------------- */
	if ( mindex == 0 ) { 
		err_val = ABAL_RETNOGSB; 
		return(SOFTERROR); 
		}

	/* Attempt liberation of current Segment Context */
	/* --------------------------------------------- */
	LiberateSegmentContext();

	/* Collect structure from the stack */
	/* -------------------------------- */
	sgcp = (struct context SPTR) minder [--mindex];

	/* Transfer from Stacked context to working variables */
	/* -------------------------------------------------- */ 
	cur_seg 	= sgcp->seg_ID;
#ifdef	ABAL21
	if (sgcp->seg_KS == (BPTR) 0)
		TcodeConstants = (BPTR) 0;
	else	TcodeConstants  = sgcp->seg_KS;
#endif
	TcodeSegment	= sgcp->seg_CS;
	fdex 		= (TcodeSegment + sgcp->seg_IP);
	GlobalErrorTrap	= sgcp->seg_EP;
	ip_next		= sgcp->seg_SP;
	StackHold	= sgcp->seg_SH;
	sicico		= sgcp->seg_SM;
	LocalDataSegment = sgcp->seg_DS;
	timersem 	= sgcp->seg_EVS;
	eventadr	= sgcp->seg_EVA;
#ifdef	ABAL21
	HardEvent	= sgcp->seg_EVH;
	enable_hard_event();
#endif

	/* Liberate stacked context pointer */
	/* -------------------------------- */
	liberate((BPTR) sgcp);
	return(1);
}

/*
 *	W H O O P S ( )
 *	---------------
 *	Recover from segment Load Error with previous segment Context intact
 *
 */

EXAWORD	whoops()
{
	EXAWORD	err_keep;
	err_keep = err_val;
	(VOID) ret_seg(0);
	err_val = err_keep;
	return(SOFTERROR);
}


/*
 *	S E G M _ V A R B ( segdt )
 *	---------------------------
 *	
 *	Etablir les variables locale d'un segment
 *
 */

EXAWORD	segm_varb( segdt )
EXAWORD	segdt;
{
	EXAWORD	x,z;
	EXAWORD	ldslen;

	/* Test for Local PUBLIC data */
	/* -------------------------- */
	if (((*(TcodeSegmentTable + segdt)).segm_OP & 0x0002) != 0) 
		LocalDataSegment = (*(TcodeSegmentTable + segdt)).segm_DS;
		
	else 	
		LocalDataSegment = (BPTR) 0; 
		

	/* Test for Local Data allocation required */
	/* --------------------------------------- */
	if ( LocalDataSegment == (BPTR) 0 )  {

		/* Test for Public Data and Save Local Data Pointer */
		/* ------------------------------------------------ */
		if (((*(TcodeSegmentTable + segdt)).segm_OP & 0x0002) != 0) { 

			/* Allow allocation and variable initialisation */
			/* -------------------------------------------- */
			if ((LocalDataSegment = init_data((Tcodeword((LocalDataTable))),(Tcodeword((LocalDataTable + 4))),(LocalDataTable + 6))) == (BPTR) 0) {

				err_val = EXER_MEMFULL; 
				return(whoops()); 

				}

			/* Store initialisaed data pointer to Segment table */
			/* ------------------------------------------------ */
			(*(TcodeSegmentTable + segdt)).segm_DS = LocalDataSegment;

			}

		/* Allocate for local data storage : Attention if none */
		/* --------------------------------------------------- */
		else if ((ldslen = (Tcodeword((LocalDataTable + 4)))) == 0)
			LocalDataSegment = (BPTR) 0;
		else if ((LocalDataSegment = (BPTR) allocate(ldslen)) == (BPTR) 0) {
			err_val = EXER_MEMFULL; 
			return(whoops()); 
			}
		else	memset( (BPTR) LocalDataSegment, 0, ldslen );
		}

	/* Indicate Local Data Allocation Success */
	/* -------------------------------------- */
	return(1);
}


/*
 *	I S E G T A B ( )
 *	-----------------
 *
 *	Initialisation of the segment table and calculation of maximum
 *	segment size.
 *
 */

EXAWORD	isegtab()
{
	EXAWORD	segdex,x;
	BPTR	temp_base;


	/* Allocate of Segment DATA (READ=0) Control Zone */
	/* ---------------------------------------------- */
	if ((temp_base = (segdata = (BPTR) allocate((SegmentCount * (5 * WORDSIZE))))) == (BPTR) 0) {
		err_val = 27; 
		return(SOFTERROR); 
		}
	else	memset( (BPTR) temp_base,0,(SegmentCount * (5 * WORDSIZE)));

	/* Initialise variables */
	/* -------------------- */
	segdex = 0; MaxOverlayCode = 0;

	/* Scan Segment Table testing for longest Segment */
	/* ---------------------------------------------- */
	while ( segdex < SegmentCount ) {

		/* If not a resident segment and Greater then Largest */
		/* -------------------------------------------------- */
		if (( ((*(TcodeSegmentTable + segdex)).segm_OP & 1) == 0) && ((x = (*(TcodeSegmentTable + segdex)).segm_LC) > MaxOverlayCode ))
			MaxOverlayCode = x; 
			

		/* Store Segment ID  to DATA control zone */
		/* -------------------------------------- */
		TcodePmot( temp_base,((*(TcodeSegmentTable + segdex)).segm_ID));

		/* Next segment table entry */
		/* ------------------------ */
		temp_base += (4 * WORDSIZE); 

		TcodePmot( temp_base , 0 );

		temp_base += WORDSIZE;
		segdex++;
		}

	return(1);

}
#ifdef	ABAL21
/*
 *	S E G T _ L O D E ( secteur , longeur )
 *	---------------------------------------
 *
 *	Creation initialisation of the segment description table 
 *
 */
EXAWORD	segt_lode(secteur,longeur)
EXAWORD	secteur,longeur;
{
	EXAWORD x;
	BPTR	wptr;
	BPTR	locsegtab;

	/* Reset Segment ID to Structure Entry MAP table */
	/* --------------------------------------------- */
	memset((BPTR)  Overlay_Map , 0xFFFF , MAX_OVERLAYS * sizeof(EXAWORD));

	/* Ensure tcode file is open */
	/* ------------------------- */
	if ( VerifTcode() == SOFTERROR )
		return(SOFTERROR);

	/* Attempt to allocate Segment Control Table */
	/* ----------------------------------------- */
	SegmentCount = longeur / 24;
	if ((TcodeSegmentTable = (struct segmform SPTR) allocate(SegmentCount * sizeof( struct segmform ))) == (struct segmform SPTR) 0)
		return( SOFTERROR );
	else	memset( TcodeSegmentTable, 0, SegmentCount * sizeof( struct segmform ));

#ifdef	VMS_OPTIMISED
	/* Attempt to load Segment description table */
	/* ----------------------------------------- */
	if ((locsegtab = (BPTR) wr_lode(secteur,longeur)) == (BPTR) 0)
		return(SOFTERROR); 
		
#else
	/* Attempt to load Segment description table */
	/* ----------------------------------------- */
	if ((locsegtab = (BPTR) kode_lode(secteur,longeur)) == (BPTR) 0)
		return(SOFTERROR); 
		
#endif

	/* Calculate segment count */
	/* ----------------------- */
	wptr 	        = (BPTR) locsegtab;
	MaxOverlayConst = 0;

	/* Initialise segment control information */
	/* -------------------------------------- */
	for ( x = 0; x < SegmentCount; x++ ) {

		(*(TcodeSegmentTable + x)).segm_ID = Tcodeword((wptr + 0));	/* Numero du segment 	*/
		(*(TcodeSegmentTable + x)).segm_AC = Tcodeword((wptr + 2));	/* Adresse disque code 	*/
		(*(TcodeSegmentTable + x)).segm_LC = Tcodeword((wptr + 4));	/* Longeur du Code	*/
		(*(TcodeSegmentTable + x)).segm_AD = Tcodeword((wptr + 6));	/* Adresse disque data  */	
		(*(TcodeSegmentTable + x)).segm_LD = Tcodeword((wptr + 8));	/* Longeur du Data	*/
		(*(TcodeSegmentTable + x)).segm_OP = Tcodeword((wptr +10));	/* Option Value     	*/

		if (((*(TcodeSegmentTable + x)).segm_AK = Tcodeword((wptr +12))) == MOINS_UN)
			(*(TcodeSegmentTable + x)).segm_AK = 0;
		if (((*(TcodeSegmentTable + x)).segm_LK= Tcodeword((wptr +14))) == MOINS_UN )
			(*(TcodeSegmentTable + x)).segm_LK = 0;

		/* Determine Maximum overlay constants allocation limit */
		/* ---------------------------------------------------- */
		if ( (*(TcodeSegmentTable + x)).segm_LK > MaxOverlayConst )
			MaxOverlayConst =  (*(TcodeSegmentTable + x)).segm_LK;

		wptr += 24;

		/* Reset RESIDENT and PUBLIC pointers */
		/* ---------------------------------- */
		(*(TcodeSegmentTable + x)).segm_KS = (BPTR) 0;
		(*(TcodeSegmentTable + x)).segm_CS = (BPTR) 0;
		(*(TcodeSegmentTable + x)).segm_DT = (BPTR) 0;
		(*(TcodeSegmentTable + x)).segm_DS = (BPTR) 0;

#ifdef	VMS_OPTIMISED
		(*(TcodeSegmentTable + x)).segm_OP |= UseVmsSection;
#endif

		/* Establish MAP correspondance */
		/* ---------------------------- */
		Overlay_Map[ (*(TcodeSegmentTable + x)).segm_ID ] = x;

		}

 	liberate( locsegtab );

	/* Allow further initialisations */
	/* ----------------------------- */
	return(isegtab());

}

#else
/*
 *	S E G T _ L O D E ( secteur , longeur )
 *	---------------------------------------
 *
 *	Creation initialisation of the segment description table 
 *
 */
#ifdef	ABAL14
EXAWORD	segt_lode(secteur,longeur)
EXAWORD	secteur,longeur;
{
	EXAWORD x;
	BPTR	wptr;

	/* Reset Segment ID to Structure Entry MAP table */
	/* --------------------------------------------- */
	memset( (BPTR) Overlay_Map , 0xFFFF , MAX_OVERLAYS );

	/* Ensure tcode file is open */
	/* ------------------------- */
	if ( VerifTcode() == SOFTERROR ) {
		return(SOFTERROR);
		}

#ifdef	VMS_OPTIMISED
	/* Attempt to allocate Segment description table */
	/* --------------------------------------------- */
	if ((TcodeSegmentTable = (struct segmform SPTR) kode_wr_lode(secteur,longeur)) == (struct segmform SPTR) 0)
		return(SOFTERROR); 
		
#else
	/* Attempt to allocate Segment description table */
	/* --------------------------------------------- */
	if ((TcodeSegmentTable = (struct segmform SPTR) kode_lode(secteur,longeur)) == (struct segmform SPTR) 0)
		return(SOFTERROR); 
		
#endif

	/* Calculate segment count */
	/* ----------------------- */
	SegmentCount = (longeur / 24); 
	wptr 	     = (BPTR) TcodeSegmentTable;

	/* Reorganise Segment Table with respect to machine charatceristics */
	/* ---------------------------------------------------------------- */
	for ( x = 0 ; x < longeur ; x += WORDSIZE ) { *((WPTR) ( wptr + x )) = Tcodeword( (wptr + x) ); }

	/* Initialise segment control information */
	/* -------------------------------------- */
	for ( x = 0; x < SegmentCount; x++ ) {

		/* Reset RESIDENT and PUBLIC pointers */
		/* ---------------------------------- */
		(*(TcodeSegmentTable + x)).segm_CS = (BPTR) 0;
		(*(TcodeSegmentTable + x)).segm_DT = (BPTR) 0;
		(*(TcodeSegmentTable + x)).segm_DS = (BPTR) 0;

#ifdef	VMS_OPTIMISED
		(*(TcodeSegmentTable + x)).segm_OP |= UseVmsSection;
#endif

		/* Establish MAP correspondance */
		/* ---------------------------- */
		Overlay_Map[ (*(TcodeSegmentTable + x)).segm_ID ] = x;

		}
 
	/* Allow further initialisations */
	/* ----------------------------- */
	return(isegtab());

}


#else

EXAWORD	segt_lode(secteur,longeur)
EXAWORD	secteur,longeur;
{
register EXAWORD x,y;
	 BPTR	wptr;

	/* Reset Segment ID to Structure Entry MAP table */
	/* --------------------------------------------- */
	memset((BPTR) Overlay_Map , 0xFFFF , MAX_OVERLAYS );

	/* Calculate segment count and Table Size */
	/* -------------------------------------- */
	SegmentCount = (longeur / 24); 
	y = (longeur / BLOCK);
	if ((longeur % BLOCK) != 0) { y++; }

	/* Attempt to allocate Segment description table */
	/* --------------------------------------------- */
	if ( (TcodeSegmentTable = (struct segmform SPTR) allocate((y * BLOCK))) == (struct segmform SPTR) 0)
		return(SOFTERROR); 
		

	/* Ensure tcode file is open */
	/* ------------------------- */
	if ( VerifTcode() == SOFTERROR ) {
		return(SOFTERROR);
		}

	/* Read segment description table from Tcode file */
	/* ---------------------------------------------- */
	if ( SectRead(TcodeFileHandle,(wptr = (BPTR) TcodeSegmentTable),(y * BLOCK),secteur) == MOINS_UN )
		return(SOFTERROR); 
		

	/* Reorganise Segment Table with respect to machine charatceristics */
	/* ---------------------------------------------------------------- */
	for ( x = 0 ; x < longeur ; x += WORDSIZE ) { *((WPTR) ( wptr + x )) = Tcodeword( (wptr + x) ); }

	/* Initialise segment control information */
	/* -------------------------------------- */
	for ( x = 0; x < SegmentCount; x++ ) {

		/* Reset RESIDENT and PUBLIC pointers */
		/* ---------------------------------- */
		(*(TcodeSegmentTable + x)).segm_CS = (BPTR) 0;
		(*(TcodeSegmentTable + x)).segm_DT = (BPTR) 0;
		(*(TcodeSegmentTable + x)).segm_DS = (BPTR) 0;

		/* Establish MAP correspondance */
		/* ---------------------------- */
		Overlay_Map[ (*(TcodeSegmentTable + x)).segm_ID ] = x;

		}
 
	/* Allow further initialisations */
	/* ----------------------------- */
	return(isegtab());

}

#endif
#endif

/*
 *	L i b e r a t e S e g m e n t T a b l e ( )
 *	-------------------------------------------
 *	Organised liberation of the segment control table 
 *
 *	Called from EXI.C during context liberation
 *
 */ 

VOID	LiberateSegmentTable()
{
	EXAWORD	segdt;

	if ( TcodeSegmentTable != (struct segmform SPTR) 0) {

		for (segdt = 0; segdt < SegmentCount; segdt++ ) {
			ControlLiberate((BPTR SPTR) & (*(TcodeSegmentTable + segdt)).segm_CS );
			ControlLiberate((BPTR SPTR) & (*(TcodeSegmentTable + segdt)).segm_DT );
			ControlLiberate((BPTR SPTR) & (*(TcodeSegmentTable + segdt)).segm_DS );
#ifdef	ABAL21
			ControlLiberate((BPTR SPTR) & (*(TcodeSegmentTable + segdt)).segm_KS );
#endif
			}

		liberate( TcodeSegmentTable );  	
		}
	return;
}



/*
 *	G E T D T C U R ( n )
 *	---------------------
 */

EXAWORD	getdtcur(segment_id)
EXAWORD	segment_id;
{
	BPTR	tp;

	tp = (BPTR) (segdata + ((Overlay_Map [segment_id]) * (5 * WORDSIZE)));

	tp += WORDSIZE;
	datadex = Tcodeword( tp); tp += WORDSIZE;
	datapnt = Tcodeword( tp); tp += WORDSIZE;
	datamax = Tcodeword( tp);
	return(datapnt);
}


/*
 *	S E T D T C U R ( n )
 *	---------------------
 */

EXAWORD	setdtcur(segment_id)
EXAWORD	segment_id;
{
	BPTR	tp;

	tp = (BPTR) (segdata + ((Overlay_Map [segment_id]) * (5 * WORDSIZE)));

	tp += WORDSIZE;
	TcodePmot( (tp) , (datadex) ); tp += WORDSIZE;
	TcodePmot( (tp) , (datapnt) ); tp += WORDSIZE;
	TcodePmot( (tp) , (datamax) );
	return(1); 
}

/*
 *	S e g m e n t C o n t r o l ( mode )
 *	------------------------------------
 *	mode(0) decrementation
 *	mode(1) incrementation
 *	of segment occupation counter
 *
 */

VOID	SegmentControl( mode , segment_id )
EXAWORD	mode;
EXAWORD	segment_id;
{
	EXAWORD	x;
	BPTR	tp;

	tp = (BPTR) (segdata + ((Overlay_Map [segment_id]) * (5 * WORDSIZE)));

	tp += (4 * WORDSIZE);
	x = Tcodeword( (tp) );
	if (mode == 1) 	x++;
	else		x--;
	TcodePmot( (tp), (x) );
	return;
}


/*
 *	S E G _ L O A D ( segdt )
 *	-------------------------
 *	Loads the Code and Local Descriptor Table from disk
 *	for the segment pointed to by SEGDT
 *
 */
#ifdef	ABAL21

EXAWORD seg_load( segdt , code_buffer , table_buffer, const_buffer )
EXAWORD	segdt;
BPTR	code_buffer;
BPTR	table_buffer;
BPTR	const_buffer;
{
	/* Default Error Value */
	/* ------------------- */
	err_val = ABAL_NUMLOG119;

	/* Check T-Code File Handle */
	/* ------------------------ */
	if ( VerifTcode() == SOFTERROR ) {
		return(SOFTERROR);
		}

	/* Collect length of the T-Code */
	/* ---------------------------- */
	segstop = ((*(TcodeSegmentTable + segdt)).segm_LC - 2);

#ifdef	VMS_OPTIMISED
	/* Attempt to Load Code from Disk */
	/* ------------------------------ */
	if ((TcodeSegment = kode_seg_lode(code_buffer , (*(TcodeSegmentTable + segdt)).segm_AC, (*(TcodeSegmentTable + segdt)).segm_LC)) == (BPTR) 0)  
		return(SOFTERROR);
#else
	/* Attempt to Load Code from Disk */
	/* ------------------------------ */
	if (((EXAWORD) kode_b_lode((TcodeSegment = code_buffer) , (*(TcodeSegmentTable + segdt)).segm_AC, (*(TcodeSegmentTable + segdt)).segm_LC)) == MOINS_UN)
		return(SOFTERROR);
		
#endif

	/* Read in The Local Data Table if required */
	/* ---------------------------------------- */
	if ( (*(TcodeSegmentTable + segdt)).segm_AD ) {
#ifdef	VMS_OPTIMISED
		if ((LocalDataTable = kode_seg_lode(table_buffer , (*(TcodeSegmentTable + segdt)).segm_AD, (*(TcodeSegmentTable + segdt)).segm_LD)) == (BPTR) 0)
			return(SOFTERROR);
#else
		if (((EXAWORD) kode_b_lode((LocalDataTable = table_buffer) , (*(TcodeSegmentTable + segdt)).segm_AD, (*(TcodeSegmentTable + segdt)).segm_LD)) == MOINS_UN)
			return(SOFTERROR);
			
#endif
		sicico |= ONSEM_VLDT;
		}

	/* Read in The Local Constants  if required */
	/* ---------------------------------------- */
	if ( (*(TcodeSegmentTable + segdt)).segm_AK != 0 ) {
#ifdef	VMS_OPTIMISED
		if ((TcodeConstants = kode_seg_lode(const_buffer , (*(TcodeSegmentTable + segdt)).segm_AK, (*(TcodeSegmentTable + segdt)).segm_LK)) == (BPTR) 0)
			return(SOFTERROR);
#else
		if (((EXAWORD) kode_b_lode((TcodeConstants = const_buffer) , (*(TcodeSegmentTable + segdt)).segm_AK, (*(TcodeSegmentTable + segdt)).segm_LK)) == MOINS_UN)
			return(SOFTERROR);
			
#endif
		}
	else	TcodeConstants = GlobalConstants;

	err_val = 0; 
	return(1);

}

#else
EXAWORD seg_load( segdt , code_buffer , table_buffer )
EXAWORD	segdt;
BPTR	code_buffer;
BPTR	table_buffer;
{
	/* Default Error Value */
	/* ------------------- */
	err_val = ABAL_NUMLOG119;

	/* Check T-Code File Handle */
	/* ------------------------ */
	if ( VerifTcode() == SOFTERROR ) {
		return(SOFTERROR);
		}

	/* Collect length of the T-Code */
	/* ---------------------------- */
	segstop = ((*(TcodeSegmentTable + segdt)).segm_LC - 2);

#ifdef	VMS_OPTIMISED
	/* Attempt to Load Code from Disk */
	/* ------------------------------ */
	if ((TcodeSegment = kode_seg_lode(code_buffer , (*(TcodeSegmentTable + segdt)).segm_AC, (*(TcodeSegmentTable + segdt)).segm_LC)) == (BPTR) 0)  
		return(SOFTERROR);
#else
	/* Attempt to Load Code from Disk */
	/* ------------------------------ */
	if (((EXAWORD) kode_b_lode((TcodeSegment = code_buffer) , (*(TcodeSegmentTable + segdt)).segm_AC, (*(TcodeSegmentTable + segdt)).segm_LC)) == MOINS_UN)
		return(SOFTERROR);
		
#endif

	/* Read in The Local Data Table if required */
	/* ---------------------------------------- */
	if ( (*(TcodeSegmentTable + segdt)).segm_AD ) {
#ifdef	VMS_OPTIMISED
		if ((LocalDataTable = kode_seg_lode(table_buffer , (*(TcodeSegmentTable + segdt)).segm_AD, (*(TcodeSegmentTable + segdt)).segm_LD)) == (BPTR) 0)
			return(SOFTERROR);
#else
		if (((EXAWORD) kode_b_lode((LocalDataTable = table_buffer) , (*(TcodeSegmentTable + segdt)).segm_AD, (*(TcodeSegmentTable + segdt)).segm_LD)) == MOINS_UN)
			return(SOFTERROR);
			
#endif
		sicico |= ONSEM_VLDT;
		}

	err_val = 0; return(1);

}
#endif


/*
 *	S e g m e n t _ L o a d ( segment_table_index )
 *	-----------------------------------------------
 *	Performs segment loading or activation (Resident or Overlay)
 *
 */
#ifdef	ABAL21

EXAWORD	Segment_Load(segdt)
EXAWORD	segdt;
{
	/* Test for Overlay or Resident Segment */
	/* ------------------------------------ */
	if (( (*(TcodeSegmentTable + segdt)).segm_OP & 1 ) == 0 ) {

		/* Check for Segment already in Overlay Zone */
		/* ----------------------------------------- */
		if ( Overlay_User != cur_seg ) {
			
			/* Identify Segment using overlay zone */
			/* ----------------------------------- */
			Overlay_User = cur_seg;
			
			/* Perform Overlay Loading */
			/* ----------------------- */
			return ( seg_load(segdt,Overlay_Code,Overlay_Data,Overlay_Const) );

			}
		else	{
			/* Segment currently loading already present */
			/* ----------------------------------------- */
			TcodeSegment   = Overlay_Code;
			LocalDataTable = Overlay_Data;

			if ( (*(TcodeSegmentTable + segdt)).segm_AK != 0 )
				TcodeConstants = Overlay_Const;
			else	TcodeConstants = GlobalConstants;

			/* Establish LOCAL variables active Flag */
			/* ------------------------------------- */
			if ( (*(TcodeSegmentTable + segdt)).segm_AD != 0 )

				sicico |= ONSEM_VLDT;

			return(1);
			}
		}

	/* Test for Resident segment buffer already allocated */
	/* -------------------------------------------------- */
	if ( (*(TcodeSegmentTable + segdt)).segm_CS == (BPTR) 0 ) {

		/* Attempt to allocate Code buffer */
		/* ------------------------------- */
		if (((*(TcodeSegmentTable + segdt)).segm_CS = (BPTR) allocate( (*(TcodeSegmentTable + segdt)).segm_LC)) != (BPTR) 0) {

			/* Check for local variables associated with segment */
			/* ------------------------------------------------- */
			if ( (*(TcodeSegmentTable + segdt)).segm_AD != 0 ) {

				/* Attempt to allocate LDT buffer */
				/* ------------------------------ */
				if (((*(TcodeSegmentTable + segdt)).segm_DT = (BPTR) allocate( (*(TcodeSegmentTable + segdt)).segm_LD)) == (BPTR) 0) {

					/* Liberate Code Buffer */
					/* -------------------- */
#ifdef	VMS_OPTIMISED
					if (!(UseVmsSection))
#endif
						liberate( (*(TcodeSegmentTable + segdt)).segm_CS );

					/* Reset to avoid Errors */
					/* --------------------- */
					(*(TcodeSegmentTable + segdt)).segm_CS = (BPTR) 0;
	
					/* Signal the allocation Allocation Error */
					/* -------------------------------------- */
					err_val = 27; return(SOFTERROR);

					}

				}

			/* Check for local Constants associated with segment */
			/* ------------------------------------------------- */
			if ( (*(TcodeSegmentTable + segdt)).segm_AK != 0 ) {

				/* Attempt to allocate LKT buffer */
				/* ------------------------------ */
				if (((*(TcodeSegmentTable + segdt)).segm_KS = (BPTR) allocate( (*(TcodeSegmentTable + segdt)).segm_LK)) == (BPTR) 0) {

					/* Liberate Code Buffer */
					/* -------------------- */
#ifdef	VMS_OPTIMISED
					if (!(UseVmsSection))
#endif
						liberate( (*(TcodeSegmentTable + segdt)).segm_CS );

					/* Reset to avoid Errors */
					/* --------------------- */
					(*(TcodeSegmentTable + segdt)).segm_CS = (BPTR) 0;
	
					/* Signal the allocation Allocation Error */
					/* -------------------------------------- */
					err_val = 27; return(SOFTERROR);

					}

				}

#ifdef	VMS_OPTIMISED

			if (seg_load(segdt,(*(TcodeSegmentTable + segdt)).segm_CS,(*(TcodeSegmentTable +segdt)).segm_DT,(*(TcodeSegmentTable +segdt)).segm_KS) == SOFTERROR)
				return(SOFTERROR );

			if ( (*(TcodeSegmentTable + segdt)).segm_CS != TcodeSegment ) {
				ControlLiberate( (*(TcodeSegmentTable + segdt)).segm_CS );
				(*(TcodeSegmentTable + segdt)).segm_CS = TcodeSegment;
				}
			if ( (*(TcodeSegmentTable + segdt)).segm_DT != LocalDataTable ) {
				ControlLiberate( (*(TcodeSegmentTable + segdt)).segm_DT );
				(*(TcodeSegmentTable + segdt)).segm_DT = LocalDataTable;
				}
			if ( (*(TcodeSegmentTable + segdt)).segm_KS != TcodeConstants ) {
				ControlLiberate( (*(TcodeSegmentTable + segdt)).segm_KS );
				(*(TcodeSegmentTable + segdt)).segm_KS = TcodeConstants;
				}

			return( GOODRESULT );
#else

			/* Perform Code and Data Table Loading */
			/* ----------------------------------- */
			return(seg_load(segdt,(*(TcodeSegmentTable + segdt)).segm_CS,(*(TcodeSegmentTable + segdt)).segm_DT,(*(TcodeSegmentTable +segdt)).segm_KS));
#endif

			}

		/* Allocation Error */
		/* ---------------- */
		err_val = 27; 
		return(SOFTERROR);


		}

	/* Establish new Code and Table Bases */
	/* ---------------------------------- */
	TcodeSegment      = (*(TcodeSegmentTable + segdt)).segm_CS;
	LocalDataTable    = (*(TcodeSegmentTable + segdt)).segm_DT;

	if ( (*(TcodeSegmentTable + segdt)).segm_AK != 0 )
		TcodeConstants	  = (*(TcodeSegmentTable + segdt)).segm_KS;
	else	TcodeConstants	  = GlobalConstants;

	/* Establish LOCAL variables active Flag */
	/* ------------------------------------- */
	if ( (*(TcodeSegmentTable + segdt)).segm_AD != 0 )
		sicico |= ONSEM_VLDT;
		

	return(1);
}


#else

EXAWORD	Segment_Load(segdt)
EXAWORD	segdt;
{
	/* Test for Overlay or Resident Segment */
	/* ------------------------------------ */
	if (( (*(TcodeSegmentTable + segdt)).segm_OP & 1 ) == 0 ) {

		/* Check for Segment already in Overlay Zone */
		/* ----------------------------------------- */
		if ( Overlay_User != cur_seg ) {
			
			/* Identify Segment using overlay zone */
			/* ----------------------------------- */
			Overlay_User = cur_seg;
			
			/* Perform Overlay Loading */
			/* ----------------------- */
			return ( seg_load(segdt,Overlay_Code,Overlay_Data) );

			}
		else	{
			/* Segment currently loading already present */
			/* ----------------------------------------- */
			TcodeSegment = Overlay_Code;
			LocalDataTable    = Overlay_Data;

			/* Establish LOCAL variables active Flag */
			/* ------------------------------------- */
			if ( (*(TcodeSegmentTable + segdt)).segm_AD != 0 )

				sicico |= ONSEM_VLDT;

				

			return(1);
			}
		}

	/* Test for Resident segment buffer already allocated */
	/* -------------------------------------------------- */
	if ( (*(TcodeSegmentTable + segdt)).segm_CS == (BPTR) 0 ) {

		/* Attempt to allocate Code buffer */
		/* ------------------------------- */
		if (((*(TcodeSegmentTable + segdt)).segm_CS = (BPTR) allocate( (*(TcodeSegmentTable + segdt)).segm_LC)) != (BPTR) 0) {

			/* Check for local variables associated with segment */
			/* ------------------------------------------------- */
			if ( (*(TcodeSegmentTable + segdt)).segm_AD != 0 ) {

				/* Attempt to allocate LDT buffer */
				/* ------------------------------ */
				if (((*(TcodeSegmentTable + segdt)).segm_DT = (BPTR) allocate( (*(TcodeSegmentTable + segdt)).segm_LD)) == (BPTR) 0) {

					/* Liberate Code Buffer */
					/* -------------------- */
#ifdef	VMS_OPTIMISED
					if (!(UseVmsSection))
#endif
						liberate( (*(TcodeSegmentTable + segdt)).segm_CS );

					/* Reset to avoid Errors */
					/* --------------------- */
					(*(TcodeSegmentTable + segdt)).segm_CS = (BPTR) 0;
	
					/* Signal the allocation Allocation Error */
					/* -------------------------------------- */
					err_val = 27; return(SOFTERROR);

					}

				}

#ifdef	VMS_OPTIMISED

			if (seg_load(segdt,(*(TcodeSegmentTable + segdt)).segm_CS,(*(TcodeSegmentTable +segdt)).segm_DT) == SOFTERROR)
				return(SOFTERROR );

			if ( (*(TcodeSegmentTable + segdt)).segm_CS != TcodeSegment ) {
				ControlLiberate( (*(TcodeSegmentTable + segdt)).segm_CS );
				(*(TcodeSegmentTable + segdt)).segm_CS = TcodeSegment;
				}
			if ( (*(TcodeSegmentTable + segdt)).segm_DT != LocalDataTable ) {
				ControlLiberate( (*(TcodeSegmentTable + segdt)).segm_DT );
				(*(TcodeSegmentTable + segdt)).segm_DT = LocalDataTable;
				}

			return( GOODRESULT );
#else

			/* Perform Code and Data Table Loading */
			/* ----------------------------------- */
			return(seg_load(segdt,(*(TcodeSegmentTable + segdt)).segm_CS,(*(TcodeSegmentTable + segdt)).segm_DT));
#endif

			}

		/* Allocation Error */
		/* ---------------- */
		err_val = 27; return(SOFTERROR);


		}

	/* Establish new Code and Table Bases */
	/* ---------------------------------- */
	TcodeSegment      = (*(TcodeSegmentTable + segdt)).segm_CS;
	LocalDataTable    = (*(TcodeSegmentTable + segdt)).segm_DT;

	/* Establish LOCAL variables active Flag */
	/* ------------------------------------- */
	if ( (*(TcodeSegmentTable + segdt)).segm_AD != 0 )

		sicico |= ONSEM_VLDT;

		

	return(1);
}
#endif

/*
 *	L D G O _ S E G ( seg_no )
 *	--------------------------
 *
 *	Chargement d'un segment de tcode
 *	
 */

EXAWORD	ldgo_seg( seg_no , tcp)
EXAWORD	seg_no,tcp;
{
	EXAWORD	x,y;
	EXAWORD	segdt;
	err_val = ABAL_MEMORY;

	/* Check for already loaded and running */
	/* ------------------------------------ */
	if ( (sicico & ONSEM_SEG ) == 0 ) {

		if ( MaxOverlayCode != 0 ) {

			/* Attempt Allocation of Overlay Code zone */
			/* --------------------------------------- */
#ifdef	VMS_OPTIMISED
			if (!(UseVmsSection)) {
#endif
				if ((Overlay_Code = (BPTR) allocate(MaxOverlayCode)) == (BPTR) 0)
					return(SOFTERROR);
					
#ifdef	ABAL21
				if ( MaxOverlayConst != 0 )
					if ((Overlay_Const= (BPTR) allocate(MaxOverlayConst)) == (BPTR) 0)
						return(SOFTERROR);
					
#endif
#ifdef	VMS_OPTIMISED
				}
#endif

			/* Attempt Allocation of Overlay Data Table Zone */
			/* --------------------------------------------- */
			if ( l_max_vls > 0 ) {
#ifdef	VMS_OPTIMISED
				if (!(UseVmsSection))
#endif
					if ((Overlay_Data = (BPTR) allocate(l_max_vls)) == (BPTR) 0) {
						return(SOFTERROR);
						}
				}

			}
		else	{
			Overlay_Code  = (BPTR) 0;
			Overlay_Data  = (BPTR) 0;
#ifdef	ABAL21
			Overlay_Const = (BPTR) 0;
#endif
			}

		/* Indicate Loaded and ready to run */
		/* -------------------------------- */
		sicico |= ONSEM_SEG; 
		}
	else 	{

		/* Save current segment context and DATA */
		/* ------------------------------------- */	
		if ( keep_segm(tcp)     == SOFTERROR ) { return(SOFTERROR); }
		if ( setdtcur(cur_seg)  == SOFTERROR ) { return(SOFTERROR); }

		}

	cur_seg = seg_no;

	/* Attepmpt to locate Segment table Entry */
	/* -------------------------------------- */
	if ( (segdt = seg_find(seg_no)) == MOINS_UN) { 

		/* Restore Possible previous Context */
		/* --------------------------------- */
		(VOID) rest_segm();
		err_val = 100;
		return(SOFTERROR); 
		}

	/* Increment New Segment Usage Counter */
	/* ----------------------------------- */
	SegmentControl(1,cur_seg);

	/* Establish Segment Code and Data Table Zones */
	/* ------------------------------------------- */
	if (Segment_Load(segdt) != SOFTERROR) { 

		/* Establish new Tcode Pointer */
		/* --------------------------- */
		fdex = TcodeSegment;

		/* Test for Existance   of DATA (READ=0) */
		/* ------------------------------------- */
		if ( getdtcur(cur_seg) == SOFTERROR ) {

			/* Allow initialisation of DATA (READ=0) */
			/* ------------------------------------- */
			if ((datapnt = (Tcodeword((TcodeSegment + segstop)))) == 0xFFFF) {

				/* No DATA (READ=0) for this Segment */
				/* --------------------------------- */
				datamax = 0; datadex = 1; 
				}
			else 	{

				/* Collect DATA item count (READ=0) */
				/* -------------------------------- */
				datamax = (Tcodeword( (TcodeSegment + segstop - 2)));
				datadex = 1;
				}

			/* Perform DATA (READ=0) Initialisation */
			/* ------------------------------------ */
			if ( setdtcur(cur_seg) == SOFTERROR ) { return(whoops()); }
			}

		/* If Succesful DATA (READ=0) Initialisation and Still Valid */
		/* --------------------------------------------------------- */
		if ( datadex <= datamax ) {

			/* Allow initialisation of DATA (READ=0) Manager */
			/* --------------------------------------------- */
			if ( setdata(datadex) == SOFTERROR ) { return(whoops()); }

			}

		/* Detect Local Variables Present semaphore and Allocate */
		/* ----------------------------------------------------- */
		if ( sicico & ONSEM_VLDT ) { return (segm_varb(segdt));}
		else { return(1); }

		}

	/* Return Error (after cleanup) to caller */
	/* -------------------------------------- */
	return(whoops());

}

/*
 *	S e g m e n t O c c u p a t i o n ( segment_id )
 *	------------------------------------------------
 *	Returns the number of occupants of specified Segment
 *
 */
EXAWORD	SegmentOccupation( segment_id )
EXAWORD	segment_id;
{
	BPTR	tp;

	tp = (BPTR) ((segdata + ((Overlay_Map [segment_id]) * (5 * WORDSIZE))) + (4 * WORDSIZE));
 	return ( (Tcodeword( (tp) )) );

}



/*
 *	S e g m e n t D i s c h a r g e ( segment_id )
 *	----------------------------------------------
 *	Liberation of Resident and Public Code and Data
 *
 */

VOID	release_segment(segment_id)
EXAWORD	segment_id;
{
	EXAWORD	segdt;

	/* Collect segment table index */
	/* --------------------------- */
	if ((segdt = seg_find(segment_id)) == MOINS_UN) return;

	/* Test for Public or Resident Options present */
	/* ------------------------------------------- */
	if ( (*(TcodeSegmentTable + segdt)).segm_OP & 0x0003 ) {

		/* Test for segment not currently occupied */
		/* --------------------------------------- */
		if ( SegmentOccupation( segment_id ) == 0 ) {

			/* Test for Public Local Data Segment */
			/* ---------------------------------- */
			if ( (*(TcodeSegmentTable + segdt)).segm_OP & 0x0002 )

				/* Liberate Public Data Segment */
				/* ---------------------------- */
				ControlLiberate((BPTR SPTR) & (*(TcodeSegmentTable + segdt)).segm_DS );

			/* Test for Resident Segment of Code  */
			/* --------------------------------- */
			if ( (*(TcodeSegmentTable + segdt)).segm_OP & 0x0001 ) {


				/* Liberate Public Code Segment */
				/* ---------------------------- */
				ControlLiberate((BPTR SPTR) & (*(TcodeSegmentTable + segdt)).segm_CS );

				/* Liberate Public Data Table */
				/* -------------------------- */
				ControlLiberate((BPTR SPTR) & (*(TcodeSegmentTable + segdt)).segm_DT );
#ifdef	ABAL21
				/* Liberate Local Constants Table */
				/* ------------------------------ */
				if ( (*(TcodeSegmentTable + segdt)).segm_AK != 0 ) {
					ControlLiberate((BPTR SPTR) & (*(TcodeSegmentTable + segdt)).segm_KS );
					}
#endif
				}
			}
		}
	return;

}

/* 
 *	R E T _ S E G ( modus_operandis )
 *	---------------------------------
 *	Performs the segment return to a stacked segment context
 *	
 *	The Mode arguament indicates 	(0 : RET.SEG normal condition       )
 *					(1 : END.SEG remove residence/public)
 *
 */

EXAWORD ret_seg(EXAWORD	modus_operandis)
{
	register EXAWORD segdt;
		 EXAWORD idkeep;	

#ifdef	ABAL21
	check_for_error_pop();
#endif	

	/* Decrement Old Segment Usage Counter */
	/* ----------------------------------- */
	SegmentControl(0,cur_seg);

	/* Duplicate current Segment Identity */
	/* ---------------------------------- */
	idkeep = cur_seg;


	/* Recover Previous Segment Context */
	/* -------------------------------- */
	if ( rest_segm() == SOFTERROR )	
		return(SOFTERROR);

	/* Collect Segment table index for Recovered Segment */
	/* ------------------------------------------------- */
	if ( (segdt = seg_find(cur_seg)) == MOINS_UN) 
		return(SOFTERROR);

	/* Attempt to Load the Segment (if needed) */
	/* --------------------------------------- */
	if (Segment_Load(segdt) == 1) {

		/* Test for END.SEG or RET.SEG */
		/* --------------------------- */
		if ( modus_operandis != 0 ) 
			
			/* Attempt liberation of Previous Segment */
			/* -------------------------------------- */
			release_segment(idkeep);

		/* Perform DATA (READ=0) recovery */
		/* ------------------------------ */
		if ( getdtcur(cur_seg) == SOFTERROR) 
			return(SOFTERROR);

		/* Initialise DATA (READ=0) Manager */
		/* -------------------------------- */
		(VOID) setdata(datadex);

		/* Return to T-Code Execution */
		/* -------------------------- */
		return(1);
		}
	else 	
		/* Indicate Segment Return Failure */
		/* ------------------------------- */
		return(SOFTERROR); 

}

/*
 *	Returns the base adresse of the currently active Segment
 *	This may be either a resident segment or an overlaid segment.
 *	For EXADB to be able to position traps in current segment.
 */

BPTR	CurrentSegmentPointer( segment_id )
EXAWORD	segment_id;
{
	EXAWORD	segdt;

	/* Currently in the overlay zone */
	/* ----------------------------- */
	if ( Overlay_User == segment_id )
		return((BPTR) Overlay_Code );

	/* Attepmpt to locate Segment table Entry */
	/* -------------------------------------- */
	if ( (segdt = seg_find(segment_id)) == MOINS_UN)
		return( (BPTR) TcodeSegment );

	/* Return Resident Zone pointer */
	/* ---------------------------- */
	return( (BPTR) (*(TcodeSegmentTable + segdt)).segm_CS  );


}
