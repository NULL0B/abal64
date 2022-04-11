#ifndef	_HTTPGET_C
#define	_HTTPGET_C

PRIVATE	INT 	http_remove_white( handle )
	INT	handle;
{
	INT	c;
	while ((c = tcp_readb( handle )) != 0 )
		if ((c != ' ') && (c != '\r') && (c != '\t'))
			break;
	return(c);
}

PRIVATE	INT 	http_not_white( handle )
	INT	handle;
{
	INT 	c;
	while ((c = tcp_readb( handle )) == '\r' );
	if (( c == ' ' ) || ( c == '\t' ))
		return(0);
	else	return(c);
}

PRIVATE	BPTR	http_get_token( handle )
	INT	handle;
{
	BPTR	tptr=(BPTR) 0;
	INT	i=0;
	INT	c;

	if ((c = http_remove_white( handle )) != 0) {
		do	{
			if (( c == '\n' )
			||  ( i >= _IB_SIZE ))
				break;
			else 	*(InputBuffer + (i++)) = c;
			}
		while ((c = http_not_white( handle )) != 0);
		}

	if ( i > 0 ) {
		*(InputBuffer + i) = 0;
		tptr = allocate_for_string( InputBuffer );
		}

	return( tptr );
}

PUBLIC 	BPTR	http_get_line( handle )
	INT	handle;
{
	BPTR	tptr=(BPTR) 0;
	INT	i=0;
	INT	c;

	while (1) {
		switch ((c = tcp_readb( handle ))) {
			case	0    :
			case	'\n' : break;
			case	'\r' : continue;
			case	' '  : if ( i == 0 ) continue;
			default	     :
				if  ( i >= _IB_SIZE )
					break;
				else 	{
					*(InputBuffer + (i++)) = c;
					continue;
					}
			}
		break;
		}

	if ( i > 0 ) {
		*(InputBuffer + i) = 0;
		tptr = allocate_for_string( InputBuffer );
		}

	return( tptr );
}

PUBLIC  HTTPVARPTR	http_get_variables( handle )
	INT		handle;
{
	HTTPVARPTR	vptr=(HTTPVARPTR) 0;
	HTTPVARPTR	last=(HTTPVARPTR) 0;
	HTTPVARPTR	root=(HTTPVARPTR) 0;

	while (1) {
		if ((vptr = allocate_http_variable()) == (HTTPVARPTR) 0) 
			break;
		if ( last == (HTTPVARPTR) 0 )
			root = vptr;
		else	last->next = vptr;
		last = vptr;
		if (((vptr->name = http_get_token( handle )) == (BPTR) 0)
		||  ((vptr->value = http_get_line( handle )) == (BPTR) 0))
			break;
		}
	return( root );
}


PUBLIC	HTTPMSGPTR	http_get_message( cptr )
	CONNECTIONPTR	cptr;
{	
	HTTPMSGPTR	mptr=(HTTPMSGPTR) 0;

	/* ------------------------------------------------------ */
	/* Allocate Message Structure, Receive Command and Object */
	/* ------------------------------------------------------ */
	if (((mptr = allocate_http_message()) != (HTTPMSGPTR) 0)
	&&  ((mptr->command = http_get_token( cptr->newsocket )) != (BPTR) 0)
	&&  ((mptr->object  = http_get_token( cptr->newsocket )) != (BPTR) 0)) { 

		/* --------------------------- */
		/* Attempt to Get HTTP Version */
		/* --------------------------- */
		if ((mptr->version = http_get_token( cptr->newsocket )) != (BPTR) 0)

			/* ------------------------------------- */
			/* Get HTTP Sub-Protocol Field Variables */
			/* ------------------------------------- */
			mptr->variables = http_get_variables( cptr->newsocket );

		}

	else	/* Allocation Error or Failure to Receive Obligatory Fields */
		/* -------------------------------------------------------- */
		mptr = liberate_http_message( mptr );

	return( mptr );
}

	/* ---------- */
#endif	/* _HTTPGET_C */
	/* ---------- */


