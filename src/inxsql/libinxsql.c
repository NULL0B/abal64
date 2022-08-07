#ifndef	_libinxsql_c
#define	_libinxsql_c

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

#include "inxsql.h"

#define	_INXS_STUB_SI
#define	_INXS_STUB_MC
#define	_INXS_STUB_DB

private	struct	xs_base	InXsqlBase =
{
        (struct xs_base          *) 0,
        (struct xs_base          *) 0,

        /* host connection */
        (struct xs_connection    *) 0,
        (struct xs_connection    *) 0,

        /* file management */
        (struct xs_file          *) 0,
        (struct xs_file          *) 0,
        (struct xs_file          *) 0,

        /* join management */
        (struct xs_joint         *) 0,
        (struct xs_joint         *) 0,
        (struct xs_joint         *) 0,
        (struct xs_joint         *) 0,

        /* view management */
        (struct xs_view          *) 0,
        (struct xs_view          *) 0,
        (struct xs_view          *) 0,

        /* database characteristics */
	_ABAL_KEY_MAX_STD,
	0,
	0,
	0,
	0,
	0,
	(char *) 0
};

private	struct	xs_connection InXsqlCnx = 
{ 
	(struct xs_file *) 0, 
	(struct xs_file *) 0,

	(struct xs_base *) 0,
	(struct xs_base *) 0,
	(struct xs_base *) 0,
	(struct xs_base *) &InXsqlBase,

	(void*) 0,
	(void*) 0,

#ifdef	_INXSQL_PGSQL
	0,
	0,
	(unsigned long *) 0,
#endif

	(char*) 0, 
	(char*) 0,
	(char*) 0,
	(char*) 0,

	(char*) 0,	/* certificate */
	(char*) 0,	/* private key */
	(char*) 0,	/* authority   */

	SSL_MODE_DISABLED,

	0,0,0,0,0,_ABAL_KEY_MAX_STD, 0, 0,

	_INXSQL_DEFAULT_ENGINE
};

public	void set_verbose(int);

/*	----------------------	*/
/*	inxsql_sigpipe_catcher	*/
/*	----------------------	*/
private	void	inxsql_sigpipe_catcher(int s)
{
	InXsqlCnx.signals++;
	return;
}

/*	-------------	*/
/*	inxsql_engine	*/
/*	-------------	*/
public	int	inxsql_engine()
{
	return( InXsqlCnx.engine );
}

/*	------------------------	*/
/*	inxsql_signal_protection	*/
/*	------------------------	*/
public	void	inxsql_signal_protection()
{
#ifdef	SIGPIPE
	signal( SIGPIPE,inxsql_sigpipe_catcher);
#endif
	return;
}

/*	---------	*/
/*	IsamBegin	*/
/*	---------	*/
public	int	IsamBegin(unsigned char * buffer, unsigned int callback) 	
{ 
	char *	pptr;
	char *	vptr;
	char *	eptr;
	char *	hptr=_LOCAL_HOST;
	int	port=_LOCAL_PORT;
	int	p;
	int	verbose=0;
	int	longNames=0;
	unsigned long t;
	unsigned long v;

	InXsqlCnx.engine = inxsql_database_engine(_INXSQL_DEFAULT_ENGINE);

	longNames = *(buffer+20);		/* grab the flag now	*/

	memset( buffer,0,105);			/* reset entire buffer	*/

	*(buffer + 0) = 5;			/* compatibility test 	*/
	*(buffer + 1) = 0x0037; 		/* database version 	*/
	*(buffer + 2) = 0x0061; 		/* database indexe  	*/
	*(buffer + 3) = 0x0040; 		/* byte 1 encryption	*/
	*(buffer + 4) = 0x0073; 		/* byte 2 encryption	*/

	p = InXsqlCnx.process = getpid();	/* 4 byte identification*/

	*(buffer + 5) = ((p >>  0) & 0x00FF);
	*(buffer + 6) = ((p >>  8) & 0x00FF);
	*(buffer + 7) = ((p >> 16) & 0x00FF);
	*(buffer + 8) = ((p >> 24) & 0x00FF);

	t = InXsqlCnx.time = time((unsigned long*)0);

	*(buffer + 9) = ((t >>  0) & 0x00FF);
	*(buffer +10) = ((t >>  8) & 0x00FF);
	*(buffer +11) = ((t >> 16) & 0x00FF);
	*(buffer +12) = ((t >> 24) & 0x00FF);
	
	v = (unsigned long) &InXsqlCnx; 	/* conenction handle	*/

	*(buffer +13) = ((v >>  0) & 0x00FF);
	*(buffer +14) = ((v >>  8) & 0x00FF);
	*(buffer +15) = ((v >> 16) & 0x00FF);
	*(buffer +16) = ((v >> 24) & 0x00FF);

	// detect request for long names
	if ( longNames )
	{
		*(buffer +20) = 1;
		InXsqlBase.maxkey = InXsqlCnx.maxkey = _ABAL_KEY_MAX_EXT;
	}
	else
	{
		*(buffer +20) = 0;
		InXsqlBase.maxkey = InXsqlCnx.maxkey = _ABAL_KEY_MAX_STD;
	}

	*(buffer +21) = 3;			/* not sure why 	*/
	*(buffer +22) = 1;			/* name_conversion flag	*/

	/* ------------------ */
	/* handle the signals */
	/* ------------------ */
	inxsql_signal_protection();

	/* ---------------------------------- */
	/* handle the configuration variables */
	/* ---------------------------------- */
	if (( eptr = getenv("INXSUSER")) != (char *) 0)
	{
		InXsqlCnx.user = eptr;
	}

	if (( eptr = getenv("INXSPASS")) != (char *) 0)
	{
		InXsqlCnx.pass = eptr;
	}

	if (( eptr = getenv("INXSBASE")) != (char *) 0)
	{
		InXsqlCnx.base = eptr;
		InXsqlBase.name = eptr;
	}
	
	if (!( eptr = getenv("INXSHOST"))) 
	{
		InXsqlCnx.port = 0;
		if (!( inxsql_security_credentials(&InXsqlCnx,0) ))
			return(_ERROR_SECURITY);
		else	return( inxsql_connect_database( &InXsqlCnx, _INXS_INIT | _INXS_SELECT ) );
	}
	else
	{

		/* --------------------------------- */
		/* handle the INXSHOST configuration */
		/* --------------------------------- */
		hptr = eptr;
		while ( *eptr ) 
		{
			if ( *eptr == ':' )
				break;
			else	eptr++;
		}
		if ( *eptr == ':' ) 
		{
			*(eptr++) = 0;
			pptr = eptr;
			while ( *eptr ) 
			{
				if ( *eptr == ':' )
					break;
				else	eptr++;
			}
			if ( *eptr == ':' ) 
			{
				*(eptr++) = 0;
				set_verbose(atoi( eptr ));
			}
			port = atoi( pptr );
		}
		InXsqlCnx.port = port;
		InXsqlCnx.host = hptr;
		/* --------------------------------- */
		/* start the database connection now */
		/* --------------------------------- */
		if (!( inxsql_security_credentials(&InXsqlCnx,0) ))
			return(_ERROR_SECURITY);
		else	return( inxsql_connect_database( &InXsqlCnx, _INXS_INIT | _INXS_SELECT ) );
	}
}

