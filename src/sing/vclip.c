#ifdef	UNIX
int	visual_get_clipboard( char * bptr, int blen )
{
	return ( paste_selection( bptr, blen ) );
}

int	visual_put_clipboard( char * bptr, int blen )
{
	return( publish_selection( bptr, blen ) );
}
#endif

