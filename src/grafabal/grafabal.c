/* File generated by /opt/prologue/bin/linbda Version 1.1b.0.02 : /home/Dev/abal32/src/grafabal/grafabal.def -> /home/Dev/abal32/src/grafabal/grafabal.c */
#ifndef __linbda__home_Dev_abal32_src_grafabal_grafabal_c__
#define __linbda__home_Dev_abal32_src_grafabal_grafabal_c__
#include <stdio.h>
#include <setjmp.h>
#include "ldfbda.h"

static BDA * DynamicLibrary;
	LPBDA_INIT	rt_init;
	BDA_INIT	v_rt_init;
	BDA_ARG rt_arg;

/* ABAL Runtime Error Trap */
static jmp_buf rt_error_context;
VOID rt_error(EXAWORD evalue) { 
	longjmp(rt_error_context,evalue);
	return;
}

static int function_counter=0;
/* ABAL Word Convertor */
static EXAWORD LdfAbalByte(char FAR PTR bptr)
{
	return(*bptr);
}

static EXAWORD LdfAbalWord(BYTE FAR PTR wptr)
{
	return(((*wptr<< 8) | *(wptr+1)));
}

#define LdfParaWord(n) ( tptr[n] == 1 ? LdfAbalWord(pptr[n]) : LdfAbalByte(pptr[n]) )
#define LdfParaByte(n) ( tptr[n] == 1 ? (LdfAbalWord(pptr[n])&0x00FF) : LdfAbalByte(pptr[n]) )
/* Library Destructor */
EXAWORD LdfBdaTerminate()
{
	if (DynamicLibrary->fin != (VOID (FAR PTR)()) 0)
		 (*DynamicLibrary->fin)();
	return(0);
}

/* Library Call Through */
EXAWORD LdfBdaExecute(
	EXAWORD fid,
	EXAWORD argc,
	BYTE FAR tptr[],
	VOID FAR PTR FAR pptr[],
	EXAWORD FAR wptr[],
	EXAWORD FAR * eptr)
{
	EXAWORD	result=0;
	rt_arg.c=argc; rt_arg.v=pptr;
	rt_arg.l=wptr; rt_arg.t=tptr;
	if ((result=setjmp(rt_error_context))!=0) {
		if ( eptr != (EXAWORD FAR *) 0) *eptr = result;
		return( result );
		}
	/* Version = 1 */
	/* Runtime = "grafabal" */
	/* %g_init() */
	/* %g_assign(#, $, #, #) */
	/* %g_open(#) */
	/* %g_close(#) */
	/* %g_window(#, .) */
	/* %g_viewport(#, .) */
	/* %g_points(#, .) */
	/* %g_lines(#, .) */
	/* %g_circle(#, .) */
	/* %g_arc(#, .) */
	/* %g_point(#, %, %) */
	/* %g_line(#, %, %, %, %) */
	/* %g_paint(#, .) */
	/* %g_atpen(#, #, #, #) */
	/* %g_defpaint(#, .) */
	/* %g_box(#, .) */
	/* %g_pie(#, .) */
	/* %g_display(#, %, %, $, .) */
	/* %g_textpen(#, #, #) */
	/* %g_usefont(#, $, #?) */
	/* %g_freefont(#, #) */
	/* %g_palet(#, .) */
	/* %g_clear(#, .) */
	/* %g_grconf(#, .) */
	/* %g_conf(#, .) */
	/* %g_pread(#, %, %, %?) */
	/* %g_atb(#, .) */
	/* %open_graphic() */
	/* %set_dimension(%, %, .) */
	/* %set_defaultparam() */
	/* %set_charttype(%, %) */
	/* %load_piestate(%, .) */
	/* %load_data(%, .) */
	/* %load_label(%, .) */
	/* %load_legend(%, .) */
	/* %set_maintitle($, .) */
	/* %set_subtitle($, .) */
	/* %set_xytitles($, $, .) */
	/* %set_param(%, .) */
	/* %draw_chart() */
	/* %unload_chart() */
	/* %close_graphic() */
	/* %clear_graphic(#) */
	/* %create_screen(%?, %, .) */
	/* %use_screen(%) */
	/* %load_prndrv($) */
	/* %print_chart(%, %, .) */
	/* %unload_prndrv() */
	/* %delete_screen(%) */
	/* %g_end() */
	if (fid > function_counter) result=138; else result=(*DynamicLibrary->fonction[fid])(pptr);
	/* End */
	return(result);
}

/* Library Constructor */

EXAWORD LdfBdaInitialise(
	BDA_INIT FAR PTR descriptor,
	EXAWORD dlength)
{
	int	i=0;
	rt_init = descriptor;
	function_counter=50;
	if (!(DynamicLibrary = InitRelais()))
		return(139);
	else	return(0);
}

#endif  /* __linbda__home_Dev_abal32_src_grafabal_grafabal_c__ */
/* End of File */