/*	------- */
/*	IsamEnd	*/
/*	------- */
public	int	IsamEnd(void * vptr) 	
{ 
	return( inxsql_close_connection( &InXsqlCnx ) );
}

#ifdef	_INXS_STUB_AD
public	int	FFcreate() 	{ return(0); }
public	int	FFrename() 	{ return(0); }
public	int	FFunlink() 	{ return(0); }
public	int	FFopen() 	{ return(0); }
public	int	FFread64() 	{ return(0); }
public	int	FFwrite64() 	{ return(0); }
public	int	FFextend() 	{ return(0); }
public	int	FFaccess() 	{ return(0); }
public	int	FFatbopen() 	{ return(0); }
public	int	FFclose() 	{ return(0); }
#endif

#ifdef	_INXS_STUB_SQ
public	int	SQcreate() 	{ return(0); }
public	int	SQrename() 	{ return(0); }
public	int	SQunlink() 	{ return(0); }
public	int	SQopen() 	{ return(0); }
public	int	SQatbopen() 	{ return(0); }
public	int	SQread() 	{ return(0); }
public	int	SQwrite() 	{ return(0); }
public	int	SQmodif() 	{ return(0); }
public	int	SQrewind() 	{ return(0); }
public	int	SQclose() 	{ return(0); }
#endif

#ifdef	_INXS_STUB_SI

/*	------------------------------------------	*/
/*		F i le   F u n c t i o n s		*/
/*	------------------------------------------	*/


/*	----------	*/
/*	IsamCreate	*/
/*	----------	*/
public	void * IsamCreate(char * n, int * i, int * d, int x, int c, int a, int v, int * e)
{ 
	struct	xs_file * fptr;
	char	buffername[1024];
	int	status;
	if (!( n = inxsql_process_filename( n )))
	{
		*e = _ERROR_SYNTAX;
		return( (void *) 0);
	}
	else if (( fptr = inxsql_locate_file( &InXsqlCnx, n, 0 )) != (struct xs_file *) 0)
	{
		*e = _ERROR_FILE_EXISTS;
		return( (void *) 0);
	}	
	else if (!( fptr = inxsql_create_file( &InXsqlCnx,n,(struct xs_base *) 0 )))
	{
		*e = _ERROR_FILE_EXISTS;
		return( (void *) 0);
	}	
	else
	{
		fptr->primary.size = *i;
		fptr->datalength = *d;
		/* ----------------------------------- */
		/* create the database table structure */
		/* ----------------------------------- */
		if ( inxsql_create_table( fptr, a ) != 0)
		{
			*e = _ERROR_FILE_EXISTS;
			return( inxsql_liberate_file( fptr ) );
		}
		else 
		{
			/* ------------------------------------------- */
			/* no data record means simply primary indexes */
			/* ------------------------------------------- */
			if ( fptr->datalength > 0 )
			{
				// detect and handle variable data length
				if ( v )
				{
					/* --------------------------------------- */
					/* create the data record of required size */
					/* --------------------------------------- */
					sprintf(buffername,"%s%u%s",_INXS_PREFIX, fptr->datalength,_INXS_RECORD);
					if (( status = inxsql_append_field( fptr, buffername, fptr->datalength, _INXS_VARBIN, 0 )) != _SUCCESS)
					{
						/* ------------------------- */
						/* clean up and report error */
						/* ------------------------- */
						*e = status;
						inxsql_drop_table( fptr );
						return( inxsql_liberate_file( fptr ) );
					}
				}				
				else
				{
					/* --------------------------------------- */
					/* create the data record of required size */
					/* --------------------------------------- */
					sprintf(buffername,"%s%u%s",_INXS_PREFIX, fptr->datalength,_INXS_RECORD);
					if (( status = inxsql_append_field( fptr, buffername, fptr->datalength, _INXS_BIN, 0 )) != _SUCCESS)
					{
						/* ------------------------- */
						/* clean up and report error */
						/* ------------------------- */
						*e = status;
						inxsql_drop_table( fptr );
						return( inxsql_liberate_file( fptr ) );
					}
				}
			}

			/* ------------------------------------- */
			/* try and set the share characteristics */
			/* ------------------------------------- */
			if (( status = inxsql_file_lock( fptr, (x ? _INXS_FILE_LOCK : _INXS_UNLOCKED) )) == _SUCCESS )
			{
				*e = _SUCCESS;
				return( fptr );
			}
			else
			{
				/* ------------------------- */
				/* clean up and report error */
				/* ------------------------- */
				*e = status;
				inxsql_drop_table( fptr );
				return( inxsql_liberate_file( fptr ) );
			}
		}
	}
}

/*	---------	*/
/*	IsamClose	*/
/*	---------	*/
public	int	IsamClose(void * h) 	
{ 
	if ( h ) { h = inxsql_liberate_file( h ); }
	return(0);
}

/*	---------	*/
/*	IsamOpen	*/
/*	---------	*/
public	void *	IsamOpen(char * n, int x, int c, int w, int * i, int * d, int * e)
{ 
	struct	xs_file * fptr;
	int	status=0;
	if (!( n = inxsql_process_filename( n )))
		return( (void *) 0);
	else if (( fptr = inxsql_locate_file( &InXsqlCnx, n, 1 )) != (struct xs_file *) 0)
	{
		/* ------------------------------------- */
		/* try and set the share characteristics */
		/* ------------------------------------- */
		if (( status = inxsql_file_lock( fptr, (x ? _INXS_FILE_LOCK : _INXS_UNLOCKED ))) == _SUCCESS )
		{
			*i = fptr->primary.size;
			*d = fptr->datalength;
			*e = status;
			return( fptr );
		}
		else
		{
			/* ------------- */
			/* access denied */
			/* ------------- */
			*e = status;
			return( inxsql_liberate_file( fptr ) );
		}
	}
	else if (!( fptr = inxsql_create_file(&InXsqlCnx, n,(struct xs_base *) 0 )))
		return( (void *) 0);
	else if (!( *e = inxsql_open_table(fptr) ))
	{
		/* ------------------------------------- */
		/* try and set the share characteristics */
		/* ------------------------------------- */
		if (( status = inxsql_file_lock( fptr, (x ? _INXS_FILE_LOCK : _INXS_UNLOCKED ))) == _SUCCESS )
		{
			*i = fptr->primary.size;
			*d = fptr->datalength;
			*e = status;
			return( fptr );
		}
		else
		{
			/* ------------- */
			/* access denied */
			/* ------------- */
			*e = status;
			return( inxsql_liberate_file( fptr ) );
		}
	}
	else	return( inxsql_liberate_file( fptr ) );
}

