private	void	c_scrollbar_driver( FILE * h, struct form_item * iptr )
{
	char	*	eptr;
	int		l;
	char 	*	mode;
	char 	*	item;
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

	fprintf(h,"%s %s%s(%s) : %c ",
		abal_keyword_proc,
		iptr->Contents.name,method_event,
		optr,0x0025);
		linefeed(h);
	indent(h,1);
	fprintf(h,"int at%s=visual_event(%u);",mode,item);
	fprintf(h,"int to%s=visual_event(%u);",mode,item);
	linefeed(h); indent(h,1); fprintf(h,"do {");
	linefeed(h); indent(h,2); fprintf(h,"while(visual_getch() != 256);");
	linefeed(h); indent(h,2); fprintf(h,"if ((to%s = visual_event(%u)) > at%s) {",mode,item,mode);
	linefeed(h); indent(h,3); 
	fprintf(h,"value_%s += (to%s-at%s);",iptr->Contents.name,mode,mode);
	linefeed(h); indent(h,3); 
	fprintf(h,"if (value_%s > (max_%s-limit_%s)) ",iptr->Contents.name,iptr->Contents.name,iptr->Contents.name);
	linefeed(h); indent(h,4); fprintf(h,"value_%s = (max_%s-limit_%s)",iptr->Contents.name,iptr->Contents.name,iptr->Contents.name);
	linefeed(h); indent(h,3); fprintf(h,"}");
	linefeed(h); indent(h,2); fprintf(h,"else if (value_%s > (at%s-to%s))",iptr->Contents.name,mode,mode);
	linefeed(h); indent(h,3); fprintf(h,"value_%s -= (at%s-to%s);",iptr->Contents.name,mode,mode);
	linefeed(h); indent(h,3); fprintf(h,"else value_%s = 0;",iptr->Contents.name);

	if (((eptr = iptr->Contents.events->on_event ) != (char *) 0)
	&&  (( l=strlen(eptr)) > 0 ))
		c_method_body(h,eptr,l,iptr->Contents.name,1);
	else	{
		/* standard payload : activate global show */
		indent(h,1);
		fprintf(h,"Status = %s%s(%s)",Abal_Config.cname,method_show,optr);
		}
	linefeed(h);
	linefeed(h); indent(h,2); fprintf(h,"if (visual_event(2) == _MIMO_LEFT) at%s = to%s;",mode,mode);
	linefeed(h); indent(h,1); fprintf(h,"while (visual_event(1) != _MIMO_UP);");
	linefeed(h); indent(h,1); fprintf(h,"return(-1);");
	linefeed(h); fprintf(h,"}");
	linefeed(h);
	return;
}


