#ifndef _inxsql_view_c
#define _inxsql_view_c

/*      ------------------------------------------------        */
/*                                                              */
/*      INXSQL : Database Client Library for ABAL and D3        */
/*                                                              */
/*      ------------------------------------------------        */
/*                                                              */
/*           Copyright (c) 2014-2021 Amenesik SARL              */
/*                                                              */
/*          Iain James Marshall  <ijm@amenesik.com>             */
/*                                                              */
/*      ------------------------------------------------        */
/*                                                              */
/*      This file manages SQL VIEWS for the MC/BD POSIT		*/
/*      instructions of ABAL.                                   */
/*                                                              */
/*      ------------------------------------------------        */

/*	-------------------	*/
/*	inxsql_is_view_name	*/
/*	-------------------	*/
public	int	inxsql_is_view_name( char * nptr )
{
	char	buffer[64];
	sprintf(buffer,"_%s_",_INXS_POSIT_VIEW);
	if (!( nptr = strstr( nptr, buffer ) ))
		return(0);
	else	return(1);
}

/*	--------------------	*/
/*	inxsql_liberate_view	*/
/*	--------------------	*/
public	struct xs_view * inxsql_liberate_view( struct xs_view * vptr )
{
	if ( vptr )
	{
		if ( vptr->name )
			vptr->name = liberate( vptr->name );

		if ( vptr->query )
			vptr->query = liberate( vptr->query );

		vptr = liberate( vptr );
	}
	return( (struct xs_view *) 0);
}

/*	--------------------	*/
/*	inxsql_allocate_view	*/
/*	--------------------	*/
public	struct xs_view * inxsql_allocate_view( char * nptr )
{
	struct	xs_view * vptr=(struct xs_view *) 0;
	int	i=0;
	int	pid=0;
	if (!( vptr = allocate( sizeof( struct xs_view ) ) ))
		return( vptr );
	else if (!( vptr->name = inxsql_allocate_string( nptr ) ))
		return( inxsql_liberate_view( vptr ));
	else	
	{
		// create a new and unique view suffix
		for ( i=0,pid=getpid(); pid != 0; pid /= 24, i++ )
			vptr->id[i] = ('a'+(pid%25));
		vptr->id[i++] = '_';
		for ( pid=inxsql_view_count(); pid != 0; pid /= 24, i++ )
			vptr->id[i] = ('a'+(pid%25));
		vptr->id[i] = 0;
		return( vptr );
	}
}

/*	------------------	*/
/*	inxsql_locate_view	*/
/*	------------------	*/
public  struct xs_view * inxsql_locate_view( struct xs_file * fptr, char * nptr )
{
	struct	xs_view * vptr=(struct xs_view *) 0;
	for (	vptr = fptr->firstview;
		vptr != (struct xs_view *) 0;
		vptr = vptr->next )
	{
		if (!( vptr->name ))
			continue;
		else if (!( inxsql_view_name_compare( vptr->name, nptr ) ))
			break;
	}
	return( vptr );
}

/*	-------------------	*/
/*	inxsql_resolve_view	*/
/*	-------------------	*/
public  struct xs_view * inxsql_resolve_view( struct xs_file * fptr, char * nptr )
{
	struct	xs_view * vptr=(struct xs_view *) 0;
	if (( vptr = inxsql_locate_view( fptr, nptr )) != (struct xs_view *) 0)
		return( vptr );
	else if (!( vptr = inxsql_allocate_view( nptr ) ))
		return( vptr );
	else if (!( vptr->previous = fptr->lastview ))
		fptr->firstview = vptr;
	else	vptr->previous->next = vptr;
	return( (fptr->lastview = vptr ) );
}

