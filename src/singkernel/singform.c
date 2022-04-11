#ifndef	_singform_c
#define	_singform_c

#include <stdio.h>
#include "sing.h"
#include "palet.h"
#include "stdpsu.h"
#include "guimouse.h"
#include "singrel.h"
#include "singpix.h"
#include "allocate.h"
#define	_SYSTEM_IMAGES
#include "genimage.h"
#include "sysimage.h"
#include "stdimage.h"
#include "singlang.h"
#include "singprod.h"
#include "singpage.h"
#include "singtree.h"
#include "singconf.h"

#include "singpal.h"
#include "singbar.h"
#include "singmenu.h"
#include "singtool.h"
#include "singtext.h"
#include "singimg.h"
#include "singdesk.h"
#include "singhtml.h"
#include "singmeth.h"
#include "singmemb.h"
#include "visual.h"

extern	char *	classbuffer;
extern	char	namebuffer[];
extern	struct	screen_control	Context;
extern	char *	font_name[];
extern	char 	LaPaterne[];
extern	char *	VisualMember[];
extern	char *	DataMember[];

extern	int	SystemD;

/*	-------------------------------------------------------		*/
/*	Forward reference Function Prototypes for DOS compilers 	*/
/*	-------------------------------------------------------		*/

public char	*	allocate_string(char *sptr);
public	char *	widget_member_list();
public	char *	data_member_list();
public	char *	normalise_method_text( char * eptr );
private	int	SelectFormWidget( struct form_control * fptr, struct form_item * iptr, int caller );
private	char *	automatic_name( int number );
public	void	set_context_gridlock( int v );
public	void	set_context_gridsize( int v );
public	int	form_parameters(struct form_control * fptr );
private	int	select_Widget(struct form_control * fptr, int x, int y );
public 	struct form_control * load_XmlForm(struct form_control* fptr, char * loadname,int reset, int automatic );

public 	char	workbuffer[1024];

public 	char *	WidgetClass[32] = {
	"fill",		"outset",	"inset",	"ridge",
	"groove",	"edit",		"text",		"image",

	"line",		"button",	"window",	"tabpage",	
	"check",	"radio",	"select",	"form",

	"scroll",	"progress",	"switch",	"graph",

	"data",		"cut",		"move",		"menu",
	"size",		"constant",	"method",	"instance",

	"string",	"integer",	"numeric",	"class"

	};

private	char * 	WidgetTypes[16] = {
	(char *) 0,	(char *) 0,	(char *) 0,	(char *) 0,
	(char *) 0,	(char *) 0,	(char *) 0,	(char *) 0,
	(char *) 0,	(char *) 0,	(char *) 0,	(char *) 0,
	(char *) 0,	(char *) 0,	(char *) 0,	(char *) 0
	};

public	char *	selection_item( int item, char * sptr )
{
	char *	rptr;
	char *	dptr=sptr;
	int	i=0;
	int	c=0;

	while (1) {
		while ( *sptr != 0 )
			if ( *sptr == '|' )
				break;
			else	sptr++;
		if (!( *sptr ))
			break;
		if ( i < item) {
			i++;
			sptr++;
			dptr = sptr;

			}
		else	break;
		}
	if ( i != item )
		return((char *) 0);
	else	{
		c = *sptr;
		*sptr = 0;
		rptr = allocate_string( dptr );
		*sptr = c;
		return( rptr );
		}
}

public	void	release_widget_types()
{
	int	i;
	if ( WidgetTypes[0] ) {
		WidgetTypes[0] = liberate( WidgetTypes[0] );
		for (i=0; i < 16; i++ )
			WidgetTypes[i] = (char *) 0;
		}
	return;
}

public	char *	get_widget_datatype( unsigned int wid )
{
	char	*	sptr;
	int		i;
	if (!( WidgetTypes[0] )) {
		if (!( sptr = allocate_string( WidgetTypeList ) ))
			return((char *) 0);
		for (i=0; i < 16; i++ ) {
			WidgetTypes[i] = sptr;
			while ( *sptr ) {
				if (( *sptr == '|' )
				||  ( *sptr == '+' )) {
					*(sptr++) = 0;
					break;
					}
				else	sptr++;
				}
			if (!( *sptr ))
				break;
			}
		}
	if ( wid < 16 )
		return( WidgetTypes[wid] );
	else	return( (char *) 0 );

}

public	char *	production_languages()
{
	if ( SingConf->expert_user ) 
		return( ProductionLanguages );
	else	return( "Abal|Abal++" );
}

public	char *	get_widget_class( int wid )
{
	return( WidgetClass[(wid  & _FRAME_TYPE)] );
}

//	This function returns a type dependant option list to
//	its caller (the visual widget properties box)
//	 align options, image options or scroll options.

public	char	*	WidgetOptionList(int widget)
{
	switch ( widget ) {
		case	_TAB_FRAME	:
			return( WidgetTabList );
		case	_FORM_FRAME	:
			return( WidgetFormList );
		case	_FILL_FRAME	:
			return( WidgetFillList );
		case	_IMAGE_FRAME	:
			return( WidgetImageList );
		case	_SCROLL_FRAME	:
			return( WidgetScrollList );
		case	_BUTTON_FRAME	:
			return( WidgetButtonList );
		case	_DATA_FRAME	:
			return( WidgetDataList );
		case	_EDIT_FRAME	:
		default			:
			return( WidgetAlignList );
		}
}

public	char	*	WidgetPayload(int widget)
{
	switch ( widget ) {
		case	_WINDOW_FRAME	:
		case	_OUTSET_FRAME	:
		case	_INSET_FRAME	:
		case	_GROOVE_FRAME	:
		case	_RIDGE_FRAME	:
			return( "Title" );
		case	_SELECT_FRAME	:
			return("OptionsList");
		case	_TEXT_FRAME	:
			return("Message");
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
		case	_SWITCH_FRAME	:
		case	_TAB_FRAME	:
			return("Label");
		case	_BUTTON_FRAME	:
			return("Label/Image");
		case	_FORM_FRAME	:
			return("ColumnTitles");
		case	_IMAGE_FRAME	:
			return("Image");
		case	_DATA_FRAME	:
			return("Filename");
		default			:
			return( "Payload" );
		}
}

public	char	*	WidgetMessage(int widget,int item)
{
	if ( item == 0 ) {
		if ( widget == _BUTTON_FRAME ) 
			return("Target");
		else	return("Format");
		}

	switch ( widget ) {
		case	_BUTTON_FRAME	:
			switch ( item ) {
				case	1	: return( "Makefit/Bold");
				case	2	: return( "Underline" );
				case	3	: return( "Coloured" );
				default		: return( "N/A" );
				}
		case	_EDIT_FRAME	:
			switch ( item ) {
				case	1	: return( "Enforce");
				case	2	: return( "Secret");
				case	3	: return( "Ask");
				default		: return( "N/A" );
				}
		case	_PROGRESS_FRAME	:
			switch ( item ) {
				case	1	: return( "Bold" );
				case	2	: return( "Underline" );
				case	3	: return( "Relief" );
				default		: return( "N/A" );
				}
		case	_FORM_FRAME	:
			switch ( item ) {
				case	1	: return( "Enforce");
				case	2	: return( "Underline" );
				case	3	: return( "Relief" );
				default		: return( "N/A" );
				}

		case	_SCROLL_FRAME	:
			switch ( item ) {
				case	1	: return( "Grip" );
				default		: return( "N/A" );
				}
		case	_IMAGE_FRAME	:
			switch ( item ) {
				case	3	: return( "Sprite" );
				case	2	: return( "Quality");
				default		: return( "N/A" );
				}
		case	_WINDOW_FRAME	:
			switch ( item ) {
				case	1	: return( "Exit" );
				case	2	: return( "Help" );
				case	3	: return( "Shadow" );
				case	4	: return( "DragBar" );
				}
		default			:
			switch ( item ) {
				case	1	: return( "Bold" );
				case	2	: return( "Underline" );
				default		: return( "Shadow" );
				}
		}

}


private	int	widget_EventMessage(char * wptr, char * mptr, int items )
{
	if (!( items ))
		strcat(wptr," (");
	else	strcat(wptr,", ");
	strcat(wptr,mptr);
	items++;
	return( items );
}

public	char *	widget_event_messages( struct form_item * iptr, char * wptr )
{
	char *	eptr;
	int	l;
	int	items=0;
	if ( method_is_valid( iptr->Contents.events.on_create))
		items = widget_EventMessage(wptr,"CREATE",items);
	if ( method_is_valid( iptr->Contents.events.on_show))
		items = widget_EventMessage(wptr,"SHOW",items);
	if ( method_is_valid( iptr->Contents.events.on_get_focus))
		items = widget_EventMessage(wptr,"GETFOCUS",items);
	if ( method_is_valid( iptr->Contents.events.on_lose_focus))
		items = widget_EventMessage(wptr,"LOSEFOCUS",items);
	if ( method_is_valid( iptr->Contents.events.on_event))
		items = widget_EventMessage(wptr,"EVENT",items);
	if ( method_is_valid( iptr->Contents.events.on_hide))
		items = widget_EventMessage(wptr,"HIDE",items);
	if ( method_is_valid( iptr->Contents.events.on_remove))
		items = widget_EventMessage(wptr,"REMOVE",items);

	if ( items )
		strcat(wptr,")");

	return( wptr );
}

public	char *	widget_prompt_message( struct form_item * iptr )
{
	char * cptr;
	char * nptr;

	if (!( cptr = get_widget_class( iptr->Contents.style )))
		cptr = "widget";
	if (!( nptr = iptr->Contents.name ))
		nptr = "noname";

	sprintf( workbuffer,"%s %s",cptr,nptr);

	return( widget_event_messages( iptr, workbuffer ) );

}

public	char *	widget_event_message( struct form_item * iptr )
{
	workbuffer[0] = 0;
	return( widget_event_messages( iptr, workbuffer ) );
}

char	*	widget_message(struct treeview * tptr,  struct form_item * iptr )
{
	if (( iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME)
		tptr->state |= _TREE_BOLD;
	else	tptr->state &= ~_TREE_BOLD;

	return( widget_prompt_message( iptr ) );

}

#include "singtype.c"
#include "singimg.c"
#include "singtext.c"
#include "singwind.c"
#include "singbutt.c"
#include "singeve.c"


public	int	use_grid_lock( int v, int adjust, int gridlock )
{
	int	x;

	if ((x = (v % gridlock)) != 0) {
		if ( v > (gridlock/2))
			v = (((v / gridlock)+adjust)*gridlock);
		else	v -= x;
		}

	else if (!( v ))
		v = (gridlock*adjust);

	return(v);
}

public	struct form_item * liberate_Widget( struct form_item * iptr )
{
	int	i;
	if ( iptr ) {
		if ( iptr->Contents.name )
			iptr->Contents.name = liberate( iptr->Contents.name );

		if ( iptr->Contents.payload )
			iptr->Contents.payload = liberate( iptr->Contents.payload );

		if ( iptr->Contents.format )
			iptr->Contents.format = liberate( iptr->Contents.format );

		if ( iptr->Contents.hint )
			iptr->Contents.hint = liberate( iptr->Contents.hint );

		if ( iptr->Contents.stylesheet )
			iptr->Contents.stylesheet = liberate( iptr->Contents.stylesheet );

		drop_event_control( & iptr->Contents.events );

		for (i=0; i < MAXNATLANG; i++ ) {
			if ( iptr->document[i] )
				iptr->document[i] = liberate( iptr->document[i] );
			}

		remove_treenode( iptr->treenode );

		iptr->treenode = liberate_for_treeview( iptr->treenode );

		iptr = liberate( iptr );
		}
	return(iptr );
}

private	void	form_is_outofdate( struct form_control * fptr )
{
	fptr->outofdate = 1;
	Context.OutOfDate |= 1;
	return;
}

#include "singmemb.c"

public	void	prepare_form_fields( struct form_control * fptr, char * nptr )
{
	if ( nptr ) {
		fptr->loadname   = allocate_string( nptr );
		fptr->prodname   = allocate_string( nptr );
		fptr->identifier = allocate_string( nptr );
		switch ( fptr->language ) {
			case	_GENERATE_C	:
				fptr->prodname = enforce_extension(fptr->prodname,C_EXTENSION);
				break;
			case	_GENERATE_CPP	:
				fptr->prodname = enforce_extension(fptr->prodname,CPP_EXTENSION);
				break;
			case	_GENERATE_BAL	:
			case	_GENERATE_ABAL	:
				fptr->prodname = enforce_extension(fptr->prodname,AS_EXTENSION);
				break;
			case	_GENERATE_HTML	:
				fptr->prodname = enforce_extension(fptr->prodname,HTM_EXTENSION);
				break;
			case	_GENERATE_JAVA	:
				fptr->prodname = enforce_extension(fptr->prodname,JAV_EXTENSION);
				break;
			case	_GENERATE_COBOL :
				fptr->prodname = enforce_extension(fptr->prodname,COB_EXTENSION);
				break;
			}
		fptr->identifier = enforce_extension( fptr->identifier, NUL_EXTENSION );
		}
	return;
}

public	struct form_control * allocate_Form(char * nptr)
{
	int	i;
	struct form_control * fptr;
	if (!( fptr = allocate( sizeof( struct form_control ) ) ))
		return( fptr );
	else if (!( fptr->treenode = allocate_for_treeview())) {
		liberate( fptr );
		return((struct form_control *) 0);
		}

	fptr->method_count	= 0;
	fptr->StandardInput		= 
	fptr->StandardError		=
	fptr->rootmethod	=
	fptr->lastmethod	= (struct forms_method*) 0;

	fptr->member_count	= 0;
	fptr->rootmember	=
	fptr->lastmember	= (struct forms_data_member*) 0;

	fptr->abal.flags	= 0;
	fptr->abal.values	= 0;
	fptr->abal.diezemem	= 0;
	fptr->abal.diezefiles	= 0;
	fptr->abal.diezestack	= 0;
	fptr->abal.diezeheap	= 0;
	fptr->abal.tokensize	= 0;
	fptr->abal.labelsize	= 0;
	fptr->abal.pragmafile	= (char *) 0;
	fptr->argvlen		= 24;
	fptr->argvcount		= 10;

	fptr->host              = (void *) 0;
	fptr->Buffer.value      = (STDPSUPTR) 0;
	fptr->Buffer.x		=
	fptr->Buffer.y		=
	fptr->Buffer.width	=
	fptr->Buffer.height	= 0;
	fptr->outofdate   = 0;
	fptr->image	  = (struct standard_image *) 0;

	for ( i=0; i < MAXNATLANG; i++) { fptr->document[i] = (char *) 0; }

	fptr->dependance  =
	fptr->stylesheet  =
	fptr->clearscreen =
	fptr->prodname    =
	fptr->loadname    = (char *) 0;
	fptr->loadstamp   =
	fptr->savestamp   = 0L;
	fptr->construction=
	fptr->identifier  = (char *) 0;

	connect_treenode(fptr->treenode,TREE_FORM,fptr);

	fptr->font      = 1;
	fptr->gridlock	= fptr->gridsize  = 0x0A0A;
	fptr->foreground= 27;
	fptr->background= 28;
	fptr->thickness	= 1;
	fptr->using	= _MOVE_FRAME;

	fptr->doctool     = _TEXT_TOOL;
	fptr->objects	  =
	fptr->page_number =
	fptr->pages	  =
	fptr->focus	  =
	fptr->items       = 0;
	fptr->formflags   = ( _FORM_TYPE_DIALOG | _FORM_ESC | _FORM_DOWN | _FORM_PAGE_DOWN |_FORM_UP | _FORM_PAGE_UP | _FORM_TAB | _FORM_INTERNATIONAL );
	fptr->mimoflags   = (_MIMO_SEND_LEFT|_MIMO_SEND_RIGHT|_MIMO_DOWN|_MIMO_UP|_MIMO_INTERRUPT);

	fptr->isprogram   = 1;	/* production of a program		*/
	fptr->isoverlay   = 0;	/* production of a dll or overlay	*/
	fptr->ispopup     = 0;	/* production of a dll or overlay	*/
	fptr->isdynamic   = 0;	/* production of a dll or overlay	*/
	fptr->natlang	  = 0;	/* default : english production		*/

	fptr->language    = production_language();
	fptr->display     = 0;	

	fptr->top   =
	fptr->first = fptr->active  = 
	fptr->last  = fptr->current = (struct form_item*) 0;

	prepare_form_fields( fptr, nptr );

	fptr->printout.TopMargin=0;
	fptr->printout.BottomMargin=0;
	fptr->printout.LeftMargin=0;
	fptr->printout.RightMargin=0;
	fptr->printout.ZoneWidth=0;
	fptr->printout.ZoneHeight=0;
	fptr->printout.Layout=SingConf->layout;
	fptr->printout.Preview=1;
	fptr->printout.Alignment=0;
	fptr->printout.PaperType=SingConf->papersize;
	fptr->printout.PrintResolution=SingConf->density;
	fptr->printout.PageHead=(char *) 0;
	fptr->printout.PageFoot=(char *) 0;
	fptr->printout.DeviceName=allocate_string("$ArgV(1)");
	fptr->printout.DriverName=allocate_string("$ArgV(2)");
	fptr->printout.TitleOpt=1;	
	fptr->printout.FeedOpt=SingConf->pagefeed;
	fptr->printout.NumbOpt=1;
	return( fptr );

}

public 	void	add_Widget(
		struct form_control * fptr,
		struct form_item * iptr, int atend)
{
	iptr->parent = fptr;
	iptr->previous = iptr->next = (struct form_item*) 0;

	if (( atend )
	||  (!( fptr->current ))) {
		if ( fptr->last )
			fptr->last->next = iptr;
		else	fptr->first = iptr;
		iptr->previous = fptr->last;
		fptr->last = fptr->current = iptr;
		add_treenode( fptr->treenode, iptr->treenode );
		}
	else	{
		if ( fptr->current )
			append_treenode( fptr->treenode,fptr->current->treenode, iptr->treenode );
		else	add_treenode( fptr->treenode, iptr->treenode );
		if (!(iptr->next = fptr->current->next))
			fptr->last = iptr;
		else	iptr->next->previous = iptr;
		iptr->previous = fptr->current;
		fptr->current->next = iptr;
		fptr->current = iptr;
		}
	connect_treenode(iptr->treenode,TREE_WIDGET, iptr );
	return;
}

public	int	is_named_widget( struct form_item * iptr )
{
	char	*	aptr;
	char	*	tptr;
	char	*	nptr;
	int		i;
	
	if (!( nptr = iptr->Contents.name ))
		return(0);
	else	{
		/* if the item name is not auto prefixed */
		/* ------------------------------------- */
		for ( 	aptr=_AUTO_PREFIX,i=0;
			i < 4;
			i++ )
			if (*(nptr+i) != *(aptr+i))
				return(1);
		return(0);
		}
}

private	void	renumerate_form( struct form_control * fptr )
{
	int	number=1;
	struct form_item * iptr;
	char	*	nptr;
	for (	number=++Context.numbering,
		iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ( is_named_widget( iptr ) )
			continue;
		if ((nptr = iptr->Contents.name) != (char *) 0 )
			liberate( nptr );
		iptr->Contents.name =  automatic_name(number++);
		form_is_outofdate( fptr );
		}
	return;
}

private	void	interface_form( struct form_control * fptr )
{
	int	number=1;
	struct form_item * iptr;
	char	*	nptr;
	for (	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ( iptr->Contents.events.control & _IS_XO_LOCK  )
			continue;
		switch ( iptr->Contents.style & _FRAME_TYPE ) {
			case	_RADIO_FRAME	:
			case	_CHECK_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SELECT_FRAME	:
			case	_EDIT_FRAME	:
				iptr->Contents.interfaceitem = 1;
				break;
			default			:
				iptr->Contents.interfaceitem = 0;
				break;
			}
		form_is_outofdate( fptr );
		}
	return;
}

private	void	calculate_graph_size( struct window_control* dptr) 
{
	char	*	sptr;
	int		i=0;
	if (!( sptr = dptr->payload ))
		dptr->size    = dptr->w;
	else	{
		while ( *sptr ) {
			if ((*sptr >= '0') && ( *sptr <= '9'))
				i = ((i*10) + ( *(sptr++) - '0'));
			else	break;
			}
		if (!( dptr->size = i ))
			dptr->size    = dptr->w;
			
		}
	return;
}

private	void	build_graph( struct form_item * iptr )
{
	char		nbuffer[32];	
	if (!( iptr )) return;
	sprintf(nbuffer,"%u",iptr->Contents.w);
	iptr->Contents.payload = allocate_string( nbuffer );
	calculate_graph_size(&iptr->Contents);

}


public	struct 	form_item * allocate_for_Widget()
{
	int	i;
	struct form_item * iptr;

	if (!(iptr = (struct form_item *) allocate( sizeof( struct form_item ) )))
		return(iptr);

	else if (!( iptr->treenode = allocate_for_treeview() )) {
		liberate( iptr );
		return( (struct form_item *) 0) ;
		}
	else	{
		iptr->parent    = (struct form_control *) 0;
		iptr->previous 	= 
		iptr->next 	= (struct form_item *) 0;
		iptr->number =++Context.numbering;
		iptr->doctool = _TEXT_TOOL;
		for ( i=0; i < MAXNATLANG; i++) { iptr->document[i] = (char *) 0; }
		iptr->Contents.x = Context.Item.x;
		iptr->Contents.y = Context.Item.y;
		iptr->Contents.w = Context.Item.w;
		iptr->Contents.h = Context.Item.h;
		iptr->Contents.name = automatic_name(iptr->number);
		iptr->Contents.datatype = _WIDGET_VOID;
		iptr->Contents.colour = Context.Item.colour;
		iptr->Contents.style  = Context.Item.style;
		iptr->Contents.font   = Context.Item.font;
		iptr->Contents.align  = Context.Item.align;
		iptr->Contents.payload = iptr->Contents.extra = (void*)0;
		iptr->Contents.format  	    = (char *) 0;
		iptr->Contents.hint   	    = (char *) 0;
		iptr->Contents.stylesheet   = (char *) 0;
		iptr->Contents.xlimit  =
		iptr->Contents.ylimit  =
		iptr->Contents.adjust  =
		iptr->Contents.page    =
		iptr->Contents.focus   =
		iptr->Contents.radio   =
		iptr->Contents.special =
		iptr->Contents.interfaceitem= 0;
		iptr->Contents.size    = 0;
		iptr->Contents.trigger = 0;
		iptr->Contents.linkage = (void *) 0;
		for (i=0; i < MAXNATLANG; i++) { iptr->Contents.messages[i] = (char *) 0; }
		reset_event_control(&iptr->Contents.events,(iptr->Contents.style & _FRAME_TYPE));
		return( iptr );
		}
}

private	struct 	form_item * allocate_Widget(struct form_control * fptr)
{
	struct form_item * iptr;
	if (!( iptr = allocate_for_Widget() ))
		return( iptr );
	else	{
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_LINE_FRAME	:
				iptr->Contents.size    = Context.Item.size;
				break;

			case	_IMAGE_FRAME	:
				build_image( iptr );
				break;

			case	_GRAPH_FRAME	:
				build_graph( iptr );
				break;

			case	_BUTTON_FRAME	:
			case	_RADIO_FRAME	:
			case	_SWITCH_FRAME	:
			case	_CHECK_FRAME	:
				build_button( iptr );
				break;

			case	_TAB_FRAME	:
				build_title( iptr,"TAB" );
				break;
			case	_WINDOW_FRAME	:
				build_title( iptr, "Sing : Version 1.0a" );
				break;
					
			case	_TEXT_FRAME	:
				build_text( iptr );
				break;
			}
		add_Widget(fptr,iptr,0);
		}
	return(iptr);
}

private	void	drop_Form_buffer( struct form_control * fptr)
{
	if ( fptr->Buffer.value )
		fptr->Buffer.value = liberate_pixel_storage( fptr->Buffer.value );
	fptr->Buffer.width = fptr->Buffer.height = 0;
	fptr->Buffer.x = fptr->Buffer.y = 0;
}

