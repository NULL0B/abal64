#ifndef	_asfun_menu_h
#define	_asfun_menu_h

#define	_OPTION_SHADED		0x0008
#define	_OPTION_CHOOSE		0x0010
#define	_OPTION_SET   		0x0020
#define	_OPTION_ACTIVE		0x0040
#define	_OPTION_BLANK 		0x0100
#define	_OPTION_SEPARATE	0x0200

#define	_HIDE_NOTHING	1
#define	_HIDE_CURRENT	2
#define	_HIDE_ALL    	3
#define	_HIDE_EXCEPT 	4

#define	_ESC_NO_CLEAR	1
#define	_ESC_ONE_LEVEL	2
#define	_ESC_CLEAR_ALL	3
#define	_ESC_TO_TOP	4
#define	_ESC_INHIBITED	5


#define	_HMENU	1
#define	_VMENU	2

struct	asfun_option	{
	char	value[_MAX_VALUE];
	int	vlen;
	char	comment[_MAX_COMMENT];
	int	clen;
	int	slen;
	int	x;
	int	y;
	int	w;
	int	h;
	int	grx;
	int	gry;
	int	grw;
	int	grh;
	int	state;
	int	style;
	int	trigger;
	int	menu;
	int	option;
	int	nature;
	};

struct	asfun_menu	{
	int	window;
	int	number;
	int	type;		
	int	escape;		
	int	options;
	int	lenopt;
	int	width;
	int	lencom;
	struct  asfun_option * 	option[_MAX_OPTIONS];
	};


#endif	/* _asfun_menu_h */
	/* ------------- */


