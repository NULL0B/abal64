/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,2008 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBSYMB.H 				*/
/*		Date 	:	15/07/2008				*/
/*		Version :	3.2b       				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBSYMB_H
#define	_EXDBSYMB_H

#include "stdtypes.h"			/* standard debug header 	*/
#include "exvtype.h"	

#ifndef	PTR
#define	PTR *
#endif

#ifndef	VERSION666
#define	WORDSIZE	sizeof( unsigned short )
#endif
/*	-----------------------------		*/
/*	Source and Symbols Management 		*/
/*	-----------------------------		*/

#define	DEBUG_EXTENSION ".dbg"
#define TCODE_EXTENSION ".at"

#define	SYMBOL_HASH	57

#define DBSYMBOLS	struct debug_context
#define	XEXTPTR	   	struct extended_control PTR
#define	SYMBOLPTR	struct symbolic_name XPTR
#define XCODEPTR	struct code_control XPTR
#define	CORRESPTR	struct source_link XPTR

#define	TCODEBLOCK	256
#ifdef	ABAL64
#define	HEADERBLOCK	512
#else
#define	HEADERBLOCK	TCODEBLOCK
#endif

#define	FNAME_SYMBOL	1
#define	VNAME_SYMBOL	2
#define	CNAME_SYMBOL	3
#define	PNAME_SYMBOL	4
#define	SNAME_SYMBOL	5
#define	LNAME_SYMBOL	6
#define	MNAME_SYMBOL	7

#define	allocate_for_fname( n ) allocate_for_symbol( n, FNAME_SYMBOL )
#define	allocate_for_vname( n ) allocate_for_symbol( n, VNAME_SYMBOL )
#define	allocate_for_cname( n ) allocate_for_symbol( n, CNAME_SYMBOL )
#define	allocate_for_pname( n ) allocate_for_symbol( n, PNAME_SYMBOL )
#define	allocate_for_sname( n ) allocate_for_symbol( n, SNAME_SYMBOL )
#define	allocate_for_lname( n ) allocate_for_symbol( n, LNAME_SYMBOL )
#define	allocate_for_mname( n ) allocate_for_symbol( n, MNAME_SYMBOL )

/*	Extended block control context	*/
/*	--------------------------	*/
struct	extended_control	{
	EXAWORD	identity;
	};

/*	Code block control context	*/
/*	--------------------------	*/
struct	code_control	{
	EXAWORD	identity;
	EXAWORD	code_sector;
	EXAWORD	code_length;
	EXAWORD	data_sector;
	EXAWORD	data_length;
	EXAWORD	const_sector;
	EXAWORD	const_length;
	EXAWORD	infos_sector;
	EXAWORD	infos_length;
	EXAWORD	options;
	};

/*	Correspondance entre tcode et source (pour pt arret) */
/*	---------------------------------------------------- */
struct	source_link	{
	EXAWORD		tcode_offset;
	EXAWORD		file_number;
	EXALONG		file_offset;
	EXAWORD		level;
	EXAWORD		nature;
	CORRESPTR	next;
	CORRESPTR	previous;
	};

/*	Structure of symbolic names list node	*/
/*	-------------------------------------	*/
struct	symbolic_name	{
	SYMBOLPTR	next;			/* Next item in the list	*/
	SYMBOLPTR	previous;		/* Previous item in list	*/
	SYMBOLPTR	nextSameName;		/* Next item in the list	*/
	SYMBOLPTR	previousSameName;	/* Previous item in list	*/
	EXAWORD		number;			/* Identification number	*/
	EXAWORD		nature;			/* Type of Debug Correspondance	*/
						/* 0 : Normal(offsets)		*/
						/* 0 : Normal(offsets)		*/
						/* 1 : Special(lines)		*/
#ifdef	OPTIMISEUR
	EXAWORD		newnumber;		/* Rellocate ID number for AO	*/
#endif
	EXAWORD		hash;			/* Hash sum of name string	*/
	BPTR		name;			/* Pointer to token storage	*/
	EXAWORD		type;			/* Indicates type of specific	*/
	VPTR		special;		/* Pointer to type specific	*/
	BPTR		signature;		/* Signature storage		*/
	SYMBOLPTR	moduleowner;		/* as its name sugests 		*/
	};