public	void	remove_Form(struct form_control *  fptr)
{
	int	i;
	struct form_item * iptr;
	struct forms_method * mptr;

	/* Release Form members */
	/* -------------------- */
	while ((iptr=fptr->first) != (struct form_item *) 0) {

		fptr->first = iptr->next;

		liberate_Widget( iptr );
#ifdef	LIKEFUCK
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_IMAGE_FRAME	:
				if (iptr->Contents.extra ) {
					iptr->Contents.extra = local_drop_image( iptr->Contents.extra );
					}	
			default			:
				if (iptr->Contents.payload )
					iptr->Contents.payload = liberate( iptr->Contents.payload );
		
			}

		if ( iptr->Contents.name )
			iptr->Contents.name = liberate( iptr->Contents.name );

		drop_event_control( & iptr->Contents.events );

		for ( i=0; i < MAXNATLANG; i++) {
			if ( iptr->document[i] != (char *) 0 )
				iptr->document[i] = liberate( iptr->document[i] );
			}

		remove_treenode( iptr->treenode );

		iptr->treenode = liberate_for_treeview( iptr->treenode );

		iptr = liberate( iptr );
#endif
		}

	/* release all forms methods */
	/* ------------------------- */
	while ((mptr= fptr->rootmethod) != (struct forms_method *) 0) {
		fptr->rootmethod = mptr->next;
		liberate_Method( mptr );
		}
	fptr->lastmethod = fptr->rootmethod;

	/* release all forms members */
	/* ------------------------- */
	while ((mptr= fptr->rootmember) != (struct forms_member *) 0) {
		fptr->rootmember = mptr->next;
		liberate_Member( mptr );
		}
	fptr->lastmember = fptr->rootmember;

	/* release document parameters */
	/* --------------------------- */
	if ( fptr->printout.PageHead )
		fptr->printout.PageHead = liberate( fptr->printout.PageHead );
	if ( fptr->printout.PageFoot )
		fptr->printout.PageFoot = liberate( fptr->printout.PageFoot );
	if ( fptr->printout.DeviceName )
		fptr->printout.DeviceName = liberate( fptr->printout.DeviceName );
	if ( fptr->printout.DriverName )
		fptr->printout.DriverName = liberate( fptr->printout.DriverName );

	if ( fptr->prodname  != (char *) 0)
		fptr->prodname = liberate( fptr->prodname );

	if ( fptr->loadname  != (char *) 0)
		fptr->loadname = liberate( fptr->loadname );

	if ( fptr->dependance  != (char *) 0)
		fptr->dependance = liberate( fptr->dependance );

	if ( fptr->stylesheet  != (char *) 0)
		fptr->stylesheet = liberate( fptr->stylesheet );

	if ( fptr->clearscreen  != (char *) 0)
		fptr->clearscreen = liberate( fptr->clearscreen );

	for (i=0; i < MAXNATLANG; i++ ) {
		if ( fptr->document[i] )
			fptr->document[i] = liberate( fptr->document[i] );
		}

	if ( fptr->identifier  != (char *) 0)
		fptr->identifier = liberate( fptr->identifier );

	if ( fptr->construction  != (char *) 0)
		fptr->construction = liberate( fptr->construction );

	if ( fptr->image != (struct standard_image *) 0)
		fptr->image = local_drop_image( fptr->image );

	fptr->first = fptr->last = fptr->current = (struct form_item *) 0;


	return;

}


public	void	drop_Form(struct form_control *  fptr)
{
	struct form_item * iptr;

	if (!( fptr ))
		return;

	drop_Form_buffer( fptr );

	remove_treenode( fptr->treenode );

	fptr->treenode = liberate_for_treeview( fptr->treenode );

	remove_Form( fptr );


	return;
}

public	void	drop_form_clipboard()
{
	struct form_item * iptr;
	if (!( Context.Widgets ))
		return;
	while ((iptr = Context.Widgets) != (struct form_item *) 0) {
		Context.Widgets = iptr->next;
		liberate_Widget( iptr );
		}
	return;
}


public 	struct form_item * copy_widget( struct form_item * wptr )
{
	struct 	form_item * iptr;
	struct	form_control * fptr;
	int	i;

	if (!(iptr = allocate_for_Widget() ))
		return( (struct form_item *) 0) ;
	else	{
		fptr = wptr->parent;
		iptr->parent    = (struct form_control *) 0;
		iptr->previous 	= 
		iptr->next 	= (struct form_item *) 0;

		if ( is_named_widget( wptr ) ) {
			if ( iptr->Contents.name )
				iptr->Contents.name = liberate( iptr->Contents.name );
			iptr->Contents.name = allocate_string( wptr->Contents.name );
			}

		iptr->doctool = wptr->doctool;

		for (i=0; i < MAXNATLANG; i++ ) {
			if ( wptr->document[i] )
				iptr->document[i] = allocate_string( wptr->document[i] );
			else	iptr->document[i] = (char *) 0;
			}

		iptr->shitem =
		iptr->shatx  =
		iptr->shaty  = 0;
		iptr->number =++Context.numbering;

		iptr->Contents.style	= wptr->Contents.style;
		iptr->Contents.x	= wptr->Contents.x;
		iptr->Contents.y	= wptr->Contents.y;	
		iptr->Contents.w	= wptr->Contents.w;	
		iptr->Contents.h	= wptr->Contents.h;	
		iptr->Contents.colour	= wptr->Contents.colour;	
		iptr->Contents.size	= wptr->Contents.size;	
		iptr->Contents.font	= wptr->Contents.font;	
		iptr->Contents.align	= wptr->Contents.align;	
		iptr->Contents.interfaceitem= wptr->Contents.interfaceitem; 

		copy_event_control( & iptr->Contents.events, & wptr->Contents.events );

		iptr->Contents.datatype	= wptr->Contents.datatype;

		for (i=0; i < MAXNATLANG; i++ ) {
			if ( wptr->Contents.messages[i] )
				iptr->Contents.messages[i] = allocate_string( wptr->Contents.messages[i] );
			else	iptr->Contents.messages[i] = (char *) 0;
			}
		if ( wptr->Contents.payload )
			iptr->Contents.payload = allocate_string( wptr->Contents.payload );
		else	iptr->Contents.payload = (char *) 0;

		if ( wptr->Contents.format )
			iptr->Contents.format = allocate_string( wptr->Contents.format );
		else	iptr->Contents.format = (char *) 0;

		if ( wptr->Contents.hint )
			iptr->Contents.hint = allocate_string( wptr->Contents.hint );
		else	iptr->Contents.hint = (char *) 0;

		if ( wptr->Contents.stylesheet )
			iptr->Contents.stylesheet = allocate_string( wptr->Contents.stylesheet );
		else	iptr->Contents.stylesheet = (char *) 0;

		iptr->Contents.extra	= (void *) 0;
		iptr->Contents.focus	= 
		iptr->Contents.page	= 
		iptr->Contents.adjust	= 
		iptr->Contents.xlimit	= 
		iptr->Contents.ylimit	= 0;

		check_Widget( iptr );

		}
	return( iptr );
}


public	struct form_control * liberate_Form(struct form_control *  fptr)
{
	struct form_item * iptr;

	if (!( fptr ))
		return( fptr );

	drop_Form( fptr );

	fptr = liberate( fptr );

	return( fptr );

}

public	int	convert_widget_type( char *tptr )
{
	if (!( tptr ))				return( _WIDGET_VOID );
	else if ( *tptr == _SYMBOLIC_BYTE )	return( _WIDGET_BYTE );
	else if ( *tptr == _SYMBOLIC_WORD )	return( _WIDGET_WORD );
	else if ( *tptr == _SYMBOLIC_LONG )	return( _WIDGET_LONG );
	else if ( *tptr == _SYMBOLIC_FLOAT )	return( _WIDGET_FLOAT);
	else if ( *tptr == _SYMBOLIC_NUMERIC )	return( _WIDGET_NUMERIC );
	else if ( *tptr == _SYMBOLIC_STRING )	return( _WIDGET_STRING );
	else if ( *tptr == _SYMBOLIC_KONSTANT )	return( _WIDGET_KONSTANT );
	else if ( *tptr == _SYMBOLIC_POINTER )	return( _WIDGET_POINTER );
	else if ( *tptr == _SYMBOLIC_CLASS )	return( _WIDGET_CLASS );
	else if ( *tptr == _SYMBOLIC_TEXTFILE)	return( _WIDGET_TEXTFILE );
	else					return( _WIDGET_VOID  );
}
	
public	int	make_widget_symbol( int widget_type )
{
	switch ( widget_type ) {
		case	_WIDGET_BYTE 	: return( _SYMBOLIC_BYTE );
		case	_WIDGET_WORD 	: return( _SYMBOLIC_WORD );
		case	_WIDGET_LONG 	: return( _SYMBOLIC_LONG );
		case	_WIDGET_FLOAT	: return( _SYMBOLIC_FLOAT );
		case	_WIDGET_NUMERIC : return( _SYMBOLIC_NUMERIC );
		case	_WIDGET_STRING 	: return( _SYMBOLIC_STRING );
		case	_WIDGET_KONSTANT: return( _SYMBOLIC_KONSTANT );
		case	_WIDGET_POINTER : return( _SYMBOLIC_POINTER );
		case	_WIDGET_CLASS 	: return( _SYMBOLIC_CLASS );
		case	_WIDGET_TEXTFILE: return( _SYMBOLIC_TEXTFILE );
		case	_WIDGET_VOID	: return( _SYMBOLIC_VOID );
		default			: return( _SYMBOLIC_VOID );
		}
}		
	
private	char *	automatic_name( int number )
{
	char	nbuffer[32];
	sprintf(nbuffer,"%s%u",_AUTO_PREFIX,number);
	return( allocate_string(nbuffer) );
}

/*	--------------------------------------------------------	*/
/*	p e r f o r m _ m e s s a g e _ c o n t r o l ( widget )	*/
/*	--------------------------------------------------------	*/
/*	For multilingual international message widgets it is		*/
/*	important to ensure that any _UNQUOTED_STRINGS be copied	*/
/*	to all empty message entries.					*/
/*	--------------------------------------------------------	*/

private	void	perform_message_control( struct form_item * iptr )
{
	int	i;
	int	n;
	char *	sptr;
	char *	mptr;
	struct	form_control * fptr;
	if (!( fptr = iptr->parent ))
		return;
	else if (!( fptr->formflags & _INTERNATIONAL))
		return;
	else if (!( fptr->formflags & _FORM_MULTILINGUAL ))
		return;
	else	{
		sptr = mptr = (char *) 0;
		for (i=0; i < MAXNATLANG; i++ ) {
			if (!( sptr = iptr->Contents.messages[i]))
				continue;
			else if ( *sptr != _UNQUOTED_STRING )
				continue;
			else	{
				mptr = sptr;
				break;
				}
			}
		if (!( mptr ))
			return;
		for (i=0; i < MAXNATLANG; i++ ) {
			if (( sptr = iptr->Contents.messages[i]) != (char *) 0)
				continue;
			else if (!( iptr->Contents.messages[i] = allocate_string( mptr ) ))
				break;
			else	continue;
			}
		return;
		}
}


public 	void	check_Widget(struct form_item * iptr )
{
	char * nptr;
	int	i;
	int	fh;
	int	fw;

	if (!( iptr ))
		return;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;

	/* Ensure Valid Name */
	/* ----------------- */
	if (!( nptr = iptr->Contents.name )) {
		nptr = iptr->Contents.name = automatic_name( ++Context.numbering );
		}

	else if (!( *nptr )) {
		liberate( nptr );
		nptr = iptr->Contents.name = automatic_name( ++Context.numbering );
		}

	for (i=0; *(nptr+i) != 0; i++ )
		if ( *(nptr+i) == ' ' )
			*(nptr+i) = '_';
			
	/* limit widget alignment to defined values */
	/* ---------------------------------------- */
	switch ( iptr->Contents.style & _FRAME_TYPE ) {
		case	_DATA_FRAME	:
			check_data_widget(  iptr );
			break;

		case	_SCROLL_FRAME	:	/* scroll bar buttons	*/
		case	_CHECK_FRAME	:	/* message alignment	*/
		case	_RADIO_FRAME	:	/* message alignment	*/
		case	_TAB_FRAME	:	/* tab alignment	*/	
		case	_SELECT_FRAME	:	/* button alignment	*/
		case	_FORM_FRAME	:		
		case	_EDIT_FRAME	:	
		case	_WINDOW_FRAME	:	/* window alignment 	*/

			if (!( iptr->Contents.events.mimo ))
				iptr->Contents.events.mimo = _MIMO_UP;

		case	_FILL_FRAME	:
		case	_OUTSET_FRAME	:
		case	_INSET_FRAME	:
		case	_RIDGE_FRAME	:
		case	_GROOVE_FRAME	:	/* These may have titles */

		case	_TEXT_FRAME	:	/* text alignment	*/
			/* ensure text has at least font size */
			/* ---------------------------------- */
			if ( iptr->Contents.h < fh )
				iptr->Contents.h = fh;
			if ( iptr->Contents.w < fw )
				iptr->Contents.w = fw;

			break;

		case	_IMAGE_FRAME	:	/* image alignment	*/
			if ( iptr->Contents.payload )
				if (!( Context.compiling ))
					iptr->Contents.extra   = widget_image_loader(iptr->Contents.payload,iptr->Contents.align);

			break;

		case	_BUTTON_FRAME	:	
			if (!( iptr->Contents.events.mimo ))
				iptr->Contents.events.mimo = _MIMO_UP;

			if (( iptr->Contents.datatype == _WIDGET_OVERLAY )
			||  ( iptr->Contents.datatype == _WIDGET_SYSTEM  )
			||  ( iptr->Contents.datatype == _WIDGET_CHAIN   )
			||  ( iptr->Contents.datatype == _WIDGET_LOADGO  )) {
				if (!( method_is_valid( iptr->Contents.format )))
					iptr->Contents.format = allocate_string( iptr->Contents.name );
				}
	
			if ( iptr->Contents.h < fh )
				iptr->Contents.h = fh;
			if ( iptr->Contents.w < fw )
				iptr->Contents.w = fw;

			break;

		case	_SWITCH_FRAME	:
			if (!( iptr->Contents.events.mimo ))
				iptr->Contents.events.mimo = _MIMO_UP;


		case	_PROGRESS_FRAME	:
			if ( iptr->Contents.h < fh )
				iptr->Contents.h = fh;
			if ( iptr->Contents.w < fw )
				iptr->Contents.w = fw;

			break;

		/* these widgets have no defined semantics : A NONE */
		/* ------------------------------------------------ */
		case	_LINE_FRAME	:	
		case	_GRAPH_FRAME	:

			iptr->Contents.align = _A_NONE;
			break;

		}
	/* Check Payload Items */
	/* ------------------- */
	switch ( iptr->Contents.style & _FRAME_TYPE ) {
		case	_FORM_FRAME	:
		case	_SELECT_FRAME	:
			if (!( iptr->Contents.payload ))
				iptr->Contents.payload = allocate_string("a|b|c");
			iptr->Contents.size = strlen( iptr->Contents.payload );
		}

	/* Inhibit Interface Items */
	/* ----------------------- */
	switch ( iptr->Contents.style & _FRAME_TYPE ) {
		case	_RADIO_FRAME	:
		case	_CHECK_FRAME	:
		case	_SWITCH_FRAME	:
		case	_SELECT_FRAME	:
		case	_EDIT_FRAME	:
			/* Do not force this any more */
			/* -------------------------- */
			/* iptr->Contents.interfaceitem = 1; */
			break;

		case	_FORM_FRAME	:
		case	_PROGRESS_FRAME	:
		case	_SCROLL_FRAME	:

		default			:
			iptr->Contents.interfaceitem = 0;
		}

	/* Trigger buttons need parameters */
	/* ------------------------------- */
	if (( iptr->Contents.style & _FRAME_TYPE ) == _BUTTON_FRAME ) {
		if (( iptr->Contents.datatype == _WIDGET_OVERLAY )
		||  ( iptr->Contents.datatype == _WIDGET_CHAIN   )
		||  ( iptr->Contents.datatype == _WIDGET_SYSTEM  )
		||  ( iptr->Contents.datatype == _WIDGET_LOADGO  )) {
			if (!(iptr->Contents.events.on_event))
				if ((iptr->Contents.events.on_event = allocate(24)) != (char *) 0)
					sprintf(iptr->Contents.events.on_event,"this.buffer=%c %c\r\n",0x0022,0x0022);
			}
		}

	perform_message_control( iptr );
	perform_event_control( & iptr->Contents.events );
	check_Widget_trigger( &iptr->Contents );
	return;
}

public 	int 	edit_Widget(struct form_item * iptr, struct form_control * fptr)
{
	char *	mptr;
	char *	eptr="\1UseVidget";
	char *	dtptr;
	int	wclass;
	int	bg;
	int	fg;
	int	fid;
	int	isb;
	int	isu;
	int	iss;
	int	isl;
	int	isa;
	int	ismove=0;
	int	isdown=0;
	int	isup=0;
	int	ishold=0;
	if ( iptr ) {
		fid = (iptr->Contents.font-1);
		fg = (iptr->Contents.colour & 0x00FF);
		bg = (iptr->Contents.colour >> 8);
		wclass = (iptr->Contents.style & _FRAME_TYPE);
		if ( iptr->Contents.align & _A_BOLD )
			isb = 1;
		else	isb = 0;
		if ( iptr->Contents.align & _A_LINE )
			isu = 1;
		else	isu = 0;
		if ( iptr->Contents.align & _A_SHADOW )
			iss = 1;
		else	iss = 0;
		isa = (iptr->Contents.align & 0x00FF);
		if ( iptr->Contents.events.control & _IS_XO_LOCK  )
			isl = 1;
		else	isl = 0;
		if ( iptr->Contents.events.control & _IS_ON_MOUSE ) {
			if ( iptr->Contents.events.mimo & _MIMO_MOVE )
				ismove=1;
			if ( iptr->Contents.events.mimo & _MIMO_DOWN )
				isdown=1;
			if ( iptr->Contents.events.mimo & _MIMO_UP )
				isup=1;
			if ( iptr->Contents.events.mimo & _MIMO_WHILE_DOWN)
				ishold=1;
			}
		if (( mptr = widget_event_message( iptr )) != (char *) 0)
			status_message(mptr,1);

		if ( accept_widget_properties(
			&iptr->Contents.x, 	&iptr->Contents.y,
			&iptr->Contents.w, 	&iptr->Contents.h,
			&fid,&fg, &bg,
			&iptr->Contents.payload,
			&iptr->Contents.name, 
			&iptr->Contents.format,
			&iptr->Contents.stylesheet,
			&iptr->Contents.trigger,
			&wclass,

			&isa,	&iptr->Contents.datatype,
			&isb, 	&isu, &iss, &isl,

			&iptr->Contents.interfaceitem,
			&iptr->Contents.special,

			&iptr->Contents.events.xo_create,
			&iptr->Contents.events.on_create,

			&iptr->Contents.events.xo_show,
			&iptr->Contents.events.on_show,

			&iptr->Contents.events.xo_get_focus,
			&iptr->Contents.events.on_get_focus,

			&ismove, &isdown, &isup, &ishold,

			&iptr->Contents.events.xo_event,
			&iptr->Contents.events.on_event,

			&iptr->Contents.events.xo_lose_focus,
			&iptr->Contents.events.on_lose_focus,

			&iptr->Contents.events.xo_hide,
			&iptr->Contents.events.on_hide,

			&iptr->Contents.events.xo_remove,
			&iptr->Contents.events.on_remove

			) != 27 ) {
			perform_event_control(&iptr->Contents.events);
			switch ((iptr->Contents.style & _FRAME_TYPE)) {
				case	_GRAPH_FRAME 	:
					calculate_graph_size(&iptr->Contents);
					break;
				case	_FORM_FRAME	:
					calculate_edit_size(&iptr->Contents);
					break;
				default			:
					iptr->Contents.size = strlen( iptr->Contents.payload );
				}
			if ((iptr->Contents.style & _FRAME_TYPE) == _IMAGE_FRAME ) 
				reload_image( &iptr->Contents );
			iptr->Contents.style &= ~ _FRAME_TYPE;
			iptr->Contents.style |= wclass;
			iptr->Contents.colour = (fg | (bg << 8));
			iptr->Contents.font = (fid+1);
			if (!( iptr->Contents.name ))
				iptr->Contents.name = automatic_name( ++Context.numbering );
			iptr->Contents.align = isa;
			if ( isb ) iptr->Contents.align |= _A_BOLD;
			if ( isu ) iptr->Contents.align |= _A_LINE;
			if ( iss ) iptr->Contents.align |= _A_SHADOW;
			if ( isl )
				iptr->Contents.events.control |= _IS_XO_LOCK;
			else	iptr->Contents.events.control &= ~_IS_XO_LOCK;
			
			if ( ismove )
				iptr->Contents.events.mimo |= _MIMO_MOVE;
			else	iptr->Contents.events.mimo &= ~_MIMO_MOVE;

			if ( isdown )
				iptr->Contents.events.mimo |= _MIMO_DOWN;
			else	iptr->Contents.events.mimo &= ~_MIMO_DOWN;

			if ( isup )
				iptr->Contents.events.mimo |= _MIMO_UP;
			else	iptr->Contents.events.mimo &= ~_MIMO_UP;

			if ( ishold )
				iptr->Contents.events.mimo |= _MIMO_WHILE_DOWN;
			else	iptr->Contents.events.mimo &= ~_MIMO_WHILE_DOWN;

			Context.OutOfDate |= 1;

			check_Widget(iptr);

			}
		draw_console();
		}
	return(0);
}

public 	int 	zoom_Widget(struct window_control* dptr)
{
	struct standard_image * iptr;
	int		event;
	if ( dptr ) {
		switch ((dptr->style & _FRAME_TYPE)) {
			case	_BUTTON_FRAME	:
				if (!( dptr->align & _B_IMAGE ))
					break;
				else if ((!( dptr->extra ))
				     &&  (!( dptr->extra = widget_image_loader(dptr->payload,dptr->align))))
					break;
			
			case	_IMAGE_FRAME 	:
				iptr = (struct standard_image *) dptr->extra;
				event = edit_Image(dptr->payload,&iptr);
				dptr->extra = iptr;
				return( event);

			}
		}
	return(0);
}


