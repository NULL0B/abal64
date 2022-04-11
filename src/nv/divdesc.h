//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_division_descriptor_h
#define	_html_division_descriptor_h

class html_division_descriptor : public virtual html_element_descriptor {
public:
	html_horizontal_alignment	*align;
	html_division_descriptor();
	void		ondestroy();

	};


#endif	// _html_division_descriptor_h




