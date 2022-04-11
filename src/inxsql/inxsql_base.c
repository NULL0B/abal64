#ifndef	_inxsql_base_c
#define	_inxsql_base_c

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

#undef	INXSQL_DEBUG_BASE

/*	----------------------	*/
/*	inxsql_database_engine	*/
/*	----------------------	*/
public	int	inxsql_database_engine(int engine)
{
	char *	eptr;
	if (!( eptr = getenv("INXSTYPE")))
		return( engine );
#ifdef	_INXSQL_MYSQL_ENGINE
	else if (!( strcasecmp( eptr, "MYSQL" ) ))
		return( _INXSQL_MYSQL_ENGINE );
#endif
#ifdef	_INXSQL_PGSQL_ENGINE
	else if (!( strcasecmp( eptr, "PGSQL" ) ))
		return( _INXSQL_PGSQL_ENGINE );
#endif
#ifdef	_INXSQL_ORACLE_ENGINE
	else if (!( strcasecmp( eptr, "ORACLE" ) ))
		return( _INXSQL_ORACLE_ENGINE );
#endif
#ifdef	_INXSQL_SQLITE_ENGINE
	else if (!( strcasecmp( eptr, "SQLITE" ) ))
		return( _INXSQL_SQLITE_ENGINE );
#endif
#ifdef	_INXSQL_SQLSERVER_ENGINE
	else if (!( strcasecmp( eptr, "SQLSERVER" ) ))
		return( _INXSQL_SQLSERVER_ENGINE );
#endif
	else	return( engine );
}

/*	-------------------------	*/
/*	 inxsql_database_engines	*/
/*	-------------------------	*/
/*	called from EXA MAIN INFO	*/
/*	-------------------------	*/
private	char 	engines[512];
public	char * inxsql_database_engines()
{
	int	engine=inxsql_database_engine(_INXSQL_DEFAULT_ENGINE);
	engines[0]= 0;
#ifdef	_INXSQL_MYSQL_ENGINE
	if ( engine == _INXSQL_MYSQL_ENGINE )
		strcat(engines,"MYSQL ");
	else	strcat(engines,"mysql ");
#endif
#ifdef	_INXSQL_PGSQL_ENGINE
	if ( engine == _INXSQL_PGSQL_ENGINE )
		strcat(engines,"PGSQL ");
	else	strcat(engines,"pgsql ");
#endif
#ifdef	_INXSQL_ORACLE_ENGINE
	if ( engine == _INXSQL_ORACLE_ENGINE )
		strcat(engines,"ORACLE ");
	else	strcat(engines,"oracle ");
#endif
#ifdef	_INXSQL_SQLITE_ENGINE
	if ( engine == _INXSQL_SQLITE_ENGINE )
		strcat(engines,"SQLITE ");
	else	strcat(engines,"sqlite ");
#endif
#ifdef	_INXSQL_SQLSERVER_ENGINE
	if ( engine == _INXSQL_SQLSERVER_ENGINE )
		strcat(engines,"SQLSERVER ");
	else	strcat(engines,"sqlserver ");
#endif
	return( engines );
}

/*	------------------------	*/
/*	 inxsql_database_create 	*/
/*	------------------------	*/
private	int	inxsql_database_create( struct xs_connection * xptr, char * name )
{
	char 	query[_STD_QUERY_LENGTH];
	switch ( xptr->engine )
	{
#ifdef	_INXSQL_MYSQL
	case	_INXSQL_MYSQL_ENGINE	:
		sprintf(query,"CREATE DATABASE %s CHARACTER SET %s COLLATE %s_0900_as_cs",name,_INXS_CHAR_SET,_INXS_CHAR_SET);
		break;
#endif
#ifdef	_INXSQL_PGSQL
	case	_INXSQL_PGSQL_ENGINE	:
		sprintf(query,"CREATE DATABASE %s WITH ENCODING '%s' COLLATE 'en_GB.%s'",name,_INXS_CHAR_SET,_INXS_CHAR_SET);
		break;
#endif
	default				:
		sprintf(query,"CREATE DATABASE %s",name);
		break;
	}
	if (!( inxsql_query( xptr, query, strlen(query))))
		return(_SUCCESS);
	else	return(_ERROR_FILE_EXISTS);
}

/*	--------------------------	*/
/*	inxsql_liberate_connection	*/
/*	--------------------------	*/
private struct xs_connection * inxsql_liberate_connection( struct xs_connection * xptr )
{
	if ( xptr )
	{
		if ( xptr->host )
			xptr->host = liberate( xptr->host );
		if ( xptr->base )
			xptr->base = liberate( xptr->base );
		if ( xptr->user )
			xptr->user = liberate( xptr->user );
		if ( xptr->pass )
			xptr->pass = liberate( xptr->pass );

		if ( xptr->certificate )
			xptr->certificate = liberate( xptr->certificate );
		if ( xptr->privatekey )
			xptr->privatekey = liberate( xptr->privatekey );
		if ( xptr->authority )
			xptr->authority = liberate( xptr->authority );

		xptr = liberate( xptr );
	}
	return( (struct xs_connection *) 0 );
}

