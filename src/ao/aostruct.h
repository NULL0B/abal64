/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AOSTRUCT.H   				*/
/*		Version :	1.4a					*/
/*		Date	:	06/11/1991				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AOSTRUCT_H
#define	_AOSTRUCT_H

#define	ITEMPTR	struct program_structure XPTR
#define	CALLERPTR	struct caller_item XPTR
#define	VOIDPTR		void XPTR
#define	INLINEPTR	struct inline_control XPTR

#define	_STATUS_LOCK		0x0001
#define	_STATUS_UNLOCK		0xFFFE
#define	_STATUS_DONE		0x0002
#define	_STATUS_INLINE		0x0004
#define	_STATUS_CHECK   	0x0008
#define	_STATUS_NORMAL  	0xFFF7
#define	_STATUS_FIN_LISTE	0x8000

#define	_FLAG_DATA		1
#define	_FLAG_TIMER		2
#define	_FLAG_EVENT		4
#define	_FLAG_ERROR		8
#define	_FLAG_STATIC		16
#define	_FLAG_STATIC_DONE	32

#define	_SEGMENT_ENTRY		0
#define	_PROCEDURE_ENTRY	1
#define	_EXIT_ENTRY		4
#define	_FILE_ENTRY		8
#define _BASIC_TYPE		0x000F
#define	_SEGMENT_RESIDENT	0x0080
#define	_SEGMENT_STATIC  	0x0040

struct	program_structure	{
	ITEMPTR	next;		/* Next Entry for PROC/SEGM 	*/
	ITEMPTR	liste;		/* Liste of BLOCKS Called	*/
	struct	caller_item {
		ITEMPTR	usercall;
		ITEMPTR owner;
		CALLERPTR	next;
		EXAWORD		status;
		} XPTR callers;
	EXAWORD		type;		/* Type of entry PROC/SEGM	*/
	EXAWORD		identity;	/* Proc/Segm Identity of entry	*/
	EXAWORD		lock;		/* Number of entries in liste	*/
	EXAWORD		ligne;		/* Ligne Number of Detail	*/
	EXAWORD		adresse;	/* Original Patch adresse	*/
	EXAWORD		keep;		/* Indicates required in result */
	EXAWORD		flag;		/* Special Status Flags		*/
	EXAWORD		sm_adj;		/* Adjustment for Static reloc  */
	EXAWORD		sd_adj;		/* Adjustment for Static reloc  */
	};

struct	inline_control {
	BPTR	code_buffer;
	EXAWORD	code_sector;
	EXAWORD	code_length;
	BPTR	data_buffer;
	EXAWORD	data_sector;
	EXAWORD	data_length;
	EXAWORD	flags;
	EXAWORD	extra_length;
	BPTR	extra_buffer;
	EXAWORD	sm_adj;		/* Adjustment for Static reloc  */
	EXAWORD	sd_adj;		/* Adjustment for Static reloc  */
	};

#ifdef	_AOSTRUCT_C
ITEMPTR	Structure;		/* Base of Program Structures	*/
#endif

#endif	/* _AOSTRUCT_H */
	/* ----------- */

