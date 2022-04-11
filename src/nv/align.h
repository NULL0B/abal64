//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_alignment_h
#define	_html_alignment_h

#include "field.h"

#define	_HTML_ALIGN_RIGHT	1
#define	_HTML_ALIGN_LEFT	2
#define	_HTML_ALIGN_CENTER	3
#define	_HTML_ALIGN_TOP  	4
#define	_HTML_ALIGN_BOTTOM	8
#define	_HTML_ALIGN_MIDDLE	9


class	html_horizontal_alignment : public html_tag_field {

public:
	html_horizontal_alignment(const char * tagname);
	virtual int	setvalue( char * nptr );
	virtual void 	generate( html_output * target );
	int	value;


	};

class	html_vertical_alignment : public html_tag_field {

public:
	html_vertical_alignment(const char * tagname);
	virtual int	setvalue( char * nptr );
	virtual void 	generate( html_output * target );
	int	value;

	};

class	html_image_alignment : public html_horizontal_alignment {

public:
	html_image_alignment(const char * tagname);
	virtual int	setvalue( char * nptr );
	virtual void 	generate( html_output * target );

	};

#endif	// _html_alignment_h





