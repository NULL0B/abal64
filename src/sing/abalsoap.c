#ifndef	_abalsoap_c
#define	_abalsoap_c

/*	---------------------------------------------------------------------------------	*/
/*					A B A L S O A P						*/
/*	---------------------------------------------------------------------------------	*/

private	void	soap_data_first(FILE * h, struct form_item * wptr )
{
	indent(h,2);
	fprintf(h,"if ( Len$(q_%s) = 0 )",wptr->Contents.name);
	linefeed(h);
		abal_ngf_first(h,wptr,3);
	indent(h,2);
	fprintf(h,"Else");
	linefeed(h);
		abal_ngf_count(h,wptr,3);
		indent(h,3);
		fprintf(h,"if ( e_%s = 0 )",wptr->Contents.name);
		linefeed(h);
			abal_ngf_posit(h,wptr,4);
			indent(h,4);
			fprintf(h,"if ( e_%s = 0 )",wptr->Contents.name);
			linefeed(h);
				abal_ngf_down(h,wptr,5);
			indent(h,4);
			fprintf(h,"Endif");
			linefeed(h);
		indent(h,3);
		fprintf(h,"Endif");
		linefeed(h);
	indent(h,2);
	fprintf(h,"Endif");
	linefeed(h);
	return;
}

private	void	soap_data_last(FILE * h, struct form_item * wptr )
{
	indent(h,2);
	fprintf(h,"if ( Len$(q_%s) = 0 )",wptr->Contents.name);
	linefeed(h);
		abal_ngf_last(h,wptr,3);
	indent(h,2);
	fprintf(h,"Else");
	linefeed(h);
		abal_ngf_count(h,wptr,3);
		indent(h,3);
		fprintf(h,"if ( e_%s = 0 )",wptr->Contents.name);
		linefeed(h);
			abal_ngf_positd(h,wptr,4);
			indent(h,4);
			fprintf(h,"if ( e_%s = 0 )",wptr->Contents.name);
			linefeed(h);
				abal_ngf_up(h,wptr,5);
			indent(h,4);
			fprintf(h,"Endif");
			linefeed(h);
		indent(h,3);
		fprintf(h,"Endif");
		linefeed(h);
	indent(h,2);
	fprintf(h,"Endif");
	linefeed(h);
	return;
}

