/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXCORE.H  				*/
/*		Version :	1.4a / 2.1a				*/
/*		Date 	:	04/08/1992				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EX_CORE_H
#define _EX_CORE_H

extern	EXAWORD	procid;		/* Current procedure identifier	*/
extern	EXAWORD	cur_seg;	/* Current segment identifier	*/
extern	BPTR	LocalDataTable;	/* Current local variable base	*/
extern	BPTR	LocalDataSegment; /* Current local data table	*/
extern	BPTR	GlobalDataSegment;/* Global variables image	*/
extern	EXAWORD	StackHold;	/* Current stack protection val	*/
extern	EXAWORD	len_glob;	/* Length of global data image	*/
extern	EXAWORD	LDS_dex;	/* current heap usage value	*/

extern	struct segmform PTR TcodeSegmentTable;

#endif	/* _EX_CORE_H */
	/* ---------- */

