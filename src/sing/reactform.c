#ifndef _reactform_c
#define _reactform_c

public  struct forms_method * detect_forms_method( struct form_control * fptr, char * nptr );
private	int	export_implicit_style(FILE * f, struct form_item * iptr, int wh, int fh, char * postfix );
private	void	react_js_element( FILE * h, struct form_item * iptr );
private	int	export_widget_dimensions( FILE * f, struct form_item * iptr, struct form_item * wptr, char * postfix );
private	void	react_configuration( struct form_control * fptr );
private	int	react_jsx_configuration( struct form_control * fptr );
private	void	react_select_options(FILE *h, struct form_item * iptr);
private	void	export_nested_style( FILE * h);
private	void	export_nested_script( FILE * h);

private	char * 	react_user() { return((char *) 0); }
private	char * 	react_pass() { return((char *) 0); }

private	char *	special_methods[] = { "generatejsx", "generatejs", "reactwillzoom","reactwillstretch",(char *) 0 };

private	int	generate_jsx=0;
private	int	debug_data_transfer=1;
private	int	debug_ajax_transfer=1;
private	int	generate_visual_base_classes=0;
private	int	generate_visual_frame=0;

/*	-----------------------------		*/
/*	r e a c t _ w i d g e t _ i d		*/
/*	-----------------------------		*/
private	char	ReactWidgetId[4096];
private	char *	react_widget_id( struct form_item * iptr )
{
	sprintf(ReactWidgetId,"%s%s",iptr->parent->identifier,iptr->Contents.name);
	return( ReactWidgetId );
}

/*	-----------------------		*/
/*	is_react_special_method		*/
/*	-----------------------		*/
private	int	is_react_special_method( char * sptr )
{
	int	i;
	for ( i=0; special_methods[i] != (char *) 0; i++ )
		if (!( strcmp( special_methods[i], sptr ) ))
			return(1);

	if (!( strncasecmp( sptr, "AJAXPHP:", 8 ) ))
		return(1);
	else	return( 0 );
}

/*	--------------------------	*/
/*	 r e a c t _ p a y l o a d	*/
/*	--------------------------	*/
public  char *  react_payload_value( struct form_item * iptr )
{
        struct  form_control * fptr;
        if (!( fptr = iptr->parent ))
                return( iptr->Contents.payload );
        else if (!( fptr->formflags & _INTERNATIONAL ))
                return( iptr->Contents.payload );
        else if (!( iptr->Contents.payload ))
                return( iptr->Contents.messages[ fptr->natlang ] );
        else    return( iptr->Contents.payload );
}

private	char 	payload_buffer[4096];

public  char *  react_payload( struct form_item * iptr )
{
	char *	payload;
	if (!( payload = react_payload_value( iptr )))
		sprintf(payload_buffer,"%c%c",__QUOTE,__QUOTE);
	else if ( *payload != '$' )
		sprintf(payload_buffer,"%c%s%c",__QUOTE,payload,__QUOTE);
	else if ( generate_jsx )
		sprintf(payload_buffer,"{%s}",(payload+1));
	else	sprintf(payload_buffer,"%s",(payload+1));
	return( payload_buffer );
}

public  char *  react_payload_format( struct form_item * iptr )
{
	char *	payload;
	if (!( method_is_valid(payload = iptr->Contents.format) ))
		sprintf(payload_buffer,"%c%c",__QUOTE,__QUOTE);
	else if ( *payload != '$' )
		sprintf(payload_buffer,"%c%s%c",__QUOTE,payload,__QUOTE);
	else if ( generate_jsx )
		sprintf(payload_buffer,"{%s}",(payload+1));
	else	sprintf(payload_buffer,"%s",(payload+1));
	return( payload_buffer );
}

/*	-----------------	*/
/*	react_bind_method	*/
/*	-----------------	*/
private	void	react_bind_method(FILE * h, char * name, char * extra )
{
	fprintf(h,"\t\tthis.%s%s = this.%s%s.bind(this);\n",name,extra,name,extra);
	return;
}

/*	---------------------	*/
/*	r e a c t _ c l a s s	*/
/*	---------------------	*/
/*	must start with upper	*/
/*	class first letter.	*/
/*	---------------------	*/
private	void	react_class( FILE * h, char * nptr, char * bptr )
{
	int	c;
	c = *(nptr++);
	if ((c >= 'a') && (c <= 'z')) c = ((c - 'a') + 'A');
	fprintf(h,"class %c%s extends %s\n{\n",c,nptr,bptr);
	return;
}

/*	-----------------------------------	*/
/*	e x p a n d _ a j a x _ m e t h o d	*/
/*	-----------------------------------	*/
private	void	expand_ajax_method(FILE * h, struct form_item * iptr, char * method )
{
	/* ------------------------------------- */
	/* TODO: Expand this better using parser */
	/* ------------------------------------- */
	fprintf(h,"%s",method);
	return;
}

/*	-------------------------------------	*/
/*	e x p a n d _ r e a c t _ m e t h o d	*/
/*	-------------------------------------	*/
private	void	expand_react_method(FILE * h, struct form_item * iptr, char * method )
{
	/* ------------------------------------- */
	/* TODO: Expand this better using parser */
	/* ------------------------------------- */
	fprintf(h,"%s",method);
	return;
}

/*	-----------------------------------------------	*/
/*	i n l i n e _ r e a c t _ c o n s t r u c t o r	*/
/*	-----------------------------------------------	*/
private	void	inline_react_constructor(FILE * h, struct form_item * iptr )
{
	if (!( method_is_valid( iptr->Contents.events->on_create ) ))
       		return;
	else
	{
		expand_react_method(h,iptr,iptr->Contents.events->on_create );
		return;
	}
}

/*	---------------------------------	*/
/*	i n l i n e _ r e a c t _ s h o w	*/
/*	---------------------------------	*/
private	void	inline_react_show(FILE * h, struct form_item * iptr )
{
	if (!( method_is_valid( iptr->Contents.events->on_show ) ))
       		return;
	else
	{
		expand_react_method(h,iptr,iptr->Contents.events->on_show );
		return;
	}
}

/*	-------------------------------------------	*/
/*	i n l i n e _ r e a c t _ g e t _ f o c u s 	*/
/*	-------------------------------------------	*/
private	void	inline_react_get_focus(FILE * h, struct form_item * iptr )
{
	if (!( method_is_valid( iptr->Contents.events->on_get_focus ) ))
       		return;
	else
	{
		expand_react_method(h,iptr,iptr->Contents.events->on_get_focus );
		return;
	}
}

/*	---------------------------------------------	*/
/*	i n l i n e _ r e a c t _ l o s e _ f o c u s 	*/
/*	---------------------------------------------	*/
private	void	inline_react_lose_focus(FILE * h, struct form_item * iptr )
{
	if (!( method_is_valid( iptr->Contents.events->on_lose_focus ) ))
       		return;
	else
	{
		expand_react_method(h,iptr,iptr->Contents.events->on_lose_focus );
		return;
	}
}

/*	-----------------------------------	*/
/*	i n l i n e _ r e a c t _ e v e n t 	*/
/*	-----------------------------------	*/
private	void	inline_react_event(FILE * h, struct form_item * iptr )
{
	if (!( method_is_valid( iptr->Contents.events->on_event ) ))
       		return;
	else
	{
		expand_react_method(h,iptr,iptr->Contents.events->on_event );
		return;
	}
}

/*	---------------------------------	*/
/*	i n l i n e _ r e a c t _ h i d e 	*/
/*	---------------------------------	*/
private	void	inline_react_hide(FILE * h, struct form_item * iptr )
{
	if (!( method_is_valid( iptr->Contents.events->on_hide ) ))
       		return;
	else
	{
		expand_react_method(h,iptr,iptr->Contents.events->on_hide );
		return;
	}
}

/*	---------------------------------------------	*/
/*	e x p o r t _ r e a c t _ d e s t r u c t o r 	*/
/*	---------------------------------------------	*/
public	void	export_react_destructor(FILE * h, struct form_item * iptr)
{
	if (!( method_is_valid( iptr->Contents.events->on_remove ) ))
       		return;
	else
	{
		fprintf(h,"\tcomponentWillUnmount()\n\t{\n");
		expand_react_method(h,iptr,iptr->Contents.events->on_remove );
		fprintf(h,"\t}\n");
		return;
	}
} 

/*	------------------------	*/
/*	export_react_data_object	*/
/*	------------------------	*/
private	void	export_react_data_object(FILE * h, struct form_item * iptr)
{
	struct  data_control *  dptr=(struct data_control *) 0;
	int                     i;
	int			fields;
	fprintf(h,"{"); 
	fprintf(h,"\n\t\t\t%s : \"%s\",","error","0");
	fprintf(h,"\n\t\t\t%s : \"%s\",","question","");
	fprintf(h,"\n\t\t\t%s : \"%s\"","response","");
        if (((dptr = iptr->Contents.extra ) != (struct data_control *) 0)
        &&  (( fields = dptr->indexfields + dptr->datafields ) != 0))
		for ( i=0; i < fields; i++ )
			fprintf(h,",\n\t\t\t%s : \"%s\"",dptr->name[i],dptr->name[i]);
	fprintf(h,"\n\t\t}");
	return;
}

/*	--------------------	*/
/*	A J A X : Processing 	*/
/*	--------------------	*/
public	void	export_react_ajax_button( FILE * h, struct form_item * iptr )
{
	fprintf(h,"\t%sAjax(request,message,action)\n\t{\n",iptr->Contents.name);
	fprintf(h,"\t\t// AJAX Request to Back End Data Source \n");
	fprintf(h,"\t\tvar parent = this;\n");
	fprintf(h,"\t\tvar req = new XMLHttpRequest();\n");
	fprintf(h,"\t\treq.open('post',request);\n");
	fprintf(h,"\t\treq.onreadystatechange = function() {\n");
	fprintf(h,"\t\t\tif ( req.readyState === 4 ) {\n");
	fprintf(h,"\t\t\t\tif ( req.status === 200 ) {\n");
	if ( debug_ajax_transfer )
		fprintf(h,"\t\t\t\t\talert(req.responseText);\n");
	fprintf(h,"\t\t\t\t\tparent.setState({%sError:req.status});\n",iptr->Contents.name);
	fprintf(h,"\t\t\t\t\tif ( action != null ) { action(JSON.parse(req.responseText)); }\n");
	fprintf(h,"\t\t\t\t} else { parent.state.%sError = req.status; }\n",iptr->Contents.name);
	fprintf(h,"\t\t\t}\n");
	fprintf(h,"\t\t}\n");
	fprintf(h,"\t\treq.send(JSON.stringify(message));\n");
	fprintf(h,"\t\treturn(false);\n");
	fprintf(h,"\t}\n");
}

/*	-----------------------------------------------------------------	*/
/*	e x p o r t _ r e a c t _ d a t a b a s e _ c o n s t r u c t o r 	*/
/*	-----------------------------------------------------------------	*/
public	void	export_react_database_constructor(FILE * h, struct form_item * iptr )
{
	char 	*		classname;

	fprintf(h,"\tconstructor(props)\n\t{\n");
	fprintf(h,"\t\tsuper(props);\n");
	fprintf(h,"\t\tthis.notify = props.notify;\n");

	/* -------------------------------- */
	/* define the database table fields */
	/* -------------------------------- */
	fprintf(h,"\t\tthis.state = ");
	export_react_data_object(h, iptr);
	fprintf(h,";\n");

	/* --------------------------- */
	/* overload the request method */
	/* --------------------------- */
	if (( classname = resolve_widget_file_class( iptr )) != (char *) 0)
	{
		fprintf(h,"\t\t// AJAX Request to Back End Data Source \n");
		fprintf(h,"\t\tthis.onrequest = function(action)\n\t\t{\n");
		fprintf(h,"\t\t\tvar parent = this;\n");
		fprintf(h,"\t\t\tvar req = new XMLHttpRequest();\n");
		fprintf(h,"\t\t\treq.open('post','ajax_%s.php?action='+action);\n",classname);
		fprintf(h,"\t\t\treq.onreadystatechange = function() {\n");
		fprintf(h,"\t\t\t\tif ( req.readyState === 4 ) {\n");
		fprintf(h,"\t\t\t\t\tif ( req.status === 200 ) {\n");
		if ( debug_data_transfer )
			fprintf(h,"\t\t\t\t\t\talert(req.responseText);\n");
		fprintf(h,"\t\t\t\t\t\tparent.state = JSON.parse(req.responseText);\n");
		fprintf(h,"\t\t\t\t\t} else { parent.state.error = req.status; }\n");
		fprintf(h,"\t\t\t\t\tparent.notify(parent.state);\n");
		fprintf(h,"\t\t\t\t}\n");
		fprintf(h,"\t\t\t}\n");
		fprintf(h,"\t\t\treq.send(JSON.stringify(this.state));\n");
		fprintf(h,"\t\t\treturn(false);\n");
		fprintf(h,"\t\t};\n");
	}

	fprintf(h,"\t}\n");
	return;
}

