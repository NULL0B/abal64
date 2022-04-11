/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1996 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXPROTO1.H  				*/
/*		Version :	1.4a / 2.1d				*/
/*		Date 	:	23/09/1996				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXPROTO1_H
#define	_EXPROTO1_H

#ifdef	ABAL_CRITERIA
#include "exadsqcr.h"
#endif

#ifdef PROLOGUE
#include "exproprl.h"
#endif

#ifdef	WIN16
#include "exprow16.h"
#else
#ifdef	WIN32
#include "exprow32.h"
#else
#ifdef	DOS
#include "exprodos.h"
#endif
#endif
#endif

#ifndef UNIX

	VOID	SegmentTrapWork(EXAWORD);
	BPTR	current_tcode_filename(VOID);
/*------------*/
/*    EXI.C   */
/*------------*/
	BPTR	exa_crypt(EXAWORD,BPTR,EXAWORD,EXAWORD);
/*------------*/
/* EXPARSER.C */
/*------------*/
	EXAWORD	fn_parser(BPTR,BPTR,EXAWORD);
/*------------*/
/*  EXLLIO.C  */
/*------------*/
	VOID	pos(EXAWORD,EXAWORD);
	VOID	x_bstart(VOID);
	VOID	x_bflush(VOID);
	VOID	x_putch(EXAWORD);
	VOID	x_cprintf(BPTR);
/*------------*/
/* EXDBPROC.C */
/*------------*/
	VOID AffProcName( EXAWORD );
	EXAWORD ProcNumb( BPTR );
/*------------*/
/* EXDBAFUN.C */
/*------------*/
	VOID	AsFunInitialise(VOID);
	VOID	AsFun_SwapState(VOID);
	VOID	AsFun_SwapView(VOID);
	VOID	Asfunused(VOID);
	VOID	asfun_program_implicite(VOID);
	VOID	asfun_monitor_implicite(VOID);
/*------------*/
/* EXDBCICO.C */
/*------------*/
	VOID    ColourAtb( EXAWORD );
	VOID    ForceProgram(VOID);
	VOID    UnForceProgram(VOID);
	EXAWORD    LibZone(VOID);
	VOID    MoniteurWindow(VOID);
	VOID    Painter(EXAWORD,EXAWORD);
	EXAWORD    PopZone(VOID);
	VOID    ProgramWindow(VOID);
	VOID    WindowOff(VOID);
	VOID    WindowOn(VOID);
	EXAWORD    ZaddLynes(EXAWORD);
	VOID    db_Cls(VOID);
	VOID    db_Refresh(VOID);
	VOID    db_foregr(EXAWORD);
	VOID    db_backgr(EXAWORD);
	EXAWORD    db_initerm(VOID);
	VOID    db_finterm(EXAWORD);
	EXAWORD    db_opb(VOID);
	VOID    db_ungetch(EXAWORD);
	EXAWORD    db_ungotch(VOID);
	EXAWORD    db_xlin(VOID);
	EXAWORD    db_xcol(VOID);
	VOID    db_xatb(EXAWORD);
	VOID    db_xpos(EXAWORD,EXAWORD);
	VOID    db_xclear(VOID);
	VOID    db_xcprintf(BPTR);
	EXAWORD    db_xgetch(VOID);
	VOID    db_xputch(EXAWORD);
	VOID    toggle_visible_screen(VOID);
	VOID    wdw_xpos(EXAWORD,EXAWORD);
	EXAWORD    wotatb(VOID);
	EXAWORD    wotfore(VOID);
	EXAWORD    wotback(VOID);
/*------------*/
/* EXDBFUNC.C */
/*------------*/
	EXAWORD	CompWild( BPTR, BPTR);
	VOID	Debordement(VOID);
	EXAWORD	ExitMethod(EXAWORD);
	VOID	ParaCharge(VOID);
	VOID	Relancer(BPTR);
	EXAWORD	Validate(EXAWORD);
	VOID	Verbose(BPTR);
	VOID	WdwLimit(EXAWORD,EXAWORD,EXAWORD); 
	EXAWORD	abalask(EXAWORD,EXAWORD,EXAWORD);
	VOID	abalprn(EXAWORD,EXAWORD,EXAWORD);
	VOID	display_assign_table(EXAWORD);
	VOID	fichview(BPTR);	
