#define	DEBUG
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRDIRECT.C				*/
/*		Version :	2.1d					*/
/*		Date	:	09/04/1998				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRDIRECT_C
#define	_TRDIRECT_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include <string.h>		/* standard string functions */
#include "stdtypes.h"
#include "translat.h"
#include "trparser.h"
#include "trinput.h"
#include "troption.h"
#include "trdirect.h"
#include "trpragma.h"
#include "trsymbol.h"
#include "trclass.h"
#include "trdebug.h"
#include "trmethod.h"	
#include "trsystem.h"	
#include "trsyntax.h"	
#include "trerrors.h"	
#include "trapl.h"		
#include "trproc.h"		
#include "trldf.h"		
#include "trcommon.h"	
#include "trmain.h"		
#ifdef	WIN32
#include "fnparser.h"	
#endif
#include "trtables.h"	
#include "trsymbol.h"
#include "trinput.h"	
#include "trabmsg.h"
#include "trecho.h"

#ifdef WIN32
#include "wotrmess.h"
// Trace
#include "trtrace.h"

extern int OptIdra;
#endif

static	WORD	PragmaAnnounce=0;
					/* ---------------------------- */
					/* This pragma controls the -g  */
					/* Language to be generated	*/
					/* ---------------------------- */
static	WORD	PragmaOutput=0;		/* 'C'		: 0		*/
					/* 'C++'	: 1		*/
					/* 'Java'	: 2		*/
					/* 'Java++'	: 3		*/
					/* ---------------------------- */
static	WORD	PragmaThrow=MOINS_UN;
static	WORD	PragmaSwapSize=16;
static	WORD	PragmaPageSize=0x0800;
static	WORD	PragmaPageNumber=16;
static	WORD	PragmaExit=FAUX;

WORD	pragma_exit()
{
	return( PragmaExit );
}
	
WORD	pragma_throw()
{
	return( PragmaThrow );
}

WORD	pragma_swap_size()
{
	return( PragmaSwapSize );
}

WORD	pragma_page_size()
{
	return( PragmaPageSize );
}

WORD	is_pragma_announce( type )
WORD	type;
{
	switch ( type ) {
		case	_CLASS_CONSTRUCTOR : return( PragmaAnnounce & 0x0010 );
		case	_CLASS_DESTRUCTOR : return( PragmaAnnounce & 0x0020 );
		case	_CLASS_INLINE  	: return( PragmaAnnounce & 0x0001 );
		case	_CLASS_ROUTINE	: return( PragmaAnnounce & 0x0002 );
		case	_CLASS_FUNCTION	: return( PragmaAnnounce & 0x0004 );
		case	_CLASS_OVERLAY 	: return( PragmaAnnounce & 0x0008 );
		case	_CLASS_EXCEPTION: return( PragmaAnnounce & 0x0040 );
		case	_CLASS_COMMON   : return( PragmaAnnounce & 0x0080 );
		default			: return( 0 );
		}
}

WORD	is_directive()
{
	WORD	i;

	if (is_star_comment())
		if ( is_hash() ) {
			if ( get_uppercase_token() ) {
			for ( i=0; i < DIRECTIVE_MAX; i++ )
				if ( compare_tokens( TokenBuffer, otr_directive[i] ) )
					return( i );
			return( unknown_directive() );
			}
		}
	return( MOINS_UN );
}

WORD	is_pragma( nptr )
BPTR	nptr;
{
	WORD	i;
	for ( i=0; i < OTR_PRAGMA_MAX; i++ )
		if ( compare_tokens( nptr, otr_pragmas[i] ) )
			return( i );
	return( MOINS_UN );
}

static	DEFINEPTR	allocate_for_definition()
{
	DEFINEPTR	dptr;

	if ((dptr = (DEFINEPTR) allocate( sizeof( struct otr_definition ))) != (DEFINEPTR) 0) {
		dptr->name  = (BPTR) 0;
		dptr->hash  = 0;
		dptr->scope = World->Scope;
		dptr->value = (BPTR) 0;
		dptr->next  = (DEFINEPTR) 0;
		dptr->prev  = (DEFINEPTR) 0;
		}
	return( dptr );
}

static	WORD	StateCounter=0;

static	STATEPTR	allocate_for_state()
{
	STATEPTR	sptr;

	if ((sptr = (STATEPTR) allocate( sizeof( struct otr_state ))) != (STATEPTR) 0) {
		sptr->fileline = 0L;
		sptr->filenumber=0;
		sptr->token = (BPTR) 0;
		sptr->state = FAUX;
		sptr->number = ++StateCounter;
		sptr->next  = (STATEPTR) 0;
		localise_state_change( sptr );
		}
	return( sptr );
}

static	DEFINEPTR	is_definition()
{
	DEFINEPTR	dptr;

	if ((dptr = World->DefineList) != (DEFINEPTR) 0) {
		do	{
			if (( TokenHash == dptr->hash )
			&&  ( compare_tokens( TokenBuffer, dptr->name ) ))
				return( dptr );
			}
		while ((dptr = dptr->next) != (DEFINEPTR) 0);
		}
	return( dptr );
}

