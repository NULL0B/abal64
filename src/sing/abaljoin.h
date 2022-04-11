#ifndef	_abaljoin_h
#define	_abaljoin_h

struct	join_link {
	struct	join_link *	previous;
	struct	join_link *	next;
	char		  *	name;
	};


struct	join_control {
	char *	name;
	char *	value;
	struct 	join_control * previous;
	struct	join_control * next;
	struct	join_link    * first;
	struct  join_link    * last;
	};

struct	join_list	{
	struct 	join_control * first;
	struct	join_control * last;
	};

#endif	/* _abaljoin_h */
	/* ----------- */










