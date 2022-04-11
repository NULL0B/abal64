#ifndef	_EXWSDL_C
#define	_EXWSDL_C

BPTR procedure_data_table(EXAWORD);

/*	----------------------------------------------------------	*/
/*		g e n e r a t e _ w s d l _ p r o c e d u r e 		*/
/*	----------------------------------------------------------	*/
/*	generates a message statement with parameter types for the	*/
/*	procedural methods.						*/
/*	----------------------------------------------------------	*/
static	int	generate_wsdl_procedure( struct abal_program_handle * hptr, FILE * h, char * name, char * hostname, char * datatable )
{
	int	vid=0;
	int	vtype=0;
	int	vcount=0;
	if (!( datatable ))
		fprintf(h,"<wsdl:message name='%sIn'/>\n",name);
	else
	{
		fprintf(h,"<wsdl:message name='%sIn'>\n",name);
		if ((vcount = Tcodeword( datatable )) != 0)
		{
			datatable += ( WORDSIZE * 3 );
			while ( vcount )
			{
				/* detect procedure parameter by ARG */
				/* --------------------------------- */
				vtype = Tcodeword( datatable );
				datatable += WORDSIZE;
				if (!( vtype & VARB_ARG ))
					break;
				else  	
				{
					fprintf(h,"<wsdl:part name='p%u' type='",++vid);
					switch( vtype & VARB_ISOL )
					{
					case VARB_FOUR 	:
					case VARB_INT8 	: 
					case VARB_INT16 : 
					case VARB_INT32 : 
					case VARB_INT64 : 
						fprintf(h,"xsd:integer");
						break;

					case VARB_BCD	:
						fprintf(h,"xsd:numeric");
						break;

					case VARB_STR	:
						fprintf(h,"xsd:string");
						break;

					}
					fprintf(h,"'/>");
				}
			
				/* step over offset and eventual base */
				/* ---------------------------------- */
				datatable += WORDSIZE;
				if (( vtype & SPECIALE )
				&&  ( (vtype &  SPECIALE) != (ISDYNAMIC | ISPOINTER) ))
				{
					datatable += WORDSIZE;
				}

				/* step over eventual string length */
				/* -------------------------------- */
				switch ( vtype & VARB_ISOL ) 
				{
				case VARB_FOUR 	:
				case VARB_INT8 	: 
				case VARB_INT16 : 
				case VARB_INT32 : 
				case VARB_INT64 : 
					break;
				default		:
					datatable += WORDSIZE;
					break;
				}

				/* step over eventual index information */
				/* ------------------------------------ */
				if ( vtype & NDX1st )
				{
					datatable += WORDSIZE;
					if ( vtype & NDX2nd )
					{
						datatable += WORDSIZE;
					}
				}
				vcount--;
			}
		}
		fprintf(h,"</wsdl:message>\n");
	}
	fprintf(h,"<wsdl:message name='%sOut'>",name);
 	fprintf(h,"<wsdl:part name='r53' type='xsd:string'/>");
	fprintf(h,"</wsdl:message>\n");
	return(0);
}

/*	----------------------------------------------------------	*/
/*		g e n e r a t e _ w s d l _ s e g m e n t		*/
/*	----------------------------------------------------------	*/
/*	generates a message statement for segmental methods.		*/
/*	----------------------------------------------------------	*/
static	int	generate_wsdl_segment( struct abal_program_handle * hptr, FILE * h, char * name, char * hostname )
{
	fprintf(h,"<wsdl:message name='%sIn'/>\n",name);
	fprintf(h,"<wsdl:message name='%sOut'/>\n",name);
	return(0);
}

