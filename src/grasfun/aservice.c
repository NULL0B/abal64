#define	_HOTKEY_TRIGGER '&'

#include "singrel.h"
#include "vframe.h"
public	int	transparent=0;
public	int	standard_black		=_DEFAULT_GUI_BLACK;
public	int	standard_lolight	=_DEFAULT_GUI_DARK_LOW;
public	int	standard_lomid		=_DEFAULT_GUI_DARK;
public	int	standard_backwash	=_DEFAULT_GUI_NEUTRAL;
public	int	standard_himid		=_DEFAULT_GUI_LIGHT;
public	int	standard_hilight	=_DEFAULT_GUI_LIGHT_HIGH;
public	int	standard_white		=_DEFAULT_GUI_WHITE;
public	int	standard_text		=_DEFAULT_GUI_FG_TITLE;
public	int	standard_title		=_DEFAULT_GUI_BG_TITLE;
public	int	standard_focus		=_DEFAULT_GUI_FOCUS;
public	int	standard_grayed		=_DEFAULT_GUI_GREYED;

private	int	LanguageCode= 0;

public	char * fontbuffer[256];
public	char * system_fontpath=(char *) 0;
public	char * system_imagepath=(char *) 0;
public	char *	system_stylepath=(char *) 0;

char *	allocate_string(char * sptr)
{
	char *	rptr;
	if (!( sptr ))
		return(sptr);
	if (!( rptr = allocate( strlen( sptr ) + 1 ) ))
		return( rptr );
	else	{
		strcpy(rptr,sptr);
		return( rptr );
		}
}

public	char *	get_system_stylepath()
{
	if ( system_stylepath )
		return( system_stylepath );
	else 	return((system_stylepath = allocate_string("/home/abal3/style/")));
}

public	char *	get_system_fontpath()
{
	if ( system_fontpath )
		return( system_fontpath );
	else 	return((system_fontpath = allocate_string("/home/abal3/fonts/")));
}

public	char *	get_system_imagepath()
{
	if ( system_imagepath )
		return( system_imagepath );
	else 	return((system_imagepath = allocate_string("/home/abal3/images/")));
}

int	handle_style_errors()
{
	return(0);
}

char*	file_to_string( char * n )
{
	return((char *) 0);
}

	
char *	configuration_item(char * mptr)
{
	if (!( mptr ))
		return(mptr);
	else	return(getenv(mptr));
}

int	lscreatc(WPTR ls_nofen)	
{
	*ls_nofen = 0;
	return(3);
}

int	lsmessc(int ls_nofen, char lg_mess, char * ls_mess)
{
	return(0);
}
int	ld_creatc(int ld_no,void * ld_de)	{	return(0);	}
int	le_creatc(int ld_no,void * ld_de)	{	return(0);	}
int	ld_close(int nl)			{	return(0);	}
int	ld_choixc(int ld)			{	return(0);	}

int	lsacti()	{	return(0);	}
int	lsdesac()	{	return(0);	}
int	ld_sup(int n)	{	return(0);	}
int	bd_supc(int n)	{	return(0);	}
int	sffind_tch(intc){	return(0);	}


private	char * 	Flags[8] = { "en.gif", "fr.gif", "it.gif","es.gif","de.gif","nl.gif","pt.gif", "xx.gif" };

public	char *	visual_language_flag()
{
	return( Flags[LanguageCode] );
}

#include "vfont.c"
#include "vipath.c"
#include "vimages.c"
#include "vrelief.c"
#include "velipse.c"
#include "vtext.c"
#include "varrow.c"
#include "vconvex.c"
#include "vconcave.c"
#include "vfilzone.c"
#include "vframe.c"



