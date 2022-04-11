/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRERRORS.H				*/
/*		Version :	2.1d					*/
/*		Date	:	20/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRERRORS_H
#define	_TRERRORS_H

#ifndef	UNIX
VOID initialise_error_trace();
VOID initialise_debug_trace();
VOID generate_debug_trace( WORD, WORD, WORD, WORD );
VOID flush_debug_trace();
VOID trace_nested_context();
WORD error_handler( WORD, BPTR, WORD );
WORD syntax_error( WORD );
WORD unknown_directive( VOID );
WORD too_many_parameters( VOID );
WORD not_enough_parameters( VOID );
WORD allocation_failure( VOID );
WORD illegal_recursivity( BPTR, WORD ) ;
WORD internal_error( WORD );
WORD file_error( WORD );
WORD target_file_error( char* ,int ) ;
WORD unexpected_dieze_endif( VOID );
WORD unexpected_dieze_else( VOID );
WORD expected_dieze_endif( VOID );
WORD incorrect_punctuation( VOID );
WORD expected_variable( VOID );
WORD expected_paragraph( VOID );
WORD expected_file( VOID );
WORD expected_program( VOID );
WORD unmatched_braces( VOID );
WORD symbol_already_defined( BPTR );
WORD undefined_label( BPTR );
WORD expected_keyword( BPTR );
WORD incorrect_data_type( VOID );
WORD not_yet_available( VOID );
WORD issue_warning( WORD );
WORD report_error( WORD );
VOID error_message( BPTR );
WORD execute( BPTR );
VOID terminate_errors( VOID );
WORD incorrect_target_type( VOID );
WORD incorrect_command_line( BPTR );
WORD target_file_busy( VOID );
WORD open_source_error(BPTR, WORD );
#else
WORD	syntax_error();
WORD	report_error();
VOID	error_message();
#endif

#endif 	/* _TRERRORS_H */
	/* ----------- */


