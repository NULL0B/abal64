#define	DEBUG
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRINPUT.C				*/
/*		Version :	2.1d					*/
/*		Date	:	08/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRINPUT_C
#define	_TRINPUT_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include <string.h>		/* string functions */
#include "stdtypes.h"
#include "translat.h"
#include "trsymbol.h"
#include "trinput.h"
#include "troption.h"
#include "trabmsg.h"
#include "trdebug.h"
#include "trmalloc.h"
#include "triter.h"		
#include "trtables.h"	
#include "trparser.h"	
#include "trsyntax.h"	
#include "trclass.h"		
#include "trecho.h"		
#include "trabal.h"		
#include "trdirect.h"	
#include "trerrors.h"	
#include "fnparser.h"	
#include "trproc.h"		
#include "triof.h"		
#include "troutput.h"	

#ifdef WIN32
extern int OptIdra;
#endif


static	int	InputNesting=0;

static SOURCEPTR FreeInput=(SOURCEPTR) 0;


#ifndef	UNIX
#else
BPTR		context_filename();
WORD		prepare_filename();
BPTR		trace_error_context();
BPTR		resolve_definition();
TCVARPTR	lock_used_variables();
WORD		lock_used_resgisters();
LONG		list_file_offset();
WORD		verify_world_list();
#endif

VOID	drop_memory_source()
{

#ifdef	SWAP_CTRL
	VALUEBUF	vbuffer;
#else
	VALUEPTR	vbuffer;
#endif
	if ( Input->Source.Macro == (VALUEPTR) 0)
		return;

#ifdef	SWAP_CTRL
	if ((vbuffer = validate_buffer( Input->Source.Macro )) == (VALUEBUF) 0)
		return;
#else
	if ((vbuffer = Input->Source.Macro) == (VALUEPTR) 0)
		return;
#endif
	vbuffer->iread = 0;
	return;
}

static VOID	release_input( iptr )
SOURCEPTR	iptr;
{
	iptr->next = FreeInput;
	FreeInput = iptr;
	return;
}

WORD	liberate_for_input()
{
	SOURCEPTR	iptr;
	WORD		nombre=0;
	trace("liberate_for_input()\n");
	while ((iptr = FreeInput) != (SOURCEPTR) 0) {
		FreeInput = iptr->next;
		liberate( iptr );
		nombre++;
		}
	return( nombre );
}

WORD	drop_source_context()
{
	SOURCEPTR	sptr;
	trace("drop_source_context()\n");
	if (Input != (SOURCEPTR) 0) {
		sptr = Input->next;
		if (!( Input->Nature )) {
			trace("drop_file_context()\n");
			if ( Input->Source.Handle != (FILEPTR) 0) {
				InputNesting--;
				fclose( Input->Source.Handle );
				Input->Source.Handle = (FILEPTR) 0;
				}
			}
		else	{
			if ( Input->Nature == _INPUT_METHOD ) {
				trace("drop_method_context() : Parameters\n");
				if ( Input->Parameters != (VPTR) 0)
					liberate_method_parameters( Input->Parameters );
				trace("drop_method_context() : Label\n");
				if ( Input->Label != MOINS_UN )
					dcl_implicite_label( Input->Label );
				trace("drop_method_context() : Variables\n");
				if ( Input->Variables != (VPTR) 0 )
					unlock_used_variables( Input->Variables );
				trace("drop_method_context() : Registers\n");
				if ( Input->Registers != 0 )
					unlock_used_registers( Input->Registers );
				trace("drop_method_context() : Results\n");
				if ( Input->Results != (VPTR) 0 )
				 	unlock_used_results( Input->Results );
				}
			else	{
				trace("drop_other_context()\n");
				}
			if ( Input->LinePointer)
				set_parser_line_buffer( Input->LinePointer);
			(void)  restore_bal_comments( Input->BalComment );
			drop_memory_source();
			}

		release_input( Input );

		if ((Input = sptr) != (SOURCEPTR) 0)
			return(VRAI);
		}
	return(FAUX);
}

struct	end_of_file {
	int	Number;
	int	Line;
	} Eof = { -1,-1 };

VOID	symbolic_file_name( nombre, buffer )
WORD	nombre;
BPTR	buffer;
{
	SOURCEPTR	iptr;

	DBGFILEPTR	fptr=(DBGFILEPTR) 0;
	*buffer = 0;
	if ((fptr = SymbolicFile) != (DBGFILEPTR) 0) {
		do	{
			if (( fptr->number == nombre )
			&&  ( fptr->name   != (BPTR) 0)) {
				strcpy( buffer, fptr->name );
				return;
				}
			}
		while ((fptr = fptr->next) != (DBGFILEPTR) 0);
		}
	if ( Input != (SOURCEPTR) 0 ) {
		if ((iptr = Input->next) == (SOURCEPTR) 0)
			(void) prepare_filename( Input, context_filename(), OtrOption.Extension,(SOURCEPTR) 0);
		else	strcpy( buffer, iptr->Name );
		}
	return;
}

