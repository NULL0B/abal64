#ifndef	_SING_C
#define	_SING_C

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
#include "singpars.h"

#include "singpal.h"
#include "singbar.h"
#include "singmenu.h"
#include "singtool.h"
#include "singtext.h"
#include "singimg.h"
#include "singdesk.h"
#include "singmeth.h"
#include "singmemb.h"

#include "vconf.h"
#include "visual.h"
#include "singconf.h"

extern	char	namebuffer[];
extern	char	workbuffer[];
extern	struct	screen_control	Context;
extern	char *	font_name[];
extern	int	TargetBiosMode;
extern	int	WindowCol;
extern	int	WindowRow;
extern	int	ZeroWindow;	

#define	__QUOTE	0x0022
#define	_STANDARD_RGB	system_palette

#define	_NATURE_PROGRAM	0
#define	_NATURE_OVERLAY	1
#define	_NATURE_MODULE 	2
#define	_NATURE_INCLUDE 3

#include "singmenu.h"

#include "singc.h"
struct	c_configuration C_Config = { 1, 0, 0, (char *) 0, (char *) 0, (char *) 0,0,0,0};

extern	int	FixedWindows;
extern	int	SignatureItems;
extern	char	Signature[512];
char *	language_prefix(int);
/*	------------------------------------------	*/
/*	C Language Widget Method Generation Tokens 	*/
/*	------------------------------------------	*/
private	char * __visual_natlang="visual_national_language";
private	char * __c_mouse_type  ="visual_event(1)";
private	char * __c_mouse_button="visual_event(2)";
private	char * __c_mouse_column="visual_event(7)";
private	char * __c_mouse_row   ="visual_event(6)";
private	char * __c_get_event   ="visual_getch";
private	char * __c_put_error   ="visual_error";
private	char * __c_test_event  ="visual_kbhit()";
private	char * __c_visual_event="visual_event";
private	char * __c_page_number ="page_number";
private	char * __c_focus_item  ="focus_item";
private	char * __c_keycode     ="keycode";
private	char * __c_status      ="status";
private	char * __c_stdinput    ="stdinput";

private	char * 	keyword_private		="private";
private	char * 	keyword_public 		="public";
private	char * 	__c_instance_prefix	="_Context";
private	char * 	__c_instance_suffix	="_context";
private	char *	__method_create		="create";
private	char *	__method_show		="show";
private	char *	__method_getfocus	="getfocus";
private	char *	__method_focus		="focus";
private	char *	__method_event		="event";
private	char *	__method_action		="action";
private	char *	__method_losefocus	="losefocus";
private	char *	__method_hide		="hide";
private	char *	__method_remove		="remove";

public	int	c_onshow_widget(FILE * h, struct form_item * iptr, int margin, int focus );
private	void	generate_c_show(FILE * handle, struct form_item * iptr, int margin );
private	void	activate_c_method( FILE * h,char * mptr, char* nptr, char * eptr, int type, int margin );
public  void	c_call( FILE * h, char * cname, char * fname, int members, int level, char * genret );
public  void	generate_c_event_flush( FILE * h );
private	void	generate_trigger( FILE * h, struct form_item * iptr, int margin );
public	struct	form_item * locate_widget( char * nptr,struct form_control * fptr );
public	char *	c_payload( struct form_item * iptr );
private	int	inline_c_method( FILE * h,char * mptr, char* nptr, char * eptr, int type, int margin );
public	void	c_special_method( FILE * h, struct  forms_method * mptr, int i );
private	void	generate_trigger_code( FILE * h, struct form_item * iptr, int margin );
private	void	c_switch_widget(FILE * handle, struct form_item * iptr, int margin,int etat );
private	void	c_check_widget(FILE * handle, struct form_item * iptr, int margin,int etat );
private	void	c_button_widget(FILE * handle, struct form_item * iptr, int margin,int etat );
private	void	generate_c_trigger( FILE * h, struct form_item * iptr, int margin );


#include "singcsyn.c"
#include "singclin.c"

extern	struct line_parser LineParser;

private	void	c_instance_position_control( FILE * h, struct form_item * iptr )
{
	char	pbuffer[256];
	/* Generate Position and Dimensions Variables */
	fprintf(h,"\tint\tx_%s;",iptr->Contents.name);
	linefeed(h);
	fprintf(h,"\tint\ty_%s;",iptr->Contents.name);
	linefeed(h);
	fprintf(h,"\tint\tw_%s;",iptr->Contents.name);
	linefeed(h);
	fprintf(h,"\tint\th_%s;",iptr->Contents.name);
	linefeed(h);
	if (!( FixedWindows )) {
		if (( iptr->Contents.style & _FRAME_TYPE ) == _WINDOW_FRAME) {
			sprintf(pbuffer,"x_%s",iptr->Contents.name);
			set_zero_window_column( pbuffer, iptr->Contents.x );	
			sprintf(pbuffer,"y_%s",iptr->Contents.name);
			set_zero_window_line( pbuffer,iptr->Contents.y );	
			}
		}
	return;
}

private	void	c_method_instance_class( FILE * h )
{
	struct	form_control	*	fptr;
	if (!( fptr = Context.Form))
		return;
	else	{
		fprintf(h,"struct %s%s", fptr->identifier,__c_instance_suffix);
		return;
		}
}

private	void	c_method_instance_this( FILE * h )
{
	c_method_instance_class(h);
	fprintf(h," * %s",__c_instance_prefix);
	return;
}

private	void	c_standard_input( FILE * h, struct form_control * fptr)
{
	linefeed(h);
	fprintf(h,"static int %s(",__c_stdinput);
	c_method_instance_this(h);
	fprintf(h,")");
	linefeed(h);
	fprintf(h,"{");
	linefeed(h);
	indent(h,1);
	fprintf(h,"int tempfocus=0;");
	linefeed(h);
	indent(h,1);
	fprintf(h,"while(1) {");
	linefeed(h);
		indent(h,2);
		fprintf(h,"switch ((%s->%s=%s())) {",
			__c_instance_prefix,__c_keycode,__c_get_event);
		linefeed(h);
			indent(h,3);
			fprintf(h,"case 256 :");
			linefeed(h);
				indent(h,4);
				fprintf(h,"if ( %s == _MIMO_MOVE ) {",__c_mouse_type);
				linefeed(h);
					indent(h,5);
					fprintf(h,"if ((tempfocus = %s_event(%s)) == -1) continue;",C_Config.cname,__c_instance_prefix);
					linefeed(h);
					indent(h,5);
					fprintf(h,"if (tempfocus == %s->%s ) continue;",__c_instance_prefix,__c_focus_item);
					linefeed(h);
					indent(h,5);
					fprintf(h,"}");
					linefeed(h);
			indent(h,3);
			fprintf(h,"default  :");
			linefeed(h);

				indent(h,4);
				fprintf(h,"return(%s->%s);",__c_instance_prefix,__c_keycode);
				linefeed(h);

			indent(h,3);
			fprintf(h,"}");
			linefeed(h);
		indent(h,2);
		fprintf(h,"}");
		linefeed(h);
	indent(h,1);
	fprintf(h,"return(-1);");
	linefeed(h);
	fprintf(h,"}");
	linefeed(h);
	linefeed(h);
	return;
}

public	void	c_forms_method_prototype(FILE * h, struct forms_method * mptr, struct form_control * fptr)
{
	if (!( mptr->type & _METHOD_PUBLIC ))
		fprintf(h,"static ");

	switch (( mptr->type & _METHOD_TYPE) ) {
		case	_METHOD_VOID	:	fprintf(h,"void\t"); break;
		case	_METHOD_BYTE 	:	fprintf(h,"char\t"); break;
		case	_METHOD_WORD 	:	fprintf(h,"short\t"); break;
		case	_METHOD_NUMERIC :	fprintf(h,"float\t"); break;
		case	_METHOD_CLASS	:	fprintf(h,"struct %s ",mptr->klass); break;
		case	_METHOD_STRING	:	fprintf(h,"char *\t" ); break;
		case	_METHOD_LONG    :	fprintf(h,"long\t" ); break;
		}
	if ( mptr->type & _METHOD_POINTER )
		fprintf(h," * ");

	/* If not an explicite Overlay or Module */
	/* ------------------------------------- */
	if ((!( C_Config.generate_overlay )) || (!( mptr->type & _METHOD_PUBLIC )))
		fprintf(h,"%s(",mptr->name);
	else	fprintf(h,"%s_%s(",fptr->identifier,mptr->name);

	c_method_instance_this(h);

	if (!( method_is_valid(mptr->signature )))
		fprintf(h,")");
	else 	fprintf(h,",%s)",mptr->signature);
	return;
}