BPTR	resolve_definition( nptr )
BPTR	nptr;
{
	DEFINEPTR	dptr;
	strcpy( TokenBuffer, nptr );
	TokenHash = keyword_hash( nptr );
	if ((dptr = is_definition()) != (DEFINEPTR) 0)
		return( dptr->value );
#ifndef PROLOGUE
	else 	return( sysgetenv( nptr ) );
#else
	else	return((BPTR) 0);
#endif
}	

WORD	is_active_region()
{
	if ( World->StateHeap != (STATEPTR) 0 )
		return( World->StateHeap->state );
	else	return( VRAI );
}

static	WORD	add_definition_value( dptr )
DEFINEPTR	dptr;
{
	if (( is_equals() ) 
	&&  ( get_filename() )
	&&  ((dptr->value = allocate_for_string( TokenBuffer )) == (BPTR) 0))
		return( allocation_failure() );
	else	return( 0 );
}

WORD	drop_definition()
{
	DEFINEPTR	dptr;
	if (!(dptr = is_definition()))
		return(0);
	else	{
		if ( dptr->prev != (DEFINEPTR) 0 )
			dptr->prev->next = dptr->next;
		if ( dptr->next != (DEFINEPTR) 0 )
			dptr->next->prev = dptr->prev;
		if ( dptr->prev == (DEFINEPTR) 0 )
			World->DefineList = dptr->next;
		if ( dptr->name != (BPTR) 0 )
			liberate( dptr->name );
		if ( dptr->value != (BPTR) 0 )
			liberate( dptr->value );
		liberate( dptr );
		return(1);
		}
}

WORD	add_definition( token, mode )
BPTR	token;
WORD	mode;
{
	DEFINEPTR	dptr;
	WORD		hs;
	if  ((dptr = allocate_for_definition()) != (DEFINEPTR) 0) {
		if ( OtrOption.SourceTrace & 2 ) {
			if (  verify_world_list() )
				fprintf(World->ListHandle,"#define %s\r\n",token);
			else	sysprintf("#define %s\r\n",token);
			}
		hs = OtrOption.TokenSize;
		OtrOption.TokenSize = OtrOption.LabelSize;
		dptr->name = allocate_for_token( token );
		OtrOption.TokenSize = hs;
		if (!( dptr->name ))
			return( allocation_failure() );
		dptr->hash = keyword_hash( token );
		if ((dptr->next = World->DefineList) != (DEFINEPTR) 0)
			World->DefineList->prev = dptr;
		World->DefineList = dptr;
		if ( mode )
			return( add_definition_value(dptr) );
		else	return(0); 
		}
	else	return( allocation_failure() );
}

WORD	add_host_definition( token )
BPTR	token;
{
	DEFINEPTR	dptr;
	BPTR		vptr;
	/* Detect Definition Value in provided string */
	/* ------------------------------------------ */
	vptr = token;
	while ( *vptr ) {
		if ( *(vptr++) == '=' ) {
			*(vptr - 1) = 0;
			break;
			}	
		}
	if  (((dptr = allocate_for_definition()) != (DEFINEPTR) 0)
	&&   ((dptr->name = allocate_for_token( token )) != (BPTR) 0)) {
		dptr->hash = keyword_hash( token );
		if ((dptr->next = World->DefineList) != (DEFINEPTR) 0)
			World->DefineList->prev = dptr;
		World->DefineList = dptr;
		if (( *vptr  )
		&&  ((dptr->value = allocate_for_string( vptr )) == (BPTR) 0))
			return( allocation_failure() );
		else	return( 0 );
		}
	else	return( allocation_failure() );
}

static WORD	directive_define()
{ 
	if ( is_method_definition() )
		return( method_directive("#define") );
	if (!( is_active_region() ))
		return(0);
	if ( get_label() ) {
		return( add_definition(TokenBuffer,VRAI) );
		}
	else	return( syntax_error(21) );
}

static	WORD	store_state( etat )
WORD	etat;
{
	STATEPTR	sptr;
	if ((sptr = allocate_for_state()) == (STATEPTR) 0)
		return( allocation_failure() );
	else if ((sptr->token = allocate_for_string( TokenBuffer )) == (BPTR) 0)
		return( allocation_failure() );

	sptr->state = etat;
	sptr->next  = World->StateHeap;
	World->StateHeap   = sptr;
	return(0);
}

static WORD	directive_error()
{
	if ( is_method_definition() )
		return( method_directive("#error") );
	else if (!( is_active_region() ))
		return(0);
	else	return( syntax_error( 6666 ) );
}

static WORD	directive_ifexist()
{
	WORD		etat;
	WORD		status;

	if ( is_method_definition() )
		return( method_directive("#ifexist") );

	else	{

		etat = is_active_region();

		switch ((status = evaluate_ifexist())) {
			case	VRAI		:
				etat &= VRAI;
				return( store_state( etat ) );

			case	FAUX		:
				etat =  FAUX;
				return( store_state( etat ) );

			case	MOINS_UN	:
				return( MOINS_UN );
			}
		}

	return(0);
}


