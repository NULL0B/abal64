#ifndef	_inxsql_record_c
#define	_inxsql_record_c

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

#include	"inxsql.h"

#ifdef	_INXSQL_MYSQL
/*	----------------------------	*/
/*	inxsql_log_statement_failure	*/
/*	----------------------------	*/
private	void	inxsql_log_statement_failure(MYSQL_STMT * sptr)
{
	switch ( inxsql_boolean("INXSQLERROR",0) )
	{
	case	1	:
		fprintf(stdout,"statement failure : %u : %s \n",sptr->last_errno,sptr->last_error);
		break;
	case	2	:
		fprintf(stderr,"statement failure : %u : %s \n",sptr->last_errno,sptr->last_error);
		break;
	}
	return;
}
#endif

/*	-------------------	*/
/*	inxsql_append_query	*/
/*	-------------------	*/
public	int	inxsql_append_query( char * query, int offset, char * sptr )
{
	int	c;
	while ((c = *(sptr++)) != 0)
		query[offset++] = c;

	query[offset] = 0;
	return( offset);
}

/*	----------------------------------	*/
/*	inxsql_append_distinct_field_names	*/
/*	----------------------------------	*/
public 	int	inxsql_append_distinct_field_names( char * query, struct xs_field * cptr, int items, struct xs_index * iptr)
{
	struct	xs_link * lptr;
	// for list of fields
	while ( cptr != (struct xs_field *) 0)
	{
		// append field separator
		if ( items++ ) strcat(query,",");

		// is it a member of the distinct index list
		if ((lptr = inxsql_locate_link( iptr, cptr )) != (struct xs_link *) 0)
			strcat(query,"Distinct ");

		// apend the column name
		strcat(query,cptr->name);
		cptr = cptr->next;
	}
	return( items );
}

/*	-------------------------	*/
/*	inxsql_append_field_names	*/
/*	-------------------------	*/
public 	int	inxsql_append_field_names( char * query, struct xs_field * cptr, int items)
{
	while ( cptr != (struct xs_field *) 0)
	{
		if ( items++ ) strcat(query,",");
		strcat(query,cptr->name);
		cptr = cptr->next;
	}
	return( items );
}

/*	----------------------	*/
/*	inxsql_max_field_value	*/
/*	----------------------	*/
public	int	inxsql_max_field_value( struct  xs_field * cptr, char * query, int offset )
{
	struct	xs_file * fptr;
	if ((fptr = cptr->file) != (struct xs_file *) 0)
	{
		offset = inxsql_append_query(query,offset,"(SELECT MAX(");
		offset = inxsql_append_query(query,offset,cptr->name);
		offset = inxsql_append_query(query,offset,") FROM ");
		offset = inxsql_append_query(query,offset,inxsql_table_name(fptr));
		offset = inxsql_append_query(query,offset,")");
	}
	return( offset );
}

/*	----------------------	*/
/*	inxsql_min_field_value	*/
/*	----------------------	*/
public	int	inxsql_min_field_value( struct  xs_field * cptr, char * query, int offset )
{
	struct	xs_file * fptr;
	if ((fptr = cptr->file) != (struct xs_file *) 0)
	{
		offset = inxsql_append_query(query,offset,"(SELECT MIN(");
		offset = inxsql_append_query(query,offset,cptr->name);
		offset = inxsql_append_query(query,offset,") FROM ");
		offset = inxsql_append_query(query,offset,inxsql_table_name(fptr));
		offset = inxsql_append_query(query,offset,")");
	}
	return( offset );
}

/*	----------------	*/
/*	inxsql_max_value	*/
/*	----------------	*/
private	int	inxsql_max_value(struct  xs_field * cptr, char * dptr)
{
	int	dlen;

	if ((dlen = inxsql_field_size(cptr)) > 0)
	{
		switch ( cptr->type )
		{
		case	_INXS_STRING	:
			memset(dptr,_INXS_MAX_STRING,dlen);
			break;
		default			:
			memset(dptr,_INXS_MAX_BINARY,dlen);
			break;
		}
	}
	return(dlen);
}

/*	----------------	*/
/*	inxsql_min_value	*/
/*	----------------	*/
int	inxsql_min_value(struct  xs_field * cptr, char * dptr)
{
	int	dlen;

	if ((dlen = inxsql_field_size(cptr)) > 0)
	{
		switch ( cptr->type )
		{
		case	_INXS_STRING	:
			memset(dptr,_INXS_MIN_STRING,dlen);
			break;
		default			:
			memset(dptr,_INXS_MIN_BINARY,dlen);
			break;
		}
	}
	return(dlen);
}

#ifdef	_INXSQL_MYSQL
/*	-------------------	*/
/*	inxsql_update_query	*/
/*	-------------------	*/
private	MYSQL_STMT * inxsql_update_query( struct xs_file * fptr, int dlen )
{
	unsigned char *	query=(unsigned char *) 0;
	unsigned long	offset=0L;
	int		status=0;
	int		items=0;
	struct	xs_field * cptr;

	if (!( fptr->update ))
	{
		// allocate the query buffer
		if (!( query = allocate( _STD_QUERY_LENGTH + inxsql_file_qlength(fptr) + dlen + strlen(fptr->name) + fptr->primary.size) ))
			return(fptr->update);
		else
		{
			/* ---------------------------- */
			/* prepare the INSERT statement */
			/* ---------------------------- */
			sprintf(query,"UPDATE %s SET ",inxsql_table_name(fptr));
			offset = strlen(query);
			items = 0;
		
			/* ---------------------------------- */
			/* handle the column data expressions */
			/* ---------------------------------- */
			for (	cptr = fptr->first;
				cptr != (struct xs_field *) 0;
				cptr = cptr->next )
			{
				/* ----------------------- */
				/* avoid the primary index */
				/* ----------------------- */
				if (!( strcmp( cptr->name, fptr->primary.name ) ))
					continue;

				/* ------------------------ */
				/* data needs the separator */
				/* ------------------------ */
				if ( items++ ) query[offset++] = ',';

				/* ------------------------ */
				/* prepare the NAME = VALUE */
				/* ------------------------ */
				offset = inxsql_append_query(query,offset,cptr->name);
				query[offset++] = '=';

				// prepare value wild card
				query[offset++] = '?';
			}

			/* ----------------------------- */
			/* prepare the primary key value */
			/* ----------------------------- */
			offset = inxsql_append_query(query,offset," WHERE ");
			offset = inxsql_append_query(query,offset,fptr->primary.name);
			offset = inxsql_append_query(query,offset,_INXS_EQ);

			// prepare value wild card
			query[offset++] = '?';

			/* ------------------------- */
			/* terminate it for the form */
			/* ------------------------- */
			query[offset] = 0;

		}

		// allocate the statement structure
		if (( fptr->update = mysql_stmt_init(fptr->connection->handle)) != (MYSQL_STMT *) 0)
		{
			// perform the statement preparation
			if ((status = mysql_stmt_prepare(fptr->update,query,offset)) != 0)
			{
				// release statement before failure
				mysql_stmt_close(fptr->update);
				fptr->update = (MYSQL_STMT *) 0;
			}
		}

		// release the query
		query = liberate( query );
	}

	// return the current statement
	return( fptr->update );
}

/*	---------------------	*/
/*	inxsql_record_binding	*/
/*	---------------------	*/
private	unsigned char * inxsql_record_binding( struct xs_file * fptr , char * iptr, char * dptr, int dlen)
{
	unsigned int ilen;
	unsigned int olen;
	unsigned int blen;
	unsigned int offset=0;
	unsigned int length=0;
	struct	xs_field * cptr;

	// collect the index and buffer lengths
	if (!( fptr ))
		return((unsigned char *) 0);
	else if ( fptr->record )
		return( fptr->record );
	else if (!( ilen = inxsql_field_bsize(&fptr->primary) ))
		return((unsigned char *) 0);
	else
	{
		// the data binding may be zero
		blen = inxsql_file_blength(fptr);

		// allocate a return the record buffer
		return (( fptr->record = allocate( ilen + blen ) ));
	}
}

/*	------------------	*/
/*	inxsql_insert_data	*/
/*	------------------	*/
private	MYSQL_BIND * inxsql_insert_data( struct xs_file * fptr, char * iptr, char * dptr, int dlen )
{
	MYSQL_BIND *	bptr;
	unsigned char *	rptr;
	unsigned int	offset=0;
	unsigned int	length=0;
	struct	xs_field * cptr;

	// check binding and record
	if (!( bptr = fptr->inserting ))
		return( bptr );
	else if (!( rptr = fptr->record ))
		return((MYSQL_BIND *) 0);
	else
	{

		// ----------------------------------------
		// INSERT (INDEX,FIELD,FIELD) VALUES(?,?,?)
		// ----------------------------------------
#ifdef	DEBUG_PREPARED_STATEMENT
		fprintf(stderr,"INSERT BINDING for %s \n",fptr->name);
		fprintf(stderr,"-----------------------------------------\n");
#endif
		// store primary index data to record and update binding
		length = inxsql_set_field( &fptr->primary, bptr, iptr, fptr->record );
		offset = inxsql_field_bsize( &fptr->primary );
		bptr++;

		// populate the record binding fields
		for (	cptr = fptr->first;
			cptr != (struct xs_field *) 0;
			cptr = cptr->next )
		{
			// set field will consume size bytes and store bsize bytes
			length = inxsql_set_field( cptr, bptr, dptr, fptr->record+offset);
			dptr   += length;
			dlen   -= length;
			offset += inxsql_field_bsize(cptr);
			bptr++;
		}

#ifdef	DEBUG_PREPARED_STATEMENT
		fprintf(stderr,"-----------------------------------------\n");
#endif
		return( fptr->inserting );
	}
}

