#ifndef	_inxsql_table_c
#define	_inxsql_table_c

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

private int inxsql_load_table_columns( struct xs_connection * xptr, char * query, struct xs_file * fptr );
private int inxsql_load_table_indexes( struct xs_connection * xptr, char * query, struct xs_file * fptr );

private char    _table_name[1024];

/*      -----------------       */
/*      inxsql_table_name       */
/*      -----------------       */
public  char *  inxsql_table_name( struct xs_file * h )
{
        if (( h ) && ( h->name ))
        {
                if (!( h->base ))
                        sprintf(_table_name,"%s",h->name);
                else    sprintf(_table_name,"%s.%s",h->base->name,h->name);
        }
        else    strcpy(_table_name,"null_table");
        return( _table_name );
}

#ifdef	_INXSQL_PGSQL
/*	-------------------------	*/
/*	inxsql_create_pgsql_table	*/
/*	-------------------------	*/
public	int	inxsql_create_pgsql_table( struct xs_file * fptr, int keytype )
{
	char 	query[_STD_QUERY_LENGTH];
	if ( verbose ) printf("inxsql_create_table()\r\n");
	switch ((fptr->align = keytype))
	{
	case _INXS_BKEY	:
		fptr->primary.type = _INXS_BIN;
		sprintf(query,"CREATE TABLE %s ( %s BYTEA PRIMARY KEY )",inxsql_table_name(fptr),fptr->primary.name);
		break;
	case _INXS_LKEY	:
	case _INXS_RKEY	:
		fptr->primary.type = _INXS_STRING;
		sprintf(query,"CREATE TABLE %s ( %s CHAR(%u) PRIMARY KEY )",inxsql_table_name(fptr),fptr->primary.name,fptr->primary.size);
		break;
	default		:
		return( _ERROR_SYNTAX );
	}
	if (!( inxsql_query( fptr->connection, query, strlen(query) )))
		return(_SUCCESS);
	else	return(_ERROR_FILE_EXISTS);
}
#endif

#ifdef	_INXSQL_MYSQL
/*	-------------------------	*/
/*	inxsql_create_mysql_table	*/
/*	-------------------------	*/
public	int	inxsql_create_mysql_table( struct xs_file * fptr, int keytype )
{
	char 	query[_STD_QUERY_LENGTH];
	if ( verbose ) printf("inxsql_create_table()\r\n");
	// handle the primary index alignment type
	switch ((fptr->align = keytype))
	{
	case _INXS_BKEY	:
		fptr->primary.type = _INXS_BIN;
		sprintf(query,"CREATE TABLE %s ( %s BINARY(%u) PRIMARY KEY )",inxsql_table_name(fptr),fptr->primary.name,fptr->primary.size);
		break;
	case _INXS_LKEY	:
	case _INXS_RKEY	:
		fptr->primary.type = _INXS_STRING;
		sprintf(query,"CREATE TABLE %s ( %s CHAR(%u) PRIMARY KEY )",inxsql_table_name(fptr),fptr->primary.name,fptr->primary.size);
		break;
	default		:
		return( _ERROR_SYNTAX );
	}
	strcat(query," CHARACTER SET = ");
	strcat(query,_INXS_CHAR_SET);
	strcat(query," COLLATE "); strcat(query,_INXS_CHAR_SET); strcat(query,"_0900_as_cs ");
	if (!( inxsql_query( fptr->connection, query, strlen(query) )))
		return(_SUCCESS);
	else	return(_ERROR_FILE_EXISTS);
}
#endif

/*	-------------------		*/
/*	inxsql_create_table		*/
/*	-------------------		*/
public	int	inxsql_create_table( struct xs_file * fptr, int keytype )
{
	switch ( fptr->connection->engine )
	{
#ifdef	_INXSQL_MYSQL	
	case	_INXSQL_MYSQL_ENGINE	:
		return( inxsql_create_mysql_table( fptr, keytype ) );
#endif
#ifdef	_INXSQL_PGSQL	
	case	_INXSQL_PGSQL_ENGINE	:
		return( inxsql_create_pgsql_table( fptr, keytype ) );
#endif
	default				:
		return( _ERROR_SYNTAX );
	}
}

