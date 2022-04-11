#ifndef	_inxsql_index_c
#define	_inxsql_index_c

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
/*	This file manages SQL INDEXES for the LINK/CLINK	*/
/*	instructions of ABAL.					*/
/*                                                              */
/*      ------------------------------------------------        */


/*	--------------------	*/
/*	inxsql_allocate_link	*/
/*	--------------------	*/
public  struct xs_link * inxsql_allocate_link(struct xs_field * cptr)
{
	struct xs_link * lptr;
	if (!( lptr = allocate( sizeof( struct xs_link ) ) ))
		return(lptr);
	else
	{
		lptr->previous = (struct xs_link *) 0;
		lptr->next = (struct xs_link *) 0;
		lptr->field = cptr;
		return( lptr );
	}
}

/*	--------------------	*/
/*	inxsql_liberate_link	*/
/*	--------------------	*/
public  struct xs_link * inxsql_liberate_link(struct xs_link * lptr)
{
	if ( lptr )
	{
		if ( lptr->value )
			lptr->value = liberate( lptr->value );
		liberate( lptr );
	}
	return( (struct xs_link *) 0);
}

/*	---------------------	*/
/*	inxsql_liberate_index	*/
/*	---------------------	*/
public  struct xs_index * inxsql_liberate_index(struct xs_index * iptr)
{
	struct	xs_link * lptr;
	if ( iptr )
	{
		/* ------------------------------- */
		/* release the list of linked keys */
		/* ------------------------------- */
		while ((lptr = iptr->first) != (struct xs_link *) 0)
		{
			if (!(iptr->first = lptr->next))
				iptr->last = (struct xs_link *) 0;
			else	lptr->next = (struct xs_link *) 0;
			lptr->previous = (struct xs_link *) 0;
			lptr = inxsql_liberate_link( lptr );
		}
		/* -------------------------- */
		/* disconnect from the parent */
		/* -------------------------- */
		if ( iptr->file )
		{
			if (!( iptr->previous ))
				iptr->file->firstindex = iptr->next;
			else	iptr->previous->next = iptr->next;
			if (!( iptr->next ))
				iptr->file->lastindex = iptr->previous;
			else	iptr->next->previous = iptr->previous;
			iptr->file = (struct xs_file *) 0;
			iptr->previous = iptr->next = (struct xs_index *) 0;
		}
		/* ---------------------------------- */
		/* reset various index control fields */
		/* ---------------------------------- */
		iptr->previous = iptr->next = (struct xs_index *) 0;
		if ( iptr->name )
			iptr->name = liberate( iptr->name );
		iptr->number = 0;
		iptr = liberate( iptr );
	}
	return((struct xs_index *) 0);
}

/*	-------------------	*/
/*	inxsql_index_fields	*/
/*	-------------------	*/
private	int inxsql_index_fields(struct xs_index * iptr)
{
	struct	xs_link * lptr;
	struct	xs_field * cptr;
	int	fields=0;

	if (!( iptr )) return(0);
	for (	lptr=iptr->first;
		lptr != (struct xs_link *) 0;
		lptr = lptr->next)
	{
		if (!(cptr = lptr->field ))
			continue;
		else if (!( cptr->name ))
			continue;
		else	fields++;
	}
	return( fields );
}

/*	-----------------	*/
/*	inxsql_index_name	*/
/*	-----------------	*/
private	struct xs_index * inxsql_index_name(struct xs_index * iptr)
{
	struct	xs_file * fptr;
	struct	xs_link * lptr;
	struct	xs_field * cptr;
	int	fields=0;
	if ( iptr->name != (char *) 0)
		return( iptr );
	else if (!( fptr = iptr->file ))
		return( inxsql_liberate_index( iptr ) );
	else if (!( fptr->name ))
		return( inxsql_liberate_index( iptr ) );
	else if (!( fields = inxsql_index_fields(iptr)))
		return( inxsql_liberate_index( iptr ) );
	else if ( fields == 1 )
	{
		if (!( iptr->name = inxsql_allocate_string( iptr->first->field->name ) ))
			return( inxsql_liberate_index( iptr ) );
		else	return( iptr );
	}
	else if (!( iptr->name = allocate( strlen( fptr->name ) + 64 )))
		return( inxsql_liberate_index( iptr ) );
	else
	{
		sprintf( iptr->name, "%s%u", fptr->name, iptr->number );
		return( iptr );
	}
}

