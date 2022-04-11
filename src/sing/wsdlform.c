#ifndef	_wsdlform_c
#define	_wsdlform_c

private	char * 	wsdl_service_program=(char *) 0;

public  void	wsdl_open_message( FILE * h, char * mptr )
{
	fprintf(h,"\t<wsdl:message xmlns:wsdl=\"http://www.w3.org/2005/08/wsdl\" name=\"%s\">\n",mptr);
}

public  void	wsdl_part( FILE * h, char * mptr, char * tptr )
{
	fprintf(h,"\t\t<wsdl:part xmlns:wsdl=\"http://www.w3.org/2005/08/wsdl\" name=\"%s\" type=\"xsd:%s\"/>\n",mptr,tptr);
}

public  void	wsdl_close_message( FILE * h )
{
	fprintf(h,"\t</wsdl:message>\n");
}

private	void	wsdl_interface( FILE * h, char * nptr)
{
	fprintf(h,"\t<wsdl:interface xmlns:wsdl=\"http://www.w3.org/2005/08/wsdl\" name=\"%s\">\n",nptr);

		fprintf(h,"\t\t<wsdl:operation xmlns:wsdl=\"http://www.w3.org/2005/08/wsdl\" name=\"%s\">\n",nptr);
			fprintf(h,"\t\t\t<wsdl:input xmlns:wsdl=\"http://www.w3.org/2005/08/wsdl\" name=\"%sIn\"/>\n",nptr);
			fprintf(h,"\t\t\t<wsdl:input xmlns:wsdl=\"http://www.w3.org/2005/08/wsdl\" name=\"%sOut\"/>\n",nptr);
			fprintf(h,"\t\t\t<wsdl:fault xmlns:wsdl=\"http://www.w3.org/2005/08/wsdl\" name=\"Fault\"/>\n",nptr);
		fprintf(h,"\t\t</wsdl:operation>\n");
	fprintf(h,"\t</wsdl:interface>\n");
	return;
}

