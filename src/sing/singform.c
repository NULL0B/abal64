#ifndef	_singform_c
#define	_singform_c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
#include "vstyle.h"

#define	ABAL31E		/* New Widget Properties Mechanisms */

#define CI_MODULE_ID 0x8000 /* pour la trace */
#if defined(WIN32)
#ifdef VISUAL_EXPORTS
#include "visualtrace.h"
#else
#include "extrace.h"
#endif
#else
#define TRACEON
#include "trace.h"
#define CI_TRA_F_DEBUG 0x0040
#endif

extern	char *	classbuffer;
extern	char	namebuffer[];
extern	struct	screen_control	Context;
extern	char *	font_name[];
extern	char 	LaPaterne[];
extern	char *	VisualMember[];
extern	char *	DataMember[];

extern	int	SystemD;
static	int	RightButtonStretch=0;

#ifdef	WIN32
#define	__ROLLBACK_PREFIX "roll"
#else
#define	__ROLLBACK_PREFIX "roll"
#endif

/*	---------------------------------	*/
/*	These are used to display widgets	*/
/*	---------------------------------	*/
char * widget_cursor_style=(char *) 0;
char * locked_cursor_style=(char *) 0;
/*	---------------------------------	*/

#ifdef	ABAL31E
struct SpecificWidgetProperties  form_widgetProperties;	
struct accept_widget_properties_context;
struct accept_widget_properties_context *widget_properties_context;
#endif
int vfh1=0;
/*	-------------------------------------------------------		*/
/*	Forward reference Function Prototypes for DOS compilers 	*/
/*	-------------------------------------------------------		*/
extern	char *	selection_item( int item, char * sptr );
public	char *	join_widget_style( struct form_item * iptr );
public	void	separate_widget_style( struct form_item * iptr, char * sptr );
#ifndef ABALCPP	/* WGB le 18/06/2007 */
public	int	accept_widget_properties_show(struct accept_widget_properties_context * _Context);
#endif
public	struct element_style * resolve_style_class( char * tptr );
private	void	apply_cut_align( struct form_item * cptr, struct form_control * fptr);
public	void	compare_Forms( struct form_control * fptr );
public char  *	allocate_string(char *sptr);
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
extern	char *	get_style_class_element(int number);
extern	char *	get_style_class_list(int separator);
public	char *	visual_table_testdata( struct form_item * iptr );
private	void	remove_widget(	struct form_control * fptr, 	struct form_item * iptr );
private	int	inside_widget( struct form_item * iptr, int x, int y );
private	int	inside_widget_cursor( struct form_item * iptr, int x, int y );
private	int	inside_line_cursor( struct form_item * iptr, int x, int y );
private	int	change_FormMember( struct form_control * fptr, int event );

public 	char	workbuffer[1024];
private	struct	window_control FormWindow;

void init_whResize(struct form_item * iptr);

/*	-------------------------------------------------------------	*/
/*	This structure is used to hold the results of analysis		*/
/*	of an editor zoom token analysis for linkage. This occurs	*/
/*	In resolve to the editor menu action Editor Resolve		*/
/*	for a specific token expression to be resolved for inspection	*/
/*	as a widget.method expression or a forms method expression.	*/
/*	-------------------------------------------------------------	*/
private	struct	forms_resolver	{
	int	nature;
	struct	form_item 	* widget;
	struct	forms_method	* method;
	char 			* action;
	} FormZoom = { 
		0, 
		(struct form_item *) 0, 
		(struct forms_method *) 0, 
		(char *) 0 
		};

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

#include "singfmf.c"	/* font label management */

public	int	detect_forms_special_method( char * mptr )
{
	if (!( mptr ))
		return(0);
	else if ( upper_compare( _METHOD_STDINPUT , mptr ) )
		return(_FORMS_STDINPUT );
	else if ( upper_compare( _METHOD_STDERROR, mptr ) ) 
		return(_FORMS_STDERROR );
	else if ( upper_compare( _METHOD_ONESCAPE, mptr ) ) 
		return(_FORMS_ONESCAPE );
	else if ( upper_compare( _METHOD_ONENTER, mptr ) ) 
		return(_FORMS_ONENTER );
	else if ( upper_compare( _METHOD_ONDEFAULT, mptr ) ) 
		return(_FORMS_ONDEFAULT );
	else if ( upper_compare( _METHOD_ONPREVIEW, mptr ) ) 		
		return(_FORMS_ONPREVIEW );
	else if ( upper_compare( _METHOD_ONPRECONSTR, mptr ) ) 		
		return(_FORMS_ONPRECONSTR );
	else if ( upper_compare( _METHOD_ONPOSTDESTR, mptr ) ) 		
		return(_FORMS_ONPOSTDESTR );
	else if ( upper_compare( _METHOD_ONHINT, mptr ) ) 		
		return(_FORMS_ONHINT );
	else if ( upper_compare( _METHOD_ONPAGE, mptr ) ) 		
		return(_FORMS_ONPAGE );
	else if ( upper_compare( _METHOD_POSITIONAT, mptr ) ) 		
		return(_FORMS_POSITIONAT );
	else	return( 0 );
}


public	char *	GetWidgetStyle(int w)
{
	if (!( Context.usestyle ))
		return(" ");
	else	{
		switch ( w ) {
			case	0 : return(_STYLE_WIDGET_WINDOW);

			case	1 : return(_STYLE_MENUTRAY_FRAME);
			case	2 : return(_STYLE_MENUTRAY_LABEL);
			case	3 : return(_STYLE_MENUTRAY_FOCUS);

			case	4 : return(_STYLE_MENUBAR_FRAME);
			case	5 : return(_STYLE_MENUBAR_LABEL);
			case	6 : return(_STYLE_MENUBAR_FOCUS);

			case	7 : return(_STYLE_MENUBAR_TRAY );
			case	8 : return(_STYLE_STATUSBAR_FRAME );

			case	9 : return(_STYLE_TOOLBAR_FRAME );
			case   10 : return(_STYLE_TOOLBAR_LABEL );

			case   11 : return(_STYLE_STATUSBAR_MESSAGE );
			case   20 : return( _STYLE_CTRL_BUTTON );
			case   21 : return( _STYLE_CTRL_LABEL  );
			default	  : return(" ");
			}
		}
}

private	char * 	resolve_dollar_style( char * sptr )
{
	char *	tptr;
	char *	wptr;
	int	item;

	if (!( sptr ))
		return(sptr);
	else if (!( tptr = allocate_string( sptr )))
		return((char *) 0);

	for ( 	wptr=tptr;
		*wptr != 0;
		wptr++ ) {
		if ( *wptr == '(' )
			break;
		}
	if ( *wptr != '(' ) {
		liberate( tptr );
		return((char *) 0);
		}
	else	{
		*(wptr++) = 0;
		if ( strcmp( tptr, "GetWidgetStyle" ) ) {
			liberate( tptr );
			return((char *) 0);
			}
		else	{
			item = atoi( wptr );
			liberate( tptr );
			if (!( tptr = GetWidgetStyle( item ) ))
				return( tptr );
			else	return( allocate_string( tptr ) );
			}
		}
}

private	int	forms_visual_style(int x, int y, int w, int h, char * sptr, char * mptr, int mlen )
{
	char	*	vptr;
	int		dollar;
	int	item=0;

	if ((dollar =  *sptr) == _UNQUOTED_STRING )
		if (!( sptr = resolve_dollar_style( (sptr+1) ) ))
			return(0);	

	while ((vptr = selection_item(item++,sptr )) != (char *) 0)
		visual_styled_element( x,y,w,h, vptr, mptr, mlen );

	if ( dollar == _UNQUOTED_STRING )
		liberate( sptr );
	return(1);
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
	if ( is_expert_user() ) 
		return( ProductionLanguages );
#ifdef	ABAL34A
	else	return("Abal|Abal++|Web-Agent|Php|XMTA|BIFS|LASER");
#else
#ifdef	ABAL32A
	else	return("Abal|Abal++|Web-Agent");
#else
	else	return( "Abal|Abal++" );
#endif
#endif
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

public	char	*	WidgetStyleList()
{
	char *	sptr;
	if (!( sptr = get_style_class_list('|') ))
		return((char *) "buttonframe|windowframe");
	else	return( sptr );
}


public	char	*	EnglishWidgetPayload(int widget)
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
		case _EDIT_FRAME:
			return("Initial Value");
		default			:
			return( "Payload" );
		}
}

public	char	*	FrenchWidgetPayload(int widget)
{
	switch ( widget ) {
		case	_WINDOW_FRAME	:
		case	_OUTSET_FRAME	:
		case	_INSET_FRAME	:
		case	_GROOVE_FRAME	:
		case	_RIDGE_FRAME	:
			return( "Titre" );
		case	_SELECT_FRAME	:
			return("ListeOptions");
		case	_TEXT_FRAME	:
			return("Message");
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
		case	_SWITCH_FRAME	:
		case	_TAB_FRAME	:
			return("Libell‚");
		case	_BUTTON_FRAME	:
			return("Libell‚/Image");
		case	_FORM_FRAME	:
			return("TitresColonnes");
		case	_IMAGE_FRAME	:
			return("Image");
		case	_DATA_FRAME	:
			return("Fichier");
		case _EDIT_FRAME:
			return("Valeur initiale");
		default			:
			return( "ChargeUtile" );
		}
}

public	char	*	WidgetPayload(int widget)
{
	switch ( visual_national_language(-1) ) {
		case	0 : return( EnglishWidgetPayload(widget) );
		case	1 : return(  FrenchWidgetPayload(widget) );
		default	  : return( EnglishWidgetPayload(widget) );
		}
}

public	char	*	EnglishWidgetMessage(int widget,int item)
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
				case	3	: return( "Colour" );
				default		: return( "N/A" );
				}
		case	_EDIT_FRAME	:
			switch ( item ) {
				case	1	: return( "Ask");
				case	2	: return( "Secret");
				case	3	: return( "N/A");
				case	4	: return( "Refresh" );
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
				case	4	: return( "Compact" );
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
				default		: return( "DragBar" );
				}
		case	_DATA_FRAME	:
			switch ( item ) {
				case	1	: return( "NoCreate" );
				case	2	: return( "Exclusive" );
				case	3	: return( "ReadOnly" );
				default		: return( "N/A" );
				}
		case _SELECT_FRAME			:
			switch ( item ) {
				case	1	: return( "Open" );
				case	2	: return( "Underline" );
				case	3 	: return( "Shadow" );
				case	4	: return( "Sort");
				default		: return( "N/A" );
				}
		default			:
			switch ( item ) {
				case	1	: return( "Bold" );
				case	2	: return( "Underline" );
				case	3 	: return( "Shadow" );
				default		: return( "N/A" );
				}
		}

}

public	char	*	FrenchWidgetMessage(int widget,int item)
{
	if ( item == 0 ) {
		if ( widget == _BUTTON_FRAME ) 
			return("Cible");
		else	return("Format");
		}

	switch ( widget ) {
		case	_BUTTON_FRAME	:
			switch ( item ) {
				case	1	: return( "Adjust‚/Gras");
				case	2	: return( "Soulign‚" );
				case	3	: return( "Couleur" );
				default		: return( "N/D" );
				}
		case	_EDIT_FRAME	:
			switch ( item ) {
				case	1	: return( "Ask");
				case	2	: return( "Secret");
				case	3	: return( "N/D");
				case	4	: return( "Suivi");
				default		: return( "N/D" );
				}
		case	_PROGRESS_FRAME	:
			switch ( item ) {
				case	1	: return( "Gras" );
				case	2	: return( "Soulign‚" );
				case	3	: return( "Relief" );
				default		: return( "N/D" );
				}
		case	_FORM_FRAME	:
			switch ( item ) {
				case	1	: return( "Obliger");
				case	2	: return( "Soulign‚" );
				case	3	: return( "Relief" );
				case	4	: return( "Compact" );
				default		: return( "N/D" );
				}

		case	_SCROLL_FRAME	:
			switch ( item ) {
				case	1	: return( "Prise" );
				default		: return( "N/D" );
				}
		case	_IMAGE_FRAME	:
			switch ( item ) {
				case	3	: return( "Transparent" );
				case	2	: return( "Qualit‚");
				default		: return( "N/D" );
				}
		case	_WINDOW_FRAME	:
			switch ( item ) {
				case	1	: return( "Sortie" );
				case	2	: return( "Aide" );
				case	3	: return( "Ombrage" );
				default		: return( "Deplacement" );
				}
		case	_DATA_FRAME	:
			switch ( item ) {
				case	1	: return( "SansCr‚er" );
				case	2	: return( "Exclusive" );
				case	3	: return( "Lecture" );
				default		: return( "N/D" );
				}
		case _SELECT_FRAME			:
			switch ( item ) {
				case	1	: return( "Ouvert" );
				case	2	: return( "Soulign‚" );
				case	3 	: return( "Ombrage" );
				case	4	: return( "tri‚");
				default		: return( "N/D" );
				}
		default			:
			switch ( item ) {
				case	1	: return( "Gras" );
				case	2	: return( "Soulign‚" );
				case	3 	: return( "Ombrage" );
				default		: return( "N/D" );
				}
		}
}

