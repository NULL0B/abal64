/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXATTACH.C
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */
#ifndef	_EXATTACH_C
#define	_EXATTACH_C

#ifdef DEBUGGER
#include "exproto1.h"
#endif

EXAWORD		detach_remote_program( ATTLOGPTR attlog );
VPTR    	attach_tcode_libraries( BPTR wptr );
EX_FILE_HANDLE 	open_tcode_file(BPTR);

ATTLOGPTR	AttachmentLog;	

VOID	initialise_attachments()
{
	AttachmentLog = (ATTLOGPTR) 0;
	return;
}

/*
 *	L I B E R A T E _ L O G _ C O N T E X T
 *	---------------------------------------
 *	This function liberates everything required 
 *	by an attached object instance except its global data segment
 */

VOID	liberate_log_context( context )
OVLOBJPTR	context;
{
	if ( context->descriptors != (BPTR) 0 )
		liberate( context->descriptors );
#ifdef	BEFORE_131195
	if ( context->procedures != (BPTR) 0 )
		liberate_procedure_table( context->procedures, context->procmaxid );
#endif
	liberate( context );
	return;
}

/*	------------------	*/
/*	liberate_log_entry	*/
/*	------------------	*/
VOID	liberate_log_entry( attent )
ATTENTPTR	attent;
{
	if (attent != (ATTENTPTR) 0) 
	{
		if ( attent->ipt != (BPTR) 0 ) 
		{
			liberate( attent->ipt );
		}
		if ( attent->context != (OVLOBJPTR) 0 )
			liberate_log_context( attent->context );
		liberate( attent );
	}
	return;
}

/*	--------------------	*/
/*	liberate_log_entries	*/
/*	--------------------	*/
VOID	liberate_log_entries( entries )
ATTENTPTR	entries;
{
	ATTENTPTR	attent;
	while ((attent = entries) != (ATTENTPTR) 0) 
	{
		entries = entries->next;
		if ( entries == (ATTENTPTR) 0) 
		{
			if ( attent->context->constants != (BPTR) 0 )
				liberate( attent->context->constants );
			if ( attent->context->libraries != (BPTR) 0 )
				attent->context->nbdll = LibFuse( attent->context->libraries, attent->context->nbdll );
		}
		liberate_log_entry( attent );
	}
	return;
}

/*	----------------------	*/
/*	release_attachment_log	*/
/*	----------------------	*/
VOID	release_attachment_log( attlog )
ATTLOGPTR	attlog;
{
	VOID	liberate_for_log( ATTLOGPTR );
	if ( attlog->prev != (ATTLOGPTR) 0 )
		attlog->prev->next = attlog->next;
	else	AttachmentLog      = attlog->next;

	if ( attlog->next != (ATTLOGPTR) 0 )
		attlog->next->prev = attlog->prev;
	liberate_for_log( attlog );
}

/*	----------------------------	*/
/*	locate_and_release_log_entry	*/
/*	----------------------------	*/
EXAWORD	locate_and_release_log_entry( context )
OVLOBJPTR	context;
{
	ATTLOGPTR	attlog;
	ATTENTPTR	attent;
	ATTENTPTR	previous=(ATTENTPTR) 0;

	if (((attlog = (ATTLOGPTR) context->master) != (ATTLOGPTR) 0 ) 
	&&  ((attent = attlog->entry) != (ATTENTPTR) 0 )) 
	{
		do  	
		{

			if ( attent->context == context ) 
			{
				if ( previous == (ATTENTPTR) 0)
					attlog->entry  = attent->next;
				else	previous->next = attent->next;
				if ( attlog->entry == (ATTENTPTR) 0) 
				{
					if ( attent->context->constants != (BPTR) 0 )
						liberate( attent->context->constants );
					if ( attent->context->libraries != (BPTR) 0 )
						attent->context->nbdll = LibFuse( attent->context->libraries, attent->context->nbdll );
				}
				liberate_log_entry( attent );
				if ( attlog->entry == (ATTENTPTR) 0 )
					release_attachment_log( attlog );
				return( 1 );
			}
			else	previous = attent;
		}
		while ((attent = attent->next) != (ATTENTPTR) 0);
	}

	liberate( context );
	return( 0 );
}

