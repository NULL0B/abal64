/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1996 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXATTACH.C				*/
/*		Date 	:	09/05/1996				*/
/*		Version :	1.4c / 2.1d				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXATTACH_C
#define	_EXATTACH_C

#ifdef DEBUGGER
#include "exproto1.h"
#endif


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
	attmsg((BPTR) "liberate CONTEXT" );
	if ( context->descriptors != (BPTR) 0 )
		liberate( context->descriptors );
#ifdef	BEFORE_131195
	if ( context->procedures != (BPTR) 0 )
		liberate_procedure_table( context->procedures, context->procmaxid );
#endif
	liberate( context );
	return;
}

VOID	liberate_log_entry( attent )
ATTENTPTR	attent;
{
	attmsg((BPTR) "liberate_log_entry()");
	if (attent != (ATTENTPTR) 0) {
		if ( attent->ipt != (BPTR) 0 ) {
			attmsg((BPTR) "liberate IPT");
			liberate( attent->ipt );
			}
		if ( attent->context != (OVLOBJPTR) 0 )
			liberate_log_context( attent->context );
		attmsg((BPTR) "liberate ATTENT" );
		liberate( attent );
		}
	return;
}

VOID	liberate_log_entries( entries )
ATTENTPTR	entries;
{
	ATTENTPTR	attent;
	attmsg((BPTR) "liberate_log_entries()");
	while ((attent = entries) != (ATTENTPTR) 0) {
		entries = entries->next;
		if ( entries == (ATTENTPTR) 0) {
			if ( attent->context->constants != (BPTR) 0 )
				liberate( attent->context->constants );
			if ( attent->context->libraries != (BPTR) 0 )
				LibFuse( attent->context->libraries, attent->context->nbdll );
			}
		liberate_log_entry( attent );
		}
	return;
}

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

EXAWORD	locate_and_release_log_entry( context )
OVLOBJPTR	context;
{
	ATTLOGPTR	attlog;
	ATTENTPTR	attent;
	ATTENTPTR	previous=(ATTENTPTR) 0;

	attmsg((BPTR) "locate_and_release_log_entry()");
	if (((attlog = (ATTLOGPTR) context->master) != (ATTLOGPTR) 0 ) 
	&&  ((attent = attlog->entry) != (ATTENTPTR) 0 )) {
		do  	{

			if ( attent->context == context ) {
				attmsg((BPTR) "Entry linkage removal");
				if ( previous == (ATTENTPTR) 0)
					attlog->entry  = attent->next;
				else	previous->next = attent->next;
				if (( attlog->entry == (ATTENTPTR) 0)
				&&  ( attent->context->constants != (BPTR) 0 ))
					liberate( attent->context->constants );
				liberate_log_entry( attent );
				if ( attlog->entry == (ATTENTPTR) 0 )
					release_attachment_log( attlog );
				return( 1 );
				}
			else	previous = attent;
			}
		while ((attent = attent->next) != (ATTENTPTR) 0);

		}

	attmsg((BPTR) "Context base liberation");
	liberate( context );
	return( 0 );
}

VOID	release_attachment_log_entry( iptbase )
BPTR	iptbase;
{
	OVLOBJPTR	context;
	attmsg((BPTR) "release_attachment_log_entry()");
	if ( iptbase != (BPTR) 0 ) {
		if (( context = (OVLOBJPTR) TcodeGetPointer((iptbase))) != (OVLOBJPTR) 0)
			if ( locate_and_release_log_entry( context ) )
				return;
		attmsg((BPTR) "IPT base liberation");
		liberate( iptbase );
		}
	return;
}

VOID	liberate_for_log( attlog )
ATTLOGPTR	attlog;
{
	attmsg((BPTR) "liberate_for_log()");
	if ( attlog != (ATTLOGPTR) 0 ) {
		if ( attlog->filename != (BPTR) 0 ) {
			attmsg((BPTR)  attlog->filename );
			liberate( attlog->filename );
			}
		if ( attlog->entry != (ATTENTPTR) 0 )
			liberate_log_entries( attlog->entry );
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
		liberate( attlog );
		}
	return;
}

VOID	liberate_attachments()
{
	ATTLOGPTR	attlog;

	attmsg((BPTR) "liberate_attachments()");

	while ((attlog = AttachmentLog) != (ATTLOGPTR) 0) {
		AttachmentLog = attlog->next;
		liberate_for_log( attlog );
		}
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
#endif
	/* Load Tcode Header */
	/* ----------------- */
	if (SectRead((EX_FILE_HANDLE) attlog->handle,(BPTR) askbuf, BLOCK,0) == MOINS_UN)
		return( SOFTERROR ); 

	fdex  = (BPTR) askbuf;

	status = version_verification( *fdex, *(fdex+1), *(fdex+2), '2' );