/*	---------------------	*/
/*	inxsql_allocate_index	*/
/*	---------------------	*/
public  struct xs_index * inxsql_allocate_index(struct xs_file * fptr)
{
	struct	xs_index * iptr;
	if (!( iptr = allocate( sizeof( struct xs_index ) ) ))
		return(iptr);
	else
	{
		/* ----------------------------------- */
		/* reset the link and field management */
		/* ----------------------------------- */
		iptr->first = (struct xs_link *) 0;
		iptr->last = (struct xs_link *) 0;
		iptr->primary = (struct xs_field *) 0;
		iptr->lastkey = (char *) 0;
		iptr->state = 0;
		iptr->current = -1;
		iptr->eof = -1;
		iptr->tof = -1;
		/* ---------------------------------- */
		/* if a parent file has been provided */
		/* ---------------------------------- */
		if (( iptr->file = fptr) != (struct xs_file *) 0)
		{
			/* ----------------------------- */
			/* chain it to the parent's list */
			/* ----------------------------- */
			if (!( iptr->previous = fptr->lastindex ))
			{
				iptr->number = 1;
				fptr->firstindex = iptr;
			}
			else
			{
			 	iptr->previous->next = iptr;
				iptr->number = (iptr->previous->number+1);
			}
			fptr->lastindex = iptr;
		
			/* --------------------- */	
			/* create the index name */
			/* --------------------- */	
			return ( iptr );
		}
		else
		{
			/* ---------------------------- */
			/* otherwise free radical index */
			/* ---------------------------- */
			iptr->previous = (struct xs_index *) 0;
			iptr->next = (struct xs_index *) 0;
			iptr->name = (char *) 0;
			iptr->number = 0;
			return(iptr);
		}
	}
}

/*	-------------------------	*/
/*	inxsql_delete_table_index	*/
/*	-------------------------	*/
private	int inxsql_delete_table_index(struct xs_index * iptr)
{
	struct	xs_file  * fptr;
	struct	xs_field * cptr;
	struct	xs_link  * lptr;
	int	status=0;
	int	items=0;
	char *	query=(char *) 0;

	/* ----------------------- */
	/* check well formed index */
	/* ----------------------- */
	if (!( fptr = iptr->file  ))
		return( _ERROR_SYNTAX );
	else if (!( iptr->name ))
		return( _ERROR_SYNTAX );

	/* ------------------------- */
	/* allocate the query buffer */
	/* ------------------------- */
	else if (!( query = allocate( _STD_QUERY_LENGTH + strlen(fptr->name) + strlen( iptr->name ) )))
		return( _ERROR_MEMORY );
	else
	{
		sprintf(query,"DROP INDEX %s ON %s ",iptr->name,inxsql_table_name(fptr));

		/* --------------------------------- */
		/* launch the index creation request */
		/* --------------------------------- */
		if ((status = inxsql_query(fptr->connection, query, strlen(query))) != _SUCCESS)
		{	
			/* ---------------- */
			/* indicate failure */
			/* ---------------- */
			liberate(query);
			return(status);
		}
		else
		{
			/* ---------------- */
			/* indicate success */
			/* ---------------- */
			liberate(query);
			return(_SUCCESS);
		}
	}
}

