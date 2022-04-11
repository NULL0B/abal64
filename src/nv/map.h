//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_map_h
#define	_html_map_h

#include "complex.h"
#include "area.h"
class html_map_descriptor {
public:
	html_string_field * name;
	html_map_descriptor();
	void		ondestroy();

	};


class html_map_component 	: public html_active_collection_component,
				  public html_map_descriptor 		{

	html_area_component *	maparea;

public:
	html_map_component * nextmap;
	html_map_component( int t = _HTML_TAG_MAP );
	virtual	void	ondestroy();
	virtual int	layout ( html_layout * target );
	virtual int	onparse( html_ascii_stream * source );
	virtual void	generate( html_output * target );
	virtual void	setparent( html_basic_component * member );

	virtual	int 	chkevent( html_logical_event * eptr ) ;
	virtual	int	validate( standard_url * uptr, char * bptr );
	virtual char *  getprompt();
	};

#endif	// _html_map_h