/*	-----------------------------------------------		*/
/*	e x p o r t _ r e a c t _ c o n s t r u c t o r 	*/
/*	-----------------------------------------------		*/
public	void	export_react_constructor(FILE * h, struct form_item * iptr)
{
	if (!( method_is_valid( iptr->Contents.events->on_create ) ))
       		return;
	else
	{
		fprintf(h,"\tconstructor(props)\n\t{\n");
		fprintf(h,"\t\tsuper(props);\n");
		expand_react_method(h,iptr,iptr->Contents.events->on_create );
		fprintf(h,"\t}\n");
		return;
	}
} 

/*	-------------------------------------	*/
/*	e x p o r t _ r e a c t _ w i d g e t 	*/
/*	-------------------------------------	*/
public  void    export_react_widget( FILE * h, struct form_control * fptr, struct form_item * iptr )
{
	char *	classname;

	switch (iptr->Contents.style & _FRAME_TYPE)
	{
	case	_DATA_FRAME	:
		/* --------------------------------------- */
		/* can only handle database tables for now */
		/* --------------------------------------- */
		if (!( classname = resolve_widget_file_class( iptr )))
			break;
		else
		{
			react_class(h, classname, "VisualDataBaseTable" );
			export_react_database_constructor(h,iptr);
			export_react_destructor(h,iptr);
			fprintf(h,"}\n");
		}
		break;

	}
}

/*	---------------------------	*/
/*	r e a c t _ c s s _ f o n t	*/
/*	---------------------------	*/
private	void	react_css_font( FILE * o, int h, int wh, int fh, char * align, int option )
{
	int	x;
	float	f;
	fprintf(o,"font-size: %upx;",fh);
	if ( align )
		fprintf(o,"text-align: %s;",align);
	fprintf(o,"overflow: hidden;");
	if (( h > 0 ) && ( wh > 0 ) && ( h > fh ))
	{
		if ((x = ((h - fh) / 2)) > (fh/2))
		{
			f = (((float) x * 100.0) / (float) wh );
			fprintf(o,"padding-top: %03.3f%;",f);
		}
	}
	return;
}


/*	-------------------------	*/
/*	f l o a t _ p e r c e n t	*/
/*	-------------------------	*/
private	void	float_percent( char * result, int v, int w )
{
	float	fv;
	float	fw;
	fv = (float) v;
	fw = (float) w;
	fv = ((fv/fw)*100.0);
	sprintf(result,"%03.3f%%",fv);
	return;
}

/*	-------------------------------		*/
/*	e x p o r t _ r e a c t _ c s s 	*/
/*	-------------------------------		*/
/*	generates the CSS style classes		*/
/*	for each of the individual form		*/
/*	widgets. This may be "as is" or		*/
/*	may be proportional to a window		*/
/*	that has declared full screen.		*/
/*	-------------------------------		*/
private	int	export_react_css( FILE * f, struct form_item * iptr, struct form_item * wptr, char * postfix )
{
	int	wh=0;
	int	fh;
	int	fw;

       	fw = guifontsize(iptr->Contents.font);
       	fh = (fw >> 8); fw &= 0x00FF;

	/* ------------------------------------------- */
	/* generate the primary widget area dimensions */
	/* ------------------------------------------- */
	wh = export_widget_dimensions( f, iptr, wptr, postfix );

	/* -------------------------------------------------- */
	/* Generate the widget specific implicite style class */
	/* if no explicite style class has been declared here */
	/* -------------------------------------------------- */
	if (!( method_is_valid ( iptr->Contents.stylesheet ) ))
		return( export_implicit_style( f, iptr, wh, fh, postfix ) );
	else	return(0);
}

/*	-----------------------		*/
/*	export_table_dimensions		*/
/*	-----------------------		*/
private	int	export_table_dimensions( FILE * f, struct form_item * iptr, struct form_item * wptr, int i, int offset, int width, char * postfix )
{
	int	fh;
	int	fw;
	char	x[64];
	char 	y[64];
	char	w[64];
	char	h[64];
       	fw = guifontsize(iptr->Contents.font);
       	fh = (fw >> 8); fw &= 0x00FF;
	sprintf(x,"%upx",iptr->Contents.x+offset);
	sprintf(y,"%upx",iptr->Contents.y);
	sprintf(w,"%upx",width);
	sprintf(h,"%upx",fh);
	fprintf(f,"#%s%s%u {",react_widget_id(iptr),postfix,i+1);
	fprintf(f,"position: absolute; top: %s; left: %s;",y,x);
	fprintf(f,"width: %s; height:%s; ",w,h);
	if (!( strcmp( postfix,"th" ) ))
		fprintf(f,"text-align: center;");
	fprintf(f,"}\n");
	return(width);
}

/*	---------------		*/
/*	react_table_css		*/
/*	---------------		*/
private	int	react_table_css( FILE * f, struct form_item * iptr, struct form_item * wptr )
{
        int     linelength, nblines,i,fields,posit;
	int	offset=0;
        int     fieldwidth[_MAX_FORM_FIELDS];
        if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
                return;
        calculate_edit_size( &iptr->Contents );
        calculate_form_lines( iptr, &linelength, &nblines );

	/* --------------- */
	/* the table frame */
	/* --------------- */
	export_react_css( f, iptr, wptr, "" );

        if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return(0);

	/* --------------- */
	/* the table title */
	/* --------------- */
	for ( offset=0,i=0; i < fields; i++)
		offset += export_table_dimensions(f, iptr, wptr, i, offset, fieldwidth[i], "th" );


	/* --------------- */
	/* the table cells */
	/* --------------- */
	for ( offset=0, i=0; i < fields; i++)
		offset += export_table_dimensions(f, iptr, wptr, i, offset, fieldwidth[i], "td" );

	return(0);
}

/*	------------------------	*/
/*	export_widget_dimensions	*/
/*	------------------------	*/
private	int	export_widget_dimensions( FILE * f, struct form_item * iptr, struct form_item * wptr, char * postfix )
{
	int	wh=0;
	int	fh;
	int	fw;
	int	fg;
	int	bg;
	char	x[64];
	char 	y[64];
	char	w[64];
	char	h[64];
	int	zoomx=0;
	int	zoomy=0;
	int	zoomw=0;
	int	zoomh=0;
	struct	forms_method * mptr;

       	fw = guifontsize(iptr->Contents.font);
       	fh = (fw >> 8); fw &= 0x00FF;
	/* ---------------------------------------------------------------------------------- */
	/* if a window has been provided then it is the reference for percentage calculations */
	/* ---------------------------------------------------------------------------------- */
	if ( wptr )
	{
		wh = wptr->Contents.h;
		
		/* -------------------------------------- */
		/* detect the zoom all to new size option */
		/* -------------------------------------- */
		if ((mptr = detect_forms_method( iptr->parent, "reactwillzoom" )) != (struct forms_method *) 0)
			zoomx = zoomy = zoomh = zoomw = 1;

		/* --------------------------------------------- */
		/* else detect the new slide and stretch options */
		/* --------------------------------------------- */
		else if ((mptr = detect_forms_method( iptr->parent, "reactwillstretch" )) != (struct forms_method *) 0)
		{
			zoomx = (iptr->Contents.wResize & 2);
			zoomy = (iptr->Contents.hResize & 2);
			zoomw = (iptr->Contents.wResize & 1);
			zoomh = (iptr->Contents.hResize & 1);
		}
		else
		{
			/* ---------------------------- */
			/* otherwise the standard means */
			/* ---------------------------- */
			zoomx = (iptr->Contents.wResize & 1);
			zoomy = (iptr->Contents.hResize & 1);
			zoomw = (iptr->Contents.wResize & 1);
			zoomh = (iptr->Contents.hResize & 1);
		}

		/* ------------------------------------- */
		/* calculate the position and dimensions */
		/* ------------------------------------- */
		switch (iptr->Contents.style & _FRAME_TYPE)
		{
		case	_WINDOW_FRAME	: 
			strcpy(x,"0px"); strcpy(y,"0px"); strcpy(w,"100%"); strcpy(h,"100%");
			break;
		case	_BUTTON_FRAME	: 
			if ( zoomx )
				float_percent(x,iptr->Contents.x,wptr->Contents.w);
			else	sprintf(x,"%upx",iptr->Contents.x);
			if ( zoomy )
				float_percent(y,iptr->Contents.y,wptr->Contents.h);
			else	sprintf(y,"%upx",iptr->Contents.y);
			if ( zoomw )
				float_percent(w,iptr->Contents.w,wptr->Contents.w);
			else	sprintf(w,"%upx",iptr->Contents.w);
			if ( zoomh )
				float_percent(h,iptr->Contents.h,wptr->Contents.h);
			else	sprintf(h,"%upx",iptr->Contents.h);
			break;
		case	_FORM_FRAME	: 
		case	_EDIT_FRAME	: 
			if ( zoomx )
				float_percent(x,iptr->Contents.x,wptr->Contents.w);
			else	sprintf(x,"%upx",iptr->Contents.x);
			if ( zoomy )
				float_percent(y,iptr->Contents.y,wptr->Contents.h);
			else	sprintf(y,"%upx",iptr->Contents.y);
			if ( zoomw )
				float_percent(w,iptr->Contents.w,wptr->Contents.w);
			else	sprintf(w,"%upx",iptr->Contents.w);
			if ( zoomh )
				float_percent(h,iptr->Contents.h,wptr->Contents.h);
			else	sprintf(h,"%upx",iptr->Contents.h);
			break;
		case	_IMAGE_FRAME	: 
			if ( zoomx )
				float_percent(x,iptr->Contents.x,wptr->Contents.w);
			else	sprintf(x,"%upx",iptr->Contents.x);
			if ( zoomy )
				float_percent(y,iptr->Contents.y,wptr->Contents.h);
			else	sprintf(y,"%upx",iptr->Contents.y);
			if ( zoomw )
				float_percent(w,iptr->Contents.w,wptr->Contents.w);
			else	sprintf(w,"%upx",iptr->Contents.w);
			if ( zoomh )
				float_percent(h,iptr->Contents.h,wptr->Contents.h);
			else	sprintf(h,"%upx",iptr->Contents.h);
			break;
		default			:
			if ( zoomx )
				float_percent(x,iptr->Contents.x,wptr->Contents.w);
			else	sprintf(x,"%upx",iptr->Contents.x);
			if ( zoomy )
				float_percent(y,iptr->Contents.y,wptr->Contents.h);
			else	sprintf(y,"%upx",iptr->Contents.y);
			if ( zoomw )
				float_percent(w,iptr->Contents.w,wptr->Contents.w);
			else	sprintf(w,"%upx",iptr->Contents.w);
			if ( zoomh )
				float_percent(h,iptr->Contents.h,wptr->Contents.h);
			else	sprintf(h,"%upx",iptr->Contents.h);
			break;
		}
	}
	else
	{
		/* ----------------------------------- */
		/* prepare the position and dimensions */
		/* ----------------------------------- */
		switch (iptr->Contents.style & _FRAME_TYPE)
		{
		case	_FORM_FRAME	: 
		case	_EDIT_FRAME	: 
			sprintf(x,"%upx",iptr->Contents.x);
			sprintf(y,"%upx",iptr->Contents.y);
			sprintf(w,"%upx",iptr->Contents.w);
			sprintf(h,"%upx",iptr->Contents.h);
			break;
		case	_IMAGE_FRAME	: 
			sprintf(x,"%upx",iptr->Contents.x);
			sprintf(y,"%upx",iptr->Contents.y);
			sprintf(w,"%upx",iptr->Contents.w+10);
			sprintf(h,"%upx",iptr->Contents.h+10);
			break;
		default	:
			sprintf(x,"%upx",iptr->Contents.x);
			sprintf(y,"%upx",iptr->Contents.y);
			sprintf(w,"%upx",iptr->Contents.w);
			sprintf(h,"%upx",iptr->Contents.h);
		}
	}

	/* ------------------------------------------ */
	/* generate the style position and dimensions */
	/* ------------------------------------------ */
	fprintf(f,"#%s%s {",react_widget_id(iptr),postfix);

	fprintf(f,"position: absolute; top: %s; left: %s;",y,x);
	fprintf(f,"width: %s; height:%s; ",w,h);

	/* ------------------------------ */
	/* handle the hidden elements too */
	/* ------------------------------ */
	if ( iptr->Contents.events->xo_show & _EVENT_IS_COND)
		fprintf(f,"visibility: hidden;");

	fprintf(f," }\n");
	return( wh );

}

