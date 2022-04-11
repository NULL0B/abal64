
#define	_ON_CREATE	"oncreate"
#define	_ON_REMOVE	"onremove"
#define	_ON_HIDE  	"onhide"
#define	_ON_SHOW  	"onshow"
#define	_ON_GETFOCUS	"ongetfocus"
#define	_ON_LOSEFOCUS	"onlosefocus"
#define	_ON_EVENT	"onevent"

private	char *	CppWidgetClass[16] = {
	"fill",		"frame",	"frame",	"frame",
	"frame",	"edit",		"text",		"image",

	"line",		"button",	"window",	"tabpage",	
	"check",	"radio",	"select",	"form"

	};


private	char *	get_cpp_widget_class( int wid )
{
	return( CppWidgetClass[(wid  & 0x000F)] );
}

private	void	define_cpp_instance(FILE * h, char * cname)
{
	struct	form_item * iptr;

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		fprintf(h,"\tvisual_%s * %s;",get_cpp_widget_class(iptr->Contents.style),iptr->Contents.name);
		linefeed(h);
		}
	return;
}

private	void	create_cpp_form(FILE * h, char * cname)
{
	struct	form_item * iptr;

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		fprintf(h,"\t%s = new visual_%s",iptr->Contents.name,
				get_cpp_widget_class(iptr->Contents.style));

		fprintf(h,"(%u,%u,%u,%u", iptr->Contents.x,iptr->Contents.y,
					  iptr->Contents.w,iptr->Contents.h );

		switch ((iptr->Contents.style & _FRAME_TYPE )) {

			case	_LINE_FRAME 	: /* thickness   */
				fprintf(h,",%u",iptr->Contents.size );

			case	_FILL_FRAME	: /* just colour */
				fprintf(h,",%u",iptr->Contents.colour);
				break;

			case	_OUTSET_FRAME	: /* just style  */
			case	_INSET_FRAME	: /* just style  */
			case	_RIDGE_FRAME	: /* just style  */
			case	_GROOVE_FRAME	: /* just style  */
				fprintf(h,",%u",iptr->Contents.style);
				break;

			case	_IMAGE_FRAME	: /* payload/align */
				filename_parameter(h,iptr->Contents.payload);
				align_parameter(h,iptr);
				break;

			case	_BUTTON_FRAME	:
			case	_TAB_FRAME	: /* f,sptr,a*/
				font_parameter(h,iptr);
				string_parameter(h,iptr->Contents.payload);
				align_parameter(h,iptr);
				break;

			case	_SELECT_FRAME	: /* f,sptr*/
				font_parameter(h,iptr);
				string_parameter(h,iptr->Contents.payload);
				fprintf(h,",0");
				break;

			case	_GRAPH_FRAME	:
			case	_SWITCH_FRAME	:
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	: /* fg,bg,f,sptr,a,v*/
				colour_parameter(h,iptr);
				font_parameter(h,iptr);
				string_parameter(h,iptr->Contents.payload);
				align_parameter(h,iptr);
				fprintf(h,",0");
				break;

			case	_TEXT_FRAME	:
			case	_WINDOW_FRAME	: /* fg,bg,f,sptr,a*/
				colour_parameter(h,iptr);
				font_parameter(h,iptr);
				string_parameter(h,iptr->Contents.payload);
				align_parameter(h,iptr);
				break;


			case	_EDIT_FRAME	: /* fg,bg,f,sptr,l*/
				colour_parameter(h,iptr);
				font_parameter(h,iptr);
				string_parameter(h,iptr->Contents.payload);
				length_parameter(h,iptr->Contents.size);
				break;
			}
		fprintf(h,");");
		linefeed(h);
		}

	return;
}

private	void	remove_cpp_form(FILE * h, char * cname)
{
	struct	form_item * iptr;

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	{
			fprintf(h,"\tdelete %s;",iptr->Contents.name);
			linefeed(h);
			}
		}

	return;
}

private	void	show_cpp_form(FILE * h, char * cname)
{
	struct	form_item * iptr;

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	{
			fprintf(h,"\t%s->%s();",iptr->Contents.name,_ON_SHOW);
			linefeed(h);
			}
		}

	return;
}

private	void	hide_cpp_form(FILE * h, char * cname)
{
	struct	form_item * iptr;

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	{
			fprintf(h,"\t%s->%s();",iptr->Contents.name,_ON_HIDE);
			linefeed(h);
			}
		}

	return;
}

private	void	cpp_banner(FILE * h, char * token )
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

private	void	void_cpp_method(FILE * h, char * cname, char * fname )
{
	if ( fname != (char *) 0)
		cpp_banner(h,fname);

	fprintf(h,"\r\nvoid %s::",cname);
	if (!( fname ))
		fprintf(h,"~%s()\r\n{",cname);
	else	fprintf(h,"%s()\r\n{",fname);
	return;
}

