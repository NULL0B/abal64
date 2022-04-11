//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_ruledesc_h
#define	_html_ruledesc_h

class html_rule_descriptor :  public virtual html_element_descriptor {
public:
	html_integer_field	*	size;
	html_percent_field	*	width;
	html_boolean_field	*	noshade;
	html_horizontal_alignment *	align;
	int			compact;
	html_rule_descriptor();
	void	ondestroy();
	};

#endif	// _html_ruledesc_h


