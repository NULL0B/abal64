public 	void	export_c_filebody( FILE * h, char * cname, char * headfile )
{
	char	*	prefix="what";

	switch ( Context.File->filetype ) {
		case	0 : prefix = "ad"; break;
		case	1 : prefix = "sq"; break;
		case	2 : prefix = "si"; break;
		case	3 : prefix = "mc"; break;
		case	4 : prefix = "db"; break;
		default	  : prefix = "xx"; break;
		}

	c_banner(h,cname);

	if ( C_Config.generate_program )
		c_include(h,"<stdio.h>");

	c_include(h,headfile);

	fprintf(h,"int  close_%s()",cname);
	linefeed(h);
	fprintf(h,"{");
	linefeed(h);

		fprintf(h,"\tint  status=0;");
		linefeed(h);

		fprintf(h,"\tvoid * liberate( void * );");
		linefeed(h);

		fprintf(h,"\tif ( %s ) {",cname);
		linefeed(h);

		fprintf(h,"\t\tif ( %s->handle ) ",cname);
		fprintf(h,"{ %s_close(%s->handle); %s->handle = 0; }",prefix,cname,cname);
		linefeed(h);

	switch ( Context.File->filetype ) {
		case	0 :	/* sectorial 	*/
			break;
		case	3 :
			fprintf(h,"\t\tif ( %s->description != (char *) 0 ) ",cname);
			fprintf(h,"{ %s->description = liberate( %s->description ); }",cname,cname);
			linefeed(h);
		case	1 :
		case	2 :
			fprintf(h,"\t\tif ( %s->buffer != (char *) 0 ) ",cname);
			fprintf(h,"{ %s->buffer = liberate( %s->buffer ); }",cname,cname);
			linefeed(h);
		}
	fprintf(h,"\t\t%s = liberate( %s );",cname,cname);
	linefeed(h);
	fprintf(h,"\t\t}");
	linefeed(h);
	fprintf(h,"\treturn(status);");
	linefeed(h);
	fprintf(h,"}");
	linefeed(h);

	linefeed(h);
	fprintf(h,"int  open_%s()",cname);
	linefeed(h);
	fprintf(h,"{");
	linefeed(h);
	fprintf(h,"\tvoid * allocate( int );");
	linefeed(h);
	fprintf(h,"\tif ( %s != (struct %s_file *) 0) { (void) close_%s(); }",
			cname,cname,cname);
	linefeed(h);
	fprintf(h,"\tif (!( %s = allocate( sizeof( struct %s_file ) ) ))",
		cname,cname);
	linefeed(h);
	fprintf(h,"\t\treturn(27);");
	linefeed(h);

	fprintf(h,"\tif (!( %s->filename = allocate( strlen( %c%s%c ) + 1) ))",
		cname,0x0022,Context.File->filename,0x0022);
	linefeed(h);
	fprintf(h,"\t\treturn(27);");
	linefeed(h);
	fprintf(h,"\telse\t{ strcpy(%s->filename,%c%s%c); }",
		cname,0x0022,Context.File->filename,0x0022);
	linefeed(h);

	switch ( Context.File->filetype ) {
		case	0 :	/* sectorial 	*/
			break;
		case	1 :
			fprintf(h,"\tif (!( %s->buffer = allocate((%s->recordsize=%u)) ))",cname,cname,Context.File->recordsize);
			linefeed(h);
			fprintf(h,"\t\treturn(27);");
			linefeed(h);
			break;
		case	3 :
			fprintf(h,"\tif (!( %s->description = allocate( 1024 ) ))",cname);
			linefeed(h);
			fprintf(h,"\t\treturn(27);");
			linefeed(h);
		case	2 :
			fprintf(h,"\tif (!( %s->buffer = allocate(((%s->recordsize=%u) + (%s->indexsize=%u) + 3)) ))",
				cname,cname,Context.File->recordsize,cname,Context.File->indexsize);
			linefeed(h);
			fprintf(h,"\t\treturn(27);");
			linefeed(h);
			fprintf(h,"\telse\t{ %s->primary = (%s->buffer+2); %s->record = (%s->buffer+3+%u); }",
				cname,cname,cname,cname,Context.File->indexsize);
			linefeed(h);
		}

	fprintf(h,"\tif ((!( %s->handle = %s_open(%s->filename,2) ))",
		cname,prefix,cname);
	linefeed(h);
	fprintf(h,"\t&&  (!( %s->handle = %s_create(%s->filename",cname,prefix,cname);
	switch ( Context.File->filetype ) {
		case	1 : 
		case	2 : 
		case	3 : fprintf(h,",%u",Context.File->recordsize); break;
		}	
	switch ( Context.File->filetype ) {
		case	2 : 
		case	3 : fprintf(h,",%u",Context.File->indexsize); break;
		}	
	fprintf(h,") ))) { return( (%s->status = err_val) ); }",cname);
	linefeed(h);
	fprintf(h,"\telse\t{ return( (%s->status = 0) ); }",cname);
	linefeed(h);
	fprintf(h,"}");
	linefeed(h);
	return;
}

public 	void	export_c_filehead( FILE * h, char * cname )
{

	c_banner(h,cname);

	c_include(h,"database.h");

	if ( Context.File->dependance)
		c_dependance(h,Context.File->dependance);

	linefeed(h);
	fprintf(h,"struct\t%s_file { ",cname);
	linefeed(h);
	fprintf(h,"\tchar *\tfilename;");
	linefeed(h);
	fprintf(h,"\tint\tstatus;");
	linefeed(h);
	fprintf(h,"\tint\thandle;");
	linefeed(h);
	switch ( Context.File->filetype ) {
		case	0 :	/* sectorial 	*/
			fprintf(h,"\tlong\toffset;");
			linefeed(h);
			fprintf(h,"\tchar\tbuffer[256];");
			linefeed(h);
			break;

		case	1 :	/* sequential	*/
			fprintf(h,"\tlong\tnumber;");
			linefeed(h);
			fprintf(h,"\tchar *\tbuffer;");
			linefeed(h);
			break;

		case	3 :	/* misam 	*/
			fprintf(h,"\tchar *\tdescription;");
			linefeed(h);
		case	2 :	/* isam 	*/
			fprintf(h,"\tint\tindexsize;");
			linefeed(h);
			fprintf(h,"\tint\trecordsize;");
			linefeed(h);
			fprintf(h,"\tchar *\tprimary;");
			linefeed(h);
			fprintf(h,"\tchar *\trecord;");
			linefeed(h);
			fprintf(h,"\tchar *\tbuffer;");
			linefeed(h);
			break;
		case	4 :	/* database 	*/
			fprintf(h,"\t	int    files;");
			break;
		}


	linefeed(h);
	fprintf(h,"} * %s = (struct %s_file *) 0;",cname,cname);
	linefeed(h);
	return;
}

public 	void	export_c_file( FILE * h, char * headname )
{
	char	*		cname;

	C_Config.generate_program   = Context.File->program;
	C_Config.generate_overlay   = Context.File->overlay;

	if (!( cname = Context.File->identifier))
		C_Config.cname = "file_component";

	else if (!( *cname ))
		C_Config.cname = "file_component";

	set_c_form_input( Context.Form );
	set_c_form_error( Context.Form );

	if (!( headname ))
		export_c_filehead( h,cname );
	else	export_c_filebody( h,cname, headname );

	return;
}