#ifdef	_INXSQL_PGSQL
/*	----------------------	*/
/*	pgsql_connect_database	*/
/*	----------------------	*/
private	int	pgsql_connect_database( struct xs_connection * xptr, int flags )
{
	char 	buffer[2048];

	/* --------------------------------------- */
	/* attempt connection to required database */
	/* --------------------------------------- */
	sprintf(buffer,"host = %s dbname = %s user = %s password = %s",
		xptr->host,
		xptr->base,
		xptr->user,
		xptr->pass);

	/* -------------------------------- */
	/* attempt connection to postgresql */
	/* -------------------------------- */
	if (!( xptr->handle = PQconnectdb(buffer) ))
		return( _ERROR_MYSQL_CONNECT );

	/* ----------------------- */
	/* check connection status */
	/* ----------------------- */
	else if ( PQstatus( xptr->handle ) != CONNECTION_OK)
	{
		PQfinish( xptr->handle );
		xptr->handle = (void *) 0;
		return( _ERROR_MYSQL_CONNECT );
	}
	else
	{
		xptr->version = PQserverVersion(xptr->handle);
		return(_SUCCESS);
	}
}
#endif

#ifdef	_INXSQL_MYSQL
/*	----------------------	*/
/*	mysql_connect_database	*/
/*	----------------------	*/
private	int	mysql_connect_database( struct xs_connection * xptr, int flags )
{
	int	option=1;
	void * 	handle=(void *) 0;
	char	query[256];

	/* -------------------------- */
	/* reset the database library */
	/* -------------------------- */
	if ( flags & _INXS_INIT )
		mysql_library_init(0,(void*) 0,(void*)0);

	/* -------------------------- */
	/* allocate a MYSQL Structure */
	/* -------------------------- */
	if (!( xptr->handle = mysql_init((MYSQL *) 0) ))
		return( _ERROR_MYSQL_INIT );

	/* -------------------------- */
	/* set the connection options */
	/* -------------------------- */
	else if ( mysql_options( xptr->handle, MYSQL_OPT_RECONNECT, (const void *)&option ) != _SUCCESS)
		return( _ERROR_MYSQL_OPTION );
	else if ( mysql_options( xptr->handle, MYSQL_OPT_SSL_MODE, (const void *)&xptr->tls) != _SUCCESS)
		return( _ERROR_MYSQL_OPTION );
	else if ( xptr->tls != SSL_MODE_DISABLED )
	{
		/* ---------------------------- */
		/* set the security credentials */
		/* ---------------------------- */
		if (( xptr->authority )
		&&  ( mysql_options( xptr->handle, MYSQL_OPT_SSL_CA, (const void *)xptr->authority) != _SUCCESS))
			return( _ERROR_MYSQL_OPTION );
		if (( xptr->authority )
		&&  ( mysql_options( xptr->handle, MYSQL_OPT_SSL_CERT, (const void *)xptr->certificate) != _SUCCESS))
			return( _ERROR_MYSQL_OPTION );
		if (( xptr->authority )
		&&  ( mysql_options( xptr->handle, MYSQL_OPT_SSL_KEY, (const void *)xptr->privatekey) != _SUCCESS))
			return( _ERROR_MYSQL_OPTION );
	}

	/* ----------------------------------- */
	/* open the connection to the endpoint */
	/* ----------------------------------- */
	if (!( handle = mysql_real_connect( xptr->handle, xptr->host, xptr->user, xptr->pass, (char *) 0 , 0, 0, 
		CLIENT_REMEMBER_OPTIONS | CLIENT_FOUND_ROWS ) ))
	{
		inxsql_log_query_failure( xptr, "real_connect");
		return( _ERROR_MYSQL_CONNECT );
	}
	else 
	{
		// set the current character set
		if ( mysql_set_character_set(xptr->handle,_INXS_CHAR_SET) != _SUCCESS )
			return( _ERROR_MYSQL_CHARSET);

		// set the NAMES value to the CHARSET
		sprintf(query,"SET NAMES '%s'",_INXS_CHAR_SET);
		if ( inxsql_query( xptr, query, strlen(query)) != _SUCCESS )
			return( _ERROR_MYSQL_NAMES);

		// set the required MODES
		sprintf(query,"SET SESSION sql_mode = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,ALLOW_INVALID_DATES,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION'");
		if ( inxsql_query( xptr, query, strlen(query)) != _SUCCESS )
			return( _ERROR_MYSQL_MODE );

		// return the connection if no select
		else if (!( flags & _INXS_SELECT ))
			return(_SUCCESS);

		// ensure the database exists 
		else if ( mysql_select_db( xptr->handle, xptr->base ) != _SUCCESS )
			return( _ERROR_MYSQL_SELECT );
		else	return(_SUCCESS);
	}
}
#endif

