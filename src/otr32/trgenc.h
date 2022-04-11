#ifndef	_TRGENC_H
#define	_TRGENC_H

#ifndef	FILEPTR	
#define	FILEPTR	FILE XPTR
#endif

#define	_RTL_RAISE_ERROR "rtl_raise(_rtl_status)"

#define	CFILEPTR	struct output_control XPTR

struct	output_control	{
	BPTR		name;
	FILEPTR 	handle;
	WORD		indentation;
	CFILEPTR	next;
	};

#ifdef	_TRGENC_C
struct	output_control OutputC;
struct	output_control OutputH;
struct	output_control OutputF;
CFILEPTR              	MakeFile;
CFILEPTR              	Output;
CFILEPTR              	Header;
CFILEPTR              	Footer;
#else
#ifdef	_TRGENRTL_C
EXTERN	struct	output_control OutputC;
EXTERN	struct	output_control OutputH;
EXTERN	struct	output_control OutputF;
EXTERN	CFILEPTR              	MakeFile;
EXTERN	CFILEPTR              	Output;
EXTERN	CFILEPTR              	Header;
EXTERN	CFILEPTR              	Footer;
#endif
#endif

#ifndef	UNIX
BPTR		RtlDataManagerName(VOID);
BPTR		IntegerResult(WORD);
BPTR		VariableExpression(WPTR);
BPTR		TypedExpression(WORD);
BPTR		EvaluateExpression(VOID);
TCVARPTR	VariableOperand( VOID );
#else
BPTR		RtlDataManagerName();
BPTR		IntegerResult();
BPTR		VariableExpression();
BPTR		TypedExpression();
BPTR		EvaluateExpression();
TCVARPTR	VariableOperand();
#endif

#include "trgenrtl.h"

#endif	/* _TRGENC_H */
	/* --------- */



