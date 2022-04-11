#ifndef	_inxsql_query_c
#define	_inxsql_query_c

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

/*	-------------------------------------------------------------------------------------------------	*/
/*	S T A N D A R D   Q U E R Y   L A N G U A G E    S T A T E M E N T    Q U E R Y    D E L I V E R	*/
/*	-------------------------------------------------------------------------------------------------	*/

private	int     inxsql_where_clause_old( struct xs_file * fptr, char * query, int offset, char * dptr, int dlen );
private	int     inxsql_where_clause_new( struct xs_file * fptr, char * query, int offset, char * dptr, int dlen );

/*	----------------------	*/
/*	inxsql_failure_message	*/
/*	----------------------	*/
private	void	inxsql_failure_message(FILE * h, struct xs_connection * xptr, char * message )
{
	switch ( xptr->engine )
	{
#ifdef	_INXSQL_MYSQL
	case	_INXSQL_MYSQL_ENGINE	:
		fprintf(h,"inxsql_query_failure(MYSQL,caller=%s,errno=%u,message=%s)\n",
			message,
			mysql_errno(xptr->handle),
			mysql_error(xptr->handle));
		break;
#endif
#ifdef	_INXSQL_PGSQL
	case	_INXSQL_PGSQL_ENGINE	:
		fprintf(h,"inxsql_query_failure(PGSQL,caller=%s,errno=%u,message=%s)\n",
			message,
			PQresultStatus(xptr->result),
			PQresultErrorMessage(xptr->result));
		break;
#endif
	default				:
		fprintf(h,"inxsql_query_failure(UNKNOWN,caller=%s,errno=%u,message=%s)\n",
			message,
			errno,
			"unknown engine");
	}
	return;
}

#ifndef	inxsql_fetch_field
/*	------------------	*/
/*	inxsql_fetch_field	*/
/*	------------------	*/
public	char *	inxsql_fetch_field(struct xs_connection * xptr, void * rptr, int f)
{
	switch ( xptr->engine )
	{
#ifdef	_INXSQL_MYSQL	
	case	_INXSQL_MYSQL_ENGINE	:
		MYSQL_ROW * row = (MYSQL_ROW) rptr;
		return( row[f] );
#endif
#ifdef	_INXSQL_PGSQL	
	case	_INXSQL_PGSQL_ENGINE	:
		return( PQgetvalue( xptr->result, (xptr->row-1), f ));
#endif
	default				:
		return((char *) 0);
	}
}
#endif

/*	----------------	*/
/*	inxsql_fetch_row	*/
/*	----------------	*/
public	void *	inxsql_fetch_row(struct xs_connection * xptr)
{
	void	* rptr=(void *) 0;
	switch ( xptr->engine )
	{
#ifdef	_INXSQL_MYSQL	
	case	_INXSQL_MYSQL_ENGINE	:
		rptr = mysql_fetch_row(xptr->result);
		break;
#endif
#ifdef	_INXSQL_PGSQL	
	case	_INXSQL_PGSQL_ENGINE	:
		if ( xptr->row >= inxsql_num_rows(xptr))
			return((void *) 0);
		else
		{
			xptr->row++;
			rptr = xptr->result;	
			if ( xptr->sizes ) 
				xptr->sizes = liberate( xptr->sizes );
		}
#endif

	}
	return( rptr );
}

/*	-----------------	*/
/*	 inxsql_num_rows	*/
/*	-----------------	*/
public	int	inxsql_num_rows(struct xs_connection * xptr)
{
	switch ( xptr->engine )
	{
#ifdef	_INXSQL_MYSQL
	case	_INXSQL_MYSQL_ENGINE	:
		return( mysql_num_rows( xptr->result ) );
#endif
#ifdef	_INXSQL_PGSQL	
	case	_INXSQL_PGSQL_ENGINE	:
		return( PQntuples(xptr->result) );
#endif
	default				:
		return(0);
	}
}

/*	-----------------	*/
/*	inxsql_num_fields	*/
/*	-----------------	*/
public	int	inxsql_num_fields(struct xs_connection * xptr)
{
	switch ( xptr->engine )
	{
#ifdef	_INXSQL_MYSQL
	case	_INXSQL_MYSQL_ENGINE	:
                return((xptr->fields = mysql_num_fields(xptr->result)));
#endif
#ifdef	_INXSQL_PGSQL	
	case	_INXSQL_PGSQL_ENGINE	:
		return( PQnfields(xptr->result) );
#endif
	default				:
		return(0);
	}
}

/*	--------------------	*/
/*	inxsql_fetch_lengths	*/
/*	--------------------	*/
public	unsigned long *	inxsql_fetch_lengths(struct xs_connection * xptr)
{
	switch ( xptr->engine )
	{
#ifdef	_INXSQL_MYSQL	
	case	_INXSQL_MYSQL_ENGINE	:
		return( mysql_fetch_lengths(xptr->result) );
#endif
#ifdef	_INXSQL_PGSQL	
	case	_INXSQL_PGSQL_ENGINE	:
	{
		int n=0;
		if ( xptr->sizes ) 
			return( xptr->sizes );
		else if (!( xptr->result ))
			return( xptr->sizes );
		else if (!( n = inxsql_num_fields( xptr ) ))
			return( xptr->sizes );
		else if (!( xptr->sizes = allocate( sizeof( unsigned long ) * n ) ))
			return( xptr->sizes );
		else
		{
			for ( int f=0; f < n; f++ )
				xptr->sizes[f] = PQgetlength(xptr->result, (xptr->row-1), f);
			return( xptr->sizes );
		}
	}
#endif
	default				:
		return((unsigned long *) 0);
	}
}

/*	-------------------	*/
/*	inxsql_store_result	*/
/*	-------------------	*/
public	void *	inxsql_store_result(struct xs_connection * xptr)
{
	switch ( xptr->engine )
	{
#ifdef	_INXSQL_MYSQL
	case	_INXSQL_MYSQL_ENGINE	:
        	return((void *)(xptr->result = mysql_store_result(xptr->handle)));
#endif
#ifdef	_INXSQL_PGSQL	
	case	_INXSQL_PGSQL_ENGINE	:
		xptr->row = 0;
		return((void *) xptr->result);
#endif
	default			:
		return((void *) 0);
	}
}

/*	------------------	*/
/*	inxsql_free_result	*/
/*	------------------	*/
public	void inxsql_free_result(struct xs_connection * xptr)
{
	switch ( xptr->engine )
	{
#ifdef	_INXSQL_MYSQL
	case	_INXSQL_MYSQL_ENGINE	:
		if ( xptr->result )
			mysql_free_result(xptr->result);
		break;
#endif
#ifdef	_INXSQL_PGSQL	
	case	_INXSQL_PGSQL_ENGINE	:
		if ( xptr->sizes ) 
			xptr->sizes = liberate( xptr->sizes );
		if ( xptr->result )
			PQclear( xptr->result );
		break;
#endif
	}
	xptr->result = (void *) 0;
	return;
}

/*      ----------------------------    */
/*      inxsql_log_statement_failure    */
/*      ----------------------------    */
private void    inxsql_log_query_failure(struct xs_connection * xptr, char * message)
{
        char *  eptr;
        switch (inxsql_boolean("INXSQLERROR",0)) 
	{
	case	1:
		inxsql_failure_message(stdout,xptr,message);
		break;
	case	2:
		inxsql_failure_message(stderr,xptr,message);
	}
        return;
}

