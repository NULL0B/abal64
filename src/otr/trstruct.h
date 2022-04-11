#ifndef	_TRSTRUCT_H
#define	_TRSTRUCT_H

#define	TCMBCONSTPTR	struct tcode_structure_const  XPTR
#define	TCMBDATAPTR	struct tcode_structure_data   XPTR
#define	TCMEMBERPTR 	struct tcode_structure_member XPTR
#define	TCSTRUCTPTR 	struct tcode_structure XPTR
#define	TCFRIENDPTR 	struct tcode_friend XPTR
#define	COMMONPTR	struct tcode_common XPTR
#define	GENERICPTR	struct tcode_generic XPTR

#include "trtext.h"
#include "trexpres.h"

/*		-------------------------------------------		*/
/*		T C O D E _ S T R U C T U R E _ F R I E N D		*/
/*		-------------------------------------------		*/
struct	tcode_friend	{
	BPTR		name;
	TCFRIENDPTR	next;
	};

/*		---------------------------------------			*/
/*		T C O D E _ S T R U C T U R E _ D A T A 		*/
/*		---------------------------------------			*/
struct	tcode_structure_data {
	WORD		field;		/* Explicite Field		*/
	BPTR		structname;	/* Name if is structure		*/
	TCSTRUCTPTR	structure;	/* Structure Resolved		*/
	TCTYPPTR	type;		/* Else type if is elementary	*/
	TCTEXTPTR	construction;	/* Construction Parameters	*/
	};


/*		-----------------------------------------		*/
/*		T C O D E _ S T R U C T U R E _ C O N S T		*/
/*		-----------------------------------------		*/
struct	tcode_structure_const	{
	BPTR		value;		/* Ascii Constant Value		*/
	TCTYPPTR	type;		/* Standard Type structure	*/
	};


/*		-------------------------------------------		*/
/*		T C O D E _ S T R U C T U R E _ M E M B E R		*/
/*		-------------------------------------------		*/
struct	tcode_structure_member	{
	BPTR		name;		/* Name of member		*/
	WORD		hash;		/* Name hash value		*/
	WORD		access;		/* Access PUBLIC or PRIVATE	*/
	WORD		lock;		/* LOCK / SIZED			*/
	WORD		size;		/* Hash value of name		*/
	WORD		nature;		/* Pointer / Union / Class Etc	*/
	VPTR		special;	/* Pointer to Special Type	*/
	TCMEMBERPTR	next;		/* Next member in list		*/
	TCMEMBERPTR	prev;		/* Prev member in list		*/
	TCVARPTR	common;		/* Common Member Variable	*/
	TCSTRUCTPTR	class;		/* Common Member Class		*/
	};

/*		-------------------------				*/
/*		T C O D E _ G E N E R I C				*/
/*		-------------------------				*/

struct	tcode_generic {
	TCSTRUCTPTR	old;
	TCSTRUCTPTR	new;
	GENERICPTR	next;
	};

/*		-----------------------------				*/
/*		T C O D E _ S T R U C T U R E				*/
/*		-----------------------------				*/

struct	tcode_structure	{
					/* ---------------------------- */
	BPTR		name;		/* Structure identifier		*/
	WORD		hash;		/* Name hash value		*/
	WORD		number;		/* Unique ID Number		*/
	WORD		size;		/* Hash value of name		*/
	WORD		nature;		/* Dynamic / Union / Class Etc  */
	WORD		lock;		/* LOCK / SIZED			*/
	WORD		access;		/* Access PUBLIC or PRIVATE	*/
	WORD		virtual;	/* Indicates Virtual Class	*/
	WORD		explicite;	/* Explicite Size for APL	*/
	WORD		scope;		/* Duration Scope : 0 WORLD	*/
	WORD		enhanced;	/* Enhanced Class Options	*/
	BPTR		source;		/* Source or Library Name	*/
	BPTR		module;		/* Library Module Name		*/
	TCVARPTR	commonroot;	/* Common Interface		*/
	WORD		commonlock; 	/* 				*/
	WORD		announce;	/* Explicite Class Announcement	*/
	TCDLBPTR	dll;		/* Dynamic Library 		*/
	TCFRIENDPTR	friend;		/* List of Freind Classes	*/
	TCMEMBERPTR	first;		/* Head of member list      	*/
	TCMEMBERPTR	last; 		/* Foot of member list      	*/
	TCSTRUCTPTR	next;		/* Next structure in list	*/
	TCSTRUCTPTR	previous;	/* Prev structure in list	*/
					/* ---------------------------- */
	};

