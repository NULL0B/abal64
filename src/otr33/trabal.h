/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 2003 Amenesik / Sologic  .			*/
/*									*/
/*									*/
/*		File	:	TRABAL.H				*/
/*		Version :	3.01					*/
/*		Date	:	28/08/03				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRTRABAL_H
#define	_TRTRABAL_H

#ifndef	UNIX

WORD	reverse_compare( WORD );
WORD	collect_normal_operator( VOID );
WORD	translate_variable( WORD, WORD );
WORD	translate_declaration( WORD ); 
WORD	translate_filler( VOID );
WORD	translate_field( VOID ); 
WORD	enter_segmental_translation( VOID );
VOID	leave_segmental_translation( VOID );
WORD	translate_endproc( VOID );
WORD	translate_eseg( VOID );
WORD	comma_option( WPTR ,WORD, WORD );
WORD	translate_endloc( VOID );
WORD	translate_segment_return( VOID );
WORD	translate_ldgo_ret_seg( WORD );
WORD	translate_gosub( VOID );
WORD	translate_goto( VOID );
WORD	translate_endif( VOID );
WORD	old_conditional_expression( WORD );
WORD	conditional_expression(WORD repeat_until);
WORD	translate_if( VOID );
WORD	translate_else( VOID );
WORD	translate_while( VOID );
WORD	translate_wend( VOID );
WORD	translate_loop( VOID );
WORD	translate_repeat( VOID );
WORD	translate_until( VOID );
TCVARPTR	for_initialisation( VOID );
WORD	generate_to( RESULTPTR, RESULTPTR, RESULTPTR, WORD );
RESULTPTR	translate_to( VOID );
RESULTPTR	generate_step( TCVARPTR, RESULTPTR );
RESULTPTR	translate_step( VOID );
WORD	translate_for( VOID );
WORD	translate_next( VOID );
WORD	translate_indirect_call( VOID );
WORD	extern_call_procedure(TCPRCPTR pptr);
WORD	translate_callproc( VOID );
WORD	translate_dll_function( VOID );
WORD	translate_call( VOID );
WORD	showme( BPTR );
WORD		translate_function_exit( RESULTPTR, TCTYPPTR );
WORD	overlay_method_parameter( TCVARPTR, WORD );
WORD	translate_procedure_exit( TCPRCPTR );
WORD	translate_exit( VOID );
WORD	translate_leave( VOID );
WORD	translate_break( VOID );
RESULTPTR	select_expression( VOID );
WORD	translate_select( VOID );
WORD	translate_case( VOID );
WORD	translate_default( VOID );
WORD	translate_endsel( VOID );
WORD	translate_then( VOID );
WORD	translate_event_do( VOID );
WORD	translate_do( VOID );
WORD	translate_soft_event( VOID );
WORD	translate_end_code( VOID );
WORD	terminate_soft_event( VOID );
WORD	translate_event_call( WORD );
WORD	translate_event( WORD );
WORD	translate_on_error( WORD );
WORD	translate_error( WORD );
WORD	translate_timer( WORD );
WORD	translate_timer_off( VOID );
WORD	translate_on_expression( WORD );
WORD	translate_of( VOID );
WORD	translate_on( WORD );
WORD	translate_data( VOID );
WORD	translate_read_data( VOID );
WORD	translate_resume( VOID );
WORD	translate_control_keyword( VOID );
WORD	translate_enter( VOID );
WORD	translate_level_two( VOID );
WORD	level_one_extension( VOID );
WORD	translate_level_one( VOID );
WORD	translate_affect_label( TCVARPTR );
WORD	variable_affectation( TCVARPTR );
WORD	translate_affectation( VOID );
WORD	translate_terminal_member( TCVARPTR );
WORD	translate_statement( VOID );
WORD	segmental_translation( VOID );
WORD	translate_segment( VOID );
WORD	no_operation( );
WORD	translate_end( VOID );
WORD	enter_procedure_translation( VOID );
WORD	translate_procedure( VOID );
WORD	translator_code_or_data( VOID );
WORD	enter_global_translation( VOID );
WORD	leave_global_translation( VOID );
WORD	start_program_or_module( WORD );
WORD	terminate_translation( WORD );
WORD	line_translation( BPTR );
RESULTPTR	intrinsic_functions( VOID );
VOID	echo_source_line( BPTR );
VOID	default_language_options( VOID );
WORD	reset_affectation( WORD );
#else
WORD	reset_affectation( WORD );
#endif


#endif 	/* _TRTRABAL_H */

