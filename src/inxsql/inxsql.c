#ifndef	_inxsql_c
#define	_inxsql_c

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

#include	"inxsql.h"

private	int	verbose=0;
private	int	view=0;
private	char	_table_name[1024];
private	char	_field_name[1024];

/*	-----------	*/
/*	set_verbose	*/
/*	-----------	*/
public	void	set_verbose(int v)	{	verbose = v;	}

/*	----------------------		*/
/*	inxsql_allocate_string		*/
/*	----------------------		*/
public	char* 	inxsql_allocate_string( char * sptr )
{
	char * rptr ;
	if (!( sptr ))
		return( sptr );
	else if (!( rptr = allocate( strlen( sptr ) + 1 ) ))
		return( rptr );
	else	return( strcpy(rptr, sptr) );
}

/*	--------------	*/
/*	inxsql_boolean	*/
/*	--------------	*/
public	int	inxsql_boolean( char * nptr, int none )
{
	char * eptr;
	if (!( eptr = getenv( nptr ) ))
		return( none );
	else if (!( strcasecmp( eptr, "TRUE" ) ))
		return(1);
	else if (!( strcasecmp( eptr, "FALSE" ) ))
		return(0);
	else if (!( strcasecmp( eptr, "ON" ) ))
		return(1);
	else if (!( strcasecmp( eptr, "OFF" ) ))
		return(0);
	else if (!( strcasecmp( eptr, "YES" ) ))
		return(1);
	else if (!( strcasecmp( eptr, "NO" ) ))
		return(0);
	else if (!( strcasecmp( eptr, "STDOUT" ) ))
		return(1);
	else if (!( strcasecmp( eptr, "STDERR" ) ))
		return(2);
	else if (!( strcasecmp( eptr, "NULL" ) ))
		return(0);
	else if (!( strcasecmp( eptr, "NONE" ) ))
		return(0);
	else	return( atoi( eptr ) );
}

/*	-----------------	*/
/*	inxsql_view_count	*/
/*	-----------------	*/
public	int	inxsql_view_count()
{
	return( ++view );
}

#include "inxsql_file.c"
#include "inxsql_lock.c"
#include "inxsql_query.c"
#include "inxsql_field.c"
#include "inxsql_record.c"
#include "inxsql_index.c"
#include "inxsql_view.c"
#include "inxsql_table.c"
#include "inxsql_join.c"
#include "inxsql_base.c"

#endif	/* _inxsql_c */

