//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------

#ifndef  _html_browser_h 
#define  _html_browser_h 

#include "parser.h" 
#include "entity.h" 

class	html_browser_node	{

public:
	html_browser_node 	* previous;
	html_browser_node 	* next;
	html_document     	* content;
	char		  	* label;
	int		    	topline;

	html_active_component	*currentactive;
	html_browser_node(html_document * document, char * lptr);
	~html_browser_node();
	html_document * setcontent( html_document * document );
	void	getposition();
	void	setposition();
	};

class	html_browser : html_cache_manager_client {
	void	fetch( char * tptr, html_document * dptr, html_output * target, char * cptr, int clen );
	void	check_service( standard_url * uptr, char * sptr );
public:
	html_browser();
	int	add_node( html_document * document, char * label=(char *) 0 );
	void	drop_node(int flag=0);
	void	drop_document(html_document * document );
	void	add_document( html_document * document );
	void	add_history( html_document * dptr, standard_url * uptr );

	virtual void	ondestroy();
	virtual void	operation( char * basename, html_output * target );
	virtual void	navigate ( html_output * target );
	virtual	html_document * load_document(char * nptr, char * tptr);
	virtual int	load( standard_url * basename, char * message, int msglen, int histflag=1 );
	virtual void	hardcopy(html_output * target, html_document * dptr, char * printer_name );

	virtual	void	configuration_option( char * tptr, char * vptr );

	void	load_configuration();			// Load config File
	void	save_configuration();			// Save config File
	void	use_configuration( char * cptr );	// Form Configuration


	int	loadprintsetup();			// Load Printer Config
	int	setprintername(char * vptr);		// Set Printer Config Filename
	int	setprintdevice(char * vptr);		// Set Printer Device Filename 

	void	load_mailmanager();			// Load config File
	int 	use_mailto( char * cptr );		// Access Mail Page
	void	use_mailer( char * cptr );		// Perform Mailing 
	
	void	load_downloader();
	int	use_downloader( char * cptr );

	void	load_passworder();
	int	use_passworder( char * cptr, char * pptr=0 );

	int	garbage_collection();			// Browser Specific

	int	authorise_load( char * cptr, html_output * target );
	static	void		set_config_filename( char * vptr );
	static	void		setconfirmfilename( char * vptr );
	static	void		set_mailpagename( char * vptr );
	static	void		set_downloadname( char * vptr );
	static	void		set_passwordname( char * vptr );
	static	int		garbage_collector();	// General Relay

	static	html_browser *  current_browser;

	static	int		garbage_collecting;

	html_browser *  	previous_browser;
	html_browser_node * 	first;
	html_browser_node * 	current;

	html_document * 	initial;
	html_document * 	final;
	html_document * 	history;
	html_document * 	configuration;
	html_document * 	confirmation;
	html_document * 	mailmanager;
	html_document * 	printsetup;
	html_document * 	downloader;
	html_document * 	passworder;
	char	      *		autohomepage;
	char	      *		helpfilename;
	char	      *		refresh;

	void			sethelpfilename(char * vptr);
	void			setautohomepage(char * vptr);
	void			setrefresh(char * vptr);

	
	static	char	*	commandline;
	static	char	*	printdevice;
	static	char  	*	downloadpagename;
	static	char  	*	passwordpagename;
	static	char  	*	mailpagefilename;
	static	char  	*	mailsendfilename;
	static	char  	*	mailfilefilename;
	static	char	*	configfilename;
	static	char	*	confirmfilename;
	static	char	*	printsetupfilename;
	static	int		printsource;
	static	int		autosavecfg;
	static	int		usehistory;
	static	int		request_authorisation;
	static	int		defaultservice;
	static	char		bookmark[16];
	};



#endif // _html_browser_h 