/*	------------------	*/
/*	inxsql_update_data	*/
/*	------------------	*/
private	MYSQL_BIND * inxsql_update_data( struct xs_file * fptr, char * iptr, char * dptr, int dlen )
{
	MYSQL_BIND *	bptr;
	unsigned char *	rptr;
	unsigned int	offset=0;
	unsigned int	length=0;
	struct	xs_field * cptr;

	// check binding and record
	if (!( bptr = fptr->updating ))
		return( bptr );
	else if (!( rptr = fptr->record ))
		return((MYSQL_BIND *) 0);
	else
	{
#ifdef	DEBUG_PREPARED_STATEMENT
		fprintf(stderr,"UPDATE BINDING for %s \n",fptr->name);
		fprintf(stderr,"-----------------------------------------\n");
#endif
		// --------------------------------------
		// UPDATE FIELD=?,FIELD=? WHERE INDEX = ?
		// --------------------------------------
		offset = inxsql_field_bsize( &fptr->primary );
		// populate the record binding fields
		for (	cptr = fptr->first;
			cptr != (struct xs_field *) 0;
			cptr = cptr->next )
		{
			// set field will consume size bytes and store bsize bytes
			length = inxsql_set_field( cptr, bptr, dptr, fptr->record+offset);
			dptr   += length;
			dlen   -= length;
			offset += inxsql_field_bsize(cptr);
			bptr++;
		}

		// store primary index data to record and update binding
		length = inxsql_set_field( &fptr->primary, bptr, iptr, fptr->record );
#ifdef	DEBUG_PREPARED_STATEMENT
		fprintf(stderr,"-----------------------------------------\n");
#endif
		return( fptr->updating );
	}
}

/*	---------------------	*/
/*	inxsql_update_binding	*/
/*	---------------------	*/
private	MYSQL_BIND * inxsql_update_binding( struct xs_file * fptr , char * iptr, char * dptr, int dlen)
{
	unsigned char * rptr;
	unsigned int fields=0;
	MYSQL_BIND * bptr;

	// prepare the record buffer for this binding
	if (!( rptr = inxsql_record_binding( fptr, iptr, dptr, dlen )))
		return((MYSQL_BIND *) 0);

	// build the update statement binding
	else if (!( fptr->updating ))
	{
		// count the fields
		fields = inxsql_field_count( fptr ) + 1;

		// allocate the bindings buffer
		if ((fptr->updating = (MYSQL_BIND *) allocate( sizeof( MYSQL_BIND ) * fields )) != (MYSQL_BIND *) 0)
		{

			// Record Fields come first
			if ((bptr = inxsql_bind_fields( fptr, fptr->updating, (rptr+inxsql_field_bsize(&fptr->primary)) )) != (MYSQL_BIND *) 0)
			{
				// Primary is Last for Where
				inxsql_bind_field( &fptr->primary, bptr, rptr);
			}
		}
	}
	return( inxsql_update_data( fptr, iptr, dptr, dlen ) );
}

/*	-------------------	*/
/*	inxsql_insert_query	*/
/*	-------------------	*/
private	MYSQL_STMT * inxsql_insert_query( struct xs_file * fptr, int dlen )
{
	unsigned char *	query=(unsigned char *) 0;
	unsigned long	offset=0L;
	int		status=0;
	int		items=0;
	struct	xs_field * cptr;

	if (!( fptr->insert ))
	{
		// allocate the query buffer
		if (!( query = allocate( _STD_QUERY_LENGTH + inxsql_file_qlength(fptr) + dlen + strlen(fptr->name) + fptr->primary.size) ))
			return(fptr->insert);
		else
		{
			/* ---------------------------- */
			/* prepare the INSERT statement */
			/* ---------------------------- */
			sprintf(query,"INSERT INTO %s",inxsql_table_name(fptr));
			strcat(query,"(");
			strcat(query,fptr->primary.name);
			inxsql_append_field_names(query,fptr->first,1);
			strcat(query,")");
			strcat(query," VALUES(");
			offset = strlen( query );

			query[offset++] = '?';
			
			/* ---------------------------------- */
			/* handle the column data expressions */
			/* ---------------------------------- */
			for (	cptr = fptr->first;
				cptr != (struct xs_field *) 0;
				cptr = cptr->next )
			{
				/* ----------------------- */
				/* avoid the primary index */
				/* ----------------------- */
				if (!( strcmp( cptr->name, fptr->primary.name ) ))
					continue;

				// field separator
				query[offset++] = ',';

				// prepare value wild card
				query[offset++] = '?';
			}

			/* ------------------------------ */
			/* terminate the INSERT statement */
			/* ------------------------------ */
			query[offset++] = ')';
			query[offset++] = 0;
		}

		// allocate the statement structure
		if (( fptr->insert = mysql_stmt_init(fptr->connection->handle)) != (MYSQL_STMT *) 0)
		{
			// perform the statement preparation
			if ((status = mysql_stmt_prepare(fptr->insert,query,offset)) != 0)
			{
				// release statement before failure
				mysql_stmt_close(fptr->insert);
				fptr->insert = (MYSQL_STMT *) 0;
			}
		}

		// release the query
		query = liberate( query );
	}

	// return the current statement
	return( fptr->insert );
}

/*	---------------------	*/
/*	inxsql_insert_binding	*/
/*	---------------------	*/
private	MYSQL_BIND * inxsql_insert_binding( struct xs_file * fptr , char * iptr, char * dptr, int dlen)
{
	unsigned char * rptr;
	unsigned int fields=0;

	// prepare the record buffer for this binding
	if (!( rptr = inxsql_record_binding( fptr, iptr, dptr, dlen )))
		return((MYSQL_BIND *) 0);

	// build the insert binding
	if (!( fptr->inserting ))
	{
		// count the fields
		fields = inxsql_field_count( fptr ) + 1;

		// allocate the bindings buffer
		if ((fptr->inserting = (MYSQL_BIND *) allocate( sizeof( MYSQL_BIND ) * fields )) != (MYSQL_BIND *) 0)
		{
			// Primary is First
			inxsql_bind_field( &fptr->primary, fptr->inserting, rptr );

			// Record Fields are After
			inxsql_bind_fields( fptr, (fptr->inserting+1), (rptr+inxsql_field_bsize(&fptr->primary)));
		}
	}

	// return the statement binding
	return( inxsql_insert_data( fptr, iptr, dptr, dlen ) );
}

/*	--------------------	*/
/*	inxsql_insert_record	*/
/*	--------------------	*/
interface  int	inxsql_insert_record_ps( struct xs_file * fptr , char * iptr, char * dptr, int dlen)
{
	int	offset=0;
	int	status=_SUCCESS;
	int	flen=0;
	struct	xs_field * cptr;
	struct	xs_connection * xptr;
	MYSQL_STMT * sptr=(MYSQL_STMT *) 0;
	MYSQL_BIND * bptr=(MYSQL_BIND *) 0;

	if ( verbose ) printf("inxsql_insert_record()\r\n");
	if (!( xptr = fptr->connection ))
		return(inxsql_connection_failure(fptr));
        else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
                return( status );
	else if ( inxsql_drop_file_view( fptr ) != _SUCCESS )
		return(inxsql_connection_failure(fptr));
	else if ((status = inxsql_commit_transaction( xptr ) ))
		return( status );
	else if ((status = inxsql_file_unlock_record( fptr )))
		return( status );
	else if (!( sptr = inxsql_insert_query( fptr, dlen ) ))
		return(_ERROR_STATEMENT);
	else if (!( bptr = inxsql_insert_binding( fptr, iptr, dptr, dlen ) ))
		return(_ERROR_STATEMENT);
	else if ((status = mysql_stmt_bind_param( fptr->insert, fptr->inserting)) != 0)
		return(_ERROR_STATEMENT);
	else if ((status =  mysql_stmt_execute( fptr->insert )) != 0)
	{
		inxsql_log_statement_failure(fptr->insert);
		switch ( fptr->insert->last_errno )
		{
		case	ER_WARN_DATA_OUT_OF_RANGE: // incorrect BCD
			return(_ERROR_RECORD_BCD );
		case	ER_TRUNCATED_WRONG_VALUE: // inccorect DATE
			return(_ERROR_RECORD_DATE );
		case	ER_DUP_ENTRY:
			return(_ERROR_RECORD_EXISTS);
		default		:
			return(fptr->insert->last_errno);
		}
	}
	else
	{
		memcpy(fptr->lastkey,iptr,fptr->primary.size);
		return( _SUCCESS );
	}
}

/*	--------------------	*/
/*	inxsql_update_record	*/
/*	--------------------	*/
interface  int	inxsql_update_record_ps( struct xs_file * fptr , char * iptr, char * dptr, int dlen)
{
	int	offset=0;
	int	status=_SUCCESS;
	int	flen=0;
	struct	xs_field * cptr;
	struct	xs_connection * xptr;
	MYSQL_STMT * sptr=(MYSQL_STMT *) 0;
	MYSQL_BIND * bptr=(MYSQL_BIND *) 0;