public 	void	draw_Widget(
	struct form_control  * fptr,
	struct form_item     * iptr)
{
	int	fh;
	int	xh;
	int	focus=0;
	if ( iptr ) {
	   if ((!( fptr->page_number   ))
	   ||  (!( iptr->Contents.page ))
	   ||  (( iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME)
	   ||  ( fptr->page_number == iptr->Contents.page )) {
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_LINE_FRAME 	:
				if (( iptr->Contents.w > 0 ) && ( iptr->Contents.h > 0))
					drawline( 	Context.DeskTop.x+iptr->Contents.x,
						Context.DeskTop.y+iptr->Contents.y,
						Context.DeskTop.x+iptr->Contents.w,
						Context.DeskTop.y+iptr->Contents.h,
						iptr->Contents.size,
						iptr->Contents.colour, filzone );
				break;

			case	_FILL_FRAME 	:
				if (( iptr->Contents.w > 0 ) && ( iptr->Contents.h > 0)) {
					if ( iptr->Contents.style & _FRAME_TRANSPARENT )
						relief(Context.DeskTop.x+iptr->Contents.x,Context.DeskTop.y+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h, iptr->Contents.colour,0,iptr->Contents.colour );
					else	{
						visual_filzone( Context.DeskTop.x+iptr->Contents.x,Context.DeskTop.y+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h, iptr->Contents.colour,(iptr->Contents.align&_VFILL_MASK) );
						}
					}
				break;

			case	_DATA_FRAME	:
				if ((iptr->Contents.align & 0x000F) != _VISUAL_FRAME) {
					draw_button(
						Context.DeskTop.x,
						Context.DeskTop.y,
						iptr,0 );
					}
				else	{
					draw_class_image(
						Context.DeskTop.x,
						Context.DeskTop.y,
						iptr,0 );
					}
				break;

			case	_IMAGE_FRAME 	:
				draw_image(
					Context.DeskTop.x,
					Context.DeskTop.y,
					iptr,0 );
				break;

			case	_TEXT_FRAME 	:
				draw_text( 
					Context.DeskTop.x,
					Context.DeskTop.y,
					iptr,0 );
				break;

			case	_FORM_FRAME	:
			case	_SCROLL_FRAME	:
			case	_PROGRESS_FRAME	:
			case	_SELECT_FRAME	:
			case	_BUTTON_FRAME 	:
			case	_SWITCH_FRAME	:
			case	_GRAPH_FRAME	:
			case	_CHECK_FRAME 	:
			case	_RADIO_FRAME 	:
				draw_button(
					Context.DeskTop.x,
					Context.DeskTop.y,
					iptr,0 );
				break;

			case	_TAB_FRAME 	:

				if ( iptr->Contents.page == fptr->page_number )
					focus = _VISUAL_FOCUS;

				if ( iptr->Contents.align & 1 )
					focus |= 0x0010;
				if ( iptr->Contents.align & 2 )
					focus |= 0x0020;
				focus |= (iptr->Contents.align & 0x0F00);
			case	_WINDOW_FRAME 	:
				draw_window(
					Context.DeskTop.x,
					Context.DeskTop.y,
					iptr, focus );
				break;

			case	_EDIT_FRAME	:
				visual_frame  ( Context.DeskTop.x+iptr->Contents.x,Context.DeskTop.y+iptr->Contents.y,iptr->Contents.w+2,iptr->Contents.h+2, iptr->Contents.style );
				break;

			case	_INSET_FRAME	:
			case	_OUTSET_FRAME	:
			case	_GROOVE_FRAME	:
			case	_RIDGE_FRAME	:
				if (( iptr->Contents.align != _A_NONE     ) 
				&&  ( iptr->Contents.payload != (char *) 0)) {
					fh = (guifontsize(iptr->Contents.font) >> 8);
					xh = iptr->Contents.h; iptr->Contents.h=fh;
					draw_text( 
						Context.DeskTop.x,
						Context.DeskTop.y,
						iptr,0 );
					iptr->Contents.h = xh;
					iptr->Contents.y += fh;
					iptr->Contents.h -= fh;
					visual_frame  ( Context.DeskTop.x+iptr->Contents.x,Context.DeskTop.y+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h, iptr->Contents.style );
					iptr->Contents.h += fh;
					iptr->Contents.y -= fh;
					break;
					}

			
			default			:
				visual_frame  ( Context.DeskTop.x+iptr->Contents.x,Context.DeskTop.y+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h, iptr->Contents.style );
			}
		}

	    }
	return;
}

public	int	flush_console_output( int atx, int aty, int state, int indent )
{
	return( console_Message( atx, aty, state, classbuffer, strlen(classbuffer), indent ) );
}

public 	int	show_Widget(struct form_item * iptr,int state)
{
	if (!( iptr ))
		return(0);

	else if (!( check_class_buffer() ))
		return(0);

	output_string( get_widget_class( iptr->Contents.style ) );
	output_string( " " );

	if (!( iptr->Contents.name ))
		iptr->Contents.name = automatic_name(iptr->number);

	output_string( iptr->Contents.name );

	output_string("("); output_int( iptr->Contents.x );
	output_string(","); output_int( iptr->Contents.y );
	output_string(","); output_int( iptr->Contents.w );
	output_string(","); output_int( iptr->Contents.h );
	switch ((iptr->Contents.style & _FRAME_TYPE)) {
		case	_LINE_FRAME 	:
		case	_FILL_FRAME 	:
			output_string(","); output_int( iptr->Contents.colour );
			break;

		case	_EDIT_FRAME 	:
			output_string(","); output_int( iptr->Contents.font );
			break;

		case	_TEXT_FRAME 	:
			output_string(","); output_int( iptr->Contents.colour );
			output_string(","); output_int( iptr->Contents.align );

		case	_FORM_FRAME	:
		case	_SELECT_FRAME 	:
		case	_BUTTON_FRAME 	:
		case	_SWITCH_FRAME	:
		case	_GRAPH_FRAME	:
		case	_CHECK_FRAME 	:
		case	_RADIO_FRAME 	:
			output_string(","); output_int( iptr->Contents.font );
		case	_TAB_FRAME 	:
		case	_IMAGE_FRAME 	:
		case	_WINDOW_FRAME 	:
			if ( iptr->Contents.payload ) {
				output_string(","); output_string( iptr->Contents.payload );
				}
			break;
			
		}
	output_string( ")" );
	return( flush_console_output( iptr->shatx, iptr->shaty, state, 1 ) );

}

public	int	select_TreeWidget( struct form_item * iptr )
{
	int	mx,my;
	struct	form_control 	* fptr;
	struct 	form_item 	* wptr;
	struct 	form_item 	* xptr;
	struct	treeview  	* tptr;

	if (!( iptr ))
		return( 0 );
	else if ((fptr = iptr->parent) !=(struct form_control *) 0) {
		if ( fptr->current )
			focus_treenode( fptr->current->treenode, 0);
		SelectFormWidget(fptr,iptr,1);
		}
	else	{		
		focus_treenode( iptr->treenode, _TREE_FOCUS );
		}
	if ( visual_event(2) != _MIMO_LEFT ) {
		if (!( Context.EditView ))
			edit_Widget( iptr, iptr->parent );
		return( 0 );
		}
	else if ( visual_event(1) != _MIMO_DOWN )
		return(0);

	else	{
		mx = visual_event(7);
		my = visual_event(6);
		do	{
			show_widget_sprite( mx,my );
			while ( visual_getch() != 256 );
			mx = visual_event(7);
			my = visual_event(6);
			hide_sprite();
			}
		while ( visual_event(1) != _MIMO_UP );
		if (visual_event(2) == _MIMO_RIGHT)
			return( _EDIT_FORM );
		if (( mx < Context.DeskTop.x)
		&&  ( mx > Context.ToolBar.w)
		&&  ( my > Context.DeskTop.y)
		&&  ( my < Context.StatusBar.y )) {
			wptr = fptr->current;
			my -= Context.DeskTop.y;
			mx -= Context.ToolBar.w;
			if ((!( tptr = newlocate_TreeViewWidget(mx,my,wptr->treenode)))
			||  ( tptr->nature != TREE_WIDGET )
			||  (!( iptr = tptr->payload )))
				return(0);
			else if ( wptr->number == iptr->number )
				return(0);
			set_national_payload(wptr,fptr->natlang);
			if (!( xptr = copy_widget( wptr ) ))
				return( 0 );
			else	{
				/* printf("moved %s to after %s\r\n",wptr->Contents.name, iptr->Contents.name); */
				remove_widget( fptr, wptr );
				remove_treenode( wptr->treenode );
				wptr = liberate_Widget( wptr );
				fptr->current = iptr;
				add_Widget( fptr, xptr, 0 );
				fptr->current = xptr;
				xptr->parent = fptr;
				get_national_payload(xptr,fptr->natlang);
				draw_TreeView();
				}
			return(0);
			}
		else	return(0);
		}
}

public	int	select_TreeForm( struct form_control * fptr )
{
	int	mx,my;
	SelectFormWidget(fptr,fptr->current,1);
	select_TreeHost( fptr->host );
	if ( visual_event(2) != _MIMO_LEFT )
		(void) form_parameters( fptr );
	else if ( visual_event(1) != _MIMO_DOWN )
		return(0);

	else	{
		mx = visual_event(7);
		my = visual_event(6);
		do	{
			show_form_sprite( mx,my );
			while ( visual_getch() != 256 );
			mx = visual_event(7);
			my = visual_event(6);
			hide_sprite();
			}
		while ( visual_event(1) != _MIMO_UP );
		if (visual_event(2) == _MIMO_RIGHT)
			return( _EDIT_FORM );
		if (( mx > Context.DeskTop.x)
		&&  ( my > Context.DeskTop.y)
		&&  ( mx < Context.Palette.x)
		&&  ( my < Context.StatusBar.y ))
			return( _EDIT_FORM );
		else	return(0);
		}

}

private	void	form_data_type( struct form_item * iptr )
{
	if ( iptr->Contents.datatype == _WIDGET_VOID ) {
		switch ((iptr->Contents.style & _FRAME_TYPE)) {

			case	_SELECT_FRAME	:
			case	_SWITCH_FRAME	:
			case	_GRAPH_FRAME	:
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
				iptr->Contents.datatype = _WIDGET_WORD;
				break;

			case	_EDIT_FRAME	:
				iptr->Contents.datatype = _WIDGET_STRING;
				break;
			}
		}
	return;
}

/*	Sets the default event conditions for new widgets	*/
/*	-------------------------------------------------	*/

private	void	form_event_type( struct form_item * iptr )
{
	switch ( iptr->Contents.style & _FRAME_TYPE ) {

		case	_SCROLL_FRAME	:	/* scroll bar buttons	*/
		case	_CHECK_FRAME	:	/* message alignment	*/
		case	_RADIO_FRAME	:	/* message alignment	*/
		case	_TAB_FRAME	:	/* tab alignment	*/	
		case	_SELECT_FRAME	:	/* button alignment	*/
		case	_FORM_FRAME	:		
		case	_EDIT_FRAME	:	
		case	_SWITCH_FRAME	:
		case	_BUTTON_FRAME	:	
			iptr->Contents.events.xo_event |= _EVENT_IS_FOCUS;
			
		case	_WINDOW_FRAME	:	/* window alignment 	*/
			iptr->Contents.events.mimo = _MIMO_UP;
			break;

		}
	return;
}

private	void	add_new_item(struct form_control * fptr, int button)
{
	int	x,y,w,h;
	struct form_item * iptr;
	struct window_control Window;
	Window.style = Context.Item.style;
	Window.font = Context.Item.font;
	calculate_cursor( &Window );
	Context.Item.x = Window.x;	Context.Item.y = Window.y;
	Context.Item.w = Window.w;	Context.Item.h = Window.h;

	Context.Item.align = Context.alignment;

	if ( Context.Item.style == _LINE_FRAME ) {
		Context.Item.colour = (button == _MIMO_LEFT ? Context.foreground : Context.background );
		Context.Item.size   = Context.thickness;
		}
	else if (( Context.Item.style == _TEXT_FRAME   ) 
	     ||  ( Context.Item.style == _TAB_FRAME    ) 
	     ||  ( Context.Item.style == _SWITCH_FRAME  ) 
	     ||  ( Context.Item.style == _GRAPH_FRAME  ) 
	     ||  ( Context.Item.style == _CHECK_FRAME  ) 
	     ||  ( Context.Item.style == _RADIO_FRAME  ) 
	     ||  ( Context.Item.style == _BUTTON_FRAME ) 
	     ||  ( Context.Item.style == _WINDOW_FRAME ))
		Context.Item.colour = (Context.foreground | (Context.background<<8));

	else if ( Context.Item.style != _FILL_FRAME ) {
		if ( button == _MIMO_LEFT )
			Context.Item.style &= ~_FRAME_TRANSPARENT;
		else	Context.Item.style |= _FRAME_TRANSPARENT;
		}

	else	Context.Item.colour = (button == _MIMO_LEFT ? Context.foreground : Context.background );

	if (( iptr = allocate_Widget(fptr)) != (struct form_item *) 0) {
		form_data_type( iptr );
		form_event_type( iptr );
		if (!( iptr->Contents.name ))
			iptr->Contents.name = automatic_name(iptr->number);
		show_item_info(fptr->current);
		}
	return;
}

private	int	calculate_page_tab( 
		int	offset,
	 	struct form_item    * pptr  )
{
	int	fh;
	int	fw;
	int	f;
	int	hk;
	char *	sptr=(char *) 0;
	if (!( f = pptr->Contents.font ))
		return(offset);
	else	{
		fh = guifontsize(f);
		fw = (fh & 0x00FF);
		fh >>= 8;
		fh &= 0x00FF;
		}
	pptr->Contents.ylimit = (fh+8);
	pptr->Contents.xlimit = (fw * 2);
	pptr->Contents.xlimit += pixel_payload_size( pptr );
	pptr->Contents.adjust = offset;
	return( (offset + pptr->Contents.xlimit + 1) );
}

private	void	calculate_select( struct form_item  * pptr  )
{
	int	fh;
	int	fw;
	int	f;
	if (!( f = pptr->Contents.font ))
		return;
	else	{
		fh = guifontsize(f);
		fw = (fh & 0x00FF);
		fh >>= 8;
		fh &= 0x00FF;
		}
	pptr->Contents.ylimit = fh;
	pptr->Contents.xlimit = pptr->Contents.w;
	pptr->Contents.adjust = 0;
	return;
}

private	int	visual_page_number( 
		 	struct form_item    * pptr ,	/* Page */
		 	struct form_item    * mptr 	/* member */ 
			)
{
	if ((!( pptr ))
	||  (!( mptr )))
		return(0);
	else if (( pptr->Contents.style & _FRAME_TYPE) != _TAB_FRAME)
		return(0);
	else if (( mptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME)
		return( mptr->Contents.page );
	else if (( mptr->Contents.style & _FRAME_TYPE) == _LINE_FRAME) {
		if (( mptr->Contents.x >= pptr->Contents.x )
		&&  ( mptr->Contents.y >= pptr->Contents.y )
		&&  ( mptr->Contents.w 
		<=   (pptr->Contents.x + pptr->Contents.w ))
		&&  (mptr->Contents.h 
		<=   (pptr->Contents.y + pptr->Contents.h )))
			return( pptr->Contents.page );
		else	return( 0 );
		}
	else if (( mptr->Contents.style & _FRAME_TYPE) == _SELECT_FRAME) {
		if (( mptr->Contents.x >= pptr->Contents.x )
		&&  ( mptr->Contents.y >= pptr->Contents.y )
		&&  ((mptr->Contents.x + mptr->Contents.xlimit )
		<=   (pptr->Contents.x + pptr->Contents.w ))
		&&  ((mptr->Contents.y + mptr->Contents.ylimit )
		<=   (pptr->Contents.y + pptr->Contents.h )))
			return( pptr->Contents.page );
		else	return( 0 );
		}
	else	{
		if (( mptr->Contents.x >= pptr->Contents.x )
		&&  ( mptr->Contents.y >= pptr->Contents.y )
		&&  ((mptr->Contents.x + mptr->Contents.w )
		<=   (pptr->Contents.x + pptr->Contents.w ))
		&&  ((mptr->Contents.y + mptr->Contents.h )
		<=   (pptr->Contents.y + pptr->Contents.h )))
			return( pptr->Contents.page );
		else	return( 0 );
		}
	return(0);
}

private	void	calculate_radio(
	struct form_item * 	iptr,
	char 		 *	name )
{
	int	i;
	for ( i=1; iptr != (struct form_item *) 0; iptr = iptr->next ) {
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_RADIO_FRAME	:
				if ((!( iptr->Contents.radio ))
				&&  ( string_compare( iptr->Contents.name, name ) )) {
					iptr->Contents.radio = i++;
					}
			}
		}
	return;
}

/*	--------------------------------			*/
/*	P R E P A R E _ F O R M ( form )			*/
/*	--------------------------------			*/
/*	Analysis of form components and application of		*/
/*	various component oriented rules and calculations.	*/
/*								*/
/*	- Tab Frame numbering and member association.		*/
/*								*/
/*	- Focus Order atribution.				*/
/*								*/
/*	- Calculate Radio button values				*/
/*								*/
/*	- Calculation of Maxmimum Window Size			*/
/*								*/
/*	--------------------------------			*/

public	void	prepare_Form(struct form_control * fptr)
{
	struct form_item * 	iptr=(struct form_item *) 0;
	struct form_item * 	tabptr=(struct form_item *) 0;
	int			offset=0;
	char		 *	tptr=(char *) 0;

	/* Clear radio button values */
	/* ------------------------- */
	for (	fptr->objects=0,
		fptr->pages=0, 
		fptr->focus=0,iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next )
		iptr->Contents.radio = 0;

	for (	fptr->pages=0, fptr->focus=0,iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  ))) {
			iptr->Contents.focus = 
			iptr->Contents.page  = 0;
			continue;
			}

		switch ((iptr->Contents.style & _FRAME_TYPE)) {

			case	_DATA_FRAME	:
				if ((iptr->Contents.align & 0x000F) == _VISUAL_FRAME) {
					fptr->objects++;
					/* Button / Check / Radio Take Focus */
					/* --------------------------------- */
					if (( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )
					||  ( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS     ))
						iptr->Contents.focus = ++fptr->focus;
					else	iptr->Contents.focus = 0;
					iptr->Contents.page  = 
						visual_page_number( tabptr, iptr );
					}
				continue;

			case	_WINDOW_FRAME	:
				/* Windows have no page and no focus */
				/* --------------------------------- */
				iptr->Contents.page  = fptr->pages = fptr->focus = 0;
				
				if (( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )
				||  ( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS     ))
					iptr->Contents.focus = ++fptr->focus;
				else	iptr->Contents.focus = 0;
				continue;

			case	_TAB_FRAME	:
				/* Tab Frames take focus and Change Page */
				/* ------------------------------------- */
				iptr->Contents.page  = ++fptr->pages;
				if (( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )
				||  ( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS     ))
					iptr->Contents.focus = ++fptr->focus;
				else	iptr->Contents.focus = 0;
				iptr->Contents.adjust= offset;
				offset = calculate_page_tab( offset, iptr );
				tabptr   = iptr;
				continue;

			case	_SELECT_FRAME	:
				/* Select can Take Focus */
				/* --------------------- */
				if (( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )
				||  ( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS     ))
					iptr->Contents.focus = ++fptr->focus;
				else	iptr->Contents.focus = 0;
				calculate_select( iptr );
				iptr->Contents.page  = 
					visual_page_number( tabptr, iptr );
				continue;


			case	_EDIT_FRAME	:
				/* Constant Edit Frames do not take Focus */
				/* -------------------------------------- */
				if ( iptr->Contents.datatype == _WIDGET_KONSTANT ) {
					iptr->Contents.focus = 0;
					iptr->Contents.page  = 
						visual_page_number( tabptr, iptr );
					continue;
					}


			case	_RADIO_FRAME	:
				if (!( iptr->Contents.radio )) 
					calculate_radio( iptr, iptr->Contents.name );

			case	_BUTTON_FRAME	:
			case	_CHECK_FRAME	:
			case	_SWITCH_FRAME	:
			case	_GRAPH_FRAME	:
				/* Button / Check / Radio Take Focus */
				/* --------------------------------- */
				if (( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )
				||  ( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS     ))
					iptr->Contents.focus = ++fptr->focus;
				else	iptr->Contents.focus = 0;
				iptr->Contents.page  = 
					visual_page_number( tabptr, iptr );
				continue;

			default			:
				/* All others : No Focus */
				/* --------------------- */
				if (( iptr->Contents.events.xo_get_focus & _EVENT_IS_FOCUS )
				||  ( iptr->Contents.events.xo_event & _EVENT_IS_FOCUS     ))
					iptr->Contents.focus = ++fptr->focus;
				else	iptr->Contents.focus = 0;
				iptr->Contents.page  = 
					visual_page_number( tabptr, iptr );
				continue;
			}
		}

	/* If Pages are present then ensure page mechanism active */
	/* ------------------------------------------------------ */
	if (( fptr->pages != 0 ) &&  (!( fptr->page_number )))
		fptr->page_number = 1;

	return;
}

public	void	form_Dimensions( 
	struct window_control * wptr,
	struct form_control   * fptr)
{
	int	fh;
	struct form_item * optr;

	wptr->x = -1; wptr->y = -1;
	wptr->w = 0; wptr->h = 0;