/*	-----------------------	*/
/*	inxsql_connect_database	*/
/*	-----------------------	*/
public	int	inxsql_connect_database( struct xs_connection * xptr, int flags )
{
	if ( verbose ) printf("inxsql_connect_database()\n");

	/* --------------------------------- */
	/* ensure clean connection structure */
	/* --------------------------------- */
	xptr->first = xptr->last = (struct xs_file *) 0;

	/* ------------------------------- */
	/* ensure connection host is valid */
	/* ------------------------------- */
	if (!( xptr->host ))
	{
		if (!( xptr->host = allocate( strlen( _LOCAL_HOST ) + 1 ) ))
			return( _ERROR_MEMORY);
		else	strcpy( xptr->host, _LOCAL_HOST );
	}

	/* ----------------------------------- */
	/* ensure connection database is valid */
	/* ----------------------------------- */
	if (!( xptr->base ))
	{
		if (!( xptr->base = allocate( strlen( _LOCAL_BASE ) + 1 ) ))
			return( _ERROR_MEMORY);
		else	strcpy( xptr->base, _LOCAL_BASE );
	}

	/* ----------------------------------- */
	/* ensure the connection user is valid */
	/* ----------------------------------- */
	if (!( xptr->user ))
	{
		if (!( xptr->user = allocate( strlen( _LOCAL_USER ) + 1 ) ))
			return( _ERROR_MEMORY);
		else	strcpy( xptr->user, _LOCAL_USER );
	}

	/* --------------------------------------- */
	/* ensure the connection password is valid */
	/* --------------------------------------- */
	if (!( xptr->pass ))
	{
		if (!( xptr->pass = allocate( strlen( _LOCAL_PASS ) + 1 ) ))
			return( _ERROR_MEMORY);
		else	strcpy( xptr->pass, _LOCAL_PASS );
	}

	/* ----------------------------------- */
	/* ensure the connection port is valid */
	/* ----------------------------------- */
	if (!( xptr->port))
		xptr->port = _LOCAL_PORT;


	/* ----------------------------------- */
	/* perform the engine specific connect */
	/* ----------------------------------- */
	switch ( xptr->engine )
	{
#ifdef	_INXSQL_MYSQL
	case	_INXSQL_MYSQL_ENGINE	:
		return( mysql_connect_database( xptr, flags ) );
#endif
#ifdef	_INXSQL_PGSQL
	case	_INXSQL_PGSQL_ENGINE	:
		return( pgsql_connect_database( xptr, flags ) );
#endif
	default				:
		return( _ERROR_MYSQL_INIT );
	}
}

/*	------------------------	*/
/*	inxsql_liberate_database	*/
/*	------------------------	*/
public	struct xs_base * inxsql_liberate_database( struct xs_base * bptr )
{
	struct	xs_connection * xptr;
	struct	xs_view * vptr;
	struct	xs_file * fptr;
	struct	xs_joint * jptr;

	if ( bptr != (struct xs_base *) 0 )
	{
		/* ----------------------- */
		/* release the table views */
		/* ----------------------- */
		while ((vptr = bptr->firstview) != (struct xs_view *) 0)
		{
			if (!( bptr->firstview = vptr->next ))
				bptr->lastview = (struct xs_view *) 0;
			else    vptr->next->previous = vptr->previous;
			vptr->previous = vptr->next = (struct xs_view *) 0;
			vptr->base = (struct xs_base *) 0;
			vptr = inxsql_liberate_view( vptr );
		}

		/* ----------------------- */
		/* release the table joint */
		/* ----------------------- */
		while ((jptr = bptr->firstjoint) != (struct xs_joint *) 0)
		{
			if (!( bptr->firstjoint = jptr->next ))
				bptr->lastjoint = (struct xs_joint *) 0;
			else    jptr->next->previous = jptr->previous;
			jptr->previous = jptr->next = (struct xs_joint *) 0;
			jptr->base = (struct xs_base *) 0;
			jptr = inxsql_liberate_joint( jptr );
		}

		/* --------------------------------------------- */
		/* remove the tables and file control structures */
		/* --------------------------------------------- */
		while ((fptr = bptr->first) != (struct xs_file *) 0)
		{
			if (!(bptr->first = fptr->next))
				bptr->last = (struct xs_file *) 0;
			else	fptr->next->previous = fptr->previous;
			fptr->previous = fptr->next = (struct xs_file *) 0;
			fptr->base = (struct xs_base *) 0;
			fptr->connection = (struct xs_connection *) 0;
			fptr = inxsql_liberate_file(fptr);
		}

		/* ---------------------------------------- */
		/* remove from the connection database list */
		/* ---------------------------------------- */
		if ((xptr =  bptr->connection ) != (struct xs_connection *) 0)
		{
			if (!( bptr->previous ))
				xptr->firstbase = bptr->next;
			else	bptr->previous->next = bptr->next;
			if (!( bptr->next ))
				xptr->lastbase = bptr->previous;
			else	bptr->next->previous = bptr->previous;
		}

		/* ------------------------- */
		/* release the database name */
		/* ------------------------- */
		if ( bptr->name )
			bptr->name = liberate( bptr->name );

		/* --------------------------- */
		/* release an owned connection */
		/* --------------------------- */
		if ( bptr->owner )
		{
			inxsql_close_connection( bptr->owner );
			bptr->owner = inxsql_liberate_connection( bptr->owner );
		}

		/* ----------------------------- */
		/* liberate the database control */
		/* ----------------------------- */
#ifdef	INXSQL_DEBUG_BASE
		printf("INXSQLDBG:remove_base:liberate_database( %llx )\n",(unsigned long long)bptr);
#endif
		bptr = liberate(bptr);

	}
	return((struct xs_base *) 0);
}