WORD	symbolic_file_number( token )
BPTR	token;
{
	DBGFILEPTR	fptr=(DBGFILEPTR) 0;
	DBGFILEPTR	lptr=(DBGFILEPTR) 0;
	WORD		h;

	if ((fptr = SymbolicFile) != (DBGFILEPTR) 0) {
		h = keyword_hash( token );
		do	{
			if (( fptr->name != (BPTR) 0)
			&&  ( h == fptr->hash )
			&&  ( compare_tokens( fptr->name, token ) ))
				return( fptr->number );
			else	lptr = fptr;
			}
		while ((fptr = fptr->next) != (DBGFILEPTR) 0);
		}
	if ((fptr = (DBGFILEPTR) allocate( sizeof( struct otr_debug_file ) )) != (DBGFILEPTR) 0) {
		fptr->next = (DBGFILEPTR) 0;
		fptr->name = allocate_for_string( token );
		fptr->hash = h;
		if ( lptr != (DBGFILEPTR) 0 ) {
			lptr->next = fptr;
			fptr->number = (lptr->number+1);
			}
		else	{
			SymbolicFile = fptr;
			fptr->number = 1;
			}
		return( fptr->number );
		}
	else	return( MOINS_UN );

}

WORD	pop_source_context(mode)
WORD	mode;
{
	trace("pop_source_context()\n");
	if ( mode ) 
		return( drop_source_context() );
	else	return(0);
}

WORD	recover_input_context()
{
	if ( Input )
		return( pop_source_context( Input->Status ) );
	else	return(0);
}

WORD	recover_source_context()
{
	SOURCEPTR	iptr;
	if ((!( Input->Status ))
	||  (( iptr = Input->next ) != (SOURCEPTR) 0)
	||  ( Input->LinePointer == (BPTR) 0 ))
		return( 0 );

	strcpy(	Input->Buffer, Input->LinePointer );
	Input->LinePointer = (BPTR) 0;
	strcpy( iptr->Buffer, Input->Buffer );
	iptr->Index = strlen( iptr->Buffer );
	drop_source_context();
	return( iptr->Index );
}

#ifdef	DEBUG_PRE_CONSTR
VOID		trace_value( master, message )
VALUEPTR	master;
BPTR		message;
{
#ifdef	SWAP_CTRL
	VALUEBUF	vbuffer;
#else
	VALUEPTR	vbuffer;
#endif
	sysprintf("\nTraceValueStart(%s)...\n",message);
	if ( master == (VALUEPTR) 0 ) {
		sysprintf("TraceValueVoid(%s)...\n",message);
		return;
		}
	while ( 1 ) {
#ifdef	SWAP_CTRL
		if ((vbuffer = validate_buffer( master )) == (VALUEBUF) 0)
			break;
#else
		if ((vbuffer = master) == (VALUEPTR) 0)
			break;
#endif
		else if ( vbuffer->iread < vbuffer->irite )
			sysprintf("%c",vbuffer->text[vbuffer->iread++] );
		else	{
			vbuffer->iread = 0;
			if ((master = vbuffer->next) == (VALUEPTR) 0)
				break;
			}
		}
	sysprintf("\n...TraceMacroEnd(%s)\n",message);
	return;
}
#endif
	
WORD	memory_source()
{

#ifdef	SWAP_CTRL
	VALUEBUF	vbuffer;
#else
	VALUEPTR	vbuffer;
#endif
	while ( 1 ) {
#ifdef	SWAP_CTRL
		if ((vbuffer = validate_buffer( Input->Source.Macro )) == (VALUEBUF) 0)
			return( MOINS_UN );
#else
		if ((vbuffer = Input->Source.Macro) == (VALUEPTR) 0)
			return( MOINS_UN );
#endif
		else if ( vbuffer->iread < vbuffer->irite )
			return( vbuffer->text[vbuffer->iread++] );
		else	{
			vbuffer->iread = 0;
			if ((Input->Source.Macro = vbuffer->next) == (VALUEPTR) 0)
				return( MOINS_UN );
			}
		}
}

WORD	xmemory_source()
{
	WORD	c;
	sysprintf("%c",(c=xmemory_source()));
	return( c );
}


WORD	get_source_character()
{
	WORD	c;
	BYTE	cc;
	if ( Input->Nature )
		c = memory_source();
	else if ( fread( & cc, 1,1 , Input->Source.Handle ) == 1 )
		c = (cc & 0x00FF);
	else	c = 0x001A; /* MOINS_UN; */
		
	if (( c ) && ( c != MOINS_UN ) && ( c != 0x001A ))
		Input->Indent++;

#ifndef	UNIX
	if ( c == '\n' )
		Input->Indent++;
#endif
	return(c);
}

