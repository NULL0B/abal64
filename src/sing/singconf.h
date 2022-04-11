#ifndef	_SINGCONF_H
#define	_SINGCONF_H

struct	tool_configuration	{
	char	*	program;
	char	*	options;
	char	*	define;
	char	*	path;
	}; 

struct	editor_configuration	{
	char	*	program;
	int		state;
	int		font;
	int		usecolour;
	int		normal;
	int		string;
	int		keyword;
	int		comment;
	int		punctuation;
	}; 

struct sing_configuration {

	char	*	filename;
	char	*	identity;
	char	*	replayscript;
	char	*	recordscript;

	struct tool_configuration exa;
	struct tool_configuration exadb;
	struct tool_configuration atr;
	struct tool_configuration otr;
	struct tool_configuration ald;
	struct tool_configuration old;
	struct editor_configuration aed;
	struct tool_configuration amake;

	char	*	imagepath;
	char	*	iconpath;
	char	*	palette;
	char	*	skin;
	char	*	fontpath;
	char	*	stylepath;
	char	*	componentpath;

	int		triggerstyle;
	int		triggercolour;

	char	*	fontname[10];

	char	*	title;
	char	*	logo;
	char	*	copyright;
	char	*	screenstyle;
	char	*	printstyle;
	char	*	navigator;
	char	*	docpath;
	char	*	printer;
	
	int		density;
	int		papersize;
	int		layout;
	int		pagefeed;

	int		expert_user;

	struct tool_configuration cpp;
	struct tool_configuration lpp;
	struct tool_configuration dll_cpp;
	struct tool_configuration dll_lpp;

	};

char *	configuration_item( char *  );

#ifndef	_SINGCONF_C
#ifdef __cplusplus
	/* GWB le 03/09/2007 */
extern "C" {
#endif
extern	struct sing_configuration * SingConf;
extern	char * system_skin;
extern	char * system_xml;
#ifdef __cplusplus	/* GWB le 03/09/2007 */
}
#endif
#else	
public	char *	configuration_rootname();
public	struct sing_configuration * SingConf=(struct sing_configuration*) 0;
public 	char * system_skin=(char *) 0;
public 	char * system_xml=(char *) 0;
public	char *	system_components=(char *) 0;
#endif	


#endif	/* _SINGCONF_H */