/*	----------------	*/
/*	inxsql_raw_trace	*/
/*	----------------	*/
private	void	inxsql_raw_trace( FILE * h, char * query, int length )
{
	int	c;
	int	i;
	fprintf(h,"INXSQLRAW: ");
	for (	i=0; i < length; i++ )
	{
		if ((c = *(query+i)) == '\\')
			continue;
		else if (!( c ))
			break;
		else if ( c < ' ' )
		{
			fprintf(h,"'0x%02X'",c);
		}
		else
		{
			fprintf(h,"%c",c);
		}
	}
	fprintf(h,"\n");
	return;
}

/*	----------------------------------------	*/
/*	  	i n x s q l _ q u e r y 		*/
/*	----------------------------------------	*/
/*	sends all SQL queries to the operational	*/
/*	database engine for processing.			*/
/*	----------------------------------------	*/
public	int	inxsql_query( struct xs_connection * xptr, char * query, int length)
{
	int	status;
	char *	eptr=(char *) 0;

	if (!( xptr ))
		return( _ERROR_CONNECTION );

	switch ( inxsql_boolean("INXSQLRAW", 0) )
	{
	case	1:
		inxsql_raw_trace(stdout,query,length);
		break;
	case	2:
		inxsql_raw_trace(stderr,query,length);
	}

	/* ------------------------ */
	/* ensure signals protected */
	/* ------------------------ */
	inxsql_signal_protection();

	/*	----------------------------	*/
	/*	handle engine specific query 	*/
	/*	----------------------------	*/
	switch ( xptr->engine )
	{
#ifdef	_INXSQL_MYSQL
	case	_INXSQL_MYSQL_ENGINE	:
		if ((status = mysql_ping(xptr->handle)) != 0)
		{
			inxsql_log_query_failure(xptr,"ping");
        	        return( _ERROR_MYSQL_PING );
		}
		if ((status = mysql_real_query(xptr->handle, query, length)) != 0)
		{
			inxsql_log_query_failure(xptr,"query");
			return( _ERROR_MYSQL_QUERY );
		}
		else	return( _SUCCESS );
#endif
#ifdef	_INXSQL_PGSQL
	case	_INXSQL_PGSQL_ENGINE	:
		if (!( xptr->result = PQexec( xptr->handle, query )))
		{
			inxsql_log_query_failure(xptr,"query");
			return( _ERROR_MYSQL_QUERY );
		}
                else
		{
			switch ( PQresultStatus( xptr->result ) )
			{
			case	PGRES_FATAL_ERROR :
				inxsql_log_query_failure(xptr,"query:fatal");
				return( _ERROR_MYSQL_QUERY );

			case	PGRES_COMMAND_OK :
			case	PGRES_TUPLES_OK :
			case	PGRES_COPY_OUT  :
			case	PGRES_COPY_IN	:
				return( _SUCCESS );

			case	PGRES_BAD_RESPONSE :
				inxsql_log_query_failure(xptr,"query:bad");
				return( _ERROR_MYSQL_QUERY );

			case	PGRES_NONFATAL_ERROR :
				inxsql_log_query_failure(xptr,"query:nonfatal");
				return( _ERROR_MYSQL_QUERY );
			}
		}
#endif
	default				:
		inxsql_log_query_failure(xptr,"query");
		return( _ERROR_MYSQL_QUERY );
	}
}

/*      ---------------------   */
/*      inxsql_standard_query   */
/*      ---------------------   */
public	int inxsql_standard_query(struct xs_connection * xptr, char * query, int length, int failure )
{
        /* ----------------- */
        /* process the query */
        /* ----------------- */
        if ( inxsql_query( xptr, query, length ) != _SUCCESS)
                return(failure);
        /* ------------------ */
        /* check for a result */
        /* ------------------ */
        else if (!( xptr->result = inxsql_store_result(xptr) ))
                return(failure);
        /* ---------------------- */
        /* detect an empty result */
        /* ---------------------- */
        else if (!( inxsql_num_fields(xptr) ))
        {
                inxsql_free_result(xptr);
                xptr->result = (void *) 0;
                return(failure);
        }
        /* -- */
        /* OK */
        /* -- */
        else
        {
                inxsql_free_result(xptr);
                xptr->result = (void *) 0;
                return(_SUCCESS);
        }
}

/*	-------------------------------------------------------------------------------------------------	*/
/*	   M U L T I C R I T E R E   A C C E S S   M E T H O D    M O N O F I L E   O P E R A T I O N		*/
/*	-------------------------------------------------------------------------------------------------	*/


/*	-----------------------------	*/
/*	   inxsql_prepare_failure	*/
/*	-----------------------------	*/
/*	provides a centalised failure	*/
/*	point for the criteria buffer	*/
/*	to SQL expression conversion.	*/
/*	-----------------------------	*/
private	int	inxsql_failure(char * message)
{
#define	INXSQL_DEBUG
#ifdef	INXSQL_DEBUG
	if ( verbose )
	{
		printf("\r\nINXSQL: PREPARE FAILURE\r\n%s\r\n",message);
	}
#endif
	return(0);
}

/*	-----------------	*/
/*	inxsql_wild_value	*/
/*	-----------------	*/
private	int	inxsql_wild_value(char * dptr, int dlen, int wild)
{
	if ((!( dptr )) || (!( dlen )))
		return(0);
	for (	; dlen != 0; dlen-- )
		if ( *(dptr++) == (wild & 0x00FF) )
			return(1);
	return(0);
}

/*	------------------------	*/
/*	 inxsql_convert_compare		*/
/*	------------------------	*/
private	char *	inxsql_convert_compare( int operator, char * dptr, int dlen, int wild )
{
	switch ( operator )
	{
	case	_POSIT_EQ	: 
		if ( inxsql_wild_value( dptr, dlen, wild ) )
			return(" Like ");
		else	return(" = ");
	case	_POSIT_NE	: 
		if ( inxsql_wild_value( dptr, dlen, wild ) )
			return(" Not Like ");
		else	return(" <> ");
	case	_POSIT_GT	: return(" > ");
	case	_POSIT_GE	: return(" >= ");
	case	_POSIT_LT	: return(" < ");
	case	_POSIT_LE	: return(" <= ");
	case	_POSIT_BTF	: return(" Between ");
	case	_POSIT_BTL	: return(" And ");
#ifdef	INXSQL_DEBUG
	default			: return(" = ");
#else
	default			: return((char *) 0);
#endif
	}
}

/*	-----------------------------------	*/
/*	i n x s q l _ c l a u s e _ t y p e	*/
/*	-----------------------------------	*/

private	int	inxsql_clause_type( int klen, char ** dptr, int * dlen )
{
	char	name[256];
	int	i;
	char *	wptr;
	int	wlen;

	if (!( wptr = *dptr ))
		return(0);
	else if (!( wlen = *dlen ))
		return(0);
	else if ( *(wptr++) > 1 )
		return(0);
	else
	{
		// step over the long name prefix
		if (!( *wptr )) wptr++;

		// collect the field name 
		for ( i=0; i < klen; i++ ) if (( name[i] = wptr[i]) == ' ') name[i] = 0; 

		// check for valid field name
		if ( strlen( name ) > 0 )
			return(0);

		// invalid field name is new description
		wptr += klen; wlen -= klen; 
	
		// step over the rubbish to the length	
		wptr += 4; wlen -= 4;

		// retrieve descriptor length
		wlen = ((( wptr[0] & 0x00FF ) << 8 ) | ( wptr[1] & 0x00FF)); 

		// consume the length
		wptr += 2; wlen -= 2;

		// store descriptor pointer and length
		*dptr = wptr; *dlen = wlen;

		return(1);
	}
}

