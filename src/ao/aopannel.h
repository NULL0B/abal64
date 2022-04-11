/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1992 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	AOPANNEL.H				*/
/*		Version :	1.1a					*/
/*		Date	:	01/10/1992				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_PANNEL_H
#define	_PANNEL_H

#define	PUBLIC_SCOPE	
#define	PRIVATE_SCOPE	extern

#define	cico_chr( c ) x_putch( c )
#define	cico_atb( n ) atb( n )
#define cico_tab( c,l) pos( l, c )
#define cico_curser_off cico_atb( 25 );
#define cico_curser_on  cico_atb( 26 );
#define	cico_save_screen cico_chr( 0x01B ); cico_chr( '>' )
#define	cico_recover_screen cico_chr( 0x01B ); cico_chr( '<' )

#define cico_paint( foreground, background ) foregr( foreground ); backgr( background );
#ifdef	UNIX
#define	cico_bufferisation x_bstart()
#define	cico_flush	   x_bflush()
#ifdef	VMS
extern	noshare	int	qio_usage_flag;
EXAWORD	VmsCico=0;
#endif
void cico_initialisation(cicoflag) {
#ifdef	VMS
	if ( getenv("PROLOGUE") != (BPTR) 0)
		VmsCico = 1;
	else	VmsCico = 0;
	qio_usage_flag  = 0;
#endif
	modterm(0); 
	initerm();
	return;
	}
#else
#define	cico_bufferisation
#define	cico_flush
#define	cico_initialisation(cicoflag) { \
		initerm();		\
		if ( cicoflag != 2 )	\
			x_putch(0x000C); \
		}

#endif
#define	cico_liberation		finterm()
#define	cico_configuration( n )	conf( n )
	
#include "aograph.h"

#define	PANNEL_COL		 9
#define	PANNEL_LIN		 7
#define	PANNEL_WIDTH		62
#define	PANNEL_HEIGHT 		 9
#define	BACKGROUND_COLOUR	 4
#define	MED_LIGHT_COLOUR	15
#define	LOW_LIGHT_COLOUR	11 
#define	HIGH_LIGHT_COLOUR	 1

/*
 *	Messages used in the status pannel
 *	----------------------------------
 *
 */
#define	CODE_SHRINK_MSG	 "Code reduction"
#define	TABLE_SHRINK_MSG "Table reduction"
#define	LIBRARY_MSG	"Library Class"
#define	LIBFILE_MSG	"Loading library"
#define	RESULT_FILE_MSG "Result"
#define	SOURCE_FILE_MSG "Source"
#define	WARNINGS_MSG	"Warnings"
#define	OPTIMISATION_MSG "Optimisations"
#define	PROC_COUNT_MSG	"Segments"
#define	SEGM_COUNT_MSG	"Procedures"
#define	SWAP_HIT_MSG	"Swap hit  count"
#define	SWAP_MISS_MSG	"Swap miss count"
#define	SWAP_SIZE_MSG	"Swap file size"
#define	OBJECT_STATUS_MSG "Object instance"
#define	CLASS_STATUS_MSG "Class definition"
#define	PROC_STATUS_MSG "Procedure"
#define	SEGM_STATUS_MSG "Segment"
#define	SUSPEND_MSG	"Operation interupted : ESC=Continue, RC=Abandon"
#define	ABANDON_MSG	"Operation abandoned"
#ifdef	_PANNEL_C

struct	pannel_infos	{
	EXAWORD	WarningCount;
	EXAWORD	OptiCount;
	EXAWORD	ProcCount;
	EXAWORD	SegmCount;
	EXAWORD	HighLight;
	EXAWORD	LowLight;
	EXAWORD	MedLight;
	EXAWORD	BackGround;
	EXAWORD	InitState;
	LONG	CodeShrink;
	LONG	TableShrink;
	BYTE	StatusMessage[64];
	BYTE	ErrorMessage[64];
	BYTE	SourceMessage[64];
	BYTE	TargetMessage[64];
	EXAWORD	ErrorFlag;

	};	

struct	pannel_infos	Pannel;

#include "abalcico.h"

#endif	/* _PANNEL_C */
#endif	/* _PANNEL_H */
	/* --------- */