/*	-------------------		*/
/*	inxsql_drop_table		*/
/*	-------------------		*/
public	int	inxsql_drop_table( struct xs_file * fptr )
{
	char 	query[_STD_QUERY_LENGTH];
	if ( verbose ) printf("inxsql_drop_table()\r\n");
	sprintf(query,"DROP TABLE %s",inxsql_table_name(fptr));
	if (!(inxsql_query( fptr->connection, query, strlen(query) )))
		return(_SUCCESS);
	else	return(_ERROR_FILE_NOT_FOUND);
}

/*	-------------------	*/
/*	inxsql_analyse_type	*/
/*	-------------------	*/
private	int	inxsql_analyse_type(char * nptr, char * sptr, int * length, int * type, int * extra )
{
	char	work[1024];
	char *	tptr = work;
	char *	vptr = work;
	char *	pptr = "0";
	int	size=0;
	int	digits=0;
	int	fraction=0;
	int	nibbles=0;

	strcpy(work,sptr);

	for (	sptr=work; *sptr != 0; sptr++ )
	{
		switch ( *sptr )
		{
		case	','	:
			pptr = (sptr+1);
			*sptr = 0;
			continue;
		case	'('	:
			vptr = (sptr+1);	
			*sptr = 0;
			continue;
		case	')'	:
		case	':'	:
		case	' '	:
			*sptr = 0;
		}
	}

	/* --------------------------------- */
	/* analsye and convert the type name */
	/* --------------------------------- */
	if ((!( strcasecmp( tptr, "char" ) ))
	||  (!( strcasecmp( tptr, "text" ) )))
	{
		*type = _INXS_STRING;
		*length = atoi(vptr);
		if (!( *length ))
		{
			/* avoid field names that are too short */
			if ( strlen(nptr) <= (strlen(_INXS_PREFIX)+strlen(_INXS_RECORD)))
				*length = 256;
			/* detect INXS and DATA wrapper on numeric value */
			else if ((!( strncasecmp( nptr, _INXS_PREFIX, strlen(_INXS_PREFIX) ) ))
		  	     &&  (!( strncasecmp( (nptr+strlen(nptr)-strlen(_INXS_RECORD)), _INXS_RECORD, strlen(_INXS_RECORD) ) )))
				*length = atoi( (nptr+strlen(_INXS_PREFIX)) );
			else	*length = 256;
		}
		return(_SUCCESS);
	}
	else if (!( strcasecmp( tptr, "varbinary" ) ))
	{
		*type = _INXS_VARBIN;
		*length = atoi(vptr);
		return(_SUCCESS);
	}
	else if (!( strcasecmp( tptr, "date" ) ))
	{
		*type = _INXS_DATE;
		*length = 4;
		return(_SUCCESS);
	}
	else if (!( strcasecmp( tptr, "time" ) ))
	{
		*type = _INXS_TIME;
		*length = 3;
		return(_SUCCESS);
	}
	else if ((!( strcasecmp( tptr, "binary" ) ))
	     ||  (!( strcasecmp( tptr, "blob" ) )))
	{
		*type = _INXS_BIN;
		*length = atoi(vptr);
		if (!( *length ))
		{
			/* avoid field names that are too short */
			if ( strlen(nptr) <= (strlen(_INXS_PREFIX)+strlen(_INXS_RECORD)))
				*length = 256;
			/* detect INXS and DATA wrapper on numeric value */
			else if ((!( strncasecmp( nptr, _INXS_PREFIX, strlen(_INXS_PREFIX) ) ))
		  	     &&  (!( strncasecmp( (nptr+strlen(nptr)-strlen(_INXS_RECORD)), _INXS_RECORD, strlen(_INXS_RECORD) ) )))
				*length = atoi( (nptr+strlen(_INXS_PREFIX)) );
			else	*length = 256;
		}
		return(_SUCCESS);
	}
	else if (!( strcasecmp( tptr, "tinyint" ) ))
	{
		*type = _INXS_INT8;
		*length = 1;
		return(_SUCCESS);
	}
	else if (!( strcasecmp( tptr, "smallint" ) ))
	{
		*type = _INXS_INT16;
		*length = 2;
		return(_SUCCESS);
	}
	else if (!( strcasecmp( tptr, "int" ) ))
	{
		*type = _INXS_INT32;
		*length = 4;
		return(_SUCCESS);
	}
	else if (!( strcasecmp( tptr, "bigint" ) ))
	{
		*type = _INXS_INT64;
		*length = 8;
		return(_SUCCESS);
	}
	else if ((!( strcasecmp( tptr, "decimal" ) ))
	     ||  (!( strcasecmp( tptr, "numeric" ) )))
	{
		*type = _INXS_BCD;
		digits =  atoi(vptr);
		fraction =  atoi(pptr);
		nibbles = (digits+(fraction?2:1));
		size = ((nibbles/2)+(nibbles&1));
		*length = size;
		*extra = fraction;
		return(_SUCCESS);
	}
	/* --------------------------- */
	/* other types not handled yet */
	/* --------------------------- */
	else	return( _ERROR_SYNTAX );

}