static WORD	directive_ifnexist()
{
	WORD		etat;
	WORD		status;

	if ( is_method_definition() )
		return( method_directive("#ifnexist") );
	else	{

		etat = is_active_region();

		switch ((status = evaluate_ifnexist())) {
			case	VRAI		:
				etat &= VRAI;
				return( store_state( etat ) );

			case	FAUX		:
				etat =  FAUX;
				return( store_state( etat ) );

			case	MOINS_UN	:
				return( MOINS_UN );
			}
		}

	return(0);
}

static WORD	directive_eofifdef()
{ 
	WORD		etat;
	
	etat = is_active_region();
	if ( get_label() ) {
		if (( etat ) 
		&&  ( is_definition() != (DEFINEPTR) 0 ))
			(void) drop_source_context();
		return( 0 );
		}
	else	return( syntax_error(22) );
}

static WORD	directive_eofifndef()
{ 
	WORD		etat;
	
	etat = is_active_region();
	if ( get_label() ) {
		if (( etat ) 
		&&  ( is_definition() == (DEFINEPTR) 0 ))
			(void) drop_source_context();
		return( 0 );
		}
	else	return( syntax_error(22) );
}

static WORD	directive_ifdef()
{ 
	WORD		etat;

	if ( is_method_definition() )
		return( method_directive("#ifdef") );
	etat = is_active_region();
	if ( get_label() ) {
		if (	is_definition() != (DEFINEPTR) 0 ) {
			if ( OtrOption.SourceTrace & 2 ) {
				if (  verify_world_list() )
					fprintf(World->ListHandle,"#ifdef %s : TRUE \r\n",TokenBuffer);
				else	sysprintf("#ifdef %s : TRUE \r\n",TokenBuffer);
				}
			etat &= VRAI;
			}
		else	{
			if ( OtrOption.SourceTrace & 2 ) {
				if (  verify_world_list() )
					fprintf(World->ListHandle,"#ifdef %s : FALSE \r\n",TokenBuffer);
				else	sysprintf("#ifdef %s : FALSE\r\n",TokenBuffer);
				}
			etat =  FAUX;
			}
		return( store_state( etat ) );
		}
	else	return( syntax_error(22) );
}

#ifdef	PROLOGUE
static	WORD	x_getch()
{
	WORD	v=0;
_asm	{
	push	cx
	push	ax
	mov	ah,10H
	int	110
	mov	al,cl
	xor	ah,ah
	mov	v,ax
	pop	ax
	pop	cx
	}
	return( v );
}
#endif

static WORD	directive_rdef()
{ 
	WORD		etat;
	BYTE		v;
	DEFINEPTR	dptr;
	BPTR		vptr;
	extern SOURCEPTR	Input;

	etat = is_active_region();
	if ( get_label() ) {
		if ( etat ) {
			if (!( dptr = is_definition() )) {
#ifdef WIN32
				if (YesNoInMsgBox((char*)imessage_text(32 /*Define*/),Input->Name,TokenBuffer))
					add_definition(TokenBuffer,VRAI);
				else
					drop_definition();
#else
				sysprintf("\r\n%s %s (Y/N)\r\n",imessage_text(32 /*Define*/),TokenBuffer);
				while (1) {
#ifdef	PROLOGUE
					v = x_getch();
#endif
#ifdef	UNIX
					scanf("%c",&v);
#endif
					if ((v == 'Y')
					||  (v == 'y')
					||  (v == 'O')
					||  (v == 'o')
					||  (v == '1')) {
						add_definition(TokenBuffer,VRAI);
						break;
						}
					if ((v == 'N')
					||  (v == 'n')
					||  (v == '0')) {
						drop_definition();
						break;
						}
					}
#endif
				}
			else	{
				if ((vptr = dptr->value ) != (BPTR) 0) {
					if ((*vptr == 'N')
					||  (*vptr == 'n')
					||  (*vptr == '0')) {
						drop_definition();
						}
					}
				}
			}
		return( 0 );
		}
	else	return( syntax_error(22) );
}


static WORD	directive_ifndef()
{ 
	WORD		etat;
	if ( is_method_definition() )
		return( method_directive("#ifndef") );
	etat = is_active_region();
	if ( get_label() ) {
		if ( is_definition() != (DEFINEPTR) 0 ) {
			if ( OtrOption.SourceTrace & 2 ) {
				if (  verify_world_list() )
					fprintf(World->ListHandle,"#ifndef %s : FALSE : defined \r\n",TokenBuffer);
				else	sysprintf("#ifndef %s : FALSE : defined \r\n",TokenBuffer);
				}
			etat = FAUX;
			}
		else	{
			if ( OtrOption.SourceTrace & 2 ) {
				if (  verify_world_list() )
					fprintf(World->ListHandle,"#ifndef %s : TRUE : defined \r\n",TokenBuffer);
				else	sysprintf("#ifndef %s : TRUE : undefined \r\n",TokenBuffer);
				}
			etat &= VRAI;
			}
		return( store_state( etat ) );
		}
	else	return( syntax_error(23) );
}

static WORD	directive_else()
{
	STATEPTR	sptr;
	WORD		status=0;
	if ( is_method_definition() )
		return( method_directive("#else") );
	if ((sptr = World->StateHeap) == (STATEPTR) 0)
		return( unexpected_dieze_else() );

	if (( get_label() )
	&& (!( uppercase_compare( sptr->token, TokenBuffer ) )))
		status = syntax_error( 4490 );
	if ( sptr->state == VRAI )
		sptr->state = FAUX;
	else if (sptr->next == (STATEPTR) 0)
		sptr->state = VRAI;
	else if (sptr->next->state == VRAI)
		sptr->state = VRAI;
	return(status);
}

