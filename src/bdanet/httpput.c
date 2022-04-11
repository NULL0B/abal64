#ifndef	_HTTPPUT_C
#define	_HTTPPUT_C

PUBLIC 	INT		http_putb( connection, c )
	CONNECTIONPTR	connection;
	BYTE		c;
{
	if ( verbose & 32 )
		printf("%c",c);
#if defined(UNIX) || defined(WIN32)
#ifdef	SYSTEM_SSL
	if ( connection->context ) {
		if ( sslsocketwriter(( connection->newobject ? connection->newobject : connection->object),(BPTR) & c, 1 ) != 1 )
			return(0);
		else	return(1);
		}
#endif
#endif
	if ( SocketWrite(connection->newsocket,(BPTR) & c, 1 ) != 1 )
		return(0);
	else	return(1);
}

PUBLIC 	INT		http_put( connection, buffer, buflen )
	CONNECTIONPTR	connection;
	BPTR		buffer;
	INT		buflen;
{
	INT	i;
	if ( verbose  & 32 )
		for ( i=0; i < buflen; i++ )
			printf("%c",*(buffer+i));
#if defined(UNIX) || defined(WIN32)
#ifdef	SYSTEM_SSL
	if ( connection->context ) {
		if ( sslsocketwriter(( connection->newobject ? connection->newobject : connection->object),(BPTR) buffer, buflen ) != buflen )
			return(0);
		else	return(1);
		}
#endif
#endif
	if ( SocketWrite(connection->newsocket,buffer,buflen) != buflen )
		return(0);
	else	return(1);
}

PRIVATE	INT	ClientUsage=0;
PRIVATE	BYTE	ClientBuffer[4000];

PRIVATE	VOID	outflush( connection )
	CONNECTIONPTR	connection;
{
	if ( ClientUsage ) {
		http_put( connection, ClientBuffer, ClientUsage );
		ClientUsage = 0;
		}
	return;
}
PRIVATE	VOID	outwrite( connection , bptr )
	CONNECTIONPTR	connection;
	BPTR		bptr;
{
	while ( *bptr ) {

		if ( ClientUsage < 4000 )
			ClientBuffer[ ClientUsage++ ] = *(bptr++);
		else	outflush( connection );

		}
	return;
}


PUBLIC	INT		http_put_message( connection, message )
	CONNECTIONPTR	connection;
	HTTPMSGPTR	message;
{	
	URLPTR		uptr;
	INT		i;
	INT		status=0;
	HTTPVARPTR	variable=(HTTPVARPTR) 0;
	BPTR		optr;
	if (( message != (HTTPMSGPTR) 0    )
	&&  ( message->command != (BPTR) 0 )
	&&  ((optr = message->object)  != (BPTR) 0 )) {

		ClientUsage = 0;
		if ( *optr == ':' )
			optr++;

		while ( *optr == ' ' )
			optr++;

		if ( message->version == (BPTR) 0 ) {
			outwrite(connection,message->command);
			outwrite(connection," ");
			if ( *optr != 0 )
				outwrite(connection,optr);
			else	outwrite(connection,"/");
			outwrite(connection,"\r\n\r\n");
			}
		else	{
			outwrite(connection,message->command);
			outwrite(connection," ");
			if ( *optr != 0 )
				outwrite(connection,optr);
			else	outwrite(connection,"/");
			outwrite(connection," ");
			outwrite(connection,message->version);
			outwrite(connection,"\r\n");
			if ((variable = message->variables) != (HTTPVARPTR) 0) {
				do	{
					outwrite(connection,variable->name);
					outwrite(connection," ");
					outwrite(connection,variable->value);
					if (( BoundaryMark != (BPTR) 0 )
					&&  ( compare_tokens( variable->name,  __CONTENT_TYPE   ))
					&&  ( compare_tokens( variable->value, __MULTIPART_FORM ))) {
						outwrite(connection,"; boundary=");
						outwrite(connection,BoundaryMark);
						}
					outwrite(connection,"\r\n");

					}
				while ((variable = variable->next) != (HTTPVARPTR) 0);
				}
			/* flush additional headers */
			/* ------------------------ */
			if (( uptr = connection->remote) != (URLPTR) 0 ) {
				for ( i=0; i < uptr->headers; i++ ) { 
					outwrite(connection,uptr->header[i]);
					outwrite(connection,"\r\n");
					}
				}
			outwrite(connection,"\r\n");
			}
		outflush( connection );
		}
	return(status );
}

#endif	/* HTTPPUT_C */
	/* --------- */

