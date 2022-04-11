/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990,1993 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	BROWSE.H				*/
/*		Version :	1.1a					*/
/*		Date	:	08/12/1993				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_BROWSE_H
#define	_BROWSE_H

#define	FILEPTR   	FILE XPTR

#define	MAX_SEARCH_PATTERN	32
#define	TRACE_EDITOR	"aed " 
#define	TRACE_OPTIONS	" -t"
#define	BROWSE_FILE 	"agr"

#ifdef	PROLOGUE
#define	ERROR_EXTENSION	".e"
#define	MEMBER_LIST_FILE "agr.tmp"
#else
#define	ERROR_EXTENSION	".err"
#define	MEMBER_LIST_FILE "agr.tmp"
#endif

BYTE	name_buffer[4096];

struct	grope_options	{
	BYTE	master[1024];
	WORD	account;
	WORD	trace;
	WORD	ignore;
	WORD	inhibit;
	WORD	expand;
	WORD	warnings;
	WORD	echo;
	WORD	verbose;
	WORD	collect;
	WORD	paths;
	BPTR	path[64];	/* 64 include paths for genmake */
	FILEPTR	tracehandle;
	BPTR	tracename;
	BPTR	editor;
	} Options;

struct	file_context	{
	BPTR	name;
	FILEPTR	handle;
	WORD	lines;
	WORD	columns;
	} Context;

struct	search_control	{
	BPTR	pattern;
	WORD	indent;
	WORD	ligne;
	WORD	column;
	int	quantity;
	int	total;
	int	files;
	} Search[MAX_SEARCH_PATTERN];

struct	collect_control	{
	WORD	status;
	BPTR	filename;
	WORD	line;
	WORD	column;
	WORD	indent;
	BYTE	token[65];
	} Collect[MAX_SEARCH_PATTERN];

#define	FOLLOWPTR	struct file_follower XPTR

struct	file_follower	{
	BPTR		name;
	WORD		hash;
	FOLLOWPTR	next;
	};

FOLLOWPTR	Follower;
WORD		MaxSearchPattern;
BPTR		Identity;

/*	-------------------------------------		*/
/*	Memory management function prototypes		*/
/*	-------------------------------------		*/

#ifndef CHECK_PROTO_ARGS
VOID  * malloc(); /* unsigned short int */
VOID  * strcpy(); /* VOID  * , VOID  * */
VOID  * memcpy(); /* VOID  * , VOID  * */
VOID  * strcat(); /* VOID  * , VOID  * */
#else
VOID  * malloc( unsigned short int );
VOID  * strcpy( VOID  * , VOID  * );
VOID  * memcpy( VOID  * , VOID  * , WORD );
VOID  * strcat( VOID  * , VOID  * );
#endif

#ifdef	UNIX
#ifndef	EXAWORD
#ifdef	VERSION666
#define	EXAWORD	unsigned long int
#else
#define	EXAWORD	unsigned short int
#endif
#endif

#include "abalcico.h"

#endif

#endif	/* _BROWSE_H */
