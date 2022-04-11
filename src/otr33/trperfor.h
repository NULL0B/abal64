/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRPERFORM.H				*/
/*		Version :	2.1c					*/
/*		Date	:	14/02/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRPERFORM_H
#define	_TRPERFORM_H

#define	PCTRLPTR	struct	cobol_pctrl XPTR
#define	UCTRLPTR	struct	cobol_uctrl XPTR

struct	cobol_uctrl	{
	WORD		label;
	UCTRLPTR	next;
	};

struct	cobol_pctrl	{
	BPTR		name;
	WORD		intro;
	WORD		users;
	UCTRLPTR	usage;
	PCTRLPTR	next;
	};

#endif	/* _TRPERFORM_H */
	/* ------------ */

