/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRJAVA.C				*/
/*		Version :	2.1c					*/
/*		Date	:	14/06/1996				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRANSLAT_C
#define	_TRANSLAT_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include "stdtypes.h"		/* Standard translator type definitions	*/
#include "translat.h"		/* Translation types and definitions	*/
#include "trparser.h"		/* Stream parser definitions		*/
#include "trerrors.h"
#include "trsymbol.h"
#include "troption.h"
#include "trexpres.h"
#include "trlabels.h"
#include "triter.h"
#include "trclf.h"
#include "trproc.h"
#include "trldf.h"
#include "trdebug.h"

WORD reverse_compare(WORD opcode) { return( 0 ); }
WORD collect_normal_operator(VOID) { return( 0 ); }
WORD translate_variable(WORD type,WORD nature) { return( 0 ); }
WORD translate_declaration(WORD type) { return( 0 ); }
WORD translate_filler(VOID) { return( 0 ); }
WORD translate_field(VOID) { return( 0 ); }
WORD enter_segmental_translation(VOID) { return( 0 ); }
VOID leave_segmental_translation(VOID) { return; }
WORD translate_endproc(VOID) { return( 0 ); }
WORD translate_eseg(VOID) { return( 0 ); }
WORD translate_endloc(VOID) { return( 0 ); }
WORD translate_segment_return(VOID) { return( 0 ); }
WORD translate_ldgo_ret_seg(WORD type) { return( 0 ); }
WORD translate_gosub(VOID) { return( 0 ); }
WORD translate_goto(VOID) { return( 0 ); }
WORD translate_endif(VOID) { return( 0 ); }
WORD conditional_expression(WORD repeat_until) { return( 0 ); }
WORD translate_if(VOID) { return( 0 ); }
WORD translate_else(VOID) { return( 0 ); }
WORD translate_while(VOID) { return( 0 ); }
WORD translate_wend(VOID) { return( 0 ); }
WORD translate_break(VOID) { return( 0 ); }
WORD translate_loop(VOID) { return( 0 ); }
WORD translate_repeat(VOID) { return( 0 ); }
WORD translate_until(VOID) { return( 0 ); }
TCVARPTR for_initialisation(VOID) { return((TCVARPTR) 0 ); }
WORD generate_to(RESULTPTR lptr,RESULTPTR rptr,RESULTPTR steptr,WORD corps) { return( 0 ); }
RESULTPTR translate_to(VOID) { return((RESULTPTR)  0 ); }
RESULTPTR generate_step(TCVARPTR vptr,RESULTPTR rptr) { return( (RESULTPTR) 0 ); }
RESULTPTR translate_step(VOID) { return((RESULTPTR) 0 ); }
WORD translate_for(VOID) { return( 0 ); }
WORD translate_next(VOID) { return( 0 ); }
WORD translate_callproc(VOID) { return( 0 ); }
WORD translate_dll_function(VOID) { return( 0 ); }
WORD translate_indirect_call(VOID) { return( 0 ); }
WORD translate_call(VOID) { return( 0 ); }
WORD showme(BPTR msg) { return( 0 ); }
WORD translate_function_exit(RESULTPTR rptr,TCTYPPTR tptr) { return( 0 ); }
WORD overlay_method_parameter(TCVARPTR object,WORD field) { return( 0 ); }
WORD translate_procedure_exit(TCPRCPTR pptr) { return( 0 ); }
WORD translate_exit(VOID) { return( 0 ); }
WORD translate_leave(VOID) { return( 0 ); }
RESULTPTR select_expression(VOID) { return( (RESULTPTR) 0 ); }
WORD translate_select(VOID) { return( 0 ); }
WORD translate_case(VOID) { return( 0 ); }
WORD translate_default(VOID) { return( 0 ); }
WORD translate_endsel(VOID) { return( 0 ); }
WORD translate_then(VOID) { return( 0 ); }
WORD translate_event_do(VOID) { return( 0 ); }
WORD translate_do(VOID) { return( 0 ); }
WORD translate_soft_event(VOID) { return( 0 ); }
WORD translate_end_code(VOID) { return( 0 ); }
WORD terminate_soft_event(VOID) { return( 0 ); }
WORD translate_event_call(VOID) { return( 0 ); }
WORD translate_event(WORD mode) { return( 0 ); }
WORD translate_on_error(WORD mode) { return( 0 ); }
WORD translate_error(WORD mode) { return( 0 ); }
WORD translate_timer(WORD mode) { return( 0 ); }
WORD translate_timer_off(VOID) { return( 0 ); }
WORD translate_on_expression(WORD braces) { return( 0 ); }
WORD translate_of(VOID) { return( 0 ); }
WORD translate_on(WORD level) { return( 0 ); }
WORD translate_data(VOID) { return( 0 ); }
WORD translate_read_data(VOID) { return( 0 ); }
WORD translate_resume(VOID) { return( 0 ); }
WORD translate_control_keyword(VOID) { return( 0 ); }
WORD translate_enter(VOID) { return( 0 ); }
WORD translate_level_two(VOID) { return( 0 ); }
WORD level_one_extension(VOID) { return( 0 ); }
WORD translate_level_one(VOID) { return( 0 ); }
WORD reset_affectation(WORD status) { return( 0 ); }
WORD translate_affect_label(TCVARPTR vptr) { return( 0 ); }
WORD variable_affectation(TCVARPTR vptr) { return( 0 ); }
WORD translate_affectation(VOID) { return( 0 ); }
WORD translate_terminal_member(TCVARPTR vptr) { return( 0 ); }
WORD translate_statement(VOID) { return( 0 ); }
WORD segmental_translation(VOID) { return( 0 ); }
WORD translate_segment(VOID) { return( 0 ); }
WORD no_operation(VOID) { return( 0 ); }
WORD translate_end(VOID) { return( 0 ); }
WORD enter_procedure_translation(VOID) { return( 0 ); }
WORD translate_procedure(VOID) { return( 0 ); }
WORD enter_global_translation(VOID) { return( 0 ); }
WORD leave_global_translation(VOID) { return( 0 ); }
WORD await_target_end(VOID) { return( 0 ); }