static WORD	directive_endif(int mode)
{
	STATEPTR	sptr;
	WORD		status=0;
	if ( is_method_definition() )
		return( method_directive("#endif") );
	if ((sptr = World->StateHeap) == (STATEPTR) 0)
		return( unexpected_dieze_endif() );
	World->StateHeap = World->StateHeap->next;
	if ( sptr->token != (BPTR) 0) {
		if ( mode ) {
			if (( get_label() )
			&& (!( uppercase_compare( sptr->token, TokenBuffer ) )))
				status = syntax_error( 4490 );
			}
		liberate( sptr->token );
		}
	liberate( sptr );
	return(status);
}

WORD	terminate_world_endif()
{
	while ( World->StateHeap )
		(void) directive_endif(0);
	return(0);
}


static WORD	directive_undef()
{ 
	if ( is_method_definition() )
		return( method_directive("#undef") );
	if (!( is_active_region() ))
		return(0);
	if ( get_label() ) {
		if (!( drop_definition() ))
			issue_warning(3);
		return(0);
		}
	else	return( syntax_error(24) );

	return(0); 
}

static WORD	directive_include()
{
	if ( is_active_region() ) {
		if ( get_filename() ) 
			return( include_source_file( TokenBuffer, OtrOption.Extension ) );
		else	return( syntax_error(25) );
		}
	else	return(0);
}

static WORD	directive_use()
{
	if ( is_active_region() ) {
		if ( get_filename() ) 
			return( translate_use( TokenBuffer ) );
		else	return( syntax_error(25) );
		}
	else	return(0);
}

static WORD	directive_mem()
{ 
	if ( is_active_region() )
		Context->DiezeMem = integer_expression();
	return(0); 
}

static WORD	directive_files()
{ 
	if ( is_active_region() )
		Context->DiezeFiles = integer_expression();
	return(0); 
}

static WORD	directive_stack()
{ 
	if ( is_active_region() )
		Context->DiezeStack = integer_expression();
	return(0); 
}

static WORD	directive_heap()
{ 
	if ( is_active_region() )
		Context->DiezeHeap = integer_expression();
	return(0); 
}

static WORD	directive_swap()
{ 
	if ( is_active_region() ) {
#ifdef	SWAP_CTRL
		set_maximum_swap_buffers( (World->SwapBuffers = integer_expression()) );
#else
		World->SwapBuffers = integer_expression();
#endif
		}
	return(0); 
}

static WORD	directive_user()
{
	if ( is_active_region() ) {
		if ( get_filename() )
			return( translate_dll_description( TokenBuffer ) );
		else	return( translate_dll_description( (BPTR) 0 ) );
		}
	else	return(0);
}

WORD	directive_charset()
{
	if ( is_active_region() ) {
		if ( is_mnemonic("ABAL") )
			return( use_abal_charset() );
		else if ( is_mnemonic("ANSI") )
			return( use_ansi_charset() );
		else if ( is_mnemonic("UTF8") )
			return( use_extended_charset( "UTF8" ));
		else if ( is_mnemonic("UTF16") )
			return( use_extended_charset( "UTF16" ));
		else if ( get_filename() )
			return( load_input_charset( TokenBuffer ) );
		else	return( syntax_error(25) );
		}
	else	return(0);
}


static	WORD	translate_on_off(mode)
WORD	mode;
{
	if ( is_mnemonic("ON") )
		return( 1 );
	else if ( is_mnemonic("OFF") )
		return( 0 );
	else if ( mode == MOINS_UN )
		return( syntax_error(26) );
	else if ( mode )
		return( mode );
	else	return( integer_expression() );
}	

static	WORD	translate_optimise()
{
	do	{
		if ( is_mnemonic("ALL") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Optimise = MOINS_UN;
			else	OtrOption.Optimise = 0;
			}
		if ( is_mnemonic("LOAD") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Optimise |= _OPTIMISE_LOAD;
			else	OtrOption.Optimise &= ~_OPTIMISE_LOAD;
			}
		else if ( is_mnemonic("STORE") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Optimise |= _OPTIMISE_STORE;
			else	OtrOption.Optimise &= ~_OPTIMISE_STORE;
			}
		else if ( is_mnemonic("TABLES") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Optimise |= _OPTIMISE_TABLES;
			else	OtrOption.Optimise &= ~_OPTIMISE_TABLES;
			}
		else if ( is_mnemonic("INCREMENT") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Optimise |= _OPTIMISE_INCREMENT;
			else	OtrOption.Optimise &= ~_OPTIMISE_INCREMENT;
			}
		else if ( is_mnemonic("PARAMETERS") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Optimise |= _OPTIMISE_PARAMETERS;
			else	OtrOption.Optimise &= ~_OPTIMISE_PARAMETERS;
			}
		else if ( is_mnemonic("NEWLINE") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Optimise |= _OPTIMISE_NEWLINE;
			else	OtrOption.Optimise &= ~_OPTIMISE_NEWLINE;
			}
		else	return( syntax_error(27) );
		}
	while ( is_comma() );

	if (!( OtrOption.Generate ))
		OtrOption.Optimise = 0;

	return( 0 );
}

