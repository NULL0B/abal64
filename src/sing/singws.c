#ifndef	_singws_c
#define	_singws_c

/*	--------------------------------------		*/
/*	Second Life and Web Service Production		*/
/*	--------------------------------------		*/

#include <stdio.h>
#include "sing.h"
#include "palet.h"
#include "stdpsu.h"
#include "guimouse.h"
#include "singrel.h"
#include "singpix.h"
#include "allocate.h"
#define	_SYSTEM_IMAGES
#include "sysimage.h"
#include "stdimage.h"
#include "singlang.h"
#include "singedit.h"
#include "singprod.h"
#include "singpage.h"
#include "singpars.h"

#include "singpal.h"
#include "singbar.h"
#include "singmenu.h"
#include "singtool.h"
#include "singtext.h"
#include "abaldata.h"
#include "singfile.h"
static	WsNameBuffer[1024];

static	FILE *	ws_open_production_stream( char * nptr, char * xptr )
{
	FILE * h=(FILE *) 0;
	if (!( nptr ))
		return(h);
	else if (!( xptr ))
		return( h );
	else	{
		sprintf( WsNameBuffer,"%s%s",nptr, xptr );
		return( fopen( WsNameBuffer, "w" ) );
		}
}


static	FILE *	ws_start_module_stream( struct form_control *  fptr ) 
{
	FILE * h;
	if (!( h = ws_open_production_stream( fptr->identifier, ".as" )))
		return(h);
	else	{

		return( h );
		}
}

static	void	ws_close_module_stream( FILE * h, struct form_control *  fptr ) 
{
	if ( h ) {
		fclose( h );
		}
	return;
}


static	void	ws_generate_client_module( struct form_control *  fptr )
{
	struct	form_item * iptr;
	FILE *	h;
	if (!( h = ws_start_module_stream( fptr )))
		return;
	ws_close_module_stream( h, fptr );
	return;
}

static	FILE *	ws_start_extern_stream( struct form_control *  fptr ) 
{
	FILE * h;
	if (!( h = ws_open_production_stream( fptr->identifier, ".ext" )))
		return(h);
	else	{

		return( h );
		}
}

static	void	ws_close_extern_stream( FILE * h, struct form_control *  fptr ) 
{
	if ( h ) {
		fclose( h );
		}
	return;
}


static	void	ws_generate_client_extern( struct form_control *  fptr )
{
	struct	form_item * iptr;
	FILE *	h;
	if (!( h = ws_start_extern_stream( fptr )))
		return;
	ws_close_extern_stream( h, fptr );
	return;
}

static	FILE *	ws_start_class_stream( struct form_control *  fptr ) 
{
	FILE * h;
	if (!( h = ws_open_production_stream( fptr->identifier, ".cls" )))
		return(h);
	else	{

		return( h );
		}
}

static	void	ws_close_class_stream( FILE * h, struct form_control *  fptr ) 
{
	if ( h ) {
		fclose( h );
		}
	return;
}


static	void	ws_generate_client_class ( struct form_control *  fptr )
{
	struct	form_item * iptr;
	FILE *	h;
	if (!( h = ws_start_class_stream( fptr )))
		return;
	ws_close_class_stream( h, fptr );
	return;
}

static	FILE *	ws_start_form_stream( struct form_control *  fptr ) 
{
	FILE * h;
	if (!( h = ws_open_production_stream( fptr->identifier, ".xml" )))
		return(h);
	else	{

		return( h );
		}
}

static	void	ws_close_form_stream( FILE * h, struct form_control *  fptr ) 
{
	if ( h ) {
		fclose( h );
		}
	return;
}


static	void	ws_generate_test_client  ( struct form_control *  fptr )
{
	struct	form_item * iptr;
	FILE *	h;
	if (!( h = ws_start_form_stream( fptr )))
		return;
	ws_close_form_stream( h, fptr );
	return;
}

static	FILE *	ws_start_wsdl_stream( struct form_control *  fptr ) 
{
	FILE * h;
	if (!( h = ws_open_production_stream( fptr->identifier, ".wsdl" )))
		return(h);
	else	{

		return( h );
		}
}

static	void	ws_close_wsdl_stream( FILE * h, struct form_control *  fptr ) 
{
	if ( h ) {
		fclose( h );
		}
	return;
}