	if ( verbose ) printf("inxsql_update_record()\r\n");
	if (!( xptr = fptr->connection ))
		return(inxsql_connection_failure(fptr));
        else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
                return( status );
	else if ( inxsql_drop_file_view( fptr ) != _SUCCESS )
		return(inxsql_connection_failure(fptr));
	else if ((status = inxsql_file_unlock_record( fptr )))
		return( status );
	else if (!( sptr = inxsql_update_query( fptr, dlen ) ))
		return(_ERROR_STATEMENT);
	else if (!( bptr = inxsql_update_binding( fptr, iptr, dptr, dlen ) ))
		return(_ERROR_STATEMENT);
	else if ((status = mysql_stmt_bind_param( fptr->update, fptr->updating)) != 0)
		return(_ERROR_STATEMENT);
	else if ((status =  mysql_stmt_execute( fptr->update )) != 0)
	{
		inxsql_log_statement_failure(fptr->update);
		switch ( fptr->update->last_errno )
		{
		case	ER_WARN_DATA_OUT_OF_RANGE: // incorrect BCD
			return(_ERROR_RECORD_BCD );
		case	ER_TRUNCATED_WRONG_VALUE: // incorrect DATE
			return(_ERROR_RECORD_DATE );
		default		:
			return(fptr->update->last_errno);
		}
	}
	else if (!( fptr->update-> affected_rows ))
		return(_ERROR_RECORD_NOT_FOUND);
	else
	{
		memcpy(fptr->lastkey,iptr,fptr->primary.size);
		return( inxsql_commit_transaction( xptr ) );
	}
}

#endif

/*	--------------------	*/
/*	inxsql_insert_record	*/
/*	--------------------	*/
interface  int	inxsql_insert_record_sql( struct xs_file * fptr , char * iptr, char * dptr, int dlen)
{
	char *	query=(char *) 0;
	int	offset=0;
	int	status=_SUCCESS;
	int	flen=0;
	struct	xs_field * cptr;
	struct	xs_connection * xptr;
	if ( verbose ) printf("inxsql_insert_record()\r\n");
	if (!( xptr = fptr->connection ))
		return(inxsql_connection_failure(fptr));
        else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
                return( status );
	else if ( inxsql_drop_file_view( fptr ) != _SUCCESS )
		return(inxsql_connection_failure(fptr));
	else if ((status = inxsql_commit_transaction( xptr ) ))
		return( status );
	else if ((status = inxsql_file_unlock_record( fptr )))
		return( status );
	else if (!( query = allocate( _STD_QUERY_LENGTH + inxsql_file_qlength(fptr) + dlen + strlen(fptr->name) + fptr->primary.size) ))
		return(_ERROR_MEMORY);
	else
	{
		/* ---------------------------- */
		/* prepare the INSERT statement */
		/* ---------------------------- */
		sprintf(query,"INSERT INTO %s",inxsql_table_name(fptr));
		strcat(query,"(");
		strcat(query,fptr->primary.name);
		inxsql_append_field_names(query,fptr->first,1);
		strcat(query,")");
		strcat(query," VALUES(");
		offset = strlen( query );

		/* ------------------------ */
		/* generate the index value */
		/* ------------------------ */
		if (!( offset = inxsql_set_field_value( &fptr->primary, query, offset, iptr, fptr->primary.size, fptr->align, 0) ))
		{
			liberate(query);
			return(_ERROR_SYNTAX);
		}

		/* ---------------------------------- */
		/* Transfer the Field / Column Values */
		/* ---------------------------------- */
		for (	cptr = fptr->first;
			cptr != (struct xs_field *) 0;
			cptr = cptr->next )
		{
			/* ----------------------- */
			/* avoid the primary index */
			/* ----------------------- */
			if (!( strcmp( cptr->name, fptr->primary.name ) ))
			{
				continue;
			}
			/* --------------------------------- */
			/* one single variable length binary */
			/* --------------------------------- */
			else if ( cptr->type == _INXS_VARBIN )
				flen = dlen;
			/* ---------------------------------- */
			/* ensure that more data is available */
			/* ---------------------------------- */
			else if (( flen = inxsql_field_size(cptr)) > dlen)
			{
				liberate(query);
				return(_ERROR_NOT_ENOUGH_DATA);
			}
			/* ------------------------------- */
			/* no data for this one so jump it */
			/* ------------------------------- */
			else if (!( flen )) continue;

			/* ------------------------ */
			/* data needs the separator */
			/* ------------------------ */
			query[offset++] = ',';

			/* ------------------------ */
			/* generate the field value */
			/* ------------------------ */
			if (!( offset = inxsql_set_field_value( cptr, query, offset, dptr, flen, 0, 0 ) ))
			{
				liberate(query);
				return(_ERROR_SYNTAX);
			}
			/* ------------------------- */
			/* consume this data portion */
			/* ------------------------- */
			else
			{
				dptr += flen;
				dlen -= flen;
			}
		}

		/* ------------------------------ */
		/* terminate the INSERT statement */
		/* ------------------------------ */
		query[offset++] = ')';
		query[offset++] = 0;

		/* ------------------------------- */
		/* launch request and handle error */
		/* ------------------------------- */
 		if (!( inxsql_query(fptr->connection, query, offset) ))
		{
			memcpy(fptr->lastkey,iptr,fptr->primary.size);
			liberate(query);
			return(_SUCCESS);
		}
		else
		{
			liberate(query);
			return(_ERROR_RECORD_EXISTS);
		}
	}
}

/*	--------------------	*/
/*	inxsql_update_record	*/
/*	--------------------	*/
interface  int	inxsql_update_record_sql( struct xs_file * fptr , char * iptr, char * dptr, int dlen)
{
	char *	query=(char *) 0;
	int	offset=0;
	int	items=0;
	int	status=_SUCCESS;
	int	flen;
	struct	xs_field * cptr;
	struct	xs_connection * xptr;
	if ( verbose ) printf("inxsql_update_record()\r\n");
	if (!( xptr = fptr->connection ))
		return(inxsql_connection_failure(fptr));
        else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
                return( status );
	else if ( inxsql_drop_file_view( fptr ) != _SUCCESS )
		return(inxsql_connection_failure(fptr));
	else if ((status = inxsql_commit_transaction( xptr ) ))
		return( status );
	else if ((status = inxsql_file_unlock_record( fptr )))
		return( status );
	else if (!( query = allocate( _STD_QUERY_LENGTH + inxsql_file_qlength(fptr) + dlen + strlen(fptr->name) + fptr->primary.size) ))
		return(_ERROR_MEMORY);
	else
	{
		/* ---------------------------- */
		/* prepare the UPDATE statement */
		/* ---------------------------- */
		sprintf(query,"UPDATE %s SET ",inxsql_table_name(fptr));
		offset = strlen(query);
		items = 0;

		/* ---------------------------------- */
		/* handle the column data expressions */
		/* ---------------------------------- */
		for (	cptr = fptr->first;
			cptr != (struct xs_field *) 0;
			cptr = cptr->next )
		{
			/* ----------------------- */
			/* avoid the primary index */
			/* ----------------------- */
			if (!( strcmp( cptr->name, fptr->primary.name ) ))
			{
				continue;
			}
			/* --------------------------------- */
			/* one single variable length binary */
			/* --------------------------------- */
			if ( cptr->type == _INXS_VARBIN )
				flen = dlen;

			/* ----------------------------- */
			/* handle the data record member */
			/* ----------------------------- */
			else if (( flen = inxsql_field_size(cptr)) > dlen)
			{
				liberate(query);
				return(_ERROR_NOT_ENOUGH_DATA);
			}
			else if (!( flen )) continue;

			/* ------------------------ */
			/* data needs the separator */
			/* ------------------------ */
			if ( items++ ) query[offset++] = ',';

			/* ------------------------ */
			/* prepare the NAME = VALUE */
			/* ------------------------ */
			offset = inxsql_append_query(query,offset,cptr->name);
			query[offset++] = '=';

			/* ------------------------ */
			/* generate the field value */
			/* ------------------------ */
			if (!( offset = inxsql_set_field_value( cptr, query, offset, dptr, flen, 0, 0 ) ))
			{
				liberate(query);
				return(_ERROR_SYNTAX);
			}
			/* ------------------------- */
			/* consume this data portion */
			/* ------------------------- */
			else
			{
				dptr += flen;
				dlen -= flen;
			}
		}

		/* ----------------------------- */
		/* prepare the primary key value */
		/* ----------------------------- */
		offset = inxsql_append_query(query,offset," WHERE ");
		offset = inxsql_append_query(query,offset,fptr->primary.name);
		offset = inxsql_append_query(query,offset,_INXS_EQ);

		/* ----------------------------- */
		/* prepare the primary key value */
		/* ----------------------------- */
		if (!( offset = inxsql_primary_field_value(&fptr->primary,query,offset,iptr,fptr->primary.size,fptr->align)))
		{
			liberate(query);
			return(_ERROR_SYNTAX);
		}
		/* ------------------------- */
		/* terminate it for the form */
		/* ------------------------- */
		query[offset] = 0;

		/* ------------------------------- */
		/* launch request and handle error */
		/* ------------------------------- */
 		if ( inxsql_query(fptr->connection, query, offset) != 0 )
		{
			liberate(query);
			return( _ERROR_RECORD_NOT_FOUND );
		}
#ifdef	_INXSQL_MYSQL
		else if (!( mysql_affected_rows(  fptr->connection->handle ) ))
		{
			liberate(query);
			return( _ERROR_RECORD_NOT_FOUND );
		}
		else if (!( status = mysql_errno( fptr->connection->handle ) ))
		{
			memcpy(fptr->lastkey,iptr,fptr->primary.size);
			liberate(query);
			return( inxsql_commit_transaction( xptr ) );
		}
#endif
		else
		{
			liberate(query);
			return( _ERROR_RECORD_NOT_FOUND );
		}
	}
}

