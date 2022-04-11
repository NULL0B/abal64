#ifndef	_TRCLASS_H
#define	_TRCLASS_H

#ifndef	UNIX
#include "trmethod.h"
#endif

#define _CLASS_KEYWORD_MAX 44

#ifndef	_TRSYNTAX_C
struct	otr_class_options	{
	WORD		Local;
	WORD		Resident;
	WORD		Public;
	WORD		Virtual;
	WORD		Overload;
	WORD		Strict;
	WORD		Static;
	WORD		Protect;	
	WORD		Declare;
	WORD		Direct;
	WORD		Method;
	WORD		Common;
	WORD		Extern;
	WORD		Special;
	WORD		Type;
	WORD		Size;
	WORD		Number;
	WORD		CallBack;
	TCTYPPTR	ReturnType;
	VALUEPTR	MethodText;
	VPTR		WorkingMethod;
	};

#else	/* _TRSYNTAX_C */

static BPTR class_keywords [_CLASS_KEYWORD_MAX] = {
	(BPTR) "PUBLIC",
	(BPTR) "PRIVATE",
	(BPTR) "FRIEND",
	(BPTR) "VIRTUAL",
	(BPTR) "INHERIT",
	(BPTR) "UNION",
	(BPTR) "CONST",
	(BPTR) "COMMON",
	(BPTR) "INLINE",
	(BPTR) "FUNCTION",
	(BPTR) "END",
	(BPTR) "LOCAL",
	(BPTR) "EXTERNAL",
	(BPTR) "DCL",
	(BPTR) "STATIC",
	(BPTR) "DYNAMIC",
	(BPTR) "PROTECT",
	(BPTR) "CONSTRUCTOR",
	(BPTR) "DESTRUCTOR",
	(BPTR) "STRICT",
	(BPTR) "METHOD",
	(BPTR) "ROUTINE",
	(BPTR) "INTEGER",
	(BPTR) "NUMERIC",
	(BPTR) "STRING",
	(BPTR) "OVERLAY",
	(BPTR) "USER",
	(BPTR) "ARGUMENT",
	(BPTR) "LIBRARY",
	(BPTR) "RELAX",
	(BPTR) "CLASS",
	(BPTR) "RESIDENT",
	(BPTR) "PRECONDITION",
	(BPTR) "EXCEPTION",
	(BPTR) "POSTCONDITION",
	(BPTR) "INHIBIT",
	(BPTR) "GENERIC",
	(BPTR) "POINTER",
	(BPTR) "INVARIANT",
	(BPTR) "INDIRECT",
	(BPTR) "DIRECT",
	(BPTR) "OVERLOAD",
	(BPTR) "OPERATOR",
	(BPTR) "CALLBACK"
	};

#endif

#define	_CLASS_PUBLIC	0
#define	_CLASS_PRIVATE	1
#define	_CLASS_FRIEND	2
#define	_CLASS_VIRTUAL	3
#define	_CLASS_INHERIT	4
#define	_CLASS_UNION	5
#define	_CLASS_CONST	6
#define	_CLASS_COMMON	7
#define	_CLASS_INLINE	8
#define	_CLASS_FUNCTION	9
#define	_CLASS_EMETHOD	10
#define	_CLASS_LOCAL	11
#define	_CLASS_EXTERN	12
#define _CLASS_DCL	13
#define	_CLASS_STATIC	14
#define	_CLASS_DYNAMIC	15
#define	_CLASS_PROTECT	16
#define	_CLASS_CONSTRUCTOR 17
#define _CLASS_DESTRUCTOR  18
#define	_CLASS_STRICT    19
#define	_CLASS_METHOD    20
#define	_CLASS_ROUTINE   21
#define	_CLASS_INTEGER   22
#define	_CLASS_NUMERIC   23
#define	_CLASS_STRING    24
#define _CLASS_OVERLAY	 25
#define _CLASS_USER   	 26
#define	_CLASS_ARGUMENT	 27
#define	_CLASS_LIBRARY	 28
#define	_CLASS_RELAX  	 29
#define	_CLASS_CLASS	 30
#define	_CLASS_RESIDENT  31
#define	_CLASS_PRECONDITION 32
#define	_CLASS_EXCEPTION 33
#define	_CLASS_POSTCONDITION 34
#define	_CLASS_INHIBIT 35
#define	_CLASS_GENERIC 36
#define	_CLASS_POINTER 37
#define	_CLASS_INVARIANT 38
#define	_CLASS_INDIRECT 39
#define	_CLASS_DIRECT 40
#define	_CLASS_OVERLOAD 41
#define	_CLASS_OPERATOR 42
#define _CLASS_CALLBACK 43

#ifdef	_TRCLASS_C
	struct	otr_class_options	ClassOptions;
#else
EXTERN	struct	otr_class_options	ClassOptions;
#endif

#ifndef	UNIX

