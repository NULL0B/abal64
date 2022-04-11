#ifndef	_singLASER_c
#define	_singLASER_c

#define	_EXT_PROTO	".lsh"
#define	_EXT_LSR 	".xsr"
#define	_EXT_MP4 	".mp4"
#define	_EXT_SVG 	".svg"
#define	_BUTTON_PRESS	'BP'

#define	_FOCUS_MANAGER	"focusManager"
#define	_INPUT_MANAGER	"inputManager"
#define	_THIS_INSTANCE	"tHiS"

#define	_TOGGLE_PREFIX	"toggle_"
#define	_FOCUS_PREFIX	"focus_"
#define	_SHOW_PREFIX	"show_"
#define	_HIDE_PREFIX	"hide_"
#define	_LOSE_PREFIX	"lose_"
#define	_SENSOR_PREFIX	"sensor_"
#define	_TRIGGER_PREFIX	"trigger_"
#define	_PRESS_PREFIX	"press_"

#define	_PATTERN_PREFIX	"pattern_"
#define	_FORM_SUFFIX	"_form"
#define	_PAGE_SUFFIX	"_page"
#define	_LOCAL_PREFIX	"local_"

#define	_BUTTON_PREFIX	"button_"
#define	_OVERLAY_PREFIX	"overlay_"
#define	_MODULE_PREFIX	"module_"
#define	_WIDGET_PREFIX	"widget_"
#define	_BUFFER_PREFIX	"buffer_"
#define	_VALUE_PREFIX	"value_"
#define	_FRAME_PREFIX	"frame_"

#define	_CICO_PREFIX	"cico_"
#define	_KEYDOWN_PREFIX	"keydown_"
#define	_KEYUP_PREFIX	"keyup_"
#define	_ACTDOWN_PREFIX	"actdown_"


#define	_SVG_NAMESPACE		"http://www.w3.org/2000/svg"
#define	_XLINK_NAMESPACE	"http://www.w3.org/1999/xlink"
#define	_EVENT_NAMESPACE	"http://www.w3.org/2001/xml-events"
#define	_SAF_NAMESPACE		"urn:mpeg:mpeg4:SAF:2005"
#define	_LASER_NAMESPACE	"urn:mpeg:mpeg4:LASeR:2005"

static	struct	laser_configuration {
	int	keepAmpersand;		/* switch allowing ampersand in buttons to disappear	*/
	int	groupId;		/* counts the group elements generated			*/
	int	useRef;			/* activate ref and id generation			*/
	int	useSaf;			/* activate SAF Production 				*/
	int	useLaser;		/* activate LASER Specific Production.			*/
	int	testData;		/* activate display of edit and table test data		*/
	int	withComments;		/* comments are added to closures for debug of source 	*/
	int	externProto;		/* extern Proto definitions are used if nesting works	*/
	int	indentSource;		/* allows indentation of generated source.		*/

	int	keySensor;
	int	KeySensorID;		/* the Key Sensor ID value when generated.		*/
	int	KeySensorOD;		/* The Key Sensor Object ID value when generated	*/

	int	stringSensor;
	int	StringSensorID;		/* the Key Sensor ID value when generated.		*/
	int	StringSensorOD;		/* The Key Sensor Object ID value when generated	*/

	int	fontWidth;		/* The overall font width of a widget under processing	*/
	int	fontHeight;		/* The overall font height of a widget under processing	*/

	int	primary;		/* initial primary objec tdescriptor			*/
	int	od;			/* OD ID distribution counter				*/
	int	es;			/* ES ID distribution counter				*/

	int	editField;		/* Edit Field Counter					*/

	int	width;			/* width of production window.				*/
	int	height;			/* the height of the production window			*/

	int	AudioLevel;		/* level of preference for audio profiles 255		*/
	int	VisualLevel;		/* level of preference for visual profiles 255		*/
	int	SceneLevel;		/* level of preference for scene profiles 255		*/
	int	GraphicsLevel;		/* level of preference for graphic profiles 255		*/
	int	ODLevel;		/* level of preference for OD profiles 255		*/

	struct	proto_item * protoHeap;	/* the list of defined PROTO descriptions.		*/
	
	char *	safNs;			/* the SAF name space 					*/
	char *	laserNs;		/* the LASeR name space					*/
	char *	svgNs;			/* the SVG name space					*/

	int	genMp4;			/* generate for mp4					*/
	int	reserved2;		/* reserved in the interface for future use		*/
	int	reserved3;		/* reserved in the interface for future use		*/
	int	reserved4;		/* reserved in the interface for future use		*/

	} LC = 	{ 
		1,
		0,			/* Group Id counter 					*/

		0,			/* Ref production in addition to Id			*/
		0,			/* SAF production					*/
		1,			/* LASeR production					*/

		0, 0, 0, 1,		/* options : data, comments, protos, indent		*/

		1,			/* use key sensor 	*/
		0,0,			/* key sensor infos	*/

		0,			/* use string sensor 	*/
		0,0,			/* string sensor infos	*/

		0,0,			/* font information	*/

		0,0,0,			/* OD and ES counters	*/

		0,			/* Edit Field Counter 	*/

		800,600,		/* default dimensions	*/

		254,254,254,254,254, 	/* default profiles	*/

		(struct proto_item *) 0,

		(char *) 0, (char *) 0, (char *) 0,	/* the three name spaces */

		0,0,0,0			/* 4 reserved values */

		};

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ m p e g _ p r o d u c t i o n 		*/
/*	-----------------------------------------------------------------------	*/
/*	this function sets the productino window sizes used to calculate widget */
/*	position information using Transform/translation nodes.			*/
/*	-----------------------------------------------------------------------	*/
void	laser_mpeg_production()
{
	mpeg_production( LC.width, LC.height );
	return;
}

char *	laser_enforce_extension( char * nptr )
{
	if ( LC.genMp4 )
		return( enforce_extension( nptr, _EXT_MP4 ) );
	else if ( LC.useSaf )
		return( enforce_extension( nptr, _EXT_LSR ) );
	else	return( enforce_extension( nptr, _EXT_SVG ) );
}