/*	--------------------	*/
/*	inxsql_insert_record	*/
/*	--------------------	*/
private	int	inssqlps=-1;
interface  int	inxsql_insert_record( struct xs_file * fptr , char * iptr, char * dptr, int dlen)
{
#ifdef	_INXSQL_MYSQL
	char *	eptr;
	if ( fptr->connection->engine == _INXSQL_MYSQL_ENGINE )
	{
		if ( inssqlps == -1 )
			inssqlps = inxsql_boolean( "INXSQLINSERTPS",1 );
		if (!( inssqlps ))
			return( inxsql_insert_record_sql( fptr, iptr, dptr, dlen ) );
		else	return( inxsql_insert_record_ps( fptr, iptr, dptr, dlen ) );
	}
	else
#endif
	return( inxsql_insert_record_sql( fptr, iptr, dptr, dlen ) );
}

/*	--------------------	*/
/*	inxsql_update_record	*/
/*	--------------------	*/
private	int	updsqlps=-1;
interface  int	inxsql_update_record( struct xs_file * fptr , char * iptr, char * dptr, int dlen)
{
#ifdef	_INXSQL_MYSQL
	char *	eptr;
	if ( fptr->connection->engine == _INXSQL_MYSQL_ENGINE )
	{
		if ( updsqlps == -1 )
			updsqlps = inxsql_boolean( "INXSQLUPDATEPS",1 );
		if (!( updsqlps ))
			return( inxsql_update_record_sql( fptr, iptr, dptr, dlen ) );
		else	return( inxsql_update_record_ps( fptr, iptr, dptr, dlen ) );
	}
	else
#endif
	return( inxsql_update_record_sql( fptr, iptr, dptr, dlen ) );
}

/*	-------------------------	*/
/*	 inxsql_buffer_too_small	*/
/*	-------------------------	*/
public	int	inxsql_buffer_too_small(void * vptr)
{
	FILE *h;
	struct	xs_file * fptr;
	struct	xs_field * cptr;
	int	offset=0;
	int	outset=0;
	if (!( fptr = (struct xs_file *) vptr))
		return(_ERROR_BUFFER_TOO_SMALL);
	else if (!( h = fopen("/tmp/bufftoosmall.txt","a") ))
		return(_ERROR_BUFFER_TOO_SMALL);
	else
	{
		fprintf(h,"----------------------\n");
		fprintf(h,"ERROR BUFFER TOO SMALL\n");
		fprintf(h,"----------------------\n");
		fprintf(h,"FILE =%s\n",fptr->name);
		fprintf(h,"DATALENGTH=%u\n",fptr->datalength);
		fprintf(h,"BLENGTH=%u\n",fptr->blength);
		fprintf(h,"QLENGTH=%u\n",fptr->qlength);
		fprintf(h,"FLENGTH=%u\n",fptr->flength);
		for (	cptr = fptr->first; 
			cptr != (struct xs_field *) 0;
			cptr = cptr->next )
		{
			fprintf(h,"COLUMN(%08x: %s,%u,%u,%u)\n",offset,cptr->name,cptr->type,cptr->size,cptr->extra);
			outset += inxsql_field_bsize(cptr);	
			offset += inxsql_field_size(cptr);	
		}
		fprintf(h,"OFFSET=%u\n",offset);
		fprintf(h,"OUTSET=%u\n",outset);
		fclose(h);
		return(_ERROR_BUFFER_TOO_SMALL);
	}
}

/*	-----------------	*/
/*	inxsql_check_lock	*/
/*	-----------------	*/
private	int	inxsql_check_lock(struct xs_file * fptr, int failure)
{
	int	status;
#ifdef	_INXSQL_MYSQL
	switch ((status = mysql_errno( fptr->connection->handle )))
	{
	case	ER_LOCK_WAIT_TIMEOUT : 	// MARIA DB LOCK NOWAIT EXCEPTION
	case	3572		:	// MYSQL 8  LOCK NOWAIT EXCEPTION
	case	ER_FILE_USED	:
	case	ER_TABLE_NOT_LOCKED_FOR_WRITE:
		return( _ERROR_LOCK_FAILURE );
	default	:	
		return(failure);
	}
#else
	return( failure );
#endif
}

/*	-------------------------	*/
/*	inxsql_connection_failure	*/
/*	-------------------------	*/
public	int	inxsql_connection_failure(void * vptr)
{
	return(_ERROR_CONNECTION);
}

/*	-----------------------	*/
/*	inxsql_retrieve_record	*/
/*	-----------------------	*/
interface  int	inxsql_retrieve_record( struct xs_file * fptr , char * iptr, char * dptr, int dlen, int lock, int * vrl)
{
	char *	query=(char *) 0;
	int	offset=0;
	int	flen=0;
	int	status=_SUCCESS;
	int	f=0;
	int	records=0;
	int	rs=0;
	struct	xs_field * cptr;
	struct	xs_connection * xptr;
	if ( verbose ) printf("inxsql_retrieve_record()\r\n");
	if (!( xptr = fptr->connection ))
		return(inxsql_connection_failure(fptr));
        else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
                return( status );
	else if ( inxsql_drop_file_view( fptr ) != _SUCCESS )
		return(inxsql_connection_failure(fptr));
	else if ((status = inxsql_commit_transaction( xptr ) ))
		return( status );
	else if ((status = inxsql_file_unlock_record( fptr )))
		return( status );
	else if (!( query = allocate( _STD_QUERY_LENGTH + inxsql_file_qlength(fptr) + strlen(fptr->name) + fptr->primary.size) ))
		return(_ERROR_MEMORY);
	else
	{
		// start a transaction if record locking
		if (( lock ) && ((status = inxsql_start_transaction( xptr )) != _SUCCESS))
			return( status );

		/* ---------------------------- */
		/* prepare the INSERT statement */
		/* ---------------------------- */
		strcpy(query,"SELECT ");
		inxsql_append_field_names(query,fptr->first,0);
		strcat(query," FROM ");
		strcat(query,inxsql_table_name(fptr));

		strcat(query," WHERE ");
		strcat(query,fptr->primary.name);
		strcat(query,_INXS_EQ);

		/* ----------------------------- */
		/* prepare the primary key value */
		/* ----------------------------- */
		if (!( offset = inxsql_primary_field_value(&fptr->primary,query,strlen(query),iptr,fptr->primary.size,fptr->align)))
		{
			liberate(query);
			return(_ERROR_SYNTAX);
		}

		offset = inxsql_append_query(query,offset,_ORDER_BY);
		offset = inxsql_append_query(query,offset,fptr->primary.name);
		offset = inxsql_append_query(query,offset,_ASC);
		offset = inxsql_append_query(query,offset,_LIMIT_ONE);

		// check for and handle record locking
		if ( lock )
		{
			offset = inxsql_append_query(query,offset,_FOR_UPDATE_NOWAIT);
		}

		query[offset++] = 0;

		/* ------------------------------- */
		/* launch request and handle error */
		/* ------------------------------- */
 		if ( inxsql_query(fptr->connection, query, offset) != _SUCCESS )
		{
			liberate(query);
			return( inxsql_check_lock( fptr, _ERROR_RECORD_NOT_FOUND) );
		}
		/* --------------------------------- */
		/* is there a result to be retrieved */
		/* --------------------------------- */
		else if (!( xptr->result = inxsql_store_result(xptr) ))
		{
			/* ------------------ */
			/* no result returned */
			/* ------------------ */
			liberate(query);
			return(_ERROR_RECORD_NOT_FOUND);
		}
        	else if (!( inxsql_num_fields(xptr) ))
		{
			/* ------------------ */
			/* no fields returned */
			/* ------------------ */
               		inxsql_free_result(xptr);
			liberate(query);
			return(_ERROR_RECORD_NOT_FOUND);
		}
		else
		{
			/* ------------------ */
			/* process the result */
			/* ------------------ */
			memcpy(fptr->lastkey,iptr,fptr->primary.size);
			/* --------------------------------- */
			/* for all rows (should only be one) */
			/* --------------------------------- */
			INXSQL_ROW row;
			while ((row = inxsql_fetch_row(xptr)))
			{
				unsigned long * rowlength = inxsql_fetch_lengths(xptr);
				records++;

				/* --------------- */
				/* for all columns */
				/* --------------- */
				for (	f=0, cptr = fptr->first;
					cptr != (struct xs_field *) 0;
					cptr = cptr->next )
				{
					/* ------------------------------ */
					/* avoid the primary index column */
					/* ------------------------------ */
					if (!( strcmp( cptr->name, fptr->primary.name ) ))
					{
						continue;
					}
					/* ----------------------------- */
					/* watch out for variable length */
					/* ----------------------------- */
					if ( cptr->type != _INXS_VARBIN )
					{
						/* ------------------------------ */
						/* calculate the column data size */
						/* ------------------------------ */
						if (( flen = inxsql_field_size( cptr )) > dlen )
						{
               						inxsql_free_result(xptr);
							liberate(query);
							return(inxsql_buffer_too_small(fptr));
						}
						else if (!( flen ))
							continue;
					}
					/* ---------------------------- */
					/* the the variable length data */
					/* ---------------------------- */
					else if (!( flen = rowlength[f] ))
						continue;
					/* ------------------------------ */
					/* transfer data to output buffer */
					/* ------------------------------ */
					if (!( flen = inxsql_get_field_value( cptr, inxsql_fetch_field(xptr,row,f), rowlength[f], dptr, flen ) ))
					{
						f++;
						continue;
					}
					else
					{
						rs += flen;
						f++;
						dptr += flen;
						dlen -= flen;
					}
				}
			}
               		inxsql_free_result(xptr);
			liberate(query);
			if (!( records ))
				return( _ERROR_RECORD_NOT_FOUND );
			else 
			{
				*vrl = rs;
				if (!( lock ))
					return(_SUCCESS);
				else	return(inxsql_file_lock_record(fptr));
			}
		}
	}
}

