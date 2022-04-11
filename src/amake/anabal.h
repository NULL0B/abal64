#ifndef	_anabal_h
#define	_anabal_h

#define	allocate(a)	malloc(a)
#define	liberate(a)	free(a)

#define	private		static
#define	public		

#define	_file_item 	1
#define	_code_item 	2
#define	_call_item 	3
#define	_include_item 	4

#define	_code_procedure	1
#define	_code_segment	2
#define	_code_function	3

struct	item_node {
	struct item_node 	* previous;
	struct item_node 	* next;
	char			* name;
	int			  type;
	void			* contents;
	};

struct	item_list {
	struct item_node 	* first;
	struct item_node 	* last;
	struct item_node 	* current;
	};

struct	file_item {
	char		*name;
	int		 nature;
	char		*logical;
	int		 type;
	int		 lock;
	struct item_list items;
	};

struct	code_item {
	char		 *name;
	int		  state;	/* 0 : open, 1 : closed		  */
	int		  nature;	/* procedure / segment / function */
	int		  lock;		/* avoid recursive expansion	  */
	struct file_item *parent;
	struct item_list  items;
	};

struct	inclusion_item {
	char		*name;
	struct file_item *item;
	};

struct	call_item {
	char		*name;
	int		 nature;	/* procedure / segment / function */
	struct code_item *item;
	};

/*	----------	*/
/*	prototypes 	*/
/*	----------	*/

struct	item_node 	* allocate_item();
struct	file_item 	* allocate_file();
struct	code_item 	* allocate_code();
struct	call_item 	* allocate_call();
struct	inclusion_item 	* allocate_inclusion();

void	reset_list( struct item_list * lptr );
void	liberate_list(struct item_list * lptr);

struct	item_node 	* liberate_item(struct item_node * iptr);
struct	file_item 	* liberate_file(struct file_item * fptr);
struct	code_item 	* liberate_code(struct code_item * cptr);
struct	call_item 	* liberate_call(struct call_item * cptr);
struct	inclusion_item 	* liberate_inclusion(struct inclusion_item * iptr);

struct	code_item	* resolve_code(struct item_list * lptr, char * nptr, int type );
struct	file_item	* resolve_file(struct item_list * lptr, char * nptr );



#endif	/* _anabal_h */


