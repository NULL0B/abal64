#ifndef _missing_h
#define _missing_h

#ifndef public
#define public
#endif

#ifndef WORD
#define WORD unsigned int
#endif

#ifndef BPTR
#define BPTR unsigned char *
#endif

/* CICO and MIMO stuff */

#include "exmimoproto.h"
#include "excicoproto.h"

public void     lsyskey();
public EXAWORD 	opb();
public void	set_allow_close_zero(EXAWORD);
public void	set_allocate_padding(EXAWORD);
public void	set_time_factor(EXAWORD);
public void	set_wait_factor(EXAWORD);
public void 	initialise_loadgo();
public void     start_allocation_trace();
public void     initialise_mallocate();
public void     reset_trace_control();
public void     reset_mima_lang(); 
public void     reset_task_manager();
public void 	SetCicoContext(BPTR);
public void	inhibit_console_purge();
public EXAWORD	open_console();
public EXAWORD	close_console();
public void	iof_initialisation();
public void	iof_liberation();
public void    	iof_reset();

/* Attachment stuff */

public void 	initialise_dynamic_allocation();
public void 	liberate_dynamic_allocation();
public void 	initialise_attachments();
public void 	liberate_attachments();
public void 	initialise_indirection_control();
public void 	liberate_indirection_control();
public void	reset_indirection_control();
public void 	initialise_task_control();
public void	liberate_task_control(EXAWORD);
public void 	liberate_thread_manager();
public void	reset_thread_manager();
public void	close_allocation_trace();
public void 	check_extern_event();
public EXAWORD	would_autopush();

/* segment management */

public EXAWORD 	LoadSegmentTable(EXAWORD,EXAWORD);
public EXAWORD 	ldgo_seg(EXAWORD,EXAWORD);
public void	rest_segm();
public void 	LiberateSegmentContext();
public void 	LiberateSegmentTable();
public void 	release_error_traps();

/* procedure management */

public EXAWORD 	procedure_exit(EXAWORD);
public BPTR	procedure_data_table(EXAWORD);
public EXAWORD 	load_procedure_table();
public void 	LiberateProcedureTable(EXAWORD);
public EXAWORD	execute_pseudo_code(BPTR);
public EXAWORD  procedure_loaded(EXAWORD);
public EXAWORD  procedure_callers(EXAWORD);

/* file management */

public 	EXAWORD initialise_assign_allocation(EXAWORD,EXAWORD);
public	void 	liberate_assign_allocation();
public 	void 	liberlox( char * );
public	void	PurgeLox();
public 	void 	freefich();
public 	EXAWORD SectRead(EX_FILE_HANDLE,BPTR,EXAWORD blen,ULONG);
public	void	sf_init();
public	EXAWORD	si_init();
public	void	si_fin();
public	EXAWORD	AutoMate();
public	EXAWORD	implicite_convert_mnemonics(EXAWORD);
public	void	initialise_access_controller();
public	void	default_access_controller();
public	EXAWORD	fn_parser(BPTR,BPTR,EXAWORD);
public	EXAWORD	si_conversion();
public 	EXALONG mc_key(EX_FILE_HANDLE,EXAWORD,BPTR,EXAWORD,EXAWORD,EXAWORD);
public	EXAWORD	killjoin(BPTR);
public	EXAWORD	questprep(EXAWORD);
public  EXAWORD dcljoin();
public  EXAWORD makejoin();
public  EXAWORD suprjoin();
public  EXAWORD namejoin();
public  EXAWORD rubrlst(EXAWORD,EXAWORD);
public  EXAWORD rubrdcl();
public  EXAWORD rubrdef();
public  EXAWORD rubrnom();
public  EXAWORD rubrfld();
public  EXAWORD rubrraz();
public	EXAWORD	prepare_jointure(BPTR,EXAWORD,EXAWORD,BPTR);

public	void	traitfilerror(EXAWORD,int);
public	EXAWORD	Access(BPTR,EXAWORD,EXAWORD);
public	void	im_close(EXAWORD);
public	EXAWORD	remove_bd_record(EXAWORD,EXAWORD);
public	void	close_base_files(EXAWORD);
public	EXAWORD	dir_seek(BPTR,EXAWORD,BPTR,EXAWORD,EXAWORD);
public 	EXAWORD	bdrecord();
public	EXAWORD	linkwork(EXAWORD,EXAWORD);
public	EXAWORD	intero(EXAWORD,EXAWORD);
public	EXAWORD	check_implicite_join_file(BPTR);
public	EXAWORD anajoin(BPTR,BPTR,EXAWORD);
public  void 	check_debug_assign(int);
public  void	basefile(EXAWORD);
public  EXAWORD makebase();
public 	BPTR    kode_lode( EXAWORD secteur, EXAWORD     longeur );

/* maths and conversion */
public	EXAWORD atobcd(BPTR,BPTR,EXAWORD,EXAWORD);
public	EXAWORD bcdfix(BPTR,BPTR,EXAWORD,EXAWORD,EXAWORD,EXAWORD);
public	EXAWORD	ltobcd(EXALONG,BPTR,EXAWORD);
public	EXAWORD	htobcd(EXAWORD,BPTR,EXAWORD);
public	EXAWORD	itoa(EXAWORD,BPTR,EXAWORD);

/* initialisation etc */

public 	EXAWORD Semaphoff(EXAWORD);
public 	int     VerifTcode();
public 	VOID    ensure_parent();
public 	EXAWORD tkodgetw32();
public 	EXAWORD tkodgetw16();
public	void   	set_chain_trace();
public	EXAWORD	argsetw(EXAWORD,EXAWORD);
public	EXAWORD	argset(EXAWORD,EXAWORD,EXAWORD);
public	void	liberate_for_on_error();
public	EXAWORD	is_on_extern_event();
public	void	std_signal_event(int);
public	EXAWORD	lenuse(BPTR,EXAWORD);
public	void	vputs(EXAWORD,EXAWORD);

/* dynamic libraries */

public EXAWORD 	InitFuse();
public EXAWORD 	MergeFuse();
public void 	TalkWork();
public void	liberate_dynamic_libraries();
public void 	exa_application_error(WORD);

	/* ---------- */
#endif	/* _missing_h */
	/* ---------- */