/*	-------------------		*/
/*	inxsql_open_table		*/
/*	-------------------		*/
public	int	inxsql_open_table( struct xs_file * fptr )
{
	char 	query[_STD_QUERY_LENGTH];
	int	status=_SUCCESS;
	struct	xs_connection * xptr = (struct xs_connection *) 0;

	if ( verbose ) printf("inxsql_open_table()\r\n");

	if (!( xptr = fptr->connection ))
		return( _ERROR_CONNECTION );
	else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
		return(status);

	/* ------------------------------------ */
	/* check that the database table exists */
	/* ------------------------------------ */
	switch ( fptr->connection->engine )
	{
#ifdef	_INXSQL_MYSQL
	case	_INXSQL_MYSQL_ENGINE	:
		sprintf(query,"SHOW TABLES LIKE '%s'",inxsql_table_name(fptr));
		break;
#endif
#ifdef	_INXSQL_PGSQL
	case	_INXSQL_PGSQL_ENGINE	:
		sprintf(query,"SELECT tablename FROM pg_catalog.pg_tables WHERE tablename LIKE '%s'",inxsql_table_name(fptr));
		break;
#endif
	default				:
		return(_ERROR_FILE_NOT_FOUND);
	}

	if ((status = inxsql_query(fptr->connection, query, strlen(query))) != _SUCCESS)
	{
		return(_ERROR_FILE_NOT_FOUND);
        }       
	/* --------------------------------- */
	/* is there a result to be retrieved */
	/* --------------------------------- */
        else if (!( xptr->result = inxsql_store_result(xptr) ))
        {
		return(_ERROR_FILE_NOT_FOUND);
	}
       	else if (!( inxsql_num_fields(xptr) ))
        {
               	inxsql_free_result(xptr);
		return(_ERROR_FILE_NOT_FOUND);
	}
	else
	{
		/* ---------------------------------- */         
       		/* the table exists so load structure */
		/* ---------------------------------- */         
               	inxsql_free_result(xptr);

		if ((status = inxsql_load_table_columns( xptr, query, fptr )) != _SUCCESS )
			return( status );
	
		else if ((status = inxsql_load_table_indexes( xptr, query, fptr )) != _SUCCESS )
			return( status );

		else	
		{
			switch ( fptr->align )
			{
			case _INXS_BKEY	:
				memset(fptr->lastkey,0,fptr->primary.size);
				break;
			case _INXS_LKEY	:
			case _INXS_RKEY	:
			default		:
				memset(fptr->lastkey,' ',fptr->primary.size);
			}		
			return( _SUCCESS );
		}
	}
}