#ifdef	VERSION_XX
	attlog->islocal=ISLOCAL;
	ISLOCAL=holdislocal;
	TOGLOBAL=holdtoglobal;
#endif
	if (status == SOFTERROR )
		return( SOFTERROR );

	/* Collect Decryption Code */
	/* ----------------------- */
	dcrypt 		=	Tcodeword( (fdex + 62 ) );

	/* Decryptage des informations essentielles */
	/* ---------------------------------------- */
	if (( dcrypt != 0 ) && ( dcrypt != MOINS_UN ))
		(VOID) exa_crypt(dcrypt,(BPTR) (fdex + 18),44,0);

	/* Ensure correct translation */
	/* -------------------------- */
	if ( *(fdex + 0x0013) != 0 ) {
		err_val = EXER_BINAIRE;
		return( SOFTERROR );
		}

	/* Collect  Information */
	/* -------------------- */
	attlog->sgct = Tcodeword( (fdex + 0x0016 ) );
	attlog->lgct = Tcodeword( (fdex + 0x0018 ) );
	attlog->sgdt = Tcodeword( (fdex + 0x001A ) );
	attlog->lgdt = Tcodeword( (fdex + 0x001C ) );
	attlog->sgpt = Tcodeword( (fdex + 0x0026 ) );
	attlog->lgpt = Tcodeword( (fdex + 0x0028 ) );
	attlog->sglt = Tcodeword( (fdex + 0x0044 ) );
	attlog->lglt = Tcodeword( (fdex + 0x0046 ) );
	attlog->procmaxid = ( attlog->lgpt / 16 );

	/* Correct for old ATR/ALD bug : Length of DLT is in sectors MERDE */
	/* --------------------------------------------------------------- */
	if ((attlog->lglt != 0) && ( attlog->lglt != MOINS_UN ))
		attlog->lglt *= BLOCK;

#ifdef	DEBUGGER
	attlog->dbok = ( *( fdex + 0x0012 ) & 1 );
