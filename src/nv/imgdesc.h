//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_image_descriptor_h
#define	_html_image_descriptor_h

#include "logimage.h"
#include "border.h"

class	cssi_selector;

class	html_image_data	{

public:	html_image_data();
	void	ondestroy();
	void	resize( int nbcols, int nbrows );
	html_logical_image		*ImageData;
	static	int	show_images;
	static	int	drop_images;
	static	void	set_show_images( char * aptr );
	};


class html_image_descriptor : public 	html_active_descriptor,
			      public 	html_image_data		{
public:
	html_url_field			*src;
	html_string_field		*usemap;
	html_string_field	  	*alt;
	html_image_alignment 		*align;
	html_integer_field		*height;
	html_percent_field		*width;
	html_integer_field		*border;
	html_integer_field		*hspace;
	html_integer_field		*vspace;
	html_boolean_field		*ismap;
	border_descriptor		*Border;
	int				atcolumn;
	int				show_image;

	html_image_descriptor();
	void	ondestroy();
	};


#endif // _html_image_descriptor_h