	for (	optr=fptr->first;
		optr != (struct form_item *) 0;
		optr = optr->next ) {

		if ((optr->Contents.style & _FRAME_TYPE) == _LINE_FRAME )
			continue;

		if (((optr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME )
		&&  ( optr->Contents.style & _A_SHADOW ))
			fh = 10;
		else	fh = 0;

		if ( wptr->x == -1 ) {
			wptr->x = optr->Contents.x;
			wptr->y = optr->Contents.y;
			wptr->w = (optr->Contents.w+fh);
			wptr->h = (optr->Contents.h+fh);
			}
		else	{
			if ( optr->Contents.x < wptr->x ) {
				wptr->w += (wptr->x - optr->Contents.x);
				wptr->x = optr->Contents.x;
				}
			if ( optr->Contents.y < wptr->y ) {
				wptr->h += (wptr->y - optr->Contents.y);
				wptr->y = optr->Contents.y;
				}
			if (( optr->Contents.x + optr->Contents.w + fh)
	  		     >  ( wptr->x+wptr->w ))
				wptr->w = (( optr->Contents.x + optr->Contents.w + fh )-wptr->x);
			if (( optr->Contents.y + optr->Contents.h + fh)
  			      >  ( wptr->y+wptr->h ))
				wptr->h = (( optr->Contents.y + optr->Contents.h + fh )-wptr->y);
			continue;
			}
		}
	return;
}


private	int	page_Dimensions( struct window_control * wptr, struct form_control * fptr )
{
	if (!( wptr ))
		return(0);

	wptr->x = wptr->y = wptr->w = wptr->h = 0;

	if (!( fptr ))
		return(0);

	switch ( fptr->formflags & _FORM_TYPE_FLAGS ) {
		case	_FORM_TYPE_DIALOG	:
		case	_FORM_TYPE_EVENT 	:
			return(0);

		case	_FORM_TYPE_SCROLL	:
		case	_FORM_TYPE_PAGE  	:
			if ( Context.Form->printout.Layout != 1 ) {
				collect_paper_dimensions( 
					&wptr->h,&wptr->w, 
					page_resolution(),
					(Context.Form->printout.PaperType-1) );
				}
			else	{
				collect_paper_dimensions( 
					&wptr->w,&wptr->h, 
					page_resolution(),
					(Context.Form->printout.PaperType-1) );
				}
			break;
		}
	return(1);

}

private	void	show_paper_info(struct form_control * fptr )
{
	char			message[120];
	struct 	window_control  Paper;
	char 	*		tptr=(char*) 0;
	char 	*		sptr=(char*) 0;
	if (!( fptr ))
		return;
	else if (!( page_Dimensions( &Paper, fptr ) ))
		return;
	else	{
		while (!( sptr = Context.paper_types ))
			if (!( Context.paper_types = allocate_string(WidgetPaperTypes) ))
				return;
		if ((tptr = selection_item(Context.Form->printout.PaperType-1,sptr)) != (char *) 0) {
			sprintf(message,"%s %u x %u pts",tptr,Paper.w,Paper.h);
			liberate( tptr );
			}
		else	sprintf(message,"Paper %u x %u pts",Paper.w,Paper.h);
		status_message(message,3);
		return;
		}
}



public 	void	show_Form(struct form_control * fptr, int refresh)
{
	int	sy,sx;
	int	hx,hy,tr;
	int	maxcol;
	int	maxrow;
	int	pixelsize=get_pixel_size();
	char *	bptr;
	struct window_control  Window;
	struct form_item * iptr;

	if (!( fptr->first ))
		return;

	/* Determine overall Form Window Dimensions and Position */
	/* ----------------------------------------------------- */
	form_Dimensions( &Window, fptr );

	if ((!( fptr->Buffer.value ))
	||   ( Window.w != fptr->Buffer.width )
	||   ( Window.h != fptr->Buffer.height )) {

		drop_Form_buffer( fptr );

		fptr->Buffer.value = allocate_graphic_storage(
					0,0,
					((fptr->Buffer.width = Window.w)+16),
					((fptr->Buffer.height = Window.h)+16));

		}

	/* Position the Forms Capture Buffer */
	/* --------------------------------- */
	if ( fptr->Buffer.value ) {
		hx = Context.DeskTop.x;
		hy = Context.DeskTop.y;
		Context.DeskTop.x = -Window.x;
		Context.DeskTop.y = -Window.y;
		background_pixel_capture( fptr->Buffer.value );
		}

	/* Draw Desktop member Items */
	/* ------------------------- */
	for (iptr=fptr->first; iptr != (struct form_item *) 0; iptr = iptr->next )
		draw_Widget( fptr,iptr );


	/* Displayed the Captured Form Image and Controls */
	/* ---------------------------------------------- */
	if ( fptr->Buffer.value ) {

		Context.DeskTop.x = hx;
		Context.DeskTop.y = hy;

		cancel_pixel_capture( fptr->Buffer.value );

		/* test to see if called for image preparation only */
		/* ------------------------------------------------ */
		if (!( refresh ))	return;

		/* Otherwise display the scrollbars and form image */
		/* ----------------------------------------------- */
		maxcol = fptr->Buffer.width; 
		maxrow = fptr->Buffer.height;

		if ((Window.x+maxcol) > Context.DeskTop.w) {
			desktop_Hscroll(
				&fptr->Buffer.x,
				fptr->Buffer.width 
				);
			if ((maxcol = (Context.DeskTop.w - Window.x)) <= 0 )
				return;
			}
		else	desktop_Hscroll((int *)0,0);

		if ((Window.y+maxrow) > Context.DeskTop.h) {
			desktop_Vscroll(
				&fptr->Buffer.y,
				fptr->Buffer.height );
			if ((maxrow = (Context.DeskTop.h - Window.y)) <= 0)
				return;
			}
		else	desktop_Vscroll((int * )0,0);


		sy = fptr->Buffer.y; sx = fptr->Buffer.x; 

		for (tr=0; tr < maxrow; tr++ ) {

			if (!( bptr = connect_pixel_row( fptr->Buffer.value, sy+tr )))
				break;
			else	putzone(Context.DeskTop.x+Window.x,
					Context.DeskTop.y+Window.y+tr,
					maxcol,1, (bptr+(sx*pixelsize)) );

			}


		draw_desktop_scroll();

		}

	return;
}

public	void	calibrate_Form(struct form_control * fptr)
{
	if ( fptr->Buffer.value ) {
		fptr->Buffer.x = fptr->Buffer.y = 0;
		}
	return;
}

public	void	draw_Form(struct form_control * fptr, int refresh)
{
	int	pas;
	int	atrow;
	int	fh;
	int	fw;
	int	items;
	char *	gptr;
	struct form_item * iptr;

	if (!( fptr ))	return;
		
	prepare_Form( fptr );

	if ( fptr->display == _EDIT_CLASS ) {
		if ( Context.DeskTop.style != _SCROLL_FRAME ) 
			activate_DeskTop( _SCROLL_FRAME );

		fh = guifontsize(1);	
		fw = (fh & 0x00FF);
		fh >>= 8;	
		fh &= 0x00FF;

		/* Draw Desktop member Items */
		/* ------------------------- */
		if (!( fptr->top )) {
			fptr->current = fptr->top = fptr->first;
			}

		for (	items=0, iptr = fptr->first;
			iptr != (struct form_item *) 0; 
			iptr = iptr->next )
				iptr->unique=++items;

		if (!( items )) items = 1;
		
		if (!( iptr = fptr->top ))
			Context.ScrollBar.y = items;
		else	Context.ScrollBar.y = iptr->unique;

		Context.ScrollBar.h = items;

		for (	items=1,atrow=0,iptr=fptr->top; 
			iptr != (struct form_item *) 0; 
			iptr = iptr->next, items++ ) {
			iptr->shatx = 0; iptr->shaty = atrow;
			iptr->shitem = items;
			show_Widget( iptr, 0 );
			atrow += fh;
			if ( atrow >= Context.DeskTop.h )
				break;
			}

		fptr->items = items;

		}

	else	{

		if ( Context.DeskTop.style == _SCROLL_FRAME ) 
			activate_DeskTop( _OUTSET_FRAME );

		if ( refresh ) {
			hide();

			/* Draw Desktop Grid if Active */
			/* --------------------------- */	
			if ( Context.gridlockw != 0 ) {

				if (!( Context.gridbuffer )) 
					Context.gridbuffer = allocate( (Context.DeskTop.w * 2) );

				/* preparation of horizontal row grid */
				/* ---------------------------------- */
				if ((gptr = Context.gridbuffer) != (char *) 0) {
					for ( 	pas=0;
						pas < Context.DeskTop.w;
						pas++ ) {
						if (!( (pas+1) % Context.gridlockw ))
							*(gptr+pas) = standard_black;
						else	*(gptr+pas) = standard_white;
						}
					}
	
				/* Horizontal Lines */
				/* ---------------- */
				for ( 	pas=0;
					pas < Context.DeskTop.h;
					pas++ ) {
					if (!( (pas+1) % Context.gridlockh )) {
						filzone(Context.DeskTop.x+1,Context.DeskTop.y+pas,
							Context.DeskTop.w-2,1,standard_black);
						}
					else if (!( gptr ))
						continue;
					else	{
						putzone8(Context.DeskTop.x+1,Context.DeskTop.y+pas,
							Context.DeskTop.w-2,1,gptr );
						}
					}
				}
			}


		show_Form( fptr,refresh );

		if ( refresh ) {
			show( 	Context.DeskTop.x, 
				Context.DeskTop.y, 
				Context.DeskTop.w,
				Context.DeskTop.h  );
			}
		}

	/* Ensure Item Name is valid */
	/* ------------------------- */
	if ((iptr = fptr->current) != (struct form_item *) 0)
		if (!( iptr->Contents.name ))
			iptr->Contents.name = automatic_name(iptr->number);

	/* Display current item and information */
	/* ------------------------------------ */
	if ( refresh ) {
		show_item_info(fptr->current);
		show_paper_info(fptr);
		}

	return;
}

private	int	is_widget_member(
		struct form_item * pptr,
		struct form_item * mptr)
{
	/* Question : Is MPTR a member of WPTR */
	/* ----------------------------------- */
	if (( pptr->Contents.page != 0)
	&&  ( pptr->Contents.page != mptr->Contents.page ))
		return(0);

	/* Ensure different widget */
	/* ----------------------- */
	else if ( pptr->number == mptr->number )
		return(0);

	/* Separate LINE from other */
	/* ------------------------ */
	else if (( mptr->Contents.style & _FRAME_TYPE) == _LINE_FRAME) {
		if (( mptr->Contents.x >= pptr->Contents.x )
		&&  ( mptr->Contents.y >= pptr->Contents.y )
		&&  ( mptr->Contents.w 
		<=   (pptr->Contents.x + pptr->Contents.w ))
		&&  (mptr->Contents.h 
		<=   (pptr->Contents.y + pptr->Contents.h )))
			return( 1 );
		else	return( 0 );
		}
	else	{
		if (( mptr->Contents.x >= pptr->Contents.x )
		&&  ( mptr->Contents.y >= pptr->Contents.y )
		&&  ((mptr->Contents.x + mptr->Contents.w )
		<=   (pptr->Contents.x + pptr->Contents.w ))
		&&  ((mptr->Contents.y + mptr->Contents.h )
		<=   (pptr->Contents.y + pptr->Contents.h )))
			return( 1 );
		else	return( 0 );
		}

}

private	void	move_widget_members(
		struct form_item * iptr,
		int	xadjust,
		int	yadjust )
{
	struct form_item * mptr;

	/* Adjust all others by same amount */
	/* -------------------------------- */
	for (	mptr=Context.Form->first;
		mptr != (struct form_item *) 0;
		mptr = mptr->next ) {

		if (!( is_widget_member( iptr, mptr ) ))
			continue;

		switch ((mptr->Contents.style & _FRAME_TYPE)) {
			case	_LINE_FRAME 	:
				mptr->Contents.x += xadjust;
				mptr->Contents.y += yadjust;
				mptr->Contents.w += xadjust;
				mptr->Contents.h += yadjust;
				break;
			default			:
				mptr->Contents.x += xadjust;
				mptr->Contents.y += yadjust;
				break;
			}
		}
	return;
}

private	void	on_reposition(
		struct form_item * iptr,
		struct window_control * wptr 
		)
{
	struct form_item * mptr;
	int	xadjust = 0;
	int	yadjust = 0;

	if ( iptr->Contents.events.control & _IS_XO_LOCK )
		return;

	xadjust = (wptr->x - iptr->Contents.x);
	yadjust = (wptr->y - iptr->Contents.y);

	switch ((iptr->Contents.style & _FRAME_TYPE)) {

		case	_LINE_FRAME 	:
			iptr->Contents.x += xadjust;
			iptr->Contents.y += yadjust;
			iptr->Contents.w += xadjust;
			iptr->Contents.h += yadjust;
			break;

		case	_CUT_FRAME	:
			move_widget_members( iptr, xadjust, yadjust );
			iptr->Contents.x = wptr->x;
			iptr->Contents.y = wptr->y;
			break;

		case	_WINDOW_FRAME	:

			if ( Context.lockon ) {
				move_widget_members( iptr, xadjust, yadjust );
				}
			
		default			:
			iptr->Contents.x = wptr->x;
			iptr->Contents.y = wptr->y;
			break;
		}
	return;
}

private	void	on_resize(
		struct form_item * iptr,
		struct window_control * wptr )
{
	if ( iptr->Contents.events.control & _IS_XO_LOCK )
		return;

	switch ((iptr->Contents.style & _FRAME_TYPE)) {
		case	_TEXT_FRAME 	:
			resize_text( iptr, wptr->w, wptr->h );
			break;

		case	_IMAGE_FRAME 	:
			resize_image( iptr, wptr->w, wptr->h );
			break;

		case	_LINE_FRAME	:
			iptr->Contents.w = wptr->w;
			iptr->Contents.h = wptr->h;
			break;

		default			:
			iptr->Contents.w = wptr->w;
			iptr->Contents.h = wptr->h;
			break;
		}
	return;
}

private	void	remove_widget(
	struct form_control * fptr,
	struct form_item * iptr )
{
	if ( iptr->next ) {
		fptr->current = iptr->next;
		if (!(iptr->next->previous = iptr->previous))
			fptr->first = iptr->next;
		else	iptr->previous->next = iptr->next;
		}
	else if ( iptr->previous ) {
		fptr->last = iptr->previous;
		fptr->current = iptr->previous;
		iptr->previous->next = (struct form_item *) 0;
		}
	else	{
		fptr->first 	= 
		fptr->last 	= 
		fptr->current = (struct form_item *) 0;		
		}
}

private	void	delete_widget(struct form_control * fptr)
{
	struct form_item * iptr;

	if ((iptr = fptr->current) != (struct form_item *) 0) {
		if (!( iptr->Contents.events.control & _IS_XO_LOCK )) {
			remove_widget( fptr, iptr );
			remove_treenode( iptr->treenode );
			if ((iptr->next = Context.UndoList) != (struct form_item *) 0)
				iptr->next->previous = iptr;
			Context.UndoList = iptr;
			iptr->previous = (struct form_item *) 0;
			/* iptr = liberate_Widget( iptr ); */
			}
		}
	return;
}

public 	void	show_form_selection(struct form_control * fptr,int mode)
{
	if ( fptr->display == _EDIT_CLASS )
		show_Widget( fptr->current, 2 );

	else	{
		if ( 	(!( fptr->active ))
		&&   	( Context.Image.state )
		&& 	( Context.Image.width  > 0 )
		&&  	( Context.Image.height > 0 )
			)
			visual_frame(	
				(Context.DeskTop.x + Context.Image.x),
				(Context.DeskTop.y + Context.Image.y),
				Context.Image.width,
				Context.Image.height,
				_CUT_FRAME);
		if ( fptr ) {
			focus_treenode( fptr->treenode, mode );
			if (( fptr->current )
			&&  ( fptr->treenode->state & _TREE_OPEN ))
				focus_treenode( fptr->current->treenode, mode );
			}
		}
	return;
}

private	void	hide_form_selection(struct form_control * fptr,int mode)
{
	if ( fptr->display == _EDIT_CLASS )
		show_Widget( fptr->current, 0 );
	else	show_form_selection(fptr,mode);
	return;
}

private	void	save_Widget(FILE * handle, struct form_item * iptr, int version )
{
	int	v;
	int	i;
	char *	mptr;

	/* Never save these two types */
	/* -------------------------- */
	switch ((iptr->Contents.style & _FRAME_TYPE)) {
		case	_CUT_FRAME	:
		case	_MOVE_FRAME	:
			return;
		}

	check_Widget( iptr );

	/* Save all the others */
	/* ------------------- */
	put_word(handle,iptr->Contents.style );
	put_string(handle,iptr->Contents.name);
	put_word(handle,iptr->Contents.x     );
	put_word(handle,iptr->Contents.y     );
	put_word(handle,iptr->Contents.w     );
	put_word(handle,iptr->Contents.h     );
	put_word(handle,iptr->Contents.colour);
	put_word(handle,iptr->Contents.font  );
	put_word(handle,iptr->Contents.align );
	
	v = ( iptr->Contents.datatype | ( iptr->Contents.interfaceitem ? 0x0100 : 0 ) );
	put_word(handle, v /* iptr->Contents.datatype */ );
	put_word(handle,iptr->Contents.trigger  );

	switch ((iptr->Contents.style & _FRAME_TYPE)) {
		case	_LINE_FRAME	:
			put_word(handle,iptr->Contents.size  );
			break;
		case	_GROOVE_FRAME	:
		case	_RIDGE_FRAME	:
		case	_INSET_FRAME	:
		case	_OUTSET_FRAME	:
		case	_EDIT_FRAME	:
		case	_SELECT_FRAME	:
		case	_SWITCH_FRAME	:
		case	_GRAPH_FRAME	:
		case	_CHECK_FRAME 	:
		case	_RADIO_FRAME 	:
		case	_BUTTON_FRAME	:
		case	_WINDOW_FRAME	:
		case	_TAB_FRAME	:
		case	_FORM_FRAME	:
		case	_TEXT_FRAME	:
		case	_DATA_FRAME	:
		case	_IMAGE_FRAME	:
			if ( version & _INTERNATIONAL ) {
				put_byte( handle, MAXNATLANG );
				for (i=0; i < MAXNATLANG; i++ ) {
					if (!( mptr = iptr->Contents.messages[i] ))
						put_byte  ( handle,0   );
					else	put_string( handle,mptr );		
					}
				}
			else	{
				if (!( iptr->Contents.payload ))
					put_byte(handle,0);
				else	put_string(handle,iptr->Contents.payload );
				}

		}
	if (!( iptr->Contents.format ))
		put_byte(handle,0);
	else	put_string(handle,iptr->Contents.format);
	save_event_control( handle, & iptr->Contents.events );
	put_word(handle,iptr->doctool);
	if ( version & _INTERNATIONAL ) {
		for (i=0; i < MAXNATLANG; i++ ) {
			if (!( mptr = iptr->document[i] ))
				put_byte  ( handle,0   );
			else	put_string( handle,mptr );		
			}
		}
	else	{
		if (!( iptr->document[0] ))
			put_byte(handle,0);
		else	put_string(handle,iptr->document[0] );
		}
	return;
}

public 	void	get_context_defaults( struct form_control * fptr )
{
	fptr->gridlock = get_context_gridlock();
	fptr->gridsize = get_context_gridsize();
	fptr->font     = Context.Item.font;
	fptr->foreground= Context.foreground;
	fptr->background= Context.background;
	fptr->thickness = Context.thickness;
	fptr->using     = Context.style;
	return;
}

private	void	set_context_defaults( struct form_control * fptr )
{
	set_context_gridlock(fptr->gridlock);
	set_context_gridsize(fptr->gridsize);
	configure_gridlock(1);
	Context.Item.font = fptr->font;
	Context.foreground = fptr->foreground;
	Context.background = fptr->background;
	Context.thickness  = fptr->thickness;
	Context.usingtool  = fptr->using;
	Context.style	   = fptr->using;
	return;
}

public 	int	save_Form( struct form_control * fptr,int automatic )
{
	struct form_item * iptr;
	struct	forms_method * mptr;
	char		 * dtdname=(char *) 0;
	FILE		 * h;
	int	i;
	int	v;
	int	o;

	if (!( fptr->loadname )) {
		if (!(fptr->loadname = allocate_string( "new" ) ))
			return(27);
		}

	if (!( system_xml ))
		fptr->loadname = verify_extension( fptr->loadname, MODEL_EXTENSION );
	else	fptr->loadname = verify_extension( fptr->loadname, XML_EXTENSION );

	if (!( automatic & _INHIBIT_PROPERTIES )) {
		if ( accept_form_save(&fptr->loadname) == 27 ) {
			draw_console();
			return(0);
			}
		else if (!( system_xml ))
			fptr->loadname = verify_extension( fptr->loadname, MODEL_EXTENSION );
		else	fptr->loadname = verify_extension( fptr->loadname, XML_EXTENSION );

		status_message(fptr->loadname,3);
		}

	if ( detect_extension( fptr->loadname, XML_EXTENSION ) ) {
		if (!(dtdname = getenv("SINGXML")))
			dtdname = "sing.dtd";
		xml_put_Form( fptr, "sing.dtd" );
		if ( fptr ) { fptr->outofdate = 0; }
		return(0);
		}
	
	/* set alternative cursor */
	x_event(33);

 	if ((h = open_production_target(fptr->loadname,1)) != (FILE*) 0) {

		status_message(fptr->loadname,3);

		put_string(h,"SING");
		put_string(h,LaPaterne);
	
		o = (fptr->formflags & _INTERNATIONAL);

		put_word(h,(0x0007  | o | _DOCUMENTATION | __WIDGET_TYPE | _EXTENDED_EVENTS | _METHOD_FILE | _LABEL_FRAME | _WIDGET_TRIGERS | _WIDGET_FORMAT ));

			put_string(h,fptr->identifier);

			if ( fptr->isprogram ) 	v  = 1;
			else			v  = 0;

			if ( fptr->isoverlay ) 	v |= 2;

			if ( fptr->ispopup   ) v |= 4;
				
			put_word( h, v );

			/* Will be extended as form type */

			if (( fptr->formflags & 2) != 0)
				fptr->formflags |= (4|8);

			put_word( h, fptr->formflags );

			if ( fptr->formflags & 4 ) {
				put_word( h, fptr->printout.TopMargin );
				put_word( h, fptr->printout.BottomMargin );
				put_word( h, fptr->printout.LeftMargin );
				put_word( h, fptr->printout.RightMargin );
				put_word( h, fptr->printout.ZoneWidth );
				put_word( h, fptr->printout.ZoneHeight );
				put_word( h, fptr->printout.Layout );	
				put_word( h, fptr->printout.PaperType );
				put_word( h, fptr->printout.PrintResolution );
				put_string(h, fptr->printout.PageHead );
				put_string(h, fptr->printout.DriverName );
				put_word( h, fptr->printout.Alignment );	
				put_word( h, fptr->printout.FeedOpt );
				put_word( h, fptr->printout.Preview );
				put_string(h,fptr->printout.DeviceName);

				fptr->formflags &= ~4;
				fptr->formflags &= ~8;
				}

			put_word(h,Context.alignment);

			put_string(h, fptr->construction );
			put_string(h, fptr->dependance );

			put_word(h,fptr->font);
			put_word(h,fptr->foreground);
			put_word(h,fptr->background);
			put_word(h,fptr->gridlock);
			put_word(h,fptr->gridsize);
			put_word(h,fptr->thickness);
			put_word(h,fptr->using );


			put_string(h,fptr->prodname);

			v = (fptr->language | (Context.imageformat << 8));

			put_word(h,v);
			put_word(h,fptr->using/*Context.style*/);
			put_word(h,Context.Image.x);
			put_word(h,Context.Image.y);
			put_word(h,Context.Image.width);
			put_word(h,Context.Image.height);
			put_word(h,Context.Image.depth);
			put_word(h,Context.Image.type);
			put_word(h,Context.Image.state);

		put_word(h,FONT_MAX);
			for (i=0; i < FONT_MAX; i++ ) {
				put_word(h,i);
				put_string(h,font_name[i]);
				}

		put_word(h,Context.numbering);

			put_word( h, fptr->doctool );
			if (!( fptr->formflags & _INTERNATIONAL))
				put_string(h, fptr->document[0] );
			else	{
				for (i=0; i < MAXNATLANG; i++ )
					put_string(h, fptr->document[i] ); 
				}

			for (iptr=fptr->first; iptr != (struct form_item *) 0; iptr = iptr->next ) {
				if ((!( iptr->Contents.w  ))
				||  (!( iptr->Contents.h  )))
					continue;
				else	{
					if ( o & _INTERNATIONAL )
						set_national_payload(iptr,fptr->natlang);
					save_Widget(h,iptr,o);
					if ( o & _INTERNATIONAL )
						get_national_payload(iptr,fptr->natlang);
					}
				}

		put_word(h,0x1A1A);	/* End of Widgets */

		put_word(h, fptr->mimoflags );
		put_word(h, fptr->natlang );
		put_word(h, fptr->abal.flags);
		put_word(h, fptr->abal.values);
		put_word(h, fptr->abal.diezemem);
		put_word(h, fptr->abal.diezefiles);
		put_word(h, fptr->abal.diezestack);
		put_word(h, fptr->abal.diezeheap);
		put_word(h, fptr->abal.tokensize);
		put_word(h, fptr->abal.labelsize);

		for (	mptr=fptr->rootmethod;	mptr != (struct forms_method *) 0; mptr = mptr->next ) {
			if (!( mptr->name )) {
				continue;
				}
			else	{
				put_word(h, mptr->type 		);
				put_string(h, mptr->name 	);
				put_string(h, mptr->signature 	);
				put_string(h, mptr->text 	);
				put_string(h, mptr->klass	);
				}
			}

		put_word(h,0x1A1A);	/* End of File */
		put_word(h,0x1A1A);	/* End of File */
		put_word(h,0x1A1A);	/* End of File */
		put_word(h,0x1A1A);	/* End of File */
		put_word(h,0x1A1A);	/* End of File */
		put_word(h,0x1A1A);	/* End of File */
		put_word(h,0x1A1A);	/* End of File */
		put_word(h,0x1A1A);	/* End of File */
		put_word(h,0x1A1A);	/* End of File */
		put_word(h,0x1A1A);	/* End of File */
		put_word(h,0x1A1A);	/* End of File */
		put_word(h,0x1A1A);	/* End of File */
		put_word(h,0x1A1A);	/* End of File */
	
		close_production_target(h,fptr->loadname);
		fptr->outofdate = 0;

		if ((dtdname = getenv("SINGXML")) != (char *) 0) { xml_put_Form( fptr, dtdname ); }

		if (!( automatic & _INHIBIT_REFRESH ))
			draw_console();

		}
	else	{
		if (!( automatic & _INHIBIT_REFRESH ))
			draw_console();
		sprintf(namebuffer,"error:%s.c","new");
		if (!( automatic & _INHIBIT_STATUS  ))
			status_message(namebuffer,3);
		else	printf("%s\n",namebuffer);
		}

	/* restore standard cursor */
	x_event(34);
	return(0);

}

public	void	get_national_payload(struct form_item * iptr, int i )
{
	if (!(iptr->Contents.payload = iptr->Contents.messages[i])) {
		iptr->Contents.size = 0;
		return;
		}
	else	{
		iptr->Contents.messages[i] = (char *) 0;
		iptr->Contents.size = strlen( iptr->Contents.payload );
		return;
		}	
}

public 	void	set_national_payload(struct form_item * iptr, int i )
{
	iptr->Contents.messages[i] = iptr->Contents.payload;
	iptr->Contents.payload     = (char *) 0;
	iptr->Contents.size	   = 0;
	return;
}

private	void	get_payload( FILE * h, struct form_item * iptr )
{
	int	n;
	int	i;
	struct	form_control * fptr;
	if (!( n = get_byte(h) ))
		return;
	for (i=0; i < n; i++ )
		iptr->Contents.messages[i] = get_string(h);
	if (!( fptr = iptr->parent ))
		return;
	get_national_payload(iptr,fptr->natlang);
}

private	int 	load_Widget(struct form_control * fptr,FILE * handle, int reset,struct image_control * mptr, int version )
{
	char	*	wtptr=(char *) 0;
	int	i;

	struct form_item * iptr=(struct form_item *) 0;
	int	t;
	if ((t = get_word(handle)) != 0x1A1A ) {
		if (!(iptr = allocate_for_Widget()))
			return( 0x1A1A );

		else	{
			iptr->parent = fptr;
			reset_event_control(&iptr->Contents.events,t);
			iptr->Contents.style 	= t;
			iptr->number =++Context.numbering;
			iptr->Contents.name     = get_string(handle);
			iptr->Contents.x 	= get_word(handle);
			iptr->Contents.y 	= get_word(handle);
			iptr->Contents.w 	= get_word(handle);
			iptr->Contents.h 	= get_word(handle);
			if ((!( reset ))
			&&  ( Context.Image.state != 0 )
			&&  ( mptr->state != 0 )) {
				/* adjust top left corner of all items */
				iptr->Contents.x -= mptr->x;
				iptr->Contents.y -= mptr->y;
				iptr->Contents.x += Context.Image.x;
				iptr->Contents.y += Context.Image.y;
				if ((iptr->Contents.style & _FRAME_TYPE) == _LINE_FRAME	) {
					/* adjust bottom right corner for lines */
					iptr->Contents.w -= mptr->x;
					iptr->Contents.h -= mptr->y;
					iptr->Contents.w += Context.Image.x;
					iptr->Contents.h += Context.Image.y;
					}
				}

			iptr->Contents.colour 	= get_word(handle);
			iptr->Contents.font   	= get_word(handle);

			iptr->Contents.align = get_word(handle);
			if ( version & __WIDGET_TYPE ) {
				iptr->Contents.datatype = get_word( handle );
				}
			else if ( version & 2 ) {
				if ((wtptr = get_string( handle)) != (char *) 0) {
					iptr->Contents.datatype = convert_widget_type( wtptr );
					wtptr = liberate( wtptr );
					}
				else	iptr->Contents.datatype = _WIDGET_VOID;
				}				
			else	iptr->Contents.datatype = _WIDGET_VOID;

			if ( version & _WIDGET_TRIGERS ) 
				iptr->Contents.trigger = get_word(handle);

			if ( iptr->Contents.datatype & 0x100 ) 
				iptr->Contents.interfaceitem = 1;
			else	iptr->Contents.interfaceitem = 0;

			iptr->Contents.datatype &= 0x00FF;

			iptr->Contents.payload = iptr->Contents.extra = (void*)0;
			iptr->Contents.size    = 0;

			form_data_type( iptr );

			switch ((iptr->Contents.style & _FRAME_TYPE)) {
				case	_LINE_FRAME	:
					iptr->Contents.size = get_word(handle);
					break;

				case	_FORM_FRAME	:
					if ( version & _INTERNATIONAL )
						get_payload(handle,iptr);
					else	iptr->Contents.payload = get_string(handle);
					break;

				case	_GRAPH_FRAME	:
					if ( version & _INTERNATIONAL )
						get_payload(handle,iptr);
					else 	iptr->Contents.payload = get_string(handle);
					calculate_graph_size(&iptr->Contents);
					break;

				case	_GROOVE_FRAME	:
				case	_RIDGE_FRAME	:
				case	_INSET_FRAME	:
				case	_OUTSET_FRAME	:
				case	_EDIT_FRAME	:
					if (!( version & _LABEL_FRAME ))
						break;
				case	_CHECK_FRAME	:
				case	_RADIO_FRAME	:
						
				case	_SWITCH_FRAME	:
				case	_SELECT_FRAME	:
				case	_BUTTON_FRAME	:
				case	_TAB_FRAME	:
				case	_WINDOW_FRAME	:
				case	_DATA_FRAME	:
				case	_TEXT_FRAME	:
					if ( version & _INTERNATIONAL )
						get_payload(handle,iptr);
					else if ((iptr->Contents.payload = get_string(handle)) != (char *) 0)
						iptr->Contents.size    = strlen(iptr->Contents.payload);
					break;

				case	_IMAGE_FRAME	:
					if ( version & _INTERNATIONAL )
						get_payload(handle,iptr);
					else if ((iptr->Contents.payload = get_string_length(handle,64)) != (char *) 0)
						iptr->Contents.size    = strlen(iptr->Contents.payload);

					break;
				}

			if ( version & _WIDGET_FORMAT )
				iptr->Contents.format = get_string(handle);

			load_event_control( handle, & iptr->Contents.events );

			if (!( version & _EXTENDED_EVENTS ))
				reset_extended_events( &iptr->Contents.events, iptr->Contents.style );

			if ( SystemD & 1 ) {

				iptr->Contents.events.xo_show &= _FUNCTION_NOT_FOCUS;
				iptr->Contents.events.xo_hide &= _FUNCTION_NOT_FOCUS;

				}

			if ( version & _DOCUMENTATION ) {
				iptr->doctool  = get_word( handle );
				if (!( version & _INTERNATIONAL )) {
					iptr->document[0]= get_string( handle );
					if (!( version & _METHOD_FILE )) {
						iptr->document[0] = normalise_method_text( iptr->document[0] );
						normalise_event_methods( &iptr->Contents.events );
						}
					}
				else	{
					for (i=0; i < MAXNATLANG; i++ ) {
						iptr->document[i]= get_string( handle );
						if (!( version & _METHOD_FILE )) {
							iptr->document[i] = normalise_method_text( iptr->document[i] );
							normalise_event_methods( &iptr->Contents.events );
							}
						}
					}
				}
			else	{
				iptr->doctool  = _TEXT_TOOL;
				iptr->document[0] = (char *) 0;
				}

			check_Widget( iptr );
			add_Widget(fptr,iptr,1);
			}
		}
	return(t);
}

public	int	compare_treeview_form ( struct form_control * fptr, char * nptr )
{
	if (!( nptr ))
		return(0);
	else if (!( fptr ))
		return(0);

	if (fptr->identifier != (char *) 0)
		if (!( wildcomp( fptr->identifier, nptr ) ))
			return(1);
	if (fptr->loadname != (char *) 0)
		if (!( wildcomp( fptr->loadname, nptr ) ))
			return(1);
	if (fptr->prodname != (char *) 0)
		if (!( wildcomp( fptr->prodname, nptr ) ))
			return(1);
	return(0);
}

char	*	form_message( struct form_control * fptr )
{
	char *	lptr;
	char *	pptr;
	char *	tptr;
	char *	iptr;
	int	options;

	if (!( Context.form_message_buffer ))
		if (!( Context.form_message_buffer = allocate( 2048 ) ))
			return("allocation failure");

	if (!( iptr = fptr->identifier ))
		iptr = "noname";

	if (!( lptr = fptr->loadname ))
		lptr = "noname";

	if (!( pptr = fptr->prodname ))
		pptr = "noname";

	if ( fptr->isprogram ) {
		if ( fptr->isoverlay )
			tptr = "OVERLAY";
		else	tptr = "PROGRAM";
		}
	else if ( fptr->isoverlay )
		tptr = "MODULE";
	else	tptr = "FILE";

	strcpy( Context.form_message_buffer, "\0");
	options = treeview_options();

	if ((options & 0x0400)) {
		strcat( Context.form_message_buffer, tptr );
		strcat( Context.form_message_buffer, " " );
		}

	if ((options & 0x800 )) {
		strcat( Context.form_message_buffer, iptr );
		strcat( Context.form_message_buffer, " " );
		}

	if ((options & 0x100 )) {
		strcat( Context.form_message_buffer, lptr );
		strcat( Context.form_message_buffer, " " );
		}

	if ((options & 0x0200)) {
		strcat( Context.form_message_buffer, pptr );
		}

	/* 	sprintf( Context.form_message_buffer, "%s (%s) %s",pptr,tptr,lptr);	*/

	return( Context.form_message_buffer);
}

public 	struct form_control * new_Form(struct form_control* fptr, char * nptr )
{
	remove_Form(fptr);
	prepare_form_fields(fptr,nptr);
	return(fptr);
}

public	void	set_context_gridlock( int v )
{
	Context.gridlockw   = (v & 0x00FF);

	if (!( Context.gridlockh   = ((v >> 8) & 0x00FF) ))
		Context.gridlockh = Context.gridlockw;
	return;
}
public	int	get_context_gridlock()
{
	return(((Context.gridlockw & 0x00FF ) | ((Context.gridlockh & 0x00FF ) << 8)));
}

public	void	set_context_gridsize( int v )
{
	Context.gridwidth   = (v & 0x00FF);
	if (!( Context.gridheight  = ((v >> 8) & 0x00FF) ))
		Context.gridheight = Context.gridwidth;
	return;
}

public	int	get_context_gridsize()
{
	return(((Context.gridwidth & 0x00FF ) | ((Context.gridheight & 0x00FF ) << 8)));
}


public 	struct form_control * load_Form(struct form_control* fptr, char * nptr,int reset, int automatic )
{
	struct	forms_method * mptr;
	int	mt;
	struct form_item * iptr;
	FILE	*	h;
	int		status=0;
	int		o;
	int		nb;
	int	t;
	int	i;
	int	n;
	int	v;
	int	fontid;
	int	natlang=0;
	char	*	sptr=(char *) 0;
	char	*	vptr=(char *) 0;
	char	*	loadname = (char *) 0;
	struct 	image_control  Merge;