static  WORD	ll_input_line()
{
	WORD	c;
	
	if (( Input == (SOURCEPTR) 0)
	||  ( Input->Source.Handle == (FILEPTR) 0))
		return( 0 );

	Input->Index = 0; 

	Input->LineStart = Input->Indent;
	
	trace("input_line()\n");

	while ( 1 ) {

		c = get_source_character();

		switch ((c)) {

			case	'\r'	: Input->Buffer[Input->Index++] = ' ';
					  break;
			case	0x001A	: Input->Lines++;
					  if (( Input->Index != 0 )
					  /*||  ( is_method_definition() )*/) {
						Input->Buffer[Input->Index++] = c;
						Input->Buffer[Input->Index] = 0;
						return( Input->Index );
						}
			case	MOINS_UN	:
			case	0	: if ( Input->Index == 0 ) {
						if (recover_source_context())
							return( Input->Index );
						else	return( 0 );
						}
					  else	{
						Input->Buffer[Input->Index++] = ' ';
						Input->Buffer[Input->Index++] = 0x001A;
						return( Input->Index );
						}

			case	'\n'	: Input->Lines++;
					  if (( Input->Index != 0 )
					  ||  ( is_method_definition() )) {
						Input->Buffer[Input->Index++] = c;
						Input->Buffer[Input->Index] = 0;
						return( Input->Index );
						}
					  continue;

			default		: Input->Buffer[Input->Index++] = c;
					  break;
			}
		if ( Input->Index >= MAX_INPUT_LINE_BUFFER )
			return( 0 );
		}
	return(0);
}

WORD	input_line()
{
	WORD	status=0;
	if ((status = ll_input_line()) != 0) {
		if ( OtrOption.ListFlag & 1 )
			echo_code_line( Input->Buffer );
		if ( OtrOption.SourceTrace & 2 ) {
			if ( is_active_region() ) 
				echo_source_line( Input->Buffer );
			}
		}
	return( status );
}


BPTR	get_input_line()
{
	if ( input_line() != 0 )
		return( Input->Buffer );
	else	return( (BPTR) 0 );
}

VOID	echo_line_prefix()
{
	if ( Input != (SOURCEPTR) 0) {
		if (  verify_world_list() ) {
			fprintf( World->ListHandle,"%s(%u) ",Input->Name,Input->Lines);
			}
		else	{
			sysprintf("%s(%u) ",Input->Name,Input->Lines);
			}
		}
	echo_target_offset(World->ListHandle);
	return;
}

WORD	context_translation()
{
	WORD	status=0;
	while ( input_line() ) {
		if ((status = line_translation( Input->Buffer )) != 0)
			break;
		}

	return(status);
}


WORD	continue_translation(mode)
WORD	mode;
{
	WORD	status;
	trace("continue_translation()\n");
	Input->Status = mode; /* 1 : Auto Pop, 0 : Manual Pop */
	while ( input_line() ) {
		if (initialise_line_parser( Input->Buffer )) {
			if ((status = is_directive()) != MOINS_UN ) {
				if ((status = translate_directive(status)) != 0)
					return( status );
				}
			else if ((status = is_active_region()) != FAUX)
				break;
			}
		}
	return(0);
}



WORD	file_translation()
{
	WORD	status=0;
	trace("file_translation()\n");
	do	{
		if ((status = context_translation()) != 0)
			return( status );
		}
	while ( pop_source_context(1) );
	return( 0 );
}

SOURCEPTR	allocate_for_source()
{
	SOURCEPTR	sptr;
	trace("allocate_for_source()\n");

	if ((sptr = FreeInput) != (SOURCEPTR) 0)
		FreeInput = sptr->next;

	else if ((sptr = (SOURCEPTR) allocate( sizeof( struct otr_source ))) == (SOURCEPTR) 0)
		return( sptr );

		sptr->Source.Handle = (FILEPTR) 0;
		sptr->Status = 1;	/* Allows auto Pop of Input Contexts */
		sptr->Nature = _INPUT_FILE;	/* Default Input Type is File	     */
		sptr->Level  = 0;
		sptr->BalComment = 1;
		sptr->Lines  = 0L;
		sptr->Number = MOINS_UN;
		sptr->Indent = 0L;
		sptr->LineStart = 0L;
		sptr->LinePointer = (BPTR) 0;
		sptr->Parameters  = (VPTR) 0;
		sptr->Variables   = (VPTR) 0;
		sptr->Results     = (VPTR) 0;
		sptr->Registers   = 0;
		sptr->Object      = (VPTR) 0;
		sptr->Method      = (VPTR) 0;
		sptr->Label 	  = MOINS_UN;
		sptr->next        = (SOURCEPTR) 0;

	return( sptr );
}