/*	--------------------	*/
/*	inxsql_delete_record	*/
/*	--------------------	*/
interface  int	inxsql_delete_record( struct xs_file * fptr , char * iptr )
{
	char *	query=(char *) 0;
	int	offset=0;
	int	status=_SUCCESS;
	struct	xs_connection * xptr;
	if ( verbose ) printf("inxsql_delete_record()\r\n");
	if (!( xptr = fptr->connection ))
		return(inxsql_connection_failure(fptr));
        else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
                return( status );
	else if ( inxsql_drop_file_view( fptr ) != _SUCCESS )
		return(inxsql_connection_failure(fptr));
	else if ((status = inxsql_commit_transaction( xptr ) ))
		return( status );
	else if ((status = inxsql_file_unlock_record( fptr )))
		return( status );
	else if (!( query = allocate( _STD_QUERY_LENGTH + inxsql_file_qlength(fptr) + strlen(fptr->name) + fptr->primary.size) ))
		return(_ERROR_MEMORY);
	else
	{
		/* ---------------------------- */
		/* prepare the DELETE statement */
		/* ---------------------------- */
		sprintf(query,"DELETE FROM %s WHERE %s=",inxsql_table_name(fptr),fptr->primary.name);

		/* ----------------------------- */
		/* prepare the primary key value */
		/* ----------------------------- */
		if (!( offset = inxsql_primary_field_value(&fptr->primary,query,strlen(query),iptr,fptr->primary.size,fptr->align)))
		{
			liberate(query);
			return(_ERROR_SYNTAX);
		}

		query[offset++] = 0;

		/* ------------------------------- */
		/* launch request and handle error */
		/* ------------------------------- */
 		if (!( inxsql_query(fptr->connection, query, offset) ))
		{
			liberate(query);
			memcpy(fptr->lastkey,iptr,fptr->primary.size);
			return(_SUCCESS);
		}
		else
		{
			liberate(query);
			return(_ERROR_RECORD_NOT_FOUND);
		}
	}

	return(0);
}

/*	------------------------	*/
/*	inxsql_sequential_record	*/
/*	------------------------	*/
private	int	inxsql_sequential(struct xs_file * fptr, char * query, char * dptr, int dlen, int failure,int dir, int cmp, int lock, int * vrl )
{
	int	offset=0;
	struct	xs_connection * xptr;
	struct	xs_index * iptr;
	struct	xs_field * cptr;
	struct	xs_link  * lptr;
	int	flen;
	int	rs=0;
	int	items=0;
	int 	f;
	int	nature=failure;
	char *	sep="";
	char *	compare;
	char 	value[64];
	int	status=0;

	/* -------------------- */
	/* check the connection */
	/* -------------------- */
	if (!( xptr = fptr->connection ))
		return(inxsql_connection_failure(fptr));

	// start a transaction if record locking
	if (( lock ) && ((status = inxsql_start_transaction( xptr )) != _SUCCESS))
		return( status );

	/* ---------------------------- */
	/* prepare the SELECT statement */
	/* ---------------------------- */
	sprintf(query,"SELECT %s",fptr->primary.name);
	inxsql_append_field_names(query,fptr->first,1);
	strcat(query," FROM ");
	strcat(query,inxsql_table_name(fptr));
	if ( fptr->view ) 
	{ 
		failure = _ERROR_END_OF_SELECTION;
		strcat(query,"_");
		strcat(query,fptr->view->name); 
		strcat(query,"_");
		strcat(query,fptr->view->id); 
	}

	/* ---------------------------------------- */
	/* IF NO selection : then use primary index */
	/* ---------------------------------------- */
	if (!(iptr = fptr->selection))
	{
		strcat(query," WHERE ");

		// handle the compare type
		switch ( cmp )
		{
		case	_POSIT_NE	:
			compare = _INXS_NE;
			break;
		case	_POSIT_GT	:
			compare = _INXS_GT;
			break;
		case	_POSIT_GE	:
			compare = _INXS_GE;
			break;
		case	_POSIT_LT	:
			compare = _INXS_LT;
			break;
		case	_POSIT_LE	:
			compare = _INXS_LE;
			break;
		case	_POSIT_EQ 	:
		default			:
			compare = _INXS_EQ;
			break;
		}

		strcat(query,fptr->primary.name);
		strcat(query,compare);

		// prepare the primary key value 
		if (!( offset = inxsql_primary_field_value(&fptr->primary,query,strlen(query),fptr->lastkey,fptr->primary.size,fptr->align)))
		{
			liberate(query);
			return(_ERROR_SYNTAX);
		}
	}
	else
	{
		offset = strlen( query );
	}

	/* -------------------------- */
	/* handle the ORDER BY CLAUSE */
	/* -------------------------- */
	offset = inxsql_append_query(query,offset,_ORDER_BY);
	if (!( iptr ))
	{
		// for NON INDEXED UP/DOWN
		offset = inxsql_append_query(query,offset,fptr->primary.name);
		offset = inxsql_append_query(query,offset,dir==_INXS_ASC?_ASC:_DESC);
	}
	else if (!( fptr->orderby ))
	{
		// for INDEXED UP/DOWN
		for (	sep="",lptr = iptr->first;
			lptr != (struct xs_link *) 0;
			lptr = lptr->next )
		{
			offset = inxsql_append_query(query,offset,sep);
			offset = inxsql_append_query(query,offset,lptr->field->name);
			if ( iptr->reverse )
				offset = inxsql_append_query(query,offset,_DESC);
			else	offset = inxsql_append_query(query,offset,_ASC);
			sep = ",";
		}
		offset = inxsql_append_query(query,offset,sep);
		offset = inxsql_append_query(query,offset,fptr->primary.name);
		if ( iptr->reverse )
			offset = inxsql_append_query(query,offset,_DESC);
		else	offset = inxsql_append_query(query,offset,_ASC);
	}
	else
	{
		// for ORDER BY INDEXED UP/DOWN
		for (	sep="",lptr = fptr->orderby->first;
			lptr != (struct xs_link *) 0;
			lptr = lptr->next )
		{
			offset = inxsql_append_query(query,offset,sep);
			offset = inxsql_append_query(query,offset,lptr->field->name);
			if ( iptr->reverse )
				offset = inxsql_append_query(query,offset,_DESC);
			else	offset = inxsql_append_query(query,offset,_ASC);
			sep = ",";
		}
	}

	/* --------------------------- */
	/* handle the LIMIT and OFFSET */
	/* --------------------------- */
	offset = inxsql_append_query(query,offset,_LIMIT_ONE);

	if ( iptr )
	{
		/* ------------------------------------------------------- */
		/* UP AND DOWN is performed WRT the CURRENT RECORD POSITON */
		/* ------------------------------------------------------- */
		// A POSIT / VIEW is ACTIVE
		offset = inxsql_append_query(query,offset,_OFFSET);
		if ( iptr->reverse )
		{
			switch ( dir )
			{
			case	_INXS_DESC	:	/* UP	*/
				if ( (iptr->current+1) < iptr->eof )
				{
					sprintf(value,"%llu",(iptr->current+1));
					break;
				}
				else
				{
					iptr->current = iptr->eof;
					query = liberate(query);
					return( failure );
				}

			case	_INXS_ASC	:	/* DOWN */
				if ( (iptr->current-1) > iptr->tof )
				{
					sprintf(value,"%llu",(iptr->current-1));
					break;
				}
				else
				{
					iptr->current = iptr->tof;
					query = liberate(query);
					return( failure );
				}
			}
		}
		else
		{
			switch ( dir )
			{
			case	_INXS_ASC	:	/* DOWN */
				if ( (iptr->current+1) < iptr->eof )
				{
					sprintf(value,"%llu",(iptr->current+1));
					break;
				}
				else
				{
					iptr->current = iptr->eof;
					query = liberate(query);
					return( failure );
				}

			case	_INXS_DESC	:	/* UP	*/
				if ( (iptr->current-1) > iptr->tof )
				{
					sprintf(value,"%llu",(iptr->current-1));
					break;
				}
				else
				{
					iptr->current = iptr->tof;
					query = liberate(query);
					return( failure );
				}
			}
		}
		offset = inxsql_append_query(query,offset,value);
	}
		
	// check for and handle record locking
	if ( lock )
	{
		offset = inxsql_append_query(query,offset,_FOR_UPDATE_NOWAIT);
	}

	/* ------------------------------- */
	/* launch request and handle error */
	/* ------------------------------- */

	query[offset++] = 0;

 	if ( inxsql_query(fptr->connection, query, offset ) != _SUCCESS )
	{
		liberate(query);
		return( inxsql_check_lock( fptr, failure ) );
	}

	/* --------------------------------- */
	/* is there a result to be retrieved */
	/* --------------------------------- */
	else if (!( xptr->result = inxsql_store_result(xptr) ))
	{
		/* ------------------ */
		/* no result returned */
		/* ------------------ */
		liberate(query);
		return(failure);
	}
       	else if (!( inxsql_num_fields(xptr) ))
	{
		/* ------------------ */
		/* no fields returned */
		/* ------------------ */
               	inxsql_free_result(xptr);
		liberate(query);
		return(failure);
	}
	else
	{
		/* ------------------ */
		/* process the result */
		/* ------------------ */
		int	records=0;
		int	slen=0;
		int	etrace=inxsql_boolean("INXSQLRAW",0);
		INXSQL_ROW row;
		while ((row = inxsql_fetch_row(xptr)))
		{
			records++;
			cptr = fptr->first;
			if ( iptr )
				lptr = iptr->first;
			else	lptr = (struct xs_link *) 0;
			if ( etrace == 2 ) fprintf(stderr,"INXSQLROW:");
			for ( int f=0; f < xptr->fields; f++ )
			{
				if ( etrace == 2 ) fprintf(stderr,"%s%c",inxsql_fetch_field(xptr,row,f),'|');
				unsigned long * rowlength = inxsql_fetch_lengths(xptr);
				if (!( f ))
				{
					/* ------------------------------ */
					/* handle the primary index field */
					/* ------------------------------ */
					if ( cptr )
						if (!( strcmp( cptr->name, fptr->primary.name ) ))
							cptr = cptr->next;

					if (!(flen = inxsql_field_size(&fptr->primary)))
					{
               					inxsql_free_result(xptr);
						liberate(query);
						return(inxsql_buffer_too_small(fptr));
					}
					else
					{
						memset(fptr->lastkey,' ',flen);
						if ((slen = rowlength[f]) > flen)
							slen = flen; 
						if (( flen = inxsql_get_field_value( &fptr->primary, inxsql_fetch_field(xptr,row,f), rowlength[f], dptr, flen )) > 0)
						{
							memcpy(fptr->lastkey,dptr,slen);
							if ( iptr )
							{
								iptr->primary = &fptr->primary;
								iptr->lastkey = fptr->lastkey;
							}
							dptr += flen;
							dlen -= flen;
							continue;
						}
						else
						{
               						inxsql_free_result(xptr);
							liberate(query);
							return(inxsql_buffer_too_small(fptr));
						}
					}
				}
				/* ---------------------------------------- */
				/* check that there is a column description */
				/* ---------------------------------------- */
				else if (!( cptr ))
				{
					break;
				}
				/* ----------------------------- */
				/* watch out for variable length */
				/* ----------------------------- */
				if ( cptr->type != _INXS_VARBIN )
				{
					/* ------------------------------------ */
					/* evaluate the column data record size */
					/* ------------------------------------ */
					if (( flen = inxsql_field_size(cptr)) > dlen)
					{
               					inxsql_free_result(xptr);
						liberate(query);
						return(inxsql_buffer_too_small(fptr));
					}
					else if (!( flen ))
					{
						if ( cptr ) 
							cptr = cptr->next;
						continue;
					}
				}
				/* ---------------------------------- */
				/* handle the variable length element */
				/* ---------------------------------- */
				else if (!( flen = rowlength[f] ))
				{
					if ( cptr ) 
						cptr = cptr->next;
					continue;
				}

				/* -------------------------------------- */
				/* store column value to ABAL data buffer */
				/* -------------------------------------- */
				if (!( flen = inxsql_get_field_value( cptr, inxsql_fetch_field(xptr,row,f), rowlength[f], dptr, flen ) ))
				{
               				inxsql_free_result(xptr);
					liberate(query);
					return(inxsql_buffer_too_small(fptr));
				}
				/* ----------------------- */
				/* consume the data buffer */
				/* ----------------------- */
				else
				{
					// detect an index field value
					if (( lptr ) && ( cptr ))
					{
						if (!( strcmp( lptr->field->name, cptr->name ) ))
						{
							lptr->type = _INXS_LINK_VALUE;
							lptr = lptr->next;
						}
					}
					rs += flen;
					dptr += flen;
					dlen -= flen;
					if ( cptr ) cptr = cptr->next;
					continue;
				}
			}
			if ( etrace == 2 ) fprintf(stderr,"\n");
		}

		/* ---------------------------- */
		/* tidy up and indicate success */
		/* ---------------------------- */
              	inxsql_free_result(xptr);
		liberate(query);
		if (!( records ))
		{
			// handle the current record index value 
			switch ( nature )
			{
			case _ERROR_TOP_OF_FILE	:
				inxsql_reset_field_value(&fptr->primary,fptr->lastkey,fptr->primary.size,0);
				inxsql_min_value(&fptr->primary,fptr->lastkey);
				if ( iptr )
				{
					if ( iptr->reverse )
						iptr->current = iptr->eof;
					else	iptr->current = iptr->tof;
					for ( 	lptr = iptr->first;
						lptr != (struct xs_link *) 0;
						lptr = lptr->next )
						lptr->type = _INXS_LINK_MIN;
				}
				break;
			case _ERROR_END_OF_FILE	:
				inxsql_reset_field_value(&fptr->primary,fptr->lastkey,fptr->primary.size,1);
				inxsql_max_value(&fptr->primary,fptr->lastkey);
				if ( iptr )
				{
					if ( iptr->reverse )
						iptr->current = iptr->tof;
					else	iptr->current = iptr->eof;
					for ( 	lptr = iptr->first;
						lptr != (struct xs_link *) 0;
						lptr = lptr->next )
						lptr->type = _INXS_LINK_MAX;
				}
				break;
			}
			return( failure );
		}
		else
		{
			if ( iptr )
			{
				if ( iptr->reverse )
				{
					switch ( dir )
					{
					case _INXS_ASC	:	/* DOWN	*/
						iptr->current--;
						break;
					case _INXS_DESC	:	/* UP */
						iptr->current++;
						break;
					}
				}
				else
				{
					switch ( dir )
					{
					case _INXS_DESC	: /* UP	*/
						iptr->current--;
						break;
					case _INXS_ASC	: /* DOWN */
						iptr->current++;
						break;
					}
				}
			}
			*vrl = rs;
			return(_SUCCESS);
		}
	}
}

