#ifndef	_singlsl_c
#define	_singlsl_c

private	void	lsl_file_menu_data(FILE * h)
{
	fprintf(h,"list\tmenu_choices = [ %cFirst%c, %cDown%c, %cSearch%c, %cUpdate%c, %cInsert%c, %cModif%c, %cUp%c, %cLast%c, %cDelete%c, %cCreate%c, %cDebug%c  ];\n",
		__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,
		__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,
		__QUOTE,__QUOTE,__QUOTE,__QUOTE,
		__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"string\tmenu_message =%cHost : %c;\n",__QUOTE,__QUOTE);
	fprintf(h,"integer\tmenu_id=0;\n");
	fprintf(h,"integer\tmenu_port=0;\n");
	fprintf(h,"key\towner_key=NULL_KEY;\n");
	return;
}

private	void	lsl_file_menu_show(FILE * h)
{
	fprintf(h,"\nMenuShow()\n");
	fprintf(h,"{\n");
	fprintf(h,"\tllListenRemove(menu_id);\n");
	fprintf(h,"\towner_key = llGetOwner();\n");
	fprintf(h,"\tmenu_port = ( -1 * (integer)(%c0x%c+llGetSubString((string)llGetKey(),-5,-1)) );\n",__QUOTE,__QUOTE);     
	fprintf(h,"\tllDialog(llDetectedKey(0),menu_message+base_url,menu_choices,menu_port);\n");
	fprintf(h,"\tmenu_id  = llListen(menu_port,%c%c,llDetectedKey(0),%c%c);\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE); 
	fprintf(h,"}\n");
	return;
}

public	void	lsl_form_menu_listen( FILE * h, struct form_control * fptr )
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

		fprintf(h,"\t\tif ( message == %c%s%c )\n",__QUOTE,mptr->name,__QUOTE);
		fprintf(h,"\t\t{\n");
		fprintf(h,"\t\t\r%sMethod(%c%s%s%c);\n",fptr->identifier,__QUOTE,fptr->identifier,mptr->name,__QUOTE);
		fprintf(h,"\t\t} else if ( message == %cDown%c ) \n",__QUOTE,__QUOTE);
		}
}

private	void	lsl_file_menu_listen( FILE * h, struct form_item * iptr )
{
	fprintf(h,"\t\tif ( message == %cFirst%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\t\r%sMethod(%c%sFirst%c);\n",iptr->Contents.name,__QUOTE,iptr->Contents.name,__QUOTE);
	fprintf(h,"\t\t} else if ( message == %cDown%c ) \n",__QUOTE,__QUOTE);
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\t\r%sMethod(%c%sDown%c);\n",iptr->Contents.name,__QUOTE,iptr->Contents.name,__QUOTE);
	fprintf(h,"\t\t} else if ( message == %cLast%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\t\r%sMethod(%c%sLast%c);\n",iptr->Contents.name,__QUOTE,iptr->Contents.name,__QUOTE);
	fprintf(h,"\t\t} else if ( message == %cUp%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\t\r%sMethod(%c%sUp%c);\n",iptr->Contents.name,__QUOTE,iptr->Contents.name,__QUOTE);
	fprintf(h,"\t\t} else if ( message == %cUpdate%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\t\r%sMethod(%c%sUpdate%c);\n",iptr->Contents.name,__QUOTE,iptr->Contents.name,__QUOTE);
	fprintf(h,"\t\t} else if ( message == %cInsert%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\t\r%sMethod(%c%sInsert%c);\n",iptr->Contents.name,__QUOTE,iptr->Contents.name,__QUOTE);
	fprintf(h,"\t\t} else if ( message == %cModif%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\t\r%sMethod(%c%sModif%c);\n",iptr->Contents.name,__QUOTE,iptr->Contents.name,__QUOTE);
	fprintf(h,"\t\t} else if ( message == %cCreate%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\t\r%sMethod(%c%sCreate%c);\n",iptr->Contents.name,__QUOTE,iptr->Contents.name,__QUOTE);
	fprintf(h,"\t\t} else if ( message == %cDelete%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\t\r%sMethod(%c%sDelete%c);\n",iptr->Contents.name,__QUOTE,iptr->Contents.name,__QUOTE);
	fprintf(h,"\t\t} else if ( message == %cSearch%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\t\t%sMethod(%c%sSearch%c);\n",iptr->Contents.name,__QUOTE,iptr->Contents.name,__QUOTE);
	fprintf(h,"\t\t} else if ( message == %cDebug%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\t\tdebug = ((debug +1) & 1);\n");
	fprintf(h,"\t\t}\n");
	return;
}

