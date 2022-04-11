#ifndef	_singclas_h
#define	_singclas_h

#define	_MEMBER_CONSTANT	0
#define	_MEMBER_DATA    	1
#define	_MEMBER_METHOD  	2

#define	_MEMBER_PRIVATE	0
#define	_MEMBER_PUBLIC	1

#define	_TYPE_VOID	0	/* no type or any type */

#define	_TYPE_BYTE	0x0001
#define	_TYPE_WORD	0x0002
#define	_TYPE_LONG	0x0004

#define	_TYPE_INT	0x0007	/* any integral type 	*/

#define	_TYPE_FLOAT	0x0008
#define	_TYPE_BCD	0x0010
#define	_TYPE_STRING	0x0020
#define	_TYPE_CLASS	0x0040

#define	_BASIC_TYPE	0x00FF

#define	_TYPE_POINTER	0x0100
#define	_TYPE_VIRTUAL	0x0200
#define	_TYPE_OVERLOAD	0x0400
#define	_TYPE_COMMON 	0x0800

#define	_TYPE_METHOD 		0x1000
#define	_TYPE_CONSTRUCTOR	0x2000
#define	_TYPE_DESTRUCTOR	0x4000
#define	_TYPE_EXCEPTION 	0x8000

struct	standard_type {
	int		type;	/* void,byte,word,long,float,bcd,string */
	char	*	name;	/* class name supplement		*/
	};

struct	standard_member	{
	int	nature;			/* DATA, CONST, METHOD 	*/
	char *	name;
	int	protection;
	struct	standard_type type;
	struct	standard_class * parent;
	int	doctool;
	char *	document;
	};

struct	standard_node	{
	struct 	standard_node * previous;
	struct 	standard_node * next;
	struct	standard_member * contents;
	int	x;
	int	y;
	int	item;
	};

struct	standard_list	{
	struct standard_node * first;
	struct standard_node * last;
	struct standard_node * base;
	struct standard_node * current;
	};


struct	standard_class	{
	char	*	name;
	char	*	loadname;
	char	*	prodname;
	char	*	headname;
	char	*	dependance;
	int		nature;
	int		tool;
	int		items;
	int		language;
	long		savestamp;
	long		loadstamp;
	struct standard_image * image;
	struct standard_list * members;
	int	doctool;
	char *	document;
	struct	treeview * treenode;
	void             * host;
	};

struct	const_member	{
	int		nature;	/* 1 : CONSTANT */
	char 	*	name;	/* the name of the constant	   */
	int	protection;
	struct	standard_type type;
	struct	standard_class * parent;
	int	doctool;
	char *	document;
	int	paratool;
	char  	*	value;	/* corresponding value of constant */
	};

struct	data_member	{
	int		nature;	/* 2 : DATA */
	char 	*	name;	/* the name of the data item		 */
	int	protection;
	struct	standard_type type;
	struct	standard_class * parent;
	int	doctool;
	char *	document;
	int	paratool;
	int		size;
	int		first;
	int		second;
	char	*	construction;
	};


struct	method_member	{
	int		nature;	/* 3 : METHOD */
	char 	*	name;	/* the name of the method  	 */
	int	protection;
	struct	standard_type type; /* Method return type	 */
	struct	standard_class *  parent;
	int	doctool;
	char *	document;
	int			  paratool;
	int			  basetool;
	int			  methtool;
	int			  options;
	struct  standard_list 	* members;
	char			* parameters;
	char			* base;
	char			* instructions;
	};


struct	standard_class * allocate_Class( char *  nptr );
struct	standard_class * liberate_Class( struct standard_class *  cptr );
	int		 edit_Class( struct standard_class **  ccptr, int mode  );
struct	standard_class * load_Class( char *, int automatic );
int 			 save_Class( struct standard_class *  cptr,int automatic );


#endif	/* _singclas_h */

