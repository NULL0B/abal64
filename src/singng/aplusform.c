public	void	export_aplus_form( FILE * h )
{
	struct form_item * iptr;
	struct form_item * wptr=(struct form_item *) 0;
	int	i;
	int			members=0;
	char	*		fname;
	int			focus_items=0;
	int			focus_item=0;
	char	*		cname;

	abal_production_type();

	/* Generate File Banner Block */
	production_banner(h,_GENERATE_ABAL,Context.Form->loadname,Context.Form->prodname);

	if ( Abal_Config.generate_program ) {
		fprintf(h,"#include pragmas");
		linefeed(h);
		fprintf(h,"#use visual");
		linefeed(h);
		}

	if ( Context.Form->dependance)
		aplus_dependance(h,Context.Form->dependance);

	if (!( cname = Context.Form->identifier ))
		cname = "visual_component";
	else if (!( *cname ))
		cname = "visual_component";

	linefeed(h); fprintf(h,"#class\t\t%s",cname); linefeed(h);

		fprintf(h,"(%s visual_object)",keyword_public);
		linefeed(h);
		fprintf(h,"%s dcl focus_item",keyword_private);
		linefeed(h);
		fprintf(h,"%s dcl focus_items",keyword_private);
		linefeed(h);
		fprintf(h,"%s visual_palette colourmap(%c%s%c;%u)",
			keyword_private,
			0x0022,_STANDARD_RGB,0x0022,strlen( _STANDARD_RGB ));
		linefeed(h);

		for (i=FONT_MIN; i< FONT_MAX; i++ ) {
			if (!(fname = font_name[i]))
				continue;
			else	{
				fprintf(h,"%s visual_font font%u(%c%s%c;%u)",
					keyword_private,
					i,0x0022,fname,0x0022,strlen(fname));
				linefeed(h);
				}
			}

		wptr=(struct form_item *) 0;
		for (	iptr=Context.Form->first; 
			iptr != (struct form_item *) 0; 
			iptr = iptr->next ) {
			if ((!( wptr ))
			&&  ((iptr->Contents.style&_FRAME_TYPE)==_WINDOW_FRAME))
				wptr = iptr;
			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			else	generate_aplus(h,iptr,++members);
	
			iptr->Contents.focus = ++focus_items;
			
			}


		wptr = generate_on_create( h, wptr, focus_items );

		generate_on_remove( h, wptr );
	
		generate_on_show(h,wptr);

		generate_on_hide( h );

		generate_on_get_focus(h,wptr,focus_items);

		generate_on_lose_focus(h,wptr);

		aplus_event_methods(h,wptr);

	linefeed(h);
	fprintf(h,"#endclass\t\t%s",cname);
	linefeed(h);

	if ( Abal_Config.generate_program ) {
		if ( Abal_Config.generate_overlay ) {
			linefeed(h);
			fprintf(h,"Program Overlay %s Sing End",cname);
			}
		else	{
			linefeed(h);
			fprintf(h,"#class %s_application",cname);
			linefeed(h);
			linefeed(h);
			fprintf(h,"%s %s vA",keyword_public,cname);
			linefeed(h); linefeed(h);
			fprintf(h,"%s inline constructor on_create:",keyword_public);
			linefeed(h);
			indent(h,1);
			fprintf(h,"vA.on_show");
			linefeed(h);
			indent(h,1);
			fprintf(h,"vA.on_get_focus");
			linefeed(h);
			aplus_end(h);
			linefeed(h);
			fprintf(h,"#endclass");
			linefeed(h);
			linefeed(h);
			fprintf(h,"Program %s_application Sing End",cname);
			linefeed(h);
			}
		}
	else if ( Abal_Config.generate_overlay ) {
		linefeed(h);
		fprintf(h,"Module %s Sing End",cname);
		}
	linefeed(h);
	abal_comment(h,"end of file",0);
	linefeed(h);
	return;
}