/*	----------	*/
/*	IsamUnlink	*/
/*	----------	*/
public	int	IsamUnlink(char * filename)
{ 
	struct	xs_file * fptr;
	int	status=0;
	if (!( filename = inxsql_process_filename( filename )))
		return( _ERROR_SYNTAX );
	else if (!( fptr = inxsql_create_file(&InXsqlCnx, filename,(struct xs_base *) 0 )))
		return( _ERROR_FILE_NOT_FOUND );
	else
	{
		status = inxsql_drop_table( fptr );
		(void) inxsql_liberate_file( fptr );
		return( status );
	}

}

/*	----------	*/
/*	IsamRename	*/
/*	----------	*/
public	int	IsamRename(struct xs_file * h, char * newname)
{ 
	if (!( newname = inxsql_process_filename( newname )))
		return( _ERROR_SYNTAX );
	else	return( inxsql_rename_table( h, newname ) );
}

/*	------------	*/
/*	IsamFileInfo	*/
/*	------------	*/
public	int	IsamFileInfo(struct xs_file * h,char * bptr, int blen)
{ 
	return(inxsql_file_description(h,bptr,blen));
}

/*	--------	*/
/*	IsamInfo	*/
/*	--------	*/
public	int	IsamInfo(struct xs_file * h,char * bptr, int blen)
{ 
	return(0);
}

/*	----------	*/
/*	IamAtbOpen	*/
/*	----------	*/
public	int	IsamAtbOpen(struct xs_file * h, int x, int c) 
{ 
	return( inxsql_file_lock( h, (x ? _INXS_FILE_LOCK : _INXS_UNLOCKED ) ) );
}

/*	------------------------------------------	*/
/*	      R e c o r d  F u n c t i o n s		*/
/*	------------------------------------------	*/

/*	----------	*/
/*	IsamInsert	*/
/*	----------	*/
public	int	IsamInsert(struct xs_file * h,char * iptr, int mq, char * rptr, int l) 	
{ 
	return( inxsql_insert_record( h, iptr, rptr, l ) );
}

/*	---------	*/
/*	IsamModif	*/
/*	---------	*/
public	int	IsamModif(struct xs_file * h,char * iptr, int mq, char * rptr, int l) 	
{ 
	return( inxsql_update_record( h, iptr, rptr, l ) );
}

/*	----------	*/
/*	IsamDelete	*/
/*	----------	*/
public	int	IsamDelete(struct xs_file * h,char * iptr, int mq )
{ 
	return( inxsql_delete_record( h, iptr ) );
}

/*	----------	*/
/*	IsamSearch	*/
/*	----------	*/
public	int	IsamSearch(struct xs_file * h, int lock, char * iptr, int * mptr, char * rptr, int dlen, int * rlen) 	
{ 
	*mptr = 1;
	*rlen = dlen;
	return( inxsql_retrieve_record( h, iptr, rptr, dlen, lock, rlen ) );
}

/*	----------	*/
/*	IsamUpDown	*/
/*	----------	*/
public	int	IsamUpDown(struct xs_file * h, int dir, int lock, int * mptr, char * rptr, int dlen, int * rlen)  	
{ 
	*mptr = 1;
	*rlen = dlen;
	if ( dir == 1 ) 
		return( inxsql_next_record( h, rptr, dlen, lock, rlen ) );
	else	return( inxsql_previous_record( h, rptr, dlen, lock, rlen ) );
}

/*	-----------	*/
/*	IsamWriteZc	*/
/*	-----------	*/
public	int	IsamWriteZc(struct xs_file * h) 	
{ 
	return(56); 
}

/*	----------	*/
/*	IsamReadZc	*/
/*	----------	*/
public	int	IsamReadZc(struct xs_file * h) 	
{ 
	return(56); 
}

/*	----------	*/
/*	IsamCriExt	*/
/*	----------	*/
public	int	IsamCriExt(struct xs_file * h) 	
{ 
	return(56); 
}
#endif

#ifdef	_INXS_STUB_MC

/*	------------------------------------------	*/
/*		F i le   F u n c t i o n s		*/
/*	------------------------------------------	*/

/*	------------	*/
/*	McIsamCreate	*/
/*	------------	*/
public	void *  McIsamCreate(char * n, int * i, int * d, int x, int c, int a, int v, int * e)
{ 
	struct	xs_file * fptr;
	int	status = 0;
	if (!( n = inxsql_process_filename( n )))
	{
		*e = _ERROR_SYNTAX;
		return( (void *) 0);
	}	
	else if (( fptr = inxsql_locate_file( &InXsqlCnx, n, 0 )) != (struct xs_file *) 0)
	{
		*e = _ERROR_FILE_EXISTS;
		return( (void *) 0);
	}	
	else if (!( fptr = inxsql_create_file( &InXsqlCnx,n,(struct xs_base *) 0  )))
	{
		*e = _ERROR_DISK_FULL;
		return( (void *) 0);
	}	
	else
	{
		fptr->primary.size = *i;
		fptr->datalength = *d;
		if ((status = inxsql_create_table( fptr, a )) != _SUCCESS)
		{
			*e = status;
			return( inxsql_liberate_file( fptr ) );
		}
		else if ((status = inxsql_file_lock( fptr, (x ? _INXS_FILE_LOCK : _INXS_UNLOCKED ))) == _SUCCESS)
		{
			*e = 0;
			return( fptr );
		}
		else
		{
			*e = status;
			return( inxsql_liberate_file( fptr ) );
		}
	}
}

/*	-----------	*/
/*	McIsamClose	*/
/*	-----------	*/
public	int	McIsamClose(void * h) 	
{ 
	if ( h ) { h = inxsql_liberate_file( h ); }
	return(0);
}