private	void	c_sort_method_forward( FILE * h )
{
	struct form_item * iptr;
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ((iptr->Contents.style & _FRAME_TYPE) == _FORM_FRAME)
			{
			fprintf(h,"%s int  sort_item_%s(",keyword_private,iptr->Contents.name);
			c_method_instance_this(h);
			fprintf(h,",int nelts);	/* returns resolved sort item */");
			linefeed(h);
			fprintf(h,"%s void start_sort_%s(",keyword_private,iptr->Contents.name);
			c_method_instance_this(h);
			fprintf(h,",int nelts);	/* allocate intermediate sort table */");
			linefeed(h);
			fprintf(h,"%s void sort_%s(",keyword_private,iptr->Contents.name);
			c_method_instance_this(h);
			fprintf(h,",int nelts);	/* sort the intermediate table into %s->tabsort_%s */",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			fprintf(h,"%s int compare_%s(",keyword_private,iptr->Contents.name);
			c_method_instance_this(h);
			fprintf(h,",int a,int b);	/* compare the elements a et b of %s->libsort_%s */",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			};
		}

	return;
}

private	void	c_sort_methods( FILE * h )
{
	struct form_item * iptr;
	char *tptr;
	char *rptr;
	char mon_code[256];
	char comment[256];
	int linelength, nblines,i,fields,posit;
	int	fieldwidth[_MAX_FORM_FIELDS];

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ((iptr->Contents.style & _FRAME_TYPE) == _FORM_FRAME)
			{
			fprintf(h,"/* ------------------- */");
			linefeed(h);
			fprintf(h,"/* resolve sorted item */");
			linefeed(h);
			fprintf(h,"/* ------------------- */");
			linefeed(h);
			fprintf(h,"%s int  sort_item_%s(",keyword_private,iptr->Contents.name);
			c_method_instance_this(h);
			fprintf(h,",int nelt)	/* returns resolved sort item */");
			linefeed(h);
			fprintf(h,"{");
			linefeed(h);
			fprintf(h,"\tif (!( nelt )) { return(nelt); }");
			linefeed(h);
			fprintf(h,"\telse {");
			linefeed(h);
			fprintf(h,"\t\treturn( %s->tabsort_%s[(nelt-1)] );",
				__c_instance_prefix,
				iptr->Contents.name);
			linefeed(h);
			fprintf(h,"\t}");
			linefeed(h);
			fprintf(h,"}");
			linefeed(h);
			linefeed(h);
			fprintf(h,"/* ------------------------------------- */");
			linefeed(h);
			fprintf(h,"/* allocate the intermediate sort table  */");
			linefeed(h);
			fprintf(h,"/* ------------------------------------- */");
			linefeed(h);
			fprintf(h,"%s void start_sort_%s(",keyword_private,iptr->Contents.name);
			c_method_instance_this(h);
			fprintf(h,",int nelts)");
			linefeed(h);
			fprintf(h,"{");
			linefeed(h);

			fprintf(h,"if (%s->nelt_%s<nelts) {",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			indent(h,1);
			fprintf(h,"liberate(%s->tabsort_%s);",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			indent(h,1);
			fprintf(h,"if ((%s->tabsort_%s=allocate(nelts*sizeof(int))) == NULL) return;",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);				
			indent(h,1);
			fprintf(h,"for (%s->nelt_%s=0;%s->nelt_%s<nelts;%s->nelt_%s++)",
					__c_instance_prefix,iptr->Contents.name,
					__c_instance_prefix,iptr->Contents.name,
					__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			indent(h,2);
			fprintf(h,"{ %s->tabsort_%s[%s->nelt_%s]=%s->nelt_%s+1; };	/* initialisation tableau sans tri */",
					__c_instance_prefix,iptr->Contents.name,
					__c_instance_prefix,iptr->Contents.name,
					__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			indent(h,1);
			fprintf(h,"};");
			linefeed(h);

			fprintf(h,"if ((%s->indsort_%s=allocate(nelts*sizeof(char))) == NULL) return;",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);

			calculate_edit_size( &iptr->Contents );
			calculate_form_lines( iptr, &linelength, &nblines );
			fprintf(h,"if ((%s->libsort_%s=allocate(nelts*%u)) != NULL)"
				,__c_instance_prefix,iptr->Contents.name,linelength);
			linefeed(h);
			indent(h,1);
			fprintf(h,"memset(%s->libsort_%s,' ',nelts*%u);"
				,__c_instance_prefix,iptr->Contents.name,linelength);
			linefeed(h);

			fprintf(h,"}");
			linefeed(h);	linefeed(h);

						/* fonction de tri */
			sprintf(comment,"sort the intermediate table into %s->tabsort_%s",__c_instance_prefix,iptr->Contents.name);
			memset(mon_code,'-',strlen(comment));
			mon_code[strlen(comment)]=0;
			fprintf(h,"/* %s */",mon_code);
			linefeed(h);
			fprintf(h,"/* %s */",comment);
			linefeed(h);
			fprintf(h,"/* %s */",mon_code);
			linefeed(h);		

			fprintf(h,"%s void sort_%s(",keyword_private,iptr->Contents.name);
			c_method_instance_this(h);
			fprintf(h,",int nelts)");
			linefeed(h);
			fprintf(h,"{");
			linefeed(h);
			fprintf(h,"int\ti,j,k;");
			linefeed(h);

			fprintf(h,"memset(%s->indsort_%s,0,nelts);",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);		linefeed(h);

			fprintf(h,"for (i=0;i<nelts;i++) {");
			linefeed(h);

			indent(h,1);
			fprintf(h,"for (k=0;(k<nelts) && (%s->indsort_%s[k]);k++);",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);

			indent(h,1);
			fprintf(h,"if (k<nelts-1) {");
			linefeed(h);

			indent(h,2);
			fprintf(h,"for (j=k+1;j<nelts;j++) {");
			linefeed(h);

			indent(h,3);
			fprintf(h,"if ((!%s->indsort_%s[j]) && (compare_%s(%s,j,k)<0)) k=j;",__c_instance_prefix,iptr->Contents.name,iptr->Contents.name,__c_instance_prefix);
			linefeed(h);

			indent(h,3);
			fprintf(h,"};	/* for j */");
			linefeed(h);
			indent(h,2);
			fprintf(h,"};	/* if k<nbelt-1 */");
			linefeed(h);
			indent(h,1);
			fprintf(h,"%s->tabsort_%s[i]=k+1;",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			indent(h,1);
			fprintf(h,"%s->indsort_%s[k]=1;",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			indent(h,1);
			fprintf(h,"};	/* for i */");
			linefeed(h);
			fprintf(h,"liberate(%s->libsort_%s);",__c_instance_prefix,iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			fprintf(h,"liberate(%s->indsort_%s);",__c_instance_prefix,iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			fprintf(h,"}");
			linefeed(h);	linefeed(h);


				/* fonction de comparaison entre deux elements */
			sprintf(comment,"compare the elements a et b of %s->libsort_%s",__c_instance_prefix,iptr->Contents.name);
			memset(mon_code,'-',strlen(comment));
			mon_code[strlen(comment)]=0;
			fprintf(h,"/* %s */",mon_code);
			linefeed(h);
			fprintf(h,"/* %s */",comment);
			linefeed(h);
			fprintf(h,"/* %s */",mon_code);
			linefeed(h);
			
			fprintf(h,"%s int compare_%s(",keyword_private,iptr->Contents.name);
			c_method_instance_this(h);
			fprintf(h,",int a,int b) {");
			linefeed(h);

			fprintf(h,"int i,j;");
			linefeed(h); linefeed(h);

			if (( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
				{
				if ((tptr = abal_payload(iptr)) != NULL)
					{
					memset(comment,0,256);
					strcpy(comment,tptr);
					tptr=comment;
					while ((rptr =strchr(tptr,'|')) != (char *) 0)
						{
						*rptr=0;
						tptr+=strlen(tptr)+1;
						};
					};
				tptr=comment;

				fprintf(h,"i=memicmp(&%s->libsort_%s[%d*a],&%s->libsort_%s[%d*b],%d);	/* comparaison zone 1 */",
						__c_instance_prefix,iptr->Contents.name,linelength,
						__c_instance_prefix,iptr->Contents.name,linelength,fieldwidth[0]);
				posit=0;
				
				linefeed(h);
				fprintf(h,"switch (%s->formsort_%s) {",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);

				for (i=0;i<fields;i++)
					{
					indent(h,1);
					fprintf(h,"case %d:	/* %s ordre normal */",i+1,tptr);
					linefeed(h);
					indent(h,2);
					if (i)
						{
						fprintf(h,"j=memicmp(&%s->libsort_%s[%d*a+%d],&%s->libsort_%s[%d*b+%d],%d);",
							__c_instance_prefix,iptr->Contents.name,linelength,posit,
							__c_instance_prefix,iptr->Contents.name,linelength,posit,fieldwidth[i]);
						linefeed(h);
						indent(h,2);
						fprintf(h,"if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */");
						linefeed(h);
						indent(h,2);
						fprintf(h,"return(j);");
						}
					else
						fprintf(h,"return(i);");
					linefeed(h);	linefeed(h);
					indent(h,1);
					fprintf(h,"case -%d:	/* %s ordre inverse */",i+1,tptr);
					linefeed(h);
					indent(h,2);
					if (i)
						{
						fprintf(h,"j=memicmp(&%s->libsort_%s[%d*b+%d],&%s->libsort_%s[%d*a+%d],%d);",
							__c_instance_prefix,iptr->Contents.name,linelength,posit,
							__c_instance_prefix,iptr->Contents.name,linelength,posit,fieldwidth[i]);
						linefeed(h);
						indent(h,2);
						fprintf(h,"if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */");
						linefeed(h);
						indent(h,2);
						fprintf(h,"return(j);");
						}
					else
						fprintf(h,"return(-i);");

					linefeed(h);
					if (i<fields-1) linefeed(h);
					posit+=fieldwidth[i];
					tptr+=strlen(tptr)+1;
					};
	
				indent(h,1);
				fprintf(h,"default:		/* pas de tri */");
				linefeed(h);
				indent(h,2);
				fprintf(h,"if (a<b) return(-1);");
				linefeed(h);
				indent(h,2);
				fprintf(h,"return(1);");
				linefeed(h);
				indent(h,1);
				fprintf(h,"}; /* fin du switch */");
				linefeed(h);
				};
			//c_method_body(h, mon_code, strlen(mon_code), iptr->Contents.name, 1 );
			fprintf(h,"}");
			linefeed(h);	linefeed(h);
			};
		}

	return;
}

public	void	c_forms_method_forward(FILE * h, struct form_control * fptr, int callmode )
{
	struct	forms_method 	* mptr;
	char			* optr;
	if (!( fptr ))	return;
	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if (!( mptr->type & _METHOD_FUNCTION ))
			continue;
		else	{
			if ((!( C_Config.generate_program ))  && ( C_Config.generate_overlay )) {
				if (( callmode ) && (!( mptr->type & _METHOD_PUBLIC ))) {
					/* private method in for C source prototype */
					/* ---------------------------------------- */
					c_forms_method_prototype(h,mptr,fptr);
					fprintf(h,";");
					linefeed(h);
					}
				else if ((!( callmode )) && ( mptr->type & _METHOD_PUBLIC )) {
					/* public  method in for C header prototype */
					/* ---------------------------------------- */
					c_forms_method_prototype(h,mptr,fptr);
					fprintf(h,";");
					linefeed(h);
					}
				}
			else	{
				/* not a modular packaging so ok no check */
				/* -------------------------------------- */
				c_forms_method_prototype(h,mptr,fptr);
				fprintf(h,";");
				linefeed(h);
				}
			}
		}
	return;

}

private	int	c_method_body( FILE * h, char * eptr, int l, char * hptr, int margin )
{
	int	i;
	int	c;
	char *	lptr;
	int	status=0;
	int	feeder=0;
	while ( *eptr != 0 ) {
		/* avoid empty lines */
		feeder=0;
		if (( *eptr == '\n' ) 
		||  ( *eptr == '\r' )) {
			eptr++;
			continue;
			}
		else	{
			/* scan till end of line or zero */
			/* ----------------------------- */
			for (	i=0,lptr = eptr;
				*eptr != 0;
				eptr++ ) {
				if (( *eptr == '\n' ) 
				||  ( *eptr == '\r' ))
					break;
				else	i++;
				}
			c = *eptr;
			*eptr = 0;
			indent(h,margin);
			status = c_method_line(h,lptr,i,hptr,&feeder);
			*eptr = c;
			if ( feeder ) linefeed(h);
			if ( status ) break;
			}
		}
	return(status);
}

public	void	raw_method_body( FILE * h, char * eptr, int l, char * hptr )
{
	int	s;
	int	n;
	int	i;
	do	{
		if ((n = l) > EDITOR_COLUMNS)
			n = EDITOR_COLUMNS;
		if (!( *eptr ))
			break;
		s = n;
		if (!( *eptr ))
			break;
		indent(h,1);
		for (i=0; i < n; i++ ) {
			if (!( *eptr )) 
				break;
			else	fprintf(h,"%c",*(eptr++));
			}
		linefeed(h);
		l -= n;
		}
	while ( l > 0 );
	return;
}

public	void	c_forms_method_header(FILE * h, char * name )
{
	int	c;
	char *	nptr;

	linefeed(h);
	fprintf(h,"/*\t");
	nptr = name;
	while ((c = *(nptr++)) != 0)
		fprintf(h,"--");
	fprintf(h,"--\t*/");
	linefeed(h);
	fprintf(h,"/*\t");
	nptr = name;
	while ((c = *(nptr++)) != 0)
		fprintf(h,"%c ",c);
	fprintf(h,"()\t*/");
	linefeed(h);
	fprintf(h,"/*\t");
	nptr = name;
	while ((c = *(nptr++)) != 0)
		fprintf(h,"--");
	fprintf(h,"--\t*/");
	linefeed(h);
	return;
}

		
public	void	c_forms_methods(FILE * h, struct form_control * fptr)
{
	struct	forms_method 	* mptr;
	char			* optr;
	int			  l;
	int			  status;
	if (!( fptr ))	return;
	if ( C_Config.newstdin ==2 ) {
		c_standard_input(h,fptr);
		}
	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if (!( mptr->type & _METHOD_FUNCTION ))
			continue;
		else	{
			c_forms_method_header(h,mptr->name);
			c_forms_method_prototype(h,mptr,fptr);
			fprintf(h,"{");
			linefeed(h);
			if (( l=method_is_valid(mptr->text)) > 0 ) {
				status = c_method_body( h, mptr->text, l, mptr->name, 1 );
				}		
			linefeed(h);
			fprintf(h,"}");
			linefeed(h);
			}
		}
	return;

}
private	void	c_banner(FILE * h, char * token )
{
	int	tokenlen;
	int	i;
	if (!( token ))
		return;
	else if (!( tokenlen =strlen( token ) ))
		return;
	else	tokenlen *= 2;

	fprintf(h,"\r\n/*\t");
	for (i=0; i < tokenlen; i++ )
		fprintf(h,"-");
	fprintf(h,"\t*/");

	fprintf(h,"\r\n/*\t");
	while ( *token )
		fprintf(h,"%c ",*(token++));

	fprintf(h,"\t*/");

	fprintf(h,"\r\n/*\t");
	for (i=0; i < tokenlen; i++ )
		fprintf(h,"-");
	fprintf(h,"\t*/\r\n");
	return;
}

public	int	method_is_valid( char * eptr )
{
	if (!( eptr ))		return(0);
	else if (!( *eptr ))	return(0);
	else 			return( strlen(eptr) );
}

private	int	c_prototype( 
	FILE * h,
	char * mptr, 
	char * nptr, 
	char * eptr )
{
	int	l;
	int	status=0;
	if (!( eptr ))
		return(0);
	else if (( l=strlen(eptr)) > 0 ) {
		fprintf(h,"%s int on_%s_%s(",keyword_private,mptr,nptr);
		c_method_instance_this(h); fprintf(h,");");
		linefeed(h);
		}		
	return(status);
}

private	int	c_method( 
	FILE * h,
	char * mptr, 
	char * nptr, 
	char * eptr )
{
	int	l;
	int	status=0;
	if (!( eptr ))
		return(0);
	else if (( l=strlen(eptr)) > 0 ) {
		fprintf(h,"%s int on_%s_%s(",keyword_private,mptr,nptr);
		c_method_instance_this(h); fprintf(h,") {");
		linefeed(h);
		status = c_method_body( h, eptr, l, mptr, 1 );
		c_return(h,"-1",1);
		fprintf(h,"}");
		linefeed(h);
		}		
	return(status);
}

private	int	open_c_page(FILE * h,struct form_item * iptr, int i)
{
	int	pn=0;

	if ((iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME)  {
		pn = iptr->Contents.page;
		}

	else if (!( C_Config.page_control ))
		return(0);

	else if (!(pn = iptr->Contents.page ))
		return(0);

	if ( i ) indent(h,i);
	fprintf(h,"if (%s->%s == %u ) {",__c_instance_prefix,__c_page_number,pn);
	linefeed(h);
	return(pn);
}

public	void	close_c_page(FILE * h,int pn,int i)
{
	if ( pn != 0 ) {
		indent(h,i+1);
		fprintf(h,"}");
		linefeed(h);
		}
	return;
}

private	void	c_conditional_show(FILE * handle, struct form_item * iptr, int mode )
{
	char *	tptr;
	int	pn=0;
	int	status=0;

	if ((status = is_named_conditional( iptr )) != 0) {

		if (!( mode )) {
			c_comment(handle,iptr->Contents.name,1);
			return;
			}
		else	{
			fprintf(handle,"void %s_onshow() {",iptr->Contents.name);
			linefeed(handle);
			pn = open_c_page( handle, iptr,1 );
			}	
		}

	/* End of the line */
	/* --------------- */
	else if ( mode ) return;

	generate_c_show(handle,iptr,(pn ? 2 : 1 ));

	if ( status ) {
		close_c_page( handle, pn,1 );
		indent(handle,1);
		fprintf(handle,"return;");
		linefeed(handle);
		fprintf(handle,"}");
		linefeed(handle);
		}
	return;

}

public	void	c_widget_viewport(FILE * h, struct form_item * iptr )
{
	switch ((iptr->Contents.style & _FRAME_TYPE)) {

		case	_EDIT_FRAME	:

			fprintf(h,"%s->%s=%s(%s+1,%s+1,%s,%s",
				__c_instance_prefix,"status",__visual_viewport,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0));
			font_parameter(h,iptr);
			fprintf(h,")");
			break;

		case	_OUTSET_FRAME	:
		case	_INSET_FRAME	:
			fprintf(h,"%s->%s=%s(%s+1,%s+1,%s-2,%s-2",
				__c_instance_prefix,"status",__visual_viewport,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0));
			font_parameter(h,iptr);
			fprintf(h,")");

			break;

		case	_RIDGE_FRAME	:
		case	_GROOVE_FRAME	:
			fprintf(h,"%s->%s=%s(%s+2,%s+2,%s-4,%s-4",
				__c_instance_prefix,"status",__visual_viewport,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0));
			font_parameter(h,iptr);
			fprintf(h,")");
			break;

		default			:
			fprintf(h,"%s->%s=%s(%s,%s,%s,%s",
				__c_instance_prefix,"status",__visual_viewport,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0));
			font_parameter(h,iptr);
			fprintf(h,")");

		}
	return;
}

private	void	c_widget_mouse_event(FILE * handle, struct form_item * iptr, int margin )
{
	int	xfi=0;
	int	f=0;
	int	fields=0;
	int	fieldwidth[_MAX_FORM_FIELDS];
	int	linelength=0;
	int	nblines=0;
	int	fw;
	int	fh;

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;	

	indent(handle,margin);
	fprintf(handle,"if ((%s->value_%s = ((%s - (%s)) / %u)) < 1)",
		__c_instance_prefix,iptr->Contents.name,
		__c_mouse_row, widget_y_position(iptr,0), fh );
	linefeed(handle);
	indent(handle,margin+1);
	fprintf(handle,"%s->value_%s=0;",__c_instance_prefix,iptr->Contents.name);
	linefeed(handle);
	fprintf(handle,"else if (%s->value_%s > %u )",
		__c_instance_prefix,iptr->Contents.name,nblines);
	linefeed(handle);
	indent(handle,margin+1);
	fprintf(handle,"%s->value_%s=%u;",__c_instance_prefix,iptr->Contents.name,nblines);
	linefeed(handle);

	indent(handle,margin);
	fprintf(handle,"if ( %s->value_%s > 0 ) { %s->row_%s = &%s->buffer_%s[(%s->value_%s-1)][0]; } ",
			__c_instance_prefix, iptr->Contents.name,
			__c_instance_prefix, iptr->Contents.name,
			__c_instance_prefix, iptr->Contents.name,
			__c_instance_prefix, iptr->Contents.name);
	linefeed(handle);
	indent(handle,margin);
	fprintf(handle,"%s->column_%s = (%s - (%s));",
		__c_instance_prefix,iptr->Contents.name,
		__c_mouse_column, widget_x_position(iptr,0));
	linefeed(handle);
	for (	f=0,xfi=0;
		f<fields;
		f++ ) {
		xfi += (fieldwidth[f]*fw);
		indent(handle,margin);
		if (!( f ))
			fprintf(handle,"if");
		else	fprintf(handle,"else if");
		fprintf(handle," ( %s->column_%s < %u ) {",
				__c_instance_prefix,iptr->Contents.name,xfi);
		linefeed(handle);
		indent(handle,margin+1);
		fprintf(handle,"%s->column_%s = %u;",
				__c_instance_prefix,iptr->Contents.name,f+1);
		linefeed(handle);
		indent(handle,margin+1);
		fprintf(handle,"}");
		linefeed(handle);
		}
	indent(handle,margin);
	fprintf(handle,"if ((!(%s->value_%s)) && (%s==_MIMO_DOWN)) {	/* si clic sur titre */",
		__c_instance_prefix,iptr->Contents.name,__c_mouse_type);
	linefeed(handle);
	indent(handle,margin+1);
	fprintf(handle,"if (%s->formsort_%s==%s->column_%s) /* si colonne choisie concerne déjà le tri */",
		__c_instance_prefix,iptr->Contents.name,
		__c_instance_prefix,iptr->Contents.name);
	linefeed(handle);
	indent(handle,margin+2);
	fprintf(handle,"%s->formsort_%s=-%s->column_%s;	/* alors tri décroissant */",
		__c_instance_prefix,iptr->Contents.name,
		__c_instance_prefix,iptr->Contents.name);
	linefeed(handle);
	indent(handle,margin+1);
	fprintf(handle,"else");
	linefeed(handle);
	indent(handle,margin+2);
	fprintf(handle,"%s->formsort_%s=%s->column_%s; };	/* sinon tri croissant */",
		__c_instance_prefix,iptr->Contents.name,
		__c_instance_prefix,iptr->Contents.name);
	linefeed(handle);
	return;
}

public	char *	c_hint( struct form_item * iptr )
{
	struct 	form_control * fptr;
	if (!( fptr = iptr->parent ))
		return( iptr->Contents.hint );
	else if (!( fptr->formflags & _INTERNATIONAL ))
		return( iptr->Contents.hint );
	else	return( iptr->Contents.hmessages[fptr->natlang] );
}

public	char *	c_payload( struct form_item * iptr )
{
	struct 	form_control * fptr;
	if (!( fptr = iptr->parent ))
		return( iptr->Contents.payload );
	else if (!( fptr->formflags & _INTERNATIONAL ))
		return( iptr->Contents.payload );
	else	return( iptr->Contents.messages[fptr->natlang] );
}

public	void	c_payload_value(FILE * h, struct form_item * iptr)
{
	char		*	sptr;
	struct 	form_control * fptr;
	if (!( fptr = iptr->parent ))
		string_value(h,iptr->Contents.payload);
	else if (!( fptr->formflags & _INTERNATIONAL ))
		string_value(h,iptr->Contents.payload);
	else if (!( fptr->formflags & _MULTILINGUAL  ))
		string_value(h,iptr->Contents.messages[fptr->natlang]);
	else if (!( sptr = c_payload(iptr) ))
		string_value(h,iptr->Contents.messages[fptr->natlang]);
	else if ( *sptr == _UNQUOTED_STRING )
		string_value(h,iptr->Contents.messages[fptr->natlang]);
	else if (( iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME ) {
		fprintf(h,"%s->msg%u_%s[%s->language]",
			__c_instance_prefix,iptr->Contents.radio,iptr->Contents.name,__c_instance_prefix);
		}
	else	{
		fprintf(h,"%s->msg_%s[%s->language]",__c_instance_prefix,iptr->Contents.name,__c_instance_prefix);
		}
	return;
}

public	void	c_hint_value(FILE * h, struct form_item * iptr)
{
	char		*	sptr;
	struct 	form_control * fptr;
	if (!( fptr = iptr->parent ))
		string_value(h,iptr->Contents.hint);
	else if (!( fptr->formflags & _INTERNATIONAL ))
		string_value(h,iptr->Contents.hint);
	else if (!( fptr->formflags & _MULTILINGUAL  ))
		string_value(h,iptr->Contents.hmessages[fptr->natlang]);
	else if (!( sptr = c_hint(iptr) ))
		string_value(h,iptr->Contents.hmessages[fptr->natlang]);
	else if ( *sptr == _UNQUOTED_STRING )
		string_value(h,iptr->Contents.hmessages[fptr->natlang]);
	else if (( iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME ) {
		fprintf(h,"%s->hint%u_%s[%s->language]",
			__c_instance_prefix,iptr->Contents.radio,iptr->Contents.name,__c_instance_prefix);
		}
	else	{
		fprintf(h,"%s->hint_%s[%s->language]",__c_instance_prefix,iptr->Contents.name,__c_instance_prefix);
		}
	return;
}

public	void	c_payload_parameter(FILE * h, struct form_item * iptr)
{
#ifdef	_OLD_PAYLOAD_HANDLER
	struct 	form_control * fptr;
	if (!( fptr = iptr->parent ))
		string_parameter(h,iptr->Contents.payload);
	else if (!( fptr->formflags & _INTERNATIONAL ))
		string_parameter(h,iptr->Contents.payload);
	else	string_parameter(h,iptr->Contents.messages[fptr->natlang]);
#else
	fprintf(h,",");
	c_payload_value(h,iptr);
#endif
	return;
}

private	void	c_hint_parameter(FILE * h, struct form_item * iptr)
{
#ifdef	_OLD_PAYLOAD_HANDLER
	struct 	form_control * fptr;
	if (!( fptr = iptr->parent ))
		string_parameter(h,iptr->Contents.hint);
	else if (!( fptr->formflags & _INTERNATIONAL ))
		string_parameter(h,iptr->Contents.hint);
	else	string_parameter(h,iptr->Contents.hmessages[fptr->natlang]);
#else
	fprintf(h,",");
	c_hint_value(h,iptr);
#endif
	return;
}

public	void	c_payload_filename_parameter(FILE * h, struct form_item * iptr)
{
	struct 	form_control * fptr;
#ifdef	_OLD_PAYLOAD_HANDLER
	if (!( fptr = iptr->parent ))
		filename_parameter(h,iptr->Contents.payload);
	else if (!( fptr->formflags & _INTERNATIONAL ))
		filename_parameter(h,iptr->Contents.payload);
	else	filename_parameter(h,iptr->Contents.messages[fptr->natlang]);
#else
	c_payload_parameter(h,iptr);
#endif
	return;
}

private	void	c_hint_method(FILE * h, struct form_item * iptr, int margin )
{
	char *	optr;
	char *	sptr;
	if (!( iptr ))
		return;
	else if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
		return;
	else if (!( iptr->parent ))
		return;
	else if (!( iptr->parent->OnHint ))
		return;
	else if (!( method_is_valid((sptr = c_hint(iptr) )) ))
		return;
	else	{
		indent(h,margin);
		fprintf(h,"%s(%s,",_METHOD_ONHINT,__c_instance_prefix);
		c_hint_value(h,iptr );
		fprintf(h,");");
		linefeed(h);
		return;
		}
}

private	void	c_hint_filename_parameter(FILE * h, struct form_item * iptr)
{
	struct 	form_control * fptr;
#ifdef	_OLD_PAYLOAD_HANDLER
	if (!( fptr = iptr->parent ))
		filename_parameter(h,iptr->Contents.hint);
	else if (!( fptr->formflags & _INTERNATIONAL ))
		filename_parameter(h,iptr->Contents.hint);
	else	filename_parameter(h,iptr->Contents.hmessages[fptr->natlang]);
#else
	c_payload_parameter(h,iptr);
#endif
	return;
}

public	void	c_payload_length_parameter(FILE * h, struct form_item * iptr)
{
#ifdef	_OLD_PAYLOAD_HANDLER
	struct 	form_control * fptr;
	char	*	sptr;
	if (!( fptr = iptr->parent ))
		string_length_parameter(h,iptr);
	else if (!( fptr->formflags & _INTERNATIONAL ))
		string_length_parameter(h,iptr);
	else if (!(sptr = iptr->Contents.messages[fptr->natlang]))
		length_parameter(h, iptr->Contents.size );
	else if ( *sptr != _UNQUOTED_STRING )
		length_parameter(h, strlen(sptr) );
	else 	generic_length_parameter(h,(sptr+1));
#else
	fprintf(h,",strlen(");
	c_payload_value(h,iptr);
	fprintf(h,")");
#endif
	return;
}


private	void	c_hint_length_parameter(FILE * h, struct form_item * iptr)
{
#ifdef	_OLD_PAYLOAD_HANDLER
	struct 	form_control * fptr;
	char	*	sptr;
	if (!( fptr = iptr->parent ))
		string_length_parameter(h,iptr);
	else if (!( fptr->formflags & _INTERNATIONAL ))
		string_length_parameter(h,iptr);
	else if (!(sptr = iptr->Contents.hmessages[fptr->natlang]))
		length_parameter(h, iptr->Contents.size );
	else if ( *sptr != _UNQUOTED_STRING )
		length_parameter(h, strlen(sptr) );
	else 	generic_length_parameter(h,(sptr+1));
#else
	fprintf(h,",strlen(");
	c_hint_value(h,iptr);
	fprintf(h,")");
#endif
	return;
}


private	void	c_trigger_parameter( FILE * h, struct form_item * iptr )
{
	c_payload_parameter(h,iptr);
	c_payload_length_parameter(h,iptr);
	return;
}

public	void	c_initialise_national_language(FILE * h, struct form_control * fptr, int mode)
{
	if ( fptr->formflags & _MULTILINGUAL ) {
		if (( C_Config.generate_program )
		&&  ( mode )) {
			if (!( C_Config.generate_overlay )) {
				indent(h,1);
				fprintf(h,"%s->language=%u;",__c_instance_prefix,fptr->natlang);
				linefeed(h);
				indent(h,1);
				fprintf(h,"(void) %s(%s->language);",
					__visual_natlang,
					__c_instance_prefix,__c_instance_prefix);
				linefeed(h);
				}
			else	{
				indent(h,1);
				fprintf(h,"%s->language = %s(-1);",
					__c_instance_prefix,__visual_natlang);
				linefeed(h);
				}
			}
		else	{
			indent(h,1);
			fprintf(h,"%s->language = %s(-1);",
				__c_instance_prefix,__visual_natlang);
			linefeed(h);
			}
		}
	return;
}

public	void	c_move_event(FILE * h, struct form_item * iptr, int margin )
{
	char	*optr;

	indent(h,margin);
	fprintf(h,"return( %s%s(%s) );",iptr->Contents.name,__method_action,__c_instance_prefix);
	linefeed(h);
}

/*	MULTILINGUAL Language Switch 	*/
/*	----------------------------	*/
public	void	c_lang_event(FILE * h, struct form_item * iptr, int margin )
{
	struct form_control * fptr;
/*	This is not necessary for C generation at the moment	*/
/*	----------------------------------------------------	*/
#ifdef	FORCE_C_PAGE_ZERO	 
	if (((fptr = iptr->parent) != (struct form_control *) 0)	
	&&  ( fptr->pages != 0 )) {
		indent(h,margin);	
		fprintf(h,"%s->%s=0;",__c_instance_prefix,__c_page_number);
		linefeed(h);
		}
#endif
	indent(h,margin);
	fprintf(h,"if (%s ==_MIMO_LEFT) {",__c_mouse_button);
	linefeed(h);
	indent(h,(margin+1));	
	fprintf(h,"%s->language++; %s->language %c=%u;",
			__c_instance_prefix,__c_instance_prefix,0x0025,MAXNATLANG);
	linefeed(h);
	indent(h,(margin+1));	fprintf(h,"}");		linefeed(h);	
	indent(h,margin);	fprintf(h,"else {");	linefeed(h);
	indent(h,margin);	
	fprintf(h,"if ( %s->language > 0 ) { %s->language--; %s->language %c=%u; }",
			__c_instance_prefix,__c_instance_prefix,__c_instance_prefix,0x0025,MAXNATLANG);
	linefeed(h);
	indent(h,margin);	
	fprintf(h,"else { %s->language=7; }", __c_instance_prefix );
	linefeed(h);
	indent(h,(margin+1));	fprintf(h,"}");		linefeed(h);	
	indent(h,margin);
	fprintf(h,"(void) %s(%s->language);",__visual_natlang,
		__c_instance_prefix,__c_instance_prefix);
	linefeed(h);
	c_call(h,C_Config.cname,__method_show, 0,2,(char *) 0 );
	return;
}

private	void	c_table_widget(FILE * handle, struct form_item * iptr, int margin )
{
	indent(handle,margin);
	fprintf(handle,"%s(",__visual_table); /* vtable */
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	colour_parameter(handle,iptr);
	c_payload_parameter(handle,iptr);
	fprintf(handle,",%s->buffer_%s",__c_instance_prefix,iptr->Contents.name);
	if (!( is_valid_format( iptr->Contents.format ) )) 
		fprintf(handle,",0x0%x,(char*) 0",(iptr->Contents.align & 0x0F07));
	else	{
		fprintf(handle,",0x%x",((iptr->Contents.align & 0x0F07) | 0x4000));
		string_parameter(handle,iptr->Contents.format);
		}
	/* table row value ( if auto focus is required ) */
	/* fprintf(handle,",s->value_%s",__c_instance_prefix,iptr->Contents.name); */
	fprintf(handle,");");
	linefeed(handle);
	return;
}

public	void	reset_c_form_input()
{
	C_Config.newstdin=0;
	C_Config.input_method = __c_get_event;
	return;
}

public	void	set_c_form_input( struct form_control * fptr )
{
	struct forms_method * mptr=(struct forms_method*)0;
	reset_c_form_input();
	if (!( fptr )) {
		C_Config.input_method = __c_get_event;
		}
	else if (!( fptr->StandardInput )) {
		if (!( fptr->mimoflags & _MIMO_MOVE ))
			C_Config.input_method = __c_get_event;
		else	{
			C_Config.newstdin=2;
			C_Config.input_method = __c_stdinput;
			}
		}
	else if (!( fptr->StandardInput->name )) {
		C_Config.input_method = __c_get_event;
		}
	else	{
		C_Config.newstdin=1;
		C_Config.input_method = fptr->StandardInput->name;
		}
	return;
}

public	void	set_c_form_error( struct form_control * fptr )
{
	struct forms_method * mptr=(struct forms_method*)0;
	C_Config.newstderr=0;
	if (!( fptr ))
		C_Config.error_method = __c_put_error;
	else if (!( fptr->StandardError ))
		C_Config.error_method = __c_put_error;
	else if (!( fptr->StandardError->name ))
		C_Config.error_method = __c_put_error;
	else	{
		C_Config.newstderr=1;
		C_Config.error_method = fptr->StandardError->name;
		}
	return;
}

private	void	c_widget_focus(
			FILE * handle, 
			struct form_item * iptr, 
			int margin )
{

	if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )) {
		indent(handle,margin);
		fprintf(handle,"%s->%s = 5;",__c_instance_prefix,__c_keycode);
		linefeed(handle);
		}
	else	{
		indent(handle,margin);
		if (C_Config.newstdin != 0) {
			fprintf(handle,"%s->%s = %s(%s);",
			__c_instance_prefix,__c_keycode,C_Config.input_method,__c_instance_prefix);
			}
		else	{
			fprintf(handle,"%s->%s = %s();",
			__c_instance_prefix,__c_keycode,C_Config.input_method);
			}

		linefeed(handle);
		}
	return;
}

private	void	c_form_losefocus(FILE * h, struct form_item * iptr, int margin, int fields, int nblines )
{
	indent(h,margin++);
	fprintf(h,"if ( %s->%s == 9 ) {",__c_instance_prefix,__c_keycode);
	linefeed(h);
		indent(h,margin);
		fprintf(h,"%s->column_%s++;",__c_instance_prefix,iptr->Contents.name);
		linefeed(h);
		indent(h,margin++);
		fprintf(h,"if ( %s->column_%s > %u ) {",__c_instance_prefix,iptr->Contents.name,fields);
		linefeed(h);
			indent(h,margin);
			fprintf(h,"%s->column_%s=1;",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			indent(h,margin);
			fprintf(h,"%s->value_%s++;",__c_instance_prefix,iptr->Contents.name);
			linefeed(h);
			indent(h,margin++);
			fprintf(h,"if ( %s->value_%s > %u ) {",__c_instance_prefix,iptr->Contents.name,nblines);
			linefeed(h);
				indent(h,margin);
				fprintf(h,"%s->value_%s=1;",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				indent(h,margin--);
				fprintf(h,"}");
				linefeed(h);
			indent(h,margin--);
			fprintf(h,"}");
			linefeed(h);

		indent(h,margin);
		fprintf(h,"%s->%s=0;",__c_instance_prefix,__c_keycode);
		linefeed(h);
		indent(h,margin--);
		fprintf(h,"}");
		linefeed(h);

	return;
}


/*		------------------------------		*/
/*		c _ o n f o c u s _ f o r m ()		*/
/*		------------------------------		*/

public	int	c_onfocus_form(FILE * h, struct form_item * iptr, int margin, int * aptr, int * bptr )
{
	int		f;
	int		fh;
	int		fw;
	int		xfi=0;
	int		xfc=0;
	int		fields=0;
	int		fieldwidth[_MAX_FORM_FIELDS];
	int		linelength=0;
	int		nblines=0;
	char	*	xptr=(char *) 0;

	*aptr = 0;	*bptr=0;
			
	
	if ( iptr->Contents.datatype == _WIDGET_KONSTANT ) {
		c_widget_focus(h,iptr,1);
		return(0);
		}
	else if (!( is_valid_format( iptr->Contents.format) )) {
		c_widget_focus(h,iptr,1); 
		return(0);
		}
	if (!( fw = guifontsize(iptr->Contents.font))) {
		c_widget_focus(h,iptr,1); 
		return(0);
		}
	else if (!(fh = (fw >> 8))) {
		c_widget_focus(h,iptr,1); 
		return(0);
		}
	else	fw &= 0x00FF;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) )) {
		c_widget_focus(h,iptr,1); 
		return(0);
		}
	else	{
		indent(h,margin);
		fprintf(h,"if (!%s->value_%s) %s->value_%s=1;	/* pour etre sur qu'on edite pas le titre */",
			__c_instance_prefix, iptr->Contents.name,
			__c_instance_prefix, iptr->Contents.name);
		linefeed(h);

		*aptr = fields;
		*bptr = nblines;

		indent(h,margin);
		fprintf(h,"%s->row_%s = &%s->buffer_%s[(%s->value_%s-1)][0];",
			__c_instance_prefix, iptr->Contents.name,
			__c_instance_prefix, iptr->Contents.name,
			__c_instance_prefix, iptr->Contents.name);
		linefeed(h);
		indent(h,margin);
		fprintf(h,"switch (%s->column_%s) {",__c_instance_prefix,iptr->Contents.name);
		linefeed(h);
		sprintf(namebuffer,"((%s->value_%s-1)&1)",
			__c_instance_prefix,iptr->Contents.name);
		xptr = allocate_string( namebuffer );
		for ( 	f = 0, xfi=0;
			f < fields;
			f++ ) {
			c_case(h,f+1,margin);
			indent(h,margin+1);
			fprintf(h,"%s->%s=%s(",__c_instance_prefix,__c_keycode,__visual_edit);

			/* the pixel column position */
			/* ------------------------- */
			if ( xfi ) 	fprintf(h,"(%s+%u),",widget_x_position(iptr,0),xfi+(fw/4));
			else		fprintf(h,"(%s+%u),",widget_x_position(iptr,0),(fw/4));

			/* the pixel line position */
			/* ----------------------- */
			fprintf(h,"(%s+(%s->value_%s*%u)+2),",
				widget_y_position(iptr,0),
				__c_instance_prefix,iptr->Contents.name,fh);

			/* The field pixel width and height */
			/* -------------------------------- */
			fprintf(h,"%u,%u",((fieldwidth[f]-1)*fw),fh);

			/* The font, buffer and Length */
			/* --------------------------- */
			font_parameter(h,iptr);

			fprintf(h,",&%s->buffer_%s[",
				__c_instance_prefix,
				iptr->Contents.name );
			fprintf(h,"(%s->value_%s-1)",
				__c_instance_prefix,
				iptr->Contents.name );
			fprintf(h,"][%u]",xfc);;
			length_parameter(h,fieldwidth[f]-1);
			fprintf(h,");");
			linefeed(h);

			indent(h,margin);
			fprintf(h,"%s(",__visual_text);

			/* the pixel column position */
			/* ------------------------- */
			if ( xfi ) 	fprintf(h,"(%s+%u),",widget_x_position(iptr,0),xfi+(fw/4));
			else		fprintf(h,"(%s+%u),",widget_x_position(iptr,0),(fw/4));

			/* the pixel line position */
			/* ----------------------- */
			fprintf(h,"(%s+(%s->value_%s*%u)+2),",
				widget_y_position(iptr,0),
				__c_instance_prefix,iptr->Contents.name,fh);

			/* The field pixel width and height */
			/* -------------------------------- */
			fprintf(h,"%u,%u",((fieldwidth[f]-1)*fw),fh);

			font_parameter(h,iptr);
			zoned_colour_parameter(h,iptr,xptr);

			fprintf(h,",&%s->buffer_%s[",
				__c_instance_prefix,
				iptr->Contents.name );
			fprintf(h,"(%s->value_%s-1)",
				__c_instance_prefix,
				iptr->Contents.name );
			fprintf(h,"][%u]",xfc);;
			length_parameter(h,fieldwidth[f]-1);
			fprintf(h,",0);");
			linefeed(h);
			xfc += fieldwidth[f];
			xfi += (fieldwidth[f]*fw);
			c_break(h,margin+1);
			}
		if ( xptr )
			liberate( xptr );
		indent(h,margin+1);
		fprintf(h,"}");
		linefeed(h);
		}
	return(1);
}

/*		-------------------------		*/
/*		c _ f o r m _f o c u s ()		*/
/*		-------------------------		*/

private	void	c_form_focus(FILE * h, struct form_item * iptr, int margin )
{
	int	fields=0;
	int	nblines=0;

	/* ------------------------------------------------------------------- */
	/* the FOCUS method for FORM widgets will replace the default beaviour */
	/* ------------------------------------------------------------------- */
	if (!( iptr->Contents.events->on_get_focus ))
		c_onfocus_form( h,iptr,margin, &fields, &nblines );
	else if ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
		activate_c_method(h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,0,margin);
	else 	inline_c_method(h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,0,margin);

	/* --------------------------------------- */
	/* standard post focus : lose focus method */
	/* --------------------------------------- */
	if (!( method_is_valid(iptr->Contents.events->on_lose_focus) )) {
		c_form_losefocus(h,iptr,margin,fields,nblines);			
		}
	else if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
		activate_c_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,margin);
	else	inline_c_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,margin);

	return;
}

/*		------------------------------		*/
/*		c _ o n f o c u s _ e d i t ()		*/
/*		------------------------------		*/

public	int	c_onfocus_edit(FILE * h, struct form_item * iptr, int margin )
{
	indent(h,margin);
	if ( iptr->Contents.datatype == _WIDGET_TEXTFILE ) {
		if ( C_Config.newstdin )
			fprintf(h,"%s->%s = %s(%s);",__c_instance_prefix,__c_keycode,C_Config.input_method,__c_instance_prefix);
		else	fprintf(h,"%s->%s = %s();",__c_instance_prefix,__c_keycode,C_Config.input_method);
		}
	else	{
		fprintf(h,"%s->%s = %s(",__c_instance_prefix,__c_keycode,__visual_edit);
		widget_position(h,iptr,1,1);
		widget_dimensions(h,iptr,0,0);
		font_parameter(h,iptr);
		fprintf(h,",%s->buffer_%s",__c_instance_prefix,iptr->Contents.name);
		length_parameter(h,iptr->Contents.size);
		fprintf(h,");");
		}
	linefeed(h);
	return(1);
}


/*		-------------------------		*/
/*		c _ e d i t _f o c u s ()		*/
/*		-------------------------		*/

public	int	c_edit_focus(FILE * h, struct form_item * iptr, int margin )
{
	/* ------------------------------------------------------------------- */
	/* the FOCUS method for EDIT widgets will replace the default beaviour */
	/* ------------------------------------------------------------------- */
	if (!( iptr->Contents.events->on_get_focus ))
		c_onfocus_edit( h, iptr, margin );
	else if ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
		activate_c_method(h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,2,margin);
	else	inline_c_method(h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,0,margin);

	/* --------------------------------------- */
	/* standard post focus : lose focus method */
	/* --------------------------------------- */
	if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
		activate_c_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,margin);
	else	inline_c_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,margin);

	return(1);
}