/*	-----------------------------------------	*/
/*	  i n x s q l _ w h e r e _ c l a u s e 	*/
/*	-----------------------------------------	*/
/*	produces an SQL select expression from a	*/
/*	criteria like selection descriptor.		*/
/*	Returns the offset into the SELECT buffer	*/
/*	with ZERO indicating failure in case of		*/
/*	any conversion problems encountered.		*/
/*	-----------------------------------------	*/

private	int	inxsql_where_clause( struct xs_file * fptr, char * query, int offset, char * dptr, int dlen )
{
	if (!( inxsql_clause_type( fptr->maxkey, &dptr, &dlen ) ))
		return( inxsql_where_clause_old(fptr, query, offset, dptr, dlen ) );
	else	return( inxsql_where_clause_new(fptr, query, offset, dptr, dlen ) );
}

/*	---------------------------------------------	*/
/*	i n x s q l _ w h e r e _ c l a u s e _ n e w	*/
/*	---------------------------------------------	*/
private	int     inxsql_where_clause_new( struct xs_file * fptr, char * query, int offset, char * dptr, int dlen )
{
	int	braces=0;
	int	type=0;
	int	clause=0;
	int	clen=0;
	int	klen=0;
	int	rlen=0;
	int	i;
	int	size;
	int	flen=0;
	int	vlen=0;
	int	orderby=0;
	int	items=0;
	char *	compare="=";
	int	operator=-1;
	char * 	logical=(char*) " WHERE ";
	char	name[256];
	unsigned char * cptr;
	struct	xs_field * kptr;
	struct	xs_link * lptr;
	char	message[1024];

	klen = fptr->maxkey;

	if (!( clause = *(dptr++) ))
		return(inxsql_failure("incorrect clause"));
	else	dlen--;

	// scan the remaining descriptor for clauses
	while ( dlen > 0 )
	{
		// ---------------------------------------
		// retrieve the clause type
		// BIT 0 : 1 = WHERE, 0 = ORDER BY ALONE
		// BIT 1 : 0 = NO ORDER BY, 1 = ORDER BY
		// ---------------------------------------
		if ( clause & 1 )
		{
			if (!( offset = inxsql_append_query( query, offset, " WHERE ")))
				return(inxsql_failure("query where append"));
			else	
			{
				orderby = 0;
				clause &= ~1;
			}
		}
		else if ( clause & 2 )
		{
			if (!( offset = inxsql_append_query( query, offset, " ORDER BY ")))
				return(inxsql_failure("query where append"));
			else	
			{
				orderby=1;
				clause &= ~2;
			}
		}
		else	break;

		// retrieve clause descriptor length
		if (!( clen = ((( dptr[0] & 0x00FF ) << 8 ) | ( dptr[1] & 0x00FF)) ))
			break;
		else
		{
			// step over length of clause
			cptr = (dptr+2);

			// step over clause
			dptr += clen; 
			dlen -= clen;

			// consume the length
			clen -= 2;

			// consume the zero column count
			if ( orderby )
			{
				items=0;
				cptr++;
				clen--;
			}

			while ( clen > 0 )
			{
				type = *(cptr++); clen--;
				switch ( type )
				{
				case	0	:	// column item

					// validate remaining data 
					if ( clen < (klen+2) ) 
						return(inxsql_failure("not enough data for column name"));

					// collect the field name 
					for ( i=0; i < klen; i++ ) if (( name[i] = cptr[i]) == ' ') name[i] = 0; 
				
					// consume the field name 
					cptr += klen; clen -= klen;

					// resolve the column element
					if ( operator == -1 )
					{
						if (!( kptr = inxsql_locate_field( fptr, name ) ))
						{
							sprintf(message,"query missing column name : [%s]",name);
							return(inxsql_failure(message));
						}
						else if (!( orderby ))
						{
							if (( fptr->selection ) && (!( lptr = inxsql_unique_link( fptr->selection, kptr ) )))
							{
								sprintf(message,"append index column failure : [%s]",name);
								return(inxsql_failure(message));
							}
						}
						else
						{
							if (!( fptr->orderby ))
							{
								if (!( fptr->orderby = inxsql_allocate_index((struct xs_file *) 0) ))
								{
									sprintf(message,"append order by column failure : [%s]",name);
									return(inxsql_failure(message));
								}
							}
							if (!( lptr = inxsql_unique_link( fptr->orderby, kptr ) ))
							{
								sprintf(message,"append order by column failure : [%s]",name);
								return(inxsql_failure(message));
							}
						}
					}

					// order by items need comma separator
					if ( orderby )
						if ( items++ )
							if (!( offset = inxsql_append_query( query, offset, "," )))
								return(inxsql_failure("query comma append"));

					if ( operator != -1 )
					{
						// operator is incremented from BETWEEN 1E to AND 1F
						if (!( compare = inxsql_convert_compare( operator++, cptr, size, '*') ))
							return(inxsql_failure("query unexpected compare operator"));
						else if (!( offset = inxsql_append_query( query, offset, compare )))
							return(inxsql_failure("query operator append"));
						else if ( operator != _POSIT_BTL )
							operator = -1;
					}

					// and add to query
					if (!( offset = inxsql_append_query( query, offset, name )))
						return(inxsql_failure("query column name append"));
					else if (!( offset = inxsql_append_query( query, offset, " " )))
						return(inxsql_failure("query column name append"));

					// the column type
					type = *(cptr++); clen--;

					// the column size
					size = (((*cptr & 0x00FF) << 8) | (*(cptr+1) & 0x00F));
					cptr += 2; clen -= 2;

					continue;

				case	6	:	// table name prefix

					// validate remaining data 
					if ( clen < (klen+2) ) 
						return(inxsql_failure("not enough data for table name prefix"));

					// collect the field name 
					for ( i=0; i < klen; i++ ) if (( name[i] = cptr[i]) == ' ') name[i] = 0; 
				
					// consume the field name 
					cptr += klen; clen -= klen; 

					if (!( offset = inxsql_append_query( query, offset, name )))
						return(inxsql_failure("query column name append"));
					else if (!( offset = inxsql_append_query( query, offset, "." )))
						return(inxsql_failure("query column name append"));

					continue;
	
				case	4	:	// open brace

					if (!( offset = inxsql_append_query( query, offset, "(" )))
						return(inxsql_failure("query left bracket append"));
					else	braces++;
					continue;

				case	8	:	// close brace

					if (!( braces ))
						return(inxsql_failure("unexpected query right bracket"));
					else if (!( offset = inxsql_append_query( query, offset, ")" )))
						return(inxsql_failure("query right bracket append"));
					else 	braces--;
					continue;

				case	2	:	// value

					// the value size
					size = (((*cptr & 0x00FF) << 8) | (*(cptr+1) & 0x00F));
					cptr += 2; clen -= 2;

					// control the value and column length
					if (!( rlen = inxsql_field_size( kptr )))
					{
						sprintf(message,"query incorrect column size : [%s]",kptr->name);
						return(inxsql_failure(message));
					}
					// operator is incremented from BETWEEN 1E to AND 1F
					else if (!( compare = inxsql_convert_compare( operator++, cptr, size, '*') ))
						return(inxsql_failure("query unexpected compare operator"));
					else if (!( offset = inxsql_append_query( query, offset, compare )))
						return(inxsql_failure("query operator append"));
					// transfer the expression value
					else if (!( offset = inxsql_set_field_value( kptr, query, offset, cptr, size, _INXS_NOKEY, 1 ) ))
						return(inxsql_failure("query column value append"));
					else if ( operator != _POSIT_BTL )
						operator = -1;

					cptr += size; clen -= size; 
					continue;

				case	1	:	// operator

					// the operator type
					type = *(cptr++); clen--;

					if ( type )
					{
						// boolean operator
						switch ((type = *(cptr++)))
						{
						case	1 :
							if (!( offset = inxsql_append_query( query, offset, " And " )))
                                        			return(inxsql_failure("query and operator append"));
							else	break;
						case	2 :
							if (!( offset = inxsql_append_query( query, offset, " Or " )))
                                        			return(inxsql_failure("query or operator append"));
							else	break;
						}
						clen--;
					}	
					else
					{
						// compare operator
						operator = *(cptr++);
						clen--;
					}
					continue;
				}
			}
			while ( braces )
			{
				if (!( offset = inxsql_append_query( query, offset, ")" )))
					return(inxsql_failure("query right bracket append"));
				else	braces--;
			}

		}
	}
	// terminate and return
	query[offset] = 0; return( offset );
}

