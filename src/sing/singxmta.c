#ifndef	_singXMTA_c
#define	_singXMTA_c

void	xmta_open_tag(FILE * h, char * nptr )
{
	mpeg_indent(h);
	fprintf(h,"<%s",nptr);
	return;
}

void	xmta_tag(FILE * h, char * nptr )
{
	mpeg_indent(h);
	fprintf(h,"<%s>\n",nptr);
	mpeg_enter();
	return;
}

void	xmta_field(FILE * h, char * nptr, char * vptr )
{
	fprintf(h," %s=%c%s%c",nptr,0x0022,vptr,0x0022);
	return;
}

void	xmta_integer_field(FILE * h, char * nptr, int v )
{
	char	value[64];
	sprintf(value,"%u",v);
	xmta_field(h,nptr,value);
	return;
}

void	xmta_close_tag(FILE * h, char * nptr )
{
	mpeg_leave();
	mpeg_indent(h);
	fprintf(h,"</%s>\n",nptr);
	return;
}

void	xmta_end_tag(FILE * h, int mode )
{
	if ( mode )
	{
		fprintf(h,"/>\n");
	}
	else 
	{
		mpeg_enter();
		fprintf(h,">\n");
	}
	return;
}

void	XMTA_decoder_config_descriptor( FILE * h, char * oti, char * st )
{
	xmta_open_tag(h,"DecoderConfigDescriptor");
	xmta_field(h,"objectTypeIndication",oti);
	xmta_field(h,"streamType",st);
	xmta_end_tag(h,0);
	return;
}

int	xmta_object_descriptor( FILE * h, char * nptr )
{
	return(0);
}

/*	-------------------------------------------	*/
/*		s i n g _ o p e n _ X M T A 		*/
/*	-------------------------------------------	*/
int	sing_open_XMTA( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;

	//  -----------------------------------------------------
	//  standard XMTA file header and name space declarations
	//  -----------------------------------------------------
	xmta_open_tag(h,"XMT-A");
		xmta_field(h,"xmlns","http://www.enst.fr/MPEG-4/XMT-A");
		xmta_field(h,"xmlns:xsi","http://www.w3.org/2001/XMLSchema-instance");
		xmta_field(h,"xsi:schemaLocation","http://www.enst.fr/MPEG-4/XMT-A xmt-a.xsd");
	xmta_end_tag(h,0);

	//  -----------------------------------------------------
	//  standard header and initial object descriptor 
	//  -----------------------------------------------------
	xmta_tag(h,"Header");

	xmta_tag(h,"InitialObjectDescriptor");
	xmta_open_tag(h,"Profiles");
		xmta_field(h,"ODProfileLevelIndication","Unspecified");
		xmta_field(h,"sceneProfileLevelIndication","Unspecified");
		xmta_field(h,"graphicsProfileLevelIndication","Unspecified");
		xmta_field(h,"visualProfileLevelIndication","Unspecified");
		xmta_field(h,"audioProfileLevelIndication","Unspecified");
	xmta_end_tag(h,1);

	xmta_tag(h,"Descr");
	xmta_tag(h,"esDescr");
	xmta_tag(h,"ES_Descriptor");
	xmta_tag(h,"decConfigDescr");

	XMTA_decoder_config_descriptor(h,"MPEG4Systems2","SceneDescription");
		xmta_tag(h,"decSpecificInfo");
			xmta_tag(h,"XMTAConfig");
				xmta_open_tag(h,"commandStream");
					xmta_field(h,"pixelMetric","true");
					xmta_end_tag(h,0);
					xmta_open_tag(h,"size");
						xmta_integer_field(h,"pixelWidth",ProductionWindow.w);
						xmta_integer_field(h,"pixelHeight",ProductionWindow.h);
						xmta_end_tag(h,1);
				xmta_close_tag(h,"commandStream");
			xmta_close_tag(h,"XMTAConfig");
		xmta_close_tag(h,"decSpecificInfo");
	xmta_close_tag(h,"DecoderConfigDescriptor");

	xmta_close_tag(h,"decConfigDescr");
	xmta_close_tag(h,"ES_Descriptor");
	xmta_close_tag(h,"esDescr");
	xmta_close_tag(h,"Descr");

	xmta_close_tag(h,"InitialObjectDescriptor");

	if ( fptr )
	{
		//  -----------------------------------------------------
		//  subsequent object descriptors for secondary streams
		//  -----------------------------------------------------
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
			if (!( iptr ))
				break;		
		}
	}

	//  -----------------------------------------------------
	//  end of header and start of body 
	//  -----------------------------------------------------
	xmta_close_tag(h,"Header");

	xmta_tag(h,"Body");
	xmta_tag(h,"Replace");
	xmta_tag(h,"Scene");
	return(0);
}

/*	-------------------------------------------	*/
/*		s i n g _ c l o s e _ X M T A 		*/
/*	-------------------------------------------	*/
int	sing_close_XMTA( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;
	if ( fptr )
	{
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
			if (!( iptr ))
				break;		
		}
	}
	xmta_close_tag(h,"Scene");
	xmta_close_tag(h,"Replace");
	xmta_close_tag(h,"Body");
	xmta_close_tag(h,"XMT-A");
	return(0);
}