/*	----------	*/
/*	McIsamOpen	*/
/*	----------	*/
public	void *	McIsamOpen(char * n, int x, int c, int w, int * i, int * d, int * e)
{ 	
	struct	xs_file * fptr;
	int	status=0;
	if (!( n = inxsql_process_filename( n )))
		return( (void *) 0);
	else if (( fptr = inxsql_locate_file( &InXsqlCnx, n, 1 )) != (struct xs_file *) 0)
	{
		if ((status = inxsql_file_lock( fptr, (x ? _INXS_FILE_LOCK : _INXS_UNLOCKED) )) == _SUCCESS)
		{
			*i = fptr->primary.size;
			*d = fptr->datalength;
			*e = status;
			return( fptr );
		}
		else
		{
			/* ------------- */
			/* access denied */
			/* ------------- */
			*e = status;
			return(inxsql_liberate_file( fptr ));
		}
	}
	else if (!( fptr = inxsql_create_file(&InXsqlCnx, n,(struct xs_base *) 0 )))
		return( (void *) 0);
	else if (!( *e = inxsql_open_table(fptr) ))
	{
		if ((status = inxsql_file_lock( fptr, (x ? _INXS_FILE_LOCK : _INXS_UNLOCKED) )) == _SUCCESS)
		{
			*i = fptr->primary.size;
			*d = fptr->datalength;
			*e = status;
			return( fptr );
		}
		else
		{
			/* ------------- */
			/* access denied */
			/* ------------- */
			*e = status;
			return(inxsql_liberate_file( fptr ));
		}
	}
	else	return( inxsql_liberate_file( fptr ) );
}

/*	------------	*/
/*	McIsamUnlink	*/
/*	------------	*/
public	int	McIsamUnlink(char * filename)
{ 
	struct	xs_file * fptr;
	int	status=0;
	if (!( filename = inxsql_process_filename( filename )))
		return( _ERROR_SYNTAX );
	else if (!( fptr = inxsql_create_file(&InXsqlCnx, filename,(struct xs_base *) 0 )))
		return( _ERROR_FILE_NOT_FOUND );
	else
	{
		status = inxsql_drop_table( fptr );
		(void) inxsql_liberate_file( fptr );
		return( status );
	}
}

/*	------------	*/
/*	McIsamRename	*/
/*	------------	*/
public	int	McIsamRename(struct xs_file * h, char * newname)
{ 
	if (!( newname = inxsql_process_filename( newname )))
		return( _ERROR_SYNTAX );
	else	return( inxsql_rename_table( h, newname ) );
}

/*	-------------	*/
/*	McIsamAtbOpen	*/
/*	-------------	*/
public	int	McIsamAtbOpen(struct xs_file * h, int x, int c) 
{ 
	return( inxsql_file_lock( h, (x ? _INXS_FILE_LOCK : _INXS_UNLOCKED) ) );
}

/*	--------------	*/
/*	McIsamFileInfo	*/
/*	--------------	*/
public	int	McIsamFileInfo(struct xs_file * h,char * bptr, int blen)
{ 
	return(inxsql_file_description(h,bptr,blen));
}

/*	----------	*/
/*	McIsamInfo	*/
/*	----------	*/
public	int	McIsamInfo(struct xs_file * h,char * bptr, int blen)
{ 
	return(inxsql_file_info(h,bptr,blen));
}

/*	------------------------------------------	*/
/*	      R e c o r d  F u n c t i o n s		*/
/*	------------------------------------------	*/

/*	------------	*/
/*	McIsamInsert	*/
/*	------------	*/
public	int	McIsamInsert(struct xs_file * h,char * iptr, int mq, char * rptr, int l) 	
{ 
	return( inxsql_insert_record( h, iptr, rptr, l ) );
}

/*	-----------	*/
/*	McIsamModif	*/
/*	-----------	*/
public	int	McIsamModif(struct xs_file * h,char * iptr, int mq, char * rptr, int l) 	
{ 
	return( inxsql_update_record( h, iptr, rptr, l ) );
}

/*	------------	*/
/*	McIsamDelete	*/
/*	------------	*/
public	int	McIsamDelete(struct xs_file * h,char * iptr, int mq )
{ 
	return( inxsql_delete_record( h, iptr ) );
}

/*	-----------	*/
/*	McIsamQuery	*/
/*	-----------	*/
public	int	McIsamQuery(struct xs_file * h, char * qptr, int qlen )
{ 
	return( inxsql_standard_query( h->connection, qptr, qlen, _SUCCESS ) );
}

/*	------------	*/
/*	McIsamSearch	*/
/*	------------	*/
public	int	McIsamSearch(struct xs_file * h, int lock, char * iptr, int * mptr, char * rptr, int dlen, int * rlen) 	
{ 
	*mptr = 1;
	*rlen = dlen;
	return( inxsql_retrieve_record( h, iptr, rptr, dlen, lock, rlen ) );
}

/*	------------	*/
/*	McIsamUpDown	*/
/*	------------	*/
public	int	McIsamUpDown(struct xs_file * h, int dir, int lock, int * mptr, char * rptr, int dlen, int * rlen)  	
{ 
	*mptr = 1;
	*rlen = dlen;
	if ( dir == 1 ) 
		return( inxsql_next_record( h, rptr, dlen, lock, rlen ) );
	else	return( inxsql_previous_record( h, rptr, dlen, lock, rlen ) );
}

/*	------------------------------------------	*/
/*	      I n d e x    F u n c t i o n s		*/
/*	------------------------------------------	*/

/*	----------	*/
/*	McIsamCkey	*/
/*	----------	*/
public	int	McIsamCkey(struct xs_file * h,char * nptr, int length, int type)
{
#ifdef	DEBUG_CKEY
	char *	sptr;
	fprintf(stderr,"MC ISAM KEY : ");
	for ( sptr = nptr; *sptr != ' '; sptr++ ) fprintf(stderr, "%c",*sptr);
	fprintf(stderr,", %u, %x \n", length, type);
#endif
	switch ( type & 0x000F )
	{
	case	_XS_KEY_A	:	/* historic binary string type */
		return( inxsql_append_field( h, nptr, length, _INXS_BIN, 0 ) );
	case	_XS_KEY_S	:	/* new standard string type */
		return( inxsql_append_field( h, nptr, length, _INXS_STRING, 0 ) );
	case	_XS_KEY_N	:	/* historic numerical type */
		switch ( length )
		{
		case	1 :
			return( inxsql_append_field( h, nptr, length, _INXS_INT8, 0 ) );
		case	2 :
			return( inxsql_append_field( h, nptr, length, _INXS_INT16, 0 ) );
		default	  :
			return( inxsql_append_field( h, nptr, length, _INXS_BCD, ((type & 0x00F0) >> 4) ) );
		}
	case	_XS_KEY_F	:	/* new NUMERIC type */
		return( inxsql_append_field( h, nptr, length, _INXS_BCD, ((type & 0x00F0) >> 4) ) );
	case	_XS_KEY_L	:	/* new LONG type */
		return( inxsql_append_field( h, nptr, length, _INXS_INT32, 0 ) );
	case	_XS_KEY_H	:	/* new HUGE type */
		return( inxsql_append_field( h, nptr, length, _INXS_INT64, 0 ) );
	case	_XS_KEY_D	:	/* new DATE type */
		return( inxsql_append_field( h, nptr, length, _INXS_DATE, 0 ) );
	case	_XS_KEY_T	:	/* new TIME type */
		return( inxsql_append_field( h, nptr, length, _INXS_TIME, 0 ) );
	default		:
		return( inxsql_append_field( h, nptr, length, _INXS_STRING, 0 ) );
	}
}