/*	-------------------	*/
/*	inxsql_first_record	*/
/*	-------------------	*/
interface  int	inxsql_first_record( struct xs_file * fptr, char * dptr, int dlen, int lock, int * vrl)
{
	char *	query=(char *) 0;
	int	status=_SUCCESS;
	struct	xs_connection * xptr;
	if ( verbose ) printf("inxsql_first_record()\r\n");
	if (!( xptr = fptr->connection ))
		return(inxsql_connection_failure(fptr));
        else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
                return( status );
	else if ((status = inxsql_commit_transaction( xptr ) ))
		return( status );
	else if ((status = inxsql_file_unlock_record( fptr )))
		return( status );
	else if (!( query = allocate( _STD_QUERY_LENGTH + inxsql_file_qlength(fptr) + strlen(fptr->name) + fptr->primary.size) ))
		return(_ERROR_MEMORY);
	else	
	{
		memset(fptr->lastkey,_MIN_VALUE,fptr->primary.size);
		return( inxsql_sequential( fptr, query, dptr, dlen, _ERROR_END_OF_FILE, _INXS_ASC, _POSIT_GE, lock, vrl ) );
	}
}

/*	------------------	*/
/*	inxsql_next_record	*/
/*	------------------	*/
interface  int	inxsql_next_record( struct xs_file * fptr , char * dptr, int dlen, int lock, int * vrl)
{
	char *	query=(char *) 0;
	int	status=_SUCCESS;
	struct	xs_connection * xptr;
	if ( verbose ) printf("inxsql_next_record()\r\n");
	if (!( xptr = fptr->connection ))
		return(inxsql_connection_failure(fptr));
        else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
                return( status );
	else if ((status = inxsql_commit_transaction( xptr ) ))
		return( status );
	else if ((status = inxsql_file_unlock_record( fptr )))
		return( status );
	else if (!( query = allocate( _STD_QUERY_LENGTH + inxsql_file_qlength(fptr) + strlen(fptr->name) + fptr->primary.size) ))
		return(_ERROR_MEMORY);
	else
	{
		return( inxsql_sequential( fptr, query, dptr, dlen, _ERROR_END_OF_FILE, _INXS_ASC, _POSIT_GT, lock, vrl ) );
	}
}

/*	----------------------	*/
/*	inxsql_previous_record	*/
/*	----------------------	*/
interface  int	inxsql_previous_record( struct xs_file * fptr , char * dptr, int dlen, int lock, int * vrl )
{
	char *	query=(char *) 0;
	int	status=_SUCCESS;
	struct	xs_connection * xptr;
	if ( verbose ) printf("inxsql_previous_record()\r\n");
	if (!( xptr = fptr->connection ))
		return(inxsql_connection_failure(fptr));
        else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
                return( status );
	else if ((status = inxsql_commit_transaction( xptr ) ))
		return( status );
	else if ((status = inxsql_file_unlock_record( fptr )))
		return( status );
	else if (!( query = allocate( _STD_QUERY_LENGTH + inxsql_file_qlength(fptr) + strlen(fptr->name) + fptr->primary.size) ))
		return(_ERROR_MEMORY);
	else
	{
		return( inxsql_sequential( fptr, query, dptr, dlen, _ERROR_TOP_OF_FILE, _INXS_DESC, _POSIT_LT, lock, vrl ) );
	}
}

