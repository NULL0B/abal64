#ifndef	_exsing_h
#define	_exsing_h

#define	__ONCREATE	0
#define	__ONREMOVE	1
#define	__ONHIDE	2
#define	__ONSHOW	3
#define	__ONEVENT	4
#define	__ONFOCUS	5
#define	__ONLOSEFOCUS 	6

struct	sing_context	{
	unsigned int 	oncreate;
	unsigned int 	onshow;
	unsigned int 	onfocus;
	unsigned int 	onevent;
	unsigned int 	onlose;
	unsigned int 	onhide;
	unsigned int 	onremove;
	};

#endif	/* _exsing_h */
	/* --------- */



