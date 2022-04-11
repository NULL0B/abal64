#ifndef	_singlist_c
#define	_singlist_c

private	int	add_filenode(struct standard_filelist * lptr, char * sptr )
{
	int			    c;
	char			  * wptr;
	struct	standard_filenode * nptr;
	
	if (!( sptr ))	return(0);
	if (!( lptr ))	return(118);

	while ( *sptr ) {

		/* step over preceeding white space and solitary separators */
		/* -------------------------------------------------------- */
		while (( *sptr == ' ' ) || ( *sptr == ',' )  
		||     ( *sptr == ';' ) || ( *sptr == ':' )
		||     ( *sptr == '\t') || ( *sptr == '\r') || ( *sptr == '\n'))
			sptr++;

		wptr = sptr;

		/* step forward until : white space or  solitary separators */
		/* -------------------------------------------------------- */
		while (( *wptr != ',' ) && ( *wptr != ';' ) && ( *wptr != 0   )
		&&     ( *wptr != '\t') && ( *wptr != '\r') && ( *wptr != '\n'))
			wptr++;

		c = *wptr; *wptr=0;

		if (!( nptr = allocate( sizeof( struct standard_filenode ) ) )) {
			*wptr = c;
			return(27);
			}
		else if (!( nptr->filename = allocate_string( sptr ) )) {
			*wptr = c;
			liberate( nptr );
			return(27);
			}
		else	{
			nptr->previous = nptr->next = (struct standard_filenode*) 0;
			if (!( nptr->previous = lptr->last ))
				lptr->first = nptr;
			else	lptr->last->next = nptr;
			lptr->last = nptr;
			*wptr = c;
			sptr = wptr;
			}
		}
	return(0);
}

private	char * next_filenode(struct standard_filelist * lptr )
{
	char			  * pptr;
	char			  * sptr;
	struct	standard_filenode * nptr;
	if (!( lptr ))	
		return((char *) 0);
	else if (!( nptr = lptr->first ))
		return((char *) 0);
	else	{
		if (!(lptr->first = nptr->next))
			lptr->last = lptr->first;
		else	nptr->next->previous = (struct standard_filenode*) 0;
		sptr = nptr->filename;
		liberate( nptr );
		if (!( pptr = get_component_path() ))
			return( sptr );
		else if ( is_absolute_path( sptr ) )
			return( sptr );
	 	else	return(resolve_componentpath(sptr,pptr));
		}	
}


#endif	/* _singlist_c */
	/* ----------- */

