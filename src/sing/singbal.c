
private	void	abal_frame(FILE * handle, int item )
{
	fprintf(handle,"\tFor l = 1 to widget%u(4)\r\n",item);
	fprintf(handle,"\t\tif ( l = 1 )\r\n");
		fprintf(handle,
			"\t\t\tPrint=1:Tab(widget%u(1),widget%u(2)+l-1),Chr$(/da),Gener(widget%u(3)-2,Chr$(/C4)),Chr$(/bf)\r\n",
				item,item,item,item);
	fprintf(handle,"\t\telse :: if ( l = widget%u(4))\r\n",item);
		fprintf(handle,
			"\t\t\tPrint=1:Tab(widget%u(1),widget%u(2)+l-1),Chr$(/c0),Gener(widget%u(3)-2,Chr$(/C4)),Chr$(/d9)\r\n",
				item,item,item,item);

	fprintf(handle,"\t\t\telse\r\n",item);
	fprintf(handle,
		"\t\t\tPrint=1:Tab(widget%u(1),widget%u(2)+l-1),Chr$(/b3),",
			item,item);
	fprintf(handle,
		"Tab(widget%u(1)+widget%u(3)-1,widget%u(2)+l-1),Chr$(/b3)\r\n",
			item,item,item);

	fprintf(handle,"\t\t\tendif\r\n",item);
	fprintf(handle,"\t\tendif\r\n",item);
	fprintf(handle,"\tNext l\r\n");
}

private	void	generate_show( FILE * handle,struct form_item * iptr, int item )
{
	switch ((iptr->Contents.style&_FRAME_TYPE)) {
		case	_FILL_FRAME	:
			fprintf(handle,"\tFor l = 1 to widget%u(4)\r\n",item);
			fprintf(handle,
				"\t\tPrint=1:Tab(widget%u(1),widget%u(2)+l-1),Paint(widget%u(5),widget%u(5)),Space(widget%u(3))\r\n",
					item,item,item,item,item);
			fprintf(handle,"\tNext l\r\n");
		case	_TEXT_FRAME	:
			break;
		case	_INSET_FRAME	:
		case	_OUTSET_FRAME	:
		case	_GROOVE_FRAME	:
		case	_RIDGE_FRAME	:
		case	_EDIT_FRAME	:
		case	_SELECT_FRAME	:
		case	_LINE_FRAME	:
		case	_IMAGE_FRAME	:
		case	_BUTTON_FRAME	:
		case	_CHECK_FRAME	:
		case	_SWITCH_FRAME	:
		case	_GRAAPH_FRAME	:
		case	_RADIO_FRAME	:
		case	_WINDOW_FRAME	:
		case	_TAB_FRAME	:
			abal_frame(handle,item);
		}
	switch ((iptr->Contents.style&_FRAME_TYPE)) {
		case	_TEXT_FRAME	:
			fprintf(handle,
				"\t\t\tPrint=1:Tab(widget%u(1),widget%u(2)),Paint(widget%u(5),widget%u(6)),string%u\r\n",
					item,item,item,item,item);
			break;
		case	_SWITCH_FRAME	:
		case	_GRAPH_FRAME	:
		case	_CHECK_FRAME	:
			fprintf(handle,
				"\t\t\tPrint=1:Tab(widget%u(1)+1,widget%u(2)+1),Paint(widget%u(1)),string%u\r\n",
					item,item,item,item);
			break;
		case	_BUTTON_FRAME	:
			fprintf(handle,
				"\t\t\tPrint=1:Tab(widget%u(1)+1,widget%u(2)+1),Paint(widget%u(1)),string%u\r\n",
					item,item,item,item);
			break;
		case	_RADIO_FRAME	:
			fprintf(handle,
				"\t\t\tPrint=1:Tab(widget%u(1)+1,widget%u(2)+1),Paint(widget%u(1)),string%u\r\n",
					item,item,item,item);
			break;
		case	_TAB_FRAME	:
		case	_WINDOW_FRAME	:
			fprintf(handle,
				"\t\t\tPrint=1:Tab(widget%u(1)+1,widget%u(2)+1),Paint(widget%u(1)),string%u\r\n",
					item,item,item,item);
			break;
		}
	return;
}

private	void	generate_init( FILE * handle,struct form_item * iptr, int item )
{
	int	c,l,nc,nl;
	int	fw;
	int	fh;

	if (!(fw = (Context.DeskTop.w/80)) )
		return;
	if (!(fh = (Context.DeskTop.h/24)) )
		return;

	c = ((iptr->Contents.x / fw)+1);
	l = ((iptr->Contents.y / fh)+1);
	nc = ((iptr->Contents.w / fw)+1);
	nl = ((iptr->Contents.h / fh)+1);

	fprintf(handle,"\twidget%u(1)=%u :: widget%u(2)=%u\r\n",item,c,item,l);
	fprintf(handle,"\twidget%u(3)=%u :: widget%u(4)=%u\r\n",item,nc,item,nl);

	switch ((iptr->Contents.style&_FRAME_TYPE)) {
		case	_FILL_FRAME	:
			fprintf(handle,"\twidget%u(5)=%u \r\n",item,iptr->Contents.colour);
			break;
		case	_TEXT_FRAME	:
		case	_BUTTON_FRAME	:
		case	_CHECK_FRAME	:
		case	_SWITCH_FRAME	:
		case	_GRAPH_FRAME	:
		case	_RADIO_FRAME	:
		case	_TAB_FRAME	:
		case	_WINDOW_FRAME	:
			fprintf(handle,"\twidget%u(6)=%u \r\n",item,(iptr->Contents.colour>>8)&0x000F);
			fprintf(handle,"\twidget%u(5)=%u \r\n",item,iptr->Contents.colour&0x000F);
			fprintf(handle,"\tstring%u=%c%s%c\r\n",item,0x0022,iptr->Contents.payload,0x0022);
			break;

		}
	return;
}