/*	-------------------------	*/
/*	inxsql_create_table_index	*/
/*	-------------------------	*/
private	int inxsql_create_table_index(struct xs_index * iptr)
{
	struct	xs_file  * fptr;
	struct	xs_field * cptr;
	struct	xs_link  * lptr;
	int	status=0;
	int	length=0;
	int	items=0;
	char *	query=(char *) 0;

	/* ----------------------- */
	/* check well formed index */
	/* ----------------------- */
	if (!( fptr = iptr->file  ))
		return( _ERROR_SYNTAX );
	else if (!( iptr->name ))
		return( _ERROR_SYNTAX );

	/* ------------------------------ */
	/* run the list of linked columns */
	/* ------------------------------ */
	for (	lptr = iptr->first;
		lptr != (struct xs_link *) 0;
		lptr = lptr->next )
	{
		if (!(cptr = lptr->field))
			continue;
		else if (!( cptr->name ))
			continue;
		else	length + (strlen(cptr->name)+1);
	}

	/* ------------------------- */
	/* allocate the query buffer */
	/* ------------------------- */
	if (!( query = allocate( _STD_QUERY_LENGTH + strlen(fptr->name) + strlen( iptr->name ) + length )))
		return( _ERROR_MEMORY );
	else
	{
		sprintf(query,"CREATE INDEX %s ON %s (",iptr->name,inxsql_table_name(fptr));

		/* ------------------------------ */
		/* run the list of linked columns */
		/* ------------------------------ */
		for (	lptr = iptr->first;
			lptr != (struct xs_link *) 0;
			lptr = lptr->next )
		{
			if (!(cptr = lptr->field))
				continue;
			else if (!( cptr->name ))
				continue;
			else
			{
				if ( items++ )
					strcat(query,",");
				strcat(query,cptr->name);
			}
		}
		strcat(query,")");

		/* --------------------------------- */
		/* launch the index creation request */
		/* --------------------------------- */
		if ((status = inxsql_query(fptr->connection, query, strlen(query))) != _SUCCESS)
		{	
			/* ---------------- */
			/* indicate failure */
			/* ---------------- */
			liberate(query);
			return(status);
		}
		else
		{
			/* ---------------- */
			/* indicate success */
			/* ---------------- */
			liberate(query);
			return(_SUCCESS);
		}
	}
}

/*	--------------------------------------- */
/*	     inxsql_descriptor_field_name	*/
/*	--------------------------------------- */
/*	extracts a KEY name from an ABAL buffer	*/
/*	each ABAL KEY name is either 16 bytes 	*/
/*	or 53 bytes long depending on whether	*/
/*	the long keynames option has been set.	*/
/*	ABAL KEY names are right space padded .	*/
/*	--------------------------------------- */
public	int inxsql_descriptor_field_name( char * rptr, int rlen, char * sptr, int slen )
{
	int	i=0;
	int	c=0;

	while ( slen != 0 )
	{
		if ((c = *(sptr+i)) == ' ')
		{
			break;
		}
		else if ( rlen > 0 )
		{
			*(rptr+i) = c;
			rlen--;
			slen--;
		} 
		else
		{
			return(0);
		}
		i++;
	}
	*(rptr+i) = 0;
	return(i);
}

/*	------------------	*/
/*	inxsql_locate_link	*/
/*	------------------	*/
public	struct xs_link * inxsql_locate_link(struct xs_index * iptr, struct xs_field * cptr )
{
	struct	xs_link *	lptr;
	struct	xs_field *	kptr;
	char * nptr;

	/* ----------------------------- */
	/* check the received parameters */
	/* ----------------------------- */
	if (!( iptr ))
		return( (struct xs_link *) 0 );
	else if (!( cptr ))
		return( (struct xs_link *) 0 );
	else if (!( cptr->name ))
		return( (struct xs_link *) 0 );
	/* -------------------------- */
	/* check for duplicate column */
	/* -------------------------- */
	for (	lptr=iptr->first;
		lptr != (struct xs_link *) 0;
		lptr = lptr->next )
	{
		if (!( kptr = lptr->field )) 
			continue;
		else if (!( nptr = kptr->name ))
			continue;
		else if (!( inxsql_field_name_compare( nptr, cptr->name ) ))
			break;
		else	continue;
	}
	return(lptr);
}

/*	------------------	*/
/*	inxsql_unique_link	*/
/*	------------------	*/
public	struct xs_link * inxsql_unique_link(struct xs_index * iptr, struct xs_field * cptr )
{
	struct	xs_link *	lptr;

	if (!( lptr = inxsql_locate_link( iptr, cptr ) ))
		return( inxsql_append_link( iptr, cptr ) );
	else	return( lptr );
}

/*	------------------	*/
/*	inxsql_append_link	*/
/*	------------------	*/
public	struct xs_link * inxsql_append_link(struct xs_index * iptr, struct xs_field * cptr )
{
	struct	xs_link *	lptr;
	/* ----------------------------- */
	/* allocate and add the new link */
	/* ----------------------------- */
	if (!( lptr = inxsql_allocate_link(cptr) ))
		return( lptr );
	else
	{
		if (!( lptr->previous = iptr->last ))
			iptr->first = lptr;
		else	lptr->previous->next = lptr;
		return((iptr->last = lptr));
	}
}