/*------------*/
/* EXDBMENU.C */
/*------------*/
	EXAWORD	CurrentTcodeOffset(EXAWORD);
#ifndef ABAL21
	VOID	Observe(VOID);
#endif
	VOID	WhereAreWe(EXAWORD,EXAWORD);
	VOID	cancel_window_coordinates(VOID);
	VOID	check_for_local_load(VOID);
	VOID	check_for_stop_status(VOID);
	EXAWORD	check_tcode_location(EXAWORD,EXAWORD,EXAWORD);
	EXAWORD	command_interpreter(BPTR,EXAWORD);
	EXAWORD	current_tcode_block_type(VOID);
	EXAWORD	current_tcode_identity(VOID);
	EXAWORD	current_tcode_offset(VOID);
	EXAWORD	dbmain(VOID);
	EXAWORD	dbvartyp(EXAWORD);
	VOID	execsys(BPTR);
	VOID	idb_restart(EXAWORD);	
	VOID	list_colours(EXAWORD);
	EXAWORD	nametest(BPTR,EXAWORD);
	VOID	previous_correspondance(VOID);
	EXAWORD	test_stop_status(VOID);
	VOID	uppercase_command(BPTR);
	EXAWORD	use_window_coordinates(VOID);
	EXAWORD	valid_local_data(VOID);
	EXAWORD	varmod(BPTR,EXAWORD);
	EXAWORD	window_ccoord(EXAWORD);
	EXAWORD	window_lcoord(EXAWORD);
	EXAWORD	window_fcoord(EXAWORD);
	EXAWORD	window_bcoord(EXAWORD);
/*------------*/
/*  EXDBOBS.C */
/*------------*/
#ifdef	ABAL21
	EXAWORD	Observe( EXAWORD );
#endif
	EXAWORD	avoid_observations(EXAWORD);
	VOID	flush_observations(EXAWORD);
	VOID	initialise_observations(VOID);
	EXAWORD	is_known_observation(EXAWORD);
	VOID	left_string(EXAWORD,EXAWORD,EXAWORD,BPTR);
	VOID	liberate_observations(VOID);
	VOID	observation_list(VOID);
	VOID	observation_management(BPTR);
	VOID	right_string(EXAWORD,EXAWORD,EXAWORD,BPTR);
/*------------*/	
/* EXDBTRAP.C */
/*------------*/
	EXAWORD	ProcedureTrapWork( EXAWORD , EXAWORD );
	VOID	flush_traps(EXAWORD);
	VOID	liberate_overlay_traps(VOID);	
	VOID	posepiege(EXAWORD,EXAWORD,EXAWORD,EXAWORD);
/*------------*/
/* EXDBSYMB.C */
/*------------*/
	EXAWORD	activate_symbols_manager(BPTR);
	VOID	check_global_load(VOID);
	VOID	collect_local_variables(EXAWORD,EXAWORD);
	VOID	configuration_file_name(BPTR,EXAWORD);
	VOID	exadb_itoa(BPTR,EXAWORD);
	EXAWORD	get_procedure_number(BPTR);
	VOID	initial_symbols_manager(VOID);
	VOID	initialise_symbols_manager(VOID);
	VOID	liberate_symbols_manager(VOID);
	VOID	replace_filename_symbol(BPTR,BPTR);
	VOID	reset_message_zone(VOID);
	EXAWORD	resolve_global_variable(BPTR);
	EXAWORD	resolve_local_variable(BPTR);
	VOID	trap_all_procedures(EXAWORD,EXAWORD);
	VOID	trap_all_segments(EXAWORD,EXAWORD);
	EXAWORD	wildcomp( BPTR, BPTR );

  #ifndef DEBUGPTR
  #define	DEBUGPTR struct debug_context SPTR
  #endif
	VOID	force_debug_context(DEBUGPTR);
	VOID	symbolic_detachment(DEBUGPTR);

/*------------*/
/* EXDBTRAC.C */
/*------------*/
	VOID	add_trace_region(EXAWORD,EXAWORD,EXAWORD,EXAWORD);
	VOID	flush_trace_list(EXAWORD);
	VOID	initialise_trace_control(VOID);
	VOID	liberate_trace_control(VOID);
	VOID	trace_control(BPTR);
	EXAWORD	trace_is_active(VOID);
	VOID	traced_regions_list(VOID);