/*	---------------------	*/
/*	inxsql_close_database	*/
/*	---------------------	*/
private	void	inxsql_close_database(struct xs_connection * xptr)
{
	if ( xptr )
	{
		switch ( xptr->engine )
		{
#ifdef	_INXSQL_MYSQL
		case	_INXSQL_MYSQL_ENGINE	:
			/* ---------------------------- */
			/* drop the database connection */
			/* ---------------------------- */
			mysql_close(xptr->handle);
			xptr->handle = (void *) 0;

			/* -------------------------- */
			/* reset the database library */
			/* -------------------------- */
			mysql_library_end();
			break;
#endif
#ifdef	_INXSQL_PGSQL
		case	_INXSQL_PGSQL_ENGINE	:
			PQfinish( xptr->handle );
			xptr->handle = (void *) 0;
			break;
#endif
		}
	}
	return;
}

/*	-----------------------	*/
/*	inxsql_close_connection */
/*	-----------------------	*/
public	int	inxsql_close_connection( struct xs_connection * xptr )
{
	struct	xs_file * fptr;
	struct	xs_base * bptr;

	if ( verbose ) printf("inxsql_close_connection()\n");

	/* --------------------------- */
	/* release the database tables */
	/* --------------------------- */
	while ((fptr = xptr->first) !=(struct xs_file *) 0)
	{
		if (!( xptr->first = fptr->next ))
			xptr->last = (struct xs_file *) 0;
		else	fptr->next->previous = fptr->previous;
		fptr->previous = fptr->next = (struct xs_file *) 0;
		fptr->connection = (struct xs_connection *) 0;
		fptr = inxsql_liberate_file( fptr );
	}

	/* --------------------- */
	/* release the databases */
	/* --------------------- */
	while ((bptr = xptr->firstbase) !=(struct xs_base *) 0)
	{
		if (!( xptr->firstbase = bptr->next ))
			xptr->lastbase = (struct xs_base *) 0;
		else	bptr->next->previous = bptr->previous;
		bptr->previous = bptr->next = (struct xs_base *) 0;
		bptr->connection = (struct xs_connection *) 0;
		bptr = inxsql_liberate_database( bptr );
	}

	/* ------------------------------- */
	/* release the database connection */
	/* ------------------------------- */
	inxsql_close_database(xptr);

	return(_SUCCESS);
}

/*	----------------------	*/
/*	inxsql_create_database	*/
/*	----------------------	*/
public	int	inxsql_create_database( struct xs_base * bptr )
{
	if ( verbose ) printf("inxsql_create_database()\n");
	return( inxsql_database_create( bptr->connection, bptr->name ) );
}

/*	--------------------	*/
/*	inxsql_drop_database	*/
/*	--------------------	*/
public	int	inxsql_drop_database( struct xs_connection * xptr, char * nptr )
{
	char 	query[_STD_QUERY_LENGTH];
	if ( verbose ) printf("inxsql_drop_database()\n");
	sprintf(query,"DROP DATABASE %s",nptr);
	if (!( inxsql_query( xptr, query, strlen(query))))
		return(_SUCCESS);
	else	return(_ERROR_FILE_NOT_FOUND);
}

/*	-------------------------	*/
/*	inxsql_drop_this_database	*/
/*	-------------------------	*/
public	int	inxsql_drop_this_database( struct xs_base * bptr )
{
	char 	query[_STD_QUERY_LENGTH];
	if ( verbose ) printf("inxsql_unlink_database()\n");
	sprintf(query,"DROP DATABASE %s",bptr->name);
	if (!( inxsql_query( bptr->connection, query, strlen(query))))
		return(_SUCCESS);
	else	return(_ERROR_FILE_NOT_FOUND);
}

/*	-------------------	*/
/*	inxsql_use_database	*/
/*	-------------------	*/
public	int	inxsql_use_database( struct xs_connection * xptr, struct xs_base * bptr )
{
	char	query[_STD_QUERY_LENGTH];
	int	status=0;

	switch ( xptr->engine )
	{
#ifdef	_INXSQL_MYSQL	
	case	_INXSQL_MYSQL_ENGINE	:
		/* ---------------- */
		/* check parameters */
		/* ---------------- */
		if (!( xptr ))
			return( _SUCCESS );
		else if (!( bptr ))
			return(inxsql_use_database( xptr, xptr->home ));
		else if (!( bptr->name ))
			return(inxsql_use_database( xptr, xptr->home ));

		/* ------------------------ */
		/* check current base is ok */
		/* ------------------------ */
		if ( xptr->thisbase )
		{
			if (!( strcmp( xptr->thisbase->name, bptr->name ) ))
				return( _SUCCESS );
			xptr->thisbase = (struct xs_base *) 0;
		}

		/* -------------------------- */
		/* attempt to change database */
		/* -------------------------- */
		sprintf(query,"USE %s",bptr->name);
		if (( status = inxsql_query( xptr, query, strlen( query ) )) != _SUCCESS)
			return( status );
		else
		{
			/* --------------- */
			/* and remember it */
			/* --------------- */
			xptr->thisbase = bptr;
			return( _SUCCESS );
		}
#endif
	default		:
		return( _SUCCESS );
	}
}