VOID	reset_oneshot_options( VOID );
WORD	set_class_local( VOID );
VOID	set_method_target( VALUEPTR );
WORD	method_requires_parameters( VOID );
WORD	method_allows_parameters( VOID );
WORD	terminate_macro_text( VOID );
WORD	terminate_method_text( VOID );
WORD	analyse_basic_type( VOID );
WORD	translate_class_dll( VOID );
WORD	translate_strict( VOID );
WORD	translate_relax( VOID );
WORD	translate_class_keyword( VOID );
WORD	base_class_translation( VOID );
WORD	translate_class_members( VOID );
WORD	translate_base_classes( VOID );
WORD	class_definition_active( VOID );
WORD	translate_class( WORD, WORD );
WORD	translate_union( WORD, WORD );
WORD	translate_endclass( WORD );
WORD	translate_extern_class( VOID );
WORD	translate_forward_class( VOID );
BPTR	trace_error_context( VOID );
WORD	directive_endclass( VOID );
WORD	directive_class( VOID );
WORD	directive_endstruct( VOID );
WORD	directive_struct( VOID );
WORD	directive_endunion( VOID ) ;
WORD	directive_union( VOID );
WORD	directive_endmacro( VOID );
WORD	directive_macro( VOID );
WORD	compare_methods( TCMBMETHPTR, TCMBMETHPTR );
WORD	compare_data_members( TCMBDATAPTR, TCMBDATAPTR );
WORD	compare_members( TCMEMBERPTR, TCMEMBERPTR );
WORD	compare_classes( TCSTRUCTPTR, TCSTRUCTPTR );
WORD	is_method_definition( VOID );
WORD	inherit_dynamic_type( TCTYPPTR, TCSTRUCTPTR, TCSTRUCTPTR );
WORD	analyse_method_end( VOID );

/* For trobject.c */
WORD	compare_parameter_list( TCVARPTR, TCVARPTR );
WORD	object_exists( VOID);
RESULTPTR	object_symbolic_term(WORD);
TCTEXTPTR	overlay_common_interface( TCVARPTR );
TCMBMETHPTR	build_overlay_interface( TCSTRUCTPTR, WORD );
WORD		transmit_common_linkage( TCVARPTR, TCVARPTR, WORD, WORD );
WORD	declare_overlay_construction( TCVARPTR, TCVARPTR, WORD, WORD );
WORD	overlay_interface_method( TCSTRUCTPTR, TCMEMBERPTR, TCMBMETHPTR );
TCSTRUCTPTR	base_class_componant( TCMEMBERPTR );
WORD	eimt_message( BPTR );
TCVARPTR	resolve_member_container( WORD, TCVARPTR, TCMEMBERPTR, WORD );
TCVARPTR	segment_pseudo_object( TCVARPTR, TCSTRUCTPTR, WORD );
TCVARPTR	resolve_object_container( TCVARPTR );
WORD	overlay_interface_methods( TCSTRUCTPTR );
WORD	declare_ocx_gds( TCSTRUCTPTR );
WORD	instance_ocx_object( TCSTRUCTPTR );
WORD	instance_program( BPTR );
WORD	instance_module( BPTR );
WORD	object_occupation( TCSTRUCTPTR );
WORD	parameter_occupation( TCSTRUCTPTR );
WORD	translate_object_message( VOID );
GENERICPTR	allocate_for_genericity( TCSTRUCTPTR, TCSTRUCTPTR );
VOID	liberate_for_genericity( GENERICPTR );
GENERICPTR	copy_genericity( GENERICPTR );
WORD	object_occupation( TCSTRUCTPTR );

/* For trmbuser.c */
WORD	call_dll_procedure( TCDLFPTR, TCMBPARAPTR );
WORD	call_dll_pptr( TCVARPTR, TCMBPARAPTR );
RESULTPTR	call_dll_function( TCDLFPTR, TCMBPARAPTR );
RESULTPTR	call_dll_fptr( TCVARPTR, TCMBPARAPTR, TCTYPPTR );
WORD 	activate_user_method( TCVARPTR, TCMEMBERPTR, TCMBMETHPTR, TCMBPARAPTR, WORD, WORD );
RESULTPTR	evaluate_user_method( TCVARPTR, TCMEMBERPTR, TCMBMETHPTR, TCMBPARAPTR, WORD, WORD );
WORD	add_user_function( TCMBMETHPTR, WORD );
WORD	affect_user_pointer( TCVARPTR, TCVARPTR, TCSTRUCTPTR, TCMEMBERPTR, TCMBMETHPTR );
WORD	initialise_indirect_user( TCMBAUTOPTR );
WORD	affect_overlay_pointer( TCVARPTR, TCVARPTR, TCSTRUCTPTR, TCMEMBERPTR, TCMBMETHPTR );
WORD	initialise_indirect_overlay( TCMBAUTOPTR );
WORD	call_overlay_pointer( TCVARPTR );
WORD	affect_method_pointer( TCVARPTR, TCVARPTR, TCSTRUCTPTR, TCMEMBERPTR, TCMBMETHPTR );

#else
BPTR	get_class_keyword();
#endif

#endif 	/* _TRCLASS_H */
	/* ---------- */