WORD	evaluate_filename( filename )
BPTR	filename;
{
	BPTR	wptr=(BPTR) 0;
	BPTR	xptr=(BPTR) 0;
	BPTR	mptr=(BPTR) 0;
	WORD	i=0;
	WORD	j=0;
	WORD	status=0;
	while ( *(filename + i) ) {

		if (( *(filename + i) == '$' ) 
		&& ( *(filename + i + 1) == '(' )) {
			*(filename + i) = 0;
			if (( wptr == (BPTR) 0 )
			&&  ((wptr = allocate( 320 )) == (BPTR) 0))
				return( allocation_failure() );
			strcpy( wptr, filename );
			mptr = (filename + i + 2); 
			j = 0;
			while ( *(mptr + j) ) {
				if ( *( mptr + j ) == ')' )
					break;
				else	j++;
				}
			if ( !( *(mptr +j ) )) {
				status = syntax_error( 6601 );
				break;
				}
			*(mptr + j) = 0;
			xptr = ( mptr + j + 1 );
			if ((mptr = resolve_definition( mptr )) != (BPTR) 0)
				strcat( wptr, mptr );
			strcat( wptr, xptr );
			strcpy( filename, wptr );
			}
		else	i++;
		}
	if ( wptr != (BPTR) 0 )
		liberate( wptr );
	return( status );
}


WORD	prepare_filename(SOURCEPTR  Input, BPTR filename, BPTR defext, SOURCEPTR OldInput )
{
	BPTR	copyname=(BPTR) 0;
	WORD	l;
	WORD	i;
	WORD	prefix=0;
	if (( *filename == '"' ) 
	||  ( *filename == '<' )) {
		prefix = *filename;
		filename++;
		i = 0;
		while ( *(filename + i) ) {
			if (( *(filename + i) == '"' )
			&&  ( prefix == '"' ))
				break;
			if (( *(filename + i) == '>' )
			&&  ( prefix == '<' ))
				break;
			i++;
			}
		*(filename+i) = 0;

		if (( OldInput != (SOURCEPTR) 0 ) 
		&&  ((l = fn_parser( filename, Input->Name, 0x0007 )) == 0) 
		&&  ((l = fn_parser( OldInput->Name, Input->Name, 0x0007 )) != 0)) {
			strcat( Input->Name, filename ); 
			if (!( copyname = allocate( strlen( Input->Name ) + 1 ))) {
				pop_source_context(MOINS_UN);
				return( allocation_failure() );
				}
			else	strcpy((filename = copyname),Input->Name);
			}
		}

	while ( *filename == ' ' )
		filename++;

	if ((l = fn_parser( filename, Input->Name, 0x0010 )) == 0) {
		if ((l = fn_parser( filename, Input->Name, 0x000F )) == 0) {
			pop_source_context(MOINS_UN);
			if ( copyname ) { liberate( copyname ); }
			return( 30 );
			}
		strcat( Input->Name,".");
		strcat( Input->Name, defext );
		}
	else	strcpy(Input->Name,filename );
	if ( copyname ) { liberate( copyname ); }
	return( evaluate_filename( Input->Name ) );
}


VOID	slash_conversion(char * nptr)
{
	char	*	sptr;
	for ( sptr=nptr; *sptr != 0; sptr++ ) {
#ifdef	UNIX
		if ( *sptr == '\\' )	*sptr = '/';
#else
		if ( *sptr == '/' ) 	*sptr = '\\';
#endif
		}
	return;
}

static	VOID	convert_filename_case (char * nptr)
{
#ifdef	UNIX
	char * eptr;
	slash_conversion( nptr );
	if (!( eptr = sysgetenv( "ABALANFC" ) )) 
		return;
	else if ( *(eptr++) != '=' )
		return;
	
	switch ( *eptr ) {
		case	'l'	:
		case	'L'	:
			while ( *nptr != 0 ) {
				if (( *nptr >= 'A' ) && ( *nptr <= 'Z'))
					*nptr = (( *nptr - 'A' ) + 'a' );
				else if ( *nptr == '@' )
					*nptr = '_';
				else if ( *nptr == '+' )
					*nptr = '_';
				else if ( *nptr == '-' )
					*nptr = '.';
				else if ( *nptr == 0x0025 )
					*nptr = '_';
				else if ( *nptr == 0x0023 )
					*nptr = '_';
				nptr++;
				}
			break;
	
		case	'u'	:
		case	'U'	:
			while ( *nptr != 0 ) {
				if (( *nptr >= 'a' ) && ( *nptr <= 'z'))
					*nptr = (( *nptr - 'a' ) + 'A' );
				else if ( *nptr == '@' )
					*nptr = '_';
				else if ( *nptr == '-' )
					*nptr = '.';
				else if ( *nptr == '+' )
					*nptr = '_';
				else if ( *nptr == 0x0025 )
					*nptr = '_';
				else if ( *nptr == 0x0023 )
					*nptr = '_';
				nptr++;
				}
			break;
	
		}
#endif
	return;
}