/*		----------------------------------		*/
/*		c _ o n f o c u s _ w i d g e t ()		*/
/*		----------------------------------		*/

public	int	c_onfocus_widget(FILE * h, struct form_item * iptr, int margin )
{
	int	a=0;
	int	b=0;

	switch ((iptr->Contents.style&_FRAME_TYPE)) {

		case	_DATA_FRAME	:
			return( c_focus_visual_widget( h, iptr, margin ) );

		case	_EDIT_FRAME	:
			return( c_onfocus_edit( h, iptr, margin ) );

		case	_FORM_FRAME	:
			return( c_onfocus_form( h, iptr, margin, &a, &b ) );

		case	_SELECT_FRAME	:
			indent(h,margin);
			fprintf(h,"%s->%s = %s(",__c_instance_prefix,__c_keycode,__visual_select);
			widget_position(h,iptr,0,0);
			widget_dimensions(h,iptr,0,0);
			font_parameter(h,iptr);
			colour_parameter(h,iptr);
			fprintf(h,",parse_selection(");
			c_payload_value(h,iptr);
			fprintf(h,",&%s->value_%s",__c_instance_prefix,iptr->Contents.name);
			fprintf(h,"),%u);",((iptr->Contents.align << 8)| (iptr->Contents.special << 2) | 2) | ((iptr->Contents.align & 256) ? 8 : 0));
			linefeed(h);
			break;

		case	_BUTTON_FRAME	:
			c_onshow_widget(h,iptr,margin,2);
			c_widget_focus(h,iptr,margin);
			c_onshow_widget(h,iptr,margin,0);
		/* 	c_button_widget(h,iptr,margin,0); */
			break;

		case	_SWITCH_FRAME	:
			c_switch_widget(h,iptr,margin,2);
			c_widget_focus(h,iptr,margin);
			c_onshow_widget(h,iptr,margin,0);
		/*	c_switch_widget(h,iptr,margin,0); */
			break;

		case	_CHECK_FRAME	:
			c_check_widget(h,iptr,margin,2);
			c_widget_focus(h,iptr,margin);
			c_onshow_widget(h,iptr,margin,0);
		/*	c_check_widget(h,iptr,margin,0); */
			break;

		case	_RADIO_FRAME	:
			c_widget_focus(h,iptr,margin);
			break;

		default			:
			c_widget_focus(h,iptr,margin);
			break;
			
		}

	return(1);
}

private	void	c_scrollbar_widget(FILE * handle, struct form_item * iptr, int margin, int focus  )
{
	indent(handle,margin);
	fprintf(handle,"%s(",__visual_scrollbar);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	colour_parameter(handle,iptr);
	fprintf(handle,",%s->value_%s",__c_instance_prefix,iptr->Contents.name);
	fprintf(handle,",%s->limit_%s",__c_instance_prefix,iptr->Contents.name);
	fprintf(handle,",%s->max_%s",__c_instance_prefix,iptr->Contents.name);
	fprintf(handle,",%u);",(iptr->Contents.align|focus) );
	linefeed(handle);
	return;

}

