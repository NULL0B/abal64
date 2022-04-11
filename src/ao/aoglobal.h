/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AOGLOBAL.H				*/
/*		Version :	1.4a					*/
/*		Date	:	06/11/1991				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AOGLOBAL_H
#define	_AOGLOBAL_H


#ifdef	_AO_C

/*	Optimiser Global Variables 	*/
/*	--------------------------	*/
EXAWORD	debug;			/* Activate debuging infos		*/
EXAWORD	MasterPhase;		/* 0 => Procedure , 1 => Segment	*/
EXAWORD	HeapSize;		/* Size of Local Variable Heap		*/
EXAWORD	diezheap;		/* Default local variable heap (procs)	*/
EXAWORD	diezfile;		/* Default file table size		*/
EXAWORD	dieztemp;		/* Default work zone 			*/
EXAWORD	diezpile;		/* Default Gosub/Proc/Segment Stack	*/
EXAWORD	BlockLen;		/* Global new length of Code Segment	*/
EXAWORD	BlockChange;		/* Indictes a Descriptor Table Modif	*/
EXAWORD	Handle;			/* T-Code File Handle			*/
EXAWORD	OptCount;		/* Count of Optimisations performed	*/
EXAWORD	SegId;			/* Current Segment ID			*/
EXAWORD	PrcId;			/* Current Procedure ID			*/
BYTE	ControlZone[HEADERBLOCK];/* Sector Zero Control Information	*/
BPTR	tcLDT;			/* Local Descriptor Table Base		*/
BPTR	tcLCT;			/* Local Constant Table Base		*/
BPTR	newLDT;			/* Compression zone for new LDT		*/
BPTR	tcLNT;			/* Local Nmes Table Base		*/
BPTR	tcPNT;			/* Procedure Names Table		*/
EXAWORD	lnPNT;			/* Length of Names Table		*/
BPTR	tcGDT;			/* Global Descriptor Table Base		*/
BPTR 	GlobalDataImage;	/* Initialise Global Data Image 	*/
BPTR	newGDT;			/* Compression zone for new GDT		*/
BPTR	tcGNT;			/* Global Names Table Base		*/
BPTR	tcGKT;			/* Global constants table		*/
BPTR 	newGKT;			/* Global constants table		*/
EXAWORD	tcGKL;			/* Length of Constants table		*/
BPTR	tcCS;			/* Current Code Segment Base Pointer	*/
BPTR	tc_SDT;			/* Segment Descriptor Table Pointer	*/
EXAWORD	ln_SDT;			/* Length of Descriptor Taable		*/ 
BPTR	tc_PDT;			/* Procedure Descriptor Table Base	*/
EXAWORD	ln_PDT;			/* Length of Procedure Table		*/
EXAWORD	sectGKT;		/* Sector for Constant Table Storage	*/
EXAWORD	ProgramShrink;		/* Size of program Shrinking		*/
EXAWORD	CodeShrink;		/* Total Code shrinking			*/
EXAWORD	TableShrink;		/* Total Data Table Shrinking		*/
EXAWORD	statix;			/* Indicates code block has static data	*/

#ifdef	PRL
BYTE	tempname[BLOCK];	/* Temporary Name Buffer		*/
#endif


#else	/* ! _AO_C */
	/* ------- */

/*	Optimiser Global Variables 	*/
/*	--------------------------	*/
extern	EXAWORD	debug;		/* Activate debuging infos		*/
extern	EXAWORD	MasterPhase;	/* 0 => Procedure , 1 => Segment	*/
extern	EXAWORD	HeapSize;	/* Size of Local Variable Heap		*/
extern	EXAWORD	diezheap;	/* Default local variable heap (procs)	*/
extern	EXAWORD	diezfile;	/* Default file table size		*/
extern	EXAWORD	dieztemp;	/* Default work zone 			*/
extern	EXAWORD	diezpile;	/* Default Gosub/Proc/Segment Stack	*/
extern	EXAWORD	BlockLen;	/* Global new length of Code Segment	*/
extern	EXAWORD	BlockChange;	/* Indictes a Descriptor Table Modif	*/
extern	EXAWORD	Handle;		/* T-Code File Handle			*/
extern	EXAWORD	OptCount;	/* Count of Optimisations performed	*/
extern	EXAWORD	SegId;		/* Current Segment ID			*/
extern	EXAWORD	PrcId;		/* Current Procedure ID			*/
extern	BYTE	ControlZone[BLOCK]; /* Sector Zero Control Information	*/
extern	BPTR	tcLDT;		/* Local Descriptor Table Base		*/
extern	BPTR	tcLCT;		/* Local Constants Table Base		*/
extern	BPTR	newLDT;		/* Compression zone for new LDT		*/
extern	BPTR	tcLNT;		/* Local Nmes Table Base		*/
extern	BPTR	tcPNT;		/* Procedure Names Table		*/
extern	EXAWORD	lnPNT;		/* Length of Names Table		*/
extern	BPTR	tcGDT;		/* Global Descriptor Table Base		*/
extern	BPTR	newGDT;		/* Compression zone for new GDT		*/
extern	BPTR 	GlobalDataImage;/* Initialise Global Data Image 	*/
extern	BPTR	tcGNT;		/* Global Names Table Base		*/
extern	BPTR	tcGKT;		/* Global constants table		*/
extern	BPTR	newGKT;		/* Global constants table		*/
extern	EXAWORD	tcGKL;		/* Length of Constants table		*/
extern	BPTR	tcCS;		/* Current Code Segment Base Pointer	*/
extern	BPTR	tc_SDT;		/* Segment Descriptor Table Pointer	*/
extern	EXAWORD	ln_SDT;		/* Length of Descriptor Taable		*/ 
extern	BPTR	tc_PDT;		/* Procedure Descriptor Table Base	*/
extern	EXAWORD	ln_PDT;		/* Length of Procedure Table		*/
extern	EXAWORD	sectGKT;	/* Sector for Constant Table Storage	*/
extern	EXAWORD	ProgramShrink;	/* Size of program Shrinking		*/
extern  EXAWORD	statix;		/* Indicates code block has static data	*/

#ifdef	PRL
extern	BYTE	tempname[BLOCK]; /* Temporary Name Buffer		*/
#endif

#endif	/* _AO_C */
	/* ----- */



#endif	/* _AOGLOBAL_H */
	/* ----------- */