/*------------*/
/* EXDBATTA.C */
/*------------*/
	VOID	attachment_manager(BPTR);
/*------------*/
/*  EXDBUI.C  */
/*------------*/
	VOID	centered_string(EXAWORD,EXAWORD,EXAWORD,BPTR);
	EXAWORD	current_mouse_click(VOID);
#ifdef ABAL21
	VOID	display_hexint(EXAWORD);
	VOID	display_hexbyte(EXAWORD);	
	EXAWORD	display_integer(EXAWORD);
#endif
	EXAWORD	display_variable_declaration(BPTR,EXAWORD);
	VOID	execute_debug_script(BPTR,EXAWORD);
	VOID	initialise_mouse_manager(VOID);
	EXAWORD	mouse_or_keyboard(VOID);
	VOID	mouse_title_box(EXAWORD,EXAWORD,EXAWORD,EXAWORD,BPTR);
	EXAWORD	offer_list_menu(EXAWORD);
	VOID	pop_mouse(VOID);
	EXAWORD	specify_filename(BPTR,EXAWORD);
	VOID	standard_message(BPTR);
	VOID	standard_error(BPTR);
	VOID	standard_errors(EXAWORD);
	EXAWORD	standard_validation(BPTR);
	EXAWORD	standard_exit_check(VOID);
	EXAWORD	standard_command_input(EXAWORD,EXAWORD);
	EXAWORD	standard_integer_ask(BPTR);
	EXAWORD	standard_ask(BPTR,EXAWORD,BPTR,EXAWORD);
	VOID	symbolic_atribut(EXAWORD);
	VOID	symbols_browser(VOID);
	EXAWORD	tcode_correspondance(EXAWORD,EXAWORD,EXAWORD,EXAWORD);
	VOID	trace_all_symbols(EXAWORD);
	VOID	draw_empty_box(EXAWORD,EXAWORD,EXAWORD,EXAWORD);
/*------------*/
/*  EXDBSTD.C */
/*------------*/
	BPTR	exadb_strcpy(BPTR,BPTR);
	BPTR	exadb_strcat(BPTR,BPTR);
	EXAWORD	exadb_strlen(BPTR);
/*------------*/
/* EXDBSTRE.C */
/*------------*/
	VOID	flush_search_path(EXAWORD);
	VOID	initialise_streams(VOID);
	VOID	set_debug_search_path(BPTR);
	VOID	terminate_streams(VOID);
/*------------*/
/* EXDBWTCH.C */
/*------------*/
	VOID	flush_watch_events(EXAWORD);
/*------------*/
/* EXDBFKEY.C */
/*------------*/
	VOID	init_fkey_storage(VOID);
	VOID	liber_fkey_storage(VOID);
	VOID	restore_function_keys(VOID);
	VOID	store_function_keys(VOID);
/*------------*/
/* EXDBHIST.C */
/*------------*/
	VOID	initialise_history(VOID);
	VOID	liberate_history(VOID);
/*------------*/
/*  EXDBCMD.C */
/*------------*/
	VOID newlyne(VOID);
	VOID set_tabulation_size(BPTR);
	VOID showptr(BPTR);
	VOID x_intvisi(EXAWORD);
/*------------*/
/* EXDBSTAK.C */
/*------------*/
	VOID	stack_trace(VOID);

#ifndef	UNIX
#ifndef	VMS
/*------------*/
/*  MOTOR.ASM */
/*------------*/
	EXAWORD adjust_gosub_offset( BPTR, EXAWORD );		/* ??? */
	EXAWORD lldbmotor(EXAWORD); 				/* ??? */

/*------------*/
/* EXCICO.ASM */
/*------------*/
	EXAWORD conf(EXAWORD);
	EXAWORD lcfo(EXAWORD,BPTR,EXAWORD);
	EXAWORD prfo(EXAWORD,BPTR,EXAWORD);
	EXAWORD x_getch(VOID);
#endif
#endif

	/* ----- */