private	void	lsl_file_menu_touch( FILE * h, struct form_item * iptr )
{
	fprintf(h,"\t\t\tMenuShow();\n");
	return;
}

private	void	lsl_file_record_show( FILE * h, struct form_item * iptr)
{
	int	i;
	int	fields;

	struct	data_control * dptr;

	if (!(dptr = iptr->Contents.extra ))
		return;

	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;

	fprintf(h,"\n%sShow()\n",iptr->Contents.name);
	fprintf(h,"{\n");
	fprintf(h,"\tllOwnerSay(%c%s =%c+(string)_%s_%s);\n",__QUOTE,"error",__QUOTE,iptr->Contents.name,"error");
	fprintf(h,"\tllOwnerSay(%c%s =%c+(string)_%s_%s);\n",__QUOTE,"response",__QUOTE,iptr->Contents.name,"response");
	for ( i=0; i < fields; i++ ) {
		fprintf(h,"\tllOwnerSay(%c%s =%c+_%s_%s);\n",__QUOTE,dptr->name[i],__QUOTE,iptr->Contents.name,dptr->name[i]);
		}
	fprintf(h,"}\n");
	return;
}

private	void	lsl_file_record_get( FILE * h, struct form_item * iptr)
{
	int	i;
	int	fields;

	struct	data_control * dptr;

	if (!(dptr = iptr->Contents.extra ))
		return;

	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return;

	fprintf(h,"\n%sGet(string body)\n",iptr->Contents.name);
	fprintf(h,"{\n");
	fprintf(h,"\tlist xmltags;\n");
	fprintf(h,"\txmltags = llParseString2List( body, [ %c<%c , %c>%c , %c=%c , %c:%c , %c %c ] , [] );\n",0x0022,0x0022,0x0022,0x0022,0x0022,0x0022,0x0022,0x0022,0x0022,0x0022);
	fprintf(h,"\t_%s_%s = (integer) SoapReturnValue( xmltags, %c%s%c );\n",iptr->Contents.name,"error",0x0022,"error",0x0022);
	fprintf(h,"\t_%s_%s = (integer) SoapReturnValue( xmltags, %c%s%c );\n",iptr->Contents.name,"response",0x0022,"response",0x0022);
	for ( i=0; i < fields; i++ ) {
		fprintf(h,"\t_%s_%s = SoapReturnValue( xmltags, %c%s%c );\n",iptr->Contents.name,dptr->name[i],0x0022,dptr->name[i],0x0022);
		}
	fprintf(h,"}\n");

	return;
}

static	void	lsl_start_stream(FILE * h, struct form_control *  fptr )
{
	if ( h ) {
		fprintf(h,"// --------------------------------------------------------------- \n");
		fprintf(h,"// top of file : %s%s \n",fptr->identifier, ".lsl" );
		fprintf(h,"// --------------------------------------------------------------- \n");
		fprintf(h,"// SOAP Data Base Access Module \n");
		fprintf(h,"// --------------------------------------------------------------- \n");
		fprintf(h,"// This file has been generated and should not be modified by hand \n");
		fprintf(h,"// --------------------------------------------------------------- \n");
		}
}

static	void	lsl_close_stream( FILE * h, struct form_control *  fptr )
{
	if ( h ) {
		fprintf(h,"// --------------------------------------------------------------- \n");
		fprintf(h,"// end of file : %s%s \n",fptr->identifier, ".lsl" );
		fprintf(h,"// --------------------------------------------------------------- \n");
		}
	return;
}

