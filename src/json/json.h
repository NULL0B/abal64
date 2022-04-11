#ifndef	_json_h
#define	_json_h

//      ------------------------------------------
//      Electronic Document Exchange : JSON
//      ------------------------------------------
//
//      Copyright (c) 2021 Amenesik SARL
//
//      Iain James MArshall <ijm@amenesik.com>
//
//      ------------------------------------------

#include "standard.h"
#include "allocate.h"
#include "dataelement.h"

struct	json_parser
{
	FILE *	handle;
	int	ungotc;
	int	line;
	int	column;
};

public	int			json_set_echo( int v );
public	int			json_show( struct data_element * dptr );
public	int			json_serialise( struct data_element * dptr, char * filename );
public	struct data_element *	json_parse_file( char * filename );
public	struct data_element *	json_parse_string( char * sptr );
public	struct data_element * 	drop_data_element( struct data_element * dptr );
public	char *			json_atribut( struct data_element * dptr, char * nptr );
public	struct data_element * 	json_element( struct data_element * dptr, char * nptr );

	/* ------- */
#endif	/* _json_h */
	/* ------- */