#ifdef	_INXSQL_PGSQL
/*	-------------------------	*/
/*	inxsql_load_pgsql_indexes	*/
/*	-------------------------	*/
private int inxsql_load_pgsql_indexes( struct xs_connection * xptr, char * query, struct xs_file * fptr )
{
	struct xs_index * iptr;
	struct xs_link  * lptr;
	struct	xs_field * cptr=(struct xs_field *) 0;
	int	status=_SUCCESS;

	sprintf(query,"SELECT indexname, indexdef FROM pg_indexes WHERE tablename = '%s'",inxsql_table_name(fptr));

	if ((status = inxsql_query(fptr->connection, query, strlen(query))) != _SUCCESS)
	{
		return(_ERROR_FILE_NOT_FOUND);
	}
        else if (!( xptr->result = inxsql_store_result(xptr) ))
        {
		return(_ERROR_FILE_NOT_FOUND);
	}
       	else if (!( inxsql_num_fields(xptr) ))
	{
              	inxsql_free_result(xptr);
		return(_ERROR_FILE_NOT_FOUND);
	}
	else
	{
		INXSQL_ROW row;
		while ((row = inxsql_fetch_row(xptr)))
                {
			char * iname;
			char * tname;
			char * ivalue;
			/* --------------------------- */
			/* collect the row information */
			/* --------------------------- */
			if (!( iname = inxsql_fetch_field(xptr,row,0)))
				continue;
			else if (!( ivalue = inxsql_fetch_field(xptr,row,1)))
				continue;
			else if (!( tname = inxsql_table_name(fptr) ))
				continue;
			/* -------------------------------- */
			/* detect an possible primary index */
			/* -------------------------------- */
			else if ((!( strncmp( iname, tname, strlen(tname) ) ))
			     &&  (!( strncmp( (iname+strlen(tname)), "_pkey", strlen("_pkey") ) )))
			{
				/* -------------------------------------------- */
				/* it is the primary index so we must adapt the */
				/* table structure accordingly and make primary */
				/* -------------------------------------------- */
				iptr = (struct xs_index *) 0;
			}
			/* ---------------------------------- */
			/* detect the same index or a new one */
			/* ---------------------------------- */
			else if (!( iptr = inxsql_locate_named_index( fptr, iname)))
			{
				/* ----------------------------- */
				/* prepare a new index structure */
				/* ----------------------------- */
				if (!( iptr = inxsql_allocate_index( fptr ) ))
				{
               				inxsql_free_result(xptr);
					return(_ERROR_MEMORY);
				}
				/* ---------------------------- */
				/* collect the index / key name */
				/* ---------------------------- */
				else if (!( iptr->name = inxsql_allocate_string( iname )))
				{
               				inxsql_free_result(xptr);
					return(_ERROR_MEMORY);
				}
			}
			/* ---------------------------- */
			/* handle the index description */
			/* ---------------------------- */
			if (!( ivalue ))
				continue;

			else if (!( ivalue = strchr(ivalue, '(') ))
				continue;
			else
			{
				/* --------------------- */
				/* step over left braace */
				/* --------------------- */
				ivalue++;
				/* ----------------------------- */
				/* Analyse the INDEX Description */
				/* ----------------------------- */
				while ( *ivalue )
				{
					/* --------------------- */
					/* step over white space */
					/* --------------------- */
					while ( *ivalue == ' ') ivalue++;
					iname = ivalue;
					/* ---------------------- */
					/* step over column value */
					/* ---------------------- */
					while ( *ivalue )
					{
						if (( *ivalue == ',' ) 
						||  ( *ivalue == ' ' ) 
						||  ( *ivalue == ')' )) 
							break;
						else	ivalue++;
					}

					/* ------------------ */
					/* handle punctuation */
					/* ------------------ */
					if ( *ivalue == ')' )
						*ivalue = 0;
					else 	*(ivalue++) = 0;

					/* ------------------------ */
					/* validate the column name */
					/* ------------------------ */
					if (!( cptr = inxsql_locate_field( fptr, iname ) ))
					{
               					inxsql_free_result(xptr);
						return(_ERROR_KEY_NOT_FOUND);
					}
					else if (!( iptr ))
					{
						/* ------------------------------------- */
						/* its the primary so define the primary */
						/* ------------------------------------- */
						fptr->primary.size = cptr->size;
						fptr->primary.extra = cptr->extra;
						fptr->datalength += inxsql_field_size(cptr);
						switch ((fptr->primary.type = cptr->type))
						{
						case	_INXS_STRING	:
							fptr->align = _INXS_LKEY;
							break;
						case	_INXS_BIN	:
							fptr->align = _INXS_BKEY;
							break;
						default			:
							fptr->align = _INXS_RKEY;
							break;
						}
						/* ------------------------- */
						/* allocate the primary name */
						/* ------------------------- */
						if (!(fptr->primary.name = inxsql_allocate_string( cptr->name )))
						{
              						inxsql_free_result(xptr);
							return( _ERROR_MEMORY );
						}
						/* ---------------------------- */
						/* unlink the column from table */
						/* ---------------------------- */
						if ( cptr->next )
							cptr->next->previous = cptr->previous;
						else	fptr->last = cptr->previous;
						if ( cptr->previous )
							cptr->previous->next = cptr->next;
						else	fptr->first = cptr->next;
						/* ---------------------------- */	
						/* release the column structure */
						/* ---------------------------- */	
						cptr = inxsql_liberate_field( cptr );
						continue;
					}
					/* ----------------------------- */
					/* allocate an index column link */
					/* ----------------------------- */
					else if (!( lptr = inxsql_allocate_link( cptr )))
					{
               					inxsql_free_result(xptr);
						return(_ERROR_KEY_NOT_FOUND);
					}
					else
					{
                		                if (!( lptr->previous = iptr->last ))
                		                        iptr->first = lptr;
                		                else    lptr->previous->next = lptr;
                		                iptr->last = lptr;
					}
				}
			}
		}
		/* ---------------------------------------- */
		/* release the results and indicate success */
		/* ---------------------------------------- */
              	inxsql_free_result(xptr);
		return( _SUCCESS );
	}
}
#endif