/*	----------------------------------------------------------	*/
/*		g e n e r a t e _ w s d l _ m e s s a g e s 		*/
/*	----------------------------------------------------------	*/
/*	generates the "message" statements providing descriptions	*/
/*	of the various messages comprising the port types for each	*/
/*	procedure and all segments.					*/
/*	----------------------------------------------------------	*/
static	int	generate_wsdl_messages( struct abal_program_handle * hptr, FILE * h, char * hostname )
{
	int	i;
	char *	datatable;
	char	name[256];

	/* ---------------------- */
	/* standard fault message */
	/* ---------------------- */
	fprintf(h,"<wsdl:message name='Fault'>\n");
	fprintf(h,"<wsdl:part name='message' type='xsd:string'/>\n");
	fprintf(h,"<wsdl:part name='value' type='xsd:string'/>\n");
	fprintf(h,"</wsdl:message>\n");

	/* ----------------------------------- */
	/* one message pair for each procedure */
	/* ----------------------------------- */
	for (	i=0; i < hptr->procedures; i++ )
	{
		sprintf(name,"p%u",(i+1));
		generate_wsdl_procedure( hptr, h, name, hostname, 
			procedure_data_table(i) );
	}
	/* --------------------------------- */
	/* one message pair for each segment */
	/* --------------------------------- */
	for (	i=0; i < hptr->segments; i++ )
	{
		sprintf(name,"s%u",(i+1));
		generate_wsdl_segment( hptr, h, name, hostname );
	}
	return(0);
}

/*	----------------------------------------------------------	*/
/*		g e n e r a t e _ w s d l _ p o r t t y p e 		*/
/*	----------------------------------------------------------	*/
/*	generates an individual porttype statement for the service	*/
/*	name. these comprise the different message descriptions		*/
/*	for the input, output and fault messages.			*/
/*	----------------------------------------------------------	*/
static	int	generate_wsdl_portType( struct abal_program_handle * hptr, FILE * h, char * name, char * hostname )
{
	fprintf(h,"<wsdl:portType name='%s' type='tns:%s'>\n",name,name);
		fprintf(h,"<wsdl:operation name='%s'>\n",name);
		fprintf(h,"<wsdl:input message='tns:%sIn'/>\n",name);
		fprintf(h,"<wsdl:output message='tns:%sOut'/>\n",name);
		fprintf(h,"<wsdl:fault name='Fault' message='tns:Fault'/>\n");
		fprintf(h,"</wsdl:operation>\n");
	fprintf(h,"</wsdl:portType>\n");
	return(0);
}

/*	----------------------------------------------------------	*/
/*		g e n e r a t e _ w s d l _ p o r t t y p e s		*/
/*	----------------------------------------------------------	*/
/*	generates the "porttype" statements providing description	*/
/*	of the different service entry points for all procedures 	*/
/*	and all segments.						*/
/*	----------------------------------------------------------	*/
int	generate_wsdl_porttypes( struct abal_program_handle * hptr, FILE * h, char * hostname )
{
	int	i;
	char	name[256];
	for (	i=0; i < hptr->procedures; i++ )
	{
		sprintf(name,"p%u",(i+1));
		generate_wsdl_portType( hptr, h, name, hostname );
	}
	for (	i=0; i < hptr->segments; i++ )
	{
		sprintf(name,"s%u",(i+1));
		generate_wsdl_portType( hptr, h, name, hostname );
	}
	return(0);
}

/*	----------------------------------------------------------	*/
/*		g e n e r a t e _ s o a p _ e n c o d i n g		*/
/*	----------------------------------------------------------	*/
/*	generates a standardised soap encoding statement.		*/
/*	----------------------------------------------------------	*/
static	int	generate_soap_encoding( FILE *  h )
{
	fprintf(h,"<soap:body use='encoded' soap:encodingStyle='http://www.w3.org/2003/05/soap-encoding'/>\n");
	return(0);
}

/*	----------------------------------------------------------	*/
/*		g e n e r a t e _ w s d l _ b i n d i n g s		*/
/*	----------------------------------------------------------	*/
/*	generates individual binding statements for the indicated	*/
/*	method name. these describe the soap action and the rpc		*/
/*	transport type for use over http.				*/
/*	----------------------------------------------------------	*/
static	int	generate_wsdl_binding( struct abal_program_handle * hptr, FILE * h, char * name, char * hostname )
{
	fprintf(h,"<wsdl:binding name='%s' type='tns:%s'>\n",name,name);
		fprintf(h,"<soap:binding style='rpc' transport='http://schemas.xmlsoap.org/soap/http'/>\n");
		fprintf(h,"<wsdl:operation name='%s'>\n",name);
			fprintf(h,"<soap:operation soapAction='http://%s/%s' style='rpc'/>\n",hostname,hptr->program);
			fprintf(h,"<wsdl:input message='tns:%sIn'>\n",name);
				generate_soap_encoding( h );
			fprintf(h,"</wsdl:input>\n");
			fprintf(h,"<wsdl:output message='tns:%sOut'>\n",name);
				generate_soap_encoding( h );
			fprintf(h,"</wsdl:output>\n");
			fprintf(h,"<wsdl:fault name='Fault' message='tns:Fault'>\n");
				generate_soap_encoding( h );
			fprintf(h,"</wsdl:fault>\n");
		fprintf(h,"</wsdl:operation>\n");
	fprintf(h,"</wsdl:binding>\n");
	return(0);
}

