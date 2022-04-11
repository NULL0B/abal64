/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRSYMBOL.H				*/
/*		Version :	2.1d					*/
/*		Date	:	08/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRSYMBOL_H
#define	_TRSYMBOL_H


#define	SYMBOLPTR	struct otr_symbol XPTR
#define	SYMBHASH1	0xFFFF

#define	SYMBOL_CONST	0x0001
#define	SYMBOL_VARB    	0x0002
#define	SYMBOL_PROC	0x0003
#define	SYMBOL_SEGM	0x0004
#define	SYMBOL_USER	0x0005
#define	SYMBOL_MODULE	0x0006
#define	SYMBOL_OBJECT	0x0100
#define	OBJECT_VARB	(SYMBOL_OBJECT | SYMBOL_VARB)
#define	SYMBOL_LOCAL	0x8000
#define	SYMBOL_TYPE	0x01FF


struct	otr_symbol	{
	WORD		hash;
	BPTR		name;
	WORD		type;
	WORD		owner;
	WORD		module;
	VPTR		contents;
	SYMBOLPTR	next;
	};

#ifdef	_TRSYMBOL_C
#ifdef	UNIX
#define	SYMBHASH2	157
#else
#define	SYMBHASH2	57
#endif
SYMBOLPTR		SymbolHash[SYMBHASH2];
WORD			SymbolOwner=0;
#endif

/* 	Public	Function Prototypes	*/
/*	---------------------------	*/
#ifndef	UNIX

WORD	symbol_compare( BPTR, BPTR );
BPTR	allocate_for_string( BPTR );
BPTR	allocate_for_token( BPTR );
VOID	release_symbol( SYMBOLPTR );
WORD	calculate_symbol_hash( BPTR , WORD );
SYMBOLPTR	allocate_for_symbol( VOID );
VOID	initialise_symbols( VOID );
VOID	liberate_symbols( VOID );
VOID	liberate_local_symbols( VOID );
VOID	new_symbol_owner( VOID );
WORD	verify_symbol_owner( SYMBOLPTR );
VOID	drop_local_symbols( VOID );
VOID	symbol_statistics( VOID );
SYMBOLPTR	is_symbol( BPTR );
SYMBOLPTR	get_alternative_symbol( SYMBOLPTR );
SYMBOLPTR	add_symbol( BPTR, WORD );
VOID consume_terminal_symbol( VOID);
VOID	reset_symbol_module();
SYMBOLPTR	get_terminal_symbol( VOID );
WORD	trace_variable( SYMBOLPTR );
TCVARPTR	get_variable( WORD );
WORD	echo_symbol( SYMBOLPTR );
TCVARPTR	get_local_variable( VOID );
TCVARPTR is_object( VOID );
TCVARPTR	is_variable( WORD );
TCVARPTR	is_local_variable( VOID );
TCPRCPTR	is_procedure( VOID );
TCCONPTR	is_constant( VOID );
TCDLFPTR	is_dll_function( VOID );
WORD	resolve_symbolic_integer( BPTR );
#else
VOID		initialise_symbols();
VOID		liberate_symbols();
VOID		reset_symbol_module();
SYMBOLPTR	get_terminal_symbol();
SYMBOLPTR	get_alternative_symbol();
SYMBOLPTR	is_symbol();
SYMBOLPTR	add_symbol();
TCVARPTR	is_object();
TCVARPTR	is_variable();
TCCONPTR	is_constant();
TCPRCPTR	is_procedure();
TCDLFPTR	is_dll_function();
BPTR		allocate_for_string();
BPTR		allocate_for_token();
#endif

#endif	/* _TRSYMBOL_H */
	/* ----------- */


