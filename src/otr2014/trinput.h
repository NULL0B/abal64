/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRINPUT.H				*/
/*		Version :	2.1d					*/
/*		Date	:	08/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRINPUT_H
#define	_TRINPUT_H

#define	_INPUT_FILE	0
#define	_INPUT_METHOD	1
#define	_INPUT_VALUE	2
#define	_INPUT_PARAM	3

#define	SOURCEPTR	struct otr_source XPTR
#define	DBGFILEPTR	struct otr_debug_file XPTR
#define	INCLUDEPTR	struct otr_path XPTR
struct	otr_debug_file	{
	BPTR		name;
	WORD		hash;
	WORD		number;
	DBGFILEPTR	next;
	};

struct	otr_path	{
	BPTR		Name;
	INCLUDEPTR	Next;
	};

/*
 *	O T R _ S O U R C E
 *	-------------------
 *	Describes the current Source or Input Context
 *	which may be either a source file or a macro
 *	value block.
 *
 *	Macro value blocks may be Auto Concatenating
 *	or manual.
 *	
 */

#define	MAX_INPUT_LINE_BUFFER 1024

struct	otr_source	{

	WORD		Nature;			/* 0 : File, 1 : Macro	*/
	WORD		Status;			/* 1 : Auto, 0 : Manual */

	union 	otr_source_access {
		FILEPTR		Handle;		/* Include File Handle	*/
		VALUEPTR	Macro;		/* Macro Value  Handle	*/
		} Source;

	BYTE		Buffer[MAX_INPUT_LINE_BUFFER];/* Input Line Buffer	*/
	BYTE		Name[256];		/* Input FileName	*/
	LONG		Lines;			/* Current Linecount	*/
	WORD		Level;			/* Current Source Depth */
	WORD		Index;			/* Current Buffer usage	*/
	WORD		Number;			/* Include File Number  */
	LONG		Indent;			/* Lseek equivance	*/
	LONG		LineStart;		
	BPTR		LinePointer;		/* Stores Previous	*/
	VPTR		Parameters;		/* Macro Parameters	*/
	VPTR		Object;			/* Parent Object	*/
	VPTR		Method;			/* Parent Method	*/
	WORD		Label;			/* Parent End Label	*/
	WORD		BalComment;		/* Stores Bal Status	*/
	VPTR		Variables;		/* Locked Variables	*/
	VPTR		Results;		/* Locked Results	*/
	WORD		Registers;		/* Locked Registers	*/
						/* -------------------- */
	SOURCEPTR	next;

#ifdef	ABAL32A
	/* --------------------------------------------------------------- */
	/* These have been added to allow character set encoding on a file */
	/* by file basis for Alliadis/Alliance October 2007 by IJM	   */
	/* --------------------------------------------------------------- */
	BPTR		encoding;		/* encoding of this file */
	WORD		encmode;		/* switch for the above	 */
	WORD		encflag;		/* ICONV Encoding Open	 */
	VPTR		enchandle;		/* ICONV Handle */
	/* --------------------------------------------------------------- */
#endif
	};

#define	_ABAL_ENCODING	"ABAL"
#define	_ANSI_ENCODING	"ANSI"
#define	__ABAL_ENCODING	0
#define	__ANSI_ENCODING	1
#define	__FILE_ENCODING	2
#define	__ICNV_ENCODING	3

#ifdef	_TRINPUT_C

SOURCEPTR	Input=(SOURCEPTR) 0;
DBGFILEPTR	SymbolicFile=(DBGFILEPTR) 0;
INCLUDEPTR	IncludePath=(INCLUDEPTR) 0;
INCLUDEPTR	IncludeLast=(INCLUDEPTR) 0;

INCLUDEPTR	LibraryPath=(INCLUDEPTR) 0;
INCLUDEPTR	LibraryLast=(INCLUDEPTR) 0;

#endif

#ifndef	UNIX
VOID	drop_memory_source( VOID );
WORD	liberate_for_input( VOID );
WORD	drop_source_context( VOID );
VOID	symbolic_file_name( WORD, BPTR );
WORD	symbolic_file_number( BPTR );
WORD	pop_source_context( WORD );
WORD	recover_input_context( VOID );
WORD	recover_source_context( VOID );
WORD	memory_source( VOID );
WORD	xmemory_source( VOID );
WORD	get_source_character( VOID );
WORD	input_line( VOID );
BPTR	get_input_line( VOID );
VOID	echo_line_prefix( VOID );
WORD	context_translation( VOID );
WORD	continue_translation( WORD );
WORD	file_translation( VOID );
SOURCEPTR	allocate_for_source( VOID );
WORD	evaluate_filename( BPTR );
WORD	prepare_filename( SOURCEPTR, BPTR, BPTR, SOURCEPTR );
VOID	slash_conversion( char * );
WORD	use_include_paths( SOURCEPTR );
VOID	add_include_path( BPTR );
WORD	goto_input_label( VOID );
WORD	establish_value_input( VALUEPTR );
VOID	set_method_infos( WORD, WORD, WORD );
WORD	establish_macro_input( VPTR, VPTR, VALUEPTR, VPTR, WORD);
WORD	establish_parameter_input( VPTR, VPTR, VALUEPTR, VPTR );
WORD	include_source_file( BPTR, BPTR );
WORD	block_translation( BPTR );
BPTR	source_file_name( VOID );
WORD	source_file_line( VOID );
WORD	current_file_line( VOID );
WORD	current_file_level( VOID );
WORD	initialise_input( BPTR );
VOID	terminate_input( VOID );
BPTR	current_error_context( VOID );
BPTR	next_error_context( VOID );
VOID	localise_error( BPTR, LONG*, WORD* );
VOID	trace_inclusion_context( VOID );
WORD	localise_trace_error( BPTR, WORD );
VOID	localise_state_change( STATEPTR );
VOID	localise_eof_error( STATEPTR );
WORD	current_file_indent( VOID );
LONG	current_file_offset( VOID );
WORD	current_file_number( VOID );
WORD	current_file_segment( VOID );
VPTR	input_parameters( VOID );
VOID	establish_input_object( VPTR );
VPTR	input_object( VOID );
VPTR	input_method( VOID );
WORD	current_invocation_counter( VOID );
WORD	flush_filenames( VOID );
WORD	verify_world_list( VOID );
WORD	terminate_world_input( int );
WORD	use_abal_charset( VOID );
WORD	use_ansi_charset( VOID );
WORD	load_input_charset( BPTR );
int	use_library_path( BPTR, int );
VOID	add_library_path( BPTR );
WORD	build_linker_default_options(BPTR );
#else
VOID	terminate_input();
WORD	initialise_input();
WORD	file_translation();
BPTR	get_input_line();
VPTR	input_object();
VPTR	input_method();
VPTR	input_parameters();
LONG	current_file_offset();
WORD	current_invocation_counter();
int	use_library_path();
WORD	build_linker_default_options( );
#endif

#endif	/* _TRINPUT_H */
	/* ----------- */


