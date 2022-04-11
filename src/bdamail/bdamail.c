/* File generated by /home/abal64/bin/linbda Version 2.1a.0.03 : /home/abal64/src/bdamail/bdamail.def -> /home/abal64/src/bdamail/bdamail.c */
#ifndef __linbda__home_abal64_src_bdamail_bdamail_c__
#define __linbda__home_abal64_src_bdamail_bdamail_c__
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
		"\n   Abal Dynamic Library : bdamail64"
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
	/* VERSION = 1 */
	/* RUNTIME = "bdamail" */
	switch ( fid ) {
		case	0 : /* mail_debug(#) */
			result=(*DynamicLibrary->fonction[0])(
				LdfParaByte(0)); break;
		case	1 : /* % smtp_connect($, %, $, %) */
			result=(*DynamicLibrary->fonction[1])(
				pptr[0],
				LdfParaWord(1),
				pptr[2],
				LdfParaWord(3)); break;
		case	2 : /* % smtp_send(#, $, %, $, %, $, %, $, %, $, %) */
			result=(*DynamicLibrary->fonction[2])(
				LdfParaByte(0),
				pptr[1],
				LdfParaWord(2),
				pptr[3],
				LdfParaWord(4),
				pptr[5],
				LdfParaWord(6),
				pptr[7],
				LdfParaWord(8),
				pptr[9],
				LdfParaWord(10)); break;
		case	3 : /* % smtp_disconnect() */
			result=(*DynamicLibrary->fonction[3])(); break;
		case	4 : /* % smtp_reset() */
			result=(*DynamicLibrary->fonction[4])(); break;
		case	5 : /* % dns_request($, %, $) */
			result=(*DynamicLibrary->fonction[5])(
				pptr[0],
				LdfParaWord(1),
				pptr[2]); break;
		case	6 : /* % mime_code($, %, $, %, $, %, $, %, $, %, $, %, $, %, #, $, %) */
			result=(*DynamicLibrary->fonction[6])(
				pptr[0],
				LdfParaWord(1),
				pptr[2],
				LdfParaWord(3),
				pptr[4],
				LdfParaWord(5),
				pptr[6],
				LdfParaWord(7),
				pptr[8],
				LdfParaWord(9),
				pptr[10],
				LdfParaWord(11),
				pptr[12],
				LdfParaWord(13),
				LdfParaByte(14),
				pptr[15],
				LdfParaWord(16)); break;
		case	7 : /* % mime_add($, %, $, %, #, $, %) */
			result=(*DynamicLibrary->fonction[7])(
				pptr[0],
				LdfParaWord(1),
				pptr[2],
				LdfParaWord(3),
				LdfParaByte(4),
				pptr[5],
				LdfParaWord(6)); break;
		case	8 : /* % mime_remove($, %, $, %) */
			result=(*DynamicLibrary->fonction[8])(
				pptr[0],
				LdfParaWord(1),
				pptr[2],
				LdfParaWord(3)); break;
		case	9 : /* % pop3_connect($, %, $, %, $, %) */
			result=(*DynamicLibrary->fonction[9])(
				pptr[0],
				LdfParaWord(1),
				pptr[2],
				LdfParaWord(3),
				pptr[4],
				LdfParaWord(5)); break;
		case	10 : /* % pop3_box_status(%, %?, %?) */
			result=(*DynamicLibrary->fonction[10])(
				LdfParaWord(0),
				pptr[1],
				pptr[2]); break;
		case	11 : /* % pop3_get_msg_buf(%, $, %?, %) */
			result=(*DynamicLibrary->fonction[11])(
				LdfParaWord(0),
				pptr[1],
				pptr[2],
				LdfParaWord(3)); break;
		case	12 : /* % pop3_get_msg(%, $, %, %) */
			result=(*DynamicLibrary->fonction[12])(
				LdfParaWord(0),
				pptr[1],
				LdfParaWord(2),
				LdfParaWord(3)); break;
		case	13 : /* % pop3_top_msg(%, $, %, %) */
			result=(*DynamicLibrary->fonction[13])(
				LdfParaWord(0),
				pptr[1],
				LdfParaWord(2),
				LdfParaWord(3)); break;
		case	14 : /* % pop3_delete_msg(%) */
			result=(*DynamicLibrary->fonction[14])(
				LdfParaWord(0)); break;
		case	15 : /* % pop3_reset() */
			result=(*DynamicLibrary->fonction[15])(); break;
		case	16 : /* % pop3_disconnect() */
			result=(*DynamicLibrary->fonction[16])(); break;
		case	17 : /* % mime_decode($, %, $, %, $, %?, $, %?, $, %?, $, %?, $, %?, $, %?, %?, %?) */
			result=(*DynamicLibrary->fonction[17])(
				pptr[0],
				LdfParaWord(1),
				pptr[2],
				LdfParaWord(3),
				pptr[4],
				pptr[5],
				pptr[6],
				pptr[7],
				pptr[8],
				pptr[9],
				pptr[10],
				pptr[11],
				pptr[12],
				pptr[13],
				pptr[14],
				pptr[15],
				pptr[16],
				pptr[17]); break;
		case	18 : /* % mime_attachment_info($, %, %, %?, %?, %?, %?, $, %?, $, %?) */
			result=(*DynamicLibrary->fonction[18])(
				pptr[0],
				LdfParaWord(1),
				LdfParaWord(2),
				pptr[3],
				pptr[4],
				pptr[5],
				pptr[6],
				pptr[7],
				pptr[8],
				pptr[9],
				pptr[10]); break;
		case	19 : /* % mime_extract($, %, %, $, %, %?) */
			result=(*DynamicLibrary->fonction[19])(
				pptr[0],
				LdfParaWord(1),
				LdfParaWord(2),
				pptr[3],
				LdfParaWord(4),
				pptr[5]); break;
		case	20 : /* % mime_field($, %, $, %, %, $, %?) */
			result=(*DynamicLibrary->fonction[20])(
				pptr[0],
				LdfParaWord(1),
				pptr[2],
				LdfParaWord(3),
				LdfParaWord(4),
				pptr[5],
				pptr[6]); break;
		case	21 : /* mail_conf(%) */
			result=(*DynamicLibrary->fonction[21])(
				LdfParaWord(0)); break;
		case	22 : /* % smtp_connect_with_auth($, %, $, %, $, %, $, %, %) */
			result=(*DynamicLibrary->fonction[22])(
				pptr[0],
				LdfParaWord(1),
				pptr[2],
				LdfParaWord(3),
				pptr[4],
				LdfParaWord(5),
				pptr[6],
				LdfParaWord(7),
				LdfParaWord(8)); break;
		default	: result=138;
		break;
		}
	/* END */
	return(result);
}

/* Library Constructor */

public EXAWORD LdfBdaInitialise(
	BDA_INIT FAR PTR descriptor,
	EXAWORD dlength)
{
	int	i=0;
	rt_init = descriptor;
	function_counter=23;
	if (!(DynamicLibrary = InitRelais()))
		return(139);
	else	return(0);
}

#endif  /* __linbda__home_abal64_src_bdamail_bdamail_c__ */
/* End of File */