#ifndef __EXPROW16_HH__
#define __EXPROW16_HH__

#ifdef WIN16
#define WIN1632
#endif

#ifdef WIN32
#define WIN1632
#define LINT_ARGS
#endif

#ifdef LINT_ARGS

VOID liberate_dynamic_libraries(void);			// EXLDF

EXAWORD prepare_jointure(BPTR,EXAWORD,EXAWORD,BPTR);		// EXBD
EXAWORD dbprep(EXAWORD,EXAWORD,BPTR,EXAWORD);

EXAWORD exatoi(BPTR,EXAWORD);					// EXCALC
EXAWORD exio_getch(void);
void x_bell(void);
void exio_putch(EXAWORD);

EXAWORD simulate_mimo(void);				// EXCLF
EXAWORD event_spawn(void);
EXAWORD set_mimo_curser(EXAWORD);
void set_time_factor(EXAWORD);
void IpcRaise(EXAWORD);
void IpcDrop(EXAWORD);
void IpcSynch(EXAWORD);
void loudspeaker(EXAWORD);
EXAWORD event_kill(EXAWORD);
void IpcInterrupt(EXAWORD);
EXAWORD disactivate_procedure(void);
EXAWORD push_tcode_offset(void);
EXAWORD activate_procedure(EXAWORD,EXAWORD);
EXAWORD ll_loadgo(BPTR,BPTR);
void establish_pointer_variable(BPTR,BPTR,EXAWORD);
void special_procedure_push(void);
EX_FILE_HANDLE CloseTcodeFile(EX_FILE_HANDLE);
void liberate_procedure_table(struct procform SPTR,EXAWORD);
EXAWORD version_verification(EXAWORD,EXAWORD,EXAWORD,EXAWORD);
EX_FILE_HANDLE open_tcode_file(BPTR);
EXAWORD IpcSend(EXAWORD,BPTR,EXAWORD);
void set_national_characteristics(EXAWORD);
BPTR initialise_data_image(BPTR,BPTR,EXAWORD);
void release_dynamic_library(EXAWORD);
EXAWORD majimini(EXAWORD);
EXAWORD fn_parser(BPTR,BPTR,EXAWORD);
EXAWORD IpcRecv(EXAWORD,BPTR,EXAWORD,EXAWORD);
EXAWORD activate_cico_printer(EXAWORD);
EXAWORD error_trapping_status(void);
EXAWORD extended_page_counter(void);
void release_procedure(struct procform SPTR,EXAWORD);
void procedure_release(struct procform SPTR,EXAWORD,EXAWORD);
void release_segment(EXAWORD);
EXAWORD loaded_procedures(void);
EXAWORD procedure_callers(EXAWORD);
EXAWORD procedure_loaded(EXAWORD);
VOID clf_procedure_release(EXAWORD,EXAWORD);

EX_FILE_HANDLE OpenTcodeFile(BPTR);			// EXCODE
void disable_hard_event(void);
void release_error_traps(void);
void enable_hard_event(void);
EXAWORD kode_b_lode(BPTR,EXAWORD,EXAWORD);
EXAWORD check_for_error_pop(void);
void establish_pointer_variable(BPTR,BPTR,EXAWORD);
EXAWORD connect_program_procedure(BPTR);
void collect_indirect_gds(void);

EXAWORD f_rte(EXAWORD);					// EXESC

EXAWORD llio_open(BPTR);					// EXFLOPPY
EXAWORD Media_Type(EXAWORD);
EXAWORD floppy_io(EXAWORD,BPTR,EXAWORD,EXAWORD);

void initialise_task_control(void);			// EXI
void reset_indirection_control(void);
void initialise_dynamic_allocation(void);
void initialise_attachments(void);
void liberate_task_control(void);
void LiberateProcedureTable(EXAWORD);
void LiberateSegmentContext(void);
void LiberateSegmentTable(void);
void liberate_assign_allocation(void);
void liberate_attachments(void);
void liberate_indirection_control(void);
void liberate_dynamic_allocation(void);
void release_error_traps(void);
EXAWORD InitQalloc(void);
EXAWORD initialise_assign_allocation(EXAWORD,EXAWORD);
void iof_reset(void);
void initialise_indirection_control(void);
void ensure_parent(void);
EXAWORD check_for_error_pop(void);
void InitPop(void);
void InitPop2(void);