private	void	control_show(FILE * handle, struct form_item * iptr, char * mptr, int mode, int isevent )
{
	indent(handle,1);
	fprintf(handle,"%s(",mptr);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	colour_parameter(handle,iptr);

	switch ((iptr->Contents.style&_FRAME_TYPE)) {

		case	_PROGRESS_FRAME	:
			fprintf(handle,",%s->value_%s",__c_instance_prefix,iptr->Contents.name);
			fprintf(handle,",%s->limit_%s",__c_instance_prefix,iptr->Contents.name);
			fprintf(handle,",0);");
			break;
		case	_SCROLL_FRAME	:
			fprintf(handle,",%s->value_%s",__c_instance_prefix,iptr->Contents.name);
			fprintf(handle,",%s->limit_%s",__c_instance_prefix,iptr->Contents.name);
			fprintf(handle,",%s->max_%s",__c_instance_prefix,iptr->Contents.name);
			fprintf(handle,",%u);",iptr->Contents.align);
			break;

		case	_SELECT_FRAME	:
			fprintf(handle,",parse_selection(");
			c_payload_value(handle,iptr);
			fprintf(handle,",&%s->value_%s",__c_instance_prefix,iptr->Contents.name);
			fprintf(handle,"),%u);",(iptr->Contents.align << 8));
			break;

		case	_RADIO_FRAME	:
			c_trigger_parameter( handle, iptr );
			fprintf(handle,",%s->value_%s",__c_instance_prefix,iptr->Contents.name);
			fprintf(handle,",%u);",iptr->Contents.radio);
			break;

		case	_BUTTON_FRAME	:
			c_trigger_parameter( handle, iptr );

			if ( iptr->Contents.align & 1 )
				isevent |= _VISUAL_IMAGE;
			if ( iptr->Contents.align & 2 )
				isevent |= _INHIBIT_FRAME;
			if ( iptr->Contents.align & _A_BOLD )
				isevent |= _A_BOLD;
			else 	isevent &= ~_A_BOLD;
			if ( iptr->Contents.align & _A_LINE )
				isevent |= _A_LINE;
			else 	isevent &= ~_A_LINE;
			if ( iptr->Contents.align & _A_SHADOW )
				isevent |= _A_SHADOW;
			else 	isevent &= ~_A_SHADOW;
			fprintf(handle,",%u);",isevent);
			break;

		case	_CHECK_FRAME	:
			c_trigger_parameter( handle, iptr );
			if ( mode )
				fprintf(handle,",%s->value_%s",__c_instance_prefix,iptr->Contents.name);
			else	fprintf(handle,",0");
			fprintf(handle,"|%u);",( iptr->Contents.align & (_A_LINE | _A_SHADOW)));
			break;

		case	_SWITCH_FRAME	:
			c_trigger_parameter( handle, iptr );
			if ( mode )
				fprintf(handle,",%s->value_%s",__c_instance_prefix,iptr->Contents.name);
			else	fprintf(handle,",0");
			fprintf(handle,"| 0x%04.4x);",(( iptr->Contents.align & 0x0F00) | (( iptr->Contents.align & 0x000F) << 4)));

			break;

		case	_GRAPH_FRAME	:
			c_payload_parameter(handle,iptr);
			c_payload_length_parameter(handle,iptr);
			if ( mode )
				fprintf(handle,",%s->value_%s);",__c_instance_prefix,iptr->Contents.name);
			else	fprintf(handle,",0);");
			break;
		}
	linefeed(handle);
	return;
}

private	void	c_scrollbar_payload( FILE * h, struct form_item * iptr )
{
	char	*	eptr;
	int		l;

	if (((eptr = iptr->Contents.events->on_event ) != (char *) 0)
	&&  (( l=strlen(eptr)) > 0 )) {
		if ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION )
			activate_c_method(h,iptr->Contents.name,__method_event,iptr->Contents.events->on_event,0,2);
		else	inline_c_method(h,iptr->Contents.name,__method_event,iptr->Contents.events->on_event,0,2);
		}
	else 	{
		/* Default Invocation of the FORM SHOW method */
		/* ------------------------------------------ */
		if ( C_Config.generate_program ) {
			indent(h,1);
			fprintf(h,"on_show();");
			linefeed(h);
			}
		else	{	
			c_call(h,C_Config.cname,__method_show, 0,1,"status" );
			}
		}
	c_scrollbar_widget(h,iptr,1,0x0100);
	return;
}

private	void	c_scrollbar_up(FILE * h)
{
	indent(h,2); 
	if ( C_Config.newstdin ) {
		fprintf(h,"do { while( %s(%s) != 256); } while ( %s  != _MIMO_UP );",
				C_Config.input_method,__c_instance_prefix,__c_mouse_type);
		}
	else	{
		fprintf(h,"do { while( %s() != 256); } while ( %s  != _MIMO_UP );",
				C_Config.input_method,__c_mouse_type);
		}
	linefeed(h); 
	return;
}

private	void	c_scrollbar_limitmin(FILE * h, struct form_item * iptr, int margin)
{
	indent(h,margin); fprintf(h,"if (%s->value_%s < 0) ",__c_instance_prefix,iptr->Contents.name);
	linefeed(h); 
	indent(h,margin+1); fprintf(h,"%s->value_%s = 0;",__c_instance_prefix,iptr->Contents.name);
	linefeed(h); 
	return;
}

private	void	c_scrollbar_limitmax(FILE * h, struct form_item * iptr, int margin)
{
	indent(h,margin); fprintf(h,"if (!(%s->max_%s))",__c_instance_prefix,iptr->Contents.name);
	linefeed(h); 
	indent(h,margin+1); fprintf(h,"%s->value_%s = 0;",__c_instance_prefix,iptr->Contents.name);
	linefeed(h); 
	indent(h,margin); fprintf(h,"else if ((%s->max_%s < %s->limit_%s) ",	__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name);
	linefeed(h); 
	indent(h,margin); fprintf(h,"&& (%s->value_%s >= %s->max_%s)) ",__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name);
	linefeed(h); 
	indent(h,margin+1); fprintf(h,"%s->value_%s = (%s->max_%s-1);",__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name);
	linefeed(h); 
	indent(h,margin); fprintf(h,"else if (%s->value_%s > (%s->max_%s-%s->limit_%s)) ",__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name);
	linefeed(h); 
	indent(h,margin+1); fprintf(h,"%s->value_%s = (%s->max_%s-%s->limit_%s);",__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name);
	linefeed(h); 
	return;
}

private	void	c_scrollbar_limits(FILE * h, struct form_item * iptr, int margin)
{
	indent(h,margin); fprintf(h,"if (%s->value_%s < 0) ",__c_instance_prefix,iptr->Contents.name);
	linefeed(h); 
	indent(h,margin+1); fprintf(h,"%s->value_%s = 0;",__c_instance_prefix,iptr->Contents.name);
	linefeed(h); 
	indent(h,margin); fprintf(h,"else if (%s->value_%s > (%s->max_%s-%s->limit_%s)) ",__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name);
	linefeed(h); 
	indent(h,margin+1); fprintf(h,"%s->value_%s = (%s->max_%s-%s->limit_%s);",__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name);
	linefeed(h); 
	return;
}

public	void	c_window_driver( FILE * h, struct form_item * iptr )
{
	char	*	eptr;
	int		l;
	char 	*	mode;
	char 	*	item;
	char	*	optr;

	linefeed(h);
	fprintf(h,"private int %s%s(",iptr->Contents.name,__method_action);
		c_method_instance_this(h); 
		fprintf(h,") {");
		linefeed(h);
	indent(h,1); fprintf(h,"int x=%s;",__c_mouse_column); linefeed(h);
	indent(h,1); fprintf(h,"int y=%s;",__c_mouse_row); linefeed(h);
	indent(h,1); fprintf(h,"do {");	 linefeed(h); 
		indent(h,2); fprintf(h,"do {");	 linefeed(h); 
		linefeed(h); indent(h,3); 
			if ( C_Config.newstdin )
				fprintf(h,"while(%s(%s) != 256);",C_Config.input_method,__c_instance_prefix);
			else	fprintf(h,"while(%s() != 256);",C_Config.input_method);
			linefeed(h); 
		indent(h,3); fprintf(h,"}");	 linefeed(h); 
		indent(h,2); fprintf(h,"while( %s );",__c_test_event);	 linefeed(h); 
		generate_c_freeze(h,2);
		indent(h,2);
		c_call(h,C_Config.cname, __method_hide, 0,1,(char *) 0 );
		linefeed(h);

		indent(h,2); fprintf(h,"%s->x_%s += (%s-x);",__c_instance_prefix,iptr->Contents.name,__c_mouse_column); linefeed(h);
		indent(h,2); fprintf(h,"x=%s;",__c_mouse_column); linefeed(h);
		indent(h,2); fprintf(h,"if (%s->x_%s < 0) { %s->x_%s=0; }",__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name); linefeed(h);
		indent(h,2); fprintf(h,"%s->y_%s += (%s-y);",__c_instance_prefix,iptr->Contents.name,__c_mouse_row); linefeed(h);
		indent(h,2); fprintf(h,"y=%s;",__c_mouse_row);    linefeed(h);
		indent(h,2); fprintf(h,"if (%s->y_%s < 0) { %s->y_%s=0; }",__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name); linefeed(h);

		indent(h,2);
		c_call(h,C_Config.cname,__method_show, 0,1,(char *) 0 );
		linefeed(h);
		generate_c_thaw(h,iptr,2);
	indent(h,2); fprintf(h,"}"); linefeed(h);
	indent(h,1); fprintf(h,"while ((%s & _MIMO_UP) != _MIMO_UP);",__c_mouse_type); linefeed(h);
	indent(h,1); fprintf(h,"return(-1);"); linefeed(h);
	fprintf(h,"}"); linefeed(h);

	return;

}


