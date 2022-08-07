#ifndef	_inxsql_file_c
#define	_inxsql_file_c

/*	------------------------------------------------	*/
/*								*/
/*	INXSQL : Database Client Library for ABAL and D3	*/
/*								*/
/*	------------------------------------------------	*/
/*								*/
/*	     Copyright (c) 2014-2021 Amenesik SARL		*/
/*								*/
/*	    Iain James Marshall  <ijm@amenesik.com>		*/
/*								*/
/*	------------------------------------------------	*/

/*	--------------------	*/
/*	inxsql_liberate_file	*/
/*	--------------------	*/
public  struct xs_file * inxsql_liberate_file( struct xs_file * fptr )
{
	struct	xs_view  * vptr;
	struct	xs_field * cptr;
	struct	xs_index * iptr;
	if ( verbose ) printf("inxsql_liberate_file()\r\n");
	if ( fptr )
	{
#ifdef	_INXSQL_MYSQL
		/* --------------------------- */
		/* release prepared statements */
		/* --------------------------- */
		if ( fptr->insert != (MYSQL_STMT *) 0)
		{
			mysql_stmt_close(fptr->insert);
			fptr->insert = (MYSQL_STMT *) 0;
		}
		if ( fptr->update != (MYSQL_STMT *) 0)
		{
			mysql_stmt_close(fptr->update);
			fptr->update = (MYSQL_STMT *) 0;
		}

		/* ------------------------- */
		/* release prepared bindings */
		/* ------------------------- */
		if ( fptr->inserting != (MYSQL_BIND *) 0)
			fptr->inserting = liberate(fptr->inserting);
		if ( fptr->updating != (MYSQL_BIND *) 0)
			fptr->updating = liberate(fptr->updating);
		if ( fptr->record )
			fptr->record = liberate( fptr->record );
#endif

		/* ------------------------ */
		/* release a posit view now */
		/* ------------------------ */
		(void) inxsql_drop_file_view( fptr );

		/* --------------------- */
		/* release the file lock */
		/* --------------------- */
		(void) inxsql_file_lock( fptr, _INXS_UNLOCKED );

		/* ------------- */
		/* drop the view */
		/* ------------- */
		(void) inxsql_drop_file_view( fptr );

		/* -------------------------- */
		/* release the collect buffer */
		/* -------------------------- */
		(void) inxsql_liberate_storage( fptr );

		/* ------------------------------------------- */
		/* remove from database list is database table */
		/* ------------------------------------------- */
		if ( fptr->base )
		{
			if ( fptr->previous )
				fptr->previous->next = fptr->next;
			else	fptr->base->first = fptr->next;
			if ( fptr->next )
				fptr->next->previous = fptr->previous;
			else	fptr->base->last = fptr->previous;
			fptr->base = (struct xs_base *) 0;
			fptr->connection = (struct xs_connection *) 0;
		}

		/* ------------------------------------------ */
		/* remove from default database is SIMC Table */
		/* ------------------------------------------ */
		else if ( fptr->connection )
		{
			if ( fptr->previous )
				fptr->previous->next = fptr->next;
			else	fptr->connection->first = fptr->next;
			if ( fptr->next )
				fptr->next->previous = fptr->previous;
			else	fptr->connection->last = fptr->previous;

			fptr->connection = (struct xs_connection *) 0;
		}

		/* ----------------------- */
		/* release the table views */
		/* ----------------------- */
		while ((vptr = fptr->firstview) != (struct xs_view *) 0)
		{
			if (!( fptr->firstview = vptr->next ))
				fptr->lastview = (struct xs_view *) 0;
			else	vptr->next = (struct xs_view *) 0;
			vptr->previous = (struct xs_view *) 0;
			vptr = inxsql_liberate_view( vptr );
		}

		/* ------------------------- */
		/* release the table indexes */
		/* ------------------------- */
		while ((iptr = fptr->firstindex) != (struct xs_index *) 0)
		{
			if (!( fptr->firstindex = iptr->next ))
				fptr->lastindex = (struct xs_index *) 0;
			else	iptr->next = (struct xs_index *) 0;
			iptr->previous = (struct xs_index *) 0;
			iptr = inxsql_liberate_index( iptr );
		}

		/* ------------------------- */
		/* release the table columns */
		/* ------------------------- */
		while ((cptr = fptr->first) != (struct xs_field *) 0)
		{
			if (!( fptr->first = cptr->next ))
				fptr->last = (struct xs_field *) 0;
			else	cptr->next = (struct xs_field *) 0;
			cptr->previous = (struct xs_field *) 0;
			cptr = inxsql_liberate_field( cptr );
		}

		/* ---------------------- */
		/* release the table name */
		/* ---------------------- */
		if ( fptr->name )
			fptr->name = liberate( fptr->name );

		liberate( fptr ); 
	}
	return( (struct xs_file *) 0 );
}

