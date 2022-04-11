#ifndef	_avnfile_h
#define	_avnfile_h


#define	_AVNOR_MODIFIED	0
#define	_AVNOR_INSERTED	1
#define	_AVNOR_DELETED 	2

struct	avnor_file {
	char	*	name;
	int		size;
	char	*	buffer;
	int		start;
	int		offset;
	int		line;
	};

struct	avnor_diff	{
	struct	avnor_diff * 	previous;
	struct	avnor_diff * 	next;
	int		lline;
	int		rline;
	int		lines;
	int		type;		/* 1 inserted in left, 2 : deleted from left : 0 modified */
	};


/*	-------------------	*/
/*	function prototypes	*/
/*	-------------------	*/

int			difference( char * , char *, int );
void			show_differences();
void			release_differences();
struct	avnor_diff *	current_difference();
struct	avnor_diff * 	select_difference(int);


#endif	/* _evnfile_h */
	/* ---------- */


