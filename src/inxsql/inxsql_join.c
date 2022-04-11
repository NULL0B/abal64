#ifndef	_inxsql_join_c
#define _inxsql_join_c

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
/*      This file manages SQL JOINTURES for the BD 		*/
/*      instructions of ABAL.                                   */
/*                                                              */
/*      ------------------------------------------------        */

#undef 	DEBUG_INXS_JOIN

#ifdef	DEBUG_INXS_JOIN
/*	-----------------	*/
/*	inxsql_show_joint	*/
/*	-----------------	*/
private	void	inxsql_show_joint( struct xs_joint * jptr )
{
	struct	xs_clause * lptr;
	struct	xs_file   * fptr;
	struct	xs_field  * cptr;
	char *	sep="";
	printf("join ( ");
	for (	lptr = jptr->first;
		lptr != (struct xs_clause *) 0;
		lptr = lptr->next )
	{
		if (!( cptr = lptr->left ))
			continue;
		else if (!( fptr = cptr->file ))
			continue;
		else 	printf("%s%s.%s",sep,fptr->name,cptr->name);

			switch ( lptr->operator )
			{
			case	_INXS_JOIN_EQ	: printf( " = "); break;
			case	_INXS_JOIN_NE	: printf( " <> "); break;
			case	_INXS_JOIN_GT	: printf( " > "); break;
			case	_INXS_JOIN_GE	: printf( " >= "); break;
			case	_INXS_JOIN_LT	: printf( " < "); break;
			case	_INXS_JOIN_LE	: printf( " <= "); break;
			case	_INXS_JOIN_BTF	: printf( " Between "); break;
			case	_INXS_JOIN_BTL	: printf( " And "); break;
			}

		if (!( cptr = lptr->left ))
			continue;
		else if (!( fptr = cptr->file ))
			continue;
		else 	printf("%s.%s",fptr->name,cptr->name);
		sep = ",";
	}
	printf(" )\r\n");
	return;
}
#endif	/* DEBUG_INXS_JOIN */

/*      -----------------------    */
/*      inxsql_allocate_clause 	   */
/*      -----------------------    */
public  struct xs_clause * inxsql_allocate_clause(struct xs_joint *jptr, struct xs_field * lptr, int operator, struct xs_field * rptr)
{
        struct xs_clause * cptr;
        if (!( cptr = allocate( sizeof( struct xs_clause ) ) ))
                return(cptr);
        else
        {
		/* ------------------------------ */
		/* prepare the clause information */
		/* ------------------------------ */
                cptr->previous = (struct xs_clause*) 0;
                cptr->next = (struct xs_clause*) 0;
                cptr->left = lptr;
                cptr->right = rptr;
		cptr->operator = operator;
		if ((cptr->join = jptr) != (struct xs_joint *) 0)
		{
			/* ------------------------ */
			/* chain it to the jointure */
			/* ------------------------ */
			if (!( cptr->previous = jptr->last ))
				jptr->first = cptr;
			else	cptr->previous->next = cptr;
			jptr->last = cptr;
		}
                return( cptr );
        }
}

/*      ----------------------    */
/*      inxsql_liberate_clause    */
/*      ----------------------    */
public  struct xs_clause * inxsql_liberate_clause(struct xs_clause* lptr)
{
        if ( lptr )
        {
                liberate( lptr );
        }
        return( (struct xs_clause*) 0);
}