/*	--------------------------------	*/
/*		inxsql_remove_base		*/
/*	--------------------------------	*/
/*		  W A R N I N G 		*/
/*	--------------------------------	*/
/*		   DROPS TABLES			*/
/*		       AND			*/
/*		  DROPS DATABASE		*/
/*	--------------------------------	*/

public	struct xs_base * inxsql_remove_base( struct xs_base * bptr )
{
	struct	xs_file * fptr;
	struct	xs_connection * xptr;
	int	status = 0;

	/* --------------------------- */
	/* cancel this active database */
	/* --------------------------- */
	if (( xptr = bptr->connection ) != (struct xs_connection *) 0)
		(void) inxsql_use_database(xptr, xptr->home);

	/* --------------------------------------------- */
	/* drop the tables and file control structures */
	/* --------------------------------------------- */
	for (	fptr = bptr->first;
		fptr != (struct xs_file *) 0;
		fptr = fptr->next)
		status = inxsql_drop_table(fptr);		

	/* ------------------------ */
	/* drop the actual database */
	/* ------------------------ */
	status = inxsql_drop_this_database( bptr );		

	/* -------------------------------------- */
	/* release the database control structure */
	/* -------------------------------------- */
	return( inxsql_liberate_database( bptr ) );

}

/*	---------------------------	*/
/*	inxsql_security_credentials	*/
/*	---------------------------	*/
public	 struct xs_connection * inxsql_security_credentials( struct  xs_connection * zptr, int mode )
{
	char *	eptr;
	if (!( zptr ))
		return( zptr );

	else if (!( inxsql_boolean( "INXSTLS", 0 ) ))
		zptr->tls = SSL_MODE_DISABLED;
	else if (((eptr = getenv( "INXSCERTIFICATE" )) != (char *) 0)
	     &&  (!( zptr->certificate = inxsql_allocate_string( eptr ))))
	{
		fprintf(stderr,"INXSCERTIFICATE must be set for secure operation\n");
		if ( mode ) return( inxsql_liberate_connection( zptr ) );
		else	return((struct xs_connection *) 0);
	}
	else if (((eptr = getenv( "INXSPRIVATEKEY" )) != (char *) 0)
	     &&  (!( zptr->privatekey = inxsql_allocate_string( eptr ))))
	{
		fprintf(stderr,"INXSPRIVATEKEY must be set for secure operation\n");
		if ( mode ) return( inxsql_liberate_connection( zptr ) );
		else	return((struct xs_connection *) 0);
	}
	else if (((eptr = getenv( "INXSCA" )) != (char *) 0)
	     &&  (!( zptr->authority = inxsql_allocate_string( eptr ))))
	{
		fprintf(stderr,"INXSCA must be set for secure operation\n");
		if ( mode ) return( inxsql_liberate_connection( zptr ) );
		else	return((struct xs_connection *) 0);
	}
	else	zptr->tls = SSL_MODE_REQUIRED;

	return( zptr );
}

/*	-------------------	*/
/*	allocate_connection	*/
/*	-------------------	*/
private	struct xs_connection * allocate_connection()
{
	struct xs_connection * xptr=(struct xs_connection *) 0;
	if (!( xptr = allocate_connection( sizeof (struct xs_connection ) )))
		return((struct xs_connection *) 0);
	else
	{
		xptr->engine = inxsql_database_engine(_INXSQL_DEFAULT_ENGINE);
		return( xptr );
	}
}

/*	--------------------------	*/
/*	inxsql_database_connection	*/
/*	--------------------------	*/
private	struct xs_connection * inxsql_database_connection( struct  xs_base * bptr, struct xs_connection * xptr, char * name )
{
	char	buffer[2048];
	char *	hostname;
	int	port;	
	char *	sptr;
	struct	xs_connection * zptr;

	// duplicate the database name
	strcpy( buffer, name );

	// detect a database connection prefix
	if (!( sptr = strchr( buffer, '@' ) ))
		return( xptr );

