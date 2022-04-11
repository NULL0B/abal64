#ifndef	_singBIFS_c
#define	_singBIFS_c

#define	_EXT_PROTO	".bth"
#define	_EXT_MP4 	".mp4"
#define	_BUTTON_PRESS	'BP'

#define	_FOCUS_PREFIX	"focus_"
#define	_LOSE_PREFIX	"lose_"
#define	_SENSOR_PREFIX	"sensor_"
#define	_TRIGGER_PREFIX	"trigger_"
#define	_PRESS_PREFIX	"press_"

#define	_LOCAL_PREFIX	"local_"

#define	_BUFFER_PREFIX	"buffer_"
#define	_VALUE_PREFIX	"value_"
#define	_FRAME_PREFIX	"frame_"

#define	_CICO_PREFIX	"cico_"
#define	_KEYDOWN_PREFIX	"keydown_"
#define	_KEYUP_PREFIX	"keyup_"
#define	_ACTDOWN_PREFIX	"actdown_"


struct	proto_item
{
	struct	proto_item * next;
	char *	name;
};

static	struct	bifs_configuration {

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

	int	width;			/* width of production window.				*/
	int	height;			/* the height of the production window			*/

	int	AudioLevel;		/* level of preference for audio profiles 255		*/
	int	VisualLevel;		/* level of preference for visual profiles 255		*/
	int	SceneLevel;		/* level of preference for scene profiles 255		*/
	int	GraphicsLevel;		/* level of preference for graphic profiles 255		*/
	int	ODLevel;		/* level of preference for OD profiles 255		*/

	struct	proto_item * protoHeap;	/* the list of defined PROTO descriptions.		*/

	} BC = 	{ 

		0, 1, 0, 1,		/* options : data, comments, protos, indent		*/

		1,			/* use key sensor 	*/
		0,0,			/* key sensor infos	*/

		0,			/* use string sensor 	*/
		0,0,			/* string sensor infos	*/

		0,0,			/* font information	*/

		0,0,0,			/* OD and ES counters	*/

		800,600,		/* default dimensions	*/

		254,254,254,254,254, 	/* default profiles	*/

		(struct proto_item *) 0,

		};

/*	-----------------------------------------------------------------------	*/
/*			b i f s _ m p e g _ p r o d u c t i o n 		*/
/*	-----------------------------------------------------------------------	*/
/*	this function sets the productino window sizes used to calculate widget */
/*	position information using Transform/translation nodes.			*/
/*	-----------------------------------------------------------------------	*/
void	bifs_mpeg_production()
{
	mpeg_production( BC.width, BC.height );
	return;
}

