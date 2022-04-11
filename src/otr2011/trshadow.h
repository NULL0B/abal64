/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRSHADOW.H				*/
/*		Version :	2.1d					*/
/*		Date	:	08/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRSHADOW_H
#define	_TRSHADOW_H

#define	MAX_REGISTERS	64

#define	_REGISTER_INT	0
#define	_REGISTER_CONST	1
#define	_REGISTER_VARB	2
#define	_REGISTER_EXPR	3
#define	_REGISTER_ALIAS	4

#define	_REGISTER_DEAD  0
#define	_REGISTER_LIVE  1
#define	_REGISTER_PUSH  2

#define	_SHADOW_MASK	0xFF00
#define	_SHADOW_TEXT	0x8000
#define	_SHADOW_CONV	0x4000
#define	_SHADOW_RESULT	0x2000
#define	_SHADOW_INC	0x0100
#define	_SHADOW_DEC	0x0200
#define	_SHADOW_NEG	0x0300

#define	_SHADOW_CONVS8	(_SHADOW_CONV | _TYPE_INT8)
#define	_SHADOW_CONVS16	(_SHADOW_CONV | _TYPE_INT16)
#define	_SHADOW_CONVSL	(_SHADOW_CONV | _TYPE_NUMERIC)
#define	_SHADOW_CONVSS	(_SHADOW_CONV | _TYPE_STRING)
#define	_SHADOW_CONVR8	(_SHADOW_CONV | _SHADOW_RESULT | _TYPE_INT8)
#define	_SHADOW_CONVR16	(_SHADOW_CONV | _SHADOW_RESULT | _TYPE_INT16)
#define	_SHADOW_CONVRL	(_SHADOW_CONV | _SHADOW_RESULT | _TYPE_NUMERIC)
#define	_SHADOW_CONVRS	(_SHADOW_CONV | _SHADOW_RESULT | _TYPE_STRING)
#define	_SHADOW_INCS	(_SHADOW_INC)
#define	_SHADOW_INCR	(_SHADOW_INC | _SHADOW_RESULT)
#define	_SHADOW_DECS	(_SHADOW_DEC)
#define	_SHADOW_DECR	(_SHADOW_DEC | _SHADOW_RESULT)
#define	_SHADOW_NEGS	(_SHADOW_NEG)
#define	_SHADOW_NEGR	(_SHADOW_NEG | _SHADOW_RESULT)

#define	SHADOWPTR	struct otr_register XPTR
#define	SHADOWNODE	struct otr_shadow_node XPTR

struct	otr_shadow_node {
	WORD		nature;
	VPTR		lptr;
	VPTR		rptr;
	};

struct	otr_register	{
	WORD		number;
	WORD		nature;
	WORD		status;
	TCTYPPTR	type;
	WORD		value;
	VPTR		contents;
	SHADOWNODE	operand;
	SHADOWPTR	next;
	SHADOWPTR	prev;
	};

#ifdef	_TRSHADOW_C
	SHADOWNODE	ShadowUsed=(SHADOWNODE) 0;
	SHADOWNODE	ShadowFree=(SHADOWNODE) 0;
	SHADOWPTR	RegisterHeap;
	SHADOWPTR	RegisterUsed;
	SHADOWPTR	Registers[MAX_REGISTERS];
static	WORD		RegisterLock[MAX_REGISTERS];
	WORD		Register;
	WORD		BaseRegister;
#else
EXTERN	WORD		Register;
EXTERN	WORD		BaseRegister;
#endif

/*	Function Prototypes 	*/
/*	-------------------	*/

#ifndef	UNIX
SHADOWPTR	allocate_for_register( VOID );
SHADOWPTR	lock_register( SHADOWPTR );
VOID	unlock_register( SHADOWPTR );
VOID	initialise_shadower( VOID );
SHADOWNODE	release_shadow_list( SHADOWNODE );
VOID	reset_shadower( VOID );
VOID	terminate_shadower( VOID );
SHADOWPTR	allocate_new_register( VOID );
VOID	release_base_register( SHADOWPTR );
SHADOWPTR protect_base_register( SHADOWPTR );
SHADOWPTR	shadow_integer_register( SHADOWPTR, WORD );
SHADOWPTR	shadow_constant_register( SHADOWPTR, TCCONPTR );
TCVARPTR	register_variable( SHADOWPTR );
TCTYPPTR	register_alias( SHADOWPTR );
SHADOWPTR	shadow_alias_register( SHADOWPTR, TCTYPPTR );
SHADOWPTR	shadow_variable_register( SHADOWPTR, TCVARPTR );
WORD	is_shadow_integer( SHADOWPTR );
WORD	is_shadow_string( SHADOWPTR );
WORD	is_shadow_numeric( SHADOWPTR );
WORD	register_type( SHADOWPTR );
WORD	verify_register_type( SHADOWPTR, TCTYPPTR );
SHADOWNODE	allocate_shadow_node( VOID );
VOID	set_shadow_operands( SHADOWPTR, WORD, VPTR, VPTR );
VOID	set_shadow_operand( SHADOWPTR, WORD, VPTR );
VOID	set_shadow_variable( SHADOWPTR, VPTR );
VOID	set_shadow_register( SHADOWPTR, SHADOWPTR );
VOID	set_shadow_constant( SHADOWPTR, VPTR );
VOID	set_shadow_text( SHADOWPTR );
VOID	set_shadow_result(SHADOWPTR, VPTR );
VOID	set_shadow_increment( SHADOWPTR );
VOID	set_shadow_decrement( SHADOWPTR );
VOID	set_shadow_negation( SHADOWPTR );
VOID	set_shadow_conv( SHADOWPTR, WORD );
SHADOWPTR	set_shadow_type( SHADOWPTR, WORD );
WORD	push_live_registers( VOID );
WORD	pop_live_registers( VOID );
WORD	pop_live_register( SHADOWPTR );
WORD	mark_live_register( SHADOWPTR );
WORD	mark_dead_register( SHADOWPTR );
WORD	mark_live_noregister( WORD );
WORD	mark_dead_noregister( WORD );
WORD	lock_used_registers( VOID );
VOID   unlock_used_registers( WORD );
#else
VOID		terminate_shadower();
VOID		reset_shadower();
VOID		initialise_shadower();
SHADOWPTR	lock_register();
VOID		unlock_register();
SHADOWPTR	allocate_new_register();
SHADOWPTR	shadow_variable_register();
SHADOWPTR	shadow_constant_register();
SHADOWPTR	shadow_integer_register();
SHADOWPTR	set_shadow_type();
SHADOWPTR	protect_base_register();
VOID		release_base_register();
WORD		lock_used_registers();
VOID     	unlock_used_registers();
#endif

#endif	/* _TRSHADOW_H */
	/* ----------- */