EXAWORD iof_atb(EXAWORD);					// EXIO
EXAWORD iof_format_string(BPTR,EXAWORD);
EXAWORD iof_format_value(EXAWORD);
void iof_backgr(EXAWORD);
void iof_foregr(EXAWORD);
EXAWORD iof_device(EXAWORD);
EXAWORD iof_device_buffer(BPTR,EXAWORD);
void iof_gosub_num_hotkey(EXAWORD,EXAWORD);
void iof_goto_num_hotkey(EXAWORD,EXAWORD);
void iof_gosub_hotkeys(BPTR,EXAWORD,EXAWORD);
void iof_goto_hotkeys(BPTR,EXAWORD,EXAWORD);
EXAWORD set_preferentiel(void);
void reset_preferentiel(EXAWORD);
void undo_ask_action(EXAWORD);
EXAWORD iof_print_int(EXAWORD,EXAWORD);
EXAWORD iof_print_bcd(BPTR,EXAWORD);
EXAWORD iof_print_str(BPTR,EXAWORD);
void iof_tabl(EXAWORD);
void iof_tabc(EXAWORD);
void iof_tabv(EXAWORD);
void iof_start(void);
void IpcRaise(EXAWORD);
void IpcDrop(EXAWORD);
EXAWORD iof_flush(void);
void atb(EXAWORD);
void x_bell(void);
EXAWORD activate_cico_printer(EXAWORD);
void update_cico_printer(void);
void initermexa(EXAWORD);

EXAWORD indirect_procedure_call(BPTR);			// EXLDF
EXAWORD indirect_segment_call(BPTR);
void IpcRaise(EXAWORD);
void IpcDrop(EXAWORD);

EXAWORD IsAbalExtendedDos(void);				// EXMAIN
EXAWORD fn_parser(BPTR,BPTR,EXAWORD);
void iof_liberation(void);
void iof_initialisation(void);
void reset_mima_lang(void);
void reset_task_manager(void);
void set_time_factor(EXAWORD);
BPTR dedicated(void);
BPTR IsDedicated(void);

void liberate_virtual_machine(void);			// EXMOTOR
EXAWORD get_lineptr_ip(void);

void close_base_files(EXAWORD);				// EXNGF
EXAWORD fn_parser(BPTR,BPTR,EXAWORD);
EXAWORD TcodeFileName(BPTR,BPTR);
EXAWORD ExaCute(BPTR);
EXAWORD creat(BPTR,EXAWORD);
EXAWORD remove_bd_record(EXAWORD,EXAWORD);

EXAWORD pop_error_context(void);				// EXSWIT
EXAWORD compbcd(EXAWORD,BPTR,BPTR);
EXAWORD activate_external_event(EXAWORD,EXAWORD);
EXAWORD disactivate_external_event(void);
void liberate_virtual_machine(void);

EXAWORD creat(BPTR,EXAWORD);					// EXTVARB

EXAWORD get_ask_event(EXAWORD);				// EXIOFUNC
VOID set_ask_event(EXAWORD,EXAWORD);
VOID iof_insert_flag(void);
EXAWORD iof_special_hotkey(EXAWORD,EXAWORD);

VOID IpcIncrement(EXAWORD);				// EXLINDA
VOID IpcDecrement(EXAWORD);

VOID set_decimal_point(EXABYTE);				// EXBCD
VOID clf_swap(VOID);

VOID liberate_for_on_error(VOID);			// apparu en 2.1d
VOID initialise_mallocate(VOID);
EXAWORD allocated_error_traps(VOID);
EXAWORD get_allocation_tracer(VOID);
EXAWORD get_allocation_counter(VOID);
EXAWORD get_liberation_counter(VOID);
EXAWORD check_implicite_join_file(BPTR);

VOID set_swap_message(VPTR);				// 2.1d > 13/10/95


#else /* ----------------- LINT_ARGS ----------------- */



VOID liberate_dynamic_libraries();

EXAWORD prepare_jointure();
EXAWORD dbprep();

EXAWORD exatoi();
EXAWORD exio_getch();
void x_bell();
void exio_putch();

EXAWORD simulate_mimo();
EXAWORD event_spawn();
EXAWORD set_mimo_curser();
void set_time_factor();
void IpcRaise();
void IpcDrop();
void IpcSynch();
void loudspeaker();
EXAWORD event_kill();
void IpcInterrupt();
EXAWORD disactivate_procedure();
EXAWORD push_tcode_offset();
EXAWORD activate_procedure();
EXAWORD ll_loadgo();
void establish_pointer_variable();
void special_procedure_push();
EX_FILE_HANDLE CloseTcodeFile();
void liberate_procedure_table();
EXAWORD version_verification();
EX_FILE_HANDLE open_tcode_file();
EXAWORD IpcSend();
void set_national_characteristics();
BPTR initialise_data_image();
void release_dynamic_library();
EXAWORD majimini();
EXAWORD fn_parser();
EXAWORD IpcRecv();
EXAWORD activate_cico_printer();
EXAWORD error_trapping_status();
EXAWORD extended_page_counter();
void release_procedure();
void procedure_release();
void release_segment();
EXAWORD loaded_procedures();
EXAWORD procedure_callers();
EXAWORD procedure_loaded();
VOID clf_procedure_release();

