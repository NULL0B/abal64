/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRDIRECT.H				*/
/*		Version :	2.1d					*/
/*		Date	:	21/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRDIRECT_H
#define	_TRDIRECT_H

#define	DIRECTIVE_MAX	29

#ifdef	_TRDIRECT_C

static	BPTR	otr_directive[ DIRECTIVE_MAX ] = {
	(BPTR) "IFDEF",
	(BPTR) "ELSE",
	(BPTR) "ENDIF",
	(BPTR) "UNDEF",
	(BPTR) "INCLUDE",
	(BPTR) "PRAGMA",
	(BPTR) "MEM",
	(BPTR) "FILES",
	(BPTR) "STACK",
	(BPTR) "HEAP",
	(BPTR) "USER",
	(BPTR) "IFNDEF",
	(BPTR) "DEF",
	(BPTR) "DEFINE",
	(BPTR) "CLASS",
	(BPTR) "ENDCLASS",
	(BPTR) "STRUCT",
	(BPTR) "ENDSTRUCT",
	(BPTR) "UNION",
	(BPTR) "ENDUNION",
	(BPTR) "MACRO",
	(BPTR) "ENDMACRO",
	(BPTR) "IFEXIST",
	(BPTR) "IFNEXIST",
	(BPTR) "ERROR",
	(BPTR) "EOFIFDEF",
	(BPTR) "EOFIFNDEF",
	(BPTR) "USE",
	(BPTR) "RDEF"
	};

#endif

#define	_OTR_IFDEF 	0
#define	_OTR_ELSE  	1
#define	_OTR_ENDIF 	2
#define	_OTR_UNDEF 	3
#define	_OTR_INCLUDE	4
#define	_OTR_PRAGMA	5
#define	_OTR_MEM   	6
#define	_OTR_FILES 	7
#define	_OTR_STACK 	8
#define	_OTR_HEAP  	9 
#define	_OTR_USER  	10
#define	_OTR_IFNDEF	11
#define _OTR_DEF	12

#define	_OTR_DEFINE	13
#define	_OTR_CLASS	14
#define	_OTR_ENDCLASS	15
#define	_OTR_STRUCT	16
#define	_OTR_ENDSTRUCT	17
#define	_OTR_UNION	18
#define	_OTR_ENDUNION	19
#define	_OTR_MACRO 	20
#define	_OTR_ENDMACRO	21

#define	_OTR_IFEXIST 	22
#define	_OTR_IFNEXIST	23
#define	_OTR_ERROR	24

#define	_OTR_EOFIFDEF	25
#define	_OTR_EOFIFNDEF	26

#define	_OTR_USE	27
#define	_OTR_RDEF	28

#ifndef	UNIX

WORD	pragma_exit( VOID );
WORD	pragma_throw( VOID );
WORD	pragma_swap_size( VOID );
WORD	pragma_page_size( VOID );
WORD	is_pragma_announce( WORD );
WORD	is_directive( VOID );
WORD	is_pragma( BPTR );
BPTR	resolve_definition( BPTR );
WORD	is_active_region( VOID );
WORD	add_definition( BPTR, WORD );
WORD	add_host_definition( BPTR );
WORD	terminate_world_endif( VOID );
WORD	active_warning( WORD );
VOID	activate_warnings( BPTR );
VOID	release_defined_pragmas( VOID );
WORD	get_pragma_output( VOID );
BPTR	set_pragma_output( BPTR );
WORD	pragma_swap_buffers( VOID );
WORD	is_directive_endmacro( VOID );
WORD	translate_directive( WORD );
WORD	liberate_definitions( VOID );
VOID	initialise_definitions( VOID );

/* For trworld.c */
VOID    terminate_world_list( VOID );
WORD    terminate_world( VOID );
WORD    set_world_virtual( VOID );
WORD    get_world_virtual( VOID );
WORD    initialise_world( VOID );
WORD    enter_world( VOID );
WORD    leave_world( VOID );
WORD    flush_world_members( VOID );
WORD    class_enhanced_indirect( TCSTRUCTPTR );
WORD    world_enhanced_indirect( VOID );
WORD    member_enhanced_indirect( TCMEMBERPTR );
BPTR    world_editor( VOID );
BPTR    world_errorfile( WORD );
BPTR    world_listfile( WORD );
BPTR    world_tracefile( WORD );
WORD    set_world_editor( BPTR );
WORD    set_world_errorfile( BPTR, BPTR );
WORD    set_world_listfile( BPTR, BPTR );
WORD    set_world_tracefile( BPTR );

#else
BPTR	set_pragma_output( BPTR );
#endif

#endif	/* _TRDIRECT_H */
	/* ----------- */

