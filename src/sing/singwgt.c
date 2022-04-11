#ifndef _singwgt_c
#define _singwgt_c	

#define	_W3C_WIDGET_NAMESPACE "http://www.w3c.org/ns/widgets"
#define	_W3C_WIDGET_WIDTH 128
#define	_W3C_WIDGET_HEIGHT 128
#define	_MPEGU_MANIFEST "urn:mpeg:mpegu:schema:widgets:manifest:2010"

int	w3c_widget_header( FILE * h, char * wname, char * uname )
{
	laser_xml_header( h );
	fprintf(h,"<widget xmlns='%s'\n",_W3C_WIDGET_NAMESPACE);
	fprintf(h,"\txmlns:mw='%s'\n",_MPEGU_MANIFEST);
	fprintf(h,"\tid='%s'\n",uname);
	fprintf(h,"\tversion='%s'\n","2.0 Beta");
	fprintf(h,"\t>\n");
	fprintf(h,"<feature name='%s'/>\n",_MPEGU_MANIFEST);
	return(1);
}

int	w3c_widget_footer( FILE * h )
{
	fprintf(h,"</widget>\n");
	return(1);
}

int	w3c_widget_configuration( char * wname, struct form_control * fptr, int options )
{
	char *	hptr="how to use it";
	char	cname[512];
	char 	uname[512];
	char 	hname[512];
	char *	cptr=cname;
	FILE * h;
	if (!( wname ))
		return( 0 );
	else if (!( fptr ))
		return( 0 );
	else
	{
		strcpy(hname,"http://127.0.0.1");
		sprintf(cname,"%s/%s",wname,"config.xml");
		sprintf(uname,"%s/%s",hname,wname);
		if (!( h = open_production_target( cname, 0 ) ))
			return( 0 );
		else
		{
			w3c_widget_header( h, wname, uname );
			fprintf(h,"<name short='%s'>Sing Generated Widget</name>\n",wname);
			fprintf(h,"<description>%s</description>\n",hptr);
			fprintf(h,"<author href='http://www.prologue.fr' email='sing@prologue.fr'>Sing Widget Production</author>\n");
			fprintf(h,"<icon src='%s.png'/>\n",wname);
			fprintf(h,"<content src='%s'>\n",fptr->prodname);
			fprintf(h,"\t<mw:interfaces>\n");
			fprintf(h,"\t<mw:interface>\n");
			fprintf(h,"\t</mw:interface>\n");
			fprintf(h,"\t</mw:interfaces>\n");
			fprintf(h,"</content>\n");
			fprintf(h,"<license>Copyright (c) 2011 Amenesik / Sologic</license>\n");
			w3c_widget_footer( h );
			close_production_target( h, cname );
			return( 1 );
		}
	}
}

char * 	w3c_widget_directory( struct form_control * fptr ) 
{
	char *	wname;
	if (!( fptr ))
		return( 0 );
	else if (!( wname = fptr->identifier ))
		return( 0 );
	else
	{
		mkdir( wname, 0666 );
		return( wname );
	}
}

int	w3c_zip_package( char * wname )
{
	char	zcmd[1024];
	sprintf(zcmd,"zip %s.wgt %s/*",wname,wname);
	system( zcmd );
	sprintf(zcmd,"rm -r %s",wname);
	system( zcmd );
	return(1);
}

int	w3c_widget_icon( struct form_control * fptr, char * wname )
{
	STDPSUPTR	pptr;
	STDPSUPTR	rptr;
	int	p1;
	int	p2;
	int	w;
	int	h;
	char	iname[512];
	struct	standard_image * iptr;
	if (!(iptr = fptr->image ))
		return(1);
	else if (!( pptr = iptr->storage ))
		return(1);
	else if (!( rptr = allocate_graphic_storage( 0,0,(p1 = _W3C_WIDGET_WIDTH),(p2 = _W3C_WIDGET_HEIGHT) ) ))
		return(0);
	else	
	{
		w = iptr->columns;
		h = iptr->rows;
		sprintf(iname,"%s/icon.png",wname);
		background_pixel_capture( rptr );
		drawimage( 0,0, p1, p2, iptr, 5);
		cancel_pixel_capture(rptr);
		iptr->storage = rptr;
		iptr->columns = p1;
		iptr->rows= p2;
		save_form_image( iname, iptr, 0x0C0, 0 );
		iptr->columns = w;
		iptr->rows= h;
		iptr->storage = pptr;
		liberate_pixel_storage( rptr );
		return(1);
	}
}

int	w3c_widget_package( struct form_control * fptr, int options )
{
	FILE * h;
	char	wform[512];
	char * 	wname;

	if (!( fptr ))
		return( 0 );

	else if (!( wname = w3c_widget_directory( fptr )))
		return( 0 );

	else if (!( w3c_widget_icon( fptr, wname ) ))
		return( 0 );

	sprintf(wform,"%s/%s",wname,fptr->prodname);

	if (!( h = open_production_target( wform, 0 ) ))
		return( 0 );
	{
		laser_export_form( h, fptr );
		close_production_target( h, wform );
		if (!( w3c_widget_configuration( wname, fptr, options ) ))
			return(0);
		else	return( w3c_zip_package( wname ) );
	}

}



#endif  /* _singwgt_c */
	/* ---------- */