static	WORD	translate_enhanced()
{
	do	{
		if ( is_mnemonic("ALL") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Enhanced = MOINS_UN;
			else	OtrOption.Enhanced = 0;
			}
		else if ( is_mnemonic("AFFECTATION") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Enhanced |= _ENHANCED_AFFECTATION;
			else	OtrOption.Enhanced &= ~_ENHANCED_AFFECTATION;
			}
		else if ( is_mnemonic("COMPARE") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Enhanced |= _ENHANCED_COMPARE;
			else	OtrOption.Enhanced &= ~_ENHANCED_COMPARE;
			}

		else if ( is_mnemonic("AUTOCONV") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Enhanced |= _ENHANCED_AUTOCONV;
			else	OtrOption.Enhanced &= ~_ENHANCED_AUTOCONV;
			}

		else if ( is_mnemonic("ASSIGN") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Enhanced |= _ENHANCED_ASSIGN;
			else	OtrOption.Enhanced &= ~_ENHANCED_ASSIGN;
			}
		else if ( is_mnemonic("LABEL") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Enhanced |= _ENHANCED_LABEL;
			else	OtrOption.Enhanced &= ~_ENHANCED_LABEL;
			}
		else if ( is_mnemonic("LOCAL") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Enhanced |= _ENHANCED_LOCAL;
			else	OtrOption.Enhanced &= ~_ENHANCED_LOCAL;
			}
		else if ( is_mnemonic("INLINE") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Enhanced |= _ENHANCED_INLINE;
			else	OtrOption.Enhanced &= ~_ENHANCED_INLINE;
			}
		else if ( is_mnemonic("INDIRECT") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Enhanced |= _ENHANCED_INDIRECT;
			else	OtrOption.Enhanced &= ~_ENHANCED_INDIRECT;
			}
		else if ( is_mnemonic("OPERATORS") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Enhanced |= _ENHANCED_OPERATORS;
			else	OtrOption.Enhanced &= ~_ENHANCED_OPERATORS;
			}

		else if ( is_mnemonic("PARAMETERS") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Enhanced |= _ENHANCED_PARAMETERS;
			else	OtrOption.Enhanced &= ~_ENHANCED_PARAMETERS;
			}
		else if ( is_mnemonic("STRICT") ) {
			if ( translate_on_off(VRAI) )
				OtrOption.Enhanced |= _ENHANCED_STRICT;
			else	OtrOption.Enhanced &= ~_ENHANCED_STRICT;
			}
		else if ( is_mnemonic("DEBUG") ) {
			if ( translate_on_off(VRAI) )
				Context->DebugNature = VRAI;
			else	Context->DebugNature = FAUX;
			}
		else if ( is_mnemonic("CONSTRUCTION") )
			set_enhanced_construction( translate_on_off(VRAI) );
		else if ( is_mnemonic("EXIT") )
			PragmaExit = translate_on_off(VRAI);
		else	return( syntax_error(28) );

		}
	while ( is_comma() );
	return( 0 );
}

static	WORD	translate_pragma_announce()
{
	WORD	keyword;
	WORD	mode;
	do	{
		if ( is_mnemonic("ALL") )
			mode = MOINS_UN;
		else	{
			if (!( evaluate_token() )) 
				return( syntax_error( 77 ) );
			switch (( keyword = is_class_keyword() )) {
				case	_CLASS_CONSTRUCTOR :
					mode = 0x0010;
					break;
				case	_CLASS_DESTRUCTOR :
					mode = 0x0020;
					break;
				case	_CLASS_EXCEPTION  :
					mode = 0x0040;
					break;
				case	_CLASS_COMMON	:
					mode = 0x0080;
					break;
				case	_CLASS_ROUTINE	:
					mode = 0x0002;
					break;
				case	_CLASS_FUNCTION	:
					mode = 0x0004;
					break;
				case	_CLASS_OVERLAY	:
					mode = 0x0008;
					break;
				case	_CLASS_INLINE 	:
					mode = 0x0001;
					break;
				default			:
					return( syntax_error(78) );
				}
			}
		if ( translate_on_off(VRAI) )
			PragmaAnnounce |= mode;
		else	PragmaAnnounce &= ~mode;

		}
	while ( is_comma() );
	return( 0 );
}

WORD	active_warning( warnval )
WORD	warnval;
{
	WORD	masque=1;
	BPTR	eptr;
	if ( warnval > 15 ) {
#ifndef PROLOGUE
		if (!(eptr = sysgetenv("OTRW16")))
			return(1);
		else if ( *eptr == '0' )
			return(0);
		else
#endif
			return(1);
		}
	else if (!( warnval ))
		return(0);
	else if (!( OtrOption.Warning & 0x8000 ))
		return( 0 );
	else	{
		masque <<= (warnval - 1);
		return( (OtrOption.Warning & masque) );
		}
}

