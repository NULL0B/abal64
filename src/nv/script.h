//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_script_component_h
#define _html_script_component_h

#include "complex.h"
#include "scridesc.h"
#include "entity.h"
class	html_script_component : public	html_collection_component,
					html_script_descriptor	{
public:
	html_script_component( int t );
	virtual	int	onparse( html_ascii_stream * source );
	virtual void	setparent( html_basic_component * member );
	virtual	int	layout( html_layout * target );
	virtual	void	generate( html_output * target );
	virtual int 	addtext( int c );
	virtual int	ontrace( html_output * target );
	virtual	void	ondestroy();
private:
	html_text_descriptor *	Script;
	int	parser( char * nature, html_text_descriptor * source, 	html_ascii_stream * target );

	};


#endif	// _html_script_component_h




