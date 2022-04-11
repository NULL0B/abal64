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
	WORD	UsingDLL;	/* OTR is a dynamic library		*/
	WORD	UsingOtr;	/* Inhibit ATR usage, OTR will be used	*/
#endif
	WORD	InhibitErrorTrace; /* normally VRAI -x sets FAUX aed /T */
	WORD	Interactive;	/* -j for interactive inspection	*/
	WORD	Conditions;	/* Default conditions for methods	*/
	WORD	Inhibitions;	/* Inhibited Conditions			*/
	WORD	InitLocal;	/*					*/
	WORD	Inform;		/* -h Generates List of classes used	*/
	BPTR	InformFile;	/* -h Information file			*/
	WORD	LibUse;
	WORD	Generate;	/* -g inhibits target creation		*/
	WORD	Inhibit;	/* -c Inhibit translation phase		*/
	WORD	Style;		/* Indicates style required		*/
	WORD	Optimise;	/* -o Indicates Optimisation required	*/
	WORD	Include;	/* -i Include path componant		*/
	WORD	Verbose;	/* -v activate messages			*/
	WORD	SourceEcho;	/* -e Echo Source file to screen	*/
	WORD	TargetEcho;	/* -t Echo Target file to screen	*/
	WORD	ErrorTrace;	/* -e Activates aplus/aed error trace	*/
	WORD	CrossTrace;	/* -x Activate Double trace		*/
	BPTR	Extension;	/* -s Default Source Extension          */
	WORD	Translator;	/* Options to be passed to atr phase	*/
				/* -w -o -a -v -e -m -l -i -d		*/
	WORD	Compile;	/* Activate class compilation		*/
	BPTR	TempDevice;	/* Device to use fore temporary file	*/
	BPTR	ListFile;	/* List filename when option -l		*/
	BPTR	SearchPath;	/* Include search path when option -i	*/
	BPTR	ErrorFile;	/* Error filename when options -e	*/
	BPTR	Result;		/* Result filename when option -d	*/
	WORD	Verify;		/* Activates Symbol verification	*/
	WORD	Version;	/* Current APLUS/ABAL Version Code	*/
	WORD	Pannel;		/* -h Activates control pannel		*/
	WORD	Report;		/* Activate Report output		*/
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
