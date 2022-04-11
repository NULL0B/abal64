//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_adi_h
#define _html_adi_h

#include "browser.h"

#define	_ADI_EXTENSION ".adi"

class	html_adi_browser : public html_browser 
{
	int		adi_configured;
	char	* 	adi_configuration;
	char	* 	adi_logo;
	int		adi_active; 
	html_logical_image * adi_image;
	void		set_adi_name( char * nptr );
	void		set_adi_logo( char * nptr );
	void		load_adi(html_output * target );
	void		save_adi();

public:	html_adi_browser( char * vptr=(char *) 0 );
	virtual	void	ondestroy();
	virtual void	operation( char * basename, html_output * target );
	virtual	void	configuration_option( char * tptr, char * vptr );

	};

	


#endif	// _html_adi_h


