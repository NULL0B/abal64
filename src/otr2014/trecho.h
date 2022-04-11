#ifndef	_TRECHO_H
#define	_TRECHO_H


#ifndef	UNIX

#include "trmethod.h"
#include "trshadow.h"

#ifdef WIN32
int	sysprintf(const char * Format, ...);
#endif

VOID	set_echo_prefix( VOID );
VOID	clear_echo_prefix( VOID );
WORD	set_echo_list_number( BPTR );
WORD	list_file_line( VOID );
WORD	list_file_indent( VOID );
WORD	list_file_segment( VOID );
LONG	list_file_offset( VOID );
WORD	list_file_number( VOID );
WORD	list_file_level( VOID );
VOID	suspend_echo( VOID );
VOID	restart_echo( VOID );
VOID	echo_byte( WORD );
VOID	echo_gener( WORD, WORD );
VOID	echo_string(BPTR);
VOID	echo_line( VOID );
VOID	echo_space( VOID );
VOID	echo_keyword( BPTR );
WORD	echo_start(WORD);
VOID	echo_line_concatenation( VOID );
VOID	echo_comma( VOID );
VOID	echo_colon( VOID );
VOID	echo_equals( VOID );
VOID	echo_left_brace( VOID );
VOID	echo_right_brace( VOID );
VOID	echo_type( TCTYPPTR, WORD );
VOID	echo_class_nature( TCSTRUCTPTR );
VOID	echo_class_options( TCSTRUCTPTR );
VOID	echo_class_name( TCSTRUCTPTR );
VOID	echo_basic_class( TCSTRUCTPTR );
VOID	echo_class( TCSTRUCTPTR );
VOID	echo_method_type( TCTYPPTR );
VOID	echo_parameters( TCVARPTR );
VOID	echo_method( TCMEMBERPTR, TCMBMETHPTR );
VOID	echo_constant( TCMEMBERPTR, TCMBCONSTPTR );
VOID	echo_member( TCMEMBERPTR );
VOID	echo_program( VOID );
VOID	echo_library( VOID );
VOID	echo_module( VOID );
VOID	echo_segment( TCSEGPTR );
VOID	echo_eseg( TCSEGPTR );
VOID	echo_extern_segment( BPTR );
VOID	echo_endproc( VOID );
VOID	echo_return( VOID );
VOID	echo_procedure( TCPRCPTR );
TCPRCPTR	get_procedure_name( WORD );
VOID	echo_procedure_name( RESULTPTR );
VOID	echo_details( TCBLKPTR );
VOID	echo_end( VOID );
VOID	echo_dll_function( TCDLFPTR );
VOID	echo_declaration( TCVARPTR );
VOID	echo_field( WORD, BPTR );
VOID	echo_code_line( BPTR );
VOID	echo_newline( VOID );
VOID	echo_label( BPTR );
VOID	echo_gosub( WORD );
VOID	echo_gosub_label( BPTR );
VOID	echo_goto_label( BPTR );
VOID	echo_implicite_goto( WORD );
VOID	echo_instruction( BPTR );
VOID	echo_leave_iteration( WORD );
VOID	echo_enter_iteration( WORD );
VOID	echo_gosub_routine( BPTR, BPTR );
VOID	echo_routine( BPTR, BPTR );
VOID	echo_call_function( BPTR, BPTR );
VOID	echo_load_overlay( BPTR, BPTR );
VOID	echo_integer_operand( WORD );
VOID	echo_dimensions( WORD, RESULTPTR, RESULTPTR );
VOID	echo_variable_operand( TCVARPTR );
VOID	echo_bcd_string( BPTR, WORD );
VOID	echo_constant_operand( TCCONPTR );
VOID	echo_void( VOID );
VOID	echo_null( VOID );
VOID	echo_braced_operand( RESULTPTR );
VOID	echo_braced_shadow( SHADOWNODE, WORD );
VOID	echo_complex_operand( WORD, VPTR, WORD );
VOID	echo_register_number( WORD, WORD );
VOID	echo_special_register( SHADOWNODE, WORD);
VOID	echo_shadow_operand( SHADOWNODE, WORD );
VOID	echo_register_operand( SHADOWPTR );
VOID	echo_constant_symbol( TCCONPTR );
VOID	echo_operand( RESULTPTR );
VOID	echo_pause( RESULTPTR );
VOID	echo_affectation( TCVARPTR, RESULTPTR, WORD );
VOID	echo_sti( TCVARPTR, WORD );
VOID	echo_case( WORD, RESULTPTR );
VOID	echo_case_end( VOID );
VOID	echo_select( RESULTPTR );
VOID	echo_for_prefix( VOID );
VOID	echo_for(TCVARPTR, RESULTPTR, WORD);
VOID	echo_to(RESULTPTR);
VOID	echo_step(RESULTPTR);
VOID	echo_compare( WORD, RESULTPTR, RESULTPTR );
VOID	echo_logic( WORD );
VOID	echo_compare_end( VOID );
VOID	echo_until( VOID );
VOID	echo_else( VOID );
VOID	echo_exit(RESULTPTR);
VOID	echo_error(RESULTPTR);
VOID	echo_next(TCVARPTR);
VOID	echo_on_timer( RESULTPTR, WORD, BPTR );
VOID	echo_timer_off( VOID );
VOID	start_echo_of( RESULTPTR, WORD );
VOID	echo_of_label( WORD, BPTR );
VOID	echo_resume( WORD, BPTR );
VOID	echo_comment( BPTR );
BPTR	get_echo_text( VOID );
VOID	echo_correspondance( WORD, WORD );
VOID	echo_error_message( BPTR, BPTR, BPTR );
VOID	echo_warning_message( BPTR, BPTR, WORD, BPTR );
VOID	echo_transmit_common( TCVARPTR );

#else

VOID	echo_line();
VOID	echo_string();

#endif

#endif	/* _TRECHO_H */
	/* --------- */

