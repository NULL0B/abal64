/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBMIMO.H  				*/
/*		Date 	:	09/08/1993				*/
/*		Version :	2.1a					*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBMIMO_H
#define	_EXDBMIMO_H

#include "exmimo.h"

struct	debug_mouse	{
	EXAWORD	mode;
	EXAWORD	top_column;
	EXAWORD	top_line;
	EXAWORD	columns;
	EXAWORD	lines;
	EXAWORD	position;
	EXAWORD	button;
	EXAWORD	clicktype;
	};

#define	MICE 16

#define	DbMouse DebugMouse[mouse_index]

#ifdef	_EXDBUI_C
	struct	debug_mouse	DebugMouse[MICE];
	EXAWORD	mouse_index;
#else
EXTERN	struct	debug_mouse	DebugMouse[MICE];
EXTERN	EXAWORD	mouse_index;
#endif

#ifdef CHECK_PROTO_ARGS
VOID	set_mouse_control( EXAWORD, EXAWORD, EXAWORD, EXAWORD );
VOID	set_mouse_level( EXAWORD );	
#else
VOID	set_mouse_control();
VOID	set_mouse_level();	
#endif

#endif 	/* _EXDBMIMO_H */
	/* ----------- */

