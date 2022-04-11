#ifndef	_singtool_h
#define _singtool_h

#define	_MAX_TOOLS	32
#define	_TOOL_MASK	0x001F

extern	int	og;

struct	tool_manager	{
	int	state;
	int	current;
	int	font;
	int	toolmap [_MAX_TOOLS];
	char *	toolmsg [_MAX_TOOLS];
	void	(*on_show)();
	int	(*on_event)(int,int);
	};

struct	tool_node {
	struct tool_manager * manager;
	struct tool_node    * previous;
	};

public	void	activate_ToolBar(int mode);
public	void	draw_tool_icon(int position, int type );
public	void	show_current_tool();
	void	draw_ToolBar();
public	void 	swap_ToolBar();
public	char *	compare(char * aptr, char * kptr);
#endif	/* _singtool_h */


