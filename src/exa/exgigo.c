#ifndef _exgigo_c
#define	_exgigo_c

/*	The GIGO Stubs	*/
/*	--------------	*/
#ifndef	public
#define	public
#endif

#define	Window unsigned long 

public	int signature_version=41;

public  EXAWORD	on_system( int state )				{	return(0);		}
public	EXAWORD close_console()         			{       return(-1);             }
public	EXAWORD open_console()          			{       return(0);              }
public  EXAWORD	apply_font_margin( int fontid ) 		{ 	return(0); 		}
public  EXAWORD	cancel_font_margin()				{	return(0);		}
public	int	close_console_panic()				{	return;			}
public	void	std_signal_event( int v )			{	return;			}
public	int 	std_thread_event( int v )			{	return(0);		}
public	void    default_access_controller()			{	return;			}
public	int	publish_selection(char * mptr, int mlen)	{	return(0);		}
public  void    use_parent_window( Window w ) 			{	return;			}
public  long    pixel_application_window(long v)		{	return((long)0);	}
public  void    pixel_screen_manager()				{	return;			}
public	void	set_desktop_name(char * nptr)			{	return;			}
public	void	set_desktop_icon(char * nptr)			{	return;			}
public	int	push_freeze()					{	return(0);		}
public	int	pop_freeze()					{	return(0);		}
public	int	get_gigo_direction()				{	return(0);		}
public	int	get_gigo_cursor()				{	return(0);		}
public	int	get_transparence_status()			{	return(0);		}
public	int	get_gigo_color()				{	return(0);		}
public	int	get_gigo_colour()				{	return(0);		}
public	int     get_reconfiguration()           		{       return(0);		}
public  int     gethqfont()					{       return(0);		}
public  int     set_gigo_cursor(int v) 				{ 	return(0); 		}
public  int     set_gigo_cursor_colour(int v) 			{ 	return(0); 		}
public  int     set_gigo_colour(int dath, int v) 		{ 	return(0); 		}
public  void    set_gigo_colours( int f, int b ) 		{ 	return; 		}
public  void    set_gigo_tab( int f, int b ) 			{ 	return; 		}
public	void    set_gigo_direction( int v ) 			{ 	return; 		}
public  int     sethqfont(int v) 				{ 	return(0); 		}
public  void    set_transparence_status(int v)			{ 	return; 		}
public  void    set_cyrillic_base(int v)			{	return;			}
public	void    set_reconfiguration(int v)			{	return;			}
public  void    x_configure(int n)      			{       return;      		}
public  Window  x_window()					{	return(0L);		}
public  void    release_input_focus()				{       return;                 }
public  void    restore_input_focus()				{       return;                 }
public  void    suspend_standard_events()			{       return;                 }
public  void    resume_standard_events()			{       return;                 }
public  int     standard_system_process( int value, char * sptr, int slen ) { return(0); }

#endif 	/* _exgigo_c */


