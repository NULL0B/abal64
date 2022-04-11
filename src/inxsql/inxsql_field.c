#ifndef	_inxsql_field_c
#define	_inxsql_field_c

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

/* external BCD conversions */
extern	unsigned int bcdtoa(unsigned char *, unsigned int, unsigned char *, unsigned int);
extern	unsigned int atobcd(unsigned char *, unsigned char *, unsigned int, unsigned int);

/* prototype UNICODE conversions */
private	unsigned int inxsql_from_unicode( struct xs_convertor * xptr );
private unsigned int inxsql_to_unicode(unsigned char * bptr,unsigned int value);

private char    _field_name[1024];

#ifdef	_INXSQL_MYSQL
/*	-----------------	*/
/*	inxsql_bind_field	*/
/*	-----------------	*/
public	int	inxsql_bind_field( struct xs_field * cptr, MYSQL_BIND * bptr, char * dptr )
{
	unsigned int blen;

	if (!( blen = inxsql_field_bsize( cptr ) ))
		return(0);

	switch ( cptr->type )
	{
	case	_INXS_INT8	:
		bptr->buffer_type = MYSQL_TYPE_TINY;
		break;
	case	_INXS_INT16	:
		bptr->buffer_type = MYSQL_TYPE_SHORT;
		break;
	case	_INXS_INT32	:
		bptr->buffer_type = MYSQL_TYPE_LONG;
		break;
	case	_INXS_INT64	:
		bptr->buffer_type = MYSQL_TYPE_LONGLONG;
		break;
	case	_INXS_STRING	:
		bptr->buffer_type = MYSQL_TYPE_STRING;
		break;
	case	_INXS_DATE	:
		bptr->buffer_type = MYSQL_TYPE_DATE;
		break;
	case	_INXS_TIME	:
		bptr->buffer_type = MYSQL_TYPE_TIME;
		break;
	case	_INXS_VARBIN	:
	case	_INXS_BIN	:
		bptr->buffer_type = MYSQL_TYPE_BLOB;
		break;
	case	_INXS_FLOAT	:
		if ( cptr->size <= 4 )
			bptr->buffer_type = MYSQL_TYPE_FLOAT;
		else	bptr->buffer_type = MYSQL_TYPE_DOUBLE;
		break;
	case	_INXS_BCD	:
		bptr->buffer_type = MYSQL_TYPE_NEWDECIMAL;
		break;
	default			:
		return(0);
	}
	
	bptr->buffer = dptr;
	bptr->buffer_length = blen;
	bptr->length = &bptr->buffer_length;
	return( blen );
}

/*	------------------	*/
/*	inxsql_bind_fields	*/
/*	------------------	*/
public  MYSQL_BIND * inxsql_bind_fields( struct xs_file * fptr, MYSQL_BIND * bptr, char * dptr )
{
	struct	xs_field * cptr;

	// bind the columns to the record buffer
	for ( 	cptr = fptr->first;
		cptr != (struct xs_field *) 0;
		cptr = cptr->next, bptr++ )
		dptr += inxsql_bind_field( cptr, bptr, dptr );

	// return next column
	return( bptr );
}
#endif

/*	------------------	*/
/*	inxsql_field_count	*/
/*	------------------	*/
public	int	inxsql_field_count(struct xs_file * fptr)
{
        struct  xs_field * cptr;
	int	fields=0;
        for (   cptr = fptr->first;
                cptr != (struct xs_field *) 0;
                cptr = cptr->next, fields++ );

	return( fields );
}


/*      -----------------       */
/*      inxsql_field_name       */
/*      -----------------       */
public  char *  inxsql_field_name( char * sptr )
{
        if ( sptr )
                sprintf(_field_name,"%s",sptr);
        else    strcpy(_field_name,"null_field");
        return( _field_name );
}

/*	----------	*/
/*	field_trim	*/
/*	----------	*/
private	void	field_trim( char * sptr )
{
	int	i;
	int	l=0;
	for ( i= 0; *(sptr+i) != 0; i++ )
		if ( *(sptr+i) != ' ' )
			l = i;
	*(sptr+l+1) = 0;
	return;
}

/*	--------------------	*/
/*	allocate_column_name	*/
/*	--------------------	*/
private	char *	allocate_column_name( char  * nptr, int nlen )
{
	char *	result;
	if (!( result = allocate( nlen+1 ) ))
		return( result );
	else
	{
		memcpy( result, nptr, nlen );
		*(result + nlen) = 0;
		field_trim( result );
		return( result );
	}
}

/*	----------------------	*/
/*	inxsql_compare_columns	*/
/*	----------------------	*/
/*	Returns an indication	*/
/*	of the difference:	*/
/*	----------------------	*/
/*	0 : SUCCESS		*/
/*	1 : Different Type	*/
/*	2 : Different Size	*/
/*	3 : Different Extra	*/
/*	----------------------	*/
public	int	inxsql_compare_columns( struct xs_field * lptr, struct xs_field * rptr )
{
	if ( lptr->type != rptr->type )
		return(_INXS_DIFFERENT_TYPE);
	else if ( lptr->size != rptr->size )
		return(_INXS_DIFFERENT_SIZE);
	else if ( lptr->extra != rptr->extra )
		return(_INXS_DIFFERENT_EXTRA);
	else	return(_SUCCESS);
}

/*	-------------------	*/
/*	inxsql_locate_field	*/
/*	-------------------	*/
public	struct xs_field * inxsql_locate_field( struct xs_file * fptr, char * nptr )
{
	struct xs_field * cptr;
	if (!( strcasecmp( nptr, fptr->primary.name ) ))
		return( &fptr->primary );
	for (	cptr = fptr->first;
		cptr != (struct xs_field *) 0;
		cptr = cptr->next)
	{
		if (!( cptr->name ))
			continue;
		else if (!( inxsql_field_name_compare( cptr->name, nptr ) ))
			break;
	}
	return( cptr );
}

/*	-------------------------	*/
/*	 inxsql_expression_field 	*/
/*	-------------------------	*/
public	struct xs_field * inxsql_expression_field( struct xs_file * fptr, char * nptr )
{
	struct xs_field * cptr=(struct xs_field *) 0;
	struct xs_field * kptr=(struct xs_field *) 0;
	int	braces=0;
	int	quoted=0;
	char	token[204];
	int	i;
	int	c;
	if (!( nptr ))
		return((struct xs_field *) 0);
	else
	{
		while ( *nptr )
		{
			switch ((c = *(nptr++)))
			{
			case	' '	:
			case	'\t'	:
			case	'\r'	:
			case	'\n'	:
				continue;
			case	'-'	:
			case	'+'	:
			case	'/'	:
			case	'*'	:
			case	','	:
				continue;
			case	0x0027	:
			case	0x0022	:
				if (!( quoted ))
					quoted = c;
				else if ( quoted == c )
					quoted = 0;
				continue;
	
			case	'('	:
				if ( quoted )
					continue;
				else
				{
					braces++;
					continue;
				}
			case	')'	:
				if ( quoted )
					continue;
				else if (!( braces ))
					break;
				else
				{
					braces--;
					continue;
				}
			default		:
				if ( quoted )
					continue;
				// detect a column legal start character
				else if (((c >= 'a') && (c <= 'z'))
				     ||  ((c >= 'A') && (c <= 'Z'))
				     ||  ( c == '_' ) )
				{
					// collect a potential column name
					i = 0;
					token[i++] = c;
					while ((c = *nptr) != 0)
					{
						if (((c >= 'a') && (c <= 'z'))
						||  ((c >= 'A') && (c <= 'Z'))
						||  ((c >= '0') && (c <= '9'))
						||  ( c == '-' ) 
						||  ( c == '.' ) 
						||  ( c == '$' ) 
						||  ( c == '_' ) )
							token[i++] = *(nptr++);
						else	break;
					}
					token[i++] = 0;
					// check if it is a column name
					if (( kptr = inxsql_locate_field( fptr, token )) != (struct xs_field *) 0)
						cptr = kptr;
				}
				continue;
			}
			break;
		}
		// ensure expression parsed correctly
		if (!( *nptr ))
			return(cptr);
		else	return((struct xs_field *) 0);
	}
}