private	void	void_cpp_emethod(FILE * h)
{
	fprintf(h,"\r\n\treturn;\r\n}\r\n");
	return;
}

private	void	int_cpp_emethod(FILE * h)
{
	fprintf(h,"\r\n\treturn(0);\r\n}\r\n");
	return;
}

private	void	int_cpp_method(FILE * h, char * cname, char * fname )
{
	if ( fname != (char *) 0)
		cpp_banner(h,fname);

	fprintf(h,"\r\nint  %s::",cname);
	if (!( fname ))
		fprintf(h,"~%s()\r\n{",cname);
	else	fprintf(h,"%s()\r\n{",fname);
	return;
}

private	void	events_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}


	return;
}

private	void	construction_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	void_cpp_method(h,cname,cname);
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}

	void_cpp_emethod(h);
	return;
}

private	void	destruction_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	void_cpp_method(h,cname,(char *) 0);
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}

	void_cpp_emethod(h);

	return;
}

private	void	on_show_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	void_cpp_method(h,cname,"on_show");
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}

	void_cpp_emethod(h);

	return;
}

private	void	on_hide_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	void_cpp_method(h,cname,"on_hide_focus");
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}

	void_cpp_emethod(h);

	return;
}

private	void	on_get_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	void_cpp_method(h,cname,"on_get_focus");
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}

	void_cpp_emethod(h);

	return;
}

private	void	on_lose_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	void_cpp_method(h,cname,"on_lose_focus");
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}

	void_cpp_emethod(h);

	return;
}

private	void	on_event_cpp(FILE * h, char * cname)
{
	struct	form_item * iptr;
	int_cpp_method(h,cname,"on_lose_focus");
	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		}

	int_cpp_emethod(h);

	return;
}



public	void	export_cpp_menu( FILE * h )
{
	return;
}