	else
	{
		// step over the user@password
		*(sptr++) = 0; hostname = sptr;

		// step over hostname
		if (!( sptr = strchr( sptr, ':' ) ))
			return((struct xs_connection *) 0);
		else
		{
			// terminate host and grab port
			*(sptr++) = 0; port = atoi(sptr);

			// step over port to basename
			if (!( sptr = strchr( sptr, ':' ) ))
				return((struct xs_connection *) 0);
			// allocate the new connection
			else if (!( zptr = allocate_connection()))
				return((struct xs_connection *) 0);
			// store the hostname
			else if (!( zptr->host = inxsql_allocate_string( hostname ) ))
				return( inxsql_liberate_connection( zptr ) );
			// store the basename
			else if (!( zptr->base = inxsql_allocate_string( (sptr+1) ) ))
				return( inxsql_liberate_connection( zptr ) );
			// separate the user and password
			else if (!( sptr = strchr(buffer,':') ))
				return( inxsql_liberate_connection( zptr ) );
			// store the password
			else if (!( zptr->pass = inxsql_allocate_string( (sptr+1) )))
				return( inxsql_liberate_connection( zptr ) );
			else
			{
				// store the user name
				*(sptr++) = 0;
				if (!( zptr->user = inxsql_allocate_string( buffer ) ))	
					return( inxsql_liberate_connection( zptr ) );
				else if (!( bptr->name = inxsql_allocate_string( zptr->base ) ))
					return( inxsql_liberate_connection( zptr ) );

				// handle secure connections and identity
				else if (!( zptr = inxsql_security_credentials(zptr,1) ))
					return( zptr );
				else
				{
					// store the port and max key
					zptr->maxkey = xptr->maxkey;
					zptr->port = port;
					bptr->maxkey = xptr->maxkey;

					// attempt to open connection
                			if (!( inxsql_connect_database( zptr, 0 ) ))
						return( (bptr->owner = zptr) );
					else	return( inxsql_liberate_connection( zptr ) );
				}
			}
		}
	}
}

/*	------------------------	*/
/*	inxsql_allocate_database	*/
/*	------------------------	*/
public	struct xs_base *	inxsql_allocate_database( struct xs_connection * xptr, char * name )
{
	struct	xs_base * bptr;

	// allocate the database management structure
	if (!( bptr = allocate(sizeof(struct xs_base)) ))
		return( bptr );
#ifdef	INXSQL_DEBUG_BASE
	printf("INXSQLDBG:allocate_database( %llx )\n",(unsigned long long)bptr);
#endif

	// detect an eventual complex name
	if (!( xptr = inxsql_database_connection( bptr, xptr, name )))
		return( inxsql_remove_base( bptr ) );
	else
	{
		/* ------------------------- */
		/* initialise database state */
		/* ------------------------- */
		bptr->lock = _INXS_UNLOCKED;
		bptr->connection = xptr;
		bptr->maxkey = xptr->maxkey;
		bptr->qlength = 0;

		/* ------------------ */
		/* reset file control */
		/* ------------------ */
		bptr->first = 
		bptr->last = 
		bptr->current = (struct xs_file *) 0;

		/* ------------------ */
		/* reset view control */
		/* ------------------ */
		bptr->firstview = 
		bptr->lastview = 
		bptr->view = (struct xs_view *) 0;

		/* ------------------ */
		/* reset join control */
		/* ------------------ */
		bptr->firstjoint = 
		bptr->lastjoint = 
		bptr->currentjoint = (struct xs_joint *) 0;

		/* ------------------------------- */
		/* add to linked list of databases */
		/* ------------------------------- */
		bptr->next = bptr->previous = (struct xs_base *) 0;

		if (!( bptr->previous = xptr->lastbase ))
			xptr->firstbase = bptr;
		else	bptr->previous->next = bptr;
		xptr->lastbase = bptr;

		return( bptr );
	}
}

/*	-----------------	*/
/*	inxsql_close_base	*/
/*	-----------------	*/
/*	 NON DESTRUCTIVE	*/
/*	-----------------	*/
public	struct xs_base *	inxsql_close_base( struct xs_base * bptr)
{
	struct	xs_file * fptr;
	struct	xs_view * vptr;
	struct	xs_joint * jptr;
	struct	xs_connection * xptr;

	/* --------------------------- */
	/* release the base view first */
	/* --------------------------- */
	(void) inxsql_drop_base_view( bptr );

	/* --------------------- */
	/* release the base lock */
	/* --------------------- */
	(void) inxsql_base_lock( bptr, _INXS_UNLOCKED );

	/* ---------------------------------------- */
	/* ensure this base is not the current base */
	/* ---------------------------------------- */
	if (!( xptr = bptr->owner ))
		if ((xptr = bptr->connection) != (struct xs_connection *) 0)
			(void) inxsql_use_database( xptr, xptr->home );

	/* -------------------------------------- */
	/* join the common database release trunc */
	/* -------------------------------------- */
	return( inxsql_liberate_database( bptr ) );

}

/*	----------------	*/
/*	inxsql_open_base	*/
/*	----------------	*/
public	struct xs_base *	inxsql_open_base( struct xs_connection * xptr, char * name )
{
	struct	xs_base * bptr=(struct xs_base *) 0;
	char 	query[_STD_QUERY_LENGTH];
	int	status=0;

	/* ------------------------------------------------- */
	/* attempt to allocate database management structure */
	/* ------------------------------------------------- */
	if (!( bptr = inxsql_allocate_database( xptr, name )))
		return( bptr );