/*	----------------------------------------------------------	*/
/*		g e n e r a t e _ w s d l _ b i n d i n g s		*/
/*	----------------------------------------------------------	*/
/*	generates the "binding" statements providing access nature	*/
/*	for the different service entry points for all procedures 	*/
/*	and all segments.						*/
/*	----------------------------------------------------------	*/
static	int	generate_wsdl_bindings( struct abal_program_handle * hptr, FILE * h, char * hostname )
{
	int	i;
	char	name[256];
	for (	i=0; i < hptr->procedures; i++ )
	{
		sprintf(name,"p%u",(i+1));
		generate_wsdl_binding(hptr, h, name, hostname );
	}
	for (	i=0; i < hptr->segments; i++ )
	{
		sprintf(name,"s%u",(i+1));
		generate_wsdl_binding(hptr, h, name, hostname );
	}
	return(0);
}

/*	----------------------------------------------------------	*/
/*		g e n e r a t e _ w s d l _ s e r v i c e 		*/
/*	----------------------------------------------------------	*/
/*	generates an individual service entry point record for the	*/
/*	provided method name.						*/
/*	----------------------------------------------------------	*/
static	int	generate_wsdl_service( struct abal_program_handle * hptr, FILE * h, char * name, char * hostname )
{
	fprintf(h,"<wsdl:service name='%s'>\n",name);
	fprintf(h,"<wsdl:port name='%s' type='tns:%s'>\n",name,name);
	fprintf(h,"<soap:address location='http://%s/%s'/>\n",hostname,name);
	fprintf(h,"</wsdl:port>\n");
	fprintf(h,"</wsdl:service>\n");
	return(0);
}

/*	----------------------------------------------------------	*/
/*		g e n e r a t e _ w s d l _ s e r v i c e s		*/
/*	----------------------------------------------------------	*/
/*	generates the "service" statements describing the toplevel	*/
/*	service entry points for all procedures and all segments.	*/
/*	----------------------------------------------------------	*/
static	int	generate_wsdl_services( struct abal_program_handle * hptr, FILE * h, char * hostname )
{
	int	i;
	char	name[256];
	for (	i=0; i < hptr->procedures; i++ )
	{
		sprintf(name,"p%u",(i+1));
		generate_wsdl_service(hptr, h, name, hostname );
	}
	for (	i=0; i < hptr->segments; i++ )
	{
		sprintf(name,"s%u",(i+1));
		generate_wsdl_service(hptr, h, name, hostname );
	}
	return(0);
}

/*	----------------------------------------------------------	*/
/*		G e n e r a t e W s d l I n t e r f a c e		*/
/*	----------------------------------------------------------	*/
/*	this function drives generation of the WSDL file produced	*/
/*	to describe the abal program in terms of its procedures 	*/
/*	and segments for use by remote SOAP clients.			*/
/*	----------------------------------------------------------	*/
static	int	GenerateWsdlInterface( struct abal_program_handle * hptr, char * filename, char * hostname )
{
	FILE *	h;
	if (!( h = fopen( filename,"w") ))
		return(SOFTERROR);
	else
	{
		fprintf(h,"<?xml version='1.0' encoding='ISO-8859-1'?>\r\n");
		fprintf(h,"<wsdl:definitions xmlns:wsdl='http://schemas.xmlsoap.org/wsdl/' xmlns:soap='http://schemas.xmlsoap.org/wsdl/soap/' xmlns:tns='%s/%s' xmlns:xsd='http://www.w3.org/2001/XMLSchema/'>\n",hostname,hptr->program); 
		generate_wsdl_messages(hptr, h, hostname);
		generate_wsdl_porttypes(hptr, h, hostname);
		generate_wsdl_bindings(hptr, h, hostname);
		generate_wsdl_services(hptr, h, hostname);
		fprintf(h,"</wsdl:definitions>\n"); 
		fclose(h);
		return(GOODRESULT);
	}
}

	/* --------- */
#endif	/* _EXWSDL_C */
	/* --------- */


