//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_fprinter_h
#define	_html_fprinter_h

#include "pprinter.h"

class	html_fprinter : public html_pprinter {

public:	
	html_fprinter(char * filename);
	virtual int		start(char * uptr=0,html_text_descriptor * tptr=0);
	virtual void		commit();
	virtual int 		loch(int c);
	virtual	void		closure();

	FILE 			* handle;

	};

#endif	// _html_fprinter_h




