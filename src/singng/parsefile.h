#ifndef	_parsefile_h
#define	_parsefile_h

struct	file_parser_application	{
	int	nature;
	char *	indexname;
	char *	markername;
	char *	recordname;
	struct	file_control * file;
	struct	data_control * data;
	};

#endif	/* _parsefile_h */
	/* ------------ */