/*	---------------------------------------------	*/
/*	i n x s q l _ w h e r e _ c l a u s e _ o l d	*/
/*	---------------------------------------------	*/
private	int     inxsql_where_clause_old( struct xs_file * fptr, char * query, int offset, char * dptr, int dlen )
{
	int	clauses=0;
	char	name[256];
	char *	compare="=";
	int	i;
	int	klen=_ABAL_KEY_MAX_STD;
	int	flen=0;
	int	vlen=0;
	int	operator=0;
	char * 	logical=(char*) " WHERE ";
	struct	xs_field * cptr;
	struct	xs_link * lptr;
	char	message[1024];
	klen = fptr->maxkey;

	/* ------------------------------------ */
	/* detect an empty selection expression */
	/* ------------------------------------ */
	if (!(  clauses = *(dptr++) ))
		return( offset );
	else	dlen--;

	/* -------------------------------------------*/
	/* for all the clauses in the query descriptor */
	/* -------------------------------------------*/
	while ( clauses-- )
	{
                       
		/* -------------------------- */
                /* step over long name prefix */
                /* -------------------------- */
                if (!( *dptr )) { dptr++; dlen--; }

		/* ----------------------- */
		/* validate remaining data */
		/* ----------------------- */
		if ( dlen < (klen+2) ) 
			return(inxsql_failure("not enough data for clauses"));

		/* ---------------------- */
		/* collect the field name */
		/* ---------------------- */
		for ( i=0; i < klen; i++ ) if (( name[i] = dptr[i]) == ' ') name[i] = 0; 

		/* ---------------------------------------- */
		/* consume the field name and operator code */
		/* ---------------------------------------- */
		dptr += klen; dlen -= klen; operator = ( *(dptr++) & 0x00FF ); dlen--;

		/* ------------------------------------ */
		/* collect and consume the value length */
		/* ------------------------------------ */
		if (!( vlen = *(dptr++)))
			return(inxsql_failure("query column value length"));
		else	dlen--;

		/* ------------------------------------- */
		/* output the relevent statement keyword */
		/* ------------------------------------- */
		if (!( offset = inxsql_append_query( query, offset, logical  )))
			return(inxsql_failure("query syntax append"));
		else	logical = " AND ";

		/* --------------------------------- */
		/* validate the column name and size */
		/* --------------------------------- */
		if (!( cptr = inxsql_locate_field( fptr, name ) ))
		{
			sprintf(message,"query missing column name : [%s]",name);
			return(inxsql_failure(message));
		}
		// addpend this column to the required index
		else if (( fptr->selection ) && (!( lptr = inxsql_unique_link( fptr->selection , cptr ) )))
		{
			sprintf(message,"append index column failure : [%s]",name);
			return(inxsql_failure(message));
		}

		if (!( flen = inxsql_field_size( cptr )))
		{
			sprintf(message,"query incorrect column size : [%s]",name);
			return(inxsql_failure(message));
		}

		else if ( vlen != flen )
			return(inxsql_failure("query unmatched column value size"));

		else if ( flen > dlen )
			return(inxsql_failure("query not enough column data"));

		else if (!( offset = inxsql_append_query( query, offset, cptr->name )))
			return(inxsql_failure("query column name append"));

		/* --------------------------------------- */
		/* convert and output the compare operator */
		/* --------------------------------------- */
		else if (!( compare = inxsql_convert_compare( operator, dptr, flen, '*' ) ))
			return(inxsql_failure("query unexpected compare operator"));

		else if (!( offset = inxsql_append_query( query, offset, compare )))
			return(inxsql_failure("query operator append"));

		/* ------------------------ */
		/* generate the field value */
		/* ------------------------ */
		else if (!( offset = inxsql_set_field_value( cptr, query, offset, dptr, flen, _INXS_NOKEY, 1 ) ))
			return(inxsql_failure("query column value append"));
		else	
		{
			dlen -= flen;
			dptr += flen;
		}
	}

	/* ------------------------------- */
	/* return the end of select offset */
	/* ------------------------------- */
	query[offset] = 0; return( offset );
} 

/*	-------------------------	*/
/*	inxsql_count_file_records	*/
/*	-------------------------	*/
public	int	inxsql_count_file_records( struct xs_file * fptr, char * dptr, int dlen, int uni, int seq, int * response )
{
        char *  query=(char *) 0;
        char *  where=(char *) 0;
	int	items=0;
	int	records=0;
	int	status=0;
	int	offset=0;
        struct  xs_field * cptr;
        struct  xs_connection * xptr;
	struct	xs_link * lptr;

        if ( verbose ) printf("inxsql_count_records()\r\n");

	/* -------------------------------- */
	/* validate the received parameters */
	/* -------------------------------- */
	if (!( xptr = fptr->connection ))
                return(_ERROR_CONNECTION);
	else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
		return( status );
	else if ((status = inxsql_commit_transaction( xptr ) ))
		return( status );
	else if ( inxsql_drop_file_view( fptr ) != _SUCCESS )
                return(_ERROR_CONNECTION);
        else if (!( query = allocate( _STD_QUERY_LENGTH + dlen + strlen(fptr->name) ) ))
                return(_ERROR_MEMORY);
        else if (!( where = allocate( _STD_QUERY_LENGTH + dlen + strlen(fptr->name) ) ))
                return(_ERROR_MEMORY);
	// allocate an index carrier
	else if (!(fptr->selection = inxsql_allocate_index((struct inxsql_index *) 0)))
	{
		query = liberate( query );
		where = liberate( where );
                return(_ERROR_MEMORY);
	}
        else
        {
		// prepare the WHERE clause first to collect colums
		if (!( offset = inxsql_where_clause( fptr, where, 0 , dptr, dlen )))
		{
			liberate( query );
			return( _ERROR_SYNTAX );
		}
		*(where+ offset) = 0;

                // prepare the SELECT statement 
		strcpy(query,"SELECT COUNT(");
		if (!( uni ))
                	strcat(query,"*");
		else if (!( fptr->selection ))
                	strcat(query,"*");
		else if (!( fptr->selection->first ))
                	strcat(query,"*");
		else
		{
			for (	items=0,lptr=fptr->selection->first;
				lptr != (struct xs_link *) 0;
				lptr = lptr->next)
			{
				if (!( cptr = lptr->field ))
					continue;
				else if (!( cptr->name ))
					continue;
				else 
				{
					if (items++)
						strcat(query,",");
					else	strcat(query,"DISTINCT ");
					strcat(query,cptr->name);
				}
			}
			if (!( items ))
                		strcat(query,"*");
		}
		strcat(strcat(strcat(query,") FROM "),inxsql_table_name(fptr))," AS result ");
		strcat(query,where);
		liberate( where );

                // process the SELECT statement
		if ((status = inxsql_query( xptr, query, strlen(query) )) != _SUCCESS)
		{
			liberate( query );
			return( status );
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
                        xptr->result = (void *) 0;
                }
                else
                {
                        /* ------------------ */
                        /* process the result */
                        /* ------------------ */
                        INXSQL_ROW row;
                        /* --------------------------------- */
                        /* for all rows (should only be one) */
                        /* --------------------------------- */
                        while ((row = inxsql_fetch_row(xptr)))
                        {
				records = atoi( inxsql_fetch_field(xptr,row,0) );
				break;
			}
                	inxsql_free_result(xptr);
                        xptr->result = (void *) 0;
		}

		/* ----------------------- */
		/* return the record count */
		/* ----------------------- */
		if ( response ) *response = records;
		liberate( query );
		return( _SUCCESS );	
	}
}