static	void	lsl_soap_object( FILE * h, struct form_item * iptr, struct data_control * dptr, int fields )
{
	int	i;
	fprintf(h,"\n// -------------------------------------");
	fprintf(h,"\n// instance %s ",iptr->Contents.name);
	fprintf(h,"\n// -------------------------------------\n");
	fprintf(h,"integer\t_%s_%s=0;\n",iptr->Contents.name,"error");
	fprintf(h,"integer\t_%s_%s=0;\n",iptr->Contents.name,"response");
	fprintf(h,"string\t_%s_%s=%c%c;\n",iptr->Contents.name,"question",__QUOTE,__QUOTE);
	for ( i=0; i < fields; i++ ) {
		fprintf(h,"string\t_%s_%s = %c%c;\n",iptr->Contents.name,dptr->name[i],__QUOTE,__QUOTE);
		}
	return;
}

static	void	lsl_soap_put_object( FILE * h, struct form_item * iptr, struct data_control * dptr, int fields )
{
	int	i;
	fprintf(h,"\n%sPut()\n",iptr->Contents.name);
	fprintf(h,"{\n");
	fprintf(h,"\tSoapParameter(%c%s%c,_%s_%s);\n",__QUOTE,"question",__QUOTE,iptr->Contents.name,"question");
	for ( i=0; i < fields; i++ ) {
		fprintf(h,"\tSoapParameter(%c%s%c,_%s_%s);\n",__QUOTE,dptr->name[i],__QUOTE,iptr->Contents.name,dptr->name[i]);
		}
	fprintf(h,"}\n");
}

