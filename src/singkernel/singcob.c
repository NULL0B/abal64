#ifndef	_singcob_c 
#define	_singcob_c

#include <stdio.h>
#include "sing.h"
#include "palet.h"
#include "stdpsu.h"
#include "guimouse.h"
#include "singrel.h"
#include "singpix.h"
#include "allocate.h"
#define	_SYSTEM_IMAGES
#include "sysimage.h"
#include "stdimage.h"
#include "singlang.h"
#include "singedit.h"
#include "singprod.h"
#include "singpage.h"
#include "singpars.h"

#include "singpal.h"
#include "singbar.h"
#include "singmenu.h"
#include "singtool.h"
#include "singtext.h"
#include "singimg.h"
#include "singdesk.h"
#include "vconf.h"
#include "vcommand.h"
#include "visual.h"
#include "singconf.h"
#include "singabal.h"
#include "singtool.h"
#include "singmeth.h"
#include "abalterm.h"


private void	generate_identification_division(FILE *h)
{
	fprintf(h,"IDENTIFICATION DIVISION.");
	linefeed(h);
	indent(h,1);
	fprintf(h,"PROGRAM-ID.\t%s.",Context.Form->identifier);
	linefeed(h);
	indent(h,1);
	fprintf(h,"AUTHOR.\tIJM");
	linefeed(h);
	indent(h,1);
	fprintf(h,"SECURITY.\tPUBLIC");
	linefeed(h);
	linefeed(h);
	return;
}

private void	generate_environment_division(FILE *h)
{
	fprintf(h,"ENVIRONMENT DIVISION.");
	linefeed(h);
	indent(h,1);
	fprintf(h,"CONFIGURATION SECTION.");
	linefeed(h);
	indent(h,2);
	fprintf(h,"SPECIAL-NAMES.");
	linefeed(h);
	indent(h,3);
	fprintf(h,"CONSOLE IS CRT.");
	linefeed(h);
	linefeed(h);
	indent(h,1);
	fprintf(h,"INPUT-OUTPUT SECTION.");
	linefeed(h);
	indent(h,2);
	fprintf(h,"FILE-CONTROL.");
	linefeed(h);
	return;
}

private void	generate_data_division(FILE *h)
{
	fprintf(h,"DATA DIVISION.");
	linefeed(h);
	linefeed(h);
	indent(h,1);
	fprintf(h,"FILE SECTION.");
	linefeed(h);
	linefeed(h);
	indent(h,1);
	fprintf(h,"WORKING-STORAGE SECTION.");
	linefeed(h);
	linefeed(h);
	
}

private void	generate_procedure_division(FILE *h)
{

	fprintf(h,"PROCEDURE DIVISION.");
	linefeed(h);

	fprintf(h,"DEBUT.");
	linefeed(h);

	indent(h,1);	fprintf(h,"PERFORM ONCREATE.");	linefeed(h);
	indent(h,1);	fprintf(h,"PERFORM ONSHOW.");	linefeed(h);
	indent(h,1);	fprintf(h,"PERFORM ONFOCUS.");	linefeed(h);
	indent(h,1);	fprintf(h,"PERFORM ONHIDE.");	linefeed(h);
	indent(h,1);	fprintf(h,"PERFORM ONREMOVE.");	linefeed(h);
	indent(h,1);	fprintf(h,"STOP RUN.");		linefeed(h);

	fprintf(h,"ONCREATE.");	linefeed(h);
	fprintf(h,"ONSHOW.");	linefeed(h);
	fprintf(h,"ONFOCUS.");	linefeed(h);
	fprintf(h,"ONEVENT.");	linefeed(h);
	fprintf(h,"ONLOSE.");	linefeed(h);
	fprintf(h,"ONHIDE.");	linefeed(h);
	fprintf(h,"ONREMOVE.");	linefeed(h);


	linefeed(h);

	return;
}

private void	generate_cobol_header( FILE * h )
{
	generate_identification_division(h);
	generate_environment_division(h);
	generate_data_division(h);
	generate_procedure_division(h);
	return;
}
public  void	export_cobol_form( FILE * h )
{
	struct form_item * iptr;
	struct form_item * wptr;
	generate_cobol_header(h);

	return;
}

public  void	export_cobol_page( FILE * h )
{
	struct form_item * iptr;
	struct form_item * wptr;
	generate_cobol_header(h);

	return;
}




#endif	/* _singcob_c */