static	void	ws_generate_wsdl_document( struct form_control *  fptr )
{
	struct	form_item * iptr;
	FILE *	h;
	if (!( h = ws_start_wsdl_stream( fptr )))
		return;
	ws_close_wsdl_stream( h, fptr );
	return;
}

static	FILE *	ws_start_wsi_stream( struct form_control *  fptr ) 
{
	FILE * h;
	if (!( h = ws_open_production_stream( fptr->identifier, ".wsi" )))
		return(h);
	else	{

		return( h );
		}
}

static	void	ws_close_wsi_stream( FILE * h, struct form_control *  fptr ) 
{
	if ( h ) {
		fclose( h );
		}
	return;
}


static	void	ws_generate_wsi_document ( struct form_control *  fptr )
{
	struct	form_item * iptr;
	FILE *	h;
	if (!( h = ws_start_wsi_stream( fptr )))
		return;
	ws_close_wsi_stream( h, fptr );
	return;
}

static	void	ws_generate_server_module( struct form_control *  fptr )
{
	struct	form_item * iptr;
	FILE *	h;
	if (!( h = ws_start_module_stream( fptr )))
		return;
	ws_close_module_stream( h, fptr );
	return;
}

static	FILE *	ws_start_lsl_stream( struct form_control *  fptr ) 
{
	FILE * h;
	if (!( h = ws_open_production_stream( fptr->identifier, ".lsl" )))
		return(h);
	else	{
		fprintf(h,"// --------------------------------------------------------------- \n");
		fprintf(h,"// top of file : %s%s \n",fptr->identifier, ".lsl" );
		fprintf(h,"// --------------------------------------------------------------- \n");
		fprintf(h,"// SOAP Data Base Access Module \n");
		fprintf(h,"// --------------------------------------------------------------- \n");
		fprintf(h,"// This file has been generated and should not be modified by hand \n");
		fprintf(h,"// --------------------------------------------------------------- \n");
		return( h );
		}
}

static	void	ws_close_lsl_stream( FILE * h, struct form_control *  fptr ) 
{
	if ( h ) {
		fprintf(h,"// --------------------------------------------------------------- \n");
		fprintf(h,"// end of file : %s%s \n",fptr->identifier, ".lsl" );
		fprintf(h,"// --------------------------------------------------------------- \n");
		fclose( h );
		}
	return;
}