#ifdef	_INXSQL_MYSQL
/*	-------------------------	*/
/*	inxsql_load_table_indexes	*/
/*	-------------------------	*/
private int inxsql_load_mysql_indexes( struct xs_connection * xptr, char * query, struct xs_file * fptr )
{
	struct xs_index * iptr;
	struct xs_link  * lptr;
	struct xs_field * cptr;
	int		  status=_SUCCESS;

	sprintf(query,"SHOW INDEXES FROM %s",inxsql_table_name(fptr));

	if ((status = inxsql_query(fptr->connection, query, strlen(query))) != _SUCCESS)
	{
		return(_ERROR_FILE_NOT_FOUND);
	}
        else if (!( xptr->result = inxsql_store_result(xptr) ))
        {
		return(_ERROR_FILE_NOT_FOUND);
	}
       	else if (!( inxsql_num_fields(xptr) ))
	{
               	inxsql_free_result(xptr);
		return(_ERROR_FILE_NOT_FOUND);
	}
	else
	{
		INXSQL_ROW row;
		while ((row = inxsql_fetch_row(xptr)))
                {
			/* --------------------------------- */
			/* detect the primary key definition */
			/* --------------------------------- */
			if (!( strcasecmp( inxsql_fetch_field(xptr,row,2), "PRIMARY" ) )) 
				continue;

			/* ---------------------------------- */
			/* detect the same index or a new one */
			/* ---------------------------------- */
			else if (!( iptr = inxsql_locate_named_index( fptr, inxsql_fetch_field(xptr,row,2) )))
			{
				/* ----------------------------- */
				/* prepare a new index structure */
				/* ----------------------------- */
				if (!( iptr = inxsql_allocate_index( fptr ) ))
				{
               				inxsql_free_result(xptr);
					return(_ERROR_MEMORY);
				}
				/* ---------------------------- */
				/* collect the index / key name */
				/* ---------------------------- */
				else if (!( iptr->name = inxsql_allocate_string( inxsql_fetch_field(xptr,row,2) )))
				{
               				inxsql_free_result(xptr);
					return(_ERROR_MEMORY);
				}
			}

			/* ----------------------------- */
			/* locate the column description */
			/* ----------------------------- */
			if (!( cptr = inxsql_locate_field( fptr, inxsql_fetch_field(xptr,row,4) ) ))
			{
               			inxsql_free_result(xptr);
				return(_ERROR_KEY_NOT_FOUND);
			}

			/* ----------------------------- */
			/* allocate an index column link */
			/* ----------------------------- */
			else if (!( lptr = inxsql_allocate_link( cptr )))
			{
               			inxsql_free_result(xptr);
				return(_ERROR_MEMORY);
			}
			else
			{
                                if (!( lptr->previous = iptr->last ))
                                        iptr->first = lptr;
                                else    lptr->previous->next = lptr;
                                iptr->last = lptr;
			}
       		}

		/* ---------------------------------------- */
		/* release the results and indicate success */
		/* ---------------------------------------- */
              	inxsql_free_result(xptr);
		return( _SUCCESS );
	}
}
#endif

