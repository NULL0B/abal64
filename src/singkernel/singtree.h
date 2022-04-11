#ifndef	_singtree_h
#define	_singtree_h

/*	Tree view state flags 	*/
/*	---------------------	*/

#define	_TREE_OPEN	1
#define	_TREE_FOCUS	2
#define	_TREE_CLOSED	4
#define	_TREE_REFRESH	8
#define	_TREE_BUILD	16
#define	_TREE_LOCK	32
#define	_TREE_BOLD	64


/*	Tree view constants	*/
/*	-------------------	*/

#define	_TREE_INDENT	16

struct	treeview	{
	struct	treeview 	* parent;
	struct	treeview 	* previous;
	struct	treeview 	* next;
	struct	treeview 	* first;
	struct	treeview 	* current;
	struct	treeview 	* last;
	int			state;
	int			nature;
	int			identity;
	int			atcol;
	int			atrow;
	void			* payload;

	};

struct	tree_manager {
	int	width;
	int	height;
	int	fontheight;
	int	fontwidth;
	char	* member;
	char	* opened;
	char	* closed;
	char	* downer;
	char	* prefix;
	char	* pattern;
	};

struct	tree_configuration {
	int	font;
	int	zonage;
	int	spacing;
	int	source;
	int	target;
	int	packaging;
	int	identity;
	int	width;
	};


#define	TREE_NULL	 0
#define	TREE_ROOT	 666
#define	TREE_EVENT	 1
#define	TREE_WIDGET	 2
#define	TREE_CLASS	 3
#define	TREE_FORM	 4
#define	TREE_FILE 	 5
#define	TREE_MENU	 6
#define	TREE_TEXT	 7
#define	TREE_PROJECT	10
#define	TREE_IMAGE	20
#define	TREE_FONT	21

public	struct treeview * allocate_for_treeview();
public	struct treeview * liberate_for_treeview(struct treeview * tptr);
public	void	reactivate_TreeView(int state);
public	struct treeview * locate_TreeViewWidget(int x, int y, struct treeview * lptr );

#endif  /* _singtree_h */