	Merge.x     = Merge.y     = 
	Merge.width = Merge.height= Merge.state =
	Merge.depth = Merge.type  =  0;

	if (!( loadname = allocate_string( nptr ) ))
		return((struct form_control *) 0);

	if (!( system_xml )) {
		if (!( loadname = verify_extension( loadname, MODEL_EXTENSION ) ))
			return((struct form_control *) 0);
		}
	else if (!( loadname = verify_extension( loadname, XML_EXTENSION ) ))
		return((struct form_control *) 0);


	if (!( automatic & _INHIBIT_PROPERTIES )) {
#ifdef	PROTOTYPE
		if (!( reset )) {
			if ( accept_mergename(&loadname) == 27 ) {
				draw_console();
				loadname = liberate( loadname );
				return((struct form_control *) 0);
				}
			}
		else 
#endif
			if ( accept_form_load(&loadname) == 27 ) {
				draw_console();
				loadname = liberate( loadname );
				return((struct form_control *) 0);
				}
		status_message(loadname,3);
		}

	if ( detect_extension( loadname, XML_EXTENSION ) ) {
		fptr = load_XmlForm( fptr, loadname, reset, automatic );
		check_forms_methods( fptr );
		return( fptr );
		}

	while (!(h = fopen(loadname,"rb"))) {
		if ( automatic & _INHIBIT_PROPERTIES )
			break;
		else if ( file_not_found( loadname ) == 27 )
			break;
		}
	if ( h != (FILE *) 0) {

		if (!( fptr )) {
			if (!( fptr = allocate_Form(loadname))) {
				fclose(h);
				loadname = liberate( loadname );
				return(fptr);
				}
			}
		else	{
			new_Form(fptr, loadname );
			}

		if ( fptr->loadname )
			if (!( automatic & _INHIBIT_STATUS ))
				status_message(fptr->loadname,3);

		if ((!(sptr = get_string(h)))
		||  (!( string_compare(sptr,"SING" )))
		||  (!(vptr = get_string(h)))) {
			incorrect_filetype(loadname);
			loadname = liberate( loadname );
			fclose(h);
			return(fptr);
			}
		else	{
			o = get_word(h);

			if ( reset ) {
				/* not a merge operation so read and use */
				/* ------------------------------------- */
				fptr->identifier = get_string(h);
				v = get_word(h);
				if ( v & 1 )	fptr->isprogram = 1;
				else		fptr->isprogram = 0;
				if ( v & 2 )	fptr->isoverlay = 1;
				else		fptr->isoverlay = 0;
				if ( v & 4 )	fptr->ispopup   = 1;
				else		fptr->ispopup   = 0;

				fptr->formflags = get_word(h);

				if (( fptr->formflags & 4) != 0) {

					macro_get_word( h, fptr->printout.TopMargin );
					macro_get_word( h, fptr->printout.BottomMargin );
					macro_get_word( h, fptr->printout.LeftMargin );
					macro_get_word( h, fptr->printout.RightMargin );
					macro_get_word( h, fptr->printout.ZoneWidth );
					macro_get_word( h, fptr->printout.ZoneHeight );
					macro_get_word( h, fptr->printout.Layout );	
					macro_get_word( h, fptr->printout.PaperType );
					macro_get_word( h, fptr->printout.PrintResolution );
					macro_get_string(h, fptr->printout.PageHead );
					macro_get_string(h, fptr->printout.DriverName);
					macro_get_word( h, fptr->printout.Alignment );	
					macro_get_word( h, fptr->printout.FeedOpt );
					macro_get_word( h, fptr->printout.Preview );
					if (( fptr->formflags & 8) != 0) {
						macro_get_string( h, fptr->printout.DeviceName );
						fptr->formflags &= ~8;
						}
					fptr->formflags &= ~4;
					}

				Context.alignment = get_word(h);

				fptr->construction = get_string(h);

				if ( o & 4 )
					fptr->dependance = get_string(h);
				else	fptr->dependance = (char *) 0;

				fptr->font 	 = Context.Item.font = get_word(h);
				fptr->foreground = Context.foreground = get_word(h);
				fptr->foreground = Context.background = get_word(h);

				set_context_gridlock((fptr->gridlock=get_word(h)));
				set_context_gridsize((fptr->gridsize=get_word(h)));


				fptr->thickness = Context.thickness = get_word(h);
				fptr->using     = Context.usingtool = get_word(h);

				fptr->prodname = get_string(h);

				v		    = get_word(h);
				fptr->language	    = (v & 0x00FF);
				Context.language    = (v & 0x00FF);
				Context.imageformat = (v >> 8);
				fptr->using = Context.style       = get_word(h);

				Context.Image.x     = get_word(h);
				Context.Image.y     = get_word(h);
				Context.Image.width = get_word(h);
				Context.Image.height= get_word(h);
				Context.Image.depth = get_word(h);
				Context.Image.type  = get_word(h);
				Context.Image.state = get_word(h);

				/* step over the fonts for now */
				for (	i=0,n=get_word(h);
					i < n;
					i++ ) {
					if ((fontid = get_word(h)) > 1) {
						get_buffer(h,namebuffer,256);
						/* 
						font_load(fontid,namebuffer,0);
						*/
						}
					else	(void) get_buffer(h,(char *) 0,0);
					}
				Context.numbering   = get_word(h);
				}
			else	{
				/* Merging files so dump these */
				/* --------------------------- */
				(void) get_buffer(h,(char *) 0,0);
				(void) get_word(h);
				(void) get_word(h);
				(void) get_word(h);

				/* construction */
				(void) get_buffer(h,(char *) 0,0);

				for (nb=0; nb < 7; nb++ )
					(void) get_word(h);

				/* production target */
				fptr->prodname = get_string(h);

				/* Production language */
				(void) get_word(h);
				/* Merge.style */

				(void) get_word(h);

				Merge.x     = get_word(h);
				Merge.y     = get_word(h);
				Merge.width = get_word(h);
				Merge.height= get_word(h);
				Merge.depth = get_word(h);
				Merge.type  = get_word(h);
				Merge.state = get_word(h);
	
				for (	i=0,n=get_word(h);
					i < n;
					i++ ) {
					(void) get_word(h);
					(void) get_buffer(h,(char *) 0,0);
					}
				if ((i = get_word(h)) > Context.numbering)
					Context.numbering = i;
				}

			if ( o & _DOCUMENTATION ) {
				fptr->doctool = get_word( h );
				if (!( o & _INTERNATIONAL )) {
					fptr->document[0]= get_string( h );
					if (!( o & _METHOD_FILE ))
						fptr->document[0] = normalise_method_text( fptr->document[0] );
					}
				else	{
					for (i=0; i < MAXNATLANG; i++ ) {
 						fptr->document[i]= get_string( h );
						if (!( o & _METHOD_FILE ))
							fptr->document[i] = normalise_method_text( fptr->document[i] );
						}
					}
				}
			else	{
				fptr->doctool = _TEXT_TOOL;
				fptr->document[0]= (char *) 0;
				}

			while (1)
				if ((t = load_Widget(fptr,h,reset,&Merge,o)) == 0x1A1A)
					break;
			}

		if (( fptr->mimoflags = get_word(h)) == 0x1A1A )
			fptr->mimoflags = (_MIMO_SEND_LEFT|_MIMO_SEND_RIGHT|_MIMO_DOWN|_MIMO_UP);

		if (!( fptr->mimoflags & _MIMO_DOWN ))
			fptr->mimoflags |= _MIMO_DOWN;
		if (!( fptr->mimoflags & _MIMO_UP   ))
			fptr->mimoflags |= _MIMO_UP;

		if ((natlang = get_word(h)) == 0x1A1A)
			natlang = 0;
		else if ((fptr->abal.flags = get_word(h)) == 0x1A1A )
			fptr->abal.flags = 0;
		else	{
			fptr->abal.values          =get_word(h); 
			fptr->abal.diezemem        =get_word(h); 
			fptr->abal.diezefiles      =get_word(h); 
			fptr->abal.diezestack      =get_word(h); 
			fptr->abal.diezeheap       =get_word(h); 
			fptr->abal.tokensize       =get_word(h); 
			fptr->abal.labelsize       =get_word(h); 

			while ((mt = get_word(h)) != 0x1A1A ) {
				if (!( mptr = allocate_for_Method() ))
					break;
				else if (!( mptr->name = get_string(h) ))
					break;
				mptr->parent 	= fptr;
				mptr->signature = get_string(h);
				mptr->text 	= get_string(h);
				mptr->klass 	= get_string(h);
				mptr->type 	= mt;
				add_Method( fptr, mptr );
				}

			}

		if ( natlang != fptr->natlang )
			change_national_language(fptr, natlang );

		if ( sptr ) sptr = liberate( sptr );
		if ( vptr ) vptr = liberate( vptr );

		fclose(h);
		if (!( automatic  & _INHIBIT_REFRESH ))
			draw_console();
		loadname = liberate( loadname );
		check_forms_methods( fptr );
		return(fptr);

		}
	else	{
		if (!( automatic  & _INHIBIT_REFRESH ))
			draw_console();
		if (!( automatic  & _INHIBIT_STATUS )) {
 			sprintf(namebuffer,"error:%s.sng",nptr);
			status_message(namebuffer,3);
			}
		loadname = liberate( loadname );
		return((struct form_control *) 0);
		}


}

private	int	use_FormEvent(struct form_control * fptr, int x, int y)
{
	int	i;
	struct form_item * iptr;
	if (( i = is_ConsoleEvent( x, y )) != 0) {
		for (	iptr=fptr->top; 
			iptr != (struct form_item *) 0;
			iptr = iptr->next ) {
			if ( iptr->shitem == i ) {
				hide_form_selection( fptr, 0 );
				fptr->current = iptr;
				show_form_selection( fptr, _TREE_FOCUS );
				break;
				}
			}
		}
	return(256);
}

private	int	StretchFormWidget( struct form_control * fptr, struct form_item * iptr )
{
	int	oldw;
	int	oldh;
	int	inw;
	int	inh;
	int	atx;
	int	aty;
	int	tox;
	int	toy;
	int	movecount=0;
	int	lastevent=0;
	if ((lastevent = visual_event(1)) == _MIMO_DOWN ) {
		inw = iptr->Contents.w;
		inh = iptr->Contents.h;
		atx = visual_event(7);
		aty = visual_event(6);
		cursor_frame(	
			Context.DeskTop.x+iptr->Contents.x,
			Context.DeskTop.y+iptr->Contents.y,
			iptr->Contents.w,iptr->Contents.h,
			_CURSOR_FRAME );
		do	{
			if ( lastevent == _MIMO_WHILE_DOWN )
				movecount=1;
			while ( visual_getch() != 256 );
			if (!( iptr->Contents.events.control & _IS_XO_LOCK ))  {
				if ((tox = visual_event(7)) < Context.DeskTop.x)
					continue;
				else if ( tox > (Context.DeskTop.x+Context.DeskTop.w))
					continue;
				else if ((toy = visual_event(6)) < Context.DeskTop.y)
					continue;
				else if ( toy > (Context.DeskTop.y+Context.DeskTop.h))
					continue;
				oldw = iptr->Contents.w;
				oldh = iptr->Contents.h;
				iptr->Contents.w = (inw + (tox-atx));
				if ( iptr->Contents.w < 0 )
					iptr->Contents.w = 0;
				iptr->Contents.h = (inh + (toy-aty));
				if ( iptr->Contents.h < 0 )
					iptr->Contents.h = 0;
				if ( Context.lockon  )
					apply_gridlock( &iptr->Contents, 6);
				if (( oldw != iptr->Contents.w )
				||  ( oldh != iptr->Contents.h )) {
					draw_Form( fptr, 1 );
					cursor_frame(	
						Context.DeskTop.x+iptr->Contents.x,
						Context.DeskTop.y+iptr->Contents.y,
						iptr->Contents.w,iptr->Contents.h,
						_CURSOR_FRAME );
					}
				}
			}
		while ((lastevent= visual_event(1)) != _MIMO_UP );
		check_Widget( fptr->active );
		form_is_outofdate( fptr );
		fptr->active = (struct form_item *) 0;
		draw_DeskTop();
		}
	return(256);
}

private	int	MoveFormWidget( struct form_control * fptr, struct form_item * iptr )
{
	struct window_control Window;
	int	oldx;
	int	oldy;
	int	inx;
	int	iny;
	int	atx;
	int	aty;
	int	tox;
	int	toy;
	if ( visual_event(1) == _MIMO_DOWN ) {
		inx = iptr->Contents.x;
		iny = iptr->Contents.y;
		atx = visual_event(7);
		aty = visual_event(6);
		cursor_frame(	
			Context.DeskTop.x+iptr->Contents.x,
			Context.DeskTop.y+iptr->Contents.y,
			iptr->Contents.w,iptr->Contents.h,
			_CURSOR_FRAME );
		do	{
			while ( visual_getch() != 256 );
			if (!( iptr->Contents.events.control & _IS_XO_LOCK ))  {
				if ((tox = visual_event(7)) < Context.DeskTop.x)
					continue;
				else if ( tox > (Context.DeskTop.x+Context.DeskTop.w))
					continue;
				else if ((toy = visual_event(6)) < Context.DeskTop.y)
					continue;
				else if ( toy > (Context.DeskTop.y+Context.DeskTop.h))
					continue;

				oldx = iptr->Contents.x;
				oldy = iptr->Contents.y;

				if ((Window.x = (inx + (tox-atx))) < 0) Window.x = 0;
				if ((Window.y = (iny + (toy-aty))) < 0) Window.y = 0;

				if ( Context.lockon  )
					apply_gridlock( &Window,5);

				if (( oldx != Window.x )
				||  ( oldy != Window.y )) {
					if ((iptr->Contents.style & _FRAME_TYPE) == _CUT_FRAME)
						move_widget_members( iptr, (Window.x-oldx),(Window.y-oldy));
					else if (( Context.lockon ) 
					     &&  ((iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME))
						move_widget_members( iptr, (Window.x-oldx),(Window.y-oldy));
					iptr->Contents.x = Window.x;
					iptr->Contents.y = Window.y;
					draw_Form( fptr,1 );
					cursor_frame(	
						Context.DeskTop.x+iptr->Contents.x,
						Context.DeskTop.y+iptr->Contents.y,
						iptr->Contents.w,iptr->Contents.h,
						_CURSOR_FRAME );
						}
				}
			}
		while ( visual_event(1) != _MIMO_UP );
		form_is_outofdate( fptr );
		fptr->active = (struct form_item *) 0;
		draw_DeskTop();
		}
	return(256);
}

private	int	SelectFormWidget( struct form_control * fptr, struct form_item * iptr, int caller )
{
	hide_form_selection(fptr,0);
	fptr->current = fptr->active = iptr;
	/* detect and activate VisualTabPage */
	if ( iptr )
		if (( iptr->Contents.style & _FRAME_TYPE ) == _TAB_FRAME ) 
			fptr->page_number = iptr->Contents.page;
	show_form_selection(fptr,_TREE_FOCUS);
	if ( iptr ) {
		if (!( caller )) {
			if ( Context.Item.style == _SIZE_FRAME )
				return( StretchFormWidget( fptr, iptr ) );
			else	return( MoveFormWidget( fptr, iptr ) );
			}
		}
	return(0);
}

private	int	select_Widget(struct form_control * fptr, int x, int y )
{
	struct form_item * iptr;
	if (!( fptr ))
		return(0);
	else	fptr->active = (struct form_item *) 0;

	for (	iptr=fptr->last; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->previous ) {
		if (( iptr->Contents.style & _FRAME_TYPE ) == _TAB_FRAME ) {
			if (( x >= (iptr->Contents.x+iptr->Contents.adjust))
			&&  ( y >=  iptr->Contents.y)
			&&  ( x <= (iptr->Contents.x+iptr->Contents.adjust+iptr->Contents.xlimit))
			&&  ( y <= (iptr->Contents.y+iptr->Contents.ylimit))) {
				return( SelectFormWidget(fptr, iptr, 0 ) );
				}
			else	continue;
			}
		if ((!( fptr->page_number   ))
		||  (!( iptr->Contents.page ))
		||  ( fptr->page_number == iptr->Contents.page )) {
			if (( iptr->Contents.style & _FRAME_TYPE ) == _LINE_FRAME ) {
				if ((x == iptr->Contents.x )
				&&  (y == iptr->Contents.y )) {
					return( SelectFormWidget(fptr,iptr,0) );
					}
				else if ((x == iptr->Contents.w )
				     &&  (y == iptr->Contents.h )) {
					return( SelectFormWidget(fptr,iptr,0) );
					}
				}
			else if (( iptr->Contents.style & _FRAME_TYPE ) == _SELECT_FRAME ) {
				if (( x >= (iptr->Contents.x+iptr->Contents.adjust))
				&&  ( y >=  iptr->Contents.y)
				&&  ( x <= (iptr->Contents.x+iptr->Contents.adjust+iptr->Contents.xlimit))
				&&  ( y <= (iptr->Contents.y+iptr->Contents.ylimit))) {
					return( SelectFormWidget(fptr, iptr,0 ) );
					}
				}
			else	{
				if ((x >= iptr->Contents.x )
				&&  (y >= iptr->Contents.y )
				&&  (x < (iptr->Contents.x+iptr->Contents.w))
				&&  (y < (iptr->Contents.y+iptr->Contents.h))) {
					return( SelectFormWidget(fptr,iptr,0) );
					}
				}
			}
		}
	return(0);
}


public	int	is_FormEvent(struct form_control * fptr, int x, int y)
{
	int	t;
	int	b;
	struct window_control Window;

	if ( fptr->display == _EDIT_CLASS )
		return( use_FormEvent( fptr, x, y ) );
		
	if (!( Context.Item.style ))
		show_mouse_position(x,y);

	if ( Context.usingtool ) {

		x += fptr->Buffer.x;
		y += fptr->Buffer.y;

		/* detect mous wheel event */
		/* ----------------------- */
		switch ( visual_event(2) ) {
			case	_MIMO_WHEELUP	:
				if ( visual_event(1) == _MIMO_UP ) {
					if ( change_FormMember( fptr, _PREVIOUS_ITEM  ) )
						draw_console();
					}
				return( 256 );

			case	_MIMO_WHEELDOWN	:
				if ( visual_event(1) == _MIMO_UP ) {
					if ( change_FormMember( fptr, _NEXT_ITEM  ) )
						draw_console();
					}
				return( 256 );
			}
		
		switch ((t = visual_event(1))) {

			case	_MIMO_DOWN	:
				Context.Item.w = Context.Item.x = x;
				Context.Item.h = Context.Item.y = y;
				if ((Context.Item.style = Context.style) == _MOVE_FRAME) {
					if ((b = visual_event(2)) == _MIMO_RIGHT )
						Context.Item.style = _SIZE_FRAME;
					if ( select_Widget(fptr,x,y) == 256 )
						return( 256 );
					}
				show_form_cursor(0);
				return(256);

			case	_MIMO_WHILE_DOWN :

				if ( Context.Item.style == -1 ) {
					Context.Item.font = Context.Item.font;
					Context.Item.w = Context.Item.x = x;
					Context.Item.h = Context.Item.y = y;	
					if ((Context.Item.style = Context.style) == _MOVE_FRAME)
						select_Widget(fptr,x,y);
					show_form_cursor(0);
					}
				else	{
					hide_form_cursor(1);
					Context.Item.w = x;
					Context.Item.h = y;
					show_form_cursor(1);
					}			
				return(256);

			case	_MIMO_UP	:
				hide_form_cursor(0);
				if ( fptr->active ) {
					Context.Item.w = x;
					Context.Item.h = y;
					calculate_cursor(&Window);
					if ( Context.Item.style == _MOVE_FRAME )
						on_reposition( fptr->active, &Window );
					else	on_resize( fptr->active,&Window);
					check_Widget( fptr->active );
					form_is_outofdate( fptr );
					fptr->active = (struct form_item *) 0;
					return(257);
					}
				else if ( Context.Item.style != -1 ) {
					Context.Item.w = x;
					Context.Item.h = y;
					if ( Context.Item.style != _MOVE_FRAME ) {
						add_new_item(fptr,visual_event(2));
						if ( Context.dropon ) {
							use_icon_tool(( Context.style = _MOVE_FRAME ));
							}
						}
					Context.Item.style = -1;
					return(257);
					}
			default			:
				return(256);
			}
		}
	else	{
		switch ((t = visual_event(1))) {
			case	_MIMO_UP	:
				hide_form_selection(fptr,0);
				select_current(x,y);
				show_form_selection(fptr,_TREE_FOCUS);
			default			:
				return(256);
			}
		}
	return(-1);
}

public 	struct standard_image * grab_Buffer(
	struct window_control * wptr, 
	struct standard_image * iptr,
	struct buffer_control * bptr )
{
	int	r;
	char *	sptr;
	char *	tptr;
	if ( iptr != (struct standard_image *) 0) {
		if ((iptr->rows    != wptr->h)
		||  (iptr->columns != wptr->w))
			iptr = local_drop_image( iptr );
		}

	if ((!( iptr ))
	&&  (!( iptr = local_allocate_image( wptr->w, wptr->h,0,0 ) )))
		return(iptr);

	for (	r=0; r < wptr->h; r++ ) {
		if (!( tptr = connect_pixel_row( iptr->storage, r ) ))
			break;
		else if (!( sptr = connect_pixel_row( bptr->value , r ) ))
			break;
		else	memcpy(tptr,sptr,wptr->w);
		}
	return( iptr );

}

public 	struct standard_image * grab_Image( 
	struct window_control * wptr, 
	struct standard_image * iptr )
{
	int	r;
	char *	sptr;

	if ( iptr != (struct standard_image *) 0) {
		if ((iptr->rows    != wptr->h)
		||  (iptr->columns != wptr->w))
			iptr = local_drop_image( iptr );
		}

	if ((!( iptr ))
	&&  (!( iptr = local_allocate_image( wptr->w, wptr->h,0,0 ) )))
		return(iptr);

	for (	r=0; r < wptr->h; r++ ) {
		if (!( sptr = connect_pixel_row( iptr->storage, r ) ))
			break;
		else 	getzone(Context.DeskTop.x+wptr->x,(Context.DeskTop.y+wptr->y+r),wptr->w,1,sptr);
		}
	return( iptr );
}

public	void	form_Image(struct form_control * fptr)
{
	struct window_control Window;
	struct	standard_image * grab_Image(struct window_control *, struct standard_image *);

	/* Calculate Entire Form Dimensions */
	/* -------------------------------- */
	form_Dimensions( &Window, fptr );

	/* Nothing so do Nothing */
	/* --------------------- */
	if ((!( Window.h ))
	||  (!( Window.w ))) return;

	/* no buffers active so grab from screen */
	/* ------------------------------------- */
	if (!( fptr->Buffer.value )) {
		fptr->image = grab_Image(&Window, fptr->image );
		}
	else	{
		/* Buffer active so Grab from Buffer */
		/* --------------------------------- */
		fptr->image = grab_Buffer(&Window, fptr->image, &fptr->Buffer );
		}

	fptr->savestamp = time((long *) 0);
	return;
}


private	int	form_editor_event(struct form_control * fptr, int event)
{
	while (1) {
		if ((!( event ))
		||  ( event == _EDIT_FORM ))
			break;				
		else if ( event == _EDIT_IMAGE ) {
			if (!( fptr->current ))
				break;
			else if (!( event = zoom_Widget( &fptr->current->Contents ) )) {
				event = _EDIT_IMAGE;
				break;
				}
			}
		else if ( event == _EDIT_DATABASE ) {
			database_editor();
			event=0;
			break;
			}
		else if ( event == _EDIT_FONT ) {
			if (!( fptr->current ))
				event = font_edit(Context.Item.font);
			else	event = font_edit(fptr->current->Contents.font);
			}
		else if ( event == _EDIT_TEXT ) {				
			if ( fptr->prodname  )
				event = use_editor( fptr->prodname, fptr->language );
			else	event=0; 
			break;
			}
		else 	break;
		}		
	draw_console();
	return(event);
}

private	int	change_FormMember( struct form_control * fptr, int event )
{
	struct 	form_item * iptr;
	iptr = fptr->current;
	switch ( event ) {
		case	_FIRST_ITEM		:
			SelectFormWidget( fptr, fptr->first,1 );
			return(257);

		case	5		:
		case	_NEXT_ITEM		:
			if (!( iptr ))
				break;
			else if (!( iptr->next )) 
				break;

			SelectFormWidget( fptr, fptr->current->next,1 );

			if ( fptr->display != _EDIT_CLASS ) 
				return(257);

			else if ( iptr->shitem == fptr->items ) {
				fptr->top = fptr->top->next;
				return(257);
				}
			else	break;

		case	_LAST_ITEM		:
			SelectFormWidget( fptr, fptr->last,1 );
			return(257);

		case	11		:
		case	_PREVIOUS_ITEM		:
			if (!( iptr ))
				break;
			else if (!( iptr->previous )) 
				break;

			SelectFormWidget( fptr, fptr->current->previous,1 );

			if ( fptr->display != _EDIT_CLASS ) 
				return(257);

			else if ( iptr->shitem  == 1 ) {
				fptr->top = fptr->top->previous;
				return(257);
				}
			else	break;

		}
	return(0);
}

private	struct form_item * locate_typed_widget( struct form_control * fptr, int type )
{
	struct 	form_item * iptr;
	for ( 	iptr=fptr->first; 
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
		if ((iptr->Contents.style & _FRAME_TYPE) == type)
			break;
	
	return( iptr );
}

private	struct form_item * locate_static_widget( struct form_control * fptr )
{
	struct 	form_item * iptr;
	for ( 	iptr=fptr->first; 
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_LINE_FRAME	:
			case	_TEXT_FRAME	:
			case	_IMAGE_FRAME	:
			case	_INSET_FRAME	:
			case	_OUTSET_FRAME	:
			case	_RIDGE_FRAME	:
			case	_GROOVE_FRAME	:
			case	_FILL_FRAME	:
				return(iptr);
			}
		}	
	return( iptr );
}

private	struct form_item * locate_dynamic_widget( struct form_control * fptr )
{
	struct 	form_item * iptr;
	for ( 	iptr=fptr->first; 
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_EDIT_FRAME	:
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
			case	_SELECT_FRAME	:
			case	_SWITCH_FRAME	:
			case	_GRAPH_FRAME	:
				return(iptr);
			}
		}
	return( iptr );
}

private	void	reorder_form( struct form_control * fptr )
{
	struct 	form_item * iptr;
	struct 	form_item * first=(struct form_item *) 0;
	struct 	form_item * last=(struct form_item *) 0;

	/* Locate a window item */
	/* -------------------- */
	if (!( first = locate_typed_widget( fptr, _WINDOW_FRAME )))
		return;
	else	last = first;

	/* Remove from the initial list */
	/* ---------------------------- */
	remove_widget( fptr, first );

	/* Collect static widgets : FRAMES, LINES, TEXT and IMAGES */
	/* ------------------------------------------------------- */
	while ((iptr = locate_static_widget( fptr )) != (struct form_item *) 0) {
		remove_widget( fptr, iptr );
		last->next = iptr;
		iptr->previous = last;
		last=iptr;
		}

	/* Collect dynamic widgets : EDIT, CHECK, RADIO, SELECT */
	/* ---------------------------------------------------- */
	while ((iptr = locate_dynamic_widget( fptr )) != (struct form_item *) 0) {
		remove_widget( fptr, iptr );
		last->next = iptr;
		iptr->previous = last;
		last=iptr;
		}

	/* Collect Push Buttons */
	/* -------------------- */
	while ((iptr = locate_typed_widget( fptr, _BUTTON_FRAME )) != (struct form_item *) 0) {
		remove_widget( fptr, iptr );
		last->next = iptr;
		iptr->previous = last;
		last=iptr;
		}
		
	fptr->current 	= 
	fptr->first 	= first;
	fptr->last  	= last;
	return;

}

public	void	SetWidgetProperty( struct form_item * iptr, int event )
{
	switch ( event ) {
		case	_WIDGET_TYPE :
			iptr->Contents.style= Context.style;
			break;
		case	_WIDGET_FONT :
			iptr->Contents.font = Context.Item.font;
			break;
		case	_WIDGET_LOCK :
			iptr->Contents.events.control |= _IS_XO_LOCK;
			break;
		case	_WIDGET_UNLOCK :
			iptr->Contents.events.control &= ~_IS_XO_LOCK;
			break;
		case	_WIDGET_BOLD :
			if (!( Context.alignment & _A_BOLD ))
				iptr->Contents.align |= _A_BOLD;
			else	iptr->Contents.align &= ~_A_BOLD;
			break;
		case	_WIDGET_SHADOW :
			if (!( Context.alignment & _A_SHADOW ))
				iptr->Contents.align |= _A_SHADOW;
			else	iptr->Contents.align &= ~_A_SHADOW;
			break;
		case	_WIDGET_ULINE:
			if (!( Context.alignment & _A_LINE ))
				iptr->Contents.align |= _A_LINE;
			else	iptr->Contents.align &= ~_A_LINE;
			break;
		case	_WIDGET_ALIG :
			iptr->Contents.align &= 0xFF00;
			iptr->Contents.align |= (Context.alignment & 0x00FF);
			break;
		case	_WIDGET_AUTO :
			iptr->Contents.events.xo_show &= ~ _EVENT_IS_COND;
			break;
		case	_WIDGET_COND :
			iptr->Contents.events.xo_show |= _EVENT_IS_COND;
			break;
		case	_WIDGET_FORE :
			iptr->Contents.colour = (Context.foreground | (iptr->Contents.colour & 0xFF00));
			break;
		case	_WIDGET_BACK :
			iptr->Contents.colour = ((Context.background << 8) | (iptr->Contents.colour & 0x00FF));
			break;
	
		}
	return;
}

public	void	set_widget_property( struct form_control * fptr, int event )
{
	struct	form_item * iptr=(struct form_item *) 0;
	struct	form_item * mptr=(struct form_item *) 0;

	if (!( fptr  )) 
		return;

	else if (!( iptr = fptr->current ))
		return;

	else if (( iptr->Contents.style & _FRAME_TYPE ) != _CUT_FRAME) {
		if ( event == _WIDGET_DELETE ) {
			delete_widget(fptr);
			form_is_outofdate(fptr);
			}
		else	{
			show_item_info(iptr);
			SetWidgetProperty( iptr, event );
			}
		}
	else if ( event != _WIDGET_DELETE ) {

		/* Adjust all others by same amount */
		/* -------------------------------- */
		for (	mptr=fptr->first;
			mptr != (struct form_item *) 0;
			mptr = mptr->next ) {

			if (!( is_widget_member( iptr, mptr ) ))
				continue;
			else	{
				show_item_info(mptr);
				SetWidgetProperty( mptr, event );
				}
			}
		}

	else	{
		mptr=fptr->first;
		while (mptr != (struct form_item *) 0) {
			if (!( is_widget_member( iptr, mptr ) ))
				mptr = mptr->next;
			else	{
				fptr->current = mptr;
				mptr = mptr->next;
				delete_widget(fptr);
				form_is_outofdate(fptr);
				}
			}
		}
	return;


}

private	void	choose_national_payload( struct	form_item * iptr )
{
	int	i;
	for ( i=0; i < MAXNATLANG; i++ ) {
		if (!(iptr->Contents.messages[i]))
			continue;
		else	{
			get_national_payload( iptr, i );
			break;
			}
		}
	return;
}


public	void	form_clipboard(struct form_control * fptr, int  event )
{
	int	i=0;
	char *	message=(char *) 0;
	struct	form_item * wptr=(struct form_item *) 0;
	struct	form_item * iptr=(struct form_item *) 0;
	struct	form_item * xptr=(struct form_item *) 0;
	struct	form_item * clipfoot=(struct form_item *) 0;

	switch ( event ) {

		case	_FORM_UNDO	:
			if (!( iptr = Context.UndoList ))
				break;
			if ((Context.UndoList = iptr->next) != (struct form_item *) 0) 
				Context.UndoList->previous = (struct form_item*) 0;

			add_Widget( fptr, iptr, 0 );
			break;

		case	_WIDGET_COPY	:

			drop_form_clipboard();

			if (!( wptr = fptr->current ))
				break;
			if ((wptr->Contents.style & _FRAME_TYPE) != _CUT_FRAME) {
				set_national_payload(wptr, fptr->natlang);
				Context.Widgets = copy_widget( wptr );
				get_national_payload(wptr, fptr->natlang);
				i=1;
				}
			else	{
				for (	iptr = fptr->first;
					iptr != (struct form_item*) 0;
					iptr = iptr->next ) {
					if (!( is_widget_member( wptr, iptr ) ))
						continue;
					set_national_payload(iptr, fptr->natlang);
					xptr = copy_widget( iptr );
					get_national_payload(iptr, fptr->natlang);
					if (!( xptr ))
						continue;
					else if (!( Context.Widgets )) {
						clipfoot = Context.Widgets = xptr;
						}
					else	{
						i++;
						clipfoot->next = xptr;
						xptr->previous = clipfoot;
						clipfoot = xptr;
						}
					}
				}
			message = "copied";
			break;


		case	_WIDGET_PASTE	:
			for (	i=0,iptr = Context.Widgets;
				iptr != (struct form_item*) 0;
				iptr = iptr->next ) {
				if (!( xptr = copy_widget( iptr )))
					continue;
				else	{
					add_Widget( fptr, xptr, 0 );
					xptr->parent = fptr;
					if ( fptr->natlang & _INTERNATIONAL )
						get_national_payload(xptr,fptr->natlang);
					else	choose_national_payload( xptr );
					i++;
					}
				}
			message = "pasted";
			break;

		}
	if (!( message ))
		return;
	else if (!( i ))
		sprintf(namebuffer,"ZERO widgets %s",message);
	else if (i > 1 )
		sprintf(namebuffer,"%u widgets %s",i,message);
	else	sprintf(namebuffer,"widget %s",message);
	status_message(namebuffer,3);
	return;

}

private	void	seek_form_page(struct form_control * fptr)
{
	struct	form_item * iptr=(struct form_item *) 0;
	for (	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((( iptr->Contents.style & _FRAME_TYPE ) == _TAB_FRAME )
		&&   ( iptr->Contents.page == fptr->page_number )) {
			fptr->top = fptr->current = iptr;
			break;
			}
		}
	return;
}

public	void	store_payloads(struct form_control * fptr )
{
	struct	form_item * iptr=(struct form_item *) 0;
	if (!( fptr->formflags & _INTERNATIONAL ))
		return;
	for (	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
		set_national_payload(iptr,fptr->natlang);
	return;
}

public	void	reload_payloads(struct form_control * fptr )
{
	struct	form_item * iptr=(struct form_item *) 0;
	if (!( fptr->formflags & _INTERNATIONAL ))
		return;
	for (	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
		get_national_payload(iptr,fptr->natlang);
	return;
}
 
public	void	change_national_language(struct form_control * fptr, int newlang )
{
	struct	form_item * iptr=(struct form_item *) 0;
	for (	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		set_national_payload(iptr,fptr->natlang);
		get_national_payload(iptr,newlang);
		check_Widget(iptr);
		}
	fptr->natlang=newlang;
	return;
}

public	void	check_forms_methods(struct form_control * fptr )
{
	struct forms_method *	mptr;
	if (!( fptr ))
		return;
	fptr->StandardError = 
	fptr->StandardInput  = (struct forms_method *)0;
	for (	mptr  = fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next) {
		if (!( mptr->name ))
			continue;
		else if ( string_compare( "stdinput", mptr->name ) ) {
			fptr->StandardInput = mptr;
			break;
			}
		else if ( string_compare( "stderror", mptr->name ) ) {
			fptr->StandardError = mptr;
			break;
			}
		}
	return;
}

public	int	form_parameters(struct form_control * fptr )
{
	int	status;
	int	ft;
	int	kesc,krc,kpu,kpd;
	int	ktab,klu,kld;
	int	kdef;
	int	kmec,kwt;
	int	mslb,msmb,msrb;
	int	msd,msu,mswd,msid,msm;
	int	prodlang;
	int	userstate=SingConf->expert_user;
	int	international=0;
	int	multilingual=0;
	int	national=0;
	int	commandline=0;
	int	generateconstants=0;

	if (!( fptr ))	return(27);
		
	if ( fptr->formflags & _FORM_INTERNATIONAL )
		international = 1;
	else	international = 0;

	if ( fptr->formflags & _FORM_COMMANDLINE )
		commandline = 1;
	else	commandline = 0;

	if ( fptr->formflags & _FORM_CONSTANTS )
		generateconstants=1;
	else	generateconstants=0;

	if ( fptr->formflags & _FORM_MULTILINGUAL )
		multilingual = 1;
	else	multilingual = 0;

	ft = (fptr->formflags & _FORM_TYPE_FLAGS);

	if ( fptr->formflags & _FORM_ESC )
		kesc = 1;
	else	kesc = 0;
	if ( fptr->formflags & _FORM_PAGE_UP )
		kpu = 1;
	else	kpu = 0;
	if ( fptr->formflags & _FORM_PAGE_DOWN)
		kpd = 1;
	else	kpd = 0;
	if ( fptr->formflags & _FORM_TAB )
		ktab = 1;
	else	ktab = 0;
	if ( fptr->formflags & _FORM_RC )
		krc = 1;
	else	krc = 0;
	if ( fptr->formflags & _FORM_UP )
		klu = 1;
	else	klu = 0;
	if ( fptr->formflags & _FORM_DOWN )
		kld = 1;
	else	kld = 0;
	if ( fptr->formflags & _FORM_DEFAULT )
		kdef = 1;
	else	kdef = 0;

	if ( fptr->mimoflags & _MIMO_INTERRUPT )
		kwt = 1;
	else	kwt = 0;

	if ( fptr->mimoflags & 2 )
		kmec = 1;
	else	kmec = 0;

	if ( fptr->mimoflags & _MIMO_SEND_LEFT )
		mslb = 1;
	else	mslb = 0;

	if ( fptr->mimoflags & _MIMO_SEND_MIDDLE)
		msmb = 1;
	else	msmb = 0;
	if ( fptr->mimoflags & _MIMO_SEND_RIGHT)
		msrb = 1;
	else	msrb = 0;
	if ( fptr->mimoflags & _MIMO_DOWN )
		msd = 1;
	else	msd = 0;
	if ( fptr->mimoflags & _MIMO_UP )
		msu = 1;
	else	msu = 0;
	if ( fptr->mimoflags & _MIMO_WHILE_DOWN)
		mswd = 1;
	else	mswd = 0;

	if ( fptr->mimoflags & _MIMO_IS_DOWN )
		msid = 1;
	else	msid = 0;

	if ( fptr->mimoflags & _MIMO_MOVE )
		msm = 1;
	else	msm = 0;

	if ( SingConf->expert_user )
		prodlang = fptr->language;
	else if ((prodlang = (fptr->language-_GENERATE_BAL)) < 0 ) {
		SingConf->expert_user++;
		prodlang = fptr->language;
		}		
	national = fptr->natlang;

	if ((status = accept_form_control(
		&ft, &prodlang, &national, 
		&international, &generateconstants, &multilingual,
		&fptr->isprogram, &fptr->isoverlay, &fptr->ispopup, &fptr->isdynamic,
		&commandline,&fptr->argvlen,&fptr->argvcount,
		&mslb,&msmb,&msrb,
		&msd,&msu,&mswd,&msm,&kmec,&kwt,
		&kesc,&krc,&kpu,&kpd,&klu,&kld,&ktab,&kdef,
		&fptr->prodname, 	&fptr->identifier,
		&fptr->stylesheet, &fptr->clearscreen
		)) != 27 ) {
		if ( SingConf->expert_user )
			fptr->language = prodlang;
		else	fptr->language = (prodlang+_GENERATE_BAL);
		fptr->formflags = (ft & _FORM_TYPE_FLAGS);
		if ( kesc ) fptr->formflags |= _FORM_ESC;
		if ( kpu  ) fptr->formflags |= _FORM_PAGE_UP;
		if ( kpd  ) fptr->formflags |= _FORM_PAGE_DOWN;
		if ( ktab ) fptr->formflags |= _FORM_TAB;
		if ( krc  ) fptr->formflags |= _FORM_RC;
		if ( klu  ) fptr->formflags |= _FORM_UP;
		if ( kld  ) fptr->formflags |= _FORM_DOWN;
		if ( kdef ) fptr->formflags |= _FORM_DEFAULT;
		if ( commandline )
			fptr->formflags |= _FORM_COMMANDLINE;
		if ( international )
			fptr->formflags |= _FORM_INTERNATIONAL;
		if ( generateconstants )
			fptr->formflags |= _FORM_CONSTANTS;
		if ( multilingual )
			fptr->formflags |= _FORM_MULTILINGUAL;
		if ( national != fptr->natlang ) {
			if ( fptr->formflags & _FORM_INTERNATIONAL )
				change_national_language( fptr, national );
			else	fptr->natlang = national;
			}
		fptr->mimoflags = 0;
		if ( kwt  ) fptr->mimoflags |= _MIMO_INTERRUPT;
		if ( kmec ) fptr->mimoflags |= _MIMO_KEYBOARD;
		if ( mslb ) fptr->mimoflags |= _MIMO_SEND_LEFT;
		if ( msmb ) fptr->mimoflags |= _MIMO_SEND_MIDDLE;
		if ( msrb ) fptr->mimoflags |= _MIMO_SEND_RIGHT;
		if ( msd  ) fptr->mimoflags |= _MIMO_DOWN;
		if ( msu  ) fptr->mimoflags |= _MIMO_UP;
		if ( mswd ) fptr->mimoflags |= _MIMO_WHILE_DOWN;
		if ( msid ) fptr->mimoflags |= _MIMO_IS_DOWN;
		if ( msm  ) fptr->mimoflags |= _MIMO_MOVE;
		switch ( fptr->formflags & _FORM_TYPE_FLAGS ) {
			case	_FORM_TYPE_DIALOG	:
			case	_FORM_TYPE_EVENT 	:
				break;
			case	_FORM_TYPE_SCROLL	:
			case	_FORM_TYPE_PAGE  	:
				/* required for multiple page printing */
				fptr->formflags |= _FORM_RC;

			}		
		check_forms_methods(fptr);
		}
	SingConf->expert_user = userstate;
	return(status);
}

public	int	form_widget_insert( struct form_control * fptr )
{
	int			item=0;
	struct form_item * 	iptr;
	struct form_item * 	xptr;

	xptr = iptr = fptr->current;

	if ((Context.Item.style = Context.style) == _MOVE_FRAME) {
		if (!( iptr ))	
			return(0);
		else	{
			Context.Item.style = iptr->Contents.style;
			Context.Item.colour= iptr->Contents.colour;
			Context.Item.font  = iptr->Contents.font;
			Context.Item.align = iptr->Contents.align;
			}
		}
	else if (!( iptr )) {
		Context.Item.x = Context.Item.y = 0;
		Context.Item.w = 100;
		Context.Item.h = 20;
		}
	else	{
		Context.Item.x = iptr->Contents.x;
		switch (( Context.Item.style & _FRAME_TYPE )) {
			case	_WINDOW_FRAME	:
			case	_TAB_FRAME	:
				Context.Item.y = iptr->Contents.y;
				break;
			default			:
				Context.Item.y = iptr->Contents.y+iptr->Contents.h+Context.fontheight;
				break;
			}
		Context.Item.w = iptr->Contents.w;
		Context.Item.h = iptr->Contents.h;
		}
	if ( Context.lockon  )
		apply_gridlock( &Context.Item,7);
	if (( iptr = allocate_Widget(fptr)) != (struct form_item *) 0) {
		form_data_type( iptr );
		if (!( iptr->Contents.name ))
			iptr->Contents.name = automatic_name(iptr->number);
		if ( xptr ) {
			iptr->Contents.colour = xptr->Contents.colour;
			iptr->Contents.align  = xptr->Contents.align ;
			iptr->Contents.style  = xptr->Contents.style ;
			iptr->Contents.font   = xptr->Contents.font  ;
			}
		show_item_info(fptr->current);
		check_Widget( iptr );
		}
	return(0);
}

public	int	await_form_event( struct form_control * fptr )
{
	int	event;
	show_form_selection(fptr,_TREE_FOCUS );
	do	{
		event = visual_getch();
		}
	while ((event == 256)
	&&     ((event = handle_event()) == 256));
	hide_form_selection(fptr,0 );
	return( event );
}

/*	--------------------------------------------------	*/
/*	F O R M _ E D I T O R  ::  O N _ G E T _ F O C U S	*/
/*	--------------------------------------------------	*/

public	int	FormEditorOnGetFocus( struct form_control ** ffptr )
{
	struct	form_control * fptr;

	if ((!( fptr = *ffptr ))
	&&  (!( fptr = allocate_Form((char *) 0) )))
		return( 0 );

	else	{
		Context.Form = fptr;	
		fptr->display = _EDIT_FORM;
		use_form_tools();
		add_form_editor_menu();
		if ( fptr->display == _EDIT_CLASS ) {
			if ( Context.DeskTop.style != _SCROLL_FRAME ) 
				activate_DeskTop( _SCROLL_FRAME );
			}
		else if ( Context.DeskTop.style == _SCROLL_FRAME ) 
			activate_DeskTop( _OUTSET_FRAME );
		set_context_defaults(fptr);
		desktop_Hscroll(0,0);
		desktop_Vscroll(0,0);
		draw_console();
		return(1);
		}
}


public	int	preserve_Form(struct form_control * fptr)
{
	if (!( fptr ))
		return(1);
	if (!( fptr->outofdate ))
		return(1);
	else	{
		while (1) {
			switch ( accept_exit(fptr->loadname) ) {
				case	_FILE_SAVE :
					save_Form(fptr,QUICK);
				case	13 :
					return(1);
				case	27 :
					draw_console();
					return(0);
				}
			}
		}
}


private	void	edit_widget_messages(struct form_item * iptr, struct form_control * fptr )
{
	set_national_payload(iptr,fptr->natlang);

	accept_widget_messages(
		&iptr->Contents.messages[0],	/* english */
		&iptr->Contents.messages[1],	/* french  */
		&iptr->Contents.messages[2],	/* italien */
		&iptr->Contents.messages[3],	/* spanish */
		&iptr->Contents.messages[4],	/* german  */
		&iptr->Contents.messages[5],	/* dutch   */
		&iptr->Contents.messages[6],	/* portugese */
		&iptr->Contents.messages[7]	/* other	*/
		);	/* portugese*/

	get_national_payload(iptr,fptr->natlang);
	return;
}

private	void	edit_widget_helptexts(struct form_item * iptr, struct form_control * fptr )
{
	accept_help_messages(
		&iptr->document[0],	/* english 	*/
		&iptr->document[1],	/* french  	*/
		&iptr->document[2],	/* italien 	*/
		&iptr->document[3],	/* spanish 	*/
		&iptr->document[4],	/* german  	*/
		&iptr->document[5],	/* dutch   	*/
		&iptr->document[6],	/* portugese 	*/
		&iptr->document[7]	/* other	*/
		);
	return;
}

public 	void	edit_form_helptexts(struct form_control * fptr )
{
	accept_help_messages(
		&fptr->document[0],	/* english 	*/
		&fptr->document[1],	/* french  	*/
		&fptr->document[2],	/* italien 	*/
		&fptr->document[3],	/* spanish 	*/
		&fptr->document[4],	/* german  	*/
		&fptr->document[5],	/* dutch   	*/
		&fptr->document[6],	/* portugese 	*/
		&fptr->document[7]	/* other	*/
		);
	return;
}

public	void	check_Form( struct form_control * fptr )
{
	struct	form_item * iptr;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
		iptr->parent = fptr;
	return;
}


/*		-----------------------------------		*/
/*		W i d g e t	R e f e r e n c e s		*/
/*		-----------------------------------		*/

struct	reference_item	{
	struct	reference_item *previous;
	struct	reference_item *next;
	struct	form_item *	widget;
	struct	forms_method *	function;
	int			line;
	int			method;
	};

static	struct	reference_item	*	ReferenceRoot=(struct reference_item*) 0;
static	int				ReferenceCount=0;
static	char				ReferenceSearch[80];

private	void	add_widget_reference( 
	struct	reference_item 	**	rptr,
	struct	reference_item 	**	lptr,
	struct	form_item	*	iptr,
	struct	forms_method	*	mptr,
	int				nbl,
	int				nbm )
{
	struct	reference_item 	*	nptr=(struct reference_item *) 0;

	if (!( nptr = allocate( sizeof( struct reference_item ) ) ))
		return;
	else	{
		nptr->line   	= nbl;
		if (!( nptr->method 	= nbm )) {
			nptr->function 	= mptr;
			nptr->widget 	= (struct form_item *) 0;
			}
		else	{
			nptr->function 	= (struct forms_method *) 0;
			nptr->widget 	= iptr;
			}
		nptr->previous	= (struct reference_item *) 0;
		nptr->next 	= (struct reference_item *) 0;
		if (!( nptr->previous	= *lptr ))
			*rptr = nptr;
		else	nptr->previous->next = nptr;
		*lptr = nptr;
		ReferenceCount++;
		return;
		}
}

public	int	widget_reference_count()
{
	return( ReferenceCount );
}

public	void	get_widget_reference(int item, char * bptr, int blen )
{
	int	i=0;
	int	x=0;
	char *	mptr;
	char	buffer[256];
	struct	reference_item 	*	rptr=(struct reference_item *) 0;
	struct	form_control    *	fptr;
	for ( x=1, rptr = ReferenceRoot; rptr != (struct reference_item *) 0; rptr = rptr->next ) {
		if ( x == item )
			break;
		else	x++;
		}

	if ( rptr ) {
		switch ( rptr->method ) {
			case	1 :	mptr = "Create"; break;
			case	2 :	mptr = "Show"; break;
			case	3 :	mptr = "GetFocus"; break;
			case	4 :	mptr = "LoseFocus"; break;
			case	5 :	mptr = "Event"; break;
			case	6 :	mptr = "Hide"; break;
			case	7 :	mptr = "Remove"; break;
			default	  :	mptr = "What"; break;
			}
		if (!( rptr->method ))
			sprintf(buffer,"%s.%s(%u)",rptr->function->parent->identifier,rptr->function->name,rptr->line);
		else if ((fptr = rptr->widget->parent) != (struct form_control *) 0)
			sprintf(buffer,"%s.%s.%s(%u)",fptr->identifier,rptr->widget->Contents.name,mptr,rptr->line);
		else	sprintf(buffer,"%s.%s(%u)",rptr->widget->Contents.name,mptr,rptr->line);
		for ( i=0; i < blen; i++ )
			if (!( *(bptr+i) = buffer[i] ))
				break;
		}

	for (; i < blen; i++ )
		*(bptr+i) = ' ';
	return;
}	

public	void	inspect_widget_reference(int item)
{
	int	x=0;
	struct	reference_item 	*	rptr=(struct reference_item *) 0;
	for ( x=1, rptr = ReferenceRoot; rptr != (struct reference_item *) 0; rptr = rptr->next ) {
		if ( x == item )
			break;
		else	x++;
		}
	if (!( rptr ))
		return;
	else if (!( rptr->widget )) {
		if ( rptr->function )
			inspect_forms_method( rptr->function, 0);
		return;
		}
	else	{
		edit_Widget( rptr->widget, rptr->widget->parent );
		return;
		}
}

private	int	detect_reference(char * mptr, char * nptr )
{
	int	nbl=0;
	int	i=0;
	while ( *mptr != 0 ) {
		if (!(*(nptr+i))) {
			return(( nbl+1 ));
			}
		else if ( *(nptr+i) != *(mptr+i) ) {
			i=0;
			mptr++;
			if ( *mptr == '\r' )	
				mptr++;
			else if ( *mptr == '\n' ) {
				nbl++;
				mptr++;
				}
			}
		else	i++;
		}
	return( 0 );
}


private	struct widget_references * build_widget_references( struct form_control * fptr, char * nptr )
{
	struct	reference_item 	*	rptr=(struct reference_item *) 0;
	struct	reference_item 	*	lptr=(struct reference_item *) 0;
	struct	forms_method	*	mptr=(struct forms_method*) 0;
	char 		  	* 	sptr;
	struct	form_item 	* 	iptr;
	int				l;
	/* Build List of Widget References */
	/* ------------------------------- */
	strcpy(ReferenceSearch,nptr);
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ( method_is_valid(iptr->Contents.events.on_create) )
			if ((l = detect_reference(iptr->Contents.events.on_create,nptr)) != 0)
				add_widget_reference(&rptr, &lptr, iptr, (struct forms_method *) 0, l, 1 );
		if ( method_is_valid(iptr->Contents.events.on_show) )
			if ((l = detect_reference(iptr->Contents.events.on_show  ,nptr)) != 0)
				add_widget_reference(&rptr, &lptr, iptr, (struct forms_method *) 0, l, 2 );
		if ( method_is_valid(iptr->Contents.events.on_get_focus) )
			if ((l = detect_reference(iptr->Contents.events.on_get_focus,nptr)) != 0)
				add_widget_reference(&rptr, &lptr, iptr, (struct forms_method *) 0, l, 3 );
		if ( method_is_valid(iptr->Contents.events.on_lose_focus) )
			if ((l = detect_reference(iptr->Contents.events.on_lose_focus,nptr)) != 0)
				add_widget_reference(&rptr, &lptr, iptr, (struct forms_method *) 0, l, 4 );
		if ( method_is_valid(iptr->Contents.events.on_event) )
			if ((l = detect_reference(iptr->Contents.events.on_event,nptr)) != 0)
				add_widget_reference(&rptr, &lptr, iptr, (struct forms_method *) 0, l, 5 );
		if ( method_is_valid(iptr->Contents.events.on_hide) )
			if ((l = detect_reference(iptr->Contents.events.on_hide,nptr)) != 0)
				add_widget_reference(&rptr, &lptr, iptr, (struct forms_method *) 0, l, 6 );
		if ( method_is_valid(iptr->Contents.events.on_remove) )
			if ((l = detect_reference(iptr->Contents.events.on_remove,nptr)) != 0)
				add_widget_reference(&rptr, &lptr, iptr, (struct forms_method *) 0, l, 7 );
		}
	/* Detect references from Forms Methods */
	/* ------------------------------------ */
	for (	mptr  = fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr =  mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if (!( method_is_valid( mptr->text ) ))
			continue;
		else if ((l = detect_reference(mptr->text,nptr)) != 0)
			add_widget_reference(&rptr, &lptr,(struct form_item *) 0, mptr, l, 0 );

		}
	return( rptr );
}


private	void	drop_widget_references( struct reference_item * rptr )
{
	struct	reference_item * lptr;

	/* Drop List of Reference items */
	/* ---------------------------- */
	while((lptr = rptr) != (struct reference_item *) 0) {
		rptr = lptr->next;
		liberate( lptr );
		}

	return;
}

public	void	search_widget_reference(int item,char * bptr, int blen)
{
	int	i=0;
	int	x=0;
	char *	mptr;
	char	buffer[256];
	struct	reference_item 	*	rptr=(struct reference_item *) 0;
	struct	form_control    *	fptr;
	for ( x=1, rptr = ReferenceRoot; rptr != (struct reference_item *) 0; rptr = rptr->next ) {
		if ( x == item )
			break;
		else	x++;
		}

	if (!( rptr ))
		return;
	else if (!( rptr->widget ))
		return;
	else	{
		strcpy(buffer,rptr->widget->Contents.name);
		fptr = rptr->widget->parent;
		drop_widget_references(ReferenceRoot);
		ReferenceCount=0;
		ReferenceRoot = build_widget_references(fptr,buffer);
		for ( i=0; i < blen; i++ )
			if (!( *(bptr+i) = ReferenceSearch[i] ))
				break;
		for ( ; i < blen; i++ )
			*(bptr+i) = ' ';

		return;
		}
	return;
}	


public 	void	locate_widget_references(struct form_control * fptr )
{

	char			*	nptr;
	struct	form_item 	* 	wptr;

	ReferenceRoot=(struct reference_item*) 0;
	if (!( wptr = fptr->current ))
		return;
	else if (!(nptr = wptr->Contents.name ))
		return;
	else	{
		ReferenceCount=0;
		ReferenceRoot = build_widget_references(fptr,nptr);
		if (!( nptr = allocate_string(ReferenceSearch)))
			return;
		else	{
			widget_reference_locator(&nptr);
			drop_widget_references(ReferenceRoot);
			ReferenceRoot=(struct reference_item*) 0;
			if ( nptr )
				liberate( nptr );
			return;
			}
		}
}


/*	--------------------------------------------------	*/
/*	F O R M _ E D I T O R  ::  O N _ U S E _ E V E N T	*/
/*	--------------------------------------------------	*/

void	calculate_form_triggers( struct form_control * fptr )
{
	struct	form_item *	iptr;
	int			language;

	/* Detect simple case of only one language */
	/* --------------------------------------- */
	if (!( fptr->formflags & _INTERNATIONAL))
		calculate_payload_triggers( fptr );

	else	{

		/* Save all payload messages to their national language slot */
		/* --------------------------------------------------------- */
		for (	iptr=fptr->first;
			iptr != (struct form_item*) 0;
			iptr = iptr->next )	
			set_national_payload(iptr,fptr->natlang);


		/* For all national languages : collect payloads, calculate triggers, store payloads */
		/* --------------------------------------------------------------------------------- */
		for ( language=0; language < MAXNATLANG; language++ ) {

			for (	iptr=fptr->first;
				iptr != (struct form_item*) 0;
				iptr = iptr->next )
				get_national_payload(iptr,language);

			calculate_payload_triggers( fptr );

			for (	iptr=fptr->first;
				iptr != (struct form_item*) 0;
				iptr = iptr->next )
				set_national_payload(iptr,language);
			}


		/* Restore all payload messages from their national language slot */
		/* -------------------------------------------------------------- */
		for (	iptr=fptr->first;
			iptr != (struct form_item*) 0;
			iptr = iptr->next )
			get_national_payload(iptr,fptr->natlang);

		}

	return;
}


int	FormEditorOnUseEvent( struct form_control ** ffptr, int event )
{
	struct form_control * fptr;
	struct form_control * xptr;

	if (!( fptr = *ffptr ))
		return( event );

	switch ( event ) {

		case	  3		:
			if (!( fptr->pages )) {
				event=0; break;
				}
			else	{
				if ( fptr->page_number < fptr->pages)
					fptr->page_number++;
				else	fptr->page_number=1;
				seek_form_page( fptr );
				draw_console();
				event=0; break;
				}

		case	  0x0012	:
			if (!( fptr->pages )) {
				event=0; break;
				}
			else	{
				if ( fptr->page_number > 1 )
					fptr->page_number--;
				else	fptr->page_number=fptr->pages;
				seek_form_page( fptr );
				draw_console();
				event=0; break;
				}
			case	257		:
			draw_console();
			event=0; break;

		case	CTRL_I			:
		case	_EDIT_PROPERTIES	:
			if ( fptr->current )
				(void) edit_Widget( fptr->current, fptr );
			event=0; break;

		case	_EDIT_TREEVIEW  :
			swap_TreeView();
			event=0; 
			break;

		case	_WIDGET_MSG	:
			if ( fptr->formflags & _INTERNATIONAL ) {
				edit_widget_messages(fptr->current,fptr);
				draw_console();
				}
			event=0;
			break;
		case	_WIDGET_HELP	:
			if ( fptr->formflags & _INTERNATIONAL ) {
				edit_widget_helptexts(fptr->current,fptr);
				draw_console();
				}
			event=0;
			break;
		case	_WIDGET_FORM	:
			if ( fptr->formflags & _INTERNATIONAL ) {
				edit_form_helptexts(fptr);
				draw_console();
				}
			event=0;
			break;

		case	_EDIT_DATABASE	:
			database_editor();
			event=0;
			break;

		case	_VIEW_TEXT	:
		case	_VIEW_IMAGE	:
		case	_EDIT_GRAPH	:
			break;

		case	_FORM_PARA	:
			(void) form_parameters(fptr);
			draw_console();
			event=0; break;

		case	_FORM_NUMBER	:
			renumerate_form(fptr);
			draw_console();
			event=0; break;

		case	_FORM_UNDO	:
			form_clipboard(fptr,event);
			draw_console();
			event=0; break;


		case	_FORM_FACE	:
			interface_form(fptr);
			draw_console();
			event=0; break;

		case	_FORM_TRIGGER	:
			calculate_form_triggers(fptr);
			draw_console();
			event = 0; break;

		case	_FORM_ORDER	:
			reorder_form(fptr);
			draw_console();
			event=0; break;

		case	_WIDGET_COPY	:
		case	_WIDGET_PASTE	:
			form_clipboard(fptr, event );
			draw_console();
			event=0; break;

		case	_WIDGET_FIND	:
			locate_widget_references(fptr);
			draw_console();
			event=0; break;

		case	_WIDGET_TYPE	:
		case	_WIDGET_FONT	:
		case	_WIDGET_ALIG	:
		case	_WIDGET_LOCK	:
		case	_WIDGET_UNLOCK	:
		case	_WIDGET_BOLD	:
		case	_WIDGET_SHADOW	:
		case	_WIDGET_ULINE	:
		case	_WIDGET_BACK	:
		case	_WIDGET_FORE	:
		case	_WIDGET_COND	:
		case	_WIDGET_AUTO	:
		case	_WIDGET_DELETE	:
			set_widget_property( fptr, event );
			draw_console();
			event=0; break;

		case	_EDIT_FORM	:

			if ( treeview_is_active() )
				break;

			if ( Context.DeskTop.style == _SCROLL_FRAME ) 
				activate_DeskTop( _OUTSET_FRAME );
			fptr->display = event;
			event = _EDIT_FORM;

			if ((event = form_editor_event(fptr,event)) == _EDIT_GRAPH) {
				form_Image(fptr);
				break;
				}
			else if (( event == _EDIT_FORM ) 
			     &&  ( treeview_is_active())) {
				form_Image(fptr);
				break;
				}
			else if (( event == _VIEW_TEXT )
			     ||  ( event == _VIEW_IMAGE )) {
				form_Image(fptr);
				break;
				}
			else if ( event != _LEAVE_SING ) {
				draw_Form(fptr,1);
				event=0; break;
				}
			else	break;

		case	0x000F		:
			form_widget_insert(fptr);
			draw_Form(fptr,1);
			event = 0; break;			

		case	_EXEC_PROG	:
			if ( fptr->prodname )
				abal_runtime( fptr->prodname, 0 );
			event=0; break;

		case	_EDIT_TEXT	:
			if ( fptr->prodname  )
				event = use_editor( fptr->prodname, fptr->language );
			else	event=0; 
			break;

		case	_EDIT_IMAGE	:
		case	_EDIT_FONT	:
			if ((event = form_editor_event(fptr,event)) == _EDIT_GRAPH ) {
				form_Image(fptr);
				break;
				}
			else if ( event == _VIEW_IMAGE ) {
				form_Image(fptr);
				break;
				}
			else if ( event == _EDIT_DATABASE ) {
				database_editor();
				event=0;
				break;
				}
			else if ( event == _EDIT_TEXT ) {				
				if ( fptr->prodname  )
					event = use_editor( fptr->prodname, fptr->language );
				else	event=0; 
				break;
				}
			else if (( event == _EDIT_FORM ) 
			     &&  ( treeview_is_active())) {
				form_Image(fptr);
				break;
				}
			else if ( event != _LEAVE_SING ) {
				draw_Form(fptr,1);
				event=0; 
				}

		case	_LEAVE_SING	:
			break;

		case	_FILE_NEW	:
			if (!( preserve_Form( fptr ) )) {
				draw_console();
				event=0; break;
				}
			new_Form(fptr,"new");
			set_context_defaults(fptr);

		case	_DISPLAY_REFRESH:
			draw_console();
			event=0; break;

		case	_FILE_SAVE	:
			get_context_defaults(fptr);
			save_Form(fptr,0);
			draw_console();
			event=0; break;

		case	_FILE_QSAVE	:
			get_context_defaults(fptr);
			save_Form(fptr,QUICK);
			draw_console();
			event=0; break;

		case	_FILE_IMPORT	:
		case	_FILE_LOAD	:
			if (!( preserve_Form( fptr ) )) {
				draw_console();
				event=0; break;
				}
			if (!(xptr = load_Form(fptr,fptr->loadname,1,4))) {
				draw_console();
				event=0; break;
				}
			else	{
				set_context_defaults(fptr);
				Context.Form = fptr = xptr;
				draw_console();
				}
			event=0; break;

		case	_FILE_MERGE	:
			(void) load_Form(fptr,fptr->loadname,0,4);
			draw_console();
			event=0; break;

		case	_FILE_PRODUCE	:
			get_context_defaults(fptr);
			check_Form(fptr);
			if ( export_Form(fptr,0) != 0 ) 
				if ( Context.AutoSave )
					save_Form(fptr,QUICK);
			draw_console();
			event=0; break;

		case	_FILE_COMPARE	:
			get_context_defaults(fptr);
			check_Form(fptr);
			compare_Files(fptr->prodname,(char *) 0);
			draw_console();
			event=0; break;

		case	_FILE_IMAGE	:
			image_DeskTop((char *) 0,0);
			draw_console();
			event=0; break;

		case	_SCROLL_V	:
			draw_console();
			event=0; break;

		case	_SCROLL_H	:
			draw_console();
			event=0; break;

		case	256	:
			handle_event();
			event=0; break;

		case	_TOGGLE_PALETTE		:
		case	_TOGGLE_STATUSBAR	:
		case	_TOGGLE_TOOLBAR		:
		case	_TOGGLE_MENUBAR		:
		case	_TOGGLE_TOOL		:
		case	_TOGGLE_IMAGE		:
		case	_TOGGLE_GRID		:
		case	_TOGGLE_LOCK		:
			perform_toggle(event);
			event=0; break;

		case	_DELETE_ITEM		:
			delete_widget(fptr);
			form_is_outofdate(fptr);
			draw_Form(fptr,1);
			event=0; break;

		case	5		:
		case	11		:
		case	_FIRST_ITEM	:
		case	_PREVIOUS_ITEM	:
		case	_NEXT_ITEM	:
		case	_LAST_ITEM	:
			if ( change_FormMember( fptr, event ) )
				draw_console();
			event=0; break;

		case	_EVENT_ITEMDOC		: 
			if (!( fptr->current )) {
				event=0; break;
				}
			else	{
				if ( fptr->formflags & _INTERNATIONAL ) 
					use_visual_text_editor( & fptr->current->document[fptr->natlang], _GENERATE_HTML );
				else 	use_visual_text_editor( & fptr->current->document[0], _GENERATE_HTML );
				event=0; break;
				}

		case	_EVENT_FORMDOC		:
			if ( fptr->formflags & _INTERNATIONAL ) 
				use_visual_text_editor( &fptr->document[fptr->natlang], _GENERATE_HTML );
			else	use_visual_text_editor( &fptr->document[0], _GENERATE_HTML );
			event=0; break;

		case	_EVENT_CREATE		:
		case	_EVENT_REMOVE		:
		case	_EVENT_SHOW  		:
		case	_EVENT_HIDE  		:
		case	_EVENT_FOCUS 		:
		case	_EVENT_LOSE  		:
		case	_EVENT_EVENT 		:
			if ( fptr->current != (struct form_item *) 0) {
				accept_event( event, &fptr->current->Contents.events);
				}
		default				:
			event=0; break;

		}
	*ffptr = fptr;
	return( event );
}

/*	----------------------------------------------------	*/
/*	F O R M _ E D I T O R  ::  O N _ L O S E _ F O C U S	*/
/*	----------------------------------------------------	*/

int	FormEditorOnLoseFocus(struct form_control **ffptr )
{
	struct form_control * fptr;
	if (!( fptr = *ffptr ))
		return(0);
	form_Image(fptr);
	get_context_defaults(fptr);
	drop_Form_buffer( fptr );
	desktop_Hscroll(0,0);
	desktop_Vscroll(0,0);
	Context.Form = (struct form_control *) 0;
	drop_form_editor_menu();
	if ( Context.DeskTop.style == _SCROLL_FRAME ) 
		activate_DeskTop( _OUTSET_FRAME );
	drop_tool_manager();
	return(1);
}


/*		----------------------------------------		*/
/*		F O R M _ E D I T O R  ::  O N _ E X E C 
/*		----------------------------------------		*/

public	int	FormEditorOnExec( struct form_control ** ffptr )
{
	int	event;
	if (!( FormEditorOnGetFocus( ffptr ) ))
		return(0);
	else	{
		while (1) {
			event = await_form_event( *ffptr );
			if (!( event = FormEditorOnUseEvent( ffptr, event )))
				continue;
			else	break;
			}
		FormEditorOnLoseFocus(ffptr);
		}
	return(event);
}

private	void	widget_Report(
		FILE * handle,
		struct form_item * iptr,
		int	options)
{
	char	*	tptr;
	html_tag(handle,"tr");
	html_tag(handle,"td");	html_text(handle,get_widget_class(iptr->Contents.style));
	html_tag(handle,"td");	html_text(handle,iptr->Contents.name);
	html_tag(handle,"td");
		html_integer(handle,iptr->Contents.x);
		html_integer(handle,iptr->Contents.y);
		html_integer(handle,iptr->Contents.w);
		html_integer(handle,iptr->Contents.h);
		html_integer(handle,iptr->Contents.font);
		html_integer(handle,iptr->Contents.align);

	html_tag(handle,"td");	
		html_text(handle,iptr->Contents.payload);
		if ((tptr = get_widget_datatype( iptr->Contents.datatype )) != (char *) 0) 
			html_text(handle,tptr );
	
	html_tag(handle,"td");
		if ( iptr->Contents.events.on_create ) {
			 html_text(handle,"OnCreate");
			}

		if ( iptr->Contents.events.on_show ) {
			 html_text(handle,"OnShow");
			}

		if ( iptr->Contents.events.on_get_focus ) {
			 html_text(handle,"OnFocus");
			}

		if ( iptr->Contents.events.on_lose_focus ) {
			 html_text(handle,"OnLose");
			}

		if ( iptr->Contents.events.on_hide ) {
			 html_text(handle,"OnHide");
			}

		if ( iptr->Contents.events.on_remove ) {
			 html_text(handle,"OnRemove");
			}

		if ( iptr->Contents.events.on_event ) {
			 html_text(handle,"OnEvent");
			}

	html_closure(handle,"tr");
	return;
}



public	int	generate_tabpage_area( FILE * handle,struct form_item * iptr, int tabadjust, struct window_control * wptr )
{
	char	*	lptr;

	switch ( (iptr->Contents.style & _FRAME_TYPE ) ) {
		case	_BUTTON_FRAME	:
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
		case	_TAB_FRAME	:
			lptr = iptr->Contents.payload;
			break;
		default			:
			lptr = iptr->Contents.name;
			break;
		}
	html_area( 
		handle,lptr,
		(iptr->Contents.x+tabadjust)-wptr->x,
		iptr->Contents.y-wptr->y,
		iptr->Contents.xlimit,
		iptr->Contents.ylimit);
	tabadjust+= iptr->Contents.xlimit;
	return( tabadjust );
}

public	int	generate_widget_area( FILE * handle,struct form_item * iptr,  struct window_control * wptr)
{
	char	*	lptr;

	switch ( (iptr->Contents.style & _FRAME_TYPE ) ) {
		case	_BUTTON_FRAME	:
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
		case	_TAB_FRAME	:
			lptr = iptr->Contents.payload;
			break;
		default			:
			lptr = iptr->Contents.name;
			break;
		}
	html_area( 
		handle,lptr,
		iptr->Contents.x-wptr->x,
		iptr->Contents.y-wptr->y,
		iptr->Contents.w,
		iptr->Contents.h );
	return(0);
}

public	int	generate_select_area( FILE * handle,struct form_item * iptr, struct window_control * wptr )
{
	int	fh;
	fh = guifontsize(iptr->Contents.font);
	fh >>= 8;
	fh &= 0x00FF;
	html_area( 
		handle,iptr->Contents.name,
		iptr->Contents.x-wptr->x,
		iptr->Contents.y-wptr->y,
		iptr->Contents.w,
		(fh+3) );
	return(0);
}

public	int	generate_Form_map( FILE * handle,struct form_control * fptr, char * mapname, int pageid )
{
	struct form_item * iptr;
	int	tabadjust=0;
	char 	*	dptr;

	struct window_control  Window;
	form_Dimensions( &Window, fptr );

	html_open_map(	handle, mapname );

	for (	tabadjust=0,iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {

		if ( fptr->formflags & _INTERNATIONAL )
			dptr = iptr->document[fptr->natlang];
		else	dptr = iptr->document[0];

		if (( dptr )
		&&  ( iptr->Contents.name )) {

			if (( iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME ) {
				tabadjust = generate_tabpage_area( handle, iptr, tabadjust, &Window );
				continue;
				}		 
			if (( iptr->Contents.page != 0 )
			&&  ( pageid  != 0 )) {
				if ( iptr->Contents.page != pageid )
					continue;
				}
			if (( iptr->Contents.style & _FRAME_TYPE) == _SELECT_FRAME ) 
				generate_select_area( handle, iptr, &Window );
			else if ((( iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME ) 
			     &&  (( iptr->Contents.align & 7 ) != _VISUAL_FRAME ))
				continue;
			else	generate_widget_area( handle, iptr, &Window );

			}
		}
	html_close_map(	handle );
}

public	int	generate_tabpage_map( FILE * handle,struct form_control * fptr )
{
	struct form_item * iptr;
	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if (( iptr->Contents.style & _FRAME_TYPE) != _TAB_FRAME ) 
			continue;
		else	{
			generate_Form_map( handle, fptr,
				iptr->Contents.name , 
				iptr->Contents.page );
			}
		}
}

public	int	document_Form( 
			FILE * handle,
			struct form_control * fptr,
			int automatic, int report
			)
{
	struct 	form_item * iptr;
	int	tabadjust=0;
	int	paging=0;
	char *	dptr;
	char *	iname=(char *) 0;
	/* generate image area map */
	/* ----------------------- */
	prepare_Form( fptr );

	if ( fptr->pages )
		generate_tabpage_map(handle,fptr);
	else	generate_Form_map( handle, fptr, fptr->identifier, 0 );

	if (!( fptr->formflags & _INTERNATIONAL )) {
		if ( fptr->document[0] )
			html_paragraph( handle, fptr->document[0] );
		}
	else if ( fptr->document[fptr->natlang] )
		html_paragraph( handle, fptr->document[fptr->natlang] );


	if ( report ) {

		html_heading(handle,3,"Components");
		html_tag(handle,"table");
		html_tag(handle,"tr");
		html_tag(handle,"td"); html_text(handle,"Class");
		html_tag(handle,"td"); html_text(handle,"Name");
		html_tag(handle,"td"); html_text(handle,"Dimensions");
		html_tag(handle,"td"); html_text(handle,"Payload");
		html_tag(handle,"td"); html_text(handle,"Events");
		html_closure(handle,"tr");
		for (	iptr=fptr->first; 
			iptr != (struct form_item *) 0; 
			iptr = iptr->next ) 
			widget_Report( handle, iptr, report );
		html_closure(handle,"table");
		html_paragraph( handle, " " );
		}

	if (!( fptr->pages ))
		open_html_definition_list(handle);

	for (	iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		if (( iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME) {
			if (!( paging )) {
				html_tag(handle,"ol");
				paging++;
				}
			else	{
				html_closure(handle,"ul");
				paging--;
				}
			}

		if (!( fptr->formflags & _INTERNATIONAL ))
			dptr = iptr->document[0];
		else	dptr = iptr->document[fptr->natlang];

		if (( dptr )
		&&  ( iptr->Contents.name )) {
			if ( paging ) {
				html_tag(handle,"li");
				open_html_definition_list(handle);
				}

			switch ( (iptr->Contents.style & _FRAME_TYPE ) ) {
				case	_BUTTON_FRAME	:
				case	_CHECK_FRAME	:
				case	_RADIO_FRAME	:
				case	_TAB_FRAME	:
					html_definition(handle,iptr->Contents.payload, dptr );
					break;

				default			:
					html_definition(handle,iptr->Contents.name, dptr );
					break;
				}
			if ( paging )
				close_html_definition_list(handle);
			}
		if (( iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME) {
			if ((iname = html_numbered_image(handle,fptr->prodname,iptr->Contents.page, iptr->Contents.name )) != (char *) 0) {
				fptr->current = iptr;
				fptr->page_number = iptr->Contents.page;
				build_tab_image( fptr, iname );
				liberate( iname );
				}
			html_tag(handle,"ul");
			paging++;
			}
		}
	switch ( paging ) {
		case	2	:
			html_closure(handle,"ul");
		case	1	:
			html_closure(handle,"ol");
			paging=0;
		}
	linefeed(handle);

	if (!( fptr->pages ))
		close_html_definition_list(handle);

	return(1);
}

public	struct form_item * validate_Widget( struct form_control * fptr , char * nptr )
{
	struct form_item * iptr;
	int	x,y,w,h;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if (!( iptr->Contents.name ))
			continue;
		else if ( string_compare( nptr, iptr->Contents.name ) )
			return(iptr);
		}
	w = ((strlen(nptr)+2) * Context.fontwidth);
	h = Context.fontheight; 
	if (!(fptr->current = fptr->last)) {
		x = 10; y=10; 
		}
	else	{
		x = fptr->current->Contents.x;
		y = (fptr->current->Contents.y + (fptr->current->Contents.h+2));
		}
	if (!( iptr = allocate_Widget( fptr ) ))
		return(iptr);
	else	{
		iptr->Contents.name = allocate_string( nptr );
		iptr->Contents.x = x;
		iptr->Contents.y = y;
		iptr->Contents.w = w;
		iptr->Contents.h = h;
		return(iptr);
		}

}

public 	void	respectcase(char * rptr, char * sptr)
{
	int	i;
	if (!( *sptr ))
		return;
	for (i=0; *(sptr+i) != 0; i++ ) {
		if (!( i )) {
			if (( *(sptr+i) >= 'a' ) && ( *(sptr+i) <= 'z'))
				*(rptr+i) = (*(sptr+i) - ('a' - 'A'));
			else 	*(rptr+i) = *(sptr+i);
			}
		else if (( *(sptr+i) >= 'A' ) && ( *(sptr+i) <= 'Z'))
			*(rptr+i) = (*(sptr+i) + ('a' - 'A'));
		else 	*(rptr+i) = *(sptr+i);
		}
	*(rptr+i) = 0;
	return;
}

struct	form_syntax_control	{
	struct form_control * form;
	struct firm_item    * widget;
	char 		    * objects;
	char		    * atributs;
	char		    * result;
	int		      selection;
	int		      current;
	int		      item;
	} FormSyntaxControl = { 
		(struct form_control *) 0,
		(char *) 0,(char *) 0,(char *) 0,
		0,0,0
		};

private	struct form_item * FormCompositionWidget(int c, int w)
{
	int	i;
	struct form_item * iptr;
	for (	i=0,iptr=FormSyntaxControl.form->first;
		iptr != (struct form_item*) 0;
		iptr = iptr->next ) {
		if (!( iptr->Contents.name ))
			continue;
		else if ((iptr->Contents.style & _FRAME_TYPE) != c)
			continue;
		else if (i == w)
			break;
		else	i++;
		}
	return( iptr );
}


public	void	FormWidgetCompose(int c, int w, int m, char * bptr, int blen, int x)
{
	int	rlen;
	char 		  * vptr;
	char		  * rptr;
	struct	form_item * iptr;
	int		    i;
	int			l;
	rptr = bptr; rlen=blen;
	if (!( x )) {
		for (i=0; i < blen; i++ )
			*(bptr+i) = ' ';
		}
	else	{
		for (i=0,l=0; i < blen; i++ ) {
			if (*( bptr+i ) == ' ')
				continue;
			else 	l=(i+1);
			}
		bptr+= l;
		blen -= l;
		}
	if (!( iptr = FormCompositionWidget(c,w) )) {
		if ( strlen("this.") > blen )
			return;
		else	strcpy(bptr,"this.");
		}
	else	{
		if ( strlen(iptr->Contents.name) > blen )
			return;
		else	sprintf(bptr,"%s.",iptr->Contents.name);
		}
	blen -= strlen(bptr);
	bptr += strlen(bptr);
	if ( c != _DATA_FRAME ) {
		if ( strlen( VisualMember[m]) < blen )	{
			if (!( Context.Form->abal.flags & 16 ))
				strcpy(bptr,VisualMember[m]);			
			else	respectcase(bptr,VisualMember[m]);
			}
		if ( is_visual_method(m) )
			strcat(bptr,"()");
		}
	else if (!( FormSyntaxControl.atributs )) {
		if ( strlen( VisualMember[m]) < blen )	 {
			if (!( Context.Form->abal.flags & 16 ))
				strcpy(bptr,DataMember[m]);			
			else	respectcase(bptr,DataMember[m]);
			}
		}
	else if (( vptr = selection_item( m, FormSyntaxControl.atributs )) != (char *) 0) {
		if ( strlen(vptr) < blen )	 {
			if (!( Context.Form->abal.flags & 16 ))
				strcpy(bptr,vptr);			
			else	respectcase(bptr,vptr);
			}
		liberate( vptr );
		}
	/* remove any zeros from string */
	for (i=0; i < rlen; i++ ) 
		if (!( *(rptr+i) ))
			*(rptr+i) = ' ';
	return;
}

public	char *	FormWidgetList(int selection)
{
	char	*	lptr=(char *) 0;
	char	*	tptr=(char *) 0;
	struct	form_item * iptr;

	if ( FormSyntaxControl.selection != (selection+1) ) {
		if ( FormSyntaxControl.objects )
			liberate( FormSyntaxControl.objects );
		FormSyntaxControl.objects  = (char *) 0;
		FormSyntaxControl.item = 0;
		FormSyntaxControl.selection = 0;
		}

	if (!( FormSyntaxControl.objects )) {
		for (	iptr=FormSyntaxControl.form->first;
			iptr != (struct form_item*) 0;
			iptr = iptr->next ) {
			if (!( iptr->Contents.name ))
				continue;
			else if ((iptr->Contents.style & _FRAME_TYPE) != selection)
				continue;
			if (!( lptr )) {
				if (!( lptr = allocate_string( iptr->Contents.name ) ))
					break;
				}
			else if (!( tptr = allocate( strlen(lptr)+strlen(iptr->Contents.name)+3) ))
				break;
			else	{
				sprintf(tptr,"%s|%s",lptr,iptr->Contents.name);
				liberate( lptr );
				lptr = tptr;
				}
			}
		FormSyntaxControl.objects=lptr;
		FormSyntaxControl.selection = (selection+1);
		}
	return(FormSyntaxControl.objects);
}

public	char *	FormMethodList(int item)
{
	struct	form_item * iptr;
	if ( (item+1) != FormSyntaxControl.item ) {
		if ( FormSyntaxControl.atributs ) {
			liberate( FormSyntaxControl.atributs );
			FormSyntaxControl.atributs = (char *) 0;
			}
		FormSyntaxControl.item = (item+1);
		}

	
	if ((!( FormSyntaxControl.atributs )) 
	&&    ( FormSyntaxControl.selection )) {
		switch ( (FormSyntaxControl.selection-1) ) {
			case	_DATA_FRAME	:
				if ((FormSyntaxControl.selection != 0) && (FormSyntaxControl.item != 0)) { 	
					iptr = FormCompositionWidget(FormSyntaxControl.selection-1,FormSyntaxControl.item-1);
					if ( is_file_Widget(iptr) ) {
						FormSyntaxControl.atributs=data_member_list(iptr);
						break;
						}
					}
				else	{
					iptr = (struct form_item *) 0;
					FormSyntaxControl.atributs=data_member_list(iptr);
					break;
					}

			case	_FORM_FRAME	:
			case	_FILL_FRAME	:		
			case	_OUTSET_FRAME	:
			case	_INSET_FRAME	:	
			case	_RIDGE_FRAME	:	
			case	_GROOVE_FRAME	:
			case	_EDIT_FRAME	:		
			case	_TEXT_FRAME	:		
			case	_IMAGE_FRAME	:	
			case	_LINE_FRAME	:		
			case	_BUTTON_FRAME	:
			case	_WINDOW_FRAME	:
			case	_TAB_FRAME	:
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
			case	_SELECT_FRAME	:
			case	_SCROLL_FRAME	:
			case	_PROGRESS_FRAME	:
			case	_SWITCH_FRAME	:
			case	_GRAPH_FRAME	:	
				FormSyntaxControl.atributs=widget_member_list();
				break;
			}
		}	
	return(FormSyntaxControl.atributs);
}


public	int	FormSyntaxComposer(struct form_control * fptr )
{
	int	concat=0;

	/* Preparation of object controller */
	/* -------------------------------- */
	FormSyntaxControl.form     = fptr;
	FormSyntaxControl.objects  = 
	FormSyntaxControl.atributs = 
	FormSyntaxControl.result   = (char *) 0;

/*
	FormSyntaxControl.item     = 0;
	FormSyntaxControl.selection = 0;
	FormSyntaxControl.current   = 0;
 */
	if ( accept_form_syntax( 
		&FormSyntaxControl.result,
		&FormSyntaxControl.selection,
		&FormSyntaxControl.current,
		&FormSyntaxControl.item, &concat ) != 27) {

		if ( FormSyntaxControl.result ) 
			editorOnUseString(FormSyntaxControl.result);

		}

	/* Liberation of object controller */
	/* ------------------------------- */
	if ( FormSyntaxControl.result )
		liberate( FormSyntaxControl.result );
	if ( FormSyntaxControl.objects )
		liberate( FormSyntaxControl.objects );
	if ( FormSyntaxControl.atributs )
		liberate( FormSyntaxControl.atributs );
	return(256);
}




#endif	/* _singform_c */


