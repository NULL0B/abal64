/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TROUTPUT.H				*/
/*		Version :	2.1d					*/
/*		Date	:	08/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TROUTPUT_H
#define	_TROUTPUT_H

#define	HEADERSIZE	256
#define	SECTORSIZE	256

#define	OFFSET_TIMESTAMP	0x00F0

#define	SECTORPTR	struct otr_sector XPTR
#define	OUTPUTPTR	struct otr_output XPTR

struct	otr_sector	{
	SECTORPTR	next;
	BYTE		buffer[256];
	};

#if	otr32 || otr64
#define	MAXOTRSECTORS 	0x00010000
#else
#define	MAXOTRSECTORS	256
#endif

#define	MAXSECTORMASK	(MAXOTRSECTORS-1)
#define	SECTORMASK	(SECTORSIZE-1)
#define	BYTEMASK	0x00FF

struct	otr_output	{
	SECTORPTR	CodeSectors[MAXOTRSECTORS];
	WORD		OutputHandle;
	BYTE		FilenameRoot[128];
	BYTE		OutputName[128];
	BYTE		ObjectName[128];
	BYTE		ResultName[128];
	BYTE		OutputBuffer[SECTORSIZE];
	WORD		OutputIndex;
	WORD		OutputBytes;
	LONG		OutputPosition;
	LONG		CodePosition;
	WORD		OutputSector;
	WORD		CodeSector;
	WORD		CryptCode;
	WORD		AcceleratorOutputBytes;
	};

#ifdef	_TROUTPUT_C

SECTORPTR	SectorHeap;

WORD		DebugHandle;
BYTE		DebugName[256];

OUTPUTPTR	Target;
OUTPUTPTR	TcodeTarget;
OUTPUTPTR	DebugTarget;

WORD		NewLineStatus;

#endif

#ifndef	UNIX

VOID	AllowAutoConv( WORD mode );
WORD	IsAutoConv( VOID );
VOID	next_sector( VOID );
VOID	first_sector( VOID );
VOID	reset_output( VOID );
VOID	tcputlong( BPTR, long );
VOID	write_target( VOID );
WORD	current_target_sector( VOID );
WORD	current_sector_offset( VOID );
WORD	current_tcode_offset( VOID );
VOID	echo_target_offset( FILE * );
VOID	print_hex_nibble( WORD );
VOID	trace_output( VOID );
SECTORPTR	allocate_for_sector( VOID );
VOID	store_sector( VOID );
VOID	flush_to_target( VOID );
VOID	set_accelerator_begin();
VOID	set_accelerator_end();
VOID	tcputbyte( WORD );
VOID	tcputword( WORD );
VOID	tcputbyte_at( WORD* piSect, WORD* piBuf, WORD v );
VOID	tcputword_at( WORD* piSect, WORD* piBuf, WORD v );
VOID	force_newline( VOID );
VOID	signal_new_line(WORD);
VOID	inhibit_source_newline( VOID );
WORD	tcode_integer( WORD );
VOID	tcode_string( BPTR );
#ifdef	WITH_NURAL
WORD	generate_nurone_entry( NURONETPTR, NURONEPTR );
#endif
VOID	symbolic_module_entry( BPTR, WORD );
VOID	symbolic_file_entry( BPTR, WORD );
WORD	tcode_instruction( WORD );
WORD	tcode_label( WORD );
WORD	implicite_label( WORD );
WORD	tcode_constant( TCCONPTR );
WORD	tcode_variable( TCVARPTR );
WORD	tcode_variable_offset( TCVARPTR );
WORD	tcode_register( WORD );
VOID	output_symbolic_variable( TCVARPTR );
VOID	reset_byte_count( VOID );
WORD	output_byte_count( VOID );
WORD	next_debug_sector( VOID );
VOID	symbolic_segment_entry( TCSEGPTR );
VOID	symbolic_procedure_entry( TCPRCPTR );
VOID	start_symbolic_procedures( VOID );
VOID	start_symbolic_segments( VOID );
WORD	start_export_procedures( VOID );
VOID	export_procedure_record( TCPRCPTR );
WORD	tc_operand( WORD );
VOID	tcode_operand( RESULTPTR );
WORD	of_requires_register( VOID );
WORD	of_release_register( VOID );
WORD	instruction_requires_LDV( int ) ;
WORD	implicite_on_error( TCVARPTR, WORD, WORD );
WORD	explicite_on_error( TCVARPTR, WORD, BPTR );
WORD	tcode_library_identity( TCDLBPTR, WORD);
WORD	tcode_procedure_identity( WORD );
WORD	tcode_procedure( TCPRCPTR );
WORD	flush_clp( PRCPTR );
WORD	store_clp( PRCPTR, RESULTPTR, WORD );
VOID	liberate_clp( PRCPTR );
WORD	clp_explicite_label( PRCPTR );
WORD	clp_implicite_label(PRCPTR, WORD );
WORD	clp_error_trap( PRCPTR );
PRCPTR	start_prc( TCPRCPTR, TCTYPPTR );
WORD	activate_procedure( TCPRCPTR, RESULTPTR, TCPRCPTR );
WORD	negate_register( RESULTPTR );
WORD	negate_variable( RESULTPTR );
WORD	tc_compare( WORD );
WORD	tc_arithmetic( WORD );
WORD	explicite_ldi( WORD, WORD );
WORD	dimensioned_variable( TCVARPTR );
WORD	alias_affectation( TCVARPTR, RESULTPTR );
RESULTPTR	force_ensure_register( RESULTPTR );
WORD	variable_to_variable( TCVARPTR, TCVARPTR );
VOID	tcode_segment_word( WORD );
VOID	flush_sector( VOID );
VOID	flush_debug_sector( VOID );
WORD	terminate_procedure_table( VOID );
WORD	terminate_segment_table( VOID );
WORD	terminate_external_segments( VOID );
WORD	terminate_external_procedures( VOID );
WORD	terminate_external_fields( VOID );
WORD	terminate_library_modules( VOID );
VOID	commit_code_block( VOID );
WORD	get_sector_byte( WORD );
WORD	get_sector_word( WORD );
VOID	put_sector_byte( WORD, WORD );
VOID	put_sector_word(WORD, WORD );
WORD	backpatch_label( WORD, WORD );
WORD	backpatch_value( WORD, WORD );
WORD	terminate_code_block( VOID );
VOID	bufferise_sectors( VOID );
VOID	terminate_correspondances( TCDBGPTR );
VOID	start_correspondances( TCDBGPTR );
VOID	start_code_block( VOID );
BPTR	abal_crypt( WORD16 , BPTR , WORD16 ,WORD16);
OUTPUTPTR	terminate_target_context( OUTPUTPTR, WORD );
WORD	set_target_encryption( WORD );
WORD	get_target_encryption( VOID );
OUTPUTPTR	create_target_context( BPTR, BPTR, BPTR, BPTR );
VOID	use_debug_file( VOID );
VOID	use_tcode_file( VOID );
BPTR	get_target_root( VOID );
WORD	initialise_apl_output( BPTR );
WORD	initialise_output( BPTR );
VOID	terminate_output( VOID );

WORD	generate_retseg( VOID );
WORD	generate_byte( WORD );
WORD	generate_constant( TCCONPTR );
VOID	generate_data_item( WORD, WORD, BPTR );
WORD	generate_descriptor( TCVARPTR, WORD );
WORD	generate_data_table( TCVDTPTR, FIELDPTR, WORD );
VOID	generate_function_entry( TCDLBPTR );
VOID	generate_procedure_paratypes( TCPRCPTR );
WORD	generate_cross_references( XREFPTR );
VOID	generate_code_rellocation( RELOCPTR );
VOID	generate_library_rellocation( WORD, RELOCPTR );
WORD	generate_external_member( XTVARPTR );
VOID	generate_external_procedure( TCPRCPTR );
VOID	generate_external_local( XTLOCALPTR );
VOID	generate_external_field( XTFIELDPTR );
VOID	generate_external_segment_entry( XTSEGPTR );
VOID	generate_data_label( TCLABELPTR );
VOID	generate_segment_entry( TCSEGPTR );
VOID	generate_procedure_entry( TCPRCPTR );
WORD	generate_pause( RESULTPTR );
WORD	generate_push( WORD );
WORD	generate_pop( WORD );
WORD	generate_proc_end( VOID );
WORD	generate_exit( RESULTPTR );
WORD	generate_segm_end( VOID );
WORD	generate_error_abort( VOID );
WORD	generate_of( RESULTPTR, WORD );
WORD	generate_on_timer( RESULTPTR, WORD );
WORD	generate_error( RESULTPTR );
WORD	generate_event_type( WORD );
WORD	generate_event_false( VOID );
WORD	generate_event_start( VOID );
WORD	generate_event( VOID );
WORD	generate_extern_event( WORD, WORD );
WORD	generate_event_call( TCPRCPTR, TCVARPTR, WORD );
WORD	generate_event_off( VOID );
WORD	generate_ngf( WORD );
VOID	generate_clp_identity( RESULTPTR );
WORD	generate_clp( VOID );
WORD	generate_lde( VOID );
WORD	generate_ldf( TCDLBPTR );
WORD	generate_clf( WORD, WORD );
WORD	generate_iof( VOID );
WORD	generate_fio( VOID );
WORD	generate_fmt( BPTR );
VOID	generate_format_label( BPTR );
WORD	generate_iof_instruction( WORD, RESULTPTR );
WORD	generate_iof_format( WORD, BPTR );
WORD	generate_iof_hotkey( HOTPTR );
RESULTPTR	generate_increment( RESULTPTR );
RESULTPTR	generate_decrement( RESULTPTR );
RESULTPTR 	generate_conversion( RESULTPTR, WORD );
WORD	generate_first_dimension( WORD, RESULTPTR );
WORD	generate_next_dimension( WORD, RESULTPTR );
WORD	generate_dimensions( WORD, TCVARPTR );
WORD	generate_op( RESULTPTR, BPTR );
WORD	generate_copy_register( WORD, WORD );
RESULTPTR	generate_register_load( RESULTPTR, RESULTPTR, WORD );
WORD	generate_label( WORD );
WORD	generate_compare( WORD, RESULTPTR, RESULTPTR, WORD, WORD);
RESULTPTR	generate_arithmetic( WORD, RESULTPTR, RESULTPTR, RESULTPTR );
WORD	generate_optimised_sti( TCVARPTR, WORD );
WORD	generate_affectation( TCVARPTR, RESULTPTR, WORD );
WORD	generate_stop( VOID );
WORD	generate_new( VOID );
WORD	generate_raz( VOID );
WORD	generate_retseg( VOID );
WORD	generate_clfendseg( RESULTPTR );
WORD	generate_call_segment( TCVARPTR );
WORD	generate_ldgoseg( RESULTPTR, WORD, WORD );
WORD	generate_return( VOID );
WORD	generate_resume( WORD, WORD );
WORD	generate_goto_register( RESULTPTR );
WORD	generate_gosub_register( RESULTPTR );
WORD	generate_goto( WORD );
WORD	generate_iteration( VOID );
WORD	generate_abandon( VOID );
WORD	generate_gosub( WORD );
WORD	generate_gosub_label( BPTR );
WORD	generate_read_data( RESULTPTR );
VOID	generate_header( BPTR, WORD, WORD );
VOID	generate_tcode_header( BPTR, WORD );
VOID	generate_debug_header( BPTR, WORD );
WORD	generate_comment( WORD );
#else
RESULTPTR	generate_conversion();
RESULTPTR	generate_register_load();
RESULTPTR	generate_arithmetic();
RESULTPTR	generate_increment();
RESULTPTR	generate_decrement();
WORD	of_release_register();
WORD	terminate_library_modules();
#endif

#endif	/* _TROUTPUT_H */
	/* ----------- */
