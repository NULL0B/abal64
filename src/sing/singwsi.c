#ifndef	_singwsi_c
#define	_singwsi_c

public	void	close_server_description()
{
	int	i;
	if ( WSI.lock )
		return;
	if ( WSI.handle ) {
		fprintf(WSI.handle,"</wasa>\n\n");
		for (i=0; i < 256; i++ )
			fprintf(WSI.handle,"\n");
		close_production_target(WSI.handle,WSI.name);
		WSI.handle = (FILE *) 0;
		}
	if ( WSI.name ) {
		liberate( WSI.name );
		WSI.name = (char *) 0;
		}
	if ( WSI.root ) {
		liberate( WSI.root );
		WSI.root = (char *) 0;
		}
	if ( WSI.style ) {
		liberate( WSI.style );
		WSI.style = (char *) 0;
		}
	return;
}

public	void	server_interface_record(char * nptr, int type, int method )
{
	char	*	item=(char*)0;
	char	*	agent=(char*)0;
	if (!( WSI.handle ))
		return;
	if (!( item = allocate_string( nptr ) ))
		return;
	else if (!( item = normalise_url( item ) ))
		return;

	switch ( type ) {
		case	_WSI_ROOT	:	
		case	_WSI_PAGE	:	
			if (!( item = enforce_extension(item,".htm") ))
				return;
			else if (!( agent = allocate_string( nptr ) ))
				break;
			else if (!( agent = enforce_extension(agent, ".at") ))
				break;
			else	{
				if ( method ) {
					fprintf(WSI.handle,
						"<agent url=%c%s%c target=%c%s%c method=%c%s%c />\n",
						__QUOTE,item,__QUOTE,
						__QUOTE,agent,__QUOTE,
						__QUOTE,"POST",__QUOTE
						);	
					}
				else	{
					fprintf(WSI.handle,
						"<agent url=%c%s%c target=%c%s%c />\n",
						__QUOTE,item,__QUOTE,
						__QUOTE,agent,__QUOTE
						);	
					}

				}
			break;

		case	_WSI_SERVICE	:
			if (!( item = enforce_extension(item,".xml") ))
				return;
			else if (!( agent = allocate_string( nptr ) ))
				break;
			else if (!( agent = enforce_extension(agent, ".at") ))
				break;
			else	{
				fprintf(WSI.handle,
					"<webservice url=%c%s%c target=%c%s%c method=%c%s%c />\n",
					__QUOTE,item,__QUOTE,
					__QUOTE,agent,__QUOTE,
					__QUOTE,method,__QUOTE
					);	
				}
			break;

		case	_WSI_SCRIPT	:	
			if (!( item = enforce_extension(item,".js")))
				return;
			else	{
				fprintf(WSI.handle,
					"<script url=%c%s%c target=%c%s%c />\n",
					__QUOTE,item,__QUOTE,
					__QUOTE,item,__QUOTE
					);	
				}
			break;
		case	_WSI_STYLE	:	
			if (!( item = enforce_extension(item,".css")))
				return;
			else	{
				fprintf(WSI.handle,
					"<style url=%c%s%c target=%c%s%c />\n",
					__QUOTE,item,__QUOTE,
					__QUOTE,item,__QUOTE
					);	
				}
			break;
		case	_WSI_IMAGE	:	
			fprintf(WSI.handle,
				"<image url=%c%s%c target=%c%s%c />\n",
				__QUOTE,item,__QUOTE,
				__QUOTE,item,__QUOTE
				);	
		}
	if ( item ) {
		liberate( item );
		}
	return;
}


public	void	server_webservice_record(char * nptr, char * agent)
{
	char	*	item=(char*)0;
	if (!( WSI.handle ))
		return;
	if (!( item = allocate_string( nptr ) ))
		return;
	else if (!( item = normalise_url( item ) ))
		return;

	else if (!( agent = allocate_string(agent) ))
		return;
	else if (!( agent = enforce_extension(agent, ".at") ))
		return;
	else if ( *item == '/' ) {
		fprintf(WSI.handle,
			"<webservice url=%c%s%c target=%c%s%c />\n",
			__QUOTE,item,__QUOTE,
			__QUOTE,agent,__QUOTE 
			);	
		}
	else 	{
		fprintf(WSI.handle,
			"<webservice url=%c/%s%c target=%c%s%c />\n",
			__QUOTE,item,__QUOTE,
			__QUOTE,agent,__QUOTE 
			);	
		}
	if ( item ) {
		liberate( item );
		}
	return;
}


public	void	server_webservice_description(char * nptr, char * wsdl)
{
	char	*	item=(char*)0;
	if (!( WSI.handle ))
		return;
	if (!( item = allocate_string( nptr ) ))
		return;
	else if (!( item = normalise_url( item ) ))
		return;
	else if (!( wsdl = allocate_string(wsdl ) ))
		return;
	else if (!( wsdl = enforce_extension(wsdl, WSDL_EXTENSION ) ))
		return;
	else if ( *item == '/' ) {
		fprintf(WSI.handle,
			"<script url=%c%s%c target=%c%s%c />\n",
			__QUOTE,item,__QUOTE,
			__QUOTE,wsdl,__QUOTE 
			);	
		}
	else 	{
		fprintf(WSI.handle,
			"<script url=%c/%s%c target=%c%s%c />\n",
			__QUOTE,item,__QUOTE,
			__QUOTE,wsdl,__QUOTE 
			);	
		}
	if ( item ) {
		liberate( item );
		}
	return;
}


public	int	open_server_description(struct form_control * fptr,int isagent)
{
	char *	wurl=(char *) 0;

	if ( WSI.lock )
		return;
	close_server_description();
	if ((!( fptr )) || (!( fptr->prodname )))
		return(0);

	else if (!( WSI.name = allocate_string( fptr->prodname )))
		return(0);
	else if (!( WSI.name = enforce_extension(WSI.name,".wsi")))
		return(0);
	else if (!( WSI.name = use_product_directory( WSI.name )))
		return(0);

	else if (!( WSI.root = allocate_string( fptr->prodname )))
		return(0);
	else if (!( WSI.root = enforce_extension(WSI.root,".htm")))
		return(0);
	else if (!( WSI.root = use_product_directory( WSI.root )))
		return(0);

	else if (!( wurl = allocate_string( fptr->prodname )))
		return(0);
	else if (!( wurl = enforce_extension(wurl,".htm")))
		return(0);

	if ( method_is_valid(fptr->stylesheet) ) {
		if (!( WSI.style = allocate_string( fptr->stylesheet )))
			return(0);
		else if (!( WSI.style = enforce_extension(WSI.style,".css")))
			return(0);
		}
	if (!( WSI.handle = open_production_target(WSI.name, 0) )) {
		return(0);
		}

	fprintf(WSI.handle,"<?xml  version=%c1.0%c encoding=%cUTF-8%c?>\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(WSI.handle,"<wasa name=%c%s%c stamp=%c%lu%c >\n",__QUOTE,fptr->identifier,__QUOTE,__QUOTE,time(0L),__QUOTE);
	if ( isagent ) {
		server_interface_record( wurl, _WSI_ROOT, get_agent_nature() );
		}
	if ( WSI.style )
		server_interface_record( WSI.style, _WSI_STYLE, 0 );

	if ( wurl )
		liberate( wurl );
	return(1);

}

#endif	/* _singwsi_c */
	/* ---------- */