private	void	data_detect_method(FILE * h, struct form_item * wptr,char * classname , char * mptr, int m)
{
	int	direction=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	if (!(dptr = wptr->Contents.extra ))
		return;
	indent(h,1);
		fprintf(h,"WebMethod=%c%s%s%c",__QUOTE,classname,mptr,__QUOTE);
		linefeed(h);
	indent(h,1);
		fprintf(h,"eptr = XDP.Document.LocateElement(WebMethod;Len$(WebMethod))");
		linefeed(h);
	indent(h,1);
		fprintf(h,"if ( ValidPtr(eptr) <> 0 )");
		linefeed(h);

	switch ( m ) {
		case DATA_MEMBER_RENAME 	:
			abal_ngf_rename(h,wptr,2);
			break;
		case DATA_MEMBER_ATB 		:	
			abal_ngf_atb(h,wptr,1,2);
			break;
		case DATA_MEMBER_OPEN		:
			abal_ngf_open(h,wptr,2);
			break;
		case DATA_MEMBER_CLOSE		:
			abal_ngf_close(h,wptr,2);
			break;
		case DATA_MEMBER_CFILE		:
			abal_ngf_cfile(h,wptr,2);
			break;
		case DATA_MEMBER_DFILE		:
			abal_ngf_dfile(h,wptr,2);
			break;
		case DATA_MEMBER_UPDATE		:
			abal_ngf_update(h,wptr,2);
			break;
		case DATA_MEMBER_INSERT		:
			abal_ngf_insert(h,wptr,2);
			break;
		case DATA_MEMBER_POSIT		:
			if (!( direction & 1 ))
				abal_ngf_posit(h,wptr,2);
			else	abal_ngf_positd(h,wptr,2);
			break;

		case DATA_MEMBER_CLINK		:
			abal_ngf_clink(h,wptr,2);
			break;
		case DATA_MEMBER_COLLECT	:
			/* abal_ngf_collect(h,wptr,2); */
			break;
		case DATA_MEMBER_COUNT		:
			abal_ngf_count(h,wptr,2);
			break;
		case DATA_MEMBER_RECORD		:
			abal_basefile_record(h,wptr,2);
			break;
		case DATA_MEMBER_MODIF		:
			abal_ngf_modif(h,wptr,2);
			break;
		case DATA_MEMBER_DELETE		:
			abal_ngf_delete(h,wptr,2);
			break;
		case DATA_MEMBER_SEARCH		:
			abal_ngf_search(h,wptr,2);
			break;
		case DATA_MEMBER_LOCATE		:
			abal_ngf_locate(h,wptr,2);
			break;
		case DATA_MEMBER_LOCK		:
			abal_ngf_lock(h,wptr,2);
			break;
		case DATA_MEMBER_FIRST		:
			soap_data_first(h,wptr);
			break;


		case DATA_MEMBER_PREVIOUS	:
		case DATA_MEMBER_UP		:
			switch ((wptr->Contents.align & 0x000F)) {
				case	_SQFILE_FRAME	:
					abal_ngf_backspace(h,wptr,2);
					abal_ngf_backspace(h,wptr,2);
					abal_ngf_read(h,wptr,2);
					break;
				case	_ADFILE_FRAME	:
				case	_DBFILE_FRAME	:
				case	_SIFILE_FRAME	:
				case	_MCFILE_FRAME	:
					abal_ngf_search(h,wptr,2);
					abal_ngf_up(h,wptr,2);
				}
			break;
		case DATA_MEMBER_NEXT		:
		case DATA_MEMBER_DOWN		:
			switch ((wptr->Contents.align & 0x000F)) {
				case	_SQFILE_FRAME	:
					abal_ngf_read(h,wptr,2);
					break;
				case	_ADFILE_FRAME	:
				case	_DBFILE_FRAME	:
				case	_SIFILE_FRAME	:
				case	_MCFILE_FRAME	:
					abal_ngf_search(h,wptr,2);
					abal_ngf_down(h,wptr,2);
					break;
				}
			break;
		case DATA_MEMBER_LAST		:
			soap_data_last(h,wptr);
			break;

		}

	indent(h,2);	fprintf(h,"Exit(0)");		linefeed(h);
	indent(h,1);	fprintf(h,"Endif");		linefeed(h);
	return;
}

private	int	generate_soap_data(FILE * h, char * vptr, char * nptr, char * mptr, int type, int length, int first, int second, int what )
{
	char *	tptr;
	switch ( type ) {
		case	_ABAL_BYTE	: 
		case	_ABAL_WORD	: 
		case	_ABAL_LONG	: tptr = "integer"; break;
		case	_ABAL_BCD 	: tptr = "float";   break;
		case	_ABAL_STRING	: tptr = "string";  break;
		default			:
			type = _ABAL_WORD;
			tptr = "integer";
		}

	indent(h,1);
	fprintf(h,"SOAP.AddParameter(%c%s%c;%c %c;%cxsd:%s%c)",__QUOTE,mptr,__QUOTE,__QUOTE,__QUOTE,__QUOTE,tptr,__QUOTE);
	linefeed(h);

	indent(h,1);
	switch ( type ) {
		case	_ABAL_BYTE	: 
		case	_ABAL_WORD	: 
		case	_ABAL_LONG	: 
		case	_ABAL_BCD 	: 
			fprintf(h,"SOAP.AddText(Conv$(%s_%s);Len$(Conv$(%s_%s)))",vptr,nptr,vptr,nptr);
			break;

		case	_ABAL_STRING	:
			fprintf(h,"SOAP.AddText(%s_%s;Len$(%s_%s))",vptr,nptr,vptr,nptr);
			break;
		}
	linefeed(h);
 	indent(h,1);
	fprintf(h,"SOAP.CloseElement");
	linefeed(h);
	return(0);
}