static	void	lsl_http_soap_response(FILE * h, struct form_control *  fptr, char * classname)
{
	int	fields;
	int	i;
	struct	form_item 	* iptr;
	struct	data_control* dptr;
	fprintf(h,"\n\thttp_response(key request_id, integer status, list metadata, string body)\n\t{\n");
	fprintf(h,"\t\tlist    xmltags=[];\n");
	fprintf(h,"\t\tif ((request_id == soap_id) && ( requesting != 0))\n");
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\t\trequesting = 0;\n");
	fprintf(h,"\t\t\tif ( status != 200 ) \n");
	fprintf(h,"\t\t\t{\n");
	fprintf(h,"\t\t\t\tllSay(0,%cfailure : %c + (string) status );\n",__QUOTE,__QUOTE);
	fprintf(h,"\t\t\t} else\n");
	fprintf(h,"\t\t\t{\n");
	for ( 	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr=iptr->next) {
		if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
			continue;
		else if ((iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME ) 
			continue;
		else if (!( is_file_Widget( iptr ) ))
			continue;
		else if (!(dptr = iptr->Contents.extra ))
			continue;
		else if (!( fields = dptr->indexfields + dptr->datafields ))
			continue;
		else	{
			break;
			}
		}

	if ( iptr ) {

		fprintf(h,"\t\t\t\t%sGet(body);\n",iptr->Contents.name);
	
		/* -------------------------- */
		/* show record if menu driven */
		/* -------------------------- */
		if ( WsGen.domenu ) { fprintf(h,"\t\t\t\t%sShow();\n",iptr->Contents.name);  }

		}

	fprintf(h,"\t\t\t}\n");
	fprintf(h,"\t\t}\n");
	fprintf(h,"\t}\n");
	return;
}

static	void	lsl_soap_client   (FILE * h, struct form_control *  fptr, char * classname )
{
	struct	form_item * iptr;
	struct	data_control * 	dptr;
	int	fields;
	int	first=0;
	int	datalength;
	int	klen;

	lsl_start_stream(h, fptr );
	
	fprintf(h,"key   \tsoap_id;\n");
	fprintf(h,"list  \tsoaparas          = [];\n");
	fprintf(h,"list  \tsoapvalues        = [];\n");
	fprintf(h,"list  \tsoapmessage       = [];\n");
	fprintf(h,"string\tsoapresult        = %c%c;\n",__QUOTE,__QUOTE);
	fprintf(h,"string\tsoaprequest       = %c%c;\n",__QUOTE,__QUOTE);
	fprintf(h,"string\tsoapxmlfile       = %c%s%c;\n",__QUOTE,"application/xml",__QUOTE);
	fprintf(h,"string\tsoap_version      = %c<?xml version=\\%c1.0\\%c encoding=\\%cISO-8859-1\\%c?>%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"string\tsoap_envelope     = %c<SOAP-ENV:Envelope xmlns:SOAP-ENV=\\%chttp://schemas.xmlsoap.org/soap/envelope/\\%c SOAP-ENV:encodingStyle=\\%chttp://schemas.xmlsoap.org/soap/encoding/\\%c>%c;\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"string\tsoap_body         = %c<SOAP-ENV:Body>%c;\n",__QUOTE,__QUOTE);
	fprintf(h,"string\tsoap_function     = %c%c;\n",__QUOTE,__QUOTE);
	fprintf(h,"string\tsoap_parameters   = %c%c;\n",__QUOTE,__QUOTE);
	fprintf(h,"string\tsoap_end_function = %c%c;\n",__QUOTE,__QUOTE);
	fprintf(h,"string\tsoap_end_body     = %c</SOAP-ENV:Body>%c;\n",__QUOTE,__QUOTE);
	fprintf(h,"string\tsoap_endvelope    = %c</SOAP-ENV:Envelope>%c;\n",__QUOTE,__QUOTE);
	fprintf(h,"string\tbase_url          = %c%s/%c;\n",__QUOTE,WsGen.url,__QUOTE);
	fprintf(h,"string\trequest_url       = %c%s/%c;\n",__QUOTE,WsGen.url,__QUOTE);
	fprintf(h,"string\tparameter         = %c%c;\n",__QUOTE,__QUOTE);
	fprintf(h,"integer\trequesting       =  0;\n");
	fprintf(h,"integer\ttimeout          = 30;\n");
	fprintf(h,"integer\tdebug            = 0;\n");
	fprintf(h,"list\tparalist            = [];\n");

	/* -------------------------------------- */
	/* generate menu control data if required */
	/* -------------------------------------- */
	if ( WsGen.domenu ) {	lsl_file_menu_data( h );	}

	/* ------------------------------ */
	/* generate file object variables */
	/* ------------------------------ */
	for ( 	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
			continue;
		else if ((iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME )
			continue;
		else if (!( is_file_Widget( iptr ) ))
			continue;
		else if (!(dptr = iptr->Contents.extra ))
			continue;
		else if (!( fields = dptr->indexfields + dptr->datafields ))
			continue;
		else	{
			break;
			}
		}
	if ((iptr ) && ( dptr )) {
		klen = dptr->indexlength;
		datalength = dptr->datalength;
		first= dptr->indexfields;
		lsl_soap_object( h, iptr, dptr, fields );
		}

	/* --------------------------- */
	/* generate standard methods   */
	/* --------------------------- */
	if ( WsGen.domenu ) {	lsl_file_menu_show( h ); 		}

	/* ------------ */
	/* SOAP REQUEST */
	/* ------------ */
	fprintf(h,"\nSoapRequest(string soapmethod)\n{\n");
		fprintf(h,"\tsoapmessage = [ soap_version , soap_envelope, soap_body , soap_function, soap_parameters, soap_end_function, soap_end_body, soap_endvelope ];\n");
		fprintf(h,"\tsoaprequest = llDumpList2String( soapmessage, %c\\n%c );\n",__QUOTE,__QUOTE);
		fprintf(h,"\tsoap_id     = llHTTPRequest( base_url + soapmethod, [ HTTP_METHOD, \%cPOST\%c, HTTP_MIMETYPE, soapxmlfile, HTTP_VERIFY_CERT, FALSE ], soaprequest );\n",__QUOTE,__QUOTE);
		fprintf(h,"\tsoapmessage = [];\n");
		fprintf(h,"\tsoaprequest = \%c\%c;\n",__QUOTE,__QUOTE);
		fprintf(h,"\tif ( soap_id != NULL_KEY ) { requesting=1; llSetTimerEvent(timeout); } else { requesting=0; }\n");
	fprintf(h,"}\n");

	/* ------------ */
	/* SOAP HEADER  */
	/* ------------ */
	fprintf(h,"\nSoapHeader(string methodname)\n{\n");
	fprintf(h,"\tparalist   = [];\n");
	fprintf(h,"\tsoaparas   = [];\n");
	fprintf(h,"\tsoapvalues = [];\n");
    	fprintf(h,"\tsoap_function =  %c<tns:%c+methodname + %c xmlns:tns=\\%c%c + request_url + %c%s\\%c>%c;\n",
			__QUOTE,	__QUOTE, __QUOTE,	__QUOTE,
			__QUOTE,	__QUOTE, fptr->identifier, __QUOTE,__QUOTE);
	fprintf(h,"}\n");

	/* ----------------- */
	/* SOAP RETURN VALUE */
	/* ----------------- */
	fprintf(h,"\nstring SoapReturnValue( list tags, string pname)\n{\n");
	fprintf(h,"\tinteger i=0;\n");
	fprintf(h,"\tinteger start=0;\n");
	fprintf(h,"\tinteger finish=0;\n");
	fprintf(h,"\tstring  value=%c%c;\n",__QUOTE,__QUOTE);
	fprintf(h,"\tstart = llListFindList(  tags, [ pname ] );\n");
	fprintf(h,"\tif ( start != -1 )\n");
	fprintf(h,"\t{\n");
	fprintf(h,"\t\tfinish = llListFindList( tags, [ %c/%c+pname ] );\n",__QUOTE,__QUOTE);
    	fprintf(h,"\t\tif ( finish != -1 )\n");
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\t\tfor ( i=(start+5); i < finish; ++i)\n");
	fprintf(h,"\t\t\t{\n");
	fprintf(h,"\t\t\t\tif ( value == %c%c ) { value = llList2String( tags, i); }\n",__QUOTE,__QUOTE);
	fprintf(h,"\t\t\t\telse { value = value + %c %c + llList2String( tags, i );}\n",__QUOTE,__QUOTE);
	fprintf(h,"\t\t\t}\n");
	fprintf(h,"\t\t}\n");
	fprintf(h,"\t}\n");
	fprintf(h,"\treturn(value);\n");
	fprintf(h,"}\n");

	/* -------------- */
	/* SOAP PARAMETER */
	/* -------------- */
	fprintf(h,"\nSoapParameter(string pname, string pvalue)\n{\n");
	fprintf(h,"\tsoaparas   = ( soaparas = [] ) + soaparas + [ pname  ];\n");
	fprintf(h,"\tsoapvalues = ( soapvalues = [] ) + soapvalues + [ pvalue ];\n");
	fprintf(h,"}\n");

	/* ------------ */
	/* SOAP FOOTER  */
	/* ------------ */
	fprintf(h,"\nSoapFooter(string methodname)\n{\n");
	fprintf(h,"\tinteger i;\n");
	fprintf(h,"\tinteger l;\n");
	fprintf(h,"\tsoap_end_function = %c</tns:%c + methodname + %c>%c;\n",	
			__QUOTE,	__QUOTE, __QUOTE,	__QUOTE);
	fprintf(h,"\tl = llGetListLength( soaparas );\n");
	fprintf(h,"\tif ( l > 0 )\n");
	fprintf(h,"\t{\n");
	fprintf(h,"\t\tfor (i=0; i < l; ++i)\n");
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\tparameter=\%c<\%c + llList2String( soaparas, i) +  \%c xsd:type=\\%cxsd:string\\%c >\%c + llList2String( soapvalues, i ) + \%c</\%c + llList2String( soaparas, i ) + \%c>\%c;\n",
			__QUOTE,	__QUOTE, __QUOTE,	__QUOTE,
			__QUOTE,	__QUOTE, __QUOTE,	__QUOTE,
			__QUOTE,	__QUOTE, __QUOTE,	__QUOTE,
			__QUOTE,	__QUOTE, __QUOTE);

	fprintf(h,"\t\tparalist  = (paralist = []) + paralist + [ parameter ];\n");
	fprintf(h,"\t\t}\n");
	fprintf(h,"\t}\n");
 	fprintf(h,"\tsoap_parameters = llDumpList2String( paralist, %c\\n%c);\n",__QUOTE,__QUOTE);
	fprintf(h,"\tSoapRequest(methodname);\n");
	fprintf(h,"\n}\n");

	/* --------------------- */
	/* FILE SPECIFIC METHODS */
	/* --------------------- */
	for ( 	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
			continue;
		else if ((iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME )
			continue;
		else if (!( is_file_Widget(iptr ) ))
			continue;
		else if (!(dptr = iptr->Contents.extra ))
			continue;
		else if (!( fields = dptr->indexfields + dptr->datafields ))
			continue;
		else	{
			klen = dptr->indexlength;
			datalength = dptr->datalength;
			first= dptr->indexfields;
			break;
			}
		}

	if ((dptr) && (iptr)) {

		lsl_soap_put_object( h, iptr, dptr, fields );
		lsl_file_record_get( h, iptr );

		if ( WsGen.domenu ) {	lsl_file_record_show( h, iptr ); }

		fprintf(h,"\n%sMethod(string methodname)\n",iptr->Contents.name);
		fprintf(h,"{\n");
		fprintf(h,"\tSoapHeader(methodname);\n");
		fprintf(h,"\t%sPut();\n",iptr->Contents.name);
		fprintf(h,"\tSoapFooter(methodname);\n");
		fprintf(h,"}\n");

		}

	/* ------------------ */
	/* generate  events   */
	/* ------------------ */
	fprintf(h,"default \n{\n");

	/* ----------- */
	/* rez : event */
	/* ----------- */
	fprintf(h,"\ton_rez(integer count)\n\t{\n");
	fprintf(h,"\t\tllResetScript();\n");
	fprintf(h,"\t}\n");

	/* ------------- */
	/* entry : event */
	/* ------------- */
	fprintf(h,"\n\tstate_entry()\n");
	fprintf(h,"\t{\n\t\trequesting=0;\n");
	fprintf(h,"\t}\n");

	/* --------------- */
	/* listen :  event */
	/* --------------- */
	fprintf(h,"\n\tlisten(integer channel, string name, key id, string message)\n\t{\n");
	if ( iptr ) {
		if ( WsGen.domenu ) { lsl_file_menu_listen( h, iptr ); }
		}
	fprintf(h,"\t}\n");

	/* --------------- */
	/* touch :  event */
	/* --------------- */
	fprintf(h,"\n\ttouch(integer count)\n\t{\n");
	fprintf(h,"\t\tif ( requesting == 0 ) \n");
	fprintf(h,"\t\t{\n");
	if ( iptr ) {
		if ( WsGen.domenu ) { lsl_file_menu_touch( h, iptr ); }
		}
	fprintf(h,"\t\t}\n");
	fprintf(h,"\t}\n");

	/* --------------- */
	/* http_request :  event */
	/* --------------- */
	lsl_http_soap_response(h,fptr,classname);

	/* ------------- */
	/* timer : event */
	/* ------------- */
	fprintf(h,"\n\ttimer()\n\t{\n");
	fprintf(h,"\t\trequesting = 0;\n");
	fprintf(h,"\t\tllSetTimerEvent(0);\n");
	fprintf(h,"\t}\n");

	/* ------------------- */
	/* dataserver :  event */
	/* ------------------- */
	fprintf(h,"\n\tdataserver(key queryid, string data )\n\t{\n");
	fprintf(h,"\t}\n");

	/* --------------------- */
	/* link_message :  event */
	/* --------------------- */
	fprintf(h,"\n\tlink_message( integer sender_num, integer num, string str, key id )\n\t{\n");
	fprintf(h,"\t}\n");

	/* --------------- */
	/* sensor :  event */
	/* --------------- */
	fprintf(h,"\n\tsensor( integer detected )\n\t{\n");
	fprintf(h,"\t}\n");

	/* --------------- */
	/* changed :  event */
	/* --------------- */
	fprintf(h,"\n\tchanged(integer change)\n\t{\n");
        fprintf(h,"\t\tif (change & CHANGED_OWNER)\n");
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\t\tllResetScript();\n");
	fprintf(h,"\t\t}\n");
	fprintf(h,"\t}\n");

	/* ------------ */
	/* exit : event */
	/* ------------ */
	fprintf(h,"\n\tstate_exit()\n\t{\n");
	fprintf(h,"\t}\n");


	fprintf(h,"\n}\n");

	lsl_close_stream( h, fptr );
	return;
}

public	void	generate_lsl_soap_client (
	struct file_control * optr, 
	char * nptr, 
	int nlen  )
{
	FILE	*	h;

	struct	form_item    * wptr=(struct form_item    *) 0;
	struct	data_control * dptr=(struct data_control *) 0;
	struct	form_control * fptr=(struct form_control *) 0;
	
	if (!( optr )) 
		return(-1); 
	else if (!( dptr = optr->payload )) 
		return(-1); 

	limit_right_space( nptr,nlen);

	if (!( nptr = allocate_string( nptr )))
		return(-1);
	if (!( nptr = enforce_extension( nptr, ".lsl" )))
		return(-1);
	else if (!(h = open_production_target(nptr,0)))
		return(-1);
	else if (!( fptr = allocate_Form("webservice"))) {
		close_production_target( h, nptr );
		return(-1);
		}
	else if (!( wptr = allocate_for_Widget())) {
		close_production_target( h, nptr );
		return(-1);
		}
	else if (!( wptr->Contents.format = allocate( strlen( optr->classname ) + 8 ) )) {
		close_production_target( h, nptr );
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
		lsl_soap_client(h,fptr,optr->classname);
		close_production_target( h, nptr );
		return;
		}
}

		/*	---------------------------------	*/
		/*	H T M L    S O A P    C L I E N T	*/
		/*	---------------------------------	*/


static	void	html_start_stream(FILE * h, struct form_control *  fptr )
{
	char	wbuffer[512];
	if ( h ) {
		html_doc_type(h,0);
		html_tag(h,"html");
		html_tag(h,"head"); 
		linefeed(h);
		html_content_type(h);
		html_generator(h);
		html_link_style(h, "style.css", "screen");
		html_link_style(h, "style.css", "print");
		sprintf(wbuffer,"soap client for the web service %s",fptr->identifier);
		html_title(h,wbuffer);
		html_closure(h,"head");
		html_tag(h,"body");
		html_open_align(h,3);
		linefeed(h);
		}
	return;
}

static	void	html_close_stream( FILE * h, struct form_control *  fptr )
{
	if ( h ) {
		linefeed(h);
		html_close_align(h,3);
		linefeed(h);
		html_closure(h,"body");
		linefeed(h);
		html_closure(h,"html");
		linefeed(h);
		}
	return;
}

static	void	html_file_method( FILE * h, char * prefix, char * nptr, char * fptr )
{
	char	nbuffer[256];
	char	abuffer[256];
	html_tag(h,"td");
	sprintf(nbuffer,"%s%s",prefix,nptr);
	sprintf(abuffer,"/%s%s",prefix,nptr);
	html_form(h,nbuffer,abuffer,"multipart/form-data","POST");
	html_bordered_table( h, 1, 2, 2 );
	linefeed(h);
	html_tag(h,"tr");
	html_tag(h,"th");
		html_text(h,nbuffer);
		html_closure(h,"th");
	linefeed(h);
	html_tag(h,"td");
		html_input_file(h,"message",fptr);
		linefeed(h);
		html_input_submit(h,nbuffer);
		linefeed(h);
		html_closure(h,"td");
	linefeed(h);
	html_closure(h,"table");
	html_closure(h,"form");
	html_closure(h,"td");
	linefeed(h);
	return;
}


static	void	html_soap_client   (FILE * h, struct form_control *  fptr, char * classname )
{
	struct	form_item * iptr;
	struct	data_control * 	dptr;
	int	fields;
	int	first=0;
	int	datalength;
	int	klen;

	html_start_stream(h, fptr );
	
	/* --------------------- */
	/* FILE SPECIFIC METHODS */
	/* --------------------- */
	for ( 	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
			continue;
		else if ((iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME )
			continue;
		else if (!( is_file_Widget(iptr ) ))
			continue;
		else if (!(dptr = iptr->Contents.extra ))
			continue;
		else if (!( fields = dptr->indexfields + dptr->datafields ))
			continue;
		else	{
			klen = dptr->indexlength;
			datalength = dptr->datalength;
			first= dptr->indexfields;
			break;
			}
		}

	if ((dptr) && (iptr)) {

		html_bordered_table( h, 1, 2, 2 );
		linefeed(h);
		html_tag(h,"tr"); linefeed(h);
		html_file_method(h,classname,"Create","cfile.xml");
		html_tag(h,"tr"); linefeed(h);
		html_file_method(h,classname,"First","first.xml");
		html_tag(h,"tr"); linefeed(h);
		html_file_method(h,classname,"Down","down.xml");
		html_tag(h,"tr"); linefeed(h);
		html_file_method(h,classname,"Insert","insert.xml");
		html_tag(h,"tr"); linefeed(h);
		html_file_method(h,classname,"Modif","modif.xml");
		html_tag(h,"tr"); linefeed(h);
		html_file_method(h,classname,"Search","search.xml");
		html_tag(h,"tr"); linefeed(h);
		html_file_method(h,classname,"Posit","posit.xml");
		html_tag(h,"tr"); linefeed(h);
		html_file_method(h,classname,"Count","count.xml");
		html_tag(h,"tr"); linefeed(h);
		html_file_method(h,classname,"Delete","delete.xml");
		html_tag(h,"tr"); linefeed(h);
		html_file_method(h,classname,"Up","up.xml");
		html_tag(h,"tr"); linefeed(h);
		html_file_method(h,classname,"Last","last.xml");
		html_closure(h,"table");
		linefeed(h);
		}

	html_close_stream( h, fptr );
	return;
}

public	void	generate_html_soap_client (
	struct file_control * optr, 
	char * nptr, 
	int nlen  )
{
	FILE	*	h;

	struct	form_item    * wptr=(struct form_item    *) 0;
	struct	data_control * dptr=(struct data_control *) 0;
	struct	form_control * fptr=(struct form_control *) 0;
	
	if (!( optr )) 
		return(-1); 
	else if (!( dptr = optr->payload )) 
		return(-1); 

	limit_right_space( nptr,nlen);

	if (!( nptr = allocate_string( nptr )))
		return(-1);
	if (!( nptr = enforce_extension( nptr, ".html" )))
		return(-1);
	else if (!(h = open_production_target(nptr,0)))
		return(-1);
	else if (!( fptr = allocate_Form(nptr))) {
		close_production_target( h, nptr );
		return(-1);
		}
	else if (!( wptr = allocate_for_Widget())) {
		close_production_target( h, nptr );
		return(-1);
		}
	else if (!( wptr->Contents.format = allocate( strlen( optr->classname ) + 8 ) )) {
		close_production_target( h, nptr );
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
		html_soap_client(h,fptr,optr->classname);
		close_production_target( h, nptr );
		return;
		}
}

public	int	lsl_generate_soap_client( struct form_control * fptr , char * target, char * classname )
{
	char	*	nptr;
	FILE	*	h;
	if (!( nptr = allocate_string( target )))
		return(-1);
	else if (!( nptr = enforce_extension( nptr, ".lsl" )))
		return(-1);
	else if (!(h = open_production_target(nptr,0)))
		return(-1);
	else	{
		lsl_soap_client(h,fptr,classname);
		close_production_target( h, nptr );
		return(0);
		}
}

public	int	html_generate_soap_client( struct form_control * fptr , char * target, char * classname )
{
	char	*	nptr;
	FILE	*	h;
	if (!( nptr = allocate_string( target )))
		return(-1);
	else if (!( nptr = enforce_extension( nptr, ".html" )))
		return(-1);
	else if (!(h = open_production_target(nptr,0)))
		return(-1);
	else	{
		html_soap_client(h,fptr,classname);
		close_production_target( h, nptr );
		return(0);
		}
}

#endif	/* _singlsl_c */
	/* ---------- */