public  void	wsdl_form_interfaces( FILE * h, struct form_control * fptr, char * rname )
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	nbuffer[8192];

	sprintf(nbuffer,"%s_%s_%s",rname,"On","Show");
	wsdl_interface(h,nbuffer);
	sprintf(nbuffer,"%s_%s_%s",rname,"On","Event");
	wsdl_interface(h,nbuffer);

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if (method_is_valid( iptr->Contents.events->on_create ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Create");
			wsdl_interface(h,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_show ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Show");
			wsdl_interface(h,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_get_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Focus");
			wsdl_interface(h,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"LoseFocus");
			wsdl_interface(h,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_event ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Event");
			wsdl_interface(h,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_hide ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Hide");
			wsdl_interface(h,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_remove) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Remove");
			wsdl_interface(h,nbuffer);
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
			wsdl_form_interfaces(h,ffptr,nbuffer);
			continue;
			}
		}
	return;
}

private	void	wsdl_service( FILE * h,char * hptr, char * nptr)
{
	server_webservice_record(nptr,wsdl_service_program);
	fprintf(h,"\t<wsdl:service xmlns:wsdl=\"http://www.w3.org/2005/08/wsdl\" name=\"%s\">\n",nptr);
		fprintf(h,"\t\t<wsdl:endpoint xmlns:wsdl=\"http://www.w3.org/2005/08/wsdl\" name=\"%s\" binding=\"tns:%s\">\n",nptr,nptr);
			fprintf(h,"\t\t\t<soap:address location=\"%s/%s\"/>\n",hptr,nptr);
		fprintf(h,"\t\t</wsdl:endpoint>\n");
	fprintf(h,"\t</wsdl:service>\n");
}

private	void	wsdl_binding( FILE * h,char * hptr, char * nptr)
{
	fprintf(h,"\t<wsdl:binding xmlns:wsdl=\"http://www.w3.org/2005/08/wsdl\" name=\"%s\">\n",nptr);
		fprintf(h,"\t\t<soap:binding style=\"rpc\" transport=\"http://schemas.xmlsoap.org/soap/http\"/>\n");
		fprintf(h,"\t\t<wsdl:operation xmlns:wsdl=\"http://www.w3.org/2005/08/wsdl\" name=\"%s\">\n",nptr);
			fprintf(h,"\t\t\t<soap:operation soapAction=\"%s/%s\" style=\"rpc\"/>\n",hptr,nptr);
			fprintf(h,"\t\t\t<input>\n");
				fprintf(h,"\t\t\t\t<soap:body use=\"encoded\"/>\n");
			fprintf(h,"\t\t\t</input>\n");
			fprintf(h,"\t\t\t<output>\n");
				fprintf(h,"\t\t\t\t<soap:body use=\"encoded\"/>\n");
			fprintf(h,"\t\t\t</output>\n");
			fprintf(h,"\t\t\t<fault>\n");
				fprintf(h,"\t\t\t\t<soap:body use=\"encoded\"/>\n");
			fprintf(h,"\t\t\t</fault>\n");
		fprintf(h,"\t\t</wsdl:operation>\n");
	fprintf(h,"\t</wsdl:binding>\n");
	return;
}

public  void	wsdl_form_bindings( FILE * h, struct form_control * fptr, char * hptr, char * rname )
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	nbuffer[8192];

	sprintf(nbuffer,"%s_%s_%s",rname,"On","Show");
	wsdl_binding(h,hptr,nbuffer);
	sprintf(nbuffer,"%s_%s_%s",rname,"On","Event");
	wsdl_binding(h,hptr,nbuffer);

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if (method_is_valid( iptr->Contents.events->on_create ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Create");
			wsdl_binding(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_show ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Show");
			wsdl_binding(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_get_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Focus");
			wsdl_binding(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"LoseFocus");
			wsdl_binding(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_event ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Event");
			wsdl_binding(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_hide ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Hide");
			wsdl_binding(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_remove) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Remove");
			wsdl_binding(h,hptr,nbuffer);
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
			wsdl_form_bindings(h,ffptr,hptr,nbuffer);
			continue;
			}
		}
}

public  void	wsdl_form_services( FILE * h, struct form_control * fptr, char * hptr, char * rname )
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	nbuffer[8192];

	sprintf(nbuffer,"%s_%s_%s",rname,"On","Show");
	wsdl_service(h,hptr,nbuffer);
	sprintf(nbuffer,"%s_%s_%s",rname,"On","Event");
	wsdl_service(h,hptr,nbuffer);

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if (method_is_valid( iptr->Contents.events->on_create ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Create");
			wsdl_service(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_show ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Show");
			wsdl_service(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_get_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Focus");
			wsdl_service(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"LoseFocus");
			wsdl_service(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_event ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Event");
			wsdl_service(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_hide ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Hide");
			wsdl_service(h,hptr,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_remove) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Remove");
			wsdl_service(h,hptr,nbuffer);
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
			wsdl_form_services(h,ffptr,hptr,nbuffer);
			continue;
			}
		}
}

public  void	wsdl_form_messages( FILE * h, struct form_control * fptr, char * rname )
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	nbuffer[8192];

	sprintf(nbuffer,"%s_%s_%s",rname,"On","Show");
	wsdl_open_message(h,nbuffer);
	wsdl_part(h,"object","string");
	wsdl_close_message(h);
	sprintf(nbuffer,"%s_%s_%s",rname,"On","Event");
	wsdl_open_message(h,nbuffer);
	wsdl_part(h,"object","string");
	wsdl_close_message(h);

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if (method_is_valid( iptr->Contents.events->on_create ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Create");
			wsdl_open_message(h,nbuffer);
			wsdl_part(h,"object","string");
			wsdl_close_message(h);
			}
		if (method_is_valid( iptr->Contents.events->on_show ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Show");
			wsdl_open_message(h,nbuffer);
			wsdl_part(h,"object","string");
			wsdl_close_message(h);
			}
		if (method_is_valid( iptr->Contents.events->on_get_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Focus");
			wsdl_open_message(h,nbuffer);
			wsdl_part(h,"object","string");
			wsdl_close_message(h);
			}
		if (method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"LoseFocus");
			wsdl_open_message(h,nbuffer);
			wsdl_part(h,"object","string");
			wsdl_close_message(h);
			}
		if (method_is_valid( iptr->Contents.events->on_event ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Event");
			wsdl_open_message(h,nbuffer);
			wsdl_part(h,"object","string");
			wsdl_close_message(h);
			}
		if (method_is_valid( iptr->Contents.events->on_hide ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Hide");
			wsdl_open_message(h,nbuffer);
			wsdl_part(h,"object","string");
			wsdl_close_message(h);
			}
		if (method_is_valid( iptr->Contents.events->on_remove) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,iptr->Contents.name,"Remove");
			wsdl_open_message(h,nbuffer);
			wsdl_part(h,"object","string");
			wsdl_close_message(h);
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
			wsdl_form_messages(h,ffptr,nbuffer);
			continue;
			}
		}
	return;
}

private	void	php_generate_wsdl( struct form_control * fptr, char * hptr, char* nptr  )
{
	FILE *	h;

	if (!( wsdl_service_program = allocate_string( fptr->prodname ) ))
		return;
	else if (!( wsdl_service_program = enforce_extension(wsdl_service_program, ".at") ))
		return;
	else if (!( h = open_production_target( nptr,0 ) ))
		return;
	else	{
		server_webservice_description( nptr, wsdl_service_program );
	
		fprintf(h,"<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n");
		fprintf(h,"<wsdl:description xmlns:wsdl=\"http://www.w3.org/2005/08/wsdl\" xmlns:soap=\"http://schemas.xmlsoap.org/wsdl/soap/\" xmlns:tns=\"172.17.111.155:8088/test\">\n");

		wsdl_open_message(h,"Fault");
		wsdl_part(h,"message","string");
		wsdl_close_message(h);

		wsdl_form_messages( h, fptr,fptr->identifier );
		wsdl_form_interfaces( h, fptr,fptr->identifier );
		wsdl_form_bindings( h, fptr,hptr,fptr->identifier );
		wsdl_form_services( h, fptr,hptr,fptr->identifier );

		fprintf(h,"</wsdl:description>\n");

		close_production_target(h,nptr);
		liberate( wsdl_service_program );
		wsdl_service_program = (char *) 0;
		return;
		}
}

	/* ----------- */
#endif	/* _wsdlform_c */
	/* ----------- */