/*	Structure of Debug Control context 	*/
/*	----------------------------------	*/
#define	DEBUGPTR struct debug_context PTR

struct	debug_context	{
	EXABYTE		DbHeader[HEADERBLOCK];	/* Debug File control block	 */
	EXABYTE		DbHeaderExt[HEADERBLOCK];/* Debug File control extension */
	EXABYTE		AtHeader[HEADERBLOCK];	/* Program File control block	 */
	SYMBOLPTR	modules;		/* List of source file names	 */
	SYMBOLPTR	sources;		/* List of source file names	 */
	SYMBOLPTR	listes;			/* List of List   file names	 */
	SYMBOLPTR	globals;		/* List of global variable names */
	SYMBOLPTR	locals;			/* List of local  variable names */
	SYMBOLPTR	constants;		/* List of constant names	 */
	SYMBOLPTR	procedures;		/* List of Procedure names	 */
	SYMBOLPTR	segments;		/* List of Segment names	 */
	SYMBOLPTR	libraries;		/* List of library names	 */
	CORRESPTR	linkage;		/* Current correspondance links	 */
	EXAWORD		linktype;		/* Segment or Procedure linkages */
	EXAWORD		linkowner;		/* Block id for Segm or Proc	 */
	SYMBOLPTR	linksymbol;		/* Symbol owning correspondances */
	EXAWORD		ldt_sector;		/* Current Code block LDT sector */	
	EXAWORD		display_mode;	/* Variable display controller	 */
	EXABYTE		programme[65];		/* Program under debug		 */
	EXABYTE		config_name[65];	/* Configuration file name	 */
	EXABYTE		MessageZone[65];	/* Current display message	 */
	EXAWORD		zoom_status;		/* Current Source zoom mode	 */
	/* visual list storage pointers */
	/* ---------------------------- */
	BPTR		ProcNameSelection;
	BPTR		SegmNameSelection;
	BPTR		GlobNameSelection;
	BPTR		LocalNameSelection;
	BPTR		SourceSelection;
	BPTR		LibrarySelection;
	EXAWORD		globalcount;
	BPTR		AtPath;
	// -------------------------------------------
	// IJM 8th June 2021
	// -------------------------------------------
	// the ABAL 64 version has a serious issue when 
	// the xxread of criteria reads data into the
	// the buffers of the streams. It underspills
	// seriously and damages the entire debug zone
	// this next buffer catches that rubbish and
	// saves the debug context.
	// -------------------------------------------
	BYTE		CriteriaUnderspillCatcher[8192];
	DEBUGSTREAM	Stream[ MAXDBSTREAMS ];
	};


#ifdef	_EXDBSYMB_C
	DEBUGPTR 	DebugSymbols;
	DEBUGPTR 	InitialDebugSymbols;
#else	
EXTERN	DEBUGPTR 	DebugSymbols;
EXTERN	DEBUGPTR 	InitialDebugSymbols;
#endif

/*	-------------------------	----------		*/
/*	FUNCTION PROTOTYPES FOR	: 	EXDBSYMB.C		*/
/*	-------------------------	----------		*/
#ifdef CHECK_PROTO_ARGS
VOID		generate_segment_name(BPTR ,EXAWORD);
VOID		forget_correspondances(VOID);
VOID		liberate_symbol_list(SYMBOLPTR );
VOID		release_correspondances(CORRESPTR );
VOID		liberate_symbols_manager(VOID);
VOID		exadb_itoa(BPTR ,EXAWORD);
VOID		exadb_itoh(BPTR ,EXAWORD);
VOID		initialise_symbols_manager(VOID);
EXAWORD		unlock_header(BPTR );
VOID		collect_local_variables( EXAWORD, EXAWORD );