	/* ---------------------- */
	/* refresh the connection */
	/* ---------------------- */
	else if (!( xptr = bptr->connection ))
		return( inxsql_close_base( bptr ) );
	else
	{
		/* ------------------------------ */
		/* attempt to locate the database */
		/* ------------------------------ */
		sprintf(query,"SHOW DATABASES LIKE '%s'",bptr->name);
		if ( inxsql_query( xptr, query, strlen(query)) != _SUCCESS )
			return( inxsql_close_base( bptr ) );

        	/* --------------------------------- */
        	/* is there a result to be retrieved */
        	/* --------------------------------- */
        	else if (!( xptr->result = inxsql_store_result(xptr) ))
			return( inxsql_close_base( bptr ));
        	else if (!( inxsql_num_fields(xptr) ))
        	{
              		inxsql_free_result(xptr);
			return( inxsql_close_base( bptr ));
        	}
       		else
        	{
			/* ------------------------------------------ */
			/* fetch the rows and check for database name */
			/* ------------------------------------------ */
			int exists=0;
                       	INXSQL_ROW row;
                       	while ((row = inxsql_fetch_row(xptr)))
			{
				if (!( strcmp( inxsql_fetch_field(xptr,row,0), bptr->name ) ))
				{
					exists = 1;
					break;
				}
			}

			/* ---------------------------- */
			/* release the previous results */
			/* ---------------------------- */
              		inxsql_free_result(xptr);

			/* ----------------------------- */
			/* cannot open if does not exist */
			/* ----------------------------- */
			if (!( exists )) { return( inxsql_close_base( bptr )); }

                	/* -------------------------------------- */
                	/* the base exists so load list of tables */
                	/* -------------------------------------- */
                	sprintf(query,"SHOW TABLES FROM %s",bptr->name);
                	if ((status = inxsql_query(xptr, query, strlen(query))) != _SUCCESS)
                	{
				/* ----------------- */
				/* an empty database */
				/* ----------------- */
                	        return(bptr);
                	}
                	else if (!( xptr->result = inxsql_store_result(xptr) ))
                	{
				/* ----------------- */
				/* an empty database */
				/* ----------------- */
                	        return(bptr);
                	}
        		else if (!( inxsql_num_fields(xptr) ))
                	{
				/* ----------------- */
				/* an empty database */
				/* ----------------- */
              			inxsql_free_result(xptr);
                	        return(bptr);
                	}
                	else
                	{
				/* -------------------------- */
				/* collect the list of tables */
				/* -------------------------- */
				struct xs_file * fptr;
                       		INXSQL_ROW row;
                       		while ((row = inxsql_fetch_row(xptr)))
				{
					if ( inxsql_is_view_name( inxsql_fetch_field(xptr,row,0) ) )
						continue;
					else if (!( fptr = inxsql_create_file(xptr, inxsql_fetch_field(xptr,row,0), bptr ) ))
						return( inxsql_close_base( bptr ) );
				}
				/* ---------------------- */
				/* release the table list */
				/* ---------------------- */
              			inxsql_free_result(xptr);

				/* --------------- */
				/* open the tables */
				/* --------------- */
				for (	fptr = bptr->first;
					fptr != (struct xs_file *) 0;
					fptr = fptr->next )
				{
					if (!( inxsql_open_table( fptr ) ))
						continue;
					else	return( inxsql_close_base( bptr ) );
				}

				/* -------------------- */
				/* the database is open */
				/* -------------------- */
				return( bptr );
			}
		}
	}
}

/*	------------------------	*/
/*	inxsql_locate_base_field	*/
/*	------------------------	*/
public  struct xs_field * inxsql_locate_base_field( struct xs_base * bptr, char * nptr)
{
	struct	xs_file * fptr;
	struct	xs_field * cptr;
	if (!( bptr ))
		return((struct xs_field *) 0);
	for (	fptr = bptr->first;
		fptr != (struct xs_file *) 0;
		fptr = fptr->next )
	{
		if (!( cptr = inxsql_locate_field( fptr, nptr )))
			continue;
		else	return( cptr );
	}
	return((struct xs_field *) 0);
}

/*	--------------------	*/
/*	inxsql_list_basefile	*/
/*	--------------------	*/
public	int	inxsql_list_basefile(struct xs_base * bptr, char * dptr, int dlen, int mode )
{
	char *	vptr;
	int	vlen;

	/* ---------------------------- */
	/* determine first or next mode */
	/* ---------------------------- */
	switch ( mode )
	{
	case	0	: /* FIRST 	*/
		if (!( bptr->current = bptr->first ))
			return(_ERROR_END_OF_FILE);
		else	break;
	case	1	: /* NEXT	*/
		if (!( bptr->current ))
			return(_ERROR_END_OF_FILE);
		else if (!( bptr->current = bptr->current->next ))
			return(_ERROR_END_OF_FILE);
		else	break;
	}

	/* --------------------------------- */
	/* generate the resulting databuffer */
	/* --------------------------------- */
	if (!( bptr->current ))
		return(_ERROR_END_OF_FILE);
	else if (!( vptr = bptr->current->name))
		return(_ERROR_END_OF_FILE);
	else	memset(dptr,' ',dlen);

	/* ------------------- */
	/* indicate the INXSQL */
	/* ------------------- */
	if ( dlen >= 3 )
	{
		dptr[0] = 'S';
		dptr[1] = 'Q';
		dptr[2] = 'L';
	}

	/* ------------------ */	
	/* put the table name */
	/* ------------------ */	
	if ( dlen >= 18 )
	{
		for ( vlen = 0; vlen < 15; vlen++ )
			if ( *vptr != 0 )
				dptr[vlen+3] = *(vptr++);
	}

	/* ---------------------- */
	/* these are zero for now */
	/* ---------------------- */
	if ( dlen >= 20 )
	{
		dptr[18] = 0;
		dptr[19] = 0;
	}
	if ( dlen >= 22 )
	{
		dptr[20] = 0;
		dptr[21] = 0;
	}
	dlen -= 22;
	if ( dlen > 0 )
	{
		dptr += 22;
		while (( *vptr != 0 ) && ( dlen != 0))
		{
			*(dptr++) = *(vptr++);
			dlen--;
		}	
	}
	return( _SUCCESS );
}