public	void	soap_forms_methods( FILE * h, struct form_control * fptr )
{
	struct	forms_method * mptr;

	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if ( mptr->type & _METHOD_EXTERN )
			continue;
		else if (!( mptr->type & _METHOD_PUBLIC ))
			continue;
		else if (!( mptr->type & _METHOD_FUNCTION ))
			continue;

		indent(h,1); fprintf(h,"WebMethod=%c%s%s%c",__QUOTE,fptr->identifier,mptr->name,__QUOTE);
		linefeed(h);
		indent(h,1); fprintf(h,"eptr = XDP.Document.LocateElement(WebMethod;Len$(WebMethod))");
		linefeed(h);
		indent(h,1); fprintf(h,"if ( ValidPtr(eptr) <> 0 )");
		linefeed(h);
		
		indent(h,2); fprintf(h,"%s(o)",mptr->name);
		linefeed(h);

		indent(h,2); fprintf(h,"Exit(0)");
		linefeed(h);
		indent(h,1); fprintf(h,"Endif");
		linefeed(h);

		}
}

private	void	redefine_soap_instance( FILE * h,  struct form_item * wptr, int first, int fields, struct data_control * 	dptr )
{
	char	membername[1024];
	int	f;
	for (f=0; f < fields; f++ ) {
		sprintf(membername,"_%s",dptr->name[f+first]);
		generate_soap_data(	h,
					membername,
					wptr->Contents.name,
					dptr->name[f+first],
					dptr->type[f+first],
					dptr->width[f+first],
					dptr->first[f+first],
					dptr->second[f+first],NULL
				);
		}
	return;
}


private	void	export_soap_data( FILE * h, struct form_item * wptr )
{
	char	*		root=(char *) 0;
	char	*		fptr=(char *) 0;
	char	*		tptr=(char *) 0;
	char	*		lptr=(char *) 0;
	int			klen=32;
	int			datalength=512;
	int			xlen=5;
	int			c;
	int			f;
	int			fields=0;
	struct	data_control * 	dptr=(struct data_control *) 0;
	int	first=0;
	int	t;
	if ((dptr = wptr->Contents.extra )  != (struct data_control *) 0) {
		wptr->Contents.extra = dptr;
		fields = dptr->indexfields + dptr->datafields;
		klen = dptr->indexlength;
		datalength = dptr->datalength;
		first= dptr->indexfields;
		}
	else	first = 0;

	if (!( fields ))
		fields = 8;

	/* --------------------------------------------------- */
	/* these values will need to be adjusted if more file  */
	/* structure control members are added. IJM March 2008 */
	/* --------------------------------------------------- */
	switch ((t = (wptr->Contents.align & 0x000F)) ) {
		case	_ADFILE_FRAME	:	
			xlen =   14; 
			if ( datalength ) {
				if ( datalength % 256 ) {
					dptr->datalength = (((datalength / 256) + 1) * 256);
					datalength = dptr->datalength;
					}
				}
			break;
		case	_SQFILE_FRAME	:	xlen =    6; break;
		case	_SIFILE_FRAME	:	xlen =   30; break;
		case	_MCFILE_FRAME	:
			xlen = (1024 + 26 +1 + (fields*32)); 
			break;
		case	_DBFILE_FRAME	:
			xlen = (4096 + 30);
			break;
		}

	/* --------------------------------------------------- */

	generate_soap_data(h,"h",wptr->Contents.name,"handle",_ABAL_WORD,0,0,0,NULL);

	if ( t == _MCFILE_FRAME ) {
		generate_soap_data(h,"q",wptr->Contents.name,"question",_ABAL_STRING,1024,0,0,NULL);
		}
	else if ( t == _DBFILE_FRAME ) {
		generate_soap_data(h,"q",wptr->Contents.name,"question",_ABAL_STRING,4096,0,0,NULL);
		}

	if (( t == _MCFILE_FRAME )
	||  ( t == _DBFILE_FRAME ) 
	||  ( t == _SIFILE_FRAME )) {
		generate_soap_data(h,"n",wptr->Contents.name,"response",_ABAL_LONG,2,0,0,NULL);
		}

	if ( t == _ADFILE_FRAME ) {
		generate_soap_data(h,"s",wptr->Contents.name,"sector",_ABAL_BCD,8,0,0,NULL);
		}

	generate_soap_data(h,"e",wptr->Contents.name,"error",_ABAL_WORD,0,0,0,NULL);
	generate_soap_data(h,"l",wptr->Contents.name,"length",_ABAL_WORD,0,0,0,NULL);

	if ( klen ) {
		if ((dptr != (struct data_control *) 0)
		&&  (dptr->indexfields != 0 )) {
			redefine_soap_instance(h,wptr,0,dptr->indexfields, dptr);
			}
		generate_soap_data(h,"m",wptr->Contents.name,"marker",_ABAL_BYTE,0,0,0,NULL);
		}

	if ( datalength ) {
		if ( t != _DBFILE_FRAME ) {
			redefine_soap_instance(h,wptr,dptr->indexfields,dptr->datafields, dptr);
			}
		}

	return(fields);
}

