/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	TCODE.C   				*/
/*		Version :	1.4a					*/
/*		Date	:	24/09/1991				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AOPROTO_H
#define	_AOPROTO_H

#ifdef	AO_LISTFILE

/*	--------------------		*/
/*	Functions in TCODE.C 		*/
/*	--------------------		*/
extern	void	LabelFormat(BPTR,EXAWORD,EXAWORD);
#ifndef AIX_VERS
extern	void	DataTable(BPTR,EXAWORD,BPTR,EXAWORD);
#else /* AIX_VERS */
extern	void	DataTable(BPTR,EXAWORD,BPTR,EXAWORD);
#endif /* AIX_VERS */
extern	void	ProgStart(EXAWORD,EXAWORD,EXAWORD,EXAWORD,EXAWORD);
extern	void	ProgEnd(EXAWORD);
extern	void	SegmentStart(EXAWORD,EXAWORD);
extern	void	ProcedureStart(EXAWORD,EXAWORD);
extern	void	SegmentEnd(EXAWORD,EXAWORD);
extern	void	ProcedureEnd(EXAWORD,EXAWORD);
extern	EXAWORD TcodeList(BPTR,EXAWORD,EXAWORD);
extern	void	AffEtt(EXAWORD);
extern	void	AffVarb(EXAWORD);
extern	void	AffCons(EXAWORD);
extern	void	AffReg(EXAWORD);
extern	void	HexWord(EXAWORD);
extern	void	HexAdresse(EXAWORD);
extern	void	IoMnemonic(EXAWORD);
extern	void	EscMnemonic(EXAWORD);
extern	void	Mnemonic(EXAWORD);

	/* ----------- */
#endif	/* AO_LISTFILE */
	/* ----------- */

#ifdef	AO_COMPILER
/*	-----------------------		*/
/*	Functions in COMPILER.C		*/
/*	-----------------------		*/
extern	void	StartSegment(EXAWORD);
extern	void	StartProcedure(EXAWORD);
extern	void	EndSegment(EXAWORD);
extern	void	EndProcedure(EXAWORD);
extern	void	InitCompile();
extern	void	EndCompile();
extern	void	Compiler( BPTR , EXAWORD );
	/* ----------- */
#endif	/* AO_COMPILER */
	/* ----------- */

/*	Functions in COPYAT.C		*/
/*	---------------------		*/
extern	void	WriteBlock(EXAWORD,BPTR,EXAWORD,EXAWORD);
extern	BPTR	MakeBlock(EXAWORD);
extern	BPTR	LoadBlock(EXAWORD,EXAWORD,EXAWORD);
extern	EXAWORD	CopyFile(EXAWORD,BPTR);
extern	BPTR	construct_filename( BPTR, BPTR );

/*	Functions in LABELS.C		*/
/*	---------------------		*/
extern	EXAWORD	LabelKnown( EXAWORD );
extern	EXAWORD	IsBackPatch( BPTR );
extern	EXAWORD	initialise_constant_compression( EXAWORD );
extern	EXAWORD	terminate_constant_compression( EXAWORD, EXAWORD );

/*	Functions in LISTFILE.C		*/
/*	-----------------------		*/
extern	void	OutPutCreate( BPTR );
extern	void	OutPutClose( void );
extern	void	OutPutInit( void );
extern	void	StreamString( BPTR );
extern	void	StreamByte( EXAWORD );
extern	void	StreamLine( void );

	/* --------------- */
#else	/* UNIX prototypes */
	/* --------------- */
#ifdef AIX_VERS
#if  defined(LINT_ARGS) && !defined(LINUX)

#ifdef	AO_LISTFILE
/*	--------------------		*/
/*	Functions in TCODE.C 		*/
/*	--------------------		*/
extern	void	LabelFormat(BPTR,EXAWORD,EXAWORD);
extern	void	DataTable(BPTR,EXAWORD,BPTR,EXAWORD);
extern	void	ProgStart(EXAWORD,EXAWORD,EXAWORD,EXAWORD,EXAWORD);
extern	void	ProgEnd(EXAWORD);
extern	void	SegmentStart(EXAWORD,EXAWORD);
extern	void	ProcedureStart(EXAWORD,EXAWORD);
extern	void	SegmentEnd(EXAWORD,EXAWORD);
extern	void	ProcedureEnd(EXAWORD,EXAWORD);
extern	void	TcodeList(BPTR,EXAWORD,EXAWORD);
extern	void	AffEtt(EXAWORD);
extern	void	AffVarb(EXAWORD);
extern	void	AffCons(EXAWORD);
extern	void	AffReg(EXAWORD);
extern	void	HexWord(EXAWORD);
extern	void	HexAdresse(EXAWORD);
extern	void	IoMnemonic(EXAWORD);
extern	void	EscMnemonic(EXAWORD);
extern	void	Mnemonic(EXAWORD);

	/* ----------- */
#endif	/* AO_LISTFILE */
	/* ----------- */

#ifdef	AO_COMPILER
/*	-----------------------		*/
/*	Functions in COMPILER.C		*/
/*	-----------------------		*/
extern	void	StartSegment(EXAWORD);
extern	void	StartProcedure(EXAWORD);
extern	void	EndSegment(EXAWORD);
extern	void	EndProcedure(EXAWORD);
extern	void	InitCompile();
extern	void	EndCompile();
extern	void	Compiler( BPTR , EXAWORD );
	/* ----------- */
#endif	/* AO_COMPILER */
	/* ----------- */

/*	Functions in COPYAT.C		*/
/*	---------------------		*/
extern	void	WriteBlock(EXAWORD,BPTR,EXAWORD,EXAWORD);
extern	BPTR	MakeBlock(EXAWORD);
extern	BPTR	LoadBlock(EXAWORD,EXAWORD,EXAWORD);
extern	EXAWORD	CopyFile(EXAWORD,BPTR);
extern	BPTR	construct_filename( BPTR, BPTR );

/*	Functions in LABELS.C		*/
/*	---------------------		*/
extern	EXAWORD	LabelKnown( EXAWORD );
extern	EXAWORD	IsBackPatch( BPTR );
extern	EXAWORD	initialise_constant_compression( EXAWORD );
extern	EXAWORD	terminate_constant_compression( EXAWORD, EXAWORD );

/*	Functions in LISTFILE.C		*/
/*	-----------------------		*/
extern	void	OutPutCreate( BPTR );
extern	void	OutPutClose( void );
extern	void	OutPutInit( void );
extern	void	StreamString( BPTR );
extern	void	StreamByte( EXAWORD );
extern	void	StreamLine( void );

#endif	/* NON LINT_ARGS */
#endif /* AIX_VERS */

#endif	/* _AOPROTO_H */
	/* ---------- */

