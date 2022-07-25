#ifndef	_inxsql_lock_c
#define _inxsql_lock_c

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

/*	-------------------------	*/
/*	inxsql_commit_transaction	*/
/*	-------------------------	*/
public	int	inxsql_commit_transaction( struct xs_connection * xptr )
{
        char    query[_STD_QUERY_LENGTH];
	if (!( xptr->transaction ))
		return( _SUCCESS );
	else
	{
	
	        if ( verbose ) printf("inxsql_start_lock_transaction()\n");
	        sprintf(query,"COMMIT WORK AND NO CHAIN NO RELEASE");
		xptr->transaction = 0;
	        return( inxsql_standard_query( xptr, query, strlen(query), _SUCCESS ) );
	}
}

/*	------------------------	*/
/*	inxsql_start_transaction	*/
/*	------------------------	*/
public	int	inxsql_start_transaction( struct xs_connection * xptr )
{
        char    query[_STD_QUERY_LENGTH];
	if (!( xptr->transaction ))
	{
        	if ( verbose ) printf("inxsql_start_lock_transaction()\n");
        	sprintf(query,"START TRANSACTION READ WRITE");
		xptr->transaction = 1;
        	return( inxsql_standard_query( xptr, query, strlen(query), _SUCCESS ) );
	}
	else	return( _SUCCESS );
}

/*      -------------------     */
/*      inxsql_acquire_lock     */
/*      -------------------     */
private int inxsql_acquire_lock( struct xs_connection * xptr, char * nptr )
{
#define _INXSQL_USE_GET_LOCK
#ifdef  _INXSQL_USE_GET_LOCK
        char    query[_STD_QUERY_LENGTH];
        if ( verbose ) printf("inxsql_acquire_lock(%s)\n",nptr);
        sprintf(query,"SELECT GET_LOCK('%s',%u)",nptr,_INXS_LOCK_TIME);
        return( inxsql_standard_query( xptr, query, strlen(query), _ERROR_FILE_LOCKED ) );
#else
        return(_SUCCESS);
#endif
}

/*      -------------------     */
/*      inxsql_release_lock     */
/*      -------------------     */
private int inxsql_release_lock( struct xs_connection * xptr, char * nptr )
{
#ifdef  _INXSQL_USE_GET_LOCK
        char    query[_STD_QUERY_LENGTH];
        if ( verbose ) printf("inxsql_release_lock(%s)\n",nptr);
        sprintf(query,"SELECT RELEASE_LOCK('%s')",nptr);
        return( inxsql_standard_query( xptr, query, strlen(query), _ERROR_FILE_LOCKED ) );
#else
        return(_SUCCESS);
#endif
}

/*      ----------------        */
/*      inxsql_file_lock        */
/*      ----------------        */
interface int inxsql_file_lock( struct xs_file * fptr, int requested )
{
        int     status=_SUCCESS;

        /* -------------------------------------- */
        /* database tables cannot be locked alone */
        /* -------------------------------------- */
        if ( fptr->base != (struct xs_base *) 0)
                return(_ERROR_NOT_ALLOWED);

        /* ----------------------------- */
        /* acquire the lock as requested */
        /* ----------------------------- */
	else if ((   requested & _INXS_FILE_LOCK   )	
             &&  (!( fptr->lock & _INXS_FILE_LOCK )))
        {
                if ((status = inxsql_acquire_lock( fptr->connection, inxsql_table_name(fptr) )) == _SUCCESS)
                        fptr->lock |= _INXS_FILE_LOCK;
                return( status );
        }
        /* ----------------------------- */
        /* release the lock as requested */
        /* ----------------------------- */
	else if ((!( requested & _INXS_FILE_LOCK  ))	
             &&  (   fptr->lock & _INXS_FILE_LOCK  ))
        {
                if ((status = inxsql_release_lock( fptr->connection, inxsql_table_name(fptr) )) == _SUCCESS)
                        fptr->lock &= ~_INXS_FILE_LOCK;
                return( status );
        }
	/* ------------------ */
	/* no change required */
	/* ------------------ */
	else
	{
                return( _SUCCESS );
	}
}

