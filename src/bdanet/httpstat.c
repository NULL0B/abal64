PRIVATE	INT		http_genstat( cptr, linebuffer )
	CONNECTIONPTR	cptr;
	BPTR		linebuffer;
{
	sprintf(linebuffer,"<LI> Server started at  %lu <BR><P>",HttpStat.StartUpDate);
	http_put( cptr,linebuffer, strlen(linebuffer));
	http_put( cptr, __HTTP_CRLF, 2 );
	sprintf(linebuffer,"<LI> Home Page          %s<BR><P>",HomePage);
	http_put( cptr,linebuffer, strlen(linebuffer));
	http_put( cptr, __HTTP_CRLF, 2 );
	sprintf(linebuffer,"<LI> Home Path          %s<BR><P>",HomePath);
	http_put( cptr,linebuffer, strlen(linebuffer));
	http_put( cptr, __HTTP_CRLF, 2 );
	sprintf(linebuffer,"<LI> Requests received  %lu <BR><P>",HttpStat.ConnectionCount);
	http_put( cptr,linebuffer, strlen(linebuffer));
	http_put( cptr, __HTTP_CRLF, 2 );
	sprintf(linebuffer,"<LI> Successful replies %lu<BR><P>",HttpStat.SuccessCount);
	http_put( cptr,linebuffer, strlen(linebuffer));
	http_put( cptr, __HTTP_CRLF, 2 );
	sprintf(linebuffer,"<LI> Reply Failures     %lu<BR><P>",HttpStat.FailureCount);
	http_put( cptr,linebuffer, strlen(linebuffer));
	http_put( cptr, __HTTP_CRLF, 2 );
	return( 1 );
}

PRIVATE	INT		http_statistics( cptr )
	CONNECTIONPTR	cptr;
{
	INT	llen=0;
	INT	handle;
	INT	status=0;
	BPTR	linebuffer=(BPTR) 0;
	BPTR	workbuffer=(BPTR) 0;

	if ((workbuffer = allocate_zone( MAX_NAME_LENGTH )) == (BPTR) 0)
		http_server_error(cptr,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");

	else if (( handle = FileOpen( __HTTP_STATISTICS, O_RDONLY )) <= 0 )
		http_server_error(cptr,_HTTP_STATUS_IMPLEMENTATION, "Not implemented");

	else	{

		http_success( cptr );

		/* Read until End of File */
		/* ---------------------- */
		while ((llen = FileGetLine( handle, workbuffer, MAX_NAME_LENGTH )) != 0) {

			linebuffer = workbuffer;

			while (( *linebuffer ) && ( *linebuffer == ' ' ))
				linebuffer++;

			/* Avoid Empty Lines */
			/* ----------------- */
			if ( *linebuffer ) {
				http_put( cptr,linebuffer, strlen(linebuffer));
				http_put( cptr, __HTTP_CRLF, 2 );
				if (!( status ))
					if (( *linebuffer == '<' )
					&&  ( *(linebuffer+1) == 'U' )
					&&  ( *(linebuffer+2) == 'L' )
					&&  ( *(linebuffer+3) == '>' ))
						status = http_genstat( cptr, workbuffer );

				}
			}

		/* Close File and Release Line Buffer */
		/* ---------------------------------- */
		FileClose( handle ); 
		}
	workbuffer = liberate_zone( workbuffer );
	return(0);
}

