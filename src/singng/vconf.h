#ifndef	_visual_config_h
#define	_visual_config_h

struct	configuration_node	{
	char *	name;
	char *	value;
	struct 	configuration_node * next;
	};

#define	MAX_CONF_NAME	64
#define	MAX_CONF_VALUE	320

#ifndef	public	
#define	public
#endif
#ifndef	private	
#define	private static
#endif

public	char	*	configuration_item( char * nptr );
public	int		configuration_load( char * nptr );
public	void		configuration_drop( void );
public	int		configuration_save( char * nptr );


#endif	/* _visual_config_h */