/*      ---------------------   */
/*      inxsql_liberate_joint   */
/*      ---------------------   */
public  struct xs_joint * inxsql_liberate_joint(struct xs_joint * jptr)
{
        struct  xs_clause * lptr;
        if ( jptr )
        {
                /* -------------------------------- */
                /* release the list of clause terms */
                /* -------------------------------- */
                while ((lptr = jptr->first) != (struct xs_clause *) 0)
                {
                        if (!(jptr->first = lptr->next))
                                jptr->last = (struct xs_clause *) 0;
                        else    lptr->next = (struct xs_clause *) 0;
                        lptr->previous = (struct xs_clause *) 0;
                        lptr = inxsql_liberate_clause( lptr );
                }
                /* -------------------------- */
                /* disconnect from the parent */
                /* -------------------------- */
                if ( jptr->base )
                {
                        if (!( jptr->previous ))
                                jptr->base->firstjoint = jptr->next;
                        else    jptr->previous->next = jptr->next;
                        if (!( jptr->next ))
                                jptr->base->lastjoint = jptr->previous;
                        else    jptr->next->previous = jptr->previous;
                        jptr->base = (struct xs_base *) 0;
                        jptr->previous = jptr->next = (struct xs_joint *) 0;
                }
                /* ---------------------------------- */
                /* reset various joint control fields */
                /* ---------------------------------- */
                jptr->previous = jptr->next = (struct xs_joint *) 0;
                if ( jptr->name )
                        jptr->name = liberate( jptr->name );

                jptr = liberate( jptr );
        }
        return((struct xs_joint *) 0);
}


/*      --------------------    */
/*      inxsql_joint_clauses    */
/*      ------------------- -   */
private int inxsql_joint_clauses(struct xs_joint * jptr)
{
        struct  xs_clause * lptr;
        struct  xs_field * cptr;
        int     clauses=0;

        if (!( jptr )) return(0);

        for (   lptr=jptr->first;
                lptr != (struct xs_clause *) 0;
                lptr = lptr->next)
        {
                if (!(cptr = lptr->left ))
                        continue;
                else if (!( cptr->name ))
                        continue;
                else if (!(cptr = lptr->right ))
                        continue;
                else if (!( cptr->name ))
                        continue;
                else    clauses++;
        }
        return( clauses );
}

/*      ---------------------   */
/*      inxsql_allocate_joint   */
/*      ---------------------   */
public  struct xs_joint * inxsql_allocate_joint(struct xs_base * bptr, char * nptr)
{
        struct  xs_joint * jptr;
        if (!( jptr = allocate( sizeof( struct xs_joint ) ) ))
                return(jptr);
        else
        {
                /* ------------------------------------- */
                /* reset the clause and field management */
                /* ------------------------------------- */
                jptr->first = (struct xs_clause*) 0;
                jptr->last = (struct xs_clause*) 0;
                jptr->state = 0;
		jptr->type = _INXS_INNER_JOIN;

		/* --------------------- */
		/* allocate the name now */
		/* --------------------- */
		if (!( jptr->name = inxsql_allocate_string( nptr )))
			return( inxsql_liberate_joint( jptr ) );
	
                /* ---------------------------------- */
                /* if a parent file has been provided */
                /* ---------------------------------- */
                else if (( jptr->base = bptr) != (struct xs_base *) 0)
                {
                        /* ----------------------------- */
                        /* chain it to the parent's list */
                        /* ----------------------------- */
                        if (!( jptr->previous = bptr->lastjoint ))
                                bptr->firstjoint = jptr;
                        else	jptr->previous->next = jptr;
                        bptr->lastjoint = jptr;

                        /* --------------------- */
                        /* create the joint name */
                        /* --------------------- */
                        return ( jptr );
                }
                else
                {
                        /* ---------------------------- */
                        /* otherwise free radical joint */
                        /* ---------------------------- */
                        jptr->previous = (struct xs_joint *) 0;
                        jptr->next = (struct xs_joint *) 0;
                        return(jptr);
                }
	}
}

/*      -------------------       */
/*      inxsql_locate_joint       */
/*      -------------------       */
public struct xs_joint * inxsql_locate_joint(struct xs_base * fptr, char * nptr)
{
        struct  xs_joint * jptr;
        for (   jptr = fptr->firstjoint;
                jptr != (struct xs_joint *) 0;
                jptr = jptr->next )
        {
                if (!( jptr->name ))
                        continue;
                else if (!( inxsql_joint_name_compare( jptr->name, nptr ) ))
                        break;
        }
        return( jptr );
}

