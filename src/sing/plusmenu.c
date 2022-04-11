#ifndef	_plusmenu_c
#define _plusmenu_c

private	void generate_menu_instance(FILE * h) 
{
	int	items=0;
	struct	menu_control * mptr=Context.Menu;
	struct menu_option * iptr;

	fprintf(h,"public visual_menu %s(%u;%u;%u;%u;%u;%u)\r\n",
			"Menu",
			mptr->x,
			mptr->y,
			mptr->w,
			mptr->h,
			mptr->nature,
			mptr->style);
			linefeed(h);

	for (	iptr=Context.Menu->first;  
		iptr != (struct menu_option *) 0; 
		iptr = iptr->next ) {
		fprintf(h,"public visual_menu_option Option%u(%u;%u;%u;%u",
			++items,
			iptr->x,iptr->y,iptr->w,iptr->h);
		aplus_string_parameter(h,iptr->label);
		aplus_length_parameter(h,strlen(iptr->label));
		aplus_string_parameter(h,iptr->hint);
		aplus_length_parameter(h,strlen(iptr->hint));
		fprintf(h,")");
		linefeed(h);
		}
}


private	void generate_menu_create(FILE * h) 
{
	int	items=0;
	struct menu_option * iptr;
	fprintf(h,"\r\npublic constructor function on_create:\r\n");
	for (	iptr=Context.Menu->first;  
		iptr != (struct menu_option *) 0; 
		iptr = iptr->next ) {
		fprintf(h,"\tMenu.add_member(Option%u)",++items);
		linefeed(h);
		}
	fprintf(h,"\tEnd\r\n");
	return;
}

private	void generate_menu_remove(FILE * h) 
{
	fprintf(h,"%s %s destructor %s on_remove:",
		keyword_public,keyword_overload,keyword_function);
	aplus_end(h);
	return;
}
private	void generate_menu_show(FILE * h) 
{
	aplus_overload_function(h,"on_show");
	linefeed(h);
		indent(h,1);
		fprintf(h,"Menu.on_show");
		linefeed(h);
	aplus_end(h);
	return;
}

private	void generate_menu_hide(FILE * h) 
{
	aplus_overload_function(h,"on_hide");
	linefeed(h);
	aplus_end(h);
	return;
}

private	void generate_menu_getfocus(FILE * h) 
{
	aplus_overload_function(h,"on_get_focus");
	linefeed(h);
		indent(h,1);
		fprintf(h,"Menu.on_get_focus");
		linefeed(h);
	aplus_end(h);
	return;
}

private	void generate_menu_losefocus(FILE * h)
{
	linefeed(h);
	fprintf(h,"%s %s %s on_lose_focus:",keyword_public,keyword_overload,keyword_function);
	linefeed(h);
	aplus_end(h);
	return;
}

public	void	export_aplus_menu( FILE * h )
{
	struct form_item * iptr;
	struct form_item * wptr=(struct form_item *) 0;
	int	i;
	int			members=0;
	char	*		fname;
	int			focus_items=0;
	int			focus_item=0;
	char	*		cname;

	Abal_Config.generate_overlay = Context.Menu->isoverlay;
	Abal_Config.generate_program = Context.Menu->isprogram;

	if ( Abal_Config.generate_program ) {
		fprintf(h,"\r\n#include pragmas\r\n");
		fprintf(h,"\r\n#use visual\r\n");
		}

	if (!( cname = Context.Menu->identifier ))
		cname = "visual_menu";
	else if (!( *cname ))
		cname = "visual_menu";

	fprintf(h,"\r\n#class\t\t%s\r\n",cname);

		fprintf(h,"(public visual_collection)\r\n");

		fprintf(h,"private visual_palette colourmap(%c%s%c;%u)\r\n",
			0x0022,SingConf->palette,0x0022,strlen( SingConf->palette ));

		for (i=FONT_MIN; i< FONT_MAX; i++ ) {
			if (!(fname = font_name[i]))
				continue;
			else	fprintf(h,"private visual_font font%u(%c%s%c;%u)\r\n",
					i,0x0022,fname,0x0022,strlen(fname));
			}

		generate_menu_instance(h);
		generate_menu_create(h);
		generate_menu_remove(h);
		generate_menu_show(h);
		generate_menu_hide(h);
		generate_menu_getfocus(h);
		generate_menu_losefocus(h);

	fprintf(h,"\r\n#endclass\t\t%s\r\n",cname);

	if ( Abal_Config.generate_program ) {
		if ( Abal_Config.generate_overlay ) {
			aplus_overlay_loader(h);
			fprintf(h,"\r\nProgram Overlay %s_loader Sing End\r\n",cname);
			}
		else	{
			fprintf(h,"\r\n#class %s_application\r\n",cname);
			fprintf(h,"\r\nPublic %s vA\r\n",cname);
			fprintf(h,"\r\npublic inline constructor on_create:\r\n");
			fprintf(h,"\tvA.on_show\r\n");
			fprintf(h,"\tvA.on_get_focus\r\n");
			fprintf(h,"\r\n#endclass\r\n");
			fprintf(h,"\r\nProgram %s_application Sing End\r\n",cname);
			}
		}
	else if ( Abal_Config.generate_overlay ) {
		fprintf(h,"\r\nModule %s Sing End\r\n",cname);
		}
	return;
}

#endif	/* _plusmenu_c */
	/* ----------- */


