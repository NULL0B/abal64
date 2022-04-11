#ifndef	_parseform_h
#define	_parseform_h

#define	_PARSE_BUCKET_SIZE	8192

struct	form_parser_application	{
	int	convert;
	int	bytecount;
	char	bucket[_PARSE_BUCKET_SIZE+1];
	struct	form_control * form;
	struct	forms_method * method;
	};

#endif	/* _parseform_h */
	/* ------------ */