/*	-----------------	*/
/*	inxsql_copy_index	*/
/*	-----------------	*/
public	struct	xs_index *	inxsql_copy_index( struct xs_file * fptr, struct xs_index * iptr )
{
	struct	xs_index * jptr;
	struct	xs_field * cptr;
	struct	xs_link  * lptr;
	struct	xs_link  * mptr;
	if (!( jptr = inxsql_allocate_index( fptr ) ))
		return( jptr );
	else if (!( jptr->name = inxsql_allocate_string( iptr->name ) ))
		return( inxsql_liberate_index( jptr ) );
	else 	
	{
		/* ------------------------------ */
		/* run the list of linked columns */
		/* ------------------------------ */
		for (	lptr = iptr->first;
			lptr != (struct xs_link *) 0;
			lptr = lptr->next )
		{
			if (!( cptr = lptr->field ))
				return( inxsql_liberate_index( jptr ) );
			else if (!( mptr = inxsql_append_link( jptr, cptr ) ))
				return( inxsql_liberate_index( jptr ) );
		}
		return( jptr );
	}
} 

/*	-------------------------	*/
/*	 inxsql_parse_index_list	*/
/*	-------------------------	*/
public	struct xs_index * inxsql_parse_index_list(struct xs_file * fptr, char * dptr, int dlen, int * error )
{
	char	*	vptr;
	char	*	nptr;
	char 		column[2048];
	int		braces=0;
	int		quoted=0;
	int		expression=0;
	int		i=0;
	int		c;
	struct	xs_index * iptr;
	struct 	xs_link * lptr;
	struct 	xs_field * cptr;

	if ((!( dptr )) || (!( dlen )))
		return((struct xs_index *) 0);
	else if (!( vptr = allocate( dlen+1 ) ))
		return((struct xs_index *) 0);
	else
	{
		memcpy(vptr,dptr,dlen);
		*(vptr+dlen) = 0;
		dptr = vptr;	
	}	
	// allocate the index carrier
	if (!( iptr = inxsql_allocate_index((struct xs_file *) 0) ))
	{
		vptr = liberate( vptr );
		*error = _ERROR_MEMORY;
		return((struct xs_index *) 0);
	}
	else
	{
		while ( dlen )
		{
			// step over white space
			while (( dlen ) && ( *dptr == ' ' )) { dptr++; dlen--; }
			if (!( dlen )) break;

			// extract a column name
			i=0;	braces=0;	expression=0;
			while ( dlen )
			{
				c = *(dptr++); dlen--;
				switch ( c ) 
				{
				case	0x0022	:
				case	0x0027	:
					expression=1;
					if ( quoted == c )
						quoted = 0;
					else if (!( quoted ))
						quoted = c;
					column[i++] = c;
					if (!( dlen ))
						break;
					else	continue;
					
				case	')'	:
					if (!( quoted )) if ( braces ) braces--;
				case	'+'	:
				case	'-'	:
				case	'/'	:
				case	'*'	:
					expression=1;
					column[i++] = c;
					if (!( dlen ))
						break;
					else	continue;
	
				case	','	:
				case	' '	:
				case	'\t'	:
					if (!( quoted ))
						if (!( braces ))
							break;
					column[i++] = c;
					if (!( dlen ))
						break;
					else	continue;
				case	'('	:
					braces++;
					expression=1;
				default		:
					column[i++] = c;
					if (!( dlen ))
						break;
					else	continue;
				}
				break;
			}
			column[i++] = 0;

			// check for incorrect expression
			if (( quoted ) || ( braces ))
			{
				vptr = liberate( vptr );
				*error = _ERROR_SYNTAX;
				return( inxsql_liberate_index(iptr) );
			}

			// detect and handle expression
			if ( expression )
			{
				// process an expression to a column
				if (!( cptr = inxsql_expression_field(fptr,column) ))
				{
					vptr = liberate( vptr );
					*error = _ERROR_KEY_NOT_FOUND;
					return( inxsql_liberate_index(iptr) );
				}
				// add the column to the link
				else if (!( lptr = inxsql_append_link(iptr,cptr) ))
				{
					vptr = liberate( vptr );
					*error = _ERROR_MEMORY;
					return( inxsql_liberate_index(iptr) );
				}
			}

			// handle the column and add the link
			else 
			{
				if (!( cptr = inxsql_locate_field(fptr,column) ))
				{
					vptr = liberate( vptr );
					*error = _ERROR_KEY_NOT_FOUND;
					return( inxsql_liberate_index(iptr) );
				}

				// add the column to the link
				else if (!( lptr = inxsql_unique_link(iptr,cptr) ))
				{
					vptr = liberate( vptr );
					*error = _ERROR_MEMORY;
					return( inxsql_liberate_index(iptr) );
				}
			}

			// check for and locate terminator 
			if ( c == ',' )
				continue;
			else
			{
				// step over white space
				while (( dlen ) && ( *dptr == ' ' )) { dptr++; dlen--; }

				// check punctuation
				if (!( dlen )) 
					break;
				else if ( *dptr != ',' )
				{
					vptr = liberate( vptr );
					*error = _ERROR_SYNTAX;
					return( inxsql_liberate_index(iptr) );
				}
				else	
				{	dptr++; dlen--; }
			}
		}
		vptr = liberate( vptr );
		return( iptr );
	}
}

