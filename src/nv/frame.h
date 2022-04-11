//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_frame_h
#define	_html_frame_h

#include "complex.h"


class html_frame_component 	: public html_based_component,
				  public html_frame_descriptor 		{
public:
	html_frame_component(int t=_HTML_TAG_FRAME);
	virtual	void	ondestroy();
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual int	ontrace( html_output * target );
	virtual int  	layout( html_layout * target );
	virtual void	setparent( html_basic_component * member );
	virtual int	addtext( int c );
	virtual	void	addpending( html_pending_image * pptr );
	virtual	html_basic_component * 	addactive( html_active_component * aptr );
#ifdef	_DO_NOT_USE_PARENT_BASE
	virtual char *		getbase();
#endif
	virtual html_basic_component* 	getmap(char * nptr);
	virtual	void	 	addmap(html_basic_component * nptr);

private:
	int	loaded;
	};
#endif	// _html_frame_h




