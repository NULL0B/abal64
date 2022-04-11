/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXATTACH.H
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */
#ifndef	_EXATTACH_H
#define	_EXATTACH_H

#define	ATTLOGPTR struct attachment_log PTR	
#define	ATTENTPTR struct attachment_entry PTR
#define	_SIZE_ATTACH_PTR 7


struct	attachment_entry {
	BPTR  		ipt;
	OVLOBJPTR	context;
	ATTENTPTR	next;
	};

#ifdef	ABAL_REMOTE
#include "exremote.h"
#endif

struct	attachment_log {
	EX_FILE_HANDLE 	handle;	
	BPTR		filename;
	ATTENTPTR	entry;
	EXAWORD		sgct;	/* Sector Constants Table	*/
	EXAWORD		lgct;	/* Length Constants Table	*/
	EXAWORD		sgdt;	/* Sector Data Table		*/
	EXAWORD		lgdt;	/* Length Data Table		*/
	EXAWORD		sgpt;	/* Sector Procedure Table	*/
	EXAWORD		lgpt;	/* Length Procedure Table	*/
	EXAWORD		sglt;	/* Sector Library Table		*/
	EXAWORD		lglt;	/* Length Library Table		*/
	EXAWORD		lgds;	/* Length Local Data Memory	*/
	BPTR		procedures;
	EXAWORD		sgpx;	/* Sector Export Table	*/
	EXAWORD		lgpx;	/* Length Export Table	*/
	BPTR		callbacks;
	EXAWORD		procmaxid;
	ATTLOGPTR	next;
	ATTLOGPTR	prev;
#ifdef	DEBUGGER
	EXAWORD		dbok;
	VPTR		debug;
#endif
#ifdef	VERSION_XX
	EXAWORD		islocal;	/* Local Variable Detection mask */
#ifdef	VERSION666
	EXAWORD		wordsize;	/* 16/32 word size indicator	 */
#endif
#endif
#ifdef	ABAL_REMOTE
	EXREMOTEPTR	remote;
#endif
	};

ATTLOGPTR	AttachmentLog;

#ifndef	UNIX
VPTR		load_tcode_libraries( BPTR );
EXAWORD		kode_b_lode( BPTR, EXAWORD, EXAWORD );
BPTR 		load_tcode_procedures( EXAWORD, BPTR);
#ifdef	DEBUGGER
VPTR		symbolic_attachment( BPTR );
#endif
#else
VPTR		load_tcode_libraries();
EXAWORD		kode_b_lode();
BPTR 		load_tcode_procedures();
#ifdef	DEBUGGER
VPTR		symbolic_attachment();
#endif
#endif


#endif	/* _EXATTACH_H */
	/* ----------- */