void	bifs_input_streams()
{
	/* --------------------------------------- */
	/* Elementary Stream : Key Sensor Infos    */
	/* --------------------------------------- */
	BC.primary = ++BC.od;

	if ( BC.keySensor )
	{
		BC.KeySensorID = ++BC.es;			
		BC.KeySensorOD = ++BC.od;			
	}
	else if ( BC.stringSensor )
	{
		BC.StringSensorID = ++BC.es;			
		BC.StringSensorOD = ++BC.od;			
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
void	exchange_mpeg_production( struct window_control * wptr )
{
	int	v;
	v = wptr->w;
	wptr->w = BC.width;
	BC.width = v;
	v = wptr->h;
	wptr->h = BC.height;
	BC.height = v;
	bifs_mpeg_production();
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			      a d d _ p r o t o _ i t e m			*/
/*	-----------------------------------------------------------------------	*/
/*	this function provides PROTO definition shadow list handling to avoid	*/
/*	multiple generation of forms proto definitions.				*/
/*	-----------------------------------------------------------------------	*/
int	add_proto_item( char * nptr )
{
	struct	proto_item * pptr;
	for (	pptr=BC.protoHeap;
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
		pptr->next = BC.protoHeap;
		BC.protoHeap = pptr;
		return(1);
	}
}

/*	-----------------------------------------------------------------------	*/
/*				d r o p _ p r o t o _ h e a p			*/
/*	-----------------------------------------------------------------------	*/
/*	releases the shadow list of PROTO definitions upon completion of the BT	*/
/*	productino operation.
/*	-----------------------------------------------------------------------	*/
void	drop_proto_heap()
{
	struct	proto_item * pptr;
	while ((pptr=BC.protoHeap) != (struct proto_item *) 0)
	{
		BC.protoHeap = pptr->next;
		if ( pptr->name )
			liberate( pptr->name );
		liberate( pptr );
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				b i f s _ i n d e n t    			*/
/*	-----------------------------------------------------------------------	*/
/*	this function controls inclusion of source indenting which ioncreases 	*/
/*	file size and so may be inhibited to optimise for transmission source.	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_indent( FILE * h )
{
	if ( BC.indentSource )
		mpeg_indent( h );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				b i f s _ c o m m e n t  			*/
/*	-----------------------------------------------------------------------	*/
/*	this function generates comment messages when allowed by configuration	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_comment( FILE * h, char * message )
{
	int	l;
	int	i;
	if ( BC.withComments )
	{
		if (( message )
		&&  ((l = strlen(message)) != 0))
		{
			if ( BC.indentSource ) { bifs_indent( h ); }
			fprintf(h,"# ");
			for ( i=0; i < l; i++)
				fprintf(h,"-");
			fprintf(h,"\n");

			if ( BC.indentSource ) { bifs_indent( h ); }
			fprintf(h,"# %s \n",message);

			if ( BC.indentSource ) { bifs_indent( h ); }
			fprintf(h,"# ");
			for ( i=0; i < l; i++)
				fprintf(h,"-");
			fprintf(h,"\n");
		}
	}	
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				b i f s _ o p e n _ t a g			*/
/*	-----------------------------------------------------------------------	*/
/*	this function generates a BiFS tag opener with eventual object name and	*/
/*	eventual indentation control.						*/
/*	-----------------------------------------------------------------------	*/
void	bifs_open_tag( FILE * h, char * nptr )
{
	bifs_indent(h);
	fprintf(h,"%s {\n",nptr);
	mpeg_enter();
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				b i f s _ c l o s e _ t a g			*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_close_tag( FILE * h, char * nptr )
{
	bifs_indent(h);
	fprintf(h,"}");
	if ( BC.withComments )
		if ( nptr )
			fprintf(h," # %s",nptr);
	fprintf(h,"\n");
	mpeg_leave();
}

/*	-----------------------------------------------------------------------	*/
/*				b i f s _ e n d _ t a g				*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_end_tag( FILE * h, int v )
{
	if ( v )
		bifs_close_tag( h, "empty" );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_tag( FILE * h, char * nptr )
{
	bifs_open_tag(h,nptr);
	bifs_end_tag(h,0);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_def_tag( FILE * h, char * nptr, char * xptr )
{
	bifs_indent(h);
	fprintf(h,"DEF %s %s {\n",xptr,nptr);
	mpeg_enter();
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			b i f s _ t o u c h _ s e n s o r			*/
/*	-----------------------------------------------------------------------	*/
/*	generates a touch sensor for mouse activity event capture for use by 	*/
/*	interactive widgets edit, check, radio, switch, select, tab and scroll	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_touch_sensor( FILE * h, char * nptr )
{
	bifs_indent(h);
	fprintf(h,"DEF %s%s %s {}\n",_SENSOR_PREFIX,nptr,"TouchSensor");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	 			b i f s _ e d i t _ r o u t e			*/
/*	-----------------------------------------------------------------------	*/
/*	generates a ROUTE instruction for the indicated edit field widget to be	*/
/*	able to distribute the edit field focus item.				*/
/*	-----------------------------------------------------------------------	*/
void	bifs_edit_route( FILE * h, struct form_item * iptr )
{
	bifs_indent(h);
	fprintf(h,"ROUTE %s%s.isActive TO %s%s.activate\n",
		_SENSOR_PREFIX,iptr->Contents.name,
		_TRIGGER_PREFIX,iptr->Contents.name);
	bifs_indent(h);
	fprintf(h,"ROUTE %s%s.outSFInt32 TO %s%s.getch\n",
		_KEYDOWN_PREFIX,iptr->Contents.name,_CICO_PREFIX,iptr->Contents.name);
	bifs_indent(h);
	fprintf(h,"ROUTE %s%s.outSFInt32 TO %s%s.cursor\n",
		_ACTDOWN_PREFIX,iptr->Contents.name,_CICO_PREFIX,iptr->Contents.name);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			b i f s _ i n p u t _ r o u t e				*/
/*	-----------------------------------------------------------------------	*/
/*	generates routing of Key Input Sensor Events to the Key Echo StringNode	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_input_route( FILE * h, struct form_control * fptr )
{
	bifs_indent(h);
	fprintf(h,"ROUTE CiKeyDown.outSFInt32 TO CICO.getch\n");
	bifs_indent(h);
	fprintf(h,"ROUTE CiActionDown.outSFInt32 TO CICO.cursor\n");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_tab_route( FILE * handle, struct form_item * iptr )
{
	struct	form_control * fptr;
	if (!( fptr = iptr->parent ))
		return;
	bifs_indent(handle);
	fprintf(handle,"ROUTE %s%s.isActive TO %s%s.activate\n",
		_SENSOR_PREFIX,iptr->Contents.name,
		_TRIGGER_PREFIX,iptr->Contents.name);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_check_route( FILE * handle, struct form_item * iptr )
{
	bifs_indent(handle);
	fprintf(handle,"ROUTE %s%s.isActive TO %s%s.activate\n",
		_SENSOR_PREFIX,iptr->Contents.name,
		_TRIGGER_PREFIX,iptr->Contents.name);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_radio_route( FILE * handle, struct form_item * iptr )
{
	bifs_indent(handle);
	fprintf(handle,"ROUTE %s%s.isActive TO %s%s.activate\n",
		_SENSOR_PREFIX,iptr->Contents.name,
		_TRIGGER_PREFIX,iptr->Contents.name);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_switch_route( FILE * handle, struct form_item * iptr )
{
	bifs_indent(handle);
	fprintf(handle,"ROUTE %s%s.isActive TO %s%s.activate\n",
		_SENSOR_PREFIX,iptr->Contents.name,
		_TRIGGER_PREFIX,iptr->Contents.name);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_scroll_route( FILE * handle, struct form_item * iptr )
{
	bifs_indent(handle);
	fprintf(handle,"ROUTE %s%s.isActive TO %s%s.activate\n",
		_SENSOR_PREFIX,iptr->Contents.name,
		_TRIGGER_PREFIX,iptr->Contents.name);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				b i f s _ f i e l d				*/
/*	-----------------------------------------------------------------------	*/
/*	generates a standard node field.					*/
/*	-----------------------------------------------------------------------	*/
void	bifs_field( FILE * h, char * nptr, char * vptr )
{
	bifs_indent(h);
	fprintf(h,"%s %s\n",nptr, vptr);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_is_field( FILE * h, char * nptr, char * vptr )
{
	bifs_indent(h);
	fprintf(h,"%s IS %s\n",nptr, vptr);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				b i f s _ e v e n t - i n			*/
/*	-----------------------------------------------------------------------	*/
/*	generates an eventIn field member					*/
/*	-----------------------------------------------------------------------	*/
void	bifs_event_in( FILE * h, char * nptr, char * tptr )
{
	bifs_indent(h);
	fprintf(h,"eventIn %s %s\n",tptr, nptr);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				b i f s _ e v e n t - o u t 			*/
/*	-----------------------------------------------------------------------	*/
/*	generates an eventOut field member					*/
/*	-----------------------------------------------------------------------	*/
void	bifs_event_out( FILE * h, char * nptr, char * tptr )
{
	bifs_indent(h);
	fprintf(h,"eventOut %s %s\n",tptr, nptr);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_quoted( FILE * h, char * nptr, char * vptr )
{
	bifs_indent(h);
	fprintf(h,"%s %c%s%c\n",nptr, 0x0022,vptr,0x0022);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_string( FILE * h, char * nptr, char * vptr )
{
	bifs_indent(h);
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

/*	----------------------------------------	*/
/*	    b i f s _ s t r i n g _ p a i r 		*/
/*	----------------------------------------	*/
/*	used for text alignment or justification 	*/
/*	----------------------------------------	*/
void	bifs_string_pair( FILE * h, char * nptr, char * vptr, char * wptr )
{
	bifs_indent(h);
	fprintf(h,"%s [ %c%s%c %c%s%c ]\n",nptr, 0x0022,vptr,0x0022, 0x0022,wptr,0x0022);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_integer_field( FILE * h, char * nptr, int vptr )
{
	char	value[32];
	sprintf(value,"%d",vptr);
	bifs_field(h,nptr,value);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			b i f s _ v e c t o r _ 2 d _ f i e l d			*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_vector_2d_field( FILE * h, char * nptr, int x, int y )
{
	char	value[64];
	sprintf(value,"%d %d",x,y);
	bifs_field(h,nptr,value);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_vector_3d_field( FILE * h, char * nptr, int x, int y,int z )
{
	char	value[96];
	sprintf(value,"%d %d %d",x,y,z);
	bifs_field(h,nptr,value);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_collection( FILE * h, char * nptr )
{
	bifs_indent(h);
	fprintf(h,"%s [\n",nptr);
	mpeg_enter();
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_close_collection( FILE * h, char * nptr )
{
	bifs_indent(h);
	fprintf(h,"]");
	if ( BC.withComments )
		fprintf(h," # %s",nptr);
	fprintf(h,"\n");
	mpeg_leave();
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_end_collection( FILE * h, int v )
{
	if ( v )
		bifs_close_collection( h, "empty" );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_background( FILE * h, int colour )
{
	char	work[1024];
	mpeg_colour( (colour & 0x00FF) , work);
	bifs_tag(h,"Background");
		bifs_field(h,"skyColor",work);
	bifs_close_tag(h,"Background");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				b i f s _ o d _ u r l 				*/
/*	-----------------------------------------------------------------------	*/
/*	generates an object descriptor type url if the od parameter is not zero	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_od_url( FILE * h, char * nptr, int od )
{
	char	work[8192];
	if (!( od ))
	{
		if ( nptr )
		{
			sprintf(work,"[ %c%s%c ]",0x0022,nptr,0x0022);
			bifs_field(h,"url",work);
		}
	}
	else
	{
		sprintf(work,"[ %cod:%u%c ]",0x0022,od,0x0022);
		bifs_field(h,"url",work);
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_background2d( FILE * h, int colour,char * member )
{
	char	work[1024];
	if ( member )
		sprintf( work,"%s Background2D",member);
	else	strcpy(work,"Background2D");
	bifs_tag(h,work);
		mpeg_colour( (colour & 0x00FF) , work);
		bifs_field(h,"backColor",work);
	bifs_close_tag(h,"Background2D");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				b i f s _ w o r l d i n f o			*/
/*	-----------------------------------------------------------------------	*/
/*	generates the world info tag with copyright and other gnerator details.	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_worldinfo( FILE * h, char * info, char * title )
{
	char	work[1024];
	bifs_tag(h,"WorldInfo");
		bifs_string_pair(h,"info",info,"Copyright (c) Amenesik / Sologic");
		bifs_string(h,"title",title);
	bifs_close_tag(h,"WorldInfo");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			b i f s _ s t a n d a r d _ i n p u t			*/
/*	-----------------------------------------------------------------------	*/
/*	generates the standard input handling mechanisms that will dispatch key	*/
/*	information to the appropriate edit filed input buffer.			*/
/*	-----------------------------------------------------------------------	*/

#define	_BIFS_BACKSPACE_KEY	 8
#define	_BIFS_ENTER_KEY		13
#define	_BIFS_END_KEY		14
#define	_BIFS_PAGEUP_KEY	15
#define	_BIFS_PAGEDOWN_KEY	16
#define	_BIFS_UP_KEY		17
#define	_BIFS_DOWN_KEY		18
#define	_BIFS_LEFT_KEY		19
#define	_BIFS_RIGHT_KEY		20
#define	_BIFS_ESCAPE_KEY	27
#define	_BIFS_INSERT_KEY	45
#define	_BIFS_DELETE_KEY	46

void	bifs_standard_input( FILE * h )
{
	return;
}

void	bifs_key_sensor( FILE * h, char * name )
{
	char	work[1024];
	if ( BC.keySensor > 1 )
	{
	/* -------------------------------------------------- */
	/* this is the Node Structure that displays Key Input */
	/* -------------------------------------------------- */
	bifs_tag(h,"Transform2D");
		bifs_field(h,"translation","0 0");
		bifs_collection(h,"children");
			bifs_tag(h,"Shape");
				bifs_tag(h,"appearance Appearance");
					bifs_tag(h,"material Material2D");
						bifs_field(h,"emissiveColor","1 0 0");
						bifs_field(h,"filled","TRUE");
        				bifs_close_tag(h,"material");
        			bifs_close_tag(h,"appearance");
				bifs_tag(h,"geometry DEF DEBUG Text");
					bifs_string(h,"string","");
					bifs_tag(h,"fontStyle FontStyle");
						bifs_justify(h,_A_CENTER);
						bifs_field(h,"size","20");
					bifs_close_tag(h,"FontStyle");
				bifs_close_tag(h,"geometry");
       			bifs_close_tag(h,"Shape");
		bifs_close_collection(h,"children");
	bifs_close_tag(h,"Transform2D");
	}

	/* -------------------------------------------------- */
	/* this is the Node Structure that receives Key Input */
	/* -------------------------------------------------- */
	sprintf(work,"%s%s",_KEYDOWN_PREFIX,name);
	bifs_def_tag(h,"Valuator",work);
	bifs_close_tag(h,"Valuator");
	sprintf(work,"%s%s",_KEYUP_PREFIX,name);
	bifs_def_tag(h,"Valuator",work);
	bifs_close_tag(h,"Valuator");
	sprintf(work,"%s%s",_ACTDOWN_PREFIX,name);
	bifs_def_tag(h,"Valuator",work);
	bifs_close_tag(h,"Valuator");

	sprintf(work,"%s%s",_FOCUS_PREFIX,name);
	bifs_def_tag(h,"InputSensor",work);
		bifs_field(h,"enabled","FALSE");
		bifs_od_url(h,(char *) 0,BC.KeySensorOD);
		bifs_tag(h,"buffer");
			bifs_indent(h);
			fprintf(h,"REPLACE %s%s.inSFInt32 BY 0\n",_KEYDOWN_PREFIX,name);
			bifs_indent(h);
			fprintf(h,"REPLACE %s%s.inSFInt32 BY 0\n",_KEYUP_PREFIX,name);
			bifs_indent(h);
			fprintf(h,"REPLACE %s%s.inSFInt32 BY 0\n",_ACTDOWN_PREFIX,name);
		bifs_close_tag(h,"buffer");
	bifs_close_tag(h,"InputSensor");

	/* -------------------------------------------------- */
	/* this is the Node Structure that receives Key Input */
	/* -------------------------------------------------- */
	sprintf(work,"%s%s",_CICO_PREFIX,name);
	bifs_def_tag(h,"Script",work);

	bifs_event_in(h,"getch","SFBool");
	bifs_event_in(h,"cursor","SFBool");

	bifs_indent(h);
	fprintf(h,"field SFInt32 bytes 0\n");
	bifs_indent(h);
	fprintf(h,"field SFInt32 current 0\n");
	bifs_indent(h);
	fprintf(h,"field SFInt32 insert 0\n");

	bifs_indent(h);
	fprintf(h,"field SFNode buffer USE %s%s\n",_BUFFER_PREFIX,name);
	bifs_indent(h);
	fprintf(h,"field SFNode source USE %s%s\n",_KEYDOWN_PREFIX,name);
	bifs_indent(h);
	fprintf(h,"field SFNode action USE %s%s\n",_ACTDOWN_PREFIX,name);

	bifs_collection(h,"url");
	bifs_indent(h);
	fprintf(h,"%cjavascript:\n",0x0022);

	bifs_tag(h,"function getch(value)");

		/* insert key */
		/* ---------- */
		bifs_indent(h);
		fprintf(h,"if ( source.outSFInt32 == %u ) { if ( insert > 0 ) { insert = 0; } else { insert = 1; }\n",_BIFS_INSERT_KEY);

		/* delete key */
		/* ---------- */
		bifs_indent(h);
		fprintf(h,"} else if ( source.outSFInt32 == %u ) { if ( current > 0 ) { \n",_BIFS_DELETE_KEY);
		bifs_indent(h);
		fprintf(h,"buffer.string[0] = buffer.string[0].slice(0,current).concat(buffer.string[0].slice(current+1)); }\n");

		/* backspace key */
		/* ------------- */
		bifs_indent(h);
		fprintf(h,"} else if ( source.outSFInt32 == %u ) { if ( current > 0 ) { \n",_BIFS_BACKSPACE_KEY);
		bifs_indent(h);
		fprintf(h,"current--; buffer.string[0] = buffer.string[0].slice(0,current).concat(buffer.string[0].slice(current+1)); }\n");

		bifs_indent(h);
		fprintf(h,"} else if ( source.outSFInt32 >= 32 ) {\n");

			bifs_indent(h);
			fprintf(h,"if ( current == bytes ) {\n");

				/* add to end of the current string value */
				/* -------------------------------------- */
				bifs_indent(h);
				fprintf(h,"buffer.string[0] = buffer.string[0].concat(String.fromCharCode(source.outSFInt32));\n");

			bifs_indent(h);
			fprintf(h,"} else if ( insert > 0 ) {\n");

				/* insert at cursor position string value */
				/* -------------------------------------- */
				bifs_indent(h);
				fprintf(h,"buffer.string[0] = buffer.string[0].slice(0,current).concat( String.fromCharCode(source.outSFInt32)).concat(buffer.string[0].slice(current));\n");

			bifs_indent(h);
			fprintf(h,"} else {\n");

				/* overwrite at current cursor */
				/* --------------------------- */
				bifs_indent(h);
				fprintf(h,"buffer.string[0] = buffer.string[0].slice(0,current).concat( String.fromCharCode(source.outSFInt32)).concat(buffer.string[0].slice(current+1));\n");

			bifs_indent(h);
			fprintf(h,"}\n");

			/* and final cursor position */
			/* ------------------------- */
			bifs_indent(h);
			fprintf(h,"current += 1;\n");

		bifs_indent(h);
		fprintf(h,"}\n");

		/* update final string length */
		/* -------------------------- */
		bifs_indent(h);
		fprintf(h,"bytes = buffer.string[0].length();\n");


	bifs_close_tag(h,(char *) 0);

	bifs_tag(h,"function cursor(value)");

		/* left arrow */
		/* ---------- */
		bifs_indent(h);
		fprintf(h,"if ( action.outSFInt32 == %u ) { if ( current > 0 ) { current--; }\n",_BIFS_LEFT_KEY);


		/* right arrow */
		/* ----------- */
		bifs_indent(h);
		fprintf(h,"} else if ( action.outSFInt32 == %u ) { if ( current < bytes ) { current++; }\n",_BIFS_RIGHT_KEY);


		/* end key */
		/* ------- */
		bifs_indent(h);
		fprintf(h,"} else if ( action.outSFInt32 == %u ) { if ( current < bytes ) { current = bytes; } else { current = 0; }\n",_BIFS_END_KEY);

		bifs_indent(h);
		fprintf(h,"}\n");

	bifs_close_tag(h,(char *) 0);

	bifs_indent(h);
	fprintf(h,"%c\n",0x0022);

	bifs_close_collection(h,"url");
	bifs_close_tag(h,"Script");

	return;
}

void	bifs_string_sensor( FILE * h, char * name )
{
	char work[1024];
	sprintf(work,"%s%s",_FOCUS_PREFIX,name);
	bifs_def_tag(h,"InputSensor",work);
		bifs_field(h,"enabled","FALSE");
		bifs_od_url(h,(char *) 0,BC.StringSensorOD);
		bifs_tag(h,"buffer");
			bifs_indent(h);
			fprintf(h,"REPLACE %s%s.string[0] BY \"\"\n",_BUFFER_PREFIX,name);
			bifs_indent(h);
			fprintf(h,"REPLACE %s%s.string[0] BY \"\"\n",_BUFFER_PREFIX,name);
		bifs_close_tag(h,"buffer");
	bifs_close_tag(h,"InputSensor");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_material( FILE * handle, char * colour, int filled, int framewidth )
{
	bifs_tag(handle,"appearance Appearance");
		bifs_tag(handle,"material Material2D");
			bifs_field(handle,"emissiveColor",colour);
			if ( filled )
				bifs_field(handle,"filled","true");
			else	bifs_field(handle,"filled","true");
			bifs_tag(handle,"lineProps LineProperties");
				bifs_integer_field(handle,"width",framewidth);
			bifs_close_tag(handle,"lineProps LineProperties");
		bifs_close_tag(handle,"Material2D");
	bifs_close_tag(handle,"appearance");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_filzone( FILE * handle, int x, int y, int w, int h, int colour, char * name )
{
	char	work[1024];

	//printf("bifs_filzone( %u,%u, %u,%u : %s )\n",x,y,w,h,(name ? name : "\0" ));

	// --------------------------------
	// generate translation to position
	// --------------------------------
	bifs_tag(handle,"Transform2D");
		mpeg_translation( work, x, y, w, h );
		// printf("bifs_transform( %s )\n",work);
		bifs_field(handle,"translation",work);

	bifs_collection(handle,"children");

	if (!( name ))
		bifs_tag(handle,"Shape");
	else	bifs_def_tag(handle,"Shape",name);

	// ----------------------------
	// generate the widget geometry
	// ----------------------------
	bifs_tag(handle,"geometry Rectangle");
		sprintf(work,"%u %u",w,h);
		bifs_field(handle,"size",work);
		bifs_close_tag(handle,"Rectangle");

	// ------------------------------
	// generate the widget appearance
	// ------------------------------
	mpeg_colour( (colour & 0x00FF) , work);
	bifs_material(handle,work,1,0);

	// ------------------------------
	// close all open groups and tags 
	// ------------------------------
	bifs_close_tag(handle,"Shape");
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_focuszone( FILE * handle, int x, int y, int w, int h, int colour, char * name )
{
	char	work[1024];

	// --------------------------------
	// generate translation to position
	// --------------------------------
	bifs_tag(handle,"Transform2D");
		mpeg_translation( work, x, y, w, h );
		bifs_field(handle,"translation",work);

	bifs_collection(handle,"children");

	bifs_touch_sensor(handle,name);

	bifs_tag(handle,"Shape");

	// ----------------------------
	// generate the widget geometry
	// ----------------------------
	bifs_tag(handle,"geometry Rectangle");
		sprintf(work,"%u %u",w,h);
		bifs_field(handle,"size",work);
		bifs_close_tag(handle,"Rectangle");

	// ------------------------------
	// generate the widget appearance
	// ------------------------------
	bifs_tag(handle,"appearance Appearance");
		bifs_tag(handle,"material Material2D");
			mpeg_colour( (colour & 0x00FF) , work);
			bifs_field(handle,"emissiveColor",work);
			bifs_field(handle,"filled","false");
			sprintf(work,"lineProps DEF %s%s LineProperties",_FOCUS_PREFIX,name);
			bifs_tag(handle,work);
			bifs_integer_field(handle,"width",0);
		bifs_close_tag(handle,"Material2D");
		bifs_close_tag(handle,"Appearance");
	bifs_close_tag(handle,"appearance");

	// ------------------------------
	// close all open groups and tags 
	// ------------------------------
	bifs_close_tag(handle,"Shape");
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_circle( FILE * handle, int x, int y, int w, int h, int colour, int border, char * name )
{
	char	work[1024];

	// --------------------------------
	// generate translation to position
	// --------------------------------
	bifs_tag(handle,"Transform2D");
		mpeg_translation( work, x, y, w, h );
		bifs_field(handle,"translation",work);

	bifs_collection(handle,"children");

	bifs_tag(handle,"Shape");

	// ----------------------------
	// generate the widget geometry
	// ----------------------------
	bifs_tag(handle,"geometry Circle");
		bifs_integer_field(handle,"radius",( w > h ? h/2 : w / 2 ));
		bifs_close_tag(handle,"Circle");

	// ------------------------------
	// generate the widget appearance
	// ------------------------------
	bifs_tag(handle,"appearance Appearance");
		bifs_tag(handle,"material Material2D");
			mpeg_colour( (colour & 0x00FF) , work);
			bifs_field(handle,"emissiveColor",work);
			bifs_field(handle,"filled","true");
			bifs_tag(handle,"lineProps LineProperties");
				mpeg_colour( (colour & 0x00FF) , work);
				bifs_field(handle,"lineColor",work);
				bifs_integer_field(handle,"width",1);
			bifs_close_tag(handle,"Material2D");
		bifs_close_tag(handle,"Appearance");
	bifs_close_tag(handle,"appearance");

	// ------------------------------
	// close all open groups and tags 
	// ------------------------------
	bifs_close_tag(handle,"Shape");
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_draw_relief(FILE * h, int atx,int aty, int nbx, int nby, int hl, int bg, int ll,char * name )
{
	if ( bg != transparent )
		bifs_filzone(h,atx,aty,nbx,nby,bg,name);
	bifs_filzone(h,atx,aty,nbx,1,hl,(char *) 0);
	bifs_filzone(h,atx,aty,1,nby,hl,(char *) 0);
	bifs_filzone(h,(atx+nbx),aty,1,nby,ll,(char *) 0);
	bifs_filzone(h,atx,(aty+nby),nbx,1,ll,(char *) 0);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_relief( FILE * handle, int atx, int aty, int nbx, int nby, int style, char * name )
{
	int	bg;

	if (( nbx > 0 ) && ( nby > 0 )) {

	switch (( style & _FRAME_TYPE )) {

		case	_RADIO_FRAME :
			bifs_circle(handle, atx,aty,nbx,nby,standard_black,standard_black,(char *) 0);
			bifs_circle(handle, atx+1,aty+1,nbx-2,nby-2,standard_white,standard_black,(char *) 0);
			break;

		case	_EDIT_FRAME :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_black,standard_white,standard_black,name);
			break;

		case	_OUTSET_FRAME :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_hilight,standard_backwash,standard_lolight,(char *) 0);
			break;

		case	_BUTTON_FRAME :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_hilight,standard_backwash,standard_lolight,name);
			break;

		case	_BUTTON_PRESS :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_lolight,standard_backwash,standard_hilight,(char *) 0);
			break;

		case	_WINDOW_FRAME :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_hilight,standard_backwash,standard_lolight,(char *) 0);
			break;

		case	_SCROLL_FRAME  :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_lolight,standard_backwash-1,standard_hilight,name);
			break;

		case	_INSET_FRAME  :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_lolight,standard_backwash,standard_hilight,(char *) 0);
			break;

		case	_RIDGE_FRAME  :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_hilight,standard_backwash,standard_lolight,(char *) 0);
			if (( nbx > 2 ) && ( nby > 2 )) 
				bifs_draw_relief(handle,(atx+1),(aty+1),(nbx-2),(nby-2),standard_lolight,transparent,standard_hilight,(char *) 0);
			break;

		case	_GROOVE_FRAME :
			transparent = transparent;
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_lolight,standard_backwash,standard_hilight,(char *) 0);
			if (( nbx > 2 ) && ( nby > 2 )) 
				bifs_draw_relief(handle, (atx+1),(aty+1),(nbx-2),(nby-2),standard_hilight,transparent,standard_lolight,(char *) 0);
			break;

		}
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				b i f s _ j u s t i f y				*/
/*	-----------------------------------------------------------------------	*/
/*	generates the text justification matrix of string values for text nodes	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_justify( FILE * handle, int align )
{

	switch ( align )
	{
		case	_A_NONE	:
		case	_A_LEFT	:
			bifs_string_pair(handle,"justify","FIRST","MIDDLE");
			break;
		case	_A_CENTER	:
		case	_A_JUSTIFY	:
			bifs_string_pair(handle,"justify","MIDDLE","MIDDLE");
			break;
		case	_A_RIGHT	:
			bifs_string_pair(handle,"justify","END","MIDDLE");
			break;
	}
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_text( FILE * handle, int x, int y, int w, int h, char * mptr, int colour, char * name, int align )
{
	int	xalign=0;
	char	work[1024];
	// --------------------------------
	// generate translation to position
	// --------------------------------
	bifs_tag(handle,"Transform2D");
	switch ( align )
	{
		case	_A_LEFT		:
			mpeg_translation( work, x-(w/2), y, w, h );
			break;
		case	_A_RIGHT	:
			mpeg_translation( work, x+(w/2), y, w, h );
			break;
		case	_A_CENTER	:
		case	_A_JUSTIFY	:
			mpeg_translation( work, x, y, w, h );
			break;
	}
	bifs_field(handle,"translation",work);

	bifs_collection(handle,"children");

#ifdef	TRY_LAYOUT
	if ((xalign = align) != _A_CENTER )
	{

		bifs_tag(handle,"Layout");
			bifs_field(handle,"wrap","TRUE");
			sprintf(work,"%u %u",w,h);
			bifs_field(handle,"size",work);
			bifs_justify( handle, align );
		align= _A_CENTER;	
		bifs_collection(handle,"children");
	}
#endif
	if (!( name ))
		bifs_tag(handle,"Shape");
	else	bifs_def_tag(handle,"Shape",name);

	// ----------------------------
	// generate the widget geometry
	// generate the text message
	// ----------------------------
	bifs_tag(handle,"geometry Text");
		bifs_string(handle,"string",mptr);
		bifs_tag(handle,"fontStyle FontStyle");
		if ( align != _A_NONE )
		{
			bifs_justify( handle, align );

		}
		bifs_integer_field(handle,"size",BC.fontHeight);
		bifs_close_tag(handle,"FontStyle");
	bifs_close_tag(handle,"Text");

	// ------------------------------
	// generate the widget appearance
	// ------------------------------
	mpeg_colour( (colour & 0x00FF) , work);
	bifs_material(handle,work,1,0);

	// ------------------------------
	// close all open groups and tags 
	// ------------------------------
	bifs_close_tag(handle,"Shape");
#ifdef	TRY_LAYOUT
	if ( xalign != _A_CENTER )
	{
		bifs_close_collection(handle,"children");
		bifs_close_tag(handle,"Layout");
	}
#endif
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			      b i f s _ t e x t _ v a l u e			*/
/*	-----------------------------------------------------------------------	*/
/*	this function is called from by bifs edit widget production function to	*/
/*	define and connect the text value buffer for use by the standard editor	*/
/*	text input mechanism, and also to receive an eventual parameter whcih 	*/
/*	may have been provided via the instance expression.			*/
/*	-----------------------------------------------------------------------	*/
void	bifs_text_value( FILE * handle, int x, int y, int w, int h, char * mptr, int colour, int align, char * nptr )
{
	char	work[1024];
	// --------------------------------
	// generate translation to position
	// --------------------------------
	bifs_tag(handle,"Transform2D");
	switch ( align )
	{
		case	_A_LEFT		:
			mpeg_translation( work, x-(w/2), y, w, h );
			break;
		case	_A_RIGHT	:
			mpeg_translation( work, x+(w/2), y, w, h );
			break;
		case	_A_CENTER	:
		case	_A_JUSTIFY	:
			mpeg_translation( work, x, y, w, h );
			break;
	}
	bifs_field(handle,"translation",work);

	bifs_collection(handle,"children");

	bifs_tag(handle,"Shape");

	// ----------------------------
	// generate the widget geometry
	// generate the text message
	// ----------------------------

		/* ---------------------------- */
		/* Define and Expose this Field */
		/* ---------------------------- */
		sprintf(work,"geometry DEF %s%s Text",_BUFFER_PREFIX,nptr);
		bifs_tag(handle,work);
		bifs_string(handle,"string","");

		bifs_tag(handle,"fontStyle FontStyle");
		if ( align != _A_NONE )
		{
			switch ( align )
			{
				case	_A_NONE	:
				case	_A_LEFT	:
					bifs_string_pair(handle,"justify","FIRST","MIDDLE");
					break;
				case	_A_CENTER	:
				case	_A_JUSTIFY	:
					bifs_string_pair(handle,"justify","MIDDLE","MIDDLE");
					break;
				case	_A_RIGHT	:
					bifs_string_pair(handle,"justify","END","MIDDLE");
					break;
			}
		}
		bifs_integer_field(handle,"size",BC.fontHeight);
		bifs_close_tag(handle,"FontStyle");

	bifs_close_tag(handle,"Text");

	// ------------------------------
	// generate the widget appearance
	// ------------------------------
	mpeg_colour( (colour & 0x00FF) , work);
	bifs_material(handle,work,1,0);

	// ------------------------------
	// close all open groups and tags 
	// ------------------------------
	bifs_close_tag(handle,"Shape");
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_image( FILE * handle, int x, int y, int w, int h, char * iptr, char * name )
{
	char	work[1024];
	// --------------------------------
	// generate translation to position
	// --------------------------------
	bifs_tag(handle,"Transform2D");
		mpeg_translation( work, x, y, w, h );
		bifs_field(handle,"translation",work);

	bifs_collection(handle,"children");

	if (!( name ))
		bifs_tag(handle,"Shape");
	else	bifs_def_tag(handle,"Shape",name);

	// ----------------------------
	// generate the widget geometry
	// generate the text message
	// ----------------------------
	bifs_tag(handle,"geometry Rectangle");
		sprintf(work,"%u %u",w,h);
		bifs_field(handle,"size",work);
		bifs_close_tag(handle,"Rectangle");

	// ------------------------------
	// generate the widget appearance
	// ------------------------------
	bifs_tag(handle,"appearance Appearance");
		bifs_tag(handle,"material Material2D");
		bifs_field(handle,"filled","true");
		bifs_close_tag(handle,"Material2D");
		if (( detect_extension( iptr, ".png"  ) )
		||  ( detect_extension( iptr, ".jpg"  ) )
		||  ( detect_extension( iptr, ".jpeg" ) )
		||  ( detect_extension( iptr, ".gif"  ) )
		||  ( detect_extension( iptr, ".bmp"  ) ))
		{
			bifs_tag(handle,"texture ImageTexture");
				bifs_od_url( handle, iptr, 0 );
			bifs_close_tag(handle,"ImageTexture");
		}
		else
		{
			bifs_tag(handle,"texture MovieTexture");
				bifs_od_url( handle, iptr, 0 );
			bifs_close_tag(handle,"MovieTexture");
		}
	bifs_close_tag(handle,"appearance");

	// ------------------------------
	// close all open groups and tags 
	// ------------------------------
	bifs_close_tag(handle,"Shape");
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_open_switch(FILE * h, char * nptr, int value )
{
	bifs_def_tag(h,"Switch",nptr );
	bifs_integer_field(h,"whichChoice",value);
	bifs_collection(h,"choice");
	return;
}
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_close_switch(FILE * h)
{
	bifs_close_collection(h,"choice");
	bifs_close_tag(h,"Switch");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_checkbox( FILE * handle, int x, int y, int w, int h, char * mptr, struct form_item * iptr )
{
	char 	work[1024];
	bifs_tag(handle,"Transform2D");
	bifs_collection(handle,"children");
	bifs_comment(handle,"table check sensor");
	bifs_touch_sensor(handle,iptr->Contents.name);
	bifs_comment(handle,"table check box frame");
	bifs_relief( handle, x,y,BC.fontHeight,BC.fontHeight, _EDIT_FRAME, (char *) 0);
	bifs_comment(handle,"table check message");
	bifs_text( handle, x+(2*BC.fontHeight),y,w-(2*BC.fontHeight),h, mptr, standard_black, (char *) 0,_A_LEFT);
	sprintf(work,"VALUE_%s",iptr->Contents.name);
	bifs_comment(handle,"table check value");
	bifs_open_switch( handle, work,0 );
		bifs_filzone(handle,x+3,y+3,BC.fontHeight-6,BC.fontHeight-6,standard_white,(char *) 0);
		bifs_filzone(handle,x+3,y+3,BC.fontHeight-6,BC.fontHeight-6,standard_black,(char *) 0);
	bifs_close_switch(handle);
	bifs_comment(handle,"table check trigger");
	bifs_toggle_conditional(handle,iptr);
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_switch( FILE * handle, int x, int y, int w, int h, char * mptr, struct form_item * iptr )
{
	char 	work[1024];
	int	fg;
	int	bg;
	fg = (iptr->Contents.colour & 0x00FF);
	bg = ((iptr->Contents.colour >> 8) & 0x00FF);
	bifs_tag(handle,"Transform2D");
	bifs_collection(handle,"children");
	bifs_comment(handle,"table switch sensor");
	bifs_touch_sensor(handle,iptr->Contents.name);
	bifs_comment(handle,"table switch frame");
	bifs_relief( handle, x,y,w,h, _INSET_FRAME, (char *) 0);
	sprintf(work,"VALUE_%s",iptr->Contents.name);
	bifs_open_switch( handle, work,0 );

		/* false value */
		bifs_comment(handle,"table switch false value");
		bifs_tag(handle,"Transform2D");
		bifs_collection(handle,"children");
			bifs_filzone(handle,x+2,y+2,w-4,h-4,bg,(char *) 0);
			bifs_text( handle, x+2,y+2,w-4,h-4, mptr, fg, (char *) 0,_A_CENTER);
		bifs_close_collection(handle,"children");
		bifs_close_tag(handle,"Transform2D");

		bifs_comment(handle,"table switch true value");
		bifs_tag(handle,"Transform2D");	
		bifs_collection(handle,"children");
			bifs_filzone(handle,x+2,y+2,w-4,h-4,fg,(char *) 0);
			bifs_text( handle, x+2,y+2,w-4,h-4,mptr, bg, (char *) 0,_A_CENTER);
		bifs_close_collection(handle,"children");
		bifs_close_tag(handle,"Transform2D");

	bifs_close_switch(handle);
	bifs_comment(handle,"table switch trigger");
	bifs_toggle_conditional(handle,iptr);
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_radiobox( FILE * handle, int x, int y, int w, int h, char * mptr, struct form_item * iptr )
{
	char 	work[1024];
	bifs_tag(handle,"Transform2D");
	bifs_collection(handle,"children");
	bifs_comment(handle,"table radio sensor");
	bifs_touch_sensor(handle,iptr->Contents.name);
	bifs_comment(handle,"table radio frame");
	bifs_relief( handle, x,y,BC.fontHeight,BC.fontHeight, _RADIO_FRAME,(char *) 0);
	bifs_comment(handle,"table radio message");
	bifs_text( handle, x+(2*BC.fontHeight),y,w-(2*BC.fontHeight),h, mptr, standard_black, (char *) 0,_A_LEFT);
	sprintf(work,"VALUE_%s",iptr->Contents.name);
	bifs_comment(handle,"table radio value");
	bifs_open_switch( handle, work,0 );
		bifs_circle(handle,x+3,y+3,BC.fontHeight-6,BC.fontHeight-6,standard_white,0,(char *) 0);
		bifs_circle(handle,x+3,y+3,BC.fontHeight-6,BC.fontHeight-6,standard_black,0,(char *) 0);
	bifs_close_switch(handle);
	bifs_comment(handle,"table radio trigger");
	bifs_toggle_conditional(handle,iptr);
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_button( FILE * handle, int x, int y, int w, int h, char * message, char * name, int align, int style )
{
	char * framename[1024];
	sprintf(framename,"%s%s",_FRAME_PREFIX,name);
	if ( align & 1 ) // is image
	{
		if ( align & 2 ) // no frame
		{
			bifs_comment(handle,"image button");
			bifs_image( handle, x,y,w,h, message, framename );
		}
		else
		{
			bifs_comment(handle,"framed image button");
			bifs_relief( handle, x,y,w,h, style, name);
			bifs_image( handle, x+2,y+2,w-4,h-4, message, (char *) 0 );
		}
	}
	else
	{
		if (!( align & 2 )) // has frame
		{
			bifs_comment(handle,"framed text button");
			bifs_relief( handle, x,y,w,h, style, name);
			bifs_text( handle, x+2,y+2,w-4,h-4, message, standard_text, (char *) 0,_A_CENTER);
		}
		else
		{
			bifs_comment(handle,"text button");
			bifs_text( handle, x,y,w,h, message, standard_text, (char *) 0,_A_CENTER);
		}
	}
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_pushbutton( FILE * h, struct form_item * iptr )
{
	int	isanchor=0;
	switch ( iptr->Contents.datatype )
	{
	case _WIDGET_OVERLAY :
	case _WIDGET_CHAIN   :
	case _WIDGET_SYSTEM  :
	case _WIDGET_TASK    :
	case _WIDGET_LOADGO  :
		bifs_comment(h,"table button link");
		if ((isanchor = bifs_anchor(h,iptr->Contents.format )) != 0)
			bifs_collection(h,"children");
		
	}
	bifs_button(
		h,
		iptr->Contents.x, iptr->Contents.y, 
		iptr->Contents.w, iptr->Contents.h, 
		abal_payload( iptr ),
		( iptr->Contents.name  ? iptr->Contents.name : (char *) 0),
		iptr->Contents.align, _BUTTON_FRAME
		);

	if ( isanchor )
	{
		bifs_close_collection(h,"children");
		bifs_close_tag(h,"Anchor");
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_tab_button( FILE * handle, struct form_item * iptr )
{
	char	work[1024];
	int	fh = guifontsize(iptr->Contents.font);
	int	fw = (fh & 0x00FF);
	fh >>= 8;
	fh &= 0x00FF;

	bifs_tag(handle,"Transform2D");
	bifs_collection(handle,"children");
	bifs_comment(handle,"tab button sensor");
	bifs_touch_sensor(handle,iptr->Contents.name);
	bifs_comment(handle,"tab button trigger");
	bifs_open_switch(handle,iptr->Contents.name,(iptr->Contents.page == 1 ? 1 : 0));
	bifs_tag(handle,"Transform2D");
	bifs_collection(handle,"children");
	bifs_comment(handle,"tab button hide");
	bifs_button( handle, 
		iptr->Contents.x+iptr->Contents.adjust,
		iptr->Contents.y,
		iptr->Contents.xlimit,
		(fh + 8 ),
		abal_payload(iptr),
		iptr->Contents.name,
		0,_BUTTON_FRAME);
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	bifs_tag(handle,"Transform2D");
	bifs_collection(handle,"children");
	bifs_comment(handle,"tab button show");
	bifs_button( handle, 
		iptr->Contents.x+iptr->Contents.adjust,
		iptr->Contents.y,
		iptr->Contents.xlimit,
		(fh + 8 ),
		abal_payload(iptr),
		iptr->Contents.name,
		0,_BUTTON_PRESS);
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	bifs_close_switch(handle);
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_open_conditional( FILE * handle, char * nptr )
{
	char	work[1024];
	sprintf(work,"%s%s",_TRIGGER_PREFIX,nptr);
	bifs_def_tag(handle,"Conditional",work);
	bifs_tag(handle,"buffer");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_press_conditional( FILE * handle, char * nptr )
{
	char	work[1024];
	sprintf(work,"%s%s",_PRESS_PREFIX,nptr);
	bifs_def_tag(handle,"Conditional",work);
	bifs_tag(handle,"buffer");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_close_conditional( FILE * handle )
{
	bifs_close_tag(handle,"buffer");
	bifs_close_tag(handle,"Conditional");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_tab_conditional( FILE * handle, struct form_item * iptr,struct form_control * fptr )
{
	char	work[1024];
	struct	form_item * wptr;
	bifs_open_conditional(handle,iptr->Contents.name);
		bifs_indent(handle);
		fprintf(handle,"REPLACE %s.whichChoice BY %u\n",iptr->Contents.name,1);
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
				bifs_indent(handle);
				fprintf(handle,"REPLACE %s.whichChoice BY %u\n",wptr->Contents.name,0);
			}
		}
		bifs_indent(handle);
		fprintf(handle,"REPLACE %s.whichChoice BY %u\n",fptr->identifier,iptr->Contents.page-1);
	bifs_close_conditional(handle);
}

/*	-----------------------------------------------------------------------	*/
/*		    b i f s _ t o g g l e _ c o n d i t i o n a l		*/
/*	-----------------------------------------------------------------------	*/
/*	this method is called for the generation of a conditional node which is	*/
/*	capable of toggling between two boolean values : true and false, called	*/
/*	to satisfy the needs of check, radio and switch widgets.		*/
/*	-----------------------------------------------------------------------	*/
void	bifs_toggle_conditional( FILE * handle, struct form_item * iptr )
{
	char	work[1024];
	sprintf(work,"%s%s",_TRIGGER_PREFIX,iptr->Contents.name);
	bifs_def_tag(handle,"Script", work );
		bifs_indent(handle);
		fprintf(handle,"eventIn SFBool activate\n");
		bifs_indent(handle);
		fprintf(handle,"field SFNode state USE VALUE_%s\n",iptr->Contents.name);
		bifs_collection(handle,"url" );
		bifs_indent(handle);
		fprintf(handle,"%cjavascript: function activate(value) { if ( value ) { if ( state.whichChoice ) { state.whichChoice = 0; } else { state.whichChoice = 1; } } }%c\n",0x0022,0x0022);
		bifs_close_collection(handle,"url" );
	bifs_close_tag( handle, "Script");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		    	b i f s _ e d i t _ c o n d i t i o n a l		*/
/*	-----------------------------------------------------------------------	*/
/*	this method is called for the generation of a conditional node which is	*/
/*	capable of activation the corresponding data input mechanism, is called	*/
/*	to satisfy the needs of the edit ( and table ) widgets.			*/
/*	-----------------------------------------------------------------------	*/
void	bifs_edit_conditional( FILE * handle, struct form_item * iptr )
{
	char	work[1024];
	sprintf(work,"%s%s",_TRIGGER_PREFIX,iptr->Contents.name);
	bifs_def_tag(handle,"Conditional", work );
		bifs_tag(handle,"buffer");
		bifs_indent(handle);
//		fprintf(handle,"REPLACE %s%s.string[0] BY \"OOPS\"\n",_BUFFER_PREFIX,iptr->Contents.name);
		fprintf(handle,"REPLACE %s%s.enabled BY TRUE\n",_FOCUS_PREFIX,iptr->Contents.name);
		bifs_close_tag(handle,"buffer" );
	bifs_close_tag( handle, "Conditional");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*		    	b i f s _ e d i t _ f o c u s 				*/
/*	-----------------------------------------------------------------------	*/
/*	this method is called for the generation of a conditional node which is	*/
/*	capable of activation the corresponding data input mechanism, is called	*/
/*	to satisfy the needs of the edit ( and table ) widgets.			*/
/*	-----------------------------------------------------------------------	*/
void	bifs_edit_focus( FILE * h, struct form_item * iptr )
{
	char	work[1024];
	struct	form_control * fptr;
	if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;

	sprintf(work,"%s%s",_TRIGGER_PREFIX,iptr->Contents.name);
	bifs_def_tag(h,"Script", work );

	bifs_indent(h);
	fprintf(h,"eventIn SFBool activate\n");
	bifs_indent(h);
	fprintf(h,"field SFNode master USE %s%s\n",_LOSE_PREFIX,fptr->identifier);
	bifs_indent(h);
	fprintf(h,"field SFNode manager USE %s%s\n",_FOCUS_PREFIX,iptr->Contents.name);

	bifs_collection(h,"url");

	bifs_indent(h);

	fprintf(h,"%cjavascript:\n",0x0022);

	/* ---------------------------------------------------------- */
	/* this function is called on the cascade down to clear focus */
	/* ---------------------------------------------------------- */

	bifs_tag(h,"function activate(value)");
	bifs_tag(h,"if ( value )");

		bifs_indent(h);
		fprintf(h,"master.loseFocus(1);\n");
		bifs_indent(h);
		fprintf(h,"manager.enabled = TRUE;\n");

	bifs_close_tag(h,(char *) 0);
	bifs_close_tag(h,(char *) 0);

	bifs_indent(h);
	fprintf(h,"%c\n",0x0022);

	bifs_close_collection(h,"url");
	bifs_close_tag(h,"Script");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_toggle_page( FILE * handle, struct form_control * fptr)
{
	int	pages=0;
	char	work[1024];
	struct	form_item * iptr;
	sprintf(work,"TOGGLE_%s",fptr->identifier);
	bifs_def_tag(handle,"Script", work );
		bifs_indent(handle);
		fprintf(handle,"eventIn SFBool activate\n");
		bifs_indent(handle);
		fprintf(handle,"field SFNode state USE %s\n",fptr->identifier);
		bifs_collection(handle,"url" );
		bifs_indent(handle);
		fprintf(handle,"%cjavascript: function activate(value) {\n",0x0022);
		bifs_indent(handle);
		fprintf(handle,"if ( value ) { \n");
		for ( 	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
			if ( iptr->Contents.style != _TAB_FRAME )
				continue;
			else
			{
				bifs_indent(handle);
				if ( pages++ )
					fprintf(handle,"else ");
				fprintf(handle,"if ( state.whichChoice == %u ) { %s.whichChoice = 0; }\n",iptr->Contents.page-1,iptr->Contents.name);
			}
		}
		bifs_indent(handle);
		fprintf(handle,"} }\n%c",0x0022);		
		bifs_close_collection(handle,"url" );
	bifs_close_tag( handle, "Script");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_true_conditional( FILE * handle, struct form_item * iptr )
{
	char	work[1024];
	bifs_open_conditional(handle,iptr->Contents.name);
		bifs_indent(handle);
		fprintf(handle,"REPLACE VALUE_%s.whichChoice BY 1\n",iptr->Contents.name);
	bifs_close_conditional(handle);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_false_conditional( FILE * handle, struct form_item * iptr )
{
	char	work[1024];
	bifs_open_conditional(handle,iptr->Contents.name);
		bifs_indent(handle);
		fprintf(handle,"REPLACE VALUE_%s.whichChoice BY 0\n",iptr->Contents.name);
	bifs_close_conditional(handle);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	bifs_tab_frame( FILE * h, struct form_item * iptr, struct form_control * fptr, int started )
{
	struct	form_item * wptr;
	char	work[1024];
	int	fh = guifontsize(iptr->Contents.font);
	int	fw = (fh & 0x00FF);
	fh >>= 8;
	fh &= 0x00FF;
	if (!( started++))
	{
		bifs_comment(h,"tab page system");
		bifs_toggle_page( h, fptr );
		bifs_open_switch(h,fptr->identifier,0);
	}
	bifs_comment(h,"tab page frame");
	bifs_tag(h,"Transform2D");
		mpeg_translation( work, 
				iptr->Contents.x, 
				iptr->Contents.y+(fh+8), 
				iptr->Contents.w, iptr->Contents.h-(fh+8) );
		bifs_field(h,"translation",work);
		bifs_collection(h,"children");
			bifs_relief( h, 
				iptr->Contents.x,
				iptr->Contents.y+(fh+8),
				iptr->Contents.w,
				iptr->Contents.h-(fh+8), 
				_OUTSET_FRAME,
				iptr->Contents.name);
	return(started);
}

/*	-----------------------------------------------------------------------	*/
/*				b i f s _ e d i t				*/
/*	-----------------------------------------------------------------------	*/
/*	this function generates all the bifs code required for the edit widget.	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_edit( FILE * handle, int x, int y, int w, int h, struct form_item * iptr )
{
	char *	work[1024];
	char *	framename[1024];
	sprintf(framename,"%s%s",_FRAME_PREFIX,iptr->Contents.name);
	// --------------------------------
	// generate translation to position
	// --------------------------------
	bifs_tag(handle,"Transform2D");
	bifs_collection(handle,"children");

	bifs_touch_sensor(handle,iptr->Contents.name);

	bifs_comment(handle,"edit frame");
	bifs_relief( handle, x,y,w,h, _EDIT_FRAME, framename);

	bifs_comment(handle,"edit text");
	bifs_text_value(handle, x+1,y+1,w-2,h-2, iptr->Contents.name, standard_black, _A_LEFT,iptr->Contents.name );

	if ( BC.keySensor )
	{
		bifs_key_sensor(handle, iptr->Contents.name );
		bifs_edit_focus( handle, iptr );
		// bifs_edit_conditional( handle, iptr );
	}
	else if ( BC.stringSensor )
	{
		bifs_string_sensor( handle, iptr->Contents.name );
		bifs_edit_conditional( handle, iptr );
	}
	
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_window( FILE * handle, int x, int y, int w, int h, char * message, char * name, struct form_item * iptr )
{
	int	fh = guifontsize(iptr->Contents.font);
	int	fw = (fh & 0x00FF);
	fh >>= 8;
	fh &= 0x00FF;
	bifs_comment(handle,"window frame");
	bifs_relief( handle, x,y,w,h, _WINDOW_FRAME, (char *) 0);
	bifs_comment(handle,"window title bar");
	bifs_filzone( handle, x+2,y+2,w-4,fh, standard_title, (char *) 0);
	bifs_comment(handle,"window title message");
	bifs_text( handle, x+fw,y+2,w-(fw*2),fh, message, standard_text, (char *) 0,_A_LEFT);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_scrollframe( FILE * handle, struct form_item * iptr )
{
	int x;
	int y; 
	int w;
	int h;
	x = iptr->Contents.x;
	y = iptr->Contents.y;
	w = iptr->Contents.w;
	h = iptr->Contents.h;
	bifs_tag(handle,"Transform2D");
	bifs_collection(handle,"children");
	bifs_comment(handle,"scroll event sensor");
	bifs_touch_sensor(handle,iptr->Contents.name);
	bifs_comment(handle,"scroll bar tray");
	bifs_relief( handle, x,y,w,h, _SCROLL_FRAME, (char *) 0);
	if ( w > h )
	{
		bifs_comment(handle,"scroll left button");
		bifs_relief( handle, x+1,y+1,h-2,h-2, _BUTTON_FRAME, (char *) 0);
		bifs_comment(handle,"scroll slider");
		bifs_relief( handle, x+w-(h-1),y+1,h-2,h-2, _BUTTON_FRAME, (char *) 0);
		bifs_comment(handle,"scroll right button");
		bifs_relief( handle, x+h, y+1,w-(h*2),h-2, _BUTTON_FRAME, (char *) 0);
	}
	else
	{
		bifs_comment(handle,"scroll top button");
		bifs_relief( handle, x+1,y+1,w-2,w-2, _BUTTON_FRAME, (char *) 0);
		bifs_comment(handle,"scroll slider");
		bifs_relief( handle, x+1,y+h-(w-1),w-2,w-2, _BUTTON_FRAME, (char *) 0);
		bifs_comment(handle,"scroll bottom button");
		bifs_relief( handle, x+1, y+w,w-2,h-(w*2), _BUTTON_FRAME, (char *) 0);
	}
	bifs_comment(handle,"scroll event trigger");
	bifs_open_conditional(handle,iptr->Contents.name);
	bifs_close_conditional(handle);
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

/*	-------------------------------------------	*/
/*	  b i f s _ p r o t o _ i n s t a n c e 	*/
/*	-------------------------------------------	*/
void	bifs_proto_instance( FILE * h, struct form_control * fptr, char * iname, int xpos, int ypos )
{
	char	work[1024];
	sprintf(work,"Forms Model : %s",fptr->identifier);
	bifs_comment(h,work);
	bifs_def_tag(h,fptr->identifier,iname);
	bifs_vector_2d_field(h,"atXY",xpos,ypos);
	bifs_close_tag(h,fptr->identifier);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_dataframe( FILE * h, struct form_item * iptr )
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
		bifs_tag(h,"Transform2D");
			mpeg_translation( work, iptr->Contents.x, iptr->Contents.y, Window.w, Window.h );
			mpeg_translation_vector( 
					&Center, 
					iptr->Contents.x+(Window.w/2), 
					iptr->Contents.y+(Window.h/2), BC.width, BC.height );
			bifs_field(h,"translation",work);
			bifs_collection(h,"children");
				bifs_proto_instance(h,ffptr,iptr->Contents.name,Center.x,Center.y);
			bifs_close_collection(h,"children");
		bifs_close_tag(h,"Transform2D");
		return;
	}
}

/*	-----------------------------------------------------------------------	*/
/*				  b i f s _ t a b l e  				*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	bifs_table( FILE * handle, int x, int y, int w, int h, int f, int fg, int bg,
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

	bifs_comment(handle,"table outer frame");
	bifs_draw_relief(handle,x,y,w,h,standard_lolight,zbg,standard_hilight,(char *) 0);

	if (!( options & 0x2000 )) {
		x += 1; y+= 1;
		w -= 2; h -= 2;
		}

	/* Generate black inside liner */
	/* --------------------------- */
	bifs_comment(handle,"table inner frame");
	bifs_draw_relief(handle,x,y,w,h,standard_black,transparent,standard_black,(char *) 0);

	if (!( options & 0x2000 )) {
		x += 1; y+= 1;
		w -= 2; h -= 2;
		}

	/* Establish Titles background fill */
	/* -------------------------------- */
	bifs_comment(handle,"table background");
	bifs_filzone( handle, x,y,w,fh, standard_title,(char *) 0);

	/* check for and perform row-wise zoning */
	/* ------------------------------------- */
	switch ( options & 0x0007 ) {
		case	1 :
		case	3 :
			zbg = (options & 2 ? bg-1 : standard_white-1);
			bifs_comment(handle,"table row zoning");
			for ( r=(fh*2); (r+fh) < h; r+= (fh*2) )
				bifs_filzone(handle, x,y+r,w,fh,zbg,(char *) 0);
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
			bifs_comment(handle,"table titles");
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
					bifs_draw_relief(handle,(lmargin*fw)+x,y-1,relw,fh+1,
						standard_hilight,standard_backwash,standard_lolight,(char *) 0);
					adjust = fh;
					}					
				memcpy( libelle, tptr, tlen );
				libelle[tlen] = 0;
				bifs_text(handle,((lmargin+padd)*fw)+x,y,relw,fh+1,libelle,txfg,(char *) 0,_A_LEFT);
				// PixelFontLat(((lmargin+padd)*fw)+x,y,f,tptr,tlen);

				if ( *(wptr++) != '|' )
					break;
				else	{
					tptr = wptr;
					lmargin += fieldwidth[field];
					/* was X */
					bifs_filzone(handle,(((lmargin*fw)+x)-1),y+adjust,1,h-adjust,dath,(char *) 0);
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
					bifs_comment(handle,"table column zoning");
					for (lmargin=0,field=0; field < fields; field++ ) {
						if ((field+1) == fields)
							tw = (w - lmargin);
						else 	tw = (fieldwidth[field] * fw);
						if (!( field & 1 ))
							bifs_filzone(handle,lmargin+x,y+fh,tw-1,(h-fh),zbg,(char *) 0);
						lmargin += (tw-xh);			
						}
					break;

				case	6 :
				case	7 :
					zbg = (options & 1 ? bg-1 : standard_white-1);
					bifs_comment(handle,"table column zoning");
					for ( nbr=0,r=fh; (r+fh) < h; r+= fh, nbr++ ) {
						for (lmargin=0,field=0; field < fields; field++ ) {
							if ((field+1) == fields)
								tw = (w - lmargin);
							else	tw = (fieldwidth[field] * fw);
							if (!( (field+nbr) & 1 ))
								bifs_filzone(handle,lmargin+x,y+r,tw-1,fh,zbg,(char *) 0);
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
					bifs_comment(handle,"table data cells");
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
/*				b i f s _ f o r m f r a m e			*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_formframe( FILE * h, struct form_item * iptr )
{
	bifs_table( 	h,
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
/*			B I F S _ w i d g e t			*/
/*	---------------------------------------------------	*/
/*	called from the upper level forms production cycle	*/
/*	for the translation of a widget to BiFS.		*/
/*	---------------------------------------------------	*/
void	BIFS_widget( FILE * h, struct form_item * iptr )
{
	struct	form_control * fptr;
	char	work[1024];
	int	isdef;
	int	align;

	if (!( iptr )) 	
		return;
	else if (!( fptr = iptr->parent ))
		return;
	else if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
		return;
	else	isdef = is_named_widget( iptr );

	BC.fontWidth  = guifontsize(iptr->Contents.font);
	BC.fontHeight = (BC.fontWidth >> 8); 
	BC.fontWidth  &= 0x00FF;

	sprintf(work,"Widget : %s.%s",fptr->identifier,iptr->Contents.name);
	bifs_comment(h, work );

	switch (iptr->Contents.style)
	{

	case	_FILL_FRAME	:	//	0
		switch ( iptr->Contents.align )
		{
		case	0	:
		case	1	:
			bifs_comment(h,"visual filzone");
			bifs_filzone( 	
				h,
				iptr->Contents.x, iptr->Contents.y, 
				iptr->Contents.w, iptr->Contents.h, 
				(iptr->Contents.colour & 0x00FF),
				( isdef ? iptr->Contents.name : (char *) 0)
				);
			break;
		case	2	:
		case	3	:
			bifs_comment(h,"visual circle");
			bifs_circle( 	
				h,
				iptr->Contents.x, iptr->Contents.y, 
				iptr->Contents.w, iptr->Contents.h, 
				(iptr->Contents.colour & 0x00FF),
				((iptr->Contents.colour>>8) & 0x00FF),
				( isdef ? iptr->Contents.name : (char *) 0)
				);
			break;
		}
		break;

	case	_EDIT_FRAME	:	//	5
		bifs_edit( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			iptr
			);
		break;
	case	_OUTSET_FRAME	:	//	1
	case	_INSET_FRAME	:	//	2
	case	_RIDGE_FRAME	:	//	3
	case	_GROOVE_FRAME	:	//	4
		bifs_comment(h,"visual frame");
		bifs_relief( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			iptr->Contents.style,
			( isdef ? iptr->Contents.name : (char *) 0)
			);
		break;

	case	_TEXT_FRAME	:	//	6
		bifs_comment(h,"visual text");
		align = (iptr->Contents.align & 0x0007);
		bifs_text(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			iptr->Contents.colour,
			( isdef ? iptr->Contents.name : (char *) 0),
			align
	
			);
		break;
	case	_IMAGE_FRAME	:	//	7
		bifs_comment(h,"visual image");
		bifs_image(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			( isdef ? iptr->Contents.name : (char *) 0)
			);
		break;

	case	_SWITCH_FRAME	:	//	18
		bifs_switch(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			iptr
			);
		break;

	case	_BUTTON_FRAME	:	//	9
		bifs_pushbutton( h, iptr );
		break;

	case	_WINDOW_FRAME	:	//	10
		bifs_window(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			( isdef ? iptr->Contents.name : (char *) 0),
			iptr
			);
		break;

	case	_CHECK_FRAME	:	//	12
		bifs_checkbox(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			iptr
			);
		break;

	case	_SCROLL_FRAME	:	//	16
		bifs_scrollframe( h, iptr );
		break;

	case	_RADIO_FRAME	:	//	13
		if ( isdef )
			sprintf(work,"%s_%u",iptr->Contents.name,iptr);
		bifs_radiobox(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			iptr
			);
		break;

	case	_DATA_FRAME	:

		bifs_dataframe( h, iptr );
		break;

	case	_FORM_FRAME	:	//	15
		bifs_formframe( h, iptr );
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

static	int	od_update_started=0;
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	bifs_start_od_update( FILE * h )
{
	if (!( od_update_started ))
	{
		od_update_started = 1;
		bifs_tag(h,"AT 0");
		bifs_collection(h,"UPDATE OD");
	}
	return(0);
}
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	bifs_close_od_update( FILE * h )
{
	if ( od_update_started )
	{
		bifs_close_collection(h,"update OD");
		bifs_close_tag(h,"AT 0");
		od_update_started = 0;
	}
	return(0);
}

/*	-------------------------------------------	*/
/*	b i f s _ o b j e c t _ d e s c r i p t o r 	*/
/*	-------------------------------------------	*/
/*	adds an object descriptor prior to addition	*/
/*	of scene children to handle images, video	*/
/*	and audio streams as textures in scene.		*/
/*	-------------------------------------------	*/
int	bifs_object_descriptor( FILE * h, char * nptr )
{
	int	result=0;
	bifs_start_od_update( h );
	bifs_tag(h,"ObjectDescriptor");
		bifs_integer_field(h,"objectDescriptorID",(result = ++BC.od));
		bifs_collection(h,"esDescr");
			bifs_tag(h,"ES_Descriptor");
				bifs_integer_field(h,"ES_ID",++BC.es);
				bifs_tag(h,"muxInfo MuxInfo");
					bifs_quoted(h,"fileName", nptr );
				bifs_close_tag(h,"MuxInfo");
			bifs_close_tag(h,"ES_Descriptor");
		bifs_close_collection(h,"esDescr");
	bifs_close_tag(h,"ObjectDescriptor");
	return( result );
}

/*	-------------------------------------------------------------	*/
/*	s t r i n g _ s e n s o r _ o b j e c t _ d e s c r i p t o r 	*/
/*	-------------------------------------------------------------	*/
/*	update of the object descriptor for the string sensor stream	*/
/*	-------------------------------------------------------------	*/
int	string_sensor_object_descriptor( FILE * h )
{
	int	result=0;
	bifs_tag(h,"AT 0");
		bifs_collection(h,"UPDATE OD");
			bifs_tag(h,"ObjectDescriptor");
				bifs_integer_field(h,"objectDescriptorID",(result = BC.StringSensorOD));
				bifs_collection(h,"esDescr");
					string_sensor_es_descriptor(h);
				bifs_close_collection(h,"esDescr");
			bifs_close_tag(h,"ObjectDescriptor");
		bifs_close_collection(h,"update OD");
	bifs_close_tag(h,"AT 0");
	return( result );
}

/*	------------------------------------------------------------	*/
/*	   s t r i n g _ s e n s o r _ e s _ d e s c r i p t o r	*/
/*	------------------------------------------------------------	*/
/*	this function is called from the initial object descriptor	*/
/*	production and also from the initial UPDATE OD description.	*/
/*	------------------------------------------------------------	*/
void	string_sensor_es_descriptor( FILE * h )
{
	bifs_tag(h,"ES_Descriptor");
		bifs_integer_field(h,"ES_ID",BC.StringSensorID);
		bifs_tag(h,"decConfigDescr DecoderConfigDescriptor");
			bifs_field(h,"streamType","10");
			bifs_tag(h,"decSpecificInfo UIConfig");
				bifs_string(h,"deviceName","StringSensor");
			bifs_close_tag(h,"UIConfig");
		bifs_close_tag(h,"DecoderConfigDescriptor");
	bifs_close_tag(h,"ES_Descriptor");
	return;
}

/*	---------------------------------------------------------	*/
/*	 k e y _ s e n s o r _ o b j e c t _ d e s c r i p t o r 	*/
/*	---------------------------------------------------------	*/
/*	update of the object descriptor for the key sensor stream	*/
/*	---------------------------------------------------------	*/
int	key_sensor_object_descriptor( FILE * h )
{
	int	result=0;
	bifs_tag(h,"AT 0");
		bifs_collection(h,"UPDATE OD");
			bifs_tag(h,"ObjectDescriptor");
				bifs_integer_field(h,"objectDescriptorID",(result = BC.KeySensorOD));
				bifs_collection(h,"esDescr");
					key_sensor_es_descriptor(h);
				bifs_close_collection(h,"esDescr");
			bifs_close_tag(h,"ObjectDescriptor");
		bifs_close_collection(h,"update OD");
	bifs_close_tag(h,"AT 0");
	return( result );
}

/*	------------------------------------------------------------	*/
/*		k e y _ s e n s o r _ e s _ d e s c r i p t o r		*/
/*	------------------------------------------------------------	*/
/*	this function is called from the initial object descriptor	*/
/*	productionand also from the initial UPDATE OD description.	*/
/*	------------------------------------------------------------	*/
void	key_sensor_es_descriptor( FILE * h )
{
	bifs_tag(h,"ES_Descriptor");
		bifs_integer_field(h,"ES_ID",BC.KeySensorID);
		bifs_tag(h,"decConfigDescr DecoderConfigDescriptor");
			bifs_field(h,"streamType","10");
			bifs_tag(h,"decSpecificInfo UIConfig");
				bifs_string(h,"deviceName","KeySensor");
			bifs_close_tag(h,"UIConfig");
		bifs_close_tag(h,"DecoderConfigDescriptor");
	bifs_close_tag(h,"ES_Descriptor");
	return;
}

/*	-------------------------------------------	*/
/*		s i n g _ o p e n _ B i F S  		*/
/*	-------------------------------------------	*/
int	sing_open_BIFS( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;

	bifs_comment(h,"Initial Object Descriptors");
	bifs_tag(h,"InitialObjectDescriptor");
		bifs_integer_field(h,"objectDescriptorID",BC.primary);
		bifs_integer_field(h,"audioProfileLevelIndication",BC.AudioLevel);
		bifs_integer_field(h,"visualProfileLevelIndication",BC.VisualLevel);
		bifs_integer_field(h,"sceneProfileLevelIndication",BC.SceneLevel);
		bifs_integer_field(h,"graphicsProfileLevelIndication",BC.GraphicsLevel);
		bifs_integer_field(h,"ODProfileLevelIndication",BC.ODLevel);

		bifs_collection(h,"esDescr");

			/* --------------------------------------- */
			/* Elementary Stream : BiFS Command Stream */
			/* --------------------------------------- */
			bifs_comment(h,"Elementary Stream : Bifs Command Stream");
			bifs_tag(h,"ES_Descriptor");
				bifs_integer_field(h,"ES_ID",++BC.es);
				bifs_tag(h,"decConfigDescr DecoderConfigDescriptor");
					bifs_field(h,"streamType","3");
					bifs_tag(h,"decSpecificInfo BIFSConfig");
						bifs_field(h,"isCommandStream","true");
						bifs_field(h,"pixelMetric","true");
						bifs_integer_field(h,"pixelWidth",BC.width);
						bifs_integer_field(h,"pixelHeight",BC.height);
					bifs_close_tag(h,"BIFSConfig");
				bifs_close_tag(h,"DecoderConfigDescriptor");
			bifs_close_tag(h,"ES_Descriptor");

			/* --------------------------------------- */
			/* Elementary Stream : Object Descriptors  */
			/* --------------------------------------- */
			bifs_comment(h,"Elementary Stream : Object Descriptors");
			bifs_tag(h,"ES_Descriptor");
				bifs_integer_field(h,"ES_ID",++BC.es);
				bifs_tag(h,"decConfigDescr DecoderConfigDescriptor");
					bifs_field(h,"streamType","1");
				bifs_close_tag(h,"DecoderConfigDescriptor");
			bifs_close_tag(h,"ES_Descriptor");

			/* --------------------------------------- */
			/* Elementary Stream : Key Sensor Infos    */
			/* --------------------------------------- */
			if ( BC.keySensor )
			{
				bifs_comment(h,"Elementary Stream : Key Sensor Information");
				key_sensor_es_descriptor(h);
			}
			else if ( BC.stringSensor )
			{
				bifs_comment(h,"Elementary Stream : String Sensor Information");
				string_sensor_es_descriptor(h);
			}


		bifs_close_collection(h,"esDescr");
	bifs_close_tag(h,"InitialObjectDescriptor");

	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	bifs_show_image3d( FILE * h, char * nptr, int od, struct coordinate3d * tl, struct coordinate3d * d )
{
	char	work[1024];

	bifs_tag(h,"Transform");
		mpeg_translation3d( work, tl->x, tl->y, d->x, d->y, tl->z );
		bifs_field(h,"translation",work);

	bifs_collection(h,"children");

	bifs_tag(h,"Shape");

		// ------------------------------
		// generate the widget appearance
		// ------------------------------
		bifs_tag(h,"appearance Appearance");
			bifs_tag(h,"material Material");
				bifs_field(h,"transparency","0");
			bifs_close_tag(h,"Material");
			bifs_tag(h,"texture ImageTexture");
				bifs_od_url( h, nptr, od );
			bifs_close_tag(h,"ImageTexture");

		bifs_close_tag(h,"appearance");

		// ----------------------------
		// generate the widget geometry
		// ----------------------------
		bifs_tag(h,"geometry Box");
			sprintf(work,"%u %u %u",d->x,d->y,d->z);
			bifs_field(h,"size",work);
		bifs_close_tag(h,"Box");

	bifs_close_tag(h,"Shape");

	bifs_close_collection(h,"children");
	bifs_close_tag(h,"Transform2D");

	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	bifs_show_movie3d( FILE * h, char * nptr, int od, struct coordinate3d * tl, struct coordinate3d * d )
{
	char	work[1024];

	bifs_tag(h,"Transform");
		mpeg_translation3d( work, tl->x, tl->y, d->x, d->y, tl->z );
		bifs_field(h,"translation",work);

	bifs_collection(h,"children");

	bifs_tag(h,"Shape");

		// ------------------------------
		// generate the widget appearance
		// ------------------------------
		bifs_tag(h,"appearance Appearance");
			bifs_tag(h,"material Material");
				bifs_field(h,"transparency","0");
			bifs_close_tag(h,"Material");
			bifs_tag(h,"texture MovieTexture");
				bifs_od_url( h, nptr, od );
			bifs_close_tag(h,"MovieTexture");

		bifs_close_tag(h,"appearance");

		// ----------------------------
		// generate the widget geometry
		// ----------------------------
		bifs_tag(h,"geometry Box");
			sprintf(work,"%u %u %u",d->x,d->y,d->z);
			bifs_field(h,"size",work);
		bifs_close_tag(h,"Box");

	bifs_close_tag(h,"Shape");

	bifs_close_collection(h,"children");
	bifs_close_tag(h,"Transform");

	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	bifs_show_audio3d( FILE * h, char * nptr, int od, struct coordinate3d * tl, struct coordinate3d * d )
{
	char	work[1024];

	bifs_tag(h,"Transform");
		mpeg_translation3d( work, tl->x, tl->y, d->x, d->y, tl->z );
		bifs_field(h,"translation",work);

	bifs_collection(h,"children");

	bifs_tag(h,"Sound");
		bifs_tag(h,"source AudioSource");
		bifs_od_url( h, nptr, od );
	bifs_close_tag(h,"Sound");

	bifs_tag(h,"Shape");

		// ------------------------------
		// generate the widget appearance
		// ------------------------------
		bifs_tag(h,"appearance Appearance");
			bifs_tag(h,"material Material");
				bifs_field(h,"transparency","0");
			bifs_close_tag(h,"Material");
		bifs_close_tag(h,"appearance");

		// ----------------------------
		// generate the widget geometry
		// ----------------------------
		bifs_tag(h,"geometry Box");
			sprintf(work,"%u %u %u",d->x,d->y,d->z);
			bifs_field(h,"size",work);
		bifs_close_tag(h,"Box");

	bifs_close_tag(h,"Shape");

	bifs_close_collection(h,"children");
	bifs_close_tag(h,"Transform");

	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	bifs_show_image2d( FILE * h, char * nptr, int od, int w, int hx )
{
	char	work[1024];

	bifs_tag(h,"Shape");

		// ------------------------------
		// generate the widget appearance
		// ------------------------------
		bifs_tag(h,"appearance Appearance");
			bifs_tag(h,"material Material2D");
				bifs_field(h,"filled","true");
			bifs_close_tag(h,"Material2D");
			bifs_tag(h,"texture ImageTexture");
				bifs_od_url( h, nptr, od );
			bifs_close_tag(h,"ImageTexture");

		bifs_close_tag(h,"appearance");

		// ----------------------------
		// generate the widget geometry
		// ----------------------------
		bifs_tag(h,"geometry Rectangle");
			sprintf(work,"%u %u" ,w,hx);
			bifs_field(h,"size",work);
		bifs_close_tag(h,"Rectangle");

	bifs_close_tag(h,"Shape");

	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	bifs_anchor( FILE * h, char * nptr )
{
	if (!( nptr ))
		return(0);
	else if (!( nptr = allocate_string( nptr ) ))
		return(0);
	else if (!( nptr = enforce_extension( nptr, _EXT_MP4 ) ))
		return( 0 );
	else	{
		bifs_tag(h,"Anchor");
			bifs_od_url(h,nptr,0);
		liberate( nptr );
		return(1);
		}
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	bifs_inline_form3d( FILE * h, char * nptr,  struct coordinate3d * tl, struct coordinate3d * d )
{
	char	work[1024];
	if (!( nptr ))
		return(0);
	else if (!( nptr = allocate_string( nptr ) ))
		return(0);
	else if (!( nptr = enforce_extension( nptr, _EXT_MP4 ) ))
		return( 0 );
	else	{
		bifs_tag(h,"Transform");
			mpeg_translation3d( work, tl->x, tl->y,d->x, d->y, tl->z );
			bifs_field(h,"translation",work);

		bifs_collection(h,"children");

		bifs_tag(h,"Inline");
			bifs_od_url(h,nptr,0);
			bifs_close_tag(h,"Inline");

		bifs_close_collection(h,"children");
		bifs_close_tag(h,"Transform");
		liberate( nptr );
		return(0);
		}
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
int	bifs_inline_form2d( FILE * h, char * nptr, int w, int hx )
{
	if (!( nptr ))
		return(0);
	else if (!( nptr = allocate_string( nptr ) ))
		return(0);
	else if (!( nptr = enforce_extension( nptr, _EXT_MP4 ) ))
		return( 0 );
	else	{
		bifs_tag(h,"Inline");
			bifs_od_url(h,nptr,0);
			bifs_close_tag(h,"Inline");
		liberate( nptr );
		return(0);
		}
}


/*	--------------------------------------------	*/
/*	    b i f s _ o p e n _ p r o j e c t		*/
/*	--------------------------------------------	*/
/*	called from the 3d viewer production manager	*/
/*	--------------------------------------------	*/
int	bifs_open_project( FILE * h )
{
	int	status=0;
	return( sing_open_BIFS(h,(struct form_control *) 0) );
}

/*	--------------------------------------------	*/
/*	    b i f s _ s t a r t _ p r o j e c t		*/
/*	--------------------------------------------	*/
/*	called from the 3d viewer production manager	*/
/*	--------------------------------------------	*/
int	bifs_start_project( FILE * h )
{
	bifs_tag(h,"OrderedGroup");
	bifs_collection(h,"children");
	return( 0 );
}

/*	-------------------------------------------	*/
/*		s i n g _ c l o s e _ B i F S 		*/
/*	-------------------------------------------	*/
int	sing_close_BIFS( FILE * h, struct form_control * fptr )
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
	drop_proto_heap();
	return(0);
}

/*	--------------------------------------------	*/
/*	    b i f s _ c l o s e _ p r o j e c t		*
/*	--------------------------------------------	*/
/*	called from the 3d viewer production manager	*/
/*	--------------------------------------------	*/
int	bifs_close_project( FILE * h )
{
	bifs_close_collection(h,"children");
	bifs_close_tag(h,"OrderedGroup");
	sing_close_BIFS( h, (struct form_control *) 0);
	return(0);
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_string_data( FILE * h, char * nptr,char * value )
{
	bifs_indent(h);
	fprintf(h,"field SFString %s %c%s%c\n",nptr,0x0022,value,0x0022);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_integer_data( FILE * h, char * nptr,int value)
{
	bifs_indent(h);
	fprintf(h,"field SFInt32 %s %u\n",nptr,value);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_vector_2d_data( FILE * h, char * nptr,int xvalue,int yvalue)
{
	bifs_indent(h);
	fprintf(h,"field SFVec2f %s %u, %u\n",nptr,xvalue,yvalue);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_vector_3d_data( FILE * h, char * nptr,int xvalue,int yvalue,int zvalue)
{
	bifs_indent(h);
	fprintf(h,"field SFVec3f %s %u, %u, %u\n",nptr,xvalue,yvalue,zvalue);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_string_member( FILE * h, char * prefix, char * nptr, char * value)
{
	char	work[1024];
	sprintf(work,"%s_%s",prefix,nptr);
	bifs_string_data(h,work,value);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_integer_member( FILE * h, char * prefix, char * nptr,int value )
{
	char	work[1024];
	sprintf(work,"%s_%s",prefix,nptr);
	bifs_integer_data(h,work,value);
	return;
}


/*	-------------------------------------------	*/
/*	 b i f s _ p r o t o _ i n t e r f a c e  	*/
/*	-------------------------------------------	*/
void	bifs_proto_interface( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;
	/* forms members */
	bifs_event_in(h,"OnLoseFocus","SFBool");
	bifs_event_out(h,"LoseFocus","SFBool");
	bifs_vector_2d_data(h,"atXY",0,0);
	if ( fptr->pages )
	{
		bifs_integer_data(h,"pageNumber",0);
		bifs_integer_data(h,"pageCount",fptr->pages);
	}
	bifs_integer_data(h,"focusItem",0);
	bifs_integer_data(h,"focusItems",fptr->items);
		/* widget members */
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch (iptr->Contents.style)
		{
		case	_EDIT_FRAME	:
			bifs_string_member(h,"b",iptr->Contents.name,iptr->Contents.name);
			break;
		case	_CHECK_FRAME	:
			bifs_integer_member(h,"v",iptr->Contents.name,0);
			break;
		case	_RADIO_FRAME	:
			bifs_integer_member(h,"v",iptr->Contents.name,0);
			break;
		case	_SWITCH_FRAME	:
			bifs_integer_member(h,"v",iptr->Contents.name,0);
			break;
		case	_SCROLL_FRAME	:
			bifs_integer_member(h,"v",iptr->Contents.name,0);
			bifs_integer_member(h,"m",iptr->Contents.name,0);
			bifs_integer_member(h,"l",iptr->Contents.name,0);
			break;
		case	_PROGRESS_FRAME	:
			bifs_integer_member(h,"v",iptr->Contents.name,0);
			bifs_integer_member(h,"m",iptr->Contents.name,0);
			break;
		}
	}
	return;
}

/*	-------------------------------------------	*/
/*	 b i f s _ p r o t o _ d e f i n i t i o n	*/
/*	-------------------------------------------	*/
void	bifs_ext_proto_definition( FILE * h, struct form_control * fptr )
{
	char* 	extname=(char *) 0;
	char	work[1024];
	struct	form_item * iptr;

	/* test if protos are developed interne */
	/* ------------------------------------ */
	if (!( BC.externProto ))
		return;
	else
	{
		/* extern prototype definition */
		sprintf(work,"EXTERNPROTO %s",fptr->identifier);
		/* prototype field definitions */
		bifs_collection( h, work );
		bifs_proto_interface(h,fptr);
		bifs_close_collection(h,"");
		if (!( extname = allocate_string( fptr->prodname ) ))
			return;
		else if (!( enforce_extension( extname, _EXT_PROTO ) ))
			return;
		else
		{
			fprintf(h," %c%s#%s%c \n",0x0022,extname,fptr->identifier,0x0022);
			liberate( extname );
			return;
		}
	}
}

/*	-------------------------------------------	*/
/*		b i f s _ l o s e _ f o c u s 		*/
/*	-------------------------------------------	*/
int	bifs_lose_focus( FILE * h, struct form_control * fptr )
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
	sprintf(work,"%s%s",_LOSE_PREFIX,fptr->identifier);
	bifs_def_tag(h,"Script",work);

	bifs_indent(h);
	fprintf(h,"eventIn SFBool loseFocus\n");
	bifs_indent(h);
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

			bifs_indent(h);
			fprintf(h,"field SFNode %s%s USE %s%s\n",
				_LOCAL_PREFIX,iptr->Contents.name,
				_FOCUS_PREFIX,iptr->Contents.name);
		}
	}

	bifs_collection(h,"url");

	bifs_indent(h);

	fprintf(h,"%cjavascript:\n",0x0022);

	bifs_tag(h,"function loseFocus(value)");

		bifs_indent(h);
		fprintf(h,"%s%s.onLoseFocus(value);\n",_LOSE_PREFIX,fptr->identifier);

	bifs_close_tag(h,(char *) 0);

	/* ---------------------------------------------------------- */
	/* this function is called on the cascade down to clear focus */
	/* ---------------------------------------------------------- */

	bifs_tag(h,"function onLoseFocus(value)");
	bifs_tag(h,"if ( value )");

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style == _EDIT_FRAME )
		{
			bifs_indent(h);
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
			bifs_indent(h);
			fprintf(h,"%s.%s%s(1);\n",iptr->Contents.name,_LOSE_PREFIX,ffptr->identifier);
		}
	}

	bifs_close_tag(h,(char *) 0);
	bifs_close_tag(h,(char *) 0);

	bifs_indent(h);
	fprintf(h,"%c\n",0x0022);

	bifs_close_collection(h,"url");
	bifs_close_tag(h,"Script");

}

/*	-------------------------------------------	*/
/*		b i f s _ p r o t o _ b o d y 		*/
/*	-------------------------------------------	*/
int	bifs_proto_body( FILE * h, struct form_control * fptr )
{
	int	i;
	int	started=0;
	struct	form_item * iptr;
	
	/* prototype nodes definitions */
	bifs_tag( h,"\0" );
	if ( fptr->first )
	{
		bifs_tag(h,"Transform2D");
		bifs_is_field(h,"center","atXY");
		bifs_collection(h,"children");
		if ( fptr->pages )
		{
			/* --------------------------------- */
			/* display page zero and tab buttons */
			/* --------------------------------- */
			for (	iptr=fptr->first;
				iptr != (struct form_item *) 0;
				iptr = iptr->next )
			{
				if (!( iptr->Contents.page ))
					BIFS_widget( h, iptr );
				else if ( iptr->Contents.style != _TAB_FRAME )
					continue;
				else
				{
					BC.fontWidth  = guifontsize(iptr->Contents.font);
					BC.fontHeight = (BC.fontWidth >> 8); 
					BC.fontWidth  &= 0x00FF;
					bifs_tab_button( h, iptr );
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
						BC.fontWidth  = guifontsize(iptr->Contents.font);
						BC.fontHeight = (BC.fontWidth >> 8); 
						BC.fontWidth  &= 0x00FF;
						started = bifs_tab_frame ( h, iptr, fptr,started );
					}
					else	BIFS_widget( h, iptr );
				}
				bifs_close_collection(h,"children");
				bifs_close_tag(h,"Transform2D");
			}
			if ( started )
			{
				bifs_close_switch(h);
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
					else	bifs_tab_conditional( h, iptr, fptr );
				}
			}
		}
		else
		{
			// ----------------------------------------
			// Generate order group of children widgets 
			// ----------------------------------------
			for (	iptr=fptr->first;
				iptr != (struct form_item *) 0;
				iptr = iptr->next )
			{
				// -----------------------------------------
				// Each widget is an ordered group of shapes
				// -----------------------------------------
				BIFS_widget( h, iptr );
			}
		}

		bifs_lose_focus(h,fptr);

		bifs_close_collection(h,"children");
		bifs_close_tag(h,"Transform2D");

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
				bifs_switch_route( h, iptr );
				break;
			case	_SCROLL_FRAME	:
				bifs_scroll_route( h, iptr );
				break;
			case	_CHECK_FRAME	:
				bifs_check_route( h, iptr );
				break;
			case	_RADIO_FRAME	:
				bifs_radio_route( h, iptr );
				break;
			case	_TAB_FRAME	:
				bifs_tab_route( h, iptr );
				break;
			case	_EDIT_FRAME	:
				bifs_edit_route( h, iptr );
				break;
			}
		}
	}
	bifs_close_tag(h,"\0");
	return(0);
}

/*	-------------------------------------------	*/
/*	 b i f s _ p r o t o _ d e f i n i t i o n	*/
/*	-------------------------------------------	*/
/* 	this function generates the prototype file	*/
/*	that will be referenced by the externproto	*/
/*	instructions for the description of the obj	*/
/*	-------------------------------------------	*/
void	bifs_proto_dependance( FILE * h, struct form_control * fptr )
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
		else if ( BC.externProto )
			bifs_ext_proto_definition( h, ffptr );
		else	bifs_proto_definition( h, ffptr );
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
/*	-----------------------------------------------------------------------	*/
void	bifs_proto_definition( FILE * handle, struct form_control * fptr )
{
	FILE *	h;
	char	work[1024];
	struct	form_item * iptr;
	char *	extname;
	struct window_control Window;


	/* avoid adding double items */
	/* ------------------------- */
	if (!( add_proto_item( fptr->identifier ) ))
		return;
	else	form_Dimensions( &Window, fptr );

	if ( BC.externProto )
	{
		if (!( extname = allocate_string( fptr->prodname ) ))	
			return;
		else if (!( enforce_extension( extname, _EXT_PROTO ) ))
			return;
		else if (!( h = open_production_target(extname,0))) 
		{
			liberate(h);
			return;
		}
	}
	else	h = handle;

	bifs_proto_dependance(h,fptr);

	/* prototype definition */
	sprintf(work,"PROTO %s",fptr->identifier);
	/* prototype field definitions */
	bifs_collection( h, work );
	bifs_proto_interface(h,fptr);
	bifs_close_collection(h,"");

	exchange_mpeg_production( &Window );
	bifs_proto_body(h, fptr );
	exchange_mpeg_production( &Window );

	if ( BC.externProto )
		close_production_target(h,extname);	

	return;
}

/*	-------------------------------------------	*/
/*	      e x p o r t _ B i F S _ f o r m 		*/
/*	-------------------------------------------	*/
int	export_BIFS_form( FILE * h, struct form_control * fptr )
{
	int	i;
	struct	form_item * iptr;

	prepare_Form( fptr );

	BC.od    = BC.es 	  = 0;
	BC.width = 800; BC.height = 600;

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style == _WINDOW_FRAME )
		{
			BC.width = iptr->Contents.w;
			BC.height = iptr->Contents.h;
			break;
		}
	}
	bifs_mpeg_production();
	bifs_input_streams();

	bifs_proto_definition( h, fptr );

	sing_open_BIFS( h, fptr );

	bifs_ext_proto_definition( h, fptr );

	bifs_comment(h,"Initial Scene Graph");
	bifs_tag(h,"OrderedGroup");
	bifs_collection(h,"children");
	bifs_background2d(h,0,(char *) 0);
	bifs_worldinfo(h,"BiFS Text Generated by Sing",fptr->identifier);
	bifs_proto_instance(h,fptr,"This",0,0);
	if ( BC.keySensor == 2 )
	{
		bifs_key_sensor(h,fptr->identifier);
	}
	bifs_close_collection(h,"children");
	bifs_close_tag(h,"OrderedGroup");
	bifs_comment(h,"Scene Route Descriptions");
	if ( BC.keySensor )
	{
		switch ( BC.keySensor )
		{
		case	2	:
			bifs_input_route(h,fptr);
		case	1	:
			bifs_comment(h,"Key Sensor Object Descriptor");
			key_sensor_object_descriptor( h );
		}
	}
	else if ( BC.stringSensor )
	{
		bifs_comment(h,"String Sensor Object Descriptor");
		string_sensor_object_descriptor( h );
	}
	sing_close_BIFS( h, fptr );
	return(0);
}

/*	-------------------------------------------	*/
/*	     e x p o r t _ B i F S _ p a g e 		*/
/*	-------------------------------------------	*/
int	export_BIFS_page( FILE * h, struct form_control * fptr )
{
	return(0);
}


#endif	/* _singBIFS_c */