/*	------------------------	*/
/*	 inxsql_liberate_storage 	*/
/*	------------------------	*/
public	int	inxsql_liberate_storage(struct xs_file * fptr)
{
	if (!( fptr ))
		return( _ERROR_CONNECTION );

	else
	{
		if ( fptr->storage )
			fptr->storage = liberate( fptr->storage );

		fptr->storagelength =
		fptr->storageoffset = 0;

		return( _SUCCESS );
	}
}

/*	------------------------	*/
/*	 inxsql_allocate_storage 	*/
/*	------------------------	*/
public	int	inxsql_allocate_storage(struct xs_file * fptr, int length)
{
	if (!( fptr ))
		return( _ERROR_CONNECTION );

	else if (!( fptr->storage = allocate( length ) ))
		return( _ERROR_MEMORY );

	else
	{	
		fptr->storagelength = length;
		fptr->storageoffset = 0;
		return( _SUCCESS );
	}
}

/*	---------------------------	*/
/*	inxsql_collect_file_records	*/
/*	---------------------------	*/
public	int	inxsql_collect_file_records( struct xs_file * fptr, char * dptr, int dlen, int last, int uni, int seq, int * response )
{
        char *  query=(char *) 0;
	char *	result=(char *) 0;
	char *	rptr=(char *) 0;
	char *	vptr=(char *) 0;
	int	i;
	int	flen;
	int	records=0;
	int	status=0;
	int	offset=0;
        struct  xs_field * cptr;
        struct  xs_connection * xptr;

        if ( verbose ) printf("inxsql_collect_records()\r\n");

	if ((status = inxsql_liberate_storage( fptr )) != _SUCCESS)
		return( status );
	else if (!( xptr = fptr->connection ))
                return(_ERROR_CONNECTION);
	else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
		return( status );
	else if ( inxsql_drop_file_view( fptr ) != _SUCCESS )
                return(_ERROR_CONNECTION);
        else if (!( query = allocate( _STD_QUERY_LENGTH + dlen + strlen(fptr->name) ) ))
                return(_ERROR_MEMORY);
        else
        {
                /* ---------------------------- */
                /* prepare the SELECT statement */
                /* ---------------------------- */
                sprintf(query,"SELECT %s FROM %s ",fptr->primary.name,inxsql_table_name(fptr));

		if (!( offset = inxsql_where_clause( fptr, query, strlen(query), dptr, dlen )))
		{
			liberate( query );
			return( _ERROR_SYNTAX );
		}

                /* ---------------------------- */
                /* process the SELECT statement */
                /* ---------------------------- */
		if ((status = inxsql_query( fptr->connection, query, offset )) != _SUCCESS)
		{
			liberate( query );
			return( status );
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
                        xptr->result = (void *) 0;
                        liberate(query);
                        return(_ERROR_RECORD_NOT_FOUND);
                }
		else if (!(records = inxsql_num_rows( xptr )))
		{
			/* ------------------------------------ */
			/* the official result rowcount is zero */
			/* ------------------------------------ */
                	inxsql_free_result(xptr);
                        xptr->result = (void *) 0;
			if ( response ) *response = records;
			liberate( query );
			return( _SUCCESS );	
		}
		/* ---------------------------------- */
		/* allocate the result storage buffer */
		/* ---------------------------------- */
		else if ((status = inxsql_allocate_storage(fptr, records * fptr->primary.size )) != _SUCCESS )
		{
			/* -------------------------------- */
			/* failure allocating result buffer */
			/* -------------------------------- */
                	inxsql_free_result(xptr);
                        xptr->result = (void *) 0;
			if ( response ) *response = 0;
			liberate( query );
			return(  _ERROR_MEMORY );	
		}
		else
                {
                        /* ------------------ */
                        /* process the result */
                        /* ------------------ */
                        INXSQL_ROW row;
                        /* --------------------------------- */
                        /* for all rows (should only be OID) */
                        /* --------------------------------- */
			rptr = fptr->storage;
                        while ((row = inxsql_fetch_row(xptr)))
                        {
				unsigned long * rowlength = inxsql_fetch_lengths(xptr);
				if (!( vptr = inxsql_fetch_field(xptr,row,0) ))
					continue;
				else if (!( flen = rowlength[0] ))
					continue;
				else if (!( flen = inxsql_get_field_value( &fptr->primary, vptr, flen, rptr, fptr->primary.size) ))
					continue;
				else	rptr += fptr->primary.size;
			}
		}

		/* ----------------------------- */        
		/* clean up and indicate success */
		/* ----------------------------- */        
		/* keydata will be fetched later */
		/* ----------------------------- */        
               	inxsql_free_result(xptr);
		xptr->result = (void *) 0;
		if ( response ) *response = records;
		liberate( query );
		return( _SUCCESS );	
	}
}