/*	--------------------	*/
/*	inxsql_allocate_file	*/
/*	--------------------	*/
public  struct xs_file * inxsql_allocate_file( char * filename )
{
	struct	xs_file * fptr;
	char	primaryname[2014];
	if (!( fptr = allocate( sizeof( struct xs_file ) ) ))
		return( fptr );
	else
	{
		memset(fptr, 0, sizeof( struct xs_file ));
	}

	sprintf(primaryname,"%s%s",filename,_INXS_DEFAULT_PRIMARY);
	if (!( fptr->name = inxsql_allocate_string( filename) ))
		return( inxsql_liberate_file( fptr ) );
	else if (!( fptr->primary.name = inxsql_allocate_string( primaryname) ))
		return( inxsql_liberate_file( fptr ) );
	else
	{
		fptr->first = (struct xs_field *) 0;
		fptr->last  = (struct xs_field *) 0;
		fptr->firstindex = (struct xs_index *) 0;
		fptr->lastindex  = (struct xs_index *) 0;
		fptr->selection  = (struct xs_index *) 0;
		fptr->base = (struct xs_base *) 0;
		fptr->primary.size = 8;
		fptr->primary.type = _INXS_STRING;
		fptr->primary.extra = 0;
		fptr->usage = 0;
		fptr->qlength = 0;
		fptr->blength = 0;
		fptr->storage = (char *) 0;
		fptr->storagelength = 0;
		fptr->storageoffset = 0;
                fptr->lock = _INXS_UNLOCKED;
#ifdef	_INXSQL_MYSQL
		fptr->insert = (MYSQL_STMT *) 0;
		fptr->update = (MYSQL_STMT *) 0;
		fptr->inserting = (MYSQL_BIND *) 0;
		fptr->updating = (MYSQL_BIND *) 0;
#endif
		fptr->record = (unsigned char *) 0;
		strcpy( fptr->name, filename );
		return( fptr );
	}
}

/*	-------------------	*/
/*	inxsql_connect_file	*/
/*	-------------------	*/
private	void	inxsql_connect_file( struct xs_file * fptr, struct xs_connection * xptr, struct xs_base * bptr )
{
	fptr->connection = xptr;
	if (!( bptr ))
	{
		if (!( fptr->previous = xptr->last ))
			xptr->first = fptr;
		else	xptr->last->next = fptr;
		xptr->last = fptr;
	}
	else
	{
		if (!( fptr->previous = bptr->last ))
			bptr->first = fptr;
		else	bptr->last->next = fptr;
		bptr->last = fptr;
		fptr->base = bptr;
	}
	return;
}

/*	----------------	*/
/*	inxsql_copy_file	*/
/*	----------------	*/
public  struct xs_file * inxsql_copy_file( struct xs_file * sptr )
{
	struct	xs_file * fptr;
	struct	xs_field * cptr;
	struct	xs_field * kptr;
	struct	xs_index * iptr;
	struct	xs_index * jptr;

	/* ------------------------------------ */
	/* duplicate the file control structure */
	/* ------------------------------------ */
	if (!( sptr ))
		return( sptr );
	else if (!( sptr->name ))
		return((struct xs_file *) 0 );
	else if (!( fptr = inxsql_allocate_file( sptr->name ) ))
		return( fptr );
	else
	{
		/* ------------------------- */
		/* duplicate the column list */
		/* ------------------------- */
		for (	cptr = sptr->first;
			cptr != (struct xs_field *) 0;
			cptr = cptr->next )
			if (!( kptr = inxsql_copy_field( fptr, cptr ) ))
				return( inxsql_liberate_file( fptr ) );	

		/* ------------------------ */
		/* duplicate the index list */
		/* ------------------------ */
		for (	iptr = sptr->firstindex;
			iptr !=(struct xs_index *) 0;
			iptr = iptr->next )
			if (!( jptr = inxsql_copy_index( fptr, iptr ) ))
				return( inxsql_liberate_file( fptr ) );	

		/* -------------------------- */
		/* duplicate file information */
		/* -------------------------- */
		fptr->maxkey = sptr->maxkey;
		fptr->datalength = sptr->datalength;
		fptr->usage = sptr->usage;
		fptr->flength = sptr->flength;
		fptr->qlength = sptr->qlength;
		fptr->blength = sptr->blength;
		fptr->primary.type = sptr->primary.type;
		fptr->primary.size = sptr->primary.size;
		fptr->primary.extra = sptr->primary.extra;
		fptr->primary.offset = sptr->primary.offset;
		fptr->align = sptr->align;

		/* -------------------------------------- */
		/* connect the file to base or connection */
		/* -------------------------------------- */
		inxsql_connect_file( fptr, sptr->connection, sptr->base );	
		return( fptr );
	}
}