/*	------------------		*/
/*	inxsql_last_record		*/
/*	------------------		*/
interface  int	inxsql_last_record( struct xs_file * fptr , char * dptr, int dlen, int lock, int * vrl )
{
	char *	query=(char *) 0;
	int	status=_SUCCESS;
	struct	xs_connection * xptr;
	if ( verbose ) printf("inxsql_last_record()\r\n");
	if (!( xptr = fptr->connection ))
		return(inxsql_connection_failure(fptr));
        else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
                return( status );
	else if ((status = inxsql_commit_transaction( xptr ) ))
		return( status );
	else if ((status = inxsql_file_unlock_record( fptr )))
		return( status );
	else if (!( query = allocate( _STD_QUERY_LENGTH + inxsql_file_qlength(fptr) + strlen(fptr->name) + fptr->primary.size) ))
		return(_ERROR_MEMORY);
	else
	{
		memset(fptr->lastkey,_MAX_VALUE,fptr->primary.size);
		return( inxsql_sequential( fptr, query, dptr, dlen, _ERROR_TOP_OF_FILE, _INXS_DESC, _POSIT_LE, lock, vrl ) );
	}
}

/*	------------------------	*/
/*	inxsql_sequential_record	*/
/*	------------------------	*/
private	int inxsql_base_sequential(struct xs_base * bptr, char * query, struct xs_record * rptr, int failure, char * direction, char * compare, int lock )
{
	int	offset=0;
	struct	xs_connection * xptr;
	struct	xs_field * cptr;
	int	flen;
	int 	f;
	struct	xs_file * fptr;
	char *	dptr = (char *) 0;
	int	dlen = 0;
	int	primary=0;

	/* -------------------- */
	/* check the connection */
	/* -------------------- */
	if (!( xptr = bptr->connection ))
		return(inxsql_connection_failure(fptr));

	/* ----------------------- */
	/* ensure records for data */
	/* ----------------------- */
	else if (!( rptr ))
	{
		return(failure);
	}
	else
	{
		dptr = rptr->buffer;
		dlen = rptr->length;
		fptr = rptr->file;
		rptr = rptr->next;
		primary = 1;
	}

	/* ---------------------------- */
	/* prepare the SELECT statement */
	/* ---------------------------- */
	sprintf(query,"SELECT * FROM %s",bptr->name);
	if ( bptr->view ) 
	{ 
		strcat(query,"_");
		strcat(query,bptr->view->name); 
		strcat(query,"_");
		strcat(query,bptr->view->id); 
	}
	strcat(query," WHERE ");
	strcat(query,fptr->primary.name);
	strcat(query,compare);

	/* ----------------------------- */
	/* prepare the primary key value */
	/* ----------------------------- */
	if (!( offset = inxsql_primary_field_value(&fptr->primary,query,strlen(query),fptr->lastkey,fptr->primary.size,fptr->align)))
	{
		liberate(query);
		return(_ERROR_SYNTAX);
	}
              
	offset = inxsql_append_query(query,offset,_ORDER_BY);
	offset = inxsql_append_query(query,offset,fptr->primary.name);
	offset = inxsql_append_query(query,offset,direction);
	offset = inxsql_append_query(query,offset,_LIMIT_ONE);
	query[offset++] = 0;

	/* ------------------------------- */
	/* launch request and handle error */
	/* ------------------------------- */
 	if ( inxsql_query(fptr->connection, query, offset ) != _SUCCESS )
	{
		liberate(query);
		return(failure);
	}

	/* --------------------------------- */
	/* is there a result to be retrieved */
	/* --------------------------------- */
	else if (!( xptr->result = inxsql_store_result(xptr) ))
	{
		/* ------------------ */
		/* no result returned */
		/* ------------------ */
		liberate(query);
		return(failure);
	}
       	else if (!( inxsql_num_fields(xptr) ))
	{
		/* ------------------ */
		/* no fields returned */
		/* ------------------ */
              	inxsql_free_result(xptr);
		liberate(query);
		return(failure);
	}
	else
	{
		/* ------------------ */
		/* process the result */
		/* ------------------ */
		int	records=0;
		int	slen=0;
		INXSQL_ROW row;
		while ((row = inxsql_fetch_row(xptr)))
		{
			unsigned long * rowlength = inxsql_fetch_lengths(xptr);
			records++;
			cptr = fptr->first;
			for ( int f=0; f < xptr->fields; f++ )
			{
				/* ---------------------------------------- */
				/* check that there is a column description */
				/* ---------------------------------------- */
				if (!( cptr ))
				{
					/* ----------------------------------- */
					/* columns provide the data for buffer */
					/* ----------------------------------- */
					if (!( rptr ))
						break;
					else
					{
						dptr = rptr->buffer;
						dlen = rptr->length;
						fptr = rptr->file;
						cptr = fptr->first;
						rptr = rptr->next;
						primary = 1;
					}
				}
				if ( primary )
				{
					/* ------------------------------ */
					/* handle the primary index field */
					/* ------------------------------ */
					if ( cptr )
						if (!( strcmp( cptr->name, fptr->primary.name ) ))
							cptr = cptr->next;

					if (!(flen = inxsql_field_size(&fptr->primary)))
					{
              					inxsql_free_result(xptr);
						liberate(query);
						return(inxsql_buffer_too_small(fptr));
					}
					else
					{
						/* ---------------------------------------- */
						/*              W A R N I N G		    */
						/* ---------------------------------------- */
						/* the RECORD buffer has a strict structure */
						/* ---------------------------------------- */
						/*   err%, len%, index$, marker#, buffer$   */
						/* ---------------------------------------- */
						if (!( f ))
						{
							memset(fptr->lastkey,' ',flen);
							if ((slen = rowlength[f]) > flen)
								slen = flen; 
							// TODO : needs to handle encoding
							memcpy(fptr->lastkey,inxsql_fetch_field(xptr,row,f),slen);
						}

						/* ---------- */
						/* error code */
						/* ---------- */
						*(dptr++) = 0; dlen--;
						*(dptr++) = 0; dlen--;

						/* ---------- */
						/* datalength */
						/* ---------- */
						*(dptr++) = 0; dlen--;
						*(dptr++) = 0; dlen--;

						/* ------------- */
						/* primary index */
						/* ------------- */
						if (( flen = inxsql_get_field_value( &fptr->primary, inxsql_fetch_field(xptr,row,f), rowlength[f], dptr, flen )) > 0)
						{
							dptr += flen;
							dlen -= flen;
						}

						/* ------ */
						/* marker */
						/* ------ */
						*(dptr++) = 1; dlen--;
					}
					primary = 0;
					continue;
				}
				/* ------------------------------------ */
				/* evaluate the column data record size */
				/* ------------------------------------ */
				if (( flen = inxsql_field_size(cptr)) > dlen)
				{
              				inxsql_free_result(xptr);
					liberate(query);
					return(inxsql_buffer_too_small(fptr));
				}
				else if (!( flen ))
				{
					if ( cptr ) cptr = cptr->next;
					continue;
				}
				/* -------------------------------------- */
				/* store column value to ABAL data buffer */
				/* -------------------------------------- */
				else if (!( flen = inxsql_get_field_value( cptr, inxsql_fetch_field(xptr,row,f), rowlength[f], dptr, flen ) ))
				{
              				inxsql_free_result(xptr);
					liberate(query);
					return(inxsql_buffer_too_small(fptr));
				}
				/* ----------------------- */
				/* consume the data buffer */
				/* ----------------------- */
				else
				{
					dptr += flen;
					dlen -= flen;
					if ( cptr ) cptr = cptr->next;
					continue;
				}
			}
		}

		/* ---------------------------- */
		/* tidy up and indicate success */
		/* ---------------------------- */
              	inxsql_free_result(xptr);
		liberate(query);
		if (!( records ))
			return( failure );
		else if (!( lock ))
			return(_SUCCESS);
		else	return(inxsql_base_lock_record(bptr));
	}
}

/*	----------------------	*/
/*	inxsql_liberate_record	*/
/*	----------------------	*/
private	struct xs_record * inxsql_liberate_record( struct xs_record * rptr)
{
	if ( rptr )
	{
		rptr = liberate( rptr );
	}
	return((struct xs_record *) 0);
}

/*	-------------------------	*/
/*	 inxsql_liberate_records 	*/
/*	-------------------------	*/
private	struct xs_record * inxsql_liberate_records( struct xs_record * rptr)
{
	struct	xs_record * wptr;

	while ((wptr = rptr) != (struct xs_record *) 0)
	{
		rptr = rptr->next;
		wptr = inxsql_liberate_record( wptr );
	}
	return((struct xs_record *) 0);
}

/*	------------------	*/
/*	 inxsql_get_short	*/
/*	------------------	*/
private	int	inxsql_get_short(char * bptr, int length)
{
	int value = 0;
	int i=sizeof(short);
	while ( i-- ) { value = ((value << 8) | ( *(bptr+i) & 0x00FF )); }
	return(value);
}

/*	------------------	*/
/*	inxsql_get_pointer	*/
/*	------------------	*/
private	void *	inxsql_get_pointer(char * bptr, int length)
{
	unsigned long long value = 0;
	int i=sizeof(char *);
	while ( i-- ) { value = ((value << 8) | ( *(bptr+i) & 0x00FF )); }
	return((void *) value);
}

/*	----------------------	*/
/*	inxsql_allocate_record	*/
/*	----------------------	*/
private	struct xs_record * inxsql_allocate_record(struct xs_file * fptr, char * bptr, int blen )
{
	struct	xs_record * rptr;
	if (!( rptr = allocate( sizeof( struct xs_record ) ) ))
		return( rptr );
	else
	{
		rptr->file = fptr;
		rptr->buffer = bptr;
		rptr->length = blen;
		return( rptr );
	}
}