/*	------------------	*/
/*	inxsql_parse_index	*/
/*	------------------	*/
private	struct xs_index * inxsql_parse_index(struct xs_file * fptr, char * dptr, int dlen, int * error )
{
	int	columns=0;
	struct	xs_index * iptr;
	struct	xs_field * cptr;
	struct	xs_link  * lptr;
	char	column[_INXS_KEY_MAX];

	/* ------------------------------ */
	/* collect the index column count */
	/* ------------------------------ */
	if ((!( dptr )) || (!( dlen )))
		return((struct xs_index *) 0);
	else if (!( columns = *(dptr++)))
		return((struct xs_index *) 0);
	else if (!( iptr = inxsql_allocate_index((struct xs_file *) 0) ))
	{
		*error = _ERROR_MEMORY;
		return((struct xs_index *) 0);
	}
	else
	{
		dlen--;

		/* --------------- */
		/* for all columns */
		/* --------------- */
		while ( columns-- )
		{
			/* -------------------------- */
			/* step over long name prefix */
			/* -------------------------- */
			if (!( *dptr )) { dptr++; dlen--; }

			/* ----------------------- */
			/* collect the column name */
			/* ----------------------- */
			if (!( inxsql_descriptor_field_name(column,_INXS_KEY_MAX,dptr,(dlen > fptr->maxkey ? dlen : fptr->maxkey)) ))
			{
				*error = _ERROR_SYNTAX;
				return( inxsql_liberate_index(iptr) );
			}
			else if (!( cptr = inxsql_locate_field(fptr,column) ))
			{
				*error = _ERROR_KEY_NOT_FOUND;
				return( inxsql_liberate_index(iptr) );
			}
			else if (!( lptr = inxsql_append_link(iptr,cptr) ))
			{
				*error = _ERROR_MEMORY;
				return( inxsql_liberate_index(iptr) );
			}
			else
			{
				dptr += fptr->maxkey; 
				dlen -= fptr->maxkey; 
			}
		}
		return( iptr );
	}
}

/*	-------------------------	*/
/*	inxsql_locate_named_index	*/
/*	-------------------------	*/
public struct xs_index * inxsql_locate_named_index(struct xs_file * fptr, char * nptr)
{
	struct	xs_index * jptr;
	for (	jptr = fptr->firstindex; 
		jptr != (struct xs_index *) 0;
		jptr = jptr->next )
	{
		if (!( jptr->name ))
			continue;
		else if (!( inxsql_index_name_compare( jptr->name, nptr ) ))
			break;
	}
	return( jptr );
}

/*	-------------------	*/
/*	inxsql_locate_index	*/
/*	-------------------	*/
private	struct xs_index * inxsql_locate_index(struct xs_file * fptr, struct xs_index * iptr)
{
	struct	xs_index * jptr;

