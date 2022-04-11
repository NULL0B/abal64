public  void	export_c_menu( FILE * h )
{
	char	*	fname;
	struct form_item * iptr;
	int	i;
	char	* cname;
	int	members=0;
	C_Config.generate_program   = Context.Menu->isprogram;
	C_Config.generate_overlay   = Context.Menu->isoverlay;
	C_Config.page_control       = 0;

	if (!( cname = Context.Menu->identifier ))
		cname = "dialog_box";
	else if (!( *cname ))
		cname = "dialog_box";

	/* Generate Inclusions for Program */
	/* ------------------------------- */
	if ( C_Config.generate_program ) {

		cname = "on";
		
		}

	c_include(h,"<stdio.h>");
	c_include(h,"visual.h");

	members = generate_c_menu_structure(h,cname);

	open_c_on_create( h, cname, members );
	fprintf(h,"\treturn(0);");
	linefeed(h); fprintf(h,"}"); linefeed(h);

	/* -------------------- */
	/*	ON _ REMOVE	*/
	/* -------------------- */
	c_signature(h,cname,"remove", members,0 );
	fprintf(h,"\treturn(0);");
	linefeed(h); fprintf(h,"}"); linefeed(h);

	/* -------------------- */
	/*	ON _  SHOW 	*/
	/* -------------------- */
	linefeed(h);
	fprintf(h,"private\tint\t%s_show()",cname);
	linefeed(h); fprintf(h,"{"); linefeed(h);
	fprintf(h,"\treturn(0);");
	linefeed(h); fprintf(h,"}"); linefeed(h);


	/* -------------------- */
	/*	ON _ EVENT 	*/
	/* -------------------- */
	linefeed(h);
	fprintf(h,"private\tint\t%s_event()",cname);
	linefeed(h); fprintf(h,"{"); linefeed(h);
	fprintf(h,"\treturn(0);");
	linefeed(h); fprintf(h,"}"); linefeed(h);

	generate_c_main( h, cname, members, 0 );

	return;
}


