#ifndef	_exmasql_c
#define	_exmasql_c

/*
 *	S Q L _ O P E N ( filename, options )
 *	-------------------------------------
 *
 */

EX_FILE_HANDLE	sql_open (  filename, options )
BPTR	filename;
EXAWORD	options;
{
	return((EX_FILE_HANDLE)0);
}


/*
 *	S Q L _ C L O S E ( handle )
 *	----------------------------
 *
 */

EXAWORD	sql_close( handle )
EX_FILE_HANDLE	handle;
{
	return( 56 );
}

/*
 *	S Q L _ S E L E C T ( handle, buffer, length )
 *	----------------------------------------------
 *
 */

EXAWORD	sql_select   (handle,buffer,buflen ) 
EX_FILE_HANDLE handle;
BPTR	buffer;
EXAWORD	buflen;
{
	return(56);
}

/*
 *	S Q L _ P R E P A R E ( handle, buffer, length )
 *	------------------------------------------------
 *
 */

EXAWORD	sql_prepare  (handle,buffer,buflen ) 
EX_FILE_HANDLE handle;
BPTR	buffer;
EXAWORD	buflen;
{
	return(56);
}

/*
 *	S Q L _ F E T C H ( handle )
 *	----------------------------
 *
 */

EXAWORD	sql_fetch( handle )
EX_FILE_HANDLE handle;
{
	return(56);
}

/*
 *	S Q L _ G E T _ I N T 8 ( handle, buffer )
 *	------------------------------------------
 *
 */

EXAWORD	sql_get_int8( handle, buffer )
EX_FILE_HANDLE handle;
BPTR	buffer;
{
	return(56);
}

/*
 *	S Q L _ G E T _ I N T 1 6 ( handle, buffer )
 *	--------------------------------------------
 *
 */

EXAWORD	sql_get_int16( handle, buffer )
EX_FILE_HANDLE handle;
BPTR	buffer;
{
	return(56);
}

/*
 *	S Q L _ G E T _ I N T 3 2 ( handle, buffer )
 *	--------------------------------------------
 *
 */

EXAWORD	sql_get_int32( handle, buffer )
EX_FILE_HANDLE handle;
BPTR	buffer;
{
	return(56);
}

/*
 *	S Q L _ G E T _ B C D ( handle, buffer, buflen )
 *	------------------------------------------------
 *
 */

EXAWORD	sql_get_bcd( handle, buffer,buflen )
EX_FILE_HANDLE handle;
BPTR	buffer;
EXAWORD	buflen;
{
	return(56);
}

/*
 *	S Q L _ G E T _ S T R I N G ( handle, buffer, buflen )
 *	------------------------------------------------------
 *
 */

EXAWORD	sql_get_string( handle, buffer,buflen )
EX_FILE_HANDLE handle;
BPTR	buffer;
EXAWORD	buflen;
{
	return(56);
}

/*
 *	S Q L _ G E T _ E X E C ( handle, buffer, buflen )
 *	--------------------------------------------------
 *
 */

EXAWORD	sql_exec     (handle,buffer,buflen ) 
EX_FILE_HANDLE handle;
BPTR	buffer;
EXAWORD	buflen;
{
	return(56);
}

/*
 *	S Q L _ G E T _ K E Y _ T Y P E ( handle, buffer, buflen )
 *	----------------------------------------------------------
 *
 */

EXAWORD	sql_key_type (handle,buffer,buflen ) 
EX_FILE_HANDLE handle;
BPTR	buffer;
EXAWORD	buflen;
{
	return(56);
}

/*
 *	S Q L _ G E T _ L I N K _ N A M E ( handle, buffer, buflen )
 *	------------------------------------------------------------
 *
 */

EXAWORD	sql_link_name(handle,buffer,buflen ) 
EX_FILE_HANDLE handle;
BPTR	buffer;
EXAWORD	buflen;
{
	return(56);
}

/*
 *	S Q L _ G E T _ F I L E _ U S E R ( handle, buffer )
 *	----------------------------------------------------
 *
 */

EXAWORD	sql_file_user(handle,buffer,buflen ) 
EX_FILE_HANDLE handle;
BPTR	buffer;
EXAWORD	buflen;
{
	return(56);
}

#endif	/* _exmasql_c */
	/* ---------- */