static	void	ws_generate_lsl_client   ( struct form_control *  fptr )
{
	struct	form_item * iptr;
	FILE *	h;
	struct	data_control * 	dptr;
	int	fields;
	int	first=0;
	int	datalength;
	int	klen;

	if (!( h = ws_start_lsl_stream( fptr )))
		return;
	
	fprintf(h,"key   \tsoap_id;\n");
	fprintf(h,"list  \tsoaparas          = [];\n");
	fprintf(h,"list  \tsoapvalues        = [];\n");
	fprintf(h,"list  \tsoapmessage       = [];\n");
	fprintf(h,"string\tsoapresult        = %c%c;\n",0x0022,0x0022);
	fprintf(h,"string\tsoaprequest       = %c%c;\n",0x0022,0x0022);
	fprintf(h,"string\tsoap_version      = %c<?xml version=\\%c1.0\\%c encoding=\\%cISO-8859-1\\%c?>%c;\n",0x0022,0x0022,0x0022,0x0022,0x0022,0x0022);
	fprintf(h,"string\tsoap_envelope     = %c<SOAP-ENV:Envelope xmlns:SOAP-ENV=\\%chttp://schemas.xmlsoap.org/soap/envelope/\\%c SOAP-ENV:encodingStyle=\\%chttp://schemas.xmlsoap.org/soap/encoding/\\%c>%c;\n",0x0022,0x0022,0x0022,0x0022,0x0022,0x0022);
	fprintf(h,"string\tsoap_body         = %c<SOAP-ENV:Body>%c;\n",0x0022,0x0022);
	fprintf(h,"string\tsoap_function     = %c%c;\n",0x0022,0x0022);
	fprintf(h,"string\tsoap_parameters   = %c%c;\n",0x0022,0x0022);
	fprintf(h,"string\tsoap_end_function = %c%c;\n",0x0022,0x0022);
	fprintf(h,"string\tsoap_end_body     = %c</SOAP-ENV:Body>%c;\n",0x0022,0x0022);
	fprintf(h,"string\tsoap_endvelope    = %c</SOAP-ENV:Envelope>%c;\n",0x0022,0x0022);
	fprintf(h,"string\tbase_url          = %chttps://abal.prologue.fr/%c;\n",0x0022,0x0022);
	fprintf(h,"string\trequest_url       = %chttps://abal.prologue.fr/home/stock/%c;\n",0x0022,0x0022);
	fprintf(h,"string\tparameter         = %c%c;\n",0x0022,0x0022);
	fprintf(h,"list\tparalist          = [];\n");

	/* ------------------ */
	/* generate variables */
	/* ------------------ */
	for ( 	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		
		if ((iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME )
			continue;
		else if (!( is_file_Widget( iptr ) ))
			continue;
		else if (!(dptr = iptr->Contents.extra ))
			continue;
		else if (!( fields = dptr->indexfields + dptr->datafields ))
			continue;
		else	{
			klen = dptr->indexlength;
			datalength = dptr->datalength;
			first= dptr->indexfields;
			}
		}

	/* ------------------ */
	/* generate methods   */
	/* ------------------ */
	fprintf(h,"\nSoapRequest(string soapmethod)\n{\n");
		fprintf(h,"\tsoapmessage = [ soap_version , soap_envelope, soap_body , soap_function, soap_parameters, soap_end_function, soap_end_body, soap_endvelope ];\n");
		fprintf(h,"\tsoaprequest = llDumpList2String( soapmessage, %c\\n%c );\n",0x0022,0x0022);
		fprintf(h,"\tsoap_id     = llHTTPRequest( base_url + soapmethod, [ HTTP_METHOD, \%cPOST\%c, HTTP_VERIFY_CERT, FALSE ], soaprequest );\n",0x0022,0x0022);
		fprintf(h,"\tsoapmessage = [];\n");
		fprintf(h,"\tsoaprequest = \%c\%c;\n",0x0022,0x0022);
	fprintf(h,"\n}\n");

	fprintf(h,"\nSoapHeader(string methodname)\n{\n");
	fprintf(h,"\tsoaparas   = [];\n");
	fprintf(h,"\tsoapvalues = [];\n");
    	fprintf(h,"\tsoap_function =  %c<tns:%c+methodname + %c xmlns:tns=\\%c%c + request_url + %c%s\\%c>%c;\n",
			0x0022,	0x0022, 0x0022,	0x0022,
			0x0022,	0x0022, fptr->identifier, 0x0022,0x0022);
	fprintf(h,"\n}\n");

	fprintf(h,"\nSoapParameter(string pname, string pvalue)\n{\n");
	fprintf(h,"\tsoaparas   = [ pname  ];\n");
	fprintf(h,"\tsoapvalues = [ pvalue ];\n");
	fprintf(h,"\n}\n");

	fprintf(h,"\nSoapFooter(string methodname)\n{\n");
	fprintf(h,"\tinteger i;\n");
	fprintf(h,"\tinteger l;\n");
	fprintf(h,"\tsoap_end_function = %c</tns:%c + methodname + %c>%c;\n",	
			0x0022,	0x0022, 0x0022,	0x0022);

	fprintf(h,"\tl = llGetListLength( soaparas );\n");
	fprintf(h,"\tif ( l > 0 )\n");
	fprintf(h,"\t{\n");
	fprintf(h,"\t\tfor (i=0; i < l; ++i)\n");
	fprintf(h,"\t\t{\n");
	fprintf(h,"\t\tparameter=\%c<\%c + llList2String( soaparas, i) +  \%c xsd:type=\\%cxsd:string\\%c >\%c + llList2String( soapvalues, i ) + \%c</\%c + llList2String( soaparas, 0 ) + \%c>\%c;\n",
			0x0022,	0x0022, 0x0022,	0x0022,
			0x0022,	0x0022, 0x0022,	0x0022,
			0x0022,	0x0022, 0x0022,	0x0022,
			0x0022,	0x0022, 0x0022);

	fprintf(h,"\t\tparalist  = (paralist = []) + paralist + [ parameter ];\n");
	fprintf(h,"\t\t}\n");
	fprintf(h,"\t}\n");

 	fprintf(h,"\tsoap_parameters = llDumpList2String( paralist, %c\\n%c);\n",0x0022,0x0022);




	fprintf(h,"\tSoapRequest(methodname);\n");
	fprintf(h,"\n}\n");


	for ( 	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if ((iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME )
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
			fprintf(h,"\n%sFirst()\n",iptr->Contents.name);
			fprintf(h,"{\n");
			fprintf(h,"\tSoapHeader(%c%sFirst%c);\n",0x0022,iptr->Contents.name,0x0022);
			fprintf(h,"\tSoapFooter(%c%sFirst%c);\n",0x0022,iptr->Contents.name,0x0022);
			fprintf(h,"}\n");

			fprintf(h,"\n%sRead(string index)\n",iptr->Contents.name);
			fprintf(h,"\{\n");
			fprintf(h,"\tSoapHeader(%c%sRead%c);\n",0x0022,iptr->Contents.name,0x0022);
			fprintf(h,"\tSoapParameter(%cref%c,index);\n",0x0022,0x0022);
			fprintf(h,"\tSoapFooter(%c%sRead%c);\n",0x0022,iptr->Contents.name,0x0022);
			fprintf(h,"}\n");

			fprintf(h,"\n%sWrite(string index, string buffer)\n",iptr->Contents.name);
			fprintf(h,"{\n");
			fprintf(h,"\tSoapHeader(%c%sWrite%c);\n",0x0022,iptr->Contents.name,0x0022);
			fprintf(h,"\tSoapParameter(%cref%c,index);\n",0x0022,0x0022);
			fprintf(h,"\tSoapParameter(%cbuf%c,buffer);\n",0x0022,0x0022);
			fprintf(h,"\tSoapFooter(%c%sWrite%c);\n",0x0022,iptr->Contents.name,0x0022);
			fprintf(h,"}\n");

			fprintf(h,"\n%sDelete(string index)\n",iptr->Contents.name);
			fprintf(h,"{\n");
			fprintf(h,"\tSoapHeader(%c%sDelete%c);\n",0x0022,iptr->Contents.name,0x0022);
			fprintf(h,"\tSoapParameter(%cref%c,index);\n",0x0022,0x0022);
			fprintf(h,"\tSoapFooter(%c%sDelete%c);\n",0x0022,iptr->Contents.name,0x0022);
			fprintf(h,"}\n");

			fprintf(h,"\n%sNext()\n",iptr->Contents.name);
			fprintf(h,"{\n");
			fprintf(h,"\tSoapHeader(%c%sNext%c);\n",0x0022,iptr->Contents.name,0x0022);
			fprintf(h,"\tSoapFooter(%c%sNext%c);\n",0x0022,iptr->Contents.name,0x0022);
			fprintf(h,"}\n");

			fprintf(h,"\n%sPrevious()\n",iptr->Contents.name);
			fprintf(h,"{\n");
			fprintf(h,"\tSoapHeader(%c%sPrevious%c);\n",0x0022,iptr->Contents.name,0x0022);
			fprintf(h,"\tSoapFooter(%c%sPrevious%c);\n",0x0022,iptr->Contents.name,0x0022);
			fprintf(h,"}\n");

			fprintf(h,"\n%sLast()\n",iptr->Contents.name);
			fprintf(h,"{\n");
			fprintf(h,"\tSoapHeader(%c%sLast%c);\n",0x0022,iptr->Contents.name,0x0022);
			fprintf(h,"\tSoapFooter(%c%sLast%c);\n",0x0022,iptr->Contents.name,0x0022);
			fprintf(h,"}\n");
			}

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
	fprintf(h,"\n\t}\n");

	/* ------------- */
	/* entry : event */
	/* ------------- */
	fprintf(h,"\tstate_entry()\n\t{\n");
	fprintf(h,"\n\t}\n");

	/* ------------ */
	/* exit : event */
	/* ------------ */
	fprintf(h,"\tstate_exit()\n\t{\n");
	fprintf(h,"\n\t}\n");

	/* ------------- */
	/* timer : event */
	/* ------------- */
	fprintf(h,"\ttimer()\n\t{\n");
	fprintf(h,"\n\t}\n");

	/* --------------- */
	/* listen :  event */
	/* --------------- */
	fprintf(h,"\tlisten(integer channel, string name, key id, string message)\n\t{\n");
	fprintf(h,"\n\t}\n");

	/* --------------- */
	/* touch :  event */
	/* --------------- */
	fprintf(h,"\ttouch(integer count)\n\t{\n");
	fprintf(h,"\n\t}\n");

	/* --------------- */
	/* sensor :  event */
	/* --------------- */
	fprintf(h,"\tsensor( integer detected )\n\t{\n");
	fprintf(h,"\n\t}\n");

	/* --------------- */
	/* http_request :  event */
	/* --------------- */
	fprintf(h,"\thttp_response(key request_id, integer status, list metadata, string body)\n\t{\n");
	fprintf(h,"\n\t}\n");

	/* --------------- */
	/* dataserver :  event */
	/* --------------- */
	fprintf(h,"\tdataserver(key queryid, string data )\n\t{\n");
	fprintf(h,"\n\t}\n");

	/* --------------- */
	/* changed :  event */
	/* --------------- */
	fprintf(h,"\tchanged(integer change)\n\t{\n");
        fprintf(h,"\t\tif (change & CHANGED_OWNER)\n");
	fprintf(h,"\n\t\t{\n");
	fprintf(h,"\t\t\tllResetScript();\n");
	fprintf(h,"\n\t\t}\n");
	fprintf(h,"\n\t}\n");

	fprintf(h,"\n}\n");
	ws_close_lsl_stream( h, fptr );
	return;
}

static	FILE *	ws_start_php_stream( struct form_control *  fptr ) 
{
	FILE * h;
	if (!( h = ws_open_production_stream( fptr->identifier, ".php" )))
		return(h);
	else	{

		return( h );
		}
}

static	void	ws_close_php_stream( FILE * h, struct form_control *  fptr ) 
{
	if ( h ) {
		fclose( h );
		}
	return;
}


static	void	ws_generate_php_client   ( struct form_control *  fptr )
{
	struct	form_item * iptr;
	FILE *	h;
	if (!( h = ws_start_php_stream( fptr )))
		return;
	ws_close_php_stream( h, fptr );
	return;
}

static	void	ws_generate_form( struct form_control * fptr, int options )
{
	if ( options &   1 ) { ws_generate_client_module( fptr ); }
	if ( options &   2 ) { ws_generate_client_extern( fptr ); }
	if ( options &   4 ) { ws_generate_client_class ( fptr ); }
	if ( options &   8 ) { ws_generate_test_client  ( fptr ); }
	if ( options &  16 ) { ws_generate_wsdl_document( fptr ); }
	if ( options &  32 ) { ws_generate_wsi_document ( fptr ); }
	if ( options &  64 ) { ws_generate_server_module( fptr ); }
	if ( options & 128 ) { ws_generate_lsl_client   ( fptr ); }
	if ( options & 256 ) { ws_generate_php_client   ( fptr ); }
	return;
}

/*	-----------------	*/
/*	Export Other Form	*/
/*	-----------------	*/
int	export_ws_form(FILE * handle, struct form_control * fptr)
{
	ws_generate_form( fptr, 0x0FFF );
	return(0);
}

/*	-----------------	*/
/*	Export Other Form	*/
/*	-----------------	*/
int	export_ws_page(FILE * handle, struct form_control * fptr)
{
	return(0);
}



/*	--------------------	*/
/*	InitialiseSing Other 	*/
/*	--------------------	*/
int	initialise_sing_other()
{
	return(0);
}

/*	-----------------	*/
/*	Export Other Form	*/
/*	-----------------	*/
int	export_other_form(FILE * handle, struct form_control * fptr)
{
	export_ws_form( handle, fptr );
	return(0);
}

/*	-----------------	*/
/*	Export Other Form	*/
/*	-----------------	*/
int	export_other_page(FILE * handle, struct form_control * fptr)
{
	return(0);
}


/*	-------------------	*/
/*	Liberate Sing Other 	*/
/*	-------------------	*/
int	liberate_sing_other()
{
	return(0);
}


#endif	/* _singother_c */
	/* ------------ */









