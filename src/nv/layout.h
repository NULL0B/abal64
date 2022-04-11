//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_h
#define _html_layout_h


#include "vector.h"
class	pixel_conversion	{

public:	
	static	int	columns( long pixels );
	static	int	rows( long pixels  );
	static	void	calibrate( int bfw, int bfh );

	static	int	pixel_font_width;
	static	int	pixel_font_height;

	static	int	columnfloor( long pixels );
	static	int	rowfloor( long pixels  );
	static	int	round_down;

	};

class	html_layout	{

public:
	html_layout();
	virtual	void	ondestroy	();
	virtual int 	start		(html_output * target);
	virtual	void	commit		(html_output * target);
	virtual void	release();
	virtual void	oninit();
	virtual	int	getevent	( html_logical_event * eptr );
	virtual	int	use		( int event );
	virtual int	position();
	virtual int	body	 	( html_body_descriptor 	* dptr );
	virtual int 	setanchor	( html_anchor_descriptor 	* dptr );
	virtual	void 	addnewfont	( int fontsize, html_colour * fontfore, html_colour * fontback );
	virtual int 	setfont  	( html_font_descriptor 	* dptr );
	virtual int	text	 	( html_text_descriptor 	* dptr );
	virtual int	item	 	( html_list_descriptor 	* dptr, html_text_descriptor 	* tptr, int iwidth );
	virtual int	list	 	( html_list_descriptor 	* dptr, int iwidth );
	virtual int	heading		( html_heading_descriptor * dptr, int mode );
	virtual void	ruler	 	(html_rule_descriptor  	* dptr );
	virtual void	image	 	(html_image_descriptor 	* dptr );
	virtual void	input	 	(html_input_descriptor 	* dptr );
	virtual void	applet 	 	(html_applet_descriptor * dptr );
	virtual void	message  	(char * mptr);

	virtual	void	quote(int mode);
	virtual	void	linefeed();
	virtual void	enter( int n );
	virtual void	leave( int n );
	virtual	int	align( int alignment );

	virtual	int	locate( char * cptr );
	virtual int	scroll( int position );

	virtual void	table( html_table_descriptor * dptr );
	virtual void	row( html_row_descriptor * dptr );
	virtual void	cell( html_cell_descriptor * dptr );
	virtual void	frameset( html_frameset_descriptor * dptr );
	virtual void	frame( html_frame_descriptor * dptr );
	virtual int 	style( int mode,cssi_selector *  sptr=0 );
	};


#endif	// _html_layout_h