private	void	export_cpp_formbody( FILE * h, char * cname, char * headfile )
{
	/* Generate File Banner Block */
	production_banner(h,_GENERATE_CPP,Context.Form->loadname,cname);

	cpp_banner(h,cname);

	if ( C_Config.generate_program )
		c_include(h,"<stdio.h>");


	c_include(h,headfile);


	/* Forms Constructor */
	/* ----------------- */
	linefeed(h );	fprintf(h,"%s::%s()",cname,cname);

	linefeed(h );	fprintf(h," : visual_container(0,0,0,0,0,0)");
	linefeed(h );	fprintf(h,"{");

	create_cpp_form(h,cname);

	linefeed(h );	fprintf(h,"\t%s();",_ON_CREATE);
	linefeed(h );	fprintf(h,"\treturn;");
	linefeed(h );	fprintf(h,"}");
	linefeed(h );


	/* Forms Destructor */
	/* ---------------- */
	linefeed(h );	fprintf(h,"%s::~%s()",cname,cname);
	linefeed(h );	fprintf(h,"{");
	linefeed(h );	fprintf(h,"\t%s();",_ON_REMOVE);

	remove_cpp_form(h,cname);

	linefeed(h );	fprintf(h,"\treturn;");
	linefeed(h );	fprintf(h,"}");
	linefeed(h );

	/* On Create */
	/* --------- */
	linefeed(h );	fprintf(h,"void %s::%s()",cname,_ON_CREATE);
	linefeed(h );	fprintf(h,"{");
	linefeed(h );	fprintf(h,"\treturn;");
	linefeed(h );	fprintf(h,"}");
	linefeed(h );

	/* On Remove */
	/* --------- */
	linefeed(h );	fprintf(h,"void %s::%s()",cname,_ON_REMOVE);
	linefeed(h );	fprintf(h,"{");
	linefeed(h );	fprintf(h,"\treturn;");
	linefeed(h );	fprintf(h,"}");
	linefeed(h );

	/* On Show */
	/* ------- */
	linefeed(h );	fprintf(h,"void %s::%s()",cname,_ON_SHOW);
	linefeed(h );	fprintf(h,"{");

	show_cpp_form(h,cname);

	linefeed(h );	fprintf(h,"\treturn;");
	linefeed(h );	fprintf(h,"}");
	linefeed(h );


	/* On Hide */
	/* ------- */
	linefeed(h );	fprintf(h,"void %s::%s()",cname,_ON_HIDE);
	linefeed(h );	fprintf(h,"{");

	hide_cpp_form(h,cname);

	linefeed(h );	fprintf(h,"\treturn;");
	linefeed(h );	fprintf(h,"}");
	linefeed(h );

	/* On GetFocus */
	/* ----------- */
	linefeed(h );	fprintf(h,"word %s::%s()",cname,_ON_GETFOCUS);
	linefeed(h );	fprintf(h,"{");
	linefeed(h );	fprintf(h,"\treturn(5);");
	linefeed(h );	fprintf(h,"}");
	linefeed(h );

	/* On LoseFocus */
	/* ------------ */
	linefeed(h );	fprintf(h,"void %s::%s()",cname,_ON_LOSEFOCUS);
	linefeed(h );	fprintf(h,"{");
	linefeed(h );	fprintf(h,"\treturn;");
	linefeed(h );	fprintf(h,"}");
	linefeed(h );

	/* On Event */
	/* -------- */
	linefeed(h );	fprintf(h,"void %s::%s()",cname,_ON_EVENT);
	linefeed(h );	fprintf(h,"{");
	linefeed(h );	fprintf(h,"\treturn;");
	linefeed(h );	fprintf(h,"}");
	linefeed(h );

	if (!( C_Config.generate_program )) {

		linefeed(h); fprintf(h,"word _%s()",cname);
		linefeed(h); fprintf(h,"{");
		linefeed(h); fprintf(h,"\tword result=0;");
		linefeed(h); fprintf(h,"\t%s * instance;",cname);
		linefeed(h); fprintf(h,"\tinstance = new %s;",cname);
		linefeed(h); fprintf(h,"\tinstance->%s();",_ON_SHOW);
		linefeed(h); fprintf(h,"\tresult = instance->%s();",_ON_GETFOCUS);
		linefeed(h); fprintf(h,"\tinstance->%s();",_ON_LOSEFOCUS);
		linefeed(h); fprintf(h,"\tinstance->%s();",_ON_HIDE);
		linefeed(h); fprintf(h,"\tdelete instance;");
		linefeed(h); fprintf(h,"\treturn(result);");
		linefeed(h); fprintf(h,"}");
		linefeed(h);
		}
	else	{
		linefeed(h); fprintf(h,"int main(int argc,char *argv[])");
		linefeed(h); fprintf(h,"{");
		linefeed(h); fprintf(h,"\tword result;");
		linefeed(h); fprintf(h,"\t%s * instance=0;",cname);
		linefeed(h); fprintf(h,"\tinstance = new %s;",cname);
		linefeed(h); fprintf(h,"\tinstance->%s();",_ON_SHOW);
		linefeed(h); fprintf(h,"\tresult = instance->%s();",_ON_GETFOCUS);
		linefeed(h); fprintf(h,"\tinstance->%s();",_ON_LOSEFOCUS);
		linefeed(h); fprintf(h,"\tinstance->%s();",_ON_HIDE);
		linefeed(h); fprintf(h,"\tdelete instance;");
		linefeed(h); fprintf(h,"\treturn(0);");
		linefeed(h); fprintf(h,"}");
		linefeed(h);
		}
	return;
}

private	void	export_cpp_formhead( FILE * h, char * cname )
{

	cpp_banner(h,cname);

	c_include(h,"visual.h");

	if ( Context.Form->dependance)
		c_dependance(h,Context.Form->dependance);

	linefeed(h);
	fprintf(h,"class\t%s : visual_container {",cname);
	linefeed(h);
	fprintf(h,"public:");
	linefeed(h);	define_cpp_instance(h,cname);
	linefeed(h );	fprintf(h,"\t%s();",cname);
	linefeed(h );	fprintf(h,"\t~%s();",cname);
	linefeed(h );	fprintf(h,"\tvoid %s();",_ON_CREATE);
	linefeed(h );	fprintf(h,"\tvirtual void %s();",_ON_REMOVE);
	linefeed(h );	fprintf(h,"\tvirtual void %s();",_ON_SHOW);
	linefeed(h );	fprintf(h,"\tvirtual void %s();",_ON_HIDE);
	linefeed(h );	fprintf(h,"\tvirtual word %s();",_ON_GETFOCUS);
	linefeed(h );	fprintf(h,"\tvirtual void %s();",_ON_LOSEFOCUS);
	linefeed(h );	fprintf(h,"\tvirtual void %s();",_ON_EVENT);
	linefeed(h);
	fprintf(h,"};");
	linefeed(h);
	return;
}


public	void	export_cpp_page( FILE * h, char * headname )
{
	return;
}

public	void	export_cpp_form( FILE * h, char * headname )
{
	char	*		cname;


	C_Config.generate_program   = Context.Form->isprogram;
	C_Config.generate_overlay   = Context.Form->isoverlay;

	if (!( cname = Context.Form->identifier))
		cname = "visual_component";

	else if (!( *cname ))
		cname = "visual_component";


	if (!( headname ))
		export_cpp_formhead( h,cname );
	else	export_cpp_formbody( h,cname, headname );


	return;
}