/*	----------	*/
/*	McIsamNkey	*/
/*	----------	*/
public	int	McIsamNkey(struct xs_file * h,char * oldname,char * newname) 	
{ 
	return( inxsql_rename_field( h, oldname, newname ) );
}

/*	----------	*/
/*	McIsamFkey	*/
/*	----------	*/
public	int	McIsamFkey(struct xs_file * h,char * parent, char * child, int length,int type, int offset) 	
{ 
	return( inxsql_append_field( h, child, length, type, 0 ) );
}

/*	----------	*/
/*	McIsamCndx	*/
/*	----------	*/
public	int	McIsamCndx(struct xs_file * h, char * descriptor,int length)
{
	return(inxsql_create_index(h,descriptor,length,1)); 
}

/*	----------	*/
/*	McIsamDndx	*/
/*	----------	*/
public	int	McIsamDndx(struct xs_file * h, char * descriptor,int length) 	
{
	return(inxsql_drop_index(h,descriptor,length,1)); 
}

/*	-----------	*/
/*	McIsamDCndx	*/
/*	-----------	*/
public	int	McIsamDCndx(struct xs_file * h, char * descriptor,int length)
{
	return(inxsql_create_index(h,descriptor,length,0)); 
}

/*	-----------	*/
/*	McIsamDDndx	*/
/*	-----------	*/
public	int	McIsamDDndx(struct xs_file * h, char * descriptor,int length) 	
{
	return(inxsql_drop_index(h,descriptor,length,0)); 
}

/*	-----------	*/
/*	McIsamLkey 	*/
/*	-----------	*/
public	int	McIsamLkey( struct xs_file * h, char * dptr, int dlen, int option)
{ 
	int 	e = inxsql_list_columns(h,dptr,dlen,option); 
	return( e );
}

/*	-----------	*/
/*	McIsamLndx 	*/
/*	-----------	*/
public	int	McIsamLndx( struct xs_file * h, char * dptr, int dlen, int option)
{ 
	int 	e = inxsql_list_indexes(h,dptr,dlen,option); 
	return( e );
}

/*	------------	*/
/*	McIsamUpdndx	*/
/*	------------	*/
public	int	McIsamUpdndx(struct xs_file * h) 
{ 
	return(inxsql_update_indexes(h)); 
}

/*	-----------	*/
/*	McIsamCount	*/
/*	-----------	*/
public	int	McIsamCount(struct xs_file * h,char * dptr,int uni,int seq,int dlen, int * response )
{
	return(inxsql_count_file_records( h, dptr, dlen, uni, seq, response)); 
}

/*	-----------	*/
/*	McIsamPosit	*/
/*	-----------	*/
public	int	McIsamPosit(struct xs_file * h,char * dptr,int uni,int seq,int last, int dlen, int * response )
{
	return(inxsql_position_file_records( h, dptr, dlen, last, uni, seq, response)); 
}

/*	-------------	*/
/*	McIsamCollect	*/
/*	-------------	*/
public	int	McIsamCollect(
	/* ---------------- */
	/* input parameters */
	/* ---------------- */
	struct xs_file * fptr,	/* the file handle		*/
	char * 	dptr,		/* the descriptor pointer	*/
	int	dlen,		/* the length of the descriptor	*/
	int 	uni,		/* unique values only		*/
	int 	seq,		/* FIRST(0) NEXT(1)		*/
	int	mode,		/* what the fuck 		*/
	int 	last, 		/* last key received		*/
	/* ----------------- */
	/* output parameters */
	/* ----------------- */
	int  *	lgcle,		/* length of the primary index	*/
	char *	outbuffer,	/* the key storage buffer	*/
	int  *	outlen,		/* length of buffer used	*/
	int  * response 	/* the POST/COUNT flag		*/
	)
{
	int	status=0;
	char *	bptr = (char *) 0;
	int	blen = 0;
	int	olen = 0;

	/* ------------------------------ */		
	/* FIRST Call to collect the keys */
	/* ------------------------------ */		
	if (!( mode ))
		/* -------------------------------- */
		/* perform collect to storage buffer */
		/* -------------------------------- */
        	if (( status = inxsql_collect_file_records( fptr, dptr, dlen, last, uni, seq, response)) != _SUCCESS)
			return(status);

	/* ------------------------------ */
	/* transfer data to output buffer */
	/* ------------------------------ */
	if (!( olen = *outlen ))
		return( _SUCCESS );
	else if (!( bptr = fptr->storage ))
	{
		if (!( response ))
			return( _SUCCESS );
		else if (!( *response ))
			return( _SUCCESS );
		else	return( _ERROR_BUFFER_TOO_SMALL );
	}
	else if (!( blen = fptr->storagelength ))
	{
		if (!( response ))
			return( _SUCCESS );
		else if (!( *response ))
			return( _SUCCESS );
		else	return( _ERROR_BUFFER_TOO_SMALL );
	}
	else
	{
		/* ------------------------- */
		/* adjust the buffer control */
		/* ------------------------- */
		bptr += fptr->storageoffset;
		blen -= fptr->storageoffset;
		
		/* --------------------- */
		/* check transfer length */
		/* --------------------- */
		if (olen > blen) olen = blen;

		/* ------------------------- */
		/* transfer the lump of data */
		/* ------------------------- */
		memcpy(outbuffer,bptr,olen);

		/* ------------------------- */
		/* update the output lengths */
		/* ------------------------- */
		*lgcle = fptr->primary.size;
		*outlen = olen;

		/* -------------------------- */
		/* update the storage control */
		/* -------------------------- */
		fptr->storageoffset += olen;
		if ( fptr->storageoffset < fptr->storagelength )
			return( _SUCCESS );
		else	return( inxsql_liberate_storage(fptr) );
	}
}

