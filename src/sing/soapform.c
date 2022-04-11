#ifndef	_soapform_c
#define	_soapform_c

/*	-------------------------------------------	*/
/*	Abal Web Service Program Overlay Generation	*/
/*	-------------------------------------------	*/

public  void	abal_soap_instance( FILE * h, struct form_control * fptr, char * rname )
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	nbuffer[8192];

	abal_widget_constants(h, fptr );
	generate_abal_structure(h,fptr);

	return;

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		switch (( iptr->Contents.style & _FRAME_TYPE )) {
			case	_EDIT_FRAME	:
				sprintf(nbuffer,"%s_%s",rname,iptr->Contents.name);
				abal_dcl(h, nbuffer, "_b", _ABAL_STRING, 256, 0,0, NULL ); 
				break;

			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
			case	_SELECT_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SCROLL_FRAME	:
				sprintf(nbuffer,"%s_%s",rname,iptr->Contents.name);
				abal_dcl(h, nbuffer, "_v", _ABAL_WORD, 2, 0,0, NULL ); 
				break;

			case	_FORM_FRAME	:
				sprintf(nbuffer,"%s_%s",rname,iptr->Contents.name);
				abal_dcl(h, nbuffer, "_b", _ABAL_STRING, 256, 0,0, NULL ); 
				break;

			case	_DATA_FRAME	:
				if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
					continue;
				else if (!( fnptr = abal_payload(iptr) )) 
					continue;
				else if (!(ffptr = locate_form_control( fnptr ) ))
					continue;
				else	{
					sprintf(nbuffer,"%s_%s",rname,iptr->Contents.name);
					abal_soap_instance(h,ffptr,nbuffer);
					continue;
					}
			}
		}
	return;
}

/*	-----------------	*/
/*	Foward Procedures	*/
/*	-----------------	*/
public	int	soap_count_overlay_methods( struct form_control * fptr )
{
	struct	forms_method 	* mptr;
	int	methods=_SOAP_OVL_METHODS;

	if (!( fptr ))	return( _SOAP_OVL_METHODS );

	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->type & _METHOD_PUBLIC ))
			continue;
		else if (!( mptr->type & _METHOD_FUNCTION ))
			continue;
		else	methods++;
		}
	return( methods );
}

public	int	soap_resolve_overlay_method( struct form_control * fptr, int method )
{
	switch ( method ) {
		case	_OVL_PRECONST	: return( _SOAP_OVL_PRECONST ); 
		case	_OVL_POSTDEST	: return( _SOAP_OVL_POSTDEST ); 
		case	_OVL_ONCREATE	: return( _SOAP_OVL_ONCREATE ); 
		case	_OVL_ONREMOVE	: return( _SOAP_OVL_ONREMOVE ); 
		case	_OVL_ONHIDE	: return( _SOAP_OVL_ONHIDE   ); 
		case	_OVL_ONSHOW	: return( _SOAP_OVL_ONSHOW   ); 
		case	_OVL_ONEVENT	: return( _SOAP_OVL_ONEVENT  ); 
		case	_OVL_ONFOCUS	: return( _SOAP_OVL_ONFOCUS  ); 
		case	_OVL_ONEXEC	: return( _SOAP_OVL_ONEXEC   ); 
		case	_OVL_ONATTACH	: return( _SOAP_OVL_ONATTACH ); 
		case	_OVL_ONDETACH	: return( _SOAP_OVL_ONDETACH ); 
		case	_OVL_ONLOSE	: return( _SOAP_OVL_ONLOSE   ); 
		case	_OVL_POSITIONAT	: return( _SOAP_OVL_POSITIONAT ); 
		default			: return(0);
		}
}

public	void	abal_soap_forward( FILE * h, char * hptr, char * nptr, char * pptr, int mode )
{ 
	if ( mode ) {
		/* integer return types */
		/* -------------------- */
		if ( hptr )
			fprintf(h,"Forward Proc %s_%s(%s) : %c",hptr,nptr,pptr,0x0025);
		else	fprintf(h,"Forward Proc %s(%s) : %c",nptr,pptr,0x0025);
		}
	else	{
		/* void return types */
		/* ----------------- */
		if ( hptr )
			fprintf(h,"Forward Proc %s_%s(%s)",hptr,nptr,pptr);
		else	fprintf(h,"Forward Proc %s(%s)",nptr,pptr);
		}

	linefeed(h);
	return;
}

public  void	abal_web_service_forwards( FILE * h )
{
	abal_comment(h,"Visual Object Derived Interface ",0);
	abal_comment(h,"Standard Web Service Interface Methods ",0);
	abal_soap_forward(h,(char*)0,"PreConstruction","ptr o$,ptr a$,ptr b$",1);
	abal_soap_forward(h,(char*)0,"PostDestruction","ptr o$,ptr a$,ptr b$",1);
	abal_soap_forward(h,(char*)0,"OnCreate","ptr o$,ptr b$,bl%",1);
	abal_soap_forward(h,(char*)0,"OnRemove","ptr o$",1);
	abal_soap_forward(h,(char*)0,"OnRequest","ptr o$,XmlName$=256",1);
	abal_soap_forward(h,(char*)0,"OnResponse","ptr o$,XmlName$=256",1);
	abal_soap_forward(h,(char*)0,"OnFault","ptr o$,XmlName$=256",1);
	abal_soap_forward(h,(char*)0,"IsPersistant","ptr o$",1);
	return;
}

