#ifndef	_TRMETHOD_H
#define	_TRMETHOD_H

#ifndef	WIN32
#include "buffers.h"
#endif

#include "trvalue.h"

#define	TCMBMETHPTR	struct tcode_structure_method XPTR
#define	TCMBFUNCPTR	struct tcode_function_method  XPTR
#define	TCMBGSBPTR 	struct tcode_routine_method   XPTR
#define	TCMBOVLPTR 	struct tcode_overlay_method   XPTR
#define	TCMBPARAPTR	struct tcode_method_parameter XPTR
#define	COMETHODPTR	struct tcode_special_method   XPTR
#define	EXCEPTIONPTR	struct tcode_exception XPTR
#define	INVARIANTPTR	struct tcode_exception XPTR

#include "trauto.h"

#define	_METHOD_MACRO		0x0001
#define	_METHOD_STRICT		0x0002
#define	_METHOD_STATIC		0x0004
#define	_METHOD_RESIDENT	0x0008
#define	_METHOD_INDIRECT	0x0010
#define	_METHOD_VIRTUAL		0x0020
#define	_METHOD_OVERLOAD	0x0040
#define	_METHOD_POINTER		0x0080

#ifdef	_BEFORE_19121996
#else
#define	_METHOD_CALLBACK	0x0100
#endif

#define _METHOD_ISPOINTER	(_METHOD_INDIRECT | _METHOD_OVERLOAD | _METHOD_VIRTUAL | _METHOD_POINTER)

struct	tcode_method_parameter	{
	WORD		mode;			/* 2 : Optimise, 1 Text */
	WORD		retmode;		/* 1 : Question, 0 None */
	TCVARPTR	variable;		/* Parameter Variable	*/
	TCMBPARAPTR	parameters;		/* Macro Parameters	*/
	TCVARPTR	object;			/* Parent Object	*/
	TCMBMETHPTR	method;			/* Parent Method	*/
	TCTEXTPTR	text;			/* Text of Parameter	*/
	RESULTPTR	result;			/* Result of Parameter	*/
	TCMBPARAPTR	next;			/* Next parameter 	*/
	};

struct	tcode_exception	{
	WORD		start;
	WORD		operate;
	WORD		finish;
	TCVARPTR	variable;
	TCMBAUTOPTR	context;
	};

struct	tcode_special_method	{
	BPTR		name;
	WORD		nature;
	COMETHODPTR	next;
	};

struct	tcode_structure_method	{
	WORD		users;
	WORD		nature;
	WORD		special;
	WORD		options;
	WORD		file;
	WORD		line;
	WORD		thisline;
	WORD		invocation;
	LONG		offset;
	WORD		number;
/*	WORD		alternative;	*/
	GENERICPTR	generic;
	TCMEMBERPTR	member;
	TCSTRUCTPTR	local;
	TCAUTOPTR	pending;
	COMETHODPTR	comethod;
	TCVARPTR	parameters;
	TCTYPPTR	type;
	TCTEXTPTR	value;
	};

struct	tcode_function_method	{
	WORD		status;
	TCPRCPTR	procedure;
	TCSTRUCTPTR	class;
	TCMEMBERPTR	member;
	TCVARPTR	parameters;
	TCTYPPTR	type;
	TCMBFUNCPTR	next;
	};

struct	tcode_routine_method	{
	WORD		status;
	WORD		label;
	TCVARPTR	object;
	TCMEMBERPTR	member;
	TCMBGSBPTR	next;
	};

struct	tcode_overlay_method	{
	WORD		status;
	TCSEGPTR	segment;
	XTSEGPTR	segptr;
	TCVARPTR	object;
	TCSTRUCTPTR	class;
	TCMEMBERPTR	member;
	WORD		field;
	TCMBOVLPTR	next;
	};