/*	---------------------------	*/
/*	inxsql_select_file_records	*/
/*	---------------------------	*/
public	int	inxsql_select_file_records(
		struct xs_file * fptr, 
		char * dptr, int dlen, char * kptr, int klen, 
		int * outlen, int * response)
{
        char *  query=(char *) 0;
	char *	result=(char *) 0;
	char *	rptr=(char *) 0;
	char *	vptr=(char *) 0;
	int	i;
	int	flen;
	int	records=0;
	int	column=0;
	int	status=0;
	int	offset=0;
        struct  xs_field * cptr;
        struct  xs_link * lptr;
	struct	xs_index * selection;
	int	selectionsize=0;
	int	selectionerror=0;
        struct  xs_connection * xptr;

        if ( verbose ) printf("inxsql_select_records()\r\n");

	if ((status = inxsql_liberate_storage( fptr )) != _SUCCESS)
		return( status );
	else if (!( xptr = fptr->connection ))
                return(_ERROR_CONNECTION);
	else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
		return( status );
	else if ( inxsql_drop_file_view( fptr ) != _SUCCESS )
                return(_ERROR_CONNECTION);
	else if (!( selection = inxsql_parse_index_list( fptr, kptr, klen, &selectionerror ) ))
		return( selectionerror );
        else if (!( query = allocate( _STD_QUERY_LENGTH + dlen + strlen(fptr->name) ) ))
	{
		selection = inxsql_liberate_index(selection);
                return(_ERROR_MEMORY);
	}
        else
        {
		/* ------------------------ */
		/* calculate the row length */
		/* ------------------------ */
		for (	selectionsize=0, lptr = selection->first;
			lptr != (struct xs_link *) 0;
			lptr = lptr->next)
		{
			if (!( cptr = lptr->field ))
				continue;
			else 	selectionsize += cptr->size;
		}	

                /* ---------------------------- */
                /* prepare the SELECT statement */
                /* ---------------------------- */
		strcpy(query, "SELECT ");

		/* --------------------------- */
		/* the key list is preprepared */
		/* --------------------------- */
		offset = strlen(query);
		memcpy( query+offset, kptr, klen);
		offset += klen;
		*(query+offset) = 0;
                strcat(query,"FROM ");
		strcat(query,inxsql_table_name(fptr));
                strcat(query," ");

		/* ---------------------------------------------- */
		/* the selection is pre prepared and not analysed */
		/* ---------------------------------------------- */
		offset = strlen(query);
		memcpy( query+offset, dptr, dlen);
		offset += dlen;
		*(query+offset) = 0;

                /* ---------------------------- */
                /* process the SELECT statement */
                /* ---------------------------- */
		if ((status = inxsql_query( fptr->connection, query, offset)) != _SUCCESS)
		{
			liberate( query );
			selection = inxsql_liberate_index(selection);
			return( status );
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
			selection = inxsql_liberate_index(selection);
                        return(_ERROR_RECORD_NOT_FOUND);
                }
        	else if (!( inxsql_num_fields(xptr) ))
                {
                        /* ------------------ */
                        /* no fields returned */
                        /* ------------------ */
                	inxsql_free_result(xptr);
                        xptr->result = (void *) 0;
                        liberate(query);
			selection = inxsql_liberate_index(selection);
                        return(_ERROR_RECORD_NOT_FOUND);
                }
		else if (!(records = inxsql_num_rows( xptr )))
		{
			/* ------------------------------------ */
			/* the official result rowcount is zero */
			/* ------------------------------------ */
                	inxsql_free_result(xptr);
                        xptr->result = (void *) 0;
			if ( response ) *response = records;
			liberate( query );
			selection = inxsql_liberate_index(selection);
			return( _SUCCESS );	
		}
		/* ---------------------------------- */
		/* allocate the result storage buffer */
		/* ---------------------------------- */
		else if ((status = inxsql_allocate_storage(fptr, records * selectionsize )) != _SUCCESS )
		{
			/* -------------------------------- */
			/* failure allocating result buffer */
			/* -------------------------------- */
                	inxsql_free_result(xptr);
                        xptr->result = (void *) 0;
			if ( response ) *response = 0;
			liberate( query );
			selection = inxsql_liberate_index(selection);
			return(  _ERROR_MEMORY );	
		}
		else
                {
                        /* ------------------ */
                        /* process the result */
                        /* ------------------ */
                        INXSQL_ROW row;
                        /* ------------------------------------- */
                        /* for all rows (should comprise fields) */
                        /* ------------------------------------- */
			rptr = fptr->storage;
                        while ((row = inxsql_fetch_row(xptr)))
                        {
				unsigned long * rowlength = inxsql_fetch_lengths(xptr);
				for (	column=0, 
					lptr = selection->first;
					lptr != (struct xs_link *) 0;
					lptr = lptr->next, column++ )
				{
					if (!( cptr = lptr->field ))
						continue;
					else if (!( vptr = inxsql_fetch_field(xptr,row,column) ))
					{
						if ( records == 1 ) { records = 0; break; }
						continue;
					}
					else if (!( flen = rowlength[column] ))
						continue;
					else if (!( flen = inxsql_get_field_value( cptr, vptr, flen, rptr, cptr->size) ))
						continue;
					else 	rptr += cptr->size;
				}
			}
		}

		/* ----------------------------- */        
		/* clean up and indicate success */
		/* ----------------------------- */        
		/* keydata will be fetched later */
		/* ----------------------------- */        
               	inxsql_free_result(xptr);
		if ( response ) *response = records;
		if ( outlen ) *outlen = selectionsize;
		liberate( query );
		selection = inxsql_liberate_index(selection);
		return( _SUCCESS );	
	}
}
/*	-----------------	*/
/*	inxsql_count_view	*/
/*	-----------------	*/
private	int	inxsql_count_view(  struct xs_file * fptr )
{
        struct  xs_connection * xptr = (struct xs_connection *) 0;
	struct	xs_view * vptr = (struct xs_view *) 0;
	struct	xs_index * iptr=(struct xs_index *) 0;
	char	query[1024];
	
	if (!( xptr = fptr->connection ))
                return(_ERROR_CONNECTION);
	else if (!( vptr = fptr->view ))
		return( _SUCCESS );
	else if (!( iptr = fptr->selection ))
		return( _SUCCESS );
	else
	{
		// build the VIEW COUNT query
                sprintf(query,"SELECT COUNT(%s) from  %s_%s_%s ",fptr->primary.name,inxsql_table_name(fptr),vptr->name,vptr->id);
			
		// launch the query 
		if (inxsql_query( fptr->connection, query, strlen(query)) != _SUCCESS)
			return( _SUCCESS );

                /* --------------------------------- */
                /* is there a result to be retrieved */
                /* --------------------------------- */
                else if (!( xptr->result = inxsql_store_result(xptr) ))
			return( _SUCCESS );
        	else if (!( inxsql_num_fields(xptr) ))
                {
                        /* ------------------ */
                        /* no fields returned */
                        /* ------------------ */
               		inxsql_free_result(xptr);
                        xptr->result = (void *) 0;
			return( _SUCCESS );
                }
                else
                {
                        /* ------------------ */
                        /* process the result */
                        /* ------------------ */
                        INXSQL_ROW row;
                        /* --------------------------------- */
                        /* for all rows (should only be one) */
                        /* --------------------------------- */
                        while ((row = inxsql_fetch_row(xptr)))
                        {
                                iptr->eof = atoi( inxsql_fetch_field(xptr,row,0) );
                                break;
                        }
               		inxsql_free_result(xptr);
                        xptr->result = (void *) 0;
			return( _SUCCESS );
                }
	}
}	

