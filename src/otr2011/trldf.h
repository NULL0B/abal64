/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Object pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRLDF.H    				*/
/*		Version :	2.1d					*/
/*		Date	:	10/01/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/

#ifndef	_TRLDF_H
#define	_TRLDF_H

#include "trarg.h"

#define	LDFPTR	struct otr_dlf XPTR

struct	otr_dlf	{
	ARGPTR		root;
	ARGPTR		last;
	TCDLFPTR	func;
	BYTE		descriptor[1024];
	};


#ifndef	UNIX
TCDLBPTR	allocate_for_dll( VOID );
TCDLFPTR	allocate_for_dlf( VOID );
WORD	get_dll_type( VOID );
WORD	add_dll_function( TCDLBPTR, TCDLFPTR );
VOID	add_dynamic_library( TCDLBPTR );
VOID	liberate_dynamic_function( TCDLFPTR, WORD );
VOID	liberate_dynamic_library(TCDLBPTR);
TCDLFPTR	locate_dynamic_function( TCDLBPTR, WORD );
TCDLBPTR	locate_dynamic_library( BPTR );
WORD	translate_dll_description( BPTR );
VOID	liberate_dynamic_libraries( VOID );
LDFPTR	allocate_for_ldf( VOID );
LDFPTR	start_ldf( TCDLFPTR );
RESULTPTR	ldf_return_value( WORD );
RESULTPTR	ldf_target( LDFPTR );
RESULTPTR	flush_ldf( LDFPTR, RESULTPTR );
RESULTPTR	flush_indirect_ldf( LDFPTR, RESULTPTR, TCTYPPTR );
WORD		flush_void_ldf( LDFPTR, RESULTPTR );
WORD		store_ldf(LDFPTR, RESULTPTR, WORD );
#ifndef	_GEN_C_RTL
RESULTPTR	evaluate_dll_function( TCDLFPTR );
#else
BPTR     	evaluate_dll_function( TCDLFPTR );
#endif
WORD		activate_dll_function( TCDLFPTR );
#else
#ifndef	_GEN_C_RTL
RESULTPTR	evaluate_dll_function();
#else
BPTR      	evaluate_dll_function();
#endif
WORD		activate_dll_function();
#endif 

#endif	/* _TRLDF_H */
	/* -------- */