/*      ----------------        */
/*      inxsql_drop_file_view        */
/*      ----------------        */
public  int     inxsql_drop_file_view(struct xs_file * fptr )
{
        char *  query=(char *) 0;
        int     status=_SUCCESS;
        struct  xs_connection * xptr;
	struct	xs_view * vptr;
        if (!( vptr = fptr->view ))
                return( _SUCCESS );
        else if (!( vptr->name ))
                return( _SUCCESS );
        else if (!( xptr = fptr->connection ))
                return(_ERROR_CONNECTION);
        else if (!( query = allocate( _STD_QUERY_LENGTH + strlen(fptr->name) + strlen(vptr->name) ) ))
                return(_ERROR_MEMORY);
        else
        {
		// release the selected index
		fptr->selection = inxsql_liberate_index( fptr->selection );

		// release the order by controller
		fptr->orderby   = inxsql_liberate_index( fptr->orderby   );

		// drop the view or table 
		switch ( inxsql_boolean( "INXSQLVIEW", 0 ) )
		{
		case	0	:
                	sprintf(query,"DROP TABLE IF EXISTS %s_%s_%s ",inxsql_table_name(fptr),vptr->name,vptr->id);
			break;
		case	1	:
                	sprintf(query,"DROP VIEW IF EXISTS %s_%s_%s ",inxsql_table_name(fptr),vptr->name,vptr->id);
			break;
		}

                fptr->view = (struct xs_view *) 0;
                if (!( status = inxsql_query( xptr, query, strlen(query) ) ))
                {
                        liberate(query);
                        return(_SUCCESS);
                }
                else
                {
                        liberate(query);
                        return( status );
                }
        }
}

/*	------------------------	*/
/*	 inxsql_locate_base_view	*/
/*	------------------------	*/
public  struct xs_view * inxsql_locate_base_view( struct xs_base * bptr, char * nptr )
{
	struct	xs_view * vptr=(struct xs_view *) 0;
	for (	vptr = bptr->firstview;
		vptr != (struct xs_view *) 0;
		vptr = vptr->next )
	{
		if (!( vptr->name ))
			continue;
		else if (!( inxsql_view_name_compare( vptr->name, nptr ) ))
			break;
	}
	return( vptr );
}

/*	------------------------	*/
/*	inxsql_resolve_base_view	*/
/*	------------------------	*/
public  struct xs_view * inxsql_resolve_base_view( struct xs_base * bptr, char * nptr )
{
	struct	xs_view * vptr=(struct xs_view *) 0;
	if (( vptr = inxsql_locate_base_view( bptr, nptr )) != (struct xs_view *) 0)
		return( vptr );
	else if (!( vptr = inxsql_allocate_view( nptr ) ))
		return( vptr );
	else if (!( vptr->previous = bptr->lastview ))
		bptr->firstview = vptr;
	else	vptr->previous->next = vptr;
	return( (bptr->lastview = vptr ) );
}

/*      ---------------------        */
/*      inxsql_drop_base_view        */
/*      ---------------------        */
public  int     inxsql_drop_base_view(struct xs_base * bptr )
{
        char *  query=(char *) 0;
        int     status=_SUCCESS;
        struct  xs_connection * xptr;
	struct	xs_view * vptr;
        if (!( vptr = bptr->view ))
                return( _SUCCESS );
        else if (!( vptr->name ))
                return( _SUCCESS );
        else if (!( xptr = bptr->connection ))
                return(_ERROR_CONNECTION);
        else if (!( query = allocate( _STD_QUERY_LENGTH + strlen(bptr->name) + strlen(vptr->name) ) ))
                return(_ERROR_MEMORY);
        else
        {
		switch ( inxsql_boolean( "INXSQLVIEW", 0 ) )
		{
		case	0	:
                	sprintf(query,"DROP TABLE IF EXISTS %s_%s_%s ",bptr->name,vptr->name,vptr->id);
			break;
		case	1:	
                	sprintf(query,"DROP VIEW IF EXISTS %s_%s_%s ",bptr->name,vptr->name,vptr->id);
			break;
		}
                bptr->view = (struct xs_view *) 0;
                if (!( status = inxsql_query( xptr, query, strlen(query) ) ))
                {
                        liberate(query);
                        return(_SUCCESS);
                }
                else
                {
                        liberate(query);
                        return( status );
                }
        }
}


#endif	/* _inxsql_view_c */