private	void	c_scrollbutton_driver( FILE * h, struct form_item * iptr )
{
	int		fw;
	int		fh;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;

	if ( iptr->Contents.w > iptr->Contents.h ) {

		/* ---------------------- */
		/* Left and Right Buttons */
		/* ---------------------- */
		if ( iptr->Contents.align & _A_LEFT ) {
			linefeed(h); 
			indent(h,1); fprintf(h,"if ( %s < (%s+%s) ) {",__c_mouse_column,widget_x_position(iptr,0),widget_h_dimension(iptr,0));
			linefeed(h); 
				c_scrollbar_up(h);
				indent(h,2); fprintf(h,"%s->value_%s -= 1;",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				c_scrollbar_limitmin(h,iptr,2);
				c_scrollbar_payload(h,iptr);
				c_return(h,"-1",2);
			c_endif(h,2);
			}
		if ( iptr->Contents.align & _A_RIGHT ) {
			indent(h,1); fprintf(h,"if ( %s > (%s+%s-%s) ) {",__c_mouse_column,widget_x_position(iptr,0),widget_w_dimension(iptr,0),widget_h_dimension(iptr,0));
			linefeed(h); 
				c_scrollbar_up(h);
				indent(h,2); fprintf(h,"%s->value_%s += 1;",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				c_scrollbar_limitmax(h,iptr,2);
				c_scrollbar_payload(h,iptr);
				c_return(h,"-1",2);
			c_endif(h,2);
			}
		}
	else	{
		/* ------------------- */
		/* Up and Down Buttons */
		/* ------------------- */
		if ( iptr->Contents.align & _A_LEFT ) {
			indent(h,1); fprintf(h,"if ( %s < (%s+%s) ) {",__c_mouse_row,widget_y_position(iptr,0),widget_w_dimension(iptr,0));
			linefeed(h);
				c_scrollbar_up(h);
				indent(h,2); fprintf(h,"%s->value_%s -= 1;",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				c_scrollbar_limitmin(h,iptr,2);
				c_scrollbar_payload(h,iptr);
				c_return(h,"-1",2);
			c_endif(h,2);
			}
		if ( iptr->Contents.align & _A_RIGHT ) {
			indent(h,1); fprintf(h,"if ( %s > (%s+%s-%s) ) {",__c_mouse_row,widget_y_position(iptr,0),widget_h_dimension(iptr,0),widget_w_dimension(iptr,0));
			linefeed(h);
				c_scrollbar_up(h);
				indent(h,2); fprintf(h,"%s->value_%s += 1;",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				c_scrollbar_limitmax(h,iptr,2);
				c_scrollbar_payload(h,iptr);
				c_return(h,"-1",2);
			c_endif(h,2);
			}
		}
	return;
}
		

private	void	c_scrollbar_driver( FILE * h, struct form_item * iptr )
{
	int	status=0;
	char	*	eptr;
	int		l;
	char 	*	mode;
	int		item;
	char	*	optr;
	if ( iptr->Contents.w > iptr->Contents.h ) {
		item = 7;
		mode = "x"; /* horizontal */
		}
	else	{
		item = 6;
		mode = "y"; /* vertical	*/
		}

	linefeed(h);
	fprintf(h,"%s int on_%s_%s(",keyword_private,iptr->Contents.name,__method_action);
	c_method_instance_this(h); fprintf(h,") {");
	linefeed(h); 
	indent(h,1); fprintf(h,"int status;");
	linefeed(h); 
	indent(h,1); fprintf(h,"int at%s=%s(%u);",mode,__c_visual_event,item);
	linefeed(h); 
	indent(h,1); fprintf(h,"int to%s=%s(%u);",mode,__c_visual_event,item);
	linefeed(h); 
	indent(h,1); fprintf(h,"if ( %s !=_MIMO_DOWN) { return(0); }",__c_mouse_type);
	linefeed(h); 

	if ( iptr->Contents.align & ( _A_LEFT |_A_RIGHT ) ) {
		c_scrollbutton_driver(h,iptr);
		}
		
	c_scrollbar_widget(h,iptr,1,0x0100);
	linefeed(h); indent(h,1); fprintf(h,"do {");
	linefeed(h); indent(h,2); 
	if ( C_Config.newstdin )
		fprintf(h,"while(%s(%s) != 256);",C_Config.input_method,__c_instance_prefix);
	else	fprintf(h,"while(%s() != 256);",C_Config.input_method);
	linefeed(h); 

	indent(h,2); fprintf(h,"switch( %s ) {",__c_mouse_button);	linefeed(h); 
	indent(h,2); fprintf(h,"case _MIMO_LEFT  :");			linefeed(h); 
	indent(h,2); fprintf(h,"case _MIMO_RIGHT :");			linefeed(h); 

	indent(h,2); fprintf(h,"at%s = %s->value_%s;",mode,__c_instance_prefix,iptr->Contents.name);
	linefeed(h); 
	indent(h,2); 
	fprintf(h,"%s->value_%s = ",__c_instance_prefix,iptr->Contents.name);
	if ( iptr->Contents.w > iptr->Contents.h ) {
		switch ( iptr->Contents.align & 0x0007 ) {
			case	_A_NONE		:
			case	_A_JUSTIFY	:
				fprintf(h,"(((%s - %s) * %s->max_%s) / %s);",
					__c_mouse_column,
					widget_x_position(iptr,0),
					__c_instance_prefix,iptr->Contents.name,
					widget_w_dimension(iptr,0));
				break;
			case	_A_CENTER	:
				fprintf(h,"(((%s - (%s+%s)) * %s->max_%s) / (%s - (2 * %s)));",
					__c_mouse_column,
					widget_x_position(iptr,0),
					widget_h_dimension(iptr,0),
					__c_instance_prefix,iptr->Contents.name,
					widget_w_dimension(iptr,0),
					widget_h_dimension(iptr,0));
				break;
			case	_A_LEFT  	:
				fprintf(h,"(((%s - (%s+%s)) * %s->max_%s) / (%s - %s));",
					__c_mouse_column,
					widget_x_position(iptr,0),
					widget_h_dimension(iptr,0),
					__c_instance_prefix,iptr->Contents.name,
					widget_w_dimension(iptr,0),
					widget_h_dimension(iptr,0));
				break;
			case	_A_RIGHT	:
				fprintf(h,"(((%s - %s) * %s->max_%s) / (%s - %s));",
					__c_mouse_column,
					widget_x_position(iptr,0),
					__c_instance_prefix,iptr->Contents.name,
					widget_w_dimension(iptr,0),
					widget_h_dimension(iptr,0));
				break;
			default			:
				fprintf(h,"%s->value_%s;",__c_instance_prefix,iptr->Contents.name);
			}
		}
	else	{
		switch ( iptr->Contents.align & 0x0007 ) {
			case	_A_NONE		:
			case	_A_JUSTIFY	:
				fprintf(h,"(((%s - %s) * %s->max_%s) / %s );",
					__c_mouse_row,
					widget_y_position(iptr,0),
					__c_instance_prefix,iptr->Contents.name,
					widget_h_dimension(iptr,0));
				break;
			case	_A_CENTER	:
				fprintf(h,"(((%s - (%s+%s)) * %s->max_%s) / (%s - (2 * %s)));",
					__c_mouse_row,
					widget_y_position(iptr,0),
					widget_w_dimension(iptr,0),
					__c_instance_prefix,iptr->Contents.name,
					widget_h_dimension(iptr,0),
					widget_w_dimension(iptr,0));
				break;
			case	_A_LEFT		:
				fprintf(h,"(((%s - (%s+%s)) * %s->max_%s) / (%s - %s));",
					__c_mouse_row,
					widget_y_position(iptr,0),
					widget_w_dimension(iptr,0),
					__c_instance_prefix,iptr->Contents.name,
					widget_h_dimension(iptr,0),
					widget_w_dimension(iptr,0));
				break;
			case	_A_RIGHT	:
				fprintf(h,"(((%s - %s) * %s->max_%s) / (%s - %s));",
					__c_mouse_row,
					widget_y_position(iptr,0),
					__c_instance_prefix,iptr->Contents.name,
					widget_h_dimension(iptr,0),
					widget_w_dimension(iptr,0));
				break;
			default			:
				fprintf(h,"%s->value_%s;",__c_instance_prefix,iptr->Contents.name);
			}
		}	
	linefeed(h); 
	c_scrollbar_limits(h,iptr,2);
	indent(h,2); fprintf(h,"if (%s->value_%s != at%s) {",__c_instance_prefix,iptr->Contents.name,mode);
	linefeed(h); 
	c_scrollbar_payload(h,iptr);
	indent(h,3); fprintf(h,"}");
	linefeed(h); 
	indent(h,3); fprintf(h,"}");						linefeed(h); 
	indent(h,2); fprintf(h,"}");						linefeed(h);
	indent(h,1); fprintf(h,"while (%s != _MIMO_UP);",__c_mouse_type);	linefeed(h);
	indent(h,1); fprintf(h,"switch( %s ) {",__c_mouse_button);		linefeed(h); 
	indent(h,2); fprintf(h,"case _MIMO_WHEELUP   :");			linefeed(h); 
		indent(h,3); fprintf(h,"%s->value_%s -= (%s->limit_%s/2);",__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name);
		linefeed(h);
		c_scrollbar_limitmin(h,iptr,3);
		c_scrollbar_payload(h,iptr);
		indent(h,3); fprintf(h,"break;"); 				linefeed(h);

	indent(h,2); fprintf(h,"case _MIMO_WHEELDOWN :");			linefeed(h); 
		indent(h,3); fprintf(h,"%s->value_%s += (%s->limit_%s/2);",__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name);
		linefeed(h);
		c_scrollbar_limitmax(h,iptr,3);
		c_scrollbar_payload(h,iptr);
		indent(h,3); fprintf(h,"break;"); 				linefeed(h);

	indent(h,2); fprintf(h,"}");						linefeed(h); 
	c_scrollbar_widget(h,iptr,1,0);
	linefeed(h); indent(h,1); fprintf(h,"return(1);");
	linefeed(h); fprintf(h,"}");
	linefeed(h);
	return;
}

public	void	generate_c_help(FILE * handle, struct form_item * iptr, int margin )
{
	char *	sptr;
	struct	form_control * fptr;
	if (!( fptr = iptr->parent ))
		return;
	else if (!( sptr = allocate_string( fptr->prodname ) ))
		return;
	else if (!( sptr = enforce_extension( sptr, HTM_EXTENSION ) ))
		return;

	indent(handle,margin++); fprintf(handle,"if ( %s & _MIMO_UP ) {",__c_mouse_type);
	linefeed(handle);
		indent(handle,margin); 
		fprintf(handle,"visual_help(");
		quoted_string(handle,sptr);
		fprintf(handle,");");
		linefeed(handle);
		indent(handle,margin--); 
		fprintf(handle,"};");
	linefeed(handle);
	return;
}

private	void	widget_event_response(FILE * handle, struct form_item * iptr, int margin )
{
	struct	form_control * fptr;

	if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;

	switch (( fptr->formflags & _FORM_TYPE_FLAGS )) {
		case	_FORM_TYPE_DIALOG	:
			indent(handle,margin);
			fprintf(handle,"return(%u); /* %s */",iptr->Contents.focus,iptr->Contents.name);
			linefeed(handle);
			break;
		case	_FORM_TYPE_EVENT 	:
			c_event_switch_item( handle, iptr, 0, margin );
			break;
		}
	return;
}

private	void	dynamic_widget_event(FILE * handle, struct form_item * iptr, int margin )
{
	indent(handle,margin);
	fprintf(handle,"if ((mx >= %s->x_%s ) ",__c_instance_prefix,iptr->Contents.name );
	linefeed(handle);
	indent(handle,margin);
	fprintf(handle,"&&  (my >= %s->y_%s ) ",__c_instance_prefix,iptr->Contents.name );
	linefeed(handle);
	indent(handle,margin);
	fprintf(handle,"&&  (mx <  (%s->x_%s+%s->w_%s)) ",__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name );
	linefeed(handle);
	indent(handle,margin);
	fprintf(handle,"&&  (my <  (%s->y_%s+%s->h_%s))) {",__c_instance_prefix,iptr->Contents.name,__c_instance_prefix,iptr->Contents.name );
	linefeed(handle);
	return;
}

private	void	generate_c_event(FILE * handle, struct form_item * iptr )
{
	int		margin;
	char	*	tptr;
	int		pn;
	int		fh;
	int		fw;
	int		f;
	int		hwx;
	int		wx;
	int		wy;
	int		v=0;
	struct	form_control * fptr;

	if (((fptr = iptr->parent) != (struct form_control*) 0)
	&&   ( fptr->formflags & _MULTILINGUAL))
		v = 1;

	switch ((iptr->Contents.style&_FRAME_TYPE)) {

		case	_WINDOW_FRAME	:
			if ((!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
			&&  (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )))
				break;

			if (!( f = iptr->Contents.font ))
				break;
			else	{
				fh = guifontsize(f);
				fw = (fh & 0x00FF);
				fh >>= 8;
				fh &= 0x00FF;
				}

			if (( iptr->Contents.align & (_A_BOLD | _A_LINE) ) || ( v ) || ( iptr->Contents.special )) {
				indent(handle,1);
				fprintf(handle,"switch (mt) {");
				linefeed(handle);
				indent(handle,1);
				fprintf(handle,"case _MIMO_UP :");
				linefeed(handle);
				}

			if ( iptr->Contents.align & _A_BOLD ) {


				if (!( FixedWindows )) {
					indent(handle,1);
					fprintf(handle,"if ((mx >= (%s+%u) )  ",widget_x_position(iptr,1),(iptr->Contents.w-(fh+5)));
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my >= (%s+%u) )  ",widget_y_position(iptr,1),4);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (mx <= (%s+%u) )  ",widget_x_position(iptr,1),(iptr->Contents.w-4));
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my <= (%s+%u) )) {",widget_y_position(iptr,1),(fh+4));
					linefeed(handle);
					indent(handle,2); 
					}
				else	{
					wx = ((iptr->Contents.x+iptr->Contents.w)-(fh+5));
					wy = (iptr->Contents.y+4);
					indent(handle,1);
					fprintf(handle,"if ((mx >= %u )  ",wx+WindowCol);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my >= %u )  ",wy+WindowRow);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (mx <= %u )  ",wx+WindowCol+fh);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my <= %u )) {",wy+WindowRow+fh);
					linefeed(handle);
					indent(handle,2); 
					}
				fprintf(handle,"return(%u);",iptr->Contents.focus);

				c_comment(handle,iptr->Contents.name,1);
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"}");
				linefeed(handle);

				}

			if ( iptr->Contents.align & _A_LINE ) {

				if (!( FixedWindows )) {
					indent(handle,1);
					fprintf(handle,"if ((mx >= (%s+%u) )  ",widget_x_position(iptr,1),(iptr->Contents.w-((fh*2)+5)));
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my >= (%s+%u) )  ",widget_y_position(iptr,1),4);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (mx <= (%s+%u) )  ",widget_x_position(iptr,1),(iptr->Contents.w-(fh+4)));
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my <= (%s+%u) )) {",widget_y_position(iptr,1),(fh+4));
					linefeed(handle);
					indent(handle,2); 
					}
				else	{
					hwx = ((iptr->Contents.x+iptr->Contents.w)-((fh*2)+5));
					wy = (iptr->Contents.y+4);
					indent(handle,1);
					fprintf(handle,"if ((mx >= %u )  ",hwx+WindowCol);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my >= %u )  ",wy+WindowRow);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (mx <= %u )  ",hwx+WindowCol+fh);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my <= %u )) {",wy+WindowRow+fh);
					linefeed(handle);
					}

				generate_c_help(handle,iptr,2);
				indent(handle,2); 
				fprintf(handle,"return(-1);",iptr->Contents.focus);
				c_comment(handle,iptr->Contents.name,1);
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"}");
				linefeed(handle);
				}

			if ( v ) {


				if (!( FixedWindows )) {
					indent(handle,1);
					fprintf(handle,"if ((mx >= (%s+%u) )  ",widget_x_position(iptr,1),(iptr->Contents.w-((fh*3)+5)));
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my >= (%s+%u) )  ",widget_y_position(iptr,1),4);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (mx <= (%s+%u) )  ",widget_x_position(iptr,1),(iptr->Contents.w-((fh*2)+4)));
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my <= (%s+%u) )) {",widget_y_position(iptr,1),(fh+4));
					linefeed(handle);
					indent(handle,2); 
					}
				else	{
					hwx = ((iptr->Contents.x+iptr->Contents.w)-((fh*3)+5));
					wy = (iptr->Contents.y+4);
					indent(handle,1);
					fprintf(handle,"if ((mx >= %u )  ",hwx+WindowCol);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my >= %u )  ",wy+WindowRow);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (mx <= %u )  ",hwx+WindowCol+fh);
					linefeed(handle);
					indent(handle,1);
					fprintf(handle,"&&  (my <= %u )) {",wy+WindowRow+fh);
					linefeed(handle);
					}
				c_lang_event(handle,iptr,2);
				indent(handle,2); 
				fprintf(handle,"return(-1);",iptr->Contents.focus);
				c_comment(handle,iptr->Contents.name,1);
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"}");
				linefeed(handle);
				}

			if ( iptr->Contents.special ) {
				indent(handle,1);
				fprintf(handle,"case _MIMO_DOWN :");
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"if ((mx >= (%s+%u) )  ",widget_x_position(iptr,1),4);
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"&&  (my >= (%s+%u) )  ",widget_y_position(iptr,1),4);
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"&&  (mx <= (%s+%u) )  ",widget_x_position(iptr,1),(iptr->Contents.w-((fh*4)+4)));
				linefeed(handle);
				indent(handle,2);
				fprintf(handle,"&&  (my <= (%s+%u) )) {",widget_y_position(iptr,1),(fh+4));
				linefeed(handle);
				c_move_event(handle,iptr,3);
				indent(handle,3);
				fprintf(handle,"}");
				linefeed(handle);
				}


			if (( iptr->Contents.align & (_A_BOLD | _A_LINE) ) || ( v ) || ( iptr->Contents.special )) {
				indent(handle,2);
				fprintf(handle,"}");
				linefeed(handle);
				}
			break;
	

		case	_SELECT_FRAME	:

			if ((!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
			&&  (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )))
				break;

			if (!(pn = open_c_page( handle, iptr,1 )))
				margin=1;
			else	margin=2;

			if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
				dynamic_widget_event(handle,iptr,margin);
				}
			else if ( FixedWindows ) {
				indent(handle,margin);
				fprintf(handle,"if ((mx >= %u ) ",iptr->Contents.x+WindowCol+iptr->Contents.adjust);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  (my >= %u ) ",iptr->Contents.y+WindowRow);	
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  (mx <= %u ) ",(iptr->Contents.x+WindowCol+iptr->Contents.xlimit+iptr->Contents.adjust));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  (my <= %u )) {",(iptr->Contents.y+WindowRow+iptr->Contents.ylimit));
				linefeed(handle);
				}
			else	{
				indent(handle,margin);
				fprintf(handle,"if (( mx >= (%s+%u) ) ",widget_x_position(iptr,1),iptr->Contents.adjust);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my >= (%s) ) ",widget_y_position(iptr,1));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( mx <= (%s+%u) ) ",widget_x_position(iptr,1),iptr->Contents.xlimit+iptr->Contents.adjust);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my <= (%s+%u))) {",widget_y_position(iptr,1),iptr->Contents.ylimit);
				linefeed(handle);
				}
			widget_event_response(handle,iptr,margin+1);
			indent(handle,margin+1);
			fprintf(handle,"}");
			linefeed(handle);
			close_c_page(handle,pn,1);
			break;

		case	_TAB_FRAME	:
			if ((!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
			&&  (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )))
				break;
			if (!(pn = open_c_page( handle, iptr,1 )))
				margin=1;
			else	{
				c_else(handle,1);
				margin=2;
				}
			if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
				dynamic_widget_event(handle,iptr,margin);
				}
			else if ( FixedWindows ) {
				indent(handle,margin);
				fprintf(handle,"if ((mx >= %u ) ",(iptr->Contents.x+WindowCol+iptr->Contents.adjust));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  (my >= %u ) ",iptr->Contents.y+WindowRow);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  (mx <= %u ) ",(iptr->Contents.x+WindowCol+iptr->Contents.adjust+iptr->Contents.xlimit));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  (my <= %u )) {",(iptr->Contents.y+WindowRow+iptr->Contents.ylimit));
				linefeed(handle);
				}
			else	{
				indent(handle,margin);
				fprintf(handle,"if (( mx >= (%s+%u) ) ",widget_x_position(iptr,1),iptr->Contents.adjust);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my >= (%s) ) ",widget_y_position(iptr,1));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( mx <= (%s+%u) ) ",widget_x_position(iptr,1),iptr->Contents.xlimit+iptr->Contents.adjust);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my <= (%s+%u))) {",widget_y_position(iptr,1),iptr->Contents.ylimit);
				linefeed(handle);
				}
			widget_event_response(handle,iptr,margin+1);
			indent(handle,margin+1);
			fprintf(handle,"}");
			linefeed(handle);
			close_c_page(handle,pn,1);
			break;

		case	_TEXT_FRAME	:
			break;

		case	_EDIT_FRAME	:
		case	_FORM_FRAME	:

			if ( iptr->Contents.datatype == _WIDGET_KONSTANT ) 
				break;

		case	_SCROLL_FRAME	:
		case	_PROGRESS_FRAME	:
		case	_BUTTON_FRAME	:
		case	_SWITCH_FRAME	:
		case	_GRAPH_FRAME	:
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
		default			:
			if ((!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
			&&  (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )))
				break;
			if (!(pn = open_c_page( handle, iptr,1 )))
				margin=1;
			else	margin=2;

			if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
				dynamic_widget_event(handle,iptr,margin);
				}
			else if ( FixedWindows ) {
				indent(handle,margin);
				fprintf(handle,"if (( mx >= %u ) ",iptr->Contents.x+WindowCol);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my >= %u ) ",iptr->Contents.y+WindowRow);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( mx <= %u ) ",(iptr->Contents.x+WindowCol+iptr->Contents.w));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my <= %u )) {",(iptr->Contents.y+WindowRow+iptr->Contents.h));
				linefeed(handle);
				}
			else	{
				indent(handle,margin);
				fprintf(handle,"if (( mx >= (%s) ) ",widget_x_position(iptr,1));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my >= (%s) ) ",widget_y_position(iptr,1));
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( mx <= (%s+%u) ) ",widget_x_position(iptr,1),iptr->Contents.w);
				linefeed(handle);
				indent(handle,margin);
				fprintf(handle,"&&  ( my <= (%s+%u))) {",widget_y_position(iptr,1),iptr->Contents.h);
				linefeed(handle);
				}
			c_widget_mouse_event(handle,iptr,(margin+1));
			widget_event_response(handle,iptr,margin+1);
			indent(handle,margin+1);
			fprintf(handle,"}");
			linefeed(handle);
			close_c_page(handle,pn,1);

		}
	return;
}

private	void	activate_c_method( FILE * h,char * mptr, char* nptr, char * eptr, int type, int margin )
{
	if (!( method_is_valid( eptr ) ))
		return;
	switch ( type ) {
		case	0 :
			/* void call */
			indent(h,margin);
			fprintf(h,"(void) on_%s_%s(%s);",mptr,nptr,__c_instance_prefix);
			break;
		case	1 :
			indent(h,margin);
			fprintf(h,"if ((%s->%s = on_%s_%s(%s)) != -1) break;",
				__c_instance_prefix,__c_keycode,mptr,nptr,__c_instance_prefix);
			break;
		case	2 :
			indent(h,margin);
			fprintf(h,"%s->%s = on_%s_%s(%s);",
				__c_instance_prefix,__c_keycode,mptr,nptr,__c_instance_prefix);
			break;
		}
	linefeed(h);
	return;
}

private	int	inline_c_method( FILE * h,char * mptr, char* nptr, char * eptr, int type, int margin )
{
	int	l;
	if (!(l = method_is_valid( eptr )))
		return(0);
	else	{
		return( c_method_body( h, eptr, l,mptr, margin) );
		}
}

public	void	c_special_method( FILE * h, struct  forms_method * mptr, int i )
{
	int	l;
	char *	qname;

	if (!( qname = mptr->name ))
		return;

	if ( mptr->type & _METHOD_FUNCTION ) {

		/* Function Method */
		/* --------------- */
		indent(h,i);
		fprintf(h,"%s(%s);",qname,__c_instance_prefix);
		linefeed(h);
		}
	else	{
		/* Inline Method */
		/* ------------- */
		inline_c_method(h,qname,qname,mptr->text,0,i);
		}
	return;
}

private	void	c_tab_widget(FILE * handle, struct form_item * iptr, int margin, int option )
{
	indent(handle,margin);
	fprintf(handle,"%s(",__visual_tabpage);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	c_trigger_parameter( handle,iptr );
	if ( iptr->Contents.align & _A_RIGHT )
		option |= 0x0010;
	if ( iptr->Contents.align & _A_LEFT )
		option |= 0x0020;
	option |= (iptr->Contents.align & 0x0F00);
	fprintf(handle,",%u,%u);",iptr->Contents.adjust,option);
	linefeed(handle);
	return;
}

private	void	c_fill_widget(FILE * handle, struct form_item * iptr, int margin )
{
	indent(handle,margin);
	fprintf(handle,"%s(",__visual_filzone);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	fprintf(handle,",%u,%u);",
		iptr->Contents.colour,
		(iptr->Contents.align&_VFILL_MASK));
	linefeed(handle);
	return;
}

private	void	c_outline_widget(FILE * handle, struct form_item * iptr, int margin )
{
	indent(handle,margin);
	fprintf(handle,"%s(",__visual_relief);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	fprintf(handle,",%u,0,%u);",iptr->Contents.colour,iptr->Contents.colour );
	linefeed(handle);
	return;
}

private	void	c_circle_widget(FILE * handle, struct form_item * iptr, int margin )
{
	indent(handle,margin);
	fprintf(handle,"visual_circle(");
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	fprintf(handle,",%u,1);",iptr->Contents.colour );
	linefeed(handle);
	return;
}

private	void	c_disc_widget(FILE * handle, struct form_item * iptr, int margin )
{
	indent(handle,margin);
	fprintf(handle,"visual_circle(");
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	fprintf(handle,",%u,0);",iptr->Contents.colour );
	linefeed(handle);
	return;
}

private	void	c_frame_widget(FILE * handle, struct form_item * iptr, int margin )
{
	int	fh=0;
	int	xh=0;
	char *	mptr=(char *) 0;
	if (( iptr->Contents.align != _A_NONE     ) 
	&&  ((mptr = c_payload(iptr)) != (char *) 0)) {
		fh = (guifontsize(iptr->Contents.font) >> 8 );
		xh = iptr->Contents.h;
		iptr->Contents.h = fh;
		indent(handle,margin);
		fprintf(handle,"%s(",__visual_text);
		widget_position(handle,iptr,0,0);
		widget_dimensions(handle,iptr,0,0);
		font_parameter(handle,iptr);
		colour_parameter(handle,iptr);
		c_payload_parameter(handle,iptr);
		c_payload_length_parameter(handle,iptr);
		fprintf(handle,",%u);",iptr->Contents.align);
		linefeed(handle);
		iptr->Contents.y += fh;
		iptr->Contents.h = xh;
		iptr->Contents.h -= fh;
		}
	else	{
		xh = fh = 0;
		}
	indent(handle,margin);
	fprintf(handle,"%s(",__visual_frame);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	fprintf(handle,",%u);",iptr->Contents.style );
	linefeed(handle);
	iptr->Contents.h += fh;
	iptr->Contents.y -= fh;
	return;
}

private	void	c_edit_widget(FILE * handle, struct form_item * iptr, int margin )
{
	calculate_edit_size( &iptr->Contents );
	indent(handle,margin);
	fprintf(handle,"%s(",__visual_frame); /* frame */
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,2,2);
	fprintf(handle,",%u);",iptr->Contents.style );
	linefeed(handle);
	if ( iptr->Contents.datatype != _WIDGET_TEXTFILE ) {
		indent(handle,margin);
		fprintf(handle,"%s(",__visual_text);
		widget_position(handle,iptr,1,1);
		widget_dimensions(handle,iptr,0,0);
		font_parameter(handle,iptr);
		colour_parameter(handle,iptr);
		fprintf(handle,",%s->buffer_%s",__c_instance_prefix,iptr->Contents.name);
		length_parameter(handle,iptr->Contents.size);
		if ( iptr->Contents.datatype == _WIDGET_KONSTANT )
			fprintf(handle,",%u);",iptr->Contents.align );
		else	fprintf(handle,",0);");
		linefeed(handle);
		}
	return;
}

private	void	c_text_widget(FILE * handle, struct form_item * iptr, int margin )
{
	indent(handle,margin);
	fprintf(handle,"%s(",__visual_text); /* text */
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	colour_parameter(handle,iptr);
	c_payload_parameter(handle,iptr);
	c_payload_length_parameter(handle,iptr);
	fprintf(handle,",%u);",iptr->Contents.align);
	linefeed(handle);
	return;
}

