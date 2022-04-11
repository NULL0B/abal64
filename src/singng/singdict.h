#ifndef	_singdict_h
#define	_singdict_h

#define	DICTIONARYHASH	57
#define	TERMHASH	133

struct	dictionary_term	{
	int	hashcode[MAXNATLANG];
	char *	normalised[MAXNATLANG];
	char *	messages[MAXNATLANG];
	struct	dictionary_term * previous;
	struct	dictionary_term * next;
	};


struct	dictionary_term * dictionary[DICTIONARYHASH];




#endif	/* _singdict_h */


