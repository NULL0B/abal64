#ifndef	_HTTPMEM_C
#define	_HTTPMEM_C


PUBLIC	VOID		show_http_variables( vptr )
	HTTPVARPTR	vptr;
{
	if (( verbose & 4 )
	&&  (vptr != (HTTPVARPTR) 0)) {
		do	{
			if ( vptr->name != (BPTR) 0 ) {
				printf("\t%s ",vptr->name);
				if ( vptr->value != (BPTR) 0 )
					printf("%s\n",vptr->value);
				else	printf("\n");
				}
			}
		while ((vptr = vptr->next) != (HTTPVARPTR) 0);
		}
	return;
}

PUBLIC 	VOID		show_http_message( message )
	HTTPMSGPTR	message;
{
	HTTPVARPTR	vptr=(HTTPVARPTR) 0;
	if ((verbose & 2)
	&&  ( message != (HTTPMSGPTR) 0)) {
		printf("HTTP Message \n");
		if ( message->command != (BPTR) 0 ) {
			printf("\t%s ",message->command);
			if ( message->object != (BPTR) 0 )
				printf("%s ",message->object);
	
			if ( message->version != (BPTR) 0 ) {
				printf("%s\n",message->version);
				show_http_variables( message->variables );
				}
			else	printf("\n");
			}
		}
	return;
}


PUBLIC	HTTPVARPTR	liberate_http_variable(vptr)
	HTTPVARPTR	vptr;
{
	if ( vptr != (HTTPVARPTR) 0 ) {
		vptr->name = liberate_zone( vptr->name );
		vptr->value = liberate_zone( vptr->value );
		vptr = liberate_zone( vptr );
		}
	return( vptr );
}

PUBLIC	HTTPVARPTR	allocate_http_variable()
{
	HTTPVARPTR	vptr;
	if ((vptr = (HTTPVARPTR) allocate_zone( sizeof( HTTPVAR ) )) != (HTTPVARPTR) 0) {
		vptr->name  = (BPTR) 0;
		vptr->value = (BPTR) 0;
		vptr->next  = (HTTPVARPTR) 0;
		}
	return( vptr );
}

PUBLIC	INT		build_http_variable( message, name, value )
	HTTPMSGPTR	message;
	BPTR		name;
	BPTR		value;
{
	HTTPVARPTR	vptr=(HTTPVARPTR) 0;

	if (( message != (HTTPMSGPTR) 0 )
	&&  ( name    != (BPTR) 0       )
	&&  ( value   != (BPTR) 0       )
	&&  ((vptr = allocate_http_variable()) != (HTTPVARPTR) 0)
	&&  ((vptr->name = allocate_for_string(name)) != (BPTR) 0)
	&&  ((vptr->value = allocate_for_string(value)) != (BPTR) 0)) {
		vptr->next  = message->variables;
		message->variables = vptr;
		}
	else	vptr = liberate_http_variable( vptr );
	return(0);
}


PUBLIC	HTTPMSGPTR	liberate_http_message(mptr)
	HTTPMSGPTR	mptr;
{
	HTTPVARPTR	vptr=(HTTPVARPTR) 0;
	if ( mptr != (HTTPMSGPTR) 0 ) {
		mptr->command = liberate_zone( mptr->command );
		mptr->object  = liberate_zone( mptr->object  );
		mptr->version = liberate_zone( mptr->version );
		/* ----------------------------------------- */
		/* 	     A T T E N T I O N		     */
		/* ----------------------------------------- */
		/* 					     */
		/* Do Not Liberate !!  mptr->parameters   !! */
		/* since it points inside !! mptr->object !! */
		/* 					     */
		/* ----------------------------------------- */
		while ((vptr = mptr->variables) != (HTTPVARPTR) 0) {
			mptr->variables = vptr->next;
			vptr = liberate_http_variable( vptr );
			}
		mptr = liberate_zone( mptr );
		}
	return( mptr );
}

PUBLIC	HTTPMSGPTR	allocate_http_message()
{
	HTTPMSGPTR	mptr;
	if ((mptr = (HTTPMSGPTR) allocate_zone( sizeof( HTTPMSG ) )) != (HTTPMSGPTR) 0) {
		mptr->command 	= (BPTR) 0;
		mptr->object  	= (BPTR) 0;
		mptr->parameters= (BPTR) 0;
		mptr->version 	= (BPTR) 0;
		mptr->variables	= (HTTPVARPTR) 0;
		}
	return( mptr );

}

	/* ---------- */
#endif	/* _HTTPMEM_C */
	/* ---------- */