WORD	translator_startup()
{
	WORD	type=0;
	if (get_uppercase_token()) {
		return(0);
		}
	return(syntax_error(230));
}

/*	-------------------------------------------	*/
/*	PUBLIC REGION	:	INTERFACE FUNCTIONS	*/
/*	-------------------------------------------	*/

WORD	terminate_translation( abandon )
WORD	abandon;
{
	if (( Context != (TCFDTPTR) 0 )
	&&  ( Context->Started        )
	&&  (!( abandon              )))
		error_message( "End instruction expected" );

	terminate_tcode_context();

	return( abandon );
}

WORD	line_translation( line_buffer )
BPTR	line_buffer;
{
	WORD	status=0;
	if (initialise_line_parser( line_buffer )) {

		if ((status = is_directive()) != MOINS_UN )
			return( translate_directive(status) );
		else if ((status = is_active_region()) != FAUX) {

			signal_new_line(VRAI);

			do	{
				if ((status = (*Context->operation)()) != 0) {
					if ( status != MOINS_UN ) {
						if (!( OtrOption.TraceErrors ))
							return(status);
						else if ( error_limit_reached() )
							return( status );
						else	{
							status = 0;
							break;
							}
						}
					else	return( syntax_error( 6006 ) );
					}
				}
			while ( soft_newline() );
			}
		}
	return(status);
}

RESULTPTR	intrinsic_functions()
{
	return( (RESULTPTR) 0 );
}

VOID	echo_source_line( lptr )
BPTR	lptr;
{
	echo_line_prefix();
	while (( *lptr ) && ( *lptr != 0x001A ) && ( *lptr != '\n'))
		sysprintf("%c",*(lptr++));
	sysprintf("\n");
	return;
}


/*
 *	Called during MAIN after initialisation of Options to
 *	detect and honour any options specified by the relevant
 *	environment variable.
 *
 */

#ifndef	UNIX
BPTR	getenv(BPTR);
#define	ENV_FIELD ';'
#else
BPTR	getenv(BPTR);
#define	ENV_FIELD ':'
#endif

VOID	default_language_options()
{
	BPTR	eptr;
	BPTR	fptr;
	WORD	term;
#ifndef	PROLOGUE
	if ((eptr = getenv(_TRANSLATOR_LANGUAGE_DEFAULT)) != (BPTR) 0) {
		while ( strlen(eptr) != 0 ) {
			fptr = eptr;
			while ( *fptr ) {
				if ( *fptr == ENV_FIELD )
					break;
				else 	fptr++;
				}
			if ((term = *fptr) == ENV_FIELD)
				*fptr = 0;
			(void) analyse_translator_options(eptr);			
			if ( term == ENV_FIELD )
				*(fptr++) = term;
			eptr = fptr;
			}		
		}
	return;
#endif
}

#endif	/* _ TRANSLAT_C */
	/* ------------ */