public  void	abal_soap_forwards( FILE * h, struct form_control * fptr, char * hptr, char * rname )
{
	struct	form_methods	* mptr;
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	nbuffer[8192];

	/* -------------------------------------- */
	/* Standard Web Service Overlay Signature */
	/* -------------------------------------- */
	abal_web_service_forwards(h);

	abal_soap_forward(h,(char*)0,"OnMember","ptr o$,nl%,ptr prefix$,pl%,ptr t$,tl%",1);
	abal_soap_forward(h,(char*)0,"OnMethod","ptr o$,nl%,ptr prefix$,pl%,ptr t$,tl%",1);
	abal_soap_forward(h,(char*)0,"OnResult","ptr o$,class soap_response pointer SOAP,ptr prefix$,pl%",1);
	abal_soap_forward(h,(char*)0,"OnShow","ptr o$",1);
	abal_soap_forward(h,(char*)0,"OnHide","ptr o$",1);
	abal_soap_forward(h,(char*)0,"OnPositionAt","ptr o$,px%,py%",1);
	abal_soap_forward(h,(char*)0,"OnFocus","ptr o$",1);
	abal_soap_forward(h,(char*)0,"OnLosefocus","ptr o$",1);
	abal_soap_forward(h,(char*)0,"OnEvent","ptr o$",1);

	abal_comment(h,"Visual Object Derived Interface ",0);
	abal_comment(h,"Public Forms Interface Methods ",0);
	abal_forms_method_forward(h,fptr,1);
	return;

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if (method_is_valid( iptr->Contents.events->on_create ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Create");
			abal_soap_forward(h,hptr,nbuffer,"\0",0);
			}
		if (method_is_valid( iptr->Contents.events->on_show ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Show");
			abal_soap_forward(h,hptr,nbuffer,"\0",0);
			}
		if (method_is_valid( iptr->Contents.events->on_get_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Focus");
			abal_soap_forward(h,hptr,nbuffer,"\0",0);
			}
		if (method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"LoseFocus");
			abal_soap_forward(h,hptr,nbuffer,"\0",0);
			}
		if (method_is_valid( iptr->Contents.events->on_event ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Event");
			abal_soap_forward(h,hptr,nbuffer,"\0",0);
			}
		if (method_is_valid( iptr->Contents.events->on_hide ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Hide");
			abal_soap_forward(h,hptr,nbuffer,"\0",0);
			}
		if (method_is_valid( iptr->Contents.events->on_remove) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Remove");
			abal_soap_forward(h,hptr,nbuffer,"\0",0);
			}

		if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	{
			sprintf(nbuffer,"%s_%s",rname,iptr->Contents.name);
			abal_soap_forwards(h,ffptr,hptr,nbuffer);
			continue;
			}
		}
}

/*	-----------------	*/
/*	Method Procedures	*/
/*	-----------------	*/
public	void	abal_soap_procedure( FILE * h, char * hptr, char * nptr )
{
	if ( hptr )
		fprintf(h,"Proc %s_%s()",hptr,nptr);
	else	fprintf(h,"Proc %s()",nptr);
	linefeed(h);
	indent(h,1);
	fprintf(h,"Exit");
	linefeed(h);
	abal_endproc(h);
	linefeed(h);
	return;
}

public  void	abal_soap_procedures( FILE * h, struct form_control * fptr, char * hptr, char * rname )
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	nbuffer[8192];
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if (method_is_valid( iptr->Contents.events->on_create ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Create");
			abal_soap_procedure(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_show ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Show");
			abal_soap_procedure(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_get_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Focus");
			abal_soap_procedure(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"LoseFocus");
			abal_soap_procedure(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_event ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Event");
			abal_soap_procedure(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_hide ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Hide");
			abal_soap_procedure(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_remove) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Remove");
			abal_soap_procedure(h,hptr,nbuffer);
			}

		if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	{
			sprintf(nbuffer,"%s_%s",rname,iptr->Contents.name);
			abal_soap_procedures(h,ffptr,hptr,nbuffer);
			continue;
			}
		}
}

/*	----------------	*/
/*	Method Detection 	*/
/*	----------------	*/
public	void	abal_soap_method( FILE * h, char * hptr, char * nptr, int i )
{
	indent(h,i);
	fprintf(h,"Case %c%s%c :: ",__QUOTE,nptr,__QUOTE);
	fprintf(h,"XmlMethod = %c%s%c",__QUOTE,nptr,__QUOTE);
	linefeed(h);
	return;
}

public  void	abal_soap_methods( FILE * h, struct form_control * fptr, char * hptr, char * rname, int i )
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	nbuffer[8192];

	sprintf(nbuffer,"%s_%s_%s",rname,"On","Show");
	abal_soap_method(h,hptr,nbuffer,i);

	sprintf(nbuffer,"%s_%s_%s",rname,"On","Event");
	abal_soap_method(h,hptr,nbuffer,i);
	

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if (method_is_valid( iptr->Contents.events->on_create ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Create");
			abal_soap_method(h,hptr,nbuffer,i);
			}
		if (method_is_valid( iptr->Contents.events->on_show ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Show");
			abal_soap_method(h,hptr,nbuffer,i);
			}
		if (method_is_valid( iptr->Contents.events->on_get_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Focus");
			abal_soap_method(h,hptr,nbuffer,i);
			}
		if (method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"LoseFocus");
			abal_soap_method(h,hptr,nbuffer,i);
			}
		if (method_is_valid( iptr->Contents.events->on_event ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Event");
			abal_soap_method(h,hptr,nbuffer,i);
			}
		if (method_is_valid( iptr->Contents.events->on_hide ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Hide");
			abal_soap_method(h,hptr,nbuffer,i);
			}
		if (method_is_valid( iptr->Contents.events->on_remove) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Remove");
			abal_soap_method(h,hptr,nbuffer,i);
			}

		if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	{
			sprintf(nbuffer,"%s_%s",rname,iptr->Contents.name);
			abal_soap_methods(h,ffptr,hptr,nbuffer,i);
			continue;
			}
		}
}

/*	----------------	*/
/*	Member Detection 	*/
/*	----------------	*/
public	void	abal_soap_result(FILE * h, char * pname, char * mname, int type )
{
	indent(h,1);
	switch ( type ) {
		case	_ABAL_BYTE	:
		case	_ABAL_WORD	:
		case	_ABAL_LONG	:
			fprintf(h,"SOAP.AddParameter(prefix!%c%s%c;%c %c;%cxsd:integer%c)",
				__QUOTE,pname,__QUOTE,
				__QUOTE,__QUOTE,
				__QUOTE,__QUOTE);
			break;
		case	_ABAL_STRING	:
			fprintf(h,"SOAP.AddParameter(prefix!%c%s%c;%c %c;%cxsd:string%c)",
				__QUOTE,pname,__QUOTE,
				__QUOTE,__QUOTE,
				__QUOTE,__QUOTE);
			break;
		case	_ABAL_BCD	:
			fprintf(h,"SOAP.AddParameter(prefix!%c%s%c;%c %c;%cxsd:float%c)",
				__QUOTE,pname,__QUOTE,
				__QUOTE,__QUOTE,
				__QUOTE,__QUOTE);
			break;
		}
	linefeed(h);
	indent(h,1);
	if ( type == _ABAL_STRING ) {
		fprintf(h,"SOAP.AddText(%s;Len$(%s))",mname,mname);
		}
	else	{
		fprintf(h,"SOAP.AddText(Conv$(%s);Len$(Conv$(%s)))",mname,mname);
		}
	linefeed(h);

	indent(h,1);
		fprintf(h,"SOAP.CloseElement");
		linefeed(h);
	return;
}

/*	-------------------------------------------------------------------	*/
/*	     a b a l _ s o a p _t a b l e _ r e q u e s t   ( h,fptr)		*/
/*	-------------------------------------------------------------------	*/
/*	recovery of table request parameters for Soap Method Request		*/
/*	-------------------------------------------------------------------	*/
private	void	abal_soap_table_request(FILE * h, struct form_item * iptr, char * hptr, char * rname, int i )
{
	int	r;
	int	c;
	char	lbuffer[64];
	char	cbuffer[64];
	char	value[32];
	char *	buffer=(char *) 0;
	int	fh;
	int	fw;
	int 	linelength, nblines,fields,posit;
	int	fieldwidth[_MAX_FORM_FIELDS];

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return;
	else if (!( buffer = allocate( (fields * 16) )))
		return;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;	

	for (	r=0; r < nblines; r ++ ) {
		sprintf(lbuffer,"%u",r+1);
		for ( c=0; c < fields; c++ ) {
			indent(h,i);
			fprintf(h,"Case %c%s_%sr%uc%u%c",__QUOTE,hptr,iptr->Contents.name,r,c,__QUOTE);
			indent(h,i+1);
			linefeed(h);
			abal_form_member_alias(h,iptr,lbuffer,i+1);
			linefeed(h);
			indent(h,i+1);
			fprintf(h,"OnAddToken(");
			sprintf(cbuffer,"%u",c+1);
			abal_macro_column(  h,iptr, cbuffer);
			fprintf(h,",Len(");
			abal_macro_column(  h,iptr, cbuffer);
			fprintf(h,"),XmlToken,XmlSize)");
			linefeed(h);
			}
		}
	return;
}

/*	-------------------------------------------------------------------	*/
/*	     a b a l _ s o a p _t a b l e _ r e s p o n s e ( h,fptr)		*/
/*	-------------------------------------------------------------------	*/
/*	generation of table response parameters for Soap Method Return		*/
/*	-------------------------------------------------------------------	*/
private	void	abal_soap_table_response( FILE * h, struct form_item * iptr, char * hptr, char * rname, int i )
{
	int	r;
	int	c;
	char	lbuffer[64];
	char	pbuffer[2048];
	char	nbuffer[2048];
	char	value[32];
	char *	buffer=(char *) 0;
	int	fh;
	int	fw;
	int 	linelength, nblines,fields,posit;
	int	fieldwidth[_MAX_FORM_FIELDS];

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return;
	else if (!( buffer = allocate( (fields * 16) )))
		return;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;	

	for (	r=0; r < nblines; r ++ ) {
		indent(h,i+1);
		sprintf(lbuffer,"%u",r+1);
		abal_form_member_alias(h,iptr,lbuffer,i+1);
		linefeed(h);
		for ( c=0; c < fields; c++ ) {
			indent(h,i+1);
			sprintf(pbuffer,"_%sr%uc%u",iptr->Contents.name,r,c);
			sprintf(nbuffer,"m%u_%s",c+1,iptr->Contents.name);
			abal_soap_result(h,pbuffer,nbuffer,_ABAL_STRING);
			}
		}
	return;
}

public  void	abal_soap_members( FILE * h, struct form_control * fptr, char * hptr, char * rname, int i, int isout )
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	nbuffer[2048];
	char	pbuffer[2048];
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		switch (( iptr->Contents.style & _FRAME_TYPE )) {
			case	_EDIT_FRAME	:
				if ( isout ) {
					sprintf(pbuffer,"_%s",iptr->Contents.name);
					sprintf(nbuffer,"b_%s",iptr->Contents.name);
					abal_soap_result(h,pbuffer,nbuffer,_ABAL_STRING);
					}
				else	{
					indent(h,i);
					fprintf(h,"Case %c%s_%s%c",__QUOTE,rname,iptr->Contents.name,__QUOTE);
					linefeed(h);
					indent(h,i+1);
					fprintf(h,"OnAddToken(b_%s,Len(b_%s),XmlToken,XmlSize)",
						iptr->Contents.name,iptr->Contents.name);
					linefeed(h);

					}
				break;
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
			case	_SELECT_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SCROLL_FRAME	:
				if ( isout ) {
					sprintf(pbuffer,"_%s",iptr->Contents.name);
					sprintf(nbuffer,"v_%s",iptr->Contents.name);
					abal_soap_result(h,pbuffer,nbuffer,_ABAL_WORD);
					}
				else	{
					indent(h,i);
					fprintf(h,"Case %c%s_%s%c",__QUOTE,rname,iptr->Contents.name,__QUOTE);
					linefeed(h);
					indent(h,i+1);
					fprintf(h,"v_%s = Conv%(XmlToken)",iptr->Contents.name);
					linefeed(h);
					}
				break;
			
			case	_FORM_FRAME	:
				if ( isout ) {
					abal_soap_table_response( h, iptr, rname, iptr->Contents.name,i);
					}
				else	{
					abal_soap_table_request( h, iptr, rname, iptr->Contents.name,i);
					}
				break;
			case	_DATA_FRAME	:
				if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
					continue;
				else if ( isout ) {
					indent(h,2);
					fprintf(h,"Call (m_%s(%u))(o_%s,SOAP,prefix!%c_%s%c,Len$(prefix!%c_%s%c))\n",
						iptr->Contents.name,
						_SOAP_OVL_ONRESULT,
						iptr->Contents.name,
						__QUOTE,iptr->Contents.name,__QUOTE,
						__QUOTE,iptr->Contents.name,__QUOTE);
					linefeed(h);
					continue;
					}
				else if (!( fnptr = abal_payload(iptr) )) 
					continue;
				else if (!(ffptr = locate_form_control( fnptr ) ))
					continue;
				else	{
					continue;
					// This is still to be sorted out TODO
					sprintf(nbuffer,"%s_%s",rname,iptr->Contents.name);
					abal_soap_members(h,ffptr,hptr,nbuffer,i,isout);
					continue;
					}
			}
		}
}

public  void	abal_wipe_soap_members( FILE * h, struct form_control * fptr, char * hptr, char * rname, int i )
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	int			components=0;
	char	nbuffer[2048];
	char	pbuffer[2048];

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		switch (( iptr->Contents.style & _FRAME_TYPE )) {
			case	_EDIT_FRAME	:
					indent(h,i);
					fprintf(h,"Case %c%s_%s%c ",__QUOTE,rname,iptr->Contents.name,__QUOTE);
					linefeed(h);
					indent(h,i+1);
					fprintf(h,"XmlMember = XmlToken"); 
					linefeed(h);
					indent(h,i+1);
					fprintf(h,"b_%s = %c %c",iptr->Contents.name,__QUOTE,__QUOTE);
					linefeed(h);
				break;
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
			case	_SELECT_FRAME	:
			case	_SWITCH_FRAME	:
			case	_SCROLL_FRAME	:
					indent(h,i);
					fprintf(h,"Case %c%s_%s%c",__QUOTE,rname,iptr->Contents.name,__QUOTE);
					linefeed(h);
					indent(h,i+1);
					fprintf(h,"XmlMember = XmlToken"); 
					linefeed(h);
					indent(h,i+1);
					fprintf(h,"v_%s = 0",iptr->Contents.name);
					linefeed(h);
				break;
			
			case	_FORM_FRAME	:
					indent(h,i);
					fprintf(h,"Case %c%s_%s%c ",__QUOTE,rname,iptr->Contents.name,__QUOTE);
					linefeed(h);
					indent(h,i+1);
					fprintf(h,"XmlMember = XmlToken"); 
					linefeed(h);
					indent(h,i+1);
					fprintf(h,"b_%s = %c %c",iptr->Contents.name,__QUOTE,__QUOTE);
					linefeed(h);
				break;
			case	_DATA_FRAME	:
				if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
					continue;
				else if (!( fnptr = abal_payload(iptr) )) 
					continue;
				else if (!(ffptr = locate_form_control( fnptr ) ))
					continue;
				else	{
					components++;
					continue;
					}
			}
		}
	if (!( components )) return;

	indent(h,i); fprintf(h,"Default"); linefeed(h);

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		switch (( iptr->Contents.style & _FRAME_TYPE )) {

			case	_DATA_FRAME	:
				if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
					continue;
				else if (!( fnptr = abal_payload(iptr) )) 
					continue;
				else if (!(ffptr = locate_form_control( fnptr ) ))
					continue;
				else	{
					sprintf(nbuffer,"%s_%s",rname,iptr->Contents.name);
					indent(h,i+1); 
					fprintf(h,"if ( Left(XmlToken,%u) = %c%s%c )",
						strlen(nbuffer),__QUOTE,nbuffer,__QUOTE);
					linefeed(h);
					indent(h,i+2); 
					fprintf(h,"Exit( Call (m_%s(9))(o,XmlHandle,XmlPrefix!%c_%s%c,(PrefixLength+%u),SaveToken,SaveSize) )",iptr->Contents.name,__QUOTE,iptr->Contents.name,__QUOTE,strlen(iptr->Contents.name)+1); 
					linefeed(h);
					indent(h,i+1); 
					fprintf(h,"Endif"); 
					linefeed(h);
					continue;
					}
			}
		}
}

/*	------------------	*/
/*	Service Invocation	*/
/*	------------------	*/
public	void	abal_soap_service( FILE * h, char * hptr, char * nptr, int i )
{
	indent(h,i);
	fprintf(h,"Case %c%s%c :: ",__QUOTE,nptr,__QUOTE);
	fprintf(h,"%s(o)",hptr);
	linefeed(h);
	return;
}

public  void	abal_soap_services( FILE * h, struct form_control * fptr, char * hptr, char * rname, int i )
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	mbuffer[8192];
	char	nbuffer[8192];
	int	components=0;

	sprintf(nbuffer,"%s_%s_%s",rname,"On","Show");
	sprintf(mbuffer,"%s%s","On","Show");
	abal_soap_service(h,mbuffer,nbuffer,i);

	sprintf(nbuffer,"%s_%s_%s",rname,"On","Event");
	sprintf(mbuffer,"%s%s","On","Event");
	abal_soap_service(h,mbuffer,nbuffer,i);

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if (( iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME ) {

			if (method_is_valid( iptr->Contents.events->on_create ) ) {
				sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Create");
				sprintf(mbuffer,"%s%s",iptr->Contents.name,"Create");
				abal_soap_service(h,mbuffer,nbuffer,i);
				}
			if (method_is_valid( iptr->Contents.events->on_show ) ) {
				sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Show");
				sprintf(mbuffer,"%s%s",iptr->Contents.name,"Show");
				abal_soap_service(h,mbuffer,nbuffer,i);
				}
			if (method_is_valid( iptr->Contents.events->on_get_focus ) ) {
				sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Focus");
				sprintf(mbuffer,"%s%s",iptr->Contents.name,"Focus");
				abal_soap_service(h,mbuffer,nbuffer,i);
				}
			if (method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
				sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"LoseFocus");
				sprintf(mbuffer,"%s%s",iptr->Contents.name,"Losefocus");
				abal_soap_service(h,mbuffer,nbuffer,i);
				}
			if (method_is_valid( iptr->Contents.events->on_event ) ) {
				sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Event");
				sprintf(mbuffer,"%s%s",iptr->Contents.name,"Event");
				abal_soap_service(h,mbuffer,nbuffer,i);
				}
			if (method_is_valid( iptr->Contents.events->on_hide ) ) {
				sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Hide");
				sprintf(mbuffer,"%s%s",iptr->Contents.name,"Hide");
				abal_soap_service(h,mbuffer,nbuffer,i);
				}
			if (method_is_valid( iptr->Contents.events->on_remove) ) {
				sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Remove");
				sprintf(mbuffer,"%s%s",iptr->Contents.name,"Remove");
				abal_soap_service(h,mbuffer,nbuffer,i);
				}
			}
		else	components++;
		}

	if (!( components ))	return;

	indent(h,i); fprintf(h,"Default"); linefeed(h);

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if (( iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME )
			continue;
		else if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	{
			sprintf(nbuffer,"%s_%s",rname,iptr->Contents.name);
			indent(h,i+1); 
			fprintf(h,"if ( Left(XmlMethod,%u) = %c%s%c )",
				strlen(nbuffer),__QUOTE,nbuffer,__QUOTE);
			linefeed(h);
			indent(h,i+2); 
			fprintf(h,"Exit( Call (m_%s(10))(o,XmlHandle,XmlPrefix!%c_%s%c,(PrefixLength+%u),SaveToken,SaveSize) )",iptr->Contents.name,__QUOTE,iptr->Contents.name,__QUOTE,strlen(iptr->Contents.name)+1); 
			linefeed(h);
			indent(h,i+1); 
			fprintf(h,"Endif"); 
			linefeed(h);
			continue;
			}
		}
	return;
}

/*	------------------	*/
/*	Service Invocation	*/
/*	------------------	*/
public	void	abal_soap_show( FILE * h, char * hptr, char * nptr, int i )
{
	indent(h,i);
	fprintf(h,"%s(o)",hptr);
	linefeed(h);
	return;
}

public  void	abal_soap_showall( FILE * h, struct form_control * fptr, char * hptr, char * rname, int i )
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	mbuffer[8192];
	char	nbuffer[8192];
	int	components=0;

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if (( iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME ) {

			if (method_is_valid( iptr->Contents.events->on_show ) ) {
				sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Show");
				sprintf(mbuffer,"%s%s",iptr->Contents.name,"Show");
				abal_soap_show(h,mbuffer,nbuffer,i);
				}
			}
		else	components++;
		}

	if (!( components ))	return;

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if (( iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME )
			continue;
		else if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	{
			indent(h,i+1); 
			fprintf(h,"Exit( Call (m_%s(%u))(o) )",
					iptr->Contents.name,
					_SOAP_OVL_ONSHOW );
			linefeed(h);
			continue;
			}
		}
	return;
}

