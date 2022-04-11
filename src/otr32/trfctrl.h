/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRFCTRL.H				*/
/*		Version :	2.1d					*/
/*		Date	:	26/01/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRFCTRL_H
#define	_TRFCTRL_H

#define	FCTRLPTR	struct	cobol_fctrl XPTR
#define RCTRLPTR	struct  cobol_rctrl XPTR
#define	OPERNODE	struct  operand_node XPTR

#define	_CAN_READ	0x0001
#define	_CAN_WRITE	0x0002
#define	_CAN_OPEN  	0x0004
#define	_CAN_CREATE	0x0008

#define	_FCTRL_NATURE_CI  	_CAN_READ
#define	_FCTRL_NATURE_CO  	_CAN_WRITE
#define	_FCTRL_NATURE_PRINTER	(_CAN_WRITE | _CAN_OPEN)
#define	_FCTRL_NATURE_DISK   	(_CAN_WRITE | _CAN_OPEN | _CAN_READ)
#define	_FCTRL_NATURE_FILE   	(_CAN_WRITE | _CAN_OPEN | _CAN_READ | _CAN_CREATE)

#define	_ITERATION_READ		_ITERATION_EVENT+50
#define	_ITERATION_WRITE	_ITERATION_EVENT+51
#define	_ITERATION_REWRITE	_ITERATION_EVENT+52
#define	_ITERATION_START	_ITERATION_EVENT+53
#define	_ITERATION_DELETE	_ITERATION_EVENT+54

struct	cobol_rctrl	{
	BPTR		name;
	RCTRLPTR	next;
	};

struct	operand_node	{
	RESULTPTR	operand;
	OPERNODE	next;
	};

struct	cobol_fctrl	{
	BPTR		select;
	BPTR		assign;
	BPTR		status;
	BPTR		recordkey;
	BPTR		recordbuf;
	WORD		recordsize;
	WORD		organisation;
	WORD		nature;
	WORD		access;
	WORD		handle;
	RCTRLPTR	records;
	FCTRLPTR	next;
	};

#ifdef	_TRFCTRL_C
	WORD		SelectHandle=3;
	BYTE		CobolToAbal[320];
#else
EXTERN	WORD		SelectHandle;
EXTERN	BYTE		CobolToAbal[320];
#endif

/*	FCTRL Function Prototypes	*/
/*	-------------------------	*/
#ifndef	UNIX
FCTRLPTR	allocate_for_fctrl( BPTR );
FCTRLPTR	locate_fctrl( BPTR );
WORD		assign_fctrl( FCTRLPTR );
WORD		open_fctrl( FCTRLPTR );
WORD		close_fctrl( FCTRLPTR );
WORD		dfile_fctrl( FCTRLPTR );
WORD		cfile_fctrl( FCTRLPTR );
WORD		translate_file_select( VOID );
WORD		translate_file_control( VOID );
OPERNODE	allocate_operand_node( RESULTPTR );
RCTRLPTR	allocate_for_rctrl( BPTR );
#else
FCTRLPTR	allocate_for_fctrl( );
FCTRLPTR	locate_fctrl();
WORD		assign_fctrl();
WORD		open_fctrl();
WORD		close_fctrl();
WORD		dfile_fctrl();
WORD		cfile_fctrl();
WORD		translate_file_select();
WORD		translate_file_control();
OPERNODE	allocate_operand_node();
RCTRLPTR	allocate_for_rctrl();
#endif

#endif 	/* _TRFCTRL_H */
	/* ---------- */

