//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_configuration_h
#define _html_configuration_h

#define	_CONFIG_GUI	"config.gui"

#define	_CONFIG_KEYWORD_BIOSMODE	 0
#define	_CONFIG_KEYWORD_LOWLIGHT	 1
#define	_CONFIG_KEYWORD_HIGHLIGHT	 2
#define	_CONFIG_KEYWORD_DARKLIGHT	 3
#define	_CONFIG_KEYWORD_BACKGROUND	 4
#define	_CONFIG_KEYWORD_STATUSBAR 	 5
#define	_CONFIG_KEYWORD_SCROLLBAR 	 6
#define	_CONFIG_KEYWORD_MENUBAR 	 7
#define	_CONFIG_KEYWORD_ACTIVE		 8
#define	_CONFIG_KEYWORD_NORMAL		 9
#define	_CONFIG_KEYWORD_TRIGGER		10
#define	_CONFIG_KEYWORD_DPI		11
#define	_CONFIG_KEYWORD_PALETTE		12
#define	_CONFIG_KEYWORD_CURSER		13
#define	_CONFIG_KEYWORD_FONT		14
#define	_CONFIG_KEYWORD_CELL		15
#define	_CONFIG_KEYWORD_LOADFONT	16
#define	_CONFIG_KEYWORD_MAGNIFY		17
#define	_CONFIG_KEYWORD_ZOOM		18
#define	_CONFIG_KEYWORD_ZOOMWIDTH	19
#define	_CONFIG_KEYWORD_ZOOMHEIGHT	20
#define	_CONFIG_KEYWORD_SYNCH	 	21

#define	_CONFIG_KEYWORD_X	 	22
#define	_CONFIG_KEYWORD_Y	 	23
#define	_CONFIG_KEYWORD_TOP	 	24
#define	_CONFIG_KEYWORD_RIGHT	 	25
#define	_CONFIG_KEYWORD_BOTTOM	 	26
#define	_CONFIG_KEYWORD_LEFT  	 	27
#define	_CONFIG_KEYWORD_WAIT  	 	28
#define	_CONFIG_KEYWORD_SMOOTH		29
#define	_CONFIG_KEYWORD_MENUFONT	30

#define	_CONFIG_KEYWORD_MAX		31

class	html_configuration	{

public:
	static	int	iskeyword( char * token );

	};

#endif	// _html_configuration_h




