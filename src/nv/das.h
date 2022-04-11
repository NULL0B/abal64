//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_das_h
#define _html_das_h

#include "string.h"
#include "dascfg.h"
#include "dasman.h"


class	distant_access_service : public distant_access_configuration {

	static	distant_access_manager * manager;

public:	static	void	activate();
	static	void	terminate();
	};


#endif	// _html_das_h





