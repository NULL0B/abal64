/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRITER.H				*/
/*		Version :	2.1d					*/
/*		Date	:	08/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRITER_H
#define	_TRITER_H

#define	_ITERATION_IF		1
#define	_ITERATION_SELECT	2
#define	_ITERATION_DO		3
#define	_ITERATION_WHILE	4
#define	_ITERATION_REPEAT	5
#define	_ITERATION_FOR		6
#define	_ITERATION_EVENT	7
#define	_ITERATION_TRY   	8
#define	_ITERATION_ELSE  	9
#define	_ITERATION_EACH		10

#define	ITERPTR	struct otr_iteration XPTR

struct	otr_iteration	{
	WORD		nature;
	WORD		repeat;
	WORD		abandon;
	WORD		operate;
	WORD		status;
	WORD		variable;
	RESULTPTR	operand[16];
	VPTR		context;
	WORD		usage;
	ITERPTR		next;
	};

#ifdef	_TRITER_C
	ITERPTR	IterationHeap;
	ITERPTR	IterationList;
	WORD	LabelCounter;
#endif

#ifndef	UNIX
ITERPTR	allocate_for_iteration( VOID );
VOID	release_iteration( VOID );
RESULTPTR	iteration_operand( VOID );
RESULTPTR	IterationOperand( WORD );
WORD	check_iteration_variable( TCVARPTR );
WORD	select_operand( RESULTPTR );
WORD	try_operand( RESULTPTR );
WORD	SelectOperand( RESULTPTR, WORD );
WORD	iteration_usage( VOID );
VOID	adjust_iteration_usage( VOID );
WORD	iteration_else( VOID );
WORD	get_iteration_labels( WORD * labeltrue, WORD * labelfail );
VPTR	get_iteration_context( VOID );
WORD	set_iteration_context( VPTR );
WORD	get_iteration_label(BPTR ilabel);
WORD	dcl_iteration_label( VOID );
WORD	enter_event_do( VOID );
WORD	enter_event_then( VOID );
WORD	awaiting_event_do( VOID );
WORD	dcl_operate_label( VOID );
WORD	dcl_abandon_label( VOID );
WORD	new_implicite_label( VOID );
WORD	new_operate_label( VOID );
WORD	new_abandon_label( VOID );
WORD	new_iterate_label( VOID );
WORD	enter_iteration( WORD,TCVARPTR );
#ifdef	_DEBUG_ITER_ERROR
VOID	debug_iteration_type( VOID );
#endif
WORD	use_implicite_label( WORD, WORD );
WORD	use_iteration_label( WORD );
WORD	use_operate_label( WORD );
WORD	use_abandon_label( WORD );
WORD	break_prior_to_case( VOID );
WORD	goto_operation_label( VOID );
WORD	use_break_label( WORD );
WORD	break_from_iteration( VOID );
WORD	iteration_type( VOID );
WORD	implicite_goto( WORD );
WORD	implicite_gosub( WORD );
WORD	dcl_implicite_label( WORD );
WORD	leave_iteration( VOID );
VOID	iteration_error( VOID );
VOID	terminate_iterations( VOID );
VOID	initialise_iterations( VOID );
VOID	liberate_iterations( VOID );
#else
WORD		iteration_type();
WORD		enter_iteration();
WORD		leave_iteration();
VOID		initialise_iterations();
VOID		terminate_iterations();
VOID		liberate_iterations();
RESULTPTR	iteration_operand();
RESULTPTR	IterationOperand();
VPTR		get_iteration_context();
WORD		set_iteration_context();
WORD		check_iteration_variable();
#endif

#endif	/* _TRITER_H */
	/* ----------- */