public	void	abal_soap_hide( FILE * h, char * hptr, char * nptr, int i )
{
	indent(h,i);
	fprintf(h,"%s(o)",hptr);
	linefeed(h);
	return;
}

public  void	abal_soap_hideall( FILE * h, struct form_control * fptr, char * hptr, char * rname, int i )
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	mbuffer[8192];
	char	nbuffer[8192];
	int	components=0;

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if (( iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME ) {

			if (method_is_valid( iptr->Contents.events->on_hide ) ) {
				sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Hide");
				sprintf(mbuffer,"%s%s",iptr->Contents.name,"Hide");
				abal_soap_hide(h,mbuffer,nbuffer,i);
				}
			}
		else	components++;
		}

	if (!( components ))	return;

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if (( iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME )
			continue;
		else if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	{
			sprintf(nbuffer,"%s_%s",rname,iptr->Contents.name);
			indent(h,i+1); 
			fprintf(h,"if ( Left(XmlMethod,%u) = %c%s%c )",
				strlen(nbuffer),__QUOTE,nbuffer,__QUOTE);
			linefeed(h);
			indent(h,i+2); 
			fprintf(h,"Exit( Call (m_%s(10))(o,XmlHandle,XmlPrefix!%c_%s%c,(PrefixLength+%u),SaveToken,SaveSize) )",iptr->Contents.name,__QUOTE,iptr->Contents.name,__QUOTE,strlen(iptr->Contents.name)+1); 
			linefeed(h);
			indent(h,i+1); 
			fprintf(h,"Endif"); 
			linefeed(h);
			continue;
			}
		}
	return;
}