VOID	activate_warnings( mptr )
BPTR	mptr;
{
	WORD	warnval;
	WORD	masque=0x7FFF;
	if (((warnval = convert_int_token( mptr )) != 0)
	&&  (warnval <= 15 )) {
		masque = 1;
		masque <<= (warnval - 1);
		}
	OtrOption.Warning |= (masque | 0x8000);
	return;
}

static	WORD	translate_pragma_warnings()
{
	WORD	mode;
	WORD	warnval;
	WORD	masque=0;
	
	if ( is_mnemonic( "ALL" ) )
		masque = 0x7FFF;

	mode = translate_on_off(MOINS_UN);

	if ( masque ) {
		if ( mode )
			OtrOption.Warning |= masque;
		else 	OtrOption.Warning &= ~masque;
		return( 0 );
		}

	do	{
		if (((warnval = integer_expression()) <= 15)
		&&  (warnval != 0 )) {
			masque = 1;
			masque <<= (warnval - 1);
			if ( mode ) {
				if ( OtrOption.Verbose & 2 )
					sysprintf("Warning W%u : ON\n",warnval);
				OtrOption.Warning |= masque;
				}
			else 	{
				if ( OtrOption.Verbose & 2 )
					sysprintf("Warning W%u : OFF\n",warnval);
				OtrOption.Warning &= ~masque;
				}
			}
		else	break;
		}
	while ( is_comma() );

	return(0);

}

VOID	release_defined_pragmas()
{
	PRAGMAPTR	pptr;

	while ((pptr = World->DefinedPragmas) != (PRAGMAPTR) 0) {
		World->DefinedPragmas = pptr->next;
		if ( pptr->name != (BPTR) 0 )
			liberate( pptr->name );
		liberate( pptr );
		}
	return;
}
	

static	PRAGMAPTR	is_defined_pragma( token )
BPTR	token;
{
	PRAGMAPTR	pptr;
	if ((pptr = World->DefinedPragmas) != (PRAGMAPTR) 0) {
		do	{
			if ( compare_tokens( pptr->name, token ) )
				break;
			}
		while ((pptr = pptr->next) != (PRAGMAPTR) 0);
		}
	return( pptr );
}


static	WORD	add_defined_pragma( token )
BPTR	token;
{
	PRAGMAPTR	pptr;

	if ((pptr = is_defined_pragma( token )) != (PRAGMAPTR) 0) {
		pptr->state++;
		return( 0 );
		}
	else if ((pptr = (PRAGMAPTR) allocate( sizeof( struct otr_user_pragma ) )) == (PRAGMAPTR) 0)
		return( allocation_failure() );

	else if ((pptr->name = allocate_for_string( token )) == (BPTR) 0) {
		liberate( pptr );
		return( allocation_failure() );
		}
	else	{
		pptr->state = 1;
		pptr->next  = World->DefinedPragmas;
		World->DefinedPragmas = pptr;
		return( 0 );
		}

}

static	WORD	define_pragma()
{
	WORD	status;
	while ( 1 ) {	
		if (!( get_uppercase_token() ))
			return( syntax_error( 9773 ) );
		else if ((status = add_defined_pragma( TokenBuffer )) != 0)
			return( status );
		else if (!( is_comma() ))
			return( 0 );
		}
}

WORD	get_pragma_output()
{
	return( PragmaOutput );
}

BPTR	set_pragma_output( sptr )
BPTR	sptr;
{
	PragmaOutput = 0;
	while (( *sptr >= '0' ) && ( *sptr <= '9' ))
		PragmaOutput = ((PragmaOutput * 10) + (*(sptr++) - '0'));

	OtrOption.Optimise = 0;
	return( sptr );
}
	
static	WORD	translate_pragma_enter()
{
	HOSTPTR	hptr; 
	if (!( hptr = allocate( sizeof( struct otr_host ) ) ))
		return(27);
	hptr->prefix = hptr->postfix = (BPTR) 0;
	hptr->nature = 0;
	hptr->line   = source_file_line();
	hptr->previous = World->SymbolicHost;
	World->SymbolicHost = hptr;
	if (!( get_token() ))
		return(0);
	else if (!( hptr->prefix = allocate_for_string( TokenBuffer ) ))
		return(27);
	else if (!(hptr->nature = is_period() ))
		return(0);
	else if (!( get_token() ))
		return(0);
	else if (!( hptr->postfix = allocate_for_string( TokenBuffer ) ))
		return(27);
	else	return(0);
	
}

static	WORD	translate_pragma_style()
{
	BPTR	sptr;
	if (( sptr = World->StyleSheet ) != (BPTR) 0) {
		liberate( sptr );
		World->StyleSheet = (BPTR) 0;
		}
	else if (!( get_token() ))
		return(0);
	else if (!( World->StyleSheet = allocate_for_string( TokenBuffer ) ))
		return(27);
	
	return(0);
}	

static	WORD	translate_pragma_leave()
{
	HOSTPTR	hptr; 
	if (( hptr = World->SymbolicHost ) != (HOSTPTR) 0) {
		World->SymbolicHost = hptr->previous;
		if ( hptr->prefix )
			liberate( hptr->prefix );
		if ( hptr->postfix )
			liberate( hptr->postfix );
		liberate( hptr );
		}
	return(0);
}