/*	-----------------------------------------	*/
/*	e x p o r t _ i m p l i c i t _ s t y l e	*/
/*	-----------------------------------------	*/
private	int	export_implicit_style(FILE * f, struct form_item * iptr, int wh, int fh, char * postfix )
{

	fprintf(f,".%s%s {\n",react_widget_id(iptr),postfix);

	/* ---------------------------- */
	/* handle the colours and frame */
	/* ---------------------------- */
	switch (iptr->Contents.style & _FRAME_TYPE)
	{
	case	_DATA_FRAME	:
               	if (( iptr->Contents.align & 0x00FF) == _VGROUP_FRAME)
			fprintf(f,"overflow: scroll;");
		break;

	case	_WINDOW_FRAME	: 
		react_css_font(f,iptr->Contents.h,wh,fh,"left",0);
		fprintf(f,"color: black; background-color: silver;");
		fprintf(f,"border-width: 1px; border-style: outset; border-color: grey;\n");
		break;
	case	_TAB_FRAME	: 
		react_css_font(f,iptr->Contents.h,wh,fh,"center",0);
		fprintf(f,"padding: 1mm; color: black;");
		fprintf(f,"background-color: silver; border-width: 1px; border-style: inset; border-color: grey;\n");
		break;
	case	_FILL_FRAME	: 
		/* -------------------------------------------- */
		/* several different types or fill are possible */
		/* -------------------------------------------- */
		/* ---------------- */
		/* background color */
		/* ---------------- */
		fprintf(f,"background-color: ");
		switch ( iptr->Contents.align & 0x001F )
		{
		case	4	:
		case	10	:	/* hconvex	*/
			html_rgb_gradient(f, ((iptr->Contents.colour & 0xFF00) >> 8), 0,0 );
			break;
		case	5	:	/* vconvex	*/
			html_rgb_gradient(f, ((iptr->Contents.colour & 0xFF00) >> 8), 1, 0 );
			break;
		case	6	:	/* hconcave	*/
		case	11	:
			html_rgb_gradient(f, ((iptr->Contents.colour & 0xFF00) >> 8), 0, 1 );
			break;
		case	7	:	/* vconcave	*/
			html_rgb_gradient(f, ((iptr->Contents.colour & 0xFF00) >> 8), 1, 1 );
			break;
		case	12	:
		case	15	:
		case	16	:	/* alpha channel */
			html_rgb_alpha(f, ((iptr->Contents.colour & 0xFF00) >> 8), 0 );
			break;
		case	0	:
		case	3	:
		case	8	:
		case	9	:
		case	14	:
		case	17	:
			html_rgb_colour(f,((iptr->Contents.colour & 0xFF00) >> 8));
			break;
		default		:
			fprintf(f,"transparent;");
			break;
		}
		/* ------------ */
		/* border style */
		/* ------------ */
		fprintf(f,"border-style: ");
		switch ( iptr->Contents.align & 0x001F )
		{
		case	1	:
		case	8	:
		case	10	:
		case	11	:
		case	15	:
			fprintf(f,"outset; border-width: 1px;");
			break;
		case	2	:
		case	9	:
			fprintf(f,"solid; border-width: 1px; border-color: ");
			html_rgb_colour(f,(iptr->Contents.colour & 0x00FF));
			break;
		default	:
			fprintf(f,"none; border-width: 0; border-color: transparent;");
		}
		/* ------------- */
		/* rounded frame */
		/* ------------- */
		switch ( iptr->Contents.align & 0x001F )
		{
		case	2	:
		case	3	:
		case	9	: 
		case	17	: /* circle */
                	fprintf(f, "border-radius: 50%;" );
			break;

		case	13	:
		case	14	: /* rounded */
                	fprintf(f, "border-radius: 4px;" );
			break;
		}
		break;
	case	_FORM_FRAME	: 
		fprintf(f,"color: black;");
		fprintf(f,"background-color: white; padding: 2px; border-width: 1px; border-style: solid; border-color: grey;\n");
		react_css_font(f,0,wh,fh,(char *) 0,0);
		fprintf(f," color: ");
		html_rgb_colour(f,(iptr->Contents.colour & 0x00FF));
		fprintf(f,"background-color: ");
		html_rgb_colour(f,((iptr->Contents.colour & 0xFF00) >> 8));
		break;
	case	_SWITCH_FRAME	: 
		react_css_font(f,iptr->Contents.h,wh,fh,"center",0);
	case	_EDIT_FRAME	: 
		fprintf(f,"color: black;");
		fprintf(f,"background-color: white; padding: 2px; border-width: 1px; border-style: solid; border-color: grey;\n");
		react_css_font(f,0,wh,fh,(char *) 0,0);
		break;
	case	_BUTTON_FRAME	: 
		fprintf(f,"color: black;");
		if (( iptr->Contents.datatype == _WIDGET_AUDIO )
		||  ( iptr->Contents.datatype == _WIDGET_VIDEO ))
			fprintf(f,"background-color: black; padding: 0; border-width:1px; border-style: solid; border-color: black;\n");
		else	
		{
			/* ------------------------- */
			/* if not an ICON the BORDER */
			/* ------------------------- */
			if (!( iptr->Contents.align & 1 ))
			{
				fprintf(f,"background-color: silver; padding: 2mm; border-style: groove; border-color: grey;\n");
				react_css_font(f,iptr->Contents.h,wh,fh,"center",0);
			}
			else
			{
				fprintf(f,"background-color: transparent; padding: 0; border-style: none; border-color: transparent;\n");
				react_css_font(f,iptr->Contents.h,wh,fh,"center",0);
			}
		}
		break;
	case	_SELECT_FRAME	: 
		react_css_font(f,iptr->Contents.h,wh,fh,"left",0);
		fprintf(f,"color: black;");
		fprintf(f,"background-color: white; border-style: solid; border-color: grey;\n");
		break;
	case	_CHECK_FRAME	:
	case	_RADIO_FRAME	:
		fprintf(f,"background-color: transparent;");
		fprintf(f," color: ");
		html_rgb_colour(f,(iptr->Contents.colour & 0x00FF));
		break;

	case	_TEXT_FRAME	:
		switch ( (iptr->Contents.align & 3 ) )
		{
		case	0	: react_css_font(f,iptr->Contents.h,wh,fh,"center",0); 	break;
		case	1	: react_css_font(f,iptr->Contents.h,wh,fh,"right",0); 	break; 
		case	2	: react_css_font(f,iptr->Contents.h,wh,fh,"left",0); 	break;
		case	3	: react_css_font(f,iptr->Contents.h,wh,fh,"center",0); 	break;
		default		: react_css_font(f,iptr->Contents.h,wh,fh,"left",0); 	break;
		}
		fprintf(f,"vertical-align: bottom;");
		fprintf(f," color: ");
		html_rgb_colour(f,(iptr->Contents.colour & 0x00FF));
	default			:
		fprintf(f,"background-color: ");
		html_rgb_colour(f,((iptr->Contents.colour & 0xFF00) >> 8));
		break;
	}
	fprintf(f,"}\n");
	return(0);
}

/*	-------------------------------		*/
/*	e x p o r t _ r e a c t _ d o m 	*/
/*	-------------------------------		*/
/*	generate document object model		*/
/*	for REACT instance to play in.		*/
/*	-------------------------------		*/
private	int	export_react_dom( FILE * h, struct form_control * fptr, char * pptr, char * qptr )
{
	/* ------------------------ */
	/* generate document header */
	/* ------------------------ */
	fprintf(h,"<!DOCTYPE html>\n<html>\n<head>\n<meta charset=\"UTF-8\"/>\n<title>%s</title>\n",fptr->identifier);

	/* -------------------------- */
	/* generate script dependance */
	/* -------------------------- */
   	fprintf(h,"<script src=\"https://unpkg.com/react@16/umd/react.development.js\"></script>\n");
	fprintf(h,"<script src=\"https://unpkg.com/react-dom@16/umd/react-dom.development.js\"></script>\n");

	if ( generate_jsx )
		fprintf(h,"<script src=\"https://unpkg.com/babel-standalone@6.15.0/babel.min.js\"></script>\n");

	if (!( generate_visual_base_classes ))
	{
		if ( generate_jsx )
			fprintf(h,"<script type=\"text/babel\" src=\"visualreact.jsx\"></script>\n");
		else	fprintf(h,"<script type=\"text/javascript\" src=\"visualreact.js\"></script>\n");
	}

	/* ---------------------------------------- */
	/* generate implicite stylesheet dependance */
	/* ---------------------------------------- */
	export_nested_style( h );

	fprintf(h,"<link rel=\"stylesheet\" type=\"text/css\" href=\"%s\">\n",qptr);

	/* ---------------------------------------- */
	/* generate explicite stylesheet dependance */
	/* ---------------------------------------- */
	if ( method_is_valid( fptr->stylesheet ) )
		fprintf(h,"<link rel=\"stylesheet\" type=\"text/css\" href=\"%s\">\n",fptr->stylesheet);

	/* ---------------------------------- */
	/* generate the document object model */
	/* ---------------------------------- */
	fprintf(h,"</head>\n<body>\n<div id=\"root_%s\"></div>\n",fptr->identifier);

	export_nested_script( h );
	
	if ( generate_jsx )
		fprintf(h,"<script type=\"text/babel\" src=\"%s\">please activate use of javascript</script>\n",pptr);
	else	fprintf(h,"<script type=\"text/javascript\" src=\"%s\">please activate use of javascript</script>\n",pptr);
	fprintf(h,"</body>\n</html>\n");
	return(0);
}

