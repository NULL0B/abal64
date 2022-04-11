#ifndef	_EXHANDLE_H
#define	_EXHANDLE_H

#ifdef	ABAL_CRITERIA
#define	EX_FILE_HANDLE EXALONG
#define EX_UNUSED_HANDLE -1L
#else
#define	EX_FILE_HANDLE EXAWORD
#define EX_UNUSED_HANDLE MOINS_UN
#endif

#define	EX_PRINTER_HANDLE	EXAWORD	/* CICO Uses Short File Handles	*/
#define EX_UNUSED_PRINTER 	0xFFFF

#endif	/* _EXHANDLE_H */
	/* ----------- */

