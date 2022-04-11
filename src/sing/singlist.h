#ifndef	_singlist_h
#define	_singlist_h

struct	standard_filenode	{
	struct	standard_filenode * previous;
	struct	standard_filenode * next;
	char *	filename;
	};

struct	standard_filelist	{
	struct	standard_filenode * first;
	struct	standard_filenode * last;
	};



#endif	/* _singlist_h */
	/* ----------- */


