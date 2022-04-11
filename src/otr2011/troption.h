
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TROPTION.H				*/
/*		Version :	2.1d					*/
/*		Date	:	08/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TROPTION_H
#define	_TROPTION_H

struct	otr_options	{
	WORD	ExportAll;
	WORD	NoInput;
	WORD	ExternCommon;
	WORD	Strict;
	WORD	DirectiveDate;
	WORD	InitLocal;
	WORD	PublicCommon;
	WORD	KeepQuote;
	WORD	Invocation;
	WORD	KeyboardFlush;
	WORD	NoFlush;
	WORD	Con;
	WORD	InhibitAlias;
	WORD	DuplicateSymbols;
	WORD	TcodeVersion;
	WORD	WordSize;
	WORD	Priority;
	WORD	Special;
	WORD	Verbose;
	WORD	UpperCase;
	WORD	TraceErrors;
	WORD	ErrorCount;
	WORD	ErrorLimit;
	WORD	SourceTrace;
	WORD	TargetTrace;
	WORD	Symbolic;
	WORD	Optimise;
	WORD	Generate;
	WORD	Enhanced;
	WORD	Warning;
	WORD	TokenSize;
	WORD	LabelSize;
	WORD	Aliasing;
	WORD	LocalConstant;
	BPTR	ErrorFile;
	WORD	ListFlag;
	WORD	BibMath;
	BPTR	ListFile;
	BPTR	Inclusion;
	BPTR	Extension;
	BPTR	TargetName;
	WORD	LabelGroup;
	WORD	TargetType;
	WORD	BlockComment;
	WORD	AutoGetLine;
#ifdef	ABAL33A
	WORD	NoAutoLink;
	BPTR	AutoLink;
#endif
	};

#define	_OPTIMISE_LOAD 			0x0001
#define	_OPTIMISE_STORE			0x0002
#define	_OPTIMISE_TABLES			0x0004
#define	_OPTIMISE_INCREMENT		0x0008
#define	_OPTIMISE_PARAMETERS		0x0010
#define	_OPTIMISE_NEWLINE   		0x0020

#define	_ALL_OPTIMISATIONS ( _OPTIMISE_LOAD | _OPTIMISE_STORE | _OPTIMISE_TABLES | _OPTIMISE_PARAMETERS | _OPTIMISE_NEWLINE )

#define	_ENHANCED_AFFECTATION		0x0001
#define	_ENHANCED_COMPARE    		0x0002
#define	_ENHANCED_AUTOCONV   		0x0004
#define	_ENHANCED_LABEL      		0x0008
#define	_ENHANCED_ASSIGN     		0x0010

#define	_ENHANCED_LOCAL			0x0100	
#define	_ENHANCED_INLINE		0x0200
#define	_ENHANCED_INDIRECT		0x0400
#define	_ENHANCED_OPERATORS		0x0800
#define	_ENHANCED_PARAMETERS		0x1000
#define	_ENHANCED_STRICT     		0x2000
#define	_ENHANCED_64K     		0x4000

#define	_TCODE_ENHANCEMENTS (_ENHANCED_AFFECTATION | _ENHANCED_COMPARE | _ENHANCED_AUTOCONV | _ENHANCED_LABEL | _ENHANCED_ASSIGN )
#define	_OBJECT_ENHANCEMENTS ( _ENHANCED_LOCAL | _ENHANCED_INLINE | _ENHANCED_INDIRECT | _ENHANCED_OPERATORS | _ENHANCED_PARAMETERS | _ENHANCED_STRICT )

#define	_ALL_ENHANCEMENTS  ( _TCODE_ENHANCEMENTS | _OBJECT_ENHANCEMENTS )

#ifdef	_TRMAIN_C
	struct	otr_options	OtrOption;
#else
EXTERN	struct	otr_options	OtrOption;
#endif

#endif	/* _TROPTION_H */
	/* ----------- */