	/* ----------------------------------- */
	/* ensure there is at least one column */
	/* ----------------------------------- */
	if (!( iptr->first ))
		return( inxsql_liberate_index( iptr ) );
	else
	{
		jptr = inxsql_resolve_index( fptr, iptr );

		/* -------------------------- */
		/* release the index template */
		/* -------------------------- */
		iptr = inxsql_liberate_index(iptr);

		return( jptr );
	}
}

/*	--------------------	*/
/*	inxsql_resolve_index	*/
/*	--------------------	*/
public	struct xs_index * inxsql_resolve_index(struct xs_file * fptr, struct xs_index * iptr)
{
	struct	xs_index * jptr;
	struct	xs_link * lptr;
	struct	xs_link * mptr;

	/* ------------------------------------------- */
	/* walk the list of file indexes to find match */
	/* ------------------------------------------- */
	for (	jptr = fptr->firstindex; 
		jptr != (struct xs_index *) 0;
		jptr = jptr->next )
	{
		/* ----------------------------------------------- */
		/* run the lists of links and compare column names */
		/* ----------------------------------------------- */
		for (	lptr = iptr->first, mptr = jptr->first;
			(lptr != (struct xs_link *) 0) && ( mptr != (struct xs_link *) 0);
			lptr = lptr->next, mptr = mptr->next)
		{
			/* ensure both index fields are valid */
			if ((!( lptr->field )) || (!( mptr->field )))
				break;
			/* ensure both index field names are valid */
			else if ((!( lptr->field->name )) || (!( mptr->field->name )))
				break;
			/* check if index field names match */
			else if (!( inxsql_field_name_compare( lptr->field->name, mptr->field->name ) ))
				continue;
			/* not matching */
			else	break;
		}
		/* -------------------------------------- */
		/* if end of both link lists reached : ok */
		/* -------------------------------------- */
		if ((!( lptr )) && (!( mptr )))
			break;
	}

	return( jptr );
}

/*	------------------------	*/
/*	inxsql_resolve_use_index	*/
/*	------------------------	*/
public	struct xs_index * inxsql_resolve_use_index(struct xs_file * fptr, struct xs_index * iptr)
{
	switch ( fptr->connection->engine )
	{
#ifdef	_INXSQL_MYSQL
	case	_INXSQL_MYSQL_ENGINE	:
		return( inxsql_resolve_index( fptr, iptr ) );
#endif
	default				:
		return((struct xs_index * ) 0);
	}
}

/*	---------------------------------	*/
/*		inxsql_create_index		*/
/*	---------------------------------	*/
/*	handles the LINK and CLINK Create	*/
/*	operations as shown by flag value	*/
/*	---------------------------------	*/
public  int inxsql_create_index(struct xs_file * fptr, char * dptr, int dlen, int clink )
{
	struct	xs_index * iptr;
	struct	xs_index * jptr;
	int	status = _SUCCESS;

	/* -------------------------------------- */
	/* ensure the current database is correct */
	/* -------------------------------------- */
	if ((status = inxsql_use_database( fptr->connection, fptr->base )) != _SUCCESS)
		return(status);

	/* ---------------------------------- */
	/* parse descriptor to index template */
	/* ---------------------------------- */
	if (!( iptr = inxsql_parse_index(fptr,dptr,dlen,&status)))
		return( status );

	else if (!( clink ))
	{
		/* ---------------------------------- */
		/* test to see if it is already known */
		/* ---------------------------------- */
		if (!( jptr = inxsql_resolve_index( fptr, iptr ) ))
		{
			/* ----------------------------- */
			/* chain it to the parent's list */
			/* ----------------------------- */
			if (!( iptr->previous = fptr->lastindex ))
			{
				iptr->number = 1;
				fptr->firstindex = iptr;
			}
			else
			{
			 	iptr->previous->next = iptr;
				iptr->number = (iptr->previous->number+1);
			}
			fptr->lastindex = iptr;
			iptr->file = fptr;
			iptr->state = _PENDING_CREATE;
			if (!( iptr = inxsql_index_name( iptr )))
				return( _ERROR_MEMORY );
			else	return( _SUCCESS );	
		}
		else 
		{
			/* ------------------------------------------------- */
			/* if current state is pending delete then cancel it */
			/* ------------------------------------------------- */
			if ( jptr->state == _PENDING_DELETE )
				jptr->state = _SUCCESS;

			/* --------------------------------------- */
			/* release the template and signal success */
			/* --------------------------------------- */
			iptr = inxsql_liberate_index( iptr );

			return( _SUCCESS );
		}
	}
	/* -------------------------------------- */
	/* resolve a file index matching template */
	/* -------------------------------------- */
	else if (!( iptr = inxsql_locate_index( fptr, iptr ) ))
		return( _ERROR_LINK_NOT_FOUND );

	/* -------------------------- */
	/* check if requires creation */
	/* -------------------------- */
	else if ( iptr->state != _PENDING_CREATE)
		return(_SUCCESS);
	else
	{
		/* ---------------------- */
		/* perform index creation */
		/* ---------------------- */
		if ((iptr->state = inxsql_create_table_index(iptr)) != _SUCCESS )
			return(iptr->state);
		else	return(_SUCCESS);
	}
}