/*	------------	*/
/*	McIsamSelect	*/
/*	------------	*/
public	int	McIsamSelect(
	/* ---------------- */
	/* input parameters */
	/* ---------------- */
	struct xs_file * fptr,	/* the file handle		*/
	char * 	dptr,		/* the descriptor pointer	*/
	int	dlen,		/* the length of the descriptor	*/
	char *	kptr,		/* the Field name list		*/
	int	klen,		/* the Field name list length	*/
	/* ----------------- */
	/* output parameters */
	/* ----------------- */
	char **	outbuffer,	/* the key storage buffer	*/
	int  *	outlen,		/* width of each row		*/
	int  * response 	/* the row count		*/
	)
{
	int	status=0;
	/* -------------------------------- */
	/* perform collect to storage buffer */
	/* -------------------------------- */
        if (( status = inxsql_select_file_records( fptr, dptr, dlen, kptr, klen, outlen, response)) != _SUCCESS)
		return(status);
	else
	{
		*outbuffer = fptr->storage;
		fptr->storage = (char *) 0;
		return( _SUCCESS );
	}
}

#endif

#ifdef	_INXS_STUB_DB

/*	------------------------------------------	*/
/*		F i le   F u n c t i o n s		*/
/*	------------------------------------------	*/

/*	------------	*/
/*	BdIsamCreate	*/
/*	------------	*/
public	void * BdIsamCreate(char * nptr, int cp, int ex, int * e) 	
{ 
	struct	xs_base * bptr;
	int	status;
	/* ------------------------- */
	/* try and open the database */
	/* ------------------------- */
	if (!( nptr = inxsql_process_filename( nptr )))
		return( (void *) 0);
	else if (( bptr = inxsql_open_base( &InXsqlCnx, nptr )) != (struct xs_base *)0)
	{
		bptr = inxsql_close_base( bptr );
		*e = _ERROR_FILE_EXISTS;
		return(bptr);
	}
	/* -------------------------------------- */
	/* create a database management structure */
	/* -------------------------------------- */
	else if (!( bptr = inxsql_allocate_database( &InXsqlCnx, nptr ) ))
	{
		*e = _ERROR_FILE_EXISTS;
		return(bptr);
	}
	/* -------------------------- */
	/* create the actual database */
	/* -------------------------- */
	else if ((status = inxsql_create_database( bptr )) != _SUCCESS )
	{
		bptr = inxsql_close_base( bptr );
		*e = _ERROR_FILE_EXISTS;
		return(bptr);
	}
	/* ----------------------------------------------------- */
	/* attempt to establish open mode as exclusive or shared */
	/* ----------------------------------------------------- */
	else if (( status = inxsql_base_lock( bptr, ex )) == _SUCCESS)
	{ 
		*e = _SUCCESS;
		return(bptr);
	}
	else
	{
		/* ------------------- */
		/* delete the database */
		/* ------------------- */
		(void) inxsql_drop_database(bptr->connection,bptr->name);

		/* ------------------ */
		/* close the database */
		/* ------------------ */
		bptr = inxsql_close_base( bptr );

		/* ---------------- */
		/* indicate failure */
		/* ---------------- */
		*e = status;
		return(bptr);
	}
}

/*	----------	*/
/*	BdIsamOpen	*/
/*	----------	*/
public	void * BdIsamOpen(char * nptr, int cp, int ex, int wr, int * e) 	
{ 
	struct	xs_base * bptr;
	int	status;

	/* ---------------------------- */
	/* attempt to open the database */
	/* ---------------------------- */
	if (!( nptr = inxsql_process_filename( nptr )))
		return( (void *) 0);
	else if (!( bptr = inxsql_open_base( &InXsqlCnx, nptr ) ))
	{
		*e = _ERROR_FILE_NOT_FOUND;
		return( (struct xs_base *) 0);
	}
	/* ----------------------------------------------------- */
	/* attempt to establish open mode as exclusive or shared */
	/* ----------------------------------------------------- */
	else if (( status = inxsql_base_lock( bptr, ex )) == _SUCCESS)
	{ 
		*e = _SUCCESS;
		return( bptr );
	}
	else
	{
		/* ------------- */
		/* access denied */
		/* ------------- */
		bptr = inxsql_close_base( bptr );
		*e = status;
		return( (struct xs_base *) 0);
	}
}

/*	-----------	*/
/*	BdIsamClose	*/
/*	-----------	*/
public	int	BdIsamClose(void * handle) 	
{ 
	struct	xs_base * bptr;
	bptr = inxsql_close_base( handle );
	return(_SUCCESS);
}

/*	------------	*/
/*	BdIsamUnlink	*/
/*	------------	*/
public	int	BdIsamUnlink(char * nptr) 	
{ 
	int	status=0;
	struct	xs_base * bptr;

	if (!( nptr = inxsql_process_filename( nptr )))
		return( _ERROR_SYNTAX );
	else if (!( bptr = inxsql_open_base( &InXsqlCnx, nptr )))
		return( _ERROR_FILE_NOT_FOUND );
	else 
	{
		// delete the database
		status = inxsql_drop_database(bptr->connection,bptr->name);

		// release the database connection
		bptr = inxsql_close_base( bptr );

		// return the operation status
		if ( status != _SUCCESS)
			return( _ERROR_FILE_NOT_FOUND );
		else	return(_SUCCESS);
	}
}

/*	------------	*/
/*	BdIsamRename	*/
/*	------------	*/
public	int	BdIsamRename(void * h, char * nptr) 	
{ 
	int	status=0;
	struct	xs_base * bptr;

	// process an eventual path name
	if (!( nptr = inxsql_process_filename( nptr )))
		return( _ERROR_SYNTAX );

	// perform the database connection
	else if (!( bptr = inxsql_open_base( &InXsqlCnx, nptr )))
		return( _ERROR_FILE_NOT_FOUND );
	else 
	{
		// attempt to rename the database
		status = inxsql_rename_database(h,nptr);

		// release the database connection
		bptr = inxsql_close_base( bptr );

		// return the operation status
		if ( status != _SUCCESS)
			return( _ERROR_FILE_NOT_FOUND );
		else	return(_SUCCESS);
	}
}

/*	-------------	*/
/*	BdIsamAtbOpen	*/
/*	-------------	*/
public	int	BdIsamAtbOpen(struct xs_base * h, int ex, int c) 
{ 
	return( inxsql_base_lock( h, ex ) );
}