/*	----------------------------	*/
/*	inxsql_position_file_records	*/
/*	----------------------------	*/
public	int	inxsql_position_file_records( struct xs_file * fptr, char * dptr, int dlen, int last, int uni, int seq, int * response )
{
        char *  query=(char *) 0;
        char *  where=(char *) 0;
	int	records=0;
	int	status=0;
        struct  xs_field * cptr;
	int	offset=0;
	int	length=0;
        struct  xs_connection * xptr = (struct xs_connection *) 0;
	struct	xs_view * vptr = (struct xs_view *) 0;
	struct	xs_index * jptr=(struct xs_index *) 0;

        if ( verbose ) printf("inxsql_position_records()\r\n");

	/* --------------------------------------- */
	/* validate the connection and handle view */
	/* --------------------------------------- */
	if ( uni )
                return(_ERROR_SYNTAX);
	else if (!( xptr = fptr->connection ))
                return(_ERROR_CONNECTION);
	else if ((status = inxsql_use_database( xptr, fptr->base )) != _SUCCESS)
		return( status );
	else if ((status = inxsql_commit_transaction( xptr ) ))
		return( status );
	else if ( inxsql_drop_file_view( fptr ) != _SUCCESS )
                return(_ERROR_CONNECTION);
        else if (!( query = allocate( _STD_QUERY_LENGTH + dlen + strlen(fptr->name) ) ))
                return(_ERROR_MEMORY);
        else if (!( where = allocate( _STD_QUERY_LENGTH + dlen + strlen(fptr->name) ) ))
	{
		query = liberate( query );
                return(_ERROR_MEMORY);
	}
	// allocate an index carrier
	else if (!(fptr->selection = inxsql_allocate_index((struct inxsql_index *) 0)))
	{
		query = liberate( query );
		where = liberate( where );
                return(_ERROR_MEMORY);
	}
	// prepare the view for the records
        else if (!( vptr = inxsql_resolve_view( fptr, _INXS_POSIT_VIEW ) ))
	{
		query = liberate( query );
		where = liberate( where );
                return(_ERROR_MEMORY);
	}
	else if (!( vptr->name ))
	{
		query = liberate( query );
		where = liberate( where );
                return(_ERROR_MEMORY);
	}
	else
        {
		// set the direction of the index
		fptr->selection->reverse = last;

		// reset the last key 
		memset(fptr->lastkey,' ',inxsql_field_size(&fptr->primary));

                // prepare the VIEW CLAUSE
		switch ( inxsql_boolean( "INXSQLVIEW", 0 ) )
		{
		case	0	:
			// Create a table for the VIEW result
                	sprintf(query,"CREATE TABLE %s_%s_%s ",inxsql_table_name(fptr),vptr->name,vptr->id);
			break;
		case	1	:
			// Create a view for the VIEW result
                	sprintf(query,"CREATE OR REPLACE VIEW %s_%s_%s AS ",inxsql_table_name(fptr),vptr->name,vptr->id);
			break;
		}

		// build the selection clause first to collect list of terms
		if (!( offset = inxsql_where_clause( fptr, where, 0, dptr, dlen )))
		{
			query = liberate( query );
			where = liberate( where );
			return( _ERROR_SYNTAX );
		}

                // prepare the SELECT statement 
		strcat(query,"SELECT ");
		if (!( uni ))
                	strcat(query,"*");
		else if (!( inxsql_boolean( "INXSQLUNIQUE", 0 ) ))
		{
                        strcat(query,"DISTINCT ");
                        inxsql_append_field_names(query,fptr->first,0);
		}
		else if (!( fptr->selection ))
                	strcat(query,"*");
		else	inxsql_append_distinct_field_names(query,fptr->first,0,fptr->selection);

		strcat(strcat(query," FROM "),inxsql_table_name(fptr));


		// retrieve the appropriate index
		if (( jptr = inxsql_resolve_use_index( fptr, fptr->selection)) != (struct xs_index *) 0)
		{
			// append query with index hint
			if (!( seq ))
				strcat(strcat(strcat(query," USE INDEX ("),jptr->name),")");

			// handle sequential with no index
			else	strcat(query," USE INDEX ()");

			jptr = (struct xs_index *) 0;
		}

		// release the index if sequential
		if ( seq ) 
			fptr->selection = inxsql_liberate_index(fptr->selection);
		else	fptr->selection->current = -1;

		// join selection query clauses
		length = strlen(query);
		memcpy( query+length, where, offset );
		offset += length;
		*(query+offset) = 0;

                /* ---------------------------- */
                /* process the SELECT statement */
                /* ---------------------------- */
		if ((status = inxsql_query( fptr->connection, query, offset )) != _SUCCESS)
		{
			query = liberate( query );
			where = liberate( where );
			return( status );
		}

                /* --------------------------------- */
                /* is there a result to be retrieved */
                /* --------------------------------- */
                else if (!( xptr->result = inxsql_store_result(xptr) ))
                {
                        /* ------------------ */
                        /* no result returned */
                        /* ------------------ */
			if ( response ) *response = 1;
			query = liberate( query );
			where = liberate( where );
			fptr->view = vptr;
			/* ---------------------- */
			/* determine size of view */
			/* ---------------------- */
			return( inxsql_count_view( fptr ) );
                }
        	else if (!( inxsql_num_fields(xptr) ))
                {
                        /* ------------------ */
                        /* no fields returned */
                        /* ------------------ */
			if ( response ) *response = 1;
               		inxsql_free_result(xptr);
			fptr->view = vptr;
			query = liberate( query );
			where = liberate( where );
			/* ---------------------- */
			/* determine size of view */
			/* ---------------------- */
			return( inxsql_count_view( fptr ) );
                }
		else
		{
			/* ----------------------- */
			/* posit indicates SUCCESS */
			/* ----------------------- */
			if ( response ) *response = 1;
               		inxsql_free_result(xptr);
			query = liberate( query );
			where = liberate( where );
			fptr->view = vptr;
			/* ---------------------- */
			/* determine size of view */
			/* ---------------------- */
			return( inxsql_count_view( fptr ) );
		}
	}
}

/*	-------------------------------------------------------------------------------------------------	*/
/*	D A T A B A S E   A C C E S S   M E T H O D   M U L T I F I L E   Q U E R Y   M A N A G E M E N T	*/
/*	-------------------------------------------------------------------------------------------------	*/

/*	------------------------	*/
/*	inxsql_base_where_clause	*/
/*	------------------------	*/
private	int	inxsql_base_where_clause( struct xs_base * bptr, char * query, int offset, char * dptr, int dlen )
{
	int	clauses=0;
	char	name[256];
	char *	compare="=";
	int	i;
	int	klen=_ABAL_KEY_MAX_STD;
	int	flen=0;
	int	vlen=0;
	int	operator=0;
	char * 	logical=(char*) " WHERE ";
	struct	xs_field * cptr;

	klen = bptr->maxkey;

	/* ------------------------------------ */
	/* detect an empty selection expression */
	/* ------------------------------------ */
	if (!(  clauses = *(dptr++) ))
		return( offset );
	else	dlen--;

	/* -------------------------------------------*/
	/* for all the clauses in the query descriptor */
	/* -------------------------------------------*/
	while ( clauses-- )
	{
		/* -------------------------- */
                /* step over long name prefix */
                /* -------------------------- */
                if (!( *dptr )) { dptr++; dlen--; }

		/* ----------------------- */
		/* validate remaining data */
		/* ----------------------- */
		if ( dlen < (klen+2) ) 
			return(inxsql_failure("not enough data for clauses"));

		/* ---------------------- */
		/* collect the field name */
		/* ---------------------- */
		for ( i=0; i < klen; i++ ) if (( name[i] = dptr[i]) == ' ') name[i] = 0; 

		/* ---------------------------------------- */
		/* consume the field name and operator code */
		/* ---------------------------------------- */
		dptr += klen; dlen -= klen; operator = ( *(dptr++) & 0x00FF ); dlen--;

		/* ------------------------------------ */
		/* collect and consume the value length */
		/* ------------------------------------ */
		if (!( vlen = *(dptr++)))
			return(inxsql_failure("query column value length"));
		else	dlen--;

		/* ------------------------------------- */
		/* output the relevent statement keyword */
		/* ------------------------------------- */
		if (!( offset = inxsql_append_query( query, offset, logical  )))
			return(inxsql_failure("query syntax append"));
		else	logical = " AND ";

		/* --------------------------------- */
		/* validate the column name and size */
		/* --------------------------------- */
		if (!( cptr = inxsql_locate_base_field( bptr, name ) ))
			return(inxsql_failure("query missing column name"));

		else if (!( flen = inxsql_field_size( cptr )))
			return(inxsql_failure("query incorrect column size"));

		else if ( vlen != flen )
			return(inxsql_failure("query unmatched column value size"));

		else if ( flen > dlen )
			return(inxsql_failure("query not enough column data"));

		else if (!( offset = inxsql_append_query( query, offset, cptr->name )))
			return(inxsql_failure("query column name append"));

		/* --------------------------------------- */
		/* convert and output the compare operator */
		/* --------------------------------------- */
		else if (!( compare = inxsql_convert_compare( operator, dptr, flen, '*' ) ))
			return(inxsql_failure("query unexpected compare operator"));

		else if (!( offset = inxsql_append_query( query, offset, compare )))
			return(inxsql_failure("query operator append"));

		/* ------------------------ */
		/* generate the field value */
		/* ------------------------ */
		else if (!( offset = inxsql_set_field_value( cptr, query, offset, dptr, flen, 0, 1 ) ))
			return(inxsql_failure("query column value append"));
		else	dlen -= flen;

	}

	/* ------------------------------- */
	/* return the end of select offset */
	/* ------------------------------- */
	query[offset] = 0; return( offset );
} 