public	void	abal_soap_onresult( FILE * h, struct form_control * fptr )
{
	linefeed(h);
	fprintf(h,"Proc OnResult(ptr o$,class soap_response pointer SOAP,ptr prefix$,pl%) : %c",0x0025);
	linefeed(h);
	indent(h,1);
	fprintf(h,"Alter prefix(pl)");
	linefeed(h);
	abal_soap_members( h, fptr,(char *) 0,fptr->identifier,1,1 );
	abal_return(h,"0",1);
	abal_endproc(h);
	return;
}

public	void	abal_file_soapout( FILE * h, struct form_control * fptr )
{
	struct	form_item	*	iptr;
	struct	form_control 	*	ffptr;
	char			*	fnptr;
	
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if (( iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME )
			continue;
		if ( is_file_Widget( iptr ) )
			abal_file_members_soapout( h, iptr );
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	abal_file_soapout( h, ffptr );
	}
	return;
}

public	void	abal_file_soapin( FILE * h, struct form_control * fptr )
{
	struct	form_item	*	iptr;
	struct	form_control 	*	ffptr;
	char			*	fnptr;
	
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if (( iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME )
			continue;
		if ( is_file_Widget( iptr ) )
			abal_file_members_soapin( h, iptr, 3 );
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	abal_file_soapin( h, ffptr );
	}
	return;
}