/*	------------------		*/
/*	inxsql_locate_file		*/
/*	------------------		*/
public  struct xs_file * inxsql_locate_file( struct xs_connection * xptr, char * filename, int copy )
{
	struct xs_file * fptr;
	if ( verbose ) printf("inxsql_locate_file()\r\n");
	for (	fptr = xptr->first;
		fptr != (struct xs_file *) 0;
		fptr = fptr->next )
	{
		if (!( fptr->name ))
			continue;
		else if (!( strcmp( fptr->name, filename ) ))
			break;
	}
	if (!( copy ))
		return( fptr );
	else	return( inxsql_copy_file(fptr) );
}

/*	-----------------------		*/
/*	inxsql_locate_base_file		*/
/*	-----------------------		*/
public  struct xs_file * inxsql_locate_base_file( struct xs_base * bptr, char * filename, int copy )
{
	struct xs_file * fptr;
	if ( verbose ) printf("inxsql_locate_file()\r\n");
	for (	fptr = bptr->first;
		fptr != (struct xs_file *) 0;
		fptr = fptr->next )
	{
		if (!( fptr->name ))
			continue;
		else if (!( strcmp( fptr->name, filename ) ))
			break;
	}
	if (!( copy ))
		return( fptr );
	else	return( inxsql_copy_file(fptr) );
}

/*	------------------		*/
/*	inxsql_create_file		*/
/*	------------------		*/
public  struct xs_file * inxsql_create_file( struct xs_connection * xptr, char * filename, struct xs_base * bptr )
{
	struct xs_file * fptr;
	if ( verbose ) printf("inxsql_create_file()\r\n");
	if (!( fptr = inxsql_allocate_file( filename ) ))
		return((struct xs_file *) 0);
	else
	{
		inxsql_connect_file(fptr, xptr, bptr);
		fptr->first = 
		fptr->last  =
		fptr->current = (struct xs_field *) 0;
		fptr->firstview = 
		fptr->lastview  =
		fptr->view = (struct xs_view *) 0;
		fptr->firstindex = 
		fptr->lastindex  =
		fptr->currentindex = (struct xs_index *) 0;

		if (!( bptr ))
			fptr->maxkey = xptr->maxkey;
		else	fptr->maxkey = bptr->maxkey;

		memset(fptr->lastkey,' ',_PRIMARY_KEY_MAX);
		return( fptr );
	}
}

/*	----------------------	*/
/*	inxsql_file_desription	*/
/*	----------------------	*/
public	int	inxsql_file_description(struct xs_file * fptr, char * dptr, int dlen )
{
	if (!( fptr ))
		return( _ERROR_CONNECTION );
	else if (!( dptr ))
		return( _ERROR_SYNTAX );
	else if (!( dlen ))
		inxsql_buffer_too_small(fptr);
	else if ( dlen < _ABAL_INFO_SIZE )
		inxsql_buffer_too_small(fptr);
	else
	{
		/* ---------------- */
		/* reset all fields */
		/* ---------------- */
		memset(dptr, 0, dlen);

		dptr[0] = ((fptr->datalength & 0xFF00) >> 8);
		dptr[1] = (fptr->datalength & 0x00FF);
		dptr[2] = ((fptr->primary.size & 0xFF00) >> 8);
		dptr[1] = (fptr->primary.size & 0x00FF);
		dptr[4] = fptr->align;

		return( _SUCCESS );
	}
}

/*	----------------	*/
/*	inxsql_file_info	*/
/*	----------------	*/
public	int	inxsql_file_info(struct xs_file * fptr, char * dptr, int dlen )
{
	struct	xs_field * cptr=(struct xs_field *) 0;
	struct	xs_index * iptr=(struct xs_index *) 0;
	int	number=0;

	if (!( fptr ))
		return( _ERROR_CONNECTION );
	else if (!( dptr ))
		return( _ERROR_SYNTAX );
	else if (!( dlen ))
		inxsql_buffer_too_small(fptr);
	else if ( dlen < _ABAL_STATS_SIZE )
		inxsql_buffer_too_small(fptr);
	else
	{
		/* ---------------- */
		/* reset all fields */
		/* ---------------- */
		memset(dptr, 0, dlen);

		/* -------------------------- */
		/* specify length and version */
		/* -------------------------- */
		dptr[0] = dlen;
		dptr[1] = _INXS_VERSION;

		/* ----------------------------- */
		/* indicates the INXSQL Database */
		/* ----------------------------- */
		dptr[12] = _INXS_MAGIC;
	
		/* ---------------- */	
		/* count the fields */
		/* ---------------- */	
		for ( 	number= 0, cptr = fptr->first; 
			cptr != (struct xs_field *) 0; 
			cptr = cptr->next )
			number++;

		dptr[15] = number;

		/* ---------------- */	
		/* count the indexs */
		/* ---------------- */	
		for ( 	number= 0, cptr = fptr->first; 
			cptr != (struct xs_field *) 0; 
			cptr = cptr->next )
			number++;

		dptr[16] = number;

		return( _SUCCESS );
	}
}