/*	----------------------		*/
/*	inxsql_rename_database		*/
/*	----------------------		*/
public	int	inxsql_rename_database( struct xs_base * bptr, char * nptr )
{
	struct xs_base * base;
	struct xs_connection * xptr;
	int	status;

	/* ----------------------- */
	/* validate the parameters */
	/* ----------------------- */
	if (!( xptr = bptr->connection ))
		return( _ERROR_CONNECTION );
	else if (!( nptr ))
		return( _ERROR_SYNTAX );
	else if (( status = inxsql_drop_base_view( bptr )) != _SUCCESS )
		return( status );
	/* ----------------------------------------- */
	/* ensure the name is not already a database */
	/* ----------------------------------------- */
	else if (( base = inxsql_open_base( xptr, nptr )) != (struct xs_base *) 0)
	{
		base = inxsql_close_base( base );
		return( _ERROR_FILE_EXISTS );
	}
	/* -------------------------------------- */
	/* start the creation of the new database */
	/* -------------------------------------- */
	else if (!(base = inxsql_allocate_database(xptr, nptr)))
		return( _ERROR_MEMORY );
	/* ---------------------- */
	/* refresh the connection */
	/* ---------------------- */
	else if (!( xptr = base->connection ))
	{
		inxsql_close_base( base );
		return( _ERROR_CONNECTION);
	}
	else if (( status = inxsql_create_database(base)) != _SUCCESS)
	{
		base = inxsql_liberate_database( base );
		return(status);
	}
	/* --------------------------------------------------- */
	/* rename the tables from the old base to the new base */
	/* --------------------------------------------------- */
	else if ((status = inxsql_transfer_tables(bptr,bptr->name,nptr)) != _SUCCESS)
	{
		base = inxsql_remove_base( base );
		return(status);
	}
	/* -------------------------------------------------- */
	/* drop the old database and rename control structure */
	/* -------------------------------------------------- */
	else 
	{
		int    lock = bptr->lock;
		char * oldname = bptr->name;
		if ((status = inxsql_base_lock( bptr, _INXS_UNLOCKED)) != _SUCCESS)
		{
			/* ----------------------------------- */
			/* restore the old database conditions */
			/* ----------------------------------- */
			bptr->name = oldname;
			(void) inxsql_transfer_tables(bptr,nptr,bptr->name);
			base = inxsql_remove_base( base );
			return(status);
		}
		else
		{
			/* --------------------------------- */
			/* attempt to reallocate to new name */
			/* --------------------------------- */
			if (!( bptr->name = inxsql_allocate_string( nptr )))
			{
				/* ----------------------------------- */
				/* restore the old database conditions */
				/* ----------------------------------- */
				bptr->name = oldname;
				(void) inxsql_transfer_tables(bptr,nptr,bptr->name);
				base = inxsql_remove_base( base );
				(void) inxsql_base_lock(bptr,lock);
				return( _ERROR_MEMORY );
			}
			/* ---------------------------------- */
			/* set the new name and drop old base */
			/* ---------------------------------- */
			(void) inxsql_base_lock(bptr,lock);
			(void) inxsql_drop_database( bptr->connection, oldname );
			oldname = liberate(oldname);
			base = inxsql_liberate_database( base );
			/* -------------------- */
			/* and indicate success */
			/* -------------------- */
			return( _SUCCESS );
		}
	}
		
}

/*      -----------------------------------------------------------     */
/*                i n x s q l _ b a s e _ q l e n g t h                 */
/*      -----------------------------------------------------------     */
/*      calculates and returns the additional query length required     */
/*      for the addition of all the column names of a database.   	*/
/*      -----------------------------------------------------------     */

public  int     inxsql_base_qlength(struct xs_base * bptr)
{
	struct	xs_file * fptr=(struct xs_file *) 0;
        if (!( bptr->qlength ))
	{
        	for (	fptr = bptr->first;
			fptr != (struct xs_file *) 0;
			fptr = fptr->next )
		{
			bptr->qlength += (inxsql_file_qlength(fptr) + 3); 
			bptr->flength += fptr->flength;
		}
	}
        return( bptr->qlength );
}

#endif	/* _inxsql_base_c */

