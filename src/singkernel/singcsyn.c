private	char *	__visual_signature="visual_signature";
private	char *	__visual_transferin="visual_transferin";
private	char *	__visual_transferout="visual_transferout";
private	char *	__visual_palette="visual_palette";
private	char *	__visual_font="visual_font";
private	char *	__visual_initialise="visual_initialise";
private	char *	__visual_liberate="visual_liberate";
private	char *	__visual_buffer="visual_buffer";
private	char *	__visual_drop="visual_drop";
private	char *	__visual_get="visual_buffer_get";
private	char *	__visual_put="visual_buffer_put";
private	char *	__visual_freeze="visual_freeze";
private	char *	__visual_thaw="visual_thaw";
private	char *	__visual_window="visual_window";
private	char *	__visual_tabpage="visual_tabpage";
private	char *	__visual_text="visual_text";
private	char *	__visual_button="visual_button";
private	char *	__visual_check="visual_check";
private	char *	__visual_radio="visual_radio";
private	char *	__visual_edit="visual_edit";
private	char *	__visual_scrollbar="visual_scrollbar";
private	char *	__visual_relief="visual_relief";
private	char *	__visual_filzone="visual_filzone";
private	char *	__visual_frame="visual_frame";
private	char *	__visual_select="visual_select";
private	char *	__visual_progress="visual_progress";
private	char *	__visual_image="visual_image";
private	char *	__visual_graph="visual_graph";
private	char *	__visual_switch="visual_switch";
private	char *	__visual_table="visual_table";
private	char *	__visual_line="visual_line";
private	char *	__visual_viewport="visual_viewport";

public	void	c_comment( FILE * handle, char * vptr , int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"/* %s */",vptr);
	linefeed(handle);
	return;
}

public	void	c_if( FILE * handle , char * expression, int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"if ( %s ) {",expression);
	linefeed(handle);
	return;
}

public	void	c_else( FILE * handle , int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"} else {");
	linefeed(handle);
	return;
}

public	void	c_endif( FILE * handle , int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"}");
	linefeed(handle);
	return;
}

public	void	c_return( FILE * handle, char * vptr , int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"return(%s);",vptr);
	linefeed(handle);
	return;
}

public	void	c_case( FILE * handle, int value, int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"case\t0x%x :",value);
	linefeed(handle);
	return;
}

public	void	c_break( FILE * handle, int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"break;");
	linefeed(handle);
	return;
}

public	void	c_continue( FILE * handle, int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"continue;");
	linefeed(handle);
	return;
}

public	void	c_default( FILE * handle, int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"default :");
	linefeed(handle);
	return;
}

public 	void	c_include( FILE * handle, char * sptr )
{
	fprintf(handle,"#include ");
	if (( *sptr != '<' )
	&&  ( *sptr != '"' ))
		quoted_string(handle,sptr);
	else	fprintf(handle,"%s",sptr);
	linefeed(handle);
	return;
}


