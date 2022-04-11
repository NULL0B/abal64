//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_based_h
#define _html_based_h

#include "pending.h"

#include "cssi.h"

class	html_based_component : 	public html_collection_component	,
				public html_style_manager	 {

public:
	html_based_component(int t);
	virtual void		setbase( standard_url * uptr, int mode=0 );
	virtual void		setroot( standard_url * uptr );
	virtual char *		getbase();
	virtual char *		getparameters();
	virtual void		sethttp(char * nptr, char * vptr);
	virtual char *		gethttp(char * nptr);
	virtual	void		ondestroy();
	virtual	void		addpending( html_pending_image * pptr );
	virtual html_basic_component* 	getmap(char * nptr);
	virtual	void	 	addmap(html_basic_component * nptr);
	standard_url    	base;
	standard_url    	root;
	standard_url    	parameters;

	http_equivalence   * 	variables;
	html_pending_image *	firstpending;
	html_pending_image *	lastpending;
	int			remote;


	};

#endif	// _html_based_h






