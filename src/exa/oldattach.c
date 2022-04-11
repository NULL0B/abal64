/* don't worry this is now excluded : its no longer valid for VERSION 666 */

/*	IJM 12/12/2002 */

BPTR	allocate_indirection_table( proc_nombre, context )
EXAWORD	proc_nombre;
BPTR	context;
{
	BPTR	result;
	EXAWORD	thisproc;
	EXAWORD	indent;

	if ((result = allocate( (proc_nombre * (5+WORDSIZE)) )) != (BPTR) 0) {
	
		for (indent=0, thisproc = 0; proc_nombre != 0; proc_nombre-- ) {
			establish_pointer_variable((BPTR) (result+indent),(BPTR) context, ALLOCATED_POINTER );
			indent += PTRSIZE;
			TcodePmot( (result+indent), thisproc );
			indent += WORDSIZE;
			thisproc += (8*WORDSIZE);
			}
		}

	return( result );
}

EXAWORD	attach_indirect_program( result, adesc )
BPTR	result;
EXAWORD	adesc;
{
	EX_FILE_HANDLE	tcode_handle;
	EX_FILE_HANDLED	hold_handle;
	EXAWORD	thisproc;
	BPTR	fdex;
	EXAWORD	dcrypt;
	EXAWORD	gdt_sector;
	EXAWORD	gdt_length;
	EXAWORD	gct_sector;
	EXAWORD	gct_length;
	EXAWORD	gpt_sector;
	EXAWORD	gpt_length;
	EXAWORD	ppt_length;
	EXAWORD	proc_nombre;
	EXAWORD	indent;
	BPTR	gct;
	BPTR	gdt;
	BPTR	attnfic;
	BPTR	ipt;
	OVLOBJPTR	context;
	EXAWORD	kode_b_lode( BPTR, EXAWORD, EXAWORD );
	BPTR	assigned_filename( EXAWORD );
	BPTR 	load_tcode_procedures( EXAWORD, BPTR);

	/* Evaluate handle or filename parameter */
	/* ------------------------------------- */
	if (argset(((adesc & 0x0006) >> 1),0,2) == SOFTERROR) 
		return(SOFTERROR);

	/* Strings are filenames */
	/* --------------------- */
	if ( (worktyp2 & VARB_ISOL) == VARB_STR)
		attnfic = workptr2;
	else	{
		/* Watch out for atr bug : BCD constant */
		/* ------------------------------------ */
		if ( (worktyp2 & VARB_ISOL) == VARB_BCD)
			workval2 = bcdtoi((BPTR) workptr2, worklen2 );

		/* Assign handle */
		/* ------------- */
		if ((attnfic = assigned_filename( workval2 )) == (BPTR) 0) {
			err_val = 116;
			return( SOFTERROR );
			}
		}

	/* Attempt to attach this specified program */
	/* ---------------------------------------- */
	if ((tcode_handle = open_tcode_file((BPTR) attnfic )) == EX_UNUSED_HANDLE )
		return( SOFTERROR );

	/* Load Tcode Header */
	/* ----------------- */
	if (SectRead((EX_FILE_HANDLE) tcode_handle,(BPTR) askbuf, TCODEBLOCK, 0) == MOINS_UN) {
		CloseTcodeFile( tcode_handle );
		return( SOFTERROR ); 
		}		

	hold_handle = TcodeFileHandle;
	TcodeFileHandle = tcode_handle;

	fdex  = (BPTR) askbuf;

	/* Collect Decryption Code */
	/* ----------------------- */
	dcrypt 		=	Tcodeword( (fdex + 62 ) );

	/* Decryptage des informations essentielles */
	/* ---------------------------------------- */
	if (( dcrypt != 0 ) && ( dcrypt != MOINS_UN ))
		(VOID) abal_crypt(dcrypt,(BPTR) (fdex + 18),44,0);

	/* Allocate Global Variables */
	/* ------------------------- */
	gct_sector = Tcodeword( (fdex + 0x0016 ) );
	gct_length = Tcodeword( (fdex + 0x0018 ) );
	gdt_sector = Tcodeword( (fdex + 0x001A ) );
	gdt_length = Tcodeword( (fdex + 0x001C ) );
	gpt_sector = Tcodeword( (fdex + 0x0026 ) );
	gpt_length = Tcodeword( (fdex + 0x0028 ) );

	/* Allocate Context controller */
	/* --------------------------- */
	if (( context = (OVLOBJPTR) allocate( sizeof( struct overlay_object ))) == (OVLOBJPTR) 0) {
		CloseTcodeFile( tcode_handle );
		TcodeFileHandle = hold_handle;
		return( SOFTERROR ); 
		}
	else	{
		context->handle      = tcode_handle;
		context->procmaxid   = 0;
		context->constants   = (BPTR) 0;
		context->variables   = (BPTR) 0;
		context->descriptors = (BPTR) 0;
		context->procedures  = (BPTR) 0;
		}

	/* Load Overlay Constants */
	/* ---------------------- */
	if ((gct_sector != MOINS_UN) && (gct_sector != 0)) 
		if (((context->constants = (BPTR) allocate( gct_length )) == (BPTR) 0)
		||  (kode_b_lode(context->constants, gct_sector, gct_length) == MOINS_UN ))
			return( release_overlay_context( context, hold_handle, SOFTERROR ) );

	if (((context->descriptors = (BPTR) allocate( gdt_length )) == (BPTR) 0)
	||  (kode_b_lode( context->descriptors, gdt_sector, gdt_length) == MOINS_UN ))
		return( release_overlay_context( context, hold_handle, SOFTERROR ) );

	gdt_length = Tcodeword((context->descriptors + (2*WORDSIZE))); 

	if ((context->variables = dynamic_object_allocation( gdt_length )) == (BPTR) 0)
		return( release_overlay_context( context, hold_handle, SOFTERROR ) );

	establish_pointer_variable( (result+PTRSIZE), context->variables, ALLOCATED_POINTER );
	
	/* Load Procedure Table */
	/* -------------------- */
	context->procmaxid = proc_nombre = ( gpt_length / (8*WORDSIZE) );
	ppt_length =  ( proc_nombre * PTRSIZE );

	/* Allocate for table of Procedure pointers */
	/* ---------------------------------------- */
	if ((gdt = dynamic_object_allocation( ppt_length )) == (BPTR) 0)
		return( release_overlay_context( context, hold_handle, SOFTERROR ) );

	establish_pointer_variable( result, gdt, ALLOCATED_POINTER );

	/* Initialise loaded procedures */
	/* ---------------------------- */
	result = gdt;

	if (((gdt = (BPTR) allocate( gpt_length )) == (BPTR) 0)
	||  (kode_b_lode( gdt, gpt_sector, gpt_length) == MOINS_UN ))
		return( release_overlay_context( context, hold_handle, SOFTERROR ) );

	/* Allocate Indirection Table */
	/* -------------------------- */
	if ((ipt = (BPTR) allocate_indirection_table( proc_nombre, context )) == (BPTR) 0) {
		liberate( gdt );
		return( release_overlay_context( context, hold_handle, SOFTERROR ) );
		}

	/* Now Load Actual Procedure Table as for Normal Program */
	/* ----------------------------------------------------- */
	if ((context->procedures = (BPTR) load_tcode_procedures( proc_nombre , gdt )) == (BPTR) 0) {
		liberate( gdt );
		liberate( ipt );
		return( release_overlay_context( context, hold_handle, SOFTERROR ) );
		}

	liberate( gdt );

	/* Now initialise Procedure Indirection Table */
	/* ------------------------------------------ */
	for (thisproc = 0 ; proc_nombre > 0; proc_nombre-- ) {
		establish_pointer_variable( result,(BPTR) ipt, PROGRAM_POINTER );
		result += PTRSIZE;
		ipt    += (PTRSIZE+WORDSIZE);
		}

	/* Restore Tcode File Handle */
	/* ------------------------- */
	TcodeFileHandle = hold_handle;

	return( GOODRESULT );

}


