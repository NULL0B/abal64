HttpPost( char * packet, char * type ) 	// multipart/form-data
					// 
{
	HttpPutLine( socket, packet, html_string::length( packet ) );
	HttpPutLine( socket, packet, 0 );
	HttpPutLine( socket, packet, 0 );