/*	-------------------	*/
/*	inxsql_declare_join	*/
/*	-------------------	*/
public  int inxsql_declare_join(struct xs_base * bptr, char * dptr, int dlen)
{
	int	device=0;
	int	resource=0;
	char	name[256];
	char	left[256];
	char	right[256];
	int	operator=0;
	int	clauses=0;
	int	i=0;
	struct	xs_joint * jptr;
	struct	xs_field * lptr;
	struct	xs_field * rptr;
	struct	xs_clause * cptr;

	if (!( bptr ))
		return( _ERROR_CONNECTION );
	else if (!( dptr ))
		return( _ERROR_SYNTAX );
	else if ( dlen < 51 )
		inxsql_buffer_too_small(bptr);
	else
	{

		/* ------------------------------ */
		/* collect the device information */
		/* ------------------------------ */
		device = *(dptr++);
		resource = *(dptr++);

		/* ------------------------- */
		/* collect the jointure name */
		/* ------------------------- */
		for ( i=0; i < _ABAL_JOIN_NAME_SIZE; i++ )
			if (( name[i] = *(dptr++)) == ' ')
				name[i] = 0;

		/* ------------------ */
		/* ensure unique name */
		/* ------------------ */
		if (( jptr = inxsql_locate_joint(bptr, name)) != (struct xs_joint *) 0)
			return( _ERROR_FILE_EXISTS );

		/* -------------------------------------- */
		/* allocate the join management structure */
		/* -------------------------------------- */
		if (!( jptr = inxsql_allocate_joint(bptr, name) ))
			return( _ERROR_MEMORY );
		else	dlen -= (_ABAL_JOIN_NAME_SIZE+2);

		/* ----------------------- */
		/* for each of the clauses */
		/* ----------------------- */
		for (	clauses = *(dptr++), dlen--; clauses != 0; clauses-- )
		{
                        /* -------------------------- */
                        /* step over long name prefix */
                        /* -------------------------- */
                        if (!( *dptr )) { dptr++; dlen--; }

			/* ---------------------------------------- */
			/* ensure sufficient data remains in buffer */
			/* ---------------------------------------- */
			if ( dlen < ((bptr->maxkey*2) + 1))
				inxsql_buffer_too_small(bptr);

			/* ---------------------- */
			/* collect left hand term */
			/* ---------------------- */
			if (!( inxsql_descriptor_field_name( left, 256, dptr, bptr->maxkey) ))
			{
				jptr = inxsql_liberate_joint( jptr );
				return( _ERROR_SYNTAX );
			}
			/* ------------------------------- */
			/* locate the database file column */
			/* ------------------------------- */
			else if (!(lptr = inxsql_locate_base_field(bptr, left) )) 
			{
				jptr = inxsql_liberate_joint( jptr );
				return( _ERROR_KEY_NOT_FOUND );
			}
			else { 	dptr += bptr->maxkey; dlen -= bptr->maxkey;  }

			/* ---------------- */
			/* collect operator */
			/* ---------------- */
			operator = *(dptr++); dlen--;

			/* ------------------- */
			/* step over null byte */
			/* ------------------- */
                	if ( bptr->maxkey > _ABAL_KEY_MAX_STD )
			{
				dptr++;
				dlen--;
			}

			/* ----------------------- */
			/* collect right hand term */
			/* ----------------------- */
			if (!( inxsql_descriptor_field_name( right, 256, dptr, bptr->maxkey) ))
			{
				jptr = inxsql_liberate_joint( jptr );
				return( _ERROR_SYNTAX );
			}
			/* ------------------------------- */
			/* locate the database file column */
			/* ------------------------------- */
			else if (!(rptr = inxsql_locate_base_field(bptr, right ) )) 
			{
				jptr = inxsql_liberate_joint( jptr );
				return( _ERROR_KEY_NOT_FOUND );
			}
			else { 	dptr += bptr->maxkey; dlen -= bptr->maxkey;  }

			/* ----------------------------------------- */
			/* ensure that the two columns are identical */
			/* ----------------------------------------- */
			if ( inxsql_compare_columns( lptr, rptr ) != _SUCCESS )
			{
				jptr = inxsql_liberate_joint( jptr );
				return( _ERROR_KEY_INCORECT );
			}

			/* ----------------------------------------- */
			/* add the new clause to the join expression */
			/* ----------------------------------------- */
			if (!( cptr = inxsql_allocate_clause( jptr, lptr, operator, rptr ) ))
			{
				jptr = inxsql_liberate_joint( jptr );
				return( _ERROR_MEMORY );
			}
		}
	}
#ifdef	DEBUG_INXS_JOIN
	inxsql_show_joint( jptr );
#endif
	return( _SUCCESS );
}