/*	----------------	*/
/*	inxsql_base_info	*/
/*	----------------	*/
public	int	inxsql_base_info(struct xs_base * bptr, char * dptr, int dlen )
{
	struct	xs_file  * fptr=(struct xs_file *) 0;
	struct	xs_joint * jptr=(struct xs_joint *) 0;;
	int	number;

	if (!( bptr ))
		return( _ERROR_CONNECTION );
	else if (!( dptr ))
		return( _ERROR_SYNTAX );
	else if (!( dlen ))
		inxsql_buffer_too_small(bptr);
	else if ( dlen < _ABAL_STATS_SIZE )
		inxsql_buffer_too_small(bptr);
	else
	{
		/* ---------------- */
		/* reset all fields */
		/* ---------------- */
		memset(dptr, 0, dlen);

		/* -------------------------- */
		/* specify length and version */
		/* -------------------------- */
		dptr[0] = dlen;
		dptr[1] = _INXS_VERSION;

		/* ----------------------------- */
		/* indicates the INXSQL Database */
		/* ----------------------------- */
		dptr[12] = _INXS_MAGIC;
	
		/* --------------- */	
		/* count the files */
		/* --------------- */	
		for ( 	number= 0, fptr = bptr->first; 
			fptr != (struct xs_file *) 0; 
			fptr = fptr->next )
			number++;

		dptr[15] = number;

		/* ---------------- */	
		/* count the joints */
		/* ---------------- */	
		for ( 	number= 0, jptr = bptr->firstjoint; 
			jptr != (struct xs_joint *) 0; 
			jptr = jptr->next )
			number++;

		dptr[16] = number;

		return( _SUCCESS );
	}
}

/*	-----------------------------------------------------------	*/
/*		i n x s q l _ p r o c e s s _ f i l e n a m e		*/
/*	-----------------------------------------------------------	*/
/*	ABAL filenames usually have a PATH prefix. MYSQL does not	*/
/*	allow tables and databases to have path prefixes so this is	*/
/*	ignored for now. Will be handled better later. TODO		*/
/*	-----------------------------------------------------------	*/

public	char *	inxsql_process_filename( char * filename )
{
	char *	pptr;
	if (!( pptr = strrchr( filename, '/' ) ))
		return( filename );
	else	return( (pptr+1) );
}

/*	-----------------------------------------------------------	*/
/*		  i n x s q l _ f i l e _ q l e n g t h 		*/
/*	-----------------------------------------------------------	*/
/*	calculates and returns the additional query length required	*/
/*	for the addition of all the column names			*/
/*	-----------------------------------------------------------	*/

public	int	inxsql_file_qlength(struct xs_file * fptr)
{
	struct xs_field * cptr=(struct xs_field *) 0;
	if (!( fptr->qlength ))
	{
		for (	cptr = fptr->first;
			cptr != (struct xs_field *) 0;
			cptr = cptr->next )
		{
			fptr->qlength += (strlen(cptr->name) + 3);
			fptr->flength += inxsql_field_qsize(cptr);
		}
	}
	return( fptr->qlength );
}

/*	-------------------	*/
/*	inxsql_file_flength	*/
/*	-------------------	*/
public	int	inxsql_file_flength(struct xs_file * fptr)
{
	struct xs_field * cptr=(struct xs_field *) 0;
	if (!( fptr->flength ))
	{
		for (	cptr = fptr->first;
			cptr != (struct xs_field *) 0;
			cptr = cptr->next )
		{
			fptr->qlength += (strlen(cptr->name) + 3);
			fptr->flength += inxsql_field_size(cptr);
		}
	}
	return( fptr->flength );
}

/*	-------------------	*/
/*	inxsql_file_blength	*/
/*	-------------------	*/
public	int	inxsql_file_blength(struct xs_file * fptr)
{
	struct xs_field * cptr=(struct xs_field *) 0;
	if (!( fptr->blength ))
	{
		for (	cptr = fptr->first;
			cptr != (struct xs_field *) 0;
			cptr = cptr->next )
			fptr->blength += inxsql_field_bsize(cptr);
	}
	return( fptr->blength );
}

#endif	/* _inxsql_file */

