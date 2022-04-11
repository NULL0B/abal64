//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_complex_h
#define	_html_complex_h

#include "basic.h"
#include "mime.h"
#include "http.h"

class html_collection_component	: public html_basic_component		{

public:	
	html_basic_component * first;
	html_basic_component * last;

	html_collection_component(int t=-1);

	// Overloading of "html_basic_component"
	// -------------------------------------
	virtual void	ondestroy();
	virtual int	addmember( html_basic_component * member );
	virtual int	addtext( int c );
	virtual int	layout ( html_layout * target );
	virtual int	ontrace( html_output * target );
	virtual int	closemember(int c, int n);
	virtual void	dimensions( html_dimensions * result, int pextra=0 );
	virtual void	getparameters( standard_url * uptr );
	virtual void	addmime( html_mime_field * mptr );

		int	collection_closed;

	};

class	html_active_collection_component : 	
		public html_collection_component,
		public html_active_component 
		{

public:
	html_active_collection_component(int t=-1);
	virtual html_basic_component * 	getbasic();
	virtual int			getnature();


	};

#include "based.h"
#endif	/* _html_complex_h */



