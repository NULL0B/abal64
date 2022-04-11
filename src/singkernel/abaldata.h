#ifndef	_abaldata_h
#define	_abaldata_h

#include "abaltype.h"

#define	MAX_DATA_FIELDS	256

struct	include_control	{
	char *	name;
	struct include_control * previous;
	struct include_control * next;
	};

struct	data_control	{
	struct	standard_image * image;
	int	indexlength;
	int	datalength;
	int	option;
	int	indexfields;
	int	datafields;
	int	fields;
	int	lock;
	int	first [MAX_DATA_FIELDS];
	int	second[MAX_DATA_FIELDS];
	int	width [MAX_DATA_FIELDS];
	char	type  [MAX_DATA_FIELDS];
	char *	name  [MAX_DATA_FIELDS];
	struct include_control * firstfile;
	struct include_control * lastfile;
	char *	indexname;
	char *	recordname;
	};

struct	database_editor_context;

public	struct	data_control * drop_data_control( struct data_control * dptr );
public	struct	data_control * analyse_data_control( char * fptr );
public	struct	data_control * resolve_class_data(struct database_editor_context * vptr, char * cptr );


#endif	/* _abaldata_h */
	/* ----------- */





