/*	----------------	*/
/*	BdIsamCreateFile	*/
/*	----------------	*/
public	void *  BdIsamCreateFile( char * n, struct xs_base * bptr, int * i, int * d, int x, int c, int a, int v, int * e)
{ 
	struct	xs_file * fptr;
	int	status = 0;
	if (!( n = inxsql_process_filename( n )))
	{
		*e = _ERROR_SYNTAX;
		return( (void *) 0);
	}
	else if (!( bptr ))
	{
		*e = _ERROR_SYNTAX;
		return( (void *) 0);
	}
	else if (( fptr = inxsql_locate_base_file( bptr, n, 0 )) != (struct xs_file *) 0)
	{
		*e = _ERROR_FILE_EXISTS;
		return( (void *) 0);
	}
	else if (!( fptr = inxsql_create_file( &InXsqlCnx, n, bptr  )))
	{
		*e = _ERROR_FILE_EXISTS;
		return( fptr );
	}
	else
	{
		fptr->primary.size = *i;
		fptr->datalength = *d;
		if ((status = inxsql_create_table( fptr, a )) != _SUCCESS)
		{
			*e = status;
			return( inxsql_liberate_file( fptr ) );
		}
		else
		{
			*e = _SUCCESS;
			return( fptr );
		}
	}
}

/*	--------------	*/
/*	BdIsamOpenFile	*/
/*	--------------	*/
public	void *	BdIsamOpenFile(char * n, struct xs_base * bptr, int x, int c, int w, int * i, int * d, int * e)
{ 
	struct	xs_file * fptr;
	if (!( bptr ))
	{
		*e = _ERROR_SYNTAX;
		return( (void*) 0);
	}
	else if (( fptr = inxsql_locate_base_file( bptr, n, 1 )) != (struct xs_file *) 0)
	{
		*i = fptr->primary.size;
		*d = fptr->datalength;
		*e = _SUCCESS;
		return(fptr);
	}
	else if (!( fptr = inxsql_create_file(&InXsqlCnx, n, bptr )))
	{
		*e = _ERROR_FILE_NOT_FOUND;
		return( (void *) 0);
	}
	else if (!( *e = inxsql_open_table(fptr) ))
	{
		*i = fptr->primary.size;
		*d = fptr->datalength;
		*e = _SUCCESS;
		return( fptr );
	}
	else	return( inxsql_liberate_file( fptr ) );
}

/*	-----------------	*/
/*	 BdIsamCloseFile	*/
/*	-----------------	*/
public	int	BdIsamCloseFile(struct xs_file * h)
{ 
	if ( h ) { h = inxsql_liberate_file( h ); }
	return(_SUCCESS);
}

/*	----------------	*/
/*	BdIsamUnlinkFile	*/
/*	----------------	*/
public	int	BdIsamUnlinkFile(char * filename, struct xs_base * bptr, int option)
{ 
	struct	xs_file * fptr;
	int	status=0;
	if (!( fptr = inxsql_create_file(&InXsqlCnx, filename,bptr )))
		return( _ERROR_FILE_NOT_FOUND );
	else
	{
		status = inxsql_drop_table( fptr );
		(void) inxsql_liberate_file( fptr );
		return( status );
	}
}

/*	----------------	*/
/*	BdIsamRenameFile	*/
/*	----------------	*/
public	int	BdIsamRenameFile(struct xs_file * h, char * newname) 
{ 
	if (!( newname = inxsql_process_filename( newname )))
		return( _ERROR_SYNTAX);
	else	return( inxsql_rename_table( h, newname ) );
}

/*	--------------		*/
/*	BdIsamInfoFile		*/
/*	--------------		*/
public	int	BdIsamInfoFile(struct xs_file * h,char * bptr, int blen)
{ 
	return(inxsql_file_info(h,bptr,blen));
}


/*	------------------------------------------	*/
/*	      R e c o r d  F u n c t i o n s		*/
/*	------------------------------------------	*/

/*	------------	*/
/*	BdIsamSearch	*/
/*	------------	*/
public	int	BdIsamSearch(struct xs_file * h, int lock, char * iptr, int * mptr, char * rptr, int dlen, int * rlen) 	
{ 
	*mptr = 1;
	*rlen = dlen;
	return( inxsql_retrieve_record( h, iptr, rptr, dlen, lock, rlen ) );
}

/*	------------	*/
/*	BdIsamInsert	*/
/*	------------	*/
public	int	BdIsamInsert(struct xs_file * h,char * iptr, int mq, char * rptr, int l) 	
{ 
	return( inxsql_insert_record( h, iptr, rptr, l ) );
}

/*	------------	*/
/*	BdIsamDelete	*/
/*	------------	*/
public	int	BdIsamDelete(struct xs_file * h,char * iptr, int mq )
{ 
	return( inxsql_delete_record( h, iptr ) );
}

/*	-----------	*/
/*	BdIsamModif	*/
/*	-----------	*/
public	int	BdIsamModif(struct xs_file * h,char * iptr, int mq, char * rptr, int l) 	
{ 
	return( inxsql_update_record( h, iptr, rptr, l ) );
}

/*	------------	*/
/*	BdIsamUpDown	*/
/*	------------	*/
public	int	BdIsamUpDown(struct xs_base * h, int dir, int lock, int * marq, char * dptr, int dlen)
{
	*marq = 1;
	if ( dir == 1 ) 
		return( inxsql_next_base_record( h, dptr, dlen, lock ) );
	else	return( inxsql_previous_base_record( h, dptr, dlen, lock ) );
}

/*	----------------	*/
/*	BdIsamUpDownFile	*/
/*	----------------	*/
public	int	BdIsamUpDownFile(struct xs_file * h, int dir, int lock, int * mptr, char * rptr, int dlen, int * rlen)  	
{ 
	*mptr = 1;
	*rlen = dlen;
	if ( dir == 1 ) 
		return( inxsql_next_record( h, rptr, dlen, lock, rlen ) );
	else	return( inxsql_previous_record( h, rptr, dlen, lock, rlen ) );
}

/*	------------------------------------------	*/
/*	      I n d e x    F u n c t i o n s		*/
/*	------------------------------------------	*/