private	void	c_line_widget(FILE * handle, struct form_item * iptr, int margin )
{
	indent(handle,margin);
	fprintf(handle,"%s(",__visual_line); /* vline */
	widget_position(handle,iptr,0,0);
	widget_bottom(handle,iptr,0,0);
	fprintf(handle,",%u,%u);",
		iptr->Contents.size,
		iptr->Contents.colour  );
	linefeed(handle);
	return;
}

private	void	c_image_widget(FILE * handle, struct form_item * iptr, int margin )
{
	indent(handle,margin);
	fprintf(handle,"%s(",__visual_image); /* vimage */
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	c_payload_filename_parameter(handle,iptr);
	fprintf(handle,",%u);",iptr->Contents.align);
	linefeed(handle);
	return;
}

private	void	c_window_widget(FILE * handle, struct form_item * iptr, int margin )
{
	int	v;
	struct	form_control * fptr;
	if (((fptr = iptr->parent) != (struct form_control*) 0)
	&&  (fptr->formflags & _MULTILINGUAL ))
		v = _WINDOW_LANG_BUTTON;
	else	v = 0;
	indent(handle,margin);
	fprintf(handle,"%s(",__visual_window);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	c_payload_parameter(handle,iptr);
	c_payload_length_parameter(handle,iptr);
	fprintf(handle,",0x%x);",
		((iptr->Contents.align & _A_SHADOW) | v |
		(iptr->Contents.align & _A_BOLD ? 1 : 0 ) | 
		(iptr->Contents.align & _A_LINE ? 2 : 0 ))
		);
	linefeed(handle);
	return;
}

public	int	c_visual_element(FILE * h, struct form_item * iptr, char * sptr, int i )
{
	char *	vptr;
	int	item=0;
	char *	selection_item(int,char *);
	struct line_parser SvLineParser;

	if ( sptr != (char *) 0) {
		while ((vptr = selection_item(item,sptr )) != (char *) 0) {		
			indent(h,i);
			if (!( item )) 
				fprintf(h,"if (");
			else	fprintf(h,"||  ");
			item++;
			fprintf(h,"((%s->status = visual_styled_element(",__c_instance_prefix);
			widget_position(h,iptr,0,0);
			widget_dimensions(h,iptr,0,0);
			fprintf(h,",");
			if ( *vptr != _UNQUOTED_STRING ) {
				quoted_string(h,vptr);
				}
			else 	{
				memcpy(&SvLineParser,&LineParser,sizeof(struct line_parser));
				c_macro_conversion(h,(vptr+1),(char *) 0);
				memcpy(&LineParser,&SvLineParser,sizeof(struct line_parser));
				}
			switch (( iptr->Contents.style & _FRAME_TYPE )) {
				case	_EDIT_FRAME	:
					fprintf(h,",%s->buffer_%s",__c_instance_prefix,iptr->Contents.name);
					length_parameter(h,iptr->Contents.size);
					break;
				case	_CHECK_FRAME	:
				case	_RADIO_FRAME	:
				case	_SWITCH_FRAME	:
				case	_WINDOW_FRAME	:
				case	_BUTTON_FRAME	:
				case	_TAB_FRAME	:
				case	_TEXT_FRAME	:
				case	_IMAGE_FRAME	:
					c_payload_parameter(h,iptr );
					c_payload_length_parameter(h,iptr);
					break;
				default		:
					fprintf(h,",%c %c,0",__QUOTE,__QUOTE);
					break;
				}
			fprintf(h,")) != 0)");
			linefeed(h);
			liberate( vptr );
			}
		if ( item ) {
			fprintf(h,") {");
			linefeed(h);
			}
		}
	return(item);
}

public	int	c_show_visual_widget(FILE * h, struct form_item * iptr, int margin )
{
	/* this will handle the visual.overlay type widget */
	/* ----------------------------------------------- */
	if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME) {
		switch ( iptr->Contents.datatype ) {
			case	_WIDGET_MODULE	:
			case	_WIDGET_OVERLAY	:
				indent(h,margin);
				fprintf(h,"%s_position_at(%s->%s,%s,%s);",
					c_payload(iptr),__c_instance_prefix,iptr->Contents.name,
					widget_x_position(iptr,0),
					widget_y_position(iptr,0));
				linefeed(h);
				indent(h,margin);
				fprintf(h,"%s_show(%s->%s);",c_payload(iptr),__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				break;
			default			:
				return(0);
			}
		return( 1 );
		}
	else	{	
		return(0);
		}
}

public	int	c_hide_visual_widget(FILE * h, struct form_item * iptr, int margin )
{
	/* this will handle the visual.overlay type widget */
	/* ----------------------------------------------- */
	if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME) {
		switch ( iptr->Contents.datatype ) {
			case	_WIDGET_MODULE	:
			case	_WIDGET_OVERLAY	:
				indent(h,margin);
				fprintf(h,"%s_hide(%s->%s);",c_payload(iptr),__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				break;
			default			:
				return(0);
			}
		return( 1 );
		}
	else	{	
		return(0);
		}
}

public	int	c_focus_visual_widget(FILE * h, struct form_item * iptr, int margin)
{
	/* this will handle the visual.overlay type widget */
	/* ----------------------------------------------- */
	if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME) {
		switch ( iptr->Contents.datatype ) {
			case	_WIDGET_MODULE	:
			case	_WIDGET_OVERLAY	:
				indent(h,margin);
				fprintf(h,"%s->keycode = %s_focus(%s->%s);",
					__c_instance_prefix,c_payload(iptr),
					__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				return( 1 );
			default			:
				c_widget_focus(h,iptr,margin);
				return(0);
			}
		}
	else	{	
		c_widget_focus(h,iptr,margin);
		return(0);
		}
}

public	int	c_onshow_widget(FILE * h, struct form_item * iptr, int margin, int focus )
{
	char *	sptr=(char *) 0;
	int	items=0;

	if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
		generate_c_popup(h,iptr,margin);
		}

	generate_trigger_code( h, iptr, margin );

	if (!( focus ))
		sptr = iptr->Contents.stylesheet;
	else	sptr = iptr->Contents.stylefocus;

	if ( method_is_valid( sptr ) ) {
		items = c_visual_element( h, iptr, sptr, margin++);
		}

	switch (( iptr->Contents.style & _FRAME_TYPE )) {
		case	_DATA_FRAME		:
			return( c_show_visual_widget(h,iptr,margin));

		case	_FILL_FRAME		:
			c_fill_widget(h,iptr,margin);
			break;

		case	_OUTSET_FRAME		:
		case	_INSET_FRAME		:
		case	_RIDGE_FRAME		:
		case	_GROOVE_FRAME		:
			c_frame_widget(h,iptr,margin);
			break;

		case	_TEXT_FRAME		:
			c_text_widget(h,iptr,margin);
			break;
		case	_IMAGE_FRAME		:
			c_image_widget(h,iptr,margin);
			break;

		case	_LINE_FRAME		:
			c_line_widget(h,iptr,margin);
			break;

		case	_WINDOW_FRAME		:
			c_window_widget(h,iptr,margin);
			break;

		case	_TAB_FRAME		:
			return(0);

		case	_BUTTON_FRAME		:
			if ( focus )
				c_button_widget(h,iptr,margin,2);
			else	control_show(h,iptr,__visual_button,0,0);
			break;

		case	_CHECK_FRAME		:
			if ( focus )
				c_check_widget(h,iptr,margin,2);
			else	control_show(h,iptr,__visual_check,1,0);
			break;
		
		case	_SWITCH_FRAME	:
			if ( focus )
				c_switch_widget(h,iptr,margin,2);
			else	control_show(h,iptr,__visual_switch,1,0);
			break;
		
		case	_RADIO_FRAME		:
			control_show(h,iptr,__visual_radio,1,0);
			break;
		
		case	_GRAPH_FRAME		:
			control_show(h,iptr,__visual_graph,1,0);
			break;
		
		case	_FORM_FRAME		:
			calculate_edit_size( &iptr->Contents );
			c_table_widget(h,iptr,margin);
			break;

		case	_EDIT_FRAME		:
			c_edit_widget(h,iptr,0);
			break;

		case	_SELECT_FRAME		:
			control_show(h,iptr,__visual_select /* "select" */,0,0);
			break;

		case	_SCROLL_FRAME		:
			control_show(h,iptr,__visual_scrollbar,1,0);
			break;

		case	_PROGRESS_FRAME		:
			control_show(h,iptr,__visual_progress,1,0);
			break;


		}

	if ( method_is_valid( sptr  ) ) {
		if ( items ) {
			indent(h,--margin);
			fprintf(h,"}");
			linefeed(h);
			}
		}

	return(1);
}

private	void	instance_trigger_code( FILE * h, struct form_item * iptr, int margin )
{
	struct form_control * fptr;
	char		    * sptr;
	if (!( fptr = iptr->parent))
		return;
	else if (!( fptr->formflags & _INTERNATIONAL ))
		return;
	else if (!( fptr->formflags & _MULTILINGUAL ))
		return;

	switch ((iptr->Contents.style&_FRAME_TYPE)) {
		case	_RADIO_FRAME	:
			if (!( sptr = c_payload(iptr)))
				return;
			indent(h,margin);
			fprintf(h,"int \ttrigger%u_%s;",iptr->Contents.radio,iptr->Contents.name);
			break;

		case	_BUTTON_FRAME	:
		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
		case	_TAB_FRAME	:
			if (!( sptr = c_payload(iptr)))
				return;
			indent(h,margin);
			fprintf(h,"int\ttrigger_%s;",iptr->Contents.name);
			linefeed(h);
			break;
		}
	return;
}

private	void	generate_trigger_code( FILE * h, struct form_item * iptr, int margin )
{
	struct form_control * fptr;
	char		*	sptr;
	if (!( fptr = iptr->parent))
		return;
	else if (!( fptr->formflags & _INTERNATIONAL ))
		return;
	else if (!( fptr->formflags & _MULTILINGUAL ))
		return;

	switch ((iptr->Contents.style&_FRAME_TYPE)) {
		case	_RADIO_FRAME	:
			if (!( sptr = c_payload(iptr)))
				return;
			indent(h,margin);
			fprintf(h,"%s->trigger%u_%s=visual_trigger_code(",
				__c_instance_prefix,
				iptr->Contents.radio,
				iptr->Contents.name);
			break;
		case	_BUTTON_FRAME	:
		case	_SWITCH_FRAME	:
		case	_CHECK_FRAME	:
		case	_TAB_FRAME	:
			if (!( sptr = c_payload(iptr)))
				return;
			indent(h,margin);
			fprintf(h,"%s->trigger_%s=visual_trigger_code(",
				__c_instance_prefix,
				iptr->Contents.name);
			break;
		default			:
			return;
		}
	c_payload_value(h,iptr);
	c_payload_length_parameter(h,iptr);
	fprintf(h,");");
	linefeed(h);
	return;
}

private	void	generate_c_show(FILE * h, struct form_item * iptr, int margin )
{
	int	items=0;
	char	*	sptr;
	char	*	tptr;
	int		pn=0;

	pn = open_c_page( h, iptr,1 );


	if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
		generate_c_popup(h,iptr,margin);
		}

	if (((iptr->Contents.style&_FRAME_TYPE) != _TAB_FRAME)
	&&  ( method_is_valid(iptr->Contents.events->on_show) )) {
		if ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION )
			activate_c_method(h,iptr->Contents.name,__method_show,iptr->Contents.events->on_show,0,margin);
		else	inline_c_method(h,iptr->Contents.name,__method_show,iptr->Contents.events->on_show,0,margin);
		}
	else	{
		generate_trigger_code( h, iptr, 1 );
		if ( method_is_valid((sptr = iptr->Contents.stylesheet)) ) {
			items = c_visual_element( h, iptr, sptr, margin++);
			}
	switch ((iptr->Contents.style&_FRAME_TYPE)) {
		case	_DATA_FRAME		:
			return( c_show_visual_widget(h,iptr,margin));

		case	_FILL_FRAME	:
			c_fill_widget(h,iptr,margin);
			break;
		case	_OUTLINE_FRAME	:
			c_outline_widget(h,iptr,margin);
			break;

		case	_CIRCLE_FRAME	:
			c_circle_widget(h,iptr,margin);
			break;
		case	_DISC_FRAME	:
			c_disc_widget(h,iptr,margin);
			break;

		case	_INSET_FRAME	:
		case	_OUTSET_FRAME	:
		case	_GROOVE_FRAME	:
		case	_RIDGE_FRAME	:
			c_frame_widget(h,iptr,margin);
			break;

		case	_FORM_FRAME	:
			calculate_edit_size( &iptr->Contents );
			if (!( iptr->Contents.events->on_show ))
				c_table_widget(h,iptr,margin);
			break;

		case	_EDIT_FRAME	:
			c_edit_widget(h,iptr,margin);
			break;

		case	_TEXT_FRAME	:
			c_text_widget(h,iptr,margin);
			break;

		case	_LINE_FRAME	:
			c_line_widget(h,iptr,margin);
			break;

		case	_IMAGE_FRAME	:
			c_image_widget(h,iptr,margin);
			break;

		case	_PROGRESS_FRAME	:
			control_show(h,iptr,__visual_progress,0,0);
			break;
		case	_SCROLL_FRAME	:
			c_scrollbar_widget(h,iptr,margin,0);
			break;
		case	_SELECT_FRAME	:
			control_show(h,iptr,__visual_select /* "select" */,0,0);
			break;
		case	_BUTTON_FRAME	:
			control_show(h,iptr,__visual_button /* "button" */,0,0);
			break;
		case	_SWITCH_FRAME	:
			control_show(h,iptr,__visual_switch /* "vswitch" */,1,0);
			break;
		case	_GRAPH_FRAME	:
			control_show(h,iptr,__visual_graph /* "vgraph" */,1,0);
			break;
		case	_CHECK_FRAME	:
			control_show(h,iptr,__visual_check /* "check" */,1,0);
			break;
		case	_RADIO_FRAME	:
			control_show(h,iptr,__visual_radio /* "radio" */,1,0);
			break;
		case	_TAB_FRAME	:
			c_tab_widget(h,iptr,margin,2);
			/* tab page on show event when page is visible */
			/* ------------------------------------------- */
			if ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION )
				activate_c_method(h,iptr->Contents.name,__method_show,iptr->Contents.events->on_show,0,margin+1);
			else	inline_c_method(h,iptr->Contents.name,__method_show,iptr->Contents.events->on_show,0,margin+1);
			c_else(h,margin);
			c_tab_widget(h,iptr,margin+1,0);
			close_c_page( h, pn,1 );
			return;

		case	_WINDOW_FRAME	:
			c_window_widget(h,iptr,margin);
			break;

		}
		if ( method_is_valid( iptr->Contents.stylesheet ) ) {
			if ( items ) {
				indent(h,margin--);
				fprintf(h,"}");
				linefeed(h);
				}
			}
		}

	close_c_page( h, pn,1 );

	return;

}

private	void	c_switch_widget(
			FILE * handle, 
			struct form_item * iptr, 
			int margin,
			int etat )

{
	indent(handle,4);
	fprintf(handle,"%s(",__visual_switch);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	colour_parameter(handle,iptr);
	c_trigger_parameter( handle,iptr );
	fprintf(handle,",(%s->value_%s | %u | 0x%04.4X ));",__c_instance_prefix,iptr->Contents.name,etat,(( iptr->Contents.align & 0x0F00) | (( iptr->Contents.align & 0x000F) << 4)));
	linefeed(handle);
}

private	void	c_check_widget(
			FILE * handle, 
			struct form_item * iptr, 
			int margin,
			int etat )

{
	indent(handle,4);
	fprintf(handle,"%s(",__visual_check);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	colour_parameter(handle,iptr);
	c_trigger_parameter( handle,iptr );
	fprintf(handle,",(%s->value_%s |%u));",__c_instance_prefix,iptr->Contents.name,etat);
	linefeed(handle);
}

private	void	c_button_widget(
			FILE * handle, 
			struct form_item * iptr, 
			int margin,
			int etat )
{
	indent(handle,margin);
	fprintf(handle,"%s(",__visual_button);
	widget_position(handle,iptr,0,0);
	widget_dimensions(handle,iptr,0,0);
	font_parameter(handle,iptr);
	colour_parameter(handle,iptr);
	c_trigger_parameter( handle,iptr );
	etat |= (iptr->Contents.align & 0x0F00);
	if ( iptr->Contents.align & 1 )
		etat |= _VISUAL_IMAGE;
	if ( iptr->Contents.align & 2 )
		etat |= _INHIBIT_FRAME;
	if ( iptr->Contents.align & _A_BOLD )
		etat |= _A_BOLD;
	if ( iptr->Contents.align & _A_LINE )
		etat |= _A_LINE;
	if ( iptr->Contents.align & _A_SHADOW )
		etat |= _A_SHADOW;
	fprintf(handle,",%u);",etat);
	linefeed(handle);
	return;
}

private	void	control_focus(FILE * h, struct form_item * iptr, char * mptr, int mode )
{
	int	pn=0;
	int	margin=0;

	c_case(h,iptr->Contents.focus,(margin=3));
	c_comment(h,iptr->Contents.name,++margin);
	if (( pn = open_c_page(h,iptr,margin ))!=0)
		margin++;

	c_hint_method( h, iptr, margin );

	if ( method_is_valid( iptr->Contents.events->on_get_focus ) ) {
		if ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
			activate_c_method(h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,2,margin);
		else	inline_c_method  (h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,0,margin);
		}
	else	{
		c_onfocus_widget( h, iptr, margin );
		}

	if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
		activate_c_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,margin);
	else	inline_c_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,margin);

	if ( pn ) {
		c_else( h, --margin );
		indent(h,margin);
		fprintf(h,"%s->%s = 5;",__c_instance_prefix,__c_keycode);
		linefeed(h);
		}
	close_c_page(h,pn,4);

	c_break(h,4);
	return;
}