/*	-----------------------------------	*/
/*	e x p o r t _ r e a c t _ s t y l e	*/
/*	-----------------------------------	*/
private	int	export_react_style( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr=(struct  form_item *) 0;
	struct	form_item * wptr=(struct  form_item *) 0;

	/* ------------------------------- */
	/* generate the stylesheet classes */
	/* ------------------------------- */
	fprintf(h,"body { font-family: Arial; margin: 0px; padding: 0px; background-color: black; }\n");

	if ( fptr->resizeauto )
	{
		/* ------------------ */
		/* form is fullscreen */
		/* ------------------ */
		fprintf(h,".%s { width: 100%; height: 100%; margin: 0px; padding: 0px; position: fixed; }\n",fptr->identifier);

		/* ------------------------- */
		/* locate the window element */
		/* ------------------------- */
		for  (  wptr=fptr->first;
			wptr != (struct form_item *) 0;
			wptr = wptr->next )
			if ((wptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME )
				break;

	}
	else
	{
		/* --------------- */
		/* not full screen */
		/* --------------- */
        	fprintf(h,".%s { margin: 0px; padding: 0px; position: relative; }\n",fptr->identifier);        
	}

	/* ---------------------------------- */
	/* generate the element style classes */
	/* ---------------------------------- */
	for  (  iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if (( iptr->Contents.style & _VISUAL_FRAME ) == _FORM_FRAME )
			react_table_css(h,iptr,wptr);
		else	export_react_css(h,iptr,wptr,"");
	}

}

/*	--------------------------	*/
/*	bind_react_forms_methods	*/
/*	--------------------------	*/
private	void	bind_react_forms_methods(FILE * h, struct form_control * fptr)
{
	struct	forms_method * mptr;
	for (	mptr = fptr->rootmethod; 
		mptr != (struct forms_method *) 0;
		mptr = mptr->next )
	{
		if ( is_react_special_method( mptr->name ) )
			continue;
		else if ( method_is_valid( mptr->text ) )
			react_bind_method(h, mptr->name, "");
	}
	return;
}

/*	--------------------------	*/
/*	export_react_forms_methods	*/
/*	--------------------------	*/
private	void	export_react_forms_methods(FILE * h, struct form_control * fptr)
{
	struct	forms_method * mptr;
	for (	mptr = fptr->rootmethod; 
		mptr != (struct forms_method *) 0;
		mptr = mptr->next )
	{
		if ( is_react_special_method( mptr->name ) )
			continue;
		else if ( method_is_valid( mptr->text ) )
		{
			if (!( method_is_valid( mptr->signature )))
				fprintf(h,"\t\%s()\n\t{\n",mptr->name);
			else	fprintf(h,"\t\%s(%s)\n\t{\n",mptr->name,mptr->signature);
			expand_react_method(h,(struct form_item*)0,mptr->text);
			fprintf(h,"\t};\n");
		}
	}
	return;
}

/*	--------------------------	*/
/*	export_react_forms_members	*/
/*	--------------------------	*/
private	char * export_react_forms_members(FILE * h, struct form_control * fptr)
{
        struct  forms_data_member * mptr;
	struct	form_item * iptr;
	char *	sep="\n";
	if ( fptr->rootmember )
	{

		for (   mptr=fptr->rootmember;
			mptr != (struct forms_data_member *) 0;
			mptr = mptr->next ) 
		{
                        fprintf(h,"%s\t\t\t%s : \"\"",sep,mptr->name);
                        sep = ",\n";
                }
	}
	for (	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style == _DATA_FRAME )
		{
			if ( is_file_Widget( iptr ) )
			{
				fprintf(h,"%s\t\t\t%s : ",sep,iptr->Contents.name);
				export_react_data_object(h, iptr );
                        	sep = ",\n";
			}
		}
	}
        return(sep);
}

/*	---------------------------------------------------------	*/
/*		     e x p o r t _ a j a x _ f o r m 			*/
/*	---------------------------------------------------------	*/
/*	generates the PHP page for the reception of AJAX requests 	*/
/*	from AJAX Widget Buttons Events defined in the form.		*/
/*	---------------------------------------------------------	*/
private	void	export_react_ajax_form( struct form_control * fptr )
{
	struct	form_item * iptr;
	struct	forms_method * mptr;
	char	ajaxname[1024];
	char	phpname[1024];
	FILE *	h;
	/* ------------------------------ */		
	/* scan the form for AJAX BUTTONS */
	/* ------------------------------ */		
	for (	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style != _BUTTON_FRAME )
			continue;
		else if ( iptr->Contents.datatype != _WIDGET_AJAX )
			continue;
		else	break;
	}
	if ( iptr )
	{
		/* ------------------------------------ */
		/* generate AJAX Button Request Handler */
		/* ------------------------------------ */
		sprintf(ajaxname,"ajax_%s.php",fptr->identifier);
		if (( h = fopen( ajaxname, "w" )) != (FILE *) 0)
		{
			fprintf(h,"<?php\n");
			fprintf(h,"// -------------------------------------------------\n");        
			fprintf(h,"// AJAX BUTTON REQUEST for FORM : %s\n",fptr->identifier);
			fprintf(h,"// -------------------------------------------------\n");        
			fprintf(h,"require_once(\"sing/html.inc\");\n");
	        	fprintf(h,"require_once(\"sing/http.inc\");\n");
	        	fprintf(h,"require_once(\"sing/soaparser.inc\");\n");
	        	fprintf(h,"require_once(\"sing/soapclient.inc\");\n");
	        	fprintf(h,"require_once(\"sing/visual.inc\");\n");

			/* -------------------------- */
			/* read the JSON message BODY */
			/* -------------------------- */
			fprintf(h,"$b = file_get_contents('php://input');\n");
			fprintf(h,"if (!( $b )) { die(400); }\n");

			/* ---------------------- */
			/* Parse the JSON message */
			/* ---------------------- */
			fprintf(h,"$request = json_decode($b);\n");
			fprintf(h,"if (!( $request )) { die(400); }\n");

			/* -------------------------------- */
			/* ensure the FORM name corresponds */
			/* ------------------------------- */
			fprintf(h,"if ( $request->form != '%s' ) { die(400); }\n",fptr->identifier);

			/* ------------------------------------- */
			/* dispatch the widget action processing */
			/* ------------------------------------- */
			fprintf(h,"switch ( $request->widget )\n{\n");

			do
			{
				if ( iptr->Contents.style != _BUTTON_FRAME )
					continue;
				else if ( iptr->Contents.datatype != _WIDGET_AJAX )
					continue;
				else
				{
					fprintf(h,"case '%s' :\n",iptr->Contents.name);
					fprintf(h,"\t// $request->text contains the message body \n");
					sprintf(phpname,"ajaxphp:%s",iptr->Contents.name);
					if  ((mptr = detect_forms_method(fptr, phpname)) != (struct forms_method *) 0)
					{
						fprintf(h,"\t// AJAX:PHP processing from %s \n",phpname);
						if ( method_is_valid( mptr->text ) )
							expand_ajax_method(h,iptr->Contents.name,mptr->text);
					}
					fprintf(h,"\tbreak;\n");
				}

			}
			while (( iptr = iptr->next) != (struct form_item *) 0 );


			fprintf(h,"default : die(405);\n");

			fprintf(h,"}\n");

			fprintf(h,"// --------------------------\n");        
			fprintf(h,"// END OF AJAX DATA CONNECTOR\n");
			fprintf(h,"// --------------------------\n");
	
			fprintf(h,"?>");
			fclose(h);
		}
	}

}

/*	---------------------------------------------------------	*/
/*		e x p o r t _ a j a x _ c o n n e c t o r		*/
/*	---------------------------------------------------------	*/
/*	generates the PHP page for the reception of AJAX requests 	*/
/*	from database objects of the specified table class.		*/
/*	---------------------------------------------------------	*/
private	void	export_ajax_connector(struct form_item * iptr, char * classname)
{
	char	ajaxname[1024];
	FILE *	h;
	int	fields;
	int	i;
	char *	sep=",";
	char *	databasename;
	char *	databasefile;
	struct  data_control *  dptr=(struct data_control *) 0;
	sprintf(ajaxname,"ajax_%s.php",classname);
	if (!( h = fopen( ajaxname, "w" )))
		return;
	else
	{
		fprintf(h,"<?php\n");
		fprintf(h,"// -------------------------------------------------\n");        
		fprintf(h,"// AJAX DATA CONNECTOR for CLASS : %s\n",classname);
		fprintf(h,"// -------------------------------------------------\n");        
		fprintf(h,"require_once(\"sing/html.inc\");\n");
	        fprintf(h,"require_once(\"sing/http.inc\");\n");
	        fprintf(h,"require_once(\"sing/soaparser.inc\");\n");
	        fprintf(h,"require_once(\"sing/soapclient.inc\");\n");
	        fprintf(h,"require_once(\"sing/visual.inc\");\n");
	        fprintf(h,"require_once(\"%s.inc\");\n",classname);
                               
		if (!( databasename = application_databasename() ))
			databasename = "mydatabase";
                                
		if (!( databasefile = react_payload( iptr ) ))
			databasefile = "mydatafile";

		fprintf(h,"// ------------------\n");
		fprintf(h,"// PARSE JSON REQUEST\n");
		fprintf(h,"// ------------------\n");
		fprintf(h,"function parse_json_request($d)\n{\n");
		fprintf(h,"\t$j = json_decode($d);\n");
		fprintf(h,"\t$q = $j->question;\n");
		fprintf(h,"\t$a = $j->response;\n");
		fprintf(h,"\t$e = $j->error;\n");
		fprintf(h,"\t$t = new %s(\"%s\",%s);\n",classname,databasename,databasefile);
		fprintf(h,"\t$t->error = $e;\n");
		fprintf(h,"\t$t->question = $q;\n");
		fprintf(h,"\t$t->response = $a;\n");
        	if (((dptr = iptr->Contents.extra ) != (struct data_control *) 0)
        	&&  (( fields = dptr->indexfields + dptr->datafields ) != 0))
		{
			for ( i=0; i < fields; i++ )
			{
				fprintf(h,"$t->_%s = $j->%s;\n",dptr->name[i],dptr->name[i]);
			}
		}
		fprintf(h,"\treturn( $t );\n");
		fprintf(h,"}\n");

		fprintf(h,"// ------------------\n");
		fprintf(h,"// RENDER JSON RESULT\n");
		fprintf(h,"// ------------------\n");
		fprintf(h,"function render_json_response($t)\n{\n");
		fprintf(h,"\t$result = \"{");
        	if (((dptr = iptr->Contents.extra ) != (struct data_control *) 0)
        	&&  (( fields = dptr->indexfields + dptr->datafields ) != 0))
		{
			fprintf(h,"\\\"error\\\":\\\"\".$t->error.\"\\\"");
			fprintf(h,",\\\"question\\\":\\\"\".$t->question.\"\\\"");
			fprintf(h,",\\\"response\\\":\\\"\".$t->response.\"\\\"");
			sep = ",";
			for ( i=0; i < fields; i++ )
			{
				fprintf(h,"%s\\\"%s\\\":\\\"\".$t->_%s.\"\\\"",sep,dptr->name[i],dptr->name[i]);
				sep = ",";
			}
		}
		fprintf(h,"}\";\n");
		fprintf(h,"\treturn( $result );\n");
		fprintf(h,"}\n");

		fprintf(h,"// -------------------------\n");
		fprintf(h,"// PROCESS AJAX DATA REQUEST\n");
		fprintf(h,"// -------------------------\n");

		fprintf(h,"$b = file_get_contents('php://input');\n");
		fprintf(h,"if (!( $b )) { die(400); }\n");

		fprintf(h,"$%s = parse_json_request($b);\n",iptr->Contents.name);

		fprintf(h,"switch ( $_REQUEST[\"action\"] )\n{\n");

		fprintf(h,"case 'oncreate'  :\n");
			fprintf(h,"\t$%s->OnCreate(); break;\n",iptr->Contents.name);

		fprintf(h,"case 'onremove'  :\n");
			fprintf(h,"\t$%s->OnRemove(); break;\n",iptr->Contents.name);

		fprintf(h,"case 'oninsert'  :\n");
			fprintf(h,"\t$%s->OnInsert(); break;\n",iptr->Contents.name);

		fprintf(h,"case 'onmodify'  :\n");
			fprintf(h,"\t$%s->OnModif(); break;\n",iptr->Contents.name);

		fprintf(h,"case 'onsearch'  :\n");
			fprintf(h,"\t$%s->OnSearch(); break;\n",iptr->Contents.name);

		fprintf(h,"case 'ondelete'  :\n");
			fprintf(h,"\t$%s->OnDelete(); break;\n",iptr->Contents.name);

		fprintf(h,"case 'oncollect' :\n");
			fprintf(h,"\t$%s->OnCollect(); break;\n",iptr->Contents.name);

		fprintf(h,"case 'onlocate'  :\n");
			fprintf(h,"\t$%s->OnLocate(); break;\n",iptr->Contents.name);

		fprintf(h,"case 'onfirst'   :\n");
			fprintf(h,"\t$%s->OnFirst(); break;\n",iptr->Contents.name);

		fprintf(h,"case 'ondown'    :\n");
			fprintf(h,"\t$%s->OnDown(); break;\n",iptr->Contents.name);

		fprintf(h,"case 'onup'      :\n");
			fprintf(h,"\t$%s->OnUp(); break;\n",iptr->Contents.name);

		fprintf(h,"case 'onlast'    :\n");
			fprintf(h,"\t$%s->OnLast(); break;\n",iptr->Contents.name);

		fprintf(h,"case 'onnew'     :\n");
			fprintf(h,"\t$%s->OnNew(); break;\n",iptr->Contents.name);

		fprintf(h,"default : die(405);\n");

		fprintf(h,"}\n");

		fprintf(h,"print render_json_response($%s);\n",iptr->Contents.name);
		fprintf(h,"die(200);\n");

		fprintf(h,"// --------------------------\n");        
		fprintf(h,"// END OF AJAX DATA CONNECTOR\n");
		fprintf(h,"// --------------------------\n");

		fprintf(h,"?>");
		fclose(h);
		return;
	}
}