#else	/* !UNIX */
	/* ----- */


	VOID	SegmentTrapWork();		/* EXAWORD */
	BPTR	current_tcode_filename();	/* VOID */
/*------------*/
/*    EXI.C   */
/*------------*/
	BPTR	exa_crypt();	/* EXAWORD,BPTR,EXAWORD,EXAWORD */
/*------------*/
/* EXPARSER.C */
/*------------*/
	EXAWORD	fn_parser();	/* BPTR,BPTR,EXAWORD */
/*------------*/
/*  EXLLIO.C  */
/*------------*/
/*	VOID	pos();	*/	/* EXAWORD  EXAWORD */
	VOID	x_bstart();	/* VOID */
	VOID	x_bflush();	/* VOID */
#if !defined(AVIION) && !defined(RT_AIX) && !defined(LINUX)
	VOID	x_putch();	/* EXAWORD */
	VOID	x_cprintf();	/* BPTR */
#endif
/*------------*/
/* EXDBPROC.C */
/*------------*/
	VOID AffProcName();	/*  EXAWORD  */
	EXAWORD ProcNumb();	/*  BPTR  */
/*------------*/
/* EXDBAFUN.C */
/*------------*/
	VOID	AsFunInitialise();	/* VOID */
	VOID	AsFun_SwapState();	/* VOID */
	VOID	AsFun_SwapView();	/* VOID */
	VOID	Asfunused();	/* VOID */
	VOID	asfun_program_implicite();	/* VOID */
	VOID	asfun_monitor_implicite();	/* VOID */
/*------------*/
/* EXDBCICO.C */
/*------------*/
	VOID    ColourAtb();	/*  EXAWORD  */
	VOID    ForceProgram();	/* VOID */
	VOID    UnForceProgram();	/* VOID */
	EXAWORD    LibZone();	/* VOID */
	VOID    MoniteurWindow();	/* VOID */
	VOID    Painter();	/* EXAWORD,EXAWORD */
	EXAWORD    PopZone();	/* VOID */
	VOID    ProgramWindow();	/* VOID */
	VOID    WindowOff();	/* VOID */
	VOID    WindowOn();	/* VOID */
	EXAWORD    ZaddLynes();	/* EXAWORD */
	VOID    db_Cls();	/* VOID */
	VOID    db_Refresh();	/* VIOD */
	VOID    db_foregr();	/* EXAWORD */
	VOID    db_backgr();	/* EXAWORD */
	EXAWORD    db_initerm();	/* VOID */
	VOID    db_finterm();	/* EXAWORD */
	EXAWORD    db_opb();	/* VOID */
	VOID    db_ungetch();	/* EXAWORD */
	EXAWORD    db_ungotch();	/* VOID */
	EXAWORD    db_xlin();	/* VOID */
	EXAWORD    db_xcol();	/* VOID */
	VOID    db_xatb();	/* EXAWORD */
	VOID    db_xpos();	/* EXAWORD,EXAWORD */
	VOID    db_xclear();	/* VOID */
	VOID    db_xcprintf();	/* BPTR */
	EXAWORD    db_xgetch();	/* VOID */
	VOID    db_xputch();	/* EXAWORD */
	VOID    toggle_visible_screen();	/* VOID */
	VOID    wdw_xpos();	/* EXAWORD,EXAWORD */
	EXAWORD    wotatb();	/* VOID */
	EXAWORD    wotfore();	/* VOID */
	EXAWORD    wotback();	/* VOID */
/*------------*/
/* EXDBFUNC.C */
/*------------*/
	EXAWORD	CompWild();	/*  BPTR, BPTR */
	VOID	Debordement();	/* VOID */
	EXAWORD	ExitMethod();	/* EXAWORD */
	VOID	ParaCharge();	/* VOID */
	VOID	Relancer();	/* BPTR */
	EXAWORD	Validate();	/* EXAWORD */
	VOID	Verbose();	/* BPTR */
	VOID	WdwLimit();	/* EXAWORD,EXAWORD,EXAWORD */ 
	EXAWORD	abalask();	/* EXAWORD,EXAWORD,EXAWORD */
	VOID	abalprn();	/* EXAWORD,EXAWORD,EXAWORD */
	VOID	display_assign_table();	/* EXAWORD */
	VOID	fichview();	/* BPTR */	