private	int	interprete_soap_item(FILE * h, char * vptr, char * nptr, char * mptr, int type, int length, int first, int second, int what )
{
	int	direction=0;
	indent(h,1);
	fprintf(h,"WebToken = %c%s%c",__QUOTE,mptr,__QUOTE);
	linefeed(h);
	indent(h,1);
	fprintf(h,"eptr = XDP.Document.LocateElement(WebToken;Len$(WebToken))");
	linefeed(h);
	indent(h,1);
	fprintf(h,"if ( ValidPtr(eptr) <> 0 )");
	linefeed(h);
	indent(h,2);
	switch ( type ) {
		case	_ABAL_BYTE	: 
		case	_ABAL_WORD	: 
		case	_ABAL_LONG	: 
			fprintf(h,"%s_%s = Conv%(eptr.GetText())",vptr,nptr);
			break;
		case	_ABAL_BCD 	: 
			fprintf(h,"%s_%s = Conv%(eptr.GetText())",vptr,nptr);
			linefeed(h);
			indent(h,2);
			fprintf(h,"%s_%s = Fix(%s_%s,%u)",vptr,nptr,vptr,nptr,0);
			break;
		case	_ABAL_STRING	: 
		default			:
			fprintf(h,"%s_%s = eptr.GetText()",vptr,nptr);
			break;
		}
	linefeed(h);
	indent(h,1);
	fprintf(h,"Endif");
	linefeed(h);
	return;
}

private	void	import_soap_members( FILE * h, struct form_item * wptr,int first,int fields,struct data_control * dptr )
{
	char	membername[1024];
	int	f;
	for (f=0; f < fields; f++ ) {
		sprintf(membername,"_%s",dptr->name[f+first]);
		interprete_soap_item(	h,
					membername,
					wptr->Contents.name,
					dptr->name[f+first],
					dptr->type[f+first],
					dptr->width[f+first],
					dptr->first[f+first],
					dptr->second[f+first],NULL
				);
		}
}

private	void	import_soap_data( FILE * h, struct form_item * wptr )
{
	struct	data_control * dptr=(struct data_control *) 0;
	if ((dptr = wptr->Contents.extra )  != (struct data_control *) 0) {
		interprete_soap_item(	h,
					"q",
					wptr->Contents.name,
					"question",
					_ABAL_STRING,
					1024,
					1,
					1,NULL
				);
		import_soap_members(h,wptr,0,dptr->indexfields, dptr);
		import_soap_members(h,wptr,dptr->indexfields,dptr->datafields, dptr);
		}
	return;
}

