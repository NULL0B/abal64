#ifndef	_singmod_h
#define	_singmod_h

#define	_FONT_MODEL	1
#define	_IMAGE_MODEL	2
#define	_FORM_MODEL	3
#define	_FILE_MODEL	4
#define	_CLASS_MODEL	5
#define	_APPLI_MODEL	6

struct	model_node	{
	int		nature;
	void *		contents;
	char *		name;
	struct model_node * previous;	
	struct model_node * next;
	int	(*onload)(struct model_node *,int);
	int	(*onshow)(struct model_node *,int);
	int	(*onedit)(struct model_node *,int);
	int	(*onprod)(struct model_node *,int);
	int	(*onsave)(struct model_node *,int);
	int	(*ondrop)(struct model_node *,int);
	};

#endif	/* _singmod_h */