/*	---------------------------------	*/
/*		inxsql_drop_index		*/
/*	---------------------------------	*/
/*	handles the LINK and CLINK Delete	*/
/*	operations as shown by flag value	*/
/*	---------------------------------	*/
public  int inxsql_drop_index(struct xs_file * fptr, char * dptr, int dlen, int clink )
{
	struct	xs_index * iptr;
	struct	xs_index * jptr;
	int	status = _SUCCESS;
	/* ---------------------------------- */
	/* parse descriptor to index template */
	/* ---------------------------------- */
	if (!( iptr = inxsql_parse_index(fptr,dptr,dlen, &status)))
		return( status );
	else if ((status = inxsql_use_database( fptr->connection, fptr->base )) != _SUCCESS)
		return(status);
	else if (!( clink ))
	{
		/* ---------------------------------- */
		/* test to see if it is already known */
		/* ---------------------------------- */
		if (!( jptr = inxsql_resolve_index( fptr, iptr ) ))
		{
			/* ----------------------------- */
			/* chain it to the parent's list */
			/* ----------------------------- */
			if (!( iptr->previous = fptr->lastindex ))
			{
				iptr->number = 1;
				fptr->firstindex = iptr;
			}
			else
			{
			 	iptr->previous->next = iptr;
				iptr->number = (iptr->previous->number+1);
			}
			fptr->lastindex = iptr;
			iptr->file = fptr;
			iptr->state = _PENDING_DELETE;
			if (!( iptr = inxsql_index_name( iptr )))
				return( _ERROR_MEMORY );
			else	return( _SUCCESS );	
		}
		else 
		{
			/* --------------------------------------- */
			/* set the current state to pending delete */
			/* --------------------------------------- */
			if ( jptr->state == _PENDING_CREATE )
				/* pending create so forget it */
				jptr = inxsql_liberate_index( jptr );
			else if ( jptr->state == _SUCCESS )
				/* a created index so request delete */
				jptr->state = _PENDING_DELETE;
			else if ( jptr->state != _PENDING_DELETE )
				/* probably and error so forget it */
				jptr = inxsql_liberate_index( jptr );

			/* --------------------------------------- */
			/* release the template and signal success */
			/* --------------------------------------- */
			iptr = inxsql_liberate_index( iptr );

			return( _SUCCESS );
		}
	}
	/* -------------------------------------- */
	/* resolve a file index matching template */
	/* -------------------------------------- */
	else if (!( iptr = inxsql_locate_index( fptr, iptr ) ))
		return( _ERROR_LINK_NOT_FOUND );

	/* -------------------------- */
	/* check if requires deletion */
	/* -------------------------- */
	else if ( iptr->state != _PENDING_DELETE)
		return(_SUCCESS);
	else
	{
		/* ---------------------- */
		/* perform index deletion */
		/* ---------------------- */
		if ((iptr->state = inxsql_delete_table_index(iptr)) != _SUCCESS )
			return(iptr->state);
		else
		{
			iptr = inxsql_liberate_index(iptr);
			return( _SUCCESS );
		}
	}
}

