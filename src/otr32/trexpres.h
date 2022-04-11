/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TREXPRES.H				*/
/*		Version :	2.1d					*/
/*		Date	:	08/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TREXPRES_H
#define	_TREXPRES_H

#define	RESULTPTR	struct otr_result XPTR
#define	FACTORPTR	struct otr_factor XPTR

#define	_RESULT_INT	0x0000
#define	_RESULT_CONST	0x0001
#define	_RESULT_VARB	0x0002
#define	_RESULT_EXPR	0x0003
#define	_RESULT_VPT 	0x1000
#define	_RESULT_VPTR	(_RESULT_VPT | _RESULT_VARB)

#define	_RESULT_NATURE	0x0003

#define	_RESULT_BASIC	0x0003
#define	_RESULT_POINTER	0x8000

#define	_RESULT_PROCPTR	0x0900
#define	_RESULT_SEGMPTR	0x0A00
#define	_RESULT_USERPTR	0x0B00

#define	_RESULT_ALIAS	(_RESULT_VARB | _RESULT_POINTER)
#define	_RESULT_ALEXPR	(_RESULT_EXPR | _RESULT_POINTER)

struct	otr_factor	{
	WORD		operation;
	RESULTPTR	operand;
	FACTORPTR	previous;
	FACTORPTR	next;
	};
	
struct	otr_result	{
	WORD		nature;
	WORD		value;
	VPTR		contents;
	RESULTPTR	next;
	};

#ifdef	_TREXPRES_C

	FACTORPTR	FactorHeap=(FACTORPTR) 0;
	RESULTPTR	ResultFree=(RESULTPTR) 0;
	RESULTPTR	ResultUsed=(RESULTPTR) 0;

#endif

#ifndef	UNIX

RESULTPTR	allocate_for_result( VOID );
FACTORPTR	allocate_for_factor( RESULTPTR, WORD );
WORD			compare_types( TCTYPPTR, TCTYPPTR );
RESULTPTR	allocate_protected_result( RESULTPTR );
VOID			transfer_result( RESULTPTR, RESULTPTR );
VOID			release_result( RESULTPTR );
VOID			forget_protected_result( RESULTPTR );
WORD			is_constant_expression( RESULTPTR );
VOID			initialise_expressions( VOID );
VOID			release_expressions( WORD );
RESULTPTR	lock_used_results( VOID );
VOID			unlock_used_results( RESULTPTR );
VOID			liberate_expressions( VOID );
RESULTPTR	constant_result( TCCONPTR );
RESULTPTR	implicite_constant( WORD );
RESULTPTR	next_free_register( VOID );
RESULTPTR	ensure_register( RESULTPTR );
RESULTPTR	negate_expression( RESULTPTR );
RESULTPTR	expression_term( VOID );
WORD			constant_type( TCCONPTR );
WORD			variable_type( TCVARPTR );
WORD			result_type( RESULTPTR );
WORD			verify_result_type( RESULTPTR, TCTYPPTR );
RESULTPTR	build_string_constant( RESULTPTR, BPTR );
RESULTPTR	build_numeric_term( RESULTPTR, BPTR );
RESULTPTR	numeric_term( VOID );
RESULTPTR	constant_term( VOID );
RESULTPTR	alias_result( TCVARPTR );
RESULTPTR	procedure_result( TCTYPPTR );
RESULTPTR	string_result( BPTR );
RESULTPTR	numeric_result( BPTR );
RESULTPTR	integer_result( WORD );
RESULTPTR	codeptr_result( WORD, WORD, VPTR );
WORD			procedure_exit( TCPRCPTR );
RESULTPTR	evaluate_procedure( TCPRCPTR, RESULTPTR, WORD );
RESULTPTR	extern_call_evaluate( TCPRCPTR );
RESULTPTR	symbolic_result( VOID );
RESULTPTR	symbolic_term( VOID );
VOID			initialise_symbolic_term( VOID );
RESULTPTR	primary_term( VOID );
RESULTPTR	evaluate_term( VOID );
TCVARPTR		is_variable_result( RESULTPTR );
WORD			is_string_variable( RESULTPTR );
WORD			is_string_constant( RESULTPTR );
WORD			is_string_register( RESULTPTR );
RESULTPTR	incrementation( RESULTPTR );
WORD			is_string_operand( RESULTPTR );
WORD			is_numeric_operand( RESULTPTR );
RESULTPTR	ensure_string( RESULTPTR );
RESULTPTR	enforce_string( RESULTPTR );
WORD			is_integer_variable( RESULTPTR );
WORD			is_integer_register( RESULTPTR );
RESULTPTR	convert_to_integer( RESULTPTR );
WORD			is_integer_operand( RESULTPTR );
RESULTPTR	ensure_integer( RESULTPTR );
RESULTPTR	enforce_integer( RESULTPTR );
RESULTPTR	convert_to_type( RESULTPTR, WORD );
RESULTPTR	ensure_numeric( RESULTPTR );
RESULTPTR	enforce_numeric( RESULTPTR );
WORD			fundemental_type( WORD );
WORD			normalised_type( WORD );
RESULTPTR	ensure_matching_type( RESULTPTR, RESULTPTR );
WORD			result_is_one( RESULTPTR );
WORD			result_is_zero( RESULTPTR );
WORD			constant_folding( WORD, RESULTPTR, RESULTPTR );
WORD			opposite_operator( WORD );
RESULTPTR	arithmetic( WORD, RESULTPTR, RESULTPTR );
WORD			evaluate_comparison( WORD, RESULTPTR, RESULTPTR, WORD, WORD );
RESULTPTR	evaluate_operation( WORD, RESULTPTR, RESULTPTR );
RESULTPTR	evaluate_factors( FACTORPTR );
RESULTPTR	secondary_evaluation( RESULTPTR );
RESULTPTR	primary_evaluation( VOID );
TCVARPTR		primary_variable( VOID );
RESULTPTR	evaluate_expression( WORD );
RESULTPTR	evaluate_integer_expression( VOID );
RESULTPTR	evaluate_typed_expression( WORD );
VOID			shadow_integer( RESULTPTR , WORD );
VOID			shadow_expression( RESULTPTR, WORD, RESULTPTR, RESULTPTR );
VOID			shadow_register( RESULTPTR , RESULTPTR );
VOID			shadow_constant( RESULTPTR , TCCONPTR );
VOID			shadow_variable( RESULTPTR , TCVARPTR );
VOID			shadow_conversion( RESULTPTR, WORD );
RESULTPTR	variable_result( TCVARPTR );
RESULTPTR	increment_variable( TCVARPTR );
VOID			unprotect_operand( RESULTPTR );
RESULTPTR	copy_result( RESULTPTR );
RESULTPTR	protect_operand( RESULTPTR );
WORD			index_available( TCVARPTR );
WORD			handle_index_expression( RESULTPTR );
WORD			zero_index_expression( RESULTPTR );
WORD			handle_target_index( RESULTPTR );
RESULTPTR	resolve_register_alias( RESULTPTR );
RESULTPTR	mark_dead_result( RESULTPTR );
RESULTPTR	mark_zero_result( RESULTPTR );
RESULTPTR	mark_dead_target( RESULTPTR );
VOID			mark_live_indexs( TCVARPTR );
RESULTPTR	mark_live_result( RESULTPTR );
VOID			rmv_statistics( VOID );
TCVARPTR		resolve_member_variable( TCVARPTR, BPTR, WORD );
TCVARPTR		resolve_structure_member( TCVARPTR );
RESULTPTR	variable_operand( VOID );
RESULTPTR	named_segment( BPTR );
WORD			collect_legal_operator( VOID );
WORD			affectation_expression( TCVARPTR );
WORD			ldgo_extern_segment( XTSEGPTR );
WORD			ldgo_intern_segment( TCSEGPTR );
WORD			constant_value( TCCONPTR );

#else

RESULTPTR	extern_call_evaluate();
RESULTPTR	allocate_protected_result();
RESULTPTR	allocate_for_result();
FACTORPTR	allocate_for_factor();
VOID		release_result();
VOID		initialise_expressions();
VOID		liberate_expressions();
VOID		release_expressions();
RESULTPTR       evaluate_factors();
RESULTPTR	evaluate_expression();
RESULTPTR	evaluate_integer_expression();
RESULTPTR	negate_expression();
RESULTPTR       primary_evaluation();
RESULTPTR	variable_result();
RESULTPTR	arithmetic();
RESULTPTR	integer_result();
RESULTPTR       codeptr_result();
RESULTPTR	procedure_result();
RESULTPTR	ensure_register();
RESULTPTR	ensure_integer();
RESULTPTR	ensure_string();
RESULTPTR	ensure_numeric();
RESULTPTR	enforce_integer();
RESULTPTR	enforce_string();
RESULTPTR	enforce_numeric();
RESULTPTR	next_free_register();
RESULTPTR	protect_operand();
RESULTPTR       convert_to_integer();
RESULTPTR	convert_to_type();
RESULTPTR	evaluate_typed_expression();
RESULTPTR	mark_zero_result();
RESULTPTR	mark_dead_result();
RESULTPTR	mark_dead_target();
RESULTPTR	mark_live_result();
RESULTPTR	implicite_constant();
RESULTPTR	numeric_term();
RESULTPTR	symbolic_term();
RESULTPTR	translate_term();
RESULTPTR	increment_variable();
RESULTPTR	named_segment();
RESULTPTR	build_string_constant();
TCVARPTR	is_variable_result();
TCVARPTR	resolve_member_variable();
RESULTPTR	incrementation();
RESULTPTR	lock_used_results();
VOID     	unlock_used_results();
WORD		constant_value();
RESULTPTR	secondary_evaluation();
WORD		fundemental_type();
#endif


#endif	/* _TREXPRES_H */
	/* ----------- */


