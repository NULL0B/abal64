/* File generated by /home/abal64/bin/linbda Version 2.1a.0.03 : /home/abal64/src/json/abaljson.def -> /home/abal64/src/json/abaljson.c */
#ifndef __linbda__home_abal64_src_json_abaljson_c__
#define __linbda__home_abal64_src_json_abaljson_c__
#include <stdio.h>
#include <setjmp.h>
#include "ldfbda.h"

private BDA * DynamicLibrary;
	public  LPBDA_INIT	rt_init;
	public  BDA_INIT	v_rt_init;
	public  BDA_ARG rt_arg;

/* ABAL Runtime Error Trap */
private	jmp_buf rt_error_context;
public  VOID rt_error(EXAWORD evalue) { 
	longjmp(rt_error_context,evalue);
	return;
}

private int function_counter=0;
/* ABAL Word Conversions */
public EXAWORD GetAbalInt8(char FAR PTR bptr)
{
	return(*bptr);
}

public EXAWORD GetAbalInt16(BYTE FAR PTR wptr)
{
	return(((*wptr<< 8)|*(wptr+1)));
}

public EXAWORD GetAbalInt32(BYTE FAR PTR wptr)
{
	int length=4;
	EXAWORD result=0;
	while ( length-- ) result = ((result << 8) | (*(wptr++) & 0x00FF));
	return(result);
}

public EXAWORD GetAbalInt64(BYTE FAR PTR wptr)
{
	int length=8;
	EXAWORD result=0;
	while ( length-- ) result = ((result << 8) | (*(wptr++) & 0x00FF));
	return(result);
}

public void PutAbalInt8(char FAR * wptr, EXAWORD v)
{
	*wptr = (v & 0x00FF);
	return;
}
public void PutAbalInt16(BYTE FAR * wptr, EXAWORD v)
{
	int length=2;
	while ( length-- ) { *(wptr +length) = (v & 0x00FF); v >>= 8; }
	return;
}

public void PutAbalInt32(BYTE FAR * wptr, EXAWORD v)
{
	int length=4;
	while ( length-- ) { *(wptr +length) = (v & 0x00FF); v >>= 8; }
	return;
}

public void PutAbalInt64(BYTE FAR * wptr, EXAWORD v)
{
	int length=8;
	while ( length-- ) { *(wptr +length) = (v & 0x00FF); v >>= 8; }
	return;
}

#define LdfParaWord(n) (tptr[n]==1 ? GetAbalInt16(pptr[n]) : (tptr[n]==0 ? GetAbalInt8(pptr[n]) : (tptr[n]==5 ? GetAbalInt32(pptr[n]): GetAbalInt64(pptr[n]) )))
#define LdfParaByte(n) (tptr[n]==1 ? (GetAbalInt16(pptr[n])&0x00FF) : (tptr[n]==0 ? GetAbalInt8(pptr[n]):(tptr[n]==5?(GetAbalInt32(pptr[n])&0x00FF):(GetAbalInt64(pptr[n])&0x00FF))))
/* Library Information */
public EXAWORD LdfBdaInformation(void * vptr)
{
	printf(
		"\n   Abal Dynamic Library : Json64"
		);
	printf(
		"\n   Copyright (c) Amenesik / Sologic \n\n"
		);
	return(0);
}

/* Library Destructor */
public EXAWORD LdfBdaTerminate()
{
	if (DynamicLibrary->fin != (VOID (FAR PTR)()) 0)
		 (*DynamicLibrary->fin)();
	return(0);
}

/* Library Call Through */
public EXAWORD LdfBdaExecute(
	EXAWORD fid,
	EXAWORD argc,
	BYTE FAR tptr[],
	VOID FAR PTR FAR pptr[],
	EXAWORD FAR wptr[],
	int FAR * eptr)
{
	EXAWORD	result=0;
	rt_arg.c=argc; rt_arg.v=pptr;
	rt_arg.l=wptr; rt_arg.t=tptr;
	if ((result=setjmp(rt_error_context))!=0) {
		if ( eptr != (int FAR *) 0) *eptr = result;
		return( result );
		}
	/* version = 1 */
	/* runtime = "json" */
	switch ( fid ) {
		case	0 : /* %openjson($,%) */
			result=(*DynamicLibrary->fonction[0])(
				pptr[0],
				LdfParaWord(1)); break;
		case	1 : /* %createjson($,%) */
			result=(*DynamicLibrary->fonction[1])(
				pptr[0],
				LdfParaWord(1)); break;
		case	2 : /* %readjson(%,$,%) */
			result=(*DynamicLibrary->fonction[2])(
				LdfParaWord(0),
				pptr[1],
				LdfParaWord(2)); break;
		case	3 : /* %writejson(%,%,$,%) */
			result=(*DynamicLibrary->fonction[3])(
				LdfParaWord(0),
				LdfParaWord(1),
				pptr[2],
				LdfParaWord(3)); break;
		case	4 : /* %closejson(%) */
			result=(*DynamicLibrary->fonction[4])(
				LdfParaWord(0)); break;
		case	5 : /* %readavro(%,%,$,%) */
			result=(*DynamicLibrary->fonction[5])(
				LdfParaWord(0),
				LdfParaWord(1),
				pptr[2],
				LdfParaWord(3)); break;
		case	6 : /* %writeavro(%,%,$,%) */
			result=(*DynamicLibrary->fonction[6])(
				LdfParaWord(0),
				LdfParaWord(1),
				pptr[2],
				LdfParaWord(3)); break;
		default	: result=138;
		break;
		}
	/* end */
	return(result);
}

/* Library Constructor */

public EXAWORD LdfBdaInitialise(
	BDA_INIT FAR PTR descriptor,
	EXAWORD dlength)
{
	int	i=0;
	rt_init = descriptor;
	function_counter=7;
	if (!(DynamicLibrary = InitRelais()))
		return(139);
	else	return(0);
}

#endif  /* __linbda__home_abal64_src_json_abaljson_c__ */
/* End of File */
