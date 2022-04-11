#ifndef	_SOAPAPP_H
#define	_SOAPAPP_H

struct	soap_application
{
	struct	xml_tag *	document;
	struct	xml_tag *	current;
};

struct xml_tag * xml_parse_file( char * filename, void * vptr );
int		generate_response_message( char * filename, char * methodname, char * host, char * object, char * result );
int		generate_fault_message( char * filename, char * methodname, char * host, char * object, char * failure );
int		generate_request_message( char * filename, int procid , char * host, char * object, char * , int );
char *		locate_method_name( struct xml_tag * document );
char *		extract_method_name( struct xml_tag * document );
struct xml_tag * locate_method_node( struct xml_tag * document );
struct xml_tag * drop_xml_document( struct xml_tag * dptr );

#endif	/* _SOAPAPP_H */