#ifdef	_INXSQL_PGSQL

/*	-----------------	*/
/*	inxsql_pgsql_type	*/
/*	-----------------	*/
private	int inxsql_pgsql_type( char * tptr, int * length )
{
	if (!( strcasecmp( tptr, "tinyint" )))
	{
		*length = 1;
		return(_INXS_INT8);
	}
	else if (!( strcasecmp( tptr, "smallint" )))
	{
		*length = 2;
		return(_INXS_INT16);
	}
	else if (!( strcasecmp( tptr, "integer" )))
	{
		*length = 4;
		return(_INXS_INT32);
	}
	else if (!( strcasecmp( tptr, "bigint" )))
	{
		*length = 8;
		return(_INXS_INT64);
	}
	else if (!( strcasecmp( tptr, "decimal" )))
	{
		return(_INXS_BCD);
	}
	else if (!( strcasecmp( tptr, "numeric" )))
	{
		return(_INXS_BCD);
	}
	else if (!( strcasecmp( tptr, "real" )))
	{
		*length = 4;
		return(_INXS_FLOAT);
	}
	else if (!( strcasecmp( tptr, "double" )))
	{
		*length = 8;
		return(_INXS_FLOAT);
	}
	else if (!( strcasecmp( tptr, "character" )))
	{
		return(_INXS_STRING);
	}
	else if (!( strcasecmp( tptr, "text" )))
	{
		return(_INXS_VARBIN);
	}
	else if (!( strcasecmp( tptr, "bytea" )))
	{
		return(_INXS_BIN);
	}
	else if (!( strcasecmp( tptr, "date" )))
	{
		return(_INXS_DATE);
	}
	else if (!( strcasecmp( tptr, "time" )))
	{
		return(_INXS_TIME);
	}
	else	return(-1);
}

