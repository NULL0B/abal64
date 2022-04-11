#ifndef	_singmenu_h
#define _singmenu_h

long	time(long *);

struct	menu_option;
struct	menu_control	{

	struct	menu_option *	first;
	struct	menu_option *	last;
	struct	menu_option *	current;

	long	savestamp;
	long	loadstamp;

	char	*	identifier;	/* production class name	*/

	int		isprogram;	/* production source type	*/
	int		isoverlay;	/* secondary production type	*/

	char	*	prodname;	/* name of production file	*/
	char	*	loadname;	/* name of source file		*/

	char	*	dependance;
	char	*	construction;

	int		doctool;	/* text tool type zero !	*/
	char	*	document;	/* string of document text	*/

	char	*	hint;		/* string of information	*/
	char	*	service;	/* name of service function	*/
	char	*	iname;		/* name of image background	*/
	void	*	image;		/* pixel images  background	*/
	void	*	shadow;		/* shadow storage for popup	*/

	int	language;	/* production language			*/

	int	font;		/* font identifier			*/
	int	style;		/* menu presentation style		*/

	int	maxwidth;

	int	x;		/* x position of display		*/
	int	y;		/* y position of display		*/
	int	w;		/* calculated width			*/
	int	h;		/* calculated height			*/
	int	nature;		/* horizontal/Vertical, popup/permenant */
	int	state;		/* active/inactive			*/
	int	members;	/* number of member items		*/
	int	storage;	/* storage for chosen member value	*/
	struct	treeview * treenode;
	void		 * host;

	};
	
struct	menu_option	{
	struct	menu_option * previous;
	struct	menu_option * next;
	struct	menu_control *parent;	
	int		doctool;	/* text tool type zero !	*/
	char	*	document;	/* string of document text	*/
	char	*	label;		/* menu option display string	*/
	char	*	hint;		/* string of advice		*/
	char	*	service;	/* name of linked function	*/
	char	*	linkage;	/* name of linked menu		*/
	int		hotkey;		/* hotkey trigger value		*/
	int		result;		/* result returned when chosen	*/
	int		state;		/* state : active/inactive/line	*/
	int		x;		/* position relative to menu	*/
	int		y;		/* x and y values		*/
	int		w;		/* position relative to menu	*/
	int		h;		/* x and y values		*/
	};

public	struct menu_control *	load_Menu(char * n, int m);
public	int 			save_Menu(struct menu_control * mptr,int m);

public	int			edit_Menu( struct menu_control ** mmptr, int mode  );
public	void			draw_Menu( struct menu_control * mptr );

public	struct menu_control *	allocate_Menu(char * nptr);
public	struct menu_control *	liberate_Menu(struct menu_control * mptr);

public	struct menu_option *	allocate_Option();
public	struct menu_option *	liberate_Option(struct menu_option * optr);



public	void	refresh_ZoomWindow();
public	void	refresh_FontWindow();
public	void	activate_MenuBar(int mode);
public	void	draw_MenuBar();
public	void 	swap_MenuBar();

#endif	/* _singmenu_h */