/*	----------------------------	*/
/*	release_attachment_log_entry	*/
/*	----------------------------	*/
VOID	release_attachment_log_entry( iptbase )
BPTR	iptbase;
{
	OVLOBJPTR	context;

	if ( iptbase != (BPTR) 0 ) 
	{
		if (( context = (OVLOBJPTR) TcodeGetPointer((iptbase))) != (OVLOBJPTR) 0)
			if ( locate_and_release_log_entry( context ) )
				return;
		liberate( iptbase );
	}
	return;
}

/*	----------------	*/
/*	liberate_for_log	*/
/*	----------------	*/
VOID	liberate_for_log( attlog )
ATTLOGPTR	attlog;
{
	if ( attlog != (ATTLOGPTR) 0 ) 
	{
		if ( attlog->filename != (BPTR) 0 ) 
		{
			liberate( attlog->filename );
		}
		if ( attlog->entry != (ATTENTPTR) 0 )
			liberate_log_entries( attlog->entry );
#ifdef	ABAL4
		if ( attlog->remote )
		{
			detach_remote_program( attlog );
		}
		else
		{
#endif
#ifndef	BEFORE_131195
			if ( attlog->procedures != (BPTR) 0 )
				liberate_procedure_table( attlog->procedures, attlog->procmaxid );
#endif
			if ( attlog->handle != EX_UNUSED_HANDLE )
				CloseTcodeFile( attlog->handle );
#ifdef	DEBUGGER
			if ( attlog->debug != (VPTR) 0 )
				symbolic_detachment( attlog->debug );
#endif
#ifdef	ABAL4
		}
#endif
		liberate( attlog );
	}
	return;
}

/*	--------------------	*/
/*	liberate_attachments	*/
/*	--------------------	*/
VOID	liberate_attachments()
{
	ATTLOGPTR	attlog;

	while ((attlog = AttachmentLog) != (ATTLOGPTR) 0) 
	{
		AttachmentLog = attlog->next;
		liberate_for_log( attlog );
	}
	return;
}

/*	-------------------	*/
/*	restore_attach_host	*/
/*	-------------------	*/
static	VOID	restore_attach_host( EXAWORD hil, EXAWORD htg, EXAWORD hws )
{
#ifdef	VERSION666
	ISLOCAL=hil;
	TOGLOBAL=htg;
	WORDSIZE=hws;
#endif
	return;
}