static	WORD	translate_pragma_output()
{
	if (!( get_uppercase_token() ))
		return( syntax_error( 9773 ) );
	else if ( uppercase_compare( TokenBuffer, "C" ) )
		PragmaOutput = 0;
	else if ( uppercase_compare( TokenBuffer, "CPLUS" ) )
		PragmaOutput = 1;
	else if ( uppercase_compare( TokenBuffer, "JAVA" ) )
		PragmaOutput = 2;
	else if ( uppercase_compare( TokenBuffer, "JPLUS" ) )
		PragmaOutput = 3;
	else	PragmaOutput = 0;
	return( 0 );
}

static	WORD	undefine_pragma()
{
	PRAGMAPTR	pptr;
	while ( 1 ) {	
		if (!( get_uppercase_token() ))
			return( syntax_error( 9773 ) );
		else if (((pptr = is_defined_pragma( TokenBuffer )) != (PRAGMAPTR) 0)
		     &&   (pptr->state ))
			pptr->state--;


		if (!( is_comma() ))
			return( 0 );
		}
}

static WORD	translate_pragma_noinput()
{
	OtrOption.NoInput = translate_on_off(1);
	return(0);
}

static WORD	translate_pragma_export()
{
	OtrOption.ExportAll = translate_on_off(1);
	return(0);
}

static WORD	directive_pragma()
{
	PRAGMAPTR	pptr;
	WORD	type;
	WORD	status;

	if ( is_active_region() ) {
		if ( is_method_definition() )
			return( method_directive("#pragma") );
		else if ( get_uppercase_token() ) {
			switch ((type = is_pragma( TokenBuffer ))) {
				case _PRAGMA_CHARSET	:
					if ((status = directive_charset()) != 0)
						return( status );
					else	break;

				case _PRAGMA_EXPORT	:
					if ((status = translate_pragma_export()) != 0)
						return( status );
					else	break;

				case _PRAGMA_NOINPUT	:

					if ((status = translate_pragma_noinput()) != 0)
						return( status );
					else	break;

				case _PRAGMA_OUTPUT     :
					if ((status = translate_pragma_output()) != 0)
						return( status );
					else	break;

				case _PRAGMA_DEFINE	:
					if ((status = define_pragma()) != 0)
						return( status );
					else	break;
				case _PRAGMA_UNDEF	:
					if ((status = undefine_pragma()) != 0)
						return( status );
					else	break;
				case _PRAGMA_SWAPSIZE	:
					if ((PragmaSwapSize = integer_expression()) < 10)
						PragmaSwapSize = 3;
					break;
				case _PRAGMA_PAGESIZE	:
					if ((PragmaPageSize = integer_expression()) < 16 )
						PragmaPageSize = 16;
					break;
				case _PRAGMA_PAGENUMBER	:
					if ((PragmaPageNumber = integer_expression()) < 16 )
						PragmaPageNumber = 16;
					break;

				case _PRAGMA_ENTER	:
					translate_pragma_enter();
					break;

				case _PRAGMA_LEAVE	:
					translate_pragma_leave();
					break;
							
				case _PRAGMA_STYLE	:
					translate_pragma_style();
					break;
							
				case _PRAGMA_EDITOR	:
					if (!( get_token() ))
						return( syntax_error( 29 ) );
					else if ((status = set_world_editor( TokenBuffer )) != 0 )
						return( status );
					else	break;
				case _PRAGMA_THROW	:
					PragmaThrow = integer_expression();
					break;

				case _PRAGMA_ERRORS     :
					OtrOption.ErrorLimit = integer_expression();
					break;
					
				case _PRAGMA_WARNINGS   :
					translate_pragma_warnings();
					break;

				case _PRAGMA_APLUS      :

					if ( translate_on_off(VRAI) ) {
						OtrOption.PublicCommon = 1;
						/* OtrOption.Enhanced = 0; OtrOption.Optimise = 0; */
						}
					else	{
						OtrOption.PublicCommon = 0;
						/* OtrOption.Optimise = _ALL_OPTIMISATIONS;  OtrOption.Enhanced = _ALL_ENHANCEMENTS; */
						}
					break;

				case _PRAGMA_IGNORE_CASE:
					OtrOption.UpperCase = translate_on_off(VRAI);
					break;
				case _PRAGMA_PRIORITY   :
					OtrOption.Priority = translate_on_off(VRAI);
					break;
				case _PRAGMA_ANNOUNCE	:
					translate_pragma_announce();
					break;
				case _PRAGMA_LIST	:
					OtrOption.ListFlag = translate_on_off(FAUX);
					break;
				case _PRAGMA_TRACE	:
					OtrOption.Special = translate_on_off(VRAI);
					break;
				case _PRAGMA_ECHO	:
					OtrOption.TargetTrace = translate_on_off(VRAI);
					break;
				case _PRAGMA_ECHO_ON    :
					OtrOption.SourceTrace = integer_expression();
					break;
				case _PRAGMA_ECHO_OFF    :
					OtrOption.SourceTrace = 0;
					break;
				case _PRAGMA_TOKEN_SIZE :
					OtrOption.TokenSize = integer_expression();
					break;
				case _PRAGMA_LABEL_SIZE :
					OtrOption.LabelSize = integer_expression();
					break;
				case _PRAGMA_HEAP	:
					(void) directive_heap();
					break;
				case _PRAGMA_STACK	:
					(void) directive_stack();
					break;
				case _PRAGMA_FILES	:
					(void) directive_files();
					break;
				case _PRAGMA_MEM	:
					(void) directive_mem();
					break;
				case _PRAGMA_LOCAL_CONSTANT :
					OtrOption.LocalConstant = translate_on_off(VRAI);
					if ( OtrOption.WordSize > 2 )
						OtrOption.LocalConstant = 0;
					break;			
					
				case _PRAGMA_INITLOCAL	:
					OtrOption.InitLocal = translate_on_off();
					break;
				case _PRAGMA_ENHANCED	:
					(void) translate_enhanced();
					break;
				case _PRAGMA_OPTIMISE	:
					(void) translate_optimise();
					break;
				case _PRAGMA_SEMAPHORES :
					if ((Context->Semaphores = integer_expression()) < 16)
						Context->Semaphores = MOINS_UN;
					break;
				case _PRAGMA_SWAP_BUFFERS :
					(void) directive_swap();
					break;

				case _PRAGMA_KEYBOARD_FLUSH	:
					OtrOption.KeyboardFlush = translate_on_off(0);
					break;

				case _PRAGMA_NOFLUSH	:
					OtrOption.NoFlush = translate_on_off(0);
					break;

				case _PRAGMA_KEYWORD	:
					if ( get_token() )
						set_keyword_status( translate_on_off(VRAI) );
					break;
				default			:
					if (((pptr = is_defined_pragma( TokenBuffer )) == (PRAGMAPTR) 0)
					||  (pptr->state == 0))
						(void) issue_warning( 4 );
				}
			terminate_line_parser();
			return( 0 );
			}
		else	return( syntax_error(29) );
		}
	else	return(0); 
}