VOID	drop_library_paths()
{
	INCLUDEPTR	iptr;
	while ((iptr = LibraryPath) != (INCLUDEPTR) 0) {
		LibraryPath = iptr->Next;
		if ( iptr->Name != (BPTR) 0)
			liberate( iptr->Name );
		liberate( iptr );
		}
	LibraryPath = LibraryLast = (INCLUDEPTR) 0;
}

int	use_library_path( char * nptr, int mode )
{
	int		Handle=-1;
	INCLUDEPTR	iptr;
	BPTR		filename=(BPTR) 0;
	WORD	l;
	if (!( LibraryPath )) {
		if (!(filename = allocate( strlen(nptr) + 1 ) ))
			return( Handle );
		else	{
			strcpy( filename, nptr );
			convert_filename_case( filename );
			Handle = open( filename, mode );
			liberate( filename );
			}
		}
	else	{
		for (	iptr = LibraryPath;
			iptr != (INCLUDEPTR) 0;
			iptr = iptr->Next ) {
			if (!(filename = allocate( strlen( nptr ) + strlen( iptr->Name ) + 32 )))
				break;
			else	{
				strcpy( filename, iptr->Name );
				l = strlen( filename );
				l += fn_parser( nptr,(BPTR) (filename+l), 0x0078 );
				convert_filename_case( filename );
				Handle = open( filename, mode );
				liberate( filename );
				if ( Handle != -1 )
					break;
				}
			}
		}
	return(Handle);

}

VOID	add_library_path( ipath )
BPTR	ipath;
{
	INCLUDEPTR	iptr;
	int	i,p;
#ifdef	UNIX
	char sep[] = "/";
#else
	char sep[] = "\\";
#endif
	if ((iptr = (INCLUDEPTR) allocate( sizeof( struct otr_path ) )) != (INCLUDEPTR) 0) {
		for (p=0,i=0; *(ipath+i) != 0; i++) {
			if ( *(ipath+i) == *sep )
				p = i;
			}
		if (( *(ipath+p) != *sep) || ( *(ipath+i) !=  0 )) {
			strcpy(TokenBuffer,ipath);
			strcat(TokenBuffer,sep);
			ipath = TokenBuffer;
			}
		if ((iptr->Name = (BPTR) allocate_for_string( ipath )) != (BPTR) 0) {
			iptr->Next = (INCLUDEPTR) 0;
			if ( LibraryLast )
				LibraryLast->Next = iptr;
			else	LibraryPath = iptr;
			LibraryLast = iptr;
			}	
		else	liberate( iptr );
 		}
	return;
}

#ifdef ABAL33A
WORD	build_linker_default_options( BPTR rptr )
{
	int		Handle = -1;
	INCLUDEPTR	iptr;

	/* Use default options built from OTR options.
	/* OTR -J (LibraryPath) becomes OLD -I (library and associated module in same place). */

	if (rptr != (BPTR) 0) {
		*rptr = '\0';

		for (iptr = LibraryPath; iptr != (INCLUDEPTR) 0; iptr = iptr->Next) {
			strcat(rptr, (BPTR)"-I");
			strcat(rptr, iptr->Name);
			strcat(rptr, (BPTR)" ");
			}

		if (OtrOption.TargetName) {
			strcat(rptr, (BPTR)" -d");
			strcat(rptr, OtrOption.TargetName);
			}
		if (OtrOption.Verbose)
			strcat(rptr, (BPTR)" -v");
		if (OtrOption.Symbolic)
			strcat(rptr, (BPTR)" -m");

		return((WORD)strlen(rptr));
		}
	else {
		/* Just check required length */
		WORD	len = 0;
		for(iptr = LibraryPath; iptr != (INCLUDEPTR) 0; iptr = iptr->Next) {
			len += strlen(iptr->Name) + 3;
			}

		if (OtrOption.TargetName)
			len += strlen(OtrOption.TargetName) + 3;
		if (OtrOption.Verbose)
			len += 3;
		if (OtrOption.Symbolic)
			len += 3;

		return (len);
		}
}
#endif

VOID	drop_include_paths()
{
	INCLUDEPTR	iptr;
	while ((iptr = IncludePath) != (INCLUDEPTR) 0) {
		IncludePath = iptr->Next;
		if ( iptr->Name != (BPTR) 0)
			liberate( iptr->Name );
		liberate( iptr );
		}
	IncludePath = IncludeLast = (INCLUDEPTR) 0;
}