/*	------------------	*/
/*	inxsql_create_join	*/
/*	------------------	*/
public  int inxsql_create_join(struct xs_base * bptr, char * dptr, int dlen,int type)
{
	return( _SUCCESS );
}

/*	------------------	*/
/*	inxsql_delete_join	*/
/*	------------------	*/
public  int inxsql_delete_join(struct xs_base * bptr, char * name)
{
	struct	xs_joint * jptr;
	if (!( jptr = inxsql_locate_joint(bptr, name)))
		return( _ERROR_FILE_NOT_FOUND );
	else
	{
		jptr = inxsql_liberate_joint(jptr);
		return( _SUCCESS );
	}
}

/*	------------------	*/
/*	inxsql_rename_join	*/
/*	------------------	*/
public  int inxsql_rename_join(struct xs_base * bptr, char * dptr, int dlen)
{
	char	name[256];
	int	i;
	int	device=0;
	int	resource=0;
	char *	vptr;
	struct	xs_joint * iptr;
	struct	xs_joint * jptr;

	if (!( bptr ))
		return( _ERROR_CONNECTION );
	else if (!( dptr ))
		return( _ERROR_SYNTAX );
	else if ( dlen < 32 )
		inxsql_buffer_too_small(bptr);
	else
	{
		/* ------------------------- */
		/* collect the jointure name */
		/* ------------------------- */
		for ( i=0; i < _ABAL_JOIN_NAME_SIZE; i++ )
			if (( name[i] = *(dptr++)) == ' ')
				name[i] = 0;
	
		/* --------------------------- */	
		/* resolve the joint structure */
		/* --------------------------- */	
		if (!( jptr = inxsql_locate_joint(bptr, name) ))
			return( _ERROR_FILE_NOT_FOUND );

		/* ------------------------------ */
		/* collect the device information */
		/* ------------------------------ */
		device = *(dptr++);
		resource = *(dptr++);

		/* ------------------------- */
		/* collect the jointure name */
		/* ------------------------- */
		for ( i=0; i < _ABAL_JOIN_NAME_SIZE; i++ )
			if (( name[i] = *(dptr++)) == ' ')
				name[i] = 0;

		/* --------------------------- */	
		/* resolve the joint structure */
		/* --------------------------- */	
		if (( iptr = inxsql_locate_joint(bptr, name)) != (struct xs_joint *) 0)
			return( _ERROR_FILE_EXISTS );

		/* --------------------- */
		/* allocate the new name */
		/* --------------------- */
		else if (!( vptr = inxsql_allocate_string( name ) ))
			return( _ERROR_MEMORY );
		else
		{
			/* ----------------------- */
			/* release old and set new */
			/* ----------------------- */
			if ( jptr->name )
				jptr->name = liberate( jptr->name );

			jptr->name = vptr;

			return( _SUCCESS );
		}
	}
}