/*	-----------------------		*/
/*	react_jsx_configuration		*/
/*	-----------------------		*/
private	int	react_jsx_configuration( struct form_control * fptr )
{
	struct	forms_method * mptr;
	if ((mptr = detect_forms_method(fptr,"generatejsx")) != (struct form_method *) 0)
		return(0);
	else if ((mptr = detect_forms_method(fptr,"generatejs")) != (struct form_method *) 0)
		return(0);
	else	return(generate_jsx);
}

/*	-------------------------------------	*/
/*	r e a c t _ c o n f i g u r a t i o n	*/
/*	-------------------------------------	*/
private	react_configuration( struct form_control * fptr )
{
	generate_jsx = react_jsx_configuration( fptr );
	return;
}

/*	-------------------------------------	*/
/*	r e a c t _ e l e m e n t _ s t y l e	*/
/*	-------------------------------------	*/
private	char *	react_element_style(struct form_item * iptr)
{
	if (!( method_is_valid( iptr->Contents.stylesheet ) ))
		return( react_widget_id(iptr) );
	else	return( iptr->Contents.stylesheet );
}

/*	---------------------------------	*/
/*	r e a c t _ j s _ i n s t a n c e 	*/
/*	----------i----------------------	*/
private	void	react_js_instance( FILE * h, struct form_item * iptr )
{

	/* --------------------------- */
	/* bind eventual event methods */
	/* --------------------------- */
	switch ( iptr->Contents.style )
	{
	case	_BUTTON_FRAME	:
		switch ( iptr->Contents.datatype )
		{
		case	_WIDGET_VIDEO	:
		case	_WIDGET_AUDIO	:
			break;
		default			:
			react_bind_method(h, iptr->Contents.name, "Event" );
			react_bind_method(h, iptr->Contents.name, "Enter" );
			react_bind_method(h, iptr->Contents.name, "Leave" );
		}
	}
	return;
}

/*	-------------------------------		*/
/*	r e a c t _ j s _ e l e m e n t 	*/
/*	-------------------------------		*/
/*	generate a JS element instance 		*/
/*	when JS generation has been set	i	*/
/*	this may be either from rendor		*/
/*	or from the constructor.		*/
/*	-------------------------------		*/
private	void	react_js_element( FILE * h, struct form_item * iptr )
{
	fprintf(h,"React.createElement(",iptr->Contents.name);

	switch ( iptr->Contents.style )
	{
	case	_WINDOW_FRAME	:
		fprintf(h,"VisualWindow,{id:'%s', className:'%s', title:%s},null",
			react_widget_id(iptr),
			react_element_style(iptr),
			react_payload(iptr));
		break;

	case	_TAB_FRAME	:
		fprintf(h,"VisualTabPage,{id:'%s',className:'%s', number:%u, label:%s}",
			react_widget_id(iptr),
			react_element_style(iptr),
			iptr->Contents.page,
			react_payload(iptr));
		/* -------------------------------------- */
		/* TAB FRAME returns now to avoid closure */
		/* Widgets will be added as children      */
		/* -------------------------------------- */
		return;

	case	_FILL_FRAME	:
		fprintf(h,"VisualFill,{id:'%s',className:'%s'},null",react_widget_id(iptr),react_element_style(iptr));
		break;

	case	_TEXT_FRAME	:
		fprintf(h,"VisualText,{id:'%s',className:'%s', value:%s},null",
			react_widget_id(iptr),
			react_element_style(iptr),
			react_payload(iptr));
		break;

	case	_IMAGE_FRAME	:
		fprintf(h,"VisualImage,{id:'%s',className:'%s', src:%s},null",
			react_widget_id(iptr),
			react_element_style(iptr),
			react_payload(iptr));
		break;

	case	_FORM_FRAME	:
		fprintf(h,"VisualTable,{id:'%s',className:'%s',format:this.state.%sFmt,titles:this.state.%sTH,data:this.state.%sData},null",
			react_widget_id(iptr),
			react_element_style(iptr),
			iptr->Contents.name,
			iptr->Contents.name,
			iptr->Contents.name);
		break;

	case	_EDIT_FRAME	:
		fprintf(h,"VisualEdit,{id:'%s',className:'%s', name:'%s',change:this.%sChange, value:this.state.%sBuffer},null",
			react_widget_id(iptr),
			react_element_style(iptr),
			iptr->Contents.name,
			iptr->Contents.name,
			iptr->Contents.name);
		break;

	case	_SELECT_FRAME	:
		fprintf(h,"VisualSelect,{id:'%s',className:'%s', name:'%s', change:this.%sChange, value:this.state.%sValue, items:",
			react_widget_id(iptr),
			react_element_style(iptr),
			iptr->Contents.name, 
			iptr->Contents.name, 
			iptr->Contents.name);

		react_select_options(h,iptr);
		fprintf(h,"},null");
		break;

	case	_SWITCH_FRAME	:
		fprintf(h,"VisualSwitch,{id:'%s',className:'%s', name:'%s', change:this.%sChange, value:this.state.%sValue, message:%s},null",
			react_widget_id(iptr),
			react_element_style(iptr),
			iptr->Contents.name,
			iptr->Contents.name,
			iptr->Contents.name,
			react_payload(iptr));
		break;

	case	_CHECK_FRAME	:
		fprintf(h,"VisualCheck,{id:'%s',className:'%s', name:'%s', change:this.%sChange, value:this.state.%sValue, message:%s},null",
			react_widget_id(iptr),
			react_element_style(iptr),
			iptr->Contents.name,
			iptr->Contents.name,
			iptr->Contents.name,
			react_payload(iptr));
		break;

	case	_RADIO_FRAME	:
		fprintf(h,"VisualRadio,{id:'%s',className:'%s', name:'%s', change:this.%sChange, value:this.state.%sValue, message:%s},null",
			react_widget_id(iptr),
			react_element_style(iptr),
			iptr->Contents.name,
			iptr->Contents.name,
			iptr->Contents.name,
			react_payload(iptr));
		break;

	case	_BUTTON_FRAME	:
		if ( iptr->Contents.datatype == _WIDGET_VIDEO )
		{
			fprintf(h,"VisualVideo,{id:'%s',className:'%s', name:'%s', items:%s},null",
				react_widget_id(iptr),react_element_style(iptr),iptr->Contents.name,react_payload(iptr));
		}
		else if ( iptr->Contents.datatype == _WIDGET_AUDIO )
		{
			fprintf(h,"VisualAudio,{id:'%s',className:'%s', name:'%s', src:%s},null",
				react_widget_id(iptr),iptr->Contents.name,react_payload(iptr));
		}
		else if (iptr->Contents.align & 1)
		{
			fprintf(h,"VisualIcon,{id:'%s',className:'%s', name:'%s', src:%s, action:this.%sEvent, enter:this.%sEnter, leave:this.%sLeave},null",
				react_widget_id(iptr),
				react_element_style(iptr),
				iptr->Contents.name,
				react_payload(iptr),
				iptr->Contents.name,
				iptr->Contents.name,
				iptr->Contents.name);
		}
		else
		{
			fprintf(h,"VisualButton,{id:'%s',className:'%s', name:'%s', label:%s, action:this.%sEvent, enter:this.%sEnter, leave:this.%sLeave},null",
				react_widget_id(iptr),
				react_element_style(iptr),
				iptr->Contents.name,
				react_payload(iptr),
				iptr->Contents.name,
				iptr->Contents.name,
				iptr->Contents.name);
		}
		break;
	}
	fprintf(h,")");
	return;
}

struct	react_require
{	struct	react_require * previous;
	struct	react_require *	next;
	char *	name;
};

private	struct react_require * head=( struct react_require *) 0;
private	struct react_require * foot=( struct react_require *) 0;

/*	------------------	*/
/*	reset_react_nested	*/
/*	------------------	*/
private	void	reset_react_nested()
{
	head = foot = ( struct react_require *) 0;
	return;
}

/*	--------------------	*/
/*	release_react_nested	*/
/*	--------------------	*/
private	void	release_react_nested()
{
	struct	react_require * nptr;
	while ((nptr = head) != (struct react_require *) 0)
	{
		head = nptr->next;
		if ( nptr->name )
			liberate( nptr->name );
		liberate(nptr);
	}
	head = foot = ( struct react_require *) 0;
	return;
}

/*	--------------------	*/
/*	require_react_nested	*/
/*	--------------------	*/
private	void	require_react_nested(FILE * h, struct form_control * fptr)
{
	struct react_require * what=( struct react_require *) 0;
	char *	sptr;
	int	c;
	for (	what = head;
		what != (struct react_require *) 0;
		what = what->next)
	{
		if (!( what->name ))
			continue;
		else if (!( strcmp( what->name, fptr->identifier ) ))
			return;
	}
	/* -------------------------------- */
	/* allocate this required component */
	/* -------------------------------- */
	if (!( what = allocate( sizeof( struct react_require ) ) ))
		return;
	else if (!( what->name = allocate_string( fptr->identifier ) ))
		return( liberate( what ) );
	else
	{
		/* ------------------ */
		/* add it to the list */
		/* ------------------ */
		if (!( what->previous = foot ))
			head = what;
		else	what->previous->next = what;
		foot = what;
		/* ------------------------------ */
		/* generate the require statement */
		/* ------------------------------ */
		return;
	}
}

/*	-------------------	*/
/*	export_nested_style	*/
/*	-------------------	*/
private	void	export_nested_style( FILE * h)
{
	struct	react_require * rptr;
	for (	rptr = head;
		rptr != (struct react_require *) 0;
		rptr = rptr->next )
		fprintf(h,"<link rel=\"stylesheet\" type=\"text/css\" href=\"%s.css\">\n",rptr->name);
	return;
}

/*	--------------------	*/
/*	export_nested_script	*/
/*	--------------------	*/
private	void	export_nested_script( FILE * h )
{
	struct	react_require * rptr;
	struct	form_control * ffptr;
	for (	rptr = head;
		rptr != (struct react_require *) 0;
		rptr = rptr->next )
	{
                if (!(ffptr = locate_form_control( rptr->name ) ))
                        continue;
		else if ( react_jsx_configuration( ffptr ) != 0)
			fprintf(h,"<script type=\"text/babel\" src=\"%s.jsx\">please activate use of javascript</script>\n",rptr->name);
		else	fprintf(h,"<script type=\"text/javascript\" src=\"%s.js\">please activate use of javascript</script>\n",rptr->name);
	}
	return;
}

/*	-------------------------------------	*/
/*	e x p o r t _ r e a c t _ n e s t e d	*/
/*	-------------------------------------	*/
private	void	export_react_nested(FILE * h, struct form_control * fptr)
{
	struct	form_item * iptr;
	char * 	fnptr;
	struct	form_control * ffptr;

	for  (  iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style != _DATA_FRAME )
			continue;
                else if ( is_file_Widget( iptr ) )
			continue;
                else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
                        continue;
                else if (!( fnptr = abal_payload(iptr) ))
                        continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
                        continue;
		else
		{
			/* --------------------------- */
			/* process in depth components */
			/* --------------------------- */
			export_react_nested( h, ffptr );

			/* ------------------------------ */
			/* require if not alreay required */
			/* ------------------------------ */
			require_react_nested( h, ffptr );
		}
	}
	
	return;
}

/*	---------------------	*/	
/*	export_react_oncreate	*/
/*	---------------------	*/	
private	void	export_react_oncreate(FILE * h, struct form_item * iptr)
{
	int	c;
	char *	sptr;
	char * 	fnptr;
        if (!( fnptr = abal_payload(iptr) ))
		return;
	fprintf(h,"\t%sCreate()\n\t{\n",iptr->Contents.name);
	if ( generate_jsx )
	{
		sptr = fnptr;
		c = *(sptr++);
		if ((c >= 'a') && (c <= 'z')) c = ((c - 'a') + 'A');
		fprintf(h,"\t\tthis.%s = <div id=\"%s\" className=\"%s\">\n",
			iptr->Contents.name,
			react_widget_id(iptr),react_element_style(iptr));
		fprintf(h,"\t\t\t<%c%s name=\"%s\" parameters=%s/>\n",
			c,sptr,react_widget_id(iptr),react_payload_format(iptr));
		fprintf(h,"\t\t</div>\n");
	}
	else
	{
		sptr = fnptr;
		c = *(sptr++);
		if ((c >= 'a') && (c <= 'z')) c = ((c - 'a') + 'A');
		fprintf(h,"\t\tthis.%s = React.createElement(%c%s,{name:'%s', parameters:%s},null);\n",
			iptr->Contents.name,
			c,sptr,react_widget_id(iptr),react_payload_format(iptr));
		fprintf(h,"\t\tthis.%sHost = React.createElement('div',{id:\"%s\",className:\"%s\"},this.%s);\n",
			iptr->Contents.name,
			react_widget_id(iptr),react_element_style(iptr),
			iptr->Contents.name);
		
	}
	fprintf(h,"\t}\n");
	return;
}