WORD		use_include_paths( fptr )
SOURCEPTR	fptr;
{
	INCLUDEPTR	iptr;
	BPTR		filename;
	WORD	l;
	if ((filename = allocate_for_string( fptr->Name )) == (BPTR) 0 )
		return( allocation_failure() );
	if ((iptr = IncludePath) != (INCLUDEPTR) 0 ) {
		do	{
			strcpy( fptr->Name, iptr->Name );
			l = strlen( fptr->Name );
			l += fn_parser( filename,(BPTR) & (fptr->Name[l]), 0x0078 );
			convert_filename_case( fptr->Name );
			if (( fptr->Source.Handle = fopen( fptr->Name, "r" )) != (FILEPTR) 0) {
				liberate( filename );
				return((fptr->Nature = 0));
				}
			}
		while ((iptr = iptr->Next) != (INCLUDEPTR) 0);
		}
	liberate( filename );
	return( 40 );

}

VOID	add_include_path( ipath )
BPTR	ipath;
{
	INCLUDEPTR	iptr;
	int	i,p;
#ifdef	UNIX
	char sep[] = "/";
#else
	char sep[] = "\\";
#endif

	if ((iptr = (INCLUDEPTR) allocate( sizeof( struct otr_path ) )) != (INCLUDEPTR) 0) {
		for (p=0,i=0; *(ipath+i) != 0; i++) {
			if ( *(ipath+i) == *sep )
				p = i;
			}

		if (( *(ipath+p) != *sep) || ( *(ipath+i) !=  0 )) {
			strcpy(TokenBuffer,ipath);
			strcat(TokenBuffer,sep);
			ipath = TokenBuffer;
			}

		if ((iptr->Name = (BPTR) allocate_for_string( ipath )) != (BPTR) 0) {
			iptr->Next = (INCLUDEPTR) 0;
			if ( IncludeLast )
				IncludeLast->Next = iptr;
			else	IncludePath = iptr;
			IncludeLast = iptr;
			}	
		else	liberate( iptr );
 		}
	return;
}

BPTR	parser_line_buffer();

WORD	goto_input_label()
{
	if ( Input->Label == MOINS_UN )
		Input->Label = new_implicite_label();
	return( implicite_goto( Input->Label ) );
}

WORD	establish_value_input( vptr )
VALUEPTR	vptr;
{
	WORD		status=0;
	SOURCEPTR	sptr;
	trace("establish_value_input()\n");
	if ((sptr = allocate_for_source()) == (SOURCEPTR) 0)
		return( allocation_failure() );

	sptr->LinePointer  = parser_line_buffer();

	sptr->Nature 	   = _INPUT_VALUE;
	sptr->Status       = 0;	/* Inhibits Auto Pop Input Context */
	sptr->BalComment   = inhibit_bal_comments();
	if ( Input != (SOURCEPTR) 0 ) {
		strcpy(sptr->Name,Input->Name);
		sptr->Object	   = Input->Object;
		sptr->Method	   = Input->Method;
		sptr->Parameters   = Input->Parameters;
		sptr->Number 	   = Input->Number;
		sptr->Lines	   = Input->Lines;
		}
	sptr->next         = Input;
	sptr->Source.Macro = vptr;
	Input 		   = sptr;
	return( 0 );
}

VOID	set_method_infos( file, line, offset )
WORD	file;
WORD	line;
WORD	offset;
{
	Input->Number       = file;
	Input->Lines	    = (line-1);
	symbolic_file_name( file, Input->Name );
	Input->LineStart    = offset;
	Input->Indent       = offset;
	return;
}

WORD	establish_macro_input( optr, mptr, vptr, pptr, mode)
VPTR		optr;
VPTR		mptr;
VALUEPTR	vptr;
VPTR		pptr;
WORD		mode;
{
	WORD		status=0;
	SOURCEPTR	sptr;

	trace("establish_macro_input()\n");

	if ((sptr = allocate_for_source()) == (SOURCEPTR) 0)
		return( allocation_failure() );

	sptr->next = Input;
	if ( Input == (SOURCEPTR) 0)
		sptr->Level = 1;
	else	sptr->Level = (Input->Level + 1);
	Input = sptr;
	Input->LinePointer = parser_line_buffer();
	Input->Nature = _INPUT_METHOD;
	Input->Status = 0;	/* Inhibits Auto Pop Input Context */
	Input->Object	    = optr;
	if ((Input->Method = mptr) != (VPTR) 0)
		set_invocation_counter( mptr );
	Input->BalComment   = inhibit_bal_comments();
	Input->Source.Macro = vptr;
	Input->Parameters   = pptr;
	if ( mode ) {	/* Inline Method : Optimised Parameters Only */
		Input->Variables    = (VPTR)lock_used_variables();
		Input->Results      = (VPTR)lock_used_results();
		Input->Registers    = lock_used_registers();
		}
	return( 0 );
}