/*	---------------------	*/
/*	inxsql_liberate_field	*/
/*	---------------------	*/
public	struct xs_field * inxsql_liberate_field( struct xs_field * cptr )
{
	if ( cptr )
	{
		if ( cptr->name )
			cptr->name = liberate( cptr->name );
		liberate( cptr );
	}
	return( (struct xs_field *) 0 );
}

/*	-----------------	*/
/*	 inxsql_bcd_size	*/
/*	-----------------	*/
public	int	inxsql_bcd_size(struct xs_field * cptr)
{
	/* the BCD unpacked size */
	return(((cptr->size * 2) +1));
}

/*	-----------------	*/
/*	inxsql_field_size	*/
/*	-----------------	*/
public	int	inxsql_field_size(struct xs_field * cptr)
{
	switch ( cptr->type )
	{
	case	_INXS_INT8	:
	case	_INXS_INT16	:
	case	_INXS_INT32	:
	case	_INXS_INT64	:
	case	_INXS_STRING	:
	case	_INXS_BIN	:
	case	_INXS_DATE	:
	case	_INXS_TIME	:
	case	_INXS_VARBIN 	:
		return( cptr->size );
	case	_INXS_FLOAT	:
		if ( cptr->size <= 4 )
			return( 4 );
		else	return( 8 );
	case	_INXS_BCD	:
		return( cptr->size );

	default			:
		return(0);
	}
}	

/*	------------------	*/
/*	inxsql_field_qsize	*/
/*	------------------	*/
public	int	inxsql_field_qsize(struct xs_field * cptr)
{
	switch ( cptr->type )
	{
	case	_INXS_STRING	:
		// worst case UTF8 size
		return( 2 + ( 4 * cptr->size ) );
	case	_INXS_FLOAT	:
	case	_INXS_BCD	:
	case	_INXS_BIN	:
	case	_INXS_VARBIN	:
		return( 2 + ( 2 * cptr->size ) );
	case	_INXS_DATE	:
		return( 12 );
	case	_INXS_TIME	:
		return( 10 );
	case	_INXS_INT8	:
		return( 4 );
	case	_INXS_INT16	:
		return( 6 );
	case	_INXS_INT32	:
		return( 14 );
	case	_INXS_INT64	:
		return( 48 );
	default			:
		return( inxsql_field_size( cptr ) );
	}
}

/*	------------------	*/
/*	inxsql_field_bsize	*/
/*	------------------	*/
public	int	inxsql_field_bsize(struct xs_field * cptr)
{
	// strings may contain UNICODE 
	switch ( cptr->type )
	{
	case	_INXS_STRING	:
		// max utf8mb4 size
		return( cptr->size * 4 );
	case	_INXS_FLOAT 	:
		if ( cptr->size <= 4 )
			return( 4 );
		else	return( 8 );
	case	_INXS_BCD 	:
		// max digit count
		return( inxsql_bcd_size(cptr) );
#ifdef	_INXSQL_MYSQL
	case	_INXS_DATE	:
		return( sizeof( MYSQL_TIME ) );
	case	_INXS_TIME	:
		return( sizeof( MYSQL_TIME ) );
#else
	case	_INXS_DATE	:
		return(4);
	case	_INXS_TIME	:
		return(4);
#endif
	default			:
		// whatver it would be
		return( inxsql_field_size( cptr ) );
	}
}

/*	---------------------	*/
/*	inxsql_allocate_field	*/
/*	---------------------	*/
private	struct xs_field * inxsql_allocate_field( char * nptr, int nlen, int length, int type, int extra )
{
	struct	xs_field * cptr;
	if (!( cptr = allocate( sizeof( struct xs_field ) ) ))
		return( cptr );
	else
	{
		memset( cptr, 0, sizeof( struct xs_field ) );
		cptr->size = length;
		cptr->type  = type;
		cptr->extra = extra;
		if (!( cptr->name = allocate_column_name( nptr, nlen ) ))
			return( inxsql_liberate_field( cptr ) );
		else	return( cptr );
	}
}

/*	----------------	*/
/*	inxsql_add_field	*/
/*	----------------	*/
public	struct xs_field * inxsql_add_field( struct xs_file * fptr, char * nptr, int length, int type, int extra )
{
	struct	xs_field * cptr;

	if (!( cptr = inxsql_allocate_field( nptr, _STD_KEY_LENGTH, length, type, extra ) ))
		return( cptr );
	else if (!( cptr->file = fptr ))
		return( inxsql_liberate_field( cptr ));
	else
	{
		if (!( cptr->previous = fptr->last ))
			fptr->first = cptr;
		else	fptr->last->next = cptr;
		fptr->last = cptr;
		if ( cptr->previous )
			cptr->offset = (cptr->previous->offset + cptr->previous->size);
		return( cptr );
	}
}

/*	-----------------	*/
/*	inxsql_copy_field	*/
/*	-----------------	*/
public	struct xs_field * inxsql_copy_field( struct xs_file * fptr, struct xs_field * cptr )
{
	return( inxsql_add_field( fptr, cptr->name, cptr->size, cptr->type, cptr->extra ) );
}