/*	-------------------------	*/
/*	inxsql_load_pgsql_columns	*/
/*	-------------------------	*/
private int inxsql_load_pgsql_columns( struct xs_connection * xptr, char * query, struct xs_file * fptr )
{
	struct	xs_field * cptr=(struct xs_field *) 0;
	int	status=_SUCCESS;

	sprintf(query,"SELECT column_name, data_type, character_maximum_length, numeric_precision, numeric_scale FROM information_schema.columns WHERE table_name = '%s'",inxsql_table_name(fptr));

	if ((status = inxsql_query(fptr->connection, query, strlen(query))) != _SUCCESS)
	{
		return(_ERROR_FILE_NOT_FOUND);
	}
        else if (!( xptr->result = inxsql_store_result(xptr) ))
        {
		return(_ERROR_FILE_NOT_FOUND);
	}
       	else if (!( inxsql_num_fields(xptr) ))
	{
              	inxsql_free_result(xptr);
		return(_ERROR_FILE_NOT_FOUND);
	}
	else
	{
		fptr->datalength = 0;
		INXSQL_ROW row;
		while ((row = inxsql_fetch_row(xptr)))
                {
			int digits=0;
			int fractions=0;
			int length=15;
			int type=_INXS_STRING;
			int primary=0;
			char * tptr;
			char * nptr;

			if (!( nptr = inxsql_fetch_field(xptr,row, 0) ))
				continue;
			else if (!( tptr = inxsql_fetch_field(xptr,row, 1) ))
				continue;
			else if (( type = inxsql_pgsql_type( tptr, &length )) < 0)
				continue;
			else
			{
				if (!( length ))
					length = atoi( inxsql_fetch_field(xptr,row,2) );
				if ( type == _INXS_BCD )
				{
					digits = atoi( inxsql_fetch_field(xptr,row,3) );
					fractions = atoi( inxsql_fetch_field(xptr,row,4) );
				}
			}
			/* -------------------------------- */
			/* handle the record key definition */
			/* -------------------------------- */
			if (!( cptr = inxsql_add_field( fptr, nptr, length?length:digits, type, fractions)))
			{
              			inxsql_free_result(xptr);
				return( _ERROR_MEMORY );
			}
			/* ------------------------------------ */
			/* adjust the global file record length */
			/* ------------------------------------ */
			else
			{
				fptr->datalength += inxsql_field_size(cptr);
			}
		}
		/* ---------------------------------------- */
		/* release the results and indicate success */
		/* ---------------------------------------- */
              	inxsql_free_result(xptr);
		return( _SUCCESS );
	}
}
#endif

#ifdef	_INXSQL_MYSQL
/*	-------------------------	*/
/*	inxsql_load_mysql_columns	*/
/*	-------------------------	*/
private int inxsql_load_mysql_columns( struct xs_connection * xptr, char * query, struct xs_file * fptr )
{
	struct	xs_field * cptr=(struct xs_field *) 0;
	int	status=_SUCCESS;

	sprintf(query,"SHOW COLUMNS FROM %s",inxsql_table_name(fptr));

	if ((status = inxsql_query(fptr->connection, query, strlen(query))) != _SUCCESS)
	{
		return(_ERROR_FILE_NOT_FOUND);
	}
        else if (!( xptr->result = inxsql_store_result(xptr) ))
        {
		return(_ERROR_FILE_NOT_FOUND);
	}
       	else if (!( inxsql_num_fields(xptr) ))
	{
              	inxsql_free_result(xptr);
		return(_ERROR_FILE_NOT_FOUND);
	}
	else
	{
		fptr->datalength = 0;
		INXSQL_ROW row;
		while ((row = inxsql_fetch_row(xptr)))
                {
			int extra=0;
			int length=15;
			int type=_INXS_STRING;
			int primary=0;
			/* --------------------------------- */
			/* detect the primary key definition */
			/* --------------------------------- */
			if (!( strcasecmp( inxsql_fetch_field(xptr,row,3), "pri" ) )) 
				primary = 1;

			/* --------------------------------- */
			/* analyse the field characteristics */
			/* --------------------------------- */
			if ( inxsql_analyse_type( 
				inxsql_fetch_field(xptr,row,0), 
				inxsql_fetch_field(xptr,row,1), 
				&length, &type, &extra ) != _SUCCESS )
			{
              			inxsql_free_result(xptr);
				return( _ERROR_SYNTAX );
			}
			/* --------------------------------- */
			/* handle the primary key definition */
			/* --------------------------------- */
			else if ( primary )
			{
				fptr->primary.size = length;
				fptr->primary.extra = extra;
				switch ((fptr->primary.type  = type))
				{
				case	_INXS_STRING	:
					fptr->align = _INXS_LKEY;
					break;
				case	_INXS_BIN	:
					fptr->align = _INXS_BKEY;
					break;
				default			:
					fptr->align = _INXS_RKEY;
					break;
				};
				if (!(fptr->primary.name = inxsql_allocate_string( inxsql_fetch_field(xptr,row,0) )))
				{
              				inxsql_free_result(xptr);
					return( _ERROR_MEMORY );
				}
			}
			/* -------------------------------- */
			/* handle the record key definition */
			/* -------------------------------- */
			else if (!( cptr = inxsql_add_field( fptr, inxsql_fetch_field(xptr,row,0), length, type, extra)))
			{
              			inxsql_free_result(xptr);
				return( _ERROR_MEMORY );
			}
			/* ------------------------------------ */
			/* adjust the global file record length */
			/* ------------------------------------ */
			else
			{
				fptr->datalength += inxsql_field_size(cptr);
			}
       		}
		/* ---------------------------------------- */
		/* release the results and indicate success */
		/* ---------------------------------------- */
              	inxsql_free_result(xptr);
		return( _SUCCESS );
	}	
}
#endif