WORD	establish_parameter_input( optr, mptr, vptr, pptr )
VPTR		optr;
VPTR		mptr;
VALUEPTR	vptr;
VPTR		pptr;
{
	WORD		status=0;
	SOURCEPTR	sptr;

	trace("establish_parameter_input()\n");

	if ((sptr = allocate_for_source()) == (SOURCEPTR) 0)
		return( allocation_failure() );

	sptr->next = Input;
	sptr->LinePointer  = parser_line_buffer();
	Input = sptr;
	Input->Nature = _INPUT_VALUE;
	Input->Status = 0;	/* Inhibits Auto Pop Input Context */
	Input->BalComment   = inhibit_bal_comments();
	Input->Object	    = optr;
	Input->Method	    = mptr;
	Input->Source.Macro = vptr;
	Input->Parameters   = pptr;
	return( 0 );
}


WORD	include_source_file( filename, extension )
BPTR	filename;
BPTR	extension;
{
	WORD		status=0;
	SOURCEPTR	sptr;
	if ((sptr = allocate_for_source()) == (SOURCEPTR) 0)
		return( allocation_failure() );
	sptr->next = Input;
	Input = sptr;

	if ((status = prepare_filename( Input, filename, extension, sptr->next )) != 0)
		return( status );

	convert_filename_case( Input->Name );

	if ((( Input->Source.Handle = fopen( Input->Name, "r" )) == (FILEPTR) 0)
	&&  ((status = use_include_paths( Input ))   != 0 )) {
		pop_source_context(MOINS_UN);
		return( file_error( status ) );
		}
	else	Input->Nature = 0;
	if ( OtrOption.Verbose & 4 )
		sysprintf("%s:#%u\n",Input->Name,++InputNesting);
	if ( OtrOption.Symbolic )
		Input->Number = symbolic_file_number( Input->Name );
	
	return( status );
}

WORD	block_translation( fptr )
BPTR	fptr;
{
	WORD	status;
	if ((status = include_source_file( fptr, OtrOption.Extension ) ) != 0)
		return( status );
	else	return( context_translation() );
}

BPTR	source_file_name()
{
	if (( Input != (SOURCEPTR) 0)
	&&  ( strlen(Input->Name)  != 0 ))
		return( (BPTR) Input->Name );
	else	return( (BPTR) "<none>" );
}

WORD	source_file_line()
{
	if ( Input != (SOURCEPTR) 0)
		return( (WORD) Input->Lines );
	else	return( 0 );
}

WORD	current_file_line()
{
	if ( OtrOption.ListFlag & 1 )
		return( list_file_line() );
	else	return( source_file_line() );
}

WORD	current_file_level()
{
	if ( OtrOption.ListFlag & 1 )
		return( list_file_level() );
	if ( Input != (SOURCEPTR) 0)
		return( Input->Level );
	else	return( 0 );
}

WORD	initialise_input( filename )
BPTR	filename;
{
	Input = (SOURCEPTR) 0;
	return( include_source_file( filename, OtrOption.Extension  ) );
}

VOID	terminate_input()
{

	trace("terminate_input()\n");

	while ( pop_source_context(MOINS_UN) );

	drop_include_paths();

	Input = (SOURCEPTR) 0;
	(void) liberate_for_input();
	return;
}


BPTR	current_error_context()
{
	return( trace_error_context() );
}

BPTR	next_error_context()
{
	if ( pop_source_context(MOINS_UN) )
		return( trace_error_context() );
	else	return((BPTR) 0 );
}


VOID	localise_error( bptr, pline, pcol )
BPTR	bptr;
LONG*	pline;
WORD*	pcol;
{
	if (( Input != (SOURCEPTR) 0 ) && ( Input->Name != (BPTR) 0)) {
#ifdef WIN32
		if (OptIdra)
		{
			sprintf( bptr, "%s", Input->Name );
			*pline = Input->Lines;
//			*pcol = Input->Columns;
			*pcol = 0;
		}
		else
			sprintf( bptr, "%s(%lu)", Input->Name, Input->Lines );
	}
	else { *bptr = '\0'; *pline = 0; *pcol = 0; }
#else
		sprintf( bptr, "%s(%lu)",Input->Name,Input->Lines );
		}
	else	strcpy(bptr,"No File");
#endif

	if ( OtrOption.TraceErrors )
		initialise_error_trace();
	return;
}


VOID	trace_inclusion_context()
{
	SOURCEPTR	iptr;

	for (iptr=Input; iptr != (SOURCEPTR) 0; iptr = iptr->next )
		sysprintf("inclusion : %s(%lu)\n",iptr->Name,iptr->Lines);
	return;
}