#ifdef	_INXSQL_PGSQL
/*	-------------------------	*/
/*	inxsql_append_pgsql_field	*/
/*	-------------------------	*/
private	int	inxsql_append_pgsql_field( struct xs_file * fptr, char * nptr, int length, int type, int extra )
{
	char	query[_STD_QUERY_LENGTH];
	struct	xs_field * cptr;
	int	status;
	int	digits=0;
	if ( verbose ) printf("inxsql_append_field( %s, %s, %u, %u )\r\n",fptr->name,nptr, length,type);
	if ((cptr = inxsql_locate_field( fptr, nptr )) != (struct xs_field *) 0)
		return(_ERROR_KEY_INCORECT);
	else if (!( cptr = inxsql_add_field( fptr, nptr, length, type, extra ) ))
		return( _ERROR_MEMORY);
	else
	{
		switch ( cptr->type )
		{
		case	_INXS_INT8	:
			sprintf(query,"ALTER TABLE %s ADD COLUMN %s TINYINT",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;
		case	_INXS_INT16	:
			sprintf(query,"ALTER TABLE %s ADD COLUMN %s SMALLINT",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;
		case	_INXS_INT32	:
			sprintf(query,"ALTER TABLE %s ADD COLUMN %s INT",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;
		case	_INXS_INT64	:
			sprintf(query,"ALTER TABLE %s ADD COLUMN %s BIGINT",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;
		case	_INXS_DATE	:
			sprintf(query,"ALTER TABLE %s ADD COLUMN %s DATE",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;
		case	_INXS_TIME	:
			sprintf(query,"ALTER TABLE %s ADD COLUMN %s TIME",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;
		case	_INXS_BCD	:
			digits=((cptr->size *2) - 1);
			if ( cptr->extra > 0 )
			{
				sprintf(query,"ALTER TABLE %s ADD COLUMN %s DECIMAL(%u,%u)",
					inxsql_table_name(fptr),
					inxsql_field_name(cptr->name),
					(digits - (cptr->extra?1:0)), cptr->extra);
			}
			else
			{
				sprintf(query,"ALTER TABLE %s ADD COLUMN %s NUMERIC(%u)",inxsql_table_name(fptr),inxsql_field_name(cptr->name),digits);
			}
			break;
		case	_INXS_FLOAT	:
			if ( cptr->size > 4 )
				sprintf(query,"ALTER TABLE %s ADD COLUMN %s DOUBLE",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			else	sprintf(query,"ALTER TABLE %s ADD COLUMN %s FLOAT",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;
		case	_INXS_STRING	:
			if ( cptr->size > 255 )
				sprintf(query,"ALTER TABLE %s ADD COLUMN %s TEXT(%u)",inxsql_table_name(fptr),inxsql_field_name(cptr->name),cptr->size);
			else 	sprintf(query,"ALTER TABLE %s ADD COLUMN %s CHAR(%u)",inxsql_table_name(fptr),inxsql_field_name(cptr->name),cptr->size);
			break;
		case	_INXS_VARBIN	:
		case	_INXS_BIN	:
			sprintf(query,"ALTER TABLE %s ADD COLUMN %s BYTEA",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;
		default			:
			return(_ERROR_UNSUPPORTED);
		}
		if (( status = inxsql_use_database( fptr->connection, fptr->base )) != _SUCCESS)
			return(status);
		else	return(inxsql_query(fptr->connection, query, strlen(query) ));
	}
}
#endif

#ifdef	_INXSQL_MYSQL
/*	-------------------------	*/
/*	inxsql_append_mysql_field	*/
/*	-------------------------	*/
private	int	inxsql_append_mysql_field( struct xs_file * fptr, char * nptr, int length, int type, int extra )
{
	char	query[_STD_QUERY_LENGTH];
	struct	xs_field * cptr;
	int	status;
	int	digits=0;
	if ( verbose ) printf("inxsql_append_field( %s, %s, %u, %u )\r\n",fptr->name,nptr, length,type);
	if ((cptr = inxsql_locate_field( fptr, nptr )) != (struct xs_field *) 0)
		return(_ERROR_KEY_INCORECT);
	else if (!( cptr = inxsql_add_field( fptr, nptr, length, type, extra ) ))
		return( _ERROR_MEMORY);
	else
	{
		switch ( cptr->type )
		{
		case	_INXS_INT8	:
			sprintf(query,"ALTER TABLE %s ADD COLUMN %s TINYINT",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;

		case	_INXS_INT16	:
			sprintf(query,"ALTER TABLE %s ADD COLUMN %s SMALLINT",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;

		case	_INXS_INT32	:
			sprintf(query,"ALTER TABLE %s ADD COLUMN %s INT",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;

		case	_INXS_INT64	:
			sprintf(query,"ALTER TABLE %s ADD COLUMN %s BIGINT",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;
		case	_INXS_DATE	:
			sprintf(query,"ALTER TABLE %s ADD COLUMN %s DATE",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;
		case	_INXS_TIME	:
			sprintf(query,"ALTER TABLE %s ADD COLUMN %s TIME",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;
		case	_INXS_BCD	:
			digits=((cptr->size *2) - 1);
			if ( cptr->extra > 0 )
			{
				sprintf(query,"ALTER TABLE %s ADD COLUMN %s DECIMAL(%u,%u)",
					inxsql_table_name(fptr),
					inxsql_field_name(cptr->name),
					(digits - (cptr->extra?1:0)), cptr->extra);
			}
			else
			{
				sprintf(query,"ALTER TABLE %s ADD COLUMN %s NUMERIC(%u)",inxsql_table_name(fptr),inxsql_field_name(cptr->name),digits);
			}
			break;

		case	_INXS_FLOAT	:
			if ( cptr->size > 4 )
				sprintf(query,"ALTER TABLE %s ADD COLUMN %s DOUBLE",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			else	sprintf(query,"ALTER TABLE %s ADD COLUMN %s FLOAT",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;

		case	_INXS_VARBIN	:
			sprintf(query,"ALTER TABLE %s ADD COLUMN %s VARBINARY(32000)",inxsql_table_name(fptr),inxsql_field_name(cptr->name));
			break;

		case	_INXS_STRING	:
			if ( cptr->size > 255 )
				sprintf(query,"ALTER TABLE %s ADD COLUMN %s TEXT(%u)",inxsql_table_name(fptr),inxsql_field_name(cptr->name),cptr->size);
			else 	sprintf(query,"ALTER TABLE %s ADD COLUMN %s CHAR(%u)",inxsql_table_name(fptr),inxsql_field_name(cptr->name),cptr->size);
			break;
		case	_INXS_BIN	:
			if ( cptr->size > 255 )
				sprintf(query,"ALTER TABLE %s ADD COLUMN %s BLOB(%u)",inxsql_table_name(fptr),inxsql_field_name(cptr->name),cptr->size);
			else	sprintf(query,"ALTER TABLE %s ADD COLUMN %s BINARY(%u)",inxsql_table_name(fptr),inxsql_field_name(cptr->name),cptr->size);
			break;
		default			:
			return(_ERROR_UNSUPPORTED);
		}
		if (( status = inxsql_use_database( fptr->connection, fptr->base )) != _SUCCESS)
			return(status);
		else	return(inxsql_query(fptr->connection, query, strlen(query) ));
	}
}			
#endif

/*	-------------------	*/
/*	inxsql_append_field	*/
/*	-------------------	*/
public	int	inxsql_append_field( struct xs_file * fptr, char * nptr, int length, int type, int extra )
{
	switch ( fptr->connection->engine )
	{
#ifdef	_INXSQL_MYSQL
	case	_INXSQL_MYSQL_ENGINE	:
		return( inxsql_append_mysql_field( fptr, nptr, length, type, extra ) );
#endif
#ifdef	_INXSQL_PGSQL
	case	_INXSQL_PGSQL_ENGINE	:
		return( inxsql_append_pgsql_field( fptr, nptr, length, type, extra ) );
#endif
	default				:
		return(_ERROR_UNSUPPORTED);
	}
}
	
/*	------------------------	*/
/*	 inxsql_get_field_value 	*/
/*	------------------------	*/
/*	stores data back to the		*/
/*	ABAL data transfer zone.	*/
/*	------------------------	*/
public  int inxsql_get_field_value( struct xs_field * cptr, char * sptr, int slen, unsigned char * dptr, int dlen )
{
	struct	xs_convertor X;
	unsigned int c;
	unsigned char buffer[1024];
	double dvalue=0;
	int	y,m,d,h,s;
	char * final=(char *) 0;

	if (cptr->type == _INXS_STRING )
	{
		memset(dptr,' ',dlen);
		X.buffer = sptr;
		X.length = slen;
		while ((c = inxsql_from_unicode( &X )) != 0)
			*(dptr++) = c;
		return( dlen );
	}
	else if ((cptr->type == _INXS_BIN    )
	     ||  (cptr->type == _INXS_VARBIN ))
	{
		memset(dptr,0,dlen);
		memcpy(dptr,sptr,(slen < dlen?slen:dlen));
		return( dlen );
	}
	else
	{
		long long v=0;
		switch ( cptr->type )
		{
		case	_INXS_INT8	:
			v = atoi(sptr);
			*dptr = v;
			return(1);
		case	_INXS_INT16	:
			v = atoi(sptr);
			*(dptr++) = ((v >> 8) & 0x00FF);	
			*(dptr++) = (v & 0x00FF);	
			return(2);
		case	_INXS_INT32	:
			v = atoi(sptr);
			*(dptr++) = ((v >> 24) & 0x00FF);	
			*(dptr++) = ((v >> 16) & 0x00FF);	
			*(dptr++) = ((v >> 8) & 0x00FF);	
			*(dptr++) = (v & 0x00FF);	
			return(4);
		case	_INXS_INT64	:
			v = atoi(sptr);
			*(dptr++) = ((v >> 56) & 0x00FF);	
			*(dptr++) = ((v >> 48) & 0x00FF);	
			*(dptr++) = ((v >> 40) & 0x00FF);	
			*(dptr++) = ((v >> 32) & 0x00FF);	
			*(dptr++) = ((v >> 24) & 0x00FF);	
			*(dptr++) = ((v >> 16) & 0x00FF);	
			*(dptr++) = ((v >> 8) & 0x00FF);	
			*(dptr++) = (v & 0x00FF);	
			return(8);
		case	_INXS_DATE	:
			memset(dptr,0,dlen);
			y = atoi(sptr);
			if (!(sptr = strchr(sptr,'-')))
				m = d = 0;
			else
			{
				sptr++;
				m = atoi(sptr);
				if (!(sptr = strchr(sptr,'-')))
					d = 0;
				else
				{
					sptr++;
					d = atoi(sptr);
				}
			}	
			switch ( dlen )
			{
			case	2	:	// Y%
				*(dptr++) = ((y >> 8) & 0x0FF);
				*(dptr++) = (y & 0x00FF);
				break;
			case	3	:	// Y%, M#
				*(dptr++) = ((y >> 8) & 0x0FF);
				*(dptr++) = (y & 0x00FF);
				*(dptr++) = (m & 0x00FF);
				break;
			case	4	:	// Y%, M#, D#
				*(dptr++) = ((y >> 8) & 0x0FF);
				*(dptr++) = (y & 0x00FF);
				*(dptr++) = (m & 0x00FF);
				*(dptr++) = (d & 0x00FF);
				break;
			case	8	:	// Y$, M$,D$
				sprintf(buffer,"%04u%02u%02u",y,m,d);
				memcpy(dptr,buffer,dlen);
				break;
			}	
			return(dlen);

		case	_INXS_TIME	:
			memset(dptr,0,dlen);
			h = atoi(sptr);
			if (!(sptr = strchr(sptr,':')))
				m = s = 0;
			else
			{
				sptr++;
				m = atoi(sptr);
				if (!(sptr = strchr(sptr,':')))
					s = 0;
				else
				{
					sptr++;
					s = atoi(sptr);
				}
			}
			switch ( dlen )
			{
			case	1	:
				*(dptr++) = h;
				break;
			case	2	:
				*(dptr++) = h;
				*(dptr++) = m;
				break;
			case	3	:
			case	4	:
				*(dptr++) = h;
				*(dptr++) = m;
				*(dptr++) = s;
				break;
			case	6	:
				sprintf(buffer,"%02u%02u%02u",h,m,s);
				memcpy(dptr,buffer,dlen);
				break;
			}
			return(dlen);
		case	_INXS_FLOAT	:
			dvalue = strtod(sptr,&final);
			sprintf(buffer,"%f",dvalue);
			sptr = buffer;
		case	_INXS_BCD	:
			memset(dptr,0x00FF,dlen);
			atobcd(sptr,dptr,dlen,strlen(sptr));
			return(dlen);
		default			:
			return(0);
		}
	}
}

/*	-----------	*/
/*	trim_length	*/
/*	-----------	*/
private	int	trim_length(char * dptr, int dlen )
{
	int	i;
	int	l;
	for ( i=0,l=0; i < dlen; i++ )
		if ( *(dptr+i) != ' ' )
			l = (i+1);
	return(l);
}

/*	---------	*/
/*	all_white	*/
/*	---------	*/
private	int	all_white(char * dptr, int dlen )
{
	while ( dlen-- > 0 )
		if ( *(dptr++) != ' ' )
			return(0);

	return(1);
}

/*	--------------------------	*/
/*	inxsql_primary_field_value	*/
/*	--------------------------	*/
public	int	inxsql_primary_field_value(struct xs_field * cptr, char * query, int offset, unsigned char * dptr, int dlen, int align)
{
	int	slen;
	int	xlen=0;
	int	rlen=0;
	int	c;
	if ( cptr->type == _INXS_STRING )
	{
		switch ( align )
		{
		case	_INXS_LKEY	: 
			// step of leading space
			xlen = 0;
			while ( *dptr == ' ' )
			{
				dptr++;
				dlen--;
				xlen++;
			}
		case	_INXS_BKEY	: 
			query[offset++] = 0x27;
			for (	slen = (cptr->size>dlen?dlen:cptr->size); slen > 0; slen--)
			{
				switch ((c = *(dptr++)))
				{
				case	' '	:
					if ( all_white( dptr, (slen-1) ) )
						break;	
				case	0x005C	: // the back slash character
				case	0	:
				case	'"'	:
					query[offset++] = '\\';
				default		:	
					offset += inxsql_to_unicode(query+offset,(c & 0x00FF));
					continue;
				}
				break;
			}
			// space fill if LKEY 
			while ( xlen > 0 )
			{
				query[offset++] = ' ';
				xlen--;
			}
			query[offset++] = 0x27;
			return( offset );
			break;
		case	_INXS_NOKEY	: 
			query[offset++] = 0x27;
			if ((slen = strlen(dptr)) > cptr->size) { slen =  cptr->size; }
			for ( 	xlen = 0; xlen < slen; xlen++ )
			{
				switch ((c = *(dptr++)))
				{
				case	' '	:
					if ( all_white( dptr, (slen-(xlen+1)) ) )
						break;	
				case	0x005C	: // the back slash character
				case	'"'	:
					query[offset++] = '\\';
				default		:	
					offset += inxsql_to_unicode(query+offset,(c & 0x00FF));
					continue;
				}
				break;
			}
#ifdef	POST_KEY_FILL_WITH_SPACE 
			// this causes problems for UP / DOWN
			for ( ; slen < cptr->size; slen++ ) 
				query[offset++] = ' ';
#endif
			query[offset++] = 0x27;
			return( offset );
		case	_INXS_RKEY	:
			query[offset++] = 0x27;
			if ((slen = strlen(dptr)) > cptr->size) { slen =  cptr->size; }
			for (	xlen = (cptr->size - slen); xlen > 0; xlen-- ) 
				query[offset++] = ' ';
			for ( 	xlen = 0; xlen < slen; xlen++ ) 
			{
				switch ((c = *(dptr++)))
				{
				case	0x005C	: // the back slash character
				case	'"'	:
					query[offset++] = '\\';
				default		:	
					offset += inxsql_to_unicode(query+offset,(c & 0x00FF));
				}
			}
			query[offset++] = 0x27;
			return( offset );
		default			:
			return(0);
		}
	}
	else if (( cptr->type == _INXS_BIN    )
	     ||  ( cptr->type == _INXS_VARBIN ))
	{
		switch ( inxsql_engine() )
		{
#ifdef	_INXSQL_MYSQL
		case	_INXSQL_MYSQL_ENGINE	:
			query[offset++] = '0';
			query[offset++] = 'x';
			break;
#endif
#ifdef	_INXSQL_PGSQL
		case	_INXSQL_PGSQL_ENGINE	:
			query[offset++] = 0x27;
			query[offset++] = '\\';
			query[offset++] = 'x';
			break;
#endif
		}
		for (	slen = 0; slen < dlen; slen++)
		{
			if (((c = *(dptr++)) & 0x00F0) > 0x0090)
				query[offset++] = (((c >> 4)-10) + 'A');
			else	query[offset++] = ((c >> 4) + '0');
				
			if ((c & 0x000F) > 0x0009)
				query[offset++] = (((c & 0x00F)-10) + 'A');
			else	query[offset++] = ((c & 0x00F) + '0');
		}
		switch ( inxsql_engine() )
		{
#ifdef	_INXSQL_PGSQL
		case	_INXSQL_PGSQL_ENGINE	:
			query[offset++] = 0x27;
#endif
		}
		return( offset );
	}
	else	return(0);
}

#include "inxsql_unicodes.h"

/*	--------------------	*/
/*	inxsql_unicode_index	*/
/*	--------------------	*/
private	unsigned int inxsql_unicode_index( unsigned int v )
{
	unsigned int i;
	for ( i=0; i < 128; i++ )
		if (unicodes[i] == v)
			return( i + 128 );
	return(0);
}

/*	-------------------	*/
/*	inxsql_from_unicode	*/
/*	-------------------	*/
private	unsigned int inxsql_from_unicode( struct xs_convertor * xptr )
{
	char * bptr;
	unsigned int	v;
	if (!( xptr ))
		return(0);
	else if (!( xptr->length ))
		return(0);
	else if (!( bptr = xptr->buffer ))
		return((xptr->length=0));
	else if (!( *bptr ))
		return((xptr->length=0));
	else if (!( (v = (*(bptr++) & 0x00FF)) & 0x0080 ))
	{
		xptr->length--;
		xptr->buffer = bptr;
		return(v);
	}
	else if (!( v & 0x20 ))
	{
		// two byte code
		v = (( (v & 0x001F) << 6) | ( *(bptr++) & 0x003F ));
		xptr->length -= 2;
		xptr->buffer = bptr;
		return(inxsql_unicode_index(v));
	}
	else if (!( v & 0x10 ))
	{
		// three byte code
		v = (( (v&0x00F) << 6) | ( *(bptr++) & 0x003F ));
		v = ((v << 6) | ( *(bptr++) & 0x003F ));
		xptr->length -= 3;
		xptr->buffer = bptr;
		return(inxsql_unicode_index(v));
	}
	else
	{
		// four byte code
		v = (( (v&7) << 6) | ( *(bptr++) & 0x003F ));
		v = ((v << 6) | ( *(bptr++) & 0x003F ));
		v = ((v << 6) | ( *(bptr++) & 0x003F ));
		xptr->length -= 4;
		xptr->buffer = bptr;
		return(inxsql_unicode_index(v));
	}
}

/*      -----------------       */
/*      inxsql_to_unicode       */
/*      -----------------       */
private unsigned int inxsql_to_unicode(unsigned char * bptr,unsigned int value)
{
        unsigned int i=0;
	if (!( value ))
		return( 0 );
	else if ( value < 0x0080 ) 
	{
		*bptr = value;
		return(1);
	}
	else if (( value = unicodes[(value - 0x0080)] ) < 0x0080)
	{
		*bptr = value;
		return(1);
	}
	else if (!( value & 0x2000 ))
	{
		/* two byte sequence */
		*(bptr++) = (0x00C0 | ((value >> 6) & 0x001F));
		*(bptr++) = (0x0080 | (value & 0x003F));
        	return( 2 );
	}
	else if (!( value & 0x4000 ))
	{
		/* three byte sequence */
		*(bptr++) = (0x00E0 | ((value >> 12) & 0x000F));
		*(bptr++) = (0x0080 | ((value >> 6) & 0x003F));
		*(bptr++) = (0x0080 | (value & 0x003F));
        	return( 3 );
	}
	else
	{
		/* four byte sequence */
		*(bptr++) = (0x00F0 | ((value >> 18) & 0x0007));
		*(bptr++) = (0x0080 | ((value >> 12) & 0x003F));
		*(bptr++) = (0x0080 | ((value >> 6) & 0x003F));
		*(bptr++) = (0x0080 | (value & 0x003F));
        	return( 4 );
	}
}

#ifdef	DEBUG_PREPARED_STATEMENT
/*	---------	*/
/*	dump_zone	*/
/*	---------	*/
private	void	dump_zone(char * msg, unsigned char * sptr, int slen)
{
	int	i;
	fprintf(stderr,"%s : 0x%08X (%u): [",msg,sptr,slen);
	for ( i=0; i < slen; i++ ) fprintf(stderr,"%02X ",*(sptr+i));
	fprintf(stderr,"]\n");
}
#endif

#ifdef	_INXSQL_MYSQL
/*	----------------	*/
/*	inxsql_set_field	*/
/*	----------------	*/
public	int	inxsql_set_field(  struct xs_field * cptr, MYSQL_BIND *    bptr, unsigned char * sptr, unsigned char * rptr )
{
	int	slen;
	int	tlen;
	unsigned long int rlen;
	int	i;
	int	y,m,d,h,s;
	char *	wptr;
	char	buffer[256];
	MYSQL_TIME t;

	if (!( slen = inxsql_field_size(cptr)))
		return(0);
	else
	{
#ifdef	DEBUG_PREPARED_STATEMENT
		fprintf(stderr,"bind : %s:%u, s=%u, l=%u [0x%08X] \n",cptr->name,cptr->type,cptr->size,slen,bptr->buffer); 
		dump_zone("from",sptr,cptr->size);
#endif

		switch ( cptr->type )
		{
		case	_INXS_INT8	:
			*rptr = *sptr;
#ifdef	DEBUG_PREPARED_STATEMENT
			dump_zone("zone",rptr,slen);
#endif
			return(slen);
		case	_INXS_INT16	:
			*rptr = *(sptr+1);
			*(rptr+1) = *sptr;
#ifdef	DEBUG_PREPARED_STATEMENT
			dump_zone("zone",rptr,slen);
#endif
			return(slen);
		case	_INXS_INT32	:
			*rptr = *(sptr+3);
			*(rptr+1) = *(sptr+2);
			*(rptr+2) = *(sptr+1);
			*(rptr+3) = *sptr;
#ifdef	DEBUG_PREPARED_STATEMENT
			dump_zone("zone",rptr,slen);
#endif
			return(slen);
		case	_INXS_INT64	:
			*rptr = *(sptr+7);
			*(rptr+1) = *(sptr+6);
			*(rptr+2) = *(sptr+5);
			*(rptr+3) = *(sptr+4);
			*(rptr+4) = *(sptr+3);
			*(rptr+5) = *(sptr+2);
			*(rptr+6) = *(sptr+1);
			*(rptr+7) = *sptr;
#ifdef	DEBUG_PREPARED_STATEMENT
			dump_zone("zone",rptr,slen);
#endif
			return(slen);
		case	_INXS_BIN	:
			for ( i=0; i < slen; i++ )
				*(rptr+i) = *(sptr+i);
#ifdef	DEBUG_PREPARED_STATEMENT
			dump_zone("zone",rptr,slen);
#endif
			return(slen);

		case	_INXS_FLOAT	:
			bcdtoa(sptr,slen,buffer,((slen*2)-1));
			if ((wptr = strchr(rptr,',')) != (char *) 0) *wptr = '.';
			sscanf(buffer,"%f",(float*)rptr);
			bptr->buffer_length = inxsql_field_bsize(cptr);
#ifdef	DEBUG_PREPARED_STATEMENT
			dump_zone("zone",rptr,bptr->buffer_length);
#endif
			return(slen);

		case	_INXS_BCD	:
			// convert BCD to ASCII into binding zone
			bcdtoa(sptr,slen,rptr,(slen*2));
			for ( i=0; i < (slen*2); i++ )
			{
				if (!( *(rptr+i) ))
					break;
				else if ( *(rptr+i) == ' ' )
					break;
				else if ( *(rptr+i) == ',' )
					*(rptr+i) = '.';
			}
			*(rptr+i) = 0;	
			bptr->buffer_length = i;
#ifdef	DEBUG_PREPARED_STATEMENT
			dump_zone("zone",rptr,i);
#endif
			return( slen );

		case	_INXS_DATE	:
			memset(&t,0,sizeof(MYSQL_TIME));
			if ( slen < 8 )
			{
				// collect the binary date fields
				if (( t.year = (((*sptr & 0x0FF) << 8) | ( *(sptr+1) & 0x00FF )) ) == 8224)
					t.year = 0;
				if ((t.month = (*(sptr+2) & 0x00FF )) == 32)
					t.month = 0;
				if ((t.day = (*(sptr+3) & 0x00FF )) == 32)
					t.day = 0;
			}
			else
			{
				// collect the ascii date fields
				memcpy(buffer,sptr,4);
				buffer[4] = 0;
				if ((t.year = atoi(buffer)) == 8224)
					t.year = 0;
				memcpy(buffer,sptr+4,2);
				buffer[2] = 0;
				if ((t.month = atoi(buffer)) == 32)
					t.month = 0;
				memcpy(buffer,sptr+6,2);
				buffer[2] = 0;
				if ((t.day = atoi(buffer)) == 32)
					t.day = 0;
			}
			memcpy(rptr,&t,sizeof(MYSQL_TIME));
			bptr->buffer_length = sizeof(MYSQL_TIME);
#ifdef	DEBUG_PREPARED_STATEMENT
			dump_zone("zone",rptr,bptr->buffer_length);
#endif
			return( slen );

		case	_INXS_TIME	:
			memset(&t,0,sizeof(MYSQL_TIME));
			if ( slen < 6 )
			{
				// collect the binary time fields
				t.hour = (*sptr & 0x00FF );
				t.minute = (*(sptr+1) & 0x00FF );
				t.second = (*(sptr+2) & 0x00FF );
			}
			else
			{
				// collect the ascii time fields
				memcpy(buffer,sptr,2);
				buffer[2] = 0;
				t.hour = atoi(buffer);
				memcpy(buffer,sptr+2,2);
				buffer[2] = 0;
				t.minute = atoi(buffer);
				memcpy(buffer,sptr+4,2);
				buffer[2] = 0;
				t.second = atoi(buffer);
			}
			memcpy(rptr,&t,sizeof(MYSQL_TIME));
			bptr->buffer_length = sizeof(MYSQL_TIME);
#ifdef	DEBUG_PREPARED_STATEMENT
			dump_zone("zone",rptr,bptr->buffer_length);
#endif
			return( slen );
			
		case	_INXS_STRING	:

			// remove trailing white space
			tlen = trim_length(sptr, slen);

			// convert PRL to UNICODE into binding zone
			for ( rlen=0, i=0; i < tlen; i++ )
				rlen += inxsql_to_unicode( rptr+rlen, (*(sptr+i) & 0x00FF));

			bptr->buffer_length = rlen;
#ifdef	DEBUG_PREPARED_STATEMENT
			dump_zone("zone",rptr,rlen);
#endif
			return( slen );

		default			:
			return(0);
		}
	}
}
#endif

/*	------------------------	*/
/*	inxsql_reset_field_value	*/
/*	------------------------	*/
public	char *	inxsql_reset_field_value( struct xs_field * cptr, char * vptr, int vlen, int reverse)
{
	if (!( cptr ))
		return( (char *) 0);
	else if (!( vptr ))
		return( vptr );
	else if (!( vlen ))
		return( vptr );
	else
	{
		// initialise the value buffer
		switch ( cptr->type )
		{
		case	_INXS_FLOAT	:
		case	_INXS_BCD	:
			memset(vptr,0x99,vlen);
			if ( reverse )
				*vptr = 0x00C9;
			else	*vptr = 0x00B9;
			return( vptr );
		case	_INXS_STRING	:
			if ( reverse )
				memset(vptr,0x00FE,vlen);
			else 	memset(vptr,' ',vlen);
			return( vptr );
		case	_INXS_DATE	:
		case	_INXS_TIME	:
			memset(vptr,0,vlen);
			return( vptr );
		case	_INXS_INT16	:
		case	_INXS_INT32	:
		case	_INXS_INT64	:
			if ( reverse )
				memset(vptr,0x0000,vlen);
			else	memset(vptr,0x00FF,vlen);
		case	_INXS_INT8	:
			if ( reverse )
				*vptr = 0x007F;
			else	*vptr = 0x0080;
			return( vptr );
		case	_INXS_VARBIN 	:
		case	_INXS_BIN 	:
		default			:
			if ( reverse )
				memset(vptr,0x00FF,vlen);
			else	memset(vptr,0,vlen);
			return( vptr );
		}
	}
}	

/*	-------------------------------------------	*/
/*	i n x s q l _ n e w _ f i e l d _ v a l u e	*/
/*	-------------------------------------------	*/
/*	builds a new current value for column test	*/
/*	in sequential access under positi control.	*/
/*	------------------------------------------	*/
public	char *	inxsql_new_field_value( struct xs_field * cptr, int reverse)
{
	char *	vptr;
	int	vlen;
	// allocate the value buffer
	if (!( vptr = allocate( (vlen = cptr->size) ) ))
		return( vptr );
	else	return( inxsql_reset_field_value( cptr, vptr, vlen, reverse ) );
}

/*	----------------------	*/
/*	inxsql_set_field_value	*/
/*	----------------------	*/
/*	collects data from the	*/
/*	ABAL data buffer zone.	*/
/*	----------------------	*/
public	int	inxsql_set_field_value( struct xs_field * cptr, char * query, int offset, unsigned char * dptr, int dlen, int align, int wild )
{
	int	slen=0;
	int	xlen=0;
	int	c;
	int	y,m,d,hour,s;
	int	waswild=0;

	if ( cptr->type == _INXS_STRING )
	{
		switch ( align )
		{
		case	_INXS_LKEY	: 
			// step of leading space
			xlen = 0;
			while ( *dptr == ' ' )
			{
				dptr++;
				dlen--;
				xlen++;
			}
		case	_INXS_BKEY	: 
			query[offset++] = 0x27;
			for (	slen = (cptr->size>dlen?dlen:cptr->size); slen > 0; slen--)
			{
				switch ((c = *(dptr++)))
				{
				case	0x002A	: // the star character
					if ( wild )
					{
						waswild=1;
						query[offset++] = '%';
					}
					else	query[offset++] = '*';
					continue;
				case	0x0020	: // the space character
					if (!( waswild ))
						query[offset++] = c;
					continue;
					
				case	0x005C	: // ignore the back slash character
					continue;
				case	0	:
				case	'"'	:
					query[offset++] = '\\';
				default		:	
					waswild = 0;
					offset += inxsql_to_unicode(query+offset,(c & 0x00FF));
				}
			}
			// space fill if LKEY 
			while (( xlen > 0 ) && (!( waswild )))
			{
				query[offset++] = ' ';
				xlen--;
			}
			query[offset++] = 0x27;
			return( offset );
			break;
		case	_INXS_NOKEY	: 
			query[offset++] = 0x27;
			if (dlen > cptr->size) { dlen =  cptr->size; }
			for ( 	xlen = 0; xlen < dlen; xlen++ )
			{
				switch ((c = *(dptr++)))
				{
				case	0x002A	: // the star character
					if ( wild )
					{
						waswild=1;
						query[offset++] = '%';
					}
					else	query[offset++] = '*';
					continue;
				case	0x0020	: // the space character
					if ( all_white( dptr, (dlen-(xlen+1)) ) )
						break;	
					else	query[offset++] = c;
					continue;
				case	0x005C	: // ignore the back slash character
					continue;
				case	'"'	:
					query[offset++] = '\\';
				default		:	
					waswild = 0;
					offset += inxsql_to_unicode(query+offset,(c & 0x00FF));
					continue;
				}
				break;
			}
			query[offset++] = 0x27;
			return( offset );
		case	_INXS_RKEY	:
			query[offset++] = 0x27;
			if ((slen = strlen(dptr)) > cptr->size) { slen =  cptr->size; }
			for (	xlen = (cptr->size - slen); xlen > 0; xlen-- ) 
				query[offset++] = ' ';
			for ( 	xlen = 0; xlen < slen; xlen++ ) 
			{
				switch ((c = *(dptr++)))
				{
				case	0x002A	: // the star character
					if ( wild )
					{
						waswild=1;
						query[offset++] = '%';
					}
					else	query[offset++] = '*';
					continue;
				case	0x0020	: // the space character
					if (!( waswild ))
						query[offset++] = c;
					continue;
				case	0x005C	: // ignore the back slash character
					continue;
				case	'"'	:
					query[offset++] = '\\';
				default		:	
					waswild = 0;
					offset += inxsql_to_unicode(query+offset,(c & 0x00FF));
				}
			}
			query[offset++] = 0x27;
			return( offset );
		default			:
			return(0);
		}
	}
	else if (( cptr->type == _INXS_BIN    )
	     ||  ( cptr->type == _INXS_VARBIN ))
	{
		// ----------------------------------------
		// prepare the 0x prefixed HEX binary value
		// ----------------------------------------
		switch ( inxsql_engine() )
		{
#ifdef	_INXSQL_MYSQL
		case	_INXSQL_MYSQL_ENGINE	:
			query[offset++] = '0';
			query[offset++] = 'x';
			break;
#endif
#ifdef	_INXSQL_PGSQL
		case	_INXSQL_PGSQL_ENGINE	:
			query[offset++] = 0x27;
			query[offset++] = '\\';
			query[offset++] = 'x';
			break;
#endif
		}
		for (	slen = 0; slen < dlen; slen++)
		{
			if (((c = *(dptr++)) & 0x00F0) > 0x0090)
				query[offset++] = (((c >> 4)-10) + 'A');
			else	query[offset++] = ((c >> 4) + '0');
			
			if ((c & 0x000F) > 0x0009)
				query[offset++] = (((c & 0x00F)-10) + 'A');
			else	query[offset++] = ((c & 0x00F) + '0');
		}
		switch ( inxsql_engine() )
		{
#ifdef	_INXSQL_PGSQL
		case	_INXSQL_PGSQL_ENGINE	:
			query[offset++] = 0x27;
#endif
		}
		return( offset );
	}
	else
	{
		char	buffer[256];
		short int w=0;
		char 	b=0;
		int	i=0;
		long long h=0;
		switch ( cptr->type )
		{
		case	_INXS_INT8	:
			b = *dptr;
			sprintf(buffer,"%d",b);
			break;
		case	_INXS_INT16	:
			w = (((*dptr & 0x00FF) << 8) | ( *(dptr+1) & 0x0FF));
			sprintf(buffer,"%d",w);
			break;
		case	_INXS_INT32	:
			i = ( ((*dptr & 0x00FF) << 24) | ((*(dptr+1) & 0x00FF) << 16) | ((*(dptr+2) & 0x00FF) << 8) | ( *(dptr+3) & 0x0FF));
			sprintf(buffer,"%d",i);
			break;
		case	_INXS_INT64	:
			h = (	(((unsigned long long)(*(dptr+0) & 0x00FF)) << 56) | 
				(((unsigned long long)(*(dptr+1) & 0x00FF)) << 48) |
				(((unsigned long long)(*(dptr+2) & 0x00FF)) << 40) |
				(((unsigned long long)(*(dptr+3) & 0x00FF)) << 32) |
				(((unsigned long long)(*(dptr+4) & 0x00FF)) << 24) |
				(((unsigned long long)(*(dptr+5) & 0x00FF)) << 16) |
				(((unsigned long long)(*(dptr+6) & 0x00FF)) <<  8) |
				(((unsigned long long)(*(dptr+7) & 0x00FF)) <<  0) 	);
			sprintf(buffer,"%lld",h);
			break;
		case	_INXS_DATE	:
			if ( dlen < 8 )
			{
				// collect the binary date fields
				if ((y = (((*dptr & 0x0FF) << 8) | ( *(dptr+1) & 0x00FF ))) == 8224)
					y = 0;

				if ((m = (*(dptr+2) & 0x00FF )) == 32)
					m = 0;
				
				if ((d = (*(dptr+3) & 0x00FF )) == 32)
					d = 0;
			}
			else 
			{
				// collect the ascii date fields
				memcpy(buffer,dptr,4);
				buffer[4] = 0;
				y = atoi(buffer);
				memcpy(buffer,dptr+4,2);
				buffer[2] = 0;
				m = atoi(buffer);
				memcpy(buffer,dptr+6,2);
				buffer[2] = 0;
				d = atoi(buffer);
			}
			// generate the ASCII SQL Date Value
			switch ( dlen )
			{
			case	2	:
				sprintf(buffer,"'%04u'",y);
				break;
			case	3	:
				sprintf(buffer,"'%04u-%02u'",y,m);
				break;
			case	4	:
			case	8	:
			default		:
				sprintf(buffer,"'%04u-%02u-%02u'",y,m,d);
				break;
			}
			break;

		case	_INXS_TIME	:
			// 6 bytes is ASCII, 3,2,1 is Binary
			if ( dlen < 4 )
			{
				// collect the binary time fields
				hour = (*dptr & 0x00FF );
				m = (*(dptr+1) & 0x00FF );
				s = (*(dptr+2) & 0x00FF );
			}
			else 
			{
				// collect the ascii time fields
				memcpy(buffer,dptr,2);
				buffer[2] = 0;
				hour = atoi(buffer);
				memcpy(buffer,dptr+2,2);
				buffer[2] = 0;
				m = atoi(buffer);
				memcpy(buffer,dptr+4,2);
				buffer[2] = 0;
				s = atoi(buffer);
			}
			// generate the ASCII SQL Time Value
			switch ( dlen )
			{
			case	1	:
				sprintf(buffer,"'%02u'",hour);
				break;
			case	2	:
			case	4	:
				sprintf(buffer,"'%02u:%02u'",hour,m);
				break;
			case	3	:
			case	6	:
			default		:
				sprintf(buffer,"'%02u:%02u:%02u'",hour,m,s);
				break;
			}
			break;

		case	_INXS_BCD	:
			memset(buffer,0,(dlen*2));
			bcdtoa(dptr,dlen,buffer,((dlen*2)-1));
			for ( i = 0; i < (dlen*2); i++)
			{
				if ( buffer[i] == ',' )
					buffer[i] = '.';
				else if ( buffer[i] == ' ' )
					buffer[i] = 0;
			}
			dlen = strlen(buffer);
			break;
		default	:
			return(0);
		}
		/* ----------------- */
		/* transfer to query */
		/* ----------------- */
		for ( i=0; buffer[i] != 0; i++ )
			query[offset++] = buffer[i];
		return( offset );
	}
}

/*	-------------------	*/
/*	inxsql_rename_field	*/
/*	-------------------	*/
public	int	inxsql_rename_field( struct xs_file * fptr, char * oldname, char * newname )
{
	char *	nptr;
	int	status;
	char *	xptr;
	struct  xs_field * cptr;
	char	query[_STD_QUERY_LENGTH];
	if ( verbose ) printf("inxsql_rename_field( %s, %s, %s )\r\n",fptr->name,oldname,newname);
	if (!( nptr = allocate_column_name( oldname, _STD_KEY_LENGTH ) ))
		return( _ERROR_MEMORY);
	else if (!( cptr = inxsql_locate_field( fptr, nptr ) ))
	{
		liberate( nptr );
		return( _ERROR_KEY_NOT_FOUND );
	}
	else
	{
		liberate( nptr );
		if (!( nptr = allocate_column_name( newname, _STD_KEY_LENGTH ) ))
			return( _ERROR_MEMORY);
		else
		{
			xptr = cptr->name;
			cptr->name = nptr;
			sprintf(query,"ALTER TABLE %s RENAME COLUMN %s AS ",inxsql_table_name(fptr),inxsql_field_name(xptr));
			strcat(query,inxsql_field_name(cptr->name));
			liberate( xptr );
			if (( status = inxsql_use_database( fptr->connection, fptr->base )) != _SUCCESS)
				return(status);
			else	return(inxsql_query(fptr->connection, query, strlen(query) ));
		}
	}
}

/*	-------------------	*/
/*	inxsql_abal_keytype	*/
/*	-------------------	*/
/*	returns the useful	*/
/*	ABAL KEY TYPE code.	*/
/*	-------------------	*/
private	int	inxsql_abal_keytype(int type)
{
	switch ( type )
	{
	case	_INXS_INT8	: 
	case	_INXS_INT16	: return( 'N' );
	case	_INXS_INT32	: return( 'L' );
	case	_INXS_INT64	: return( 'H' );
	case	_INXS_BCD	: return( 'B' );
	case	_INXS_FLOAT	: return( 'F' );
	case	_INXS_STRING	: return( 'S' );
	case	_INXS_DATE	: return( 'D' );
	case	_INXS_TIME	: return( 'T' );
	case	_INXS_BIN	: 
	case	_INXS_VARBIN	: 
	default			: return( 'A' );
	}
}

/*	-------------------	*/
/*	inxsql_list_columns	*/
/*	-------------------	*/
public	int	inxsql_list_columns(struct xs_file * fptr, char * dptr, int dlen, int mode )
{
        char *  vptr;
        int     vlen;
	int	size=0;
        /* ---------------------------- */
        /* determine first or next mode */
        /* ---------------------------- */
        switch ( mode )
        {
        case    0       : /* FIRST      */
                if (!( fptr->current = fptr->first ))
                        return(_ERROR_END_OF_FILE);
                else    break;
        case    1       : /* NEXT       */
                if (!( fptr->current ))
                        return(_ERROR_END_OF_FILE);
                else if (!( fptr->current = fptr->current->next ))
                        return(_ERROR_END_OF_FILE);
                else    break;
        }

        /* --------------------------------- */
        /* generate the resulting databuffer */
        /* --------------------------------- */
        if (!( fptr->current ))
                return(_ERROR_END_OF_FILE);
        else if (!( vptr = fptr->current->name))
                return(_ERROR_END_OF_FILE);
        else    memset(dptr,' ',dlen);

        /* ------------------- */
        /* put the column name */
        /* ------------------- */
	for ( vlen = 0; vlen < fptr->maxkey ; vlen++ )
		if ( *vptr != 0 )
			dptr[vlen] = *(vptr++);

	size = inxsql_field_size(fptr->current);

	dptr[fptr->maxkey] = ((size & 0x00FF00) >> 8);
	dptr[fptr->maxkey+1] = (size & 0x00FF);
	dptr[fptr->maxkey+2] = inxsql_abal_keytype(fptr->current->type);
	size = fptr->current->offset;
	dptr[fptr->maxkey+3] = ((size & 0x00FF00) >> 8);
	dptr[fptr->maxkey+4] = (size & 0x00FF);

	if ( dlen > (fptr->maxkey+5) )
	{
		dptr += (fptr->maxkey+5);
		dlen -= fptr->maxkey;
		while (( *vptr != 0 ) && ( dlen != 0 ))
		{
			*(dptr++) = *(vptr++);
			dlen--;
		}
	}

	return( _SUCCESS );
}

	/* --------------- */
#endif	/* _inxsql_field_c */
	/* --------------- */