public	void	abal_file_soapwipe( FILE * h, struct form_control * fptr )
{
	struct	form_item	*	iptr;
	struct	form_control 	*	ffptr;
	char			*	fnptr;
	
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if (( iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME )
			continue;
		if ( is_file_Widget( iptr ) )
			abal_file_members_soapwipe( h, iptr, 2 );
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	abal_file_soapwipe( h, ffptr );
	}
	return;
}

public	void	abal_file_onresult( FILE * h, struct form_control * fptr )
{
	linefeed(h);
	fprintf(h,"Proc OnResult(ptr o$,class soap_response pointer SOAP,ptr prefix$,pl%) : %c",0x0025);
	linefeed(h);
	indent(h,1);
	fprintf(h,"Alter prefix(pl)");
	linefeed(h);

	indent(h,1);
	fprintf(h,"Select XmlMethod");
	linefeed(h);

	abal_file_soapout( h, fptr );

	indent(h,1);
	fprintf(h,"EndSel");
	linefeed(h);

	abal_return(h,"0",1);
	abal_endproc(h);
	return;
}

public	void	abal_soap_onresponse( FILE * h, struct form_control * fptr, char * uptr )
{
	linefeed(h);
	fprintf(h,"Proc OnResponse(ptr o$,XmlName$=256) : %c",0x0025);
	linefeed(h);
	indent(h,1);
		fprintf(h,"soap_response pointer SOAP");
		linefeed(h);
	indent(h,1);
		fprintf(h,"file_output pointer TARGET");
		linefeed(h);
	indent(h,1);
		fprintf(h,"Create SOAP(XmlMethod!%cResponse%c;%c%s%c)",
			__QUOTE,__QUOTE,__QUOTE,uptr,__QUOTE);
		linefeed(h);
	indent(h,1);
		fprintf(h,"SOAP.AddParameter(%cresult%c,%c %c,%cxsd:integer%c)",
			__QUOTE,__QUOTE,
			__QUOTE,__QUOTE,
			__QUOTE,__QUOTE);
		linefeed(h);
	indent(h,1);
		fprintf(h,"SOAP.AddText(Conv$(XmlResult),Len$(Conv$(XmlResult)))");
		linefeed(h);
	indent(h,1);
		fprintf(h,"SOAP.CloseElement");
		linefeed(h);

	indent(h,1);
		fprintf(h,"OnResult(o,SOAP,%c%s%c,%u)",__QUOTE,fptr->identifier,__QUOTE,strlen( fptr->identifier ));
		linefeed(h);

	indent(h,1);
		fprintf(h,"Create TARGET(XmlName)");
		linefeed(h);
	indent(h,1);
		fprintf(h,"SOAP.Serialize(TARGET)");
		linefeed(h);
	indent(h,1);
		fprintf(h,"Remove TARGET");
		linefeed(h);
	indent(h,1);
		fprintf(h,"Remove SOAP");
		linefeed(h);
	abal_return(h,"0",1);
	abal_endproc(h);
	return;
}

public	void	abal_file_onresponse( FILE * h, struct form_control * fptr, char * uptr )
{
	linefeed(h);
	fprintf(h,"Proc OnResponse(ptr o$,XmlName$=256) : %c",0x0025);
	linefeed(h);
	indent(h,1);
		fprintf(h,"soap_response pointer SOAP");
		linefeed(h);
	indent(h,1);
		fprintf(h,"file_output pointer TARGET");
		linefeed(h);
	indent(h,1);
		fprintf(h,"Create SOAP(XmlMethod!%cResponse%c;%c%s%c)",
			__QUOTE,__QUOTE,__QUOTE,uptr,__QUOTE);
		linefeed(h);

	indent(h,1);
		fprintf(h,"OnResult(o,SOAP,%c%s%c,%u)",__QUOTE,"tns:",__QUOTE,strlen( "tns:" ));
		linefeed(h);

	indent(h,1);
		fprintf(h,"Create TARGET(XmlName)");
		linefeed(h);
	indent(h,1);
		fprintf(h,"SOAP.Serialize(TARGET)");
		linefeed(h);
	indent(h,1);
		fprintf(h,"Remove TARGET");
		linefeed(h);
	indent(h,1);
		fprintf(h,"Remove SOAP");
		linefeed(h);
	abal_return(h,"0",1);
	abal_endproc(h);
	return;
}

