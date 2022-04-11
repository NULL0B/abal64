/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1991, 1993 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	OPTIONS.H				*/
/*		Version :	1.1a					*/
/*		Date	:	08/07/1993				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	OPTIONSH
#define	OPTIONSH

struct	aplus_options {
				/* ------------------------------------ */
				/* -r Resets all options to FAUX	*/
#ifdef	USING_DLL
	EXAWORD	UsingDLL;	/* OTR is a dynamic library		*/
	EXAWORD	UsingOtr;	/* Inhibit ATR usage, OTR will be used	*/
#endif
	EXAWORD	InhibitErrorTrace; /* normally VRAI -x sets FAUX aed /T */
	EXAWORD	Interactive;	/* -j for interactive inspection	*/
	EXAWORD	Conditions;	/* Default conditions for methods	*/
	EXAWORD	Inhibitions;	/* Inhibited Conditions			*/
	EXAWORD	InitLocal;	/*					*/
	EXAWORD	Inform;		/* -h Generates List of classes used	*/
	BPTR	InformFile;	/* -h Information file			*/
	EXAWORD	LibUse;
	EXAWORD	Generate;	/* -g inhibits target creation		*/
	EXAWORD	Inhibit;	/* -c Inhibit translation phase		*/
	EXAWORD	Style;		/* Indicates style required		*/
	EXAWORD	Optimise;	/* -o Indicates Optimisation required	*/
	EXAWORD	Include;	/* -i Include path componant		*/
	EXAWORD	Verbose;	/* -v activate messages			*/
	EXAWORD	SourceEcho;	/* -e Echo Source file to screen	*/
	EXAWORD	TargetEcho;	/* -t Echo Target file to screen	*/
	EXAWORD	ErrorTrace;	/* -e Activates aplus/aed error trace	*/
	EXAWORD	CrossTrace;	/* -x Activate Double trace		*/
	BPTR	Extension;	/* -s Default Source Extension          */
	EXAWORD	Translator;	/* Options to be passed to atr phase	*/
				/* -w -o -a -v -e -m -l -i -d		*/
	EXAWORD	Compile;	/* Activate class compilation		*/
	BPTR	TempDevice;	/* Device to use fore temporary file	*/
	BPTR	ListFile;	/* List filename when option -l		*/
	BPTR	SearchPath;	/* Include search path when option -i	*/
	BPTR	ErrorFile;	/* Error filename when options -e	*/
	BPTR	Result;		/* Result filename when option -d	*/
	EXAWORD	Verify;		/* Activates Symbol verification	*/
	EXAWORD	Version;	/* Current APLUS/ABAL Version Code	*/
	EXAWORD	Pannel;		/* -h Activates control pannel		*/
	EXAWORD	Report;		/* Activate Report output		*/
				/* ------------------------------------ */
	};
#ifdef	APLUSC
	struct	aplus_options	Options;
#else
EXTERN	struct	aplus_options	Options;
#endif

#define	verbalisation	(( Options.Verbose ) && ( ! Options.Pannel ))

#endif	/* OPTIONSH */
	/* -------- */