/*      ----------------        */
/*      inxsql_base_lock        */
/*      ----------------        */
interface int inxsql_base_lock( struct xs_base * bptr, int requested)
{
        int     status=_SUCCESS;

        /* ----------------------------- */
        /* acquire the lock as requested */
        /* ----------------------------- */
	if ((   requested & _INXS_FILE_LOCK   )	
        &&  (!( bptr->lock & _INXS_FILE_LOCK )))
        {
                if ((status = inxsql_acquire_lock( bptr->connection, bptr->name )) == _SUCCESS)
                        bptr->lock |= _INXS_FILE_LOCK ;
                return( status );
        }
        /* ----------------------------- */
        /* release the lock as requested */
        /* ----------------------------- */
	else if ((!( requested & _INXS_FILE_LOCK  ))	
             &&  (   bptr->lock & _INXS_FILE_LOCK  ))
        {
                if ((status = inxsql_release_lock( bptr->connection, bptr->name )) == _SUCCESS)
                        bptr->lock &= ~_INXS_FILE_LOCK;
                return( status );
        }
	/* ------------------ */
	/* no change required */
	/* ------------------ */
	else
	{
                return( _SUCCESS );
	}
}

/*	-----------------------------------------------------------	*/
/*	IJM: 7/7/2022							*/
/*	-----------------------------------------------------------	*/
/*	this has been added to see if the locking conflict that has 	*/
/*	been encountered between SEARCH.M and INXSQUERY updates has	*/
/*	been caused by the hard hitting RECORD locking.			*/
/*	-----------------------------------------------------------	*/
private int avoid_lock_bug=1;

/*	---------------------------	*/
/*	 inxsql_file_unlock_record	*/
/*	---------------------------	*/

public  int inxsql_file_unlock_record( struct xs_file * fptr)
{
	char	lockname[_INXS_LOCK_NAME_SIZE];	
	int	status=_SUCCESS;
	if ( avoid_lock_bug )
		return( _SUCCESS );
	else if ( fptr->lock & _INXS_RECORD_LOCK )
	{
		sprintf(lockname,"%s.rl",inxsql_table_name(fptr));
		if ((status = inxsql_release_lock( fptr->connection, lockname )) != _SUCCESS )
			return( _ERROR_FILE_LOCKED );
		else	fptr->lock &= ~_INXS_RECORD_LOCK;
	}
	return( _SUCCESS );
}

/*	-------------------------	*/
/*	 inxsql_file_lock_record	*/
/*	-------------------------	*/
public  int inxsql_file_lock_record( struct xs_file * fptr)
{
	char	lockname[_INXS_LOCK_NAME_SIZE];	
	int	status=_SUCCESS;
	if ( avoid_lock_bug )
		return( _SUCCESS );
	else if (!( fptr->lock & _INXS_RECORD_LOCK ))
	{
		sprintf(lockname,"%s.rl",inxsql_table_name(fptr));
		if ((status = inxsql_acquire_lock( fptr->connection, lockname )) != _SUCCESS )
			return( _ERROR_FILE_LOCKED );
		fptr->lock |= _INXS_RECORD_LOCK;
	}
	return( _SUCCESS );
}

/*	---------------------------	*/
/*	 inxsql_base_unlock_record	*/
/*	---------------------------	*/
public  int inxsql_base_unlock_record( struct xs_base * bptr)
{
	struct xs_file * fptr;
	int	status=_SUCCESS;
	for (	fptr = bptr->first;
		fptr != (struct xs_file *) 0;
		fptr = fptr->next )
		if ( fptr->lock & _INXS_RECORD_LOCK )
			if ((status = inxsql_file_unlock_record(fptr)) != _SUCCESS )
				break;
	return( status );
}

/*	-------------------------	*/
/*	 inxsql_base_lock_record	*/
/*	-------------------------	*/
public  int inxsql_base_lock_record( struct xs_base * bptr )
{
	struct xs_file * fptr;
	int	status=_SUCCESS;
	for (	fptr = bptr->first;
		fptr != (struct xs_file *) 0;
		fptr = fptr->next )
		if ( fptr->usage == bptr->requests )
			if ((status = inxsql_file_lock_record(fptr)) != _SUCCESS )
				break;
	return( status );
}

#endif /* _inxsql_lock_c */