/*	--------------------	*/
/*	inxsql_locate_record	*/
/*	--------------------	*/
private struct xs_record * inxsql_locate_record(struct xs_record * rptr, struct xs_file * fptr)
{
	struct	xs_file * tptr;
	char *	sptr;
	char *	nptr;
	/* -------------------------- */
	/* check the input parameters */
	/* -------------------------- */
	if (!( rptr ))
		return( rptr );
	else if (!( fptr ))
		return((struct xs_record *) 0);
	else if (!( sptr = fptr->name ))
		return((struct xs_record *) 0);
	else
	{
		/* --------------------------------------------- */
		/* run the record list to find the matching file */
		/* --------------------------------------------- */
		for ( ; rptr != (struct xs_record *) 0; rptr = rptr->next )
		{
			if (!( tptr = rptr->file ))
				continue;
			else if (!( nptr = tptr->name ))
				continue;
			else if (!( inxsql_table_name_compare( sptr, nptr ) ))
				break;
		}
		return( rptr );
	}	
}

/*	---------------------	*/
/*	inxsql_connect_record	*/
/*	---------------------	*/
private	struct xs_record * inxsql_connect_record(struct xs_record * head, char * dptr, int dlen)
{
	struct	xs_record * rptr;
	struct	xs_file * fptr;

	/* --------------------------------------- */
	/* collect the file handle from descriptor */
	/* --------------------------------------- */
	if (!( fptr = inxsql_get_pointer( dptr, dlen )))
		return( (struct xs_record *) 0);

	/* ----------------------------------------- */
	/* locate the corresponding record structure */
	/* ----------------------------------------- */
	else if (!( rptr = inxsql_locate_record( head, fptr ) ))
		return( (struct xs_record *) 0);
	else	
	{
		/* ------------------------------------ */
		/* step over file to buffer information */
		/* ------------------------------------ */
		dptr += sizeof( struct xs_file * );
		dlen += sizeof( struct xs_file * );

		/* -------------------------------------- */
		/* connect the file record to data buffer */
		/* -------------------------------------- */
		if (!( rptr->buffer = inxsql_get_pointer( dptr, dlen )))
			return( (struct xs_record *) 0);
		else
		{
			dptr += sizeof( struct xs_file * );
			dlen += sizeof( struct xs_file * );

			if (!( rptr->length = inxsql_get_short( dptr, dlen )))
				return( (struct xs_record *) 0);
			else	return( rptr );
		}
	}
}

/*	-------------------	*/
/*	inxsql_load_records	*/
/*	-------------------	*/
private	struct xs_record * inxsql_load_records(struct xs_base * bptr, char * dptr, int dlen)
{
	int	records = 0;
	struct	xs_record * head=(struct xs_record *) 0;
	struct	xs_record * foot=(struct xs_record *) 0;
	struct	xs_record * rptr;
	int	xlen = (sizeof(struct xs_file *) + sizeof(char *) + sizeof(short));

	struct	xs_joint * jptr;
	struct	xs_clause * tptr;
	struct	xs_field * cptr;
	struct	xs_file  * fptr;

	if (!( jptr = bptr->join ))
		return( inxsql_liberate_records( head ) );
	else	bptr->requests++;

	/* ------------------------------------------------------- */
	/* create the rcord list in the order of the files in join */
	/* ------------------------------------------------------- */
	for (	tptr = jptr->first;
		tptr != (struct xs_clause *) 0;
		tptr = tptr->next)
	{
		/* -------------------------------------------- */
		/* process the left term and locate file handle */
		/* -------------------------------------------- */
		if (!( cptr = tptr->left ))
			return( inxsql_liberate_records( head ) );
		else if (!( fptr = cptr->file ))
			return( inxsql_liberate_records( head ) );
		else if ( fptr->usage != bptr->requests )
		{
			fptr->usage = bptr->requests;
			/* ------------------------------------ */
			/* add this file to the list of records */
			/* ------------------------------------ */
			if (!( rptr = inxsql_allocate_record( fptr, (char *) 0, 0 ) ))
				return( inxsql_liberate_records( head ) );
			else
			{
				if (!( rptr->previous = foot ))
					head = rptr;
				else	rptr->previous->next = rptr;
				foot = rptr;
			}	
		}
		
		/* --------------------------------------------- */
		/* process the right term and locate file handle */
		/* --------------------------------------------- */
		if (!( cptr = tptr->right ))
			return( inxsql_liberate_records( head ) );
		else if (!( fptr = cptr->file ))
			return( inxsql_liberate_records( head ) );
		else if ( fptr->usage != bptr->requests )
		{
			fptr->usage = bptr->requests;
			/* ------------------------------------ */
			/* add this file to the list of records */
			/* ------------------------------------ */
			if (!( rptr = inxsql_allocate_record( fptr, (char *) 0, 0 ) ))
				return( inxsql_liberate_records( head ) );
			else
			{
				if (!( rptr->previous = foot ))
					head = rptr;
				else	rptr->previous->next = rptr;
				foot = rptr;
			}	
		}
	}
	
	/* --------------------------------------------------- */
	/* collect the record buffer information for each file */
	/* --------------------------------------------------- */
	for ( dlen--, records = *(dptr++); records != 0; records--, dptr += xlen, dlen -= xlen )
	{
		/* -------------------------------------------- */
		/* check for sufficient data left in descriptor */
		/* -------------------------------------------- */
		if ( dlen < xlen )
			return( inxsql_liberate_records( head ) );

		/* ------------------------------------------------- */
		/* connect the corresponding file to the data buffer */
		/* ------------------------------------------------- */
		else if (!( rptr = inxsql_connect_record(head, dptr, dlen )))
			return( inxsql_liberate_records( head ) );

	}
	return( head );
}

/*	---------------------------	*/
/*	inxsql_previous_base_record	*/
/*	---------------------------	*/
interface  int	inxsql_previous_base_record( struct xs_base * bptr , char * dptr, int dlen, int lock )
{
	struct	xs_record * rptr;

	char *	query=(char *) 0;
	int	status=_SUCCESS;
	struct	xs_connection * xptr;

	if ( verbose ) printf("inxsql_next_record()\r\n");

	/* ----------------------------- */
	/* check connection and database */
	/* ----------------------------- */
	if (!( xptr = bptr->connection ))
		return(inxsql_connection_failure(bptr));
        else if ((status = inxsql_use_database( xptr, bptr )) != _SUCCESS)
                return( status );
	else if ((status = inxsql_commit_transaction( xptr ) ))
		return( status );
	else if ((status = inxsql_base_unlock_record( bptr )))
		return( status );

	/* ---------------------------------- */
	/* load the data file storage records */
	/* ---------------------------------- */
	else if (!( rptr = inxsql_load_records( bptr, dptr, dlen ) ))
		return(inxsql_buffer_too_small(bptr));

	/* ---------------------------- */
	/* prepare for sequential query */
	/* ---------------------------- */
	else if (!( query = allocate( (_STD_QUERY_LENGTH*3) + inxsql_base_qlength(bptr)+ strlen(bptr->name) ) ))
	{
		rptr = inxsql_liberate_records( rptr );
		return(_ERROR_MEMORY);
	}

	/* ---------------------------- */
	/* join common sequential trunk */
	/* ---------------------------- */
	if ((status = inxsql_base_sequential( bptr, query, rptr, _ERROR_END_OF_VIEW, _DESC, _INXS_LT, lock )) != _SUCCESS)
	{
		rptr = inxsql_liberate_records( rptr );
		return( _ERROR_END_OF_VIEW );
	}
	else
	{
		rptr = inxsql_liberate_records( rptr );
		return(  _SUCCESS );
	}
}

/*	-----------------------	*/
/*	inxsql_next_base_record	*/
/*	-----------------------	*/
interface  int	inxsql_next_base_record( struct xs_base * bptr , char * dptr, int dlen, int lock )
{
	struct	xs_record * rptr;
	char *	query=(char *) 0;
	int	status=_SUCCESS;
	struct	xs_connection * xptr;

	if ( verbose ) printf("inxsql_next_record()\r\n");

	/* ----------------------------- */
	/* check connection and database */
	/* ----------------------------- */
	if (!( xptr = bptr->connection ))
		return(inxsql_connection_failure(bptr));
        else if ((status = inxsql_use_database( xptr, bptr )) != _SUCCESS)
                return( status );
	else if ((status = inxsql_commit_transaction( xptr ) ))
		return( status );
	else if ((status = inxsql_base_unlock_record( bptr )))
		return( status );

	/* ---------------------------------- */
	/* load the data file storage records */
	/* ---------------------------------- */
	else if (!( rptr = inxsql_load_records( bptr, dptr, dlen ) ))
		return(inxsql_buffer_too_small(bptr));

	/* ---------------------------- */
	/* prepare for sequential query */
	/* ---------------------------- */
	else if (!( query = allocate( (_STD_QUERY_LENGTH * 3) + inxsql_base_qlength(bptr) + strlen(bptr->name) ) ))
	{
		rptr = inxsql_liberate_records( rptr );
		return(_ERROR_MEMORY);
	}

	/* ---------------------------- */
	/* join common sequential trunk */
	/* ---------------------------- */
	else if ((status = inxsql_base_sequential( bptr, query, rptr, _ERROR_END_OF_VIEW, _ASC, _INXS_GT, lock )) != _SUCCESS)
	{
		rptr = inxsql_liberate_records( rptr );
		return( _ERROR_END_OF_VIEW );
	}
	else
	{
		rptr = inxsql_liberate_records( rptr );
		return(  _SUCCESS );
	}

}

#endif	/* _inxsql_record_c */


