#ifndef	_sing_type_h
#define	_sing_type_h

char *	get_string( FILE * );
char *	get_string_length( FILE *, int );
char *	get_filename( FILE * );
long	get_long( FILE * );

#define	GetWord(a,b)   b = get_word(a)
#define	GetLong(a,b)   b = get_long(a)
#define	GetFile(a,b)   b = get_filename(a)
#define	GetString(a,b) b = get_string(a)

#endif	/* _sing_type_h	*/