/*	------------------	*/
/*	react_table_format	*/
/*	------------------	*/
private	void	react_table_format(FILE *h, struct form_item *iptr)
{
        int     linelength, nblines,i,fields,posit;
        int     fieldwidth[_MAX_FORM_FIELDS];
        if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
                return;
        calculate_edit_size( &iptr->Contents );
        calculate_form_lines( iptr, &linelength, &nblines );

        if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
                return;
	fprintf(h,"[");
        for (i=0; i < fields; i++ ) {
                if ( i ) fprintf(h,",");
                fprintf(h,"%u",fieldwidth[i]);
                }
	fprintf(h,"]");
	return;
}

/*	-------------------	*/
/*	react_payload_array	*/
/*	-------------------	*/
private	void	react_payload_array(FILE * h, struct form_item * iptr )
{
        int     item=0;
        char *  vptr;
	char * sptr;

	if ((sptr = react_payload_value(iptr))!= (char *) 0)
	{
		if ( *sptr == '$' )
		{
			fprintf(h,"%s",(sptr+1));
		}
		else
		{
			fprintf(h,"[");
        		while ((vptr = selection_item(item++,sptr )) != (char *) 0)
        		{
				if (item > 1 ) 
					fprintf(h,",'%s'",vptr);
				else	fprintf(h,"'%s'",vptr);
        		}
			fprintf(h,"]");
		}
	}
	else
	{
		fprintf(h,"[");
		fprintf(h,"]");
	}
	return;
}

/*	-------------------	*/
/*	react_table_headers	*/
/*	-------------------	*/
private	void	react_table_headers(FILE *h, struct form_item *iptr)
{
        if ((iptr->Contents.style & _FRAME_TYPE) == _FORM_FRAME)
		react_payload_array(h,iptr);
	return;
}

/*	--------------------	*/
/*	react_select_options	*/
/*	--------------------	*/
private	void	react_select_options(FILE *h, struct form_item * iptr)
{
        if ((iptr->Contents.style & _FRAME_TYPE) == _SELECT_FRAME)
		react_payload_array(h,iptr);
	return;
}

/*	------------------	*/
/*	react_table_cells	*/
/*	------------------	*/
private	void	react_table_cells(FILE *h, struct form_item *iptr)
{
        int     linelength, nblines,i,fields,posit;
        int     fieldwidth[_MAX_FORM_FIELDS];
        if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
                return;
        calculate_edit_size( &iptr->Contents );
        calculate_form_lines( iptr, &linelength, &nblines );

        if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
                return;
	fprintf(h,"[");
	fprintf(h,"]");
	return;
}

/*	-------------------	*/
/*	react_render_widget	*/
/*	-------------------	*/
private	int	react_render_widget(FILE *h, struct form_item *iptr)
{
	int	c;
	char *	sptr;
	char * 	fnptr;
	struct	form_control * ffptr;
	/* ------------------------------------------- */
	/* avoid non visual objects and hidden widgets */
	/* ------------------------------------------- */
	if ( iptr->Contents.style == _DATA_FRAME )
	{
		if ( is_file_Widget( iptr ) )
			return(0);
		else if (( iptr->Contents.align & 0x00FF) == _VGROUP_FRAME)
		{
			if ( generate_jsx )
			{
				fprintf(h,"\t\t\t");
				fprintf(h,"<VisualGroup id=\"%s\" className=\"%s\" value=%s/>\n",
					react_widget_id(iptr),react_element_style(iptr),react_payload(iptr));
			}
			else
			{
				fprintf(h,",\n\t\t\t\t");
				fprintf(h,"this.%s.render()",iptr->Contents.name);
			}
		}
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			return(0);
		else if ( generate_visual_frame )
		{
			fprintf(h,",\n\t\t\t\tthis.%sHost",iptr->Contents.name);
			return(0);
		}
		else if (!( fnptr = abal_payload(iptr) ))
			return(0);
               	else if (!(ffptr = locate_form_control( fnptr ) ))
			return(0);
		/* ------------------- */
		/* its a visual object */
		/* ------------------- */
		else if ( generate_jsx )
		{
			sptr = fnptr;
			c = *(sptr++);
			if ((c >= 'a') && (c <= 'z')) c = ((c - 'a') + 'A');
			fprintf(h,"\t\t\t<div id=\"%s\" className=\"%s\">\n",
				react_widget_id(iptr),react_element_style(iptr));
			fprintf(h,"\t\t\t\t<%c%s name=\"%s\" parameters=%s/>\n",
				c,sptr,react_widget_id(iptr),react_payload_format(iptr));
			fprintf(h,"\t\t\t</div>\n");
			return(0);
		}
		else
		{
			sptr = fnptr;
			c = *(sptr++);
			if ((c >= 'a') && (c <= 'z')) c = ((c - 'a') + 'A');
			fprintf(h,",\n\t\t\t\t");
			fprintf(h,"React.createElement('div',{id:\"%s\",className:\"%s\"},",
				react_widget_id(iptr),react_element_style(iptr),react_payload(iptr));
			fprintf(h,"React.createElement(%c%s,{name:'%s', parameters:%s},null))",
				c,sptr,react_widget_id(iptr),react_payload_format(iptr));
			return(0);
		}
	}
	/* ------------------------------------------------ */
	/* check for overloaded render method using ON SHOW */
	/* ------------------------------------------------ */
	else if ( method_is_valid( iptr->Contents.events->on_show ) )
	{
		if ( generate_jsx )
			fprintf(h,"\t\t\tthis.%sShow()",iptr->Contents.name);
		else	fprintf(h,",\t\t\tthis.%sShow()",iptr->Contents.name);
	}
	/* ------------------------------------------- */
	/* decoration elements are frequent and simple */
	/* ------------------------------------------- */
	else if ( iptr->Contents.style == _WINDOW_FRAME)
	{
		if ( generate_jsx )
		{
			fprintf(h,"\t\t\t<VisualWindow id=\"%s\" className=\"%s\" title=%s/>\n",
				react_widget_id(iptr),
				react_element_style(iptr),
				react_payload(iptr));
		}
		else	
		{
			fprintf(h,",\n\t\t\t\t");
			react_js_element(h,iptr);
		}
	}
	else if ( iptr->Contents.style == _TAB_FRAME)
	{
		if ( generate_jsx )
		{
			fprintf(h,"\t\t\t<VisualTabPage id=\"%s\" className=\"%s\" number=\"%u\" label=%s>\n",
				react_widget_id(iptr),
				react_element_style(iptr),
				iptr->Contents.page,
				react_payload(iptr));
		}
		else	
		{
			fprintf(h,",\n\t\t\t\t");
			react_js_element(h,iptr);
		}
	}
	else if ( iptr->Contents.style == _FILL_FRAME)
	{
		if ( generate_jsx )
		{
			fprintf(h,"\t\t\t<VisualFill id=\"%s\" className=\"%s\"/>\n",
				react_widget_id(iptr),
				react_element_style(iptr));
		}
		else	
		{
			fprintf(h,",\n\t\t\t\t");
			react_js_element(h,iptr);
		}
	}
	else if ( iptr->Contents.style == _IMAGE_FRAME )
	{
		if ( generate_jsx )
		{
			fprintf(h,"\t\t\t<VisualImage id=\"%s\" className=\"%s\" src=%s/>\n",
				react_widget_id(iptr),
				react_element_style(iptr),
				react_payload(iptr));
		}
		else	
		{
			fprintf(h,",\n\t\t\t\t");
			react_js_element(h,iptr);
		}
	}
	else if ( iptr->Contents.style == _TEXT_FRAME )
	{
		if ( generate_jsx )
		{
			fprintf(h,"\t\t\t<VisualText id=\"%s\" className=\"%s\" value=%s/>\n",
				react_widget_id(iptr),
				react_element_style(iptr),
				react_payload(iptr));
		}
		else	
		{
			fprintf(h,",\n\t\t\t\t");
			react_js_element(h,iptr);
		}
	}
	else if ( iptr->Contents.style == _FORM_FRAME )
	{
		if ( generate_jsx )
		{
			fprintf(h,"\t\t\t<VisualTable id=\"%s\" className=\"%s\" name=\"%s\" format={this.%sFmt} titles={this.state.%sTH} data={this.state.%sData}/>\n",
				react_widget_id(iptr),
				react_element_style(iptr),
				iptr->Contents.name,
				iptr->Contents.name,
				iptr->Contents.name);
		}
		else	
		{
			fprintf(h,",\n\t\t\t\t");
			react_js_element(h,iptr);
		}
	}
	else if ( iptr->Contents.style == _EDIT_FRAME )
	{
		if ( generate_jsx )
		{
			fprintf(h,"\t\t\t<VisualEdit id=\"%s\" className=\"%s\" name=\"%s\" change={this.%sChange} value={this.state.%sBuffer}/>\n",
				react_widget_id(iptr),
				react_element_style(iptr),
				iptr->Contents.name,
				iptr->Contents.name,
				iptr->Contents.name);
		}
		else	
		{
			fprintf(h,",\n\t\t\t\t");
			react_js_element(h,iptr);
		}
	}
	else if ( iptr->Contents.style == _SELECT_FRAME )
	{
		if ( generate_jsx )
		{
			fprintf(h,"\t\t\t<VisualSelect id=\"%s\" className=\"%s\" name=\"%s\" change={this.%sChange} value={this.state.%sValue} items=%s/>\n",
				react_widget_id(iptr),
				react_element_style(iptr),
				iptr->Contents.name,
				iptr->Contents.name,
				iptr->Contents.name,
				react_payload(iptr));
		}
		else	
		{
			fprintf(h,",\n\t\t\t\t");
			react_js_element(h,iptr);
		}
	}
	else if ( iptr->Contents.style == _SWITCH_FRAME )
	{
		if ( generate_jsx )
		{
			fprintf(h,"\t\t\t<VisualSwitch id=\"%s\" className=\"%s\" name=\"%s\" change={this.%sChange} value={this.state.%sValue} message=%s/>\n",
				react_widget_id(iptr),
				react_element_style(iptr),
				iptr->Contents.name,
				iptr->Contents.name,
				iptr->Contents.name,
				react_payload(iptr));
		}
		else	
		{
			fprintf(h,",\n\t\t\t\t");
			react_js_element(h,iptr);
		}
	}
	else if ( iptr->Contents.style == _CHECK_FRAME )
	{
		if ( generate_jsx )
		{
			fprintf(h,"\t\t\t<VisualCheck id=\"%s\" className=\"%s\" name=\"%s\" change={this.%sChange} value={this.state.%sValue} message=%s/>\n",
			react_widget_id(iptr),
			react_element_style(iptr),
			iptr->Contents.name,
			iptr->Contents.name,
			iptr->Contents.name,
			react_payload(iptr));
		}
		else	
		{
			fprintf(h,",\n\t\t\t\t");
			react_js_element(h,iptr);
		}
	}
	else if ( iptr->Contents.style == _RADIO_FRAME )
	{
		if ( generate_jsx )
		{
			fprintf(h,"\t\t\t<VisualRadio id=\"%s\" className=\"%s\" name=\"%s\" change:{this.%sChange} value={this.state.%sValue} message=%s/>\n",
				react_widget_id(iptr),
				react_element_style(iptr),
				iptr->Contents.name,
				iptr->Contents.name,
				iptr->Contents.name,
				react_payload(iptr));
		}
		else	
		{
			fprintf(h,",\n\t\t\t\t");
			react_js_element(h,iptr);
		}
	}
	else if ( iptr->Contents.style == _BUTTON_FRAME )
	{
		if ( iptr->Contents.datatype == _WIDGET_VIDEO )
		{
			if ( generate_jsx )
			{
				fprintf(h,"\t\t\t<VisualVideo id=\"%s\" className=\"%s\" name=\"%s\" items=%s/>\n",
					react_widget_id(iptr),
					react_element_style(iptr),
					iptr->Contents.name,
					react_payload(iptr));
			}
			else	
			{
				fprintf(h,",\n\t\t\t\t");
				react_js_element(h,iptr);
			}
		}
		else if ( iptr->Contents.datatype == _WIDGET_AUDIO )
		{
			if ( generate_jsx )
			{
				fprintf(h,"\t\t\t<VisualAudio id=\"%s\" className=\"%s\" name=\"%s\" src=%s/>\n",
					react_widget_id(iptr),
					react_element_style(iptr),
					iptr->Contents.name,
					react_payload(iptr));
			}
			else	
			{
				fprintf(h,",\n\t\t\t\t");
				react_js_element(h,iptr);
			}
		}
		else 	
		{
			if ( generate_jsx )
			{
				if (iptr->Contents.align & 1)
				{
					/* -------------------- */
					/* The ICON PUSH BUTTON */
					/* -------------------- */
					fprintf(h,"\t\t\t<VisualIcon id=\"%s\" className=\"%s\" name=\"%s\" ",
						react_widget_id(iptr),
						react_element_style(iptr),
						iptr->Contents.name);
					fprintf(h,"src=%s action={this.%sEvent} enter={this.%sEnter} leave={this.%sLeave}/>\n",
						react_payload(iptr),
						iptr->Contents.name,
						iptr->Contents.name,
						iptr->Contents.name);
				}
				else
				{
					/* -------------------- */
					/* The TEXT PUSH BUTTON */
					/* -------------------- */
					fprintf(h,"\t\t\t<VisualButton id=\"%s\" className=\"%s\" name=\"%s\" ",
						react_widget_id(iptr),
						react_element_style(iptr),
						iptr->Contents.name);
					fprintf(h,"label=%s action={this.%sEvent} enter={this.%sEnter} leave={this.%sLeave}/>\n",
						react_payload(iptr),
						iptr->Contents.name,
						iptr->Contents.name,
						iptr->Contents.name);
				}
			}
			else	
			{
				fprintf(h,",\n\t\t\t\t");
				react_js_element(h,iptr);
			}
		}
	}

	/* ----------------------------------------------- */
	/* active elements have specialisation derivatives */
	/* ----------------------------------------------- */
	else
	{
		if ( generate_jsx )
			fprintf(h,"\t\t\t<%s/>\n",iptr->Contents.name);
		else	fprintf(h,",this.%s",iptr->Contents.name);
	}
	return(0);
}

