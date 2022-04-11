#ifndef	_singLASER_c
#define	_singLASER_c

#include "abaldata.h"

#define	_EXT_PROTO	".lsh"
#define	_EXT_LSR 	".xsr"
#define	_EXT_MP4 	".mp4"
#define	_EXT_SVG 	".svg"
#define	_BUTTON_PRESS	'BP'
#define	_BUTTON_PRESS_FRAME	'PF'

/*	-----------------------------------	*/
/*	Definition of Standard File Methods	*/
/*	-----------------------------------	*/
#define	 _ASSIGN_COMMAND 	"Assign"
#define	 _OPEN_COMMAND 		"Open"
#define	 _CLOSE_COMMAND 	"Close"
#define	 _CFILE_COMMAND 	"Cfile"
#define	 _DFILE_COMMAND 	"Dfile"
#define	 _RENAME_COMMAND 	"Rename"
#define	 _READ_COMMAND 		"Read"
#define	 _WRITE_COMMAND 	"Write"
#define	 _REWIND_COMMAND 	"Rewind"
#define	 _MODIFY_COMMAND 	"Modify"
#define	 _SEARCH_COMMAND 	"Search"
#define	 _INSERT_COMMAND 	"Insert"
#define	 _DELETE_COMMAND 	"Delete"
#define	 _UPDATE_COMMAND 	"Update"
#define	 _FIRST_COMMAND 	"First"
#define	 _DOWN_COMMAND 		"Down"
#define	 _UP_COMMAND 		"Up"
#define	 _LAST_COMMAND 		"Last"
#define	 _KEY_COMMAND 		"Key"
#define	 _LINK_COMMAND 		"Link"
#define	 _CKEY_COMMAND 		"Ckey"
#define	 _CLINK_COMMAND 	"Clink"
#define	 _POSIT_COMMAND 	"Posit"
#define	 _COUNT_COMMAND 	"Count"
#define	 _COLLECT_COMMAND 	"Collect"
#define	 _LOCATE_COMMAND 	"Locate"
#define	 _JOIN_COMMAND 		"Join"
#define	 _CJOIN_COMMAND 	"Cjoin"
#define	 _FILE_COMMAND 		"File"
#define	 _RECORD_COMMAND 	"Record"

/*	-----------------------------------	*/
/*	Definition of Standard File Members	*/
/*	-----------------------------------	*/
#define	_FILE_METHOD		"FileMethod"
#define	_FILE_NAME		"FileName"
#define	_FILE_HANDLE		"FileHandle"
#define	_FILE_ERROR		"FileError"
#define	_FILE_SECTOR		"FileSector"

#define	_RECORD_INDEX		"RecordIndex"
#define	_RECORD_MARKER		"RecordMarker"
#define	_RECORD_LENGTH		"RecordLength"
#define	_RECORD_QUESTION	"RecordQuestion"
#define	_RECORD_DIRECTION	"RecordDirection"

#define	_COLLECT_COUNT		"CollectCount"
#define	_COLLECT_ITEM		"CollectItem"
#define	_COLLECT_TABLE		"CollectTable"

#define	_DEFAULT_URL	"http://127.0.0.1:8088"

/*	-----------------------------------	*/
/*	Definition of standard JS MEthods	*/
/*	-----------------------------------	*/
#define	_JS_FILE_ERROR	"js_FileError"
#define	_JS_XML_VALUE	"js_XmlValue"
#define	_SOAP_REQUEST	"js_SoapRequest"
#define	_SERVER_COMMAND	"js_ServerCommand"
#define	_PRESS_MANAGER	"js_ButtonPress"
#define	_RELEASE_MANAGER "js_ButtonRelease"
#define	_TIMER_MANAGER "js_ButtonTimer"

#define	_FOCUS_MANAGER	"focusManager"
#define	_INPUT_MANAGER	"inputManager"
#define	_THIS_INSTANCE	"This"

#define	_ONEVENT_PREFIX	"onevent_"
#define	_TOGGLE_PREFIX	"toggle_"
#define	_FOCUS_PREFIX	"focus_"
#define	_SHOW_PREFIX	"show_"
#define	_CREATE_PREFIX	"create_"
#define	_REMOVE_PREFIX	"remove_"
#define	_EVENT_PREFIX	"event_"
#define	_CLICK_PREFIX	"click_"
#define	_HIDE_PREFIX	"hide_"
#define	_LOSE_PREFIX	"lose_"
#define	_SENSOR_PREFIX	"sensor_"
#define	_TRIGGER_PREFIX	"trigger_"
#define	_PRESS_PREFIX	"press_"
#define	_BOOLEAN_TOGGLE	"booleanToggle"
#define	_PATTERN_PREFIX	"pattern_"
#define	_FORM_SUFFIX	"_form"
#define	_PAGE_SUFFIX	"_page"
#define	_LOCAL_PREFIX	"local_"
#define	_LOCAL_PREFIX	"local_"
#define	_GLOBAL_PREFIX	"globalData_"
#define	_RECORD_PREFIX	"fileRecord_"
#define	_REQUEST_PREFIX	"fileRequest_"

#define	_BUTTON_PREFIX	"button_"
#define	_OVERLAY_PREFIX	"overlay_"
#define	_MODULE_PREFIX	"module_"
#define	_WIDGET_PREFIX	"widget_"
#define	_COLUMN_PREFIX	"column_"
#define	_LINE_PREFIX	"line_"
#define	_BUFFER_PREFIX	"buffer_"
#define	_VALUE_PREFIX	"value_"
#define	_MAX_PREFIX	"max_"
#define	_LIMIT_PREFIX	"limit_"
#define	_FRAME_PREFIX	"frame_"
#define	_TRUE_PREFIX	"true_"

#define	_CICO_PREFIX	"cico_"
#define	_KEYDOWN_PREFIX	"keydown_"
#define	_KEYUP_PREFIX	"keyup_"
#define	_ACTDOWN_PREFIX	"actdown_"


#define	_SVG_NAMESPACE		"http://www.w3.org/2000/svg"
#define	_XLINK_NAMESPACE	"http://www.w3.org/1999/xlink"
#define	_EVENT_NAMESPACE	"http://www.w3.org/2001/xml-events"
#define	_SAF_NAMESPACE		"urn:mpeg:mpeg4:SAF:2005"
#define	_LASER_NAMESPACE	"urn:mpeg:mpeg4:LASeR:2005"


static	int	laser_hilight=0;
static	int	laser_lolight=0;
static	int	laser_backwash=0;
static	int	laser_black=0;
static	int	laser_white=0;
static	int	laser_control_frame=0;
static	int	laser_control_backwash=0;
static	int	laser_palette_title=0;
static	int	laser_palette_text=0;
static	int	laser_palette_label=0;