private	void	generate_dcl( FILE * handle, struct form_item * iptr, int item )
{
	switch ((iptr->Contents.style&_FRAME_TYPE)) {
		case	_FILL_FRAME	:
			fprintf(handle,";** frame \r\nDcl widget%u%%(5)\r\n",item);
			break;
		case	_INSET_FRAME	:
			fprintf(handle,";** inset \r\nDcl widget%u%%(4)\r\n",item);
			break;

		case	_OUTSET_FRAME	:
			fprintf(handle,";** outset\r\nDcl widget%u%%(4)\r\n",item);
			break;

		case	_GROOVE_FRAME	:
			fprintf(handle,";** groove\r\nDcl widget%u%%(4)\r\n",item);
			break;

		case	_RIDGE_FRAME	:
			fprintf(handle,";** ridge \r\nDcl widget%u%%(4)\r\n",item);
			break;

		case	_SELECT_FRAME	:
			fprintf(handle,";** edit\r\nDcl widget%u%%(4)\r\n",item);
			break;

		case	_EDIT_FRAME	:
			fprintf(handle,";** edit\r\nDcl widget%u%%(4)\r\n",item);
			break;

		case	_TEXT_FRAME	:
			fprintf(handle,";** text \r\nDcl widget%u%%(6)\r\n",item);
			fprintf(handle,"Dcl string%u$=%u\r\n",item,iptr->Contents.size);
			break;

		case	_LINE_FRAME	:
			fprintf(handle,";** frame \r\n");
			break;

		case	_IMAGE_FRAME	:
			fprintf(handle,";** image \r\nDcl widget%u%%(4)\r\n",item);
			fprintf(handle,"Dcl string%u$=%u\r\n",item,iptr->Contents.size);
			break;

		case	_BUTTON_FRAME	:
			fprintf(handle,";** button \r\nDcl widget%u%%(6)\r\n",item);
			fprintf(handle,"Dcl string%u$=%u\r\n",item,iptr->Contents.size);
			break;

		case	_CHECK_FRAME	:
			fprintf(handle,";** check  \r\nDcl widget%u%%(6)\r\n",item);
			fprintf(handle,"Dcl string%u$=%u\r\n",item,iptr->Contents.size);
			break;
		case	_SWITCH_FRAME	:
			fprintf(handle,";** switch \r\nDcl widget%u%%(6)\r\n",item);
			fprintf(handle,"Dcl string%u$=%u\r\n",item,iptr->Contents.size);
			break;
		case	_GRAPH_FRAME	:
			fprintf(handle,";** graph \r\nDcl widget%u%%(6)\r\n",item);
			fprintf(handle,"Dcl string%u$=%u\r\n",item,iptr->Contents.size);
			break;

		case	_RADIO_FRAME	:
			fprintf(handle,";** radio \r\nDcl widget%u%%(6)\r\n",item);
			fprintf(handle,"Dcl string%u$=%u\r\n",item,iptr->Contents.size);
			break;

		case	_TAB_FRAME	:
			fprintf(handle,";** tabpage \r\nDcl widget%u%%(6)\r\n",item);
			fprintf(handle,"Dcl string%u$=%u\r\n",item,iptr->Contents.size);
			break;

		case	_WINDOW_FRAME	:
			fprintf(handle,";** window \r\nDcl widget%u%%(6)\r\n",item);
			fprintf(handle,"Dcl string%u$=%u\r\n",item,iptr->Contents.size);
			break;

		}
	return;
}

public	void	export_bal_menu( FILE * handle )
{
	return;
}

public	void	export_bal_form( FILE * handle )
{
	struct form_item * iptr;
	int	item=0;

	Abal_Config.generate_overlay = Context.Form->isoverlay;
	Abal_Config.generate_program = Context.Form->isprogram;

	fprintf(handle,"Program %c %c\r\n",0x0022,0x0022);

	fprintf(handle,"Dcl x%%,y%%,c%%,l%%,nc%%,nl%%\r\n");

	for (	iptr=Context.Form->first,item=1; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next, item++ )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	generate_dcl(handle,iptr,item);
		}

	fprintf(handle,"\r\nSegment 0\r\n");

	fprintf(handle,"\tgosub &oninit\r\n");
	fprintf(handle,"\tgosub &onshow\r\n");
	fprintf(handle,"\twait 10\r\n");
	fprintf(handle,"\tstop\r\n");

	fprintf(handle,"\r\n&oninit\r\n");
	for (	iptr=Context.Form->first,item=1; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next, item++ )  {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	generate_init(handle,iptr,item);
		}

	fprintf(handle,"\treturn\r\n");


	fprintf(handle,"\r\n&onshow\r\n");
	for (	iptr=Context.Form->first,item=1; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next, item++ ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else	generate_show(handle,iptr,item);
		}

	fprintf(handle,"\treturn\r\n");

	fprintf(handle,"\r\nEseg 0\r\n");
	fprintf(handle,"End\r\n");
	return;
}