public	char	*	WidgetMessage(int widget,int item)
{
	switch ( visual_national_language(-1) ) {
		case	0 :	return( EnglishWidgetMessage(widget,item) );
		case	1 :	return(  FrenchWidgetMessage(widget,item) );
		default   :	return( EnglishWidgetMessage(widget,item) );
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
	if ( method_is_valid( iptr->Contents.events->on_create))
		items = widget_EventMessage(wptr,"CREATE",items);
	if ( method_is_valid( iptr->Contents.events->on_show))
		items = widget_EventMessage(wptr,"SHOW",items);
	if ( method_is_valid( iptr->Contents.events->on_get_focus))
		items = widget_EventMessage(wptr,"GETFOCUS",items);
	if ( method_is_valid( iptr->Contents.events->on_lose_focus))
		items = widget_EventMessage(wptr,"LOSEFOCUS",items);
	if ( method_is_valid( iptr->Contents.events->on_event))
		items = widget_EventMessage(wptr,"EVENT",items);
	if ( method_is_valid( iptr->Contents.events->on_hide))
		items = widget_EventMessage(wptr,"HIDE",items);
	if ( method_is_valid( iptr->Contents.events->on_remove))
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
	if (( iptr->Contents.style & _FRAME_TYPE ) == _TEXT_FRAME ) {
		if (!( nptr = iptr->Contents.payload )) {
			if (!( nptr = iptr->Contents.name ))
				nptr = "noname";
			}
		}
	else if (!( nptr = iptr->Contents.name ))
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
		if (( iptr->Contents.style & _FRAME_TYPE) == _IMAGE_FRAME ) {
			if (iptr->Contents.extra ) {
				iptr->Contents.extra = local_drop_image( iptr->Contents.extra );
				}	
			}
		else if ((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME) {
			if (iptr->Contents.extra ) {
				iptr->Contents.extra = drop_data_control( iptr->Contents.extra );
				}	
			}
		if ( iptr->Contents.name )
			iptr->Contents.name = liberate( iptr->Contents.name );

		if ( iptr->Contents.payload )
			iptr->Contents.payload = liberate( iptr->Contents.payload );
		if ( iptr->Contents.hint )
			iptr->Contents.hint = liberate( iptr->Contents.hint );

		for (i=0; i < MAXNATLANG; i++ ) {
			if ( iptr->Contents.messages[i] ) 
				iptr->Contents.messages[i]  = liberate( iptr->Contents.messages[i] );
			if ( iptr->Contents.hmessages[i] ) 
				iptr->Contents.hmessages[i]  = liberate( iptr->Contents.hmessages[i] );
			}

		if ( iptr->Contents.format )
			iptr->Contents.format = liberate( iptr->Contents.format );

		if ( iptr->Contents.stylesheet )
			iptr->Contents.stylesheet = liberate( iptr->Contents.stylesheet );

		if ( iptr->Contents.stylefocus )
			iptr->Contents.stylefocus = liberate( iptr->Contents.stylefocus );

		if ( iptr->Contents.stylepress )
			iptr->Contents.stylepress = liberate( iptr->Contents.stylepress );

		drop_event_control(& iptr->Contents.abal_events );
		drop_event_control(& iptr->Contents.c_events );

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

private	char  *	rollback_filename( char * nptr, int i )
{
	char *	nomfic;
	char *	tmpfic;
	char *	pthfic;

	if (!( nptr ))
		return( nptr );
	else if (!( nomfic = allocate( strlen(nptr) +256 )))
		return( nomfic );
	else if (!( tmpfic = allocate( strlen(nptr) +64 ))) {
		liberate( nomfic );
		return( tmpfic );
		}
	else if (!( pthfic = allocate( strlen(nptr) +64 ))) {
		liberate( nomfic );
		liberate( tmpfic );
		return( pthfic );
		}
	else	{
		fn_parser(nptr,pthfic,0x0007);
		fn_parser(nptr,tmpfic,0x0018);
 		sprintf(nomfic,"%s%s%u%s",pthfic,__ROLLBACK_PREFIX,i,tmpfic );
		liberate( tmpfic );
		liberate( pthfic );
		return( nomfic );
		}
}

public	void	unlink_form_rollback(struct form_control * fptr, int i )
{
	char *	nomfic;

	if (!( fptr->loadname ))
		return;
	else if (!( nomfic = rollback_filename( fptr->loadname, i )))
			return;
	else	{
		unlink( nomfic );
		liberate( nomfic );
		}
}

public	void	liberate_Form_rollnext(struct form_control *  fptr)
{
	int	i;
	if ( Context.rollback ) {
		for ( i=fptr->rollback; i <= fptr->rollnext; i++ ) 
			unlink_form_rollback( fptr, i );
		}
	return;
}

public	void	save_for_rollback(struct form_control * fptr, int force, char * caller )
{
	char *	eptr;
	char *	nomfic;
	if ( Context.lockroll )
		return;
	else if (!( Context.rollback ))
		return;
	else if (( fptr->rollchck == fptr->outofdate ) && (!( force )))
		return;
	else if (!( nomfic = rollback_filename( fptr->loadname, ++fptr->rollback )))
		return;
	else	{
		liberate_Form_rollnext(fptr);
		if ((eptr = confgetenv("SINGROLL")) != (char *) 0)
			printf("rollback save : %u : %s : from %s \r\n",fptr->rollback,nomfic,caller);
		xml_put_Form( nomfic, fptr, "sing.dtd" );
		fptr->rollchck = fptr->outofdate;
		fptr->rollnext = fptr->rollback;
		liberate( nomfic );
		return;
		}
}


public 	void	form_is_outofdate( struct form_control * fptr )
{
	if (!( Context.lockroll )) {
		fptr->outofdate++;
		Context.OutOfDate |= 1;
		}
	return;
}

#include "singmemb.c"

public	void	check_forms_production( struct form_control * fptr )
{
	switch ( fptr->language ) {
		case	_GENERATE_C	:
			fptr->prodname = enforce_extension(fptr->prodname,C_EXTENSION);
			break;
		case	_GENERATE_CPP	:
			fptr->prodname = enforce_extension(fptr->prodname,CPP_EXTENSION);
			break;
		case	_GENERATE_BAL	:
			fptr->prodname = enforce_extension(fptr->prodname,(Context.BalOrAbal ? S_EXTENSION : AS_EXTENSION ));
			break;
		case	_GENERATE_ABAL	:
			fptr->prodname = enforce_extension(fptr->prodname,CLASS_EXTENSION);
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
		case	_GENERATE_ANDROID	:
			fptr->prodname = enforce_extension(fptr->prodname,JSON_EXTENSION);
			break;
		case	_GENERATE_PHP :
			fptr->prodname = enforce_extension(fptr->prodname,PHP_EXTENSION);
			break;
		case	_GENERATE_NODE :
			fptr->prodname = enforce_extension(fptr->prodname,NODE_EXTENSION);
			break;
		case	_GENERATE_BIFS :
			fptr->prodname = enforce_extension(fptr->prodname,BIFS_EXTENSION);
			break;
		case	_GENERATE_LASER :
			fptr->prodname = enforce_extension(fptr->prodname,LASER_EXTENSION);
			break;
		case	_GENERATE_XMTA :
			fptr->prodname = enforce_extension(fptr->prodname,XMTA_EXTENSION);
			break;
		}
	return;
}

public	void	prepare_form_fields( struct form_control * fptr, char * nptr )
{
	unsigned char *justname;

	if ( nptr ) {
                justname=allocate(strlen(nptr)+8);
	        fn_parser(nptr,justname,8);
		fptr->loadname   = allocate_string( nptr );
		fptr->prodname   = allocate_string( justname );
		fptr->identifier = allocate_string( justname );
		liberate(justname);
		check_forms_production( fptr );
		fptr->identifier = enforce_extension( fptr->identifier, NUL_EXTENSION );
		}
	return;
}

public	void	reset_form_control( struct form_control * fptr )
{
	int	i;

	fptr->OptionsCompile = (char *) 0;
	fptr->OptionsLinkage = (char *) 0;
	fptr->method_count	= 0;
	fptr->PositionAt	=
	fptr->OnPage		= 
	fptr->OnHint		= 
	fptr->OnEscape		= 
	fptr->OnEnter		= 
	fptr->OnDefault		= 
	fptr->OnPreview		= 
	fptr->OnPreConstr	= 
	fptr->OnPostDestr	=
	fptr->StandardInput	= 
	fptr->StandardError	=
	fptr->rootmethod	=
	fptr->lastmethod	= (struct forms_method*) 0;

	fptr->member_count	= 0;
	fptr->rootmember	=
	fptr->lastmember	= (struct forms_data_member*) 0;

	fptr->abal.flags	= 256;
	fptr->abal.values	= 0;
	fptr->abal.diezemem	= 16000;
	fptr->abal.diezefiles	= 256;
	fptr->abal.diezestack	= 2048;
	fptr->abal.diezeheap	= 0;
	fptr->abal.tokensize	= 0;
	fptr->abal.labelsize	= 0;
	fptr->abal.pragmafile	= (char *) 0;
	fptr->argvlen		= 24;
	fptr->argvcount		= 10;

	fptr->extends		= (char *) 0;
	fptr->host              = (void *) 0;
	fptr->Buffer.value      = (STDPSUPTR) 0;
	fptr->Buffer.x		=
	fptr->Buffer.y		=
	fptr->Buffer.width	=
	fptr->Buffer.height	= 0;
	fptr->outofdate   = 0;
	fptr->image	  = (struct standard_image *) 0;

	for ( i=0; i < MAXNATLANG; i++) { fptr->document[i] = (char *) 0; }

	fptr->hostname	  =
	fptr->dependance  =
	fptr->stylesheet  =
	fptr->clearscreen =
	fptr->prodname    =
	fptr->loadname    = (char *) 0;
	fptr->loadstamp   =
	fptr->savestamp   = 0L;
	fptr->construction=
	fptr->identifier  = (char *) 0;

	fptr->font      = 1;
	fptr->gridlock	= fptr->gridsize  = 0x0A0A;
	fptr->foreground= 27;
	fptr->background= 28;
	fptr->thickness	= 1;
	fptr->activetool	= _MOVE_FRAME;

	fptr->doctool     = _TEXT_TOOL;
	fptr->objects	  =
	fptr->page_number =
	fptr->pages	  =
	fptr->focus	  =
	fptr->items       = 0;
	fptr->resizeauto  = 0;
	fptr->resizew=800;
	fptr->resizeh=600;
	fptr->formflags   = ( _FORM_TYPE_DIALOG | _FORM_ESC | _FORM_DOWN | _FORM_PAGE_DOWN |_FORM_UP | _FORM_PAGE_UP | _FORM_TAB | _FORM_INTERNATIONAL );
	fptr->mimoflags   = (_MIMO_SEND_LEFT|_MIMO_SEND_RIGHT|_MIMO_DOWN|_MIMO_UP|_MIMO_INTERRUPT);

	fptr->isprogram   = 1;	/* production of a program		*/
	fptr->isoverlay   = 0;	/* production of a dll or overlay	*/
	fptr->ispopup     = 0;	/* production of a dll or overlay	*/
	fptr->isdynamic   = 0;	/* production of a dll or overlay	*/
	/* use camera properties default value */
	fptr->natlang	  = Context.natlang;
	fptr->printout.TopMargin=(char*)0;
	fptr->printout.BottomMargin=0;
	fptr->printout.LeftMargin=(char*)0;
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
	fptr->printout.TitleOpt=1;	
	fptr->printout.FeedOpt=SingConf->pagefeed;
	fptr->printout.NumbOpt=1;

	fptr->modext=0;
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

	fptr->extension=0;
	fptr->flow = 0;
	fptr->x = fptr->y	= -1;

	fptr->OptionsCompile = (char *) 0;
	fptr->OptionsLinkage = (char *) 0;
	fptr->hostname = (char *) 0;
#ifdef	ABAL32A
	fptr->imagetype		= 0;
	fptr->askatb		= 53;
	fptr->askback		= 15;
	fptr->askfore		= 0;
	fptr->inhibit_flush	= 0;
	fptr->styling		= 0;
	fptr->weboptions	= 1+2+16+64;
#endif
	fptr->radioshow		= 
	fptr->radiogroup  	= 
	fptr->radioshowall	= 0;
	fptr->interfaceitems	= 0;
	fptr->rollback		= 0;
	fptr->rollnext		= 0;
	fptr->rollchck		= 0;
	fptr->onlinehelp	= 0;
	fptr->palette		= (char *) 0;

	reset_form_control( fptr );

	fptr->extends = (char *) 0;
	fptr->language    = production_language();
	fptr->display     = 0;	
	fptr->hash	  = -1;
	fptr->top   =
	fptr->first = fptr->active  = 
	fptr->last  = fptr->current = (struct form_item*) 0;

	connect_treenode(fptr->treenode,TREE_FORM,fptr);

	fptr->printout.DeviceName=allocate_string("$ArgV(1)");
	fptr->printout.DriverName=allocate_string("$ArgV(2)");

	prepare_form_fields( fptr, nptr );

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
	form_is_outofdate(fptr);
	save_for_rollback(fptr,0,"add_Widget");
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

public	void	renumerate_form( struct form_control * fptr )
{
	int	changes=0;
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
		changes++;
		iptr->Contents.name =  automatic_name(number++);
		}
	return;
}

public	int	widget_is_locked(struct form_item * iptr)
{
	if ( iptr->Contents.events->control & _IS_XO_LOCK  )
		return(1);
	else 	return(is_form_camera_locked( iptr->parent ) );
}

private	void	interface_form( struct form_control * fptr )
{
	int	number=1;
	struct form_item * iptr;
	char	*	nptr;

	for (	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ( widget_is_locked( iptr ) )
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
		save_for_rollback( fptr,0, "interface_form" );
		}
	return;
}

public	void	calculate_interface_items( struct form_control * fptr )
{
	int	number=1;
	struct form_item * iptr;
	char	*	nptr;
	int		adjust=0;

	fptr->interfaceitems = 0;

	switch ( fptr->formflags & _FORM_TYPE_FLAGS ) {

		case	_FORM_TYPE_DIALOG	:
		case	_FORM_TYPE_EVENT 	:
			fptr->interfaceitems = 0;
			break;

		case	_FORM_TYPE_QUALITY	:
		case	_FORM_TYPE_PAGE  	:
			fptr->interfaceitems = 2;
			break;
		}

	for (	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if (!( iptr->Contents.interfaceitem ))
			iptr->Contents.interfacenumber = 0;
		else 	iptr->Contents.interfacenumber = ++fptr->interfaceitems;
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
		iptr->ismember= 0;
		for ( i=0; i < MAXNATLANG; i++) { iptr->document[i] = (char *) 0; }
		iptr->sequence = 0;
		iptr->Contents.hash = -1;
		iptr->Contents.cursor = 0;
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
		iptr->Contents.stylefocus   = (char *) 0;
		iptr->Contents.stylepress   = (char *) 0;
		iptr->Contents.stylesheet   = (char *) 0;
		iptr->Contents.access  =
		iptr->Contents.xlimit  =
		iptr->Contents.ylimit  =
		iptr->Contents.adjust  =
		iptr->Contents.page    =
		iptr->Contents.focus   =
		iptr->Contents.radio   =
		iptr->Contents.radiogroup =
		iptr->Contents.special =
		iptr->Contents.interfaceitem= 0;
		iptr->Contents.size    = 0;
		iptr->Contents.trigger = 0;
		iptr->Contents.linkage = (void *) 0;
		for (i=0; i < MAXNATLANG; i++) { iptr->Contents.messages[i] = (char *) 0; }
		for (i=0; i < MAXNATLANG; i++) { iptr->Contents.hmessages[i] = (char *) 0; }
		reset_event_control(&iptr->Contents.c_events,(iptr->Contents.style & _FRAME_TYPE));
		reset_event_control(&iptr->Contents.abal_events,(iptr->Contents.style & _FRAME_TYPE));
		iptr->Contents.events = &iptr->Contents.abal_events;
		init_whResize(iptr);
		return( iptr );
		}
}

void init_whResize(struct form_item * iptr)
{
	iptr->Contents.wResize = 0;
	iptr->Contents.hResize = 0;
	switch ( (iptr->Contents.style & _FRAME_TYPE ) )
		{
		case _FILL_FRAME:
		case _OUTSET_FRAME:
		case _INSET_FRAME:
		case _RIDGE_FRAME:
		case _GROOVE_FRAME:
		case _IMAGE_FRAME:
		case _LINE_FRAME:
		case _BUTTON_FRAME	:
		case	_WINDOW_FRAME:
		case	_TAB_FRAME 	:
		case	_FORM_FRAME	:
		case	_SCROLL_FRAME:
		case	_PROGRESS_FRAME	:
		case _GRAPH_FRAME:
			iptr->Contents.hResize = 1;

		case _EDIT_FRAME:
		case	_TEXT_FRAME:
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
		case	_SELECT_FRAME:
		case	_SWITCH_FRAME	:
			iptr->Contents.wResize = 1;		
		};
}

public	struct 	form_item * allocate_Widget(struct form_control * fptr)
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

			case	_RADIO_FRAME	:
			case	_CHECK_FRAME	:
				iptr->Contents.colour &= 0xFF00;
				iptr->Contents.colour |= standard_black;

			case	_BUTTON_FRAME	:
			case	_SWITCH_FRAME	:
				build_button( iptr );
				break;

			case	_TAB_FRAME	:
				build_title( iptr,"TAB" );
				break;
			case	_WINDOW_FRAME	:
				build_title( iptr, "Sing : Version 2.2b" );
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
	return;

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
	if ( fptr->printout.LeftMargin )
		fptr->printout.LeftMargin = liberate( fptr->printout.LeftMargin );
	if ( fptr->printout.TopMargin )
		fptr->printout.TopMargin = liberate( fptr->printout.TopMargin );
	if ( fptr->printout.PageHead )
		fptr->printout.PageHead = liberate( fptr->printout.PageHead );
	if ( fptr->printout.PageFoot )
		fptr->printout.PageFoot = liberate( fptr->printout.PageFoot );
	if ( fptr->printout.DeviceName )
		fptr->printout.DeviceName = liberate( fptr->printout.DeviceName );
	if ( fptr->printout.DriverName )
		fptr->printout.DriverName = liberate( fptr->printout.DriverName );

	if ( fptr->hostname  != (char *) 0)
		fptr->hostname = liberate( fptr->hostname );
	if ( fptr->extends  != (char *) 0)
		fptr->extends = liberate( fptr->extends );
	if ( fptr->prodname  != (char *) 0)
		fptr->prodname = liberate( fptr->prodname );

	if ( fptr->palette  != (char *) 0)
		fptr->palette = liberate( fptr->palette );

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

	if ( fptr->OptionsCompile ) 
		fptr->OptionsCompile = liberate( fptr->OptionsCompile );

	if ( fptr->OptionsLinkage ) 
		fptr->OptionsLinkage = liberate( fptr->OptionsLinkage );

	reset_form_control( fptr );

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

		if ( is_named_widget( wptr ) ) 
		{
			if ( iptr->Contents.name )
				iptr->Contents.name = liberate( iptr->Contents.name );
			iptr->Contents.name = allocate_string( wptr->Contents.name );
		}

		iptr->doctool = wptr->doctool;

		for (i=0; i < MAXNATLANG; i++ ) 
		{
			if ( wptr->document[i] )
				iptr->document[i] = allocate_string( wptr->document[i] );
			else	iptr->document[i] = (char *) 0;
		}

		iptr->shitem =
		iptr->shatx  =
		iptr->shaty  = 0;
		iptr->number =++Context.numbering;
		iptr->Contents.cursor   = wptr->Contents.cursor;
		iptr->Contents.trigger	= wptr->Contents.trigger;
		iptr->Contents.special	= wptr->Contents.special;
		iptr->Contents.style	= wptr->Contents.style;
		iptr->Contents.access	= wptr->Contents.access;
		iptr->Contents.x	= wptr->Contents.x;
		iptr->Contents.y	= wptr->Contents.y;	
		iptr->Contents.w	= wptr->Contents.w;	
		iptr->Contents.h	= wptr->Contents.h;	
		iptr->Contents.colour	= wptr->Contents.colour;	
		iptr->Contents.size	= wptr->Contents.size;	
		iptr->Contents.font	= wptr->Contents.font;	
		iptr->Contents.align	= wptr->Contents.align;	
		iptr->Contents.interfaceitem= wptr->Contents.interfaceitem; 
		iptr->Contents.wResize=wptr->Contents.wResize;
		iptr->Contents.hResize=wptr->Contents.hResize;

		copy_event_control( &iptr->Contents.c_events, &wptr->Contents.c_events );
		copy_event_control( &iptr->Contents.abal_events, &wptr->Contents.abal_events );

		iptr->Contents.datatype	= wptr->Contents.datatype;

		for (i=0; i < MAXNATLANG; i++ ) 
		{
			if ( wptr->Contents.messages[i] )
				iptr->Contents.messages[i] = allocate_string( wptr->Contents.messages[i] );
			else	iptr->Contents.messages[i] = (char *) 0;
		}

		for (i=0; i < MAXNATLANG; i++ ) 
		{
			if ( wptr->Contents.hmessages[i] )
				iptr->Contents.hmessages[i] = allocate_string( wptr->Contents.hmessages[i] );
			else	iptr->Contents.hmessages[i] = (char *) 0;
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

		if ( wptr->Contents.stylefocus )
			iptr->Contents.stylefocus = allocate_string( wptr->Contents.stylefocus );
		else	iptr->Contents.stylefocus = (char *) 0;

		if ( wptr->Contents.stylepress )
			iptr->Contents.stylepress = allocate_string( wptr->Contents.stylepress );
		else	iptr->Contents.stylepress = (char *) 0;

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


public	void	liberate_Form_rollback(struct form_control *  fptr)
{
	int	i;
	if ( Context.rollback ) {
		for ( i=1; i <= fptr->rollnext; i++ ) 
			unlink_form_rollback( fptr, i );
		}
	return;
}


public	struct form_control * liberate_Form(struct form_control *  fptr)
{
	int	i;
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
		if ( mptr  != (char *) 0) {
			for (i=0; i < MAXNATLANG; i++ ) {
				if (( sptr = iptr->Contents.messages[i]) != (char *) 0)
					continue;
				else if (!( iptr->Contents.messages[i] = allocate_string( mptr ) ))
					break;
				else	continue;
				}
			}
		sptr = mptr = (char *) 0;
		for (i=0; i < MAXNATLANG; i++ ) {
			if (!( sptr = iptr->Contents.hmessages[i]))
				continue;
			else if ( *sptr != _UNQUOTED_STRING )
				continue;
			else	{
				mptr = sptr;
				break;
				}
			}
		if ( mptr  != (char *) 0) {
			for (i=0; i < MAXNATLANG; i++ ) {
				if (( sptr = iptr->Contents.hmessages[i]) != (char *) 0)
					continue;
				else if (!( iptr->Contents.hmessages[i] = allocate_string( mptr ) ))
					break;
				else	continue;
				}
			}

		return;
		}
}

private	void	check_QuoteCount( char * sptr, char * mptr )
{
	int	qc=0;
	if (!( sptr ))
		return;
	while ( *sptr )
		if ( *(sptr++) == '"' )
			qc++;
	if ( qc & 1 )
		report_quote_count(mptr);

	return;
}

private	int	detect_form_instance_type( struct form_item * iptr )
{
	struct	form_control 	* fptr;
	char 			* sptr;
	if (!( method_is_valid(( sptr = iptr->Contents.payload)) ))
		return(0);
	else if (!(fptr = locate_form_control( sptr ) ))
		return(0);
	else if (!( fptr->isoverlay ))
		return(0);
	else if (!( fptr->isprogram ))
		return((iptr->Contents.datatype = _WIDGET_MODULE));
	else	return((iptr->Contents.datatype = _WIDGET_OVERLAY));
}
				
private	char *	default_public_widget_focus( struct form_item * iptr )
{
	switch ((iptr->Contents.style & _FRAME_TYPE )) {
		case	_BUTTON_FRAME	:
		case	_CHECK_FRAME    :
		case	_RADIO_FRAME    :
		case	_SWITCH_FRAME	:
		case	_SELECT_FRAME	:
			return( allocate_string("this.OnShow.Focus() :: this.OnFocus() :: this.OnShow() :: Exit(KeyCode)") );
		default			:
			return( allocate_string("this.OnFocus() :: Exit(KeyCode)") );
		}
}
	
public 	void	check_Widget(struct form_item * iptr )
{
	struct	form_control * fptr;
	char * nptr;
	int	i;
	int	fh;
	int	fw;

	if (!( iptr ))
		return;
	else if ((fptr = iptr->parent) != (struct form_control *) 0) {
		switch ( fptr->language ) {
			case	_GENERATE_BAL	:
			case	_GENERATE_ABAL	:
			case	_GENERATE_HTML	:
				break;
			default			:
				fptr = (struct form_control *) 0;
			}
		}

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
		case	_LINE_FRAME	:
			iptr->Contents.align = _A_NONE;
			if (!( iptr->Contents.size ))
				iptr->Contents.size=1;
			break;
	
		case	_DATA_FRAME	:
			check_data_widget(  iptr );
			break;

		case	_FORM_FRAME	:		
			if (!( iptr->Contents.events->mimo ))
				iptr->Contents.events->mimo = _MIMO_DOWN;

			if ( iptr->Contents.h < fh )
				iptr->Contents.h = fh;
			if ( iptr->Contents.w < fw )
				iptr->Contents.w = fw;

			break;


		case	_EDIT_FRAME	:	
			if ( iptr->Contents.align & _A_SHADOW ) {
				iptr->Contents.align |= _A_BOLD;
				iptr->Contents.align &= ~_A_SHADOW;
				}

		case	_SCROLL_FRAME	:	/* scroll bar buttons	*/
		case	_CHECK_FRAME	:	/* message alignment	*/
		case	_RADIO_FRAME	:	/* message alignment	*/
		case	_TAB_FRAME	:	/* tab alignment	*/	
		case	_SELECT_FRAME	:	/* button alignment	*/
		case	_WINDOW_FRAME	:	/* window alignment 	*/

			if (!( iptr->Contents.events->mimo ))
				iptr->Contents.events->mimo = _MIMO_UP;


		case	_FILL_FRAME	:
			break;
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
			if ( iptr->Contents.payload ) {
				if (!( Context.compiling )) {
					if ( iptr->Contents.extra )
						iptr->Contents.extra = local_drop_image( iptr->Contents.extra );
					iptr->Contents.extra   = widget_image_loader(iptr->Contents.payload,iptr->Contents.align);
					}
				}
			break;

		case	_BUTTON_FRAME	:	
			if (!( iptr->Contents.events->mimo ))
				iptr->Contents.events->mimo = _MIMO_UP;

			if (( iptr->Contents.datatype == _WIDGET_OVERLAY )
#ifdef	ABAL32A
			||  ( iptr->Contents.datatype == _WIDGET_TASK    )
#endif
			||  ( iptr->Contents.datatype == _WIDGET_SYSTEM  )
			||  ( iptr->Contents.datatype == _WIDGET_HYPERLINK  )
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
			if (!( iptr->Contents.events->mimo ))
				iptr->Contents.events->mimo = _MIMO_UP;


		case	_PROGRESS_FRAME	:
			if ( iptr->Contents.h < fh )
				iptr->Contents.h = fh;
			if ( iptr->Contents.w < fw )
				iptr->Contents.w = fw;

			break;

		/* these widgets have no defined semantics : A NONE */
		/* ------------------------------------------------ */
		case	_GRAPH_FRAME	:
			iptr->Contents.align = _A_NONE;
			break;

		}
	/* Check Payload Items */
	/* ------------------- */
	switch ( iptr->Contents.style & _FRAME_TYPE ) {
		case	_TEXT_FRAME	:
			if ( method_is_valid( iptr->Contents.payload ) )
				iptr->Contents.size = strlen( iptr->Contents.payload );
			else	iptr->Contents.size = 0;
			if ( iptr->Contents.size >= 256 )
				report_constant_size(iptr->Contents.payload);
			break;

		case	_FORM_FRAME	:
			/* its quite nice to have tables without titles */
			/* -------------------------------------------- */
			break;

		case	_SELECT_FRAME	:
			if (!( method_is_valid( iptr->Contents.payload )))
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

	switch ( ( iptr->Contents.style & _FRAME_TYPE ) ) {

		case	_DATA_FRAME	:
			if ((iptr->Contents.align & 0x000F) != _VISUAL_FRAME)
				break;
			else if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
			     &&  ( iptr->Contents.datatype != _WIDGET_MODULE  ))
				break;
			else if (iptr->Contents.events->on_create)
				break;
			else if (!( forms_dynamic_position( iptr->Contents.payload ) ))
				break;
			else if (!(iptr->Contents.events->on_create = allocate(64)))
				break;
			else	{
				iptr->Contents.events->mimo		|= _MIMO_DOWN;
				iptr->Contents.events->xo_event     	= 
				iptr->Contents.events->xo_get_focus 	= _FUNCTION_AND_FOCUS;
				sprintf(iptr->Contents.events->on_create,"this.PositionAt(this.x,this.y)\r\n",0x0022,0x0022);
				break;
				}

		case	_BUTTON_FRAME	:

			/* Trigger buttons need parameters */
			/* ------------------------------- */
			if (( iptr->Contents.datatype == _WIDGET_OVERLAY )
			||  ( iptr->Contents.datatype == _WIDGET_CHAIN   )
#ifdef	ABAL32A
			||  ( iptr->Contents.datatype == _WIDGET_TASK    )
#endif
			||  ( iptr->Contents.datatype == _WIDGET_SYSTEM  )
			||  ( iptr->Contents.datatype == _WIDGET_LOADGO  )) {
				if ( fptr ) {
					if (!( method_is_valid( iptr->Contents.events->on_event ) ))
						if ((iptr->Contents.events->on_event = allocate(64)) != (char *) 0)
							sprintf(iptr->Contents.events->on_event,"this.buffer=%c %c\r\n",0x0022,0x0022);
					}
				}
			else if ( iptr->Contents.datatype == _WIDGET_HYPERLINK  ) {
				if ( fptr ) {
					if (!( method_is_valid( iptr->Contents.events->on_event ) ))
						if ((iptr->Contents.events->on_event = allocate(64)) != (char *) 0)
							sprintf(iptr->Contents.events->on_event,"; hyper link button trigger\r\n");
					}
				}

			if (( iptr->Contents.datatype == _WIDGET_OVERLAY )
			||  ( iptr->Contents.datatype == _WIDGET_MODULE  )) 
				detect_form_instance_type( iptr );

			break;

		case	_SCROLL_FRAME	:
			if (!(iptr->Contents.events->on_create)) {
				if ( fptr ) {
					if ((iptr->Contents.events->on_create = allocate(64)) != (char *) 0)
						sprintf(iptr->Contents.events->on_create,"this.value=0\r\n{this.limit=[List].lines}\r\nthis.max=this.limit\r\n");
					}
				}
			if (!(iptr->Contents.events->on_event)) {
				if ( fptr ) {
					if ((iptr->Contents.events->on_event = allocate(64)) != (char *) 0)
						sprintf(iptr->Contents.events->on_event,"{ [List].Show() }\r\n");
					}
				}
			break;

		case	_FORM_FRAME	:
			if (!(iptr->Contents.events->on_show)) {
				if ( fptr ) {
					if ((iptr->Contents.events->on_show = allocate(256)) != (char *) 0)
						sprintf(iptr->Contents.events->on_show,"Dcl l%c,n%c\r\nthis.buffer=%c %c\r\nFor l = 1 to this.lines\r\nthis.line(l)\r\nNext l\r\nthis.OnShow()\r\n",0X0025,0x0025,0x0022,0x0022);
					}
				}
			break;
		}

	/* check public or extern member widget functions */
	/* ---------------------------------------------- */
	if ( iptr->Contents.access & (_WIDGET_PUBLIC | _WIDGET_EXTERN)) {
		if (!( method_is_valid( iptr->Contents.events->on_get_focus ) )) {
			if ((( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS    ))
			&&  (( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION ))) {
				iptr->Contents.events->on_get_focus = default_public_widget_focus( iptr );
				}
			}
		if (!( method_is_valid( iptr->Contents.events->on_show ) )) {
			if ((!( iptr->Contents.events->xo_show & _EVENT_IS_COND    ))
			&&  (( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION ))) {
				iptr->Contents.events->on_show = allocate_string("this.OnShow()");
				}
			}
		}

	/* check default button information */
	/* -------------------------------- */
	if (!( iptr->Contents.events->mimo & 
		( _MIMO_SEND_LEFT | _MIMO_SEND_RIGHT | _MIMO_SEND_MIDDLE | _MIMO_SEND_WHEEL ) )) {
		if ( iptr->Contents.events->mimo & 
			( _MIMO_UP | _MIMO_DOWN | _MIMO_MOVE | _MIMO_WHILE_DOWN )) { 
			if (( iptr->Contents.style & _FRAME_TYPE) != _SCROLL_FRAME) 
				iptr->Contents.events->mimo |= ( _MIMO_SEND_LEFT | _MIMO_SEND_RIGHT);
			else	iptr->Contents.events->mimo |= ( _MIMO_SEND_LEFT | _MIMO_SEND_RIGHT | _MIMO_SEND_WHEEL);
			}
		}
	perform_event_control( &iptr->Contents.c_events );
	perform_event_control( &iptr->Contents.abal_events );
	perform_message_control( iptr );
	check_Widget_trigger( &iptr->Contents );
	check_QuoteCount( iptr->Contents.payload,"widget payload" );
	check_QuoteCount( iptr->Contents.format ,"widget format" );
	check_QuoteCount( iptr->Contents.hint,	"widget hint" );
	if (iptr->Contents.events->on_create)
		check_QuoteCount( iptr->Contents.events->on_create,"method Create" );
	if (iptr->Contents.events->on_create)
		check_QuoteCount( iptr->Contents.events->on_remove,"method Remove" );
	if (iptr->Contents.events->on_show)
		check_QuoteCount( iptr->Contents.events->on_show,"method Show" );
	if (iptr->Contents.events->on_hide)
		check_QuoteCount( iptr->Contents.events->on_hide,"method Hide" );
	if (iptr->Contents.events->on_get_focus)
		check_QuoteCount( iptr->Contents.events->on_get_focus,"method GetFocus" );
	if (iptr->Contents.events->on_lose_focus)
		check_QuoteCount( iptr->Contents.events->on_lose_focus,"method LoseFocus" );
	if (iptr->Contents.events->on_event)
		check_QuoteCount( iptr->Contents.events->on_event,"method Event" );
	return;
}

/*	---------------------------------------------------	*/
/*		c h e c k _ W i d g e t s ( fptr )		*/
/*	---------------------------------------------------	*/
/*	This function is called prior to producing the HTML	*/
/*	documentation of a forms model from the 3D project	*/
/*	editor. This is necessary to ensure that all visual	*/
/*	component widgets have been correctly resolved and	*/
/*	there image is available.				*/
/*	---------------------------------------------------	*/
public 	void	check_Widgets(struct form_control * fptr)
{
	struct form_item * iptr;
	for (	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
		check_Widget( iptr );
	return;
}


public	int	change_widget_class(int * wcptr)
{
	char	*	mptr;
	char	*	tptr;
	int		wclass;
	int		result;
	struct SpecificWidgetProperties *pSpecificWidgetProperties=get_form_widgetProperties();
	void	*	vptr=widget_properties_context;

	if (!( wcptr )) {
		return(0);
		}
	else	wclass = *wcptr;

	if (!( pSpecificWidgetProperties->pWidgetClass )) {
		return(0);
		}
	else if ( wclass == *((int *)pSpecificWidgetProperties->pWidgetClass) ) {
		return(0);
		}
	else if (!( mptr = allocate_string("Do you want to save the current properties") )) {
		*wcptr = *((int *)pSpecificWidgetProperties->pWidgetClass) ;
		return(0);
		}
	else if (!( tptr = allocate_string("Prior to changing the widget class") )) {
		*wcptr = *((int *)pSpecificWidgetProperties->pWidgetClass) ;
		liberate( mptr );
		return(0);
		}
	else	{
		result = accept_yes_no_abandon( mptr, tptr );
		liberate( mptr );
		liberate( tptr );
		switch ( result ) {
			case	13 :
				/* YES : save widget data before class change */
				/* ------------------------------------------ */
#ifdef ABALCPP	/* GWB le 20/06/2007 */
				WidgetGetFields();
#else
				WidgetGetFields(vptr);
#endif
				*((int *)pSpecificWidgetProperties->pWidgetClass) = *wcptr;
#ifdef ABALCPP	/* GWB le 20/06/2007 */
				WidgetPutFields();
#else
				WidgetPutFields(vptr);
#endif
				return( 26 );

			case	26 :
				/* NO  : don't save widget data before class change */
				/* ------------------------------------------------ */
				*((int *)pSpecificWidgetProperties->pWidgetClass) = *wcptr;
				WidgetPutFields(vptr);
				return( 26 );

			case	27 :
			default	   :
				/* ABANDON : Do not change widget class */
				/* ------------------------------------ */
				*wcptr = *((int *)pSpecificWidgetProperties->pWidgetClass) ;
				return(  0 );
			}
		}
}


public	int	change_widget_view(int v)
{
	char	*	mptr;
	char	*	tptr;
	int		result;
	struct SpecificWidgetProperties *pSpecificWidgetProperties=get_form_widgetProperties();
	void	*	vptr=widget_properties_context;

	if ( use_all_widget() == v )
		return(0);

	else if (!( pSpecificWidgetProperties->pWidgetClass )) {
		return(0);
		}
	else if (!( mptr = allocate_string("Do you want to save the current properties") )) {
		return(0);
		}
	else if (!( tptr = allocate_string("Prior to changing the widget view") )) {
		liberate( mptr );
		return(0);
		}
	else	{
		result = accept_yes_no_abandon( mptr, tptr );
		liberate( mptr );
		liberate( tptr );
		switch ( result ) {
			case	13 :
				/* YES : save widget data before view  change */
				/* ------------------------------------------ */
#ifdef ABALCPP	/* GWB le 20/06/2007 */
				WidgetGetFields();
#else
				WidgetGetFields(vptr);
#endif
				set_all_widget(v);
#ifdef ABALCPP	/* GWB le 20/06/2007 */
				WidgetPutFields();
#else
				WidgetPutFields(vptr);
#endif
				return( 26 );

			case	26 :
				/* NO  : don't save widget data before view  change */
				/* ------------------------------------------------ */
				set_all_widget(v);
				WidgetPutFields(vptr);
				return( 26 );

			case	27 :
			default	   :
				/* ABANDON : Do not change widget view  */
				/* ------------------------------------ */
				return(  0 );
			}
		}
}


public 	int 	edit_Widget(struct form_item * iptr, struct form_control * fptr)
{
	char *	ssptr=(char *) 0;
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
	int	isaf;
	int	iin;
	int	ismove=0;
	int	isdown=0;
	int	isup=0;
	int	ishold=0;
	int	mlb=0;
	int	mrb=0;
	int	mmb=0;
	int	mwh=0;
	int	waccess=0;
	int	wextern=0;
	if ( iptr ) {
		waccess = (iptr->Contents.access & _WIDGET_PUBLIC ? 1 : 0);
		wextern = (iptr->Contents.access & _WIDGET_EXTERN ? 1 : 0);
		iin     = ((iptr->Contents.access & _WIDGET_ACCESS) >> 2);
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

		if ( iptr->Contents.align & _A_BAR )
			isaf = 1;
		else	isaf = 0;

		isa = (iptr->Contents.align & 0x00FF);
		if ( iptr->Contents.events->control & _IS_XO_LOCK  )
			isl = 1;
		else	isl = 0;
		if ( iptr->Contents.events->control & _IS_ON_MOUSE ) {
			if ( iptr->Contents.events->mimo & _MIMO_MOVE )
				ismove=1;
			if ( iptr->Contents.events->mimo & _MIMO_DOWN )
				isdown=1;
			if ( iptr->Contents.events->mimo & _MIMO_UP )
				isup=1;
			if ( iptr->Contents.events->mimo & _MIMO_WHILE_DOWN)
				ishold=1;
			if ( iptr->Contents.events->mimo & _MIMO_SEND_LEFT )
				mlb = 1;
			else	mlb = 0;
			if ( iptr->Contents.events->mimo & _MIMO_SEND_RIGHT )
				mrb = 1;
			else	mrb = 0;
			if ( iptr->Contents.events->mimo & _MIMO_SEND_MIDDLE )
				mmb = 1;
			else	mmb = 0;
			if ( iptr->Contents.events->mimo & _MIMO_SEND_WHEEL )
				mwh = 1;
			else	mwh = 0;
			}
		if (( mptr = widget_event_message( iptr )) != (char *) 0)
			status_message(mptr,1);

#ifdef	ABAL31E
		form_widgetProperties.pAtX = (char *)&iptr->Contents.x;
		form_widgetProperties.pAtY = (char *)&iptr->Contents.y;
		form_widgetProperties.pWidth = (char *)&iptr->Contents.w;
		form_widgetProperties.pHeight = (char *)&iptr->Contents.h;
		form_widgetProperties.pTextFont = (char *)&fid;
		form_widgetProperties.pTextColour = (char *)&fg;
		form_widgetProperties.pBackground = (char *)&bg;
		form_widgetProperties.pPayLoad = (char *)&iptr->Contents.payload;
		form_widgetProperties.pIdentity = (char *)&iptr->Contents.name;
		form_widgetProperties.pFormat = (char *)&iptr->Contents.format;

		form_widgetProperties.pStyleSheet = (char *) &iptr->Contents.stylesheet; 
		form_widgetProperties.pStyleFocus = (char *) &iptr->Contents.stylefocus; 
		form_widgetProperties.pStylePress = (char *) &iptr->Contents.stylepress; 
		form_widgetProperties.pHint = (char *)&iptr->Contents.hint;
		form_widgetProperties.pHotkeyValue = (char *)&iptr->Contents.trigger;
		form_widgetProperties.pWidgetClass = (char *)&wclass;
		form_widgetProperties.pAlign = (char *)&isa;
		form_widgetProperties.pType = (char *)&iptr->Contents.datatype;
		form_widgetProperties.pIsBold = (char *)&isb;
		form_widgetProperties.pIsUnderline = (char *)&isu;
		form_widgetProperties.pIsShadow = (char *)&iss;
		form_widgetProperties.pIsLock = (char *)&isl;
		form_widgetProperties.pIsInterface = (char *)&iptr->Contents.interfaceitem;
		form_widgetProperties.pIsSpecial = (char *)&iptr->Contents.special;
		form_widgetProperties.pIsSpecial2 = (char *)&isaf;
		form_widgetProperties.pCursorType = (char *)&iptr->Contents.cursor;
		form_widgetProperties.pIswResize = (char *)&iptr->Contents.wResize;
		form_widgetProperties.pIshResize = (char *)&iptr->Contents.hResize;
		form_widgetProperties.pInhibit   = &iin;
#endif
		if ( accept_widget_properties(
#ifndef	ABAL31E
			&iptr->Contents.x, 	&iptr->Contents.y,
			&iptr->Contents.w, 	&iptr->Contents.h,
			&fid,&fg, &bg,
			&iptr->Contents.payload,
			&iptr->Contents.name, 
			&iptr->Contents.format,
			&iptr->Contents.stylesheet,
			&iptr->Contents.stylefocus,
			&iptr->Contents.hint,
			&iptr->Contents.trigger,
			&wclass,
			&isa,	&iptr->Contents.datatype,
			&isb, 	&isu, &iss, &isl,
			&iptr->Contents.interfaceitem,
			&iptr->Contents.special,
#endif
			&waccess, &wextern,

			&iptr->Contents.events->xo_create,
			&iptr->Contents.events->on_create,

			&iptr->Contents.events->xo_show,
			&iptr->Contents.events->on_show,

			&iptr->Contents.events->xo_get_focus,
			&iptr->Contents.events->on_get_focus,

			&ismove, &isdown, &isup, &ishold,
			&mlb,	&mrb,	&mwh,	&mmb,

			&iptr->Contents.events->xo_event,
			&iptr->Contents.events->on_event,

			&iptr->Contents.events->xo_lose_focus,
			&iptr->Contents.events->on_lose_focus,

			&iptr->Contents.events->xo_hide,
			&iptr->Contents.events->on_hide,

			&iptr->Contents.events->xo_remove,
			&iptr->Contents.events->on_remove

			) != 27 ) {

			if ( waccess )
				iptr->Contents.access |= _WIDGET_PUBLIC;
			else	iptr->Contents.access &= ~_WIDGET_PUBLIC;

			if ( wextern )
				iptr->Contents.access |= _WIDGET_EXTERN;
			else	iptr->Contents.access &= ~_WIDGET_EXTERN;

			iptr->Contents.access &= ~ _WIDGET_ACCESS;
			iptr->Contents.access |= ((iin << 2) & _WIDGET_ACCESS);

			switch ((iptr->Contents.style & _FRAME_TYPE)) {
				case	_LINE_FRAME	:
					break;
				case	_GRAPH_FRAME 	:
					calculate_graph_size(&iptr->Contents);
					break;
				case	_FORM_FRAME	:
					calculate_edit_size(&iptr->Contents);
					break;
				default			:
					if (!( method_is_valid( iptr->Contents.payload ) ))
						iptr->Contents.size = 0;
					else iptr->Contents.size = strlen( iptr->Contents.payload );
					break;
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
			if ( isaf) iptr->Contents.align |= _A_BAR;

			if ( isl )
				iptr->Contents.events->control |= _IS_XO_LOCK;
			else	iptr->Contents.events->control &= ~_IS_XO_LOCK;
			
			if ( ismove )
				iptr->Contents.events->mimo |= _MIMO_MOVE;
			else	iptr->Contents.events->mimo &= ~_MIMO_MOVE;

			if ( isdown )
				iptr->Contents.events->mimo |= _MIMO_DOWN;
			else	iptr->Contents.events->mimo &= ~_MIMO_DOWN;

			if ( isup )
				iptr->Contents.events->mimo |= _MIMO_UP;
			else	iptr->Contents.events->mimo &= ~_MIMO_UP;

			if ( ishold )
				iptr->Contents.events->mimo |= _MIMO_WHILE_DOWN;
			else	iptr->Contents.events->mimo &= ~_MIMO_WHILE_DOWN;

			if ( mlb ) 
				iptr->Contents.events->mimo |= _MIMO_SEND_LEFT;
			else	iptr->Contents.events->mimo &= ~_MIMO_SEND_LEFT;

			if ( mrb ) 
				iptr->Contents.events->mimo |= _MIMO_SEND_RIGHT;
			else	iptr->Contents.events->mimo &= ~_MIMO_SEND_RIGHT;

			if ( mmb ) 
				iptr->Contents.events->mimo |= _MIMO_SEND_MIDDLE;
			else	iptr->Contents.events->mimo &= ~_MIMO_SEND_MIDDLE;

			if ( mwh ) 
				iptr->Contents.events->mimo |= _MIMO_SEND_WHEEL;
			else	iptr->Contents.events->mimo &= ~_MIMO_SEND_WHEEL;

			if (( iptr->Contents.style & _FRAME_TYPE ) == _CUT_FRAME )
				apply_cut_align( iptr, fptr );
			else 	{
				check_Widget(iptr);
				perform_event_control(&iptr->Contents.c_events);
				perform_event_control(&iptr->Contents.abal_events);
				}
			form_is_outofdate( fptr );
			save_for_rollback( fptr,0,"edit_Widget" );

			}
		else	{
			if ( ssptr )
				liberate( ssptr );
			}
		draw_console();
		/* flush pending events */
		while ( visual_kbhit() ) { visual_getch(); }
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


private	int	explicite_Styled_Widget(
	struct form_control  * fptr,
	struct form_item     * iptr)
{
	char *	sptr;	
	int	item=0;

	if (!( sptr = iptr->Contents.stylesheet)) 
		return(0);
	else if ((iptr->Contents.style & _FRAME_TYPE) == _EDIT_FRAME) {
		item = forms_visual_style(
				Context.DeskTop.x+iptr->Contents.x,
				Context.DeskTop.y+iptr->Contents.y,
				iptr->Contents.w+2,
				iptr->Contents.h+2,
				sptr,check_payload(iptr->Contents.payload),iptr->Contents.size);
		return(1);
		}
	else	{
		item = forms_visual_style(
				Context.DeskTop.x+iptr->Contents.x,
				Context.DeskTop.y+iptr->Contents.y,
				iptr->Contents.w,
				iptr->Contents.h,
				sptr,check_payload(iptr->Contents.payload),iptr->Contents.size);
		return(1);
		}

}

#include "styled.c"

public	char *	visual_table_testdata( struct form_item * iptr )
{
	char *	lptr;
	int	linelength=0;
	int	nblines=0;
	int	l;
	int	c;
	if (!( Context.UseTestData )) return((char *) 0);
	if (!( iptr ))	return((char *) 0);
	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );
	if (!( linelength * nblines )) return((char *) 0);
	if ((!( Context.TestData )) || ( Context.TestDataSize < (linelength * nblines))) {
 		if ( Context.TestData ) {
			liberate( Context.TestData );
			Context.TestData = (char *) 0;
			}
		if (!( Context.TestData = allocate((Context.TestDataSize=(linelength*nblines))) ))
			return((char *) 0);
		}
	for  (	l=0; l < nblines; l++ ) {
		lptr = (Context.TestData+(l*linelength));
		for (c=0; c < linelength; c++)
			*(lptr+c) = (0x0061 + (c % 26));
		}
	return(Context.TestData);
}


private	int	implicite_Styled_Widget(
	struct form_control  * fptr,
	struct form_item     * iptr)
{
	int	dummy=1;
	int	v=0;
	int	topx=Context.DeskTop.x;
	int	topy=Context.DeskTop.y;
	int	fid = (iptr->Contents.font-1);
	int	fg = (iptr->Contents.colour & 0x00FF);
	int	bg = (iptr->Contents.colour >> 8);
	int	focus=0;
	char *	sptr;

	switch (( iptr->Contents.style & _FRAME_TYPE )) {

		case	_FILL_FRAME	:
		case	_TEXT_FRAME	:
		case	_LINE_FRAME	:
		case	_IMAGE_FRAME	:
		case	_GRAPH_FRAME	:
		case	_DATA_FRAME	:
			return(0);

		case	_INSET_FRAME	:
			if ( is_styled_inset_frame(
				topx+iptr->Contents.x,topy+iptr->Contents.y,
				iptr->Contents.w,iptr->Contents.h, 
				iptr->Contents.style )  != 0 ) {
				return(0);
				}

			if (( iptr->Contents.align != _A_NONE     ) 
			&&  ( iptr->Contents.payload != (char *) 0)) {
				if ((sptr = allocate_string("inset_title")) != (char *) 0) {
					forms_visual_style(
						topx+iptr->Contents.x,
						topy+iptr->Contents.y,
						iptr->Contents.w,
						iptr->Contents.h,
						sptr,check_payload(iptr->Contents.payload),iptr->Contents.size);
					liberate(sptr);
					}
				}
			return(1);

		case	_OUTSET_FRAME	:
			if ( is_styled_outset_frame(
				topx+iptr->Contents.x,topy+iptr->Contents.y,
				iptr->Contents.w,iptr->Contents.h, 
				iptr->Contents.style ) != 0 ) {
				return(0);
				}
			if (( iptr->Contents.align != _A_NONE     ) 
			&&  ( iptr->Contents.payload != (char *) 0)) {
				if ((sptr = allocate_string("outset_title")) != (char *) 0) {
					forms_visual_style(
						topx+iptr->Contents.x,
						topy+iptr->Contents.y,
						iptr->Contents.w,
						iptr->Contents.h,
						sptr,check_payload(iptr->Contents.payload),iptr->Contents.size);
					liberate(sptr);
					}
				}
			return(1);

		case	_GROOVE_FRAME	:
			if ( is_styled_groove_frame(
				topx+iptr->Contents.x,topy+iptr->Contents.y,
				iptr->Contents.w,iptr->Contents.h, 
				iptr->Contents.style ) != 0 ) {
				return(0);
				}
			if (( iptr->Contents.align != _A_NONE     ) 
			&&  ( iptr->Contents.payload != (char *) 0)) {
				if ((sptr = allocate_string("groove_title")) != (char *) 0) {
					forms_visual_style(
						topx+iptr->Contents.x,
						topy+iptr->Contents.y,
						iptr->Contents.w,
						iptr->Contents.h,
						sptr,check_payload(iptr->Contents.payload),iptr->Contents.size);
					liberate(sptr);
					}
				}
			return(1);

		case	_RIDGE_FRAME	:
			if ( is_styled_ridge_frame(
				topx+iptr->Contents.x,topy+iptr->Contents.y,
				iptr->Contents.w,iptr->Contents.h, 
				iptr->Contents.style ) != 0  ) {
				return(0);
				}
			if (( iptr->Contents.align != _A_NONE     ) 
			&&  ( iptr->Contents.payload != (char *) 0)) {
				if ((sptr = allocate_string("ridge_title")) != (char *) 0) {
					forms_visual_style(
						topx+iptr->Contents.x,
						topy+iptr->Contents.y,
						iptr->Contents.w,
						iptr->Contents.h,
						sptr,check_payload(iptr->Contents.payload),iptr->Contents.size);
					liberate(sptr);
					}
				}
			return(1);

		case	_EDIT_FRAME	:
			styled_edit_frame(
				topx+iptr->Contents.x,topy+iptr->Contents.y,
				iptr->Contents.w,iptr->Contents.h, 
				iptr->Contents.style );
			return(1);

		case	_WINDOW_FRAME	:
			styled_visual_window( 	topx+iptr->Contents.x,topy+iptr->Contents.y,
					iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,check_payload(iptr->Contents.payload),iptr->Contents.size,
				((iptr->Contents.align&_A_SHADOW)| 
				((iptr->Contents.align&_A_BOLD)   ? _WINDOW_EXIT_BUTTON : 0 ) | 
				((iptr->Contents.align&_A_LINE)   ? _WINDOW_HELP_BUTTON : 0 ) |
				( fptr->formflags & _MULTILINGUAL ? _WINDOW_LANG_BUTTON : 0 ) |
				( fptr->resizeauto                ? _WINDOW_MAXIMIZE    : 0 ) )
				);
			return(1);

		case	_TAB_FRAME	:
			if ( iptr->Contents.page == fptr->page_number )
				focus = _VISUAL_FOCUS;
			if ( iptr->Contents.align & 1 )
				focus |= 0x0010;
			if ( iptr->Contents.align & 2 )
				focus |= 0x0020;
			focus |= (iptr->Contents.align & 0x0F00);

			styled_visual_tabpage( topx+iptr->Contents.x,topy+iptr->Contents.y,
					iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,check_payload(iptr->Contents.payload),
					iptr->Contents.size, iptr->Contents.adjust, focus );
			return(1);

		case	_BUTTON_FRAME	:
			styled_visual_button( topx+iptr->Contents.x,topy+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h,
				iptr->Contents.font,fg,bg,check_payload(iptr->Contents.payload),iptr->Contents.size,
				((iptr->Contents.align&1?_VISUAL_IMAGE:0) |
				 (iptr->Contents.align&_A_BOLD?_A_BOLD:0) |
				 (iptr->Contents.align&_A_LINE?_A_LINE:0) |
				 (iptr->Contents.align&_A_SHADOW?_A_SHADOW:0) |
				 (iptr->Contents.align&2?_INHIBIT_FRAME:0)));
			return(1);

		case	_SCROLL_FRAME	:
			styled_visual_scroll( 
				topx+iptr->Contents.x,topy+iptr->Contents.y,
				iptr->Contents.w,iptr->Contents.h,
				iptr->Contents.font,fg,bg,
				10,40,100,iptr->Contents.align);
			return(1);

		case	_CHECK_FRAME	:
			styled_visual_check( topx+iptr->Contents.x,topy+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,fg,bg,check_payload(iptr->Contents.payload),iptr->Contents.size,0 );
			return(1);

		case	_SWITCH_FRAME 	:
			styled_visual_switch( topx+iptr->Contents.x,topy+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h,
				iptr->Contents.font,fg,bg,check_payload(iptr->Contents.payload),iptr->Contents.size,
				((iptr->Contents.align & 0x0F00)| ((iptr->Contents.align & 0x000F) << 4)) );
			return(1);

		case	_RADIO_FRAME 	:
			styled_visual_radio( topx+iptr->Contents.x,topy+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h,
				iptr->Contents.font,fg,bg,check_payload(iptr->Contents.payload),iptr->Contents.size,0,0 );
			return(1);

		case	_PROGRESS_FRAME	:
			styled_visual_progress( topx+iptr->Contents.x,topy+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,fg,bg,100,50,iptr->Contents.align);
			return(1);

		case	_SELECT_FRAME 	:
			styled_visual_select( 
				topx+iptr->Contents.x,	topy+iptr->Contents.y,
				iptr->Contents.w,iptr->Contents.h,
				iptr->Contents.font,fg,bg,
				check_payload(iptr->Contents.payload),iptr->Contents.size,
				&dummy,((iptr->Contents.align&7)<< 8));
			return(1);

		case	_FORM_FRAME	:
			styled_visual_table( topx+iptr->Contents.x,topy+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h,
						iptr->Contents.font,fg,bg,
						check_payload(iptr->Contents.payload),
						visual_table_testdata(iptr),
						(iptr->Contents.align 
						|(iptr->Contents.format ? 0x4000 : 0)
						|(iptr->Contents.special? 0x2000 : 0)
						), 
						iptr->Contents.format );
			return(1);
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
		if ( Context.usestyle ) {

			/* Detect explicite widget style */
			/* ----------------------------- */
			if ( method_is_valid( iptr->Contents.stylesheet ) )  {

				/* Handle explicite widget style */
				/* ----------------------------- */
				if ( explicite_Styled_Widget( fptr, iptr ) )
					return;

				}

			/* Detect implicite widget style */
			/* ----------------------------- */
			if ( implicite_Styled_Widget( fptr, iptr ) )
				return;
			}

		/* Handle fallback pixel drawn widget */
		/* ---------------------------------- */
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_LINE_FRAME 	:
				if (( iptr->Contents.w > 0 ) && ( iptr->Contents.h > 0))
					drawline(
					 	Context.DeskTop.x+iptr->Contents.x,
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
				if ((iptr->Contents.align & 0x000F) != _VISUAL_FRAME) 
				{
					draw_button(
						Context.DeskTop.x,
						Context.DeskTop.y,
						iptr,0 );
				}
				else if ( Context.showframe )
				{
					draw_class_image(
						Context.DeskTop.x,
						Context.DeskTop.y,
						iptr,0 );
				}
				else
				{
					draw_button(
						Context.DeskTop.x,
						Context.DeskTop.y,
						iptr,0 );
				}
				break;

			case	_IMAGE_FRAME 	:
				draw_image(
					Context.DeskTop.x,
					Context.DeskTop.y,
					iptr,_I_HIDE );
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

public	int	FormFileOptions(  struct form_control * fptr, int mode )
{
	switch ( mode ) {
		case	0	: 
			if ( is_form_camera_locked( fptr ) )
				return(0);
			else	return( standard_file_permission(fptr->loadname,XML_EXTENSION) );
		case	1	: return( standard_file_lock(fptr->loadname,XML_EXTENSION) );
		case	2	: return( standard_file_unlock(fptr->loadname,XML_EXTENSION) );
		default		: return(0);
		}
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
		if ( visual_event(1) == _MIMO_UP ) {
			if (!( Context.EditView )) {
				edit_Widget( iptr, iptr->parent );
				FormEditorZoom();
				}
			}
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
			if ( my < Context.DeskTop.y )
				TreeViewScrollUp(1);
			else if ( my > Context.StatusBar.y )
				TreeViewScrollDown(1);
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
			else if ( widget_is_locked( wptr ) )
				return(0);
			Context.lockroll++;
			set_national_payload(wptr,fptr->natlang);
			if (!( xptr = copy_widget( wptr ) )) {
				Context.lockroll--;
				return( 0 );
				}
			else	{
				/* printf("moved %s to after %s\r\n",wptr->Contents.name, iptr->Contents.name); */
				remove_widget( fptr, wptr );
				remove_treenode( wptr->treenode );
				wptr = liberate_Widget( wptr );
				fptr->current = iptr;
				add_Widget( fptr, xptr, 0 );
				fptr->current = xptr;
				xptr->parent = fptr;
				use_widget_events(xptr);
				set_tree_focus_node( xptr->treenode );
				get_national_payload(xptr,fptr->natlang);
				Context.lockroll--;
				save_for_rollback(fptr,0,"edit_Widget");
				draw_TreeView();
				}
			return(0);
			}
		else	return(0);
		}
}

public	int	select_TreeForm( struct form_control * fptr )
{
	struct	form_control * xfptr;
	int	mx,my;
	if(!( fptr ))	
		return(0);
	SelectFormWidget(fptr,fptr->current,1);
	select_TreeHost( fptr->host );
	if ( visual_event(2) != _MIMO_LEFT ) {
		if ( visual_event(1) == _MIMO_UP ) {
			xfptr = Context.Form;
			Context.Form = fptr;
			(void) form_parameters( fptr );
			Context.Form = xfptr;
			}
		return(0);
		}
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

		case	_FORM_FRAME	:		
			iptr->Contents.events->xo_event |= _EVENT_IS_FOCUS;
			iptr->Contents.events->mimo = _MIMO_DOWN | _MIMO_SEND_LEFT | _MIMO_SEND_RIGHT;
			break;

		case	_SCROLL_FRAME	:	/* scroll bar buttons	*/
			iptr->Contents.events->xo_event |= _EVENT_IS_FOCUS;
			iptr->Contents.events->mimo = _MIMO_UP | _MIMO_SEND_LEFT | _MIMO_SEND_RIGHT | _MIMO_SEND_WHEEL;
			break;

		case	_CHECK_FRAME	:	/* message alignment	*/
		case	_RADIO_FRAME	:	/* message alignment	*/
		case	_TAB_FRAME	:	/* tab alignment	*/	
		case	_SELECT_FRAME	:	/* button alignment	*/
		case	_EDIT_FRAME	:	
		case	_SWITCH_FRAME	:
		case	_BUTTON_FRAME	:	
			iptr->Contents.events->xo_event |= _EVENT_IS_FOCUS;
			
		case	_WINDOW_FRAME	:	/* window alignment 	*/
			iptr->Contents.events->mimo = _MIMO_UP | _MIMO_SEND_LEFT | _MIMO_SEND_RIGHT;
			break;

		}
	return;
}

private	struct form_item * copy_TemplateWidget( struct form_control * fptr )
{
struct form_item * wptr;
struct form_item * xptr;

	if (!(xptr = Context.TemplateWidget ))
		return(xptr);
	else	{
		Context.TemplateWidget = (struct form_item *) 0;
		if (!(wptr = copy_widget( xptr )))
			return(wptr);
		wptr->Contents.x = Context.Item.x;
		wptr->Contents.y = Context.Item.y;
		add_Widget(fptr,wptr,0);
		return(wptr);
		}
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

	if ((iptr = copy_TemplateWidget(fptr )) != (struct form_item *) 0) {
		if (!( iptr->Contents.name ))
			iptr->Contents.name = automatic_name(iptr->number);
		show_item_info(fptr->current);
		}
	else if (( iptr = allocate_Widget(fptr)) != (struct form_item *) 0) {
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
	int	sw;
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
	if (!( sw = resolve_style_height( "pagebutton" )))
		pptr->Contents.ylimit = (fh+8);
	else	pptr->Contents.ylimit = sw;

	if (!( sw = resolve_style_width( "pagebutton" ))) {
		pptr->Contents.xlimit = (fw * 2);
		pptr->Contents.xlimit += pixel_payload_size( pptr );
		}
	else	pptr->Contents.xlimit = sw;

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
	struct	form_control * fptr;
	if ( iptr->Contents.radio )
		return;
	else if (!( fptr = iptr->parent ))
		return;
	else 	iptr->Contents.radiogroup = ++fptr->radiogroup;

	for ( i=1; iptr != (struct form_item *) 0; iptr = iptr->next ) {
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_RADIO_FRAME	:
				if ((!( iptr->Contents.radio ))
				&&  ( string_compare( iptr->Contents.name, name ) )) {
					iptr->Contents.radio = i++;
					iptr->Contents.radiogroup = fptr->radiogroup;
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
		fptr->radiogroup=0,
		fptr->radioshow=0,
		fptr->pages=0, 
		fptr->focus=0,iptr=fptr->first; 
		iptr != (struct form_item *) 0; 
		iptr = iptr->next ) {
		iptr->Contents.radio = 
		iptr->Contents.radiogroup = 0;
		}

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
					if (( iptr->Contents.datatype  == _WIDGET_CLASS   )
					||  ( iptr->Contents.datatype  == _WIDGET_POINTER ))
						fptr->objects++;

					/* Button / Check / Radio Take Focus */
					/* --------------------------------- */
					if (( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )
					||  ( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS     ))
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
				
				if (( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )
				||  ( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS     ))
					iptr->Contents.focus = ++fptr->focus;
				else	iptr->Contents.focus = 0;
				continue;

			case	_TAB_FRAME	:
				/* Tab Frames take focus and Change Page */
				/* ------------------------------------- */
				iptr->Contents.page  = ++fptr->pages;
				if (( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )
				||  ( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS     ))
					iptr->Contents.focus = ++fptr->focus;
				else	iptr->Contents.focus = 0;
				iptr->Contents.adjust= offset;
				offset = calculate_page_tab( offset, iptr );
				tabptr   = iptr;
				continue;

			case	_SELECT_FRAME	:
				/* Select can Take Focus */
				/* --------------------- */
				if (( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )
				||  ( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS     ))
					iptr->Contents.focus = ++fptr->focus;
				else	iptr->Contents.focus = 0;
				calculate_select( iptr );
				iptr->Contents.page  = 
					visual_page_number( tabptr, iptr );
				continue;

			case	_RADIO_FRAME	:
				if (!( iptr->Contents.radio )) 
					calculate_radio( iptr, iptr->Contents.name );

			case	_EDIT_FRAME	:
				/* Constant Edit Frames do not take Focus */
				/* -------------------------------------- */
				if ((iptr->Contents.style & _FRAME_TYPE) != _RADIO_FRAME ) {
					if ( iptr->Contents.datatype == _WIDGET_KONSTANT ) {
						iptr->Contents.focus = 0;
						iptr->Contents.page  = 
							visual_page_number( tabptr, iptr );
						continue;
						}
					}

			case	_BUTTON_FRAME	:
			case	_CHECK_FRAME	:
			case	_SWITCH_FRAME	:
			case	_GRAPH_FRAME	:
				/* Button / Check / Radio Take Focus */
				/* --------------------------------- */
				if (( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )
				||  ( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS     ))
					iptr->Contents.focus = ++fptr->focus;
				else	iptr->Contents.focus = 0;
				iptr->Contents.page  = 
					visual_page_number( tabptr, iptr );
				continue;

			default			:
				/* All others : No Focus */
				/* --------------------- */
				if (( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )
				||  ( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS     ))
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

#ifdef	NEWSING
/*	-------------------------------------	*/
/*	b a s e f o r m _ D i m e n s i o n s 	*/
/*	-------------------------------------	*/
public	void	form_Dimensions(  struct window_control * wptr, struct form_control   * fptr);
private	void	baseform_Dimensions( struct window_control * wptr, char * baseform )
{
	struct	form_control * fptr;

	if (!( fptr = locate_form_control( baseform ) ))
		return;
	else	form_Dimensions( wptr, fptr );
	return;
}
#endif

	
/*	-----------------------------	*/
/*	f o r m _ D i m e n s i o n s 	*/
/*	-----------------------------	*/
public	void	form_Dimensions(  struct window_control * wptr, struct form_control   * fptr)
{
	int	fh;
	struct form_item * optr;

	wptr->x = -1; wptr->y = -1;
	wptr->w = 0; wptr->h = 0;

#ifdef	NEWSING	
	if ( method_is_valid( fptr->extends ) ) 
		baseform_Dimensions( wptr, fptr->extends );
	
#endif
	for (	optr=fptr->first;
		optr != (struct form_item *) 0;
		optr = optr->next ) {

		if ((optr->Contents.style & _FRAME_TYPE) == _LINE_FRAME )
			continue;

		else if ( is_file_Widget( optr ) )
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


public	void	window_Dimensions( 
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

		else if ((optr->Contents.events->xo_show & _EVENT_IS_COND ))
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


private	int	page_Dimensions( struct window_control * wptr, struct form_control * fptr)
{
	int	dpi;
	if (!( wptr ))
		return(0);

	wptr->x = wptr->y = wptr->w = wptr->h = 0;

	if (!( fptr ))
		return(0);

	switch ( fptr->formflags & _FORM_TYPE_FLAGS ) {
		case	_FORM_TYPE_DIALOG	:
		case	_FORM_TYPE_EVENT 	:
			return(0);

		case	_FORM_TYPE_QUALITY	:
			if ( Context.Form->printout.Layout != 1 ) {
				collect_paper_dimensions( 
					&wptr->h,&wptr->w, 
					75,
					(Context.Form->printout.PaperType-1) );
				}
			else	{
				collect_paper_dimensions( 
					&wptr->w,&wptr->h, 
					75,
					(Context.Form->printout.PaperType-1) );
				}
			break;

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
	char	*		q=(char *) 0;
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
		switch ( fptr->formflags & _FORM_TYPE_FLAGS ) {
			case	_FORM_TYPE_QUALITY	:
				q = "HQ"; break;
			case	_FORM_TYPE_PAGE   	:
				q = "DD"; break;
			default				:
				return;
			}
		if ((tptr = selection_item(Context.Form->printout.PaperType-1,sptr)) != (char *) 0) {
			sprintf(message,"%s(%u) %s %u x %u pts",q,page_resolution(),tptr,Paper.w,Paper.h);
			liberate( tptr );
			}
		else	sprintf(message,"%s(%u) Paper %u x %u pts",q,page_resolution(),Paper.w,Paper.h);

		if (( FormWindow.w > Paper.w ) || ( FormWindow.h > Paper.h ))
			failure_message(message,3);
		else 	status_message(message,3);
		return;
		}
}

private	void	makeformfit( int atx,int aty, int nbx, int nby ,struct	buffer_control * buffer) 
{
	visual_bestfit( atx,aty,nbx,nby,buffer->value,buffer->width,buffer->height);
	return;
}

#ifdef	NEWSING
private	void	draw_form_members( struct form_control * fptr, int refresh );
private	void	draw_baseform_members( char * baseform, int refresh )
{
	struct	form_control * fptr;
	if (( fptr = locate_form_control( baseform )) != (struct form_control *) 0 )
		draw_form_members( fptr, refresh );
	return;
}
#endif

private	void	draw_form_members( struct form_control * fptr, int refresh )
{
	struct form_item * iptr;
	/* ------------------------- */
	/* Draw Desktop member Items */
	/* ------------------------- */
#ifdef	NEWSING
	if ( method_is_valid( fptr->extends ) ) 
		draw_baseform_members( fptr->extends, refresh );
#endif
	for (iptr=fptr->first; iptr != (struct form_item *) 0; iptr = iptr->next ) 
	{

		/* test for inhibition of conditional display items */
		/* ------------------------------------------------ */
		if (iptr->Contents.events->xo_show & _EVENT_IS_COND ) 
		{
			if (!( refresh ))
				continue;
			else if (!( Context.showall ))
				continue;
		}

		switch ( (iptr->Contents.style & _FRAME_TYPE) ) 
		{

		case	_DATA_FRAME	:
			if (( iptr->Contents.align & 0x000F ) == _VISUAL_FRAME) 
			{
				if (iptr->Contents.events->xo_show & _EVENT_IS_COND )
					if (!( refresh )) 
						continue;
				draw_Widget( fptr,iptr );
				continue;
			}
		case	_CUT_FRAME	:
		case	_MOVE_FRAME	:
			/* image for html request */
			/* ---------------------- */
			if (!( refresh )) continue;

		default			:
			if (iptr->Contents.events->xo_show & _EVENT_IS_COND )
				if (!( refresh )) 
					continue;
			draw_Widget( fptr,iptr );
			if ( Context.gridtype != 2 )
				continue;
			else if ((iptr->Contents.style & _FRAME_TYPE) != _WINDOW_FRAME )
				continue;
			else if (!( refresh ))
				continue;
			else 	
			{
				draw_window_grid(
					Context.DeskTop.x,
					Context.DeskTop.y,
					iptr );
				continue;
			}
		}
	}
	return;
}


public 	void	show_Form(struct form_control * fptr, int refresh )
{
	int	whoops=0;
	int	sy,sx;
	int	hx,hy,tr;
	int	maxcol;
	int	maxrow;
	int	pixelsize=get_pixel_size();
	char *	bptr;
	struct form_item * iptr;
	int	holdtestdata=Context.UseTestData;
	

	if (!( fptr->first ))
		return;

	/* Determine overall Form Window Dimensions and Position */
	/* ----------------------------------------------------- */
	if ( refresh ) 
	{
		form_Dimensions( &FormWindow, fptr  );
	}
	else	
	{
#ifdef	NEWSING
		form_Dimensions( &FormWindow, fptr  );
#else
		window_Dimensions( &FormWindow, fptr  );
#endif
	}

	if ((!( fptr->Buffer.value ))
	||   ( FormWindow.w != fptr->Buffer.width )
	||   ( FormWindow.h != fptr->Buffer.height )) {
		drop_Form_buffer( fptr );

		fptr->Buffer.value = allocate_graphic_storage(
					0,0,
					((fptr->Buffer.width = FormWindow.w)+16),
					((fptr->Buffer.height = FormWindow.h)+16));

		}

	/* Position the Forms Capture Buffer */
	/* --------------------------------- */
	if ( fptr->Buffer.value ) {
		hx = Context.DeskTop.x;
		hy = Context.DeskTop.y;
		Context.DeskTop.x = -FormWindow.x;
		Context.DeskTop.y = -FormWindow.y;
		background_pixel_capture( fptr->Buffer.value );
		filzone(0,0,FormWindow.w,FormWindow.h,0);
		}

	if ( method_is_valid( fptr->stylesheet ) ) {
		load_visual_style(fptr->stylesheet,strlen(fptr->stylesheet));
		whoops = consult_style_trace();
		}
	else	whoops=0;

	/* detect default style classes */
	/* ---------------------------- */
	if ( Context.usestyle ) { detect_default_style(); }

	/* inhibit this for simple image generation */
	/* ---------------------------------------- */
	if (!( refresh ))  { Context.UseTestData = 0; }

	draw_form_members( fptr, refresh );

	/* Restore this now in case of return */
	/* ---------------------------------- */
	Context.UseTestData = holdtestdata;

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


		if (( Context.MakeFormFit )
		&&  (( FormWindow.w > Context.DeskTop.w )
		||   ( FormWindow.h > Context.DeskTop.h )))

			makeformfit(	Context.DeskTop.x,
					Context.DeskTop.y,
					Context.DeskTop.w,
					Context.DeskTop.h,
					&fptr->Buffer);

		else	{
			desktop_Hscroll((int *)0,0);
			desktop_Vscroll((int * )0,0);
			if ((FormWindow.x+maxcol) > Context.DeskTop.w) {
				desktop_Hscroll(
					&fptr->Buffer.x,
					fptr->Buffer.width 
					);
				if ((maxcol = (Context.DeskTop.w - FormWindow.x)) <= 0 )
					return;
				}

			if ((FormWindow.y+maxrow) > Context.DeskTop.h) {
				desktop_Vscroll(
					&fptr->Buffer.y,
					fptr->Buffer.height );
				if ((maxrow = (Context.DeskTop.h - FormWindow.y)) <= 0)
					return;
				}


			sy = fptr->Buffer.y; sx = fptr->Buffer.x; 

			for (tr=0; tr < maxrow; tr++ ) {
	
				if (!( bptr = connect_pixel_row( fptr->Buffer.value, sy+tr )))
					break;
				else	putzone(Context.DeskTop.x+FormWindow.x,
						Context.DeskTop.y+FormWindow.y+tr,
						maxcol,1, (bptr+(sx*pixelsize)) );
	
				}


			draw_desktop_scroll();
			}

		}
	if ( whoops ) {
		style_editor();
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
	int	grid_background=15;
	int	dath;
	int	m;
	int	p;
	int	pas;
	int	atrow;
	int	fh;
	int	fw;
	int	items;
	char *	gptr;
	char *	sptr;
	int	emode=0;
	struct 	form_item * iptr;
	struct	element_style * eptr;

	int	pixelsize=get_pixel_size();
	int	colourmaped=get_pixel_format();

	if (!( fptr ))	return;
		
	/* detect default style classes */
	/* ---------------------------- */
	if ( Context.usestyle ) { detect_default_style(); }

	if ( method_is_valid( fptr->stylesheet ) ) 
	{
		load_visual_style(fptr->stylesheet,strlen(fptr->stylesheet));
	}

	/* prepare form components */
	/* ----------------------- */
	prepare_Form( fptr );

	if ( fptr->display == _EDIT_CLASS ) 
	{

		if ( Context.DeskTop.style != _SCROLL_FRAME ) 
			activate_DeskTop( _SCROLL_FRAME );

		fh = guifontsize(1);	
		fw = (fh & 0x00FF);
		fh >>= 8;	
		fh &= 0x00FF;

		/* Draw Desktop member Items */
		/* ------------------------- */
		if (!( fptr->top )) 
		{
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
			iptr = iptr->next, items++ ) 
		{
			iptr->shatx = 0; iptr->shaty = atrow;
			iptr->shitem = items;
			show_Widget( iptr, 0 );
			atrow += fh;
			if ( atrow >= Context.DeskTop.h )
				break;
		}

		fptr->items = items;

	}

	else	
	{

		if ( Context.DeskTop.style == _SCROLL_FRAME ) 
			activate_DeskTop( _OUTSET_FRAME );

		if ( refresh ) 
		{

			hide();
#ifdef	ABAL32A
			if (method_is_valid((sptr = fptr->clearscreen))) {
				if ( *sptr == '.' )
					sptr++;
				if (( eptr = resolve_style_class( sptr )) != (struct element_style *) 0) {
					emode = style_inhibit_position_home( eptr );					
					visual_styled_element( 
					 	Context.DeskTop.x, 
						Context.DeskTop.y, 
						Context.DeskTop.w,
						Context.DeskTop.h,
						sptr, " ",0);
					style_permit_position_home( eptr, emode );					
					}
				grid_background=0;
				}
			else	{
				if ( colourmaped )
					grid_background=15;
				else	grid_background=0xFF;		
				}
#else
			if ( colourmaped )
				grid_background=15;
			else	grid_background=0xFF;		
#endif

			/* Draw Desktop Grid if Active */
			/* --------------------------- */	
			if ( Context.gridlockw != 0 ) 
			{

				if (!( Context.gridbuffer )) 
					Context.gridbuffer = allocate( (Context.DeskTop.w * 2 * get_pixel_size()) );

				/* preparation of horizontal row grid */
				/* ---------------------------------- */
				if ((gptr = Context.gridbuffer) != (char *) 0) 
				{
					for ( 	pas=0;
						pas < Context.DeskTop.w;
						pas++ ) 
					{

						if ( colourmaped ) 
						{
							if (!( (pas+1) % Context.gridlockw ))
								dath = standard_black+1;
							else	dath = grid_background;
							*(gptr+pas) = dath;
						}
						else
						{
							if (!( (pas+1) % Context.gridlockw ))
								dath = 64;
							else	dath = grid_background;
							m = (pas*pixelsize);							
							for (p=0; p < pixelsize; p++ )
								*(gptr+m+p)=dath;
						}
					}
				}
	
				/* Horizontal Lines */
				/* ---------------- */
				for ( 	pas=0;
					pas < Context.DeskTop.h;
					pas++ ) 
				{
					if (!( (pas+1) % Context.gridlockh )) 
					{
						filzone(Context.DeskTop.x+1,Context.DeskTop.y+pas,
							Context.DeskTop.w-2,1,standard_black+1);
					}
					else if (!( gptr ))
						continue;
					else if (!( grid_background )) 
					{
						mixzone(Context.DeskTop.x+1,Context.DeskTop.y+pas,
							Context.DeskTop.w-2,1,gptr );
					}
					else
					{
						putzone(Context.DeskTop.x+1,Context.DeskTop.y+pas,
							Context.DeskTop.w-2,1,gptr );
					}
				}
			}
		}

		show_Form( fptr,refresh );

		if ( refresh ) 
		{
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
	if ( refresh ) 
	{
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
	if ((pptr->Contents.page != 0) && ( pptr->Contents.page != mptr->Contents.page))
		return(0);

	/* Ensure different widget */
	/* ----------------------- */
	if ( pptr->number == mptr->number )
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

private	void	apply_cut_align( struct form_item * cptr, struct form_control * fptr)
{
	struct form_item * mptr;

	for (	mptr=fptr->first;
		mptr != (struct form_item *) 0;
		mptr = mptr->next ) {

		if (!( is_widget_member( cptr, mptr ) ))
			continue;

		switch ( cptr->Contents.align & 7 ) {
			case	_A_NONE	 :
				continue;
			case	_A_LEFT	 :
				mptr->Contents.x = cptr->Contents.x;
				continue;
			case	_A_RIGHT :
				mptr->Contents.x = cptr->Contents.x+(cptr->Contents.w - mptr->Contents.w);
				continue;
			case	_A_CENTER	:
				mptr->Contents.x = cptr->Contents.x+((cptr->Contents.w - mptr->Contents.w)/2);
				continue;
			case	_A_JUSTIFY	:
				mptr->Contents.x = cptr->Contents.x;
				mptr->Contents.w = cptr->Contents.w;
				continue;
			}
		}
	return;
}

private	void	define_widget_members( struct form_item * iptr, int mode )
{
	struct 	form_item * mptr;
	struct	form_control * fptr;

	if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;

	/* if ( mode ) { printf("define widget collection : page %u{ \r\n",iptr->Contents.page); } */

	/* Adjust all others by same amount */
	/* -------------------------------- */
	for (	mptr=fptr->first;
		mptr != (struct form_item *) 0;
		mptr = mptr->next ) {
		if (!( is_widget_member( iptr, mptr ) ))
			mptr->ismember = 0;
		else	{
			mptr->ismember = mode;
			/* if ( mode ) { printf("\t%s : %u \r\n",mptr->Contents.name,mptr->Contents.page); } */
			}
		}
	/* if ( mode ) { printf("\t} \r\n"); } */
	return;
}

private	void	move_widget_members(
		struct form_item * iptr,
		int	xadjust,
		int	yadjust )
{
	struct form_item * mptr;

	struct	form_control * fptr;

	if (!( fptr = iptr->parent ))
		return;

	/* Adjust all others by same amount */
	/* -------------------------------- */
	for (	mptr=fptr->first;
		mptr != (struct form_item *) 0;
		mptr = mptr->next ) {

		if (!( mptr->ismember ))
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

	if ( widget_is_locked( iptr ) )
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
			define_widget_members(iptr,1);
			move_widget_members( iptr, xadjust, yadjust );
			define_widget_members(iptr,0);
			iptr->Contents.x = wptr->x;
			iptr->Contents.y = wptr->y;
			break;

		case	_WINDOW_FRAME	:

			if ( Context.lockon ) {
				define_widget_members(iptr,1);
				move_widget_members( iptr, xadjust, yadjust );
				define_widget_members(iptr,0);
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
	if ( widget_is_locked( iptr ) ) 
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

private	void	remove_widget(	struct form_control * fptr, 	struct form_item * iptr )
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
		if (!( widget_is_locked( iptr ) )) {
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


private	void	release_widget_cursor()
{
	if ( Context.WidgetCursor ) {
		/* printf("release widget_cursor at %u,%u \r\n",Context.WidgetCursorX,Context.WidgetCursorY); */
		visual_buffer_put(Context.WidgetCursor,Context.WidgetCursorX,Context.WidgetCursorY);
		visual_drop(Context.WidgetCursor);
		Context.WidgetCursor = (void*)0;
		}
	return;
}

private	void	apply_widget_cursor_style( int x, int y, int w, int h, char * sptr, char * mptr, int mlen )
{
	if ( Context.WidgetCursor ) {
		visual_drop(Context.WidgetCursor);
		Context.WidgetCursor = (void*)0;
		}
	if (( Context.WidgetCursor = visual_buffer(x,y,w,h)) != (void *) 0) {
		visual_buffer_get(Context.WidgetCursor,(Context.WidgetCursorX=x),(Context.WidgetCursorY=y));
		}
	/* printf("display widget_cursor at %u,%u \r\n",Context.WidgetCursorX,Context.WidgetCursorY); */
	forms_visual_style( x,y,w,h,sptr, mptr, mlen );
	return;
}

private	int	active_widget_cursor( struct form_item * iptr )
{
	struct	form_control * fptr;
	char		     * wcs;
	if ( Context.MakeFormFit )
		return(0);
	else if (!( iptr ))
		return(0);
	else if (!( fptr = iptr->parent ))
		return(0);
	else if ((iptr->Contents.page) && ( iptr->Contents.page != fptr->page_number))
		return(0);
	else if ( iptr->Contents.x < fptr->Buffer.x )
		return(0);
	else if ( iptr->Contents.y < fptr->Buffer.y )
		return(0);
	else if ( (iptr->Contents.x+iptr->Contents.w) > (fptr->Buffer.x+Context.DeskTop.w)) 
		return(0);
	else if ( (iptr->Contents.y+iptr->Contents.h) > (fptr->Buffer.y+Context.DeskTop.h))
		return(0);

	if (( iptr->Contents.w > 0 ) &&  ( iptr->Contents.h > 0 )) {

		if ( widget_is_locked( iptr ) ) {
			if (!( locked_cursor_style ))
				if (!( locked_cursor_style = allocate_string("sing/locked_cursor_frame") ))
					return(0);
			wcs = locked_cursor_style;
			}
		else	{
			if (!( widget_cursor_style ))
				if (!( widget_cursor_style = allocate_string("sing/widget_cursor_frame") ))
					return(0);
			wcs = widget_cursor_style;
			}

		if ((iptr->Contents.style & _FRAME_TYPE) != _LINE_FRAME ) {
			apply_widget_cursor_style(
				(Context.DeskTop.x+iptr->Contents.x)-fptr->Buffer.x,
				(Context.DeskTop.y+iptr->Contents.y)-fptr->Buffer.y,
				iptr->Contents.w,
				iptr->Contents.h, 
				wcs ," ",0);
			}
		else	{
			apply_widget_cursor_style(
				(Context.DeskTop.x+iptr->Contents.x)-fptr->Buffer.x,
				(Context.DeskTop.y+iptr->Contents.y)-fptr->Buffer.y,
				iptr->Contents.w-iptr->Contents.x,
				iptr->Contents.h-iptr->Contents.y, 
				wcs ," ",0);
			}
		return(1);
		}
	else	{
		return(0);
		}
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
	save_event_control( handle, iptr->Contents.events );
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
	fptr->activetool     = Context.style;
	return;
}

private	void	set_context_defaults( struct form_control * fptr )
{
	set_context_gridlock(fptr->gridlock);
	set_context_gridsize(fptr->gridsize);
	configure_gridlock(Context.gridtype);
	Context.Item.font = fptr->font;
	Context.foreground = fptr->foreground;
	Context.background = fptr->background;
	Context.thickness  = fptr->thickness;
	Context.usingtool  = fptr->activetool;
	Context.style	   = fptr->activetool;
	return;
}

public 	int	save_Form( struct form_control * fptr,int automatic, char * checkname )
{
	struct form_item * iptr;
	struct	forms_method * mptr;
	char		 * dtdname=(char *) 0;
	FILE		 * h;
	int	i;
	int	v;
	int	o;

	while  ( is_form_camera_locked( fptr ) ) {
		if ( report_accept_error( "parent project of form is locked", fptr->loadname ) == 27 )
			return(0);
		}
	
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

	if (( checkname ) && (!( strcmp( fptr->loadname, checkname ) ))) {
		name_conflict_failure( fptr->loadname );
		return(0);
		}

	if ( detect_extension( fptr->loadname, XML_EXTENSION ) ) {
		if (!(dtdname = confgetenv("SINGXML")))
			dtdname = "sing.dtd";
		xml_put_Form( fptr->loadname, fptr, "sing.dtd" );
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
				put_string( h, fptr->printout.TopMargin );
				put_word( h, fptr->printout.BottomMargin );
				put_string( h, fptr->printout.LeftMargin );
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
			put_word(h,fptr->activetool );


			put_string(h,fptr->prodname);

			v = (fptr->language | (Context.imageformat << 8));

			put_word(h,v);
			put_word(h,fptr->activetool/*Context.style*/);
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
		if ((dtdname = confgetenv("SINGXML")) != (char *) 0) { 
			xml_put_Form( fptr->loadname, fptr, dtdname ); 
			}

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
	if ((iptr->Contents.style & _FRAME_TYPE) == _LINE_FRAME)
		return;
	if (!(iptr->Contents.payload = iptr->Contents.messages[i])) 
	{
		iptr->Contents.size = 0;
	}
	else	
	{
		iptr->Contents.messages[i] = (char *) 0;
		iptr->Contents.size = strlen( iptr->Contents.payload );
	}	
	if ((iptr->Contents.hint = iptr->Contents.hmessages[i]) != (char *) 0)
		iptr->Contents.hmessages[i] = (char *) 0;
}

public 	void	set_national_payload(struct form_item * iptr, int i )
{
	if ((iptr->Contents.style & _FRAME_TYPE) == _LINE_FRAME)
		return;
	iptr->Contents.messages[i] = iptr->Contents.payload;
	iptr->Contents.payload     = (char *) 0;
	iptr->Contents.hmessages[i] = iptr->Contents.hint;
	iptr->Contents.hint        = (char *) 0;
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
			reset_event_control(iptr->Contents.events,t);
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

			load_event_control( handle, iptr->Contents.events );

			if (!( version & _EXTENDED_EVENTS ))
				reset_extended_events( iptr->Contents.events, iptr->Contents.style );

			if ( SystemD & 1 ) {

				iptr->Contents.events->xo_show &= _FUNCTION_NOT_FOCUS;
				iptr->Contents.events->xo_hide &= _FUNCTION_NOT_FOCUS;

				}

			if ( version & _DOCUMENTATION ) {
				iptr->doctool  = get_word( handle );
				if (!( version & _INTERNATIONAL )) {
					iptr->document[0]= get_string( handle );
					if (!( version & _METHOD_FILE )) {
						iptr->document[0] = normalise_method_text( iptr->document[0] );
						normalise_event_methods( iptr->Contents.events );
						}
					}
				else	{
					for (i=0; i < MAXNATLANG; i++ ) {
						iptr->document[i]= get_string( handle );
						if (!( version & _METHOD_FILE )) {
							iptr->document[i] = normalise_method_text( iptr->document[i] );
							normalise_event_methods( iptr->Contents.events );
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

					macro_get_string( h, fptr->printout.TopMargin );
					macro_get_word( h, fptr->printout.BottomMargin );
					macro_get_string( h, fptr->printout.LeftMargin );
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
				fptr->activetool     = Context.usingtool = get_word(h);

				fptr->prodname = get_string(h);

				v		    = get_word(h);
				fptr->language	    = (v & 0x00FF);
				Context.language    = (v & 0x00FF);
				Context.imageformat = (v >> 8);
				fptr->activetool = Context.style       = get_word(h);

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
			if (!( widget_is_locked( iptr ) )) {
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
		if (( inw != iptr->Contents.w )
		||  ( inh != iptr->Contents.h )) {
			form_is_outofdate( fptr );
			save_for_rollback( fptr,0,"StretchFormWidget" );
			}
		fptr->active = (struct form_item *) 0;
		draw_DeskTop();
		}
	else	fptr->active = (struct form_item *) 0;
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

		/* --------------------------------- */
		/* define widget specific collection */
		/* --------------------------------- */
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_WINDOW_FRAME	:
				if (!( Context.lockon ))
					break;
			case	_CUT_FRAME	:
				define_widget_members( iptr, 1 );
			}

		do	{
			while ( visual_getch() != 256 );
			if (!( widget_is_locked( iptr ) )) {
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

		/* ----------------------------------- */
		/* undefine widget specific collection */
		/* ----------------------------------- */
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_WINDOW_FRAME	:
				if (!( Context.lockon ))
					break;
			case	_CUT_FRAME	:
				define_widget_members( iptr, 0 );
			}

		if (( inx != iptr->Contents.x )
		||  ( iny != iptr->Contents.y )) {
			form_is_outofdate( fptr );
			save_for_rollback( fptr,0,"MoveFormWidget" );
			}
		fptr->active = (struct form_item *) 0;
		draw_DeskTop();
		}
	else	fptr->active = (struct form_item *) 0;
	return(256);
}

private	int	SelectFormWidget( struct form_control * fptr, struct form_item * iptr, int treeviewcaller )
{
	hide_form_selection(fptr,0);
	fptr->current = fptr->active = iptr;
	/* detect and activate VisualTabPage */
	if ( iptr )
		if (( iptr->Contents.style & _FRAME_TYPE ) == _TAB_FRAME ) 
			fptr->page_number = iptr->Contents.page;
	show_form_selection(fptr,_TREE_FOCUS);
	if ( iptr ) {
		if (!( treeviewcaller )) {
			if ( Context.Item.style == _SIZE_FRAME )
				return( StretchFormWidget( fptr, iptr ) );
			else	return( MoveFormWidget( fptr, iptr ) );
			}
		fptr->active = (struct form_item *) 0;
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
			if ( Context.Item.style != _SIZE_FRAME ) {
				/* request to move tab page by tab button */
				if (( x >= (iptr->Contents.x+iptr->Contents.adjust))
				&&  ( y >=  iptr->Contents.y)
				&&  ( x <= (iptr->Contents.x+iptr->Contents.adjust+iptr->Contents.xlimit))
				&&  ( y <= (iptr->Contents.y+iptr->Contents.ylimit))) {
					return( SelectFormWidget(fptr, iptr, 0 ) );
					}
				else	continue;
				}
			else if ( Context.ResizeBy /* RightButtonStretch */ ) {
				/* request to stretch with right mouse button */
				if (( x >= (iptr->Contents.x+iptr->Contents.adjust))
				&&  ( y >=  iptr->Contents.y)
				&&  ( x <= (iptr->Contents.x+iptr->Contents.adjust+iptr->Contents.xlimit))
				&&  ( y <= (iptr->Contents.y+iptr->Contents.ylimit))) {
					return( SelectFormWidget(fptr, iptr, 0 ) );
					}
				else	continue;
				}
			else if (!( inside_widget_cursor( iptr, x, y ) ))
				continue;
			else if ( iptr->Contents.page != fptr->page_number ) 
				continue;
			else	return( SelectFormWidget(fptr,iptr,0) );
			}
		if ((!( fptr->page_number   ))
		||  (!( iptr->Contents.page ))
		||  ( fptr->page_number == iptr->Contents.page )) 
		{
			if (( iptr->Contents.style & _FRAME_TYPE ) == _LINE_FRAME ) 
			{
				if (( Context.Item.style != _SIZE_FRAME ) || ( RightButtonStretch )) 
				{
					if ((x == iptr->Contents.x )
					&&  (y == iptr->Contents.y )) 
					{
						return( SelectFormWidget(fptr,iptr,0) );
					}
					else if ((x == iptr->Contents.w )
					     &&  (y == iptr->Contents.h )) 
					{
						return( SelectFormWidget(fptr,iptr,0) );
					}
				}
				else if (!( inside_line_cursor( iptr, x, y ) ))
					continue;
				else	return( SelectFormWidget(fptr,iptr,0) );
			}
			else if (( iptr->Contents.style & _FRAME_TYPE ) == _SELECT_FRAME ) 
			{
				if (( Context.Item.style != _SIZE_FRAME ) || ( RightButtonStretch )) 
				{
					if (( x >= (iptr->Contents.x+iptr->Contents.adjust))
					&&  ( y >=  iptr->Contents.y)
					&&  ( x <= (iptr->Contents.x+iptr->Contents.adjust+iptr->Contents.xlimit))
					&&  ( y <= (iptr->Contents.y+iptr->Contents.ylimit))) 
					{
						return( SelectFormWidget(fptr, iptr,0 ) );
					}
					else	continue;
				}
				else if (!( inside_widget_cursor( iptr, x, y ) ))
					continue;
				else	return( SelectFormWidget(fptr,iptr,0) );
			}
			else	
			{
				if (!( inside_widget( iptr, x, y ) ))
					continue;
				else	return( SelectFormWidget(fptr,iptr,0) );
			}
		}
	}
	return(0);
}

private	int	inside_zone(int x, int y, int zx, int zy, int zw, int zh )
{
	if ( x < zx ) 		return(0);
	else if ( y < zy ) 	return(0);
	else if ( x > zx+zw )	return(0);
	else if ( y > zy+zh )	return(0);
	else			return(1);
}

private	int	outside_zone(int x, int y, int zx, int zy, int zw, int zh )
{
	if ( x < zx ) 		return(1);
	else if ( y < zy ) 	return(1);
	else if ( x > zx+zw )	return(1);
	else if ( y > zy+zh )	return(1);
	else			return(0);
}

private	int	inside_widget( struct form_item * iptr, int x, int y )
{
	if ( Context.showframe )
		return( inside_zone( x, y, iptr->Contents.x, iptr->Contents.y, iptr->Contents.w, iptr->Contents.h ) );
	else if ((iptr->Contents.style & _FRAME_TYPE) != _DATA_FRAME) 
		return( inside_zone( x, y, iptr->Contents.x, iptr->Contents.y, iptr->Contents.w, iptr->Contents.h ) );
	else if ((iptr->Contents.align & 0x000F) != _VISUAL_FRAME) 
		return( inside_zone( x, y, iptr->Contents.x, iptr->Contents.y, iptr->Contents.w, iptr->Contents.h ) );
	else	return( inside_zone( x, y, iptr->Contents.x, iptr->Contents.y, 20, 30 ) );
}

private	int	inside_widget_item_cursor( struct form_item * iptr, int x, int y )
{
	if (!( inside_zone(x,y, iptr->Contents.x, iptr->Contents.y, iptr->Contents.w, iptr->Contents.h ) ))
		return(0);
	else if (!( outside_zone(x,y, iptr->Contents.x+6, iptr->Contents.y+6, iptr->Contents.w-12, iptr->Contents.h-12 ) ))
		return(0);
	else	return(1);
}

private	int	inside_widget_form_cursor( struct form_item * iptr, int x, int y )
{
	if (!( inside_zone(x,y, iptr->Contents.x, iptr->Contents.y, 20, 30 ) ))
		return(0);
	else if (!( outside_zone(x,y, iptr->Contents.x+6, iptr->Contents.y+6, 20-12, 30-12 ) ))
		return(0);
	else	return(1);
}

private	int	inside_widget_cursor( struct form_item * iptr, int x, int y )
{
	if ( Context.showframe )
		return( inside_widget_item_cursor( iptr, x, y ) );
	else if ((iptr->Contents.style & _FRAME_TYPE) != _DATA_FRAME) 
		return( inside_widget_item_cursor( iptr, x, y ) );
	else if ((iptr->Contents.align & 0x000F) != _VISUAL_FRAME) 
		return( inside_widget_item_cursor( iptr, x, y ) );
	else	return( inside_widget_form_cursor( iptr, x, y ) );
}

private	int	inside_line_cursor( struct form_item * iptr, int x, int y )
{
	int	w;
	int	h;
	if (!( iptr ))
		return(0);
	else	{
		w = iptr->Contents.w - iptr->Contents.x;
		h = iptr->Contents.h - iptr->Contents.y;
		}
	if (!( inside_zone(x,y, iptr->Contents.x, iptr->Contents.y, w, h ) ))
		return(0);
	else if (!( outside_zone(x,y, iptr->Contents.x+6, iptr->Contents.y+6, w-12, h-12 ) ))
		return(0);
	else	return(1);
}

private	int	widget_alt_shift( int event, struct form_control * fptr )
{
	int	hx,hy;
	struct	form_item * iptr;
	if (( iptr = fptr->current ) != (struct form_item *) 0) {
		hx = iptr->Contents.x;
		hy = iptr->Contents.y;
		switch ( event ) {
			case	_ALT_UP		:
				if ((iptr->Contents.style & _FRAME_TYPE) == _LINE_FRAME ) {
					if (( iptr->Contents.y > 0 ) 
					&&  ( iptr->Contents.h > 0 )){
						iptr->Contents.y--;
						iptr->Contents.h--;
						break;
						}
					else	return(256);
					}
				else 	{
					if ( iptr->Contents.y > 0 ) {
						iptr->Contents.y--;
						break;
						}
					else	return(256);
					}

			case	_ALT_DOWN	:
				if ((iptr->Contents.style & _FRAME_TYPE) == _LINE_FRAME ) {
					iptr->Contents.y++;
					iptr->Contents.h++;
					}
				else	iptr->Contents.y++;
				break;

			case	_ALT_LEFT	:
				if ((iptr->Contents.style & _FRAME_TYPE) == _LINE_FRAME ) {
					if (( iptr->Contents.x > 0 ) 
					&&  ( iptr->Contents.w > 0 )){
						iptr->Contents.x--;
						iptr->Contents.w--;
						break;
						}
					else	return(256);
					}
				else	{
					if ( iptr->Contents.x > 0 ) {
						iptr->Contents.x--;
						break;
						}
					else	return(256);
					}

			case	_ALT_RIGHT	:
				if ((iptr->Contents.style & _FRAME_TYPE) == _LINE_FRAME ) {
					iptr->Contents.x++;
					iptr->Contents.w++;
					}
				else 	iptr->Contents.x++;
				break;
			default			:
				return(256);
			}
		if ((hx != iptr->Contents.x)
		||  (hy != iptr->Contents.y)) {
			form_is_outofdate( fptr );
			save_for_rollback( fptr,0,"widget_alt_shift" );
			draw_console();
			return(257);
			}
		}
	return(256);
}

public	int	is_FormEvent(struct form_control * fptr, int x, int y)
{
	int	t;
	int	b;
	struct	form_item * iptr;
	struct window_control Window;

	if ( fptr->display == _EDIT_CLASS )
		return( use_FormEvent( fptr, x, y ) );
		
	if (!( Context.Item.style ))
		show_mouse_position(x,y);

	if ( Context.usingtool ) {

		x += fptr->Buffer.x;
		y += fptr->Buffer.y;

		/* detect mouse wheel event */
		/* ------------------------ */
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
					/* -------------------------------------------- */
					/* IJM 14/9/2006 : Modified for Stretch Frame 	*/
					/* instead of right button			*/
					/* -------------------------------------------- */
					if ( Context.ResizeBy /* RightButtonStretch */ ) {
						if ((b = visual_event(2)) == _MIMO_RIGHT )
							Context.Item.style = _SIZE_FRAME;
						}
					else if ((iptr = fptr->current ) != (struct form_item *) 0) {
						if ((b = visual_event(2)) == _MIMO_LEFT )
							if ( inside_widget_cursor( iptr, x, y ) )
								Context.Item.style = _SIZE_FRAME;
						}

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
				hide_form_selection(fptr,0);
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
					save_for_rollback( fptr,0,"is_FormEvent" );
					fptr->active = (struct form_item *) 0;
					return(257);
					}
				else if ( Context.Item.style != -1 ) {
					Context.Item.w = x;
					Context.Item.h = y;
					if ( Context.Item.style != _MOVE_FRAME ) {
						add_new_item(fptr,visual_event(2));
						if ( Context.dropon ) {
							use_icon_tool(( Context.style = _MOVE_FRAME ) , -1 /* FCH il faut 2 param */);
							}
						}
					Context.Item.style = -1;
					return(257);
					}
			default			:
				if ( t & _MIMO_ALT)
					return(widget_alt_shift( visual_event(2), fptr ));
				else	return(256);
			}
		}
	else	{
		switch ((t = visual_event(1))) {
			case	_MIMO_UP	:
				hide_form_selection(fptr,0);
				select_current(x,y);
				show_form_selection(fptr,_TREE_FOCUS);
			default			:
				if (t & _MIMO_ALT)
					return(widget_alt_shift( visual_event(2), fptr ));
				else	return(256);
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
	register int colourmaped;
	register int pixelsize;

	colourmaped = get_pixel_format();
	pixelsize   = get_pixel_size();

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
		else if ( colourmaped )
			memcpy(tptr,sptr,wptr->w);
		else	memcpy(tptr,sptr,wptr->w*pixelsize);
		}

	if (!( colourmaped )) 
		iptr->format = pixelsize;

	return( iptr );

}

public 	struct standard_image * grab_Image( 
	struct window_control * wptr, 
	struct standard_image * iptr )
{
	int	r;
	char *	sptr;
	register int colourmaped;
	register int pixelsize;

	colourmaped = get_pixel_format();
	pixelsize   = get_pixel_size();


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

public	void	form_Image(struct form_control * fptr, int refresh)
{
	struct window_control Window;
	struct	standard_image * grab_Image(struct window_control *, struct standard_image *);

	/* Calculate Entire Form Dimensions */
	/* -------------------------------- */
	if ( refresh )
		form_Dimensions( &Window, fptr );
	else
	{
#ifdef	NEWSING
		form_Dimensions( &Window, fptr );
#else
		window_Dimensions( &Window, fptr );
#endif

	}
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
			if ((event = old_database_editor()) == 27)
				event = 0;
			break;
			}
#ifdef	ABAL32A
		else if ( event == _EDIT_DATAMODEL ) {
			if ((event = database_model_editor()) == _LEAVE_SING)
				event = 0;
			break;
			}
		else if ( event == _EDIT_FLOWCHART ) {
			if ((event = flowchart_editor()) == _LEAVE_SING)
				event = 0;
			break;
			}
		else if ( event == _EDIT_STYLE ) {
			style_editor();
			event=0;
			break;
			}
		else if ( event == _EDIT_DEPEND ) {
			style_model_editor();
			event=0;
			break;
			}
#endif
		else if ( event == _EDIT_FONT ) {
			if (!( fptr->current ))
				event = font_edit(Context.Item.font);
			else	event = font_edit(fptr->current->Contents.font);
			}
		else if ( event == _EDIT_TEXT ) {				
			event = edit_form_production( fptr );
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
			SelectFormWidget( fptr, fptr->first,0 );
			return(257);

		case	5		:
		case	_NEXT_ITEM		:
			if (!( iptr ))
				break;
			else if (!( iptr->next )) 
				break;

			SelectFormWidget( fptr, fptr->current->next,0 );

			if ( fptr->display != _EDIT_CLASS ) 
				return(257);

			else if ( iptr->shitem == fptr->items ) {
				fptr->top = fptr->top->next;
				return(257);
				}
			else	break;

		case	_LAST_ITEM		:
			SelectFormWidget( fptr, fptr->last,0 );
			return(257);

		case	11		:
		case	_PREVIOUS_ITEM		:
			if (!( iptr ))
				break;
			else if (!( iptr->previous )) 
				break;

			SelectFormWidget( fptr, fptr->current->previous,0 );

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
	char *	sptr;
	switch ( event ) {
		case	_CREATE_WITHOUT_SIZE	:
		case	_CREATE_WITH_SIZE	:
		case	_SHOW_AUTOMATIC		:
		case	_SHOW_CONDITIONAL	:
		case	_FOCUS_WITH_FOCUS	:
		case	_FOCUS_WITHOUT_FOCUS	:
		case	_EVENT_WITH_EVENT	:
		case	_EVENT_WITHOUT_EVENT	:
		case	_HIDE_NO_POPUP		:
		case	_HIDE_WITH_POPUP	:
			SetEventProperty( iptr->Contents.events, event );
			break;

		case	_WIDGET_STYLE:
			if (( sptr=get_style_class_element(Context.widgetstyle)) != (char *) 0) {
				if ( iptr->Contents.stylesheet )
					liberate( iptr->Contents.stylesheet );
				iptr->Contents.stylesheet=allocate_string(sptr);
				}
			break;

		case	_WIDGET_TYPE :
			iptr->Contents.style= Context.style;
			break;
		case	_WIDGET_FONT :
			iptr->Contents.font = Context.Item.font;
			break;
		case	_WIDGET_LOCK :
			iptr->Contents.events->control |= _IS_XO_LOCK;
			break;
		case	_WIDGET_UNLOCK :
			iptr->Contents.events->control &= ~_IS_XO_LOCK;
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
			iptr->Contents.events->xo_show &= ~ _EVENT_IS_COND;
			break;
		case	_WIDGET_COND :
			iptr->Contents.events->xo_show |= _EVENT_IS_COND;
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
	int	changes=0;
	struct	form_item * iptr=(struct form_item *) 0;
	struct	form_item * mptr=(struct form_item *) 0;

	if (!( fptr  )) 
		return;

	else if (!( iptr = fptr->current ))
		return;

	else if (( iptr->Contents.style & _FRAME_TYPE ) != _CUT_FRAME) {
		changes++;
		if ( event == _WIDGET_DELETE ) {
			delete_widget(fptr);
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
				changes++;
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
				changes++;
				fptr->current = mptr;
				mptr = mptr->next;
				delete_widget(fptr);
				}
			}
		}
	form_is_outofdate(fptr);
	save_for_rollback( fptr,0,"set_widget_property" );
	return;
}

private	void	choose_national_payload( struct	form_item * iptr )
{
	int	i;
	for ( i=0; i < MAXNATLANG; i++ ) 
	{
		if (!(iptr->Contents.messages[i]))
			continue;
		else	
		{
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
				check_Widget( iptr );
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
			inhibit_rollback();
			for (	i=0,iptr = Context.Widgets;
				iptr != (struct form_item*) 0;
				iptr = iptr->next ) 
			{
				xptr = copy_widget( iptr );
				if (!( xptr ))
					continue;
				else	
				{
					add_Widget( fptr, xptr, 0 );
					xptr->parent = fptr;
					if ( fptr->natlang & _INTERNATIONAL )
						get_national_payload(xptr,fptr->natlang);
					else if (!( fptr->formflags & _FORM_MULTILINGUAL ))
						choose_national_payload( xptr );
					else	get_national_payload(xptr,fptr->natlang);
					i++;
					use_widget_events(xptr);
					check_Widget( xptr );
				}
			}
			message = "pasted";
			allow_rollback();
			form_is_outofdate(fptr);
			save_for_rollback(fptr,0,"form_clipboard");
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

public	void	form_national_language(struct form_control * fptr, int newlang )
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

public	void	change_national_language(struct form_control * fptr, int newlang )
{
	form_national_language(fptr, newlang);
	show_Form(fptr,1);
	return;
}

public	void	check_forms_methods(struct form_control * fptr )
{
	struct forms_method *	mptr;
	if (!( fptr ))
		return;

	fptr->PositionAt	=
	fptr->OnPage		=
	fptr->OnHint		=
	fptr->OnPreview		=
	fptr->OnPreConstr	=
	fptr->OnPostDestr	=
	fptr->OnEscape 		=
	fptr->OnEnter	 	=
	fptr->OnDefault		=
	fptr->StandardError  	= 
	fptr->StandardInput  	= (struct forms_method *)0;
	
	for (	mptr  = fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next) {
		if (!( mptr->name ))
			continue;
	
		switch ( detect_forms_special_method( mptr->name ) ) {
			case	_FORMS_POSITIONAT :
				fptr->PositionAt = mptr; break;
			case	_FORMS_ONPAGE	:
				fptr->OnPage		= mptr; break;
			case	_FORMS_ONHINT	:
				fptr->OnHint		= mptr; break;
			case	_FORMS_ONPREVIEW:
				fptr->OnPreview		= mptr; break;
			case	_FORMS_ONPRECONSTR	:
				fptr->OnPreConstr	= mptr; break;
			case	_FORMS_ONPOSTDESTR	:
				fptr->OnPostDestr	= mptr; break;
			case	_FORMS_ONESCAPE :
				fptr->OnEscape 		= mptr; break;
			case	_FORMS_ONENTER 	:
				fptr->OnEnter	 	= mptr; break;
			case	_FORMS_ONDEFAULT:
				fptr->OnDefault		= mptr; break;
			case	_FORMS_STDERROR :
				fptr->StandardError  	= mptr; break;
			case	_FORMS_STDINPUT	:
				fptr->StandardInput  	= mptr; break;
			}
		}
	return;
}

public	int	use_widget_events(struct form_item * iptr)
{
	struct form_control * fptr;
	if (!( fptr = iptr->parent))
		return(0);
	else	{
		switch ( fptr->language ) {
			case	_GENERATE_C	:
			case	_GENERATE_CPP	:
			case	_GENERATE_COBOL	:
			case	_GENERATE_JAVA	:
				iptr->Contents.events = &iptr->Contents.c_events;
				break;
			case	_GENERATE_BAL	:
			case	_GENERATE_ABAL	:
			case	_GENERATE_HTML	:
				iptr->Contents.events = &iptr->Contents.abal_events;
				break;
			}
		return(fptr->language);
		}
}


public	int	use_form_widget_events( struct form_control * fptr )
{
	struct	form_item * iptr;
	for (	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		use_widget_events(iptr);
		}
	return(fptr->language);
}


public	int	change_form_language( struct form_control * fptr, int national )
{
	if ( fptr->formflags & _FORM_INTERNATIONAL ) {
		if ( national != fptr->natlang ) {
			if ( fptr->formflags & _FORM_MULTILINGUAL )
				change_national_language( fptr, national );
			else	fptr->natlang = national;
			return(1);
			}
		else	return(0);
		}
	else	return(0);
}

public	int	form_parameters(struct form_control * fptr )
{
	int	status;
	int	ft;
	int	kesc,krc,kpu,kpd;
	int	ktab,klu,kld;
	int	kdef;
	int	kmec,kwt;
	int	mslb,msmb,mswh,msrb;
	int	msd,msu,mswd,msid,msm,msw;
	int	prodlang;
	int	userstate=SingConf->expert_user;
	int	international=0;
	int	multilingual=0;
	int	national=0;
	int	commandline=0;
	int	generateconstants=0;
	int	genhelp=0;
	int	acthelp=0;
	int	epurge=0;
	int	moving=0;

	if (!( fptr ))	return(27);
		
#ifdef	ABAL32A
	if ( fptr->inhibit_flush & 1 )
		epurge = 1;
	else	epurge = 0;

	if ( fptr->inhibit_flush & 2 )
		moving = 1;
	else	moving = 0;	
#endif
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

	if ( fptr->mimoflags & _MIMO_KEYBOARD )
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
	if ( fptr->mimoflags & _MIMO_SEND_WHEEL)
		mswh = 1;
	else	mswh = 0;
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

	if ( fptr->mimoflags & _MIMO_WIDGETS )
		msw = 1;
	else	msw = 0;

	if ( fptr->onlinehelp & 16 )
		acthelp = 1;
	else	acthelp = 0;

	genhelp = (fptr->onlinehelp & 7);

	if ( SingConf->expert_user )
		prodlang = fptr->language;
	else	{
#ifdef	ABAL32A
		if (( prodlang = fptr->language) == _GENERATE_BIFS )
			SingConf->expert_user=1;
		else if (( prodlang = fptr->language) == _GENERATE_XMTA )
			SingConf->expert_user=1;
		else if (( prodlang = fptr->language) == _GENERATE_LASER )
			SingConf->expert_user=1;
		else if (( prodlang = fptr->language) > _GENERATE_HTML ) {
#else
		if (( prodlang = fptr->language) > _GENERATE_ABAL ) {
#endif
			SingConf->expert_user++;
			}		
		}
	national = fptr->natlang;

	if ((status = accept_form_control(
		&ft, 			&prodlang, 		&national, 	

		&international, 	&generateconstants,
#ifdef	ABAL32A
		&fptr->styling,	
#endif
		&multilingual,
		&fptr->isprogram, 	&fptr->isoverlay, 
		&fptr->ispopup,   	&fptr->isdynamic,

		&commandline,	  	&fptr->argvlen,		&fptr->argvcount,

		&fptr->resizeauto,&fptr->resizew,&fptr->resizeh,


		&genhelp,	&acthelp,

		&fptr->askatb,	&fptr->askfore,	&fptr->askback,

		&fptr->prodname,	&fptr->identifier,
		&fptr->stylesheet, 	&fptr->palette,
		&fptr->clearscreen,	
#ifdef	NEWSING
		&fptr->extends,
#endif

		&mslb,&msmb,&msrb,&mswh,&msw,	/* LEFT, MIDDLE,RIGHT,WHEEL,WIDGETS */
#ifdef	ABAL32A
		&epurge,	&moving,
#endif
		&msd,&msu,&mswd,&msm,&kmec,&kwt,

		&kesc,&krc,&kpu,&kpd,&klu,&kld,&ktab,&kdef

		)) != 27 ) {

		if ( SingConf->expert_user )
			fptr->language = prodlang;
#ifdef	ABAL34A
		else if ( prodlang == 3 )
			fptr->language = _GENERATE_PHP;
		else if ( prodlang == 4 )
			fptr->language = _GENERATE_NODE;
		else if ( prodlang == 5 )
			fptr->language = _GENERATE_BIFS;
		else if ( prodlang == 6 )
			fptr->language = _GENERATE_XMTA;
		else if ( prodlang == 7 )
			fptr->language = _GENERATE_LASER;
#endif
		else	fptr->language = (prodlang+_GENERATE_BAL);

		fptr->onlinehelp = genhelp;

		if ( acthelp )
			fptr->onlinehelp |= 16;
		else	fptr->onlinehelp &= ~16;

		use_form_widget_events( fptr );

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
		fptr->mimoflags = 0;
		if ( kwt  ) fptr->mimoflags |= _MIMO_INTERRUPT;
		if ( kmec ) fptr->mimoflags |= _MIMO_KEYBOARD;
		if ( mslb ) fptr->mimoflags |= _MIMO_SEND_LEFT;
		if ( msmb ) fptr->mimoflags |= _MIMO_SEND_MIDDLE;
		if ( msrb ) fptr->mimoflags |= _MIMO_SEND_RIGHT;
		if ( mswh ) fptr->mimoflags |= _MIMO_SEND_WHEEL;
		if ( msd  ) fptr->mimoflags |= _MIMO_DOWN;
		if ( msu  ) fptr->mimoflags |= _MIMO_UP;
		if ( mswd ) fptr->mimoflags |= _MIMO_WHILE_DOWN;
		if ( msid ) fptr->mimoflags |= _MIMO_IS_DOWN;
		if ( msm  ) fptr->mimoflags |= _MIMO_MOVE;
		if ( msw  ) fptr->mimoflags |= _MIMO_WIDGETS;

		fptr->inhibit_flush = 0;
		if ( epurge ) { fptr->inhibit_flush |= 1; }
		if ( moving ) { fptr->inhibit_flush |= 2; }

		switch ( fptr->formflags & _FORM_TYPE_FLAGS ) {
			case	_FORM_TYPE_DIALOG	:
			case	_FORM_TYPE_EVENT 	:
				break;
			case	_FORM_TYPE_QUALITY	:
			case	_FORM_TYPE_PAGE  	:
				/* required for multiple page printing */
				fptr->formflags |= _FORM_RC;

			}		
		change_form_language( fptr, national );
		check_forms_production( fptr );
		check_forms_methods(fptr);
		form_is_outofdate( fptr );
		save_for_rollback( fptr,0,"form_parameters" );
		}
	SingConf->expert_user = userstate;
	return(status);
}

public	int	form_widget_insert( struct form_control * fptr )
{
	int	holdroll=0;
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

	inhibit_rollback();
	if (( iptr = allocate_Widget(fptr)) != (struct form_item *) 0) {
		form_data_type( iptr );
		if (!( iptr->Contents.name ))
			iptr->Contents.name = automatic_name(iptr->number);
		if ( xptr ) {
			iptr->Contents.colour = xptr->Contents.colour;
			iptr->Contents.align  = xptr->Contents.align ;
			iptr->Contents.style  = xptr->Contents.style ;
			iptr->Contents.font   = xptr->Contents.font  ;
			iptr->Contents.datatype = xptr->Contents.datatype;
			if ( method_is_valid( xptr->Contents.stylesheet ) ) 
				iptr->Contents.stylesheet = allocate_string( xptr->Contents.stylesheet );
			if ( method_is_valid( xptr->Contents.stylefocus ) ) 
				iptr->Contents.stylefocus = allocate_string( xptr->Contents.stylefocus );
			if ( method_is_valid( xptr->Contents.stylepress ) ) 
				iptr->Contents.stylepress = allocate_string( xptr->Contents.stylepress );
			if ( method_is_valid( xptr->Contents.format ) ) 
				iptr->Contents.format = allocate_string( xptr->Contents.format );
			}
		show_item_info(fptr->current);
		check_Widget( iptr );
		}
	allow_rollback();
	form_is_outofdate( fptr );
	save_for_rollback( fptr,0,"form_widget_insert" );
	fptr->active = (struct form_item *) 0;
	return(257);
}

public	int	await_form_event( struct form_control * fptr )
{
	int	event;
	int	awctrue;
	show_form_selection(fptr,_TREE_FOCUS );
	do	{
		/* Attempt to Display the active widget Cursor */
		/* ------------------------------------------- */
		if (!( RightButtonStretch ))
			awctrue = active_widget_cursor( fptr->current );						
		else	awctrue = 0;

		event = visual_getch();

		/* Attempt to Release the active widget Cursor */
		/* ------------------------------------------- */
		if ( awctrue ) {
			release_widget_cursor();
			awctrue=0;
			}
		}
	while ((event == 256)
	&&     ((event = handle_event()) == 256));
	hide_form_selection(fptr,0 );
	return( event );
}

/*	--------------------------------------------------	*/
/*	F O R M _ E D I T O R  ::  O N _ G E T _ F O C U S	*/
/*	--------------------------------------------------	*/

public	void	use_widget_cursor()
{
	if (!( resolve_style_class( "sing/widget_cursor_frame" )))
		RightButtonStretch = 1;
	else	RightButtonStretch = 0;
	return;
}

public	void	use_right_button_stretch()
{
	RightButtonStretch=1;
	return;
}

public	void	toggle_widget_cursor()
{
	if ( RightButtonStretch )
		use_widget_cursor();
	else	use_right_button_stretch();
	return;
}

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
					save_Form(fptr,QUICK,(char *) 0);
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
		&iptr->Contents.hmessages[0],	/* english */
		&iptr->Contents.messages[1],	/* french  */
		&iptr->Contents.hmessages[1],	/* french  */
		&iptr->Contents.messages[2],	/* italien */
		&iptr->Contents.hmessages[2],	/* italien */
		&iptr->Contents.messages[3],	/* spanish */
		&iptr->Contents.hmessages[3],	/* spanish */
		&iptr->Contents.messages[4],	/* german  */
		&iptr->Contents.hmessages[4],	/* german  */
		&iptr->Contents.messages[5],	/* dutch   */
		&iptr->Contents.hmessages[5],	/* dutch   */
		&iptr->Contents.messages[6],	/* portugese */
		&iptr->Contents.hmessages[6],	/* portugese */
		&iptr->Contents.messages[7],	/* other	*/
		&iptr->Contents.hmessages[7]	/* other	*/
		);	/* portugese*/

	get_national_payload(iptr,fptr->natlang);
	return;
}

public	void	edit_national_messages()
{
	struct	form_item * iptr;
	if (!( Context.Form ))
		return;
	else if (!( iptr = Context.Form->current ))
		return;
	else	{
		edit_widget_messages( iptr, iptr->parent );
		return;
		}
}
void	transcode_accents( char ** mptr, int mode )
{
	convert_html_accents( mptr, mode );
	return;
}

private	void	edit_widget_helptexts(struct form_item * iptr, struct form_control * fptr )
{
	int	i;
	for (i=0; i < MAXNATLANG; i++) { transcode_accents(&iptr->document[i],1); }
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
	for (i=0; i < MAXNATLANG; i++) { transcode_accents(&iptr->document[i],2); }
	return;
}

public	void	edit_national_helptext()
{
	struct	form_item * iptr;
	if (!( Context.Form ))
		return;
	else if (!( iptr = Context.Form->current ))
		return;
	else	{
		edit_widget_helptexts( iptr, iptr->parent );
		return;
		}
}

public 	void	edit_form_helptexts(struct form_control * fptr )
{
	int	i;
	for (i=0; i < MAXNATLANG; i++) { transcode_accents(&fptr->document[i],1); }
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
	for (i=0; i < MAXNATLANG; i++) { transcode_accents(&fptr->document[i],2); }
	return;
}

public	void	check_Form( struct form_control * fptr )
{
	struct	form_item * iptr;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
		iptr->parent = fptr;
	use_form_widget_events(fptr);
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
		if ( method_is_valid(iptr->Contents.events->on_create) )
			if ((l = detect_reference(iptr->Contents.events->on_create,nptr)) != 0)
				add_widget_reference(&rptr, &lptr, iptr, (struct forms_method *) 0, l, 1 );
		if ( method_is_valid(iptr->Contents.events->on_show) )
			if ((l = detect_reference(iptr->Contents.events->on_show  ,nptr)) != 0)
				add_widget_reference(&rptr, &lptr, iptr, (struct forms_method *) 0, l, 2 );
		if ( method_is_valid(iptr->Contents.events->on_get_focus) )
			if ((l = detect_reference(iptr->Contents.events->on_get_focus,nptr)) != 0)
				add_widget_reference(&rptr, &lptr, iptr, (struct forms_method *) 0, l, 3 );
		if ( method_is_valid(iptr->Contents.events->on_lose_focus) )
			if ((l = detect_reference(iptr->Contents.events->on_lose_focus,nptr)) != 0)
				add_widget_reference(&rptr, &lptr, iptr, (struct forms_method *) 0, l, 4 );
		if ( method_is_valid(iptr->Contents.events->on_event) )
			if ((l = detect_reference(iptr->Contents.events->on_event,nptr)) != 0)
				add_widget_reference(&rptr, &lptr, iptr, (struct forms_method *) 0, l, 5 );
		if ( method_is_valid(iptr->Contents.events->on_hide) )
			if ((l = detect_reference(iptr->Contents.events->on_hide,nptr)) != 0)
				add_widget_reference(&rptr, &lptr, iptr, (struct forms_method *) 0, l, 6 );
		if ( method_is_valid(iptr->Contents.events->on_remove) )
			if ((l = detect_reference(iptr->Contents.events->on_remove,nptr)) != 0)
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

private	void	set_widget_style( struct form_control * fptr )
{
	if ( accept_widget_style(&Context.widgetstyle) != 27 )
		set_widget_property( fptr, _WIDGET_STYLE );
	return;
}

private	void	toggle_gridlock(struct form_control * fptr)
{
	if (!( Context.gridlockw ))
		set_context_gridlock(fptr->gridlock);
	else	set_context_gridlock(0);
	draw_console();
	return;
}

private	void	toggle_formview(struct form_control * fptr)
{
	if ( Context.MakeFormFit )
		Context.MakeFormFit=0;
	else	Context.MakeFormFit=1;
	draw_console();
	return;
}

private	void	toggle_styleview(struct form_control * fptr)
{
	if ( Context.usestyle )
		Context.usestyle=0;
	else	Context.usestyle=1;
	draw_console();
	return;
}

public	struct form_control * load_from_rollback(struct form_control * fptr )
{
	struct	form_control * xptr;
	char *	nomfic;
	int	rb;
	int	rc;
	int	rd;
	int	rn;
	FILE *	h;
	char *	rf;
	if (!( Context.rollback ))
		return(fptr);
	else if (!( fptr->rollback > 1 ))
		return( fptr );
	else if (!( rf = allocate_string( fptr->loadname ) ))
		return(fptr);
	else if (!( nomfic = rollback_filename( fptr->loadname, (fptr->rollback-1) )))
		return;
	else	{
		rn = fptr->rollnext;
		rc = fptr->rollchck;
		rd = fptr->outofdate;
		if (!( h = fopen( nomfic, "r" ))) {
			liberate( nomfic );
			liberate( rf );
			return(fptr);
			}
		else	{
			fclose(h);
			fptr->rollback--;
			rb = fptr->rollback;
			}
		if (!( fptr = load_XmlForm(fptr, nomfic, 1, QUICK )))
			return( fptr );
		else	{
			liberate( nomfic );
			fptr->rollnext = rn;
			fptr->rollback = rb;
			fptr->rollchck = rc;
			fptr->outofdate= rd;
			if ( fptr->loadname )
				liberate( fptr->loadname );
			fptr->loadname = rf;
			return( fptr );
			}
		}
}

public	struct form_control * load_from_rollfore(struct form_control * fptr )
{
	FILE *	h;
	struct	form_control * xptr;
	char *	nomfic;
	int	rb;
	int	rc;
	int	rd;
	int	rn;
	char *	rf;
	if (!( Context.rollback ))
		return(fptr);
	else if ( fptr->rollback >= fptr->rollnext )
		return( fptr );
	else if (!( rf = allocate_string( fptr->loadname ) ))
		return(fptr);
	else if (!( nomfic = rollback_filename( fptr->loadname, (fptr->rollback+1))))
		return;
	else	{
		rn = fptr->rollnext;
		rc = fptr->rollchck;
		rd = fptr->outofdate;
		if (!( h = fopen( nomfic, "r" ))) {
			liberate( nomfic );
			liberate( rf );
			return(fptr);
			}
		else	{
			fclose(h);
			fptr->rollback++;
			rb = fptr->rollback;
			}
		if (!( fptr = load_XmlForm(fptr, nomfic, 1, QUICK )))
			return( fptr );
		else	{
			liberate( nomfic );
			fptr->rollnext = rn;
			fptr->rollback = rb;
			fptr->rollchck = rc;
			fptr->outofdate= rd;
			if ( fptr->loadname )
				liberate( fptr->loadname );
			fptr->loadname = rf;
			return( fptr );
			}
		}
}

static	FormsMethodList=(char *) 0;
char	*	FormsMethodNames()
{
	char *	bptr;
	struct	forms_method * mptr;
	if (!( Context.Form ))
		return("no form");
	if (!( FormsMethodList )) {
		for (	mptr=Context.Form->rootmethod;
			mptr != (struct forms_method *) 0;
			mptr = mptr->next ) {
			if (!( FormsMethodList ))
				FormsMethodList = allocate_string( mptr->name );							
			else if (!( bptr = allocate( ( strlen(mptr->name ) + strlen( FormsMethodList ) + 8 ) )))
				break;
			else	{
				sprintf(bptr,"%s|%s",FormsMethodList,mptr->name);
				liberate( FormsMethodList );
				FormsMethodList = bptr;
				}
			}
		}
	return(( FormsMethodList ? FormsMethodList : "n/a"));
}


int	form_methods( struct form_control * fptr )
{
	int	event=0;
	int	mid=0;
	int	kid=0;
	struct	form_control * ffptr;
	FormsMethodList = (char *) 0;
	ffptr = Context.Form;
	Context.Form = fptr;

	while ((kid = form_methods_menu(&mid)) != 27 ) {
		edit_forms_method((mid+1));
		if ( FormZoomCheck() ) {
			event = _EDIT_RESOLVE;
			break;
			}
		}
		
	if ( FormsMethodList ) {
		liberate( FormsMethodList );
		}
	Context.Form = ffptr;
	return(event);
}


public	int	FormZoomCheck()
{
	if ( FormZoom.nature )
		return(27);
	else	return(0);
}

private	void	ResetFormZoom()
{
	FormZoom.nature = 0;
	FormZoom.widget =(struct form_item *) 0;
	FormZoom.method =(struct forms_method *) 0;
	FormZoom.action =(char *) 0;
	return;
}

int	FormWidgetZoom(struct form_item * iptr, char * nptr)
{
	ResetFormZoom();
	edit_Widget( iptr, iptr->parent );
	return(0);
}

int	FormMethodZoom(struct forms_method * mptr)
{
	int	newmethod=0;
	ResetFormZoom();
	inspect_forms_method( mptr,newmethod );
	return(0);
}

int	FormEditorZoom()
{
	do	{
		switch ( FormZoom.nature ) {
			case	1 :
				FormWidgetZoom(FormZoom.widget,FormZoom.action);
				break;
			case	2 :
				FormMethodZoom(FormZoom.method);
				break;
			default	  : 
				ResetFormZoom();
				break;
			}
		}
	while ( FormZoomCheck() );
	return(0);
}

int	useSingHelpCenter(int v)
{
#ifdef	SING_MODEL_EDITOR
	int	event;
	switch ((event = SingHelpCenter(&v))) {
		case	27		:
		case	_LEAVE_SING	:
			return(0);
		default			:
			return( event );
		}
#else
	return(0);
#endif
}

int	FormEditorOnUseEvent( struct form_control ** ffptr, int event )
{
	struct form_control * fptr;
	struct form_control * xptr;

	if (!( fptr = *ffptr ))
		return( event );

	switch ( event ) {

		case	'-'	:
			toggle_national_language(0);
			draw_console();
			event = 0; break;			

		case	'+'	:
			toggle_national_language(1);
			draw_console();
			event = 0; break;			

		case	'!'	:
			Context.showframe = ((Context.showframe+1) & 1);
			draw_console();
			event=0; break;

		case	0x000F		:
			form_widget_insert(fptr);
			draw_console();
			event = 0; break;			

		case	1		:
			toggle_widget_cursor();
			event = 0; break;

		case	0x0016		:
			/* toggle between implicite style / pixel view */
			/* ------------------------------------------- */
			toggle_styleview(fptr);
			event=0; break;

		case	_FORM_FIT	:
		case	4		:
			/* toggle between makefit/scrolling form view */
			/* ------------------------------------------ */
			toggle_formview(fptr);
			event=0; break;

		case	  7		:
			/* toggle between grid active/inhibited modes */
			/* ------------------------------------------ */
			toggle_gridlock(fptr);
			event=0; break;
			
		case	  3		:
			/* Page Down : Next Tab Page */
			/* ------------------------- */
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

		case	0x000A	:
			Context.showall = ((Context.showall+1) & 1);
			draw_console();
			event=0; break;

		case	 0x000C	: 
			/* CTRL L : Toggle LOCKON */
			/* ---------------------- */
			Context.lockon = ((Context.lockon + 1) & 1);
			event = 0;
			break;

		case	 0x0012	:
			/* Page Up : Previous Tab Page */
			/* --------------------------- */
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
			if ( fptr->current ) {
				edit_Widget( fptr->current, fptr );
				FormEditorZoom();
				}
			event=0;
			break;

		case	_EDIT_TREEVIEW  :
			swap_TreeView();
			event=0; 
			break;
#ifdef	ABAL32A
		case	_FORM_COMPARE	:
			compare_Forms( fptr );
			event=0;
			break;
		case	_FORM_IMPORT	:
			import_Forms( fptr );
			event=0;
			break;
#endif
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

		case 	_EDIT_FLOWCHART	:
		case	0x0006		: /* CTRL F */
			if ((event = flowchart_editor()) == _LEAVE_SING)
				event = 0;
			break;

		case	0x001A		: /* CTRL Z  */
		case	_EDIT_DATAMODEL	:
			if ((event = database_model_editor()) == _LEAVE_SING)
				event = 0;
			break;

		case	_EDIT_DATABASE	:
			if ( old_database_editor() != 27 )
				context_is_outofdate(Context.Camera,4);
			event=0;
			break;

		case	_EDIT_RESOLVE	:
			event = FormEditorZoom();
			break;

		case	_VIEW_TEXT	:
		case	_VIEW_IMAGE	:
		case	_EDIT_GRAPH	:
			break;

		case	_FORM_HELP	:
			generate_Form_document( fptr );
			draw_console();
			event=0; break;
			
		case	0x000D	: /* CTRL M : ENTER */
		case	_FORM_PARA	:
			(void) form_parameters(fptr);
			draw_console();
			event=0; break;

		case	_FORM_METH	:
			event = form_methods(fptr);
			draw_console();
			break;

		case	_FORM_NUMBER	:
			renumerate_form(fptr);
			form_is_outofdate( fptr );
			save_for_rollback( fptr,0,"_FORM_NUMBER" );
			draw_console();
			event=0; break;

		case	0x0008		: /* CTRL H */
			break;

		case	_ALT_UP		:
		case	_ALT_DOWN	:
		case	_ALT_LEFT	:
		case	_ALT_RIGHT	:
			widget_alt_shift(event, fptr );
			event = 0; break;
		
		case	_FORM_ROLLBACK	:
			fptr = load_from_rollback(fptr);
			draw_console();
			event=0; break;

		case	_FORM_ROLLFORE	:
			fptr = load_from_rollfore(fptr);
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
		case	_FORM_STYLE	:
			if ( fptr->stylesheet != (char *) 0) {
				if ( edit_style_file(fptr->stylesheet,strlen(fptr->stylesheet)) ) {
					style_editor();
					}
				draw_console();
				}
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

		case	_WIDGET_STYLE	:
			set_widget_style( fptr );
			draw_console();
			event=0; break;

		case	_CREATE_WITHOUT_SIZE	:
		case	_CREATE_WITH_SIZE	:
		case	_SHOW_AUTOMATIC		:
		case	_SHOW_CONDITIONAL	:
		case	_FOCUS_WITH_FOCUS	:
		case	_FOCUS_WITHOUT_FOCUS	:
		case	_EVENT_WITH_EVENT	:
		case	_EVENT_WITHOUT_EVENT	:
		case	_HIDE_NO_POPUP		:
		case	_HIDE_WITH_POPUP	:

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
				form_Image(fptr,1);
				break;
				}
			else if (( event == _EDIT_FORM ) 
			     &&  ( treeview_is_active())) {
				form_Image(fptr,1);
				break;
				}
			else if (( event == _VIEW_TEXT )
			     ||  ( event == _VIEW_IMAGE )) {
				form_Image(fptr,1);
				break;
				}
			else if ( event != _LEAVE_SING ) {
				draw_Form(fptr,1);
				event=0; break;
				}
			else	break;

		case	_EXEC_PROG	:
			if ( fptr->prodname )
				abal_runtime( fptr->prodname, 0 );
			event=0; break;

		case	_EDIT_TEXT	:
			event = edit_form_production( fptr );
			break;

		case	_EDIT_IMAGE	:
		case	_EDIT_FONT	:
#ifdef	ABAL32A
		case	_EDIT_STYLE	:
#endif
			if ((event = form_editor_event(fptr,event)) == _EDIT_GRAPH ) {
				form_Image(fptr,1);
				break;
				}
			else if ( event == _VIEW_IMAGE ) {
				form_Image(fptr,1);
				break;
				}
			else if ( event == _EDIT_DATABASE ) {
				if ( old_database_editor() != 27 )
					context_is_outofdate(Context.Camera,4);
				event=0;
				break;
				}
#ifdef	ABAL32A
			else if ( event == _EDIT_DATAMODEL ) {
				if ( database_model_editor() != 27 )
					context_is_outofdate(Context.Camera,4);
				event=0;
				break;
				}
			else if ( event == _EDIT_FLOWCHART ) {
				if ( flowchart_editor() != 27 )
					context_is_outofdate(Context.Camera,4);
				event=0;
				break;
				}
			else if ( event == _EDIT_STYLE ) {
				style_editor();
				event=0;
				break;
				}
			else if ( event == _EDIT_DEPEND ) {
				style_model_editor();
				event=0;
				break;
				}
#endif
			else if ( event == _EDIT_TEXT ) {				
				event = edit_form_production( fptr );
				break;
				}
			else if (( event == _EDIT_FORM ) 
			     &&  ( treeview_is_active())) {
				form_Image(fptr,1);
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

		case	_FILE_ABOUT	:
			CameraAbout();
			event=0; break;;

		case	_FILE_SAVE	:
			get_context_defaults(fptr);
			save_Form(fptr,0,(char *) 0);
			draw_console();
			event=0; break;

		case	_FILE_QSAVE	:
			get_context_defaults(fptr);
			save_Form(fptr,QUICK,(char *) 0);
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

		case	_SING_PROD	:
		case	_FILE_PRODUCE	:
			get_context_defaults(fptr);
			check_Form(fptr);
			if ( export_Form(fptr,0) != 0 ) 
				if ( Context.AutoSave )
					save_Form(fptr,QUICK,(char *) 0);
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
			save_for_rollback( fptr,0,"_DELETE_ITEM" );
			draw_Form(fptr,1);
			event=0; break;

		case	5		:
		case	11		:
		case	_FIRST_ITEM	:
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

		case	27			:
			swap_MenuBar();
			event=0; break;

		case	_EVENT_CREATE		:
		case	_EVENT_REMOVE		:
		case	_EVENT_SHOW  		:
		case	_EVENT_HIDE  		:
		case	_EVENT_FOCUS 		:
		case	_EVENT_LOSE  		:
		case	_EVENT_EVENT 		:
			if ( fptr->current != (struct form_item *) 0) {
				accept_event( event, fptr->current->Contents.events);
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
	form_Image(fptr,1);
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
	struct	form_control * fptr;
	struct 	form_item    * iptr;
	if ((fptr = *ffptr) != (struct form_control *) 0) {
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next) {
			check_Widget( iptr );
			}
		}
	if (!( FormEditorOnGetFocus( ffptr ) ))
		return(0);
	else	{
		while (1) {
			event = await_form_event( *ffptr );
			do	{
				while (( event = FormEditorOnUseEvent( ffptr, event )) == _EDIT_RESOLVE);
				if ( event != 0x0008)
					break;
				}
			while ((event = useSingHelpCenter(2)) != 0);

			if (!( event ))
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
	html_tag(handle,"td");	
		html_text(handle,get_widget_class(iptr->Contents.style));
	html_tag(handle,"td");	
		html_text(handle,iptr->Contents.name);
	html_tag(handle,"td");
		html_integer(handle,iptr->Contents.x);
		fprintf(handle,",");
		html_integer(handle,iptr->Contents.y);
		fprintf(handle,",");
		html_integer(handle,iptr->Contents.w);
		fprintf(handle,",");
		html_integer(handle,iptr->Contents.h);

	html_tag(handle,"td");
		html_integer(handle,iptr->Contents.font);
	html_tag(handle,"td");
		html_integer(handle,iptr->Contents.align);

	html_tag(handle,"td");	
		if ((tptr = get_widget_datatype( iptr->Contents.datatype )) != (char *) 0) 
			html_text(handle,tptr );

	html_tag(handle,"td");	
		if ( method_is_valid(iptr->Contents.payload ) )
			html_text(handle,iptr->Contents.payload);
		else	html_text(handle,"&nbsp;");

	html_tag(handle,"td");	
		if ( method_is_valid(iptr->Contents.format ) )
			html_text(handle,iptr->Contents.format);
		else	html_text(handle,"&nbsp;");

	html_tag(handle,"td");	
		if ( method_is_valid(iptr->Contents.stylesheet ) )
			html_text(handle,iptr->Contents.stylesheet);
		else	html_text(handle,"&nbsp;");
	
	html_tag(handle,"td");
		if ( method_is_valid( iptr->Contents.events->on_create) ) {
			fprintf(handle,"<a href=%c#%s_Create%c>",0x0022,iptr->Contents.name,0x0022);
			html_text(handle,"Create");
			html_closure(handle,"a");
			html_tag(handle,"br");
			}

		if ( method_is_valid( iptr->Contents.events->on_show) ) {
			fprintf(handle,"<a href=%c#%s_Show%c>",0x0022,iptr->Contents.name,0x0022);
			html_text(handle,"Show");
			html_closure(handle,"a");
			html_tag(handle,"br");
			}

		if ( method_is_valid( iptr->Contents.events->on_get_focus) ) {
			fprintf(handle,"<a href=%c#%s_Focus%c>",0x0022,iptr->Contents.name,0x0022);
			html_text(handle,"Focus");
			html_closure(handle,"a");
			html_tag(handle,"br");
			}
		if ( method_is_valid( iptr->Contents.events->on_event) ) {
			fprintf(handle,"<a href=%c#%s_Event%c>",0x0022,iptr->Contents.name,0x0022);
			html_text(handle,"Event");
			html_closure(handle,"a");
			html_tag(handle,"br");
			}

		if ( method_is_valid( iptr->Contents.events->on_lose_focus) ) {
			fprintf(handle,"<a href=%c#%s_LoseFocus%c>",0x0022,iptr->Contents.name,0x0022);
			html_text(handle,"LoseFocus");
			html_closure(handle,"a");
			html_tag(handle,"br");
			}

		if ( method_is_valid( iptr->Contents.events->on_hide) ) {
			fprintf(handle,"<a href=%c#%s_Hide%c>",0x0022,iptr->Contents.name,0x0022);
			html_text(handle,"Hide");
			html_closure(handle,"a");
			html_tag(handle,"br");
			}

		if ( method_is_valid( iptr->Contents.events->on_remove) ) {
			fprintf(handle,"<a href=%c#%s_Remove%c>",0x0022,iptr->Contents.name,0x0022);
			html_text(handle,"Remove");
			html_closure(handle,"a");
			html_tag(handle,"br");
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
		iptr->Contents.ylimit,iptr->Contents.name);
	tabadjust+= iptr->Contents.xlimit;
	return( tabadjust );
}

public	int	generate_widget_area( FILE * handle,struct form_item * iptr,  struct window_control * wptr)
{
	char	*	lptr;
	char	*	hptr=(char *) 0;

	switch ( (iptr->Contents.style & _FRAME_TYPE ) ) {
		case	_BUTTON_FRAME	:
			if ( iptr->Contents.datatype  ==  _WIDGET_HYPERLINK )
				hptr = iptr->Contents.format;

		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
		case	_TAB_FRAME	:
			lptr = iptr->Contents.payload;
			break;
		default			:
			lptr = iptr->Contents.name;
			break;
		}
	if ( hptr ) {
		html_area_href(
			handle,lptr,
			iptr->Contents.x-wptr->x,
			iptr->Contents.y-wptr->y,
			iptr->Contents.w,
			iptr->Contents.h, iptr->Contents.name, hptr );
		}
	else	{
		html_area( 
			handle,lptr,
			iptr->Contents.x-wptr->x,
			iptr->Contents.y-wptr->y,
			iptr->Contents.w,
			iptr->Contents.h, iptr->Contents.name );
		}
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
		(fh+3), iptr->Contents.name );
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

		if (!( iptr->Contents.name ))
			continue;

		if ( fptr->formflags & _INTERNATIONAL )
			dptr = iptr->document[fptr->natlang];
		else	dptr = iptr->document[0];

		if ( dptr ) {

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
		else if (( iptr->Contents.style & _FRAME_TYPE) == _BUTTON_FRAME ) 
			if ( iptr->Contents.datatype  ==  _WIDGET_HYPERLINK )
				generate_widget_area( handle, iptr, &Window );

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

private	void	report_widget_method( FILE * h, char * wname, char * wtext, char * mname, char * mtype, struct form_item * iptr )
{
	char *	sptr;
	linefeed(h);
	fprintf(h,"<p><a name=%c%s_%s%c><table border=1><tr><th>%s<th>%s<th>%s<tr><td colspan=3><code><pre>",0x0022,wname,mname,0x0022,wname,mname,mtype);
	linefeed(h);
	fprintf(h,"%s %s.%s()",mtype,wname,mname);
	linefeed(h);
	html_text(h,wtext);
	linefeed(h);
	fprintf(h,"</pre></code>");
	if ((iptr->Contents.style & _FRAME_TYPE) == _BUTTON_FRAME) {
		if (!( sptr = iptr->Contents.format ))
			sptr = "undefined";
		switch ( iptr->Contents.datatype ) {
			case	_WIDGET_OVERLAY	:
				fprintf(h,"<tr><td>Overlay : %s ",sptr);
				break;
			case	_WIDGET_CHAIN  	:
				fprintf(h,"<tr><td>Chain   : %s ",sptr);
				break;
			case	_WIDGET_MODULE 	:
				fprintf(h,"<tr><td>Module  : %s ",sptr);
				break;
			case	_WIDGET_LOADGO 	:
				fprintf(h,"<tr><td>Load.Go : %s ",sptr);
				break;
			case	_WIDGET_SYSTEM 	:
				fprintf(h,"<tr><td>System  : %s ",sptr);
				break;
#ifdef	ABAL32A
			case	_WIDGET_TASK   	:
				fprintf(h,"<tr><td>Task    : %s ",sptr);
				break;
#endif
			case	_WIDGET_HYPERLINK   	:
				fprintf(h,"<tr><td>Href : %s ",sptr);
				break;

			}
		}
	fprintf(h,"</table><p>");
	linefeed(h);
	return;

}

private	char	widgetoptionbuffer[256];

private	char *	widget_method_options(int value,char * tptr, char * fptr)
{
	if ( value & _EVENT_IS_FUNCTION )
		strcpy(widgetoptionbuffer,"Function ");
	else	strcpy(widgetoptionbuffer,"Inline ");

	if ( value & _EVENT_IS_OTHER ) {
		if ( tptr )
			strcat(widgetoptionbuffer,tptr);
		}
	else if ( fptr )
		strcat(widgetoptionbuffer,fptr);

	return( widgetoptionbuffer );
}

private	void	report_forms_methods( FILE * h,struct form_control * fptr)
{
	struct	forms_method * mptr;
	char *	sptr;
	for ( 	mptr=fptr->rootmethod; 
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		linefeed(h);
		fprintf(h,"<p><table border=1><tr><th>");
		if ( mptr->type & _METHOD_PUBLIC )
			fprintf(h,"Public ");
		if ( mptr->type & _METHOD_FUNCTION )
			fprintf(h,"Function %s",mptr->name);
		else	fprintf(h,"Inline   %s",mptr->name);
		if (!( method_is_valid((sptr = mptr->signature) )))
			sptr="\0";
		fprintf(h,"(%s)",sptr);
		switch ( (mptr->type & _METHOD_TYPE) ) {
			case	_METHOD_VOID	: break;
			case	_METHOD_BYTE	: fprintf(h," : # " ); break;
			case	_METHOD_LONG : fprintf(h," : :  "); break;
			case	_METHOD_WORD	: fprintf(h," : %% "); break;
			case	_METHOD_NUMERIC	: fprintf(h," : =8 "); break; 
			case	_METHOD_CLASS	:
			case	_METHOD_STRING	: fprintf(h," : $ " ); break;
			}

		linefeed(h);
		if (!( method_is_valid((sptr = mptr->text) )))
			sptr="\0";
		else	{
			fprintf(h,"<tr><td><code><pre>");
			linefeed(h);
			html_text(h,sptr);
			linefeed(h);
			fprintf(h,"</pre></code>");
			}
		fprintf(h,"</table><p>");
		linefeed(h);
		}
	return;
}

private	void	report_widget_methods( FILE * handle,struct form_item * iptr)
{
	char	*	optr;

	/* report widget CREATE */
	/* -------------------- */
	if ( method_is_valid( iptr->Contents.events->on_create ) ) {
		optr = widget_method_options(iptr->Contents.events->xo_create,"Dynamic","Static");
		report_widget_method(handle,iptr->Contents.name,iptr->Contents.events->on_create,"Create",optr,iptr);
		}
	/* report widget SHOW */
	/* ------------------ */
	if ( method_is_valid( iptr->Contents.events->on_show ) ) {
		optr = widget_method_options(iptr->Contents.events->xo_show,"Conditional","Automatic");
		report_widget_method(handle,iptr->Contents.name,iptr->Contents.events->on_show,"Show",optr,iptr);
		}
	/* report widget GET FOCUS */
	/* ----------------------- */
	if ( method_is_valid( iptr->Contents.events->on_get_focus ) ) {
		optr = widget_method_options(iptr->Contents.events->xo_get_focus,"FocusItem",(char *) 0);
		report_widget_method(handle,iptr->Contents.name,iptr->Contents.events->on_get_focus,"Focus",optr,iptr);
		}
	/* report widget EVENT */
	/* ------------------- */
	if ( method_is_valid( iptr->Contents.events->on_event ) ) {
		optr = widget_method_options(iptr->Contents.events->xo_event,"EventItem",(char *) 0);
		report_widget_method(handle,iptr->Contents.name,iptr->Contents.events->on_event,"Event",optr,iptr);
		}
	/* report widget LOSE FOCUS */
	/* ------------------------ */
	if ( method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
		optr = widget_method_options(iptr->Contents.events->xo_lose_focus,(char *) 0, (char *) 0);
		report_widget_method(handle,iptr->Contents.name,iptr->Contents.events->on_lose_focus,"LoseFocus",optr,iptr);
		}
	/* report widget HIDE */
	/* ------------------ */
	if ( method_is_valid( iptr->Contents.events->on_hide ) ) {
		optr = widget_method_options(iptr->Contents.events->xo_hide,"PopUp", (char *) 0);
		report_widget_method(handle,iptr->Contents.name,iptr->Contents.events->on_hide,"Hide",optr,iptr);
		}
	/* report widget REMOVE */
	/* -------------------- */
	if ( method_is_valid( iptr->Contents.events->on_remove ) ) {
		optr = widget_method_options(iptr->Contents.events->xo_remove,(char *) 0, (char *) 0);
		report_widget_method(handle,iptr->Contents.name,iptr->Contents.events->on_remove,"Remove",optr,iptr);
		}
	return;
}

private	void	report_forms_specifications( FILE * h, struct form_control * fptr )
{
	html_heading(h,3,"Forms Production");
	html_tag(h,"table");
	html_tag(h,"tr"); 
		html_tag(h,"th"); fprintf(h,"Language");
		html_tag(h,"td");
		switch ( fptr->language ) {
			case	_GENERATE_BAL		: fprintf(h,"%s","ABAL"); 	break;
			case	_GENERATE_ABAL		: fprintf(h,"%s","ABAL++");	break;
			case	_GENERATE_C		: fprintf(h,"%s","C"); 		break;
			case	_GENERATE_CPP		: fprintf(h,"%s","C++"); 	break;
			case	_GENERATE_HTML		: fprintf(h,"%s","HTML"); 	break;
			case	_GENERATE_JAVA		: fprintf(h,"%s","JAVA"); 	break;
			case	_GENERATE_COBOL		: fprintf(h,"%s","COBOL"); 	break;
			case	_GENERATE_MAKE		: fprintf(h,"%s","MAKE"); 	break;
			}
	html_tag(h,"tr"); 
		html_tag(h,"th"); fprintf(h,"Packaging");
		html_tag(h,"td");
		if ( fptr->isprogram) {
			fprintf(h,"Program ");
			if ( fptr->isoverlay)
				fprintf(h,"Overlay ");
			}
		else if ( fptr->isoverlay)
			fprintf(h,"Module  ");
		else	fprintf(h,"Include ");

	html_tag(h,"tr"); 
		html_tag(h,"th"); fprintf(h,"Description");
		html_tag(h,"td");
		if ( fptr->formflags & _FORM_MULTILINGUAL )
			fprintf(h,"Multilingual ");
		switch ( fptr->natlang ) {
			case	0 : fprintf(h,"English "); break;
			case	1 : fprintf(h,"French "); break;
			case	2 : fprintf(h,"Italian "); break;
			case	3 : fprintf(h,"Spanish "); break;
			case	4 : fprintf(h,"German "); break;
			case	5 : fprintf(h,"Dutch "); break;
			case	6 : fprintf(h,"Portugese "); break;
			}
		switch ( fptr->formflags & _FORM_TYPE_FLAGS ) {
			case	_FORM_TYPE_DIALOG	: fprintf(h,"Dialog Box "); 	break;
			case	_FORM_TYPE_EVENT 	: fprintf(h,"Event Driven "); 	break;
			case	_FORM_TYPE_QUALITY	: fprintf(h,"High Quality "); 	break;
			case	_FORM_TYPE_PAGE   	: fprintf(h,"Document "); 	break;
			}
		 fprintf(h,"Model"); 

	if (method_is_valid( fptr->prodname ) ) {
		html_tag(h,"tr"); 
			html_tag(h,"th"); fprintf(h,"Target");
			html_tag(h,"td"); fprintf(h,"%s",fptr->prodname);
		}


	html_tag(h,"tr"); 
		html_tag(h,"th"); fprintf(h,"Keyboard Events");
		html_tag(h,"td");
		if ( fptr->formflags & _FORM_ESC )		fprintf(h,"ESC "); 
		if ( fptr->formflags & _FORM_DOWN )		fprintf(h,"DOWN ");
		if ( fptr->formflags & _FORM_UP )		fprintf(h,"UP ");
		if ( fptr->formflags & _FORM_PAGE_DOWN )	fprintf(h,"PAGEDOWN ");
		if ( fptr->formflags & _FORM_PAGE_UP )		fprintf(h,"PAGEUP ");
		if ( fptr->formflags & _FORM_TAB )		fprintf(h,"TABULATION ");
		if ( fptr->formflags & _FORM_RC    )		fprintf(h,"ENTER ");
		if ( fptr->formflags & _FORM_DEFAULT )		fprintf(h,"DEFAULT ");


	if (method_is_valid( fptr->stylesheet ) ) {
		html_tag(h,"tr"); 
			html_tag(h,"th"); fprintf(h,"Style");
			html_tag(h,"td"); fprintf(h,"%s",fptr->stylesheet);
		}

	if (method_is_valid( fptr->dependance ) ) {
		html_tag(h,"tr"); 
			html_tag(h,"th"); fprintf(h,"Inclusion");
			html_tag(h,"td"); fprintf(h,"%s",fptr->dependance);
		}

	if (method_is_valid( fptr->construction ) ) {
		html_tag(h,"tr"); 
			html_tag(h,"th"); fprintf(h,"Modules");
			html_tag(h,"td"); fprintf(h,"%s",fptr->construction);
		}

	if (method_is_valid( fptr->clearscreen ) ) {
		html_tag(h,"tr"); 
			html_tag(h,"th"); fprintf(h,"Background");
			html_tag(h,"td"); fprintf(h,"%s",fptr->clearscreen);
		}

	html_closure(h,"table");
	html_paragraph( h, " " );
	return;
}

public	int	document_Form( 
			FILE * handle,
			struct form_control * fptr,
			int automatic, int report
			)
{
	struct	form_item * 	current;
	int			pagenumber;
	struct 	form_item * iptr;
	int	tabadjust=0;
	int	paging=0;
	char *	dptr;
	char *	iname=(char *) 0;

	/* Do nothing if nothing to do */
	/* --------------------------- */ 
	if (!( fptr )) 	return(0);

	/* save these crucial values please */
	/* -------------------------------- */
	else	{
		current 	= fptr->current;
		pagenumber	= fptr->page_number;
		}
	
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

		/* Generate Complete Forms Specifications */
		/* -------------------------------------- */
		report_forms_specifications(handle,fptr);

		/* Generate Complete Component Table */
		/* --------------------------------- */
		html_heading(handle,3,"Components");
		html_tag(handle,"table");
		html_tag(handle,"tr");
		html_tag(handle,"th"); html_text(handle,"Class");
		html_tag(handle,"th"); html_text(handle,"Name");
		html_tag(handle,"th"); html_text(handle,"Dimensions");
		html_tag(handle,"th"); html_text(handle,"Font");
		html_tag(handle,"th"); html_text(handle,"Option");
		html_tag(handle,"th"); html_text(handle,"Action");
		html_tag(handle,"th"); html_text(handle,"Payload");
		html_tag(handle,"th"); html_text(handle,"Format");
		html_tag(handle,"th"); html_text(handle,"Style");
		html_tag(handle,"th"); html_text(handle,"Events");
		html_closure(handle,"tr");
		for (	iptr=fptr->first; 
			iptr != (struct form_item *) 0; 
			iptr = iptr->next ) 
			widget_Report( handle, iptr, report );
		html_closure(handle,"table");
		html_paragraph( handle, " " );

		html_heading(handle,3,"Forms Methods");
		report_forms_methods(handle, fptr );
		html_heading(handle,3,"Widget Documentation and Methods");
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

		if (( dptr ) &&  ( iptr->Contents.name )) {

			if ( paging ) {
				html_page_tag(handle,"li");
				open_html_definition_list(handle);
				}

			/* Generation of Help Text */
			/* ----------------------- */
			switch ( (iptr->Contents.style & _FRAME_TYPE ) ) {
				case	_BUTTON_FRAME	:
					switch ( iptr->Contents.datatype ) {
						case	_WIDGET_OVERLAY	:
						case	_WIDGET_MODULE 	:
						case	_WIDGET_CHAIN  	:
						case	_WIDGET_LOADGO 	:
							if ( iptr->Contents.align & 1 ) 
								html_enhanced_icon_definition(handle,iptr->Contents.payload, dptr, iptr->Contents.format, fptr->natlang, iptr->Contents.w,iptr->Contents.h, iptr->Contents.align & _A_BOLD );
							else	html_enhanced_definition(handle,iptr->Contents.payload, dptr, iptr->Contents.format, fptr->natlang );
							break;
						default			:
							if ( iptr->Contents.align & 1 ) 
								html_icon_definition(handle,iptr->Contents.payload, dptr, iptr->Contents.w,iptr->Contents.h, iptr->Contents.align & _A_BOLD  );
							else	html_definition(handle,iptr->Contents.payload, dptr );
							break;
						}
					break;
		
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

		if ( report ) {
			/* Generation of Method Code */
			/* ------------------------- */
			report_widget_methods(handle,iptr);
			}

		if (( iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME) {
			if ((iname = html_numbered_image(handle,fptr->prodname,iptr->Contents.page, iptr->Contents.name, form_imagetype( fptr ) )) != (char *) 0) {
				fptr->current = iptr;
				fptr->page_number = iptr->Contents.page;
				build_tab_image( fptr, iname, form_imagetype( fptr ) );
				liberate( iname );
				}
			html_tag(handle,"p");
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


	/* restore these crucial values please */
	/* ----------------------------------- */
	fptr->current 	 = current;
	fptr->page_number= pagenumber;

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

int	package_Form(struct form_control * fptr)
{
	int	items=0;
	struct	form_item * iptr;
	char *	progname;

	switch ( Context.Form->language ) {
		case	_GENERATE_BAL	:
		case	_GENERATE_ABAL	:
			break;
		default			:
			return(0);
		}

	if ( Context.Form->isprogram ) {
		if (!( progname = allocate_string( fptr->prodname )))
			return(27);
		else if (!( progname = enforce_extension(progname,AT_EXTENSION)))
			return(27);
		else	add_project_package_item( progname, 0 );
		}

	if ( method_is_valid(fptr->stylesheet) ) { 
		add_project_package_item(allocate_string(fptr->stylesheet),0);
		}

	for (	iptr=fptr->first;
		iptr != (struct form_item*) 0;
		iptr = iptr->next ) {
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_BUTTON_FRAME	:
				switch ( iptr->Contents.align & 7 ) {
					case	1 :	
					case	3 : break;
					default	  : continue;
					}
			case	_IMAGE_FRAME	:
				if (( method_is_valid( iptr->Contents.payload ) ) 
				&&  ( *iptr->Contents.payload != _UNQUOTED_STRING )) {
					add_project_package_item(allocate_string(iptr->Contents.payload),1);
					}
				continue;
			}
		}
	return(0);
}

public	char * 	forms_template_selection(struct form_control * fptr, int nature)
{
	struct	form_item * iptr;
	char		  * rptr=(char*)0;
	char		  * wptr=(char*)0;
	for (	iptr=fptr->first;
		iptr != (struct form_item*) 0;
		iptr = iptr->next ) {
		if ((iptr->Contents.style & _FRAME_TYPE) != nature)
			continue;
		if (!( iptr->Contents.name ))
			continue;
		if (!( rptr ))
			rptr = allocate_string( iptr->Contents.name );
		else if ((wptr = allocate( strlen( rptr ) + strlen(iptr->Contents.name) + 8)) != (char *) 0) {
			sprintf(wptr,"%s|%s",rptr,iptr->Contents.name);
			liberate(rptr);
			rptr =wptr;
			}
		}
	return(rptr);
}

public	int	use_forms_template_selection(struct form_control * fptr, int nature, int item)
{
	int	i=0;
	struct	form_item * iptr;
	for (	iptr=fptr->first;
		iptr != (struct form_item*) 0;
		iptr = iptr->next ) {
		if ((iptr->Contents.style & _FRAME_TYPE) != nature)
			continue;
		else if (!( iptr->Contents.name ))
			continue;
		else if ( i == item ) {
			Context.TemplateWidget = iptr;
			return(i);
			}
		else	i++;
		}
	return(-1);
}

int	select_form_member( char * wptr )
{
	struct	form_control * fptr;
	struct	form_item    * iptr;
	struct	forms_method * mptr;
	char *	optr=wptr;
	char *	nptr=wptr;

	/* --------------------------- */
	/* Reset the call back context */
	/* --------------------------- */
	ResetFormZoom();
	if (!( wptr  ))	
		return(0);
	else if (!( *wptr )) 
		return(0);
	else if (!( fptr = Context.Form ))
		return(0);

	/* detect object.method type expression */
	/* ------------------------------------ */
 	while ( *wptr != 0 ) { if ( *wptr == '.' ) break; else	wptr++; }

	/* Determine expression type */
	/* ------------------------- */
	if ( *wptr == '.' )  { 	*(wptr++) = 0; nptr = wptr; 		}
	else		     {  nptr = optr;   optr = (char *) 0;	}

	/* Arrival here with :	optr -> widget name, nptr method name or optr null */
	/* ----------------------------------------------------------------------- */
	if ( optr ) {
		/* Detect named widget member */
		/* -------------------------- */
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next ) {
			if (!( iptr->Contents.name ))
				continue;
			else if ( string_compare( iptr->Contents.name , optr ) )
				break;
			}
		if (!( iptr ))	return(0);		
		else	{
			FormZoom.action = nptr;
			FormZoom.widget = iptr;
			FormZoom.nature=1;
			return(_EDIT_RESOLVE);
			}
		}
	else	{
		/* Detect named forms Method */
		/* ------------------------- */
		for (	mptr = fptr->rootmethod; 
			mptr != (struct forms_method *) 0;
			mptr = mptr->next ) {
			if (!( mptr->name ))
				continue;
			else if ( string_compare( mptr->name , nptr ) )
				break;
			}
		if (!( mptr ))	return(0);		
		else	{
			FormZoom.method = mptr;
			FormZoom.nature=2;
			return(_EDIT_RESOLVE);
			}
		}

}

#ifdef	ABAL32A
public	void	load_form_styling(struct form_control * fptr )
{
	char	*	sptr;
	if ( fptr->styling ) {
		if ((sptr = allocate_string( fptr->prodname )) !=(char *) 0) {
			if (( sptr = enforce_extension( sptr, CSS_EXTENSION )) != (char *) 0) {
				load_visual_style(sptr,strlen(sptr));
				liberate( sptr );
				}
			}			
		}
	return;
}

#include "singcomp.c"

#endif	/* ABAL32A */

int visual_initialise(int mode)	{ return(0); }
int visual_liberate()		{ return(0); }

public struct SpecificWidgetProperties *get_form_widgetProperties()
{
	return(&form_widgetProperties);
}

private	int	help_portion_length( char * mptr )
{
	int	i=0;
	for (i=0; *(mptr+i) != 0; i++ )
		if ( *(mptr+i) == '\n' )
			break;
	return(i);
}

#ifndef ABALCPP	/* GWB le 18/06/2007 */
#define AIDE_EN_LIGNE
#endif
#ifdef	AIDE_EN_LIGNE
public void aide_en_ligne(int x,int y,int h,char *mptr)
{
	int	l;
	int 	i;
	int	n;
	int	w=0;
	int	fh=16;
	int	fw=8;
	unsigned char *msg;
	if (!( mptr ))
		return;
	else if (visual_event(2) !=_MIMO_RIGHT)
		return;
	else	{
		/* calculate longest message line */
		/* ------------------------------ */
		for (msg=mptr,i=0; i<h; i++) {
			l = help_portion_length(msg);
			if ( w < l ) w = l;
			if (!( *(msg+l) ))
				break;
			else	msg += (l+1);
			}
		/* calculate and draw popup message frame */
		/* -------------------------------------- */
		w *= fw;
		if ( x < 7 ) { x = 7; }
		if ( y < 5 ) { y = 5; }
		visual_filzone(x-7,y-5,w+fw+6,(h*fh)+10,3598,0);
		visual_filzone(x-5,y-3,w+fw+2,(h*fh)+6,27,13);
		visual_filzone(x-4,y-2,w+fw,(h*fh)+4,27,13);

		/* display message lines */
		/* --------------------- */
		for (msg=mptr,i=0; i<h; i++) {
			if ((l = help_portion_length(msg)) > 0) {
				visual_text(x,y,w,fh,vfh1,27,14,msg,l,0);
				}
			y += fh;
			if (!( *(msg+l) ))
				break;
			else	msg += (l+1);
			}

		/* Await mouse up event */
		/* -------------------- */
		while ((visual_getch()==256) && ((visual_event(1) & _MIMO_UP) !=_MIMO_UP));

		/* Redisplay widget properties */
		/* --------------------------- */
		accept_widget_properties_show(widget_properties_context);
		return;
		}
}
#endif

private	int	HelpTextLines=0;
private	char **	HelpTextArray=(char**) 0;

public	int	get_helpline_count()
{
	return( HelpTextLines );
}

public	void	get_helptext_line( int l, char * nptr, int nlen, char * tptr, int tlen )
{
	char *	sptr;
	int	i;
	memset(nptr,' ',nlen);
	memset(tptr,' ',tlen);
	if ( l <= 0 )
		return;
	else if ( l > HelpTextLines ) 
		return;
	else if (!(sptr = HelpTextArray[l-1]))
		return;
	else	{
		sprintf(nptr,"%u",l);
		for (i=0; i < tlen; i++ )
			if (!( *(tptr+i) = *(sptr+i) ))
				break;
		return;
		}
}

private	int	use_popup_scroller(char *mptr[],int h)
{
	HelpTextLines = h;
	HelpTextArray = mptr;
	accept_visual_popup();
	HelpTextLines = 0;
	HelpTextArray = (char **) 0;
	return(0);
}


public int	visual_online_help(char *mptr[],int h)
{
	void * 	vb=(void *)0;
	int	fg;
	int	bg;
	int	x;
	int	y;
	int	zy;
	int	zx;
	int	zw;
	int	zh;
	int	l;
	int 	i;
	int	n;
	int	w=0;
	int	fh=16;
	int	sfh=0;
	int	fw=8;
	unsigned char *msg;
	if (!( mptr ))
		return(0);
	else if (visual_event(2) !=_MIMO_RIGHT)
		return(0);
	else if ( h > 20 )
		return( use_popup_scroller( mptr, h ) );
	else if  (!(fw = guifontsize(Context.basefont)))
		return(0);
	else	{
		fh = (fw >> 8); fw &= 0x00FF;

		/* calculate longest message line */
		/* ------------------------------ */
		for (i=0; i < h; i++ ) {
			if (mptr[i])
				l = strlen(mptr[i]);
			else	l = 0;
			if ( w < l ) w = l;
			}			

		/* calculate and draw popup message frame */
		/* -------------------------------------- */
		w *= fw;
		
		while(1) {

			x = visual_event(7);
			y = visual_event(6);
			if ( x < 7 ) { x = 7; }
			if ( y < 5 ) { y = 5; }

			x+=20; y+=25;

			if (!( sfh = resolve_style_fontheight( "widget_help_text" ) ))
				sfh = fh;

			zx = (x-7);    zy = (y-5);
			zw = (w+fw+6); zh = ((h*sfh)+10);

			if ((zx+zw) > x_conf(69) ) { zx = ((x_conf(69) - zw)-7); }
			if ((zy+zh) > x_conf(68) ) { zy = ((x_conf(68) - zh)-5); }

			/* whoops too much helptext */
			/* ------------------------ */
			if (( zx < 0 ) || ( zy < 0 )) { break; }
		
			if (!( vb )) {
				vb = visual_buffer(zx,zy,zw,zh);
				}
			if ( vb != (void *) 0) {
				visual_buffer_get(vb,zx,zy);
				}

			hide();
			if ( visual_element(zx,zy,zw,zh,_STYLE_HELP_FRAME," ",0) != 0) {
				fg = 27; bg=14;
				visual_filzone(zx,zy,zw,zh,3598,0);
				visual_filzone(zx+2,zy+2,zw-4,zh-4,fg,13);
				visual_filzone(zx+3,zy+3,zw-6,zh-6,fg,13);
				}
			else	{
				fg = 16;
				bg = 0;
				}

			/* display message lines */
			/* --------------------- */
			y = zy;

			for ( i=0; i<h; i++) {
				if (( mptr[i] !=(char *) 0)
				&&  ((l = strlen( mptr[i] )) != 0)) {
					if ( visual_element(zx+7,zy+5,w,sfh,_STYLE_HELP_TEXT,mptr[i],l) != 0) {
						visual_text(zx+7,zy+5,w,sfh,Context.basefont,fg,bg,mptr[i],l,0);
						}
					}
				zy += sfh;
				}

			show(zx,y,zw,zh);

			/* Await mouse up event */
			/* -------------------- */
			if ((visual_getch()==256)
			&&  ((visual_event(1) & _MIMO_UP) ==_MIMO_UP))
				break;
			else if ( vb ) {
				visual_buffer_put(vb,zx,y);
				}
			}

		/* Redisplay widget properties */
		/* --------------------------- */
		if ( vb != (void *) 0) {
			visual_buffer_put(vb,zx,y);
			visual_drop(vb);
			}

		return(1);
		}
}

#endif	/* _singform_c */