WORD	pragma_swap_buffers()
{
	return( World->SwapBuffers );
}

WORD	is_directive_endmacro()
{
	if ( is_directive() == _OTR_ENDMACRO )
		return( VRAI );
	else	return( FAUX );
}


WORD	translate_directive( n )
WORD	n;
{
	switch ( n ) {
		case _OTR_DEF		:
		case _OTR_DEFINE	: return( directive_define()  );
		case _OTR_IFDEF 	: return( directive_ifdef()   );
		case _OTR_IFNDEF 	: return( directive_ifndef()  );
		case _OTR_EOFIFDEF 	: return( directive_eofifdef() );
		case _OTR_EOFIFNDEF 	: return( directive_eofifndef());
		case _OTR_ELSE  	: return( directive_else()    );
		case _OTR_ENDIF 	: return( directive_endif(1)  );
		case _OTR_RDEF		: return( directive_rdef()    );
		case _OTR_CHARSET	: return( directive_charset() );
		case _OTR_UNDEF 	: return( directive_undef()   );
		case _OTR_INCLUDE	: return( directive_include() );
		case _OTR_USE		: return( directive_use()     );
		case _OTR_PRAGMA	: return( directive_pragma()  );
		case _OTR_MEM   	: return( directive_mem()     );
		case _OTR_FILES 	: return( directive_files()   );
		case _OTR_STACK 	: return( directive_stack()   );
		case _OTR_HEAP  	: return( directive_heap()    );
		case _OTR_USER  	: return( directive_user()    );
		case _OTR_CLASS		: return( directive_class()   );
		case _OTR_ENDCLASS	: return( directive_endclass());
		case _OTR_STRUCT	: return( directive_struct()  );
		case _OTR_ENDSTRUCT	: return( directive_endstruct());
		case _OTR_UNION		: return( directive_union()   );
		case _OTR_ENDUNION	: return( directive_endunion());
		case _OTR_MACRO		: return( directive_macro()   );
		case _OTR_ENDMACRO	: return( directive_endmacro());
		case _OTR_IFEXIST 	: return( directive_ifexist() );
		case _OTR_IFNEXIST 	: return( directive_ifnexist());
		case _OTR_ERROR		: return( directive_error() );
		default			: return(0);
		}
}

WORD	liberate_definitions()
{
	DEFINEPTR	dptr;
	STATEPTR	sptr;
	WORD		status=0;
	trace("liberate(World->DefineList)\n");
	while ((dptr = World->DefineList) != (DEFINEPTR) 0) {
		World->DefineList = World->DefineList->next;
		if ( dptr->name != (BPTR) 0)
			liberate( dptr->name );
		liberate( dptr );
		}
	trace("liberate(World->StateHeap)\n");
	while ((sptr = World->StateHeap) != (STATEPTR) 0) {
		World->StateHeap = World->StateHeap->next;
		localise_eof_error( sptr );	
		sprintf(TokenBuffer,"%",sptr->token);
		if ( sptr->token != (BPTR) 0) {
			strcpy( TokenBuffer, sptr->token );
			liberate( sptr->token );
			}
		liberate( sptr );
		expected_dieze_endif();
		status++;
		}
	return(status);
}

VOID	initialise_definitions()
{
	World->DefineList = (DEFINEPTR) 0;
	World->StateHeap  = (STATEPTR) 0;
	return;
}

#include "trworld.c"

#endif	/* _TRDIRECT_C */
	/* ----------- */

