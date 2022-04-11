#ifndef	_forms_data_member
#define	_forms_data_member

#define	_FORMS_STDINPUT 	1
#define	_FORMS_STDERROR 	2
#define	_FORMS_ONESCAPE 	3
#define	_FORMS_ONENTER 		4
#define	_FORMS_ONDEFAULT 	5
#define	_FORMS_ONPREVIEW 	6
#define	_FORMS_ONHINT 		7
#define	_FORMS_ONPAGE 		8
#define	_FORMS_POSITIONAT	9
#define	_FORMS_ONPRECONSTR	10
#define	_FORMS_ONPOSTDESTR	11

#define	_METHOD_STDINPUT 	 "stdinput" 
#define	_METHOD_STDERROR 	 "stderror" 
#define	_METHOD_ONESCAPE 	 "onescape" 
#define	_METHOD_ONENTER 	 "onenter" 
#define	_METHOD_ONDEFAULT 	 "ondefault" 
#define	_METHOD_ONPREVIEW 	 "onpreview" 		
#define	_METHOD_ONPRECONSTR 	 "preconstruction" 		
#define	_METHOD_ONPOSTDESTR 	 "postdestruction" 		
#define	_METHOD_ONHINT 		 "onhint" 		
#define	_METHOD_ONPAGE 		 "onpage" 		
#define	_METHOD_POSITIONAT	 "positionat" 		

struct	forms_data_member	{
	struct	forms_data_member *	previous;
	struct	forms_data_member *	next;
	struct	form_control	 *	parent;
	char			 *	name;
	int				number;
	int				number_sort;
	int				type;
	int				size;
	int				first;
	int				second;
	char			 * 	comment;
	char			 *	klass;
	char			 *	construction;
	};


#endif	


