//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_anchor_descriptor_h
#define	_html_anchor_descriptor_h

class html_anchor_descriptor : public html_active_descriptor {
public:
	html_string_field		*name;
	html_url_field			*href;
	html_uppercase_field		*rel;
	html_uppercase_field		*rev;
	html_colour_field		*bgcolor;
	html_colour_field		*txcolor;

	int	hit_status;
	int	hit_count;

	static	int	underlinelinks;

	html_anchor_descriptor();
	void		ondestroy();

	};


#endif	// _html_anchor_descriptor_h