private	void	abal_soap_request( FILE * h, struct form_control * fptr, 	char * classname )
{
	struct	form_item * wptr;

	/* ---------------------- */
	/* O n R e q u e s t ( )  */
	/* ---------------------- */
	abal_standard_function(h,"OnRequest","ptr o$,filename$=256",_ABAL_WORD);
		indent(h,1);
		fprintf(h,"xml_dom_parser XDP(filename)"); 
		linefeed(h);
		indent(h,1);
		fprintf(h,"xml_element pointer eptr"); 
		linefeed(h);
		indent(h,1);
		fprintf(h,"xml_element pointer pptr"); 
		linefeed(h);
		indent(h,1);
		fprintf(h,"XDP.parse"); 
		linefeed(h);
		indent(h,1);
		fprintf(h,"On Local Error Goto &FaultTrap,FaultCatcher"); 
		linefeed(h);

		for (	wptr=fptr->first;
			wptr != (struct form_item *) 0;
			wptr = wptr->next )
			{
			if (!( wptr->Contents.access & _WIDGET_PUBLIC ))
				continue;
			else if ((wptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME ) 
				continue;
			else if (!( is_file_Widget( wptr ) ))
				continue;
			else	{
				import_soap_data(h,wptr);
				data_detect_method(h,wptr,wptr->Contents.name,"First",DATA_MEMBER_FIRST);
				data_detect_method(h,wptr,wptr->Contents.name,"Down",DATA_MEMBER_DOWN);
				data_detect_method(h,wptr,wptr->Contents.name,"Search",DATA_MEMBER_SEARCH);
				data_detect_method(h,wptr,wptr->Contents.name,"Lock",DATA_MEMBER_LOCK);
				data_detect_method(h,wptr,wptr->Contents.name,"Insert",DATA_MEMBER_INSERT);
				data_detect_method(h,wptr,wptr->Contents.name,"Update",DATA_MEMBER_UPDATE);
				data_detect_method(h,wptr,wptr->Contents.name,"Modif",DATA_MEMBER_MODIF);
				data_detect_method(h,wptr,wptr->Contents.name,"Delete",DATA_MEMBER_DELETE);
				data_detect_method(h,wptr,wptr->Contents.name,"Up",DATA_MEMBER_UP);
				data_detect_method(h,wptr,wptr->Contents.name,"Last",DATA_MEMBER_LAST);
				data_detect_method(h,wptr,wptr->Contents.name,"Collect",DATA_MEMBER_COLLECT);
				data_detect_method(h,wptr,wptr->Contents.name,"Posit",DATA_MEMBER_POSIT);
				data_detect_method(h,wptr,wptr->Contents.name,"Count",DATA_MEMBER_COUNT);
				data_detect_method(h,wptr,wptr->Contents.name,"Create",DATA_MEMBER_CFILE);
				}
			}

		soap_forms_methods( h, fptr );

		fprintf(h,"&FaultTrap :: On Local Error Abort");
		linefeed(h);
		indent(h,1);
		fprintf(h,"FaultCode=%cSOAP-ENV:Server%c",__QUOTE,__QUOTE);
		linefeed(h);
		indent(h,1);
		fprintf(h,"FaultString=%cApplication Exception%c",__QUOTE,__QUOTE);
		linefeed(h);
		indent(h,1);
		fprintf(h,"FaultActor=%cWasp%c",__QUOTE,__QUOTE);
		linefeed(h);
		indent(h,1);
		fprintf(h,"FaultMessage = Print((E,X,$),FaultCatcher,%cMethod Error%c)",__QUOTE,__QUOTE);
		linefeed(h);
		indent(h,1);
		fprintf(h,"Exit(1)");
		linefeed(h);

		abal_endproc(h);
	return;
}

private	void	abal_soap_response( FILE * h, struct form_control * fptr, 	char * classname )
{
	struct	form_item * wptr;

	/* ---------------------- */
	/* O n R e s p o n s e () */
	/* ---------------------- */
	abal_standard_function(h,"OnResponse","ptr o$,filename$=256",_ABAL_WORD);
		indent(h,1);	fprintf(h,"Dcl wbuf$=1024");		linefeed(h);
		indent(h,1);	fprintf(h,"soap_response pointer SOAP");linefeed(h);
		indent(h,1);	fprintf(h,"file_output pointer TARGET");linefeed(h);
			
		indent(h,1);
		fprintf(h,"Create SOAP(WebMethod!%cResponse%c;%c%s%c)",__QUOTE,__QUOTE,__QUOTE,WsGen.url,__QUOTE);
		linefeed(h);

		for (	wptr=fptr->first;
			wptr != (struct form_item *) 0;
			wptr = wptr->next )
			{
			if (!( wptr->Contents.access & _WIDGET_PUBLIC ))
				continue;
			else if ((wptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME ) 
				continue;
			else if (!( is_file_Widget( wptr ) ))
				continue;
			else	export_soap_data(h,wptr);
			}

		indent(h,1);	fprintf(h,"SOAP.CloseElement");		linefeed(h);
		indent(h,1);	fprintf(h,"Create TARGET(filename)");	linefeed(h);
		indent(h,1);	fprintf(h,"SOAP.Serialize(TARGET)");	linefeed(h);
		indent(h,1);	fprintf(h,"Remove TARGET");		linefeed(h);
		indent(h,1);	fprintf(h,"Remove SOAP");		linefeed(h);

		abal_endproc(h);
	return;
}

private	void	abal_soap_fault( FILE * h, struct form_control * fptr, 	char * classname )
{
		/* ---------------------- */
		/* O n F a u l t     ( )  */
		/* ---------------------- */
		abal_standard_function(h,"OnFault","ptr o$,filename$=256",_ABAL_WORD);
			indent(h,1);
			fprintf(h,"Dcl msgbuffer$=256");
			linefeed(h);
			indent(h,1);
			fprintf(h,"Local soap_fault pointer SOAP");
			linefeed(h);
			indent(h,1);
			fprintf(h,"Local file_output pointer TARGET");
			linefeed(h);
			indent(h,1);
			fprintf(h,"Create SOAP(%cFault%c;%c%s%c)",__QUOTE,__QUOTE,__QUOTE,WsGen.url,__QUOTE);
			linefeed(h);
						
			indent(h,1);
			fprintf(h,"SOAP.AddParameter(%cfaultcode%c;%c %c;%cxsd:string%c)",__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE);
			linefeed(h);
			indent(h,1);
			fprintf(h,"SOAP.AddText(FaultCode;Len$(FaultCode))");
			linefeed(h);
			indent(h,1);
			fprintf(h,"SOAP.CloseElement");
			linefeed(h);
			indent(h,1);
			fprintf(h,"SOAP.AddParameter(%cfaultstring%c;%c %c;%cxsd:string%c)",__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE);
			linefeed(h);
			indent(h,1);
			fprintf(h,"SOAP.AddText(FaultString;Len$(FaultString))");
			linefeed(h);
			indent(h,1);
			fprintf(h,"SOAP.CloseElement");
			linefeed(h);
			indent(h,1);
			fprintf(h,"SOAP.AddParameter(%cfaultactor%c,%c %c,%cxsd:string%c)",__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE);
			linefeed(h);
			indent(h,1);
			fprintf(h,"SOAP.AddText(FaultActor;Len$(FaultActor))");
			linefeed(h);
			indent(h,1);
			fprintf(h,"SOAP.CloseElement");
			linefeed(h);
			indent(h,1);
			fprintf(h,"SOAP.AddParameter(%cdetail%c;%c %c;%cxsd:string%c)",__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE);
			linefeed(h);
			indent(h,1);
			fprintf(h,"SOAP.AddText(FaultMessage;Len$(FaultMessage))");
			linefeed(h);
			indent(h,1);
			fprintf(h,"SOAP.CloseElement");
			linefeed(h);
			indent(h,1);
			fprintf(h,"Create TARGET(filename)");
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
		abal_endproc(h);
	return;
}

public	void	soap_webservice_record(char * cptr, char * mptr, char * nptr )
{
	char	servicename[512];
	sprintf(servicename,"/%s%s",cptr,mptr);
	server_webservice_record(servicename,nptr);
	return;
}


public	void	wsdl_generate_interface( struct form_control * fptr , char * target, char * classname )
{
	return;
}

/*	----------------------------------------------------------------------------------	*/
/*	   s o a p _ g e n e r a t e _ i n t e r f a c e ( form, filename, classname )		*/
/*	----------------------------------------------------------------------------------	*/
/*	generates the web server interface description file for WASP describing the web		*/
/*	service and its interface components.							*/
/*	----------------------------------------------------------------------------------	*/

public	void	soap_generate_interface( struct form_control * fptr , char * target, char * classname )
{
	struct	form_item    * wptr=(struct form_item    *) 0;
	struct	forms_method * mptr;

	open_server_description( fptr,0 );

	soap_webservice_record(classname,"On_Show",target);
	soap_webservice_record(classname,"On_Event",target);

	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if ( mptr->type & _METHOD_EXTERN )
			continue;
		else if (!( mptr->type & _METHOD_PUBLIC ))
			continue;
		else if (!( mptr->type & _METHOD_FUNCTION ))
			continue;
		else	soap_webservice_record(classname,mptr->name,target);
		}

	for (	wptr=fptr->first;
		wptr != (struct form_item *) 0;
		wptr = wptr->next )
		{
		if (!( wptr->Contents.access & _WIDGET_PUBLIC ))
			continue;
		else if ((wptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME ) 
			continue;
		else if (!( is_file_Widget( wptr ) ))
			continue;
		else	{
			soap_webservice_record(wptr->Contents.name,"First",target);
			soap_webservice_record(wptr->Contents.name,"Down",target);
			soap_webservice_record(wptr->Contents.name,"Search",target);
			soap_webservice_record(wptr->Contents.name,"Lock",target);
			soap_webservice_record(wptr->Contents.name,"Insert",target);
			soap_webservice_record(wptr->Contents.name,"Update",target);
			soap_webservice_record(wptr->Contents.name,"Modif",target);
			soap_webservice_record(wptr->Contents.name,"Delete",target);
			soap_webservice_record(wptr->Contents.name,"Up",target);
			soap_webservice_record(wptr->Contents.name,"Last",target);
			soap_webservice_record(wptr->Contents.name,"Collect",target);
			soap_webservice_record(wptr->Contents.name,"Posit",target);
			soap_webservice_record(wptr->Contents.name,"Count",target);
			soap_webservice_record(wptr->Contents.name,"Create",target);
			}
		}
	close_server_description();
	return;
}

/*	----------------------------------------------------------------------------------	*/
/*	     s o a p _ g e n e r a t e _ s e r v i c e ( form, filename, classname )		*/
/*	----------------------------------------------------------------------------------	*/
/*	generates the abal web service program for the specified form to the target file	*/
/*	name and as the indicated classname. post production will be performed by this		*/
/*	function.										*/
/*	----------------------------------------------------------------------------------	*/

public	int	soap_generate_service( struct form_control * fptr, char * nptr, char * classname )
{
	FILE	*	h;
	char	*	wnptr;
	struct	form_item    * wptr=(struct form_item    *) 0;

	/* --------------------------------------------------- */
	/* allocate and initiate production to target filename */
	/* --------------------------------------------------- */
	if (!( nptr = allocate_string( nptr )))
		return(-1);
	else if (!( nptr = enforce_extension( nptr, AS_EXTENSION )))
		return(-1);
	else if (!(h = open_production_target(nptr,0))) {
		liberate( nptr );
		return(-1);
		}
	else	{

		set_abal_config_overlay(fptr->isoverlay);
		set_abal_config_program(fptr->isprogram);

		/* ---------------------- */
		/* program overlay header */
		/* ---------------------- */
		abal_include(h, "pragmas.as" );
		aplus_apl(h,"soap" );
		abal_program(h,"ws");

		/* -------------------------- */
		/* default web service fields */
		/* -------------------------- */
		fprintf(h,"Dcl Persistance%%");	 	linefeed(h);
		fprintf(h,"Dcl FaultCatcher%%"); 	linefeed(h);
		fprintf(h,"Dcl FaultCode$=256"); 	linefeed(h);
		fprintf(h,"Dcl FaultString$=256"); 	linefeed(h);
		fprintf(h,"Dcl FaultMessage$=256"); 	linefeed(h);
		fprintf(h,"Dcl FaultActor$=256"); 	linefeed(h);
		fprintf(h,"Dcl WebMethod$=256"); 	linefeed(h);
		fprintf(h,"Dcl WebToken$=256"); 	linefeed(h);

		abal_widget_constants(h, fptr);
		abal_forms_members(h,fptr);
		generate_abal_structure(h,fptr);

		/* ------------------------------ */
		/* Forward Procedure Declarations */
		/* ------------------------------ */
		abal_forward_proc(h,"PreConstruction","ptr o$,ptr a$,ptr b$","\0");
		abal_forward_proc(h,"PostDestruction","ptr o$,ptr a$,ptr b$","\0");
		abal_forward_proc(h,"OnCreate","ptr o$","\0");
		abal_forward_proc(h,"OnRemove","ptr o$","\0");
		abal_forward_func(h,"OnRequest","ptr o$,filename$=256",_ABAL_WORD);
		abal_forward_func(h,"OnResponse","ptr o$,filename$=256",_ABAL_WORD);
		abal_forward_func(h,"OnFault","ptr o$,filename$=256",_ABAL_WORD);
		abal_forward_func(h,"IsPesistant","ptr o$",_ABAL_WORD);

		/* ---------------------- */
		/* Procedure Declarations */
		/* ---------------------- */
		abal_forms_methods(h,fptr);

		abal_standard_proc(h,"PreConstruction","ptr o$,ptr a$,ptr b$","\0");
		abal_endproc(h);
		abal_standard_proc(h,"PostDestruction","ptr o$,ptr a$,ptr b$","\0");
		abal_endproc(h);

		abal_standard_proc(h,"OnCreate","ptr o$","\0");
		indent(h,1); fprintf(h,"Persistance=1"); linefeed(h);
		abal_widget_construction( h, fptr );
		abal_endproc(h);

		abal_standard_proc(h,"OnRemove","ptr o$","\0");
		abal_widget_destruction( h, fptr );
		abal_endproc(h);

		abal_soap_request(h,fptr,classname);
		abal_soap_response(h,fptr,classname);
		abal_soap_fault   (h,fptr,classname);

		/* ---------------------- */
		/* Is P e r s i s t a n t */
		/* ---------------------- */
		abal_standard_function(h,"IsPesistant","ptr o$",_ABAL_WORD);
		indent(h,1); fprintf(h,"Exit(Persistance)"); linefeed(h);
		abal_endproc(h);

		/* ---------------------- */
		/* program overlay footer */
		/* ---------------------- */
		abal_segment(h,"0");
		abal_endseg(h,"0");
		abal_end(h,0);

		/* ------------------------------- */
		/* duplicate filename for postprod */
		/* ------------------------------- */
		wnptr = allocate_string( nptr );
		close_production_target( h, nptr );

		/* perform secondary production : translation */
		/* ------------------------------------------ */
		post_production( fptr, _GENERATE_ABAL, wnptr, 0 );

		return(0);
		}
}

/*	----------------------------------------------------------------------------------	*/
/*	    g e n e r a t e _ s o a p _ w e b _ s e r v i c e ( file, name, length )		*/
/*	----------------------------------------------------------------------------------	*/
/*	generates a file specific web service module for the indicated file description.	*/
/*	----------------------------------------------------------------------------------	*/

public	void	generate_soap_web_service(
	struct file_control * optr, 
	char * nptr, 
	int nlen  )
{
	FILE	*	h=(FILE * )0 ;
	char	*	fnptr=(char * ) 0;
	struct	form_item    * wptr=(struct form_item    *) 0;
	struct	data_control * dptr=(struct data_control *) 0;
	struct	form_control * fptr=(struct form_control *) 0;
	
	if (!( nptr ))
		return( -1 );
	else if (!( optr )) 
		return(-1); 
	else if (!( dptr = optr->payload )) 
		return(-1); 

	limit_right_space( nptr,nlen);

	if (!( nptr = allocate_string( nptr )))
		return(-1);
	else if (!( fptr = allocate_Form(nptr) ))
		return(-1);
	else if (!( wptr = allocate_for_Widget())) {
		liberate_Form( fptr );
		return(-1);
		}
	else if (!( wptr->Contents.format = allocate( strlen( optr->classname ) + 8 ) )) {
		liberate_Form( fptr );
		return(-1);
		}
	else	{
		wptr->Contents.style = _DATA_FRAME;
		wptr->Contents.align = _MCFILE_FRAME;
		sprintf(wptr->Contents.format,"(%s)",optr->classname);
		wptr->Contents.name = allocate_string( optr->identity );
		wptr->Contents.payload = allocate_string( optr->filename );
		dptr->lock++;
		wptr->Contents.extra = dptr;
		reset_event_control(wptr->Contents.events,(wptr->Contents.style & _FRAME_TYPE));
		check_Widget( wptr );
		add_Widget(fptr,wptr,0);
		wptr->Contents.access |= _WIDGET_PUBLIC;
		soap_generate_service  ( fptr, nptr, optr->classname );
		soap_generate_interface( fptr, nptr, optr->classname );
		liberate_Form( fptr );
		}
	return;
}


	/* ----------- */
#endif	/* _abalsoap_c */
	/* ----------- */