EX_FILE_HANDLE OpenTcodeFile();
void disable_hard_event();
void release_error_traps();
void enable_hard_event();
EXAWORD kode_b_lode();
EXAWORD check_for_error_pop();
void establish_pointer_variable();
EXAWORD connect_program_procedure();
void collect_indirect_gds();

EXAWORD f_rte();

EXAWORD llio_open();
EXAWORD Media_Type();
EXAWORD floppy_io();

void initialise_task_control();
void reset_indirection_control();
void initialise_dynamic_allocation();
void initialise_attachments();
void liberate_task_control();
void LiberateProcedureTable();
void LiberateSegmentContext();
void LiberateSegmentTable();
void liberate_assign_allocation();
void liberate_attachments();
void liberate_indirection_control();
void liberate_dynamic_allocation();
void release_error_traps();
EXAWORD InitQalloc();
EXAWORD initialise_assign_allocation();
void iof_reset();
void initialise_indirection_control();
void ensure_parent();
EXAWORD check_for_error_pop();
void InitPop();
void InitPop2();

EXAWORD iof_atb();
EXAWORD iof_format_string();
EXAWORD iof_format_value();
void iof_backgr();
void iof_foregr();
EXAWORD iof_device();
EXAWORD iof_device_buffer();
void iof_gosub_num_hotkey();
void iof_goto_num_hotkey();
void iof_gosub_hotkeys();
void iof_goto_hotkeys();
EXAWORD set_preferentiel();
void reset_preferentiel();
void undo_ask_action();
EXAWORD iof_print_int();
EXAWORD iof_print_bcd();
EXAWORD iof_print_str();
void iof_tabl();
void iof_tabc();
void iof_tabv();
void iof_start();
void IpcRaise();
void IpcDrop();
EXAWORD iof_flush();
void atb();
void x_bell();
EXAWORD activate_cico_printer();
void update_cico_printer();
void initermexa();

EXAWORD indirect_procedure_call();
EXAWORD indirect_segment_call();
void IpcRaise();
void IpcDrop();

EXAWORD IsAbalExtendedDos();
EXAWORD fn_parser();
void iof_liberation();
void iof_initialisation();
void reset_mima_lang();
void reset_task_manager();
void set_time_factor();
BPTR dedicated();
BPTR IsDedicated();

void liberate_virtual_machine();
EXAWORD get_lineptr_ip();

void close_base_files();
EXAWORD fn_parser();
EXAWORD TcodeFileName();
EXAWORD ExaCute();
EXAWORD creat();
EXAWORD remove_bd_record();

EXAWORD pop_error_context();
EXAWORD compbcd();
EXAWORD activate_external_event();
EXAWORD disactivate_external_event();
void liberate_virtual_machine();

EXAWORD creat();

EXAWORD get_ask_event();
VOID set_ask_event();
VOID iof_insert_flag();
EXAWORD iof_special_hotkey();

VOID IpcIncrement();
VOID IpcDecrement();

VOID set_decimal_point();
VOID clf_swap();

VOID liberate_for_on_error();			// apparu en 2.1d
VOID initialise_mallocate();
EXAWORD allocated_error_traps();
EXAWORD get_allocation_tracer();
EXAWORD get_allocation_counter();
EXAWORD get_liberation_counter();
EXAWORD check_implicite_join_file();

VOID set_swap_message(VPTR);				// 2.1d > 13/10/95

#endif /* LINT_ARGS */


	/* --------------- */
	/* MIMO Prototypes */
	/* --------------- */
EXTERN	EXAWORD	activate_event_interrupt(BPTR);
EXTERN	VOID	inhibit_event_interrupt(VOID);
EXTERN	VOID	cancel_event_interrupt(VOID);
EXTERN	EXAWORD	set_event_parameter(EXAWORD,EXAWORD);
EXTERN	EXAWORD	get_event_parameter(EXAWORD);
EXTERN	VOID	clear_wakeup_status(VOID);
EXTERN	EXAWORD	verify_wakeup_status(EXAWORD);
EXTERN	VOID	cancel_mimo_alarm(VOID);
EXTERN	VOID	start_mimo_alarm(VOID);

EXTERN	VOID	init_mimo( VOID );
EXTERN	EXAWORD	activate_mimo( VOID );
EXTERN	VOID	inhibit_mimo( VOID );
EXTERN	VOID	flush_mimo( VOID );
EXTERN	VOID	fin_mimo( VOID );

EXTERN	EXAWORD	get_mimo_status( VOID );
EXTERN	EXAWORD	get_mimo_col( VOID );
EXTERN	EXAWORD	get_mimo_lin( VOID );
EXTERN	EXAWORD	get_mimo_par( VOID );
EXTERN	EXAWORD	get_mimo_mask( VOID );
EXTERN	EXAWORD	get_mimo_type( VOID );
EXTERN	VOID	set_mimo_mask( EXAWORD );

EXTERN	VOID	save_mimo_context( BPTR );
EXTERN	VOID	restore_mimo_context( BPTR );

#endif

