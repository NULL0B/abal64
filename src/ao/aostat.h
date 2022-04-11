/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AOSTAT.H   				*/
/*		Version :	1.4a					*/
/*		Date	:	24/09/1991				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AOSTAT_H
#define	_AOSTAT_H

#define	STAT_VRAI	0x0001
#define	STAT_PROC	0x0002
#define	STAT_SEGM	0x0004
#define	STAT_GRAPH	0x0008
#define	STAT_CODE	0x0010
#define	STAT_HEAD	0x0020

#ifdef	AO_STATS

/*	Options and Status flags	*/
/*	------------------------	*/

struct	tcode_stats {
	EXAWORD	VmemCount;
	EXAWORD	FileCount;

	EXAWORD	ConstantSize;
	EXAWORD	GlobalTableSize;
	EXAWORD	GlobalDataSize;
	long	ExtendedSize;

	/* Procedures */
	/* ---------- */
	EXAWORD	ProcCount;
	EXAWORD	LargestProc;
	EXAWORD	LargestProcTable;
	EXAWORD	LargestProcData;
	EXAWORD	SmallestProc;
	long	ProcCodeSize;
	long	ProcDataSize;
	long	ProcTableSize;

	/* Segments */
	/* -------- */
	EXAWORD	SegmCount;
	EXAWORD	LargestSegm;
	EXAWORD	SmallestSegm;
	EXAWORD	LargestSegmData;
	EXAWORD	LargestSegmTable;
	long	SegmCodeSize;
	long	SegmDataSize;
	long	SegmTableSize;

	EXAWORD	OverlayCode;
	EXAWORD	OverlayData;

	/* Global Totals */
	/* ------------- */
	long	TotalCodeSize;
	long	TotalDataSize;
	long	TotalTableSize;
	long	StartupSize;

	};

#ifdef	_AOSTAT_C
struct tcode_stats		Stats;		/* Stats Collection Struct */
	WPTR			LocalDataPtr;	/* Local Data Segment zone */
#else
extern	struct tcode_stats	Stats;		/* Stats Collection Struct */
extern	WPTR			LocalDataPtr;	/* Local Data Segment zone */
#endif



#endif	/* AO_STATS */
	/* -------- */

#endif	/* _AOSTAT_H */
	/* --------- */