public	int	abal_open_web_service( FILE * h, struct form_control * fptr )
{
	int	holder;
	/* ------------------------------------------------------- */
	/* establish configuration for abal web service production */
	/* ------------------------------------------------------- */
	holder = set_variable_macros(_GENERATE_BAL);
	reset_abal_config();
	set_abal_config_overlay(fptr->isoverlay);
	set_abal_config_program(fptr->isprogram);
	set_abal_config_name("On");

	/* ------------------------------------------------------- */
	/* start production of the abal web service program header */
	/* ------------------------------------------------------- */
	abal_comment(h,"web service overlay for php/soap",0);
	abal_include(h,"pragmas.as");
	abal_pragmas(h,fptr );
	abal_use(h,"soap.apl");
	abal_program(h,fptr->identifier);

	/* ------------------------------------------------- */
	/* global variables and web service control memebers */
	/* ------------------------------------------------- */
	abal_dcl(h,"Response","File",_ABAL_STRING,1024,0,0,NULL);
	abal_dcl(h,"Client","Redirect",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"Xml","Punctuation",_ABAL_STRING,36,0,0,NULL);
	abal_dcl(h,"Xml","Prefix",_ABAL_STRING,1024,0,0,NULL);
	abal_dcl(h,"Prefix","Length",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"Save","Token",_ABAL_STRING,1024,0,0,NULL);
	abal_dcl(h,"Save","Size",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"Xml","Method",_ABAL_STRING,1024,0,0,NULL);
	abal_dcl(h,"XmlFile","Method",_ABAL_STRING,1024,0,0,NULL);
	abal_dcl(h,"XmlFile","Item",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"Xml","Member",_ABAL_STRING,1024,0,0,NULL);
	abal_dcl(h,"Xml","Result",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"Xml","Buffer",_ABAL_STRING,1024,0,0,NULL);
	indent(h,1); fprintf(h,"Field=m,XmlBuffer"); linefeed(h);
	abal_dcl(h,"Xml","Type",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"Xml","Size",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"Xml","Token",_ABAL_STRING,1020,0,0,NULL);
	indent(h,1); fprintf(h,"Field=m"); linefeed(h);
	abal_dcl(h,"Xml","Status",_ABAL_WORD,2,0,0,NULL);
	abal_dcl(h,"Xml","Handle",_ABAL_WORD,2,0,0,NULL);
	abal_argv_control(h,fptr);
	abal_soap_instance(h,fptr,fptr->identifier);

	return( holder );
}

public	int	abal_close_web_service( FILE * h, struct form_control * fptr, int holder )
{
	linefeed(h);
	fprintf(h,"Proc OnFault(ptr o$,XmlName$=256) : %c",0x0025);
	linefeed(h);
	abal_endproc(h);

	linefeed(h);
	fprintf(h,"Proc IsPersistant(ptr o$) : %c",0x0025);
	linefeed(h);
		indent(h,1);
		fprintf(h,"Exit(1)");
	linefeed(h);
	abal_endproc(h);

	/* ------------------------------------------------------- */
	/* close production of the abal web service program footer */
	/* ------------------------------------------------------- */
	abal_segment(h,"0");
	fprintf(h,"Pause %cWeb Service Abal : Generated by Sing%c",__QUOTE,__QUOTE);
	linefeed(h);
	abal_endseg(h,"0");
	abal_end(h,0);

	holder=set_variable_macros(holder);
	return( holder );
}

public	void	abal_soap_preconstruction( FILE * h )
{
	/* -------------------------------------- */
	/* The Web Service PreConstruction Method */
	/* -------------------------------------- */
	linefeed(h);
	fprintf(h,"Proc PreConstruction(ptr o$,ptr a$,ptr b$) : %c ",0x0025);
	linefeed(h);
		indent(h,1); fprintf(h,"Dcl i%,j%"); 		linefeed(h);
		indent(h,1); fprintf(h,"InitGlobal"); 		linefeed(h);
		indent(h,1); fprintf(h,"j = 0"); 		linefeed(h);
		indent(h,1); fprintf(h,"For i = /21 to /2F"); 	linefeed(h);
		indent(h,1); fprintf(h,"Gosub &punctuate");	linefeed(h);
		indent(h,1); fprintf(h,"Next i"); 		linefeed(h);
		indent(h,1); fprintf(h,"For i = /3A to /3F"); 	linefeed(h);
		indent(h,1); fprintf(h,"Gosub &punctuate");	linefeed(h);
		indent(h,1); fprintf(h,"Next i"); 		linefeed(h);
		indent(h,1); fprintf(h,"For i = /5B to /5F"); 	linefeed(h);
		indent(h,1); fprintf(h,"Gosub &punctuate");	linefeed(h);
		indent(h,1); fprintf(h,"Next i"); 		linefeed(h);
		indent(h,1); fprintf(h,"For i = /7B to /7E"); 	linefeed(h);
		indent(h,1); fprintf(h,"Gosub &punctuate");	linefeed(h);
		indent(h,1); fprintf(h,"Next i"); 		linefeed(h);
		indent(h,1); fprintf(h,"Exit(0)");			linefeed(h);
		fprintf(h,"&punctuate");			linefeed(h);
		indent(h,1); fprintf(h,"j += 1");		linefeed(h);
		indent(h,1); fprintf(h,"XmlPunctuation = Includ(j,Chr$(i))");
								linefeed(h);
		indent(h,1); fprintf(h,"Return");		linefeed(h);
	abal_endproc(h);
	return;
}

public	void	abal_soap_postdestruction( FILE * h )
{
	/* -------------------------------------- */
	/* The Web Service PostDestruction Method */
	/* -------------------------------------- */
	linefeed(h);
	fprintf(h,"Proc PostDestruction(ptr o$,ptr a$,ptr b$) : %c ",0x0025);
	linefeed(h);
	abal_endproc(h);
	return;
}

public	void	abal_onaddtoken(FILE * h)
{
	/* ---------------------------------------- */
	/* The Web Service Visual WebHost Interface */
	/* ---------------------------------------- */
	fprintf(h,"Proc OnAddToken(ptr r$, rl%c, ptr s$, sl%c)",0x0025,0x0025);
	linefeed(h);
		indent(h,1); 	fprintf(h,"Alter r(rl)");			linefeed(h);
		indent(h,1); 	fprintf(h,"Alter s(sl)");			linefeed(h);
		indent(h,1); 	fprintf(h,"if (Len$(r)=0)");			linefeed(h);
		indent(h,2); 	fprintf(h,"r = Left(s,sl)");			linefeed(h);
		indent(h,1);	fprintf(h,"Else"); 				linefeed(h);
		indent(h,2); 	fprintf(h,"if ((sl = 1) ");	
			     	fprintf(h,"and (Index(XmlPunctuation,Left(s,sl)) <> 0))");
			     	linefeed(h);
		indent(h,3); 	fprintf(h,"r = Print(($,?$),((sl)),r,s)");	linefeed(h);
		indent(h,2);	fprintf(h,"Else");	 			linefeed(h);
		indent(h,3);	fprintf(h,"r = Print(($,X,?$),((sl)),r,s)");	linefeed(h);
		indent(h,2);	fprintf(h,"Endif"); 				linefeed(h);
		indent(h,1);	fprintf(h,"Endif"); 				linefeed(h);
	fprintf(h,"EndProc");
	linefeed(h);
	return;
}