EXAWORD		exadb_strlen(BPTR );
EXAWORD		TcGetWord(BPTR );
EXAWORD		initialise_symbolic_file(BPTR );
EXAWORD		calculate_symbol_hash(BPTR );
EXAWORD		load_global_variables(VOID);
EXAWORD		load_segment_names(VOID);
EXAWORD		load_procedure_names(VOID);
EXAWORD		load_filename_symbols(VOID);
EXAWORD		load_listname_symbols(VOID);
EXAWORD		load_dynamic_libraries(VOID);
EXAWORD		activate_symbols_manager(BPTR );
EXAWORD		compare_symbols(BPTR ,BPTR );
EXAWORD		get_procedure_number(BPTR );
EXAWORD		get_variable_number(BPTR );

BPTR 		get_procedure_name(EXAWORD);
BPTR		get_segment_name(EXAWORD);
BPTR 		exadb_strcpy(BPTR ,BPTR );
BPTR 		exadb_strcat(BPTR ,BPTR );
BPTR 		get_variable_name(EXAWORD);

XCODEPTR 	allocate_for_code_control(EXAWORD);
XCODEPTR 	collect_procedure_infos(EXAWORD);
XCODEPTR 	collect_segment_infos(EXAWORD);

SYMBOLPTR 	allocate_for_symbol(BPTR ,EXAWORD);
SYMBOLPTR 	locate_symbol_number(SYMBOLPTR ,EXAWORD);
SYMBOLPTR 	locate_symbol(SYMBOLPTR ,BPTR );
SYMBOLPTR 	locate_variable_name(BPTR );
SYMBOLPTR 	locate_variable_number(EXAWORD);
SYMBOLPTR 	locate_procedure_number(EXAWORD);
SYMBOLPTR 	locate_procedure_name(BPTR );
SYMBOLPTR 	locate_source_name(BPTR );
SYMBOLPTR 	locate_source_number(EXAWORD);
SYMBOLPTR 	locate_segment_number(EXAWORD);
SYMBOLPTR	locate_any_symbol( BPTR );	
SYMBOLPTR	load_local_variables( SYMBOLPTR );

CORRESPTR 	allocate_for_linkage(VOID);
CORRESPTR 	collect_correspondances(SYMBOLPTR );
CORRESPTR 	locate_correspondance(SYMBOLPTR ,EXAWORD);

#else
VOID		generate_segment_name();
VOID		forget_correspondances();
VOID		liberate_symbol_list( );
VOID		release_correspondances();
VOID		liberate_symbols_manager();
VOID		exadb_itoa();
VOID		exadb_itoh();
VOID		initialise_symbols_manager();
EXAWORD		unlock_header();
VOID		collect_local_variables();

EXAWORD		exadb_strlen();
EXAWORD		TcGetWord();
EXAWORD		initialise_symbolic_file();
EXAWORD		calculate_symbol_hash();
EXAWORD		load_global_variables();
EXAWORD		load_segment_names();
EXAWORD		load_procedure_names();
EXAWORD		load_filename_symbols();
EXAWORD		load_listname_symbols();
EXAWORD		load_dynamic_libraries();
EXAWORD		activate_symbols_manager();
EXAWORD		compare_symbols( );
EXAWORD		get_procedure_number();
EXAWORD		get_variable_number();

BPTR 		get_procedure_name();
BPTR		get_segment_name();
BPTR 		exadb_strcpy( );
BPTR 		exadb_strcat();
BPTR 		get_variable_name();

XCODEPTR 	allocate_for_code_control();
XCODEPTR 	collect_procedure_infos();
XCODEPTR 	collect_segment_infos();

SYMBOLPTR 	allocate_for_symbol();
SYMBOLPTR 	locate_symbol_number();
SYMBOLPTR 	locate_symbol();
SYMBOLPTR 	locate_variable_name();
SYMBOLPTR 	locate_variable_number();
SYMBOLPTR 	locate_procedure_number();
SYMBOLPTR 	locate_procedure_name();
SYMBOLPTR 	locate_source_name();
SYMBOLPTR 	locate_source_number();
SYMBOLPTR 	locate_segment_number();
SYMBOLPTR	locate_any_symbol();	
SYMBOLPTR	load_local_variables();

CORRESPTR 	allocate_for_linkage();
CORRESPTR 	collect_correspondances();
CORRESPTR 	locate_correspondance();

#endif		/*CHECK_PROTO_ARGS */

#endif	/* _EXDBSYMB_H */
	/* ---------- */