#endif

	return( GOODRESULT );

}


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

	if ((attlog = (ATTLOGPTR) allocate( sizeof( struct attachment_log ) )) != (ATTLOGPTR) 0) {
		if ((attlog->filename = (BPTR) allocate( strlen((BPTR) attnfic) + 1 )) != (BPTR) 0) {
			memcpy( (BPTR) attlog->filename,(BPTR) attnfic, strlen((BPTR)attnfic)+1 );
			attlog->entry  = (ATTENTPTR) 0;
			attlog->procmaxid   = 0;
			attlog->procedures  = (BPTR) 0;
			attlog->prev   = (ATTLOGPTR) 0;
#ifdef	DEBUGGER
			attlog->debug  = (VPTR) 0;
			attlog->dbok   = 0;
#endif
#ifdef	VERSION_XX
			attlog->islocal=ISLOCAL3;
#endif
			if ((attlog->handle = open_tcode_file((BPTR) attnfic )) != EX_UNUSED_HANDLE ) {
				if ( attach_log_header( attlog ) ) {
					if ((attlog->next = AttachmentLog) != (ATTLOGPTR) 0)
						attlog->next->prev = attlog;
					AttachmentLog  = attlog;
					return( attlog );
					}
				else	{
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

OVLOBJPTR	allocate_for_context( attlog )
ATTLOGPTR	attlog;
{
	OVLOBJPTR	context;

	/* Allocate Context controller */
	/* --------------------------- */
	if (( context = (OVLOBJPTR) allocate( sizeof( struct overlay_object ))) != (OVLOBJPTR) 0) {
		context->handle      = attlog->handle;
		context->procmaxid   = 0;
#ifdef	VERSION_XX
		context->islocal     = attlog->islocal;
#endif
		context->constants   = (BPTR) 0;
		context->variables   = (BPTR) 0;
		context->descriptors = (BPTR) 0;
		context->procedures  = (BPTR) 0;
		context->libraries   = (BPTR) 0;
		context->nbdll       = 0;
		context->ipt         = (BPTR) 0;
		context->master	     = (VPTR) attlog;
		}
	else	err_val = 27;
	return( context );
}

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
	

ATTLOGPTR	is_already_attached( attnfic )
BPTR		attnfic;
{
	ATTLOGPTR	attlog=AttachmentLog;

	while (attlog != (ATTLOGPTR) 0) {
		if ( attach_compare( attnfic, attlog->filename ) )
			break;
		else	attlog = attlog->next;
		}
	return( attlog );

}

EXAWORD	attachment_failure( attlog, attent, holdhandle )
ATTLOGPTR	attlog;
ATTENTPTR	attent;
EX_FILE_HANDLE	holdhandle;
{
	EXAWORD	local_error=err_val;

	attmsg((BPTR)  "Attachment_Failure" );

	if ( attent != (ATTENTPTR) 0 )
		liberate_log_entry( attent );		

	if ( attlog->entry == (ATTENTPTR) 0 )
		release_attachment_log( attlog );

	if ( holdhandle != EX_UNUSED_HANDLE )
		TcodeFileHandle = holdhandle;

	err_val = local_error;
	return( SOFTERROR );
}

BPTR	allocate_indirection_table( proc_nombre, context )
EXAWORD	proc_nombre;
BPTR	context;
{
	BPTR	result;
	EXAWORD	thisproc;
	EXAWORD	indent;

	if ((result = allocate( (proc_nombre * _SIZE_ATTACH_PTR) )) != (BPTR) 0) {
	
		for (indent=0, thisproc = 0; proc_nombre != 0; proc_nombre-- ) {
			establish_pointer_variable((BPTR) (result+indent),(BPTR) context, ALLOCATED_POINTER );
			TcodePmot( (result+indent+5), thisproc );
			indent += _SIZE_ATTACH_PTR;
			thisproc += 16;
			}
		}
	else	err_val = 27;

	return( result );
}



EXAWORD	overlay_object_attachment( attnfic, result )
BPTR	attnfic;
BPTR	result;
{
	ATTLOGPTR	attlog=(ATTLOGPTR) 0;
	ATTENTPTR	attent=(ATTENTPTR) 0;
	ATTENTPTR	cpyent=(ATTENTPTR) 0;
	OVLOBJPTR	context=(OVLOBJPTR) 0;
	EXAWORD		proc_nombre=0;
	BPTR		methods=(BPTR) 0;
	BPTR		tptr;
	EXAWORD		newatt=0;
	EX_FILE_HANDLE	HoldHandle=EX_UNUSED_HANDLE;
#ifdef	DEBUGGER
#ifdef	UNIX
	VPTR	symbolic_attachment();
#else
	VPTR	symbolic_attachment(BPTR);
#endif
#endif

	attmsg((BPTR) "overlay_object_attachment" );
	attmsg((BPTR) attnfic );
	attmsg((BPTR) "allocate_for_log");

	/* Collect existing OR create new LOG node */
	/* --------------------------------------- */
	if (((attlog = is_already_attached( attnfic )) == (ATTLOGPTR) 0)
	&&  ((attlog = allocate_for_log( attnfic )) == (ATTLOGPTR) 0 ))
		return( SOFTERROR );

	if ( attlog->entry == (ATTENTPTR) 0 ) {
		attmsg((BPTR) "initial attachement");
		newatt = 1;
		}
	else	{
		newatt = 0;
		attmsg((BPTR) "secondary attachement");
		}

	attmsg((BPTR) "allocate_for_entry");

	/* Create context control entry */
	/* ---------------------------- */
	if (((attent = allocate_for_entry()) == (ATTENTPTR) 0)
	||  ((attent->context = allocate_for_context( attlog )) == (OVLOBJPTR) 0))
		return( attachment_failure( attlog, attent, HoldHandle ) );


	/* Prepare for Loading */
	/* ------------------- */
	HoldHandle = TcodeFileHandle;
	TcodeFileHandle = attlog->handle;
	cpyent = attlog->entry;

	attmsg((BPTR) "Constants loading");

	/* Load or Share Overlay Constants */
	/* ------------------------------- */
	if ((attlog->sgct != MOINS_UN) && (attlog->sgct != 0)) {
		if (cpyent == (ATTENTPTR) 0) {
			if (((attent->context->constants = (BPTR) allocate( attlog->lgct )) == (BPTR) 0)
			||  (kode_b_lode(attent->context->constants, attlog->sgct, attlog->lgct) == MOINS_UN ))
				return( attachment_failure( attlog, attent, HoldHandle ) );

			}
		else	attent->context->constants = cpyent->context->constants;
		}


	attmsg((BPTR) "variable loading");

	/* Load Data table and allocate Global DATA : OBJECT CONTAINER */
	/* ----------------------------------------------------------- */
	if ((attlog->sgdt != MOINS_UN) && (attlog->sgdt != 0)) {

		if (((attent->context->descriptors = (BPTR) allocate( attlog->lgdt )) == (BPTR) 0)
		||  (kode_b_lode( attent->context->descriptors, attlog->sgdt, attlog->lgdt) == MOINS_UN ))
			return( attachment_failure( attlog, attent, HoldHandle ) );

		if ( cpyent == (ATTENTPTR) 0 )
			attlog->lgds = Tcodeword((attent->context->descriptors + 4)); 

		if ((attent->context->variables = dynamic_object_allocation( attlog->lgds )) == (BPTR) 0)
			return( attachment_failure( attlog, attent, HoldHandle ) );

		}

#ifdef	_ABAL_DLL_PRIVATE

	attmsg((BPTR) "library loading" );

	/* Load or Share Dynamic Library Table */
	/* ----------------------------------- */
	if ((attlog->sglt != MOINS_UN) && (attlog->sglt != 0)) {
		if (cpyent == (ATTENTPTR) 0) {
			if (((tptr = (BPTR) allocate( attlog->lglt )) == (BPTR) 0)
			||  (kode_b_lode( tptr, attlog->sglt, attlog->lglt) == MOINS_UN ))
				return( attachment_failure( attlog, attent, HoldHandle ) );
			attent->context->nbdll = Tcodeword( (tptr) );
			if ( attent->context->nbdll != 0 )
				if ((attent->context->libraries = (BPTR) load_tcode_libraries(tptr)) == (BPTR) 0)
					return( attachment_failure( attlog, attent, HoldHandle ) );
			liberate( tptr );
			}
		else	attent->context->libraries = cpyent->context->libraries;
		}
	
#endif

	attmsg((BPTR) "methods allocation");
	/* Allocate for table of Procedure pointers */
	/* ---------------------------------------- */
	if ((methods = dynamic_object_allocation(((attent->context->procmaxid = attlog->procmaxid ) * 5 ))) == (BPTR) 0)
		return( attachment_failure( attlog, attent, HoldHandle ) );

	proc_nombre = attent->context->procmaxid;

	attmsg((BPTR) "tcode proctable");

	if ( newatt ) {

		/* Allocate and load Tcode File Procedure Information */
		/* -------------------------------------------------- */
		if (((tptr = (BPTR) allocate( attlog->lgpt )) == (BPTR) 0)
		||  (kode_b_lode( tptr, attlog->sgpt, attlog->lgpt) == MOINS_UN ))
			return( attachment_failure( attlog, attent, HoldHandle ) );

		}

	attmsg((BPTR) "IPT allocation");
	/* Allocate Indirect Procedure Table IPT */
	/* ------------------------------------- */
	if ((attent->ipt = (BPTR) allocate_indirection_table(proc_nombre , attent->context )) == (BPTR) 0) {
		liberate( tptr );
		return( attachment_failure( attlog, attent, HoldHandle ) );
		}

	if ( newatt ) {
		attmsg((BPTR) "load_tcode_procedures");
		/* Now Load Actual Procedure Table as for Normal Program */
		/* ----------------------------------------------------- */
		if ((attlog->procedures = (BPTR) load_tcode_procedures( proc_nombre , tptr )) == (BPTR) 0) {
			liberate( tptr );
			liberate( attent->ipt );
			return( attachment_failure( attlog, attent, HoldHandle ) );
			}
		liberate( tptr ); 
		}

	attent->context->procedures = attlog->procedures;

	tptr = attent->ipt; 

	/* Attach METHOD TABLE     to CLIENT PROGRAM storage */
	/* ------------------------------------------------- */
	establish_pointer_variable( result, methods, ALLOCATED_POINTER );

	/* Now initialise Object Methods Table */
	/* ----------------------------------- */
	for ( ; proc_nombre > 0; proc_nombre-- ) {
		establish_pointer_variable( methods,(BPTR) tptr, PROGRAM_POINTER );
		methods += 5;
		tptr    += _SIZE_ATTACH_PTR;
		}

	/* Attach OBJECT CONTAINER to CLIENT PROGRAM storage */
	/* ------------------------------------------------- */
	establish_pointer_variable( (result+5), attent->context->variables, ALLOCATED_POINTER );

	/* Store attachment context in Log list */
	/* ------------------------------------ */
	attent->context->ipt = attent->ipt;
	attent->next  = cpyent; 
	attlog->entry = attent;	
	TcodeFileHandle = HoldHandle;

#ifdef	DEBUGGER
	if (( newatt ) 
	&& ( attlog->debug == (VPTR) 0) 
	&& ( attlog->dbok )) {
		if ((attlog->debug = symbolic_attachment( (BPTR) attlog->filename )) == (VPTR) 0)
			attlog->dbok = 0;
		}
#endif
	attmsg((BPTR) "Success");

	return( GOODRESULT );

}

#endif	/* _EXATTACH_C */
	/* ----------- */
