/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRPROC.H				*/
/*		Version :	2.1d					*/
/*		Date	:	16/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRPROC_H
#define	_TRPROC_H

#define	_EXIT_REGISTER	53

#define	_RETURN_PROC	0x7F00

#include "trstatic.h"
#include "trarg.h"

#define	_DIFFERED_PROC	0x0002
#define	_REMOTE_PROC	0x0004

#define	_DTYPE_PROC	0x0700

#define	_INT8_PROC	0x0100
#define	_INT16_PROC	0x0200
#define	_NUMERIC_PROC	0x0300
#define	_STRING_PROC	0x0400
#define	_INT32_PROC	0x0500
#define	_PTR_PROC	0x0800
#define	_PROC_PROC	0x1000
#define	_SEGM_PROC	0x2000
#define	_USER_PROC	0x4000
#define	_CODE_PROC	0x7000


#define	PRCPTR	struct otr_callproc XPTR

#define	_MAX_PROC_DESCRIPTOR 1024
#define	_MAX_PROC_LABEL 64

struct	otr_callproc	{
	ARGPTR		root;
	ARGPTR		last;
	TCPRCPTR	proc;
	TCTYPPTR	type;
	BYTE		descriptor[_MAX_PROC_DESCRIPTOR];
	WORD		ErrorFlag;
	WORD		ErrorAdr;
	RESULTPTR	Error;
	BYTE		ErrorLabel[_MAX_PROC_LABEL];
	};

/*	Function Prototypes	*/
/*	-------------------	*/

#ifndef	UNIX

WORD	extern_call_end( VOID );
WORD	analyse_tcode_proc_parameter( TCVARPTR, WORD );
TCVARPTR	collect_typed_parameters( WORD );
WORD	procedure_parameters( TCPRCPTR );
WORD	procedure_type( TCPRCPTR );
WORD	analyse_procedure_type( TCPRCPTR );
WORD	procedure_return_type( TCPRCPTR );
WORD	procedure_options( TCPRCPTR ,WORD );
#ifdef	DEBUG
WORD	showme_params( TCPRCPTR );
#endif
TCPRCPTR	add_function_method( BPTR, TCVARPTR, TCTYPPTR, WORD, WORD, WORD, WORD );
WORD	detect_extern_call( TCPRCPTR, WORD ); 
TCPRCPTR	translate_signature( WORD );
WORD	translate_proc( VOID );
WORD	translate_extern_segment( VOID );
WORD	translate_extern_proc( VOID );
WORD	close_extern_field(WORD mode);
WORD	translate_extern_field( VOID );
WORD	translate_extern_dcl( WORD );
WORD	extern_call_start( VOID );
WORD	translate_extern_call( VOID );
WORD	translate_export( VOID );
WORD	translate_extern( VOID );
WORD	translate_forward( VOID );
VOID	start_verbose_report(char * sptr);
VOID	verbose_report_footer( VOID );
VOID	close_verbose_report( VOID );
VOID	verbose_report_header(int extmode);
VOID	procedure_verbose( TCPRCPTR );
TCPRCPTR	allocate_for_procedure( VOID );
VOID	liberate_rellocation_list( RELOCPTR );
VOID	liberate_cross_reference_list( XREFPTR );
VOID	liberate_for_variable( TCVARPTR );
VOID	liberate_parameter_variable( TCVARPTR );
WORD	ensure_correct_parameter_types( TCTYPPTR, TCTYPPTR, WORD );
WORD	ensure_correct_parameter_names( TCVARPTR, TCVARPTR,WORD );
VOID	liberate_for_procedure( TCPRCPTR );
#else
WORD	translate_proc( );
WORD	translate_extern( );
WORD	translate_forward( );
VOID	start_verbose_report( );
VOID	verbose_report_footer( );
VOID	close_verbose_report( );
VOID	verbose_report_header( );
WORD	activate_procedure( );
TCVARPTR	collect_typed_parameters();
#endif

#endif	/* _TRPROC_H */
	/* --------- */

