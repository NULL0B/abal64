#ifndef	_EXHANDLE_H
#define	_EXHANDLE_H

#ifdef	ABAL_CRITERIA
#define	EX_FILE_HANDLE LONG
#define EX_UNUSED_HANDLE -1L
#else
#define	EX_FILE_HANDLE EXAWORD
#define EX_UNUSED_HANDLE MOINS_UN
#endif

#define	EX_PRINTER_HANDLE	EXAWORD	/* CICO Uses Short File Handles	*/

#endif	/* _EXHANDLE_H */
	/* ----------- */

