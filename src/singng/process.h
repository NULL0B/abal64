#ifndef	_PROCESS_H
#define	_PROCESS_H

#define	_ACCESS_MODE	0
#define	_ACCESS_NUMB	16

struct	standard_process {
	int	id;
	int	mode;
	int	serial;
	int  *	identity;
	char *	access;
	char *	gsd;
	struct 	standard_image * image;	
	};

#endif	/* _PROCESS_H */