void	laser_input_streams()
{
	/* --------------------------------------- */
	/* Elementary Stream : Key Sensor Infos    */
	/* --------------------------------------- */
	LC.primary = ++LC.od;

	if ( LC.keySensor )
	{
		LC.KeySensorID = ++LC.es;			
		LC.KeySensorOD = ++LC.od;			
	}
	else if ( LC.stringSensor )
	{
		LC.StringSensorID = ++LC.es;			
		LC.StringSensorOD = ++LC.od;			
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		   e x c h a n g e _ m p e g _ p r o d u c t i o n 		*/
/*	-----------------------------------------------------------------------	*/
/*	this function is called to allow the swap of the production dimensions	*/
/*	of the form production window for the production of nested components	*/
/*	the size of the object production window is crucial for the calculation	*/
/*	of the translation of its center for correct positioning.		*/
/*	-----------------------------------------------------------------------	*/
void	laser_exchange_mpeg_production( struct window_control * wptr )
{
	int	v;
	v = wptr->w;
	wptr->w = LC.width;
	LC.width = v;
	v = wptr->h;
	wptr->h = LC.height;
	LC.height = v;
	laser_mpeg_production();
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			      a d d _ p r o t o _ i t e m			*/
/*	-----------------------------------------------------------------------	*/
/*	this function provides PROTO definition shadow list handling to avoid	*/
/*	multiple generation of forms proto definitions.				*/
/*	-----------------------------------------------------------------------	*/
int	laser_add_proto_item( char * nptr )
{
	struct	proto_item * pptr;
	for (	pptr=LC.protoHeap;
		pptr != (struct proto_item *) 0;
		pptr = pptr->next )
	{
		if (!( pptr->name ))
			continue;
		else if (!( strcmp( pptr->name, nptr ) ))
			return(0);
		else	continue;
	}
	if (!( pptr = allocate( sizeof( struct proto_item ) ) ))
		return(0);
	else if (!( pptr->name = allocate_string( nptr ) ))
		return( 0 );
	else
	{
		pptr->next = LC.protoHeap;
		LC.protoHeap = pptr;
		return(1);
	}
}

/*	-----------------------------------------------------------------------	*/
/*				d r o p _ p r o t o _ h e a p			*/
/*	-----------------------------------------------------------------------	*/
/*	releases the shadow list of PROTO definitions upon completion of the BT	*/
/*	productino operation.
/*	-----------------------------------------------------------------------	*/
void	laser_drop_proto_heap()
{
	struct	proto_item * pptr;
	while ((pptr=LC.protoHeap) != (struct proto_item *) 0)
	{
		LC.protoHeap = pptr->next;
		if ( pptr->name )
			liberate( pptr->name );
		liberate( pptr );
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ i n d e n t    			*/
/*	-----------------------------------------------------------------------	*/
/*	this function controls inclusion of source indenting which ioncreases 	*/
/*	file size and so may be inhibited to optimise for transmission source.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_indent( FILE * h )
{
	if ( LC.indentSource )
		mpeg_indent( h );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ c o m m e n t  			*/
/*	-----------------------------------------------------------------------	*/
/*	this function generates comment messages when allowed by configuration	*/
/*	-----------------------------------------------------------------------	*/
void	laser_comment( FILE * h, char * message )
{
	int	l;
	int	i;
	if ( LC.withComments )
	{
		if (( message )
		&&  ((l = strlen(message)) != 0))
		{
			if ( LC.indentSource ) { laser_indent( h ); }
			fprintf(h,"<-- ");
			for ( i=0; i < l; i++)
				fprintf(h,"-");
			fprintf(h," -->\n");

			if ( LC.indentSource ) { laser_indent( h ); }
			fprintf(h,"<-- %s -->\n",message);

			if ( LC.indentSource ) { laser_indent( h ); }
			fprintf(h,"<-- ");
			for ( i=0; i < l; i++)
				fprintf(h,"-");
			fprintf(h," -->\n");
		}
	}	
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ o p e n _ t a g			*/
/*	-----------------------------------------------------------------------	*/
/*	this function generates a LASeR open tag open with eventual object name */
/*	eventual indentation control.						*/
/*	-----------------------------------------------------------------------	*/
void	laser_open_tag( FILE * h, char * nptr )
{
	laser_indent(h);
	fprintf(h,"<%s",nptr);
	mpeg_enter();
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ c l o s e _ t a g			*/
/*	-----------------------------------------------------------------------	*/
/*	generates an xml close tag for the provided name			*/
/*	-----------------------------------------------------------------------	*/
void	laser_close_tag( FILE * h, char * nptr )
{
	mpeg_leave();
	laser_indent(h);
	fprintf(h,"</%s>",nptr);
	if ( LC.withComments )
		if ( nptr )
			fprintf(h," # %s",nptr);
	fprintf(h,"\n");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ e n d _ t a g			*/
/*	-----------------------------------------------------------------------	*/
/*	closes an open tag ready for child components.				*/
/*	-----------------------------------------------------------------------	*/
void	laser_end_tag( FILE * h, int v )
{
	fprintf(h,">\n");
	if ( v )
		laser_close_tag( h, "empty" );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ t a g				*/
/*	-----------------------------------------------------------------------	*/
/*	opens a laser scene tag ready for child component addition.		*/
/*	-----------------------------------------------------------------------	*/
void	laser_tag( FILE * h, char * nptr )
{
	laser_open_tag(h,nptr);
	laser_end_tag(h,0);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ d e f _ t a g			*/
/*	-----------------------------------------------------------------------	*/
/*	generates a laser tag with the id set to the provided name.		*/
/*	-----------------------------------------------------------------------	*/
void	laser_def_tag( FILE * h, char * nptr, char * xptr )
{
	laser_indent(h);
	fprintf(h,"<%s id=%c%s%c ",nptr,0x0022,xptr,0x0022);
	laser_end_tag(h,0);
	mpeg_enter();
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ w i d g e t _ g r o u p			*/
/*	-----------------------------------------------------------------------	*/
/*	opens a laser scene group tag.						*/
/*	-----------------------------------------------------------------------	*/
void	laser_widget_group( FILE * h, struct form_item * iptr )
{
	if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
	{
		laser_indent(h);
		fprintf(h,"<g id=%c%s%s%c visibility=%c%s%c>\n",
			0x0022,_WIDGET_PREFIX,iptr->Contents.name,0x0022,
			0x0022,"hidden",0x0022);
		mpeg_enter();
	}
	else
	{
		laser_indent(h);
		fprintf(h,"<g id=%c%s%s%c visibility=%c%s%c>\n",
			0x0022,_WIDGET_PREFIX,iptr->Contents.name,0x0022,
			0x0022,"inherit",0x0022);
		mpeg_enter();
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		   l a s e r _ w i d g e t _ e d i t _ g r o u p		*/
/*	-----------------------------------------------------------------------	*/
/*	opens a laser scene group tag for edit widgets with focus launch.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_widget_edit_group( FILE * h, struct form_item * iptr )
{
	if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
	{
		laser_indent(h);
		fprintf(h,"<g id=%c%s%s%c activate=%c%s('%s%u_%s')%c visibility=%c%s%c>\n",
			0x0022,_WIDGET_PREFIX,iptr->Contents.name,0x0022,
			0x0022,_FOCUS_MANAGER,_BUFFER_PREFIX,++LC.editField,iptr->Contents.name,0x0022,
			0x0022,"hidden",0x0022);
		mpeg_enter();
	}
	else
	{
		laser_indent(h);
		fprintf(h,"<g id=%c%s%s%c activate=%c%s('%s%u_%s')%c visibility=%c%s%c>\n",
			0x0022,_WIDGET_PREFIX,iptr->Contents.name,0x0022,
			0x0022,_FOCUS_MANAGER,_BUFFER_PREFIX,++LC.editField,iptr->Contents.name,0x0022,
			0x0022,"inherit",0x0022);
		mpeg_enter();
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			     l a s e r _ g r o u p  				*/
/*	-----------------------------------------------------------------------	*/
/*	opens a laser scene widget group tag.					*/
/*	-----------------------------------------------------------------------	*/
void	laser_group( FILE * h )
{
	laser_tag(h,"g");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			     l a s e r _ g r o u p e n d 			*/
/*	-----------------------------------------------------------------------	*/
/*	closes a laser scene widget group tag.					*/
/*	-----------------------------------------------------------------------	*/
void	laser_groupend( FILE * h )
{
	laser_close_tag(h,"g");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ t o u c h _ s e n s o r			*/
/*	-----------------------------------------------------------------------	*/
/*	generates a touch sensor for mouse activity event capture for use by 	*/
/*	interactive widgets edit, check, radio, switch, select, tab and scroll	*/
/*	depreciated ... this came from bifs and will be removed.		*/
/*	-----------------------------------------------------------------------	*/
void	laser_touch_sensor( FILE * h, char * nptr )
{
	laser_indent(h);
	fprintf(h,"DEF %s%s %s {}\n",_SENSOR_PREFIX,nptr,"TouchSensor");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ m o u s e _ s e n s o r			*/
/*	-----------------------------------------------------------------------	*/
/*	generates a touch sensor for mouse activity event capture for use by 	*/
/*	interactive widgets edit, check, radio, switch, select, tab and scroll	*/
/*	-----------------------------------------------------------------------	*/
void	laser_mouse_sensor( FILE * h, struct form_item * iptr, char * eventname )
{
	laser_indent(h);
	fprintf(h,"<ev:listener event=%c%s%c handler=%c#%s%s%c/>\n",
			0x0022,eventname,0x0022,
			0x0022,_TRIGGER_PREFIX,iptr->Contents.name,0x0022);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ c l i c k _ s e n s o r			*/
/*	-----------------------------------------------------------------------	*/
void	laser_click_sensor( FILE * h, struct form_item * iptr )
{
	laser_mouse_sensor(h,iptr,"click");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		    l a s e r _ m o u s e _ o v e r _ s e n s o r		*/
/*	-----------------------------------------------------------------------	*/
void	laser_mouse_over_sensor( FILE * h, struct form_item * iptr )
{
	laser_mouse_sensor(h,iptr,"mouseover");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		     l a s e r _ m o u s e _ o u t _ s e n s o r		*/
/*	-----------------------------------------------------------------------	*/
void	laser_mouse_out_sensor( FILE * h, struct form_item * iptr )
{
	laser_mouse_sensor(h,iptr,"mouseout");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	 			l a s e r _ e d i t _ r o u t e			*/
/*	-----------------------------------------------------------------------	*/
/*	generates a ROUTE instruction for the indicated edit field widget to be	*/
/*	able to distribute the edit field focus item.				*/
/*	depreciated ... this came from bifs and will be removed.		*/
/*	-----------------------------------------------------------------------	*/
void	laser_edit_route( FILE * h, struct form_item * iptr )
{
	return;
	laser_indent(h);
	fprintf(h,"ROUTE %s%s.isActive TO %s%s.activate\n",
		_SENSOR_PREFIX,iptr->Contents.name,
		_TRIGGER_PREFIX,iptr->Contents.name);
	laser_indent(h);
	fprintf(h,"ROUTE %s%s.outSFInt32 TO %s%s.getch\n",
		_KEYDOWN_PREFIX,iptr->Contents.name,_CICO_PREFIX,iptr->Contents.name);
	laser_indent(h);
	fprintf(h,"ROUTE %s%s.outSFInt32 TO %s%s.cursor\n",
		_ACTDOWN_PREFIX,iptr->Contents.name,_CICO_PREFIX,iptr->Contents.name);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ i n p u t _ r o u t e			*/
/*	-----------------------------------------------------------------------	*/
/*	generates routing of Key Input Sensor Events to the Key Echo StringNode	*/
/*	depreciated ... this came from bifs and will be removed.		*/
/*	-----------------------------------------------------------------------	*/
void	laser_input_route( FILE * h, struct form_control * fptr )
{
	return;
	laser_indent(h);
	fprintf(h,"ROUTE CiKeyDown.outSFInt32 TO CICO.getch\n");
	laser_indent(h);
	fprintf(h,"ROUTE CiActionDown.outSFInt32 TO CICO.cursor\n");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			       l a s e r _ t a b _ r o u t e 			*/
/*	-----------------------------------------------------------------------	*/
/*	depreciated ... this came from bifs and will be removed.		*/
/*	-----------------------------------------------------------------------	*/
void	laser_tab_route( FILE * handle, struct form_item * iptr )
{
	struct	form_control * fptr;
	return;
	if (!( fptr = iptr->parent ))
		return;
	laser_indent(handle);
	fprintf(handle,"ROUTE %s%s.isActive TO %s%s.activate\n",
		_SENSOR_PREFIX,iptr->Contents.name,
		_TRIGGER_PREFIX,iptr->Contents.name);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ c h e c k _ r o u t e			*/
/*	-----------------------------------------------------------------------	*/
/*	depreciated ... this came from bifs and will be removed.		*/
/*	-----------------------------------------------------------------------	*/
void	laser_check_route( FILE * handle, struct form_item * iptr )
{
	return;
	laser_indent(handle);
	fprintf(handle,"ROUTE %s%s.isActive TO %s%s.activate\n",
		_SENSOR_PREFIX,iptr->Contents.name,
		_TRIGGER_PREFIX,iptr->Contents.name);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ r a d i o _ r o u t e			*/
/*	-----------------------------------------------------------------------	*/
/*	depreciated ... this came from bifs and will be removed.		*/
/*	-----------------------------------------------------------------------	*/
void	laser_radio_route( FILE * handle, struct form_item * iptr )
{
	return;
	laser_indent(handle);
	fprintf(handle,"ROUTE %s%s.isActive TO %s%s.activate\n",
		_SENSOR_PREFIX,iptr->Contents.name,
		_TRIGGER_PREFIX,iptr->Contents.name);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ s w i t c h _ r o u t e			*/
/*	-----------------------------------------------------------------------	*/
/*	depreciated ... this came from bifs and will be removed.		*/
/*	-----------------------------------------------------------------------	*/
void	laser_switch_route( FILE * handle, struct form_item * iptr )
{
	return;
	laser_indent(handle);
	fprintf(handle,"ROUTE %s%s.isActive TO %s%s.activate\n",
		_SENSOR_PREFIX,iptr->Contents.name,
		_TRIGGER_PREFIX,iptr->Contents.name);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ s c r o l l _ r o u t e			*/
/*	-----------------------------------------------------------------------	*/
/*	depreciated ... this came from bifs and will be removed.		*/
/*	-----------------------------------------------------------------------	*/
void	laser_scroll_route( FILE * handle, struct form_item * iptr )
{
	return;
	laser_indent(handle);
	fprintf(handle,"ROUTE %s%s.isActive TO %s%s.activate\n",
		_SENSOR_PREFIX,iptr->Contents.name,
		_TRIGGER_PREFIX,iptr->Contents.name);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ f i e l d				*/
/*	-----------------------------------------------------------------------	*/
/*	generates a standard node field.					*/
/*	-----------------------------------------------------------------------	*/
void	laser_field( FILE * h, char * nptr, char * vptr )
{
	laser_indent(h);
	fprintf(h,"%s %s\n",nptr, vptr);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_is_field( FILE * h, char * nptr, char * vptr )
{
	laser_indent(h);
	fprintf(h,"%s IS %s\n",nptr, vptr);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ e v e n t - i n			*/
/*	-----------------------------------------------------------------------	*/
/*	generates an eventIn field member					*/
/*	-----------------------------------------------------------------------	*/
void	laser_event_in( FILE * h, char * nptr, char * tptr )
{
	laser_indent(h);
	fprintf(h,"eventIn %s %s\n",tptr, nptr);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ e v e n t - o u t 			*/
/*	-----------------------------------------------------------------------	*/
/*	generates an eventOut field member					*/
/*	-----------------------------------------------------------------------	*/
void	laser_event_out( FILE * h, char * nptr, char * tptr )
{
	laser_indent(h);
	fprintf(h,"eventOut %s %s\n",tptr, nptr);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_quoted( FILE * h, char * nptr, char * vptr )
{
	laser_indent(h);
	fprintf(h,"%s %c%s%c\n",nptr, 0x0022,vptr,0x0022);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ s t r i n g				*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_string( FILE * h, char * nptr, char * vptr )
{
	laser_indent(h);
	fprintf(h,"%s %c",nptr,0x0022);
	while ( *vptr )
	{
		if ( *vptr != '&' )
			fprintf(h,"%c",*vptr);
		vptr++;
	}
	fprintf(h,"%c\n",0x0022);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			   l a s e r _ t e x t _ s t r i n g			*/
/*	-----------------------------------------------------------------------	*/
/*	generates a text string for push buttons in particular removing andsign */
/*	-----------------------------------------------------------------------	*/
void	laser_text_string( FILE * h, char * vptr )
{
	while ( *vptr )
	{
		switch ( *vptr )
		{
		case	'&'	: 
			if ( LC.keepAmpersand )
				fprintf(h,"&amp;"); 
			break;
		case	'<'	: fprintf(h,"&lt;");  break;
		case	'>'	: fprintf(h,"&gt;");  break;
		default		: fprintf(h,"%c",*vptr);
		}
		vptr++;
	}
	return;
}

/*	----------------------------------------	*/
/*	    l a s e r _ s t r i n g _ p a i r 		*/
/*	----------------------------------------	*/
/*	used for text alignment or justification 	*/
/*	----------------------------------------	*/
void	laser_string_pair( FILE * h, char * nptr, char * vptr, char * wptr )
{
	laser_indent(h);
	fprintf(h,"%s [ %c%s%c %c%s%c ]\n",nptr, 0x0022,vptr,0x0022, 0x0022,wptr,0x0022);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_integer_field( FILE * h, char * nptr, int vptr )
{
	char	value[32];
	sprintf(value,"%d",vptr);
	laser_field(h,nptr,value);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ v e c t o r _ 2 d _ f i e l d			*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_vector_2d_field( FILE * h, char * nptr, int x, int y )
{
	char	value[64];
	sprintf(value,"%d %d",x,y);
	laser_field(h,nptr,value);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_vector_3d_field( FILE * h, char * nptr, int x, int y,int z )
{
	char	value[96];
	sprintf(value,"%d %d %d",x,y,z);
	laser_field(h,nptr,value);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_collection( FILE * h, char * nptr )
{
	laser_indent(h);
	fprintf(h,"<%s>\n",nptr);
	mpeg_enter();
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_close_collection( FILE * h, char * nptr )
{
	laser_indent(h);
	fprintf(h,"</%s>",nptr);
	if ( LC.withComments )
		fprintf(h," # %s",nptr);
	fprintf(h,"\n");
	mpeg_leave();
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_end_collection( FILE * h, int v )
{
	if ( v )
		laser_close_collection( h, "empty" );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_background( FILE * h, int colour )
{
	char	work[1024];
	laser_colour( (colour & 0x00FF) , work);
	laser_tag(h,"Background");
		laser_field(h,"skyColor",work);
	laser_close_tag(h,"Background");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ o d _ u r l 				*/
/*	-----------------------------------------------------------------------	*/
/*	generates an object descriptor type url if the od parameter is not zero	*/
/*	-----------------------------------------------------------------------	*/
void	laser_od_url( FILE * h, char * nptr, int od )
{
	char	work[8192];
	if (!( od ))
	{
		if ( nptr )
		{
			sprintf(work,"[ %c%s%c ]",0x0022,nptr,0x0022);
			laser_field(h,"url",work);
		}
	}
	else
	{
		sprintf(work,"[ %cod:%u%c ]",0x0022,od,0x0022);
		laser_field(h,"url",work);
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_background2d( FILE * h, int colour,char * member )
{
	char	work[1024];
	if ( member )
		sprintf( work,"%s Background2D",member);
	else	strcpy(work,"Background2D");
	laser_tag(h,work);
		laser_colour( (colour & 0x00FF) , work);
		laser_field(h,"backColor",work);
	laser_close_tag(h,"Background2D");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ w o r l d i n f o			*/
/*	-----------------------------------------------------------------------	*/
/*	generates the world info tag with copyright and other gnerator details.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_worldinfo( FILE * h, char * info, char * title )
{
	char	work[1024];
	laser_tag(h,"WorldInfo");
		laser_string_pair(h,"info",info,"Copyright (c) Amenesik / Sologic");
		laser_string(h,"title",title);
	laser_close_tag(h,"WorldInfo");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ s t a n d a r d _ i n p u t			*/
/*	-----------------------------------------------------------------------	*/
/*	generates the standard input handling mechanisms that will dispatch key	*/
/*	information to the appropriate edit filed input buffer.			*/
/*	-----------------------------------------------------------------------	*/

#define	_LASER_BACKSPACE_KEY	 8
#define	_LASER_ENTER_KEY		13
#define	_LASER_END_KEY		14
#define	_LASER_PAGEUP_KEY	15
#define	_LASER_PAGEDOWN_KEY	16
#define	_LASER_UP_KEY		17
#define	_LASER_DOWN_KEY		18
#define	_LASER_LEFT_KEY		19
#define	_LASER_RIGHT_KEY		20
#define	_LASER_ESCAPE_KEY	27
#define	_LASER_INSERT_KEY	45
#define	_LASER_DELETE_KEY	46

void	laser_standard_input( FILE * h )
{
	return;
}

void	laser_set( FILE * h, char * pptr, char * eptr, char * aptr, char * vptr )
{
	laser_indent(h);
	fprintf(h,"<set xlink:href=%c#%s%s%c",0x0022,pptr,eptr,0x0022);
	fprintf(h," attributeName=%c%s%c",0x0022,aptr,0x0022);
	fprintf(h," to=%c%s%c/>\n",0x0022,vptr,0x0022);
	return;
}

void	laser_set_int( FILE * h, char * pptr, char * eptr, char * aptr, int v )
{
	laser_indent(h);
	fprintf(h,"<set xlink:href=%c#%s%s%c",0x0022,pptr,eptr,0x0022);
	fprintf(h," attributeName=%c%s%c",0x0022,aptr,0x0022);
	fprintf(h," to=%c%u%c/>\n",0x0022,v,0x0022);
	return;
}

void	laser_replace( FILE * h, char * pptr, char * eptr, char * aptr, char * vptr )
{
	if ( LC.useLaser )
	{
		laser_indent(h);
		fprintf(h,"<lsr:Replace ref=%c%s%s%c",0x0022,pptr,eptr,0x0022);
		fprintf(h," attributeName=%c%s%c",0x0022,aptr,0x0022);
		fprintf(h," value=%c%s%c/>\n",0x0022,vptr,0x0022);
	}
	return;
}

void	laser_replace_target( FILE * h, char * pptr, char * eptr, char * aptr, char * vptr )
{
	if ( LC.useLaser )
	{
		laser_indent(h);
		fprintf(h,"<lsr:Replace ref=%c%s%s%c",0x0022,pptr,eptr,0x0022);
		fprintf(h," attributeName=%c%s%c",0x0022,aptr,0x0022);
		fprintf(h," value=%c#%s%c/>\n",0x0022,vptr,0x0022);
	}
	return;
}

void	laser_replace_int( FILE * h, char * pptr, char * eptr, char * aptr, int v )
{
	if ( LC.useLaser )
	{
		laser_indent(h);
		fprintf(h,"<lsr:Replace ref=%c%s%s%c",0x0022,pptr,eptr,0x0022);
		fprintf(h," attributeName=%c%s%c",0x0022,aptr,0x0022);
		fprintf(h," value=%c%u%c/>\n",0x0022,v,0x0022);
	}
	return;
}

void	laser_add( FILE * h, char * pptr, char * eptr, char * aptr, char * vptr )
{
	if ( LC.useLaser )
	{
		laser_indent(h);
		fprintf(h,"<lsr:Add ref=%c%s%s%c",0x0022,pptr,eptr,0x0022);
		fprintf(h," attributeName=%c%s%c",0x0022,aptr,0x0022);
		fprintf(h," value=%c%s%c/>\n",0x0022,vptr,0x0022);
	}
	return;
}

void	laser_add_int( FILE * h, char * pptr, char * eptr, char * aptr, int v )
{
	if ( LC.useLaser )
	{
		laser_indent(h);
		fprintf(h,"<lsr:Add ref=%c%s%s%c",0x0022,pptr,eptr,0x0022);
		fprintf(h," attributeName=%c%s%c",0x0022,aptr,0x0022);
		fprintf(h," value=%c%u%c/>\n",0x0022,v,0x0022);
	}
	return;
}

void	laser_key_sensor( FILE * h, char * name )
{
	return;
}

void	laser_string_sensor( FILE * h, char * name )
{
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ c o l o u r				*/
/*	-----------------------------------------------------------------------	*/
/*	generates a laser RGB triad for colour description.			*/
/*	-----------------------------------------------------------------------	*/
void	laser_colour( int x, char * bptr )
{
	int	r=0;
	int	g=0;
	int	b=0;
	get_rgb_values(x,&r,&g,&b);	
	sprintf(bptr,"rgb(%u,%u,%u)",r,g,b);
	return;

}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ f i l z o n e			*/
/*	-----------------------------------------------------------------------	*/
/*	draws and fills the rectangle of the provided dimensions unless zero	*/
/*	-----------------------------------------------------------------------	*/
void	laser_filzone( FILE * handle, int x, int y, int w, int h, int colour )
{
	char	work[1024];

	/* transparent is not rendered */
	/* --------------------------- */
	if (!( colour )) 
		return;
	// ----------------------------
	// generate coloured rectanlgle
	// ----------------------------
	laser_colour( (colour & 0x00FF) , work);
	bifs_indent( handle );
	fprintf(handle,"<rect x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c fill=%c%s%c/>\n",
		0x0022,x,0x0022,
		0x0022,y,0x0022,
		0x0022,w,0x0022,
		0x0022,h,0x0022,
		0x0022,work,0x0022 );

	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ f r a m e z o n e			*/
/*	-----------------------------------------------------------------------	*/
/*	draws the rectangle frame of the provided dimensions unless zero	*/
/*	-----------------------------------------------------------------------	*/
void	laser_framezone( FILE * handle, int x, int y, int w, int h, int colour, char * name )
{
	char	work[1024];

	/* transparent is not rendered */
	/* --------------------------- */
	if (!( colour )) 
		return;
	// ----------------------------
	// generate coloured rectanlgle
	// ----------------------------
	laser_colour( (colour & 0x00FF) , work);
	bifs_indent( handle );
	fprintf(handle,"<rect x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c fill='none' stroke=%c%s%c/>\n",
		0x0022,x,0x0022,
		0x0022,y,0x0022,
		0x0022,w,0x0022,
		0x0022,h,0x0022,
		0x0022,work,0x0022 );

	return;
}

/*	-----------------------------------------------------------------------	*/
/*			   l a s e r _ r o u n d e d _ f i l l			*/
/*	-----------------------------------------------------------------------	*/
/*	draws and fills the rounded rectangle of the provided dimensions 	*/
/*	-----------------------------------------------------------------------	*/
void	laser_rounded_fill( FILE * handle, int x, int y, int w, int h, int colour, char * name )
{
	char	work[1024];

	/* transparent is not rendered */
	/* --------------------------- */
	if (!( colour )) 
		return;
	// ----------------------------
	// generate coloured rectanlgle
	// ----------------------------
	laser_colour( (colour & 0x00FF) , work);
	bifs_indent( handle );
	fprintf(handle,"<rect x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c rx=%c%u%c fill=%c%s%c/>\n",
		0x0022,x,0x0022,
		0x0022,y,0x0022,
		0x0022,w,0x0022,
		0x0022,h,0x0022,
		0x0022,(w < h ? w/4 : h/4),0x0022,
		0x0022,work,0x0022 );

	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ r o u n d e d _ f r a m e 			*/
/*	-----------------------------------------------------------------------	*/
/*	draws the rounded frame of the provided dimensions unless colour zero	*/
/*	-----------------------------------------------------------------------	*/
void	laser_rounded_frame( FILE * handle, int x, int y, int w, int h, int colour, char * name )
{
	char	work[1024];

	/* transparent is not rendered */
	/* --------------------------- */
	if (!( colour )) 
		return;
	// ----------------------------
	// generate coloured rectanlgle
	// ----------------------------
	laser_colour( (colour & 0x00FF) , work);
	bifs_indent( handle );
	fprintf(handle,"<rect x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c rx=%c%u%c fill='none' stroke=%c%s%c/>\n",
		0x0022,x,0x0022,
		0x0022,y,0x0022,
		0x0022,w,0x0022,
		0x0022,h,0x0022,
		0x0022,(w < h ? w/4 : h/4),0x0022,
		0x0022,work,0x0022 );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ f o c u s z o n e			*/
/*	-----------------------------------------------------------------------	*/
/*	just like filzone for the moment.					*/
/*	-----------------------------------------------------------------------	*/
void	laser_focuszone( FILE * handle, int x, int y, int w, int h, int colour, char * name )
{
	char	work[1024];

	/* transparent is not rendered */
	/* --------------------------- */
	if (!( colour )) 
		return;

	// ----------------------------
	// generate coloured rectanlgle
	// ----------------------------
	laser_colour( (colour & 0x00FF) , work);
	bifs_indent( handle );
	fprintf(handle,"<rect x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c fill=%c%s%c/>\n",
		0x0022,x,0x0022,
		0x0022,y,0x0022,
		0x0022,w,0x0022,
		0x0022,h,0x0022,
		0x0022,work,0x0022 );

	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ c i r c l e				*/
/*	-----------------------------------------------------------------------	*/
/*	draws and fills a curcle.						*/
/*	-----------------------------------------------------------------------	*/
void	laser_circle( FILE * handle, int x, int y, int w, int h, int colour,  char * name )
{
	char	bwork[1024];
	char	fwork[1024];

	// ------------------------
	// generate coloured circle 
	// ------------------------
	laser_colour( (colour & 0x00FF) , fwork);
	bifs_indent( handle );
	fprintf(handle,"<circle cx=%c%u%c cy=%c%u%c r=%c%u%c fill=%c%s%c/>\n",
		0x0022,x+(w/2),0x0022,
		0x0022,y+(h/2),0x0022,
		0x0022,(w < h ? w/2 : h/2),0x0022,
		0x0022,fwork,0x0022); 
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ f r a m e c i r c l e			*/
/*	-----------------------------------------------------------------------	*/
/*	draws and a circle frame .						*/
/*	-----------------------------------------------------------------------	*/
void	laser_framecircle( FILE * handle, int x, int y, int w, int h,  int border, char * name )
{
	char	bwork[1024];
	char	fwork[1024];

	// ------------------------
	// generate coloured circle 
	// ------------------------
	laser_colour( (border & 0x00FF) , bwork);
	bifs_indent( handle );
	fprintf(handle,"<circle cx=%c%u%c cy=%c%u%c r=%c%u%c fill='none' stroke=%c%s%c/>\n",
		0x0022,x+(w/2),0x0022,
		0x0022,y+(h/2),0x0022,
		0x0022,(w < h ? w/2 : h/2),0x0022,
		0x0022,bwork,0x0022 );
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ d r a w _ r e l i e f			*/
/*	-----------------------------------------------------------------------	*/
/*	draws a relief frame and eventual background if not transparent.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_draw_relief(FILE * h, int atx,int aty, int nbx, int nby, int hl, int bg, int ll,char * name )
{
	if ( bg != transparent )
		laser_filzone(h,atx,aty,nbx,nby,bg);
	laser_filzone(h,atx,aty,nbx,1,hl);
	laser_filzone(h,atx,aty,1,nby,hl);
	laser_filzone(h,(atx+nbx),aty,1,nby,ll);
	laser_filzone(h,atx,(aty+nby),nbx,1,ll);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ r e l i e f				*/
/*	-----------------------------------------------------------------------	*/
/*	draws a specific frame type.						*/
/*	-----------------------------------------------------------------------	*/
void	laser_relief( FILE * handle, int atx, int aty, int nbx, int nby, int style, char * name )
{
	int	bg;

	if (( nbx > 0 ) && ( nby > 0 )) {

	switch (( style & _FRAME_TYPE )) {

		case	_RADIO_FRAME :
			laser_circle(handle, atx,aty,nbx,nby,standard_black,(char *) 0);
			laser_circle(handle, atx+1,aty+1,nbx-2,nby-2,standard_white,(char *) 0);
			break;

		case	_EDIT_FRAME :
			laser_draw_relief(handle, atx,aty,nbx,nby,standard_black,standard_white,standard_black,name);
			break;

		case	_OUTSET_FRAME :
			laser_draw_relief(handle, atx,aty,nbx,nby,standard_hilight,standard_backwash,standard_lolight,(char *) 0);
			break;

		case	_BUTTON_FRAME :
			laser_draw_relief(handle, atx,aty,nbx,nby,standard_hilight,standard_backwash,standard_lolight,name);
			break;

		case	_BUTTON_PRESS :
			laser_draw_relief(handle, atx,aty,nbx,nby,standard_lolight,standard_backwash,standard_hilight,(char *) 0);
			break;

		case	_WINDOW_FRAME :
			laser_draw_relief(handle, atx,aty,nbx,nby,standard_hilight,standard_backwash,standard_lolight,(char *) 0);
			break;

		case	_SCROLL_FRAME  :
			laser_draw_relief(handle, atx,aty,nbx,nby,standard_lolight,standard_backwash-1,standard_hilight,name);
			break;

		case	_INSET_FRAME  :
			laser_draw_relief(handle, atx,aty,nbx,nby,standard_lolight,standard_backwash,standard_hilight,(char *) 0);
			break;

		case	_RIDGE_FRAME  :
			laser_draw_relief(handle, atx,aty,nbx,nby,standard_hilight,standard_backwash,standard_lolight,(char *) 0);
			if (( nbx > 2 ) && ( nby > 2 )) 
				laser_draw_relief(handle,(atx+1),(aty+1),(nbx-2),(nby-2),standard_lolight,transparent,standard_hilight,(char *) 0);
			break;

		case	_GROOVE_FRAME :
			transparent = transparent;
			laser_draw_relief(handle, atx,aty,nbx,nby,standard_lolight,standard_backwash,standard_hilight,(char *) 0);
			if (( nbx > 2 ) && ( nby > 2 )) 
				laser_draw_relief(handle, (atx+1),(aty+1),(nbx-2),(nby-2),standard_hilight,transparent,standard_lolight,(char *) 0);
			break;

		}
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ j u s t i f y				*/
/*	-----------------------------------------------------------------------	*/
/*	generates the text justification matrix of string values for text nodes	*/
/*	-----------------------------------------------------------------------	*/
void	laser_justify( FILE * handle, int align )
{

	switch ( align & 0x000F)
	{
		case	_A_NONE	:
		case	_A_LEFT	:
			laser_string_pair(handle,"justify","FIRST","MIDDLE");
			break;
		case	_A_CENTER	:
		case	_A_JUSTIFY	:
			laser_string_pair(handle,"justify","MIDDLE","MIDDLE");
			break;
		case	_A_RIGHT	:
			laser_string_pair(handle,"justify","END","MIDDLE");
			break;
	}
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ a l i g n				*/
/*	-----------------------------------------------------------------------	*/
/*	generates the text justification matrix of string values for text nodes	*/
/*	-----------------------------------------------------------------------	*/
int	laser_align( char * result, int align, int x, int w )
{

	switch ( align & 0x000F )
	{
		case	_A_CENTER	:
			strcpy(result,"middle");
			x += (w/2);
			break;
		case	_A_JUSTIFY	:
			strcpy(result,"middle");
			x += (w/2);
			break;
		case	_A_RIGHT	:
			strcpy(result,"end");
			x += w;
			break;
		case	_A_NONE	:
		case	_A_LEFT	:
		default		:
			strcpy(result,"start");
			break;
	}
	return(x);
}

/*	-----------------------------------------------------------------------	*/
/*			  l a s e r _ d e c o r a t i o n			*/
/*	-----------------------------------------------------------------------	*/
/*	generates the optional text decoration bold, underline and italic.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_decoration( char * result, int align )
{
	*result = 0;
	if ( align & _A_BOLD )
		strcat(result,"font-weight='bold'");
	else	strcat(result,"font-weight='normal'");

	if ( align & _A_LINE )
		strcat(result," text-decoration='underline'");
	else if ( align & _A_BAR )
		strcat(result," text-decoration='overline'");
	else if ( align & _A_STRIKE )
		strcat(result," text-decoration='line-through'");

	if ( align & _A_SHADOW )
		strcat(result," font-style='italic'");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ t e x t				*/
/*	-----------------------------------------------------------------------	*/
/*	generates a laser text element with alignment colour and font infos	*/
/*	-----------------------------------------------------------------------	*/
void	laser_text( FILE * handle, int x, int y, int w, int h, char * mptr, int colour, int align )
{
	int	fheight=0;
	char	work[1024];
	char	awork[256];
	char	dwork[512];
	// --------------------------------
	// generate translation to position
	// --------------------------------
	laser_colour( (colour & 0x00FF) , work);
	x = laser_align( awork, align, x, w );
	laser_decoration( dwork, align );
	bifs_indent( handle );
	fheight = ((LC.fontHeight * 4) / 5);
	fprintf(handle,"<text x=%c%u%c y=%c%u%c font-size=%c%u%c %s text-anchor=%c%s%c fill=%c%s%c>\n",
		0x0022,x,0x0022,
		0x0022,y+((LC.fontHeight*5)/6),0x0022,
		0x0022,fheight,0x0022,
		dwork,
		0x0022,awork,0x0022,
		0x0022,work,0x0022);
	mpeg_enter();
	bifs_indent( handle );
	laser_text_string( handle, mptr );
	fprintf(handle,"\n");
	laser_close_tag(handle,"text");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			      l a s e r _ t e x t _ v a l u e			*/
/*	-----------------------------------------------------------------------	*/
/*	this function is called from by laser edit widget production function to	*/
/*	define and connect the text value buffer for use by the standard editor	*/
/*	text input mechanism, and also to receive an eventual parameter whcih 	*/
/*	may have been provided via the instance expression.			*/
/*	-----------------------------------------------------------------------	*/
void	laser_text_value( FILE * handle, int x, int y, int w, int h, char * mptr, int colour, int align, char * nptr )
{
	char* interactive="false";
	int	fheight=0;
	char	work[1024];
	char	awork[256];
	char	dwork[512];
	if (!( nptr ))
		laser_text( handle, x,y,w,h,mptr, colour, align );
	else
	{
		laser_colour( (colour & 0x00FF) , work);
		x = laser_align( awork, align, x, w );
		laser_decoration( dwork, align );
		bifs_indent( handle );
		fheight = ((LC.fontHeight * 4) / 5);
		interactive = "true";
		fprintf(handle,"<text id=%c%s%u_%s%c x=%c%u%c y=%c%u%c font-size=%c%u%c %s text-anchor=%c%s%c fill=%c%s%c focusable = %c%s%c editable=%c%s%c visibility='visible'>\n",
			0x0022,_BUFFER_PREFIX,LC.editField,nptr,0x0022,
			0x0022,x,0x0022,
			0x0022,y+((LC.fontHeight*5)/6),0x0022,
			0x0022,fheight,0x0022,
			dwork,
			0x0022,awork,0x0022,
			0x0022,work,0x0022,
			0x0022,interactive,0x0022,
			0x0022,interactive,0x0022);
		mpeg_enter();
		bifs_indent( handle );
		laser_text_string( handle, mptr );
		fprintf(handle,"\n");
		laser_close_tag(handle,"text");
		return;
	}
}

/*	-----------------------------------------------------------------------	*/
/*			     s i n g _ s v g _ i m a g e			*/
/*	-----------------------------------------------------------------------	*/
/*	generates an svg image component.					*/
/*	-----------------------------------------------------------------------	*/
void	sing_svg_image( FILE * handle, int x, int y, int w, int h, char * iptr,char * nptr, int option )
{
	switch ( option & 0x000F )
	{
	case	_A_NONE	:
		laser_indent(handle);
		fprintf(handle,"<image x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c xlink:href=%c%s%c/>\n", 
			0x0022,x,0x0022,
			0x0022,y,0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,iptr,0x0022
			);
		break;
	case	_A_LEFT	:
		laser_indent(handle);
		fprintf(handle,"<image preserveAspectRatio='xMinYMid slice' x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c xlink:href=%c%s%c/>\n", 
			0x0022,x,0x0022,
			0x0022,y,0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,iptr,0x0022
			);
		break;
	case	_A_RIGHT:
		laser_indent(handle);
		fprintf(handle,"<image preserveAspectRatio='xMaxYMid slice' x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c xlink:href=%c%s%c/>\n", 
			0x0022,x,0x0022,
			0x0022,y,0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,iptr,0x0022
			);
		break;
	case	_A_CENTER:
		laser_indent(handle);
		fprintf(handle,"<image preserveAspectRatio='xMidYMid slice' x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c xlink:href=%c%s%c/>\n", 
			0x0022,x,0x0022,
			0x0022,y,0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,iptr,0x0022
			);
		break;
	case	_I_MAKEFIT	:
		laser_indent(handle);
		fprintf(handle,"<image preserveAspectRatio='none' x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c xlink:href=%c%s%c/>\n", 
			0x0022,x,0x0022,
			0x0022,y,0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,iptr,0x0022
			);
		break;
	case	_I_BESTFIT	:
		laser_indent(handle);
		fprintf(handle,"<image preserveAspectRatio='xMidYMid meet' x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c xlink:href=%c%s%c/>\n", 
			0x0022,x,0x0022,
			0x0022,y,0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,iptr,0x0022
			);
		break;
	case	_I_TILE		:
		laser_indent(handle);
			fprintf(handle,"<rect x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c fill=%curl(#%s%s)%c/>\n", 
			0x0022,x,0x0022,
			0x0022,y,0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,_PATTERN_PREFIX,nptr,0x0022
			);
		break;
	}

	return;
}

/*	-----------------------------------------------------------------------	*/
/*			     s i n g _ s v g _ v i d e o 			*/
/*	-----------------------------------------------------------------------	*/
/*	generates a video component.						*/
/*	-----------------------------------------------------------------------	*/
void	sing_svg_video( FILE * handle, int x, int y, int w, int h, char * iptr, int option )
{
	laser_indent(handle);
	fprintf(handle,"<video x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c",
 
		0x0022,x,0x0022,
		0x0022,y,0x0022,
		0x0022,w,0x0022,
		0x0022,h,0x0022);

	if ( option & _A_LINE )
	{
		fprintf(handle," repeatCount=%c%s%c",0x0022,"indefinite",0x0022);
	}
	fprintf(handle," xlink:href=%c%s%c/>\n",0x0022,iptr,0x0022);

	return;
}

/*	-----------------------------------------------------------------------	*/
/*			     s i n g _ s v g _ a u d i o	 		*/
/*	-----------------------------------------------------------------------	*/
/*	generates an audio component.						*/
/*	-----------------------------------------------------------------------	*/
void	sing_svg_audio( FILE * handle, char * iptr, char * nptr, int option )
{
	laser_indent(handle);
	fprintf(handle,"<audio volume=%c0.7%c",0x0022,0x0022);
	if ( option & _A_LINE )
	{
		fprintf(handle," repeatCount=%c%s%c",0x0022,"indefinite",0x0022);
	}
	fprintf(handle," xlink:href=%c%s%c/>\n",0x0022,iptr,0x0022);

	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ i m a g e				*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_image( FILE * handle, int x, int y, int w, int h, char * iptr, char * name, int option )
{

		if (( detect_extension( iptr, ".png"  ) )
		||  ( detect_extension( iptr, ".jpg"  ) )
		||  ( detect_extension( iptr, ".jpeg" ) )
		||  ( detect_extension( iptr, ".gif"  ) )
		||  ( detect_extension( iptr, ".bmp"  ) ))
		{
			sing_svg_image( handle, x,y,w,h, iptr, name, option );
		}
		else if (( detect_extension( iptr, ".ogg"  ) )
		     ||  ( detect_extension( iptr, ".wav"  ) )
		     ||  ( detect_extension( iptr, ".aif"  ) )
		     ||  ( detect_extension( iptr, ".aiff" ) )
		     ||  ( detect_extension( iptr, ".mp3"  ) ))
		{
			sing_svg_audio( handle, iptr, name, option );
		}
		else
		{
			sing_svg_video( handle, x,y,w,h, iptr, option );
		}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ o p e n _ s w i t c h			*/
/*	-----------------------------------------------------------------------	*/
/*	starts the production of a named switch/selector mechanisms with value	*/
/*	-----------------------------------------------------------------------	*/
void	laser_open_switch(FILE * h, char * nptr, int value )
{
	if ( LC.useLaser )
	{
		laser_indent(h);
		fprintf(h,"<lsr:selector id=%c%s%c",0x0022,nptr,0x0022);
		if ( LC.useRef )
		{
			fprintf(h," ref=%c%s%c",0x0022,nptr,0x0022);
		}	
		fprintf(h," choice=%c%u%c>\n",0x0022,value,0x0022);
		mpeg_enter();
	}
	return;
}
/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ c l o s e _ s w i t c h			*/
/*	-----------------------------------------------------------------------	*/
/*	closes the names switch/selector construction opened above.		*/
/*	-----------------------------------------------------------------------	*/
void	laser_close_switch(FILE * h)
{
	if ( LC.useLaser )
	{
		laser_close_tag(h,"lsr:selector");
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_checkbox( FILE * handle, int x, int y, int w, int h, char * mptr, struct form_item * iptr )
{
	char 	work[1024];

	laser_comment(handle,"table check sensor");
	laser_click_sensor(handle,iptr);
	laser_comment(handle,"table check box frame");
	laser_relief( handle, x,y,LC.fontHeight,LC.fontHeight, _EDIT_FRAME, (char *) 0);

	laser_comment(handle,"table check message");
	laser_text( handle, x+(2*LC.fontHeight),y,w-(2*LC.fontHeight),h, mptr, standard_black, _A_LEFT);
	sprintf(work,"VALUE_%s",iptr->Contents.name);
	laser_comment(handle,"table check value");
	laser_open_switch( handle, work,0 );
		laser_filzone(handle,x+3,y+3,LC.fontHeight-6,LC.fontHeight-6,standard_white);
		laser_filzone(handle,x+3,y+3,LC.fontHeight-6,LC.fontHeight-6,standard_black);
	laser_close_switch(handle);
	laser_comment(handle,"table check trigger");
	laser_toggle_conditional(handle,iptr);

	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_switch( FILE * handle, int x, int y, int w, int h, char * mptr, struct form_item * iptr )
{
	char 	work[1024];
	int	fg;
	int	bg;
	fg = (iptr->Contents.colour & 0x00FF);
	bg = ((iptr->Contents.colour >> 8) & 0x00FF);
	laser_comment(handle,"table switch sensor");
	laser_click_sensor(handle,iptr);
	laser_comment(handle,"table switch frame");
	laser_relief( handle, x,y,w,h, _INSET_FRAME, (char *) 0);
	sprintf(work,"VALUE_%s",iptr->Contents.name);
	laser_open_switch( handle, work,0 );

		/* false value */
		laser_comment(handle,"table switch false value");
		laser_group(handle);
			laser_filzone(handle,x+2,y+2,w-4,h-4,bg);
			laser_text( handle, x+2,y+2,w-4,h-4, mptr, fg,_A_CENTER);
		laser_close_tag(handle,"g");

		laser_comment(handle,"table switch true value");
		laser_group(handle);	
			laser_filzone(handle,x+2,y+2,w-4,h-4,fg);
			laser_text( handle, x+2,y+2,w-4,h-4,mptr, bg,_A_CENTER);
		laser_close_tag(handle,"g");

	laser_close_switch(handle);
	laser_comment(handle,"table switch trigger");
	laser_toggle_conditional(handle,iptr);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_radiobox( FILE * handle, int x, int y, int w, int h, char * mptr, struct form_item * iptr )
{
	char 	work[1024];
	laser_comment(handle,"table radio sensor");
	laser_click_sensor(handle,iptr);
	laser_comment(handle,"table radio frame");
	laser_relief( handle, x,y,LC.fontHeight,LC.fontHeight, _RADIO_FRAME,(char *) 0);
	laser_comment(handle,"table radio message");
	laser_text( handle, x+(2*LC.fontHeight),y,w-(2*LC.fontHeight),h, mptr, standard_black, _A_LEFT);
	sprintf(work,"VALUE_%s",iptr->Contents.name);
	laser_comment(handle,"table radio value");
	laser_open_switch( handle, work,0 );
		laser_circle(handle,x+3,y+3,LC.fontHeight-6,LC.fontHeight-6,standard_white,(char *) 0);
		laser_circle(handle,x+3,y+3,LC.fontHeight-6,LC.fontHeight-6,standard_black,(char *) 0);
	laser_close_switch(handle);
	laser_comment(handle,"table radio trigger");
	laser_toggle_conditional(handle,iptr);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ b u t t o n				*/
/*	-----------------------------------------------------------------------	*/
/*	generates a standard pushbutton type widget				*/
/*	-----------------------------------------------------------------------	*/
void	laser_button( FILE * handle, int x, int y, int w, int h, char * message, char * name, int align, int style )
{
	char * framename[1024];
	sprintf(framename,"%s%s",_FRAME_PREFIX,name);
	if ( align & 1 ) // is image
	{
		if ( align & 2 ) // no frame
		{
			laser_comment(handle,"image button");
			laser_image( handle, x,y,w,h, message, framename, align );
		}
		else
		{
			laser_comment(handle,"framed image button");
			laser_relief( handle, x,y,w,h, style, name);
			laser_image( handle, x+2,y+2,w-4,h-4, message, framename, align );
		}
	}
	else
	{
		if (!( align & 2 )) // has frame
		{
			laser_comment(handle,"framed text button");
			laser_relief( handle, x,y,w,h, style, name);
			laser_text( handle, x+2,y+8,w-4,h-4, message, standard_text,_A_CENTER);
		}
		else
		{
			laser_comment(handle,"text button");
			laser_text( handle, x,y,w,h, message, standard_text,_A_CENTER);
		}
	}
}

/*	-----------------------------------------------------------------------	*/
/*		l a s e r _ i n s t a n c e _ l a u n c h e r s			*/
/*	-----------------------------------------------------------------------	*/
laser_instance_popups(FILE * h, struct form_control * fptr)
{
	struct	form_item * iptr;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style != _BUTTON_FRAME )
			continue;
		else if ( iptr->Contents.datatype == _WIDGET_OVERLAY )
			laser_popup_launcher(h,iptr,1);
		else if ( iptr->Contents.datatype == _WIDGET_MODULE )
			laser_popup_launcher(h,iptr,0);
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ p u s h b u t t o n			*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_pushbutton( FILE * h, struct form_item * iptr )
{
	int	isanchor=0;
	LC.keepAmpersand=0;
	switch ( iptr->Contents.datatype )
	{
	case _WIDGET_OVERLAY :
		laser_comment(h,"overlay button link");
		laser_popup(h,iptr,1);
		return;

	case _WIDGET_MODULE  :
		laser_comment(h,"module button link");
		laser_popup(h,iptr,0);
		return;

	case _WIDGET_CHAIN   :
	case _WIDGET_SYSTEM  :
	case _WIDGET_TASK    :
	case _WIDGET_LOADGO  :
		laser_comment(h,"chain, loadgo button link");
		isanchor = laser_anchor(h,iptr->Contents.format );
		break;		
	}
	laser_button(
		h,
		iptr->Contents.x, iptr->Contents.y, 
		iptr->Contents.w, iptr->Contents.h, 
		abal_payload( iptr ),
		( iptr->Contents.name  ? iptr->Contents.name : (char *) 0),
		iptr->Contents.align, _BUTTON_FRAME
		);

	if ( isanchor )
	{
		laser_close_tag(h,"a");
	}
	LC.keepAmpersand=1;
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ d e f s _ h e a d e r			*/
/*	-----------------------------------------------------------------------	*/
/*	opens a definition block and named group.				*/
/*	-----------------------------------------------------------------------	*/
void	laser_defs_header( FILE * handle, char * prefix, char * suffix )
{
	char	work[1024];
	laser_tag( handle, "defs");
	if ( suffix )
		sprintf(work,"g id='%s%s'",prefix,suffix);
	else if ( prefix )
		sprintf(work,"g id='%s'",prefix);
	else	strcpy(work,"g");
	laser_tag( handle, work );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ d e f s _ f o o t e r			*/
/*	-----------------------------------------------------------------------	*/
/*	close a definition block and named group.				*/
/*	-----------------------------------------------------------------------	*/
void	laser_defs_footer( FILE * handle )
{
	laser_close_tag(handle,"g");
	laser_close_tag(handle,"defs");
	return;
}

/*	--------------------------------------------------------	*/
/*		      l a s e r _ o p e n _ p r o t o 			*/
/*	--------------------------------------------------------	*/
/*	generates an open  useage instance of a particular defs		*/
/*	--------------------------------------------------------	*/
void	laser_open_proto_use( FILE * h, int x, int y, char * cname, char * iname)
{
	laser_indent(h);
	fprintf(h,"<use x=%c%u%c y=%c%u%c xlink:href=%c#%s%c id=%c%s%c>\n",
		0x0022,x,0x0022,
		0x0022,y,0x0022,
		0x0022,cname,0x0022,
		0x0022,iname,0x0022);
	mpeg_enter();
	return;
}

/*	--------------------------------------------------------	*/
/*		      l a s e r _ o p e n _ p r o t o 			*/
/*	--------------------------------------------------------	*/
/*	generates an open  useage instance of a particular defs		*/
/*	--------------------------------------------------------	*/
void	laser_use_activate( FILE * h, int x, int y, char * cname, char * iname,char * tname)
{
	laser_indent(h);
	fprintf(h,"<use activate=%c%s%c x=%c%u%c y=%c%u%c xlink:href=%c#%s%c id=%c%s%c/>\n",
		0x0022,tname,0x0022,
		0x0022,x,0x0022,
		0x0022,y,0x0022,
		0x0022,cname,0x0022,
		0x0022,iname,0x0022);
	return;
}


/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ t a b _ b u t t o n				*/
/*	-----------------------------------------------------------------------	*/
/*	generates a tab button construction which comprises :			*/
/*		the unpressed button is visible except the first		*/
/*		the pressed button is hidden except the first			*/
/*	-----------------------------------------------------------------------	*/
void	laser_tab_button( FILE * handle, struct form_item * iptr )
{
	struct	form_control * fptr;
	char	work[1024];
	char	iwork[1024];
	char	twork[1024];
	int	fh = guifontsize(iptr->Contents.font);
	int	fw = (fh & 0x00FF);

	fh >>= 8;
	fh &= 0x00FF;

	if (!( fptr = iptr->parent ))
		return;

	laser_widget_group(handle,iptr);

	laser_indent(handle);
	fprintf(handle,"<g id=%c%s%s%c visibility=%c%s%c>\n",
		0x0022,_LOSE_PREFIX,iptr->Contents.name,0x0022,
		0x0022,(iptr->Contents.page != 1 ? "visible" : "hidden"),0x0022);
		mpeg_enter();
		laser_button( handle, 
			iptr->Contents.x+iptr->Contents.adjust,
			iptr->Contents.y,
			iptr->Contents.xlimit,
			(fh + 8 ),
			abal_payload(iptr),
			iptr->Contents.name,
			0,_BUTTON_FRAME);

	laser_groupend(handle);

	laser_indent(handle);
	fprintf(handle,"<g id=%c%s%s%c visibility=%c%s%c>\n",
		0x0022,_PRESS_PREFIX,iptr->Contents.name,0x0022,
		0x0022,(iptr->Contents.page == 1 ? "visible" : "hidden"),0x0022);
		mpeg_enter();
		laser_button( handle, 
			iptr->Contents.x+iptr->Contents.adjust,
			iptr->Contents.y,
			iptr->Contents.xlimit,
			(fh + 8 ),
			abal_payload(iptr),
			iptr->Contents.name,
			0,_BUTTON_PRESS);

	laser_groupend(handle);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_open_script( FILE * handle )
{
	laser_indent(handle);
	fprintf(handle,"<script type=%c%s%c> <![CDATA[\n",0x0022,"application/ecmascript",0x0022);
	mpeg_enter();
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_close_script( FILE * handle )
{
	mpeg_leave();
	laser_indent(handle);
	fprintf(handle,"]]></script>\n");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_open_conditional( FILE * handle, char * nptr )
{
	char	work[1024];
	if ( LC.useLaser )
	{
		sprintf(work,"%s%s",_TRIGGER_PREFIX,nptr);
		laser_def_tag(handle,"lsr:conditional",work);
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_press_conditional( FILE * handle, char * nptr )
{
	char	work[1024];
	if ( LC.useLaser )
	{
		sprintf(work,"%s%s",_PRESS_PREFIX,nptr);
		laser_def_tag(handle,"lsr:conditional",work);
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_close_conditional( FILE * handle )
{
	if ( LC.useLaser )
	{
		laser_close_tag(handle,"lsr:conditional");
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		      l a s e r _ t a b _ c o n d i t i o n a l			*/
/*	-----------------------------------------------------------------------	*/
/*	this is used to handle tab page change operations for laser source.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_tab_conditional( FILE * handle, struct form_item * iptr,struct form_control * fptr )
{
	char	work[1024];
	struct	form_item * wptr;
	laser_open_conditional(handle,iptr->Contents.name);
		sprintf(work,"%s%s",_PRESS_PREFIX,iptr->Contents.name);
		laser_replace_target(handle,_BUTTON_PREFIX,iptr->Contents.name,"xlink:href",work);
		for ( 	wptr=fptr->first;
			wptr != (struct form_item *) 0;
			wptr = wptr->next )
		{
			if ( wptr->Contents.style != _TAB_FRAME )
				continue;
			else if ( wptr->Contents.page == iptr->Contents.page )
				continue;
			else
			{
				sprintf(work,"%s%s",_LOSE_PREFIX,wptr->Contents.name);
				laser_replace_target(handle,_BUTTON_PREFIX,wptr->Contents.name,"xlink:href",work);
			}
		}
		sprintf(work,"%s%s",_FRAME_PREFIX,iptr->Contents.name);
		laser_replace_target(handle,_FRAME_PREFIX,fptr->identifier,"xlink:href",work);
	laser_close_conditional(handle);
}

/*	-----------------------------------------------------------------------	*/
/*			       l a s e r _ t a b _ s c r i p t			*/
/*	-----------------------------------------------------------------------	*/
/*	this is used to handle tab page change operations for non laser source.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_tab_script( FILE * handle, struct form_item * iptr,struct form_control * fptr )
{
	int	items=0;
	struct	form_item * wptr;
	laser_open_script(handle);
		laser_indent(handle);
		fprintf(handle,"function %s%s(evt) {\n",_TRIGGER_PREFIX,iptr->Contents.name);
		mpeg_enter();
		laser_indent(handle);
		fprintf(handle,"var item = document.getElementById(%c%s%s%c);\n",
			0x0022,_BUTTON_PREFIX,iptr->Contents.name,0x0022);
		laser_indent(handle);
		fprintf(handle,"item.setAttribute(%cxlink:href%c,%c#%s%s%c);\n",
			0x0022,0x0022,
			0x0022,_PRESS_PREFIX,iptr->Contents.name,0x0022);
		for ( 	items=0,wptr=fptr->first;
			wptr != (struct form_item *) 0;
			wptr = wptr->next )
		{
			if ( wptr->Contents.style != _TAB_FRAME )
				continue;
			else if ( wptr->Contents.page == iptr->Contents.page )
				continue;
			else
			{
				laser_indent(handle);
				fprintf(handle,"var item%u = document.getElementById(%c%s%s%c);\n",
					++items,0x0022,_BUTTON_PREFIX,wptr->Contents.name,0x0022);
				laser_indent(handle);
				fprintf(handle,"item%u.setAttribute(%cxlink:href%c,%c#%s%s%c);\n",
					items,0x0022,0x0022,
					0x0022,_LOSE_PREFIX,wptr->Contents.name,0x0022);
			}
		}
		laser_indent(handle);
		fprintf(handle,"var fitem = document.getElementById(%c%s%s%c);\n",
			0x0022,_FRAME_PREFIX,fptr->identifier,0x0022);
		laser_indent(handle);
		fprintf(handle,"fitem.setAttribute(%cxlink:href%c,%c#%s%s%c);\n",
			0x0022,0x0022,
			0x0022,_FRAME_PREFIX,iptr->Contents.name,0x0022);
		mpeg_leave();
		laser_indent(handle);
		fprintf(handle,"}\n");
	laser_close_script(handle);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ c l o s e _ b r a c e			*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_close_brace(FILE * handle)
{
	mpeg_leave();
	laser_indent(handle);
	fprintf(handle,"}\n");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ s c r i p t _ e l s e			*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_script_else(FILE * handle)
{
	mpeg_leave();
	laser_indent(handle);
	fprintf(handle,"} else {\n");
	mpeg_enter();
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			   l a s e r _ f r a m e _ s c r i p t			*/
/*	-----------------------------------------------------------------------	*/
/*	this is used to handle the complete tab page change operation for a non */
/*	laser source. The single script receives the page number parameter and  */
/*	sets the tab system accordingly.					*/
/*	This is the optimised version that calculates all page button and frame	*/
/*	variable pointers once and for all allowing their simple use at each	*/
/*	subsequent page change instead of having to scan the list each time.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_frame_script( FILE * handle, struct form_control * fptr )
{
	int	items=0;
	struct	form_item * wptr;
	laser_open_script(handle);

		/* --------------------------------------------------------------- */
		/* create the page switching function using the prepared variables */
		/* --------------------------------------------------------------- */
		laser_indent(handle);
		fprintf(handle,"function %s%s(pageNumber) {\n",_TRIGGER_PREFIX,fptr->identifier);
		mpeg_enter();
		/* -------------------------------------------------------------------------- */
		/* Attempt to instance the variables to point to the various pages and frames */
		/* -------------------------------------------------------------------------- */
		laser_indent(handle);

		fprintf(handle,"var js%s%s = document.getElementById(%c%s%s%c);\n",
			_FRAME_PREFIX,fptr->identifier,
			0x0022,_FRAME_PREFIX,fptr->identifier,0x0022);

		for ( 	items=0,wptr=fptr->first;
			wptr != (struct form_item *) 0;
			wptr = wptr->next )
		{
			if ( wptr->Contents.style != _TAB_FRAME )
				continue;
			else
			{
				laser_indent(handle);
				fprintf(handle,"var js%s%s%u = document.getElementById(%c%s%s%c);\n",
					_BUTTON_PREFIX,fptr->identifier,
					wptr->Contents.page,
					0x0022,_BUTTON_PREFIX,wptr->Contents.name,0x0022);
			}
		}

		for ( 	items=0,wptr=fptr->first;
			wptr != (struct form_item *) 0;
			wptr = wptr->next )
		{
			if ( wptr->Contents.style != _TAB_FRAME )
				continue;
			else
			{
				laser_indent(handle);
				fprintf(handle,"if ( pageNumber == %u ) {\n",wptr->Contents.page);
				mpeg_enter();
					laser_indent(handle);
					fprintf(handle,"js%s%s%u.setAttribute(%cxlink:href%c,%c#%s%s%c);\n",
						_BUTTON_PREFIX,fptr->identifier,
						wptr->Contents.page,
						0x0022,0x0022,
						0x0022,_PRESS_PREFIX,wptr->Contents.name,0x0022);
					laser_indent(handle);
					fprintf(handle,"js%s%s.setAttribute(%cxlink:href%c,%c#%s%s%c);\n",
						_FRAME_PREFIX,fptr->identifier,
						0x0022,0x0022,
						0x0022,_FRAME_PREFIX,wptr->Contents.name,0x0022);
				laser_script_else( handle );
					laser_indent(handle);
					fprintf(handle,"js%s%s%u.setAttribute(%cxlink:href%c,%c#%s%s%c);\n",
						_BUTTON_PREFIX,fptr->identifier,
						wptr->Contents.page,
						0x0022,0x0022,
						0x0022,_LOSE_PREFIX,wptr->Contents.name,0x0022);
				laser_close_brace(handle);
			}
		}
		laser_close_brace(handle);
	laser_close_script(handle);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			   l a s e r _ f r a m e _ s c r i p t			*/
/*	-----------------------------------------------------------------------	*/
/*	this is used to handle the complete tab page change operation for a non */
/*	laser source. The single script receives the page number parameter and  */
/*	sets the tab system accordingly.					*/
/*	-----------------------------------------------------------------------	*/
void	slow_laser_frame_script( FILE * handle, struct form_control * fptr )
{
	int	items=0;
	struct	form_item * wptr;
	laser_open_script(handle);
		laser_indent(handle);
		fprintf(handle,"function %s%s(pageNumber) {\n",_TRIGGER_PREFIX,fptr->identifier);
		mpeg_enter();
		laser_indent(handle);
		fprintf(handle,"var currentFrame = document.getElementById(%c%s%s%c);\n",
			0x0022,_FRAME_PREFIX,fptr->identifier,0x0022);
		for ( 	items=0,wptr=fptr->first;
			wptr != (struct form_item *) 0;
			wptr = wptr->next )
		{
			if ( wptr->Contents.style != _TAB_FRAME )
				continue;
			else
			{
				laser_indent(handle);
				fprintf(handle,"var pageitem%u = document.getElementById(%c%s%s%c);\n",
					wptr->Contents.page,
					0x0022,_BUTTON_PREFIX,wptr->Contents.name,0x0022);

				laser_indent(handle);
				fprintf(handle,"if ( pageNumber == %u ) {\n",wptr->Contents.page);
				mpeg_enter();
				laser_indent(handle);
				fprintf(handle,"pageitem%u.setAttribute(%cxlink:href%c,%c#%s%s%c);\n",
					wptr->Contents.page,
					0x0022,0x0022,
					0x0022,_PRESS_PREFIX,wptr->Contents.name,0x0022);
				laser_indent(handle);
				fprintf(handle,"currentFrame.setAttribute(%cxlink:href%c,%c#%s%s%c);\n",
					0x0022,0x0022,
					0x0022,_FRAME_PREFIX,wptr->Contents.name,0x0022);
				laser_script_else( handle );
				laser_indent(handle);
				fprintf(handle,"pageitem%u.setAttribute(%cxlink:href%c,%c#%s%s%c);\n",
					wptr->Contents.page,
					0x0022,0x0022,
					0x0022,_LOSE_PREFIX,wptr->Contents.name,0x0022);
				laser_close_brace(handle);
			}
		}
		laser_close_brace(handle);
	laser_close_script(handle);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		    l a s e r _ t o g g l e _ c o n d i t i o n a l		*/
/*	-----------------------------------------------------------------------	*/
/*	this method is called for the generation of a conditional node which is	*/
/*	capable of toggling between two boolean values : true and false, called	*/
/*	to satisfy the needs of check, radio and switch widgets.		*/
/*	-----------------------------------------------------------------------	*/
void	laser_toggle_conditional( FILE * handle, struct form_item * iptr )
{
	char	work[1024];
	return;
	sprintf(work,"%s%s",_TRIGGER_PREFIX,iptr->Contents.name);
	laser_def_tag(handle,"Script", work );
		laser_indent(handle);
		fprintf(handle,"eventIn SFBool activate\n");
		laser_indent(handle);
		fprintf(handle,"field SFNode state USE VALUE_%s\n",iptr->Contents.name);
		laser_collection(handle,"url" );
		laser_indent(handle);
		fprintf(handle,"%cjavascript: function activate(value) { if ( value ) { if ( state.whichChoice ) { state.whichChoice = 0; } else { state.whichChoice = 1; } } }%c\n",0x0022,0x0022);
		laser_close_collection(handle,"url" );
	laser_close_tag( handle, "Script");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		    	l a s e r _ e d i t _ c o n d i t i o n a l		*/
/*	-----------------------------------------------------------------------	*/
/*	this method is called for the generation of a conditional node which is	*/
/*	capable of activation the corresponding data input mechanism, is called	*/
/*	to satisfy the needs of the edit ( and table ) widgets.			*/
/*	-----------------------------------------------------------------------	*/
void	laser_edit_conditional( FILE * handle, struct form_item * iptr )
{
	char	work[1024];
	if ( LC.useLaser )
	{
		sprintf(work,"%s%s",_TRIGGER_PREFIX,iptr->Contents.name);
		laser_def_tag(handle,"lsr:conditional", work );
			laser_replace(handle,_FOCUS_PREFIX,iptr->Contents.name,"enabled","1");
		laser_close_tag( handle, "lsr:conditional");
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		    	l a s e r _ e d i t _ f o c u s 				*/
/*	-----------------------------------------------------------------------	*/
/*	this method is called for the generation of a conditional node which is	*/
/*	capable of activation the corresponding data input mechanism, is called	*/
/*	to satisfy the needs of the edit ( and table ) widgets.			*/
/*	-----------------------------------------------------------------------	*/
void	laser_edit_focus( FILE * h, struct form_item * iptr )
{
	char	work[1024];
	struct	form_control * fptr;
	return;

	if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;

	sprintf(work,"%s%s",_TRIGGER_PREFIX,iptr->Contents.name);
	laser_def_tag(h,"Script", work );

	laser_indent(h);
	fprintf(h,"eventIn SFBool activate\n");
	laser_indent(h);
	fprintf(h,"field SFNode master USE %s%s\n",_LOSE_PREFIX,fptr->identifier);
	laser_indent(h);
	fprintf(h,"field SFNode manager USE %s%s\n",_FOCUS_PREFIX,iptr->Contents.name);

	laser_collection(h,"url");

	laser_indent(h);

	fprintf(h,"%cjavascript:\n",0x0022);

	/* ---------------------------------------------------------- */
	/* this function is called on the cascade down to clear focus */
	/* ---------------------------------------------------------- */

	laser_tag(h,"function activate(value)");
	laser_tag(h,"if ( value )");

		laser_indent(h);
		fprintf(h,"master.loseFocus(1);\n");
		laser_indent(h);
		fprintf(h,"manager.enabled = TRUE;\n");

	laser_close_tag(h,(char *) 0);
	laser_close_tag(h,(char *) 0);

	laser_indent(h);
	fprintf(h,"%c\n",0x0022);

	laser_close_collection(h,"url");
	laser_close_tag(h,"Script");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_toggle_page( FILE * handle, struct form_control * fptr)
{
	int	pages=0;
	char	work[1024];
	struct	form_item * iptr;
	return;
	sprintf(work,"%s%s",_TOGGLE_PREFIX,fptr->identifier);
	laser_def_tag(handle,"Script", work );
		laser_indent(handle);
		fprintf(handle,"eventIn SFBool activate\n");
		laser_indent(handle);
		fprintf(handle,"field SFNode state USE %s\n",fptr->identifier);
		laser_collection(handle,"url" );
		laser_indent(handle);
		fprintf(handle,"%cjavascript: function activate(value) {\n",0x0022);
		laser_indent(handle);
		fprintf(handle,"if ( value ) { \n");
		for ( 	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
			if ( iptr->Contents.style != _TAB_FRAME )
				continue;
			else
			{
				laser_indent(handle);
				if ( pages++ )
					fprintf(handle,"else ");
				fprintf(handle,"if ( state.whichChoice == %u ) { %s.whichChoice = 0; }\n",iptr->Contents.page-1,iptr->Contents.name);
			}
		}
		laser_indent(handle);
		fprintf(handle,"} }\n%c",0x0022);		
		laser_close_collection(handle,"url" );
	laser_close_tag( handle, "Script");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_true_conditional( FILE * handle, struct form_item * iptr )
{
	char	work[1024];
	laser_open_conditional(handle,iptr->Contents.name);
		laser_indent(handle);
		fprintf(handle,"REPLACE VALUE_%s.whichChoice BY 1\n",iptr->Contents.name);
	laser_close_conditional(handle);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_false_conditional( FILE * handle, struct form_item * iptr )
{
	char	work[1024];
	laser_open_conditional(handle,iptr->Contents.name);
		laser_indent(handle);
		fprintf(handle,"REPLACE VALUE_%s.whichChoice BY 0\n",iptr->Contents.name);
	laser_close_conditional(handle);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	laser_tab_frame( FILE * h, struct form_item * iptr, struct form_control * fptr, int started )
{
	struct	form_item * wptr;
	char	work[1024];
	int	fh = guifontsize(iptr->Contents.font);
	int	fw = (fh & 0x00FF);
	fh >>= 8;
	fh &= 0x00FF;
	if ( started++)
		laser_defs_footer(h);

	laser_comment(h,"tab page frame");
	laser_defs_header(h,_FRAME_PREFIX,iptr->Contents.name);
		laser_relief( h, 
			iptr->Contents.x,
			iptr->Contents.y+(fh+8),
			iptr->Contents.w,
			iptr->Contents.h-(fh+8), 
			_OUTSET_FRAME,
			iptr->Contents.name);
	return(started);
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ e d i t				*/
/*	-----------------------------------------------------------------------	*/
/*	this function generates all the laser code required for the edit widget.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_edit( FILE * handle, int x, int y, int w, int h, struct form_item * iptr )
{
	char *	work[1024];
	char *	framename[1024];

	sprintf(framename,"%s%s",_FRAME_PREFIX,iptr->Contents.name);
	// --------------------------------
	// generate translation to position
	// --------------------------------
	// laser_touch_sensor(handle,iptr->Contents.name);

	laser_comment(handle,"edit frame");
	laser_relief( handle, x,y,w,h, _EDIT_FRAME, framename);

	if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS  ))
	{
		laser_text(handle, x+1,y+1,w-2,h-2, iptr->Contents.name, standard_black, _A_LEFT );
	}
	else
	{
		laser_text_value(handle, x+1,y+1,w-2,h-2, "", standard_black, _A_LEFT, iptr->Contents.name );
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_window( FILE * handle, int x, int y, int w, int h, char * message, char * name, struct form_item * iptr )
{
	int	fh = guifontsize(iptr->Contents.font);
	int	fw = (fh & 0x00FF);
	fh >>= 8;
	fh &= 0x00FF;
	laser_comment(handle,"window frame");
	laser_relief( handle, x,y,w,h, _WINDOW_FRAME, (char *) 0);
	laser_comment(handle,"window title bar");
	laser_filzone( handle, x+2,y+2,w-4,fh, standard_title);
	laser_comment(handle,"window title message");
	laser_text( handle, x+fw,y+2,w-(fw*2),fh, message, standard_text, _A_LEFT);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_scrollframe( FILE * handle, struct form_item * iptr )
{
	int x;
	int y; 
	int w;
	int h;
	x = iptr->Contents.x;
	y = iptr->Contents.y;
	w = iptr->Contents.w;
	h = iptr->Contents.h;
	laser_group(handle);
	laser_comment(handle,"scroll event sensor");
	laser_click_sensor(handle,iptr);
	laser_comment(handle,"scroll bar tray");
	laser_relief( handle, x,y,w,h, _SCROLL_FRAME, (char *) 0);
	if ( w > h )
	{
		laser_comment(handle,"scroll left button");
		laser_relief( handle, x+1,y+1,h-2,h-2, _BUTTON_FRAME, (char *) 0);
		laser_comment(handle,"scroll slider");
		laser_relief( handle, x+w-(h-1),y+1,h-2,h-2, _BUTTON_FRAME, (char *) 0);
		laser_comment(handle,"scroll right button");
		laser_relief( handle, x+h, y+1,w-(h*2),h-2, _BUTTON_FRAME, (char *) 0);
	}
	else
	{
		laser_comment(handle,"scroll top button");
		laser_relief( handle, x+1,y+1,w-2,w-2, _BUTTON_FRAME, (char *) 0);
		laser_comment(handle,"scroll slider");
		laser_relief( handle, x+1,y+h-(w-1),w-2,w-2, _BUTTON_FRAME, (char *) 0);
		laser_comment(handle,"scroll bottom button");
		laser_relief( handle, x+1, y+w,w-2,h-(w*2), _BUTTON_FRAME, (char *) 0);
	}
	laser_comment(handle,"scroll event trigger");
	laser_open_conditional(handle,iptr->Contents.name);
	laser_close_conditional(handle);
	laser_close_tag(handle,"g");
	return;
}


/*	--------------------------------------------------------	*/
/*		      l a s e r _ p r o t o _ u s e 			*/
/*	--------------------------------------------------------	*/
/*	generates a useage instance of a particular defs		*/
/*	--------------------------------------------------------	*/
void	laser_proto_use( FILE * h, int x, int y, char * cname, char * iname, int visible )
{
	laser_indent(h);
	fprintf(h,"<use x=%c%u%c y=%c%u%c xlink:href=%c#%s%c id=%c%s%c/>\n",
		0x0022,x,0x0022,
		0x0022,y,0x0022,
		0x0022,cname,0x0022,
		0x0022,iname,0x0022);
	return;
}


/*	-------------------------------------------	*/
/*	  l a s e r _ p r o t o _ i n s t a n c e 	*/
/*	-------------------------------------------	*/
void	laser_proto_instance( FILE * h, struct form_control * fptr, char * iname, int xpos, int ypos, int visible, char * fname )
{
	char	work[1024];
	if (!( fname ))
		fname = fptr->identifier;
	sprintf(work,"Forms Model : %s",fptr->identifier);
	laser_comment(h,work);
	laser_indent(h);
	fprintf(h,"<use x=%c%u%c y=%c%u%c xlink:href=%c#%s%s%c id=%c%s%c",
		0x0022,xpos,0x0022,
		0x0022,ypos,0x0022,
		0x0022,fname,_FORM_SUFFIX,0x0022,
		0x0022,iname,0x0022);
	if ( visible )
		fprintf(h," visibility=%c%s%c/>\n",0x0022,"inherit",0x0022);
	else	fprintf(h," visibility=%c%s%c/>\n",0x0022,"hidden",0x0022);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_dataframe( FILE * h, struct form_item * iptr )
{
	char	work[1024];
	char	* fnptr;
	struct	form_control * ffptr;
	struct window_control Window;
	struct window_control Center;

	/* TODO : FIx This */
	Center.x = Center.y = 0;
	
	if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
		return;
	else if (!( fnptr = abal_payload(iptr) )) 
		return;
	else if (!(ffptr = locate_form_control( fnptr ) ))
		return;
	else
	{
		form_Dimensions( &Window, ffptr );
		laser_group(h);
			laser_proto_instance(h,ffptr,
				iptr->Contents.name,
				iptr->Contents.x,iptr->Contents.y,
				( iptr->Contents.events->xo_show & _EVENT_IS_COND ? 0 : 1 ),
				ffptr->identifier
				);
		laser_close_tag(h,"g");
		return;
	}
}

/*	-----------------------------------------------------------------------	*/
/*				  l a s e r _ t a b l e  				*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	laser_table( FILE * handle, int x, int y, int w, int h, int f, int fg, int bg,
		char * tptr, char * vptr, int options, char * fptr )
{
	int	focusline=0;
	int	thisrow=0;
	int	rowfg;
	int	rowbg;

	/* these four are for the hide / show */
	/* ---------------------------------- */
	int	ty,tw;
	int	xs;
	int	zw=w;
	int	zh=h;
	int	zx=x;
	int	zy=y;
	int	fh=0;
	int	fw=0;

	/* Field width calculations */
	/* ------------------------ */
	int	extra=0;
	int	underspill=0;
	int	overspill=0;
	int	field;
	int	fields;
	int	fieldwidth[_MAX_FORM_FIELDS];

	/* text display and bars */
	/* --------------------- */
	int	dath;
	int	tlen;
	int	padd;
	int	lmargin=0;
	char *	wptr;

	int	xh=0;
	int	r;
	int	a=0;
	int	ha=-1;
	int	zbg=0;
	int	adjust=0;
	int	relw=0;
	int	nbr;
	int	txfg;
	int	txbg;
	char	libelle[1024];

	/* Handle CICO atributs */
	/* -------------------- */
//	if ( options & _A_BOLD  ) a |= _PIXELCO_BOLD;
//	if ( options & _A_LINE  ) a |= _PIXELCO_ULINE;

//	if ( options & _A_BAR )
//		focusline = TableFocusLine;
//	else	focusline = 0;

	/* if ( options & _A_SHADOW) a |= _PIXELCO_SHADOW; */

	/* Calculate font sizes */
	/* -------------------- */
	if (!( f ))
		return(0);		
	else	{
		fw = guifontsize(f);
		if (!(fh = (( fw >> 8) & 0x00FF)))
			return(0);		
		fw &= 0x00FF;
		if (!( fw ))
			return(0);		
		}

	/* Ensure legal zone */
	/* ----------------- */
	if (( w < fw )
	||  ( h < fh ))
		return(0);

	/* Check overall table width calculation */
	/* ------------------------------------- */
	if (!( options & 0x2000 )) {
		if ((xs = ((w - 4) % fw)) != 0)
			w -= xs;
		}
	else if ((xs = (w % fw)) != 0)
		w -= xs;
	
	zw = w;

	if (!( options  & 0x2000 ))
		xh = 0;
	else	{
		xh = 1;
		if( fh ) 
			h = (((h / fh) * fh) + (xh*2));
		else	h = (((h / fh) * fh)+xh);
		}

	/* Generate relief frame with background */
	/* ------------------------------------- */
	if ((options & 0x0007 ) < 4) 
		zbg = (options & 2 ? bg : standard_white);
	else	zbg = (options & 1 ? bg : standard_white);

	laser_comment(handle,"table outer frame");
	laser_draw_relief(handle,x,y,w,h,standard_lolight,zbg,standard_hilight,(char *) 0);

	if (!( options & 0x2000 )) {
		x += 1; y+= 1;
		w -= 2; h -= 2;
		}

	/* Generate black inside liner */
	/* --------------------------- */
	laser_comment(handle,"table inner frame");
	laser_draw_relief(handle,x,y,w,h,standard_black,transparent,standard_black,(char *) 0);

	if (!( options & 0x2000 )) {
		x += 1; y+= 1;
		w -= 2; h -= 2;
		}

	/* Establish Titles background fill */
	/* -------------------------------- */
	laser_comment(handle,"table background");
	laser_filzone( handle, x,y,w,fh, standard_title);

	/* check for and perform row-wise zoning */
	/* ------------------------------------- */
	switch ( options & 0x0007 ) {
		case	1 :
		case	3 :
			zbg = (options & 2 ? bg-1 : standard_white-1);
			laser_comment(handle,"table row zoning");
			for ( r=(fh*2); (r+fh) < h; r+= (fh*2) )
				laser_filzone(handle, x,y+r,w,fh,zbg);
			break;
		}

	/* If a title has been provided */
	/* ---------------------------- */
	if ( tptr ) {

		/* Calculate title items */
		/* --------------------- */
		if ( options & _A_SHADOW) 
		{
			txfg = standard_black; txbg = 0;
		}
		else
		{
			txfg = standard_text; txbg = standard_title;
		}

		/* Calculate Title widths , hence widths */
		/* ------------------------------------- */
		if (( options & 0x4000 )
		&&  ( is_valid_format( fptr ) ))
			fields = vformat(fptr,fieldwidth,_MAX_FORM_FIELDS,(w/fw));
		else 	fields = vfields(tptr,fieldwidth,_MAX_FORM_FIELDS,(w/fw));

		if ( fields != 0) {

			/* Print texts and vertical lines */
			/* ---------------------------- */
			dath = (standard_white | (standard_black << 8));
			laser_comment(handle,"table titles");
			for (lmargin=0,field=0; field < fields; field++ ) {
				for ( 	tlen=0,wptr=tptr; *wptr != 0; wptr++) {
					if ( *wptr == '|' )
						break;
					else	tlen++;
					}
				if ( tlen < fieldwidth[field] )
					padd = ((fieldwidth[field]-tlen)/2);
				else	padd = 0;

				if ( options & _A_SHADOW) {
					relw = (fieldwidth[field]*fw);
					if ( *wptr != '|' )
						if (( lmargin*fw) < w )
							relw = (w - (lmargin*fw));
					laser_draw_relief(handle,(lmargin*fw)+x,y-1,relw,fh+1,
						standard_hilight,standard_backwash,standard_lolight,(char *) 0);
					adjust = fh;
					}					
				memcpy( libelle, tptr, tlen );
				libelle[tlen] = 0;
				laser_text(handle,((lmargin+padd)*fw)+x,y,relw,fh+1,libelle,txfg,_A_LEFT);

				if ( *(wptr++) != '|' )
					break;
				else	{
					tptr = wptr;
					lmargin += fieldwidth[field];
					/* was X */
					laser_filzone(handle,(((lmargin*fw)+x)-1),y+adjust,1,h-adjust,dath);
					}
				}

			}


		/* check for text and space remaining */
		/* ---------------------------------- */
		if (( options & 0x8000 )) {
			/* previous one shot display method */
			/* -------------------------------- */
			if (( vptr ) && (( h-fh ) > fh)) {
				visual_text(x,y+fh,w,h-fh,f,fg,0,vptr,strlen(vptr), _A_NONE);
				}
			}
		else 	{

			/* New Line by Line and Cell by Cell display */
			/* ----------------------------------------- */
			ty=fh; 
			for (extra=0,field=0;field < fields; field++)
				extra += fieldwidth[field];

			if ( extra > (w / fw ))
				overspill = (extra - (w/fw));
			else if ( extra < (w / fw))
				underspill = ((w/fw)-extra);

			/* check for and perform column-wise zoning */
			/* ---------------------------------------- */
			switch ( options & 0x0007 ) {

				case	4 :
				case	5 :
					zbg = (options & 1 ? bg-1 : standard_white-1);
					laser_comment(handle,"table column zoning");
					for (lmargin=0,field=0; field < fields; field++ ) {
						if ((field+1) == fields)
							tw = (w - lmargin);
						else 	tw = (fieldwidth[field] * fw);
						if (!( field & 1 ))
							laser_filzone(handle,lmargin+x,y+fh,tw-1,(h-fh),zbg);
						lmargin += (tw-xh);			
						}
					break;

				case	6 :
				case	7 :
					zbg = (options & 1 ? bg-1 : standard_white-1);
					laser_comment(handle,"table column zoning");
					for ( nbr=0,r=fh; (r+fh) < h; r+= fh, nbr++ ) {
						for (lmargin=0,field=0; field < fields; field++ ) {
							if ((field+1) == fields)
								tw = (w - lmargin);
							else	tw = (fieldwidth[field] * fw);
							if (!( (field+nbr) & 1 ))
								laser_filzone(handle,lmargin+x,y+r,tw-1,fh,zbg);
							lmargin += (tw-xh);			
							}
						}
					break;
				}

			/* Display Texts */
			/* ------------- */
			if ( vptr != (char *) 0) {
				thisrow=1;
				while ( (ty+fh) <= h ) {
					if ( thisrow == focusline ) {
						rowbg = fg;
						rowfg = bg;
						}
					else	{
						rowfg=fg;
						rowbg=0;
						}
					laser_comment(handle,"table data cells");
					for (lmargin=0,field=0; field < fields; field++ ) {
						tw = (fieldwidth[field] * fw);
						// visual_text(lmargin+x,ty+y,tw,fh,f,rowfg,rowbg,vptr,fieldwidth[field], _A_NONE );
						vptr += fieldwidth[field];
						lmargin += (tw-xh);			
						}
					ty += fh;
					vptr += underspill;
					vptr -= overspill;
					thisrow++;
					}
				}
			}
		}
	return(0);		
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ f o r m f r a m e			*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_formframe( FILE * h, struct form_item * iptr )
{
	laser_table( 	h,
			iptr->Contents.x, iptr->Contents.y,
			iptr->Contents.w, iptr->Contents.h,
			iptr->Contents.font,
			(iptr->Contents.colour & 0x00FF),
			((iptr->Contents.colour >> 8) & 0x00FF),
			abal_payload( iptr ),
			(char *) 0,
			iptr->Contents.align,
			iptr->Contents.format
		);
	return;
}



/*	---------------------------------------------------	*/
/*			L A S e R_ p a t t e r n		*/
/*	---------------------------------------------------	*/
/*	called from the laser form production to generate a	*/
/*	pattern element for the tiling of an image texture.	*/
/*	---------------------------------------------------	*/
void	LASER_pattern( FILE * handle, struct form_item * iptr )
{
	struct	form_control * fptr;
	char	work[1024];
	int	isdef;
	int	align;
	int	w;
	int	h;
	struct	standard_image * image=(struct standard_image *) 0;

	if (!( iptr )) 	
		return;
	else if (!( fptr = iptr->parent ))
		return;

	LC.fontWidth  = guifontsize(iptr->Contents.font);
	LC.fontHeight = (LC.fontWidth >> 8); 
	LC.fontWidth  &= 0x00FF;

	sprintf(work,"Pattern : %s.%s",fptr->identifier,iptr->Contents.name);
	laser_comment(handle, work );

	if (( image = iptr->Contents.extra ) != (struct standard_image *) 0)
	{
		w = image->columns;
		h = image->rows;
	}
	else
	{
		w = h = 10;
	}

	fprintf(handle,"<defs><pattern id=%c%s%s%c x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c>\n", 
		0x0022,_PATTERN_PREFIX,iptr->Contents.name,0x0022,
		0x0022,0,0x0022,
		0x0022,0,0x0022,
		0x0022,w,0x0022,
		0x0022,h,0x0022);

		fprintf(handle,"<image x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c xlink:href=%c%s%c/>\n", 
			0x0022,0,0x0022,
			0x0022,0,0x0022,
			0x0022,w,0x0022,
			0x0022,h,0x0022,
			0x0022,abal_payload(iptr),0x0022
			);

	fprintf(handle,"</pattern></defs>\n");
	return;
}

void	laser_widget_fill( FILE * h, struct form_item * iptr )
{
	switch ( iptr->Contents.align )
	{
	case	8	:
		laser_filzone( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			((iptr->Contents.colour >> 8) & 0x00FF)
			);
		laser_framezone( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			(iptr->Contents.colour & 0x00FF),
			(char *) 0
			);
		break;
	case	0	:
		laser_comment(h,"visual fill zone");
		laser_filzone( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			(iptr->Contents.colour & 0x00FF)
			);
		break;
	case	1	:
		laser_comment(h,"visual frame zone");
		laser_framezone( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			(iptr->Contents.colour & 0x00FF),
			(char *) 0
			);
		break;
	case	9	:
		laser_circle( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			((iptr->Contents.colour>>8) & 0x00FF),
			(char *) 0
			);
		laser_framecircle( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			(iptr->Contents.colour & 0x00FF),
			(char *) 0
			);
		break;
	case	13 :
		laser_rounded_frame(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			(iptr->Contents.colour & 0x00FF),
			(char *) 0
			);
			break;
	case	14 :
		laser_rounded_fill(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			(iptr->Contents.colour & 0x00FF),
			(char *) 0
			);
			break;

	case	3	:
		laser_comment(h,"visual circle");
		laser_circle( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			(iptr->Contents.colour & 0x00FF),
			(char *) 0
			);
		break;
	case	2	:
		laser_comment(h,"visual frame circle");
		laser_framecircle( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			((iptr->Contents.colour>>8) & 0x00FF),
			(char *) 0
			);
		break;
	}
	return;
}

#include "lsrstyle.c"

/*	---------------------------------------------------	*/
/*			L A S e R_ w i d g e t			*/
/*	---------------------------------------------------	*/
/*	called from the upper level forms production cycle	*/
/*	for the translation of a widget to BiFS.		*/
/*	---------------------------------------------------	*/
void	LASER_widget( FILE * h, struct form_item * iptr )
{
	struct	form_control * fptr;
	char	work[1024];
	int	align;

	if (!( iptr )) 	
		return;
	else if (!( fptr = iptr->parent ))
		return;

	LC.fontWidth  = guifontsize(iptr->Contents.font);
	LC.fontHeight = (LC.fontWidth >> 8); 
	LC.fontWidth  &= 0x00FF;

	sprintf(work,"Widget : %s.%s",fptr->identifier,iptr->Contents.name);
	laser_comment(h, work );

	switch (iptr->Contents.style)
	{

	case	_FILL_FRAME	:	//	0
		laser_widget_group(h, iptr);
		laser_widget_fill( h, iptr );
		laser_groupend(h);
		break;

	case	_EDIT_FRAME	:	//	5
		laser_widget_group(h, iptr);
		laser_edit( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			iptr
			);
		laser_groupend(h);
		break;
	case	_OUTSET_FRAME	:	//	1
	case	_INSET_FRAME	:	//	2
	case	_RIDGE_FRAME	:	//	3
	case	_GROOVE_FRAME	:	//	4
		laser_widget_group(h, iptr);
		laser_comment(h,"visual frame");
		laser_relief( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			iptr->Contents.style,
			(char *) 0
			);
		laser_groupend(h);
		break;

	case	_TEXT_FRAME	:	//	6
		laser_widget_group(h, iptr);
		laser_comment(h,"visual text");
		laser_text(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			iptr->Contents.colour,
			iptr->Contents.align
			);
		laser_groupend(h);
		break;
	case	_IMAGE_FRAME	:	//	7
		laser_widget_group(h, iptr);
		laser_comment(h,"visual image");
		laser_image(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			iptr->Contents.name,
			iptr->Contents.align
			);
		laser_groupend(h);
		break;

	case	_SWITCH_FRAME	:	//	18
		laser_widget_group(h, iptr);
		laser_switch(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			iptr
			);
		laser_groupend(h);
		break;

	case	_BUTTON_FRAME	:	//	9
		laser_widget_group(h, iptr);
		laser_pushbutton( h, iptr );
		laser_groupend(h);
		break;

	case	_WINDOW_FRAME	:	//	10
		laser_widget_group(h, iptr);
		laser_window(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			iptr->Contents.name,
			iptr
			);
		laser_groupend(h);
		break;

	case	_CHECK_FRAME	:	//	12
		laser_widget_group(h, iptr);
		laser_checkbox(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			iptr
			);
		laser_groupend(h);
		break;

	case	_SCROLL_FRAME	:	//	16
		laser_widget_group(h, iptr);
		laser_scrollframe( h, iptr );
		laser_groupend(h);
		break;

	case	_RADIO_FRAME	:	//	13
		laser_widget_group(h, iptr);
		sprintf(work,"%s_%u",iptr->Contents.name,iptr);
		laser_radiobox(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			iptr
			);
		laser_groupend(h);
		break;

	case	_DATA_FRAME	:
		laser_widget_group(h, iptr);
		laser_dataframe( h, iptr );
		laser_groupend(h);
		break;

	case	_FORM_FRAME	:	//	15
		laser_widget_group(h, iptr);
		laser_formframe( h, iptr );
		laser_groupend(h);
		break;

	case	_LINE_FRAME	:	//	8
	case	_TAB_FRAME	:	//	11
	case	_SELECT_FRAME	:	//	14
	case	_PROGRESS_FRAME	:	//	17	
	case	_GRAPH_FRAME	:	//	19
		break;

	}
	return;
}

static	int	laser_od_update_started=0;
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	laser_start_od_update( FILE * h )
{
	if (!( laser_od_update_started ))
	{
		laser_od_update_started = 1;
		laser_tag(h,"AT 0");
		laser_collection(h,"UPDATE OD");
	}
	return(0);
}
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	laser_close_od_update( FILE * h )
{
	if ( laser_od_update_started )
	{
		laser_close_collection(h,"update OD");
		laser_close_tag(h,"AT 0");
		laser_od_update_started = 0;
	}
	return(0);
}

/*	-------------------------------------------	*/
/*	l a s e r _ o b j e c t _ d e s c r i p t o r 	*/
/*	-------------------------------------------	*/
/*	adds an object descriptor prior to addition	*/
/*	of scene svg to handle images, video	*/
/*	and audio streams as textures in scene.		*/
/*	-------------------------------------------	*/
int	laser_object_descriptor( FILE * h, char * nptr )
{
	int	result=0;
	laser_start_od_update( h );
	laser_tag(h,"ObjectDescriptor");
		laser_integer_field(h,"objectDescriptorID",(result = ++LC.od));
		laser_collection(h,"esDescr");
			laser_tag(h,"ES_Descriptor");
				laser_integer_field(h,"ES_ID",++LC.es);
				laser_tag(h,"muxInfo MuxInfo");
					laser_quoted(h,"fileName", nptr );
				laser_close_tag(h,"MuxInfo");
			laser_close_tag(h,"ES_Descriptor");
		laser_close_collection(h,"esDescr");
	laser_close_tag(h,"ObjectDescriptor");
	return( result );
}

/*	-------------------------------------------------------------	*/
/*	s t r i n g _ s e n s o r _ o b j e c t _ d e s c r i p t o r 	*/
/*	-------------------------------------------------------------	*/
/*	update of the object descriptor for the string sensor stream	*/
/*	-------------------------------------------------------------	*/
int	laser_string_sensor_object_descriptor( FILE * h )
{
	int	result=0;
	laser_tag(h,"AT 0");
		laser_collection(h,"UPDATE OD");
			laser_tag(h,"ObjectDescriptor");
				laser_integer_field(h,"objectDescriptorID",(result = LC.StringSensorOD));
				laser_collection(h,"esDescr");
					laser_string_sensor_es_descriptor(h);
				laser_close_collection(h,"esDescr");
			laser_close_tag(h,"ObjectDescriptor");
		laser_close_collection(h,"update OD");
	laser_close_tag(h,"AT 0");
	return( result );
}

/*	------------------------------------------------------------	*/
/*	   s t r i n g _ s e n s o r _ e s _ d e s c r i p t o r	*/
/*	------------------------------------------------------------	*/
/*	this function is called from the initial object descriptor	*/
/*	production and also from the initial UPDATE OD description.	*/
/*	------------------------------------------------------------	*/
void	laser_string_sensor_es_descriptor( FILE * h )
{
	laser_tag(h,"ES_Descriptor");
		laser_integer_field(h,"ES_ID",LC.StringSensorID);
		laser_tag(h,"decConfigDescr DecoderConfigDescriptor");
			laser_field(h,"streamType","10");
			laser_tag(h,"decSpecificInfo UIConfig");
				laser_string(h,"deviceName","StringSensor");
			laser_close_tag(h,"UIConfig");
		laser_close_tag(h,"DecoderConfigDescriptor");
	laser_close_tag(h,"ES_Descriptor");
	return;
}

/*	---------------------------------------------------------	*/
/*	 k e y _ s e n s o r _ o b j e c t _ d e s c r i p t o r 	*/
/*	---------------------------------------------------------	*/
/*	update of the object descriptor for the key sensor stream	*/
/*	---------------------------------------------------------	*/
int	laser_key_sensor_object_descriptor( FILE * h )
{
	int	result=0;
	laser_tag(h,"AT 0");
		laser_collection(h,"UPDATE OD");
			laser_tag(h,"ObjectDescriptor");
				laser_integer_field(h,"objectDescriptorID",(result = LC.KeySensorOD));
				laser_collection(h,"esDescr");
					laser_key_sensor_es_descriptor(h);
				laser_close_collection(h,"esDescr");
			laser_close_tag(h,"ObjectDescriptor");
		laser_close_collection(h,"update OD");
	laser_close_tag(h,"AT 0");
	return( result );
}

/*	------------------------------------------------------------	*/
/*		k e y _ s e n s o r _ e s _ d e s c r i p t o r		*/
/*	------------------------------------------------------------	*/
/*	this function is called from the initial object descriptor	*/
/*	productionand also from the initial UPDATE OD description.	*/
/*	------------------------------------------------------------	*/
void	laser_key_sensor_es_descriptor( FILE * h )
{
	laser_tag(h,"ES_Descriptor");
		laser_integer_field(h,"ES_ID",LC.KeySensorID);
		laser_tag(h,"decConfigDescr DecoderConfigDescriptor");
			laser_field(h,"streamType","10");
			laser_tag(h,"decSpecificInfo UIConfig");
				laser_string(h,"deviceName","KeySensor");
			laser_close_tag(h,"UIConfig");
		laser_close_tag(h,"DecoderConfigDescriptor");
	laser_close_tag(h,"ES_Descriptor");
	return;
}

/*	-------------------------------------------	*/
/*		s i n g _ o p e n _ L A S e R  		*/
/*	-------------------------------------------	*/
void	laser_xml_header(FILE *h)
{
	fprintf(h,"<?xml version='1.0' encoding='UTF-8'?>\n");
	return;
}

void	laser_saf_header(FILE *h)
{
	if ( LC.useSaf )
	{
		fprintf(h,"<saf:SAFSession\n");
		fprintf(h,"\txmlns:saf='%s'\n",LC.safNs);
		fprintf(h,"\txmlns='%s'\n",LC.svgNs);
		if ( LC.useLaser )
		{
			fprintf(h,"\txmlns:lsr='%s'\n",LC.laserNs);
		}
		fprintf(h,"\txmlns:xlink='%s'\n",_XLINK_NAMESPACE);
		fprintf(h,"\txmlns:ev='%s'>\n",_EVENT_NAMESPACE);
	}
	return;
}

void	laser_open_svg(FILE *h)
{
	if (!( LC.useSaf ))
	{
		fprintf(h,"<svg\n");
		fprintf(h,"\txmlns='%s'\n",LC.svgNs);
		if ( LC.useLaser )
		{
			fprintf(h,"\txmlns:lsr='%s'\n",LC.laserNs);
		}
		fprintf(h,"\txmlns:xlink='%s'\n",_XLINK_NAMESPACE);
		fprintf(h,"\txmlns:ev='%s'\n",_EVENT_NAMESPACE);
		fprintf(h,"\twidth='%upx' height='%upx' viewBox='0 0 %u %u' version='1.2'>\n",LC.width,LC.height,LC.width,LC.height);
	}
	else
	{
		fprintf(h,"<svg\n");
		fprintf(h,"\txmlns='%s'\n",LC.svgNs);
		if ( LC.useLaser )
		{
			fprintf(h,"\txmlns:lsr='%s'\n",LC.laserNs);
		}
		fprintf(h,"\txmlns:xlink='%s'\n",_XLINK_NAMESPACE);
		fprintf(h,"\txmlns:ev='%s'\n",_EVENT_NAMESPACE);
		fprintf(h,"\twidth='%upx' height='%upx' viewBox='0 0 %u %u' version='1.2'>\n",LC.width,LC.height,LC.width,LC.height);
	}	
	return;
}

void	laser_close_svg(FILE *h)
{
	fprintf(h,"</svg>\n");
	return;
}

void	laser_scene_header(FILE *h)
{
	if ( LC.useSaf )
	{
		fprintf(h,"<saf:sceneHeader>\n");
		fprintf(h,"<LASeRHeader profile='full' resolution='1'/>\n");
		fprintf(h,"</saf:sceneHeader>\n");
	}
	return;
}

void	laser_media_header(FILE *h)
{
	if ( LC.useSaf > 1 )
	{
		fprintf(h,"<saf:mediaHeader streamID='stream16' streamType='10' objectTypeIndication='0' timeStampResolution='1000'/>\n");
	}
	return;
}

void	laser_media_unit(FILE *h)
{
	if ( LC.useSaf )
	{
		fprintf(h,"<saf:mediaUnit/>\n");
	}
	return;
}

void	laser_saf_footer(FILE *h)
{
	if ( LC.useSaf )
	{
		fprintf(h,"<saf:endOfSAFSession/>\n");
		fprintf(h,"</saf:SAFSession>\n");
	}
	return;
}

int	sing_open_LASER( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;

	laser_comment(h,"Initial Object Descriptors");
	laser_xml_header(h);
	laser_saf_header(h);
	laser_scene_header(h);
	laser_media_header(h);
	laser_media_unit(h);
#ifdef	_OOOPS
	laser_tag(h,"InitialObjectDescriptor");
		laser_integer_field(h,"objectDescriptorID",LC.primary);
		laser_integer_field(h,"audioProfileLevelIndication",LC.AudioLevel);
		laser_integer_field(h,"visualProfileLevelIndication",LC.VisualLevel);
		laser_integer_field(h,"sceneProfileLevelIndication",LC.SceneLevel);
		laser_integer_field(h,"graphicsProfileLevelIndication",LC.GraphicsLevel);
		laser_integer_field(h,"ODProfileLevelIndication",LC.ODLevel);

		laser_collection(h,"esDescr");

			/* --------------------------------------- */
			/* Elementary Stream : BiFS Command Stream */
			/* --------------------------------------- */
			laser_comment(h,"Elementary Stream : Bifs Command Stream");
			laser_tag(h,"ES_Descriptor");
				laser_integer_field(h,"ES_ID",++LC.es);
				laser_tag(h,"decConfigDescr DecoderConfigDescriptor");
					laser_field(h,"streamType","3");
					laser_tag(h,"decSpecificInfo LASERConfig");
						laser_field(h,"isCommandStream","true");
						laser_field(h,"pixelMetric","true");
						laser_integer_field(h,"pixelWidth",LC.width);
						laser_integer_field(h,"pixelHeight",LC.height);
					laser_close_tag(h,"LASERConfig");
				laser_close_tag(h,"DecoderConfigDescriptor");
			laser_close_tag(h,"ES_Descriptor");

			/* --------------------------------------- */
			/* Elementary Stream : Object Descriptors  */
			/* --------------------------------------- */
			laser_comment(h,"Elementary Stream : Object Descriptors");
			laser_tag(h,"ES_Descriptor");
				laser_integer_field(h,"ES_ID",++LC.es);
				laser_tag(h,"decConfigDescr DecoderConfigDescriptor");
					laser_field(h,"streamType","1");
				laser_close_tag(h,"DecoderConfigDescriptor");
			laser_close_tag(h,"ES_Descriptor");

			/* --------------------------------------- */
			/* Elementary Stream : Key Sensor Infos    */
			/* --------------------------------------- */
			if ( LC.keySensor )
			{
				laser_comment(h,"Elementary Stream : Key Sensor Information");
				laser_key_sensor_es_descriptor(h);
			}
			else if ( LC.stringSensor )
			{
				laser_comment(h,"Elementary Stream : String Sensor Information");
				laser_string_sensor_es_descriptor(h);
			}


		laser_close_collection(h,"esDescr");
	laser_close_tag(h,"InitialObjectDescriptor");
#endif
	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	laser_show_image3d( FILE * h, char * nptr, int od, struct coordinate3d * tl, struct coordinate3d * d )
{
	char	work[1024];
	return;

	laser_tag(h,"Transform");
		mpeg_translation3d( work, tl->x, tl->y, d->x, d->y, tl->z );
		laser_field(h,"translation",work);

	laser_tag(h,"Shape");

		// ------------------------------
		// generate the widget appearance
		// ------------------------------
		laser_tag(h,"appearance Appearance");
			laser_tag(h,"material Material");
				laser_field(h,"transparency","0");
			laser_close_tag(h,"Material");
			laser_tag(h,"texture ImageTexture");
				laser_od_url( h, nptr, od );
			laser_close_tag(h,"ImageTexture");

		laser_close_tag(h,"appearance");

		// ----------------------------
		// generate the widget geometry
		// ----------------------------
		laser_tag(h,"geometry Box");
			sprintf(work,"%u %u %u",d->x,d->y,d->z);
			laser_field(h,"size",work);
		laser_close_tag(h,"Box");

	laser_close_tag(h,"Shape");

	laser_close_tag(h,"g");

	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	laser_show_movie3d( FILE * h, char * nptr, int od, struct coordinate3d * tl, struct coordinate3d * d )
{
	char	work[1024];
	return;
	laser_tag(h,"Transform");
		mpeg_translation3d( work, tl->x, tl->y, d->x, d->y, tl->z );
		laser_field(h,"translation",work);

	laser_tag(h,"Shape");

		// ------------------------------
		// generate the widget appearance
		// ------------------------------
		laser_tag(h,"appearance Appearance");
			laser_tag(h,"material Material");
				laser_field(h,"transparency","0");
			laser_close_tag(h,"Material");
			laser_tag(h,"texture MovieTexture");
				laser_od_url( h, nptr, od );
			laser_close_tag(h,"MovieTexture");

		laser_close_tag(h,"appearance");

		// ----------------------------
		// generate the widget geometry
		// ----------------------------
		laser_tag(h,"geometry Box");
			sprintf(work,"%u %u %u",d->x,d->y,d->z);
			laser_field(h,"size",work);
		laser_close_tag(h,"Box");

	laser_close_tag(h,"Shape");

	laser_close_tag(h,"Transform");

	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	laser_show_audio3d( FILE * h, char * nptr, int od, struct coordinate3d * tl, struct coordinate3d * d )
{
	char	work[1024];

	laser_tag(h,"Transform");
		mpeg_translation3d( work, tl->x, tl->y, d->x, d->y, tl->z );
		laser_field(h,"translation",work);

	laser_tag(h,"Sound");
		laser_tag(h,"source AudioSource");
		laser_od_url( h, nptr, od );
	laser_close_tag(h,"Sound");

	laser_tag(h,"Shape");

		// ------------------------------
		// generate the widget appearance
		// ------------------------------
		laser_tag(h,"appearance Appearance");
			laser_tag(h,"material Material");
				laser_field(h,"transparency","0");
			laser_close_tag(h,"Material");
		laser_close_tag(h,"appearance");

		// ----------------------------
		// generate the widget geometry
		// ----------------------------
		laser_tag(h,"geometry Box");
			sprintf(work,"%u %u %u",d->x,d->y,d->z);
			laser_field(h,"size",work);
		laser_close_tag(h,"Box");

	laser_close_tag(h,"Shape");

	laser_close_tag(h,"Transform");

	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	laser_show_image2d( FILE * h, char * nptr, int od, int w, int hx )
{
	char	work[1024];

	laser_tag(h,"Shape");

		// ------------------------------
		// generate the widget appearance
		// ------------------------------
		laser_tag(h,"appearance Appearance");
			laser_tag(h,"material Material2D");
				laser_field(h,"filled","true");
			laser_close_tag(h,"Material2D");
			laser_tag(h,"texture ImageTexture");
				laser_od_url( h, nptr, od );
			laser_close_tag(h,"ImageTexture");

		laser_close_tag(h,"appearance");

		// ----------------------------
		// generate the widget geometry
		// ----------------------------
		laser_tag(h,"geometry Rectangle");
			sprintf(work,"%u %u" ,w,hx);
			laser_field(h,"size",work);
		laser_close_tag(h,"Rectangle");

	laser_close_tag(h,"Shape");

	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ a n c h o r				*/
/*	-----------------------------------------------------------------------	*/
/*	provides for hyperlink type chaining between documents.			*/
/*	-----------------------------------------------------------------------	*/
int	laser_anchor( FILE * h, char * nptr )
{
	if (!( nptr ))
		return(0);
	else if (!( nptr = allocate_string( nptr ) ))
		return(0);
	else if (!( nptr = laser_enforce_extension( nptr ) ))
		return( 0 );
	else	
	{
		laser_indent(h);
		fprintf(h,"<a xlink:href=%c%s%c>\n",0x0022,nptr,0x0022);
		liberate( nptr );
		mpeg_enter();
		return(1);
	}
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ p o p u p					*/
/*	-----------------------------------------------------------------------	*/
/*	provides for popup launch (OVERLAY, MODULE) of nested use of documents.	*/
/*	-----------------------------------------------------------------------	*/
int	laser_popup( FILE * h, struct form_item * iptr, int overlay )
{
	char	fwork[1024];
	char	work[1024];
	struct	form_control * ffptr;
	if (!(ffptr = locate_form_control( iptr->Contents.format ) ))
		return(0);
	else
	{
		if ( overlay )
			sprintf(fwork,"%s%s%s",_OVERLAY_PREFIX,ffptr->identifier,iptr->Contents.name);
		else	sprintf(fwork,"%s%s",_MODULE_PREFIX,ffptr->identifier);
		laser_indent(h);
		fprintf(h,"<g activate=%c%s%s(1)%c>\n",0x0022,_TOGGLE_PREFIX,iptr->Contents.name,0x0022);
		mpeg_enter();
		laser_button(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			( iptr->Contents.name  ? iptr->Contents.name : (char *) 0),
			iptr->Contents.align, _BUTTON_FRAME
			);
		laser_close_tag(h,"g");
		if ( laser_add_proto_item( fwork ) )
		{
			laser_defs_header(h,fwork,_FORM_SUFFIX);
			laser_proto_body(h,ffptr,fwork);
			laser_defs_footer(h);
		}

		laser_open_script(h);
		laser_indent(h);
		fprintf(h,"function %s%s(v) {\n",_TOGGLE_PREFIX,iptr->Contents.name);
		mpeg_enter();
		laser_indent(h);
		fprintf(h,"var item = document.getElementById(%c%s%s%c);\n",
			0x0022,_OVERLAY_PREFIX,iptr->Contents.name,0x0022);
		laser_indent(h);
		fprintf(h,"var state = item.getAttribute(%cvisibility%c);\n",0x0022,0x0022);
		laser_indent(h);
		fprintf(h,"if ( state == %chidden%c ) {\n",0x0022,0x0022);
		mpeg_enter();
		laser_indent(h);
		fprintf(h,"item.setAttribute(%cvisibility%c,%cvisible%c);\n",
			0x0022,0x0022,
			0x0022,0x0022);
		laser_script_else(h);
		laser_indent(h);
		fprintf(h,"item.setAttribute(%cvisibility%c,%chidden%c);\n",
			0x0022,0x0022,
			0x0022,0x0022);
		laser_close_brace(h);
		laser_close_brace(h);
		laser_close_script(h);
	return(0);
	}
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ p o p u p _ l a u n c h e r			*/
/*	-----------------------------------------------------------------------	*/
/*	instance of class for launching of pop up (OVERLAY, MODULE)		*/
/*	-----------------------------------------------------------------------	*/
int	laser_popup_launcher( FILE * h, struct form_item * iptr, int overlay )
{
	char	fwork[1024];
	char	work[1024];
	struct	form_control * ffptr;
	if (!(ffptr = locate_form_control( iptr->Contents.format ) ))
		return(0);
	else
	{
		if ( overlay )
			sprintf(fwork,"%s%s%s",_OVERLAY_PREFIX,ffptr->identifier,iptr->Contents.name);
		else	sprintf(fwork,"%s%s",_MODULE_PREFIX,ffptr->identifier);

		sprintf(work,"%s%s",_OVERLAY_PREFIX,iptr->Contents.name);
		laser_proto_instance(h,ffptr,work,iptr->Contents.x+10,iptr->Contents.y+10,0,fwork);	
		return(0);
	}
}


/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	laser_inline_form3d( FILE * h, char * nptr,  struct coordinate3d * tl, struct coordinate3d * d )
{
	char	work[1024];
	if (!( nptr ))
		return(0);
	else if (!( nptr = allocate_string( nptr ) ))
		return(0);
	else if (!( nptr = laser_enforce_extension( nptr ) ))
		return(0);
	else	
	{
		laser_tag(h,"Transform");
			mpeg_translation3d( work, tl->x, tl->y,d->x, d->y, tl->z );
			laser_field(h,"translation",work);

		laser_tag(h,"Inline");
			laser_od_url(h,nptr,0);
			laser_close_tag(h,"Inline");

		laser_close_tag(h,"Transform");
		liberate( nptr );
		return(0);
	}
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	laser_inline_form2d( FILE * h, char * nptr, int w, int hx )
{
	if (!( nptr ))
		return(0);
	else if (!( nptr = allocate_string( nptr ) ))
		return(0);
	else if (!( nptr = enforce_extension( nptr, _EXT_MP4 ) ))
		return( 0 );
	else	{
		laser_tag(h,"Inline");
			laser_od_url(h,nptr,0);
			laser_close_tag(h,"Inline");
		liberate( nptr );
		return(0);
		}
}


/*	--------------------------------------------	*/
/*	    l a s e r _ o p e n _ p r o j e c t		*/
/*	--------------------------------------------	*/
/*	called from the 3d viewer production manager	*/
/*	--------------------------------------------	*/
int	laser_open_project( FILE * h )
{
	int	status=0;
	return( sing_open_LASER(h,(struct form_control *) 0) );
}

/*	--------------------------------------------	*/
/*	    l a s e r _ s t a r t _ p r o j e c t		*/
/*	--------------------------------------------	*/
/*	called from the 3d viewer production manager	*/
/*	--------------------------------------------	*/
int	laser_start_project( FILE * h )
{
	if ( LC.useSaf )
	{
		laser_tag(h,"saf:sceneUnit");
		laser_tag(h,"lsr:NewScene");
	}
	return( 0 );
}

/*	-------------------------------------------	*/
/*		s i n g _ c l o s e _ L A S e R 		*/
/*	-------------------------------------------	*/
int	sing_close_LASER( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;
	if ( fptr )
	{
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
		
		}
	}
	laser_saf_footer(h);
	laser_drop_proto_heap();
	return(0);
}

/*	--------------------------------------------	*/
/*	    l a s e r _ c l o s e _ p r o j e c t		*
/*	--------------------------------------------	*/
/*	called from the 3d viewer production manager	*/
/*	--------------------------------------------	*/
int	laser_close_project( FILE * h )
{
	if ( LC.useSaf )
	{
		laser_close_tag(h,"lsr:NewScene");
		laser_close_tag(h,"saf:sceneUnit");
	}
	sing_close_LASER( h, (struct form_control *) 0);
	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_string_data( FILE * h, char * nptr,char * value )
{
	laser_indent(h);
	fprintf(h,"field SFString %s %c%s%c\n",nptr,0x0022,value,0x0022);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_integer_data( FILE * h, char * nptr,int value)
{
	laser_indent(h);
	fprintf(h,"field SFInt32 %s %u\n",nptr,value);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_vector_2d_data( FILE * h, char * nptr,int xvalue,int yvalue)
{
	laser_indent(h);
	fprintf(h,"field SFVec2f %s %u, %u\n",nptr,xvalue,yvalue);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_vector_3d_data( FILE * h, char * nptr,int xvalue,int yvalue,int zvalue)
{
	laser_indent(h);
	fprintf(h,"field SFVec3f %s %u, %u, %u\n",nptr,xvalue,yvalue,zvalue);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_string_member( FILE * h, char * prefix, char * nptr, char * value)
{
	char	work[1024];
	sprintf(work,"%s_%s",prefix,nptr);
	laser_string_data(h,work,value);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_integer_member( FILE * h, char * prefix, char * nptr,int value )
{
	char	work[1024];
	sprintf(work,"%s_%s",prefix,nptr);
	laser_integer_data(h,work,value);
	return;
}


/*	-------------------------------------------	*/
/*	 l a s e r _ p r o t o _ i n t e r f a c e  	*/
/*	-------------------------------------------	*/
void	laser_proto_interface( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;
	/* forms members */
	laser_event_in(h,"OnLoseFocus","SFBool");
	laser_event_out(h,"LoseFocus","SFBool");
	laser_vector_2d_data(h,"atXY",0,0);
	if ( fptr->pages )
	{
		laser_integer_data(h,"pageNumber",0);
		laser_integer_data(h,"pageCount",fptr->pages);
	}
	laser_integer_data(h,"focusItem",0);
	laser_integer_data(h,"focusItems",fptr->items);
		/* widget members */
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch (iptr->Contents.style)
		{
		case	_EDIT_FRAME	:
			laser_string_member(h,"b",iptr->Contents.name,iptr->Contents.name);
			break;
		case	_CHECK_FRAME	:
			laser_integer_member(h,"v",iptr->Contents.name,0);
			break;
		case	_RADIO_FRAME	:
			laser_integer_member(h,"v",iptr->Contents.name,0);
			break;
		case	_SWITCH_FRAME	:
			laser_integer_member(h,"v",iptr->Contents.name,0);
			break;
		case	_SCROLL_FRAME	:
			laser_integer_member(h,"v",iptr->Contents.name,0);
			laser_integer_member(h,"m",iptr->Contents.name,0);
			laser_integer_member(h,"l",iptr->Contents.name,0);
			break;
		case	_PROGRESS_FRAME	:
			laser_integer_member(h,"v",iptr->Contents.name,0);
			laser_integer_member(h,"m",iptr->Contents.name,0);
			break;
		}
	}
	return;
}

/*	-------------------------------------------	*/
/*		l a s e r _ l o s e _ f o c u s 		*/
/*	-------------------------------------------	*/
int	laser_lose_focus( FILE * h, struct form_control * fptr )
{
	char *	fnptr;
	struct	form_control * ffptr;
	char 	work[1024];
	int	i;
	int	started=0;
	struct	form_item * iptr;

	// -----------------------------	
	// Disable all InputSensor Nodes
	// -----------------------------	
	return;

	sprintf(work,"%s%s",_LOSE_PREFIX,fptr->identifier);
	laser_def_tag(h,"Script",work);

	laser_indent(h);
	fprintf(h,"eventIn SFBool loseFocus\n");
	laser_indent(h);
	fprintf(h,"eventIn SFBool onLoseFocus\n");

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch ( iptr->Contents.style )
		{

		case	_DATA_FRAME	:

			if (iptr->Contents.style != _DATA_FRAME	)
				continue;
			else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
				continue;
			else if (!( fnptr = abal_payload(iptr) )) 
				continue;
			else if (!(ffptr = locate_form_control( fnptr ) ))
				continue;

		case	_EDIT_FRAME	:

			laser_indent(h);
			fprintf(h,"field SFNode %s%s USE %s%s\n",
				_LOCAL_PREFIX,iptr->Contents.name,
				_FOCUS_PREFIX,iptr->Contents.name);
		}
	}

	laser_collection(h,"url");

	laser_indent(h);

	fprintf(h,"%cjavascript:\n",0x0022);

	laser_tag(h,"function loseFocus(value)");

		laser_indent(h);
		fprintf(h,"%s%s.onLoseFocus(value);\n",_LOSE_PREFIX,fptr->identifier);

	laser_close_tag(h,(char *) 0);

	/* ---------------------------------------------------------- */
	/* this function is called on the cascade down to clear focus */
	/* ---------------------------------------------------------- */

	laser_tag(h,"function onLoseFocus(value)");
	laser_tag(h,"if ( value )");

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style == _EDIT_FRAME )
		{
			laser_indent(h);
			fprintf(h,"%s%s.enabled = FALSE;\n",_LOCAL_PREFIX,iptr->Contents.name);
		}
		else if (iptr->Contents.style != _DATA_FRAME	)
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else 	
		{
			laser_indent(h);
			fprintf(h,"%s.%s%s(1);\n",iptr->Contents.name,_LOSE_PREFIX,ffptr->identifier);
		}
	}

	laser_close_tag(h,(char *) 0);
	laser_close_tag(h,(char *) 0);

	laser_indent(h);
	fprintf(h,"%c\n",0x0022);

	laser_close_collection(h,"url");
	laser_close_tag(h,"Script");

}

/*	-------------------------------------------	*/
/*		l a s e r _ p r o t o _ b o d y 		*/
/*	-------------------------------------------	*/
int	laser_proto_body( FILE * h, struct form_control * fptr, char * nptr )
{
	int	i;
	int	started=0;
	struct	form_item * iptr;
	struct	form_item * iiptr;
	char	work[1024];
	char	iwork[1024];

	if (!( nptr ))
		nptr = fptr->identifier;
	
	/* prototype nodes definitions */
	if ( fptr->first )
	{
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
			if ( iptr->Contents.style != _IMAGE_FRAME )
				continue;
			else if (( iptr->Contents.align & 0x000F ) != _I_TILE )
				continue;
			else
			{
				LASER_pattern( h, iptr );
			}
		}

		if ( fptr->pages )
		{
			/* --------------------------------- */
			/* display page zero and tab buttons */
			/* --------------------------------- */
			iiptr = (struct form_item *) 0;
			for (	iptr=fptr->first;
				iptr != (struct form_item *) 0;
				iptr = iptr->next )
			{
				if (!( iptr->Contents.page ))
					LASER_widget( h, iptr );
				else if ( iptr->Contents.style != _TAB_FRAME )
					continue;
				else
				{
					LC.fontWidth  = guifontsize(iptr->Contents.font);
					LC.fontHeight = (LC.fontWidth >> 8); 
					LC.fontWidth  &= 0x00FF;
					laser_tab_button( h, iptr );
				}
			}
			/* --------------------------------- */
			/* display  switched  page  contents */
			/* --------------------------------- */
			for ( i=1; i <= fptr->pages; i++ )
			{
				for (	iptr=fptr->first;
					iptr != (struct form_item *) 0;
					iptr = iptr->next )
				{
					if ( iptr->Contents.page != i )
					{
						continue;
					}
					else if ( iptr->Contents.style == _TAB_FRAME )
					{
						LC.fontWidth  = guifontsize(iptr->Contents.font);
						LC.fontHeight = (LC.fontWidth >> 8); 
						LC.fontWidth  &= 0x00FF;
						if (!( iiptr )) iiptr = iptr; 
						started = laser_tab_frame ( h, iptr, fptr,started );
					}
					else	LASER_widget( h, iptr );
				}
			}
			if ( started )
			{
				laser_defs_footer(h);
				if ( iiptr )
				{
					sprintf(work,"%s%s",_FRAME_PREFIX,iiptr->Contents.name);
					sprintf(iwork,"%s%s",_FRAME_PREFIX,nptr);
					laser_proto_use( h, 0,0, work, iwork, 1 );
					if (!( LC.useLaser ))
					{
						laser_frame_script( h, fptr );
					}
				}
				started=0;
				/* --------------------------------- */
				/* generate page trigger conditions  */
				/* --------------------------------- */
				for (	iptr=fptr->first;
					iptr != (struct form_item *) 0;
					iptr = iptr->next )
				{
					if ( iptr->Contents.style != _TAB_FRAME )
						continue;
					else if ( LC.useLaser )
						laser_tab_conditional( h, iptr, fptr );
				}
			}
		}
		else
		{
			// ----------------------------------------
			// Generate order group of svg widgets 
			// ----------------------------------------
			for (	iptr=fptr->first;
				iptr != (struct form_item *) 0;
				iptr = iptr->next )
			{
				// -----------------------------------------
				// Each widget is an ordered group of shapes
				// -----------------------------------------
				LASER_widget( h, iptr );
			}
			laser_instance_popups( h , fptr );
		}

		laser_lose_focus(h,fptr);

		// --------------------------		
		// Generate Route Information 
		// --------------------------		
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
			if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
				continue;
			switch ( iptr->Contents.style )
			{
			case	_SWITCH_FRAME	:
				laser_switch_route( h, iptr );
				break;
			case	_SCROLL_FRAME	:
				laser_scroll_route( h, iptr );
				break;
			case	_CHECK_FRAME	:
				laser_check_route( h, iptr );
				break;
			case	_RADIO_FRAME	:
				laser_radio_route( h, iptr );
				break;
			case	_TAB_FRAME	:
				laser_tab_route( h, iptr );
				break;
			case	_EDIT_FRAME	:
				laser_edit_route( h, iptr );
				break;
			}
		}
	}
	return(0);
}

/*	-------------------------------------------	*/
/*	 l a s e r _ p r o t o _ d e f i n i t i o n	*/
/*	-------------------------------------------	*/
/* 	this function generates the prototype file	*/
/*	that will be referenced by the externproto	*/
/*	instructions for the description of the obj	*/
/*	-------------------------------------------	*/
void	laser_proto_dependance( FILE * h, struct form_control * fptr )
{
	struct	form_item * 	iptr;
	char *			fnptr;
	struct	form_control * 	ffptr;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if (iptr->Contents.style != _DATA_FRAME	)
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	laser_proto_definition( h, ffptr );
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ p r o t o _ d e f i n i t i o n		*/
/*	-----------------------------------------------------------------------	*/
/*	performs a definition of a complete forms component.			*/
/*	-----------------------------------------------------------------------	*/
void	laser_proto_definition( FILE * handle, struct form_control * fptr, char * nptr )
{
	FILE *	h;
	char	work[1024];
	struct	form_item * iptr;
	char *	extname;
	struct window_control Window;

	/* avoid adding double items */
	/* ------------------------- */
	if (!( laser_add_proto_item( fptr->identifier ) ))
		return;
	else	form_Dimensions( &Window, fptr );

	h = handle;

	laser_proto_dependance(h,fptr);

	laser_defs_header( h, fptr->identifier, _FORM_SUFFIX);

	laser_exchange_mpeg_production( &Window );
	laser_proto_body(h, fptr, fptr->identifier );
	laser_exchange_mpeg_production( &Window );

	laser_defs_footer(h);

	return;
}

/*	-------------------------------------------	*/
/*	l a s e r _ c h e c k _ n a m e s p a c e s	*/
/*	-------------------------------------------	*/
/*	to ensure non null and to reset to defaults	*/
/*	-------------------------------------------	*/
void	laser_check_namespaces()
{
	if (!( LC.safNs ))
		LC.safNs = allocate_string( _SAF_NAMESPACE );
	if (!( LC.laserNs ))
		LC.laserNs = allocate_string( _LASER_NAMESPACE );
	if (!( LC.svgNs ))
		LC.svgNs = allocate_string( _SVG_NAMESPACE );
	return;
}

/*	-------------------------------------------	*/
/*	  l a s e r _ f o c u s _ m a n a g e r 	*/
/*	-------------------------------------------	*/
void	laser_focus_manager( FILE * h, struct form_item * fptr )
{
	laser_open_script( h );
		laser_indent(h);
		fprintf(h,"var thisFocus = 0;\n");
#ifdef	_OLD_FOCUS_MAN
	laser_indent(h);
	fprintf(h,"function %s(kvalue) {\n",_INPUT_MANAGER);
		mpeg_enter();
		laser_indent(h);
		fprintf(h,"if ( thisFocus ) {\n");
			mpeg_enter();
			laser_indent(h);
			fprintf(h,"var textvalue = thisFocus.getAttribute(%cnodeValue%c);\n",0x0022,0x0022);
			laser_indent(h);
			fprintf(h,"alert(textvalue);\n");
		laser_close_brace(h);
	laser_close_brace(h);
#endif
	laser_indent(h);
	fprintf(h,"function %s(tgt) {\n",_FOCUS_MANAGER);
	mpeg_enter();
#ifdef	_OLD_FOCUS_MAN
		laser_indent(h);
		fprintf(h,"if ( thisFocus ) { ");
		fprintf(h,"thisFocus.setAttribute(%cvisibility%c,%chidden%c); }\n",
			0x0022,0x0022,
			0x0022,0x0022);
		laser_indent(h);
		fprintf(h,"thisFocus = document.getElementById(tgt);\n");
		laser_indent(h);
		fprintf(h,"if ( thisFocus ) { ");
		fprintf(h,"thisFocus.setAttribute(%cvisibility%c,%cvisible%c); }\n",
			0x0022,0x0022,
			0x0022,0x0022);
#endif
		laser_indent(h);
		fprintf(h,"thisFocus = document.getElementById(tgt);\n");
		laser_indent(h);
		fprintf(h,"if ( thisFocus ) { thisFocus.focus(); }\n");
	laser_close_brace(h);
	laser_close_script( h );
	return;
}

/*	-------------------------------------------	*/
/*	l a s e r _ s e t _ f o r m _ o p t i o n s	*/
/*	-------------------------------------------	*/
void	laser_set_form_options( struct form_control * fptr )
{
	LC.useSaf 	= ( fptr->extension &   1 ? 1 : 0 );
	LC.useLaser 	= ( fptr->extension &   2 ? 1 : 0 );
	LC.withComments = ( fptr->extension &   4 ? 1 : 0 );
	LC.testData	= ( fptr->extension &   8 ? 1 : 0 );
	LC.genMp4	= ( fptr->extension &  16 ? 1 : 0 );
	LC.reserved2	= ( fptr->extension &  32 ? 1 : 0 );
	LC.reserved3	= ( fptr->extension &  64 ? 1 : 0 );
	LC.reserved4	= ( fptr->extension & 128 ? 1 : 0 );
	return;
}

/*	-------------------------------------------	*/
/*	      e x p o r t _ L A S e R _ f o r m 		*/
/*	-------------------------------------------	*/
int	export_LASER_form( FILE * h, struct form_control * fptr )
{
	int	i;
	struct	form_item * iptr;

	prepare_Form( fptr );

	LC.editField = 0;
	LC.groupId = 0,
	LC.od    = LC.es 	  = 0;
	LC.width = 800; LC.height = 600;

	laser_check_namespaces();
	laser_set_form_options( fptr );

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style == _WINDOW_FRAME )
		{
			LC.width = iptr->Contents.w;
			LC.height = iptr->Contents.h;
			break;
		}
	}

	laser_mpeg_production();
	laser_input_streams();


	sing_open_LASER( h, fptr );
	laser_start_project(h);

	laser_open_svg(h);
	laser_proto_definition( h, fptr, fptr->identifier );
	laser_proto_instance( h, fptr,_THIS_INSTANCE,0,0,1,fptr->identifier );
//	laser_focus_manager(h,fptr);
	laser_close_svg(h);

	laser_close_project(h);
	return(0);
}

/*	-------------------------------------------	*/
/*	     e x p o r t _ L A S e R _ p a g e 		*/
/*	-------------------------------------------	*/
int	export_LASER_page( FILE * h, struct form_control * fptr )
{
	laser_check_namespaces();
	laser_set_form_options( fptr );
	return(0);
}

/*	---------------------------------------------	*/
/*	a c c e p t _ l a s e r _ p r o d u c t i o n	*/
/*	---------------------------------------------	*/
int	accept_laser_production( struct form_control * fptr )
{
	laser_check_namespaces();
	laser_set_form_options( fptr );
	if ( laser_production_parameters(
		&fptr->prodname,
		&fptr->identifier,
		&LC.safNs, &LC.laserNs, &LC.svgNs,
		&LC.useSaf,
		&LC.useLaser,
		&LC.withComments,
		&LC.testData,
		&LC.genMp4,
		&LC.reserved2,
		&LC.reserved3,
		&LC.reserved4 )  == 27 )
		return( 27 );
	else
	{
		fptr->extension = 0;
		if ( LC.useSaf 		) fptr->extension |=    1;
		if ( LC.useLaser 	) fptr->extension |=    2;
		if ( LC.withComments 	) fptr->extension |=    4;
		if ( LC.testData	) fptr->extension |=    8;
		if ( LC.genMp4		) fptr->extension |=   16;
		if ( LC.reserved2	) fptr->extension |=   32;
		if ( LC.reserved3	) fptr->extension |=   64;
		if ( LC.reserved4	) fptr->extension |=  128;
		if ( LC.useSaf != 0 )
			fptr->prodname = enforce_extension( fptr->prodname, _EXT_LSR );
		else 	fptr->prodname = enforce_extension( fptr->prodname, _EXT_SVG );
		return(13);
	}
}

#endif	/* _singLASER_c */


