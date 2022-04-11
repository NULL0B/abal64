#ifndef	_forms_data_member
#define	_forms_data_member

struct	forms_data_member	{
	struct	forms_data_member *	previous;
	struct	forms_data_member *	next;
	struct	form_control	 *	parent;
	char			 *	name;
	int				number;
	int				type;
	int				size;
	int				first;
	int				second;
	char			 *	klass;
	char			 *	construction;
	};


#endif	