/*	-----------------	*/
/*	react_render_form 	*/
/*	-----------------	*/
private	void	react_render_form(FILE *h, struct form_control *fptr)
{
	struct	form_item * iptr;
	for  (  iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
		react_render_widget(h,iptr);
	return;
}

/*	-----------------	*/
/*	react_render_page	*/
/*	-----------------	*/
private	void	react_render_page(FILE *h, struct form_control *fptr,int page)
{
	struct	form_item * iptr;
	for  (  iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
		if ( iptr->Contents.page == page )
			react_render_widget(h,iptr);

	if ( page ) 
	{
		if ( generate_jsx)
			fprintf(h,"</TabPage>");
		else	fprintf(h,"%c",')');
	}
	return;
}

/*	------------------	*/
/*	react_render_pages	*/
/*	------------------	*/
private	void	react_render_pages(FILE *h, struct form_control *fptr)
{
	int	i;
	for ( i=0; i <= fptr->pages; i++ )
		react_render_page(h,fptr,i);
	return;
}


/*      ----------------------------------------------------------      */
/*                  e x p o r t _ r e a c t _ f o r m                   */
/*      ----------------------------------------------------------      */
/*      called from the top level production routiens to generate       */
/*      a react form.                                                   */
/*      ----------------------------------------------------------      */
public  void    export_react_form( 
		FILE * 	h, 
		int restriction, 
		int contextual, 
		int autotrad, 
		char * prodname )
{
        FILE                    *hh;
        int                     withstyle=0;
        char                    * eptr;
        char                    * nptr;
        char                    * pptr;
        char                    * qptr;
	char			* classname;
	char			* databasename;
	char			* databasefile;
	char			* databaseuser;
	char			* databasepass;
        struct  form_control    * fptr;
        struct  forms_method    * mptr;
        struct  form_item       * iptr;
        struct  form_item       * wptr;
        int     i;
	int	c;
	char *	sep;
	char *	sptr;
	char * 	fnptr;
	struct	form_control * ffptr;

	reset_react_nested();
        if (!( fptr = Context.Form ))
                return;
        else if (!( fptr->identifier ))
                return;
        else if (!( nptr = allocate_string( fptr->identifier )))
                return;
        else if (!( pptr = allocate_string( fptr->identifier )))
                return;
        else if (!( pptr = enforce_extension( pptr, JS_EXTENSION )))
                return;
        else if (!( qptr = allocate_string( fptr->identifier )))
                return;
        else if (!( qptr = enforce_extension( qptr, CSS_EXTENSION )))
                return;
	else
	{
		/* -------------------------------------- */
		/* handle the configuration methods first */
		/* -------------------------------------- */
		react_configuration( fptr );

		/* ---------------------------------- */
		/* include any component descriptions */
		/* ---------------------------------- */
		export_react_nested(h, fptr);

		/* -------------------------- */
		/* export the DOM environment */
		/* -------------------------- */
		export_react_dom(h,fptr,pptr,qptr);
		close_production_target(h,prodname);

		/* ---------------------------------------- */
		/* open the css style production target now */
		/* ---------------------------------------- */
		if (!( h = open_production_target(qptr,0)))
		{
			release_react_nested();
			return;
		}

		/* -------------------------- */
		/* export the CSS style class */
		/* -------------------------- */
		export_react_style(h,fptr);
		close_production_target(h,qptr);

		/* ---------------------------------- */
		/* generate the AJAX Button Interface */
		/* ---------------------------------- */
		export_react_ajax_form(fptr);

		/* ----------------------------------------- */
		/* open the javascript production target now */
		/* ----------------------------------------- */
		if (!( h = open_production_target(pptr,0)))
		{
			release_react_nested();
			return;
		}
		else
		{
			fprintf(h, "// ------------------------------------------\n");
			fprintf(h, "// SING REACT Generator : Version %s \n",getpatternversion());
			fprintf(h, "// ------------------------------------------\n");
			fprintf(h, "// Visual Form : %s\n",nptr);
			fprintf(h, "// ------------------------------------------\n");
		}

		/* --------------------------- */
		/* generate the widget classes */
		/* --------------------------- */
                for  (  iptr=fptr->first;
                       	iptr != (struct form_item *) 0;
                        iptr = iptr->next )
			export_react_widget(h, fptr, iptr);

		/* ------------------------------ */
		/* start the component production */
		/* ------------------------------ */
		react_class(h, nptr, "React.Component" );

		/* ------------------- */
		/* construction method */
		/* ------------------- */
		if ( generate_visual_frame )
		{
                	for  (  iptr=fptr->first;
                	       	iptr != (struct form_item *) 0;
                	        iptr = iptr->next )
			{
				if ( iptr->Contents.style != _DATA_FRAME )
					continue;
				else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
					continue;
				else	export_react_oncreate(h,iptr);
			}
		}

		fprintf(h,"// %s Object Constructor \n",nptr);
		fprintf(h,"\tconstructor(props)\n\t{\n");
		fprintf(h,"\t\tsuper(props);\n");
		fprintf(h,"\t\tthis.allowUpdate=false;\n");
		fprintf(h,"\t\tthis.parameters=props.parameters;\n");
		fprintf(h,"\t\tthis.name=props.name;\n");
		bind_react_forms_methods(h,fptr);	
		fprintf(h,"\t\tthis.state = {");
		sep = export_react_forms_members(h,fptr);
                for  (  iptr=fptr->first;
                       	iptr != (struct form_item *) 0;
                        iptr = iptr->next )
		{
			if ( iptr->Contents.style == _EDIT_FRAME )
			{
				fprintf(h,"%s\t\t\t%sBuffer:%s",sep,iptr->Contents.name,react_payload(iptr));
                        	sep = ",\n";
			}
			else if ( iptr->Contents.style == _FORM_FRAME )
			{
				/* -------------------------------------- */
				/* TODO calculate table format and titles */
				/* -------------------------------------- */
				fprintf(h,"%s\t\t\t%sFmt:",sep,iptr->Contents.name);
				react_table_format(h,iptr);
                        	sep = ",\n";
				fprintf(h,"%s\t\t\t%sTH:",sep,iptr->Contents.name);
				react_table_headers(h,iptr);
				fprintf(h,"%s\t\t\t%sData:",sep,iptr->Contents.name);
				react_table_cells(h,iptr);
			}
			else if ( iptr->Contents.style == _BUTTON_FRAME )
			{
				if ( iptr->Contents.datatype == _WIDGET_AJAX )
				{
					fprintf(h,"%s\t\t\t%sError:0",sep,iptr->Contents.name);
                        		sep = ",\n";
				}
			}
			else if (( iptr->Contents.style == _CHECK_FRAME )
			     ||  ( iptr->Contents.style == _RADIO_FRAME )
			     ||  ( iptr->Contents.style == _SWITCH_FRAME )
			     ||  ( iptr->Contents.style == _SELECT_FRAME ))
			{
				fprintf(h,"%s\t\t\t%sValue:0",sep,iptr->Contents.name);
                        	sep = ",\n";
			}
		}
		fprintf(h,"\n\t\t};\n");
                for  (  iptr=fptr->first;
                       	iptr != (struct form_item *) 0;
                        iptr = iptr->next )
		{
			/* ------------------------------------- */
			/* database objects need to be instanced */
			/* ------------------------------------- */
			if ( iptr->Contents.style != _DATA_FRAME )
			{
				/* ---------------------------------- */
				/* instance the bound method pointers */
				/* ---------------------------------- */
				react_js_instance(h,iptr);		

				/* ------------------------------------- */
				/* storage variables for storage widgets */
				/* ------------------------------------- */
				if ( iptr->Contents.style == _EDIT_FRAME )
					react_bind_method(h,iptr->Contents.name,"Change");
				else if (( iptr->Contents.style == _CHECK_FRAME )
				     ||  ( iptr->Contents.style == _RADIO_FRAME )
				     ||  ( iptr->Contents.style == _SWITCH_FRAME )
				     ||  ( iptr->Contents.style == _SELECT_FRAME ))
					react_bind_method(h,iptr->Contents.name,"Change");
				/* ----------------------------- */
				/* widget explicite construction */
				/* ----------------------------- */
				inline_react_constructor(h,iptr);
				continue;
			}
                	else if (( iptr->Contents.align & 0x00FF) == _VGROUP_FRAME)
			{
				react_bind_method(h,iptr->Contents.name,"Focus");
				react_bind_method(h,iptr->Contents.name,"Event");
				fprintf(h,"\t\tthis.%s = new VisualGroup({ id:\"%s\", className:\"%s\", feedback:this.%sFocus, action:this.%sEvent });\n",
					iptr->Contents.name,react_widget_id(iptr),react_element_style(iptr),iptr->Contents.name,iptr->Contents.name );
				inline_react_constructor(h,iptr);
				continue;

			}
			else if (( iptr->Contents.align & 0x00FF) == _VISUAL_FRAME)
			{
				if (!( generate_visual_frame ))
					continue;
                		else if (!( fnptr = abal_payload(iptr) ))
                		        continue;
                		else if (!(ffptr = locate_form_control( fnptr ) ))
                        		continue;
				else
				{
					fprintf(h,"\t\tthis.%sCreate();\n",iptr->Contents.name);
					continue;
				}
			}
			else if (!( classname = resolve_widget_file_class( iptr )))
				continue;
			else
			{
				/* -------------------------------- */
				/* collect the database credentials */
				/* -------------------------------- */
                                if (!( databasename = application_databasename() ))
                                        databasename = "mydatabase";
                                if (!( databasefile = react_payload( iptr ) ))
					databasefile = "mydatafile";
                                if (!( databaseuser = react_user( iptr ) ))
					databaseuser = "myusername";
                                if (!( databasepass = react_pass( iptr ) ))
					databasepass = "mypassword";
				/* --------------------------------------- */
				/* and create the database access instance */
				/* --------------------------------------- */
				c = *classname;
				if ((c >= 'a') && (c <= 'z')) c = ((c - 'a') + 'A');
				react_bind_method(h,iptr->Contents.name,"Notify");
				fprintf(h,"\t\tthis.%s = new %c%s({ name: '%s', notify: this.%sNotify });\n",
					iptr->Contents.name,c,(classname+1),iptr->Contents.name, iptr->Contents.name);

				/* --------------------------------------- */
				/* allow explicite construction to operate */
				/* --------------------------------------- */
				inline_react_constructor(h,iptr);
			}
		}	
		fprintf(h,"\t}\n");

		export_react_forms_methods(h,fptr);	

		/* ------------------------------- */
		/* generate the push button events */
		/* ------------------------------- */
                for  (  iptr=fptr->first;
                       	iptr != (struct form_item *) 0;
                        iptr = iptr->next )
		{
			if ( method_is_valid( iptr->Contents.events->on_show ) )
			{
				fprintf(h,"// %s Overload Render \n",iptr->Contents.name);
				fprintf(h,"\t%sShow()\n\t{\n",iptr->Contents.name);
					expand_react_method(h,iptr->Contents.name,iptr->Contents.events->on_show);
				fprintf(h,"\t}\n");
			}
			if ( iptr->Contents.style == _EDIT_FRAME )
			{
				fprintf(h,"// %s Change Catcher \n",iptr->Contents.name);
				fprintf(h,"\t%sChange(event)\n\t{\n",iptr->Contents.name);
				fprintf(h,"\t\tthis.allowUpdate = true;\n");
				fprintf(h,"\t\tthis.setState({%sBuffer:event.target.value});\n",iptr->Contents.name);
				inline_react_event(h,iptr);
				fprintf(h,"\t}\n");
			}
			if ( iptr->Contents.style == _SELECT_FRAME )
			{
				fprintf(h,"// %s Change Catcher \n",iptr->Contents.name);
				fprintf(h,"\t%sChange(event)\n\t{\n",iptr->Contents.name);
				fprintf(h,"\t\tthis.allowUpdate = true;\n");
				fprintf(h,"\t\tthis.setState({%sValue:event.target.selectedIndex});\n",iptr->Contents.name);
				inline_react_event(h,iptr);
				fprintf(h,"\t}\n");
			}
			else if (( iptr->Contents.style == _CHECK_FRAME )
			     ||  ( iptr->Contents.style == _RADIO_FRAME )
			     ||  ( iptr->Contents.style == _SWITCH_FRAME ))
			{
				fprintf(h,"// %s Change Catcher \n",iptr->Contents.name);
				fprintf(h,"\t%sChange(event)\n\t{\n",iptr->Contents.name);
				fprintf(h,"\t\tthis.allowUpdate = true;\n");
				fprintf(h,"\t\tthis.setState({%sValue:event.target.value});\n",iptr->Contents.name);
				inline_react_event(h,iptr);
				fprintf(h,"\t}\n");
			}
			else if ( iptr->Contents.style == _BUTTON_FRAME )
			{
				// ---------------------
				// BUTTON ONFOCUS METHOD
				// ---------------------
				fprintf(h,"// %s Enter Catcher \n",iptr->Contents.name);
				fprintf(h,"\t%sEnter(event)\n\t{\n",iptr->Contents.name);
				fprintf(h,"\t\tthis.allowUpdate = true;\n");
				if ( method_is_valid( iptr->Contents.events->on_get_focus ) )
					expand_react_method(h,iptr->Contents.name,iptr->Contents.events->on_get_focus);
				fprintf(h,"\t}\n");

				// --------------------
				// AJAX BUTTON COMETHOD
				// --------------------
				if ( iptr->Contents.datatype == _WIDGET_AJAX )
					export_react_ajax_button(h,iptr);

				// ---------------------
				// BUTTON ONEVENT METHOD
				// ---------------------
				fprintf(h,"// %s Event Catcher \n",iptr->Contents.name);
				fprintf(h,"\t%sEvent(event)\n\t{\n",iptr->Contents.name);
				fprintf(h,"\t\tthis.allowUpdate = true;\n");
				// AJAX PREPARATION
				if ( iptr->Contents.datatype == _WIDGET_AJAX )
				{
					fprintf(h,"\t\tvar request='ajax_%s.php?action=%s';\n",fptr->identifier,iptr->Contents.name);
					fprintf(h,"\t\tvar message={form:'%s',widget:'%s',text:null};\n",fptr->identifier,iptr->Contents.name);
					fprintf(h,"\t\tvar action = null;\n");
				}
				// EVENT METHOD BODY
				if ( method_is_valid( iptr->Contents.events->on_event ) )
					expand_react_method(h,iptr->Contents.name,iptr->Contents.events->on_event);
				else	fprintf(h,"\t\talert('%sEvent');\n",iptr->Contents.name);
				// AJAX SEND
				if ( iptr->Contents.datatype == _WIDGET_AJAX )
				{
					fprintf(h,"\t\tthis.%sAjax(request,message,action);\n",iptr->Contents.name);
				}
				fprintf(h,"\t}\n");

				// ---------------------
				// BUTTON ONLOSE  METHOD
				// ---------------------
				fprintf(h,"// %s Leave Catcher \n",iptr->Contents.name);
				fprintf(h,"\t%sLeave(event)\n\t{\n",iptr->Contents.name);
				fprintf(h,"\t\tthis.allowUpdate = true;\n");
				if ( method_is_valid( iptr->Contents.events->on_lose_focus ) )
					expand_react_method(h,iptr->Contents.name,iptr->Contents.events->on_lose_focus);
				fprintf(h,"\t}\n");
			}
			else if ( iptr->Contents.style == _DATA_FRAME )
			{
                		if (( iptr->Contents.align & 0x00FF) == _VGROUP_FRAME)
				{
					fprintf(h,"// %s Focus Catcher \n",iptr->Contents.name);
					fprintf(h,"\t%sFocus(event)\n\t{\n",iptr->Contents.name);
					if ( method_is_valid( iptr->Contents.events->on_get_focus ) )
						expand_react_method(h,iptr->Contents.name,iptr->Contents.events->on_get_focus );
					fprintf(h,"\t}\n");

					fprintf(h,"// %s Event Catcher \n",iptr->Contents.name);
					fprintf(h,"\t%sEvent(event)\n\t{\n",iptr->Contents.name);
					fprintf(h,"\t\tthis.allowUpdate = true;\n");
					if ( method_is_valid( iptr->Contents.events->on_event ) )
						expand_react_method(h,iptr->Contents.name,iptr->Contents.events->on_event );
					fprintf(h,"\t}\n");
				}
				else
				{
					fprintf(h,"// %s Notification Catcher \n",iptr->Contents.name);
					fprintf(h,"\t%sNotify(state)\n\t{\n",iptr->Contents.name);
					fprintf(h,"\t\tthis.allowUpdate = true;\n");
					fprintf(h,"\t\tthis.setState({%s:state});\n",iptr->Contents.name);
					fprintf(h,"\t}\n");
				}
			}
			else if ( method_is_valid( iptr->Contents.events->on_event ) )
			{
				fprintf(h,"// %s Event Catcher \n",iptr->Contents.name);
				fprintf(h,"\t%sEvent(event)\n\t{\n",iptr->Contents.name);
				fprintf(h,"\t\tthis.allowUpdate = true;\n");
					expand_react_method(h,iptr->Contents.name,iptr->Contents.events->on_event);
				fprintf(h,"\t}\n");
			}
		}

		/* ------------------- */
		/* before mount method */
		/* ------------------- */
		fprintf(h,"// %s Before Component Mounts \n",nptr);
		fprintf(h,"\tcomponentWillMount()\n\t{\n");
                for  (  iptr=fptr->first;
                       	iptr != (struct form_item *) 0;
                        iptr = iptr->next )
			inline_react_show(h,iptr);

		fprintf(h,"\t}\n");

		/* ------------------------- */
		/* before receive properties */
		/* ------------------------- */
		if ( 1 > 1 )
		{
		fprintf(h,"\tcomponentWillReceiveProps()\n\t{\n");

		fprintf(h,"\t}\n");
		}

		/* ---------------------- */
		/* test for update method */
		/* ---------------------- */
		fprintf(h,"\tshouldComponentUpdate()\n\t{\n");
		fprintf(h,"\t\tvar v = this.allowUpdate;\n");
		fprintf(h,"\t\tthis.allowUpdate = false;\n");
		fprintf(h,"\t\treturn( v );\n");
		fprintf(h,"\t}\n");

		/* -------------------- */
		/* before update method */
		/* -------------------- */
		if ( 1 > 1 )
		{
			fprintf(h,"// %s Before Component Update \n",nptr);
			fprintf(h,"\tcomponentWillUpdate(nextProps,nextState)\n\t{\n");

			fprintf(h,"\t}\n");
		}

		/* ---------------- */
		/* rendering method */
		/* ---------------- */
		fprintf(h,"// %s Object Renderer \n",nptr);
		fprintf(h,"\trender()\n\t{\n");
			fprintf(h,"\t\treturn(\n");

		if ( generate_jsx )
			fprintf(h,"\t\t\t<div className=\"%s\">\n",nptr);
		else	fprintf(h,"\t\tReact.createElement('div',{className:'%s'}",nptr);

		/* -------------------------------- */
		/* TAB PAGE has different rendering */
		/* -------------------------------- */
		if ( fptr->pages )
			react_render_pages( h, fptr );
		else	react_render_form( h, fptr );

		if ( generate_jsx )
			fprintf(h,"\n\t\t\t</div>\t\t);\n");
		else	fprintf(h,"\n\t\t\t) );\n");
		fprintf(h,"\t}\n");

		/* ------------------ */
		/* after mount method */
		/* ------------------ */
		if ( 1 > 1 )
		{
		fprintf(h,"// %s After Component Mounts \n",nptr);
		fprintf(h,"\tcomponentDidMount()\n\t{\n");

		fprintf(h,"\t}\n");
		}

		/* ------------------- */
		/* after update method */
		/* ------------------- */
		if ( 1 > 1 )
		{
		fprintf(h,"// %s After Component Update \n",nptr);
		fprintf(h,"\tcomponentDidUpdate()\n\t{\n");

		fprintf(h,"\t}\n");
		}

		/* ------------------ */
		/* before destruction */
		/* ------------------ */
		fprintf(h,"// %s Component Destructor \n",nptr);
		fprintf(h,"\tcomponentWillUnmount()\n\t{\n");
                for  (  iptr=fptr->last;
                       	iptr != (struct form_item *) 0;
                        iptr = iptr->previous)
		{
			inline_react_hide(h,iptr);
			export_react_destructor(h,iptr);
		}
		fprintf(h,"\t}\n");

		fprintf(h,"}\n");

		/* ------------------------------- */
		/* start the document object model */
		/* ------------------------------- */
		if  (!( fptr->isoverlay ))
		{
			c = *nptr;
			if ((c >= 'a') && (c <= 'z')) c = ((c - 'a') + 'A');
      			fprintf(h,"\nReactDOM.render(\n");
			if ( generate_jsx )
				fprintf(h,"\t\t<%c%s/>,\n",c,(nptr+1));
			else	fprintf(h,"\t\tReact.createElement(%c%s,null,null),\n",c,(nptr+1));
  			fprintf(h,"\tdocument.getElementById('root_%s'));\n",nptr);
		}

		/* ------------------------------------- */
		/* close the component production stream */
		/* ------------------------------------- */
		close_production_target(h,pptr);

		/* -------------------------------------- */
		/* generate backend AJAX data connections */
		/* -------------------------------------- */
                for  (  sep="\n",iptr=fptr->first;
                       	iptr != (struct form_item *) 0;
                        iptr = iptr->next )
		{
			if ( iptr->Contents.style != _DATA_FRAME )
				continue;
			else if (!( classname = resolve_widget_file_class( iptr )))
				continue;
			else	export_ajax_connector( iptr, classname );
		}

		liberate( pptr );
		liberate( nptr );
		release_react_nested();
		return;
        }
}

#endif  /* _reactform_c */
        /* ------------ */