/*      -------------------     */
/*       inxsql_list_joins      */
/*      -------------------     */
public  int inxsql_list_joins(struct xs_base * bptr, char * dptr, int dlen, int mode )
{
        char *  vptr;
        char *  sptr;
        int     vlen;
        struct  xs_joint * jptr;
        struct  xs_clause * lptr;
        struct  xs_field * cptr;

        /* ---------------------------- */
        /* determine first or next mode */
        /* ---------------------------- */
        switch ( mode )
        {
        case    0       : /* FIRST      */
                if (!( bptr->currentjoint = bptr->firstjoint ))
                        return(_ERROR_END_OF_FILE);
                else    break;
        case    1       : /* NEXT       */
                if (!( bptr->currentjoint ))
                        return(_ERROR_END_OF_FILE);
                else if (!( bptr->currentjoint = bptr->currentjoint->next ))
                        return(_ERROR_END_OF_FILE);
                else    break;
        }

        /* --------------------------------- */
        /* generate the resulting databuffer */
        /* --------------------------------- */
        if (!( jptr = bptr->currentjoint))
                return( _ERROR_END_OF_FILE );
        else if (!( vptr = jptr->name ))
                return( _ERROR_END_OF_FILE );
        else if ( dlen < 2 )
		inxsql_buffer_too_small(bptr);
        else    memset(dptr,' ',dlen);

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
        if ( dlen >= 19 )
        {
                for ( vlen = 0; vlen < _ABAL_JOIN_NAME_SIZE; vlen++ )
                        if ( *vptr != 0 )
                                dptr[vlen+3] = *(vptr++);

                /* -------------------------- */
                /* set the joint clause count */
                /* -------------------------- */
                dptr[18] = ( inxsql_joint_clauses( jptr ) & 0x00FF);

                dptr += 19; dlen -= 19;
        }

        /* ------------------ */
        /* copy the key names */
        /* ------------------ */
        for (   lptr = jptr->first;
                lptr != (struct xs_clause *) 0;
                lptr = lptr->next )
        {
                if ( dlen < 33 )
			inxsql_buffer_too_small(bptr);
                else if (!( cptr = lptr->left ))
                        continue;
                else if (!( sptr = cptr->name ))
                        continue;

                for ( vlen = 0; vlen < bptr->maxkey; vlen++ )
                        if (*sptr != 0)
                                dptr[vlen] = *(sptr++);

                dptr += bptr->maxkey; dlen -= bptr->maxkey;
                *(dptr++) = lptr->operator;
                dlen--;

                if (!( cptr = lptr->right ))
                        continue;
                else if (!( sptr = cptr->name ))
                        continue;

                for ( vlen = 0; vlen < bptr->maxkey; vlen++ )
                        if (*sptr != 0)
                                dptr[vlen] = *(sptr++);

                dptr += bptr->maxkey; dlen -= bptr->maxkey;
        }

        return( _SUCCESS );
}