int	xmta_show_image2d( FILE * h, char * nptr,int od, int w, int hx )
{
	return(0);
}

int	xmta_show_image3d( FILE * h, char * nptr,int od,  struct coordinate3d * tl, struct coordinate3d * d )
{
	return(0);
}

int	xmta_show_movie3d( FILE * h, char * nptr,int od,  struct coordinate3d * tl, struct coordinate3d * d )
{
	return(0);
}

int	xmta_show_audio3d( FILE * h, char * nptr,int od,  struct coordinate3d * tl, struct coordinate3d * d )
{
	return(0);
}

int	xmta_inline_form2d( FILE * h, char * nptr, int w, int hx )
{
	return(0);
}


int	xmta_inline_form3d( FILE * h, char * nptr,  struct coordinate3d * tl, struct coordinate3d * d )
{
	return(0);
}

/*	--------------------------------------------	*/
/*	    x m t a _ s t a r t _ p r o j e c t		*/
/*	--------------------------------------------	*/
/*	called from the 3d viewer production manager	*/
/*	--------------------------------------------	*/
int	xmta_start_project( FILE * h )
{
	xmta_tag(h,"OrderedGroup");
	xmta_tag(h,"children");
	return( 0 );
}


/*	--------------------------------------------	*/
/*	    x m t a _ o p e n _ p r o j e c t		*
/*	--------------------------------------------	*/
/*	called from the 3d viewer production manager	*/
/*	--------------------------------------------	*/
int	xmta_open_project( FILE * h )
{
	return( sing_open_XMTA(h,(struct form_control *) 0) );
}

/*	--------------------------------------------	*/
/*	    x m t a _ c l o s e _ p r o j e c t		*
/*	--------------------------------------------	*/
/*	called from the 3d viewer production manager	*/
/*	--------------------------------------------	*/
int	xmta_close_project( FILE * h )
{
	xmta_close_tag(h,"children");
	xmta_close_tag(h,"OrderedGroup");
	sing_close_XMTA( h, (struct form_control *) 0 );
	return(0);
}

void	xmta_background( FILE * h, int colour )
{
	char	work[1024];

	mpeg_colour( (colour & 0x00FF) , work);
	xmta_open_tag(h,"Background2D");
	xmta_field(h,"backColor",work);
	xmta_end_tag(h,1);
	return;
}

void	XMTA_widget( FILE * h, struct form_item * iptr )
{
	char	work[1024];

	// --------------------------------
	// generate translation to position
	// --------------------------------

	xmta_open_tag(h,"Transform2D");
		mpeg_translation( work, iptr->Contents.x, iptr->Contents.y,iptr->Contents.w, iptr->Contents.h );
		xmta_field(h,"translation",work);
		xmta_end_tag(h,0);
	xmta_tag(h,"children");

	if (!( is_named_widget( iptr ) ))
		xmta_tag(h,"Shape");
	else
	{
		xmta_open_tag(h,"Shape");
		xmta_field(h,"DEF",iptr->Contents.name);
		xmta_end_tag(h,0);
	}
		// ----------------------------
		// generate the widget geometry
		// ----------------------------
		xmta_tag(h,"geometry");
			xmta_open_tag(h,"Rectangle");
				sprintf(work,"%u %u",iptr->Contents.w,iptr->Contents.h);
				xmta_field(h,"size",work);
				xmta_end_tag(h,1);
		xmta_close_tag(h,"geometry");

		// ------------------------------
		// generate the widget appearance
		// ------------------------------
		mpeg_colour( (iptr->Contents.colour & 0x00FF) , work);
		xmta_tag(h,"appearance");
			xmta_tag(h,"Appearance");
				xmta_tag(h,"material");
					xmta_open_tag(h,"Material2D");
						xmta_field(h,"emissiveColor",work);
						xmta_field(h,"filled","true");
						xmta_end_tag(h,1);
				xmta_close_tag(h,"material");
			xmta_close_tag(h,"Appearance");
		xmta_close_tag(h,"appearance");

	xmta_close_tag(h,"Shape");

	xmta_close_tag(h,"children");
	xmta_close_tag(h,"Transform2D");

	// xmta_close_tag(h,"children");
	// xmta_close_tag(h,"OrderedGroup");

	return;
}

/*	-------------------------------------------	*/
/*		s i n g _ X M T A _ f o r m 		*/
/*	-------------------------------------------	*/
int	export_XMTA_form( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;
	sing_open_XMTA( h, fptr );

	if ( fptr->first )
	{
		// ----------------------------------------
		// Generate order group of children widgets 
		// ----------------------------------------
		xmta_tag(h,"OrderedGroup");
		xmta_tag(h,"children");
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
			// -----------------------------------------
			// Each widget is an ordered group of shapes
			// -----------------------------------------
			XMTA_widget( h, iptr );
		}
		xmta_close_tag(h,"children");
		xmta_close_tag(h,"OrderedGroup");
	}
	sing_close_XMTA( h, fptr );
	return(0);
}

/*	-------------------------------------------	*/
/*		s i n g _ X M T A _ p a g e 		*/
/*	-------------------------------------------	*/
int	export_XMTA_page( FILE * h, struct form_control * fptr )
{
	return(0);
}


#endif	/* _singXMTA_c */