public	void	abal_web_service( FILE * h, struct form_control * fptr, char * nptr, char* hptr )
{
	int	holder;

	holder = abal_open_web_service(h,fptr);

	/* ----------------------------------------------- */
	/* the format specific host and forward prototypes */
	/* ----------------------------------------------- */
	abal_soap_forwards( h, fptr,(char*)0, fptr->identifier );
	abal_form_body(h,fptr);
	abal_command_line(h,fptr);
	abal_oncreate_methods( h,fptr );
	abal_onevent_methods( h,fptr );
	abal_onlose_methods( h, fptr, __abal_method_lose_focus, 1 );
	abal_onget_methods( h,fptr, __abal_method_get_focus );
	abal_onshow_methods( h,fptr );
	abal_onhide_methods( h,fptr, __abal_method_hide );
	abal_onremove_methods( h,fptr );

	/* abal_soap_procedures( h, fptr,(char *) 0,fptr->identifier ); */

	/* -------------------------------------- */
	/* The Web Service PreConstruction Method */
	/* -------------------------------------- */
	abal_soap_preconstruction(h);

	/* -------------------------------------- */
	/* The Web Service PostDestruction Method */
	/* -------------------------------------- */
	abal_soap_postdestruction(h);

	/* ----------------------------------- */
	/* The Web Service Construction Method */
	/* ----------------------------------- */
	linefeed(h);
	fprintf(h,"Proc OnCreate(ptr o$,ptr b$,bl%c) : %c ",0x0025,0x0025);
	linefeed(h);
	abal_widget_construction( h, fptr );
	abal_endproc(h);

	/* ---------------------------------- */
	/* The Web Service Destruction Method */
	/* ---------------------------------- */
	linefeed(h);
	fprintf(h,"Proc OnRemove(ptr o$) : %c ",0x0025);
	abal_widget_destruction( h, fptr );
	linefeed(h);
	abal_endproc(h);

	/* -------------------------------- */
	/* The Web Service Visual Interface */
	/* -------------------------------- */
	linefeed(h);
	fprintf(h,"Proc OnShow(ptr o$) : %c",0x0025);
	linefeed(h);
	abal_soap_showall(h,fptr,(char *) 0,fptr->identifier,4 );
	linefeed(h);
	abal_endproc(h);

	linefeed(h);
	fprintf(h,"Proc OnHide(ptr o$) : %c",0x0025);
	linefeed(h);
	abal_soap_hideall(h,fptr,(char *) 0,fptr->identifier,4  );
	linefeed(h);
	abal_endproc(h);

	linefeed(h);
	fprintf(h,"Proc OnFocus(ptr o$) : %c",0x0025);
	linefeed(h);
	abal_endproc(h);

	linefeed(h);
	fprintf(h,"Proc OnPositionAt(ptr o$,px%,py%) : %c",0x0025);
	linefeed(h);
	abal_endproc(h);

	linefeed(h);
	fprintf(h,"Proc OnLosefocus(ptr o$) : %c",0x0025);
	linefeed(h);
	abal_endproc(h);

	linefeed(h);
	fprintf(h,"Proc OnEvent(ptr o$) : %c",0x0025);
	linefeed(h);
	abal_endproc(h);

	abal_onaddtoken(h);

	linefeed(h);
	fprintf(h,"Proc OnMember(ptr o$,nl%c,ptr prefix$,pl%c,ptr token$,tl%c) : %c",0x0025,0x0025,0x0025,0x0025);
	linefeed(h);
		indent(h,1); fprintf(h,"if ( nl <> 0 )"); linefeed(h);
		indent(h,2); fprintf(h,"XmlHandle = nl"); linefeed(h);
		indent(h,2); fprintf(h,"Alter prefix(pl)"); linefeed(h);
		indent(h,2); fprintf(h,"XmlPrefix = prefix"); linefeed(h);
		indent(h,2); fprintf(h,"PrefixLength = pl"); linefeed(h);
		indent(h,2); fprintf(h,"Alter  token(tl)"); linefeed(h);
		indent(h,2); fprintf(h,"XmlToken = token"); linefeed(h);
		indent(h,2); fprintf(h,"XmlSize  = tl"); linefeed(h);
		indent(h,2); fprintf(h,"XmlType  = 1"); linefeed(h);
		indent(h,2); fprintf(h,"SaveToken = token"); linefeed(h);
		indent(h,2); fprintf(h,"SaveSize  = tl"); linefeed(h);
		indent(h,2); fprintf(h,"XmlMember = XmlToken"); linefeed(h);
		indent(h,2); fprintf(h,"if ( Index(XmlToken,prefix) = 1 )");linefeed(h);
		indent(h,3); fprintf(h,"XmlToken=Includ(1,Space(pl))");linefeed(h);
		indent(h,3); fprintf(h,"XmlToken=Shl(XmlToken)");linefeed(h);
		indent(h,3); fprintf(h,"XmlToken = Insert(1,%c%s%c)",__QUOTE,fptr->identifier,__QUOTE);linefeed(h);
		indent(h,2); fprintf(h,"Endif");linefeed(h);
		indent(h,2); fprintf(h,"Select XmlToken"); linefeed(h);
			abal_wipe_soap_members( h, fptr,(char *) 0,fptr->identifier,2 );
		indent(h,2); fprintf(h,"EndSel ;**  XmlToken"); linefeed(h);
		indent(h,2); fprintf(h,"Do"); linefeed(h);
		indent(h,3); fprintf(h,"Read=XmlHandle,/60,0:Next,XmlStatus,XmlBuffer"); linefeed(h);
		indent(h,3); fprintf(h,"if ( XmlStatus <> 0 )");
		indent(h,4); fprintf(h,"XmlMember = %c %c",__QUOTE,__QUOTE); linefeed(h);
		indent(h,4); fprintf(h,"Exit( XmlStatus )"); linefeed(h);
		indent(h,3); fprintf(h,"Endif"); linefeed(h);
		indent(h,3); fprintf(h,"Select XmlType"); linefeed(h);
		indent(h,3); fprintf(h,"Case 1,4;** open or close tag"); linefeed(h);
		indent(h,4); fprintf(h,"XmlMember = %c %c",__QUOTE,__QUOTE); linefeed(h);
		indent(h,4); fprintf(h,"Exit(0)"); linefeed(h);
		indent(h,3); fprintf(h,"Case 5 ;** tag data"); linefeed(h);
		indent(h,4); fprintf(h,"Select XmlMember"); linefeed(h);
			abal_soap_members( h, fptr,(char *) 0,fptr->identifier,4,0 );
		indent(h,4); fprintf(h,"EndSel ;**  XmlMember"); linefeed(h);
		indent(h,3); fprintf(h,"EndSel ;**  XmlType"); linefeed(h);
		indent(h,2); fprintf(h,"Loop"); linefeed(h);
		indent(h,1); fprintf(h,"Endif"); linefeed(h);
	abal_endproc(h);
	linefeed(h);

	linefeed(h);
	fprintf(h,"Proc OnMethod(ptr o$,nl%c,ptr prefix$,pl%c,ptr token$,tl%) : %c",0x0025,0x0025,0x0025,0x0025);
	linefeed(h);
		indent(h,1); fprintf(h,"if ( nl <> 0 )"); linefeed(h);
		indent(h,2); fprintf(h,"XmlHandle = nl"); linefeed(h);
		indent(h,2); fprintf(h,"Alter prefix(pl)"); linefeed(h);
		indent(h,2); fprintf(h,"Alter token(tl)"); linefeed(h);
		indent(h,2); fprintf(h,"XmlPrefix = prefix"); linefeed(h);
		indent(h,2); fprintf(h,"PrefixLength = pl"); linefeed(h);
		indent(h,2); fprintf(h,"XmlMethod = token"); linefeed(h);
		indent(h,2); fprintf(h,"SaveToken = XmlMethod"); linefeed(h);
		indent(h,2); fprintf(h,"SaveSize  = Len$(XmlMethod)"); linefeed(h);
		indent(h,2); fprintf(h,"if ( Index(XmlMethod,prefix) = 1 )");linefeed(h);
		indent(h,3); fprintf(h,"XmlMethod=Includ(1,Space(pl))");linefeed(h);
		indent(h,3); fprintf(h,"XmlMethod=Shl(XmlMethod)");linefeed(h);
		indent(h,3); fprintf(h,"XmlMethod = Insert(1,%c%s%c)",__QUOTE,fptr->identifier,__QUOTE);linefeed(h);
		indent(h,3); fprintf(h,"Select XmlMethod"); linefeed(h);
			abal_soap_services( h, fptr,(char *) 0,fptr->identifier,4 );
		indent(h,3); fprintf(h,"EndSel ;**  XmlMethod"); linefeed(h);
		indent(h,2); fprintf(h,"Endif");linefeed(h);
		indent(h,1); fprintf(h,"Endif"); linefeed(h);
		abal_endproc(h);

	/* ---------------------------------- */
	/* The Web Service Web Host Interface */
	/* ---------------------------------- */
	linefeed(h);
	fprintf(h,"Proc OnRequest(ptr o$,XmlName$=256) : %c",0x0025);
	linefeed(h);
		indent(h,1); fprintf(h,"XmlResult = 0"); linefeed(h);
		indent(h,1); fprintf(h,"XmlMethod = %c %c",__QUOTE,__QUOTE); linefeed(h);
		indent(h,1); fprintf(h,"XmlMember = %c %c",__QUOTE,__QUOTE); linefeed(h);
		indent(h,1); fprintf(h,"XmlHandle = Event(77)"); linefeed(h);
		indent(h,1); fprintf(h,"if ( XmlHandle <> 0 )"); linefeed(h);
		indent(h,2); fprintf(h,"Assign=XmlHandle,XmlName,XML:Next,XmlStatus"); linefeed(h);
		indent(h,2); fprintf(h,"if ( XmlStatus = 0 )"); linefeed(h);
		indent(h,3); fprintf(h,"Open=XmlHandle:Next,XmlStatus"); linefeed(h);
		indent(h,3); fprintf(h,"if ( XmlStatus = 0 )"); linefeed(h);
		indent(h,4); fprintf(h,"Do"); linefeed(h);
		indent(h,5); fprintf(h,"Read=XmlHandle,/60,0:Next,XmlStatus,XmlBuffer"); linefeed(h);
		indent(h,5); fprintf(h,"if ( XmlStatus <> 0 ) :: Break :: Endif"); linefeed(h);
		indent(h,5); fprintf(h,"Select XmlType"); linefeed(h);
		indent(h,5); fprintf(h,"Case 1 ;** open tag"); linefeed(h);
		indent(h,6); fprintf(h,"if ( Len$(XmlMethod) = 0 )"); linefeed(h);
		indent(h,7); fprintf(h,"Select XmlToken"); linefeed(h);
			abal_soap_methods( h, fptr,(char *) 0,fptr->identifier,7 );
		indent(h,7); fprintf(h,"EndSel ;**  XmlToken"); linefeed(h);
		indent(h,6); fprintf(h,"Else   ;**  XmlMethod"); linefeed(h);
		indent(h,7); fprintf(h,"OnMember(o,XmlHandle,%c%s%c,%u,XmlToken,XmlSize)",__QUOTE,fptr->identifier,__QUOTE,strlen(fptr->identifier)); linefeed(h);
		indent(h,6); fprintf(h,"Endif  ;**  XmlMethod"); linefeed(h);
		indent(h,5); fprintf(h,"EndSel ;**  XmlType"); linefeed(h);
		indent(h,4); fprintf(h,"Loop"); linefeed(h);
		indent(h,4); fprintf(h,"Event(77) = XmlHandle"); linefeed(h);
		indent(h,7); fprintf(h,"OnMethod(o,XmlHandle,%c%s%c,%u,XmlMethod,Len$(XmlMethod))",__QUOTE,fptr->identifier,__QUOTE,strlen(fptr->identifier)); linefeed(h);
		indent(h,3); fprintf(h,"Endif"); linefeed(h);
		indent(h,2); fprintf(h,"Endif"); linefeed(h);
		indent(h,1); fprintf(h,"Endif"); linefeed(h);
	abal_endproc(h);

	abal_soap_onresult(h,fptr);
	abal_soap_onresponse(h,fptr,hptr);

	holder = abal_close_web_service(h,fptr,holder);

	return;
}

public	int	php_generate_abal( struct form_control * fptr, char * hptr, char* nptr )
{
	FILE * h;

	if (!( h = open_production_target( nptr,0 ) )) 
		return(46);
	else	{
		abal_web_service( h, fptr, nptr, hptr );
		close_production_target(h,nptr);
		return(0);
		}
}

public	void	php_translate_abal( struct form_control * fptr, char* nptr, int autotrad )
{
	translate_abal(1,nptr,autotrad,NULL);
}

	/* ----------- */
#endif	/* _soapform_c */
	/* ----------- */