/*	-------------------------	*/
/*	inxsql_load_table_indexes	*/
/*	-------------------------	*/
private int inxsql_load_table_indexes( struct xs_connection * xptr, char * query, struct xs_file * fptr )
{
	switch ( fptr->connection->engine )
	{
#ifdef	_INXSQL_MYSQL
	case	_INXSQL_MYSQL_ENGINE	:
		return( inxsql_load_mysql_indexes( xptr, query, fptr ) );
#endif
#ifdef	_INXSQL_PGSQL
	case	_INXSQL_PGSQL_ENGINE	:
		return( inxsql_load_pgsql_indexes( xptr, query, fptr ) );
#endif
	default				:
		return(_ERROR_FILE_NOT_FOUND);
	}
}

/*	-------------------------	*/
/*	inxsql_load_table_columns	*/
/*	-------------------------	*/
private int inxsql_load_table_columns( struct xs_connection * xptr, char * query, struct xs_file * fptr )
{
	switch ( fptr->connection->engine )
	{
#ifdef	_INXSQL_MYSQL
	case	_INXSQL_MYSQL_ENGINE	:
		return( inxsql_load_mysql_columns( xptr, query, fptr ) );
#endif
#ifdef	_INXSQL_PGSQL
	case	_INXSQL_PGSQL_ENGINE	:
		return( inxsql_load_pgsql_columns( xptr, query, fptr ) );
#endif
	default				:
		return(_ERROR_FILE_NOT_FOUND);
	}
}

/*	-------------------		*/
/*	inxsql_rename_table		*/
/*	-------------------		*/
public  int	inxsql_rename_table( struct xs_file * fptr, char * filename )
{
	char 	query[_STD_QUERY_LENGTH];
	int	status;
	if ( verbose ) printf("inxsql_rename_table()\r\n");
	if ((status = inxsql_use_database( fptr->connection, fptr->base )) != _SUCCESS)
		return(status);
	else
	{
		sprintf(query,"RENAME TABLE %s TO ",inxsql_table_name(fptr));
		strcat(query,filename);
		if ( inxsql_query( fptr->connection, query, strlen(query) ) == _SUCCESS)
		{
			/* --------------------- */
			/* replace the file name */
			/* --------------------- */
			char * oldname = fptr->name;
			int lock = fptr->lock;
			(void) inxsql_file_lock(fptr,_INXS_UNLOCKED);
			fptr->name = inxsql_allocate_string(filename);
			(void) inxsql_file_lock(fptr,lock);
			oldname = liberate(oldname);
			return( _SUCCESS );
		}
		else	return( _ERROR_FILE_EXISTS );
	}
}

/*	------------------------	*/
/*	 inxsql_transfer_tables 	*/
/*	------------------------	*/
public	int	inxsql_transfer_tables(struct xs_base * bptr, char * oldbase, char * newbase )
{
	struct	xs_file * fptr;
	char 	query[_STD_QUERY_LENGTH];
	int	status;
	if ( verbose ) printf("inxsql_transfer_tables()\r\n");
	for (	fptr = bptr->first;
		fptr != (struct xs_file *) 0;
		fptr = fptr->next )
	{
		sprintf(query,"RENAME TABLE %s.%s TO %s.%s ", oldbase,fptr->name, newbase,fptr->name);
		if ((status = inxsql_query( fptr->connection, query, strlen(query))) != _SUCCESS)
			return( status );
	}
	return( _SUCCESS );
}

#endif	/* _inxsql_table_c */