private	void	generate_c_focus(FILE * h, struct form_item * iptr )
{
	char	*	tptr;
	int		pn=0;
	int	margin=0;

	if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
		return;

	switch ((iptr->Contents.style&_FRAME_TYPE)) {

		case	_DATA_FRAME	:

			if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME) {
				switch ( iptr->Contents.datatype ) {

					case	_WIDGET_MODULE	:
					case	_WIDGET_OVERLAY	:

						c_case(h,iptr->Contents.focus,margin=3);
						c_comment(h,iptr->Contents.name,++margin);
						if ((pn = open_c_page(h,iptr,margin)) != 0)
							margin++;

						if ( method_is_valid( iptr->Contents.events->on_get_focus ) ) {
							if ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
								activate_c_method(h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,2,margin);
							else	inline_c_method  (h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,0,margin);
							}
						else	{
							(void) c_focus_visual_widget( h, iptr, margin );
							}

						if ( pn ) {
							c_else( h, --margin );
							indent(h,margin);
							fprintf(h,"%s->%s = 5;",__c_instance_prefix,__c_keycode);
							linefeed(h);
							}
						close_c_page(h,pn,--margin);
						c_break(h,margin);
					}
				}
			break;

		case	_FORM_FRAME	:
		case	_EDIT_FRAME	:

			if ( iptr->Contents.datatype == _WIDGET_KONSTANT ) 
				break;
			else	{
				c_case(h,iptr->Contents.focus,margin=3);
				c_comment(h,iptr->Contents.name,++margin);

				if ((pn = open_c_page(h,iptr,margin)) != 0)
					margin++;

				c_hint_method( h, iptr, margin );
				switch ((iptr->Contents.style&_FRAME_TYPE)) {
	
					case	_FORM_FRAME	:
						c_form_focus(h, iptr, margin );
						break;
					case	_EDIT_FRAME	:
						c_edit_focus(h, iptr, margin );
						break;
					}

				if ( pn ) {
					c_else( h,(margin-1) );
					indent(h,margin);
					fprintf(h,"%s->%s = 5;",__c_instance_prefix,__c_keycode);
					linefeed(h);
					}
				close_c_page(h,pn,--margin);
				c_break(h,margin);
				}
			break;

		case	_IMAGE_FRAME	:
			control_focus(h,iptr,__c_get_event /* "select" */,0);
			break;
		case	_SELECT_FRAME	:
			control_focus(h,iptr,__visual_select /* "select" */,0);
			break;
		case	_BUTTON_FRAME	:
			control_focus(h,iptr,__visual_button /* "button" */,0);
			break;
		case	_SWITCH_FRAME	:
			control_focus(h,iptr,__visual_switch /* "vswitch" */,1);
			break;
		case	_GRAPH_FRAME	:
			control_focus(h,iptr,__visual_graph /* "vgraph" */,1);
			break;
		case	_CHECK_FRAME	:
			control_focus(h,iptr,__visual_check /* "check" */,1);
			break;
		case	_RADIO_FRAME	:
			control_focus(h,iptr,__visual_radio /* "radio" */,1);
			break;

		case	_SCROLL_FRAME	:
		case	_WINDOW_FRAME	:
		case	_TAB_FRAME	:
			c_case(h,iptr->Contents.focus,3);
			c_comment(h,iptr->Contents.name,4);
			if (!( 	pn = open_c_page(h,iptr,4) ))
				margin = 4;
			else	margin = 5;

			if (!( iptr->Contents.events->on_get_focus )) {
				indent(h,margin);
				if ( C_Config.newstdin )
					fprintf(h,"%s->%s=%s(%s);",__c_instance_prefix,__c_keycode,C_Config.input_method,__c_instance_prefix);
				else 	fprintf(h,"%s->%s=%s();",__c_instance_prefix,__c_keycode,C_Config.input_method);
				linefeed(h);
				}
			else if ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
				activate_c_method(h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,2,margin);
			else	inline_c_method(h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus,0,margin);
			if ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
				activate_c_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,margin);
			else	inline_c_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus,0,margin);
			if ( pn ) {
				c_else( h, 4 );
					indent(h,margin);
					fprintf(h,"%s->%s=5;",__c_instance_prefix,__c_keycode);
					linefeed(h);
				}
			close_c_page(h,pn,4);
			c_break(h,4);
			break;

		}

	return;

}

private  void	open_c_structure( FILE * h,char * cname)
{
	linefeed(h);
	fprintf(h,"%s struct %s%s {",keyword_private,cname,__c_instance_suffix);
	linefeed(h);
	fprintf(h,"\tint\t%s;",__c_status);
	linefeed(h);
	fprintf(h,"\tint\t%s;",__c_keycode);
	linefeed(h);
	fprintf(h,"\tint\t%s;",__c_focus_item);
	linefeed(h);
	fprintf(h,"\tint\t%ss;",__c_focus_item);
	linefeed(h);
	fprintf(h,"\tint\twindow_col;");
	linefeed(h);
	fprintf(h,"\tint\twindow_row;");
	linefeed(h);
	fprintf(h,"\tint\tlanguage;");
	linefeed(h);
	return;
}



private int	c_widget_value( FILE * h,struct form_item * iptr, int margin )
{
	indent(h,margin);
	fprintf(h,"int\tvalue_%s;",iptr->Contents.name);
	linefeed(h);
	return(0);
}

private int	c_widget_column( FILE * h,struct form_item * iptr, int margin )
{
	indent(h,margin);
	fprintf(h,"int\tcolumn_%s;",iptr->Contents.name);
	linefeed(h);
	return(0);
}

private int	c_widget_limit( FILE * h,struct form_item * iptr, int margin )
{
	indent(h,margin);
	fprintf(h,"int\tlimit_%s;",iptr->Contents.name);
	linefeed(h);
	return(0);
}

private int	c_widget_formsort( FILE * h,struct form_item * iptr, int margin )
{
	indent(h,margin);
	fprintf(h,"int\tformsort_%s;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */",iptr->Contents.name);
	linefeed(h);
	return(0);
}

private int	c_widget_libsort( FILE * h,struct form_item * iptr, int margin )
{
	indent(h,margin);
	fprintf(h,"char\t*libsort_%s;	/* table intermédiaire contenant la liste des éléments a trier */",iptr->Contents.name);
	linefeed(h);
	indent(h,margin);
	fprintf(h,"int\t*tabsort_%s;	/* numéro d'ordre des elements triés */",iptr->Contents.name);
	linefeed(h);
	indent(h,margin);
	fprintf(h,"char\t*indsort_%s;	/* pointeur table intermédiaire de tri */",iptr->Contents.name);
	linefeed(h);
	indent(h,margin);
	fprintf(h,"int\tnelt_%s;	/* nombre d'eléments aloués dans tabsort */",iptr->Contents.name);
	linefeed(h);
	return(0);
}

private int	c_widget_max( FILE * h,struct form_item * iptr, int margin )
{
 	indent(h,margin);
	fprintf(h,"int\tmax_%s;", iptr->Contents.name);
	linefeed(h);
	return(0);
}


private int	c_widget_buffer( 
			FILE * h,
			struct form_item * iptr, int margin,
			int	lines,	int	columns )
{
 	indent(h,margin);
	if (!( lines )) {
		fprintf(h,"char\tbuffer_%s[%u];",
			iptr->Contents.name,
			columns+1);

		}
	else	{
		fprintf(h,"char\tbuffer_%s[%u][%u];",
			iptr->Contents.name,
			lines,columns);
		}
	linefeed(h);
	return(0);
}
private int	c_widget_pointer( 
			FILE * h,
			struct form_item * iptr, 
			int margin,
			char * id )
{
 	indent(h,margin);
	fprintf(h,"char * %s_%s;",id,iptr->Contents.name);
	linefeed(h);
	return(0);
}

private int	c_hint_matrix(FILE * h,struct form_item * iptr )
{
 	indent(h,1);
	if (( iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
		fprintf(h,"char * hint%u_%s[%u];",iptr->Contents.radio,iptr->Contents.name,MAXNATLANG);
	else	fprintf(h,"char * hint_%s[%u];",iptr->Contents.name,MAXNATLANG);
	linefeed(h);
	return(0);
}
private int	c_message_matrix(FILE * h,struct form_item * iptr )
{
 	indent(h,1);
	if (( iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
		fprintf(h,"char * msg%u_%s[%u];",iptr->Contents.radio,iptr->Contents.name,MAXNATLANG);
	else	fprintf(h,"char * msg_%s[%u];",iptr->Contents.name,MAXNATLANG);
	linefeed(h);
	instance_trigger_code(h,iptr,1);
	c_hint_matrix( h, iptr );
	return(0);
}

char *	add_antislach(char *org)
{
	char *dest;
	int c=0,d=0;

	if (!org) return((char *)0);

	dest=org;
	while (strchr(dest,'\\')) {
		c++;
		dest=strchr(dest,'\\')+1;
		}

	if ((dest=allocate(method_is_valid(org)+c+1))) {
		c=0;
		while (org[c]) {
			if (org[c]=='\\')
				dest[d++]='\\';
			dest[d++]=org[c++];	
			}
		dest[d]=0;
		}
	return(dest);
}

int	c_define_messages(FILE * h,struct form_control * fptr)
{
	struct form_item * iptr;
	char 		 * sptr=(char *) 0;
	int		   nl;
	for (	iptr=fptr->first;
		iptr != (struct form_item*) 0;
		iptr = iptr->next ) {
		for ( nl=0; nl < MAXNATLANG; nl++ ) {
			if (!( sptr = iptr->Contents.messages[nl] ))
				continue;
			else if ( *sptr == _UNQUOTED_STRING )
				continue;
			else if (!( sptr = add_antislach(sptr)))
				continue;
			else	{
				if (( iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
					fprintf(h,"#define %s%u_%s %c%s%c",language_prefix(nl),iptr->Contents.radio,iptr->Contents.name,__QUOTE,sptr,__QUOTE);
				else	fprintf(h,"#define %s_%s   %c%s%c",language_prefix(nl),iptr->Contents.name,__QUOTE,sptr,__QUOTE);
				linefeed(h);
				liberate( sptr );
				}
			}
		for ( nl=0; nl < MAXNATLANG; nl++ ) {
			if (!( sptr = iptr->Contents.hmessages[nl] ))
				continue;
			else if ( *sptr == _UNQUOTED_STRING )
				continue;
			else if (!( sptr = add_antislach( sptr )))
				continue;
			else	{
				if (( iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
					fprintf(h,"#define %s%u__%s %c%s%c",language_prefix(nl),iptr->Contents.radio,iptr->Contents.name,__QUOTE,sptr,__QUOTE);
				else	fprintf(h,"#define %s__%s   %c%s%c",language_prefix(nl),iptr->Contents.name,__QUOTE,sptr,__QUOTE);
				linefeed(h);
				liberate(sptr);
				}
			}
		}
	return(0);
}

public  void	logical_c_font( FILE * h,struct form_item * iptr )
{
	if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS )
		fprintf(h,"%s->fid_%s",__c_instance_prefix,iptr->Contents.name);
	else if ( C_Config.generate_program )
		fprintf(h,"vfh[%u]",iptr->Contents.font);
	else if ( C_Config.generate_overlay )
		fprintf(h,"vfh[%u]",iptr->Contents.font);
	else	fprintf(h,"vfh[%u]",iptr->Contents.font);
	return;
}


private	void	generate_c_data_instance( FILE * h, struct form_item * iptr )
{
	int	t;
	switch ((t = (iptr->Contents.align & 0x000F)) ) {
		case	_OBJECT_FRAME	:

			indent(h,1);
			if ( iptr->Contents.datatype == _WIDGET_POINTER )
				fprintf(h,"struct %s * %s",c_payload(iptr),iptr->Contents.name);
			else	fprintf(h,"struct %s %s",c_payload(iptr),iptr->Contents.name);
			fprintf(h,";");
			linefeed(h);
			break;

		case	_VISUAL_FRAME	:
			switch ( iptr->Contents.datatype ) {
				case	_WIDGET_MODULE	:
				case	_WIDGET_OVERLAY	:
					indent(h,1);
					fprintf(h,"struct %s%s * %s;",c_payload(iptr),__c_instance_suffix,iptr->Contents.name);
					linefeed(h);
					break;
	
				case	_WIDGET_CLASS  	:
					indent(h,1);
					fprintf(h,"struct %s %s;",c_payload(iptr),iptr->Contents.name);
					/* fprintf(h,"(%u,%u);",iptr->Contents.x,iptr->Contents.y); */
					linefeed(h);
					break;

				case 	_WIDGET_POINTER : 
					indent(h,1);
					fprintf(h,"struct %s * %s;",c_payload(iptr),iptr->Contents.name);
					/* fprintf(h,"(%u,%u);",iptr->Contents.x,iptr->Contents.y); */
					linefeed(h);
					break;
				}
			break;

		case	_VARIABLE_FRAME :
			indent(h,1);
			switch ( iptr->Contents.datatype ) {
				case	_WIDGET_BYTE		:	fprintf(h,"char   %s;",iptr->Contents.name); break;
				case	_WIDGET_WORD		:	fprintf(h,"short  %s;",iptr->Contents.name); break;
				case	_WIDGET_LONG		:	fprintf(h,"long   %s;",iptr->Contents.name); break;
				case	_WIDGET_FLOAT		:	fprintf(h,"float  %s;",iptr->Contents.name); break;
				case	_WIDGET_NUMERIC		:	fprintf(h,"double %s;",iptr->Contents.name); break;
				case	_WIDGET_STRING 		:	fprintf(h,"char * %s;",iptr->Contents.name); break;
				}
			break;
		case	_VMEMORY_FRAME	:
			break;

		case	_SQFILE_FRAME	:
		case	_DBFILE_FRAME	:
		case	_SIFILE_FRAME	:
		case	_MCFILE_FRAME	:
			break;
		}
	return;
}

private int	c_module_description( FILE * h,char * cname)
{
	char 		* headname=(char *) 0;
	if (!( headname = allocate_string( cname ) )) {
		allocate_failure();
		return(0);
		}
	else if (!( headname = enforce_extension( headname, H_EXTENSION ) )) {
		allocate_failure();
		return(0);
		}
	else	{
		c_include(h, headname );
		liberate( headname );
		return(1);
		}
}

private int	generate_c_form_structure( FILE * h,char * cname)
{
	char		* tptr;
	struct form_item* iptr;
	struct form_item* wptr=(struct form_item*) 0;
	int		  s;
	int		  items=0;
	int		  wt;
	int		  f;
	int		  linelength;
	int		  nblines=0;
	int		  fields=0;
	int		  fieldwidth[_MAX_FORM_FIELDS];
	int		  payloadmax;
	char		* prefix[16];
	int		  ispublic=0;
	FILE		* hh=(FILE *) 0;
	char 		* headname=(char *) 0;

	if ( Context.Form->formflags & _MULTILINGUAL )
		c_define_messages(h,Context.Form);

	if (( C_Config.generate_program   )
	&&  (!( C_Config.generate_overlay ))) {
		fprintf(h,"static int _%s_users=0;",C_Config.cname);
		linefeed(h);
		fprintf(h,"static struct %s_context * _%s=(struct %s_context* )0;",C_Config.cname,C_Config.cname,C_Config.cname);
		linefeed(h);
		}

	if ((!( C_Config.generate_program ))  && ( C_Config.generate_overlay )) {

		if (!( headname = headername( Context.Form->prodname, H_EXTENSION ) ))
			return( allocate_failure() );
		else if (!( hh = open_production_target(headname,0))) 
			return(0);
		else	file_exclusion(hh, headname );

		production_banner(hh,_GENERATE_C,Context.Form->loadname,headname);

		c_include(h, headname );

		}
	else	hh = h;

	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if ((iptr->Contents.style & _FRAME_TYPE) != _DATA_FRAME)
			continue;
		else if ((iptr->Contents.align & 0x000F) != _VISUAL_FRAME)
			continue;
		else	{
			switch ( iptr->Contents.datatype ) {
				case	_WIDGET_MODULE	:
				case	_WIDGET_OVERLAY	:
					if ( method_is_valid( c_payload(iptr) ) ) {
						if (!( c_module_description(hh,c_payload( iptr )) )) {
							fprintf(hh,"struct %s%s;",c_payload(iptr),__c_instance_suffix);
							linefeed(hh);
							}
						}
					break;
				}
			}		
		}	

	open_c_structure( hh, cname );

	Signature[0] = 0;

	if ( Context.Form->pages ) {
		fprintf(hh,"\tint\tfocus_pages[%u+1];",Context.Form->pages);
		linefeed(hh);
		}
	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if ( Context.Form->formflags & _MULTILINGUAL ) {
			if (( payloadmax = max_payload_size( iptr )) != 0) {
				c_message_matrix(hh,iptr);
				}
			else	c_hint_matrix(hh,iptr);
			}

		if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
			/* Generate Position and Dimensions Variables */
			fprintf(hh,"\tint\tx_%s;",iptr->Contents.name);
			linefeed(hh);
			fprintf(hh,"\tint\ty_%s;",iptr->Contents.name);
			linefeed(hh);
			fprintf(hh,"\tint\tw_%s;",iptr->Contents.name);
			linefeed(hh);
			fprintf(hh,"\tint\th_%s;",iptr->Contents.name);
			linefeed(hh);
			fprintf(hh,"\tint\tfg_%s;",iptr->Contents.name);
			linefeed(hh);
			fprintf(hh,"\tint\tbg_%s;",iptr->Contents.name);
			linefeed(hh);
			fprintf(hh,"\tint\tfid_%s;",iptr->Contents.name);
			linefeed(hh);
			}

		if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
			fprintf(hh,"\tint\ts_%s;",iptr->Contents.name);
			linefeed(hh);
			fprintf(hh,"\tvoid *\tp_%s;",iptr->Contents.name);
			linefeed(hh);
			}

		switch (((s=iptr->Contents.style)&_FRAME_TYPE)) {
			case	_DATA_FRAME	:
				generate_c_data_instance( hh, iptr );
				break;

			case	_WINDOW_FRAME	:
				if (!( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ))
					c_instance_position_control( hh, iptr );
				wptr = iptr;
				calculate_window_alignment(iptr);
				break;

			case	_TAB_FRAME	:
				if (!( C_Config.page_control )) {
					indent(hh,1);
					fprintf(hh,"int\t%s;",__c_page_number);
					C_Config.page_control=1;
					linefeed(hh);
					}
				break;

			case	_RADIO_FRAME	:
				if ( iptr->Contents.radio == 1 ) {
					c_widget_value(hh,iptr,1);
					items = add_interface_item(items, iptr, _SYMBOLIC_WORD );
					}
				break;

			case	_PROGRESS_FRAME	:
				c_widget_value(hh,iptr,1);
				c_widget_limit(hh,iptr,1);
				items = add_interface_item(items, iptr, _SYMBOLIC_WORD );
				items = add_interface_item(items, iptr, _SYMBOLIC_WORD );
				break;

			case	_SCROLL_FRAME	:
				c_widget_value(hh,iptr,1);
				c_widget_limit(hh,iptr,1);
				c_widget_max(hh,iptr,1);
				items = add_interface_item(items, iptr, _SYMBOLIC_WORD );
				items = add_interface_item(items, iptr, _SYMBOLIC_WORD );
				items = add_interface_item(items, iptr, _SYMBOLIC_WORD );
				break;

			case	_GRAPH_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SELECT_FRAME	:
			case	_CHECK_FRAME	:
				c_widget_value(hh,iptr,1);
				items = add_interface_item(items,  iptr, _SYMBOLIC_WORD );
				break;

			case	_FORM_FRAME	:
				calculate_edit_size( &iptr->Contents );
				calculate_form_lines( iptr, &linelength, &nblines );
				if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
					break;
				c_widget_value(hh,iptr,1);
				c_widget_column(hh,iptr,1);
				c_widget_buffer(hh,iptr,1,nblines+1,linelength);
				c_widget_formsort(hh,iptr,1);
				c_widget_libsort(hh,iptr,1);
				c_widget_pointer(hh,iptr,1,"row");
				items = add_interface_item(items, iptr, _SYMBOLIC_STRING );
				break;

			case	_EDIT_FRAME	:
				calculate_edit_size( &iptr->Contents );
				if ( iptr->Contents.datatype == _WIDGET_TEXTFILE ) {
					c_widget_pointer(hh,iptr,1,"buffer");
					}
				else	{
					c_widget_buffer(hh,iptr,1,0,iptr->Contents.size);
					}
				items = add_interface_item(items, iptr, _SYMBOLIC_STRING );
				break;

			}
		}

	/* handle screen saver */
	/* ------------------- */
	if ( Context.Form->ispopup ) {
		if (!( wptr != (struct form_item *) 0))  {
			indent(hh,1);
			fprintf(hh,"int\tx_,y_,w_,h_;");
			linefeed(hh);
			}
		indent(hh,1);
		fprintf(hh,"int\tctrlbuffer;");
		linefeed(hh);
		indent(hh,1);
		fprintf(hh,"void * pushbuffer;");
		linefeed(hh);
		}

	fprintf(hh,"\tchar\tsignature[%u];",items+1);
	linefeed(hh);

	fprintf(hh,"\t};");
	linefeed(hh);

	if ((!( C_Config.generate_program ))  && ( C_Config.generate_overlay )) {
		c_forms_method_forward(hh,Context.Form,0);
		close_exclusion(hh, headname );
		close_production_target(hh,headname);
		}

	fprintf(h,"static int\tvfh[16];");
	linefeed(h);

	return(items);
}

public  void	c_member_parameters( FILE * h, int iscall )
{
	int	nb;
	char *	prefix;
	struct form_item * iptr;
	if (!( iscall & 1))
		prefix = "char *";
	else	prefix = "\0";


	/* ---------------------------------------------- */
	/* No instance parameter for Parental Exec Method */
	/* ---------------------------------------------- */
	if (!( iscall & 4 )) {

		linefeed(h);
		indent(h,1);	

		/* special case for oncreate ! */
		/* --------------------------- */
		if (!( iscall & 2)) {
			/* NOT ON CREATE */
			if (!( iscall & 1 ))
				c_method_instance_this(h);
			else	fprintf(h,"%s",__c_instance_prefix);
			}
		else	{
			/* ONCREATE SIGNATURE */
			if (!( iscall & 1 )) {
				c_method_instance_class(h);
				fprintf(h," ** cptr");
				}
			else	fprintf(h,"&%s",__c_instance_prefix);
			}
		}

	for (	nb=0,iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		switch ((iptr->Contents.style)&_FRAME_TYPE) {
			case	_RADIO_FRAME	:
				if ( iptr->Contents.radio != 1 )
					break;
			case	_GRAPH_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SELECT_FRAME	:
			case	_CHECK_FRAME	:
			case	_EDIT_FRAME	:
				
				if (!( iptr->Contents.interfaceitem ))
					break;
				if (!(iscall & 4))
					fprintf(h,",");
				else if ( nb )
					fprintf(h,",");
				linefeed(h);
				indent(h,1);	
				fprintf(h,"%s p%s",prefix,iptr->Contents.name);
				nb++;
			}
		}
	return;
}

public  void	c_signature( FILE * h, char * cname, char * fname, int members,int iscall )
{
	linefeed(h);

	if (!( *fname ))
		fprintf(h,"public\tint\t%s(",cname);
	else	fprintf(h,"public\tint\t%s_%s(",cname,fname);

	if ( members != 0 )
		c_member_parameters( h, iscall );
	else if (!( iscall & 2 ))
		c_method_instance_this(h);
	else if (!(  iscall & 4 )) {
		/* special case for void create */
		c_method_instance_class(h);
		fprintf(h," **cptr");
		}

	fprintf(h,")");
	linefeed(h);
	fprintf(h,"{");
	linefeed(h);
	return;
}

public  void	c_call( FILE * h, char * cname, char * fname, int members, int level, char * genret )
{
	indent(h,level);

	if ( genret )
		fprintf(h,"%s = ",genret);

	if (!( *fname ))
		fprintf(h,"%s(",cname);
	else	fprintf(h,"%s_%s(",cname,fname);

	if ( members != 0 )
		c_member_parameters(h,1);
	else	{
		fprintf(h,"%s",__c_instance_prefix);
		}

	fprintf(h,");");
	linefeed(h);
	return;
}

public  void	c_call_create( FILE * h, char * cname, char * fname, int members, int level, char * genret )
{
	indent(h,level);

	if ( genret )
		fprintf(h,"%s = ",genret);

	if (!( *fname ))
		fprintf(h,"%s(",cname);
	else	fprintf(h,"%s_%s(",cname,fname);

	if ( members != 0 )
		c_member_parameters(h,3);
	else 	fprintf(h,"&%s",__c_instance_prefix);

	fprintf(h,");");
	linefeed(h);
	return;
}

public  void	reset_parameters( FILE * h  )
{
	struct form_item * iptr;
	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ( iptr->Contents.interfaceitem )
			continue;
		switch ((iptr->Contents.style&_FRAME_TYPE)) {

			case	_SCROLL_FRAME	:
				indent(h,2);
				fprintf(h,"%s->max_%s=0;",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);

			case	_PROGRESS_FRAME	:
				indent(h,2);
				fprintf(h,"%s->limit_%s=0;",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);

			case	_RADIO_FRAME	:
			case	_CHECK_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SELECT_FRAME	:
				indent(h,2);
				fprintf(h,"%s->value_%s=0;",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				continue;

			case	_FORM_FRAME	:
				indent(h,1);
				fprintf(h,"%s->formsort_%s=0;	/* valeur initiale du tri : aucun */",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				indent(h,1);
				fprintf(h,"%s->libsort_%s=NULL;	/* pas de table intermédiaire de tri */",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				indent(h,1);
				fprintf(h,"if ((%s->tabsort_%s=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);				
				indent(h,2);
				fprintf(h,"for (%s->nelt_%s=0;%s->nelt_%s<512;%s->nelt_%s++)",
					__c_instance_prefix,iptr->Contents.name,
					__c_instance_prefix,iptr->Contents.name,
					__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				indent(h,3);
				fprintf(h,"{ %s->tabsort_%s[%s->nelt_%s]=%s->nelt_%s+1; };	/* initialisation tableau sans tri */",
					__c_instance_prefix,iptr->Contents.name,
					__c_instance_prefix,iptr->Contents.name,
					__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				indent(h,1);
				fprintf(h,"} else %s->nelt_%s=0; /* si problème d'allocation */",__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
				fprintf(h,"%s->indsort_%s=NULL;	/* pas de pointeur de table intermédiaire */",__c_instance_prefix,iptr->Contents.name);
				continue;

			case	_EDIT_FRAME	:
				calculate_edit_size( &iptr->Contents );
				indent(h,2);
				if ( iptr->Contents.datatype == _WIDGET_TEXTFILE )
					fprintf(h,"%s->buffer_%s=(char *) 0;",__c_instance_prefix,iptr->Contents.name);
				else	fprintf(h,"for (i=0; i < %u; i++)  *(%s->buffer_%s+i)=' ';",iptr->Contents.size,__c_instance_prefix,iptr->Contents.name);
				linefeed(h);
			}
		}
	return;
}

public  void	transfer_parameters( FILE * h , int direction )
{
	int	e=0;
	int	item=0;
	int	s;
	struct form_item * iptr;
	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (!( iptr->Contents.interfaceitem ))
			continue;
		switch (((s=iptr->Contents.style)&_FRAME_TYPE)) {
			case	_EDIT_FRAME	:
				if (!( direction )) {
					if ( iptr->Contents.datatype == _WIDGET_TEXTFILE ) {
						if (!( e )) {
							indent(h,1);
							fprintf(h,"if (%s->%s == 27 ) {",__c_instance_prefix,__c_keycode);
							linefeed(h);
							}
						e++;
						indent(h,2);
						fprintf(h,"filetransferdrop(%s->buffer_%s);",
							__c_instance_prefix,iptr->Contents.name);
						linefeed(h);
						}
					}
				}
		}
	if ( e != 0 ) {
		indent(h,2);
		linefeed(h);
		c_else(h,1);
		}
	else	{
		indent(h,1);
		fprintf(h,"if (%s->%s != 27 ) {",__c_instance_prefix,__c_keycode);
		linefeed(h);
		}
	indent(h,2);
	fprintf(h,"strcpy(%s->signature,%c%s%c);",__c_instance_prefix,__QUOTE,Signature,__QUOTE);
	linefeed(h);
	indent(h,2);
	fprintf(h,"%s(%s->signature,%s->signature);",__visual_signature,__c_instance_prefix,__c_instance_prefix);
	linefeed(h);
	for (	iptr=Context.Form->first;  
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (!( iptr->Contents.interfaceitem ))
			continue;
		switch (((s=iptr->Contents.style)&_FRAME_TYPE)) {
			case	_RADIO_FRAME	:
				if ( iptr->Contents.radio != 1 )
					break;
			case	_SELECT_FRAME	:
			case	_SWITCH_FRAME	:
			case	_GRAPH_FRAME	:
			case	_CHECK_FRAME	:
				if ( direction ) {
					/* transfer  in */
					indent(h,2);
					fprintf(h,"%s((void *) 0, 0, p%s);",__visual_transferin,iptr->Contents.name);
					linefeed(h);
					indent(h,2);
					fprintf(h,"if (!( p%s )) %s->value_%s=0;",
						iptr->Contents.name,__c_instance_prefix,iptr->Contents.name);
					linefeed(h);
					indent(h,2);
					fprintf(h,"else\t%s->value_%s = *((int *)p%s);",__c_instance_prefix,
						iptr->Contents.name,iptr->Contents.name);
					linefeed(h);
					}
				else	{
					/* transfer out */
					indent(h,2);
					fprintf(h,"%s((void *) 0, 0, p%s);",__visual_transferout,iptr->Contents.name);
					linefeed(h);
					indent(h,2);
					fprintf(h,"if ( p%s != (char *) 0)",iptr->Contents.name);
					linefeed(h);
					indent(h,3);
					fprintf(h,"*((int*)p%s) = %s->value_%s;",
						iptr->Contents.name,__c_instance_prefix,iptr->Contents.name);
					linefeed(h);
					}
				item++;
				break;
			case	_EDIT_FRAME	:
				calculate_edit_size( &iptr->Contents );
				if ( direction ) {
					/* transfer  in */
					indent(h,2);
					if ( iptr->Contents.datatype == _WIDGET_TEXTFILE ) {	
						indent(h,2);
						fprintf(h,"%s->buffer_%s=(char *) 0;",__c_instance_prefix,iptr->Contents.name);
						linefeed(h);
						indent(h,2);
						fprintf(h,"%s(&%s->buffer_%s, %u, p%s);",__visual_transferin,__c_instance_prefix,
							iptr->Contents.name,iptr->Contents.size,iptr->Contents.name);
						}
					else	{	
						fprintf(h,"%s(%s->buffer_%s, %u, p%s);",__visual_transferin,__c_instance_prefix,
							iptr->Contents.name,iptr->Contents.size,iptr->Contents.name);
						}
					linefeed(h);
					}
				else	{
					/* transfer out */
					indent(h,2);
					if ( iptr->Contents.datatype == _WIDGET_TEXTFILE ) {	
						fprintf(h,"%s(&%s->buffer_%s, %u, p%s);",__visual_transferout,__c_instance_prefix,
							iptr->Contents.name,iptr->Contents.size,iptr->Contents.name);
						}
					else	{
						fprintf(h,"%s(%s->buffer_%s, %u, p%s);",__visual_transferout,__c_instance_prefix,
							iptr->Contents.name,iptr->Contents.size,iptr->Contents.name);
						}
					linefeed(h);
					}
				item++;
			}
		}
	indent(h,2);
	fprintf(h,"}");
	linefeed(h);
	return;
}

private	void	c_oncreate_prototypes( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_create )
		&&  ( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION ))
			c_prototype(h,iptr->Contents.name,__method_create,iptr->Contents.events->on_create);

		}

	return;
}
private	void	c_oncreate_methods( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_create )
		&&  ( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION ))
			c_method(h,iptr->Contents.name,__method_create,iptr->Contents.events->on_create);

		}

	return;
}

private	void	c_onshow_prototypes( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_show )
		&&  ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION ))
			c_prototype(h,iptr->Contents.name,__method_show,iptr->Contents.events->on_show);
		}

	return;
}
private	void	c_onshow_methods( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_show )
		&&  ( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION ))
			c_method(h,iptr->Contents.name,__method_show,iptr->Contents.events->on_show);
		}

	return;
}