/*	----------------------------	*/
/*	inxsql_position_base_records	*/
/*	----------------------------	*/
public	int	inxsql_position_base_records( struct xs_base * bptr, char * dptr, int dlen, int last, int uni, int seq, int * response )
{
        char *  query=(char *) 0;
	int	records=0;
	int	status=0;
        struct  xs_field * cptr;
	int	offset=0;
        struct  xs_connection * xptr = (struct xs_connection *) 0;
	struct	xs_view * vptr = (struct xs_view *) 0;
        struct  xs_joint * jptr;

        if ( verbose ) printf("inxsql_position_base_records()\r\n");

	/* --------------------------------------- */
	/* validate the connection and handle view */
	/* --------------------------------------- */
	if (!( xptr = bptr->connection ))
                return(_ERROR_CONNECTION);
	else if ((status = inxsql_use_database( xptr, bptr )) != _SUCCESS)
		return( status );
	else if ( inxsql_drop_base_view( bptr ) != _SUCCESS )
                return(_ERROR_CONNECTION);
        else if (!( query = allocate( _STD_QUERY_LENGTH + dlen + strlen(bptr->name) ) ))
                return(_ERROR_MEMORY);
        else if (!( vptr = inxsql_resolve_base_view( bptr, _INXS_POSIT_VIEW ) ))
                return(_ERROR_MEMORY);
	else if (!( vptr->name ))
                return(_ERROR_MEMORY);
	else
        {
                /* ---------------------------- */
                /* prepare the SELECT statement */
                /* ---------------------------- */
		switch ( inxsql_boolean( "INXSQLVIEW", 0 ) )
		{
		case	0	:
			// Create a table for the VIEW result
                	sprintf(query,"CREATE TABLE %s_%s_%s SELECT * FROM ",bptr->name,vptr->name,vptr->id);
			break;
		case	1	:
			// Create a view for the VIEW result
                	sprintf(query,"CREATE OR REPLACE VIEW %s_%s_%s AS SELECT * FROM ",bptr->name,vptr->name,vptr->id);
			break;
		}

		/* ----------------------- */
		/* prepare the JOIN clause */
		/* ----------------------- */
		if (( status =  inxsql_join_clause( bptr, query, dptr, dlen ) ) != _SUCCESS)
		{
			liberate( query );
			return( status );
		}

		if (!( offset = inxsql_base_where_clause( bptr, query, strlen(query), dptr, dlen )))
		{
			liberate( query );
			return( _ERROR_SYNTAX );
		}

                /* ---------------------------- */
                /* process the SELECT statement */
                /* ---------------------------- */
		if ((status = inxsql_query( bptr->connection, query, offset )) != _SUCCESS)
		{
			liberate( query );
			return( status );
		}

                /* --------------------------------- */
                /* is there a result to be retrieved */
                /* --------------------------------- */
                else if (!( xptr->result = inxsql_store_result(xptr) ))
                {
                        /* ------------------ */
                        /* no result returned */
                        /* ------------------ */
			if ( response ) *response = 1;
                        liberate(query);
			bptr->view = vptr;
			return( _SUCCESS );	
                }
        	else if (!( inxsql_num_fields(xptr) ))
                {
                        /* ------------------ */
                        /* no fields returned */
                        /* ------------------ */
			if ( response ) *response = 1;
               		inxsql_free_result(xptr);
			bptr->view = vptr;
                        liberate(query);
			return( _SUCCESS );	
                }
		else
		{
			/* ----------------------- */
			/* posit indicates SUCCESS */
			/* ----------------------- */
			if ( response ) *response = 1;
               		inxsql_free_result(xptr);
			liberate( query );
			bptr->view = vptr;
			return( _SUCCESS );	
		}
	}
}

/*	-------------------------	*/
/*	inxsql_count_base_records	*/
/*	-------------------------	*/
public	int	inxsql_count_base_records( struct xs_base * bptr, char * dptr, int dlen, int uni, int seq, int * response )
{
        char *  query=(char *) 0;
	int	records=0;
	int	status=0;
	int	offset=0;
        struct  xs_field * cptr;
        struct  xs_joint * jptr;
        struct  xs_connection * xptr;

        if ( verbose ) printf("inxsql_count_base_records()\r\n");

	/* -------------------------------- */
	/* validate the received parameters */
	/* -------------------------------- */
	if (!( xptr = bptr->connection ))
                return(_ERROR_CONNECTION);
	else if ((status = inxsql_use_database( xptr, bptr )) != _SUCCESS)
		return( status );
	else if ( inxsql_drop_base_view( bptr ) != _SUCCESS )
                return(_ERROR_CONNECTION);
        else if (!( query = allocate( _STD_QUERY_LENGTH + dlen + strlen(bptr->name) ) ))
                return(_ERROR_MEMORY);
        else
        {
                /* ---------------------------- */
                /* prepare the SELECT statement */
                /* ---------------------------- */
                sprintf(query,"SELECT COUNT(*) AS result FROM ");

		/* ----------------------- */
		/* prepare the JOIN clause */
		/* ----------------------- */
		if (( status =  inxsql_join_clause( bptr, query, dptr, dlen ) ) != _SUCCESS)
		{
			liberate( query );
			return( _ERROR_SYNTAX );
		}

		/* ----------------------------- */
		/* process the where description */
		/* ----------------------------- */
		if (!( offset = inxsql_base_where_clause( bptr, query, strlen(query) , dptr, dlen )))
		{
			liberate( query );
			return( _ERROR_SYNTAX );
		}

                /* ---------------------------- */
                /* process the SELECT statement */
                /* ---------------------------- */
		if ((status = inxsql_query( xptr, query, offset )) != _SUCCESS)
		{
			liberate( query );
			return( status );
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
                        INXSQL_ROW row;
                        /* --------------------------------- */
                        /* for all rows (should only be one) */
                        /* --------------------------------- */
                        while ((row = inxsql_fetch_row(xptr)))
                        {
				records = atoi( inxsql_fetch_field(xptr,row,0) );
				break;
			}
		}

		/* ----------------------- */
		/* return the record count */
		/* ----------------------- */
		if ( response ) *response = records;

		liberate( query );
		return( _SUCCESS );	
	}
}

#endif	/* _inxsql_query_c */

