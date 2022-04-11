//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_body_h
#define	_html_layout_body_h

class	html_layout_body : 	public html_layout_item {

public:
	html_body_descriptor *	context;
	html_layout_body( html_body_descriptor * dptr );
	virtual	void	release();
	void	oninit( html_body_descriptor * dptr );
	virtual	void	commit( html_output * target );
	};


#endif	// _html_layout_body_h





