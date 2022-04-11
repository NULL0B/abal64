/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Object pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRIOF.H    				*/
/*		Version :	2.1d					*/
/*		Date	:	20/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/

#ifndef	_TRIOF_H
#define	_TRIOF_H

#define	_iof_FIO 	0x0000
#define	_iof_HOT 	0x0001
#define	_iof_TABC	0x0002
#define	_iof_ATB	0x0003
#define	_iof_PRN	0x0004
#define	_iof_TABV	0x0005
#define	_iof_FMT	0x0006
#define	_iof_DEV	0x0007
#define	_iof_BACK	0x0008
#define	_iof_CLEAR	0x0009
#define	_iof_HOME 	0x0029
#define	_iof_BELL 	0x0049
#define	_iof_FORE	0x000A
#define	_iof_TABL	0x000B
#define	_iof_ASK	0x000C
#define	_iof_GSBX	0x000D
#define	_iof_HOTX	0x000E
#define	_iof_GSBH	0x000F

#define	_hot_I		0x0000
#define	_hot_L		0x0010
#define	_hot_U		0x0020
#define	_hot_D		0x0030
#define	_hot_E		0x0040
#define	_hot_T		0x0050
#define	_hot_X		0x0060

#define	_PRINT_KEYWORD_MAX	8

#define	IOFPTR	struct iof_control XPTR
#define	HOTPTR	struct hot_control XPTR

struct	iof_control	{
	WORD		operation;
#ifndef	_GEN_C_RTL
	RESULTPTR	operand;
#else
	BPTR		operand;
#endif
	BPTR		buffer;
	IOFPTR		next;
	IOFPTR		prev;
	};

struct	hot_control	{
	WORD		nature;
#ifndef	_GEN_C_RTL
	RESULTPTR	operand;
#else
	BPTR		operand;
#endif
	BPTR		label;
	WORD		gosub;
	HOTPTR		next;
	HOTPTR		prev;
	};

#ifdef	_TRIOF_C

IOFPTR	IofHead;
IOFPTR	IofFoot;
IOFPTR	IofFree;
	
HOTPTR	HotHead;
HOTPTR	HotFoot;
HOTPTR	HotFree;

WORD	AskEndLabel=MOINS_UN;
WORD	AskStartLabel=MOINS_UN;
BPTR	PrintFormatLabel=(BPTR) 0;
	
static BPTR print_keywords [_PRINT_KEYWORD_MAX] = {
	(BPTR) "TAB",
	(BPTR) "TABV",
	(BPTR) "PAINT",
	(BPTR) "ATB",
	(BPTR) "CLEAR",
	(BPTR) "BELL",
	(BPTR) "HOME",
	(BPTR) "PAGE"
	};
#endif	

#ifndef	UNIX
WORD	initialise_iof( VOID );
IOFPTR	allocate_for_iof( VOID );
HOTPTR	allocate_for_hotkey( VOID );
HOTPTR	copy_hotkey( HOTPTR );
VOID	release_iof( IOFPTR );
VOID	release_hotkey( HOTPTR );
VOID	liberate_iof( VOID );
VOID	liberate_hot( VOID );
WORD	get_ask_start_label( VOID );
WORD	ask_start_label( VOID );
WORD	start_iof( VOID );
VOID	terminate_iof( VOID );
WORD	translate_pause( VOID );
WORD	is_iof_instruction( VOID );
WORD	cancel_iof_instruction( VOID );
WORD	store_fmt( WORD, BPTR );
BPTR	allocate_for_format( VOID );
BPTR	convert_ascii_format( BPTR );
WORD	store_iof_fmt( BPTR );
WORD	store_iof( RESULTPTR, WORD );
WORD	store_iof_prn( RESULTPTR );
WORD	translate_prn( WORD );
WORD	store_iof_atb( RESULTPTR );
WORD	translate_atb( VOID );
WORD	store_iof_tabv( RESULTPTR );
WORD	translate_tabv( VOID );
WORD	store_iof_tabl( RESULTPTR );
WORD	store_iof_tabc( RESULTPTR );
WORD	translate_iof_tab( WORD );
WORD	translate_tab( VOID );
WORD	store_iof_foreground( RESULTPTR );
WORD	store_iof_background( RESULTPTR );
WORD	translate_paint( VOID );
WORD	flush_fmt( VOID );
WORD	ask_end_label( VOID );
WORD	dcl_ask_end_label( VOID );
WORD	flush_hotkey( HOTPTR );
WORD	flush_hotkeys( VOID );
WORD	message( BPTR );
BPTR	convert_explicite_format( VOID );
WORD	translate_fmt( VOID );
WORD	translate_format( VOID );
WORD	iof_special( WORD );
WORD	translate_iof_bell( VOID );
WORD	translate_iof_clear( VOID );
WORD	translate_iof_atom( VOID );
WORD	iof_instructions(WORD);
WORD	flush_iof( VOID );
WORD	flush_device( RESULTPTR );
WORD	check_print_operands( RESULTPTR, WORD );
WORD	check_hotkey_operands( VOID );
WORD	check_ask_operands( RESULTPTR );
WORD	check_ask_target( RESULTPTR );
VOID	echo_format( BPTR );
WORD	echo_print( RESULTPTR );
WORD	echo_ask( RESULTPTR, RESULTPTR );
WORD	flush_print( RESULTPTR, WORD );
WORD	flush_iof_ask( RESULTPTR, RESULTPTR );
WORD	flush_ask( RESULTPTR );
WORD	translate_format_labels( VOID );
WORD	translate_print( VOID );
#ifndef	_GEN_C_RTL
WORD	translate_clf_print( RESULTPTR );
#else
WORD	translate_clf_print( BPTR );
#endif
WORD	store_hotkey( HOTPTR );
WORD	translate_hotkey_adresse( HOTPTR );
WORD	translate_implicite_hotkey( WORD );
WORD	store_implicite_hotkeys( BPTR, BPTR );
WORD	translate_explicite_hotkey( VOID );
WORD	translate_primary_hotkey( VOID );
WORD	translate_hotkeys( VOID );
WORD	translate_ask( VOID );
WORD	translate_op( VOID );
WORD	translate_iof( VOID );
WORD	clf_print( RESULTPTR, BPTR, RESULTPTR );
HOTPTR	copy_hotkey( HOTPTR );

#else

WORD	translate_print();
WORD	translate_ask();
WORD	translate_pause();
WORD	translate_op();
WORD	translate_clf_print();
HOTPTR	copy_hotkey();
#endif

#endif	/* _TRIOF_H */
	/* -------- */

