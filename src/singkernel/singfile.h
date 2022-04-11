#ifndef	_singfile_h
#define	_singfile_h


#include "abaldata.h"
#include "valign.h"

struct	file_control	{
	struct	file_control 	* previous;
	struct	file_control 	* next;
	char			* identity;
	char			* filename;
	char			* format;
	char			* classname;
	char			* indextype;
	char			* recordtype;
	struct	data_control	* payload;
	int			  nature;
	int			  number;
	int			  members;
	};

struct	file_manager	{
	struct	file_control	*	first;
	struct	file_control	*	current;
	struct	file_control	*	last;
	};

#ifdef	_vfile_c
struct	file_manager FileManager = {
		 	(struct file_control *) 0,
		 	(struct file_control *) 0,
		 	(struct file_control *) 0
			};

#else
extern	struct	file_manager FileManager;
#endif


#endif	/* _singfile_h */