/*------------*/
/* EXDBMENU.C */
/*------------*/
	EXAWORD	CurrentTcodeOffset();	/* EXAWORD */
#ifndef ABAL21
	VOID	Observe();	/* VOID */
#endif
	VOID	WhereAreWe();	/* EXAWORD,EXAWORD */
	VOID	cancel_window_coordinates();	/* VOID */
	VOID	check_for_local_load();	/* VOID */
	VOID	check_for_stop_status();	/* VOID */
	EXAWORD	check_tcode_location();	/* EXAWORD,EXAWORD,EXAWORD */
	EXAWORD	command_interpreter();	/* BPTR,EXAWORD */
	EXAWORD	current_tcode_block_type();	/* VOID */
	EXAWORD	current_tcode_identity();	/* VOID */
	EXAWORD	current_tcode_offset();	/* VOID */
	EXAWORD	dbmain();	/* VOID */
	EXAWORD	dbvartyp();	/* EXAWORD */
	VOID	execsys();	/* BPTR */
	VOID	idb_restart();	/* EXAWORD */	
	VOID	list_colours();	/* EXAWORD */
	EXAWORD	nametest();	/* BPTR,EXAWORD */
	VOID	previous_correspondance();	/* VOID */
	EXAWORD	test_stop_status();	/* VOID */
	VOID	uppercase_command();	/* BPTR */
	EXAWORD	use_window_coordinates();	/* VOID */
	EXAWORD	valid_local_data();	/* VOID */
	EXAWORD	varmod();	/* BPTR,EXAWORD */
	EXAWORD	window_ccoord();	/* EXAWORD */
	EXAWORD	window_lcoord();	/* EXAWORD */
	EXAWORD	window_fcoord();	/* EXAWORD */
	EXAWORD	window_bcoord();	/* EXAWORD */
/*------------*/
/*  EXDBOBS.C */
/*------------*/
#ifdef	ABAL21
	EXAWORD	Observe();	/*  EXAWORD  */
#endif
	EXAWORD	avoid_observations();	/* EXAWORD */
	VOID	flush_observations();	/* EXAWORD */
	VOID	initialise_observations();	/* VOID */
	EXAWORD	is_known_observation();	/* EXAWORD */
	VOID	left_string();	/* EXAWORD,EXAWORD,EXAWORD,BPTR */
	VOID	liberate_observations();	/* VOID */
	VOID	observation_list();	/* VOID */
	VOID	observation_management();	/* BPTR */
	VOID	right_string();	/* EXAWORD,EXAWORD,EXAWORD,BPTR */
/*------------*/	
/* EXDBTRAP.C */
/*------------*/
	EXAWORD	ProcedureTrapWork();	/*  EXAWORD , EXAWORD  */
	VOID	flush_traps();	/* EXAWORD */
	VOID	liberate_overlay_traps();	/* BPTR */	
	VOID	posepiege();	/* EXAWORD,EXAWORD,EXAWORD,EXAWORD */
/*------------*/
/* EXDBSYMB.C */
/*------------*/
	EXAWORD	activate_symbols_manager();	/* BPTR */
	VOID	check_global_load();	/* VOID */
	VOID	collect_local_variables();	/* EXAWORD,EXAWORD */
	VOID	configuration_file_name();	/* BPTR,EXAWORD */
	VOID	exadb_itoa();	/* BPTR,EXAWORD */
	EXAWORD	get_procedure_number();	/* BPTR */
	VOID	initial_symbols_manager();	/* VOID */
	VOID	initialise_symbols_manager();	/* VOID */
	VOID	liberate_symbols_manager();	/* VOID */
	VOID	replace_filename_symbol();	/* BPTR,BPTR */
	VOID	reset_message_zone();	/* VOID */
	EXAWORD	resolve_global_variable();	/* BPTR */
	EXAWORD	resolve_local_variable();	/* BPTR */
	VOID	trap_all_procedures();	/* EXAWORD,EXAWORD */
	VOID	trap_all_segments();	/* EXAWORD,EXAWORD */
	EXAWORD	wildcomp();	/*  BPTR, BPTR  */
	VOID	force_debug_context();	/* DEBUGPTR */
	VOID	symbolic_detachment();	/* DEBUGPTR */