/*	--------------------------------	*/
/*		inxsql_join_clause		*/
/*	---------------------------------	*/
/*	called for database query prepare	*/
/*	---------------------------------	*/ 
public	int	inxsql_join_clause( struct xs_base * bptr, char * query, char * dptr, int dlen )
{
	struct	xs_joint * jptr;
	struct	xs_clause* tptr;
	struct	xs_field * cptr;
	struct	xs_file  * fptr;
	int		   first=1;
	char 		 * logical=(char *) 0;
	char		 * final="";
	int		   i=0;
	char		   name[256];

	/* ---------------------------- */
	/* check descriptor for a joint */
	/* ---------------------------- */
	if (( dptr != (char *) 0) && ( dlen > _ABAL_JOIN_NAME_SIZE ))
	{
		/* ------------------------- */
		/* collect the jointure name */
		/* ------------------------- */
		dptr += (dlen - _ABAL_JOIN_NAME_SIZE);
		for ( i=0; i < _ABAL_JOIN_NAME_SIZE; i++ )
			if (( name[i] = *(dptr++)) == ' ')
				name[i] = 0;

		/* ---------------------------------------- */
		/* check that a JOIN name has been provided */
		/* ---------------------------------------- */
		if (!( strlen( name ) ))
			return( _ERROR_MISSING_JOIN );

		/* ------------------------------------ */
		/* attempt to locate the specified JOIN */
		/* ------------------------------------ */
		else if (!( bptr->join = inxsql_locate_joint( bptr, name )))
			return( _ERROR_JOIN_NOT_FOUND );

	}
	/* --------------------------------------- */
	/* a valid JOIN descriptor must be present */
	/* --------------------------------------- */
	else	inxsql_buffer_too_small(bptr);

	/* ------------------------------- */
	/* a joint must have been selected */
	/* ------------------------------- */
	if (!( jptr = bptr->join ))
		return( _ERROR_SYNTAX );
	else
	{
#ifdef	DEBUG_INXS_JOIN
		inxsql_show_joint( jptr );
#endif
		/* --------------------------- */
		/* increase JOIN request count */
		/* --------------------------- */
		bptr->requests++;

		/* --------------------------------------- */
		/* generate the INNER JOIN table name list */
		/* --------------------------------------- */
		for (	logical = (char *) 0,
			tptr = jptr->first;
			tptr != (struct xs_clause *) 0;
			tptr = tptr->next )
		{
			/* ---------------- */	
			/* handle left term */
			/* ---------------- */	
			if (!( cptr = tptr->left ))
				return( _ERROR_SYNTAX );
			else if (!( fptr = cptr->file ))
				return( _ERROR_SYNTAX );

			/* --------------------------- */
			/* check if file has been used */
			/* --------------------------- */
			else if ( fptr->usage != bptr->requests )
			{	
				/* ----------------------- */
				/* handle logical operator */
				/* ----------------------- */
				if ( logical ) strcat(query,logical);

				/* --------------- */
				/* this TABLE name */
				/* --------------- */
				strcat(query, fptr->name);

				if (!( logical )) 
				{
					/* -------------------------------- */
					/* handle the JOIN declaration TYPE */
					/* -------------------------------- */
					switch ( jptr->type )
					{
					case	_INXS_INNER_JOIN : strcat(query," INNER"); break;
					case	_INXS_OUTER_JOIN : strcat(query," OUTER"); break;
					case	_INXS_LEFT_JOIN  : strcat(query," LEFT"); break;
					case	_INXS_RIGHT_JOIN : strcat(query," RIGHT"); break;	
					}

					strcat(query," JOIN "); 
					logical = "(";
				}

				fptr->usage = bptr->requests;
			}

			/* ----------------- */	
			/* handle right term */
			/* ----------------- */	
			if (!( cptr = tptr->right))
				return( _ERROR_SYNTAX );
			else if (!( fptr = cptr->file ))
				return( _ERROR_SYNTAX );

			/* --------------------------- */
			/* check if file has been used */
			/* --------------------------- */
			else if ( fptr->usage != bptr->requests )
			{
				/* --------------- */
				/* this TABLE name */
				/* --------------- */
				strcat(query,logical);
				strcat(query, fptr->name);
				fptr->usage = bptr->requests;
				logical = ",";
				final = ")";
			}
		}

		/* ---------------------------------- */
		/* generate the JOIN column relations */
		/* ---------------------------------- */
		strcat(query,final);
		strcat(query," ON "); 
		logical = "(";

		for (	tptr = jptr->first;
			tptr != (struct xs_clause *) 0;
			tptr = tptr->next )
		{
			/* ----------------------- */
			/* handle logical operator */
			/* ----------------------- */
			strcat(query,logical); logical = " AND ";

			/* ---------------- */	
			/* handle left term */
			/* ---------------- */	
			if (!( cptr = tptr->left ))
				return( _ERROR_SYNTAX );
			else if (!( fptr = cptr->file ))
				return( _ERROR_SYNTAX );
			else
			{
				strcat(query,fptr->name);
				strcat(query,".");
				strcat(query,cptr->name);
			}

			/* ------------------------ */
			/* handle the JOIN operator */
			/* ------------------------ */
			switch ( tptr->operator )
			{
			case	_INXS_JOIN_EQ	: strcat( query, " = "); break;
			case	_INXS_JOIN_NE	: strcat( query, " <> "); break;
			case	_INXS_JOIN_GT	: strcat( query, " > "); break;
			case	_INXS_JOIN_GE	: strcat( query, " >= "); break;
			case	_INXS_JOIN_LT	: strcat( query, " < "); break;
			case	_INXS_JOIN_LE	: strcat( query, " <= "); break;
			case	_INXS_JOIN_BTF	: strcat( query, " Between "); break;
			case	_INXS_JOIN_BTL	: strcat( query, " And "); break;
			default			: return( _ERROR_SYNTAX );
			}

			/* ----------------- */	
			/* handle right term */
			/* ----------------- */	
			if (!( cptr = tptr->right))
				return( _ERROR_SYNTAX );
			else if (!( fptr = cptr->file ))
				return( _ERROR_SYNTAX );
			else
			{
				strcat(query,fptr->name);
				strcat(query,".");
				strcat(query,cptr->name);
			}
		}

		/* --------------------------------- */
		/* terminate JOIN and signal SUCCESS */
		/* --------------------------------- */
		strcat(query,") "); return( _SUCCESS );
	}
	
}

#endif /* _inxsql_join_c */

