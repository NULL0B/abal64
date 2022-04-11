#ifndef	_specialsql_c
#define	_specialsql_c

/*	---------------------------------------------------------------------------------	*/
/*	this file provides functions to handle filtering of special SQL reserved keywords 	*/
/*	---------------------------------------------------------------------------------	*/

static  char    SpecialNameBuffer[2048];
static	char * 	SpecialPrefix="_";

/*	-----------------------------------	*/
/*	s e t _ s p e c i a l _ p r e f i x	*/
/*	-----------------------------------	*/
static	void	set_special_prefix( char * sptr )
{
	SpecialPrefix = sptr;
	return;
}

/*	-----------------------------------	*/
/*	  s p e c i a l _ s q l _ n a m e	*/
/*	-----------------------------------	*/
static  char *  special_sql_name( char * nptr )
{
        sprintf(SpecialNameBuffer,"%s%s",SpecialPrefix,nptr);
        return( SpecialNameBuffer );
}

/*	---------------------------	*/
/*	c h e c k _ s q l _ n a m e 	*/
/*	---------------------------	*/
static  char *  check_sql_name( char * nptr )
{
        if (!( strcasecmp( nptr, "DATE" ) ))
                return( special_sql_name( nptr ) );
        else if (!( strcasecmp( nptr, "TIME" ) ))
                return( special_sql_name( nptr ) );
        else if (!( strcasecmp( nptr, "GROUP" ) ))
                return( special_sql_name( nptr ) );
        else    return( nptr );
}

#endif	/* _specialsql_c */
	/* ------------- */