/*------------*/
/* EXDBTRAC.C */
/*------------*/
	VOID	add_trace_region();	/* EXAWORD,EXAWORD,EXAWORD,EXAWORD */
	VOID	flush_trace_list();	/* EXAWORD */
	VOID	initialise_trace_control();	/* VOID */
	VOID	liberate_trace_control();	/* VOID */
	VOID	trace_control();	/* BPTR */
	EXAWORD	trace_is_active();	/* VOID */
	VOID	traced_regions_list();	/* VOID */
/*------------*/
/* EXDBATTA.C */
/*------------*/
	VOID	attachment_manager();	/* BPTR */
/*------------*/
/*  EXDBUI.C  */
/*------------*/
	VOID	centered_string();	/* EXAWORD,EXAWORD,EXAWORD,BPTR */
	EXAWORD	current_mouse_click();	/* VOID */
#ifdef ABAL21
	VOID	display_hexint();	/* EXAWORD */
	VOID	display_hexbyte();	/* EXAWORD */	
	EXAWORD	display_integer();	/* EXAWORD */
#endif
	EXAWORD	display_variable_declaration();	/* BPTR,EXAWORD */
	VOID	execute_debug_script();	/* BPTR,EXAWORD */
	VOID	initialise_mouse_manager();	/* VOID */
	EXAWORD	mouse_or_keyboard();	/* VOID */
	VOID	mouse_title_box();	/* EXAWORD,EXAWORD,EXAWORD,EXAWORD,BPTR */
	EXAWORD	offer_list_menu();	/* EXAWORD */
	VOID	pop_mouse();	/* VOID */
	EXAWORD	specify_filename();	/* BPTR,EXAWORD */
	VOID	standard_message();	/* BPTR */
	VOID	standard_error();	/* BPTR */
	VOID	standard_errors();	/* EXAWORD */
	EXAWORD	standard_validation();	/* BPTR */
	EXAWORD	standard_exit_check();	/* VOID */
	EXAWORD	standard_command_input();	/* EXAWORD,EXAWORD */
	EXAWORD	standard_integer_ask();	/* BPTR */
	EXAWORD	standard_ask();	/* BPTR,EXAWORD,BPTR,EXAWORD */
	VOID	symbolic_atribut();	/* EXAWORD */
	VOID	symbols_browser();	/* VOID */
	EXAWORD	tcode_correspondance();	/* EXAWORD,EXAWORD,EXAWORD,EXAWORD */
	VOID	trace_all_symbols();	/* EXAWORD */
	VOID	draw_empty_box();
/*------------*/
/*  EXDBSTD.C */
/*------------*/
	BPTR	exadb_strcpy();	/* BPTR,BPTR */
	BPTR	exadb_strcat();	/* BPTR,BPTR */
	EXAWORD	exadb_strlen();	/* BPTR */
/*------------*/
/* EXDBSTRE.C */
/*------------*/
	VOID	flush_search_path();	/* EXAWORD */
	VOID	initialise_streams();	/* VOID */
	VOID	set_debug_search_path();	/* BPTR */
	VOID	terminate_streams();	/* VOID */
/*------------*/
/* EXDBWTCH.C */
/*------------*/
	VOID	flush_watch_events();	/* EXAWORD */
/*------------*/
/* EXDBFKEY.C */
/*------------*/
	VOID	init_fkey_storage();	/* VOID */
	VOID	liber_fkey_storage();	/* VOID */
	VOID	restore_function_keys();	/* VOID */
	VOID	store_function_keys();	/* VOID */
/*------------*/
/* EXDBHIST.C */
/*------------*/
	VOID	initialise_history();	/* VOID */
	VOID	liberate_history();	/* VOID */
/*------------*/
/*  EXDBCMD.C */
/*------------*/
	VOID newlyne();	/* VOID */
	VOID set_tabulation_size();	/* BPTR */
	VOID showptr();	/* BPTR */
	VOID x_intvisi();	/* EXAWORD */
/*------------*/
/* EXDBSTAK.C */
/*------------*/
	VOID	stack_trace();	/* VOID */

#endif	/* UNIX */
	/* ---- */

#endif  /* _EXPROTO1_H */
	/*-------------*/
