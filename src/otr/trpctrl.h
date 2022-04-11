/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRPCTRL.H				*/
/*		Version :	2.1c					*/
/*		Date	:	14/02/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRPCTRL_H
#define	_TRPCTRL_H

#define	PCTRLPTR	struct	cobol_pctrl XPTR
#define	UCTRLPTR	struct	cobol_uctrl XPTR

struct	cobol_uctrl	{
	WORD		label;
	WORD		nombre;
	UCTRLPTR	next;
	};

struct	cobol_pctrl	{
	BPTR		name;
	WORD		intro;
	WORD		callback;
	WORD		users;
	TCVARPTR	control;
	UCTRLPTR	usage;
	PCTRLPTR	next;
	};

#ifndef	UNIX
PCTRLPTR	allocate_for_pctrl( BPTR );
UCTRLPTR	allocate_for_uctrl( VOID );
#else
PCTRLPTR	allocate_for_pctrl();
UCTRLPTR	allocate_for_uctrl();
#endif

#endif	/* _TRPCTRL_H */
	/* ---------- */