WORD	localise_trace_error( bptr,nb )
BPTR	bptr;
WORD	nb;
{
	HOSTPTR	hptr;
	if (( Input != (SOURCEPTR) 0 )
	&&  ( Input->Name != (BPTR) 0)) {
		if ( Eof.Number != -1 ) {
			*bptr = 0;
			symbolic_file_name( Eof.Number, bptr );
			sprintf( (bptr+strlen(bptr)), " %lu 1",
					Input->Lines );
			}
		else	{
			sprintf( bptr, "%s %lu 1",
					Input->Name,
					Input->Lines );
			}
		if ((( hptr = World->SymbolicHost ) != (HOSTPTR) 0)
		&&  ( hptr->prefix != (BPTR) 0)) {
			bptr += strlen(bptr);
			sprintf( bptr," !%s",hptr->prefix);
			if ( hptr->postfix ) {
				bptr += strlen(bptr);
				sprintf( bptr,".%s",hptr->postfix);
				}
			bptr += strlen(bptr);
			sprintf(bptr,"(%u)",(Input->Lines-hptr->line));
			}			
		bptr += strlen( bptr );
		sprintf( bptr," %s",imessage_text(nb));
		return( 1 );
		}
	else	return( 0 );
}

VOID	localise_state_change( STATEPTR sptr )
{
	if ( Input != (SOURCEPTR) 0 ) {
		sptr->filenumber = Input->Number;
		sptr->fileline = Input->Lines;
		}
	return;
}

VOID	localise_eof_error( STATEPTR sptr )
{
	Eof.Number = sptr->filenumber;
	Eof.Line   = sptr->fileline;
	return;
}

WORD	current_file_indent()
{
	if ( OtrOption.ListFlag & 1 )
		return( list_file_indent() );
	else if ( Input != (SOURCEPTR) 0 )
		return((WORD) Input->LineStart );
	else	return( 0 );
}

LONG	current_file_offset()
{
	if ( OtrOption.ListFlag & 1 )
		return( list_file_offset() );
	else if ( Input != (SOURCEPTR) 0 )
		return( Input->Indent );
	else	return( 0L );
}

WORD	current_file_number()
{
	if ( OtrOption.ListFlag & 1 )
		return( list_file_number() );
	if ( Input != (SOURCEPTR) 0 )
		return( Input->Number );
	else    return(0);
}

WORD	current_file_segment()
{
	if ( OtrOption.ListFlag & 1 )
		return( list_file_segment() );
	else if ( Input != (SOURCEPTR) 0 )
		return((WORD) (Input->LineStart >> 16));
	else	return(0);
}

VPTR	input_parameters()
{
	if ( Input != (SOURCEPTR) 0 )
		return( Input->Parameters );
	return( (VPTR) 0 );
}

VOID	establish_input_object( object )
VPTR	object;
{
	if ( Input != (SOURCEPTR) 0 )
		Input->Object = object;
	return;
}	

VPTR	input_object()
{
	if ( Input != (SOURCEPTR) 0 )
		return( Input->Object );
	return( (VPTR) 0 );
}

VPTR	input_method()
{
	if ( Input != (SOURCEPTR) 0 )
		return( Input->Method );
	return( (VPTR) 0 );
}

WORD	current_invocation_counter()
{
	VOID	*	mptr;
	if (!( mptr = input_method() ))
		return( OtrOption.LabelGroup );
	else	return( get_invocation_counter( mptr ) );
}

WORD	flush_filenames()
{
	WORD		target=0;
	DBGFILEPTR	fptr;
	if (OtrOption.Symbolic)  {
		target = next_debug_sector();
		while ((fptr = SymbolicFile) != (DBGFILEPTR) 0) {
			SymbolicFile = fptr->next;
			if (( OtrOption.Verbose & 4 )
			&&  ( OtrOption.Symbolic & 1 ))
				sysprintf("Debug Filename : %u : %s \n",fptr->number,fptr->name );
			symbolic_file_entry( fptr->name, fptr->number );
			liberate( fptr->name );
			liberate( fptr );
			}
		symbolic_file_entry( (BPTR) 0, MOINS_UN );
		flush_debug_sector();
		}
	return( target );
}

WORD	verify_world_list()
{
	BPTR	fptr;
	if (!( OtrOption.ListFlag ))
		return( FAUX );
	else if (World->ListHandle != (FILEPTR) 0)
		return( VRAI );
	else if ((fptr = world_listfile(1)) == (BPTR) 0)
		return( FAUX );
	else if ((World->ListHandle = fopen( fptr,"w" )) != (FILEPTR) 0)
		return( set_echo_list_number( fptr ) );
	else	return( FAUX );
}

WORD	terminate_world_input(int status )
{
	while ( Input != (SOURCEPTR) 0 )
		if (!( drop_source_context() ))
			break;
	return(status);
}

#endif	/* _TRINPUT_C */
	/* ----------- */