/*		-----------------------				*/
/*		T C O D E _ C O M M O N				*/
/*		-----------------------				*/

struct	tcode_common	{
	WORD		scope;
	TCMEMBERPTR	member;
	TCSTRUCTPTR	class;
	COMMONPTR	next;
	};

/*
 *	Function prototypes returning members and structures (classes)
 *	--------------------------------------------------------------
 *
 */

#ifndef	UNIX

WORD	set_world_announce( VOID );
WORD	translate_extern_keyword( VOID );
WORD	translate_overlay_keyword( VOID );
WORD	translate_ocx_keyword( VOID );
VOID	cancel_extern_overlay( VOID );
WORD	translate_protect( VOID );
WORD	translate_local_keyword( VOID );
WORD	translate_overload( VOID );
WORD	translate_static_keyword( VOID );
WORD	translate_dynamic_keyword( VOID );
WORD	translate_virtual( VOID );
WORD	translate_generic( VOID );
WORD	translate_private( VOID );
WORD	translate_public( VOID );
VOID	liberate_structure_data( TCMBDATAPTR );
VOID	liberate_structure_const( TCMBCONSTPTR );
VOID	liberate_structure_member( TCMEMBERPTR );
VOID	liberate_friends( TCFRIENDPTR );
VOID	liberate_for_structure( TCSTRUCTPTR );
TCMBDATAPTR	allocate_structure_data( VOID );
TCMBCONSTPTR	allocate_structure_const( BPTR, TCTYPPTR );
TCMEMBERPTR	allocate_structure_member( BPTR );
WORD	copy_structure_data( TCMEMBERPTR, TCMEMBERPTR );
WORD	copy_structure_const( TCMEMBERPTR, TCMEMBERPTR );
TCMEMBERPTR		copy_member( TCMEMBERPTR );
TCSTRUCTPTR	allocate_for_structure( BPTR );
TCSTRUCTPTR	locate_structure( BPTR );
VOID	kc_statistics( VOID );
TCSTRUCTPTR	known_structure( BPTR );
TCMEMBERPTR	locate_member( TCSTRUCTPTR, BPTR );
WORD	dcl_method_pointer( TCMEMBERPTR, WORD, WORD, WORD, TCSTRUCTPTR );
WORD	structure_occupation( TCSTRUCTPTR );
#ifdef	_TRACE_OCCUPATION
WORD	structure_occupation( TCSTRUCTPTR );
#endif
WORD	ll_member_occupation( TCMEMBERPTR );
WORD	declare_structure( TCSTRUCTPTR, BPTR, WORD, WORD, WORD, TCTEXTPTR, WORD );
TCSTRUCTPTR	input_class( VOID );
WORD	declare_instance( TCSTRUCTPTR, BPTR, WORD, WORD, WORD, TCTEXTPTR, WORD );
WORD	declare_terminal( BPTR, WORD, WORD, WORD, WORD, WORD, WORD, WORD );
WORD	allocate_indirect_object( TCVARPTR );
TCVARPTR	base_member_host( TCVARPTR );
TCTEXTPTR	default_construction( TCVARPTR );
WORD	explicite_construction( TCVARPTR, WORD );
WORD	explicite_destruction( TCVARPTR, WORD );
WORD	declare_local_members( TCSTRUCTPTR );
WORD	define_explicite_union( VOID );
WORD	add_member( TCSTRUCTPTR, TCMEMBERPTR );
WORD	terminate_explicite_union( VOID );
WORD	open_structure_definition( BPTR, WORD );
WORD	close_structure_definition( TCSTRUCTPTR );
WORD	define_structure( BPTR, WORD );
WORD	translate_struct(WORD);
WORD	add_friend( TCSTRUCTPTR, BPTR );
WORD	translate_friend( VOID );
WORD	translate_endstruct(WORD);
WORD	replace_member( TCSTRUCTPTR, TCMEMBERPTR, TCMEMBERPTR );
WORD	add_to_structure( BPTR, WORD, WORD, WORD, WORD, WORD, WORD );
WORD	add_structure_method( BPTR, VPTR);
WORD	add_structure_constant( BPTR, WORD, BPTR );
VOID	unnamed_structure( BPTR );
WORD	add_member_structure( TCSTRUCTPTR, BPTR, WORD, WORD );
WORD	translate_structure( WORD, WORD );
WORD	translate_instance_option( WORD );
WORD	translate_structured_parameter( TCVARPTR, WORD, WORD, TCSTRUCTPTR );
WORD	translate_struct_parameter( TCVARPTR, WORD, WORD );
WORD	implicite_struct_parameter( TCVARPTR, WORD );
WORD	generate_struct_parameter( TCVARPTR );
WORD	verify_structure_type( WORD, BPTR );
WORD	static_inheritance( TCSTRUCTPTR, TCSTRUCTPTR );
WORD	delayed_inheritance(TCSTRUCTPTR, TCSTRUCTPTR );
WORD	perform_inheritance( TCSTRUCTPTR, BPTR );
WORD	inherit_struct( BPTR );
WORD	translate_instance( VOID );
WORD	translate_base_instance(WORD);
WORD	translate_object_data( TCVARPTR, TCMEMBERPTR, BPTR );
TCMEMBERPTR	resolve_baseclass_member( TCVARPTR XPTR, TCVARPTR, TCSTRUCTPTR, BPTR );
TCMEMBERPTR	locate_baseclass_member( TCVARPTR XPTR, TCVARPTR, TCSTRUCTPTR, BPTR, WORD );
TCMEMBERPTR	locate_class_member( TCVARPTR XPTR, BPTR );
RESULTPTR	evaluate_constant_member( TCMBCONSTPTR );
WORD	encapsulation_violation( TCVARPTR, TCSTRUCTPTR, TCMEMBERPTR );
WORD	expand_member_constant( TCMBCONSTPTR );
WORD	legal_member_access( WORD, WORD );
WORD	legal_member_access( WORD, WORD );
WORD	expand_base_class_constant( TCSTRUCTPTR, WORD );
WORD	expand_class_constant( TCSTRUCTPTR, WORD );
WORD	expand_object_member( TCVARPTR );
WORD	expand_class_number( VOID );
WORD	expand_this( VOID );
WORD	expand_member( VOID );
TCVARPTR	resolve_member_componant( TCVARPTR, TCMEMBERPTR );
WORD	resolve_member_term( TCVARPTR, TCVARPTR XPTR, TCMEMBERPTR XPTR, WPTR );
RESULTPTR	evaluate_method_pointer( TCVARPTR, TCMEMBERPTR );
RESULTPTR	evaluate_member_term( TCVARPTR, WORD );
TCMEMBERPTR	locate_operator_member( TCSTRUCTPTR, BPTR, WORD, RESULTPTR );
RESULTPTR	evaluate_object_operator( WORD, RESULTPTR, RESULTPTR, WORD, WORD );
WORD	object_affectation( TCVARPTR, RESULTPTR );
WORD	translate_object_member( TCVARPTR );
WORD	translate_member_statement( VOID );
WORD	translate_event_member( VOID );
WORD	translate_instruction( TCVARPTR );
WORD	translate_local_statement( VOID );
WORD	translate_object_statement( VOID );
TCVARPTR	resolve_parent_object( TCVARPTR );
WORD	build_method_pointer( TCVARPTR, VPTR );
RESULTPTR	translate_method_name( VOID );
RESULTPTR	translate_class_name( VOID );
RESULTPTR	translate_class_number( VOID );
RESULTPTR	translate_object_number( VOID );
RESULTPTR	translate_object_name( VOID );
RESULTPTR	translate_sizeof( VOID );
RESULTPTR	translate_procedure_name(VOID);
RESULTPTR	translate_program_name(VOID);
RESULTPTR	translate_segment_name(VOID);
WORD	base_member_constant( BPTR );
VOID	trace_class_dependance( TCSTRUCTPTR, WORD, WORD );
WORD	translate_macro( VOID );
WORD	translate_endmacro( VOID );
WORD	expand_macro( VOID );
#else
TCSTRUCTPTR	input_class();
TCSTRUCTPTR	allocate_for_structure();
TCSTRUCTPTR	known_structure();
TCSTRUCTPTR	locate_structure();
TCMEMBERPTR	allocate_structure_member();
TCMEMBERPTR	copy_member();
TCMEMBERPTR	locate_baseclass_member();
TCMEMBERPTR	locate_class_member();
TCVARPTR	resolve_member_componant();
TCMEMBERPTR	locate_member();
#endif

#endif	/* _TRSTRUCT_H */
	/* ----------- */