#ifdef	_TRMETHOD_C
	TCMBFUNCPTR	FunctionHeap=(TCMBFUNCPTR) 0;
	TCMBGSBPTR	RoutineHeap=(TCMBGSBPTR) 0;
	TCMBOVLPTR	OverlayHeap=(TCMBOVLPTR) 0;
	WORD		NextOverlay=254;
	WORD		NextFunction=1;
#else
#ifdef	_TRCLASS_C
EXTERN	TCMBFUNCPTR	FunctionHeap;
#endif
#endif

#ifndef	UNIX

WORD	release_method_parameters( VOID );
TCMBPARAPTR	liberate_method_parameters( TCMBPARAPTR );
TCMBOVLPTR	locate_overlay_method( TCSTRUCTPTR, TCMEMBERPTR, WORD );
TCMBOVLPTR	build_overlay_method( TCVARPTR, TCSTRUCTPTR, TCMEMBERPTR, WORD );
VOID	liberate_special_method( COMETHODPTR );
COMETHODPTR	allocate_special_method( BPTR, WORD );
TCMBMETHPTR	allocate_structure_method( VOID );
VOID	establish_method_member( TCMBMETHPTR , TCMEMBERPTR );
TCMEMBERPTR	resolve_method_member( TCMBMETHPTR );
WORD	build_pseudo_object( TCMBMETHPTR, TCSTRUCTPTR );
TCVARPTR	explicite_method_parameters( TCMBMETHPTR );
TCVARPTR	copy_method_parameters( TCMBMETHPTR );
WORD	copy_structure_method( TCMEMBERPTR, TCMEMBERPTR );
VOID	liberate_structure_method( TCMBMETHPTR );
WORD	put_method_byte( WORD );
WORD	put_method_string( BPTR );
TCTEXTPTR	collect_construction_parameters( VOID );
VOID	dump_white_space( WORD );
TCMBMETHPTR	output_method( VOID );
TCMBPARAPTR	parameter_term( VOID );
RESULTPTR	is_parameter_term( VOID );
WORD	transmit_method_label( BPTR );
WORD	method_directive( BPTR );
WORD	evaluate_ifexist( VOID );
WORD	evaluate_ifnexist( VOID );
TCTYPPTR	resolve_method_type( TCMBMETHPTR );
TCVARPTR	resolve_method_parameters( TCMBMETHPTR );
WORD	translate_method_type( WORD );
WORD	is_static_function( TCMBMETHPTR );
WORD	is_overlay_indirect( TCMBMETHPTR );
WORD	identify_indirect_method( TCMBMETHPTR, WORD );
WORD	set_method_options( TCMBMETHPTR, WORD );
WORD	activate_method_target( TCMBMETHPTR );
VOID	establish_method_symbolic( TCMBMETHPTR );
WORD	translate_pointer_method( VOID );
WORD	translate_method( VOID );
WORD	translate_macro_method( TCMEMBERPTR );
WORD	translate_operator( VOID );
TCMBPARAPTR		collect_strict_parameters( VOID );
TCVARPTR	is_parameter_variable( VOID );
WORD	expand_parameter( VOID );
WORD	translate_parameter_statement( VOID );
TCMBPARAPTR		formal_function_parameters( TCVARPTR );
TCMBPARAPTR		translate_method_parameters( TCMBMETHPTR );
WORD	pause_announcement( BPTR );
WORD	set_invocation_counter( TCMBMETHPTR );
WORD	get_invocation_counter( TCMBMETHPTR );
WORD	activate_macro( TCMEMBERPTR, TCMBMETHPTR );
WORD	flush_routine_methods( VOID );
WORD	trace_message( BPTR );
WORD	flush_function_method( TCSTRUCTPTR, TCMEMBERPTR, TCMBMETHPTR, TCPRCPTR );
WORD	flush_function_methods( WORD );
WORD	flush_overlay_methods( VOID );
TCMBFUNCPTR	build_function_method( TCSTRUCTPTR, TCMEMBERPTR, TCMBMETHPTR, WORD );
TCVARPTR	resolve_method_pointer( TCVARPTR, TCMBMETHPTR );
TCVARPTR	resolve_method_table( TCVARPTR );
TCVARPTR	overlay_object_method( TCVARPTR, WORD );
WORD	method_object_alias( TCVARPTR, TCVARPTR );
WORD	affect_function_pointer( TCVARPTR, TCVARPTR, TCSTRUCTPTR, TCMEMBERPTR, TCMBMETHPTR );
WORD	resolve_method_context( TCVARPTR, TCMEMBERPTR, TCSTRUCTPTR XPTR, TCVARPTR XPTR );
WORD	resolve_method_componant( TCMBAUTOPTR, TCVARPTR XPTR );
WORD	field_equals_vbm( TCVARPTR, LONG, TCMEMBERPTR );
WORD	base_member_field( WORD, TCMEMBERPTR, TCMBMETHPTR );
WORD  locate_method_pointer( TCVARPTR, TCMBMETHPTR, TCVARPTR XPTR, TCVARPTR XPTR, TCMEMBERPTR );
WORD	detect_memory_field( TCVARPTR );
WORD	is_method_pointer( TCMBMETHPTR );
WORD	method_occupation( TCMEMBERPTR, TCMBMETHPTR );
VOID	verbalise_method( TCVARPTR, TCSTRUCTPTR, TCMEMBERPTR );
WORD	verify_operator_parameter( TCMBMETHPTR, RESULTPTR );
WORD	verify_strict_parameters( TCVARPTR, TCMBPARAPTR );
WORD	is_strict_method( TCMBMETHPTR );
WORD	compare_strict_methods( TCMBMETHPTR, TCMBMETHPTR );
TCMEMBERPTR	locate_alternative_method( BPTR, WORD, TCMEMBERPTR );
TCMEMBERPTR	locate_strict_alternative( TCMEMBERPTR, TCMEMBERPTR );
WORD	strict_elimination( WORD, TCMBPARAPTR, TCMEMBERPTR );
WORD	activate_method( TCVARPTR, TCMEMBERPTR, TCMBMETHPTR, TCMBPARAPTR, WORD, WORD );
WORD	activate_object_method( TCVARPTR, TCMEMBERPTR, WORD );
RESULTPTR	evaluate_inline_macro( TCVARPTR, TCMEMBERPTR, TCMBMETHPTR );
WORD	expand_method_token( TCVARPTR, TCMEMBERPTR, TCMBMETHPTR );
RESULTPTR	evaluate_method_term( TCVARPTR, TCMEMBERPTR, TCMBMETHPTR, WORD );
RESULTPTR	evaluate_method_operator( TCVARPTR, TCSTRUCTPTR, TCMEMBERPTR, RESULTPTR );
WORD	method_affectation( TCVARPTR, TCSTRUCTPTR, TCMEMBERPTR, RESULTPTR );
WORD	is_inline_function( VOID );
WORD	is_method_function( VOID );
WORD	translate_inline_exit( VOID );
WORD	declare_module_method( TCVARPTR, TCSTRUCTPTR, TCMEMBERPTR, TCMBMETHPTR );
WORD	declare_module_methods( TCVARPTR, TCSTRUCTPTR );
WORD	inherit_dynamic_method( TCMBMETHPTR, TCSTRUCTPTR, TCSTRUCTPTR );
WORD		event_call_method( TCVARPTR, TCSTRUCTPTR, TCMEMBERPTR, TCMBMETHPTR );

/* For trlocal.c */
WORD	translate_local( VOID );
WORD	initialise_method_local( TCMBMETHPTR );
WORD	terminate_method_local( TCMBMETHPTR );

#else

TCVARPTR	is_parameter_variable();
WORD		expand_method_token();
RESULTPTR	object_symbolic_term();
RESULTPTR	evaluate_method_term();
RESULTPTR	evaluate_method_operator();
TCMBMETHPTR	allocate_structure_method();
WORD		set_invocation_counter();
WORD		get_invocation_counter();

#endif


#endif	/* _TRMETHOD_H */
	/* ----------- */