/*	---------------------	*/
/*	inxsql_set_link_value	*/
/*	---------------------	*/
public	int inxsql_set_link_value( struct xs_link * lptr, char * query, int offset, int vlen, int reverse)
{
	switch ( lptr->type )
	{
	case	_INXS_LINK_MIN	:
		return( inxsql_min_field_value( lptr->field, query, offset ) );
	case	_INXS_LINK_MAX	:
		return( inxsql_max_field_value( lptr->field, query, offset ) );
	case	_INXS_LINK_VALUE:
		return( inxsql_set_field_value( lptr->field, query, offset, lptr->value, lptr->field->size, _INXS_NOKEY, 0 ) );
	default			:
		return( offset );
	}
}

/*	---------------------------------	*/
/*		inxsql_update_index		*/
/*	---------------------------------	*/
/*	handles the default CLINK Update	*/
/*	---------------------------------	*/
public  int inxsql_update_indexes(struct xs_file * fptr)
{
	struct	xs_index * iptr;
	int	status=_SUCCESS;

	/* -------------------------------------- */
	/* ensure the current database is correct */
	/* -------------------------------------- */
	if (!( fptr ))
		return( _SUCCESS );
	else if ((status = inxsql_use_database( fptr->connection, fptr->base )) != _SUCCESS)
		return(status);
	else	iptr = fptr->firstindex;

	while ( iptr != (struct xs_index *) 0 )
	{
		switch ( iptr->state )
		{
	
		case	_PENDING_DELETE :
			if ((iptr->state = inxsql_delete_table_index(iptr)) != _SUCCESS )
			{
				iptr = iptr->next;
				continue;
			}
			else
			{
				iptr = inxsql_liberate_index(iptr);
				iptr = fptr->firstindex;
				continue;
			}		
		
		case	_PENDING_CREATE :
			if ((iptr->state = inxsql_create_table_index(iptr)) != _SUCCESS )
				return(iptr->state);
		default			:
			iptr = iptr->next;
			continue;
		}
	}
	return( _SUCCESS );
}

/*	-------------------	*/
/*	inxsql_list_indexes	*/
/*	-------------------	*/
public	int inxsql_list_indexes(struct xs_file * fptr, char * dptr, int dlen, int mode )
{
        char *  vptr;
        char *  sptr;
        int     vlen;
	struct	xs_index * iptr;
	struct	xs_link  * lptr;
	struct	xs_field * cptr;

        /* ---------------------------- */
        /* determine first or next mode */
        /* ---------------------------- */
        switch ( mode )
        {
        case    0       : /* FIRST      */
                if (!( fptr->currentindex = fptr->firstindex ))
                        return(_ERROR_END_OF_FILE);
                else    break;
        case    1       : /* NEXT       */
                if (!( fptr->currentindex ))
                        return(_ERROR_END_OF_FILE);
                else if (!( fptr->currentindex = fptr->currentindex->next ))
                        return(_ERROR_END_OF_FILE);
                else    break;
        }

        /* --------------------------------- */
        /* generate the resulting databuffer */
        /* --------------------------------- */
	if (!( iptr = fptr->currentindex))
		return( _ERROR_END_OF_FILE );
	else if ( dlen < 2 )
		inxsql_buffer_too_small(fptr);
	else	memset(dptr,' ',dlen);

	/* ------------------- */
	/* set the index state */
	/* ------------------- */
	switch ( iptr->state )
	{
	case	_PENDING_CREATE	:
		dptr[0] = 24;
		break;
	case	_PENDING_DELETE	:
		dptr[0] = 26;
		break;
	default			:
		dptr[0] = 20;
	}

	/* -------------------------- */
	/* set the index column count */
	/* -------------------------- */
	dptr[1] = ( inxsql_index_fields( iptr ) & 0x00FF);	

	dptr += 2; dlen -= 2;

	/* ------------------ */
	/* copy the key names */
	/* ------------------ */
	for (	lptr = iptr->first;
		lptr != (struct xs_link *) 0;
		lptr = lptr->next )
	{
		if (!( dlen ))
			inxsql_buffer_too_small(fptr);
		else if (!( cptr = lptr->field ))
			continue;
		else if (!( sptr = cptr->name ))
			continue;
		else
		{
			for ( vlen = 0; vlen < (dlen > fptr->maxkey ? fptr->maxkey : dlen); vlen++ )
				if (*sptr != 0) 
					dptr[vlen] = *(sptr++);
			dptr += vlen;
			dlen -= vlen;
		}
	}

	return( _SUCCESS );
}

#endif	/* _inxsql_index_c */

