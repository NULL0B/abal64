public	void	generate_java( FILE * h,struct form_item * iptr )
{
	switch ((iptr->Contents.style&_FRAME_TYPE)) {
		case	_FILL_FRAME	:
			break;
		case	_INSET_FRAME	:
			break;

		case	_OUTSET_FRAME	:
			break;

		case	_GROOVE_FRAME	:
			break;

		case	_RIDGE_FRAME	:
			break;

		case	_SELECT_FRAME	:
			break;

		case	_EDIT_FRAME	:
			break;

		case	_TEXT_FRAME	:
			break;

		case	_LINE_FRAME	:
			break;

		case	_IMAGE_FRAME	:
			break;

		case	_BUTTON_FRAME	:
			break;

		case	_WINDOW_FRAME	:
			break;

		case	_TAB_FRAME	:
			break;

		}
	return;
}

public	void	export_java_menu( FILE * h )
{
	return;
}

public	void	export_java_form( FILE * h )
{
	struct form_item * iptr;

	for (	iptr=Context.Form->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) 
		generate_java(h,iptr);

	return;
}












