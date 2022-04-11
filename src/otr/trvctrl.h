/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRVCTRL.H				*/
/*		Version :	2.1d					*/
/*		Date	:	26/01/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRVCTRL_H
#define	_TRVCTRL_H

#define	VCTRLPTR	struct	cobol_vctrl XPTR

#define	_LOCAL_SCOPE	1
#define	_GLOBAL_SCOPE	2
#define	_EXTERNAL_SCOPE	4

struct	cobol_vctrl	{
	BPTR		name;
	WORD		level;
	WORD		nature;
	WORD		scope;
	WORD		size;
	WORD		type;
	WORD		first;
	WORD		second;
	WORD		picsize;
	BPTR		picture;
	BPTR		value;
	VPTR		fichier;
	VPTR		record;
	TCVARPTR	contents;
	VCTRLPTR	redefines;
	VCTRLPTR	previous;
	VCTRLPTR	next;
	};

/*	VCTRL Function Prototypes	*/
/*	-------------------------	*/
#ifndef	UNIX
VCTRLPTR	allocate_for_vctrl( BPTR );
VCTRLPTR	locate_vctrl( BPTR );
RESULTPTR	resolve_vctrl( BPTR );
#else
VCTRLPTR	allocate_for_vctrl();
VCTRLPTR	locate_vctrl();
RESULTPTR	resolve_vctrl();
#endif

#endif 	/* _TRVCTRL_H */
	/* ---------- */
