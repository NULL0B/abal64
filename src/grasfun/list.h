#ifndef	_asfun_list_h
#define	_asfun_list_h

#define	LIST_AHDH	0x0011
#define	LIST_AHDV	0x0012
#define	LIST_AVDH	0x0021
#define	LIST_AVDV	0x0022

#define	_NOCLEAR	1
#define	_VSCROLLBAR	2
#define	_HSCROLLBAR	4
#define	_RETURNTAB	8
#define	_NODIALOGBOX	16
#define	_RETURNESC	32
#define	_RETURNBEFORE	64


struct	asfun_item	{
	int	c;			/* current display column id	*/
	int	l;			/* current display row id	*/
	int	ataff;			/* display type normal/grey	*/
	int	etat;			/* selected or not		*/
	int	atlen;			/* display length		*/
	int	comlen;			/* comment length		*/
	char	value[_MAX_VALUE];	/* option value			*/
	char	comment[_MAX_COMMENT];	/* comment value		*/
	};

struct	asfun_list	{
	int	control;		/* enhanced list options 	*/
	int	colinc;			/* column increment value	*/
	int	rowinc;			/* line or row increment value	*/
	int	indent;			/* first cell visible topleft	*/
	int	active;			/* current focus item		*/
	int	window;			/* lowlevel window handle	*/
	int	number;			/* list number for list		*/
	int	multiple;		/* is multiple 			*/
	int	mode;			/* combined mode values		*/
	int	amode;			/* display mode H or V		*/
	int	dmode;			/* scroll mode H or V		*/
	int	align;			/* list alignment L or C	*/
	int	columns;		/* total columns		*/
	int	lines;			/* total rows ( visible )	*/
	int	maxel;			/* total number of items	*/
	int	lenel;			/* item unit length		*/
	int	disel;			/* item display length		*/
	int	comel;			/* comment storage length	*/
	int	isopen;			/* list is open : not closed	*/
	int	options;		/* number of items/options	*/
	struct  asfun_item * option[_MAX_ITEMS];
	};

public	void	show_list( struct asfun_list * lptr );

#endif	/* _asfun_list_h */
	/* ------------- */