EXAWORD	attach_log_header( attlog )
ATTLOGPTR	attlog;
{
	BPTR	fdex;
	EXAWORD	dcrypt;
	EXAWORD	status;
#ifdef	VERSION_XX
	EXAWORD	holdislocal=ISLOCAL;
	EXAWORD	holdtoglobal=TOGLOBAL;
	EXAWORD	holdwordsize=WORDSIZE;
#endif
	/* Load Tcode Header */
	/* ----------------- */
	if (SectRead((EX_FILE_HANDLE) attlog->handle,(BPTR) askbuf, ASKBUFMAX,0) == MOINS_UN)
		return( SOFTERROR ); 

	fdex  = (BPTR) askbuf;

	status = version_verification( *fdex, *(fdex+1), *(fdex+2), '2' );

#ifdef	VERSION_XX
	attlog->islocal=ISLOCAL;
#ifdef	ABAL64
	if ( *fdex >= '4' )
		WORDSIZE = WORD64SIZE;
	else
#endif
	if ( *fdex >= '3' )
		WORDSIZE=WORD32SIZE;
	else	WORDSIZE=WORD16SIZE;
	attlog->wordsize=WORDSIZE;
#endif

	if (status == SOFTERROR ) 
	{
#ifdef	VERSION_XX
		restore_attach_host(holdislocal,holdtoglobal,holdwordsize);
#endif
		return( SOFTERROR );
	}

	/* Collect Decryption Code */
	/* ----------------------- */
	dcrypt 		=	TcodeWord16( (fdex + ((21 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 62 */ ) );

	/* Decryptage des informations essentielles */
	/* ---------------------------------------- */
	if (( dcrypt != 0 ) && ( dcrypt != MOINS_UN ))
		(VOID) abal_crypt(dcrypt,(BPTR) (fdex + TCPREFIX),((21*WORDSIZE)+(2*BYTESIZE)),0);

	/* Ensure correct translation */
	/* -------------------------- */
	if ( *(fdex + 0x0013) != 0 ) 
	{
		err_val = EXER_BINAIRE;
#ifdef	VERSION_XX
		restore_attach_host(holdislocal,holdtoglobal,holdwordsize);
#endif
		return( SOFTERROR );
	}

	/* Collect  Information */
	/* -------------------- */
#ifdef	VERSION666
	attlog->sgct = Tcodeword( (fdex + (( 1 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 0x0016 */ ) );
	attlog->lgct = Tcodeword( (fdex + (( 2 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 0x0018 */ ) );
	attlog->sgdt = Tcodeword( (fdex + (( 3 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 0x001A */ ) ); 
	attlog->lgdt = Tcodeword( (fdex + (( 4 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 0x001C */ ) ); 
	attlog->sgpt = Tcodeword( (fdex + (( 9 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 0x0026 */ ) ); 
	attlog->lgpt = Tcodeword( (fdex + ((10 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 0x0028 */ ) );
	attlog->sglt = Tcodeword( (fdex + ((24 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 0x0044 */ ) );
	attlog->lglt = Tcodeword( (fdex + ((25 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 0x0046 */ ) );
	attlog->sgpx = Tcodeword( (fdex + ((35 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 0x0046 */ ) );
	attlog->lgpx = Tcodeword( (fdex + ((36 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 0x0046 */ ) );
#else
	attlog->sgct = Tcodeword( (fdex + 0x0016 ) ); 
	attlog->lgct = Tcodeword( (fdex + 0x0018 ) ); 
	attlog->sgdt = Tcodeword( (fdex + 0x001A ) ); 
	attlog->lgdt = Tcodeword( (fdex + 0x001C ) ); 
	attlog->sgpt = Tcodeword( (fdex + 0x0026 ) ); 
	attlog->lgpt = Tcodeword( (fdex + 0x0028 ) );
	attlog->sglt = 	Tcodeword( (fdex + 0x0044 ) );
	attlog->lglt = Tcodeword( (fdex + 0x0046 ) );
#endif
	attlog->procmaxid = ( attlog->lgpt / (8*WORDSIZE) );

	/* Correct for old ATR/ALD bug : Length of DLT is in sectors MERDE */
	/* --------------------------------------------------------------- */
	if ((attlog->lglt != 0) && ( attlog->lglt != MOINS_UN ))
		attlog->lglt *= TCODEBLOCK;

#ifdef	DEBUGGER
	attlog->dbok = ( *( fdex + 0x0012 ) & 1 );
#endif
#ifdef	VERSION_XX
	restore_attach_host(holdislocal,holdtoglobal,holdwordsize);
#endif

	return( GOODRESULT );
}

/*
 *	-------------------------------------------------------
 *	Handling of remote ressources for distributed execution
 *	-------------------------------------------------------
 */
#ifdef	ABAL_REMOTE
#include "exremote.c"
#endif	/* ABAL_REMOTE */

/*
 *	---------------------------------------------
 *	A L L O C A T E _ F O R _ L O G  ( filename )
 *	---------------------------------------------
 *
 *	This function creates a new attachment log node.
 *
 *		- Allocation of the node, 
 *		- allocation and storage of the filename
 *		- opening of attachement tcode program file
 *		- reads tcode header and collects information
 *		- insertion at top of log list
 *
 *		NB: the entry field is not allocated !
 *
 *	--> returns log node pointer or ATTLOGPTR NULL
 *
 */	

ATTLOGPTR	allocate_for_log( attnfic )
BPTR		attnfic;
{
	ATTLOGPTR	attlog;
	EXAWORD		local_error;

	if ((attlog = (ATTLOGPTR) allocate( sizeof( struct attachment_log ) )) != (ATTLOGPTR) 0) 
	{
		if ((attlog->filename = (BPTR) allocate( strlen((BPTR) attnfic) + 1 )) != (BPTR) 0) 
		{
			memcpy( (BPTR) attlog->filename,(BPTR) attnfic, strlen((BPTR)attnfic)+1 );
			attlog->entry  = (ATTENTPTR) 0;
			attlog->procmaxid   = 0;
			attlog->procedures  = (BPTR) 0;
			attlog->callbacks   = (BPTR) 0;
			attlog->prev   = (ATTLOGPTR) 0;
#ifdef	DEBUGGER
			attlog->debug  = (VPTR) 0;
			attlog->dbok   = 0;
#endif
#ifdef	VERSION_XX
			attlog->islocal=ISLOCAL3;
#ifdef	VERSION666
			attlog->wordsize=WORD16SIZE;
#else
			attlog->wordsize= WORDSIZE;
#endif
#endif
#ifdef	ABAL_REMOTE
			attlog->remote = (EXREMOTEPTR *) 0;
			if ( is_remote_attachment((BPTR) attlog->filename) )
			{
				if ( attach_remote_header( attlog ) ) 
				{
					attlog->wordsize = WORDSIZE;
					if ((attlog->next = AttachmentLog) != (ATTLOGPTR) 0)
						attlog->next->prev = attlog;
					AttachmentLog  = attlog;
					return( attlog );
				}
				else	
				{
					liberate_for_log( attlog );
					err_val = 136;
					return((ATTLOGPTR) 0);
				}
			}
			else 
#endif
			if ((attlog->handle = open_tcode_file((BPTR) attnfic )) != EX_UNUSED_HANDLE ) 
			{
				if ( attach_log_header( attlog ) ) 
				{
					if ((attlog->next = AttachmentLog) != (ATTLOGPTR) 0)
						attlog->next->prev = attlog;
					AttachmentLog  = attlog;
					return( attlog );
				}
				else
				{
					liberate_for_log( attlog );
					err_val = 136;
					return((ATTLOGPTR) 0);
					}
				}
			else	local_error = 40;
			liberate( attlog->filename );
			}
		else	local_error = 27;
		liberate( attlog );
		}
	else	local_error = 27;
	err_val = local_error;
	return((ATTLOGPTR) 0);
}

/*	------------------	*/
/*	allocate_for_entry	*/
/*	------------------	*/
ATTENTPTR	allocate_for_entry()
{
	ATTENTPTR	attent;

	if ((attent = (ATTENTPTR) allocate( sizeof( struct attachment_entry ) )) != (ATTENTPTR) 0) {
		attent->context = (OVLOBJPTR) 0;
		attent->ipt     = (BPTR) 0;
		attent->next    = (ATTENTPTR) 0;
		}
	else	err_val = 27;
	return( attent );
}

/*	--------------------	*/
/*	allocate_for_context	*/
/*	--------------------	*/
OVLOBJPTR	allocate_for_context( attlog )
ATTLOGPTR	attlog;
{
	OVLOBJPTR	context;

	/* Allocate Context controller */
	/* --------------------------- */
	if (( context = (OVLOBJPTR) allocate( sizeof( struct overlay_object ))) != (OVLOBJPTR) 0) 
	{
		context->handle      = attlog->handle;
		context->procmaxid   = 0;
#ifdef	VERSION_XX
		context->islocal     = attlog->islocal;
#ifdef	VERSION666
		context->wordsize    = attlog->wordsize;
#else
		context->wordsize= WORDSIZE;
#endif
#else
		context->wordsize= WORDSIZE;
#endif
#ifdef	ABAL_REMOTE
		context->remote	     = attlog->remote;
#endif
		context->filename    = attlog->filename;
		context->constants   = (BPTR) 0;
		context->variables   = (BPTR) 0;
		context->descriptors = (BPTR) 0;
		context->procedures  = (BPTR) 0;
		context->callbacks  = (BPTR) 0;
		context->libraries   = (BPTR) 0;
		context->nbdll       = 0;
		context->ipt         = (BPTR) 0;
		context->master	     = (VPTR) attlog;
		context->special=1;
	}
	else	err_val = 27;
	return( context );
}

/*	--------------	*/
/*	attach_compare	*/
/*	--------------	*/
EXAWORD	attach_compare( aptr, bptr )
BPTR	aptr;
BPTR	bptr;
{
	while ((*aptr ) && ( *bptr))
		if (*(aptr++) != *(bptr++))
			return(0);
	if (*(aptr++) != *(bptr++))
		return( 0 );
	else	return( 1 );
}
	
/*	-------------------	*/
/*	is_already_attached	*/
/*	-------------------	*/
ATTLOGPTR	is_already_attached( attnfic )
BPTR		attnfic;
{
	ATTLOGPTR	attlog=AttachmentLog;

	while (attlog != (ATTLOGPTR) 0) 
	{
		if ( attach_compare( attnfic, attlog->filename ) )
#ifdef	ABAL_REMOTE
			if (!( attlog->remote ))
#endif
				break;
		attlog = attlog->next;
	}
	return( attlog );
}

/*	------------------	*/
/*	attachment_failure	*/
/*	------------------	*/
EXAWORD	attachment_failure( attlog, attent, holdhandle, hws )
ATTLOGPTR	attlog;
ATTENTPTR	attent;
EX_FILE_HANDLE	holdhandle;
EXAWORD		hws;
{
	EXAWORD	local_error=err_val;

	if ( attent != (ATTENTPTR) 0 )
		liberate_log_entry( attent );		

	if ( attlog->entry == (ATTENTPTR) 0 )
		release_attachment_log( attlog );

	if ( holdhandle != EX_UNUSED_HANDLE )
		TcodeFileHandle = holdhandle;

#ifdef	VERSION666
	WORDSIZE = hws;
#endif
	err_val = local_error;
	return( SOFTERROR );
}

/*	--------------------------	*/
/*	allocate_indirection_table	*/
/*	--------------------------	*/
BPTR	allocate_indirection_table( proc_nombre, context, ws)
EXAWORD	proc_nombre;
BPTR	context;
EXAWORD	ws;
{
	BPTR	result;
	EXAWORD	thisproc;
	EXAWORD	indent;
	EXAWORD	SizeIdt;
#ifdef	VERSION666
	EXAWORD	hWS=WORDSIZE;
#ifdef	ABAL64
	EXAWORD	hPS=PTRSIZE;
	PTRSIZE = ABALPTRSIZE;
#endif
	WORDSIZE = ws;
#endif
	SizeIdt = (WORDSIZE+PTRSIZE);
	if ((result = allocate( (proc_nombre * SizeIdt ) )) != (BPTR) 0) 
	{
		for (indent=0, thisproc = 0; proc_nombre != 0; proc_nombre-- ) 
		{
			establish_pointer_variable((BPTR) (result+indent),(BPTR) context, ALLOCATED_POINTER );
			TcodePmot( (result+indent+PTRSIZE), thisproc );
			indent   += SizeIdt;
			thisproc += (8*WORDSIZE);
		}
	}
	else	err_val = 27;
#ifdef	VERSION666
	WORDSIZE = hWS;
#ifdef	ABAL64
	PTRSIZE = hPS;
#endif
#endif
	return( result );
}

/*
 * 	L O A D _ O V E R L A Y _ P R O C E D U R E S 
 *	---------------------------------------------
 *	This is required by ABAL 32 bit to ensure correct
 *	WORDSIZE value for procedure table loading.
 *
 */

static	BPTR	load_overlay_procedures( EXAWORD nb, BPTR tptr, EXAWORD ws )
{
	BPTR	rptr;
#ifdef	VERSION666
	EXAWORD	hws=WORDSIZE;
	ws = ws;
#endif
	rptr = load_tcode_procedures( nb, tptr );

#ifdef	VERSION666
	WORDSIZE=hws;
#endif
	return( rptr );
}

static	BPTR	load_overlay_callbacks( EXAWORD s, EXAWORD l , EXAWORD ws )
{
	BPTR	rptr;
#ifdef	VERSION666
	EXAWORD	hws=WORDSIZE;
	ws = ws;
#endif
	rptr = load_tcode_callbacks(s,l);

#ifdef	VERSION666
	WORDSIZE=hws;
#endif
	return( rptr );
}

/*
 *	I N I T I A L I S E _ O B J E C T _ M E T H O D _ T A B L E
 *	-----------------------------------------------------------
 *	This function performs the multiple PROC PTR operations
 *	required to point the various method table entries to the
 *	corresponding IMT entry of the following structure 
 *	
 *		ABALPTR	pointer_to_context 
 *		EXAWORD	procedure_identity;
 *
 */
	
static	VOID	initialise_object_method_table(
		EXAWORD proc_nombre,
		BPTR	methods,
		BPTR	tptr,
		EXAWORD	ws,
		EXAWORD	ptype )
{
	for ( ; proc_nombre > 0; proc_nombre-- ) {
		establish_pointer_variable( methods,(BPTR) tptr, ptype );
		methods += PTRSIZE;
		tptr    += (ws+PTRSIZE);
		}
	return;
}

/*
 *	O V E R L A Y _ O B J E C T _ A T T A C H M E N T 
 *	-------------------------------------------------
 *
 */

EXAWORD	overlay_object_attachment( attnfic, result )
BPTR	attnfic;
BPTR	result;
{
	EXAWORD		methodtype=PROGRAM_POINTER;
	ATTLOGPTR	attlog=(ATTLOGPTR) 0;
	ATTENTPTR	attent=(ATTENTPTR) 0;
	ATTENTPTR	cpyent=(ATTENTPTR) 0;
	OVLOBJPTR	context=(OVLOBJPTR) 0;
	EXAWORD		proc_nombre=0;
	BPTR		methods=(BPTR) 0;
	BPTR		tptr;
	EXAWORD		newatt=0;
	EX_FILE_HANDLE	HoldHandle=EX_UNUSED_HANDLE;
	EXAWORD		HoldWordSize=WORDSIZE;

#ifdef	DEBUGGER
#ifdef	UNIX
	VPTR	symbolic_attachment();
#else
	VPTR	symbolic_attachment(BPTR);
#endif
#endif

	/* Collect existing OR create new LOG node */
	/* --------------------------------------- */
	if (((attlog = is_already_attached( attnfic )) == (ATTLOGPTR) 0)
	&&  ((attlog = allocate_for_log( attnfic )) == (ATTLOGPTR) 0 ))
		return( SOFTERROR );

	if ( attlog->entry == (ATTENTPTR) 0 )
	{
		newatt = 1;
	}
	else
	{
		newatt = 0;
	}

	/* Create context control entry */
	/* ---------------------------- */
	if (((attent = allocate_for_entry()) == (ATTENTPTR) 0)
	||  ((attent->context = allocate_for_context( attlog )) == (OVLOBJPTR) 0))
		return( attachment_failure( attlog, attent, HoldHandle ) );


	/* Prepare for Loading */
	/* ------------------- */
	HoldHandle = TcodeFileHandle;
	HoldWordSize=WORDSIZE;
#ifdef	VERSION666
	WORDSIZE = attent->context->wordsize;
#endif
	TcodeFileHandle = attlog->handle;
	cpyent = attlog->entry;

	/* Load or Share Overlay Constants */
	/* ------------------------------- */
	if ((attlog->sgct != MOINS_UN) && (attlog->sgct != 0))
	{
		if (cpyent == (ATTENTPTR) 0)
		{
#ifdef	MMAP_OPTIMISED
			if (!(attent->context->constants = (BPTR) kode_load( attlog->sgct, attlog->lgct )))
#else
			if (((attent->context->constants = (BPTR) allocate( attlog->lgct )) == (BPTR) 0)
			||  (kode_b_lode(attent->context->constants, attlog->sgct, attlog->lgct) == MOINS_UN ))
#endif
				return( attachment_failure( attlog, attent, HoldHandle,HoldWordSize ) );
		}
		else	attent->context->constants = cpyent->context->constants;
	}

	/* Load Data table and allocate Global DATA : OBJECT CONTAINER */
	/* ----------------------------------------------------------- */
	if ((attlog->sgdt != MOINS_UN) && (attlog->sgdt != 0))
	{
#ifdef	MMAP_OPTIMISED
		if (!(attent->context->descriptors = (BPTR) kode_lode( attlog->sgdt, attlog->lgdt) ))
#else
		if (((attent->context->descriptors = (BPTR) allocate( attlog->lgdt )) == (BPTR) 0)
		||  (kode_b_lode( attent->context->descriptors, attlog->sgdt, attlog->lgdt) == MOINS_UN ))
#endif
			return( attachment_failure( attlog, attent, HoldHandle,HoldWordSize ) );

		if ( cpyent == (ATTENTPTR) 0 )
			attlog->lgds = Tcodeword((attent->context->descriptors + (2*WORDSIZE))); 

		if ((attent->context->variables = dynamic_object_allocation( attlog->lgds )) == (BPTR) 0)
			return( attachment_failure( attlog, attent, HoldHandle,HoldWordSize ) );

	}

/* #ifdef	VERSION666	*/

	/* Load or Share Dynamic Library Table */
	/* ----------------------------------- */
	if ((attlog->sglt != MOINS_UN) && (attlog->sglt != 0))
	{
		if (cpyent == (ATTENTPTR) 0)
		{
#ifdef	MMAP_OPTIMISED
			if (!(tptr = (BPTR) kode_lode( attlog->sglt, attlog->lglt) ))
#else
			if (((tptr = (BPTR) allocate( attlog->lglt )) == (BPTR) 0)
			||  (kode_b_lode( tptr, attlog->sglt, attlog->lglt) == MOINS_UN ))
#endif
				return( attachment_failure( attlog, attent, HoldHandle, HoldWordSize ) );
			attent->context->nbdll = Tcodeword( (tptr) );
			if ( attent->context->nbdll != 0 )
				if ((attent->context->libraries = (BPTR) attach_tcode_libraries(tptr)) == (BPTR) 0)
					return( attachment_failure( attlog, attent, HoldHandle, HoldWordSize ) );
			liberate( tptr );
		}
		else	attent->context->libraries = cpyent->context->libraries;
	}
	
/* #endif */

	/* Allocate for table of Procedure pointers */
	/* ---------------------------------------- */
	if ((methods = dynamic_object_allocation(((attent->context->procmaxid = attlog->procmaxid ) * PTRSIZE ))) == (BPTR) 0)
		return( attachment_failure( attlog, attent, HoldHandle,HoldWordSize ) );

	proc_nombre = attent->context->procmaxid;

	if ( newatt ) 
	{
		/* Allocate and load Tcode File Procedure Information */
		/* -------------------------------------------------- */
#ifdef	MMAP_OPTIMISED
		if (!(tptr = (BPTR) kode_lode( attlog->sgpt, attlog->lgpt) ))
#else
		if (((tptr = (BPTR) allocate( attlog->lgpt )) == (BPTR) 0)
		||  (kode_b_lode( tptr, attlog->sgpt, attlog->lgpt) == MOINS_UN ))
#endif
			return( attachment_failure( attlog, attent, HoldHandle, HoldWordSize ) );

	}

	/* Allocate Indirect Procedure Table IPT */
	/* ------------------------------------- */
	if ((attent->ipt = (BPTR) allocate_indirection_table(proc_nombre , attent->context, attent->context->wordsize )) == (BPTR) 0)
	{
		liberate( tptr );
		return( attachment_failure( attlog, attent, HoldHandle, HoldWordSize ) );
	}

	if ( newatt ) 
	{
#ifdef	ABAL_REMOTE
		if (!( attlog->remote ))
		{
#endif
			/* Now Load Actual Procedure Table as for Normal Program */
			/* ----------------------------------------------------- */
			if (( attlog->procedures = (BPTR) load_overlay_procedures( proc_nombre , tptr, attent->context->wordsize )) == (BPTR) 0) 
			{
				liberate( tptr );
				liberate( attent->ipt );
				return( attachment_failure( attlog, attent, HoldHandle, HoldWordSize ) );
			}
			else 	attlog->callbacks = (BPTR) load_overlay_callbacks( attlog->sgpx, attlog->lgpx, attent->context->wordsize );
			liberate( tptr );
			methodtype = PROGRAM_POINTER;
#ifdef	ABAL_REMOTE
		}
		else	methodtype = REMOTE_POINTER;
#endif
	}

	attent->context->procedures = attlog->procedures;
	attent->context->callbacks  = attlog->callbacks;
	tptr = attent->ipt; 

	/* Attach METHOD TABLE     to CLIENT PROGRAM storage */
	/* ------------------------------------------------- */
	establish_pointer_variable( result, methods, ALLOCATED_POINTER );

	/* Now initialise Object Methods Table */
	/* ----------------------------------- */
	initialise_object_method_table( proc_nombre, methods,tptr, attent->context->wordsize, methodtype );

	/* Attach OBJECT CONTAINER to CLIENT PROGRAM storage */
	/* ------------------------------------------------- */
	establish_pointer_variable( (result+PTRSIZE), attent->context->variables, ALLOCATED_POINTER );

	/* Store attachment context in Log list */
	/* ------------------------------------ */
	attent->context->ipt = attent->ipt;
	attent->next  = cpyent; 
	attlog->entry = attent;	
	TcodeFileHandle = HoldHandle;
#ifdef	VERSION666
	WORDSIZE = HoldWordSize;
#endif
#ifdef	DEBUGGER
	if (( newatt ) 
	&& ( attlog->debug == (VPTR) 0) 
	&& ( attlog->dbok )) {
		if ((attlog->debug = symbolic_attachment( (BPTR) attlog->filename )) == (VPTR) 0)
			attlog->dbok = 0;
		}
#endif

	return( GOODRESULT );

}

#endif	/* _EXATTACH_C */
		/* ----------- */