/*	----------	*/
/*	BdIsamCkey	*/
/*	----------	*/
public	int	BdIsamCkey(struct xs_file * h,char * nptr, int length, int type)
{
#ifdef	DEBUG_CKEY
	char *	sptr;
	fprintf(stderr,"BD ISAM KEY : ");
	for ( sptr = nptr; *sptr != ' '; sptr++ ) fprintf(stderr, "%c",*sptr);
	fprintf(stderr,", %u, %x \n", length, type);
#endif
	switch ( type & 0x000F )
	{
	case	_XS_KEY_A	:	/* historic binary string type */
		return( inxsql_append_field( h, nptr, length, _INXS_BIN, 0 ) );
	case	_XS_KEY_S	:	/* new standard string type */
		return( inxsql_append_field( h, nptr, length, _INXS_STRING, 0 ) );
	case	_XS_KEY_N	:	/* historic numerical type */
		switch ( length )
		{
		case	1 :
			return( inxsql_append_field( h, nptr, length, _INXS_INT8, 0 ) );
		case	2 :
			return( inxsql_append_field( h, nptr, length, _INXS_INT16, 0 ) );
		default	  :
			return( inxsql_append_field( h, nptr, length, _INXS_BCD, ((type & 0x00F0) >> 4) ) );
		}
	case	_XS_KEY_F	:	/* new NUMERIC type */
		return( inxsql_append_field( h, nptr, length, _INXS_BCD, ((type & 0x00F0) >> 4) ) );
	case	_XS_KEY_L	:	/* new LONG type */
		return( inxsql_append_field( h, nptr, length, _INXS_INT32, 0 ) );
	case	_XS_KEY_H	:	/* new HUGE type */
		return( inxsql_append_field( h, nptr, length, _INXS_INT64, 0 ) );
	case	_XS_KEY_D	:	/* new DATE type */
		return( inxsql_append_field( h, nptr, length, _INXS_DATE, 0 ) );
	case	_XS_KEY_T	:	/* new TIME type */
		return( inxsql_append_field( h, nptr, length, _INXS_TIME, 0 ) );
	default		:
		return( inxsql_append_field( h, nptr, length, _INXS_STRING, 0 ) );
	}
}

/*	----------	*/
/*	BdIsamNkey	*/
/*	----------	*/
public	int	BdIsamNkey(struct xs_file * h,char * oldname,char * newname) 	
{ 
	return( inxsql_rename_field( h, oldname, newname ) );
}

/*	----------	*/
/*	BdIsamFkey	*/
/*	----------	*/
public	int	BdIsamFkey(struct xs_file * h,char * parent, char * child, int length,int type, int offset) 	
{ 
	return( inxsql_append_field( h, child, length, type, 0 ) );
}

/*	----------	*/
/*	BdIsamCndx	*/
/*	----------	*/
public	int	BdIsamCndx(struct xs_file * h, char * descriptor,int length)
{
	return(inxsql_create_index(h,descriptor,length,1)); 
}

/*	----------	*/
/*	BdIsamDndx	*/
/*	----------	*/
public	int	BdIsamDndx(struct xs_file * h, char * descriptor,int length) 	
{
	return(inxsql_drop_index(h,descriptor,length,1)); 
}

/*	-----------	*/
/*	BdIsamDCndx	*/
/*	-----------	*/
public	int	BdIsamDCndx(struct xs_file * h, char * descriptor,int length)
{
	return(inxsql_create_index(h,descriptor,length,0)); 
}

/*	-----------	*/
/*	BdIsamDDndx	*/
/*	-----------	*/
public	int	BdIsamDDndx(struct xs_file * h, char * descriptor,int length) 	
{
	return(inxsql_drop_index(h,descriptor,length,0)); 
}

/*	------------	*/
/*	BdIsamUpdndx	*/
/*	------------	*/
public	int	BdIsamUpdndx(struct xs_file * h) 
{ 
	return(inxsql_update_indexes(h)); 
}

/*	------------------------------------------	*/
/*	   D a t a b a s e  F u n c t i o n s		*/
/*	------------------------------------------	*/

/*	-----------	*/
/*	BdIsamCount	*/
/*	-----------	*/
public	int	BdIsamCount(struct xs_base * h,char * dptr,int uni,int seq,int dlen, int * response )
{
	return(inxsql_count_base_records( h, dptr, dlen, uni, seq, response)); 
}

/*	-----------	*/
/*	BdIsamPosit	*/
/*	-----------	*/
public	int	BdIsamPosit(struct xs_base * h,char * dptr,int uni,int seq,int last, int dlen, int * response )
{
	return(inxsql_position_base_records( h, dptr, dlen, last, uni, seq, response)); 
}

/*	----------	*/
/*	BdIsamJoin	*/
/*	----------	*/
public	int	BdIsamJoin(struct xs_base * h, char * dptr, int dlen) 	
{ 
	return(inxsql_declare_join(h,dptr,dlen)); 
}

/*	-----------	*/
/*	BdIsamCJoin	*/
/*	-----------	*/
public	int	BdIsamCjoin(struct xs_base * h, char * dptr, int dlen, int type) 	
{ 
	return(inxsql_create_join(h,dptr,dlen,type)); 
}

/*	-----------	*/
/*	BdIsamDJoin	*/
/*	-----------	*/
public	int	BdIsamDjoin(struct xs_base * h, char * name) 	
{ 
	return(inxsql_delete_join(h,name));
}

/*	-----------	*/
/*	BdIsamRJoin	*/
/*	-----------	*/
public	int	BdIsamRjoin(struct xs_base * h, char * dptr, int dlen) 	
{ 
	return(inxsql_rename_join(h,dptr,dlen)); 
}

/*	----------	*/
/*	BdIsamInfo	*/
/*	----------	*/
public	int	BdIsamInfo(struct xs_base * h,char * bptr, int blen)
{ 
	return(inxsql_base_info(h,bptr,blen));
}

/*	-----------	*/
/*	BdIsamLfile	*/
/*	-----------	*/
public	int	BdIsamLfile(struct xs_base * h, char * dptr, int dlen, int option) 	
{ 
	int 	e = inxsql_list_basefile(h,dptr,dlen,option); 
	return( e );
}

/*	-----------	*/
/*	BdIsamLjoin	*/
/*	-----------	*/
public	int	BdIsamLjoin( struct xs_base * h, char * dptr, int dlen, int option)
{ 
	int 	e = inxsql_list_joins(h,dptr,dlen,option); 
	return( e );
}

/*	----------	*/
/*	BdIsamLkey	*/
/*	----------	*/
public	int	BdIsamLkey( struct xs_file * h, char * dptr, int dlen, int option)
{ 
	int 	e = inxsql_list_columns(h,dptr,dlen,option); 
	return( e );
}

/*	-----------	*/
/*	BdIsamLlink	*/
/*	-----------	*/
public	int	BdIsamLlink( struct xs_file * h, char * dptr, int dlen, int option)
{ 
	int 	e = inxsql_list_indexes(h,dptr,dlen,option); 
	return( e );
}

#endif

	/* ----------- */
#endif	/* _libinxsql_c */
	/* ----------- */