private	void	c_onget_prototypes( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_get_focus )
		&&  ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION ))
			c_prototype(h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus);
		}

	return;
}
private	void	c_onget_methods( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_get_focus )
		&&  ( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION ))
			c_method(h,iptr->Contents.name,__method_getfocus,iptr->Contents.events->on_get_focus);
		}

	return;
}

private	void	c_onlose_prototypes( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_lose_focus )
		&&  ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION ))
			c_prototype(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus);
		}

	return;
}

private	void	c_onlose_methods( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_lose_focus )
		&&  ( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION ))
			c_method(h,iptr->Contents.name,__method_losefocus,iptr->Contents.events->on_lose_focus);
		}

	return;
}

private	void	c_onevent_prototypes( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;

	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if (( iptr->Contents.events->on_event )
		&&  ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))
			c_prototype(h,iptr->Contents.name,__method_event,iptr->Contents.events->on_event);

		}
	return;
}

private	void	c_onevent_methods( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;

	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		if (( iptr->Contents.events->on_event )
		&&  ( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION ))
			c_method(h,iptr->Contents.name,__method_event,iptr->Contents.events->on_event);

		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_WINDOW_FRAME	:
				if ( iptr->Contents.special ) {
					c_window_driver(h,iptr);
					}
				break;

			case	_SCROLL_FRAME	:
				/* Scroll Bar Specific Complement */
				/* ------------------------------ */
				c_scrollbar_driver(h,iptr);
				break;

			}
		}
	return;
}

private	void	c_onhide_prototypes( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_hide )
		&&  ( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION ))
			c_prototype(h,iptr->Contents.name,__method_hide,iptr->Contents.events->on_hide);
		}

	return;
}
private	void	c_onhide_methods( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_hide )
		&&  ( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION ))
			c_method(h,iptr->Contents.name,__method_hide,iptr->Contents.events->on_hide);
		}

	return;
}
private	void	c_onremove_prototypes( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_remove )
		&&  ( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION ))
			c_prototype(h,iptr->Contents.name,__method_remove,iptr->Contents.events->on_remove);
		}

	return;
}

private	void	c_onremove_methods( FILE * h, struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if (( iptr->Contents.events->on_remove )
		&&  ( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION ))
			c_method(h,iptr->Contents.name,__method_remove,iptr->Contents.events->on_remove);
		}

	return;
}

private	void	c_event_prototypes( FILE * h )
{

	c_oncreate_prototypes(h,Context.Form);	
	c_onshow_prototypes(h,Context.Form);	
	c_onget_prototypes(h,Context.Form);	
	c_onlose_prototypes(h,Context.Form);	
	c_onevent_prototypes(h,Context.Form);	
	c_onhide_prototypes(h,Context.Form);	
	c_onremove_prototypes(h,Context.Form);	
	return;
}

private	void	c_event_methods( FILE * h )
{

	c_oncreate_prototypes(h,Context.Form);	
	c_onshow_prototypes(h,Context.Form);	
	c_onget_prototypes(h,Context.Form);	
	c_onlose_prototypes(h,Context.Form);	
	c_onevent_prototypes(h,Context.Form);	
	c_onhide_prototypes(h,Context.Form);	
	c_onremove_prototypes(h,Context.Form);	

	c_oncreate_methods(h,Context.Form);	
	c_onshow_methods(h,Context.Form);	
	c_onget_methods(h,Context.Form);	
	c_onlose_methods(h,Context.Form);	
	c_onevent_methods(h,Context.Form);	
	c_onhide_methods(h,Context.Form);	
	c_onremove_methods(h,Context.Form);	
	return;
}

private	void	generate_c_main(FILE * h, char * cname, int members, int canfocus)
{
	int	i;
	/* -------------------- */
	/*	MAIN ()    	*/
	/* -------------------- */

	if ( C_Config.generate_program ) {

		fprintf(h,"public\tint\tmain(int argc, char * argv[])");
		linefeed(h);
		fprintf(h,"{");
		linefeed(h);

		indent(h,1);	
		c_method_instance_this( h );	fprintf(h,"=(");	
		c_method_instance_class(h); 	fprintf(h,"*) 0;");	
		linefeed(h);

		indent(h,1);
		fprintf(h,"set_configuration_name(argv[0]);");
		linefeed(h);
		indent(h,1);
		fprintf(h,"if ( on_create(&%s",__c_instance_prefix);
		for (i=0; i < members; i++ ) {
			fprintf(h,",0");
			}
		fprintf(h,") == 0 ) {");
		linefeed(h);
		indent(h,2);
		fprintf(h,"on_show(%s);",__c_instance_prefix);
		linefeed(h);
		indent(h,2);
		fprintf(h,"on_focus(%s);",__c_instance_prefix);
		linefeed(h);
		indent(h,2);
		fprintf(h,"on_hide(%s);",__c_instance_prefix);
		linefeed(h);
		indent(h,2);
		fprintf(h,"on_remove(%s",__c_instance_prefix);
		for (i=0; i < members; i++ ) {
			fprintf(h,",0");
			}
		fprintf(h,");");
		linefeed(h);
		indent(h,2);
		fprintf(h,"}");
		linefeed(h);
		c_return(h,"0",1);
		linefeed(h);
		fprintf(h,"}");
		linefeed(h);

		}

	/* -------------------- */
	/*	METHOD     	*/
	/* -------------------- */
	else	{
		c_signature(h,cname,"\0", members,6 );
		indent(h,1);
		fprintf(h,"int\tstatus=0;");
		linefeed(h);
		indent(h,1);	
		c_method_instance_this( h );	fprintf(h,"=(");	
		c_method_instance_class(h); 	fprintf(h,"*) 0;");	
		linefeed(h);
		c_call_create(h,cname,__method_create, members,1,"status");
		indent(h,1);
		fprintf(h,"if ( status != 0) return(status);");
		linefeed(h);
		c_call(h,cname,__method_show, 0,1,"status" );
		if (( Context.Form->formflags & _FORM_TYPE_FLAGS ) == _FORM_TYPE_DIALOG	) {
			indent(h,2); 
			fprintf(h,"enter_modal();"); 
			linefeed(h);
			}
		c_call(h,cname,"focus", 0,1,"status" );
		if (( Context.Form->formflags & _FORM_TYPE_FLAGS ) == _FORM_TYPE_DIALOG	) {
			indent(h,2); 
			fprintf(h,"leave_modal();"); 
			linefeed(h);
			}
		c_call(h,cname,__method_hide, 0,1,"status" );
		c_call(h,cname,__method_remove, members,1,"status" );
		/* ------------------------------------ */
		/* cancel the stdinput: ijm 17/02/2007  */
		/* ------------------------------------ */
		reset_c_form_input();
		generate_c_event_flush(h);
		indent(h,1);
		fprintf(h,"return(status);");
		linefeed(h);
		fprintf(h,"}");
		linefeed(h);
		}

	c_comment(h,"End of File",0);
	return;
}


private	void	open_c_on_create(FILE * h, char * cname, int members)
{
	/* -------------------- */
	/*	ON _ CREATE	*/
	/* -------------------- */
	c_signature(h,cname,__method_create, members, 2 );
	linefeed(h);

	return;
}


public	void	c_dependance( FILE * h, char * sptr )
{
	standard_dependance( h, sptr, keyword_include );
}

public  void	export_c_page( FILE * h )
{
	return;
}

#include "singcfrm.c"

public	void	initialise_c_production()
{
	return;
}

public	void	release_c_production()
{
	return;
}

#endif	/* _SINGC_C */