static	struct	laser_configuration {
	char *	scriptName;		/* type of scripting used				*/
	int	w3cWidget;		/* generates a widget package				*/
	int	buttonPress;		/* true when button press script required		*/
	int	soapCookies;		/* causes soap cookies to be managed in JS for Ajax 	*/
	int	needBoolean;		/* counter of check and switch elements.		*/
	int	keepAmpersand;		/* switch allowing ampersand in buttons to disappear	*/
	int	groupId;		/* counts the group elements generated			*/
	int	useRef;			/* activate ref and id generation			*/
	int	useSaf;			/* activate SAF Production 				*/
	int	useLaser;		/* activate LASER Specific Production.			*/
	int	testData;		/* activate display of edit and table test data		*/
	int	withDebug;		/* comments are added to closures for debug of source 	*/
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
	int	methodText;		/* process and generate methodf text			*/
	int	soapInterface;		/* reserved in the interface for future use		*/
	int	serverCommand;		/* reserved in the interface for future use		*/
	int	serverPhp;		/* reserved in the interface for future use		*/
	int	serverAbal;		/* reserved in the interface for future use		*/
	char *	serverUrl;		/* url of server for soap or server command		*/
	struct	form_control * form;	/* current form 					*/
	struct	form_item * widget;	/* current widget					*/
	} LC = 	{ 
		"javascript",		/* name of the scripting used				*/
		0,			/* generate widget packaging				*/
		0,			/* dont need button press				*/
		3,			/* need cookie management				*/
		0,			/* need booleans 					*/
		1,			/* make ampersand disappear				*/
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

		0,0,0,0,0,0,			/* 4 reserved values */

		(struct form_control *) 0,	/* current form 		*/
		(struct form_item *) 0		/* current widget		*/

		};

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ s e t _ p a l e t t e 			*/
/*	-----------------------------------------------------------------------	*/
/*	sets the colours to be used in the laser gui palette.			*/
/*	-----------------------------------------------------------------------	*/
static	void	laser_set_palette( struct form_control * fptr )
{
	laser_hilight = standard_hilight;
	laser_lolight = standard_lolight;
	laser_backwash = standard_backwash;
	laser_black = standard_black;
	laser_white = standard_white;
	laser_control_frame = standard_black;
	laser_control_backwash = standard_hilight;
	laser_palette_title = standard_title;
	laser_palette_text = standard_text;
	laser_palette_label = 26;
	return;
}

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

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ i n p u t _ s t r e a m s			*/
/*	-----------------------------------------------------------------------	*/
/*	initiation of elementary streams for LASeR production.			*/
/*	-----------------------------------------------------------------------	*/
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
/*	production operation.							*/
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
	return;
	if ( LC.withDebug )
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
	fprintf(h,"</%s>\n",nptr);
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
/*			l a s e r _ t r i g g e r _ g r o u p			*/
/*	-----------------------------------------------------------------------	*/
/*	opens a laser scene group with id and trigger onclick tag.		*/
/*	for use by booleans only						*/
/*	-----------------------------------------------------------------------	*/
void	laser_trigger_group( FILE * h, struct form_item * iptr )
{
	laser_indent(h);
	fprintf(h,"<g id=%c%s%s%c onclick=%c%s('%s%s')%c>\n",
		0x0022,_SENSOR_PREFIX,iptr->Contents.name,0x0022,
		0x0022,_BOOLEAN_TOGGLE,_TRUE_PREFIX,iptr->Contents.name,0x0022);
	mpeg_enter();
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ t a b l e _ s c r i p t 			*/
/*	-----------------------------------------------------------------------	*/
/*	opens a laser scene script block for definition of a table trigger	*/
/*	-----------------------------------------------------------------------	*/
void	laser_table_script( FILE * h, struct form_item * iptr )
{
	if ( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ? 2 : 0 )
	{
		laser_open_script(h);
		laser_indent(h);
		fprintf(h,"function %s%s(rid,cid) {\n",_TRIGGER_PREFIX,iptr->Contents.name);
		mpeg_enter();
		laser_indent(h);
		fprintf(h,"document.getElementById(%c%s%s%c).textContent=rid.toString();\n",
			0x0022,_LINE_PREFIX,iptr->Contents.name,0x0022);
		laser_indent(h);
		fprintf(h,"document.getElementById(%c%s%s%c).textContent=cid.toString();\n",
			0x0022,_COLUMN_PREFIX,iptr->Contents.name,0x0022);
		if (method_is_valid(iptr->Contents.events->on_event) )
		{
			laser_indent(h);
			fprintf(h,"%s%s();\n",_EVENT_PREFIX,iptr->Contents.name);
		}
		laser_close_brace( h );
		laser_close_script(h);
	}
	return;	
}


/*	-----------------------------------------------------------------------	*/
/*			   l a s e r _ v a l u e _ g r o u p			*/
/*	-----------------------------------------------------------------------	*/
/*	opens a laser scene group with id for use by boolean switchs only	*/
/*	-----------------------------------------------------------------------	*/
void	laser_value_group( FILE * h, struct form_item * iptr )
{
	laser_indent(h);
	fprintf(h,"<g id=%c%s%s%c>\n",0x0022,_TRUE_PREFIX,iptr->Contents.name,0x0022);
	mpeg_enter();
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ m e t h o d _ g r o u p			*/
/*	-----------------------------------------------------------------------	*/
/*	opens a laser scene group with id and trigger onclick tag.		*/
/*	for use by booleans only						*/
/*	-----------------------------------------------------------------------	*/
int	laser_method_group( FILE * h, struct form_item * iptr, char * mptr )
{
	laser_indent(h);
	fprintf(h,"<g onclick=%c%s%s()%c>\n",0x0022,mptr,iptr->Contents.name,0x0022);
	mpeg_enter();
	return(1);
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ r a d i o _ g r o u p			*/
/*	-----------------------------------------------------------------------	*/
/*	opens a laser scene radio group tag.					*/
/*	-----------------------------------------------------------------------	*/
void	laser_radio_group( FILE * h, struct form_item * iptr )
{
	if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
	{
		laser_indent(h);
		fprintf(h,"<g id=%c%s%u_%s%c visibility=%c%s%c onclick=%c%s%s(%u)%c>\n",
			0x0022,_WIDGET_PREFIX,iptr->Contents.radio,iptr->Contents.name,0x0022,
			0x0022,"hidden",0x0022,
			0x0022,_TRIGGER_PREFIX,iptr->Contents.name,
			iptr->Contents.radio,0x0022);
		mpeg_enter();
	}
	else
	{
		laser_indent(h);
		fprintf(h,"<g id=%c%s%u_%s%c visibility=%c%s%c onclick=%c%s%s(%u)%c>\n",
			0x0022,_WIDGET_PREFIX,iptr->Contents.radio,iptr->Contents.name,0x0022,
			0x0022,"inherit",0x0022,
			0x0022,_TRIGGER_PREFIX,iptr->Contents.name,
			iptr->Contents.radio,0x0022);
		mpeg_enter();
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		   l a s e r _ w i d g e t _ e d i t _ g r o u p		*/
/*	-----------------------------------------------------------------------	*/
/*	opens a laser scene group tag for edit widgets with focus launch.	*/
/*	this is no longer called since the editable and focusable atributes	*/
/*	NOTNEEDED								*/
/*	-----------------------------------------------------------------------	*/
void	laser_widget_edit_group( FILE * h, struct form_item * iptr )
{
	if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
	{
		laser_indent(h);
		fprintf(h,"<g id=%c%s%s%c onclick=%c%s('%s%u_%s')%c visibility=%c%s%c>\n",
			0x0022,_WIDGET_PREFIX,iptr->Contents.name,0x0022,
			0x0022,_FOCUS_MANAGER,_BUFFER_PREFIX,iptr->sequence,iptr->Contents.name,0x0022,
			0x0022,"hidden",0x0022);
		mpeg_enter();
	}
	else
	{
		laser_indent(h);
		fprintf(h,"<g id=%c%s%s%c onclick=%c%s('%s%u_%s')%c visibility=%c%s%c>\n",
			0x0022,_WIDGET_PREFIX,iptr->Contents.name,0x0022,
			0x0022,_FOCUS_MANAGER,_BUFFER_PREFIX,iptr->sequence,iptr->Contents.name,0x0022,
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
/*			  l a s e r _ h i d d e n _ g r o u p  			*/
/*	-----------------------------------------------------------------------	*/
/*	opens a hidden laser scene widget group tag.					*/
/*	-----------------------------------------------------------------------	*/
void	laser_hidden_group( FILE * h, char * id )
{
	laser_indent(h);
	fprintf(h,"<g id=%c%s%c visibility=%chidden%c>\n",0x0022,id,0x0022,0x0022,0x0022);
	mpeg_enter();
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
/*				l a s e r _ f i l z o n e			*/
/*	-----------------------------------------------------------------------	*/
/*	draws and fills the rectangle of the provided dimensions unless zero	*/
/*	-----------------------------------------------------------------------	*/
void	laser_named_filzone( FILE * handle, int x, int y, int w, int h, int colour, char * nptr, char * vptr )
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
	fprintf(handle,"<rect id=%c%s%c visibility=%c%s%c x=%c%u%c y=%c%u%c width=%c%u%c height=%c%u%c fill=%c%s%c/>\n",
		0x0022,nptr,0x0022,
		0x0022,vptr,0x0022,
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
/*			l a s e r _ n a m e d _ c i r c l e			*/
/*	-----------------------------------------------------------------------	*/
/*	draws and fills a named curcle.						*/
/*	-----------------------------------------------------------------------	*/
void	laser_named_circle( FILE * handle, int x, int y, int w, int h, int colour, char * nptr, char * vptr )
{
	char	bwork[1024];
	char	fwork[1024];

	// ------------------------
	// generate coloured circle 
	// ------------------------
	laser_colour( (colour & 0x00FF) , fwork);
	bifs_indent( handle );
	fprintf(handle,"<circle id=%c%s%c visibility=%c%s%c cx=%c%u%c cy=%c%u%c r=%c%u%c fill=%c%s%c/>\n",
		0x0022,nptr,0x0022,
		0x0022,vptr,0x0022,
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

	if ( style == _BUTTON_PRESS )
		laser_draw_relief(handle, atx,aty,nbx,nby,laser_lolight,laser_backwash,laser_hilight,(char *) 0);
	else if ( style == _BUTTON_PRESS_FRAME )
		laser_draw_relief(handle, atx,aty,nbx,nby,laser_lolight,transparent,laser_hilight,(char *) 0);

	else switch (( style & _FRAME_TYPE )) {

		case	_RADIO_FRAME :
			laser_circle(handle, atx,aty,nbx,nby,laser_control_frame,(char *) 0);
			laser_circle(handle, atx+1,aty+1,nbx-2,nby-2,laser_control_backwash,(char *) 0);
			break;

		case	_EDIT_FRAME :
			laser_draw_relief(handle, atx,aty,nbx,nby,laser_control_frame,laser_control_backwash,laser_control_frame,name);
			break;

		case	_OUTSET_FRAME :
			laser_draw_relief(handle, atx,aty,nbx,nby,laser_hilight,laser_backwash,laser_lolight,(char *) 0);
			break;

		case	_BUTTON_FRAME :
			laser_draw_relief(handle, atx,aty,nbx,nby,laser_hilight,laser_backwash,laser_lolight,name);
			break;

		case	_WINDOW_FRAME :
			laser_draw_relief(handle, atx,aty,nbx,nby,laser_hilight,laser_backwash,laser_lolight,(char *) 0);
			break;

		case	_SCROLL_FRAME  :
			laser_draw_relief(handle, atx,aty,nbx,nby,laser_lolight,laser_backwash-1,laser_hilight,name);
			break;

		case	_INSET_FRAME  :
			laser_draw_relief(handle, atx,aty,nbx,nby,laser_lolight,laser_backwash,laser_hilight,(char *) 0);
			break;

		case	_RIDGE_FRAME  :
			laser_draw_relief(handle, atx,aty,nbx,nby,laser_hilight,laser_backwash,laser_lolight,(char *) 0);
			if (( nbx > 2 ) && ( nby > 2 )) 
				laser_draw_relief(handle,(atx+1),(aty+1),(nbx-2),(nby-2),laser_lolight,transparent,laser_hilight,(char *) 0);
			break;

		case	_GROOVE_FRAME :
			transparent = transparent;
			laser_draw_relief(handle, atx,aty,nbx,nby,laser_lolight,laser_backwash,laser_hilight,(char *) 0);
			if (( nbx > 2 ) && ( nby > 2 )) 
				laser_draw_relief(handle, (atx+1),(aty+1),(nbx-2),(nby-2),laser_hilight,transparent,laser_lolight,(char *) 0);
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

/*	--------------------------------------------------	*/
/*		l a s e r _ u s e _ u n q u o t e d		*/
/*	--------------------------------------------------	*/
/*	unquoted reference to another widgets member zone	*/
/*	--------------------------------------------------	*/
int	laser_use_unquoted( FILE * handle, int x, int y, int w, int h,char * mptr, char * wptr, int colour, int align )
{
	int	fheight=0;
	char	work[1024];
	char	awork[1024];
	char	dwork[1024];
	laser_colour( (colour & 0x00FF) , work);
//	x = laser_align( awork, align, x, w );
	strcpy(awork,"start");
	laser_decoration( dwork, align );
	fheight = ((LC.fontHeight * 4) / 5);
	laser_indent(handle);
	fprintf(handle,"<use x=%c%d%c y=%c%d%c xlink:href=%c#%s%s%c",
		0x0022,x,0x0022,0x0022,y,0x0022,
		0x0022,mptr,wptr,0x0022);
	fprintf(handle," font-size=%c%u%c %s text-anchor=%c%s%c fill=%c%s%c/>\n",
		0x0022,fheight,0x0022,
		dwork,
		0x0022,awork,0x0022,
		0x0022,work,0x0022);
	return;
}		

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ u n q u o t e d _ w i d g e t 		*/
/*	-----------------------------------------------------------------------	*/
/*	generates a reference to an edit buffer text element 			*/
/*	-----------------------------------------------------------------------	*/
int	laser_unquoted_widget( FILE * handle, int x, int y, int w, int h, char * wptr, char * mptr, int colour, int align )
{
	char	work[1024];
	struct	form_control * fptr;
	struct	form_item * iptr;
	if (!( fptr = LC.form ))
		return(0);
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if (!( iptr->Contents.name ))
			continue;
		else if (!( strcmp( wptr, iptr->Contents.name ) ))
			break;
	}
	if (!( iptr ))
		return(0);
	else
	{
		x -= iptr->Contents.x;
		y -= iptr->Contents.y;
	}
	if (!( strcmp( mptr, "buffer" ) ))
	{
		sprintf(work,"%s%u_",_BUFFER_PREFIX,iptr->sequence);
		return(laser_use_unquoted(handle,x,y,w,h,work,wptr,colour,align));
	}
	else if (!( strcmp( mptr, "value" ) ))
		return(laser_use_unquoted(handle,x,y,w,h,_VALUE_PREFIX,wptr,colour,align));
	else if (!( strcmp( mptr, "limit" ) ))
		return(laser_use_unquoted(handle,x,y,w,h,_LIMIT_PREFIX,wptr,colour,align));
	else if (!( strcmp( mptr, "max" ) ))
		return(laser_use_unquoted(handle,x,y,w,h,_MAX_PREFIX,wptr,colour,align));
	else	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ u n q u o t e d _ m e m b e r		*/
/*	-----------------------------------------------------------------------	*/
/*	generates a reference to an edit buffer text element 			*/
/*	-----------------------------------------------------------------------	*/
int	laser_unquoted_member( FILE * handle, int x, int y, int w, int h, char * mptr, int colour, int align )
{
	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ u n q u o t e d _ m e t h o d		*/
/*	-----------------------------------------------------------------------	*/
/*	generates a reference to an edit buffer text element 			*/
/*	-----------------------------------------------------------------------	*/
int	laser_unquoted_method( FILE * handle, int x, int y, int w, int h, char * mptr, int colour, int align )
{
	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ u n q u o t e d 			*/
/*	-----------------------------------------------------------------------	*/
/*	generates a reference to an edit buffer text element 			*/
/*	-----------------------------------------------------------------------	*/
int	laser_unquoted( FILE * handle, int x, int y, int w, int h, char * mptr, int colour, int align )
{
	char	work[1024];
	char *	nptr;
	strcpy(work,mptr);
	nptr = mptr = work;
	/* -------------------------------- */
	/* scan to eventual member operator */
	/* -------------------------------- */
	while ( *nptr )
	{
		if ( *nptr == '.' )
			break;
		else	nptr++;
	}
	if ( *nptr == '.' )
	{
		*(nptr++) = 0;
		return( laser_unquoted_widget(	  handle, x, y, w, h, mptr, nptr, colour, align ) );
	}
	else if ( laser_unquoted_member(  handle, x, y, w, h, mptr, colour, align ) )
		return( 1 );
	else	return( laser_unquoted_method(  handle, x, y, w, h, mptr, colour, align ) );
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
	if (!( colour ))
		colour = laser_palette_label;
	if (!( mptr ))
		return;
	else if ( *mptr == _UNQUOTED_STRING )
		if ( laser_unquoted(  handle, x, y, w, h, (mptr+1), colour, align ) )
			return;

	laser_colour( (colour & 0x00FF) , work);
	x = laser_align( awork, align, x, w );
	laser_decoration( dwork, align );
	bifs_indent( handle );
	fheight = ((LC.fontHeight * 4) / 5);
	fprintf(handle,"<text x=%c%u%c y=%c%u%c font-size=%c%u%c %s text-anchor=%c%s%c fill=%c%s%c>",
		0x0022,x,0x0022,
		0x0022,y+((LC.fontHeight*5)/6),0x0022,
		0x0022,fheight,0x0022,
		dwork,
		0x0022,awork,0x0022,
		0x0022,work,0x0022);
	while ( *mptr == ' ' )
		mptr++;
	laser_text_string( handle, mptr );
	fprintf(handle,"</text>\n");
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
		fprintf(handle,"<text id=%c%s%u_%s%c x=%c%u%c y=%c%u%c font-size=%c%u%c %s text-anchor=%c%s%c fill=%c%s%c focusable = %c%s%c editable=%c%s%c visibility=%c%s%c>",
			0x0022,_BUFFER_PREFIX,LC.widget->sequence,nptr,0x0022,
			0x0022,x,0x0022,
			0x0022,y+((LC.fontHeight*5)/6),0x0022,
			0x0022,fheight,0x0022,
			dwork,
			0x0022,awork,0x0022,
			0x0022,work,0x0022,
			0x0022,"true",0x0022,
			0x0022,"true",0x0022,
			0x0022,"inherit",0x0022);
		while ( *mptr == ' ' )
			mptr++;
		laser_text_string( handle, mptr );
		fprintf(handle,"</text>\n");
		return;
	}
}

/*	-----------------------------------------------------------------------	*/
/*			      l a s e r _ t e x t _ c e l l   			*/
/*	-----------------------------------------------------------------------	*/
/*	this function is called from by laser tablewidget production function to*/
/*	define and connect the text value buffersfor use by the standard editor	*/
/*	-----------------------------------------------------------------------	*/
void	laser_text_cell( FILE * handle, int x, int y, int w, int h, char * mptr, int colour, int align, char * nptr,int focus,int rowid,int colid,char * wname )
{
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
		fprintf(handle,"<text id=%c%s%c x=%c%u%c y=%c%u%c font-size=%c%u%c %s text-anchor=%c%s%c fill=%c%s%c focusable = %c%s%c editable=%c%s%c visibility=%c%s%c",
			0x0022,nptr,0x0022,
			0x0022,x,0x0022,
			0x0022,y+((LC.fontHeight*5)/6),0x0022,
			0x0022,fheight,0x0022,
			dwork,
			0x0022,awork,0x0022,
			0x0022,work,0x0022,
			0x0022,(focus & 1 ?"true":"false"),0x0022,
			0x0022,(focus & 1 ?"true":"false"),0x0022,
			0x0022,"inherit",0x0022);
		if ( focus & 2 )
		{
			fprintf(handle," onclick='%s%s(%u,%u)'",_TRIGGER_PREFIX,wname,rowid,colid);
		}
		fprintf(handle,">");
		while ( *mptr == ' ' )
			mptr++;
		laser_text_string( handle, mptr );
		fprintf(handle,"</text>\n");
		return;
	}
}

/*	-----------------------------------------------------------------------	*/
/*			      l a s e r _ t e x t _ v a l u e			*/
/*	-----------------------------------------------------------------------	*/
/*	this function is called from by laser edit widget production function to	*/
/*	define and connect the text value buffer for use by the standard editor	*/
/*	text input mechanism, and also to receive an eventual parameter whcih 	*/
/*	may have been provided via the instance expression.			*/
/*	-----------------------------------------------------------------------	*/
void	laser_text_message( FILE * handle, int x, int y, int w, int h, char * mptr, int colour, int align, char * nptr )
{
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
		fprintf(handle,"<text id=%c%s%u_%s%c x=%c%u%c y=%c%u%c font-size=%c%u%c %s text-anchor=%c%s%c fill=%c%s%c focusable = %c%s%c editable=%c%s%c visibility=%c%s%c>",
			0x0022,_BUFFER_PREFIX,LC.widget->sequence,nptr,0x0022,
			0x0022,x,0x0022,
			0x0022,y+((LC.fontHeight*5)/6),0x0022,
			0x0022,fheight,0x0022,
			dwork,
			0x0022,awork,0x0022,
			0x0022,work,0x0022,
			0x0022,"false",0x0022,
			0x0022,"false",0x0022,
			0x0022,"inherit",0x0022);
		while ( *mptr == ' ' )
			mptr++;
		laser_text_string( handle, mptr );
		fprintf(handle,"</text>\n");
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
		if (!( iptr ))
			return;
		else if ( *iptr == _UNQUOTED_STRING )
		{
			sing_svg_video( handle, x,y,w,h, (iptr+1), option );
		}
		else if (( detect_extension( iptr, ".png"  ) )
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
/*				l a s e r _ c h e c k b o x			*/
/*	-----------------------------------------------------------------------	*/
/*	produces an operational check box widget.				*/
/*	-----------------------------------------------------------------------	*/
void	laser_checkbox( FILE * handle, int x, int y, int w, int h, char * mptr, struct form_item * iptr )
{
	char 	work[1024];

	LC.needBoolean++;

	laser_comment(handle,"table check box frame");
	laser_trigger_group(handle,iptr);

	laser_relief( handle, x,y,LC.fontHeight,LC.fontHeight, _EDIT_FRAME, (char *) 0);
	laser_comment(handle,"table check message");
	laser_text( handle, x+(2*LC.fontHeight),y,w-(2*LC.fontHeight),h, mptr, laser_palette_label, _A_LEFT);

	laser_comment(handle,"table check value");

		sprintf(work,"%s%s",_TRUE_PREFIX,iptr->Contents.name);
		laser_named_filzone(handle,x+3,y+3,LC.fontHeight-6,LC.fontHeight-6,laser_black,work,"hidden");

	laser_groupend(handle);

	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ s w i t c h				*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_switch( FILE * handle, int x, int y, int w, int h, char * mptr, struct form_item * iptr )
{
	int	i;
	char *	vptr;
	int	mlen;
	char 	work[1024];
	int	ty;
	int	fg;
	int	bg;

	LC.needBoolean++;
	bg = (iptr->Contents.colour & 0x00FF);
	fg = ((iptr->Contents.colour >> 8) & 0x00FF);

	laser_comment(handle,"table switch frame");
	laser_trigger_group(handle,iptr);

	laser_relief( handle, x,y,w,h, _INSET_FRAME, (char *) 0);

	ty = (h/2) - (LC.fontHeight/2);

	strcpy(work,mptr);
	mptr = work;
	mlen = strlen(work);
	vptr = mptr;
	for (i=0; i < mlen; i++) {
		if (*(mptr+i) == '|') {
			vptr = (mptr+i);
			*(vptr++) = 0;
			mlen = i;
			break;
			}
		}

	/* false value */
	laser_comment(handle,"table switch false value");
	laser_group(handle);
		laser_filzone(handle,x+2,y+2,w-4,h-4,bg);
		laser_text( handle, x+2,y+ty,w-4,h-4, vptr, fg,_A_CENTER);
	laser_groupend(handle);

	/* true value */
	laser_comment(handle,"table switch true value");
	laser_value_group(handle,iptr);	
		laser_filzone(handle,x+2,y+2,w-4,h-4,fg);
		laser_text( handle, x+2,y+ty,w-4,h-4,mptr, bg,_A_CENTER);
	laser_groupend(handle);

	laser_groupend(handle);

	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ r a d i o b o x			*/
/*	-----------------------------------------------------------------------	*/
/*	draws a radio button / radiobox element.				*/
/*	-----------------------------------------------------------------------	*/
void	laser_radiobox( FILE * handle, int x, int y, int w, int h, char * mptr, struct form_item * iptr )
{
	char 	work[1024];
	laser_comment(handle,"radio frame");
	laser_relief( handle, x,y,LC.fontHeight,LC.fontHeight, _RADIO_FRAME,(char *) 0);
	laser_comment(handle,"radio message");
	laser_text( handle, x+(2*LC.fontHeight),y,w-(2*LC.fontHeight),h, mptr, laser_palette_label, _A_LEFT);
	sprintf(work,"%s%u_%s",_TRUE_PREFIX,iptr->Contents.radio,iptr->Contents.name);
	laser_comment(handle,"radio value");
	laser_named_circle(handle,x+3,y+3,LC.fontHeight-6,LC.fontHeight-6,laser_black,work,
		( iptr->Contents.radio == 1 ? "inherit" : "hidden"));
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ b u t t o n				*/
/*	-----------------------------------------------------------------------	*/
/*	generates a standard pushbutton type widget				*/
/*	-----------------------------------------------------------------------	*/
void	laser_button( FILE * handle, int x, int y, int w, int h, char * message, char * name, int align, int style )
{
	int	ty;
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
			ty = (h / 2 ) - (LC.fontHeight / 2);
			laser_text( handle, x+2,y+ty,w-4,h-4, message,laser_palette_title ,_A_CENTER);
		}
		else
		{
			laser_comment(handle,"text button");
			laser_text( handle, x,y,w,h, message, laser_palette_title,_A_CENTER);
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

void	laser_close_anchor( FILE * h, int isanchor )
{
	switch ( isanchor )
	{
	case	1 :	
		laser_close_tag(h,"a");
		break;
	case	2 :
		laser_close_tag(h,"g");
		break;
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ d r a w b u t t o n			*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	laser_drawbutton( FILE * h, struct form_item * iptr )
{
	char	work[1024];
	laser_button(
		h,
		iptr->Contents.x, iptr->Contents.y, 
		iptr->Contents.w, iptr->Contents.h, 
		abal_payload( iptr ),
		( iptr->Contents.name  ? iptr->Contents.name : (char *) 0),
		iptr->Contents.align, _BUTTON_FRAME
		);
	sprintf(work,"%s%s",_PRESS_PREFIX,iptr->Contents.name);
	laser_hidden_group( h, work );
	laser_relief( h, 
		iptr->Contents.x, iptr->Contents.y, 
		iptr->Contents.w, iptr->Contents.h, 
		_BUTTON_PRESS_FRAME,work);
	laser_groupend(h);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ p u s h b u t t o n			*/
/*	-----------------------------------------------------------------------	*/
/*	this function handles the complete widget push button package with its	*/
/*	behavioural aspects for chaining and the like.				*/
/*	-----------------------------------------------------------------------	*/
void	laser_pushbutton( FILE * h, struct form_item * iptr )
{
	int	started=0;
	int	isanchor=0;
	LC.keepAmpersand=0;

	/* --------------------------------------------- */
	/* if an event is defined then it takes priority */
	/* --------------------------------------------- */
	if (method_is_valid(iptr->Contents.events->on_event) )
	{
		started = laser_method_group( h, iptr, _CLICK_PREFIX );
		laser_drawbutton( h, iptr );
		if ( started )
			laser_groupend( h );
	}
	else
	{
		/* --------------------------------------------- */
		/* otherwise perform the standard defined action */
		/* --------------------------------------------- */
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
			laser_comment(h,"chain, loadgo button link");
			isanchor = laser_anchor(h,iptr->Contents.format, 0 );
			laser_drawbutton( h, iptr );
			laser_close_anchor(h,isanchor);
			break;

		case _WIDGET_TASK    :
		case _WIDGET_SYSTEM  :
		case _WIDGET_LOADGO  :
			laser_comment(h,"chain, loadgo button link");
			isanchor = laser_anchor(h,iptr->Contents.format, 1 );
			laser_drawbutton( h, iptr );
			laser_close_anchor(h,isanchor);
			break;

		default			:
			if (method_is_valid(iptr->Contents.events->on_event) )
				started = laser_method_group( h, iptr, _CLICK_PREFIX );
			laser_drawbutton( h, iptr );
			if ( started )
				laser_groupend( h );
			break;
		}
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
void	laser_use_onclick( FILE * h, int x, int y, char * cname, char * iname,char * tname)
{
	laser_indent(h);
	fprintf(h,"<use onclick=%c%s%c x=%c%u%c y=%c%u%c xlink:href=%c#%s%c id=%c%s%c/>\n",
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
/*		the definition of the unpressed button				*/
/*		the definition of the pressed button				*/
/*		the usage instance of either the pressed or unpressed		*/
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

	laser_defs_header(handle,_LOSE_PREFIX,iptr->Contents.name);
	laser_comment(handle,"tab button release");
	laser_button( handle, 
		iptr->Contents.x+iptr->Contents.adjust,
		iptr->Contents.y,
		iptr->Contents.xlimit,
		(fh + 8 ),
		abal_payload(iptr),
		iptr->Contents.name,
		0,_BUTTON_FRAME);
	laser_defs_footer(handle);

	laser_defs_header(handle,_PRESS_PREFIX,iptr->Contents.name);
	laser_comment(handle,"tab button press");
	laser_button( handle, 
		iptr->Contents.x+iptr->Contents.adjust,
		iptr->Contents.y,
		iptr->Contents.xlimit,
		(fh + 8 ),
		abal_payload(iptr),
		iptr->Contents.name,
		0,_BUTTON_PRESS);
	laser_defs_footer(handle);

	if ( iptr->Contents.page == 1 )
		sprintf(work,"%s%s",_PRESS_PREFIX,iptr->Contents.name);
	else	sprintf(work,"%s%s",_LOSE_PREFIX,iptr->Contents.name);

	sprintf(iwork,"%s%s",_BUTTON_PREFIX,iptr->Contents.name);
	sprintf(twork,"%s%s(%u)",_TRIGGER_PREFIX,fptr->identifier,iptr->Contents.page);
	laser_use_onclick( handle, 0,0, work,iwork,twork);
	laser_groupend(handle);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ o p e n _ s c r i p t			*/
/*	-----------------------------------------------------------------------	*/
/*	starts a script definition block.					*/
/*	-----------------------------------------------------------------------	*/
void	laser_open_script( FILE * handle )
{
	laser_indent(handle);
	fprintf(handle,"<script type=%c%s/%s%c> <![CDATA[\n",0x0022,"application",LC.scriptName,0x0022);
	mpeg_enter();
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ c l o s e _ s c r i p t			*/
/*	-----------------------------------------------------------------------	*/
/*	closes a script definition block.					*/
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
		fprintf(handle,"item.setAttributeNS(%c%s%c,%cxlink:href%c,%c#%s%s%c);\n",
			0x0022,_XLINK_NAMESPACE,0x0022,
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
				fprintf(handle,"item%u.setAttributeNS(%c%s%c,%cxlink:href%c,%c#%s%s%c);\n",
					items,
					0x0022,_XLINK_NAMESPACE,0x0022,
					0x0022,0x0022,
					0x0022,_LOSE_PREFIX,wptr->Contents.name,0x0022);
			}
		}
		laser_indent(handle);
		fprintf(handle,"var fitem = document.getElementById(%c%s%s%c);\n",
			0x0022,_FRAME_PREFIX,fptr->identifier,0x0022);
		laser_indent(handle);
		fprintf(handle,"fitem.setAttributeNS(%c%s%c,%cxlink:href%c,%c#%s%s%c);\n",
			0x0022,_XLINK_NAMESPACE,0x0022,
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
					fprintf(handle,"js%s%s%u.setAttributeNS(%c%s%c,%cxlink:href%c,%c#%s%s%c);\n",
						_BUTTON_PREFIX,fptr->identifier,
						wptr->Contents.page,
						0x0022,_XLINK_NAMESPACE,0x0022,
						0x0022,0x0022,
						0x0022,_PRESS_PREFIX,wptr->Contents.name,0x0022);
					laser_indent(handle);
					fprintf(handle,"js%s%s.setAttributeNS(%c%s%c,%cxlink:href%c,%c#%s%s%c);\n",
						_FRAME_PREFIX,fptr->identifier,
						0x0022,_XLINK_NAMESPACE,0x0022,
						0x0022,0x0022,
						0x0022,_FRAME_PREFIX,wptr->Contents.name,0x0022);
				laser_script_else( handle );
					laser_indent(handle);
					fprintf(handle,"js%s%s%u.setAttributeNS(%c%s%c,%cxlink:href%c,%c#%s%s%c);\n",
						_BUTTON_PREFIX,fptr->identifier,
						wptr->Contents.page,
						0x0022,_XLINK_NAMESPACE,0x0022,
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
/*	This is the optimised version that calculates all page button and frame	*/
/*	variable pointers once and for all allowing their simple use at each	*/
/*	subsequent page change instead of having to scan the list each time.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_radio_script( FILE * handle, struct form_item * iptr )
{
	int	items=0;
	struct	form_item * wptr;
	laser_open_script(handle);

		/* ---------------------------------------------------------------- */
		/* create the value switching function using the prepared variables */
		/* ---------------------------------------------------------------- */
		laser_indent(handle);
		fprintf(handle,"function %s%s(radionumber) {\n",_TRIGGER_PREFIX,iptr->Contents.name);
		mpeg_enter();

			/* ------------------------------------------------ */
			/* collect and reset the current radio button value */
			/* ------------------------------------------------ */
			laser_indent(handle);
			fprintf(handle,"var item = document.getElementById(%c%s%s%c);\n",
				0x0022,_VALUE_PREFIX,iptr->Contents.name,0x0022);

			/* ------------------------------------------------ */
			/* collect and reset the current radio button value */
			/* ------------------------------------------------ */
			laser_indent(handle);
			fprintf(handle,"var previousnumber = item.getAttribute(%cx%c);\n",0x0022,0x0022);

			/* ------------------------------------------------ */
			/* collect and reset the current radio button value */
			/* ------------------------------------------------ */
			laser_indent(handle);
			fprintf(handle,"var js_%s%s = document.getElementById(%c%s%c+previousnumber+%c_%s%c);\n",
				_TRUE_PREFIX,iptr->Contents.name,
				0x0022,_TRUE_PREFIX,0x0022,0x0022,iptr->Contents.name,0x0022);

			laser_indent(handle);
			fprintf(handle,"if ( js_%s%s ) { js_%s%s.setAttribute(%c%s%c,%c%s%c); }\n",
				_TRUE_PREFIX,iptr->Contents.name,
				_TRUE_PREFIX,iptr->Contents.name,
				0x0022,"visibility",0x0022,
				0x0022,"hidden",0x0022);

			/* --------------------------------------------- */
			/* collect and reset the next radio button value */
			/* --------------------------------------------- */
			laser_indent(handle);
			fprintf(handle,"var js_%s%s = document.getElementById(%c%s%c+radionumber+%c_%s%c);\n",
				_TRUE_PREFIX,iptr->Contents.name,
				0x0022,_TRUE_PREFIX,0x0022,0x0022,iptr->Contents.name,0x0022);

			laser_indent(handle);
			fprintf(handle,"if ( js_%s%s ) { js_%s%s.setAttribute(%c%s%c,%c%s%c); }\n",
				_TRUE_PREFIX,iptr->Contents.name,
				_TRUE_PREFIX,iptr->Contents.name,
				0x0022,"visibility",0x0022,
				0x0022,"inherit",0x0022);

			/* ---------------------------------- */
			/* set the current radio button value */
			/* ---------------------------------- */
			laser_indent(handle);
//			fprintf(handle,"item.textContent = radionumber;\n");
			fprintf(handle,"item.setAttribute(%cx%c,radionumber);\n",0x0022,0x0022);

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
		laser_text_message(handle, x+1,y+1,w-2,h-2, "", laser_black, iptr->Contents.align, iptr->Contents.name );
	}
	else
	{
		laser_text_value(handle, x+1,y+1,w-2,h-2, "", laser_black, _A_LEFT, iptr->Contents.name );
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
	laser_filzone( handle, x+2,y+2,w-4,fh, laser_palette_title);
	laser_comment(handle,"window title message");
	laser_text( handle, x+fw,y+2,w-(fw*2),fh, message, laser_palette_text, _A_LEFT);
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
/*		 	  l a s e r _ s e r v e r _ c o m m a n d 		*/
/*	-----------------------------------------------------------------------	*/
/*	generation of the new laser server command element.			*/
/*	-----------------------------------------------------------------------	*/ 
void	laser_server_command( FILE * h, struct form_item * iptr, char * command )
{
	if (LC.useLaser )
	{
		laser_indent(h);
		fprintf(h,"<lsr:serverCommand enable='true' url='%s' command='%s%s'/>\n",
			LC.serverUrl,iptr->Contents.name,command);
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		   l a s e r _ a d _ s e r v e r _ c o m m a n d s		*/
/*	-----------------------------------------------------------------------	*/
/*	handles production of server command instructions for direct access.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_ad_server_commands( FILE * h, struct form_item * iptr )
{
	laser_server_command(h,iptr, _ASSIGN_COMMAND );
	laser_server_command(h,iptr, _OPEN_COMMAND );
	laser_server_command(h,iptr, _CLOSE_COMMAND );
	laser_server_command(h,iptr, _CFILE_COMMAND );
	laser_server_command(h,iptr, _DFILE_COMMAND );
	laser_server_command(h,iptr, _RENAME_COMMAND );
	laser_server_command(h,iptr, _READ_COMMAND );
	laser_server_command(h,iptr, _WRITE_COMMAND );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		   l a s e r _ s q _ s e r v e r _ c o m m a n d s		*/
/*	-----------------------------------------------------------------------	*/
/*	handles production of server command instructions for sequential access	*/
/*	-----------------------------------------------------------------------	*/
void	laser_sq_server_commands( FILE * h, struct form_item * iptr )
{
	laser_server_command(h,iptr, _REWIND_COMMAND );
	laser_server_command(h,iptr, _MODIFY_COMMAND );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		   l a s e r _ sid _ s e r v e r _ c o m m a n d s		*/
/*	-----------------------------------------------------------------------	*/
/*	handles production of server command instructions for sequential index.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_si_server_commands( FILE * h, struct form_item * iptr )
{
	laser_server_command(h,iptr, _SEARCH_COMMAND );
	laser_server_command(h,iptr, _INSERT_COMMAND );
	laser_server_command(h,iptr, _MODIFY_COMMAND );
	laser_server_command(h,iptr, _DELETE_COMMAND );
	laser_server_command(h,iptr, _UPDATE_COMMAND );
	laser_server_command(h,iptr, _FIRST_COMMAND );
	laser_server_command(h,iptr, _DOWN_COMMAND );
	laser_server_command(h,iptr, _UP_COMMAND );
	laser_server_command(h,iptr, _LAST_COMMAND );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		   l a s e r _ m c _ s e r v e r _ c o m m a n d s		*/
/*	-----------------------------------------------------------------------	*/
/*	handles production of server command instructions for multicriteria.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_mc_server_commands( FILE * h, struct form_item * iptr )
{
	laser_server_command(h,iptr, _KEY_COMMAND );
	laser_server_command(h,iptr, _LINK_COMMAND );
	laser_server_command(h,iptr, _CKEY_COMMAND );
	laser_server_command(h,iptr, _CLINK_COMMAND );
	laser_server_command(h,iptr, _POSIT_COMMAND );
	laser_server_command(h,iptr, _COUNT_COMMAND );
	laser_server_command(h,iptr, _COLLECT_COMMAND );
	laser_server_command(h,iptr, _LOCATE_COMMAND );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		   l a s e r _ d b _ s e r v e r _ c o m m a n d s		*/
/*	-----------------------------------------------------------------------	*/
/*	handles production of server command instructions for database files.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_db_server_commands( FILE * h, struct form_item * iptr )
{
	laser_server_command(h,iptr, _JOIN_COMMAND );
	laser_server_command(h,iptr, _CJOIN_COMMAND );
	laser_server_command(h,iptr, _FILE_COMMAND );
	laser_server_command(h,iptr, _RECORD_COMMAND );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ f i l e f r a m e				*/
/*	-----------------------------------------------------------------------	*/
/*	handles production of laser code for file widgets where required.	*/
/*	-----------------------------------------------------------------------	*/
void	laser_fileframe( FILE * h, struct form_item * iptr )
{
	char	work[1024];
	struct	data_control * 	dptr;
	int	nature;

	if (!( LC.serverCommand ))
		return;
	else if (!( nature = is_file_Widget( iptr ) ))
		return;
	else if (!(dptr = iptr->Contents.extra ))
		return;

	switch ( nature )
	{
	case	_SQFILE_FRAME		:
		laser_ad_server_commands(h,iptr);
		laser_sq_server_commands(h,iptr);
		break;

	case	_DBFILE_FRAME		:
		laser_db_server_commands(h,iptr);

	case	_MCFILE_FRAME		:
		laser_mc_server_commands(h,iptr);

	case	_SIFILE_FRAME		:
		laser_si_server_commands(h,iptr);
	case	_VMEMORY_FRAME		:
	case	_ADFILE_FRAME		:
		laser_ad_server_commands(h,iptr);
		break;
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ d a t a f r a m e				*/
/*	-----------------------------------------------------------------------	*/
/*	handles generation for data frame widgets, components and dispatching 	*/
/*	of file production.							*/
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
	{
		if ( is_file_Widget( iptr ) )
			laser_fileframe( h, iptr );
		return;
	}
	else if (!( fnptr = abal_payload(iptr) )) 
		return;
	else if (!(ffptr = locate_form_control( fnptr ) ))
		return;
	else
	{
		laser_widget_group(h, iptr);
		form_Dimensions( &Window, ffptr );
		laser_group(h);
			laser_proto_instance(h,ffptr,
				iptr->Contents.name,
				iptr->Contents.x,iptr->Contents.y,
				( iptr->Contents.events->xo_show & _EVENT_IS_COND ? 0 : 1 ),
				ffptr->identifier
				);
		laser_close_tag(h,"g");
		laser_groupend(h);
		return;
	}
}

/*	-----------------------------------------------------------------------	*/
/*				  l a s e r _ t a b l e  				*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	laser_table( FILE * handle, int x, int y, int w, int h, int f, int fg, int bg,
		char * tptr, int options, char * fptr, char * cellname, int focus )
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
	char	cellprefix[512];
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
		zbg = (options & 2 ? bg : laser_white);
	else	zbg = (options & 1 ? bg : laser_white);

	laser_comment(handle,"table outer frame");
	laser_draw_relief(handle,x,y,w,h,laser_lolight,zbg,laser_hilight,(char *) 0);

	if (!( options & 0x2000 )) {
		x += 1; y+= 1;
		w -= 2; h -= 2;
		}

	/* Generate black inside liner */
	/* --------------------------- */
	laser_comment(handle,"table inner frame");
	laser_draw_relief(handle,x,y,w,h,laser_black,transparent,laser_black,(char *) 0);

	if (!( options & 0x2000 )) {
		x += 1; y+= 1;
		w -= 2; h -= 2;
		}

	/* Establish Titles background fill */
	/* -------------------------------- */
	laser_comment(handle,"table background");
	laser_filzone( handle, x,y,w,fh, laser_palette_title);

	/* check for and perform row-wise zoning */
	/* ------------------------------------- */
	switch ( options & 0x0007 ) {
		case	1 :
		case	3 :
			zbg = (options & 2 ? bg-1 : laser_white-1);
			laser_comment(handle,"table row zoning");
			for ( r=(fh*2); (r+fh) < h; r+= (fh*2) )
				laser_filzone(handle, x,y+r,w,fh,zbg);
			break;
		}

	/* If a title has been provided */
	/* ---------------------------- */
	if ( tptr ) 
	{

		/* Calculate title items */
		/* --------------------- */
		if ( options & _A_SHADOW) 
		{
			txfg = laser_black; txbg = 0;
		}
		else
		{
			txfg = laser_palette_text; txbg = laser_palette_title;
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
			dath = (laser_white | (laser_black << 8));
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
						laser_hilight,laser_backwash,laser_lolight,(char *) 0);
					adjust = fh;
					}					
				memcpy( libelle, tptr, tlen );
				libelle[tlen] = 0;
				laser_text(handle,((lmargin+padd)*fw)+x,y,relw,fh+1,libelle,laser_palette_title,_A_LEFT);

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
		switch ( options & 0x0007 ) 
		{
		case	4 :
		case	5 :
			zbg = (options & 1 ? bg-1 : laser_white-1);
			laser_comment(handle,"table column zoning");
			for (lmargin=0,field=0; field < fields; field++ ) 
			{
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
			zbg = (options & 1 ? bg-1 : laser_white-1);
			laser_comment(handle,"table column zoning");
			for ( nbr=0,r=fh; (r+fh) < h; r+= fh, nbr++ ) 
			{
				for (lmargin=0,field=0; field < fields; field++ ) 
				{
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
		thisrow=1;
		while ( (ty+fh) <= h ) 
		{
			if ( thisrow == focusline ) 	
			{
				rowbg = fg;
				rowfg = bg;
			}
			else	
			{
				rowfg=fg;
				rowbg=0;
			}
			laser_comment(handle,"table data cells");
			for (lmargin=0,field=0; field < fields; field++ ) 
			{
				tw = (fieldwidth[field] * fw);
				sprintf(cellprefix,"r%uc%u",thisrow,field+1);
				sprintf(libelle,"%s_%s",cellprefix,cellname);
				laser_text_cell(handle, 
					(lmargin*fw)+x,y+(thisrow*fh),relw,fh+1,
					(LC.testData ? cellprefix : ""), txfg, _A_LEFT, libelle, focus, thisrow, field+1,cellname );
				lmargin += (fieldwidth[field]-xh);			
			}
			ty += fh;
			thisrow++;
		}
	}
	return(0);		
}

/*	-----------------------------------------------------------------------	*/
/*			 l a s e r _ s e l e c t f r a m e			*/
/*	-----------------------------------------------------------------------	*/
/*	called from widget production for the production of a select widget.	*/
/*	this is a temporary measure version to fill the visual space TODO	*/
/*	-----------------------------------------------------------------------	*/
void	laser_selectframe( FILE * h, struct form_item * iptr )
{
	char	work[2048];
	char *	mptr;
	char *	vptr;
	int	mlen;
	int	i;
	laser_edit( 	
		h,
		iptr->Contents.x, iptr->Contents.y, 
		iptr->Contents.w-LC.fontHeight, LC.fontHeight,
		iptr
		);
	laser_relief(
		h,
		iptr->Contents.x+(iptr->Contents.w-LC.fontHeight), 
		iptr->Contents.y, 
		LC.fontHeight, LC.fontHeight,
		_EDIT_FRAME,(char *) 0
		);
	laser_button( 	
		h,
		iptr->Contents.x+(iptr->Contents.w-LC.fontHeight)+1, 
		iptr->Contents.y+1, 
		LC.fontHeight-2, LC.fontHeight-2,
		"*",(char *) 0,0,_BUTTON_FRAME
		);
	if (!( mptr = abal_payload( iptr )))
		return;
	else
	{
		strcpy(work,mptr);
		mptr = work;
		mlen = strlen(work);
		vptr = mptr;
		for (i=0; i < mlen; i++) {
			if (*(mptr+i) == '|') {
				vptr = (mptr+i);
				*(vptr++) = 0;
				mlen = i;
				break;
				}
			}
	laser_text( 	
		h,
		iptr->Contents.x, iptr->Contents.y, 
		iptr->Contents.w-LC.fontHeight, LC.fontHeight,
		mptr, laser_palette_title, _A_CENTER
		);
		return;
	}
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ f o r m f r a m e			*/
/*	-----------------------------------------------------------------------	*/
/*	called from widget production for the production of a table widget.	*/
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
			iptr->Contents.align,
			iptr->Contents.format,
			iptr->Contents.name,
			(( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ? 1 : 0 )
			 | ( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ? 2 : 0 ))
	
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
	LC.form   = fptr;
	LC.widget = iptr;

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
		laser_radio_group(h, iptr);
		laser_radiobox(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			iptr
			);
		laser_groupend(h);
		if ( iptr->Contents.radio == 1 )
		{
			laser_radio_script( h, iptr );
		}
		break;

	case	_DATA_FRAME	:
		laser_dataframe( h, iptr );
		laser_widget_group(h, iptr);
		laser_groupend(h);
		break;

	case	_FORM_FRAME	:	//	15
		laser_widget_group(h, iptr);
		laser_formframe( h, iptr );
		laser_table_script( h, iptr );
		laser_groupend(h);
		break;

	case	_SELECT_FRAME	:	//	14
		laser_widget_group(h, iptr);
		laser_selectframe( h, iptr );
		laser_groupend(h);
		break;

	case	_LINE_FRAME	:	//	8
	case	_TAB_FRAME	:	//	11
	case	_PROGRESS_FRAME	:	//	17	
	case	_GRAPH_FRAME	:	//	19
		break;

	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ s t a r t _ o d _ u p d a t e		*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	laser_start_od_update( FILE * h )
{
	return(0);
}
/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ c l o s e _ o d _ u p d a t e		*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	laser_close_od_update( FILE * h )
{
	return(0);
}

/*	-------------------------------------------	*/
/*	l a s e r _ o b j e c t _ d e s c r i p t o r 	*/
/*	-------------------------------------------	*/
/*	adds an object descriptor prior to addition	*/
/*	of scene svg to handle images, video		*/
/*	and audio streams as textures in scene.		*/
/*	-------------------------------------------	*/
int	laser_object_descriptor( FILE * h, char * nptr )
{
	return;
}

/*	-------------------------------------------------------------	*/
/*	s t r i n g _ s e n s o r _ o b j e c t _ d e s c r i p t o r 	*/
/*	-------------------------------------------------------------	*/
/*	update of the object descriptor for the string sensor stream	*/
/*	-------------------------------------------------------------	*/
int	laser_string_sensor_object_descriptor( FILE * h )
{
	return;
}

/*	------------------------------------------------------------	*/
/*	   s t r i n g _ s e n s o r _ e s _ d e s c r i p t o r	*/
/*	------------------------------------------------------------	*/
/*	this function is called from the initial object descriptor	*/
/*	production and also from the initial UPDATE OD description.	*/
/*	------------------------------------------------------------	*/
void	laser_string_sensor_es_descriptor( FILE * h )
{
	return;
}

/*	---------------------------------------------------------	*/
/*	 k e y _ s e n s o r _ o b j e c t _ d e s c r i p t o r 	*/
/*	---------------------------------------------------------	*/
/*	update of the object descriptor for the key sensor stream	*/
/*	---------------------------------------------------------	*/
int	laser_key_sensor_object_descriptor( FILE * h )
{
	return( 0 );
}

/*	------------------------------------------------------------	*/
/*		k e y _ s e n s o r _ e s _ d e s c r i p t o r		*/
/*	------------------------------------------------------------	*/
/*	this function is called from the initial object descriptor	*/
/*	productionand also from the initial UPDATE OD description.	*/
/*	------------------------------------------------------------	*/
void	laser_key_sensor_es_descriptor( FILE * h )
{
	return;
}

/*	------------------------------------------------------------	*/
/*			l a s e r _ x m l _ h e a d e r			*/
/*	------------------------------------------------------------	*/
/*	generates an XML file header string.				*/
/*	------------------------------------------------------------	*/
void	laser_xml_header(FILE *h)
{
	fprintf(h,"<?xml version='1.0' encoding='UTF-8'?>\n");
	return;
}

/*	------------------------------------------------------------	*/
/*			l a s e r _ s a f _ h e a d e r			*/
/*	------------------------------------------------------------	*/
/*	generates the SAF Stream Agregation Format header block when	*/
/*	requied for by the production stream type.			*/		
/*	------------------------------------------------------------	*/
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

/*	------------------------------------------------------------	*/
/*			l a s e r _ o p e n _ s v g			*/
/*	------------------------------------------------------------	*/
/*	generates the initial SVG document element.			*/
/*	------------------------------------------------------------	*/
void	laser_open_svg(FILE *h,struct form_control * fptr)
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
		if ( LC.methodText )
		{
			fprintf(h,"\tonload='%s%s()'\n",_CREATE_PREFIX,fptr->identifier);
			fprintf(h,"\tonunload='%s%s()'\n",_REMOVE_PREFIX,fptr->identifier);
		}		
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
		if ( LC.methodText )
		{
			fprintf(h,"\tonload='%s%s()'\n",_CREATE_PREFIX,fptr->identifier);
			fprintf(h,"\tonunload='%s%s()'\n",_REMOVE_PREFIX,fptr->identifier);
		}		
		fprintf(h,"\twidth='%upx' height='%upx' viewBox='0 0 %u %u' version='1.2'>\n",LC.width,LC.height,LC.width,LC.height);
	}	
	return;
}

/*	------------------------------------------------------------	*/
/*			l a s e r _ c l o s e _ s v g			*/
/*	------------------------------------------------------------	*/
/*	close the SVG document element.					*/
/*	------------------------------------------------------------	*/
void	laser_close_svg(FILE *h)
{
	fprintf(h,"</svg>\n");
	return;
}

/*	------------------------------------------------------------	*/
/*		   l a s e r _ s c e n e _ h e a d e r			*/
/*	------------------------------------------------------------	*/
/*	generates a LSeR scene header block.				*/
/*	------------------------------------------------------------	*/
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

/*	------------------------------------------------------------	*/
/*		l a s e r _ m e d i a _ h e a d e r			*/
/*	------------------------------------------------------------	*/
/*	generates a LASeR / SAF media header element.			*/
/*	------------------------------------------------------------	*/
void	laser_media_header(FILE *h)
{
	if ( LC.useSaf > 1 )
	{
		fprintf(h,"<saf:mediaHeader streamID='stream16' streamType='10' objectTypeIndication='0' timeStampResolution='1000'/>\n");
	}
	return;
}

/*	------------------------------------------------------------	*/
/*	l a s e r _ m e d i a _ u n i t
/*	------------------------------------------------------------	*/
/*	generates a LASeR / SAF media unit element.			*/
/*	------------------------------------------------------------	*/
void	laser_media_unit(FILE *h)
{
	if ( LC.useSaf )
	{
		fprintf(h,"<saf:mediaUnit/>\n");
	}
	return;
}

/*	------------------------------------------------------------	*/
/*			l a s e r _ s a f _ f o o t e r			*/
/*	------------------------------------------------------------	*/
/*	closure of the SAF document encapsulation element.			*/
/*	------------------------------------------------------------	*/
void	laser_saf_footer(FILE *h)
{
	if ( LC.useSaf )
	{
		fprintf(h,"<saf:endOfSAFSession/>\n");
		fprintf(h,"</saf:SAFSession>\n");
	}
	return;
}

/*	------------------------------------------------------------	*/
/*			s i n g _ o p e n _ L A S e R  			*/
/*	------------------------------------------------------------	*/
/*	opens a LASeR production stream for the identified form.	*/
/*	------------------------------------------------------------	*/
int	sing_open_LASER( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;

	laser_xml_header(h);
	laser_saf_header(h);
	laser_scene_header(h);
	laser_media_header(h);
	laser_media_unit(h);

	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ s h o w _ i m a g e 3 d			*/
/*	-----------------------------------------------------------------------	*/
/*	called from the 3D production workbench.				*/
/*	-----------------------------------------------------------------------	*/
int	laser_show_image3d( FILE * h, char * nptr, int od, struct coordinate3d * tl, struct coordinate3d * d )
{
	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ s h o w _ m o v i e 3 d			*/
/*	-----------------------------------------------------------------------	*/
/*	called from the 3D production workbench.				*/
/*	-----------------------------------------------------------------------	*/
int	laser_show_movie3d( FILE * h, char * nptr, int od, struct coordinate3d * tl, struct coordinate3d * d )
{
	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ s h o w _ a u d i o 3 d			*/
/*	-----------------------------------------------------------------------	*/
/*	called from the 3D production workbench.				*/
/*	-----------------------------------------------------------------------	*/
int	laser_show_audio3d( FILE * h, char * nptr, int od, struct coordinate3d * tl, struct coordinate3d * d )
{
	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ s h o w _ i m a g e 2 d			*/
/*	-----------------------------------------------------------------------	*/
/*	called from the 3D production workbench.				*/
/*	-----------------------------------------------------------------------	*/
int	laser_show_image2d( FILE * h, char * nptr, int od, int w, int hx )
{
	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ a n c h o r				*/
/*	-----------------------------------------------------------------------	*/
/*	provides for hyperlink type chaining between documents.			*/
/*	-----------------------------------------------------------------------	*/
int	laser_unquoted_anchor( FILE * h, char * nptr, int started )
{
	char	work[1024];
	if (!( nptr )) return(0);
	sprintf(work,"window.location.replace(%s);\n",nptr);
	if (!( started ))
	{
		laser_open_script(h);
	}
	laser_indent(h);
	fprintf(h,"function %s%s() {\n",_ONEVENT_PREFIX,LC.widget->Contents.name);
	laser_method_body(h,LC.widget->Contents.name,work);
	laser_close_brace(h);
	if (!( started ))
	{
		laser_close_script(h);
		laser_method_group(h,LC.widget,_ONEVENT_PREFIX);
	}
	return(2);
}

/*	-----------------------------------------------------------------------	*/
/*				l a s e r _ a n c h o r				*/
/*	-----------------------------------------------------------------------	*/
/*	provides for hyperlink type chaining between documents.			*/
/*	-----------------------------------------------------------------------	*/
int	laser_anchor( FILE * h, char * nptr, int nested )
{
	char	work[1024];
	if (!( nptr ))
		return(0);
	else if ( *nptr == _UNQUOTED_STRING )
		return( laser_unquoted_anchor( h, (nptr+1), 0 ) );
	else if (!( nptr = allocate_string( nptr ) ))
		return(0);
	else if (!( nptr = laser_enforce_extension( nptr ) ))
		return( 0 );
	else	
	{
		laser_indent(h);
		if (!( nested ))
			fprintf(h,"<a xlink:href=%c%s%c>\n",0x0022,nptr,0x0022);
		else
		{
			sprintf(work,"window.open('%s')",nptr);
			fprintf(h,"<a xlink:href=%c%s%c>\n",0x0022,work,0x0022);
		}
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
		fprintf(h,"<g onclick=%c%s%s(1)%c>\n",0x0022,_TOGGLE_PREFIX,iptr->Contents.name,0x0022);
		mpeg_enter();
		laser_drawbutton( h, iptr );
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
/*			l a s e r _ i n l i n e _ f o r m 3 d			*/
/*	-----------------------------------------------------------------------	*/
/*	called from the 3D production workbench.				*/
/*	-----------------------------------------------------------------------	*/
int	laser_inline_form3d( FILE * h, char * nptr,  struct coordinate3d * tl, struct coordinate3d * d )
{
	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ i n l i n e _ f o r m 2 d			*/
/*	-----------------------------------------------------------------------	*/
/*	called from the 3D production workbench.				*/
/*	-----------------------------------------------------------------------	*/
int	laser_inline_form2d( FILE * h, char * nptr, int w, int hx )
{
	return(0);
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
/*	    l a s e r _ s t a r t _ p r o j e c t	*/
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
/*		s i n g _ c l o s e _ L A S e R 	*/
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
/*	    l a s e r _ c l o s e _ p r o j e c t	*
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

/*	-------------------------------------------	*/
/*	  l a s e r _ f i l e _ i n t e r f a c e  	*/
/*	-------------------------------------------	*/
/*	produces the description of a file record	*/
/*	-------------------------------------------	*/
void	laser_file_instance( FILE * h, struct form_item * iptr )
{
	int	f;
	char	work[1024];

	struct	data_control * 	dptr;
	int	nature;
	if (!( nature = is_file_Widget( iptr ) ))
		return;
	else if (!(dptr = iptr->Contents.extra ))
		return;

	sprintf(work,"%s%s",_RECORD_PREFIX,iptr->Contents.name);
	laser_hidden_group(h,work);
	laser_string_variable(h,_FILE_METHOD,abal_payload(iptr),iptr->Contents.name);
	laser_string_variable(h,_FILE_NAME,abal_payload(iptr),iptr->Contents.name);
	laser_integer_variable(h,_FILE_HANDLE,0,iptr->Contents.name);
	laser_integer_variable(h,_FILE_ERROR,0,iptr->Contents.name);
	laser_integer_variable(h,_RECORD_LENGTH,0,iptr->Contents.name);

	switch ( nature )
	{
	case	_ADFILE_FRAME		:	/* 8 adfile		*/
		laser_integer_variable(h,_FILE_SECTOR,0,iptr->Contents.name);
	case	_SQFILE_FRAME		:	/* 6 sqfile		*/
	case	_VMEMORY_FRAME		:
		laser_comment(h,"AD / SQ / VM direct access file");
		for (f=0; f < dptr->datafields; f++ ) {
			if (!( dptr->name[f] ))
				continue;
			else	laser_string_variable(h,dptr->name[f]," ",iptr->Contents.name);
		}
		break;

	case	_DBFILE_FRAME		:	/* 7 dbfile		*/
		laser_comment(h,"database file");
		laser_string_variable(h,_RECORD_QUESTION," ",iptr->Contents.name);
		laser_integer_variable(h,_COLLECT_COUNT,0,iptr->Contents.name);
		laser_integer_variable(h,_COLLECT_ITEM,0,iptr->Contents.name);
		break;

	case	_MCFILE_FRAME		:	/* 4 mcfile		*/
		laser_string_variable(h,_COLLECT_TABLE," ",iptr->Contents.name);
		laser_string_variable(h,_RECORD_QUESTION," ",iptr->Contents.name);
		laser_integer_variable(h,_RECORD_DIRECTION,0,iptr->Contents.name);

	case	_SIFILE_FRAME		:	/* 3 sifile		*/
		laser_comment(h,"SI / MC sequential indexed file");
		laser_integer_variable(h,_COLLECT_COUNT,0,iptr->Contents.name);
		laser_integer_variable(h,_COLLECT_ITEM,0,iptr->Contents.name);
		laser_string_variable(h,_RECORD_INDEX," ",iptr->Contents.name);
		laser_integer_variable(h,_RECORD_MARKER,0,iptr->Contents.name);
		if ( dptr->indexfields ) 
		{
			for (f=0; f < dptr->indexfields; f++ ) 
			{
				if (!( dptr->name[f] ))
					continue;
				else	laser_string_variable(h,dptr->name[f]," ",iptr->Contents.name);
			}
		}
		if ( dptr->datafields ) 
		{
			for (f=0; f < dptr->datafields; f++ ) 
			{
				if (!( dptr->name[f+dptr->indexfields] ))
					continue;
				else	laser_string_variable(h,dptr->name[f+dptr->indexfields]," ",iptr->Contents.name);
			}
		}
		break;
	}
	laser_groupend(h);
	return;
}

/*	-------------------------------------------	*/
/*	 l a s e r _ p r o t o _ i n t e r f a c e  	*/
/*	-------------------------------------------	*/
void	laser_proto_interface( FILE * h, struct form_control * fptr )
{
	char	work[1024];
	struct	form_item * iptr;
	struct	forms_data_member * mptr;
	/* --------------------------- */
	/* prototype widget data items */
	/* --------------------------- */
	laser_comment(h,"forms members and widget value fields");
	sprintf(work,"%s%s",_GLOBAL_PREFIX,fptr->identifier);
	laser_hidden_group(h,work);
	if ( fptr->pages )
	{
		laser_integer_variable(h,"pageNumber",0,fptr->identifier);
		laser_integer_variable(h,"pageCount",fptr->pages,fptr->identifier);
	}
	laser_integer_variable(h,"focusItem",0,fptr->identifier);
	laser_integer_variable(h,"focusItems",fptr->items,fptr->identifier);
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch (iptr->Contents.style)
		{
		case	_BUTTON_FRAME	:
			switch ( iptr->Contents.datatype )
			{
			case _WIDGET_OVERLAY :
			case _WIDGET_MODULE  :
			case _WIDGET_CHAIN   :
			case _WIDGET_TASK    :
			case _WIDGET_SYSTEM  :
			case _WIDGET_LOADGO  :
				sprintf(work,"%s%u_",_BUFFER_PREFIX,iptr->sequence);
				laser_string_variable(	h, iptr->Contents.name, "", work );
				break;
			}
			break;

		case	_EDIT_FRAME	:
			laser_string_variable(	h, iptr->Contents.name, "", _VALUE_PREFIX );
			break;

		case	_RADIO_FRAME	:
			if ( iptr->Contents.radio == 1 )
				laser_integer_variable(	h, iptr->Contents.name, 1, _VALUE_PREFIX );
			break;

		case	_CHECK_FRAME	:
			laser_integer_variable(	h, iptr->Contents.name, 0, _VALUE_PREFIX );
			break;

		case	_SWITCH_FRAME	:
			laser_integer_variable(	h, iptr->Contents.name, 0, _VALUE_PREFIX );
			break;

		case	_SCROLL_FRAME	:
			laser_integer_variable(	h, iptr->Contents.name, 0, _VALUE_PREFIX );
			laser_integer_variable(	h, iptr->Contents.name, 0, _MAX_PREFIX );
			laser_integer_variable(	h, iptr->Contents.name, 0, _LIMIT_PREFIX );
			break;

		case	_FORM_FRAME	:
			laser_stringseq_variable(	h, iptr->Contents.name, "", _BUFFER_PREFIX, iptr->sequence );
			laser_integer_variable(	h, iptr->Contents.name, 1, _COLUMN_PREFIX );
			laser_integer_variable(	h, iptr->Contents.name, 1, _LINE_PREFIX );
			break;

		case	_PROGRESS_FRAME	:
			laser_integer_variable(	h, iptr->Contents.name, 0, _VALUE_PREFIX );
			laser_integer_variable(	h, iptr->Contents.name, 0, _LIMIT_PREFIX );
			break;

		case	_DATA_FRAME	:
			laser_file_instance(h, iptr );
			break;
		}
	}
	laser_groupend(h);
	if ( fptr->rootmember )
	{
		laser_comment(h,"forms member value fields");
		laser_group(h);
		for (	mptr=fptr->rootmember;
			mptr != (struct forms_data_member *) 0;
			mptr = mptr->next ) 
		{
			switch ( mptr->type ) 
			{
			case	_ABAL_BYTE 	:
			case	_ABAL_WORD 	:
			case	_ABAL_LONG 	:
			case	_ABAL_BCD  	:
				laser_integer_variable(	h, mptr->name, 0, _VALUE_PREFIX );
				break;
			case	_ABAL_STRING 	:
				laser_string_variable(	h, mptr->name, " ", _VALUE_PREFIX );
				break;
			}
		}
		laser_groupend(h);
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

/*	----------------------------------------------------------	*/
/*		l a s e r _ i n t e g e r _ v a r i a b l e		*/
/*	----------------------------------------------------------	*/
int	laser_integer_variable( FILE * h, char * name , int value, char * prefix )
{
	laser_indent(h);
	fprintf(h,"<text id=%c%s%s%c x=%c%u%c y=%c0%c font-size=%c0%c visibility='hidden'>%u</text>\n",
		0x0022,prefix,name,0x0022,
		0x0022,value,0x0022,
		0x0022,0x0022,
		0x0022,0x0022,
		value);
	return;
}

/*	----------------------------------------------------------	*/
/*		l a s e r _ s t r i n g _ v a r i a b l e		*/
/*	----------------------------------------------------------	*/
int	laser_stringseq_variable( FILE * h, char * name, char * value, char * prefix, int seq )
{
	laser_indent(h);
	while ( *value == ' ')
		value++;
	fprintf(h,"<text id=%c%s%u_%s%c x=%c0%c y=%c0%c font-size=%c0%c visibility='hidden'>%s</text>\n",
		0x0022,prefix,seq,name,0x0022,
		0x0022,0x0022,
		0x0022,0x0022,
		0x0022,0x0022,
		value);
	return;
}
/*	----------------------------------------------------------	*/
/*		l a s e r _ s t r i n g _ v a r i a b l e		*/
/*	----------------------------------------------------------	*/
int	laser_string_variable( FILE * h, char * name, char * value, char * prefix )
{
	laser_indent(h);
	while ( *value == ' ')
		value++;
	fprintf(h,"<text id=%c%s%s%c x=%c0%c y=%c0%c font-size=%c0%c visibility='hidden'>%s</text>\n",
		0x0022,prefix,name,0x0022,
		0x0022,0x0022,
		0x0022,0x0022,
		0x0022,0x0022,
		value);
	return;
}

/*	-------------------------------------------	*/
/*	   l a s e r _ m e t h o d _ b o d y		*/
/*	-------------------------------------------	*/
/*	generates a javascript function body for	*/
/*	forms and widget methods.			*/
/*	-------------------------------------------	*/

#include "singjs.c" 	
#include "singxsd.c" 	
#include "singwgt.c" 	

void	laser_method_body( FILE * h, char * hostname, char * body )
{
	if ( body )
	{
		_JS_method_body( h, body, strlen( body ), hostname, 2 );
	}
	return;
}

/*	-------------------------------------------	*/
/*	   l a s e r _ w i d g e t _ m e t h o d 	*/
/*	-------------------------------------------	*/
/*	generates a javascript function for widget	*/
/*	methods create,show,event,hide and remove.	*/
/*	-------------------------------------------	*/
int	laser_widget_method( FILE * h, struct form_item * iptr, char * prefix, char * body, int started )
{
	if (!( started++ ))
		laser_open_script(h);
	laser_indent(h);
	fprintf(h,"function %s%s() {\n",prefix,iptr->Contents.name);
	mpeg_enter();
	if ( LC.methodText )
	{
		laser_method_body(h,iptr->Contents.name,body);
	}
	laser_close_brace(h);
	return( started );
}

/*	----------------------------------------------------	*/
/*		l a s e r _ b u t t o n _  p r e s s 		*/
/*	----------------------------------------------------	*/
void	laser_button_press(FILE* h, struct form_item * iptr )
{
	struct	form_control * fptr;
	if (!( fptr = iptr->parent ))
		return;
	else
	{
		LC.buttonPress=1;
		laser_indent(h);
		fprintf(h,"%s('%s%s');\n",_PRESS_MANAGER,_PRESS_PREFIX,iptr->Contents.name );
		return;
	}
}

/*	----------------------------------------------------	*/
/*		l a s e r _ b u t t o n _  p r e s s 		*/
/*	----------------------------------------------------	*/
void	laser_button_release(FILE* h, struct form_item * iptr )
{
	struct	form_control * fptr;
	if (!( fptr = iptr->parent ))
		return;
	else
	{
		LC.buttonPress=1;
		laser_indent(h);
		fprintf(h,"%s();\n",_TIMER_MANAGER );
		return;
	}
}

/*	----------------------------------------------------	*/
/*	   l a s e r _ w i d g e t _ e v e n t _ m e t h o d 	*/
/*	----------------------------------------------------	*/
/*	will generate a widget event method but may need to	*/
/*	add extra behaviour for different button types.		*/
/*	----------------------------------------------------	*/
int	laser_widget_event_method( FILE * h, struct form_item * iptr, char * prefix, char * body, int started )
{
	char *	nptr;
	char	work[2048];
	if ( iptr->Contents.style != _BUTTON_FRAME )
		return( laser_widget_method( h, iptr, prefix, body, started ) );
	else
	{
		if (!( started++ ))
			laser_open_script(h);
		
		laser_indent(h);
		fprintf(h,"function %s%s() {\n",_CLICK_PREFIX,iptr->Contents.name);
		mpeg_enter();
			laser_button_press(h,iptr);
			laser_indent(h);
			fprintf(h,"%s%s();\n",prefix,iptr->Contents.name);
			laser_button_release(h,iptr);
		laser_close_brace(h);

		laser_indent(h);
		fprintf(h,"function %s%s() {\n",prefix,iptr->Contents.name);
		mpeg_enter();

			if ( LC.methodText )
			{
				laser_method_body(h,iptr->Contents.name,body);
			}

			switch ( iptr->Contents.datatype )
			{
			case _WIDGET_OVERLAY :
			case _WIDGET_MODULE  :
				laser_indent(h);
				fprintf(h,"%s%s(v);\n",_TOGGLE_PREFIX,iptr->Contents.name);
				break;
			case _WIDGET_CHAIN   :
			case _WIDGET_TASK    :
			case _WIDGET_SYSTEM  :
			case _WIDGET_LOADGO  :
				/* launch the ON EVENT for this widget */
				/* ----------------------------------- */
				laser_indent(h);
				fprintf(h,"%s%s();\n",_ONEVENT_PREFIX,iptr->Contents.name);
			default		:
				laser_close_brace(h);
			}


		switch ( iptr->Contents.datatype )
		{
		case _WIDGET_CHAIN   :
		case _WIDGET_TASK    :
		case _WIDGET_SYSTEM  :
		case _WIDGET_LOADGO  :
			if ( *iptr->Contents.format == _UNQUOTED_STRING )
				laser_unquoted_anchor(h, (iptr->Contents.format+1),started );
			else
			{
				if (!( nptr = allocate_string( iptr->Contents.format ) ))
					break;
				else if (!( nptr = laser_enforce_extension( nptr ) ))
					break;
				else
				{
					sprintf(work,"%c%s%c",0x0022,nptr,0x0022);
					laser_unquoted_anchor(h, work, started );
					liberate( nptr );
					break;
				}
			}
		}
		return( started );
	}
}

/*	-------------------------------------------	*/
/*	  l a s e r _ r e q u e s t _ m e t h o d 	*/
/*	-------------------------------------------	*/
/*	generates a javascript function for widget	*/
/*	file requests depending on configuration.	*/
/*	-------------------------------------------	*/
int	laser_request_method( FILE * h, struct form_item * iptr, char * prefix, int started )
{
	char *	classname;
	if (!( classname = resolve_widget_file_class( iptr ) ))
		return(started);
	else if (!( started++ ))
		laser_open_script(h);

	laser_indent(h);
	fprintf(h,"function %s%s(req) {\n",prefix,iptr->Contents.name);
	mpeg_enter();
	if ( LC.methodText )
	{
		laser_indent(h);
		_JS_file_member(h,iptr,-1, _FILE_METHOD );
		fprintf(h," = req;\n");
		if ( LC.serverCommand )
		{
			laser_indent(h);
			fprintf(h,"%s( '%s%s','%s','%s' );\n",_SERVER_COMMAND,
				_RECORD_PREFIX,iptr->Contents.name,
				iptr->Contents.name,classname);
		}
		else if ( LC.soapInterface )
		{
			laser_indent(h);
			fprintf(h,"%s( '%s%s', '%s', '%s' );\n",_SOAP_REQUEST,
				_RECORD_PREFIX,iptr->Contents.name,
				iptr->Contents.name,classname);
		}
	}
	laser_close_brace(h);
	return( started );
}

/*	-------------------------------------------	*/
/*	    l a s e r _ f o r m s _ m e t h o d 	*/
/*	-------------------------------------------	*/
/*	generates a javascript function for forms	*/
/*	methods.					*/
/*	-------------------------------------------	*/
int	laser_forms_method( FILE * h, struct form_control * fptr, struct forms_method * mptr, int started )
{
	if (!( started++ ))
		laser_open_script(h);
	laser_indent(h);
	fprintf(h,"function %s%s(%s) {\n",fptr->identifier,mptr->name,( mptr->signature ? mptr->signature : "\0" ));
	mpeg_enter();
	if ( LC.methodText )
	{
		laser_method_body(h,fptr->identifier,mptr->text);
	}
	laser_close_brace(h);
	return( started );
}

/*	-------------------------------------------	*/
/*	    l a s e r _ f o r m s _ m e t h o d s 	*/
/*	-------------------------------------------	*/
/*	generates forms methods as javascript		*/
/*	-------------------------------------------	*/
int	laser_forms_methods( FILE * h, struct form_control * fptr, int started )
{
	struct	forms_method 	* mptr;

	if (!( fptr ))	
		return(started);
	else if (!( fptr->rootmethod ))
		return(started);
	else
	{
		for (	mptr=fptr->rootmethod;
			mptr != (struct forms_method *) 0;
			mptr = mptr->next ) 
		{
			if ( mptr->type & _METHOD_EXTERN )
				continue;
			else if (!( mptr->name ))
				continue;
			started = laser_forms_method(h,fptr,mptr,started);
		}
		return(started);
	}
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ c r e a t e _ m e t h o d			*/
/*	-----------------------------------------------------------------------	*/
/*	generation of the standard forms interface method CREATE.		*/
/*	-----------------------------------------------------------------------	*/
int	laser_create_method( FILE * h, struct form_control * fptr, int started )
{
	char *	fnptr;
	struct form_control * ffptr;
	struct	form_item * iptr;
	if (!( started++ ))
		laser_open_script(h);

	laser_indent(h);
	fprintf(h,"function %s%s() {\n",_CREATE_PREFIX,fptr->identifier);
	mpeg_enter();

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if (( iptr->Contents.style == _DATA_FRAME )
		&&  (( iptr->Contents.align & 0x00FF) == _VISUAL_FRAME)
		&&  (( fnptr = abal_payload(iptr)) != (char *) 0) 
		&&  ((ffptr = locate_form_control( fnptr )) != (struct form_control *) 0))
		{
			laser_indent(h);
			fprintf(h,"%s%s();\n",_CREATE_PREFIX,ffptr->identifier);
		}
		if ( method_is_valid( iptr->Contents.events->on_create) )
		{
			laser_indent(h);
			fprintf(h,"%s%s();\n",_CREATE_PREFIX,iptr->Contents.name);
		}
	}
	laser_indent(h);
	fprintf(h,"%s%s();\n",_SHOW_PREFIX,fptr->identifier);
	laser_close_brace(h);

	return( started );
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ s h o w _ m e t h o d			*/
/*	-----------------------------------------------------------------------	*/
/*	generation of the standard forms interface method SHOW			*/
/*	-----------------------------------------------------------------------	*/
int	laser_show_method( FILE * h, struct form_control * fptr, int started )
{
	struct	form_item * iptr;
	if (!( started++ ))
		laser_open_script(h);

	laser_indent(h);
	fprintf(h,"function %s%s() {\n",_SHOW_PREFIX,fptr->identifier);
	mpeg_enter();

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( method_is_valid( iptr->Contents.events->on_show) )
		{
			laser_indent(h);
			fprintf(h,"%s%s();\n",_SHOW_PREFIX,iptr->Contents.name);
		}
	}
	laser_close_brace(h);
	return( started );
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ r e m o v e _ m e t h o d			*/
/*	-----------------------------------------------------------------------	*/
/*	generation of the standard forms interface method REMOVE.		*/
/*	-----------------------------------------------------------------------	*/
int	laser_remove_method( FILE * h, struct form_control * fptr, int started )
{
	char *	fnptr;
	struct form_control * ffptr;
	struct	form_item * iptr;
	if (!( started++ ))
		laser_open_script(h);

	laser_indent(h);
	fprintf(h,"function %s%s() {\n",_REMOVE_PREFIX,fptr->identifier);
	mpeg_enter();

	laser_indent(h);
	fprintf(h,"%s%s();\n",_HIDE_PREFIX,fptr->identifier);

	for (	iptr=fptr->last;
		iptr != (struct form_item *) 0;
		iptr = iptr->previous )
	{
		if ( method_is_valid( iptr->Contents.events->on_remove) )
		{
			laser_indent(h);
			fprintf(h,"%s%s();\n",_REMOVE_PREFIX,iptr->Contents.name);
		}
		if (( iptr->Contents.style == _DATA_FRAME )
		&&  (( iptr->Contents.align & 0x00FF) == _VISUAL_FRAME)
		&&  (( fnptr = abal_payload(iptr)) != (char *) 0) 
		&&  ((ffptr = locate_form_control( fnptr )) != (struct form_control *) 0))
		{
			laser_indent(h);
			fprintf(h,"%s%s();\n",_REMOVE_PREFIX,ffptr->identifier);
		}
	}
	laser_close_brace(h);
	return( started );
}

/*	-----------------------------------------------------------------------	*/
/*			l a s e r _ h i d e _ m e t h o d 			*/
/*	-----------------------------------------------------------------------	*/
/*	generation of the standard forms interface method HIDE.			*/
/*	-----------------------------------------------------------------------	*/
int	laser_hide_method( FILE * h, struct form_control * fptr, int started )
{
	struct	form_item * iptr;
	if (!( started++ ))
		laser_open_script(h);

	laser_indent(h);
	fprintf(h,"function %s%s() {\n",_HIDE_PREFIX,fptr->identifier);
	mpeg_enter();

	for (	iptr=fptr->last;
		iptr != (struct form_item *) 0;
		iptr = iptr->previous )
	{
		if ( method_is_valid( iptr->Contents.events->on_hide) )
		{
			laser_indent(h);
			fprintf(h,"%s%s();\n",_HIDE_PREFIX,iptr->Contents.name);
		}
	}
	laser_close_brace(h);
	return( started );
}

/*	-------------------------------------------	*/
/*		l a s e r _ p r o t o _ b o d y 	*/
/*	-------------------------------------------	*/
int	laser_proto_body( FILE * h, struct form_control * fptr, char * nptr )
{
	char	*	sptr;
	int	i;
	int	started=0;
	struct	form_item * iptr;
	struct	form_item * iiptr;
	char	work[1024];
	char	iwork[1024];
	struct	form_control * xfptr;
	xfptr = LC.form;
	LC.form = fptr;
	if (!( nptr ))
		nptr = fptr->identifier;

	/* ----------------- */
	/* prototype widgets */
	/* ----------------- */
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
					laser_frame_script( h, fptr );
				}
				started=0;
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

		/* Generate Widget Methods */
		/* ----------------------- */		
		for (	started=0,iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
			if (method_is_valid((sptr = iptr->Contents.events->on_create)))
				started = laser_widget_method( h, iptr, _CREATE_PREFIX,sptr,started ); 
			if (method_is_valid((sptr = iptr->Contents.events->on_remove)))
				started = laser_widget_method( h, iptr, _REMOVE_PREFIX,sptr,started ); 
			if (method_is_valid((sptr = iptr->Contents.events->on_event)))
				started = laser_widget_event_method( h, iptr, _EVENT_PREFIX,sptr,started ); 

			if ( is_file_Widget( iptr ) )
			{
				started = laser_request_method( h, iptr, _REQUEST_PREFIX,started ); 
			}
			else
			{
				if (method_is_valid((sptr = iptr->Contents.events->on_show)))
					started = laser_widget_method( h, iptr, _SHOW_PREFIX,sptr,started ); 
				if (method_is_valid((sptr = iptr->Contents.events->on_hide)))
					started = laser_widget_method( h, iptr, _HIDE_PREFIX,sptr,started ); 
			}
		}
		if ( LC.methodText )
		{
			started = laser_create_method( h, fptr, started );
			started = laser_show_method( h, fptr, started );
			started = laser_hide_method( h, fptr, started );
			started = laser_remove_method( h, fptr, started );
			started = laser_forms_methods( h, fptr, started );
		}
		if ( started )
			laser_close_script(h);
	}
	LC.form = xfptr;
	return(0);
}

/*	--------------------------------------------	*/
/*	 l a s e r _ p r o t o _ d e p e n d a n c e	*/
/*	--------------------------------------------	*/
/* 	this function generates the prototype file	*/
/*	that will be referenced by the externproto	*/
/*	instructions for the description of the obj	*/
/*	--------------------------------------------	*/
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
	laser_proto_interface(h, fptr );
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
/*	   l a s e r _ j s _ g e t _ c o o k i e	*/
/*	-------------------------------------------	*/
/*	collects a cookie sent by the server from 	*/
/*	the Ajax Response Header and stores it int	*/
/*	the local DOM tree soapCookie element 		*/
/*	-------------------------------------------	*/
void	laser_js_get_cookie( FILE * h)
{
	if ( LC.soapCookies & 2 )
	{
		laser_indent(h);
		fprintf(h,"try { var serverCookie=server.getResponseHeader('Set-Cookie');\n");
		laser_indent(h);
		fprintf(h,"if ( serverCookie.length ) { document.getElementById('soapCookie').textContent = serverCookie; }\n");
		laser_indent(h);
		fprintf(h,"} catch (kerr) {}\n");
	}
	return;
}

/*	-------------------------------------------	*/
/*	   l a s e r _ j s _ s e t _ c o o k i e	*/
/*	-------------------------------------------	*/
/*	outputs the cookie sent by the server into 	*/
/*	the Ajax Request Header using the current	*/
/*	value of the local DOM soapCookie element 	*/
/*	-------------------------------------------	*/
void	laser_js_set_cookie( FILE * h)
{
	if ( LC.soapCookies & 1 )
	{
		laser_indent(h);
		fprintf(h,"var clientCookie = document.getElementById('soapCookie').textContent;\n");
		laser_indent(h);
		fprintf(h,"if ( clientCookie.length ) { server.setRequestHeader('Cookie',clientCookie); }\n");
	}
	return;
}

/*	-------------------------------------------	*/
/*	  l a s e r _ s t a n d a r d _ s c r i p t	*/
/*	-------------------------------------------	*/
void	laser_standard_script( FILE * h,struct form_control * fptr)
{
	char *	pagename=(char *) 0;
	char *	databasename;
	if (!( databasename = application_databasename() ))
		databasename = "mydatabase";
	if (!( LC.needBoolean ))
		if (!( LC.soapInterface ))
			if (!( LC.serverCommand ))
				if (!( LC.buttonPress ))
					return;

	if (!( pagename = allocate_string( fptr->prodname )))
		return;

	if ( LC.serverPhp )	
		if (!( pagename = enforce_extension( pagename, PHP_EXTENSION ) ))
			return;

	laser_open_script( h );

	if ( LC.needBoolean )
	{
		laser_indent(h);
		fprintf(h,"function %s(tgt) {\n",_BOOLEAN_TOGGLE);
		mpeg_enter();
			laser_indent(h);
			fprintf(h,"var item = document.getElementById(tgt);\n");
			laser_indent(h);
			fprintf(h,"var state = item.getAttribute(%cvisibility%c);\n",0x0022,0x0022);
			laser_indent(h);
			fprintf(h,"if ( state == %chidden%c ) {\n",0x0022,0x0022);
			mpeg_enter();
			laser_indent(h);
			fprintf(h,"item.setAttribute(%cvisibility%c,%cinherit%c);\n",
				0x0022,0x0022,
				0x0022,0x0022);
			laser_script_else(h);
			laser_indent(h);
			fprintf(h,"item.setAttribute(%cvisibility%c,%chidden%c);\n",
				0x0022,0x0022,
				0x0022,0x0022);
			laser_close_brace(h);
		laser_close_brace(h);
	}

	if ( LC.buttonPress )
	{
		laser_indent(h);
		fprintf(h,"var lastPressed=0;\n");
		laser_indent(h);
		fprintf(h,"var releaseTimer=0;\n");

		laser_indent(h);
		fprintf(h,"function %s(tgt) {\n",_RELEASE_MANAGER);
		mpeg_enter();
			laser_indent(h);
			fprintf(h,"if ( lastPressed ) { lastPressed.setAttribute('visibility','hidden'); }\n");
			laser_indent(h);
			fprintf(h,"lastPressed=0;\n");
		laser_close_brace(h);

		laser_indent(h);
		fprintf(h,"function %s(tgt) {\n",_TIMER_MANAGER);
		mpeg_enter();
			laser_indent(h);
			fprintf(h,"try { if ( lastPressed ) { releaseTimer = setTimeout('%s()',500); }} catch (oops) {};\n",_RELEASE_MANAGER);
		laser_close_brace(h);

		laser_indent(h);
		fprintf(h,"function %s(tgt) {\n",_PRESS_MANAGER);
		mpeg_enter();
			laser_indent(h);
			fprintf(h,"%s();\n",_RELEASE_MANAGER);
			laser_indent(h);
			fprintf(h,"lastPressed = document.getElementById(tgt);\n");
			laser_indent(h);
			fprintf(h,"if ( lastPressed ) { lastPressed.setAttribute('visibility','inherit'); }\n");
		laser_close_brace(h);
	}

	if ( LC.serverCommand )
	{
		laser_indent(h);
		fprintf(h,"function %s(tgt,wdg,kptr) {\n",_SERVER_COMMAND);
		mpeg_enter();
			laser_indent(h);
			fprintf(h,"var rptr = document.getElementById(tgt);\n");
			laser_indent(h);
			fprintf(h,"alert('Server Command: '+tgt);\n");
		laser_close_brace(h);
	}

	if ( LC.soapInterface )
	{
		laser_indent(h);
		fprintf(h,"var workname = 0;\n");
		laser_indent(h);
		fprintf(h,"var workfile = 0;\n");
		laser_indent(h);
		fprintf(h,"var workroot = 0;\n");
		laser_indent(h);
		fprintf(h,"var workclass = 0;\n");
		laser_indent(h);
		fprintf(h,"function %s(eval) {\n",_JS_FILE_ERROR);
		mpeg_enter();
			laser_indent(h);
			fprintf(h,"document.getElementById(workfile+'%s').textContent=eval;\n",_FILE_ERROR);
		laser_close_brace(h);

		laser_indent(h);
		fprintf(h,"function %s(src,tag) {\n",_JS_XML_VALUE);
		mpeg_enter();
			laser_indent(h);
			fprintf(h,"var v = src.indexOf(tag);\n");
			laser_indent(h);
			fprintf(h,"if ( v != -1 ) {\n");
			mpeg_enter();
				laser_indent(h);
				fprintf(h,"var srca = src.substring(v+tag.length);\n");
				laser_indent(h);
				fprintf(h,"v = srca.indexOf('>');\n");
				laser_indent(h);
				fprintf(h,"if ( v != -1 ) {\n");
				mpeg_enter();
					laser_indent(h);
					fprintf(h,"var srcb = srca.substring(v+1);\n");
					laser_indent(h);
					fprintf(h,"v = srcb.indexOf('<');\n");
					laser_indent(h);
					fprintf(h,"if ( v > 0 ) {\n");
					mpeg_enter();
						laser_indent(h);
						fprintf(h,"var srcc = srcb.substring(0,v);\n");
						laser_indent(h);
						fprintf(h,"return( srcc );\n");
					laser_close_brace(h);
				laser_close_brace(h);
			laser_close_brace(h);
			laser_indent(h);
			fprintf(h,"return('');\n");
		laser_close_brace(h);

		/* --------------------------------- */			
		/* Soap Request / Response Interface */
		/* --------------------------------- */			
		laser_indent(h);
		fprintf(h,"function %s(tgt,wdgt,kptr) {\n",_SOAP_REQUEST);
		mpeg_enter();
			laser_indent(h);
			fprintf(h,"workname = tgt;\n");
			laser_indent(h);
			fprintf(h,"workfile = wdgt;\n");
			laser_indent(h);
			fprintf(h,"workclass = kptr;\n");
			/* ------------------------------- */	
			/* Soap Message Header Preparation */
			/* ------------------------------- */			
			laser_indent(h);
			fprintf(h,"var message=%c<?xml version='1.0' encoding='ISO-8859-1'?>\\n%c;\n",0x0022,0x0022);
			laser_indent(h);
			fprintf(h,"message +=  %c<SOAP-ENV:Envelope xmlns:SOAP-ENV='http://schemas.xmlsoap.org/soap/envelope/' SOAP-ENV:encodingStyle='http://schemas.xmlsoap.org/soap/encoding/'>\\n%c;\n",0x0022,0x0022);
			laser_indent(h);
			fprintf(h,"message +=  %c<SOAP-ENV:Body>\\n%c;\n",0x0022,0x0022);
			/* --------------------------------- */	
			/* Soap Message Contents Preparation */
			/* --------------------------------- */			
			laser_indent(h);
			fprintf(h,"message += %c<tns:%c+workclass+%c xmlns:tns='%c+%c%s/%c+workclass+%c.xsd'>\\n%c;\n",
				0x0022,0x0022,
				0x0022,0x0022,
				0x0022,LC.serverUrl,0x0022,
				0x0022,0x0022);
			laser_indent(h);
			fprintf(h,"workroot = document.getElementById(workname);\n");
			laser_indent(h);
			fprintf(h,"var thisitem=workroot.firstChild;\n");
			laser_indent(h);
			fprintf(h,"var thistag=0;\n");
			laser_indent(h);
			fprintf(h,"while ( thisitem ) {\n");
				mpeg_enter();
				laser_indent(h);
				fprintf(h,"if ( thisitem.id ) { thistag = thisitem.id.substring(workfile.length); message+='<tns:'+thistag+'>'+thisitem.textContent+'</tns:'+thistag+'>\\n'; }\n");
				laser_indent(h);
				fprintf(h,"thisitem=thisitem.nextSibling;\n");
			laser_close_brace(h);
			laser_indent(h);
			/* ------------------------------- */	
			/* Soap Message Footer Preparation */
			/* ------------------------------- */			
			fprintf(h,"message += %c</tns:%c+workclass+%c>\\n%c;\n",0x0022,0x0022,0x0022,0x0022);
			laser_indent(h);
			fprintf(h,"message +=  %c</SOAP-ENV:Body>%c;\n",0x0022,0x0022);
			laser_indent(h);
			fprintf(h,"message +=  %c</SOAP-ENV:Envelope>\\n%c;\n",0x0022,0x0022);
			if ( LC.withDebug )
			{
				laser_indent(h);
				fprintf(h,"alert('Synchronous Soap Request:\\n'+workname+': '+message);\n");
			}
			/* ------------------------------- */	
			/* Ajax Server Request Preparation */
			/* ------------------------------- */			
			laser_indent(h);
			fprintf(h,"try { server = new XMLHttpRequest(); }\n");
			laser_indent(h);
			fprintf(h,"catch(e) { if (window.XMLHttpRequest) { server=new XMLHttpRequest(); }\n");
			laser_indent(h);
			fprintf(h,"else { server=new ActiveXObject('Microsoft.XMLHTTP'); } }\n");

			/* --------------------- */
			/* Ajax Request Handling */
			/* --------------------- */
			laser_indent(h);
			if ( LC.serverPhp )
				fprintf(h,"var surl = '%s'+'/%s';\n",LC.serverUrl,pagename);
			else	fprintf(h,"var surl = '%s'+'/'+workname;\n",LC.serverUrl);
			laser_indent(h);
			fprintf(h,"try { server.open('POST',surl,false);\n");
			laser_indent(h);
			fprintf(h,"server.setRequestHeader('Content-Type','application/soap+xml; charset=utf-8');\n");
			laser_js_set_cookie(h);
			laser_indent(h);
			fprintf(h,"server.send(message);\n");
			laser_indent(h);
			fprintf(h,"if ( server.status == 200 ) {\n");
			mpeg_enter();
				/* --------------------------------- */
				/* Integration of SOAP Response Data */
				/* --------------------------------- */
				laser_indent(h);
				fprintf(h,"var xmldoc = server.responseXML;\n");
				if ( LC.withDebug )
				{
					laser_indent(h);
					fprintf(h,"alert( 'Synchronous Soap Response:\\n'+server.responseText );\n");
				}
				laser_js_get_cookie(h);
				laser_indent(h);
				fprintf(h,"thisitem=workroot.firstChild;\n");
				laser_indent(h);
				fprintf(h,"while ( thisitem ) {\n");
				mpeg_enter();
					laser_indent(h);
					fprintf(h,"if ( thisitem.id ) {\n");
					mpeg_enter();
						laser_indent(h);
						fprintf(h,"thisitem.textContent = %s(server.responseText,'tns:'+thisitem.id.substring(workfile.length));\n",_JS_XML_VALUE);
					laser_close_brace(h);
					laser_indent(h);
					fprintf(h,"thisitem=thisitem.nextSibling;\n");
				laser_close_brace(h);
			laser_close_brace(h);
			laser_indent(h);
			fprintf(h,"else { %s('55'); }\n",_JS_FILE_ERROR);
			fprintf(h,"} catch (err) { %s('56'); }\n",_JS_FILE_ERROR);
		laser_close_brace(h);	
		/* --------------------------------- */			
		/* Soap Request / Response Interface */
		/* --------------------------------- */			
		laser_indent(h);
		fprintf(h,"function asynch_%s(tgt,wdgt,kptr) {\n",_SOAP_REQUEST);
		mpeg_enter();
			laser_indent(h);
			fprintf(h,"workname = tgt;\n");
			laser_indent(h);
			fprintf(h,"workfile = wdgt;\n");
			laser_indent(h);
			fprintf(h,"workclass = kptr;\n");
			/* ------------------------------- */	
			/* Soap Message Header Preparation */
			/* ------------------------------- */			
			laser_indent(h);
			fprintf(h,"var message=%c<?xml version='1.0' encoding='ISO-8859-1'?>\\n%c;\n",0x0022,0x0022);
			laser_indent(h);
			fprintf(h,"message +=  %c<SOAP-ENV:Envelope xmlns:SOAP-ENV='http://schemas.xmlsoap.org/soap/envelope/' SOAP-ENV:encodingStyle='http://schemas.xmlsoap.org/soap/encoding/'>\\n%c;\n",0x0022,0x0022);
			laser_indent(h);
			fprintf(h,"message +=  %c<SOAP-ENV:Body>\\n%c;\n",0x0022,0x0022);
			/* --------------------------------- */	
			/* Soap Message Contents Preparation */
			/* --------------------------------- */			
			laser_indent(h);
			fprintf(h,"message += %c<tns:%c+workclass+%c xmlns:tns='%c+%c%s/%c+workclass+%c.xsd'>\\n%c;\n",
				0x0022,0x0022,
				0x0022,0x0022,
				0x0022,LC.serverUrl,0x0022,
				0x0022,0x0022);

			laser_indent(h);
			fprintf(h,"workroot = document.getElementById(workname);\n");
			laser_indent(h);
			fprintf(h,"var thisitem=workroot.firstChild;\n");
			laser_indent(h);
			fprintf(h,"var thistag=0;\n");
			laser_indent(h);
			fprintf(h,"while ( thisitem ) {\n");
				mpeg_enter();
				laser_indent(h);
				fprintf(h,"if ( thisitem.id ) { thistag = thisitem.id.substring(workfile.length); message+='<tns:'+thistag+'>'+thisitem.textContent+'</tns:'+thistag+'>\\n'; }\n");
				laser_indent(h);
				fprintf(h,"thisitem=thisitem.nextSibling;\n");
			laser_close_brace(h);
			laser_indent(h);
			/* ------------------------------- */	
			/* Soap Message Footer Preparation */
			/* ------------------------------- */			
			fprintf(h,"message += %c</tns:%c+workclass+%c>\\n%c;\n",0x0022,0x0022,0x0022,0x0022);
			laser_indent(h);
			fprintf(h,"message +=  %c</SOAP-ENV:Body>%c;\n",0x0022,0x0022);
			laser_indent(h);
			fprintf(h,"message +=  %c</SOAP-ENV:Envelope>\\n%c;\n",0x0022,0x0022);
			if ( LC.withDebug )
			{
				laser_indent(h);
				fprintf(h,"alert('Async Soap Request:\\n'+workname+': '+message);\n");
			}
			/* ------------------------------- */	
			/* Ajax Server Request Preparation */
			/* ------------------------------- */			
			laser_indent(h);
			fprintf(h,"try { server = new XMLHttpRequest(); }\n");
			laser_indent(h);
			fprintf(h,"catch(e) { if (window.XMLHttpRequest) { server=new XMLHttpRequest(); }\n");
			laser_indent(h);
			fprintf(h,"else { server=new ActiveXObject('Microsoft.XMLHTTP'); } }\n");
			laser_indent(h);
			fprintf(h,"server.onreadystatechange = function() {\n");
			laser_indent(h);
			fprintf(h,"if ( server.readyState == 4 ) {\n");
				laser_indent(h);
				fprintf(h,"if ( server.status == 200 ) {\n");
					mpeg_enter();
					/* --------------------------------- */
					/* Integration of SOAP Response Data */
					/* --------------------------------- */
					laser_indent(h);
					fprintf(h,"var xmldoc = server.responseXML;\n");
					if ( LC.withDebug )
					{
						laser_indent(h);
						fprintf(h,"alert( 'Async Soap Response:\\n'+server.responseText );\n");
					}
					laser_js_get_cookie(h);
					laser_indent(h);
					fprintf(h,"var thisitem=workroot.firstChild;\n");
					laser_indent(h);
					fprintf(h,"while ( thisitem ) {\n");
						mpeg_enter();
						laser_indent(h);
						fprintf(h,"if ( thisitem.id ) {\n");
						mpeg_enter();
							laser_indent(h);
							fprintf(h,"thisitem.textContent = %s(server.responseText,'tns:'+thisitem.id.substring(workfile.length));\n",_JS_XML_VALUE);
						laser_close_brace(h);
						laser_indent(h);
						fprintf(h,"thisitem=thisitem.nextSibling;\n");
					laser_close_brace(h);
				laser_close_brace(h);
				laser_indent(h);
				fprintf(h,"else { %s('55'); }\n",_JS_FILE_ERROR);
			laser_indent(h);
			fprintf(h,"}};\n");
			/* --------------------- */
			/* Ajax Request Handling */
			/* --------------------- */
			laser_indent(h);
			if ( LC.serverPhp )
				fprintf(h,"var surl = '%s'+'/%s';\n",LC.serverUrl,pagename);
			else	fprintf(h,"var surl = '%s'+'/'+workname;\n",LC.serverUrl);
			laser_indent(h);
			fprintf(h,"try { server.open('POST',surl,true);\n");
			laser_indent(h);
			fprintf(h,"server.setRequestHeader('Content-type','application/soap+xml; charset=utf-8');\n");
			laser_js_set_cookie(h);
			laser_indent(h);
			fprintf(h,"server.send(message);\n");
			laser_indent(h);
			fprintf(h,"} catch (err) { %s('56'); }\n",_JS_FILE_ERROR);
		laser_close_brace(h);	
	}

	laser_close_script( h );

	if ( pagename )
		liberate( pagename );

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
	LC.withDebug    = ( fptr->extension &   4 ? 1 : 0 );
	LC.testData	= ( fptr->extension &   8 ? 1 : 0 );
	LC.genMp4	= ( fptr->extension &  16 ? 1 : 0 );
	LC.methodText	= ( fptr->extension &  32 ? 1 : 0 );
	LC.soapInterface= ( fptr->extension &  64 ? 1 : 0 );
	LC.serverCommand= ( fptr->extension & 128 ? 1 : 0 );
	LC.serverPhp	= ( fptr->extension & 256 ? 1 : 0 );
	LC.serverAbal   = ( fptr->extension & 512 ? 1 : 0 );
	if (( LC.serverUrl = fptr->hostname) != (char *) 0)
		if ( *LC.serverUrl == '$' )
			if (!( LC.serverUrl = getenv( (LC.serverUrl+1) ) ))
				if ( environment_failure( fptr->hostname ) == 27 )
					cancel_automatic_production();

	return;
}


/*	-------------------------------------------	*/
/*	      l a s e r _ e x p o r t _ f o r m 	*/
/*	-------------------------------------------	*/
int	laser_export_form( FILE * h, struct form_control * fptr )
{
	int	i;
	struct	form_item * iptr;

	prepare_Form( fptr );

	LC.editField = 0;
	LC.groupId = 0,
	LC.buttonPress = 0;
	LC.needBoolean = 0;
	LC.od    = LC.es 	  = 0;
	LC.width = 800; LC.height = 600;
	
	laser_check_namespaces();
	laser_set_form_options( fptr );
	laser_set_palette( fptr );

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style == _WINDOW_FRAME )
		{
			LC.width = iptr->Contents.w+1;
			LC.height = iptr->Contents.h+1;
		}
		else if ( iptr->Contents.style == _EDIT_FRAME )
		{
			iptr->sequence = ++LC.editField;
		}
		else if ( iptr->Contents.style == _BUTTON_FRAME )
		{
			iptr->sequence = ++LC.editField;
		}
	}

	laser_mpeg_production();
	laser_input_streams();
	sing_open_LASER( h, fptr );
	laser_start_project(h);
	laser_open_svg(h,fptr);
	if ( LC.soapCookies ) { laser_string_variable(h,"Cookie","","soap"); }
	laser_proto_definition( h, fptr, fptr->identifier );
	laser_proto_instance( h, fptr,_THIS_INSTANCE,0,0,1,fptr->identifier );
	laser_standard_script(h,fptr);
	laser_close_svg(h);
	laser_close_project(h);

	return(0);
}

/*	-------------------------------------------	*/
/*	  l a s e r _ s o a p _ i n t e r f a c e	*/
/*	-------------------------------------------	*/
int	laser_soap_interface(FILE * h, struct form_control *  fptr, int started )
{
	char *	fnptr;
	struct	form_control * ffptr;
	struct	form_item * iptr;
	char *	classname;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if ( is_file_Widget( iptr ) )
		{
			if (!( classname = resolve_widget_file_class( iptr ) ))
				continue;
			if ( started ) fprintf(h,",");
			fprintf(h,"\n\t\t%ctns:%s%c=>0",0x0022,classname,0x0022);
			started++;
		}
		else if (( iptr->Contents.align & 0x000F) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			return;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			return;
		else	started = laser_soap_interface( h, ffptr, started );
	}
	return( started );
}

/*	-------------------------------------------------	*/
/*	  l a s e r _ s o a p _ f i l e _ i n s t a n c e  	*/
/*	-------------------------------------------------	*/
int	laser_soap_file_instance( FILE * h, struct form_item * iptr )
{
	char *	databasename;
	char *	classname;
	char *	filename;
	if (!( classname = resolve_widget_file_class( iptr ) ))
		return(0);
	else if (!( filename = abal_payload( iptr ) ))
		return(0);
	else
	{
		if (!( databasename = application_databasename() ))
			databasename = "mydatabase";
		fprintf(h,"\t$%s = new %s(%c%s%c,%c%s%c);\n",
			iptr->Contents.name,classname,
			__QUOTE,databasename,__QUOTE,
			__QUOTE,filename,__QUOTE);
		return(1);
	}
}

/*	-------------------------------------------	*/
/*	  l a s e r _ s o a p _ i n s t a n c e  	*/
/*	-------------------------------------------	*/
int	laser_soap_instance(FILE * h, struct form_control *  fptr, int started )
{
	char *	fnptr;
	struct	data_control * 	dptr;
	struct	form_control * ffptr;
	struct	form_item * iptr;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if ( is_file_Widget( iptr ) )
		{
			started += laser_soap_file_instance( h, iptr );
		}
		else if (( iptr->Contents.align & 0x000F) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			return;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			return;
		else	started = laser_soap_instance( h, ffptr, started );
	}
	return( started );
}

/*	-------------------------------------------	*/
/*	    l a s e r _ s o a p _ r e q u e s t		*/
/*	-------------------------------------------	*/
int	laser_soap_request(FILE * h, struct form_control *  fptr, int started )
{
	int	fields;
	int	i;
	char *	fnptr;
	struct	data_control * 	dptr;
	struct	form_control * ffptr;
	struct	form_item * iptr;
	char *	classname;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if ( is_file_Widget( iptr ) )
		{
			if (!( classname = resolve_widget_file_class( iptr ) ))
				continue;
			else if (!(dptr = iptr->Contents.extra ))
				continue;
			else if (!( fields = dptr->indexfields + dptr->datafields ))
				continue;
			else if ( started ) 
				fprintf(h,"\telse if");
			else	fprintf(h,"\tif");
			fprintf(h," ( $xsp->method == %ctns:%s%c ) {\n",0x0022,classname,0x0022);

			laser_soap_file_instance( h, iptr );
			fprintf(h,"\t\t$%s->OnStartSession();\n",iptr->Contents.name);
			fprintf(h,"\t\t$method = $xsp->parameters['tns:%s'];\n",_FILE_METHOD);
			fprintf(h,"\t\t$item   = $xsp->parameters['tns:%s'];\n",_COLLECT_ITEM);
			fprintf(h,"\t\t$%s->question = ltrim( $xsp->parameters['tns:%s'] );\n",iptr->Contents.name,_RECORD_QUESTION);
			for (i=0; i < fields; i++ )
				fprintf(h,"\t\t$%s->_%s = ltrim( $xsp->parameters['tns:%s'] );\n",iptr->Contents.name,dptr->name[i],dptr->name[i]);

			fprintf(h,"\t\t$%s->OnCheck();\n",iptr->Contents.name);
			php_file_method_switch(h,iptr,2);

			fprintf(h,"\t}\n");
			started++;
		}
		else if (( iptr->Contents.align & 0x000F) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			return;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			return;
		else	started = laser_soap_request( h, ffptr, started );
	}
	return( started );
}

/*	-------------------------------------------	*/
/*	    l a s e r _ s o a p _ r e s p o n s e	*/
/*	-------------------------------------------	*/
int	laser_soap_response(FILE * h, struct form_control *  fptr, int started )
{
	int	fields;
	int	i;
	char *	fnptr;
	struct	data_control * 	dptr;
	struct	form_control * ffptr;
	struct	form_item * iptr;
	char *	classname;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if ( is_file_Widget( iptr ) )
		{
			if (!( classname = resolve_widget_file_class( iptr ) ))
				continue;
			else if (!(dptr = iptr->Contents.extra ))
				continue;
			else if (!( fields = dptr->indexfields + dptr->datafields ))
				continue;
			else if ( started ) 
				fprintf(h,"\telse if");
			else	fprintf(h,"\tif");
			fprintf(h," ( $xsp->method == %ctns:%s%c ) {\n",0x0022,classname,0x0022);
			fprintf(h,"\t\t$xsp->StringParameter('tns:%s',$%s->%s);\n",
				_FILE_ERROR, iptr->Contents.name,"error");
			fprintf(h,"\t\t$xsp->StringParameter('tns:%s',$%s->%s);\n",
				_COLLECT_COUNT, iptr->Contents.name,"response");
			for (i=0; i < fields; i++ )
				fprintf(h,"\t\t$xsp->StringParameter('tns:%s',$%s->_%s);\n",
					dptr->name[i],
					iptr->Contents.name,dptr->name[i]);
			fprintf(h,"\t\t$%s->OnSaveSession();\n",iptr->Contents.name);
			fprintf(h,"\t}\n");
			started++;
		}
		else if (( iptr->Contents.align & 0x000F) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			return;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			return;
		else	started = laser_soap_response( h, ffptr, started );
	}
	return( started );
}

/*	-------------------------------------------	*/
/*	  l a s e r _ s o a p _ i n t e r f a c e	*/
/*	-------------------------------------------	*/
void	laser_parse_soap(FILE * h, struct form_control *  fptr )
{
	int			fields=0;
	int			i;
	fprintf(h,"\t/*-------------------------- */\n");
	fprintf(h,"\t/*S O A P  I N T E R F A C E */\n");
	fprintf(h,"\t/*-------------------------- */\n");
	fprintf(h,"\t$soaptempfile = 0;\n");
	fprintf(h,"\t$soapfilename = %c%c;\n",__QUOTE,__QUOTE);
	fprintf(h,"\t$soapmethods = $names = array(");
	laser_soap_interface(h, fptr,0);
	fprintf(h,"\n\t\t);\n");
	fprintf(h,"\tforeach ( $_FILES as $first ) ");
	fprintf(h,"{ $soapfilename = $first[%ctmp_name%c]; break; }\n",__QUOTE,__QUOTE);
	fprintf(h,"\tif ( $soapfilename == %c%c)\n",__QUOTE,__QUOTE);
	fprintf(h,"\t{\n");
		fprintf(h,"\t\t$rdata = implode('',file(%cphp://input%c));\n",__QUOTE,__QUOTE);
		fprintf(h,"\t\t$soapfilename = tempnam(%c/home/soap/%c,%c%sQ%c);\n",__QUOTE,__QUOTE,__QUOTE,fptr->identifier,__QUOTE);
		fprintf(h,"\t\t$thand = fopen($soapfilename,%cw%c);\n",__QUOTE,__QUOTE);
		fprintf(h,"\t\tfwrite($thand,$rdata,strlen($rdata));\n");
		fprintf(h,"\t\tfclose($thand);\n");
		fprintf(h,"\t\t$soaptempfile = 1;\n");
	fprintf(h,"\t}\n");
	fprintf(h,"\t$xsp->ParseFile($soapfilename,$soapmethods);\n");
	fprintf(h,"\t/*---------------------- */\n");
	fprintf(h,"\t/*S O A P  R E Q U E S T */\n");
	fprintf(h,"\t/*---------------------- */\n");
	laser_soap_request(h, fptr,0);
	fprintf(h,"\t/*------------------------ */\n");
	fprintf(h,"\t/*S O A P  R E S P O N S E */\n");
	fprintf(h,"\t/*------------------------ */\n");
	laser_soap_response(h, fptr,0);
	fprintf(h,"\t$rdata = $xsp->SerialiseString();\n");

	if (!( LC.withDebug ))
	{
		fprintf(h,"\tif ( $soaptempfile != 0 ) { unlink($soapfilename); $soaptempfile=0; }\n");
	}
	else
	{
		fprintf(h,"\t/*------------------------ */\n");
		fprintf(h,"\t/* DEBUG - R E S P O N S E */\n");
		fprintf(h,"\t/*------------------------ */\n");
		fprintf(h,"\t$soapfilename = tempnam(%c/home/soap/%c,%c%sR%c);\n",__QUOTE,__QUOTE,__QUOTE,fptr->identifier,__QUOTE);
		fprintf(h,"\t$thand = fopen($soapfilename,%cw%c);\n",__QUOTE,__QUOTE);
		fprintf(h,"\tfwrite($thand,$rdata,strlen($rdata));\n");
		fprintf(h,"\tfclose($thand);\n");
	}
	fprintf(h,"\t/*------------------------ */\n");
	fprintf(h,"\t/* S E N D R E S P O N S E */\n");
	fprintf(h,"\t/*------------------------ */\n");
	fprintf(h,"\theader('Content-Type: application/xml');\n");
	fprintf(h,"\theader('Content-Length: '.strlen($rdata));\n");
	fprintf(h,"\tprint $rdata;\n");
	return;
}

/*	-------------------------------------------	*/
/*	      l a s e r _ e x p o r t _ p h p   	*/
/*	-------------------------------------------	*/
int	laser_export_php( struct form_control * fptr )
{
	char *	databasename;
	char *	nptr;
	FILE *	handle;
	if (!( nptr = allocate_string( fptr->prodname ) ))
		return(27);
	else if (!( nptr = enforce_extension( nptr, PHP_EXTENSION ) ))
		return(27);
	else if (!( handle = open_production_target( nptr, 0) ))
		return( 46 );
	else
	{
		if (!( databasename = application_databasename() ))
			databasename = "mydatabase";
		php_start(handle);
		php_session(handle,databasename);
		fprintf(handle,"\t/*--------------------- */\n");
		fprintf(handle,"\t/*S O A P  4  L A S e R */\n");
		fprintf(handle,"\t/*--------------------- */\n");
		php_file_requires( handle, fptr );
		php_start_soap(handle);
		laser_parse_soap(handle,fptr);
		php_end(handle);
		liberate_php_requires();
		close_production_target( handle, nptr );
		liberate( nptr );
		return(0);
	}
}

public	void	abal_file_members_soapin( FILE * h, struct form_item * iptr, int i )
{
	char	pbuffer[1024];
	char	nbuffer[1024];
	struct	data_control * 	dptr;
	int	nature;
	int	f;
	char *	classname;

	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( classname = resolve_widget_file_class( iptr ) ))
		return;

	indent(h,i++); 
	fprintf(h,"Case =%c%s%c",0x0022,classname,0x0022); 
	linefeed(h);

	indent(h,i); fprintf(h,"Select XmlMember"); linefeed(h);
	indent(h,i);
	fprintf(h,"Case =%c%s%c :: ",0x0022,_FILE_METHOD,__QUOTE);
	fprintf(h,"XmlFileMethod = XmlToken");
	linefeed(h);

	indent(h,i);
	fprintf(h,"Case =%c%s%c :: ",0x0022,_COLLECT_ITEM,__QUOTE);
	fprintf(h,"XmlFileItem = Conv%(XmlToken)");
	linefeed(h);

	indent(h,i);
	fprintf(h,"Case =%c%s%c :: ",0x0022,_RECORD_QUESTION,__QUOTE);
	fprintf(h,"q_%s = XmlToken",iptr->Contents.name);
	linefeed(h);

	for (f=0; f < dptr->datafields; f++ ) 
	{
		if (!( dptr->name[f] ))
			continue;
		else	
		{
			indent(h,i);
			fprintf(h,"Case =%c%s%c :: ",0x0022,dptr->name[f],__QUOTE);
			if ( dptr->type[f] == _ABAL_STRING )
			{
				fprintf(h,"OnAddToken(_%s_%s,Len(_%s_%s),XmlToken,XmlSize)",
					dptr->name[f],iptr->Contents.name,
					dptr->name[f],iptr->Contents.name);
				linefeed(h);
			}
			else
			{
				fprintf(h,"_%s_%s = Conv(XmlToken)",dptr->name[f],iptr->Contents.name);
				linefeed(h);
			}
		}
	}

	indent(h,i); fprintf(h,"Default :: XmlMember = %c %c :: Exit(55)",0x0022,0x0022); linefeed(h);
	indent(h,i); fprintf(h,"EndSel ;**  XmlMember"); linefeed(h);
	return;
}

public	void	abal_file_members_soapwipe( FILE * h, struct form_item * iptr, int i )
{
	char	pbuffer[1024];
	char	nbuffer[1024];
	struct	data_control * 	dptr;
	int	nature;
	int	f;
	char *	classname;

	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( classname = resolve_widget_file_class( iptr ) ))
		return;

	indent(h,1);
	fprintf(h,"Case =%c%s%c",0x0022,classname,__QUOTE);
	linefeed(h);
	indent(h,i);
	fprintf(h,"Select XmlToken");
	linefeed(h);

	indent(h,i);
	fprintf(h,"Case =%c%s%c :: ",0x0022,_FILE_METHOD,__QUOTE);
	fprintf(h,"XmlFileMethod = %c %c",0x0022,0x0022);
	linefeed(h);

	indent(h,i);
	fprintf(h,"Case =%c%s%c :: ",0x0022,_COLLECT_ITEM,__QUOTE);
	fprintf(h,"XmlFileItem = 0");
	linefeed(h);

	indent(h,i);
	fprintf(h,"Case =%c%s%c :: ",0x0022,_RECORD_QUESTION,__QUOTE);
	fprintf(h,"q_%s = %c %c",iptr->Contents.name,0x0022,0x0022);
	linefeed(h);

	for (f=0; f < dptr->datafields; f++ ) 
	{
		if (!( dptr->name[f] ))
			continue;
		else	
		{
			indent(h,i);
			fprintf(h,"Case =%c%s%c :: ",0x0022,dptr->name[f],__QUOTE);
			if ( dptr->type[f] == _ABAL_STRING )
			{
				fprintf(h,"_%s_%s = %c %c",
					dptr->name[f],iptr->Contents.name,
					0x0022,0x0022);
				linefeed(h);
			}
			else
			{
				fprintf(h,"_%s_%s = 0",dptr->name[f],iptr->Contents.name);
				linefeed(h);
			}
		}
	}
	indent(h,i); fprintf(h,"Default :: Exit(78)"); linefeed(h);
	indent(h,i);
	fprintf(h,"EndSel");
	linefeed(h);
	return;
}

public	void	abal_file_members_soapout( FILE * h, struct form_item * iptr )
{
	char	pbuffer[1024];
	char	nbuffer[1024];
	struct	data_control * 	dptr;
	int	nature;
	int	f;
	char *	classname;

	if (!(dptr = iptr->Contents.extra ))
		return;
	else if (!( classname = resolve_widget_file_class( iptr ) ))
		return;

	indent(h,1);
	fprintf(h,"Case =%c%s%c",0x0022,classname,0x0022);
	linefeed(h);

	sprintf(nbuffer,"%s_%s","e",iptr->Contents.name);
	abal_soap_result(h,_FILE_ERROR,nbuffer,_ABAL_WORD);

	sprintf(nbuffer,"%s_%s","n",iptr->Contents.name);
	abal_soap_result(h,_COLLECT_COUNT,nbuffer,_ABAL_WORD);

	for (f=0; f < dptr->datafields; f++ ) 
	{
		if (!( dptr->name[f] ))
			continue;
		else	
		{
			sprintf(nbuffer,"_%s_%s",dptr->name[f],iptr->Contents.name);
			abal_soap_result(h,dptr->name[f],nbuffer,dptr->type[f]);
		}
	}

	return;
}

int	laser_abal_file_method( FILE * h, struct form_item * iptr, char * mptr, int i, int ngfcode )
{
	indent(h,i);
	fprintf(h,"Case %c%s%c",0x0022,mptr,0x0022);
	linefeed(h);
	if ( ngfcode )
	{
		abal_data_instruction( h, iptr, ngfcode, i+1, "", 0);
	}
	return;
}

int	laser_abal_file_methods( FILE * h, struct form_control * fptr )
{
	char 			*	fnptr;
	struct	form_control 	* 	ffptr;
	struct	form_item 	* 	iptr;
	char			*	classname;
	
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if ( is_file_Widget( iptr ) )
		{
			if (!( classname = resolve_widget_file_class( iptr ) ))
				continue;
			else
			{
				indent(h,1);
				fprintf(h,"Case %c%s%c",0x0022,classname,0x0022);
				linefeed(h);
				indent(h,2);
				fprintf(h,"Select XmlFileMethod",0x0022,classname,0x0022);
				linefeed(h);
				laser_abal_file_method(h,iptr,"Assign",2,DATA_MEMBER_ASSIGN);	
				laser_abal_file_method(h,iptr,"Open",2,DATA_MEMBER_OPEN);	
				laser_abal_file_method(h,iptr,"Close",2,DATA_MEMBER_CLOSE);	
				laser_abal_file_method(h,iptr,"OnCreate",2,DATA_MEMBER_ONCREATE);	
				laser_abal_file_method(h,iptr,"OnRemove",2,DATA_MEMBER_ONREMOVE);	
				laser_abal_file_method(h,iptr,"Search",2,DATA_MEMBER_SEARCH);	
				laser_abal_file_method(h,iptr,"Insert",2,DATA_MEMBER_INSERT);	
				laser_abal_file_method(h,iptr,"Modif",2,DATA_MEMBER_MODIF);	
				laser_abal_file_method(h,iptr,"Update",2,DATA_MEMBER_UPDATE);	
				laser_abal_file_method(h,iptr,"Delete",2,DATA_MEMBER_DELETE);	
				laser_abal_file_method(h,iptr,"Up",2,DATA_MEMBER_UP);	
				laser_abal_file_method(h,iptr,"Down",2,DATA_MEMBER_DOWN);	
				laser_abal_file_method(h,iptr,"Collect",2,DATA_MEMBER_COLLECT);	
				laser_abal_file_method(h,iptr,"Locate",2,DATA_MEMBER_LOCATE);	
				laser_abal_file_method(h,iptr,"Posit",2,DATA_MEMBER_POSIT);	
				laser_abal_file_method(h,iptr,"Count",2,DATA_MEMBER_COUNT);	
				indent(h,2);
				fprintf(h,"EndSel");
				linefeed(h);
				continue;
			}
		}
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	laser_abal_file_methods(h, ffptr );
	}
	return;
}

int	laser_abal_file_services( FILE * h, struct form_control * fptr )
{
	char 			*	fnptr;
	struct	form_control 	* 	ffptr;
	struct	form_item 	* 	iptr;
	char			*	classname;
	
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if ( is_file_Widget( iptr ) )
		{
			if (!( classname = resolve_widget_file_class( iptr ) ))
				continue;
			else
			{
				indent(h,7);
				fprintf(h,"Case %c%s%c :: XmlMethod = XmlToken",0x0022,classname,0x0022);
				linefeed(h);
				continue;
			}
		}
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	laser_abal_file_services(h, ffptr );
	}
	return;
}

void	laser_file_web_service( struct form_control * fptr, char * target )
{
	char 			*	fnptr;
	struct	form_control 	* 	ffptr;
	struct	form_item 	* 	iptr;
	char			*	classname;
	
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if ( is_file_Widget( iptr ) )
		{
			if (!( classname = resolve_widget_file_class( iptr ) ))
				continue;
			else
			{
				soap_webservice_record(classname,"\0",target);
				continue;
			}
		}
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	laser_file_web_service(ffptr,target );
	}
	return;
}

char *	current_working_directory( char * iname  )
{
	char *	ipath;
	if (!( iname ))
		return( iname );
#ifdef	UNIX
	else if ( *iname == '/' )
		return( iname );
	else if ( *iname == '.' )
		return( iname );
#else
	else if ( *(iname+1) == ':' )
		return( iname );
	else if ( *iname == '\\' )
		return( iname );
	else if ( *iname == '.' )
		return( iname );
#endif
	if (( ipath = allocate( 1024 )) != (char *) 0) {
		getcwd(ipath,1023);
		if ( strlen(ipath) > 1 ) {
#ifdef	UNIX
			strcat(ipath,"/");
#else
			strcat(ipath,"\\");
#endif
			strcat(ipath,iname);
			}
		liberate(iname);
		}
	else	ipath = iname;
	return( ipath );
}

/*	-------------------------------------------	*/
/*	l a s e r _ a b a l _ w e b _ s e r v i c e  	*/
/*	-------------------------------------------	*/
int	laser_abal_web_service( FILE * handle, struct form_control * fptr, char * filename )
{
	int	holder;
	char *	empty;
	char *	target;
	/* -------------------------------------- */
	/* generate WSI file description for WASP */
	/* -------------------------------------- */
	if ((target = allocate_string(filename)) != (char *) 0)
	{
		if ((target = enforce_extension( target, AT_EXTENSION)) != (char *) 0)
		{
			if (( target = current_working_directory( target )) != (char *) 0)
			{
				open_server_description(fptr,0);
				laser_file_web_service(fptr,target);
				close_server_description();
				liberate( target );
			}
		}
	}

	/* -------------------------------------- */
	/*  Generate the Abal Web Service Source  */
	/* -------------------------------------- */
	empty = set_abal_empty_string();
	holder = abal_open_web_service(handle,fptr);
	abal_web_service_forwards(handle);
	abal_soap_forward(handle,(char*)0,"OnMember","ptr o$",1);
	abal_soap_forward(handle,(char*)0,"OnMethod","ptr o$",1);
	abal_soap_forward(handle,(char*)0,"OnResult","ptr o$,class soap_response pointer SOAP,ptr prefix$,pl%",1);
	abal_soap_preconstruction(handle);
	abal_soap_postdestruction(handle);

	/* ----------------------------------- */
	/* The Web Service Construction Method */
	/* ----------------------------------- */
	linefeed(handle);
	fprintf(handle,"Proc OnCreate(ptr o$,ptr b$,bl%c) : %c ",0x0025,0x0025);
	linefeed(handle);
	abal_file_construction(handle, fptr );
	abal_endproc(handle);

	/* ---------------------------------- */
	/* The Web Service Destruction Method */
	/* ---------------------------------- */
	linefeed(handle);
	fprintf(handle,"Proc OnRemove(ptr o$) : %c ",0x0025);
	abal_file_destruction( handle, fptr );
	linefeed(handle);
	abal_endproc(handle);

	/* ---------------------------------- */
	/* The Web Service Web Host Interface */
	/* ---------------------------------- */
	linefeed(handle);
	fprintf(handle,"Proc OnRequest(ptr o$,XmlName$=256) : %c",0x0025);
	linefeed(handle);
		indent(handle,1); fprintf(handle,"XmlResult = 0"); linefeed(handle);
		indent(handle,1); fprintf(handle,"XmlMethod = %c %c",__QUOTE,__QUOTE); linefeed(handle);
		indent(handle,1); fprintf(handle,"XmlMember = %c %c",__QUOTE,__QUOTE); linefeed(handle);
		indent(handle,1); fprintf(handle,"XmlHandle = Event(77)"); linefeed(handle);
		indent(handle,1); fprintf(handle,"if ( XmlHandle <> 0 )"); linefeed(handle);
		indent(handle,2); fprintf(handle,"Assign=XmlHandle,XmlName,XML:Next,XmlStatus"); linefeed(handle);
		indent(handle,2); fprintf(handle,"if ( XmlStatus = 0 )"); linefeed(handle);
		indent(handle,3); fprintf(handle,"Open=XmlHandle:Next,XmlStatus"); linefeed(handle);
		indent(handle,3); fprintf(handle,"if ( XmlStatus = 0 )"); linefeed(handle);
		indent(handle,4); fprintf(handle,"Do"); linefeed(handle);
		indent(handle,5); fprintf(handle,"Read=XmlHandle,/60,0:Next,XmlStatus,XmlBuffer"); linefeed(handle);
		indent(handle,5); fprintf(handle,"if ( XmlStatus <> 0 ) :: Break :: Endif"); linefeed(handle);
		indent(handle,5); fprintf(handle,"Select XmlType"); linefeed(handle);
		indent(handle,5); fprintf(handle,"Case 1 ;** open tag "); linefeed(handle);
		indent(handle,6); fprintf(handle,"if ( Len$(XmlMethod) = 0 )"); linefeed(handle);
		indent(handle,7); fprintf(handle,"Select XmlToken"); linefeed(handle);
		laser_abal_file_services( handle, fptr );
		indent(handle,7); fprintf(handle,"EndSel "); linefeed(handle);
		indent(handle,6); fprintf(handle,"Else :: OnMember(o)"); linefeed(handle);
		indent(handle,6); fprintf(handle,"Endif"); linefeed(handle);
		indent(handle,5); fprintf(handle,"EndSel"); linefeed(handle);
		indent(handle,4); fprintf(handle,"Loop"); linefeed(handle);
		indent(handle,4); fprintf(handle,"Event(77) = XmlHandle"); linefeed(handle);
		indent(handle,4); fprintf(handle,"OnMethod(o)"); linefeed(handle);
		indent(handle,3); fprintf(handle,"Endif"); linefeed(handle);
		indent(handle,2); fprintf(handle,"Endif"); linefeed(handle);
		indent(handle,1); fprintf(handle,"Endif"); linefeed(handle);
	abal_endproc(handle);

	abal_file_onresult(handle, fptr );
	abal_file_onresponse(handle, fptr, LC.serverUrl );

	linefeed(handle);
	fprintf(handle,"Proc OnMethod(ptr o$) : %c",0x0025);
	linefeed(handle);
		indent(handle,1); fprintf(handle,"Select XmlMethod"); linefeed(handle);
		laser_abal_file_methods( handle, fptr );
		indent(handle,1); fprintf(handle,"EndSel ;**  XmlMethod"); linefeed(handle);
	abal_endproc(handle);

	abal_onaddtoken( handle );

	linefeed(handle);
	fprintf(handle,"Proc OnMember(ptr o$) : %c",0x0025);
	linefeed(handle);
		indent(handle,1); fprintf(handle,"Select XmlMethod"); linefeed(handle);
		abal_file_soapwipe(handle, fptr);
		indent(handle,1); fprintf(handle,"Default :: Exit(78)"); linefeed(handle);
		indent(handle,1); fprintf(handle,"EndSel ;**  XmlMethod"); linefeed(handle);
		indent(handle,1); fprintf(handle,"XmlMember = XmlToken"); linefeed(handle);
		indent(handle,1); fprintf(handle,"Do"); linefeed(handle);
		indent(handle,2); fprintf(handle,"Read=XmlHandle,/60,0:Next,XmlStatus,XmlBuffer"); linefeed(handle);
		indent(handle,2); fprintf(handle,"if ( XmlStatus <> 0 )"); linefeed(handle);
		indent(handle,3); fprintf(handle,"XmlMember = %c %c",__QUOTE,__QUOTE); linefeed(handle);
		indent(handle,3); fprintf(handle,"Exit( XmlStatus )"); linefeed(handle);
		indent(handle,2); fprintf(handle,"Endif"); linefeed(handle);
		indent(handle,2); fprintf(handle,"Select XmlType"); linefeed(handle);
		indent(handle,2); fprintf(handle,"Case 1,4;** open or close tag"); linefeed(handle);
		indent(handle,3); fprintf(handle,"XmlMember = %c %c",__QUOTE,__QUOTE); linefeed(handle);
		indent(handle,3); fprintf(handle,"Exit(0)"); linefeed(handle);
		indent(handle,2); fprintf(handle,"Case 5 ;** tag data"); linefeed(handle);
		indent(handle,3); fprintf(handle,"Select XmlMethod"); linefeed(handle);
		abal_file_soapin(handle, fptr);
		indent(handle,3); fprintf(handle,"Default :: XmlMember = %c %c :: Exit(56)",0x0022,0x0022); linefeed(handle);
		indent(handle,3); fprintf(handle,"EndSel ;**  XmlMethod"); linefeed(handle);
		indent(handle,2); fprintf(handle,"EndSel ;**  XmlType"); linefeed(handle);
		indent(handle,1); fprintf(handle,"Loop"); linefeed(handle);
	abal_endproc(handle);
	linefeed(handle);

	holder = abal_close_web_service(handle,fptr,holder);
	close_server_description();
	set_empty_string( empty );
	return(0);
}

/*	-------------------------------------------	*/
/*	l a s e r _ a b a l _ t r a n s l a t i o n	*/
/*	-------------------------------------------	*/
int	laser_abal_translation( FILE * handle, struct form_control * fptr, char * filename )
{
	translate_abal(1,filename,1,NULL);
	return(0);
}

/*	-------------------------------------------	*/
/*	      l a s e r _ e x p o r t _ a b a l   	*/
/*	-------------------------------------------	*/
int	laser_export_abal( struct form_control * fptr )
{
	char *	nptr;
	FILE *	handle;
	if (!( nptr = allocate_string( fptr->prodname ) ))
		return(27);
	else if (!( nptr = enforce_extension( nptr, AS_EXTENSION ) ))
		return(27);
	else if (!( handle = open_production_target( nptr, 0 ) ))
		return( 46 );
	else
	{
		/* generate abal web service overlay */
		/* --------------------------------- */
		laser_abal_web_service( handle, fptr, nptr );
		close_production_target( handle, nptr );

		/* generate abal web service overlay */
		/* --------------------------------- */
		laser_abal_translation( handle, fptr, nptr );
		liberate( nptr );

		return(0);
	}
}

/*	-------------------------------------------	*/
/*	      e x p o r t _ L A S e R _ f o r m 	*/
/*	-------------------------------------------	*/
int	export_LASER_form( FILE * h, struct form_control * fptr )
{
	if (!( LC.w3cWidget ))
		laser_export_form( h, fptr );
	else if (!( w3c_widget_package( fptr , 0 ) ))
		laser_export_form( h,fptr );

	if (( LC.soapInterface ) && ( LC.serverUrl ))
		export_xsd( fptr, LC.serverUrl );

	if ( LC.serverPhp )
		laser_export_php( fptr );

	if ( LC.serverAbal )
		laser_export_abal( fptr );

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
		&fptr->hostname,
		&LC.safNs, &LC.laserNs, &LC.svgNs,
		&LC.useSaf,
		&LC.useLaser,
		&LC.withDebug,
		&LC.testData,
		&LC.genMp4,
		&LC.methodText,
		&LC.soapInterface,
		&LC.serverCommand,
		&LC.serverPhp,
		&LC.serverAbal,
		&LC.w3cWidget )  == 27 )
		return( 27 );
	else
	{
		fptr->extension = 0;
		if ( LC.useSaf 		) fptr->extension |=    1;
		if ( LC.useLaser 	) fptr->extension |=    2;
		if ( LC.withDebug 	) fptr->extension |=    4;
		if ( LC.testData	) fptr->extension |=    8;
		if ( LC.genMp4		) fptr->extension |=   16;
		if ( LC.methodText	) fptr->extension |=   32;
		if ( LC.soapInterface	) fptr->extension |=   64;
		if ( LC.serverCommand	) fptr->extension |=  128;
		if ( LC.serverPhp    	) fptr->extension |=  256;
		if ( LC.serverAbal   	) fptr->extension |=  512;
		if ( LC.useSaf != 0 )
			fptr->prodname = enforce_extension( fptr->prodname, _EXT_LSR );
		else 	fptr->prodname = enforce_extension( fptr->prodname, _EXT_SVG );
		return(13);
	}
}

	/* ------------ */
#endif	/* _singLASER_c */
	/* ------------ */


